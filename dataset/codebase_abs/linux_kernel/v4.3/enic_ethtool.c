static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
int V_4 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_5 ; V_3 ++ ) {
V_4 = F_2 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] , V_2 ) ;
}
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_9 -> V_10 = ( V_11 | V_12 ) ;
V_9 -> V_13 = ( V_14 | V_15 ) ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
if ( F_6 ( V_7 ) ) {
F_7 ( V_9 , F_8 ( V_1 -> V_20 ) ) ;
V_9 -> V_21 = V_22 ;
} else {
F_7 ( V_9 , V_23 ) ;
V_9 -> V_21 = V_24 ;
}
V_9 -> V_25 = V_26 ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_29 * V_30 ;
int V_31 ;
V_31 = F_10 ( V_1 , & V_30 ) ;
if ( V_31 == - V_32 )
return;
F_11 ( V_28 -> V_33 , V_34 , sizeof( V_28 -> V_33 ) ) ;
F_11 ( V_28 -> V_35 , V_36 , sizeof( V_28 -> V_35 ) ) ;
F_11 ( V_28 -> V_37 , V_30 -> V_37 ,
sizeof( V_28 -> V_37 ) ) ;
F_11 ( V_28 -> V_38 , F_12 ( V_1 -> V_39 ) ,
sizeof( V_28 -> V_38 ) ) ;
}
static void F_13 ( struct V_6 * V_7 , T_1 V_40 ,
T_2 * V_41 )
{
unsigned int V_3 ;
switch ( V_40 ) {
case V_42 :
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
memcpy ( V_41 , V_44 [ V_3 ] . V_45 , V_46 ) ;
V_41 += V_46 ;
}
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
memcpy ( V_41 , V_48 [ V_3 ] . V_45 , V_46 ) ;
V_41 += V_46 ;
}
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ ) {
memcpy ( V_41 , V_50 [ V_3 ] . V_45 , V_46 ) ;
V_41 += V_46 ;
}
break;
}
}
static int F_14 ( struct V_6 * V_7 , int V_51 )
{
switch ( V_51 ) {
case V_42 :
return V_43 + V_47 + V_49 ;
default:
return - V_52 ;
}
}
static void F_15 ( struct V_6 * V_7 ,
struct V_53 * V_54 , T_3 * V_41 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_55 * V_56 ;
unsigned int V_3 ;
int V_31 ;
V_31 = F_16 ( V_1 , & V_56 ) ;
if ( V_31 == - V_32 )
return;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
* ( V_41 ++ ) = ( ( T_3 * ) & V_56 -> V_57 ) [ V_44 [ V_3 ] . V_58 ] ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ )
* ( V_41 ++ ) = ( ( T_3 * ) & V_56 -> V_59 ) [ V_48 [ V_3 ] . V_58 ] ;
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ )
* ( V_41 ++ ) = ( ( T_3 * ) & V_1 -> V_60 ) [ V_50 [ V_3 ] . V_58 ] ;
}
static T_1 F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
return V_1 -> V_61 ;
}
static void F_18 ( struct V_6 * V_7 , T_1 V_62 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_1 -> V_61 = V_62 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_63 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_64 * V_65 = & V_1 -> V_66 ;
if ( F_20 ( V_1 -> V_20 ) == V_67 )
V_9 -> V_68 = V_1 -> V_68 ;
V_9 -> V_69 = V_1 -> V_69 ;
if ( V_65 -> V_70 )
V_9 -> V_70 = 1 ;
V_9 -> V_71 = V_65 -> V_72 ;
V_9 -> V_73 = V_65 -> V_74 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_63 * V_75 )
{
T_1 V_76 = F_22 ( V_1 -> V_20 ) ;
T_1 V_73 = F_23 ( T_1 , V_76 ,
V_75 -> V_73 ) ;
T_1 V_71 = F_23 ( T_1 , V_76 ,
V_75 -> V_71 ) ;
if ( V_75 -> V_77 ||
V_75 -> V_78 ||
V_75 -> V_79 ||
V_75 -> V_80 ||
V_75 -> V_81 ||
V_75 -> V_82 ||
V_75 -> V_83 ||
V_75 -> V_84 ||
V_75 -> V_85 ||
V_75 -> V_86 ||
V_75 -> V_87 ||
V_75 -> V_88 ||
V_75 -> V_89 ||
V_75 -> V_90 ||
V_75 -> V_91 ||
V_75 -> V_92 ||
V_75 -> V_93 )
return - V_94 ;
if ( ( F_20 ( V_1 -> V_20 ) != V_67 ) &&
V_75 -> V_68 )
return - V_94 ;
if ( ( V_75 -> V_68 > V_76 ) ||
( V_75 -> V_69 > V_76 ) ||
( V_75 -> V_71 > V_76 ) ||
( V_75 -> V_73 > V_76 ) )
F_24 ( V_1 -> V_7 , L_1 ,
V_76 ) ;
if ( V_75 -> V_73 &&
( V_73 <
V_71 + V_95 ) )
return - V_94 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_63 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
T_1 V_68 ;
T_1 V_69 ;
T_1 V_71 ;
T_1 V_73 ;
T_1 V_76 ;
unsigned int V_3 , V_4 ;
int V_96 ;
struct V_64 * V_65 = & V_1 -> V_66 ;
V_96 = F_21 ( V_1 , V_9 ) ;
if ( V_96 )
return V_96 ;
V_76 = F_22 ( V_1 -> V_20 ) ;
V_68 = F_23 ( T_1 , V_9 -> V_68 ,
V_76 ) ;
V_69 = F_23 ( T_1 , V_9 -> V_69 ,
V_76 ) ;
V_71 = F_23 ( T_1 , V_9 -> V_71 ,
V_76 ) ;
V_73 = F_23 ( T_1 , V_9 -> V_73 ,
V_76 ) ;
if ( F_20 ( V_1 -> V_20 ) == V_67 ) {
for ( V_3 = 0 ; V_3 < V_1 -> V_97 ; V_3 ++ ) {
V_4 = F_26 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_68 ) ;
}
V_1 -> V_68 = V_68 ;
}
V_65 -> V_70 = ! ! V_9 -> V_70 ;
if ( ! V_65 -> V_70 )
F_1 ( V_1 , V_69 ) ;
if ( V_9 -> V_73 ) {
V_65 -> V_74 = V_73 ;
V_65 -> V_72 = V_71 ;
V_65 -> V_98 = V_71 +
V_95 ;
}
V_1 -> V_69 = V_69 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 , struct V_99 * V_100 ,
T_1 * V_101 )
{
int V_102 , V_96 = 0 , V_103 = 0 ;
V_100 -> V_41 = V_1 -> V_104 . V_105 - V_1 -> V_104 . free ;
for ( V_102 = 0 ; V_102 < ( 1 << V_106 ) ; V_102 ++ ) {
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
V_108 = & V_1 -> V_104 . V_113 [ V_102 ] ;
F_28 (n, tmp, hhead, node) {
if ( V_103 == V_100 -> V_114 )
return - V_115 ;
V_101 [ V_103 ] = V_112 -> V_116 ;
V_103 ++ ;
}
}
V_100 -> V_114 = V_103 ;
return V_96 ;
}
static int F_29 ( struct V_1 * V_1 , struct V_99 * V_100 )
{
struct V_117 * V_118 =
(struct V_117 * ) & V_100 -> V_119 ;
struct V_111 * V_112 ;
V_112 = F_30 ( V_1 , ( V_120 ) V_118 -> V_121 ) ;
if ( ! V_112 )
return - V_94 ;
switch ( V_112 -> V_122 . V_123 . V_124 ) {
case V_125 :
V_118 -> V_126 = V_127 ;
break;
case V_128 :
V_118 -> V_126 = V_129 ;
break;
default:
return - V_94 ;
break;
}
V_118 -> V_130 . V_131 . V_132 = F_31 ( & V_112 -> V_122 ) ;
V_118 -> V_133 . V_131 . V_132 = ( V_134 ) ~ 0 ;
V_118 -> V_130 . V_131 . V_135 = F_32 ( & V_112 -> V_122 ) ;
V_118 -> V_133 . V_131 . V_135 = ( V_134 ) ~ 0 ;
V_118 -> V_130 . V_131 . V_136 = V_112 -> V_122 . V_137 . V_138 ;
V_118 -> V_133 . V_131 . V_136 = ( V_139 ) ~ 0 ;
V_118 -> V_130 . V_131 . V_140 = V_112 -> V_122 . V_137 . V_141 ;
V_118 -> V_133 . V_131 . V_140 = ( V_139 ) ~ 0 ;
V_118 -> V_142 = V_112 -> V_143 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_144 , struct V_99 * V_100 ,
T_1 * V_101 )
{
struct V_1 * V_1 = F_5 ( V_144 ) ;
int V_96 = 0 ;
switch ( V_100 -> V_100 ) {
case V_145 :
V_100 -> V_41 = V_1 -> V_5 ;
break;
case V_146 :
F_34 ( & V_1 -> V_104 . V_147 ) ;
V_100 -> V_114 = V_1 -> V_104 . V_105 - V_1 -> V_104 . free ;
V_100 -> V_41 = V_1 -> V_104 . V_105 ;
F_35 ( & V_1 -> V_104 . V_147 ) ;
break;
case V_148 :
F_34 ( & V_1 -> V_104 . V_147 ) ;
V_96 = F_27 ( V_1 , V_100 , V_101 ) ;
F_35 ( & V_1 -> V_104 . V_147 ) ;
break;
case V_149 :
F_34 ( & V_1 -> V_104 . V_147 ) ;
V_96 = F_29 ( V_1 , V_100 ) ;
F_35 ( & V_1 -> V_104 . V_147 ) ;
break;
default:
V_96 = - V_52 ;
break;
}
return V_96 ;
}
static int F_36 ( struct V_6 * V_144 ,
const struct V_150 * V_151 , void * V_41 )
{
struct V_1 * V_1 = F_5 ( V_144 ) ;
int V_96 = 0 ;
switch ( V_151 -> V_152 ) {
case V_153 :
* ( T_1 * ) V_41 = V_1 -> V_154 ;
break;
default:
V_96 = - V_94 ;
break;
}
return V_96 ;
}
static int F_37 ( struct V_6 * V_144 ,
const struct V_150 * V_151 ,
const void * V_41 )
{
struct V_1 * V_1 = F_5 ( V_144 ) ;
int V_96 = 0 ;
switch ( V_151 -> V_152 ) {
case V_153 :
V_1 -> V_154 = * ( T_1 * ) V_41 ;
break;
default:
V_96 = - V_94 ;
break;
}
return V_96 ;
}
static T_1 F_38 ( struct V_6 * V_7 )
{
return V_155 ;
}
static int F_39 ( struct V_6 * V_7 , T_1 * V_156 , T_2 * V_157 ,
T_2 * V_158 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( V_157 )
memcpy ( V_157 , V_1 -> V_159 , V_155 ) ;
if ( V_158 )
* V_158 = V_160 ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 , const T_1 * V_156 ,
const T_2 * V_157 , const T_2 V_158 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( ( V_158 != V_161 && V_158 != V_160 ) ||
V_156 )
return - V_94 ;
if ( V_157 )
memcpy ( V_1 -> V_159 , V_157 , V_155 ) ;
return F_41 ( V_1 ) ;
}
void F_42 ( struct V_6 * V_7 )
{
V_7 -> V_162 = & V_163 ;
}
