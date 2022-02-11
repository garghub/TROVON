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
unsigned V_38 , V_39 ;
F_13 ( 10 ) ;
V_24 = F_3 ( V_37 + V_10 -> V_26 ) ;
V_38 = V_24 & V_40 ;
V_39 = V_24 & V_41 ;
if ( ! V_38 && ! V_39 )
break;
} while ( V_23 ++ < 50 );
if ( V_23 == 10000 )
F_9 ( L_3 , V_10 -> V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_42 * V_43 ,
struct V_9 * V_10 )
{
struct V_16 * V_17 = V_43 -> V_18 . V_17 ;
struct V_44 V_45 [ 6 ] ;
int V_46 ;
int V_47 = 0 ;
struct V_42 * V_42 ;
struct V_48 * V_49 ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
F_15 (connector, &dev->mode_config.connector_list, head) {
struct V_9 * V_50 ;
struct V_11 * V_12 ;
V_42 = F_16 ( V_49 ) ;
if ( ! V_42 -> V_51 )
continue;
if ( V_42 -> V_52 != V_43 )
continue;
V_50 = V_42 -> V_53 ;
V_12 = V_50 -> V_54 ;
if ( ! V_12 -> V_55 )
continue;
V_45 [ V_47 ] . V_28 = V_12 -> V_28 ;
V_45 [ V_47 ] . V_32 = F_17 ( & V_43 -> V_56 , V_12 -> V_57 ) ;
V_47 ++ ;
}
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( V_45 [ V_46 ] . V_28 != V_43 -> V_58 [ V_46 ] . V_28 ||
V_45 [ V_46 ] . V_32 != V_43 -> V_58 [ V_46 ] . V_32 ) {
F_10 ( V_10 , V_46 , V_45 [ V_46 ] . V_28 , V_45 [ V_46 ] . V_32 ) ;
V_43 -> V_58 [ V_46 ] . V_28 = V_45 [ V_46 ] . V_28 ;
V_43 -> V_58 [ V_46 ] . V_32 = V_45 [ V_46 ] . V_32 ;
}
}
for ( V_46 = V_47 ; V_46 < V_43 -> V_59 ; V_46 ++ ) {
F_10 ( V_10 , V_46 , 0 , 0 ) ;
V_43 -> V_58 [ V_46 ] . V_28 = 0 ;
V_43 -> V_58 [ V_46 ] . V_32 = 0 ;
}
V_43 -> V_59 = V_47 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_60 , T_3 V_61 )
{
struct V_16 * V_17 = V_60 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_11 * V_12 = V_60 -> V_54 ;
T_1 V_33 , V_24 ;
T_1 V_26 = F_1 ( V_12 -> V_28 ) ;
int V_23 = 0 ;
T_1 V_62 = F_19 ( V_61 ) ;
T_1 V_63 = F_20 ( ( V_61 - V_62 ) << 26 ) ;
V_33 = F_21 ( V_62 ) | F_22 ( V_63 ) ;
F_8 ( V_64 + V_26 , V_33 ) ;
do {
V_24 = F_3 ( V_65 + V_26 ) ;
F_13 ( 10 ) ;
} while ( ( V_24 & 0x1 ) && ( V_23 ++ < 10000 ) );
if ( V_23 >= 10000 )
F_9 ( L_4 , V_12 -> V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_48 * V_49 )
{
struct V_42 * V_42 = F_16 ( V_49 ) ;
struct V_42 * V_66 = V_42 -> V_52 ;
struct V_67 * V_67 ;
int V_68 = 0 ;
V_67 = F_24 ( V_49 , & V_66 -> V_56 , V_42 -> V_57 ) ;
V_42 -> V_67 = V_67 ;
F_7 ( L_5 , V_67 ) ;
if ( V_42 -> V_67 ) {
F_25 ( & V_42 -> V_18 , V_42 -> V_67 ) ;
V_68 = F_26 ( & V_42 -> V_18 , V_42 -> V_67 ) ;
F_27 ( & V_42 -> V_18 , V_42 -> V_67 ) ;
return V_68 ;
}
F_25 ( & V_42 -> V_18 , NULL ) ;
return V_68 ;
}
static int F_28 ( struct V_48 * V_49 )
{
return F_23 ( V_49 ) ;
}
static enum V_69
F_29 ( struct V_48 * V_49 ,
struct V_70 * V_71 )
{
if ( V_71 -> clock < 10000 )
return V_72 ;
if ( V_71 -> V_73 & V_74 )
return V_75 ;
return V_76 ;
}
static struct
V_77 * F_30 ( struct V_48 * V_49 )
{
struct V_42 * V_42 = F_16 ( V_49 ) ;
return & V_42 -> V_53 -> V_18 ;
}
static enum V_78
F_31 ( struct V_48 * V_49 , bool V_79 )
{
struct V_42 * V_42 = F_16 ( V_49 ) ;
struct V_42 * V_66 = V_42 -> V_52 ;
return F_32 ( V_49 , & V_66 -> V_56 , V_42 -> V_57 ) ;
}
static void
F_33 ( struct V_48 * V_49 )
{
struct V_42 * V_42 = F_16 ( V_49 ) ;
struct V_9 * V_9 = V_42 -> V_53 ;
F_34 ( & V_9 -> V_18 ) ;
F_35 ( V_9 ) ;
F_36 ( V_49 ) ;
F_35 ( V_42 ) ;
}
static struct V_48 * F_37 ( struct V_80 * V_81 ,
struct V_82 * V_57 ,
const char * V_83 )
{
struct V_42 * V_66 = F_38 ( V_81 , struct V_42 , V_56 ) ;
struct V_16 * V_17 = V_66 -> V_18 . V_17 ;
struct V_42 * V_42 ;
struct V_48 * V_49 ;
V_42 = F_39 ( sizeof( * V_42 ) , V_84 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_51 = true ;
V_49 = & V_42 -> V_18 ;
V_42 -> V_57 = V_57 ;
V_42 -> V_52 = V_66 ;
F_7 ( L_6 ) ;
F_40 ( V_17 , V_49 , & V_85 , V_86 ) ;
F_41 ( V_49 , & V_87 ) ;
V_42 -> V_53 = F_42 ( V_66 ) ;
F_43 ( & V_49 -> V_18 , V_17 -> V_88 . V_89 , 0 ) ;
F_43 ( & V_49 -> V_18 , V_17 -> V_88 . V_90 , 0 ) ;
F_44 ( V_49 , V_83 ) ;
return V_49 ;
}
static void F_45 ( struct V_48 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
F_46 ( V_17 ) ;
F_47 ( V_20 , V_49 ) ;
F_48 ( V_17 ) ;
F_49 ( V_49 ) ;
}
static void F_50 ( struct V_80 * V_81 ,
struct V_48 * V_49 )
{
struct V_42 * V_66 = F_38 ( V_81 , struct V_42 , V_56 ) ;
struct V_16 * V_17 = V_66 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
F_51 ( V_49 ) ;
F_46 ( V_17 ) ;
F_52 ( V_20 , V_49 ) ;
F_36 ( V_49 ) ;
F_48 ( V_17 ) ;
F_35 ( V_49 ) ;
F_7 ( L_6 ) ;
}
static void F_53 ( struct V_80 * V_81 )
{
struct V_42 * V_66 = F_38 ( V_81 , struct V_42 , V_56 ) ;
struct V_16 * V_17 = V_66 -> V_18 . V_17 ;
F_54 ( V_17 ) ;
}
static struct
V_42 * F_55 ( struct V_77 * V_91 )
{
struct V_16 * V_17 = V_91 -> V_17 ;
struct V_48 * V_49 ;
F_15 (connector, &dev->mode_config.connector_list, head) {
struct V_42 * V_42 = F_16 ( V_49 ) ;
if ( ! V_49 -> V_91 )
continue;
if ( ! V_42 -> V_51 )
continue;
F_7 ( L_7 , V_49 -> V_91 , V_91 ) ;
if ( V_49 -> V_91 == V_91 )
return V_42 ;
}
return NULL ;
}
void F_56 ( struct V_92 * V_93 , struct V_70 * V_71 )
{
struct V_94 * V_94 = F_57 ( V_93 ) ;
struct V_16 * V_17 = V_93 -> V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_9 * V_9 = F_58 ( V_94 -> V_91 ) ;
struct V_11 * V_12 = V_9 -> V_54 ;
struct V_42 * V_42 = F_55 ( & V_9 -> V_18 ) ;
int V_95 ;
struct V_96 * V_97 = V_12 -> V_49 -> V_98 ;
if ( V_42 ) {
V_42 -> V_99 = V_71 -> clock ;
if ( V_42 -> V_18 . V_100 . V_101 )
V_94 -> V_101 = V_42 -> V_18 . V_100 . V_101 ;
else
V_94 -> V_101 = 8 ;
}
F_7 ( L_8 , V_97 , V_97 -> V_95 ) ;
V_95 = V_97 -> V_95 ;
V_94 -> V_102 =
F_59 ( V_20 , & V_94 -> V_103 ,
V_104 ,
V_95 ) ;
}
static void
F_60 ( struct V_77 * V_91 , int V_71 )
{
struct V_16 * V_17 = V_91 -> V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_9 * V_9 , * V_10 ;
struct V_11 * V_12 ;
struct V_105 * V_106 ;
struct V_42 * V_42 ;
struct V_92 * V_93 ;
struct V_94 * V_94 ;
int V_68 , V_32 ;
T_3 V_107 , V_108 , V_61 ;
if ( ! F_61 ( V_20 ) ) {
F_9 ( L_9 ) ;
return;
}
V_42 = F_55 ( V_91 ) ;
if ( ! V_42 )
return;
V_9 = F_58 ( V_91 ) ;
V_12 = V_9 -> V_54 ;
V_10 = V_12 -> V_10 ;
V_106 = V_10 -> V_54 ;
V_93 = V_91 -> V_93 ;
F_7 ( L_10 , V_106 -> V_109 ) ;
switch ( V_71 ) {
case V_110 :
V_106 -> V_109 ++ ;
V_94 = F_57 ( V_93 ) ;
if ( V_106 -> V_109 == 1 ) {
V_12 -> V_28 = V_106 -> V_111 ;
V_12 -> V_112 = true ;
F_62 ( V_91 , V_12 -> V_28 ) ;
F_63 ( & V_10 -> V_18 , V_113 , 0 ) ;
F_64 ( & V_10 -> V_18 , V_114 ,
0 , 0 , V_106 -> V_111 ) ;
if ( F_65 ( V_12 -> V_49 ) ||
V_106 -> V_109 == 1 ) {
F_66 ( & V_10 -> V_18 , & V_12 -> V_49 -> V_18 ) ;
}
} else {
V_12 -> V_28 = F_67 ( V_91 , V_94 -> V_115 ) ;
if ( V_12 -> V_28 == - 1 )
F_9 ( L_11 ) ;
V_12 -> V_112 = false ;
F_62 ( V_91 , V_12 -> V_28 ) ;
}
F_7 ( L_12 , V_106 -> V_111 ,
V_106 -> V_116 , V_94 -> V_115 ) ;
V_68 = F_68 ( & V_42 -> V_52 -> V_56 ,
V_42 -> V_57 ,
V_12 -> V_117 , & V_32 ) ;
V_68 = F_69 ( & V_42 -> V_52 -> V_56 ) ;
F_2 ( V_10 , V_12 ,
V_42 -> V_52 -> V_14 . V_14 , true ) ;
V_12 -> V_55 = true ;
F_14 ( V_42 -> V_52 , V_10 ) ;
V_107 = F_70 ( V_12 -> V_117 ) ;
V_108 = F_70 ( V_42 -> V_52 -> V_56 . V_118 ) ;
V_61 = F_71 ( V_107 , V_108 ) ;
F_18 ( V_9 , V_61 ) ;
F_72 ( & V_10 -> V_18 , V_119 , 0 ,
V_12 -> V_28 ) ;
V_68 = F_73 ( & V_42 -> V_52 -> V_56 ) ;
V_68 = F_74 ( & V_42 -> V_52 -> V_56 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
F_9 ( L_13 , V_106 -> V_109 ) ;
if ( ! V_12 -> V_55 )
return;
F_75 ( & V_42 -> V_52 -> V_56 , V_12 -> V_57 ) ;
V_68 = F_69 ( & V_42 -> V_52 -> V_56 ) ;
F_73 ( & V_42 -> V_52 -> V_56 ) ;
F_74 ( & V_42 -> V_52 -> V_56 ) ;
F_76 ( & V_42 -> V_52 -> V_56 , V_12 -> V_57 ) ;
V_12 -> V_55 = false ;
F_14 ( V_42 -> V_52 , V_10 ) ;
F_2 ( V_10 , V_12 ,
V_42 -> V_52 -> V_14 . V_14 , false ) ;
F_72 ( & V_10 -> V_18 , V_123 , 0 ,
V_12 -> V_28 ) ;
if ( ! V_12 -> V_112 )
F_77 ( V_20 , V_12 -> V_28 ) ;
V_12 -> V_112 = false ;
V_106 -> V_109 -- ;
if ( V_106 -> V_109 == 0 ) {
}
break;
}
}
static bool F_78 ( struct V_77 * V_91 ,
const struct V_70 * V_71 ,
struct V_70 * V_124 )
{
struct V_11 * V_12 ;
struct V_9 * V_9 = F_58 ( V_91 ) ;
struct V_96 * V_97 ;
int V_125 = 24 ;
V_12 = V_9 -> V_54 ;
V_12 -> V_117 = F_79 ( V_124 -> clock , V_125 ) ;
V_12 -> V_10 -> V_126 = V_12 -> V_10 -> V_127 & V_12 -> V_49 -> V_127 ;
F_7 ( L_14 ,
V_12 -> V_10 -> V_126 , V_12 -> V_10 -> V_127 ,
V_12 -> V_49 -> V_127 , V_12 -> V_10 -> V_18 . V_128 ) ;
F_80 ( V_124 , 0 ) ;
V_97 = V_12 -> V_49 -> V_98 ;
V_97 -> V_129 = F_81 ( V_97 -> V_130 ) ;
V_97 -> V_95 = F_82 ( V_97 -> V_130 ) ;
F_7 ( L_15 , V_97 ,
V_97 -> V_129 , V_97 -> V_95 ) ;
return true ;
}
static void F_83 ( struct V_77 * V_91 )
{
struct V_42 * V_42 ;
struct V_9 * V_9 , * V_10 ;
struct V_11 * V_12 ;
struct V_105 * V_106 ;
V_42 = F_55 ( V_91 ) ;
if ( ! V_42 ) {
F_7 ( L_16 , V_91 ) ;
return;
}
V_9 = F_58 ( V_91 ) ;
F_60 ( V_91 , V_122 ) ;
V_12 = V_9 -> V_54 ;
V_10 = V_12 -> V_10 ;
V_106 = V_10 -> V_54 ;
V_12 -> V_57 = V_42 -> V_57 ;
if ( V_106 -> V_111 == - 1 ) {
V_106 -> V_111 = F_67 ( & V_10 -> V_18 , - 1 ) ;
V_10 -> V_26 = F_1 ( V_106 -> V_111 ) ;
F_62 ( V_91 , V_106 -> V_111 ) ;
}
F_7 ( L_17 , V_106 -> V_111 , V_10 -> V_26 ) ;
}
static void
F_84 ( struct V_77 * V_91 ,
struct V_70 * V_71 ,
struct V_70 * V_124 )
{
F_7 ( L_6 ) ;
}
static void F_85 ( struct V_77 * V_91 )
{
F_60 ( V_91 , V_110 ) ;
F_7 ( L_6 ) ;
}
static void F_86 ( struct V_77 * V_91 )
{
F_34 ( V_91 ) ;
F_35 ( V_91 ) ;
}
static struct V_9 *
F_42 ( struct V_42 * V_49 )
{
struct V_16 * V_17 = V_49 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
struct V_9 * V_9 ;
struct V_11 * V_12 ;
struct V_77 * V_91 ;
const struct V_131 * V_132 = V_49 -> V_18 . V_133 ;
struct V_77 * V_134 = V_132 -> V_135 ( & V_49 -> V_18 ) ;
F_7 ( L_18 , V_134 ) ;
V_9 = F_39 ( sizeof( * V_9 ) , V_84 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_54 = F_39 ( sizeof( * V_12 ) , V_84 ) ;
if ( ! V_9 -> V_54 ) {
F_35 ( V_9 ) ;
return NULL ;
}
V_91 = & V_9 -> V_18 ;
switch ( V_20 -> V_136 ) {
case 1 :
V_91 -> V_137 = 0x1 ;
break;
case 2 :
default:
V_91 -> V_137 = 0x3 ;
break;
case 4 :
V_91 -> V_137 = 0xf ;
break;
case 6 :
V_91 -> V_137 = 0x3f ;
break;
}
F_87 ( V_17 , & V_9 -> V_18 , & V_138 ,
V_139 , NULL ) ;
F_88 ( V_91 , & V_140 ) ;
V_12 = V_9 -> V_54 ;
V_12 -> V_49 = V_49 ;
V_12 -> V_10 = F_58 ( V_134 ) ;
V_9 -> V_141 = true ;
return V_9 ;
}
int
F_89 ( struct V_42 * V_42 )
{
struct V_16 * V_17 = V_42 -> V_18 . V_17 ;
if ( ! V_42 -> V_142 -> V_143 )
return 0 ;
V_42 -> V_56 . V_144 = & V_145 ;
return F_90 ( & V_42 -> V_56 , V_17 ,
& V_42 -> V_142 -> V_146 , 16 , 6 ,
V_42 -> V_18 . V_18 . V_1 ) ;
}
int
F_91 ( struct V_42 * V_42 )
{
struct V_96 * V_97 = V_42 -> V_98 ;
struct V_16 * V_17 = V_42 -> V_18 . V_17 ;
struct V_19 * V_20 = V_17 -> V_21 ;
int V_68 ;
T_4 V_147 [ 1 ] ;
if ( ! V_148 )
return 0 ;
if ( ! F_61 ( V_20 ) )
return 0 ;
if ( V_97 -> V_130 [ V_149 ] < 0x12 )
return 0 ;
V_68 = F_92 ( & V_42 -> V_142 -> V_146 , V_150 , V_147 ,
1 ) ;
if ( V_68 ) {
if ( V_147 [ 0 ] & V_151 ) {
F_7 ( L_19 ) ;
V_97 -> V_152 = true ;
} else {
F_7 ( L_20 ) ;
V_97 -> V_152 = false ;
}
}
F_93 ( & V_42 -> V_56 ,
V_97 -> V_152 ) ;
return V_97 -> V_152 ;
}
int
F_94 ( struct V_42 * V_42 )
{
struct V_96 * V_97 = V_42 -> V_98 ;
int V_153 ;
if ( V_97 -> V_152 ) {
T_4 V_154 [ 16 ] = { 0 } ;
int V_155 ;
int V_68 = 0 ;
bool V_156 ;
V_155 = F_92 ( & V_42 -> V_142 -> V_146 ,
V_157 , V_154 , 8 ) ;
V_158:
if ( V_155 == 8 ) {
F_7 ( L_21 , V_154 [ 0 ] , V_154 [ 1 ] , V_154 [ 2 ] ) ;
V_68 = F_95 ( & V_42 -> V_56 , V_154 , & V_156 ) ;
if ( V_156 ) {
for ( V_153 = 0 ; V_153 < 3 ; V_153 ++ ) {
int V_159 ;
V_159 = F_96 ( & V_42 -> V_142 -> V_146 ,
V_157 + 1 , & V_154 [ 1 ] , 3 ) ;
if ( V_159 == 3 )
break;
}
V_155 = F_92 ( & V_42 -> V_142 -> V_146 ,
V_157 , V_154 , 8 ) ;
if ( V_155 == 8 ) {
F_7 ( L_22 , V_154 [ 0 ] , V_154 [ 1 ] , V_154 [ 2 ] ) ;
goto V_158;
}
} else
V_68 = 0 ;
return V_68 ;
} else {
F_7 ( L_23 , V_68 ) ;
V_97 -> V_152 = false ;
F_93 ( & V_42 -> V_56 ,
V_97 -> V_152 ) ;
}
}
return - V_160 ;
}
static int F_97 ( struct V_161 * V_162 , void * V_163 )
{
struct V_164 * V_165 = (struct V_164 * ) V_162 -> V_166 ;
struct V_16 * V_17 = V_165 -> V_167 -> V_17 ;
struct V_48 * V_49 ;
struct V_42 * V_42 ;
struct V_96 * V_97 ;
int V_46 ;
F_46 ( V_17 ) ;
F_15 (connector, &dev->mode_config.connector_list, head) {
if ( V_49 -> V_168 != V_86 )
continue;
V_42 = F_16 ( V_49 ) ;
V_97 = V_42 -> V_98 ;
if ( V_42 -> V_51 )
continue;
if ( ! V_97 -> V_152 )
continue;
F_98 ( V_162 , & V_42 -> V_56 ) ;
for ( V_46 = 0 ; V_46 < V_42 -> V_59 ; V_46 ++ )
F_99 ( V_162 , L_24 , V_46 ,
V_42 -> V_58 [ V_46 ] . V_28 ,
V_42 -> V_58 [ V_46 ] . V_32 ) ;
}
F_48 ( V_17 ) ;
return 0 ;
}
int F_100 ( struct V_19 * V_20 )
{
#if F_101 ( V_169 )
return F_102 ( V_20 , V_170 , 1 ) ;
#endif
return 0 ;
}
