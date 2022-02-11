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
if ( V_142 -> V_2 . V_169 == F_48 ( V_170 ) ) {
V_140 -> V_130 . V_157 |=
V_164 |
V_163 |
V_166 |
V_167 ;
} else {
V_140 -> V_130 . V_157 |=
V_163 |
V_166 |
V_167 ;
}
} else {
V_140 -> V_130 . V_157 |=
V_163 |
V_168 ;
}
V_140 -> V_130 . V_171 |= V_172 ;
V_140 -> V_130 . V_173 = V_142 -> V_174 ;
V_140 -> V_130 . V_175 |= V_176 ;
if ( V_142 -> V_2 . V_169 == F_48 ( V_170 ) )
V_140 -> V_130 . V_175 |= V_177 ;
else
V_140 -> V_130 . V_175 |= V_178 ;
V_140 -> V_130 . V_179 |= V_180 | V_181 ;
V_140 -> V_130 . V_131 &= 0xC7 ;
V_140 -> V_130 . V_131 |= ( V_142 -> V_2 . V_182 ) << 3 ;
V_140 -> V_183 = V_142 -> V_2 . V_183 ;
}
if ( V_142 -> V_2 . V_184 ) {
V_140 -> V_130 . V_179 |= V_185 ;
V_140 -> V_130 . V_186 = ( 0x80 & V_140 -> V_130 . V_186 ) + V_142 -> V_187 ;
}
V_59:
return V_44 ;
}
static int F_49 ( struct V_31 * V_32 )
{
return V_32 -> V_62 . V_78 - 1 ;
}
static void * F_50 ( struct V_31 * V_32 , T_1 V_7 ,
enum V_18 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
return F_2 ( & V_38 -> V_41 . V_42 . V_43 . V_94 [ type ] ,
V_7 ) ;
}
static int F_51 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type ,
void * V_11 )
{
struct V_10 * V_188 ;
int V_44 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_50 ( V_32 , V_7 , type ) ;
if ( ! V_188 ) {
V_44 = - V_189 ;
goto exit;
}
if ( V_188 -> V_2 == V_190 ) {
V_44 = - V_191 ;
goto exit;
}
if ( V_188 -> V_192 != V_33 ) {
V_44 = - V_193 ;
goto exit;
}
V_188 -> V_194 = V_188 -> V_2 ;
V_188 -> V_2 = V_190 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_188 ;
exit:
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
int F_55 ( struct V_31 * V_32 ,
enum V_18 type ,
T_1 V_7 , int * V_33 )
{
struct V_10 * V_188 ;
int V_44 = - V_195 ;
int V_196 = V_7 ;
if ( type == V_20 )
V_196 &= 0x7fffff ;
F_9 ( F_53 ( V_32 ) ) ;
V_188 = F_50 ( V_32 , V_196 , type ) ;
if ( V_188 ) {
* V_33 = V_188 -> V_192 ;
V_44 = 0 ;
}
F_11 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static void F_56 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_188 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_50 ( V_32 , V_7 , type ) ;
if ( V_188 )
V_188 -> V_2 = V_188 -> V_194 ;
F_54 ( F_53 ( V_32 ) ) ;
}
static int F_57 ( struct V_31 * V_32 , T_2 V_33 , int V_36 ,
int V_197 )
{
struct V_10 * V_188 ;
struct V_198 * V_199 ;
int V_200 = 0 ;
if ( V_197 == F_58 ( V_32 ) )
return V_200 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_50 ( V_32 , V_197 , V_28 ) ;
if ( ! V_188 || V_188 -> V_192 != V_33 ) {
V_200 = - V_45 ;
} else {
V_199 = F_3 ( V_188 , struct V_198 , V_201 ) ;
if ( ! V_199 -> V_36 )
V_199 -> V_36 = V_36 ;
}
F_54 ( F_53 ( V_32 ) ) ;
return V_200 ;
}
static int F_59 ( struct V_31 * V_32 ,
struct V_122 * V_140 , T_2 V_33 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_204 ;
struct V_198 * V_199 ;
T_1 V_205 = F_58 ( V_32 ) ;
int V_44 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
F_60 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_199 = F_3 ( V_204 , struct V_198 , V_201 ) ;
if ( V_36 == V_199 -> V_36 ) {
V_140 -> V_130 . V_197 = V_199 -> V_201 . V_7 ;
F_54 ( F_53 ( V_32 ) ) ;
return 0 ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
V_44 = F_61 ( V_32 , V_33 , V_206 , 0 , 0 , & V_205 ,
V_36 ) ;
if ( V_44 == - V_195 ) {
V_44 = 0 ;
} else if ( V_44 && V_44 != - V_207 ) {
F_62 ( V_32 , L_19 ,
V_208 , V_33 , V_44 ) ;
} else {
V_140 -> V_130 . V_197 = V_205 ;
F_24 ( V_32 , L_20 ,
V_208 , V_33 , V_140 -> V_130 . V_197 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_44 ( struct V_31 * V_32 , struct V_122 * V_140 ,
T_2 V_33 , int V_36 )
{
if ( V_140 -> V_130 . V_197 != F_58 ( V_32 ) )
return F_57 ( V_32 , V_33 , V_36 ,
V_140 -> V_130 . V_197 ) ;
return F_59 ( V_32 , V_140 , V_33 , V_36 ) ;
}
static struct V_10 * F_63 ( int V_196 )
{
struct V_209 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_210 ;
V_200 -> V_211 = V_196 ;
F_22 ( & V_200 -> V_212 ) ;
F_26 ( & V_200 -> V_213 ) ;
F_64 ( & V_200 -> V_214 , 0 ) ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_65 ( int V_196 , int V_215 )
{
struct V_216 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_215 = V_215 ;
V_200 -> V_201 . V_2 = V_4 ;
F_64 ( & V_200 -> V_214 , 0 ) ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_66 ( int V_196 , int V_217 )
{
struct V_218 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_219 ;
V_200 -> V_217 = V_217 ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_67 ( int V_196 )
{
struct V_220 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_221 ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_68 ( int V_196 )
{
struct V_222 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_223 ;
F_64 ( & V_200 -> V_214 , 0 ) ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_69 ( int V_196 )
{
struct V_224 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_225 ;
F_64 ( & V_200 -> V_214 , 0 ) ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_70 ( int V_196 , int V_36 )
{
struct V_198 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_226 ;
V_200 -> V_36 = V_36 ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_71 ( int V_196 )
{
struct V_227 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_228 ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_72 ( T_1 V_196 , int V_139 )
{
struct V_229 * V_200 ;
V_200 = F_21 ( sizeof *V_200 , V_89 ) ;
if ( ! V_200 )
return NULL ;
V_200 -> V_201 . V_7 = V_196 ;
V_200 -> V_201 . V_2 = V_230 ;
V_200 -> V_139 = V_139 ;
return & V_200 -> V_201 ;
}
static struct V_10 * F_73 ( T_1 V_196 , enum V_18 type , int V_33 ,
int V_231 )
{
struct V_10 * V_200 ;
switch ( type ) {
case V_20 :
V_200 = F_63 ( V_196 ) ;
break;
case V_23 :
V_200 = F_66 ( V_196 , V_231 ) ;
break;
case V_24 :
V_200 = F_65 ( V_196 , V_231 ) ;
break;
case V_27 :
V_200 = F_67 ( V_196 ) ;
break;
case V_21 :
V_200 = F_68 ( V_196 ) ;
break;
case V_22 :
V_200 = F_69 ( V_196 ) ;
break;
case V_25 :
F_74 ( L_21 ) ;
return NULL ;
case V_28 :
V_200 = F_70 ( V_196 , V_231 ) ;
break;
case V_30 :
V_200 = F_71 ( V_196 ) ;
break;
case V_29 :
V_200 = F_72 ( V_196 , V_231 ) ;
break;
default:
return NULL ;
}
if ( V_200 )
V_200 -> V_192 = V_33 ;
return V_200 ;
}
int F_75 ( struct V_31 * V_32 , int V_33 , int V_36 ,
struct V_232 * V_233 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_204 ;
struct V_198 * V_199 ;
int * V_234 ;
int V_83 = 0 , V_44 = 0 ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
V_234 = F_76 ( V_32 -> V_62 . V_80 ,
sizeof( * V_234 ) , V_89 ) ;
if ( ! V_234 )
return - V_90 ;
F_52 ( F_53 ( V_32 ) ) ;
F_60 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_199 = F_3 ( V_204 , struct V_198 , V_201 ) ;
if ( V_199 -> V_36 == V_36 ) {
V_234 [ V_83 ] = ( int ) V_204 -> V_7 ;
V_83 ++ ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
V_234 [ V_83 ] = - 1 ;
V_83 = 0 ;
while ( V_234 [ V_83 ] != - 1 ) {
V_44 = F_77 ( V_32 , V_234 [ V_83 ] , V_233 ,
0 ) ;
if ( V_44 ) {
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
goto V_235;
}
V_83 ++ ;
}
V_235:
F_31 ( V_234 ) ;
return 0 ;
}
static int F_78 ( struct V_31 * V_32 , int V_33 , T_1 V_236 , int V_35 ,
enum V_18 type , int V_231 )
{
int V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_10 * * V_237 ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_203 -> V_94 [ type ] ;
V_237 = F_21 ( V_35 * sizeof *V_237 , V_89 ) ;
if ( ! V_237 )
return - V_90 ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
V_237 [ V_83 ] = F_73 ( V_236 + V_83 , type , V_33 , V_231 ) ;
if ( ! V_237 [ V_83 ] ) {
for ( -- V_83 ; V_83 >= 0 ; -- V_83 )
F_31 ( V_237 [ V_83 ] ) ;
F_31 ( V_237 ) ;
return - V_90 ;
}
}
F_52 ( F_53 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
if ( F_50 ( V_32 , V_236 + V_83 , type ) ) {
V_44 = - V_17 ;
goto V_238;
}
V_44 = F_4 ( V_6 , V_237 [ V_83 ] ) ;
if ( V_44 )
goto V_238;
F_79 ( & V_237 [ V_83 ] -> V_239 ,
& V_203 -> V_87 [ V_33 ] . V_92 [ type ] ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
F_31 ( V_237 ) ;
return 0 ;
V_238:
for ( -- V_83 ; V_83 >= 0 ; -- V_83 ) {
F_80 ( & V_237 [ V_83 ] -> V_9 , V_6 ) ;
F_81 ( & V_237 [ V_83 ] -> V_239 ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 )
F_31 ( V_237 [ V_83 ] ) ;
F_31 ( V_237 ) ;
return V_44 ;
}
static int F_82 ( struct V_209 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_240 || F_83 ( & V_11 -> V_214 ) ||
! F_84 ( & V_11 -> V_212 ) ) {
F_74 ( L_22 ,
V_11 -> V_201 . V_2 , F_83 ( & V_11 -> V_214 ) ) ;
return - V_191 ;
} else if ( V_11 -> V_201 . V_2 != V_210 ) {
return - V_193 ;
}
return 0 ;
}
static int F_85 ( struct V_216 * V_11 , int V_215 )
{
if ( V_11 -> V_201 . V_2 == V_3 ||
F_83 ( & V_11 -> V_214 ) ) {
F_86 ( L_23 ,
V_208 , __LINE__ ,
F_1 ( V_11 -> V_201 . V_2 ) ,
F_83 ( & V_11 -> V_214 ) ) ;
return - V_191 ;
} else if ( V_11 -> V_201 . V_2 != V_4 )
return - V_193 ;
else if ( V_11 -> V_215 != V_215 )
return - V_45 ;
return 0 ;
}
static int F_87 ( struct V_218 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_241 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_219 )
return - V_193 ;
return 0 ;
}
static int F_88 ( struct V_220 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_241 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_219 )
return - V_193 ;
return 0 ;
}
static int F_89 ( struct V_198 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_242 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_226 )
return - V_193 ;
return 0 ;
}
static int F_90 ( struct V_227 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_243 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_228 )
return - V_193 ;
return 0 ;
}
static int F_91 ( struct V_229 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_244 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_230 )
return - V_193 ;
return 0 ;
}
static int F_92 ( struct V_222 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_245 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_223 )
return - V_193 ;
return 0 ;
}
static int F_93 ( struct V_224 * V_11 )
{
if ( V_11 -> V_201 . V_2 == V_246 )
return - V_191 ;
else if ( V_11 -> V_201 . V_2 != V_225 )
return - V_193 ;
return 0 ;
}
static int F_94 ( struct V_10 * V_11 , enum V_18 type , int V_231 )
{
switch ( type ) {
case V_20 :
return F_82 ( (struct V_209 * ) V_11 ) ;
case V_21 :
return F_92 ( (struct V_222 * ) V_11 ) ;
case V_22 :
return F_93 ( (struct V_224 * ) V_11 ) ;
case V_23 :
return F_87 ( (struct V_218 * ) V_11 ) ;
case V_24 :
return F_85 ( (struct V_216 * ) V_11 , V_231 ) ;
case V_25 :
return - V_247 ;
case V_27 :
return F_88 ( (struct V_220 * ) V_11 ) ;
case V_28 :
return F_89 ( (struct V_198 * ) V_11 ) ;
case V_30 :
return F_90 ( (struct V_227 * ) V_11 ) ;
case V_29 :
return F_91 ( (struct V_229 * ) V_11 ) ;
default:
return - V_45 ;
}
}
static int F_95 ( struct V_31 * V_32 , int V_33 , T_1 V_236 , int V_35 ,
enum V_18 type , int V_231 )
{
T_1 V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_188 ;
F_52 ( F_53 ( V_32 ) ) ;
for ( V_83 = V_236 ; V_83 < V_236 + V_35 ; ++ V_83 ) {
V_188 = F_2 ( & V_203 -> V_94 [ type ] , V_83 ) ;
if ( ! V_188 ) {
V_44 = - V_195 ;
goto V_59;
}
if ( V_188 -> V_192 != V_33 ) {
V_44 = - V_193 ;
goto V_59;
}
V_44 = F_94 ( V_188 , type , V_231 ) ;
if ( V_44 )
goto V_59;
}
for ( V_83 = V_236 ; V_83 < V_236 + V_35 ; ++ V_83 ) {
V_188 = F_2 ( & V_203 -> V_94 [ type ] , V_83 ) ;
F_80 ( & V_188 -> V_9 , & V_203 -> V_94 [ type ] ) ;
F_96 ( & V_188 -> V_239 ) ;
F_31 ( V_188 ) ;
}
V_44 = 0 ;
V_59:
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static int F_97 ( struct V_31 * V_32 , int V_33 , int V_139 ,
enum V_248 V_2 , struct V_209 * * V_66 ,
int V_249 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_209 * V_188 ;
int V_44 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ V_20 ] , V_139 ) ;
if ( ! V_188 )
V_44 = - V_195 ;
else if ( V_188 -> V_201 . V_192 != V_33 )
V_44 = - V_193 ;
else {
switch ( V_2 ) {
case V_240 :
F_24 ( V_32 , L_24 ,
V_208 , V_188 -> V_201 . V_7 ) ;
V_44 = - V_191 ;
break;
case V_210 :
if ( V_188 -> V_201 . V_2 == V_250 && ! V_249 )
break;
F_24 ( V_32 , L_25 , V_188 -> V_201 . V_7 ) ;
V_44 = - V_45 ;
break;
case V_250 :
if ( ( V_188 -> V_201 . V_2 == V_210 && V_249 ) ||
V_188 -> V_201 . V_2 == V_251 )
break;
else {
F_24 ( V_32 , L_25 ,
V_188 -> V_201 . V_7 ) ;
V_44 = - V_45 ;
}
break;
case V_251 :
if ( V_188 -> V_201 . V_2 != V_250 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_188 -> V_201 . V_194 = V_188 -> V_201 . V_2 ;
V_188 -> V_201 . V_252 = V_2 ;
V_188 -> V_201 . V_2 = V_240 ;
if ( V_66 )
* V_66 = V_188 ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static int F_98 ( struct V_31 * V_32 , int V_33 , int V_253 ,
enum V_254 V_2 , struct V_218 * * V_77 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_218 * V_188 ;
int V_44 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ V_23 ] , V_253 ) ;
if ( ! V_188 )
V_44 = - V_195 ;
else if ( V_188 -> V_201 . V_192 != V_33 )
V_44 = - V_193 ;
else {
switch ( V_2 ) {
case V_241 :
V_44 = - V_45 ;
break;
case V_219 :
if ( V_188 -> V_201 . V_2 != V_255 )
V_44 = - V_45 ;
break;
case V_255 :
if ( V_188 -> V_201 . V_2 != V_219 &&
V_188 -> V_201 . V_2 != V_256 )
V_44 = - V_45 ;
break;
case V_256 :
if ( V_188 -> V_201 . V_2 != V_255 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_188 -> V_201 . V_194 = V_188 -> V_201 . V_2 ;
V_188 -> V_201 . V_252 = V_2 ;
V_188 -> V_201 . V_2 = V_241 ;
if ( V_77 )
* V_77 = V_188 ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static int F_99 ( struct V_31 * V_32 , int V_33 , int V_253 ,
enum V_257 V_2 , struct V_220 * * V_258 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_220 * V_188 ;
int V_44 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ V_27 ] , V_253 ) ;
if ( ! V_188 )
V_44 = - V_195 ;
else if ( V_188 -> V_201 . V_192 != V_33 )
V_44 = - V_193 ;
else {
switch ( V_2 ) {
case V_259 :
V_44 = - V_45 ;
break;
case V_221 :
if ( V_188 -> V_201 . V_2 != V_260 )
V_44 = - V_45 ;
break;
case V_260 :
if ( V_188 -> V_201 . V_2 != V_221 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_188 -> V_201 . V_194 = V_188 -> V_201 . V_2 ;
V_188 -> V_201 . V_252 = V_2 ;
V_188 -> V_201 . V_2 = V_259 ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
if ( ! V_44 && V_258 )
* V_258 = V_188 ;
return V_44 ;
}
static int F_100 ( struct V_31 * V_32 , int V_33 , int V_261 ,
enum V_262 V_2 , struct V_222 * * V_69 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_222 * V_188 ;
int V_44 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ V_21 ] , V_261 ) ;
if ( ! V_188 ) {
V_44 = - V_195 ;
} else if ( V_188 -> V_201 . V_192 != V_33 ) {
V_44 = - V_193 ;
} else if ( V_2 == V_223 ) {
if ( V_188 -> V_201 . V_2 != V_263 )
V_44 = - V_45 ;
else if ( F_83 ( & V_188 -> V_214 ) )
V_44 = - V_191 ;
else
V_44 = 0 ;
} else if ( V_2 != V_263 || V_188 -> V_201 . V_2 != V_223 ) {
V_44 = - V_45 ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
V_188 -> V_201 . V_194 = V_188 -> V_201 . V_2 ;
V_188 -> V_201 . V_252 = V_2 ;
V_188 -> V_201 . V_2 = V_245 ;
if ( V_69 )
* V_69 = V_188 ;
}
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static int F_101 ( struct V_31 * V_32 , int V_33 , int V_253 ,
enum V_264 V_2 , struct V_224 * * V_72 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_224 * V_188 ;
int V_44 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ V_22 ] , V_253 ) ;
if ( ! V_188 ) {
V_44 = - V_195 ;
} else if ( V_188 -> V_201 . V_192 != V_33 ) {
V_44 = - V_193 ;
} else if ( V_2 == V_225 ) {
if ( V_188 -> V_201 . V_2 != V_265 )
V_44 = - V_45 ;
else if ( F_83 ( & V_188 -> V_214 ) )
V_44 = - V_191 ;
} else if ( V_2 != V_265 || V_188 -> V_201 . V_2 != V_225 ) {
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_188 -> V_201 . V_194 = V_188 -> V_201 . V_2 ;
V_188 -> V_201 . V_252 = V_2 ;
V_188 -> V_201 . V_2 = V_246 ;
if ( V_72 )
* V_72 = V_188 ;
}
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static void F_102 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_196 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_188 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ type ] , V_196 ) ;
if ( V_188 && ( V_188 -> V_192 == V_33 ) )
V_188 -> V_2 = V_188 -> V_194 ;
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_103 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_196 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_188 ;
F_52 ( F_53 ( V_32 ) ) ;
V_188 = F_2 ( & V_203 -> V_94 [ type ] , V_196 ) ;
if ( V_188 && ( V_188 -> V_192 == V_33 ) )
V_188 -> V_2 = V_188 -> V_252 ;
F_54 ( F_53 ( V_32 ) ) ;
}
static int F_104 ( struct V_31 * V_32 , int V_33 , int V_139 )
{
return F_45 ( V_32 , V_139 ) &&
( F_105 ( V_32 ) || F_106 ( V_32 , V_33 , V_139 ) ) ;
}
static int F_107 ( struct V_31 * V_32 , int V_139 )
{
return V_139 < V_32 -> V_62 . V_266 [ V_267 ] ;
}
static int F_108 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_44 ;
int V_35 ;
int V_272 ;
int V_236 ;
int V_139 ;
T_2 V_128 ;
switch ( V_268 ) {
case V_206 :
V_35 = F_109 ( & V_270 ) & 0xffffff ;
V_128 = ( F_109 ( & V_270 ) >> 24 ) & V_32 -> V_62 . V_273 ;
V_272 = F_110 ( & V_270 ) ;
V_44 = F_8 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_111 ( V_32 , V_35 , V_272 , & V_236 , V_128 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
return V_44 ;
}
V_44 = F_78 ( V_32 , V_33 , V_236 , V_35 , V_20 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_112 ( V_32 , V_236 , V_35 ) ;
return V_44 ;
}
F_113 ( V_271 , V_236 ) ;
break;
case V_274 :
V_139 = F_109 ( & V_270 ) & 0x7fffff ;
if ( F_104 ( V_32 , V_33 , V_139 ) ) {
V_44 = F_78 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_97 ( V_32 , V_33 , V_139 , V_250 ,
NULL , 1 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_107 ( V_32 , V_139 ) ) {
V_44 = F_114 ( V_32 , V_139 , V_89 ) ;
if ( V_44 ) {
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
}
F_103 ( V_32 , V_33 , V_20 , V_139 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_115 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_44 = - V_45 ;
int V_236 ;
int V_215 ;
if ( V_268 != V_275 )
return V_44 ;
V_215 = F_109 ( & V_270 ) ;
V_44 = F_8 ( V_32 , V_33 , V_24 , 1 << V_215 , 0 ) ;
if ( V_44 )
return V_44 ;
V_236 = F_116 ( V_32 , V_215 ) ;
if ( V_236 == - 1 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_215 , 0 ) ;
return - V_90 ;
}
V_44 = F_78 ( V_32 , V_33 , V_236 , 1 , V_24 , V_215 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_215 , 0 ) ;
F_117 ( V_32 , V_236 , V_215 ) ;
} else {
F_113 ( V_271 , V_236 ) ;
}
return V_44 ;
}
static int F_118 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_44 = - V_45 ;
int V_253 ;
int V_196 ;
struct V_218 * V_77 ;
switch ( V_268 ) {
case V_206 :
V_44 = F_8 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
if ( V_44 )
break;
V_253 = F_119 ( V_32 ) ;
if ( V_253 == - 1 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
break;
}
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_78 ( V_32 , V_33 , V_196 , 1 , V_23 , V_253 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_120 ( V_32 , V_253 ) ;
break;
}
F_113 ( V_271 , V_253 ) ;
break;
case V_274 :
V_253 = F_109 ( & V_270 ) ;
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_98 ( V_32 , V_33 , V_196 ,
V_255 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_121 ( V_32 , V_77 -> V_217 , V_89 ) ;
if ( V_44 ) {
F_102 ( V_32 , V_33 , V_23 , V_196 ) ;
return V_44 ;
}
F_103 ( V_32 , V_33 , V_23 , V_196 ) ;
break;
}
return V_44 ;
}
static int F_122 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_261 ;
int V_44 ;
switch ( V_268 ) {
case V_275 :
V_44 = F_8 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_123 ( V_32 , & V_261 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
break;
}
V_44 = F_78 ( V_32 , V_33 , V_261 , 1 , V_21 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_124 ( V_32 , V_261 ) ;
break;
}
F_113 ( V_271 , V_261 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_125 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_276 ;
int V_44 ;
switch ( V_268 ) {
case V_275 :
V_44 = F_8 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_126 ( V_32 , & V_276 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
break;
}
V_44 = F_78 ( V_32 , V_33 , V_276 , 1 , V_22 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_127 ( V_32 , V_276 ) ;
break;
}
F_113 ( V_271 , V_276 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_128 ( struct V_31 * V_32 , int V_33 , int V_36 ,
T_2 V_277 , T_1 * V_278 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_280 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_281 * V_11 , * V_204 ;
F_129 (res, tmp, mac_list, list) {
if ( V_11 -> V_277 == V_277 && V_11 -> V_36 == ( T_2 ) V_36 ) {
* V_278 = V_11 -> V_278 ;
return 0 ;
}
}
return - V_195 ;
}
static int F_130 ( struct V_31 * V_32 , int V_33 , T_1 V_278 , int V_36 , T_2 V_277 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_280 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_281 * V_11 , * V_204 ;
F_129 (res, tmp, mac_list, list) {
if ( V_11 -> V_278 == V_278 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_214 ;
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
V_11 -> V_278 = V_278 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_277 = V_277 ;
V_11 -> V_214 = 1 ;
F_79 ( & V_11 -> V_239 ,
& V_203 -> V_87 [ V_33 ] . V_92 [ V_25 ] ) ;
return 0 ;
}
static void F_131 ( struct V_31 * V_32 , int V_33 , T_1 V_278 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_280 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_281 * V_11 , * V_204 ;
F_129 (res, tmp, mac_list, list) {
if ( V_11 -> V_278 == V_278 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_214 ) {
F_96 ( & V_11 -> V_239 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
F_31 ( V_11 ) ;
}
break;
}
}
}
static void F_132 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_280 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_281 * V_11 , * V_204 ;
int V_83 ;
F_129 (res, tmp, mac_list, list) {
F_96 ( & V_11 -> V_239 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_214 ; V_83 ++ )
F_133 ( V_32 , V_11 -> V_36 , V_11 -> V_278 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_134 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 , int V_282 )
{
int V_44 = - V_45 ;
int V_36 ;
T_1 V_278 ;
T_2 V_277 ;
if ( V_268 != V_275 )
return V_44 ;
V_36 = ! V_282 ? F_109 ( V_271 ) : V_282 ;
V_36 = F_135 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
V_278 = V_270 ;
V_44 = F_136 ( V_32 , V_36 , V_278 ) ;
if ( V_44 >= 0 ) {
V_277 = V_44 ;
F_113 ( V_271 , V_44 ) ;
V_44 = 0 ;
}
if ( ! V_44 ) {
V_44 = F_130 ( V_32 , V_33 , V_278 , V_36 , V_277 ) ;
if ( V_44 )
F_133 ( V_32 , V_36 , V_278 ) ;
}
return V_44 ;
}
static int F_137 ( struct V_31 * V_32 , int V_33 , T_4 V_283 ,
int V_36 , int V_173 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_284 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_285 * V_11 , * V_204 ;
F_129 (res, tmp, vlan_list, list) {
if ( V_11 -> V_283 == V_283 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_214 ;
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
V_11 -> V_283 = V_283 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_173 = V_173 ;
V_11 -> V_214 = 1 ;
F_79 ( & V_11 -> V_239 ,
& V_203 -> V_87 [ V_33 ] . V_92 [ V_26 ] ) ;
return 0 ;
}
static void F_138 ( struct V_31 * V_32 , int V_33 , T_4 V_283 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_284 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_285 * V_11 , * V_204 ;
F_129 (res, tmp, vlan_list, list) {
if ( V_11 -> V_283 == V_283 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_214 ) {
F_96 ( & V_11 -> V_239 ) ;
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
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_284 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_285 * V_11 , * V_204 ;
int V_83 ;
F_129 (res, tmp, vlan_list, list) {
F_96 ( & V_11 -> V_239 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_214 ; V_83 ++ )
F_139 ( V_32 , V_11 -> V_36 , V_11 -> V_283 ) ;
F_12 ( V_32 , V_33 , V_26 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_140 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 , int V_282 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_286 * V_287 = V_38 -> V_41 . V_42 . V_287 ;
int V_44 ;
T_4 V_283 ;
int V_173 ;
int V_36 ;
V_36 = ! V_282 ? F_109 ( V_271 ) : V_282 ;
if ( ! V_36 || V_268 != V_275 )
return - V_45 ;
V_36 = F_135 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
if ( ! V_282 && V_36 > 0 && V_36 <= V_32 -> V_62 . V_100 ) {
V_287 [ V_33 ] . V_288 = true ;
return 0 ;
}
V_283 = ( T_4 ) V_270 ;
V_44 = F_141 ( V_32 , V_36 , V_283 , & V_173 ) ;
if ( ! V_44 ) {
F_113 ( V_271 , ( T_3 ) V_173 ) ;
V_44 = F_137 ( V_32 , V_33 , V_283 , V_36 , V_173 ) ;
if ( V_44 )
F_139 ( V_32 , V_36 , V_283 ) ;
}
return V_44 ;
}
static int F_61 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 , int V_36 )
{
T_3 V_253 ;
int V_44 ;
if ( V_268 != V_206 )
return - V_45 ;
V_44 = F_8 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_142 ( V_32 , & V_253 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
V_44 = F_78 ( V_32 , V_33 , V_253 , 1 , V_28 , V_36 ) ;
if ( V_44 ) {
F_143 ( V_32 , V_253 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
} else {
F_113 ( V_271 , V_253 ) ;
}
return V_44 ;
}
static int F_144 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
T_3 V_289 ;
int V_44 ;
if ( V_268 != V_206 )
return - V_45 ;
V_44 = F_145 ( V_32 , & V_289 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_78 ( V_32 , V_33 , V_289 , 1 , V_30 , 0 ) ;
if ( V_44 )
F_146 ( V_32 , V_289 ) ;
else
F_113 ( V_271 , V_289 ) ;
return V_44 ;
}
int F_147 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_294 = V_291 -> V_295 ;
switch ( V_291 -> V_296 & 0xFF ) {
case V_20 :
V_44 = F_108 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_24 :
V_44 = F_115 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_23 :
V_44 = F_118 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_21 :
V_44 = F_122 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_22 :
V_44 = F_125 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_25 :
V_44 = F_134 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ,
( V_291 -> V_296 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_140 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ,
( V_291 -> V_296 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_61 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 , 0 ) ;
break;
case V_30 :
V_44 = F_144 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_148 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 )
{
int V_44 ;
int V_35 ;
int V_236 ;
int V_139 ;
switch ( V_268 ) {
case V_206 :
V_236 = F_109 ( & V_270 ) & 0x7fffff ;
V_35 = F_110 ( & V_270 ) ;
V_44 = F_95 ( V_32 , V_33 , V_236 , V_35 , V_20 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_112 ( V_32 , V_236 , V_35 ) ;
break;
case V_274 :
V_139 = F_109 ( & V_270 ) & 0x7fffff ;
V_44 = F_97 ( V_32 , V_33 , V_139 , V_210 ,
NULL , 0 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_107 ( V_32 , V_139 ) )
F_149 ( V_32 , V_139 ) ;
F_103 ( V_32 , V_33 , V_20 , V_139 ) ;
if ( F_104 ( V_32 , V_33 , V_139 ) )
V_44 = F_95 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_150 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_44 = - V_45 ;
int V_236 ;
int V_215 ;
if ( V_268 != V_275 )
return V_44 ;
V_236 = F_109 ( & V_270 ) ;
V_215 = F_110 ( & V_270 ) ;
V_44 = F_95 ( V_32 , V_33 , V_236 , 1 , V_24 , V_215 ) ;
if ( ! V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_215 , 0 ) ;
F_117 ( V_32 , V_236 , V_215 ) ;
}
return V_44 ;
}
static int F_151 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 )
{
int V_44 = - V_45 ;
int V_253 ;
int V_196 ;
struct V_218 * V_77 ;
switch ( V_268 ) {
case V_206 :
V_253 = F_109 ( & V_270 ) ;
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_51 ( V_32 , V_33 , V_196 , V_23 , & V_77 ) ;
if ( V_44 )
break;
V_253 = V_77 -> V_217 ;
F_56 ( V_32 , V_33 , V_196 , V_23 ) ;
V_44 = F_95 ( V_32 , V_33 , V_196 , 1 , V_23 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_120 ( V_32 , V_253 ) ;
break;
case V_274 :
V_253 = F_109 ( & V_270 ) ;
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_98 ( V_32 , V_33 , V_196 ,
V_219 , & V_77 ) ;
if ( V_44 )
return V_44 ;
F_152 ( V_32 , V_77 -> V_217 ) ;
F_103 ( V_32 , V_33 , V_23 , V_196 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_153 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_261 ;
int V_44 ;
switch ( V_268 ) {
case V_275 :
V_261 = F_109 ( & V_270 ) ;
V_44 = F_95 ( V_32 , V_33 , V_261 , 1 , V_21 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_124 ( V_32 , V_261 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_154 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_276 ;
int V_44 ;
switch ( V_268 ) {
case V_275 :
V_276 = F_109 ( & V_270 ) ;
V_44 = F_95 ( V_32 , V_33 , V_276 , 1 , V_22 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_127 ( V_32 , V_276 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_155 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 , int V_282 )
{
int V_36 ;
int V_44 = 0 ;
switch ( V_268 ) {
case V_275 :
V_36 = ! V_282 ? F_109 ( V_271 ) : V_282 ;
V_36 = F_135 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
F_131 ( V_32 , V_33 , V_270 , V_36 ) ;
F_133 ( V_32 , V_36 , V_270 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_156 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 , int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_286 * V_287 = V_38 -> V_41 . V_42 . V_287 ;
int V_44 = 0 ;
V_36 = F_135 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
switch ( V_268 ) {
case V_275 :
if ( V_287 [ V_33 ] . V_288 )
return 0 ;
if ( ! V_36 )
return - V_45 ;
F_138 ( V_32 , V_33 , V_270 , V_36 ) ;
F_139 ( V_32 , V_36 , V_270 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_157 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_253 ;
int V_44 ;
if ( V_268 != V_206 )
return - V_45 ;
V_253 = F_109 ( & V_270 ) ;
if ( V_253 == F_58 ( V_32 ) )
return 0 ;
V_44 = F_95 ( V_32 , V_33 , V_253 , 1 , V_28 , 0 ) ;
if ( V_44 )
return V_44 ;
F_143 ( V_32 , V_253 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
static int F_158 ( struct V_31 * V_32 , int V_33 , int V_268 , int V_269 ,
T_1 V_270 , T_1 * V_271 )
{
int V_289 ;
int V_44 ;
if ( V_268 != V_206 )
return - V_45 ;
V_289 = F_109 ( & V_270 ) ;
V_44 = F_95 ( V_32 , V_33 , V_289 , 1 , V_30 , 0 ) ;
if ( V_44 )
return V_44 ;
F_146 ( V_32 , V_289 ) ;
return V_44 ;
}
int F_159 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 = - V_45 ;
int V_294 = V_291 -> V_295 ;
switch ( V_291 -> V_296 & 0xFF ) {
case V_20 :
V_44 = F_148 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 ) ;
break;
case V_24 :
V_44 = F_150 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_23 :
V_44 = F_151 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 ) ;
break;
case V_21 :
V_44 = F_153 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_22 :
V_44 = F_154 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_25 :
V_44 = F_155 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ,
( V_291 -> V_296 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_156 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ,
( V_291 -> V_296 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_157 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
break;
case V_30 :
V_44 = F_158 ( V_32 , V_33 , V_291 -> V_295 , V_294 ,
V_291 -> V_270 , & V_291 -> V_271 ) ;
default:
break;
}
return V_44 ;
}
static int F_160 ( struct V_297 * V_77 )
{
return ( F_40 ( V_77 -> V_128 ) >> 9 ) & 1 ;
}
static int F_161 ( struct V_297 * V_77 )
{
return ( int ) F_162 ( V_77 -> V_298 ) & 0xfffffff8 ;
}
static int F_163 ( struct V_297 * V_77 )
{
return F_40 ( V_77 -> V_299 ) ;
}
static T_3 F_164 ( struct V_297 * V_77 )
{
return F_40 ( V_77 -> V_300 ) & 0x00ffffff ;
}
static int F_165 ( struct V_297 * V_77 )
{
return F_40 ( V_77 -> V_300 ) & V_301 ;
}
static int F_166 ( struct V_297 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_302 ;
}
static int F_167 ( struct V_297 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_303 ;
}
static int F_168 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_304 ) & 0xfffffff8 ;
}
static int F_169 ( struct V_305 * V_306 )
{
return F_40 ( V_306 -> V_304 ) & 0xfffffff8 ;
}
static int F_170 ( struct V_122 * V_140 )
{
int V_307 = ( V_140 -> V_308 & 0x3f ) + 12 ;
int V_309 = ( V_140 -> V_310 >> 3 ) & 0xf ;
int V_311 = V_140 -> V_310 & 7 ;
int V_312 = ( V_140 -> V_313 >> 3 ) & 0xf ;
int V_314 = V_140 -> V_313 & 7 ;
int V_72 = ( F_40 ( V_140 -> V_276 ) >> 24 ) & 1 ;
int V_315 = ( F_40 ( V_140 -> V_128 ) >> 13 ) & 1 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
int V_316 = ( V_127 == V_134 ) ? 1 : 0 ;
int V_317 ;
int V_318 ;
int V_319 ;
int V_320 ;
int V_321 = ( F_40 ( V_140 -> V_322 ) >> 6 ) & 0x3f ;
V_317 = 1 << ( V_309 + V_311 + 4 ) ;
V_318 = ( V_72 | V_315 | V_316 ) ? 0 : ( 1 << ( V_312 + V_314 + 4 ) ) ;
V_320 = V_317 + V_318 ;
V_319 =
F_171 ( ( V_320 + ( V_321 << 6 ) ) >>
V_307 ) ;
return V_319 ;
}
static int F_172 ( struct V_31 * V_32 , int V_33 , int V_323 ,
int V_324 , struct V_216 * V_75 )
{
int V_325 = V_75 -> V_201 . V_7 ;
int V_326 = ( 1 << V_75 -> V_215 ) ;
if ( V_323 < V_325 || V_323 + V_324 > V_325 + V_326 )
return - V_193 ;
return 0 ;
}
int F_173 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_253 = V_291 -> V_296 ;
struct V_216 * V_75 ;
struct V_218 * V_77 ;
int V_327 = F_161 ( V_116 -> V_118 ) / V_32 -> V_62 . V_328 ;
int V_329 ;
int V_196 ;
T_3 V_330 ;
int V_331 ;
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_98 ( V_32 , V_33 , V_196 , V_256 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_167 ( V_116 -> V_118 ) ) {
V_44 = - V_193 ;
goto V_332;
}
V_330 = F_164 ( V_116 -> V_118 ) ;
V_331 = ( V_330 >> 17 ) & 0x7f ;
if ( V_331 != 0 && -- V_331 != V_33 ) {
V_44 = - V_193 ;
goto V_332;
}
if ( F_165 ( V_116 -> V_118 ) ) {
if ( F_166 ( V_116 -> V_118 ) ) {
V_44 = - V_193 ;
goto V_332;
}
if ( ! F_167 ( V_116 -> V_118 ) ) {
V_44 = - V_193 ;
goto V_332;
}
}
V_329 = F_160 ( V_116 -> V_118 ) ;
if ( ! V_329 ) {
V_44 = F_51 ( V_32 , V_33 , V_327 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_332;
V_44 = F_172 ( V_32 , V_33 , V_327 ,
F_163 ( V_116 -> V_118 ) , V_75 ) ;
if ( V_44 )
goto V_333;
V_77 -> V_75 = V_75 ;
}
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_333;
if ( ! V_329 ) {
F_175 ( & V_75 -> V_214 ) ;
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
}
F_103 ( V_32 , V_33 , V_23 , V_196 ) ;
return 0 ;
V_333:
if ( ! V_329 )
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
V_332:
F_102 ( V_32 , V_33 , V_23 , V_196 ) ;
return V_44 ;
}
int F_176 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_253 = V_291 -> V_296 ;
struct V_218 * V_77 ;
int V_196 ;
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_98 ( V_32 , V_33 , V_196 , V_255 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_332;
if ( V_77 -> V_75 )
F_177 ( & V_77 -> V_75 -> V_214 ) ;
F_103 ( V_32 , V_33 , V_23 , V_196 ) ;
return 0 ;
V_332:
F_102 ( V_32 , V_33 , V_23 , V_196 ) ;
return V_44 ;
}
int F_178 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_253 = V_291 -> V_296 ;
struct V_218 * V_77 ;
int V_196 ;
V_196 = V_253 & F_49 ( V_32 ) ;
V_44 = F_51 ( V_32 , V_33 , V_196 , V_23 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( V_77 -> V_201 . V_194 == V_255 ) {
struct V_297 * V_334 = F_179 (
& V_37 ( V_32 ) -> V_335 . V_336 ,
V_77 -> V_217 , NULL ) ;
if ( NULL == V_334 || NULL == V_292 -> V_118 ) {
V_44 = - V_45 ;
goto V_59;
}
memcpy ( V_292 -> V_118 , V_334 , sizeof( * V_334 ) ) ;
V_44 = 0 ;
} else if ( V_77 -> V_201 . V_194 == V_256 ) {
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
} else {
V_44 = - V_191 ;
goto V_59;
}
V_59:
F_56 ( V_32 , V_33 , V_196 , V_23 ) ;
return V_44 ;
}
static int F_180 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_337 ) & 0xffffff ;
}
static int F_181 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_338 ) & 0xffffff ;
}
static T_3 F_182 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_276 ) & 0x1ffffff ;
}
static void F_183 ( struct V_31 * V_32 , struct V_290 * V_291 ,
struct V_122 * V_339 )
{
T_3 V_139 = V_291 -> V_296 & 0xffffff ;
T_3 V_340 = 0 ;
if ( F_184 ( V_32 , V_139 , & V_340 ) )
return;
V_339 -> V_340 = F_46 ( V_340 ) ;
}
int F_185 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_139 = V_291 -> V_296 & 0x7fffff ;
struct V_216 * V_75 ;
struct V_209 * V_66 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_327 = F_168 ( V_140 ) / V_32 -> V_62 . V_328 ;
int V_341 = F_170 ( V_140 ) ;
struct V_222 * V_342 ;
struct V_222 * V_343 ;
int V_344 = F_180 ( V_140 ) ;
int V_345 = F_181 ( V_140 ) ;
T_3 V_276 = F_182 ( V_140 ) & 0xffffff ;
int V_346 = ( F_182 ( V_140 ) >> 24 ) & 1 ;
struct V_224 * V_72 ;
int V_211 = F_40 ( V_140 -> V_211 ) & 0xffffff ;
V_44 = F_186 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_97 ( V_32 , V_33 , V_139 , V_251 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_66 -> V_211 = V_211 ;
V_66 -> V_131 = 0 ;
V_66 -> V_152 = 0 ;
V_66 -> V_157 = 0 ;
V_66 -> V_171 = 0 ;
V_66 -> V_347 = 0 ;
V_66 -> V_173 = 0 ;
V_66 -> V_179 = 0 ;
V_66 -> V_348 = F_40 ( V_140 -> V_128 ) ;
V_44 = F_51 ( V_32 , V_33 , V_327 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_332;
V_44 = F_172 ( V_32 , V_33 , V_327 , V_341 , V_75 ) ;
if ( V_44 )
goto V_349;
V_44 = F_51 ( V_32 , V_33 , V_344 , V_21 , & V_342 ) ;
if ( V_44 )
goto V_349;
if ( V_345 != V_344 ) {
V_44 = F_51 ( V_32 , V_33 , V_345 , V_21 , & V_343 ) ;
if ( V_44 )
goto V_350;
} else
V_343 = V_342 ;
if ( V_346 ) {
V_44 = F_51 ( V_32 , V_33 , V_276 , V_22 , & V_72 ) ;
if ( V_44 )
goto V_351;
}
F_183 ( V_32 , V_291 , V_140 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_352;
F_175 ( & V_75 -> V_214 ) ;
V_66 -> V_75 = V_75 ;
F_175 ( & V_342 -> V_214 ) ;
V_66 -> V_342 = V_342 ;
F_175 ( & V_343 -> V_214 ) ;
V_66 -> V_343 = V_343 ;
if ( V_345 != V_344 )
F_56 ( V_32 , V_33 , V_345 , V_21 ) ;
if ( V_346 ) {
F_175 ( & V_72 -> V_214 ) ;
F_56 ( V_32 , V_33 , V_276 , V_22 ) ;
V_66 -> V_72 = V_72 ;
}
V_66 -> V_152 = V_140 -> V_152 ;
F_56 ( V_32 , V_33 , V_344 , V_21 ) ;
F_56 ( V_32 , V_33 , V_327 , V_24 ) ;
F_103 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_352:
if ( V_346 )
F_56 ( V_32 , V_33 , V_276 , V_22 ) ;
V_351:
if ( V_345 != V_344 )
F_56 ( V_32 , V_33 , V_345 , V_21 ) ;
V_350:
F_56 ( V_32 , V_33 , V_344 , V_21 ) ;
V_349:
F_56 ( V_32 , V_33 , V_327 , V_24 ) ;
V_332:
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static int F_187 ( struct V_353 * V_354 )
{
return F_40 ( V_354 -> V_304 ) & 0xfffffff8 ;
}
static int F_188 ( struct V_353 * V_354 )
{
int V_355 = V_354 -> V_355 & 0x1f ;
int V_307 = ( V_354 -> V_308 & 0x3f ) + 12 ;
if ( V_355 + 5 < V_307 )
return 1 ;
return 1 << ( V_355 + 5 - V_307 ) ;
}
static int F_189 ( struct V_356 * V_357 )
{
return F_40 ( V_357 -> V_304 ) & 0xfffffff8 ;
}
static int F_190 ( struct V_356 * V_357 )
{
int V_358 = ( F_40 ( V_357 -> V_359 ) >> 24 ) & 0x1f ;
int V_307 = ( V_357 -> V_308 & 0x3f ) + 12 ;
if ( V_358 + 5 < V_307 )
return 1 ;
return 1 << ( V_358 + 5 - V_307 ) ;
}
int F_191 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_360 = V_291 -> V_296 ;
int V_7 = ( V_33 << 10 ) | V_360 ;
struct V_353 * V_354 = V_116 -> V_118 ;
int V_327 = F_187 ( V_354 ) / V_32 -> V_62 . V_328 ;
int V_341 = F_188 ( V_354 ) ;
struct V_220 * V_258 ;
struct V_216 * V_75 ;
V_44 = F_78 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_99 ( V_32 , V_33 , V_7 , V_260 , & V_258 ) ;
if ( V_44 )
goto V_361;
V_44 = F_51 ( V_32 , V_33 , V_327 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_362;
V_44 = F_172 ( V_32 , V_33 , V_327 , V_341 , V_75 ) ;
if ( V_44 )
goto V_363;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_363;
F_175 ( & V_75 -> V_214 ) ;
V_258 -> V_75 = V_75 ;
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
F_103 ( V_32 , V_33 , V_27 , V_7 ) ;
return 0 ;
V_363:
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
V_362:
F_102 ( V_32 , V_33 , V_27 , V_7 ) ;
V_361:
F_95 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return V_44 ;
}
int F_192 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
T_2 V_364 = V_291 -> V_295 ;
if ( V_364 != 1 )
return - V_193 ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
return V_44 ;
}
static int F_193 ( struct V_31 * V_32 , int V_33 , int V_323 ,
int V_365 , struct V_216 * * V_11 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_216 * V_75 ;
int V_44 = - V_45 ;
F_52 ( F_53 ( V_32 ) ) ;
F_60 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_172 ( V_32 , V_33 , V_323 , V_365 , V_75 ) ) {
* V_11 = V_75 ;
V_75 -> V_201 . V_194 = V_75 -> V_201 . V_2 ;
V_75 -> V_201 . V_2 = V_3 ;
V_44 = 0 ;
break;
}
}
F_54 ( F_53 ( V_32 ) ) ;
return V_44 ;
}
static int F_194 ( struct V_31 * V_32 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
enum V_366 V_367 , T_2 V_33 )
{
T_3 V_143 ;
T_3 V_139 ;
struct V_122 * V_123 ;
enum V_124 V_125 ;
int V_36 ;
int V_368 ;
V_123 = V_116 -> V_118 + 8 ;
V_143 = ( F_40 ( V_123 -> V_128 ) >> 16 ) & 0xff ;
V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
if ( V_33 != F_14 ( V_32 ) ) {
V_123 -> V_322 &= ~ V_369 ;
if ( V_123 -> V_370 )
return - V_193 ;
}
switch ( V_143 ) {
case V_133 :
case V_134 :
case V_135 :
switch ( V_367 ) {
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
if ( V_33 != F_14 ( V_32 ) ) {
if ( V_125 & V_136 ) {
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_376 [ V_36 ] != V_377 )
V_368 = F_195 ( V_32 , V_33 , V_36 ) ;
else
V_368 = 1 ;
if ( V_123 -> V_130 . V_132 >= V_368 )
return - V_45 ;
}
if ( V_125 & V_137 ) {
V_36 = ( V_123 -> V_138 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_376 [ V_36 ] != V_377 )
V_368 = F_195 ( V_32 , V_33 , V_36 ) ;
else
V_368 = 1 ;
if ( V_123 -> V_138 . V_132 >= V_368 )
return - V_45 ;
}
}
break;
default:
break;
}
break;
case V_148 :
V_139 = V_291 -> V_296 & 0x7fffff ;
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_367 == V_371 &&
V_33 != F_14 ( V_32 ) &&
F_45 ( V_32 , V_139 ) &&
! F_196 ( V_32 , V_33 , V_36 ) ) {
F_62 ( V_32 , L_26 ,
V_208 , V_33 , V_36 ) ;
return - V_193 ;
}
break;
default:
break;
}
return 0 ;
}
int F_197 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
struct V_378 V_75 ;
T_5 * V_379 = V_116 -> V_118 ;
T_1 * V_380 = ( T_1 * ) V_379 ;
int V_83 ;
struct V_216 * V_381 = NULL ;
int V_323 = F_162 ( V_379 [ 0 ] ) ;
int V_382 = V_291 -> V_296 ;
int V_44 ;
V_44 = F_193 ( V_32 , V_33 , V_323 , V_382 , & V_381 ) ;
if ( V_44 )
return V_44 ;
V_75 . V_383 = 0 ;
V_75 . V_215 = 0 ;
V_75 . V_307 = 0 ;
for ( V_83 = 0 ; V_83 < V_382 ; ++ V_83 )
V_380 [ V_83 + 2 ] = ( F_162 ( V_379 [ V_83 + 2 ] ) & ~ 1ULL ) ;
V_44 = F_198 ( V_32 , & V_75 , F_162 ( V_379 [ 0 ] ) , V_382 ,
( ( T_1 * ) V_379 + 2 ) ) ;
if ( V_381 )
F_56 ( V_32 , V_33 , V_381 -> V_201 . V_7 , V_24 ) ;
return V_44 ;
}
int F_199 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_360 = V_291 -> V_296 ;
int V_7 = V_360 | ( V_33 << 10 ) ;
struct V_220 * V_258 ;
int V_44 ;
V_44 = F_99 ( V_32 , V_33 , V_7 , V_221 , & V_258 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_51 ( V_32 , V_33 , V_258 -> V_75 -> V_201 . V_7 , V_24 , NULL ) ;
if ( V_44 )
goto V_332;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_333;
F_177 ( & V_258 -> V_75 -> V_214 ) ;
F_56 ( V_32 , V_33 , V_258 -> V_75 -> V_201 . V_7 , V_24 ) ;
F_103 ( V_32 , V_33 , V_27 , V_7 ) ;
F_95 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return 0 ;
V_333:
F_56 ( V_32 , V_33 , V_258 -> V_75 -> V_201 . V_7 , V_24 ) ;
V_332:
F_102 ( V_32 , V_33 , V_27 , V_7 ) ;
return V_44 ;
}
int F_200 ( struct V_31 * V_32 , int V_33 , struct V_384 * V_385 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_386 * V_387 ;
struct V_115 * V_388 ;
T_3 V_296 = 0 ;
int V_44 ;
int V_7 ;
struct V_220 * V_389 ;
if ( ! V_38 -> V_41 . V_42 . V_287 )
return - V_45 ;
if ( V_33 < 0 || V_33 > V_32 -> V_51 -> V_52 ||
V_33 == V_32 -> V_62 . V_113 ||
! V_38 -> V_41 . V_42 . V_287 [ V_33 ] . V_390 )
return 0 ;
V_387 = & V_38 -> V_41 . V_42 . V_287 [ V_33 ] . V_387 [ V_385 -> type ] ;
if ( V_387 -> V_360 < 0 )
return 0 ;
F_35 ( & V_38 -> V_41 . V_42 . V_391 [ V_33 ] ) ;
V_7 = ( V_33 << 10 ) | V_387 -> V_360 ;
V_44 = F_51 ( V_32 , V_33 , V_7 , V_27 , & V_389 ) ;
if ( V_44 )
goto V_392;
if ( V_389 -> V_201 . V_194 != V_260 ) {
V_44 = - V_45 ;
goto V_393;
}
V_388 = F_201 ( V_32 ) ;
if ( F_202 ( V_388 ) ) {
V_44 = F_203 ( V_388 ) ;
goto V_393;
}
if ( V_385 -> type == V_394 ) {
++ V_387 -> V_395 ;
V_385 -> V_396 . V_269 . V_395 = F_204 ( V_387 -> V_395 ) ;
}
memcpy ( V_388 -> V_118 , ( T_2 * ) V_385 , 28 ) ;
V_296 = ( V_33 & 0xff ) | ( ( V_387 -> V_360 & 0x3ff ) << 16 ) ;
V_44 = F_205 ( V_32 , V_388 -> V_397 , V_296 , 0 ,
V_398 , V_399 ,
V_400 ) ;
F_56 ( V_32 , V_33 , V_7 , V_27 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_391 [ V_33 ] ) ;
F_206 ( V_32 , V_388 ) ;
return V_44 ;
V_393:
F_56 ( V_32 , V_33 , V_7 , V_27 ) ;
V_392:
F_37 ( & V_38 -> V_41 . V_42 . V_391 [ V_33 ] ) ;
return V_44 ;
}
int F_207 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_360 = V_291 -> V_296 ;
int V_7 = V_360 | ( V_33 << 10 ) ;
struct V_220 * V_258 ;
int V_44 ;
V_44 = F_51 ( V_32 , V_33 , V_7 , V_27 , & V_258 ) ;
if ( V_44 )
return V_44 ;
if ( V_258 -> V_201 . V_194 != V_260 ) {
V_44 = - V_45 ;
goto V_333;
}
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_333:
F_56 ( V_32 , V_33 , V_7 , V_27 ) ;
return V_44 ;
}
int F_208 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_261 = V_291 -> V_296 ;
struct V_356 * V_357 = V_116 -> V_118 ;
int V_327 = F_189 ( V_357 ) / V_32 -> V_62 . V_328 ;
struct V_222 * V_69 = NULL ;
struct V_216 * V_75 ;
V_44 = F_100 ( V_32 , V_33 , V_261 , V_263 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_51 ( V_32 , V_33 , V_327 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_362;
V_44 = F_172 ( V_32 , V_33 , V_327 , F_190 ( V_357 ) , V_75 ) ;
if ( V_44 )
goto V_363;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_363;
F_175 ( & V_75 -> V_214 ) ;
V_69 -> V_75 = V_75 ;
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
F_103 ( V_32 , V_33 , V_21 , V_261 ) ;
return 0 ;
V_363:
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
V_362:
F_102 ( V_32 , V_33 , V_21 , V_261 ) ;
return V_44 ;
}
int F_209 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_261 = V_291 -> V_296 ;
struct V_222 * V_69 = NULL ;
V_44 = F_100 ( V_32 , V_33 , V_261 , V_223 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_362;
F_177 ( & V_69 -> V_75 -> V_214 ) ;
F_103 ( V_32 , V_33 , V_21 , V_261 ) ;
return 0 ;
V_362:
F_102 ( V_32 , V_33 , V_21 , V_261 ) ;
return V_44 ;
}
int F_210 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_261 = V_291 -> V_296 ;
struct V_222 * V_69 ;
int V_44 ;
V_44 = F_51 ( V_32 , V_33 , V_261 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_201 . V_194 != V_263 )
goto V_333;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_333:
F_56 ( V_32 , V_33 , V_261 , V_21 ) ;
return V_44 ;
}
static int F_211 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 ,
struct V_222 * V_69 )
{
int V_44 ;
struct V_216 * V_401 ;
struct V_216 * V_75 ;
struct V_356 * V_357 = V_116 -> V_118 ;
int V_327 = F_189 ( V_357 ) / V_32 -> V_62 . V_328 ;
V_44 = F_51 ( V_32 , V_33 , V_69 -> V_75 -> V_201 . V_7 , V_24 , & V_401 ) ;
if ( V_44 )
return V_44 ;
if ( V_401 != V_69 -> V_75 ) {
V_44 = - V_45 ;
goto V_333;
}
V_44 = F_51 ( V_32 , V_33 , V_327 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_333;
V_44 = F_172 ( V_32 , V_33 , V_327 , F_190 ( V_357 ) , V_75 ) ;
if ( V_44 )
goto V_402;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_402;
F_177 ( & V_401 -> V_214 ) ;
F_56 ( V_32 , V_33 , V_401 -> V_201 . V_7 , V_24 ) ;
F_175 ( & V_75 -> V_214 ) ;
V_69 -> V_75 = V_75 ;
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
return 0 ;
V_402:
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
V_333:
F_56 ( V_32 , V_33 , V_401 -> V_201 . V_7 , V_24 ) ;
return V_44 ;
}
int F_212 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_261 = V_291 -> V_296 ;
struct V_222 * V_69 ;
int V_44 ;
V_44 = F_51 ( V_32 , V_33 , V_261 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_201 . V_194 != V_263 )
goto V_333;
if ( V_291 -> V_295 == 0 ) {
V_44 = F_211 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 , V_69 ) ;
goto V_333;
}
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_333:
F_56 ( V_32 , V_33 , V_261 , V_21 ) ;
return V_44 ;
}
static int F_213 ( struct V_305 * V_306 )
{
int V_403 = ( F_40 ( V_306 -> V_404 ) >> 24 ) & 0xf ;
int V_314 = V_306 -> V_405 & 7 ;
int V_307 = ( V_306 -> V_308 & 0x3f ) + 12 ;
if ( V_403 + V_314 + 4 < V_307 )
return 1 ;
return 1 << ( V_403 + V_314 + 4 - V_307 ) ;
}
int F_214 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_276 = V_291 -> V_296 ;
struct V_216 * V_75 ;
struct V_224 * V_72 = NULL ;
struct V_305 * V_306 = V_116 -> V_118 ;
int V_327 = F_169 ( V_306 ) / V_32 -> V_62 . V_328 ;
if ( V_276 != ( F_40 ( V_306 -> V_404 ) & 0xffffff ) )
return - V_45 ;
V_44 = F_101 ( V_32 , V_33 , V_276 , V_265 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_51 ( V_32 , V_33 , V_327 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_332;
V_44 = F_172 ( V_32 , V_33 , V_327 , F_213 ( V_306 ) ,
V_75 ) ;
if ( V_44 )
goto V_349;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_349;
F_175 ( & V_75 -> V_214 ) ;
V_72 -> V_75 = V_75 ;
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
F_103 ( V_32 , V_33 , V_22 , V_276 ) ;
return 0 ;
V_349:
F_56 ( V_32 , V_33 , V_75 -> V_201 . V_7 , V_24 ) ;
V_332:
F_102 ( V_32 , V_33 , V_22 , V_276 ) ;
return V_44 ;
}
int F_215 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_276 = V_291 -> V_296 ;
struct V_224 * V_72 = NULL ;
V_44 = F_101 ( V_32 , V_33 , V_276 , V_225 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_332;
F_177 ( & V_72 -> V_75 -> V_214 ) ;
if ( V_72 -> V_69 )
F_177 ( & V_72 -> V_69 -> V_214 ) ;
F_103 ( V_32 , V_33 , V_22 , V_276 ) ;
return 0 ;
V_332:
F_102 ( V_32 , V_33 , V_22 , V_276 ) ;
return V_44 ;
}
int F_216 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_276 = V_291 -> V_296 ;
struct V_224 * V_72 ;
V_44 = F_51 ( V_32 , V_33 , V_276 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_201 . V_194 != V_265 ) {
V_44 = - V_191 ;
goto V_59;
}
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_59:
F_56 ( V_32 , V_33 , V_276 , V_22 ) ;
return V_44 ;
}
int F_217 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_276 = V_291 -> V_296 ;
struct V_224 * V_72 ;
V_44 = F_51 ( V_32 , V_33 , V_276 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_201 . V_194 != V_265 ) {
V_44 = - V_191 ;
goto V_59;
}
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_59:
F_56 ( V_32 , V_33 , V_276 , V_22 ) ;
return V_44 ;
}
int F_218 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_139 = V_291 -> V_296 & 0x7fffff ;
struct V_209 * V_66 ;
V_44 = F_51 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_201 . V_194 != V_251 ) {
V_44 = - V_191 ;
goto V_59;
}
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_59:
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_219 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
struct V_122 * V_339 = V_116 -> V_118 + 8 ;
F_183 ( V_32 , V_291 , V_339 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_218 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
}
static int F_186 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
enum V_124 V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
T_2 V_406 ;
int V_36 = F_135 (
V_32 , V_33 , ( V_140 -> V_130 . V_131 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_406 = ( V_140 -> V_130 . V_131 & ~ ( 1 << 6 ) ) |
( ( V_36 & 1 ) << 6 ) ;
if ( V_125 & ( V_136 | V_407 ) ||
V_140 -> V_130 . V_131 || F_41 ( V_32 , V_36 + 1 ) ) {
V_140 -> V_130 . V_131 = V_406 ;
}
if ( V_125 & V_137 ) {
V_36 = F_135 (
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
static int F_220 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
T_1 V_278 ;
int V_36 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
T_2 V_117 = * ( T_2 * ) ( V_116 -> V_118 + 64 ) ;
T_2 V_408 ;
V_36 = ( V_117 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) && ( V_127 != V_148 ) ) {
V_408 = V_140 -> V_130 . V_186 & 0x7f ;
if ( F_128 ( V_32 , V_33 , V_36 , V_408 , & V_278 ) )
return - V_195 ;
}
return 0 ;
}
int F_221 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_139 = V_291 -> V_296 & 0x7fffff ;
struct V_209 * V_66 ;
T_2 V_409 ;
T_2 V_410 = V_140 -> V_130 . V_157 ;
T_2 V_411 = V_140 -> V_130 . V_171 ;
T_2 V_412 = V_140 -> V_130 . V_175 ;
T_2 V_413 = V_140 -> V_130 . V_173 ;
T_2 V_414 = V_140 -> V_130 . V_179 ;
V_44 = F_186 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_194 ( V_32 , V_291 , V_116 , V_371 , V_33 ) ;
if ( V_44 )
return V_44 ;
if ( F_220 ( V_32 , V_33 , V_140 , V_116 ) )
return - V_45 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_183 ( V_32 , V_291 , V_140 ) ;
V_409 = V_140 -> V_130 . V_131 ;
V_44 = F_51 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_201 . V_194 != V_251 ) {
V_44 = - V_191 ;
goto V_59;
}
V_44 = F_43 ( V_32 , V_116 , V_33 , V_139 ) ;
if ( V_44 )
goto V_59;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
V_59:
if ( ! V_44 ) {
V_66 -> V_131 = V_409 ;
V_66 -> V_157 = V_410 ;
V_66 -> V_171 = V_411 ;
V_66 -> V_347 = V_412 ;
V_66 -> V_173 = V_413 ;
V_66 -> V_179 = V_414 ;
}
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_222 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
struct V_122 * V_339 = V_116 -> V_118 + 8 ;
V_44 = F_186 ( V_32 , V_33 , V_339 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_194 ( V_32 , V_291 , V_116 , V_372 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_183 ( V_32 , V_291 , V_339 ) ;
return F_218 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
}
int F_223 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
struct V_122 * V_339 = V_116 -> V_118 + 8 ;
V_44 = F_186 ( V_32 , V_33 , V_339 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_194 ( V_32 , V_291 , V_116 , V_373 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_183 ( V_32 , V_291 , V_339 ) ;
return F_218 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
}
int F_224 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
struct V_122 * V_339 = V_116 -> V_118 + 8 ;
int V_44 = F_186 ( V_32 , V_33 , V_339 , V_116 ) ;
if ( V_44 )
return V_44 ;
F_183 ( V_32 , V_291 , V_339 ) ;
return F_218 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
}
int F_225 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
struct V_122 * V_339 = V_116 -> V_118 + 8 ;
V_44 = F_186 ( V_32 , V_33 , V_339 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_194 ( V_32 , V_291 , V_116 , V_374 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_183 ( V_32 , V_291 , V_339 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_218 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
}
int F_226 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
struct V_122 * V_339 = V_116 -> V_118 + 8 ;
V_44 = F_186 ( V_32 , V_33 , V_339 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_194 ( V_32 , V_291 , V_116 , V_375 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_183 ( V_32 , V_291 , V_339 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_218 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
}
int F_227 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_139 = V_291 -> V_296 & 0x7fffff ;
struct V_209 * V_66 ;
V_44 = F_97 ( V_32 , V_33 , V_139 , V_250 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
if ( V_44 )
goto V_332;
F_177 ( & V_66 -> V_75 -> V_214 ) ;
F_177 ( & V_66 -> V_342 -> V_214 ) ;
F_177 ( & V_66 -> V_343 -> V_214 ) ;
if ( V_66 -> V_72 )
F_177 ( & V_66 -> V_72 -> V_214 ) ;
F_103 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_332:
F_102 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static struct V_415 * F_228 ( struct V_31 * V_32 , int V_33 ,
struct V_209 * V_416 , T_2 * V_417 )
{
struct V_415 * V_11 ;
F_60 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_417 , V_417 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_229 ( struct V_31 * V_32 , int V_33 , struct V_209 * V_416 ,
T_2 * V_417 , enum V_418 V_419 ,
enum V_420 V_421 , T_1 V_422 )
{
struct V_415 * V_11 ;
int V_44 ;
V_11 = F_21 ( sizeof *V_11 , V_89 ) ;
if ( ! V_11 )
return - V_90 ;
F_52 ( & V_416 -> V_213 ) ;
if ( F_228 ( V_32 , V_33 , V_416 , V_417 ) ) {
F_31 ( V_11 ) ;
V_44 = - V_17 ;
} else {
memcpy ( V_11 -> V_417 , V_417 , 16 ) ;
V_11 -> V_419 = V_419 ;
V_11 -> V_421 = V_421 ;
V_11 -> V_422 = V_422 ;
F_79 ( & V_11 -> V_239 , & V_416 -> V_212 ) ;
V_44 = 0 ;
}
F_54 ( & V_416 -> V_213 ) ;
return V_44 ;
}
static int F_230 ( struct V_31 * V_32 , int V_33 , struct V_209 * V_416 ,
T_2 * V_417 , enum V_418 V_419 ,
enum V_420 V_421 , T_1 * V_422 )
{
struct V_415 * V_11 ;
int V_44 ;
F_52 ( & V_416 -> V_213 ) ;
V_11 = F_228 ( V_32 , V_33 , V_416 , V_417 ) ;
if ( ! V_11 || V_11 -> V_419 != V_419 || V_11 -> V_421 != V_421 )
V_44 = - V_45 ;
else {
* V_422 = V_11 -> V_422 ;
F_96 ( & V_11 -> V_239 ) ;
F_31 ( V_11 ) ;
V_44 = 0 ;
}
F_54 ( & V_416 -> V_213 ) ;
return V_44 ;
}
static int F_231 ( struct V_31 * V_32 , int V_33 , struct V_423 * V_66 ,
T_2 V_417 [ 16 ] , int V_424 , enum V_418 V_419 ,
enum V_420 type , T_1 * V_422 )
{
switch ( V_32 -> V_62 . V_425 ) {
case V_426 : {
int V_36 = F_135 ( V_32 , V_33 , V_417 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return F_232 ( V_32 , V_66 , V_417 , V_36 ,
V_424 , V_419 ,
V_422 ) ;
}
case V_427 :
if ( V_419 == V_428 ) {
int V_36 = F_135 ( V_32 , V_33 , V_417 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
V_417 [ 5 ] = V_36 ;
}
return F_233 ( V_32 , V_66 , V_417 ,
V_424 , V_419 , type ) ;
default:
return - V_45 ;
}
}
static int F_234 ( struct V_31 * V_32 , struct V_423 * V_66 ,
T_2 V_417 [ 16 ] , enum V_418 V_419 ,
enum V_420 type , T_1 V_422 )
{
switch ( V_32 -> V_62 . V_425 ) {
case V_426 :
return F_235 ( V_32 , V_422 ) ;
case V_427 :
return F_236 ( V_32 , V_66 , V_417 , V_419 , type ) ;
default:
return - V_45 ;
}
}
static int F_237 ( struct V_31 * V_32 , int V_33 ,
T_2 * V_417 , enum V_418 V_419 )
{
int V_429 ;
if ( V_419 != V_428 )
return 0 ;
if ( V_32 -> V_62 . V_425 == V_427 ||
V_32 -> V_62 . V_425 == V_426 ) {
V_429 = F_135 ( V_32 , V_33 , V_417 [ 5 ] ) ;
if ( V_429 < 0 )
return - V_45 ;
V_417 [ 5 ] = V_429 ;
}
return 0 ;
}
int F_238 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
struct V_423 V_66 ;
T_2 * V_417 = V_116 -> V_118 ;
enum V_418 V_419 = ( V_291 -> V_296 >> 28 ) & 0x7 ;
int V_44 ;
int V_139 ;
struct V_209 * V_416 ;
T_1 V_422 = 0 ;
int V_430 = V_291 -> V_295 ;
int V_424 = V_291 -> V_296 >> 31 ;
T_2 V_431 = 2 ;
enum V_420 type = ( V_417 [ 7 ] & V_431 ) >> 1 ;
V_139 = V_291 -> V_296 & 0xffffff ;
V_44 = F_51 ( V_32 , V_33 , V_139 , V_20 , & V_416 ) ;
if ( V_44 )
return V_44 ;
V_66 . V_139 = V_139 ;
if ( V_430 ) {
V_44 = F_231 ( V_32 , V_33 , & V_66 , V_417 , V_424 , V_419 ,
type , & V_422 ) ;
if ( V_44 ) {
F_74 ( L_27 , V_139 ) ;
goto V_333;
}
V_44 = F_229 ( V_32 , V_33 , V_416 , V_417 , V_419 , type , V_422 ) ;
if ( V_44 )
goto V_432;
} else {
V_44 = F_237 ( V_32 , V_33 , V_417 , V_419 ) ;
if ( V_44 )
goto V_333;
V_44 = F_230 ( V_32 , V_33 , V_416 , V_417 , V_419 , type , & V_422 ) ;
if ( V_44 )
goto V_333;
V_44 = F_234 ( V_32 , & V_66 , V_417 , V_419 , type , V_422 ) ;
if ( V_44 )
F_74 ( L_28 ,
V_139 , V_422 ) ;
}
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
V_432:
F_234 ( V_32 , & V_66 , V_417 , V_419 , type , V_422 ) ;
V_333:
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static int F_239 ( int V_33 , struct V_433 * V_434 ,
struct V_279 * V_435 )
{
struct V_281 * V_11 , * V_204 ;
T_5 V_436 ;
if ( ! F_240 ( V_434 -> V_437 . V_438 ) &&
! F_241 ( V_434 -> V_437 . V_438 ) ) {
F_129 (res, tmp, rlist, list) {
V_436 = F_242 ( V_11 -> V_278 << 16 ) ;
if ( F_243 ( ( T_2 * ) & V_436 , V_434 -> V_437 . V_438 ) )
return 0 ;
}
F_74 ( L_29 ,
V_434 -> V_437 . V_438 , V_33 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_244 ( struct V_31 * V_32 , int V_33 ,
struct V_115 * V_116 ,
struct V_279 * V_435 , int V_439 )
{
struct V_281 * V_11 , * V_204 ;
T_2 V_36 ;
struct V_440 * V_441 ;
struct V_442 * V_434 ;
struct V_443 * V_444 ;
struct V_445 * V_446 ;
T_5 V_436 = 0 ;
T_5 V_447 = F_242 ( V_448 << 16 ) ;
V_441 = (struct V_440 * ) V_116 -> V_118 ;
V_36 = V_441 -> V_36 ;
V_434 = (struct V_442 * ) ( V_441 + 1 ) ;
switch ( V_439 ) {
case V_449 :
V_444 =
(struct V_443 * ) ( V_434 + 1 ) ;
memmove ( V_444 , V_434 ,
sizeof( * V_444 ) + sizeof( * V_446 ) ) ;
break;
case V_450 :
case V_451 :
V_446 = (struct V_445 * )
( V_434 + 1 ) ;
memmove ( V_446 , V_434 , sizeof( * V_446 ) ) ;
break;
default:
return - V_45 ;
}
F_129 (res, tmp, rlist, list) {
if ( V_36 == V_11 -> V_36 ) {
V_436 = F_242 ( V_11 -> V_278 << 16 ) ;
break;
}
}
if ( ! V_436 ) {
F_74 ( L_30 ,
V_36 ) ;
return - V_45 ;
}
memset ( V_434 , 0 , sizeof( * V_434 ) ) ;
V_434 -> V_324 = sizeof( * V_434 ) >> 2 ;
V_434 -> V_196 = F_204 ( V_452 [ V_453 ] ) ;
memcpy ( V_434 -> V_438 , & V_436 , V_454 ) ;
memcpy ( V_434 -> V_455 , & V_447 , V_454 ) ;
return 0 ;
}
int F_245 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_456 )
{
int V_44 ;
T_3 V_139 = V_291 -> V_296 & 0xffffff ;
struct V_209 * V_416 ;
T_1 V_278 ;
unsigned V_36 ;
T_1 V_457 ;
struct V_458 * V_269 ;
int V_277 ;
V_269 = (struct V_458 * ) V_116 -> V_118 ;
V_457 = F_162 ( V_269 -> V_459 ) ;
if ( V_269 -> V_460 || V_269 -> V_461 ||
( V_457 & ~ V_462 ) )
return - V_193 ;
if ( ( V_457 &
( 1ULL << V_463 ) ) &&
! ( V_32 -> V_62 . V_161 &
V_464 ) ) {
F_10 ( V_32 , L_31 ,
V_33 ) ;
return - V_465 ;
}
V_44 = F_51 ( V_32 , V_33 , V_139 , V_20 , & V_416 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_32 , V_139 , V_33 ) ;
return V_44 ;
}
V_36 = ( V_416 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_457 & ( 1ULL << V_466 ) ) {
V_277 = V_269 -> V_467 . V_130 . V_186 ;
V_44 = F_128 ( V_32 , V_33 , V_36 ,
V_277 , & V_278 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_33 ,
V_139 , V_277 ) ;
goto V_468;
}
}
V_44 = F_205 ( V_32 , V_116 -> V_397 ,
V_291 -> V_296 , 0 ,
V_469 , V_470 ,
V_400 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_34 , V_139 ) ;
goto V_468;
}
V_468:
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static T_3 F_246 ( void * V_471 )
{
T_3 V_324 = sizeof( struct V_440 ) ;
struct V_433 * V_472 ;
V_472 = (struct V_433 * ) ( V_471 + V_324 ) ;
while ( V_472 -> V_324 ) {
V_324 += V_472 -> V_324 * sizeof( T_3 ) ;
V_472 += 1 ;
}
return V_324 ;
}
int F_247 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_435 = & V_203 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
int V_44 ;
int V_139 ;
struct V_209 * V_416 ;
struct V_440 * V_441 ;
struct V_433 * V_472 ;
int V_439 ;
struct V_229 * V_473 ;
T_3 V_474 ;
if ( V_32 -> V_62 . V_425 !=
V_426 )
return - V_475 ;
V_441 = (struct V_440 * ) V_116 -> V_118 ;
V_44 = F_135 ( V_32 , V_33 , V_441 -> V_36 ) ;
if ( V_44 <= 0 )
return - V_45 ;
V_441 -> V_36 = V_44 ;
V_139 = F_40 ( V_441 -> V_139 ) & 0xffffff ;
V_44 = F_51 ( V_32 , V_33 , V_139 , V_20 , & V_416 ) ;
if ( V_44 ) {
F_74 ( L_35 , V_139 ) ;
return V_44 ;
}
V_472 = (struct V_433 * ) ( V_441 + 1 ) ;
V_439 = F_248 ( F_249 ( V_472 -> V_196 ) ) ;
if ( V_439 == V_453 )
F_250 ( V_441 , V_472 ) ;
switch ( V_439 ) {
case V_453 :
if ( F_239 ( V_33 , V_472 , V_435 ) ) {
V_44 = - V_45 ;
goto V_476;
}
break;
case V_477 :
break;
case V_449 :
case V_450 :
case V_451 :
F_251 ( L_36 ) ;
if ( F_244 ( V_32 , V_33 , V_116 , V_435 , V_439 ) ) {
V_44 = - V_45 ;
goto V_476;
}
V_291 -> V_296 +=
sizeof( struct V_442 ) >> 2 ;
break;
default:
F_74 ( L_37 ) ;
V_44 = - V_45 ;
goto V_476;
}
V_44 = F_252 ( V_32 , V_116 -> V_397 , & V_291 -> V_271 ,
V_291 -> V_296 , 0 ,
V_478 , V_470 ,
V_400 ) ;
if ( V_44 )
goto V_476;
V_44 = F_78 ( V_32 , V_33 , V_291 -> V_271 , 1 , V_29 , V_139 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_38 ) ;
goto V_479;
}
V_44 = F_51 ( V_32 , V_33 , V_291 -> V_271 , V_29 , & V_473 ) ;
if ( V_44 )
goto V_479;
V_474 = F_246 ( V_116 -> V_118 ) ;
V_473 -> V_480 = F_25 ( V_474 , V_89 ) ;
if ( ! V_473 -> V_480 ) {
V_44 = - V_90 ;
goto V_481;
}
V_473 -> V_482 = V_474 ;
V_473 -> V_483 = 0 ;
memcpy ( V_473 -> V_480 , V_116 -> V_118 , V_474 ) ;
V_441 = (struct V_440 * ) V_473 -> V_480 ;
if ( V_441 -> V_36 == 1 )
V_441 -> V_36 = 2 ;
else
V_441 -> V_36 = 1 ;
if ( F_253 ( V_32 ) )
F_254 ( V_32 , V_473 ) ;
F_175 ( & V_416 -> V_214 ) ;
V_481:
F_56 ( V_32 , V_33 , V_291 -> V_271 , V_29 ) ;
V_479:
if ( V_44 )
F_205 ( V_32 , V_291 -> V_271 , 0 , 0 ,
V_484 , V_470 ,
V_400 ) ;
V_476:
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static int F_255 ( struct V_31 * V_32 , struct V_229 * V_485 )
{
int V_44 ;
V_44 = F_95 ( V_32 , V_485 -> V_201 . V_192 , V_485 -> V_201 . V_7 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_39 ) ;
return V_44 ;
}
F_205 ( V_32 , V_485 -> V_201 . V_7 , 0 , 0 , V_484 ,
V_470 , V_400 ) ;
return 0 ;
}
int F_256 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
struct V_209 * V_416 ;
struct V_229 * V_473 ;
T_1 V_486 ;
int V_139 ;
if ( V_32 -> V_62 . V_425 !=
V_426 )
return - V_475 ;
V_44 = F_51 ( V_32 , V_33 , V_291 -> V_270 , V_29 , & V_473 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_473 -> V_480 ) {
F_62 ( V_32 , L_40 ) ;
F_56 ( V_32 , V_33 , V_291 -> V_270 , V_29 ) ;
return - V_45 ;
}
V_486 = V_473 -> V_483 ;
F_31 ( V_473 -> V_480 ) ;
V_139 = V_473 -> V_139 ;
F_56 ( V_32 , V_33 , V_291 -> V_270 , V_29 ) ;
V_44 = F_51 ( V_32 , V_33 , V_139 , V_20 , & V_416 ) ;
if ( V_44 )
return V_44 ;
if ( V_486 && F_253 ( V_32 ) ) {
V_44 = F_51 ( V_32 , V_33 , V_486 , V_29 , & V_473 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_41 ) ;
} else {
F_56 ( V_32 , V_33 , V_486 , V_29 ) ;
F_255 ( V_32 , V_473 ) ;
}
}
V_44 = F_95 ( V_32 , V_33 , V_291 -> V_270 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_62 ( V_32 , L_39 ) ;
goto V_59;
}
V_44 = F_205 ( V_32 , V_291 -> V_270 , 0 , 0 ,
V_484 , V_470 ,
V_400 ) ;
if ( ! V_44 )
F_177 ( & V_416 -> V_214 ) ;
V_59:
F_56 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_257 ( struct V_31 * V_32 , int V_33 ,
struct V_290 * V_291 ,
struct V_115 * V_116 ,
struct V_115 * V_292 ,
struct V_293 * V_269 )
{
int V_44 ;
int V_253 = V_291 -> V_296 & 0xffff ;
V_44 = F_51 ( V_32 , V_33 , V_253 , V_28 , NULL ) ;
if ( V_44 )
return V_44 ;
V_44 = F_174 ( V_32 , V_33 , V_291 , V_116 , V_292 , V_269 ) ;
F_56 ( V_32 , V_33 , V_253 , V_28 ) ;
return V_44 ;
}
static void F_258 ( struct V_31 * V_32 , int V_33 , struct V_209 * V_416 )
{
struct V_415 * V_487 ;
struct V_415 * V_204 ;
struct V_423 V_66 ;
F_129 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_32 -> V_62 . V_425 ) {
case V_426 :
F_235 ( V_32 , V_487 -> V_422 ) ;
break;
case V_427 :
V_66 . V_139 = V_416 -> V_211 ;
( void ) F_236 ( V_32 , & V_66 , V_487 -> V_417 ,
V_487 -> V_419 , V_487 -> V_421 ) ;
break;
}
F_96 ( & V_487 -> V_239 ) ;
F_31 ( V_487 ) ;
}
}
static int F_259 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_488 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_435 = & V_203 -> V_87 [ V_33 ] . V_92 [ type ] ;
struct V_10 * V_188 ;
struct V_10 * V_204 ;
int V_489 ;
V_489 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (r, tmp, rlist, list) {
if ( V_188 -> V_192 == V_33 ) {
if ( ! V_188 -> V_490 ) {
if ( V_188 -> V_2 == V_190 ) {
if ( V_488 )
F_24 ( V_32 ,
L_42 ,
F_7 ( type ) ,
V_188 -> V_7 ) ;
++ V_489 ;
} else {
V_188 -> V_194 = V_188 -> V_2 ;
V_188 -> V_2 = V_190 ;
V_188 -> V_490 = 1 ;
}
}
}
}
F_54 ( F_53 ( V_32 ) ) ;
return V_489 ;
}
static int F_260 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type )
{
unsigned long V_491 ;
int V_489 ;
V_491 = V_492 ;
do {
V_489 = F_259 ( V_32 , V_33 , type , 0 ) ;
if ( F_261 ( V_492 , V_491 + 5 * V_493 ) )
break;
if ( V_489 )
F_262 () ;
} while ( V_489 );
if ( V_489 )
V_489 = F_259 ( V_32 , V_33 , type , 1 ) ;
return V_489 ;
}
static void F_263 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_494 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_20 ] ;
struct V_209 * V_66 ;
struct V_209 * V_204 ;
int V_2 ;
T_1 V_270 ;
int V_139 ;
int V_44 ;
V_44 = F_260 ( V_32 , V_33 , V_20 ) ;
if ( V_44 )
F_10 ( V_32 , L_43 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (qp, tmp, qp_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_66 -> V_201 . V_192 == V_33 ) {
V_139 = V_66 -> V_201 . V_7 ;
F_258 ( V_32 , V_33 , V_66 ) ;
V_2 = V_66 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_210 :
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_66 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_20 ] ) ;
F_96 ( & V_66 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
if ( ! F_104 ( V_32 , V_33 , V_139 ) ) {
F_112 ( V_32 , V_139 , 1 ) ;
F_12 ( V_32 , V_33 ,
V_20 , 1 , 0 ) ;
}
F_31 ( V_66 ) ;
V_2 = 0 ;
break;
case V_250 :
if ( ! F_104 ( V_32 , V_33 , V_139 ) )
F_149 ( V_32 , V_139 ) ;
V_2 = V_210 ;
break;
case V_251 :
V_270 = V_33 ;
V_44 = F_205 ( V_32 , V_270 ,
V_66 -> V_211 , 2 ,
V_495 ,
V_470 ,
V_400 ) ;
if ( V_44 )
F_24 ( V_32 , L_44 ,
V_33 , V_66 -> V_211 ) ;
F_177 ( & V_66 -> V_342 -> V_214 ) ;
F_177 ( & V_66 -> V_343 -> V_214 ) ;
F_177 ( & V_66 -> V_75 -> V_214 ) ;
if ( V_66 -> V_72 )
F_177 ( & V_66 -> V_72 -> V_214 ) ;
V_2 = V_250 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_264 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_496 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_22 ] ;
struct V_224 * V_72 ;
struct V_224 * V_204 ;
int V_2 ;
T_1 V_270 ;
F_265 ( V_497 ) ;
int V_276 ;
int V_44 ;
V_44 = F_260 ( V_32 , V_33 , V_22 ) ;
if ( V_44 )
F_10 ( V_32 , L_45 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (srq, tmp, srq_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_72 -> V_201 . V_192 == V_33 ) {
V_276 = V_72 -> V_201 . V_7 ;
V_2 = V_72 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_225 :
F_127 ( V_32 , V_276 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_72 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_22 ] ) ;
F_96 ( & V_72 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_22 , 1 , 0 ) ;
F_31 ( V_72 ) ;
V_2 = 0 ;
break;
case V_265 :
V_270 = V_33 ;
V_44 = F_205 ( V_32 , V_270 , V_276 , 1 ,
V_498 ,
V_470 ,
V_400 ) ;
if ( V_44 )
F_24 ( V_32 , L_46 ,
V_33 , V_276 ) ;
F_177 ( & V_72 -> V_75 -> V_214 ) ;
if ( V_72 -> V_69 )
F_177 ( & V_72 -> V_69 -> V_214 ) ;
V_2 = V_225 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_266 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_499 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_21 ] ;
struct V_222 * V_69 ;
struct V_222 * V_204 ;
int V_2 ;
T_1 V_270 ;
F_265 ( V_497 ) ;
int V_261 ;
int V_44 ;
V_44 = F_260 ( V_32 , V_33 , V_21 ) ;
if ( V_44 )
F_10 ( V_32 , L_47 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (cq, tmp, cq_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_69 -> V_201 . V_192 == V_33 && ! F_83 ( & V_69 -> V_214 ) ) {
V_261 = V_69 -> V_201 . V_7 ;
V_2 = V_69 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_223 :
F_124 ( V_32 , V_261 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_69 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_21 ] ) ;
F_96 ( & V_69 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_21 , 1 , 0 ) ;
F_31 ( V_69 ) ;
V_2 = 0 ;
break;
case V_263 :
V_270 = V_33 ;
V_44 = F_205 ( V_32 , V_270 , V_261 , 1 ,
V_500 ,
V_470 ,
V_400 ) ;
if ( V_44 )
F_24 ( V_32 , L_48 ,
V_33 , V_261 ) ;
F_177 ( & V_69 -> V_75 -> V_214 ) ;
V_2 = V_223 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_267 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_501 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_23 ] ;
struct V_218 * V_77 ;
struct V_218 * V_204 ;
int V_2 ;
T_1 V_270 ;
F_265 ( V_497 ) ;
int V_502 ;
int V_44 ;
V_44 = F_260 ( V_32 , V_33 , V_23 ) ;
if ( V_44 )
F_10 ( V_32 , L_49 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (mpt, tmp, mpt_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_77 -> V_201 . V_192 == V_33 ) {
V_502 = V_77 -> V_201 . V_7 ;
V_2 = V_77 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_219 :
F_120 ( V_32 , V_77 -> V_217 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_77 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_23 ] ) ;
F_96 ( & V_77 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_23 , 1 , 0 ) ;
F_31 ( V_77 ) ;
V_2 = 0 ;
break;
case V_255 :
F_152 ( V_32 , V_77 -> V_217 ) ;
V_2 = V_219 ;
break;
case V_256 :
V_270 = V_33 ;
V_44 = F_205 ( V_32 , V_270 , V_502 , 0 ,
V_503 ,
V_470 ,
V_400 ) ;
if ( V_44 )
F_24 ( V_32 , L_50 ,
V_33 , V_502 ) ;
if ( V_77 -> V_75 )
F_177 ( & V_77 -> V_75 -> V_214 ) ;
V_2 = V_255 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_268 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_504 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_24 ] ;
struct V_216 * V_75 ;
struct V_216 * V_204 ;
int V_2 ;
F_265 ( V_497 ) ;
int V_236 ;
int V_44 ;
V_44 = F_260 ( V_32 , V_33 , V_24 ) ;
if ( V_44 )
F_10 ( V_32 , L_51 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (mtt, tmp, mtt_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_75 -> V_201 . V_192 == V_33 ) {
V_236 = V_75 -> V_201 . V_7 ;
V_2 = V_75 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_117 ( V_32 , V_236 ,
V_75 -> V_215 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_75 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_24 ] ) ;
F_96 ( & V_75 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
F_12 ( V_32 , V_33 , V_24 ,
1 << V_75 -> V_215 , 0 ) ;
F_31 ( V_75 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static int F_254 ( struct V_31 * V_32 , struct V_229 * V_485 )
{
struct V_115 * V_388 ;
int V_44 ;
struct V_229 * V_505 ;
T_1 V_422 ;
V_388 = F_201 ( V_32 ) ;
if ( F_202 ( V_388 ) )
return F_203 ( V_388 ) ;
if ( ! V_485 -> V_480 ) {
F_62 ( V_32 , L_52 ) ;
return - V_45 ;
}
memcpy ( V_388 -> V_118 , V_485 -> V_480 , V_485 -> V_482 ) ;
V_44 = F_252 ( V_32 , V_388 -> V_397 , & V_422 , V_485 -> V_482 >> 2 , 0 ,
V_478 , V_470 ,
V_400 ) ;
F_206 ( V_32 , V_388 ) ;
if ( V_44 )
goto V_44;
V_44 = F_78 ( V_32 , V_485 -> V_201 . V_192 , V_422 , 1 , V_29 , V_485 -> V_139 ) ;
if ( V_44 )
goto V_479;
V_44 = F_51 ( V_32 , V_485 -> V_201 . V_192 , V_422 , V_29 , & V_505 ) ;
if ( V_44 )
goto V_506;
V_485 -> V_483 = V_422 ;
V_505 -> V_483 = 0 ;
V_505 -> V_482 = 0 ;
V_505 -> V_480 = NULL ;
F_56 ( V_32 , V_485 -> V_201 . V_192 , V_422 , V_29 ) ;
return 0 ;
V_506:
F_95 ( V_32 , V_485 -> V_201 . V_192 , V_422 , 1 , V_29 , 0 ) ;
V_479:
F_205 ( V_32 , V_422 , 0 , 0 , V_484 ,
V_470 , V_400 ) ;
V_44:
return V_44 ;
}
static int F_269 ( struct V_31 * V_32 , bool V_507 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_203 -> V_94 [ V_29 ] ;
struct V_8 * V_508 ;
struct V_229 * V_485 ;
int V_44 = 0 ;
F_265 ( V_509 ) ;
for ( V_508 = F_270 ( V_6 ) ; V_508 ; V_508 = F_271 ( V_508 ) ) {
V_485 = F_272 ( V_508 , struct V_229 , V_201 . V_9 ) ;
if ( ( V_507 && V_485 -> V_482 ) ||
( ! V_507 && ! V_485 -> V_482 ) )
F_79 ( & V_485 -> V_509 , & V_509 ) ;
}
F_60 (fs_rule, &mirr_list, mirr_list) {
if ( V_507 )
V_44 += F_254 ( V_32 , V_485 ) ;
else
V_44 += F_255 ( V_32 , V_485 ) ;
}
return V_44 ;
}
int F_273 ( struct V_31 * V_32 )
{
return F_269 ( V_32 , true ) ;
}
int F_274 ( struct V_31 * V_32 )
{
return F_269 ( V_32 , false ) ;
}
static void F_275 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_510 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_29 ] ;
struct V_229 * V_485 ;
struct V_229 * V_204 ;
int V_2 ;
T_1 V_236 ;
int V_44 ;
V_44 = F_260 ( V_32 , V_33 , V_29 ) ;
if ( V_44 )
F_10 ( V_32 , L_53 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (fs_rule, tmp, fs_rule_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_485 -> V_201 . V_192 == V_33 ) {
V_236 = V_485 -> V_201 . V_7 ;
V_2 = V_485 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_230 :
V_44 = F_205 ( V_32 , V_236 , 0 , 0 ,
V_484 ,
V_470 ,
V_400 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_485 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_29 ] ) ;
F_96 ( & V_485 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
F_31 ( V_485 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_276 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_511 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_27 ] ;
struct V_220 * V_258 ;
struct V_220 * V_204 ;
int V_44 ;
int V_2 ;
F_265 ( V_497 ) ;
int V_360 ;
V_44 = F_260 ( V_32 , V_33 , V_27 ) ;
if ( V_44 )
F_10 ( V_32 , L_54 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (eq, tmp, eq_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_258 -> V_201 . V_192 == V_33 ) {
V_360 = V_258 -> V_201 . V_7 ;
V_2 = V_258 -> V_201 . V_194 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_221 :
F_52 ( F_53 ( V_32 ) ) ;
F_80 ( & V_258 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_27 ] ) ;
F_96 ( & V_258 -> V_201 . V_239 ) ;
F_54 ( F_53 ( V_32 ) ) ;
F_31 ( V_258 ) ;
V_2 = 0 ;
break;
case V_260 :
V_44 = F_205 ( V_32 , V_33 , V_360 & 0x3ff ,
1 , V_512 ,
V_470 ,
V_400 ) ;
if ( V_44 )
F_24 ( V_32 , L_55 ,
V_33 , V_360 & 0x3ff ) ;
F_177 ( & V_258 -> V_75 -> V_214 ) ;
V_2 = V_221 ;
break;
default:
V_2 = 0 ;
}
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
}
static void F_277 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_513 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_28 ] ;
struct V_198 * V_199 ;
struct V_198 * V_204 ;
int V_44 ;
int * V_234 = NULL ;
int V_83 , V_84 ;
V_44 = F_260 ( V_32 , V_33 , V_28 ) ;
if ( V_44 )
F_10 ( V_32 , L_56 ,
V_33 ) ;
V_234 = F_76 ( V_32 -> V_62 . V_80 ,
sizeof( * V_234 ) , V_89 ) ;
if ( ! V_234 )
return;
do {
V_83 = 0 ;
V_84 = 0 ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (counter, tmp, counter_list, com.list) {
if ( V_199 -> V_201 . V_192 == V_33 ) {
V_234 [ V_83 ++ ] = V_199 -> V_201 . V_7 ;
F_80 ( & V_199 -> V_201 . V_9 ,
& V_203 -> V_94 [ V_28 ] ) ;
F_96 ( & V_199 -> V_201 . V_239 ) ;
F_31 ( V_199 ) ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
while ( V_84 < V_83 ) {
F_143 ( V_32 , V_234 [ V_84 ++ ] ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
}
} while ( V_83 );
F_31 ( V_234 ) ;
}
static void F_278 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_202 * V_203 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_514 =
& V_203 -> V_87 [ V_33 ] . V_92 [ V_30 ] ;
struct V_227 * V_515 ;
struct V_227 * V_204 ;
int V_44 ;
int V_289 ;
V_44 = F_260 ( V_32 , V_33 , V_30 ) ;
if ( V_44 )
F_10 ( V_32 , L_57 ,
V_33 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_515 -> V_201 . V_192 == V_33 ) {
V_289 = V_515 -> V_201 . V_7 ;
F_80 ( & V_515 -> V_201 . V_9 , & V_203 -> V_94 [ V_30 ] ) ;
F_96 ( & V_515 -> V_201 . V_239 ) ;
F_31 ( V_515 ) ;
F_146 ( V_32 , V_289 ) ;
}
}
F_54 ( F_53 ( V_32 ) ) ;
}
void F_33 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
F_34 ( V_32 , V_33 ) ;
F_35 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
F_36 ( V_32 , V_33 ) ;
F_132 ( V_32 , V_33 ) ;
F_275 ( V_32 , V_33 ) ;
F_263 ( V_32 , V_33 ) ;
F_264 ( V_32 , V_33 ) ;
F_266 ( V_32 , V_33 ) ;
F_267 ( V_32 , V_33 ) ;
F_276 ( V_32 , V_33 ) ;
F_268 ( V_32 , V_33 ) ;
F_277 ( V_32 , V_33 ) ;
F_278 ( V_32 , V_33 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
}
void F_279 ( struct V_516 * V_517 )
{
struct V_518 * V_519 =
F_3 ( V_517 , struct V_518 , V_519 ) ;
struct V_115 * V_388 ;
struct V_458 * V_520 ;
struct V_31 * V_32 = & V_519 -> V_38 -> V_32 ;
struct V_202 * V_203 =
& V_519 -> V_38 -> V_41 . V_42 . V_43 ;
struct V_279 * V_494 =
& V_203 -> V_87 [ V_519 -> V_33 ] . V_92 [ V_20 ] ;
struct V_209 * V_66 ;
struct V_209 * V_204 ;
T_1 V_521 =
( ( 1ULL << V_522 ) |
( 1ULL << V_523 ) |
( 1ULL << V_524 ) |
( 1ULL << V_525 ) |
( 1ULL << V_526 ) |
( 1ULL << V_527 ) ) ;
T_1 V_528 = ( ( 1ULL << V_529 ) |
( 1ULL << V_530 ) |
( 1ULL << V_531 ) |
( 1ULL << V_532 ) |
( 1ULL << V_533 ) |
( 1ULL << V_534 ) |
( 1ULL << V_535 ) |
( 1ULL << V_536 ) ) ;
int V_44 ;
int V_36 , V_537 = 0 ;
T_2 V_157 ;
if ( F_16 ( V_32 ) ) {
F_10 ( V_32 , L_58 ,
V_519 -> V_33 ) ;
goto V_59;
}
V_388 = F_201 ( V_32 ) ;
if ( F_202 ( V_388 ) )
goto V_59;
if ( V_519 -> V_128 & V_538 )
V_157 = V_163 |
V_164 |
V_165 |
V_166 |
V_167 |
V_168 ;
else if ( ! V_519 -> V_539 )
V_157 = V_163 |
V_168 ;
else if ( V_519 -> V_169 == F_48 ( V_170 ) )
V_157 = V_164 |
V_163 |
V_166 |
V_167 ;
else
V_157 = V_163 |
V_166 |
V_167 ;
V_520 = V_388 -> V_118 ;
V_520 -> V_460 = F_242 ( 1ULL << V_540 ) ;
F_52 ( F_53 ( V_32 ) ) ;
F_129 (qp, tmp, qp_list, com.list) {
F_54 ( F_53 ( V_32 ) ) ;
if ( V_66 -> V_201 . V_192 == V_519 -> V_33 ) {
if ( V_66 -> V_201 . V_194 != V_251 ||
! V_66 -> V_131 ||
F_45 ( V_32 , V_66 -> V_211 ) ||
V_66 -> V_348 & ( 1 << V_541 ) ) {
F_52 ( F_53 ( V_32 ) ) ;
continue;
}
V_36 = ( V_66 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_36 != V_519 -> V_36 ) {
F_52 ( F_53 ( V_32 ) ) ;
continue;
}
if ( V_133 == ( ( V_66 -> V_348 >> 16 ) & 0xff ) )
V_520 -> V_459 = F_242 ( V_528 ) ;
else
V_520 -> V_459 =
F_242 ( V_528 | V_521 ) ;
if ( V_519 -> V_539 == V_146 ) {
V_520 -> V_467 . V_152 = V_66 -> V_152 ;
V_520 -> V_467 . V_130 . V_157 = V_66 -> V_157 ;
V_520 -> V_467 . V_130 . V_171 = V_66 -> V_171 ;
V_520 -> V_467 . V_130 . V_173 = V_66 -> V_173 ;
V_520 -> V_467 . V_130 . V_175 = V_66 -> V_347 ;
V_520 -> V_467 . V_130 . V_179 = V_66 -> V_179 ;
V_520 -> V_467 . V_130 . V_131 =
V_66 -> V_131 ;
} else {
V_520 -> V_467 . V_152 = V_66 -> V_152 & ~ F_46 ( V_153 ) ;
V_520 -> V_467 . V_130 . V_157 = V_157 ;
V_520 -> V_467 . V_130 . V_173 = V_519 -> V_542 ;
V_520 -> V_467 . V_130 . V_171 =
V_66 -> V_171 | V_172 ;
V_520 -> V_467 . V_130 . V_175 =
V_66 -> V_347 | V_176 ;
if ( V_519 -> V_169 == F_48 ( V_170 ) )
V_520 -> V_467 . V_130 . V_175 |= V_177 ;
else
V_520 -> V_467 . V_130 . V_175 |= V_178 ;
V_520 -> V_467 . V_130 . V_179 =
V_66 -> V_179 | V_180 | V_181 ;
V_520 -> V_467 . V_130 . V_131 =
V_66 -> V_131 & 0xC7 ;
V_520 -> V_467 . V_130 . V_131 |=
( ( V_519 -> V_543 & 0x7 ) << 3 ) ;
V_520 -> V_460 |=
F_242 ( 1ULL <<
V_544 ) ;
V_520 -> V_467 . V_183 =
V_519 -> V_183 ;
}
V_44 = F_205 ( V_32 , V_388 -> V_397 ,
V_66 -> V_211 & 0xffffff ,
0 , V_469 ,
V_545 , V_400 ) ;
if ( V_44 ) {
F_280 ( V_32 , L_59 ,
V_519 -> V_33 , V_36 , V_66 -> V_211 , V_44 ) ;
V_537 ++ ;
}
}
F_52 ( F_53 ( V_32 ) ) ;
}
F_54 ( F_53 ( V_32 ) ) ;
F_206 ( V_32 , V_388 ) ;
if ( V_537 )
F_62 ( V_32 , L_60 ,
V_537 , V_519 -> V_33 , V_519 -> V_36 ) ;
if ( V_519 -> V_128 & V_546 && ! V_537 &&
V_547 != V_519 -> V_548 )
F_139 ( & V_519 -> V_38 -> V_32 , V_519 -> V_36 ,
V_519 -> V_549 ) ;
V_59:
F_31 ( V_519 ) ;
return;
}
