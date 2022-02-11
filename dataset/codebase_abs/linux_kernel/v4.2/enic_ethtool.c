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
V_9 -> V_67 = V_1 -> V_67 ;
V_9 -> V_68 = V_1 -> V_68 ;
if ( V_65 -> V_69 )
V_9 -> V_69 = 1 ;
V_9 -> V_70 = V_65 -> V_71 ;
V_9 -> V_72 = V_65 -> V_73 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_63 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_70 ;
T_1 V_72 ;
T_1 V_74 ;
unsigned int V_3 , V_4 ;
struct V_64 * V_65 = & V_1 -> V_66 ;
V_74 = F_21 ( V_1 -> V_20 ) ;
V_67 = F_22 ( T_1 , V_9 -> V_67 ,
V_74 ) ;
V_68 = F_22 ( T_1 , V_9 -> V_68 ,
V_74 ) ;
V_70 = F_22 ( T_1 , V_9 -> V_70 ,
V_74 ) ;
V_72 = F_22 ( T_1 , V_9 -> V_72 ,
V_74 ) ;
switch ( F_23 ( V_1 -> V_20 ) ) {
case V_75 :
if ( V_67 != V_68 )
return - V_76 ;
if ( V_9 -> V_69 ||
V_9 -> V_70 ||
V_9 -> V_72 )
return - V_76 ;
V_4 = F_24 () ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_67 ) ;
break;
case V_77 :
if ( V_67 != V_68 )
return - V_76 ;
if ( V_9 -> V_69 ||
V_9 -> V_70 ||
V_9 -> V_72 )
return - V_76 ;
F_3 ( & V_1 -> V_4 [ 0 ] ,
V_67 ) ;
break;
case V_78 :
if ( V_9 -> V_72 &&
( V_72 <
V_70 + V_79 ) )
return - V_76 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_80 ; V_3 ++ ) {
V_4 = F_25 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_67 ) ;
}
V_65 -> V_69 =
! ! V_9 -> V_69 ;
if ( ! V_65 -> V_69 )
F_1 ( V_1 , V_68 ) ;
if ( V_9 -> V_72 ) {
V_65 -> V_73 = V_72 ;
V_65 -> V_71 = V_70 ;
V_65 -> V_81 = V_70 +
V_79 ;
}
break;
default:
break;
}
V_1 -> V_67 = V_67 ;
V_1 -> V_68 = V_68 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_82 * V_83 ,
T_1 * V_84 )
{
int V_85 , V_86 = 0 , V_87 = 0 ;
V_83 -> V_41 = V_1 -> V_88 . V_89 - V_1 -> V_88 . free ;
for ( V_85 = 0 ; V_85 < ( 1 << V_90 ) ; V_85 ++ ) {
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
V_92 = & V_1 -> V_88 . V_97 [ V_85 ] ;
F_27 (n, tmp, hhead, node) {
if ( V_87 == V_83 -> V_98 )
return - V_99 ;
V_84 [ V_87 ] = V_96 -> V_100 ;
V_87 ++ ;
}
}
V_83 -> V_98 = V_87 ;
return V_86 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
struct V_101 * V_102 =
(struct V_101 * ) & V_83 -> V_103 ;
struct V_95 * V_96 ;
V_96 = F_29 ( V_1 , ( V_104 ) V_102 -> V_105 ) ;
if ( ! V_96 )
return - V_76 ;
switch ( V_96 -> V_106 . V_107 . V_108 ) {
case V_109 :
V_102 -> V_110 = V_111 ;
break;
case V_112 :
V_102 -> V_110 = V_113 ;
break;
default:
return - V_76 ;
break;
}
V_102 -> V_114 . V_115 . V_116 = F_30 ( & V_96 -> V_106 ) ;
V_102 -> V_117 . V_115 . V_116 = ( V_118 ) ~ 0 ;
V_102 -> V_114 . V_115 . V_119 = F_31 ( & V_96 -> V_106 ) ;
V_102 -> V_117 . V_115 . V_119 = ( V_118 ) ~ 0 ;
V_102 -> V_114 . V_115 . V_120 = V_96 -> V_106 . V_121 . V_122 ;
V_102 -> V_117 . V_115 . V_120 = ( V_123 ) ~ 0 ;
V_102 -> V_114 . V_115 . V_124 = V_96 -> V_106 . V_121 . V_125 ;
V_102 -> V_117 . V_115 . V_124 = ( V_123 ) ~ 0 ;
V_102 -> V_126 = V_96 -> V_127 ;
return 0 ;
}
static int F_32 ( struct V_6 * V_128 , struct V_82 * V_83 ,
T_1 * V_84 )
{
struct V_1 * V_1 = F_5 ( V_128 ) ;
int V_86 = 0 ;
switch ( V_83 -> V_83 ) {
case V_129 :
V_83 -> V_41 = V_1 -> V_5 ;
break;
case V_130 :
F_33 ( & V_1 -> V_88 . V_131 ) ;
V_83 -> V_98 = V_1 -> V_88 . V_89 - V_1 -> V_88 . free ;
V_83 -> V_41 = V_1 -> V_88 . V_89 ;
F_34 ( & V_1 -> V_88 . V_131 ) ;
break;
case V_132 :
F_33 ( & V_1 -> V_88 . V_131 ) ;
V_86 = F_26 ( V_1 , V_83 , V_84 ) ;
F_34 ( & V_1 -> V_88 . V_131 ) ;
break;
case V_133 :
F_33 ( & V_1 -> V_88 . V_131 ) ;
V_86 = F_28 ( V_1 , V_83 ) ;
F_34 ( & V_1 -> V_88 . V_131 ) ;
break;
default:
V_86 = - V_52 ;
break;
}
return V_86 ;
}
static int F_35 ( struct V_6 * V_128 ,
const struct V_134 * V_135 , void * V_41 )
{
struct V_1 * V_1 = F_5 ( V_128 ) ;
int V_86 = 0 ;
switch ( V_135 -> V_136 ) {
case V_137 :
* ( T_1 * ) V_41 = V_1 -> V_138 ;
break;
default:
V_86 = - V_76 ;
break;
}
return V_86 ;
}
static int F_36 ( struct V_6 * V_128 ,
const struct V_134 * V_135 ,
const void * V_41 )
{
struct V_1 * V_1 = F_5 ( V_128 ) ;
int V_86 = 0 ;
switch ( V_135 -> V_136 ) {
case V_137 :
V_1 -> V_138 = * ( T_1 * ) V_41 ;
break;
default:
V_86 = - V_76 ;
break;
}
return V_86 ;
}
static T_1 F_37 ( struct V_6 * V_7 )
{
return V_139 ;
}
static int F_38 ( struct V_6 * V_7 , T_1 * V_140 , T_2 * V_141 ,
T_2 * V_142 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( V_141 )
memcpy ( V_141 , V_1 -> V_143 , V_139 ) ;
if ( V_142 )
* V_142 = V_144 ;
return 0 ;
}
static int F_39 ( struct V_6 * V_7 , const T_1 * V_140 ,
const T_2 * V_141 , const T_2 V_142 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( ( V_142 != V_145 && V_142 != V_144 ) ||
V_140 )
return - V_76 ;
if ( V_141 )
memcpy ( V_1 -> V_143 , V_141 , V_139 ) ;
return F_40 ( V_1 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
V_7 -> V_146 = & V_147 ;
}
