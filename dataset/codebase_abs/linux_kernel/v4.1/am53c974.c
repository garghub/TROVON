static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_2 * V_2 , T_1 V_6 , unsigned long V_7 )
{
F_4 ( V_6 , V_2 -> V_8 + ( V_7 * 4UL ) ) ;
}
static T_1 F_5 ( struct V_2 * V_2 , unsigned long V_7 )
{
return F_6 ( V_2 -> V_8 + ( V_7 * 4UL ) ) ;
}
static void F_7 ( struct V_2 * V_2 , T_2 V_6 , unsigned long V_7 )
{
return F_8 ( V_6 , V_2 -> V_8 + ( V_7 * 4UL ) ) ;
}
static T_3 F_9 ( struct V_2 * V_2 , void * V_9 ,
T_4 V_10 , int V_11 )
{
return F_10 ( V_2 -> V_5 , V_9 , V_10 , V_11 ) ;
}
static int F_11 ( struct V_2 * V_2 , struct V_12 * V_13 ,
int V_14 , int V_11 )
{
return F_12 ( V_2 -> V_5 , V_13 , V_14 , V_11 ) ;
}
static void F_13 ( struct V_2 * V_2 , T_3 V_15 ,
T_4 V_10 , int V_11 )
{
F_14 ( V_2 -> V_5 , V_15 , V_10 , V_11 ) ;
}
static void F_15 ( struct V_2 * V_2 , struct V_12 * V_13 ,
int V_14 , int V_11 )
{
F_16 ( V_2 -> V_5 , V_13 , V_14 , V_11 ) ;
}
static int F_17 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
V_16 -> V_17 = F_5 ( V_2 , V_18 ) ;
F_18 ( L_1 , V_16 -> V_17 ) ;
if ( V_16 -> V_17 & ( V_19 |
V_20 |
V_21 |
V_22 ) )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_2 * V_2 )
{
}
static void F_20 ( struct V_2 * V_2 )
{
T_1 V_23 ;
int V_24 = 1000 ;
if ( ( V_2 -> V_25 & V_26 ) == V_27 ||
( V_2 -> V_25 & V_26 ) == V_28 )
return;
while ( -- V_24 > 0 ) {
V_23 = F_5 ( V_2 , V_29 ) & V_30 ;
if ( V_23 <= 1 )
break;
F_21 () ;
}
V_24 = 1000 ;
F_3 ( V_2 , V_31 | V_32 , V_33 ) ;
while ( F_5 ( V_2 , V_18 ) & V_34 ) {
if ( -- V_24 == 0 )
break;
F_21 () ;
}
F_3 ( V_2 , V_31 | V_35 , V_33 ) ;
F_18 ( L_2 , V_24 , V_23 ) ;
if ( F_22 ( V_23 == 1 ) ) {
struct V_36 * V_37 = V_2 -> V_38 ;
V_37 -> V_39 |= V_40 ;
}
}
static void F_23 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
F_18 ( L_3 ) ;
F_3 ( V_2 , V_35 , V_33 ) ;
V_16 -> V_17 = 0 ;
}
static int F_24 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
if ( V_16 -> V_17 & V_19 ) {
T_1 V_41 = F_5 ( V_2 , V_33 ) ;
if ( ( V_41 & V_42 ) == V_43 )
F_3 ( V_2 , V_44 , V_33 ) ;
return 1 ;
}
if ( V_16 -> V_17 & V_20 ) {
F_3 ( V_2 , V_35 , V_33 ) ;
V_16 -> V_17 = F_5 ( V_2 , V_33 ) ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_2 * V_2 , T_2 V_15 , T_2 V_45 ,
T_2 V_46 , int V_47 , T_1 V_48 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
T_2 V_6 = 0 ;
F_26 ( ! ( V_48 & V_49 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_47 )
V_6 |= V_31 ;
F_3 ( V_2 , V_35 | V_6 , V_33 ) ;
F_3 ( V_2 , ( V_45 >> 0 ) & 0xff , V_50 ) ;
F_3 ( V_2 , ( V_45 >> 8 ) & 0xff , V_51 ) ;
if ( V_2 -> V_52 & V_53 )
F_3 ( V_2 , ( V_45 >> 16 ) & 0xff , V_54 ) ;
F_7 ( V_2 , V_45 , V_55 ) ;
F_7 ( V_2 , V_15 , V_56 ) ;
F_18 ( L_4 ,
V_15 , V_45 , V_46 ) ;
F_27 ( V_2 , V_48 ) ;
F_3 ( V_2 , V_43 | V_6 , V_33 ) ;
}
static T_2 F_28 ( struct V_2 * V_2 , T_2 V_57 , T_2 V_58 )
{
int V_59 = 16 ;
T_2 V_60 , V_61 ;
if ( V_2 -> V_52 & V_53 )
V_59 = 24 ;
if ( V_58 > ( 1U << V_59 ) )
V_58 = ( 1U << V_59 ) ;
V_60 = V_57 & ( ( 1U << 24 ) - 1U ) ;
V_61 = V_60 + V_58 ;
if ( V_61 > ( 1U << 24 ) )
V_61 = ( 1U << 24 ) ;
V_58 = V_61 - V_60 ;
return V_58 ;
}
static void F_29 ( struct V_3 * V_4 , T_1 V_48 )
{
T_1 V_62 = 1 , V_63 = 0x80 , V_64 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < 9 ; V_65 ++ ) {
if ( V_62 ) {
F_30 ( V_4 , 0x80 , 0x40 ) ;
V_64 = 0xc0 ;
} else
V_64 = 0x80 ;
F_31 ( 160 ) ;
F_30 ( V_4 , 0x80 , V_64 ) ;
F_31 ( 160 ) ;
F_30 ( V_4 , 0x80 , 0 ) ;
F_31 ( 160 ) ;
V_62 = ( V_48 & V_63 ) ? 1 : 0 ;
V_63 >>= 1 ;
}
}
static T_5 F_32 ( struct V_3 * V_4 )
{
int V_65 ;
T_5 V_66 = 0 ;
T_1 V_64 ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ ) {
V_66 <<= 1 ;
F_30 ( V_4 , 0x80 , 0x80 ) ;
F_31 ( 160 ) ;
F_30 ( V_4 , 0x80 , 0x40 ) ;
F_31 ( 160 ) ;
F_33 ( V_4 , 0x00 , & V_64 ) ;
if ( V_64 == 0x22 )
V_66 |= 1 ;
}
return V_66 ;
}
static void F_34 ( struct V_3 * V_4 , T_5 * V_67 )
{
T_1 V_48 = V_68 , V_65 ;
for ( V_65 = 0 ; V_65 < V_69 ; V_65 ++ ) {
F_30 ( V_4 , 0xc0 , 0 ) ;
F_31 ( 160 ) ;
F_29 ( V_4 , V_48 ++ ) ;
* V_67 ++ = F_32 ( V_4 ) ;
F_30 ( V_4 , 0x80 , 0 ) ;
F_30 ( V_4 , 0x80 , 0 ) ;
F_31 ( 160 ) ;
}
}
static void F_35 ( struct V_2 * V_2 )
{
T_1 V_70 [ 128 ] ;
T_5 * V_67 = ( T_5 * ) V_70 , V_66 = 0 ;
int V_65 ;
F_34 ( (struct V_3 * ) V_2 -> V_5 , V_67 ) ;
for ( V_65 = 0 ; V_65 < V_69 ; V_65 ++ , V_67 ++ )
V_66 += * V_67 ;
if ( V_66 != 0x1234 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
F_36 ( V_71 , & V_4 -> V_5 ,
L_5 ) ;
return;
}
V_2 -> V_72 = V_70 [ V_73 ] ;
V_2 -> V_74 = 2 << V_70 [ V_75 ] ;
if ( V_70 [ V_76 ] & V_77 )
V_2 -> V_78 |= V_79 | V_80 ;
}
static int F_37 ( struct V_3 * V_4 ,
const struct V_81 * V_82 )
{
struct V_83 * V_84 = & V_85 ;
int V_86 = - V_87 ;
struct V_88 * V_89 ;
struct V_2 * V_2 ;
struct V_1 * V_16 ;
if ( F_38 ( V_4 ) ) {
F_36 ( V_71 , & V_4 -> V_5 , L_6 ) ;
return - V_87 ;
}
if ( F_39 ( V_4 , F_40 ( 32 ) ) ) {
F_36 ( V_71 , & V_4 -> V_5 ,
L_7 ) ;
goto V_90;
}
V_89 = F_41 ( V_84 , sizeof( struct V_2 ) ) ;
if ( ! V_89 ) {
F_36 ( V_71 , & V_4 -> V_5 ,
L_8 ) ;
V_86 = - V_91 ;
goto V_90;
}
V_16 = F_42 ( sizeof( struct V_1 ) , V_92 ) ;
if ( ! V_16 ) {
F_36 ( V_71 , & V_4 -> V_5 ,
L_9 ) ;
V_86 = - V_91 ;
goto V_93;
}
V_2 = F_43 ( V_89 ) ;
V_2 -> V_94 = V_89 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_95 = & V_96 ;
V_2 -> V_39 |= V_97 ;
if ( V_98 )
V_2 -> V_52 |= V_53 ;
V_16 -> V_2 = V_2 ;
if ( F_44 ( V_4 , V_99 ) ) {
F_36 ( V_100 , & V_4 -> V_5 ,
L_10 ) ;
goto V_101;
}
V_2 -> V_8 = F_45 ( V_4 , 0 , F_46 ( V_4 , 0 ) ) ;
if ( ! V_2 -> V_8 ) {
F_36 ( V_100 , & V_4 -> V_5 , L_11 ) ;
V_86 = - V_102 ;
goto V_103;
}
V_2 -> V_104 = V_2 -> V_8 ;
F_47 ( V_4 ) ;
V_2 -> V_105 = F_48 ( V_4 , 16 ,
& V_2 -> V_106 ) ;
if ( ! V_2 -> V_105 ) {
F_36 ( V_100 , & V_4 -> V_5 ,
L_12 ) ;
V_86 = - V_91 ;
goto V_107;
}
F_49 ( V_4 , V_16 ) ;
V_86 = F_50 ( V_4 -> V_108 , V_109 , V_110 ,
V_99 , V_2 ) ;
if ( V_86 < 0 ) {
F_36 ( V_100 , & V_4 -> V_5 , L_13 ) ;
goto V_111;
}
V_2 -> V_72 = 7 ;
F_35 ( V_2 ) ;
V_89 -> V_112 = V_2 -> V_72 ;
V_89 -> V_113 = 8 ;
V_89 -> V_108 = V_4 -> V_108 ;
V_89 -> V_114 = F_51 ( V_4 , 0 ) ;
V_89 -> V_115 = F_46 ( V_4 , 0 ) ;
V_89 -> V_116 = V_89 -> V_114 ;
V_2 -> V_117 = ( 1 << V_2 -> V_72 ) ;
V_2 -> V_118 = 40000000 ;
V_86 = F_52 ( V_2 , & V_4 -> V_5 ) ;
if ( V_86 )
goto V_119;
return 0 ;
V_119:
F_53 ( V_4 -> V_108 , V_2 ) ;
V_111:
F_49 ( V_4 , NULL ) ;
F_54 ( V_4 , 16 , V_2 -> V_105 ,
V_2 -> V_106 ) ;
V_107:
F_55 ( V_4 , V_2 -> V_8 ) ;
V_103:
F_56 ( V_4 ) ;
V_101:
F_57 ( V_16 ) ;
V_93:
F_58 ( V_89 ) ;
V_90:
F_59 ( V_4 ) ;
return V_86 ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_1 * V_16 = F_2 ( V_4 ) ;
struct V_2 * V_2 = V_16 -> V_2 ;
F_61 ( V_2 ) ;
F_53 ( V_4 -> V_108 , V_2 ) ;
F_49 ( V_4 , NULL ) ;
F_54 ( V_4 , 16 , V_2 -> V_105 ,
V_2 -> V_106 ) ;
F_55 ( V_4 , V_2 -> V_8 ) ;
F_56 ( V_4 ) ;
F_59 ( V_4 ) ;
F_57 ( V_16 ) ;
F_58 ( V_2 -> V_94 ) ;
}
static int T_6 F_62 ( void )
{
return F_63 ( & V_120 ) ;
}
static void T_7 F_64 ( void )
{
F_65 ( & V_120 ) ;
}
