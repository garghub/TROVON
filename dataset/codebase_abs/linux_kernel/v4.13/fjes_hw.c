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
V_19 -> V_44 . V_53 |= V_54 ;
}
void
F_27 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_11 ( V_57 , ( V_58 ) ( V_56 -> V_59 ) ) ;
F_11 ( V_60 , ( V_58 ) ( V_56 -> V_61 ) ) ;
F_11 ( V_62 ,
( V_58 ) ( V_56 -> V_63 & F_28 ( 31 , 0 ) ) ) ;
F_11 ( V_64 ,
( V_58 ) ( ( V_56 -> V_63 & F_28 ( 63 , 32 ) ) >> 32 ) ) ;
F_11 ( V_65 ,
( V_58 ) ( V_56 -> V_66 & F_28 ( 31 , 0 ) ) ) ;
F_11 ( V_67 ,
( V_58 ) ( ( V_56 -> V_66 & F_28 ( 63 , 32 ) ) >> 32 ) ) ;
F_11 ( V_68 ,
( V_58 ) ( V_56 -> V_69 & F_28 ( 31 , 0 ) ) ) ;
F_11 ( V_70 ,
( V_58 ) ( ( V_56 -> V_69 & F_28 ( 63 , 32 ) ) >> 32 ) ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_71 [ V_46 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
struct V_55 V_56 ;
struct V_72 * V_73 ;
unsigned long V_74 ;
T_3 V_75 ;
int V_76 ;
int V_77 ;
void * V_78 ;
V_2 -> V_27 . V_26 = & V_2 -> V_26 ;
V_2 -> V_27 . V_79 = & V_2 -> V_79 ;
V_78 = F_30 ( V_2 -> V_26 , sizeof( struct V_72 ) ,
V_29 ) ;
if ( ! V_78 )
return - V_30 ;
V_2 -> V_80 = (struct V_72 * ) V_78 ;
V_75 = F_31 ( V_2 -> V_26 ) ;
V_2 -> V_27 . V_81 = F_17 ( V_75 , V_29 ) ;
if ( ! ( V_2 -> V_27 . V_81 ) )
return - V_30 ;
V_2 -> V_27 . V_82 = V_75 ;
V_75 = F_32 ( V_2 -> V_26 ) ;
V_2 -> V_27 . V_83 = F_17 ( V_75 , V_29 ) ;
if ( ! ( V_2 -> V_27 . V_83 ) )
return - V_30 ;
V_2 -> V_27 . V_84 = V_75 ;
V_76 = F_16 ( V_2 ) ;
if ( V_76 )
return V_76 ;
V_2 -> V_27 . V_85 = 0 ;
V_2 -> V_27 . V_86 = 0 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 != V_2 -> V_79 ) {
V_73 = & V_2 -> V_80 [ V_77 ] ;
V_76 = F_20 ( & V_73 -> V_87 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_20 ( & V_73 -> V_88 ) ;
if ( V_76 )
return V_76 ;
F_33 ( & V_2 -> V_89 , V_74 ) ;
F_24 ( & V_73 -> V_87 , V_71 ,
V_90 [ 0 ] ) ;
F_24 ( & V_73 -> V_88 , V_71 ,
V_90 [ 0 ] ) ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
}
}
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_59 = V_2 -> V_27 . V_82 ;
V_56 . V_63 = F_35 ( V_2 -> V_27 . V_81 ) ;
V_56 . V_61 = V_2 -> V_27 . V_84 ;
V_56 . V_66 = F_35 ( V_2 -> V_27 . V_83 ) ;
V_56 . V_69 = F_35 ( V_2 -> V_27 . V_28 -> V_91 ) ;
F_27 ( V_2 , & V_56 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_77 ;
if ( ! V_2 -> V_80 )
return;
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_27 . V_81 ) ;
V_2 -> V_27 . V_81 = NULL ;
F_19 ( V_2 -> V_27 . V_83 ) ;
V_2 -> V_27 . V_83 = NULL ;
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
F_22 ( & V_2 -> V_80 [ V_77 ] . V_87 ) ;
F_22 ( & V_2 -> V_80 [ V_77 ] . V_88 ) ;
}
F_19 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_92 ;
V_2 -> V_4 = F_3 ( V_2 ) ;
if ( ! V_2 -> V_4 )
return - V_17 ;
V_92 = F_10 ( V_2 ) ;
if ( V_92 )
return V_92 ;
F_38 ( V_2 , V_93 , true ) ;
F_39 ( & V_2 -> V_94 , V_95 ) ;
F_39 ( & V_2 -> V_96 , V_97 ) ;
F_40 ( & V_2 -> V_27 . V_98 ) ;
F_41 ( & V_2 -> V_89 ) ;
V_2 -> V_26 = F_14 ( V_2 ) ;
V_2 -> V_79 = F_15 ( V_2 ) ;
if ( ( V_2 -> V_26 == 0 ) || ( V_2 -> V_79 >= V_2 -> V_26 ) )
return - V_99 ;
V_92 = F_29 ( V_2 ) ;
V_2 -> V_27 . V_100 = F_21 ( V_101 ) ;
V_2 -> V_27 . V_102 = V_101 ;
return V_92 ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_92 ;
if ( V_2 -> V_4 ) {
if ( V_2 -> V_103 ) {
F_43 ( & V_2 -> V_27 . V_98 ) ;
F_44 ( V_2 ) ;
F_45 ( & V_2 -> V_27 . V_98 ) ;
}
F_23 ( V_2 -> V_27 . V_100 ) ;
V_2 -> V_27 . V_100 = NULL ;
V_2 -> V_27 . V_102 = 0 ;
V_2 -> V_103 = 0 ;
V_92 = F_10 ( V_2 ) ;
if ( V_92 )
F_5 ( L_2 , V_104 ) ;
F_7 ( V_2 ) ;
V_2 -> V_4 = NULL ;
}
F_36 ( V_2 ) ;
F_46 ( & V_2 -> V_94 ) ;
F_46 ( & V_2 -> V_96 ) ;
}
static enum V_105
F_47 ( struct V_1 * V_2 ,
enum V_106 type )
{
enum V_105 V_92 = V_107 ;
union V_108 V_109 ;
union V_110 V_111 ;
int V_12 = V_112 * 1000 ;
V_109 . V_3 = 0 ;
V_109 . V_13 . V_63 = 1 ;
V_109 . V_13 . V_113 = type ;
F_11 ( V_114 , V_109 . V_3 ) ;
V_109 . V_3 = F_12 ( V_114 ) ;
if ( V_109 . V_13 . error == 0 ) {
V_12 = V_112 * 1000 ;
V_111 . V_3 = F_12 ( V_115 ) ;
while ( ( V_111 . V_13 . V_116 != 1 ) && V_12 > 0 ) {
F_13 ( 1000 ) ;
V_111 . V_3 = F_12 ( V_115 ) ;
V_12 -= 1000 ;
}
if ( V_111 . V_13 . V_116 == 1 )
V_92 = V_117 ;
else if ( V_12 <= 0 )
V_92 = V_118 ;
} else {
switch ( V_109 . V_13 . V_119 ) {
case V_120 :
V_92 = V_121 ;
break;
case V_122 :
V_92 = V_123 ;
break;
default:
V_92 = V_107 ;
break;
}
}
F_48 ( & V_109 , & V_111 , V_12 , V_92 ) ;
return V_92 ;
}
int F_49 ( struct V_1 * V_2 )
{
union V_124 * V_81 = V_2 -> V_27 . V_81 ;
union V_125 * V_83 = V_2 -> V_27 . V_83 ;
enum V_105 V_92 ;
int V_76 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_19 . V_126 = V_127 ;
V_83 -> V_19 . V_126 = 0 ;
V_83 -> V_19 . V_128 = 0 ;
V_92 = F_47 ( V_2 , V_129 ) ;
F_50 ( V_2 , V_83 ) ;
V_76 = 0 ;
if ( F_51 ( ( * V_2 -> V_27 . V_26 ) ) !=
V_83 -> V_19 . V_126 ) {
F_52 ( L_3 ) ;
V_76 = - V_130 ;
} else if ( V_92 == V_117 ) {
switch ( V_83 -> V_19 . V_128 ) {
case V_131 :
V_76 = 0 ;
break;
default:
V_76 = - V_132 ;
break;
}
} else {
switch ( V_92 ) {
case V_107 :
V_76 = - V_132 ;
break;
case V_118 :
F_52 ( L_4 ) ;
V_76 = - V_133 ;
break;
case V_121 :
V_76 = - V_132 ;
break;
case V_123 :
V_76 = - V_132 ;
break;
default:
V_76 = - V_132 ;
break;
}
}
return V_76 ;
}
int F_53 ( struct V_1 * V_2 , int V_134 ,
struct V_72 * V_73 )
{
union V_124 * V_81 = V_2 -> V_27 . V_81 ;
union V_125 * V_83 = V_2 -> V_27 . V_83 ;
enum V_105 V_92 ;
int V_135 ;
int V_12 ;
int V_43 , V_136 ;
void * V_137 ;
int V_76 ;
if ( F_54 ( V_134 , & V_2 -> V_27 . V_85 ) )
return 0 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_138 . V_126 = F_55 (
V_73 -> V_87 . V_8 ,
V_73 -> V_88 . V_8 ) ;
V_81 -> V_138 . V_24 = V_134 ;
V_136 = 0 ;
V_81 -> V_138 . V_36 [ V_136 ++ ] = V_73 -> V_87 . V_8 ;
V_135 = V_73 -> V_87 . V_8 / V_139 ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_137 = ( ( T_2 * ) ( V_73 -> V_87 . V_36 ) ) +
( V_43 * V_139 ) ;
V_81 -> V_138 . V_36 [ V_136 ++ ] =
( V_140 ) ( F_56 ( F_57 ( V_137 ) ) +
F_58 ( V_137 ) ) ;
}
V_81 -> V_138 . V_36 [ V_136 ++ ] = V_73 -> V_88 . V_8 ;
V_135 = V_73 -> V_88 . V_8 / V_139 ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_137 = ( ( T_2 * ) ( V_73 -> V_88 . V_36 ) ) +
( V_43 * V_139 ) ;
V_81 -> V_138 . V_36 [ V_136 ++ ] =
( V_140 ) ( F_56 ( F_57 ( V_137 ) ) +
F_58 ( V_137 ) ) ;
}
V_83 -> V_138 . V_126 = 0 ;
V_83 -> V_138 . V_128 = 0 ;
F_59 ( V_81 , V_73 ) ;
V_92 = F_47 ( V_2 , V_141 ) ;
V_12 = V_142 * 1000 ;
while ( ( V_92 == V_117 ) &&
( V_83 -> V_138 . V_126 ==
V_143 ) &&
( V_83 -> V_138 . V_128 == V_144 ) &&
( V_12 > 0 ) ) {
F_13 ( 200 + V_2 -> V_79 * 20 ) ;
V_12 -= ( 200 + V_2 -> V_79 * 20 ) ;
V_83 -> V_138 . V_126 = 0 ;
V_83 -> V_138 . V_128 = 0 ;
V_92 = F_47 (
V_2 , V_141 ) ;
}
V_76 = 0 ;
F_60 ( V_83 , V_12 ) ;
if ( V_83 -> V_138 . V_126 !=
V_143 ) {
F_61 ( L_3 ) ;
V_76 = - V_130 ;
} else if ( V_92 == V_117 ) {
switch ( V_83 -> V_138 . V_128 ) {
case V_131 :
V_76 = 0 ;
F_62 ( V_134 , & V_2 -> V_27 . V_85 ) ;
break;
case V_144 :
F_61 ( L_5 ) ;
V_76 = - V_133 ;
break;
default:
V_76 = - V_132 ;
break;
}
} else {
switch ( V_92 ) {
case V_107 :
V_76 = - V_132 ;
break;
case V_118 :
F_61 ( L_4 ) ;
V_76 = - V_133 ;
break;
case V_121 :
case V_123 :
default:
V_76 = - V_132 ;
break;
}
}
return V_76 ;
}
int F_63 ( struct V_1 * V_2 , int V_134 )
{
union V_124 * V_81 = V_2 -> V_27 . V_81 ;
union V_125 * V_83 = V_2 -> V_27 . V_83 ;
struct V_25 * V_28 = V_2 -> V_27 . V_28 ;
enum V_105 V_92 ;
int V_12 ;
int V_76 ;
if ( ! V_2 -> V_4 )
return - V_132 ;
if ( ! V_81 || ! V_83 || ! V_28 )
return - V_132 ;
if ( ! F_54 ( V_134 , & V_2 -> V_27 . V_85 ) )
return 0 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_145 . V_126 =
V_146 ;
V_81 -> V_145 . V_24 = V_134 ;
V_83 -> V_145 . V_126 = 0 ;
V_83 -> V_145 . V_128 = 0 ;
F_64 ( V_81 ) ;
V_92 = F_47 ( V_2 , V_147 ) ;
V_12 = V_142 * 1000 ;
while ( ( V_92 == V_117 ) &&
( V_83 -> V_145 . V_126 ==
V_148 ) &&
( V_83 -> V_145 . V_128 ==
V_144 ) &&
( V_12 > 0 ) ) {
F_13 ( 200 + V_2 -> V_79 * 20 ) ;
V_12 -= ( 200 + V_2 -> V_79 * 20 ) ;
V_83 -> V_145 . V_126 = 0 ;
V_83 -> V_145 . V_128 = 0 ;
V_92 =
F_47 ( V_2 , V_147 ) ;
}
V_76 = 0 ;
F_65 ( V_83 , V_12 ) ;
if ( V_83 -> V_145 . V_126 !=
V_148 ) {
F_66 ( L_3 ) ;
V_76 = - V_130 ;
} else if ( V_92 == V_117 ) {
switch ( V_83 -> V_145 . V_128 ) {
case V_131 :
V_76 = 0 ;
F_67 ( V_134 , & V_2 -> V_27 . V_85 ) ;
break;
case V_144 :
F_66 ( L_5 ) ;
V_76 = - V_133 ;
break;
default:
V_76 = - V_132 ;
break;
}
} else {
switch ( V_92 ) {
case V_107 :
V_76 = - V_132 ;
break;
case V_118 :
F_66 ( L_4 ) ;
V_76 = - V_133 ;
break;
case V_121 :
case V_123 :
default:
V_76 = - V_132 ;
break;
}
}
return V_76 ;
}
int F_68 ( struct V_1 * V_2 , int V_134 ,
enum V_149 V_150 )
{
T_1 V_151 = V_150 | V_134 ;
F_11 ( V_152 , F_69 ( V_151 ) ) ;
return 0 ;
}
T_1 F_70 ( struct V_1 * V_2 )
{
T_1 V_153 ;
V_153 = F_12 ( V_154 ) ;
return V_153 ;
}
void F_38 ( struct V_1 * V_2 ,
enum V_149 V_155 , bool V_150 )
{
if ( V_150 )
F_11 ( V_156 , V_155 ) ;
else
F_11 ( V_157 , V_155 ) ;
}
bool F_71 ( struct V_1 * V_2 , int V_24 )
{
if ( V_24 >= V_2 -> V_26 )
return false ;
if ( ( V_2 -> V_80 [ V_24 ] . V_158 !=
V_159 ) ||
( V_2 -> V_80 [ V_2 -> V_79 ] . V_160 ==
V_161 ) )
return false ;
else
return ( V_2 -> V_80 [ V_24 ] . V_160 ==
V_2 -> V_80 [ V_2 -> V_79 ] . V_160 ) ;
}
int F_72 ( struct V_25 * V_28 ,
int V_134 )
{
int V_5 = false ;
if ( V_134 < V_28 -> V_31 )
V_5 = V_28 -> V_91 [ V_134 ] ;
return V_5 ;
}
static bool F_73 ( struct V_1 * V_2 , int V_162 )
{
return F_54 ( V_162 , & V_2 -> V_163 ) ;
}
static bool F_74 ( struct V_1 * V_2 , int V_162 )
{
return ( V_2 -> V_80 [ V_162 ] . V_87 . V_19 -> V_44 . V_53 &
V_164 ) ;
}
enum V_165
F_75 ( struct V_1 * V_2 , int V_24 )
{
enum V_165 V_166 ;
if ( F_72 ( V_2 -> V_27 . V_28 , V_24 ) ) {
if ( F_73 ( V_2 , V_24 ) ) {
V_166 = V_167 ;
} else {
if ( F_74 ( V_2 , V_24 ) )
V_166 = V_168 ;
else
V_166 = V_169 ;
}
} else {
V_166 = V_170 ;
}
return V_166 ;
}
void F_76 ( struct V_1 * V_2 )
{
enum V_165 V_166 ;
unsigned long V_74 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
V_166 = F_75 ( V_2 , V_77 ) ;
switch ( V_166 ) {
case V_169 :
F_68 ( V_2 , V_77 ,
V_171 ) ;
V_2 -> V_80 [ V_77 ] . V_172 . V_173 += 1 ;
break;
default:
break;
}
F_62 ( V_77 , & V_2 -> V_27 . V_86 ) ;
F_62 ( V_77 , & V_2 -> V_163 ) ;
F_33 ( & V_2 -> V_89 , V_74 ) ;
V_2 -> V_80 [ V_77 ] . V_87 . V_19 -> V_44 . V_53 |=
V_174 ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
}
}
int F_77 ( struct V_1 * V_2 )
{
enum V_165 V_166 ;
union V_37 * V_19 ;
int V_175 = 0 ;
int V_77 ;
while ( V_2 -> V_27 . V_86 &&
( V_175 < V_176 * 1000 ) ) {
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
V_166 = F_72 ( V_2 -> V_27 . V_28 ,
V_77 ) ;
V_19 = V_2 -> V_80 [ V_77 ] . V_88 . V_19 ;
if ( ( ! V_166 ||
( V_19 -> V_44 . V_53 &
V_164 ) ) &&
F_54 ( V_77 ,
& V_2 -> V_27 . V_86 ) ) {
F_67 ( V_77 ,
& V_2 -> V_27 . V_86 ) ;
}
}
F_13 ( 100 ) ;
V_175 += 100 ;
}
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
if ( F_54 ( V_77 , & V_2 -> V_27 . V_86 ) )
F_67 ( V_77 ,
& V_2 -> V_27 . V_86 ) ;
}
return ( V_175 < V_176 * 1000 )
? 0 : - V_133 ;
}
bool F_78 ( struct V_32 * V_33 , T_1 V_45 )
{
union V_37 * V_19 = V_33 -> V_19 ;
return ( V_19 -> V_177 . V_45 == V_45 ) ;
}
bool F_79 ( struct V_32 * V_33 , T_1 V_40 )
{
union V_37 * V_19 = V_33 -> V_19 ;
return ( ( V_19 -> V_44 . V_51 == F_25 ( V_40 ) ) &&
V_19 -> V_44 . V_53 & V_54 ) ;
}
bool F_80 ( struct V_32 * V_33 , T_4 V_41 )
{
union V_37 * V_19 = V_33 -> V_19 ;
bool V_92 = false ;
int V_43 ;
if ( V_41 == 0 ) {
V_92 = true ;
} else {
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( V_41 == V_19 -> V_44 . V_41 [ V_43 ] ) {
V_92 = true ;
break;
}
}
}
return V_92 ;
}
bool F_81 ( struct V_32 * V_33 , T_4 V_41 )
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
void F_82 ( struct V_32 * V_33 , T_4 V_41 )
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
bool F_83 ( struct V_32 * V_33 )
{
union V_37 * V_19 = V_33 -> V_19 ;
if ( ! ( V_19 -> V_44 . V_53 & V_54 ) )
return true ;
if ( V_19 -> V_44 . V_52 == 0 )
return true ;
return F_84 ( V_19 -> V_44 . V_47 , V_19 -> V_44 . V_48 ,
V_19 -> V_44 . V_52 ) ;
}
void * F_85 ( struct V_32 * V_33 ,
T_3 * V_178 )
{
union V_37 * V_19 = V_33 -> V_19 ;
struct V_179 * V_180 ;
void * V_181 ;
V_180 = (struct V_179 * ) & ( V_33 -> V_38 [ F_86
( V_19 -> V_44 . V_47 ,
V_19 -> V_44 . V_52 ) *
V_19 -> V_44 . V_51 ] ) ;
* V_178 = ( T_3 ) V_180 -> V_182 ;
V_181 = V_180 -> V_183 ;
return V_181 ;
}
void F_87 ( struct V_32 * V_33 )
{
union V_37 * V_19 = V_33 -> V_19 ;
if ( F_83 ( V_33 ) )
return;
F_88 ( V_33 -> V_19 -> V_44 . V_47 , V_19 -> V_44 . V_52 ) ;
}
int F_89 ( struct V_32 * V_33 ,
void * V_181 , T_3 V_8 )
{
union V_37 * V_19 = V_33 -> V_19 ;
struct V_179 * V_180 ;
if ( F_90 ( V_19 -> V_44 . V_47 , V_19 -> V_44 . V_48 , V_19 -> V_44 . V_52 ) )
return - V_184 ;
V_180 = (struct V_179 * ) & ( V_33 -> V_38 [ F_86
( V_19 -> V_44 . V_48 - 1 ,
V_19 -> V_44 . V_52 ) *
V_19 -> V_44 . V_51 ] ) ;
V_180 -> V_182 = V_8 ;
memcpy ( ( void * ) ( V_180 -> V_183 ) , ( void * ) V_181 , V_8 ) ;
F_88 ( V_33 -> V_19 -> V_44 . V_48 , V_19 -> V_44 . V_52 ) ;
return 0 ;
}
static void V_95 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_91 ( V_186 ,
struct V_1 , V_94 ) ;
struct V_187 { T_2 V_158 ; T_2 V_160 ; } * V_19 ;
union V_125 * V_83 ;
enum V_165 V_188 ;
struct V_189 * V_190 ;
struct V_191 * V_192 ;
unsigned long V_74 ;
T_5 V_193 = 0 ;
T_5 V_194 = 0 ;
T_5 V_195 = 0 ;
int V_77 ;
int V_92 ;
V_190 = (struct V_189 * ) V_2 -> V_196 ;
V_192 = V_190 -> V_192 ;
V_83 = V_2 -> V_27 . V_83 ;
V_19 = (struct V_187 * ) & V_83 -> V_19 . V_19 ;
F_43 ( & V_2 -> V_27 . V_98 ) ;
V_92 = F_49 ( V_2 ) ;
switch ( V_92 ) {
case - V_130 :
case - V_133 :
default:
if ( ! F_92 ( & V_190 -> V_197 ) ) {
V_190 -> V_198 = true ;
F_93 ( & V_190 -> V_197 ) ;
}
break;
case 0 :
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 ) {
V_2 -> V_80 [ V_77 ] . V_158 =
V_19 [ V_77 ] . V_158 ;
V_2 -> V_80 [ V_77 ] . V_160 =
V_19 [ V_77 ] . V_160 ;
continue;
}
V_188 = F_75 ( V_2 , V_77 ) ;
switch ( V_188 ) {
case V_170 :
default:
if ( ( V_19 [ V_77 ] . V_160 !=
V_161 ) &&
( V_19 [ V_77 ] . V_158 ==
V_159 ) &&
( V_19 [ V_77 ] . V_160 ==
V_19 [ V_2 -> V_79 ] . V_160 ) )
F_62 ( V_77 , & V_194 ) ;
else
F_62 ( V_77 , & V_193 ) ;
break;
case V_168 :
case V_167 :
if ( ( V_19 [ V_77 ] . V_160 ==
V_161 ) ||
( V_19 [ V_77 ] . V_158 !=
V_159 ) ||
( V_19 [ V_77 ] . V_160 !=
V_19 [ V_2 -> V_79 ] . V_160 ) ) {
F_62 ( V_77 ,
& V_190 -> V_199 ) ;
F_62 ( V_77 ,
& V_2 -> V_27 . V_86 ) ;
}
break;
case V_169 :
if ( ( V_19 [ V_77 ] . V_160 ==
V_161 ) ||
( V_19 [ V_77 ] . V_158 !=
V_159 ) ||
( V_19 [ V_77 ] . V_160 !=
V_19 [ V_2 -> V_79 ] . V_160 ) )
F_62 ( V_77 , & V_195 ) ;
break;
}
V_2 -> V_80 [ V_77 ] . V_158 =
V_19 [ V_77 ] . V_158 ;
V_2 -> V_80 [ V_77 ] . V_160 = V_19 [ V_77 ] . V_160 ;
}
break;
}
F_45 ( & V_2 -> V_27 . V_98 ) ;
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
if ( F_54 ( V_77 , & V_194 ) ) {
F_33 ( & V_2 -> V_89 , V_74 ) ;
F_24 ( & V_2 -> V_80 [ V_77 ] . V_87 ,
V_192 -> V_200 , V_192 -> V_40 ) ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
F_43 ( & V_2 -> V_27 . V_98 ) ;
V_92 = F_53 (
V_2 , V_77 , & V_2 -> V_80 [ V_77 ] ) ;
switch ( V_92 ) {
case 0 :
break;
case - V_130 :
case - V_133 :
default:
if ( ! F_92 ( & V_190 -> V_197 ) ) {
V_190 -> V_198 = true ;
F_93 (
& V_190 -> V_197 ) ;
}
break;
}
F_45 ( & V_2 -> V_27 . V_98 ) ;
V_2 -> V_80 [ V_77 ] . V_172
. V_201 += 1 ;
}
if ( F_54 ( V_77 , & V_193 ) ) {
F_43 ( & V_2 -> V_27 . V_98 ) ;
V_92 = F_63 ( V_2 , V_77 ) ;
switch ( V_92 ) {
case 0 :
break;
case - V_130 :
case - V_133 :
default:
if ( ! F_92 ( & V_190 -> V_197 ) ) {
V_190 -> V_198 = true ;
F_93 (
& V_190 -> V_197 ) ;
}
break;
}
F_45 ( & V_2 -> V_27 . V_98 ) ;
V_2 -> V_80 [ V_77 ] . V_172
. V_202 += 1 ;
if ( V_92 == 0 ) {
F_33 ( & V_2 -> V_89 , V_74 ) ;
F_24 (
& V_2 -> V_80 [ V_77 ] . V_87 ,
V_192 -> V_200 , V_192 -> V_40 ) ;
F_34 ( & V_2 -> V_89 ,
V_74 ) ;
}
}
if ( F_54 ( V_77 , & V_195 ) ) {
F_68 ( V_2 , V_77 ,
V_171 ) ;
V_2 -> V_80 [ V_77 ] . V_172 . V_173 += 1 ;
F_62 ( V_77 , & V_2 -> V_163 ) ;
F_33 ( & V_2 -> V_89 , V_74 ) ;
V_2 -> V_80 [ V_77 ] . V_87 .
V_19 -> V_44 . V_53 |=
V_174 ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
F_62 ( V_77 , & V_2 -> V_27 . V_86 ) ;
}
}
if ( V_195 || V_190 -> V_199 ) {
if ( ! F_92 ( & V_190 -> V_203 ) )
F_94 ( V_190 -> V_204 ,
& V_190 -> V_203 ) ;
}
}
static void V_97 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_91 ( V_186 , struct V_1 , V_96 ) ;
struct V_189 * V_190 = (struct V_189 * ) V_2 -> V_196 ;
unsigned long V_74 ;
T_5 V_205 ;
int V_206 ;
while ( ( V_205 = V_2 -> V_207 ) ) {
for ( V_206 = 0 ; V_205 ; V_205 >>= 1 , V_206 ++ ) {
if ( V_205 & 1 ) {
F_33 ( & V_2 -> V_89 , V_74 ) ;
V_2 -> V_80 [ V_206 ] .
V_87 . V_19 -> V_44 . V_53 |=
V_164 ;
F_34 ( & V_2 -> V_89 ,
V_74 ) ;
F_67 ( V_206 , & V_2 -> V_207 ) ;
F_62 ( V_206 ,
& V_190 -> V_199 ) ;
if ( ! F_92 ( & V_190 -> V_203 ) )
F_94 (
V_190 -> V_204 ,
& V_190 -> V_203 ) ;
}
}
}
}
int F_95 ( struct V_1 * V_2 )
{
union V_124 * V_81 = V_2 -> V_27 . V_81 ;
union V_125 * V_83 = V_2 -> V_27 . V_83 ;
enum V_105 V_92 ;
int V_135 ;
int V_76 = 0 ;
void * V_137 ;
int V_43 ;
if ( ! V_2 -> V_27 . V_100 )
return - V_132 ;
memset ( V_2 -> V_27 . V_100 , 0 , V_101 ) ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_208 . V_126 =
F_96 ( V_2 -> V_27 . V_102 ) ;
V_81 -> V_208 . V_209 = V_2 -> V_103 ;
V_81 -> V_208 . V_210 = V_2 -> V_27 . V_102 ;
V_135 = V_2 -> V_27 . V_102 / V_211 ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_137 = ( ( T_2 * ) V_2 -> V_27 . V_100 ) + V_43 * V_211 ;
V_81 -> V_208 . V_36 [ V_43 ] =
( V_140 ) ( F_56 ( F_57 ( V_137 ) ) +
F_58 ( V_137 ) ) ;
}
V_83 -> V_208 . V_126 = 0 ;
V_83 -> V_208 . V_128 = 0 ;
F_97 ( V_81 ) ;
V_92 = F_47 ( V_2 , V_212 ) ;
F_98 ( V_83 ) ;
if ( V_83 -> V_208 . V_126 !=
V_213 ) {
V_76 = - V_130 ;
F_99 ( L_3 ) ;
} else if ( V_92 == V_117 ) {
switch ( V_83 -> V_208 . V_128 ) {
case V_131 :
V_76 = 0 ;
break;
default:
V_76 = - V_132 ;
break;
}
} else {
switch ( V_92 ) {
case V_107 :
V_76 = - V_132 ;
break;
case V_118 :
F_99 ( L_5 ) ;
V_76 = - V_133 ;
break;
case V_121 :
case V_123 :
default:
V_76 = - V_132 ;
break;
}
}
return V_76 ;
}
int F_44 ( struct V_1 * V_2 )
{
union V_124 * V_81 = V_2 -> V_27 . V_81 ;
union V_125 * V_83 = V_2 -> V_27 . V_83 ;
enum V_105 V_92 ;
int V_76 = 0 ;
if ( ! V_2 -> V_27 . V_100 )
return - V_132 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_214 . V_126 = V_215 ;
V_83 -> V_214 . V_126 = 0 ;
V_83 -> V_214 . V_128 = 0 ;
V_92 = F_47 ( V_2 , V_216 ) ;
F_100 ( V_83 ) ;
if ( V_83 -> V_214 . V_126 != V_217 ) {
F_101 ( L_3 ) ;
V_76 = - V_130 ;
} else if ( V_92 == V_117 ) {
switch ( V_83 -> V_214 . V_128 ) {
case V_131 :
V_76 = 0 ;
V_2 -> V_103 = 0 ;
break;
default:
V_76 = - V_132 ;
break;
}
} else {
switch ( V_92 ) {
case V_107 :
V_76 = - V_132 ;
break;
case V_118 :
V_76 = - V_133 ;
F_101 ( L_5 ) ;
break;
case V_121 :
case V_123 :
default:
V_76 = - V_132 ;
break;
}
}
return V_76 ;
}
