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
F_6 ( V_6 , L_1 , V_8 ,
- 1 , V_9 , NULL ) ;
F_7 ( false ) ;
}
static int F_8 ( void )
{
V_10 = F_9 ( V_6 + V_11 ) ;
return 0 ;
}
static void F_10 ( void )
{
F_5 ( - 1 , V_4 + V_5 ) ;
F_5 ( - 1 , V_6 + V_5 ) ;
F_5 ( - 1 , V_6 + V_7 ) ;
F_5 ( V_10 , V_6 + V_12 ) ;
}
static int T_1 F_11 ( void )
{
F_12 ( & V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 )
{
T_2 V_16 ;
F_5 ( V_17 | V_18 , V_19 ) ;
V_16 = F_9 ( V_20 ) | V_21 ;
F_5 ( V_16 , V_20 ) ;
if ( ! ( F_9 ( V_20 ) & V_21 ) ) {
F_5 ( 0xa05f , V_22 ) ;
F_5 ( V_16 , V_20 ) ;
F_5 ( 0 , V_22 ) ;
}
return 0 ;
}
static void F_14 ( struct V_14 * V_15 )
{
T_2 V_16 ;
F_5 ( V_17 | V_18 , V_19 ) ;
V_16 = F_9 ( V_20 ) & ~ V_21 ;
F_5 ( V_16 , V_20 ) ;
if ( F_9 ( V_20 ) & V_21 ) {
F_5 ( 0xa05f , V_22 ) ;
F_5 ( V_16 , V_20 ) ;
F_5 ( 0 , V_22 ) ;
}
}
static void F_15 ( struct V_14 * V_23 , int V_24 )
{
void T_3 * V_25 = V_24 ? V_26 : V_19 ;
F_5 ( V_17 , V_25 ) ;
}
static void T_1 F_16 ( void )
{
unsigned long V_27 ;
int V_28 ;
F_17 ( & V_29 ) ;
V_27 = F_9 ( V_30 + V_31 ) ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
struct V_32 * V_33 ;
if ( ( V_27 & ( 16 << V_28 ) ) == 0 )
continue;
V_33 = F_18 ( sizeof( struct V_32 ) , V_34 ) ;
if ( ! V_33 )
continue;
V_33 -> V_35 . V_36 = 0xc0000000 + 0x10000000 * V_28 ;
V_33 -> V_35 . V_37 = V_33 -> V_35 . V_36 + 0x0fffffff ;
V_33 -> V_35 . V_38 = V_39 ;
V_33 -> V_40 = V_41 + V_28 ;
V_33 -> V_42 = V_28 ;
F_19 ( V_33 ) ;
}
}
static T_2 T_4 F_20 ( void )
{
return - F_9 ( ( void T_3 * ) V_43 + V_44 ) ;
}
static void F_21 ( unsigned long V_45 )
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
F_22 ( V_46 + V_44 , L_2 ,
V_50 , 200 , 16 , V_54 ) ;
F_23 ( F_20 , 16 , V_50 ) ;
}
static T_5 F_24 ( int V_40 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
F_5 ( 1 , V_58 + V_59 ) ;
V_57 -> V_60 ( V_57 ) ;
return V_61 ;
}
static void F_25 ( enum V_62 V_63 , struct V_56 * V_57 )
{
T_2 V_47 = F_9 ( V_58 + V_53 ) & ~ V_48 ;
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
static int F_26 ( unsigned long V_70 , struct V_56 * V_57 )
{
unsigned long V_47 = F_9 ( V_58 + V_53 ) ;
F_5 ( V_47 & ~ V_48 , V_58 + V_53 ) ;
F_5 ( V_70 , V_58 + V_52 ) ;
F_5 ( V_47 | V_48 , V_58 + V_53 ) ;
return 0 ;
}
static void F_27 ( unsigned long V_45 )
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
F_28 ( V_73 , & V_74 ) ;
F_29 ( & V_75 ,
V_50 ,
1 ,
0xffffU ) ;
}
void T_1 F_30 ( void )
{
}
static void T_1 F_31 ( void )
{
struct V_76 * V_76 ;
unsigned long V_50 ;
V_76 = F_32 ( L_3 , NULL ) ;
F_33 ( F_34 ( V_76 ) ) ;
F_35 ( V_76 ) ;
V_50 = F_36 ( V_76 ) ;
F_5 ( 0 , V_77 + V_53 ) ;
F_5 ( 0 , V_78 + V_53 ) ;
F_5 ( 0 , V_43 + V_53 ) ;
F_21 ( V_50 ) ;
F_27 ( V_50 ) ;
}
