static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 , T_1 V_6 )
{
int V_7 , V_8 ;
struct V_1 * V_9 ;
T_2 V_10 = 0 ;
T_3 V_11 ;
V_9 = F_2 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_9 ) {
F_3 ( V_3 , L_1 ) ;
return NULL ;
}
F_4 ( & V_3 -> V_13 ) ;
if ( V_3 -> V_14 == V_15 )
V_8 = V_16 ;
else if ( V_5 && V_5 -> V_17 && V_5 -> V_17 -> V_18 )
V_8 = V_16 ;
else
V_8 = V_19 ;
if ( V_8 >= V_20 && V_8 <= V_21 )
V_10 |= V_22 ;
V_10 |= F_5 ( V_3 -> V_23 . V_24 ) <<
V_25 ;
V_11 = F_6 ( V_26 [ V_8 ] . V_27 , V_10 ) ;
for ( V_7 = 0 ; V_7 < V_28 ; V_7 ++ )
V_9 -> V_29 [ V_7 ] . V_11 = V_11 ;
V_9 -> V_30 . V_31 =
F_5 ( V_3 -> V_23 . V_24 ) ;
V_9 -> V_30 . V_32 =
V_3 -> V_23 . V_24 &
~ F_5 ( V_3 -> V_23 . V_24 ) ;
if ( ! V_9 -> V_30 . V_32 ) {
V_9 -> V_30 . V_32 = V_33 ;
} else if ( F_7 ( V_3 -> V_23 . V_24 ) == 2 ) {
V_9 -> V_30 . V_32 =
V_3 -> V_23 . V_24 ;
}
V_9 -> V_34 . V_35 = V_36 ;
V_9 -> V_34 . V_37 =
F_8 ( V_38 ) ;
V_9 -> V_6 = V_6 ;
return V_9 ;
}
int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const T_1 * V_39 , T_1 * V_40 )
{
int V_41 ;
T_1 V_6 ;
struct V_1 * V_9 ;
unsigned long V_42 ;
if ( V_40 )
* V_40 = V_43 ;
V_41 = F_10 ( V_3 , V_5 , V_39 , 0 , NULL , & V_6 ) ;
if ( V_41 ) {
F_3 ( V_3 , L_2 , V_39 ) ;
return V_41 ;
}
if ( V_40 )
* V_40 = V_6 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_46 |= V_47 ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_9 ) {
F_3 ( V_3 , L_3 ,
V_39 ) ;
return - V_48 ;
}
V_41 = F_13 ( V_3 , V_5 , V_9 , V_49 , true ) ;
if ( V_41 )
F_3 ( V_3 , L_4 , V_41 ) ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_50 = V_9 ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_51 )
{
int V_7 , V_52 = 0 ;
T_1 V_53 [ sizeof( struct V_54 ) +
sizeof( struct V_55 ) * V_56 ] ;
struct V_54 * V_57 = (struct V_54 * ) V_53 ;
T_4 V_58 = sizeof( struct V_54 ) ;
struct V_59 V_60 = {
. V_61 = V_5 -> V_62 ,
. V_63 = { V_57 , } ,
. V_42 = V_49 ,
} ;
F_15 () ;
memset ( V_57 , 0 , V_58 +
( sizeof( struct V_55 ) * V_56 ) ) ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
V_57 -> V_64 [ V_7 ] . V_65 = V_7 ;
if ( V_5 -> V_66 [ V_7 ] . V_67 ) {
V_57 -> V_64 [ V_7 ] . V_68 = V_7 ;
V_52 = 1 ;
} else {
V_57 -> V_64 [ V_7 ] . V_68 = V_69 ;
}
V_57 -> V_64 [ V_7 ] . V_67 = V_5 -> V_66 [ V_7 ] . V_67 ;
memcpy ( & V_57 -> V_64 [ V_7 ] . V_64 [ 3 ] , V_5 -> V_66 [ V_7 ] . V_64 ,
V_5 -> V_66 [ V_7 ] . V_67 ) ;
}
V_57 -> V_70 = V_71 ;
V_57 -> V_72 = V_56 ;
V_58 += sizeof( struct V_55 ) * V_56 ;
V_60 . V_73 [ 0 ] = V_58 ;
if ( V_52 || V_51 )
return F_16 ( & V_3 -> V_74 , & V_60 ) ;
else
return 0 ;
}
int F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_4 ( & V_3 -> V_13 ) ;
return F_14 ( V_3 , V_5 , false ) ;
}
int F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_75 * V_76 )
{
int V_41 ;
F_4 ( & V_3 -> V_13 ) ;
F_19 ( V_3 , L_5 ,
V_76 -> V_77 ) ;
memset ( & V_5 -> V_66 [ V_76 -> V_77 ] , 0 , sizeof( V_5 -> V_66 [ 0 ] ) ) ;
if ( F_20 ( V_3 ) ) {
F_19 ( V_3 , L_6 ) ;
return 0 ;
}
V_41 = F_14 ( V_3 , V_5 , 1 ) ;
F_19 ( V_3 , L_7 ,
V_76 -> V_77 , V_41 ) ;
return V_41 ;
}
int F_21 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_75 * V_76 )
{
int V_41 ;
F_4 ( & V_3 -> V_13 ) ;
if ( V_76 -> V_78 != V_79 &&
V_76 -> V_78 != V_80 ) {
F_19 ( V_3 , L_8 , V_76 -> V_78 ) ;
return - V_81 ;
}
V_76 -> V_82 = V_83 ;
V_5 -> V_66 [ V_76 -> V_77 ] . V_67 = V_76 -> V_78 ;
memcpy ( & V_5 -> V_66 [ V_76 -> V_77 ] . V_64 , & V_76 -> V_64 ,
V_76 -> V_78 ) ;
V_41 = F_14 ( V_3 , V_5 , false ) ;
F_19 ( V_3 , L_9 ,
V_76 -> V_78 , V_76 -> V_77 , V_41 ) ;
return V_41 ;
}
static T_1 F_22 ( struct V_2 * V_3 ,
struct V_84 * V_17 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 = ( void * ) V_17 -> V_89 ;
T_1 V_6 = V_43 ;
if ( V_86 )
V_6 = F_23 ( V_86 ) ;
if ( ! V_86 && V_17 && V_88 -> V_5 ) {
switch ( V_17 -> type ) {
case V_90 :
V_6 = V_88 -> V_5 -> V_91 ;
break;
default:
break;
}
}
return V_6 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_75 * V_76 ,
T_1 V_6 , T_2 V_92 , T_5 * V_93 ,
T_2 V_94 )
{
unsigned long V_42 ;
T_6 V_95 ;
struct V_96 V_97 ;
int V_7 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
memcpy ( & V_97 , & V_3 -> V_45 [ V_6 ] . V_86 , sizeof( V_97 ) ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
V_95 = F_8 ( V_76 -> V_77 << V_98 ) ;
V_95 |= V_99 ;
switch ( V_76 -> V_100 ) {
case V_101 :
V_95 |= V_102 ;
memcpy ( V_97 . V_64 . V_64 , V_76 -> V_64 , V_76 -> V_78 ) ;
break;
case V_103 :
V_95 |= V_104 ;
V_97 . V_64 . V_105 = V_92 ;
for ( V_7 = 0 ; V_7 < 5 ; V_7 ++ )
V_97 . V_64 . V_106 [ V_7 ] = F_8 ( V_93 [ V_7 ] ) ;
memcpy ( V_97 . V_64 . V_64 , V_76 -> V_64 , V_76 -> V_78 ) ;
break;
case V_107 :
V_95 |= V_108 ;
case V_109 :
V_95 |= V_110 ;
memcpy ( & V_97 . V_64 . V_64 [ 3 ] , V_76 -> V_64 , V_76 -> V_78 ) ;
break;
default:
F_25 ( 1 ) ;
return - V_81 ;
}
if ( ! ( V_76 -> V_42 & V_111 ) )
V_95 |= V_112 ;
V_97 . V_64 . V_68 = V_76 -> V_82 ;
V_97 . V_64 . V_95 = V_95 ;
V_97 . V_113 = V_114 ;
V_97 . V_86 . V_115 = V_116 ;
return F_26 ( V_3 , & V_97 , V_94 ) ;
}
void F_27 ( struct V_2 * V_3 ,
struct V_84 * V_17 ,
struct V_75 * V_76 ,
struct V_85 * V_86 , T_2 V_117 , T_5 * V_118 )
{
T_1 V_6 = F_22 ( V_3 , V_17 , V_86 ) ;
if ( V_6 == V_43 )
return;
if ( F_28 ( V_3 ) ) {
return;
}
F_24 ( V_3 , V_76 , V_6 ,
V_117 , V_118 , V_119 ) ;
}
int F_29 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_75 * V_76 ,
struct V_85 * V_86 )
{
unsigned long V_42 ;
struct V_96 V_97 ;
T_1 V_6 = F_22 ( V_3 , V_5 -> V_17 , V_86 ) ;
if ( V_6 == V_43 )
return - V_120 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
memcpy ( & V_97 , & V_3 -> V_45 [ V_6 ] . V_86 , sizeof( V_97 ) ) ;
if ( ! ( V_3 -> V_45 [ V_6 ] . V_46 & V_121 ) )
V_6 = V_43 ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
if ( V_6 == V_43 )
return 0 ;
F_4 ( & V_3 -> V_13 ) ;
V_5 -> V_122 -- ;
F_19 ( V_3 , L_10 ,
V_76 -> V_77 , V_6 ) ;
if ( ! F_30 ( V_76 -> V_82 , & V_3 -> V_123 ) )
F_3 ( V_3 , L_11 ,
V_76 -> V_82 ) ;
V_97 . V_64 . V_95 = V_124 | V_125 ;
V_97 . V_64 . V_68 = V_69 ;
V_97 . V_86 . V_115 = V_116 ;
V_97 . V_113 = V_114 ;
return F_26 ( V_3 , & V_97 , V_49 ) ;
}
int F_31 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_75 * V_76 ,
struct V_85 * V_86 )
{
struct V_126 V_127 ;
T_5 V_128 [ 5 ] ;
int V_41 ;
T_1 V_6 = F_22 ( V_3 , V_5 -> V_17 , V_86 ) ;
const T_1 * V_39 ;
if ( V_6 == V_43 )
return - V_81 ;
F_4 ( & V_3 -> V_13 ) ;
V_76 -> V_82 = F_32 ( V_3 ) ;
if ( V_76 -> V_82 == V_69 )
return - V_129 ;
V_5 -> V_122 ++ ;
switch ( V_76 -> V_100 ) {
case V_103 :
V_76 -> V_42 |= V_130 ;
V_76 -> V_42 |= V_131 ;
if ( V_86 )
V_39 = V_86 -> V_39 ;
else
V_39 = V_5 -> V_132 . V_133 ;
F_33 ( V_76 , 0 , & V_127 ) ;
F_34 ( V_76 , V_39 , V_127 . V_134 . V_117 , V_128 ) ;
V_41 = F_24 ( V_3 , V_76 , V_6 ,
V_127 . V_134 . V_117 , V_128 , V_49 ) ;
break;
case V_101 :
V_76 -> V_42 |= V_131 ;
case V_109 :
case V_107 :
V_41 = F_24 ( V_3 , V_76 , V_6 ,
0 , NULL , V_49 ) ;
break;
default:
F_3 ( V_3 , L_12 , V_76 -> V_100 ) ;
V_41 = - V_81 ;
}
if ( V_41 ) {
V_5 -> V_122 -- ;
F_35 ( V_76 -> V_82 , & V_3 -> V_123 ) ;
}
F_19 ( V_3 , L_13 ,
V_76 -> V_100 , V_76 -> V_78 , V_76 -> V_77 ,
V_86 ? V_86 -> V_39 : NULL , V_41 ) ;
return V_41 ;
}
int F_36 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_9 ;
unsigned long V_42 ;
T_1 V_6 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_6 = F_37 ( V_3 , V_5 , V_135 , false , NULL ) ;
if ( V_6 == V_43 ) {
F_3 ( V_3 , L_14 ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return - V_81 ;
}
V_3 -> V_45 [ V_6 ] . V_46 |= V_136 ;
V_3 -> V_45 [ V_6 ] . V_46 |= V_137 ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_9 ) {
F_3 ( V_3 ,
L_15 ) ;
return - V_48 ;
}
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_50 = V_9 ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return 0 ;
}
int F_38 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
unsigned long V_42 ;
struct V_1 * V_9 ;
T_1 V_6 = V_5 -> V_138 ;
V_9 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_9 ) {
F_3 ( V_3 , L_15 ) ;
return - V_48 ;
}
F_11 ( & V_3 -> V_44 , V_42 ) ;
if ( V_3 -> V_45 [ V_6 ] . V_50 )
F_39 ( V_3 -> V_45 [ V_6 ] . V_50 ) ;
else
F_40 ( V_3 , L_16 ) ;
V_3 -> V_45 [ V_6 ] . V_50 = V_9 ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return 0 ;
}
int F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_41 = 0 ;
F_42 (priv, ctx) {
V_41 = F_38 ( V_3 , V_5 ) ;
if ( V_41 )
break;
}
return V_41 ;
}
int F_43 ( struct V_2 * V_3 , int V_6 , int V_139 )
{
unsigned long V_42 ;
struct V_96 V_97 ;
F_4 ( & V_3 -> V_13 ) ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_86 . V_115 = V_140 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_141 &= F_8 ( ~ ( 1 << V_139 ) ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_113 = V_114 ;
memcpy ( & V_97 , & V_3 -> V_45 [ V_6 ] . V_86 , sizeof( struct V_96 ) ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return F_26 ( V_3 , & V_97 , V_49 ) ;
}
int F_44 ( struct V_2 * V_3 , struct V_85 * V_86 ,
int V_139 , T_5 V_142 )
{
unsigned long V_42 ;
int V_6 ;
struct V_96 V_97 ;
F_4 ( & V_3 -> V_13 ) ;
V_6 = F_23 ( V_86 ) ;
if ( V_6 == V_43 )
return - V_143 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_144 = 0 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_86 . V_115 = V_145 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_146 = ( T_1 ) V_139 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_147 = F_8 ( V_142 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_113 = V_114 ;
memcpy ( & V_97 , & V_3 -> V_45 [ V_6 ] . V_86 , sizeof( struct V_96 ) ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return F_26 ( V_3 , & V_97 , V_49 ) ;
}
int F_45 ( struct V_2 * V_3 , struct V_85 * V_86 ,
int V_139 )
{
unsigned long V_42 ;
int V_6 ;
struct V_96 V_97 ;
F_4 ( & V_3 -> V_13 ) ;
V_6 = F_23 ( V_86 ) ;
if ( V_6 == V_43 ) {
F_3 ( V_3 , L_17 , V_139 ) ;
return - V_143 ;
}
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_144 = 0 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_86 . V_115 = V_148 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_149 = ( T_1 ) V_139 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_113 = V_114 ;
memcpy ( & V_97 , & V_3 -> V_45 [ V_6 ] . V_86 , sizeof( struct V_96 ) ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
return F_26 ( V_3 , & V_97 , V_49 ) ;
}
static void F_46 ( struct V_2 * V_3 , int V_6 )
{
unsigned long V_42 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_150 &= ~ V_151 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_144 = V_151 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_86 . V_115 = 0 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_152 = 0 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_113 = V_114 ;
F_26 ( V_3 , & V_3 -> V_45 [ V_6 ] . V_86 , V_119 ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
}
void F_47 ( struct V_2 * V_3 , int V_6 , int V_153 )
{
unsigned long V_42 ;
F_11 ( & V_3 -> V_44 , V_42 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_150 |= V_151 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_144 = V_151 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_86 . V_115 =
V_154 ;
V_3 -> V_45 [ V_6 ] . V_86 . V_152 = F_8 ( V_153 ) ;
V_3 -> V_45 [ V_6 ] . V_86 . V_113 = V_114 ;
F_26 ( V_3 , & V_3 -> V_45 [ V_6 ] . V_86 , V_119 ) ;
F_12 ( & V_3 -> V_44 , V_42 ) ;
}
void F_48 ( struct V_155 * V_156 ,
struct V_84 * V_17 ,
enum V_157 V_60 ,
struct V_85 * V_86 )
{
struct V_2 * V_3 = V_156 -> V_3 ;
struct V_158 * V_159 = ( void * ) V_86 -> V_89 ;
int V_6 ;
switch ( V_60 ) {
case V_160 :
F_25 ( ! V_159 -> V_161 ) ;
V_159 -> V_162 = true ;
if ( F_49 ( & V_159 -> V_163 ) > 0 )
F_50 ( V_156 , V_86 , true ) ;
break;
case V_164 :
F_25 ( ! V_159 -> V_161 ) ;
if ( ! V_159 -> V_162 )
break;
V_159 -> V_162 = false ;
V_6 = F_23 ( V_86 ) ;
if ( V_6 != V_43 )
F_46 ( V_3 , V_6 ) ;
break;
default:
break;
}
}
