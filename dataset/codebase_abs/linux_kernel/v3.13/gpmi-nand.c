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
static bool F_10 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_21 * V_22 = V_23 . V_24 ;
unsigned int V_25 ;
if ( ! ( V_19 -> V_26 > 0 && V_19 -> V_27 > 0 ) )
return false ;
switch ( V_19 -> V_27 ) {
case V_28 :
V_8 -> V_14 = 13 ;
break;
case V_29 :
V_8 -> V_14 = 14 ;
break;
default:
F_11 ( V_4 -> V_30 ,
L_1 ,
V_19 -> V_26 , V_19 -> V_27 ) ;
return false ;
}
V_8 -> V_31 = V_19 -> V_27 ;
V_8 -> V_11 = F_12 ( V_19 -> V_26 , 2 ) ;
if ( ! F_6 ( V_4 ) )
return false ;
if ( V_8 -> V_31 < V_10 -> V_12 ) {
F_11 ( V_4 -> V_30 ,
L_2 ,
V_19 -> V_27 , V_10 -> V_12 ) ;
return false ;
}
V_8 -> V_13 = 10 ;
V_8 -> V_15 = V_10 -> V_32 / V_8 -> V_31 ;
V_8 -> V_33 = V_10 -> V_32 + V_8 -> V_13 +
( V_8 -> V_14 * V_8 -> V_11 * V_8 -> V_15 ) / 8 ;
if ( V_8 -> V_33 < V_10 -> V_32 + V_10 -> V_12 ) {
V_22 -> V_34 = V_8 -> V_33 - V_10 -> V_32 ;
V_22 -> V_35 = V_10 -> V_12 - V_22 -> V_34 ;
}
V_8 -> V_36 = V_10 -> V_32 ;
V_8 -> V_37 = F_13 ( V_8 -> V_13 , 4 ) ;
V_8 -> V_38 = F_13 ( V_8 -> V_13 , 4 )
+ F_13 ( V_8 -> V_15 , 4 ) ;
if ( ! V_4 -> V_39 )
return true ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return true ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_13 ;
unsigned int V_41 ;
unsigned int V_25 ;
V_8 -> V_13 = 10 ;
V_8 -> V_14 = 13 ;
V_8 -> V_31 = 512 ;
while ( V_8 -> V_31 < V_10 -> V_12 ) {
V_8 -> V_31 *= 2 ;
V_8 -> V_14 = 14 ;
}
V_8 -> V_15 = V_10 -> V_32 / V_8 -> V_31 ;
V_8 -> V_11 = F_4 ( V_4 ) ;
if ( ! F_6 ( V_4 ) ) {
F_11 ( V_4 -> V_30 ,
L_3
L_4
L_5 , V_8 -> V_11 ,
( F_9 ( V_4 ) ? V_17
: V_16 ) ) ;
return - V_42 ;
}
V_8 -> V_33 = V_10 -> V_32 + V_10 -> V_12 ;
V_8 -> V_36 = V_10 -> V_32 ;
V_13 = F_13 ( V_8 -> V_13 , 4 ) ;
V_41 = F_13 ( V_8 -> V_15 , 4 ) ;
V_8 -> V_38 = V_13 + V_41 ;
V_8 -> V_37 = V_13 ;
if ( ! V_4 -> V_39 )
return 0 ;
V_25 = V_10 -> V_32 * 8 -
( V_8 -> V_11 * V_8 -> V_14 * ( V_8 -> V_15 - 1 )
+ V_8 -> V_13 * 8 ) ;
V_8 -> V_40 = V_25 / 8 ;
V_8 -> V_25 = V_25 % 8 ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 )
{
return F_14 ( V_4 ) ;
}
struct V_43 * F_16 ( struct V_3 * V_4 )
{
return V_4 -> V_44 [ 0 ] ;
}
void F_17 ( struct V_3 * V_4 , enum V_45 V_46 )
{
struct V_47 * V_48 = & V_4 -> V_49 ;
int V_50 ;
V_4 -> V_51 = true ;
F_18 ( V_48 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_50 = F_19 ( V_4 -> V_30 , V_48 , 1 , V_46 ) ;
if ( V_50 == 0 ) {
F_18 ( V_48 , V_4 -> V_54 , V_55 ) ;
if ( V_46 == V_56 )
memcpy ( V_4 -> V_54 , V_4 -> V_52 ,
V_4 -> V_53 ) ;
V_50 = F_19 ( V_4 -> V_30 , V_48 , 1 , V_46 ) ;
if ( V_50 == 0 )
F_20 ( L_6 ) ;
V_4 -> V_51 = false ;
}
}
static void F_21 ( void * V_57 )
{
struct V_3 * V_4 = V_57 ;
struct V_58 * V_59 = & V_4 -> V_60 ;
switch ( V_4 -> V_61 ) {
case V_62 :
F_22 ( V_4 -> V_30 , & V_4 -> V_63 , 1 , V_56 ) ;
break;
case V_64 :
F_22 ( V_4 -> V_30 , & V_4 -> V_49 , 1 , V_65 ) ;
if ( V_4 -> V_51 == false )
memcpy ( V_4 -> V_52 , V_4 -> V_54 ,
V_4 -> V_53 ) ;
break;
case V_66 :
F_22 ( V_4 -> V_30 , & V_4 -> V_49 , 1 , V_56 ) ;
break;
case V_67 :
case V_68 :
break;
default:
F_20 ( L_7 ) ;
}
F_3 ( V_59 ) ;
}
int F_23 ( struct V_3 * V_4 ,
struct V_69 * V_70 )
{
struct V_58 * V_59 = & V_4 -> V_60 ;
int V_71 ;
F_24 ( V_59 ) ;
V_70 -> V_72 = F_21 ;
V_70 -> V_73 = V_4 ;
F_25 ( V_70 ) ;
F_26 ( F_16 ( V_4 ) ) ;
V_71 = F_27 ( V_59 , F_28 ( 1000 ) ) ;
if ( ! V_71 ) {
F_20 ( L_8 , V_4 -> V_74 ) ;
F_29 ( V_4 ) ;
return - V_75 ;
}
return 0 ;
}
int F_30 ( struct V_3 * V_4 ,
struct V_69 * V_70 )
{
struct V_58 * V_76 = & V_4 -> V_5 ;
int V_71 ;
F_24 ( V_76 ) ;
F_23 ( V_4 , V_70 ) ;
V_71 = F_27 ( V_76 , F_28 ( 1000 ) ) ;
if ( ! V_71 ) {
F_20 ( L_9 , V_4 -> V_74 ) ;
F_29 ( V_4 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
const char * V_77 )
{
struct V_78 * V_79 = V_4 -> V_79 ;
struct V_80 * V_81 = & V_4 -> V_80 ;
struct V_82 * V_83 ;
void T_2 * V_84 ;
V_83 = F_32 ( V_79 , V_85 , V_77 ) ;
if ( ! V_83 ) {
F_20 ( L_10 , V_77 ) ;
return - V_86 ;
}
V_84 = F_33 ( V_83 -> V_87 , F_34 ( V_83 ) ) ;
if ( ! V_84 ) {
F_20 ( L_11 , V_77 ) ;
return - V_88 ;
}
if ( ! strcmp ( V_77 , V_89 ) )
V_81 -> V_90 = V_84 ;
else if ( ! strcmp ( V_77 , V_91 ) )
V_81 -> V_92 = V_84 ;
else
F_20 ( L_12 , V_77 ) ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 )
{
struct V_80 * V_81 = & V_4 -> V_80 ;
if ( V_81 -> V_90 )
F_36 ( V_81 -> V_90 ) ;
if ( V_81 -> V_92 )
F_36 ( V_81 -> V_92 ) ;
V_81 -> V_90 = NULL ;
V_81 -> V_92 = NULL ;
}
static int F_37 ( struct V_3 * V_4 , T_3 V_93 )
{
struct V_78 * V_79 = V_4 -> V_79 ;
struct V_80 * V_81 = & V_4 -> V_80 ;
const char * V_77 = V_94 ;
struct V_82 * V_83 ;
int V_71 ;
V_83 = F_32 ( V_79 , V_95 , V_77 ) ;
if ( ! V_83 ) {
F_20 ( L_10 , V_77 ) ;
return - V_86 ;
}
V_71 = F_38 ( V_83 -> V_87 , V_93 , 0 , V_77 , V_4 ) ;
if ( V_71 ) {
F_20 ( L_13 , V_77 ) ;
return V_71 ;
}
V_81 -> V_96 = V_83 -> V_87 ;
V_81 -> V_97 = V_83 -> V_98 ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_80 * V_81 = & V_4 -> V_80 ;
int V_99 = V_81 -> V_96 ;
for (; V_99 <= V_81 -> V_97 ; V_99 ++ )
F_40 ( V_99 , V_4 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
unsigned int V_99 ;
for ( V_99 = 0 ; V_99 < V_100 ; V_99 ++ )
if ( V_4 -> V_44 [ V_99 ] ) {
F_42 ( V_4 -> V_44 [ V_99 ] ) ;
V_4 -> V_44 [ V_99 ] = NULL ;
}
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_78 * V_79 = V_4 -> V_79 ;
struct V_43 * V_43 ;
V_43 = F_44 ( & V_79 -> V_30 , L_14 ) ;
if ( ! V_43 ) {
F_20 ( L_15 ) ;
goto V_101;
}
V_4 -> V_44 [ 0 ] = V_43 ;
return 0 ;
V_101:
F_41 ( V_4 ) ;
return - V_42 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_80 * V_83 = & V_4 -> V_80 ;
struct V_102 * V_102 ;
int V_99 ;
for ( V_99 = 0 ; V_99 < V_103 ; V_99 ++ ) {
V_102 = V_83 -> clock [ V_99 ] ;
if ( V_102 ) {
F_46 ( V_102 ) ;
V_83 -> clock [ V_99 ] = NULL ;
}
}
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_80 * V_83 = & V_4 -> V_80 ;
char * * V_104 = NULL ;
struct V_102 * V_102 ;
int V_71 , V_99 ;
V_83 -> clock [ 0 ] = F_48 ( V_4 -> V_30 , L_16 ) ;
if ( F_49 ( V_83 -> clock [ 0 ] ) ) {
V_71 = F_50 ( V_83 -> clock [ 0 ] ) ;
goto V_105;
}
if ( F_9 ( V_4 ) )
V_104 = V_106 ;
if ( ! V_104 )
return 0 ;
for ( V_99 = 1 ; V_99 < V_103 ; V_99 ++ ) {
if ( V_104 [ V_99 - 1 ] == NULL )
break;
V_102 = F_48 ( V_4 -> V_30 , V_104 [ V_99 - 1 ] ) ;
if ( F_49 ( V_102 ) ) {
V_71 = F_50 ( V_102 ) ;
goto V_105;
}
V_83 -> clock [ V_99 ] = V_102 ;
}
if ( F_9 ( V_4 ) )
F_51 ( V_83 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_105:
F_52 ( V_4 -> V_30 , L_17 ) ;
F_45 ( V_4 ) ;
return V_71 ;
}
static int F_53 ( struct V_3 * V_4 )
{
int V_50 ;
V_50 = F_31 ( V_4 , V_89 ) ;
if ( V_50 )
goto V_107;
V_50 = F_31 ( V_4 , V_91 ) ;
if ( V_50 )
goto V_107;
V_50 = F_37 ( V_4 , F_1 ) ;
if ( V_50 )
goto V_107;
V_50 = F_43 ( V_4 ) ;
if ( V_50 )
goto V_108;
V_50 = F_47 ( V_4 ) ;
if ( V_50 )
goto V_109;
return 0 ;
V_109:
F_41 ( V_4 ) ;
V_108:
F_39 ( V_4 ) ;
V_107:
F_35 ( V_4 ) ;
return V_50 ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_45 ( V_4 ) ;
F_35 ( V_4 ) ;
F_39 ( V_4 ) ;
F_41 ( V_4 ) ;
}
static int F_55 ( struct V_3 * V_4 )
{
int V_50 ;
struct V_110 V_111 = {
. V_112 = 80 ,
. V_113 = 60 ,
. V_114 = 25 ,
. V_115 = 6 ,
. V_116 = - 1 ,
. V_117 = - 1 ,
. V_118 = - 1 ,
} ;
V_50 = F_56 ( V_4 ) ;
if ( V_50 )
return V_50 ;
V_4 -> V_119 = V_111 ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 ,
void * V_120 , unsigned V_35 ,
void * V_121 , T_4 V_122 , unsigned V_123 ,
void * * V_124 , T_4 * V_125 )
{
struct V_126 * V_30 = V_4 -> V_30 ;
if ( F_58 ( V_120 ) ) {
T_4 V_127 ;
V_127 = F_59 ( V_30 , V_120 ,
V_35 , V_65 ) ;
if ( F_60 ( V_30 , V_127 ) ) {
if ( V_123 < V_35 ) {
F_20 ( L_18 ,
V_128 ) ;
return - V_88 ;
}
goto V_129;
}
* V_124 = V_120 ;
* V_125 = V_127 ;
V_4 -> V_51 = true ;
return 0 ;
}
V_129:
* V_124 = V_121 ;
* V_125 = V_122 ;
V_4 -> V_51 = false ;
return 0 ;
}
static inline void F_61 ( struct V_3 * V_4 ,
void * V_120 , unsigned V_35 ,
void * V_121 , T_4 V_122 , unsigned V_123 ,
void * V_130 , T_4 V_131 )
{
if ( V_4 -> V_51 )
F_62 ( V_4 -> V_30 , V_131 , V_35 , V_65 ) ;
}
static inline void F_63 ( struct V_3 * V_4 ,
void * V_120 , unsigned V_35 ,
void * V_121 , T_4 V_122 , unsigned V_123 ,
void * V_130 , T_4 V_131 )
{
if ( ! V_4 -> V_51 )
memcpy ( V_120 , V_121 , V_35 ) ;
}
static int F_64 ( struct V_3 * V_4 ,
const void * V_132 , unsigned V_35 ,
void * V_121 , T_4 V_122 , unsigned V_123 ,
const void * * V_124 , T_4 * V_125 )
{
struct V_126 * V_30 = V_4 -> V_30 ;
if ( F_58 ( V_132 ) ) {
T_4 V_133 ;
V_133 = F_59 ( V_30 , ( void * ) V_132 , V_35 ,
V_56 ) ;
if ( F_60 ( V_30 , V_133 ) ) {
if ( V_123 < V_35 ) {
F_20 ( L_18 ,
V_128 ) ;
return - V_88 ;
}
goto V_129;
}
* V_124 = V_132 ;
* V_125 = V_133 ;
return 0 ;
}
V_129:
memcpy ( V_121 , V_132 , V_35 ) ;
* V_124 = V_121 ;
* V_125 = V_122 ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 ,
const void * V_132 , unsigned V_35 ,
void * V_121 , T_4 V_122 , unsigned V_123 ,
const void * V_130 , T_4 V_131 )
{
struct V_126 * V_30 = V_4 -> V_30 ;
if ( V_130 == V_132 )
F_62 ( V_30 , V_131 , V_35 , V_56 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_126 * V_30 = V_4 -> V_30 ;
if ( V_4 -> V_134 && F_58 ( V_4 -> V_134 ) )
F_67 ( V_30 , V_4 -> V_135 ,
V_4 -> V_134 ,
V_4 -> V_136 ) ;
F_68 ( V_4 -> V_137 ) ;
F_68 ( V_4 -> V_54 ) ;
V_4 -> V_137 = NULL ;
V_4 -> V_54 = NULL ;
V_4 -> V_134 = NULL ;
V_4 -> V_135 = 0 ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_7 ;
struct V_126 * V_30 = V_4 -> V_30 ;
V_4 -> V_137 = F_70 ( V_55 , V_138 | V_139 ) ;
if ( V_4 -> V_137 == NULL )
goto V_140;
V_4 -> V_54 = F_70 ( V_55 , V_138 | V_139 ) ;
if ( V_4 -> V_54 == NULL )
goto V_140;
V_4 -> V_135 = V_8 -> V_36 + V_8 -> V_38 ;
V_4 -> V_134 = F_71 ( V_30 , V_4 -> V_135 ,
& V_4 -> V_136 , V_138 ) ;
if ( ! V_4 -> V_134 )
goto V_140;
V_4 -> V_141 = V_4 -> V_134 ;
V_4 -> V_142 = V_4 -> V_136 ;
V_4 -> V_143 = V_4 -> V_141 + V_8 -> V_36 ;
V_4 -> V_144 = V_4 -> V_142 + V_8 -> V_36 ;
return 0 ;
V_140:
F_66 ( V_4 ) ;
F_20 ( L_19 ) ;
return - V_88 ;
}
static void F_72 ( struct V_9 * V_10 , int V_145 , unsigned int V_146 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_50 ;
if ( ( V_146 & ( V_147 | V_148 ) ) ) {
if ( V_145 != V_149 )
V_4 -> V_137 [ V_4 -> V_150 ++ ] = V_145 ;
return;
}
if ( ! V_4 -> V_150 )
return;
V_50 = F_73 ( V_4 ) ;
if ( V_50 )
F_20 ( L_20 , V_4 -> V_151 , V_50 ) ;
V_4 -> V_150 = 0 ;
}
static int F_74 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
return F_75 ( V_4 , V_4 -> V_151 ) ;
}
static void F_76 ( struct V_9 * V_10 , int V_152 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
if ( ( V_4 -> V_151 < 0 ) && ( V_152 >= 0 ) )
F_77 ( V_4 ) ;
else if ( ( V_4 -> V_151 >= 0 ) && ( V_152 < 0 ) )
F_78 ( V_4 ) ;
V_4 -> V_151 = V_152 ;
}
static void F_79 ( struct V_9 * V_10 , T_5 * V_153 , int V_154 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_80 ( L_21 , V_154 ) ;
V_4 -> V_52 = V_153 ;
V_4 -> V_53 = V_154 ;
F_81 ( V_4 ) ;
}
static void F_82 ( struct V_9 * V_10 , const T_5 * V_153 , int V_154 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
F_80 ( L_21 , V_154 ) ;
V_4 -> V_52 = ( T_5 * ) V_153 ;
V_4 -> V_53 = V_154 ;
F_83 ( V_4 ) ;
}
static T_5 F_84 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
T_5 * V_153 = V_4 -> V_54 ;
F_79 ( V_10 , V_153 , 1 ) ;
return V_153 [ 0 ] ;
}
static void F_85 ( struct V_3 * V_4 ,
void * V_155 , void * V_156 )
{
struct V_7 * V_157 = & V_4 -> V_7 ;
unsigned char * V_84 ;
unsigned char * V_158 ;
unsigned int V_159 ;
unsigned char V_160 ;
unsigned char V_161 ;
unsigned char V_162 ;
if ( ! V_4 -> V_39 )
return;
V_159 = V_157 -> V_25 ;
V_84 = V_155 + V_157 -> V_40 ;
V_158 = V_156 ;
V_161 = ( V_84 [ 0 ] >> V_159 ) | ( V_84 [ 1 ] << ( 8 - V_159 ) ) ;
V_162 = V_158 [ 0 ] ;
V_158 [ 0 ] = V_161 ;
V_160 = ( 0x1 << V_159 ) - 1 ;
V_84 [ 0 ] = ( V_84 [ 0 ] & V_160 ) | ( V_162 << V_159 ) ;
V_160 = ~ 0 << V_159 ;
V_84 [ 1 ] = ( V_84 [ 1 ] & V_160 ) | ( V_162 >> ( 8 - V_159 ) ) ;
}
static int F_86 ( struct V_9 * V_10 , struct V_18 * V_19 ,
T_5 * V_153 , int V_163 , int V_164 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_157 = & V_4 -> V_7 ;
void * V_141 ;
T_4 V_142 ;
void * V_143 ;
T_4 V_144 ;
unsigned int V_99 ;
unsigned char * V_165 ;
unsigned int V_166 = 0 ;
int V_50 ;
F_80 ( L_22 , V_164 ) ;
V_50 = F_57 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_157 -> V_36 ,
& V_141 , & V_142 ) ;
if ( V_50 ) {
F_20 ( L_23 ) ;
V_50 = - V_88 ;
return V_50 ;
}
V_143 = V_4 -> V_143 ;
V_144 = V_4 -> V_144 ;
V_50 = F_87 ( V_4 , V_142 , V_144 ) ;
F_61 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_157 -> V_36 ,
V_141 , V_142 ) ;
if ( V_50 ) {
F_20 ( L_24 , V_50 ) ;
return V_50 ;
}
F_85 ( V_4 , V_141 , V_143 ) ;
V_165 = V_143 + V_157 -> V_37 ;
for ( V_99 = 0 ; V_99 < V_157 -> V_15 ; V_99 ++ , V_165 ++ ) {
if ( ( * V_165 == V_167 ) || ( * V_165 == V_168 ) )
continue;
if ( * V_165 == V_169 ) {
V_10 -> V_170 . V_171 ++ ;
continue;
}
V_10 -> V_170 . V_172 += * V_165 ;
V_166 = F_88 (unsigned int, max_bitflips, *status) ;
}
if ( V_163 ) {
memset ( V_19 -> V_173 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_173 [ 0 ] = ( ( T_5 * ) V_143 ) [ 0 ] ;
}
F_63 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_157 -> V_36 ,
V_141 , V_142 ) ;
return V_166 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_18 * V_19 ,
const T_5 * V_153 , int V_163 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
struct V_7 * V_157 = & V_4 -> V_7 ;
const void * V_141 ;
T_4 V_142 ;
const void * V_143 ;
T_4 V_144 ;
int V_50 ;
F_80 ( L_25 ) ;
if ( V_4 -> V_39 ) {
memcpy ( V_4 -> V_141 , V_153 , V_10 -> V_32 ) ;
V_141 = V_4 -> V_141 ;
V_142 = V_4 -> V_142 ;
memcpy ( V_4 -> V_143 , V_19 -> V_173 ,
V_157 -> V_38 ) ;
V_143 = V_4 -> V_143 ;
V_144 = V_4 -> V_144 ;
F_85 ( V_4 ,
( void * ) V_141 , ( void * ) V_143 ) ;
} else {
V_50 = F_64 ( V_4 ,
V_153 , V_10 -> V_32 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_157 -> V_36 ,
& V_141 , & V_142 ) ;
if ( V_50 ) {
F_20 ( L_26 ) ;
return 0 ;
}
V_50 = F_64 ( V_4 ,
V_19 -> V_173 , V_10 -> V_12 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_38 ,
& V_143 , & V_144 ) ;
if ( V_50 ) {
F_20 ( L_27 ) ;
goto V_174;
}
}
V_50 = F_90 ( V_4 , V_142 , V_144 ) ;
if ( V_50 )
F_20 ( L_28 , V_50 ) ;
if ( ! V_4 -> V_39 ) {
F_65 ( V_4 , V_19 -> V_173 , V_10 -> V_12 ,
V_4 -> V_143 , V_4 -> V_144 ,
V_157 -> V_38 ,
V_143 , V_144 ) ;
V_174:
F_65 ( V_4 , V_153 , V_10 -> V_32 ,
V_4 -> V_141 , V_4 -> V_142 ,
V_157 -> V_36 ,
V_141 , V_142 ) ;
}
return 0 ;
}
static int F_91 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_164 )
{
struct V_3 * V_4 = V_19 -> V_20 ;
F_80 ( L_29 , V_164 ) ;
memset ( V_19 -> V_173 , ~ 0 , V_10 -> V_12 ) ;
V_19 -> V_175 ( V_10 , V_176 , V_10 -> V_32 , V_164 ) ;
V_19 -> V_177 ( V_10 , V_19 -> V_173 , V_10 -> V_12 ) ;
if ( ! V_4 -> V_39 ) {
V_19 -> V_175 ( V_10 , V_176 , 0 , V_164 ) ;
V_19 -> V_173 [ 0 ] = V_19 -> V_178 ( V_10 ) ;
}
return 0 ;
}
static int
F_92 ( struct V_9 * V_10 , struct V_18 * V_19 , int V_164 )
{
struct V_21 * V_22 = V_10 -> V_179 -> V_24 ;
int V_165 = 0 ;
if ( ! V_22 -> V_35 )
return - V_180 ;
if ( ! F_93 ( V_19 ) )
return - V_180 ;
V_19 -> V_175 ( V_10 , V_181 , V_10 -> V_32 + V_22 -> V_34 , V_164 ) ;
V_19 -> V_182 ( V_10 , V_19 -> V_173 + V_22 -> V_34 , V_22 -> V_35 ) ;
V_19 -> V_175 ( V_10 , V_183 , - 1 , - 1 ) ;
V_165 = V_19 -> V_184 ( V_10 , V_19 ) ;
return V_165 & V_185 ? - V_186 : 0 ;
}
static int F_94 ( struct V_9 * V_10 , T_6 V_187 )
{
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_3 * V_4 = V_19 -> V_20 ;
int V_50 = 0 ;
T_5 * V_188 ;
int V_189 , V_164 , V_165 , V_152 ;
V_152 = ( int ) ( V_187 >> V_19 -> V_190 ) ;
V_19 -> V_191 ( V_10 , V_152 ) ;
V_189 = V_4 -> V_39 ? V_10 -> V_32 : 0 ;
V_188 = V_4 -> V_54 ;
V_188 [ 0 ] = 0 ;
V_164 = ( int ) ( V_187 >> V_19 -> V_192 ) ;
V_19 -> V_175 ( V_10 , V_181 , V_189 , V_164 ) ;
V_19 -> V_182 ( V_10 , V_188 , 1 ) ;
V_19 -> V_175 ( V_10 , V_183 , - 1 , - 1 ) ;
V_165 = V_19 -> V_184 ( V_10 , V_19 ) ;
if ( V_165 & V_185 )
V_50 = - V_186 ;
V_19 -> V_191 ( V_10 , - 1 ) ;
return V_50 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_193 * V_194 = & V_4 -> V_195 ;
V_194 -> V_196 = 64 ;
V_194 -> V_197 = 2 ;
return 0 ;
}
static int F_96 ( struct V_3 * V_4 )
{
struct V_193 * V_198 = & V_4 -> V_195 ;
struct V_126 * V_30 = V_4 -> V_30 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_199 ;
unsigned int V_200 ;
unsigned int V_201 ;
unsigned int V_164 ;
T_5 * V_202 = V_19 -> V_203 -> V_204 ;
int V_205 ;
int V_206 = false ;
V_200 = 1 << V_198 -> V_197 ;
V_205 = V_4 -> V_151 ;
V_19 -> V_191 ( V_10 , 0 ) ;
F_52 ( V_30 , L_30 ) ;
for ( V_201 = 0 ; V_201 < V_200 ; V_201 ++ ) {
V_164 = V_201 * V_198 -> V_196 ;
F_52 ( V_30 , L_31 , V_164 ) ;
V_19 -> V_175 ( V_10 , V_176 , 12 , V_164 ) ;
V_19 -> V_177 ( V_10 , V_202 , strlen ( V_207 ) ) ;
if ( ! memcmp ( V_202 , V_207 , strlen ( V_207 ) ) ) {
V_206 = true ;
break;
}
}
V_19 -> V_191 ( V_10 , V_205 ) ;
if ( V_206 )
F_52 ( V_30 , L_32 ) ;
else
F_52 ( V_30 , L_33 ) ;
return V_206 ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_126 * V_30 = V_4 -> V_30 ;
struct V_193 * V_198 = & V_4 -> V_195 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_199 ;
unsigned int V_208 ;
unsigned int V_200 ;
unsigned int V_209 ;
unsigned int V_210 ;
unsigned int V_211 ;
unsigned int V_201 ;
unsigned int V_164 ;
T_5 * V_202 = V_19 -> V_203 -> V_204 ;
int V_205 ;
int V_165 ;
V_208 = V_10 -> V_212 / V_10 -> V_32 ;
V_200 = 1 << V_198 -> V_197 ;
V_209 = V_200 *
V_198 -> V_196 ;
V_210 =
( V_209 + ( V_208 - 1 ) ) /
V_208 ;
F_52 ( V_30 , L_34 ) ;
F_52 ( V_30 , L_35 , V_210 ) ;
F_52 ( V_30 , L_36 , V_200 ) ;
F_52 ( V_30 , L_37 , V_209 ) ;
V_205 = V_4 -> V_151 ;
V_19 -> V_191 ( V_10 , 0 ) ;
F_52 ( V_30 , L_38 ) ;
for ( V_211 = 0 ; V_211 < V_210 ; V_211 ++ ) {
V_164 = V_211 * V_208 ;
F_52 ( V_30 , L_39 , V_211 ) ;
V_19 -> V_175 ( V_10 , V_213 , - 1 , V_164 ) ;
V_19 -> V_175 ( V_10 , V_214 , - 1 , - 1 ) ;
V_165 = V_19 -> V_184 ( V_10 , V_19 ) ;
if ( V_165 & V_185 )
F_11 ( V_30 , L_40 , V_128 ) ;
}
memset ( V_202 , ~ 0 , V_10 -> V_32 ) ;
memset ( V_19 -> V_173 , ~ 0 , V_10 -> V_12 ) ;
memcpy ( V_202 + 12 , V_207 , strlen ( V_207 ) ) ;
F_52 ( V_30 , L_41 ) ;
for ( V_201 = 0 ; V_201 < V_200 ; V_201 ++ ) {
V_164 = V_201 * V_198 -> V_196 ;
F_52 ( V_30 , L_42 , V_164 ) ;
V_19 -> V_175 ( V_10 , V_181 , 0x00 , V_164 ) ;
V_19 -> V_215 . V_216 ( V_10 , V_19 , V_202 , 0 ) ;
V_19 -> V_175 ( V_10 , V_183 , - 1 , - 1 ) ;
V_165 = V_19 -> V_184 ( V_10 , V_19 ) ;
if ( V_165 & V_185 )
F_11 ( V_30 , L_43 , V_128 ) ;
}
V_19 -> V_191 ( V_10 , V_205 ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_126 * V_30 = V_4 -> V_30 ;
struct V_18 * V_19 = & V_4 -> V_199 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned int V_217 ;
unsigned int V_211 ;
int V_152 ;
int V_164 ;
T_6 V_218 ;
T_5 V_188 ;
int V_50 = 0 ;
if ( F_96 ( V_4 ) )
return 0 ;
F_52 ( V_30 , L_44 ) ;
V_217 = V_19 -> V_219 >> V_19 -> V_220 ;
for ( V_211 = 0 ; V_211 < V_217 ; V_211 ++ ) {
V_152 = V_211 >> ( V_19 -> V_190 - V_19 -> V_220 ) ;
V_164 = V_211 << ( V_19 -> V_220 - V_19 -> V_192 ) ;
V_218 = V_211 << V_19 -> V_220 ;
V_19 -> V_191 ( V_10 , V_152 ) ;
V_19 -> V_175 ( V_10 , V_176 , V_10 -> V_32 , V_164 ) ;
V_188 = V_19 -> V_178 ( V_10 ) ;
V_19 -> V_191 ( V_10 , - 1 ) ;
if ( V_188 != 0xff ) {
F_52 ( V_30 , L_45 , V_211 ) ;
V_50 = V_19 -> V_221 ( V_10 , V_218 ) ;
if ( V_50 )
F_11 ( V_30 , L_46
L_47 , V_50 ) ;
}
}
F_97 ( V_4 ) ;
return 0 ;
}
static int F_99 ( struct V_3 * V_4 )
{
F_95 ( V_4 ) ;
if ( F_7 ( V_4 ) )
return F_98 ( V_4 ) ;
return 0 ;
}
static int F_100 ( struct V_3 * V_4 )
{
int V_50 ;
F_66 ( V_4 ) ;
V_50 = F_101 ( V_4 ) ;
if ( V_50 ) {
F_20 ( L_48 , V_50 ) ;
return V_50 ;
}
return F_69 ( V_4 ) ;
}
static int F_102 ( struct V_3 * V_4 )
{
if ( F_7 ( V_4 ) )
V_4 -> V_39 = false ;
else
V_4 -> V_39 = true ;
return F_100 ( V_4 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
F_104 ( & V_4 -> V_10 ) ;
F_66 ( V_4 ) ;
}
static int F_105 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_20 ;
struct V_222 * V_215 = & V_19 -> V_215 ;
struct V_7 * V_223 = & V_4 -> V_7 ;
int V_50 ;
V_50 = F_102 ( V_4 ) ;
if ( V_50 )
return V_50 ;
V_215 -> V_224 = F_86 ;
V_215 -> V_225 = F_89 ;
V_215 -> V_226 = F_91 ;
V_215 -> V_227 = F_92 ;
V_215 -> V_228 = V_229 ;
V_215 -> V_230 = V_223 -> V_31 ;
V_215 -> V_231 = V_223 -> V_11 ;
V_215 -> V_232 = & V_23 ;
F_106 ( V_4 ) ;
return 0 ;
}
static int F_107 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_18 * V_19 = & V_4 -> V_199 ;
struct V_233 V_234 = {} ;
int V_50 ;
V_4 -> V_151 = - 1 ;
V_10 -> V_20 = V_19 ;
V_10 -> V_235 = L_49 ;
V_10 -> V_236 = V_237 ;
V_19 -> V_20 = V_4 ;
V_19 -> V_191 = F_76 ;
V_19 -> V_238 = F_72 ;
V_19 -> V_239 = F_74 ;
V_19 -> V_178 = F_84 ;
V_19 -> V_177 = F_79 ;
V_19 -> V_182 = F_82 ;
V_19 -> V_240 = & V_241 ;
V_19 -> V_221 = F_94 ;
V_19 -> V_242 |= V_243 ;
if ( F_108 ( V_4 -> V_30 -> V_244 ) )
V_19 -> V_245 |= V_246 | V_247 ;
V_4 -> V_7 . V_36 = 1024 ;
V_4 -> V_7 . V_38 = 128 ;
V_50 = F_69 ( V_4 ) ;
if ( V_50 )
goto V_248;
V_50 = F_109 ( V_10 , F_9 ( V_4 ) ? 2 : 1 , NULL ) ;
if ( V_50 )
goto V_248;
V_50 = F_105 ( V_4 ) ;
if ( V_50 )
goto V_248;
V_19 -> V_242 |= V_249 ;
V_50 = F_110 ( V_10 ) ;
if ( V_50 )
goto V_248;
V_50 = F_99 ( V_4 ) ;
if ( V_50 )
goto V_248;
V_19 -> V_250 ( V_10 ) ;
V_234 . V_244 = V_4 -> V_79 -> V_30 . V_244 ;
V_50 = F_111 ( V_10 , NULL , & V_234 , NULL , 0 ) ;
if ( V_50 )
goto V_248;
return 0 ;
V_248:
F_103 ( V_4 ) ;
return V_50 ;
}
static int F_112 ( struct V_78 * V_79 )
{
struct V_3 * V_4 ;
const struct V_251 * V_252 ;
int V_50 ;
V_252 = F_113 ( V_253 , & V_79 -> V_30 ) ;
if ( V_252 ) {
V_79 -> V_254 = V_252 -> V_145 ;
} else {
F_20 ( L_50 ) ;
return - V_86 ;
}
V_4 = F_114 ( & V_79 -> V_30 , sizeof( * V_4 ) , V_139 ) ;
if ( ! V_4 ) {
F_20 ( L_51 ) ;
return - V_88 ;
}
F_115 ( V_79 , V_4 ) ;
V_4 -> V_79 = V_79 ;
V_4 -> V_30 = & V_79 -> V_30 ;
V_50 = F_53 ( V_4 ) ;
if ( V_50 )
goto V_255;
V_50 = F_55 ( V_4 ) ;
if ( V_50 )
goto V_256;
V_50 = F_107 ( V_4 ) ;
if ( V_50 )
goto V_256;
F_116 ( V_4 -> V_30 , L_52 ) ;
return 0 ;
V_256:
F_54 ( V_4 ) ;
V_255:
F_11 ( V_4 -> V_30 , L_53 , V_50 ) ;
return V_50 ;
}
static int F_117 ( struct V_78 * V_79 )
{
struct V_3 * V_4 = F_118 ( V_79 ) ;
F_103 ( V_4 ) ;
F_54 ( V_4 ) ;
return 0 ;
}
