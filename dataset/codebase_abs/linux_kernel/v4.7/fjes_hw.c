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
return V_92 ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_92 ;
if ( V_2 -> V_4 ) {
V_92 = F_10 ( V_2 ) ;
if ( V_92 )
F_5 ( L_2 , V_100 ) ;
F_7 ( V_2 ) ;
V_2 -> V_4 = NULL ;
}
F_36 ( V_2 ) ;
F_43 ( & V_2 -> V_94 ) ;
F_43 ( & V_2 -> V_96 ) ;
}
static enum V_101
F_44 ( struct V_1 * V_2 ,
enum V_102 type )
{
enum V_101 V_92 = V_103 ;
union V_104 V_105 ;
union V_106 V_107 ;
int V_12 ;
V_105 . V_3 = 0 ;
V_105 . V_13 . V_63 = 1 ;
V_105 . V_13 . V_108 = type ;
F_11 ( V_109 , V_105 . V_3 ) ;
V_105 . V_3 = F_12 ( V_109 ) ;
if ( V_105 . V_13 . error == 0 ) {
V_12 = V_110 * 1000 ;
V_107 . V_3 = F_12 ( V_111 ) ;
while ( ( V_107 . V_13 . V_112 != 1 ) && V_12 > 0 ) {
F_13 ( 1000 ) ;
V_107 . V_3 = F_12 ( V_111 ) ;
V_12 -= 1000 ;
}
if ( V_107 . V_13 . V_112 == 1 )
V_92 = V_113 ;
else if ( V_12 <= 0 )
V_92 = V_114 ;
} else {
switch ( V_105 . V_13 . V_115 ) {
case V_116 :
V_92 = V_117 ;
break;
case V_118 :
V_92 = V_119 ;
break;
default:
V_92 = V_103 ;
break;
}
}
return V_92 ;
}
int F_45 ( struct V_1 * V_2 )
{
union V_120 * V_81 = V_2 -> V_27 . V_81 ;
union V_121 * V_83 = V_2 -> V_27 . V_83 ;
enum V_101 V_92 ;
int V_76 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_19 . V_122 = V_123 ;
V_83 -> V_19 . V_122 = 0 ;
V_83 -> V_19 . V_124 = 0 ;
V_92 = F_44 ( V_2 , V_125 ) ;
V_76 = 0 ;
if ( F_46 ( ( * V_2 -> V_27 . V_26 ) ) !=
V_83 -> V_19 . V_122 ) {
V_76 = - V_126 ;
} else if ( V_92 == V_113 ) {
switch ( V_83 -> V_19 . V_124 ) {
case V_127 :
V_76 = 0 ;
break;
default:
V_76 = - V_128 ;
break;
}
} else {
switch ( V_92 ) {
case V_103 :
V_76 = - V_128 ;
break;
case V_114 :
V_76 = - V_129 ;
break;
case V_117 :
V_76 = - V_128 ;
break;
case V_119 :
V_76 = - V_128 ;
break;
default:
V_76 = - V_128 ;
break;
}
}
return V_76 ;
}
int F_47 ( struct V_1 * V_2 , int V_130 ,
struct V_72 * V_73 )
{
union V_120 * V_81 = V_2 -> V_27 . V_81 ;
union V_121 * V_83 = V_2 -> V_27 . V_83 ;
enum V_101 V_92 ;
int V_131 ;
int V_12 ;
int V_43 , V_132 ;
void * V_133 ;
int V_76 ;
if ( F_48 ( V_130 , & V_2 -> V_27 . V_85 ) )
return 0 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_134 . V_122 = F_49 (
V_73 -> V_87 . V_8 ,
V_73 -> V_88 . V_8 ) ;
V_81 -> V_134 . V_24 = V_130 ;
V_132 = 0 ;
V_81 -> V_134 . V_36 [ V_132 ++ ] = V_73 -> V_87 . V_8 ;
V_131 = V_73 -> V_87 . V_8 / V_135 ;
for ( V_43 = 0 ; V_43 < V_131 ; V_43 ++ ) {
V_133 = ( ( T_2 * ) ( V_73 -> V_87 . V_36 ) ) +
( V_43 * V_135 ) ;
V_81 -> V_134 . V_36 [ V_132 ++ ] =
( V_136 ) ( F_50 ( F_51 ( V_133 ) ) +
F_52 ( V_133 ) ) ;
}
V_81 -> V_134 . V_36 [ V_132 ++ ] = V_73 -> V_88 . V_8 ;
V_131 = V_73 -> V_88 . V_8 / V_135 ;
for ( V_43 = 0 ; V_43 < V_131 ; V_43 ++ ) {
V_133 = ( ( T_2 * ) ( V_73 -> V_88 . V_36 ) ) +
( V_43 * V_135 ) ;
V_81 -> V_134 . V_36 [ V_132 ++ ] =
( V_136 ) ( F_50 ( F_51 ( V_133 ) ) +
F_52 ( V_133 ) ) ;
}
V_83 -> V_134 . V_122 = 0 ;
V_83 -> V_134 . V_124 = 0 ;
V_92 = F_44 ( V_2 , V_137 ) ;
V_12 = V_138 * 1000 ;
while ( ( V_92 == V_113 ) &&
( V_83 -> V_134 . V_122 ==
V_139 ) &&
( V_83 -> V_134 . V_124 == V_140 ) &&
( V_12 > 0 ) ) {
F_13 ( 200 + V_2 -> V_79 * 20 ) ;
V_12 -= ( 200 + V_2 -> V_79 * 20 ) ;
V_83 -> V_134 . V_122 = 0 ;
V_83 -> V_134 . V_124 = 0 ;
V_92 = F_44 (
V_2 , V_137 ) ;
}
V_76 = 0 ;
if ( V_83 -> V_134 . V_122 !=
V_139 )
V_76 = - V_126 ;
else if ( V_92 == V_113 ) {
switch ( V_83 -> V_134 . V_124 ) {
case V_127 :
V_76 = 0 ;
F_53 ( V_130 , & V_2 -> V_27 . V_85 ) ;
break;
case V_140 :
V_76 = - V_129 ;
break;
default:
V_76 = - V_128 ;
break;
}
} else {
switch ( V_92 ) {
case V_103 :
V_76 = - V_128 ;
break;
case V_114 :
V_76 = - V_129 ;
break;
case V_117 :
case V_119 :
default:
V_76 = - V_128 ;
break;
}
}
return V_76 ;
}
int F_54 ( struct V_1 * V_2 , int V_130 )
{
union V_120 * V_81 = V_2 -> V_27 . V_81 ;
union V_121 * V_83 = V_2 -> V_27 . V_83 ;
struct V_25 * V_28 = V_2 -> V_27 . V_28 ;
enum V_101 V_92 ;
int V_12 ;
int V_76 ;
if ( ! V_2 -> V_4 )
return - V_128 ;
if ( ! V_81 || ! V_83 || ! V_28 )
return - V_128 ;
if ( ! F_48 ( V_130 , & V_2 -> V_27 . V_85 ) )
return 0 ;
memset ( V_81 , 0 , V_2 -> V_27 . V_82 ) ;
memset ( V_83 , 0 , V_2 -> V_27 . V_84 ) ;
V_81 -> V_141 . V_122 =
V_142 ;
V_81 -> V_141 . V_24 = V_130 ;
V_83 -> V_141 . V_122 = 0 ;
V_83 -> V_141 . V_124 = 0 ;
V_92 = F_44 ( V_2 , V_143 ) ;
V_12 = V_138 * 1000 ;
while ( ( V_92 == V_113 ) &&
( V_83 -> V_141 . V_122 ==
V_144 ) &&
( V_83 -> V_141 . V_124 ==
V_140 ) &&
( V_12 > 0 ) ) {
F_13 ( 200 + V_2 -> V_79 * 20 ) ;
V_12 -= ( 200 + V_2 -> V_79 * 20 ) ;
V_83 -> V_141 . V_122 = 0 ;
V_83 -> V_141 . V_124 = 0 ;
V_92 =
F_44 ( V_2 , V_143 ) ;
}
V_76 = 0 ;
if ( V_83 -> V_141 . V_122 !=
V_144 ) {
V_76 = - V_126 ;
} else if ( V_92 == V_113 ) {
switch ( V_83 -> V_141 . V_124 ) {
case V_127 :
V_76 = 0 ;
F_55 ( V_130 , & V_2 -> V_27 . V_85 ) ;
break;
case V_140 :
V_76 = - V_129 ;
break;
default:
V_76 = - V_128 ;
break;
}
} else {
switch ( V_92 ) {
case V_103 :
V_76 = - V_128 ;
break;
case V_114 :
V_76 = - V_129 ;
break;
case V_117 :
case V_119 :
default:
V_76 = - V_128 ;
break;
}
}
return V_76 ;
}
int F_56 ( struct V_1 * V_2 , int V_130 ,
enum V_145 V_146 )
{
T_1 V_147 = V_146 | V_130 ;
F_11 ( V_148 , F_57 ( V_147 ) ) ;
return 0 ;
}
T_1 F_58 ( struct V_1 * V_2 )
{
T_1 V_149 ;
V_149 = F_12 ( V_150 ) ;
return V_149 ;
}
void F_38 ( struct V_1 * V_2 ,
enum V_145 V_151 , bool V_146 )
{
if ( V_146 )
F_11 ( V_152 , V_151 ) ;
else
F_11 ( V_153 , V_151 ) ;
}
bool F_59 ( struct V_1 * V_2 , int V_24 )
{
if ( V_24 >= V_2 -> V_26 )
return false ;
if ( ( V_2 -> V_80 [ V_24 ] . V_154 !=
V_155 ) ||
( V_2 -> V_80 [ V_2 -> V_79 ] . V_156 ==
V_157 ) )
return false ;
else
return ( V_2 -> V_80 [ V_24 ] . V_156 ==
V_2 -> V_80 [ V_2 -> V_79 ] . V_156 ) ;
}
int F_60 ( struct V_25 * V_28 ,
int V_130 )
{
int V_5 = false ;
if ( V_130 < V_28 -> V_31 )
V_5 = V_28 -> V_91 [ V_130 ] ;
return V_5 ;
}
static bool F_61 ( struct V_1 * V_2 , int V_158 )
{
return F_48 ( V_158 , & V_2 -> V_159 ) ;
}
static bool F_62 ( struct V_1 * V_2 , int V_158 )
{
return ( V_2 -> V_80 [ V_158 ] . V_87 . V_19 -> V_44 . V_53 &
V_160 ) ;
}
enum V_161
F_63 ( struct V_1 * V_2 , int V_24 )
{
enum V_161 V_162 ;
if ( F_60 ( V_2 -> V_27 . V_28 , V_24 ) ) {
if ( F_61 ( V_2 , V_24 ) ) {
V_162 = V_163 ;
} else {
if ( F_62 ( V_2 , V_24 ) )
V_162 = V_164 ;
else
V_162 = V_165 ;
}
} else {
V_162 = V_166 ;
}
return V_162 ;
}
void F_64 ( struct V_1 * V_2 )
{
enum V_161 V_162 ;
unsigned long V_74 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
V_162 = F_63 ( V_2 , V_77 ) ;
switch ( V_162 ) {
case V_165 :
F_56 ( V_2 , V_77 ,
V_167 ) ;
break;
default:
break;
}
F_53 ( V_77 , & V_2 -> V_27 . V_86 ) ;
F_53 ( V_77 , & V_2 -> V_159 ) ;
F_33 ( & V_2 -> V_89 , V_74 ) ;
V_2 -> V_80 [ V_77 ] . V_87 . V_19 -> V_44 . V_53 |=
V_168 ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
}
}
int F_65 ( struct V_1 * V_2 )
{
enum V_161 V_162 ;
union V_37 * V_19 ;
int V_169 = 0 ;
int V_77 ;
while ( V_2 -> V_27 . V_86 &&
( V_169 < V_170 * 1000 ) ) {
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
V_162 = F_60 ( V_2 -> V_27 . V_28 ,
V_77 ) ;
V_19 = V_2 -> V_80 [ V_77 ] . V_88 . V_19 ;
if ( ( ! V_162 ||
( V_19 -> V_44 . V_53 &
V_160 ) ) &&
F_48 ( V_77 ,
& V_2 -> V_27 . V_86 ) ) {
F_55 ( V_77 ,
& V_2 -> V_27 . V_86 ) ;
}
}
F_13 ( 100 ) ;
V_169 += 100 ;
}
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
if ( F_48 ( V_77 , & V_2 -> V_27 . V_86 ) )
F_55 ( V_77 ,
& V_2 -> V_27 . V_86 ) ;
}
return ( V_169 < V_170 * 1000 )
? 0 : - V_129 ;
}
bool F_66 ( struct V_32 * V_33 , T_1 V_45 )
{
union V_37 * V_19 = V_33 -> V_19 ;
return ( V_19 -> V_171 . V_45 == V_45 ) ;
}
bool F_67 ( struct V_32 * V_33 , T_1 V_40 )
{
union V_37 * V_19 = V_33 -> V_19 ;
return ( ( V_19 -> V_44 . V_51 == F_25 ( V_40 ) ) &&
V_19 -> V_44 . V_53 & V_54 ) ;
}
bool F_68 ( struct V_32 * V_33 , T_4 V_41 )
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
bool F_69 ( struct V_32 * V_33 , T_4 V_41 )
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
void F_70 ( struct V_32 * V_33 , T_4 V_41 )
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
bool F_71 ( struct V_32 * V_33 )
{
union V_37 * V_19 = V_33 -> V_19 ;
if ( ! ( V_19 -> V_44 . V_53 & V_54 ) )
return true ;
if ( V_19 -> V_44 . V_52 == 0 )
return true ;
return F_72 ( V_19 -> V_44 . V_47 , V_19 -> V_44 . V_48 ,
V_19 -> V_44 . V_52 ) ;
}
void * F_73 ( struct V_32 * V_33 ,
T_3 * V_172 )
{
union V_37 * V_19 = V_33 -> V_19 ;
struct V_173 * V_174 ;
void * V_175 ;
V_174 = (struct V_173 * ) & ( V_33 -> V_38 [ F_74
( V_19 -> V_44 . V_47 ,
V_19 -> V_44 . V_52 ) *
V_19 -> V_44 . V_51 ] ) ;
* V_172 = ( T_3 ) V_174 -> V_176 ;
V_175 = V_174 -> V_177 ;
return V_175 ;
}
void F_75 ( struct V_32 * V_33 )
{
union V_37 * V_19 = V_33 -> V_19 ;
if ( F_71 ( V_33 ) )
return;
F_76 ( V_33 -> V_19 -> V_44 . V_47 , V_19 -> V_44 . V_52 ) ;
}
int F_77 ( struct V_32 * V_33 ,
void * V_175 , T_3 V_8 )
{
union V_37 * V_19 = V_33 -> V_19 ;
struct V_173 * V_174 ;
if ( F_78 ( V_19 -> V_44 . V_47 , V_19 -> V_44 . V_48 , V_19 -> V_44 . V_52 ) )
return - V_178 ;
V_174 = (struct V_173 * ) & ( V_33 -> V_38 [ F_74
( V_19 -> V_44 . V_48 - 1 ,
V_19 -> V_44 . V_52 ) *
V_19 -> V_44 . V_51 ] ) ;
V_174 -> V_176 = V_8 ;
memcpy ( ( void * ) ( V_174 -> V_177 ) , ( void * ) V_175 , V_8 ) ;
F_76 ( V_33 -> V_19 -> V_44 . V_48 , V_19 -> V_44 . V_52 ) ;
return 0 ;
}
static void V_95 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = F_79 ( V_180 ,
struct V_1 , V_94 ) ;
struct V_181 { T_2 V_154 ; T_2 V_156 ; } * V_19 ;
union V_121 * V_83 ;
enum V_161 V_182 ;
struct V_183 * V_184 ;
struct V_185 * V_186 ;
unsigned long V_74 ;
T_5 V_187 = 0 ;
T_5 V_188 = 0 ;
T_5 V_189 = 0 ;
int V_77 ;
int V_92 ;
V_184 = (struct V_183 * ) V_2 -> V_190 ;
V_186 = V_184 -> V_186 ;
V_83 = V_2 -> V_27 . V_83 ;
V_19 = (struct V_181 * ) & V_83 -> V_19 . V_19 ;
F_80 ( & V_2 -> V_27 . V_98 ) ;
V_92 = F_45 ( V_2 ) ;
switch ( V_92 ) {
case - V_126 :
case - V_129 :
default:
if ( ! F_81 ( & V_184 -> V_191 ) ) {
V_184 -> V_192 = true ;
F_82 ( & V_184 -> V_191 ) ;
}
break;
case 0 :
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 ) {
V_2 -> V_80 [ V_77 ] . V_154 =
V_19 [ V_77 ] . V_154 ;
V_2 -> V_80 [ V_77 ] . V_156 =
V_19 [ V_77 ] . V_156 ;
continue;
}
V_182 = F_63 ( V_2 , V_77 ) ;
switch ( V_182 ) {
case V_166 :
default:
if ( ( V_19 [ V_77 ] . V_156 !=
V_157 ) &&
( V_19 [ V_77 ] . V_154 ==
V_155 ) &&
( V_19 [ V_77 ] . V_156 ==
V_19 [ V_2 -> V_79 ] . V_156 ) )
F_53 ( V_77 , & V_188 ) ;
else
F_53 ( V_77 , & V_187 ) ;
break;
case V_164 :
case V_163 :
if ( ( V_19 [ V_77 ] . V_156 ==
V_157 ) ||
( V_19 [ V_77 ] . V_154 !=
V_155 ) ||
( V_19 [ V_77 ] . V_156 !=
V_19 [ V_2 -> V_79 ] . V_156 ) ) {
F_53 ( V_77 ,
& V_184 -> V_193 ) ;
F_53 ( V_77 ,
& V_2 -> V_27 . V_86 ) ;
}
break;
case V_165 :
if ( ( V_19 [ V_77 ] . V_156 ==
V_157 ) ||
( V_19 [ V_77 ] . V_154 !=
V_155 ) ||
( V_19 [ V_77 ] . V_156 !=
V_19 [ V_2 -> V_79 ] . V_156 ) )
F_53 ( V_77 , & V_189 ) ;
break;
}
V_2 -> V_80 [ V_77 ] . V_154 =
V_19 [ V_77 ] . V_154 ;
V_2 -> V_80 [ V_77 ] . V_156 = V_19 [ V_77 ] . V_156 ;
}
break;
}
F_83 ( & V_2 -> V_27 . V_98 ) ;
for ( V_77 = 0 ; V_77 < V_2 -> V_26 ; V_77 ++ ) {
if ( V_77 == V_2 -> V_79 )
continue;
if ( F_48 ( V_77 , & V_188 ) ) {
F_33 ( & V_2 -> V_89 , V_74 ) ;
F_24 ( & V_2 -> V_80 [ V_77 ] . V_87 ,
V_186 -> V_194 , V_186 -> V_40 ) ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
F_80 ( & V_2 -> V_27 . V_98 ) ;
V_92 = F_47 (
V_2 , V_77 , & V_2 -> V_80 [ V_77 ] ) ;
switch ( V_92 ) {
case 0 :
break;
case - V_126 :
case - V_129 :
default:
if ( ! F_81 ( & V_184 -> V_191 ) ) {
V_184 -> V_192 = true ;
F_82 (
& V_184 -> V_191 ) ;
}
break;
}
F_83 ( & V_2 -> V_27 . V_98 ) ;
}
if ( F_48 ( V_77 , & V_187 ) ) {
F_80 ( & V_2 -> V_27 . V_98 ) ;
V_92 = F_54 ( V_2 , V_77 ) ;
switch ( V_92 ) {
case 0 :
break;
case - V_126 :
case - V_129 :
default:
if ( ! F_81 ( & V_184 -> V_191 ) ) {
V_184 -> V_192 = true ;
F_82 (
& V_184 -> V_191 ) ;
}
break;
}
F_83 ( & V_2 -> V_27 . V_98 ) ;
if ( V_92 == 0 ) {
F_33 ( & V_2 -> V_89 , V_74 ) ;
F_24 (
& V_2 -> V_80 [ V_77 ] . V_87 ,
V_186 -> V_194 , V_186 -> V_40 ) ;
F_34 ( & V_2 -> V_89 ,
V_74 ) ;
}
}
if ( F_48 ( V_77 , & V_189 ) ) {
F_56 ( V_2 , V_77 ,
V_167 ) ;
F_53 ( V_77 , & V_2 -> V_159 ) ;
F_33 ( & V_2 -> V_89 , V_74 ) ;
V_2 -> V_80 [ V_77 ] . V_87 .
V_19 -> V_44 . V_53 |=
V_168 ;
F_34 ( & V_2 -> V_89 , V_74 ) ;
F_53 ( V_77 , & V_2 -> V_27 . V_86 ) ;
}
}
if ( V_189 || V_184 -> V_193 ) {
if ( ! F_81 ( & V_184 -> V_195 ) )
F_84 ( V_184 -> V_196 ,
& V_184 -> V_195 ) ;
}
}
static void V_97 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = F_79 ( V_180 , struct V_1 , V_96 ) ;
struct V_183 * V_184 = (struct V_183 * ) V_2 -> V_190 ;
unsigned long V_74 ;
T_5 V_197 ;
int V_198 ;
while ( ( V_197 = V_2 -> V_199 ) ) {
for ( V_198 = 0 ; V_197 ; V_197 >>= 1 , V_198 ++ ) {
if ( V_197 & 1 ) {
F_33 ( & V_2 -> V_89 , V_74 ) ;
V_2 -> V_80 [ V_198 ] .
V_87 . V_19 -> V_44 . V_53 |=
V_160 ;
F_34 ( & V_2 -> V_89 ,
V_74 ) ;
F_55 ( V_198 , & V_2 -> V_199 ) ;
F_53 ( V_198 ,
& V_184 -> V_193 ) ;
if ( ! F_81 ( & V_184 -> V_195 ) )
F_84 (
V_184 -> V_196 ,
& V_184 -> V_195 ) ;
}
}
}
}
