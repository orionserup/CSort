import matplotlib.pyplot as plt
import csv
import glob
import sys

def GetSortData(file) -> dict[str, list]:
    reader = csv.reader(open(file))
    data = [ row for row in reader ]
    
    ndata = [ int(row[0]) for row in data]
    timedata = [ float(row[1]) for row in data]
    
    return { 'n': ndata, 'time': timedata}

def PlotSortData(path, combined = False) -> None:
    
    # Get all .csv Files from the Path
    files = glob.glob(path + "*.csv")
    # Get The Name of the Sort eg QuickSort
    sorts = set([ file.split("Sort")[0] for file in files ])
    
    if combined == True:
        plt.title("Worst Case Times")
        plt.xlabel("Number of Elements")
        plt.ylabel("Time to Sort (ms)")
        for sort in sorts:
            worstdata = GetSortData(sort + "SortWorst.csv")
            plt.plot(worstdata['n'], worstdata['time'])
        plt.legend([sort.replace(path, "") + " Sort" for sort in sorts])
        plt.savefig(path + "WorstCase.png", dpi = 600)
        plt.close()

        plt.title("Best Case Times")
        plt.xlabel("Number of Elements")
        plt.ylabel("Time to Sort (ms)")
        for sort in sorts:
            bestdata = GetSortData(sort + "SortBest.csv")
            plt.plot(bestdata['n'], bestdata['time'])
        plt.legend([sort.replace(path, "") + " Sort" for sort in sorts])
        plt.savefig(path + "BestCase.png", dpi = 600)
        plt.close()
        
        plt.title("Average Case Times")
        plt.xlabel("Number of Elements")
        plt.ylabel("Time to Sort (ms)")
        for sort in sorts:
            avgdata = GetSortData(sort + "SortAvg.csv")
            plt.plot(avgdata['n'], avgdata['time'])
        plt.legend([sort.replace(path, "") + " Sort"for sort in sorts])
        plt.savefig(path + "AverageCase.png", dpi = 600)
        plt.close()

    else:
        for sort in sorts:
            plt.title(sort.replace(path, "") + " Sort")
            plt.xlabel("Number of Elements")
            plt.ylabel("Time to Sort (ms)") 
            avgdata = GetSortData(sort + "SortAvg.csv")
            bestdata = GetSortData(sort + "SortBest.csv")
            worstdata = GetSortData(sort + "SortWorst.csv")

            plt.plot(worstdata['n'], worstdata['time'], 'r.')
            plt.plot(bestdata['n'], bestdata['time'], 'g.')
            plt.plot(avgdata['n'], avgdata['time'], 'b.')

            plt.legend(["Worst Case", "Best Case", "Average Case"])

            plt.savefig(sort + "Sort.png", dpi = 300)
            plt.close()

if __name__ == "__main__":

    path = "../data/"
    combined = False
    
    for arg in sys.argv:
        if arg == "--combined":
            combined = True
        elif "--path=" in arg:
            path = arg.split("--path=")[1]
        elif "-h" in arg or "--help" in arg:
            print("Usage: python plotdata.py [--combined] [--path=<path to data>]")
            exit()
    
    PlotSortData(path, combined)