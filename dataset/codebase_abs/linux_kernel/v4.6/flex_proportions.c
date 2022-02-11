int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_2 -> V_5 = 0 ;
V_4 = F_2 ( & V_2 -> V_6 , 1 , V_3 ) ;
if ( V_4 )
return V_4 ;
F_3 ( & V_2 -> V_7 ) ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_6 ) ;
}
bool F_6 ( struct V_1 * V_2 , int V_8 )
{
T_2 V_6 ;
unsigned long V_9 ;
F_7 ( V_9 ) ;
V_6 = F_8 ( & V_2 -> V_6 ) ;
if ( V_6 <= 1 ) {
F_9 ( V_9 ) ;
return false ;
}
F_10 ( & V_2 -> V_7 ) ;
if ( V_8 < 64 )
V_6 -= V_6 >> V_8 ;
F_11 ( & V_2 -> V_6 , - V_6 ) ;
V_2 -> V_5 += V_8 ;
F_12 ( & V_2 -> V_7 ) ;
F_9 ( V_9 ) ;
return true ;
}
int F_13 ( struct V_10 * V_11 )
{
V_11 -> V_6 = 0 ;
V_11 -> V_5 = 0 ;
F_14 ( & V_11 -> V_12 ) ;
return 0 ;
}
void F_15 ( struct V_10 * V_11 )
{
}
static void F_16 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
unsigned int V_5 = V_2 -> V_5 ;
unsigned long V_9 ;
if ( V_11 -> V_5 == V_5 )
return;
F_17 ( & V_11 -> V_12 , V_9 ) ;
if ( V_11 -> V_5 >= V_5 ) {
F_18 ( & V_11 -> V_12 , V_9 ) ;
return;
}
if ( V_5 - V_11 -> V_5 < V_13 )
V_11 -> V_6 >>= V_5 - V_11 -> V_5 ;
else
V_11 -> V_6 = 0 ;
V_11 -> V_5 = V_5 ;
F_18 ( & V_11 -> V_12 , V_9 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_16 ( V_2 , V_11 ) ;
V_11 -> V_6 ++ ;
F_11 ( & V_2 -> V_6 , 1 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned long * V_14 , unsigned long * V_15 )
{
unsigned int V_16 ;
T_2 V_17 , V_18 ;
do {
V_16 = F_21 ( & V_2 -> V_7 ) ;
F_16 ( V_2 , V_11 ) ;
V_17 = V_11 -> V_6 ;
V_18 = F_22 ( & V_2 -> V_6 ) ;
} while ( F_23 ( & V_2 -> V_7 , V_16 ) );
if ( V_18 <= V_17 ) {
if ( V_17 )
V_18 = V_17 ;
else
V_18 = 1 ;
}
* V_15 = V_18 ;
* V_14 = V_17 ;
}
int F_24 ( struct V_19 * V_11 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( & V_11 -> V_6 , 0 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_11 -> V_5 = 0 ;
F_14 ( & V_11 -> V_12 ) ;
return 0 ;
}
void F_25 ( struct V_19 * V_11 )
{
F_5 ( & V_11 -> V_6 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_19 * V_11 )
{
unsigned int V_5 = V_2 -> V_5 ;
unsigned long V_9 ;
if ( V_11 -> V_5 == V_5 )
return;
F_17 ( & V_11 -> V_12 , V_9 ) ;
if ( V_11 -> V_5 >= V_5 ) {
F_18 ( & V_11 -> V_12 , V_9 ) ;
return;
}
if ( V_5 - V_11 -> V_5 < V_13 ) {
T_2 V_20 = F_27 ( & V_11 -> V_6 ) ;
if ( V_20 < ( V_21 * V_22 ) )
V_20 = F_8 ( & V_11 -> V_6 ) ;
F_28 ( & V_11 -> V_6 ,
- V_20 + ( V_20 >> ( V_5 - V_11 -> V_5 ) ) , V_22 ) ;
} else
F_29 ( & V_11 -> V_6 , 0 ) ;
V_11 -> V_5 = V_5 ;
F_18 ( & V_11 -> V_12 , V_9 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_19 * V_11 )
{
F_26 ( V_2 , V_11 ) ;
F_28 ( & V_11 -> V_6 , 1 , V_22 ) ;
F_11 ( & V_2 -> V_6 , 1 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_19 * V_11 ,
unsigned long * V_14 , unsigned long * V_15 )
{
unsigned int V_16 ;
T_2 V_17 , V_18 ;
do {
V_16 = F_21 ( & V_2 -> V_7 ) ;
F_26 ( V_2 , V_11 ) ;
V_17 = F_22 ( & V_11 -> V_6 ) ;
V_18 = F_22 ( & V_2 -> V_6 ) ;
} while ( F_23 ( & V_2 -> V_7 , V_16 ) );
if ( V_18 <= V_17 ) {
if ( V_17 )
V_18 = V_17 ;
else
V_18 = 1 ;
}
* V_15 = V_18 ;
* V_14 = V_17 ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_19 * V_11 , int V_23 )
{
if ( F_33 ( V_23 < V_24 ) ) {
unsigned long V_14 , V_15 ;
F_31 ( V_2 , V_11 , & V_14 , & V_15 ) ;
if ( V_14 >
( ( ( V_25 ) V_15 ) * V_23 ) >> V_26 )
return;
} else
F_26 ( V_2 , V_11 ) ;
F_28 ( & V_11 -> V_6 , 1 , V_22 ) ;
F_11 ( & V_2 -> V_6 , 1 ) ;
}
