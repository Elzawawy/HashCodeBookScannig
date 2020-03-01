#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <set>

#include "hashcode_solver.h"
#define mp make_pair
using namespace std;

int num_libraries,num_days,num_books;
int book_scores[N],library_num_books[N],library_sign_days[N],library_books_per_day[N];
vector<int> library_books[N],books_relation[N];
vector<pair<int,int> >library_sorted_books[N];

void read_input(char* input_filename){
    freopen(input_filename,"r",stdin);
    // Input First line: num_books - num_libraries - num_days_allowed
    scanf("%d %d %d",&num_books,&num_libraries,&num_daysys);
    // Input Second line: scores for each book.
    for(int i = 0 ;i < num_books ; i++)
        scanf("%d",&book_scores[i]);
    // For each library, two lines
    for(int i = 0 ; i < num_libraries ; i++){
        // Library Line One: num_books - sign process days - books per day
        scanf("%d %d %d",&library_num_books[i],&library_sign_days[i],&library_books_per_day[i]);
        // Library Line Two: books ids to define books in this library
        for(int j = 0; j < library_num_books[i] ; j++){
            int book_id;
            scanf("%d",&book_id);
            library_books[i].push_back(book_id);
            library_sorted_books[i].push_back(mp(book_scores[book_id],book_id));
            // 
            books_relation[book_id].push_back(i);
        }
        // Sort books scores for each library according to descending order.
        sort(library_sorted_books[i].begin(), library_sorted_books[i].end(), greater<>());
    }
}