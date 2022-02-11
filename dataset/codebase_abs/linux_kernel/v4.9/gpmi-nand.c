static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_10 ;
if ( V_3 )
return - V_12 ;
V_5 -> V_13 = 0 ;
V_5 -> V_14 = V_11 -> V_15 - V_2 -> V_16 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_10 ;
if ( V_3 )
return - V_12 ;
if ( V_11 -> V_15 < V_2 -> V_16 + V_2 -> V_17 ) {
V_5 -> V_13 = V_11 -> V_15 - V_2 -> V_16 ;
V_5 -> V_14 = V_2 -> V_17 - V_5 -> V_13 ;
}
return 0 ;
}
static T_1 F_5 ( int V_18 , void * V_19 )
{
struct V_8 * V_9 = V_19 ;
F_6 ( V_9 ) ;
F_7 ( & V_9 -> V_20 ) ;
return V_21 ;
}
static inline int F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_1 * V_2 = F_9 ( & V_9 -> V_22 ) ;
int V_23 ;
V_23 = ( ( V_2 -> V_17 - V_11 -> V_24 ) * 8 )
/ ( V_11 -> V_25 * V_11 -> V_26 ) ;
return F_10 ( V_23 , 2 ) ;
}
static inline bool F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
if ( F_12 ( V_9 ) || F_13 ( V_9 ) ) {
if ( V_11 -> V_25 == 14 )
return false ;
}
return V_11 -> V_23 <= V_9 -> V_27 -> V_28 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_29 ;
if ( ! ( V_7 -> V_30 > 0 && V_7 -> V_31 > 0 ) )
return - V_32 ;
switch ( V_7 -> V_31 ) {
case V_33 :
V_11 -> V_25 = 13 ;
break;
case V_34 :
V_11 -> V_25 = 14 ;
break;
default:
F_15 ( V_9 -> V_35 ,
L_1 ,
V_7 -> V_30 , V_7 -> V_31 ) ;
return - V_32 ;
}
V_11 -> V_36 = V_7 -> V_31 ;
V_11 -> V_23 = F_16 ( V_7 -> V_30 , 2 ) ;
if ( ! F_11 ( V_9 ) )
return - V_32 ;
if ( V_11 -> V_36 < V_2 -> V_17 ) {
F_15 ( V_9 -> V_35 ,
L_2 ,
V_7 -> V_31 , V_2 -> V_17 ) ;
return - V_32 ;
}
V_11 -> V_24 = 10 ;
V_11 -> V_26 = V_2 -> V_16 / V_11 -> V_36 ;
V_11 -> V_15 = V_2 -> V_16 + V_11 -> V_24 +
( V_11 -> V_25 * V_11 -> V_23 * V_11 -> V_26 ) / 8 ;
V_11 -> V_37 = V_2 -> V_16 ;
V_11 -> V_38 = F_17 ( V_11 -> V_24 , 4 ) ;
V_11 -> V_39 = F_17 ( V_11 -> V_24 , 4 )
+ F_17 ( V_11 -> V_26 , 4 ) ;
if ( ! V_9 -> V_40 )
return 0 ;
V_29 = V_2 -> V_16 * 8 -
( V_11 -> V_23 * V_11 -> V_25 * ( V_11 -> V_26 - 1 )
+ V_11 -> V_24 * 8 ) ;
V_11 -> V_41 = V_29 / 8 ;
V_11 -> V_29 = V_29 % 8 ;
return 0 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_1 * V_2 = F_9 ( & V_9 -> V_22 ) ;
unsigned int V_24 ;
unsigned int V_42 ;
unsigned int V_29 ;
V_11 -> V_24 = 10 ;
V_11 -> V_25 = 13 ;
V_11 -> V_36 = 512 ;
while ( V_11 -> V_36 < V_2 -> V_17 ) {
V_11 -> V_36 *= 2 ;
V_11 -> V_25 = 14 ;
}
V_11 -> V_26 = V_2 -> V_16 / V_11 -> V_36 ;
V_11 -> V_23 = F_8 ( V_9 ) ;
if ( ! F_11 ( V_9 ) ) {
F_15 ( V_9 -> V_35 ,
L_3
L_4 ,
V_11 -> V_23 ,
V_9 -> V_27 -> V_28 ) ;
return - V_32 ;
}
V_11 -> V_15 = V_2 -> V_16 + V_11 -> V_24 +
( V_11 -> V_25 * V_11 -> V_23 * V_11 -> V_26 ) / 8 ;
V_11 -> V_37 = V_2 -> V_16 ;
V_24 = F_17 ( V_11 -> V_24 , 4 ) ;
V_42 = F_17 ( V_11 -> V_26 , 4 ) ;
V_11 -> V_39 = V_24 + V_42 ;
V_11 -> V_38 = V_24 ;
if ( ! V_9 -> V_40 )
return 0 ;
V_29 = V_2 -> V_16 * 8 -
( V_11 -> V_23 * V_11 -> V_25 * ( V_11 -> V_26 - 1 )
+ V_11 -> V_24 * 8 ) ;
V_11 -> V_41 = V_29 / 8 ;
V_11 -> V_29 = V_29 % 8 ;
return 0 ;
}
int F_19 ( struct V_8 * V_9 )
{
if ( ( F_20 ( V_9 -> V_35 -> V_43 , L_5 ) )
|| F_18 ( V_9 ) )
return F_14 ( V_9 ) ;
return 0 ;
}
struct V_44 * F_21 ( struct V_8 * V_9 )
{
return V_9 -> V_45 [ 0 ] ;
}
void F_22 ( struct V_8 * V_9 , enum V_46 V_47 )
{
struct V_48 * V_49 = & V_9 -> V_50 ;
int V_51 ;
if ( F_23 ( V_9 -> V_52 ) &&
! F_24 ( V_9 -> V_52 ) ) {
F_25 ( V_49 , V_9 -> V_52 , V_9 -> V_53 ) ;
V_51 = F_26 ( V_9 -> V_35 , V_49 , 1 , V_47 ) ;
if ( V_51 == 0 )
goto V_54;
V_9 -> V_55 = true ;
return;
}
V_54:
F_25 ( V_49 , V_9 -> V_56 , V_9 -> V_53 ) ;
if ( V_47 == V_57 )
memcpy ( V_9 -> V_56 , V_9 -> V_52 , V_9 -> V_53 ) ;
F_26 ( V_9 -> V_35 , V_49 , 1 , V_47 ) ;
V_9 -> V_55 = false ;
}
static void F_27 ( void * V_58 )
{
struct V_8 * V_9 = V_58 ;
struct V_59 * V_60 = & V_9 -> V_61 ;
switch ( V_9 -> V_62 ) {
case V_63 :
F_28 ( V_9 -> V_35 , & V_9 -> V_64 , 1 , V_57 ) ;
break;
case V_65 :
F_28 ( V_9 -> V_35 , & V_9 -> V_50 , 1 , V_66 ) ;
if ( V_9 -> V_55 == false )
memcpy ( V_9 -> V_52 , V_9 -> V_56 ,
V_9 -> V_53 ) ;
break;
case V_67 :
F_28 ( V_9 -> V_35 , & V_9 -> V_50 , 1 , V_57 ) ;
break;
case V_68 :
case V_69 :
break;
default:
F_15 ( V_9 -> V_35 , L_6 ) ;
}
F_7 ( V_60 ) ;
}
int F_29 ( struct V_8 * V_9 ,
struct V_70 * V_71 )
{
struct V_59 * V_60 = & V_9 -> V_61 ;
unsigned long V_72 ;
F_30 ( V_60 ) ;
V_71 -> V_73 = F_27 ;
V_71 -> V_74 = V_9 ;
F_31 ( V_71 ) ;
F_32 ( F_21 ( V_9 ) ) ;
V_72 = F_33 ( V_60 , F_34 ( 1000 ) ) ;
if ( ! V_72 ) {
F_15 ( V_9 -> V_35 , L_7 ,
V_9 -> V_75 ) ;
F_35 ( V_9 ) ;
return - V_76 ;
}
return 0 ;
}
int F_36 ( struct V_8 * V_9 ,
struct V_70 * V_71 )
{
struct V_59 * V_77 = & V_9 -> V_20 ;
unsigned long V_72 ;
F_30 ( V_77 ) ;
F_29 ( V_9 , V_71 ) ;
V_72 = F_33 ( V_77 , F_34 ( 1000 ) ) ;
if ( ! V_72 ) {
F_15 ( V_9 -> V_35 , L_8 ,
V_9 -> V_75 ) ;
F_35 ( V_9 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_37 ( struct V_8 * V_9 ,
const char * V_78 )
{
struct V_79 * V_80 = V_9 -> V_80 ;
struct V_81 * V_82 = & V_9 -> V_81 ;
struct V_83 * V_84 ;
void T_2 * V_85 ;
V_84 = F_38 ( V_80 , V_86 , V_78 ) ;
V_85 = F_39 ( & V_80 -> V_35 , V_84 ) ;
if ( F_40 ( V_85 ) )
return F_41 ( V_85 ) ;
if ( ! strcmp ( V_78 , V_87 ) )
V_82 -> V_88 = V_85 ;
else if ( ! strcmp ( V_78 , V_89 ) )
V_82 -> V_90 = V_85 ;
else
F_15 ( V_9 -> V_35 , L_9 , V_78 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , T_3 V_91 )
{
struct V_79 * V_80 = V_9 -> V_80 ;
const char * V_78 = V_92 ;
struct V_83 * V_84 ;
int V_93 ;
V_84 = F_38 ( V_80 , V_94 , V_78 ) ;
if ( ! V_84 ) {
F_15 ( V_9 -> V_35 , L_10 , V_78 ) ;
return - V_95 ;
}
V_93 = F_43 ( V_9 -> V_35 , V_84 -> V_96 , V_91 , 0 , V_78 , V_9 ) ;
if ( V_93 )
F_15 ( V_9 -> V_35 , L_11 ) ;
return V_93 ;
}
static void F_44 ( struct V_8 * V_9 )
{
unsigned int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ )
if ( V_9 -> V_45 [ V_97 ] ) {
F_45 ( V_9 -> V_45 [ V_97 ] ) ;
V_9 -> V_45 [ V_97 ] = NULL ;
}
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_79 * V_80 = V_9 -> V_80 ;
struct V_44 * V_44 ;
V_44 = F_47 ( & V_80 -> V_35 , L_12 ) ;
if ( ! V_44 ) {
F_15 ( V_9 -> V_35 , L_13 ) ;
goto V_99;
}
V_9 -> V_45 [ 0 ] = V_44 ;
return 0 ;
V_99:
F_44 ( V_9 ) ;
return - V_32 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_81 * V_84 = & V_9 -> V_81 ;
char * * V_100 = NULL ;
struct V_101 * V_101 ;
int V_93 , V_97 ;
V_84 -> clock [ 0 ] = F_49 ( V_9 -> V_35 , L_14 ) ;
if ( F_40 ( V_84 -> clock [ 0 ] ) ) {
V_93 = F_41 ( V_84 -> clock [ 0 ] ) ;
goto V_102;
}
if ( F_50 ( V_9 ) )
V_100 = V_103 ;
if ( ! V_100 )
return 0 ;
for ( V_97 = 1 ; V_97 < V_104 ; V_97 ++ ) {
if ( V_100 [ V_97 - 1 ] == NULL )
break;
V_101 = F_49 ( V_9 -> V_35 , V_100 [ V_97 - 1 ] ) ;
if ( F_40 ( V_101 ) ) {
V_93 = F_41 ( V_101 ) ;
goto V_102;
}
V_84 -> clock [ V_97 ] = V_101 ;
}
if ( F_50 ( V_9 ) )
F_51 ( V_84 -> clock [ 0 ] , 22000000 ) ;
return 0 ;
V_102:
F_52 ( V_9 -> V_35 , L_15 ) ;
return V_93 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_51 ;
V_51 = F_37 ( V_9 , V_87 ) ;
if ( V_51 )
goto V_105;
V_51 = F_37 ( V_9 , V_89 ) ;
if ( V_51 )
goto V_105;
V_51 = F_42 ( V_9 , F_5 ) ;
if ( V_51 )
goto V_105;
V_51 = F_46 ( V_9 ) ;
if ( V_51 )
goto V_105;
V_51 = F_48 ( V_9 ) ;
if ( V_51 )
goto V_106;
return 0 ;
V_106:
F_44 ( V_9 ) ;
V_105:
return V_51 ;
}
static void F_54 ( struct V_8 * V_9 )
{
F_44 ( V_9 ) ;
}
static int F_55 ( struct V_8 * V_9 )
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
V_51 = F_56 ( V_9 ) ;
if ( V_51 )
return V_51 ;
V_9 -> V_116 = V_108 ;
return 0 ;
}
static int F_57 ( struct V_8 * V_9 ,
void * V_117 , unsigned V_14 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
void * * V_121 , T_4 * V_122 )
{
struct V_123 * V_35 = V_9 -> V_35 ;
if ( F_23 ( V_117 ) ) {
T_4 V_124 ;
V_124 = F_58 ( V_35 , V_117 ,
V_14 , V_66 ) ;
if ( F_59 ( V_35 , V_124 ) ) {
if ( V_120 < V_14 ) {
F_15 ( V_35 , L_16 ) ;
return - V_125 ;
}
goto V_126;
}
* V_121 = V_117 ;
* V_122 = V_124 ;
V_9 -> V_55 = true ;
return 0 ;
}
V_126:
* V_121 = V_118 ;
* V_122 = V_119 ;
V_9 -> V_55 = false ;
return 0 ;
}
static inline void F_60 ( struct V_8 * V_9 ,
void * V_117 , unsigned V_14 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
void * V_127 , T_4 V_128 )
{
if ( V_9 -> V_55 )
F_61 ( V_9 -> V_35 , V_128 , V_14 , V_66 ) ;
}
static inline void F_62 ( struct V_8 * V_9 ,
void * V_117 , unsigned V_14 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
void * V_127 , T_4 V_128 )
{
if ( ! V_9 -> V_55 )
memcpy ( V_117 , V_118 , V_14 ) ;
}
static int F_63 ( struct V_8 * V_9 ,
const void * V_129 , unsigned V_14 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
const void * * V_121 , T_4 * V_122 )
{
struct V_123 * V_35 = V_9 -> V_35 ;
if ( F_23 ( V_129 ) ) {
T_4 V_130 ;
V_130 = F_58 ( V_35 , ( void * ) V_129 , V_14 ,
V_57 ) ;
if ( F_59 ( V_35 , V_130 ) ) {
if ( V_120 < V_14 ) {
F_15 ( V_35 , L_16 ) ;
return - V_125 ;
}
goto V_126;
}
* V_121 = V_129 ;
* V_122 = V_130 ;
return 0 ;
}
V_126:
memcpy ( V_118 , V_129 , V_14 ) ;
* V_121 = V_118 ;
* V_122 = V_119 ;
return 0 ;
}
static void F_64 ( struct V_8 * V_9 ,
const void * V_129 , unsigned V_14 ,
void * V_118 , T_4 V_119 , unsigned V_120 ,
const void * V_127 , T_4 V_128 )
{
struct V_123 * V_35 = V_9 -> V_35 ;
if ( V_127 == V_129 )
F_61 ( V_35 , V_128 , V_14 , V_57 ) ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_123 * V_35 = V_9 -> V_35 ;
if ( V_9 -> V_131 && F_23 ( V_9 -> V_131 ) )
F_66 ( V_35 , V_9 -> V_132 ,
V_9 -> V_131 ,
V_9 -> V_133 ) ;
F_67 ( V_9 -> V_134 ) ;
F_67 ( V_9 -> V_56 ) ;
F_67 ( V_9 -> V_135 ) ;
V_9 -> V_134 = NULL ;
V_9 -> V_56 = NULL ;
V_9 -> V_135 = NULL ;
V_9 -> V_131 = NULL ;
V_9 -> V_132 = 0 ;
}
static int F_68 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_10 ;
struct V_123 * V_35 = V_9 -> V_35 ;
struct V_1 * V_2 = F_9 ( & V_9 -> V_22 ) ;
V_9 -> V_134 = F_69 ( V_136 , V_137 | V_138 ) ;
if ( V_9 -> V_134 == NULL )
goto V_139;
V_9 -> V_56 = F_69 ( V_2 -> V_16 ? : V_136 ,
V_137 | V_138 ) ;
if ( V_9 -> V_56 == NULL )
goto V_139;
V_9 -> V_132 = V_11 -> V_37 + V_11 -> V_39 ;
V_9 -> V_131 = F_70 ( V_35 , V_9 -> V_132 ,
& V_9 -> V_133 , V_137 ) ;
if ( ! V_9 -> V_131 )
goto V_139;
V_9 -> V_135 = F_69 ( V_2 -> V_16 + V_2 -> V_17 , V_138 ) ;
if ( ! V_9 -> V_135 )
goto V_139;
V_9 -> V_140 = V_9 -> V_131 ;
V_9 -> V_141 = V_9 -> V_133 ;
V_9 -> V_142 = V_9 -> V_140 + V_11 -> V_37 ;
V_9 -> V_143 = V_9 -> V_141 + V_11 -> V_37 ;
return 0 ;
V_139:
F_65 ( V_9 ) ;
return - V_125 ;
}
static void F_71 ( struct V_1 * V_2 , int V_144 , unsigned int V_145 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_51 ;
if ( ( V_145 & ( V_146 | V_147 ) ) ) {
if ( V_144 != V_148 )
V_9 -> V_134 [ V_9 -> V_149 ++ ] = V_144 ;
return;
}
if ( ! V_9 -> V_149 )
return;
V_51 = F_72 ( V_9 ) ;
if ( V_51 )
F_15 ( V_9 -> V_35 , L_17 ,
V_9 -> V_150 , V_51 ) ;
V_9 -> V_149 = 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return F_74 ( V_9 , V_9 -> V_150 ) ;
}
static void F_75 ( struct V_1 * V_2 , int V_151 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ( V_9 -> V_150 < 0 ) && ( V_151 >= 0 ) )
F_76 ( V_9 ) ;
else if ( ( V_9 -> V_150 >= 0 ) && ( V_151 < 0 ) )
F_77 ( V_9 ) ;
V_9 -> V_150 = V_151 ;
}
static void F_78 ( struct V_1 * V_2 , T_5 * V_152 , int V_153 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_52 ( V_9 -> V_35 , L_18 , V_153 ) ;
V_9 -> V_52 = V_152 ;
V_9 -> V_53 = V_153 ;
F_79 ( V_9 ) ;
}
static void F_80 ( struct V_1 * V_2 , const T_5 * V_152 , int V_153 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_52 ( V_9 -> V_35 , L_18 , V_153 ) ;
V_9 -> V_52 = ( T_5 * ) V_152 ;
V_9 -> V_53 = V_153 ;
F_81 ( V_9 ) ;
}
static T_5 F_82 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_5 * V_152 = V_9 -> V_56 ;
F_78 ( V_2 , V_152 , 1 ) ;
return V_152 [ 0 ] ;
}
static void F_83 ( struct V_8 * V_9 ,
void * V_154 , void * V_155 )
{
struct V_10 * V_156 = & V_9 -> V_10 ;
unsigned char * V_85 ;
unsigned char * V_157 ;
unsigned int V_158 ;
unsigned char V_159 ;
unsigned char V_160 ;
unsigned char V_161 ;
if ( ! V_9 -> V_40 )
return;
V_158 = V_156 -> V_29 ;
V_85 = V_154 + V_156 -> V_41 ;
V_157 = V_155 ;
V_160 = ( V_85 [ 0 ] >> V_158 ) | ( V_85 [ 1 ] << ( 8 - V_158 ) ) ;
V_161 = V_157 [ 0 ] ;
V_157 [ 0 ] = V_160 ;
V_159 = ( 0x1 << V_158 ) - 1 ;
V_85 [ 0 ] = ( V_85 [ 0 ] & V_159 ) | ( V_161 << V_158 ) ;
V_159 = ~ 0 << V_158 ;
V_85 [ 1 ] = ( V_85 [ 1 ] & V_159 ) | ( V_161 >> ( 8 - V_158 ) ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_5 * V_152 , int V_162 , int V_163 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_156 = & V_9 -> V_10 ;
void * V_140 ;
T_4 V_141 ;
void * V_142 ;
T_4 V_143 ;
unsigned int V_97 ;
unsigned char * V_164 ;
unsigned int V_165 = 0 ;
int V_51 ;
F_52 ( V_9 -> V_35 , L_19 , V_163 ) ;
V_51 = F_57 ( V_9 , V_152 , V_156 -> V_37 ,
V_9 -> V_140 , V_9 -> V_141 ,
V_156 -> V_37 ,
& V_140 , & V_141 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_20 ) ;
V_51 = - V_125 ;
return V_51 ;
}
V_142 = V_9 -> V_142 ;
V_143 = V_9 -> V_143 ;
V_51 = F_85 ( V_9 , V_141 , V_143 ) ;
F_60 ( V_9 , V_152 , V_156 -> V_37 ,
V_9 -> V_140 , V_9 -> V_141 ,
V_156 -> V_37 ,
V_140 , V_141 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_21 , V_51 ) ;
return V_51 ;
}
F_83 ( V_9 , V_140 , V_142 ) ;
V_164 = V_142 + V_156 -> V_38 ;
F_62 ( V_9 , V_152 , V_156 -> V_37 ,
V_9 -> V_140 , V_9 -> V_141 ,
V_156 -> V_37 ,
V_140 , V_141 ) ;
for ( V_97 = 0 ; V_97 < V_156 -> V_26 ; V_97 ++ , V_164 ++ ) {
if ( ( * V_164 == V_166 ) || ( * V_164 == V_167 ) )
continue;
if ( * V_164 == V_168 ) {
int V_169 = V_156 -> V_23 * V_156 -> V_25 ;
T_6 * V_170 = V_9 -> V_135 ;
int V_13 , V_171 ;
int V_172 ;
int V_173 ;
V_13 = V_156 -> V_24 * 8 ;
V_13 += ( ( 8 * V_156 -> V_36 ) + V_169 ) * ( V_97 + 1 ) ;
V_13 -= V_169 ;
V_171 = V_13 % 8 ;
V_172 = F_86 ( V_13 + V_169 , 8 ) ;
V_13 /= 8 ;
V_172 -= V_13 ;
V_7 -> V_174 ( V_2 , V_175 , V_13 , - 1 ) ;
V_7 -> V_176 ( V_2 , V_170 , V_172 ) ;
if ( V_171 )
V_170 [ 0 ] |= F_87 ( V_171 - 1 , 0 ) ;
V_171 = ( V_171 + V_169 ) % 8 ;
if ( V_171 )
V_170 [ V_172 - 1 ] |= F_87 ( 7 , V_171 ) ;
if ( V_97 == 0 ) {
V_173 = F_88 (
V_152 + V_97 * V_156 -> V_36 ,
V_156 -> V_36 ,
V_170 , V_172 ,
V_142 ,
V_156 -> V_24 ,
V_156 -> V_23 ) ;
} else {
V_173 = F_88 (
V_152 + V_97 * V_156 -> V_36 ,
V_156 -> V_36 ,
V_170 , V_172 ,
NULL , 0 ,
V_156 -> V_23 ) ;
}
if ( V_173 > 0 ) {
V_165 = F_89 (unsigned int, max_bitflips,
flips) ;
V_2 -> V_177 . V_178 += V_173 ;
continue;
}
V_2 -> V_177 . V_179 ++ ;
continue;
}
V_2 -> V_177 . V_178 += * V_164 ;
V_165 = F_89 (unsigned int, max_bitflips, *status) ;
}
if ( V_162 ) {
memset ( V_7 -> V_180 , ~ 0 , V_2 -> V_17 ) ;
V_7 -> V_180 [ 0 ] = ( ( T_5 * ) V_142 ) [ 0 ] ;
}
return V_165 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_7 V_181 , T_7 V_153 , T_5 * V_152 , int V_163 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
void T_2 * V_90 = V_9 -> V_81 . V_90 ;
struct V_10 V_182 = V_9 -> V_10 ;
struct V_10 * V_11 = & V_9 -> V_10 ;
int V_183 = V_7 -> V_184 . V_183 ;
int V_185 , V_186 , V_15 ;
T_8 V_187 , V_188 , V_189 , V_190 ;
unsigned int V_165 ;
int V_191 , V_192 , V_193 ;
int V_194 ;
int V_195 = 0 ;
int V_196 = V_9 -> V_40 ;
V_194 = V_11 -> V_25 * V_11 -> V_23 / 8 ;
V_191 = V_181 / V_183 ;
V_192 = ( V_181 + V_153 - 1 ) / V_183 ;
if ( V_9 -> V_40 ) {
V_193 = V_11 -> V_41 / V_183 ;
if ( V_192 >= V_193 && V_191 <= V_193 ) {
F_52 ( V_9 -> V_35 ,
L_22 ,
V_163 , V_191 , V_192 , V_193 ) ;
return F_84 ( V_2 , V_7 , V_152 , 0 , V_163 ) ;
}
}
V_185 = V_11 -> V_24 ;
if ( V_191 ) {
V_195 = V_185 + ( V_183 + V_194 ) * V_191 ;
V_7 -> V_174 ( V_2 , V_175 , V_195 , - 1 ) ;
V_185 = 0 ;
V_152 = V_152 + V_191 * V_183 ;
}
V_187 = V_189 = F_91 ( V_90 + V_197 ) ;
V_188 = V_190 = F_91 ( V_90 + V_198 ) ;
V_186 = V_192 - V_191 + 1 ;
V_15 = V_185 + ( V_183 + V_194 ) * V_186 ;
V_189 &= ~ ( V_199 |
V_200 ) ;
V_189 |= F_92 ( V_186 - 1 )
| F_93 ( V_185 ) ;
F_94 ( V_189 , V_90 + V_197 ) ;
V_190 &= ~ V_201 ;
V_190 |= F_95 ( V_15 ) ;
F_94 ( V_190 , V_90 + V_198 ) ;
V_11 -> V_26 = V_186 ;
V_11 -> V_37 = V_186 * V_183 ;
V_11 -> V_15 = V_15 ;
V_11 -> V_38 = F_17 ( V_185 , 4 ) ;
F_52 ( V_9 -> V_35 , L_23 ,
V_163 , V_181 , V_153 , V_195 , V_191 , V_186 , V_15 ) ;
V_9 -> V_40 = false ;
V_165 = F_84 ( V_2 , V_7 , V_152 , 0 , V_163 ) ;
F_94 ( V_187 , V_90 + V_197 ) ;
F_94 ( V_188 , V_90 + V_198 ) ;
V_9 -> V_10 = V_182 ;
V_9 -> V_40 = V_196 ;
return V_165 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_6 * V_7 ,
const T_5 * V_152 , int V_162 , int V_163 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_156 = & V_9 -> V_10 ;
const void * V_140 ;
T_4 V_141 ;
const void * V_142 ;
T_4 V_143 ;
int V_51 ;
F_52 ( V_9 -> V_35 , L_24 ) ;
if ( V_9 -> V_40 ) {
memcpy ( V_9 -> V_140 , V_152 , V_2 -> V_16 ) ;
V_140 = V_9 -> V_140 ;
V_141 = V_9 -> V_141 ;
memcpy ( V_9 -> V_142 , V_7 -> V_180 ,
V_156 -> V_39 ) ;
V_142 = V_9 -> V_142 ;
V_143 = V_9 -> V_143 ;
F_83 ( V_9 ,
( void * ) V_140 , ( void * ) V_142 ) ;
} else {
V_51 = F_63 ( V_9 ,
V_152 , V_2 -> V_16 ,
V_9 -> V_140 , V_9 -> V_141 ,
V_156 -> V_37 ,
& V_140 , & V_141 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_25 ) ;
return 0 ;
}
V_51 = F_63 ( V_9 ,
V_7 -> V_180 , V_2 -> V_17 ,
V_9 -> V_142 , V_9 -> V_143 ,
V_156 -> V_39 ,
& V_142 , & V_143 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_26 ) ;
goto V_202;
}
}
V_51 = F_97 ( V_9 , V_141 , V_143 ) ;
if ( V_51 )
F_15 ( V_9 -> V_35 , L_27 , V_51 ) ;
if ( ! V_9 -> V_40 ) {
F_64 ( V_9 , V_7 -> V_180 , V_2 -> V_17 ,
V_9 -> V_142 , V_9 -> V_143 ,
V_156 -> V_39 ,
V_142 , V_143 ) ;
V_202:
F_64 ( V_9 , V_152 , V_2 -> V_16 ,
V_9 -> V_140 , V_9 -> V_141 ,
V_156 -> V_37 ,
V_140 , V_141 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_163 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_52 ( V_9 -> V_35 , L_28 , V_163 ) ;
memset ( V_7 -> V_180 , ~ 0 , V_2 -> V_17 ) ;
V_7 -> V_174 ( V_2 , V_203 , V_2 -> V_16 , V_163 ) ;
V_7 -> V_176 ( V_2 , V_7 -> V_180 , V_2 -> V_17 ) ;
if ( F_12 ( V_9 ) ) {
V_7 -> V_174 ( V_2 , V_203 , 0 , V_163 ) ;
V_7 -> V_180 [ 0 ] = V_7 -> V_204 ( V_2 ) ;
}
return 0 ;
}
static int
F_99 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_163 )
{
struct V_4 V_205 = { } ;
int V_164 = 0 ;
F_100 ( V_2 , 0 , & V_205 ) ;
if ( ! V_205 . V_14 )
return - V_206 ;
if ( ! F_101 ( V_7 ) )
return - V_206 ;
V_7 -> V_174 ( V_2 , V_207 , V_2 -> V_16 + V_205 . V_13 , V_163 ) ;
V_7 -> V_208 ( V_2 , V_7 -> V_180 + V_205 . V_13 , V_205 . V_14 ) ;
V_7 -> V_174 ( V_2 , V_209 , - 1 , - 1 ) ;
V_164 = V_7 -> V_210 ( V_2 , V_7 ) ;
return V_164 & V_211 ? - V_212 : 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_6 * V_7 , T_5 * V_152 ,
int V_162 , int V_163 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_156 = & V_9 -> V_10 ;
int V_213 = V_156 -> V_36 ;
int V_169 = V_156 -> V_23 * V_156 -> V_25 ;
T_6 * V_214 = V_9 -> V_135 ;
T_9 V_215 ;
T_9 V_216 ;
T_9 V_217 ;
T_5 * V_218 = V_7 -> V_180 ;
int V_219 ;
V_7 -> V_176 ( V_2 , V_214 ,
V_2 -> V_16 + V_2 -> V_17 ) ;
if ( V_9 -> V_40 ) {
T_6 V_220 = V_214 [ 0 ] ;
V_214 [ 0 ] = V_214 [ V_2 -> V_16 ] ;
V_214 [ V_2 -> V_16 ] = V_220 ;
}
if ( V_162 )
memcpy ( V_218 , V_214 , V_156 -> V_24 ) ;
V_216 = V_156 -> V_24 * 8 ;
V_215 = V_216 ;
for ( V_219 = 0 ; V_219 < V_156 -> V_26 ; V_219 ++ ) {
if ( V_152 )
F_103 ( V_152 , V_219 * V_213 * 8 ,
V_214 , V_215 ,
V_213 * 8 ) ;
V_215 += V_213 * 8 ;
if ( V_219 == V_156 -> V_26 - 1 &&
( V_216 + V_169 ) % 8 )
V_169 += 8 - ( ( V_216 + V_169 ) % 8 ) ;
if ( V_162 )
F_103 ( V_218 , V_216 ,
V_214 , V_215 ,
V_169 ) ;
V_215 += V_169 ;
V_216 += V_169 ;
}
if ( V_162 ) {
V_217 = V_216 / 8 ;
if ( V_217 < V_2 -> V_17 )
memcpy ( V_218 + V_217 ,
V_214 + V_2 -> V_16 + V_217 ,
V_2 -> V_17 - V_217 ) ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_5 * V_152 ,
int V_162 , int V_163 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_10 * V_156 = & V_9 -> V_10 ;
int V_213 = V_156 -> V_36 ;
int V_169 = V_156 -> V_23 * V_156 -> V_25 ;
T_6 * V_214 = V_9 -> V_135 ;
T_5 * V_218 = V_7 -> V_180 ;
T_9 V_221 ;
T_9 V_216 ;
T_9 V_217 ;
int V_219 ;
if ( ! V_152 || ! V_162 )
memset ( V_214 , 0xff , V_2 -> V_16 + V_2 -> V_17 ) ;
memcpy ( V_214 , V_218 , V_156 -> V_24 ) ;
V_216 = V_156 -> V_24 * 8 ;
V_221 = V_216 ;
for ( V_219 = 0 ; V_219 < V_156 -> V_26 ; V_219 ++ ) {
if ( V_152 )
F_103 ( V_214 , V_221 ,
V_152 , V_219 * V_213 * 8 , V_213 * 8 ) ;
V_221 += V_213 * 8 ;
if ( V_219 == V_156 -> V_26 - 1 &&
( V_216 + V_169 ) % 8 )
V_169 += 8 - ( ( V_216 + V_169 ) % 8 ) ;
if ( V_162 )
F_103 ( V_214 , V_221 ,
V_218 , V_216 , V_169 ) ;
V_221 += V_169 ;
V_216 += V_169 ;
}
V_217 = V_216 / 8 ;
if ( V_162 && V_217 < V_2 -> V_17 )
memcpy ( V_214 + V_2 -> V_16 + V_217 ,
V_218 + V_217 , V_2 -> V_17 - V_217 ) ;
if ( V_9 -> V_40 ) {
T_6 V_220 = V_214 [ 0 ] ;
V_214 [ 0 ] = V_214 [ V_2 -> V_16 ] ;
V_214 [ V_2 -> V_16 ] = V_220 ;
}
V_7 -> V_208 ( V_2 , V_214 , V_2 -> V_16 + V_2 -> V_17 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_163 )
{
V_7 -> V_174 ( V_2 , V_203 , 0 , V_163 ) ;
return F_102 ( V_2 , V_7 , NULL , 1 , V_163 ) ;
}
static int F_106 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_163 )
{
V_7 -> V_174 ( V_2 , V_207 , 0 , V_163 ) ;
return F_104 ( V_2 , V_7 , NULL , 1 , V_163 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_10 V_222 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_51 = 0 ;
T_5 * V_223 ;
int V_224 , V_163 , V_164 , V_151 ;
V_151 = ( int ) ( V_222 >> V_7 -> V_225 ) ;
V_7 -> V_226 ( V_2 , V_151 ) ;
V_224 = ! F_12 ( V_9 ) ? V_2 -> V_16 : 0 ;
V_223 = V_9 -> V_56 ;
V_223 [ 0 ] = 0 ;
V_163 = ( int ) ( V_222 >> V_7 -> V_227 ) ;
V_7 -> V_174 ( V_2 , V_207 , V_224 , V_163 ) ;
V_7 -> V_208 ( V_2 , V_223 , 1 ) ;
V_7 -> V_174 ( V_2 , V_209 , - 1 , - 1 ) ;
V_164 = V_7 -> V_210 ( V_2 , V_7 ) ;
if ( V_164 & V_211 )
V_51 = - V_212 ;
V_7 -> V_226 ( V_2 , - 1 ) ;
return V_51 ;
}
static int F_108 ( struct V_8 * V_9 )
{
struct V_228 * V_229 = & V_9 -> V_230 ;
V_229 -> V_231 = 64 ;
V_229 -> V_232 = 2 ;
return 0 ;
}
static int F_109 ( struct V_8 * V_9 )
{
struct V_228 * V_233 = & V_9 -> V_230 ;
struct V_123 * V_35 = V_9 -> V_35 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_234 ;
unsigned int V_235 ;
unsigned int V_163 ;
T_5 * V_236 = V_7 -> V_237 -> V_238 ;
int V_239 ;
int V_240 = false ;
V_234 = 1 << V_233 -> V_232 ;
V_239 = V_9 -> V_150 ;
V_7 -> V_226 ( V_2 , 0 ) ;
F_52 ( V_35 , L_29 ) ;
for ( V_235 = 0 ; V_235 < V_234 ; V_235 ++ ) {
V_163 = V_235 * V_233 -> V_231 ;
F_52 ( V_35 , L_30 , V_163 ) ;
V_7 -> V_174 ( V_2 , V_203 , 12 , V_163 ) ;
V_7 -> V_176 ( V_2 , V_236 , strlen ( V_241 ) ) ;
if ( ! memcmp ( V_236 , V_241 , strlen ( V_241 ) ) ) {
V_240 = true ;
break;
}
}
V_7 -> V_226 ( V_2 , V_239 ) ;
if ( V_240 )
F_52 ( V_35 , L_31 ) ;
else
F_52 ( V_35 , L_32 ) ;
return V_240 ;
}
static int F_110 ( struct V_8 * V_9 )
{
struct V_123 * V_35 = V_9 -> V_35 ;
struct V_228 * V_233 = & V_9 -> V_230 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_242 ;
unsigned int V_234 ;
unsigned int V_243 ;
unsigned int V_244 ;
unsigned int V_245 ;
unsigned int V_235 ;
unsigned int V_163 ;
T_5 * V_236 = V_7 -> V_237 -> V_238 ;
int V_239 ;
int V_164 ;
V_242 = V_2 -> V_246 / V_2 -> V_16 ;
V_234 = 1 << V_233 -> V_232 ;
V_243 = V_234 *
V_233 -> V_231 ;
V_244 =
( V_243 + ( V_242 - 1 ) ) /
V_242 ;
F_52 ( V_35 , L_33 ) ;
F_52 ( V_35 , L_34 , V_244 ) ;
F_52 ( V_35 , L_35 , V_234 ) ;
F_52 ( V_35 , L_36 , V_243 ) ;
V_239 = V_9 -> V_150 ;
V_7 -> V_226 ( V_2 , 0 ) ;
F_52 ( V_35 , L_37 ) ;
for ( V_245 = 0 ; V_245 < V_244 ; V_245 ++ ) {
V_163 = V_245 * V_242 ;
F_52 ( V_35 , L_38 , V_245 ) ;
V_7 -> V_174 ( V_2 , V_247 , - 1 , V_163 ) ;
V_7 -> V_174 ( V_2 , V_248 , - 1 , - 1 ) ;
V_164 = V_7 -> V_210 ( V_2 , V_7 ) ;
if ( V_164 & V_211 )
F_15 ( V_35 , L_39 , V_249 ) ;
}
memset ( V_236 , ~ 0 , V_2 -> V_16 ) ;
memcpy ( V_236 + 12 , V_241 , strlen ( V_241 ) ) ;
F_52 ( V_35 , L_40 ) ;
for ( V_235 = 0 ; V_235 < V_234 ; V_235 ++ ) {
V_163 = V_235 * V_233 -> V_231 ;
F_52 ( V_35 , L_41 , V_163 ) ;
V_7 -> V_174 ( V_2 , V_207 , 0x00 , V_163 ) ;
V_7 -> V_184 . V_250 ( V_2 , V_7 , V_236 , 0 , V_163 ) ;
V_7 -> V_174 ( V_2 , V_209 , - 1 , - 1 ) ;
V_164 = V_7 -> V_210 ( V_2 , V_7 ) ;
if ( V_164 & V_211 )
F_15 ( V_35 , L_42 , V_249 ) ;
}
V_7 -> V_226 ( V_2 , V_239 ) ;
return 0 ;
}
static int F_111 ( struct V_8 * V_9 )
{
struct V_123 * V_35 = V_9 -> V_35 ;
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
unsigned int V_251 ;
unsigned int V_245 ;
int V_151 ;
int V_163 ;
T_10 V_252 ;
T_5 V_223 ;
int V_51 = 0 ;
if ( F_109 ( V_9 ) )
return 0 ;
F_52 ( V_35 , L_43 ) ;
V_251 = V_7 -> V_253 >> V_7 -> V_254 ;
for ( V_245 = 0 ; V_245 < V_251 ; V_245 ++ ) {
V_151 = V_245 >> ( V_7 -> V_225 - V_7 -> V_254 ) ;
V_163 = V_245 << ( V_7 -> V_254 - V_7 -> V_227 ) ;
V_252 = V_245 << V_7 -> V_254 ;
V_7 -> V_226 ( V_2 , V_151 ) ;
V_7 -> V_174 ( V_2 , V_203 , V_2 -> V_16 , V_163 ) ;
V_223 = V_7 -> V_204 ( V_2 ) ;
V_7 -> V_226 ( V_2 , - 1 ) ;
if ( V_223 != 0xff ) {
F_52 ( V_35 , L_44 , V_245 ) ;
V_51 = V_7 -> V_255 ( V_2 , V_252 ) ;
if ( V_51 )
F_15 ( V_35 ,
L_45 ,
V_51 ) ;
}
}
F_110 ( V_9 ) ;
return 0 ;
}
static int F_112 ( struct V_8 * V_9 )
{
F_108 ( V_9 ) ;
if ( F_12 ( V_9 ) )
return F_111 ( V_9 ) ;
return 0 ;
}
static int F_113 ( struct V_8 * V_9 )
{
int V_51 ;
F_65 ( V_9 ) ;
V_51 = F_114 ( V_9 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_46 , V_51 ) ;
return V_51 ;
}
return F_68 ( V_9 ) ;
}
static void F_115 ( struct V_8 * V_9 )
{
F_116 ( F_9 ( & V_9 -> V_22 ) ) ;
F_65 ( V_9 ) ;
}
static int F_117 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
struct V_256 * V_184 = & V_7 -> V_184 ;
struct V_10 * V_257 = & V_9 -> V_10 ;
int V_51 ;
V_51 = F_113 ( V_9 ) ;
if ( V_51 )
return V_51 ;
V_184 -> V_258 = F_84 ;
V_184 -> V_259 = F_96 ;
V_184 -> V_260 = F_98 ;
V_184 -> V_261 = F_99 ;
V_184 -> V_262 = F_102 ;
V_184 -> V_250 = F_104 ;
V_184 -> V_263 = F_105 ;
V_184 -> V_264 = F_106 ;
V_184 -> V_265 = V_266 ;
V_184 -> V_183 = V_257 -> V_36 ;
V_184 -> V_267 = V_257 -> V_23 ;
F_118 ( V_2 , & V_268 ) ;
if ( F_50 ( V_9 ) &&
( ( V_257 -> V_25 * V_257 -> V_23 ) % 8 ) == 0 ) {
V_184 -> V_269 = F_90 ;
V_7 -> V_270 |= V_271 ;
}
F_119 ( V_9 ) ;
return 0 ;
}
static int F_120 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = & V_9 -> V_22 ;
struct V_1 * V_2 = F_9 ( V_7 ) ;
int V_51 ;
V_9 -> V_150 = - 1 ;
V_2 -> V_272 = L_47 ;
V_2 -> V_35 . V_273 = V_9 -> V_35 ;
F_121 ( V_7 , V_9 ) ;
F_122 ( V_7 , V_9 -> V_80 -> V_35 . V_43 ) ;
V_7 -> V_226 = F_75 ;
V_7 -> V_274 = F_71 ;
V_7 -> V_275 = F_73 ;
V_7 -> V_204 = F_82 ;
V_7 -> V_176 = F_78 ;
V_7 -> V_208 = F_80 ;
V_7 -> V_276 = & V_277 ;
V_7 -> V_255 = F_107 ;
V_7 -> V_270 |= V_278 ;
V_9 -> V_40 = ! F_12 ( V_9 ) ;
V_9 -> V_10 . V_37 = 1024 ;
V_9 -> V_10 . V_39 = 128 ;
V_51 = F_68 ( V_9 ) ;
if ( V_51 )
goto V_279;
V_51 = F_123 ( V_2 , F_50 ( V_9 ) ? 2 : 1 , NULL ) ;
if ( V_51 )
goto V_279;
if ( V_7 -> V_280 & V_281 ) {
V_7 -> V_280 |= V_282 ;
if ( F_20 ( V_9 -> V_35 -> V_43 ,
L_48 ) )
V_9 -> V_40 = false ;
}
F_52 ( V_9 -> V_35 , L_49 ,
V_9 -> V_40 ? L_50 : L_51 ) ;
V_51 = F_117 ( V_9 ) ;
if ( V_51 )
goto V_279;
V_7 -> V_270 |= V_283 ;
V_51 = F_124 ( V_2 ) ;
if ( V_51 )
goto V_279;
V_51 = F_112 ( V_9 ) ;
if ( V_51 )
goto V_279;
V_51 = V_7 -> V_284 ( V_2 ) ;
if ( V_51 )
goto V_279;
V_51 = F_125 ( V_2 , NULL , 0 ) ;
if ( V_51 )
goto V_279;
return 0 ;
V_279:
F_115 ( V_9 ) ;
return V_51 ;
}
static int F_126 ( struct V_79 * V_80 )
{
struct V_8 * V_9 ;
const struct V_285 * V_286 ;
int V_51 ;
V_9 = F_127 ( & V_80 -> V_35 , sizeof( * V_9 ) , V_138 ) ;
if ( ! V_9 )
return - V_125 ;
V_286 = F_128 ( V_287 , & V_80 -> V_35 ) ;
if ( V_286 ) {
V_9 -> V_27 = V_286 -> V_144 ;
} else {
F_15 ( & V_80 -> V_35 , L_52 ) ;
return - V_95 ;
}
F_129 ( V_80 , V_9 ) ;
V_9 -> V_80 = V_80 ;
V_9 -> V_35 = & V_80 -> V_35 ;
V_51 = F_53 ( V_9 ) ;
if ( V_51 )
goto V_288;
V_51 = F_55 ( V_9 ) ;
if ( V_51 )
goto V_289;
V_51 = F_120 ( V_9 ) ;
if ( V_51 )
goto V_289;
F_130 ( V_9 -> V_35 , L_53 ) ;
return 0 ;
V_289:
F_54 ( V_9 ) ;
V_288:
return V_51 ;
}
static int F_131 ( struct V_79 * V_80 )
{
struct V_8 * V_9 = F_132 ( V_80 ) ;
F_115 ( V_9 ) ;
F_54 ( V_9 ) ;
return 0 ;
}
static int F_133 ( struct V_123 * V_35 )
{
struct V_8 * V_9 = F_134 ( V_35 ) ;
F_44 ( V_9 ) ;
return 0 ;
}
static int F_135 ( struct V_123 * V_35 )
{
struct V_8 * V_9 = F_134 ( V_35 ) ;
int V_51 ;
V_51 = F_46 ( V_9 ) ;
if ( V_51 < 0 )
return V_51 ;
V_9 -> V_290 &= ~ V_291 ;
V_51 = F_56 ( V_9 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_54 , V_51 ) ;
return V_51 ;
}
V_51 = F_114 ( V_9 ) ;
if ( V_51 ) {
F_15 ( V_9 -> V_35 , L_55 , V_51 ) ;
return V_51 ;
}
F_119 ( V_9 ) ;
return 0 ;
}
