static unsigned long F_1 ( unsigned long V_1 ,
T_1 V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
long V_6 , V_7 , V_8 , V_9 , V_10 ;
unsigned long V_11 ;
T_2 V_12 ;
V_11 = V_2 & V_13 ;
V_9 = V_3 & V_14 ;
V_6 = ( V_3 & V_15 ) >> V_16 ;
V_6 = ( V_6 <= 5 ) ? 5 : V_6 ;
V_8 = V_4 & V_17 ;
V_7 = V_5 & V_18 ;
V_7 = F_2 ( V_7 , 26 ) ;
V_10 = 2 * V_1 ;
if ( V_11 != 0 )
V_10 *= 2 ;
V_10 /= ( V_9 + 1 ) ;
V_12 = ( T_2 ) V_10 * abs ( V_7 ) ;
F_3 ( V_12 , V_8 + 1 ) ;
if ( V_7 < 0 )
V_12 = ( V_10 * V_6 ) - V_12 ;
else
V_12 = ( V_10 * V_6 ) + V_12 ;
return V_12 ;
}
static unsigned long F_4 ( struct V_19 * V_20 ,
unsigned long V_1 )
{
T_1 V_3 , V_4 , V_5 , V_2 ;
void T_3 * V_21 ;
struct V_22 * V_23 = F_5 ( V_20 ) ;
V_21 = V_23 -> V_24 ;
V_2 = F_6 ( V_21 + V_25 ) ;
V_3 = F_6 ( V_21 + V_26 ) ;
V_4 = F_6 ( V_21 + V_27 ) ;
V_5 = F_6 ( V_21 + V_28 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_7 ( unsigned long V_29 , unsigned long V_1 ,
T_1 * V_3 , T_1 * V_4 , T_1 * V_5 )
{
T_1 V_30 ;
long V_6 , V_9 , V_7 , V_8 = 999999 ;
T_2 V_31 ;
unsigned long V_32 ;
V_32 = 4 * V_1 ;
V_9 = V_6 = - 1 ;
while ( ++ V_9 < 16 && V_6 < 5 )
V_6 = V_29 * ( V_9 + 1 ) / V_32 ;
if ( V_6 > 15 )
return - V_33 ;
V_9 -- ;
V_31 = V_29 * ( V_9 + 1 ) - V_32 * V_6 ;
F_3 ( V_31 , V_32 / 1000000 ) ;
V_7 = ( long ) V_31 ;
V_30 = V_6 << 4 | V_9 ;
* V_3 = V_30 ;
* V_4 = V_8 ;
* V_5 = V_7 ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , unsigned long V_29 ,
unsigned long V_1 )
{
struct V_22 * V_23 = F_5 ( V_20 ) ;
void T_3 * V_21 ;
T_1 V_2 , V_3 , V_4 , V_5 ;
int V_34 ;
V_21 = V_23 -> V_24 ;
V_34 = F_7 ( V_29 , V_1 , & V_3 , & V_4 , & V_5 ) ;
if ( V_34 )
return V_34 ;
V_2 = F_6 ( V_21 + V_25 ) ;
F_9 ( V_2 | 0x1000L , V_21 + V_25 ) ;
F_9 ( V_3 , V_21 + V_26 ) ;
F_9 ( V_4 , V_21 + V_27 ) ;
F_9 ( V_5 , V_21 + V_28 ) ;
return 0 ;
}
static long F_10 ( struct V_19 * V_20 , unsigned long V_29 ,
unsigned long * V_35 )
{
T_1 V_3 , V_4 , V_5 ;
F_7 ( V_29 , * V_35 , & V_3 , & V_4 , & V_5 ) ;
return F_1 ( * V_35 , V_13 ,
V_3 , V_4 , V_5 ) ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 ) ;
T_1 V_30 ;
void T_3 * V_21 ;
int V_36 = 0 ;
V_21 = V_23 -> V_24 ;
V_30 = F_6 ( V_21 + V_25 ) | V_37 ;
F_9 ( V_30 , V_21 + V_25 ) ;
do {
V_30 = F_6 ( V_21 + V_25 ) ;
if ( V_30 & V_38 )
break;
F_12 ( 1 ) ;
} while ( ++ V_36 < V_39 );
if ( V_36 == V_39 ) {
F_13 ( L_1 ) ;
return - V_33 ;
}
return 0 ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_5 ( V_20 ) ;
T_1 V_30 ;
void T_3 * V_21 ;
V_21 = V_23 -> V_24 ;
V_30 = F_6 ( V_21 + V_25 ) & ~ V_37 ;
F_9 ( V_30 , V_21 + V_25 ) ;
}
struct V_40 * F_15 ( const char * V_41 , const char * V_42 ,
void T_3 * V_24 )
{
struct V_22 * V_23 ;
struct V_40 * V_40 ;
struct V_43 V_44 ;
V_23 = F_16 ( sizeof( * V_23 ) , V_45 ) ;
if ( ! V_23 )
return F_17 ( - V_46 ) ;
V_23 -> V_24 = V_24 ;
V_44 . V_41 = V_41 ;
V_44 . V_47 = & V_48 ;
V_44 . V_49 = 0 ;
V_44 . V_50 = & V_42 ;
V_44 . V_51 = 1 ;
V_23 -> V_20 . V_44 = & V_44 ;
V_40 = F_18 ( NULL , & V_23 -> V_20 ) ;
if ( F_19 ( V_40 ) )
F_20 ( V_23 ) ;
return V_40 ;
}
