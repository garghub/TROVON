static struct V_1 *
F_1 ( long int V_2 , long int V_3 , int V_4 ,
int V_5 )
{
struct V_1 * V_6 = F_2 ( sizeof( * V_6 ) ,
V_7 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = V_5 ;
V_6 -> V_4 = V_4 ;
return V_6 ;
}
static int F_3 ( void * V_8 , struct V_9 * V_10 , struct V_9 * V_11 )
{
struct V_1 * V_12 , * V_13 ;
V_12 = F_4 ( V_10 , struct V_1 , V_14 ) ;
V_13 = F_4 ( V_11 , struct V_1 , V_14 ) ;
if ( V_12 -> V_2 < V_13 -> V_2 )
return - 1 ;
else if ( V_12 -> V_2 > V_13 -> V_2 )
return 1 ;
return 0 ;
}
static void
F_5 ( struct V_15 * V_16 ,
unsigned long V_2 , unsigned long V_3 ,
struct V_9 * V_17 )
{
struct V_1 * V_18 ;
F_6 ( V_17 ) ;
for ( V_18 = F_7 ( V_16 , V_2 , V_3 ) ;
V_18 ;
V_18 = F_8 ( V_18 , V_2 , V_3 ) )
F_9 ( & V_18 -> V_14 , V_17 ) ;
F_10 ( NULL , V_17 , F_3 ) ;
}
int F_11 ( unsigned long V_2 , unsigned long V_3 ,
int V_5 , int V_19 ,
struct V_15 * V_16 ,
struct V_9 * V_20 )
{
struct V_1 * V_6 , * V_21 ;
int V_22 = 0 ;
long int V_23 = V_2 ;
F_12 ( V_24 ) ;
F_6 ( V_20 ) ;
F_5 ( V_16 , V_2 , V_3 ,
& V_24 ) ;
F_13 (interval, &intersection_set, link) {
if ( V_23 < V_6 -> V_2 ) {
F_14 ( V_21 , V_23 , V_6 -> V_2 - 1 ,
1 , V_5 , V_22 , V_25 ,
V_20 ) ;
V_23 = V_6 -> V_2 ;
}
if ( V_23 > V_6 -> V_3 ) {
continue;
} else if ( V_23 <= V_6 -> V_3 &&
F_15 ( V_6 -> V_5 , V_5 ,
V_19 ) ) {
V_23 = V_6 -> V_3 + 1 ;
}
}
if ( V_23 <= V_3 )
F_14 ( V_21 , V_23 , V_3 , 1 , V_5 , V_22 , V_25 ,
V_20 ) ;
return 0 ;
V_25:
F_16 (interval, tmp, diff_set, link) {
F_17 ( & V_6 -> V_14 ) ;
F_18 ( V_6 ) ;
}
return V_22 ;
}
void F_19 ( struct V_9 * V_26 )
{
struct V_1 * V_6 , * V_21 ;
F_16 (interval, tmp, intervals, link)
F_18 ( V_6 ) ;
}
int F_20 ( struct V_15 * V_16 , unsigned long V_2 ,
unsigned long V_3 , int V_5 )
{
struct V_1 * V_6 , * V_21 ;
unsigned long V_27 , V_28 ;
int V_29 , V_30 ;
unsigned long V_31 = V_2 ;
int V_22 = 0 ;
F_12 ( V_32 ) ;
F_12 ( V_24 ) ;
F_5 ( V_16 , V_2 , V_3 ,
& V_24 ) ;
F_13 (interval, &intersection_set, link) {
V_27 = V_6 -> V_2 ;
V_28 = V_6 -> V_3 ;
V_29 = V_6 -> V_4 ;
V_30 = V_6 -> V_5 ;
if ( V_27 < V_31 ) {
F_14 ( V_21 , V_27 , V_31 - 1 , V_29 ,
V_30 , V_22 , V_25 , & V_32 ) ;
} else if ( V_27 > V_31 ) {
F_14 ( V_21 , V_31 , V_27 - 1 , 1 , V_5 ,
V_22 , V_25 , & V_32 ) ;
V_31 = V_27 ;
} else {
V_31 = V_27 ;
}
if ( V_28 > V_3 ) {
F_14 ( V_21 , V_31 , V_3 , V_29 + 1 ,
V_30 | V_5 , V_22 , V_25 ,
& V_32 ) ;
F_14 ( V_21 , V_3 + 1 , V_28 , V_29 ,
V_30 , V_22 , V_25 , & V_32 ) ;
} else {
F_14 ( V_21 , V_31 , V_28 , V_29 + 1 ,
V_30 | V_5 , V_22 , V_25 ,
& V_32 ) ;
}
V_31 = V_28 + 1 ;
}
if ( V_31 <= V_3 )
F_14 ( V_21 , V_31 , V_3 , 1 , V_5 , V_22 , V_25 ,
& V_32 ) ;
F_16 (interval, tmp, &intersection_set, link) {
F_21 ( V_6 , V_16 ) ;
F_18 ( V_6 ) ;
}
F_13 (interval, &to_add, link)
F_22 ( V_6 , V_16 ) ;
return 0 ;
V_25:
F_16 (interval, tmp, &to_add, link)
F_18 ( V_6 ) ;
return V_22 ;
}
void F_23 ( struct V_15 * V_16 ,
unsigned long V_2 , unsigned long V_3 ,
struct V_9 * V_33 )
{
struct V_1 * V_6 ;
for ( V_6 = F_7 ( V_16 , V_2 , V_3 ) ;
V_6 ;
V_6 = F_8 ( V_6 ,
V_2 ,
V_3 ) ) {
if ( -- V_6 -> V_4 == 0 )
F_9 ( & V_6 -> V_14 , V_33 ) ;
}
F_13 (interval, removed, link)
F_21 ( V_6 , V_16 ) ;
}
