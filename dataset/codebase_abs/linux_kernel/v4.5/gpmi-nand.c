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
struct V_9 * V_10 = F_5 ( & V_4 -> V_11 ) ;
int V_12 ;
V_12 = ( ( V_10 -> V_13 - V_8 -> V_14 ) * 8 )
/ ( V_8 -> V_15 * V_8 -> V_16 ) ;
return F_6 ( V_12 , 2 ) ;
}
static inline bool F_7 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
if ( F_8 ( V_4 ) || F_9 ( V_4 ) ) {
if ( V_8 -> V_15 == 14 )
return false ;
}
return V_8 -> V_12 <= V_4 -> V_17 -> V_18 ;
}
static bool F_10 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_19 * V_20 = & V_4 -> V_11 ;
struct V_9 * V_10 = F_5 ( V_20 ) ;
struct V_21 * V_22 = V_23 . V_24 ;
unsigned int V_25 ;
if ( ! ( V_20 -> V_26 > 0 && V_20 -> V_27 > 0 ) )
return false ;
switch ( V_20 -> V_27 ) {
case V_28 :
V_8 -> V_15 = 13 ;
break;
case V_29 :
V_8 -> V_15 = 14 ;
break;
default:
F_11 ( V_4 -> V_30 ,
L_1 ,
V_20 -> V_26 , V_20 -> V_27 ) ;
return false ;
}
V_8 -> V_31 = V_20 -> V_27 ;
V_8 -> V_12 = F_12 ( V_20 -> V_26 , 2 ) ;
if ( ! F_7 ( V_4 ) )
return false ;
if ( V_8 -> V_31 < V_10 -> V_13 ) {
F_11 ( V_4 -> V_30 ,
L_2 ,
V_20 -> V_27 , V_10 -> V_13 ) ;
return false ;
}
V_8 -> V_14 = 10 ;
V_8 -> V_16 = V_10 -> V_32 / V_8 -> V_31 ;
V_8 -> V_33 = V_10 -> V_32 + V_8 -> V_14 +
( V_8 -> V_15 * V_8 -> V_12 * V_8 -> V_16 ) / 8 ;
if ( V_8 -> V_33 < V_10 -> V_32 + V_10 -> V_13 ) {
V_22 -> V_34 = V_8 -> V_33 - V_10 -> V_32 ;
V_22 -> V_35 = V_10 -> V_13 - V_22 -> V_34 ;
}
V_8 -> V_36 = V_10 -> V_32 ;
V_8 -> V_37 = F_13 ( V_8 -> V_14 , 4 ) ;
V_8 -> V_38 = F_13 ( V_8 -> V_14 , 4 )
+ F_13 ( V_8 -> V_16 , 4 ) ;
if ( ! V_4 -> V_39 )
return true ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_12 * V_8 -> V_15 * ( V_8 -> V_16 - 1 )
+ V_8 -> V_14 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return true ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = F_5 ( & V_4 -> V_11 ) ;
unsigned int V_14 ;
unsigned int V_41 ;
unsigned int V_25 ;
V_8 -> V_14 = 10 ;
V_8 -> V_15 = 13 ;
V_8 -> V_31 = 512 ;
while ( V_8 -> V_31 < V_10 -> V_13 ) {
V_8 -> V_31 *= 2 ;
V_8 -> V_15 = 14 ;
}
V_8 -> V_16 = V_10 -> V_32 / V_8 -> V_31 ;
V_8 -> V_12 = F_4 ( V_4 ) ;
if ( ! F_7 ( V_4 ) ) {
F_11 ( V_4 -> V_30 ,
L_3 ,
V_8 -> V_12 ,
V_4 -> V_17 -> V_18 ) ;
return - V_42 ;
}
V_8 -> V_33 = V_10 -> V_32 + V_10 -> V_13 ;
V_8 -> V_36 = V_10 -> V_32 ;
V_14 = F_13 ( V_8 -> V_14 , 4 ) ;
V_41 = F_13 ( V_8 -> V_16 , 4 ) ;
V_8 -> V_38 = V_14 + V_41 ;
V_8 -> V_37 = V_14 ;
if ( ! V_4 -> V_39 )
return 0 ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_12 * V_8 -> V_15 * ( V_8 -> V_16 - 1 )
+ V_8 -> V_14 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 )
{
if ( F_16 ( V_4 -> V_30 -> V_43 , L_4 )
&& F_10 ( V_4 ) )
return 0 ;
return F_14 ( V_4 ) ;
}
struct V_44 * F_17 ( struct V_3 * V_4 )
{
return V_4 -> V_45 [ 0 ] ;
}
void F_18 ( struct V_3 * V_4 , enum V_46 V_47 )
{
struct V_48 * V_49 = & V_4 -> V_50 ;
int V_51 ;
if ( F_19 ( V_4 -> V_52 ) &&
! F_20 ( V_4 -> V_52 ) ) {
F_21 ( V_49 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_51 = F_22 ( V_4 -> V_30 , V_49 , 1 , V_47 ) ;
if ( V_51 == 0 )
goto V_54;
V_4 -> V_55 = true ;
return;
}
V_54:
F_21 ( V_49 , V_4 -> V_56 , V_4 -> V_53 ) ;
if ( V_47 == V_57 )
memcpy ( V_4 -> V_56 , V_4 -> V_52 , V_4 -> V_53 ) ;
F_22 ( V_4 -> V_30 , V_49 , 1 , V_47 ) ;
V_4 -> V_55 = false ;
}
static void F_23 ( void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_59 * V_60 = & V_4 -> V_61 ;
switch ( V_4 -> V_62 ) {
case V_63 :
F_24 ( V_4 -> V_30 , & V_4 -> V_64 , 1 , V_57 ) ;
break;
case V_65 :
F_24 ( V_4 -> V_30 , & V_4 -> V_50 , 1 , V_66 ) ;
if ( V_4 -> V_55 == false )
memcpy ( V_4 -> V_52 , V_4 -> V_56 ,
V_4 -> V_53 ) ;
break;
case V_67 :
F_24 ( V_4 -> V_30 , & V_4 -> V_50 , 1 , V_57 ) ;
break;
case V_68 :
case V_69 :
break;
default:
F_11 ( V_4 -> V_30 , L_5 ) ;
}
F_3 ( V_60 ) ;
}
int F_25 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_59 * V_60 = & V_4 -> V_61 ;
unsigned long V_72 ;
F_26 ( V_60 ) ;
V_71 -> V_73 = F_23 ;
V_71 -> V_74 = V_4 ;
F_27 ( V_71 ) ;
F_28 ( F_17 ( V_4 ) ) ;
V_72 = F_29 ( V_60 , F_30 ( 1000 ) ) ;
if ( ! V_72 ) {
F_11 ( V_4 -> V_30 , L_6 ,
V_4 -> V_75 ) ;
F_31 ( V_4 ) ;
return - V_76 ;
}
return 0 ;
}
int F_32 ( struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_59 * V_77 = & V_4 -> V_5 ;
unsigned long V_72 ;
F_26 ( V_77 ) ;
F_25 ( V_4 , V_71 ) ;
V_72 = F_29 ( V_77 , F_30 ( 1000 ) ) ;
if ( ! V_72 ) {
F_11 ( V_4 -> V_30 , L_7 ,
V_4 -> V_75 ) ;
F_31 ( V_4 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_33 ( struct V_3 * V_4 ,
const char * V_78 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
struct V_81 * V_82 = & V_4 -> V_81 ;
struct V_83 * V_84 ;
void T_2 * V_85 ;
V_84 = F_34 ( V_80 , V_86 , V_78 ) ;
V_85 = F_35 ( & V_80 -> V_30 , V_84 ) ;
if ( F_36 ( V_85 ) )
return F_37 ( V_85 ) ;
if ( ! strcmp ( V_78 , V_87 ) )
V_82 -> V_88 = V_85 ;
else if ( ! strcmp ( V_78 , V_89 ) )
V_82 -> V_90 = V_85 ;
else
F_11 ( V_4 -> V_30 , L_8 , V_78 ) ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , T_3 V_91 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
const char * V_78 = V_92 ;
struct V_83 * V_84 ;
int V_93 ;
V_84 = F_34 ( V_80 , V_94 , V_78 ) ;
if ( ! V_84 ) {
F_11 ( V_4 -> V_30 , L_9 , V_78 ) ;
return - V_95 ;
}
V_93 = F_39 ( V_4 -> V_30 , V_84 -> V_96 , V_91 , 0 , V_78 , V_4 ) ;
if ( V_93 )
F_11 ( V_4 -> V_30 , L_10 ) ;
return V_93 ;
}
static void F_40 ( struct V_3 * V_4 )
{
unsigned int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ )
if ( V_4 -> V_45 [ V_97 ] ) {
F_41 ( V_4 -> V_45 [ V_97 ] ) ;
V_4 -> V_45 [ V_97 ] = NULL ;
}
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_79 * V_80 = V_4 -> V_80 ;
struct V_44 * V_44 ;
V_44 = F_43 ( & V_80 -> V_30 , L_11 ) ;
if ( ! V_44 ) {
F_11 ( V_4 -> V_30 , L_12 ) ;
goto V_99;
}
V_4 -> V_45 [ 0 ] = V_44 ;
return 0 ;
V_99:
F_40 ( V_4 ) ;
return - V_42 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_81 * V_84 = & V_4 -> V_81 ;
char * * V_100 = NULL ;
struct V_101 * V_101 ;
int V_93 , V_97 ;
V_84 -> clock [ 0 ] = F_45 ( V_4 -> V_30 , L_13 ) ;
if ( F_36 ( V_84 -> clock [ 0 ] ) ) {
V_93 = F_37 ( V_84 -> clock [ 0 ] ) ;
goto V_102;
}
if ( F_46 ( V_4 ) )
V_100 = V_103 ;
if ( ! V_100 )
return 0 ;
for ( V_97 = 1 ; V_97 < V_104 ; V_97 ++ ) {
if ( V_100 [ V_97 - 1 ] == NULL )
break;
V_101 = F_45 ( V_4 -> V_30 , V_100 [ V_97 - 1 ] ) ;
if ( F_36 ( V_101 ) ) {
V_93 = F_37 ( V_101 ) ;
goto V_102;
}
V_84 -> clock [ V_97 ] = V_101 ;
}
if ( F_46 ( V_4 ) )
F_47 ( V_84 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_102:
F_48 ( V_4 -> V_30 , L_14 ) ;
return V_93 ;
}
static int F_49 ( struct V_3 * V_4 )
{
int V_51 ;
V_51 = F_33 ( V_4 , V_87 ) ;
if ( V_51 )
goto V_105;
V_51 = F_33 ( V_4 , V_89 ) ;
if ( V_51 )
goto V_105;
V_51 = F_38 ( V_4 , F_1 ) ;
if ( V_51 )
goto V_105;
V_51 = F_42 ( V_4 ) ;
if ( V_51 )
goto V_105;
V_51 = F_44 ( V_4 ) ;
if ( V_51 )
goto V_106;
return 0 ;
V_106:
F_40 ( V_4 ) ;
V_105:
return V_51 ;
}
static void F_50 ( struct V_3 * V_4 )
{
F_40 ( V_4 ) ;
}
static int F_51 ( struct V_3 * V_4 )
{
int V_51 ;
struct V_107 V_108 = {
. V_109 = 80 ,
. V_110 = 60 ,
. V_111 = 25 ,
. V_112 = 6 ,
. V_113 = - 1 ,
. V_114 = - 1 ,
. V_115 = - 1 ,
} ;
V_51 = F_52 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_4 -> V_116 = V_108 ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
void * V_117 , unsigned V_35 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
void * * V_121 , T_4 * V_122 )
{
struct V_123 * V_30 = V_4 -> V_30 ;
if ( F_19 ( V_117 ) ) {
T_4 V_124 ;
V_124 = F_54 ( V_30 , V_117 ,
V_35 , V_66 ) ;
if ( F_55 ( V_30 , V_124 ) ) {
if ( V_120 < V_35 ) {
F_11 ( V_30 , L_15 ) ;
return - V_125 ;
}
goto V_126;
}
* V_121 = V_117 ;
* V_122 = V_124 ;
V_4 -> V_55 = true ;
return 0 ;
}
V_126:
* V_121 = V_118 ;
* V_122 = V_119 ;
V_4 -> V_55 = false ;
return 0 ;
}
static inline void F_56 ( struct V_3 * V_4 ,
void * V_117 , unsigned V_35 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
void * V_127 , T_4 V_128 )
{
if ( V_4 -> V_55 )
F_57 ( V_4 -> V_30 , V_128 , V_35 , V_66 ) ;
}
static inline void F_58 ( struct V_3 * V_4 ,
void * V_117 , unsigned V_35 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
void * V_127 , T_4 V_128 )
{
if ( ! V_4 -> V_55 )
memcpy ( V_117 , V_118 , V_35 ) ;
}
static int F_59 ( struct V_3 * V_4 ,
const void * V_129 , unsigned V_35 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
const void * * V_121 , T_4 * V_122 )
{
struct V_123 * V_30 = V_4 -> V_30 ;
if ( F_19 ( V_129 ) ) {
T_4 V_130 ;
V_130 = F_54 ( V_30 , ( void * ) V_129 , V_35 ,
V_57 ) ;
if ( F_55 ( V_30 , V_130 ) ) {
if ( V_120 < V_35 ) {
F_11 ( V_30 , L_15 ) ;
return - V_125 ;
}
goto V_126;
}
* V_121 = V_129 ;
* V_122 = V_130 ;
return 0 ;
}
V_126:
memcpy ( V_118 , V_129 , V_35 ) ;
* V_121 = V_118 ;
* V_122 = V_119 ;
return 0 ;
}
static void F_60 ( struct V_3 * V_4 ,
const void * V_129 , unsigned V_35 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
const void * V_127 , T_4 V_128 )
{
struct V_123 * V_30 = V_4 -> V_30 ;
if ( V_127 == V_129 )
F_57 ( V_30 , V_128 , V_35 , V_57 ) ;
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_123 * V_30 = V_4 -> V_30 ;
if ( V_4 -> V_131 && F_19 ( V_4 -> V_131 ) )
F_62 ( V_30 , V_4 -> V_132 ,
V_4 -> V_131 ,
V_4 -> V_133 ) ;
F_63 ( V_4 -> V_134 ) ;
F_63 ( V_4 -> V_56 ) ;
F_63 ( V_4 -> V_135 ) ;
V_4 -> V_134 = NULL ;
V_4 -> V_56 = NULL ;
V_4 -> V_131 = NULL ;
V_4 -> V_132 = 0 ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_123 * V_30 = V_4 -> V_30 ;
struct V_9 * V_10 = F_5 ( & V_4 -> V_11 ) ;
V_4 -> V_134 = F_65 ( V_136 , V_137 | V_138 ) ;
if ( V_4 -> V_134 == NULL )
goto V_139;
V_4 -> V_56 = F_65 ( V_10 -> V_32 ? : V_136 ,
V_137 | V_138 ) ;
if ( V_4 -> V_56 == NULL )
goto V_139;
V_4 -> V_132 = V_8 -> V_36 + V_8 -> V_38 ;
V_4 -> V_131 = F_66 ( V_30 , V_4 -> V_132 ,
& V_4 -> V_133 , V_137 ) ;
if ( ! V_4 -> V_131 )
goto V_139;
V_4 -> V_135 = F_65 ( V_10 -> V_32 + V_10 -> V_13 , V_138 ) ;
if ( ! V_4 -> V_135 )
goto V_139;
V_4 -> V_140 = V_4 -> V_131 ;
V_4 -> V_141 = V_4 -> V_133 ;
V_4 -> V_142 = V_4 -> V_140 + V_8 -> V_36 ;
V_4 -> V_143 = V_4 -> V_141 + V_8 -> V_36 ;
return 0 ;
V_139:
F_61 ( V_4 ) ;
return - V_125 ;
}
static void F_67 ( struct V_9 * V_10 , int V_144 , unsigned int V_145 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
int V_51 ;
if ( ( V_145 & ( V_146 | V_147 ) ) ) {
if ( V_144 != V_148 )
V_4 -> V_134 [ V_4 -> V_149 ++ ] = V_144 ;
return;
}
if ( ! V_4 -> V_149 )
return;
V_51 = F_70 ( V_4 ) ;
if ( V_51 )
F_11 ( V_4 -> V_30 , L_16 ,
V_4 -> V_150 , V_51 ) ;
V_4 -> V_149 = 0 ;
}
static int F_71 ( struct V_9 * V_10 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
return F_72 ( V_4 , V_4 -> V_150 ) ;
}
static void F_73 ( struct V_9 * V_10 , int V_151 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
if ( ( V_4 -> V_150 < 0 ) && ( V_151 >= 0 ) )
F_74 ( V_4 ) ;
else if ( ( V_4 -> V_150 >= 0 ) && ( V_151 < 0 ) )
F_75 ( V_4 ) ;
V_4 -> V_150 = V_151 ;
}
static void F_76 ( struct V_9 * V_10 , T_5 * V_152 , int V_153 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
F_48 ( V_4 -> V_30 , L_17 , V_153 ) ;
V_4 -> V_52 = V_152 ;
V_4 -> V_53 = V_153 ;
F_77 ( V_4 ) ;
}
static void F_78 ( struct V_9 * V_10 , const T_5 * V_152 , int V_153 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
F_48 ( V_4 -> V_30 , L_17 , V_153 ) ;
V_4 -> V_52 = ( T_5 * ) V_152 ;
V_4 -> V_53 = V_153 ;
F_79 ( V_4 ) ;
}
static T_5 F_80 ( struct V_9 * V_10 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
T_5 * V_152 = V_4 -> V_56 ;
F_76 ( V_10 , V_152 , 1 ) ;
return V_152 [ 0 ] ;
}
static void F_81 ( struct V_3 * V_4 ,
void * V_154 , void * V_155 )
{
struct V_7 * V_156 = & V_4 -> V_7 ;
unsigned char * V_85 ;
unsigned char * V_157 ;
unsigned int V_158 ;
unsigned char V_159 ;
unsigned char V_160 ;
unsigned char V_161 ;
if ( ! V_4 -> V_39 )
return;
V_158 = V_156 -> V_25 ;
V_85 = V_154 + V_156 -> V_40 ;
V_157 = V_155 ;
V_160 = ( V_85 [ 0 ] >> V_158 ) | ( V_85 [ 1 ] << ( 8 - V_158 ) ) ;
V_161 = V_157 [ 0 ] ;
V_157 [ 0 ] = V_160 ;
V_159 = ( 0x1 << V_158 ) - 1 ;
V_85 [ 0 ] = ( V_85 [ 0 ] & V_159 ) | ( V_161 << V_158 ) ;
V_159 = ~ 0 << V_158 ;
V_85 [ 1 ] = ( V_85 [ 1 ] & V_159 ) | ( V_161 >> ( 8 - V_158 ) ) ;
}
static int F_82 ( struct V_9 * V_10 , struct V_19 * V_20 ,
T_5 * V_152 , int V_162 , int V_163 )
{
struct V_3 * V_4 = F_69 ( V_20 ) ;
struct V_7 * V_156 = & V_4 -> V_7 ;
void * V_140 ;
T_4 V_141 ;
void * V_142 ;
T_4 V_143 ;
unsigned int V_97 ;
unsigned char * V_164 ;
unsigned int V_165 = 0 ;
int V_51 ;
F_48 ( V_4 -> V_30 , L_18 , V_163 ) ;
V_51 = F_53 ( V_4 , V_152 , V_156 -> V_36 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_156 -> V_36 ,
& V_140 , & V_141 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_19 ) ;
V_51 = - V_125 ;
return V_51 ;
}
V_142 = V_4 -> V_142 ;
V_143 = V_4 -> V_143 ;
V_51 = F_83 ( V_4 , V_141 , V_143 ) ;
F_56 ( V_4 , V_152 , V_156 -> V_36 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_156 -> V_36 ,
V_140 , V_141 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_20 , V_51 ) ;
return V_51 ;
}
F_81 ( V_4 , V_140 , V_142 ) ;
V_164 = V_142 + V_156 -> V_37 ;
for ( V_97 = 0 ; V_97 < V_156 -> V_16 ; V_97 ++ , V_164 ++ ) {
if ( ( * V_164 == V_166 ) || ( * V_164 == V_167 ) )
continue;
if ( * V_164 == V_168 ) {
V_10 -> V_169 . V_170 ++ ;
continue;
}
V_10 -> V_169 . V_171 += * V_164 ;
V_165 = F_84 (unsigned int, max_bitflips, *status) ;
}
if ( V_162 ) {
memset ( V_20 -> V_172 , ~ 0 , V_10 -> V_13 ) ;
V_20 -> V_172 [ 0 ] = ( ( T_5 * ) V_142 ) [ 0 ] ;
}
F_58 ( V_4 , V_152 , V_156 -> V_36 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_156 -> V_36 ,
V_140 , V_141 ) ;
return V_165 ;
}
static int F_85 ( struct V_9 * V_10 , struct V_19 * V_20 ,
T_6 V_173 , T_6 V_153 , T_5 * V_152 , int V_163 )
{
struct V_3 * V_4 = F_69 ( V_20 ) ;
void T_2 * V_90 = V_4 -> V_81 . V_90 ;
struct V_7 V_174 = V_4 -> V_7 ;
struct V_7 * V_8 = & V_4 -> V_7 ;
int V_175 = V_20 -> V_176 . V_175 ;
int V_177 , V_178 , V_33 ;
T_7 V_179 , V_180 , V_181 , V_182 ;
unsigned int V_165 ;
int V_183 , V_184 , V_185 ;
int V_186 ;
int V_187 = 0 ;
int V_188 = V_4 -> V_39 ;
V_186 = V_8 -> V_15 * V_8 -> V_12 / 8 ;
V_183 = V_173 / V_175 ;
V_184 = ( V_173 + V_153 - 1 ) / V_175 ;
if ( V_4 -> V_39 ) {
V_185 = V_8 -> V_40 / V_175 ;
if ( V_184 >= V_185 && V_183 <= V_185 ) {
F_48 ( V_4 -> V_30 ,
L_21 ,
V_163 , V_183 , V_184 , V_185 ) ;
return F_82 ( V_10 , V_20 , V_152 , 0 , V_163 ) ;
}
}
V_177 = V_8 -> V_14 ;
if ( V_183 ) {
V_187 = V_177 + ( V_175 + V_186 ) * V_183 ;
V_20 -> V_189 ( V_10 , V_190 , V_187 , - 1 ) ;
V_177 = 0 ;
V_152 = V_152 + V_183 * V_175 ;
}
V_179 = V_181 = F_86 ( V_90 + V_191 ) ;
V_180 = V_182 = F_86 ( V_90 + V_192 ) ;
V_178 = V_184 - V_183 + 1 ;
V_33 = V_177 + ( V_175 + V_186 ) * V_178 ;
V_181 &= ~ ( V_193 |
V_194 ) ;
V_181 |= F_87 ( V_178 - 1 )
| F_88 ( V_177 ) ;
F_89 ( V_181 , V_90 + V_191 ) ;
V_182 &= ~ V_195 ;
V_182 |= F_90 ( V_33 ) ;
F_89 ( V_182 , V_90 + V_192 ) ;
V_8 -> V_16 = V_178 ;
V_8 -> V_36 = V_178 * V_175 ;
V_8 -> V_33 = V_33 ;
V_8 -> V_37 = F_13 ( V_177 , 4 ) ;
F_48 ( V_4 -> V_30 , L_22 ,
V_163 , V_173 , V_153 , V_187 , V_183 , V_178 , V_33 ) ;
V_4 -> V_39 = false ;
V_165 = F_82 ( V_10 , V_20 , V_152 , 0 , V_163 ) ;
F_89 ( V_179 , V_90 + V_191 ) ;
F_89 ( V_180 , V_90 + V_192 ) ;
V_4 -> V_7 = V_174 ;
V_4 -> V_39 = V_188 ;
return V_165 ;
}
static int F_91 ( struct V_9 * V_10 , struct V_19 * V_20 ,
const T_5 * V_152 , int V_162 , int V_163 )
{
struct V_3 * V_4 = F_69 ( V_20 ) ;
struct V_7 * V_156 = & V_4 -> V_7 ;
const void * V_140 ;
T_4 V_141 ;
const void * V_142 ;
T_4 V_143 ;
int V_51 ;
F_48 ( V_4 -> V_30 , L_23 ) ;
if ( V_4 -> V_39 ) {
memcpy ( V_4 -> V_140 , V_152 , V_10 -> V_32 ) ;
V_140 = V_4 -> V_140 ;
V_141 = V_4 -> V_141 ;
memcpy ( V_4 -> V_142 , V_20 -> V_172 ,
V_156 -> V_38 ) ;
V_142 = V_4 -> V_142 ;
V_143 = V_4 -> V_143 ;
F_81 ( V_4 ,
( void * ) V_140 , ( void * ) V_142 ) ;
} else {
V_51 = F_59 ( V_4 ,
V_152 , V_10 -> V_32 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_156 -> V_36 ,
& V_140 , & V_141 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_24 ) ;
return 0 ;
}
V_51 = F_59 ( V_4 ,
V_20 -> V_172 , V_10 -> V_13 ,
V_4 -> V_142 , V_4 -> V_143 ,
V_156 -> V_38 ,
& V_142 , & V_143 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_25 ) ;
goto V_196;
}
}
V_51 = F_92 ( V_4 , V_141 , V_143 ) ;
if ( V_51 )
F_11 ( V_4 -> V_30 , L_26 , V_51 ) ;
if ( ! V_4 -> V_39 ) {
F_60 ( V_4 , V_20 -> V_172 , V_10 -> V_13 ,
V_4 -> V_142 , V_4 -> V_143 ,
V_156 -> V_38 ,
V_142 , V_143 ) ;
V_196:
F_60 ( V_4 , V_152 , V_10 -> V_32 ,
V_4 -> V_140 , V_4 -> V_141 ,
V_156 -> V_36 ,
V_140 , V_141 ) ;
}
return 0 ;
}
static int F_93 ( struct V_9 * V_10 , struct V_19 * V_20 ,
int V_163 )
{
struct V_3 * V_4 = F_69 ( V_20 ) ;
F_48 ( V_4 -> V_30 , L_27 , V_163 ) ;
memset ( V_20 -> V_172 , ~ 0 , V_10 -> V_13 ) ;
V_20 -> V_189 ( V_10 , V_197 , V_10 -> V_32 , V_163 ) ;
V_20 -> V_198 ( V_10 , V_20 -> V_172 , V_10 -> V_13 ) ;
if ( F_8 ( V_4 ) ) {
V_20 -> V_189 ( V_10 , V_197 , 0 , V_163 ) ;
V_20 -> V_172 [ 0 ] = V_20 -> V_199 ( V_10 ) ;
}
return 0 ;
}
static int
F_94 ( struct V_9 * V_10 , struct V_19 * V_20 , int V_163 )
{
struct V_21 * V_22 = V_10 -> V_200 -> V_24 ;
int V_164 = 0 ;
if ( ! V_22 -> V_35 )
return - V_201 ;
if ( ! F_95 ( V_20 ) )
return - V_201 ;
V_20 -> V_189 ( V_10 , V_202 , V_10 -> V_32 + V_22 -> V_34 , V_163 ) ;
V_20 -> V_203 ( V_10 , V_20 -> V_172 + V_22 -> V_34 , V_22 -> V_35 ) ;
V_20 -> V_189 ( V_10 , V_204 , - 1 , - 1 ) ;
V_164 = V_20 -> V_205 ( V_10 , V_20 ) ;
return V_164 & V_206 ? - V_207 : 0 ;
}
static int F_96 ( struct V_9 * V_10 ,
struct V_19 * V_20 , T_5 * V_152 ,
int V_162 , int V_163 )
{
struct V_3 * V_4 = F_69 ( V_20 ) ;
struct V_7 * V_156 = & V_4 -> V_7 ;
int V_208 = V_156 -> V_31 ;
int V_209 = V_156 -> V_12 * V_156 -> V_15 ;
T_8 * V_210 = V_4 -> V_135 ;
T_9 V_211 ;
T_9 V_212 ;
T_9 V_213 ;
T_5 * V_214 = V_20 -> V_172 ;
int V_215 ;
V_20 -> V_198 ( V_10 , V_210 ,
V_10 -> V_32 + V_10 -> V_13 ) ;
if ( V_4 -> V_39 ) {
T_8 V_216 = V_210 [ 0 ] ;
V_210 [ 0 ] = V_210 [ V_10 -> V_32 ] ;
V_210 [ V_10 -> V_32 ] = V_216 ;
}
if ( V_162 )
memcpy ( V_214 , V_210 , V_156 -> V_14 ) ;
V_212 = V_156 -> V_14 * 8 ;
V_211 = V_212 ;
for ( V_215 = 0 ; V_215 < V_156 -> V_16 ; V_215 ++ ) {
if ( V_152 )
F_97 ( V_152 , V_215 * V_208 * 8 ,
V_210 , V_211 ,
V_208 * 8 ) ;
V_211 += V_208 * 8 ;
if ( V_215 == V_156 -> V_16 - 1 &&
( V_212 + V_209 ) % 8 )
V_209 += 8 - ( ( V_212 + V_209 ) % 8 ) ;
if ( V_162 )
F_97 ( V_214 , V_212 ,
V_210 , V_211 ,
V_209 ) ;
V_211 += V_209 ;
V_212 += V_209 ;
}
if ( V_162 ) {
V_213 = V_212 / 8 ;
if ( V_213 < V_10 -> V_13 )
memcpy ( V_214 + V_213 ,
V_210 + V_10 -> V_32 + V_213 ,
V_10 -> V_13 - V_213 ) ;
}
return 0 ;
}
static int F_98 ( struct V_9 * V_10 ,
struct V_19 * V_20 ,
const T_5 * V_152 ,
int V_162 , int V_163 )
{
struct V_3 * V_4 = F_69 ( V_20 ) ;
struct V_7 * V_156 = & V_4 -> V_7 ;
int V_208 = V_156 -> V_31 ;
int V_209 = V_156 -> V_12 * V_156 -> V_15 ;
T_8 * V_210 = V_4 -> V_135 ;
T_5 * V_214 = V_20 -> V_172 ;
T_9 V_217 ;
T_9 V_212 ;
T_9 V_213 ;
int V_215 ;
if ( ! V_152 || ! V_162 )
memset ( V_210 , 0xff , V_10 -> V_32 + V_10 -> V_13 ) ;
memcpy ( V_210 , V_214 , V_156 -> V_14 ) ;
V_212 = V_156 -> V_14 * 8 ;
V_217 = V_212 ;
for ( V_215 = 0 ; V_215 < V_156 -> V_16 ; V_215 ++ ) {
if ( V_152 )
F_97 ( V_210 , V_217 ,
V_152 , V_215 * V_208 * 8 , V_208 * 8 ) ;
V_217 += V_208 * 8 ;
if ( V_215 == V_156 -> V_16 - 1 &&
( V_212 + V_209 ) % 8 )
V_209 += 8 - ( ( V_212 + V_209 ) % 8 ) ;
if ( V_162 )
F_97 ( V_210 , V_217 ,
V_214 , V_212 , V_209 ) ;
V_217 += V_209 ;
V_212 += V_209 ;
}
V_213 = V_212 / 8 ;
if ( V_162 && V_213 < V_10 -> V_13 )
memcpy ( V_210 + V_10 -> V_32 + V_213 ,
V_214 + V_213 , V_10 -> V_13 - V_213 ) ;
if ( V_4 -> V_39 ) {
T_8 V_216 = V_210 [ 0 ] ;
V_210 [ 0 ] = V_210 [ V_10 -> V_32 ] ;
V_210 [ V_10 -> V_32 ] = V_216 ;
}
V_20 -> V_203 ( V_10 , V_210 , V_10 -> V_32 + V_10 -> V_13 ) ;
return 0 ;
}
static int F_99 ( struct V_9 * V_10 , struct V_19 * V_20 ,
int V_163 )
{
V_20 -> V_189 ( V_10 , V_197 , 0 , V_163 ) ;
return F_96 ( V_10 , V_20 , NULL , 1 , V_163 ) ;
}
static int F_100 ( struct V_9 * V_10 , struct V_19 * V_20 ,
int V_163 )
{
V_20 -> V_189 ( V_10 , V_202 , 0 , V_163 ) ;
return F_98 ( V_10 , V_20 , NULL , 1 , V_163 ) ;
}
static int F_101 ( struct V_9 * V_10 , T_10 V_218 )
{
struct V_19 * V_20 = F_68 ( V_10 ) ;
struct V_3 * V_4 = F_69 ( V_20 ) ;
int V_51 = 0 ;
T_5 * V_219 ;
int V_220 , V_163 , V_164 , V_151 ;
V_151 = ( int ) ( V_218 >> V_20 -> V_221 ) ;
V_20 -> V_222 ( V_10 , V_151 ) ;
V_220 = ! F_8 ( V_4 ) ? V_10 -> V_32 : 0 ;
V_219 = V_4 -> V_56 ;
V_219 [ 0 ] = 0 ;
V_163 = ( int ) ( V_218 >> V_20 -> V_223 ) ;
V_20 -> V_189 ( V_10 , V_202 , V_220 , V_163 ) ;
V_20 -> V_203 ( V_10 , V_219 , 1 ) ;
V_20 -> V_189 ( V_10 , V_204 , - 1 , - 1 ) ;
V_164 = V_20 -> V_205 ( V_10 , V_20 ) ;
if ( V_164 & V_206 )
V_51 = - V_207 ;
V_20 -> V_222 ( V_10 , - 1 ) ;
return V_51 ;
}
static int F_102 ( struct V_3 * V_4 )
{
struct V_224 * V_225 = & V_4 -> V_226 ;
V_225 -> V_227 = 64 ;
V_225 -> V_228 = 2 ;
return 0 ;
}
static int F_103 ( struct V_3 * V_4 )
{
struct V_224 * V_229 = & V_4 -> V_226 ;
struct V_123 * V_30 = V_4 -> V_30 ;
struct V_19 * V_20 = & V_4 -> V_11 ;
struct V_9 * V_10 = F_5 ( V_20 ) ;
unsigned int V_230 ;
unsigned int V_231 ;
unsigned int V_163 ;
T_5 * V_232 = V_20 -> V_233 -> V_234 ;
int V_235 ;
int V_236 = false ;
V_230 = 1 << V_229 -> V_228 ;
V_235 = V_4 -> V_150 ;
V_20 -> V_222 ( V_10 , 0 ) ;
F_48 ( V_30 , L_28 ) ;
for ( V_231 = 0 ; V_231 < V_230 ; V_231 ++ ) {
V_163 = V_231 * V_229 -> V_227 ;
F_48 ( V_30 , L_29 , V_163 ) ;
V_20 -> V_189 ( V_10 , V_197 , 12 , V_163 ) ;
V_20 -> V_198 ( V_10 , V_232 , strlen ( V_237 ) ) ;
if ( ! memcmp ( V_232 , V_237 , strlen ( V_237 ) ) ) {
V_236 = true ;
break;
}
}
V_20 -> V_222 ( V_10 , V_235 ) ;
if ( V_236 )
F_48 ( V_30 , L_30 ) ;
else
F_48 ( V_30 , L_31 ) ;
return V_236 ;
}
static int F_104 ( struct V_3 * V_4 )
{
struct V_123 * V_30 = V_4 -> V_30 ;
struct V_224 * V_229 = & V_4 -> V_226 ;
struct V_19 * V_20 = & V_4 -> V_11 ;
struct V_9 * V_10 = F_5 ( V_20 ) ;
unsigned int V_238 ;
unsigned int V_230 ;
unsigned int V_239 ;
unsigned int V_240 ;
unsigned int V_241 ;
unsigned int V_231 ;
unsigned int V_163 ;
T_5 * V_232 = V_20 -> V_233 -> V_234 ;
int V_235 ;
int V_164 ;
V_238 = V_10 -> V_242 / V_10 -> V_32 ;
V_230 = 1 << V_229 -> V_228 ;
V_239 = V_230 *
V_229 -> V_227 ;
V_240 =
( V_239 + ( V_238 - 1 ) ) /
V_238 ;
F_48 ( V_30 , L_32 ) ;
F_48 ( V_30 , L_33 , V_240 ) ;
F_48 ( V_30 , L_34 , V_230 ) ;
F_48 ( V_30 , L_35 , V_239 ) ;
V_235 = V_4 -> V_150 ;
V_20 -> V_222 ( V_10 , 0 ) ;
F_48 ( V_30 , L_36 ) ;
for ( V_241 = 0 ; V_241 < V_240 ; V_241 ++ ) {
V_163 = V_241 * V_238 ;
F_48 ( V_30 , L_37 , V_241 ) ;
V_20 -> V_189 ( V_10 , V_243 , - 1 , V_163 ) ;
V_20 -> V_189 ( V_10 , V_244 , - 1 , - 1 ) ;
V_164 = V_20 -> V_205 ( V_10 , V_20 ) ;
if ( V_164 & V_206 )
F_11 ( V_30 , L_38 , V_245 ) ;
}
memset ( V_232 , ~ 0 , V_10 -> V_32 ) ;
memcpy ( V_232 + 12 , V_237 , strlen ( V_237 ) ) ;
F_48 ( V_30 , L_39 ) ;
for ( V_231 = 0 ; V_231 < V_230 ; V_231 ++ ) {
V_163 = V_231 * V_229 -> V_227 ;
F_48 ( V_30 , L_40 , V_163 ) ;
V_20 -> V_189 ( V_10 , V_202 , 0x00 , V_163 ) ;
V_20 -> V_176 . V_246 ( V_10 , V_20 , V_232 , 0 , V_163 ) ;
V_20 -> V_189 ( V_10 , V_204 , - 1 , - 1 ) ;
V_164 = V_20 -> V_205 ( V_10 , V_20 ) ;
if ( V_164 & V_206 )
F_11 ( V_30 , L_41 , V_245 ) ;
}
V_20 -> V_222 ( V_10 , V_235 ) ;
return 0 ;
}
static int F_105 ( struct V_3 * V_4 )
{
struct V_123 * V_30 = V_4 -> V_30 ;
struct V_19 * V_20 = & V_4 -> V_11 ;
struct V_9 * V_10 = F_5 ( V_20 ) ;
unsigned int V_247 ;
unsigned int V_241 ;
int V_151 ;
int V_163 ;
T_10 V_248 ;
T_5 V_219 ;
int V_51 = 0 ;
if ( F_103 ( V_4 ) )
return 0 ;
F_48 ( V_30 , L_42 ) ;
V_247 = V_20 -> V_249 >> V_20 -> V_250 ;
for ( V_241 = 0 ; V_241 < V_247 ; V_241 ++ ) {
V_151 = V_241 >> ( V_20 -> V_221 - V_20 -> V_250 ) ;
V_163 = V_241 << ( V_20 -> V_250 - V_20 -> V_223 ) ;
V_248 = V_241 << V_20 -> V_250 ;
V_20 -> V_222 ( V_10 , V_151 ) ;
V_20 -> V_189 ( V_10 , V_197 , V_10 -> V_32 , V_163 ) ;
V_219 = V_20 -> V_199 ( V_10 ) ;
V_20 -> V_222 ( V_10 , - 1 ) ;
if ( V_219 != 0xff ) {
F_48 ( V_30 , L_43 , V_241 ) ;
V_51 = V_20 -> V_251 ( V_10 , V_248 ) ;
if ( V_51 )
F_11 ( V_30 ,
L_44 ,
V_51 ) ;
}
}
F_104 ( V_4 ) ;
return 0 ;
}
static int F_106 ( struct V_3 * V_4 )
{
F_102 ( V_4 ) ;
if ( F_8 ( V_4 ) )
return F_105 ( V_4 ) ;
return 0 ;
}
static int F_107 ( struct V_3 * V_4 )
{
int V_51 ;
F_61 ( V_4 ) ;
V_51 = F_108 ( V_4 ) ;
if ( V_51 ) {
F_11 ( V_4 -> V_30 , L_45 , V_51 ) ;
return V_51 ;
}
return F_64 ( V_4 ) ;
}
static void F_109 ( struct V_3 * V_4 )
{
F_110 ( F_5 ( & V_4 -> V_11 ) ) ;
F_61 ( V_4 ) ;
}
static int F_111 ( struct V_3 * V_4 )
{
struct V_19 * V_20 = & V_4 -> V_11 ;
struct V_252 * V_176 = & V_20 -> V_176 ;
struct V_7 * V_253 = & V_4 -> V_7 ;
int V_51 ;
V_51 = F_107 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_176 -> V_254 = F_82 ;
V_176 -> V_255 = F_91 ;
V_176 -> V_256 = F_93 ;
V_176 -> V_257 = F_94 ;
V_176 -> V_258 = F_96 ;
V_176 -> V_246 = F_98 ;
V_176 -> V_259 = F_99 ;
V_176 -> V_260 = F_100 ;
V_176 -> V_261 = V_262 ;
V_176 -> V_175 = V_253 -> V_31 ;
V_176 -> V_263 = V_253 -> V_12 ;
V_176 -> V_264 = & V_23 ;
if ( F_46 ( V_4 ) &&
( ( V_253 -> V_15 * V_253 -> V_12 ) % 8 ) == 0 ) {
V_176 -> V_265 = F_85 ;
V_20 -> V_266 |= V_267 ;
}
F_112 ( V_4 ) ;
return 0 ;
}
static int F_113 ( struct V_3 * V_4 )
{
struct V_19 * V_20 = & V_4 -> V_11 ;
struct V_9 * V_10 = F_5 ( V_20 ) ;
int V_51 ;
V_4 -> V_150 = - 1 ;
V_10 -> V_268 = L_46 ;
V_10 -> V_30 . V_269 = V_4 -> V_30 ;
F_114 ( V_20 , V_4 ) ;
F_115 ( V_20 , V_4 -> V_80 -> V_30 . V_43 ) ;
V_20 -> V_222 = F_73 ;
V_20 -> V_270 = F_67 ;
V_20 -> V_271 = F_71 ;
V_20 -> V_199 = F_80 ;
V_20 -> V_198 = F_76 ;
V_20 -> V_203 = F_78 ;
V_20 -> V_272 = & V_273 ;
V_20 -> V_251 = F_101 ;
V_20 -> V_266 |= V_274 ;
V_4 -> V_39 = ! F_8 ( V_4 ) ;
if ( F_116 ( V_4 -> V_30 -> V_43 ) ) {
V_20 -> V_275 |= V_276 | V_277 ;
if ( F_16 ( V_4 -> V_30 -> V_43 ,
L_47 ) )
V_4 -> V_39 = false ;
}
F_48 ( V_4 -> V_30 , L_48 ,
V_4 -> V_39 ? L_49 : L_50 ) ;
V_4 -> V_7 . V_36 = 1024 ;
V_4 -> V_7 . V_38 = 128 ;
V_51 = F_64 ( V_4 ) ;
if ( V_51 )
goto V_278;
V_51 = F_117 ( V_10 , F_46 ( V_4 ) ? 2 : 1 , NULL ) ;
if ( V_51 )
goto V_278;
V_51 = F_111 ( V_4 ) ;
if ( V_51 )
goto V_278;
V_20 -> V_266 |= V_279 ;
V_51 = F_118 ( V_10 ) ;
if ( V_51 )
goto V_278;
V_51 = F_106 ( V_4 ) ;
if ( V_51 )
goto V_278;
V_51 = V_20 -> V_280 ( V_10 ) ;
if ( V_51 )
goto V_278;
V_51 = F_119 ( V_10 , NULL , 0 ) ;
if ( V_51 )
goto V_278;
return 0 ;
V_278:
F_109 ( V_4 ) ;
return V_51 ;
}
static int F_120 ( struct V_79 * V_80 )
{
struct V_3 * V_4 ;
const struct V_281 * V_282 ;
int V_51 ;
V_4 = F_121 ( & V_80 -> V_30 , sizeof( * V_4 ) , V_138 ) ;
if ( ! V_4 )
return - V_125 ;
V_282 = F_122 ( V_283 , & V_80 -> V_30 ) ;
if ( V_282 ) {
V_4 -> V_17 = V_282 -> V_144 ;
} else {
F_11 ( & V_80 -> V_30 , L_51 ) ;
return - V_95 ;
}
F_123 ( V_80 , V_4 ) ;
V_4 -> V_80 = V_80 ;
V_4 -> V_30 = & V_80 -> V_30 ;
V_51 = F_49 ( V_4 ) ;
if ( V_51 )
goto V_284;
V_51 = F_51 ( V_4 ) ;
if ( V_51 )
goto V_285;
V_51 = F_113 ( V_4 ) ;
if ( V_51 )
goto V_285;
F_124 ( V_4 -> V_30 , L_52 ) ;
return 0 ;
V_285:
F_50 ( V_4 ) ;
V_284:
return V_51 ;
}
static int F_125 ( struct V_79 * V_80 )
{
struct V_3 * V_4 = F_126 ( V_80 ) ;
F_109 ( V_4 ) ;
F_50 ( V_4 ) ;
return 0 ;
}
