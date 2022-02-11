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
static int F_23 ( T_3 V_48 , T_2 V_37 )
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
static int F_27 ( struct V_25 * V_50 , struct V_25 * V_51 , T_4 V_52 )
{
T_3 V_48 , V_53 ;
int V_54 = 0 ;
T_2 V_55 , V_56 ;
T_4 V_57 ;
F_13 ( V_50 , V_30 , & V_55 ) ;
V_55 = ( V_55 >> 1 ) & 7 ;
F_13 ( V_50 , V_41 , & V_56 ) ;
V_53 = V_56 << 25 ;
F_28 ( V_51 , V_52 + 0x14 , & V_57 ) ;
if ( V_57 == 0xffff ) {
if ( F_23 ( V_53 , ( 32 * 1024 * 1024 ) << V_55 ) )
return 0 ;
return - 1 ;
}
V_57 &= 0xfff ;
if ( V_57 & 0xff )
V_57 |= 0xf00 ;
V_54 = 7 - F_29 ( V_57 ) ;
V_48 = F_30 ( V_51 , V_58 ) ;
if ( V_54 >= 0 && V_48 + ( 32ULL << ( 20 + V_54 ) ) > 0x100000000ULL ) {
F_31 ( & V_51 -> V_26 , L_3 ,
32 << V_54 ) ;
V_54 = V_55 ;
}
if ( V_55 >= V_54 ) {
if ( F_23 ( V_53 , ( 32 * 1024 * 1024 ) << V_55 ) )
return 0 ;
}
F_31 ( & V_51 -> V_26 , L_4 ,
V_48 , 32 << V_54 ) ;
if ( V_54 < 0 || ! F_23 ( V_48 , ( 32 * 1024 * 1024 ) << V_54 ) )
return - 1 ;
F_32 ( V_50 , V_54 ) ;
F_22 ( V_50 , V_41 , V_48 >> 25 ) ;
return 0 ;
}
static int F_33 ( struct V_25 * V_59 , T_2 V_60 )
{
int V_5 ;
if ( F_34 () < 0 )
return - V_61 ;
if ( ! F_19 ( V_45 ) )
return - V_61 ;
V_5 = 0 ;
for ( V_5 = 0 ; V_5 < F_20 () ; V_5 ++ ) {
struct V_25 * V_26 = F_12 ( V_5 ) -> V_29 ;
if ( F_27 ( V_26 , V_59 , V_60 ) < 0 ) {
F_35 ( & V_26 -> V_26 , L_5 ) ;
#ifdef F_36
F_35 ( & V_26 -> V_26 , L_6 ) ;
#endif
return - 1 ;
}
}
return 0 ;
}
static void F_37 ( struct V_25 * V_59 , struct V_10 * V_11 )
{
char * V_62 ;
switch ( V_59 -> V_63 ) {
case 0x01 : V_62 = L_7 ; break;
case 0x02 : V_62 = L_8 ; break;
case 0x11 : V_62 = L_9 ; break;
case 0x12 : V_62 = L_10 ; break;
case 0x13 : V_62 = L_11 ; break;
case 0x14 : V_62 = L_12 ; break;
default: V_62 = L_13 ; break;
}
F_31 ( & V_59 -> V_26 , L_14 , V_62 ) ;
if ( V_59 -> V_63 < 0x13 ) {
F_31 ( & V_59 -> V_26 , L_15 ) ;
V_11 -> V_64 = 3 ;
V_11 -> V_65 = 0 ;
}
}
static int F_38 ( struct V_25 * V_59 )
{
T_2 V_66 , V_67 , V_68 ;
struct V_25 * V_69 ;
int V_5 , V_70 ;
unsigned V_37 = F_11 () ;
F_31 ( & V_59 -> V_26 , L_16 ) ;
V_69 = F_39 ( V_59 -> V_71 , F_40 ( 0 , 0 ) ) ;
if ( V_69 == NULL ) {
F_31 ( & V_59 -> V_26 , L_17 ) ;
return - V_61 ;
}
for ( V_5 = 0 ; V_5 < F_41 ( V_72 ) ; V_5 ++ )
if ( V_72 [ V_5 ] . V_37 == V_37 )
break;
if ( V_5 == F_41 ( V_72 ) ) {
F_31 ( & V_59 -> V_26 , L_18 , V_37 ) ;
V_70 = - V_61 ;
goto V_73;
}
F_13 ( F_12 ( 0 ) -> V_29 , V_41 ,
& V_66 ) ;
if ( ( V_66 & 0x7fff ) >> ( 32 - 25 ) ) {
V_70 = - V_61 ;
goto V_73;
}
V_66 = ( V_66 & 0x7fff ) << 25 ;
F_13 ( V_59 , V_74 , & V_67 ) ;
V_67 &= ~ V_42 ;
V_67 |= V_66 ;
F_22 ( V_59 , V_74 , V_67 ) ;
V_68 = V_66 + ( V_37 * 1024 * 1024 ) - 1 ;
F_22 ( V_69 , V_75 , V_66 ) ;
F_22 ( V_69 , V_76 , V_68 ) ;
V_70 = 0 ;
V_73:
F_42 ( V_69 ) ;
return V_70 ;
}
static int F_43 ( struct V_25 * V_59 )
{
T_2 V_8 , V_77 , V_78 , V_79 ;
struct V_25 * V_69 ;
int V_5 , V_70 ;
unsigned V_37 = F_11 () ;
F_31 ( & V_59 -> V_26 , L_19 ) ;
V_69 = F_39 ( V_59 -> V_71 , F_40 ( 11 , 0 ) ) ;
if ( V_69 == NULL ) {
F_31 ( & V_59 -> V_26 , L_20 ) ;
return - V_61 ;
}
for ( V_5 = 0 ; V_5 < F_41 ( V_80 ) ; V_5 ++ )
if ( V_80 [ V_5 ] . V_37 == V_37 )
break;
if ( V_5 == F_41 ( V_80 ) ) {
F_31 ( & V_59 -> V_26 , L_21 , V_37 ) ;
V_70 = - V_61 ;
goto V_73;
}
F_13 ( V_69 , V_81 , & V_8 ) ;
V_8 &= ~ ( 0xf ) ;
V_8 |= V_80 [ V_5 ] . V_33 ;
F_22 ( V_69 , V_81 , V_8 ) ;
F_13 ( F_12 ( 0 ) -> V_29 , V_41 ,
& V_77 ) ;
if ( ( V_77 & 0x7fff ) >> ( 32 - 25 ) ) {
F_31 ( & V_59 -> V_26 , L_22 ) ;
V_70 = - V_61 ;
goto V_73;
}
V_77 = ( V_77 & 0x7fff ) << 25 ;
F_13 ( V_59 , V_82 , & V_78 ) ;
V_78 &= ~ V_42 ;
V_78 |= V_77 ;
F_22 ( V_59 , V_82 , V_78 ) ;
V_79 = V_77 + ( V_37 * 1024 * 1024 ) - 1 ;
F_22 ( V_69 , V_83 , V_77 ) ;
F_22 ( V_69 , V_84 , V_79 ) ;
F_22 ( V_69 , V_85 , V_77 ) ;
F_22 ( V_69 , V_86 , V_79 ) ;
V_70 = 0 ;
V_73:
F_42 ( V_69 ) ;
return V_70 ;
}
static int F_44 ( struct V_25 * V_59 ,
const struct V_87 * V_88 )
{
struct V_10 * V_11 ;
T_5 V_60 ;
int V_89 ;
if ( V_90 )
return - V_61 ;
V_60 = F_45 ( V_59 , V_91 ) ;
if ( ! V_60 )
return - V_61 ;
V_11 = F_46 () ;
if ( ! V_11 )
return - V_92 ;
if ( V_59 -> V_93 == V_94 &&
V_59 -> V_95 == V_96 ) {
F_37 ( V_59 , V_11 ) ;
} else {
F_31 ( & V_59 -> V_26 , L_23 ,
V_59 -> V_93 , V_59 -> V_95 ) ;
}
V_11 -> V_14 = & V_97 ;
V_11 -> V_26 = V_59 ;
V_11 -> V_98 = V_60 ;
F_13 ( V_59 , V_11 -> V_98 + V_99 , & V_11 -> V_100 ) ;
if ( F_33 ( V_59 , V_60 ) == - 1 ) {
F_47 ( V_11 ) ;
return - V_61 ;
}
if ( V_59 -> V_93 == V_101 ) {
int V_70 = F_43 ( V_59 ) ;
if ( V_70 ) {
F_47 ( V_11 ) ;
return V_70 ;
}
}
if ( V_59 -> V_93 == V_102 ) {
int V_70 = F_38 ( V_59 ) ;
if ( V_70 ) {
F_47 ( V_11 ) ;
return V_70 ;
}
}
F_48 ( V_59 , V_11 ) ;
V_89 = F_49 ( V_11 ) ;
if ( V_89 < 0 )
return V_89 ;
V_90 ++ ;
return 0 ;
}
static void F_50 ( struct V_25 * V_59 )
{
struct V_10 * V_11 = F_51 ( V_59 ) ;
F_52 ( F_18 ( V_11 -> V_44 ) ,
V_31 [ V_11 -> V_36 ] . V_37 ) ;
F_53 ( V_11 ) ;
F_47 ( V_11 ) ;
V_90 -- ;
}
static int F_54 ( struct V_25 * V_59 , T_6 V_103 )
{
F_55 ( V_59 ) ;
F_56 ( V_59 , F_57 ( V_59 , V_103 ) ) ;
return 0 ;
}
static int F_58 ( struct V_25 * V_59 )
{
F_56 ( V_59 , V_104 ) ;
F_59 ( V_59 ) ;
if ( V_59 -> V_93 == V_101 )
F_43 ( V_59 ) ;
return F_17 () ;
}
int T_7 F_60 ( void )
{
int V_89 = 0 ;
if ( V_105 )
return - V_13 ;
V_89 = F_61 ( & V_106 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_90 == 0 ) {
if ( ! V_107 && ! V_108 ) {
F_26 (KERN_INFO PFX L_24 ) ;
#ifdef F_62
F_26 (KERN_INFO PFX L_25 ) ;
#else
F_26 (KERN_INFO PFX L_26 ) ;
#endif
F_63 ( & V_106 ) ;
return - V_61 ;
}
if ( ! F_64 ( V_109 ) ) {
F_63 ( & V_106 ) ;
return - V_61 ;
}
V_106 . V_110 = V_111 ;
V_89 = F_65 ( & V_106 . V_14 ) ;
if ( V_89 == 0 && V_90 == 0 ) {
F_63 ( & V_106 ) ;
V_89 = - V_61 ;
}
}
return V_89 ;
}
static int T_7 F_66 ( void )
{
#ifndef F_62
if ( V_112 )
return V_90 ? 0 : - V_61 ;
#endif
return F_60 () ;
}
static void T_8 F_67 ( void )
{
#ifndef F_62
if ( V_112 )
return;
#endif
if ( V_49 )
F_68 ( V_49 ) ;
F_63 ( & V_106 ) ;
}
