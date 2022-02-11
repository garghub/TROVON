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
return false ;
if ( V_2 == 0 && ( V_3 == F_7 ( 2 , 0 )
|| V_3 == F_7 ( 0 , 0 )
|| V_3 == F_7 ( 3 , 0 ) ) )
return true ;
return false ;
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
struct V_33 V_34 ;
int V_35 ;
int V_36 ;
if ( V_32 -> V_37 && V_32 -> V_38 > 0 )
return 0 ;
switch ( F_11 () ) {
case V_39 :
V_35 = V_40 ;
if ( V_32 -> V_38 == 0 ) {
if ( V_32 -> V_41 != V_42 )
return - V_43 ;
}
break;
default:
V_35 = V_44 ;
break;
}
F_12 ( & V_34 , F_13 ( & V_32 -> V_32 ) , 1 , V_35 ) ;
V_36 = F_14 ( V_32 -> V_38 , V_45 , & V_34 ) ;
if ( V_36 < 0 )
return V_36 ;
V_32 -> V_37 = 1 ;
return 0 ;
}
static void F_15 ( struct V_31 * V_32 )
{
if ( ! F_16 ( & V_32 -> V_32 ) && V_32 -> V_37 &&
V_32 -> V_38 > 0 ) {
F_17 ( V_32 -> V_38 ) ;
V_32 -> V_37 = 0 ;
}
}
int T_2 F_18 ( void )
{
F_19 ( L_1 ) ;
F_20 () ;
V_46 = F_10 ;
V_47 = F_15 ;
V_48 = V_49 ;
V_50 = 1 ;
return 1 ;
}
static void F_21 ( struct V_31 * V_32 )
{
if ( ! V_50 )
return;
if ( F_6 ( V_32 -> V_2 -> V_10 , V_32 -> V_3 , V_51 ) )
return;
V_32 -> V_52 = 0 ;
}
static void F_22 ( struct V_31 * V_32 )
{
F_23 ( V_32 , V_53 ) ;
}
static void F_24 ( struct V_31 * V_32 )
{
unsigned long V_16 ;
T_1 V_17 ;
int V_54 ;
if ( ! V_50 )
return;
if ( V_32 -> V_55 < V_7 + 4 )
return;
V_16 = F_1 ( V_32 -> V_2 , V_32 -> V_3 ) ;
if ( ! V_16 || F_7 ( 2 , 0 ) == V_32 -> V_3 ||
F_7 ( 2 , 2 ) == V_32 -> V_3 )
return;
for ( V_54 = 0 ; V_54 < V_56 ; V_54 ++ ) {
F_25 ( V_32 , V_16 + 8 + ( V_54 * 4 ) , & V_17 ) ;
V_32 -> V_57 [ V_54 ] . V_58 = V_32 -> V_57 [ V_54 ] . V_59 + V_17 - 1 ;
V_32 -> V_57 [ V_54 ] . V_60 |= V_61 ;
}
}
