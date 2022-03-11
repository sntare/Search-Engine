# 21f-pa02-stv-and-miles
21f-pa02-stv-and-miles created by GitHub Classroom

This repo contains 3 custom container classes: a linked list, a vector, and a Dictonary which makes use of an AVLTree. 
All of these container classes contain a forward iterator implementation, the vector also contains a random access iterator.
We intended to implement a find function using the forward iterators however we could not complete this in time.

Utilizing the random access iterator for the vector class, we attempted to implement insertionsort, quicksort, and heapsort.
Unfortunately we were only able to produce data utilizing insertionsort. 
To confirm that the data was all sorted, we utilized a for loop which checked that each element was greater than the previous element.
(We did not include the run time added from this to our calculations)
From this check, we learned that despite seeming to work on our checks for smaller data sets, our insertion sort had a flaw we could not solve.
Our code told us that the following sorts failed in the data we used for our graphs: 
Random(1000), 20%(1000), 40%(1000), Ascending(100000), Random(100000), 20%(100000)

We also analyzed from our data the following. For the data with twenty percent duplicates there wasn't much of a common pattern as the data with 100,000 
elements had the highest runtime followed by the data with 25,000 elements. As for the forty percent duplicates and the descending with no duplicates data sets, 
the highest runtime was for the 1000 element data set which meant they didn't have a logical pattern either. However, the data set generated randomly with no duplicates and
the data set that was ascending with no duplicates both had an increasing linear relationship between the size and time which logically makes sense. Based on the 
lack of logical pattern with three of our five data sets, we determined that something may have been wrong with our sorting algorithm which we weren't able to find out.

We generated our randomized data by adapting the algorithm used in the following link https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
to use vectors instead which we were using. To make sure there were no sets we utilized sets as they don't have duplicates. This also meant that we had 
ascending data with no duplicates once we copied the set data to one of our data vectors. As for the descending data with no duplicates we just used a for loop
that started at the end of the vector from the ascending data with no duplicates and copied the elements while decrementing through the vector. The data with
20 and 40 percent duplicates, we were able to generate by way of simple math. We calculated the size of none duplicates for both which would be 80% for our 
20% duplicates for example, and used that size in a loop that copied the none duplicated data. We then pushed back the same data to the end of our vector but while 
adjusting our size to the required duplicates meaning our for loop goes for 20% of the size of the non duplicated data. We then randomized the data once it was duplicated. 




![Random 0 Duplicates Size vs Runtime](https://user-images.githubusercontent.com/71847764/137809557-4d51e719-f23f-4bad-894f-52964c5581a4.png)
![Descending 0 duplicates Size vs Runtime](https://user-images.githubusercontent.com/71847764/137809563-e41d2364-fd3a-41cc-9dbf-ce8e11a9c0c8.png)
![40% Duplicates Size vs Runtime](https://user-images.githubusercontent.com/71847764/137809569-6523794e-1755-4f50-bcc4-3137ca3748e0.png)
![Ascending 0 duplicates Size vs Runtime](https://user-images.githubusercontent.com/71847764/137809574-ad758fe1-8fb3-48b7-b525-05d1ed3868f5.png)
![20% Duplicates Size vs Runtime](https://user-images.githubusercontent.com/71847764/137809578-9f0a4e01-3deb-4da0-9ae7-2f03d3e2f1d0.png)
