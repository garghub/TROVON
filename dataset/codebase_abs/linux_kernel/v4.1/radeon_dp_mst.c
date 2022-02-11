static int F_1 ( int V_1 )
{
static const int V_2 [] = { V_3 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ,
V_8 ,
0x13830 - 0x7030 } ;
return V_2 [ V_1 ] ;
}
static int F_2 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
enum V_13 V_14 , bool V_15 )
{
struct V_16 * V_17 = V_10 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
T_1 V_22 ;
int V_23 = 0 ;
T_1 V_24 ;
V_22 = F_3 ( V_25 + V_10 -> V_26 ) ;
V_22 &= ~ F_4 ( 7 ) ;
V_22 |= F_4 ( V_27 ) ;
if ( V_15 )
V_22 |= F_5 ( 1 << V_12 -> V_28 ) ;
else
V_22 &= ~ F_5 ( 1 << V_12 -> V_28 ) ;
V_22 |= F_6 ( V_14 ) ;
F_7 ( L_1 , V_25 + V_10 -> V_26 , V_22 ) ;
F_8 ( V_25 + V_10 -> V_26 , V_22 ) ;
if ( V_15 ) {
T_1 V_26 = F_1 ( V_12 -> V_28 ) ;
do {
V_24 = F_3 ( V_29 + V_26 ) ;
} while ( ( V_24 & V_30 ) && V_23 ++ < 10000 );
if ( V_23 == 10000 )
F_9 ( L_2 , V_10 -> V_26 , V_12 -> V_28 ) ;
}
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
int V_31 ,
int V_28 ,
int V_32 )
{
struct V_16 * V_17 = V_10 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
T_2 V_24 , V_33 ;
int V_23 = 0 ;
int V_34 , V_35 ;
V_34 = V_31 >> 1 ;
V_35 = V_31 & 1 ;
V_24 = F_3 ( V_36 + V_34 + V_10 -> V_26 ) ;
V_33 = F_11 ( V_32 ) | F_12 ( V_28 ) ;
V_33 <<= ( 16 * V_35 ) ;
V_24 &= ~ ( 0xffff << ( 16 * V_35 ) ) ;
V_24 |= V_33 ;
F_7 ( L_1 , V_36 + V_34 + V_10 -> V_26 , V_24 ) ;
F_8 ( V_36 + V_34 + V_10 -> V_26 , V_24 ) ;
F_8 ( V_37 + V_10 -> V_26 , 1 ) ;
do {
V_24 = F_3 ( V_37 + V_10 -> V_26 ) ;
} while ( ( V_24 & 0x1 ) && V_23 ++ < 10000 );
if ( V_23 == 10000 )
F_9 ( L_3 , V_10 -> V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 ,
struct V_9 * V_10 )
{
struct V_16 * V_17 = V_39 -> V_18 . V_17 ;
struct V_40 V_41 [ 6 ] ;
int V_42 ;
int V_43 = 0 ;
struct V_38 * V_38 ;
struct V_44 * V_45 ;
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_9 * V_46 ;
struct V_11 * V_12 ;
V_38 = F_15 ( V_45 ) ;
if ( ! V_38 -> V_47 )
continue;
if ( V_38 -> V_48 != V_39 )
continue;
V_46 = V_38 -> V_49 ;
V_12 = V_46 -> V_50 ;
if ( ! V_12 -> V_51 )
continue;
V_41 [ V_43 ] . V_28 = V_12 -> V_28 ;
V_41 [ V_43 ] . V_32 = F_16 ( & V_39 -> V_52 , V_12 -> V_53 ) ;
V_43 ++ ;
}
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_41 [ V_42 ] . V_28 != V_39 -> V_54 [ V_42 ] . V_28 ||
V_41 [ V_42 ] . V_32 != V_39 -> V_54 [ V_42 ] . V_32 ) {
F_10 ( V_10 , V_42 , V_41 [ V_42 ] . V_28 , V_41 [ V_42 ] . V_32 ) ;
V_39 -> V_54 [ V_42 ] . V_28 = V_41 [ V_42 ] . V_28 ;
V_39 -> V_54 [ V_42 ] . V_32 = V_41 [ V_42 ] . V_32 ;
}
}
for ( V_42 = V_43 ; V_42 < V_39 -> V_55 ; V_42 ++ ) {
F_10 ( V_10 , V_42 , 0 , 0 ) ;
V_39 -> V_54 [ V_42 ] . V_28 = 0 ;
V_39 -> V_54 [ V_42 ] . V_32 = 0 ;
}
V_39 -> V_55 = V_43 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_56 , T_1 V_57 , T_1 V_58 )
{
struct V_16 * V_17 = V_56 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_11 * V_12 = V_56 -> V_50 ;
T_1 V_33 , V_24 ;
T_1 V_26 = F_1 ( V_12 -> V_28 ) ;
int V_23 = 0 ;
V_33 = F_18 ( V_57 ) | F_19 ( V_58 ) ;
F_8 ( V_59 + V_26 , V_33 ) ;
do {
V_24 = F_3 ( V_60 + V_26 ) ;
} while ( ( V_24 & 0x1 ) && ( V_23 ++ < 10000 ) );
if ( V_23 >= 10000 )
F_9 ( L_4 , V_12 -> V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 )
{
struct V_38 * V_38 = F_15 ( V_45 ) ;
struct V_38 * V_61 = V_38 -> V_48 ;
struct V_62 * V_62 ;
int V_63 = 0 ;
V_62 = F_21 ( V_45 , & V_61 -> V_52 , V_38 -> V_53 ) ;
V_38 -> V_62 = V_62 ;
F_7 ( L_5 , V_62 ) ;
if ( V_38 -> V_62 ) {
F_22 ( & V_38 -> V_18 , V_38 -> V_62 ) ;
V_63 = F_23 ( & V_38 -> V_18 , V_38 -> V_62 ) ;
F_24 ( & V_38 -> V_18 , V_38 -> V_62 ) ;
return V_63 ;
}
F_22 ( & V_38 -> V_18 , NULL ) ;
return V_63 ;
}
static int F_25 ( struct V_44 * V_45 )
{
return F_20 ( V_45 ) ;
}
static enum V_64
F_26 ( struct V_44 * V_45 ,
struct V_65 * V_66 )
{
if ( V_66 -> clock < 10000 )
return V_67 ;
if ( V_66 -> V_68 & V_69 )
return V_70 ;
return V_71 ;
}
struct V_72 * F_27 ( struct V_44 * V_45 )
{
struct V_38 * V_38 = F_15 ( V_45 ) ;
return & V_38 -> V_49 -> V_18 ;
}
static enum V_73
F_28 ( struct V_44 * V_45 , bool V_74 )
{
struct V_38 * V_38 = F_15 ( V_45 ) ;
struct V_38 * V_61 = V_38 -> V_48 ;
return F_29 ( V_45 , & V_61 -> V_52 , V_38 -> V_53 ) ;
}
static void
F_30 ( struct V_44 * V_45 )
{
struct V_38 * V_38 = F_15 ( V_45 ) ;
struct V_9 * V_9 = V_38 -> V_49 ;
F_31 ( & V_9 -> V_18 ) ;
F_32 ( V_9 ) ;
F_33 ( V_45 ) ;
F_32 ( V_38 ) ;
}
static void F_34 ( struct V_44 * V_45 , int V_66 )
{
F_7 ( L_6 ) ;
}
static struct V_44 * F_35 ( struct V_75 * V_76 ,
struct V_77 * V_53 ,
const char * V_78 )
{
struct V_38 * V_61 = F_36 ( V_76 , struct V_38 , V_52 ) ;
struct V_16 * V_17 = V_61 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_38 * V_38 ;
struct V_44 * V_45 ;
V_38 = F_37 ( sizeof( * V_38 ) , V_79 ) ;
if ( ! V_38 )
return NULL ;
V_38 -> V_47 = true ;
V_45 = & V_38 -> V_18 ;
V_38 -> V_53 = V_53 ;
V_38 -> V_48 = V_61 ;
F_7 ( L_6 ) ;
F_38 ( V_17 , V_45 , & V_80 , V_81 ) ;
F_39 ( V_45 , & V_82 ) ;
V_38 -> V_49 = F_40 ( V_61 ) ;
F_41 ( & V_45 -> V_18 , V_17 -> V_83 . V_84 , 0 ) ;
F_42 ( V_45 , V_78 ) ;
F_43 ( V_17 ) ;
F_44 ( & V_17 -> V_83 . V_85 ) ;
F_45 ( V_20 , V_45 ) ;
F_46 ( & V_17 -> V_83 . V_85 ) ;
F_47 ( V_45 ) ;
return V_45 ;
}
static void F_48 ( struct V_75 * V_76 ,
struct V_44 * V_45 )
{
struct V_38 * V_61 = F_36 ( V_76 , struct V_38 , V_52 ) ;
struct V_16 * V_17 = V_61 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
F_49 ( V_45 ) ;
F_44 ( & V_17 -> V_83 . V_85 ) ;
F_50 ( V_20 , V_45 ) ;
F_33 ( V_45 ) ;
F_46 ( & V_17 -> V_83 . V_85 ) ;
F_43 ( V_17 ) ;
F_32 ( V_45 ) ;
F_7 ( L_6 ) ;
}
static void F_51 ( struct V_75 * V_76 )
{
struct V_38 * V_61 = F_36 ( V_76 , struct V_38 , V_52 ) ;
struct V_16 * V_17 = V_61 -> V_18 . V_17 ;
F_52 ( V_17 ) ;
}
struct V_38 * F_53 ( struct V_72 * V_86 )
{
struct V_16 * V_17 = V_86 -> V_17 ;
struct V_44 * V_45 ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_38 * V_38 = F_15 ( V_45 ) ;
if ( ! V_45 -> V_86 )
continue;
if ( ! V_38 -> V_47 )
continue;
F_7 ( L_7 , V_45 -> V_86 , V_86 ) ;
if ( V_45 -> V_86 == V_86 )
return V_38 ;
}
return NULL ;
}
void F_54 ( struct V_87 * V_88 , struct V_65 * V_66 )
{
struct V_89 * V_89 = F_55 ( V_88 ) ;
struct V_16 * V_17 = V_88 -> V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_9 * V_9 = F_56 ( V_89 -> V_86 ) ;
struct V_11 * V_12 = V_9 -> V_50 ;
struct V_38 * V_38 = F_53 ( & V_9 -> V_18 ) ;
int V_90 ;
struct V_91 * V_92 = V_12 -> V_45 -> V_93 ;
if ( V_38 ) {
V_38 -> V_94 = V_66 -> clock ;
if ( V_38 -> V_18 . V_95 . V_96 )
V_89 -> V_96 = V_38 -> V_18 . V_95 . V_96 ;
else
V_89 -> V_96 = 8 ;
}
F_7 ( L_8 , V_92 , V_92 -> V_90 ) ;
V_90 = V_92 -> V_90 ;
V_89 -> V_97 =
F_57 ( V_20 , & V_89 -> V_98 ,
V_99 ,
V_90 ) ;
}
static void
F_58 ( struct V_72 * V_86 , int V_66 )
{
struct V_16 * V_17 = V_86 -> V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_9 * V_9 , * V_10 ;
struct V_11 * V_12 ;
struct V_100 * V_101 ;
struct V_38 * V_38 ;
struct V_87 * V_88 ;
struct V_89 * V_89 ;
int V_63 , V_32 ;
if ( ! F_59 ( V_20 ) ) {
F_9 ( L_9 ) ;
return;
}
V_38 = F_53 ( V_86 ) ;
if ( ! V_38 )
return;
V_9 = F_56 ( V_86 ) ;
V_12 = V_9 -> V_50 ;
V_10 = V_12 -> V_10 ;
V_101 = V_10 -> V_50 ;
V_88 = V_86 -> V_88 ;
F_7 ( L_10 , V_101 -> V_102 ) ;
switch ( V_66 ) {
case V_103 :
V_101 -> V_102 ++ ;
V_89 = F_55 ( V_88 ) ;
if ( V_101 -> V_102 == 1 ) {
V_12 -> V_28 = V_101 -> V_104 ;
V_12 -> V_105 = true ;
F_60 ( V_86 , V_12 -> V_28 ) ;
F_61 ( & V_10 -> V_18 , V_106 , 0 ) ;
F_62 ( & V_10 -> V_18 , V_107 ,
0 , 0 , V_101 -> V_104 ) ;
if ( F_63 ( V_12 -> V_45 ) ||
V_101 -> V_102 == 1 ) {
F_64 ( & V_10 -> V_18 , & V_12 -> V_45 -> V_18 ) ;
}
} else {
V_12 -> V_28 = F_65 ( V_86 , V_89 -> V_108 ) ;
if ( V_12 -> V_28 == - 1 )
F_9 ( L_11 ) ;
V_12 -> V_105 = false ;
F_60 ( V_86 , V_12 -> V_28 ) ;
}
F_7 ( L_12 , V_101 -> V_104 ,
V_101 -> V_109 , V_89 -> V_108 ) ;
V_63 = F_66 ( & V_38 -> V_48 -> V_52 ,
V_38 -> V_53 ,
V_12 -> V_110 , & V_32 ) ;
V_63 = F_67 ( & V_38 -> V_48 -> V_52 ) ;
F_2 ( V_10 , V_12 ,
V_38 -> V_48 -> V_14 . V_14 , true ) ;
V_12 -> V_51 = true ;
F_13 ( V_38 -> V_48 , V_10 ) ;
F_17 ( V_9 , V_32 , 0 ) ;
F_68 ( & V_10 -> V_18 , V_111 , 0 ,
V_12 -> V_28 ) ;
V_63 = F_69 ( & V_38 -> V_48 -> V_52 ) ;
V_63 = F_70 ( & V_38 -> V_48 -> V_52 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
F_9 ( L_13 , V_101 -> V_102 ) ;
if ( ! V_12 -> V_51 )
return;
F_71 ( & V_38 -> V_48 -> V_52 , V_12 -> V_53 ) ;
V_63 = F_67 ( & V_38 -> V_48 -> V_52 ) ;
F_69 ( & V_38 -> V_48 -> V_52 ) ;
F_70 ( & V_38 -> V_48 -> V_52 ) ;
F_72 ( & V_38 -> V_48 -> V_52 , V_12 -> V_53 ) ;
V_12 -> V_51 = false ;
F_13 ( V_38 -> V_48 , V_10 ) ;
F_2 ( V_10 , V_12 ,
V_38 -> V_48 -> V_14 . V_14 , false ) ;
F_68 ( & V_10 -> V_18 , V_115 , 0 ,
V_12 -> V_28 ) ;
if ( ! V_12 -> V_105 )
F_73 ( V_20 , V_12 -> V_28 ) ;
V_12 -> V_105 = false ;
V_101 -> V_102 -- ;
if ( V_101 -> V_102 == 0 ) {
}
break;
}
}
static bool F_74 ( struct V_72 * V_86 ,
const struct V_65 * V_66 ,
struct V_65 * V_116 )
{
struct V_11 * V_12 ;
struct V_9 * V_9 = F_56 ( V_86 ) ;
int V_117 = 24 ;
V_12 = V_9 -> V_50 ;
V_12 -> V_110 = F_75 ( V_116 -> clock , V_117 ) ;
V_12 -> V_10 -> V_118 = V_12 -> V_10 -> V_119 & V_12 -> V_45 -> V_119 ;
F_7 ( L_14 ,
V_12 -> V_10 -> V_118 , V_12 -> V_10 -> V_119 ,
V_12 -> V_45 -> V_119 , V_12 -> V_10 -> V_18 . V_120 ) ;
F_76 ( V_116 , 0 ) ;
{
struct V_91 * V_92 ;
V_92 = V_12 -> V_45 -> V_93 ;
V_92 -> V_121 = F_77 ( V_92 -> V_122 ) ;
V_92 -> V_90 = F_78 ( & V_12 -> V_45 -> V_18 ,
V_92 -> V_122 ) ;
F_7 ( L_15 , V_92 ,
V_92 -> V_121 , V_92 -> V_90 ) ;
}
return true ;
}
static void F_79 ( struct V_72 * V_86 )
{
struct V_38 * V_38 ;
struct V_9 * V_9 , * V_10 ;
struct V_11 * V_12 ;
struct V_100 * V_101 ;
V_38 = F_53 ( V_86 ) ;
if ( ! V_38 ) {
F_7 ( L_16 , V_86 ) ;
return;
}
V_9 = F_56 ( V_86 ) ;
F_58 ( V_86 , V_114 ) ;
V_12 = V_9 -> V_50 ;
V_10 = V_12 -> V_10 ;
V_101 = V_10 -> V_50 ;
V_12 -> V_53 = V_38 -> V_53 ;
if ( V_101 -> V_104 == - 1 ) {
V_101 -> V_104 = F_65 ( & V_10 -> V_18 , - 1 ) ;
V_10 -> V_26 = F_1 ( V_101 -> V_104 ) ;
F_60 ( V_86 , V_101 -> V_104 ) ;
}
F_7 ( L_17 , V_101 -> V_104 , V_10 -> V_26 ) ;
}
static void
F_80 ( struct V_72 * V_86 ,
struct V_65 * V_66 ,
struct V_65 * V_116 )
{
F_7 ( L_6 ) ;
}
static void F_81 ( struct V_72 * V_86 )
{
F_58 ( V_86 , V_103 ) ;
F_7 ( L_6 ) ;
}
void F_82 ( struct V_72 * V_86 )
{
F_31 ( V_86 ) ;
F_32 ( V_86 ) ;
}
static struct V_9 *
F_40 ( struct V_38 * V_45 )
{
struct V_16 * V_17 = V_45 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_9 * V_9 ;
struct V_11 * V_12 ;
struct V_72 * V_86 ;
const struct V_123 * V_124 = V_45 -> V_18 . V_125 ;
struct V_72 * V_126 = V_124 -> V_127 ( & V_45 -> V_18 ) ;
F_7 ( L_18 , V_126 ) ;
V_9 = F_37 ( sizeof( * V_9 ) , V_79 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_50 = F_37 ( sizeof( * V_12 ) , V_79 ) ;
if ( ! V_9 -> V_50 ) {
F_32 ( V_9 ) ;
return NULL ;
}
V_86 = & V_9 -> V_18 ;
switch ( V_20 -> V_128 ) {
case 1 :
V_86 -> V_129 = 0x1 ;
break;
case 2 :
default:
V_86 -> V_129 = 0x3 ;
break;
case 4 :
V_86 -> V_129 = 0xf ;
break;
case 6 :
V_86 -> V_129 = 0x3f ;
break;
}
F_83 ( V_17 , & V_9 -> V_18 , & V_130 ,
V_131 ) ;
F_84 ( V_86 , & V_132 ) ;
V_12 = V_9 -> V_50 ;
V_12 -> V_45 = V_45 ;
V_12 -> V_10 = F_56 ( V_126 ) ;
V_9 -> V_133 = true ;
return V_9 ;
}
int
F_85 ( struct V_38 * V_38 )
{
struct V_16 * V_17 = V_38 -> V_18 . V_17 ;
if ( ! V_38 -> V_134 -> V_135 )
return 0 ;
V_38 -> V_52 . V_136 = & V_137 ;
return F_86 ( & V_38 -> V_52 , V_17 -> V_17 ,
& V_38 -> V_134 -> V_138 , 16 , 6 ,
V_38 -> V_18 . V_18 . V_1 ) ;
}
int
F_87 ( struct V_38 * V_38 )
{
struct V_91 * V_92 = V_38 -> V_93 ;
struct V_16 * V_17 = V_38 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
int V_63 ;
T_3 V_139 [ 1 ] ;
if ( ! V_140 )
return 0 ;
if ( ! F_59 ( V_20 ) )
return 0 ;
if ( V_92 -> V_122 [ V_141 ] < 0x12 )
return 0 ;
V_63 = F_88 ( & V_38 -> V_134 -> V_138 , V_142 , V_139 ,
1 ) ;
if ( V_63 ) {
if ( V_139 [ 0 ] & V_143 ) {
F_7 ( L_19 ) ;
V_92 -> V_144 = true ;
} else {
F_7 ( L_20 ) ;
V_92 -> V_144 = false ;
}
}
F_89 ( & V_38 -> V_52 ,
V_92 -> V_144 ) ;
return V_92 -> V_144 ;
}
int
F_90 ( struct V_38 * V_38 )
{
struct V_91 * V_92 = V_38 -> V_93 ;
int V_145 ;
if ( V_92 -> V_144 ) {
T_3 V_146 [ 16 ] = { 0 } ;
int V_147 ;
int V_63 = 0 ;
bool V_148 ;
V_147 = F_88 ( & V_38 -> V_134 -> V_138 ,
V_149 , V_146 , 8 ) ;
V_150:
if ( V_147 == 8 ) {
F_7 ( L_21 , V_146 [ 0 ] , V_146 [ 1 ] , V_146 [ 2 ] ) ;
V_63 = F_91 ( & V_38 -> V_52 , V_146 , & V_148 ) ;
if ( V_148 ) {
for ( V_145 = 0 ; V_145 < 3 ; V_145 ++ ) {
int V_151 ;
V_151 = F_92 ( & V_38 -> V_134 -> V_138 ,
V_149 + 1 , & V_146 [ 1 ] , 3 ) ;
if ( V_151 == 3 )
break;
}
V_147 = F_88 ( & V_38 -> V_134 -> V_138 ,
V_149 , V_146 , 8 ) ;
if ( V_147 == 8 ) {
F_7 ( L_22 , V_146 [ 0 ] , V_146 [ 1 ] , V_146 [ 2 ] ) ;
goto V_150;
}
} else
V_63 = 0 ;
return V_63 ;
} else {
F_7 ( L_23 , V_63 ) ;
V_92 -> V_144 = false ;
F_89 ( & V_38 -> V_52 ,
V_92 -> V_144 ) ;
}
}
return - V_152 ;
}
static int F_93 ( struct V_153 * V_154 , void * V_155 )
{
struct V_156 * V_157 = (struct V_156 * ) V_154 -> V_158 ;
struct V_16 * V_17 = V_157 -> V_159 -> V_17 ;
struct V_44 * V_45 ;
struct V_38 * V_38 ;
struct V_91 * V_92 ;
int V_42 ;
F_94 ( V_17 ) ;
F_14 (connector, &dev->mode_config.connector_list, head) {
if ( V_45 -> V_160 != V_81 )
continue;
V_38 = F_15 ( V_45 ) ;
V_92 = V_38 -> V_93 ;
if ( V_38 -> V_47 )
continue;
if ( ! V_92 -> V_144 )
continue;
F_95 ( V_154 , & V_38 -> V_52 ) ;
for ( V_42 = 0 ; V_42 < V_38 -> V_55 ; V_42 ++ )
F_96 ( V_154 , L_24 , V_42 ,
V_38 -> V_54 [ V_42 ] . V_28 ,
V_38 -> V_54 [ V_42 ] . V_32 ) ;
}
F_97 ( V_17 ) ;
return 0 ;
}
int F_98 ( struct V_19 * V_20 )
{
#if F_99 ( V_161 )
return F_100 ( V_20 , V_162 , 1 ) ;
#endif
return 0 ;
}
