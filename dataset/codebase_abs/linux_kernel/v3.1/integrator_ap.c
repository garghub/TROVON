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
static void F_19 ( T_2 V_43 )
{
void T_3 * V_44 = ( void T_3 * ) V_45 ;
T_2 V_46 = V_47 | V_48 ;
if ( V_43 >= 1500 ) {
V_43 /= 16 ;
V_46 |= V_49 ;
}
F_5 ( 0xffff , V_44 + V_50 ) ;
F_5 ( V_46 , V_44 + V_51 ) ;
F_20 ( V_44 + V_52 , L_1 ,
V_43 * 1000 , 200 , 16 , V_53 ) ;
}
static T_4 F_21 ( int V_40 , void * V_54 )
{
struct V_55 * V_56 = V_54 ;
F_5 ( 1 , V_57 + V_58 ) ;
V_56 -> V_59 ( V_56 ) ;
return V_60 ;
}
static void F_22 ( enum V_61 V_62 , struct V_55 * V_56 )
{
T_2 V_46 = F_8 ( V_57 + V_51 ) & ~ V_47 ;
F_23 ( V_62 == V_63 ) ;
if ( V_62 == V_64 ) {
F_5 ( V_46 , V_57 + V_51 ) ;
F_5 ( V_65 , V_57 + V_50 ) ;
V_46 |= V_48 | V_47 ;
}
F_5 ( V_46 , V_57 + V_51 ) ;
}
static int F_24 ( unsigned long V_66 , struct V_55 * V_56 )
{
unsigned long V_46 = F_8 ( V_57 + V_51 ) ;
F_5 ( V_46 & ~ V_47 , V_57 + V_51 ) ;
F_5 ( V_66 , V_57 + V_50 ) ;
F_5 ( V_46 | V_47 , V_57 + V_51 ) ;
return 0 ;
}
static void F_25 ( T_2 V_43 )
{
struct V_55 * V_56 = & V_67 ;
unsigned int V_46 = 0 ;
if ( V_43 * 1000 > 0x100000 * V_68 ) {
V_43 /= 256 ;
V_46 |= V_69 ;
} else if ( V_43 * 1000 > 0x10000 * V_68 ) {
V_43 /= 16 ;
V_46 |= V_49 ;
}
V_65 = V_43 * 1000 / V_68 ;
F_5 ( V_46 , V_57 + V_51 ) ;
V_56 -> V_40 = V_70 ;
V_56 -> V_71 = F_26 ( V_43 , V_72 , V_56 -> V_73 ) ;
V_56 -> V_74 = F_27 ( 0xffff , V_56 ) ;
V_56 -> V_75 = F_27 ( 0xf , V_56 ) ;
F_28 ( V_70 , & V_76 ) ;
F_29 ( V_56 ) ;
}
static void T_1 F_30 ( void )
{
T_2 V_43 = V_77 * 1000 ;
F_5 ( 0 , V_78 + V_51 ) ;
F_5 ( 0 , V_79 + V_51 ) ;
F_5 ( 0 , V_45 + V_51 ) ;
F_19 ( V_43 ) ;
F_25 ( V_43 ) ;
}
