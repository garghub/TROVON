static int
F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
V_8 = (* V_7 -> V_9 )( V_2 , V_3 ,
V_4 , V_5 ) ;
return V_8 ;
}
static int
F_2 ( struct V_1 * V_2 , T_2 V_10 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_12 ;
int V_8 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_15 = true ;
V_8 = F_1 ( V_2 , V_3 , 0 , NULL ) ;
return V_8 ;
}
static void
F_3 ( struct V_1 * V_2 , bool V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_3 = V_16 ;
if ( V_11 )
V_3 |= V_13 ;
else
V_3 |= V_14 ;
if ( V_7 -> V_15 ) {
( void ) F_1 ( V_2 , V_3 , 0 , NULL ) ;
V_7 -> V_15 = false ;
}
}
static int
F_4 ( struct V_1 * V_2 , T_3 V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_14 , V_17 , NULL ) ;
return V_8 ;
}
static int
F_5 ( struct V_1 * V_2 , T_3 * V_19 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
if ( ! V_7 -> V_15 )
return - V_18 ;
V_8 = F_1 ( V_2 , V_13 , 0 , V_19 ) ;
return V_8 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
int V_22 )
{
int V_8 = 0 ;
bool V_11 = false ;
int V_23 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
T_2 V_25 = V_21 [ V_23 ] . V_25 ;
T_3 * V_26 = V_21 [ V_23 ] . V_26 ;
V_11 = ( V_21 [ V_23 ] . V_27 & V_28 ) != 0 ;
V_8 = F_2 ( V_2 , V_21 [ V_23 ] . V_29 , V_11 ) ;
if ( V_8 < 0 )
break;
if ( V_11 ) {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_5 ( V_2 , & V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
} else {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_8 = F_4 ( V_2 , V_26 [ V_24 ] ) ;
if ( V_8 < 0 )
break;
}
}
if ( V_8 < 0 )
break;
}
if ( V_8 >= 0 )
V_8 = V_22 ;
F_3 ( V_2 , V_11 ) ;
F_7 ( L_1 , V_8 ) ;
return V_8 ;
}
static T_4
F_8 ( struct V_1 * V_2 )
{
return V_30 | V_31 |
V_32 |
V_33 |
V_34 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
( void ) F_2 ( V_2 , 0 , false ) ;
( void ) F_3 ( V_2 , false ) ;
}
static int
F_10 ( struct V_1 * V_2 )
{
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = 3 ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
int error ;
error = F_10 ( V_2 ) ;
if ( error )
return error ;
error = F_12 ( V_2 ) ;
return error ;
}
static bool F_13 ( struct V_38 * V_39 )
{
return V_39 -> type == V_40 ;
}
static int
F_14 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
int V_44 = 4 ;
if ( V_42 -> V_45 [ V_46 ] >= 0x11 ) {
V_44 = V_42 -> V_45 [ V_47 ] & 0x1f ;
switch ( V_44 ) {
case 1 : case 2 : case 4 :
break;
default:
V_44 = 4 ;
}
}
return V_44 ;
}
static int
F_15 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
int V_48 = V_42 -> V_45 [ V_49 ] ;
switch ( V_48 ) {
case V_50 :
case V_51 :
break;
default:
V_48 = V_50 ;
break;
}
return V_48 ;
}
static int
F_16 ( T_1 V_52 )
{
if ( V_52 == V_51 )
return 270000 ;
else
return 162000 ;
}
static int
F_17 ( int V_53 , int V_54 )
{
return ( V_53 * V_54 + 7 ) / 8 ;
}
static int
F_18 ( int V_55 , int V_56 )
{
return ( V_55 * V_56 * 19 ) / 20 ;
}
static void F_19 ( struct V_38 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 . V_59 ;
struct V_41 * V_42 = V_57 -> V_43 ;
T_4 V_61 ;
if ( V_42 -> V_62 ) {
F_7 ( L_2 ) ;
return;
}
F_7 ( L_3 ) ;
V_61 = F_20 ( V_63 ) ;
V_61 |= V_64 ;
F_21 ( V_63 , V_61 ) ;
F_20 ( V_63 ) ;
F_22 ( V_42 -> V_65 ) ;
}
static void F_23 ( struct V_38 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 . V_59 ;
T_4 V_61 ;
F_7 ( L_3 ) ;
V_61 = F_20 ( V_63 ) ;
V_61 &= ~ V_64 ;
F_21 ( V_63 , V_61 ) ;
F_20 ( V_63 ) ;
}
static bool F_24 ( struct V_38 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 . V_59 ;
struct V_41 * V_42 = V_57 -> V_43 ;
T_4 V_61 , V_66 = V_67 | V_68 ;
if ( V_42 -> V_62 )
return true ;
F_7 ( L_3 ) ;
V_61 = F_20 ( V_63 ) ;
V_61 &= ~ V_69 ;
V_61 |= ( V_70 | V_71 ) ;
F_21 ( V_63 , V_61 ) ;
F_20 ( V_63 ) ;
if ( F_25 ( ( ( F_20 ( V_72 ) & V_66 ) == V_66 ) , 1000 ) ) {
F_7 ( L_4 , F_20 ( V_72 ) ) ;
V_42 -> V_62 = false ;
} else
V_42 -> V_62 = true ;
F_22 ( V_42 -> V_65 ) ;
return false ;
}
static void F_26 ( struct V_38 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 . V_59 ;
T_4 V_61 , V_73 = V_67 ;
struct V_41 * V_42 = V_57 -> V_43 ;
F_7 ( L_3 ) ;
V_61 = F_20 ( V_63 ) ;
if ( ( V_61 & V_71 ) == 0 )
return;
V_42 -> V_62 = false ;
V_61 &= ~ V_69 ;
V_61 &= ~ V_71 ;
V_61 &= ~ V_64 ;
V_61 &= ~ V_74 ;
F_21 ( V_63 , V_61 ) ;
F_20 ( V_63 ) ;
F_7 ( L_5 , F_20 ( V_72 ) ) ;
if ( F_25 ( ( F_20 ( V_72 ) & V_73 ) == 0 , 1000 ) ) {
F_7 ( L_6 ) ;
}
F_22 ( V_42 -> V_75 ) ;
F_7 ( L_7 ) ;
}
static void F_27 ( struct V_38 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 . V_59 ;
T_4 V_61 ;
F_7 ( L_3 ) ;
F_22 ( 300 ) ;
V_61 = F_20 ( V_63 ) ;
V_61 |= V_74 ;
F_21 ( V_63 , V_61 ) ;
F_28 ( V_59 ) ;
}
static void F_29 ( struct V_38 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 . V_59 ;
struct V_41 * V_42 = V_57 -> V_43 ;
T_4 V_61 ;
F_7 ( L_3 ) ;
F_30 ( V_59 ) ;
F_22 ( 10 ) ;
V_61 = F_20 ( V_63 ) ;
V_61 &= ~ V_74 ;
F_21 ( V_63 , V_61 ) ;
F_22 ( V_42 -> V_76 ) ;
}
static int
F_31 ( struct V_77 * V_78 ,
struct V_79 * V_3 )
{
struct V_38 * V_39 = F_32 ( V_78 ) ;
struct V_41 * V_42 = V_39 -> V_43 ;
int V_55 = F_16 ( F_15 ( V_39 ) ) ;
int V_56 = F_14 ( V_39 ) ;
struct V_80 * V_43 = V_78 -> V_59 -> V_81 ;
if ( F_13 ( V_39 ) && V_42 -> V_82 ) {
if ( V_3 -> V_83 > V_42 -> V_82 -> V_83 )
return V_84 ;
if ( V_3 -> V_85 > V_42 -> V_82 -> V_85 )
return V_84 ;
}
if ( ! F_13 ( V_39 ) &&
( F_17 ( V_3 -> clock , V_43 -> V_86 . V_54 )
> F_18 ( V_55 , V_56 ) ) )
return V_87 ;
if ( F_13 ( V_39 ) ) {
if ( F_17 ( V_3 -> clock , 24 )
> F_18 ( V_55 , V_56 ) )
return V_87 ;
}
if ( V_3 -> clock < 10000 )
return V_88 ;
return V_89 ;
}
static T_5
F_33 ( T_1 * V_90 , int V_91 )
{
int V_92 ;
T_5 V_93 = 0 ;
if ( V_91 > 4 )
V_91 = 4 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ )
V_93 |= ( ( T_5 ) V_90 [ V_92 ] ) << ( ( 3 - V_92 ) * 8 ) ;
return V_93 ;
}
static void
F_34 ( T_5 V_90 , T_1 * V_94 , int V_95 )
{
int V_92 ;
if ( V_95 > 4 )
V_95 = 4 ;
for ( V_92 = 0 ; V_92 < V_95 ; V_92 ++ )
V_94 [ V_92 ] = V_90 >> ( ( 3 - V_92 ) * 8 ) ;
}
static int
F_35 ( struct V_38 * V_39 ,
T_1 * V_96 , int V_97 ,
T_1 * V_98 , int V_99 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_5 V_100 = V_42 -> V_100 ;
struct V_58 * V_59 = V_39 -> V_60 . V_59 ;
T_5 V_101 = V_100 + 0x10 ;
T_5 V_102 = V_101 + 4 ;
int V_92 ;
int V_103 ;
T_5 V_104 ;
T_5 V_105 ;
int V_106 , V_107 ;
V_105 = 200 / 2 ;
V_107 = 4 ;
if ( F_13 ( V_39 ) )
V_107 = 10 ;
if ( F_20 ( V_101 ) & V_108 ) {
F_36 ( L_8 ,
F_20 ( V_101 ) ) ;
return - V_109 ;
}
for ( V_106 = 0 ; V_106 < 5 ; V_106 ++ ) {
for ( V_92 = 0 ; V_92 < V_97 ; V_92 += 4 )
F_21 ( V_102 + V_92 ,
F_33 ( V_96 + V_92 , V_97 - V_92 ) ) ;
F_21 ( V_101 ,
V_108 |
V_110 |
( V_97 << V_111 ) |
( V_107 << V_112 ) |
( V_105 << V_113 ) |
V_114 |
V_115 |
V_116 ) ;
for (; ; ) {
V_104 = F_20 ( V_101 ) ;
if ( ( V_104 & V_108 ) == 0 )
break;
F_37 ( 100 ) ;
}
F_21 ( V_101 ,
V_104 |
V_114 |
V_115 |
V_116 ) ;
if ( V_104 & V_114 )
break;
}
if ( ( V_104 & V_114 ) == 0 ) {
F_36 ( L_9 , V_104 ) ;
return - V_109 ;
}
if ( V_104 & V_116 ) {
F_36 ( L_10 , V_104 ) ;
return - V_18 ;
}
if ( V_104 & V_115 ) {
F_7 ( L_11 , V_104 ) ;
return - V_117 ;
}
V_103 = ( ( V_104 & V_118 ) >>
V_111 ) ;
if ( V_103 > V_99 )
V_103 = V_99 ;
for ( V_92 = 0 ; V_92 < V_103 ; V_92 += 4 )
F_34 ( F_20 ( V_102 + V_92 ) ,
V_98 + V_92 , V_103 - V_92 ) ;
return V_103 ;
}
static int
F_38 ( struct V_38 * V_39 ,
T_6 V_10 , T_1 * V_96 , int V_97 )
{
int V_8 ;
T_1 V_119 [ 20 ] ;
int V_120 ;
T_1 V_121 ;
if ( V_97 > 16 )
return - 1 ;
V_119 [ 0 ] = V_122 << 4 ;
V_119 [ 1 ] = V_10 >> 8 ;
V_119 [ 2 ] = V_10 & 0xff ;
V_119 [ 3 ] = V_97 - 1 ;
memcpy ( & V_119 [ 4 ] , V_96 , V_97 ) ;
V_120 = V_97 + 4 ;
for (; ; ) {
V_8 = F_35 ( V_39 , V_119 , V_120 , & V_121 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_121 >>= 4 ;
if ( ( V_121 & V_123 ) == V_124 )
break;
else if ( ( V_121 & V_123 ) == V_125 )
F_37 ( 100 ) ;
else
return - V_18 ;
}
return V_97 ;
}
static int
F_39 ( struct V_38 * V_39 ,
T_6 V_10 , T_1 V_17 )
{
return F_38 ( V_39 , V_10 , & V_17 , 1 ) ;
}
static int
F_40 ( struct V_38 * V_39 ,
T_6 V_10 , T_1 * V_98 , int V_103 )
{
T_1 V_119 [ 4 ] ;
int V_120 ;
T_1 V_126 [ 20 ] ;
int V_127 ;
T_1 V_121 ;
int V_8 ;
V_119 [ 0 ] = V_128 << 4 ;
V_119 [ 1 ] = V_10 >> 8 ;
V_119 [ 2 ] = V_10 & 0xff ;
V_119 [ 3 ] = V_103 - 1 ;
V_120 = 4 ;
V_127 = V_103 + 1 ;
for (; ; ) {
V_8 = F_35 ( V_39 , V_119 , V_120 ,
V_126 , V_127 ) ;
if ( V_8 == 0 )
return - V_129 ;
if ( V_8 < 0 )
return V_8 ;
V_121 = V_126 [ 0 ] >> 4 ;
if ( ( V_121 & V_123 ) == V_124 ) {
memcpy ( V_98 , V_126 + 1 , V_8 - 1 ) ;
return V_8 - 1 ;
}
else if ( ( V_121 & V_123 ) == V_125 )
F_37 ( 100 ) ;
else
return - V_18 ;
}
}
static int
F_41 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_41 * V_42 = F_42 ( V_2 ,
struct V_41 ,
V_2 ) ;
struct V_38 * V_39 = V_42 -> V_39 ;
T_6 V_10 = V_7 -> V_10 ;
T_1 V_119 [ 5 ] ;
T_1 V_126 [ 2 ] ;
unsigned V_130 ;
int V_120 ;
int V_127 ;
int V_8 ;
if ( V_3 & V_13 )
V_119 [ 0 ] = V_131 << 4 ;
else
V_119 [ 0 ] = V_132 << 4 ;
if ( ! ( V_3 & V_16 ) )
V_119 [ 0 ] |= V_133 << 4 ;
V_119 [ 1 ] = V_10 >> 8 ;
V_119 [ 2 ] = V_10 ;
switch ( V_3 ) {
case V_14 :
V_119 [ 3 ] = 0 ;
V_119 [ 4 ] = V_4 ;
V_120 = 5 ;
V_127 = 1 ;
break;
case V_13 :
V_119 [ 3 ] = 0 ;
V_120 = 4 ;
V_127 = 2 ;
break;
default:
V_120 = 3 ;
V_127 = 1 ;
break;
}
for ( V_130 = 0 ; V_130 < 5 ; V_130 ++ ) {
V_8 = F_35 ( V_39 ,
V_119 , V_120 ,
V_126 , V_127 ) ;
if ( V_8 < 0 ) {
F_7 ( L_12 , V_8 ) ;
return V_8 ;
}
switch ( ( V_126 [ 0 ] >> 4 ) & V_123 ) {
case V_124 :
break;
case V_134 :
F_7 ( L_13 ) ;
return - V_135 ;
case V_125 :
F_37 ( 100 ) ;
continue;
default:
F_36 ( L_14 ,
V_126 [ 0 ] ) ;
return - V_135 ;
}
switch ( ( V_126 [ 0 ] >> 4 ) & V_136 ) {
case V_137 :
if ( V_3 == V_13 ) {
* V_5 = V_126 [ 1 ] ;
}
return V_127 - 1 ;
case V_138 :
F_7 ( L_15 ) ;
return - V_135 ;
case V_139 :
F_7 ( L_16 ) ;
F_37 ( 100 ) ;
break;
default:
F_36 ( L_17 , V_126 [ 0 ] ) ;
return - V_135 ;
}
}
F_36 ( L_18 ) ;
return - V_135 ;
}
static int
F_43 ( struct V_140 * V_78 ,
struct V_38 * V_39 , const char * V_141 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
int V_8 ;
F_7 ( L_19 , V_141 ) ;
V_42 -> V_35 . V_15 = false ;
V_42 -> V_35 . V_10 = 0 ;
V_42 -> V_35 . V_9 = F_41 ;
memset ( & V_42 -> V_2 , '\0' , sizeof ( V_42 -> V_2 ) ) ;
V_42 -> V_2 . V_142 = V_143 ;
V_42 -> V_2 . V_144 = V_145 ;
strncpy ( V_42 -> V_2 . V_141 , V_141 , sizeof( V_42 -> V_2 . V_141 ) - 1 ) ;
V_42 -> V_2 . V_141 [ sizeof( V_42 -> V_2 . V_141 ) - 1 ] = '\0' ;
V_42 -> V_2 . V_7 = & V_42 -> V_35 ;
V_42 -> V_2 . V_59 . V_146 = V_78 -> V_60 . V_147 ;
if ( F_13 ( V_39 ) )
F_19 ( V_39 ) ;
V_8 = F_11 ( & V_42 -> V_2 ) ;
if ( F_13 ( V_39 ) )
F_23 ( V_39 ) ;
return V_8 ;
}
static void F_44 ( struct V_79 * V_148 ,
struct V_79 * V_149 )
{
V_149 -> V_83 = V_148 -> V_83 ;
V_149 -> V_150 = V_148 -> V_150 ;
V_149 -> V_151 = V_148 -> V_151 ;
V_149 -> V_152 = V_148 -> V_152 ;
V_149 -> V_85 = V_148 -> V_85 ;
V_149 -> V_153 = V_148 -> V_153 ;
V_149 -> V_154 = V_148 -> V_154 ;
V_149 -> V_155 = V_148 -> V_155 ;
V_149 -> clock = V_148 -> clock ;
F_45 ( V_149 , V_156 ) ;
}
static bool
F_46 ( struct V_157 * V_39 , const struct V_79 * V_3 ,
struct V_79 * V_149 )
{
struct V_80 * V_43 = V_39 -> V_59 -> V_81 ;
struct V_38 * V_57 = F_47 ( V_39 ) ;
struct V_41 * V_42 = V_57 -> V_43 ;
int V_158 , clock ;
int V_44 = F_14 ( V_57 ) ;
int V_159 = F_15 ( V_57 ) == V_51 ? 1 : 0 ;
static int V_160 [ 2 ] = { V_50 , V_51 } ;
int V_161 = V_3 -> clock ;
int V_54 = 24 ;
if ( F_13 ( V_57 ) && V_42 -> V_82 ) {
F_44 ( V_42 -> V_82 , V_149 ) ;
V_161 = V_42 -> V_82 -> clock ;
V_54 = V_43 -> V_86 . V_54 ;
}
for ( V_158 = 1 ; V_158 <= V_44 ; V_158 <<= 1 ) {
for ( clock = V_159 ; clock >= 0 ; clock -- ) {
int V_162 = F_18 ( F_16 ( V_160 [ clock ] ) , V_158 ) ;
if ( F_17 ( V_161 , V_54 ) <= V_162 ) {
V_42 -> V_52 = V_160 [ clock ] ;
V_42 -> V_158 = V_158 ;
V_149 -> clock = F_16 ( V_42 -> V_52 ) ;
F_7 ( L_20
L_21 ,
V_42 -> V_52 , V_42 -> V_158 ,
V_149 -> clock ) ;
return true ;
}
}
}
if ( F_13 ( V_57 ) ) {
V_42 -> V_158 = V_44 ;
V_42 -> V_52 = V_160 [ V_159 ] ;
V_149 -> clock = F_16 ( V_42 -> V_52 ) ;
F_7 ( L_22
L_21 ,
V_42 -> V_52 , V_42 -> V_158 ,
V_149 -> clock ) ;
return true ;
}
return false ;
}
static void
F_48 ( T_5 * V_22 , T_5 * V_163 )
{
T_7 V_164 , V_23 ;
V_23 = * V_22 ;
V_164 = V_23 * ( 0x800000 ) ;
V_23 = F_49 ( V_164 , * V_163 ) ;
* V_22 = V_164 ;
* V_163 = 0x800000 ;
}
static void
F_50 ( int V_54 ,
int V_165 ,
int V_53 ,
int V_166 ,
struct V_167 * V_168 )
{
V_168 -> V_169 = 64 ;
V_168 -> V_170 = ( V_53 * V_54 + 7 ) >> 3 ;
V_168 -> V_171 = V_166 * V_165 ;
F_48 ( & V_168 -> V_170 , & V_168 -> V_171 ) ;
V_168 -> V_172 = V_53 ;
V_168 -> V_173 = V_166 ;
F_48 ( & V_168 -> V_172 , & V_168 -> V_173 ) ;
}
void
F_51 ( struct V_174 * V_175 , struct V_79 * V_3 ,
struct V_79 * V_149 )
{
struct V_58 * V_59 = V_175 -> V_59 ;
struct V_80 * V_43 = V_59 -> V_81 ;
struct V_176 * V_177 = & V_59 -> V_177 ;
struct V_157 * V_39 ;
struct V_178 * V_178 = F_52 ( V_175 ) ;
int V_158 = 4 , V_54 = 24 ;
struct V_167 V_168 ;
int V_179 = V_178 -> V_179 ;
F_53 (encoder, &mode_config->encoder_list, head) {
struct V_38 * V_57 ;
struct V_41 * V_42 ;
if ( V_39 -> V_175 != V_175 )
continue;
V_57 = F_47 ( V_39 ) ;
V_42 = V_57 -> V_43 ;
if ( V_57 -> type == V_180 ) {
V_158 = V_42 -> V_158 ;
break;
} else if ( F_13 ( V_57 ) ) {
V_158 = V_42 -> V_158 ;
V_54 = V_43 -> V_86 . V_54 ;
break;
}
}
F_50 ( V_54 , V_158 ,
V_3 -> clock , V_149 -> clock , & V_168 ) ;
{
F_21 ( F_54 ( V_179 ) ,
( ( V_168 . V_169 - 1 ) << V_181 ) |
V_168 . V_170 ) ;
F_21 ( F_55 ( V_179 ) , V_168 . V_171 ) ;
F_21 ( F_56 ( V_179 ) , V_168 . V_172 ) ;
F_21 ( F_57 ( V_179 ) , V_168 . V_173 ) ;
}
}
static void
F_58 ( struct V_157 * V_39 , struct V_79 * V_3 ,
struct V_79 * V_149 )
{
struct V_38 * V_57 = F_47 ( V_39 ) ;
struct V_174 * V_175 = V_39 -> V_175 ;
struct V_178 * V_178 = F_52 ( V_175 ) ;
struct V_41 * V_42 = V_57 -> V_43 ;
struct V_58 * V_59 = V_39 -> V_59 ;
V_42 -> V_182 = V_183 | V_184 ;
V_42 -> V_182 |= V_42 -> V_185 ;
if ( V_149 -> V_27 & V_186 )
V_42 -> V_182 |= V_187 ;
if ( V_149 -> V_27 & V_188 )
V_42 -> V_182 |= V_189 ;
V_42 -> V_182 |= V_190 ;
switch ( V_42 -> V_158 ) {
case 1 :
V_42 -> V_182 |= V_191 ;
break;
case 2 :
V_42 -> V_182 |= V_192 ;
break;
case 4 :
V_42 -> V_182 |= V_193 ;
break;
}
if ( V_42 -> V_194 )
V_42 -> V_182 |= V_195 ;
memset ( V_42 -> V_196 , 0 , V_197 ) ;
V_42 -> V_196 [ 0 ] = V_42 -> V_52 ;
V_42 -> V_196 [ 1 ] = V_42 -> V_158 ;
if ( V_42 -> V_45 [ V_46 ] >= 0x11 &&
( V_42 -> V_45 [ V_47 ] & V_198 ) ) {
V_42 -> V_196 [ 1 ] |= V_199 ;
V_42 -> V_182 |= V_200 ;
}
if ( V_178 -> V_179 == 1 )
V_42 -> V_182 |= V_201 ;
F_21 ( V_42 -> V_100 , ( V_42 -> V_182 | V_202 ) ) ;
F_7 ( L_23 , V_42 -> V_182 ) ;
if ( F_13 ( V_57 ) ) {
T_5 V_203 ;
F_24 ( V_57 ) ;
if ( V_3 -> V_83 != V_149 -> V_83 ||
V_3 -> V_85 != V_149 -> V_85 )
V_203 = V_204 ;
else
V_203 = 0 ;
V_203 |= V_178 -> V_179 << V_205 ;
F_21 ( V_206 , V_203 ) ;
}
}
static void F_59 ( struct V_38 * V_39 , int V_3 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
int V_8 , V_92 ;
if ( V_42 -> V_45 [ V_46 ] < 0x11 )
return;
if ( V_3 != V_207 ) {
V_8 = F_39 ( V_39 , V_208 ,
V_209 ) ;
if ( V_8 != 1 )
F_60 ( L_24 ) ;
} else {
for ( V_92 = 0 ; V_92 < 3 ; V_92 ++ ) {
V_8 = F_39 ( V_39 ,
V_208 ,
V_210 ) ;
if ( V_8 == 1 )
break;
F_37 ( 1000 ) ;
}
}
}
static void F_61 ( struct V_157 * V_39 )
{
struct V_38 * V_57 = F_47 ( V_39 ) ;
int V_86 = F_13 ( V_57 ) ;
if ( V_86 ) {
F_29 ( V_57 ) ;
F_26 ( V_57 ) ;
F_19 ( V_57 ) ;
}
F_59 ( V_57 , V_207 ) ;
F_62 ( V_57 ) ;
if ( V_86 )
F_23 ( V_57 ) ;
}
static void F_63 ( struct V_157 * V_39 )
{
struct V_38 * V_57 = F_47 ( V_39 ) ;
int V_86 = F_13 ( V_57 ) ;
if ( V_86 )
F_24 ( V_57 ) ;
F_64 ( V_57 ) ;
F_65 ( V_57 ) ;
if ( V_86 )
F_27 ( V_57 ) ;
}
static void
F_66 ( struct V_157 * V_39 , int V_3 )
{
struct V_38 * V_57 = F_47 ( V_39 ) ;
struct V_41 * V_42 = V_57 -> V_43 ;
struct V_58 * V_59 = V_39 -> V_59 ;
T_5 V_211 = F_20 ( V_42 -> V_100 ) ;
int V_86 = F_13 ( V_57 ) ;
if ( V_3 != V_207 ) {
if ( V_86 ) {
F_29 ( V_57 ) ;
F_19 ( V_57 ) ;
}
F_59 ( V_57 , V_3 ) ;
F_62 ( V_57 ) ;
if ( V_86 ) {
F_23 ( V_57 ) ;
F_26 ( V_57 ) ;
}
} else {
if ( V_86 )
F_24 ( V_57 ) ;
F_59 ( V_57 , V_3 ) ;
if ( ! ( V_211 & V_202 ) ) {
F_64 ( V_57 ) ;
F_65 ( V_57 ) ;
}
if ( V_86 )
F_27 ( V_57 ) ;
}
}
static bool
F_67 ( struct V_38 * V_39 , T_6 V_10 ,
T_1 * V_98 , int V_103 )
{
int V_8 , V_92 ;
for ( V_92 = 0 ; V_92 < 3 ; V_92 ++ ) {
V_8 = F_40 ( V_39 , V_10 , V_98 ,
V_103 ) ;
if ( V_8 == V_103 )
return true ;
F_37 ( 1000 ) ;
}
return false ;
}
static bool
F_68 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
return F_67 ( V_39 ,
V_212 ,
V_42 -> V_213 ,
V_214 ) ;
}
static T_1
F_69 ( T_1 V_213 [ V_214 ] ,
int V_215 )
{
return V_213 [ V_215 - V_212 ] ;
}
static T_1
F_70 ( T_1 V_213 [ V_214 ] ,
int V_216 )
{
int V_92 = V_217 + ( V_216 >> 1 ) ;
int V_218 = ( ( V_216 & 1 ) ?
V_219 :
V_220 ) ;
T_1 V_221 = F_69 ( V_213 , V_92 ) ;
return ( ( V_221 >> V_218 ) & 3 ) << V_222 ;
}
static T_1
F_71 ( T_1 V_213 [ V_214 ] ,
int V_216 )
{
int V_92 = V_217 + ( V_216 >> 1 ) ;
int V_218 = ( ( V_216 & 1 ) ?
V_223 :
V_224 ) ;
T_1 V_221 = F_69 ( V_213 , V_92 ) ;
return ( ( V_221 >> V_218 ) & 3 ) << V_225 ;
}
static void
F_72 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_93 = 0 ;
T_1 V_226 = 0 ;
int V_216 ;
for ( V_216 = 0 ; V_216 < V_42 -> V_158 ; V_216 ++ ) {
T_1 V_227 = F_70 ( V_42 -> V_213 , V_216 ) ;
T_1 V_228 = F_71 ( V_42 -> V_213 , V_216 ) ;
if ( V_227 > V_93 )
V_93 = V_227 ;
if ( V_228 > V_226 )
V_226 = V_228 ;
}
if ( V_93 >= V_229 )
V_93 = V_229 | V_230 ;
if ( V_226 == V_231 )
V_226 |= V_232 ;
for ( V_216 = 0 ; V_216 < 4 ; V_216 ++ )
V_42 -> V_233 [ V_216 ] = V_93 | V_226 ;
}
static T_1
F_73 ( T_1 V_213 [ V_214 ] ,
int V_216 )
{
int V_92 = V_212 + ( V_216 >> 1 ) ;
int V_218 = ( V_216 & 1 ) * 4 ;
T_1 V_221 = F_69 ( V_213 , V_92 ) ;
return ( V_221 >> V_218 ) & 0xf ;
}
static bool
F_74 ( T_1 V_213 [ V_214 ] , int V_158 )
{
int V_216 ;
T_1 V_234 ;
for ( V_216 = 0 ; V_216 < V_158 ; V_216 ++ ) {
V_234 = F_73 ( V_213 , V_216 ) ;
if ( ( V_234 & V_235 ) == 0 )
return false ;
}
return true ;
}
static bool
F_75 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_236 ;
T_1 V_234 ;
int V_216 ;
V_236 = F_69 ( V_42 -> V_213 ,
V_237 ) ;
if ( ( V_236 & V_238 ) == 0 )
return false ;
for ( V_216 = 0 ; V_216 < V_42 -> V_158 ; V_216 ++ ) {
V_234 = F_73 ( V_42 -> V_213 , V_216 ) ;
if ( ( V_234 & V_239 ) != V_239 )
return false ;
}
return true ;
}
static bool
F_76 ( struct V_38 * V_39 ,
T_5 V_240 ,
T_1 V_241 )
{
struct V_58 * V_59 = V_39 -> V_60 . V_59 ;
int V_8 ;
struct V_41 * V_42 = V_39 -> V_43 ;
F_21 ( V_42 -> V_100 , V_240 ) ;
F_20 ( V_42 -> V_100 ) ;
V_8 = F_39 ( V_39 ,
V_242 ,
V_241 ) ;
if ( V_8 != 1 ) {
F_7 ( L_25 ,
V_241 ) ;
return false ;
}
return true ;
}
static bool
F_77 ( struct V_38 * V_39 ,
T_1 V_241 )
{
int V_8 ;
struct V_41 * V_42 = V_39 -> V_43 ;
V_8 = F_38 ( V_39 ,
V_243 ,
V_42 -> V_233 ,
V_42 -> V_158 ) ;
if ( V_8 != V_42 -> V_158 ) {
F_7 ( L_26 ,
V_42 -> V_233 [ 0 ] , V_42 -> V_158 ) ;
return false ;
}
return true ;
}
static void
F_78 ( struct V_38 * V_39 , T_1 V_244 )
{
struct V_58 * V_59 = V_39 -> V_60 . V_59 ;
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_245 * V_246 ;
int V_247 , V_248 , V_249 ;
if ( V_42 -> V_100 == V_250 )
V_246 = & V_251 [ 0 ] ;
else
V_246 = & V_251 [ 1 ] ;
V_247 = ( V_244 & V_252 ) ;
V_248 = ( ( V_244 & V_231 ) ) >>
V_225 ;
if ( V_247 + V_248 > 3 )
return;
#ifdef F_79
return;
#endif
F_7 ( L_27 ) ;
F_80 ( V_59 ) ;
F_81 ( V_59 , V_246 -> V_253 , 0x0505313A ) ;
F_81 ( V_59 , V_246 -> V_254 , 0x43406055 ) ;
V_249 = ( V_247 + V_248 ) * 2 ;
if ( V_248 == 1 && V_247 == 1 ) {
F_81 ( V_59 , V_246 -> V_255 , 0x055738954 ) ;
} else
F_81 ( V_59 , V_246 -> V_255 , V_256 [ V_249 ] ) ;
if ( ( V_247 + V_248 ) == V_257 )
F_81 ( V_59 , V_246 -> V_258 , 0x70802040 ) ;
else
F_81 ( V_59 , V_246 -> V_258 , 0x40802040 ) ;
F_81 ( V_59 , V_246 -> V_254 , 0xc3406055 ) ;
F_81 ( V_59 , V_246 -> V_259 , 0x1f030040 ) ;
V_249 = 2 * V_248 + 1 ;
F_81 ( V_59 , V_246 -> V_260 , V_256 [ V_249 ] ) ;
return;
}
static void
F_64 ( struct V_38 * V_39 )
{
struct V_58 * V_59 = V_39 -> V_60 . V_59 ;
struct V_41 * V_42 = V_39 -> V_43 ;
int V_92 ;
T_1 V_261 ;
bool V_262 = false ;
int V_263 ;
T_4 V_264 ;
T_5 V_182 = V_42 -> V_182 ;
V_182 |= V_202 ;
V_182 &= ~ V_265 ;
V_264 = V_182 ;
V_264 |= V_266 ;
F_21 ( V_42 -> V_100 , V_264 ) ;
F_20 ( V_42 -> V_100 ) ;
F_82 ( V_59 ) ;
F_7 ( L_28 ) ;
F_38 ( V_39 , V_267 ,
V_42 -> V_196 ,
2 ) ;
memset ( V_42 -> V_233 , 0 , 4 ) ;
V_261 = 0 ;
V_263 = 0 ;
V_262 = false ;
F_7 ( L_29 ) ;
V_264 = V_182 | V_266 ;
for (; ; ) {
F_7 ( L_30 ,
V_42 -> V_233 [ 0 ] ,
V_42 -> V_196 [ 0 ] ,
V_42 -> V_196 [ 1 ] ) ;
if ( ! F_76 ( V_39 , V_264 , V_268 ) ) {
F_7 ( L_31 ) ;
}
F_78 ( V_39 , V_42 -> V_233 [ 0 ] ) ;
F_77 ( V_39 , V_268 ) ;
F_37 ( 200 ) ;
if ( ! F_68 ( V_39 ) )
break;
F_7 ( L_32 ,
V_42 -> V_213 [ 0 ] , V_42 -> V_213 [ 1 ] , V_42 -> V_213 [ 2 ] ,
V_42 -> V_213 [ 3 ] , V_42 -> V_213 [ 4 ] , V_42 -> V_213 [ 5 ] ) ;
if ( F_74 ( V_42 -> V_213 , V_42 -> V_158 ) ) {
F_7 ( L_33 ) ;
V_262 = true ;
break;
}
for ( V_92 = 0 ; V_92 < V_42 -> V_158 ; V_92 ++ )
if ( ( V_42 -> V_233 [ V_92 ] & V_230 ) == 0 )
break;
if ( V_92 == V_42 -> V_158 )
break;
if ( ( V_42 -> V_233 [ 0 ] & V_252 ) == V_261 ) {
++ V_263 ;
if ( V_263 == 5 )
break;
} else
V_263 = 0 ;
V_261 = V_42 -> V_233 [ 0 ] & V_252 ;
F_72 ( V_39 ) ;
}
if ( ! V_262 ) {
F_7 ( L_34 , V_42 -> V_233 [ 0 ] ) ;
}
V_42 -> V_182 = V_182 ;
}
static void
F_65 ( struct V_38 * V_39 )
{
struct V_58 * V_59 = V_39 -> V_60 . V_59 ;
struct V_41 * V_42 = V_39 -> V_43 ;
bool V_269 = false ;
int V_263 , V_270 ;
T_4 V_264 ;
T_5 V_182 = V_42 -> V_182 ;
V_263 = 0 ;
V_270 = 0 ;
V_269 = false ;
F_7 ( L_3 ) ;
V_264 = V_182 | V_271 ;
for (; ; ) {
F_7 ( L_30 ,
V_42 -> V_233 [ 0 ] ,
V_42 -> V_196 [ 0 ] ,
V_42 -> V_196 [ 1 ] ) ;
if ( ! F_76 ( V_39 , V_264 ,
V_272 ) ) {
F_7 ( L_35 ) ;
}
if ( V_270 > 5 ) {
F_36 ( L_36 ) ;
F_62 ( V_39 ) ;
break;
}
F_78 ( V_39 , V_42 -> V_233 [ 0 ] ) ;
F_77 ( V_39 , V_272 ) ;
F_37 ( 1000 ) ;
if ( ! F_68 ( V_39 ) )
break;
F_7 ( L_32 ,
V_42 -> V_213 [ 0 ] , V_42 -> V_213 [ 1 ] , V_42 -> V_213 [ 2 ] ,
V_42 -> V_213 [ 3 ] , V_42 -> V_213 [ 4 ] , V_42 -> V_213 [ 5 ] ) ;
if ( ! F_74 ( V_42 -> V_213 , V_42 -> V_158 ) ) {
F_64 ( V_39 ) ;
V_270 ++ ;
continue;
}
if ( F_75 ( V_39 ) ) {
F_7 ( L_37 ) ;
V_269 = true ;
break;
}
if ( V_263 > 5 ) {
F_62 ( V_39 ) ;
F_64 ( V_39 ) ;
V_263 = 0 ;
V_270 ++ ;
continue;
}
F_72 ( V_39 ) ;
++ V_263 ;
}
V_264 = V_182 | V_190 ;
F_21 ( V_42 -> V_100 , V_264 ) ;
F_20 ( V_42 -> V_100 ) ;
F_39 ( V_39 ,
V_242 , V_273 ) ;
}
static void
F_62 ( struct V_38 * V_39 )
{
struct V_58 * V_59 = V_39 -> V_60 . V_59 ;
struct V_41 * V_42 = V_39 -> V_43 ;
T_5 V_182 = V_42 -> V_182 ;
if ( ( F_20 ( V_42 -> V_100 ) & V_202 ) == 0 )
return;
F_7 ( L_3 ) ;
{
V_182 &= ~ V_265 ;
F_21 ( V_42 -> V_100 , V_182 | V_274 ) ;
}
F_20 ( V_42 -> V_100 ) ;
F_22 ( 17 ) ;
F_21 ( V_42 -> V_100 , V_182 & ~ V_202 ) ;
F_20 ( V_42 -> V_100 ) ;
}
static enum V_275 F_83 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
enum V_275 V_104 ;
V_104 = V_276 ;
if ( F_40 ( V_39 , 0x000 , V_42 -> V_45 ,
sizeof ( V_42 -> V_45 ) ) == sizeof ( V_42 -> V_45 ) )
{
if ( V_42 -> V_45 [ V_46 ] != 0 )
V_104 = V_277 ;
}
if ( V_104 == V_277 )
F_7 ( L_38 ,
V_42 -> V_45 [ 0 ] , V_42 -> V_45 [ 1 ] ,
V_42 -> V_45 [ 2 ] , V_42 -> V_45 [ 3 ] ) ;
return V_104 ;
}
static enum V_275
F_84 ( struct V_77 * V_78 , bool V_278 )
{
struct V_38 * V_39 = F_32 ( V_78 ) ;
struct V_41 * V_42 = V_39 -> V_43 ;
enum V_275 V_104 ;
struct V_279 * V_279 = NULL ;
int V_86 = F_13 ( V_39 ) ;
V_42 -> V_194 = false ;
if ( V_86 )
F_19 ( V_39 ) ;
V_104 = F_83 ( V_39 ) ;
if ( V_104 != V_277 ) {
if ( V_86 )
F_23 ( V_39 ) ;
return V_104 ;
}
if ( V_42 -> V_280 ) {
V_42 -> V_194 = V_42 -> V_280 > 0 ;
} else {
V_279 = F_85 ( V_78 , & V_42 -> V_2 ) ;
if ( V_279 ) {
V_42 -> V_194 = F_86 ( V_279 ) ;
F_87 ( V_279 ) ;
}
}
if ( V_86 )
F_23 ( V_39 ) ;
return V_277 ;
}
static int F_88 ( struct V_77 * V_78 )
{
struct V_38 * V_57 = F_32 ( V_78 ) ;
struct V_41 * V_42 = V_57 -> V_43 ;
struct V_279 * V_279 = NULL ;
int V_8 = 0 ;
int V_86 = F_13 ( V_57 ) ;
V_279 = F_85 ( V_78 , & V_42 -> V_2 ) ;
if ( V_279 ) {
F_89 ( V_78 , V_279 ) ;
V_8 = F_90 ( V_78 , V_279 ) ;
F_87 ( V_279 ) ;
}
if ( F_13 ( V_57 ) ) {
struct V_58 * V_59 = V_78 -> V_59 ;
struct V_80 * V_43 = V_59 -> V_81 ;
F_23 ( V_57 ) ;
if ( V_8 ) {
if ( V_86 && ! V_42 -> V_82 ) {
struct V_79 * V_281 ;
F_53 (newmode, &connector->probed_modes,
head) {
if ( V_281 -> type & V_282 ) {
V_42 -> V_82 =
F_91 ( V_59 , V_281 ) ;
break;
}
}
}
return V_8 ;
}
if ( ! V_42 -> V_82 && V_43 -> V_283 ) {
V_42 -> V_82 =
F_91 ( V_59 , V_43 -> V_283 ) ;
if ( V_42 -> V_82 ) {
V_42 -> V_82 -> type |=
V_282 ;
}
}
if ( V_42 -> V_82 != NULL ) {
struct V_79 * V_3 ;
V_3 = F_91 ( V_59 , V_42 -> V_82 ) ;
F_92 ( V_78 , V_3 ) ;
return 1 ;
}
}
return V_8 ;
}
static bool
F_93 ( struct V_77 * V_78 )
{
struct V_38 * V_39 = F_32 ( V_78 ) ;
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_279 * V_279 ;
bool V_194 = false ;
int V_86 = F_13 ( V_39 ) ;
if ( V_86 )
F_19 ( V_39 ) ;
V_279 = F_85 ( V_78 , & V_42 -> V_2 ) ;
if ( V_279 ) {
V_194 = F_86 ( V_279 ) ;
F_87 ( V_279 ) ;
}
if ( V_86 )
F_23 ( V_39 ) ;
return V_194 ;
}
static int
F_94 ( struct V_77 * V_78 ,
struct V_284 * V_285 ,
T_7 V_286 )
{
struct V_80 * V_43 = V_78 -> V_59 -> V_81 ;
struct V_38 * V_39 = F_32 ( V_78 ) ;
struct V_41 * V_42 = V_39 -> V_43 ;
int V_8 ;
V_8 = F_95 ( & V_78 -> V_60 , V_285 , V_286 ) ;
if ( V_8 )
return V_8 ;
if ( V_285 == V_43 -> V_287 ) {
int V_92 = V_286 ;
bool V_194 ;
if ( V_92 == V_42 -> V_280 )
return 0 ;
V_42 -> V_280 = V_92 ;
if ( V_92 == 0 )
V_194 = F_93 ( V_78 ) ;
else
V_194 = V_92 > 0 ;
if ( V_194 == V_42 -> V_194 )
return 0 ;
V_42 -> V_194 = V_194 ;
goto V_288;
}
if ( V_285 == V_43 -> V_289 ) {
if ( V_286 == ! ! V_42 -> V_185 )
return 0 ;
V_42 -> V_185 = V_286 ? V_290 : 0 ;
goto V_288;
}
return - V_291 ;
V_288:
if ( V_39 -> V_60 . V_175 ) {
struct V_174 * V_175 = V_39 -> V_60 . V_175 ;
F_96 ( V_175 , & V_175 -> V_3 ,
V_175 -> V_292 , V_175 -> V_293 ,
V_175 -> V_294 -> V_295 ) ;
}
return 0 ;
}
static void
F_97 ( struct V_77 * V_78 )
{
struct V_38 * V_38 = F_32 ( V_78 ) ;
struct V_41 * V_42 = V_38 -> V_43 ;
if ( F_13 ( V_38 ) ) {
if ( V_42 -> V_82 ) {
F_87 ( V_42 -> V_82 ) ;
V_42 -> V_82 = NULL ;
}
}
F_98 ( & V_42 -> V_2 ) ;
F_99 ( V_78 ) ;
F_100 ( V_78 ) ;
F_87 ( V_78 ) ;
}
static void F_101 ( struct V_157 * V_39 )
{
F_102 ( V_39 ) ;
}
static void F_103 ( struct V_77 * V_78 )
{
F_104 ( V_78 ) ;
F_105 ( V_78 ) ;
}
static bool F_106 ( struct V_58 * V_59 )
{
struct V_80 * V_43 = V_59 -> V_81 ;
struct V_296 * V_297 ;
int V_92 ;
if ( ! V_43 -> V_298 )
return false ;
for ( V_92 = 0 ; V_92 < V_43 -> V_298 ; V_92 ++ ) {
V_297 = V_43 -> V_299 + V_92 ;
if ( V_297 -> V_300 == V_301 &&
V_297 -> V_302 == V_303 )
return true ;
}
return false ;
}
static void F_107 ( struct V_58 * V_59 )
{
T_4 V_304 ;
V_304 = F_20 ( V_305 ) ;
V_304 |= ( V_306 |
V_307 |
V_308 |
V_309 |
V_310 |
V_311 ) ;
F_21 ( V_305 , V_304 ) ;
F_37 ( 500 ) ;
}
void
F_108 ( struct V_58 * V_59 , struct V_312 * V_313 , int V_100 )
{
struct V_38 * V_38 ;
struct V_140 * V_140 ;
struct V_77 * V_78 ;
struct V_157 * V_39 ;
struct V_41 * V_42 ;
const char * V_141 = NULL ;
int type = V_314 ;
V_38 = F_109 ( sizeof( struct V_38 ) , V_315 ) ;
if ( ! V_38 )
return;
V_140 = F_109 ( sizeof( struct V_140 ) , V_315 ) ;
if ( ! V_140 )
goto V_316;
V_42 = F_109 ( sizeof( struct V_41 ) , V_315 ) ;
if ( ! V_42 )
goto V_317;
if ( ( V_100 == V_318 ) && F_106 ( V_59 ) )
type = V_319 ;
V_78 = & V_140 -> V_60 ;
V_39 = & V_38 -> V_60 ;
F_110 ( V_59 , V_78 , & V_320 , type ) ;
F_111 ( V_59 , V_39 , & V_321 ,
V_322 , NULL ) ;
F_112 ( V_140 , V_38 ) ;
if ( type == V_314 )
V_38 -> type = V_180 ;
else
V_38 -> type = V_40 ;
V_38 -> V_43 = V_42 ;
V_42 -> V_39 = V_38 ;
V_42 -> V_100 = V_100 ;
F_113 ( V_39 , & V_323 ) ;
F_114 ( V_78 , & V_324 ) ;
V_78 -> V_325 = V_326 ;
V_78 -> V_327 = false ;
V_78 -> V_328 = false ;
F_115 ( V_78 ) ;
switch ( V_100 ) {
case V_250 :
V_141 = L_39 ;
V_38 -> V_329 = ( V_330 | V_331 ) ;
break;
case V_318 :
V_141 = L_40 ;
V_38 -> V_329 = ( V_330 | V_332 ) ;
break;
}
F_107 ( V_59 ) ;
F_43 ( V_140 , V_38 , V_141 ) ;
F_103 ( V_78 ) ;
if ( F_13 ( V_38 ) ) {
int V_8 ;
struct V_333 V_334 ;
T_4 V_335 , V_336 , V_337 ;
T_4 V_338 ;
V_335 = F_20 ( V_63 ) ;
V_335 &= ~ V_69 ;
V_335 |= V_70 ;
F_21 ( V_63 , V_335 ) ;
V_338 = F_20 ( V_339 ) ;
V_338 |= V_340 ;
F_21 ( V_339 , V_338 ) ;
V_335 = F_20 ( V_341 ) ;
V_336 = F_20 ( V_342 ) ;
V_337 = F_20 ( V_343 ) ;
V_334 . V_344 = ( V_335 & V_345 ) >>
V_346 ;
V_334 . V_347 = ( V_335 & V_348 ) >>
V_349 ;
V_334 . V_350 = ( V_336 & V_351 ) >>
V_352 ;
V_334 . V_353 = ( V_336 & V_354 ) >>
V_355 ;
V_334 . V_356 = ( ( V_337 & V_357 ) >>
V_358 ) ;
F_7 ( L_41 ,
V_334 . V_344 , V_334 . V_347 , V_334 . V_350 , V_334 . V_353 , V_334 . V_356 ) ;
V_42 -> V_65 = V_334 . V_344 / 10 ;
V_42 -> V_359 = V_334 . V_347 / 10 ;
V_42 -> V_76 = V_334 . V_350 / 10 ;
V_42 -> V_360 = V_334 . V_353 / 10 ;
V_42 -> V_75 = ( V_334 . V_356 - 1 ) * 100 ;
F_7 ( L_42 ,
V_42 -> V_65 , V_42 -> V_360 ,
V_42 -> V_75 ) ;
F_7 ( L_43 ,
V_42 -> V_359 , V_42 -> V_76 ) ;
F_19 ( V_38 ) ;
V_8 = F_40 ( V_38 , V_46 ,
V_42 -> V_45 ,
sizeof( V_42 -> V_45 ) ) ;
F_23 ( V_38 ) ;
if ( V_8 == 0 ) {
F_116 ( L_44 ) ;
F_101 ( V_39 ) ;
F_97 ( V_78 ) ;
goto V_317;
} else {
F_7 ( L_38 ,
V_42 -> V_45 [ 0 ] , V_42 -> V_45 [ 1 ] ,
V_42 -> V_45 [ 2 ] , V_42 -> V_45 [ 3 ] ) ;
}
}
return;
V_317:
F_87 ( V_140 ) ;
V_316:
F_87 ( V_38 ) ;
}
