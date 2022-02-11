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
static void F_38 ( struct V_3 * V_4 )
{
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ )
if ( V_4 -> V_33 [ V_88 ] ) {
F_39 ( V_4 -> V_33 [ V_88 ] ) ;
V_4 -> V_33 [ V_88 ] = NULL ;
}
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_67 * V_68 = V_4 -> V_68 ;
struct V_30 * V_30 ;
V_30 = F_41 ( & V_68 -> V_22 , L_12 ) ;
if ( ! V_30 ) {
F_17 ( L_13 ) ;
goto V_90;
}
V_4 -> V_33 [ 0 ] = V_30 ;
return 0 ;
V_90:
F_38 ( V_4 ) ;
return - V_23 ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_69 * V_72 = & V_4 -> V_69 ;
struct V_91 * V_91 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_92 ; V_88 ++ ) {
V_91 = V_72 -> clock [ V_88 ] ;
if ( V_91 ) {
F_43 ( V_91 ) ;
V_72 -> clock [ V_88 ] = NULL ;
}
}
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_69 * V_72 = & V_4 -> V_69 ;
char * * V_93 = NULL ;
struct V_91 * V_91 ;
int V_88 ;
V_72 -> clock [ 0 ] = F_45 ( V_4 -> V_22 , L_14 ) ;
if ( F_46 ( V_72 -> clock [ 0 ] ) )
goto V_94;
if ( F_9 ( V_4 ) )
V_93 = V_95 ;
if ( ! V_93 )
return 0 ;
for ( V_88 = 1 ; V_88 < V_92 ; V_88 ++ ) {
if ( V_93 [ V_88 - 1 ] == NULL )
break;
V_91 = F_45 ( V_4 -> V_22 , V_93 [ V_88 - 1 ] ) ;
if ( F_46 ( V_91 ) )
goto V_94;
V_72 -> clock [ V_88 ] = V_91 ;
}
if ( F_9 ( V_4 ) )
F_47 ( V_72 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_94:
F_48 ( V_4 -> V_22 , L_15 ) ;
F_42 ( V_4 ) ;
return - V_77 ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_96 * V_96 ;
int V_39 ;
V_39 = F_28 ( V_4 , V_78 ) ;
if ( V_39 )
goto V_97;
V_39 = F_28 ( V_4 , V_80 ) ;
if ( V_39 )
goto V_97;
V_39 = F_34 ( V_4 , F_1 ) ;
if ( V_39 )
goto V_97;
V_39 = F_40 ( V_4 ) ;
if ( V_39 )
goto V_98;
V_96 = F_50 ( & V_4 -> V_68 -> V_22 ) ;
if ( F_46 ( V_96 ) ) {
V_39 = F_51 ( V_96 ) ;
goto V_99;
}
V_39 = F_44 ( V_4 ) ;
if ( V_39 )
goto V_100;
return 0 ;
V_100:
V_99:
F_38 ( V_4 ) ;
V_98:
F_36 ( V_4 ) ;
V_97:
F_32 ( V_4 ) ;
return V_39 ;
}
static void F_52 ( struct V_3 * V_4 )
{
F_42 ( V_4 ) ;
F_32 ( V_4 ) ;
F_36 ( V_4 ) ;
F_38 ( V_4 ) ;
}
static int F_53 ( struct V_3 * V_4 )
{
int V_39 ;
struct V_101 V_102 = {
. V_103 = 80 ,
. V_104 = 60 ,
. V_105 = 25 ,
. V_106 = 6 ,
. V_107 = - 1 ,
. V_108 = - 1 ,
. V_109 = - 1 ,
} ;
V_39 = F_54 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_110 = V_102 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
void * V_111 , unsigned V_112 ,
void * V_113 , T_4 V_114 , unsigned V_115 ,
void * * V_116 , T_4 * V_117 )
{
struct V_118 * V_22 = V_4 -> V_22 ;
if ( F_56 ( V_111 ) ) {
T_4 V_119 ;
V_119 = F_57 ( V_22 , V_111 ,
V_112 , V_54 ) ;
if ( F_58 ( V_22 , V_119 ) ) {
if ( V_115 < V_112 ) {
F_17 ( L_16 ,
V_120 ) ;
return - V_77 ;
}
goto V_121;
}
* V_116 = V_111 ;
* V_117 = V_119 ;
V_4 -> V_40 = true ;
return 0 ;
}
V_121:
* V_116 = V_113 ;
* V_117 = V_114 ;
V_4 -> V_40 = false ;
return 0 ;
}
static inline void F_59 ( struct V_3 * V_4 ,
void * V_111 , unsigned V_112 ,
void * V_113 , T_4 V_114 , unsigned V_115 ,
void * V_122 , T_4 V_123 )
{
if ( V_4 -> V_40 )
F_60 ( V_4 -> V_22 , V_123 , V_112 , V_54 ) ;
}
static inline void F_61 ( struct V_3 * V_4 ,
void * V_111 , unsigned V_112 ,
void * V_113 , T_4 V_114 , unsigned V_115 ,
void * V_122 , T_4 V_123 )
{
if ( ! V_4 -> V_40 )
memcpy ( V_111 , V_113 , V_112 ) ;
}
static int F_62 ( struct V_3 * V_4 ,
const void * V_124 , unsigned V_112 ,
void * V_113 , T_4 V_114 , unsigned V_115 ,
const void * * V_116 , T_4 * V_117 )
{
struct V_118 * V_22 = V_4 -> V_22 ;
if ( F_56 ( V_124 ) ) {
T_4 V_125 ;
V_125 = F_57 ( V_22 , ( void * ) V_124 , V_112 ,
V_45 ) ;
if ( F_58 ( V_22 , V_125 ) ) {
if ( V_115 < V_112 ) {
F_17 ( L_16 ,
V_120 ) ;
return - V_77 ;
}
goto V_121;
}
* V_116 = V_124 ;
* V_117 = V_125 ;
return 0 ;
}
V_121:
memcpy ( V_113 , V_124 , V_112 ) ;
* V_116 = V_113 ;
* V_117 = V_114 ;
return 0 ;
}
static void F_63 ( struct V_3 * V_4 ,
const void * V_124 , unsigned V_112 ,
void * V_113 , T_4 V_114 , unsigned V_115 ,
const void * V_122 , T_4 V_123 )
{
struct V_118 * V_22 = V_4 -> V_22 ;
if ( V_122 == V_124 )
F_60 ( V_22 , V_123 , V_112 , V_45 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_118 * V_22 = V_4 -> V_22 ;
if ( V_4 -> V_126 && F_56 ( V_4 -> V_126 ) )
F_65 ( V_22 , V_4 -> V_127 ,
V_4 -> V_126 ,
V_4 -> V_128 ) ;
F_66 ( V_4 -> V_129 ) ;
F_66 ( V_4 -> V_43 ) ;
V_4 -> V_129 = NULL ;
V_4 -> V_43 = NULL ;
V_4 -> V_126 = NULL ;
V_4 -> V_127 = 0 ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_118 * V_22 = V_4 -> V_22 ;
V_4 -> V_129 = F_68 ( V_44 , V_130 | V_131 ) ;
if ( V_4 -> V_129 == NULL )
goto V_132;
V_4 -> V_43 = F_68 ( V_44 , V_130 | V_131 ) ;
if ( V_4 -> V_43 == NULL )
goto V_132;
V_4 -> V_127 = V_8 -> V_25 + V_8 -> V_26 ;
V_4 -> V_126 = F_69 ( V_22 , V_4 -> V_127 ,
& V_4 -> V_128 , V_130 ) ;
if ( ! V_4 -> V_126 )
goto V_132;
V_4 -> V_133 = V_4 -> V_126 ;
V_4 -> V_134 = V_4 -> V_128 ;
V_4 -> V_135 = V_4 -> V_133 + V_8 -> V_25 ;
V_4 -> V_136 = V_4 -> V_134 + V_8 -> V_25 ;
return 0 ;
V_132:
F_64 ( V_4 ) ;
F_17 ( L_17 ) ;
return - V_77 ;
}
static void F_70 ( struct V_9 * V_10 , int V_137 , unsigned int V_138 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
int V_39 ;
if ( ( V_138 & ( V_142 | V_143 ) ) ) {
if ( V_137 != V_144 )
V_4 -> V_129 [ V_4 -> V_145 ++ ] = V_137 ;
return;
}
if ( ! V_4 -> V_145 )
return;
V_39 = F_71 ( V_4 ) ;
if ( V_39 )
F_17 ( L_18 , V_4 -> V_32 , V_39 ) ;
V_4 -> V_145 = 0 ;
}
static int F_72 ( struct V_9 * V_10 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
return F_73 ( V_4 , V_4 -> V_32 ) ;
}
static void F_74 ( struct V_9 * V_10 , int V_31 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
if ( ( V_4 -> V_32 < 0 ) && ( V_31 >= 0 ) )
F_75 ( V_4 ) ;
else if ( ( V_4 -> V_32 >= 0 ) && ( V_31 < 0 ) )
F_76 ( V_4 ) ;
V_4 -> V_32 = V_31 ;
}
static void F_77 ( struct V_9 * V_10 , T_5 * V_146 , int V_147 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
F_78 ( L_19 , V_147 ) ;
V_4 -> V_41 = V_146 ;
V_4 -> V_42 = V_147 ;
F_79 ( V_4 ) ;
}
static void F_80 ( struct V_9 * V_10 , const T_5 * V_146 , int V_147 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
F_78 ( L_19 , V_147 ) ;
V_4 -> V_41 = ( T_5 * ) V_146 ;
V_4 -> V_42 = V_147 ;
F_81 ( V_4 ) ;
}
static T_5 F_82 ( struct V_9 * V_10 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
T_5 * V_146 = V_4 -> V_43 ;
F_77 ( V_10 , V_146 , 1 ) ;
return V_146 [ 0 ] ;
}
static void F_83 ( struct V_3 * V_4 ,
void * V_148 , void * V_149 )
{
struct V_7 * V_150 = & V_4 -> V_7 ;
unsigned char * V_73 ;
unsigned char * V_151 ;
unsigned int V_152 ;
unsigned char V_153 ;
unsigned char V_154 ;
unsigned char V_155 ;
if ( ! V_4 -> V_28 )
return;
V_152 = V_150 -> V_19 ;
V_73 = V_148 + V_150 -> V_29 ;
V_151 = V_149 ;
V_154 = ( V_73 [ 0 ] >> V_152 ) | ( V_73 [ 1 ] << ( 8 - V_152 ) ) ;
V_155 = V_151 [ 0 ] ;
V_151 [ 0 ] = V_154 ;
V_153 = ( 0x1 << V_152 ) - 1 ;
V_73 [ 0 ] = ( V_73 [ 0 ] & V_153 ) | ( V_155 << V_152 ) ;
V_153 = ~ 0 << V_152 ;
V_73 [ 1 ] = ( V_73 [ 1 ] & V_153 ) | ( V_155 >> ( 8 - V_152 ) ) ;
}
static int F_84 ( struct V_9 * V_10 , struct V_139 * V_140 ,
T_5 * V_146 , int V_156 , int V_157 )
{
struct V_3 * V_4 = V_140 -> V_141 ;
struct V_7 * V_150 = & V_4 -> V_7 ;
void * V_133 ;
T_4 V_134 ;
void * V_135 ;
T_4 V_136 ;
unsigned int V_88 ;
unsigned char * V_158 ;
unsigned int V_159 = 0 ;
int V_39 ;
F_78 ( L_20 , V_157 ) ;
V_39 = F_55 ( V_4 , V_146 , V_10 -> V_21 ,
V_4 -> V_133 , V_4 -> V_134 ,
V_150 -> V_25 ,
& V_133 , & V_134 ) ;
if ( V_39 ) {
F_17 ( L_21 ) ;
V_39 = - V_77 ;
return V_39 ;
}
V_135 = V_4 -> V_135 ;
V_136 = V_4 -> V_136 ;
V_39 = F_85 ( V_4 , V_134 , V_136 ) ;
F_59 ( V_4 , V_146 , V_10 -> V_21 ,
V_4 -> V_133 , V_4 -> V_134 ,
V_150 -> V_25 ,
V_133 , V_134 ) ;
if ( V_39 ) {
F_17 ( L_22 , V_39 ) ;
return V_39 ;
}
F_83 ( V_4 , V_133 , V_135 ) ;
V_158 = V_135 + V_150 -> V_27 ;
for ( V_88 = 0 ; V_88 < V_150 -> V_15 ; V_88 ++ , V_158 ++ ) {
if ( ( * V_158 == V_160 ) || ( * V_158 == V_161 ) )
continue;
if ( * V_158 == V_162 ) {
V_10 -> V_163 . V_164 ++ ;
continue;
}
V_10 -> V_163 . V_165 += * V_158 ;
V_159 = F_86 (unsigned int, max_bitflips, *status) ;
}
if ( V_156 ) {
memset ( V_140 -> V_166 , ~ 0 , V_10 -> V_12 ) ;
V_140 -> V_166 [ 0 ] = ( ( T_5 * ) V_135 ) [ 0 ] ;
}
F_61 ( V_4 , V_146 , V_10 -> V_21 ,
V_4 -> V_133 , V_4 -> V_134 ,
V_150 -> V_25 ,
V_133 , V_134 ) ;
return V_159 ;
}
static int F_87 ( struct V_9 * V_10 , struct V_139 * V_140 ,
const T_5 * V_146 , int V_156 )
{
struct V_3 * V_4 = V_140 -> V_141 ;
struct V_7 * V_150 = & V_4 -> V_7 ;
const void * V_133 ;
T_4 V_134 ;
const void * V_135 ;
T_4 V_136 ;
int V_39 ;
F_78 ( L_23 ) ;
if ( V_4 -> V_28 ) {
memcpy ( V_4 -> V_133 , V_146 , V_10 -> V_21 ) ;
V_133 = V_4 -> V_133 ;
V_134 = V_4 -> V_134 ;
memcpy ( V_4 -> V_135 , V_140 -> V_166 ,
V_150 -> V_26 ) ;
V_135 = V_4 -> V_135 ;
V_136 = V_4 -> V_136 ;
F_83 ( V_4 ,
( void * ) V_133 , ( void * ) V_135 ) ;
} else {
V_39 = F_62 ( V_4 ,
V_146 , V_10 -> V_21 ,
V_4 -> V_133 , V_4 -> V_134 ,
V_150 -> V_25 ,
& V_133 , & V_134 ) ;
if ( V_39 ) {
F_17 ( L_24 ) ;
return 0 ;
}
V_39 = F_62 ( V_4 ,
V_140 -> V_166 , V_10 -> V_12 ,
V_4 -> V_135 , V_4 -> V_136 ,
V_150 -> V_26 ,
& V_135 , & V_136 ) ;
if ( V_39 ) {
F_17 ( L_25 ) ;
goto V_167;
}
}
V_39 = F_88 ( V_4 , V_134 , V_136 ) ;
if ( V_39 )
F_17 ( L_26 , V_39 ) ;
if ( ! V_4 -> V_28 ) {
F_63 ( V_4 , V_140 -> V_166 , V_10 -> V_12 ,
V_4 -> V_135 , V_4 -> V_136 ,
V_150 -> V_26 ,
V_135 , V_136 ) ;
V_167:
F_63 ( V_4 , V_146 , V_10 -> V_21 ,
V_4 -> V_133 , V_4 -> V_134 ,
V_150 -> V_25 ,
V_133 , V_134 ) ;
}
return 0 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_139 * V_140 ,
int V_157 )
{
struct V_3 * V_4 = V_140 -> V_141 ;
F_78 ( L_27 , V_157 ) ;
memset ( V_140 -> V_166 , ~ 0 , V_10 -> V_12 ) ;
V_140 -> V_168 ( V_10 , V_169 , V_10 -> V_21 , V_157 ) ;
V_140 -> V_170 ( V_10 , V_140 -> V_166 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_28 ) {
V_140 -> V_168 ( V_10 , V_169 , 0 , V_157 ) ;
V_140 -> V_166 [ 0 ] = V_140 -> V_171 ( V_10 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_9 * V_10 , struct V_139 * V_140 , int V_157 )
{
return - V_172 ;
}
static int F_91 ( struct V_9 * V_10 , T_6 V_173 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
int V_174 , V_39 = 0 ;
T_5 * V_175 ;
int V_176 , V_157 , V_158 , V_31 ;
V_174 = ( int ) ( V_173 >> V_140 -> V_177 ) ;
if ( V_140 -> V_178 )
V_140 -> V_178 [ V_174 >> 2 ] |= 0x01 << ( ( V_174 & 0x03 ) << 1 ) ;
if ( V_140 -> V_179 & V_180 )
V_39 = F_92 ( V_10 , V_173 ) ;
else {
V_31 = ( int ) ( V_173 >> V_140 -> V_181 ) ;
V_140 -> V_182 ( V_10 , V_31 ) ;
V_176 = V_4 -> V_28 ? V_10 -> V_21 : 0 ;
V_175 = V_4 -> V_43 ;
V_175 [ 0 ] = 0 ;
V_157 = ( int ) ( V_173 >> V_140 -> V_183 ) ;
V_140 -> V_168 ( V_10 , V_184 , V_176 , V_157 ) ;
V_140 -> V_185 ( V_10 , V_175 , 1 ) ;
V_140 -> V_168 ( V_10 , V_186 , - 1 , - 1 ) ;
V_158 = V_140 -> V_187 ( V_10 , V_140 ) ;
if ( V_158 & V_188 )
V_39 = - V_189 ;
V_140 -> V_182 ( V_10 , - 1 ) ;
}
if ( ! V_39 )
V_10 -> V_163 . V_190 ++ ;
return V_39 ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_191 * V_192 = & V_4 -> V_193 ;
V_192 -> V_194 = 64 ;
V_192 -> V_195 = 2 ;
return 0 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_191 * V_196 = & V_4 -> V_193 ;
struct V_118 * V_22 = V_4 -> V_22 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_139 * V_140 = & V_4 -> V_197 ;
unsigned int V_198 ;
unsigned int V_199 ;
unsigned int V_157 ;
T_5 * V_200 = V_140 -> V_201 -> V_202 ;
int V_203 ;
int V_204 = false ;
V_198 = 1 << V_196 -> V_195 ;
V_203 = V_4 -> V_32 ;
V_140 -> V_182 ( V_10 , 0 ) ;
F_48 ( V_22 , L_28 ) ;
for ( V_199 = 0 ; V_199 < V_198 ; V_199 ++ ) {
V_157 = V_199 * V_196 -> V_194 ;
F_48 ( V_22 , L_29 , V_157 ) ;
V_140 -> V_168 ( V_10 , V_169 , 12 , V_157 ) ;
V_140 -> V_170 ( V_10 , V_200 , strlen ( V_205 ) ) ;
if ( ! memcmp ( V_200 , V_205 , strlen ( V_205 ) ) ) {
V_204 = true ;
break;
}
}
V_140 -> V_182 ( V_10 , V_203 ) ;
if ( V_204 )
F_48 ( V_22 , L_30 ) ;
else
F_48 ( V_22 , L_31 ) ;
return V_204 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_118 * V_22 = V_4 -> V_22 ;
struct V_191 * V_196 = & V_4 -> V_193 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_139 * V_140 = & V_4 -> V_197 ;
unsigned int V_206 ;
unsigned int V_198 ;
unsigned int V_207 ;
unsigned int V_208 ;
unsigned int V_174 ;
unsigned int V_199 ;
unsigned int V_157 ;
T_5 * V_200 = V_140 -> V_201 -> V_202 ;
int V_203 ;
int V_158 ;
V_206 = V_10 -> V_209 / V_10 -> V_21 ;
V_198 = 1 << V_196 -> V_195 ;
V_207 = V_198 *
V_196 -> V_194 ;
V_208 =
( V_207 + ( V_206 - 1 ) ) /
V_206 ;
F_48 ( V_22 , L_32 ) ;
F_48 ( V_22 , L_33 , V_208 ) ;
F_48 ( V_22 , L_34 , V_198 ) ;
F_48 ( V_22 , L_35 , V_207 ) ;
V_203 = V_4 -> V_32 ;
V_140 -> V_182 ( V_10 , 0 ) ;
F_48 ( V_22 , L_36 ) ;
for ( V_174 = 0 ; V_174 < V_208 ; V_174 ++ ) {
V_157 = V_174 * V_206 ;
F_48 ( V_22 , L_37 , V_174 ) ;
V_140 -> V_168 ( V_10 , V_210 , - 1 , V_157 ) ;
V_140 -> V_168 ( V_10 , V_211 , - 1 , - 1 ) ;
V_158 = V_140 -> V_187 ( V_10 , V_140 ) ;
if ( V_158 & V_188 )
F_11 ( V_22 , L_38 , V_120 ) ;
}
memset ( V_200 , ~ 0 , V_10 -> V_21 ) ;
memset ( V_140 -> V_166 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_200 + 12 , V_205 , strlen ( V_205 ) ) ;
F_48 ( V_22 , L_39 ) ;
for ( V_199 = 0 ; V_199 < V_198 ; V_199 ++ ) {
V_157 = V_199 * V_196 -> V_194 ;
F_48 ( V_22 , L_40 , V_157 ) ;
V_140 -> V_168 ( V_10 , V_184 , 0x00 , V_157 ) ;
V_140 -> V_212 . V_213 ( V_10 , V_140 , V_200 , 0 ) ;
V_140 -> V_168 ( V_10 , V_186 , - 1 , - 1 ) ;
V_158 = V_140 -> V_187 ( V_10 , V_140 ) ;
if ( V_158 & V_188 )
F_11 ( V_22 , L_41 , V_120 ) ;
}
V_140 -> V_182 ( V_10 , V_203 ) ;
return 0 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_118 * V_22 = V_4 -> V_22 ;
struct V_139 * V_140 = & V_4 -> V_197 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_214 ;
unsigned int V_174 ;
int V_31 ;
int V_157 ;
T_6 V_215 ;
T_5 V_175 ;
int V_39 = 0 ;
if ( F_94 ( V_4 ) )
return 0 ;
F_48 ( V_22 , L_42 ) ;
V_214 = V_140 -> V_216 >> V_140 -> V_217 ;
for ( V_174 = 0 ; V_174 < V_214 ; V_174 ++ ) {
V_31 = V_174 >> ( V_140 -> V_181 - V_140 -> V_217 ) ;
V_157 = V_174 << ( V_140 -> V_217 - V_140 -> V_183 ) ;
V_215 = V_174 << V_140 -> V_217 ;
V_140 -> V_182 ( V_10 , V_31 ) ;
V_140 -> V_168 ( V_10 , V_169 , V_10 -> V_21 , V_157 ) ;
V_175 = V_140 -> V_171 ( V_10 ) ;
V_140 -> V_182 ( V_10 , - 1 ) ;
if ( V_175 != 0xff ) {
F_48 ( V_22 , L_43 , V_174 ) ;
V_39 = V_140 -> V_218 ( V_10 , V_215 ) ;
if ( V_39 )
F_11 ( V_22 , L_44
L_45 , V_39 ) ;
}
}
F_95 ( V_4 ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_4 )
{
F_93 ( V_4 ) ;
if ( F_7 ( V_4 ) )
return F_96 ( V_4 ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
int V_39 ;
F_64 ( V_4 ) ;
V_39 = F_99 ( V_4 ) ;
if ( V_39 ) {
F_17 ( L_46 , V_39 ) ;
return V_39 ;
}
return F_67 ( V_4 ) ;
}
static int F_100 ( struct V_3 * V_4 )
{
int V_39 ;
if ( F_7 ( V_4 ) )
V_4 -> V_28 = false ;
else
V_4 -> V_28 = true ;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_197 . V_212 . V_219 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_11 = V_4 -> V_7 . V_11 ;
V_4 -> V_10 . V_220 = V_4 -> V_7 . V_11 ;
return F_97 ( V_4 ) ;
}
static int F_101 ( struct V_9 * V_10 )
{
struct V_139 * V_140 = V_10 -> V_141 ;
struct V_3 * V_4 = V_140 -> V_141 ;
int V_39 ;
V_39 = F_100 ( V_4 ) ;
if ( V_39 )
return V_39 ;
F_102 ( V_4 ) ;
return F_103 ( V_10 ) ;
}
static void F_104 ( struct V_3 * V_4 )
{
F_105 ( & V_4 -> V_10 ) ;
F_64 ( V_4 ) ;
}
static int F_106 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_139 * V_140 = & V_4 -> V_197 ;
struct V_221 V_222 = {} ;
int V_39 ;
V_4 -> V_32 = - 1 ;
V_10 -> V_141 = V_140 ;
V_10 -> V_223 = L_47 ;
V_10 -> V_224 = V_225 ;
V_140 -> V_141 = V_4 ;
V_140 -> V_182 = F_74 ;
V_140 -> V_226 = F_70 ;
V_140 -> V_227 = F_72 ;
V_140 -> V_171 = F_82 ;
V_140 -> V_170 = F_77 ;
V_140 -> V_185 = F_80 ;
V_140 -> V_212 . V_228 = F_84 ;
V_140 -> V_212 . V_229 = F_87 ;
V_140 -> V_212 . V_230 = F_89 ;
V_140 -> V_212 . V_231 = F_90 ;
V_140 -> V_232 = F_101 ;
V_140 -> V_233 = & V_234 ;
V_140 -> V_218 = F_91 ;
V_140 -> V_235 |= V_236 ;
V_140 -> V_212 . V_237 = V_238 ;
V_140 -> V_212 . V_239 = 1 ;
V_140 -> V_212 . V_219 = 8 ;
V_140 -> V_212 . V_240 = & V_241 ;
if ( F_107 ( V_4 -> V_22 -> V_242 ) )
V_140 -> V_179 |= V_180 | V_243 ;
V_4 -> V_7 . V_25 = 1024 ;
V_4 -> V_7 . V_26 = 128 ;
V_39 = F_67 ( V_4 ) ;
if ( V_39 )
goto V_244;
V_39 = F_108 ( V_10 , 1 ) ;
if ( V_39 ) {
F_17 ( L_48 ) ;
goto V_244;
}
V_222 . V_242 = V_4 -> V_68 -> V_22 . V_242 ;
V_39 = F_109 ( V_10 , NULL , & V_222 , NULL , 0 ) ;
if ( V_39 )
goto V_244;
return 0 ;
V_244:
F_104 ( V_4 ) ;
return V_39 ;
}
static int F_110 ( struct V_67 * V_68 )
{
struct V_3 * V_4 ;
const struct V_245 * V_246 ;
int V_39 ;
V_246 = F_111 ( V_247 , & V_68 -> V_22 ) ;
if ( V_246 ) {
V_68 -> V_248 = V_246 -> V_137 ;
} else {
F_17 ( L_49 ) ;
return - V_77 ;
}
V_4 = F_68 ( sizeof( * V_4 ) , V_131 ) ;
if ( ! V_4 ) {
F_17 ( L_50 ) ;
return - V_77 ;
}
F_112 ( V_68 , V_4 ) ;
V_4 -> V_68 = V_68 ;
V_4 -> V_22 = & V_68 -> V_22 ;
V_39 = F_49 ( V_4 ) ;
if ( V_39 )
goto V_249;
V_39 = F_53 ( V_4 ) ;
if ( V_39 )
goto V_250;
V_39 = F_106 ( V_4 ) ;
if ( V_39 )
goto V_250;
F_113 ( V_4 -> V_22 , L_51 ) ;
return 0 ;
V_250:
F_52 ( V_4 ) ;
V_249:
F_112 ( V_68 , NULL ) ;
F_11 ( V_4 -> V_22 , L_52 , V_39 ) ;
F_66 ( V_4 ) ;
return V_39 ;
}
static int F_114 ( struct V_67 * V_68 )
{
struct V_3 * V_4 = F_115 ( V_68 ) ;
F_104 ( V_4 ) ;
F_52 ( V_4 ) ;
F_112 ( V_68 , NULL ) ;
F_66 ( V_4 ) ;
return 0 ;
}
