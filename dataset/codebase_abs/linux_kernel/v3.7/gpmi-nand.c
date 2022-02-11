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
void T_3 * V_71 ;
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
F_29 ( struct V_3 * V_4 , T_4 V_80 )
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
T_5 V_88 ;
int V_36 ;
struct V_27 * V_27 ;
T_6 V_96 ;
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
static void F_42 ( struct V_3 * V_4 )
{
struct V_67 * V_70 = & V_4 -> V_67 ;
struct V_102 * V_102 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_103 ; V_86 ++ ) {
V_102 = V_70 -> clock [ V_86 ] ;
if ( V_102 ) {
F_43 ( V_102 ) ;
V_70 -> clock [ V_86 ] = NULL ;
}
}
}
static int T_2 F_44 ( struct V_3 * V_4 )
{
struct V_67 * V_70 = & V_4 -> V_67 ;
char * * V_104 = NULL ;
struct V_102 * V_102 ;
int V_86 ;
V_70 -> clock [ 0 ] = F_45 ( V_4 -> V_40 , L_14 ) ;
if ( F_46 ( V_70 -> clock [ 0 ] ) )
goto V_105;
if ( F_47 ( V_4 ) )
V_104 = V_106 ;
if ( ! V_104 )
return 0 ;
for ( V_86 = 1 ; V_86 < V_103 ; V_86 ++ ) {
if ( V_104 [ V_86 - 1 ] == NULL )
break;
V_102 = F_45 ( V_4 -> V_40 , V_104 [ V_86 - 1 ] ) ;
if ( F_46 ( V_102 ) )
goto V_105;
V_70 -> clock [ V_86 ] = V_102 ;
}
if ( F_47 ( V_4 ) )
F_48 ( V_70 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_105:
F_49 ( V_4 -> V_40 , L_15 ) ;
F_42 ( V_4 ) ;
return - V_75 ;
}
static int T_2 F_50 ( struct V_3 * V_4 )
{
struct V_107 * V_107 ;
int V_36 ;
V_36 = F_23 ( V_4 , V_76 ) ;
if ( V_36 )
goto V_108;
V_36 = F_23 ( V_4 , V_78 ) ;
if ( V_36 )
goto V_108;
V_36 = F_29 ( V_4 , F_1 ) ;
if ( V_36 )
goto V_108;
V_36 = F_37 ( V_4 ) ;
if ( V_36 )
goto V_109;
V_107 = F_51 ( & V_4 -> V_66 -> V_40 ) ;
if ( F_46 ( V_107 ) ) {
V_36 = F_52 ( V_107 ) ;
goto V_110;
}
V_36 = F_44 ( V_4 ) ;
if ( V_36 )
goto V_111;
return 0 ;
V_111:
V_110:
F_35 ( V_4 ) ;
V_109:
F_31 ( V_4 ) ;
V_108:
F_27 ( V_4 ) ;
return V_36 ;
}
static void F_53 ( struct V_3 * V_4 )
{
F_42 ( V_4 ) ;
F_27 ( V_4 ) ;
F_31 ( V_4 ) ;
F_35 ( V_4 ) ;
}
static int T_2 F_54 ( struct V_3 * V_4 )
{
int V_36 ;
struct V_112 V_113 = {
. V_114 = 80 ,
. V_115 = 60 ,
. V_116 = 25 ,
. V_117 = 6 ,
. V_118 = - 1 ,
. V_119 = - 1 ,
. V_120 = - 1 ,
} ;
V_36 = F_55 ( V_4 ) ;
if ( V_36 )
return V_36 ;
V_4 -> V_121 = V_113 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
void * V_122 , unsigned V_123 ,
void * V_124 , T_7 V_125 , unsigned V_126 ,
void * * V_127 , T_7 * V_128 )
{
struct V_129 * V_40 = V_4 -> V_40 ;
if ( F_57 ( V_122 ) ) {
T_7 V_130 ;
V_130 = F_58 ( V_40 , V_122 ,
V_123 , V_52 ) ;
if ( F_59 ( V_40 , V_130 ) ) {
if ( V_126 < V_123 ) {
F_7 ( L_16 ) ;
return - V_75 ;
}
goto V_131;
}
* V_127 = V_122 ;
* V_128 = V_130 ;
V_4 -> V_37 = true ;
return 0 ;
}
V_131:
* V_127 = V_124 ;
* V_128 = V_125 ;
V_4 -> V_37 = false ;
return 0 ;
}
static inline void F_60 ( struct V_3 * V_4 ,
void * V_122 , unsigned V_123 ,
void * V_124 , T_7 V_125 , unsigned V_126 ,
void * V_132 , T_7 V_133 )
{
if ( V_4 -> V_37 )
F_61 ( V_4 -> V_40 , V_133 , V_123 , V_52 ) ;
}
static inline void F_62 ( struct V_3 * V_4 ,
void * V_122 , unsigned V_123 ,
void * V_124 , T_7 V_125 , unsigned V_126 ,
void * V_132 , T_7 V_133 )
{
if ( ! V_4 -> V_37 )
memcpy ( V_122 , V_124 , V_123 ) ;
}
static int F_63 ( struct V_3 * V_4 ,
const void * V_134 , unsigned V_123 ,
void * V_124 , T_7 V_125 , unsigned V_126 ,
const void * * V_127 , T_7 * V_128 )
{
struct V_129 * V_40 = V_4 -> V_40 ;
if ( F_57 ( V_134 ) ) {
T_7 V_135 ;
V_135 = F_58 ( V_40 , ( void * ) V_134 , V_123 ,
V_43 ) ;
if ( F_59 ( V_40 , V_135 ) ) {
if ( V_126 < V_123 ) {
F_7 ( L_16 ) ;
return - V_75 ;
}
goto V_131;
}
* V_127 = V_134 ;
* V_128 = V_135 ;
return 0 ;
}
V_131:
memcpy ( V_124 , V_134 , V_123 ) ;
* V_127 = V_124 ;
* V_128 = V_125 ;
return 0 ;
}
static void F_64 ( struct V_3 * V_4 ,
const void * V_134 , unsigned V_123 ,
void * V_124 , T_7 V_125 , unsigned V_126 ,
const void * V_132 , T_7 V_133 )
{
struct V_129 * V_40 = V_4 -> V_40 ;
if ( V_132 == V_134 )
F_61 ( V_40 , V_133 , V_123 , V_43 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_129 * V_40 = V_4 -> V_40 ;
if ( V_4 -> V_136 && F_57 ( V_4 -> V_136 ) )
F_66 ( V_40 , V_4 -> V_137 ,
V_4 -> V_136 ,
V_4 -> V_138 ) ;
F_67 ( V_4 -> V_139 ) ;
F_67 ( V_4 -> V_41 ) ;
V_4 -> V_139 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_136 = NULL ;
V_4 -> V_137 = 0 ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_129 * V_40 = V_4 -> V_40 ;
V_4 -> V_139 = F_69 ( V_42 , V_140 | V_141 ) ;
if ( V_4 -> V_139 == NULL )
goto V_142;
V_4 -> V_41 = F_69 ( V_42 , V_140 | V_141 ) ;
if ( V_4 -> V_41 == NULL )
goto V_142;
V_4 -> V_137 = V_8 -> V_22 + V_8 -> V_23 ;
V_4 -> V_136 = F_70 ( V_40 , V_4 -> V_137 ,
& V_4 -> V_138 , V_140 ) ;
if ( ! V_4 -> V_136 )
goto V_142;
V_4 -> V_143 = V_4 -> V_136 ;
V_4 -> V_144 = V_4 -> V_138 ;
V_4 -> V_145 = V_4 -> V_143 + V_8 -> V_22 ;
V_4 -> V_146 = V_4 -> V_144 + V_8 -> V_22 ;
return 0 ;
V_142:
F_65 ( V_4 ) ;
F_7 ( L_17 ) ;
return - V_75 ;
}
static void F_71 ( struct V_9 * V_10 , int V_147 , unsigned int V_148 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
int V_36 ;
if ( ( V_148 & ( V_152 | V_153 ) ) ) {
if ( V_147 != V_154 )
V_4 -> V_139 [ V_4 -> V_155 ++ ] = V_147 ;
return;
}
if ( ! V_4 -> V_155 )
return;
V_36 = F_72 ( V_4 ) ;
if ( V_36 )
F_7 ( L_18 , V_4 -> V_29 , V_36 ) ;
V_4 -> V_155 = 0 ;
}
static int F_73 ( struct V_9 * V_10 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
return F_74 ( V_4 , V_4 -> V_29 ) ;
}
static void F_75 ( struct V_9 * V_10 , int V_28 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
if ( ( V_4 -> V_29 < 0 ) && ( V_28 >= 0 ) )
F_76 ( V_4 ) ;
else if ( ( V_4 -> V_29 >= 0 ) && ( V_28 < 0 ) )
F_77 ( V_4 ) ;
V_4 -> V_29 = V_28 ;
}
static void F_78 ( struct V_9 * V_10 , T_8 * V_156 , int V_157 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
F_79 ( L_19 , V_157 ) ;
V_4 -> V_38 = V_156 ;
V_4 -> V_39 = V_157 ;
F_80 ( V_4 ) ;
}
static void F_81 ( struct V_9 * V_10 , const T_8 * V_156 , int V_157 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
F_79 ( L_19 , V_157 ) ;
V_4 -> V_38 = ( T_8 * ) V_156 ;
V_4 -> V_39 = V_157 ;
F_82 ( V_4 ) ;
}
static T_8 F_83 ( struct V_9 * V_10 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
T_8 * V_156 = V_4 -> V_41 ;
F_78 ( V_10 , V_156 , 1 ) ;
return V_156 [ 0 ] ;
}
static void F_84 ( struct V_3 * V_4 ,
void * V_158 , void * V_159 )
{
struct V_7 * V_160 = & V_4 -> V_7 ;
unsigned char * V_71 ;
unsigned char * V_161 ;
unsigned int V_162 ;
unsigned char V_96 ;
unsigned char V_163 ;
unsigned char V_164 ;
if ( ! V_4 -> V_25 )
return;
V_162 = V_160 -> V_17 ;
V_71 = V_158 + V_160 -> V_26 ;
V_161 = V_159 ;
V_163 = ( V_71 [ 0 ] >> V_162 ) | ( V_71 [ 1 ] << ( 8 - V_162 ) ) ;
V_164 = V_161 [ 0 ] ;
V_161 [ 0 ] = V_163 ;
V_96 = ( 0x1 << V_162 ) - 1 ;
V_71 [ 0 ] = ( V_71 [ 0 ] & V_96 ) | ( V_164 << V_162 ) ;
V_96 = ~ 0 << V_162 ;
V_71 [ 1 ] = ( V_71 [ 1 ] & V_96 ) | ( V_164 >> ( 8 - V_162 ) ) ;
}
static int F_85 ( struct V_9 * V_10 , struct V_149 * V_150 ,
T_8 * V_156 , int V_165 , int V_166 )
{
struct V_3 * V_4 = V_150 -> V_151 ;
struct V_7 * V_160 = & V_4 -> V_7 ;
void * V_143 ;
T_7 V_144 ;
void * V_145 ;
T_7 V_146 ;
unsigned int V_86 ;
unsigned char * V_167 ;
unsigned int V_168 ;
unsigned int V_169 ;
int V_36 ;
F_79 ( L_20 , V_166 ) ;
V_36 = F_56 ( V_4 , V_156 , V_10 -> V_19 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_160 -> V_22 ,
& V_143 , & V_144 ) ;
if ( V_36 ) {
F_7 ( L_21 ) ;
V_36 = - V_75 ;
return V_36 ;
}
V_145 = V_4 -> V_145 ;
V_146 = V_4 -> V_146 ;
V_36 = F_86 ( V_4 , V_144 , V_146 ) ;
F_60 ( V_4 , V_156 , V_10 -> V_19 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_160 -> V_22 ,
V_143 , V_144 ) ;
if ( V_36 ) {
F_7 ( L_22 , V_36 ) ;
goto V_170;
}
F_84 ( V_4 , V_143 , V_145 ) ;
V_168 = 0 ;
V_169 = 0 ;
V_167 = V_145 + V_160 -> V_24 ;
for ( V_86 = 0 ; V_86 < V_160 -> V_15 ; V_86 ++ , V_167 ++ ) {
if ( ( * V_167 == V_171 ) || ( * V_167 == V_172 ) )
continue;
if ( * V_167 == V_173 ) {
V_168 ++ ;
continue;
}
V_169 += * V_167 ;
}
if ( V_168 || V_169 >= ( V_160 -> V_11 - 1 ) ) {
V_10 -> V_174 . V_168 += V_168 ;
V_10 -> V_174 . V_169 += V_169 ;
}
if ( V_165 ) {
memset ( V_150 -> V_175 , ~ 0 , V_10 -> V_12 ) ;
V_150 -> V_175 [ 0 ] = ( ( T_8 * ) V_145 ) [ 0 ] ;
}
F_62 ( V_4 , V_156 , V_10 -> V_19 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_160 -> V_22 ,
V_143 , V_144 ) ;
V_170:
return V_36 ;
}
static int F_87 ( struct V_9 * V_10 , struct V_149 * V_150 ,
const T_8 * V_156 , int V_165 )
{
struct V_3 * V_4 = V_150 -> V_151 ;
struct V_7 * V_160 = & V_4 -> V_7 ;
const void * V_143 ;
T_7 V_144 ;
const void * V_145 ;
T_7 V_146 ;
int V_36 ;
F_79 ( L_23 ) ;
if ( V_4 -> V_25 ) {
memcpy ( V_4 -> V_143 , V_156 , V_10 -> V_19 ) ;
V_143 = V_4 -> V_143 ;
V_144 = V_4 -> V_144 ;
memcpy ( V_4 -> V_145 , V_150 -> V_175 ,
V_160 -> V_23 ) ;
V_145 = V_4 -> V_145 ;
V_146 = V_4 -> V_146 ;
F_84 ( V_4 ,
( void * ) V_143 , ( void * ) V_145 ) ;
} else {
V_36 = F_63 ( V_4 ,
V_156 , V_10 -> V_19 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_160 -> V_22 ,
& V_143 , & V_144 ) ;
if ( V_36 ) {
F_7 ( L_24 ) ;
return 0 ;
}
V_36 = F_63 ( V_4 ,
V_150 -> V_175 , V_10 -> V_12 ,
V_4 -> V_145 , V_4 -> V_146 ,
V_160 -> V_23 ,
& V_145 , & V_146 ) ;
if ( V_36 ) {
F_7 ( L_25 ) ;
goto V_176;
}
}
V_36 = F_88 ( V_4 , V_144 , V_146 ) ;
if ( V_36 )
F_7 ( L_26 , V_36 ) ;
if ( ! V_4 -> V_25 ) {
F_64 ( V_4 , V_150 -> V_175 , V_10 -> V_12 ,
V_4 -> V_145 , V_4 -> V_146 ,
V_160 -> V_23 ,
V_145 , V_146 ) ;
V_176:
F_64 ( V_4 , V_156 , V_10 -> V_19 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_160 -> V_22 ,
V_143 , V_144 ) ;
}
return 0 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_149 * V_150 ,
int V_166 )
{
struct V_3 * V_4 = V_150 -> V_151 ;
F_79 ( L_27 , V_166 ) ;
memset ( V_150 -> V_175 , ~ 0 , V_10 -> V_12 ) ;
V_150 -> V_177 ( V_10 , V_178 , V_10 -> V_19 , V_166 ) ;
V_150 -> V_179 ( V_10 , V_150 -> V_175 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_25 ) {
V_150 -> V_177 ( V_10 , V_178 , 0 , V_166 ) ;
V_150 -> V_175 [ 0 ] = V_150 -> V_180 ( V_10 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_9 * V_10 , struct V_149 * V_150 , int V_166 )
{
return - V_181 ;
}
static int F_91 ( struct V_9 * V_10 , T_9 V_182 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
int V_183 , V_36 = 0 ;
T_8 * V_184 ;
int V_185 , V_166 , V_167 , V_28 ;
V_183 = ( int ) ( V_182 >> V_150 -> V_186 ) ;
if ( V_150 -> V_187 )
V_150 -> V_187 [ V_183 >> 2 ] |= 0x01 << ( ( V_183 & 0x03 ) << 1 ) ;
if ( V_150 -> V_188 & V_189 )
V_36 = F_92 ( V_10 , V_182 ) ;
else {
V_28 = ( int ) ( V_182 >> V_150 -> V_190 ) ;
V_150 -> V_191 ( V_10 , V_28 ) ;
V_185 = V_4 -> V_25 ? V_10 -> V_19 : 0 ;
V_184 = V_4 -> V_41 ;
V_184 [ 0 ] = 0 ;
V_166 = ( int ) ( V_182 >> V_150 -> V_192 ) ;
V_150 -> V_177 ( V_10 , V_193 , V_185 , V_166 ) ;
V_150 -> V_194 ( V_10 , V_184 , 1 ) ;
V_150 -> V_177 ( V_10 , V_195 , - 1 , - 1 ) ;
V_167 = V_150 -> V_196 ( V_10 , V_150 ) ;
if ( V_167 & V_197 )
V_36 = - V_198 ;
V_150 -> V_191 ( V_10 , - 1 ) ;
}
if ( ! V_36 )
V_10 -> V_174 . V_199 ++ ;
return V_36 ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_200 * V_201 = & V_4 -> V_202 ;
V_201 -> V_203 = 64 ;
V_201 -> V_204 = 2 ;
return 0 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_200 * V_205 = & V_4 -> V_202 ;
struct V_129 * V_40 = V_4 -> V_40 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_149 * V_150 = & V_4 -> V_206 ;
unsigned int V_207 ;
unsigned int V_208 ;
unsigned int V_166 ;
T_8 * V_209 = V_150 -> V_210 -> V_211 ;
int V_212 ;
int V_213 = false ;
V_207 = 1 << V_205 -> V_204 ;
V_212 = V_4 -> V_29 ;
V_150 -> V_191 ( V_10 , 0 ) ;
F_49 ( V_40 , L_28 ) ;
for ( V_208 = 0 ; V_208 < V_207 ; V_208 ++ ) {
V_166 = V_208 * V_205 -> V_203 ;
F_49 ( V_40 , L_29 , V_166 ) ;
V_150 -> V_177 ( V_10 , V_178 , 12 , V_166 ) ;
V_150 -> V_179 ( V_10 , V_209 , strlen ( V_214 ) ) ;
if ( ! memcmp ( V_209 , V_214 , strlen ( V_214 ) ) ) {
V_213 = true ;
break;
}
}
V_150 -> V_191 ( V_10 , V_212 ) ;
if ( V_213 )
F_49 ( V_40 , L_30 ) ;
else
F_49 ( V_40 , L_31 ) ;
return V_213 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_129 * V_40 = V_4 -> V_40 ;
struct V_200 * V_205 = & V_4 -> V_202 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_149 * V_150 = & V_4 -> V_206 ;
unsigned int V_215 ;
unsigned int V_207 ;
unsigned int V_216 ;
unsigned int V_217 ;
unsigned int V_183 ;
unsigned int V_208 ;
unsigned int V_166 ;
T_8 * V_209 = V_150 -> V_210 -> V_211 ;
int V_212 ;
int V_167 ;
V_215 = V_10 -> V_218 / V_10 -> V_19 ;
V_207 = 1 << V_205 -> V_204 ;
V_216 = V_207 *
V_205 -> V_203 ;
V_217 =
( V_216 + ( V_215 - 1 ) ) /
V_215 ;
F_49 ( V_40 , L_32 ) ;
F_49 ( V_40 , L_33 , V_217 ) ;
F_49 ( V_40 , L_34 , V_207 ) ;
F_49 ( V_40 , L_35 , V_216 ) ;
V_212 = V_4 -> V_29 ;
V_150 -> V_191 ( V_10 , 0 ) ;
F_49 ( V_40 , L_36 ) ;
for ( V_183 = 0 ; V_183 < V_217 ; V_183 ++ ) {
V_166 = V_183 * V_215 ;
F_49 ( V_40 , L_37 , V_183 ) ;
V_150 -> V_177 ( V_10 , V_219 , - 1 , V_166 ) ;
V_150 -> V_177 ( V_10 , V_220 , - 1 , - 1 ) ;
V_167 = V_150 -> V_196 ( V_10 , V_150 ) ;
if ( V_167 & V_197 )
F_96 ( V_40 , L_38 , V_221 ) ;
}
memset ( V_209 , ~ 0 , V_10 -> V_19 ) ;
memset ( V_150 -> V_175 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_209 + 12 , V_214 , strlen ( V_214 ) ) ;
F_49 ( V_40 , L_39 ) ;
for ( V_208 = 0 ; V_208 < V_207 ; V_208 ++ ) {
V_166 = V_208 * V_205 -> V_203 ;
F_49 ( V_40 , L_40 , V_166 ) ;
V_150 -> V_177 ( V_10 , V_193 , 0x00 , V_166 ) ;
V_150 -> V_222 . V_223 ( V_10 , V_150 , V_209 , 0 ) ;
V_150 -> V_177 ( V_10 , V_195 , - 1 , - 1 ) ;
V_167 = V_150 -> V_196 ( V_10 , V_150 ) ;
if ( V_167 & V_197 )
F_96 ( V_40 , L_41 , V_221 ) ;
}
V_150 -> V_191 ( V_10 , V_212 ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_129 * V_40 = V_4 -> V_40 ;
struct V_149 * V_150 = & V_4 -> V_206 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_224 ;
unsigned int V_183 ;
int V_28 ;
int V_166 ;
T_9 V_225 ;
T_8 V_184 ;
int V_36 = 0 ;
if ( F_94 ( V_4 ) )
return 0 ;
F_49 ( V_40 , L_42 ) ;
V_224 = V_150 -> V_226 >> V_150 -> V_227 ;
for ( V_183 = 0 ; V_183 < V_224 ; V_183 ++ ) {
V_28 = V_183 >> ( V_150 -> V_190 - V_150 -> V_227 ) ;
V_166 = V_183 << ( V_150 -> V_227 - V_150 -> V_192 ) ;
V_225 = V_183 << V_150 -> V_227 ;
V_150 -> V_191 ( V_10 , V_28 ) ;
V_150 -> V_177 ( V_10 , V_178 , V_10 -> V_19 , V_166 ) ;
V_184 = V_150 -> V_180 ( V_10 ) ;
V_150 -> V_191 ( V_10 , - 1 ) ;
if ( V_184 != 0xff ) {
F_49 ( V_40 , L_43 , V_183 ) ;
V_36 = V_150 -> V_228 ( V_10 , V_225 ) ;
if ( V_36 )
F_96 ( V_40 , L_44
L_45 , V_36 ) ;
}
}
F_95 ( V_4 ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
F_93 ( V_4 ) ;
if ( F_99 ( V_4 ) )
return F_97 ( V_4 ) ;
return 0 ;
}
static int F_100 ( struct V_3 * V_4 )
{
int V_36 ;
F_65 ( V_4 ) ;
V_36 = F_101 ( V_4 ) ;
if ( V_36 ) {
F_7 ( L_46 , V_36 ) ;
return V_36 ;
}
return F_68 ( V_4 ) ;
}
static int F_102 ( struct V_3 * V_4 )
{
int V_36 ;
if ( F_99 ( V_4 ) )
V_4 -> V_25 = false ;
else
V_4 -> V_25 = true ;
V_36 = F_100 ( V_4 ) ;
if ( V_36 )
return V_36 ;
V_4 -> V_206 . V_222 . V_229 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_11 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_230 = V_4 -> V_7 . V_11 ;
return F_98 ( V_4 ) ;
}
static int F_103 ( struct V_9 * V_10 )
{
struct V_149 * V_150 = V_10 -> V_151 ;
struct V_3 * V_4 = V_150 -> V_151 ;
int V_36 ;
V_36 = F_102 ( V_4 ) ;
if ( V_36 )
return V_36 ;
F_104 ( V_4 ) ;
return F_105 ( V_10 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
F_107 ( & V_4 -> V_10 ) ;
F_65 ( V_4 ) ;
}
static int T_2 F_108 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_149 * V_150 = & V_4 -> V_206 ;
struct V_231 V_232 = {} ;
int V_36 ;
V_4 -> V_29 = - 1 ;
V_10 -> V_151 = V_150 ;
V_10 -> V_233 = L_47 ;
V_10 -> V_234 = V_235 ;
V_150 -> V_151 = V_4 ;
V_150 -> V_191 = F_75 ;
V_150 -> V_236 = F_71 ;
V_150 -> V_237 = F_73 ;
V_150 -> V_180 = F_83 ;
V_150 -> V_179 = F_78 ;
V_150 -> V_194 = F_81 ;
V_150 -> V_222 . V_238 = F_85 ;
V_150 -> V_222 . V_239 = F_87 ;
V_150 -> V_222 . V_240 = F_89 ;
V_150 -> V_222 . V_241 = F_90 ;
V_150 -> V_242 = F_103 ;
V_150 -> V_243 = & V_244 ;
V_150 -> V_228 = F_91 ;
V_150 -> V_245 |= V_246 ;
V_150 -> V_222 . V_247 = V_248 ;
V_150 -> V_222 . V_249 = 1 ;
V_150 -> V_222 . V_229 = 8 ;
V_150 -> V_222 . V_250 = & V_251 ;
if ( F_109 ( V_4 -> V_40 -> V_97 ) )
V_150 -> V_188 |= V_189 | V_252 ;
V_4 -> V_7 . V_22 = 1024 ;
V_4 -> V_7 . V_23 = 128 ;
V_36 = F_68 ( V_4 ) ;
if ( V_36 )
goto V_253;
V_36 = F_110 ( V_10 , 1 ) ;
if ( V_36 ) {
F_7 ( L_48 ) ;
goto V_253;
}
V_232 . V_97 = V_4 -> V_66 -> V_40 . V_97 ;
V_36 = F_111 ( V_10 , NULL , & V_232 , NULL , 0 ) ;
if ( V_36 )
goto V_253;
return 0 ;
V_253:
F_106 ( V_4 ) ;
return V_36 ;
}
static int T_2 F_112 ( struct V_65 * V_66 )
{
struct V_3 * V_4 ;
const struct V_254 * V_255 ;
int V_36 ;
V_255 = F_113 ( V_256 , & V_66 -> V_40 ) ;
if ( V_255 ) {
V_66 -> V_257 = V_255 -> V_147 ;
} else {
F_7 ( L_49 ) ;
return - V_75 ;
}
V_4 = F_69 ( sizeof( * V_4 ) , V_141 ) ;
if ( ! V_4 ) {
F_7 ( L_50 ) ;
return - V_75 ;
}
F_114 ( V_66 , V_4 ) ;
V_4 -> V_66 = V_66 ;
V_4 -> V_40 = & V_66 -> V_40 ;
V_36 = F_50 ( V_4 ) ;
if ( V_36 )
goto V_258;
V_36 = F_54 ( V_4 ) ;
if ( V_36 )
goto V_259;
V_36 = F_108 ( V_4 ) ;
if ( V_36 )
goto V_259;
F_115 ( V_4 -> V_40 , L_51 ) ;
return 0 ;
V_259:
F_53 ( V_4 ) ;
V_258:
F_114 ( V_66 , NULL ) ;
F_67 ( V_4 ) ;
F_96 ( V_4 -> V_40 , L_52 , V_36 ) ;
return V_36 ;
}
static int T_10 F_116 ( struct V_65 * V_66 )
{
struct V_3 * V_4 = F_117 ( V_66 ) ;
F_106 ( V_4 ) ;
F_53 ( V_4 ) ;
F_114 ( V_66 , NULL ) ;
F_67 ( V_4 ) ;
return 0 ;
}
