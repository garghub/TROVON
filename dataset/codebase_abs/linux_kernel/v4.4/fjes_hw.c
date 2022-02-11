T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_4 ;
T_1 V_5 = 0 ;
V_5 = F_2 ( & V_4 [ V_3 ] ) ;
return V_5 ;
}
static T_2 * F_3 ( struct V_1 * V_2 )
{
T_2 * V_4 ;
if ( ! F_4 ( V_2 -> V_6 . V_7 , V_2 -> V_6 . V_8 ,
V_9 ) ) {
F_5 ( L_1 ) ;
return NULL ;
}
V_4 = ( T_2 * ) F_6 ( V_2 -> V_6 . V_7 , V_2 -> V_6 . V_8 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_4 ) ;
F_9 ( V_2 -> V_6 . V_7 , V_2 -> V_6 . V_8 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
union V_10 V_11 ;
int V_12 ;
V_11 . V_3 = 0 ;
V_11 . V_13 . V_14 = 1 ;
F_11 ( V_15 , V_11 . V_3 ) ;
V_12 = V_16 * 1000 ;
V_11 . V_3 = F_12 ( V_15 ) ;
while ( ( V_11 . V_13 . V_14 == 1 ) && ( V_12 > 0 ) ) {
F_13 ( 1000 ) ;
V_11 . V_3 = F_12 ( V_15 ) ;
V_12 -= 1000 ;
}
return V_12 > 0 ? 0 : - V_17 ;
}
static int F_14 ( struct V_1 * V_2 )
{
union V_18 V_19 ;
V_19 . V_3 = F_12 ( V_20 ) ;
return V_19 . V_13 . V_21 ;
}
static int F_15 ( struct V_1 * V_2 )
{
union V_22 V_19 ;
V_19 . V_3 = F_12 ( V_23 ) ;
return V_19 . V_13 . V_24 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_3 V_8 ;
V_8 = sizeof( struct V_25 ) +
( sizeof( T_2 ) * V_2 -> V_26 ) ;
V_2 -> V_27 . V_28 = F_17 ( V_8 , V_29 ) ;
if ( ! V_2 -> V_27 . V_28 )
return - V_30 ;
V_2 -> V_27 . V_28 -> V_31 = V_2 -> V_26 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_27 . V_28 ) ;
V_2 -> V_27 . V_28 = NULL ;
}
static int F_20 ( struct V_32 * V_33 )
{
void * V_34 ;
V_34 = F_21 ( V_35 ) ;
if ( ! V_34 )
return - V_30 ;
V_33 -> V_36 = V_34 ;
V_33 -> V_8 = V_35 ;
V_33 -> V_19 = (union V_37 * ) V_34 ;
V_33 -> V_38 = ( T_2 * ) ( V_34 + sizeof( union V_37 ) ) ;
return 0 ;
}
static void F_22 ( struct V_32 * V_33 )
{
F_23 ( V_33 -> V_36 ) ;
V_33 -> V_36 = NULL ;
V_33 -> V_8 = 0 ;
V_33 -> V_19 = NULL ;
V_33 -> V_38 = NULL ;
}
void F_24 ( struct V_32 * V_33 , T_2 * V_39 , T_1 V_40 )
{
union V_37 * V_19 = V_33 -> V_19 ;
T_4 V_41 [ V_42 ] ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
V_41 [ V_43 ] = V_19 -> V_44 . V_41 [ V_43 ] ;
memset ( V_19 , 0 , sizeof( union V_37 ) ) ;
V_19 -> V_44 . V_45 = 0 ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ )
V_19 -> V_44 . V_39 [ V_43 ] = V_39 [ V_43 ] ;
V_19 -> V_44 . V_47 = 0 ;
V_19 -> V_44 . V_48 = 1 ;
V_19 -> V_44 . V_49 = sizeof( union V_37 ) ;
V_19 -> V_44 . V_50 = V_33 -> V_8 - V_19 -> V_44 . V_49 ;
V_19 -> V_44 . V_51 = F_25 ( V_40 ) ;
V_19 -> V_44 . V_52 =
F_26 ( V_19 -> V_44 . V_50 , V_19 -> V_44 . V_51 ) ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
V_19 -> V_44 . V_41 [ V_43 ] = V_41 [ V_43 ] ;
}
void
F_27 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
F_11 ( V_55 , ( V_56 ) ( V_54 -> V_57 ) ) ;
F_11 ( V_58 , ( V_56 ) ( V_54 -> V_59 ) ) ;
F_11 ( V_60 ,
( V_56 ) ( V_54 -> V_61 & F_28 ( 31 , 0 ) ) ) ;
F_11 ( V_62 ,
( V_56 ) ( ( V_54 -> V_61 & F_28 ( 63 , 32 ) ) >> 32 ) ) ;
F_11 ( V_63 ,
( V_56 ) ( V_54 -> V_64 & F_28 ( 31 , 0 ) ) ) ;
F_11 ( V_65 ,
( V_56 ) ( ( V_54 -> V_64 & F_28 ( 63 , 32 ) ) >> 32 ) ) ;
F_11 ( V_66 ,
( V_56 ) ( V_54 -> V_67 & F_28 ( 31 , 0 ) ) ) ;
F_11 ( V_68 ,
( V_56 ) ( ( V_54 -> V_67 & F_28 ( 63 , 32 ) ) >> 32 ) ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_69 [ V_46 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
struct V_53 V_54 ;
struct V_70 * V_71 ;
T_3 V_72 ;
int V_73 ;
int V_74 ;
void * V_75 ;
V_2 -> V_27 . V_26 = & V_2 -> V_26 ;
V_2 -> V_27 . V_76 = & V_2 -> V_76 ;
V_75 = F_30 ( V_2 -> V_26 , sizeof( struct V_70 ) ,
V_29 ) ;
if ( ! V_75 )
return - V_30 ;
V_2 -> V_77 = (struct V_70 * ) V_75 ;
V_72 = F_31 ( V_2 -> V_26 ) ;
V_2 -> V_27 . V_78 = F_17 ( V_72 , V_29 ) ;
if ( ! ( V_2 -> V_27 . V_78 ) )
return - V_30 ;
V_2 -> V_27 . V_79 = V_72 ;
V_72 = F_32 ( V_2 -> V_26 ) ;
V_2 -> V_27 . V_80 = F_17 ( V_72 , V_29 ) ;
if ( ! ( V_2 -> V_27 . V_80 ) )
return - V_30 ;
V_2 -> V_27 . V_81 = V_72 ;
V_73 = F_16 ( V_2 ) ;
if ( V_73 )
return V_73 ;
V_2 -> V_27 . V_82 = 0 ;
V_2 -> V_27 . V_83 = 0 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 != V_2 -> V_76 ) {
V_71 = & V_2 -> V_77 [ V_74 ] ;
V_73 = F_20 ( & V_71 -> V_84 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_20 ( & V_71 -> V_85 ) ;
if ( V_73 )
return V_73 ;
F_24 ( & V_71 -> V_84 , V_69 ,
V_86 [ 0 ] ) ;
F_24 ( & V_71 -> V_85 , V_69 ,
V_86 [ 0 ] ) ;
}
}
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_57 = V_2 -> V_27 . V_79 ;
V_54 . V_61 = F_33 ( V_2 -> V_27 . V_78 ) ;
V_54 . V_59 = V_2 -> V_27 . V_81 ;
V_54 . V_64 = F_33 ( V_2 -> V_27 . V_80 ) ;
V_54 . V_67 = F_33 ( V_2 -> V_27 . V_28 -> V_87 ) ;
F_27 ( V_2 , & V_54 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_77 )
return;
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_27 . V_78 ) ;
V_2 -> V_27 . V_78 = NULL ;
F_19 ( V_2 -> V_27 . V_80 ) ;
V_2 -> V_27 . V_80 = NULL ;
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 == V_2 -> V_76 )
continue;
F_22 ( & V_2 -> V_77 [ V_74 ] . V_84 ) ;
F_22 ( & V_2 -> V_77 [ V_74 ] . V_85 ) ;
}
F_19 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_88 ;
V_2 -> V_4 = F_3 ( V_2 ) ;
if ( ! V_2 -> V_4 )
return - V_17 ;
V_88 = F_10 ( V_2 ) ;
if ( V_88 )
return V_88 ;
F_36 ( V_2 , V_89 , true ) ;
F_37 ( & V_2 -> V_90 , V_91 ) ;
F_37 ( & V_2 -> V_92 , V_93 ) ;
F_38 ( & V_2 -> V_27 . V_94 ) ;
V_2 -> V_26 = F_14 ( V_2 ) ;
V_2 -> V_76 = F_15 ( V_2 ) ;
if ( ( V_2 -> V_26 == 0 ) || ( V_2 -> V_76 >= V_2 -> V_26 ) )
return - V_95 ;
V_88 = F_29 ( V_2 ) ;
return V_88 ;
}
void F_39 ( struct V_1 * V_2 )
{
int V_88 ;
if ( V_2 -> V_4 ) {
V_88 = F_10 ( V_2 ) ;
if ( V_88 )
F_5 ( L_2 , V_96 ) ;
F_7 ( V_2 ) ;
V_2 -> V_4 = NULL ;
}
F_34 ( V_2 ) ;
F_40 ( & V_2 -> V_90 ) ;
F_40 ( & V_2 -> V_92 ) ;
}
static enum V_97
F_41 ( struct V_1 * V_2 ,
enum V_98 type )
{
enum V_97 V_88 = V_99 ;
union V_100 V_101 ;
union V_102 V_103 ;
int V_12 ;
V_101 . V_3 = 0 ;
V_101 . V_13 . V_61 = 1 ;
V_101 . V_13 . V_104 = type ;
F_11 ( V_105 , V_101 . V_3 ) ;
V_101 . V_3 = F_12 ( V_105 ) ;
if ( V_101 . V_13 . error == 0 ) {
V_12 = V_106 * 1000 ;
V_103 . V_3 = F_12 ( V_107 ) ;
while ( ( V_103 . V_13 . V_108 != 1 ) && V_12 > 0 ) {
F_13 ( 1000 ) ;
V_103 . V_3 = F_12 ( V_107 ) ;
V_12 -= 1000 ;
}
if ( V_103 . V_13 . V_108 == 1 )
V_88 = V_109 ;
else if ( V_12 <= 0 )
V_88 = V_110 ;
} else {
switch ( V_101 . V_13 . V_111 ) {
case V_112 :
V_88 = V_113 ;
break;
case V_114 :
V_88 = V_115 ;
break;
default:
V_88 = V_99 ;
break;
}
}
return V_88 ;
}
int F_42 ( struct V_1 * V_2 )
{
union V_116 * V_78 = V_2 -> V_27 . V_78 ;
union V_117 * V_80 = V_2 -> V_27 . V_80 ;
enum V_97 V_88 ;
int V_73 ;
memset ( V_78 , 0 , V_2 -> V_27 . V_79 ) ;
memset ( V_80 , 0 , V_2 -> V_27 . V_81 ) ;
V_78 -> V_19 . V_118 = V_119 ;
V_80 -> V_19 . V_118 = 0 ;
V_80 -> V_19 . V_120 = 0 ;
V_88 = F_41 ( V_2 , V_121 ) ;
V_73 = 0 ;
if ( F_43 ( ( * V_2 -> V_27 . V_26 ) ) !=
V_80 -> V_19 . V_118 ) {
V_73 = - V_122 ;
} else if ( V_88 == V_109 ) {
switch ( V_80 -> V_19 . V_120 ) {
case V_123 :
V_73 = 0 ;
break;
default:
V_73 = - V_124 ;
break;
}
} else {
switch ( V_88 ) {
case V_99 :
V_73 = - V_124 ;
break;
case V_110 :
V_73 = - V_125 ;
break;
case V_113 :
V_73 = - V_124 ;
break;
case V_115 :
V_73 = - V_124 ;
break;
default:
V_73 = - V_124 ;
break;
}
}
return V_73 ;
}
int F_44 ( struct V_1 * V_2 , int V_126 ,
struct V_70 * V_71 )
{
union V_116 * V_78 = V_2 -> V_27 . V_78 ;
union V_117 * V_80 = V_2 -> V_27 . V_80 ;
enum V_97 V_88 ;
int V_127 ;
int V_12 ;
int V_43 , V_128 ;
void * V_129 ;
int V_73 ;
if ( F_45 ( V_126 , & V_2 -> V_27 . V_82 ) )
return 0 ;
memset ( V_78 , 0 , V_2 -> V_27 . V_79 ) ;
memset ( V_80 , 0 , V_2 -> V_27 . V_81 ) ;
V_78 -> V_130 . V_118 = F_46 (
V_71 -> V_84 . V_8 ,
V_71 -> V_85 . V_8 ) ;
V_78 -> V_130 . V_24 = V_126 ;
V_128 = 0 ;
V_78 -> V_130 . V_36 [ V_128 ++ ] = V_71 -> V_84 . V_8 ;
V_127 = V_71 -> V_84 . V_8 / V_131 ;
for ( V_43 = 0 ; V_43 < V_127 ; V_43 ++ ) {
V_129 = ( ( T_2 * ) ( V_71 -> V_84 . V_36 ) ) +
( V_43 * V_131 ) ;
V_78 -> V_130 . V_36 [ V_128 ++ ] =
( V_132 ) ( F_47 ( F_48 ( V_129 ) ) +
F_49 ( V_129 ) ) ;
}
V_78 -> V_130 . V_36 [ V_128 ++ ] = V_71 -> V_85 . V_8 ;
V_127 = V_71 -> V_85 . V_8 / V_131 ;
for ( V_43 = 0 ; V_43 < V_127 ; V_43 ++ ) {
V_129 = ( ( T_2 * ) ( V_71 -> V_85 . V_36 ) ) +
( V_43 * V_131 ) ;
V_78 -> V_130 . V_36 [ V_128 ++ ] =
( V_132 ) ( F_47 ( F_48 ( V_129 ) ) +
F_49 ( V_129 ) ) ;
}
V_80 -> V_130 . V_118 = 0 ;
V_80 -> V_130 . V_120 = 0 ;
V_88 = F_41 ( V_2 , V_133 ) ;
V_12 = V_134 * 1000 ;
while ( ( V_88 == V_109 ) &&
( V_80 -> V_130 . V_118 ==
V_135 ) &&
( V_80 -> V_130 . V_120 == V_136 ) &&
( V_12 > 0 ) ) {
F_13 ( 200 + V_2 -> V_76 * 20 ) ;
V_12 -= ( 200 + V_2 -> V_76 * 20 ) ;
V_80 -> V_130 . V_118 = 0 ;
V_80 -> V_130 . V_120 = 0 ;
V_88 = F_41 (
V_2 , V_133 ) ;
}
V_73 = 0 ;
if ( V_80 -> V_130 . V_118 !=
V_135 )
V_73 = - V_122 ;
else if ( V_88 == V_109 ) {
switch ( V_80 -> V_130 . V_120 ) {
case V_123 :
V_73 = 0 ;
F_50 ( V_126 , & V_2 -> V_27 . V_82 ) ;
break;
case V_136 :
V_73 = - V_125 ;
break;
default:
V_73 = - V_124 ;
break;
}
} else {
switch ( V_88 ) {
case V_99 :
V_73 = - V_124 ;
break;
case V_110 :
V_73 = - V_125 ;
break;
case V_113 :
case V_115 :
default:
V_73 = - V_124 ;
break;
}
}
return V_73 ;
}
int F_51 ( struct V_1 * V_2 , int V_126 )
{
union V_116 * V_78 = V_2 -> V_27 . V_78 ;
union V_117 * V_80 = V_2 -> V_27 . V_80 ;
struct V_25 * V_28 = V_2 -> V_27 . V_28 ;
enum V_97 V_88 ;
int V_12 ;
int V_73 ;
if ( ! V_2 -> V_4 )
return - V_124 ;
if ( ! V_78 || ! V_80 || ! V_28 )
return - V_124 ;
if ( ! F_45 ( V_126 , & V_2 -> V_27 . V_82 ) )
return 0 ;
memset ( V_78 , 0 , V_2 -> V_27 . V_79 ) ;
memset ( V_80 , 0 , V_2 -> V_27 . V_81 ) ;
V_78 -> V_137 . V_118 =
V_138 ;
V_78 -> V_137 . V_24 = V_126 ;
V_80 -> V_137 . V_118 = 0 ;
V_80 -> V_137 . V_120 = 0 ;
V_88 = F_41 ( V_2 , V_139 ) ;
V_12 = V_134 * 1000 ;
while ( ( V_88 == V_109 ) &&
( V_80 -> V_137 . V_118 ==
V_140 ) &&
( V_80 -> V_137 . V_120 ==
V_136 ) &&
( V_12 > 0 ) ) {
F_13 ( 200 + V_2 -> V_76 * 20 ) ;
V_12 -= ( 200 + V_2 -> V_76 * 20 ) ;
V_80 -> V_137 . V_118 = 0 ;
V_80 -> V_137 . V_120 = 0 ;
V_88 =
F_41 ( V_2 , V_139 ) ;
}
V_73 = 0 ;
if ( V_80 -> V_137 . V_118 !=
V_140 ) {
V_73 = - V_122 ;
} else if ( V_88 == V_109 ) {
switch ( V_80 -> V_137 . V_120 ) {
case V_123 :
V_73 = 0 ;
F_52 ( V_126 , & V_2 -> V_27 . V_82 ) ;
break;
case V_136 :
V_73 = - V_125 ;
break;
default:
V_73 = - V_124 ;
break;
}
} else {
switch ( V_88 ) {
case V_99 :
V_73 = - V_124 ;
break;
case V_110 :
V_73 = - V_125 ;
break;
case V_113 :
case V_115 :
default:
V_73 = - V_124 ;
break;
}
}
return V_73 ;
}
int F_53 ( struct V_1 * V_2 , int V_126 ,
enum V_141 V_142 )
{
T_1 V_143 = V_142 | V_126 ;
F_11 ( V_144 , F_54 ( V_143 ) ) ;
return 0 ;
}
T_1 F_55 ( struct V_1 * V_2 )
{
T_1 V_145 ;
V_145 = F_12 ( V_146 ) ;
return V_145 ;
}
void F_36 ( struct V_1 * V_2 ,
enum V_141 V_147 , bool V_142 )
{
if ( V_142 )
F_11 ( V_148 , V_147 ) ;
else
F_11 ( V_149 , V_147 ) ;
}
bool F_56 ( struct V_1 * V_2 , int V_24 )
{
if ( V_24 >= V_2 -> V_26 )
return false ;
if ( ( V_2 -> V_77 [ V_24 ] . V_150 !=
V_151 ) ||
( V_2 -> V_77 [ V_2 -> V_76 ] . V_152 ==
V_153 ) )
return false ;
else
return ( V_2 -> V_77 [ V_24 ] . V_152 ==
V_2 -> V_77 [ V_2 -> V_76 ] . V_152 ) ;
}
int F_57 ( struct V_25 * V_28 ,
int V_126 )
{
int V_5 = false ;
if ( V_126 < V_28 -> V_31 )
V_5 = V_28 -> V_87 [ V_126 ] ;
return V_5 ;
}
static bool F_58 ( struct V_1 * V_2 , int V_154 )
{
return F_45 ( V_154 , & V_2 -> V_155 ) ;
}
static bool F_59 ( struct V_1 * V_2 , int V_154 )
{
return ( V_2 -> V_77 [ V_154 ] . V_84 . V_19 -> V_44 . V_156 &
V_157 ) ;
}
enum V_158
F_60 ( struct V_1 * V_2 , int V_24 )
{
enum V_158 V_159 ;
if ( F_57 ( V_2 -> V_27 . V_28 , V_24 ) ) {
if ( F_58 ( V_2 , V_24 ) ) {
V_159 = V_160 ;
} else {
if ( F_59 ( V_2 , V_24 ) )
V_159 = V_161 ;
else
V_159 = V_162 ;
}
} else {
V_159 = V_163 ;
}
return V_159 ;
}
void F_61 ( struct V_1 * V_2 )
{
enum V_158 V_159 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 == V_2 -> V_76 )
continue;
V_159 = F_60 ( V_2 , V_74 ) ;
switch ( V_159 ) {
case V_162 :
F_53 ( V_2 , V_74 ,
V_164 ) ;
break;
default:
break;
}
F_50 ( V_74 , & V_2 -> V_27 . V_83 ) ;
F_50 ( V_74 , & V_2 -> V_155 ) ;
V_2 -> V_77 [ V_74 ] . V_84 . V_19 -> V_44 . V_156 |=
V_165 ;
}
}
int F_62 ( struct V_1 * V_2 )
{
enum V_158 V_159 ;
union V_37 * V_19 ;
int V_166 = 0 ;
int V_74 ;
while ( V_2 -> V_27 . V_83 &&
( V_166 < V_167 * 1000 ) ) {
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 == V_2 -> V_76 )
continue;
V_159 = F_57 ( V_2 -> V_27 . V_28 ,
V_74 ) ;
V_19 = V_2 -> V_77 [ V_74 ] . V_85 . V_19 ;
if ( ( ! V_159 ||
( V_19 -> V_44 . V_156 &
V_157 ) ) &&
F_45 ( V_74 ,
& V_2 -> V_27 . V_83 ) ) {
F_52 ( V_74 ,
& V_2 -> V_27 . V_83 ) ;
}
}
F_13 ( 100 ) ;
V_166 += 100 ;
}
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 == V_2 -> V_76 )
continue;
if ( F_45 ( V_74 , & V_2 -> V_27 . V_83 ) )
F_52 ( V_74 ,
& V_2 -> V_27 . V_83 ) ;
}
return ( V_166 < V_167 * 1000 )
? 0 : - V_125 ;
}
bool F_63 ( struct V_32 * V_33 , T_1 V_45 )
{
union V_37 * V_19 = V_33 -> V_19 ;
return ( V_19 -> V_168 . V_45 == V_45 ) ;
}
bool F_64 ( struct V_32 * V_33 , T_1 V_40 )
{
union V_37 * V_19 = V_33 -> V_19 ;
return ( V_19 -> V_44 . V_51 == F_25 ( V_40 ) ) ;
}
bool F_65 ( struct V_32 * V_33 , T_4 V_41 )
{
union V_37 * V_19 = V_33 -> V_19 ;
bool V_88 = false ;
int V_43 ;
if ( V_41 == 0 ) {
V_88 = true ;
} else {
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( V_41 == V_19 -> V_44 . V_41 [ V_43 ] ) {
V_88 = true ;
break;
}
}
}
return V_88 ;
}
bool F_66 ( struct V_32 * V_33 , T_4 V_41 )
{
union V_37 * V_19 = V_33 -> V_19 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( V_19 -> V_44 . V_41 [ V_43 ] == 0 ) {
V_19 -> V_44 . V_41 [ V_43 ] = V_41 ;
return true ;
}
}
return false ;
}
void F_67 ( struct V_32 * V_33 , T_4 V_41 )
{
union V_37 * V_19 = V_33 -> V_19 ;
int V_43 ;
if ( 0 != V_41 ) {
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( V_41 == V_19 -> V_44 . V_41 [ V_43 ] )
V_19 -> V_44 . V_41 [ V_43 ] = 0 ;
}
}
}
bool F_68 ( struct V_32 * V_33 )
{
union V_37 * V_19 = V_33 -> V_19 ;
if ( V_19 -> V_44 . V_52 == 0 )
return true ;
return F_69 ( V_19 -> V_44 . V_47 , V_19 -> V_44 . V_48 ,
V_19 -> V_44 . V_52 ) ;
}
void * F_70 ( struct V_32 * V_33 ,
T_3 * V_169 )
{
union V_37 * V_19 = V_33 -> V_19 ;
struct V_170 * V_171 ;
void * V_172 ;
V_171 = (struct V_170 * ) & ( V_33 -> V_38 [ F_71
( V_19 -> V_44 . V_47 ,
V_19 -> V_44 . V_52 ) *
V_19 -> V_44 . V_51 ] ) ;
* V_169 = ( T_3 ) V_171 -> V_173 ;
V_172 = V_171 -> V_174 ;
return V_172 ;
}
void F_72 ( struct V_32 * V_33 )
{
union V_37 * V_19 = V_33 -> V_19 ;
if ( F_68 ( V_33 ) )
return;
F_73 ( V_33 -> V_19 -> V_44 . V_47 , V_19 -> V_44 . V_52 ) ;
}
int F_74 ( struct V_32 * V_33 ,
void * V_172 , T_3 V_8 )
{
union V_37 * V_19 = V_33 -> V_19 ;
struct V_170 * V_171 ;
if ( F_75 ( V_19 -> V_44 . V_47 , V_19 -> V_44 . V_48 , V_19 -> V_44 . V_52 ) )
return - V_175 ;
V_171 = (struct V_170 * ) & ( V_33 -> V_38 [ F_71
( V_19 -> V_44 . V_48 - 1 ,
V_19 -> V_44 . V_52 ) *
V_19 -> V_44 . V_51 ] ) ;
V_171 -> V_173 = V_8 ;
memcpy ( ( void * ) ( V_171 -> V_174 ) , ( void * ) V_172 , V_8 ) ;
F_73 ( V_33 -> V_19 -> V_44 . V_48 , V_19 -> V_44 . V_52 ) ;
return 0 ;
}
static void V_91 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = F_76 ( V_177 ,
struct V_1 , V_90 ) ;
struct V_178 { T_2 V_150 ; T_2 V_152 ; } * V_19 ;
union V_117 * V_80 ;
enum V_158 V_179 ;
struct V_180 * V_181 ;
struct V_182 * V_183 ;
T_5 V_184 = 0 ;
T_5 V_185 = 0 ;
T_5 V_186 = 0 ;
int V_74 ;
int V_88 ;
V_181 = (struct V_180 * ) V_2 -> V_187 ;
V_183 = V_181 -> V_183 ;
V_80 = V_2 -> V_27 . V_80 ;
V_19 = (struct V_178 * ) & V_80 -> V_19 . V_19 ;
F_77 ( & V_2 -> V_27 . V_94 ) ;
V_88 = F_42 ( V_2 ) ;
switch ( V_88 ) {
case - V_122 :
case - V_125 :
default:
if ( ! F_78 ( & V_181 -> V_188 ) ) {
V_181 -> V_189 = true ;
F_79 ( & V_181 -> V_188 ) ;
}
break;
case 0 :
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 == V_2 -> V_76 ) {
V_2 -> V_77 [ V_74 ] . V_150 =
V_19 [ V_74 ] . V_150 ;
V_2 -> V_77 [ V_74 ] . V_152 =
V_19 [ V_74 ] . V_152 ;
continue;
}
V_179 = F_60 ( V_2 , V_74 ) ;
switch ( V_179 ) {
case V_163 :
default:
if ( ( V_19 [ V_74 ] . V_152 !=
V_153 ) &&
( V_19 [ V_74 ] . V_150 ==
V_151 ) &&
( V_19 [ V_74 ] . V_152 ==
V_19 [ V_2 -> V_76 ] . V_152 ) )
F_50 ( V_74 , & V_185 ) ;
else
F_50 ( V_74 , & V_184 ) ;
break;
case V_161 :
case V_160 :
if ( ( V_19 [ V_74 ] . V_152 ==
V_153 ) ||
( V_19 [ V_74 ] . V_150 !=
V_151 ) ||
( V_19 [ V_74 ] . V_152 !=
V_19 [ V_2 -> V_76 ] . V_152 ) ) {
F_50 ( V_74 ,
& V_181 -> V_190 ) ;
F_50 ( V_74 ,
& V_2 -> V_27 . V_83 ) ;
}
break;
case V_162 :
if ( ( V_19 [ V_74 ] . V_152 ==
V_153 ) ||
( V_19 [ V_74 ] . V_150 !=
V_151 ) ||
( V_19 [ V_74 ] . V_152 !=
V_19 [ V_2 -> V_76 ] . V_152 ) )
F_50 ( V_74 , & V_186 ) ;
break;
}
V_2 -> V_77 [ V_74 ] . V_150 =
V_19 [ V_74 ] . V_150 ;
V_2 -> V_77 [ V_74 ] . V_152 = V_19 [ V_74 ] . V_152 ;
}
break;
}
F_80 ( & V_2 -> V_27 . V_94 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_26 ; V_74 ++ ) {
if ( V_74 == V_2 -> V_76 )
continue;
if ( F_45 ( V_74 , & V_185 ) ) {
F_24 ( & V_2 -> V_77 [ V_74 ] . V_84 ,
V_183 -> V_191 , V_183 -> V_40 ) ;
F_77 ( & V_2 -> V_27 . V_94 ) ;
V_88 = F_44 (
V_2 , V_74 , & V_2 -> V_77 [ V_74 ] ) ;
switch ( V_88 ) {
case 0 :
break;
case - V_122 :
case - V_125 :
default:
if ( ! F_78 ( & V_181 -> V_188 ) ) {
V_181 -> V_189 = true ;
F_79 (
& V_181 -> V_188 ) ;
}
break;
}
F_80 ( & V_2 -> V_27 . V_94 ) ;
}
if ( F_45 ( V_74 , & V_184 ) ) {
F_77 ( & V_2 -> V_27 . V_94 ) ;
V_88 = F_51 ( V_2 , V_74 ) ;
switch ( V_88 ) {
case 0 :
break;
case - V_122 :
case - V_125 :
default:
if ( ! F_78 ( & V_181 -> V_188 ) ) {
V_181 -> V_189 = true ;
F_79 (
& V_181 -> V_188 ) ;
}
break;
}
F_80 ( & V_2 -> V_27 . V_94 ) ;
if ( V_88 == 0 )
F_24 (
& V_2 -> V_77 [ V_74 ] . V_84 ,
V_183 -> V_191 , V_183 -> V_40 ) ;
}
if ( F_45 ( V_74 , & V_186 ) ) {
F_53 ( V_2 , V_74 ,
V_164 ) ;
F_50 ( V_74 , & V_2 -> V_155 ) ;
V_2 -> V_77 [ V_74 ] . V_84 .
V_19 -> V_44 . V_156 |=
V_165 ;
F_50 ( V_74 , & V_2 -> V_27 . V_83 ) ;
}
}
if ( V_186 || V_181 -> V_190 ) {
if ( ! F_78 ( & V_181 -> V_192 ) )
F_81 ( V_181 -> V_193 ,
& V_181 -> V_192 ) ;
}
}
static void V_93 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = F_76 ( V_177 , struct V_1 , V_92 ) ;
struct V_180 * V_181 = (struct V_180 * ) V_2 -> V_187 ;
T_5 V_194 ;
int V_195 ;
while ( ( V_194 = V_2 -> V_196 ) ) {
for ( V_195 = 0 ; V_194 ; V_194 >>= 1 , V_195 ++ ) {
if ( V_194 & 1 ) {
V_2 -> V_77 [ V_195 ] .
V_84 . V_19 -> V_44 . V_156 |=
V_157 ;
F_52 ( V_195 , & V_2 -> V_196 ) ;
F_50 ( V_195 ,
& V_181 -> V_190 ) ;
if ( ! F_78 ( & V_181 -> V_192 ) )
F_81 (
V_181 -> V_193 ,
& V_181 -> V_192 ) ;
}
}
}
}
