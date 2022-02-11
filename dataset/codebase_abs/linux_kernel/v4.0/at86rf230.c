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
if ( V_8 > 0 )
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
static bool
F_8 ( struct V_9 * V_10 , unsigned int V_11 )
{
switch ( V_11 ) {
case V_12 :
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
return true ;
default:
return false ;
}
}
static bool
F_9 ( struct V_9 * V_10 , unsigned int V_11 )
{
bool V_8 ;
V_8 = F_8 ( V_10 , V_11 ) ;
if ( V_8 )
return V_8 ;
switch ( V_11 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
return true ;
default:
return false ;
}
}
static bool
F_10 ( struct V_9 * V_10 , unsigned int V_11 )
{
switch ( V_11 ) {
case V_48 :
case V_12 :
case V_49 :
case V_16 :
case V_50 :
case V_24 :
return true ;
default:
return false ;
}
}
static bool
F_11 ( struct V_9 * V_10 , unsigned int V_11 )
{
switch ( V_11 ) {
case V_50 :
return true ;
default:
return false ;
}
}
static void
F_12 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_13 ( V_2 , V_57 , V_58 , NULL , false ) ;
F_14 ( V_2 -> V_59 ) ;
}
static inline void
F_15 ( struct V_1 * V_2 ,
struct V_56 * V_57 , int V_8 )
{
F_16 ( & V_2 -> V_60 -> V_10 , L_1 , V_8 ) ;
F_13 ( V_2 , V_57 , V_61 ,
F_12 , false ) ;
}
static void
F_17 ( struct V_1 * V_2 , const T_1 V_11 ,
struct V_56 * V_57 ,
void (* F_18)( void * V_55 ) ,
const bool V_62 )
{
int V_8 ;
T_1 * V_63 = V_57 -> V_64 ;
V_63 [ 0 ] = ( V_11 & V_65 ) | V_66 ;
V_57 -> V_67 . V_68 = 2 ;
V_57 -> V_69 . F_18 = F_18 ;
V_57 -> V_62 = V_62 ;
V_8 = F_19 ( V_2 -> V_60 , & V_57 -> V_69 ) ;
if ( V_8 ) {
if ( V_62 )
F_20 ( V_2 -> V_60 -> V_70 ) ;
F_15 ( V_2 , V_57 , V_8 ) ;
}
}
static void
F_21 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_64 = V_57 -> V_64 ;
const T_1 V_71 = V_64 [ 1 ] & 0x1f ;
if ( V_71 != V_57 -> V_72 ) {
if ( V_71 == V_73 ) {
if ( V_57 -> V_72 == V_58 )
goto V_74;
if ( V_57 -> V_72 == V_75 ) {
F_13 ( V_2 , V_57 ,
V_76 ,
V_57 -> F_18 ,
V_57 -> V_62 ) ;
return;
}
}
F_22 ( & V_2 -> V_60 -> V_10 , L_2 ,
V_57 -> V_77 , V_57 -> V_72 , V_71 ) ;
}
V_74:
if ( V_57 -> F_18 )
V_57 -> F_18 ( V_55 ) ;
}
static void
F_23 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_78 * V_79 = V_2 -> V_4 ;
bool V_80 = false ;
switch ( V_57 -> V_72 ) {
case V_76 :
V_57 -> V_72 = V_75 ;
V_80 = true ;
break;
case V_61 :
V_57 -> V_72 = V_81 ;
V_80 = true ;
break;
default:
break;
}
switch ( V_57 -> V_77 ) {
case V_81 :
switch ( V_57 -> V_72 ) {
case V_58 :
F_24 ( V_79 -> V_82 , V_79 -> V_82 + 10 ) ;
goto V_83;
case V_75 :
F_24 ( V_79 -> V_84 ,
V_79 -> V_84 + 10 ) ;
goto V_83;
default:
break;
}
break;
case V_73 :
switch ( V_57 -> V_72 ) {
case V_75 :
if ( ! V_80 ) {
F_24 ( V_79 -> V_85 + V_79 -> V_86 ,
V_79 -> V_85 + V_79 -> V_86 + 1000 ) ;
goto V_83;
}
break;
default:
break;
}
break;
case V_87 :
switch ( V_57 -> V_72 ) {
case V_81 :
F_24 ( V_79 -> V_88 , V_79 -> V_88 + 10 ) ;
goto V_83;
default:
break;
}
break;
default:
break;
}
F_25 ( 1 ) ;
V_83:
F_17 ( V_2 , V_48 , V_57 ,
F_21 ,
V_57 -> V_62 ) ;
}
static void
F_26 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
T_1 * V_64 = V_57 -> V_64 ;
const T_1 V_71 = V_64 [ 1 ] & 0x1f ;
int V_8 ;
if ( V_71 == V_89 ) {
F_25 ( 1 ) ;
F_17 ( V_2 , V_48 , V_57 ,
F_26 ,
V_57 -> V_62 ) ;
return;
}
if ( V_71 == V_57 -> V_72 ) {
if ( V_57 -> F_18 )
V_57 -> F_18 ( V_55 ) ;
return;
}
V_57 -> V_77 = V_71 ;
V_64 [ 0 ] = ( V_12 & V_65 ) | V_66 | V_90 ;
V_64 [ 1 ] = V_57 -> V_72 ;
V_57 -> V_67 . V_68 = 2 ;
V_57 -> V_69 . F_18 = F_23 ;
V_8 = F_19 ( V_2 -> V_60 , & V_57 -> V_69 ) ;
if ( V_8 ) {
if ( V_57 -> V_62 )
F_20 ( V_2 -> V_60 -> V_70 ) ;
F_15 ( V_2 , V_57 , V_8 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
const T_1 V_91 , void (* F_18)( void * V_55 ) ,
const bool V_62 )
{
V_57 -> V_72 = V_91 ;
V_57 -> F_18 = F_18 ;
V_57 -> V_62 = V_62 ;
F_17 ( V_2 , V_48 , V_57 ,
F_26 ,
V_62 ) ;
}
static void
F_27 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_18 ( & V_2 -> V_92 ) ;
}
static int
F_28 ( struct V_1 * V_2 , unsigned int V_91 )
{
int V_8 ;
F_13 ( V_2 , & V_2 -> V_91 , V_91 ,
F_27 ,
false ) ;
V_8 = F_29 ( & V_2 -> V_92 ,
F_30 ( 100 ) ) ;
if ( ! V_8 ) {
F_15 ( V_2 , & V_2 -> V_91 , - V_93 ) ;
return - V_93 ;
}
return 0 ;
}
static void
F_31 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_94 * V_95 = V_2 -> V_96 ;
F_20 ( V_2 -> V_60 -> V_70 ) ;
F_32 ( V_2 -> V_59 , V_95 , ! V_2 -> V_97 ) ;
}
static void
F_33 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_13 ( V_2 , & V_2 -> V_70 , V_58 ,
F_31 , true ) ;
}
static void
F_34 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_13 ( V_2 , V_57 , V_75 ,
F_33 , true ) ;
}
static void
F_35 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_64 = V_57 -> V_64 ;
const T_1 V_98 = ( V_64 [ 1 ] & 0xe0 ) >> 5 ;
if ( V_98 )
F_13 ( V_2 , V_57 , V_61 ,
F_34 , true ) ;
else
F_33 ( V_55 ) ;
}
static void
F_36 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_17 ( V_2 , V_12 , V_57 ,
F_35 , true ) ;
}
static void
F_37 ( struct V_1 * V_2 ,
const T_1 * V_4 , const T_1 V_68 , const T_1 V_99 )
{
struct V_94 * V_95 ;
T_1 V_100 [ V_101 ] ;
memcpy ( V_100 , V_4 , V_68 ) ;
F_20 ( V_2 -> V_60 -> V_70 ) ;
V_95 = F_38 ( V_102 ) ;
if ( ! V_95 ) {
F_39 ( & V_2 -> V_60 -> V_10 , L_3 ) ;
return;
}
memcpy ( F_40 ( V_95 , V_68 ) , V_100 , V_68 ) ;
F_41 ( V_2 -> V_59 , V_95 , V_99 ) ;
}
static void
F_42 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_64 = V_2 -> V_70 . V_64 ;
T_1 V_68 = V_64 [ 1 ] ;
if ( ! F_43 ( V_68 ) ) {
F_39 ( & V_2 -> V_60 -> V_10 , L_4 ) ;
V_68 = V_102 ;
}
F_37 ( V_2 , V_64 + 2 , V_68 , V_64 [ 2 + V_68 ] ) ;
}
static void
F_44 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 * V_64 = V_2 -> V_70 . V_64 ;
V_64 [ 0 ] = V_103 ;
V_2 -> V_70 . V_67 . V_68 = V_101 ;
V_2 -> V_70 . V_69 . F_18 = F_42 ;
V_8 = F_19 ( V_2 -> V_60 , & V_2 -> V_70 . V_69 ) ;
if ( V_8 ) {
F_20 ( V_2 -> V_60 -> V_70 ) ;
F_15 ( V_2 , & V_2 -> V_70 , V_8 ) ;
}
}
static void
F_45 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_44 ( V_2 ) ;
}
static void
F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_105 ) {
V_2 -> V_105 = 0 ;
F_48 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_97 )
F_13 ( V_2 , & V_2 -> V_70 ,
V_76 ,
F_36 ,
true ) ;
else
F_13 ( V_2 , & V_2 -> V_70 ,
V_58 ,
F_31 ,
true ) ;
} else {
F_48 ( & V_2 -> V_104 ) ;
F_17 ( V_2 , V_12 , & V_2 -> V_70 ,
F_45 , true ) ;
}
}
static void
F_49 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_64 = V_2 -> V_70 . V_64 ;
const T_1 V_70 = V_64 [ 1 ] ;
if ( V_70 & V_106 ) {
F_46 ( V_2 ) ;
} else {
F_20 ( V_2 -> V_60 -> V_70 ) ;
F_16 ( & V_2 -> V_60 -> V_10 , L_5 ,
V_70 ) ;
}
}
static T_2 F_50 ( int V_70 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_56 * V_57 = & V_2 -> V_70 ;
T_1 * V_64 = V_57 -> V_64 ;
int V_8 ;
F_51 ( V_70 ) ;
V_64 [ 0 ] = ( V_50 & V_65 ) | V_66 ;
V_57 -> V_67 . V_68 = 2 ;
V_57 -> V_69 . F_18 = F_49 ;
V_8 = F_19 ( V_2 -> V_60 , & V_57 -> V_69 ) ;
if ( V_8 ) {
F_20 ( V_70 ) ;
F_15 ( V_2 , V_57 , V_8 ) ;
return V_107 ;
}
return V_108 ;
}
static void
F_52 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
T_1 * V_64 = V_57 -> V_64 ;
int V_8 ;
V_64 [ 0 ] = ( V_12 & V_65 ) | V_66 | V_90 ;
V_64 [ 1 ] = V_109 ;
V_57 -> V_67 . V_68 = 2 ;
V_57 -> V_69 . F_18 = NULL ;
V_8 = F_19 ( V_2 -> V_60 , & V_57 -> V_69 ) ;
if ( V_8 )
F_15 ( V_2 , V_57 , V_8 ) ;
}
static void
F_53 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_94 * V_95 = V_2 -> V_96 ;
T_1 * V_64 = V_2 -> V_110 . V_64 ;
int V_8 ;
F_47 ( & V_2 -> V_104 ) ;
V_2 -> V_105 = 1 ;
F_48 ( & V_2 -> V_104 ) ;
V_64 [ 0 ] = V_103 | V_90 ;
V_64 [ 1 ] = V_95 -> V_68 + 2 ;
memcpy ( V_64 + 2 , V_95 -> V_4 , V_95 -> V_68 ) ;
V_2 -> V_110 . V_67 . V_68 = V_95 -> V_68 + 2 ;
V_2 -> V_110 . V_69 . F_18 = F_52 ;
V_8 = F_19 ( V_2 -> V_60 , & V_2 -> V_110 . V_69 ) ;
if ( V_8 )
F_15 ( V_2 , V_57 , V_8 ) ;
}
static void
F_54 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_13 ( V_2 , V_57 , V_111 ,
F_53 , false ) ;
}
static int
F_55 ( struct V_112 * V_59 , struct V_94 * V_95 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
struct V_56 * V_57 = & V_2 -> V_110 ;
void (* F_56)( void * V_55 ) = F_53 ;
V_2 -> V_96 = V_95 ;
if ( V_2 -> V_97 )
F_56 = F_54 ;
F_13 ( V_2 , V_57 , V_75 , F_56 , false ) ;
return 0 ;
}
static int
F_57 ( struct V_112 * V_59 , T_1 * V_114 )
{
F_58 ( ! V_114 ) ;
* V_114 = 0xbe ;
return 0 ;
}
static int
F_59 ( struct V_112 * V_59 )
{
return F_28 ( V_59 -> V_113 , V_58 ) ;
}
static void
F_60 ( struct V_112 * V_59 )
{
F_28 ( V_59 -> V_113 , V_61 ) ;
}
static int
F_61 ( struct V_1 * V_2 , T_1 V_115 , T_1 V_116 )
{
return F_6 ( V_2 , V_117 , V_116 ) ;
}
static int
F_62 ( struct V_1 * V_2 , T_1 V_115 , T_1 V_116 )
{
int V_8 ;
if ( V_116 == 0 )
V_8 = F_6 ( V_2 , V_118 , 0 ) ;
else
V_8 = F_6 ( V_2 , V_118 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_115 == 0 ) {
V_8 = F_6 ( V_2 , V_119 , 0 ) ;
V_2 -> V_4 -> V_120 = - 100 ;
} else {
V_8 = F_6 ( V_2 , V_119 , 1 ) ;
V_2 -> V_4 -> V_120 = - 98 ;
}
if ( V_8 < 0 )
return V_8 ;
if ( V_116 == 0 ) {
if ( V_115 == 0 ) {
V_2 -> V_59 -> V_121 -> V_122 = 50 ;
} else {
V_2 -> V_59 -> V_121 -> V_122 = 25 ;
}
} else {
if ( V_115 == 0 )
V_2 -> V_59 -> V_121 -> V_122 = 40 ;
else
V_2 -> V_59 -> V_121 -> V_122 = 16 ;
}
V_2 -> V_59 -> V_121 -> V_123 = V_124 *
V_2 -> V_59 -> V_121 -> V_122 ;
V_2 -> V_59 -> V_121 -> V_125 = V_126 *
V_2 -> V_59 -> V_121 -> V_122 ;
return F_6 ( V_2 , V_117 , V_116 ) ;
}
static int
F_63 ( struct V_112 * V_59 , T_1 V_115 , T_1 V_116 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
int V_8 ;
V_8 = V_2 -> V_4 -> V_127 ( V_2 , V_115 , V_116 ) ;
F_24 ( V_2 -> V_4 -> V_128 ,
V_2 -> V_4 -> V_128 + 10 ) ;
return V_8 ;
}
static int
F_64 ( struct V_112 * V_59 ,
struct V_129 * V_130 ,
unsigned long V_131 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
if ( V_131 & V_132 ) {
T_3 V_3 = F_65 ( V_130 -> V_133 ) ;
F_39 ( & V_2 -> V_60 -> V_10 ,
L_6 ) ;
F_1 ( V_2 , V_32 , V_3 ) ;
F_1 ( V_2 , V_33 , V_3 >> 8 ) ;
}
if ( V_131 & V_134 ) {
T_3 V_135 = F_65 ( V_130 -> V_136 ) ;
F_39 ( & V_2 -> V_60 -> V_10 ,
L_7 ) ;
F_1 ( V_2 , V_34 , V_135 ) ;
F_1 ( V_2 , V_35 , V_135 >> 8 ) ;
}
if ( V_131 & V_137 ) {
T_1 V_138 , V_3 [ 8 ] ;
memcpy ( V_3 , & V_130 -> V_139 , 8 ) ;
F_39 ( & V_2 -> V_60 -> V_10 ,
L_8 ) ;
for ( V_138 = 0 ; V_138 < 8 ; V_138 ++ )
F_1 ( V_2 , V_36 + V_138 , V_3 [ V_138 ] ) ;
}
if ( V_131 & V_140 ) {
F_39 ( & V_2 -> V_60 -> V_10 ,
L_9 ) ;
if ( V_130 -> V_141 )
F_6 ( V_2 , V_142 , 1 ) ;
else
F_6 ( V_2 , V_142 , 0 ) ;
}
return 0 ;
}
static int
F_66 ( struct V_112 * V_59 , int V_143 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
if ( V_143 > 5 || V_143 < - 26 )
return - V_144 ;
V_143 = - ( V_143 - 5 ) ;
return F_1 ( V_2 , V_15 , 0x60 | V_143 ) ;
}
static int
F_67 ( struct V_112 * V_59 , bool V_145 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
return F_6 ( V_2 , V_146 , V_145 ) ;
}
static int
F_68 ( struct V_112 * V_59 ,
const struct V_147 * V_148 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
T_1 V_149 ;
switch ( V_148 -> V_150 ) {
case V_151 :
V_149 = 1 ;
break;
case V_152 :
V_149 = 2 ;
break;
case V_153 :
switch ( V_148 -> V_154 ) {
case V_155 :
V_149 = 3 ;
break;
case V_156 :
V_149 = 0 ;
break;
default:
return - V_144 ;
}
break;
default:
return - V_144 ;
}
return F_6 ( V_2 , V_157 , V_149 ) ;
}
static int
F_69 ( struct V_1 * V_2 , T_4 V_114 )
{
return ( V_114 - V_2 -> V_4 -> V_120 ) * 100 / 207 ;
}
static int
F_70 ( struct V_1 * V_2 , T_4 V_114 )
{
return ( V_114 - V_2 -> V_4 -> V_120 ) / 2 ;
}
static int
F_71 ( struct V_112 * V_59 , T_4 V_114 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
if ( V_114 < V_2 -> V_4 -> V_120 || V_114 > 30 )
return - V_144 ;
return F_6 ( V_2 , V_158 ,
V_2 -> V_4 -> V_159 ( V_2 , V_114 ) ) ;
}
static int
F_72 ( struct V_112 * V_59 , T_1 V_160 , T_1 V_161 ,
T_1 V_162 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
int V_8 ;
V_8 = F_6 ( V_2 , V_163 , V_160 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_164 , V_161 ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_2 , V_165 , V_162 ) ;
}
static int
F_73 ( struct V_112 * V_59 , T_5 V_162 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
int V_8 = 0 ;
V_2 -> V_97 = V_162 >= 0 ;
V_2 -> V_166 = V_162 ;
if ( V_162 >= 0 )
V_8 = F_6 ( V_2 , V_167 , V_162 ) ;
return V_8 ;
}
static int
F_74 ( struct V_112 * V_59 , const bool V_145 )
{
struct V_1 * V_2 = V_59 -> V_113 ;
int V_8 ;
if ( V_145 ) {
V_8 = F_6 ( V_2 , V_168 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 , V_169 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
V_8 = F_6 ( V_2 , V_169 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_6 ( V_2 , V_168 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_8 , V_170 , V_171 = V_172 ;
unsigned int V_173 ;
T_1 V_174 [ 2 ] ;
V_8 = F_28 ( V_2 , V_61 ) ;
if ( V_8 )
return V_8 ;
V_170 = F_76 ( V_2 -> V_60 -> V_70 ) ;
if ( V_170 == V_175 )
V_171 = V_176 ;
V_8 = F_6 ( V_2 , V_177 , V_171 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_178 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_179 , V_106 ) ;
if ( V_8 )
return V_8 ;
F_77 ( V_174 , F_78 ( V_174 ) ) ;
V_8 = F_6 ( V_2 , V_180 , V_174 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_181 , V_174 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_182 , 0x00 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_183 , 0x00 ) ;
if ( V_8 )
return V_8 ;
F_24 ( V_2 -> V_4 -> V_184 ,
V_2 -> V_4 -> V_184 + 100 ) ;
V_8 = F_5 ( V_2 , V_185 , & V_173 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_173 ) {
F_16 ( & V_2 -> V_60 -> V_10 , L_10 ) ;
return - V_144 ;
}
return F_6 ( V_2 , V_186 , 0 ) ;
}
static struct V_187 *
F_79 ( struct V_188 * V_60 )
{
struct V_187 * V_189 ;
if ( ! F_80 ( V_190 ) || ! V_60 -> V_10 . V_191 )
return V_60 -> V_10 . V_192 ;
V_189 = F_81 ( & V_60 -> V_10 , sizeof( * V_189 ) , V_193 ) ;
if ( ! V_189 )
goto V_74;
V_189 -> V_194 = F_82 ( V_60 -> V_10 . V_191 , L_11 , 0 ) ;
V_189 -> V_195 = F_82 ( V_60 -> V_10 . V_191 , L_12 , 0 ) ;
V_60 -> V_10 . V_192 = V_189 ;
V_74:
return V_189 ;
}
static int
F_83 ( struct V_1 * V_2 )
{
unsigned int V_196 , V_197 , V_149 ;
T_3 V_198 = 0 ;
const char * V_199 ;
int V_8 ;
V_8 = F_3 ( V_2 , V_54 , & V_149 ) ;
if ( V_8 )
return V_8 ;
V_198 |= V_149 ;
V_8 = F_3 ( V_2 , V_53 , & V_149 ) ;
if ( V_8 )
return V_8 ;
V_198 |= ( V_149 << 8 ) ;
V_8 = F_3 ( V_2 , V_51 , & V_196 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_52 , & V_197 ) ;
if ( V_8 )
return V_8 ;
if ( V_198 != 0x001f ) {
F_16 ( & V_2 -> V_60 -> V_10 , L_13 ,
V_198 >> 8 , V_198 & 0xFF ) ;
return - V_144 ;
}
V_2 -> V_59 -> V_200 = V_201 | V_202 |
V_203 | V_204 |
V_205 | V_206 ;
V_2 -> V_59 -> V_121 -> V_148 . V_150 = V_151 ;
switch ( V_196 ) {
case 2 :
V_199 = L_14 ;
V_8 = - V_207 ;
break;
case 3 :
V_199 = L_15 ;
V_2 -> V_4 = & V_208 ;
V_2 -> V_59 -> V_121 -> V_209 [ 0 ] = 0x7FFF800 ;
V_2 -> V_59 -> V_121 -> V_210 = 11 ;
V_2 -> V_59 -> V_121 -> V_122 = 16 ;
break;
case 7 :
V_199 = L_16 ;
V_2 -> V_4 = & V_211 ;
V_2 -> V_59 -> V_200 |= V_212 ;
V_2 -> V_59 -> V_121 -> V_209 [ 0 ] = 0x00007FF ;
V_2 -> V_59 -> V_121 -> V_209 [ 2 ] = 0x00007FF ;
V_2 -> V_59 -> V_121 -> V_210 = 5 ;
V_2 -> V_59 -> V_121 -> V_122 = 25 ;
break;
case 11 :
V_199 = L_17 ;
V_2 -> V_4 = & V_213 ;
V_2 -> V_59 -> V_121 -> V_209 [ 0 ] = 0x7FFF800 ;
V_2 -> V_59 -> V_121 -> V_210 = 13 ;
V_2 -> V_59 -> V_121 -> V_122 = 16 ;
break;
default:
V_199 = L_18 ;
V_8 = - V_207 ;
break;
}
F_84 ( & V_2 -> V_60 -> V_10 , L_19 , V_199 , V_197 ) ;
return V_8 ;
}
static void
F_85 ( struct V_1 * V_2 )
{
V_2 -> V_91 . V_2 = V_2 ;
F_86 ( & V_2 -> V_91 . V_69 ) ;
V_2 -> V_91 . V_69 . V_55 = & V_2 -> V_91 ;
V_2 -> V_91 . V_67 . V_63 = V_2 -> V_91 . V_64 ;
V_2 -> V_91 . V_67 . V_214 = V_2 -> V_91 . V_64 ;
F_87 ( & V_2 -> V_91 . V_67 , & V_2 -> V_91 . V_69 ) ;
V_2 -> V_70 . V_2 = V_2 ;
F_86 ( & V_2 -> V_70 . V_69 ) ;
V_2 -> V_70 . V_69 . V_55 = & V_2 -> V_70 ;
V_2 -> V_70 . V_67 . V_63 = V_2 -> V_70 . V_64 ;
V_2 -> V_70 . V_67 . V_214 = V_2 -> V_70 . V_64 ;
F_87 ( & V_2 -> V_70 . V_67 , & V_2 -> V_70 . V_69 ) ;
V_2 -> V_110 . V_2 = V_2 ;
F_86 ( & V_2 -> V_110 . V_69 ) ;
V_2 -> V_110 . V_69 . V_55 = & V_2 -> V_110 ;
V_2 -> V_110 . V_67 . V_63 = V_2 -> V_110 . V_64 ;
V_2 -> V_110 . V_67 . V_214 = V_2 -> V_110 . V_64 ;
F_87 ( & V_2 -> V_110 . V_67 , & V_2 -> V_110 . V_69 ) ;
}
static int F_88 ( struct V_188 * V_60 )
{
struct V_187 * V_189 ;
struct V_112 * V_59 ;
struct V_1 * V_2 ;
unsigned int V_215 ;
int V_8 , V_170 ;
if ( ! V_60 -> V_70 ) {
F_16 ( & V_60 -> V_10 , L_20 ) ;
return - V_144 ;
}
V_189 = F_79 ( V_60 ) ;
if ( ! V_189 ) {
F_16 ( & V_60 -> V_10 , L_21 ) ;
return - V_144 ;
}
if ( F_89 ( V_189 -> V_194 ) ) {
V_8 = F_90 ( & V_60 -> V_10 , V_189 -> V_194 ,
V_216 , L_22 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_89 ( V_189 -> V_195 ) ) {
V_8 = F_90 ( & V_60 -> V_10 , V_189 -> V_195 ,
V_217 , L_23 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_89 ( V_189 -> V_194 ) ) {
F_25 ( 1 ) ;
F_91 ( V_189 -> V_194 , 0 ) ;
F_25 ( 1 ) ;
F_91 ( V_189 -> V_194 , 1 ) ;
F_24 ( 120 , 240 ) ;
}
V_59 = F_92 ( sizeof( * V_2 ) , & V_218 ) ;
if ( ! V_59 )
return - V_219 ;
V_2 = V_59 -> V_113 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_60 = V_60 ;
V_59 -> V_220 = & V_60 -> V_10 ;
V_59 -> V_221 = sizeof( * V_2 ) ;
F_93 ( & V_59 -> V_121 -> V_222 ) ;
V_2 -> V_5 = F_94 ( V_60 , & V_223 ) ;
if ( F_95 ( V_2 -> V_5 ) ) {
V_8 = F_96 ( V_2 -> V_5 ) ;
F_16 ( & V_60 -> V_10 , L_24 ,
V_8 ) ;
goto V_224;
}
F_85 ( V_2 ) ;
V_8 = F_83 ( V_2 ) ;
if ( V_8 < 0 )
goto V_224;
F_97 ( & V_2 -> V_104 ) ;
F_98 ( & V_2 -> V_92 ) ;
F_99 ( V_60 , V_2 ) ;
V_8 = F_75 ( V_2 ) ;
if ( V_8 )
goto V_224;
V_8 = F_5 ( V_2 , V_50 , 0xff , 0 , & V_215 ) ;
if ( V_8 )
goto V_224;
V_170 = F_76 ( V_60 -> V_70 ) ;
if ( ! V_170 )
V_170 = V_225 ;
V_8 = F_100 ( & V_60 -> V_10 , V_60 -> V_70 , F_50 ,
V_226 | V_170 , F_101 ( & V_60 -> V_10 ) , V_2 ) ;
if ( V_8 )
goto V_224;
V_8 = F_102 ( V_2 -> V_59 ) ;
if ( V_8 )
goto V_224;
return V_8 ;
V_224:
F_103 ( V_2 -> V_59 ) ;
return V_8 ;
}
static int F_104 ( struct V_188 * V_60 )
{
struct V_1 * V_2 = F_105 ( V_60 ) ;
F_6 ( V_2 , V_179 , 0 ) ;
F_106 ( V_2 -> V_59 ) ;
F_103 ( V_2 -> V_59 ) ;
F_107 ( & V_60 -> V_10 , L_25 ) ;
return 0 ;
}
