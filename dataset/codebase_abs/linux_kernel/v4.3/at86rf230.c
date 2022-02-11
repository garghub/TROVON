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
V_2 -> V_63 = 0 ;
F_20 ( V_2 , V_62 , V_64 , NULL , false ) ;
F_21 ( V_2 -> V_65 ) ;
}
static inline void
F_22 ( struct V_1 * V_2 ,
struct V_61 * V_62 , int V_13 )
{
F_23 ( & V_2 -> V_66 -> V_15 , L_1 , V_13 ) ;
F_20 ( V_2 , V_62 , V_67 ,
F_19 , false ) ;
}
static void
F_24 ( struct V_1 * V_2 , const T_1 V_16 ,
struct V_61 * V_62 ,
void (* F_25)( void * V_60 ) ,
const bool V_68 )
{
int V_13 ;
T_1 * V_69 = V_62 -> V_70 ;
V_69 [ 0 ] = ( V_16 & V_71 ) | V_72 ;
V_62 -> V_73 . F_25 = F_25 ;
V_62 -> V_68 = V_68 ;
V_13 = F_26 ( V_2 -> V_66 , & V_62 -> V_73 ) ;
if ( V_13 ) {
if ( V_68 )
F_27 ( V_62 -> V_74 ) ;
F_22 ( V_2 , V_62 , V_13 ) ;
}
}
static inline T_1 F_28 ( T_1 V_75 )
{
if ( V_75 == V_76 )
return V_77 ;
else
return V_67 ;
}
static void
F_29 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
const T_1 * V_70 = V_62 -> V_70 ;
const T_1 V_78 = V_70 [ 1 ] & V_79 ;
if ( V_78 != V_62 -> V_80 ) {
if ( V_78 == V_81 ) {
if ( V_62 -> V_80 == V_64 )
goto V_82;
if ( V_62 -> V_80 == V_76 ||
V_62 -> V_80 == V_83 ) {
T_1 V_75 = V_62 -> V_80 ;
if ( V_2 -> V_84 >= V_85 )
V_75 = F_28 ( V_75 ) ;
V_2 -> V_84 ++ ;
F_20 ( V_2 , V_62 , V_75 ,
V_62 -> F_25 ,
V_62 -> V_68 ) ;
return;
}
}
F_30 ( & V_2 -> V_66 -> V_15 , L_2 ,
V_62 -> V_86 , V_62 -> V_80 , V_78 ) ;
}
V_82:
if ( V_62 -> F_25 )
V_62 -> F_25 ( V_60 ) ;
}
static enum V_87 F_31 ( struct V_88 * V_89 )
{
struct V_61 * V_62 =
F_32 ( V_89 , struct V_61 , V_89 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_24 ( V_2 , V_53 , V_62 ,
F_29 ,
V_62 -> V_68 ) ;
return V_90 ;
}
static void
F_33 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_91 * V_92 = V_2 -> V_4 ;
bool V_93 = false ;
T_2 V_94 ;
switch ( V_62 -> V_80 ) {
case V_77 :
V_62 -> V_80 = V_76 ;
V_93 = true ;
break;
case V_67 :
V_62 -> V_80 = V_83 ;
V_93 = true ;
break;
default:
break;
}
switch ( V_62 -> V_86 ) {
case V_83 :
switch ( V_62 -> V_80 ) {
case V_64 :
V_94 = F_34 ( 0 , V_92 -> V_95 * V_96 ) ;
V_2 -> V_97 = V_98 + V_99 ;
goto V_100;
case V_101 :
case V_76 :
V_94 = F_34 ( 0 , V_92 -> V_102 * V_96 ) ;
V_2 -> V_97 = V_98 + V_99 ;
goto V_100;
default:
break;
}
break;
case V_81 :
switch ( V_62 -> V_80 ) {
case V_83 :
case V_76 :
if ( ! V_93 ) {
V_94 = F_34 ( 0 , ( V_92 -> V_103 + V_92 -> V_104 ) *
V_96 ) ;
goto V_100;
}
break;
default:
break;
}
break;
case V_105 :
switch ( V_62 -> V_80 ) {
case V_83 :
V_94 = F_34 ( 0 , V_92 -> V_106 * V_96 ) ;
goto V_100;
default:
break;
}
break;
default:
break;
}
F_14 ( 1 ) ;
F_31 ( & V_62 -> V_89 ) ;
return;
V_100:
F_35 ( & V_62 -> V_89 , V_94 , V_107 ) ;
}
static void
F_36 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 * V_70 = V_62 -> V_70 ;
const T_1 V_78 = V_70 [ 1 ] & V_79 ;
int V_13 ;
if ( V_78 == V_108 ) {
F_14 ( 1 ) ;
F_24 ( V_2 , V_53 , V_62 ,
F_36 ,
V_62 -> V_68 ) ;
return;
}
if ( V_78 == V_62 -> V_80 ) {
if ( V_62 -> F_25 )
V_62 -> F_25 ( V_60 ) ;
return;
}
V_62 -> V_86 = V_78 ;
V_70 [ 0 ] = ( V_17 & V_71 ) | V_72 | V_109 ;
V_70 [ 1 ] = V_62 -> V_80 ;
V_62 -> V_73 . F_25 = F_33 ;
V_13 = F_26 ( V_2 -> V_66 , & V_62 -> V_73 ) ;
if ( V_13 ) {
if ( V_62 -> V_68 )
F_27 ( V_62 -> V_74 ) ;
F_22 ( V_2 , V_62 , V_13 ) ;
}
}
static void
F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
const T_1 V_75 , void (* F_25)( void * V_60 ) ,
const bool V_68 )
{
V_62 -> V_80 = V_75 ;
V_62 -> F_25 = F_25 ;
V_62 -> V_68 = V_68 ;
F_24 ( V_2 , V_53 , V_62 ,
F_36 ,
V_68 ) ;
}
static void
F_37 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_25 ( & V_2 -> V_110 ) ;
}
static int
F_38 ( struct V_1 * V_2 , unsigned int V_75 )
{
unsigned long V_13 ;
F_20 ( V_2 , & V_2 -> V_75 , V_75 ,
F_37 ,
false ) ;
V_13 = F_39 ( & V_2 -> V_110 ,
F_40 ( 100 ) ) ;
if ( ! V_13 ) {
F_22 ( V_2 , & V_2 -> V_75 , - V_111 ) ;
return - V_111 ;
}
return 0 ;
}
static void
F_41 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_27 ( V_62 -> V_74 ) ;
F_42 ( V_2 -> V_65 , V_2 -> V_112 , false ) ;
}
static void
F_43 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_20 ( V_2 , V_62 , V_64 ,
F_41 , true ) ;
}
static void
F_44 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
const T_1 * V_70 = V_62 -> V_70 ;
const T_1 V_113 = ( V_70 [ 1 ] & 0xe0 ) >> 5 ;
if ( V_113 )
F_20 ( V_2 , V_62 , V_67 ,
F_43 , true ) ;
else
F_43 ( V_60 ) ;
}
static void
F_45 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_24 ( V_2 , V_17 , V_62 ,
F_44 , true ) ;
}
static void
F_46 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 V_114 [ V_115 ] ;
const T_1 * V_70 = V_62 -> V_70 ;
struct V_116 * V_117 ;
T_1 V_118 , V_119 ;
V_118 = V_70 [ 1 ] ;
if ( ! F_47 ( V_118 ) ) {
F_48 ( & V_2 -> V_66 -> V_15 , L_3 ) ;
V_118 = V_120 ;
}
V_119 = V_70 [ 2 + V_118 ] ;
memcpy ( V_114 , V_70 + 2 , V_118 ) ;
V_62 -> V_121 . V_118 = 2 ;
F_27 ( V_62 -> V_74 ) ;
V_117 = F_49 ( V_120 ) ;
if ( ! V_117 ) {
F_48 ( & V_2 -> V_66 -> V_15 , L_4 ) ;
return;
}
memcpy ( F_50 ( V_117 , V_118 ) , V_114 , V_118 ) ;
F_51 ( V_2 -> V_65 , V_117 , V_119 ) ;
}
static void
F_52 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 * V_70 = V_62 -> V_70 ;
int V_13 ;
V_70 [ 0 ] = V_122 ;
V_62 -> V_121 . V_118 = V_115 ;
V_62 -> V_73 . F_25 = F_46 ;
V_13 = F_26 ( V_2 -> V_66 , & V_62 -> V_73 ) ;
if ( V_13 ) {
V_62 -> V_121 . V_118 = 2 ;
F_27 ( V_62 -> V_74 ) ;
F_22 ( V_2 , V_62 , V_13 ) ;
}
}
static void
F_53 ( void * V_60 )
{
F_52 ( V_60 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 ) {
V_2 -> V_63 = 0 ;
F_20 ( V_2 , & V_2 -> V_74 ,
V_77 ,
F_45 ,
true ) ;
} else {
F_24 ( V_2 , V_17 , & V_2 -> V_74 ,
F_53 , true ) ;
}
}
static void
F_55 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
const T_1 * V_70 = V_62 -> V_70 ;
const T_1 V_74 = V_70 [ 1 ] ;
if ( V_74 & V_123 ) {
F_54 ( V_2 ) ;
} else {
F_27 ( V_62 -> V_74 ) ;
F_23 ( & V_2 -> V_66 -> V_15 , L_5 ,
V_74 ) ;
}
}
static T_3 F_56 ( int V_74 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_61 * V_62 = & V_2 -> V_74 ;
T_1 * V_70 = V_62 -> V_70 ;
int V_13 ;
F_57 ( V_74 ) ;
V_70 [ 0 ] = ( V_55 & V_71 ) | V_72 ;
V_62 -> V_73 . F_25 = F_55 ;
V_13 = F_26 ( V_2 -> V_66 , & V_62 -> V_73 ) ;
if ( V_13 ) {
F_27 ( V_74 ) ;
F_22 ( V_2 , V_62 , V_13 ) ;
return V_124 ;
}
return V_125 ;
}
static void
F_58 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 * V_70 = V_62 -> V_70 ;
int V_13 ;
V_62 -> V_121 . V_118 = 2 ;
if ( F_2 ( V_2 -> V_3 ) ) {
F_13 ( V_2 ) ;
} else {
V_70 [ 0 ] = ( V_17 & V_71 ) | V_72 | V_109 ;
V_70 [ 1 ] = V_126 ;
V_62 -> V_73 . F_25 = NULL ;
V_13 = F_26 ( V_2 -> V_66 , & V_62 -> V_73 ) ;
if ( V_13 )
F_22 ( V_2 , V_62 , V_13 ) ;
}
}
static void
F_59 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_116 * V_117 = V_2 -> V_112 ;
T_1 * V_70 = V_62 -> V_70 ;
int V_13 ;
V_2 -> V_63 = 1 ;
V_70 [ 0 ] = V_122 | V_109 ;
V_70 [ 1 ] = V_117 -> V_118 + 2 ;
memcpy ( V_70 + 2 , V_117 -> V_4 , V_117 -> V_118 ) ;
V_62 -> V_121 . V_118 = V_117 -> V_118 + 2 ;
V_62 -> V_73 . F_25 = F_58 ;
V_13 = F_26 ( V_2 -> V_66 , & V_62 -> V_73 ) ;
if ( V_13 ) {
V_62 -> V_121 . V_118 = 2 ;
F_22 ( V_2 , V_62 , V_13 ) ;
}
}
static void
F_60 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
F_20 ( V_2 , V_62 , V_101 ,
F_59 , false ) ;
}
static void
F_61 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( V_2 -> V_127 ) {
V_2 -> V_127 = false ;
F_20 ( V_2 , V_62 , V_101 ,
F_59 ,
false ) ;
} else {
F_20 ( V_2 , V_62 , V_76 ,
F_60 ,
false ) ;
}
}
static int
F_62 ( struct V_128 * V_65 , struct V_116 * V_117 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
struct V_61 * V_62 = & V_2 -> V_130 ;
V_2 -> V_112 = V_117 ;
V_2 -> V_84 = 0 ;
if ( F_63 ( V_2 -> V_97 ) ) {
V_2 -> V_127 = true ;
F_20 ( V_2 , V_62 , V_83 ,
F_61 , false ) ;
} else {
F_61 ( V_62 ) ;
}
return 0 ;
}
static int
F_64 ( struct V_128 * V_65 , T_1 * V_131 )
{
F_65 ( ! V_131 ) ;
* V_131 = 0xbe ;
return 0 ;
}
static int
F_66 ( struct V_128 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
F_5 ( V_2 ) ;
F_27 ( V_2 -> V_66 -> V_74 ) ;
return F_38 ( V_2 , V_64 ) ;
}
static void
F_67 ( struct V_128 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
T_1 V_132 [ 2 ] ;
F_38 ( V_2 , V_67 ) ;
F_68 ( V_2 -> V_66 -> V_74 ) ;
F_69 ( V_132 , F_70 ( V_132 ) ) ;
F_11 ( V_2 , V_133 , V_132 [ 0 ] ) ;
F_11 ( V_2 , V_134 , V_132 [ 1 ] ) ;
F_1 ( V_2 ) ;
}
static int
F_71 ( struct V_1 * V_2 , T_1 V_135 , T_1 V_136 )
{
return F_11 ( V_2 , V_137 , V_136 ) ;
}
static inline int
F_72 ( struct V_1 * V_2 , int V_138 )
{
unsigned int V_139 ;
int V_13 ;
V_13 = F_10 ( V_2 , V_140 , & V_139 ) ;
if ( V_13 < 0 )
return V_13 ;
switch ( V_138 ) {
case - 98 :
V_2 -> V_65 -> V_141 -> V_142 . V_143 = V_144 ;
V_2 -> V_65 -> V_141 -> V_142 . V_145 = F_70 ( V_144 ) ;
V_2 -> V_65 -> V_141 -> V_146 = V_144 [ V_139 ] ;
break;
case - 100 :
V_2 -> V_65 -> V_141 -> V_142 . V_143 = V_147 ;
V_2 -> V_65 -> V_141 -> V_142 . V_145 = F_70 ( V_147 ) ;
V_2 -> V_65 -> V_141 -> V_146 = V_147 [ V_139 ] ;
break;
default:
F_73 ( 1 ) ;
}
return 0 ;
}
static int
F_74 ( struct V_1 * V_2 , T_1 V_135 , T_1 V_136 )
{
int V_13 ;
if ( V_136 == 0 )
V_13 = F_11 ( V_2 , V_148 , 0 ) ;
else
V_13 = F_11 ( V_2 , V_148 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_135 == 0 ) {
V_13 = F_11 ( V_2 , V_149 , 0 ) ;
V_2 -> V_4 -> V_138 = - 100 ;
} else {
V_13 = F_11 ( V_2 , V_149 , 1 ) ;
V_2 -> V_4 -> V_138 = - 98 ;
}
if ( V_13 < 0 )
return V_13 ;
V_13 = F_72 ( V_2 , V_2 -> V_4 -> V_138 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_136 == 0 ) {
if ( V_135 == 0 ) {
V_2 -> V_65 -> V_141 -> V_150 = 50 ;
} else {
V_2 -> V_65 -> V_141 -> V_150 = 25 ;
}
} else {
if ( V_135 == 0 )
V_2 -> V_65 -> V_141 -> V_150 = 40 ;
else
V_2 -> V_65 -> V_141 -> V_150 = 16 ;
}
V_2 -> V_65 -> V_141 -> V_151 = V_152 *
V_2 -> V_65 -> V_141 -> V_150 ;
V_2 -> V_65 -> V_141 -> V_153 = V_154 *
V_2 -> V_65 -> V_141 -> V_150 ;
return F_11 ( V_2 , V_137 , V_136 ) ;
}
static int
F_75 ( struct V_128 * V_65 , T_1 V_135 , T_1 V_136 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
int V_13 ;
V_13 = V_2 -> V_4 -> V_155 ( V_2 , V_135 , V_136 ) ;
F_4 ( V_2 -> V_4 -> V_156 ,
V_2 -> V_4 -> V_156 + 10 ) ;
V_2 -> V_97 = V_98 + V_99 ;
return V_13 ;
}
static int
F_76 ( struct V_128 * V_65 ,
struct V_157 * V_158 ,
unsigned long V_159 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
if ( V_159 & V_160 ) {
T_4 V_8 = F_77 ( V_158 -> V_161 ) ;
F_48 ( & V_2 -> V_66 -> V_15 ,
L_6 ) ;
F_6 ( V_2 , V_37 , V_8 ) ;
F_6 ( V_2 , V_38 , V_8 >> 8 ) ;
}
if ( V_159 & V_162 ) {
T_4 V_163 = F_77 ( V_158 -> V_164 ) ;
F_48 ( & V_2 -> V_66 -> V_15 ,
L_7 ) ;
F_6 ( V_2 , V_39 , V_163 ) ;
F_6 ( V_2 , V_40 , V_163 >> 8 ) ;
}
if ( V_159 & V_165 ) {
T_1 V_166 , V_8 [ 8 ] ;
memcpy ( V_8 , & V_158 -> V_167 , 8 ) ;
F_48 ( & V_2 -> V_66 -> V_15 ,
L_8 ) ;
for ( V_166 = 0 ; V_166 < 8 ; V_166 ++ )
F_6 ( V_2 , V_41 + V_166 , V_8 [ V_166 ] ) ;
}
if ( V_159 & V_168 ) {
F_48 ( & V_2 -> V_66 -> V_15 ,
L_9 ) ;
if ( V_158 -> V_169 )
F_11 ( V_2 , V_170 , 1 ) ;
else
F_11 ( V_2 , V_170 , 0 ) ;
}
return 0 ;
}
static int
F_78 ( struct V_1 * V_2 , T_5 V_171 )
{
T_6 V_166 ;
for ( V_166 = 0 ; V_166 < V_2 -> V_65 -> V_141 -> V_142 . V_172 ; V_166 ++ ) {
if ( V_2 -> V_65 -> V_141 -> V_142 . V_173 [ V_166 ] == V_171 )
return F_11 ( V_2 , V_174 , V_166 ) ;
}
return - V_175 ;
}
static int
F_79 ( struct V_1 * V_2 , T_5 V_171 )
{
T_6 V_166 ;
for ( V_166 = 0 ; V_166 < V_2 -> V_65 -> V_141 -> V_142 . V_172 ; V_166 ++ ) {
if ( V_2 -> V_65 -> V_141 -> V_142 . V_173 [ V_166 ] == V_171 )
return F_11 ( V_2 , V_176 , V_166 ) ;
}
return - V_175 ;
}
static int
F_80 ( struct V_128 * V_65 , T_5 V_171 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
return V_2 -> V_4 -> V_177 ( V_2 , V_171 ) ;
}
static int
F_81 ( struct V_128 * V_65 , bool V_178 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
return F_11 ( V_2 , V_179 , V_178 ) ;
}
static int
F_82 ( struct V_128 * V_65 ,
const struct V_180 * V_181 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
T_1 V_182 ;
switch ( V_181 -> V_183 ) {
case V_184 :
V_182 = 1 ;
break;
case V_185 :
V_182 = 2 ;
break;
case V_186 :
switch ( V_181 -> V_187 ) {
case V_188 :
V_182 = 3 ;
break;
case V_189 :
V_182 = 0 ;
break;
default:
return - V_175 ;
}
break;
default:
return - V_175 ;
}
return F_11 ( V_2 , V_190 , V_182 ) ;
}
static int
F_83 ( struct V_128 * V_65 , T_5 V_171 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
T_6 V_166 ;
for ( V_166 = 0 ; V_166 < V_65 -> V_141 -> V_142 . V_145 ; V_166 ++ ) {
if ( V_65 -> V_141 -> V_142 . V_143 [ V_166 ] == V_171 )
return F_11 ( V_2 , V_140 , V_166 ) ;
}
return - V_175 ;
}
static int
F_84 ( struct V_128 * V_65 , T_1 V_191 , T_1 V_192 ,
T_1 V_193 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
int V_13 ;
V_13 = F_11 ( V_2 , V_194 , V_191 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_195 , V_192 ) ;
if ( V_13 )
return V_13 ;
return F_11 ( V_2 , V_196 , V_193 ) ;
}
static int
F_85 ( struct V_128 * V_65 , T_7 V_193 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
return F_11 ( V_2 , V_197 , V_193 ) ;
}
static int
F_86 ( struct V_128 * V_65 , const bool V_178 )
{
struct V_1 * V_2 = V_65 -> V_129 ;
int V_13 ;
if ( V_178 ) {
V_13 = F_11 ( V_2 , V_198 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_11 ( V_2 , V_199 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
} else {
V_13 = F_11 ( V_2 , V_199 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_11 ( V_2 , V_198 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_200 )
{
int V_13 , V_201 , V_202 = V_203 ;
unsigned int V_204 ;
T_1 V_132 [ 2 ] ;
V_13 = F_38 ( V_2 , V_67 ) ;
if ( V_13 )
return V_13 ;
V_201 = F_88 ( V_2 -> V_66 -> V_74 ) ;
if ( V_201 == V_205 ||
V_201 == V_206 )
F_30 ( & V_2 -> V_66 -> V_15 ,
L_10 ) ;
if ( V_201 == V_206 ||
V_201 == V_207 )
V_202 = V_208 ;
V_13 = F_11 ( V_2 , V_209 , V_202 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_210 , 1 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_211 , V_123 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_212 , 0 ) ;
if ( V_13 )
return V_13 ;
F_69 ( V_132 , F_70 ( V_132 ) ) ;
V_13 = F_11 ( V_2 , V_133 , V_132 [ 0 ] ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_134 , V_132 [ 1 ] ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_213 , 0x00 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( V_2 , V_214 , 0x00 ) ;
if ( V_13 )
return V_13 ;
F_4 ( V_2 -> V_4 -> V_215 ,
V_2 -> V_4 -> V_215 + 100 ) ;
V_13 = F_11 ( V_2 , V_216 , V_200 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_10 ( V_2 , V_217 , & V_204 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_204 ) {
F_23 ( & V_2 -> V_66 -> V_15 , L_11 ) ;
return - V_175 ;
}
return F_11 ( V_2 , V_218 , 0 ) ;
}
static int
F_89 ( struct V_219 * V_66 , int * V_220 , int * V_3 ,
T_1 * V_200 )
{
struct V_221 * V_222 = V_66 -> V_15 . V_223 ;
int V_9 ;
if ( ! F_90 ( V_224 ) || ! V_66 -> V_15 . V_225 ) {
if ( ! V_222 )
return - V_226 ;
* V_220 = V_222 -> V_220 ;
* V_3 = V_222 -> V_3 ;
* V_200 = V_222 -> V_200 ;
return 0 ;
}
* V_220 = F_91 ( V_66 -> V_15 . V_225 , L_12 , 0 ) ;
* V_3 = F_91 ( V_66 -> V_15 . V_225 , L_13 , 0 ) ;
V_9 = F_92 ( V_66 -> V_15 . V_225 , L_14 , V_200 ) ;
if ( V_9 < 0 && V_9 != - V_175 )
return V_9 ;
return 0 ;
}
static int
F_93 ( struct V_1 * V_2 )
{
unsigned int V_227 , V_228 , V_182 ;
T_4 V_229 = 0 ;
const char * V_230 ;
int V_13 ;
V_13 = F_8 ( V_2 , V_59 , & V_182 ) ;
if ( V_13 )
return V_13 ;
V_229 |= V_182 ;
V_13 = F_8 ( V_2 , V_58 , & V_182 ) ;
if ( V_13 )
return V_13 ;
V_229 |= ( V_182 << 8 ) ;
V_13 = F_8 ( V_2 , V_56 , & V_227 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_8 ( V_2 , V_57 , & V_228 ) ;
if ( V_13 )
return V_13 ;
if ( V_229 != 0x001f ) {
F_23 ( & V_2 -> V_66 -> V_15 , L_15 ,
V_229 >> 8 , V_229 & 0xFF ) ;
return - V_175 ;
}
V_2 -> V_65 -> V_231 = V_232 |
V_233 |
V_234 | V_235 |
V_236 ;
V_2 -> V_65 -> V_141 -> V_231 = V_237 |
V_238 |
V_239 ;
V_2 -> V_65 -> V_141 -> V_142 . V_240 = F_94 ( V_184 ) |
F_94 ( V_185 ) | F_94 ( V_186 ) ;
V_2 -> V_65 -> V_141 -> V_142 . V_241 = F_94 ( V_188 ) |
F_94 ( V_189 ) ;
V_2 -> V_65 -> V_141 -> V_142 . V_143 = V_242 ;
V_2 -> V_65 -> V_141 -> V_142 . V_145 = F_70 ( V_242 ) ;
V_2 -> V_65 -> V_141 -> V_181 . V_183 = V_184 ;
switch ( V_227 ) {
case 2 :
V_230 = L_16 ;
V_13 = - V_243 ;
goto V_244;
case 3 :
V_230 = L_17 ;
V_2 -> V_4 = & V_245 ;
V_2 -> V_65 -> V_141 -> V_142 . V_246 [ 0 ] = 0x7FFF800 ;
V_2 -> V_65 -> V_141 -> V_247 = 11 ;
V_2 -> V_65 -> V_141 -> V_150 = 16 ;
V_2 -> V_65 -> V_141 -> V_142 . V_173 = V_248 ;
V_2 -> V_65 -> V_141 -> V_142 . V_172 = F_70 ( V_248 ) ;
break;
case 7 :
V_230 = L_18 ;
V_2 -> V_4 = & V_249 ;
V_2 -> V_65 -> V_231 |= V_250 ;
V_2 -> V_65 -> V_141 -> V_142 . V_246 [ 0 ] = 0x00007FF ;
V_2 -> V_65 -> V_141 -> V_142 . V_246 [ 2 ] = 0x00007FF ;
V_2 -> V_65 -> V_141 -> V_247 = 5 ;
V_2 -> V_65 -> V_141 -> V_150 = 25 ;
V_2 -> V_65 -> V_141 -> V_142 . V_251 = V_252 ;
V_2 -> V_65 -> V_141 -> V_142 . V_173 = V_253 ;
V_2 -> V_65 -> V_141 -> V_142 . V_172 = F_70 ( V_253 ) ;
V_2 -> V_65 -> V_141 -> V_142 . V_143 = V_147 ;
V_2 -> V_65 -> V_141 -> V_142 . V_145 = F_70 ( V_147 ) ;
break;
case 11 :
V_230 = L_19 ;
V_2 -> V_4 = & V_254 ;
V_2 -> V_65 -> V_141 -> V_142 . V_246 [ 0 ] = 0x7FFF800 ;
V_2 -> V_65 -> V_141 -> V_247 = 13 ;
V_2 -> V_65 -> V_141 -> V_150 = 16 ;
V_2 -> V_65 -> V_141 -> V_142 . V_173 = V_255 ;
V_2 -> V_65 -> V_141 -> V_142 . V_172 = F_70 ( V_255 ) ;
break;
default:
V_230 = L_20 ;
V_13 = - V_243 ;
goto V_244;
}
V_2 -> V_65 -> V_141 -> V_146 = V_2 -> V_65 -> V_141 -> V_142 . V_143 [ 7 ] ;
V_2 -> V_65 -> V_141 -> V_256 = V_2 -> V_65 -> V_141 -> V_142 . V_173 [ 0 ] ;
V_244:
F_95 ( & V_2 -> V_66 -> V_15 , L_21 , V_230 , V_228 ) ;
return V_13 ;
}
static void
F_96 ( struct V_1 * V_2 )
{
V_2 -> V_75 . V_2 = V_2 ;
V_2 -> V_75 . V_74 = V_2 -> V_66 -> V_74 ;
F_97 ( & V_2 -> V_75 . V_73 ) ;
V_2 -> V_75 . V_73 . V_60 = & V_2 -> V_75 ;
V_2 -> V_75 . V_121 . V_118 = 2 ;
V_2 -> V_75 . V_121 . V_69 = V_2 -> V_75 . V_70 ;
V_2 -> V_75 . V_121 . V_257 = V_2 -> V_75 . V_70 ;
F_98 ( & V_2 -> V_75 . V_121 , & V_2 -> V_75 . V_73 ) ;
F_99 ( & V_2 -> V_75 . V_89 , V_258 , V_107 ) ;
V_2 -> V_75 . V_89 . V_259 = F_31 ;
V_2 -> V_74 . V_2 = V_2 ;
V_2 -> V_74 . V_74 = V_2 -> V_66 -> V_74 ;
F_97 ( & V_2 -> V_74 . V_73 ) ;
V_2 -> V_74 . V_73 . V_60 = & V_2 -> V_74 ;
V_2 -> V_74 . V_121 . V_118 = 2 ;
V_2 -> V_74 . V_121 . V_69 = V_2 -> V_74 . V_70 ;
V_2 -> V_74 . V_121 . V_257 = V_2 -> V_74 . V_70 ;
F_98 ( & V_2 -> V_74 . V_121 , & V_2 -> V_74 . V_73 ) ;
F_99 ( & V_2 -> V_74 . V_89 , V_258 , V_107 ) ;
V_2 -> V_74 . V_89 . V_259 = F_31 ;
V_2 -> V_130 . V_2 = V_2 ;
V_2 -> V_130 . V_74 = V_2 -> V_66 -> V_74 ;
F_97 ( & V_2 -> V_130 . V_73 ) ;
V_2 -> V_130 . V_73 . V_60 = & V_2 -> V_130 ;
V_2 -> V_130 . V_121 . V_118 = 2 ;
V_2 -> V_130 . V_121 . V_69 = V_2 -> V_130 . V_70 ;
V_2 -> V_130 . V_121 . V_257 = V_2 -> V_130 . V_70 ;
F_98 ( & V_2 -> V_130 . V_121 , & V_2 -> V_130 . V_73 ) ;
F_99 ( & V_2 -> V_130 . V_89 , V_258 , V_107 ) ;
V_2 -> V_130 . V_89 . V_259 = F_31 ;
}
static int F_100 ( struct V_219 * V_66 )
{
struct V_128 * V_65 ;
struct V_1 * V_2 ;
unsigned int V_260 ;
int V_13 , V_201 , V_220 , V_3 ;
T_1 V_200 = 0 ;
if ( ! V_66 -> V_74 ) {
F_23 ( & V_66 -> V_15 , L_22 ) ;
return - V_175 ;
}
V_13 = F_89 ( V_66 , & V_220 , & V_3 , & V_200 ) ;
if ( V_13 < 0 ) {
F_23 ( & V_66 -> V_15 , L_23 , V_13 ) ;
return V_13 ;
}
if ( F_2 ( V_220 ) ) {
V_13 = F_101 ( & V_66 -> V_15 , V_220 ,
V_261 , L_24 ) ;
if ( V_13 )
return V_13 ;
}
if ( F_2 ( V_3 ) ) {
V_13 = F_101 ( & V_66 -> V_15 , V_3 ,
V_262 , L_25 ) ;
if ( V_13 )
return V_13 ;
}
if ( F_2 ( V_220 ) ) {
F_14 ( 1 ) ;
F_3 ( V_220 , 0 ) ;
F_14 ( 1 ) ;
F_3 ( V_220 , 1 ) ;
F_4 ( 120 , 240 ) ;
}
V_65 = F_102 ( sizeof( * V_2 ) , & V_263 ) ;
if ( ! V_65 )
return - V_264 ;
V_2 = V_65 -> V_129 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_3 = V_3 ;
V_65 -> V_265 = & V_66 -> V_15 ;
F_103 ( & V_65 -> V_141 -> V_266 ) ;
V_2 -> V_10 = F_104 ( V_66 , & V_267 ) ;
if ( F_105 ( V_2 -> V_10 ) ) {
V_13 = F_106 ( V_2 -> V_10 ) ;
F_23 ( & V_66 -> V_15 , L_26 ,
V_13 ) ;
goto V_268;
}
F_96 ( V_2 ) ;
V_13 = F_93 ( V_2 ) ;
if ( V_13 < 0 )
goto V_268;
F_107 ( & V_2 -> V_110 ) ;
F_108 ( V_66 , V_2 ) ;
V_13 = F_87 ( V_2 , V_200 ) ;
if ( V_13 )
goto V_268;
V_13 = F_10 ( V_2 , V_55 , 0xff , 0 , & V_260 ) ;
if ( V_13 )
goto V_268;
V_201 = F_88 ( V_66 -> V_74 ) ;
if ( ! V_201 )
V_201 = V_269 ;
V_13 = F_109 ( & V_66 -> V_15 , V_66 -> V_74 , F_56 ,
V_270 | V_201 , F_110 ( & V_66 -> V_15 ) , V_2 ) ;
if ( V_13 )
goto V_268;
F_68 ( V_66 -> V_74 ) ;
F_1 ( V_2 ) ;
V_13 = F_111 ( V_2 -> V_65 ) ;
if ( V_13 )
goto V_268;
return V_13 ;
V_268:
F_112 ( V_2 -> V_65 ) ;
return V_13 ;
}
static int F_113 ( struct V_219 * V_66 )
{
struct V_1 * V_2 = F_114 ( V_66 ) ;
F_11 ( V_2 , V_211 , 0 ) ;
F_115 ( V_2 -> V_65 ) ;
F_112 ( V_2 -> V_65 ) ;
F_116 ( & V_66 -> V_15 , L_27 ) ;
return 0 ;
}
