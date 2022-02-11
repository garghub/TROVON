static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) )
return 1 ;
if ( V_2 -> V_4 == 0x161F && V_2 -> V_5 == 0x2032 )
return 1 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 ) {
const struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 -> V_12 ) ;
T_1 V_13 ;
if ( F_1 ( V_2 ) )
return V_14 ;
if ( ( V_9 -> V_15 & V_16 ) && V_7 -> V_17 == 0 )
return V_18 ;
if ( V_9 -> V_19 < V_20 )
return V_21 ;
else if ( V_9 -> V_19 < V_22 )
return V_23 ;
F_5 ( V_2 , 0x50 , & V_13 ) ;
if ( V_13 & ( 0x10100000 >> ( 16 * V_7 -> V_17 ) ) )
return V_24 ;
if ( F_6 ( V_7 ) &&
F_7 ( V_7 , F_6 ( V_7 ) ) )
return V_24 ;
return V_21 ;
}
static int F_8 ( struct V_25 * V_26 , unsigned long V_27 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
const struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
if ( ! ( V_9 -> V_15 & V_28 ) ) {
static const struct V_29 V_30 [] = {
{ 0x40 , 1 , 0x02 , 0x02 } ,
{ 0x40 , 1 , 0x01 , 0x01 }
} ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 -> V_12 ) ;
if ( ! F_9 ( V_2 , & V_30 [ V_7 -> V_17 ] ) )
return - V_31 ;
}
return F_10 ( V_26 , V_27 ) ;
}
static void F_11 ( struct V_6 * V_7 , struct V_32 * V_33 ,
int V_34 , int V_35 , int V_36 )
{
struct V_1 * V_2 = F_4 ( V_7 -> V_10 -> V_12 ) ;
struct V_32 * V_37 = F_12 ( V_33 ) ;
struct V_38 V_39 , V_40 ;
static int V_41 = 33333 ;
unsigned long V_42 = 1000000000 / V_41 ;
unsigned long V_43 = V_42 ;
int V_44 ;
int V_45 = 3 - ( 2 * V_7 -> V_17 ) - V_33 -> V_46 ;
switch ( V_36 ) {
case V_20 :
V_43 = V_42 / 2 ; break;
case V_22 :
V_43 = V_42 / 3 ; break;
case V_47 :
V_43 = V_42 / 4 ; break;
}
F_13 ( V_33 , V_34 , & V_39 , V_42 , V_43 ) ;
if ( V_37 ) {
if ( V_37 -> V_48 ) {
F_13 ( V_37 , V_37 -> V_48 , & V_40 , V_42 , V_43 ) ;
F_14 ( & V_40 , & V_39 , & V_39 , V_49 ) ;
}
}
if ( V_35 ) {
T_2 V_50 ;
int V_51 = 2 * V_45 ;
F_15 ( V_2 , 0x4C , & V_50 ) ;
V_50 &= ~ ( 3 << V_51 ) ;
V_50 |= ( F_16 ( V_39 . V_50 , 1 , 4 ) - 1 ) << V_51 ;
F_17 ( V_2 , 0x4C , V_50 ) ;
}
F_17 ( V_2 , 0x4F - V_7 -> V_17 ,
( ( F_16 ( V_39 . V_52 , 1 , 16 ) - 1 ) << 4 ) | ( F_16 ( V_39 . V_53 , 1 , 16 ) - 1 ) ) ;
F_17 ( V_2 , 0x48 + V_45 ,
( ( F_16 ( V_39 . V_54 , 1 , 16 ) - 1 ) << 4 ) | ( F_16 ( V_39 . V_55 , 1 , 16 ) - 1 ) ) ;
switch ( V_36 ) {
case V_56 :
default:
V_44 = V_39 . V_57 ? ( 0xe0 | ( F_16 ( V_39 . V_57 , 2 , 5 ) - 2 ) ) : 0x03 ;
break;
case V_20 :
V_44 = V_39 . V_57 ? ( 0xe8 | ( F_16 ( V_39 . V_57 , 2 , 9 ) - 2 ) ) : 0x0f ;
break;
case V_22 :
V_44 = V_39 . V_57 ? ( 0xe0 | ( F_16 ( V_39 . V_57 , 2 , 9 ) - 2 ) ) : 0x07 ;
break;
case V_47 :
V_44 = V_39 . V_57 ? ( 0xe0 | ( F_16 ( V_39 . V_57 , 2 , 9 ) - 2 ) ) : 0x07 ;
break;
}
if ( V_36 ) {
T_2 V_58 ;
F_15 ( V_2 , 0x50 + V_45 , & V_58 ) ;
V_58 &= ~ 0x20 ;
if ( V_39 . V_57 ) {
V_58 &= 0x10 ;
V_58 |= V_44 ;
}
F_17 ( V_2 , 0x50 + V_45 , V_58 ) ;
}
}
static void F_18 ( struct V_6 * V_7 , struct V_32 * V_33 )
{
const struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
int V_35 = ( V_9 -> V_15 & V_59 ) ? 0 : 1 ;
F_11 ( V_7 , V_33 , V_33 -> V_48 , V_35 , V_9 -> V_19 ) ;
}
static void F_19 ( struct V_6 * V_7 , struct V_32 * V_33 )
{
const struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
int V_35 = ( V_9 -> V_15 & V_59 ) ? 0 : 1 ;
F_11 ( V_7 , V_33 , V_33 -> V_60 , V_35 , V_9 -> V_19 ) ;
}
static unsigned long F_20 ( struct V_32 * V_12 , unsigned long V_61 )
{
struct V_62 * V_10 = V_12 -> V_26 -> V_7 -> V_10 ;
const struct V_8 * V_9 = V_10 -> V_11 ;
unsigned char V_63 [ V_64 + 1 ] ;
if ( V_9 -> V_65 == V_66 ) {
F_21 ( V_12 -> V_65 , V_63 , V_67 , sizeof( V_63 ) ) ;
if ( strcmp ( V_63 , L_1 ) == 0 ) {
F_22 ( V_12 ,
L_2 ) ;
V_61 &= ~ V_68 ;
}
}
if ( V_12 -> V_69 == V_70 &&
F_2 ( V_71 ) ) {
F_22 ( V_12 , L_3 ) ;
V_61 &= V_72 ;
}
return V_61 ;
}
static void F_23 ( struct V_6 * V_7 , const struct V_73 * V_74 )
{
struct V_75 * V_76 = & V_7 -> V_76 ;
struct V_77 * V_78 = V_7 -> V_11 ;
unsigned int V_79 = V_74 -> V_15 & V_80 ;
int V_81 = 0 ;
if ( V_74 -> V_82 != V_7 -> V_83 ) {
F_24 ( V_74 -> V_82 , V_76 -> V_84 ) ;
V_7 -> V_83 = V_74 -> V_82 ;
F_25 ( V_7 ) ;
V_81 = 1 ;
}
if ( V_74 -> V_15 & V_85 ) {
F_24 ( V_74 -> V_86 , V_76 -> V_87 ) ;
V_78 -> V_88 = V_74 -> V_86 ;
} else if ( V_81 )
F_24 ( V_78 -> V_88 , V_76 -> V_87 ) ;
if ( V_79 && ( V_74 -> V_15 & V_89 ) ) {
F_26 ( ! V_76 -> V_84 ) ;
F_24 ( V_74 -> V_90 , V_76 -> V_91 ) ;
F_24 ( V_74 -> V_92 , V_76 -> V_93 ) ;
F_24 ( V_74 -> V_94 , V_76 -> V_95 ) ;
F_24 ( V_74 -> V_96 , V_76 -> V_97 ) ;
F_24 ( V_74 -> V_98 , V_76 -> V_99 ) ;
F_27 ( L_4 ,
V_74 -> V_90 ,
V_74 -> V_92 ,
V_74 -> V_94 ,
V_74 -> V_96 ,
V_74 -> V_98 ) ;
}
if ( V_79 ) {
F_24 ( V_74 -> V_100 , V_76 -> V_91 ) ;
F_24 ( V_74 -> V_101 , V_76 -> V_93 ) ;
F_24 ( V_74 -> V_102 , V_76 -> V_95 ) ;
F_24 ( V_74 -> V_103 , V_76 -> V_97 ) ;
F_24 ( V_74 -> V_104 , V_76 -> V_99 ) ;
F_27 ( L_5 ,
V_74 -> V_100 ,
V_74 -> V_101 ,
V_74 -> V_102 ,
V_74 -> V_103 ,
V_74 -> V_104 ) ;
}
F_25 ( V_7 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_77 * V_78 ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 -> V_12 ) ;
int V_105 = F_29 ( V_7 ) ;
if ( V_105 < 0 )
return V_105 ;
V_78 = F_30 ( & V_2 -> V_12 , sizeof( struct V_77 ) , V_106 ) ;
if ( V_78 == NULL )
return - V_107 ;
V_7 -> V_11 = V_78 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_15 )
{
T_2 V_108 ;
F_15 ( V_2 , 0x40 , & V_108 ) ;
V_108 &= 3 ;
if ( V_15 & V_109 ) {
static const T_2 V_110 [ 4 ] = { 0x00 , 0x60 , 0x00 , 0x20 } ;
T_2 V_111 ;
F_15 ( V_2 , 0x43 , & V_111 ) ;
if ( V_15 & V_112 )
V_111 &= 0x7F ;
else
V_111 &= 0x9f ;
V_111 |= V_110 [ V_108 ] ;
F_17 ( V_2 , 0x43 , V_111 ) ;
}
}
static int F_32 ( struct V_1 * V_2 , const struct V_113 * V_65 )
{
static const struct V_114 V_115 = {
. V_15 = V_116 ,
. V_117 = V_118 ,
. V_119 = V_120 ,
. V_121 = & V_122
} ;
static const struct V_114 V_123 = {
. V_15 = V_116 ,
. V_117 = V_118 ,
. V_119 = V_120 ,
. V_121 = & V_124 ,
} ;
static const struct V_114 V_125 = {
. V_15 = V_116 ,
. V_117 = V_118 ,
. V_119 = V_120 ,
. V_19 = V_56 ,
. V_121 = & V_122
} ;
static const struct V_114 V_126 = {
. V_15 = V_116 ,
. V_117 = V_118 ,
. V_119 = V_120 ,
. V_19 = V_20 ,
. V_121 = & V_122
} ;
static const struct V_114 V_127 = {
. V_15 = V_116 ,
. V_117 = V_118 ,
. V_119 = V_120 ,
. V_19 = V_22 ,
. V_121 = & V_122
} ;
static const struct V_114 V_128 = {
. V_15 = V_116 ,
. V_117 = V_118 ,
. V_119 = V_120 ,
. V_19 = V_47 ,
. V_121 = & V_122
} ;
const struct V_114 * V_129 [] = { NULL , NULL } ;
struct V_1 * V_130 ;
const struct V_8 * V_9 ;
T_2 V_108 ;
T_1 V_131 ;
unsigned long V_15 = V_65 -> V_132 ;
int V_133 ;
F_33 ( & V_2 -> V_12 , V_134 ) ;
V_133 = F_34 ( V_2 ) ;
if ( V_133 )
return V_133 ;
if ( V_15 & V_135 )
V_129 [ 1 ] = & V_136 ;
for ( V_9 = V_137 ; V_9 -> V_65 != V_138 ;
V_9 ++ )
if ( ( V_130 = F_35 ( V_139 +
! ! ( V_9 -> V_15 & V_140 ) ,
V_9 -> V_65 , NULL ) ) ) {
T_2 V_141 = V_130 -> V_142 ;
F_36 ( V_130 ) ;
if ( ( V_65 -> V_86 == 0x0415 || V_65 -> V_86 == 0x3164 ) &&
( V_9 -> V_65 != V_65 -> V_86 ) )
continue;
if ( V_141 >= V_9 -> V_143 && V_141 <= V_9 -> V_144 )
break;
}
if ( ! ( V_9 -> V_15 & V_28 ) ) {
F_15 ( V_2 , 0x40 , & V_108 ) ;
V_108 &= 3 ;
if ( V_108 == 0 )
return - V_145 ;
}
F_31 ( V_2 , V_9 -> V_15 ) ;
switch ( V_9 -> V_19 ) {
case 0x00 :
if ( V_9 -> V_15 & V_146 )
V_129 [ 0 ] = & V_123 ;
else
V_129 [ 0 ] = & V_115 ;
break;
case V_56 :
V_129 [ 0 ] = & V_125 ;
break;
case V_20 :
V_129 [ 0 ] = & V_126 ;
break;
case V_22 :
V_129 [ 0 ] = & V_127 ;
break;
case V_47 :
V_129 [ 0 ] = & V_128 ;
break;
default:
F_37 ( 1 ) ;
return - V_145 ;
}
if ( V_9 -> V_15 & V_147 ) {
F_5 ( V_2 , 0x50 , & V_131 ) ;
V_131 &= ~ 0x80008 ;
F_38 ( V_2 , 0x50 , V_131 ) ;
}
return F_39 ( V_2 , V_129 , & V_148 , ( void * ) V_9 , 0 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_131 ;
struct V_62 * V_10 = F_41 ( & V_2 -> V_12 ) ;
const struct V_8 * V_9 = V_10 -> V_11 ;
int V_133 ;
V_133 = F_42 ( V_2 ) ;
if ( V_133 )
return V_133 ;
F_31 ( V_2 , V_9 -> V_15 ) ;
if ( V_9 -> V_19 == V_20 ) {
F_5 ( V_2 , 0x50 , & V_131 ) ;
V_131 |= 0x80008 ;
F_38 ( V_2 , 0x50 , V_131 ) ;
}
if ( V_9 -> V_15 & V_147 ) {
F_5 ( V_2 , 0x50 , & V_131 ) ;
V_131 &= ~ 0x80008 ;
F_38 ( V_2 , 0x50 , V_131 ) ;
}
F_43 ( V_10 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_149 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_149 ) ;
}
