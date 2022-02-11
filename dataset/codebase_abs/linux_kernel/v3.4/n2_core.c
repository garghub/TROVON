static unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( V_2 -> V_4 == V_5 ) {
V_3 += V_6 ;
if ( V_3 == ( V_6 * V_7 ) )
V_3 = 0 ;
} else {
V_3 += V_8 ;
if ( V_3 == ( V_8 * V_9 ) )
V_3 = 0 ;
}
return V_3 ;
}
static inline bool F_2 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
if ( V_11 <= V_12 ) {
if ( V_10 > V_11 && V_10 <= V_12 )
return true ;
} else {
if ( V_10 > V_11 || V_10 <= V_12 )
return true ;
}
return false ;
}
static T_1 F_3 ( int V_13 , void * V_14 )
{
unsigned long V_3 , V_12 , V_15 ;
struct V_1 * V_2 = V_14 ;
F_4 ( L_1 ,
F_5 () , V_2 -> V_16 ) ;
F_6 ( & V_2 -> V_17 ) ;
V_15 = F_7 ( V_2 -> V_16 , & V_12 ) ;
F_4 ( L_2 ,
F_5 () , V_12 , V_15 ) ;
for ( V_3 = V_2 -> V_18 ; V_3 != V_12 ; V_3 = F_1 ( V_2 , V_3 ) ) {
}
V_15 = F_8 ( V_2 -> V_16 , V_12 ) ;
if ( V_15 == V_19 )
V_2 -> V_18 = V_12 ;
F_9 ( & V_2 -> V_17 ) ;
return V_20 ;
}
static T_1 F_10 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
unsigned long V_18 , V_15 ;
F_6 ( & V_2 -> V_17 ) ;
F_4 ( L_3 ,
F_5 () , V_2 -> V_16 ) ;
V_15 = F_7 ( V_2 -> V_16 , & V_18 ) ;
F_4 ( L_4 ,
F_5 () , V_18 , V_15 ) ;
F_8 ( V_2 -> V_16 , V_18 ) ;
F_9 ( & V_2 -> V_17 ) ;
return V_20 ;
}
static void * F_11 ( struct V_1 * V_2 , void * V_21 )
{
return V_2 -> V_2 + F_1 ( V_2 , V_21 - V_2 -> V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned long V_18 = V_2 -> V_18 ;
unsigned long V_22 = V_2 -> V_22 ;
unsigned long V_23 = ( V_8 * V_9 ) ;
unsigned long V_24 ;
if ( V_18 > V_22 )
V_24 = V_18 - V_22 ;
else
V_24 = ( V_23 - V_22 ) + V_18 ;
return ( V_24 / V_8 ) - 1 ;
}
static void * F_13 ( struct V_1 * V_2 , int V_25 )
{
int V_26 = F_12 ( V_2 ) ;
if ( V_26 >= V_25 )
return V_2 -> V_2 + V_2 -> V_22 ;
return NULL ;
}
static unsigned long F_14 ( struct V_1 * V_2 , void * V_27 )
{
unsigned long V_15 , V_28 ;
V_28 = F_1 ( V_2 , V_27 - V_2 -> V_2 ) ;
V_15 = F_15 ( V_2 -> V_16 , V_28 ) ;
if ( V_15 == V_19 )
V_2 -> V_22 = V_28 ;
return V_15 ;
}
static T_2 F_16 ( unsigned int V_29 , unsigned int V_30 ,
int V_31 , int V_32 ,
unsigned int V_33 ,
bool V_34 , bool V_35 , bool V_36 , bool V_37 ,
int V_38 )
{
T_2 V_39 = ( V_29 - 1 ) & V_40 ;
V_39 |= ( ( T_2 ) V_38 << V_41 ) ;
V_39 |= ( ( T_2 ) V_31 << V_42 ) ;
V_39 |= ( ( T_2 ) V_32 << V_43 ) ;
if ( V_34 )
V_39 |= V_44 ;
if ( V_35 )
V_39 |= V_45 ;
if ( V_36 )
V_39 |= V_46 ;
if ( V_37 )
V_39 |= V_47 ;
if ( V_30 )
V_39 |= ( ( T_2 ) ( V_30 - 1 ) ) << V_48 ;
if ( V_33 )
V_39 |= ( ( T_2 ) ( V_33 - 1 ) ) << V_49 ;
return V_39 ;
}
static inline struct V_50 * V_50 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_56 * V_56 ;
V_56 = F_17 ( V_54 , struct V_56 , V_57 . V_58 ) ;
return F_17 ( V_56 , struct V_50 , V_54 ) ;
}
static inline struct V_59 * V_59 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_56 * V_56 ;
V_56 = F_17 ( V_54 , struct V_56 , V_57 . V_58 ) ;
return F_17 ( V_56 , struct V_59 , V_60 . V_54 ) ;
}
static int F_18 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
return F_23 ( & V_64 -> V_68 ) ;
}
static int F_24 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
return F_25 ( & V_64 -> V_68 ) ;
}
static int F_26 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_27 ( & V_64 -> V_68 ) ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_29 ( & V_64 -> V_68 ) ;
}
static int F_30 ( struct V_51 * V_52 )
{
const char * V_75 = V_52 -> V_55 -> V_76 ;
struct V_65 * V_77 = F_31 ( V_52 ) ;
struct V_66 * V_67 = F_21 ( V_77 ) ;
struct V_65 * V_69 ;
int V_78 ;
V_69 = F_32 ( V_75 , 0 ,
V_79 ) ;
if ( F_33 ( V_69 ) ) {
F_34 ( L_5 ,
V_75 ) ;
V_78 = F_35 ( V_69 ) ;
goto V_80;
}
F_36 ( V_77 , ( sizeof( struct V_63 ) +
F_37 ( V_69 ) ) ) ;
V_67 -> V_69 = V_69 ;
return 0 ;
V_80:
return V_78 ;
}
static void F_38 ( struct V_51 * V_52 )
{
struct V_65 * V_77 = F_31 ( V_52 ) ;
struct V_66 * V_67 = F_21 ( V_77 ) ;
F_39 ( V_67 -> V_69 ) ;
}
static int F_40 ( struct V_51 * V_52 )
{
const char * V_75 = V_52 -> V_55 -> V_76 ;
struct V_65 * V_77 = F_31 ( V_52 ) ;
struct V_81 * V_67 = F_21 ( V_77 ) ;
struct V_59 * V_82 = V_59 ( V_52 ) ;
struct V_65 * V_69 ;
struct V_83 * V_84 ;
int V_78 ;
V_69 = F_32 ( V_75 , 0 ,
V_79 ) ;
if ( F_33 ( V_69 ) ) {
F_34 ( L_5 ,
V_75 ) ;
V_78 = F_35 ( V_69 ) ;
goto V_80;
}
V_84 = F_41 ( V_82 -> V_85 , 0 , 0 ) ;
if ( F_33 ( V_84 ) ) {
F_34 ( L_6 ,
V_82 -> V_85 ) ;
V_78 = F_35 ( V_84 ) ;
goto V_86;
}
F_36 ( V_77 , ( sizeof( struct V_63 ) +
F_37 ( V_69 ) ) ) ;
V_67 -> V_84 = V_84 ;
V_67 -> V_58 . V_69 = V_69 ;
return 0 ;
V_86:
F_39 ( V_69 ) ;
V_80:
return V_78 ;
}
static void F_42 ( struct V_51 * V_52 )
{
struct V_65 * V_77 = F_31 ( V_52 ) ;
struct V_81 * V_67 = F_21 ( V_77 ) ;
F_39 ( V_67 -> V_58 . V_69 ) ;
F_43 ( V_67 -> V_84 ) ;
}
static int F_44 ( struct V_65 * V_52 , const T_3 * V_87 ,
unsigned int V_88 )
{
struct V_81 * V_67 = F_21 ( V_52 ) ;
struct V_83 * V_84 = V_67 -> V_84 ;
struct V_65 * V_69 ;
struct {
struct V_89 V_90 ;
char V_67 [ F_45 ( V_84 ) ] ;
} V_91 ;
int V_78 , V_92 , V_93 ;
V_69 = V_67 -> V_58 . V_69 ;
V_78 = F_46 ( V_69 , V_87 , V_88 ) ;
if ( V_78 )
return V_78 ;
V_91 . V_90 . V_52 = V_84 ;
V_91 . V_90 . V_70 = F_47 ( V_52 ) &
V_71 ;
V_92 = F_48 ( V_84 ) ;
V_93 = F_49 ( V_84 ) ;
F_50 ( V_93 > V_94 ) ;
if ( V_88 > V_92 ) {
V_78 = F_51 ( & V_91 . V_90 , V_87 , V_88 ,
V_67 -> V_95 ) ;
if ( V_78 )
return V_78 ;
V_88 = V_93 ;
} else if ( V_88 <= V_94 )
memcpy ( V_67 -> V_95 , V_87 , V_88 ) ;
V_67 -> V_96 = V_88 ;
return V_78 ;
}
static unsigned long F_52 ( struct V_1 * V_97 )
{
unsigned long V_18 , V_15 ;
do {
V_15 = F_7 ( V_97 -> V_16 , & V_18 ) ;
if ( V_15 != V_19 ) {
F_4 ( L_7 ) ;
break;
}
if ( V_18 == V_97 -> V_22 ) {
V_97 -> V_18 = V_18 ;
break;
}
} while ( 1 );
return V_15 ;
}
static unsigned long F_53 ( struct V_1 * V_97 ,
struct V_98 * V_99 )
{
unsigned long V_15 = F_14 ( V_97 , V_99 ) ;
if ( V_15 == V_19 )
V_15 = F_52 ( V_97 ) ;
return V_15 ;
}
static int F_54 ( struct V_61 * V_62 ,
unsigned int V_32 , unsigned int V_100 ,
unsigned int V_101 , void * V_102 ,
unsigned long V_103 , unsigned int V_104 )
{
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_98 * V_99 ;
struct V_105 V_106 ;
struct V_1 * V_97 ;
unsigned long V_70 ;
int V_78 = - V_107 ;
int V_72 , V_108 ;
if ( F_55 ( V_62 -> V_72 > ( 1 << 16 ) ) ) {
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 =
V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_56 ( & V_64 -> V_68 ) ;
}
V_72 = F_57 ( V_62 , & V_106 ) ;
V_108 = F_58 () ;
V_97 = V_109 [ V_108 ] ;
if ( ! V_97 )
goto V_80;
F_59 ( & V_97 -> V_17 , V_70 ) ;
V_99 = V_97 -> V_2 + V_97 -> V_22 ;
V_99 -> V_110 = F_16 ( V_72 , V_104 , 0 ,
V_32 , V_100 ,
false , true , false , false ,
V_111 |
V_112 ) ;
V_99 -> V_113 = F_60 ( V_106 . V_114 ) ;
V_99 -> V_115 = V_103 ;
V_99 -> V_116 = F_60 ( V_102 ) ;
V_99 -> V_117 = 0UL ;
V_99 -> V_118 = 0UL ;
V_99 -> V_119 = 0UL ;
V_99 -> V_120 = F_60 ( V_102 ) ;
V_72 = F_61 ( & V_106 , 0 ) ;
while ( V_72 > 0 ) {
V_99 = F_11 ( V_97 , V_99 ) ;
V_99 -> V_110 = ( V_72 - 1 ) ;
V_99 -> V_113 = F_60 ( V_106 . V_114 ) ;
V_99 -> V_115 = 0UL ;
V_99 -> V_116 = 0UL ;
V_99 -> V_117 = 0UL ;
V_99 -> V_118 = 0UL ;
V_99 -> V_119 = 0UL ;
V_99 -> V_120 = 0UL ;
V_72 = F_61 ( & V_106 , 0 ) ;
}
V_99 -> V_110 |= V_46 ;
if ( F_53 ( V_97 , V_99 ) != V_19 )
V_78 = - V_121 ;
else
V_78 = 0 ;
F_62 ( & V_97 -> V_17 , V_70 ) ;
if ( ! V_78 )
memcpy ( V_62 -> V_74 , V_102 , V_101 ) ;
V_80:
F_63 () ;
return V_78 ;
}
static int F_64 ( struct V_61 * V_62 )
{
struct V_50 * V_82 = V_50 ( V_62 -> V_58 . V_52 ) ;
struct V_63 * V_64 = F_19 ( V_62 ) ;
int V_93 ;
V_93 = V_82 -> V_100 ;
if ( F_55 ( V_62 -> V_72 == 0 ) ) {
memcpy ( V_62 -> V_74 , V_82 -> V_122 , V_93 ) ;
return 0 ;
}
memcpy ( & V_64 -> V_123 , V_82 -> V_124 , V_82 -> V_125 ) ;
return F_54 ( V_62 , V_82 -> V_32 ,
V_82 -> V_125 , V_93 ,
& V_64 -> V_123 , 0UL , 0 ) ;
}
static int F_65 ( struct V_61 * V_62 )
{
struct V_59 * V_82 = V_59 ( V_62 -> V_58 . V_52 ) ;
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_81 * V_67 = F_21 ( V_52 ) ;
int V_93 ;
V_93 = V_82 -> V_60 . V_100 ;
if ( F_55 ( V_62 -> V_72 == 0 ) ||
F_55 ( V_67 -> V_96 > V_94 ) ) {
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 =
V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_56 ( & V_64 -> V_68 ) ;
}
memcpy ( & V_64 -> V_123 , V_82 -> V_60 . V_124 ,
V_82 -> V_60 . V_125 ) ;
return F_54 ( V_62 , V_82 -> V_60 . V_126 ,
V_82 -> V_60 . V_125 , V_93 ,
& V_64 -> V_123 ,
F_60 ( & V_67 -> V_95 ) ,
V_67 -> V_96 ) ;
}
static inline struct V_127 * V_127 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
return F_17 ( V_54 , struct V_127 , V_54 ) ;
}
static int F_66 ( struct V_128 * V_129 , const T_3 * V_87 ,
unsigned int V_88 )
{
struct V_51 * V_52 = F_67 ( V_129 ) ;
struct V_130 * V_67 = F_68 ( V_52 ) ;
struct V_127 * V_82 = V_127 ( V_52 ) ;
V_67 -> V_31 = ( V_82 -> V_31 & V_131 ) ;
switch ( V_88 ) {
case V_132 :
V_67 -> V_31 |= V_133 ;
break;
case V_134 :
V_67 -> V_31 |= V_135 ;
break;
case V_136 :
V_67 -> V_31 |= V_137 ;
break;
default:
F_69 ( V_129 , V_138 ) ;
return - V_121 ;
}
V_67 -> V_139 = V_88 ;
memcpy ( V_67 -> V_87 . V_140 , V_87 , V_88 ) ;
return 0 ;
}
static int F_70 ( struct V_128 * V_129 , const T_3 * V_87 ,
unsigned int V_88 )
{
struct V_51 * V_52 = F_67 ( V_129 ) ;
struct V_130 * V_67 = F_68 ( V_52 ) ;
struct V_127 * V_82 = V_127 ( V_52 ) ;
T_4 V_141 [ V_142 ] ;
int V_78 ;
V_67 -> V_31 = V_82 -> V_31 ;
if ( V_88 != V_143 ) {
F_69 ( V_129 , V_138 ) ;
return - V_121 ;
}
V_78 = F_71 ( V_141 , V_87 ) ;
if ( V_78 == 0 && ( V_52 -> V_144 & V_145 ) ) {
V_52 -> V_144 |= V_146 ;
return - V_121 ;
}
V_67 -> V_139 = V_88 ;
memcpy ( V_67 -> V_87 . V_147 , V_87 , V_88 ) ;
return 0 ;
}
static int F_72 ( struct V_128 * V_129 , const T_3 * V_87 ,
unsigned int V_88 )
{
struct V_51 * V_52 = F_67 ( V_129 ) ;
struct V_130 * V_67 = F_68 ( V_52 ) ;
struct V_127 * V_82 = V_127 ( V_52 ) ;
V_67 -> V_31 = V_82 -> V_31 ;
if ( V_88 != ( 3 * V_143 ) ) {
F_69 ( V_129 , V_138 ) ;
return - V_121 ;
}
V_67 -> V_139 = V_88 ;
memcpy ( V_67 -> V_87 . V_148 , V_87 , V_88 ) ;
return 0 ;
}
static int F_73 ( struct V_128 * V_129 , const T_3 * V_87 ,
unsigned int V_88 )
{
struct V_51 * V_52 = F_67 ( V_129 ) ;
struct V_130 * V_67 = F_68 ( V_52 ) ;
struct V_127 * V_82 = V_127 ( V_52 ) ;
T_3 * V_149 = V_67 -> V_87 . V_150 ;
T_3 * V_151 = V_149 + 256 ;
T_3 * V_152 = V_151 + 1 ;
int V_153 , V_154 , V_155 ;
V_67 -> V_31 = V_82 -> V_31 ;
V_154 = V_155 = 0 ;
* V_151 = 0 ;
* V_152 = 0 ;
for ( V_153 = 0 ; V_153 < 256 ; V_153 ++ )
V_149 [ V_153 ] = V_153 ;
for ( V_153 = 0 ; V_153 < 256 ; V_153 ++ ) {
T_3 V_156 = V_149 [ V_153 ] ;
V_154 = ( V_154 + V_87 [ V_155 ] + V_156 ) & 0xff ;
V_149 [ V_153 ] = V_149 [ V_154 ] ;
V_149 [ V_154 ] = V_156 ;
if ( ++ V_155 >= V_88 )
V_155 = 0 ;
}
return 0 ;
}
static inline int F_74 ( int V_72 , unsigned int V_157 )
{
int V_158 = V_72 ;
V_158 -= ( V_72 & ( V_157 - 1 ) ) ;
return V_158 > ( 1 << 16 ) ? ( 1 << 16 ) : V_158 ;
}
static int F_75 ( struct V_51 * V_52 , struct V_159 * V_160 ,
struct V_1 * V_97 , bool V_37 )
{
struct V_130 * V_67 = F_68 ( V_52 ) ;
struct V_98 * V_99 ;
bool V_161 ;
int V_153 ;
V_99 = F_13 ( V_97 , V_160 -> V_162 ) ;
if ( ! V_99 ) {
F_76 ( L_8 ,
V_160 -> V_162 ) ;
return - V_163 ;
}
V_161 = ( V_160 -> V_164 == V_160 -> V_165 [ 0 ] . V_166 ) ;
V_99 -> V_110 = F_16 ( V_160 -> V_165 [ 0 ] . V_167 ,
0 , V_67 -> V_31 , 0 , 0 ,
false , true , false , V_37 ,
V_168 |
( V_161 ? V_111 : 0 ) ) ;
V_99 -> V_113 = V_160 -> V_165 [ 0 ] . V_166 ;
V_99 -> V_115 = 0UL ;
V_99 -> V_116 = 0UL ;
V_99 -> V_117 = 0UL ;
V_99 -> V_118 = F_60 ( & V_67 -> V_87 ) ;
V_99 -> V_119 = V_160 -> V_169 ;
V_99 -> V_120 = ( V_161 ? 0UL : V_160 -> V_164 ) ;
for ( V_153 = 1 ; V_153 < V_160 -> V_162 ; V_153 ++ ) {
V_99 = F_11 ( V_97 , V_99 ) ;
V_99 -> V_110 = V_160 -> V_165 [ V_153 ] . V_167 - 1 ;
V_99 -> V_113 = V_160 -> V_165 [ V_153 ] . V_166 ;
V_99 -> V_115 = 0UL ;
V_99 -> V_116 = 0UL ;
V_99 -> V_117 = 0UL ;
V_99 -> V_118 = 0UL ;
V_99 -> V_119 = 0UL ;
V_99 -> V_120 = 0UL ;
}
V_99 -> V_110 |= V_46 ;
return ( F_14 ( V_97 , V_99 ) != V_19 ) ? - V_121 : 0 ;
}
static int F_77 ( struct V_170 * V_62 )
{
struct V_171 * V_64 = F_78 ( V_62 ) ;
struct V_172 * V_106 = & V_64 -> V_106 ;
struct V_159 * V_173 ;
unsigned long V_174 ;
unsigned int V_175 ;
bool V_176 ;
int V_78 , V_72 ;
F_79 ( V_106 , V_62 -> V_177 , V_62 -> V_73 , V_62 -> V_72 ) ;
V_78 = F_80 ( V_62 , V_106 ) ;
if ( V_78 )
return V_78 ;
F_81 ( & V_64 -> V_178 ) ;
V_173 = & V_64 -> V_173 ;
F_81 ( & V_173 -> V_179 ) ;
V_173 -> V_169 = 0UL ;
V_173 -> V_162 = 0 ;
V_173 -> V_164 = 0UL ;
V_176 = false ;
V_174 = ~ 0UL ;
V_175 = 0 ;
while ( ( V_72 = V_106 -> V_72 ) != 0 ) {
unsigned long V_164 , V_166 ;
bool V_161 ;
int V_158 ;
V_166 = ( F_82 ( V_106 -> V_73 . V_180 ) +
V_106 -> V_73 . V_10 ) ;
V_164 = ( F_82 ( V_106 -> V_177 . V_180 ) +
V_106 -> V_177 . V_10 ) ;
V_161 = ( V_166 == V_164 ) ;
V_158 = F_74 ( V_72 , V_106 -> V_181 ) ;
if ( V_173 -> V_162 != 0 ) {
if ( V_161 != V_176 ||
( ! V_176 &&
V_164 != V_174 ) ||
V_173 -> V_162 == V_182 ||
V_175 + V_158 > ( 1 << 16 ) ) {
V_173 -> V_183 = V_174 ;
F_83 ( & V_173 -> V_179 ,
& V_64 -> V_178 ) ;
V_173 = F_84 ( sizeof( * V_173 ) , V_184 ) ;
if ( ! V_173 ) {
V_78 = - V_185 ;
break;
}
F_81 ( & V_173 -> V_179 ) ;
}
}
if ( V_173 -> V_162 == 0 ) {
V_173 -> V_164 = V_164 ;
V_175 = 0 ;
}
V_173 -> V_165 [ V_173 -> V_162 ] . V_166 = V_166 ;
V_173 -> V_165 [ V_173 -> V_162 ] . V_167 = V_158 ;
V_173 -> V_162 ++ ;
V_174 = V_164 + V_158 ;
V_176 = V_161 ;
V_175 += V_158 ;
V_78 = F_85 ( V_62 , V_106 , V_72 - V_158 ) ;
if ( V_78 )
break;
}
if ( ! V_78 && V_173 -> V_162 != 0 ) {
V_173 -> V_183 = V_174 ;
F_83 ( & V_173 -> V_179 , & V_64 -> V_178 ) ;
}
return V_78 ;
}
static void F_86 ( struct V_170 * V_62 , void * V_186 )
{
struct V_171 * V_64 = F_78 ( V_62 ) ;
struct V_159 * V_187 , * V_141 ;
if ( V_186 )
memcpy ( V_64 -> V_106 . V_188 , V_186 , V_64 -> V_106 . V_181 ) ;
F_87 ( & V_64 -> V_106 ) ;
F_88 (c, tmp, &rctx->chunk_list, entry) {
F_89 ( & V_187 -> V_179 ) ;
if ( F_55 ( V_187 != & V_64 -> V_173 ) )
F_90 ( V_187 ) ;
}
}
static int F_91 ( struct V_170 * V_62 , bool V_37 )
{
struct V_171 * V_64 = F_78 ( V_62 ) ;
struct V_51 * V_52 = V_62 -> V_58 . V_52 ;
int V_78 = F_77 ( V_62 ) ;
struct V_159 * V_187 , * V_141 ;
unsigned long V_70 , V_15 ;
struct V_1 * V_97 ;
if ( V_78 )
return V_78 ;
V_97 = V_109 [ F_58 () ] ;
V_78 = - V_107 ;
if ( ! V_97 )
goto V_80;
F_59 ( & V_97 -> V_17 , V_70 ) ;
F_88 (c, tmp, &rctx->chunk_list, entry) {
V_78 = F_75 ( V_52 , V_187 , V_97 , V_37 ) ;
if ( V_78 )
break;
F_89 ( & V_187 -> V_179 ) ;
if ( F_55 ( V_187 != & V_64 -> V_173 ) )
F_90 ( V_187 ) ;
}
if ( ! V_78 ) {
V_15 = F_52 ( V_97 ) ;
if ( V_15 != V_19 )
V_78 = - V_121 ;
}
F_62 ( & V_97 -> V_17 , V_70 ) ;
V_80:
F_63 () ;
F_86 ( V_62 , NULL ) ;
return V_78 ;
}
static int F_92 ( struct V_170 * V_62 )
{
return F_91 ( V_62 , true ) ;
}
static int F_93 ( struct V_170 * V_62 )
{
return F_91 ( V_62 , false ) ;
}
static int F_94 ( struct V_170 * V_62 , bool V_37 )
{
struct V_171 * V_64 = F_78 ( V_62 ) ;
struct V_51 * V_52 = V_62 -> V_58 . V_52 ;
unsigned long V_70 , V_15 , V_169 ;
int V_78 = F_77 ( V_62 ) ;
struct V_159 * V_187 , * V_141 ;
struct V_1 * V_97 ;
void * V_189 ;
V_189 = NULL ;
if ( V_78 )
return V_78 ;
V_97 = V_109 [ F_58 () ] ;
V_78 = - V_107 ;
if ( ! V_97 )
goto V_80;
F_59 ( & V_97 -> V_17 , V_70 ) ;
if ( V_37 ) {
V_169 = F_60 ( V_64 -> V_106 . V_188 ) ;
F_88 (c, tmp, &rctx->chunk_list,
entry) {
V_187 -> V_169 = V_169 ;
V_78 = F_75 ( V_52 , V_187 , V_97 , true ) ;
if ( V_78 )
break;
V_169 = V_187 -> V_183 - V_64 -> V_106 . V_181 ;
F_89 ( & V_187 -> V_179 ) ;
if ( F_55 ( V_187 != & V_64 -> V_173 ) )
F_90 ( V_187 ) ;
}
V_189 = F_95 ( V_169 ) ;
} else {
F_96 (c, tmp, &rctx->chunk_list,
entry) {
if ( V_187 == & V_64 -> V_173 ) {
V_169 = F_60 ( V_64 -> V_106 . V_188 ) ;
} else {
V_169 = ( V_141 -> V_165 [ V_141 -> V_162 - 1 ] . V_166 +
V_141 -> V_165 [ V_141 -> V_162 - 1 ] . V_167 -
V_64 -> V_106 . V_181 ) ;
}
if ( ! V_189 ) {
unsigned long V_190 ;
V_190 = ( V_187 -> V_165 [ V_187 -> V_162 - 1 ] . V_166 +
V_187 -> V_165 [ V_187 -> V_162 - 1 ] . V_167 -
V_64 -> V_106 . V_181 ) ;
V_189 = V_64 -> V_191 ;
memcpy ( V_64 -> V_191 , F_95 ( V_190 ) ,
V_64 -> V_106 . V_181 ) ;
}
V_187 -> V_169 = V_169 ;
V_78 = F_75 ( V_52 , V_187 , V_97 , false ) ;
if ( V_78 )
break;
F_89 ( & V_187 -> V_179 ) ;
if ( F_55 ( V_187 != & V_64 -> V_173 ) )
F_90 ( V_187 ) ;
}
}
if ( ! V_78 ) {
V_15 = F_52 ( V_97 ) ;
if ( V_15 != V_19 )
V_78 = - V_121 ;
}
F_62 ( & V_97 -> V_17 , V_70 ) ;
V_80:
F_63 () ;
F_86 ( V_62 , V_78 ? NULL : V_189 ) ;
return V_78 ;
}
static int F_97 ( struct V_170 * V_62 )
{
return F_94 ( V_62 , true ) ;
}
static int F_98 ( struct V_170 * V_62 )
{
return F_94 ( V_62 , false ) ;
}
static void F_99 ( void )
{
struct V_127 * V_129 , * V_192 ;
struct V_50 * V_54 , * V_193 ;
struct V_59 * V_194 , * V_195 ;
F_88 (cipher, cipher_tmp, &cipher_algs, entry) {
F_100 ( & V_129 -> V_54 ) ;
F_89 ( & V_129 -> V_179 ) ;
F_90 ( V_129 ) ;
}
F_88 (hmac, hmac_tmp, &hmac_algs, derived.entry) {
F_101 ( & V_194 -> V_60 . V_54 ) ;
F_89 ( & V_194 -> V_60 . V_179 ) ;
F_90 ( V_194 ) ;
}
F_88 (alg, alg_tmp, &ahash_algs, entry) {
F_101 ( & V_54 -> V_54 ) ;
F_89 ( & V_54 -> V_179 ) ;
F_90 ( V_54 ) ;
}
}
static int F_102 ( struct V_51 * V_52 )
{
V_52 -> V_196 . V_197 = sizeof( struct V_171 ) ;
return 0 ;
}
static int T_5 F_103 ( const struct V_198 * V_199 )
{
struct V_127 * V_200 = F_84 ( sizeof( * V_200 ) , V_201 ) ;
struct V_53 * V_54 ;
int V_78 ;
if ( ! V_200 )
return - V_185 ;
V_54 = & V_200 -> V_54 ;
snprintf ( V_54 -> V_76 , V_202 , L_9 , V_199 -> V_203 ) ;
snprintf ( V_54 -> V_204 , V_202 , L_10 , V_199 -> V_205 ) ;
V_54 -> V_206 = V_207 ;
V_54 -> V_208 = V_209 |
V_210 | V_211 ;
V_54 -> V_212 = V_199 -> V_157 ;
V_200 -> V_31 = V_199 -> V_31 ;
V_54 -> V_213 = sizeof( struct V_130 ) ;
V_54 -> V_214 = & V_215 ;
V_54 -> V_216 . V_217 = V_199 -> V_217 ;
V_54 -> V_218 = F_102 ;
V_54 -> V_219 = V_220 ;
F_104 ( & V_200 -> V_179 , & V_221 ) ;
V_78 = F_105 ( V_54 ) ;
if ( V_78 ) {
F_4 ( L_11 , V_54 -> V_76 ) ;
F_89 ( & V_200 -> V_179 ) ;
F_90 ( V_200 ) ;
} else {
F_76 ( L_12 , V_54 -> V_76 ) ;
}
return V_78 ;
}
static int T_5 F_106 ( struct V_50 * V_222 )
{
struct V_59 * V_200 = F_84 ( sizeof( * V_200 ) , V_201 ) ;
struct V_56 * V_77 ;
struct V_53 * V_58 ;
int V_78 ;
if ( ! V_200 )
return - V_185 ;
V_200 -> V_85 = V_222 -> V_54 . V_57 . V_58 . V_76 ;
memcpy ( & V_200 -> V_60 , V_222 , sizeof( struct V_50 ) ) ;
F_81 ( & V_200 -> V_60 . V_179 ) ;
V_77 = & V_200 -> V_60 . V_54 ;
V_77 -> V_223 = F_65 ;
V_77 -> V_224 = F_44 ;
V_58 = & V_77 -> V_57 . V_58 ;
snprintf ( V_58 -> V_76 , V_202 , L_13 , V_200 -> V_85 ) ;
snprintf ( V_58 -> V_204 , V_202 , L_14 , V_200 -> V_85 ) ;
V_58 -> V_213 = sizeof( struct V_81 ) ;
V_58 -> V_218 = F_40 ;
V_58 -> V_225 = F_42 ;
F_104 ( & V_200 -> V_60 . V_179 , & V_226 ) ;
V_78 = F_107 ( V_77 ) ;
if ( V_78 ) {
F_4 ( L_11 , V_58 -> V_76 ) ;
F_89 ( & V_200 -> V_60 . V_179 ) ;
F_90 ( V_200 ) ;
} else {
F_76 ( L_12 , V_58 -> V_76 ) ;
}
return V_78 ;
}
static int T_5 F_108 ( const struct V_227 * V_199 )
{
struct V_50 * V_200 = F_84 ( sizeof( * V_200 ) , V_201 ) ;
struct V_228 * V_57 ;
struct V_53 * V_58 ;
struct V_56 * V_77 ;
int V_78 ;
if ( ! V_200 )
return - V_185 ;
V_200 -> V_122 = V_199 -> V_122 ;
V_200 -> V_124 = V_199 -> V_124 ;
V_200 -> V_32 = V_199 -> V_32 ;
V_200 -> V_126 = V_199 -> V_126 ;
V_200 -> V_125 = V_199 -> V_125 ;
V_200 -> V_100 = V_199 -> V_100 ;
V_77 = & V_200 -> V_54 ;
V_77 -> V_229 = F_18 ;
V_77 -> V_230 = F_24 ;
V_77 -> V_231 = F_26 ;
V_77 -> V_232 = F_28 ;
V_77 -> V_223 = F_64 ;
V_57 = & V_77 -> V_57 ;
V_57 -> V_233 = V_199 -> V_100 ;
V_58 = & V_57 -> V_58 ;
snprintf ( V_58 -> V_76 , V_202 , L_9 , V_199 -> V_203 ) ;
snprintf ( V_58 -> V_204 , V_202 , L_10 , V_199 -> V_203 ) ;
V_58 -> V_206 = V_207 ;
V_58 -> V_208 = V_234 |
V_210 |
V_79 ;
V_58 -> V_212 = V_199 -> V_157 ;
V_58 -> V_213 = sizeof( struct V_66 ) ;
V_58 -> V_219 = V_220 ;
V_58 -> V_218 = F_30 ;
V_58 -> V_225 = F_38 ;
F_104 ( & V_200 -> V_179 , & V_235 ) ;
V_78 = F_107 ( V_77 ) ;
if ( V_78 ) {
F_4 ( L_11 , V_58 -> V_76 ) ;
F_89 ( & V_200 -> V_179 ) ;
F_90 ( V_200 ) ;
} else {
F_76 ( L_12 , V_58 -> V_76 ) ;
}
if ( ! V_78 && V_200 -> V_126 != V_236 )
V_78 = F_106 ( V_200 ) ;
return V_78 ;
}
static int T_5 F_109 ( void )
{
int V_153 , V_78 = 0 ;
F_110 ( & V_237 ) ;
if ( V_238 ++ )
goto V_80;
for ( V_153 = 0 ; V_153 < V_239 ; V_153 ++ ) {
V_78 = F_108 ( & V_240 [ V_153 ] ) ;
if ( V_78 ) {
F_99 () ;
goto V_80;
}
}
for ( V_153 = 0 ; V_153 < V_241 ; V_153 ++ ) {
V_78 = F_103 ( & V_242 [ V_153 ] ) ;
if ( V_78 ) {
F_99 () ;
goto V_80;
}
}
V_80:
F_111 ( & V_237 ) ;
return V_78 ;
}
static void T_6 F_112 ( void )
{
F_110 ( & V_237 ) ;
if ( ! -- V_238 )
F_99 () ;
F_111 ( & V_237 ) ;
}
static int F_113 ( struct V_243 * V_244 , struct V_245 * V_246 ,
unsigned long V_247 )
{
const unsigned int * V_248 ;
unsigned int V_249 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_246 -> V_250 ; V_153 ++ ) {
if ( V_246 -> V_251 [ V_153 ] . V_252 == V_247 )
break;
}
if ( V_153 == V_246 -> V_250 )
return - V_107 ;
V_249 = V_246 -> V_251 [ V_153 ] . V_249 ;
V_248 = F_114 ( V_244 -> V_244 . V_253 , L_15 , NULL ) ;
if ( ! V_248 )
return - V_107 ;
for ( V_153 = 0 ; V_153 < V_244 -> V_254 . V_255 ; V_153 ++ ) {
if ( V_248 [ V_153 ] == V_249 )
return V_153 ;
}
return - V_107 ;
}
static int F_115 ( struct V_243 * V_244 , struct V_245 * V_246 ,
const char * V_256 , struct V_1 * V_200 ,
T_7 V_257 )
{
unsigned long V_258 ;
int V_259 ;
V_258 = F_116 ( V_200 -> V_16 , & V_200 -> V_260 ) ;
if ( V_258 )
return - V_121 ;
V_259 = F_113 ( V_244 , V_246 , V_200 -> V_260 ) ;
if ( V_259 < 0 )
return V_259 ;
V_200 -> V_13 = V_244 -> V_254 . V_261 [ V_259 ] ;
sprintf ( V_200 -> V_256 , L_16 , V_256 , V_259 ) ;
return F_117 ( V_200 -> V_13 , V_257 , V_262 ,
V_200 -> V_256 , V_200 ) ;
}
static void * F_118 ( unsigned long V_4 )
{
return F_119 ( V_263 [ V_4 - 1 ] , V_201 ) ;
}
static void F_120 ( void * V_200 , unsigned long V_4 )
{
return F_121 ( V_263 [ V_4 - 1 ] , V_200 ) ;
}
static int F_122 ( void )
{
if ( ! V_263 [ V_5 - 1 ] )
V_263 [ V_5 - 1 ] =
F_123 ( L_17 ,
( V_7 *
V_6 ) ,
V_6 , 0 , NULL ) ;
if ( ! V_263 [ V_5 - 1 ] )
return - V_185 ;
if ( ! V_263 [ V_264 - 1 ] )
V_263 [ V_264 - 1 ] =
F_123 ( L_18 ,
( V_9 *
V_8 ) ,
V_8 , 0 , NULL ) ;
if ( ! V_263 [ V_264 - 1 ] ) {
F_124 ( V_263 [ V_5 - 1 ] ) ;
return - V_185 ;
}
return 0 ;
}
static void F_125 ( void )
{
F_124 ( V_263 [ V_5 - 1 ] ) ;
F_124 ( V_263 [ V_264 - 1 ] ) ;
}
static int F_126 ( struct V_1 * V_200 , unsigned long V_4 )
{
T_8 V_265 ;
unsigned long V_15 ;
if ( F_127 ( & V_200 -> V_266 ) )
return - V_121 ;
if ( ! F_128 ( & V_265 , V_201 ) )
return - V_185 ;
F_129 ( V_265 , & V_267 -> V_268 ) ;
F_130 ( V_267 , & V_200 -> V_266 ) ;
V_15 = F_131 ( V_4 , F_60 ( V_200 -> V_2 ) ,
V_9 , & V_200 -> V_16 ) ;
if ( ! V_15 )
F_8 ( V_200 -> V_16 , 0 ) ;
F_130 ( V_267 , V_265 ) ;
F_132 ( V_265 ) ;
return ( V_15 ? - V_121 : 0 ) ;
}
static int F_133 ( struct V_1 * V_200 )
{
int V_78 ;
V_200 -> V_2 = F_118 ( V_200 -> V_4 ) ;
if ( ! V_200 -> V_2 )
return - V_185 ;
V_78 = F_126 ( V_200 , V_200 -> V_4 ) ;
if ( V_78 ) {
F_120 ( V_200 -> V_2 , V_200 -> V_4 ) ;
V_200 -> V_2 = NULL ;
}
return V_78 ;
}
static void F_134 ( struct V_1 * V_200 )
{
unsigned long V_15 ;
if ( ! V_200 -> V_2 )
return;
V_15 = F_131 ( V_200 -> V_4 , V_200 -> V_16 , 0 , & V_200 -> V_16 ) ;
if ( ! V_15 )
F_120 ( V_200 -> V_2 , V_200 -> V_4 ) ;
}
static void F_135 ( struct V_269 * V_270 )
{
struct V_1 * V_200 , * V_271 ;
F_88 (p, n, list, list) {
int V_153 ;
for ( V_153 = 0 ; V_153 < V_272 ; V_153 ++ ) {
if ( V_109 [ V_153 ] == V_200 )
V_109 [ V_153 ] = NULL ;
}
if ( V_200 -> V_13 ) {
F_136 ( V_200 -> V_13 , V_200 ) ;
V_200 -> V_13 = 0 ;
}
F_134 ( V_200 ) ;
F_89 ( & V_200 -> V_270 ) ;
F_90 ( V_200 ) ;
}
}
static int F_137 ( struct V_273 * V_274 ,
struct V_243 * V_244 ,
T_2 V_275 , struct V_1 * V_200 ,
struct V_1 * * V_276 )
{
T_2 V_277 ;
F_138 (arc, mdesc, node, MDESC_ARC_TYPE_BACK) {
T_2 V_278 = F_139 ( V_274 , V_277 ) ;
const char * V_203 = F_140 ( V_274 , V_278 ) ;
const T_2 * V_279 ;
if ( strcmp ( V_203 , L_19 ) )
continue;
V_279 = F_141 ( V_274 , V_278 , L_20 , NULL ) ;
if ( V_276 [ * V_279 ] != NULL ) {
F_142 ( & V_244 -> V_244 , L_21 ,
V_244 -> V_244 . V_253 -> V_280 ) ;
return - V_121 ;
}
F_143 ( * V_279 , V_200 -> V_266 ) ;
V_276 [ * V_279 ] = V_200 ;
}
return 0 ;
}
static int F_144 ( struct V_245 * V_246 , struct V_269 * V_270 ,
struct V_243 * V_244 , struct V_273 * V_274 ,
T_2 V_275 , const char * V_281 , unsigned long V_4 ,
T_7 V_257 , struct V_1 * * V_276 )
{
struct V_1 * V_200 ;
int V_78 ;
V_200 = F_84 ( sizeof( struct V_1 ) , V_201 ) ;
if ( ! V_200 ) {
F_142 ( & V_244 -> V_244 , L_22 ,
V_244 -> V_244 . V_253 -> V_280 ) ;
return - V_185 ;
}
F_145 ( V_200 -> V_266 ) ;
F_146 ( & V_200 -> V_17 ) ;
V_200 -> V_4 = V_4 ;
F_81 ( & V_200 -> V_282 ) ;
F_104 ( & V_200 -> V_270 , V_270 ) ;
V_78 = F_137 ( V_274 , V_244 , V_275 , V_200 , V_276 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_133 ( V_200 ) ;
if ( V_78 )
return V_78 ;
return F_115 ( V_244 , V_246 , V_281 , V_200 , V_257 ) ;
}
static int F_147 ( struct V_273 * V_274 , struct V_243 * V_244 ,
struct V_245 * V_246 , struct V_269 * V_270 ,
const char * V_283 , unsigned long V_4 ,
T_7 V_257 , struct V_1 * * V_276 )
{
int V_78 = 0 ;
T_2 V_275 ;
F_148 (mdesc, node, L_23 ) {
const char * type ;
type = F_141 ( V_274 , V_275 , L_24 , NULL ) ;
if ( ! type || strcmp ( type , V_283 ) )
continue;
V_78 = F_144 ( V_246 , V_270 , V_244 , V_274 , V_275 ,
V_283 , V_4 , V_257 , V_276 ) ;
if ( V_78 ) {
F_135 ( V_270 ) ;
break;
}
}
return V_78 ;
}
static int T_5 F_149 ( struct V_273 * V_274 , T_2 V_275 ,
struct V_245 * V_246 )
{
const T_2 * V_252 ;
int V_284 ;
int V_153 ;
V_252 = F_141 ( V_274 , V_275 , L_25 , & V_284 ) ;
if ( ! V_252 ) {
F_150 ( L_26 ) ;
return - V_107 ;
}
V_246 -> V_250 = V_284 / sizeof( T_2 ) ;
V_246 -> V_251 = F_84 ( ( sizeof( struct V_285 ) *
V_246 -> V_250 ) ,
V_201 ) ;
if ( ! V_246 -> V_251 )
return - V_185 ;
for ( V_153 = 0 ; V_153 < V_246 -> V_250 ; V_153 ++ ) {
struct V_285 * V_286 = & V_246 -> V_251 [ V_153 ] ;
V_286 -> V_249 = V_153 + 1 ;
V_286 -> V_252 = V_252 [ V_153 ] ;
}
return 0 ;
}
static int T_5 F_151 ( struct V_273 * V_274 ,
struct V_243 * V_244 ,
struct V_245 * V_246 ,
const char * V_287 )
{
const unsigned int * V_288 ;
T_2 V_275 ;
V_288 = F_114 ( V_244 -> V_244 . V_253 , L_27 , NULL ) ;
if ( ! V_288 )
return - V_107 ;
F_148 (mdesc, node, L_28 ) {
const char * V_203 ;
const T_2 * V_289 ;
V_203 = F_141 ( V_274 , V_275 , L_29 , NULL ) ;
if ( ! V_203 || strcmp ( V_203 , V_287 ) )
continue;
V_289 = F_141 ( V_274 , V_275 , L_30 , NULL ) ;
if ( ! V_289 || ( * V_289 != * V_288 ) )
continue;
V_246 -> V_290 = * V_289 ;
return F_149 ( V_274 , V_275 , V_246 ) ;
}
return - V_107 ;
}
static int T_5 F_152 ( void )
{
int V_78 ;
V_291 = 2 ;
V_292 = 0 ;
V_78 = F_153 ( V_293 ,
V_291 ,
& V_292 ) ;
if ( ! V_78 )
F_76 ( L_31 ,
V_291 ,
V_292 ) ;
return V_78 ;
}
static void F_154 ( void )
{
F_155 ( V_293 ) ;
}
static int T_5 F_156 ( void )
{
int V_78 = 0 ;
F_110 ( & V_237 ) ;
if ( V_294 ++ )
goto V_80;
V_78 = F_152 () ;
if ( V_78 )
goto V_80;
V_78 = F_122 () ;
if ( V_78 )
goto V_295;
V_78 = - V_185 ;
V_109 = F_84 ( sizeof( struct V_1 * ) * V_272 ,
V_201 ) ;
if ( ! V_109 )
goto V_296;
V_297 = F_84 ( sizeof( struct V_1 * ) * V_272 ,
V_201 ) ;
if ( ! V_297 )
goto V_298;
V_78 = 0 ;
V_80:
if ( V_78 )
V_294 -- ;
F_111 ( & V_237 ) ;
return V_78 ;
V_298:
F_90 ( V_109 ) ;
V_109 = NULL ;
V_296:
F_125 () ;
V_295:
F_154 () ;
goto V_80;
}
static void F_157 ( void )
{
F_110 ( & V_237 ) ;
if ( ! -- V_294 ) {
F_90 ( V_109 ) ;
V_109 = NULL ;
F_90 ( V_297 ) ;
V_297 = NULL ;
F_125 () ;
F_154 () ;
}
F_111 ( & V_237 ) ;
}
static struct V_299 * T_5 F_158 ( void )
{
struct V_299 * V_300 = F_84 ( sizeof( struct V_299 ) , V_201 ) ;
if ( V_300 )
F_81 ( & V_300 -> V_301 ) ;
return V_300 ;
}
static void F_159 ( struct V_299 * V_300 )
{
if ( V_300 -> V_302 . V_251 ) {
F_90 ( V_300 -> V_302 . V_251 ) ;
V_300 -> V_302 . V_251 = NULL ;
}
F_90 ( V_300 ) ;
}
static void T_5 F_160 ( void )
{
static int V_303 ;
if ( V_303 ++ == 0 )
F_76 ( L_9 , V_304 ) ;
}
static int T_5 F_161 ( struct V_243 * V_244 )
{
struct V_273 * V_274 ;
const char * V_280 ;
struct V_299 * V_300 ;
int V_78 ;
F_160 () ;
V_280 = V_244 -> V_244 . V_253 -> V_280 ;
F_76 ( L_32 , V_280 ) ;
V_300 = F_158 () ;
if ( ! V_300 ) {
F_142 ( & V_244 -> V_244 , L_33 ,
V_280 ) ;
return - V_185 ;
}
V_78 = F_156 () ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_34
L_35 , V_280 ) ;
goto V_305;
}
V_274 = F_162 () ;
if ( ! V_274 ) {
F_142 ( & V_244 -> V_244 , L_36 ,
V_280 ) ;
V_78 = - V_107 ;
goto V_306;
}
V_78 = F_151 ( V_274 , V_244 , & V_300 -> V_302 , L_37 ) ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_38 ,
V_280 ) ;
F_163 ( V_274 ) ;
goto V_306;
}
V_78 = F_147 ( V_274 , V_244 , & V_300 -> V_302 , & V_300 -> V_301 ,
L_39 , V_264 , F_3 ,
V_109 ) ;
F_163 ( V_274 ) ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_40 ,
V_280 ) ;
goto V_306;
}
V_78 = F_109 () ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_41 ,
V_280 ) ;
goto V_307;
}
F_164 ( & V_244 -> V_244 , V_300 ) ;
return 0 ;
V_307:
F_135 ( & V_300 -> V_301 ) ;
V_306:
F_157 () ;
V_305:
F_159 ( V_300 ) ;
return V_78 ;
}
static int T_6 F_165 ( struct V_243 * V_244 )
{
struct V_299 * V_300 = F_166 ( & V_244 -> V_244 ) ;
F_112 () ;
F_135 ( & V_300 -> V_301 ) ;
F_157 () ;
F_159 ( V_300 ) ;
return 0 ;
}
static struct V_308 * T_5 F_167 ( void )
{
struct V_308 * V_309 = F_84 ( sizeof( struct V_308 ) , V_201 ) ;
if ( V_309 )
F_81 ( & V_309 -> V_310 ) ;
return V_309 ;
}
static void F_168 ( struct V_308 * V_309 )
{
if ( V_309 -> V_311 . V_251 ) {
F_90 ( V_309 -> V_311 . V_251 ) ;
V_309 -> V_311 . V_251 = NULL ;
}
F_90 ( V_309 ) ;
}
static int T_5 F_169 ( struct V_243 * V_244 )
{
struct V_273 * V_274 ;
const char * V_280 ;
struct V_308 * V_309 ;
int V_78 ;
F_160 () ;
V_280 = V_244 -> V_244 . V_253 -> V_280 ;
F_76 ( L_42 , V_280 ) ;
V_309 = F_167 () ;
if ( ! V_309 ) {
F_142 ( & V_244 -> V_244 , L_43 ,
V_280 ) ;
return - V_185 ;
}
V_78 = F_156 () ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_34
L_35 , V_280 ) ;
goto V_312;
}
V_274 = F_162 () ;
if ( ! V_274 ) {
F_142 ( & V_244 -> V_244 , L_36 ,
V_280 ) ;
V_78 = - V_107 ;
goto V_306;
}
V_78 = F_151 ( V_274 , V_244 , & V_309 -> V_311 , L_44 ) ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_38 ,
V_280 ) ;
F_163 ( V_274 ) ;
goto V_306;
}
V_78 = F_147 ( V_274 , V_244 , & V_309 -> V_311 , & V_309 -> V_310 ,
L_45 , V_5 , F_10 ,
V_297 ) ;
F_163 ( V_274 ) ;
if ( V_78 ) {
F_142 ( & V_244 -> V_244 , L_46 ,
V_280 ) ;
goto V_306;
}
F_164 ( & V_244 -> V_244 , V_309 ) ;
return 0 ;
V_306:
F_157 () ;
V_312:
F_168 ( V_309 ) ;
return V_78 ;
}
static int T_6 F_170 ( struct V_243 * V_244 )
{
struct V_308 * V_309 = F_166 ( & V_244 -> V_244 ) ;
F_135 ( & V_309 -> V_310 ) ;
F_157 () ;
F_168 ( V_309 ) ;
return 0 ;
}
static int T_9 F_171 ( void )
{
int V_78 = F_172 ( & V_313 ) ;
if ( ! V_78 ) {
V_78 = F_172 ( & V_314 ) ;
if ( V_78 )
F_173 ( & V_313 ) ;
}
return V_78 ;
}
static void T_10 F_174 ( void )
{
F_173 ( & V_314 ) ;
F_173 ( & V_313 ) ;
}
