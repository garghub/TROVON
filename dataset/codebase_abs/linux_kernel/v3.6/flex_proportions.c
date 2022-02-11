int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = 0 ;
V_3 = F_2 ( & V_2 -> V_5 , 1 ) ;
if ( V_3 )
return V_3 ;
F_3 ( & V_2 -> V_6 ) ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_5 ) ;
}
bool F_6 ( struct V_1 * V_2 , int V_7 )
{
T_1 V_5 ;
unsigned long V_8 ;
F_7 ( V_8 ) ;
V_5 = F_8 ( & V_2 -> V_5 ) ;
if ( V_5 <= 1 ) {
F_9 ( V_8 ) ;
return false ;
}
F_10 ( & V_2 -> V_6 ) ;
if ( V_7 < 64 )
V_5 -= V_5 >> V_7 ;
F_11 ( & V_2 -> V_5 , - V_5 ) ;
V_2 -> V_4 += V_7 ;
F_12 ( & V_2 -> V_6 ) ;
F_9 ( V_8 ) ;
return true ;
}
int F_13 ( struct V_9 * V_10 )
{
V_10 -> V_5 = 0 ;
V_10 -> V_4 = 0 ;
F_14 ( & V_10 -> V_11 ) ;
return 0 ;
}
void F_15 ( struct V_9 * V_10 )
{
}
static void F_16 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned int V_4 = V_2 -> V_4 ;
unsigned long V_8 ;
if ( V_10 -> V_4 == V_4 )
return;
F_17 ( & V_10 -> V_11 , V_8 ) ;
if ( V_10 -> V_4 >= V_4 ) {
F_18 ( & V_10 -> V_11 , V_8 ) ;
return;
}
if ( V_4 - V_10 -> V_4 < V_12 )
V_10 -> V_5 >>= V_4 - V_10 -> V_4 ;
else
V_10 -> V_5 = 0 ;
V_10 -> V_4 = V_4 ;
F_18 ( & V_10 -> V_11 , V_8 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_16 ( V_2 , V_10 ) ;
V_10 -> V_5 ++ ;
F_11 ( & V_2 -> V_5 , 1 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned long * V_13 , unsigned long * V_14 )
{
unsigned int V_15 ;
T_1 V_16 , V_17 ;
do {
V_15 = F_21 ( & V_2 -> V_6 ) ;
F_16 ( V_2 , V_10 ) ;
V_16 = V_10 -> V_5 ;
V_17 = F_22 ( & V_2 -> V_5 ) ;
} while ( F_23 ( & V_2 -> V_6 , V_15 ) );
if ( V_17 <= V_16 ) {
if ( V_16 )
V_17 = V_16 ;
else
V_17 = 1 ;
}
* V_14 = V_17 ;
* V_13 = V_16 ;
}
int F_24 ( struct V_18 * V_10 )
{
int V_3 ;
V_3 = F_2 ( & V_10 -> V_5 , 0 ) ;
if ( V_3 )
return V_3 ;
V_10 -> V_4 = 0 ;
F_14 ( & V_10 -> V_11 ) ;
return 0 ;
}
void F_25 ( struct V_18 * V_10 )
{
F_5 ( & V_10 -> V_5 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_18 * V_10 )
{
unsigned int V_4 = V_2 -> V_4 ;
unsigned long V_8 ;
if ( V_10 -> V_4 == V_4 )
return;
F_17 ( & V_10 -> V_11 , V_8 ) ;
if ( V_10 -> V_4 >= V_4 ) {
F_18 ( & V_10 -> V_11 , V_8 ) ;
return;
}
if ( V_4 - V_10 -> V_4 < V_12 ) {
T_1 V_19 = F_27 ( & V_10 -> V_5 ) ;
if ( V_19 < ( V_20 * V_21 ) )
V_19 = F_8 ( & V_10 -> V_5 ) ;
F_28 ( & V_10 -> V_5 ,
- V_19 + ( V_19 >> ( V_4 - V_10 -> V_4 ) ) , V_21 ) ;
} else
F_29 ( & V_10 -> V_5 , 0 ) ;
V_10 -> V_4 = V_4 ;
F_18 ( & V_10 -> V_11 , V_8 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_18 * V_10 )
{
F_26 ( V_2 , V_10 ) ;
F_28 ( & V_10 -> V_5 , 1 , V_21 ) ;
F_11 ( & V_2 -> V_5 , 1 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_18 * V_10 ,
unsigned long * V_13 , unsigned long * V_14 )
{
unsigned int V_15 ;
T_1 V_16 , V_17 ;
do {
V_15 = F_21 ( & V_2 -> V_6 ) ;
F_26 ( V_2 , V_10 ) ;
V_16 = F_22 ( & V_10 -> V_5 ) ;
V_17 = F_22 ( & V_2 -> V_5 ) ;
} while ( F_23 ( & V_2 -> V_6 , V_15 ) );
if ( V_17 <= V_16 ) {
if ( V_16 )
V_17 = V_16 ;
else
V_17 = 1 ;
}
* V_14 = V_17 ;
* V_13 = V_16 ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_18 * V_10 , int V_22 )
{
if ( F_33 ( V_22 < V_23 ) ) {
unsigned long V_13 , V_14 ;
F_31 ( V_2 , V_10 , & V_13 , & V_14 ) ;
if ( V_13 >
( ( ( V_24 ) V_14 ) * V_22 ) >> V_25 )
return;
} else
F_26 ( V_2 , V_10 ) ;
F_28 ( & V_10 -> V_5 , 1 , V_21 ) ;
F_11 ( & V_2 -> V_5 , 1 ) ;
}
