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
F_13 ( V_2 , V_57 , V_58 , NULL ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_56 * V_57 , int V_8 )
{
F_15 ( & V_2 -> V_59 -> V_10 , L_1 , V_8 ) ;
F_13 ( V_2 , V_57 , V_60 ,
F_12 ) ;
}
static int
F_16 ( struct V_1 * V_2 , const T_1 V_11 ,
struct V_56 * V_57 ,
void (* F_17)( void * V_55 ) )
{
T_1 * V_61 = V_57 -> V_62 ;
V_61 [ 0 ] = ( V_11 & V_63 ) | V_64 ;
V_57 -> V_65 . V_66 = 2 ;
V_57 -> V_67 . F_17 = F_17 ;
return F_18 ( V_2 -> V_59 , & V_57 -> V_67 ) ;
}
static void
F_19 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_62 = V_57 -> V_62 ;
const T_1 V_68 = V_62 [ 1 ] & 0x1f ;
if ( V_68 != V_57 -> V_69 ) {
if ( V_68 == V_70 ) {
if ( V_57 -> V_69 == V_58 )
goto V_71;
if ( V_57 -> V_69 == V_72 ) {
F_13 ( V_2 , V_57 ,
V_73 ,
V_57 -> F_17 ) ;
return;
}
}
F_20 ( & V_2 -> V_59 -> V_10 , L_2 ,
V_57 -> V_74 , V_57 -> V_69 , V_68 ) ;
}
V_71:
if ( V_57 -> F_17 )
V_57 -> F_17 ( V_55 ) ;
}
static void
F_21 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_75 * V_76 = V_2 -> V_4 ;
bool V_77 = false ;
int V_8 ;
switch ( V_57 -> V_69 ) {
case V_73 :
V_57 -> V_69 = V_72 ;
V_77 = true ;
break;
case V_60 :
V_57 -> V_69 = V_78 ;
V_77 = true ;
break;
default:
break;
}
switch ( V_57 -> V_74 ) {
case V_78 :
switch ( V_57 -> V_69 ) {
case V_58 :
F_22 ( V_76 -> V_79 , V_76 -> V_79 + 10 ) ;
goto V_80;
case V_72 :
F_22 ( V_76 -> V_81 ,
V_76 -> V_81 + 10 ) ;
goto V_80;
default:
break;
}
break;
case V_70 :
switch ( V_57 -> V_69 ) {
case V_72 :
if ( ! V_77 ) {
F_22 ( V_76 -> V_82 + V_76 -> V_83 ,
V_76 -> V_82 + V_76 -> V_83 + 1000 ) ;
goto V_80;
}
break;
default:
break;
}
break;
case V_84 :
switch ( V_57 -> V_69 ) {
case V_78 :
F_22 ( V_76 -> V_85 , V_76 -> V_85 + 10 ) ;
goto V_80;
default:
break;
}
break;
default:
break;
}
F_23 ( 1 ) ;
V_80:
V_8 = F_16 ( V_2 , V_48 , V_57 ,
F_19 ) ;
if ( V_8 )
F_15 ( & V_2 -> V_59 -> V_10 , L_1 , V_8 ) ;
}
static void
F_24 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
T_1 * V_62 = V_57 -> V_62 ;
const T_1 V_68 = V_62 [ 1 ] & 0x1f ;
int V_8 ;
if ( V_68 == V_86 ) {
F_23 ( 1 ) ;
V_8 = F_16 ( V_2 , V_48 , V_57 ,
F_24 ) ;
if ( V_8 )
F_15 ( & V_2 -> V_59 -> V_10 , L_1 , V_8 ) ;
return;
}
if ( V_68 == V_57 -> V_69 ) {
if ( V_57 -> F_17 )
V_57 -> F_17 ( V_55 ) ;
return;
}
V_57 -> V_74 = V_68 ;
V_62 [ 0 ] = ( V_12 & V_63 ) | V_64 | V_87 ;
V_62 [ 1 ] = V_57 -> V_69 ;
V_57 -> V_65 . V_66 = 2 ;
V_57 -> V_67 . F_17 = F_21 ;
V_8 = F_18 ( V_2 -> V_59 , & V_57 -> V_67 ) ;
if ( V_8 )
F_15 ( & V_2 -> V_59 -> V_10 , L_1 , V_8 ) ;
}
static int
F_13 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
const T_1 V_88 , void (* F_17)( void * V_55 ) )
{
V_57 -> V_69 = V_88 ;
V_57 -> F_17 = F_17 ;
return F_16 ( V_2 , V_48 , V_57 ,
F_24 ) ;
}
static void
F_25 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_17 ( & V_2 -> V_89 ) ;
}
static int
F_26 ( struct V_1 * V_2 , unsigned int V_88 )
{
int V_8 ;
V_8 = F_13 ( V_2 , & V_2 -> V_88 , V_88 ,
F_25 ) ;
if ( V_8 ) {
F_14 ( V_2 , & V_2 -> V_88 , V_8 ) ;
return V_8 ;
}
V_8 = F_27 ( & V_2 -> V_89 ,
F_28 ( 100 ) ) ;
if ( ! V_8 )
return - V_90 ;
return 0 ;
}
static void
F_29 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_17 ( & V_2 -> V_91 ) ;
}
static void
F_30 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_8 ;
V_8 = F_13 ( V_2 , & V_2 -> V_92 , V_58 ,
F_29 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
}
static void
F_31 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_8 ;
V_8 = F_13 ( V_2 , V_57 , V_72 ,
F_30 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
}
static void
F_32 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_62 = V_57 -> V_62 ;
const T_1 V_93 = ( V_62 [ 1 ] & 0xe0 ) >> 5 ;
int V_8 ;
if ( V_93 ) {
V_8 = F_13 ( V_2 , V_57 , V_60 ,
F_31 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
return;
}
F_30 ( V_55 ) ;
}
static void
F_33 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_8 ;
V_8 = F_16 ( V_2 , V_12 , V_57 ,
F_32 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
}
static void
F_34 ( struct V_1 * V_2 ,
const T_1 * V_4 , T_1 V_66 )
{
T_1 V_94 ;
struct V_95 * V_96 ;
T_1 V_97 [ V_98 ] ;
if ( V_66 < 2 )
return;
if ( V_66 > V_99 ) {
V_94 = 0 ;
V_66 = V_99 ;
F_35 ( & V_2 -> V_59 -> V_10 , L_3 ) ;
} else {
V_94 = V_4 [ V_66 ] ;
}
memcpy ( V_97 , V_4 , V_66 ) ;
F_36 ( V_2 -> V_59 -> V_92 ) ;
V_96 = F_37 ( V_99 , V_100 ) ;
if ( ! V_96 ) {
F_35 ( & V_2 -> V_59 -> V_10 , L_4 ) ;
return;
}
memcpy ( F_38 ( V_96 , V_66 ) , V_97 , V_66 ) ;
F_39 ( V_96 , V_66 - 2 ) ;
F_40 ( V_2 -> V_10 , V_96 , V_94 ) ;
}
static void
F_41 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_62 = V_2 -> V_92 . V_62 ;
const T_1 V_66 = V_62 [ 1 ] ;
F_34 ( V_2 , V_62 + 2 , V_66 ) ;
}
static int
F_42 ( struct V_1 * V_2 )
{
T_1 * V_62 = V_2 -> V_92 . V_62 ;
V_62 [ 0 ] = V_101 ;
V_2 -> V_92 . V_65 . V_66 = V_98 ;
V_2 -> V_92 . V_67 . F_17 = F_41 ;
return F_18 ( V_2 -> V_59 , & V_2 -> V_92 . V_67 ) ;
}
static void
F_43 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_8 ;
V_8 = F_42 ( V_2 ) ;
if ( V_8 ) {
F_36 ( V_2 -> V_59 -> V_92 ) ;
F_14 ( V_2 , V_57 , V_8 ) ;
}
}
static int
F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_103 ) {
V_2 -> V_103 = 0 ;
F_46 ( & V_2 -> V_102 ) ;
F_36 ( V_2 -> V_59 -> V_92 ) ;
if ( V_2 -> V_104 )
return F_13 ( V_2 , & V_2 -> V_92 ,
V_73 ,
F_33 ) ;
else
return F_13 ( V_2 , & V_2 -> V_92 ,
V_58 ,
F_29 ) ;
} else {
F_46 ( & V_2 -> V_102 ) ;
return F_16 ( V_2 , V_12 , & V_2 -> V_92 ,
F_43 ) ;
}
}
static void
F_47 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
const T_1 * V_62 = V_2 -> V_92 . V_62 ;
const T_1 V_92 = V_62 [ 1 ] ;
int V_8 ;
if ( V_92 & V_105 ) {
V_8 = F_44 ( V_2 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
} else {
F_36 ( V_2 -> V_59 -> V_92 ) ;
F_15 ( & V_2 -> V_59 -> V_10 , L_5 ,
V_92 ) ;
}
}
static T_2 F_48 ( int V_92 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_56 * V_57 = & V_2 -> V_92 ;
T_1 * V_62 = V_57 -> V_62 ;
int V_8 ;
F_49 ( V_2 -> V_59 -> V_92 ) ;
V_62 [ 0 ] = ( V_50 & V_63 ) | V_64 ;
V_57 -> V_65 . V_66 = 2 ;
V_57 -> V_67 . F_17 = F_47 ;
V_8 = F_18 ( V_2 -> V_59 , & V_57 -> V_67 ) ;
if ( V_8 ) {
F_14 ( V_2 , V_57 , V_8 ) ;
return V_106 ;
}
return V_107 ;
}
static void
F_50 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
T_1 * V_62 = V_57 -> V_62 ;
int V_8 ;
V_62 [ 0 ] = ( V_12 & V_63 ) | V_64 | V_87 ;
V_62 [ 1 ] = V_108 ;
V_57 -> V_65 . V_66 = 2 ;
V_57 -> V_67 . F_17 = NULL ;
V_8 = F_18 ( V_2 -> V_59 , & V_57 -> V_67 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
}
static void
F_51 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_95 * V_96 = V_2 -> V_109 ;
T_1 * V_62 = V_2 -> V_110 . V_62 ;
int V_8 ;
F_45 ( & V_2 -> V_102 ) ;
V_2 -> V_103 = 1 ;
F_46 ( & V_2 -> V_102 ) ;
V_62 [ 0 ] = V_101 | V_87 ;
V_62 [ 1 ] = V_96 -> V_66 + 2 ;
memcpy ( V_62 + 2 , V_96 -> V_4 , V_96 -> V_66 ) ;
V_2 -> V_110 . V_65 . V_66 = V_96 -> V_66 + 2 ;
V_2 -> V_110 . V_67 . F_17 = F_50 ;
V_8 = F_18 ( V_2 -> V_59 , & V_2 -> V_110 . V_67 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
}
static void
F_52 ( void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_8 ;
V_8 = F_13 ( V_2 , V_57 , V_111 ,
F_51 ) ;
if ( V_8 )
F_14 ( V_2 , V_57 , V_8 ) ;
}
static int
F_53 ( struct V_112 * V_10 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
struct V_56 * V_57 = & V_2 -> V_110 ;
void (* V_91)( void * V_55 ) = F_51 ;
int V_8 ;
V_2 -> V_109 = V_96 ;
if ( V_2 -> V_104 )
V_91 = F_52 ;
V_8 = F_13 ( V_2 , V_57 , V_72 ,
V_91 ) ;
if ( V_8 ) {
F_14 ( V_2 , V_57 , V_8 ) ;
return V_8 ;
}
V_8 = F_54 ( & V_2 -> V_91 ,
F_28 ( V_2 -> V_4 -> V_114 ) ) ;
if ( ! V_8 ) {
F_14 ( V_2 , V_57 , V_8 ) ;
return - V_90 ;
}
if ( V_96 -> V_66 > 18 )
F_22 ( V_2 -> V_4 -> V_115 , V_2 -> V_4 -> V_115 + 10 ) ;
else
F_22 ( V_2 -> V_4 -> V_116 , V_2 -> V_4 -> V_116 + 10 ) ;
return 0 ;
}
static int
F_55 ( struct V_112 * V_10 , T_1 * V_117 )
{
F_56 () ;
F_57 ( ! V_117 ) ;
* V_117 = 0xbe ;
return 0 ;
}
static int
F_58 ( struct V_112 * V_10 )
{
return F_26 ( V_10 -> V_113 , V_58 ) ;
}
static void
F_59 ( struct V_112 * V_10 )
{
F_26 ( V_10 -> V_113 , V_60 ) ;
}
static int
F_60 ( struct V_1 * V_2 , int V_118 , int V_119 )
{
return F_6 ( V_2 , V_120 , V_119 ) ;
}
static int
F_61 ( struct V_1 * V_2 , int V_118 , int V_119 )
{
int V_8 ;
if ( V_119 == 0 )
V_8 = F_6 ( V_2 , V_121 , 0 ) ;
else
V_8 = F_6 ( V_2 , V_121 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_118 == 0 ) {
V_8 = F_6 ( V_2 , V_122 , 0 ) ;
V_2 -> V_4 -> V_123 = - 100 ;
} else {
V_8 = F_6 ( V_2 , V_122 , 1 ) ;
V_2 -> V_4 -> V_123 = - 98 ;
}
if ( V_8 < 0 )
return V_8 ;
return F_6 ( V_2 , V_120 , V_119 ) ;
}
static int
F_62 ( struct V_112 * V_10 , int V_118 , int V_119 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
int V_8 ;
F_56 () ;
if ( V_118 < 0 || V_118 > 31 ||
! ( V_2 -> V_10 -> V_124 -> V_125 [ V_118 ] & F_63 ( V_119 ) ) ) {
F_64 ( 1 ) ;
return - V_126 ;
}
V_8 = V_2 -> V_4 -> V_127 ( V_2 , V_118 , V_119 ) ;
if ( V_8 < 0 )
return V_8 ;
F_22 ( V_2 -> V_4 -> V_128 ,
V_2 -> V_4 -> V_128 + 10 ) ;
V_10 -> V_124 -> V_129 = V_119 ;
V_10 -> V_124 -> V_130 = V_118 ;
return 0 ;
}
static int
F_65 ( struct V_112 * V_10 ,
struct V_131 * V_132 ,
unsigned long V_133 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
if ( V_133 & V_134 ) {
T_3 V_3 = F_66 ( V_132 -> V_135 ) ;
F_35 ( & V_2 -> V_59 -> V_10 ,
L_6 ) ;
F_1 ( V_2 , V_32 , V_3 ) ;
F_1 ( V_2 , V_33 , V_3 >> 8 ) ;
}
if ( V_133 & V_136 ) {
T_3 V_137 = F_66 ( V_132 -> V_138 ) ;
F_35 ( & V_2 -> V_59 -> V_10 ,
L_7 ) ;
F_1 ( V_2 , V_34 , V_137 ) ;
F_1 ( V_2 , V_35 , V_137 >> 8 ) ;
}
if ( V_133 & V_139 ) {
T_1 V_140 , V_3 [ 8 ] ;
memcpy ( V_3 , & V_132 -> V_141 , 8 ) ;
F_35 ( & V_2 -> V_59 -> V_10 ,
L_8 ) ;
for ( V_140 = 0 ; V_140 < 8 ; V_140 ++ )
F_1 ( V_2 , V_36 + V_140 , V_3 [ V_140 ] ) ;
}
if ( V_133 & V_142 ) {
F_35 ( & V_2 -> V_59 -> V_10 ,
L_9 ) ;
if ( V_132 -> V_143 )
F_6 ( V_2 , V_144 , 1 ) ;
else
F_6 ( V_2 , V_144 , 0 ) ;
}
return 0 ;
}
static int
F_67 ( struct V_112 * V_10 , int V_145 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
if ( V_145 > 5 || V_145 < - 26 )
return - V_126 ;
V_145 = - ( V_145 - 5 ) ;
return F_1 ( V_2 , V_15 , 0x60 | V_145 ) ;
}
static int
F_68 ( struct V_112 * V_10 , bool V_146 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
return F_6 ( V_2 , V_147 , V_146 ) ;
}
static int
F_69 ( struct V_112 * V_10 , T_1 V_148 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
return F_6 ( V_2 , V_149 , V_148 ) ;
}
static int
F_70 ( struct V_1 * V_2 , T_4 V_117 )
{
return ( V_117 - V_2 -> V_4 -> V_123 ) * 100 / 207 ;
}
static int
F_71 ( struct V_1 * V_2 , T_4 V_117 )
{
return ( V_117 - V_2 -> V_4 -> V_123 ) / 2 ;
}
static int
F_72 ( struct V_112 * V_10 , T_4 V_117 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
if ( V_117 < V_2 -> V_4 -> V_123 || V_117 > 30 )
return - V_126 ;
return F_6 ( V_2 , V_150 ,
V_2 -> V_4 -> V_151 ( V_2 , V_117 ) ) ;
}
static int
F_73 ( struct V_112 * V_10 , T_1 V_152 , T_1 V_153 ,
T_1 V_154 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
int V_8 ;
if ( V_152 > V_153 || V_153 > 8 || V_154 > 5 )
return - V_126 ;
V_8 = F_6 ( V_2 , V_155 , V_152 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_156 , V_153 ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_2 , V_157 , V_154 ) ;
}
static int
F_74 ( struct V_112 * V_10 , T_5 V_154 )
{
struct V_1 * V_2 = V_10 -> V_113 ;
int V_8 = 0 ;
if ( V_154 < - 1 || V_154 > 15 )
return - V_126 ;
V_2 -> V_104 = V_154 >= 0 ;
if ( V_154 >= 0 )
V_8 = F_6 ( V_2 , V_158 , V_154 ) ;
return V_8 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_8 , V_159 , V_160 = V_161 ;
unsigned int V_162 ;
T_1 V_163 [ 2 ] ;
V_8 = F_26 ( V_2 , V_60 ) ;
if ( V_8 )
return V_8 ;
V_159 = F_76 ( V_2 -> V_59 -> V_92 ) ;
if ( V_159 == V_164 )
V_160 = V_165 ;
V_8 = F_6 ( V_2 , V_166 , V_160 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_167 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_168 , V_105 ) ;
if ( V_8 )
return V_8 ;
F_77 ( V_163 , F_78 ( V_163 ) ) ;
V_8 = F_6 ( V_2 , V_169 , V_163 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_170 , V_163 [ 1 ] ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_171 , 0x00 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_172 , 0x00 ) ;
if ( V_8 )
return V_8 ;
F_22 ( V_2 -> V_4 -> V_173 ,
V_2 -> V_4 -> V_173 + 100 ) ;
V_8 = F_5 ( V_2 , V_174 , & V_162 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_162 ) {
F_15 ( & V_2 -> V_59 -> V_10 , L_10 ) ;
return - V_126 ;
}
return 0 ;
}
static struct V_175 *
F_79 ( struct V_176 * V_59 )
{
struct V_175 * V_177 ;
if ( ! F_80 ( V_178 ) || ! V_59 -> V_10 . V_179 )
return V_59 -> V_10 . V_180 ;
V_177 = F_81 ( & V_59 -> V_10 , sizeof( * V_177 ) , V_181 ) ;
if ( ! V_177 )
goto V_71;
V_177 -> V_182 = F_82 ( V_59 -> V_10 . V_179 , L_11 , 0 ) ;
V_177 -> V_183 = F_82 ( V_59 -> V_10 . V_179 , L_12 , 0 ) ;
V_59 -> V_10 . V_180 = V_177 ;
V_71:
return V_177 ;
}
static int
F_83 ( struct V_1 * V_2 )
{
unsigned int V_184 , V_185 , V_186 ;
T_3 V_187 = 0 ;
const char * V_188 ;
int V_8 ;
V_8 = F_3 ( V_2 , V_54 , & V_186 ) ;
if ( V_8 )
return V_8 ;
V_187 |= V_186 ;
V_8 = F_3 ( V_2 , V_53 , & V_186 ) ;
if ( V_8 )
return V_8 ;
V_187 |= ( V_186 << 8 ) ;
V_8 = F_3 ( V_2 , V_51 , & V_184 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_3 ( V_2 , V_51 , & V_185 ) ;
if ( V_8 )
return V_8 ;
if ( V_187 != 0x001f ) {
F_15 ( & V_2 -> V_59 -> V_10 , L_13 ,
V_187 >> 8 , V_187 & 0xFF ) ;
return - V_126 ;
}
V_2 -> V_10 -> V_189 = 0 ;
V_2 -> V_10 -> V_190 = V_191 | V_192 |
V_193 | V_194 ;
switch ( V_184 ) {
case 2 :
V_188 = L_14 ;
V_8 = - V_195 ;
break;
case 3 :
V_188 = L_15 ;
V_2 -> V_4 = & V_196 ;
V_2 -> V_10 -> V_124 -> V_125 [ 0 ] = 0x7FFF800 ;
break;
case 7 :
V_188 = L_16 ;
if ( V_185 == 1 ) {
V_2 -> V_4 = & V_197 ;
V_2 -> V_10 -> V_190 |= V_198 ;
V_2 -> V_10 -> V_124 -> V_125 [ 0 ] = 0x00007FF ;
V_2 -> V_10 -> V_124 -> V_125 [ 2 ] = 0x00007FF ;
} else {
V_8 = - V_195 ;
}
break;
case 11 :
V_188 = L_17 ;
V_2 -> V_4 = & V_199 ;
V_2 -> V_10 -> V_124 -> V_125 [ 0 ] = 0x7FFF800 ;
break;
default:
V_188 = L_18 ;
V_8 = - V_195 ;
break;
}
F_84 ( & V_2 -> V_59 -> V_10 , L_19 , V_188 , V_185 ) ;
return V_8 ;
}
static void
F_85 ( struct V_1 * V_2 )
{
V_2 -> V_88 . V_2 = V_2 ;
F_86 ( & V_2 -> V_88 . V_67 ) ;
V_2 -> V_88 . V_67 . V_55 = & V_2 -> V_88 ;
V_2 -> V_88 . V_65 . V_61 = V_2 -> V_88 . V_62 ;
V_2 -> V_88 . V_65 . V_200 = V_2 -> V_88 . V_62 ;
F_87 ( & V_2 -> V_88 . V_65 , & V_2 -> V_88 . V_67 ) ;
V_2 -> V_92 . V_2 = V_2 ;
F_86 ( & V_2 -> V_92 . V_67 ) ;
V_2 -> V_92 . V_67 . V_55 = & V_2 -> V_92 ;
V_2 -> V_92 . V_65 . V_61 = V_2 -> V_92 . V_62 ;
V_2 -> V_92 . V_65 . V_200 = V_2 -> V_92 . V_62 ;
F_87 ( & V_2 -> V_92 . V_65 , & V_2 -> V_92 . V_67 ) ;
V_2 -> V_110 . V_2 = V_2 ;
F_86 ( & V_2 -> V_110 . V_67 ) ;
V_2 -> V_110 . V_67 . V_55 = & V_2 -> V_110 ;
V_2 -> V_110 . V_65 . V_61 = V_2 -> V_110 . V_62 ;
V_2 -> V_110 . V_65 . V_200 = V_2 -> V_110 . V_62 ;
F_87 ( & V_2 -> V_110 . V_65 , & V_2 -> V_110 . V_67 ) ;
}
static int F_88 ( struct V_176 * V_59 )
{
struct V_175 * V_177 ;
struct V_112 * V_10 ;
struct V_1 * V_2 ;
unsigned int V_201 ;
int V_8 , V_159 ;
if ( ! V_59 -> V_92 ) {
F_15 ( & V_59 -> V_10 , L_20 ) ;
return - V_126 ;
}
V_177 = F_79 ( V_59 ) ;
if ( ! V_177 ) {
F_15 ( & V_59 -> V_10 , L_21 ) ;
return - V_126 ;
}
if ( F_89 ( V_177 -> V_182 ) ) {
V_8 = F_90 ( & V_59 -> V_10 , V_177 -> V_182 ,
V_202 , L_22 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_89 ( V_177 -> V_183 ) ) {
V_8 = F_90 ( & V_59 -> V_10 , V_177 -> V_183 ,
V_203 , L_23 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_89 ( V_177 -> V_182 ) ) {
F_23 ( 1 ) ;
F_91 ( V_177 -> V_182 , 0 ) ;
F_23 ( 1 ) ;
F_91 ( V_177 -> V_182 , 1 ) ;
F_22 ( 120 , 240 ) ;
}
V_10 = F_92 ( sizeof( * V_2 ) , & V_204 ) ;
if ( ! V_10 )
return - V_205 ;
V_2 = V_10 -> V_113 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_59 = V_59 ;
V_10 -> V_206 = & V_59 -> V_10 ;
V_2 -> V_5 = F_93 ( V_59 , & V_207 ) ;
if ( F_94 ( V_2 -> V_5 ) ) {
V_8 = F_95 ( V_2 -> V_5 ) ;
F_15 ( & V_59 -> V_10 , L_24 ,
V_8 ) ;
goto V_208;
}
F_85 ( V_2 ) ;
V_8 = F_83 ( V_2 ) ;
if ( V_8 < 0 )
goto V_208;
F_96 ( & V_2 -> V_102 ) ;
F_97 ( & V_2 -> V_91 ) ;
F_97 ( & V_2 -> V_89 ) ;
F_98 ( V_59 , V_2 ) ;
V_8 = F_75 ( V_2 ) ;
if ( V_8 )
goto V_208;
V_8 = F_5 ( V_2 , V_50 , 0xff , 0 , & V_201 ) ;
if ( V_8 )
goto V_208;
V_159 = F_76 ( V_59 -> V_92 ) ;
if ( ! V_159 )
V_159 = V_209 ;
V_8 = F_99 ( & V_59 -> V_10 , V_59 -> V_92 , F_48 ,
V_210 | V_159 , F_100 ( & V_59 -> V_10 ) , V_2 ) ;
if ( V_8 )
goto V_208;
V_8 = F_101 ( V_2 -> V_10 ) ;
if ( V_8 )
goto V_208;
return V_8 ;
V_208:
F_102 ( V_2 -> V_10 ) ;
return V_8 ;
}
static int F_103 ( struct V_176 * V_59 )
{
struct V_1 * V_2 = F_104 ( V_59 ) ;
F_6 ( V_2 , V_168 , 0 ) ;
F_105 ( V_2 -> V_10 ) ;
F_102 ( V_2 -> V_10 ) ;
F_106 ( & V_59 -> V_10 , L_25 ) ;
return 0 ;
}
