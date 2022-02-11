static unsigned long F_1 ( unsigned long V_1 ,
T_1 V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
long V_6 , V_7 , V_8 , V_9 , V_10 , V_11 ;
unsigned long V_12 ;
T_2 V_13 ;
V_12 = V_2 & V_14 ;
V_9 = V_3 & V_15 ;
V_6 = ( V_3 & V_16 ) >> V_17 ;
V_6 = ( V_6 <= 5 ) ? 5 : V_6 ;
V_8 = V_4 & V_18 ;
V_7 = V_11 = V_5 & V_19 ;
if ( V_7 >= 0x04000000 ) {
V_7 |= 0xFC000000 ;
V_11 = - V_7 ;
}
V_10 = 2 * V_1 ;
if ( V_12 != 0 )
V_10 *= 2 ;
V_10 /= ( V_9 + 1 ) ;
V_13 = ( V_20 ) V_10 * V_11 ;
F_2 ( V_13 , V_8 + 1 ) ;
if ( V_7 < 0 )
V_13 = - V_13 ;
V_13 = ( V_10 * V_6 ) + V_13 ;
return V_13 ;
}
static unsigned long F_3 ( struct V_21 * V_22 ,
unsigned long V_1 )
{
T_1 V_3 , V_4 , V_5 , V_2 ;
void T_3 * V_23 ;
struct V_24 * V_25 = F_4 ( V_22 ) ;
V_23 = V_25 -> V_26 ;
V_2 = F_5 ( V_23 + V_27 ) ;
V_3 = F_5 ( V_23 + V_28 ) ;
V_4 = F_5 ( V_23 + V_29 ) ;
V_5 = F_5 ( V_23 + V_30 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_6 ( unsigned long V_31 , unsigned long V_1 ,
T_1 * V_3 , T_1 * V_4 , T_1 * V_5 )
{
T_1 V_32 ;
long V_6 , V_9 , V_7 , V_8 = 999999 ;
T_2 V_33 ;
unsigned long V_34 ;
V_34 = 4 * V_1 ;
V_9 = V_6 = - 1 ;
while ( ++ V_9 < 16 && V_6 < 5 )
V_6 = V_31 * ( V_9 + 1 ) / V_34 ;
if ( V_6 > 15 )
return - V_35 ;
V_9 -- ;
V_33 = V_31 * ( V_9 + 1 ) - V_34 * V_6 ;
F_2 ( V_33 , V_34 / 1000000 ) ;
V_7 = ( long ) V_33 ;
V_32 = V_6 << 4 | V_9 ;
* V_3 = V_32 ;
* V_4 = V_8 ;
* V_5 = V_7 ;
return 0 ;
}
static int F_7 ( struct V_21 * V_22 , unsigned long V_31 ,
unsigned long V_1 )
{
struct V_24 * V_25 = F_4 ( V_22 ) ;
void T_3 * V_23 ;
T_1 V_2 , V_3 , V_4 , V_5 ;
int V_36 ;
V_23 = V_25 -> V_26 ;
V_36 = F_6 ( V_31 , V_1 , & V_3 , & V_4 , & V_5 ) ;
if ( V_36 )
return V_36 ;
V_2 = F_5 ( V_23 + V_27 ) ;
F_8 ( V_2 | 0x1000L , V_23 + V_27 ) ;
F_8 ( V_3 , V_23 + V_28 ) ;
F_8 ( V_4 , V_23 + V_29 ) ;
F_8 ( V_5 , V_23 + V_30 ) ;
return 0 ;
}
static long F_9 ( struct V_21 * V_22 , unsigned long V_31 ,
unsigned long * V_37 )
{
T_1 V_3 , V_4 , V_5 ;
F_6 ( V_31 , * V_37 , & V_3 , & V_4 , & V_5 ) ;
return F_1 ( * V_37 , V_14 ,
V_3 , V_4 , V_5 ) ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_4 ( V_22 ) ;
T_1 V_32 ;
void T_3 * V_23 ;
int V_38 = 0 ;
V_23 = V_25 -> V_26 ;
V_32 = F_5 ( V_23 + V_27 ) | V_39 ;
F_8 ( V_32 , V_23 + V_27 ) ;
do {
V_32 = F_5 ( V_23 + V_27 ) ;
if ( V_32 & V_40 )
break;
F_11 ( 1 ) ;
} while ( ++ V_38 < V_41 );
if ( V_38 == V_41 ) {
F_12 ( L_1 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_13 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_4 ( V_22 ) ;
T_1 V_32 ;
void T_3 * V_23 ;
V_23 = V_25 -> V_26 ;
V_32 = F_5 ( V_23 + V_27 ) & ~ V_39 ;
F_8 ( V_32 , V_23 + V_27 ) ;
}
struct V_42 * F_14 ( const char * V_43 , const char * V_44 ,
void T_3 * V_26 )
{
struct V_24 * V_25 ;
struct V_42 * V_42 ;
struct V_45 V_46 ;
V_25 = F_15 ( sizeof( * V_25 ) , V_47 ) ;
if ( ! V_25 )
return F_16 ( - V_48 ) ;
V_25 -> V_26 = V_26 ;
V_46 . V_43 = V_43 ;
V_46 . V_49 = & V_50 ;
V_46 . V_51 = 0 ;
V_46 . V_52 = & V_44 ;
V_46 . V_53 = 1 ;
V_25 -> V_22 . V_46 = & V_46 ;
V_42 = F_17 ( NULL , & V_25 -> V_22 ) ;
if ( F_18 ( V_42 ) )
F_19 ( V_25 ) ;
return V_42 ;
}
