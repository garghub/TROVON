static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
V_2 = V_3 ;
}
static void T_1 F_4 ( void )
{
F_5 ( - 1 , V_4 + V_5 ) ;
F_5 ( - 1 , V_6 + V_5 ) ;
F_5 ( - 1 , V_6 + V_7 ) ;
F_6 ( - 1 , V_8 , & V_9 ) ;
}
static int F_7 ( void )
{
V_10 = F_8 ( V_6 + V_11 ) ;
return 0 ;
}
static void F_9 ( void )
{
F_5 ( - 1 , V_4 + V_5 ) ;
F_5 ( - 1 , V_6 + V_5 ) ;
F_5 ( - 1 , V_6 + V_7 ) ;
F_5 ( V_10 , V_6 + V_12 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_13 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
T_2 V_16 ;
F_5 ( V_17 | V_18 , V_19 ) ;
V_16 = F_8 ( V_20 ) | V_21 ;
F_5 ( V_16 , V_20 ) ;
if ( ! ( F_8 ( V_20 ) & V_21 ) ) {
F_5 ( 0xa05f , V_22 ) ;
F_5 ( V_16 , V_20 ) ;
F_5 ( 0 , V_22 ) ;
}
return 0 ;
}
static void F_13 ( struct V_14 * V_15 )
{
T_2 V_16 ;
F_5 ( V_17 | V_18 , V_19 ) ;
V_16 = F_8 ( V_20 ) & ~ V_21 ;
F_5 ( V_16 , V_20 ) ;
if ( F_8 ( V_20 ) & V_21 ) {
F_5 ( 0xa05f , V_22 ) ;
F_5 ( V_16 , V_20 ) ;
F_5 ( 0 , V_22 ) ;
}
}
static void F_14 ( struct V_14 * V_23 , int V_24 )
{
void T_3 * V_25 = V_24 ? V_26 : V_19 ;
F_5 ( V_17 , V_25 ) ;
}
static void T_1 F_15 ( void )
{
unsigned long V_27 ;
int V_28 ;
F_16 ( & V_29 ) ;
V_27 = F_8 ( V_30 + V_31 ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
struct V_32 * V_33 ;
if ( ( V_27 & ( 16 << V_28 ) ) == 0 )
continue;
V_33 = F_17 ( sizeof( struct V_32 ) , V_34 ) ;
if ( ! V_33 )
continue;
V_33 -> V_35 . V_36 = 0xc0000000 + 0x10000000 * V_28 ;
V_33 -> V_35 . V_37 = V_33 -> V_35 . V_36 + 0x0fffffff ;
V_33 -> V_35 . V_38 = V_39 ;
V_33 -> V_40 = V_41 + V_28 ;
V_33 -> V_42 = V_28 ;
F_18 ( V_33 ) ;
}
}
static T_2 T_4 F_19 ( void )
{
return - F_8 ( ( void T_3 * ) V_43 + V_44 ) ;
}
static void F_20 ( unsigned long V_45 )
{
void T_3 * V_46 = ( void T_3 * ) V_43 ;
T_2 V_47 = V_48 | V_49 ;
unsigned long V_50 = V_45 ;
if ( V_50 >= 1500000 ) {
V_50 /= 16 ;
V_47 |= V_51 ;
}
F_5 ( 0xffff , V_46 + V_52 ) ;
F_5 ( V_47 , V_46 + V_53 ) ;
F_21 ( V_46 + V_44 , L_1 ,
V_50 , 200 , 16 , V_54 ) ;
F_22 ( F_19 , 16 , V_50 ) ;
}
static T_5 F_23 ( int V_40 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
F_5 ( 1 , V_58 + V_59 ) ;
V_57 -> V_60 ( V_57 ) ;
return V_61 ;
}
static void F_24 ( enum V_62 V_63 , struct V_56 * V_57 )
{
T_2 V_47 = F_8 ( V_58 + V_53 ) & ~ V_48 ;
F_5 ( V_47 , V_58 + V_53 ) ;
switch ( V_63 ) {
case V_64 :
F_5 ( V_65 , V_58 + V_52 ) ;
V_47 |= V_49 | V_48 ;
F_5 ( V_47 , V_58 + V_53 ) ;
break;
case V_66 :
V_47 &= ~ V_49 ;
F_5 ( V_47 , V_58 + V_53 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
default:
break;
}
}
static int F_25 ( unsigned long V_70 , struct V_56 * V_57 )
{
unsigned long V_47 = F_8 ( V_58 + V_53 ) ;
F_5 ( V_47 & ~ V_48 , V_58 + V_53 ) ;
F_5 ( V_70 , V_58 + V_52 ) ;
F_5 ( V_47 | V_48 , V_58 + V_53 ) ;
return 0 ;
}
static void F_26 ( unsigned long V_45 )
{
unsigned long V_50 = V_45 ;
unsigned int V_47 = 0 ;
if ( V_50 > 0x100000 * V_71 ) {
V_50 /= 256 ;
V_47 |= V_72 ;
} else if ( V_50 > 0x10000 * V_71 ) {
V_50 /= 16 ;
V_47 |= V_51 ;
}
V_65 = V_50 / V_71 ;
F_5 ( V_47 , V_58 + V_53 ) ;
F_27 ( V_73 , & V_74 ) ;
F_28 ( & V_75 ,
V_50 ,
1 ,
0xffffU ) ;
}
static void T_1 F_29 ( void )
{
struct V_76 * V_76 ;
unsigned long V_50 ;
V_76 = F_30 ( L_2 , NULL ) ;
F_31 ( F_32 ( V_76 ) ) ;
F_33 ( V_76 ) ;
V_50 = F_34 ( V_76 ) ;
F_5 ( 0 , V_77 + V_53 ) ;
F_5 ( 0 , V_78 + V_53 ) ;
F_5 ( 0 , V_43 + V_53 ) ;
F_20 ( V_50 ) ;
F_26 ( V_50 ) ;
}
