static int F_1 ( int V_1 , int V_2 ,
struct V_3 * * V_4 ,
struct V_3 * V_5 , T_1 V_6 )
{
int V_7 = F_2 ( * V_4 ) ;
struct V_3 * V_8 ;
if ( ! ( V_6 & V_9 ) ) {
V_5 = F_3 ( V_7 , sizeof( * V_4 ) , V_10 ) ;
if ( ! V_5 )
return - V_11 ;
F_4 ( V_5 , V_7 ) ;
}
V_8 = V_5 ;
while ( * V_4 && V_1 ) {
int V_12 = ( * V_4 ) -> V_13 ;
if ( V_1 < V_12 )
V_12 = V_1 ;
if ( V_12 > 0 ) {
V_1 -= V_12 ;
F_5 ( V_8 , F_6 ( * V_4 ) , V_12 , ( * V_4 ) -> V_14 ) ;
if ( V_1 <= 0 )
F_7 ( V_8 ) ;
V_8 = F_8 ( V_8 ) ;
}
* V_4 = F_8 ( * V_4 ) ;
}
* V_4 = V_5 ;
return 0 ;
}
static int F_9 ( int V_1 , int V_2 , struct V_3 * * V_4 ,
struct V_3 * V_5 , T_1 V_6 )
{
void * V_15 ;
int V_16 ;
int V_17 ;
V_17 = F_10 ( V_1 , V_2 ) ;
V_16 = F_11 ( V_17 ) ;
V_15 = ( void * ) F_12 ( V_18 , V_16 ) ;
if ( ! V_15 ) {
F_13 ( L_1 ,
V_19 ) ;
return - V_11 ;
}
if ( V_6 & V_20 ) {
F_14 ( V_15 , * V_4 , 0 , V_1 , 0 ) ;
if ( V_6 & V_21 )
memset ( V_15 + V_1 , 0 , V_17 - V_1 ) ;
}
if ( ! ( V_6 & V_9 ) )
F_4 ( V_5 , 1 ) ;
F_15 ( V_5 , V_15 , V_17 ) ;
* V_4 = V_5 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , int V_1 , int V_2 ,
T_1 V_6 )
{
int V_12 = 0 ;
int V_22 = 0 ;
if ( ! F_17 ( V_1 , V_2 ) )
return V_23 ;
while ( V_4 ) {
V_22 ++ ;
if ( ! F_17 ( V_4 -> V_14 , 4 ) )
return V_23 ;
if ( ! F_17 ( V_4 -> V_13 , V_2 ) )
return V_23 ;
V_12 += V_4 -> V_13 ;
V_4 = F_8 ( V_4 ) ;
if ( V_12 >= V_1 )
break;
}
if ( ( V_6 & V_9 ) && V_22 > 1 )
return V_23 ;
if ( V_12 != V_1 )
return V_24 ;
return 0 ;
}
int F_18 ( struct V_3 * * V_4 , int V_1 , int V_2 ,
struct V_3 * V_5 , T_1 V_6 ,
T_2 V_25 , unsigned long * V_26 )
{
int V_27 ;
* V_26 &= ~ ( V_28 << V_25 ) ;
if ( V_6 & V_29 )
V_27 = V_23 ;
else
V_27 = F_16 ( * V_4 , V_1 , V_2 , V_6 ) ;
if ( V_27 == V_23 ) {
V_27 = F_9 ( V_1 , V_2 , V_4 , V_5 , V_6 ) ;
if ( V_27 )
return V_27 ;
* V_26 |= V_30 << V_25 ;
} else if ( V_27 == V_24 ) {
V_27 = F_1 ( V_1 , V_2 , V_4 , V_5 , V_6 ) ;
if ( V_27 )
return V_27 ;
if ( ! ( V_6 & V_9 ) )
* V_26 |= V_31 << V_25 ;
} else if ( V_6 & V_9 ) {
F_15 ( V_5 , F_19 ( * V_4 ) , ( * V_4 ) -> V_13 ) ;
}
return 0 ;
}
void F_20 ( struct V_3 * V_4 , struct V_3 * V_32 ,
int V_14 , int V_12 , T_2 V_25 ,
unsigned long V_6 )
{
void * V_15 ;
int V_16 ;
V_6 >>= V_25 ;
V_6 &= V_28 ;
if ( ! V_6 )
return;
V_15 = F_19 ( V_4 ) ;
V_16 = F_11 ( V_12 ) ;
if ( V_32 && ( V_6 & V_28 ) )
F_14 ( V_15 , V_32 , V_14 , V_12 , 1 ) ;
if ( V_6 & V_30 )
F_21 ( ( unsigned long ) V_15 , V_16 ) ;
else if ( V_6 & V_31 )
F_22 ( V_4 ) ;
}
