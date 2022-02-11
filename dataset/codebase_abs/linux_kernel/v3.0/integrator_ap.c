static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( - 1 , V_2 + V_3 ) ;
F_5 ( - 1 , V_4 + V_3 ) ;
F_5 ( - 1 , V_4 + V_5 ) ;
F_6 ( - 1 , V_6 , & V_7 ) ;
}
static int F_7 ( void )
{
V_8 = F_8 ( V_4 + V_9 ) ;
return 0 ;
}
static void F_9 ( void )
{
F_5 ( - 1 , V_2 + V_3 ) ;
F_5 ( - 1 , V_4 + V_3 ) ;
F_5 ( - 1 , V_4 + V_5 ) ;
F_5 ( V_8 , V_4 + V_10 ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
T_2 V_14 ;
F_5 ( V_15 | V_16 , V_17 ) ;
V_14 = F_8 ( V_18 ) | V_19 ;
F_5 ( V_14 , V_18 ) ;
if ( ! ( F_8 ( V_18 ) & V_19 ) ) {
F_5 ( 0xa05f , V_20 ) ;
F_5 ( V_14 , V_18 ) ;
F_5 ( 0 , V_20 ) ;
}
return 0 ;
}
static void F_13 ( struct V_12 * V_13 )
{
T_2 V_14 ;
F_5 ( V_15 | V_16 , V_17 ) ;
V_14 = F_8 ( V_18 ) & ~ V_19 ;
F_5 ( V_14 , V_18 ) ;
if ( F_8 ( V_18 ) & V_19 ) {
F_5 ( 0xa05f , V_20 ) ;
F_5 ( V_14 , V_18 ) ;
F_5 ( 0 , V_20 ) ;
}
}
static void F_14 ( struct V_12 * V_21 , int V_22 )
{
void T_3 * V_23 = V_22 ? V_24 : V_17 ;
F_5 ( V_15 , V_23 ) ;
}
static void T_1 F_15 ( void )
{
unsigned long V_25 ;
int V_26 ;
F_16 ( & V_27 ) ;
V_25 = F_8 ( V_28 + V_29 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
struct V_30 * V_31 ;
if ( ( V_25 & ( 16 << V_26 ) ) == 0 )
continue;
V_31 = F_17 ( sizeof( struct V_30 ) , V_32 ) ;
if ( ! V_31 )
continue;
V_31 -> V_33 . V_34 = 0xc0000000 + 0x10000000 * V_26 ;
V_31 -> V_33 . V_35 = V_31 -> V_33 . V_34 + 0x0fffffff ;
V_31 -> V_33 . V_36 = V_37 ;
V_31 -> V_38 = V_39 + V_26 ;
V_31 -> V_40 = V_26 ;
F_18 ( V_31 ) ;
}
}
static void F_19 ( T_2 V_41 )
{
void T_3 * V_42 = ( void T_3 * ) V_43 ;
T_2 V_44 = V_45 ;
if ( V_41 >= 1500 ) {
V_41 /= 16 ;
V_44 = V_46 ;
}
F_5 ( V_44 , V_42 + V_47 ) ;
F_5 ( 0xffff , V_42 + V_48 ) ;
F_20 ( V_42 + V_49 , L_1 ,
V_41 * 1000 , 200 , 16 , V_50 ) ;
}
static T_4 F_21 ( int V_38 , void * V_51 )
{
struct V_52 * V_53 = V_51 ;
F_5 ( 1 , V_54 + V_55 ) ;
V_53 -> V_56 ( V_53 ) ;
return V_57 ;
}
static void F_22 ( enum V_58 V_59 , struct V_52 * V_53 )
{
T_2 V_44 = F_8 ( V_54 + V_47 ) & ~ V_45 ;
F_23 ( V_59 == V_60 ) ;
if ( V_59 == V_61 ) {
F_5 ( V_44 , V_54 + V_47 ) ;
F_5 ( V_62 , V_54 + V_48 ) ;
V_44 |= V_63 | V_45 ;
}
F_5 ( V_44 , V_54 + V_47 ) ;
}
static int F_24 ( unsigned long V_64 , struct V_52 * V_53 )
{
unsigned long V_44 = F_8 ( V_54 + V_47 ) ;
F_5 ( V_44 & ~ V_45 , V_54 + V_47 ) ;
F_5 ( V_64 , V_54 + V_48 ) ;
F_5 ( V_44 | V_45 , V_54 + V_47 ) ;
return 0 ;
}
static void F_25 ( T_2 V_41 )
{
struct V_52 * V_53 = & V_65 ;
unsigned int V_44 = 0 ;
if ( V_41 * 1000 > 0x100000 * V_66 ) {
V_41 /= 256 ;
V_44 |= V_67 ;
} else if ( V_41 * 1000 > 0x10000 * V_66 ) {
V_41 /= 16 ;
V_44 |= V_46 ;
}
V_62 = V_41 * 1000 / V_66 ;
F_5 ( V_44 , V_54 + V_47 ) ;
V_53 -> V_38 = V_68 ;
V_53 -> V_69 = F_26 ( V_41 , V_70 , V_53 -> V_71 ) ;
V_53 -> V_72 = F_27 ( 0xffff , V_53 ) ;
V_53 -> V_73 = F_27 ( 0xf , V_53 ) ;
F_28 ( V_68 , & V_74 ) ;
F_29 ( V_53 ) ;
}
static void T_1 F_30 ( void )
{
T_2 V_41 = V_75 * 1000 ;
F_5 ( 0 , V_76 + V_47 ) ;
F_5 ( 0 , V_77 + V_47 ) ;
F_5 ( 0 , V_43 + V_47 ) ;
F_19 ( V_41 ) ;
F_25 ( V_41 ) ;
}
