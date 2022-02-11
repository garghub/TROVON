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
F_10 ( V_1 , & V_30 ) ;
F_11 ( V_28 -> V_31 , V_32 , sizeof( V_28 -> V_31 ) ) ;
F_11 ( V_28 -> V_33 , V_34 , sizeof( V_28 -> V_33 ) ) ;
F_11 ( V_28 -> V_35 , V_30 -> V_35 ,
sizeof( V_28 -> V_35 ) ) ;
F_11 ( V_28 -> V_36 , F_12 ( V_1 -> V_37 ) ,
sizeof( V_28 -> V_36 ) ) ;
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
F_16 ( V_1 , & V_54 ) ;
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
V_9 -> V_65 = V_1 -> V_65 ;
V_9 -> V_66 = V_1 -> V_66 ;
if ( V_63 -> V_67 )
V_9 -> V_67 = 1 ;
V_9 -> V_68 = V_63 -> V_69 ;
V_9 -> V_70 = V_63 -> V_71 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_61 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_68 ;
T_1 V_70 ;
T_1 V_72 ;
unsigned int V_3 , V_4 ;
struct V_62 * V_63 = & V_1 -> V_64 ;
V_72 = F_21 ( V_1 -> V_20 ) ;
V_65 = F_22 ( T_1 , V_9 -> V_65 ,
V_72 ) ;
V_66 = F_22 ( T_1 , V_9 -> V_66 ,
V_72 ) ;
V_68 = F_22 ( T_1 , V_9 -> V_68 ,
V_72 ) ;
V_70 = F_22 ( T_1 , V_9 -> V_70 ,
V_72 ) ;
switch ( F_23 ( V_1 -> V_20 ) ) {
case V_73 :
if ( V_65 != V_66 )
return - V_74 ;
if ( V_9 -> V_67 ||
V_9 -> V_68 ||
V_9 -> V_70 )
return - V_74 ;
V_4 = F_24 () ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_65 ) ;
break;
case V_75 :
if ( V_65 != V_66 )
return - V_74 ;
if ( V_9 -> V_67 ||
V_9 -> V_68 ||
V_9 -> V_70 )
return - V_74 ;
F_3 ( & V_1 -> V_4 [ 0 ] ,
V_65 ) ;
break;
case V_76 :
if ( V_9 -> V_70 &&
( V_70 <
V_68 + V_77 ) )
return - V_74 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_78 ; V_3 ++ ) {
V_4 = F_25 ( V_1 , V_3 ) ;
F_3 ( & V_1 -> V_4 [ V_4 ] ,
V_65 ) ;
}
V_63 -> V_67 =
! ! V_9 -> V_67 ;
if ( ! V_63 -> V_67 )
F_1 ( V_1 , V_66 ) ;
if ( V_9 -> V_70 ) {
V_63 -> V_71 = V_70 ;
V_63 -> V_69 = V_68 ;
V_63 -> V_79 = V_68 +
V_77 ;
}
break;
default:
break;
}
V_1 -> V_65 = V_65 ;
V_1 -> V_66 = V_66 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_80 * V_81 ,
T_1 * V_82 )
{
int V_83 , V_84 = 0 , V_85 = 0 ;
V_81 -> V_39 = V_1 -> V_86 . V_87 - V_1 -> V_86 . free ;
for ( V_83 = 0 ; V_83 < ( 1 << V_88 ) ; V_83 ++ ) {
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
V_90 = & V_1 -> V_86 . V_95 [ V_83 ] ;
F_27 (n, tmp, hhead, node) {
if ( V_85 == V_81 -> V_96 )
return - V_97 ;
V_82 [ V_85 ] = V_94 -> V_98 ;
V_85 ++ ;
}
}
V_81 -> V_96 = V_85 ;
return V_84 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_80 * V_81 )
{
struct V_99 * V_100 =
(struct V_99 * ) & V_81 -> V_101 ;
struct V_93 * V_94 ;
V_94 = F_29 ( V_1 , ( V_102 ) V_100 -> V_103 ) ;
if ( ! V_94 )
return - V_74 ;
switch ( V_94 -> V_104 . V_105 ) {
case V_106 :
V_100 -> V_107 = V_108 ;
break;
case V_109 :
V_100 -> V_107 = V_110 ;
break;
default:
return - V_74 ;
break;
}
V_100 -> V_111 . V_112 . V_113 = V_94 -> V_104 . V_114 ;
V_100 -> V_115 . V_112 . V_113 = ( V_116 ) ~ 0 ;
V_100 -> V_111 . V_112 . V_117 = V_94 -> V_104 . V_118 ;
V_100 -> V_115 . V_112 . V_117 = ( V_116 ) ~ 0 ;
V_100 -> V_111 . V_112 . V_119 = V_94 -> V_104 . V_120 [ 0 ] ;
V_100 -> V_115 . V_112 . V_119 = ( V_121 ) ~ 0 ;
V_100 -> V_111 . V_112 . V_122 = V_94 -> V_104 . V_120 [ 1 ] ;
V_100 -> V_115 . V_112 . V_122 = ( V_121 ) ~ 0 ;
V_100 -> V_123 = V_94 -> V_124 ;
return 0 ;
}
static int F_30 ( struct V_6 * V_125 , struct V_80 * V_81 ,
T_1 * V_82 )
{
struct V_1 * V_1 = F_5 ( V_125 ) ;
int V_84 = 0 ;
switch ( V_81 -> V_81 ) {
case V_126 :
V_81 -> V_39 = V_1 -> V_5 ;
break;
case V_127 :
F_31 ( & V_1 -> V_86 . V_128 ) ;
V_81 -> V_96 = V_1 -> V_86 . V_87 - V_1 -> V_86 . free ;
V_81 -> V_39 = V_1 -> V_86 . V_87 ;
F_32 ( & V_1 -> V_86 . V_128 ) ;
break;
case V_129 :
F_31 ( & V_1 -> V_86 . V_128 ) ;
V_84 = F_26 ( V_1 , V_81 , V_82 ) ;
F_32 ( & V_1 -> V_86 . V_128 ) ;
break;
case V_130 :
F_31 ( & V_1 -> V_86 . V_128 ) ;
V_84 = F_28 ( V_1 , V_81 ) ;
F_32 ( & V_1 -> V_86 . V_128 ) ;
break;
default:
V_84 = - V_50 ;
break;
}
return V_84 ;
}
static int F_33 ( struct V_6 * V_125 ,
const struct V_131 * V_132 , void * V_39 )
{
struct V_1 * V_1 = F_5 ( V_125 ) ;
int V_84 = 0 ;
switch ( V_132 -> V_133 ) {
case V_134 :
* ( T_1 * ) V_39 = V_1 -> V_135 ;
break;
default:
V_84 = - V_74 ;
break;
}
return V_84 ;
}
static int F_34 ( struct V_6 * V_125 ,
const struct V_131 * V_132 ,
const void * V_39 )
{
struct V_1 * V_1 = F_5 ( V_125 ) ;
int V_84 = 0 ;
switch ( V_132 -> V_133 ) {
case V_134 :
V_1 -> V_135 = * ( T_1 * ) V_39 ;
break;
default:
V_84 = - V_74 ;
break;
}
return V_84 ;
}
static T_1 F_35 ( struct V_6 * V_7 )
{
return V_136 ;
}
static int F_36 ( struct V_6 * V_7 , T_1 * V_137 , T_2 * V_138 ,
T_2 * V_139 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( V_138 )
memcpy ( V_138 , V_1 -> V_140 , V_136 ) ;
if ( V_139 )
* V_139 = V_141 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , const T_1 * V_137 ,
const T_2 * V_138 , const T_2 V_139 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
if ( ( V_139 != V_142 && V_139 != V_141 ) ||
V_137 )
return - V_74 ;
if ( V_138 )
memcpy ( V_1 -> V_140 , V_138 , V_136 ) ;
return F_38 ( V_1 ) ;
}
void F_39 ( struct V_6 * V_7 )
{
V_7 -> V_143 = & V_144 ;
}
