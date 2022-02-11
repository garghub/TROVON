static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
default: return L_3 ;
}
}
static void * F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 -> V_8 ;
while ( V_9 ) {
struct V_10 * V_11 = F_3 ( V_9 , struct V_10 ,
V_9 ) ;
if ( V_7 < V_11 -> V_7 )
V_9 = V_9 -> V_12 ;
else if ( V_7 > V_11 -> V_7 )
V_9 = V_9 -> V_13 ;
else
return V_11 ;
}
return NULL ;
}
static int F_4 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_8 * * V_14 = & ( V_6 -> V_8 ) , * V_15 = NULL ;
while ( * V_14 ) {
struct V_10 * V_16 = F_3 ( * V_14 , struct V_10 ,
V_9 ) ;
V_15 = * V_14 ;
if ( V_11 -> V_7 < V_16 -> V_7 )
V_14 = & ( ( * V_14 ) -> V_12 ) ;
else if ( V_11 -> V_7 > V_16 -> V_7 )
V_14 = & ( ( * V_14 ) -> V_13 ) ;
else
return - V_17 ;
}
F_5 ( & V_11 -> V_9 , V_15 , V_14 ) ;
F_6 ( & V_11 -> V_9 , V_6 ) ;
return 0 ;
}
static const char * F_7 ( enum V_18 V_19 )
{
switch ( V_19 ) {
case V_20 : return L_4 ;
case V_21 : return L_5 ;
case V_22 : return L_6 ;
case V_23 : return L_7 ;
case V_24 : return L_8 ;
case V_25 : return L_9 ;
case V_26 : return L_10 ;
case V_27 : return L_11 ;
case V_28 : return L_12 ;
case V_29 : return L_13 ;
case V_30 : return L_14 ;
default: return L_15 ;
} ;
}
static inline int F_8 ( struct V_31 * V_32 , int V_33 ,
enum V_18 V_34 , int V_35 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_39 * V_40 =
& V_38 -> V_41 . V_42 . V_43 . V_40 [ V_34 ] ;
int V_44 = - V_45 ;
int V_46 , free , V_47 , V_48 , V_49 ;
int V_50 ;
if ( V_33 > V_32 -> V_51 -> V_52 )
return - V_45 ;
F_9 ( & V_40 -> V_53 ) ;
V_46 = ( V_36 > 0 ) ?
V_40 -> V_46 [ ( V_36 - 1 ) *
( V_32 -> V_51 -> V_52 + 1 ) + V_33 ] :
V_40 -> V_46 [ V_33 ] ;
free = ( V_36 > 0 ) ? V_40 -> V_54 [ V_36 - 1 ] :
V_40 -> V_55 ;
V_47 = ( V_36 > 0 ) ? V_40 -> V_56 [ V_36 - 1 ] :
V_40 -> V_57 ;
V_48 = V_40 -> V_48 [ V_33 ] ;
if ( V_46 + V_35 > V_40 -> V_58 [ V_33 ] ) {
F_10 ( V_32 , L_16 ,
V_33 , V_36 , F_7 ( V_34 ) , V_35 ,
V_46 , V_40 -> V_58 [ V_33 ] ) ;
goto V_59;
}
if ( V_46 + V_35 <= V_48 ) {
V_44 = 0 ;
V_50 = V_35 ;
} else {
if ( V_48 - V_46 > 0 )
V_49 = V_35 - ( V_48 - V_46 ) ;
else
V_49 = V_35 ;
V_50 = V_35 - V_49 ;
if ( free - V_49 >= V_47 )
V_44 = 0 ;
else
F_10 ( V_32 , L_17 ,
V_33 , V_36 , F_7 ( V_34 ) , free ,
V_49 , V_47 ) ;
}
if ( ! V_44 ) {
if ( V_36 > 0 ) {
V_40 -> V_46 [ ( V_36 - 1 ) *
( V_32 -> V_51 -> V_52 + 1 ) + V_33 ] += V_35 ;
V_40 -> V_54 [ V_36 - 1 ] -= V_35 ;
V_40 -> V_56 [ V_36 - 1 ] -= V_50 ;
} else {
V_40 -> V_46 [ V_33 ] += V_35 ;
V_40 -> V_55 -= V_35 ;
V_40 -> V_57 -= V_50 ;
}
}
V_59:
F_11 ( & V_40 -> V_53 ) ;
return V_44 ;
}
static inline void F_12 ( struct V_31 * V_32 , int V_33 ,
enum V_18 V_34 , int V_35 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_39 * V_40 =
& V_38 -> V_41 . V_42 . V_43 . V_40 [ V_34 ] ;
int V_46 , V_48 , V_50 ;
if ( V_33 > V_32 -> V_51 -> V_52 )
return;
F_9 ( & V_40 -> V_53 ) ;
V_46 = ( V_36 > 0 ) ?
V_40 -> V_46 [ ( V_36 - 1 ) *
( V_32 -> V_51 -> V_52 + 1 ) + V_33 ] :
V_40 -> V_46 [ V_33 ] ;
V_48 = V_40 -> V_48 [ V_33 ] ;
if ( V_46 - V_35 >= V_48 ) {
V_50 = 0 ;
} else {
if ( V_46 - V_48 > 0 )
V_50 = V_35 - ( V_46 - V_48 ) ;
else
V_50 = V_35 ;
}
if ( V_36 > 0 ) {
V_40 -> V_46 [ ( V_36 - 1 ) *
( V_32 -> V_51 -> V_52 + 1 ) + V_33 ] -= V_35 ;
V_40 -> V_54 [ V_36 - 1 ] += V_35 ;
V_40 -> V_56 [ V_36 - 1 ] += V_50 ;
} else {
V_40 -> V_46 [ V_33 ] -= V_35 ;
V_40 -> V_55 += V_35 ;
V_40 -> V_57 += V_50 ;
}
F_11 ( & V_40 -> V_53 ) ;
return;
}
static inline void F_13 ( struct V_31 * V_32 ,
struct V_39 * V_40 ,
enum V_18 V_34 ,
int V_60 , int V_61 )
{
V_40 -> V_48 [ V_60 ] = V_61 /
( 2 * ( V_32 -> V_51 -> V_52 + 1 ) ) ;
V_40 -> V_58 [ V_60 ] = ( V_61 / 2 ) + V_40 -> V_48 [ V_60 ] ;
if ( V_60 == F_14 ( V_32 ) ) {
V_40 -> V_55 = V_61 ;
if ( V_34 == V_24 ) {
V_40 -> V_55 += V_32 -> V_62 . V_63 ;
V_40 -> V_48 [ V_60 ] += V_32 -> V_62 . V_63 ;
V_40 -> V_58 [ V_60 ] += V_32 -> V_62 . V_63 ;
}
}
}
void F_15 ( struct V_31 * V_32 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_64 ;
if ( F_16 ( V_32 ) )
return;
if ( ! F_17 ( V_32 ) ) {
V_32 -> V_65 . V_66 = V_32 -> V_62 . V_67 - V_32 -> V_62 . V_68 -
F_18 ( V_32 ) ;
V_32 -> V_65 . V_69 = V_32 -> V_62 . V_70 - V_32 -> V_62 . V_71 ;
V_32 -> V_65 . V_72 = V_32 -> V_62 . V_73 - V_32 -> V_62 . V_74 ;
V_32 -> V_65 . V_75 = V_32 -> V_62 . V_76 - V_32 -> V_62 . V_63 ;
V_32 -> V_65 . V_77 = V_32 -> V_62 . V_78 - V_32 -> V_62 . V_79 ;
return;
}
V_64 = F_14 ( V_32 ) ;
V_32 -> V_65 . V_66 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_20 ] . V_58 [ V_64 ] ;
V_32 -> V_65 . V_69 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_21 ] . V_58 [ V_64 ] ;
V_32 -> V_65 . V_72 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_22 ] . V_58 [ V_64 ] ;
V_32 -> V_65 . V_75 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_24 ] . V_58 [ V_64 ] ;
V_32 -> V_65 . V_77 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_23 ] . V_58 [ V_64 ] ;
}
static int F_19 ( struct V_31 * V_32 )
{
return ( V_32 -> V_62 . V_80 - 1 -
( V_81 * V_82 ) )
/ V_82 ;
}
int F_20 ( struct V_31 * V_32 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_83 , V_84 ;
int V_85 ;
int V_86 = F_19 ( V_32 ) ;
V_38 -> V_41 . V_42 . V_43 . V_87 =
F_21 ( V_32 -> V_88 * sizeof( struct V_87 ) ,
V_89 ) ;
if ( ! V_38 -> V_41 . V_42 . V_43 . V_87 )
return - V_90 ;
for ( V_83 = 0 ; V_83 < V_32 -> V_88 ; V_83 ++ ) {
for ( V_85 = 0 ; V_85 < V_91 ; ++ V_85 )
F_22 ( & V_38 -> V_41 . V_42 . V_43 .
V_87 [ V_83 ] . V_92 [ V_85 ] ) ;
F_23 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_83 ] . V_93 ) ;
}
F_24 ( V_32 , L_18 ,
V_32 -> V_88 ) ;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ )
V_38 -> V_41 . V_42 . V_43 . V_94 [ V_83 ] = V_95 ;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
struct V_39 * V_40 =
& V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] ;
V_40 -> V_58 = F_25 ( ( V_32 -> V_51 -> V_52 + 1 ) *
sizeof( int ) , V_89 ) ;
V_40 -> V_48 = F_25 ( ( V_32 -> V_51 -> V_52 + 1 ) *
sizeof( int ) , V_89 ) ;
if ( V_83 == V_25 || V_83 == V_26 )
V_40 -> V_46 = F_21 ( V_82 *
( V_32 -> V_51 -> V_52
+ 1 ) *
sizeof( int ) , V_89 ) ;
else
V_40 -> V_46 = F_21 ( ( V_32 -> V_51 ->
V_52 + 1 ) *
sizeof( int ) , V_89 ) ;
if ( V_83 == V_28 )
V_40 -> V_55 = V_32 -> V_62 . V_80 - 1 ;
if ( ! V_40 -> V_58 || ! V_40 -> V_48 ||
! V_40 -> V_46 )
goto V_96;
F_26 ( & V_40 -> V_53 ) ;
for ( V_85 = 0 ; V_85 < V_32 -> V_51 -> V_52 + 1 ; V_85 ++ ) {
struct V_97 V_98 =
F_27 ( V_32 , V_85 ) ;
switch ( V_83 ) {
case V_20 :
F_13 ( V_32 , V_40 , V_20 ,
V_85 , V_32 -> V_62 . V_67 -
V_32 -> V_62 . V_68 -
F_18 ( V_32 ) ) ;
break;
case V_21 :
F_13 ( V_32 , V_40 , V_21 ,
V_85 , V_32 -> V_62 . V_70 -
V_32 -> V_62 . V_71 ) ;
break;
case V_22 :
F_13 ( V_32 , V_40 , V_22 ,
V_85 , V_32 -> V_62 . V_73 -
V_32 -> V_62 . V_74 ) ;
break;
case V_23 :
F_13 ( V_32 , V_40 , V_23 ,
V_85 , V_32 -> V_62 . V_78 -
V_32 -> V_62 . V_79 ) ;
break;
case V_24 :
F_13 ( V_32 , V_40 , V_24 ,
V_85 , V_32 -> V_62 . V_76 -
V_32 -> V_62 . V_63 ) ;
break;
case V_25 :
if ( V_85 == F_14 ( V_32 ) ) {
int V_99 = 0 ;
for ( V_84 = 0 ; V_84 < V_32 -> V_62 . V_100 ;
V_84 ++ ) {
struct V_101 V_102 =
F_28 ( V_32 , V_84 + 1 ) ;
unsigned V_103 =
F_29 ( V_102 . V_104 ,
V_32 -> V_62 . V_100 ) - 1 ;
if ( V_99 < V_103 )
V_99 =
V_103 ;
}
V_40 -> V_58 [ V_85 ] =
V_105 -
2 * V_99 ;
V_40 -> V_48 [ V_85 ] = 2 ;
for ( V_84 = 0 ; V_84 < V_82 ; V_84 ++ )
V_40 -> V_54 [ V_84 ] =
V_105 ;
} else {
V_40 -> V_58 [ V_85 ] = V_105 ;
V_40 -> V_48 [ V_85 ] = 2 ;
}
break;
case V_26 :
if ( V_85 == F_14 ( V_32 ) ) {
V_40 -> V_58 [ V_85 ] = V_106 ;
V_40 -> V_48 [ V_85 ] = V_106 / 2 ;
for ( V_84 = 0 ; V_84 < V_82 ; V_84 ++ )
V_40 -> V_54 [ V_84 ] =
V_40 -> V_58 [ V_85 ] ;
} else {
V_40 -> V_58 [ V_85 ] = V_106 / 2 ;
V_40 -> V_48 [ V_85 ] = 0 ;
}
break;
case V_28 :
V_40 -> V_58 [ V_85 ] = V_32 -> V_62 . V_80 ;
if ( V_85 == F_14 ( V_32 ) )
V_40 -> V_48 [ V_85 ] =
V_81 *
V_82 ;
else if ( V_85 <= V_86 )
V_40 -> V_48 [ V_85 ] =
V_107 *
V_82 ;
else
V_40 -> V_48 [ V_85 ] = 0 ;
V_40 -> V_55 -= V_40 -> V_48 [ V_85 ] ;
break;
default:
break;
}
if ( V_83 == V_25 || V_83 == V_26 ) {
for ( V_84 = 0 ; V_84 < V_32 -> V_62 . V_100 ; V_84 ++ )
if ( F_30 ( V_84 , V_98 . V_108 ) )
V_40 -> V_56 [ V_84 ] +=
V_40 -> V_48 [ V_85 ] ;
} else {
V_40 -> V_57 += V_40 -> V_48 [ V_85 ] ;
}
}
}
F_26 ( & V_38 -> V_41 . V_42 . V_43 . V_109 ) ;
return 0 ;
V_96:
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_46 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_46 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_48 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_48 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_58 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_58 = NULL ;
}
return - V_90 ;
}
void F_32 ( struct V_31 * V_32 ,
enum V_110 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_83 ;
if ( V_38 -> V_41 . V_42 . V_43 . V_87 ) {
if ( type != V_111 ) {
for ( V_83 = 0 ; V_83 < V_32 -> V_88 ; V_83 ++ ) {
if ( type == V_112 ||
V_32 -> V_62 . V_113 != V_83 )
F_33 ( V_32 , V_83 ) ;
}
V_83 = V_32 -> V_62 . V_113 ;
F_34 ( V_32 , V_83 ) ;
F_35 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_83 ] . V_93 ) ;
F_36 ( V_32 , V_83 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_83 ] . V_93 ) ;
}
if ( type != V_114 ) {
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_46 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_46 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_48 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_48 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_58 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_83 ] . V_58 = NULL ;
}
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_87 ) ;
V_38 -> V_41 . V_42 . V_43 . V_87 = NULL ;
}
}
}
static void F_38 ( struct V_31 * V_32 , int V_33 ,
struct V_115 * V_116 )
{
T_2 V_117 = * ( T_2 * ) ( V_116 -> V_118 + 64 ) ;
T_2 V_119 = * ( T_2 * ) ( V_116 -> V_118 + 35 ) ;
T_2 V_120 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_36 ;
V_36 = ( V_117 >> 6 & 1 ) + 1 ;
V_120 = V_38 -> V_121 [ V_33 ] [ V_36 - 1 ] [ V_119 ] ;
* ( T_2 * ) ( V_116 -> V_118 + 35 ) = V_120 ;
}
static void F_39 ( struct V_31 * V_32 , struct V_115 * V_116 ,
T_2 V_33 )
{
struct V_122 * V_123 = V_116 -> V_118 + 8 ;
enum V_124 V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
T_3 V_127 = ( F_40 ( V_123 -> V_128 ) >> 16 ) & 0xff ;
int V_36 ;
if ( V_129 == V_127 ) {
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) )
V_123 -> V_130 . V_132 =
F_42 ( V_32 , V_33 , V_36 ) | 0x80 ;
else
V_123 -> V_130 . V_132 = V_33 | 0x80 ;
} else if ( V_133 == V_127 || V_134 == V_127 || V_135 == V_127 ) {
if ( V_125 & V_136 ) {
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) ) {
V_123 -> V_130 . V_132 +=
F_42 ( V_32 , V_33 , V_36 ) ;
V_123 -> V_130 . V_132 &= 0x7f ;
} else {
V_123 -> V_130 . V_132 = V_33 & 0x7F ;
}
}
if ( V_125 & V_137 ) {
V_36 = ( V_123 -> V_138 . V_131 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) ) {
V_123 -> V_138 . V_132 +=
F_42 ( V_32 , V_33 , V_36 ) ;
V_123 -> V_138 . V_132 &= 0x7f ;
} else {
V_123 -> V_138 . V_132 = V_33 & 0x7F ;
}
}
}
}
static int F_43 ( struct V_31 * V_32 ,
struct V_115 * V_116 ,
T_2 V_33 , T_3 V_139 )
{
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
struct V_141 * V_142 ;
struct V_37 * V_38 ;
T_3 V_143 ;
int V_36 , V_44 = 0 ;
V_36 = ( V_140 -> V_130 . V_131 & 0x40 ) ? 2 : 1 ;
V_38 = V_37 ( V_32 ) ;
V_142 = & V_38 -> V_41 . V_42 . V_144 [ V_33 ] . V_145 [ V_36 ] ;
V_143 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
V_44 = F_44 ( V_32 , V_140 , V_33 , V_36 ) ;
if ( V_44 )
goto V_59;
if ( V_146 != V_142 -> V_2 . V_147 ) {
if ( F_45 ( V_32 , V_139 ) )
return 0 ;
if ( V_143 == V_129 ||
( V_143 == V_148 && F_41 ( V_32 , V_36 ) ) ) {
if ( V_32 -> V_62 . V_149 & V_150 ) {
* ( V_126 * ) V_116 -> V_118 =
F_46 ( F_40 ( * ( V_126 * ) V_116 -> V_118 ) |
V_151 ) ;
V_140 -> V_152 &= ~ F_46 ( V_153 ) ;
} else {
struct V_154 V_155 = { . V_128 = 0 } ;
V_44 = F_47 ( V_32 , V_139 , V_156 , & V_155 ) ;
if ( V_44 )
goto V_59;
}
}
V_140 -> V_130 . V_157 &=
V_158 ;
if ( V_142 -> V_2 . V_159 == V_160 &&
V_32 -> V_62 . V_161 & V_162 ) {
V_140 -> V_130 . V_157 |=
V_163 |
V_164 |
V_165 |
V_166 |
V_167 |
V_168 ;
} else if ( 0 != V_142 -> V_2 . V_147 ) {
V_140 -> V_130 . V_157 |=
V_163 |
V_166 |
V_167 ;
} else {
V_140 -> V_130 . V_157 |=
V_163 |
V_168 ;
}
V_140 -> V_130 . V_169 |= V_170 ;
V_140 -> V_130 . V_171 = V_142 -> V_172 ;
V_140 -> V_130 . V_173 |= V_174 | V_175 ;
V_140 -> V_130 . V_176 |= V_177 | V_178 ;
V_140 -> V_130 . V_131 &= 0xC7 ;
V_140 -> V_130 . V_131 |= ( V_142 -> V_2 . V_179 ) << 3 ;
V_140 -> V_180 = V_142 -> V_2 . V_180 ;
}
if ( V_142 -> V_2 . V_181 ) {
V_140 -> V_130 . V_176 |= V_182 ;
V_140 -> V_130 . V_183 = ( 0x80 & V_140 -> V_130 . V_183 ) + V_142 -> V_184 ;
}
V_59:
return V_44 ;
}
static int F_48 ( struct V_31 * V_32 )
{
return V_32 -> V_62 . V_78 - 1 ;
}
static void * F_49 ( struct V_31 * V_32 , T_1 V_7 ,
enum V_18 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
return F_2 ( & V_38 -> V_41 . V_42 . V_43 . V_94 [ type ] ,
V_7 ) ;
}
static int F_50 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type ,
void * V_11 )
{
struct V_10 * V_185 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_49 ( V_32 , V_7 , type ) ;
if ( ! V_185 ) {
V_44 = - V_186 ;
goto exit;
}
if ( V_185 -> V_2 == V_187 ) {
V_44 = - V_188 ;
goto exit;
}
if ( V_185 -> V_189 != V_33 ) {
V_44 = - V_190 ;
goto exit;
}
V_185 -> V_191 = V_185 -> V_2 ;
V_185 -> V_2 = V_187 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_185 ;
exit:
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
int F_54 ( struct V_31 * V_32 ,
enum V_18 type ,
T_1 V_7 , int * V_33 )
{
struct V_10 * V_185 ;
int V_44 = - V_192 ;
int V_193 = V_7 ;
if ( type == V_20 )
V_193 &= 0x7fffff ;
F_9 ( F_52 ( V_32 ) ) ;
V_185 = F_49 ( V_32 , V_193 , type ) ;
if ( V_185 ) {
* V_33 = V_185 -> V_189 ;
V_44 = 0 ;
}
F_11 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static void F_55 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_185 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_49 ( V_32 , V_7 , type ) ;
if ( V_185 )
V_185 -> V_2 = V_185 -> V_191 ;
F_53 ( F_52 ( V_32 ) ) ;
}
static int F_56 ( struct V_31 * V_32 , T_2 V_33 , int V_36 ,
int V_194 )
{
struct V_10 * V_185 ;
struct V_195 * V_196 ;
int V_197 = 0 ;
if ( V_194 == F_57 ( V_32 ) )
return V_197 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_49 ( V_32 , V_194 , V_28 ) ;
if ( ! V_185 || V_185 -> V_189 != V_33 )
V_197 = - V_45 ;
V_196 = F_3 ( V_185 , struct V_195 , V_198 ) ;
if ( ! V_196 -> V_36 )
V_196 -> V_36 = V_36 ;
F_53 ( F_52 ( V_32 ) ) ;
return V_197 ;
}
static int F_58 ( struct V_31 * V_32 ,
struct V_122 * V_140 , T_2 V_33 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_201 ;
struct V_195 * V_196 ;
T_1 V_202 = F_57 ( V_32 ) ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
F_59 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_196 = F_3 ( V_201 , struct V_195 , V_198 ) ;
if ( V_36 == V_196 -> V_36 ) {
V_140 -> V_130 . V_194 = V_196 -> V_198 . V_7 ;
F_53 ( F_52 ( V_32 ) ) ;
return 0 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
V_44 = F_60 ( V_32 , V_33 , V_203 , 0 , 0 , & V_202 ,
V_36 ) ;
if ( V_44 == - V_192 ) {
V_44 = 0 ;
} else if ( V_44 && V_44 != - V_204 ) {
F_61 ( V_32 , L_19 ,
V_205 , V_33 , V_44 ) ;
} else {
V_140 -> V_130 . V_194 = V_202 ;
F_24 ( V_32 , L_20 ,
V_205 , V_33 , V_140 -> V_130 . V_194 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_44 ( struct V_31 * V_32 , struct V_122 * V_140 ,
T_2 V_33 , int V_36 )
{
if ( V_140 -> V_130 . V_194 != F_57 ( V_32 ) )
return F_56 ( V_32 , V_33 , V_36 ,
V_140 -> V_130 . V_194 ) ;
return F_58 ( V_32 , V_140 , V_33 , V_36 ) ;
}
static struct V_10 * F_62 ( int V_193 )
{
struct V_206 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_207 ;
V_197 -> V_208 = V_193 ;
F_22 ( & V_197 -> V_209 ) ;
F_26 ( & V_197 -> V_210 ) ;
F_63 ( & V_197 -> V_211 , 0 ) ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_64 ( int V_193 , int V_212 )
{
struct V_213 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_212 = V_212 ;
V_197 -> V_198 . V_2 = V_4 ;
F_63 ( & V_197 -> V_211 , 0 ) ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_65 ( int V_193 , int V_214 )
{
struct V_215 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_216 ;
V_197 -> V_214 = V_214 ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_66 ( int V_193 )
{
struct V_217 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_218 ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_67 ( int V_193 )
{
struct V_219 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_220 ;
F_63 ( & V_197 -> V_211 , 0 ) ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_68 ( int V_193 )
{
struct V_221 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_222 ;
F_63 ( & V_197 -> V_211 , 0 ) ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_69 ( int V_193 , int V_36 )
{
struct V_195 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_223 ;
V_197 -> V_36 = V_36 ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_70 ( int V_193 )
{
struct V_224 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_225 ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_71 ( T_1 V_193 , int V_139 )
{
struct V_226 * V_197 ;
V_197 = F_21 ( sizeof *V_197 , V_89 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_198 . V_7 = V_193 ;
V_197 -> V_198 . V_2 = V_227 ;
V_197 -> V_139 = V_139 ;
return & V_197 -> V_198 ;
}
static struct V_10 * F_72 ( T_1 V_193 , enum V_18 type , int V_33 ,
int V_228 )
{
struct V_10 * V_197 ;
switch ( type ) {
case V_20 :
V_197 = F_62 ( V_193 ) ;
break;
case V_23 :
V_197 = F_65 ( V_193 , V_228 ) ;
break;
case V_24 :
V_197 = F_64 ( V_193 , V_228 ) ;
break;
case V_27 :
V_197 = F_66 ( V_193 ) ;
break;
case V_21 :
V_197 = F_67 ( V_193 ) ;
break;
case V_22 :
V_197 = F_68 ( V_193 ) ;
break;
case V_25 :
F_73 ( L_21 ) ;
return NULL ;
case V_28 :
V_197 = F_69 ( V_193 , V_228 ) ;
break;
case V_30 :
V_197 = F_70 ( V_193 ) ;
break;
case V_29 :
V_197 = F_71 ( V_193 , V_228 ) ;
break;
default:
return NULL ;
}
if ( V_197 )
V_197 -> V_189 = V_33 ;
return V_197 ;
}
int F_74 ( struct V_31 * V_32 , int V_33 , int V_36 ,
struct V_229 * V_230 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_201 ;
struct V_195 * V_196 ;
int * V_231 ;
int V_83 = 0 , V_44 = 0 ;
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
V_231 = F_75 ( V_32 -> V_62 . V_80 ,
sizeof( * V_231 ) , V_89 ) ;
if ( ! V_231 )
return - V_90 ;
F_51 ( F_52 ( V_32 ) ) ;
F_59 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_196 = F_3 ( V_201 , struct V_195 , V_198 ) ;
if ( V_196 -> V_36 == V_36 ) {
V_231 [ V_83 ] = ( int ) V_201 -> V_7 ;
V_83 ++ ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
V_231 [ V_83 ] = - 1 ;
V_83 = 0 ;
while ( V_231 [ V_83 ] != - 1 ) {
V_44 = F_76 ( V_32 , V_231 [ V_83 ] , V_230 ,
0 ) ;
if ( V_44 ) {
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
goto V_232;
}
V_83 ++ ;
}
V_232:
F_31 ( V_231 ) ;
return 0 ;
}
static int F_77 ( struct V_31 * V_32 , int V_33 , T_1 V_233 , int V_35 ,
enum V_18 type , int V_228 )
{
int V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_10 * * V_234 ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_200 -> V_94 [ type ] ;
V_234 = F_21 ( V_35 * sizeof *V_234 , V_89 ) ;
if ( ! V_234 )
return - V_90 ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
V_234 [ V_83 ] = F_72 ( V_233 + V_83 , type , V_33 , V_228 ) ;
if ( ! V_234 [ V_83 ] ) {
for ( -- V_83 ; V_83 >= 0 ; -- V_83 )
F_31 ( V_234 [ V_83 ] ) ;
F_31 ( V_234 ) ;
return - V_90 ;
}
}
F_51 ( F_52 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
if ( F_49 ( V_32 , V_233 + V_83 , type ) ) {
V_44 = - V_17 ;
goto V_235;
}
V_44 = F_4 ( V_6 , V_234 [ V_83 ] ) ;
if ( V_44 )
goto V_235;
F_78 ( & V_234 [ V_83 ] -> V_236 ,
& V_200 -> V_87 [ V_33 ] . V_92 [ type ] ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
F_31 ( V_234 ) ;
return 0 ;
V_235:
for ( -- V_83 ; V_83 >= 0 ; -- V_83 ) {
F_79 ( & V_234 [ V_83 ] -> V_9 , V_6 ) ;
F_80 ( & V_234 [ V_83 ] -> V_236 ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 )
F_31 ( V_234 [ V_83 ] ) ;
F_31 ( V_234 ) ;
return V_44 ;
}
static int F_81 ( struct V_206 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_237 || F_82 ( & V_11 -> V_211 ) ||
! F_83 ( & V_11 -> V_209 ) ) {
F_73 ( L_22 ,
V_11 -> V_198 . V_2 , F_82 ( & V_11 -> V_211 ) ) ;
return - V_188 ;
} else if ( V_11 -> V_198 . V_2 != V_207 ) {
return - V_190 ;
}
return 0 ;
}
static int F_84 ( struct V_213 * V_11 , int V_212 )
{
if ( V_11 -> V_198 . V_2 == V_3 ||
F_82 ( & V_11 -> V_211 ) ) {
F_85 ( L_23 ,
V_205 , __LINE__ ,
F_1 ( V_11 -> V_198 . V_2 ) ,
F_82 ( & V_11 -> V_211 ) ) ;
return - V_188 ;
} else if ( V_11 -> V_198 . V_2 != V_4 )
return - V_190 ;
else if ( V_11 -> V_212 != V_212 )
return - V_45 ;
return 0 ;
}
static int F_86 ( struct V_215 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_238 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_216 )
return - V_190 ;
return 0 ;
}
static int F_87 ( struct V_217 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_238 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_216 )
return - V_190 ;
return 0 ;
}
static int F_88 ( struct V_195 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_239 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_223 )
return - V_190 ;
return 0 ;
}
static int F_89 ( struct V_224 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_240 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_225 )
return - V_190 ;
return 0 ;
}
static int F_90 ( struct V_226 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_241 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_227 )
return - V_190 ;
return 0 ;
}
static int F_91 ( struct V_219 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_242 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_220 )
return - V_190 ;
return 0 ;
}
static int F_92 ( struct V_221 * V_11 )
{
if ( V_11 -> V_198 . V_2 == V_243 )
return - V_188 ;
else if ( V_11 -> V_198 . V_2 != V_222 )
return - V_190 ;
return 0 ;
}
static int F_93 ( struct V_10 * V_11 , enum V_18 type , int V_228 )
{
switch ( type ) {
case V_20 :
return F_81 ( (struct V_206 * ) V_11 ) ;
case V_21 :
return F_91 ( (struct V_219 * ) V_11 ) ;
case V_22 :
return F_92 ( (struct V_221 * ) V_11 ) ;
case V_23 :
return F_86 ( (struct V_215 * ) V_11 ) ;
case V_24 :
return F_84 ( (struct V_213 * ) V_11 , V_228 ) ;
case V_25 :
return - V_244 ;
case V_27 :
return F_87 ( (struct V_217 * ) V_11 ) ;
case V_28 :
return F_88 ( (struct V_195 * ) V_11 ) ;
case V_30 :
return F_89 ( (struct V_224 * ) V_11 ) ;
case V_29 :
return F_90 ( (struct V_226 * ) V_11 ) ;
default:
return - V_45 ;
}
}
static int F_94 ( struct V_31 * V_32 , int V_33 , T_1 V_233 , int V_35 ,
enum V_18 type , int V_228 )
{
T_1 V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_185 ;
F_51 ( F_52 ( V_32 ) ) ;
for ( V_83 = V_233 ; V_83 < V_233 + V_35 ; ++ V_83 ) {
V_185 = F_2 ( & V_200 -> V_94 [ type ] , V_83 ) ;
if ( ! V_185 ) {
V_44 = - V_192 ;
goto V_59;
}
if ( V_185 -> V_189 != V_33 ) {
V_44 = - V_190 ;
goto V_59;
}
V_44 = F_93 ( V_185 , type , V_228 ) ;
if ( V_44 )
goto V_59;
}
for ( V_83 = V_233 ; V_83 < V_233 + V_35 ; ++ V_83 ) {
V_185 = F_2 ( & V_200 -> V_94 [ type ] , V_83 ) ;
F_79 ( & V_185 -> V_9 , & V_200 -> V_94 [ type ] ) ;
F_95 ( & V_185 -> V_236 ) ;
F_31 ( V_185 ) ;
}
V_44 = 0 ;
V_59:
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_96 ( struct V_31 * V_32 , int V_33 , int V_139 ,
enum V_245 V_2 , struct V_206 * * V_66 ,
int V_246 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_206 * V_185 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ V_20 ] , V_139 ) ;
if ( ! V_185 )
V_44 = - V_192 ;
else if ( V_185 -> V_198 . V_189 != V_33 )
V_44 = - V_190 ;
else {
switch ( V_2 ) {
case V_237 :
F_24 ( V_32 , L_24 ,
V_205 , V_185 -> V_198 . V_7 ) ;
V_44 = - V_188 ;
break;
case V_207 :
if ( V_185 -> V_198 . V_2 == V_247 && ! V_246 )
break;
F_24 ( V_32 , L_25 , V_185 -> V_198 . V_7 ) ;
V_44 = - V_45 ;
break;
case V_247 :
if ( ( V_185 -> V_198 . V_2 == V_207 && V_246 ) ||
V_185 -> V_198 . V_2 == V_248 )
break;
else {
F_24 ( V_32 , L_25 ,
V_185 -> V_198 . V_7 ) ;
V_44 = - V_45 ;
}
break;
case V_248 :
if ( V_185 -> V_198 . V_2 != V_247 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_185 -> V_198 . V_191 = V_185 -> V_198 . V_2 ;
V_185 -> V_198 . V_249 = V_2 ;
V_185 -> V_198 . V_2 = V_237 ;
if ( V_66 )
* V_66 = V_185 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_97 ( struct V_31 * V_32 , int V_33 , int V_250 ,
enum V_251 V_2 , struct V_215 * * V_77 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_215 * V_185 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ V_23 ] , V_250 ) ;
if ( ! V_185 )
V_44 = - V_192 ;
else if ( V_185 -> V_198 . V_189 != V_33 )
V_44 = - V_190 ;
else {
switch ( V_2 ) {
case V_238 :
V_44 = - V_45 ;
break;
case V_216 :
if ( V_185 -> V_198 . V_2 != V_252 )
V_44 = - V_45 ;
break;
case V_252 :
if ( V_185 -> V_198 . V_2 != V_216 &&
V_185 -> V_198 . V_2 != V_253 )
V_44 = - V_45 ;
break;
case V_253 :
if ( V_185 -> V_198 . V_2 != V_252 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_185 -> V_198 . V_191 = V_185 -> V_198 . V_2 ;
V_185 -> V_198 . V_249 = V_2 ;
V_185 -> V_198 . V_2 = V_238 ;
if ( V_77 )
* V_77 = V_185 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_98 ( struct V_31 * V_32 , int V_33 , int V_250 ,
enum V_254 V_2 , struct V_217 * * V_255 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_217 * V_185 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ V_27 ] , V_250 ) ;
if ( ! V_185 )
V_44 = - V_192 ;
else if ( V_185 -> V_198 . V_189 != V_33 )
V_44 = - V_190 ;
else {
switch ( V_2 ) {
case V_256 :
V_44 = - V_45 ;
break;
case V_218 :
if ( V_185 -> V_198 . V_2 != V_257 )
V_44 = - V_45 ;
break;
case V_257 :
if ( V_185 -> V_198 . V_2 != V_218 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_185 -> V_198 . V_191 = V_185 -> V_198 . V_2 ;
V_185 -> V_198 . V_249 = V_2 ;
V_185 -> V_198 . V_2 = V_256 ;
if ( V_255 )
* V_255 = V_185 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_99 ( struct V_31 * V_32 , int V_33 , int V_258 ,
enum V_259 V_2 , struct V_219 * * V_69 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_219 * V_185 ;
int V_44 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ V_21 ] , V_258 ) ;
if ( ! V_185 ) {
V_44 = - V_192 ;
} else if ( V_185 -> V_198 . V_189 != V_33 ) {
V_44 = - V_190 ;
} else if ( V_2 == V_220 ) {
if ( V_185 -> V_198 . V_2 != V_260 )
V_44 = - V_45 ;
else if ( F_82 ( & V_185 -> V_211 ) )
V_44 = - V_188 ;
else
V_44 = 0 ;
} else if ( V_2 != V_260 || V_185 -> V_198 . V_2 != V_220 ) {
V_44 = - V_45 ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
V_185 -> V_198 . V_191 = V_185 -> V_198 . V_2 ;
V_185 -> V_198 . V_249 = V_2 ;
V_185 -> V_198 . V_2 = V_242 ;
if ( V_69 )
* V_69 = V_185 ;
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_100 ( struct V_31 * V_32 , int V_33 , int V_250 ,
enum V_261 V_2 , struct V_221 * * V_72 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_221 * V_185 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ V_22 ] , V_250 ) ;
if ( ! V_185 ) {
V_44 = - V_192 ;
} else if ( V_185 -> V_198 . V_189 != V_33 ) {
V_44 = - V_190 ;
} else if ( V_2 == V_222 ) {
if ( V_185 -> V_198 . V_2 != V_262 )
V_44 = - V_45 ;
else if ( F_82 ( & V_185 -> V_211 ) )
V_44 = - V_188 ;
} else if ( V_2 != V_262 || V_185 -> V_198 . V_2 != V_222 ) {
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_185 -> V_198 . V_191 = V_185 -> V_198 . V_2 ;
V_185 -> V_198 . V_249 = V_2 ;
V_185 -> V_198 . V_2 = V_243 ;
if ( V_72 )
* V_72 = V_185 ;
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static void F_101 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_193 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_185 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ type ] , V_193 ) ;
if ( V_185 && ( V_185 -> V_189 == V_33 ) )
V_185 -> V_2 = V_185 -> V_191 ;
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_102 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_193 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_185 ;
F_51 ( F_52 ( V_32 ) ) ;
V_185 = F_2 ( & V_200 -> V_94 [ type ] , V_193 ) ;
if ( V_185 && ( V_185 -> V_189 == V_33 ) )
V_185 -> V_2 = V_185 -> V_249 ;
F_53 ( F_52 ( V_32 ) ) ;
}
static int F_103 ( struct V_31 * V_32 , int V_33 , int V_139 )
{
return F_45 ( V_32 , V_139 ) &&
( F_104 ( V_32 ) || F_105 ( V_32 , V_33 , V_139 ) ) ;
}
static int F_106 ( struct V_31 * V_32 , int V_139 )
{
return V_139 < V_32 -> V_62 . V_263 [ V_264 ] ;
}
static int F_107 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_44 ;
int V_35 ;
int V_269 ;
int V_233 ;
int V_139 ;
T_2 V_128 ;
switch ( V_265 ) {
case V_203 :
V_35 = F_108 ( & V_267 ) & 0xffffff ;
V_128 = ( F_108 ( & V_267 ) >> 24 ) & V_32 -> V_62 . V_270 ;
V_269 = F_109 ( & V_267 ) ;
V_44 = F_8 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_110 ( V_32 , V_35 , V_269 , & V_233 , V_128 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
return V_44 ;
}
V_44 = F_77 ( V_32 , V_33 , V_233 , V_35 , V_20 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_111 ( V_32 , V_233 , V_35 ) ;
return V_44 ;
}
F_112 ( V_268 , V_233 ) ;
break;
case V_271 :
V_139 = F_108 ( & V_267 ) & 0x7fffff ;
if ( F_103 ( V_32 , V_33 , V_139 ) ) {
V_44 = F_77 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_96 ( V_32 , V_33 , V_139 , V_247 ,
NULL , 1 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_106 ( V_32 , V_139 ) ) {
V_44 = F_113 ( V_32 , V_139 , V_89 ) ;
if ( V_44 ) {
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
}
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_114 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_44 = - V_45 ;
int V_233 ;
int V_212 ;
if ( V_265 != V_272 )
return V_44 ;
V_212 = F_108 ( & V_267 ) ;
V_44 = F_8 ( V_32 , V_33 , V_24 , 1 << V_212 , 0 ) ;
if ( V_44 )
return V_44 ;
V_233 = F_115 ( V_32 , V_212 ) ;
if ( V_233 == - 1 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_212 , 0 ) ;
return - V_90 ;
}
V_44 = F_77 ( V_32 , V_33 , V_233 , 1 , V_24 , V_212 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_212 , 0 ) ;
F_116 ( V_32 , V_233 , V_212 ) ;
} else {
F_112 ( V_268 , V_233 ) ;
}
return V_44 ;
}
static int F_117 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_44 = - V_45 ;
int V_250 ;
int V_193 ;
struct V_215 * V_77 ;
switch ( V_265 ) {
case V_203 :
V_44 = F_8 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
if ( V_44 )
break;
V_250 = F_118 ( V_32 ) ;
if ( V_250 == - 1 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
break;
}
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_77 ( V_32 , V_33 , V_193 , 1 , V_23 , V_250 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_119 ( V_32 , V_250 ) ;
break;
}
F_112 ( V_268 , V_250 ) ;
break;
case V_271 :
V_250 = F_108 ( & V_267 ) ;
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_97 ( V_32 , V_33 , V_193 ,
V_252 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_120 ( V_32 , V_77 -> V_214 , V_89 ) ;
if ( V_44 ) {
F_101 ( V_32 , V_33 , V_23 , V_193 ) ;
return V_44 ;
}
F_102 ( V_32 , V_33 , V_23 , V_193 ) ;
break;
}
return V_44 ;
}
static int F_121 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_258 ;
int V_44 ;
switch ( V_265 ) {
case V_272 :
V_44 = F_8 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_122 ( V_32 , & V_258 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
break;
}
V_44 = F_77 ( V_32 , V_33 , V_258 , 1 , V_21 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_123 ( V_32 , V_258 ) ;
break;
}
F_112 ( V_268 , V_258 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_124 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_273 ;
int V_44 ;
switch ( V_265 ) {
case V_272 :
V_44 = F_8 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_125 ( V_32 , & V_273 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
break;
}
V_44 = F_77 ( V_32 , V_33 , V_273 , 1 , V_22 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_126 ( V_32 , V_273 ) ;
break;
}
F_112 ( V_268 , V_273 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_127 ( struct V_31 * V_32 , int V_33 , int V_36 ,
T_2 V_274 , T_1 * V_275 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_277 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_278 * V_11 , * V_201 ;
F_128 (res, tmp, mac_list, list) {
if ( V_11 -> V_274 == V_274 && V_11 -> V_36 == ( T_2 ) V_36 ) {
* V_275 = V_11 -> V_275 ;
return 0 ;
}
}
return - V_192 ;
}
static int F_129 ( struct V_31 * V_32 , int V_33 , T_1 V_275 , int V_36 , T_2 V_274 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_277 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_278 * V_11 , * V_201 ;
F_128 (res, tmp, mac_list, list) {
if ( V_11 -> V_275 == V_275 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_211 ;
return 0 ;
}
}
if ( F_8 ( V_32 , V_33 , V_25 , 1 , V_36 ) )
return - V_45 ;
V_11 = F_21 ( sizeof *V_11 , V_89 ) ;
if ( ! V_11 ) {
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
return - V_90 ;
}
V_11 -> V_275 = V_275 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_274 = V_274 ;
V_11 -> V_211 = 1 ;
F_78 ( & V_11 -> V_236 ,
& V_200 -> V_87 [ V_33 ] . V_92 [ V_25 ] ) ;
return 0 ;
}
static void F_130 ( struct V_31 * V_32 , int V_33 , T_1 V_275 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_277 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_278 * V_11 , * V_201 ;
F_128 (res, tmp, mac_list, list) {
if ( V_11 -> V_275 == V_275 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_211 ) {
F_95 ( & V_11 -> V_236 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
F_31 ( V_11 ) ;
}
break;
}
}
}
static void F_131 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_277 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_278 * V_11 , * V_201 ;
int V_83 ;
F_128 (res, tmp, mac_list, list) {
F_95 ( & V_11 -> V_236 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_211 ; V_83 ++ )
F_132 ( V_32 , V_11 -> V_36 , V_11 -> V_275 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_133 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 , int V_279 )
{
int V_44 = - V_45 ;
int V_36 ;
T_1 V_275 ;
T_2 V_274 ;
if ( V_265 != V_272 )
return V_44 ;
V_36 = ! V_279 ? F_108 ( V_268 ) : V_279 ;
V_36 = F_134 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
V_275 = V_267 ;
V_44 = F_135 ( V_32 , V_36 , V_275 ) ;
if ( V_44 >= 0 ) {
V_274 = V_44 ;
F_112 ( V_268 , V_44 ) ;
V_44 = 0 ;
}
if ( ! V_44 ) {
V_44 = F_129 ( V_32 , V_33 , V_275 , V_36 , V_274 ) ;
if ( V_44 )
F_132 ( V_32 , V_36 , V_275 ) ;
}
return V_44 ;
}
static int F_136 ( struct V_31 * V_32 , int V_33 , T_4 V_280 ,
int V_36 , int V_171 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_281 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_282 * V_11 , * V_201 ;
F_128 (res, tmp, vlan_list, list) {
if ( V_11 -> V_280 == V_280 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_211 ;
return 0 ;
}
}
if ( F_8 ( V_32 , V_33 , V_26 , 1 , V_36 ) )
return - V_45 ;
V_11 = F_21 ( sizeof( * V_11 ) , V_89 ) ;
if ( ! V_11 ) {
F_12 ( V_32 , V_33 , V_26 , 1 , V_36 ) ;
return - V_90 ;
}
V_11 -> V_280 = V_280 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_171 = V_171 ;
V_11 -> V_211 = 1 ;
F_78 ( & V_11 -> V_236 ,
& V_200 -> V_87 [ V_33 ] . V_92 [ V_26 ] ) ;
return 0 ;
}
static void F_137 ( struct V_31 * V_32 , int V_33 , T_4 V_280 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_281 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_282 * V_11 , * V_201 ;
F_128 (res, tmp, vlan_list, list) {
if ( V_11 -> V_280 == V_280 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_211 ) {
F_95 ( & V_11 -> V_236 ) ;
F_12 ( V_32 , V_33 , V_26 ,
1 , V_36 ) ;
F_31 ( V_11 ) ;
}
break;
}
}
}
static void F_36 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_281 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_282 * V_11 , * V_201 ;
int V_83 ;
F_128 (res, tmp, vlan_list, list) {
F_95 ( & V_11 -> V_236 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_211 ; V_83 ++ )
F_138 ( V_32 , V_11 -> V_36 , V_11 -> V_280 ) ;
F_12 ( V_32 , V_33 , V_26 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_139 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 , int V_279 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_283 * V_284 = V_38 -> V_41 . V_42 . V_284 ;
int V_44 ;
T_4 V_280 ;
int V_171 ;
int V_36 ;
V_36 = ! V_279 ? F_108 ( V_268 ) : V_279 ;
if ( ! V_36 || V_265 != V_272 )
return - V_45 ;
V_36 = F_134 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
if ( ! V_279 && V_36 > 0 && V_36 <= V_32 -> V_62 . V_100 ) {
V_284 [ V_33 ] . V_285 = true ;
return 0 ;
}
V_280 = ( T_4 ) V_267 ;
V_44 = F_140 ( V_32 , V_36 , V_280 , & V_171 ) ;
if ( ! V_44 ) {
F_112 ( V_268 , ( T_3 ) V_171 ) ;
V_44 = F_136 ( V_32 , V_33 , V_280 , V_36 , V_171 ) ;
if ( V_44 )
F_138 ( V_32 , V_36 , V_280 ) ;
}
return V_44 ;
}
static int F_60 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 , int V_36 )
{
T_3 V_250 ;
int V_44 ;
if ( V_265 != V_203 )
return - V_45 ;
V_44 = F_8 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_141 ( V_32 , & V_250 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
V_44 = F_77 ( V_32 , V_33 , V_250 , 1 , V_28 , V_36 ) ;
if ( V_44 ) {
F_142 ( V_32 , V_250 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
} else {
F_112 ( V_268 , V_250 ) ;
}
return V_44 ;
}
static int F_143 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
T_3 V_286 ;
int V_44 ;
if ( V_265 != V_203 )
return - V_45 ;
V_44 = F_144 ( V_32 , & V_286 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_77 ( V_32 , V_33 , V_286 , 1 , V_30 , 0 ) ;
if ( V_44 )
F_145 ( V_32 , V_286 ) ;
else
F_112 ( V_268 , V_286 ) ;
return V_44 ;
}
int F_146 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_291 = V_288 -> V_292 ;
switch ( V_288 -> V_293 & 0xFF ) {
case V_20 :
V_44 = F_107 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_24 :
V_44 = F_114 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_23 :
V_44 = F_117 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_21 :
V_44 = F_121 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_22 :
V_44 = F_124 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_25 :
V_44 = F_133 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ,
( V_288 -> V_293 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_139 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ,
( V_288 -> V_293 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_60 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 , 0 ) ;
break;
case V_30 :
V_44 = F_143 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_147 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 )
{
int V_44 ;
int V_35 ;
int V_233 ;
int V_139 ;
switch ( V_265 ) {
case V_203 :
V_233 = F_108 ( & V_267 ) & 0x7fffff ;
V_35 = F_109 ( & V_267 ) ;
V_44 = F_94 ( V_32 , V_33 , V_233 , V_35 , V_20 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_111 ( V_32 , V_233 , V_35 ) ;
break;
case V_271 :
V_139 = F_108 ( & V_267 ) & 0x7fffff ;
V_44 = F_96 ( V_32 , V_33 , V_139 , V_207 ,
NULL , 0 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_106 ( V_32 , V_139 ) )
F_148 ( V_32 , V_139 ) ;
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
if ( F_103 ( V_32 , V_33 , V_139 ) )
V_44 = F_94 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_149 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_44 = - V_45 ;
int V_233 ;
int V_212 ;
if ( V_265 != V_272 )
return V_44 ;
V_233 = F_108 ( & V_267 ) ;
V_212 = F_109 ( & V_267 ) ;
V_44 = F_94 ( V_32 , V_33 , V_233 , 1 , V_24 , V_212 ) ;
if ( ! V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_212 , 0 ) ;
F_116 ( V_32 , V_233 , V_212 ) ;
}
return V_44 ;
}
static int F_150 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 )
{
int V_44 = - V_45 ;
int V_250 ;
int V_193 ;
struct V_215 * V_77 ;
switch ( V_265 ) {
case V_203 :
V_250 = F_108 ( & V_267 ) ;
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_50 ( V_32 , V_33 , V_193 , V_23 , & V_77 ) ;
if ( V_44 )
break;
V_250 = V_77 -> V_214 ;
F_55 ( V_32 , V_33 , V_193 , V_23 ) ;
V_44 = F_94 ( V_32 , V_33 , V_193 , 1 , V_23 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_119 ( V_32 , V_250 ) ;
break;
case V_271 :
V_250 = F_108 ( & V_267 ) ;
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_97 ( V_32 , V_33 , V_193 ,
V_216 , & V_77 ) ;
if ( V_44 )
return V_44 ;
F_151 ( V_32 , V_77 -> V_214 ) ;
F_102 ( V_32 , V_33 , V_23 , V_193 ) ;
return V_44 ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_152 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_258 ;
int V_44 ;
switch ( V_265 ) {
case V_272 :
V_258 = F_108 ( & V_267 ) ;
V_44 = F_94 ( V_32 , V_33 , V_258 , 1 , V_21 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_123 ( V_32 , V_258 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_153 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_273 ;
int V_44 ;
switch ( V_265 ) {
case V_272 :
V_273 = F_108 ( & V_267 ) ;
V_44 = F_94 ( V_32 , V_33 , V_273 , 1 , V_22 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_126 ( V_32 , V_273 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_154 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 , int V_279 )
{
int V_36 ;
int V_44 = 0 ;
switch ( V_265 ) {
case V_272 :
V_36 = ! V_279 ? F_108 ( V_268 ) : V_279 ;
V_36 = F_134 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
F_130 ( V_32 , V_33 , V_267 , V_36 ) ;
F_132 ( V_32 , V_36 , V_267 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_155 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 , int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_283 * V_284 = V_38 -> V_41 . V_42 . V_284 ;
int V_44 = 0 ;
V_36 = F_134 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
switch ( V_265 ) {
case V_272 :
if ( V_284 [ V_33 ] . V_285 )
return 0 ;
if ( ! V_36 )
return - V_45 ;
F_137 ( V_32 , V_33 , V_267 , V_36 ) ;
F_138 ( V_32 , V_36 , V_267 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_156 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_250 ;
int V_44 ;
if ( V_265 != V_203 )
return - V_45 ;
V_250 = F_108 ( & V_267 ) ;
if ( V_250 == F_57 ( V_32 ) )
return 0 ;
V_44 = F_94 ( V_32 , V_33 , V_250 , 1 , V_28 , 0 ) ;
if ( V_44 )
return V_44 ;
F_142 ( V_32 , V_250 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
static int F_157 ( struct V_31 * V_32 , int V_33 , int V_265 , int V_266 ,
T_1 V_267 , T_1 * V_268 )
{
int V_286 ;
int V_44 ;
if ( V_265 != V_203 )
return - V_45 ;
V_286 = F_108 ( & V_267 ) ;
V_44 = F_94 ( V_32 , V_33 , V_286 , 1 , V_30 , 0 ) ;
if ( V_44 )
return V_44 ;
F_145 ( V_32 , V_286 ) ;
return V_44 ;
}
int F_158 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 = - V_45 ;
int V_291 = V_288 -> V_292 ;
switch ( V_288 -> V_293 & 0xFF ) {
case V_20 :
V_44 = F_147 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 ) ;
break;
case V_24 :
V_44 = F_149 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_23 :
V_44 = F_150 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 ) ;
break;
case V_21 :
V_44 = F_152 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_22 :
V_44 = F_153 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_25 :
V_44 = F_154 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ,
( V_288 -> V_293 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_155 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ,
( V_288 -> V_293 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_156 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
break;
case V_30 :
V_44 = F_157 ( V_32 , V_33 , V_288 -> V_292 , V_291 ,
V_288 -> V_267 , & V_288 -> V_268 ) ;
default:
break;
}
return V_44 ;
}
static int F_159 ( struct V_294 * V_77 )
{
return ( F_40 ( V_77 -> V_128 ) >> 9 ) & 1 ;
}
static int F_160 ( struct V_294 * V_77 )
{
return ( int ) F_161 ( V_77 -> V_295 ) & 0xfffffff8 ;
}
static int F_162 ( struct V_294 * V_77 )
{
return F_40 ( V_77 -> V_296 ) ;
}
static T_3 F_163 ( struct V_294 * V_77 )
{
return F_40 ( V_77 -> V_297 ) & 0x00ffffff ;
}
static int F_164 ( struct V_294 * V_77 )
{
return F_40 ( V_77 -> V_297 ) & V_298 ;
}
static int F_165 ( struct V_294 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_299 ;
}
static int F_166 ( struct V_294 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_300 ;
}
static int F_167 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_301 ) & 0xfffffff8 ;
}
static int F_168 ( struct V_302 * V_303 )
{
return F_40 ( V_303 -> V_301 ) & 0xfffffff8 ;
}
static int F_169 ( struct V_122 * V_140 )
{
int V_304 = ( V_140 -> V_305 & 0x3f ) + 12 ;
int V_306 = ( V_140 -> V_307 >> 3 ) & 0xf ;
int V_308 = V_140 -> V_307 & 7 ;
int V_309 = ( V_140 -> V_310 >> 3 ) & 0xf ;
int V_311 = V_140 -> V_310 & 7 ;
int V_72 = ( F_40 ( V_140 -> V_273 ) >> 24 ) & 1 ;
int V_312 = ( F_40 ( V_140 -> V_128 ) >> 13 ) & 1 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
int V_313 = ( V_127 == V_134 ) ? 1 : 0 ;
int V_314 ;
int V_315 ;
int V_316 ;
int V_317 ;
int V_318 = ( F_40 ( V_140 -> V_319 ) >> 6 ) & 0x3f ;
V_314 = 1 << ( V_306 + V_308 + 4 ) ;
V_315 = ( V_72 | V_312 | V_313 ) ? 0 : ( 1 << ( V_309 + V_311 + 4 ) ) ;
V_317 = V_314 + V_315 ;
V_316 =
F_170 ( ( V_317 + ( V_318 << 6 ) ) >>
V_304 ) ;
return V_316 ;
}
static int F_171 ( struct V_31 * V_32 , int V_33 , int V_320 ,
int V_321 , struct V_213 * V_75 )
{
int V_322 = V_75 -> V_198 . V_7 ;
int V_323 = ( 1 << V_75 -> V_212 ) ;
if ( V_320 < V_322 || V_320 + V_321 > V_322 + V_323 )
return - V_190 ;
return 0 ;
}
int F_172 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_250 = V_288 -> V_293 ;
struct V_213 * V_75 ;
struct V_215 * V_77 ;
int V_324 = F_160 ( V_116 -> V_118 ) / V_32 -> V_62 . V_325 ;
int V_326 ;
int V_193 ;
T_3 V_327 ;
int V_328 ;
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_97 ( V_32 , V_33 , V_193 , V_253 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_166 ( V_116 -> V_118 ) ) {
V_44 = - V_190 ;
goto V_329;
}
V_327 = F_163 ( V_116 -> V_118 ) ;
V_328 = ( V_327 >> 17 ) & 0x7f ;
if ( V_328 != 0 && -- V_328 != V_33 ) {
V_44 = - V_190 ;
goto V_329;
}
if ( F_164 ( V_116 -> V_118 ) ) {
if ( F_165 ( V_116 -> V_118 ) ) {
V_44 = - V_190 ;
goto V_329;
}
if ( ! F_166 ( V_116 -> V_118 ) ) {
V_44 = - V_190 ;
goto V_329;
}
}
V_326 = F_159 ( V_116 -> V_118 ) ;
if ( ! V_326 ) {
V_44 = F_50 ( V_32 , V_33 , V_324 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_329;
V_44 = F_171 ( V_32 , V_33 , V_324 ,
F_162 ( V_116 -> V_118 ) , V_75 ) ;
if ( V_44 )
goto V_330;
V_77 -> V_75 = V_75 ;
}
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_330;
if ( ! V_326 ) {
F_174 ( & V_75 -> V_211 ) ;
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
}
F_102 ( V_32 , V_33 , V_23 , V_193 ) ;
return 0 ;
V_330:
if ( ! V_326 )
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
V_329:
F_101 ( V_32 , V_33 , V_23 , V_193 ) ;
return V_44 ;
}
int F_175 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_250 = V_288 -> V_293 ;
struct V_215 * V_77 ;
int V_193 ;
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_97 ( V_32 , V_33 , V_193 , V_252 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_329;
if ( V_77 -> V_75 )
F_176 ( & V_77 -> V_75 -> V_211 ) ;
F_102 ( V_32 , V_33 , V_23 , V_193 ) ;
return 0 ;
V_329:
F_101 ( V_32 , V_33 , V_23 , V_193 ) ;
return V_44 ;
}
int F_177 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_250 = V_288 -> V_293 ;
struct V_215 * V_77 ;
int V_193 ;
V_193 = V_250 & F_48 ( V_32 ) ;
V_44 = F_50 ( V_32 , V_33 , V_193 , V_23 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( V_77 -> V_198 . V_191 == V_252 ) {
struct V_294 * V_331 = F_178 (
& V_37 ( V_32 ) -> V_332 . V_333 ,
V_77 -> V_214 , NULL ) ;
if ( NULL == V_331 || NULL == V_289 -> V_118 ) {
V_44 = - V_45 ;
goto V_59;
}
memcpy ( V_289 -> V_118 , V_331 , sizeof( * V_331 ) ) ;
V_44 = 0 ;
} else if ( V_77 -> V_198 . V_191 == V_253 ) {
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
} else {
V_44 = - V_188 ;
goto V_59;
}
V_59:
F_55 ( V_32 , V_33 , V_193 , V_23 ) ;
return V_44 ;
}
static int F_179 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_334 ) & 0xffffff ;
}
static int F_180 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_335 ) & 0xffffff ;
}
static T_3 F_181 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_273 ) & 0x1ffffff ;
}
static void F_182 ( struct V_31 * V_32 , struct V_287 * V_288 ,
struct V_122 * V_336 )
{
T_3 V_139 = V_288 -> V_293 & 0xffffff ;
T_3 V_337 = 0 ;
if ( F_183 ( V_32 , V_139 , & V_337 ) )
return;
V_336 -> V_337 = F_46 ( V_337 ) ;
}
int F_184 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_139 = V_288 -> V_293 & 0x7fffff ;
struct V_213 * V_75 ;
struct V_206 * V_66 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_324 = F_167 ( V_140 ) / V_32 -> V_62 . V_325 ;
int V_338 = F_169 ( V_140 ) ;
struct V_219 * V_339 ;
struct V_219 * V_340 ;
int V_341 = F_179 ( V_140 ) ;
int V_342 = F_180 ( V_140 ) ;
T_3 V_273 = F_181 ( V_140 ) & 0xffffff ;
int V_343 = ( F_181 ( V_140 ) >> 24 ) & 1 ;
struct V_221 * V_72 ;
int V_208 = F_40 ( V_140 -> V_208 ) & 0xffffff ;
V_44 = F_185 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_96 ( V_32 , V_33 , V_139 , V_248 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_66 -> V_208 = V_208 ;
V_66 -> V_131 = 0 ;
V_66 -> V_152 = 0 ;
V_66 -> V_157 = 0 ;
V_66 -> V_169 = 0 ;
V_66 -> V_344 = 0 ;
V_66 -> V_171 = 0 ;
V_66 -> V_176 = 0 ;
V_66 -> V_345 = F_40 ( V_140 -> V_128 ) ;
V_44 = F_50 ( V_32 , V_33 , V_324 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_329;
V_44 = F_171 ( V_32 , V_33 , V_324 , V_338 , V_75 ) ;
if ( V_44 )
goto V_346;
V_44 = F_50 ( V_32 , V_33 , V_341 , V_21 , & V_339 ) ;
if ( V_44 )
goto V_346;
if ( V_342 != V_341 ) {
V_44 = F_50 ( V_32 , V_33 , V_342 , V_21 , & V_340 ) ;
if ( V_44 )
goto V_347;
} else
V_340 = V_339 ;
if ( V_343 ) {
V_44 = F_50 ( V_32 , V_33 , V_273 , V_22 , & V_72 ) ;
if ( V_44 )
goto V_348;
}
F_182 ( V_32 , V_288 , V_140 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_349;
F_174 ( & V_75 -> V_211 ) ;
V_66 -> V_75 = V_75 ;
F_174 ( & V_339 -> V_211 ) ;
V_66 -> V_339 = V_339 ;
F_174 ( & V_340 -> V_211 ) ;
V_66 -> V_340 = V_340 ;
if ( V_342 != V_341 )
F_55 ( V_32 , V_33 , V_342 , V_21 ) ;
if ( V_343 ) {
F_174 ( & V_72 -> V_211 ) ;
F_55 ( V_32 , V_33 , V_273 , V_22 ) ;
V_66 -> V_72 = V_72 ;
}
F_55 ( V_32 , V_33 , V_341 , V_21 ) ;
F_55 ( V_32 , V_33 , V_324 , V_24 ) ;
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_349:
if ( V_343 )
F_55 ( V_32 , V_33 , V_273 , V_22 ) ;
V_348:
if ( V_342 != V_341 )
F_55 ( V_32 , V_33 , V_342 , V_21 ) ;
V_347:
F_55 ( V_32 , V_33 , V_341 , V_21 ) ;
V_346:
F_55 ( V_32 , V_33 , V_324 , V_24 ) ;
V_329:
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static int F_186 ( struct V_350 * V_351 )
{
return F_40 ( V_351 -> V_301 ) & 0xfffffff8 ;
}
static int F_187 ( struct V_350 * V_351 )
{
int V_352 = V_351 -> V_352 & 0x1f ;
int V_304 = ( V_351 -> V_305 & 0x3f ) + 12 ;
if ( V_352 + 5 < V_304 )
return 1 ;
return 1 << ( V_352 + 5 - V_304 ) ;
}
static int F_188 ( struct V_353 * V_354 )
{
return F_40 ( V_354 -> V_301 ) & 0xfffffff8 ;
}
static int F_189 ( struct V_353 * V_354 )
{
int V_355 = ( F_40 ( V_354 -> V_356 ) >> 24 ) & 0x1f ;
int V_304 = ( V_354 -> V_305 & 0x3f ) + 12 ;
if ( V_355 + 5 < V_304 )
return 1 ;
return 1 << ( V_355 + 5 - V_304 ) ;
}
int F_190 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_357 = V_288 -> V_293 ;
int V_7 = ( V_33 << 10 ) | V_357 ;
struct V_350 * V_351 = V_116 -> V_118 ;
int V_324 = F_186 ( V_351 ) / V_32 -> V_62 . V_325 ;
int V_338 = F_187 ( V_351 ) ;
struct V_217 * V_255 ;
struct V_213 * V_75 ;
V_44 = F_77 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_98 ( V_32 , V_33 , V_7 , V_257 , & V_255 ) ;
if ( V_44 )
goto V_358;
V_44 = F_50 ( V_32 , V_33 , V_324 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_359;
V_44 = F_171 ( V_32 , V_33 , V_324 , V_338 , V_75 ) ;
if ( V_44 )
goto V_360;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_360;
F_174 ( & V_75 -> V_211 ) ;
V_255 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
F_102 ( V_32 , V_33 , V_27 , V_7 ) ;
return 0 ;
V_360:
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
V_359:
F_101 ( V_32 , V_33 , V_27 , V_7 ) ;
V_358:
F_94 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return V_44 ;
}
int F_191 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
T_2 V_361 = V_288 -> V_292 ;
if ( V_361 != 1 )
return - V_190 ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
return V_44 ;
}
static int F_192 ( struct V_31 * V_32 , int V_33 , int V_320 ,
int V_362 , struct V_213 * * V_11 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_213 * V_75 ;
int V_44 = - V_45 ;
F_51 ( F_52 ( V_32 ) ) ;
F_59 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_171 ( V_32 , V_33 , V_320 , V_362 , V_75 ) ) {
* V_11 = V_75 ;
V_75 -> V_198 . V_191 = V_75 -> V_198 . V_2 ;
V_75 -> V_198 . V_2 = V_3 ;
V_44 = 0 ;
break;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_193 ( struct V_31 * V_32 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
enum V_363 V_364 , T_2 V_33 )
{
T_3 V_143 ;
T_3 V_139 ;
struct V_122 * V_123 ;
enum V_124 V_125 ;
int V_36 ;
int V_365 ;
V_123 = V_116 -> V_118 + 8 ;
V_143 = ( F_40 ( V_123 -> V_128 ) >> 16 ) & 0xff ;
V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
if ( V_33 != F_14 ( V_32 ) ) {
V_123 -> V_319 &= ~ V_366 ;
if ( V_123 -> V_367 )
return - V_190 ;
}
switch ( V_143 ) {
case V_133 :
case V_134 :
case V_135 :
switch ( V_364 ) {
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
if ( V_33 != F_14 ( V_32 ) )
if ( V_125 & V_136 ) {
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_373 [ V_36 ] != V_374 )
V_365 = F_194 ( V_32 , V_33 , V_36 ) ;
else
V_365 = 1 ;
if ( V_123 -> V_130 . V_132 >= V_365 )
return - V_45 ;
}
if ( V_125 & V_137 ) {
V_36 = ( V_123 -> V_138 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_373 [ V_36 ] != V_374 )
V_365 = F_194 ( V_32 , V_33 , V_36 ) ;
else
V_365 = 1 ;
if ( V_123 -> V_138 . V_132 >= V_365 )
return - V_45 ;
}
break;
default:
break;
}
break;
case V_148 :
V_139 = V_288 -> V_293 & 0x7fffff ;
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_364 == V_368 &&
V_33 != F_14 ( V_32 ) &&
F_45 ( V_32 , V_139 ) &&
! F_195 ( V_32 , V_33 , V_36 ) ) {
F_61 ( V_32 , L_26 ,
V_205 , V_33 , V_36 ) ;
return - V_190 ;
}
break;
default:
break;
}
return 0 ;
}
int F_196 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
struct V_375 V_75 ;
T_5 * V_376 = V_116 -> V_118 ;
T_1 * V_377 = ( T_1 * ) V_376 ;
int V_83 ;
struct V_213 * V_378 = NULL ;
int V_320 = F_161 ( V_376 [ 0 ] ) ;
int V_379 = V_288 -> V_293 ;
int V_44 ;
V_44 = F_192 ( V_32 , V_33 , V_320 , V_379 , & V_378 ) ;
if ( V_44 )
return V_44 ;
V_75 . V_380 = 0 ;
V_75 . V_212 = 0 ;
V_75 . V_304 = 0 ;
for ( V_83 = 0 ; V_83 < V_379 ; ++ V_83 )
V_377 [ V_83 + 2 ] = ( F_161 ( V_376 [ V_83 + 2 ] ) & ~ 1ULL ) ;
V_44 = F_197 ( V_32 , & V_75 , F_161 ( V_376 [ 0 ] ) , V_379 ,
( ( T_1 * ) V_376 + 2 ) ) ;
if ( V_378 )
F_55 ( V_32 , V_33 , V_378 -> V_198 . V_7 , V_24 ) ;
return V_44 ;
}
int F_198 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_357 = V_288 -> V_293 ;
int V_7 = V_357 | ( V_33 << 10 ) ;
struct V_217 * V_255 ;
int V_44 ;
V_44 = F_98 ( V_32 , V_33 , V_7 , V_218 , & V_255 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_255 -> V_75 -> V_198 . V_7 , V_24 , NULL ) ;
if ( V_44 )
goto V_329;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_330;
F_176 ( & V_255 -> V_75 -> V_211 ) ;
F_55 ( V_32 , V_33 , V_255 -> V_75 -> V_198 . V_7 , V_24 ) ;
F_102 ( V_32 , V_33 , V_27 , V_7 ) ;
F_94 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return 0 ;
V_330:
F_55 ( V_32 , V_33 , V_255 -> V_75 -> V_198 . V_7 , V_24 ) ;
V_329:
F_101 ( V_32 , V_33 , V_27 , V_7 ) ;
return V_44 ;
}
int F_199 ( struct V_31 * V_32 , int V_33 , struct V_381 * V_382 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_383 * V_384 ;
struct V_115 * V_385 ;
T_3 V_293 = 0 ;
int V_44 ;
int V_7 ;
struct V_217 * V_386 ;
if ( ! V_38 -> V_41 . V_42 . V_284 )
return - V_45 ;
if ( V_33 < 0 || V_33 > V_32 -> V_51 -> V_52 ||
V_33 == V_32 -> V_62 . V_113 ||
! V_38 -> V_41 . V_42 . V_284 [ V_33 ] . V_387 )
return 0 ;
V_384 = & V_38 -> V_41 . V_42 . V_284 [ V_33 ] . V_384 [ V_382 -> type ] ;
if ( V_384 -> V_357 < 0 )
return 0 ;
F_35 ( & V_38 -> V_41 . V_42 . V_388 [ V_33 ] ) ;
V_7 = ( V_33 << 10 ) | V_384 -> V_357 ;
V_44 = F_50 ( V_32 , V_33 , V_7 , V_27 , & V_386 ) ;
if ( V_44 )
goto V_389;
if ( V_386 -> V_198 . V_191 != V_257 ) {
V_44 = - V_45 ;
goto V_390;
}
V_385 = F_200 ( V_32 ) ;
if ( F_201 ( V_385 ) ) {
V_44 = F_202 ( V_385 ) ;
goto V_390;
}
if ( V_382 -> type == V_391 ) {
++ V_384 -> V_392 ;
V_382 -> V_393 . V_266 . V_392 = F_203 ( V_384 -> V_392 ) ;
}
memcpy ( V_385 -> V_118 , ( T_2 * ) V_382 , 28 ) ;
V_293 = ( V_33 & 0xff ) | ( ( V_384 -> V_357 & 0x3ff ) << 16 ) ;
V_44 = F_204 ( V_32 , V_385 -> V_394 , V_293 , 0 ,
V_395 , V_396 ,
V_397 ) ;
F_55 ( V_32 , V_33 , V_7 , V_27 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_388 [ V_33 ] ) ;
F_205 ( V_32 , V_385 ) ;
return V_44 ;
V_390:
F_55 ( V_32 , V_33 , V_7 , V_27 ) ;
V_389:
F_37 ( & V_38 -> V_41 . V_42 . V_388 [ V_33 ] ) ;
return V_44 ;
}
int F_206 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_357 = V_288 -> V_293 ;
int V_7 = V_357 | ( V_33 << 10 ) ;
struct V_217 * V_255 ;
int V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_7 , V_27 , & V_255 ) ;
if ( V_44 )
return V_44 ;
if ( V_255 -> V_198 . V_191 != V_257 ) {
V_44 = - V_45 ;
goto V_330;
}
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_330:
F_55 ( V_32 , V_33 , V_7 , V_27 ) ;
return V_44 ;
}
int F_207 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_258 = V_288 -> V_293 ;
struct V_353 * V_354 = V_116 -> V_118 ;
int V_324 = F_188 ( V_354 ) / V_32 -> V_62 . V_325 ;
struct V_219 * V_69 = NULL ;
struct V_213 * V_75 ;
V_44 = F_99 ( V_32 , V_33 , V_258 , V_260 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_324 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_359;
V_44 = F_171 ( V_32 , V_33 , V_324 , F_189 ( V_354 ) , V_75 ) ;
if ( V_44 )
goto V_360;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_360;
F_174 ( & V_75 -> V_211 ) ;
V_69 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
F_102 ( V_32 , V_33 , V_21 , V_258 ) ;
return 0 ;
V_360:
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
V_359:
F_101 ( V_32 , V_33 , V_21 , V_258 ) ;
return V_44 ;
}
int F_208 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_258 = V_288 -> V_293 ;
struct V_219 * V_69 = NULL ;
V_44 = F_99 ( V_32 , V_33 , V_258 , V_220 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_359;
F_176 ( & V_69 -> V_75 -> V_211 ) ;
F_102 ( V_32 , V_33 , V_21 , V_258 ) ;
return 0 ;
V_359:
F_101 ( V_32 , V_33 , V_21 , V_258 ) ;
return V_44 ;
}
int F_209 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_258 = V_288 -> V_293 ;
struct V_219 * V_69 ;
int V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_258 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_198 . V_191 != V_260 )
goto V_330;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_330:
F_55 ( V_32 , V_33 , V_258 , V_21 ) ;
return V_44 ;
}
static int F_210 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 ,
struct V_219 * V_69 )
{
int V_44 ;
struct V_213 * V_398 ;
struct V_213 * V_75 ;
struct V_353 * V_354 = V_116 -> V_118 ;
int V_324 = F_188 ( V_354 ) / V_32 -> V_62 . V_325 ;
V_44 = F_50 ( V_32 , V_33 , V_69 -> V_75 -> V_198 . V_7 , V_24 , & V_398 ) ;
if ( V_44 )
return V_44 ;
if ( V_398 != V_69 -> V_75 ) {
V_44 = - V_45 ;
goto V_330;
}
V_44 = F_50 ( V_32 , V_33 , V_324 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_330;
V_44 = F_171 ( V_32 , V_33 , V_324 , F_189 ( V_354 ) , V_75 ) ;
if ( V_44 )
goto V_399;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_399;
F_176 ( & V_398 -> V_211 ) ;
F_55 ( V_32 , V_33 , V_398 -> V_198 . V_7 , V_24 ) ;
F_174 ( & V_75 -> V_211 ) ;
V_69 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
return 0 ;
V_399:
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
V_330:
F_55 ( V_32 , V_33 , V_398 -> V_198 . V_7 , V_24 ) ;
return V_44 ;
}
int F_211 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_258 = V_288 -> V_293 ;
struct V_219 * V_69 ;
int V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_258 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_198 . V_191 != V_260 )
goto V_330;
if ( V_288 -> V_292 == 0 ) {
V_44 = F_210 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 , V_69 ) ;
goto V_330;
}
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_330:
F_55 ( V_32 , V_33 , V_258 , V_21 ) ;
return V_44 ;
}
static int F_212 ( struct V_302 * V_303 )
{
int V_400 = ( F_40 ( V_303 -> V_401 ) >> 24 ) & 0xf ;
int V_311 = V_303 -> V_402 & 7 ;
int V_304 = ( V_303 -> V_305 & 0x3f ) + 12 ;
if ( V_400 + V_311 + 4 < V_304 )
return 1 ;
return 1 << ( V_400 + V_311 + 4 - V_304 ) ;
}
int F_213 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_273 = V_288 -> V_293 ;
struct V_213 * V_75 ;
struct V_221 * V_72 = NULL ;
struct V_302 * V_303 = V_116 -> V_118 ;
int V_324 = F_168 ( V_303 ) / V_32 -> V_62 . V_325 ;
if ( V_273 != ( F_40 ( V_303 -> V_401 ) & 0xffffff ) )
return - V_45 ;
V_44 = F_100 ( V_32 , V_33 , V_273 , V_262 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_324 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_329;
V_44 = F_171 ( V_32 , V_33 , V_324 , F_212 ( V_303 ) ,
V_75 ) ;
if ( V_44 )
goto V_346;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_346;
F_174 ( & V_75 -> V_211 ) ;
V_72 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
F_102 ( V_32 , V_33 , V_22 , V_273 ) ;
return 0 ;
V_346:
F_55 ( V_32 , V_33 , V_75 -> V_198 . V_7 , V_24 ) ;
V_329:
F_101 ( V_32 , V_33 , V_22 , V_273 ) ;
return V_44 ;
}
int F_214 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_273 = V_288 -> V_293 ;
struct V_221 * V_72 = NULL ;
V_44 = F_100 ( V_32 , V_33 , V_273 , V_222 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_329;
F_176 ( & V_72 -> V_75 -> V_211 ) ;
if ( V_72 -> V_69 )
F_176 ( & V_72 -> V_69 -> V_211 ) ;
F_102 ( V_32 , V_33 , V_22 , V_273 ) ;
return 0 ;
V_329:
F_101 ( V_32 , V_33 , V_22 , V_273 ) ;
return V_44 ;
}
int F_215 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_273 = V_288 -> V_293 ;
struct V_221 * V_72 ;
V_44 = F_50 ( V_32 , V_33 , V_273 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_198 . V_191 != V_262 ) {
V_44 = - V_188 ;
goto V_59;
}
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_59:
F_55 ( V_32 , V_33 , V_273 , V_22 ) ;
return V_44 ;
}
int F_216 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_273 = V_288 -> V_293 ;
struct V_221 * V_72 ;
V_44 = F_50 ( V_32 , V_33 , V_273 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_198 . V_191 != V_262 ) {
V_44 = - V_188 ;
goto V_59;
}
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_59:
F_55 ( V_32 , V_33 , V_273 , V_22 ) ;
return V_44 ;
}
int F_217 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_139 = V_288 -> V_293 & 0x7fffff ;
struct V_206 * V_66 ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_198 . V_191 != V_248 ) {
V_44 = - V_188 ;
goto V_59;
}
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_59:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_218 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
struct V_122 * V_336 = V_116 -> V_118 + 8 ;
F_182 ( V_32 , V_288 , V_336 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_217 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
}
static int F_185 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
enum V_124 V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
T_2 V_403 ;
int V_36 = F_134 (
V_32 , V_33 , ( V_140 -> V_130 . V_131 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_403 = ( V_140 -> V_130 . V_131 & ~ ( 1 << 6 ) ) |
( ( V_36 & 1 ) << 6 ) ;
if ( V_125 & ( V_136 | V_404 ) ||
V_140 -> V_130 . V_131 || F_41 ( V_32 , V_36 + 1 ) ) {
V_140 -> V_130 . V_131 = V_403 ;
}
if ( V_125 & V_137 ) {
V_36 = F_134 (
V_32 , V_33 , ( V_140 -> V_138 . V_131 >> 6 & 1 )
+ 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_140 -> V_138 . V_131 =
( V_140 -> V_138 . V_131 & ~ ( 1 << 6 ) ) |
( V_36 & 1 ) << 6 ;
}
return 0 ;
}
static int F_219 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
T_1 V_275 ;
int V_36 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
T_2 V_117 = * ( T_2 * ) ( V_116 -> V_118 + 64 ) ;
T_2 V_405 ;
V_36 = ( V_117 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) && ( V_127 != V_148 ) ) {
V_405 = V_140 -> V_130 . V_183 & 0x7f ;
if ( F_127 ( V_32 , V_33 , V_36 , V_405 , & V_275 ) )
return - V_192 ;
}
return 0 ;
}
int F_220 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_139 = V_288 -> V_293 & 0x7fffff ;
struct V_206 * V_66 ;
T_2 V_406 ;
V_126 V_407 = V_140 -> V_152 ;
T_2 V_408 = V_140 -> V_130 . V_157 ;
T_2 V_409 = V_140 -> V_130 . V_169 ;
T_2 V_410 = V_140 -> V_130 . V_173 ;
T_2 V_411 = V_140 -> V_130 . V_171 ;
T_2 V_412 = V_140 -> V_130 . V_176 ;
V_44 = F_185 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_193 ( V_32 , V_288 , V_116 , V_368 , V_33 ) ;
if ( V_44 )
return V_44 ;
if ( F_219 ( V_32 , V_33 , V_140 , V_116 ) )
return - V_45 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_182 ( V_32 , V_288 , V_140 ) ;
V_406 = V_140 -> V_130 . V_131 ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_198 . V_191 != V_248 ) {
V_44 = - V_188 ;
goto V_59;
}
V_44 = F_43 ( V_32 , V_116 , V_33 , V_139 ) ;
if ( V_44 )
goto V_59;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
V_59:
if ( ! V_44 ) {
V_66 -> V_131 = V_406 ;
V_66 -> V_152 = V_407 ;
V_66 -> V_157 = V_408 ;
V_66 -> V_169 = V_409 ;
V_66 -> V_344 = V_410 ;
V_66 -> V_171 = V_411 ;
V_66 -> V_176 = V_412 ;
}
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_221 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
struct V_122 * V_336 = V_116 -> V_118 + 8 ;
V_44 = F_185 ( V_32 , V_33 , V_336 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_193 ( V_32 , V_288 , V_116 , V_369 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_182 ( V_32 , V_288 , V_336 ) ;
return F_217 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
}
int F_222 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
struct V_122 * V_336 = V_116 -> V_118 + 8 ;
V_44 = F_185 ( V_32 , V_33 , V_336 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_193 ( V_32 , V_288 , V_116 , V_370 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_182 ( V_32 , V_288 , V_336 ) ;
return F_217 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
}
int F_223 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
struct V_122 * V_336 = V_116 -> V_118 + 8 ;
int V_44 = F_185 ( V_32 , V_33 , V_336 , V_116 ) ;
if ( V_44 )
return V_44 ;
F_182 ( V_32 , V_288 , V_336 ) ;
return F_217 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
}
int F_224 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
struct V_122 * V_336 = V_116 -> V_118 + 8 ;
V_44 = F_185 ( V_32 , V_33 , V_336 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_193 ( V_32 , V_288 , V_116 , V_371 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_182 ( V_32 , V_288 , V_336 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_217 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
}
int F_225 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
struct V_122 * V_336 = V_116 -> V_118 + 8 ;
V_44 = F_185 ( V_32 , V_33 , V_336 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_193 ( V_32 , V_288 , V_116 , V_372 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_182 ( V_32 , V_288 , V_336 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_217 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
}
int F_226 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_139 = V_288 -> V_293 & 0x7fffff ;
struct V_206 * V_66 ;
V_44 = F_96 ( V_32 , V_33 , V_139 , V_247 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
if ( V_44 )
goto V_329;
F_176 ( & V_66 -> V_75 -> V_211 ) ;
F_176 ( & V_66 -> V_339 -> V_211 ) ;
F_176 ( & V_66 -> V_340 -> V_211 ) ;
if ( V_66 -> V_72 )
F_176 ( & V_66 -> V_72 -> V_211 ) ;
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_329:
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static struct V_413 * F_227 ( struct V_31 * V_32 , int V_33 ,
struct V_206 * V_414 , T_2 * V_415 )
{
struct V_413 * V_11 ;
F_59 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_415 , V_415 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_228 ( struct V_31 * V_32 , int V_33 , struct V_206 * V_414 ,
T_2 * V_415 , enum V_416 V_417 ,
enum V_418 V_419 , T_1 V_420 )
{
struct V_413 * V_11 ;
int V_44 ;
V_11 = F_21 ( sizeof *V_11 , V_89 ) ;
if ( ! V_11 )
return - V_90 ;
F_51 ( & V_414 -> V_210 ) ;
if ( F_227 ( V_32 , V_33 , V_414 , V_415 ) ) {
F_31 ( V_11 ) ;
V_44 = - V_17 ;
} else {
memcpy ( V_11 -> V_415 , V_415 , 16 ) ;
V_11 -> V_417 = V_417 ;
V_11 -> V_419 = V_419 ;
V_11 -> V_420 = V_420 ;
F_78 ( & V_11 -> V_236 , & V_414 -> V_209 ) ;
V_44 = 0 ;
}
F_53 ( & V_414 -> V_210 ) ;
return V_44 ;
}
static int F_229 ( struct V_31 * V_32 , int V_33 , struct V_206 * V_414 ,
T_2 * V_415 , enum V_416 V_417 ,
enum V_418 V_419 , T_1 * V_420 )
{
struct V_413 * V_11 ;
int V_44 ;
F_51 ( & V_414 -> V_210 ) ;
V_11 = F_227 ( V_32 , V_33 , V_414 , V_415 ) ;
if ( ! V_11 || V_11 -> V_417 != V_417 || V_11 -> V_419 != V_419 )
V_44 = - V_45 ;
else {
* V_420 = V_11 -> V_420 ;
F_95 ( & V_11 -> V_236 ) ;
F_31 ( V_11 ) ;
V_44 = 0 ;
}
F_53 ( & V_414 -> V_210 ) ;
return V_44 ;
}
static int F_230 ( struct V_31 * V_32 , int V_33 , struct V_421 * V_66 ,
T_2 V_415 [ 16 ] , int V_422 , enum V_416 V_417 ,
enum V_418 type , T_1 * V_420 )
{
switch ( V_32 -> V_62 . V_423 ) {
case V_424 : {
int V_36 = F_134 ( V_32 , V_33 , V_415 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return F_231 ( V_32 , V_66 , V_415 , V_36 ,
V_422 , V_417 ,
V_420 ) ;
}
case V_425 :
if ( V_417 == V_426 ) {
int V_36 = F_134 ( V_32 , V_33 , V_415 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
V_415 [ 5 ] = V_36 ;
}
return F_232 ( V_32 , V_66 , V_415 ,
V_422 , V_417 , type ) ;
default:
return - V_45 ;
}
}
static int F_233 ( struct V_31 * V_32 , struct V_421 * V_66 ,
T_2 V_415 [ 16 ] , enum V_416 V_417 ,
enum V_418 type , T_1 V_420 )
{
switch ( V_32 -> V_62 . V_423 ) {
case V_424 :
return F_234 ( V_32 , V_420 ) ;
case V_425 :
return F_235 ( V_32 , V_66 , V_415 , V_417 , type ) ;
default:
return - V_45 ;
}
}
static int F_236 ( struct V_31 * V_32 , int V_33 ,
T_2 * V_415 , enum V_416 V_417 )
{
int V_427 ;
if ( V_417 != V_426 )
return 0 ;
if ( V_32 -> V_62 . V_423 == V_425 ||
V_32 -> V_62 . V_423 == V_424 ) {
V_427 = F_134 ( V_32 , V_33 , V_415 [ 5 ] ) ;
if ( V_427 < 0 )
return - V_45 ;
V_415 [ 5 ] = V_427 ;
}
return 0 ;
}
int F_237 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
struct V_421 V_66 ;
T_2 * V_415 = V_116 -> V_118 ;
enum V_416 V_417 = ( V_288 -> V_293 >> 28 ) & 0x7 ;
int V_44 ;
int V_139 ;
struct V_206 * V_414 ;
T_1 V_420 = 0 ;
int V_428 = V_288 -> V_292 ;
int V_422 = V_288 -> V_293 >> 31 ;
T_2 V_429 = 2 ;
enum V_418 type = ( V_415 [ 7 ] & V_429 ) >> 1 ;
V_139 = V_288 -> V_293 & 0xffffff ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_414 ) ;
if ( V_44 )
return V_44 ;
V_66 . V_139 = V_139 ;
if ( V_428 ) {
V_44 = F_230 ( V_32 , V_33 , & V_66 , V_415 , V_422 , V_417 ,
type , & V_420 ) ;
if ( V_44 ) {
F_73 ( L_27 , V_139 ) ;
goto V_330;
}
V_44 = F_228 ( V_32 , V_33 , V_414 , V_415 , V_417 , type , V_420 ) ;
if ( V_44 )
goto V_430;
} else {
V_44 = F_236 ( V_32 , V_33 , V_415 , V_417 ) ;
if ( V_44 )
goto V_330;
V_44 = F_229 ( V_32 , V_33 , V_414 , V_415 , V_417 , type , & V_420 ) ;
if ( V_44 )
goto V_330;
V_44 = F_233 ( V_32 , & V_66 , V_415 , V_417 , type , V_420 ) ;
if ( V_44 )
F_73 ( L_28 ,
V_139 , V_420 ) ;
}
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
V_430:
F_233 ( V_32 , & V_66 , V_415 , V_417 , type , V_420 ) ;
V_330:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static int F_238 ( int V_33 , struct V_431 * V_432 ,
struct V_276 * V_433 )
{
struct V_278 * V_11 , * V_201 ;
T_5 V_434 ;
if ( ! F_239 ( V_432 -> V_435 . V_436 ) &&
! F_240 ( V_432 -> V_435 . V_436 ) ) {
F_128 (res, tmp, rlist, list) {
V_434 = F_241 ( V_11 -> V_275 << 16 ) ;
if ( F_242 ( ( T_2 * ) & V_434 , V_432 -> V_435 . V_436 ) )
return 0 ;
}
F_73 ( L_29 ,
V_432 -> V_435 . V_436 , V_33 ) ;
return - V_45 ;
}
return 0 ;
}
static void F_243 ( struct V_437 * V_438 ,
struct V_431 * V_432 )
{
if ( F_239 ( V_432 -> V_435 . V_436 ) ||
F_240 ( V_432 -> V_435 . V_436 ) ) {
struct V_439 * V_435 =
(struct V_439 * ) V_432 ;
struct V_431 * V_440 = (struct V_431 * ) ( V_435 + 1 ) ;
bool V_441 = V_440 -> V_321 == 0 && V_440 -> V_193 == 0 &&
V_440 -> V_442 == 0 ;
if ( V_441 )
V_438 -> V_443 = F_203 ( V_444 ) ;
}
}
static int F_244 ( struct V_31 * V_32 , int V_33 ,
struct V_115 * V_116 ,
struct V_276 * V_433 , int V_445 )
{
struct V_278 * V_11 , * V_201 ;
T_2 V_36 ;
struct V_437 * V_438 ;
struct V_439 * V_432 ;
struct V_446 * V_447 ;
struct V_448 * V_449 ;
T_5 V_434 = 0 ;
T_5 V_450 = F_241 ( V_451 << 16 ) ;
V_438 = (struct V_437 * ) V_116 -> V_118 ;
V_36 = V_438 -> V_36 ;
V_432 = (struct V_439 * ) ( V_438 + 1 ) ;
switch ( V_445 ) {
case V_452 :
V_447 =
(struct V_446 * ) ( V_432 + 1 ) ;
memmove ( V_447 , V_432 ,
sizeof( * V_447 ) + sizeof( * V_449 ) ) ;
break;
case V_453 :
case V_454 :
V_449 = (struct V_448 * )
( V_432 + 1 ) ;
memmove ( V_449 , V_432 , sizeof( * V_449 ) ) ;
break;
default:
return - V_45 ;
}
F_128 (res, tmp, rlist, list) {
if ( V_36 == V_11 -> V_36 ) {
V_434 = F_241 ( V_11 -> V_275 << 16 ) ;
break;
}
}
if ( ! V_434 ) {
F_73 ( L_30 ,
V_36 ) ;
return - V_45 ;
}
memset ( V_432 , 0 , sizeof( * V_432 ) ) ;
V_432 -> V_321 = sizeof( * V_432 ) >> 2 ;
V_432 -> V_193 = F_203 ( V_455 [ V_456 ] ) ;
memcpy ( V_432 -> V_436 , & V_434 , V_457 ) ;
memcpy ( V_432 -> V_458 , & V_450 , V_457 ) ;
return 0 ;
}
int F_245 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_459 )
{
int V_44 ;
T_3 V_139 = V_288 -> V_293 & 0xffffff ;
struct V_206 * V_414 ;
T_1 V_275 ;
unsigned V_36 ;
T_1 V_460 ;
struct V_461 * V_266 ;
int V_274 ;
V_266 = (struct V_461 * ) V_116 -> V_118 ;
V_460 = F_161 ( V_266 -> V_462 ) ;
if ( V_266 -> V_463 || V_266 -> V_464 ||
( V_460 & ~ V_465 ) )
return - V_190 ;
if ( ( V_460 &
( 1ULL << V_466 ) ) &&
! ( V_32 -> V_62 . V_161 &
V_467 ) ) {
F_10 ( V_32 ,
L_31 ,
V_33 ) ;
return - V_468 ;
}
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_414 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_32 , V_139 , V_33 ) ;
return V_44 ;
}
V_36 = ( V_414 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_460 & ( 1ULL << V_469 ) ) {
V_274 = V_266 -> V_470 . V_130 . V_183 ;
V_44 = F_127 ( V_32 , V_33 , V_36 ,
V_274 , & V_275 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_33 ,
V_139 , V_274 ) ;
goto V_471;
}
}
V_44 = F_204 ( V_32 , V_116 -> V_394 ,
V_288 -> V_293 , 0 ,
V_472 , V_473 ,
V_397 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_34 , V_139 ) ;
goto V_471;
}
V_471:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_246 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_433 = & V_200 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
int V_44 ;
int V_139 ;
struct V_206 * V_414 ;
struct V_437 * V_438 ;
struct V_431 * V_474 ;
int V_445 ;
if ( V_32 -> V_62 . V_423 !=
V_424 )
return - V_475 ;
V_438 = (struct V_437 * ) V_116 -> V_118 ;
V_44 = F_134 ( V_32 , V_33 , V_438 -> V_36 ) ;
if ( V_44 <= 0 )
return - V_45 ;
V_438 -> V_36 = V_44 ;
V_139 = F_40 ( V_438 -> V_139 ) & 0xffffff ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_414 ) ;
if ( V_44 ) {
F_73 ( L_35 , V_139 ) ;
return V_44 ;
}
V_474 = (struct V_431 * ) ( V_438 + 1 ) ;
V_445 = F_247 ( F_248 ( V_474 -> V_193 ) ) ;
if ( V_445 == V_456 )
F_243 ( V_438 , V_474 ) ;
if ( V_33 == V_32 -> V_62 . V_113 )
goto V_476;
switch ( V_445 ) {
case V_456 :
if ( F_238 ( V_33 , V_474 , V_433 ) ) {
V_44 = - V_45 ;
goto V_477;
}
break;
case V_478 :
break;
case V_452 :
case V_453 :
case V_454 :
F_249 ( L_36 ) ;
if ( F_244 ( V_32 , V_33 , V_116 , V_433 , V_445 ) ) {
V_44 = - V_45 ;
goto V_477;
}
V_288 -> V_293 +=
sizeof( struct V_439 ) >> 2 ;
break;
default:
F_73 ( L_37 ) ;
V_44 = - V_45 ;
goto V_477;
}
V_476:
V_44 = F_250 ( V_32 , V_116 -> V_394 , & V_288 -> V_268 ,
V_288 -> V_293 , 0 ,
V_479 , V_473 ,
V_397 ) ;
if ( V_44 )
goto V_477;
V_44 = F_77 ( V_32 , V_33 , V_288 -> V_268 , 1 , V_29 , V_139 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_38 ) ;
F_204 ( V_32 , V_288 -> V_268 , 0 , 0 ,
V_480 , V_473 ,
V_397 ) ;
goto V_477;
}
F_174 ( & V_414 -> V_211 ) ;
V_477:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_251 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
struct V_206 * V_414 ;
struct V_226 * V_481 ;
if ( V_32 -> V_62 . V_423 !=
V_424 )
return - V_475 ;
V_44 = F_50 ( V_32 , V_33 , V_288 -> V_267 , V_29 , & V_481 ) ;
if ( V_44 )
return V_44 ;
F_55 ( V_32 , V_33 , V_288 -> V_267 , V_29 ) ;
V_44 = F_50 ( V_32 , V_33 , V_481 -> V_139 , V_20 , & V_414 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_94 ( V_32 , V_33 , V_288 -> V_267 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_39 ) ;
goto V_59;
}
V_44 = F_204 ( V_32 , V_288 -> V_267 , 0 , 0 ,
V_480 , V_473 ,
V_397 ) ;
if ( ! V_44 )
F_176 ( & V_414 -> V_211 ) ;
V_59:
F_55 ( V_32 , V_33 , V_481 -> V_139 , V_20 ) ;
return V_44 ;
}
int F_252 ( struct V_31 * V_32 , int V_33 ,
struct V_287 * V_288 ,
struct V_115 * V_116 ,
struct V_115 * V_289 ,
struct V_290 * V_266 )
{
int V_44 ;
int V_250 = V_288 -> V_293 & 0xffff ;
V_44 = F_50 ( V_32 , V_33 , V_250 , V_28 , NULL ) ;
if ( V_44 )
return V_44 ;
V_44 = F_173 ( V_32 , V_33 , V_288 , V_116 , V_289 , V_266 ) ;
F_55 ( V_32 , V_33 , V_250 , V_28 ) ;
return V_44 ;
}
static void F_253 ( struct V_31 * V_32 , int V_33 , struct V_206 * V_414 )
{
struct V_413 * V_482 ;
struct V_413 * V_201 ;
struct V_421 V_66 ;
F_128 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_32 -> V_62 . V_423 ) {
case V_424 :
F_234 ( V_32 , V_482 -> V_420 ) ;
break;
case V_425 :
V_66 . V_139 = V_414 -> V_208 ;
( void ) F_235 ( V_32 , & V_66 , V_482 -> V_415 ,
V_482 -> V_417 , V_482 -> V_419 ) ;
break;
}
F_95 ( & V_482 -> V_236 ) ;
F_31 ( V_482 ) ;
}
}
static int F_254 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_483 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_433 = & V_200 -> V_87 [ V_33 ] . V_92 [ type ] ;
struct V_10 * V_185 ;
struct V_10 * V_201 ;
int V_484 ;
V_484 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (r, tmp, rlist, list) {
if ( V_185 -> V_189 == V_33 ) {
if ( ! V_185 -> V_485 ) {
if ( V_185 -> V_2 == V_187 ) {
if ( V_483 )
F_24 ( V_32 ,
L_40 ,
F_7 ( type ) ,
V_185 -> V_7 ) ;
++ V_484 ;
} else {
V_185 -> V_191 = V_185 -> V_2 ;
V_185 -> V_2 = V_187 ;
V_185 -> V_485 = 1 ;
}
}
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_484 ;
}
static int F_255 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type )
{
unsigned long V_486 ;
int V_484 ;
V_486 = V_487 ;
do {
V_484 = F_254 ( V_32 , V_33 , type , 0 ) ;
if ( F_256 ( V_487 , V_486 + 5 * V_488 ) )
break;
if ( V_484 )
F_257 () ;
} while ( V_484 );
if ( V_484 )
V_484 = F_254 ( V_32 , V_33 , type , 1 ) ;
return V_484 ;
}
static void F_258 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_489 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_20 ] ;
struct V_206 * V_66 ;
struct V_206 * V_201 ;
int V_2 ;
T_1 V_267 ;
int V_139 ;
int V_44 ;
V_44 = F_255 ( V_32 , V_33 , V_20 ) ;
if ( V_44 )
F_10 ( V_32 , L_41 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (qp, tmp, qp_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_66 -> V_198 . V_189 == V_33 ) {
V_139 = V_66 -> V_198 . V_7 ;
F_253 ( V_32 , V_33 , V_66 ) ;
V_2 = V_66 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_207 :
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_66 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_20 ] ) ;
F_95 ( & V_66 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
if ( ! F_103 ( V_32 , V_33 , V_139 ) ) {
F_111 ( V_32 , V_139 , 1 ) ;
F_12 ( V_32 , V_33 ,
V_20 , 1 , 0 ) ;
}
F_31 ( V_66 ) ;
V_2 = 0 ;
break;
case V_247 :
if ( ! F_103 ( V_32 , V_33 , V_139 ) )
F_148 ( V_32 , V_139 ) ;
V_2 = V_207 ;
break;
case V_248 :
V_267 = V_33 ;
V_44 = F_204 ( V_32 , V_267 ,
V_66 -> V_208 , 2 ,
V_490 ,
V_473 ,
V_397 ) ;
if ( V_44 )
F_24 ( V_32 , L_42 ,
V_33 , V_66 -> V_208 ) ;
F_176 ( & V_66 -> V_339 -> V_211 ) ;
F_176 ( & V_66 -> V_340 -> V_211 ) ;
F_176 ( & V_66 -> V_75 -> V_211 ) ;
if ( V_66 -> V_72 )
F_176 ( & V_66 -> V_72 -> V_211 ) ;
V_2 = V_247 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_259 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_491 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_22 ] ;
struct V_221 * V_72 ;
struct V_221 * V_201 ;
int V_2 ;
T_1 V_267 ;
F_260 ( V_492 ) ;
int V_273 ;
int V_44 ;
V_44 = F_255 ( V_32 , V_33 , V_22 ) ;
if ( V_44 )
F_10 ( V_32 , L_43 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (srq, tmp, srq_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_72 -> V_198 . V_189 == V_33 ) {
V_273 = V_72 -> V_198 . V_7 ;
V_2 = V_72 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_222 :
F_126 ( V_32 , V_273 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_72 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_22 ] ) ;
F_95 ( & V_72 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_22 , 1 , 0 ) ;
F_31 ( V_72 ) ;
V_2 = 0 ;
break;
case V_262 :
V_267 = V_33 ;
V_44 = F_204 ( V_32 , V_267 , V_273 , 1 ,
V_493 ,
V_473 ,
V_397 ) ;
if ( V_44 )
F_24 ( V_32 , L_44 ,
V_33 , V_273 ) ;
F_176 ( & V_72 -> V_75 -> V_211 ) ;
if ( V_72 -> V_69 )
F_176 ( & V_72 -> V_69 -> V_211 ) ;
V_2 = V_222 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_261 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_494 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_21 ] ;
struct V_219 * V_69 ;
struct V_219 * V_201 ;
int V_2 ;
T_1 V_267 ;
F_260 ( V_492 ) ;
int V_258 ;
int V_44 ;
V_44 = F_255 ( V_32 , V_33 , V_21 ) ;
if ( V_44 )
F_10 ( V_32 , L_45 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (cq, tmp, cq_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_69 -> V_198 . V_189 == V_33 && ! F_82 ( & V_69 -> V_211 ) ) {
V_258 = V_69 -> V_198 . V_7 ;
V_2 = V_69 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_220 :
F_123 ( V_32 , V_258 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_69 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_21 ] ) ;
F_95 ( & V_69 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_21 , 1 , 0 ) ;
F_31 ( V_69 ) ;
V_2 = 0 ;
break;
case V_260 :
V_267 = V_33 ;
V_44 = F_204 ( V_32 , V_267 , V_258 , 1 ,
V_495 ,
V_473 ,
V_397 ) ;
if ( V_44 )
F_24 ( V_32 , L_46 ,
V_33 , V_258 ) ;
F_176 ( & V_69 -> V_75 -> V_211 ) ;
V_2 = V_220 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_262 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_496 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_23 ] ;
struct V_215 * V_77 ;
struct V_215 * V_201 ;
int V_2 ;
T_1 V_267 ;
F_260 ( V_492 ) ;
int V_497 ;
int V_44 ;
V_44 = F_255 ( V_32 , V_33 , V_23 ) ;
if ( V_44 )
F_10 ( V_32 , L_47 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (mpt, tmp, mpt_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_77 -> V_198 . V_189 == V_33 ) {
V_497 = V_77 -> V_198 . V_7 ;
V_2 = V_77 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_216 :
F_119 ( V_32 , V_77 -> V_214 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_77 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_23 ] ) ;
F_95 ( & V_77 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_23 , 1 , 0 ) ;
F_31 ( V_77 ) ;
V_2 = 0 ;
break;
case V_252 :
F_151 ( V_32 , V_77 -> V_214 ) ;
V_2 = V_216 ;
break;
case V_253 :
V_267 = V_33 ;
V_44 = F_204 ( V_32 , V_267 , V_497 , 0 ,
V_498 ,
V_473 ,
V_397 ) ;
if ( V_44 )
F_24 ( V_32 , L_48 ,
V_33 , V_497 ) ;
if ( V_77 -> V_75 )
F_176 ( & V_77 -> V_75 -> V_211 ) ;
V_2 = V_252 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_263 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_499 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_24 ] ;
struct V_213 * V_75 ;
struct V_213 * V_201 ;
int V_2 ;
F_260 ( V_492 ) ;
int V_233 ;
int V_44 ;
V_44 = F_255 ( V_32 , V_33 , V_24 ) ;
if ( V_44 )
F_10 ( V_32 , L_49 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (mtt, tmp, mtt_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_75 -> V_198 . V_189 == V_33 ) {
V_233 = V_75 -> V_198 . V_7 ;
V_2 = V_75 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_116 ( V_32 , V_233 ,
V_75 -> V_212 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_75 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_24 ] ) ;
F_95 ( & V_75 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 , V_24 ,
1 << V_75 -> V_212 , 0 ) ;
F_31 ( V_75 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_264 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_500 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_29 ] ;
struct V_226 * V_501 ;
struct V_226 * V_201 ;
int V_2 ;
T_1 V_233 ;
int V_44 ;
V_44 = F_255 ( V_32 , V_33 , V_29 ) ;
if ( V_44 )
F_10 ( V_32 , L_50 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (fs_rule, tmp, fs_rule_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_501 -> V_198 . V_189 == V_33 ) {
V_233 = V_501 -> V_198 . V_7 ;
V_2 = V_501 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_227 :
V_44 = F_204 ( V_32 , V_233 , 0 , 0 ,
V_480 ,
V_473 ,
V_397 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_501 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_29 ] ) ;
F_95 ( & V_501 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_31 ( V_501 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_265 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_502 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_27 ] ;
struct V_217 * V_255 ;
struct V_217 * V_201 ;
int V_44 ;
int V_2 ;
F_260 ( V_492 ) ;
int V_357 ;
V_44 = F_255 ( V_32 , V_33 , V_27 ) ;
if ( V_44 )
F_10 ( V_32 , L_51 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (eq, tmp, eq_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_255 -> V_198 . V_189 == V_33 ) {
V_357 = V_255 -> V_198 . V_7 ;
V_2 = V_255 -> V_198 . V_191 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_218 :
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_255 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_27 ] ) ;
F_95 ( & V_255 -> V_198 . V_236 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_31 ( V_255 ) ;
V_2 = 0 ;
break;
case V_257 :
V_44 = F_204 ( V_32 , V_33 , V_357 & 0x3ff ,
1 , V_503 ,
V_473 ,
V_397 ) ;
if ( V_44 )
F_24 ( V_32 , L_52 ,
V_33 , V_357 & 0x3ff ) ;
F_176 ( & V_255 -> V_75 -> V_211 ) ;
V_2 = V_218 ;
break;
default:
V_2 = 0 ;
}
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_266 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_504 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_28 ] ;
struct V_195 * V_196 ;
struct V_195 * V_201 ;
int V_44 ;
int * V_231 = NULL ;
int V_83 , V_84 ;
V_44 = F_255 ( V_32 , V_33 , V_28 ) ;
if ( V_44 )
F_10 ( V_32 , L_53 ,
V_33 ) ;
V_231 = F_75 ( V_32 -> V_62 . V_80 ,
sizeof( * V_231 ) , V_89 ) ;
if ( ! V_231 )
return;
do {
V_83 = 0 ;
V_84 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (counter, tmp, counter_list, com.list) {
if ( V_196 -> V_198 . V_189 == V_33 ) {
V_231 [ V_83 ++ ] = V_196 -> V_198 . V_7 ;
F_79 ( & V_196 -> V_198 . V_9 ,
& V_200 -> V_94 [ V_28 ] ) ;
F_95 ( & V_196 -> V_198 . V_236 ) ;
F_31 ( V_196 ) ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
while ( V_84 < V_83 ) {
F_142 ( V_32 , V_231 [ V_84 ++ ] ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
}
} while ( V_83 );
F_31 ( V_231 ) ;
}
static void F_267 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_199 * V_200 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_505 =
& V_200 -> V_87 [ V_33 ] . V_92 [ V_30 ] ;
struct V_224 * V_506 ;
struct V_224 * V_201 ;
int V_44 ;
int V_286 ;
V_44 = F_255 ( V_32 , V_33 , V_30 ) ;
if ( V_44 )
F_10 ( V_32 , L_54 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_506 -> V_198 . V_189 == V_33 ) {
V_286 = V_506 -> V_198 . V_7 ;
F_79 ( & V_506 -> V_198 . V_9 , & V_200 -> V_94 [ V_30 ] ) ;
F_95 ( & V_506 -> V_198 . V_236 ) ;
F_31 ( V_506 ) ;
F_145 ( V_32 , V_286 ) ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
}
void F_33 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
F_34 ( V_32 , V_33 ) ;
F_35 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
F_36 ( V_32 , V_33 ) ;
F_131 ( V_32 , V_33 ) ;
F_264 ( V_32 , V_33 ) ;
F_258 ( V_32 , V_33 ) ;
F_259 ( V_32 , V_33 ) ;
F_261 ( V_32 , V_33 ) ;
F_262 ( V_32 , V_33 ) ;
F_265 ( V_32 , V_33 ) ;
F_263 ( V_32 , V_33 ) ;
F_266 ( V_32 , V_33 ) ;
F_267 ( V_32 , V_33 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
}
void F_268 ( struct V_507 * V_508 )
{
struct V_509 * V_510 =
F_3 ( V_508 , struct V_509 , V_510 ) ;
struct V_115 * V_385 ;
struct V_461 * V_511 ;
struct V_31 * V_32 = & V_510 -> V_38 -> V_32 ;
struct V_199 * V_200 =
& V_510 -> V_38 -> V_41 . V_42 . V_43 ;
struct V_276 * V_489 =
& V_200 -> V_87 [ V_510 -> V_33 ] . V_92 [ V_20 ] ;
struct V_206 * V_66 ;
struct V_206 * V_201 ;
T_1 V_512 =
( ( 1ULL << V_513 ) |
( 1ULL << V_514 ) |
( 1ULL << V_515 ) |
( 1ULL << V_516 ) |
( 1ULL << V_517 ) |
( 1ULL << V_518 ) ) ;
T_1 V_519 = ( ( 1ULL << V_520 ) |
( 1ULL << V_521 ) |
( 1ULL << V_522 ) |
( 1ULL << V_523 ) |
( 1ULL << V_524 ) |
( 1ULL << V_525 ) |
( 1ULL << V_526 ) ) ;
int V_44 ;
int V_36 , V_527 = 0 ;
T_2 V_157 ;
if ( F_16 ( V_32 ) ) {
F_10 ( V_32 , L_55 ,
V_510 -> V_33 ) ;
goto V_59;
}
V_385 = F_200 ( V_32 ) ;
if ( F_201 ( V_385 ) )
goto V_59;
if ( V_510 -> V_128 & V_528 )
V_157 = V_163 |
V_164 |
V_165 |
V_166 |
V_167 |
V_168 ;
else if ( ! V_510 -> V_529 )
V_157 = V_163 |
V_168 ;
else
V_157 = V_163 |
V_166 |
V_167 ;
V_511 = V_385 -> V_118 ;
V_511 -> V_463 = F_241 ( 1ULL << V_530 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_128 (qp, tmp, qp_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_66 -> V_198 . V_189 == V_510 -> V_33 ) {
if ( V_66 -> V_198 . V_191 != V_248 ||
! V_66 -> V_131 ||
F_45 ( V_32 , V_66 -> V_208 ) ||
V_66 -> V_345 & ( 1 << V_531 ) ) {
F_51 ( F_52 ( V_32 ) ) ;
continue;
}
V_36 = ( V_66 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_36 != V_510 -> V_36 ) {
F_51 ( F_52 ( V_32 ) ) ;
continue;
}
if ( V_133 == ( ( V_66 -> V_345 >> 16 ) & 0xff ) )
V_511 -> V_462 = F_241 ( V_519 ) ;
else
V_511 -> V_462 =
F_241 ( V_519 | V_512 ) ;
if ( V_510 -> V_529 == V_146 ) {
V_511 -> V_470 . V_152 = V_66 -> V_152 ;
V_511 -> V_470 . V_130 . V_157 = V_66 -> V_157 ;
V_511 -> V_470 . V_130 . V_169 = V_66 -> V_169 ;
V_511 -> V_470 . V_130 . V_171 = V_66 -> V_171 ;
V_511 -> V_470 . V_130 . V_173 = V_66 -> V_344 ;
V_511 -> V_470 . V_130 . V_176 = V_66 -> V_176 ;
V_511 -> V_470 . V_130 . V_131 =
V_66 -> V_131 ;
} else {
V_511 -> V_470 . V_152 = V_66 -> V_152 & ~ F_46 ( V_153 ) ;
V_511 -> V_470 . V_130 . V_157 = V_157 ;
V_511 -> V_470 . V_130 . V_171 = V_510 -> V_532 ;
V_511 -> V_470 . V_130 . V_169 =
V_66 -> V_169 | V_170 ;
V_511 -> V_470 . V_130 . V_173 =
V_66 -> V_344 | V_174 | V_175 ;
V_511 -> V_470 . V_130 . V_176 =
V_66 -> V_176 | V_177 | V_178 ;
V_511 -> V_470 . V_130 . V_131 =
V_66 -> V_131 & 0xC7 ;
V_511 -> V_470 . V_130 . V_131 |=
( ( V_510 -> V_533 & 0x7 ) << 3 ) ;
V_511 -> V_463 |=
F_241 ( 1ULL <<
V_534 ) ;
V_511 -> V_470 . V_180 =
V_510 -> V_180 ;
}
V_44 = F_204 ( V_32 , V_385 -> V_394 ,
V_66 -> V_208 & 0xffffff ,
0 , V_472 ,
V_535 , V_397 ) ;
if ( V_44 ) {
F_269 ( V_32 , L_56 ,
V_510 -> V_33 , V_36 , V_66 -> V_208 , V_44 ) ;
V_527 ++ ;
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
F_205 ( V_32 , V_385 ) ;
if ( V_527 )
F_61 ( V_32 , L_57 ,
V_527 , V_510 -> V_33 , V_510 -> V_36 ) ;
if ( V_510 -> V_128 & V_536 && ! V_527 &&
V_537 != V_510 -> V_538 )
F_138 ( & V_510 -> V_38 -> V_32 , V_510 -> V_36 ,
V_510 -> V_539 ) ;
V_59:
F_31 ( V_510 ) ;
return;
}
