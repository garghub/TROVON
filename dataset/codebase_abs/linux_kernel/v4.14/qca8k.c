static void
F_1 ( T_1 V_1 , T_2 * V_2 , T_2 * V_3 , T_2 * V_4 )
{
V_1 >>= 1 ;
* V_2 = V_1 & 0x1e ;
V_1 >>= 5 ;
* V_3 = V_1 & 0x7 ;
V_1 >>= 3 ;
* V_4 = V_1 & 0x3ff ;
}
static T_1
F_2 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
T_1 V_9 ;
int V_10 ;
V_10 = V_6 -> V_11 ( V_6 , V_7 , V_8 ) ;
if ( V_10 >= 0 ) {
V_9 = V_10 ;
V_10 = V_6 -> V_11 ( V_6 , V_7 , V_8 + 1 ) ;
V_9 |= V_10 << 16 ;
}
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 ,
L_1 ) ;
return V_10 ;
}
return V_9 ;
}
static void
F_4 ( struct V_5 * V_6 , int V_7 , T_1 V_8 , T_1 V_9 )
{
T_2 V_13 , V_14 ;
int V_10 ;
V_13 = V_9 & 0xffff ;
V_14 = ( T_2 ) ( V_9 >> 16 ) ;
V_10 = V_6 -> V_15 ( V_6 , V_7 , V_8 , V_13 ) ;
if ( V_10 >= 0 )
V_10 = V_6 -> V_15 ( V_6 , V_7 , V_8 + 1 , V_14 ) ;
if ( V_10 < 0 )
F_3 ( & V_6 -> V_12 ,
L_2 ) ;
}
static void
F_5 ( struct V_5 * V_6 , T_2 V_4 )
{
if ( V_4 == V_16 )
return;
if ( V_6 -> V_15 ( V_6 , 0x18 , 0 , V_4 ) < 0 )
F_3 ( & V_6 -> V_12 ,
L_3 ) ;
V_16 = V_4 ;
}
static T_1
F_6 ( struct V_17 * V_18 , T_1 V_19 )
{
T_2 V_2 , V_3 , V_4 ;
T_1 V_9 ;
F_1 ( V_19 , & V_2 , & V_3 , & V_4 ) ;
F_7 ( & V_18 -> V_6 -> V_20 , V_21 ) ;
F_5 ( V_18 -> V_6 , V_4 ) ;
V_9 = F_2 ( V_18 -> V_6 , 0x10 | V_3 , V_2 ) ;
F_8 ( & V_18 -> V_6 -> V_20 ) ;
return V_9 ;
}
static void
F_9 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_9 )
{
T_2 V_2 , V_3 , V_4 ;
F_1 ( V_19 , & V_2 , & V_3 , & V_4 ) ;
F_7 ( & V_18 -> V_6 -> V_20 , V_21 ) ;
F_5 ( V_18 -> V_6 , V_4 ) ;
F_4 ( V_18 -> V_6 , 0x10 | V_3 , V_2 , V_9 ) ;
F_8 ( & V_18 -> V_6 -> V_20 ) ;
}
static T_1
F_10 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_22 , T_1 V_9 )
{
T_2 V_2 , V_3 , V_4 ;
T_1 V_10 ;
F_1 ( V_19 , & V_2 , & V_3 , & V_4 ) ;
F_7 ( & V_18 -> V_6 -> V_20 , V_21 ) ;
F_5 ( V_18 -> V_6 , V_4 ) ;
V_10 = F_2 ( V_18 -> V_6 , 0x10 | V_3 , V_2 ) ;
V_10 &= ~ V_22 ;
V_10 |= V_9 ;
F_4 ( V_18 -> V_6 , 0x10 | V_3 , V_2 , V_10 ) ;
F_8 ( & V_18 -> V_6 -> V_20 ) ;
return V_10 ;
}
static void
F_11 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_9 )
{
F_10 ( V_18 , V_19 , 0 , V_9 ) ;
}
static void
F_12 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_9 )
{
F_10 ( V_18 , V_19 , V_9 , 0 ) ;
}
static int
F_13 ( void * V_23 , T_3 V_19 , T_3 * V_9 )
{
struct V_17 * V_18 = (struct V_17 * ) V_23 ;
* V_9 = F_6 ( V_18 , V_19 ) ;
return 0 ;
}
static int
F_14 ( void * V_23 , T_3 V_19 , T_3 V_9 )
{
struct V_17 * V_18 = (struct V_17 * ) V_23 ;
F_9 ( V_18 , V_19 , V_9 ) ;
return 0 ;
}
static int
F_15 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_22 )
{
unsigned long V_24 ;
V_24 = V_25 + F_16 ( 20 ) ;
do {
T_1 V_9 = F_6 ( V_18 , V_19 ) ;
int V_26 = V_9 & V_22 ;
if ( ! V_26 )
break;
F_17 () ;
} while ( ! F_18 ( V_25 , V_24 ) );
return F_18 ( V_25 , V_24 ) ;
}
static void
F_19 ( struct V_17 * V_18 , struct V_27 * V_28 )
{
T_1 V_19 [ 4 ] ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ )
V_19 [ V_29 ] = F_6 ( V_18 , V_30 + ( V_29 * 4 ) ) ;
V_28 -> V_31 = ( V_19 [ 2 ] >> V_32 ) & V_33 ;
V_28 -> V_34 = V_19 [ 2 ] & V_35 ;
V_28 -> V_36 = ( V_19 [ 1 ] >> V_37 ) & V_38 ;
V_28 -> V_39 [ 0 ] = ( V_19 [ 1 ] >> V_40 ) & 0xff ;
V_28 -> V_39 [ 1 ] = V_19 [ 1 ] & 0xff ;
V_28 -> V_39 [ 2 ] = ( V_19 [ 0 ] >> V_41 ) & 0xff ;
V_28 -> V_39 [ 3 ] = ( V_19 [ 0 ] >> V_42 ) & 0xff ;
V_28 -> V_39 [ 4 ] = ( V_19 [ 0 ] >> V_43 ) & 0xff ;
V_28 -> V_39 [ 5 ] = V_19 [ 0 ] & 0xff ;
}
static void
F_20 ( struct V_17 * V_18 , T_2 V_31 , T_4 V_36 , const T_4 * V_39 ,
T_4 V_34 )
{
T_1 V_19 [ 3 ] = { 0 } ;
int V_29 ;
V_19 [ 2 ] = ( V_31 & V_33 ) << V_32 ;
V_19 [ 2 ] |= V_34 & V_35 ;
V_19 [ 1 ] = ( V_36 & V_38 ) << V_37 ;
V_19 [ 1 ] |= V_39 [ 0 ] << V_40 ;
V_19 [ 1 ] |= V_39 [ 1 ] ;
V_19 [ 0 ] |= V_39 [ 2 ] << V_41 ;
V_19 [ 0 ] |= V_39 [ 3 ] << V_42 ;
V_19 [ 0 ] |= V_39 [ 4 ] << V_43 ;
V_19 [ 0 ] |= V_39 [ 5 ] ;
for ( V_29 = 0 ; V_29 < 3 ; V_29 ++ )
F_9 ( V_18 , V_30 + ( V_29 * 4 ) , V_19 [ V_29 ] ) ;
}
static int
F_21 ( struct V_17 * V_18 , enum V_44 V_45 , int V_46 )
{
T_1 V_19 ;
V_19 = V_47 ;
V_19 |= V_45 ;
if ( V_46 >= 0 ) {
V_19 |= V_48 ;
V_19 |= ( V_46 & V_49 ) << V_50 ;
}
F_9 ( V_18 , V_51 , V_19 ) ;
if ( F_15 ( V_18 , V_51 , V_47 ) )
return - 1 ;
if ( V_45 == V_52 ) {
V_19 = F_6 ( V_18 , V_51 ) ;
if ( V_19 & V_53 )
return - 1 ;
}
return 0 ;
}
static int
F_22 ( struct V_17 * V_18 , struct V_27 * V_28 , int V_46 )
{
int V_10 ;
F_20 ( V_18 , V_28 -> V_31 , V_28 -> V_36 , V_28 -> V_39 , V_28 -> V_34 ) ;
V_10 = F_21 ( V_18 , V_54 , V_46 ) ;
if ( V_10 >= 0 )
F_19 ( V_18 , V_28 ) ;
return V_10 ;
}
static int
F_23 ( struct V_17 * V_18 , const T_4 * V_39 , T_2 V_36 ,
T_2 V_31 , T_4 V_34 )
{
int V_10 ;
F_24 ( & V_18 -> V_55 ) ;
F_20 ( V_18 , V_31 , V_36 , V_39 , V_34 ) ;
V_10 = F_21 ( V_18 , V_52 , - 1 ) ;
F_8 ( & V_18 -> V_55 ) ;
return V_10 ;
}
static int
F_25 ( struct V_17 * V_18 , const T_4 * V_39 , T_2 V_36 , T_2 V_31 )
{
int V_10 ;
F_24 ( & V_18 -> V_55 ) ;
F_20 ( V_18 , V_31 , V_36 , V_39 , 0 ) ;
V_10 = F_21 ( V_18 , V_56 , - 1 ) ;
F_8 ( & V_18 -> V_55 ) ;
return V_10 ;
}
static void
F_26 ( struct V_17 * V_18 )
{
F_24 ( & V_18 -> V_55 ) ;
F_21 ( V_18 , V_57 , - 1 ) ;
F_8 ( & V_18 -> V_55 ) ;
}
static void
F_27 ( struct V_17 * V_18 )
{
F_24 ( & V_18 -> V_55 ) ;
F_11 ( V_18 , V_58 , V_59 | V_60 ) ;
F_15 ( V_18 , V_58 , V_60 ) ;
F_11 ( V_18 , V_58 , V_61 ) ;
F_9 ( V_18 , V_62 , V_63 ) ;
F_8 ( & V_18 -> V_55 ) ;
}
static int
F_28 ( struct V_17 * V_18 , int V_46 , int V_64 )
{
T_1 V_19 ;
switch ( V_46 ) {
case 0 :
V_19 = V_65 ;
break;
case 6 :
V_19 = V_66 ;
break;
default:
F_29 ( L_4 , V_46 ) ;
return - V_67 ;
}
switch ( V_64 ) {
case V_68 :
F_9 ( V_18 , V_19 ,
V_69 |
F_30 ( 3 ) |
F_31 ( 3 ) ) ;
F_9 ( V_18 , V_70 ,
V_71 ) ;
break;
case V_72 :
F_9 ( V_18 , V_19 , V_73 ) ;
break;
default:
F_29 ( L_5 , V_64 ) ;
return - V_67 ;
}
return 0 ;
}
static void
F_32 ( struct V_17 * V_18 , int V_46 , int V_74 )
{
T_1 V_22 = V_75 ;
if ( ( V_46 > 0 ) && ( V_46 < 6 ) )
V_22 |= V_76 ;
if ( V_74 )
F_11 ( V_18 , F_33 ( V_46 ) , V_22 ) ;
else
F_12 ( V_18 , F_33 ( V_46 ) , V_22 ) ;
}
static int
F_34 ( struct V_77 * V_78 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
int V_10 , V_29 , V_79 = - 1 ;
if ( ! F_35 ( V_78 , 0 ) ) {
F_29 ( L_6 ) ;
return - V_67 ;
}
F_36 ( & V_18 -> V_55 ) ;
V_18 -> V_80 = F_37 ( V_78 -> V_12 , NULL , V_18 ,
& V_81 ) ;
if ( F_38 ( V_18 -> V_80 ) )
F_39 ( L_7 ) ;
V_79 = F_40 ( V_78 -> V_82 -> V_83 -> V_84 ) ;
if ( V_79 < 0 ) {
F_29 ( L_8 ) ;
return V_79 ;
}
V_10 = F_28 ( V_18 , V_85 , V_79 ) ;
if ( V_10 < 0 )
return V_10 ;
F_11 ( V_18 , V_86 ,
V_87 ) ;
F_32 ( V_18 , V_85 , 1 ) ;
V_18 -> V_88 [ V_85 ] . V_89 = 1 ;
F_27 ( V_18 ) ;
F_9 ( V_18 , F_41 ( V_85 ) ,
V_90 << V_91 |
V_90 << V_92 ) ;
for ( V_29 = 0 ; V_29 < V_93 ; V_29 ++ )
F_10 ( V_18 , F_42 ( V_29 ) ,
V_94 , 0 ) ;
for ( V_29 = 1 ; V_29 < V_93 ; V_29 ++ )
if ( V_78 -> V_95 & F_43 ( V_29 ) )
F_32 ( V_18 , V_29 , 0 ) ;
F_9 ( V_18 , V_96 ,
F_43 ( 0 ) << V_97 |
F_43 ( 0 ) << V_98 |
F_43 ( 0 ) << V_99 |
F_43 ( 0 ) << V_100 ) ;
for ( V_29 = 0 ; V_29 < V_101 ; V_29 ++ ) {
if ( F_35 ( V_78 , V_29 ) ) {
F_10 ( V_18 , F_42 ( V_85 ) ,
V_94 ,
V_78 -> V_95 ) ;
}
if ( V_78 -> V_95 & F_43 ( V_29 ) ) {
int V_102 = 16 * ( V_29 % 2 ) ;
F_10 ( V_18 , F_42 ( V_29 ) ,
V_94 ,
F_43 ( V_85 ) ) ;
F_11 ( V_18 , F_42 ( V_29 ) ,
V_103 ) ;
F_10 ( V_18 , F_44 ( V_29 ) ,
0xffff << V_102 , 1 << V_102 ) ;
F_9 ( V_18 , F_45 ( V_29 ) ,
F_46 ( 1 ) |
F_47 ( 1 ) ) ;
}
}
F_26 ( V_18 ) ;
return 0 ;
}
static int
F_48 ( struct V_77 * V_78 , int V_104 , int V_8 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
return F_49 ( V_18 -> V_6 , V_104 , V_8 ) ;
}
static int
F_50 ( struct V_77 * V_78 , int V_104 , int V_8 , T_2 V_9 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
return F_51 ( V_18 -> V_6 , V_104 , V_8 , V_9 ) ;
}
static void
F_52 ( struct V_77 * V_78 , int V_46 , T_5 * V_105 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_53 ( V_106 ) ; V_29 ++ )
strncpy ( V_105 + V_29 * V_107 , V_106 [ V_29 ] . V_108 ,
V_107 ) ;
}
static void
F_54 ( struct V_77 * V_78 , int V_46 ,
T_6 * V_105 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
const struct V_109 * V_110 ;
T_1 V_19 , V_29 ;
T_7 V_14 ;
for ( V_29 = 0 ; V_29 < F_53 ( V_106 ) ; V_29 ++ ) {
V_110 = & V_106 [ V_29 ] ;
V_19 = F_55 ( V_46 ) + V_110 -> V_111 ;
V_105 [ V_29 ] = F_6 ( V_18 , V_19 ) ;
if ( V_110 -> V_112 == 2 ) {
V_14 = F_6 ( V_18 , V_19 + 4 ) ;
V_105 [ V_29 ] |= V_14 << 32 ;
}
}
}
static int
F_56 ( struct V_77 * V_78 )
{
return F_53 ( V_106 ) ;
}
static int
F_57 ( struct V_77 * V_78 , int V_46 , struct V_113 * V_114 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
T_1 V_115 = F_58 ( V_46 ) ;
T_1 V_19 ;
F_24 ( & V_18 -> V_55 ) ;
V_19 = F_6 ( V_18 , V_116 ) ;
if ( V_114 -> V_117 )
V_19 |= V_115 ;
else
V_19 &= ~ V_115 ;
F_9 ( V_18 , V_116 , V_19 ) ;
F_8 ( & V_18 -> V_55 ) ;
return 0 ;
}
static int
F_59 ( struct V_77 * V_78 , int V_46 , struct V_113 * V_118 )
{
return 0 ;
}
static void
F_60 ( struct V_77 * V_78 , int V_46 , T_4 V_119 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
T_1 V_120 ;
switch ( V_119 ) {
case V_121 :
V_120 = V_122 ;
break;
case V_123 :
V_120 = V_124 ;
break;
case V_125 :
V_120 = V_126 ;
break;
case V_127 :
V_120 = V_128 ;
break;
case V_129 :
default:
V_120 = V_130 ;
break;
}
F_10 ( V_18 , F_42 ( V_46 ) ,
V_131 , V_120 ) ;
}
static int
F_61 ( struct V_77 * V_78 , int V_46 , struct V_132 * V_133 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
int V_36 = F_43 ( V_85 ) ;
int V_29 ;
for ( V_29 = 1 ; V_29 < V_93 ; V_29 ++ ) {
if ( V_78 -> V_134 [ V_29 ] . V_135 != V_133 )
continue;
F_11 ( V_18 ,
F_42 ( V_29 ) ,
F_43 ( V_46 ) ) ;
if ( V_29 != V_46 )
V_36 |= F_43 ( V_29 ) ;
}
F_10 ( V_18 , F_42 ( V_46 ) ,
V_94 , V_36 ) ;
return 0 ;
}
static void
F_62 ( struct V_77 * V_78 , int V_46 , struct V_132 * V_133 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
int V_29 ;
for ( V_29 = 1 ; V_29 < V_93 ; V_29 ++ ) {
if ( V_78 -> V_134 [ V_29 ] . V_135 != V_133 )
continue;
F_12 ( V_18 ,
F_42 ( V_29 ) ,
F_43 ( V_46 ) ) ;
}
F_10 ( V_18 , F_42 ( V_46 ) ,
V_94 , F_43 ( V_85 ) ) ;
}
static int
F_63 ( struct V_77 * V_78 , int V_46 ,
struct V_136 * V_104 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
F_32 ( V_18 , V_46 , 1 ) ;
V_18 -> V_88 [ V_46 ] . V_89 = 1 ;
return 0 ;
}
static void
F_64 ( struct V_77 * V_78 , int V_46 ,
struct V_136 * V_104 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
F_32 ( V_18 , V_46 , 0 ) ;
V_18 -> V_88 [ V_46 ] . V_89 = 0 ;
}
static int
F_65 ( struct V_17 * V_18 , const T_4 * V_137 ,
T_2 V_36 , T_2 V_31 )
{
if ( ! V_31 )
V_31 = 1 ;
return F_23 ( V_18 , V_137 , V_36 , V_31 ,
V_138 ) ;
}
static int
F_66 ( struct V_77 * V_78 , int V_46 ,
const unsigned char * V_137 , T_2 V_31 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
T_2 V_36 = F_43 ( V_46 ) ;
return F_65 ( V_18 , V_137 , V_36 , V_31 ) ;
}
static int
F_67 ( struct V_77 * V_78 , int V_46 ,
const unsigned char * V_137 , T_2 V_31 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
T_2 V_36 = F_43 ( V_46 ) ;
if ( ! V_31 )
V_31 = 1 ;
return F_25 ( V_18 , V_137 , V_36 , V_31 ) ;
}
static int
F_68 ( struct V_77 * V_78 , int V_46 ,
T_8 * V_139 , void * V_105 )
{
struct V_17 * V_18 = (struct V_17 * ) V_78 -> V_18 ;
struct V_27 V_140 = { 0 } ;
int V_141 = V_142 ;
bool V_143 ;
int V_10 = 0 ;
F_24 ( & V_18 -> V_55 ) ;
while ( V_141 -- && ! F_22 ( V_18 , & V_140 , V_46 ) ) {
if ( ! V_140 . V_34 )
break;
V_143 = ( V_140 . V_34 == V_138 ) ;
V_10 = V_139 ( V_140 . V_39 , V_140 . V_31 , V_143 , V_105 ) ;
if ( V_10 )
break;
}
F_8 ( & V_18 -> V_55 ) ;
return 0 ;
}
static enum V_144
F_69 ( struct V_77 * V_78 )
{
return V_145 ;
}
static int
F_70 ( struct V_146 * V_147 )
{
struct V_17 * V_18 ;
T_1 V_148 ;
V_18 = F_71 ( & V_147 -> V_12 , sizeof( * V_18 ) , V_149 ) ;
if ( ! V_18 )
return - V_150 ;
V_18 -> V_6 = V_147 -> V_6 ;
V_148 = F_6 ( V_18 , V_151 ) ;
V_148 >>= V_152 ;
V_148 &= V_153 ;
if ( V_148 != V_154 )
return - V_155 ;
V_18 -> V_78 = F_72 ( & V_147 -> V_12 , V_101 ) ;
if ( ! V_18 -> V_78 )
return - V_150 ;
V_18 -> V_78 -> V_18 = V_18 ;
V_18 -> V_78 -> V_156 = & V_157 ;
F_36 ( & V_18 -> V_55 ) ;
F_73 ( & V_147 -> V_12 , V_18 ) ;
return F_74 ( V_18 -> V_78 ) ;
}
static void
F_75 ( struct V_146 * V_147 )
{
struct V_17 * V_18 = F_76 ( & V_147 -> V_12 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_93 ; V_29 ++ )
F_32 ( V_18 , V_29 , 0 ) ;
F_77 ( V_18 -> V_78 ) ;
}
static void
F_78 ( struct V_17 * V_18 , int V_74 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_93 ; V_29 ++ ) {
if ( ! V_18 -> V_88 [ V_29 ] . V_89 )
continue;
F_32 ( V_18 , V_29 , V_74 ) ;
}
}
static int F_79 ( struct V_158 * V_12 )
{
struct V_159 * V_160 = F_80 ( V_12 ) ;
struct V_17 * V_18 = F_81 ( V_160 ) ;
F_78 ( V_18 , 0 ) ;
return F_82 ( V_18 -> V_78 ) ;
}
static int F_83 ( struct V_158 * V_12 )
{
struct V_159 * V_160 = F_80 ( V_12 ) ;
struct V_17 * V_18 = F_81 ( V_160 ) ;
F_78 ( V_18 , 1 ) ;
return F_84 ( V_18 -> V_78 ) ;
}
