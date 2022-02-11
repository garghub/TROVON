void * F_1 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 )
{
if ( V_3 <= V_2 -> V_5 &&
( ( ( unsigned long ) V_2 -> V_6 ) & ( V_7 - 1 ) ) + V_3 <=
V_7 )
return V_2 -> V_6 ;
else
return V_4 ;
}
static void F_2 ( void * V_8 , void * V_9 , T_1 V_3 , int V_10 )
{
if ( V_10 )
memcpy ( V_9 , V_8 , V_3 ) ;
else
memcpy ( V_8 , V_9 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned int V_13 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_14 = V_12 -> V_14 ;
V_2 -> V_15 = V_12 -> V_16 ;
V_13 = V_7 - ( V_12 -> V_17 & ( V_7 - 1 ) ) ;
V_2 -> V_5 = F_4 ( V_12 -> V_16 , V_13 ) ;
V_2 -> V_17 = V_12 -> V_17 ;
}
void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_6 = F_6 ( V_2 -> V_14 ) + V_2 -> V_17 ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 ,
unsigned int V_18 )
{
if ( V_10 )
F_8 ( V_2 -> V_14 ) ;
if ( V_18 ) {
V_2 -> V_15 -= V_2 -> V_5 ;
if ( V_2 -> V_15 ) {
V_2 -> V_14 ++ ;
V_2 -> V_5 = F_4 ( V_2 -> V_15 ,
( unsigned ) V_7 ) ;
V_2 -> V_17 = 0 ;
}
else
F_3 ( V_2 , F_9 ( V_2 -> V_12 ) ) ;
}
}
void F_10 ( struct V_1 * V_2 , int V_10 , int V_18 )
{
F_11 ( V_2 -> V_6 , V_10 ) ;
if ( V_2 -> V_5 == 0 || ! V_18 )
F_7 ( V_2 , V_10 , V_18 ) ;
}
int F_12 ( void * V_8 , struct V_1 * V_2 ,
T_1 V_3 )
{
if ( V_8 != V_2 -> V_6 ) {
while ( V_3 > V_2 -> V_5 ) {
F_2 ( V_8 , V_2 -> V_6 , V_2 -> V_5 , V_10 ) ;
V_8 += V_2 -> V_5 ;
V_3 -= V_2 -> V_5 ;
F_13 ( V_2 -> V_6 ) ;
F_7 ( V_2 , V_10 , 1 ) ;
F_5 ( V_2 ) ;
}
F_2 ( V_8 , V_2 -> V_6 , V_3 , V_10 ) ;
}
V_2 -> V_17 += V_3 ;
V_2 -> V_5 -= V_3 ;
V_2 -> V_15 -= V_3 ;
return 0 ;
}
