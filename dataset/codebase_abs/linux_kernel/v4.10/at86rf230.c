static inline void
F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) ) {
F_3 ( V_2 -> V_3 , 1 ) ;
F_4 ( V_2 -> V_4 -> V_5 ,
V_2 -> V_4 -> V_5 + 10 ) ;
V_2 -> V_6 = true ;
}
}
static inline void
F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) ) {
F_3 ( V_2 -> V_3 , 0 ) ;
F_4 ( V_2 -> V_4 -> V_7 ,
V_2 -> V_4 -> V_7 + 100 ) ;
V_2 -> V_6 = false ;
}
}
static inline int
F_6 ( struct V_1 * V_2 ,
unsigned int V_8 , unsigned int V_4 )
{
bool V_6 = V_2 -> V_6 ;
int V_9 ;
if ( V_6 )
F_5 ( V_2 ) ;
V_9 = F_7 ( V_2 -> V_10 , V_8 , V_4 ) ;
if ( V_6 )
F_1 ( V_2 ) ;
return V_9 ;
}
static inline int
F_8 ( struct V_1 * V_2 ,
unsigned int V_8 , unsigned int * V_4 )
{
bool V_6 = V_2 -> V_6 ;
int V_9 ;
if ( V_6 )
F_5 ( V_2 ) ;
V_9 = F_9 ( V_2 -> V_10 , V_8 , V_4 ) ;
if ( V_6 )
F_1 ( V_2 ) ;
return V_9 ;
}
static inline int
F_10 ( struct V_1 * V_2 ,
unsigned int V_8 , unsigned int V_11 ,
unsigned int V_12 , unsigned int * V_4 )
{
int V_13 ;
V_13 = F_8 ( V_2 , V_8 , V_4 ) ;
if ( ! V_13 )
* V_4 = ( * V_4 & V_11 ) >> V_12 ;
return V_13 ;
}
static inline int
F_11 ( struct V_1 * V_2 ,
unsigned int V_8 , unsigned int V_11 ,
unsigned int V_12 , unsigned int V_4 )
{
bool V_6 = V_2 -> V_6 ;
int V_9 ;
if ( V_6 )
F_5 ( V_2 ) ;
V_9 = F_12 ( V_2 -> V_10 , V_8 , V_11 , V_4 << V_12 ) ;
if ( V_6 )
F_1 ( V_2 ) ;
return V_9 ;
}
static inline void
F_13 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_3 , 1 ) ;
F_14 ( 1 ) ;
F_3 ( V_2 -> V_3 , 0 ) ;
}
static bool
F_15 ( struct V_14 * V_15 , unsigned int V_16 )
{
switch ( V_16 ) {
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
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return true ;
default:
return false ;
}
}
static bool
F_16 ( struct V_14 * V_15 , unsigned int V_16 )
{
bool V_13 ;
V_13 = F_15 ( V_15 , V_16 ) ;
if ( V_13 )
return V_13 ;
switch ( V_16 ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return true ;
default:
return false ;
}
}
static bool
F_17 ( struct V_14 * V_15 , unsigned int V_16 )
{
switch ( V_16 ) {
case V_53 :
case V_17 :
case V_54 :
case V_21 :
case V_55 :
case V_29 :
case V_35 :
case V_36 :
return true ;
default:
return false ;
}
}
static bool
F_18 ( struct V_14 * V_15 , unsigned int V_16 )
{
switch ( V_16 ) {
case V_55 :
return true ;
default:
return false ;
}
}
static void
F_19 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( V_62 -> free )
F_20 ( V_62 ) ;
F_21 ( V_2 -> V_63 ) ;
}
static void
F_22 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
V_2 -> V_64 = 0 ;
F_23 ( V_2 , V_62 , V_65 ,
F_19 ) ;
}
static inline void
F_24 ( struct V_1 * V_2 ,
struct V_61 * V_62 , int V_13 )
{
F_25 ( & V_2 -> V_66 -> V_15 , L_1 , V_13 ) ;
F_23 ( V_2 , V_62 , V_67 ,
F_22 ) ;
}
static void
F_26 ( struct V_1 * V_2 , T_1 V_16 ,
struct V_61 * V_62 ,
void (* F_27)( void * V_60 ) )
{
int V_13 ;
T_1 * V_68 = V_62 -> V_69 ;
V_68 [ 0 ] = ( V_16 & V_70 ) | V_71 ;
V_62 -> V_72 . F_27 = F_27 ;
V_13 = F_28 ( V_2 -> V_66 , & V_62 -> V_72 ) ;
if ( V_13 )
F_24 ( V_2 , V_62 , V_13 ) ;
}
static void
F_29 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_73 ,
struct V_61 * V_62 ,
void (* F_27)( void * V_60 ) )
{
int V_13 ;
V_62 -> V_69 [ 0 ] = ( V_16 & V_70 ) | V_71 | V_74 ;
V_62 -> V_69 [ 1 ] = V_73 ;
V_62 -> V_72 . F_27 = F_27 ;
V_13 = F_28 ( V_2 -> V_66 , & V_62 -> V_72 ) ;
if ( V_13 )
F_24 ( V_2 , V_62 , V_13 ) ;
}
static void
F_30 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
const T_1 * V_69 = V_62 -> V_69 ;
const T_1 V_75 = V_69 [ 1 ] & V_76 ;
if ( V_75 != V_62 -> V_77 ) {
if ( V_75 == V_78 ) {
if ( V_62 -> V_77 == V_65 )
goto V_79;
if ( V_62 -> V_77 == V_80 ||
V_62 -> V_77 == V_81 ) {
T_1 V_82 = V_62 -> V_77 ;
if ( V_2 -> V_83 >= V_84 )
V_82 = V_67 ;
V_2 -> V_83 ++ ;
F_23 ( V_2 , V_62 , V_82 ,
V_62 -> F_27 ) ;
return;
}
}
F_31 ( & V_2 -> V_66 -> V_15 , L_2 ,
V_62 -> V_85 , V_62 -> V_77 , V_75 ) ;
}
V_79:
if ( V_62 -> F_27 )
V_62 -> F_27 ( V_60 ) ;
}
static enum V_86 F_32 ( struct V_87 * V_88 )
{
struct V_61 * V_62 =
F_33 ( V_88 , struct V_61 , V_88 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_26 ( V_2 , V_53 , V_62 ,
F_30 ) ;
return V_89 ;
}
static void
F_34 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_90 * V_91 = V_2 -> V_4 ;
bool V_92 = false ;
T_2 V_93 ;
switch ( V_62 -> V_77 ) {
case V_94 :
V_62 -> V_77 = V_80 ;
V_92 = true ;
break;
case V_67 :
V_62 -> V_77 = V_81 ;
V_92 = true ;
break;
default:
break;
}
switch ( V_62 -> V_85 ) {
case V_81 :
switch ( V_62 -> V_77 ) {
case V_65 :
V_93 = V_91 -> V_95 * V_96 ;
V_2 -> V_97 = V_98 + V_99 ;
goto V_100;
case V_101 :
case V_80 :
V_93 = V_91 -> V_102 * V_96 ;
V_2 -> V_97 = V_98 + V_99 ;
goto V_100;
default:
break;
}
break;
case V_78 :
switch ( V_62 -> V_77 ) {
case V_81 :
case V_80 :
if ( ! V_92 ) {
V_93 = ( V_91 -> V_103 + V_91 -> V_104 ) * V_96 ;
goto V_100;
}
break;
default:
break;
}
break;
case V_105 :
switch ( V_62 -> V_77 ) {
case V_81 :
V_93 = V_91 -> V_106 * V_96 ;
goto V_100;
default:
break;
}
break;
default:
break;
}
F_14 ( 1 ) ;
F_32 ( & V_62 -> V_88 ) ;
return;
V_100:
F_35 ( & V_62 -> V_88 , V_93 , V_107 ) ;
}
static void
F_36 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 * V_69 = V_62 -> V_69 ;
const T_1 V_75 = V_69 [ 1 ] & V_76 ;
if ( V_75 == V_108 ) {
F_14 ( 1 ) ;
F_26 ( V_2 , V_53 , V_62 ,
F_36 ) ;
return;
}
if ( V_75 == V_62 -> V_77 ) {
if ( V_62 -> F_27 )
V_62 -> F_27 ( V_60 ) ;
return;
}
V_62 -> V_85 = V_75 ;
F_29 ( V_2 , V_17 , V_62 -> V_77 , V_62 ,
F_34 ) ;
}
static void
F_23 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
const T_1 V_82 , void (* F_27)( void * V_60 ) )
{
V_62 -> V_77 = V_82 ;
V_62 -> F_27 = F_27 ;
F_26 ( V_2 , V_53 , V_62 ,
F_36 ) ;
}
static void
F_37 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_27 ( & V_2 -> V_109 ) ;
}
static int
F_38 ( struct V_1 * V_2 , unsigned int V_82 )
{
unsigned long V_13 ;
F_23 ( V_2 , & V_2 -> V_82 , V_82 ,
F_37 ) ;
V_13 = F_39 ( & V_2 -> V_109 ,
F_40 ( 100 ) ) ;
if ( ! V_13 ) {
F_24 ( V_2 , & V_2 -> V_82 , - V_110 ) ;
return - V_110 ;
}
return 0 ;
}
static void
F_41 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_42 ( V_2 -> V_63 , V_2 -> V_111 , false ) ;
F_20 ( V_62 ) ;
}
static void
F_43 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_23 ( V_2 , V_62 , V_65 ,
F_41 ) ;
}
static void
F_44 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( F_45 ( V_112 ) ) {
T_1 V_113 = F_46 ( V_62 -> V_69 [ 1 ] ) ;
switch ( V_113 ) {
case V_114 :
V_2 -> V_113 . V_115 ++ ;
break;
case V_116 :
V_2 -> V_113 . V_117 ++ ;
break;
case V_118 :
V_2 -> V_113 . V_119 ++ ;
break;
case V_120 :
V_2 -> V_113 . V_121 ++ ;
break;
case V_122 :
V_2 -> V_113 . V_123 ++ ;
break;
default:
F_47 ( 1 , L_3 , V_113 ) ;
break;
}
}
F_23 ( V_2 , V_62 , V_80 , F_43 ) ;
}
static void
F_48 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
const T_1 * V_69 = V_62 -> V_69 ;
struct V_124 * V_125 ;
T_1 V_126 , V_127 ;
V_126 = V_69 [ 1 ] ;
if ( ! F_49 ( V_126 ) ) {
F_50 ( & V_2 -> V_66 -> V_15 , L_4 ) ;
V_126 = V_128 ;
}
V_127 = V_69 [ 2 + V_126 ] ;
V_125 = F_51 ( V_128 ) ;
if ( ! V_125 ) {
F_50 ( & V_2 -> V_66 -> V_15 , L_5 ) ;
F_20 ( V_62 ) ;
return;
}
memcpy ( F_52 ( V_125 , V_126 ) , V_69 + 2 , V_126 ) ;
F_53 ( V_2 -> V_63 , V_125 , V_127 ) ;
F_20 ( V_62 ) ;
}
static void
F_54 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 * V_69 = V_62 -> V_69 ;
int V_13 ;
if ( F_45 ( V_112 ) ) {
T_1 V_113 = F_46 ( V_69 [ 1 ] ) ;
switch ( V_113 ) {
case V_114 :
V_2 -> V_113 . V_115 ++ ;
break;
case V_129 :
V_2 -> V_113 . V_130 ++ ;
break;
case V_122 :
V_2 -> V_113 . V_123 ++ ;
break;
default:
F_47 ( 1 , L_6 , V_113 ) ;
break;
}
}
V_69 [ 0 ] = V_131 ;
V_62 -> V_132 . V_126 = V_133 ;
V_62 -> V_72 . F_27 = F_48 ;
V_13 = F_28 ( V_2 -> V_66 , & V_62 -> V_72 ) ;
if ( V_13 ) {
V_62 -> V_132 . V_126 = 2 ;
F_24 ( V_2 , V_62 , V_13 ) ;
}
}
static void
F_55 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 = 0 ;
F_26 ( V_2 , V_17 , V_62 ,
F_44 ) ;
} else {
F_26 ( V_2 , V_17 , V_62 ,
F_54 ) ;
}
}
static void
F_56 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
const T_1 * V_69 = V_62 -> V_69 ;
T_1 V_134 = V_69 [ 1 ] ;
F_57 ( V_2 -> V_66 -> V_134 ) ;
if ( V_134 & V_135 ) {
F_55 ( V_62 ) ;
} else {
F_25 ( & V_2 -> V_66 -> V_15 , L_7 ,
V_134 ) ;
F_20 ( V_62 ) ;
}
}
static void
F_58 ( struct V_1 * V_2 ,
struct V_61 * V_82 )
{
V_82 -> V_2 = V_2 ;
V_82 -> V_134 = V_2 -> V_66 -> V_134 ;
F_59 ( & V_82 -> V_72 ) ;
V_82 -> V_72 . V_60 = V_82 ;
V_82 -> V_132 . V_126 = 2 ;
V_82 -> V_132 . V_68 = V_82 -> V_69 ;
V_82 -> V_132 . V_136 = V_82 -> V_69 ;
F_60 ( & V_82 -> V_132 , & V_82 -> V_72 ) ;
F_61 ( & V_82 -> V_88 , V_137 , V_107 ) ;
V_82 -> V_88 . V_138 = F_32 ;
}
static T_3 F_62 ( int V_134 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_61 * V_62 ;
int V_13 ;
F_63 ( V_134 ) ;
V_62 = F_64 ( sizeof( * V_62 ) , V_139 ) ;
if ( ! V_62 ) {
F_57 ( V_134 ) ;
return V_140 ;
}
F_58 ( V_2 , V_62 ) ;
V_62 -> free = true ;
V_62 -> V_69 [ 0 ] = ( V_55 & V_70 ) | V_71 ;
V_62 -> V_72 . F_27 = F_56 ;
V_13 = F_28 ( V_2 -> V_66 , & V_62 -> V_72 ) ;
if ( V_13 ) {
F_24 ( V_2 , V_62 , V_13 ) ;
F_57 ( V_134 ) ;
return V_140 ;
}
return V_141 ;
}
static void
F_65 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
V_62 -> V_132 . V_126 = 2 ;
if ( F_2 ( V_2 -> V_3 ) )
F_13 ( V_2 ) ;
else
F_29 ( V_2 , V_17 , V_142 , V_62 ,
NULL ) ;
}
static void
F_66 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_124 * V_125 = V_2 -> V_111 ;
T_1 * V_69 = V_62 -> V_69 ;
int V_13 ;
V_2 -> V_64 = 1 ;
V_69 [ 0 ] = V_131 | V_74 ;
V_69 [ 1 ] = V_125 -> V_126 + 2 ;
memcpy ( V_69 + 2 , V_125 -> V_4 , V_125 -> V_126 ) ;
V_62 -> V_132 . V_126 = V_125 -> V_126 + 2 ;
V_62 -> V_72 . F_27 = F_65 ;
V_13 = F_28 ( V_2 -> V_66 , & V_62 -> V_72 ) ;
if ( V_13 ) {
V_62 -> V_132 . V_126 = 2 ;
F_24 ( V_2 , V_62 , V_13 ) ;
}
}
static void
F_67 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_23 ( V_2 , V_62 , V_101 ,
F_66 ) ;
}
static void
F_68 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( V_2 -> V_143 )
F_23 ( V_2 , V_62 , V_101 ,
F_66 ) ;
else
F_23 ( V_2 , V_62 , V_80 ,
F_67 ) ;
}
static int
F_69 ( struct V_144 * V_63 , struct V_124 * V_125 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
struct V_61 * V_62 = & V_2 -> V_146 ;
V_2 -> V_111 = V_125 ;
V_2 -> V_83 = 0 ;
if ( F_70 ( V_2 -> V_97 ) ) {
V_2 -> V_143 = true ;
F_23 ( V_2 , V_62 , V_81 ,
F_68 ) ;
} else {
V_2 -> V_143 = false ;
F_68 ( V_62 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_144 * V_63 , T_1 * V_147 )
{
F_72 ( ! V_147 ) ;
* V_147 = 0xbe ;
return 0 ;
}
static int
F_73 ( struct V_144 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
if ( F_45 ( V_112 ) )
memset ( & V_2 -> V_113 , 0 , sizeof( struct V_148 ) ) ;
F_5 ( V_2 ) ;
F_57 ( V_2 -> V_66 -> V_134 ) ;
return F_38 ( V_2 , V_65 ) ;
}
static void
F_74 ( struct V_144 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
T_1 V_149 [ 2 ] ;
F_38 ( V_2 , V_67 ) ;
F_75 ( V_2 -> V_66 -> V_134 ) ;
F_76 ( V_149 , F_77 ( V_149 ) ) ;
F_11 ( V_2 , V_150 , V_149 [ 0 ] ) ;
F_11 ( V_2 , V_151 , V_149 [ 1 ] ) ;
F_1 ( V_2 ) ;
}
static int
F_78 ( struct V_1 * V_2 , T_1 V_152 , T_1 V_153 )
{
return F_11 ( V_2 , V_154 , V_153 ) ;
}
static inline int
F_79 ( struct V_1 * V_2 , int V_155 )
{
unsigned int V_156 ;
int V_13 ;
V_13 = F_10 ( V_2 , V_157 , & V_156 ) ;
if ( V_13 < 0 )
return V_13 ;
switch ( V_155 ) {
case - 98 :
V_2 -> V_63 -> V_158 -> V_159 . V_160 = V_161 ;
V_2 -> V_63 -> V_158 -> V_159 . V_162 = F_77 ( V_161 ) ;
V_2 -> V_63 -> V_158 -> V_163 = V_161 [ V_156 ] ;
break;
case - 100 :
V_2 -> V_63 -> V_158 -> V_159 . V_160 = V_164 ;
V_2 -> V_63 -> V_158 -> V_159 . V_162 = F_77 ( V_164 ) ;
V_2 -> V_63 -> V_158 -> V_163 = V_164 [ V_156 ] ;
break;
default:
F_80 ( 1 ) ;
}
return 0 ;
}
static int
F_81 ( struct V_1 * V_2 , T_1 V_152 , T_1 V_153 )
{
int V_13 ;
if ( V_153 == 0 )
V_13 = F_11 ( V_2 , V_165 , 0 ) ;
else
V_13 = F_11 ( V_2 , V_165 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_152 == 0 ) {
V_13 = F_11 ( V_2 , V_166 , 0 ) ;
V_2 -> V_4 -> V_155 = - 100 ;
} else {
V_13 = F_11 ( V_2 , V_166 , 1 ) ;
V_2 -> V_4 -> V_155 = - 98 ;
}
if ( V_13 < 0 )
return V_13 ;
V_13 = F_79 ( V_2 , V_2 -> V_4 -> V_155 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_153 == 0 ) {
if ( V_152 == 0 ) {
V_2 -> V_63 -> V_158 -> V_167 = 50 ;
} else {
V_2 -> V_63 -> V_158 -> V_167 = 25 ;
}
} else {
if ( V_152 == 0 )
V_2 -> V_63 -> V_158 -> V_167 = 40 ;
else
V_2 -> V_63 -> V_158 -> V_167 = 16 ;
}
V_2 -> V_63 -> V_158 -> V_168 = V_169 *
V_2 -> V_63 -> V_158 -> V_167 ;
V_2 -> V_63 -> V_158 -> V_170 = V_171 *
V_2 -> V_63 -> V_158 -> V_167 ;
return F_11 ( V_2 , V_154 , V_153 ) ;
}
static int
F_82 ( struct V_144 * V_63 , T_1 V_152 , T_1 V_153 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
int V_13 ;
V_13 = V_2 -> V_4 -> V_172 ( V_2 , V_152 , V_153 ) ;
F_4 ( V_2 -> V_4 -> V_173 ,
V_2 -> V_4 -> V_173 + 10 ) ;
V_2 -> V_97 = V_98 + V_99 ;
return V_13 ;
}
static int
F_83 ( struct V_144 * V_63 ,
struct V_174 * V_175 ,
unsigned long V_176 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
if ( V_176 & V_177 ) {
T_4 V_8 = F_84 ( V_175 -> V_178 ) ;
F_50 ( & V_2 -> V_66 -> V_15 ,
L_8 ) ;
F_6 ( V_2 , V_37 , V_8 ) ;
F_6 ( V_2 , V_38 , V_8 >> 8 ) ;
}
if ( V_176 & V_179 ) {
T_4 V_180 = F_84 ( V_175 -> V_181 ) ;
F_50 ( & V_2 -> V_66 -> V_15 ,
L_9 ) ;
F_6 ( V_2 , V_39 , V_180 ) ;
F_6 ( V_2 , V_40 , V_180 >> 8 ) ;
}
if ( V_176 & V_182 ) {
T_1 V_183 , V_8 [ 8 ] ;
memcpy ( V_8 , & V_175 -> V_184 , 8 ) ;
F_50 ( & V_2 -> V_66 -> V_15 ,
L_10 ) ;
for ( V_183 = 0 ; V_183 < 8 ; V_183 ++ )
F_6 ( V_2 , V_41 + V_183 , V_8 [ V_183 ] ) ;
}
if ( V_176 & V_185 ) {
F_50 ( & V_2 -> V_66 -> V_15 ,
L_11 ) ;
if ( V_175 -> V_186 )
F_11 ( V_2 , V_187 , 1 ) ;
else
F_11 ( V_2 , V_187 , 0 ) ;
}
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 , T_5 V_188 )
{
T_6 V_183 ;
for ( V_183 = 0 ; V_183 < V_2 -> V_63 -> V_158 -> V_159 . V_189 ; V_183 ++ ) {
if ( V_2 -> V_63 -> V_158 -> V_159 . V_190 [ V_183 ] == V_188 )
return F_11 ( V_2 , V_191 , V_183 ) ;
}
return - V_192 ;
}
static int
F_86 ( struct V_1 * V_2 , T_5 V_188 )
{
T_6 V_183 ;
for ( V_183 = 0 ; V_183 < V_2 -> V_63 -> V_158 -> V_159 . V_189 ; V_183 ++ ) {
if ( V_2 -> V_63 -> V_158 -> V_159 . V_190 [ V_183 ] == V_188 )
return F_11 ( V_2 , V_193 , V_183 ) ;
}
return - V_192 ;
}
static int
F_87 ( struct V_144 * V_63 , T_5 V_188 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
return V_2 -> V_4 -> V_194 ( V_2 , V_188 ) ;
}
static int
F_88 ( struct V_144 * V_63 , bool V_195 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
return F_11 ( V_2 , V_196 , V_195 ) ;
}
static int
F_89 ( struct V_144 * V_63 ,
const struct V_197 * V_198 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
T_1 V_73 ;
switch ( V_198 -> V_199 ) {
case V_200 :
V_73 = 1 ;
break;
case V_201 :
V_73 = 2 ;
break;
case V_202 :
switch ( V_198 -> V_203 ) {
case V_204 :
V_73 = 3 ;
break;
case V_205 :
V_73 = 0 ;
break;
default:
return - V_192 ;
}
break;
default:
return - V_192 ;
}
return F_11 ( V_2 , V_206 , V_73 ) ;
}
static int
F_90 ( struct V_144 * V_63 , T_5 V_188 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
T_6 V_183 ;
for ( V_183 = 0 ; V_183 < V_63 -> V_158 -> V_159 . V_162 ; V_183 ++ ) {
if ( V_63 -> V_158 -> V_159 . V_160 [ V_183 ] == V_188 )
return F_11 ( V_2 , V_157 , V_183 ) ;
}
return - V_192 ;
}
static int
F_91 ( struct V_144 * V_63 , T_1 V_207 , T_1 V_208 ,
T_1 V_209 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
int V_13 ;
V_13 = F_11 ( V_2 , V_210 , V_207 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_211 , V_208 ) ;
if ( V_13 )
return V_13 ;
return F_11 ( V_2 , V_212 , V_209 ) ;
}
static int
F_92 ( struct V_144 * V_63 , T_7 V_209 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
return F_11 ( V_2 , V_213 , V_209 ) ;
}
static int
F_93 ( struct V_144 * V_63 , const bool V_195 )
{
struct V_1 * V_2 = V_63 -> V_145 ;
int V_13 ;
if ( V_195 ) {
V_13 = F_11 ( V_2 , V_214 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_11 ( V_2 , V_215 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
} else {
V_13 = F_11 ( V_2 , V_215 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_11 ( V_2 , V_214 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , T_1 V_216 )
{
int V_13 , V_217 , V_218 = V_219 ;
unsigned int V_220 ;
T_1 V_149 [ 2 ] ;
V_13 = F_38 ( V_2 , V_67 ) ;
if ( V_13 )
return V_13 ;
V_217 = F_95 ( V_2 -> V_66 -> V_134 ) ;
if ( V_217 == V_221 ||
V_217 == V_222 )
V_218 = V_223 ;
V_13 = F_11 ( V_2 , V_224 , V_218 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_225 , 1 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_226 , V_135 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_227 , 0 ) ;
if ( V_13 )
return V_13 ;
F_76 ( V_149 , F_77 ( V_149 ) ) ;
V_13 = F_11 ( V_2 , V_150 , V_149 [ 0 ] ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_151 , V_149 [ 1 ] ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_228 , 0x00 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_229 , 0x00 ) ;
if ( V_13 )
return V_13 ;
F_4 ( V_2 -> V_4 -> V_230 ,
V_2 -> V_4 -> V_230 + 100 ) ;
V_13 = F_11 ( V_2 , V_231 , V_216 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_10 ( V_2 , V_232 , & V_220 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_220 ) {
F_25 ( & V_2 -> V_66 -> V_15 , L_12 ) ;
return - V_192 ;
}
return F_11 ( V_2 , V_233 , 0 ) ;
}
static int
F_96 ( struct V_234 * V_66 , int * V_235 , int * V_3 ,
T_1 * V_216 )
{
struct V_236 * V_237 = V_66 -> V_15 . V_238 ;
int V_9 ;
if ( ! F_45 ( V_239 ) || ! V_66 -> V_15 . V_240 ) {
if ( ! V_237 )
return - V_241 ;
* V_235 = V_237 -> V_235 ;
* V_3 = V_237 -> V_3 ;
* V_216 = V_237 -> V_216 ;
return 0 ;
}
* V_235 = F_97 ( V_66 -> V_15 . V_240 , L_13 , 0 ) ;
* V_3 = F_97 ( V_66 -> V_15 . V_240 , L_14 , 0 ) ;
V_9 = F_98 ( V_66 -> V_15 . V_240 , L_15 , V_216 ) ;
if ( V_9 < 0 && V_9 != - V_192 )
return V_9 ;
return 0 ;
}
static int
F_99 ( struct V_1 * V_2 )
{
unsigned int V_242 , V_243 , V_73 ;
T_4 V_244 = 0 ;
const char * V_245 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_59 , & V_73 ) ;
if ( V_13 )
return V_13 ;
V_244 |= V_73 ;
V_13 = F_8 ( V_2 , V_58 , & V_73 ) ;
if ( V_13 )
return V_13 ;
V_244 |= ( V_73 << 8 ) ;
V_13 = F_8 ( V_2 , V_56 , & V_242 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_8 ( V_2 , V_57 , & V_243 ) ;
if ( V_13 )
return V_13 ;
if ( V_244 != 0x001f ) {
F_25 ( & V_2 -> V_66 -> V_15 , L_16 ,
V_244 >> 8 , V_244 & 0xFF ) ;
return - V_192 ;
}
V_2 -> V_63 -> V_246 = V_247 |
V_248 |
V_249 | V_250 |
V_251 ;
V_2 -> V_63 -> V_158 -> V_246 = V_252 |
V_253 |
V_254 ;
V_2 -> V_63 -> V_158 -> V_159 . V_255 = F_100 ( V_200 ) |
F_100 ( V_201 ) | F_100 ( V_202 ) ;
V_2 -> V_63 -> V_158 -> V_159 . V_256 = F_100 ( V_204 ) |
F_100 ( V_205 ) ;
V_2 -> V_63 -> V_158 -> V_198 . V_199 = V_200 ;
switch ( V_242 ) {
case 2 :
V_245 = L_17 ;
V_13 = - V_257 ;
goto V_258;
case 3 :
V_245 = L_18 ;
V_2 -> V_4 = & V_259 ;
V_2 -> V_63 -> V_158 -> V_159 . V_260 [ 0 ] = 0x7FFF800 ;
V_2 -> V_63 -> V_158 -> V_261 = 11 ;
V_2 -> V_63 -> V_158 -> V_167 = 16 ;
V_2 -> V_63 -> V_158 -> V_159 . V_190 = V_262 ;
V_2 -> V_63 -> V_158 -> V_159 . V_189 = F_77 ( V_262 ) ;
V_2 -> V_63 -> V_158 -> V_159 . V_160 = V_263 ;
V_2 -> V_63 -> V_158 -> V_159 . V_162 = F_77 ( V_263 ) ;
break;
case 7 :
V_245 = L_19 ;
V_2 -> V_4 = & V_264 ;
V_2 -> V_63 -> V_246 |= V_265 ;
V_2 -> V_63 -> V_158 -> V_159 . V_260 [ 0 ] = 0x00007FF ;
V_2 -> V_63 -> V_158 -> V_159 . V_260 [ 2 ] = 0x00007FF ;
V_2 -> V_63 -> V_158 -> V_261 = 5 ;
V_2 -> V_63 -> V_158 -> V_167 = 25 ;
V_2 -> V_63 -> V_158 -> V_159 . V_266 = V_267 ;
V_2 -> V_63 -> V_158 -> V_159 . V_190 = V_268 ;
V_2 -> V_63 -> V_158 -> V_159 . V_189 = F_77 ( V_268 ) ;
V_2 -> V_63 -> V_158 -> V_159 . V_160 = V_164 ;
V_2 -> V_63 -> V_158 -> V_159 . V_162 = F_77 ( V_164 ) ;
break;
case 11 :
V_245 = L_20 ;
V_2 -> V_4 = & V_269 ;
V_2 -> V_63 -> V_158 -> V_159 . V_260 [ 0 ] = 0x7FFF800 ;
V_2 -> V_63 -> V_158 -> V_261 = 13 ;
V_2 -> V_63 -> V_158 -> V_167 = 16 ;
V_2 -> V_63 -> V_158 -> V_159 . V_190 = V_270 ;
V_2 -> V_63 -> V_158 -> V_159 . V_189 = F_77 ( V_270 ) ;
V_2 -> V_63 -> V_158 -> V_159 . V_160 = V_271 ;
V_2 -> V_63 -> V_158 -> V_159 . V_162 = F_77 ( V_271 ) ;
break;
default:
V_245 = L_21 ;
V_13 = - V_257 ;
goto V_258;
}
V_2 -> V_63 -> V_158 -> V_163 = V_2 -> V_63 -> V_158 -> V_159 . V_160 [ 7 ] ;
V_2 -> V_63 -> V_158 -> V_272 = V_2 -> V_63 -> V_158 -> V_159 . V_190 [ 0 ] ;
V_258:
F_101 ( & V_2 -> V_66 -> V_15 , L_22 , V_245 , V_243 ) ;
return V_13 ;
}
static int F_102 ( struct V_273 * V_274 , void * V_275 )
{
struct V_1 * V_2 = V_274 -> V_276 ;
F_103 ( V_274 , L_23 , V_2 -> V_113 . V_115 ) ;
F_103 ( V_274 , L_24 ,
V_2 -> V_113 . V_117 ) ;
F_103 ( V_274 , L_25 ,
V_2 -> V_113 . V_130 ) ;
F_103 ( V_274 , L_26 ,
V_2 -> V_113 . V_119 ) ;
F_103 ( V_274 , L_27 , V_2 -> V_113 . V_121 ) ;
F_103 ( V_274 , L_28 , V_2 -> V_113 . V_123 ) ;
return 0 ;
}
static int F_104 ( struct V_277 * V_277 , struct V_274 * V_274 )
{
return F_105 ( V_274 , F_102 , V_277 -> V_278 ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
char V_279 [ V_280 + 1 ] = L_29 ;
struct V_281 * V_282 ;
strncat ( V_279 , F_107 ( & V_2 -> V_66 -> V_15 ) , V_280 ) ;
V_283 = F_108 ( V_279 , NULL ) ;
if ( ! V_283 )
return - V_284 ;
V_282 = F_109 ( L_30 , V_285 ,
V_283 , V_2 ,
& V_286 ) ;
if ( ! V_282 )
return - V_284 ;
return 0 ;
}
static void F_110 ( void )
{
F_111 ( V_283 ) ;
}
static int F_106 ( struct V_1 * V_2 ) { return 0 ; }
static void F_110 ( void ) { }
static int F_112 ( struct V_234 * V_66 )
{
struct V_144 * V_63 ;
struct V_1 * V_2 ;
unsigned int V_287 ;
int V_13 , V_217 , V_235 , V_3 ;
T_1 V_216 = 0 ;
if ( ! V_66 -> V_134 ) {
F_25 ( & V_66 -> V_15 , L_31 ) ;
return - V_192 ;
}
V_13 = F_96 ( V_66 , & V_235 , & V_3 , & V_216 ) ;
if ( V_13 < 0 ) {
F_25 ( & V_66 -> V_15 , L_32 , V_13 ) ;
return V_13 ;
}
if ( F_2 ( V_235 ) ) {
V_13 = F_113 ( & V_66 -> V_15 , V_235 ,
V_288 , L_33 ) ;
if ( V_13 )
return V_13 ;
}
if ( F_2 ( V_3 ) ) {
V_13 = F_113 ( & V_66 -> V_15 , V_3 ,
V_289 , L_34 ) ;
if ( V_13 )
return V_13 ;
}
if ( F_2 ( V_235 ) ) {
F_14 ( 1 ) ;
F_114 ( V_235 , 0 ) ;
F_14 ( 1 ) ;
F_114 ( V_235 , 1 ) ;
F_4 ( 120 , 240 ) ;
}
V_63 = F_115 ( sizeof( * V_2 ) , & V_290 ) ;
if ( ! V_63 )
return - V_284 ;
V_2 = V_63 -> V_145 ;
V_2 -> V_63 = V_63 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_3 = V_3 ;
V_63 -> V_291 = & V_66 -> V_15 ;
F_116 ( & V_63 -> V_158 -> V_292 ) ;
V_2 -> V_10 = F_117 ( V_66 , & V_293 ) ;
if ( F_118 ( V_2 -> V_10 ) ) {
V_13 = F_119 ( V_2 -> V_10 ) ;
F_25 ( & V_66 -> V_15 , L_35 ,
V_13 ) ;
goto V_294;
}
F_58 ( V_2 , & V_2 -> V_82 ) ;
F_58 ( V_2 , & V_2 -> V_146 ) ;
V_13 = F_99 ( V_2 ) ;
if ( V_13 < 0 )
goto V_294;
F_120 ( & V_2 -> V_109 ) ;
F_121 ( V_66 , V_2 ) ;
V_13 = F_94 ( V_2 , V_216 ) ;
if ( V_13 )
goto V_294;
V_13 = F_10 ( V_2 , V_55 , 0xff , 0 , & V_287 ) ;
if ( V_13 )
goto V_294;
V_217 = F_95 ( V_66 -> V_134 ) ;
if ( ! V_217 )
V_217 = V_295 ;
V_13 = F_122 ( & V_66 -> V_15 , V_66 -> V_134 , F_62 ,
V_296 | V_217 , F_107 ( & V_66 -> V_15 ) , V_2 ) ;
if ( V_13 )
goto V_294;
F_75 ( V_66 -> V_134 ) ;
F_1 ( V_2 ) ;
V_13 = F_106 ( V_2 ) ;
if ( V_13 )
goto V_294;
V_13 = F_123 ( V_2 -> V_63 ) ;
if ( V_13 )
goto V_297;
return V_13 ;
V_297:
F_110 () ;
V_294:
F_124 ( V_2 -> V_63 ) ;
return V_13 ;
}
static int F_125 ( struct V_234 * V_66 )
{
struct V_1 * V_2 = F_126 ( V_66 ) ;
F_11 ( V_2 , V_226 , 0 ) ;
F_127 ( V_2 -> V_63 ) ;
F_124 ( V_2 -> V_63 ) ;
F_110 () ;
F_128 ( & V_66 -> V_15 , L_36 ) ;
return 0 ;
}
