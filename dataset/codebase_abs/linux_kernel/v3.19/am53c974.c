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
if ( V_23 > 1 ) {
F_22 ( V_31 , V_2 -> V_32 ,
L_2 ,
V_23 ) ;
}
V_24 = 1000 ;
F_3 ( V_2 , V_33 | V_34 , V_35 ) ;
while ( F_5 ( V_2 , V_18 ) & V_36 ) {
if ( -- V_24 == 0 )
break;
F_21 () ;
}
F_3 ( V_2 , V_33 | V_37 , V_35 ) ;
F_18 ( L_3 , V_24 , V_23 ) ;
if ( F_23 ( V_23 == 1 ) ) {
struct V_38 * V_39 = V_2 -> V_40 ;
V_39 -> V_41 |= V_42 ;
}
}
static void F_24 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
F_18 ( L_4 ) ;
F_3 ( V_2 , V_37 , V_35 ) ;
V_16 -> V_17 = 0 ;
}
static int F_25 ( struct V_2 * V_2 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
if ( V_16 -> V_17 & V_19 ) {
T_1 V_43 = F_5 ( V_2 , V_35 ) ;
if ( ( V_43 & V_44 ) == V_45 )
F_3 ( V_2 , V_46 , V_35 ) ;
return 1 ;
}
if ( V_16 -> V_17 & V_20 ) {
F_3 ( V_2 , V_37 , V_35 ) ;
V_16 -> V_17 = F_5 ( V_2 , V_35 ) ;
return 1 ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_2 , T_2 V_15 , T_2 V_47 ,
T_2 V_48 , int V_49 , T_1 V_50 )
{
struct V_1 * V_16 = F_1 ( V_2 ) ;
T_2 V_6 = 0 ;
F_27 ( ! ( V_50 & V_51 ) ) ;
V_16 -> V_17 = 0 ;
if ( V_49 )
V_6 |= V_33 ;
F_3 ( V_2 , V_37 | V_6 , V_35 ) ;
F_3 ( V_2 , ( V_47 >> 0 ) & 0xff , V_52 ) ;
F_3 ( V_2 , ( V_47 >> 8 ) & 0xff , V_53 ) ;
if ( V_2 -> V_54 & V_55 )
F_3 ( V_2 , ( V_47 >> 16 ) & 0xff , V_56 ) ;
F_7 ( V_2 , V_47 , V_57 ) ;
F_7 ( V_2 , V_15 , V_58 ) ;
F_18 ( L_5 ,
V_15 , V_47 , V_48 ) ;
F_28 ( V_2 , V_50 ) ;
F_3 ( V_2 , V_45 | V_6 , V_35 ) ;
}
static T_2 F_29 ( struct V_2 * V_2 , T_2 V_59 , T_2 V_60 )
{
int V_61 = 16 ;
T_2 V_62 , V_63 ;
if ( V_2 -> V_54 & V_55 )
V_61 = 24 ;
if ( V_60 > ( 1U << V_61 ) )
V_60 = ( 1U << V_61 ) ;
V_62 = V_59 & ( ( 1U << 24 ) - 1U ) ;
V_63 = V_62 + V_60 ;
if ( V_63 > ( 1U << 24 ) )
V_63 = ( 1U << 24 ) ;
V_60 = V_63 - V_62 ;
return V_60 ;
}
static void F_30 ( struct V_3 * V_4 , T_1 V_50 )
{
T_1 V_64 = 1 , V_65 = 0x80 , V_66 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < 9 ; V_67 ++ ) {
if ( V_64 ) {
F_31 ( V_4 , 0x80 , 0x40 ) ;
V_66 = 0xc0 ;
} else
V_66 = 0x80 ;
F_32 ( 160 ) ;
F_31 ( V_4 , 0x80 , V_66 ) ;
F_32 ( 160 ) ;
F_31 ( V_4 , 0x80 , 0 ) ;
F_32 ( 160 ) ;
V_64 = ( V_50 & V_65 ) ? 1 : 0 ;
V_65 >>= 1 ;
}
}
static T_5 F_33 ( struct V_3 * V_4 )
{
int V_67 ;
T_5 V_68 = 0 ;
T_1 V_66 ;
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ ) {
V_68 <<= 1 ;
F_31 ( V_4 , 0x80 , 0x80 ) ;
F_32 ( 160 ) ;
F_31 ( V_4 , 0x80 , 0x40 ) ;
F_32 ( 160 ) ;
F_34 ( V_4 , 0x00 , & V_66 ) ;
if ( V_66 == 0x22 )
V_68 |= 1 ;
}
return V_68 ;
}
static void F_35 ( struct V_3 * V_4 , T_5 * V_69 )
{
T_1 V_50 = V_70 , V_67 ;
for ( V_67 = 0 ; V_67 < V_71 ; V_67 ++ ) {
F_31 ( V_4 , 0xc0 , 0 ) ;
F_32 ( 160 ) ;
F_30 ( V_4 , V_50 ++ ) ;
* V_69 ++ = F_33 ( V_4 ) ;
F_31 ( V_4 , 0x80 , 0 ) ;
F_31 ( V_4 , 0x80 , 0 ) ;
F_32 ( 160 ) ;
}
}
static void F_36 ( struct V_2 * V_2 )
{
T_1 V_72 [ 128 ] ;
T_5 * V_69 = ( T_5 * ) V_72 , V_68 = 0 ;
int V_67 ;
F_35 ( (struct V_3 * ) V_2 -> V_5 , V_69 ) ;
for ( V_67 = 0 ; V_67 < V_71 ; V_67 ++ , V_69 ++ )
V_68 += * V_69 ;
if ( V_68 != 0x1234 ) {
struct V_3 * V_4 = V_2 -> V_5 ;
F_37 ( V_31 , & V_4 -> V_5 ,
L_6 ) ;
return;
}
V_2 -> V_73 = V_72 [ V_74 ] ;
V_2 -> V_75 = 2 << V_72 [ V_76 ] ;
if ( V_72 [ V_77 ] & V_78 )
V_2 -> V_79 |= V_80 | V_81 ;
}
static int F_38 ( struct V_3 * V_4 ,
const struct V_82 * V_83 )
{
struct V_84 * V_85 = & V_86 ;
int V_87 = - V_88 ;
struct V_89 * V_90 ;
struct V_2 * V_2 ;
struct V_1 * V_16 ;
if ( F_39 ( V_4 ) ) {
F_37 ( V_31 , & V_4 -> V_5 , L_7 ) ;
return - V_88 ;
}
if ( F_40 ( V_4 , F_41 ( 32 ) ) ) {
F_37 ( V_31 , & V_4 -> V_5 ,
L_8 ) ;
goto V_91;
}
V_90 = F_42 ( V_85 , sizeof( struct V_2 ) ) ;
if ( ! V_90 ) {
F_37 ( V_31 , & V_4 -> V_5 ,
L_9 ) ;
V_87 = - V_92 ;
goto V_91;
}
V_16 = F_43 ( sizeof( struct V_1 ) , V_93 ) ;
if ( ! V_16 ) {
F_37 ( V_31 , & V_4 -> V_5 ,
L_10 ) ;
V_87 = - V_92 ;
goto V_94;
}
V_2 = F_44 ( V_90 ) ;
V_2 -> V_32 = V_90 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_95 = & V_96 ;
V_2 -> V_41 |= V_97 ;
if ( V_98 )
V_2 -> V_54 |= V_55 ;
V_16 -> V_2 = V_2 ;
if ( F_45 ( V_4 , V_99 ) ) {
F_37 ( V_100 , & V_4 -> V_5 ,
L_11 ) ;
goto V_101;
}
V_2 -> V_8 = F_46 ( V_4 , 0 , F_47 ( V_4 , 0 ) ) ;
if ( ! V_2 -> V_8 ) {
F_37 ( V_100 , & V_4 -> V_5 , L_12 ) ;
V_87 = - V_102 ;
goto V_103;
}
V_2 -> V_104 = V_2 -> V_8 ;
F_48 ( V_4 ) ;
V_2 -> V_105 = F_49 ( V_4 , 16 ,
& V_2 -> V_106 ) ;
if ( ! V_2 -> V_105 ) {
F_37 ( V_100 , & V_4 -> V_5 ,
L_13 ) ;
V_87 = - V_92 ;
goto V_107;
}
V_87 = F_50 ( V_4 -> V_108 , V_109 , V_110 ,
V_99 , V_2 ) ;
if ( V_87 < 0 ) {
F_37 ( V_100 , & V_4 -> V_5 , L_14 ) ;
goto V_111;
}
V_2 -> V_73 = 7 ;
F_36 ( V_2 ) ;
V_90 -> V_112 = V_2 -> V_73 ;
V_90 -> V_113 = 8 ;
V_90 -> V_108 = V_4 -> V_108 ;
V_90 -> V_114 = F_51 ( V_4 , 0 ) ;
V_90 -> V_115 = F_47 ( V_4 , 0 ) ;
V_90 -> V_116 = V_90 -> V_114 ;
V_2 -> V_117 = ( 1 << V_2 -> V_73 ) ;
V_2 -> V_118 = 40000000 ;
F_52 ( V_4 , V_16 ) ;
V_87 = F_53 ( V_2 , & V_4 -> V_5 ) ;
if ( V_87 )
goto V_119;
return 0 ;
V_119:
F_54 ( V_4 -> V_108 , V_2 ) ;
V_111:
F_55 ( V_4 , 16 , V_2 -> V_105 ,
V_2 -> V_106 ) ;
V_107:
F_56 ( V_4 , V_2 -> V_8 ) ;
V_103:
F_57 ( V_4 ) ;
V_101:
F_58 ( V_16 ) ;
V_94:
F_59 ( V_90 ) ;
V_91:
F_60 ( V_4 ) ;
return V_87 ;
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_1 * V_16 = F_2 ( V_4 ) ;
struct V_2 * V_2 = V_16 -> V_2 ;
F_62 ( V_2 ) ;
F_54 ( V_4 -> V_108 , V_2 ) ;
F_55 ( V_4 , 16 , V_2 -> V_105 ,
V_2 -> V_106 ) ;
F_56 ( V_4 , V_2 -> V_8 ) ;
F_57 ( V_4 ) ;
F_60 ( V_4 ) ;
F_58 ( V_16 ) ;
F_59 ( V_2 -> V_32 ) ;
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_120 ) ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_120 ) ;
}
