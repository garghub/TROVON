static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
if ( F_2 ( V_2 ) )
return;
if ( ! V_4 || ! V_4 -> V_7 || ! V_4 -> V_8 )
return;
#ifdef F_3
if ( V_4 -> V_9 . type == V_10 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
if ( V_5 )
F_4 ( V_12 -> V_14 , V_12 -> V_6 ) ;
else
F_5 ( V_12 -> V_14 , V_12 -> V_6 ) ;
return;
}
#endif
V_6 = ( V_4 -> V_8 + V_15 - 1 ) >> V_16 ;
if ( V_5 )
F_6 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
else
F_7 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_17 ,
bool V_5 )
{
F_1 ( V_2 , V_17 , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
struct V_19 * V_20 , bool V_5 )
{
if ( V_18 -> V_21 != V_5 ) {
F_1 ( V_2 , F_10 ( V_20 ) , V_5 ) ;
V_18 -> V_21 = V_5 ;
}
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_17 ,
bool V_5 )
{
}
static inline void F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
struct V_19 * V_20 , bool V_5 )
{
}
static void F_11 ( struct V_22 * V_23 , unsigned int V_24 ,
unsigned char V_25 , unsigned char V_26 )
{
unsigned char V_27 ;
F_12 ( V_23 , V_24 , & V_27 ) ;
V_27 &= ~ V_25 ;
V_27 |= ( V_26 & V_25 ) ;
F_13 ( V_23 , V_24 , V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_28 & V_29 ) ) {
F_15 ( V_2 -> V_30 -> V_9 , L_1 ) ;
F_11 ( V_2 -> V_23 , V_31 , 0x07 , 0 ) ;
}
if ( V_2 -> V_28 & V_32 ) {
F_15 ( V_2 -> V_30 -> V_9 , L_2 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_23 ,
V_33 , 0x07 ,
F_2 ( V_2 ) ? V_34 : 0 ) ;
}
if ( V_2 -> V_28 & V_35 ) {
F_15 ( V_2 -> V_30 -> V_9 , L_3 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_23 ,
V_36 ,
0x0f , V_37 ) ;
F_11 ( V_2 -> V_23 ,
V_38 ,
0x01 , V_39 ) ;
F_11 ( V_2 -> V_23 ,
V_40 ,
0x01 , V_39 ) ;
}
if ( V_2 -> V_28 & V_41 ) {
unsigned short V_42 ;
F_16 ( V_2 -> V_23 , V_43 , & V_42 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_42 & V_44 ) ) ||
( F_2 ( V_2 ) && ( V_42 & V_44 ) ) ) {
V_42 &= ~ V_44 ;
if ( ! F_2 ( V_2 ) )
V_42 |= V_44 ;
F_17 ( V_2 -> V_23 , V_43 , V_42 ) ;
F_16 ( V_2 -> V_23 ,
V_43 , & V_42 ) ;
}
F_15 ( V_2 -> V_30 -> V_9 , L_4 ,
( V_42 & V_44 ) ?
L_5 : L_6 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_18 * V_18 ,
unsigned int V_45 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
int V_46 = V_20 -> V_46 ;
unsigned int V_47 = F_19 ( V_2 , V_18 ) ;
int V_48 ;
if ( V_46 == V_49 )
V_48 = V_45 - V_47 ;
else
V_48 = V_47 - V_45 ;
if ( V_48 < 0 ) {
if ( V_48 >= V_18 -> V_50 )
V_48 = 0 ;
else
V_48 += V_18 -> V_51 ;
}
if ( V_48 >= V_18 -> V_52 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_7 ,
V_48 , V_18 -> V_52 ) ;
V_48 = 0 ;
V_2 -> V_28 &= ~ V_53 ;
V_2 -> V_54 [ V_46 ] = NULL ;
}
return F_21 ( V_20 -> V_55 , V_48 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
int V_58 ;
V_58 = F_24 ( V_2 , V_18 ) ;
if ( V_58 == 1 ) {
V_18 -> V_59 = 0 ;
return V_58 ;
} else if ( V_58 == 0 && V_2 -> V_60 && V_2 -> V_60 -> V_61 ) {
V_18 -> V_59 = 1 ;
F_25 ( V_2 -> V_60 -> V_61 , & V_57 -> V_62 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
int V_46 = V_20 -> V_46 ;
T_1 V_63 ;
unsigned int V_45 ;
V_63 = F_26 ( V_2 , V_64 ) - V_18 -> V_65 ;
if ( V_63 < ( V_18 -> V_66 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_67 [ V_46 ] )
V_45 = V_2 -> V_67 [ V_46 ] ( V_2 , V_18 ) ;
else {
V_45 = F_27 ( V_2 , V_18 ) ;
if ( ! V_45 || V_45 == ( T_1 ) - 1 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_8 ) ;
V_2 -> V_67 [ V_46 ] = F_19 ;
V_45 = F_19 ( V_2 , V_18 ) ;
V_2 -> V_54 [ V_46 ] = NULL ;
} else {
V_2 -> V_67 [ V_46 ] = F_27 ;
if ( V_2 -> V_28 & V_53 )
V_2 -> V_54 [ V_46 ] = F_18 ;
}
}
if ( V_45 >= V_18 -> V_51 )
V_45 = 0 ;
if ( F_28 ( ! V_18 -> V_52 ,
L_9 ) )
return - 1 ;
if ( V_63 < ( V_18 -> V_66 * 5 ) / 4 &&
V_45 % V_18 -> V_52 > V_18 -> V_52 / 2 )
return V_2 -> V_68 [ V_2 -> V_69 ] ? 0 : - 1 ;
V_18 -> V_65 += V_63 ;
return 1 ;
}
static void F_29 ( struct V_70 * V_71 )
{
struct V_56 * V_57 = F_23 ( V_71 , struct V_56 , V_62 ) ;
struct V_1 * V_2 = & V_57 -> V_2 ;
int V_72 , V_73 , V_58 ;
if ( ! V_57 -> V_74 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_10 ,
V_2 -> V_30 -> V_75 ) ;
V_57 -> V_74 = 1 ;
}
for (; ; ) {
V_73 = 0 ;
F_30 ( & V_2 -> V_76 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_77 ; V_72 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_72 ] ;
if ( ! V_18 -> V_59 ||
! V_18 -> V_20 ||
! V_18 -> V_78 )
continue;
V_58 = F_24 ( V_2 , V_18 ) ;
if ( V_58 > 0 ) {
V_18 -> V_59 = 0 ;
F_31 ( & V_2 -> V_76 ) ;
F_32 ( V_18 -> V_20 ) ;
F_33 ( & V_2 -> V_76 ) ;
} else if ( V_58 < 0 ) {
V_73 = 0 ;
} else
V_73 ++ ;
}
F_34 ( & V_2 -> V_76 ) ;
if ( ! V_73 )
return;
F_35 ( 1 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
int V_72 ;
F_30 ( & V_2 -> V_76 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_77 ; V_72 ++ )
V_2 -> V_18 [ V_72 ] . V_59 = 0 ;
F_34 ( & V_2 -> V_76 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_79 )
{
if ( F_38 ( V_2 -> V_23 -> V_80 , V_81 ,
V_2 -> V_82 ? 0 : V_83 ,
V_84 , V_2 ) ) {
F_39 ( V_2 -> V_30 -> V_9 ,
L_11 ,
V_2 -> V_23 -> V_80 ) ;
if ( V_79 )
F_40 ( V_2 -> V_30 ) ;
return - 1 ;
}
V_2 -> V_80 = V_2 -> V_23 -> V_80 ;
F_41 ( V_2 -> V_23 , ! V_2 -> V_82 ) ;
return 0 ;
}
static unsigned int F_42 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
unsigned int V_85 , V_86 , V_87 ;
unsigned int V_88 , V_89 , V_90 ;
unsigned int V_91 ;
V_85 = F_43 ( V_2 , V_18 , V_92 ) ;
if ( V_18 -> V_20 -> V_46 == V_49 ) {
return V_85 ;
}
V_89 = F_44 ( * V_18 -> V_93 ) ;
V_89 %= V_18 -> V_52 ;
V_91 = F_45 ( V_2 -> V_94 + V_95 ) ;
if ( V_18 -> V_96 ) {
if ( V_85 <= V_91 )
return 0 ;
V_18 -> V_96 = 0 ;
}
if ( V_85 <= V_91 )
V_86 = V_18 -> V_51 + V_85 - V_91 ;
else
V_86 = V_85 - V_91 ;
V_90 = V_86 % V_18 -> V_52 ;
V_88 = V_85 % V_18 -> V_52 ;
if ( V_88 >= V_91 )
V_87 = V_85 - V_88 ;
else if ( V_89 >= V_90 )
V_87 = V_86 - V_90 ;
else {
V_87 = V_86 - V_90 + V_18 -> V_52 ;
if ( V_87 >= V_18 -> V_51 )
V_87 = 0 ;
}
return V_87 + V_89 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
F_47 ( & V_97 ) ;
F_48 ( & V_57 -> V_98 , & V_99 ) ;
F_49 ( & V_97 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
F_47 ( & V_97 ) ;
F_51 ( & V_57 -> V_98 ) ;
F_49 ( & V_97 ) ;
}
static int F_52 ( const char * V_26 , const struct V_100 * V_101 )
{
struct V_56 * V_57 ;
struct V_1 * V_2 ;
struct V_102 * V_103 ;
int V_104 = V_105 ;
int V_106 = F_53 ( V_26 , V_101 ) ;
if ( V_106 || V_104 == V_105 )
return V_106 ;
F_47 ( & V_97 ) ;
F_54 (hda, &card_list, list) {
V_2 = & V_57 -> V_2 ;
if ( ! V_2 -> V_60 || V_2 -> V_107 )
continue;
F_54 (c, &chip->bus->codec_list, list)
F_55 ( V_103 ) ;
}
F_49 ( & V_97 ) ;
return 0 ;
}
static int F_56 ( struct V_108 * V_9 )
{
struct V_22 * V_23 = F_57 ( V_9 ) ;
struct V_109 * V_30 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
struct V_110 * V_111 ;
if ( ! V_30 )
return 0 ;
V_2 = V_30 -> V_13 ;
V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
if ( V_2 -> V_107 || V_57 -> V_112 )
return 0 ;
F_59 ( V_30 , V_113 ) ;
F_36 ( V_2 ) ;
F_54 (p, &chip->pcm_list, list)
F_60 ( V_111 -> V_114 ) ;
if ( V_2 -> V_115 )
F_61 ( V_2 -> V_60 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_80 >= 0 ) {
F_64 ( V_2 -> V_80 , V_2 ) ;
V_2 -> V_80 = - 1 ;
}
if ( V_2 -> V_82 )
F_65 ( V_2 -> V_23 ) ;
F_66 ( V_23 ) ;
F_67 ( V_23 ) ;
F_68 ( V_23 , V_116 ) ;
if ( V_2 -> V_28 & V_117 )
F_69 ( false ) ;
return 0 ;
}
static int F_70 ( struct V_108 * V_9 )
{
struct V_22 * V_23 = F_57 ( V_9 ) ;
struct V_109 * V_30 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
if ( ! V_30 )
return 0 ;
V_2 = V_30 -> V_13 ;
V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
if ( V_2 -> V_107 || V_57 -> V_112 )
return 0 ;
if ( V_2 -> V_28 & V_117 ) {
F_69 ( true ) ;
F_71 ( V_2 ) ;
}
F_68 ( V_23 , V_118 ) ;
F_72 ( V_23 ) ;
if ( F_73 ( V_23 ) < 0 ) {
F_39 ( V_2 -> V_30 -> V_9 ,
L_12 ) ;
F_40 ( V_30 ) ;
return - V_119 ;
}
F_74 ( V_23 ) ;
if ( V_2 -> V_82 )
if ( F_75 ( V_23 ) < 0 )
V_2 -> V_82 = 0 ;
if ( F_37 ( V_2 , 1 ) < 0 )
return - V_119 ;
F_14 ( V_2 ) ;
F_76 ( V_2 , true ) ;
F_77 ( V_2 -> V_60 ) ;
F_59 ( V_30 , V_120 ) ;
return 0 ;
}
static int F_78 ( struct V_108 * V_9 )
{
struct V_109 * V_30 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
if ( ! V_30 )
return 0 ;
V_2 = V_30 -> V_13 ;
V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
if ( V_2 -> V_107 || V_57 -> V_112 )
return 0 ;
if ( ! ( V_2 -> V_28 & V_121 ) )
return 0 ;
F_79 ( V_2 , V_122 , F_80 ( V_2 , V_122 ) |
V_123 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( V_2 -> V_28 & V_117 )
F_69 ( false ) ;
return 0 ;
}
static int F_81 ( struct V_108 * V_9 )
{
struct V_109 * V_30 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
struct V_124 * V_60 ;
struct V_102 * V_125 ;
int V_126 ;
if ( ! V_30 )
return 0 ;
V_2 = V_30 -> V_13 ;
V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
if ( V_2 -> V_107 || V_57 -> V_112 )
return 0 ;
if ( ! ( V_2 -> V_28 & V_121 ) )
return 0 ;
if ( V_2 -> V_28 & V_117 ) {
F_69 ( true ) ;
F_71 ( V_2 ) ;
}
V_126 = F_80 ( V_2 , V_127 ) ;
F_14 ( V_2 ) ;
F_76 ( V_2 , true ) ;
V_60 = V_2 -> V_60 ;
if ( V_126 && V_60 ) {
F_54 (codec, &bus->codec_list, list)
if ( V_126 & ( 1 << V_125 -> V_128 ) )
F_82 ( V_125 -> V_60 -> V_61 ,
& V_125 -> V_129 , V_125 -> V_130 ) ;
}
F_79 ( V_2 , V_122 , F_80 ( V_2 , V_122 ) &
~ V_123 ) ;
return 0 ;
}
static int F_83 ( struct V_108 * V_9 )
{
struct V_109 * V_30 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_56 * V_57 ;
if ( ! V_30 )
return 0 ;
V_2 = V_30 -> V_13 ;
V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
if ( V_2 -> V_107 || V_57 -> V_112 )
return 0 ;
if ( ! V_131 ||
! ( V_2 -> V_28 & V_121 ) )
return - V_132 ;
return 0 ;
}
static void F_84 ( struct V_22 * V_23 ,
enum V_133 V_134 )
{
struct V_109 * V_30 = F_85 ( V_23 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
bool V_107 ;
F_86 ( & V_57 -> V_135 ) ;
if ( V_57 -> V_112 )
return;
V_107 = ( V_134 == V_136 ) ;
if ( V_2 -> V_107 == V_107 )
return;
if ( ! V_2 -> V_60 ) {
V_2 -> V_107 = V_107 ;
if ( ! V_107 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_13 ) ;
if ( F_87 ( V_2 ) < 0 ) {
F_39 ( V_2 -> V_30 -> V_9 , L_14 ) ;
V_57 -> V_112 = true ;
}
}
} else {
F_20 ( V_2 -> V_30 -> V_9 , L_15 ,
V_107 ? L_16 : L_17 ) ;
if ( V_107 ) {
F_88 ( V_30 -> V_9 ) ;
F_56 ( V_30 -> V_9 ) ;
V_23 -> V_137 = V_138 ;
V_2 -> V_107 = true ;
if ( F_89 ( V_2 -> V_60 ) )
F_90 ( V_2 -> V_30 -> V_9 ,
L_18 ) ;
} else {
F_91 ( V_2 -> V_60 ) ;
F_92 ( V_30 -> V_9 ) ;
V_2 -> V_107 = false ;
F_70 ( V_30 -> V_9 ) ;
}
}
}
static bool F_93 ( struct V_22 * V_23 )
{
struct V_109 * V_30 = F_85 ( V_23 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
F_86 ( & V_57 -> V_135 ) ;
if ( V_57 -> V_112 )
return false ;
if ( V_2 -> V_107 || ! V_2 -> V_60 )
return true ;
if ( F_89 ( V_2 -> V_60 ) )
return false ;
F_91 ( V_2 -> V_60 ) ;
return true ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
struct V_22 * V_111 = F_95 ( V_2 -> V_23 ) ;
if ( V_111 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_19 ) ;
V_57 -> V_139 = 1 ;
F_96 ( V_111 ) ;
}
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
int V_140 ;
if ( ! V_57 -> V_139 )
return 0 ;
V_140 = F_98 ( V_2 -> V_23 , & V_141 ,
V_142 ,
V_2 -> V_60 != NULL ) ;
if ( V_140 < 0 )
return V_140 ;
V_57 -> V_143 = 1 ;
F_99 ( V_2 -> V_30 -> V_9 ,
& V_57 -> V_144 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
int V_72 ;
if ( ( V_2 -> V_28 & V_121 )
&& V_2 -> V_78 )
F_92 ( & V_23 -> V_9 ) ;
F_50 ( V_2 ) ;
F_101 ( V_2 ) ;
V_57 -> V_112 = 1 ;
F_102 ( & V_57 -> V_135 ) ;
if ( V_139 ( V_57 ) ) {
if ( V_2 -> V_107 && V_2 -> V_60 )
F_91 ( V_2 -> V_60 ) ;
if ( V_57 -> V_143 )
F_103 ( V_2 -> V_23 ) ;
}
if ( V_2 -> V_115 ) {
F_36 ( V_2 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_77 ; V_72 ++ )
F_104 ( V_2 , & V_2 -> V_18 [ V_72 ] ) ;
F_62 ( V_2 ) ;
}
if ( V_2 -> V_80 >= 0 )
F_64 ( V_2 -> V_80 , ( void * ) V_2 ) ;
if ( V_2 -> V_82 )
F_65 ( V_2 -> V_23 ) ;
if ( V_2 -> V_94 )
F_105 ( V_2 -> V_94 ) ;
F_106 ( V_2 ) ;
if ( V_2 -> V_145 )
F_107 ( V_2 -> V_23 ) ;
F_66 ( V_2 -> V_23 ) ;
F_108 ( V_2 -> V_18 ) ;
#ifdef F_109
if ( V_2 -> V_146 )
F_110 ( V_2 -> V_146 ) ;
#endif
if ( V_2 -> V_28 & V_117 ) {
F_69 ( false ) ;
F_111 () ;
}
F_108 ( V_57 ) ;
return 0 ;
}
static int F_112 ( struct V_147 * V_108 )
{
return F_100 ( V_108 -> V_148 ) ;
}
static struct V_22 * F_95 ( struct V_22 * V_23 )
{
struct V_22 * V_111 ;
switch ( V_23 -> V_149 ) {
case V_150 :
case V_151 :
case V_152 :
if ( V_23 -> V_153 == 1 ) {
V_111 = F_113 ( F_114 ( V_23 -> V_60 ) ,
V_23 -> V_60 -> V_75 , 0 ) ;
if ( V_111 ) {
if ( ( V_111 -> V_154 >> 8 ) == V_155 )
return V_111 ;
F_96 ( V_111 ) ;
}
}
break;
}
return NULL ;
}
static bool F_115 ( struct V_22 * V_23 )
{
bool V_156 = false ;
struct V_22 * V_111 = F_95 ( V_23 ) ;
if ( V_111 ) {
if ( F_116 ( V_111 ) == V_136 )
V_156 = true ;
F_96 ( V_111 ) ;
}
return V_156 ;
}
static int F_117 ( struct V_1 * V_2 , int V_157 )
{
const struct V_158 * V_159 ;
switch ( V_157 ) {
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
return V_157 ;
}
V_159 = F_118 ( V_2 -> V_23 , V_165 ) ;
if ( V_159 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_20 ,
V_159 -> V_166 , V_159 -> V_167 , V_159 -> V_168 ) ;
return V_159 -> V_166 ;
}
if ( V_2 -> V_28 & V_169 ) {
F_15 ( V_2 -> V_30 -> V_9 , L_21 ) ;
return V_163 ;
}
if ( V_2 -> V_28 & V_170 ) {
F_15 ( V_2 -> V_30 -> V_9 , L_22 ) ;
return V_161 ;
}
return V_160 ;
}
static void F_119 ( struct V_1 * V_2 , int V_157 )
{
static T_2 V_171 [] = {
[ V_160 ] = NULL ,
[ V_161 ] = F_19 ,
[ V_162 ] = F_27 ,
[ V_163 ] = F_42 ,
[ V_164 ] = F_19 ,
} ;
V_2 -> V_67 [ 0 ] = V_2 -> V_67 [ 1 ] = V_171 [ V_157 ] ;
if ( V_157 == V_164 )
V_2 -> V_67 [ 1 ] = NULL ;
if ( V_157 == V_162 &&
( V_2 -> V_28 & V_53 ) ) {
V_2 -> V_54 [ 0 ] = V_2 -> V_54 [ 1 ] =
F_18 ;
}
}
static void F_120 ( struct V_1 * V_2 , int V_9 )
{
const struct V_158 * V_159 ;
V_2 -> V_172 = V_173 [ V_9 ] ;
if ( V_2 -> V_172 == - 1 ) {
V_159 = F_118 ( V_2 -> V_23 , V_174 ) ;
if ( V_159 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_23 ,
V_159 -> V_166 , V_159 -> V_167 , V_159 -> V_168 ) ;
V_2 -> V_172 = V_159 -> V_166 ;
}
}
if ( V_2 -> V_172 != - 1 &&
( V_2 -> V_172 & V_175 ) ) {
V_2 -> V_176 = V_2 -> V_172 & 0xff ;
F_20 ( V_2 -> V_30 -> V_9 , L_24 ,
V_2 -> V_176 ) ;
}
}
static void F_121 ( struct V_1 * V_2 )
{
const struct V_158 * V_159 ;
if ( V_177 >= 0 ) {
V_2 -> V_82 = ! ! V_177 ;
return;
}
V_2 -> V_82 = 1 ;
V_159 = F_118 ( V_2 -> V_23 , V_178 ) ;
if ( V_159 ) {
F_20 ( V_2 -> V_30 -> V_9 ,
L_25 ,
V_159 -> V_167 , V_159 -> V_168 , V_159 -> V_166 ) ;
V_2 -> V_82 = V_159 -> V_166 ;
return;
}
if ( V_2 -> V_28 & V_179 ) {
F_20 ( V_2 -> V_30 -> V_9 , L_26 ) ;
V_2 -> V_82 = 0 ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
bool V_42 = V_2 -> V_42 ;
switch ( V_2 -> V_180 ) {
case V_181 :
if ( V_42 ) {
T_3 V_26 ;
F_12 ( V_2 -> V_23 , 0x42 , & V_26 ) ;
if ( ! ( V_26 & 0x80 ) && V_2 -> V_23 -> V_182 == 0x30 )
V_42 = false ;
}
break;
case V_183 :
V_42 = false ;
break;
case V_184 :
case V_185 :
V_42 = false ;
break;
}
if ( V_42 != V_2 -> V_42 ) {
F_20 ( V_2 -> V_30 -> V_9 , L_27 ,
V_42 ? L_28 : L_29 ) ;
V_2 -> V_42 = V_42 ;
}
}
static void F_123 ( struct V_70 * V_71 )
{
struct V_56 * V_57 = F_23 ( V_71 , struct V_56 , V_186 ) ;
F_87 ( & V_57 -> V_2 ) ;
}
static int F_124 ( struct V_109 * V_30 , struct V_22 * V_23 ,
int V_9 , unsigned int V_28 ,
const struct V_187 * V_188 ,
struct V_1 * * V_189 )
{
static struct V_190 V_191 = {
. V_192 = F_112 ,
} ;
struct V_56 * V_57 ;
struct V_1 * V_2 ;
int V_140 ;
* V_189 = NULL ;
V_140 = F_73 ( V_23 ) ;
if ( V_140 < 0 )
return V_140 ;
V_57 = F_125 ( sizeof( * V_57 ) , V_193 ) ;
if ( ! V_57 ) {
F_39 ( V_30 -> V_9 , L_30 ) ;
F_66 ( V_23 ) ;
return - V_194 ;
}
V_2 = & V_57 -> V_2 ;
F_126 ( & V_2 -> V_76 ) ;
F_127 ( & V_2 -> V_195 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_191 = V_188 ;
V_2 -> V_80 = - 1 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_180 = V_28 & 0xff ;
F_121 ( V_2 ) ;
V_2 -> V_69 = V_9 ;
V_2 -> V_196 = V_196 ;
F_128 ( & V_2 -> V_197 ) ;
F_129 ( & V_57 -> V_62 , F_29 ) ;
F_128 ( & V_57 -> V_98 ) ;
F_94 ( V_2 ) ;
F_130 ( & V_57 -> V_135 ) ;
F_119 ( V_2 , F_117 ( V_2 , V_198 [ V_9 ] ) ) ;
F_120 ( V_2 , V_9 ) ;
V_2 -> V_199 = V_199 ;
V_2 -> V_42 = V_200 ;
F_122 ( V_2 ) ;
if ( V_68 [ V_9 ] < 0 ) {
switch ( V_2 -> V_180 ) {
case V_201 :
case V_202 :
V_68 [ V_9 ] = 1 ;
break;
default:
V_68 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_68 = V_68 ;
V_140 = F_131 ( V_30 , V_203 , V_2 , & V_191 ) ;
if ( V_140 < 0 ) {
F_39 ( V_30 -> V_9 , L_31 ) ;
F_100 ( V_2 ) ;
return V_140 ;
}
F_129 ( & V_57 -> V_186 , F_123 ) ;
* V_189 = V_2 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_69 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_109 * V_30 = V_2 -> V_30 ;
int V_140 ;
unsigned short V_204 ;
#if V_205 != 64
if ( V_2 -> V_180 == V_206 ) {
T_4 V_207 ;
F_16 ( V_23 , 0x40 , & V_207 ) ;
F_17 ( V_23 , 0x40 , V_207 | 0x10 ) ;
F_133 ( V_23 , V_208 , 0 ) ;
}
#endif
V_140 = F_134 ( V_23 , L_32 ) ;
if ( V_140 < 0 )
return V_140 ;
V_2 -> V_145 = 1 ;
V_2 -> V_128 = F_135 ( V_23 , 0 ) ;
V_2 -> V_94 = F_136 ( V_23 , 0 ) ;
if ( V_2 -> V_94 == NULL ) {
F_39 ( V_30 -> V_9 , L_33 ) ;
return - V_209 ;
}
if ( V_2 -> V_82 )
if ( F_75 ( V_23 ) < 0 )
V_2 -> V_82 = 0 ;
if ( F_37 ( V_2 , 0 ) < 0 )
return - V_132 ;
F_74 ( V_23 ) ;
F_137 ( V_2 -> V_80 ) ;
V_204 = F_80 ( V_2 , V_210 ) ;
F_15 ( V_30 -> V_9 , L_34 , V_204 ) ;
if ( V_2 -> V_23 -> V_149 == V_150 ) {
struct V_22 * V_211 ;
V_211 = F_138 ( V_150 ,
V_212 ,
NULL ) ;
if ( V_211 ) {
if ( V_211 -> V_182 < 0x30 )
V_204 &= ~ V_213 ;
F_96 ( V_211 ) ;
}
}
if ( V_2 -> V_28 & V_214 ) {
F_15 ( V_30 -> V_9 , L_35 ) ;
V_204 &= ~ V_213 ;
}
if ( V_215 >= 0 )
V_2 -> V_215 = ! ! V_215 ;
else {
if ( V_2 -> V_28 & V_216 )
V_2 -> V_215 = 0 ;
else if ( V_2 -> V_28 & V_217 )
V_2 -> V_215 = 1 ;
else
V_2 -> V_215 = 1 ;
}
if ( ( V_204 & V_213 ) && ! F_139 ( V_23 , F_140 ( 64 ) ) )
F_141 ( V_23 , F_140 ( 64 ) ) ;
else {
F_139 ( V_23 , F_140 ( 32 ) ) ;
F_141 ( V_23 , F_140 ( 32 ) ) ;
}
V_2 -> V_218 = ( V_204 >> 8 ) & 0x0f ;
V_2 -> V_219 = ( V_204 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_219 && ! V_2 -> V_218 ) {
switch ( V_2 -> V_180 ) {
case V_206 :
V_2 -> V_219 = V_220 ;
V_2 -> V_218 = V_221 ;
break;
case V_222 :
case V_183 :
V_2 -> V_219 = V_223 ;
V_2 -> V_218 = V_224 ;
break;
case V_225 :
default:
V_2 -> V_219 = V_226 ;
V_2 -> V_218 = V_227 ;
break;
}
}
V_2 -> V_228 = 0 ;
V_2 -> V_229 = V_2 -> V_218 ;
V_2 -> V_77 = V_2 -> V_219 + V_2 -> V_218 ;
V_2 -> V_18 = F_142 ( V_2 -> V_77 , sizeof( * V_2 -> V_18 ) ,
V_193 ) ;
if ( ! V_2 -> V_18 ) {
F_39 ( V_30 -> V_9 , L_36 ) ;
return - V_194 ;
}
V_140 = F_143 ( V_2 ) ;
if ( V_140 < 0 )
return V_140 ;
F_144 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_28 & V_117 )
F_71 ( V_2 ) ;
F_76 ( V_2 , ( V_230 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_176 ) {
F_39 ( V_30 -> V_9 , L_37 ) ;
return - V_231 ;
}
strcpy ( V_30 -> V_232 , L_38 ) ;
F_145 ( V_30 -> V_233 , V_234 [ V_2 -> V_180 ] ,
sizeof( V_30 -> V_233 ) ) ;
snprintf ( V_30 -> V_235 , sizeof( V_30 -> V_235 ) ,
L_39 ,
V_30 -> V_233 , V_2 -> V_128 , V_2 -> V_80 ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 )
{
#ifdef F_147
struct V_102 * V_125 ;
F_54 (codec, &chip->bus->codec_list, list) {
F_148 ( V_125 ) ;
}
#endif
}
static void F_149 ( const struct V_236 * V_146 , void * V_237 )
{
struct V_109 * V_30 = V_237 ;
struct V_1 * V_2 = V_30 -> V_13 ;
struct V_22 * V_23 = V_2 -> V_23 ;
if ( ! V_146 ) {
F_39 ( V_30 -> V_9 , L_40 ) ;
goto error;
}
V_2 -> V_146 = V_146 ;
if ( ! V_2 -> V_107 ) {
if ( F_87 ( V_2 ) )
goto error;
}
return;
error:
F_150 ( V_30 ) ;
F_151 ( V_23 , NULL ) ;
}
static void F_152 ( T_1 V_166 , T_1 T_5 * V_128 )
{
F_153 ( V_166 , V_128 ) ;
}
static T_1 F_154 ( T_1 T_5 * V_128 )
{
return F_155 ( V_128 ) ;
}
static void F_156 ( T_4 V_166 , T_4 T_5 * V_128 )
{
F_157 ( V_166 , V_128 ) ;
}
static T_4 F_158 ( T_4 T_5 * V_128 )
{
return F_45 ( V_128 ) ;
}
static void F_159 ( T_3 V_166 , T_3 T_5 * V_128 )
{
F_160 ( V_166 , V_128 ) ;
}
static T_3 F_161 ( T_3 T_5 * V_128 )
{
return F_162 ( V_128 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_140 ;
F_64 ( V_2 -> V_80 , V_2 ) ;
V_2 -> V_80 = - 1 ;
F_65 ( V_2 -> V_23 ) ;
V_2 -> V_82 = 0 ;
V_140 = F_37 ( V_2 , 1 ) ;
if ( V_140 < 0 )
return V_140 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 ,
int type ,
T_6 V_238 ,
struct V_3 * V_17 )
{
int V_140 ;
V_140 = F_165 ( type ,
V_2 -> V_30 -> V_9 ,
V_238 , V_17 ) ;
if ( V_140 < 0 )
return V_140 ;
F_8 ( V_2 , V_17 , true ) ;
return 0 ;
}
static void F_166 ( struct V_1 * V_2 , struct V_3 * V_17 )
{
F_8 ( V_2 , V_17 , false ) ;
F_167 ( V_17 ) ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_6 V_238 )
{
struct V_18 * V_18 = F_169 ( V_20 ) ;
int V_106 ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_51 = 0 ;
V_18 -> V_52 = 0 ;
V_18 -> V_239 = 0 ;
V_106 = F_170 ( V_20 , V_238 ) ;
if ( V_106 < 0 )
return V_106 ;
F_9 ( V_2 , V_18 , V_20 , true ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_18 * V_18 = F_169 ( V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
return F_172 ( V_20 ) ;
}
static void F_173 ( struct V_19 * V_20 ,
struct V_240 * V_7 )
{
#ifdef F_174
struct V_110 * V_241 = F_175 ( V_20 ) ;
struct V_1 * V_2 = V_241 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_242 = F_176 ( V_7 -> V_242 ) ;
#endif
}
static int F_177 ( struct V_22 * V_23 ,
const struct V_243 * V_244 )
{
static int V_9 ;
struct V_109 * V_30 ;
struct V_56 * V_57 ;
struct V_1 * V_2 ;
bool V_245 ;
int V_140 ;
if ( V_9 >= V_246 )
return - V_231 ;
if ( ! V_247 [ V_9 ] ) {
V_9 ++ ;
return - V_248 ;
}
V_140 = F_178 ( & V_23 -> V_9 , V_249 [ V_9 ] , V_250 [ V_9 ] , V_251 ,
0 , & V_30 ) ;
if ( V_140 < 0 ) {
F_39 ( & V_23 -> V_9 , L_41 ) ;
return V_140 ;
}
V_140 = F_124 ( V_30 , V_23 , V_9 , V_244 -> V_252 ,
& V_253 , & V_2 ) ;
if ( V_140 < 0 )
goto V_254;
V_30 -> V_13 = V_2 ;
V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
F_151 ( V_23 , V_30 ) ;
V_140 = F_97 ( V_2 ) ;
if ( V_140 < 0 ) {
F_39 ( V_30 -> V_9 , L_42 ) ;
goto V_254;
}
if ( F_115 ( V_23 ) ) {
F_20 ( V_30 -> V_9 , L_43 ) ;
F_20 ( V_30 -> V_9 , L_44 ) ;
V_2 -> V_107 = true ;
}
V_245 = ! V_2 -> V_107 ;
#ifdef F_109
if ( V_255 [ V_9 ] && * V_255 [ V_9 ] ) {
F_20 ( V_30 -> V_9 , L_45 ,
V_255 [ V_9 ] ) ;
V_140 = F_179 ( V_251 , true , V_255 [ V_9 ] ,
& V_23 -> V_9 , V_193 , V_30 ,
F_149 ) ;
if ( V_140 < 0 )
goto V_254;
V_245 = false ;
}
#endif
#ifndef F_180
if ( V_2 -> V_28 & V_117 )
F_39 ( V_30 -> V_9 , L_46 ) ;
#endif
if ( V_245 )
F_181 ( & V_57 -> V_186 ) ;
V_9 ++ ;
if ( V_2 -> V_107 )
F_102 ( & V_57 -> V_135 ) ;
return 0 ;
V_254:
F_150 ( V_30 ) ;
return V_140 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_23 ( V_2 , struct V_56 , V_2 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_9 = V_2 -> V_69 ;
int V_140 ;
if ( V_2 -> V_28 & V_117 ) {
#ifdef F_180
V_140 = F_182 () ;
if ( V_140 < 0 ) {
F_39 ( V_2 -> V_30 -> V_9 ,
L_47 ) ;
goto V_254;
}
V_140 = F_69 ( true ) ;
if ( V_140 < 0 ) {
F_39 ( V_2 -> V_30 -> V_9 ,
L_48 ) ;
goto V_254;
}
#endif
}
V_140 = F_132 ( V_2 ) ;
if ( V_140 < 0 )
goto V_254;
#ifdef F_183
V_2 -> V_256 = V_256 [ V_9 ] ;
#endif
V_140 = F_184 ( V_2 , V_257 [ V_9 ] ,
V_258 [ V_2 -> V_180 ] ,
V_259 ) ;
if ( V_140 < 0 )
goto V_254;
#ifdef F_109
if ( V_2 -> V_146 ) {
V_140 = F_185 ( V_2 -> V_60 , V_2 -> V_146 -> V_238 ,
V_2 -> V_146 -> V_27 ) ;
if ( V_140 < 0 )
goto V_254;
#ifndef F_147
F_110 ( V_2 -> V_146 ) ;
V_2 -> V_146 = NULL ;
#endif
}
#endif
if ( ( V_230 [ V_9 ] & 1 ) == 0 ) {
V_140 = F_186 ( V_2 ) ;
if ( V_140 < 0 )
goto V_254;
}
V_140 = F_187 ( V_2 -> V_60 ) ;
if ( V_140 < 0 )
goto V_254;
V_140 = F_188 ( V_2 ) ;
if ( V_140 < 0 )
goto V_254;
V_140 = F_189 ( V_2 -> V_30 ) ;
if ( V_140 < 0 )
goto V_254;
V_2 -> V_78 = 1 ;
F_146 ( V_2 ) ;
F_190 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( ( V_2 -> V_28 & V_121 ) || V_57 -> V_139 )
F_191 ( & V_23 -> V_9 ) ;
V_254:
if ( V_140 < 0 )
V_57 -> V_112 = 1 ;
F_102 ( & V_57 -> V_135 ) ;
return V_140 ;
}
static void F_192 ( struct V_22 * V_23 )
{
struct V_109 * V_30 = F_85 ( V_23 ) ;
if ( V_30 )
F_150 ( V_30 ) ;
}
