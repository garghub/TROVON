static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
if ( V_2 -> V_4 & V_5 )
V_4 = 1 ;
else
V_4 = 0 ;
if ( V_2 -> V_4 & V_6 )
V_3 &= 0x7f ;
else
V_3 &= 0xff ;
V_4 = V_4 ^ ( F_2 ( V_3 ) & 1 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_1 ( V_2 , V_3 ) == ( ( V_3 >> 8 ) & 1 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( V_2 -> V_4 & V_6 )
* V_3 &= 0x7f ;
else
* V_3 &= 0xff ;
if ( V_2 -> V_4 & V_7 )
* V_3 |= F_1 ( V_2 , * V_3 ) << 8 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 && ! F_6 ( V_9 ) && ! V_2 -> V_10 )
F_7 ( V_2 -> V_11 , & V_2 -> V_12 ) ;
}
static void F_8 ( unsigned long V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
if ( V_2 -> V_14 . V_15 ) {
F_5 ( V_2 ) ;
F_9 ( & V_2 -> V_16 , V_17 + V_2 -> V_18 ) ;
}
}
static int F_10 ( struct V_1 * V_2 , T_1 V_19 , T_1 * V_20 )
{
struct V_21 V_22 ;
T_1 V_23 , V_24 ;
int V_25 ;
struct V_26 V_27 = {
. V_28 = & V_23 ,
. V_29 = & V_24 ,
. V_30 = 2 ,
} ;
V_23 = F_11 ( V_19 ) ;
F_12 ( & V_22 ) ;
F_13 ( & V_27 , & V_22 ) ;
V_25 = F_14 ( V_2 -> V_31 , & V_22 ) ;
if ( V_25 ) {
F_15 ( & V_2 -> V_31 -> V_32 , L_1 ) ;
return - V_33 ;
}
* V_20 = F_16 ( V_24 ) ;
V_2 -> V_34 = ( * V_20 & V_35 ) > 0 ;
F_17 ( & V_2 -> V_31 -> V_32 , L_2 , V_19 , * V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_20 )
{
unsigned int V_36 , V_37 , V_25 = 0 ;
int V_38 = 0 , V_39 ;
if ( V_20 & V_40 && V_2 -> V_41 ) {
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
V_36 = V_20 & ( V_2 -> V_4 & V_6 ? 0x7f : 0xff ) ;
if ( V_20 & V_43 ) {
V_2 -> V_14 . V_44 . V_45 ++ ;
V_37 = V_46 ;
V_25 |= V_47 ;
} else {
if ( V_2 -> V_4 & V_7 ) {
if ( F_3 ( V_2 , V_20 ) ) {
V_2 -> V_14 . V_44 . V_20 ++ ;
V_37 = V_48 ;
} else {
V_2 -> V_14 . V_44 . V_4 ++ ;
V_37 = V_49 ;
V_25 |= V_50 ;
}
} else {
V_2 -> V_14 . V_44 . V_20 ++ ;
V_37 = V_48 ;
}
}
F_19 ( & V_2 -> V_14 , V_25 , V_51 , V_36 , V_37 ) ;
V_38 = 1 ;
}
V_39 = ( V_20 & V_52 ) > 0 ;
if ( V_2 -> V_39 != V_39 ) {
V_2 -> V_39 = V_39 ;
F_20 ( & V_2 -> V_14 , V_39 ? V_53 : 0 ) ;
}
return V_38 ;
}
static void F_21 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 , struct V_1 , V_12 ) ;
int V_56 ;
T_1 V_19 , V_20 ;
int V_57 , V_58 , V_59 , V_60 ;
struct V_61 * V_62 = & V_2 -> V_14 . V_15 -> V_62 ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
V_56 = 0 ;
do {
F_23 ( & V_2 -> V_63 ) ;
V_57 = V_2 -> V_57 ;
V_58 = V_2 -> V_64 ;
V_2 -> V_64 = 0 ;
V_59 = V_2 -> V_59 ;
V_60 = V_2 -> V_65 ;
V_2 -> V_65 = 0 ;
F_24 ( & V_2 -> V_63 ) ;
if ( V_58 )
F_10 ( V_2 , V_66 | V_57 , & V_20 ) ;
if ( V_60 ) {
F_10 ( V_2 , V_67 | V_68 |
( V_2 -> V_59 ? V_69 : 0 ) , & V_20 ) ;
V_56 += F_18 ( V_2 , V_20 ) ;
}
F_10 ( V_2 , V_70 , & V_20 ) ;
V_56 += F_18 ( V_2 , V_20 ) ;
if ( V_20 & V_35 ) {
V_19 = 0xffff ;
if ( V_2 -> V_14 . V_71 ) {
V_19 = V_2 -> V_14 . V_71 ;
V_2 -> V_14 . V_44 . V_19 ++ ;
V_2 -> V_14 . V_71 = 0 ;
} else if ( ! F_25 ( V_62 ) &&
! F_26 ( & V_2 -> V_14 ) ) {
V_19 = V_62 -> V_72 [ V_62 -> V_73 ] ;
V_62 -> V_73 = ( V_62 -> V_73 + 1 ) &
( V_74 - 1 ) ;
V_2 -> V_14 . V_44 . V_19 ++ ;
}
if ( V_19 != 0xffff ) {
F_4 ( V_2 , & V_19 ) ;
V_19 |= V_67 | ( V_2 -> V_59 ? V_69 : 0 ) ;
F_10 ( V_2 , V_19 , & V_20 ) ;
V_56 += F_18 ( V_2 , V_20 ) ;
}
}
if ( V_56 > 16 ) {
F_27 ( & V_2 -> V_14 . V_15 -> V_14 ) ;
V_56 = 0 ;
}
if ( F_28 ( V_62 ) < V_75 )
F_29 ( & V_2 -> V_14 ) ;
} while ( ! V_2 -> V_8 &&
! F_6 ( V_9 ) &&
( ( V_20 & V_40 ) ||
( ! F_25 ( V_62 ) &&
! F_26 ( & V_2 -> V_14 ) ) ) );
if ( V_56 > 0 )
F_27 ( & V_2 -> V_14 . V_15 -> V_14 ) ;
}
static T_2 F_30 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
F_5 ( V_2 ) ;
return V_78 ;
}
static void F_31 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
if ( V_2 -> V_18 > 0 )
F_9 ( & V_2 -> V_16 , V_17 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
}
static void F_32 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
F_5 ( V_2 ) ;
}
static void F_33 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
V_2 -> V_41 = 0 ;
F_23 ( & V_2 -> V_63 ) ;
V_2 -> V_57 &= ~ V_80 ;
V_2 -> V_64 = 1 ;
F_24 ( & V_2 -> V_63 ) ;
F_5 ( V_2 ) ;
}
static unsigned int F_34 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
F_5 ( V_2 ) ;
return V_2 -> V_34 ;
}
static unsigned int F_35 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
F_5 ( V_2 ) ;
return ( V_2 -> V_39 ? V_53 : 0 ) | V_81 | V_82 ;
}
static void F_36 ( struct V_79 * V_14 , unsigned int V_83 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
int V_59 ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
V_59 = ( V_83 & V_84 ) > 0 ;
F_23 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_59 != V_59 ) {
V_2 -> V_59 = V_59 ;
V_2 -> V_65 = 1 ;
F_5 ( V_2 ) ;
}
F_24 ( & V_2 -> V_63 ) ;
}
static void
F_37 ( struct V_79 * V_14 , struct V_85 * V_86 ,
struct V_85 * V_87 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
int V_88 = 0 ;
unsigned V_89 ;
T_3 V_90 , V_91 , V_4 = 0 ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
V_89 = V_86 -> V_92 ;
V_90 = 0 ;
V_91 = 0 ;
V_88 = F_38 ( V_86 ) ;
V_90 = V_2 -> V_57 & V_93 ;
switch ( V_88 ) {
case 300 :
if ( V_2 -> V_94 )
V_88 = V_2 -> V_88 ;
else
V_90 = 15 ;
break;
case 600 :
V_90 = 14 + V_2 -> V_94 ;
break;
case 1200 :
V_90 = 13 + V_2 -> V_94 ;
break;
case 2400 :
V_90 = 12 + V_2 -> V_94 ;
break;
case 4800 :
V_90 = 11 + V_2 -> V_94 ;
break;
case 9600 :
V_90 = 10 + V_2 -> V_94 ;
break;
case 19200 :
V_90 = 9 + V_2 -> V_94 ;
break;
case 38400 :
V_90 = 8 + V_2 -> V_94 ;
break;
case 57600 :
V_90 = 1 + V_2 -> V_94 ;
break;
case 115200 :
V_90 = 0 + V_2 -> V_94 ;
break;
case 230400 :
if ( V_2 -> V_94 )
V_90 = 0 ;
else
V_88 = V_2 -> V_88 ;
break;
default:
V_88 = V_2 -> V_88 ;
}
F_39 ( V_86 , V_88 , V_88 ) ;
V_2 -> V_88 = V_88 ;
V_91 |= V_93 ;
if ( ( V_89 & V_95 ) == V_96 ) {
V_90 &= ~ V_97 ;
V_4 &= ~ V_6 ;
} else {
V_90 |= V_97 ;
V_4 |= V_6 ;
V_89 = ( V_89 & ~ V_95 ) | V_98 ;
}
V_91 |= V_97 ;
if ( V_89 & V_99 )
V_90 |= V_100 ;
else
V_90 &= ~ V_100 ;
V_91 |= V_100 ;
if ( V_89 & V_101 ) {
V_90 |= V_102 ;
V_4 |= V_7 ;
} else {
V_90 &= ~ V_102 ;
V_4 &= ~ V_7 ;
}
V_91 |= V_102 ;
if ( V_89 & V_103 )
V_4 |= V_5 ;
else
V_4 &= ~ V_5 ;
V_89 &= ~ V_104 ;
V_86 -> V_92 = V_89 ;
V_2 -> V_14 . V_105 = 0 ;
if ( V_86 -> V_106 & V_107 )
V_2 -> V_14 . V_105 |=
V_50 | V_47 |
V_51 ;
V_2 -> V_14 . V_15 -> V_14 . V_108 = 1 ;
if ( V_2 -> V_18 > 0 )
F_40 ( & V_2 -> V_16 ) ;
F_41 ( V_14 , V_86 -> V_92 , V_88 ) ;
F_23 ( & V_2 -> V_63 ) ;
V_2 -> V_57 = ( V_2 -> V_57 & ~ V_91 ) | ( V_90 & V_91 ) ;
V_2 -> V_64 = 1 ;
V_2 -> V_4 = V_4 ;
F_24 ( & V_2 -> V_63 ) ;
F_5 ( V_2 ) ;
if ( F_42 ( & V_2 -> V_14 , V_86 -> V_92 ) )
F_31 ( & V_2 -> V_14 ) ;
}
static void F_43 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
if ( V_2 -> V_10 )
return;
V_2 -> V_8 = 1 ;
if ( V_2 -> V_18 > 0 )
F_40 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_11 ) {
F_44 ( V_2 -> V_11 ) ;
F_45 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
if ( V_2 -> V_109 )
F_46 ( V_2 -> V_109 , V_2 ) ;
if ( V_2 -> V_110 )
V_2 -> V_110 ( 1 ) ;
else {
T_1 V_19 , V_20 ;
V_19 = V_66 | V_111 ;
F_10 ( V_2 , V_19 , & V_20 ) ;
}
}
static int F_47 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
char V_112 [ 12 ] ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
V_2 -> V_57 = V_80 ;
V_2 -> V_88 = V_2 -> V_94 ? 230400 : 115200 ;
V_2 -> V_41 = 1 ;
if ( V_2 -> V_10 )
return 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_59 = 0 ;
sprintf ( V_112 , L_4 , V_2 -> V_113 ) ;
V_2 -> V_11 = F_48 ( V_112 ) ;
if ( ! V_2 -> V_11 ) {
F_15 ( & V_2 -> V_31 -> V_32 , L_5 ) ;
return - V_114 ;
}
F_49 ( & V_2 -> V_12 , F_21 ) ;
if ( F_50 ( V_2 -> V_109 , F_30 ,
V_115 , L_6 , V_2 ) < 0 ) {
F_15 ( & V_2 -> V_31 -> V_32 , L_7 , V_2 -> V_109 ) ;
V_2 -> V_109 = 0 ;
F_45 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
return - V_114 ;
}
if ( V_2 -> V_116 ) {
T_1 V_19 , V_20 ;
V_19 = 0x4001 ;
F_10 ( V_2 , V_19 , & V_20 ) ;
}
if ( V_2 -> V_110 )
V_2 -> V_110 ( 0 ) ;
V_2 -> V_64 = 1 ;
F_5 ( V_2 ) ;
F_51 ( 50 ) ;
F_31 ( & V_2 -> V_14 ) ;
return 0 ;
}
static const char * F_52 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
return V_2 -> V_14 . type == V_117 ? L_8 : NULL ;
}
static void F_53 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
}
static void F_54 ( struct V_79 * V_14 , int V_118 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
if ( V_118 & V_119 )
V_2 -> V_14 . type = V_117 ;
}
static int F_55 ( struct V_79 * V_14 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
int V_38 = - V_122 ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
if ( V_121 -> type == V_123 || V_121 -> type == V_117 )
V_38 = 0 ;
return V_38 ;
}
static void F_56 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
}
static int F_57 ( struct V_79 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
return 0 ;
}
static void F_58 ( struct V_79 * V_14 , int V_124 )
{
struct V_1 * V_2 = F_22 ( V_14 ,
struct V_1 ,
V_14 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
}
static int F_59 ( struct V_125 * V_31 )
{
int V_126 , V_127 ;
struct V_128 * V_129 ;
T_1 V_19 , V_20 ;
F_60 ( & V_130 ) ;
if ( ! V_131 ) {
V_131 = 1 ;
V_127 = F_61 ( & V_132 ) ;
if ( V_127 ) {
F_62 ( V_133 L_9 ) ;
F_63 ( & V_130 ) ;
return V_127 ;
}
}
for ( V_126 = 0 ; V_126 < V_134 ; V_126 ++ )
if ( ! V_135 [ V_126 ] )
break;
if ( V_126 == V_134 ) {
F_15 ( & V_31 -> V_32 , L_10 ) ;
F_63 ( & V_130 ) ;
return - V_136 ;
}
V_135 [ V_126 ] = F_64 ( sizeof( struct V_1 ) , V_137 ) ;
if ( ! V_135 [ V_126 ] ) {
F_15 ( & V_31 -> V_32 ,
L_11 , V_126 ) ;
F_63 ( & V_130 ) ;
return - V_136 ;
}
V_135 [ V_126 ] -> V_31 = V_31 ;
V_135 [ V_126 ] -> V_109 = V_31 -> V_109 ;
F_65 ( & V_135 [ V_126 ] -> V_63 ) ;
F_66 ( V_31 , V_135 [ V_126 ] ) ;
V_129 = F_67 ( & V_31 -> V_32 ) ;
V_135 [ V_126 ] -> V_94 = V_129 -> V_94 ;
V_135 [ V_126 ] -> V_116 = V_129 -> V_116 ;
V_135 [ V_126 ] -> V_18 = F_68 ( V_129 -> V_18 ) ;
if ( V_129 -> V_18 > 0 && V_135 [ V_126 ] -> V_18 == 0 )
V_135 [ V_126 ] -> V_18 = 1 ;
V_135 [ V_126 ] -> V_110 = V_129 -> V_110 ;
V_135 [ V_126 ] -> V_113 = V_126 ;
F_69 ( & V_135 [ V_126 ] -> V_16 ) ;
V_135 [ V_126 ] -> V_16 . V_138 = F_8 ;
V_135 [ V_126 ] -> V_16 . V_13 = ( unsigned long ) V_135 [ V_126 ] ;
F_17 ( & V_31 -> V_32 , L_12 , V_42 , V_126 ) ;
V_135 [ V_126 ] -> V_14 . V_109 = V_135 [ V_126 ] -> V_109 ;
V_135 [ V_126 ] -> V_14 . V_139 = V_135 [ V_126 ] -> V_94 ? 3686400 : 1843200 ;
V_135 [ V_126 ] -> V_14 . V_140 = 16 ;
V_135 [ V_126 ] -> V_14 . V_141 = & V_142 ;
V_135 [ V_126 ] -> V_14 . V_118 = V_143 | V_144 ;
V_135 [ V_126 ] -> V_14 . line = V_126 ;
V_135 [ V_126 ] -> V_14 . type = V_117 ;
V_135 [ V_126 ] -> V_14 . V_32 = & V_31 -> V_32 ;
V_127 = F_70 ( & V_132 , & V_135 [ V_126 ] -> V_14 ) ;
if ( V_127 < 0 )
F_15 ( & V_31 -> V_32 ,
L_13 ,
V_126 , V_127 ) ;
if ( V_135 [ V_126 ] -> V_110 )
V_135 [ V_126 ] -> V_110 ( 1 ) ;
else {
V_19 = V_66 | V_111 ;
F_10 ( V_135 [ V_126 ] , V_19 , & V_20 ) ;
}
F_63 ( & V_130 ) ;
return 0 ;
}
static int F_71 ( struct V_125 * V_31 )
{
struct V_1 * V_2 = F_72 ( V_31 ) ;
int V_126 ;
F_60 ( & V_130 ) ;
for ( V_126 = 0 ; V_126 < V_134 ; V_126 ++ )
if ( V_135 [ V_126 ] == V_2 ) {
F_17 ( & V_31 -> V_32 , L_14 , V_42 , V_126 ) ;
F_73 ( & V_132 , & V_135 [ V_126 ] -> V_14 ) ;
F_74 ( V_135 [ V_126 ] ) ;
V_135 [ V_126 ] = NULL ;
break;
}
F_75 ( V_126 == V_134 ) ;
for ( V_126 = 0 ; V_126 < V_134 ; V_126 ++ )
if ( V_135 [ V_126 ] ) {
F_63 ( & V_130 ) ;
return 0 ;
}
F_76 ( L_15 ) ;
F_77 ( & V_132 ) ;
F_63 ( & V_130 ) ;
return 0 ;
}
static int F_78 ( struct V_145 * V_32 )
{
struct V_1 * V_2 = F_79 ( V_32 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
F_80 ( V_2 -> V_109 ) ;
V_2 -> V_10 = 1 ;
F_81 ( & V_132 , & V_2 -> V_14 ) ;
if ( V_2 -> V_110 )
V_2 -> V_110 ( 1 ) ;
else {
T_1 V_19 , V_20 ;
V_19 = V_66 | V_111 ;
F_10 ( V_2 , V_19 , & V_20 ) ;
}
return 0 ;
}
static int F_82 ( struct V_145 * V_32 )
{
struct V_1 * V_2 = F_79 ( V_32 ) ;
F_17 ( & V_2 -> V_31 -> V_32 , L_3 , V_42 ) ;
if ( V_2 -> V_110 )
V_2 -> V_110 ( 0 ) ;
F_83 ( & V_132 , & V_2 -> V_14 ) ;
V_2 -> V_10 = 0 ;
F_84 ( V_2 -> V_109 ) ;
V_2 -> V_64 = 1 ;
if ( V_2 -> V_11 )
F_5 ( V_2 ) ;
return 0 ;
}
