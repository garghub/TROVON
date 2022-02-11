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
struct V_10 * V_11 = & V_9 -> V_11 ;
F_6 ( V_9 , V_12 ,
10000baseT_Full ) ;
F_6 ( V_9 , V_12 , V_13 ) ;
F_6 ( V_9 , V_14 ,
10000baseT_Full ) ;
F_6 ( V_9 , V_14 , V_13 ) ;
V_11 -> V_15 = V_16 ;
if ( F_7 ( V_7 ) ) {
V_11 -> V_17 = F_8 ( V_1 -> V_18 ) ;
V_11 -> V_19 = V_20 ;
} else {
V_11 -> V_17 = V_21 ;
V_11 -> V_19 = V_22 ;
}
V_11 -> V_23 = V_24 ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_25 * V_26 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_27 * V_28 ;
int V_29 ;
V_29 = F_10 ( V_1 , & V_28 ) ;
if ( V_29 == - V_30 )
return;
F_11 ( V_26 -> V_31 , V_32 , sizeof( V_26 -> V_31 ) ) ;
F_11 ( V_26 -> V_33 , V_34 , sizeof( V_26 -> V_33 ) ) ;
F_11 ( V_26 -> V_35 , V_28 -> V_35 ,
sizeof( V_26 -> V_35 ) ) ;
F_11 ( V_26 -> V_36 , F_12 ( V_1 -> V_37 ) ,
sizeof( V_26 -> V_36 ) ) ;
}
static void F_13 ( struct V_6 * V_7 , T_1 V_38 ,
T_2 * V_39 )
{
unsigned int V_3 ;
switch ( V_38 ) {
case V_40 :
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ ) {
memcpy ( V_39 , V_42 [ V_3 ] . V_43 , V_44 ) ;
V_39 += V_44 ;
}
for ( V_3 = 0 ; V_3 < V_45 ; V_3 ++ ) {
memcpy ( V_39 , V_46 [ V_3 ] . V_43 , V_44 ) ;
V_39 += V_44 ;
}
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
memcpy ( V_39 , V_48 [ V_3 ] . V_43 , V_44 ) ;
V_39 += V_44 ;
}
break;
}
}
static int F_14 ( struct V_6 * V_7 , int V_49 )
{
switch ( V_49 ) {
case V_40 :
return V_41 + V_45 + V_47 ;
default:
return - V_50 ;
}
}
static void F_15 ( struct V_6 * V_7 ,
struct V_51 * V_52 , T_3 * V_39 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_53 * V_54 ;
unsigned int V_3 ;
int V_29 ;
V_29 = F_16 ( V_1 , & V_54 ) ;
if ( V_29 == - V_30 )
return;
for ( V_3 = 0 ; V_3 < V_41 ; V_3 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_54 -> V_55 ) [ V_42 [ V_3 ] . V_56 ] ;
for ( V_3 = 0 ; V_3 < V_45 ; V_3 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_54 -> V_57 ) [ V_46 [ V_3 ] . V_56 ] ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ )
* ( V_39 ++ ) = ( ( T_3 * ) & V_1 -> V_58 ) [ V_48 [ V_3 ] . V_56 ] ;
}
static T_1 F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
return V_1 -> V_59 ;
}
static void F_18 ( struct V_6 * V_7 , T_1 V_60 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
V_1 -> V_59 = V_60 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_61 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_62 * V_63 = & V_1 -> V_64 ;
if ( F_20 ( V_1 -> V_18 ) == V_65 )
V_9 -> V_66 = V_1 -> V_66 ;
V_9 -> V_67 = V_1 -> V_67 ;
if ( V_63 -> V_68 )
V_9 -> V_68 = 1 ;
V_9 -> V_69 = V_63 -> V_70 ;
V_9 -> V_71 = V_63 -> V_72 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_61 * V_73 )
{
T_1 V_74 = F_22 ( V_1 -> V_18 ) ;
T_1 V_71 = F_23 ( T_1 , V_74 ,
V_73 -> V_71 ) ;
T_1 V_69 = F_23 ( T_1 , V_74 ,
V_73 -> V_69 ) ;
if ( V_73 -> V_75 ||
V_73 -> V_76 ||
V_73 -> V_77 ||
V_73 -> V_78 ||
V_73 -> V_79 ||
V_73 -> V_80 ||
V_73 -> V_81 ||
V_73 -> V_82 ||
V_73 -> V_83 ||
V_73 -> V_84 ||
V_73 -> V_85 ||
V_73 -> V_86 ||
V_73 -> V_87 ||
V_73 -> V_88 ||
V_73 -> V_89 ||
V_73 -> V_90 ||
V_73 -> V_91 )
return - V_92 ;
if ( ( F_20 ( V_1 -> V_18 ) != V_65 ) &&
V_73 -> V_66 )
return - V_92 ;
if ( ( V_73 -> V_66 > V_74 ) ||
( V_73 -> V_67 > V_74 ) ||
( V_73 -> V_69 > V_74 ) ||
( V_73 -> V_71 > V_74 ) )
F_24 ( V_1 -> V_7 , L_1 ,
V_74 ) ;
if ( V_73 -> V_71 &&
( V_71 <
V_69 + V_93 ) )
return - V_92 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_61 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_69 ;
T_1 V_71 ;
T_1 V_74 ;
unsigned int V_3 , V_4 ;
int V_94 ;
struct V_62 * V_63 = & V_1 -> V_64 ;
V_94 = F_21 ( V_1 , V_9 ) ;
if ( V_94 )
return V_94 ;
V_74 = F_22 ( V_1 -> V_18 ) ;
V_66 = F_23 ( T_1 , V_9 -> V_66 ,
V_74 ) ;
V_67 = F_23 ( T_1 , V_9 -> V_67 ,
V_74 ) ;
V_69 = F_23 ( T_1 , V_9 -> V_69 ,
V_74 ) ;
V_71 = F_23 ( T_1 , V_9 -> V_71 ,
V_74 ) ;
if ( F_20 ( V_1 -> V_18 ) == V_65 ) {
for ( V_3 = 0 ; V_3 < V_1 -> V_95 ; V_3 ++ ) {
V_4 = F_26 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_66 ) ;
}
V_1 -> V_66 = V_66 ;
}
V_63 -> V_68 = ! ! V_9 -> V_68 ;
if ( ! V_63 -> V_68 )
F_1 ( V_1 , V_67 ) ;
if ( V_9 -> V_71 ) {
V_63 -> V_72 = V_71 ;
V_63 -> V_70 = V_69 ;
V_63 -> V_96 = V_69 +
V_93 ;
}
V_1 -> V_67 = V_67 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 , struct V_97 * V_98 ,
T_1 * V_99 )
{
int V_100 , V_94 = 0 , V_101 = 0 ;
V_98 -> V_39 = V_1 -> V_102 . V_103 - V_1 -> V_102 . free ;
for ( V_100 = 0 ; V_100 < ( 1 << V_104 ) ; V_100 ++ ) {
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
V_106 = & V_1 -> V_102 . V_111 [ V_100 ] ;
F_28 (n, tmp, hhead, node) {
if ( V_101 == V_98 -> V_112 )
return - V_113 ;
V_99 [ V_101 ] = V_110 -> V_114 ;
V_101 ++ ;
}
}
V_98 -> V_112 = V_101 ;
return V_94 ;
}
static int F_29 ( struct V_1 * V_1 , struct V_97 * V_98 )
{
struct V_115 * V_116 =
(struct V_115 * ) & V_98 -> V_117 ;
struct V_109 * V_110 ;
V_110 = F_30 ( V_1 , ( V_118 ) V_116 -> V_119 ) ;
if ( ! V_110 )
return - V_92 ;
switch ( V_110 -> V_120 . V_121 . V_122 ) {
case V_123 :
V_116 -> V_124 = V_125 ;
break;
case V_126 :
V_116 -> V_124 = V_127 ;
break;
default:
return - V_92 ;
break;
}
V_116 -> V_128 . V_129 . V_130 = F_31 ( & V_110 -> V_120 ) ;
V_116 -> V_131 . V_129 . V_130 = ( V_132 ) ~ 0 ;
V_116 -> V_128 . V_129 . V_133 = F_32 ( & V_110 -> V_120 ) ;
V_116 -> V_131 . V_129 . V_133 = ( V_132 ) ~ 0 ;
V_116 -> V_128 . V_129 . V_134 = V_110 -> V_120 . V_135 . V_136 ;
V_116 -> V_131 . V_129 . V_134 = ( V_137 ) ~ 0 ;
V_116 -> V_128 . V_129 . V_138 = V_110 -> V_120 . V_135 . V_139 ;
V_116 -> V_131 . V_129 . V_138 = ( V_137 ) ~ 0 ;
V_116 -> V_140 = V_110 -> V_141 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_142 , struct V_97 * V_98 ,
T_1 * V_99 )
{
struct V_1 * V_1 = F_5 ( V_142 ) ;
int V_94 = 0 ;
switch ( V_98 -> V_98 ) {
case V_143 :
V_98 -> V_39 = V_1 -> V_5 ;
break;
case V_144 :
F_34 ( & V_1 -> V_102 . V_145 ) ;
V_98 -> V_112 = V_1 -> V_102 . V_103 - V_1 -> V_102 . free ;
V_98 -> V_39 = V_1 -> V_102 . V_103 ;
F_35 ( & V_1 -> V_102 . V_145 ) ;
break;
case V_146 :
F_34 ( & V_1 -> V_102 . V_145 ) ;
V_94 = F_27 ( V_1 , V_98 , V_99 ) ;
F_35 ( & V_1 -> V_102 . V_145 ) ;
break;
case V_147 :
F_34 ( & V_1 -> V_102 . V_145 ) ;
V_94 = F_29 ( V_1 , V_98 ) ;
F_35 ( & V_1 -> V_102 . V_145 ) ;
break;
default:
V_94 = - V_50 ;
break;
}
return V_94 ;
}
static int F_36 ( struct V_6 * V_142 ,
const struct V_148 * V_149 , void * V_39 )
{
struct V_1 * V_1 = F_5 ( V_142 ) ;
int V_94 = 0 ;
switch ( V_149 -> V_150 ) {
case V_151 :
* ( T_1 * ) V_39 = V_1 -> V_152 ;
break;
default:
V_94 = - V_92 ;
break;
}
return V_94 ;
}
static int F_37 ( struct V_6 * V_142 ,
const struct V_148 * V_149 ,
const void * V_39 )
{
struct V_1 * V_1 = F_5 ( V_142 ) ;
int V_94 = 0 ;
switch ( V_149 -> V_150 ) {
case V_151 :
V_1 -> V_152 = * ( T_1 * ) V_39 ;
break;
default:
V_94 = - V_92 ;
break;
}
return V_94 ;
}
static T_1 F_38 ( struct V_6 * V_7 )
{
return V_153 ;
}
static int F_39 ( struct V_6 * V_7 , T_1 * V_154 , T_2 * V_155 ,
T_2 * V_156 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( V_155 )
memcpy ( V_155 , V_1 -> V_157 , V_153 ) ;
if ( V_156 )
* V_156 = V_158 ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 , const T_1 * V_154 ,
const T_2 * V_155 , const T_2 V_156 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( ( V_156 != V_159 && V_156 != V_158 ) ||
V_154 )
return - V_92 ;
if ( V_155 )
memcpy ( V_1 -> V_157 , V_155 , V_153 ) ;
return F_41 ( V_1 ) ;
}
void F_42 ( struct V_6 * V_7 )
{
V_7 -> V_160 = & V_161 ;
}
