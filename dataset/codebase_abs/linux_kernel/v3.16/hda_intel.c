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
static int F_18 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
int V_45 ;
V_45 = F_19 ( V_2 , V_18 ) ;
if ( V_45 == 1 ) {
V_18 -> V_46 = 0 ;
return V_45 ;
} else if ( V_45 == 0 && V_2 -> V_47 && V_2 -> V_47 -> V_48 ) {
V_18 -> V_46 = 1 ;
F_20 ( V_2 -> V_47 -> V_48 , & V_2 -> V_49 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
T_1 V_50 ;
unsigned int V_51 ;
V_50 = F_21 ( V_2 , V_52 ) - V_18 -> V_53 ;
if ( V_50 < ( V_18 -> V_54 * 2 ) / 3 )
return - 1 ;
V_51 = F_22 ( V_2 , V_18 , true ) ;
if ( F_23 ( ! V_18 -> V_55 ,
L_7 ) )
return - 1 ;
if ( V_50 < ( V_18 -> V_54 * 5 ) / 4 &&
V_51 % V_18 -> V_55 > V_18 -> V_55 / 2 )
return V_2 -> V_56 [ V_2 -> V_57 ] ? 0 : - 1 ;
V_18 -> V_53 += V_50 ;
return 1 ;
}
static void F_24 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_25 ( V_59 , struct V_1 , V_49 ) ;
int V_60 , V_61 , V_45 ;
if ( ! V_2 -> V_62 ) {
F_26 ( V_2 -> V_30 -> V_9 ,
L_8 ,
V_2 -> V_30 -> V_63 ) ;
V_2 -> V_62 = 1 ;
}
for (; ; ) {
V_61 = 0 ;
F_27 ( & V_2 -> V_64 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_65 ; V_60 ++ ) {
struct V_18 * V_18 = & V_2 -> V_18 [ V_60 ] ;
if ( ! V_18 -> V_46 ||
! V_18 -> V_20 ||
! V_18 -> V_66 )
continue;
V_45 = F_19 ( V_2 , V_18 ) ;
if ( V_45 > 0 ) {
V_18 -> V_46 = 0 ;
F_28 ( & V_2 -> V_64 ) ;
F_29 ( V_18 -> V_20 ) ;
F_30 ( & V_2 -> V_64 ) ;
} else if ( V_45 < 0 ) {
V_61 = 0 ;
} else
V_61 ++ ;
}
F_31 ( & V_2 -> V_64 ) ;
if ( ! V_61 )
return;
F_32 ( 1 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
int V_60 ;
F_27 ( & V_2 -> V_64 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_65 ; V_60 ++ )
V_2 -> V_18 [ V_60 ] . V_46 = 0 ;
F_31 ( & V_2 -> V_64 ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_67 )
{
if ( F_35 ( V_2 -> V_23 -> V_68 , V_69 ,
V_2 -> V_70 ? 0 : V_71 ,
V_72 , V_2 ) ) {
F_36 ( V_2 -> V_30 -> V_9 ,
L_9 ,
V_2 -> V_23 -> V_68 ) ;
if ( V_67 )
F_37 ( V_2 -> V_30 ) ;
return - 1 ;
}
V_2 -> V_68 = V_2 -> V_23 -> V_68 ;
F_38 ( V_2 -> V_23 , ! V_2 -> V_70 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_73 ) ;
F_41 ( & V_2 -> V_74 , & V_75 ) ;
F_42 ( & V_73 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_40 ( & V_73 ) ;
F_44 ( & V_2 -> V_74 ) ;
F_42 ( & V_73 ) ;
}
static int F_45 ( const char * V_26 , const struct V_76 * V_77 )
{
struct V_1 * V_2 ;
struct V_78 * V_79 ;
int V_80 = V_81 ;
int V_82 = F_46 ( V_26 , V_77 ) ;
if ( V_82 || V_80 == V_81 )
return V_82 ;
F_40 ( & V_73 ) ;
F_47 (chip, &card_list, list) {
if ( ! V_2 -> V_47 || V_2 -> V_83 )
continue;
F_47 (c, &chip->bus->codec_list, list)
F_48 ( V_79 ) ;
}
F_42 ( & V_73 ) ;
return 0 ;
}
static int F_49 ( struct V_84 * V_9 )
{
struct V_22 * V_23 = F_50 ( V_9 ) ;
struct V_85 * V_30 = F_51 ( V_9 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
struct V_86 * V_87 ;
if ( V_2 -> V_83 || V_2 -> V_88 )
return 0 ;
F_52 ( V_30 , V_89 ) ;
F_33 ( V_2 ) ;
F_47 (p, &chip->pcm_list, list)
F_53 ( V_87 -> V_90 ) ;
if ( V_2 -> V_91 )
F_54 ( V_2 -> V_47 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_68 >= 0 ) {
F_57 ( V_2 -> V_68 , V_2 ) ;
V_2 -> V_68 = - 1 ;
}
if ( V_2 -> V_70 )
F_58 ( V_2 -> V_23 ) ;
F_59 ( V_23 ) ;
F_60 ( V_23 ) ;
F_61 ( V_23 , V_92 ) ;
if ( V_2 -> V_28 & V_93 )
F_62 ( false ) ;
return 0 ;
}
static int F_63 ( struct V_84 * V_9 )
{
struct V_22 * V_23 = F_50 ( V_9 ) ;
struct V_85 * V_30 = F_51 ( V_9 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
if ( V_2 -> V_83 || V_2 -> V_88 )
return 0 ;
if ( V_2 -> V_28 & V_93 ) {
F_62 ( true ) ;
F_64 ( V_2 ) ;
}
F_61 ( V_23 , V_94 ) ;
F_65 ( V_23 ) ;
if ( F_66 ( V_23 ) < 0 ) {
F_36 ( V_2 -> V_30 -> V_9 ,
L_10 ) ;
F_37 ( V_30 ) ;
return - V_95 ;
}
F_67 ( V_23 ) ;
if ( V_2 -> V_70 )
if ( F_68 ( V_23 ) < 0 )
V_2 -> V_70 = 0 ;
if ( F_34 ( V_2 , 1 ) < 0 )
return - V_95 ;
F_14 ( V_2 ) ;
F_69 ( V_2 , true ) ;
F_70 ( V_2 -> V_47 ) ;
F_52 ( V_30 , V_96 ) ;
return 0 ;
}
static int F_71 ( struct V_84 * V_9 )
{
struct V_85 * V_30 = F_51 ( V_9 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
if ( V_2 -> V_83 || V_2 -> V_88 )
return 0 ;
if ( ! ( V_2 -> V_28 & V_97 ) )
return 0 ;
F_72 ( V_2 , V_98 , F_73 ( V_2 , V_98 ) |
V_99 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_28 & V_93 )
F_62 ( false ) ;
return 0 ;
}
static int F_74 ( struct V_84 * V_9 )
{
struct V_85 * V_30 = F_51 ( V_9 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
struct V_100 * V_47 ;
struct V_78 * V_101 ;
int V_102 ;
if ( V_2 -> V_83 || V_2 -> V_88 )
return 0 ;
if ( ! ( V_2 -> V_28 & V_97 ) )
return 0 ;
if ( V_2 -> V_28 & V_93 ) {
F_62 ( true ) ;
F_64 ( V_2 ) ;
}
V_102 = F_73 ( V_2 , V_103 ) ;
F_14 ( V_2 ) ;
F_69 ( V_2 , true ) ;
V_47 = V_2 -> V_47 ;
if ( V_102 && V_47 ) {
F_47 (codec, &bus->codec_list, list)
if ( V_102 & ( 1 << V_101 -> V_104 ) )
F_75 ( V_101 -> V_47 -> V_48 ,
& V_101 -> V_105 , V_101 -> V_106 ) ;
}
F_72 ( V_2 , V_98 , F_73 ( V_2 , V_98 ) &
~ V_99 ) ;
return 0 ;
}
static int F_76 ( struct V_84 * V_9 )
{
struct V_85 * V_30 = F_51 ( V_9 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
if ( V_2 -> V_83 || V_2 -> V_88 )
return 0 ;
if ( ! V_107 ||
! ( V_2 -> V_28 & V_97 ) )
return - V_108 ;
return 0 ;
}
static int F_77 ( struct V_109 * V_110 , unsigned long V_111 , void * V_17 )
{
struct V_1 * V_2 = F_25 ( V_110 , struct V_1 , V_112 ) ;
F_78 ( V_2 -> V_47 ) ;
F_55 ( V_2 ) ;
return V_113 ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_112 . V_114 = F_77 ;
F_80 ( & V_2 -> V_112 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 . V_114 )
F_82 ( & V_2 -> V_112 ) ;
}
static void F_83 ( struct V_22 * V_23 ,
enum V_115 V_116 )
{
struct V_85 * V_30 = F_84 ( V_23 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
bool V_83 ;
F_85 ( & V_2 -> V_117 ) ;
if ( V_2 -> V_88 )
return;
V_83 = ( V_116 == V_118 ) ;
if ( V_2 -> V_83 == V_83 )
return;
if ( ! V_2 -> V_47 ) {
V_2 -> V_83 = V_83 ;
if ( ! V_83 ) {
F_26 ( V_2 -> V_30 -> V_9 ,
L_11 ) ;
if ( F_86 ( V_2 ) < 0 ) {
F_36 ( V_2 -> V_30 -> V_9 , L_12 ) ;
V_2 -> V_88 = true ;
}
}
} else {
F_26 ( V_2 -> V_30 -> V_9 , L_13 ,
V_83 ? L_14 : L_15 ) ;
if ( V_83 ) {
F_87 ( V_30 -> V_9 ) ;
F_49 ( V_30 -> V_9 ) ;
V_23 -> V_119 = V_120 ;
V_2 -> V_83 = true ;
if ( F_88 ( V_2 -> V_47 ) )
F_89 ( V_2 -> V_30 -> V_9 ,
L_16 ) ;
} else {
F_90 ( V_2 -> V_47 ) ;
F_91 ( V_30 -> V_9 ) ;
V_2 -> V_83 = false ;
F_63 ( V_30 -> V_9 ) ;
}
}
}
static bool F_92 ( struct V_22 * V_23 )
{
struct V_85 * V_30 = F_84 ( V_23 ) ;
struct V_1 * V_2 = V_30 -> V_13 ;
F_85 ( & V_2 -> V_117 ) ;
if ( V_2 -> V_88 )
return false ;
if ( V_2 -> V_83 || ! V_2 -> V_47 )
return true ;
if ( F_88 ( V_2 -> V_47 ) )
return false ;
F_90 ( V_2 -> V_47 ) ;
return true ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_22 * V_87 = F_94 ( V_2 -> V_23 ) ;
if ( V_87 ) {
F_26 ( V_2 -> V_30 -> V_9 ,
L_17 ) ;
V_2 -> V_121 = 1 ;
F_95 ( V_87 ) ;
}
}
static int F_96 ( struct V_1 * V_2 )
{
int V_122 ;
if ( ! V_2 -> V_121 )
return 0 ;
V_122 = F_97 ( V_2 -> V_23 , & V_123 ,
V_124 ,
V_2 -> V_47 != NULL ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 -> V_125 = 1 ;
F_98 ( V_2 -> V_30 -> V_9 ,
& V_2 -> V_126 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_127 * V_128 = F_25 ( V_2 , struct V_127 , V_2 ) ;
int V_60 ;
if ( ( V_2 -> V_28 & V_97 )
&& V_2 -> V_66 )
F_91 ( & V_23 -> V_9 ) ;
F_43 ( V_2 ) ;
F_81 ( V_2 ) ;
V_2 -> V_88 = 1 ;
F_100 ( & V_2 -> V_117 ) ;
if ( V_121 ( V_2 ) ) {
if ( V_2 -> V_83 && V_2 -> V_47 )
F_90 ( V_2 -> V_47 ) ;
if ( V_2 -> V_125 )
F_101 ( V_2 -> V_23 ) ;
}
if ( V_2 -> V_91 ) {
F_33 ( V_2 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_65 ; V_60 ++ )
F_102 ( V_2 , & V_2 -> V_18 [ V_60 ] ) ;
F_55 ( V_2 ) ;
}
if ( V_2 -> V_68 >= 0 )
F_57 ( V_2 -> V_68 , ( void * ) V_2 ) ;
if ( V_2 -> V_70 )
F_58 ( V_2 -> V_23 ) ;
if ( V_2 -> V_129 )
F_103 ( V_2 -> V_129 ) ;
F_104 ( V_2 ) ;
if ( V_2 -> V_130 )
F_105 ( V_2 -> V_23 ) ;
F_59 ( V_2 -> V_23 ) ;
F_106 ( V_2 -> V_18 ) ;
#ifdef F_107
if ( V_2 -> V_131 )
F_108 ( V_2 -> V_131 ) ;
#endif
if ( V_2 -> V_28 & V_93 ) {
F_62 ( false ) ;
F_109 () ;
}
F_106 ( V_128 ) ;
return 0 ;
}
static int F_110 ( struct V_132 * V_84 )
{
return F_99 ( V_84 -> V_133 ) ;
}
static struct V_22 * F_94 ( struct V_22 * V_23 )
{
struct V_22 * V_87 ;
switch ( V_23 -> V_134 ) {
case V_135 :
case V_136 :
case V_137 :
if ( V_23 -> V_138 == 1 ) {
V_87 = F_111 ( F_112 ( V_23 -> V_47 ) ,
V_23 -> V_47 -> V_63 , 0 ) ;
if ( V_87 ) {
if ( ( V_87 -> V_139 >> 8 ) == V_140 )
return V_87 ;
F_95 ( V_87 ) ;
}
}
break;
}
return NULL ;
}
static bool F_113 ( struct V_22 * V_23 )
{
bool V_141 = false ;
struct V_22 * V_87 = F_94 ( V_23 ) ;
if ( V_87 ) {
if ( F_114 ( V_87 ) == V_118 )
V_141 = true ;
F_95 ( V_87 ) ;
}
return V_141 ;
}
static int F_115 ( struct V_1 * V_2 , int V_142 )
{
const struct V_143 * V_144 ;
switch ( V_142 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
return V_142 ;
}
V_144 = F_116 ( V_2 -> V_23 , V_150 ) ;
if ( V_144 ) {
F_26 ( V_2 -> V_30 -> V_9 ,
L_18 ,
V_144 -> V_151 , V_144 -> V_152 , V_144 -> V_153 ) ;
return V_144 -> V_151 ;
}
if ( V_2 -> V_28 & V_154 ) {
F_15 ( V_2 -> V_30 -> V_9 , L_19 ) ;
return V_148 ;
}
if ( V_2 -> V_28 & V_155 ) {
F_15 ( V_2 -> V_30 -> V_9 , L_20 ) ;
return V_146 ;
}
return V_145 ;
}
static void F_117 ( struct V_1 * V_2 , int V_9 )
{
const struct V_143 * V_144 ;
V_2 -> V_156 = V_157 [ V_9 ] ;
if ( V_2 -> V_156 == - 1 ) {
V_144 = F_116 ( V_2 -> V_23 , V_158 ) ;
if ( V_144 ) {
F_26 ( V_2 -> V_30 -> V_9 ,
L_21 ,
V_144 -> V_151 , V_144 -> V_152 , V_144 -> V_153 ) ;
V_2 -> V_156 = V_144 -> V_151 ;
}
}
if ( V_2 -> V_156 != - 1 &&
( V_2 -> V_156 & V_159 ) ) {
V_2 -> V_160 = V_2 -> V_156 & 0xff ;
F_26 ( V_2 -> V_30 -> V_9 , L_22 ,
V_2 -> V_160 ) ;
}
}
static void F_118 ( struct V_1 * V_2 )
{
const struct V_143 * V_144 ;
if ( V_161 >= 0 ) {
V_2 -> V_70 = ! ! V_161 ;
return;
}
V_2 -> V_70 = 1 ;
V_144 = F_116 ( V_2 -> V_23 , V_162 ) ;
if ( V_144 ) {
F_26 ( V_2 -> V_30 -> V_9 ,
L_23 ,
V_144 -> V_152 , V_144 -> V_153 , V_144 -> V_151 ) ;
V_2 -> V_70 = V_144 -> V_151 ;
return;
}
if ( V_2 -> V_28 & V_163 ) {
F_26 ( V_2 -> V_30 -> V_9 , L_24 ) ;
V_2 -> V_70 = 0 ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
bool V_42 = V_2 -> V_42 ;
switch ( V_2 -> V_164 ) {
case V_165 :
if ( V_42 ) {
T_2 V_26 ;
F_12 ( V_2 -> V_23 , 0x42 , & V_26 ) ;
if ( ! ( V_26 & 0x80 ) && V_2 -> V_23 -> V_166 == 0x30 )
V_42 = false ;
}
break;
case V_167 :
V_42 = false ;
break;
case V_168 :
V_42 = false ;
break;
}
if ( V_42 != V_2 -> V_42 ) {
F_26 ( V_2 -> V_30 -> V_9 , L_25 ,
V_42 ? L_26 : L_27 ) ;
V_2 -> V_42 = V_42 ;
}
}
static void F_120 ( struct V_58 * V_59 )
{
F_86 ( F_25 ( V_59 , struct V_1 , V_169 ) ) ;
}
static int F_121 ( struct V_85 * V_30 , struct V_22 * V_23 ,
int V_9 , unsigned int V_28 ,
const struct V_170 * V_171 ,
struct V_1 * * V_172 )
{
static struct V_173 V_174 = {
. V_175 = F_110 ,
} ;
struct V_127 * V_128 ;
struct V_1 * V_2 ;
int V_122 ;
* V_172 = NULL ;
V_122 = F_66 ( V_23 ) ;
if ( V_122 < 0 )
return V_122 ;
V_128 = F_122 ( sizeof( * V_128 ) , V_176 ) ;
if ( ! V_128 ) {
F_36 ( V_30 -> V_9 , L_28 ) ;
F_59 ( V_23 ) ;
return - V_177 ;
}
V_2 = & V_128 -> V_2 ;
F_123 ( & V_2 -> V_64 ) ;
F_124 ( & V_2 -> V_178 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_174 = V_171 ;
V_2 -> V_68 = - 1 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_164 = V_28 & 0xff ;
F_118 ( V_2 ) ;
V_2 -> V_57 = V_9 ;
V_2 -> V_179 = V_179 ;
F_125 ( & V_2 -> V_49 , F_24 ) ;
F_126 ( & V_2 -> V_180 ) ;
F_126 ( & V_2 -> V_74 ) ;
F_93 ( V_2 ) ;
F_127 ( & V_2 -> V_117 ) ;
V_2 -> V_181 [ 0 ] = V_2 -> V_181 [ 1 ] =
F_115 ( V_2 , V_181 [ V_9 ] ) ;
if ( V_2 -> V_181 [ 0 ] == V_149 ) {
V_2 -> V_181 [ 0 ] = V_146 ;
V_2 -> V_181 [ 1 ] = V_145 ;
}
F_117 ( V_2 , V_9 ) ;
V_2 -> V_182 = V_182 ;
V_2 -> V_42 = V_183 ;
F_119 ( V_2 ) ;
if ( V_56 [ V_9 ] < 0 ) {
switch ( V_2 -> V_164 ) {
case V_184 :
case V_185 :
V_56 [ V_9 ] = 1 ;
break;
default:
V_56 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_56 = V_56 ;
V_122 = F_128 ( V_30 , V_186 , V_2 , & V_174 ) ;
if ( V_122 < 0 ) {
F_36 ( V_30 -> V_9 , L_29 ) ;
F_99 ( V_2 ) ;
return V_122 ;
}
F_125 ( & V_2 -> V_169 , F_120 ) ;
* V_172 = V_2 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_57 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_85 * V_30 = V_2 -> V_30 ;
int V_122 ;
unsigned short V_187 ;
#if V_188 != 64
if ( V_2 -> V_164 == V_189 ) {
T_3 V_190 ;
F_16 ( V_23 , 0x40 , & V_190 ) ;
F_17 ( V_23 , 0x40 , V_190 | 0x10 ) ;
F_130 ( V_23 , V_191 , 0 ) ;
}
#endif
V_122 = F_131 ( V_23 , L_30 ) ;
if ( V_122 < 0 )
return V_122 ;
V_2 -> V_130 = 1 ;
V_2 -> V_104 = F_132 ( V_23 , 0 ) ;
V_2 -> V_129 = F_133 ( V_23 , 0 ) ;
if ( V_2 -> V_129 == NULL ) {
F_36 ( V_30 -> V_9 , L_31 ) ;
return - V_192 ;
}
if ( V_2 -> V_70 )
if ( F_68 ( V_23 ) < 0 )
V_2 -> V_70 = 0 ;
if ( F_34 ( V_2 , 0 ) < 0 )
return - V_108 ;
F_67 ( V_23 ) ;
F_134 ( V_2 -> V_68 ) ;
V_187 = F_73 ( V_2 , V_193 ) ;
F_15 ( V_30 -> V_9 , L_32 , V_187 ) ;
if ( V_2 -> V_23 -> V_134 == V_135 ) {
struct V_22 * V_194 ;
V_194 = F_135 ( V_135 ,
V_195 ,
NULL ) ;
if ( V_194 ) {
if ( V_194 -> V_166 < 0x30 )
V_187 &= ~ V_196 ;
F_95 ( V_194 ) ;
}
}
if ( V_2 -> V_28 & V_197 ) {
F_15 ( V_30 -> V_9 , L_33 ) ;
V_187 &= ~ V_196 ;
}
if ( V_198 >= 0 )
V_2 -> V_198 = ! ! V_198 ;
else {
if ( V_2 -> V_28 & V_199 )
V_2 -> V_198 = 0 ;
else if ( V_2 -> V_28 & V_200 )
V_2 -> V_198 = 1 ;
else
V_2 -> V_198 = 1 ;
}
if ( ( V_187 & V_196 ) && ! F_136 ( V_23 , F_137 ( 64 ) ) )
F_138 ( V_23 , F_137 ( 64 ) ) ;
else {
F_136 ( V_23 , F_137 ( 32 ) ) ;
F_138 ( V_23 , F_137 ( 32 ) ) ;
}
V_2 -> V_201 = ( V_187 >> 8 ) & 0x0f ;
V_2 -> V_202 = ( V_187 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_202 && ! V_2 -> V_201 ) {
switch ( V_2 -> V_164 ) {
case V_189 :
V_2 -> V_202 = V_203 ;
V_2 -> V_201 = V_204 ;
break;
case V_205 :
case V_167 :
V_2 -> V_202 = V_206 ;
V_2 -> V_201 = V_207 ;
break;
case V_208 :
default:
V_2 -> V_202 = V_209 ;
V_2 -> V_201 = V_210 ;
break;
}
}
V_2 -> V_211 = 0 ;
V_2 -> V_212 = V_2 -> V_201 ;
V_2 -> V_65 = V_2 -> V_202 + V_2 -> V_201 ;
V_2 -> V_18 = F_139 ( V_2 -> V_65 , sizeof( * V_2 -> V_18 ) ,
V_176 ) ;
if ( ! V_2 -> V_18 ) {
F_36 ( V_30 -> V_9 , L_34 ) ;
return - V_177 ;
}
V_122 = F_140 ( V_2 ) ;
if ( V_122 < 0 )
return V_122 ;
F_141 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_28 & V_93 )
F_64 ( V_2 ) ;
F_69 ( V_2 , ( V_213 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_160 ) {
F_36 ( V_30 -> V_9 , L_35 ) ;
return - V_214 ;
}
strcpy ( V_30 -> V_215 , L_36 ) ;
F_142 ( V_30 -> V_216 , V_217 [ V_2 -> V_164 ] ,
sizeof( V_30 -> V_216 ) ) ;
snprintf ( V_30 -> V_218 , sizeof( V_30 -> V_218 ) ,
L_37 ,
V_30 -> V_216 , V_2 -> V_104 , V_2 -> V_68 ) ;
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
#ifdef F_144
struct V_78 * V_101 ;
F_47 (codec, &chip->bus->codec_list, list) {
F_145 ( V_101 ) ;
}
#endif
}
static void F_146 ( const struct V_219 * V_131 , void * V_220 )
{
struct V_85 * V_30 = V_220 ;
struct V_1 * V_2 = V_30 -> V_13 ;
struct V_22 * V_23 = V_2 -> V_23 ;
if ( ! V_131 ) {
F_36 ( V_30 -> V_9 , L_38 ) ;
goto error;
}
V_2 -> V_131 = V_131 ;
if ( ! V_2 -> V_83 ) {
if ( F_86 ( V_2 ) )
goto error;
}
return;
error:
F_147 ( V_30 ) ;
F_148 ( V_23 , NULL ) ;
}
static void F_149 ( T_1 V_151 , T_1 T_4 * V_104 )
{
F_150 ( V_151 , V_104 ) ;
}
static T_1 F_151 ( T_1 T_4 * V_104 )
{
return F_152 ( V_104 ) ;
}
static void F_153 ( T_3 V_151 , T_3 T_4 * V_104 )
{
F_154 ( V_151 , V_104 ) ;
}
static T_3 F_155 ( T_3 T_4 * V_104 )
{
return F_156 ( V_104 ) ;
}
static void F_157 ( T_2 V_151 , T_2 T_4 * V_104 )
{
F_158 ( V_151 , V_104 ) ;
}
static T_2 F_159 ( T_2 T_4 * V_104 )
{
return F_160 ( V_104 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_122 ;
F_57 ( V_2 -> V_68 , V_2 ) ;
V_2 -> V_68 = - 1 ;
F_58 ( V_2 -> V_23 ) ;
V_2 -> V_70 = 0 ;
V_122 = F_34 ( V_2 , 1 ) ;
if ( V_122 < 0 )
return V_122 ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 ,
int type ,
T_5 V_221 ,
struct V_3 * V_17 )
{
int V_122 ;
V_122 = F_163 ( type ,
V_2 -> V_30 -> V_9 ,
V_221 , V_17 ) ;
if ( V_122 < 0 )
return V_122 ;
F_8 ( V_2 , V_17 , true ) ;
return 0 ;
}
static void F_164 ( struct V_1 * V_2 , struct V_3 * V_17 )
{
F_8 ( V_2 , V_17 , false ) ;
F_165 ( V_17 ) ;
}
static int F_166 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_5 V_221 )
{
struct V_18 * V_18 = F_167 ( V_20 ) ;
int V_82 ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
V_18 -> V_222 = 0 ;
V_18 -> V_55 = 0 ;
V_18 -> V_223 = 0 ;
V_82 = F_168 ( V_20 , V_221 ) ;
if ( V_82 < 0 )
return V_82 ;
F_9 ( V_2 , V_18 , V_20 , true ) ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_18 * V_18 = F_167 ( V_20 ) ;
F_9 ( V_2 , V_18 , V_20 , false ) ;
return F_170 ( V_20 ) ;
}
static void F_171 ( struct V_19 * V_20 ,
struct V_224 * V_7 )
{
#ifdef F_172
struct V_86 * V_225 = F_173 ( V_20 ) ;
struct V_1 * V_2 = V_225 -> V_2 ;
if ( ! F_2 ( V_2 ) )
V_7 -> V_226 = F_174 ( V_7 -> V_226 ) ;
#endif
}
static int F_175 ( struct V_22 * V_23 ,
const struct V_227 * V_228 )
{
static int V_9 ;
struct V_85 * V_30 ;
struct V_1 * V_2 ;
bool V_229 ;
int V_122 ;
if ( V_9 >= V_230 )
return - V_214 ;
if ( ! V_231 [ V_9 ] ) {
V_9 ++ ;
return - V_232 ;
}
V_122 = F_176 ( & V_23 -> V_9 , V_233 [ V_9 ] , V_234 [ V_9 ] , V_235 ,
0 , & V_30 ) ;
if ( V_122 < 0 ) {
F_36 ( & V_23 -> V_9 , L_39 ) ;
return V_122 ;
}
V_122 = F_121 ( V_30 , V_23 , V_9 , V_228 -> V_236 ,
& V_237 , & V_2 ) ;
if ( V_122 < 0 )
goto V_238;
V_30 -> V_13 = V_2 ;
F_148 ( V_23 , V_30 ) ;
V_122 = F_96 ( V_2 ) ;
if ( V_122 < 0 ) {
F_36 ( V_30 -> V_9 , L_40 ) ;
goto V_238;
}
if ( F_113 ( V_23 ) ) {
F_26 ( V_30 -> V_9 , L_41 ) ;
F_26 ( V_30 -> V_9 , L_42 ) ;
V_2 -> V_83 = true ;
}
V_229 = ! V_2 -> V_83 ;
#ifdef F_107
if ( V_239 [ V_9 ] && * V_239 [ V_9 ] ) {
F_26 ( V_30 -> V_9 , L_43 ,
V_239 [ V_9 ] ) ;
V_122 = F_177 ( V_235 , true , V_239 [ V_9 ] ,
& V_23 -> V_9 , V_176 , V_30 ,
F_146 ) ;
if ( V_122 < 0 )
goto V_238;
V_229 = false ;
}
#endif
#ifndef F_178
if ( V_2 -> V_28 & V_93 )
F_36 ( V_30 -> V_9 , L_44 ) ;
#endif
if ( V_229 )
F_179 ( & V_2 -> V_169 ) ;
V_9 ++ ;
if ( V_2 -> V_83 )
F_100 ( & V_2 -> V_117 ) ;
return 0 ;
V_238:
F_147 ( V_30 ) ;
return V_122 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
int V_9 = V_2 -> V_57 ;
int V_122 ;
if ( V_2 -> V_28 & V_93 ) {
#ifdef F_178
V_122 = F_180 () ;
if ( V_122 < 0 ) {
F_36 ( V_2 -> V_30 -> V_9 ,
L_45 ) ;
goto V_238;
}
V_122 = F_62 ( true ) ;
if ( V_122 < 0 ) {
F_36 ( V_2 -> V_30 -> V_9 ,
L_46 ) ;
goto V_238;
}
#endif
}
V_122 = F_129 ( V_2 ) ;
if ( V_122 < 0 )
goto V_238;
#ifdef F_181
V_2 -> V_240 = V_240 [ V_9 ] ;
#endif
V_122 = F_182 ( V_2 , V_241 [ V_9 ] ,
V_242 [ V_2 -> V_164 ] ,
V_243 ) ;
if ( V_122 < 0 )
goto V_238;
#ifdef F_107
if ( V_2 -> V_131 ) {
V_122 = F_183 ( V_2 -> V_47 , V_2 -> V_131 -> V_221 ,
V_2 -> V_131 -> V_27 ) ;
if ( V_122 < 0 )
goto V_238;
#ifndef F_144
F_108 ( V_2 -> V_131 ) ;
V_2 -> V_131 = NULL ;
#endif
}
#endif
if ( ( V_213 [ V_9 ] & 1 ) == 0 ) {
V_122 = F_184 ( V_2 ) ;
if ( V_122 < 0 )
goto V_238;
}
V_122 = F_185 ( V_2 -> V_47 ) ;
if ( V_122 < 0 )
goto V_238;
V_122 = F_186 ( V_2 ) ;
if ( V_122 < 0 )
goto V_238;
V_122 = F_187 ( V_2 -> V_30 ) ;
if ( V_122 < 0 )
goto V_238;
V_2 -> V_66 = 1 ;
F_143 ( V_2 ) ;
F_79 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( ( V_2 -> V_28 & V_97 ) || V_2 -> V_121 )
F_188 ( & V_23 -> V_9 ) ;
V_238:
if ( V_122 < 0 )
V_2 -> V_88 = 1 ;
F_100 ( & V_2 -> V_117 ) ;
return V_122 ;
}
static void F_189 ( struct V_22 * V_23 )
{
struct V_85 * V_30 = F_84 ( V_23 ) ;
if ( V_30 )
F_147 ( V_30 ) ;
}
