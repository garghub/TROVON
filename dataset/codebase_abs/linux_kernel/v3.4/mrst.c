static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
T_1 V_5 = 0 , V_6 ;
V_4 = V_7 ;
if ( ! V_8 )
return 0 ;
while ( V_4 ) {
if ( V_8 -> V_9 ( F_2 ( V_2 ) , V_2 -> V_10 ,
V_3 , V_4 , 4 , & V_5 ) )
return 0 ;
if ( F_3 ( V_5 ) == 0x0000 ||
F_3 ( V_5 ) == 0xffff )
break;
if ( F_3 ( V_5 ) == V_11 ) {
V_8 -> V_9 ( F_2 ( V_2 ) , V_2 -> V_10 ,
V_3 , V_4 + 4 , 4 , & V_6 ) ;
if ( ( V_6 & 0xffff ) == V_12 )
return V_4 ;
}
V_4 = F_4 ( V_5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_13 , int V_14 , T_1 V_15 , int V_16 )
{
T_1 V_17 ;
unsigned int V_18 , V_19 ;
int V_20 = ( V_13 - V_21 ) >> 2 ;
V_18 = F_2 ( V_2 ) ;
V_19 = V_2 -> V_10 ;
if ( V_15 == ~ 0 && V_14 == 4 ) {
unsigned long V_22 ;
V_8 -> V_9 ( V_18 , V_19 , V_3 ,
V_16 + 8 + ( V_20 * 4 ) , 4 , & V_17 ) ;
if ( V_17 ) {
V_22 = V_17 - 1 ;
V_22 |= V_22 >> 1 ;
V_22 |= V_22 >> 2 ;
V_22 |= V_22 >> 4 ;
V_22 |= V_22 >> 8 ;
V_22 |= V_22 >> 16 ;
V_22 ++ ;
V_22 = ~ ( V_22 - 1 ) ;
} else {
V_22 = 0 ;
}
return V_8 -> V_23 ( V_18 , V_19 , V_3 , V_13 , 4 ,
V_22 ) ;
}
return V_8 -> V_23 ( V_18 , V_19 , V_3 , V_13 , V_14 , V_15 ) ;
}
static bool F_6 ( unsigned int V_2 , unsigned int V_3 , int V_13 )
{
if ( V_13 >= 0x100 || V_13 == V_24 || V_13 == V_25 )
return 0 ;
if ( V_2 == 0 && ( V_3 == F_7 ( 2 , 0 )
|| V_3 == F_7 ( 0 , 0 )
|| V_3 == F_7 ( 3 , 0 ) ) )
return 1 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 , int V_26 ,
int V_17 , T_1 * V_27 )
{
if ( F_6 ( V_2 -> V_10 , V_3 , V_26 ) )
return V_28 . V_9 ( F_2 ( V_2 ) , V_2 -> V_10 ,
V_3 , V_26 , V_17 , V_27 ) ;
return V_8 -> V_9 ( F_2 ( V_2 ) , V_2 -> V_10 ,
V_3 , V_26 , V_17 , V_27 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 , int V_26 ,
int V_17 , T_1 V_27 )
{
int V_16 ;
if ( V_26 == V_29 )
return 0 ;
V_16 = F_1 ( V_2 , V_3 ) ;
if ( V_16 &&
( V_26 >= V_21 && V_26 <= V_30 ) ) {
return F_5 ( V_2 , V_3 , V_26 , V_17 , V_27 ,
V_16 ) ;
}
if ( F_6 ( V_2 -> V_10 , V_3 , V_26 ) )
return V_28 . V_23 ( F_2 ( V_2 ) , V_2 -> V_10 ,
V_3 , V_26 , V_17 , V_27 ) ;
return V_8 -> V_23 ( F_2 ( V_2 ) , V_2 -> V_10 , V_3 ,
V_26 , V_17 , V_27 ) ;
}
static int F_10 ( struct V_31 * V_32 )
{
T_2 V_33 ;
struct V_34 V_35 ;
F_11 ( V_32 , V_36 , & V_33 ) ;
V_35 . V_37 = F_12 ( V_32 -> V_38 ) ;
V_35 . V_39 = V_32 -> V_38 ;
V_35 . V_40 = 1 ;
V_35 . V_41 = 1 ;
F_13 ( & V_32 -> V_32 , V_32 -> V_38 , & V_35 ) ;
return 0 ;
}
int T_3 F_14 ( void )
{
F_15 ( V_42 L_1 ) ;
F_16 () ;
V_43 = F_10 ;
V_44 = V_45 ;
V_46 = 1 ;
return 1 ;
}
static void T_4 F_17 ( struct V_31 * V_32 )
{
if ( ! V_46 )
return;
if ( F_6 ( V_32 -> V_2 -> V_10 , V_32 -> V_3 , V_47 ) )
return;
V_32 -> V_48 = 0 ;
}
static void T_4 F_18 ( struct V_31 * V_32 )
{
F_19 ( V_32 , V_49 ) ;
}
static void T_4 F_20 ( struct V_31 * V_32 )
{
unsigned long V_16 ;
T_1 V_17 ;
int V_50 ;
if ( ! V_46 )
return;
if ( V_32 -> V_51 < V_7 + 4 )
return;
V_16 = F_1 ( V_32 -> V_2 , V_32 -> V_3 ) ;
if ( ! V_16 || F_7 ( 2 , 0 ) == V_32 -> V_3 ||
F_7 ( 2 , 2 ) == V_32 -> V_3 )
return;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
F_21 ( V_32 , V_16 + 8 + ( V_50 * 4 ) , & V_17 ) ;
V_32 -> V_53 [ V_50 ] . V_54 = V_32 -> V_53 [ V_50 ] . V_55 + V_17 - 1 ;
V_32 -> V_53 [ V_50 ] . V_56 |= V_57 ;
}
}
