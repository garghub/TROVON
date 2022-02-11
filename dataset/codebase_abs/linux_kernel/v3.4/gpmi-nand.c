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
struct V_69 * V_70 = V_4 -> V_88 ;
if ( ! F_34 ( V_87 ) )
return false ;
if ( V_70 -> V_74 <= V_87 -> V_89 && V_87 -> V_89 <= V_70 -> V_85 ) {
V_87 -> V_88 = & V_4 -> V_90 ;
return true ;
}
return false ;
}
static void F_35 ( struct V_3 * V_4 )
{
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_91 ; V_86 ++ )
if ( V_4 -> V_30 [ V_86 ] ) {
F_36 ( V_4 -> V_30 [ V_86 ] ) ;
V_4 -> V_30 [ V_86 ] = NULL ;
}
}
static int T_2 F_37 ( struct V_3 * V_4 )
{
struct V_65 * V_66 = V_4 -> V_66 ;
struct V_92 * V_93 = V_4 -> V_93 ;
struct V_67 * V_68 = & V_4 -> V_67 ;
struct V_69 * V_70 , * V_94 ;
unsigned int V_86 ;
V_70 = F_24 ( V_66 , V_95 ,
V_96 ) ;
V_94 = F_24 ( V_66 , V_82 ,
V_97 ) ;
if ( ! V_70 || ! V_94 ) {
F_7 ( L_10 ) ;
return - V_73 ;
}
V_4 -> V_88 = V_70 ;
for ( V_86 = V_70 -> V_74 ; V_86 <= V_70 -> V_85 ; V_86 ++ ) {
struct V_27 * V_27 ;
T_4 V_98 ;
if ( V_86 - V_70 -> V_74 >= V_93 -> V_99 )
break;
F_38 ( V_98 ) ;
F_39 ( V_100 , V_98 ) ;
if ( V_94 -> V_74 == V_94 -> V_85 ) {
if ( V_86 == V_70 -> V_74 )
V_4 -> V_90 . V_101 = V_94 -> V_74 ;
else
V_4 -> V_90 . V_101 = V_102 ;
} else
V_4 -> V_90 . V_101 = V_94 -> V_74 + ( V_86 - V_70 -> V_74 ) ;
V_27 = F_40 ( V_98 , F_33 , V_4 ) ;
if ( ! V_27 )
goto V_103;
V_4 -> V_30 [ V_86 - V_70 -> V_74 ] = V_27 ;
}
V_68 -> V_104 = V_70 -> V_74 ;
V_68 -> V_105 = V_86 ;
return 0 ;
V_103:
F_7 ( L_11 , V_86 ) ;
F_35 ( V_4 ) ;
return - V_20 ;
}
static int T_2 F_41 ( struct V_3 * V_4 )
{
struct V_67 * V_68 = & V_4 -> V_67 ;
int V_36 ;
V_36 = F_23 ( V_4 , V_76 ) ;
if ( V_36 )
goto V_106;
V_36 = F_23 ( V_4 , V_78 ) ;
if ( V_36 )
goto V_106;
V_36 = F_29 ( V_4 , F_1 ) ;
if ( V_36 )
goto V_106;
V_36 = F_37 ( V_4 ) ;
if ( V_36 )
goto V_107;
V_68 -> clock = F_42 ( & V_4 -> V_66 -> V_40 , NULL ) ;
if ( F_43 ( V_68 -> clock ) ) {
F_7 ( L_12 ) ;
V_36 = - V_108 ;
goto V_109;
}
return 0 ;
V_109:
F_35 ( V_4 ) ;
V_107:
F_31 ( V_4 ) ;
V_106:
F_27 ( V_4 ) ;
return V_36 ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_67 * V_70 = & V_4 -> V_67 ;
F_45 ( V_70 -> clock ) ;
F_27 ( V_4 ) ;
F_31 ( V_4 ) ;
F_35 ( V_4 ) ;
}
static int T_2 F_46 ( struct V_3 * V_4 )
{
int V_36 ;
struct V_110 V_111 = {
. V_112 = 80 ,
. V_113 = 60 ,
. V_114 = 25 ,
. V_115 = 6 ,
. V_116 = - 1 ,
. V_117 = - 1 ,
. V_118 = - 1 ,
} ;
V_36 = F_47 ( V_4 ) ;
if ( V_36 )
return V_36 ;
V_4 -> V_119 = V_111 ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 ,
void * V_120 , unsigned V_121 ,
void * V_122 , T_5 V_123 , unsigned V_124 ,
void * * V_125 , T_5 * V_126 )
{
struct V_127 * V_40 = V_4 -> V_40 ;
if ( F_49 ( V_120 ) ) {
T_5 V_128 ;
V_128 = F_50 ( V_40 , V_120 ,
V_121 , V_52 ) ;
if ( F_51 ( V_40 , V_128 ) ) {
if ( V_124 < V_121 ) {
F_7 ( L_13 ) ;
return - V_75 ;
}
goto V_129;
}
* V_125 = V_120 ;
* V_126 = V_128 ;
V_4 -> V_37 = true ;
return 0 ;
}
V_129:
* V_125 = V_122 ;
* V_126 = V_123 ;
V_4 -> V_37 = false ;
return 0 ;
}
static inline void F_52 ( struct V_3 * V_4 ,
void * V_120 , unsigned V_121 ,
void * V_122 , T_5 V_123 , unsigned V_124 ,
void * V_130 , T_5 V_131 )
{
if ( V_4 -> V_37 )
F_53 ( V_4 -> V_40 , V_131 , V_121 , V_52 ) ;
}
static inline void F_54 ( struct V_3 * V_4 ,
void * V_120 , unsigned V_121 ,
void * V_122 , T_5 V_123 , unsigned V_124 ,
void * V_130 , T_5 V_131 )
{
if ( ! V_4 -> V_37 )
memcpy ( V_120 , V_122 , V_121 ) ;
}
static int F_55 ( struct V_3 * V_4 ,
const void * V_132 , unsigned V_121 ,
void * V_122 , T_5 V_123 , unsigned V_124 ,
const void * * V_125 , T_5 * V_126 )
{
struct V_127 * V_40 = V_4 -> V_40 ;
if ( F_49 ( V_132 ) ) {
T_5 V_133 ;
V_133 = F_50 ( V_40 , ( void * ) V_132 , V_121 ,
V_43 ) ;
if ( F_51 ( V_40 , V_133 ) ) {
if ( V_124 < V_121 ) {
F_7 ( L_13 ) ;
return - V_75 ;
}
goto V_129;
}
* V_125 = V_132 ;
* V_126 = V_133 ;
return 0 ;
}
V_129:
memcpy ( V_122 , V_132 , V_121 ) ;
* V_125 = V_122 ;
* V_126 = V_123 ;
return 0 ;
}
static void F_56 ( struct V_3 * V_4 ,
const void * V_132 , unsigned V_121 ,
void * V_122 , T_5 V_123 , unsigned V_124 ,
const void * V_130 , T_5 V_131 )
{
struct V_127 * V_40 = V_4 -> V_40 ;
if ( V_130 == V_132 )
F_53 ( V_40 , V_131 , V_121 , V_43 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
struct V_127 * V_40 = V_4 -> V_40 ;
if ( V_4 -> V_134 && F_49 ( V_4 -> V_134 ) )
F_58 ( V_40 , V_4 -> V_135 ,
V_4 -> V_134 ,
V_4 -> V_136 ) ;
F_59 ( V_4 -> V_137 ) ;
F_59 ( V_4 -> V_41 ) ;
V_4 -> V_137 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_134 = NULL ;
V_4 -> V_135 = 0 ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_127 * V_40 = V_4 -> V_40 ;
V_4 -> V_137 = F_61 ( V_42 , V_138 ) ;
if ( V_4 -> V_137 == NULL )
goto V_139;
V_4 -> V_41 = F_61 ( V_42 , V_138 ) ;
if ( V_4 -> V_41 == NULL )
goto V_139;
V_4 -> V_135 = V_8 -> V_22 + V_8 -> V_23 ;
V_4 -> V_134 = F_62 ( V_40 , V_4 -> V_135 ,
& V_4 -> V_136 , V_138 ) ;
if ( ! V_4 -> V_134 )
goto V_139;
V_4 -> V_140 = V_4 -> V_134 ;
V_4 -> V_141 = V_4 -> V_136 ;
V_4 -> V_142 = V_4 -> V_140 + V_8 -> V_22 ;
V_4 -> V_143 = V_4 -> V_141 + V_8 -> V_22 ;
return 0 ;
V_139:
F_57 ( V_4 ) ;
F_7 ( L_14 ) ;
return - V_75 ;
}
static void F_63 ( struct V_9 * V_10 , int V_144 , unsigned int V_145 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
int V_36 ;
if ( ( V_145 & ( V_149 | V_150 ) ) ) {
if ( V_144 != V_151 )
V_4 -> V_137 [ V_4 -> V_152 ++ ] = V_144 ;
return;
}
if ( ! V_4 -> V_152 )
return;
V_36 = F_64 ( V_4 ) ;
if ( V_36 )
F_7 ( L_15 , V_4 -> V_29 , V_36 ) ;
V_4 -> V_152 = 0 ;
}
static int F_65 ( struct V_9 * V_10 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
return F_66 ( V_4 , V_4 -> V_29 ) ;
}
static void F_67 ( struct V_9 * V_10 , int V_28 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
if ( ( V_4 -> V_29 < 0 ) && ( V_28 >= 0 ) )
F_68 ( V_4 ) ;
else if ( ( V_4 -> V_29 >= 0 ) && ( V_28 < 0 ) )
F_69 ( V_4 ) ;
V_4 -> V_29 = V_28 ;
}
static void F_70 ( struct V_9 * V_10 , T_6 * V_153 , int V_154 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
F_71 ( L_16 , V_154 ) ;
V_4 -> V_38 = V_153 ;
V_4 -> V_39 = V_154 ;
F_72 ( V_4 ) ;
}
static void F_73 ( struct V_9 * V_10 , const T_6 * V_153 , int V_154 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
F_71 ( L_16 , V_154 ) ;
V_4 -> V_38 = ( T_6 * ) V_153 ;
V_4 -> V_39 = V_154 ;
F_74 ( V_4 ) ;
}
static T_6 F_75 ( struct V_9 * V_10 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
T_6 * V_153 = V_4 -> V_41 ;
F_70 ( V_10 , V_153 , 1 ) ;
return V_153 [ 0 ] ;
}
static void F_76 ( struct V_3 * V_4 ,
void * V_155 , void * V_156 )
{
struct V_7 * V_157 = & V_4 -> V_7 ;
unsigned char * V_71 ;
unsigned char * V_158 ;
unsigned int V_159 ;
unsigned char V_98 ;
unsigned char V_160 ;
unsigned char V_161 ;
if ( ! V_4 -> V_25 )
return;
V_159 = V_157 -> V_17 ;
V_71 = V_155 + V_157 -> V_26 ;
V_158 = V_156 ;
V_160 = ( V_71 [ 0 ] >> V_159 ) | ( V_71 [ 1 ] << ( 8 - V_159 ) ) ;
V_161 = V_158 [ 0 ] ;
V_158 [ 0 ] = V_160 ;
V_98 = ( 0x1 << V_159 ) - 1 ;
V_71 [ 0 ] = ( V_71 [ 0 ] & V_98 ) | ( V_161 << V_159 ) ;
V_98 = ~ 0 << V_159 ;
V_71 [ 1 ] = ( V_71 [ 1 ] & V_98 ) | ( V_161 >> ( 8 - V_159 ) ) ;
}
static int F_77 ( struct V_9 * V_10 , struct V_146 * V_147 ,
T_6 * V_153 , int V_162 )
{
struct V_3 * V_4 = V_147 -> V_148 ;
struct V_7 * V_157 = & V_4 -> V_7 ;
void * V_140 ;
T_5 V_141 ;
void * V_142 ;
T_5 V_143 ;
unsigned int V_86 ;
unsigned char * V_163 ;
unsigned int V_164 ;
unsigned int V_165 ;
int V_36 ;
F_71 ( L_17 , V_162 ) ;
V_36 = F_48 ( V_4 , V_153 , V_10 -> V_19 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_157 -> V_22 ,
& V_140 , & V_141 ) ;
if ( V_36 ) {
F_7 ( L_18 ) ;
V_36 = - V_75 ;
return V_36 ;
}
V_142 = V_4 -> V_142 ;
V_143 = V_4 -> V_143 ;
V_36 = F_78 ( V_4 , V_141 , V_143 ) ;
F_52 ( V_4 , V_153 , V_10 -> V_19 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_157 -> V_22 ,
V_140 , V_141 ) ;
if ( V_36 ) {
F_7 ( L_19 , V_36 ) ;
goto V_166;
}
F_76 ( V_4 , V_140 , V_142 ) ;
V_164 = 0 ;
V_165 = 0 ;
V_163 = V_142 + V_157 -> V_24 ;
for ( V_86 = 0 ; V_86 < V_157 -> V_15 ; V_86 ++ , V_163 ++ ) {
if ( ( * V_163 == V_167 ) || ( * V_163 == V_168 ) )
continue;
if ( * V_163 == V_169 ) {
V_164 ++ ;
continue;
}
V_165 += * V_163 ;
}
if ( V_164 || V_165 >= ( V_157 -> V_11 - 1 ) ) {
V_10 -> V_170 . V_164 += V_164 ;
V_10 -> V_170 . V_165 += V_165 ;
}
memset ( V_147 -> V_171 , ~ 0 , V_10 -> V_12 ) ;
V_147 -> V_171 [ 0 ] = ( ( T_6 * ) V_142 ) [ 0 ] ;
F_54 ( V_4 , V_153 , V_10 -> V_19 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_157 -> V_22 ,
V_140 , V_141 ) ;
V_166:
return V_36 ;
}
static void F_79 ( struct V_9 * V_10 ,
struct V_146 * V_147 , const T_6 * V_153 )
{
struct V_3 * V_4 = V_147 -> V_148 ;
struct V_7 * V_157 = & V_4 -> V_7 ;
const void * V_140 ;
T_5 V_141 ;
const void * V_142 ;
T_5 V_143 ;
int V_36 ;
F_71 ( L_20 ) ;
if ( V_4 -> V_25 ) {
memcpy ( V_4 -> V_140 , V_153 , V_10 -> V_19 ) ;
V_140 = V_4 -> V_140 ;
V_141 = V_4 -> V_141 ;
memcpy ( V_4 -> V_142 , V_147 -> V_171 ,
V_157 -> V_23 ) ;
V_142 = V_4 -> V_142 ;
V_143 = V_4 -> V_143 ;
F_76 ( V_4 ,
( void * ) V_140 , ( void * ) V_142 ) ;
} else {
V_36 = F_55 ( V_4 ,
V_153 , V_10 -> V_19 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_157 -> V_22 ,
& V_140 , & V_141 ) ;
if ( V_36 ) {
F_7 ( L_21 ) ;
return;
}
V_36 = F_55 ( V_4 ,
V_147 -> V_171 , V_10 -> V_12 ,
V_4 -> V_142 , V_4 -> V_143 ,
V_157 -> V_23 ,
& V_142 , & V_143 ) ;
if ( V_36 ) {
F_7 ( L_22 ) ;
goto V_172;
}
}
V_36 = F_80 ( V_4 , V_141 , V_143 ) ;
if ( V_36 )
F_7 ( L_23 , V_36 ) ;
if ( ! V_4 -> V_25 ) {
F_56 ( V_4 , V_147 -> V_171 , V_10 -> V_12 ,
V_4 -> V_142 , V_4 -> V_143 ,
V_157 -> V_23 ,
V_142 , V_143 ) ;
V_172:
F_56 ( V_4 , V_153 , V_10 -> V_19 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_157 -> V_22 ,
V_140 , V_141 ) ;
}
}
static int F_81 ( struct V_9 * V_10 , struct V_146 * V_147 ,
int V_162 , int V_173 )
{
struct V_3 * V_4 = V_147 -> V_148 ;
F_71 ( L_24 , V_162 ) ;
memset ( V_147 -> V_171 , ~ 0 , V_10 -> V_12 ) ;
V_147 -> V_174 ( V_10 , V_175 , V_10 -> V_19 , V_162 ) ;
V_147 -> V_176 ( V_10 , V_147 -> V_171 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_25 ) {
V_147 -> V_174 ( V_10 , V_175 , 0 , V_162 ) ;
V_147 -> V_171 [ 0 ] = V_147 -> V_177 ( V_10 ) ;
}
return true ;
}
static int
F_82 ( struct V_9 * V_10 , struct V_146 * V_147 , int V_162 )
{
return - V_178 ;
}
static int F_83 ( struct V_9 * V_10 , T_7 V_179 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
int V_180 , V_36 = 0 ;
T_6 * V_181 ;
int V_182 , V_162 , V_163 , V_28 ;
V_180 = ( int ) ( V_179 >> V_147 -> V_183 ) ;
if ( V_147 -> V_184 )
V_147 -> V_184 [ V_180 >> 2 ] |= 0x01 << ( ( V_180 & 0x03 ) << 1 ) ;
if ( V_147 -> V_185 & V_186 )
V_36 = F_84 ( V_10 , V_179 ) ;
else {
V_28 = ( int ) ( V_179 >> V_147 -> V_187 ) ;
V_147 -> V_188 ( V_10 , V_28 ) ;
V_182 = V_4 -> V_25 ? V_10 -> V_19 : 0 ;
V_181 = V_4 -> V_41 ;
V_181 [ 0 ] = 0 ;
V_162 = ( int ) ( V_179 >> V_147 -> V_189 ) ;
V_147 -> V_174 ( V_10 , V_190 , V_182 , V_162 ) ;
V_147 -> V_191 ( V_10 , V_181 , 1 ) ;
V_147 -> V_174 ( V_10 , V_192 , - 1 , - 1 ) ;
V_163 = V_147 -> V_193 ( V_10 , V_147 ) ;
if ( V_163 & V_194 )
V_36 = - V_195 ;
V_147 -> V_188 ( V_10 , - 1 ) ;
}
if ( ! V_36 )
V_10 -> V_170 . V_196 ++ ;
return V_36 ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_197 * V_198 = & V_4 -> V_199 ;
V_198 -> V_200 = 64 ;
V_198 -> V_201 = 2 ;
return 0 ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_197 * V_202 = & V_4 -> V_199 ;
struct V_127 * V_40 = V_4 -> V_40 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_146 * V_147 = & V_4 -> V_203 ;
unsigned int V_204 ;
unsigned int V_205 ;
unsigned int V_162 ;
T_7 V_206 ;
T_6 * V_207 = V_147 -> V_208 -> V_209 ;
int V_210 ;
int V_211 = false ;
V_204 = 1 << V_202 -> V_201 ;
V_210 = V_4 -> V_29 ;
V_147 -> V_188 ( V_10 , 0 ) ;
F_87 ( V_40 , L_25 ) ;
for ( V_205 = 0 ; V_205 < V_204 ; V_205 ++ ) {
V_162 = V_205 * V_202 -> V_200 ;
V_206 = V_162 * V_10 -> V_19 ;
F_87 ( V_40 , L_26 , V_162 ) ;
V_147 -> V_174 ( V_10 , V_175 , 12 , V_162 ) ;
V_147 -> V_176 ( V_10 , V_207 , strlen ( V_212 ) ) ;
if ( ! memcmp ( V_207 , V_212 , strlen ( V_212 ) ) ) {
V_211 = true ;
break;
}
}
V_147 -> V_188 ( V_10 , V_210 ) ;
if ( V_211 )
F_87 ( V_40 , L_27 ) ;
else
F_87 ( V_40 , L_28 ) ;
return V_211 ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_127 * V_40 = V_4 -> V_40 ;
struct V_197 * V_202 = & V_4 -> V_199 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_146 * V_147 = & V_4 -> V_203 ;
unsigned int V_213 ;
unsigned int V_204 ;
unsigned int V_214 ;
unsigned int V_215 ;
unsigned int V_180 ;
unsigned int V_205 ;
unsigned int V_162 ;
T_7 V_206 ;
T_6 * V_207 = V_147 -> V_208 -> V_209 ;
int V_210 ;
int V_163 ;
V_213 = V_10 -> V_216 / V_10 -> V_19 ;
V_204 = 1 << V_202 -> V_201 ;
V_214 = V_204 *
V_202 -> V_200 ;
V_215 =
( V_214 + ( V_213 - 1 ) ) /
V_213 ;
F_87 ( V_40 , L_29 ) ;
F_87 ( V_40 , L_30 , V_215 ) ;
F_87 ( V_40 , L_31 , V_204 ) ;
F_87 ( V_40 , L_32 , V_214 ) ;
V_210 = V_4 -> V_29 ;
V_147 -> V_188 ( V_10 , 0 ) ;
F_87 ( V_40 , L_33 ) ;
for ( V_180 = 0 ; V_180 < V_215 ; V_180 ++ ) {
V_162 = V_180 * V_213 ;
F_87 ( V_40 , L_34 , V_180 ) ;
V_147 -> V_174 ( V_10 , V_217 , - 1 , V_162 ) ;
V_147 -> V_174 ( V_10 , V_218 , - 1 , - 1 ) ;
V_163 = V_147 -> V_193 ( V_10 , V_147 ) ;
if ( V_163 & V_194 )
F_89 ( V_40 , L_35 , V_219 ) ;
}
memset ( V_207 , ~ 0 , V_10 -> V_19 ) ;
memset ( V_147 -> V_171 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_207 + 12 , V_212 , strlen ( V_212 ) ) ;
F_87 ( V_40 , L_36 ) ;
for ( V_205 = 0 ; V_205 < V_204 ; V_205 ++ ) {
V_162 = V_205 * V_202 -> V_200 ;
V_206 = V_162 * V_10 -> V_19 ;
F_87 ( V_40 , L_37 , V_162 ) ;
V_147 -> V_174 ( V_10 , V_190 , 0x00 , V_162 ) ;
V_147 -> V_220 . V_221 ( V_10 , V_147 , V_207 ) ;
V_147 -> V_174 ( V_10 , V_192 , - 1 , - 1 ) ;
V_163 = V_147 -> V_193 ( V_10 , V_147 ) ;
if ( V_163 & V_194 )
F_89 ( V_40 , L_38 , V_219 ) ;
}
V_147 -> V_188 ( V_10 , V_210 ) ;
return 0 ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_127 * V_40 = V_4 -> V_40 ;
struct V_146 * V_147 = & V_4 -> V_203 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_222 ;
unsigned int V_180 ;
int V_28 ;
int V_162 ;
T_7 V_206 ;
T_6 V_181 ;
int V_36 = 0 ;
if ( F_86 ( V_4 ) )
return 0 ;
F_87 ( V_40 , L_39 ) ;
V_222 = V_147 -> V_223 >> V_147 -> V_224 ;
for ( V_180 = 0 ; V_180 < V_222 ; V_180 ++ ) {
V_28 = V_180 >> ( V_147 -> V_187 - V_147 -> V_224 ) ;
V_162 = V_180 << ( V_147 -> V_224 - V_147 -> V_189 ) ;
V_206 = V_180 << V_147 -> V_224 ;
V_147 -> V_188 ( V_10 , V_28 ) ;
V_147 -> V_174 ( V_10 , V_175 , V_10 -> V_19 , V_162 ) ;
V_181 = V_147 -> V_177 ( V_10 ) ;
V_147 -> V_188 ( V_10 , - 1 ) ;
if ( V_181 != 0xff ) {
F_87 ( V_40 , L_40 , V_180 ) ;
V_36 = V_147 -> V_225 ( V_10 , V_206 ) ;
if ( V_36 )
F_89 ( V_40 , L_41
L_42 , V_36 ) ;
}
}
F_88 ( V_4 ) ;
return 0 ;
}
static int F_91 ( struct V_3 * V_4 )
{
F_85 ( V_4 ) ;
if ( F_92 ( V_4 ) )
return F_90 ( V_4 ) ;
return 0 ;
}
static int F_93 ( struct V_3 * V_4 )
{
int V_36 ;
F_57 ( V_4 ) ;
V_36 = F_94 ( V_4 ) ;
if ( V_36 ) {
F_7 ( L_43 , V_36 ) ;
return V_36 ;
}
return F_60 ( V_4 ) ;
}
static int F_95 ( struct V_3 * V_4 )
{
int V_36 ;
if ( F_92 ( V_4 ) )
V_4 -> V_25 = false ;
else
V_4 -> V_25 = true ;
V_36 = F_93 ( V_4 ) ;
if ( V_36 )
return V_36 ;
return F_91 ( V_4 ) ;
}
static int F_96 ( struct V_9 * V_10 )
{
struct V_146 * V_147 = V_10 -> V_148 ;
struct V_3 * V_4 = V_147 -> V_148 ;
int V_36 ;
V_36 = F_95 ( V_4 ) ;
if ( V_36 )
return V_36 ;
return F_97 ( V_10 ) ;
}
void F_98 ( struct V_3 * V_4 )
{
F_99 ( & V_4 -> V_10 ) ;
F_57 ( V_4 ) ;
}
static int T_2 F_100 ( struct V_3 * V_4 )
{
struct V_92 * V_93 = V_4 -> V_93 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_146 * V_147 = & V_4 -> V_203 ;
int V_36 ;
V_4 -> V_29 = - 1 ;
V_10 -> V_148 = V_147 ;
V_10 -> V_226 = L_44 ;
V_10 -> V_227 = V_228 ;
V_147 -> V_148 = V_4 ;
V_147 -> V_188 = F_67 ;
V_147 -> V_229 = F_63 ;
V_147 -> V_230 = F_65 ;
V_147 -> V_177 = F_75 ;
V_147 -> V_176 = F_70 ;
V_147 -> V_191 = F_73 ;
V_147 -> V_220 . V_231 = F_77 ;
V_147 -> V_220 . V_232 = F_79 ;
V_147 -> V_220 . V_233 = F_81 ;
V_147 -> V_220 . V_234 = F_82 ;
V_147 -> V_235 = F_96 ;
V_147 -> V_236 = & V_237 ;
V_147 -> V_225 = F_83 ;
V_147 -> V_238 |= V_239 ;
V_147 -> V_220 . V_240 = V_241 ;
V_147 -> V_220 . V_242 = 1 ;
V_147 -> V_220 . V_243 = & V_244 ;
V_4 -> V_7 . V_22 = 1024 ;
V_4 -> V_7 . V_23 = 128 ;
V_36 = F_60 ( V_4 ) ;
if ( V_36 )
goto V_245;
V_36 = F_101 ( V_10 , V_93 -> V_99 ) ;
if ( V_36 ) {
F_7 ( L_45 ) ;
goto V_245;
}
V_36 = F_102 ( V_10 , NULL , NULL ,
V_93 -> V_246 , V_93 -> V_247 ) ;
if ( V_36 )
goto V_245;
return 0 ;
V_245:
F_98 ( V_4 ) ;
return V_36 ;
}
static int T_2 F_103 ( struct V_65 * V_66 )
{
struct V_92 * V_93 = V_66 -> V_40 . V_248 ;
struct V_3 * V_4 ;
int V_36 ;
V_4 = F_61 ( sizeof( * V_4 ) , V_249 ) ;
if ( ! V_4 ) {
F_7 ( L_46 ) ;
return - V_75 ;
}
F_104 ( V_66 , V_4 ) ;
V_4 -> V_66 = V_66 ;
V_4 -> V_40 = & V_66 -> V_40 ;
V_4 -> V_93 = V_93 ;
if ( V_93 -> V_250 ) {
V_36 = V_93 -> V_250 () ;
if ( V_36 )
goto V_251;
}
V_36 = F_41 ( V_4 ) ;
if ( V_36 )
goto V_252;
V_36 = F_46 ( V_4 ) ;
if ( V_36 )
goto V_253;
V_36 = F_100 ( V_4 ) ;
if ( V_36 )
goto V_253;
return 0 ;
V_253:
F_44 ( V_4 ) ;
V_251:
V_252:
F_104 ( V_66 , NULL ) ;
F_59 ( V_4 ) ;
return V_36 ;
}
static int T_8 F_105 ( struct V_65 * V_66 )
{
struct V_3 * V_4 = F_106 ( V_66 ) ;
F_98 ( V_4 ) ;
F_44 ( V_4 ) ;
F_104 ( V_66 , NULL ) ;
F_59 ( V_4 ) ;
return 0 ;
}
static int T_9 F_107 ( void )
{
int V_58 ;
V_58 = F_108 ( & V_254 ) ;
if ( V_58 == 0 )
F_109 ( V_255 L_47 ) ;
else
F_7 ( L_48 ) ;
return V_58 ;
}
static void T_8 F_110 ( void )
{
F_111 ( & V_254 ) ;
}
