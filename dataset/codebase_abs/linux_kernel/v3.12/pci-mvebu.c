static bool F_1 ( struct V_1 * V_2 )
{
return ! ( F_2 ( V_2 -> V_3 + V_4 ) & V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
V_7 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_7 &= ~ V_8 ;
V_7 |= V_6 << 8 ;
F_4 ( V_7 , V_2 -> V_3 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
V_7 = F_2 ( V_2 -> V_3 + V_4 ) ;
V_7 &= ~ V_9 ;
V_7 |= V_6 << 16 ;
F_4 ( V_7 , V_2 -> V_3 + V_4 ) ;
}
static void T_2 F_6 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 ;
T_1 V_12 ;
int V_13 ;
V_11 = F_7 () ;
for ( V_13 = 1 ; V_13 < 3 ; V_13 ++ ) {
F_4 ( 0 , V_2 -> V_3 + F_8 ( V_13 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_9 ( V_13 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_10 ( V_13 ) ) ;
}
for ( V_13 = 0 ; V_13 < 5 ; V_13 ++ ) {
F_4 ( 0 , V_2 -> V_3 + F_11 ( V_13 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_12 ( V_13 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_13 ( V_13 ) ) ;
}
F_4 ( 0 , V_2 -> V_3 + V_14 ) ;
F_4 ( 0 , V_2 -> V_3 + V_15 ) ;
F_4 ( 0 , V_2 -> V_3 + V_16 ) ;
V_12 = 0 ;
for ( V_13 = 0 ; V_13 < V_11 -> V_17 ; V_13 ++ ) {
const struct V_18 * V_19 = V_11 -> V_19 + V_13 ;
F_4 ( V_19 -> V_3 & 0xffff0000 ,
V_2 -> V_3 + F_12 ( V_13 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_13 ( V_13 ) ) ;
F_4 ( ( ( V_19 -> V_12 - 1 ) & 0xffff0000 ) |
( V_19 -> V_20 << 8 ) |
( V_11 -> V_21 << 4 ) | 1 ,
V_2 -> V_3 + F_11 ( V_13 ) ) ;
V_12 += V_19 -> V_12 ;
}
if ( ( V_12 & ( V_12 - 1 ) ) != 0 )
V_12 = 1 << F_14 ( V_12 ) ;
F_4 ( V_11 -> V_19 [ 0 ] . V_3 , V_2 -> V_3 + F_9 ( 1 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_10 ( 1 ) ) ;
F_4 ( ( ( V_12 - 1 ) & 0xffff0000 ) | 1 ,
V_2 -> V_3 + F_8 ( 1 ) ) ;
}
static void T_2 F_15 ( struct V_1 * V_2 )
{
T_3 V_22 ;
T_1 V_23 ;
F_6 ( V_2 ) ;
V_22 = F_16 ( V_2 -> V_3 + V_24 ) ;
V_22 |= V_25 ;
V_22 |= V_26 ;
V_22 |= V_27 ;
F_17 ( V_22 , V_2 -> V_3 + V_24 ) ;
V_23 = F_2 ( V_2 -> V_3 + V_28 ) ;
V_23 |= V_29 ;
F_4 ( V_23 , V_2 -> V_3 + V_28 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
T_1 V_32 , int V_33 , int V_12 , T_1 * V_34 )
{
F_4 ( F_19 ( V_31 -> V_35 , V_32 , V_33 ) ,
V_2 -> V_3 + V_36 ) ;
* V_34 = F_2 ( V_2 -> V_3 + V_37 ) ;
if ( V_12 == 1 )
* V_34 = ( * V_34 >> ( 8 * ( V_33 & 3 ) ) ) & 0xff ;
else if ( V_12 == 2 )
* V_34 = ( * V_34 >> ( 8 * ( V_33 & 3 ) ) ) & 0xffff ;
return V_38 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
T_1 V_32 , int V_33 , int V_12 , T_1 V_34 )
{
int V_39 = V_38 ;
F_4 ( F_19 ( V_31 -> V_35 , V_32 , V_33 ) ,
V_2 -> V_3 + V_36 ) ;
if ( V_12 == 4 )
F_4 ( V_34 , V_2 -> V_3 + V_37 ) ;
else if ( V_12 == 2 )
F_17 ( V_34 , V_2 -> V_3 + V_37 + ( V_33 & 3 ) ) ;
else if ( V_12 == 1 )
F_21 ( V_34 , V_2 -> V_3 + V_37 + ( V_33 & 3 ) ) ;
else
V_39 = V_40 ;
return V_39 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_4 V_41 ;
if ( V_2 -> V_42 . V_43 < V_2 -> V_42 . V_41 ||
V_2 -> V_42 . V_44 < V_2 -> V_42 . V_45 ) {
if ( V_2 -> V_46 ) {
F_23 ( V_2 -> V_46 ,
V_2 -> V_47 ) ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
}
return;
}
V_41 = ( ( V_2 -> V_42 . V_41 & 0xF0 ) << 8 ) |
( V_2 -> V_42 . V_45 << 16 ) ;
V_2 -> V_46 = V_2 -> V_48 -> V_49 . V_50 + V_41 ;
V_2 -> V_47 = ( ( 0xFFF | ( ( V_2 -> V_42 . V_43 & 0xF0 ) << 8 ) |
( V_2 -> V_42 . V_44 << 16 ) ) -
V_41 ) ;
F_24 ( V_2 -> V_51 , V_2 -> V_52 ,
V_2 -> V_46 , V_2 -> V_47 ,
V_41 ) ;
F_25 ( V_41 , V_2 -> V_46 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 . V_53 < V_2 -> V_42 . V_54 ) {
if ( V_2 -> V_55 ) {
F_23 ( V_2 -> V_55 ,
V_2 -> V_56 ) ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
}
return;
}
V_2 -> V_55 = ( ( V_2 -> V_42 . V_54 & 0xFFF0 ) << 16 ) ;
V_2 -> V_56 =
( ( ( V_2 -> V_42 . V_53 & 0xFFF0 ) << 16 ) | 0xFFFFF ) -
V_2 -> V_55 ;
F_27 ( V_2 -> V_57 , V_2 -> V_58 ,
V_2 -> V_55 , V_2 -> V_56 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_59 * V_42 = & V_2 -> V_42 ;
memset ( V_42 , 0 , sizeof( struct V_59 ) ) ;
V_42 -> V_60 = V_61 ;
V_42 -> V_62 = V_63 ;
V_42 -> V_64 = V_65 ;
V_42 -> V_66 = V_67 ;
V_42 -> V_68 = 0x10 ;
V_42 -> V_41 = V_69 ;
V_42 -> V_43 = V_69 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_33 , int V_12 , T_1 * V_70 )
{
struct V_59 * V_42 = & V_2 -> V_42 ;
switch ( V_33 & ~ 3 ) {
case V_71 :
* V_70 = V_42 -> V_64 << 16 | V_42 -> V_62 ;
break;
case V_72 :
* V_70 = V_42 -> V_73 ;
break;
case V_74 :
* V_70 = V_42 -> V_60 << 16 | V_42 -> V_75 << 8 |
V_42 -> V_76 ;
break;
case V_77 :
* V_70 = V_42 -> V_78 << 24 | V_42 -> V_66 << 16 |
V_42 -> V_79 << 8 | V_42 -> V_68 ;
break;
case V_80 ... V_81 :
* V_70 = V_42 -> V_82 [ ( ( V_33 & ~ 3 ) - V_80 ) / 4 ] ;
break;
case V_83 :
* V_70 = ( V_42 -> V_84 << 24 |
V_42 -> V_85 << 16 |
V_42 -> V_86 << 8 |
V_42 -> V_87 ) ;
break;
case V_88 :
* V_70 = ( V_42 -> V_89 << 16 |
V_42 -> V_43 << 8 |
V_42 -> V_41 ) ;
break;
case V_90 :
* V_70 = ( V_42 -> V_53 << 16 | V_42 -> V_54 ) ;
break;
case V_91 :
* V_70 = 0 ;
break;
case V_92 :
* V_70 = ( V_42 -> V_44 << 16 | V_42 -> V_45 ) ;
break;
case V_93 :
* V_70 = 0 ;
break;
default:
* V_70 = 0xffffffff ;
return V_40 ;
}
if ( V_12 == 2 )
* V_70 = ( * V_70 >> ( 8 * ( V_33 & 3 ) ) ) & 0xffff ;
else if ( V_12 == 1 )
* V_70 = ( * V_70 >> ( 8 * ( V_33 & 3 ) ) ) & 0xff ;
return V_38 ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned int V_33 , int V_12 , T_1 V_70 )
{
struct V_59 * V_42 = & V_2 -> V_42 ;
T_1 V_23 , V_94 ;
int V_95 ;
if ( V_12 == 4 )
V_23 = 0x0 ;
else if ( V_12 == 2 )
V_23 = ~ ( 0xffff << ( ( V_33 & 3 ) * 8 ) ) ;
else if ( V_12 == 1 )
V_23 = ~ ( 0xff << ( ( V_33 & 3 ) * 8 ) ) ;
else
return V_40 ;
V_95 = F_29 ( V_2 , V_33 & ~ 3 , 4 , & V_94 ) ;
if ( V_95 )
return V_95 ;
V_70 = ( V_94 & V_23 ) | V_70 << ( ( V_33 & 3 ) * 8 ) ;
switch ( V_33 & ~ 3 ) {
case V_72 :
V_42 -> V_73 = V_70 & 0xffff ;
break;
case V_80 ... V_81 :
V_42 -> V_82 [ ( ( V_33 & ~ 3 ) - V_80 ) / 4 ] = V_70 ;
break;
case V_88 :
V_42 -> V_41 = ( V_70 & 0xff ) | V_69 ;
V_42 -> V_43 = ( ( V_70 >> 8 ) & 0xff ) | V_69 ;
V_42 -> V_89 = V_70 >> 16 ;
F_22 ( V_2 ) ;
break;
case V_90 :
V_42 -> V_54 = V_70 & 0xffff ;
V_42 -> V_53 = V_70 >> 16 ;
F_26 ( V_2 ) ;
break;
case V_92 :
V_42 -> V_45 = V_70 & 0xffff ;
V_42 -> V_44 = V_70 >> 16 ;
F_22 ( V_2 ) ;
break;
case V_83 :
V_42 -> V_87 = V_70 & 0xff ;
V_42 -> V_86 = ( V_70 >> 8 ) & 0xff ;
V_42 -> V_85 = ( V_70 >> 16 ) & 0xff ;
V_42 -> V_84 = ( V_70 >> 24 ) & 0xff ;
F_3 ( V_2 , V_42 -> V_86 ) ;
break;
default:
break;
}
return V_38 ;
}
static inline struct V_96 * F_31 ( struct V_97 * V_98 )
{
return V_98 -> V_99 ;
}
static struct V_1 *
F_32 ( struct V_96 * V_48 , struct V_30 * V_31 ,
int V_32 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_48 -> V_100 ; V_13 ++ ) {
struct V_1 * V_2 = & V_48 -> V_101 [ V_13 ] ;
if ( V_31 -> V_35 == 0 && V_2 -> V_32 == V_32 )
return V_2 ;
if ( V_31 -> V_35 != 0 &&
V_31 -> V_35 >= V_2 -> V_42 . V_86 &&
V_31 -> V_35 <= V_2 -> V_42 . V_85 )
return V_2 ;
}
return NULL ;
}
static int F_33 ( struct V_30 * V_31 , T_1 V_32 ,
int V_33 , int V_12 , T_1 V_34 )
{
struct V_96 * V_48 = F_31 ( V_31 -> V_102 ) ;
struct V_1 * V_2 ;
unsigned long V_103 ;
int V_39 ;
V_2 = F_32 ( V_48 , V_31 , V_32 ) ;
if ( ! V_2 )
return V_104 ;
if ( V_31 -> V_35 == 0 )
return F_30 ( V_2 , V_33 , V_12 , V_34 ) ;
if ( ! V_2 -> V_105 )
return V_104 ;
if ( V_31 -> V_35 == V_2 -> V_42 . V_86 &&
F_34 ( V_32 ) != 0 )
return V_104 ;
F_35 ( & V_2 -> V_106 , V_103 ) ;
V_39 = F_20 ( V_2 , V_31 , V_32 ,
V_33 , V_12 , V_34 ) ;
F_36 ( & V_2 -> V_106 , V_103 ) ;
return V_39 ;
}
static int F_37 ( struct V_30 * V_31 , T_1 V_32 , int V_33 ,
int V_12 , T_1 * V_34 )
{
struct V_96 * V_48 = F_31 ( V_31 -> V_102 ) ;
struct V_1 * V_2 ;
unsigned long V_103 ;
int V_39 ;
V_2 = F_32 ( V_48 , V_31 , V_32 ) ;
if ( ! V_2 ) {
* V_34 = 0xffffffff ;
return V_104 ;
}
if ( V_31 -> V_35 == 0 )
return F_29 ( V_2 , V_33 , V_12 , V_34 ) ;
if ( ! V_2 -> V_105 ) {
* V_34 = 0xffffffff ;
return V_104 ;
}
if ( V_31 -> V_35 == V_2 -> V_42 . V_86 &&
F_34 ( V_32 ) != 0 ) {
* V_34 = 0xffffffff ;
return V_104 ;
}
F_35 ( & V_2 -> V_106 , V_103 ) ;
V_39 = F_18 ( V_2 , V_31 , V_32 ,
V_33 , V_12 , V_34 ) ;
F_36 ( & V_2 -> V_106 , V_103 ) ;
return V_39 ;
}
static int T_2 F_38 ( int V_6 , struct V_97 * V_98 )
{
struct V_96 * V_48 = F_31 ( V_98 ) ;
int V_13 ;
F_39 ( & V_98 -> V_107 , & V_48 -> V_108 , V_98 -> V_109 ) ;
F_39 ( & V_98 -> V_107 , & V_48 -> V_110 , V_98 -> V_111 ) ;
F_40 ( & V_98 -> V_107 , & V_48 -> V_112 ) ;
for ( V_13 = 0 ; V_13 < V_48 -> V_100 ; V_13 ++ ) {
struct V_1 * V_2 = & V_48 -> V_101 [ V_13 ] ;
if ( ! V_2 -> V_3 )
continue;
F_15 ( V_2 ) ;
}
return 1 ;
}
static int T_2 F_41 ( const struct V_113 * V_114 , T_5 V_115 , T_5 V_116 )
{
struct V_117 V_118 ;
int V_39 ;
V_39 = F_42 ( V_114 , & V_118 ) ;
if ( V_39 )
return V_39 ;
return F_43 ( V_118 . V_119 , V_118 . V_120 ,
V_118 . V_12 ) ;
}
static struct V_30 * F_44 ( int V_6 , struct V_97 * V_98 )
{
struct V_96 * V_48 = F_31 ( V_98 ) ;
struct V_30 * V_31 ;
V_31 = F_45 ( & V_48 -> V_121 -> V_114 , V_98 -> V_122 ,
& V_123 , V_98 , & V_98 -> V_107 ) ;
if ( ! V_31 )
return NULL ;
F_46 ( V_31 ) ;
return V_31 ;
}
T_6 F_47 ( struct V_113 * V_114 ,
const struct V_124 * V_125 ,
T_6 V_50 ,
T_6 V_12 ,
T_6 V_126 )
{
if ( V_114 -> V_31 -> V_35 != 0 )
return V_50 ;
if ( V_125 -> V_103 & V_127 )
return F_48 ( V_50 , F_49 ( ( T_6 ) V_128 , V_12 ) ) ;
else if ( V_125 -> V_103 & V_129 )
return F_48 ( V_50 , F_49 ( ( T_6 ) V_130 , V_12 ) ) ;
else
return V_50 ;
}
static void T_2 F_50 ( struct V_96 * V_48 )
{
struct V_131 V_132 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . V_133 = 1 ;
V_132 . V_99 = ( void * * ) & V_48 ;
V_132 . V_134 = F_38 ;
V_132 . V_135 = F_44 ;
V_132 . V_136 = F_41 ;
V_132 . V_137 = & V_123 ;
V_132 . V_138 = F_47 ;
F_51 ( & V_132 ) ;
}
static void T_7 * T_2
F_52 ( struct V_139 * V_121 ,
struct V_140 * V_141 ,
struct V_1 * V_2 )
{
struct V_124 V_142 ;
int V_39 = 0 ;
V_39 = F_53 ( V_141 , 0 , & V_142 ) ;
if ( V_39 )
return F_54 ( V_39 ) ;
return F_55 ( & V_121 -> V_114 , & V_142 ) ;
}
static int F_56 ( struct V_140 * V_141 , int V_32 ,
unsigned long type , int * V_143 , int * V_144 )
{
const int V_145 = 3 , V_146 = 2 ;
const T_8 * V_147 ;
int V_148 , V_149 , V_150 , V_151 , V_13 ;
V_147 = F_57 ( V_141 , L_1 , & V_148 ) ;
if ( ! V_147 )
return - V_152 ;
V_151 = F_58 ( V_141 ) ;
V_150 = V_151 + V_145 + V_146 ;
V_149 = V_148 / sizeof( T_8 ) / V_150 ;
for ( V_13 = 0 ; V_13 < V_149 ; V_13 ++ ) {
T_1 V_103 = F_59 ( V_147 , 1 ) ;
T_1 V_115 = F_59 ( V_147 , 2 ) ;
T_9 V_153 = F_59 ( V_147 + V_145 , V_151 ) ;
unsigned long V_154 ;
if ( F_60 ( V_103 ) == V_155 )
V_154 = V_127 ;
else if ( F_60 ( V_103 ) == V_156 )
V_154 = V_129 ;
if ( V_115 == F_34 ( V_32 ) && type == V_154 ) {
* V_143 = F_61 ( V_153 ) ;
* V_144 = F_62 ( V_153 ) ;
return 0 ;
}
V_147 += V_150 ;
}
return - V_157 ;
}
static int T_2 F_63 ( struct V_139 * V_121 )
{
struct V_96 * V_48 ;
struct V_140 * V_141 = V_121 -> V_114 . V_158 ;
struct V_140 * V_159 ;
int V_13 , V_39 ;
V_48 = F_64 ( & V_121 -> V_114 , sizeof( struct V_96 ) ,
V_160 ) ;
if ( ! V_48 )
return - V_161 ;
V_48 -> V_121 = V_121 ;
F_65 ( & V_48 -> V_110 ) ;
if ( F_66 ( & V_48 -> V_110 ) == 0 ) {
F_67 ( & V_121 -> V_114 , L_2 ) ;
return - V_152 ;
}
F_68 ( & V_48 -> V_49 ) ;
if ( F_66 ( & V_48 -> V_49 ) == 0 ) {
F_67 ( & V_121 -> V_114 , L_3 ) ;
return - V_152 ;
}
V_48 -> V_108 . V_103 = V_48 -> V_49 . V_103 ;
V_48 -> V_108 . V_50 = V_162 ;
V_48 -> V_108 . V_163 = F_69 ( T_6 ,
V_164 ,
F_66 ( & V_48 -> V_49 ) ) ;
V_39 = F_70 ( V_141 , & V_48 -> V_112 ) ;
if ( V_39 ) {
F_67 ( & V_121 -> V_114 , L_4 ,
V_39 ) ;
return V_39 ;
}
F_71 (pdev->dev.of_node, child) {
if ( ! F_72 ( V_159 ) )
continue;
V_48 -> V_100 ++ ;
}
V_48 -> V_101 = F_64 ( & V_121 -> V_114 , V_48 -> V_100 *
sizeof( struct V_1 ) ,
V_160 ) ;
if ( ! V_48 -> V_101 )
return - V_161 ;
V_13 = 0 ;
F_71 (pdev->dev.of_node, child) {
struct V_1 * V_2 = & V_48 -> V_101 [ V_13 ] ;
if ( ! F_72 ( V_159 ) )
continue;
V_2 -> V_48 = V_48 ;
if ( F_73 ( V_159 , L_5 ,
& V_2 -> V_2 ) ) {
F_74 ( & V_121 -> V_114 ,
L_6 ) ;
continue;
}
if ( F_73 ( V_159 , L_7 ,
& V_2 -> V_165 ) )
V_2 -> V_165 = 0 ;
V_2 -> V_166 = F_75 ( V_160 , L_8 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
V_2 -> V_32 = F_76 ( V_159 ) ;
if ( V_2 -> V_32 < 0 )
continue;
V_39 = F_56 ( V_141 , V_2 -> V_32 , V_129 ,
& V_2 -> V_57 , & V_2 -> V_58 ) ;
if ( V_39 < 0 ) {
F_67 ( & V_121 -> V_114 , L_9 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
continue;
}
V_39 = F_56 ( V_141 , V_2 -> V_32 , V_127 ,
& V_2 -> V_51 , & V_2 -> V_52 ) ;
if ( V_39 < 0 ) {
F_67 ( & V_121 -> V_114 , L_10 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
continue;
}
V_2 -> V_3 = F_52 ( V_121 , V_159 , V_2 ) ;
if ( F_77 ( V_2 -> V_3 ) ) {
F_67 ( & V_121 -> V_114 , L_11 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
V_2 -> V_3 = NULL ;
continue;
}
F_5 ( V_2 , 1 ) ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_105 = 1 ;
F_78 ( & V_121 -> V_114 , L_12 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
} else {
V_2 -> V_105 = 0 ;
F_78 ( & V_121 -> V_114 , L_13 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
}
V_2 -> V_167 = F_79 ( V_159 , NULL ) ;
if ( F_77 ( V_2 -> V_167 ) ) {
F_67 ( & V_121 -> V_114 , L_14 ,
V_2 -> V_2 , V_2 -> V_165 ) ;
F_80 ( V_2 -> V_3 ) ;
V_2 -> V_105 = 0 ;
continue;
}
V_2 -> V_168 = V_159 ;
F_81 ( V_2 -> V_167 ) ;
F_82 ( & V_2 -> V_106 ) ;
F_28 ( V_2 ) ;
V_13 ++ ;
}
F_50 ( V_48 ) ;
return 0 ;
}
static int T_2 F_83 ( void )
{
return F_84 ( & V_169 ,
F_63 ) ;
}
