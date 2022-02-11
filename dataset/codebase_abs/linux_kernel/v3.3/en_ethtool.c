static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_11 , V_12 L_1 V_13 L_2 ,
sizeof( V_4 -> V_11 ) ) ;
snprintf ( V_4 -> V_14 , sizeof( V_4 -> V_14 ) ,
L_3 ,
( V_15 ) ( V_8 -> V_2 -> V_16 . V_17 >> 32 ) ,
( V_15 ) ( ( V_8 -> V_2 -> V_16 . V_17 >> 16 ) & 0xffff ) ,
( V_15 ) ( V_8 -> V_2 -> V_16 . V_17 & 0xffff ) ) ;
F_3 ( V_4 -> V_18 , F_4 ( V_8 -> V_2 -> V_19 ) ,
sizeof( V_4 -> V_18 ) ) ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
return ( (struct V_5 * ) F_2 ( V_2 ) ) -> V_23 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_24 )
{
( (struct V_5 * ) F_2 ( V_2 ) ) -> V_23 = V_24 ;
}
static void F_7 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
int V_28 = 0 ;
T_2 V_29 = 0 ;
T_2 V_30 ;
if ( ( V_6 -> V_31 < 1 ) || ( V_6 -> V_31 > 2 ) ) {
F_8 ( V_6 , L_4 ) ;
return;
}
V_30 = ( V_6 -> V_31 == 1 ) ? V_32 :
V_33 ;
if ( ! ( V_6 -> V_8 -> V_2 -> V_16 . V_34 & V_30 ) ) {
V_27 -> V_35 = 0 ;
V_27 -> V_36 = 0 ;
return;
}
V_28 = F_9 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_31 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_4 ) ;
return;
}
if ( V_29 & V_37 )
V_27 -> V_35 = V_38 ;
else
V_27 -> V_35 = 0 ;
if ( V_29 & V_39 )
V_27 -> V_36 = V_38 ;
else
V_27 -> V_36 = 0 ;
}
static int F_10 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
T_2 V_29 = 0 ;
int V_28 = 0 ;
T_2 V_30 ;
if ( ( V_6 -> V_31 < 1 ) || ( V_6 -> V_31 > 2 ) )
return - V_40 ;
V_30 = ( V_6 -> V_31 == 1 ) ? V_32 :
V_33 ;
if ( ! ( V_6 -> V_8 -> V_2 -> V_16 . V_34 & V_30 ) )
return - V_40 ;
if ( V_27 -> V_35 & ~ V_38 )
return - V_41 ;
V_28 = F_9 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_31 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_5 ) ;
return V_28 ;
}
if ( V_27 -> V_36 & V_38 ) {
V_29 |= V_42 | V_39 |
V_37 ;
} else {
V_29 &= ~ ( V_39 | V_37 ) ;
V_29 |= V_42 ;
}
V_28 = F_11 ( V_6 -> V_8 -> V_2 , V_29 , V_6 -> V_31 ) ;
if ( V_28 )
F_8 ( V_6 , L_6 ) ;
return V_28 ;
}
static int F_12 ( struct V_1 * V_2 , int V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_44 = F_13 ( V_6 -> V_45 ) ;
switch ( V_43 ) {
case V_46 :
return ( V_6 -> V_45 ? V_44 : V_47 ) +
( V_6 -> V_48 + V_6 -> V_49 ) * 2 ;
case V_50 :
return V_51 - ! ( V_6 -> V_8 -> V_2 -> V_16 . V_34
& V_52 ) * 2 ;
default:
return - V_40 ;
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_53 * V_54 , T_3 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_56 = 0 ;
int V_57 , V_58 = 0 ;
F_15 ( & V_6 -> V_59 ) ;
if ( ! ( V_6 -> V_45 ) ) {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_54 ) [ V_57 ] ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_62 ) [ V_57 ] ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_64 ) [ V_57 ] ;
} else {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( ( V_6 -> V_45 >> V_58 ) & 1 )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_54 ) [ V_57 ] ;
V_58 ++ ;
}
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ ) {
if ( ( V_6 -> V_45 >> V_58 ) & 1 )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_62 ) [ V_57 ] ;
V_58 ++ ;
}
}
for ( V_57 = 0 ; V_57 < V_6 -> V_48 ; V_57 ++ ) {
V_55 [ V_56 ++ ] = V_6 -> V_65 [ V_57 ] . V_66 ;
V_55 [ V_56 ++ ] = V_6 -> V_65 [ V_57 ] . V_67 ;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
V_55 [ V_56 ++ ] = V_6 -> V_68 [ V_57 ] . V_66 ;
V_55 [ V_56 ++ ] = V_6 -> V_68 [ V_57 ] . V_67 ;
}
F_16 ( & V_6 -> V_59 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_2 * V_71 )
{
F_18 ( V_2 , & V_70 -> V_34 , V_71 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
T_4 V_72 , T_5 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_56 = 0 ;
int V_57 ;
switch ( V_72 ) {
case V_50 :
for ( V_57 = 0 ; V_57 < V_51 - 2 ; V_57 ++ )
strcpy ( V_55 + V_57 * V_73 , V_74 [ V_57 ] ) ;
if ( V_6 -> V_8 -> V_2 -> V_16 . V_34 & V_52 )
for (; V_57 < V_51 ; V_57 ++ )
strcpy ( V_55 + V_57 * V_73 , V_74 [ V_57 ] ) ;
break;
case V_46 :
if ( ! V_6 -> V_45 ) {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
strcpy ( V_55 + ( V_56 ++ ) * V_73 ,
V_75 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ )
strcpy ( V_55 + ( V_56 ++ ) * V_73 ,
V_75 [ V_57 +
V_60 ] ) ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ )
strcpy ( V_55 + ( V_56 ++ ) * V_73 ,
V_75 [ V_57 +
V_60 +
V_61 ] ) ;
} else
for ( V_57 = 0 ; V_57 < V_60 + V_61 ; V_57 ++ ) {
if ( ( V_6 -> V_45 >> V_57 ) & 1 ) {
strcpy ( V_55 +
( V_56 ++ ) * V_73 ,
V_75 [ V_57 ] ) ;
}
if ( ! ( V_6 -> V_45 >> V_57 ) )
break;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_48 ; V_57 ++ ) {
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_7 , V_57 ) ;
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_8 , V_57 ) ;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_9 , V_57 ) ;
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_10 , V_57 ) ;
}
break;
}
}
static int F_20 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_78 ;
V_77 -> V_79 = V_80 ;
V_77 -> V_35 = V_81 ;
V_77 -> V_82 = V_83 ;
if ( F_21 ( V_6 -> V_8 , V_6 -> V_31 ) )
return - V_84 ;
V_78 = V_6 -> V_85 . V_86 ;
if ( F_22 ( V_2 ) ) {
F_23 ( V_77 , V_6 -> V_85 . V_87 ) ;
V_77 -> V_88 = V_89 ;
} else {
F_23 ( V_77 , - 1 ) ;
V_77 -> V_88 = - 1 ;
}
if ( V_78 > 0 && V_78 <= 0xC ) {
V_77 -> V_31 = V_90 ;
V_77 -> V_91 = V_92 ;
V_77 -> V_35 |= V_93 ;
V_77 -> V_82 |= V_94 ;
} else if ( V_78 == 0x80 || V_78 == 0 ) {
V_77 -> V_31 = V_95 ;
V_77 -> V_91 = V_96 ;
V_77 -> V_35 |= V_97 ;
V_77 -> V_82 |= V_98 ;
} else {
V_77 -> V_31 = - 1 ;
V_77 -> V_91 = - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
if ( ( V_77 -> V_79 == V_99 ) ||
( F_25 ( V_77 ) != V_100 ) ||
( V_77 -> V_88 != V_89 ) )
return - V_41 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_102 -> V_103 = 0 ;
V_102 -> V_104 = 0 ;
V_102 -> V_105 = V_6 -> V_106 ;
V_102 -> V_107 = V_6 -> V_108 ;
V_102 -> V_109 = V_6 -> V_109 ;
V_102 -> V_110 = V_6 -> V_111 ;
V_102 -> V_112 = V_6 -> V_112 ;
V_102 -> V_113 = V_6 -> V_114 ;
V_102 -> V_115 = V_6 -> V_116 ;
V_102 -> V_117 = V_6 -> V_118 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 , V_57 ;
V_6 -> V_108 = ( V_102 -> V_107 ==
V_119 ) ?
V_120 :
V_102 -> V_107 ;
V_6 -> V_106 = ( V_102 -> V_105 ==
V_119 ) ?
V_121 :
V_102 -> V_105 ;
V_6 -> V_109 = V_102 -> V_109 ;
V_6 -> V_111 = V_102 -> V_110 ;
V_6 -> V_112 = V_102 -> V_112 ;
V_6 -> V_114 = V_102 -> V_113 ;
V_6 -> V_116 = V_102 -> V_115 ;
V_6 -> V_118 = V_102 -> V_117 ;
if ( V_6 -> V_118 )
return 0 ;
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
V_6 -> V_122 [ V_57 ] . V_123 = V_6 -> V_108 ;
V_6 -> V_122 [ V_57 ] . V_124 = V_6 -> V_106 ;
V_6 -> V_125 [ V_57 ] = V_119 ;
V_28 = F_28 ( V_6 , & V_6 -> V_122 [ V_57 ] ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
V_6 -> V_128 -> V_129 = V_127 -> V_129 != 0 ;
V_6 -> V_128 -> V_130 = V_127 -> V_130 != 0 ;
V_28 = F_30 ( V_8 -> V_2 , V_6 -> V_31 ,
V_6 -> V_131 + V_132 ,
V_6 -> V_128 -> V_129 ,
V_6 -> V_128 -> V_133 ,
V_6 -> V_128 -> V_130 ,
V_6 -> V_128 -> V_134 ) ;
if ( V_28 )
F_8 ( V_6 , L_11 ) ;
return V_28 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_127 -> V_129 = V_6 -> V_128 -> V_129 ;
V_127 -> V_130 = V_6 -> V_128 -> V_130 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_137 , V_138 ;
int V_139 = 0 ;
int V_28 = 0 ;
int V_57 ;
if ( V_136 -> V_140 || V_136 -> V_141 )
return - V_41 ;
V_137 = F_33 ( V_136 -> V_142 ) ;
V_137 = F_34 ( T_1 , V_137 , V_143 ) ;
V_137 = F_35 ( T_1 , V_137 , V_144 ) ;
V_138 = F_33 ( V_136 -> V_145 ) ;
V_138 = F_34 ( T_1 , V_138 , V_146 ) ;
V_138 = F_35 ( T_1 , V_138 , V_147 ) ;
if ( V_137 == ( V_6 -> V_139 ? V_6 -> V_68 [ 0 ] . V_148 :
V_6 -> V_68 [ 0 ] . V_149 ) &&
V_138 == V_6 -> V_65 [ 0 ] . V_149 )
return 0 ;
F_36 ( & V_8 -> V_150 ) ;
if ( V_6 -> V_139 ) {
V_139 = 1 ;
F_37 ( V_2 ) ;
}
F_38 ( V_6 ) ;
V_6 -> V_128 -> V_151 = V_138 ;
V_6 -> V_128 -> V_152 = V_137 ;
V_28 = F_39 ( V_6 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_12 ) ;
goto V_153;
}
if ( V_139 ) {
V_28 = F_40 ( V_2 ) ;
if ( V_28 )
F_8 ( V_6 , L_13 ) ;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
V_6 -> V_122 [ V_57 ] . V_123 = V_6 -> V_108 ;
V_6 -> V_122 [ V_57 ] . V_124 = V_6 -> V_106 ;
V_6 -> V_125 [ V_57 ] = V_119 ;
V_28 = F_28 ( V_6 , & V_6 -> V_122 [ V_57 ] ) ;
if ( V_28 )
goto V_153;
}
V_153:
F_41 ( & V_8 -> V_150 ) ;
return V_28 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
V_136 -> V_154 = V_144 ;
V_136 -> V_155 = V_147 ;
V_136 -> V_142 = V_6 -> V_139 ?
V_6 -> V_68 [ 0 ] . V_148 : V_6 -> V_68 [ 0 ] . V_149 ;
V_136 -> V_145 = V_6 -> V_65 [ 0 ] . V_149 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_49 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 * V_156 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_157 * V_158 = & V_6 -> V_158 ;
int V_159 ;
T_6 V_160 = V_6 -> V_49 ;
int V_28 = 0 ;
V_159 = V_6 -> V_128 -> V_159 ? : V_6 -> V_49 ;
while ( V_160 -- ) {
V_156 [ V_160 ] = V_158 -> V_161 [ V_160 % V_159 ] . V_162 -
V_158 -> V_163 ;
}
return V_28 ;
}
static int F_45 ( struct V_1 * V_2 ,
const T_1 * V_156 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_139 = 0 ;
int V_28 = 0 ;
int V_57 ;
int V_159 = 0 ;
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
if ( V_57 > 0 && ! V_156 [ V_57 ] && ! V_159 )
V_159 = V_57 ;
if ( V_156 [ V_57 ] != ( V_57 % ( V_159 ? : V_6 -> V_49 ) ) )
return - V_41 ;
}
if ( ! V_159 )
V_159 = V_6 -> V_49 ;
if ( ! F_46 ( V_159 ) )
return - V_41 ;
F_36 ( & V_8 -> V_150 ) ;
if ( V_6 -> V_139 ) {
V_139 = 1 ;
F_37 ( V_2 ) ;
}
V_6 -> V_128 -> V_159 = V_159 ;
if ( V_139 ) {
V_28 = F_40 ( V_2 ) ;
if ( V_28 )
F_8 ( V_6 , L_13 ) ;
}
F_41 ( & V_8 -> V_150 ) ;
return V_28 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_164 * V_77 ,
T_1 * V_165 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 = 0 ;
switch ( V_77 -> V_77 ) {
case V_166 :
V_77 -> V_55 = V_6 -> V_49 ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
