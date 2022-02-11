void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = NULL ;
V_2 -> V_3 . V_5 . V_6 = FALSE ;
V_2 -> V_3 . V_5 . V_7 = NULL ;
F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_8 * * V_10 ;
struct V_8 * V_11 ;
V_9 -> V_6 = FALSE ;
if ( V_2 -> V_3 . V_4 == V_9 && ! V_9 -> V_7 ) {
F_4 ( V_2 ) ;
}
for ( V_10 = & V_2 -> V_3 . V_4 ; ( V_11 = * V_10 ) ; V_10 = & V_11 -> V_7 ) {
if ( V_11 == V_9 ) {
* V_10 = V_11 -> V_7 ;
if ( V_11 -> V_7 ) {
V_11 -> V_7 -> V_12 += V_11 -> V_12 ;
}
return ;
}
}
}
void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 , T_1 time ,
T_1 V_13 )
{
struct V_8 * * V_10 ;
struct V_8 * V_11 ;
T_1 V_14 = 0 ;
time /= 16 ;
if ( ! time )
time = 1 ;
F_3 ( V_2 , V_9 ) ;
V_9 -> V_15 = V_2 ;
V_9 -> V_16 = V_13 ;
V_9 -> V_6 = TRUE ;
if ( ! V_2 -> V_3 . V_4 ) {
V_2 -> V_3 . V_4 = V_9 ;
V_9 -> V_7 = NULL ;
V_9 -> V_12 = time ;
F_6 ( V_2 , time ) ;
return ;
}
F_7 ( V_2 , 0 ) ;
V_14 = 0 ;
for ( V_10 = & V_2 -> V_3 . V_4 ; ( V_11 = * V_10 ) ; V_10 = & V_11 -> V_7 ) {
if ( V_14 + V_11 -> V_12 > time ) {
break ;
}
V_14 += V_11 -> V_12 ;
}
* V_10 = V_9 ;
V_9 -> V_7 = V_11 ;
V_9 -> V_12 = time - V_14 ;
if ( V_11 )
V_11 -> V_12 -= V_9 -> V_12 ;
F_6 ( V_2 , V_2 -> V_3 . V_4 -> V_12 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_3 . V_5 , 32L , F_9 ( V_17 , V_18 ) ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 1 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_19 )
{
T_1 V_14 ;
struct V_8 * V_11 ;
struct V_8 * V_20 ;
struct V_8 * * V_21 ;
int V_22 = 0 ;
V_14 = F_11 ( V_2 ) ;
V_21 = & V_2 -> V_3 . V_4 ;
V_11 = V_2 -> V_3 . V_4 ;
while ( V_11 && ! V_22 ) {
if ( V_14 >= V_11 -> V_12 ) {
V_11 -> V_6 = FALSE ;
V_14 -= V_11 -> V_12 ;
V_21 = & V_11 -> V_7 ;
V_11 = V_11 -> V_7 ;
}
else {
V_11 -> V_12 -= V_14 ;
V_14 = 0 ;
V_22 = 1 ;
}
}
* V_21 = NULL ;
V_20 = V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = V_11 ;
for ( V_11 = V_20 ; V_11 ; V_11 = V_20 ) {
V_20 = V_11 -> V_7 ;
F_12 ( V_2 , V_11 -> V_16 ) ;
}
if ( V_19 && V_2 -> V_3 . V_4 )
F_6 ( V_2 , V_2 -> V_3 . V_4 -> V_12 ) ;
}
