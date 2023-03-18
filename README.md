# footpath-search

## Overview

This program utilizes a linked list to create a dictionary that stores information about footpaths in Melbourne sourced from a given dataset. The dictionary is constructed by reading the data from a file and inserting each footpath record as a node in the linked list. The program also incorporates a search function that allows users to retrieve information about footpaths in Melbourne using attributes (keys) in the dataset. When a match is found, the program outputs the relevant record(s) associated with the key.

## Data Retrieval 

Implementes the core functionality of a dictionary, allowing for the retrieval of data by key (address). 

The `Makefile` should produce an executable program named `dict1`, which takes three command line arguments:

1. The first argument will be the *stage*, for this part, the value will always be 1.
2. The second argument will be the filename of the *data file*. 
3. The third argument will be the filename of the *output file*.

The `dict1` program reads the data from the specified data file and stores it in a linked list of pointers to `struct`s for the data, with each record (row) in a separate node. 

Users can enter `address`es via *stdin*, and the program searches the linked list for all matching records and outputs them to the output file. If no matches are found, the program outputs `NOTFOUND`. The number of records found is also displayed on *stdout*.

### Execution

An example *execution* of the program might be:

```powershell
make -B dict1
# ./dict1 stage datafile outputfile
./dict1 1 dataset_1000.csv output.txt
```

An example of what might be output to the *output file* after two queries:

```bash
Drummond Street between Pelham Street and Grattan Street
--> footpath_id: 28948 || address: Drummond Street between Pelham Street and Grattan Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 1.02 || distance: 64.57 || grade1in: 63.3 || mcc_id: 1384459 || mccid_int: 20546 || rlmax: 42.32 || rlmin: 41.30 || segside: East || statusid: 2 || streetid: 583 || street_group: 29566 || start_lat: -37.802858 || start_lon: 144.968182 || end_lat: -37.802148 || end_lon: 144.968370 || 
--> footpath_id: 29753 || address: Drummond Street between Pelham Street and Grattan Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 0.61 || distance: 40.26 || grade1in: 66.0 || mcc_id: 1388956 || mccid_int: 20546 || rlmax: 43.31 || rlmin: 42.70 || segside: East || statusid: 2 || streetid: 583 || street_group: 29753 || start_lat: -37.802108 || start_lon: 144.968340 || end_lat: -37.801593 || end_lon: 144.968462 || 
--> footpath_id: 29359 || address: Drummond Street between Pelham Street and Grattan Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 3.45 || distance: 202.79 || grade1in: 58.8 || mcc_id: 1384369 || mccid_int: 20546 || rlmax: 44.31 || rlmin: 40.86 || segside: West || statusid: 2 || streetid: 583 || street_group: 30061 || start_lat: -37.802826 || start_lon: 144.967906 || end_lat: -37.801028 || end_lon: 144.968293 || 
Swanston Street
```

With the following output to *stdout*:

```bash
Drummond Street between Pelham Street and Grattan Street --> 3
Swanston Street --> NOTFOUND
```

## Lookup Index

To implement a simple calculated index on the dataset (address), this program reads the data from a CSV file and stores it in a linked list of pointers to structs for the data. Each record is stored in a separate node. Additionally, this program constructs a sorted array that contains pointers to each node in the dataset, sorted on the `grade1in` attribute.

The program accepts double type values from stdin, searches the index for the closest record to that value, and outputs the record(s) and the `grade1in` value of the record found to an output file. It assumes no blank lines will be present in the queries. The closest point is defined by the absolute difference between the search value and the dataset value. If multiple closest matches for the query are found in the dataset, the program may select any or all matching records.

To run the program, the Makefile produces an executable program called `dict2`. The program takes three command line arguments: the filename of the *data file*, the filename of the *output file*, and the *stage number* (which is always 2 for this part).

### Execution

An example execution of the program might be:

```powershell
make -B dict2
# ./dict2 stage datafile outputfile
./dict2 2 dataset_1000.csv output.txt
```

An example of what might be output to the *output file* after two queries:

```bash
20.49
--> footpath_id: 30506 || address: Rathdowne Street between Carlton Street and Faraday Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 3.02 || distance: 61.86 || grade1in: 20.5 || mcc_id: 1389885 || mccid_int: 20561 || rlmax: 40.7 || rlmin: 37.68 || segside: East || statusid: 2 || streetid: 1024 || street_group: 30882 || start_lat: -37.79934541 || start_lon: 144.9703623 || end_lat: -37.80018581 || end_lon: 144.9701767 ||
6
--> footpath_id: 28120 || address: Argyle Place East from Lygon Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 0.17 || distance: 1.04 || grade1in: 6.1 || mcc_id: 1389857 || mccid_int: 20727 || rlmax: 39.52 || rlmin: 39.35 || segside: || statusid: 3 || streetid: 396 || street_group: 28700 || start_lat: -37.80359949 || start_lon: 144.9671894 || end_lat: -37.80354208 || end_lon: 144.966623 ||
```

With the following output to *stdout*:

```bash
20.49 --> 20.5
6 --> 6.1
```

*** Note: This is my submission for *Project 1 of COMP20003 Algorithms and Data Structures in Sem 2 2022*. ***
