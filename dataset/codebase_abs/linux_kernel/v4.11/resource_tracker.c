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
static const char * F_50 ( enum V_18 V_85 )
{
switch ( V_85 ) {
case V_20 :
return L_19 ;
case V_21 :
return L_20 ;
case V_22 :
return L_21 ;
case V_30 :
return L_22 ;
case V_23 :
return L_23 ;
case V_24 :
return L_24 ;
case V_25 :
return L_25 ;
case V_26 :
return L_26 ;
case V_28 :
return L_27 ;
case V_29 :
return L_28 ;
case V_27 :
return L_29 ;
default:
return L_30 ;
}
}
static void * F_51 ( struct V_31 * V_32 , T_1 V_7 ,
enum V_18 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
return F_2 ( & V_38 -> V_41 . V_42 . V_43 . V_94 [ type ] ,
V_7 ) ;
}
static int F_52 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type ,
void * V_11 , const char * V_188 )
{
struct V_10 * V_189 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_51 ( V_32 , V_7 , type ) ;
if ( ! V_189 ) {
V_44 = - V_190 ;
goto exit;
}
if ( V_189 -> V_2 == V_191 ) {
F_10 ( V_32 ,
L_31 ,
V_188 , V_33 , V_7 , F_50 ( type ) ,
V_189 -> V_188 ) ;
V_44 = - V_192 ;
goto exit;
}
if ( V_189 -> V_193 != V_33 ) {
V_44 = - V_194 ;
goto exit;
}
V_189 -> V_195 = V_189 -> V_2 ;
V_189 -> V_2 = V_191 ;
V_189 -> V_188 = V_188 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_189 ;
exit:
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
int F_56 ( struct V_31 * V_32 ,
enum V_18 type ,
T_1 V_7 , int * V_33 )
{
struct V_10 * V_189 ;
int V_44 = - V_196 ;
int V_197 = V_7 ;
if ( type == V_20 )
V_197 &= 0x7fffff ;
F_9 ( F_54 ( V_32 ) ) ;
V_189 = F_51 ( V_32 , V_197 , type ) ;
if ( V_189 ) {
* V_33 = V_189 -> V_193 ;
V_44 = 0 ;
}
F_11 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static void F_57 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_189 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_51 ( V_32 , V_7 , type ) ;
if ( V_189 ) {
V_189 -> V_2 = V_189 -> V_195 ;
V_189 -> V_188 = L_32 ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static int F_58 ( struct V_31 * V_32 , T_2 V_33 , int V_36 ,
int V_198 )
{
struct V_10 * V_189 ;
struct V_199 * V_200 ;
int V_201 = 0 ;
if ( V_198 == F_59 ( V_32 ) )
return V_201 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_51 ( V_32 , V_198 , V_28 ) ;
if ( ! V_189 || V_189 -> V_193 != V_33 ) {
V_201 = - V_45 ;
} else {
V_200 = F_60 ( V_189 , struct V_199 , V_202 ) ;
if ( ! V_200 -> V_36 )
V_200 -> V_36 = V_36 ;
}
F_55 ( F_54 ( V_32 ) ) ;
return V_201 ;
}
static int F_61 ( struct V_31 * V_32 ,
struct V_122 * V_140 , T_2 V_33 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_205 ;
struct V_199 * V_200 ;
T_1 V_206 = F_59 ( V_32 ) ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
F_62 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_200 = F_60 ( V_205 , struct V_199 , V_202 ) ;
if ( V_36 == V_200 -> V_36 ) {
V_140 -> V_130 . V_198 = V_200 -> V_202 . V_7 ;
F_55 ( F_54 ( V_32 ) ) ;
return 0 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
V_44 = F_63 ( V_32 , V_33 , V_207 , 0 , 0 , & V_206 ,
V_36 ) ;
if ( V_44 == - V_196 ) {
V_44 = 0 ;
} else if ( V_44 && V_44 != - V_208 ) {
F_64 ( V_32 , L_33 ,
V_209 , V_33 , V_44 ) ;
} else {
V_140 -> V_130 . V_198 = V_206 ;
F_24 ( V_32 , L_34 ,
V_209 , V_33 , V_140 -> V_130 . V_198 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_44 ( struct V_31 * V_32 , struct V_122 * V_140 ,
T_2 V_33 , int V_36 )
{
if ( V_140 -> V_130 . V_198 != F_59 ( V_32 ) )
return F_58 ( V_32 , V_33 , V_36 ,
V_140 -> V_130 . V_198 ) ;
return F_61 ( V_32 , V_140 , V_33 , V_36 ) ;
}
static struct V_10 * F_65 ( int V_197 )
{
struct V_210 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_211 ;
V_201 -> V_212 = V_197 ;
F_22 ( & V_201 -> V_213 ) ;
F_26 ( & V_201 -> V_214 ) ;
F_66 ( & V_201 -> V_215 , 0 ) ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_67 ( int V_197 , int V_216 )
{
struct V_217 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_216 = V_216 ;
V_201 -> V_202 . V_2 = V_4 ;
F_66 ( & V_201 -> V_215 , 0 ) ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_68 ( int V_197 , int V_218 )
{
struct V_219 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_220 ;
V_201 -> V_218 = V_218 ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_69 ( int V_197 )
{
struct V_221 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_222 ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_70 ( int V_197 )
{
struct V_223 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_224 ;
F_66 ( & V_201 -> V_215 , 0 ) ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_71 ( int V_197 )
{
struct V_225 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_226 ;
F_66 ( & V_201 -> V_215 , 0 ) ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_72 ( int V_197 , int V_36 )
{
struct V_199 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_227 ;
V_201 -> V_36 = V_36 ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_73 ( int V_197 )
{
struct V_228 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_229 ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_74 ( T_1 V_197 , int V_139 )
{
struct V_230 * V_201 ;
V_201 = F_21 ( sizeof *V_201 , V_89 ) ;
if ( ! V_201 )
return NULL ;
V_201 -> V_202 . V_7 = V_197 ;
V_201 -> V_202 . V_2 = V_231 ;
V_201 -> V_139 = V_139 ;
return & V_201 -> V_202 ;
}
static struct V_10 * F_75 ( T_1 V_197 , enum V_18 type , int V_33 ,
int V_232 )
{
struct V_10 * V_201 ;
switch ( type ) {
case V_20 :
V_201 = F_65 ( V_197 ) ;
break;
case V_23 :
V_201 = F_68 ( V_197 , V_232 ) ;
break;
case V_24 :
V_201 = F_67 ( V_197 , V_232 ) ;
break;
case V_27 :
V_201 = F_69 ( V_197 ) ;
break;
case V_21 :
V_201 = F_70 ( V_197 ) ;
break;
case V_22 :
V_201 = F_71 ( V_197 ) ;
break;
case V_25 :
F_76 ( L_35 ) ;
return NULL ;
case V_28 :
V_201 = F_72 ( V_197 , V_232 ) ;
break;
case V_30 :
V_201 = F_73 ( V_197 ) ;
break;
case V_29 :
V_201 = F_74 ( V_197 , V_232 ) ;
break;
default:
return NULL ;
}
if ( V_201 )
V_201 -> V_193 = V_33 ;
return V_201 ;
}
int F_77 ( struct V_31 * V_32 , int V_33 , int V_36 ,
struct V_233 * V_234 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_205 ;
struct V_199 * V_200 ;
int * V_235 ;
int V_83 = 0 , V_44 = 0 ;
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
V_235 = F_78 ( V_32 -> V_62 . V_80 ,
sizeof( * V_235 ) , V_89 ) ;
if ( ! V_235 )
return - V_90 ;
F_53 ( F_54 ( V_32 ) ) ;
F_62 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_200 = F_60 ( V_205 , struct V_199 , V_202 ) ;
if ( V_200 -> V_36 == V_36 ) {
V_235 [ V_83 ] = ( int ) V_205 -> V_7 ;
V_83 ++ ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
V_235 [ V_83 ] = - 1 ;
V_83 = 0 ;
while ( V_235 [ V_83 ] != - 1 ) {
V_44 = F_79 ( V_32 , V_235 [ V_83 ] , V_234 ,
0 ) ;
if ( V_44 ) {
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
goto V_236;
}
V_83 ++ ;
}
V_236:
F_31 ( V_235 ) ;
return 0 ;
}
static int F_80 ( struct V_31 * V_32 , int V_33 , T_1 V_237 , int V_35 ,
enum V_18 type , int V_232 )
{
int V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_10 * * V_238 ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_204 -> V_94 [ type ] ;
V_238 = F_21 ( V_35 * sizeof *V_238 , V_89 ) ;
if ( ! V_238 )
return - V_90 ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
V_238 [ V_83 ] = F_75 ( V_237 + V_83 , type , V_33 , V_232 ) ;
if ( ! V_238 [ V_83 ] ) {
for ( -- V_83 ; V_83 >= 0 ; -- V_83 )
F_31 ( V_238 [ V_83 ] ) ;
F_31 ( V_238 ) ;
return - V_90 ;
}
}
F_53 ( F_54 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 ) {
if ( F_51 ( V_32 , V_237 + V_83 , type ) ) {
V_44 = - V_17 ;
goto V_239;
}
V_44 = F_4 ( V_6 , V_238 [ V_83 ] ) ;
if ( V_44 )
goto V_239;
F_81 ( & V_238 [ V_83 ] -> V_240 ,
& V_204 -> V_87 [ V_33 ] . V_92 [ type ] ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
F_31 ( V_238 ) ;
return 0 ;
V_239:
for ( -- V_83 ; V_83 >= 0 ; -- V_83 ) {
F_82 ( & V_238 [ V_83 ] -> V_9 , V_6 ) ;
F_83 ( & V_238 [ V_83 ] -> V_240 ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
for ( V_83 = 0 ; V_83 < V_35 ; ++ V_83 )
F_31 ( V_238 [ V_83 ] ) ;
F_31 ( V_238 ) ;
return V_44 ;
}
static int F_84 ( struct V_210 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_241 || F_85 ( & V_11 -> V_215 ) ||
! F_86 ( & V_11 -> V_213 ) ) {
F_76 ( L_36 ,
V_11 -> V_202 . V_2 , F_85 ( & V_11 -> V_215 ) ) ;
return - V_192 ;
} else if ( V_11 -> V_202 . V_2 != V_211 ) {
return - V_194 ;
}
return 0 ;
}
static int F_87 ( struct V_217 * V_11 , int V_216 )
{
if ( V_11 -> V_202 . V_2 == V_3 ||
F_85 ( & V_11 -> V_215 ) ) {
F_88 ( L_37 ,
V_209 , __LINE__ ,
F_1 ( V_11 -> V_202 . V_2 ) ,
F_85 ( & V_11 -> V_215 ) ) ;
return - V_192 ;
} else if ( V_11 -> V_202 . V_2 != V_4 )
return - V_194 ;
else if ( V_11 -> V_216 != V_216 )
return - V_45 ;
return 0 ;
}
static int F_89 ( struct V_219 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_242 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_220 )
return - V_194 ;
return 0 ;
}
static int F_90 ( struct V_221 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_242 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_220 )
return - V_194 ;
return 0 ;
}
static int F_91 ( struct V_199 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_243 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_227 )
return - V_194 ;
return 0 ;
}
static int F_92 ( struct V_228 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_244 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_229 )
return - V_194 ;
return 0 ;
}
static int F_93 ( struct V_230 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_245 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_231 )
return - V_194 ;
return 0 ;
}
static int F_94 ( struct V_223 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_246 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_224 )
return - V_194 ;
return 0 ;
}
static int F_95 ( struct V_225 * V_11 )
{
if ( V_11 -> V_202 . V_2 == V_247 )
return - V_192 ;
else if ( V_11 -> V_202 . V_2 != V_226 )
return - V_194 ;
return 0 ;
}
static int F_96 ( struct V_10 * V_11 , enum V_18 type , int V_232 )
{
switch ( type ) {
case V_20 :
return F_84 ( (struct V_210 * ) V_11 ) ;
case V_21 :
return F_94 ( (struct V_223 * ) V_11 ) ;
case V_22 :
return F_95 ( (struct V_225 * ) V_11 ) ;
case V_23 :
return F_89 ( (struct V_219 * ) V_11 ) ;
case V_24 :
return F_87 ( (struct V_217 * ) V_11 , V_232 ) ;
case V_25 :
return - V_248 ;
case V_27 :
return F_90 ( (struct V_221 * ) V_11 ) ;
case V_28 :
return F_91 ( (struct V_199 * ) V_11 ) ;
case V_30 :
return F_92 ( (struct V_228 * ) V_11 ) ;
case V_29 :
return F_93 ( (struct V_230 * ) V_11 ) ;
default:
return - V_45 ;
}
}
static int F_97 ( struct V_31 * V_32 , int V_33 , T_1 V_237 , int V_35 ,
enum V_18 type , int V_232 )
{
T_1 V_83 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_189 ;
F_53 ( F_54 ( V_32 ) ) ;
for ( V_83 = V_237 ; V_83 < V_237 + V_35 ; ++ V_83 ) {
V_189 = F_2 ( & V_204 -> V_94 [ type ] , V_83 ) ;
if ( ! V_189 ) {
V_44 = - V_196 ;
goto V_59;
}
if ( V_189 -> V_193 != V_33 ) {
V_44 = - V_194 ;
goto V_59;
}
V_44 = F_96 ( V_189 , type , V_232 ) ;
if ( V_44 )
goto V_59;
}
for ( V_83 = V_237 ; V_83 < V_237 + V_35 ; ++ V_83 ) {
V_189 = F_2 ( & V_204 -> V_94 [ type ] , V_83 ) ;
F_82 ( & V_189 -> V_9 , & V_204 -> V_94 [ type ] ) ;
F_98 ( & V_189 -> V_240 ) ;
F_31 ( V_189 ) ;
}
V_44 = 0 ;
V_59:
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_99 ( struct V_31 * V_32 , int V_33 , int V_139 ,
enum V_249 V_2 , struct V_210 * * V_66 ,
int V_250 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_210 * V_189 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ V_20 ] , V_139 ) ;
if ( ! V_189 )
V_44 = - V_196 ;
else if ( V_189 -> V_202 . V_193 != V_33 )
V_44 = - V_194 ;
else {
switch ( V_2 ) {
case V_241 :
F_24 ( V_32 , L_38 ,
V_209 , V_189 -> V_202 . V_7 ) ;
V_44 = - V_192 ;
break;
case V_211 :
if ( V_189 -> V_202 . V_2 == V_251 && ! V_250 )
break;
F_24 ( V_32 , L_39 , V_189 -> V_202 . V_7 ) ;
V_44 = - V_45 ;
break;
case V_251 :
if ( ( V_189 -> V_202 . V_2 == V_211 && V_250 ) ||
V_189 -> V_202 . V_2 == V_252 )
break;
else {
F_24 ( V_32 , L_39 ,
V_189 -> V_202 . V_7 ) ;
V_44 = - V_45 ;
}
break;
case V_252 :
if ( V_189 -> V_202 . V_2 != V_251 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_189 -> V_202 . V_195 = V_189 -> V_202 . V_2 ;
V_189 -> V_202 . V_253 = V_2 ;
V_189 -> V_202 . V_2 = V_241 ;
if ( V_66 )
* V_66 = V_189 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_100 ( struct V_31 * V_32 , int V_33 , int V_254 ,
enum V_255 V_2 , struct V_219 * * V_77 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_219 * V_189 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ V_23 ] , V_254 ) ;
if ( ! V_189 )
V_44 = - V_196 ;
else if ( V_189 -> V_202 . V_193 != V_33 )
V_44 = - V_194 ;
else {
switch ( V_2 ) {
case V_242 :
V_44 = - V_45 ;
break;
case V_220 :
if ( V_189 -> V_202 . V_2 != V_256 )
V_44 = - V_45 ;
break;
case V_256 :
if ( V_189 -> V_202 . V_2 != V_220 &&
V_189 -> V_202 . V_2 != V_257 )
V_44 = - V_45 ;
break;
case V_257 :
if ( V_189 -> V_202 . V_2 != V_256 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_189 -> V_202 . V_195 = V_189 -> V_202 . V_2 ;
V_189 -> V_202 . V_253 = V_2 ;
V_189 -> V_202 . V_2 = V_242 ;
if ( V_77 )
* V_77 = V_189 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_101 ( struct V_31 * V_32 , int V_33 , int V_254 ,
enum V_258 V_2 , struct V_221 * * V_259 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_221 * V_189 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ V_27 ] , V_254 ) ;
if ( ! V_189 )
V_44 = - V_196 ;
else if ( V_189 -> V_202 . V_193 != V_33 )
V_44 = - V_194 ;
else {
switch ( V_2 ) {
case V_260 :
V_44 = - V_45 ;
break;
case V_222 :
if ( V_189 -> V_202 . V_2 != V_261 )
V_44 = - V_45 ;
break;
case V_261 :
if ( V_189 -> V_202 . V_2 != V_222 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_189 -> V_202 . V_195 = V_189 -> V_202 . V_2 ;
V_189 -> V_202 . V_253 = V_2 ;
V_189 -> V_202 . V_2 = V_260 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
if ( ! V_44 && V_259 )
* V_259 = V_189 ;
return V_44 ;
}
static int F_102 ( struct V_31 * V_32 , int V_33 , int V_262 ,
enum V_263 V_2 , struct V_223 * * V_69 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_223 * V_189 ;
int V_44 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ V_21 ] , V_262 ) ;
if ( ! V_189 ) {
V_44 = - V_196 ;
} else if ( V_189 -> V_202 . V_193 != V_33 ) {
V_44 = - V_194 ;
} else if ( V_2 == V_224 ) {
if ( V_189 -> V_202 . V_2 != V_264 )
V_44 = - V_45 ;
else if ( F_85 ( & V_189 -> V_215 ) )
V_44 = - V_192 ;
else
V_44 = 0 ;
} else if ( V_2 != V_264 || V_189 -> V_202 . V_2 != V_224 ) {
V_44 = - V_45 ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
V_189 -> V_202 . V_195 = V_189 -> V_202 . V_2 ;
V_189 -> V_202 . V_253 = V_2 ;
V_189 -> V_202 . V_2 = V_246 ;
if ( V_69 )
* V_69 = V_189 ;
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_103 ( struct V_31 * V_32 , int V_33 , int V_254 ,
enum V_265 V_2 , struct V_225 * * V_72 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_225 * V_189 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ V_22 ] , V_254 ) ;
if ( ! V_189 ) {
V_44 = - V_196 ;
} else if ( V_189 -> V_202 . V_193 != V_33 ) {
V_44 = - V_194 ;
} else if ( V_2 == V_226 ) {
if ( V_189 -> V_202 . V_2 != V_266 )
V_44 = - V_45 ;
else if ( F_85 ( & V_189 -> V_215 ) )
V_44 = - V_192 ;
} else if ( V_2 != V_266 || V_189 -> V_202 . V_2 != V_226 ) {
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_189 -> V_202 . V_195 = V_189 -> V_202 . V_2 ;
V_189 -> V_202 . V_253 = V_2 ;
V_189 -> V_202 . V_2 = V_247 ;
if ( V_72 )
* V_72 = V_189 ;
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static void F_104 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_197 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_189 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ type ] , V_197 ) ;
if ( V_189 && ( V_189 -> V_193 == V_33 ) )
V_189 -> V_2 = V_189 -> V_195 ;
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_105 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_197 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_189 ;
F_53 ( F_54 ( V_32 ) ) ;
V_189 = F_2 ( & V_204 -> V_94 [ type ] , V_197 ) ;
if ( V_189 && ( V_189 -> V_193 == V_33 ) )
V_189 -> V_2 = V_189 -> V_253 ;
F_55 ( F_54 ( V_32 ) ) ;
}
static int F_106 ( struct V_31 * V_32 , int V_33 , int V_139 )
{
return F_45 ( V_32 , V_139 ) &&
( F_107 ( V_32 ) || F_108 ( V_32 , V_33 , V_139 ) ) ;
}
static int F_109 ( struct V_31 * V_32 , int V_139 )
{
return V_139 < V_32 -> V_62 . V_267 [ V_268 ] ;
}
static int F_110 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_44 ;
int V_35 ;
int V_273 ;
int V_237 ;
int V_139 ;
T_2 V_128 ;
switch ( V_269 ) {
case V_207 :
V_35 = F_111 ( & V_271 ) & 0xffffff ;
V_128 = ( F_111 ( & V_271 ) >> 24 ) & V_32 -> V_62 . V_274 ;
V_273 = F_112 ( & V_271 ) ;
V_44 = F_8 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_113 ( V_32 , V_35 , V_273 , & V_237 , V_128 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
return V_44 ;
}
V_44 = F_80 ( V_32 , V_33 , V_237 , V_35 , V_20 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_114 ( V_32 , V_237 , V_35 ) ;
return V_44 ;
}
F_115 ( V_272 , V_237 ) ;
break;
case V_275 :
V_139 = F_111 ( & V_271 ) & 0x7fffff ;
if ( F_106 ( V_32 , V_33 , V_139 ) ) {
V_44 = F_80 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_99 ( V_32 , V_33 , V_139 , V_251 ,
NULL , 1 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_109 ( V_32 , V_139 ) ) {
V_44 = F_116 ( V_32 , V_139 , V_89 ) ;
if ( V_44 ) {
F_104 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
}
F_105 ( V_32 , V_33 , V_20 , V_139 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_117 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_44 = - V_45 ;
int V_237 ;
int V_216 ;
if ( V_269 != V_276 )
return V_44 ;
V_216 = F_111 ( & V_271 ) ;
V_44 = F_8 ( V_32 , V_33 , V_24 , 1 << V_216 , 0 ) ;
if ( V_44 )
return V_44 ;
V_237 = F_118 ( V_32 , V_216 ) ;
if ( V_237 == - 1 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_216 , 0 ) ;
return - V_90 ;
}
V_44 = F_80 ( V_32 , V_33 , V_237 , 1 , V_24 , V_216 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_216 , 0 ) ;
F_119 ( V_32 , V_237 , V_216 ) ;
} else {
F_115 ( V_272 , V_237 ) ;
}
return V_44 ;
}
static int F_120 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_44 = - V_45 ;
int V_254 ;
int V_197 ;
struct V_219 * V_77 ;
switch ( V_269 ) {
case V_207 :
V_44 = F_8 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
if ( V_44 )
break;
V_254 = F_121 ( V_32 ) ;
if ( V_254 == - 1 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
break;
}
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_80 ( V_32 , V_33 , V_197 , 1 , V_23 , V_254 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_122 ( V_32 , V_254 ) ;
break;
}
F_115 ( V_272 , V_254 ) ;
break;
case V_275 :
V_254 = F_111 ( & V_271 ) ;
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_197 ,
V_256 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_123 ( V_32 , V_77 -> V_218 , V_89 ) ;
if ( V_44 ) {
F_104 ( V_32 , V_33 , V_23 , V_197 ) ;
return V_44 ;
}
F_105 ( V_32 , V_33 , V_23 , V_197 ) ;
break;
}
return V_44 ;
}
static int F_124 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_262 ;
int V_44 ;
switch ( V_269 ) {
case V_276 :
V_44 = F_8 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_125 ( V_32 , & V_262 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
break;
}
V_44 = F_80 ( V_32 , V_33 , V_262 , 1 , V_21 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_126 ( V_32 , V_262 ) ;
break;
}
F_115 ( V_272 , V_262 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_127 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_277 ;
int V_44 ;
switch ( V_269 ) {
case V_276 :
V_44 = F_8 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_128 ( V_32 , & V_277 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
break;
}
V_44 = F_80 ( V_32 , V_33 , V_277 , 1 , V_22 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_129 ( V_32 , V_277 ) ;
break;
}
F_115 ( V_272 , V_277 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_130 ( struct V_31 * V_32 , int V_33 , int V_36 ,
T_2 V_278 , T_1 * V_279 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_281 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_282 * V_11 , * V_205 ;
F_131 (res, tmp, mac_list, list) {
if ( V_11 -> V_278 == V_278 && V_11 -> V_36 == ( T_2 ) V_36 ) {
* V_279 = V_11 -> V_279 ;
return 0 ;
}
}
return - V_196 ;
}
static int F_132 ( struct V_31 * V_32 , int V_33 , T_1 V_279 , int V_36 , T_2 V_278 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_281 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_282 * V_11 , * V_205 ;
F_131 (res, tmp, mac_list, list) {
if ( V_11 -> V_279 == V_279 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_215 ;
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
V_11 -> V_279 = V_279 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_278 = V_278 ;
V_11 -> V_215 = 1 ;
F_81 ( & V_11 -> V_240 ,
& V_204 -> V_87 [ V_33 ] . V_92 [ V_25 ] ) ;
return 0 ;
}
static void F_133 ( struct V_31 * V_32 , int V_33 , T_1 V_279 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_281 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_282 * V_11 , * V_205 ;
F_131 (res, tmp, mac_list, list) {
if ( V_11 -> V_279 == V_279 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_215 ) {
F_98 ( & V_11 -> V_240 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
F_31 ( V_11 ) ;
}
break;
}
}
}
static void F_134 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_281 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
struct V_282 * V_11 , * V_205 ;
int V_83 ;
F_131 (res, tmp, mac_list, list) {
F_98 ( & V_11 -> V_240 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_215 ; V_83 ++ )
F_135 ( V_32 , V_11 -> V_36 , V_11 -> V_279 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_136 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 , int V_283 )
{
int V_44 = - V_45 ;
int V_36 ;
T_1 V_279 ;
T_2 V_278 ;
if ( V_269 != V_276 )
return V_44 ;
V_36 = ! V_283 ? F_111 ( V_272 ) : V_283 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
V_279 = V_271 ;
V_44 = F_138 ( V_32 , V_36 , V_279 ) ;
if ( V_44 >= 0 ) {
V_278 = V_44 ;
F_115 ( V_272 , V_44 ) ;
V_44 = 0 ;
}
if ( ! V_44 ) {
V_44 = F_132 ( V_32 , V_33 , V_279 , V_36 , V_278 ) ;
if ( V_44 )
F_135 ( V_32 , V_36 , V_279 ) ;
}
return V_44 ;
}
static int F_139 ( struct V_31 * V_32 , int V_33 , T_4 V_284 ,
int V_36 , int V_173 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_285 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_286 * V_11 , * V_205 ;
F_131 (res, tmp, vlan_list, list) {
if ( V_11 -> V_284 == V_284 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_215 ;
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
V_11 -> V_284 = V_284 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_173 = V_173 ;
V_11 -> V_215 = 1 ;
F_81 ( & V_11 -> V_240 ,
& V_204 -> V_87 [ V_33 ] . V_92 [ V_26 ] ) ;
return 0 ;
}
static void F_140 ( struct V_31 * V_32 , int V_33 , T_4 V_284 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_285 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_286 * V_11 , * V_205 ;
F_131 (res, tmp, vlan_list, list) {
if ( V_11 -> V_284 == V_284 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_215 ) {
F_98 ( & V_11 -> V_240 ) ;
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
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_285 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_26 ] ;
struct V_286 * V_11 , * V_205 ;
int V_83 ;
F_131 (res, tmp, vlan_list, list) {
F_98 ( & V_11 -> V_240 ) ;
for ( V_83 = 0 ; V_83 < V_11 -> V_215 ; V_83 ++ )
F_141 ( V_32 , V_11 -> V_36 , V_11 -> V_284 ) ;
F_12 ( V_32 , V_33 , V_26 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_142 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 , int V_283 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_287 * V_288 = V_38 -> V_41 . V_42 . V_288 ;
int V_44 ;
T_4 V_284 ;
int V_173 ;
int V_36 ;
V_36 = ! V_283 ? F_111 ( V_272 ) : V_283 ;
if ( ! V_36 || V_269 != V_276 )
return - V_45 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
if ( ! V_283 && V_36 > 0 && V_36 <= V_32 -> V_62 . V_100 ) {
V_288 [ V_33 ] . V_289 = true ;
return 0 ;
}
V_284 = ( T_4 ) V_271 ;
V_44 = F_143 ( V_32 , V_36 , V_284 , & V_173 ) ;
if ( ! V_44 ) {
F_115 ( V_272 , ( T_3 ) V_173 ) ;
V_44 = F_139 ( V_32 , V_33 , V_284 , V_36 , V_173 ) ;
if ( V_44 )
F_141 ( V_32 , V_36 , V_284 ) ;
}
return V_44 ;
}
static int F_63 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 , int V_36 )
{
T_3 V_254 ;
int V_44 ;
if ( V_269 != V_207 )
return - V_45 ;
V_44 = F_8 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_144 ( V_32 , & V_254 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
V_44 = F_80 ( V_32 , V_33 , V_254 , 1 , V_28 , V_36 ) ;
if ( V_44 ) {
F_145 ( V_32 , V_254 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
} else {
F_115 ( V_272 , V_254 ) ;
}
return V_44 ;
}
static int F_146 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
T_3 V_290 ;
int V_44 ;
if ( V_269 != V_207 )
return - V_45 ;
V_44 = F_147 ( V_32 , & V_290 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_80 ( V_32 , V_33 , V_290 , 1 , V_30 , 0 ) ;
if ( V_44 )
F_148 ( V_32 , V_290 ) ;
else
F_115 ( V_272 , V_290 ) ;
return V_44 ;
}
int F_149 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_295 = V_292 -> V_296 ;
switch ( V_292 -> V_297 & 0xFF ) {
case V_20 :
V_44 = F_110 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_24 :
V_44 = F_117 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_23 :
V_44 = F_120 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_21 :
V_44 = F_124 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_22 :
V_44 = F_127 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_25 :
V_44 = F_136 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ,
( V_292 -> V_297 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_142 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ,
( V_292 -> V_297 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_63 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 , 0 ) ;
break;
case V_30 :
V_44 = F_146 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_150 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 )
{
int V_44 ;
int V_35 ;
int V_237 ;
int V_139 ;
switch ( V_269 ) {
case V_207 :
V_237 = F_111 ( & V_271 ) & 0x7fffff ;
V_35 = F_112 ( & V_271 ) ;
V_44 = F_97 ( V_32 , V_33 , V_237 , V_35 , V_20 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_114 ( V_32 , V_237 , V_35 ) ;
break;
case V_275 :
V_139 = F_111 ( & V_271 ) & 0x7fffff ;
V_44 = F_99 ( V_32 , V_33 , V_139 , V_211 ,
NULL , 0 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_109 ( V_32 , V_139 ) )
F_151 ( V_32 , V_139 ) ;
F_105 ( V_32 , V_33 , V_20 , V_139 ) ;
if ( F_106 ( V_32 , V_33 , V_139 ) )
V_44 = F_97 ( V_32 , V_33 , V_139 , 1 , V_20 , 0 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_152 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_44 = - V_45 ;
int V_237 ;
int V_216 ;
if ( V_269 != V_276 )
return V_44 ;
V_237 = F_111 ( & V_271 ) ;
V_216 = F_112 ( & V_271 ) ;
V_44 = F_97 ( V_32 , V_33 , V_237 , 1 , V_24 , V_216 ) ;
if ( ! V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_216 , 0 ) ;
F_119 ( V_32 , V_237 , V_216 ) ;
}
return V_44 ;
}
static int F_153 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 )
{
int V_44 = - V_45 ;
int V_254 ;
int V_197 ;
struct V_219 * V_77 ;
switch ( V_269 ) {
case V_207 :
V_254 = F_111 ( & V_271 ) ;
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_154 ( V_32 , V_33 , V_197 , V_23 , & V_77 ) ;
if ( V_44 )
break;
V_254 = V_77 -> V_218 ;
F_57 ( V_32 , V_33 , V_197 , V_23 ) ;
V_44 = F_97 ( V_32 , V_33 , V_197 , 1 , V_23 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_122 ( V_32 , V_254 ) ;
break;
case V_275 :
V_254 = F_111 ( & V_271 ) ;
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_197 ,
V_220 , & V_77 ) ;
if ( V_44 )
return V_44 ;
F_155 ( V_32 , V_77 -> V_218 ) ;
F_105 ( V_32 , V_33 , V_23 , V_197 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_156 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_262 ;
int V_44 ;
switch ( V_269 ) {
case V_276 :
V_262 = F_111 ( & V_271 ) ;
V_44 = F_97 ( V_32 , V_33 , V_262 , 1 , V_21 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_126 ( V_32 , V_262 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_157 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_277 ;
int V_44 ;
switch ( V_269 ) {
case V_276 :
V_277 = F_111 ( & V_271 ) ;
V_44 = F_97 ( V_32 , V_33 , V_277 , 1 , V_22 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_129 ( V_32 , V_277 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_158 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 , int V_283 )
{
int V_36 ;
int V_44 = 0 ;
switch ( V_269 ) {
case V_276 :
V_36 = ! V_283 ? F_111 ( V_272 ) : V_283 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
F_133 ( V_32 , V_33 , V_271 , V_36 ) ;
F_135 ( V_32 , V_36 , V_271 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_159 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 , int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_287 * V_288 = V_38 -> V_41 . V_42 . V_288 ;
int V_44 = 0 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
switch ( V_269 ) {
case V_276 :
if ( V_288 [ V_33 ] . V_289 )
return 0 ;
if ( ! V_36 )
return - V_45 ;
F_140 ( V_32 , V_33 , V_271 , V_36 ) ;
F_141 ( V_32 , V_36 , V_271 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_160 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_254 ;
int V_44 ;
if ( V_269 != V_207 )
return - V_45 ;
V_254 = F_111 ( & V_271 ) ;
if ( V_254 == F_59 ( V_32 ) )
return 0 ;
V_44 = F_97 ( V_32 , V_33 , V_254 , 1 , V_28 , 0 ) ;
if ( V_44 )
return V_44 ;
F_145 ( V_32 , V_254 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
static int F_161 ( struct V_31 * V_32 , int V_33 , int V_269 , int V_270 ,
T_1 V_271 , T_1 * V_272 )
{
int V_290 ;
int V_44 ;
if ( V_269 != V_207 )
return - V_45 ;
V_290 = F_111 ( & V_271 ) ;
V_44 = F_97 ( V_32 , V_33 , V_290 , 1 , V_30 , 0 ) ;
if ( V_44 )
return V_44 ;
F_148 ( V_32 , V_290 ) ;
return V_44 ;
}
int F_162 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 = - V_45 ;
int V_295 = V_292 -> V_296 ;
switch ( V_292 -> V_297 & 0xFF ) {
case V_20 :
V_44 = F_150 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 ) ;
break;
case V_24 :
V_44 = F_152 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_23 :
V_44 = F_153 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 ) ;
break;
case V_21 :
V_44 = F_156 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_22 :
V_44 = F_157 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_25 :
V_44 = F_158 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ,
( V_292 -> V_297 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_159 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ,
( V_292 -> V_297 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_160 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
break;
case V_30 :
V_44 = F_161 ( V_32 , V_33 , V_292 -> V_296 , V_295 ,
V_292 -> V_271 , & V_292 -> V_272 ) ;
default:
break;
}
return V_44 ;
}
static int F_163 ( struct V_298 * V_77 )
{
return ( F_40 ( V_77 -> V_128 ) >> 9 ) & 1 ;
}
static int F_164 ( struct V_298 * V_77 )
{
return ( int ) F_165 ( V_77 -> V_299 ) & 0xfffffff8 ;
}
static int F_166 ( struct V_298 * V_77 )
{
return F_40 ( V_77 -> V_300 ) ;
}
static T_3 F_167 ( struct V_298 * V_77 )
{
return F_40 ( V_77 -> V_301 ) & 0x00ffffff ;
}
static int F_168 ( struct V_298 * V_77 )
{
return F_40 ( V_77 -> V_301 ) & V_302 ;
}
static int F_169 ( struct V_298 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_303 ;
}
static int F_170 ( struct V_298 * V_77 )
{
return F_40 ( V_77 -> V_128 ) & V_304 ;
}
static int F_171 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_305 ) & 0xfffffff8 ;
}
static int F_172 ( struct V_306 * V_307 )
{
return F_40 ( V_307 -> V_305 ) & 0xfffffff8 ;
}
static int F_173 ( struct V_122 * V_140 )
{
int V_308 = ( V_140 -> V_309 & 0x3f ) + 12 ;
int V_310 = ( V_140 -> V_311 >> 3 ) & 0xf ;
int V_312 = V_140 -> V_311 & 7 ;
int V_313 = ( V_140 -> V_314 >> 3 ) & 0xf ;
int V_315 = V_140 -> V_314 & 7 ;
int V_72 = ( F_40 ( V_140 -> V_277 ) >> 24 ) & 1 ;
int V_316 = ( F_40 ( V_140 -> V_128 ) >> 13 ) & 1 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
int V_317 = ( V_127 == V_134 ) ? 1 : 0 ;
int V_318 ;
int V_319 ;
int V_320 ;
int V_321 ;
int V_322 = ( F_40 ( V_140 -> V_323 ) >> 6 ) & 0x3f ;
V_318 = 1 << ( V_310 + V_312 + 4 ) ;
V_319 = ( V_72 | V_316 | V_317 ) ? 0 : ( 1 << ( V_313 + V_315 + 4 ) ) ;
V_321 = V_318 + V_319 ;
V_320 =
F_174 ( ( V_321 + ( V_322 << 6 ) ) >>
V_308 ) ;
return V_320 ;
}
static int F_175 ( struct V_31 * V_32 , int V_33 , int V_324 ,
int V_325 , struct V_217 * V_75 )
{
int V_326 = V_75 -> V_202 . V_7 ;
int V_327 = ( 1 << V_75 -> V_216 ) ;
if ( V_324 < V_326 || V_324 + V_325 > V_326 + V_327 )
return - V_194 ;
return 0 ;
}
int F_176 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_254 = V_292 -> V_297 ;
struct V_217 * V_75 ;
struct V_219 * V_77 ;
int V_328 = F_164 ( V_116 -> V_118 ) / V_32 -> V_62 . V_329 ;
int V_330 ;
int V_197 ;
T_3 V_331 ;
int V_332 ;
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_197 , V_257 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_170 ( V_116 -> V_118 ) ) {
V_44 = - V_194 ;
goto V_333;
}
V_331 = F_167 ( V_116 -> V_118 ) ;
V_332 = ( V_331 >> 17 ) & 0x7f ;
if ( V_332 != 0 && -- V_332 != V_33 ) {
V_44 = - V_194 ;
goto V_333;
}
if ( F_168 ( V_116 -> V_118 ) ) {
if ( F_169 ( V_116 -> V_118 ) ) {
V_44 = - V_194 ;
goto V_333;
}
if ( ! F_170 ( V_116 -> V_118 ) ) {
V_44 = - V_194 ;
goto V_333;
}
}
V_330 = F_163 ( V_116 -> V_118 ) ;
if ( ! V_330 ) {
V_44 = F_154 ( V_32 , V_33 , V_328 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_333;
V_44 = F_175 ( V_32 , V_33 , V_328 ,
F_166 ( V_116 -> V_118 ) , V_75 ) ;
if ( V_44 )
goto V_334;
V_77 -> V_75 = V_75 ;
}
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_334;
if ( ! V_330 ) {
F_178 ( & V_75 -> V_215 ) ;
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
}
F_105 ( V_32 , V_33 , V_23 , V_197 ) ;
return 0 ;
V_334:
if ( ! V_330 )
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
V_333:
F_104 ( V_32 , V_33 , V_23 , V_197 ) ;
return V_44 ;
}
int F_179 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_254 = V_292 -> V_297 ;
struct V_219 * V_77 ;
int V_197 ;
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_197 , V_256 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_333;
if ( V_77 -> V_75 )
F_180 ( & V_77 -> V_75 -> V_215 ) ;
F_105 ( V_32 , V_33 , V_23 , V_197 ) ;
return 0 ;
V_333:
F_104 ( V_32 , V_33 , V_23 , V_197 ) ;
return V_44 ;
}
int F_181 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_254 = V_292 -> V_297 ;
struct V_219 * V_77 ;
int V_197 ;
V_197 = V_254 & F_49 ( V_32 ) ;
V_44 = F_154 ( V_32 , V_33 , V_197 , V_23 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( V_77 -> V_202 . V_195 == V_256 ) {
struct V_298 * V_335 = F_182 (
& V_37 ( V_32 ) -> V_336 . V_337 ,
V_77 -> V_218 , NULL ) ;
if ( NULL == V_335 || NULL == V_293 -> V_118 ) {
V_44 = - V_45 ;
goto V_59;
}
memcpy ( V_293 -> V_118 , V_335 , sizeof( * V_335 ) ) ;
V_44 = 0 ;
} else if ( V_77 -> V_202 . V_195 == V_257 ) {
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
} else {
V_44 = - V_192 ;
goto V_59;
}
V_59:
F_57 ( V_32 , V_33 , V_197 , V_23 ) ;
return V_44 ;
}
static int F_183 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_338 ) & 0xffffff ;
}
static int F_184 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_339 ) & 0xffffff ;
}
static T_3 F_185 ( struct V_122 * V_140 )
{
return F_40 ( V_140 -> V_277 ) & 0x1ffffff ;
}
static void F_186 ( struct V_31 * V_32 , struct V_291 * V_292 ,
struct V_122 * V_340 )
{
T_3 V_139 = V_292 -> V_297 & 0xffffff ;
T_3 V_341 = 0 ;
if ( F_187 ( V_32 , V_139 , & V_341 ) )
return;
V_340 -> V_341 = F_46 ( V_341 ) ;
}
int F_188 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_139 = V_292 -> V_297 & 0x7fffff ;
struct V_217 * V_75 ;
struct V_210 * V_66 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_328 = F_171 ( V_140 ) / V_32 -> V_62 . V_329 ;
int V_342 = F_173 ( V_140 ) ;
struct V_223 * V_343 ;
struct V_223 * V_344 ;
int V_345 = F_183 ( V_140 ) ;
int V_346 = F_184 ( V_140 ) ;
T_3 V_277 = F_185 ( V_140 ) & 0xffffff ;
int V_347 = ( F_185 ( V_140 ) >> 24 ) & 1 ;
struct V_225 * V_72 ;
int V_212 = F_40 ( V_140 -> V_212 ) & 0xffffff ;
V_44 = F_189 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_99 ( V_32 , V_33 , V_139 , V_252 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_66 -> V_212 = V_212 ;
V_66 -> V_131 = 0 ;
V_66 -> V_152 = 0 ;
V_66 -> V_157 = 0 ;
V_66 -> V_171 = 0 ;
V_66 -> V_348 = 0 ;
V_66 -> V_173 = 0 ;
V_66 -> V_179 = 0 ;
V_66 -> V_349 = F_40 ( V_140 -> V_128 ) ;
V_44 = F_154 ( V_32 , V_33 , V_328 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_333;
V_44 = F_175 ( V_32 , V_33 , V_328 , V_342 , V_75 ) ;
if ( V_44 )
goto V_350;
V_44 = F_154 ( V_32 , V_33 , V_345 , V_21 , & V_343 ) ;
if ( V_44 )
goto V_350;
if ( V_346 != V_345 ) {
V_44 = F_154 ( V_32 , V_33 , V_346 , V_21 , & V_344 ) ;
if ( V_44 )
goto V_351;
} else
V_344 = V_343 ;
if ( V_347 ) {
V_44 = F_154 ( V_32 , V_33 , V_277 , V_22 , & V_72 ) ;
if ( V_44 )
goto V_352;
}
F_186 ( V_32 , V_292 , V_140 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_353;
F_178 ( & V_75 -> V_215 ) ;
V_66 -> V_75 = V_75 ;
F_178 ( & V_343 -> V_215 ) ;
V_66 -> V_343 = V_343 ;
F_178 ( & V_344 -> V_215 ) ;
V_66 -> V_344 = V_344 ;
if ( V_346 != V_345 )
F_57 ( V_32 , V_33 , V_346 , V_21 ) ;
if ( V_347 ) {
F_178 ( & V_72 -> V_215 ) ;
F_57 ( V_32 , V_33 , V_277 , V_22 ) ;
V_66 -> V_72 = V_72 ;
}
V_66 -> V_152 = V_140 -> V_152 ;
F_57 ( V_32 , V_33 , V_345 , V_21 ) ;
F_57 ( V_32 , V_33 , V_328 , V_24 ) ;
F_105 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_353:
if ( V_347 )
F_57 ( V_32 , V_33 , V_277 , V_22 ) ;
V_352:
if ( V_346 != V_345 )
F_57 ( V_32 , V_33 , V_346 , V_21 ) ;
V_351:
F_57 ( V_32 , V_33 , V_345 , V_21 ) ;
V_350:
F_57 ( V_32 , V_33 , V_328 , V_24 ) ;
V_333:
F_104 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static int F_190 ( struct V_354 * V_355 )
{
return F_40 ( V_355 -> V_305 ) & 0xfffffff8 ;
}
static int F_191 ( struct V_354 * V_355 )
{
int V_356 = V_355 -> V_356 & 0x1f ;
int V_308 = ( V_355 -> V_309 & 0x3f ) + 12 ;
if ( V_356 + 5 < V_308 )
return 1 ;
return 1 << ( V_356 + 5 - V_308 ) ;
}
static int F_192 ( struct V_357 * V_358 )
{
return F_40 ( V_358 -> V_305 ) & 0xfffffff8 ;
}
static int F_193 ( struct V_357 * V_358 )
{
int V_359 = ( F_40 ( V_358 -> V_360 ) >> 24 ) & 0x1f ;
int V_308 = ( V_358 -> V_309 & 0x3f ) + 12 ;
if ( V_359 + 5 < V_308 )
return 1 ;
return 1 << ( V_359 + 5 - V_308 ) ;
}
int F_194 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_361 = V_292 -> V_297 ;
int V_7 = ( V_33 << 10 ) | V_361 ;
struct V_354 * V_355 = V_116 -> V_118 ;
int V_328 = F_190 ( V_355 ) / V_32 -> V_62 . V_329 ;
int V_342 = F_191 ( V_355 ) ;
struct V_221 * V_259 ;
struct V_217 * V_75 ;
V_44 = F_80 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_101 ( V_32 , V_33 , V_7 , V_261 , & V_259 ) ;
if ( V_44 )
goto V_362;
V_44 = F_154 ( V_32 , V_33 , V_328 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_363;
V_44 = F_175 ( V_32 , V_33 , V_328 , V_342 , V_75 ) ;
if ( V_44 )
goto V_364;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_364;
F_178 ( & V_75 -> V_215 ) ;
V_259 -> V_75 = V_75 ;
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_27 , V_7 ) ;
return 0 ;
V_364:
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
V_363:
F_104 ( V_32 , V_33 , V_27 , V_7 ) ;
V_362:
F_97 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return V_44 ;
}
int F_195 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
T_2 V_365 = V_292 -> V_296 ;
if ( V_365 != 1 )
return - V_194 ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
return V_44 ;
}
static int F_196 ( struct V_31 * V_32 , int V_33 , int V_324 ,
int V_366 , struct V_217 * * V_11 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_217 * V_75 ;
int V_44 = - V_45 ;
F_53 ( F_54 ( V_32 ) ) ;
F_62 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_175 ( V_32 , V_33 , V_324 , V_366 , V_75 ) ) {
* V_11 = V_75 ;
V_75 -> V_202 . V_195 = V_75 -> V_202 . V_2 ;
V_75 -> V_202 . V_2 = V_3 ;
V_44 = 0 ;
break;
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_197 ( struct V_31 * V_32 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
enum V_367 V_368 , T_2 V_33 )
{
T_3 V_143 ;
T_3 V_139 ;
struct V_122 * V_123 ;
enum V_124 V_125 ;
int V_36 ;
int V_369 ;
V_123 = V_116 -> V_118 + 8 ;
V_143 = ( F_40 ( V_123 -> V_128 ) >> 16 ) & 0xff ;
V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
if ( V_33 != F_14 ( V_32 ) ) {
V_123 -> V_323 &= ~ V_370 ;
if ( V_123 -> V_371 )
return - V_194 ;
}
switch ( V_143 ) {
case V_133 :
case V_134 :
case V_135 :
switch ( V_368 ) {
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
if ( V_33 != F_14 ( V_32 ) ) {
if ( V_125 & V_136 ) {
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_377 [ V_36 ] != V_378 )
V_369 = F_198 ( V_32 , V_33 , V_36 ) ;
else
V_369 = 1 ;
if ( V_123 -> V_130 . V_132 >= V_369 )
return - V_45 ;
}
if ( V_125 & V_137 ) {
V_36 = ( V_123 -> V_138 . V_131 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_377 [ V_36 ] != V_378 )
V_369 = F_198 ( V_32 , V_33 , V_36 ) ;
else
V_369 = 1 ;
if ( V_123 -> V_138 . V_132 >= V_369 )
return - V_45 ;
}
}
break;
default:
break;
}
break;
case V_148 :
V_139 = V_292 -> V_297 & 0x7fffff ;
V_36 = ( V_123 -> V_130 . V_131 >> 6 & 1 ) + 1 ;
if ( V_368 == V_372 &&
V_33 != F_14 ( V_32 ) &&
F_45 ( V_32 , V_139 ) &&
! F_199 ( V_32 , V_33 , V_36 ) ) {
F_64 ( V_32 , L_40 ,
V_209 , V_33 , V_36 ) ;
return - V_194 ;
}
break;
default:
break;
}
return 0 ;
}
int F_200 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
struct V_379 V_75 ;
T_5 * V_380 = V_116 -> V_118 ;
T_1 * V_381 = ( T_1 * ) V_380 ;
int V_83 ;
struct V_217 * V_382 = NULL ;
int V_324 = F_165 ( V_380 [ 0 ] ) ;
int V_383 = V_292 -> V_297 ;
int V_44 ;
V_44 = F_196 ( V_32 , V_33 , V_324 , V_383 , & V_382 ) ;
if ( V_44 )
return V_44 ;
V_75 . V_384 = 0 ;
V_75 . V_216 = 0 ;
V_75 . V_308 = 0 ;
for ( V_83 = 0 ; V_83 < V_383 ; ++ V_83 )
V_381 [ V_83 + 2 ] = ( F_165 ( V_380 [ V_83 + 2 ] ) & ~ 1ULL ) ;
V_44 = F_201 ( V_32 , & V_75 , F_165 ( V_380 [ 0 ] ) , V_383 ,
( ( T_1 * ) V_380 + 2 ) ) ;
if ( V_382 )
F_57 ( V_32 , V_33 , V_382 -> V_202 . V_7 , V_24 ) ;
return V_44 ;
}
int F_202 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_361 = V_292 -> V_297 ;
int V_7 = V_361 | ( V_33 << 10 ) ;
struct V_221 * V_259 ;
int V_44 ;
V_44 = F_101 ( V_32 , V_33 , V_7 , V_222 , & V_259 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_259 -> V_75 -> V_202 . V_7 , V_24 , NULL ) ;
if ( V_44 )
goto V_333;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_334;
F_180 ( & V_259 -> V_75 -> V_215 ) ;
F_57 ( V_32 , V_33 , V_259 -> V_75 -> V_202 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_27 , V_7 ) ;
F_97 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return 0 ;
V_334:
F_57 ( V_32 , V_33 , V_259 -> V_75 -> V_202 . V_7 , V_24 ) ;
V_333:
F_104 ( V_32 , V_33 , V_27 , V_7 ) ;
return V_44 ;
}
int F_203 ( struct V_31 * V_32 , int V_33 , struct V_385 * V_386 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_387 * V_388 ;
struct V_115 * V_389 ;
T_3 V_297 = 0 ;
int V_44 ;
int V_7 ;
struct V_221 * V_390 ;
if ( ! V_38 -> V_41 . V_42 . V_288 )
return - V_45 ;
if ( V_33 < 0 || V_33 > V_32 -> V_51 -> V_52 ||
V_33 == V_32 -> V_62 . V_113 ||
! V_38 -> V_41 . V_42 . V_288 [ V_33 ] . V_391 )
return 0 ;
V_388 = & V_38 -> V_41 . V_42 . V_288 [ V_33 ] . V_388 [ V_386 -> type ] ;
if ( V_388 -> V_361 < 0 )
return 0 ;
F_35 ( & V_38 -> V_41 . V_42 . V_392 [ V_33 ] ) ;
V_7 = ( V_33 << 10 ) | V_388 -> V_361 ;
V_44 = F_154 ( V_32 , V_33 , V_7 , V_27 , & V_390 ) ;
if ( V_44 )
goto V_393;
if ( V_390 -> V_202 . V_195 != V_261 ) {
V_44 = - V_45 ;
goto V_394;
}
V_389 = F_204 ( V_32 ) ;
if ( F_205 ( V_389 ) ) {
V_44 = F_206 ( V_389 ) ;
goto V_394;
}
if ( V_386 -> type == V_395 ) {
++ V_388 -> V_396 ;
V_386 -> V_397 . V_270 . V_396 = F_207 ( V_388 -> V_396 ) ;
}
memcpy ( V_389 -> V_118 , ( T_2 * ) V_386 , 28 ) ;
V_297 = ( V_33 & 0xff ) | ( ( V_388 -> V_361 & 0x3ff ) << 16 ) ;
V_44 = F_208 ( V_32 , V_389 -> V_398 , V_297 , 0 ,
V_399 , V_400 ,
V_401 ) ;
F_57 ( V_32 , V_33 , V_7 , V_27 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_392 [ V_33 ] ) ;
F_209 ( V_32 , V_389 ) ;
return V_44 ;
V_394:
F_57 ( V_32 , V_33 , V_7 , V_27 ) ;
V_393:
F_37 ( & V_38 -> V_41 . V_42 . V_392 [ V_33 ] ) ;
return V_44 ;
}
int F_210 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_361 = V_292 -> V_297 ;
int V_7 = V_361 | ( V_33 << 10 ) ;
struct V_221 * V_259 ;
int V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_7 , V_27 , & V_259 ) ;
if ( V_44 )
return V_44 ;
if ( V_259 -> V_202 . V_195 != V_261 ) {
V_44 = - V_45 ;
goto V_334;
}
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_334:
F_57 ( V_32 , V_33 , V_7 , V_27 ) ;
return V_44 ;
}
int F_211 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_262 = V_292 -> V_297 ;
struct V_357 * V_358 = V_116 -> V_118 ;
int V_328 = F_192 ( V_358 ) / V_32 -> V_62 . V_329 ;
struct V_223 * V_69 = NULL ;
struct V_217 * V_75 ;
V_44 = F_102 ( V_32 , V_33 , V_262 , V_264 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_328 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_363;
V_44 = F_175 ( V_32 , V_33 , V_328 , F_193 ( V_358 ) , V_75 ) ;
if ( V_44 )
goto V_364;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_364;
F_178 ( & V_75 -> V_215 ) ;
V_69 -> V_75 = V_75 ;
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_21 , V_262 ) ;
return 0 ;
V_364:
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
V_363:
F_104 ( V_32 , V_33 , V_21 , V_262 ) ;
return V_44 ;
}
int F_212 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_262 = V_292 -> V_297 ;
struct V_223 * V_69 = NULL ;
V_44 = F_102 ( V_32 , V_33 , V_262 , V_224 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_363;
F_180 ( & V_69 -> V_75 -> V_215 ) ;
F_105 ( V_32 , V_33 , V_21 , V_262 ) ;
return 0 ;
V_363:
F_104 ( V_32 , V_33 , V_21 , V_262 ) ;
return V_44 ;
}
int F_213 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_262 = V_292 -> V_297 ;
struct V_223 * V_69 ;
int V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_262 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_202 . V_195 != V_264 )
goto V_334;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_334:
F_57 ( V_32 , V_33 , V_262 , V_21 ) ;
return V_44 ;
}
static int F_214 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 ,
struct V_223 * V_69 )
{
int V_44 ;
struct V_217 * V_402 ;
struct V_217 * V_75 ;
struct V_357 * V_358 = V_116 -> V_118 ;
int V_328 = F_192 ( V_358 ) / V_32 -> V_62 . V_329 ;
V_44 = F_154 ( V_32 , V_33 , V_69 -> V_75 -> V_202 . V_7 , V_24 , & V_402 ) ;
if ( V_44 )
return V_44 ;
if ( V_402 != V_69 -> V_75 ) {
V_44 = - V_45 ;
goto V_334;
}
V_44 = F_154 ( V_32 , V_33 , V_328 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_334;
V_44 = F_175 ( V_32 , V_33 , V_328 , F_193 ( V_358 ) , V_75 ) ;
if ( V_44 )
goto V_403;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_403;
F_180 ( & V_402 -> V_215 ) ;
F_57 ( V_32 , V_33 , V_402 -> V_202 . V_7 , V_24 ) ;
F_178 ( & V_75 -> V_215 ) ;
V_69 -> V_75 = V_75 ;
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
return 0 ;
V_403:
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
V_334:
F_57 ( V_32 , V_33 , V_402 -> V_202 . V_7 , V_24 ) ;
return V_44 ;
}
int F_215 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_262 = V_292 -> V_297 ;
struct V_223 * V_69 ;
int V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_262 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_202 . V_195 != V_264 )
goto V_334;
if ( V_292 -> V_296 == 0 ) {
V_44 = F_214 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 , V_69 ) ;
goto V_334;
}
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_334:
F_57 ( V_32 , V_33 , V_262 , V_21 ) ;
return V_44 ;
}
static int F_216 ( struct V_306 * V_307 )
{
int V_404 = ( F_40 ( V_307 -> V_405 ) >> 24 ) & 0xf ;
int V_315 = V_307 -> V_406 & 7 ;
int V_308 = ( V_307 -> V_309 & 0x3f ) + 12 ;
if ( V_404 + V_315 + 4 < V_308 )
return 1 ;
return 1 << ( V_404 + V_315 + 4 - V_308 ) ;
}
int F_217 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_277 = V_292 -> V_297 ;
struct V_217 * V_75 ;
struct V_225 * V_72 = NULL ;
struct V_306 * V_307 = V_116 -> V_118 ;
int V_328 = F_172 ( V_307 ) / V_32 -> V_62 . V_329 ;
if ( V_277 != ( F_40 ( V_307 -> V_405 ) & 0xffffff ) )
return - V_45 ;
V_44 = F_103 ( V_32 , V_33 , V_277 , V_266 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_328 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_333;
V_44 = F_175 ( V_32 , V_33 , V_328 , F_216 ( V_307 ) ,
V_75 ) ;
if ( V_44 )
goto V_350;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_350;
F_178 ( & V_75 -> V_215 ) ;
V_72 -> V_75 = V_75 ;
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_22 , V_277 ) ;
return 0 ;
V_350:
F_57 ( V_32 , V_33 , V_75 -> V_202 . V_7 , V_24 ) ;
V_333:
F_104 ( V_32 , V_33 , V_22 , V_277 ) ;
return V_44 ;
}
int F_218 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_277 = V_292 -> V_297 ;
struct V_225 * V_72 = NULL ;
V_44 = F_103 ( V_32 , V_33 , V_277 , V_226 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_333;
F_180 ( & V_72 -> V_75 -> V_215 ) ;
if ( V_72 -> V_69 )
F_180 ( & V_72 -> V_69 -> V_215 ) ;
F_105 ( V_32 , V_33 , V_22 , V_277 ) ;
return 0 ;
V_333:
F_104 ( V_32 , V_33 , V_22 , V_277 ) ;
return V_44 ;
}
int F_219 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_277 = V_292 -> V_297 ;
struct V_225 * V_72 ;
V_44 = F_154 ( V_32 , V_33 , V_277 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_202 . V_195 != V_266 ) {
V_44 = - V_192 ;
goto V_59;
}
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_59:
F_57 ( V_32 , V_33 , V_277 , V_22 ) ;
return V_44 ;
}
int F_220 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_277 = V_292 -> V_297 ;
struct V_225 * V_72 ;
V_44 = F_154 ( V_32 , V_33 , V_277 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_202 . V_195 != V_266 ) {
V_44 = - V_192 ;
goto V_59;
}
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_59:
F_57 ( V_32 , V_33 , V_277 , V_22 ) ;
return V_44 ;
}
int F_221 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_139 = V_292 -> V_297 & 0x7fffff ;
struct V_210 * V_66 ;
V_44 = F_154 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_202 . V_195 != V_252 ) {
V_44 = - V_192 ;
goto V_59;
}
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_59:
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_222 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
struct V_122 * V_340 = V_116 -> V_118 + 8 ;
F_186 ( V_32 , V_292 , V_340 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_221 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
}
static int F_189 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
enum V_124 V_125 = F_40 ( * ( V_126 * ) V_116 -> V_118 ) ;
T_2 V_407 ;
int V_36 = F_137 (
V_32 , V_33 , ( V_140 -> V_130 . V_131 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_407 = ( V_140 -> V_130 . V_131 & ~ ( 1 << 6 ) ) |
( ( V_36 & 1 ) << 6 ) ;
if ( V_125 & ( V_136 | V_408 ) ||
V_140 -> V_130 . V_131 || F_41 ( V_32 , V_36 + 1 ) ) {
V_140 -> V_130 . V_131 = V_407 ;
}
if ( V_125 & V_137 ) {
V_36 = F_137 (
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
static int F_223 ( struct V_31 * V_32 , int V_33 ,
struct V_122 * V_140 ,
struct V_115 * V_116 )
{
T_1 V_279 ;
int V_36 ;
T_3 V_127 = ( F_40 ( V_140 -> V_128 ) >> 16 ) & 0xff ;
T_2 V_117 = * ( T_2 * ) ( V_116 -> V_118 + 64 ) ;
T_2 V_409 ;
V_36 = ( V_117 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) && ( V_127 != V_148 ) ) {
V_409 = V_140 -> V_130 . V_186 & 0x7f ;
if ( F_130 ( V_32 , V_33 , V_36 , V_409 , & V_279 ) )
return - V_196 ;
}
return 0 ;
}
int F_224 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
struct V_122 * V_140 = V_116 -> V_118 + 8 ;
int V_139 = V_292 -> V_297 & 0x7fffff ;
struct V_210 * V_66 ;
T_2 V_410 ;
T_2 V_411 = V_140 -> V_130 . V_157 ;
T_2 V_412 = V_140 -> V_130 . V_171 ;
T_2 V_413 = V_140 -> V_130 . V_175 ;
T_2 V_414 = V_140 -> V_130 . V_173 ;
T_2 V_415 = V_140 -> V_130 . V_179 ;
V_44 = F_189 ( V_32 , V_33 , V_140 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_292 , V_116 , V_372 , V_33 ) ;
if ( V_44 )
return V_44 ;
if ( F_223 ( V_32 , V_33 , V_140 , V_116 ) )
return - V_45 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_186 ( V_32 , V_292 , V_140 ) ;
V_410 = V_140 -> V_130 . V_131 ;
V_44 = F_154 ( V_32 , V_33 , V_139 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_202 . V_195 != V_252 ) {
V_44 = - V_192 ;
goto V_59;
}
V_44 = F_43 ( V_32 , V_116 , V_33 , V_139 ) ;
if ( V_44 )
goto V_59;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
V_59:
if ( ! V_44 ) {
V_66 -> V_131 = V_410 ;
V_66 -> V_157 = V_411 ;
V_66 -> V_171 = V_412 ;
V_66 -> V_348 = V_413 ;
V_66 -> V_173 = V_414 ;
V_66 -> V_179 = V_415 ;
}
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_225 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
struct V_122 * V_340 = V_116 -> V_118 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_340 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_292 , V_116 , V_373 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_186 ( V_32 , V_292 , V_340 ) ;
return F_221 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
}
int F_226 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
struct V_122 * V_340 = V_116 -> V_118 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_340 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_292 , V_116 , V_374 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_116 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_186 ( V_32 , V_292 , V_340 ) ;
return F_221 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
}
int F_227 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
struct V_122 * V_340 = V_116 -> V_118 + 8 ;
int V_44 = F_189 ( V_32 , V_33 , V_340 , V_116 ) ;
if ( V_44 )
return V_44 ;
F_186 ( V_32 , V_292 , V_340 ) ;
return F_221 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
}
int F_228 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
struct V_122 * V_340 = V_116 -> V_118 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_340 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_292 , V_116 , V_375 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_186 ( V_32 , V_292 , V_340 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_221 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
}
int F_229 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
struct V_122 * V_340 = V_116 -> V_118 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_340 , V_116 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_292 , V_116 , V_376 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_186 ( V_32 , V_292 , V_340 ) ;
F_39 ( V_32 , V_116 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_116 ) ;
return F_221 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
}
int F_230 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_139 = V_292 -> V_297 & 0x7fffff ;
struct V_210 * V_66 ;
V_44 = F_99 ( V_32 , V_33 , V_139 , V_251 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
if ( V_44 )
goto V_333;
F_180 ( & V_66 -> V_75 -> V_215 ) ;
F_180 ( & V_66 -> V_343 -> V_215 ) ;
F_180 ( & V_66 -> V_344 -> V_215 ) ;
if ( V_66 -> V_72 )
F_180 ( & V_66 -> V_72 -> V_215 ) ;
F_105 ( V_32 , V_33 , V_20 , V_139 ) ;
return 0 ;
V_333:
F_104 ( V_32 , V_33 , V_20 , V_139 ) ;
return V_44 ;
}
static struct V_416 * F_231 ( struct V_31 * V_32 , int V_33 ,
struct V_210 * V_417 , T_2 * V_418 )
{
struct V_416 * V_11 ;
F_62 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_418 , V_418 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_232 ( struct V_31 * V_32 , int V_33 , struct V_210 * V_417 ,
T_2 * V_418 , enum V_419 V_420 ,
enum V_421 V_422 , T_1 V_423 )
{
struct V_416 * V_11 ;
int V_44 ;
V_11 = F_21 ( sizeof *V_11 , V_89 ) ;
if ( ! V_11 )
return - V_90 ;
F_53 ( & V_417 -> V_214 ) ;
if ( F_231 ( V_32 , V_33 , V_417 , V_418 ) ) {
F_31 ( V_11 ) ;
V_44 = - V_17 ;
} else {
memcpy ( V_11 -> V_418 , V_418 , 16 ) ;
V_11 -> V_420 = V_420 ;
V_11 -> V_422 = V_422 ;
V_11 -> V_423 = V_423 ;
F_81 ( & V_11 -> V_240 , & V_417 -> V_213 ) ;
V_44 = 0 ;
}
F_55 ( & V_417 -> V_214 ) ;
return V_44 ;
}
static int F_233 ( struct V_31 * V_32 , int V_33 , struct V_210 * V_417 ,
T_2 * V_418 , enum V_419 V_420 ,
enum V_421 V_422 , T_1 * V_423 )
{
struct V_416 * V_11 ;
int V_44 ;
F_53 ( & V_417 -> V_214 ) ;
V_11 = F_231 ( V_32 , V_33 , V_417 , V_418 ) ;
if ( ! V_11 || V_11 -> V_420 != V_420 || V_11 -> V_422 != V_422 )
V_44 = - V_45 ;
else {
* V_423 = V_11 -> V_423 ;
F_98 ( & V_11 -> V_240 ) ;
F_31 ( V_11 ) ;
V_44 = 0 ;
}
F_55 ( & V_417 -> V_214 ) ;
return V_44 ;
}
static int F_234 ( struct V_31 * V_32 , int V_33 , struct V_424 * V_66 ,
T_2 V_418 [ 16 ] , int V_425 , enum V_419 V_420 ,
enum V_421 type , T_1 * V_423 )
{
switch ( V_32 -> V_62 . V_426 ) {
case V_427 : {
int V_36 = F_137 ( V_32 , V_33 , V_418 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return F_235 ( V_32 , V_66 , V_418 , V_36 ,
V_425 , V_420 ,
V_423 ) ;
}
case V_428 :
if ( V_420 == V_429 ) {
int V_36 = F_137 ( V_32 , V_33 , V_418 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
V_418 [ 5 ] = V_36 ;
}
return F_236 ( V_32 , V_66 , V_418 ,
V_425 , V_420 , type ) ;
default:
return - V_45 ;
}
}
static int F_237 ( struct V_31 * V_32 , struct V_424 * V_66 ,
T_2 V_418 [ 16 ] , enum V_419 V_420 ,
enum V_421 type , T_1 V_423 )
{
switch ( V_32 -> V_62 . V_426 ) {
case V_427 :
return F_238 ( V_32 , V_423 ) ;
case V_428 :
return F_239 ( V_32 , V_66 , V_418 , V_420 , type ) ;
default:
return - V_45 ;
}
}
static int F_240 ( struct V_31 * V_32 , int V_33 ,
T_2 * V_418 , enum V_419 V_420 )
{
int V_430 ;
if ( V_420 != V_429 )
return 0 ;
if ( V_32 -> V_62 . V_426 == V_428 ||
V_32 -> V_62 . V_426 == V_427 ) {
V_430 = F_137 ( V_32 , V_33 , V_418 [ 5 ] ) ;
if ( V_430 < 0 )
return - V_45 ;
V_418 [ 5 ] = V_430 ;
}
return 0 ;
}
int F_241 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
struct V_424 V_66 ;
T_2 * V_418 = V_116 -> V_118 ;
enum V_419 V_420 = ( V_292 -> V_297 >> 28 ) & 0x7 ;
int V_44 ;
int V_139 ;
struct V_210 * V_417 ;
T_1 V_423 = 0 ;
int V_431 = V_292 -> V_296 ;
int V_425 = V_292 -> V_297 >> 31 ;
T_2 V_432 = 2 ;
enum V_421 type = ( V_418 [ 7 ] & V_432 ) >> 1 ;
V_139 = V_292 -> V_297 & 0xffffff ;
V_44 = F_154 ( V_32 , V_33 , V_139 , V_20 , & V_417 ) ;
if ( V_44 )
return V_44 ;
V_66 . V_139 = V_139 ;
if ( V_431 ) {
V_44 = F_234 ( V_32 , V_33 , & V_66 , V_418 , V_425 , V_420 ,
type , & V_423 ) ;
if ( V_44 ) {
F_76 ( L_41 , V_139 ) ;
goto V_334;
}
V_44 = F_232 ( V_32 , V_33 , V_417 , V_418 , V_420 , type , V_423 ) ;
if ( V_44 )
goto V_433;
} else {
V_44 = F_240 ( V_32 , V_33 , V_418 , V_420 ) ;
if ( V_44 )
goto V_334;
V_44 = F_233 ( V_32 , V_33 , V_417 , V_418 , V_420 , type , & V_423 ) ;
if ( V_44 )
goto V_334;
V_44 = F_237 ( V_32 , & V_66 , V_418 , V_420 , type , V_423 ) ;
if ( V_44 )
F_76 ( L_42 ,
V_139 , V_423 ) ;
}
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
V_433:
F_237 ( V_32 , & V_66 , V_418 , V_420 , type , V_423 ) ;
V_334:
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static int F_242 ( int V_33 , struct V_434 * V_435 ,
struct V_280 * V_436 )
{
struct V_282 * V_11 , * V_205 ;
T_5 V_437 ;
if ( ! F_243 ( V_435 -> V_438 . V_439 ) &&
! F_244 ( V_435 -> V_438 . V_439 ) ) {
F_131 (res, tmp, rlist, list) {
V_437 = F_245 ( V_11 -> V_279 << 16 ) ;
if ( F_246 ( ( T_2 * ) & V_437 , V_435 -> V_438 . V_439 ) )
return 0 ;
}
F_76 ( L_43 ,
V_435 -> V_438 . V_439 , V_33 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_247 ( struct V_31 * V_32 , int V_33 ,
struct V_115 * V_116 ,
struct V_280 * V_436 , int V_440 )
{
struct V_282 * V_11 , * V_205 ;
T_2 V_36 ;
struct V_441 * V_442 ;
struct V_443 * V_435 ;
struct V_444 * V_445 ;
struct V_446 * V_447 ;
T_5 V_437 = 0 ;
T_5 V_448 = F_245 ( V_449 << 16 ) ;
V_442 = (struct V_441 * ) V_116 -> V_118 ;
V_36 = V_442 -> V_36 ;
V_435 = (struct V_443 * ) ( V_442 + 1 ) ;
switch ( V_440 ) {
case V_450 :
V_445 =
(struct V_444 * ) ( V_435 + 1 ) ;
memmove ( V_445 , V_435 ,
sizeof( * V_445 ) + sizeof( * V_447 ) ) ;
break;
case V_451 :
case V_452 :
V_447 = (struct V_446 * )
( V_435 + 1 ) ;
memmove ( V_447 , V_435 , sizeof( * V_447 ) ) ;
break;
default:
return - V_45 ;
}
F_131 (res, tmp, rlist, list) {
if ( V_36 == V_11 -> V_36 ) {
V_437 = F_245 ( V_11 -> V_279 << 16 ) ;
break;
}
}
if ( ! V_437 ) {
F_76 ( L_44 ,
V_36 ) ;
return - V_45 ;
}
memset ( V_435 , 0 , sizeof( * V_435 ) ) ;
V_435 -> V_325 = sizeof( * V_435 ) >> 2 ;
V_435 -> V_197 = F_207 ( V_453 [ V_454 ] ) ;
memcpy ( V_435 -> V_439 , & V_437 , V_455 ) ;
memcpy ( V_435 -> V_456 , & V_448 , V_455 ) ;
return 0 ;
}
int F_248 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_457 )
{
int V_44 ;
T_3 V_139 = V_292 -> V_297 & 0xffffff ;
struct V_210 * V_417 ;
T_1 V_279 ;
unsigned V_36 ;
T_1 V_458 ;
struct V_459 * V_270 ;
int V_278 ;
V_270 = (struct V_459 * ) V_116 -> V_118 ;
V_458 = F_165 ( V_270 -> V_460 ) ;
if ( V_270 -> V_461 || V_270 -> V_462 ||
( V_458 & ~ V_463 ) )
return - V_194 ;
if ( ( V_458 &
( 1ULL << V_464 ) ) &&
! ( V_32 -> V_62 . V_161 &
V_465 ) ) {
F_10 ( V_32 , L_45 ,
V_33 ) ;
return - V_248 ;
}
V_44 = F_154 ( V_32 , V_33 , V_139 , V_20 , & V_417 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_46 , V_139 , V_33 ) ;
return V_44 ;
}
V_36 = ( V_417 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_458 & ( 1ULL << V_466 ) ) {
V_278 = V_270 -> V_467 . V_130 . V_186 ;
V_44 = F_130 ( V_32 , V_33 , V_36 ,
V_278 , & V_279 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_47 ,
V_139 , V_278 ) ;
goto V_468;
}
}
V_44 = F_208 ( V_32 , V_116 -> V_398 ,
V_292 -> V_297 , 0 ,
V_469 , V_470 ,
V_401 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_48 , V_139 ) ;
goto V_468;
}
V_468:
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static T_3 F_249 ( void * V_471 )
{
T_3 V_325 = sizeof( struct V_441 ) ;
struct V_434 * V_472 ;
V_472 = (struct V_434 * ) ( V_471 + V_325 ) ;
while ( V_472 -> V_325 ) {
V_325 += V_472 -> V_325 * sizeof( T_3 ) ;
V_472 += 1 ;
}
return V_325 ;
}
int F_250 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_436 = & V_204 -> V_87 [ V_33 ] . V_92 [ V_25 ] ;
int V_44 ;
int V_139 ;
struct V_210 * V_417 ;
struct V_441 * V_442 ;
struct V_434 * V_472 ;
int V_440 ;
struct V_230 * V_473 ;
T_3 V_474 ;
if ( V_32 -> V_62 . V_426 !=
V_427 )
return - V_248 ;
V_442 = (struct V_441 * ) V_116 -> V_118 ;
V_44 = F_137 ( V_32 , V_33 , V_442 -> V_36 ) ;
if ( V_44 <= 0 )
return - V_45 ;
V_442 -> V_36 = V_44 ;
V_139 = F_40 ( V_442 -> V_139 ) & 0xffffff ;
V_44 = F_154 ( V_32 , V_33 , V_139 , V_20 , & V_417 ) ;
if ( V_44 ) {
F_76 ( L_49 , V_139 ) ;
return V_44 ;
}
V_472 = (struct V_434 * ) ( V_442 + 1 ) ;
V_440 = F_251 ( F_252 ( V_472 -> V_197 ) ) ;
if ( V_440 == V_454 )
F_253 ( V_442 , V_472 ) ;
switch ( V_440 ) {
case V_454 :
if ( F_242 ( V_33 , V_472 , V_436 ) ) {
V_44 = - V_45 ;
goto V_475;
}
break;
case V_476 :
break;
case V_450 :
case V_451 :
case V_452 :
F_254 ( L_50 ) ;
if ( F_247 ( V_32 , V_33 , V_116 , V_436 , V_440 ) ) {
V_44 = - V_45 ;
goto V_475;
}
V_292 -> V_297 +=
sizeof( struct V_443 ) >> 2 ;
break;
default:
F_76 ( L_51 ) ;
V_44 = - V_45 ;
goto V_475;
}
V_44 = F_255 ( V_32 , V_116 -> V_398 , & V_292 -> V_272 ,
V_292 -> V_297 , 0 ,
V_477 , V_470 ,
V_401 ) ;
if ( V_44 )
goto V_475;
V_44 = F_80 ( V_32 , V_33 , V_292 -> V_272 , 1 , V_29 , V_139 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_52 ) ;
goto V_478;
}
V_44 = F_154 ( V_32 , V_33 , V_292 -> V_272 , V_29 , & V_473 ) ;
if ( V_44 )
goto V_478;
V_474 = F_249 ( V_116 -> V_118 ) ;
V_473 -> V_479 = F_25 ( V_474 , V_89 ) ;
if ( ! V_473 -> V_479 ) {
V_44 = - V_90 ;
goto V_480;
}
V_473 -> V_481 = V_474 ;
V_473 -> V_482 = 0 ;
memcpy ( V_473 -> V_479 , V_116 -> V_118 , V_474 ) ;
V_442 = (struct V_441 * ) V_473 -> V_479 ;
if ( V_442 -> V_36 == 1 )
V_442 -> V_36 = 2 ;
else
V_442 -> V_36 = 1 ;
if ( F_256 ( V_32 ) )
F_257 ( V_32 , V_473 ) ;
F_178 ( & V_417 -> V_215 ) ;
V_480:
F_57 ( V_32 , V_33 , V_292 -> V_272 , V_29 ) ;
V_478:
if ( V_44 )
F_208 ( V_32 , V_292 -> V_272 , 0 , 0 ,
V_483 , V_470 ,
V_401 ) ;
V_475:
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
static int F_258 ( struct V_31 * V_32 , struct V_230 * V_484 )
{
int V_44 ;
V_44 = F_97 ( V_32 , V_484 -> V_202 . V_193 , V_484 -> V_202 . V_7 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_53 ) ;
return V_44 ;
}
F_208 ( V_32 , V_484 -> V_202 . V_7 , 0 , 0 , V_483 ,
V_470 , V_401 ) ;
return 0 ;
}
int F_259 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
struct V_210 * V_417 ;
struct V_230 * V_473 ;
T_1 V_485 ;
int V_139 ;
if ( V_32 -> V_62 . V_426 !=
V_427 )
return - V_248 ;
V_44 = F_154 ( V_32 , V_33 , V_292 -> V_271 , V_29 , & V_473 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_473 -> V_479 ) {
F_64 ( V_32 , L_54 ) ;
F_57 ( V_32 , V_33 , V_292 -> V_271 , V_29 ) ;
return - V_45 ;
}
V_485 = V_473 -> V_482 ;
F_31 ( V_473 -> V_479 ) ;
V_139 = V_473 -> V_139 ;
F_57 ( V_32 , V_33 , V_292 -> V_271 , V_29 ) ;
V_44 = F_154 ( V_32 , V_33 , V_139 , V_20 , & V_417 ) ;
if ( V_44 )
return V_44 ;
if ( V_485 && F_256 ( V_32 ) ) {
V_44 = F_154 ( V_32 , V_33 , V_485 , V_29 , & V_473 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_55 ) ;
} else {
F_57 ( V_32 , V_33 , V_485 , V_29 ) ;
F_258 ( V_32 , V_473 ) ;
}
}
V_44 = F_97 ( V_32 , V_33 , V_292 -> V_271 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_53 ) ;
goto V_59;
}
V_44 = F_208 ( V_32 , V_292 -> V_271 , 0 , 0 ,
V_483 , V_470 ,
V_401 ) ;
if ( ! V_44 )
F_180 ( & V_417 -> V_215 ) ;
V_59:
F_57 ( V_32 , V_33 , V_139 , V_20 ) ;
return V_44 ;
}
int F_260 ( struct V_31 * V_32 , int V_33 ,
struct V_291 * V_292 ,
struct V_115 * V_116 ,
struct V_115 * V_293 ,
struct V_294 * V_270 )
{
int V_44 ;
int V_254 = V_292 -> V_297 & 0xffff ;
V_44 = F_154 ( V_32 , V_33 , V_254 , V_28 , NULL ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_292 , V_116 , V_293 , V_270 ) ;
F_57 ( V_32 , V_33 , V_254 , V_28 ) ;
return V_44 ;
}
static void F_261 ( struct V_31 * V_32 , int V_33 , struct V_210 * V_417 )
{
struct V_416 * V_486 ;
struct V_416 * V_205 ;
struct V_424 V_66 ;
F_131 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_32 -> V_62 . V_426 ) {
case V_427 :
F_238 ( V_32 , V_486 -> V_423 ) ;
break;
case V_428 :
V_66 . V_139 = V_417 -> V_212 ;
( void ) F_239 ( V_32 , & V_66 , V_486 -> V_418 ,
V_486 -> V_420 , V_486 -> V_422 ) ;
break;
}
F_98 ( & V_486 -> V_240 ) ;
F_31 ( V_486 ) ;
}
}
static int F_262 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_487 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_436 = & V_204 -> V_87 [ V_33 ] . V_92 [ type ] ;
struct V_10 * V_189 ;
struct V_10 * V_205 ;
int V_488 ;
V_488 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (r, tmp, rlist, list) {
if ( V_189 -> V_193 == V_33 ) {
if ( ! V_189 -> V_489 ) {
if ( V_189 -> V_2 == V_191 ) {
if ( V_487 )
F_24 ( V_32 ,
L_56 ,
F_7 ( type ) ,
V_189 -> V_7 ) ;
++ V_488 ;
} else {
V_189 -> V_195 = V_189 -> V_2 ;
V_189 -> V_2 = V_191 ;
V_189 -> V_489 = 1 ;
}
}
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_488 ;
}
static int F_263 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type )
{
unsigned long V_490 ;
int V_488 ;
V_490 = V_491 ;
do {
V_488 = F_262 ( V_32 , V_33 , type , 0 ) ;
if ( F_264 ( V_491 , V_490 + 5 * V_492 ) )
break;
if ( V_488 )
F_265 () ;
} while ( V_488 );
if ( V_488 )
V_488 = F_262 ( V_32 , V_33 , type , 1 ) ;
return V_488 ;
}
static void F_266 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_493 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_20 ] ;
struct V_210 * V_66 ;
struct V_210 * V_205 ;
int V_2 ;
T_1 V_271 ;
int V_139 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_20 ) ;
if ( V_44 )
F_10 ( V_32 , L_57 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (qp, tmp, qp_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_66 -> V_202 . V_193 == V_33 ) {
V_139 = V_66 -> V_202 . V_7 ;
F_261 ( V_32 , V_33 , V_66 ) ;
V_2 = V_66 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_211 :
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_66 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_20 ] ) ;
F_98 ( & V_66 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
if ( ! F_106 ( V_32 , V_33 , V_139 ) ) {
F_114 ( V_32 , V_139 , 1 ) ;
F_12 ( V_32 , V_33 ,
V_20 , 1 , 0 ) ;
}
F_31 ( V_66 ) ;
V_2 = 0 ;
break;
case V_251 :
if ( ! F_106 ( V_32 , V_33 , V_139 ) )
F_151 ( V_32 , V_139 ) ;
V_2 = V_211 ;
break;
case V_252 :
V_271 = V_33 ;
V_44 = F_208 ( V_32 , V_271 ,
V_66 -> V_212 , 2 ,
V_494 ,
V_470 ,
V_401 ) ;
if ( V_44 )
F_24 ( V_32 , L_58 ,
V_33 , V_66 -> V_212 ) ;
F_180 ( & V_66 -> V_343 -> V_215 ) ;
F_180 ( & V_66 -> V_344 -> V_215 ) ;
F_180 ( & V_66 -> V_75 -> V_215 ) ;
if ( V_66 -> V_72 )
F_180 ( & V_66 -> V_72 -> V_215 ) ;
V_2 = V_251 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_267 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_495 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_22 ] ;
struct V_225 * V_72 ;
struct V_225 * V_205 ;
int V_2 ;
T_1 V_271 ;
F_268 ( V_496 ) ;
int V_277 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_22 ) ;
if ( V_44 )
F_10 ( V_32 , L_59 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (srq, tmp, srq_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_72 -> V_202 . V_193 == V_33 ) {
V_277 = V_72 -> V_202 . V_7 ;
V_2 = V_72 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_226 :
F_129 ( V_32 , V_277 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_72 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_22 ] ) ;
F_98 ( & V_72 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_22 , 1 , 0 ) ;
F_31 ( V_72 ) ;
V_2 = 0 ;
break;
case V_266 :
V_271 = V_33 ;
V_44 = F_208 ( V_32 , V_271 , V_277 , 1 ,
V_497 ,
V_470 ,
V_401 ) ;
if ( V_44 )
F_24 ( V_32 , L_60 ,
V_33 , V_277 ) ;
F_180 ( & V_72 -> V_75 -> V_215 ) ;
if ( V_72 -> V_69 )
F_180 ( & V_72 -> V_69 -> V_215 ) ;
V_2 = V_226 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_269 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_498 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_21 ] ;
struct V_223 * V_69 ;
struct V_223 * V_205 ;
int V_2 ;
T_1 V_271 ;
F_268 ( V_496 ) ;
int V_262 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_21 ) ;
if ( V_44 )
F_10 ( V_32 , L_61 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (cq, tmp, cq_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_69 -> V_202 . V_193 == V_33 && ! F_85 ( & V_69 -> V_215 ) ) {
V_262 = V_69 -> V_202 . V_7 ;
V_2 = V_69 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_224 :
F_126 ( V_32 , V_262 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_69 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_21 ] ) ;
F_98 ( & V_69 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_21 , 1 , 0 ) ;
F_31 ( V_69 ) ;
V_2 = 0 ;
break;
case V_264 :
V_271 = V_33 ;
V_44 = F_208 ( V_32 , V_271 , V_262 , 1 ,
V_499 ,
V_470 ,
V_401 ) ;
if ( V_44 )
F_24 ( V_32 , L_62 ,
V_33 , V_262 ) ;
F_180 ( & V_69 -> V_75 -> V_215 ) ;
V_2 = V_224 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_270 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_500 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_23 ] ;
struct V_219 * V_77 ;
struct V_219 * V_205 ;
int V_2 ;
T_1 V_271 ;
F_268 ( V_496 ) ;
int V_501 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_23 ) ;
if ( V_44 )
F_10 ( V_32 , L_63 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (mpt, tmp, mpt_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_77 -> V_202 . V_193 == V_33 ) {
V_501 = V_77 -> V_202 . V_7 ;
V_2 = V_77 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_220 :
F_122 ( V_32 , V_77 -> V_218 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_77 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_23 ] ) ;
F_98 ( & V_77 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_23 , 1 , 0 ) ;
F_31 ( V_77 ) ;
V_2 = 0 ;
break;
case V_256 :
F_155 ( V_32 , V_77 -> V_218 ) ;
V_2 = V_220 ;
break;
case V_257 :
V_271 = V_33 ;
V_44 = F_208 ( V_32 , V_271 , V_501 , 0 ,
V_502 ,
V_470 ,
V_401 ) ;
if ( V_44 )
F_24 ( V_32 , L_64 ,
V_33 , V_501 ) ;
if ( V_77 -> V_75 )
F_180 ( & V_77 -> V_75 -> V_215 ) ;
V_2 = V_256 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_271 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_503 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_24 ] ;
struct V_217 * V_75 ;
struct V_217 * V_205 ;
int V_2 ;
F_268 ( V_496 ) ;
int V_237 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_24 ) ;
if ( V_44 )
F_10 ( V_32 , L_65 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (mtt, tmp, mtt_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_75 -> V_202 . V_193 == V_33 ) {
V_237 = V_75 -> V_202 . V_7 ;
V_2 = V_75 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_119 ( V_32 , V_237 ,
V_75 -> V_216 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_75 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_24 ] ) ;
F_98 ( & V_75 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 , V_24 ,
1 << V_75 -> V_216 , 0 ) ;
F_31 ( V_75 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static int F_257 ( struct V_31 * V_32 , struct V_230 * V_484 )
{
struct V_115 * V_389 ;
int V_44 ;
struct V_230 * V_504 ;
T_1 V_423 ;
V_389 = F_204 ( V_32 ) ;
if ( F_205 ( V_389 ) )
return F_206 ( V_389 ) ;
if ( ! V_484 -> V_479 ) {
F_64 ( V_32 , L_66 ) ;
return - V_45 ;
}
memcpy ( V_389 -> V_118 , V_484 -> V_479 , V_484 -> V_481 ) ;
V_44 = F_255 ( V_32 , V_389 -> V_398 , & V_423 , V_484 -> V_481 >> 2 , 0 ,
V_477 , V_470 ,
V_401 ) ;
F_209 ( V_32 , V_389 ) ;
if ( V_44 )
goto V_44;
V_44 = F_80 ( V_32 , V_484 -> V_202 . V_193 , V_423 , 1 , V_29 , V_484 -> V_139 ) ;
if ( V_44 )
goto V_478;
V_44 = F_154 ( V_32 , V_484 -> V_202 . V_193 , V_423 , V_29 , & V_504 ) ;
if ( V_44 )
goto V_505;
V_484 -> V_482 = V_423 ;
V_504 -> V_482 = 0 ;
V_504 -> V_481 = 0 ;
V_504 -> V_479 = NULL ;
F_57 ( V_32 , V_484 -> V_202 . V_193 , V_423 , V_29 ) ;
return 0 ;
V_505:
F_97 ( V_32 , V_484 -> V_202 . V_193 , V_423 , 1 , V_29 , 0 ) ;
V_478:
F_208 ( V_32 , V_423 , 0 , 0 , V_483 ,
V_470 , V_401 ) ;
V_44:
return V_44 ;
}
static int F_272 ( struct V_31 * V_32 , bool V_506 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_204 -> V_94 [ V_29 ] ;
struct V_8 * V_507 ;
struct V_230 * V_484 ;
int V_44 = 0 ;
F_268 ( V_508 ) ;
for ( V_507 = F_273 ( V_6 ) ; V_507 ; V_507 = F_274 ( V_507 ) ) {
V_484 = F_3 ( V_507 , struct V_230 , V_202 . V_9 ) ;
if ( ( V_506 && V_484 -> V_481 ) ||
( ! V_506 && ! V_484 -> V_481 ) )
F_81 ( & V_484 -> V_508 , & V_508 ) ;
}
F_62 (fs_rule, &mirr_list, mirr_list) {
if ( V_506 )
V_44 += F_257 ( V_32 , V_484 ) ;
else
V_44 += F_258 ( V_32 , V_484 ) ;
}
return V_44 ;
}
int F_275 ( struct V_31 * V_32 )
{
return F_272 ( V_32 , true ) ;
}
int F_276 ( struct V_31 * V_32 )
{
return F_272 ( V_32 , false ) ;
}
static void F_277 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_509 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_29 ] ;
struct V_230 * V_484 ;
struct V_230 * V_205 ;
int V_2 ;
T_1 V_237 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_29 ) ;
if ( V_44 )
F_10 ( V_32 , L_67 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (fs_rule, tmp, fs_rule_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_484 -> V_202 . V_193 == V_33 ) {
V_237 = V_484 -> V_202 . V_7 ;
V_2 = V_484 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_231 :
V_44 = F_208 ( V_32 , V_237 , 0 , 0 ,
V_483 ,
V_470 ,
V_401 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_484 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_29 ] ) ;
F_98 ( & V_484 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_31 ( V_484 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_278 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_510 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_27 ] ;
struct V_221 * V_259 ;
struct V_221 * V_205 ;
int V_44 ;
int V_2 ;
F_268 ( V_496 ) ;
int V_361 ;
V_44 = F_263 ( V_32 , V_33 , V_27 ) ;
if ( V_44 )
F_10 ( V_32 , L_68 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (eq, tmp, eq_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_259 -> V_202 . V_193 == V_33 ) {
V_361 = V_259 -> V_202 . V_7 ;
V_2 = V_259 -> V_202 . V_195 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_222 :
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_259 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_27 ] ) ;
F_98 ( & V_259 -> V_202 . V_240 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_31 ( V_259 ) ;
V_2 = 0 ;
break;
case V_261 :
V_44 = F_208 ( V_32 , V_33 , V_361 & 0x3ff ,
1 , V_511 ,
V_470 ,
V_401 ) ;
if ( V_44 )
F_24 ( V_32 , L_69 ,
V_33 , V_361 & 0x3ff ) ;
F_180 ( & V_259 -> V_75 -> V_215 ) ;
V_2 = V_222 ;
break;
default:
V_2 = 0 ;
}
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_279 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_512 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_28 ] ;
struct V_199 * V_200 ;
struct V_199 * V_205 ;
int V_44 ;
int * V_235 = NULL ;
int V_83 , V_84 ;
V_44 = F_263 ( V_32 , V_33 , V_28 ) ;
if ( V_44 )
F_10 ( V_32 , L_70 ,
V_33 ) ;
V_235 = F_78 ( V_32 -> V_62 . V_80 ,
sizeof( * V_235 ) , V_89 ) ;
if ( ! V_235 )
return;
do {
V_83 = 0 ;
V_84 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (counter, tmp, counter_list, com.list) {
if ( V_200 -> V_202 . V_193 == V_33 ) {
V_235 [ V_83 ++ ] = V_200 -> V_202 . V_7 ;
F_82 ( & V_200 -> V_202 . V_9 ,
& V_204 -> V_94 [ V_28 ] ) ;
F_98 ( & V_200 -> V_202 . V_240 ) ;
F_31 ( V_200 ) ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
while ( V_84 < V_83 ) {
F_145 ( V_32 , V_235 [ V_84 ++ ] ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
}
} while ( V_83 );
F_31 ( V_235 ) ;
}
static void F_280 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_203 * V_204 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_513 =
& V_204 -> V_87 [ V_33 ] . V_92 [ V_30 ] ;
struct V_228 * V_514 ;
struct V_228 * V_205 ;
int V_44 ;
int V_290 ;
V_44 = F_263 ( V_32 , V_33 , V_30 ) ;
if ( V_44 )
F_10 ( V_32 , L_71 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_514 -> V_202 . V_193 == V_33 ) {
V_290 = V_514 -> V_202 . V_7 ;
F_82 ( & V_514 -> V_202 . V_9 , & V_204 -> V_94 [ V_30 ] ) ;
F_98 ( & V_514 -> V_202 . V_240 ) ;
F_31 ( V_514 ) ;
F_148 ( V_32 , V_290 ) ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
}
void F_33 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
F_34 ( V_32 , V_33 ) ;
F_35 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
F_36 ( V_32 , V_33 ) ;
F_134 ( V_32 , V_33 ) ;
F_277 ( V_32 , V_33 ) ;
F_266 ( V_32 , V_33 ) ;
F_267 ( V_32 , V_33 ) ;
F_269 ( V_32 , V_33 ) ;
F_270 ( V_32 , V_33 ) ;
F_278 ( V_32 , V_33 ) ;
F_271 ( V_32 , V_33 ) ;
F_279 ( V_32 , V_33 ) ;
F_280 ( V_32 , V_33 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_87 [ V_33 ] . V_93 ) ;
}
void F_281 ( struct V_515 * V_516 )
{
struct V_517 * V_518 =
F_60 ( V_516 , struct V_517 , V_518 ) ;
struct V_115 * V_389 ;
struct V_459 * V_519 ;
struct V_31 * V_32 = & V_518 -> V_38 -> V_32 ;
struct V_203 * V_204 =
& V_518 -> V_38 -> V_41 . V_42 . V_43 ;
struct V_280 * V_493 =
& V_204 -> V_87 [ V_518 -> V_33 ] . V_92 [ V_20 ] ;
struct V_210 * V_66 ;
struct V_210 * V_205 ;
T_1 V_520 =
( ( 1ULL << V_521 ) |
( 1ULL << V_522 ) |
( 1ULL << V_523 ) |
( 1ULL << V_524 ) |
( 1ULL << V_525 ) |
( 1ULL << V_526 ) ) ;
T_1 V_527 = ( ( 1ULL << V_528 ) |
( 1ULL << V_529 ) |
( 1ULL << V_530 ) |
( 1ULL << V_531 ) |
( 1ULL << V_532 ) |
( 1ULL << V_533 ) |
( 1ULL << V_534 ) |
( 1ULL << V_535 ) ) ;
int V_44 ;
int V_36 , V_536 = 0 ;
T_2 V_157 ;
if ( F_16 ( V_32 ) ) {
F_10 ( V_32 , L_72 ,
V_518 -> V_33 ) ;
goto V_59;
}
V_389 = F_204 ( V_32 ) ;
if ( F_205 ( V_389 ) )
goto V_59;
if ( V_518 -> V_128 & V_537 )
V_157 = V_163 |
V_164 |
V_165 |
V_166 |
V_167 |
V_168 ;
else if ( ! V_518 -> V_538 )
V_157 = V_163 |
V_168 ;
else if ( V_518 -> V_169 == F_48 ( V_170 ) )
V_157 = V_164 |
V_163 |
V_166 |
V_167 ;
else
V_157 = V_163 |
V_166 |
V_167 ;
V_519 = V_389 -> V_118 ;
V_519 -> V_461 = F_245 ( 1ULL << V_539 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (qp, tmp, qp_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_66 -> V_202 . V_193 == V_518 -> V_33 ) {
if ( V_66 -> V_202 . V_195 != V_252 ||
! V_66 -> V_131 ||
F_45 ( V_32 , V_66 -> V_212 ) ||
V_66 -> V_349 & ( 1 << V_540 ) ) {
F_53 ( F_54 ( V_32 ) ) ;
continue;
}
V_36 = ( V_66 -> V_131 >> 6 & 1 ) + 1 ;
if ( V_36 != V_518 -> V_36 ) {
F_53 ( F_54 ( V_32 ) ) ;
continue;
}
if ( V_133 == ( ( V_66 -> V_349 >> 16 ) & 0xff ) )
V_519 -> V_460 = F_245 ( V_527 ) ;
else
V_519 -> V_460 =
F_245 ( V_527 | V_520 ) ;
if ( V_518 -> V_538 == V_146 ) {
V_519 -> V_467 . V_152 = V_66 -> V_152 ;
V_519 -> V_467 . V_130 . V_157 = V_66 -> V_157 ;
V_519 -> V_467 . V_130 . V_171 = V_66 -> V_171 ;
V_519 -> V_467 . V_130 . V_173 = V_66 -> V_173 ;
V_519 -> V_467 . V_130 . V_175 = V_66 -> V_348 ;
V_519 -> V_467 . V_130 . V_179 = V_66 -> V_179 ;
V_519 -> V_467 . V_130 . V_131 =
V_66 -> V_131 ;
} else {
V_519 -> V_467 . V_152 = V_66 -> V_152 & ~ F_46 ( V_153 ) ;
V_519 -> V_467 . V_130 . V_157 = V_157 ;
V_519 -> V_467 . V_130 . V_173 = V_518 -> V_541 ;
V_519 -> V_467 . V_130 . V_171 =
V_66 -> V_171 | V_172 ;
V_519 -> V_467 . V_130 . V_175 =
V_66 -> V_348 | V_176 ;
if ( V_518 -> V_169 == F_48 ( V_170 ) )
V_519 -> V_467 . V_130 . V_175 |= V_177 ;
else
V_519 -> V_467 . V_130 . V_175 |= V_178 ;
V_519 -> V_467 . V_130 . V_179 =
V_66 -> V_179 | V_180 | V_181 ;
V_519 -> V_467 . V_130 . V_131 =
V_66 -> V_131 & 0xC7 ;
V_519 -> V_467 . V_130 . V_131 |=
( ( V_518 -> V_542 & 0x7 ) << 3 ) ;
V_519 -> V_461 |=
F_245 ( 1ULL <<
V_543 ) ;
V_519 -> V_467 . V_183 =
V_518 -> V_183 ;
}
V_44 = F_208 ( V_32 , V_389 -> V_398 ,
V_66 -> V_212 & 0xffffff ,
0 , V_469 ,
V_544 , V_401 ) ;
if ( V_44 ) {
F_282 ( V_32 , L_73 ,
V_518 -> V_33 , V_36 , V_66 -> V_212 , V_44 ) ;
V_536 ++ ;
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
F_209 ( V_32 , V_389 ) ;
if ( V_536 )
F_64 ( V_32 , L_74 ,
V_536 , V_518 -> V_33 , V_518 -> V_36 ) ;
if ( V_518 -> V_128 & V_545 && ! V_536 &&
V_546 != V_518 -> V_547 )
F_141 ( & V_518 -> V_38 -> V_32 , V_518 -> V_36 ,
V_518 -> V_548 ) ;
V_59:
F_31 ( V_518 ) ;
return;
}
