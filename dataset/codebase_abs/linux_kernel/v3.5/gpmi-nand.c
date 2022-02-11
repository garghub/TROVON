static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
F_3 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static inline int F_4 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
int V_11 ;
V_11 = ( ( V_10 -> V_12 - V_8 -> V_13 ) * 8 )
/ ( V_8 -> V_14 * V_8 -> V_15 ) ;
return F_5 ( V_11 , 2 ) ;
}
int F_6 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_13 ;
unsigned int V_16 ;
unsigned int V_17 ;
V_8 -> V_13 = 10 ;
V_8 -> V_14 = 13 ;
V_8 -> V_18 = 512 ;
while ( V_8 -> V_18 < V_10 -> V_12 )
V_8 -> V_18 *= 2 ;
V_8 -> V_15 = V_10 -> V_19 / V_8 -> V_18 ;
V_8 -> V_11 = F_4 ( V_4 ) ;
if ( ! V_8 -> V_11 ) {
F_7 ( L_1 ) ;
return - V_20 ;
}
V_8 -> V_21 = V_10 -> V_19 + V_10 -> V_12 ;
V_8 -> V_22 = V_10 -> V_19 ;
V_13 = F_8 ( V_8 -> V_13 , 4 ) ;
V_16 = F_8 ( V_8 -> V_15 , 4 ) ;
V_8 -> V_23 = V_13 + V_16 ;
V_8 -> V_24 = V_13 ;
if ( ! V_4 -> V_25 )
return 0 ;
V_17 = V_10 -> V_19 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_26 = V_17 / 8 ;
V_8 -> V_17 = V_17 % 8 ;
return 0 ;
}
struct V_27 * F_9 ( struct V_3 * V_4 )
{
int V_28 = V_4 -> V_29 ;
return V_4 -> V_30 [ V_28 ] ;
}
void F_10 ( struct V_3 * V_4 , enum V_31 V_32 )
{
struct V_33 * V_34 = & V_4 -> V_35 ;
int V_36 ;
V_4 -> V_37 = true ;
F_11 ( V_34 , V_4 -> V_38 , V_4 -> V_39 ) ;
V_36 = F_12 ( V_4 -> V_40 , V_34 , 1 , V_32 ) ;
if ( V_36 == 0 ) {
F_11 ( V_34 , V_4 -> V_41 , V_42 ) ;
if ( V_32 == V_43 )
memcpy ( V_4 -> V_41 , V_4 -> V_38 ,
V_4 -> V_39 ) ;
V_36 = F_12 ( V_4 -> V_40 , V_34 , 1 , V_32 ) ;
if ( V_36 == 0 )
F_7 ( L_2 ) ;
V_4 -> V_37 = false ;
}
}
static void F_13 ( void * V_44 )
{
struct V_3 * V_4 = V_44 ;
struct V_45 * V_46 = & V_4 -> V_47 ;
F_3 ( V_46 ) ;
switch ( V_4 -> V_48 ) {
case V_49 :
F_14 ( V_4 -> V_40 , & V_4 -> V_50 , 1 , V_43 ) ;
break;
case V_51 :
F_14 ( V_4 -> V_40 , & V_4 -> V_35 , 1 , V_52 ) ;
if ( V_4 -> V_37 == false )
memcpy ( V_4 -> V_38 , V_4 -> V_41 ,
V_4 -> V_39 ) ;
break;
case V_53 :
F_14 ( V_4 -> V_40 , & V_4 -> V_35 , 1 , V_43 ) ;
break;
case V_54 :
case V_55 :
break;
default:
F_7 ( L_3 ) ;
}
}
int F_15 ( struct V_3 * V_4 ,
struct V_56 * V_57 )
{
struct V_45 * V_46 = & V_4 -> V_47 ;
int V_58 ;
F_16 ( V_46 ) ;
V_57 -> V_59 = F_13 ;
V_57 -> V_60 = V_4 ;
F_17 ( V_57 ) ;
F_18 ( F_9 ( V_4 ) ) ;
V_58 = F_19 ( V_46 , F_20 ( 1000 ) ) ;
if ( ! V_58 ) {
F_7 ( L_4 , V_4 -> V_61 ) ;
F_21 ( V_4 ) ;
return - V_62 ;
}
return 0 ;
}
int F_22 ( struct V_3 * V_4 ,
struct V_56 * V_57 )
{
struct V_45 * V_63 = & V_4 -> V_5 ;
int V_58 ;
F_16 ( V_63 ) ;
F_15 ( V_4 , V_57 ) ;
V_58 = F_19 ( V_63 , F_20 ( 1000 ) ) ;
if ( ! V_58 ) {
F_7 ( L_5 , V_4 -> V_61 ) ;
F_21 ( V_4 ) ;
return - V_62 ;
}
return 0 ;
}
static int T_2
F_23 ( struct V_3 * V_4 , const char * V_64 )
{
struct V_65 * V_66 = V_4 -> V_66 ;
struct V_67 * V_68 = & V_4 -> V_67 ;
struct V_69 * V_70 ;
void * V_71 ;
V_70 = F_24 ( V_66 , V_72 , V_64 ) ;
if ( ! V_70 ) {
F_7 ( L_6 , V_64 ) ;
return - V_73 ;
}
V_71 = F_25 ( V_70 -> V_74 , F_26 ( V_70 ) ) ;
if ( ! V_71 ) {
F_7 ( L_7 , V_64 ) ;
return - V_75 ;
}
if ( ! strcmp ( V_64 , V_76 ) )
V_68 -> V_77 = V_71 ;
else if ( ! strcmp ( V_64 , V_78 ) )
V_68 -> V_79 = V_71 ;
else
F_7 ( L_8 , V_64 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_67 * V_68 = & V_4 -> V_67 ;
if ( V_68 -> V_77 )
F_28 ( V_68 -> V_77 ) ;
if ( V_68 -> V_79 )
F_28 ( V_68 -> V_79 ) ;
V_68 -> V_77 = NULL ;
V_68 -> V_79 = NULL ;
}
static int T_2
F_29 ( struct V_3 * V_4 , T_3 V_80 )
{
struct V_65 * V_66 = V_4 -> V_66 ;
struct V_67 * V_68 = & V_4 -> V_67 ;
const char * V_64 = V_81 ;
struct V_69 * V_70 ;
int V_58 ;
V_70 = F_24 ( V_66 , V_82 , V_64 ) ;
if ( ! V_70 ) {
F_7 ( L_6 , V_64 ) ;
return - V_73 ;
}
V_58 = F_30 ( V_70 -> V_74 , V_80 , 0 , V_64 , V_4 ) ;
if ( V_58 ) {
F_7 ( L_9 , V_64 ) ;
return V_58 ;
}
V_68 -> V_83 = V_70 -> V_74 ;
V_68 -> V_84 = V_70 -> V_85 ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_67 * V_68 = & V_4 -> V_67 ;
int V_86 = V_68 -> V_83 ;
for (; V_86 <= V_68 -> V_84 ; V_86 ++ )
F_32 ( V_86 , V_4 ) ;
}
static bool F_33 ( struct V_27 * V_87 , void * V_44 )
{
struct V_3 * V_4 = V_44 ;
int V_88 = ( int ) V_4 -> V_89 ;
if ( ! F_34 ( V_87 ) )
return false ;
if ( V_88 == V_87 -> V_90 ) {
V_87 -> V_89 = & V_4 -> V_91 ;
return true ;
}
return false ;
}
static void F_35 ( struct V_3 * V_4 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_92 ; V_86 ++ )
if ( V_4 -> V_30 [ V_86 ] ) {
F_36 ( V_4 -> V_30 [ V_86 ] ) ;
V_4 -> V_30 [ V_86 ] = NULL ;
}
}
static int T_2 F_37 ( struct V_3 * V_4 )
{
struct V_65 * V_66 = V_4 -> V_66 ;
struct V_69 * V_93 ;
struct V_94 * V_95 ;
int V_88 ;
unsigned int V_36 ;
struct V_27 * V_27 ;
T_4 V_96 ;
V_95 = V_66 -> V_40 . V_97 ;
V_36 = F_38 ( V_95 , L_10 , & V_88 ) ;
if ( V_36 ) {
F_7 ( L_11 ) ;
goto V_98;
}
V_4 -> V_89 = ( void * ) V_88 ;
V_93 = F_24 ( V_66 , V_82 ,
V_99 ) ;
if ( ! V_93 ) {
F_7 ( L_12 ) ;
goto V_98;
}
V_4 -> V_91 . V_100 = V_93 -> V_74 ;
F_39 ( V_96 ) ;
F_40 ( V_101 , V_96 ) ;
V_27 = F_41 ( V_96 , F_33 , V_4 ) ;
if ( ! V_27 ) {
F_7 ( L_13 ) ;
goto V_98;
}
V_4 -> V_30 [ 0 ] = V_27 ;
return 0 ;
V_98:
F_35 ( V_4 ) ;
return - V_20 ;
}
static int T_2 F_42 ( struct V_3 * V_4 )
{
struct V_67 * V_68 = & V_4 -> V_67 ;
struct V_102 * V_102 ;
int V_36 ;
V_36 = F_23 ( V_4 , V_76 ) ;
if ( V_36 )
goto V_103;
V_36 = F_23 ( V_4 , V_78 ) ;
if ( V_36 )
goto V_103;
V_36 = F_29 ( V_4 , F_1 ) ;
if ( V_36 )
goto V_103;
V_36 = F_37 ( V_4 ) ;
if ( V_36 )
goto V_104;
V_102 = F_43 ( & V_4 -> V_66 -> V_40 ) ;
if ( F_44 ( V_102 ) ) {
V_36 = F_45 ( V_102 ) ;
goto V_105;
}
V_68 -> clock = F_46 ( & V_4 -> V_66 -> V_40 , NULL ) ;
if ( F_44 ( V_68 -> clock ) ) {
F_7 ( L_14 ) ;
V_36 = - V_106 ;
goto V_107;
}
return 0 ;
V_107:
V_105:
F_35 ( V_4 ) ;
V_104:
F_31 ( V_4 ) ;
V_103:
F_27 ( V_4 ) ;
return V_36 ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_67 * V_70 = & V_4 -> V_67 ;
F_48 ( V_70 -> clock ) ;
F_27 ( V_4 ) ;
F_31 ( V_4 ) ;
F_35 ( V_4 ) ;
}
static int T_2 F_49 ( struct V_3 * V_4 )
{
int V_36 ;
struct V_108 V_109 = {
. V_110 = 80 ,
. V_111 = 60 ,
. V_112 = 25 ,
. V_113 = 6 ,
. V_114 = - 1 ,
. V_115 = - 1 ,
. V_116 = - 1 ,
} ;
V_36 = F_50 ( V_4 ) ;
if ( V_36 )
return V_36 ;
V_4 -> V_117 = V_109 ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
void * V_118 , unsigned V_119 ,
void * V_120 , T_5 V_121 , unsigned V_122 ,
void * * V_123 , T_5 * V_124 )
{
struct V_125 * V_40 = V_4 -> V_40 ;
if ( F_52 ( V_118 ) ) {
T_5 V_126 ;
V_126 = F_53 ( V_40 , V_118 ,
V_119 , V_52 ) ;
if ( F_54 ( V_40 , V_126 ) ) {
if ( V_122 < V_119 ) {
F_7 ( L_15 ) ;
return - V_75 ;
}
goto V_127;
}
* V_123 = V_118 ;
* V_124 = V_126 ;
V_4 -> V_37 = true ;
return 0 ;
}
V_127:
* V_123 = V_120 ;
* V_124 = V_121 ;
V_4 -> V_37 = false ;
return 0 ;
}
static inline void F_55 ( struct V_3 * V_4 ,
void * V_118 , unsigned V_119 ,
void * V_120 , T_5 V_121 , unsigned V_122 ,
void * V_128 , T_5 V_129 )
{
if ( V_4 -> V_37 )
F_56 ( V_4 -> V_40 , V_129 , V_119 , V_52 ) ;
}
static inline void F_57 ( struct V_3 * V_4 ,
void * V_118 , unsigned V_119 ,
void * V_120 , T_5 V_121 , unsigned V_122 ,
void * V_128 , T_5 V_129 )
{
if ( ! V_4 -> V_37 )
memcpy ( V_118 , V_120 , V_119 ) ;
}
static int F_58 ( struct V_3 * V_4 ,
const void * V_130 , unsigned V_119 ,
void * V_120 , T_5 V_121 , unsigned V_122 ,
const void * * V_123 , T_5 * V_124 )
{
struct V_125 * V_40 = V_4 -> V_40 ;
if ( F_52 ( V_130 ) ) {
T_5 V_131 ;
V_131 = F_53 ( V_40 , ( void * ) V_130 , V_119 ,
V_43 ) ;
if ( F_54 ( V_40 , V_131 ) ) {
if ( V_122 < V_119 ) {
F_7 ( L_15 ) ;
return - V_75 ;
}
goto V_127;
}
* V_123 = V_130 ;
* V_124 = V_131 ;
return 0 ;
}
V_127:
memcpy ( V_120 , V_130 , V_119 ) ;
* V_123 = V_120 ;
* V_124 = V_121 ;
return 0 ;
}
static void F_59 ( struct V_3 * V_4 ,
const void * V_130 , unsigned V_119 ,
void * V_120 , T_5 V_121 , unsigned V_122 ,
const void * V_128 , T_5 V_129 )
{
struct V_125 * V_40 = V_4 -> V_40 ;
if ( V_128 == V_130 )
F_56 ( V_40 , V_129 , V_119 , V_43 ) ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_125 * V_40 = V_4 -> V_40 ;
if ( V_4 -> V_132 && F_52 ( V_4 -> V_132 ) )
F_61 ( V_40 , V_4 -> V_133 ,
V_4 -> V_132 ,
V_4 -> V_134 ) ;
F_62 ( V_4 -> V_135 ) ;
F_62 ( V_4 -> V_41 ) ;
V_4 -> V_135 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_132 = NULL ;
V_4 -> V_133 = 0 ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_125 * V_40 = V_4 -> V_40 ;
V_4 -> V_135 = F_64 ( V_42 , V_136 ) ;
if ( V_4 -> V_135 == NULL )
goto V_137;
V_4 -> V_41 = F_64 ( V_42 , V_136 ) ;
if ( V_4 -> V_41 == NULL )
goto V_137;
V_4 -> V_133 = V_8 -> V_22 + V_8 -> V_23 ;
V_4 -> V_132 = F_65 ( V_40 , V_4 -> V_133 ,
& V_4 -> V_134 , V_136 ) ;
if ( ! V_4 -> V_132 )
goto V_137;
V_4 -> V_138 = V_4 -> V_132 ;
V_4 -> V_139 = V_4 -> V_134 ;
V_4 -> V_140 = V_4 -> V_138 + V_8 -> V_22 ;
V_4 -> V_141 = V_4 -> V_139 + V_8 -> V_22 ;
return 0 ;
V_137:
F_60 ( V_4 ) ;
F_7 ( L_16 ) ;
return - V_75 ;
}
static void F_66 ( struct V_9 * V_10 , int V_142 , unsigned int V_143 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
int V_36 ;
if ( ( V_143 & ( V_147 | V_148 ) ) ) {
if ( V_142 != V_149 )
V_4 -> V_135 [ V_4 -> V_150 ++ ] = V_142 ;
return;
}
if ( ! V_4 -> V_150 )
return;
V_36 = F_67 ( V_4 ) ;
if ( V_36 )
F_7 ( L_17 , V_4 -> V_29 , V_36 ) ;
V_4 -> V_150 = 0 ;
}
static int F_68 ( struct V_9 * V_10 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
return F_69 ( V_4 , V_4 -> V_29 ) ;
}
static void F_70 ( struct V_9 * V_10 , int V_28 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
if ( ( V_4 -> V_29 < 0 ) && ( V_28 >= 0 ) )
F_71 ( V_4 ) ;
else if ( ( V_4 -> V_29 >= 0 ) && ( V_28 < 0 ) )
F_72 ( V_4 ) ;
V_4 -> V_29 = V_28 ;
}
static void F_73 ( struct V_9 * V_10 , T_6 * V_151 , int V_152 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
F_74 ( L_18 , V_152 ) ;
V_4 -> V_38 = V_151 ;
V_4 -> V_39 = V_152 ;
F_75 ( V_4 ) ;
}
static void F_76 ( struct V_9 * V_10 , const T_6 * V_151 , int V_152 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
F_74 ( L_18 , V_152 ) ;
V_4 -> V_38 = ( T_6 * ) V_151 ;
V_4 -> V_39 = V_152 ;
F_77 ( V_4 ) ;
}
static T_6 F_78 ( struct V_9 * V_10 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
T_6 * V_151 = V_4 -> V_41 ;
F_73 ( V_10 , V_151 , 1 ) ;
return V_151 [ 0 ] ;
}
static void F_79 ( struct V_3 * V_4 ,
void * V_153 , void * V_154 )
{
struct V_7 * V_155 = & V_4 -> V_7 ;
unsigned char * V_71 ;
unsigned char * V_156 ;
unsigned int V_157 ;
unsigned char V_96 ;
unsigned char V_158 ;
unsigned char V_159 ;
if ( ! V_4 -> V_25 )
return;
V_157 = V_155 -> V_17 ;
V_71 = V_153 + V_155 -> V_26 ;
V_156 = V_154 ;
V_158 = ( V_71 [ 0 ] >> V_157 ) | ( V_71 [ 1 ] << ( 8 - V_157 ) ) ;
V_159 = V_156 [ 0 ] ;
V_156 [ 0 ] = V_158 ;
V_96 = ( 0x1 << V_157 ) - 1 ;
V_71 [ 0 ] = ( V_71 [ 0 ] & V_96 ) | ( V_159 << V_157 ) ;
V_96 = ~ 0 << V_157 ;
V_71 [ 1 ] = ( V_71 [ 1 ] & V_96 ) | ( V_159 >> ( 8 - V_157 ) ) ;
}
static int F_80 ( struct V_9 * V_10 , struct V_144 * V_145 ,
T_6 * V_151 , int V_160 , int V_161 )
{
struct V_3 * V_4 = V_145 -> V_146 ;
struct V_7 * V_155 = & V_4 -> V_7 ;
void * V_138 ;
T_5 V_139 ;
void * V_140 ;
T_5 V_141 ;
unsigned int V_86 ;
unsigned char * V_162 ;
unsigned int V_163 ;
unsigned int V_164 ;
int V_36 ;
F_74 ( L_19 , V_161 ) ;
V_36 = F_51 ( V_4 , V_151 , V_10 -> V_19 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_155 -> V_22 ,
& V_138 , & V_139 ) ;
if ( V_36 ) {
F_7 ( L_20 ) ;
V_36 = - V_75 ;
return V_36 ;
}
V_140 = V_4 -> V_140 ;
V_141 = V_4 -> V_141 ;
V_36 = F_81 ( V_4 , V_139 , V_141 ) ;
F_55 ( V_4 , V_151 , V_10 -> V_19 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_155 -> V_22 ,
V_138 , V_139 ) ;
if ( V_36 ) {
F_7 ( L_21 , V_36 ) ;
goto V_165;
}
F_79 ( V_4 , V_138 , V_140 ) ;
V_163 = 0 ;
V_164 = 0 ;
V_162 = V_140 + V_155 -> V_24 ;
for ( V_86 = 0 ; V_86 < V_155 -> V_15 ; V_86 ++ , V_162 ++ ) {
if ( ( * V_162 == V_166 ) || ( * V_162 == V_167 ) )
continue;
if ( * V_162 == V_168 ) {
V_163 ++ ;
continue;
}
V_164 += * V_162 ;
}
if ( V_163 || V_164 >= ( V_155 -> V_11 - 1 ) ) {
V_10 -> V_169 . V_163 += V_163 ;
V_10 -> V_169 . V_164 += V_164 ;
}
if ( V_160 ) {
memset ( V_145 -> V_170 , ~ 0 , V_10 -> V_12 ) ;
V_145 -> V_170 [ 0 ] = ( ( T_6 * ) V_140 ) [ 0 ] ;
}
F_57 ( V_4 , V_151 , V_10 -> V_19 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_155 -> V_22 ,
V_138 , V_139 ) ;
V_165:
return V_36 ;
}
static void F_82 ( struct V_9 * V_10 , struct V_144 * V_145 ,
const T_6 * V_151 , int V_160 )
{
struct V_3 * V_4 = V_145 -> V_146 ;
struct V_7 * V_155 = & V_4 -> V_7 ;
const void * V_138 ;
T_5 V_139 ;
const void * V_140 ;
T_5 V_141 ;
int V_36 ;
F_74 ( L_22 ) ;
if ( V_4 -> V_25 ) {
memcpy ( V_4 -> V_138 , V_151 , V_10 -> V_19 ) ;
V_138 = V_4 -> V_138 ;
V_139 = V_4 -> V_139 ;
memcpy ( V_4 -> V_140 , V_145 -> V_170 ,
V_155 -> V_23 ) ;
V_140 = V_4 -> V_140 ;
V_141 = V_4 -> V_141 ;
F_79 ( V_4 ,
( void * ) V_138 , ( void * ) V_140 ) ;
} else {
V_36 = F_58 ( V_4 ,
V_151 , V_10 -> V_19 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_155 -> V_22 ,
& V_138 , & V_139 ) ;
if ( V_36 ) {
F_7 ( L_23 ) ;
return;
}
V_36 = F_58 ( V_4 ,
V_145 -> V_170 , V_10 -> V_12 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_155 -> V_23 ,
& V_140 , & V_141 ) ;
if ( V_36 ) {
F_7 ( L_24 ) ;
goto V_171;
}
}
V_36 = F_83 ( V_4 , V_139 , V_141 ) ;
if ( V_36 )
F_7 ( L_25 , V_36 ) ;
if ( ! V_4 -> V_25 ) {
F_59 ( V_4 , V_145 -> V_170 , V_10 -> V_12 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_155 -> V_23 ,
V_140 , V_141 ) ;
V_171:
F_59 ( V_4 , V_151 , V_10 -> V_19 ,
V_4 -> V_138 , V_4 -> V_139 ,
V_155 -> V_22 ,
V_138 , V_139 ) ;
}
}
static int F_84 ( struct V_9 * V_10 , struct V_144 * V_145 ,
int V_161 )
{
struct V_3 * V_4 = V_145 -> V_146 ;
F_74 ( L_26 , V_161 ) ;
memset ( V_145 -> V_170 , ~ 0 , V_10 -> V_12 ) ;
V_145 -> V_172 ( V_10 , V_173 , V_10 -> V_19 , V_161 ) ;
V_145 -> V_174 ( V_10 , V_145 -> V_170 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_25 ) {
V_145 -> V_172 ( V_10 , V_173 , 0 , V_161 ) ;
V_145 -> V_170 [ 0 ] = V_145 -> V_175 ( V_10 ) ;
}
return 0 ;
}
static int
F_85 ( struct V_9 * V_10 , struct V_144 * V_145 , int V_161 )
{
return - V_176 ;
}
static int F_86 ( struct V_9 * V_10 , T_7 V_177 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
int V_178 , V_36 = 0 ;
T_6 * V_179 ;
int V_180 , V_161 , V_162 , V_28 ;
V_178 = ( int ) ( V_177 >> V_145 -> V_181 ) ;
if ( V_145 -> V_182 )
V_145 -> V_182 [ V_178 >> 2 ] |= 0x01 << ( ( V_178 & 0x03 ) << 1 ) ;
if ( V_145 -> V_183 & V_184 )
V_36 = F_87 ( V_10 , V_177 ) ;
else {
V_28 = ( int ) ( V_177 >> V_145 -> V_185 ) ;
V_145 -> V_186 ( V_10 , V_28 ) ;
V_180 = V_4 -> V_25 ? V_10 -> V_19 : 0 ;
V_179 = V_4 -> V_41 ;
V_179 [ 0 ] = 0 ;
V_161 = ( int ) ( V_177 >> V_145 -> V_187 ) ;
V_145 -> V_172 ( V_10 , V_188 , V_180 , V_161 ) ;
V_145 -> V_189 ( V_10 , V_179 , 1 ) ;
V_145 -> V_172 ( V_10 , V_190 , - 1 , - 1 ) ;
V_162 = V_145 -> V_191 ( V_10 , V_145 ) ;
if ( V_162 & V_192 )
V_36 = - V_193 ;
V_145 -> V_186 ( V_10 , - 1 ) ;
}
if ( ! V_36 )
V_10 -> V_169 . V_194 ++ ;
return V_36 ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_195 * V_196 = & V_4 -> V_197 ;
V_196 -> V_198 = 64 ;
V_196 -> V_199 = 2 ;
return 0 ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_195 * V_200 = & V_4 -> V_197 ;
struct V_125 * V_40 = V_4 -> V_40 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_144 * V_145 = & V_4 -> V_201 ;
unsigned int V_202 ;
unsigned int V_203 ;
unsigned int V_161 ;
T_7 V_204 ;
T_6 * V_205 = V_145 -> V_206 -> V_207 ;
int V_208 ;
int V_209 = false ;
V_202 = 1 << V_200 -> V_199 ;
V_208 = V_4 -> V_29 ;
V_145 -> V_186 ( V_10 , 0 ) ;
F_90 ( V_40 , L_27 ) ;
for ( V_203 = 0 ; V_203 < V_202 ; V_203 ++ ) {
V_161 = V_203 * V_200 -> V_198 ;
V_204 = V_161 * V_10 -> V_19 ;
F_90 ( V_40 , L_28 , V_161 ) ;
V_145 -> V_172 ( V_10 , V_173 , 12 , V_161 ) ;
V_145 -> V_174 ( V_10 , V_205 , strlen ( V_210 ) ) ;
if ( ! memcmp ( V_205 , V_210 , strlen ( V_210 ) ) ) {
V_209 = true ;
break;
}
}
V_145 -> V_186 ( V_10 , V_208 ) ;
if ( V_209 )
F_90 ( V_40 , L_29 ) ;
else
F_90 ( V_40 , L_30 ) ;
return V_209 ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_125 * V_40 = V_4 -> V_40 ;
struct V_195 * V_200 = & V_4 -> V_197 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_144 * V_145 = & V_4 -> V_201 ;
unsigned int V_211 ;
unsigned int V_202 ;
unsigned int V_212 ;
unsigned int V_213 ;
unsigned int V_178 ;
unsigned int V_203 ;
unsigned int V_161 ;
T_7 V_204 ;
T_6 * V_205 = V_145 -> V_206 -> V_207 ;
int V_208 ;
int V_162 ;
V_211 = V_10 -> V_214 / V_10 -> V_19 ;
V_202 = 1 << V_200 -> V_199 ;
V_212 = V_202 *
V_200 -> V_198 ;
V_213 =
( V_212 + ( V_211 - 1 ) ) /
V_211 ;
F_90 ( V_40 , L_31 ) ;
F_90 ( V_40 , L_32 , V_213 ) ;
F_90 ( V_40 , L_33 , V_202 ) ;
F_90 ( V_40 , L_34 , V_212 ) ;
V_208 = V_4 -> V_29 ;
V_145 -> V_186 ( V_10 , 0 ) ;
F_90 ( V_40 , L_35 ) ;
for ( V_178 = 0 ; V_178 < V_213 ; V_178 ++ ) {
V_161 = V_178 * V_211 ;
F_90 ( V_40 , L_36 , V_178 ) ;
V_145 -> V_172 ( V_10 , V_215 , - 1 , V_161 ) ;
V_145 -> V_172 ( V_10 , V_216 , - 1 , - 1 ) ;
V_162 = V_145 -> V_191 ( V_10 , V_145 ) ;
if ( V_162 & V_192 )
F_92 ( V_40 , L_37 , V_217 ) ;
}
memset ( V_205 , ~ 0 , V_10 -> V_19 ) ;
memset ( V_145 -> V_170 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_205 + 12 , V_210 , strlen ( V_210 ) ) ;
F_90 ( V_40 , L_38 ) ;
for ( V_203 = 0 ; V_203 < V_202 ; V_203 ++ ) {
V_161 = V_203 * V_200 -> V_198 ;
V_204 = V_161 * V_10 -> V_19 ;
F_90 ( V_40 , L_39 , V_161 ) ;
V_145 -> V_172 ( V_10 , V_188 , 0x00 , V_161 ) ;
V_145 -> V_218 . V_219 ( V_10 , V_145 , V_205 , 0 ) ;
V_145 -> V_172 ( V_10 , V_190 , - 1 , - 1 ) ;
V_162 = V_145 -> V_191 ( V_10 , V_145 ) ;
if ( V_162 & V_192 )
F_92 ( V_40 , L_40 , V_217 ) ;
}
V_145 -> V_186 ( V_10 , V_208 ) ;
return 0 ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_125 * V_40 = V_4 -> V_40 ;
struct V_144 * V_145 = & V_4 -> V_201 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_220 ;
unsigned int V_178 ;
int V_28 ;
int V_161 ;
T_7 V_204 ;
T_6 V_179 ;
int V_36 = 0 ;
if ( F_89 ( V_4 ) )
return 0 ;
F_90 ( V_40 , L_41 ) ;
V_220 = V_145 -> V_221 >> V_145 -> V_222 ;
for ( V_178 = 0 ; V_178 < V_220 ; V_178 ++ ) {
V_28 = V_178 >> ( V_145 -> V_185 - V_145 -> V_222 ) ;
V_161 = V_178 << ( V_145 -> V_222 - V_145 -> V_187 ) ;
V_204 = V_178 << V_145 -> V_222 ;
V_145 -> V_186 ( V_10 , V_28 ) ;
V_145 -> V_172 ( V_10 , V_173 , V_10 -> V_19 , V_161 ) ;
V_179 = V_145 -> V_175 ( V_10 ) ;
V_145 -> V_186 ( V_10 , - 1 ) ;
if ( V_179 != 0xff ) {
F_90 ( V_40 , L_42 , V_178 ) ;
V_36 = V_145 -> V_223 ( V_10 , V_204 ) ;
if ( V_36 )
F_92 ( V_40 , L_43
L_44 , V_36 ) ;
}
}
F_91 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_3 * V_4 )
{
F_88 ( V_4 ) ;
if ( F_95 ( V_4 ) )
return F_93 ( V_4 ) ;
return 0 ;
}
static int F_96 ( struct V_3 * V_4 )
{
int V_36 ;
F_60 ( V_4 ) ;
V_36 = F_97 ( V_4 ) ;
if ( V_36 ) {
F_7 ( L_45 , V_36 ) ;
return V_36 ;
}
return F_63 ( V_4 ) ;
}
static int F_98 ( struct V_3 * V_4 )
{
int V_36 ;
if ( F_95 ( V_4 ) )
V_4 -> V_25 = false ;
else
V_4 -> V_25 = true ;
V_36 = F_96 ( V_4 ) ;
if ( V_36 )
return V_36 ;
V_4 -> V_201 . V_218 . V_224 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_11 = V_4 -> V_7 . V_11 ;
return F_94 ( V_4 ) ;
}
static int F_99 ( struct V_9 * V_10 )
{
struct V_144 * V_145 = V_10 -> V_146 ;
struct V_3 * V_4 = V_145 -> V_146 ;
int V_36 ;
V_36 = F_98 ( V_4 ) ;
if ( V_36 )
return V_36 ;
return F_100 ( V_10 ) ;
}
void F_101 ( struct V_3 * V_4 )
{
F_102 ( & V_4 -> V_10 ) ;
F_60 ( V_4 ) ;
}
static int T_2 F_103 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_144 * V_145 = & V_4 -> V_201 ;
struct V_225 V_226 = {} ;
int V_36 ;
V_4 -> V_29 = - 1 ;
V_10 -> V_146 = V_145 ;
V_10 -> V_227 = L_46 ;
V_10 -> V_228 = V_229 ;
V_145 -> V_146 = V_4 ;
V_145 -> V_186 = F_70 ;
V_145 -> V_230 = F_66 ;
V_145 -> V_231 = F_68 ;
V_145 -> V_175 = F_78 ;
V_145 -> V_174 = F_73 ;
V_145 -> V_189 = F_76 ;
V_145 -> V_218 . V_232 = F_80 ;
V_145 -> V_218 . V_233 = F_82 ;
V_145 -> V_218 . V_234 = F_84 ;
V_145 -> V_218 . V_235 = F_85 ;
V_145 -> V_236 = F_99 ;
V_145 -> V_237 = & V_238 ;
V_145 -> V_223 = F_86 ;
V_145 -> V_239 |= V_240 ;
V_145 -> V_218 . V_241 = V_242 ;
V_145 -> V_218 . V_243 = 1 ;
V_145 -> V_218 . V_224 = 8 ;
V_145 -> V_218 . V_244 = & V_245 ;
V_4 -> V_7 . V_22 = 1024 ;
V_4 -> V_7 . V_23 = 128 ;
V_36 = F_63 ( V_4 ) ;
if ( V_36 )
goto V_246;
V_36 = F_104 ( V_10 , 1 ) ;
if ( V_36 ) {
F_7 ( L_47 ) ;
goto V_246;
}
V_226 . V_97 = V_4 -> V_66 -> V_40 . V_97 ;
V_36 = F_105 ( V_10 , NULL , & V_226 , NULL , 0 ) ;
if ( V_36 )
goto V_246;
return 0 ;
V_246:
F_101 ( V_4 ) ;
return V_36 ;
}
static int T_2 F_106 ( struct V_65 * V_66 )
{
struct V_3 * V_4 ;
const struct V_247 * V_248 ;
int V_36 ;
V_248 = F_107 ( V_249 , & V_66 -> V_40 ) ;
if ( V_248 ) {
V_66 -> V_250 = V_248 -> V_142 ;
} else {
F_7 ( L_48 ) ;
return - V_75 ;
}
V_4 = F_64 ( sizeof( * V_4 ) , V_251 ) ;
if ( ! V_4 ) {
F_7 ( L_49 ) ;
return - V_75 ;
}
F_108 ( V_66 , V_4 ) ;
V_4 -> V_66 = V_66 ;
V_4 -> V_40 = & V_66 -> V_40 ;
V_36 = F_42 ( V_4 ) ;
if ( V_36 )
goto V_252;
V_36 = F_49 ( V_4 ) ;
if ( V_36 )
goto V_253;
V_36 = F_103 ( V_4 ) ;
if ( V_36 )
goto V_253;
return 0 ;
V_253:
F_47 ( V_4 ) ;
V_252:
F_108 ( V_66 , NULL ) ;
F_62 ( V_4 ) ;
return V_36 ;
}
static int T_8 F_109 ( struct V_65 * V_66 )
{
struct V_3 * V_4 = F_110 ( V_66 ) ;
F_101 ( V_4 ) ;
F_47 ( V_4 ) ;
F_108 ( V_66 , NULL ) ;
F_62 ( V_4 ) ;
return 0 ;
}
static int T_9 F_111 ( void )
{
int V_58 ;
V_58 = F_112 ( & V_254 ) ;
if ( V_58 == 0 )
F_113 ( V_255 L_50 ) ;
else
F_7 ( L_51 ) ;
return V_58 ;
}
static void T_8 F_114 ( void )
{
F_115 ( & V_254 ) ;
}
