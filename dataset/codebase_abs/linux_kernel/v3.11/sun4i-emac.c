static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_7 ) ;
V_5 &= ~ ( 0x1 << 8 ) ;
if ( V_4 -> V_8 == V_9 )
V_5 |= 1 << 8 ;
F_4 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_10 ) ;
V_5 &= ~ V_11 ;
if ( V_4 -> V_12 )
V_5 |= V_11 ;
F_4 ( V_5 , V_4 -> V_6 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_4 -> V_15 ;
unsigned long V_16 ;
int V_17 = 0 ;
if ( V_14 -> V_18 ) {
if ( V_4 -> V_8 != V_14 -> V_8 ) {
F_7 ( & V_4 -> V_19 , V_16 ) ;
V_4 -> V_8 = V_14 -> V_8 ;
F_1 ( V_2 ) ;
F_8 ( & V_4 -> V_19 , V_16 ) ;
V_17 = 1 ;
}
if ( V_4 -> V_12 != V_14 -> V_12 ) {
F_7 ( & V_4 -> V_19 , V_16 ) ;
V_4 -> V_12 = V_14 -> V_12 ;
F_5 ( V_2 ) ;
F_8 ( & V_4 -> V_19 , V_16 ) ;
V_17 = 1 ;
}
}
if ( V_14 -> V_18 != V_4 -> V_18 ) {
if ( ! V_14 -> V_18 ) {
V_4 -> V_8 = 0 ;
V_4 -> V_12 = - 1 ;
}
V_4 -> V_18 = V_14 -> V_18 ;
V_17 = 1 ;
}
if ( V_17 )
F_9 ( V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_15 = F_11 ( V_4 -> V_20 , V_4 -> V_21 ,
& F_6 , 0 ,
V_4 -> V_22 ) ;
if ( ! V_4 -> V_15 ) {
F_12 ( V_4 -> V_20 , L_1 ) ;
return - V_23 ;
}
V_4 -> V_15 -> V_24 &= V_25 ;
V_4 -> V_15 -> V_26 = V_4 -> V_15 -> V_24 ;
V_4 -> V_18 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_12 = - 1 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_14 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_16 ( V_4 -> V_2 , L_2 ) ;
F_4 ( 0 , V_4 -> V_6 + V_27 ) ;
F_17 ( 200 ) ;
F_4 ( V_28 , V_4 -> V_6 + V_27 ) ;
F_17 ( 200 ) ;
}
static void F_18 ( void T_1 * V_29 , void * V_30 , int V_31 )
{
F_19 ( V_29 , V_30 , F_20 ( V_31 , 4 ) / 4 ) ;
}
static void F_21 ( void T_1 * V_29 , void * V_30 , int V_31 )
{
F_22 ( V_29 , V_30 , F_20 ( V_31 , 4 ) / 4 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_32 * V_33 , int V_34 )
{
struct V_3 * V_35 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_35 -> V_15 ;
if ( ! F_24 ( V_2 ) )
return - V_36 ;
if ( ! V_14 )
return - V_23 ;
return F_25 ( V_14 , V_33 , V_34 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
F_27 ( V_38 -> V_39 , V_40 , sizeof( V_40 ) ) ;
F_27 ( V_38 -> V_41 , V_42 , sizeof( V_42 ) ) ;
F_27 ( V_38 -> V_43 , F_28 ( & V_2 -> V_2 ) , sizeof( V_38 -> V_43 ) ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_44 * V_34 )
{
struct V_3 * V_35 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_35 -> V_15 ;
if ( ! V_14 )
return - V_23 ;
return F_30 ( V_14 , V_34 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_44 * V_34 )
{
struct V_3 * V_35 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_35 -> V_15 ;
if ( ! V_14 )
return - V_23 ;
return F_32 ( V_14 , V_34 ) ;
}
static unsigned int F_33 ( struct V_1 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
unsigned int V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_45 ) ;
F_4 ( V_5 | V_46 ,
V_4 -> V_6 + V_45 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_47 ) ;
F_4 ( V_5 | V_48 |
V_49 | V_50 |
V_51 |
V_52 ,
V_4 -> V_6 + V_47 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_53 ) ;
F_4 ( V_5 | V_54 |
V_55 ,
V_4 -> V_6 + V_53 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_10 ) ;
V_5 |= V_56 ;
V_5 |= V_57 ;
V_5 |= V_58 ;
F_4 ( V_5 , V_4 -> V_6 + V_10 ) ;
F_4 ( V_59 , V_4 -> V_6 + V_60 ) ;
F_4 ( ( V_61 << 8 ) | V_62 ,
V_4 -> V_6 + V_63 ) ;
F_4 ( ( V_64 << 8 ) | V_65 ,
V_4 -> V_6 + V_66 ) ;
F_4 ( V_67 ,
V_4 -> V_6 + V_68 ) ;
return 0 ;
}
static unsigned int F_34 ( struct V_1 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
unsigned int V_5 ;
V_5 = F_3 ( V_4 -> V_6 + V_47 ) ;
V_5 |= 0x8 ;
F_4 ( V_5 , V_4 -> V_6 + V_47 ) ;
F_17 ( 1 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_53 ) ;
V_5 &= ~ V_69 ;
F_4 ( V_5 , V_4 -> V_6 + V_53 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_70 ) ;
V_5 &= ( ~ ( 0xf << 2 ) ) ;
V_5 |= ( 0xD << 2 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_70 ) ;
F_4 ( 0x0 , V_4 -> V_6 + V_71 ) ;
F_4 ( 0 , V_4 -> V_6 + V_72 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_73 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_73 ) ;
F_17 ( 1 ) ;
F_33 ( V_20 ) ;
F_4 ( V_20 -> V_74 [ 0 ] << 16 | V_20 -> V_74 [ 1 ] << 8 | V_20 ->
V_74 [ 2 ] , V_4 -> V_6 + V_75 ) ;
F_4 ( V_20 -> V_74 [ 3 ] << 16 | V_20 -> V_74 [ 4 ] << 8 | V_20 ->
V_74 [ 5 ] , V_4 -> V_6 + V_76 ) ;
F_35 ( 1 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_77 )
{
struct V_78 * V_79 = V_77 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_24 ( V_2 ) )
return - V_80 ;
memcpy ( V_2 -> V_74 , V_79 -> V_81 , V_82 ) ;
F_4 ( V_2 -> V_74 [ 0 ] << 16 | V_2 -> V_74 [ 1 ] << 8 | V_2 ->
V_74 [ 2 ] , V_4 -> V_6 + V_75 ) ;
F_4 ( V_2 -> V_74 [ 3 ] << 16 | V_2 -> V_74 [ 4 ] << 8 | V_2 ->
V_74 [ 5 ] , V_4 -> V_6 + V_76 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_16 ;
unsigned int V_5 ;
F_7 ( & V_4 -> V_19 , V_16 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_27 ) ;
F_4 ( V_5 | V_28 | V_83 | V_84 ,
V_4 -> V_6 + V_27 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_72 ) ;
V_5 |= ( 0xf << 0 ) | ( 0x01 << 8 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_72 ) ;
F_8 ( & V_4 -> V_19 , V_16 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_16 ;
if ( F_39 ( V_4 ) )
F_40 ( V_4 -> V_2 , L_3 ) ;
F_7 ( & V_4 -> V_19 , V_16 ) ;
F_41 ( V_2 ) ;
F_15 ( V_4 ) ;
F_37 ( V_2 ) ;
V_2 -> V_85 = V_86 ;
F_42 ( V_2 ) ;
F_8 ( & V_4 -> V_19 , V_16 ) ;
}
static int F_43 ( struct V_87 * V_88 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_89 ;
unsigned long V_16 ;
V_89 = V_4 -> V_90 & 3 ;
if ( V_89 == 3 )
return 1 ;
V_89 = ( V_89 == 1 ? 1 : 0 ) ;
F_7 ( & V_4 -> V_19 , V_16 ) ;
F_4 ( V_89 , V_4 -> V_6 + V_91 ) ;
F_18 ( V_4 -> V_6 + V_92 ,
V_88 -> V_30 , V_88 -> V_93 ) ;
V_2 -> V_94 . V_95 += V_88 -> V_93 ;
V_4 -> V_90 |= 1 << V_89 ;
if ( V_89 == 0 ) {
F_4 ( V_88 -> V_93 , V_4 -> V_6 + V_96 ) ;
F_4 ( F_3 ( V_4 -> V_6 + V_97 ) | 1 ,
V_4 -> V_6 + V_97 ) ;
V_2 -> V_85 = V_86 ;
} else if ( V_89 == 1 ) {
F_4 ( V_88 -> V_93 , V_4 -> V_6 + V_98 ) ;
F_4 ( F_3 ( V_4 -> V_6 + V_99 ) | 1 ,
V_4 -> V_6 + V_99 ) ;
V_2 -> V_85 = V_86 ;
}
if ( ( V_4 -> V_90 & 3 ) == 3 ) {
F_41 ( V_2 ) ;
}
F_8 ( & V_4 -> V_19 , V_16 ) ;
F_44 ( V_88 ) ;
return V_100 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_101 )
{
V_4 -> V_90 &= ~ ( V_101 & 3 ) ;
if ( 3 == ( V_101 & 3 ) )
V_2 -> V_94 . V_102 += 2 ;
else
V_2 -> V_94 . V_102 ++ ;
if ( F_46 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_4 , V_101 ) ;
F_42 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_87 * V_88 ;
T_2 * V_103 ;
bool V_104 ;
static int V_105 ;
unsigned int V_5 ;
T_3 V_106 , V_107 , V_108 , V_109 ;
while ( 1 ) {
V_108 = F_3 ( V_4 -> V_6 + V_71 ) ;
if ( F_48 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_5 , V_108 ) ;
if ( ( V_4 -> V_110 != NULL ) && ( V_105 > 0 ) ) {
V_2 -> V_94 . V_111 += V_105 ;
V_4 -> V_110 -> V_112 = F_49 ( V_4 -> V_110 ,
V_2 ) ;
F_50 ( V_4 -> V_110 ) ;
V_2 -> V_94 . V_113 ++ ;
V_4 -> V_110 = NULL ;
V_105 = 0 ;
V_5 = F_3 ( V_4 -> V_6 + V_47 ) ;
V_5 &= ~ V_114 ;
F_4 ( V_5 , V_4 -> V_6 + V_47 ) ;
}
if ( ! V_108 ) {
V_4 -> V_115 = 1 ;
V_5 = F_3 ( V_4 -> V_6 + V_72 ) ;
V_5 |= ( 0xf << 0 ) | ( 0x01 << 8 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_72 ) ;
V_108 = F_3 ( V_4 -> V_6 + V_71 ) ;
if ( ! V_108 )
return;
}
V_5 = F_3 ( V_4 -> V_6 + V_116 ) ;
if ( F_48 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_6 , V_5 ) ;
if ( V_5 != V_117 ) {
V_5 = F_3 ( V_4 -> V_6 + V_27 ) ;
F_4 ( V_5 & ~ V_84 ,
V_4 -> V_6 + V_27 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_47 ) ;
F_4 ( V_5 | ( 1 << 3 ) ,
V_4 -> V_6 + V_47 ) ;
do {
V_5 = F_3 ( V_4 -> V_6 + V_47 ) ;
} while ( V_5 & ( 1 << 3 ) );
V_5 = F_3 ( V_4 -> V_6 + V_27 ) ;
F_4 ( V_5 | V_84 ,
V_4 -> V_6 + V_27 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_72 ) ;
V_5 |= ( 0xf << 0 ) | ( 0x01 << 8 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_72 ) ;
V_4 -> V_115 = 1 ;
return;
}
V_104 = true ;
F_21 ( V_4 -> V_6 + V_116 ,
& V_106 , sizeof( V_106 ) ) ;
if ( F_48 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_7 , * ( ( int * ) ( & V_106 ) ) ) ;
V_109 = F_51 ( V_106 ) ;
V_107 = F_52 ( V_106 ) ;
if ( F_48 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_8 ,
V_107 , V_109 ) ;
if ( V_109 < 0x40 ) {
V_104 = false ;
if ( F_53 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_9 ) ;
}
if ( F_54 ( ! ( V_107 & V_118 ) ) ) {
V_104 = false ;
if ( V_107 & V_119 ) {
if ( F_53 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_10 ) ;
V_2 -> V_94 . V_120 ++ ;
}
if ( V_107 & V_121 ) {
if ( F_53 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_11 ) ;
V_2 -> V_94 . V_122 ++ ;
}
}
V_88 = F_55 ( V_109 + 4 ) ;
if ( V_104 && V_88 ) {
F_56 ( V_88 , 2 ) ;
V_103 = ( T_2 * ) F_57 ( V_88 , V_109 - 4 ) ;
if ( F_48 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_12 , V_109 ) ;
F_21 ( V_4 -> V_6 + V_116 ,
V_103 , V_109 ) ;
V_2 -> V_94 . V_111 += V_109 ;
V_88 -> V_112 = F_49 ( V_88 , V_2 ) ;
F_50 ( V_88 ) ;
V_2 -> V_94 . V_113 ++ ;
}
}
}
static T_4 F_58 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_125 ;
unsigned long V_16 ;
unsigned int V_5 ;
F_7 ( & V_4 -> V_19 , V_16 ) ;
F_4 ( 0 , V_4 -> V_6 + V_72 ) ;
V_125 = F_3 ( V_4 -> V_6 + V_73 ) ;
F_4 ( V_125 , V_4 -> V_6 + V_73 ) ;
if ( F_59 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_13 , V_125 ) ;
if ( ( V_125 & 0x100 ) && ( V_4 -> V_115 == 1 ) ) {
V_4 -> V_115 = 0 ;
F_47 ( V_2 ) ;
}
if ( V_125 & ( 0x01 | 0x02 ) )
F_45 ( V_2 , V_4 , V_125 ) ;
if ( V_125 & ( 0x04 | 0x08 ) )
F_60 ( V_2 , L_14 , V_125 ) ;
if ( V_4 -> V_115 == 1 ) {
V_5 = F_3 ( V_4 -> V_6 + V_72 ) ;
V_5 |= ( 0xf << 0 ) | ( 0x01 << 8 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_72 ) ;
}
F_8 ( & V_4 -> V_19 , V_16 ) ;
return V_126 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_123 ) ;
F_58 ( V_2 -> V_123 , V_2 ) ;
F_63 ( V_2 -> V_123 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_127 ;
if ( F_65 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_15 , V_2 -> V_128 ) ;
if ( F_66 ( V_4 -> V_2 , V_2 -> V_123 , & F_58 ,
0 , V_2 -> V_128 , V_2 ) )
return - V_129 ;
F_15 ( V_4 ) ;
F_37 ( V_2 ) ;
V_127 = F_10 ( V_2 ) ;
if ( V_127 < 0 ) {
F_12 ( V_2 , L_16 ) ;
return V_127 ;
}
F_67 ( V_4 -> V_15 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( 0 , V_4 -> V_6 + V_72 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_73 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_73 ) ;
V_5 = F_3 ( V_4 -> V_6 + V_27 ) ;
V_5 &= ~ ( V_83 | V_84 | V_28 ) ;
F_4 ( V_5 , V_4 -> V_6 + V_27 ) ;
}
static int F_70 ( struct V_1 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 ) ;
if ( F_71 ( V_4 ) )
F_16 ( V_4 -> V_2 , L_17 , V_20 -> V_128 ) ;
F_41 ( V_20 ) ;
F_72 ( V_20 ) ;
F_73 ( V_4 -> V_15 ) ;
F_13 ( V_20 ) ;
F_69 ( V_20 ) ;
return 0 ;
}
static int F_74 ( struct V_130 * V_131 )
{
struct V_132 * V_133 = V_131 -> V_2 . V_134 ;
struct V_3 * V_4 ;
struct V_1 * V_20 ;
int V_127 = 0 ;
const char * V_135 ;
V_20 = F_75 ( sizeof( struct V_3 ) ) ;
if ( ! V_20 ) {
F_40 ( & V_131 -> V_2 , L_18 ) ;
return - V_136 ;
}
F_76 ( V_20 , & V_131 -> V_2 ) ;
V_4 = F_2 ( V_20 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_2 = & V_131 -> V_2 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_131 = V_131 ;
F_77 ( & V_4 -> V_19 ) ;
V_4 -> V_6 = F_78 ( V_133 , 0 ) ;
if ( ! V_4 -> V_6 ) {
F_40 ( & V_131 -> V_2 , L_19 ) ;
V_127 = - V_136 ;
goto V_137;
}
V_20 -> V_138 = ( unsigned long ) V_4 -> V_6 ;
V_20 -> V_123 = F_79 ( V_133 , 0 ) ;
if ( V_20 -> V_123 == - V_139 ) {
F_12 ( V_20 , L_20 ) ;
V_127 = V_20 -> V_123 ;
goto V_137;
}
V_4 -> V_140 = F_80 ( & V_131 -> V_2 , NULL ) ;
if ( F_81 ( V_4 -> V_140 ) )
goto V_137;
F_82 ( V_4 -> V_140 ) ;
V_4 -> V_21 = F_83 ( V_133 , L_21 , 0 ) ;
if ( ! V_4 -> V_21 ) {
F_40 ( & V_131 -> V_2 , L_22 ) ;
V_127 = - V_23 ;
goto V_137;
}
V_135 = F_84 ( V_133 ) ;
if ( V_135 )
memcpy ( V_20 -> V_74 , V_135 , V_82 ) ;
if ( ! F_85 ( V_20 -> V_74 ) ) {
F_86 ( V_20 ) ;
F_87 ( & V_131 -> V_2 , L_23 ,
V_20 -> V_74 ) ;
}
V_4 -> V_115 = 1 ;
F_34 ( V_20 ) ;
F_15 ( V_4 ) ;
F_88 ( V_20 ) ;
V_20 -> V_141 = & V_142 ;
V_20 -> V_143 = F_89 ( V_144 ) ;
V_20 -> V_145 = & V_146 ;
F_90 ( V_131 , V_20 ) ;
F_72 ( V_20 ) ;
V_127 = F_91 ( V_20 ) ;
if ( V_127 ) {
F_40 ( & V_131 -> V_2 , L_24 ) ;
V_127 = - V_23 ;
goto V_137;
}
F_92 ( & V_131 -> V_2 , L_25 ,
V_20 -> V_128 , V_4 -> V_6 , V_20 -> V_123 , V_20 -> V_74 ) ;
return 0 ;
V_137:
F_40 ( V_4 -> V_2 , L_26 , V_127 ) ;
F_93 ( V_20 ) ;
return V_127 ;
}
static int F_94 ( struct V_130 * V_131 )
{
struct V_1 * V_20 = F_95 ( V_131 ) ;
F_96 ( V_20 ) ;
F_93 ( V_20 ) ;
F_16 ( & V_131 -> V_2 , L_27 ) ;
return 0 ;
}
static int F_97 ( struct V_130 * V_2 , T_5 V_147 )
{
struct V_1 * V_20 = F_95 ( V_2 ) ;
F_72 ( V_20 ) ;
F_98 ( V_20 ) ;
F_69 ( V_20 ) ;
return 0 ;
}
static int F_99 ( struct V_130 * V_2 )
{
struct V_1 * V_20 = F_95 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_20 ) ;
F_15 ( V_4 ) ;
F_37 ( V_20 ) ;
F_100 ( V_20 ) ;
return 0 ;
}
