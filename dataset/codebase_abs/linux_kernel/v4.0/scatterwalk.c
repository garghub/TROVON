static inline void F_1 ( void * V_1 , void * V_2 , T_1 V_3 , int V_4 )
{
void * V_5 = V_4 ? V_1 : V_2 ;
void * V_6 = V_4 ? V_2 : V_1 ;
memcpy ( V_6 , V_5 , V_3 ) ;
}
void F_2 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
V_8 -> V_10 = V_10 ;
F_3 ( ! V_10 -> V_11 ) ;
V_8 -> V_12 = V_10 -> V_12 ;
}
void * F_4 ( struct V_7 * V_8 )
{
return F_5 ( F_6 ( V_8 ) ) +
F_7 ( V_8 -> V_12 ) ;
}
static void F_8 ( struct V_7 * V_8 , int V_4 ,
unsigned int V_13 )
{
if ( V_4 ) {
struct V_14 * V_14 ;
V_14 = F_9 ( V_8 -> V_10 ) + ( ( V_8 -> V_12 - 1 ) >> V_15 ) ;
if ( ! F_10 ( V_14 ) )
F_11 ( V_14 ) ;
}
if ( V_13 ) {
V_8 -> V_12 += V_16 - 1 ;
V_8 -> V_12 &= V_17 ;
if ( V_8 -> V_12 >= V_8 -> V_10 -> V_12 + V_8 -> V_10 -> V_11 )
F_2 ( V_8 , F_12 ( V_8 -> V_10 ) ) ;
}
}
void F_13 ( struct V_7 * V_8 , int V_4 , int V_13 )
{
if ( ! ( F_14 ( V_8 ) & ( V_16 - 1 ) ) || ! V_13 )
F_8 ( V_8 , V_4 , V_13 ) ;
}
void F_15 ( void * V_1 , struct V_7 * V_8 ,
T_1 V_3 , int V_4 )
{
for (; ; ) {
unsigned int V_18 = F_14 ( V_8 ) ;
T_2 * V_19 ;
if ( V_18 > V_3 )
V_18 = V_3 ;
V_19 = F_4 ( V_8 ) ;
F_1 ( V_1 , V_19 , V_18 , V_4 ) ;
F_16 ( V_19 ) ;
F_17 ( V_8 , V_18 ) ;
if ( V_3 == V_18 )
break;
V_1 += V_18 ;
V_3 -= V_18 ;
F_8 ( V_8 , V_4 , 1 ) ;
}
}
void F_18 ( void * V_1 , struct V_9 * V_10 ,
unsigned int V_20 , unsigned int V_3 , int V_4 )
{
struct V_7 V_8 ;
unsigned int V_12 = 0 ;
if ( ! V_3 )
return;
for (; ; ) {
F_2 ( & V_8 , V_10 ) ;
if ( V_20 < V_12 + V_10 -> V_11 )
break;
V_12 += V_10 -> V_11 ;
V_10 = F_12 ( V_10 ) ;
}
F_17 ( & V_8 , V_20 - V_12 ) ;
F_15 ( V_1 , & V_8 , V_3 , V_4 ) ;
F_13 ( & V_8 , V_4 , 0 ) ;
}
int F_19 ( struct V_9 * V_10 , int V_21 )
{
int V_12 = 0 , V_22 = 0 ;
if ( V_21 < V_10 -> V_11 )
return - 1 ;
do {
V_12 += V_10 -> V_11 ;
V_22 ++ ;
V_10 = F_12 ( V_10 ) ;
if ( F_20 ( ! V_10 && ( V_21 < V_12 ) ) )
return - 1 ;
} while ( V_10 && ( V_21 > V_12 ) );
return V_22 ;
}
