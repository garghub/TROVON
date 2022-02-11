T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
const struct V_10 * V_11 ;
char T_2 * V_12 ;
void * V_13 , * V_14 ;
if ( F_2 ( V_3 > V_5 -> V_15 ) )
V_3 = V_5 -> V_15 ;
if ( F_2 ( ! V_3 ) )
return 0 ;
V_9 = V_3 ;
V_11 = V_5 -> V_11 ;
V_6 = V_5 -> V_16 ;
V_12 = V_11 -> V_17 + V_6 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
if ( ! F_4 ( V_12 , V_7 ) ) {
V_13 = F_5 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_6 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_6 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
if ( F_7 ( ! V_3 ) ) {
F_8 ( V_13 ) ;
goto V_19;
}
V_2 = V_14 - V_13 ;
V_12 += V_7 ;
F_8 ( V_13 ) ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_6 ) ;
}
V_13 = F_9 ( V_1 ) ;
V_14 = V_13 + V_2 ;
V_8 = F_10 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 += V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
while ( F_2 ( ! V_8 && V_3 ) ) {
V_11 ++ ;
V_12 = V_11 -> V_17 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 ) ;
V_8 = F_10 ( V_12 , V_14 , V_7 ) ;
V_7 -= V_8 ;
V_6 = V_7 ;
V_14 += V_7 ;
V_3 -= V_7 ;
}
F_11 ( V_1 ) ;
V_19:
V_5 -> V_15 -= V_9 - V_3 ;
V_5 -> V_20 -= V_11 - V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_6 ;
return V_9 - V_3 ;
}
static T_1 F_12 ( char * V_21 ,
const struct V_10 * V_11 , T_1 V_22 , T_1 V_3 )
{
T_1 V_23 = 0 , V_8 = 0 ;
while ( V_3 ) {
char T_2 * V_12 = V_11 -> V_17 + V_22 ;
int V_7 = F_3 ( V_3 , V_11 -> V_18 - V_22 ) ;
V_22 = 0 ;
V_8 = F_13 ( V_21 , V_12 , V_7 ) ;
V_23 += V_7 ;
V_3 -= V_7 ;
V_21 += V_7 ;
V_11 ++ ;
if ( F_2 ( V_8 ) )
break;
}
return V_23 - V_8 ;
}
T_1 F_14 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 ;
T_1 V_23 ;
V_13 = F_5 ( V_1 ) ;
if ( F_7 ( V_5 -> V_20 == 1 ) ) {
int V_8 ;
char T_2 * V_12 = V_5 -> V_11 -> V_17 + V_5 -> V_16 ;
V_8 = F_13 ( V_13 + V_2 , V_12 , V_3 ) ;
V_23 = V_3 - V_8 ;
} else {
V_23 = F_12 ( V_13 + V_2 ,
V_5 -> V_11 , V_5 -> V_16 , V_3 ) ;
}
F_8 ( V_13 ) ;
return V_23 ;
}
T_1 F_15 ( struct V_1 * V_1 ,
struct V_4 * V_5 , unsigned long V_2 , T_1 V_3 )
{
char * V_13 ;
T_1 V_23 ;
V_13 = F_9 ( V_1 ) ;
if ( F_7 ( V_5 -> V_20 == 1 ) ) {
int V_8 ;
char T_2 * V_12 = V_5 -> V_11 -> V_17 + V_5 -> V_16 ;
V_8 = F_16 ( V_13 + V_2 , V_12 , V_3 ) ;
V_23 = V_3 - V_8 ;
} else {
V_23 = F_12 ( V_13 + V_2 ,
V_5 -> V_11 , V_5 -> V_16 , V_3 ) ;
}
F_11 ( V_1 ) ;
return V_23 ;
}
void F_17 ( struct V_4 * V_5 , T_1 V_3 )
{
F_18 ( V_5 -> V_15 < V_3 ) ;
if ( F_7 ( V_5 -> V_20 == 1 ) ) {
V_5 -> V_16 += V_3 ;
V_5 -> V_15 -= V_3 ;
} else {
const struct V_10 * V_11 = V_5 -> V_11 ;
T_1 V_22 = V_5 -> V_16 ;
unsigned long V_20 = V_5 -> V_20 ;
while ( V_3 || F_2 ( V_5 -> V_15 && ! V_11 -> V_18 ) ) {
int V_7 ;
V_7 = F_3 ( V_3 , V_11 -> V_18 - V_22 ) ;
F_18 ( ! V_5 -> V_15 || V_5 -> V_15 < V_7 ) ;
V_5 -> V_15 -= V_7 ;
V_3 -= V_7 ;
V_22 += V_7 ;
if ( V_11 -> V_18 == V_22 ) {
V_11 ++ ;
V_20 -- ;
V_22 = 0 ;
}
}
V_5 -> V_11 = V_11 ;
V_5 -> V_16 = V_22 ;
V_5 -> V_20 = V_20 ;
}
}
int F_19 ( struct V_4 * V_5 , T_1 V_3 )
{
char T_2 * V_12 = V_5 -> V_11 -> V_17 + V_5 -> V_16 ;
V_3 = F_3 ( V_3 , V_5 -> V_11 -> V_18 - V_5 -> V_16 ) ;
return F_20 ( V_12 , V_3 ) ;
}
T_1 F_21 ( const struct V_4 * V_5 )
{
const struct V_10 * V_11 = V_5 -> V_11 ;
if ( V_5 -> V_20 == 1 )
return V_5 -> V_15 ;
else
return F_3 ( V_5 -> V_15 , V_11 -> V_18 - V_5 -> V_16 ) ;
}
