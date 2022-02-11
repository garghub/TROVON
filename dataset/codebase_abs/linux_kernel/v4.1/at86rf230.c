static inline int
F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static inline int
F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_4 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static inline int
F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_6 ,
unsigned int V_7 , unsigned int * V_4 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( ! V_8 )
* V_4 = ( * V_4 & V_6 ) >> V_7 ;
return V_8 ;
}
static inline int
F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_6 ,
unsigned int V_7 , unsigned int V_4 )
{
return F_7 ( V_2 -> V_5 , V_3 , V_6 , V_4 << V_7 ) ;
}
static inline void
F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_9 , 1 ) ;
F_10 ( 1 ) ;
F_9 ( V_2 -> V_9 , 0 ) ;
}
static bool
F_11 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
return true ;
default:
return false ;
}
}
static bool
F_12 ( struct V_10 * V_11 , unsigned int V_12 )
{
bool V_8 ;
V_8 = F_11 ( V_11 , V_12 ) ;
if ( V_8 )
return V_8 ;
switch ( V_12 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
return true ;
default:
return false ;
}
}
static bool
F_13 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_49 :
case V_13 :
case V_50 :
case V_17 :
case V_51 :
case V_25 :
case V_31 :
case V_32 :
return true ;
default:
return false ;
}
}
static bool
F_14 ( struct V_10 * V_11 , unsigned int V_12 )
{
switch ( V_12 ) {
case V_51 :
return true ;
default:
return false ;
}
}
static void
F_15 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
V_2 -> V_59 = 0 ;
F_16 ( V_2 , V_58 , V_60 , NULL , false ) ;
F_17 ( V_2 -> V_61 ) ;
}
static inline void
F_18 ( struct V_1 * V_2 ,
struct V_57 * V_58 , int V_8 )
{
F_19 ( & V_2 -> V_62 -> V_11 , L_1 , V_8 ) ;
F_16 ( V_2 , V_58 , V_63 ,
F_15 , false ) ;
}
static void
F_20 ( struct V_1 * V_2 , const T_1 V_12 ,
struct V_57 * V_58 ,
void (* F_21)( void * V_56 ) ,
const bool V_64 )
{
int V_8 ;
T_1 * V_65 = V_58 -> V_66 ;
V_65 [ 0 ] = ( V_12 & V_67 ) | V_68 ;
V_58 -> V_69 . F_21 = F_21 ;
V_58 -> V_64 = V_64 ;
V_8 = F_22 ( V_2 -> V_62 , & V_58 -> V_69 ) ;
if ( V_8 ) {
if ( V_64 )
F_23 ( V_58 -> V_70 ) ;
F_18 ( V_2 , V_58 , V_8 ) ;
}
}
static inline T_1 F_24 ( T_1 V_71 )
{
if ( V_71 == V_72 )
return V_73 ;
else
return V_63 ;
}
static void
F_25 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
const T_1 * V_66 = V_58 -> V_66 ;
const T_1 V_74 = V_66 [ 1 ] & V_75 ;
if ( V_74 != V_58 -> V_76 ) {
if ( V_74 == V_77 ) {
if ( V_58 -> V_76 == V_60 )
goto V_78;
if ( V_58 -> V_76 == V_72 ||
V_58 -> V_76 == V_79 ) {
T_1 V_71 = V_58 -> V_76 ;
if ( V_2 -> V_80 >= V_81 )
V_71 = F_24 ( V_71 ) ;
V_2 -> V_80 ++ ;
F_16 ( V_2 , V_58 , V_71 ,
V_58 -> F_21 ,
V_58 -> V_64 ) ;
return;
}
}
F_26 ( & V_2 -> V_62 -> V_11 , L_2 ,
V_58 -> V_82 , V_58 -> V_76 , V_74 ) ;
}
V_78:
if ( V_58 -> F_21 )
V_58 -> F_21 ( V_56 ) ;
}
static enum V_83 F_27 ( struct V_84 * V_85 )
{
struct V_57 * V_58 =
F_28 ( V_85 , struct V_57 , V_85 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_20 ( V_2 , V_49 , V_58 ,
F_25 ,
V_58 -> V_64 ) ;
return V_86 ;
}
static void
F_29 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_87 * V_88 = V_2 -> V_4 ;
bool V_89 = false ;
T_2 V_90 ;
switch ( V_58 -> V_76 ) {
case V_73 :
V_58 -> V_76 = V_72 ;
V_89 = true ;
break;
case V_63 :
V_58 -> V_76 = V_79 ;
V_89 = true ;
break;
default:
break;
}
switch ( V_58 -> V_82 ) {
case V_79 :
switch ( V_58 -> V_76 ) {
case V_60 :
V_90 = F_30 ( 0 , V_88 -> V_91 * V_92 ) ;
V_2 -> V_93 = V_94 + V_95 ;
goto V_96;
case V_97 :
case V_72 :
V_90 = F_30 ( 0 , V_88 -> V_98 * V_92 ) ;
V_2 -> V_93 = V_94 + V_95 ;
goto V_96;
default:
break;
}
break;
case V_77 :
switch ( V_58 -> V_76 ) {
case V_79 :
case V_72 :
if ( ! V_89 ) {
V_90 = F_30 ( 0 , ( V_88 -> V_99 + V_88 -> V_100 ) *
V_92 ) ;
goto V_96;
}
break;
default:
break;
}
break;
case V_101 :
switch ( V_58 -> V_76 ) {
case V_79 :
V_90 = F_30 ( 0 , V_88 -> V_102 * V_92 ) ;
goto V_96;
default:
break;
}
break;
default:
break;
}
V_90 = F_30 ( 0 , V_92 ) ;
V_96:
F_31 ( & V_58 -> V_85 , V_90 , V_103 ) ;
}
static void
F_32 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 * V_66 = V_58 -> V_66 ;
const T_1 V_74 = V_66 [ 1 ] & V_75 ;
int V_8 ;
if ( V_74 == V_104 ) {
F_10 ( 1 ) ;
F_20 ( V_2 , V_49 , V_58 ,
F_32 ,
V_58 -> V_64 ) ;
return;
}
if ( V_74 == V_58 -> V_76 ) {
if ( V_58 -> F_21 )
V_58 -> F_21 ( V_56 ) ;
return;
}
V_58 -> V_82 = V_74 ;
V_66 [ 0 ] = ( V_13 & V_67 ) | V_68 | V_105 ;
V_66 [ 1 ] = V_58 -> V_76 ;
V_58 -> V_69 . F_21 = F_29 ;
V_8 = F_22 ( V_2 -> V_62 , & V_58 -> V_69 ) ;
if ( V_8 ) {
if ( V_58 -> V_64 )
F_23 ( V_58 -> V_70 ) ;
F_18 ( V_2 , V_58 , V_8 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
const T_1 V_71 , void (* F_21)( void * V_56 ) ,
const bool V_64 )
{
V_58 -> V_76 = V_71 ;
V_58 -> F_21 = F_21 ;
V_58 -> V_64 = V_64 ;
F_20 ( V_2 , V_49 , V_58 ,
F_32 ,
V_64 ) ;
}
static void
F_33 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_21 ( & V_2 -> V_106 ) ;
}
static int
F_34 ( struct V_1 * V_2 , unsigned int V_71 )
{
unsigned long V_8 ;
F_16 ( V_2 , & V_2 -> V_71 , V_71 ,
F_33 ,
false ) ;
V_8 = F_35 ( & V_2 -> V_106 ,
F_36 ( 100 ) ) ;
if ( ! V_8 ) {
F_18 ( V_2 , & V_2 -> V_71 , - V_107 ) ;
return - V_107 ;
}
return 0 ;
}
static void
F_37 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_23 ( V_58 -> V_70 ) ;
F_38 ( V_2 -> V_61 , V_2 -> V_108 , ! V_2 -> V_109 ) ;
}
static void
F_39 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_16 ( V_2 , V_58 , V_60 ,
F_37 , true ) ;
}
static void
F_40 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
const T_1 * V_66 = V_58 -> V_66 ;
const T_1 V_110 = ( V_66 [ 1 ] & 0xe0 ) >> 5 ;
if ( V_110 )
F_16 ( V_2 , V_58 , V_63 ,
F_39 , true ) ;
else
F_39 ( V_56 ) ;
}
static void
F_41 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_20 ( V_2 , V_13 , V_58 ,
F_40 , true ) ;
}
static void
F_42 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 V_111 [ V_112 ] ;
const T_1 * V_66 = V_58 -> V_66 ;
struct V_113 * V_114 ;
T_1 V_115 , V_116 ;
V_115 = V_66 [ 1 ] ;
if ( ! F_43 ( V_115 ) ) {
F_44 ( & V_2 -> V_62 -> V_11 , L_3 ) ;
V_115 = V_117 ;
}
V_116 = V_66 [ 2 + V_115 ] ;
memcpy ( V_111 , V_66 + 2 , V_115 ) ;
V_58 -> V_118 . V_115 = 2 ;
F_23 ( V_58 -> V_70 ) ;
V_114 = F_45 ( V_117 ) ;
if ( ! V_114 ) {
F_44 ( & V_2 -> V_62 -> V_11 , L_4 ) ;
return;
}
memcpy ( F_46 ( V_114 , V_115 ) , V_111 , V_115 ) ;
F_47 ( V_2 -> V_61 , V_114 , V_116 ) ;
}
static void
F_48 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 * V_66 = V_58 -> V_66 ;
int V_8 ;
V_66 [ 0 ] = V_119 ;
V_58 -> V_118 . V_115 = V_112 ;
V_58 -> V_69 . F_21 = F_42 ;
V_8 = F_22 ( V_2 -> V_62 , & V_58 -> V_69 ) ;
if ( V_8 ) {
V_58 -> V_118 . V_115 = 2 ;
F_23 ( V_58 -> V_70 ) ;
F_18 ( V_2 , V_58 , V_8 ) ;
}
}
static void
F_49 ( void * V_56 )
{
F_48 ( V_56 ) ;
}
static void
F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 ) {
V_2 -> V_59 = 0 ;
if ( V_2 -> V_109 )
F_16 ( V_2 , & V_2 -> V_70 ,
V_73 ,
F_41 ,
true ) ;
else
F_16 ( V_2 , & V_2 -> V_70 ,
V_60 ,
F_37 ,
true ) ;
} else {
F_20 ( V_2 , V_13 , & V_2 -> V_70 ,
F_49 , true ) ;
}
}
static void
F_51 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
const T_1 * V_66 = V_58 -> V_66 ;
const T_1 V_70 = V_66 [ 1 ] ;
if ( V_70 & V_120 ) {
F_50 ( V_2 ) ;
} else {
F_23 ( V_58 -> V_70 ) ;
F_19 ( & V_2 -> V_62 -> V_11 , L_5 ,
V_70 ) ;
}
}
static T_3 F_52 ( int V_70 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_57 * V_58 = & V_2 -> V_70 ;
T_1 * V_66 = V_58 -> V_66 ;
int V_8 ;
F_53 ( V_70 ) ;
V_66 [ 0 ] = ( V_51 & V_67 ) | V_68 ;
V_58 -> V_69 . F_21 = F_51 ;
V_8 = F_22 ( V_2 -> V_62 , & V_58 -> V_69 ) ;
if ( V_8 ) {
F_23 ( V_70 ) ;
F_18 ( V_2 , V_58 , V_8 ) ;
return V_121 ;
}
return V_122 ;
}
static void
F_54 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 * V_66 = V_58 -> V_66 ;
int V_8 ;
V_58 -> V_118 . V_115 = 2 ;
if ( F_55 ( V_2 -> V_9 ) ) {
F_8 ( V_2 ) ;
} else {
V_66 [ 0 ] = ( V_13 & V_67 ) | V_68 | V_105 ;
V_66 [ 1 ] = V_123 ;
V_58 -> V_69 . F_21 = NULL ;
V_8 = F_22 ( V_2 -> V_62 , & V_58 -> V_69 ) ;
if ( V_8 )
F_18 ( V_2 , V_58 , V_8 ) ;
}
}
static void
F_56 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_113 * V_114 = V_2 -> V_108 ;
T_1 * V_66 = V_58 -> V_66 ;
int V_8 ;
V_2 -> V_59 = 1 ;
V_66 [ 0 ] = V_119 | V_105 ;
V_66 [ 1 ] = V_114 -> V_115 + 2 ;
memcpy ( V_66 + 2 , V_114 -> V_4 , V_114 -> V_115 ) ;
V_58 -> V_118 . V_115 = V_114 -> V_115 + 2 ;
V_58 -> V_69 . F_21 = F_54 ;
V_8 = F_22 ( V_2 -> V_62 , & V_58 -> V_69 ) ;
if ( V_8 ) {
V_58 -> V_118 . V_115 = 2 ;
F_18 ( V_2 , V_58 , V_8 ) ;
}
}
static void
F_57 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_16 ( V_2 , V_58 , V_97 ,
F_56 , false ) ;
}
static void
F_58 ( void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
if ( V_2 -> V_109 ) {
if ( V_2 -> V_124 ) {
V_2 -> V_124 = false ;
F_16 ( V_2 , V_58 , V_97 ,
F_57 ,
false ) ;
} else {
F_16 ( V_2 , V_58 , V_72 ,
F_57 ,
false ) ;
}
} else {
F_16 ( V_2 , V_58 , V_72 ,
F_56 , false ) ;
}
}
static int
F_59 ( struct V_125 * V_61 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
struct V_57 * V_58 = & V_2 -> V_127 ;
V_2 -> V_108 = V_114 ;
V_2 -> V_80 = 0 ;
if ( F_60 ( V_2 -> V_93 ) ) {
V_2 -> V_124 = true ;
F_16 ( V_2 , V_58 , V_79 ,
F_58 , false ) ;
} else {
F_58 ( V_58 ) ;
}
return 0 ;
}
static int
F_61 ( struct V_125 * V_61 , T_1 * V_128 )
{
F_62 ( ! V_128 ) ;
* V_128 = 0xbe ;
return 0 ;
}
static int
F_63 ( struct V_125 * V_61 )
{
return F_34 ( V_61 -> V_126 , V_60 ) ;
}
static void
F_64 ( struct V_125 * V_61 )
{
F_34 ( V_61 -> V_126 , V_63 ) ;
}
static int
F_65 ( struct V_1 * V_2 , T_1 V_129 , T_1 V_130 )
{
return F_6 ( V_2 , V_131 , V_130 ) ;
}
static int
F_66 ( struct V_1 * V_2 , T_1 V_129 , T_1 V_130 )
{
int V_8 ;
if ( V_130 == 0 )
V_8 = F_6 ( V_2 , V_132 , 0 ) ;
else
V_8 = F_6 ( V_2 , V_132 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_129 == 0 ) {
V_8 = F_6 ( V_2 , V_133 , 0 ) ;
V_2 -> V_4 -> V_134 = - 100 ;
} else {
V_8 = F_6 ( V_2 , V_133 , 1 ) ;
V_2 -> V_4 -> V_134 = - 98 ;
}
if ( V_8 < 0 )
return V_8 ;
if ( V_130 == 0 ) {
if ( V_129 == 0 ) {
V_2 -> V_61 -> V_135 -> V_136 = 50 ;
} else {
V_2 -> V_61 -> V_135 -> V_136 = 25 ;
}
} else {
if ( V_129 == 0 )
V_2 -> V_61 -> V_135 -> V_136 = 40 ;
else
V_2 -> V_61 -> V_135 -> V_136 = 16 ;
}
V_2 -> V_61 -> V_135 -> V_137 = V_138 *
V_2 -> V_61 -> V_135 -> V_136 ;
V_2 -> V_61 -> V_135 -> V_139 = V_140 *
V_2 -> V_61 -> V_135 -> V_136 ;
return F_6 ( V_2 , V_131 , V_130 ) ;
}
static int
F_67 ( struct V_125 * V_61 , T_1 V_129 , T_1 V_130 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
int V_8 ;
V_8 = V_2 -> V_4 -> V_141 ( V_2 , V_129 , V_130 ) ;
F_68 ( V_2 -> V_4 -> V_142 ,
V_2 -> V_4 -> V_142 + 10 ) ;
V_2 -> V_93 = V_94 + V_95 ;
return V_8 ;
}
static int
F_69 ( struct V_125 * V_61 ,
struct V_143 * V_144 ,
unsigned long V_145 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
if ( V_145 & V_146 ) {
T_4 V_3 = F_70 ( V_144 -> V_147 ) ;
F_44 ( & V_2 -> V_62 -> V_11 ,
L_6 ) ;
F_1 ( V_2 , V_33 , V_3 ) ;
F_1 ( V_2 , V_34 , V_3 >> 8 ) ;
}
if ( V_145 & V_148 ) {
T_4 V_149 = F_70 ( V_144 -> V_150 ) ;
F_44 ( & V_2 -> V_62 -> V_11 ,
L_7 ) ;
F_1 ( V_2 , V_35 , V_149 ) ;
F_1 ( V_2 , V_36 , V_149 >> 8 ) ;
}
if ( V_145 & V_151 ) {
T_1 V_152 , V_3 [ 8 ] ;
memcpy ( V_3 , & V_144 -> V_153 , 8 ) ;
F_44 ( & V_2 -> V_62 -> V_11 ,
L_8 ) ;
for ( V_152 = 0 ; V_152 < 8 ; V_152 ++ )
F_1 ( V_2 , V_37 + V_152 , V_3 [ V_152 ] ) ;
}
if ( V_145 & V_154 ) {
F_44 ( & V_2 -> V_62 -> V_11 ,
L_9 ) ;
if ( V_144 -> V_155 )
F_6 ( V_2 , V_156 , 1 ) ;
else
F_6 ( V_2 , V_156 , 0 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_125 * V_61 , T_5 V_157 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
if ( V_157 > 5 || V_157 < - 26 )
return - V_158 ;
V_157 = - ( V_157 - 5 ) ;
return F_1 ( V_2 , V_16 , 0x60 | V_157 ) ;
}
static int
F_72 ( struct V_125 * V_61 , bool V_159 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
return F_6 ( V_2 , V_160 , V_159 ) ;
}
static int
F_73 ( struct V_125 * V_61 ,
const struct V_161 * V_162 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
T_1 V_163 ;
switch ( V_162 -> V_164 ) {
case V_165 :
V_163 = 1 ;
break;
case V_166 :
V_163 = 2 ;
break;
case V_167 :
switch ( V_162 -> V_168 ) {
case V_169 :
V_163 = 3 ;
break;
case V_170 :
V_163 = 0 ;
break;
default:
return - V_158 ;
}
break;
default:
return - V_158 ;
}
return F_6 ( V_2 , V_171 , V_163 ) ;
}
static int
F_74 ( struct V_1 * V_2 , T_6 V_128 )
{
return ( V_128 - V_2 -> V_4 -> V_134 ) * 100 / 207 ;
}
static int
F_75 ( struct V_1 * V_2 , T_6 V_128 )
{
return ( V_128 - V_2 -> V_4 -> V_134 ) / 2 ;
}
static int
F_76 ( struct V_125 * V_61 , T_6 V_128 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
if ( V_128 < V_2 -> V_4 -> V_134 || V_128 > 30 )
return - V_158 ;
return F_6 ( V_2 , V_172 ,
V_2 -> V_4 -> V_173 ( V_2 , V_128 ) ) ;
}
static int
F_77 ( struct V_125 * V_61 , T_1 V_174 , T_1 V_175 ,
T_1 V_176 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
int V_8 ;
V_8 = F_6 ( V_2 , V_177 , V_174 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_178 , V_175 ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_2 , V_179 , V_176 ) ;
}
static int
F_78 ( struct V_125 * V_61 , T_5 V_176 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
int V_8 = 0 ;
V_2 -> V_109 = V_176 >= 0 ;
V_2 -> V_180 = V_176 ;
if ( V_176 >= 0 )
V_8 = F_6 ( V_2 , V_181 , V_176 ) ;
return V_8 ;
}
static int
F_79 ( struct V_125 * V_61 , const bool V_159 )
{
struct V_1 * V_2 = V_61 -> V_126 ;
int V_8 ;
if ( V_159 ) {
V_8 = F_6 ( V_2 , V_182 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 , V_183 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_8 = F_6 ( V_2 , V_183 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 , V_182 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , T_1 V_184 )
{
int V_8 , V_185 , V_186 = V_187 ;
unsigned int V_188 ;
T_1 V_189 [ 2 ] ;
V_8 = F_34 ( V_2 , V_63 ) ;
if ( V_8 )
return V_8 ;
V_185 = F_81 ( V_2 -> V_62 -> V_70 ) ;
if ( V_185 == V_190 ||
V_185 == V_191 )
F_26 ( & V_2 -> V_62 -> V_11 ,
L_10 ) ;
if ( V_185 == V_191 ||
V_185 == V_192 )
V_186 = V_193 ;
V_8 = F_6 ( V_2 , V_194 , V_186 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_195 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_196 , V_120 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_197 , 0 ) ;
if ( V_8 )
return V_8 ;
F_82 ( V_189 , F_83 ( V_189 ) ) ;
V_8 = F_6 ( V_2 , V_198 , V_189 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_199 , V_189 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_200 , 0x00 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_201 , 0x00 ) ;
if ( V_8 )
return V_8 ;
F_68 ( V_2 -> V_4 -> V_202 ,
V_2 -> V_4 -> V_202 + 100 ) ;
V_8 = F_6 ( V_2 , V_203 , V_184 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_5 ( V_2 , V_204 , & V_188 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_188 ) {
F_19 ( & V_2 -> V_62 -> V_11 , L_11 ) ;
return - V_158 ;
}
return F_6 ( V_2 , V_205 , 0 ) ;
}
static int
F_84 ( struct V_206 * V_62 , int * V_207 , int * V_9 ,
T_1 * V_184 )
{
struct V_208 * V_209 = V_62 -> V_11 . V_210 ;
int V_211 ;
if ( ! F_85 ( V_212 ) || ! V_62 -> V_11 . V_213 ) {
if ( ! V_209 )
return - V_214 ;
* V_207 = V_209 -> V_207 ;
* V_9 = V_209 -> V_9 ;
* V_184 = V_209 -> V_184 ;
return 0 ;
}
* V_207 = F_86 ( V_62 -> V_11 . V_213 , L_12 , 0 ) ;
* V_9 = F_86 ( V_62 -> V_11 . V_213 , L_13 , 0 ) ;
V_211 = F_87 ( V_62 -> V_11 . V_213 , L_14 , V_184 ) ;
if ( V_211 < 0 && V_211 != - V_158 )
return V_211 ;
return 0 ;
}
static int
F_88 ( struct V_1 * V_2 )
{
unsigned int V_215 , V_216 , V_163 ;
T_4 V_217 = 0 ;
const char * V_218 ;
int V_8 ;
V_8 = F_3 ( V_2 , V_55 , & V_163 ) ;
if ( V_8 )
return V_8 ;
V_217 |= V_163 ;
V_8 = F_3 ( V_2 , V_54 , & V_163 ) ;
if ( V_8 )
return V_8 ;
V_217 |= ( V_163 << 8 ) ;
V_8 = F_3 ( V_2 , V_52 , & V_215 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_53 , & V_216 ) ;
if ( V_8 )
return V_8 ;
if ( V_217 != 0x001f ) {
F_19 ( & V_2 -> V_62 -> V_11 , L_15 ,
V_217 >> 8 , V_217 & 0xFF ) ;
return - V_158 ;
}
V_2 -> V_61 -> V_219 = V_220 | V_221 |
V_222 | V_223 |
V_224 | V_225 ;
V_2 -> V_61 -> V_135 -> V_162 . V_164 = V_165 ;
switch ( V_215 ) {
case 2 :
V_218 = L_16 ;
V_8 = - V_226 ;
break;
case 3 :
V_218 = L_17 ;
V_2 -> V_4 = & V_227 ;
V_2 -> V_61 -> V_135 -> V_228 [ 0 ] = 0x7FFF800 ;
V_2 -> V_61 -> V_135 -> V_229 = 11 ;
V_2 -> V_61 -> V_135 -> V_136 = 16 ;
break;
case 7 :
V_218 = L_18 ;
V_2 -> V_4 = & V_230 ;
V_2 -> V_61 -> V_219 |= V_231 ;
V_2 -> V_61 -> V_135 -> V_228 [ 0 ] = 0x00007FF ;
V_2 -> V_61 -> V_135 -> V_228 [ 2 ] = 0x00007FF ;
V_2 -> V_61 -> V_135 -> V_229 = 5 ;
V_2 -> V_61 -> V_135 -> V_136 = 25 ;
break;
case 11 :
V_218 = L_19 ;
V_2 -> V_4 = & V_232 ;
V_2 -> V_61 -> V_135 -> V_228 [ 0 ] = 0x7FFF800 ;
V_2 -> V_61 -> V_135 -> V_229 = 13 ;
V_2 -> V_61 -> V_135 -> V_136 = 16 ;
break;
default:
V_218 = L_20 ;
V_8 = - V_226 ;
break;
}
F_89 ( & V_2 -> V_62 -> V_11 , L_21 , V_218 , V_216 ) ;
return V_8 ;
}
static void
F_90 ( struct V_1 * V_2 )
{
V_2 -> V_71 . V_2 = V_2 ;
V_2 -> V_71 . V_70 = V_2 -> V_62 -> V_70 ;
F_91 ( & V_2 -> V_71 . V_69 ) ;
V_2 -> V_71 . V_69 . V_56 = & V_2 -> V_71 ;
V_2 -> V_71 . V_118 . V_115 = 2 ;
V_2 -> V_71 . V_118 . V_65 = V_2 -> V_71 . V_66 ;
V_2 -> V_71 . V_118 . V_233 = V_2 -> V_71 . V_66 ;
F_92 ( & V_2 -> V_71 . V_118 , & V_2 -> V_71 . V_69 ) ;
F_93 ( & V_2 -> V_71 . V_85 , V_234 , V_103 ) ;
V_2 -> V_71 . V_85 . V_235 = F_27 ;
V_2 -> V_70 . V_2 = V_2 ;
V_2 -> V_70 . V_70 = V_2 -> V_62 -> V_70 ;
F_91 ( & V_2 -> V_70 . V_69 ) ;
V_2 -> V_70 . V_69 . V_56 = & V_2 -> V_70 ;
V_2 -> V_70 . V_118 . V_115 = 2 ;
V_2 -> V_70 . V_118 . V_65 = V_2 -> V_70 . V_66 ;
V_2 -> V_70 . V_118 . V_233 = V_2 -> V_70 . V_66 ;
F_92 ( & V_2 -> V_70 . V_118 , & V_2 -> V_70 . V_69 ) ;
F_93 ( & V_2 -> V_70 . V_85 , V_234 , V_103 ) ;
V_2 -> V_70 . V_85 . V_235 = F_27 ;
V_2 -> V_127 . V_2 = V_2 ;
V_2 -> V_127 . V_70 = V_2 -> V_62 -> V_70 ;
F_91 ( & V_2 -> V_127 . V_69 ) ;
V_2 -> V_127 . V_69 . V_56 = & V_2 -> V_127 ;
V_2 -> V_127 . V_118 . V_115 = 2 ;
V_2 -> V_127 . V_118 . V_65 = V_2 -> V_127 . V_66 ;
V_2 -> V_127 . V_118 . V_233 = V_2 -> V_127 . V_66 ;
F_92 ( & V_2 -> V_127 . V_118 , & V_2 -> V_127 . V_69 ) ;
F_93 ( & V_2 -> V_127 . V_85 , V_234 , V_103 ) ;
V_2 -> V_127 . V_85 . V_235 = F_27 ;
}
static int F_94 ( struct V_206 * V_62 )
{
struct V_125 * V_61 ;
struct V_1 * V_2 ;
unsigned int V_236 ;
int V_8 , V_185 , V_207 , V_9 ;
T_1 V_184 = 0 ;
if ( ! V_62 -> V_70 ) {
F_19 ( & V_62 -> V_11 , L_22 ) ;
return - V_158 ;
}
V_8 = F_84 ( V_62 , & V_207 , & V_9 , & V_184 ) ;
if ( V_8 < 0 ) {
F_19 ( & V_62 -> V_11 , L_23 , V_8 ) ;
return V_8 ;
}
if ( F_55 ( V_207 ) ) {
V_8 = F_95 ( & V_62 -> V_11 , V_207 ,
V_237 , L_24 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_55 ( V_9 ) ) {
V_8 = F_95 ( & V_62 -> V_11 , V_9 ,
V_238 , L_25 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_55 ( V_207 ) ) {
F_10 ( 1 ) ;
F_9 ( V_207 , 0 ) ;
F_10 ( 1 ) ;
F_9 ( V_207 , 1 ) ;
F_68 ( 120 , 240 ) ;
}
V_61 = F_96 ( sizeof( * V_2 ) , & V_239 ) ;
if ( ! V_61 )
return - V_240 ;
V_2 = V_61 -> V_126 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_9 = V_9 ;
V_61 -> V_241 = & V_62 -> V_11 ;
V_61 -> V_242 = sizeof( * V_2 ) ;
F_97 ( & V_61 -> V_135 -> V_243 ) ;
V_2 -> V_5 = F_98 ( V_62 , & V_244 ) ;
if ( F_99 ( V_2 -> V_5 ) ) {
V_8 = F_100 ( V_2 -> V_5 ) ;
F_19 ( & V_62 -> V_11 , L_26 ,
V_8 ) ;
goto V_245;
}
F_90 ( V_2 ) ;
V_8 = F_88 ( V_2 ) ;
if ( V_8 < 0 )
goto V_245;
F_101 ( & V_2 -> V_106 ) ;
F_102 ( V_62 , V_2 ) ;
V_8 = F_80 ( V_2 , V_184 ) ;
if ( V_8 )
goto V_245;
V_8 = F_5 ( V_2 , V_51 , 0xff , 0 , & V_236 ) ;
if ( V_8 )
goto V_245;
V_185 = F_81 ( V_62 -> V_70 ) ;
if ( ! V_185 )
V_185 = V_246 ;
V_8 = F_103 ( & V_62 -> V_11 , V_62 -> V_70 , F_52 ,
V_247 | V_185 , F_104 ( & V_62 -> V_11 ) , V_2 ) ;
if ( V_8 )
goto V_245;
V_8 = F_105 ( V_2 -> V_61 ) ;
if ( V_8 )
goto V_245;
return V_8 ;
V_245:
F_106 ( V_2 -> V_61 ) ;
return V_8 ;
}
static int F_107 ( struct V_206 * V_62 )
{
struct V_1 * V_2 = F_108 ( V_62 ) ;
F_6 ( V_2 , V_196 , 0 ) ;
F_109 ( V_2 -> V_61 ) ;
F_106 ( V_2 -> V_61 ) ;
F_110 ( & V_62 -> V_11 , L_27 ) ;
return 0 ;
}
