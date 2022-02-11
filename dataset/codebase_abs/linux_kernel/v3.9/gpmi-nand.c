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
static inline bool F_6 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
if ( F_7 ( V_4 ) || F_8 ( V_4 ) ) {
if ( V_8 -> V_14 == 14 )
return false ;
if ( V_8 -> V_11 > V_16 )
return false ;
} else if ( F_9 ( V_4 ) ) {
if ( V_8 -> V_11 > V_17 )
return false ;
}
return true ;
}
int F_10 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_13 ;
unsigned int V_18 ;
unsigned int V_19 ;
V_8 -> V_13 = 10 ;
V_8 -> V_14 = 13 ;
V_8 -> V_20 = 512 ;
while ( V_8 -> V_20 < V_10 -> V_12 ) {
V_8 -> V_20 *= 2 ;
V_8 -> V_14 = 14 ;
}
V_8 -> V_15 = V_10 -> V_21 / V_8 -> V_20 ;
V_8 -> V_11 = F_4 ( V_4 ) ;
if ( ! F_6 ( V_4 ) ) {
F_11 ( V_4 -> V_22 ,
L_1
L_2
L_3 , V_8 -> V_11 ,
( F_9 ( V_4 ) ? V_17
: V_16 ) ) ;
return - V_23 ;
}
V_8 -> V_24 = V_10 -> V_21 + V_10 -> V_12 ;
V_8 -> V_25 = V_10 -> V_21 ;
V_13 = F_12 ( V_8 -> V_13 , 4 ) ;
V_18 = F_12 ( V_8 -> V_15 , 4 ) ;
V_8 -> V_26 = V_13 + V_18 ;
V_8 -> V_27 = V_13 ;
if ( ! V_4 -> V_28 )
return 0 ;
V_19 = V_10 -> V_21 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_29 = V_19 / 8 ;
V_8 -> V_19 = V_19 % 8 ;
return 0 ;
}
struct V_30 * F_13 ( struct V_3 * V_4 )
{
int V_31 = V_4 -> V_32 ;
return V_4 -> V_33 [ V_31 ] ;
}
void F_14 ( struct V_3 * V_4 , enum V_34 V_35 )
{
struct V_36 * V_37 = & V_4 -> V_38 ;
int V_39 ;
V_4 -> V_40 = true ;
F_15 ( V_37 , V_4 -> V_41 , V_4 -> V_42 ) ;
V_39 = F_16 ( V_4 -> V_22 , V_37 , 1 , V_35 ) ;
if ( V_39 == 0 ) {
F_15 ( V_37 , V_4 -> V_43 , V_44 ) ;
if ( V_35 == V_45 )
memcpy ( V_4 -> V_43 , V_4 -> V_41 ,
V_4 -> V_42 ) ;
V_39 = F_16 ( V_4 -> V_22 , V_37 , 1 , V_35 ) ;
if ( V_39 == 0 )
F_17 ( L_4 ) ;
V_4 -> V_40 = false ;
}
}
static void F_18 ( void * V_46 )
{
struct V_3 * V_4 = V_46 ;
struct V_47 * V_48 = & V_4 -> V_49 ;
F_3 ( V_48 ) ;
switch ( V_4 -> V_50 ) {
case V_51 :
F_19 ( V_4 -> V_22 , & V_4 -> V_52 , 1 , V_45 ) ;
break;
case V_53 :
F_19 ( V_4 -> V_22 , & V_4 -> V_38 , 1 , V_54 ) ;
if ( V_4 -> V_40 == false )
memcpy ( V_4 -> V_41 , V_4 -> V_43 ,
V_4 -> V_42 ) ;
break;
case V_55 :
F_19 ( V_4 -> V_22 , & V_4 -> V_38 , 1 , V_45 ) ;
break;
case V_56 :
case V_57 :
break;
default:
F_17 ( L_5 ) ;
}
}
int F_20 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
struct V_47 * V_48 = & V_4 -> V_49 ;
int V_60 ;
F_21 ( V_48 ) ;
V_59 -> V_61 = F_18 ;
V_59 -> V_62 = V_4 ;
F_22 ( V_59 ) ;
F_23 ( F_13 ( V_4 ) ) ;
V_60 = F_24 ( V_48 , F_25 ( 1000 ) ) ;
if ( ! V_60 ) {
F_17 ( L_6 , V_4 -> V_63 ) ;
F_26 ( V_4 ) ;
return - V_64 ;
}
return 0 ;
}
int F_27 ( struct V_3 * V_4 ,
struct V_58 * V_59 )
{
struct V_47 * V_65 = & V_4 -> V_5 ;
int V_60 ;
F_21 ( V_65 ) ;
F_20 ( V_4 , V_59 ) ;
V_60 = F_24 ( V_65 , F_25 ( 1000 ) ) ;
if ( ! V_60 ) {
F_17 ( L_7 , V_4 -> V_63 ) ;
F_26 ( V_4 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
const char * V_66 )
{
struct V_67 * V_68 = V_4 -> V_68 ;
struct V_69 * V_70 = & V_4 -> V_69 ;
struct V_71 * V_72 ;
void T_2 * V_73 ;
V_72 = F_29 ( V_68 , V_74 , V_66 ) ;
if ( ! V_72 ) {
F_17 ( L_8 , V_66 ) ;
return - V_75 ;
}
V_73 = F_30 ( V_72 -> V_76 , F_31 ( V_72 ) ) ;
if ( ! V_73 ) {
F_17 ( L_9 , V_66 ) ;
return - V_77 ;
}
if ( ! strcmp ( V_66 , V_78 ) )
V_70 -> V_79 = V_73 ;
else if ( ! strcmp ( V_66 , V_80 ) )
V_70 -> V_81 = V_73 ;
else
F_17 ( L_10 , V_66 ) ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_69 * V_70 = & V_4 -> V_69 ;
if ( V_70 -> V_79 )
F_33 ( V_70 -> V_79 ) ;
if ( V_70 -> V_81 )
F_33 ( V_70 -> V_81 ) ;
V_70 -> V_79 = NULL ;
V_70 -> V_81 = NULL ;
}
static int F_34 ( struct V_3 * V_4 , T_3 V_82 )
{
struct V_67 * V_68 = V_4 -> V_68 ;
struct V_69 * V_70 = & V_4 -> V_69 ;
const char * V_66 = V_83 ;
struct V_71 * V_72 ;
int V_60 ;
V_72 = F_29 ( V_68 , V_84 , V_66 ) ;
if ( ! V_72 ) {
F_17 ( L_8 , V_66 ) ;
return - V_75 ;
}
V_60 = F_35 ( V_72 -> V_76 , V_82 , 0 , V_66 , V_4 ) ;
if ( V_60 ) {
F_17 ( L_11 , V_66 ) ;
return V_60 ;
}
V_70 -> V_85 = V_72 -> V_76 ;
V_70 -> V_86 = V_72 -> V_87 ;
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_69 * V_70 = & V_4 -> V_69 ;
int V_88 = V_70 -> V_85 ;
for (; V_88 <= V_70 -> V_86 ; V_88 ++ )
F_37 ( V_88 , V_4 ) ;
}
static bool F_38 ( struct V_30 * V_89 , void * V_46 )
{
struct V_3 * V_4 = V_46 ;
int V_90 = ( int ) V_4 -> V_91 ;
if ( ! F_39 ( V_89 ) )
return false ;
if ( V_90 == V_89 -> V_92 ) {
V_89 -> V_91 = & V_4 -> V_93 ;
return true ;
}
return false ;
}
static void F_40 ( struct V_3 * V_4 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_94 ; V_88 ++ )
if ( V_4 -> V_33 [ V_88 ] ) {
F_41 ( V_4 -> V_33 [ V_88 ] ) ;
V_4 -> V_33 [ V_88 ] = NULL ;
}
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_67 * V_68 = V_4 -> V_68 ;
struct V_71 * V_95 ;
struct V_96 * V_97 ;
T_4 V_90 ;
int V_39 ;
struct V_30 * V_30 ;
T_5 V_98 ;
V_97 = V_68 -> V_22 . V_99 ;
V_39 = F_43 ( V_97 , L_12 , & V_90 ) ;
if ( V_39 ) {
F_17 ( L_13 ) ;
goto V_100;
}
V_4 -> V_91 = ( void * ) V_90 ;
V_95 = F_29 ( V_68 , V_84 ,
V_101 ) ;
if ( ! V_95 ) {
F_17 ( L_14 ) ;
goto V_100;
}
V_4 -> V_93 . V_102 = V_95 -> V_76 ;
F_44 ( V_98 ) ;
F_45 ( V_103 , V_98 ) ;
V_30 = F_46 ( V_98 , F_38 , V_4 ) ;
if ( ! V_30 ) {
F_17 ( L_15 ) ;
goto V_100;
}
V_4 -> V_33 [ 0 ] = V_30 ;
return 0 ;
V_100:
F_40 ( V_4 ) ;
return - V_23 ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_69 * V_72 = & V_4 -> V_69 ;
struct V_104 * V_104 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_105 ; V_88 ++ ) {
V_104 = V_72 -> clock [ V_88 ] ;
if ( V_104 ) {
F_48 ( V_104 ) ;
V_72 -> clock [ V_88 ] = NULL ;
}
}
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_69 * V_72 = & V_4 -> V_69 ;
char * * V_106 = NULL ;
struct V_104 * V_104 ;
int V_88 ;
V_72 -> clock [ 0 ] = F_50 ( V_4 -> V_22 , L_16 ) ;
if ( F_51 ( V_72 -> clock [ 0 ] ) )
goto V_107;
if ( F_9 ( V_4 ) )
V_106 = V_108 ;
if ( ! V_106 )
return 0 ;
for ( V_88 = 1 ; V_88 < V_105 ; V_88 ++ ) {
if ( V_106 [ V_88 - 1 ] == NULL )
break;
V_104 = F_50 ( V_4 -> V_22 , V_106 [ V_88 - 1 ] ) ;
if ( F_51 ( V_104 ) )
goto V_107;
V_72 -> clock [ V_88 ] = V_104 ;
}
if ( F_9 ( V_4 ) )
F_52 ( V_72 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_107:
F_53 ( V_4 -> V_22 , L_17 ) ;
F_47 ( V_4 ) ;
return - V_77 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_109 * V_109 ;
int V_39 ;
V_39 = F_28 ( V_4 , V_78 ) ;
if ( V_39 )
goto V_110;
V_39 = F_28 ( V_4 , V_80 ) ;
if ( V_39 )
goto V_110;
V_39 = F_34 ( V_4 , F_1 ) ;
if ( V_39 )
goto V_110;
V_39 = F_42 ( V_4 ) ;
if ( V_39 )
goto V_111;
V_109 = F_55 ( & V_4 -> V_68 -> V_22 ) ;
if ( F_51 ( V_109 ) ) {
V_39 = F_56 ( V_109 ) ;
goto V_112;
}
V_39 = F_49 ( V_4 ) ;
if ( V_39 )
goto V_113;
return 0 ;
V_113:
V_112:
F_40 ( V_4 ) ;
V_111:
F_36 ( V_4 ) ;
V_110:
F_32 ( V_4 ) ;
return V_39 ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_47 ( V_4 ) ;
F_32 ( V_4 ) ;
F_36 ( V_4 ) ;
F_40 ( V_4 ) ;
}
static int F_58 ( struct V_3 * V_4 )
{
int V_39 ;
struct V_114 V_115 = {
. V_116 = 80 ,
. V_117 = 60 ,
. V_118 = 25 ,
. V_119 = 6 ,
. V_120 = - 1 ,
. V_121 = - 1 ,
. V_122 = - 1 ,
} ;
V_39 = F_59 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_123 = V_115 ;
return 0 ;
}
static int F_60 ( struct V_3 * V_4 ,
void * V_124 , unsigned V_125 ,
void * V_126 , T_6 V_127 , unsigned V_128 ,
void * * V_129 , T_6 * V_130 )
{
struct V_131 * V_22 = V_4 -> V_22 ;
if ( F_61 ( V_124 ) ) {
T_6 V_132 ;
V_132 = F_62 ( V_22 , V_124 ,
V_125 , V_54 ) ;
if ( F_63 ( V_22 , V_132 ) ) {
if ( V_128 < V_125 ) {
F_17 ( L_18 ,
V_133 ) ;
return - V_77 ;
}
goto V_134;
}
* V_129 = V_124 ;
* V_130 = V_132 ;
V_4 -> V_40 = true ;
return 0 ;
}
V_134:
* V_129 = V_126 ;
* V_130 = V_127 ;
V_4 -> V_40 = false ;
return 0 ;
}
static inline void F_64 ( struct V_3 * V_4 ,
void * V_124 , unsigned V_125 ,
void * V_126 , T_6 V_127 , unsigned V_128 ,
void * V_135 , T_6 V_136 )
{
if ( V_4 -> V_40 )
F_65 ( V_4 -> V_22 , V_136 , V_125 , V_54 ) ;
}
static inline void F_66 ( struct V_3 * V_4 ,
void * V_124 , unsigned V_125 ,
void * V_126 , T_6 V_127 , unsigned V_128 ,
void * V_135 , T_6 V_136 )
{
if ( ! V_4 -> V_40 )
memcpy ( V_124 , V_126 , V_125 ) ;
}
static int F_67 ( struct V_3 * V_4 ,
const void * V_137 , unsigned V_125 ,
void * V_126 , T_6 V_127 , unsigned V_128 ,
const void * * V_129 , T_6 * V_130 )
{
struct V_131 * V_22 = V_4 -> V_22 ;
if ( F_61 ( V_137 ) ) {
T_6 V_138 ;
V_138 = F_62 ( V_22 , ( void * ) V_137 , V_125 ,
V_45 ) ;
if ( F_63 ( V_22 , V_138 ) ) {
if ( V_128 < V_125 ) {
F_17 ( L_18 ,
V_133 ) ;
return - V_77 ;
}
goto V_134;
}
* V_129 = V_137 ;
* V_130 = V_138 ;
return 0 ;
}
V_134:
memcpy ( V_126 , V_137 , V_125 ) ;
* V_129 = V_126 ;
* V_130 = V_127 ;
return 0 ;
}
static void F_68 ( struct V_3 * V_4 ,
const void * V_137 , unsigned V_125 ,
void * V_126 , T_6 V_127 , unsigned V_128 ,
const void * V_135 , T_6 V_136 )
{
struct V_131 * V_22 = V_4 -> V_22 ;
if ( V_135 == V_137 )
F_65 ( V_22 , V_136 , V_125 , V_45 ) ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_131 * V_22 = V_4 -> V_22 ;
if ( V_4 -> V_139 && F_61 ( V_4 -> V_139 ) )
F_70 ( V_22 , V_4 -> V_140 ,
V_4 -> V_139 ,
V_4 -> V_141 ) ;
F_71 ( V_4 -> V_142 ) ;
F_71 ( V_4 -> V_43 ) ;
V_4 -> V_142 = NULL ;
V_4 -> V_43 = NULL ;
V_4 -> V_139 = NULL ;
V_4 -> V_140 = 0 ;
}
static int F_72 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_131 * V_22 = V_4 -> V_22 ;
V_4 -> V_142 = F_73 ( V_44 , V_143 | V_144 ) ;
if ( V_4 -> V_142 == NULL )
goto V_145;
V_4 -> V_43 = F_73 ( V_44 , V_143 | V_144 ) ;
if ( V_4 -> V_43 == NULL )
goto V_145;
V_4 -> V_140 = V_8 -> V_25 + V_8 -> V_26 ;
V_4 -> V_139 = F_74 ( V_22 , V_4 -> V_140 ,
& V_4 -> V_141 , V_143 ) ;
if ( ! V_4 -> V_139 )
goto V_145;
V_4 -> V_146 = V_4 -> V_139 ;
V_4 -> V_147 = V_4 -> V_141 ;
V_4 -> V_148 = V_4 -> V_146 + V_8 -> V_25 ;
V_4 -> V_149 = V_4 -> V_147 + V_8 -> V_25 ;
return 0 ;
V_145:
F_69 ( V_4 ) ;
F_17 ( L_19 ) ;
return - V_77 ;
}
static void F_75 ( struct V_9 * V_10 , int V_150 , unsigned int V_151 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
int V_39 ;
if ( ( V_151 & ( V_155 | V_156 ) ) ) {
if ( V_150 != V_157 )
V_4 -> V_142 [ V_4 -> V_158 ++ ] = V_150 ;
return;
}
if ( ! V_4 -> V_158 )
return;
V_39 = F_76 ( V_4 ) ;
if ( V_39 )
F_17 ( L_20 , V_4 -> V_32 , V_39 ) ;
V_4 -> V_158 = 0 ;
}
static int F_77 ( struct V_9 * V_10 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
return F_78 ( V_4 , V_4 -> V_32 ) ;
}
static void F_79 ( struct V_9 * V_10 , int V_31 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
if ( ( V_4 -> V_32 < 0 ) && ( V_31 >= 0 ) )
F_80 ( V_4 ) ;
else if ( ( V_4 -> V_32 >= 0 ) && ( V_31 < 0 ) )
F_81 ( V_4 ) ;
V_4 -> V_32 = V_31 ;
}
static void F_82 ( struct V_9 * V_10 , T_7 * V_159 , int V_160 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
F_83 ( L_21 , V_160 ) ;
V_4 -> V_41 = V_159 ;
V_4 -> V_42 = V_160 ;
F_84 ( V_4 ) ;
}
static void F_85 ( struct V_9 * V_10 , const T_7 * V_159 , int V_160 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
F_83 ( L_21 , V_160 ) ;
V_4 -> V_41 = ( T_7 * ) V_159 ;
V_4 -> V_42 = V_160 ;
F_86 ( V_4 ) ;
}
static T_7 F_87 ( struct V_9 * V_10 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
T_7 * V_159 = V_4 -> V_43 ;
F_82 ( V_10 , V_159 , 1 ) ;
return V_159 [ 0 ] ;
}
static void F_88 ( struct V_3 * V_4 ,
void * V_161 , void * V_162 )
{
struct V_7 * V_163 = & V_4 -> V_7 ;
unsigned char * V_73 ;
unsigned char * V_164 ;
unsigned int V_165 ;
unsigned char V_98 ;
unsigned char V_166 ;
unsigned char V_167 ;
if ( ! V_4 -> V_28 )
return;
V_165 = V_163 -> V_19 ;
V_73 = V_161 + V_163 -> V_29 ;
V_164 = V_162 ;
V_166 = ( V_73 [ 0 ] >> V_165 ) | ( V_73 [ 1 ] << ( 8 - V_165 ) ) ;
V_167 = V_164 [ 0 ] ;
V_164 [ 0 ] = V_166 ;
V_98 = ( 0x1 << V_165 ) - 1 ;
V_73 [ 0 ] = ( V_73 [ 0 ] & V_98 ) | ( V_167 << V_165 ) ;
V_98 = ~ 0 << V_165 ;
V_73 [ 1 ] = ( V_73 [ 1 ] & V_98 ) | ( V_167 >> ( 8 - V_165 ) ) ;
}
static int F_89 ( struct V_9 * V_10 , struct V_152 * V_153 ,
T_7 * V_159 , int V_168 , int V_169 )
{
struct V_3 * V_4 = V_153 -> V_154 ;
struct V_7 * V_163 = & V_4 -> V_7 ;
void * V_146 ;
T_6 V_147 ;
void * V_148 ;
T_6 V_149 ;
unsigned int V_88 ;
unsigned char * V_170 ;
unsigned int V_171 = 0 ;
int V_39 ;
F_83 ( L_22 , V_169 ) ;
V_39 = F_60 ( V_4 , V_159 , V_10 -> V_21 ,
V_4 -> V_146 , V_4 -> V_147 ,
V_163 -> V_25 ,
& V_146 , & V_147 ) ;
if ( V_39 ) {
F_17 ( L_23 ) ;
V_39 = - V_77 ;
return V_39 ;
}
V_148 = V_4 -> V_148 ;
V_149 = V_4 -> V_149 ;
V_39 = F_90 ( V_4 , V_147 , V_149 ) ;
F_64 ( V_4 , V_159 , V_10 -> V_21 ,
V_4 -> V_146 , V_4 -> V_147 ,
V_163 -> V_25 ,
V_146 , V_147 ) ;
if ( V_39 ) {
F_17 ( L_24 , V_39 ) ;
return V_39 ;
}
F_88 ( V_4 , V_146 , V_148 ) ;
V_170 = V_148 + V_163 -> V_27 ;
for ( V_88 = 0 ; V_88 < V_163 -> V_15 ; V_88 ++ , V_170 ++ ) {
if ( ( * V_170 == V_172 ) || ( * V_170 == V_173 ) )
continue;
if ( * V_170 == V_174 ) {
V_10 -> V_175 . V_176 ++ ;
continue;
}
V_10 -> V_175 . V_177 += * V_170 ;
V_171 = F_91 (unsigned int, max_bitflips, *status) ;
}
if ( V_168 ) {
memset ( V_153 -> V_178 , ~ 0 , V_10 -> V_12 ) ;
V_153 -> V_178 [ 0 ] = ( ( T_7 * ) V_148 ) [ 0 ] ;
}
F_66 ( V_4 , V_159 , V_10 -> V_21 ,
V_4 -> V_146 , V_4 -> V_147 ,
V_163 -> V_25 ,
V_146 , V_147 ) ;
return V_171 ;
}
static int F_92 ( struct V_9 * V_10 , struct V_152 * V_153 ,
const T_7 * V_159 , int V_168 )
{
struct V_3 * V_4 = V_153 -> V_154 ;
struct V_7 * V_163 = & V_4 -> V_7 ;
const void * V_146 ;
T_6 V_147 ;
const void * V_148 ;
T_6 V_149 ;
int V_39 ;
F_83 ( L_25 ) ;
if ( V_4 -> V_28 ) {
memcpy ( V_4 -> V_146 , V_159 , V_10 -> V_21 ) ;
V_146 = V_4 -> V_146 ;
V_147 = V_4 -> V_147 ;
memcpy ( V_4 -> V_148 , V_153 -> V_178 ,
V_163 -> V_26 ) ;
V_148 = V_4 -> V_148 ;
V_149 = V_4 -> V_149 ;
F_88 ( V_4 ,
( void * ) V_146 , ( void * ) V_148 ) ;
} else {
V_39 = F_67 ( V_4 ,
V_159 , V_10 -> V_21 ,
V_4 -> V_146 , V_4 -> V_147 ,
V_163 -> V_25 ,
& V_146 , & V_147 ) ;
if ( V_39 ) {
F_17 ( L_26 ) ;
return 0 ;
}
V_39 = F_67 ( V_4 ,
V_153 -> V_178 , V_10 -> V_12 ,
V_4 -> V_148 , V_4 -> V_149 ,
V_163 -> V_26 ,
& V_148 , & V_149 ) ;
if ( V_39 ) {
F_17 ( L_27 ) ;
goto V_179;
}
}
V_39 = F_93 ( V_4 , V_147 , V_149 ) ;
if ( V_39 )
F_17 ( L_28 , V_39 ) ;
if ( ! V_4 -> V_28 ) {
F_68 ( V_4 , V_153 -> V_178 , V_10 -> V_12 ,
V_4 -> V_148 , V_4 -> V_149 ,
V_163 -> V_26 ,
V_148 , V_149 ) ;
V_179:
F_68 ( V_4 , V_159 , V_10 -> V_21 ,
V_4 -> V_146 , V_4 -> V_147 ,
V_163 -> V_25 ,
V_146 , V_147 ) ;
}
return 0 ;
}
static int F_94 ( struct V_9 * V_10 , struct V_152 * V_153 ,
int V_169 )
{
struct V_3 * V_4 = V_153 -> V_154 ;
F_83 ( L_29 , V_169 ) ;
memset ( V_153 -> V_178 , ~ 0 , V_10 -> V_12 ) ;
V_153 -> V_180 ( V_10 , V_181 , V_10 -> V_21 , V_169 ) ;
V_153 -> V_182 ( V_10 , V_153 -> V_178 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_28 ) {
V_153 -> V_180 ( V_10 , V_181 , 0 , V_169 ) ;
V_153 -> V_178 [ 0 ] = V_153 -> V_183 ( V_10 ) ;
}
return 0 ;
}
static int
F_95 ( struct V_9 * V_10 , struct V_152 * V_153 , int V_169 )
{
return - V_184 ;
}
static int F_96 ( struct V_9 * V_10 , T_8 V_185 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
int V_186 , V_39 = 0 ;
T_7 * V_187 ;
int V_188 , V_169 , V_170 , V_31 ;
V_186 = ( int ) ( V_185 >> V_153 -> V_189 ) ;
if ( V_153 -> V_190 )
V_153 -> V_190 [ V_186 >> 2 ] |= 0x01 << ( ( V_186 & 0x03 ) << 1 ) ;
if ( V_153 -> V_191 & V_192 )
V_39 = F_97 ( V_10 , V_185 ) ;
else {
V_31 = ( int ) ( V_185 >> V_153 -> V_193 ) ;
V_153 -> V_194 ( V_10 , V_31 ) ;
V_188 = V_4 -> V_28 ? V_10 -> V_21 : 0 ;
V_187 = V_4 -> V_43 ;
V_187 [ 0 ] = 0 ;
V_169 = ( int ) ( V_185 >> V_153 -> V_195 ) ;
V_153 -> V_180 ( V_10 , V_196 , V_188 , V_169 ) ;
V_153 -> V_197 ( V_10 , V_187 , 1 ) ;
V_153 -> V_180 ( V_10 , V_198 , - 1 , - 1 ) ;
V_170 = V_153 -> V_199 ( V_10 , V_153 ) ;
if ( V_170 & V_200 )
V_39 = - V_201 ;
V_153 -> V_194 ( V_10 , - 1 ) ;
}
if ( ! V_39 )
V_10 -> V_175 . V_202 ++ ;
return V_39 ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_203 * V_204 = & V_4 -> V_205 ;
V_204 -> V_206 = 64 ;
V_204 -> V_207 = 2 ;
return 0 ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_203 * V_208 = & V_4 -> V_205 ;
struct V_131 * V_22 = V_4 -> V_22 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_152 * V_153 = & V_4 -> V_209 ;
unsigned int V_210 ;
unsigned int V_211 ;
unsigned int V_169 ;
T_7 * V_212 = V_153 -> V_213 -> V_214 ;
int V_215 ;
int V_216 = false ;
V_210 = 1 << V_208 -> V_207 ;
V_215 = V_4 -> V_32 ;
V_153 -> V_194 ( V_10 , 0 ) ;
F_53 ( V_22 , L_30 ) ;
for ( V_211 = 0 ; V_211 < V_210 ; V_211 ++ ) {
V_169 = V_211 * V_208 -> V_206 ;
F_53 ( V_22 , L_31 , V_169 ) ;
V_153 -> V_180 ( V_10 , V_181 , 12 , V_169 ) ;
V_153 -> V_182 ( V_10 , V_212 , strlen ( V_217 ) ) ;
if ( ! memcmp ( V_212 , V_217 , strlen ( V_217 ) ) ) {
V_216 = true ;
break;
}
}
V_153 -> V_194 ( V_10 , V_215 ) ;
if ( V_216 )
F_53 ( V_22 , L_32 ) ;
else
F_53 ( V_22 , L_33 ) ;
return V_216 ;
}
static int F_100 ( struct V_3 * V_4 )
{
struct V_131 * V_22 = V_4 -> V_22 ;
struct V_203 * V_208 = & V_4 -> V_205 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_152 * V_153 = & V_4 -> V_209 ;
unsigned int V_218 ;
unsigned int V_210 ;
unsigned int V_219 ;
unsigned int V_220 ;
unsigned int V_186 ;
unsigned int V_211 ;
unsigned int V_169 ;
T_7 * V_212 = V_153 -> V_213 -> V_214 ;
int V_215 ;
int V_170 ;
V_218 = V_10 -> V_221 / V_10 -> V_21 ;
V_210 = 1 << V_208 -> V_207 ;
V_219 = V_210 *
V_208 -> V_206 ;
V_220 =
( V_219 + ( V_218 - 1 ) ) /
V_218 ;
F_53 ( V_22 , L_34 ) ;
F_53 ( V_22 , L_35 , V_220 ) ;
F_53 ( V_22 , L_36 , V_210 ) ;
F_53 ( V_22 , L_37 , V_219 ) ;
V_215 = V_4 -> V_32 ;
V_153 -> V_194 ( V_10 , 0 ) ;
F_53 ( V_22 , L_38 ) ;
for ( V_186 = 0 ; V_186 < V_220 ; V_186 ++ ) {
V_169 = V_186 * V_218 ;
F_53 ( V_22 , L_39 , V_186 ) ;
V_153 -> V_180 ( V_10 , V_222 , - 1 , V_169 ) ;
V_153 -> V_180 ( V_10 , V_223 , - 1 , - 1 ) ;
V_170 = V_153 -> V_199 ( V_10 , V_153 ) ;
if ( V_170 & V_200 )
F_11 ( V_22 , L_40 , V_133 ) ;
}
memset ( V_212 , ~ 0 , V_10 -> V_21 ) ;
memset ( V_153 -> V_178 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_212 + 12 , V_217 , strlen ( V_217 ) ) ;
F_53 ( V_22 , L_41 ) ;
for ( V_211 = 0 ; V_211 < V_210 ; V_211 ++ ) {
V_169 = V_211 * V_208 -> V_206 ;
F_53 ( V_22 , L_42 , V_169 ) ;
V_153 -> V_180 ( V_10 , V_196 , 0x00 , V_169 ) ;
V_153 -> V_224 . V_225 ( V_10 , V_153 , V_212 , 0 ) ;
V_153 -> V_180 ( V_10 , V_198 , - 1 , - 1 ) ;
V_170 = V_153 -> V_199 ( V_10 , V_153 ) ;
if ( V_170 & V_200 )
F_11 ( V_22 , L_43 , V_133 ) ;
}
V_153 -> V_194 ( V_10 , V_215 ) ;
return 0 ;
}
static int F_101 ( struct V_3 * V_4 )
{
struct V_131 * V_22 = V_4 -> V_22 ;
struct V_152 * V_153 = & V_4 -> V_209 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_226 ;
unsigned int V_186 ;
int V_31 ;
int V_169 ;
T_8 V_227 ;
T_7 V_187 ;
int V_39 = 0 ;
if ( F_99 ( V_4 ) )
return 0 ;
F_53 ( V_22 , L_44 ) ;
V_226 = V_153 -> V_228 >> V_153 -> V_229 ;
for ( V_186 = 0 ; V_186 < V_226 ; V_186 ++ ) {
V_31 = V_186 >> ( V_153 -> V_193 - V_153 -> V_229 ) ;
V_169 = V_186 << ( V_153 -> V_229 - V_153 -> V_195 ) ;
V_227 = V_186 << V_153 -> V_229 ;
V_153 -> V_194 ( V_10 , V_31 ) ;
V_153 -> V_180 ( V_10 , V_181 , V_10 -> V_21 , V_169 ) ;
V_187 = V_153 -> V_183 ( V_10 ) ;
V_153 -> V_194 ( V_10 , - 1 ) ;
if ( V_187 != 0xff ) {
F_53 ( V_22 , L_45 , V_186 ) ;
V_39 = V_153 -> V_230 ( V_10 , V_227 ) ;
if ( V_39 )
F_11 ( V_22 , L_46
L_47 , V_39 ) ;
}
}
F_100 ( V_4 ) ;
return 0 ;
}
static int F_102 ( struct V_3 * V_4 )
{
F_98 ( V_4 ) ;
if ( F_7 ( V_4 ) )
return F_101 ( V_4 ) ;
return 0 ;
}
static int F_103 ( struct V_3 * V_4 )
{
int V_39 ;
F_69 ( V_4 ) ;
V_39 = F_104 ( V_4 ) ;
if ( V_39 ) {
F_17 ( L_48 , V_39 ) ;
return V_39 ;
}
return F_72 ( V_4 ) ;
}
static int F_105 ( struct V_3 * V_4 )
{
int V_39 ;
if ( F_7 ( V_4 ) )
V_4 -> V_28 = false ;
else
V_4 -> V_28 = true ;
V_39 = F_103 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_209 . V_224 . V_231 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_11 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_232 = V_4 -> V_7 . V_11 ;
return F_102 ( V_4 ) ;
}
static int F_106 ( struct V_9 * V_10 )
{
struct V_152 * V_153 = V_10 -> V_154 ;
struct V_3 * V_4 = V_153 -> V_154 ;
int V_39 ;
V_39 = F_105 ( V_4 ) ;
if ( V_39 )
return V_39 ;
F_107 ( V_4 ) ;
return F_108 ( V_10 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
F_110 ( & V_4 -> V_10 ) ;
F_69 ( V_4 ) ;
}
static int F_111 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_152 * V_153 = & V_4 -> V_209 ;
struct V_233 V_234 = {} ;
int V_39 ;
V_4 -> V_32 = - 1 ;
V_10 -> V_154 = V_153 ;
V_10 -> V_235 = L_49 ;
V_10 -> V_236 = V_237 ;
V_153 -> V_154 = V_4 ;
V_153 -> V_194 = F_79 ;
V_153 -> V_238 = F_75 ;
V_153 -> V_239 = F_77 ;
V_153 -> V_183 = F_87 ;
V_153 -> V_182 = F_82 ;
V_153 -> V_197 = F_85 ;
V_153 -> V_224 . V_240 = F_89 ;
V_153 -> V_224 . V_241 = F_92 ;
V_153 -> V_224 . V_242 = F_94 ;
V_153 -> V_224 . V_243 = F_95 ;
V_153 -> V_244 = F_106 ;
V_153 -> V_245 = & V_246 ;
V_153 -> V_230 = F_96 ;
V_153 -> V_247 |= V_248 ;
V_153 -> V_224 . V_249 = V_250 ;
V_153 -> V_224 . V_251 = 1 ;
V_153 -> V_224 . V_231 = 8 ;
V_153 -> V_224 . V_252 = & V_253 ;
if ( F_112 ( V_4 -> V_22 -> V_99 ) )
V_153 -> V_191 |= V_192 | V_254 ;
V_4 -> V_7 . V_25 = 1024 ;
V_4 -> V_7 . V_26 = 128 ;
V_39 = F_72 ( V_4 ) ;
if ( V_39 )
goto V_255;
V_39 = F_113 ( V_10 , 1 ) ;
if ( V_39 ) {
F_17 ( L_50 ) ;
goto V_255;
}
V_234 . V_99 = V_4 -> V_68 -> V_22 . V_99 ;
V_39 = F_114 ( V_10 , NULL , & V_234 , NULL , 0 ) ;
if ( V_39 )
goto V_255;
return 0 ;
V_255:
F_109 ( V_4 ) ;
return V_39 ;
}
static int F_115 ( struct V_67 * V_68 )
{
struct V_3 * V_4 ;
const struct V_256 * V_257 ;
int V_39 ;
V_257 = F_116 ( V_258 , & V_68 -> V_22 ) ;
if ( V_257 ) {
V_68 -> V_259 = V_257 -> V_150 ;
} else {
F_17 ( L_51 ) ;
return - V_77 ;
}
V_4 = F_73 ( sizeof( * V_4 ) , V_144 ) ;
if ( ! V_4 ) {
F_17 ( L_52 ) ;
return - V_77 ;
}
F_117 ( V_68 , V_4 ) ;
V_4 -> V_68 = V_68 ;
V_4 -> V_22 = & V_68 -> V_22 ;
V_39 = F_54 ( V_4 ) ;
if ( V_39 )
goto V_260;
V_39 = F_58 ( V_4 ) ;
if ( V_39 )
goto V_261;
V_39 = F_111 ( V_4 ) ;
if ( V_39 )
goto V_261;
F_118 ( V_4 -> V_22 , L_53 ) ;
return 0 ;
V_261:
F_57 ( V_4 ) ;
V_260:
F_117 ( V_68 , NULL ) ;
F_11 ( V_4 -> V_22 , L_54 , V_39 ) ;
F_71 ( V_4 ) ;
return V_39 ;
}
static int F_119 ( struct V_67 * V_68 )
{
struct V_3 * V_4 = F_120 ( V_68 ) ;
F_109 ( V_4 ) ;
F_57 ( V_4 ) ;
F_117 ( V_68 , NULL ) ;
F_71 ( V_4 ) ;
return 0 ;
}
