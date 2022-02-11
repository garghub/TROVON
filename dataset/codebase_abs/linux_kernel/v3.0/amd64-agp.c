static void F_1 ( struct V_1 * V_2 )
{
F_2 () ;
}
static int F_3 ( struct V_1 * V_3 , T_1 V_4 , int type )
{
int V_5 , V_6 , V_7 ;
long long V_8 ;
int V_9 ;
struct V_10 * V_11 = V_3 -> V_11 ;
T_2 V_12 ;
V_7 = F_4 () ;
if ( type != V_3 -> type )
return - V_13 ;
V_9 = V_11 -> V_14 -> V_15 ( V_11 , type ) ;
if ( V_9 != 0 )
return - V_13 ;
if ( ( ( unsigned long ) V_4 + V_3 -> V_16 ) > V_7 )
return - V_13 ;
V_6 = V_4 ;
while ( V_6 < ( V_4 + V_3 -> V_16 ) ) {
if ( ! F_5 ( V_17 , F_6 ( V_17 -> V_18 + V_6 ) ) )
return - V_19 ;
V_6 ++ ;
}
if ( ! V_3 -> V_20 ) {
F_7 () ;
V_3 -> V_20 = true ;
}
for ( V_5 = 0 , V_6 = V_4 ; V_5 < V_3 -> V_16 ; V_5 ++ , V_6 ++ ) {
V_8 = V_17 -> V_14 -> V_21 ( V_17 ,
F_8 ( V_3 -> V_22 [ V_5 ] ) ,
V_9 ) ;
F_9 ( V_8 & 0xffffff0000000ffcULL ) ;
V_12 = ( V_8 & 0x000000ff00000000ULL ) >> 28 ;
V_12 |= ( V_8 & 0x00000000fffff000ULL ) ;
V_12 |= V_23 | V_24 ;
F_10 ( V_12 , V_17 -> V_18 + V_6 ) ;
F_6 ( V_17 -> V_18 + V_6 ) ;
}
F_1 ( V_3 ) ;
return 0 ;
}
static int F_11 ( void )
{
struct V_25 * V_26 ;
int V_5 ;
T_2 V_2 ;
struct V_27 * V_28 ;
V_26 = F_12 ( 0 ) -> V_29 ;
if ( V_26 == NULL )
return 0 ;
F_13 ( V_26 , V_30 , & V_2 ) ;
V_2 = ( V_2 & 0xe ) ;
V_28 = F_14 ( V_31 ) ;
for ( V_5 = 0 ; V_5 < V_17 -> V_14 -> V_32 ; V_5 ++ ) {
if ( V_2 == V_28 [ V_5 ] . V_33 ) {
V_17 -> V_34 =
V_17 -> V_35 = ( void * ) ( V_28 + V_5 ) ;
V_17 -> V_36 = V_5 ;
return V_28 [ V_5 ] . V_37 ;
}
}
return 0 ;
}
static T_3 F_15 ( struct V_25 * V_38 , T_3 V_18 )
{
T_3 V_39 ;
T_2 V_8 ;
T_3 V_40 ;
F_13 ( V_38 , V_41 , & V_8 ) ;
V_39 = V_8 << 25 ;
V_40 = ( V_39 & V_42 ) ;
F_16 ( V_38 , V_18 ) ;
return V_40 ;
}
static int F_17 ( void )
{
unsigned long V_43 = F_18 ( V_17 -> V_44 ) ;
int V_5 ;
if ( ! F_19 ( V_45 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < F_20 () ; V_5 ++ ) {
V_17 -> V_46 =
F_15 ( F_12 ( V_5 ) -> V_29 , V_43 ) ;
}
F_2 () ;
return 0 ;
}
static void F_21 ( void )
{
T_2 V_8 ;
int V_5 ;
if ( ! F_19 ( V_45 ) )
return;
for ( V_5 = 0 ; V_5 < F_20 () ; V_5 ++ ) {
struct V_25 * V_26 = F_12 ( V_5 ) -> V_29 ;
F_13 ( V_26 , V_30 , & V_8 ) ;
V_8 &= ~ V_47 ;
F_22 ( V_26 , V_30 , V_8 ) ;
}
}
static int T_4 F_23 ( T_3 V_48 , T_2 V_37 )
{
if ( ! F_24 ( V_48 , V_37 , 32 * 1024 * 1024 ) )
return 0 ;
if ( ! V_49 &&
! ( V_49 = F_25 ( V_48 , V_37 , L_1 ) ) ) {
F_26 (KERN_ERR PFX L_2 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_27 ( struct V_25 * V_50 , struct V_25 * V_51 ,
T_5 V_52 )
{
T_2 V_53 , V_54 ;
T_3 V_48 , V_55 ;
int V_56 = 0 ;
T_2 V_57 , V_58 ;
T_5 V_59 ;
F_13 ( V_50 , V_30 , & V_57 ) ;
V_57 = ( V_57 >> 1 ) & 7 ;
F_13 ( V_50 , V_41 , & V_58 ) ;
V_55 = V_58 << 25 ;
F_28 ( V_51 , V_52 + 0x14 , & V_59 ) ;
if ( V_59 == 0xffff ) {
if ( F_23 ( V_55 , ( 32 * 1024 * 1024 ) << V_57 ) )
return 0 ;
return - 1 ;
}
V_59 &= 0xfff ;
if ( V_59 & 0xff )
V_59 |= 0xf00 ;
V_56 = 7 - F_29 ( V_59 ) ;
F_13 ( V_51 , 0x10 , & V_53 ) ;
F_13 ( V_51 , 0x14 , & V_54 ) ;
V_48 = ( V_53 & ~ ( ( 1 << 22 ) - 1 ) ) | ( ( T_3 ) V_54 << 32 ) ;
if ( V_56 >= 0 && V_48 + ( 32ULL << ( 20 + V_56 ) ) > 0x100000000ULL ) {
F_30 ( & V_51 -> V_26 , L_3 ,
32 << V_56 ) ;
V_56 = V_57 ;
}
if ( V_57 >= V_56 ) {
if ( F_23 ( V_55 , ( 32 * 1024 * 1024 ) << V_57 ) )
return 0 ;
}
F_30 ( & V_51 -> V_26 , L_4 ,
V_48 , 32 << V_56 ) ;
if ( V_56 < 0 || ! F_23 ( V_48 , ( 32 * 1024 * 1024 ) << V_56 ) )
return - 1 ;
F_31 ( V_50 , V_56 ) ;
F_22 ( V_50 , V_41 , V_48 >> 25 ) ;
return 0 ;
}
static T_4 int F_32 ( struct V_25 * V_60 , T_2 V_61 )
{
int V_5 ;
if ( F_33 () < 0 )
return - V_62 ;
if ( ! F_19 ( V_45 ) )
return - V_62 ;
V_5 = 0 ;
for ( V_5 = 0 ; V_5 < F_20 () ; V_5 ++ ) {
struct V_25 * V_26 = F_12 ( V_5 ) -> V_29 ;
if ( F_27 ( V_26 , V_60 , V_61 ) < 0 ) {
F_34 ( & V_26 -> V_26 , L_5 ) ;
#ifdef F_35
F_34 ( & V_26 -> V_26 , L_6 ) ;
#endif
return - 1 ;
}
}
return 0 ;
}
static void T_4 F_36 ( struct V_25 * V_60 , struct V_10 * V_11 )
{
char * V_63 ;
switch ( V_60 -> V_64 ) {
case 0x01 : V_63 = L_7 ; break;
case 0x02 : V_63 = L_8 ; break;
case 0x11 : V_63 = L_9 ; break;
case 0x12 : V_63 = L_10 ; break;
case 0x13 : V_63 = L_11 ; break;
case 0x14 : V_63 = L_12 ; break;
default: V_63 = L_13 ; break;
}
F_30 ( & V_60 -> V_26 , L_14 , V_63 ) ;
if ( V_60 -> V_64 < 0x13 ) {
F_30 ( & V_60 -> V_26 , L_15 ) ;
V_11 -> V_65 = 3 ;
V_11 -> V_66 = 0 ;
}
}
static int T_4 F_37 ( struct V_25 * V_60 )
{
T_2 V_67 , V_68 , V_69 ;
struct V_25 * V_70 ;
int V_5 , V_71 ;
unsigned V_37 = F_11 () ;
F_30 ( & V_60 -> V_26 , L_16 ) ;
V_70 = F_38 ( V_60 -> V_72 , F_39 ( 0 , 0 ) ) ;
if ( V_70 == NULL ) {
F_30 ( & V_60 -> V_26 , L_17 ) ;
return - V_62 ;
}
for ( V_5 = 0 ; V_5 < F_40 ( V_73 ) ; V_5 ++ )
if ( V_73 [ V_5 ] . V_37 == V_37 )
break;
if ( V_5 == F_40 ( V_73 ) ) {
F_30 ( & V_60 -> V_26 , L_18 , V_37 ) ;
V_71 = - V_62 ;
goto V_74;
}
F_13 ( F_12 ( 0 ) -> V_29 , V_41 ,
& V_67 ) ;
if ( ( V_67 & 0x7fff ) >> ( 32 - 25 ) ) {
V_71 = - V_62 ;
goto V_74;
}
V_67 = ( V_67 & 0x7fff ) << 25 ;
F_13 ( V_60 , V_75 , & V_68 ) ;
V_68 &= ~ V_42 ;
V_68 |= V_67 ;
F_22 ( V_60 , V_75 , V_68 ) ;
V_69 = V_67 + ( V_37 * 1024 * 1024 ) - 1 ;
F_22 ( V_70 , V_76 , V_67 ) ;
F_22 ( V_70 , V_77 , V_69 ) ;
V_71 = 0 ;
V_74:
F_41 ( V_70 ) ;
return V_71 ;
}
static int F_42 ( struct V_25 * V_60 )
{
T_2 V_8 , V_78 , V_79 , V_80 ;
struct V_25 * V_70 ;
int V_5 , V_71 ;
unsigned V_37 = F_11 () ;
F_30 ( & V_60 -> V_26 , L_19 ) ;
V_70 = F_38 ( V_60 -> V_72 , F_39 ( 11 , 0 ) ) ;
if ( V_70 == NULL ) {
F_30 ( & V_60 -> V_26 , L_20 ) ;
return - V_62 ;
}
for ( V_5 = 0 ; V_5 < F_40 ( V_81 ) ; V_5 ++ )
if ( V_81 [ V_5 ] . V_37 == V_37 )
break;
if ( V_5 == F_40 ( V_81 ) ) {
F_30 ( & V_60 -> V_26 , L_21 , V_37 ) ;
V_71 = - V_62 ;
goto V_74;
}
F_13 ( V_70 , V_82 , & V_8 ) ;
V_8 &= ~ ( 0xf ) ;
V_8 |= V_81 [ V_5 ] . V_33 ;
F_22 ( V_70 , V_82 , V_8 ) ;
F_13 ( F_12 ( 0 ) -> V_29 , V_41 ,
& V_78 ) ;
if ( ( V_78 & 0x7fff ) >> ( 32 - 25 ) ) {
F_30 ( & V_60 -> V_26 , L_22 ) ;
V_71 = - V_62 ;
goto V_74;
}
V_78 = ( V_78 & 0x7fff ) << 25 ;
F_13 ( V_60 , V_83 , & V_79 ) ;
V_79 &= ~ V_42 ;
V_79 |= V_78 ;
F_22 ( V_60 , V_83 , V_79 ) ;
V_80 = V_78 + ( V_37 * 1024 * 1024 ) - 1 ;
F_22 ( V_70 , V_84 , V_78 ) ;
F_22 ( V_70 , V_85 , V_80 ) ;
F_22 ( V_70 , V_86 , V_78 ) ;
F_22 ( V_70 , V_87 , V_80 ) ;
V_71 = 0 ;
V_74:
F_41 ( V_70 ) ;
return V_71 ;
}
static int T_4 F_43 ( struct V_25 * V_60 ,
const struct V_88 * V_89 )
{
struct V_10 * V_11 ;
T_6 V_61 ;
int V_90 ;
if ( V_91 )
return - V_62 ;
V_61 = F_44 ( V_60 , V_92 ) ;
if ( ! V_61 )
return - V_62 ;
V_11 = F_45 () ;
if ( ! V_11 )
return - V_93 ;
if ( V_60 -> V_94 == V_95 &&
V_60 -> V_96 == V_97 ) {
F_36 ( V_60 , V_11 ) ;
} else {
F_30 ( & V_60 -> V_26 , L_23 ,
V_60 -> V_94 , V_60 -> V_96 ) ;
}
V_11 -> V_14 = & V_98 ;
V_11 -> V_26 = V_60 ;
V_11 -> V_99 = V_61 ;
F_13 ( V_60 , V_11 -> V_99 + V_100 , & V_11 -> V_101 ) ;
if ( F_32 ( V_60 , V_61 ) == - 1 ) {
F_46 ( V_11 ) ;
return - V_62 ;
}
if ( V_60 -> V_94 == V_102 ) {
int V_71 = F_42 ( V_60 ) ;
if ( V_71 ) {
F_46 ( V_11 ) ;
return V_71 ;
}
}
if ( V_60 -> V_94 == V_103 ) {
int V_71 = F_37 ( V_60 ) ;
if ( V_71 ) {
F_46 ( V_11 ) ;
return V_71 ;
}
}
F_47 ( V_60 , V_11 ) ;
V_90 = F_48 ( V_11 ) ;
if ( V_90 < 0 )
return V_90 ;
V_91 ++ ;
return 0 ;
}
static void T_7 F_49 ( struct V_25 * V_60 )
{
struct V_10 * V_11 = F_50 ( V_60 ) ;
F_51 ( F_18 ( V_11 -> V_44 ) ,
V_31 [ V_11 -> V_36 ] . V_37 ) ;
F_52 ( V_11 ) ;
F_46 ( V_11 ) ;
V_91 -- ;
}
static int F_53 ( struct V_25 * V_60 , T_8 V_104 )
{
F_54 ( V_60 ) ;
F_55 ( V_60 , F_56 ( V_60 , V_104 ) ) ;
return 0 ;
}
static int F_57 ( struct V_25 * V_60 )
{
F_55 ( V_60 , V_105 ) ;
F_58 ( V_60 ) ;
if ( V_60 -> V_94 == V_102 )
F_42 ( V_60 ) ;
return F_17 () ;
}
int T_9 F_59 ( void )
{
int V_90 = 0 ;
if ( V_106 )
return - V_13 ;
V_90 = F_60 ( & V_107 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( V_91 == 0 ) {
if ( ! V_108 && ! V_109 ) {
F_26 (KERN_INFO PFX L_24 ) ;
#ifdef F_61
F_26 (KERN_INFO PFX L_25 ) ;
#else
F_26 (KERN_INFO PFX L_26 ) ;
#endif
F_62 ( & V_107 ) ;
return - V_62 ;
}
if ( ! F_63 ( V_110 ) ) {
F_62 ( & V_107 ) ;
return - V_62 ;
}
V_107 . V_111 = V_112 ;
V_90 = F_64 ( & V_107 . V_14 ) ;
if ( V_90 == 0 && V_91 == 0 ) {
F_62 ( & V_107 ) ;
V_90 = - V_62 ;
}
}
return V_90 ;
}
static int T_9 F_65 ( void )
{
#ifndef F_61
if ( V_113 )
return V_91 ? 0 : - V_62 ;
#endif
return F_59 () ;
}
static void T_10 F_66 ( void )
{
#ifndef F_61
if ( V_113 )
return;
#endif
if ( V_49 )
F_67 ( V_49 ) ;
F_62 ( & V_107 ) ;
}
