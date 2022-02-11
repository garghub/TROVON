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
if ( V_142 -> V_2 . V_157 == V_158 &&
V_32 -> V_62 . V_159 & V_160 ) {
V_140 -> V_130 . V_161 =
V_162 |
V_163 |
V_164 |
V_165 |
V_166 |
V_167 ;
} else if ( 0 != V_142 -> V_2 . V_147 ) {
V_140 -> V_130 . V_161 =
V_162 |
V_165 |
V_166 ;
} else {
V_140 -> V_130 . V_161 =
V_162 |
V_167 ;
}
V_140 -> V_130 . V_168 |= V_169 ;
V_140 -> V_130 . V_170 = V_142 -> V_171 ;
V_140 -> V_130 . V_172 |= V_173 | V_174 ;
V_140 -> V_130 . V_175 |= V_176 | V_177 ;
V_140 -> V_130 . V_131 &= 0xC7 ;
V_140 -> V_130 . V_131 |= ( V_142 -> V_2 . V_178 ) << 3 ;
V_140 -> V_179 = V_142 -> V_2 . V_179 ;
}
if ( V_142 -> V_2 . V_180 ) {
V_140 -> V_130 . V_175 |= V_181 ;
V_140 -> V_130 . V_182 = ( 0x80 & V_140 -> V_130 . V_182 ) + V_142 -> V_183 ;
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
struct V_10 * V_184 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_49 ( V_32 , V_7 , type ) ;
if ( ! V_184 ) {
V_44 = - V_185 ;
goto exit;
}
if ( V_184 -> V_2 == V_186 ) {
V_44 = - V_187 ;
goto exit;
}
if ( V_184 -> V_188 != V_33 ) {
V_44 = - V_189 ;
goto exit;
}
V_184 -> V_190 = V_184 -> V_2 ;
V_184 -> V_2 = V_186 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_184 ;
exit:
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
int F_54 ( struct V_31 * V_32 ,
enum V_18 type ,
T_1 V_7 , int * V_33 )
{
struct V_10 * V_184 ;
int V_44 = - V_191 ;
int V_192 = V_7 ;
if ( type == V_20 )
V_192 &= 0x7fffff ;
F_9 ( F_52 ( V_32 ) ) ;
V_184 = F_49 ( V_32 , V_192 , type ) ;
if ( V_184 ) {
* V_33 = V_184 -> V_188 ;
V_44 = 0 ;
}
F_11 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static void F_55 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_184 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_49 ( V_32 , V_7 , type ) ;
if ( V_184 )
V_184 -> V_2 = V_184 -> V_190 ;
F_53 ( F_52 ( V_32 ) ) ;
}
static int F_56 ( struct V_31 * V_32 , T_2 V_33 , int V_36 ,
int V_193 )
{
struct V_10 * V_184 ;
struct V_194 * V_195 ;
int V_196 = 0 ;
if ( V_193 == F_57 ( V_32 ) )
return V_196 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_49 ( V_32 , V_193 , V_28 ) ;
if ( ! V_184 || V_184 -> V_188 != V_33 )
V_196 = - V_45 ;
V_195 = F_3 ( V_184 , struct V_194 , V_197 ) ;
if ( ! V_195 -> V_36 )
V_195 -> V_36 = V_36 ;
F_53 ( F_52 ( V_32 ) ) ;
return V_196 ;
}
static int F_58 ( struct V_31 * V_32 ,
struct V_122 * V_140 , T_2 V_33 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_200 ;
struct V_194 * V_195 ;
T_1 V_201 = F_57 ( V_32 ) ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
F_59 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_195 = F_3 ( V_200 , struct V_194 , V_197 ) ;
if ( V_36 == V_195 -> V_36 ) {
V_140 -> V_130 . V_193 = V_195 -> V_197 . V_7 ;
F_53 ( F_52 ( V_32 ) ) ;
return 0 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
V_44 = F_60 ( V_32 , V_33 , V_202 , 0 , 0 , & V_201 ,
V_36 ) ;
if ( V_44 == - V_191 ) {
V_44 = 0 ;
} else if ( V_44 && V_44 != - V_203 ) {
F_61 ( V_32 , L_19 ,
V_204 , V_33 , V_44 ) ;
} else {
V_140 -> V_130 . V_193 = V_201 ;
F_24 ( V_32 , L_20 ,
V_204 , V_33 , V_140 -> V_130 . V_193 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_44 ( struct V_31 * V_32 , struct V_122 * V_140 ,
T_2 V_33 , int V_36 )
{
if ( V_140 -> V_130 . V_193 != F_57 ( V_32 ) )
return F_56 ( V_32 , V_33 , V_36 ,
V_140 -> V_130 . V_193 ) ;
return F_58 ( V_32 , V_140 , V_33 , V_36 ) ;
}
static struct V_10 * F_62 ( int V_192 )
{
struct V_205 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_206 ;
V_196 -> V_207 = V_192 ;
F_22 ( & V_196 -> V_208 ) ;
F_26 ( & V_196 -> V_209 ) ;
F_63 ( & V_196 -> V_210 , 0 ) ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_64 ( int V_192 , int V_211 )
{
struct V_212 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_211 = V_211 ;
V_196 -> V_197 . V_2 = V_4 ;
F_63 ( & V_196 -> V_210 , 0 ) ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_65 ( int V_192 , int V_213 )
{
struct V_214 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_215 ;
V_196 -> V_213 = V_213 ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_66 ( int V_192 )
{
struct V_216 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_217 ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_67 ( int V_192 )
{
struct V_218 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_219 ;
F_63 ( & V_196 -> V_210 , 0 ) ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_68 ( int V_192 )
{
struct V_220 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_221 ;
F_63 ( & V_196 -> V_210 , 0 ) ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_69 ( int V_192 , int V_36 )
{
struct V_194 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_222 ;
V_196 -> V_36 = V_36 ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_70 ( int V_192 )
{
struct V_223 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_224 ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_71 ( T_1 V_192 , int V_139 )
{
struct V_225 * V_196 ;
V_196 = F_21 ( sizeof *V_196 , V_89 ) ;
if ( ! V_196 )
return NULL ;
V_196 -> V_197 . V_7 = V_192 ;
V_196 -> V_197 . V_2 = V_226 ;
V_196 -> V_139 = V_139 ;
return & V_196 -> V_197 ;
}
static struct V_10 * F_72 ( T_1 V_192 , enum V_18 type , int V_33 ,
int V_227 )
{
struct V_10 * V_196 ;
switch ( type ) {
case V_20 :
V_196 = F_62 ( V_192 ) ;
break;
case V_23 :
V_196 = F_65 ( V_192 , V_227 ) ;
break;
case V_24 :
V_196 = F_64 ( V_192 , V_227 ) ;
break;
case V_27 :
V_196 = F_66 ( V_192 ) ;
break;
case V_21 :
V_196 = F_67 ( V_192 ) ;
break;
case V_22 :
V_196 = F_68 ( V_192 ) ;
break;
case V_25 :
F_73 ( L_21 ) ;
return NULL ;
case V_28 :
V_196 = F_69 ( V_192 , V_227 ) ;
break;
case V_30 :
V_196 = F_70 ( V_192 ) ;
break;
case V_29 :
V_196 = F_71 ( V_192 , V_227 ) ;
break;
default:
return NULL ;
}
if ( V_196 )
V_196 -> V_188 = V_33 ;
return V_196 ;
}
int F_74 ( struct V_31 * V_32 , int V_33 , int V_36 ,
struct V_228 * V_229 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_200 ;
struct V_194 * V_195 ;
int * V_230 ;
int V_83 = 0 , V_44 = 0 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
V_230 = F_75 ( V_32 -> V_62 . V_80 ,
sizeof( * V_230 ) , V_89 ) ;
if ( ! V_230 )
return - V_90 ;
F_51 ( F_52 ( V_32 ) ) ;
F_59 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_195 = F_3 ( V_200 , struct V_194 , V_197 ) ;
if ( V_195 -> V_36 == V_36 ) {
V_230 [ V_83 ] = ( int ) V_200 -> V_7 ;
V_83 ++ ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
V_230 [ V_83 ] = - 1 ;
V_83 = 0 ;
while ( V_230 [ V_83 ] != - 1 ) {
V_44 = F_76 ( V_32 , V_230 [ V_83 ] , V_229 ,
0 ) ;
if ( V_44 ) {
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
goto V_231;
}
V_83 ++ ;
}
V_231:
F_31 ( V_230 ) ;
return 0 ;
}
static int F_77 ( struct V_31 * V_32 , int V_33 , T_1 V_232 , int V_35 ,
enum V_18 type , int V_227 )
{
int V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_10 * * V_233 ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_199 -> V_94 [ type ] ;
V_233 = F_21 ( V_35 * sizeof *V_233 , V_89 ) ;
if ( ! V_233 )
return - V_90 ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
V_233 [ V_83 ] = F_72 ( V_232 + V_83 , type , V_33 , V_227 ) ;
if ( ! V_233 [ V_83 ] ) {
for ( -- V_83 ; V_83 >= 0 ; -- V_83 )
F_31 ( V_233 [ V_83 ] ) ;
F_31 ( V_233 ) ;
return - V_90 ;
}
}
F_51 ( F_52 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
if ( F_49 ( V_32 , V_232 + V_83 , type ) ) {
V_44 = - V_17 ;
goto V_234;
}
V_44 = F_4 ( V_6 , V_233 [ V_83 ] ) ;
if ( V_44 )
goto V_234;
F_78 ( & V_233 [ V_83 ] -> V_235 ,
& V_199 -> V_87 [ V_33 ] . V_92 [ type ] ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
F_31 ( V_233 ) ;
return 0 ;
V_234:
for ( -- V_83 ; V_83 >= V_232 ; -- V_83 )
F_79 ( & V_233 [ V_83 ] -> V_9 , V_6 ) ;
F_53 ( F_52 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 )
F_31 ( V_233 [ V_83 ] ) ;
F_31 ( V_233 ) ;
return V_44 ;
}
static int F_80 ( struct V_205 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_236 || F_81 ( & V_11 -> V_210 ) ||
! F_82 ( & V_11 -> V_208 ) ) {
F_73 ( L_22 ,
V_11 -> V_197 . V_2 , F_81 ( & V_11 -> V_210 ) ) ;
return - V_187 ;
} else if ( V_11 -> V_197 . V_2 != V_206 ) {
return - V_189 ;
}
return 0 ;
}
static int F_83 ( struct V_212 * V_11 , int V_211 )
{
if ( V_11 -> V_197 . V_2 == V_3 ||
F_81 ( & V_11 -> V_210 ) ) {
F_84 ( L_23 ,
V_204 , __LINE__ ,
F_1 ( V_11 -> V_197 . V_2 ) ,
F_81 ( & V_11 -> V_210 ) ) ;
return - V_187 ;
} else if ( V_11 -> V_197 . V_2 != V_4 )
return - V_189 ;
else if ( V_11 -> V_211 != V_211 )
return - V_45 ;
return 0 ;
}
static int F_85 ( struct V_214 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_237 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_215 )
return - V_189 ;
return 0 ;
}
static int F_86 ( struct V_216 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_237 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_215 )
return - V_189 ;
return 0 ;
}
static int F_87 ( struct V_194 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_238 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_222 )
return - V_189 ;
return 0 ;
}
static int F_88 ( struct V_223 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_239 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_224 )
return - V_189 ;
return 0 ;
}
static int F_89 ( struct V_225 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_240 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_226 )
return - V_189 ;
return 0 ;
}
static int F_90 ( struct V_218 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_241 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_219 )
return - V_189 ;
return 0 ;
}
static int F_91 ( struct V_220 * V_11 )
{
if ( V_11 -> V_197 . V_2 == V_242 )
return - V_187 ;
else if ( V_11 -> V_197 . V_2 != V_221 )
return - V_189 ;
return 0 ;
}
static int F_92 ( struct V_10 * V_11 , enum V_18 type , int V_227 )
{
switch ( type ) {
case V_20 :
return F_80 ( (struct V_205 * ) V_11 ) ;
case V_21 :
return F_90 ( (struct V_218 * ) V_11 ) ;
case V_22 :
return F_91 ( (struct V_220 * ) V_11 ) ;
case V_23 :
return F_85 ( (struct V_214 * ) V_11 ) ;
case V_24 :
return F_83 ( (struct V_212 * ) V_11 , V_227 ) ;
case V_25 :
return - V_243 ;
case V_27 :
return F_86 ( (struct V_216 * ) V_11 ) ;
case V_28 :
return F_87 ( (struct V_194 * ) V_11 ) ;
case V_30 :
return F_88 ( (struct V_223 * ) V_11 ) ;
case V_29 :
return F_89 ( (struct V_225 * ) V_11 ) ;
default:
return - V_45 ;
}
}
static int F_93 ( struct V_31 * V_32 , int V_33 , T_1 V_232 , int V_35 ,
enum V_18 type , int V_227 )
{
T_1 V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_184 ;
F_51 ( F_52 ( V_32 ) ) ;
for ( V_83 = V_232 ; V_83 < V_232 + V_35 ; ++ V_83 ) {
V_184 = F_2 ( & V_199 -> V_94 [ type ] , V_83 ) ;
if ( ! V_184 ) {
V_44 = - V_191 ;
goto V_59;
}
if ( V_184 -> V_188 != V_33 ) {
V_44 = - V_189 ;
goto V_59;
}
V_44 = F_92 ( V_184 , type , V_227 ) ;
if ( V_44 )
goto V_59;
}
for ( V_83 = V_232 ; V_83 < V_232 + V_35 ; ++ V_83 ) {
V_184 = F_2 ( & V_199 -> V_94 [ type ] , V_83 ) ;
F_79 ( & V_184 -> V_9 , & V_199 -> V_94 [ type ] ) ;
F_94 ( & V_184 -> V_235 ) ;
F_31 ( V_184 ) ;
}
V_44 = 0 ;
V_59:
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_95 ( struct V_31 * V_32 , int V_33 , int V_139 ,
enum V_244 V_2 , struct V_205 * * V_66 ,
int V_245 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_205 * V_184 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ V_20 ] , V_139 ) ;
if ( ! V_184 )
V_44 = - V_191 ;
else if ( V_184 -> V_197 . V_188 != V_33 )
V_44 = - V_189 ;
else {
switch ( V_2 ) {
case V_236 :
F_24 ( V_32 , L_24 ,
V_204 , V_184 -> V_197 . V_7 ) ;
V_44 = - V_187 ;
break;
case V_206 :
if ( V_184 -> V_197 . V_2 == V_246 && ! V_245 )
break;
F_24 ( V_32 , L_25 , V_184 -> V_197 . V_7 ) ;
V_44 = - V_45 ;
break;
case V_246 :
if ( ( V_184 -> V_197 . V_2 == V_206 && V_245 ) ||
V_184 -> V_197 . V_2 == V_247 )
break;
else {
F_24 ( V_32 , L_25 ,
V_184 -> V_197 . V_7 ) ;
V_44 = - V_45 ;
}
break;
case V_247 :
if ( V_184 -> V_197 . V_2 != V_246 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_184 -> V_197 . V_190 = V_184 -> V_197 . V_2 ;
V_184 -> V_197 . V_248 = V_2 ;
V_184 -> V_197 . V_2 = V_236 ;
if ( V_66 )
* V_66 = V_184 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_96 ( struct V_31 * V_32 , int V_33 , int V_249 ,
enum V_250 V_2 , struct V_214 * * V_77 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_214 * V_184 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ V_23 ] , V_249 ) ;
if ( ! V_184 )
V_44 = - V_191 ;
else if ( V_184 -> V_197 . V_188 != V_33 )
V_44 = - V_189 ;
else {
switch ( V_2 ) {
case V_237 :
V_44 = - V_45 ;
break;
case V_215 :
if ( V_184 -> V_197 . V_2 != V_251 )
V_44 = - V_45 ;
break;
case V_251 :
if ( V_184 -> V_197 . V_2 != V_215 &&
V_184 -> V_197 . V_2 != V_252 )
V_44 = - V_45 ;
break;
case V_252 :
if ( V_184 -> V_197 . V_2 != V_251 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_184 -> V_197 . V_190 = V_184 -> V_197 . V_2 ;
V_184 -> V_197 . V_248 = V_2 ;
V_184 -> V_197 . V_2 = V_237 ;
if ( V_77 )
* V_77 = V_184 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_97 ( struct V_31 * V_32 , int V_33 , int V_249 ,
enum V_253 V_2 , struct V_216 * * V_254 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_216 * V_184 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ V_27 ] , V_249 ) ;
if ( ! V_184 )
V_44 = - V_191 ;
else if ( V_184 -> V_197 . V_188 != V_33 )
V_44 = - V_189 ;
else {
switch ( V_2 ) {
case V_255 :
V_44 = - V_45 ;
break;
case V_217 :
if ( V_184 -> V_197 . V_2 != V_256 )
V_44 = - V_45 ;
break;
case V_256 :
if ( V_184 -> V_197 . V_2 != V_217 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_184 -> V_197 . V_190 = V_184 -> V_197 . V_2 ;
V_184 -> V_197 . V_248 = V_2 ;
V_184 -> V_197 . V_2 = V_255 ;
if ( V_254 )
* V_254 = V_184 ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_98 ( struct V_31 * V_32 , int V_33 , int V_257 ,
enum V_258 V_2 , struct V_218 * * V_69 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_218 * V_184 ;
int V_44 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ V_21 ] , V_257 ) ;
if ( ! V_184 ) {
V_44 = - V_191 ;
} else if ( V_184 -> V_197 . V_188 != V_33 ) {
V_44 = - V_189 ;
} else if ( V_2 == V_219 ) {
if ( V_184 -> V_197 . V_2 != V_259 )
V_44 = - V_45 ;
else if ( F_81 ( & V_184 -> V_210 ) )
V_44 = - V_187 ;
else
V_44 = 0 ;
} else if ( V_2 != V_259 || V_184 -> V_197 . V_2 != V_219 ) {
V_44 = - V_45 ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
V_184 -> V_197 . V_190 = V_184 -> V_197 . V_2 ;
V_184 -> V_197 . V_248 = V_2 ;
V_184 -> V_197 . V_2 = V_241 ;
if ( V_69 )
* V_69 = V_184 ;
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_99 ( struct V_31 * V_32 , int V_33 , int V_249 ,
enum V_260 V_2 , struct V_220 * * V_72 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_220 * V_184 ;
int V_44 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ V_22 ] , V_249 ) ;
if ( ! V_184 ) {
V_44 = - V_191 ;
} else if ( V_184 -> V_197 . V_188 != V_33 ) {
V_44 = - V_189 ;
} else if ( V_2 == V_221 ) {
if ( V_184 -> V_197 . V_2 != V_261 )
V_44 = - V_45 ;
else if ( F_81 ( & V_184 -> V_210 ) )
V_44 = - V_187 ;
} else if ( V_2 != V_261 || V_184 -> V_197 . V_2 != V_221 ) {
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_184 -> V_197 . V_190 = V_184 -> V_197 . V_2 ;
V_184 -> V_197 . V_248 = V_2 ;
V_184 -> V_197 . V_2 = V_242 ;
if ( V_72 )
* V_72 = V_184 ;
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static void F_100 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_192 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_184 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ type ] , V_192 ) ;
if ( V_184 && ( V_184 -> V_188 == V_33 ) )
V_184 -> V_2 = V_184 -> V_190 ;
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_101 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_192 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_184 ;
F_51 ( F_52 ( V_32 ) ) ;
V_184 = F_2 ( & V_199 -> V_94 [ type ] , V_192 ) ;
if ( V_184 && ( V_184 -> V_188 == V_33 ) )
V_184 -> V_2 = V_184 -> V_248 ;
F_53 ( F_52 ( V_32 ) ) ;
}
static int F_102 ( struct V_31 * V_32 , int V_33 , int V_139 )
{
return F_45 ( V_32 , V_139 ) &&
( F_103 ( V_32 ) || F_104 ( V_32 , V_33 , V_139 ) ) ;
}
static int F_105 ( struct V_31 * V_32 , int V_139 )
{
return V_139 < V_32 -> V_62 . V_262 [ V_263 ] ;
}
static int F_106 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_44 ;
int V_35 ;
int V_268 ;
int V_232 ;
int V_139 ;
T_2 V_128 ;
switch ( V_264 ) {
case V_202 :
V_35 = F_107 ( & V_266 ) & 0xffffff ;
V_128 = ( F_107 ( & V_266 ) >> 24 ) & V_32 -> V_62 . V_269 ;
V_268 = F_108 ( & V_266 ) ;
V_44 = F_8 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_109 ( V_32 , V_35 , V_268 , & V_232 , V_128 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
return V_44 ;
}
V_44 = F_77 ( V_32 , V_33 , V_232 , V_35 , V_20 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_110 ( V_32 , V_232 , V_35 ) ;
return V_44 ;
}
F_111 ( V_267 , V_232 ) ;
break;
case V_270 :
V_139 = F_107 ( & V_266 ) & 0x7fffff ;
if ( F_102 ( V_32 , V_33 , V_139 ) ) {
V_44 = F_77 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_95 ( V_32 , V_33 , V_139 , V_246 ,
NULL , 1 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_105 ( V_32 , V_139 ) ) {
V_44 = F_112 ( V_32 , V_139 , V_89 ) ;
if ( V_44 ) {
F_100 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
}
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_113 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_44 = - V_45 ;
int V_232 ;
int V_211 ;
if ( V_264 != V_271 )
return V_44 ;
V_211 = F_107 ( & V_266 ) ;
V_44 = F_8 ( V_32 , V_33 , V_24 , 1 << V_211 , 0 ) ;
if ( V_44 )
return V_44 ;
V_232 = F_114 ( V_32 , V_211 ) ;
if ( V_232 == - 1 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_211 , 0 ) ;
return - V_90 ;
}
V_44 = F_77 ( V_32 , V_33 , V_232 , 1 , V_24 , V_211 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_211 , 0 ) ;
F_115 ( V_32 , V_232 , V_211 ) ;
} else {
F_111 ( V_267 , V_232 ) ;
}
return V_44 ;
}
static int F_116 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_44 = - V_45 ;
int V_249 ;
int V_192 ;
struct V_214 * V_77 ;
switch ( V_264 ) {
case V_202 :
V_44 = F_8 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
if ( V_44 )
break;
V_249 = F_117 ( V_32 ) ;
if ( V_249 == - 1 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
break;
}
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_77 ( V_32 , V_33 , V_192 , 1 , V_23 , V_249 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_118 ( V_32 , V_249 ) ;
break;
}
F_111 ( V_267 , V_249 ) ;
break;
case V_270 :
V_249 = F_107 ( & V_266 ) ;
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_96 ( V_32 , V_33 , V_192 ,
V_251 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_119 ( V_32 , V_77 -> V_213 , V_89 ) ;
if ( V_44 ) {
F_100 ( V_32 , V_33 , V_23 , V_192 ) ;
return V_44 ;
}
F_101 ( V_32 , V_33 , V_23 , V_192 ) ;
break;
}
return V_44 ;
}
static int F_120 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_257 ;
int V_44 ;
switch ( V_264 ) {
case V_271 :
V_44 = F_8 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_121 ( V_32 , & V_257 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
break;
}
V_44 = F_77 ( V_32 , V_33 , V_257 , 1 , V_21 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_122 ( V_32 , V_257 ) ;
break;
}
F_111 ( V_267 , V_257 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_123 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_272 ;
int V_44 ;
switch ( V_264 ) {
case V_271 :
V_44 = F_8 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_124 ( V_32 , & V_272 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
break;
}
V_44 = F_77 ( V_32 , V_33 , V_272 , 1 , V_22 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_125 ( V_32 , V_272 ) ;
break;
}
F_111 ( V_267 , V_272 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_126 ( struct V_31 * V_32 , int V_33 , int V_36 ,
T_2 V_273 , T_1 * V_274 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_276 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_277 * V_11 , * V_200 ;
F_127 (res, tmp, mac_list, list) {
if ( V_11 -> V_273 == V_273 && V_11 -> V_36 == ( T_2 ) V_36 ) {
* V_274 = V_11 -> V_274 ;
return 0 ;
}
}
return - V_191 ;
}
static int F_128 ( struct V_31 * V_32 , int V_33 , T_1 V_274 , int V_36 , T_2 V_273 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_276 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_277 * V_11 , * V_200 ;
F_127 (res, tmp, mac_list, list) {
if ( V_11 -> V_274 == V_274 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_210 ;
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
V_11 -> V_274 = V_274 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_273 = V_273 ;
V_11 -> V_210 = 1 ;
F_78 ( & V_11 -> V_235 ,
& V_199 -> V_87 [ V_33 ] . V_92 [ V_25 ] ) ;
return 0 ;
}
static void F_129 ( struct V_31 * V_32 , int V_33 , T_1 V_274 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_276 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_277 * V_11 , * V_200 ;
F_127 (res, tmp, mac_list, list) {
if ( V_11 -> V_274 == V_274 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_210 ) {
F_94 ( & V_11 -> V_235 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
F_31 ( V_11 ) ;
}
break;
}
}
}
static void F_130 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_276 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_277 * V_11 , * V_200 ;
int V_83 ;
F_127 (res, tmp, mac_list, list) {
F_94 ( & V_11 -> V_235 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_210 ; V_83 ++ )
F_131 ( V_32 , V_11 -> V_36 , V_11 -> V_274 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_132 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 , int V_278 )
{
int V_44 = - V_45 ;
int V_36 ;
T_1 V_274 ;
T_2 V_273 ;
if ( V_264 != V_271 )
return V_44 ;
V_36 = ! V_278 ? F_107 ( V_267 ) : V_278 ;
V_36 = F_133 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
V_274 = V_266 ;
V_44 = F_134 ( V_32 , V_36 , V_274 ) ;
if ( V_44 >= 0 ) {
V_273 = V_44 ;
F_111 ( V_267 , V_44 ) ;
V_44 = 0 ;
}
if ( ! V_44 ) {
V_44 = F_128 ( V_32 , V_33 , V_274 , V_36 , V_273 ) ;
if ( V_44 )
F_131 ( V_32 , V_36 , V_274 ) ;
}
return V_44 ;
}
static int F_135 ( struct V_31 * V_32 , int V_33 , T_4 V_279 ,
int V_36 , int V_170 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_280 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_281 * V_11 , * V_200 ;
F_127 (res, tmp, vlan_list, list) {
if ( V_11 -> V_279 == V_279 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_210 ;
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
V_11 -> V_279 = V_279 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_170 = V_170 ;
V_11 -> V_210 = 1 ;
F_78 ( & V_11 -> V_235 ,
& V_199 -> V_87 [ V_33 ] . V_92 [ V_26 ] ) ;
return 0 ;
}
static void F_136 ( struct V_31 * V_32 , int V_33 , T_4 V_279 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_280 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_281 * V_11 , * V_200 ;
F_127 (res, tmp, vlan_list, list) {
if ( V_11 -> V_279 == V_279 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_210 ) {
F_94 ( & V_11 -> V_235 ) ;
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
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_280 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_281 * V_11 , * V_200 ;
int V_83 ;
F_127 (res, tmp, vlan_list, list) {
F_94 ( & V_11 -> V_235 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_210 ; V_83 ++ )
F_137 ( V_32 , V_11 -> V_36 , V_11 -> V_279 ) ;
F_12 ( V_32 , V_33 , V_26 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_138 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 , int V_278 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_282 * V_283 = V_38 -> V_41 . V_42 . V_283 ;
int V_44 ;
T_4 V_279 ;
int V_170 ;
int V_36 ;
V_36 = ! V_278 ? F_107 ( V_267 ) : V_278 ;
if ( ! V_36 || V_264 != V_271 )
return - V_45 ;
V_36 = F_133 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
if ( ! V_278 && V_36 > 0 && V_36 <= V_32 -> V_62 . V_100 ) {
V_283 [ V_33 ] . V_284 = true ;
return 0 ;
}
V_279 = ( T_4 ) V_266 ;
V_44 = F_139 ( V_32 , V_36 , V_279 , & V_170 ) ;
if ( ! V_44 ) {
F_111 ( V_267 , ( T_3 ) V_170 ) ;
V_44 = F_135 ( V_32 , V_33 , V_279 , V_36 , V_170 ) ;
if ( V_44 )
F_137 ( V_32 , V_36 , V_279 ) ;
}
return V_44 ;
}
static int F_60 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 , int V_36 )
{
T_3 V_249 ;
int V_44 ;
if ( V_264 != V_202 )
return - V_45 ;
V_44 = F_8 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_140 ( V_32 , & V_249 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
V_44 = F_77 ( V_32 , V_33 , V_249 , 1 , V_28 , V_36 ) ;
if ( V_44 ) {
F_141 ( V_32 , V_249 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
} else {
F_111 ( V_267 , V_249 ) ;
}
return V_44 ;
}
static int F_142 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
T_3 V_285 ;
int V_44 ;
if ( V_264 != V_202 )
return - V_45 ;
V_44 = F_143 ( V_32 , & V_285 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_77 ( V_32 , V_33 , V_285 , 1 , V_30 , 0 ) ;
if ( V_44 )
F_144 ( V_32 , V_285 ) ;
else
F_111 ( V_267 , V_285 ) ;
return V_44 ;
}
int F_145 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_290 = V_287 -> V_291 ;
switch ( V_287 -> V_292 & 0xFF ) {
case V_20 :
V_44 = F_106 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_24 :
V_44 = F_113 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_23 :
V_44 = F_116 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_21 :
V_44 = F_120 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_22 :
V_44 = F_123 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_25 :
V_44 = F_132 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ,
( V_287 -> V_292 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_138 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ,
( V_287 -> V_292 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_60 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 , 0 ) ;
break;
case V_30 :
V_44 = F_142 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_146 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 )
{
int V_44 ;
int V_35 ;
int V_232 ;
int V_139 ;
switch ( V_264 ) {
case V_202 :
V_232 = F_107 ( & V_266 ) & 0x7fffff ;
V_35 = F_108 ( & V_266 ) ;
V_44 = F_93 ( V_32 , V_33 , V_232 , V_35 , V_20 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_110 ( V_32 , V_232 , V_35 ) ;
break;
case V_270 :
V_139 = F_107 ( & V_266 ) & 0x7fffff ;
V_44 = F_95 ( V_32 , V_33 , V_139 , V_206 ,
NULL , 0 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_105 ( V_32 , V_139 ) )
F_147 ( V_32 , V_139 ) ;
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
if ( F_102 ( V_32 , V_33 , V_139 ) )
V_44 = F_93 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_148 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_44 = - V_45 ;
int V_232 ;
int V_211 ;
if ( V_264 != V_271 )
return V_44 ;
V_232 = F_107 ( & V_266 ) ;
V_211 = F_108 ( & V_266 ) ;
V_44 = F_93 ( V_32 , V_33 , V_232 , 1 , V_24 , V_211 ) ;
if ( ! V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_211 , 0 ) ;
F_115 ( V_32 , V_232 , V_211 ) ;
}
return V_44 ;
}
static int F_149 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 )
{
int V_44 = - V_45 ;
int V_249 ;
int V_192 ;
struct V_214 * V_77 ;
switch ( V_264 ) {
case V_202 :
V_249 = F_107 ( & V_266 ) ;
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_50 ( V_32 , V_33 , V_192 , V_23 , & V_77 ) ;
if ( V_44 )
break;
V_249 = V_77 -> V_213 ;
F_55 ( V_32 , V_33 , V_192 , V_23 ) ;
V_44 = F_93 ( V_32 , V_33 , V_192 , 1 , V_23 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_118 ( V_32 , V_249 ) ;
break;
case V_270 :
V_249 = F_107 ( & V_266 ) ;
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_96 ( V_32 , V_33 , V_192 ,
V_215 , & V_77 ) ;
if ( V_44 )
return V_44 ;
F_150 ( V_32 , V_77 -> V_213 ) ;
F_101 ( V_32 , V_33 , V_23 , V_192 ) ;
return V_44 ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_151 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_257 ;
int V_44 ;
switch ( V_264 ) {
case V_271 :
V_257 = F_107 ( & V_266 ) ;
V_44 = F_93 ( V_32 , V_33 , V_257 , 1 , V_21 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_122 ( V_32 , V_257 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_152 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_272 ;
int V_44 ;
switch ( V_264 ) {
case V_271 :
V_272 = F_107 ( & V_266 ) ;
V_44 = F_93 ( V_32 , V_33 , V_272 , 1 , V_22 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_125 ( V_32 , V_272 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_153 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 , int V_278 )
{
int V_36 ;
int V_44 = 0 ;
switch ( V_264 ) {
case V_271 :
V_36 = ! V_278 ? F_107 ( V_267 ) : V_278 ;
V_36 = F_133 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
F_129 ( V_32 , V_33 , V_266 , V_36 ) ;
F_131 ( V_32 , V_36 , V_266 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_154 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 , int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_282 * V_283 = V_38 -> V_41 . V_42 . V_283 ;
int V_44 = 0 ;
V_36 = F_133 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
switch ( V_264 ) {
case V_271 :
if ( V_283 [ V_33 ] . V_284 )
return 0 ;
if ( ! V_36 )
return - V_45 ;
F_136 ( V_32 , V_33 , V_266 , V_36 ) ;
F_137 ( V_32 , V_36 , V_266 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_155 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_249 ;
int V_44 ;
if ( V_264 != V_202 )
return - V_45 ;
V_249 = F_107 ( & V_266 ) ;
if ( V_249 == F_57 ( V_32 ) )
return 0 ;
V_44 = F_93 ( V_32 , V_33 , V_249 , 1 , V_28 , 0 ) ;
if ( V_44 )
return V_44 ;
F_141 ( V_32 , V_249 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
static int F_156 ( struct V_31 * V_32 , int V_33 , int V_264 , int V_265 ,
T_1 V_266 , T_1 * V_267 )
{
int V_285 ;
int V_44 ;
if ( V_264 != V_202 )
return - V_45 ;
V_285 = F_107 ( & V_266 ) ;
V_44 = F_93 ( V_32 , V_33 , V_285 , 1 , V_30 , 0 ) ;
if ( V_44 )
return V_44 ;
F_144 ( V_32 , V_285 ) ;
return V_44 ;
}
int F_157 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 = - V_45 ;
int V_290 = V_287 -> V_291 ;
switch ( V_287 -> V_292 & 0xFF ) {
case V_20 :
V_44 = F_146 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 ) ;
break;
case V_24 :
V_44 = F_148 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_23 :
V_44 = F_149 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 ) ;
break;
case V_21 :
V_44 = F_151 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_22 :
V_44 = F_152 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_25 :
V_44 = F_153 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ,
( V_287 -> V_292 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_154 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ,
( V_287 -> V_292 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_155 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
break;
case V_30 :
V_44 = F_156 ( V_32 , V_33 , V_287 -> V_291 , V_290 ,
V_287 -> V_266 , & V_287 -> V_267 ) ;
default:
break;
}
return V_44 ;
}
static int F_158 ( struct V_293 * V_77 )
{
return ( F_40 ( V_77 -> V_128 ) >> 9 ) & 1 ;
}
static int F_159 ( struct V_293 * V_77 )
{
return ( int ) F_160 ( V_77 -> V_294 ) & 0xfffffff8 ;
}
static int F_161 ( struct V_293 * V_77 )
{
return F_40 ( V_77 -> V_295 ) ;
}
static T_3 F_162 ( struct V_293 * V_77 )
{
return F_40 ( V_77 -> V_296 ) & 0x00ffffff ;
}
static int F_163 ( struct V_293 * V_77 )
{
return F_40 ( V_77 -> V_296 ) & V_297 ;
}
static int F_164 ( struct V_293 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_298 ;
}
static int F_165 ( struct V_293 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_299 ;
}
static int F_166 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_300 ) & 0xfffffff8 ;
}
static int F_167 ( struct V_301 * V_302 )
{
return F_40 ( V_302 -> V_300 ) & 0xfffffff8 ;
}
static int F_168 ( struct V_122 * V_140 )
{
int V_303 = ( V_140 -> V_304 & 0x3f ) + 12 ;
int V_305 = ( V_140 -> V_306 >> 3 ) & 0xf ;
int V_307 = V_140 -> V_306 & 7 ;
int V_308 = ( V_140 -> V_309 >> 3 ) & 0xf ;
int V_310 = V_140 -> V_309 & 7 ;
int V_72 = ( F_40 ( V_140 -> V_272 ) >> 24 ) & 1 ;
int V_311 = ( F_40 ( V_140 -> V_128 ) >> 13 ) & 1 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
int V_312 = ( V_127 == V_134 ) ? 1 : 0 ;
int V_313 ;
int V_314 ;
int V_315 ;
int V_316 ;
int V_317 = ( F_40 ( V_140 -> V_318 ) >> 6 ) & 0x3f ;
V_313 = 1 << ( V_305 + V_307 + 4 ) ;
V_314 = ( V_72 | V_311 | V_312 ) ? 0 : ( 1 << ( V_308 + V_310 + 4 ) ) ;
V_316 = V_313 + V_314 ;
V_315 =
F_169 ( ( V_316 + ( V_317 << 6 ) ) >>
V_303 ) ;
return V_315 ;
}
static int F_170 ( struct V_31 * V_32 , int V_33 , int V_319 ,
int V_320 , struct V_212 * V_75 )
{
int V_321 = V_75 -> V_197 . V_7 ;
int V_322 = ( 1 << V_75 -> V_211 ) ;
if ( V_319 < V_321 || V_319 + V_320 > V_321 + V_322 )
return - V_189 ;
return 0 ;
}
int F_171 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_249 = V_287 -> V_292 ;
struct V_212 * V_75 ;
struct V_214 * V_77 ;
int V_323 = F_159 ( V_116 -> V_118 ) / V_32 -> V_62 . V_324 ;
int V_325 ;
int V_192 ;
T_3 V_326 ;
int V_327 ;
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_96 ( V_32 , V_33 , V_192 , V_252 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_165 ( V_116 -> V_118 ) ) {
V_44 = - V_189 ;
goto V_328;
}
V_326 = F_162 ( V_116 -> V_118 ) ;
V_327 = ( V_326 >> 17 ) & 0x7f ;
if ( V_327 != 0 && -- V_327 != V_33 ) {
V_44 = - V_189 ;
goto V_328;
}
if ( F_163 ( V_116 -> V_118 ) ) {
if ( F_164 ( V_116 -> V_118 ) ) {
V_44 = - V_189 ;
goto V_328;
}
if ( ! F_165 ( V_116 -> V_118 ) ) {
V_44 = - V_189 ;
goto V_328;
}
}
V_325 = F_158 ( V_116 -> V_118 ) ;
if ( ! V_325 ) {
V_44 = F_50 ( V_32 , V_33 , V_323 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_328;
V_44 = F_170 ( V_32 , V_33 , V_323 ,
F_161 ( V_116 -> V_118 ) , V_75 ) ;
if ( V_44 )
goto V_329;
V_77 -> V_75 = V_75 ;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_329;
if ( ! V_325 ) {
F_173 ( & V_75 -> V_210 ) ;
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
}
F_101 ( V_32 , V_33 , V_23 , V_192 ) ;
return 0 ;
V_329:
if ( ! V_325 )
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
V_328:
F_100 ( V_32 , V_33 , V_23 , V_192 ) ;
return V_44 ;
}
int F_174 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_249 = V_287 -> V_292 ;
struct V_214 * V_77 ;
int V_192 ;
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_96 ( V_32 , V_33 , V_192 , V_251 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_328;
if ( V_77 -> V_75 )
F_175 ( & V_77 -> V_75 -> V_210 ) ;
F_101 ( V_32 , V_33 , V_23 , V_192 ) ;
return 0 ;
V_328:
F_100 ( V_32 , V_33 , V_23 , V_192 ) ;
return V_44 ;
}
int F_176 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_249 = V_287 -> V_292 ;
struct V_214 * V_77 ;
int V_192 ;
V_192 = V_249 & F_48 ( V_32 ) ;
V_44 = F_50 ( V_32 , V_33 , V_192 , V_23 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( V_77 -> V_197 . V_190 == V_251 ) {
struct V_293 * V_330 = F_177 (
& V_37 ( V_32 ) -> V_331 . V_332 ,
V_77 -> V_213 , NULL ) ;
if ( NULL == V_330 || NULL == V_288 -> V_118 ) {
V_44 = - V_45 ;
goto V_59;
}
memcpy ( V_288 -> V_118 , V_330 , sizeof( * V_330 ) ) ;
V_44 = 0 ;
} else if ( V_77 -> V_197 . V_190 == V_252 ) {
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
} else {
V_44 = - V_187 ;
goto V_59;
}
V_59:
F_55 ( V_32 , V_33 , V_192 , V_23 ) ;
return V_44 ;
}
static int F_178 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_333 ) & 0xffffff ;
}
static int F_179 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_334 ) & 0xffffff ;
}
static T_3 F_180 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_272 ) & 0x1ffffff ;
}
static void F_181 ( struct V_31 * V_32 , struct V_286 * V_287 ,
struct V_122 * V_335 )
{
T_3 V_139 = V_287 -> V_292 & 0xffffff ;
T_3 V_336 = 0 ;
if ( F_182 ( V_32 , V_139 , & V_336 ) )
return;
V_335 -> V_336 = F_46 ( V_336 ) ;
}
int F_183 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_139 = V_287 -> V_292 & 0x7fffff ;
struct V_212 * V_75 ;
struct V_205 * V_66 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_323 = F_166 ( V_140 ) / V_32 -> V_62 . V_324 ;
int V_337 = F_168 ( V_140 ) ;
struct V_218 * V_338 ;
struct V_218 * V_339 ;
int V_340 = F_178 ( V_140 ) ;
int V_341 = F_179 ( V_140 ) ;
T_3 V_272 = F_180 ( V_140 ) & 0xffffff ;
int V_342 = ( F_180 ( V_140 ) >> 24 ) & 1 ;
struct V_220 * V_72 ;
int V_207 = F_40 ( V_140 -> V_207 ) & 0xffffff ;
V_44 = F_184 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_95 ( V_32 , V_33 , V_139 , V_247 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_66 -> V_207 = V_207 ;
V_66 -> V_131 = 0 ;
V_66 -> V_152 = 0 ;
V_66 -> V_161 = 0 ;
V_66 -> V_168 = 0 ;
V_66 -> V_343 = 0 ;
V_66 -> V_170 = 0 ;
V_66 -> V_175 = 0 ;
V_66 -> V_344 = F_40 ( V_140 -> V_128 ) ;
V_44 = F_50 ( V_32 , V_33 , V_323 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_328;
V_44 = F_170 ( V_32 , V_33 , V_323 , V_337 , V_75 ) ;
if ( V_44 )
goto V_345;
V_44 = F_50 ( V_32 , V_33 , V_340 , V_21 , & V_338 ) ;
if ( V_44 )
goto V_345;
if ( V_341 != V_340 ) {
V_44 = F_50 ( V_32 , V_33 , V_341 , V_21 , & V_339 ) ;
if ( V_44 )
goto V_346;
} else
V_339 = V_338 ;
if ( V_342 ) {
V_44 = F_50 ( V_32 , V_33 , V_272 , V_22 , & V_72 ) ;
if ( V_44 )
goto V_347;
}
F_181 ( V_32 , V_287 , V_140 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_348;
F_173 ( & V_75 -> V_210 ) ;
V_66 -> V_75 = V_75 ;
F_173 ( & V_338 -> V_210 ) ;
V_66 -> V_338 = V_338 ;
F_173 ( & V_339 -> V_210 ) ;
V_66 -> V_339 = V_339 ;
if ( V_341 != V_340 )
F_55 ( V_32 , V_33 , V_341 , V_21 ) ;
if ( V_342 ) {
F_173 ( & V_72 -> V_210 ) ;
F_55 ( V_32 , V_33 , V_272 , V_22 ) ;
V_66 -> V_72 = V_72 ;
}
F_55 ( V_32 , V_33 , V_340 , V_21 ) ;
F_55 ( V_32 , V_33 , V_323 , V_24 ) ;
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_348:
if ( V_342 )
F_55 ( V_32 , V_33 , V_272 , V_22 ) ;
V_347:
if ( V_341 != V_340 )
F_55 ( V_32 , V_33 , V_341 , V_21 ) ;
V_346:
F_55 ( V_32 , V_33 , V_340 , V_21 ) ;
V_345:
F_55 ( V_32 , V_33 , V_323 , V_24 ) ;
V_328:
F_100 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static int F_185 ( struct V_349 * V_350 )
{
return F_40 ( V_350 -> V_300 ) & 0xfffffff8 ;
}
static int F_186 ( struct V_349 * V_350 )
{
int V_351 = V_350 -> V_351 & 0x1f ;
int V_303 = ( V_350 -> V_304 & 0x3f ) + 12 ;
if ( V_351 + 5 < V_303 )
return 1 ;
return 1 << ( V_351 + 5 - V_303 ) ;
}
static int F_187 ( struct V_352 * V_353 )
{
return F_40 ( V_353 -> V_300 ) & 0xfffffff8 ;
}
static int F_188 ( struct V_352 * V_353 )
{
int V_354 = ( F_40 ( V_353 -> V_355 ) >> 24 ) & 0x1f ;
int V_303 = ( V_353 -> V_304 & 0x3f ) + 12 ;
if ( V_354 + 5 < V_303 )
return 1 ;
return 1 << ( V_354 + 5 - V_303 ) ;
}
int F_189 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_356 = V_287 -> V_292 ;
int V_7 = ( V_33 << 10 ) | V_356 ;
struct V_349 * V_350 = V_116 -> V_118 ;
int V_323 = F_185 ( V_350 ) / V_32 -> V_62 . V_324 ;
int V_337 = F_186 ( V_350 ) ;
struct V_216 * V_254 ;
struct V_212 * V_75 ;
V_44 = F_77 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_97 ( V_32 , V_33 , V_7 , V_256 , & V_254 ) ;
if ( V_44 )
goto V_357;
V_44 = F_50 ( V_32 , V_33 , V_323 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_358;
V_44 = F_170 ( V_32 , V_33 , V_323 , V_337 , V_75 ) ;
if ( V_44 )
goto V_359;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_359;
F_173 ( & V_75 -> V_210 ) ;
V_254 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
F_101 ( V_32 , V_33 , V_27 , V_7 ) ;
return 0 ;
V_359:
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
V_358:
F_100 ( V_32 , V_33 , V_27 , V_7 ) ;
V_357:
F_93 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return V_44 ;
}
int F_190 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
T_2 V_360 = V_287 -> V_291 ;
if ( V_360 != 1 )
return - V_189 ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
return V_44 ;
}
static int F_191 ( struct V_31 * V_32 , int V_33 , int V_319 ,
int V_361 , struct V_212 * * V_11 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_212 * V_75 ;
int V_44 = - V_45 ;
F_51 ( F_52 ( V_32 ) ) ;
F_59 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_170 ( V_32 , V_33 , V_319 , V_361 , V_75 ) ) {
* V_11 = V_75 ;
V_75 -> V_197 . V_190 = V_75 -> V_197 . V_2 ;
V_75 -> V_197 . V_2 = V_3 ;
V_44 = 0 ;
break;
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_44 ;
}
static int F_192 ( struct V_31 * V_32 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
enum V_362 V_363 , T_2 V_33 )
{
T_3 V_143 ;
T_3 V_139 ;
struct V_122 * V_123 ;
enum V_124 V_125 ;
int V_36 ;
int V_364 ;
V_123 = V_116 -> V_118 + 8 ;
V_143 = ( F_40 ( V_123 -> V_128 ) >> 16 ) & 0xff ;
V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
if ( V_33 != F_14 ( V_32 ) ) {
V_123 -> V_318 &= ~ V_365 ;
if ( V_123 -> V_366 )
return - V_189 ;
}
switch ( V_143 ) {
case V_133 :
case V_134 :
case V_135 :
switch ( V_363 ) {
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
if ( V_33 != F_14 ( V_32 ) )
if ( V_125 & V_136 ) {
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_372 [ V_36 ] != V_373 )
V_364 = F_193 ( V_32 , V_33 , V_36 ) ;
else
V_364 = 1 ;
if ( V_123 -> V_130 . V_132 >= V_364 )
return - V_45 ;
}
if ( V_125 & V_137 ) {
V_36 = ( V_123 -> V_138 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_372 [ V_36 ] != V_373 )
V_364 = F_193 ( V_32 , V_33 , V_36 ) ;
else
V_364 = 1 ;
if ( V_123 -> V_138 . V_132 >= V_364 )
return - V_45 ;
}
break;
default:
break;
}
break;
case V_148 :
V_139 = V_287 -> V_292 & 0x7fffff ;
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_363 == V_367 &&
V_33 != F_14 ( V_32 ) &&
F_45 ( V_32 , V_139 ) &&
! F_194 ( V_32 , V_33 , V_36 ) ) {
F_61 ( V_32 , L_26 ,
V_204 , V_33 , V_36 ) ;
return - V_189 ;
}
break;
default:
break;
}
return 0 ;
}
int F_195 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
struct V_374 V_75 ;
T_5 * V_375 = V_116 -> V_118 ;
T_1 * V_376 = ( T_1 * ) V_375 ;
int V_83 ;
struct V_212 * V_377 = NULL ;
int V_319 = F_160 ( V_375 [ 0 ] ) ;
int V_378 = V_287 -> V_292 ;
int V_44 ;
V_44 = F_191 ( V_32 , V_33 , V_319 , V_378 , & V_377 ) ;
if ( V_44 )
return V_44 ;
V_75 . V_379 = 0 ;
V_75 . V_211 = 0 ;
V_75 . V_303 = 0 ;
for ( V_83 = 0 ; V_83 < V_378 ; ++ V_83 )
V_376 [ V_83 + 2 ] = ( F_160 ( V_375 [ V_83 + 2 ] ) & ~ 1ULL ) ;
V_44 = F_196 ( V_32 , & V_75 , F_160 ( V_375 [ 0 ] ) , V_378 ,
( ( T_1 * ) V_375 + 2 ) ) ;
if ( V_377 )
F_55 ( V_32 , V_33 , V_377 -> V_197 . V_7 , V_24 ) ;
return V_44 ;
}
int F_197 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_356 = V_287 -> V_292 ;
int V_7 = V_356 | ( V_33 << 10 ) ;
struct V_216 * V_254 ;
int V_44 ;
V_44 = F_97 ( V_32 , V_33 , V_7 , V_217 , & V_254 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_254 -> V_75 -> V_197 . V_7 , V_24 , NULL ) ;
if ( V_44 )
goto V_328;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_329;
F_175 ( & V_254 -> V_75 -> V_210 ) ;
F_55 ( V_32 , V_33 , V_254 -> V_75 -> V_197 . V_7 , V_24 ) ;
F_101 ( V_32 , V_33 , V_27 , V_7 ) ;
F_93 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return 0 ;
V_329:
F_55 ( V_32 , V_33 , V_254 -> V_75 -> V_197 . V_7 , V_24 ) ;
V_328:
F_100 ( V_32 , V_33 , V_27 , V_7 ) ;
return V_44 ;
}
int F_198 ( struct V_31 * V_32 , int V_33 , struct V_380 * V_381 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_382 * V_383 ;
struct V_115 * V_384 ;
T_3 V_292 = 0 ;
int V_44 ;
int V_7 ;
struct V_216 * V_385 ;
if ( ! V_38 -> V_41 . V_42 . V_283 )
return - V_45 ;
if ( V_33 < 0 || V_33 > V_32 -> V_51 -> V_52 ||
V_33 == V_32 -> V_62 . V_113 ||
! V_38 -> V_41 . V_42 . V_283 [ V_33 ] . V_386 )
return 0 ;
V_383 = & V_38 -> V_41 . V_42 . V_283 [ V_33 ] . V_383 [ V_381 -> type ] ;
if ( V_383 -> V_356 < 0 )
return 0 ;
F_35 ( & V_38 -> V_41 . V_42 . V_387 [ V_33 ] ) ;
V_7 = ( V_33 << 10 ) | V_383 -> V_356 ;
V_44 = F_50 ( V_32 , V_33 , V_7 , V_27 , & V_385 ) ;
if ( V_44 )
goto V_388;
if ( V_385 -> V_197 . V_190 != V_256 ) {
V_44 = - V_45 ;
goto V_389;
}
V_384 = F_199 ( V_32 ) ;
if ( F_200 ( V_384 ) ) {
V_44 = F_201 ( V_384 ) ;
goto V_389;
}
if ( V_381 -> type == V_390 ) {
++ V_383 -> V_391 ;
V_381 -> V_392 . V_265 . V_391 = F_202 ( V_383 -> V_391 ) ;
}
memcpy ( V_384 -> V_118 , ( T_2 * ) V_381 , 28 ) ;
V_292 = ( V_33 & 0xff ) | ( ( V_383 -> V_356 & 0x3ff ) << 16 ) ;
V_44 = F_203 ( V_32 , V_384 -> V_393 , V_292 , 0 ,
V_394 , V_395 ,
V_396 ) ;
F_55 ( V_32 , V_33 , V_7 , V_27 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_387 [ V_33 ] ) ;
F_204 ( V_32 , V_384 ) ;
return V_44 ;
V_389:
F_55 ( V_32 , V_33 , V_7 , V_27 ) ;
V_388:
F_37 ( & V_38 -> V_41 . V_42 . V_387 [ V_33 ] ) ;
return V_44 ;
}
int F_205 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_356 = V_287 -> V_292 ;
int V_7 = V_356 | ( V_33 << 10 ) ;
struct V_216 * V_254 ;
int V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_7 , V_27 , & V_254 ) ;
if ( V_44 )
return V_44 ;
if ( V_254 -> V_197 . V_190 != V_256 ) {
V_44 = - V_45 ;
goto V_329;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_329:
F_55 ( V_32 , V_33 , V_7 , V_27 ) ;
return V_44 ;
}
int F_206 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_257 = V_287 -> V_292 ;
struct V_352 * V_353 = V_116 -> V_118 ;
int V_323 = F_187 ( V_353 ) / V_32 -> V_62 . V_324 ;
struct V_218 * V_69 = NULL ;
struct V_212 * V_75 ;
V_44 = F_98 ( V_32 , V_33 , V_257 , V_259 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_323 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_358;
V_44 = F_170 ( V_32 , V_33 , V_323 , F_188 ( V_353 ) , V_75 ) ;
if ( V_44 )
goto V_359;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_359;
F_173 ( & V_75 -> V_210 ) ;
V_69 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
F_101 ( V_32 , V_33 , V_21 , V_257 ) ;
return 0 ;
V_359:
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
V_358:
F_100 ( V_32 , V_33 , V_21 , V_257 ) ;
return V_44 ;
}
int F_207 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_257 = V_287 -> V_292 ;
struct V_218 * V_69 = NULL ;
V_44 = F_98 ( V_32 , V_33 , V_257 , V_219 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_358;
F_175 ( & V_69 -> V_75 -> V_210 ) ;
F_101 ( V_32 , V_33 , V_21 , V_257 ) ;
return 0 ;
V_358:
F_100 ( V_32 , V_33 , V_21 , V_257 ) ;
return V_44 ;
}
int F_208 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_257 = V_287 -> V_292 ;
struct V_218 * V_69 ;
int V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_257 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_197 . V_190 != V_259 )
goto V_329;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_329:
F_55 ( V_32 , V_33 , V_257 , V_21 ) ;
return V_44 ;
}
static int F_209 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 ,
struct V_218 * V_69 )
{
int V_44 ;
struct V_212 * V_397 ;
struct V_212 * V_75 ;
struct V_352 * V_353 = V_116 -> V_118 ;
int V_323 = F_187 ( V_353 ) / V_32 -> V_62 . V_324 ;
V_44 = F_50 ( V_32 , V_33 , V_69 -> V_75 -> V_197 . V_7 , V_24 , & V_397 ) ;
if ( V_44 )
return V_44 ;
if ( V_397 != V_69 -> V_75 ) {
V_44 = - V_45 ;
goto V_329;
}
V_44 = F_50 ( V_32 , V_33 , V_323 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_329;
V_44 = F_170 ( V_32 , V_33 , V_323 , F_188 ( V_353 ) , V_75 ) ;
if ( V_44 )
goto V_398;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_398;
F_175 ( & V_397 -> V_210 ) ;
F_55 ( V_32 , V_33 , V_397 -> V_197 . V_7 , V_24 ) ;
F_173 ( & V_75 -> V_210 ) ;
V_69 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
return 0 ;
V_398:
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
V_329:
F_55 ( V_32 , V_33 , V_397 -> V_197 . V_7 , V_24 ) ;
return V_44 ;
}
int F_210 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_257 = V_287 -> V_292 ;
struct V_218 * V_69 ;
int V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_257 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_197 . V_190 != V_259 )
goto V_329;
if ( V_287 -> V_291 == 0 ) {
V_44 = F_209 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 , V_69 ) ;
goto V_329;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_329:
F_55 ( V_32 , V_33 , V_257 , V_21 ) ;
return V_44 ;
}
static int F_211 ( struct V_301 * V_302 )
{
int V_399 = ( F_40 ( V_302 -> V_400 ) >> 24 ) & 0xf ;
int V_310 = V_302 -> V_401 & 7 ;
int V_303 = ( V_302 -> V_304 & 0x3f ) + 12 ;
if ( V_399 + V_310 + 4 < V_303 )
return 1 ;
return 1 << ( V_399 + V_310 + 4 - V_303 ) ;
}
int F_212 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_272 = V_287 -> V_292 ;
struct V_212 * V_75 ;
struct V_220 * V_72 = NULL ;
struct V_301 * V_302 = V_116 -> V_118 ;
int V_323 = F_167 ( V_302 ) / V_32 -> V_62 . V_324 ;
if ( V_272 != ( F_40 ( V_302 -> V_400 ) & 0xffffff ) )
return - V_45 ;
V_44 = F_99 ( V_32 , V_33 , V_272 , V_261 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_323 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_328;
V_44 = F_170 ( V_32 , V_33 , V_323 , F_211 ( V_302 ) ,
V_75 ) ;
if ( V_44 )
goto V_345;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_345;
F_173 ( & V_75 -> V_210 ) ;
V_72 -> V_75 = V_75 ;
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
F_101 ( V_32 , V_33 , V_22 , V_272 ) ;
return 0 ;
V_345:
F_55 ( V_32 , V_33 , V_75 -> V_197 . V_7 , V_24 ) ;
V_328:
F_100 ( V_32 , V_33 , V_22 , V_272 ) ;
return V_44 ;
}
int F_213 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_272 = V_287 -> V_292 ;
struct V_220 * V_72 = NULL ;
V_44 = F_99 ( V_32 , V_33 , V_272 , V_221 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_328;
F_175 ( & V_72 -> V_75 -> V_210 ) ;
if ( V_72 -> V_69 )
F_175 ( & V_72 -> V_69 -> V_210 ) ;
F_101 ( V_32 , V_33 , V_22 , V_272 ) ;
return 0 ;
V_328:
F_100 ( V_32 , V_33 , V_22 , V_272 ) ;
return V_44 ;
}
int F_214 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_272 = V_287 -> V_292 ;
struct V_220 * V_72 ;
V_44 = F_50 ( V_32 , V_33 , V_272 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_197 . V_190 != V_261 ) {
V_44 = - V_187 ;
goto V_59;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_59:
F_55 ( V_32 , V_33 , V_272 , V_22 ) ;
return V_44 ;
}
int F_215 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_272 = V_287 -> V_292 ;
struct V_220 * V_72 ;
V_44 = F_50 ( V_32 , V_33 , V_272 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_197 . V_190 != V_261 ) {
V_44 = - V_187 ;
goto V_59;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_59:
F_55 ( V_32 , V_33 , V_272 , V_22 ) ;
return V_44 ;
}
int F_216 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_139 = V_287 -> V_292 & 0x7fffff ;
struct V_205 * V_66 ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_197 . V_190 != V_247 ) {
V_44 = - V_187 ;
goto V_59;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_59:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_217 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
struct V_122 * V_335 = V_116 -> V_118 + 8 ;
F_181 ( V_32 , V_287 , V_335 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_216 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
}
static int F_184 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
enum V_124 V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
T_2 V_402 ;
int V_36 = F_133 (
V_32 , V_33 , ( V_140 -> V_130 . V_131 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_402 = ( V_140 -> V_130 . V_131 & ~ ( 1 << 6 ) ) |
( ( V_36 & 1 ) << 6 ) ;
if ( V_125 & ( V_136 | V_403 ) ||
V_140 -> V_130 . V_131 || F_41 ( V_32 , V_36 + 1 ) ) {
V_140 -> V_130 . V_131 = V_402 ;
}
if ( V_125 & V_137 ) {
V_36 = F_133 (
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
static int F_218 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
T_1 V_274 ;
int V_36 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
T_2 V_117 = * ( T_2 * ) ( V_116 -> V_118 + 64 ) ;
T_2 V_404 ;
V_36 = ( V_117 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) && ( V_127 != V_148 ) ) {
V_404 = V_140 -> V_130 . V_182 & 0x7f ;
if ( F_126 ( V_32 , V_33 , V_36 , V_404 , & V_274 ) )
return - V_191 ;
}
return 0 ;
}
int F_219 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_139 = V_287 -> V_292 & 0x7fffff ;
struct V_205 * V_66 ;
T_2 V_405 ;
V_126 V_406 = V_140 -> V_152 ;
T_2 V_407 = V_140 -> V_130 . V_161 ;
T_2 V_408 = V_140 -> V_130 . V_168 ;
T_2 V_409 = V_140 -> V_130 . V_172 ;
T_2 V_410 = V_140 -> V_130 . V_170 ;
T_2 V_411 = V_140 -> V_130 . V_175 ;
V_44 = F_184 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_192 ( V_32 , V_287 , V_116 , V_367 , V_33 ) ;
if ( V_44 )
return V_44 ;
if ( F_218 ( V_32 , V_33 , V_140 , V_116 ) )
return - V_45 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_181 ( V_32 , V_287 , V_140 ) ;
V_405 = V_140 -> V_130 . V_131 ;
V_44 = F_43 ( V_32 , V_116 , V_33 , V_139 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_197 . V_190 != V_247 ) {
V_44 = - V_187 ;
goto V_59;
}
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
V_59:
if ( ! V_44 ) {
V_66 -> V_131 = V_405 ;
V_66 -> V_152 = V_406 ;
V_66 -> V_161 = V_407 ;
V_66 -> V_168 = V_408 ;
V_66 -> V_343 = V_409 ;
V_66 -> V_170 = V_410 ;
V_66 -> V_175 = V_411 ;
}
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_220 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
struct V_122 * V_335 = V_116 -> V_118 + 8 ;
V_44 = F_184 ( V_32 , V_33 , V_335 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_192 ( V_32 , V_287 , V_116 , V_368 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_181 ( V_32 , V_287 , V_335 ) ;
return F_216 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
}
int F_221 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
struct V_122 * V_335 = V_116 -> V_118 + 8 ;
V_44 = F_184 ( V_32 , V_33 , V_335 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_192 ( V_32 , V_287 , V_116 , V_369 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_181 ( V_32 , V_287 , V_335 ) ;
return F_216 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
}
int F_222 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
struct V_122 * V_335 = V_116 -> V_118 + 8 ;
int V_44 = F_184 ( V_32 , V_33 , V_335 , V_116 ) ;
if ( V_44 )
return V_44 ;
F_181 ( V_32 , V_287 , V_335 ) ;
return F_216 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
}
int F_223 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
struct V_122 * V_335 = V_116 -> V_118 + 8 ;
V_44 = F_184 ( V_32 , V_33 , V_335 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_192 ( V_32 , V_287 , V_116 , V_370 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_181 ( V_32 , V_287 , V_335 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_216 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
}
int F_224 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
struct V_122 * V_335 = V_116 -> V_118 + 8 ;
V_44 = F_184 ( V_32 , V_33 , V_335 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_192 ( V_32 , V_287 , V_116 , V_371 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_181 ( V_32 , V_287 , V_335 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_216 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
}
int F_225 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_139 = V_287 -> V_292 & 0x7fffff ;
struct V_205 * V_66 ;
V_44 = F_95 ( V_32 , V_33 , V_139 , V_246 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
if ( V_44 )
goto V_328;
F_175 ( & V_66 -> V_75 -> V_210 ) ;
F_175 ( & V_66 -> V_338 -> V_210 ) ;
F_175 ( & V_66 -> V_339 -> V_210 ) ;
if ( V_66 -> V_72 )
F_175 ( & V_66 -> V_72 -> V_210 ) ;
F_101 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_328:
F_100 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static struct V_412 * F_226 ( struct V_31 * V_32 , int V_33 ,
struct V_205 * V_413 , T_2 * V_414 )
{
struct V_412 * V_11 ;
F_59 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_414 , V_414 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_227 ( struct V_31 * V_32 , int V_33 , struct V_205 * V_413 ,
T_2 * V_414 , enum V_415 V_416 ,
enum V_417 V_418 , T_1 V_419 )
{
struct V_412 * V_11 ;
int V_44 ;
V_11 = F_21 ( sizeof *V_11 , V_89 ) ;
if ( ! V_11 )
return - V_90 ;
F_51 ( & V_413 -> V_209 ) ;
if ( F_226 ( V_32 , V_33 , V_413 , V_414 ) ) {
F_31 ( V_11 ) ;
V_44 = - V_17 ;
} else {
memcpy ( V_11 -> V_414 , V_414 , 16 ) ;
V_11 -> V_416 = V_416 ;
V_11 -> V_418 = V_418 ;
V_11 -> V_419 = V_419 ;
F_78 ( & V_11 -> V_235 , & V_413 -> V_208 ) ;
V_44 = 0 ;
}
F_53 ( & V_413 -> V_209 ) ;
return V_44 ;
}
static int F_228 ( struct V_31 * V_32 , int V_33 , struct V_205 * V_413 ,
T_2 * V_414 , enum V_415 V_416 ,
enum V_417 V_418 , T_1 * V_419 )
{
struct V_412 * V_11 ;
int V_44 ;
F_51 ( & V_413 -> V_209 ) ;
V_11 = F_226 ( V_32 , V_33 , V_413 , V_414 ) ;
if ( ! V_11 || V_11 -> V_416 != V_416 || V_11 -> V_418 != V_418 )
V_44 = - V_45 ;
else {
* V_419 = V_11 -> V_419 ;
F_94 ( & V_11 -> V_235 ) ;
F_31 ( V_11 ) ;
V_44 = 0 ;
}
F_53 ( & V_413 -> V_209 ) ;
return V_44 ;
}
static int F_229 ( struct V_31 * V_32 , int V_33 , struct V_420 * V_66 ,
T_2 V_414 [ 16 ] , int V_421 , enum V_415 V_416 ,
enum V_417 type , T_1 * V_419 )
{
switch ( V_32 -> V_62 . V_422 ) {
case V_423 : {
int V_36 = F_133 ( V_32 , V_33 , V_414 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return F_230 ( V_32 , V_66 , V_414 , V_36 ,
V_421 , V_416 ,
V_419 ) ;
}
case V_424 :
if ( V_416 == V_425 ) {
int V_36 = F_133 ( V_32 , V_33 , V_414 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
V_414 [ 5 ] = V_36 ;
}
return F_231 ( V_32 , V_66 , V_414 ,
V_421 , V_416 , type ) ;
default:
return - V_45 ;
}
}
static int F_232 ( struct V_31 * V_32 , struct V_420 * V_66 ,
T_2 V_414 [ 16 ] , enum V_415 V_416 ,
enum V_417 type , T_1 V_419 )
{
switch ( V_32 -> V_62 . V_422 ) {
case V_423 :
return F_233 ( V_32 , V_419 ) ;
case V_424 :
return F_234 ( V_32 , V_66 , V_414 , V_416 , type ) ;
default:
return - V_45 ;
}
}
static int F_235 ( struct V_31 * V_32 , int V_33 ,
T_2 * V_414 , enum V_415 V_416 )
{
int V_426 ;
if ( V_416 != V_425 )
return 0 ;
if ( V_32 -> V_62 . V_422 == V_424 ||
V_32 -> V_62 . V_422 == V_423 ) {
V_426 = F_133 ( V_32 , V_33 , V_414 [ 5 ] ) ;
if ( V_426 < 0 )
return - V_45 ;
V_414 [ 5 ] = V_426 ;
}
return 0 ;
}
int F_236 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
struct V_420 V_66 ;
T_2 * V_414 = V_116 -> V_118 ;
enum V_415 V_416 = ( V_287 -> V_292 >> 28 ) & 0x7 ;
int V_44 ;
int V_139 ;
struct V_205 * V_413 ;
T_1 V_419 = 0 ;
int V_427 = V_287 -> V_291 ;
int V_421 = V_287 -> V_292 >> 31 ;
T_2 V_428 = 2 ;
enum V_417 type = ( V_414 [ 7 ] & V_428 ) >> 1 ;
V_139 = V_287 -> V_292 & 0xffffff ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_413 ) ;
if ( V_44 )
return V_44 ;
V_66 . V_139 = V_139 ;
if ( V_427 ) {
V_44 = F_229 ( V_32 , V_33 , & V_66 , V_414 , V_421 , V_416 ,
type , & V_419 ) ;
if ( V_44 ) {
F_73 ( L_27 , V_139 ) ;
goto V_329;
}
V_44 = F_227 ( V_32 , V_33 , V_413 , V_414 , V_416 , type , V_419 ) ;
if ( V_44 )
goto V_429;
} else {
V_44 = F_235 ( V_32 , V_33 , V_414 , V_416 ) ;
if ( V_44 )
goto V_329;
V_44 = F_228 ( V_32 , V_33 , V_413 , V_414 , V_416 , type , & V_419 ) ;
if ( V_44 )
goto V_329;
V_44 = F_232 ( V_32 , & V_66 , V_414 , V_416 , type , V_419 ) ;
if ( V_44 )
F_73 ( L_28 ,
V_139 , V_419 ) ;
}
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
V_429:
F_232 ( V_32 , & V_66 , V_414 , V_416 , type , V_419 ) ;
V_329:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static int F_237 ( int V_33 , struct V_430 * V_431 ,
struct V_275 * V_432 )
{
struct V_277 * V_11 , * V_200 ;
T_5 V_433 ;
if ( ! F_238 ( V_431 -> V_434 . V_435 ) &&
! F_239 ( V_431 -> V_434 . V_435 ) ) {
F_127 (res, tmp, rlist, list) {
V_433 = F_240 ( V_11 -> V_274 << 16 ) ;
if ( F_241 ( ( T_2 * ) & V_433 , V_431 -> V_434 . V_435 ) )
return 0 ;
}
F_73 ( L_29 ,
V_431 -> V_434 . V_435 , V_33 ) ;
return - V_45 ;
}
return 0 ;
}
static void F_242 ( struct V_436 * V_437 ,
struct V_430 * V_431 )
{
if ( F_238 ( V_431 -> V_434 . V_435 ) ||
F_239 ( V_431 -> V_434 . V_435 ) ) {
struct V_438 * V_434 =
(struct V_438 * ) V_431 ;
struct V_430 * V_439 = (struct V_430 * ) ( V_434 + 1 ) ;
bool V_440 = V_439 -> V_320 == 0 && V_439 -> V_192 == 0 &&
V_439 -> V_441 == 0 ;
if ( V_440 )
V_437 -> V_442 = F_202 ( V_443 ) ;
}
}
static int F_243 ( struct V_31 * V_32 , int V_33 ,
struct V_115 * V_116 ,
struct V_275 * V_432 , int V_444 )
{
struct V_277 * V_11 , * V_200 ;
T_2 V_36 ;
struct V_436 * V_437 ;
struct V_438 * V_431 ;
struct V_445 * V_446 ;
struct V_447 * V_448 ;
T_5 V_433 = 0 ;
T_5 V_449 = F_240 ( V_450 << 16 ) ;
V_437 = (struct V_436 * ) V_116 -> V_118 ;
V_36 = V_437 -> V_36 ;
V_431 = (struct V_438 * ) ( V_437 + 1 ) ;
switch ( V_444 ) {
case V_451 :
V_446 =
(struct V_445 * ) ( V_431 + 1 ) ;
memmove ( V_446 , V_431 ,
sizeof( * V_446 ) + sizeof( * V_448 ) ) ;
break;
case V_452 :
case V_453 :
V_448 = (struct V_447 * )
( V_431 + 1 ) ;
memmove ( V_448 , V_431 , sizeof( * V_448 ) ) ;
break;
default:
return - V_45 ;
}
F_127 (res, tmp, rlist, list) {
if ( V_36 == V_11 -> V_36 ) {
V_433 = F_240 ( V_11 -> V_274 << 16 ) ;
break;
}
}
if ( ! V_433 ) {
F_73 ( L_30 ,
V_36 ) ;
return - V_45 ;
}
memset ( V_431 , 0 , sizeof( * V_431 ) ) ;
V_431 -> V_320 = sizeof( * V_431 ) >> 2 ;
V_431 -> V_192 = F_202 ( V_454 [ V_455 ] ) ;
memcpy ( V_431 -> V_435 , & V_433 , V_456 ) ;
memcpy ( V_431 -> V_457 , & V_449 , V_456 ) ;
return 0 ;
}
int F_244 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_458 )
{
int V_44 ;
T_3 V_139 = V_287 -> V_292 & 0xffffff ;
struct V_205 * V_413 ;
T_1 V_274 ;
unsigned V_36 ;
T_1 V_459 ;
struct V_460 * V_265 ;
int V_273 ;
V_265 = (struct V_460 * ) V_116 -> V_118 ;
V_459 = F_160 ( V_265 -> V_461 ) ;
if ( V_265 -> V_462 || V_265 -> V_463 ||
( V_459 & ~ V_464 ) )
return - V_189 ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_413 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_31 , V_139 , V_33 ) ;
return V_44 ;
}
V_36 = ( V_413 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_459 & ( 1ULL << V_465 ) ) {
V_273 = V_265 -> V_466 . V_130 . V_182 ;
V_44 = F_126 ( V_32 , V_33 , V_36 ,
V_273 , & V_274 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_32 ,
V_139 , V_273 ) ;
goto V_467;
}
}
V_44 = F_203 ( V_32 , V_116 -> V_393 ,
V_287 -> V_292 , 0 ,
V_468 , V_469 ,
V_396 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_33 , V_139 ) ;
goto V_467;
}
V_467:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_245 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_432 = & V_199 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
int V_44 ;
int V_139 ;
struct V_205 * V_413 ;
struct V_436 * V_437 ;
struct V_430 * V_470 ;
int V_444 ;
if ( V_32 -> V_62 . V_422 !=
V_423 )
return - V_471 ;
V_437 = (struct V_436 * ) V_116 -> V_118 ;
V_437 -> V_36 = F_133 ( V_32 , V_33 , V_437 -> V_36 ) ;
if ( V_437 -> V_36 <= 0 )
return - V_45 ;
V_139 = F_40 ( V_437 -> V_139 ) & 0xffffff ;
V_44 = F_50 ( V_32 , V_33 , V_139 , V_20 , & V_413 ) ;
if ( V_44 ) {
F_73 ( L_34 , V_139 ) ;
return V_44 ;
}
V_470 = (struct V_430 * ) ( V_437 + 1 ) ;
V_444 = F_246 ( F_247 ( V_470 -> V_192 ) ) ;
if ( V_444 == V_455 )
F_242 ( V_437 , V_470 ) ;
if ( V_33 == V_32 -> V_62 . V_113 )
goto V_472;
switch ( V_444 ) {
case V_455 :
if ( F_237 ( V_33 , V_470 , V_432 ) ) {
V_44 = - V_45 ;
goto V_473;
}
break;
case V_474 :
break;
case V_451 :
case V_452 :
case V_453 :
F_248 ( L_35 ) ;
if ( F_243 ( V_32 , V_33 , V_116 , V_432 , V_444 ) ) {
V_44 = - V_45 ;
goto V_473;
}
V_287 -> V_292 +=
sizeof( struct V_438 ) >> 2 ;
break;
default:
F_73 ( L_36 ) ;
V_44 = - V_45 ;
goto V_473;
}
V_472:
V_44 = F_249 ( V_32 , V_116 -> V_393 , & V_287 -> V_267 ,
V_287 -> V_292 , 0 ,
V_475 , V_469 ,
V_396 ) ;
if ( V_44 )
goto V_473;
V_44 = F_77 ( V_32 , V_33 , V_287 -> V_267 , 1 , V_29 , V_139 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_37 ) ;
F_203 ( V_32 , V_287 -> V_267 , 0 , 0 ,
V_476 , V_469 ,
V_396 ) ;
goto V_473;
}
F_173 ( & V_413 -> V_210 ) ;
V_473:
F_55 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_250 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
struct V_205 * V_413 ;
struct V_225 * V_477 ;
if ( V_32 -> V_62 . V_422 !=
V_423 )
return - V_471 ;
V_44 = F_50 ( V_32 , V_33 , V_287 -> V_266 , V_29 , & V_477 ) ;
if ( V_44 )
return V_44 ;
F_55 ( V_32 , V_33 , V_287 -> V_266 , V_29 ) ;
V_44 = F_50 ( V_32 , V_33 , V_477 -> V_139 , V_20 , & V_413 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_93 ( V_32 , V_33 , V_287 -> V_266 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_61 ( V_32 , L_38 ) ;
goto V_59;
}
V_44 = F_203 ( V_32 , V_287 -> V_266 , 0 , 0 ,
V_476 , V_469 ,
V_396 ) ;
if ( ! V_44 )
F_175 ( & V_413 -> V_210 ) ;
V_59:
F_55 ( V_32 , V_33 , V_477 -> V_139 , V_20 ) ;
return V_44 ;
}
int F_251 ( struct V_31 * V_32 , int V_33 ,
struct V_286 * V_287 ,
struct V_115 * V_116 ,
struct V_115 * V_288 ,
struct V_289 * V_265 )
{
int V_44 ;
int V_249 = V_287 -> V_292 & 0xffff ;
V_44 = F_50 ( V_32 , V_33 , V_249 , V_28 , NULL ) ;
if ( V_44 )
return V_44 ;
V_44 = F_172 ( V_32 , V_33 , V_287 , V_116 , V_288 , V_265 ) ;
F_55 ( V_32 , V_33 , V_249 , V_28 ) ;
return V_44 ;
}
static void F_252 ( struct V_31 * V_32 , int V_33 , struct V_205 * V_413 )
{
struct V_412 * V_478 ;
struct V_412 * V_200 ;
struct V_420 V_66 ;
F_127 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_32 -> V_62 . V_422 ) {
case V_423 :
F_233 ( V_32 , V_478 -> V_419 ) ;
break;
case V_424 :
V_66 . V_139 = V_413 -> V_207 ;
( void ) F_234 ( V_32 , & V_66 , V_478 -> V_414 ,
V_478 -> V_416 , V_478 -> V_418 ) ;
break;
}
F_94 ( & V_478 -> V_235 ) ;
F_31 ( V_478 ) ;
}
}
static int F_253 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_479 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_432 = & V_199 -> V_87 [ V_33 ] . V_92 [ type ] ;
struct V_10 * V_184 ;
struct V_10 * V_200 ;
int V_480 ;
V_480 = 0 ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (r, tmp, rlist, list) {
if ( V_184 -> V_188 == V_33 ) {
if ( ! V_184 -> V_481 ) {
if ( V_184 -> V_2 == V_186 ) {
if ( V_479 )
F_24 ( V_32 ,
L_39 ,
F_7 ( type ) ,
V_184 -> V_7 ) ;
++ V_480 ;
} else {
V_184 -> V_190 = V_184 -> V_2 ;
V_184 -> V_2 = V_186 ;
V_184 -> V_481 = 1 ;
}
}
}
}
F_53 ( F_52 ( V_32 ) ) ;
return V_480 ;
}
static int F_254 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type )
{
unsigned long V_482 ;
int V_480 ;
V_482 = V_483 ;
do {
V_480 = F_253 ( V_32 , V_33 , type , 0 ) ;
if ( F_255 ( V_483 , V_482 + 5 * V_484 ) )
break;
if ( V_480 )
F_256 () ;
} while ( V_480 );
if ( V_480 )
V_480 = F_253 ( V_32 , V_33 , type , 1 ) ;
return V_480 ;
}
static void F_257 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_485 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_20 ] ;
struct V_205 * V_66 ;
struct V_205 * V_200 ;
int V_2 ;
T_1 V_266 ;
int V_139 ;
int V_44 ;
V_44 = F_254 ( V_32 , V_33 , V_20 ) ;
if ( V_44 )
F_10 ( V_32 , L_40 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (qp, tmp, qp_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_66 -> V_197 . V_188 == V_33 ) {
V_139 = V_66 -> V_197 . V_7 ;
F_252 ( V_32 , V_33 , V_66 ) ;
V_2 = V_66 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_206 :
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_66 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_20 ] ) ;
F_94 ( & V_66 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
if ( ! F_102 ( V_32 , V_33 , V_139 ) ) {
F_110 ( V_32 , V_139 , 1 ) ;
F_12 ( V_32 , V_33 ,
V_20 , 1 , 0 ) ;
}
F_31 ( V_66 ) ;
V_2 = 0 ;
break;
case V_246 :
if ( ! F_102 ( V_32 , V_33 , V_139 ) )
F_147 ( V_32 , V_139 ) ;
V_2 = V_206 ;
break;
case V_247 :
V_266 = V_33 ;
V_44 = F_203 ( V_32 , V_266 ,
V_66 -> V_207 , 2 ,
V_486 ,
V_469 ,
V_396 ) ;
if ( V_44 )
F_24 ( V_32 , L_41 ,
V_33 , V_66 -> V_207 ) ;
F_175 ( & V_66 -> V_338 -> V_210 ) ;
F_175 ( & V_66 -> V_339 -> V_210 ) ;
F_175 ( & V_66 -> V_75 -> V_210 ) ;
if ( V_66 -> V_72 )
F_175 ( & V_66 -> V_72 -> V_210 ) ;
V_2 = V_246 ;
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
static void F_258 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_487 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_22 ] ;
struct V_220 * V_72 ;
struct V_220 * V_200 ;
int V_2 ;
T_1 V_266 ;
F_259 ( V_488 ) ;
int V_272 ;
int V_44 ;
V_44 = F_254 ( V_32 , V_33 , V_22 ) ;
if ( V_44 )
F_10 ( V_32 , L_42 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (srq, tmp, srq_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_72 -> V_197 . V_188 == V_33 ) {
V_272 = V_72 -> V_197 . V_7 ;
V_2 = V_72 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_221 :
F_125 ( V_32 , V_272 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_72 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_22 ] ) ;
F_94 ( & V_72 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_22 , 1 , 0 ) ;
F_31 ( V_72 ) ;
V_2 = 0 ;
break;
case V_261 :
V_266 = V_33 ;
V_44 = F_203 ( V_32 , V_266 , V_272 , 1 ,
V_489 ,
V_469 ,
V_396 ) ;
if ( V_44 )
F_24 ( V_32 , L_43 ,
V_33 , V_272 ) ;
F_175 ( & V_72 -> V_75 -> V_210 ) ;
if ( V_72 -> V_69 )
F_175 ( & V_72 -> V_69 -> V_210 ) ;
V_2 = V_221 ;
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
static void F_260 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_490 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_21 ] ;
struct V_218 * V_69 ;
struct V_218 * V_200 ;
int V_2 ;
T_1 V_266 ;
F_259 ( V_488 ) ;
int V_257 ;
int V_44 ;
V_44 = F_254 ( V_32 , V_33 , V_21 ) ;
if ( V_44 )
F_10 ( V_32 , L_44 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (cq, tmp, cq_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_69 -> V_197 . V_188 == V_33 && ! F_81 ( & V_69 -> V_210 ) ) {
V_257 = V_69 -> V_197 . V_7 ;
V_2 = V_69 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_219 :
F_122 ( V_32 , V_257 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_69 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_21 ] ) ;
F_94 ( & V_69 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_21 , 1 , 0 ) ;
F_31 ( V_69 ) ;
V_2 = 0 ;
break;
case V_259 :
V_266 = V_33 ;
V_44 = F_203 ( V_32 , V_266 , V_257 , 1 ,
V_491 ,
V_469 ,
V_396 ) ;
if ( V_44 )
F_24 ( V_32 , L_45 ,
V_33 , V_257 ) ;
F_175 ( & V_69 -> V_75 -> V_210 ) ;
V_2 = V_219 ;
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
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_492 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_23 ] ;
struct V_214 * V_77 ;
struct V_214 * V_200 ;
int V_2 ;
T_1 V_266 ;
F_259 ( V_488 ) ;
int V_493 ;
int V_44 ;
V_44 = F_254 ( V_32 , V_33 , V_23 ) ;
if ( V_44 )
F_10 ( V_32 , L_46 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (mpt, tmp, mpt_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_77 -> V_197 . V_188 == V_33 ) {
V_493 = V_77 -> V_197 . V_7 ;
V_2 = V_77 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_215 :
F_118 ( V_32 , V_77 -> V_213 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_77 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_23 ] ) ;
F_94 ( & V_77 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_23 , 1 , 0 ) ;
F_31 ( V_77 ) ;
V_2 = 0 ;
break;
case V_251 :
F_150 ( V_32 , V_77 -> V_213 ) ;
V_2 = V_215 ;
break;
case V_252 :
V_266 = V_33 ;
V_44 = F_203 ( V_32 , V_266 , V_493 , 0 ,
V_494 ,
V_469 ,
V_396 ) ;
if ( V_44 )
F_24 ( V_32 , L_47 ,
V_33 , V_493 ) ;
if ( V_77 -> V_75 )
F_175 ( & V_77 -> V_75 -> V_210 ) ;
V_2 = V_251 ;
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
struct V_198 * V_199 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_495 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_24 ] ;
struct V_212 * V_75 ;
struct V_212 * V_200 ;
int V_2 ;
F_259 ( V_488 ) ;
int V_232 ;
int V_44 ;
V_44 = F_254 ( V_32 , V_33 , V_24 ) ;
if ( V_44 )
F_10 ( V_32 , L_48 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (mtt, tmp, mtt_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_75 -> V_197 . V_188 == V_33 ) {
V_232 = V_75 -> V_197 . V_7 ;
V_2 = V_75 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_115 ( V_32 , V_232 ,
V_75 -> V_211 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_75 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_24 ] ) ;
F_94 ( & V_75 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_12 ( V_32 , V_33 , V_24 ,
1 << V_75 -> V_211 , 0 ) ;
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
static void F_263 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_496 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_29 ] ;
struct V_225 * V_497 ;
struct V_225 * V_200 ;
int V_2 ;
T_1 V_232 ;
int V_44 ;
V_44 = F_254 ( V_32 , V_33 , V_29 ) ;
if ( V_44 )
F_10 ( V_32 , L_49 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (fs_rule, tmp, fs_rule_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_497 -> V_197 . V_188 == V_33 ) {
V_232 = V_497 -> V_197 . V_7 ;
V_2 = V_497 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_226 :
V_44 = F_203 ( V_32 , V_232 , 0 , 0 ,
V_476 ,
V_469 ,
V_396 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_497 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_29 ] ) ;
F_94 ( & V_497 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_31 ( V_497 ) ;
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
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_498 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_27 ] ;
struct V_216 * V_254 ;
struct V_216 * V_200 ;
int V_44 ;
int V_2 ;
F_259 ( V_488 ) ;
int V_356 ;
V_44 = F_254 ( V_32 , V_33 , V_27 ) ;
if ( V_44 )
F_10 ( V_32 , L_50 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (eq, tmp, eq_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_254 -> V_197 . V_188 == V_33 ) {
V_356 = V_254 -> V_197 . V_7 ;
V_2 = V_254 -> V_197 . V_190 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_217 :
F_51 ( F_52 ( V_32 ) ) ;
F_79 ( & V_254 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_27 ] ) ;
F_94 ( & V_254 -> V_197 . V_235 ) ;
F_53 ( F_52 ( V_32 ) ) ;
F_31 ( V_254 ) ;
V_2 = 0 ;
break;
case V_256 :
V_44 = F_203 ( V_32 , V_33 , V_356 & 0x3ff ,
1 , V_499 ,
V_469 ,
V_396 ) ;
if ( V_44 )
F_24 ( V_32 , L_51 ,
V_33 , V_356 & 0x3ff ) ;
F_175 ( & V_254 -> V_75 -> V_210 ) ;
V_2 = V_217 ;
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
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_500 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_28 ] ;
struct V_194 * V_195 ;
struct V_194 * V_200 ;
int V_44 ;
int V_249 ;
V_44 = F_254 ( V_32 , V_33 , V_28 ) ;
if ( V_44 )
F_10 ( V_32 , L_52 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (counter, tmp, counter_list, com.list) {
if ( V_195 -> V_197 . V_188 == V_33 ) {
V_249 = V_195 -> V_197 . V_7 ;
F_79 ( & V_195 -> V_197 . V_9 ,
& V_199 -> V_94 [ V_28 ] ) ;
F_94 ( & V_195 -> V_197 . V_235 ) ;
F_31 ( V_195 ) ;
F_141 ( V_32 , V_249 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
}
}
F_53 ( F_52 ( V_32 ) ) ;
}
static void F_266 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_198 * V_199 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_501 =
& V_199 -> V_87 [ V_33 ] . V_92 [ V_30 ] ;
struct V_223 * V_502 ;
struct V_223 * V_200 ;
int V_44 ;
int V_285 ;
V_44 = F_254 ( V_32 , V_33 , V_30 ) ;
if ( V_44 )
F_10 ( V_32 , L_53 ,
V_33 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_502 -> V_197 . V_188 == V_33 ) {
V_285 = V_502 -> V_197 . V_7 ;
F_79 ( & V_502 -> V_197 . V_9 , & V_199 -> V_94 [ V_30 ] ) ;
F_94 ( & V_502 -> V_197 . V_235 ) ;
F_31 ( V_502 ) ;
F_144 ( V_32 , V_285 ) ;
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
F_130 ( V_32 , V_33 ) ;
F_263 ( V_32 , V_33 ) ;
F_257 ( V_32 , V_33 ) ;
F_258 ( V_32 , V_33 ) ;
F_260 ( V_32 , V_33 ) ;
F_261 ( V_32 , V_33 ) ;
F_264 ( V_32 , V_33 ) ;
F_262 ( V_32 , V_33 ) ;
F_265 ( V_32 , V_33 ) ;
F_266 ( V_32 , V_33 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
}
void F_267 ( struct V_503 * V_504 )
{
struct V_505 * V_506 =
F_3 ( V_504 , struct V_505 , V_506 ) ;
struct V_115 * V_384 ;
struct V_460 * V_507 ;
struct V_31 * V_32 = & V_506 -> V_38 -> V_32 ;
struct V_198 * V_199 =
& V_506 -> V_38 -> V_41 . V_42 . V_43 ;
struct V_275 * V_485 =
& V_199 -> V_87 [ V_506 -> V_33 ] . V_92 [ V_20 ] ;
struct V_205 * V_66 ;
struct V_205 * V_200 ;
T_1 V_508 =
( ( 1ULL << V_509 ) |
( 1ULL << V_510 ) |
( 1ULL << V_511 ) |
( 1ULL << V_512 ) |
( 1ULL << V_513 ) |
( 1ULL << V_514 ) ) ;
T_1 V_515 = ( ( 1ULL << V_516 ) |
( 1ULL << V_517 ) |
( 1ULL << V_518 ) |
( 1ULL << V_519 ) |
( 1ULL << V_520 ) |
( 1ULL << V_521 ) |
( 1ULL << V_522 ) ) ;
int V_44 ;
int V_36 , V_523 = 0 ;
T_2 V_161 ;
if ( F_16 ( V_32 ) ) {
F_10 ( V_32 , L_54 ,
V_506 -> V_33 ) ;
goto V_59;
}
V_384 = F_199 ( V_32 ) ;
if ( F_200 ( V_384 ) )
goto V_59;
if ( V_506 -> V_128 & V_524 )
V_161 = V_162 |
V_163 |
V_164 |
V_165 |
V_166 |
V_167 ;
else if ( ! V_506 -> V_525 )
V_161 = V_162 |
V_167 ;
else
V_161 = V_162 |
V_165 |
V_166 ;
V_507 = V_384 -> V_118 ;
V_507 -> V_462 = F_240 ( 1ULL << V_526 ) ;
F_51 ( F_52 ( V_32 ) ) ;
F_127 (qp, tmp, qp_list, com.list) {
F_53 ( F_52 ( V_32 ) ) ;
if ( V_66 -> V_197 . V_188 == V_506 -> V_33 ) {
if ( V_66 -> V_197 . V_190 != V_247 ||
! V_66 -> V_131 ||
F_45 ( V_32 , V_66 -> V_207 ) ||
V_66 -> V_344 & ( 1 << V_527 ) ) {
F_51 ( F_52 ( V_32 ) ) ;
continue;
}
V_36 = ( V_66 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_36 != V_506 -> V_36 ) {
F_51 ( F_52 ( V_32 ) ) ;
continue;
}
if ( V_133 == ( ( V_66 -> V_344 >> 16 ) & 0xff ) )
V_507 -> V_461 = F_240 ( V_515 ) ;
else
V_507 -> V_461 =
F_240 ( V_515 | V_508 ) ;
if ( V_506 -> V_525 == V_146 ) {
V_507 -> V_466 . V_152 = V_66 -> V_152 ;
V_507 -> V_466 . V_130 . V_161 = V_66 -> V_161 ;
V_507 -> V_466 . V_130 . V_168 = V_66 -> V_168 ;
V_507 -> V_466 . V_130 . V_170 = V_66 -> V_170 ;
V_507 -> V_466 . V_130 . V_172 = V_66 -> V_343 ;
V_507 -> V_466 . V_130 . V_175 = V_66 -> V_175 ;
V_507 -> V_466 . V_130 . V_131 =
V_66 -> V_131 ;
} else {
V_507 -> V_466 . V_152 = V_66 -> V_152 & ~ F_46 ( V_153 ) ;
V_507 -> V_466 . V_130 . V_161 = V_161 ;
V_507 -> V_466 . V_130 . V_170 = V_506 -> V_528 ;
V_507 -> V_466 . V_130 . V_168 =
V_66 -> V_168 | V_169 ;
V_507 -> V_466 . V_130 . V_172 =
V_66 -> V_343 | V_173 | V_174 ;
V_507 -> V_466 . V_130 . V_175 =
V_66 -> V_175 | V_176 | V_177 ;
V_507 -> V_466 . V_130 . V_131 =
V_66 -> V_131 & 0xC7 ;
V_507 -> V_466 . V_130 . V_131 |=
( ( V_506 -> V_529 & 0x7 ) << 3 ) ;
V_507 -> V_462 |=
F_240 ( 1ULL <<
V_530 ) ;
V_507 -> V_466 . V_179 =
V_506 -> V_179 ;
}
V_44 = F_203 ( V_32 , V_384 -> V_393 ,
V_66 -> V_207 & 0xffffff ,
0 , V_468 ,
V_531 , V_396 ) ;
if ( V_44 ) {
F_268 ( V_32 , L_55 ,
V_506 -> V_33 , V_36 , V_66 -> V_207 , V_44 ) ;
V_523 ++ ;
}
}
F_51 ( F_52 ( V_32 ) ) ;
}
F_53 ( F_52 ( V_32 ) ) ;
F_204 ( V_32 , V_384 ) ;
if ( V_523 )
F_61 ( V_32 , L_56 ,
V_523 , V_506 -> V_33 , V_506 -> V_36 ) ;
if ( V_506 -> V_128 & V_532 && ! V_523 &&
V_533 != V_506 -> V_534 )
F_137 ( & V_506 -> V_38 -> V_32 , V_506 -> V_36 ,
V_506 -> V_535 ) ;
V_59:
F_31 ( V_506 ) ;
return;
}
