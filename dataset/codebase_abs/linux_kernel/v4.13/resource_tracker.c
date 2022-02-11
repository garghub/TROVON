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
return - V_53 ;
F_9 ( & V_40 -> V_54 ) ;
V_46 = ( V_36 > 0 ) ?
V_40 -> V_46 [ ( V_36 - 1 ) *
( V_32 -> V_51 -> V_52 + 1 ) + V_33 ] :
V_40 -> V_46 [ V_33 ] ;
free = ( V_36 > 0 ) ? V_40 -> V_55 [ V_36 - 1 ] :
V_40 -> V_56 ;
V_47 = ( V_36 > 0 ) ? V_40 -> V_57 [ V_36 - 1 ] :
V_40 -> V_58 ;
V_48 = V_40 -> V_48 [ V_33 ] ;
if ( V_46 + V_35 > V_40 -> V_59 [ V_33 ] ) {
F_10 ( V_32 , L_16 ,
V_33 , V_36 , F_7 ( V_34 ) , V_35 ,
V_46 , V_40 -> V_59 [ V_33 ] ) ;
goto V_60;
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
V_40 -> V_55 [ V_36 - 1 ] -= V_35 ;
V_40 -> V_57 [ V_36 - 1 ] -= V_50 ;
} else {
V_40 -> V_46 [ V_33 ] += V_35 ;
V_40 -> V_56 -= V_35 ;
V_40 -> V_58 -= V_50 ;
}
}
V_60:
F_11 ( & V_40 -> V_54 ) ;
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
F_9 ( & V_40 -> V_54 ) ;
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
V_40 -> V_55 [ V_36 - 1 ] += V_35 ;
V_40 -> V_57 [ V_36 - 1 ] += V_50 ;
} else {
V_40 -> V_46 [ V_33 ] -= V_35 ;
V_40 -> V_56 += V_35 ;
V_40 -> V_58 += V_50 ;
}
F_11 ( & V_40 -> V_54 ) ;
return;
}
static inline void F_13 ( struct V_31 * V_32 ,
struct V_39 * V_40 ,
enum V_18 V_34 ,
int V_61 , int V_62 )
{
V_40 -> V_48 [ V_61 ] = V_62 /
( 2 * ( V_32 -> V_51 -> V_52 + 1 ) ) ;
V_40 -> V_59 [ V_61 ] = ( V_62 / 2 ) + V_40 -> V_48 [ V_61 ] ;
if ( V_61 == F_14 ( V_32 ) ) {
V_40 -> V_56 = V_62 ;
if ( V_34 == V_24 ) {
V_40 -> V_56 += V_32 -> V_63 . V_64 ;
V_40 -> V_48 [ V_61 ] += V_32 -> V_63 . V_64 ;
V_40 -> V_59 [ V_61 ] += V_32 -> V_63 . V_64 ;
}
}
}
void F_15 ( struct V_31 * V_32 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_65 ;
if ( F_16 ( V_32 ) )
return;
if ( ! F_17 ( V_32 ) ) {
V_32 -> V_66 . V_67 = V_32 -> V_63 . V_68 - V_32 -> V_63 . V_69 -
F_18 ( V_32 ) ;
V_32 -> V_66 . V_70 = V_32 -> V_63 . V_71 - V_32 -> V_63 . V_72 ;
V_32 -> V_66 . V_73 = V_32 -> V_63 . V_74 - V_32 -> V_63 . V_75 ;
V_32 -> V_66 . V_76 = V_32 -> V_63 . V_77 - V_32 -> V_63 . V_64 ;
V_32 -> V_66 . V_78 = V_32 -> V_63 . V_79 - V_32 -> V_63 . V_80 ;
return;
}
V_65 = F_14 ( V_32 ) ;
V_32 -> V_66 . V_67 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_20 ] . V_59 [ V_65 ] ;
V_32 -> V_66 . V_70 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_21 ] . V_59 [ V_65 ] ;
V_32 -> V_66 . V_73 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_22 ] . V_59 [ V_65 ] ;
V_32 -> V_66 . V_76 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_24 ] . V_59 [ V_65 ] ;
V_32 -> V_66 . V_78 =
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_23 ] . V_59 [ V_65 ] ;
}
static int F_19 ( struct V_31 * V_32 )
{
return ( V_32 -> V_63 . V_81 - 1 -
( V_82 * V_83 ) )
/ V_83 ;
}
int F_20 ( struct V_31 * V_32 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_84 , V_85 ;
int V_86 ;
int V_87 = F_19 ( V_32 ) ;
V_38 -> V_41 . V_42 . V_43 . V_88 =
F_21 ( V_32 -> V_89 * sizeof( struct V_88 ) ,
V_90 ) ;
if ( ! V_38 -> V_41 . V_42 . V_43 . V_88 )
return - V_91 ;
for ( V_84 = 0 ; V_84 < V_32 -> V_89 ; V_84 ++ ) {
for ( V_86 = 0 ; V_86 < V_92 ; ++ V_86 )
F_22 ( & V_38 -> V_41 . V_42 . V_43 .
V_88 [ V_84 ] . V_93 [ V_86 ] ) ;
F_23 ( & V_38 -> V_41 . V_42 . V_43 . V_88 [ V_84 ] . V_94 ) ;
}
F_24 ( V_32 , L_18 ,
V_32 -> V_89 ) ;
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ )
V_38 -> V_41 . V_42 . V_43 . V_95 [ V_84 ] = V_96 ;
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
struct V_39 * V_40 =
& V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] ;
V_40 -> V_59 = F_25 ( ( V_32 -> V_51 -> V_52 + 1 ) *
sizeof( int ) , V_90 ) ;
V_40 -> V_48 = F_25 ( ( V_32 -> V_51 -> V_52 + 1 ) *
sizeof( int ) , V_90 ) ;
if ( V_84 == V_25 || V_84 == V_26 )
V_40 -> V_46 = F_21 ( V_83 *
( V_32 -> V_51 -> V_52
+ 1 ) *
sizeof( int ) , V_90 ) ;
else
V_40 -> V_46 = F_21 ( ( V_32 -> V_51 ->
V_52 + 1 ) *
sizeof( int ) , V_90 ) ;
if ( V_84 == V_28 )
V_40 -> V_56 = V_32 -> V_63 . V_81 - 1 ;
if ( ! V_40 -> V_59 || ! V_40 -> V_48 ||
! V_40 -> V_46 )
goto V_97;
F_26 ( & V_40 -> V_54 ) ;
for ( V_86 = 0 ; V_86 < V_32 -> V_51 -> V_52 + 1 ; V_86 ++ ) {
struct V_98 V_99 =
F_27 ( V_32 , V_86 ) ;
switch ( V_84 ) {
case V_20 :
F_13 ( V_32 , V_40 , V_20 ,
V_86 , V_32 -> V_63 . V_68 -
V_32 -> V_63 . V_69 -
F_18 ( V_32 ) ) ;
break;
case V_21 :
F_13 ( V_32 , V_40 , V_21 ,
V_86 , V_32 -> V_63 . V_71 -
V_32 -> V_63 . V_72 ) ;
break;
case V_22 :
F_13 ( V_32 , V_40 , V_22 ,
V_86 , V_32 -> V_63 . V_74 -
V_32 -> V_63 . V_75 ) ;
break;
case V_23 :
F_13 ( V_32 , V_40 , V_23 ,
V_86 , V_32 -> V_63 . V_79 -
V_32 -> V_63 . V_80 ) ;
break;
case V_24 :
F_13 ( V_32 , V_40 , V_24 ,
V_86 , V_32 -> V_63 . V_77 -
V_32 -> V_63 . V_64 ) ;
break;
case V_25 :
if ( V_86 == F_14 ( V_32 ) ) {
int V_100 = 0 ;
for ( V_85 = 0 ; V_85 < V_32 -> V_63 . V_101 ;
V_85 ++ ) {
struct V_102 V_103 =
F_28 ( V_32 , V_85 + 1 ) ;
unsigned V_104 =
F_29 ( V_103 . V_105 ,
V_32 -> V_63 . V_101 ) - 1 ;
if ( V_100 < V_104 )
V_100 =
V_104 ;
}
V_40 -> V_59 [ V_86 ] =
V_106 -
2 * V_100 ;
V_40 -> V_48 [ V_86 ] = 2 ;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ )
V_40 -> V_55 [ V_85 ] =
V_106 ;
} else {
V_40 -> V_59 [ V_86 ] = V_106 ;
V_40 -> V_48 [ V_86 ] = 2 ;
}
break;
case V_26 :
if ( V_86 == F_14 ( V_32 ) ) {
V_40 -> V_59 [ V_86 ] = V_107 ;
V_40 -> V_48 [ V_86 ] = V_107 / 2 ;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ )
V_40 -> V_55 [ V_85 ] =
V_40 -> V_59 [ V_86 ] ;
} else {
V_40 -> V_59 [ V_86 ] = V_107 / 2 ;
V_40 -> V_48 [ V_86 ] = 0 ;
}
break;
case V_28 :
V_40 -> V_59 [ V_86 ] = V_32 -> V_63 . V_81 ;
if ( V_86 == F_14 ( V_32 ) )
V_40 -> V_48 [ V_86 ] =
V_82 *
V_83 ;
else if ( V_86 <= V_87 )
V_40 -> V_48 [ V_86 ] =
V_108 *
V_83 ;
else
V_40 -> V_48 [ V_86 ] = 0 ;
V_40 -> V_56 -= V_40 -> V_48 [ V_86 ] ;
break;
default:
break;
}
if ( V_84 == V_25 || V_84 == V_26 ) {
for ( V_85 = 0 ; V_85 < V_32 -> V_63 . V_101 ; V_85 ++ )
if ( F_30 ( V_85 , V_99 . V_109 ) )
V_40 -> V_57 [ V_85 ] +=
V_40 -> V_48 [ V_86 ] ;
} else {
V_40 -> V_58 += V_40 -> V_48 [ V_86 ] ;
}
}
}
F_26 ( & V_38 -> V_41 . V_42 . V_43 . V_110 ) ;
return 0 ;
V_97:
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_46 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_46 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_48 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_48 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_59 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_59 = NULL ;
}
return - V_91 ;
}
void F_32 ( struct V_31 * V_32 ,
enum V_111 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_84 ;
if ( V_38 -> V_41 . V_42 . V_43 . V_88 ) {
if ( type != V_112 ) {
for ( V_84 = 0 ; V_84 < V_32 -> V_89 ; V_84 ++ ) {
if ( type == V_113 ||
V_32 -> V_63 . V_114 != V_84 )
F_33 ( V_32 , V_84 ) ;
}
V_84 = V_32 -> V_63 . V_114 ;
F_34 ( V_32 , V_84 ) ;
F_35 ( & V_38 -> V_41 . V_42 . V_43 . V_88 [ V_84 ] . V_94 ) ;
F_36 ( V_32 , V_84 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_88 [ V_84 ] . V_94 ) ;
}
if ( type != V_115 ) {
for ( V_84 = 0 ; V_84 < V_92 ; V_84 ++ ) {
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_46 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_46 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_48 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_48 = NULL ;
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_59 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_84 ] . V_59 = NULL ;
}
F_31 ( V_38 -> V_41 . V_42 . V_43 . V_88 ) ;
V_38 -> V_41 . V_42 . V_43 . V_88 = NULL ;
}
}
}
static void F_38 ( struct V_31 * V_32 , int V_33 ,
struct V_116 * V_117 )
{
T_2 V_118 = * ( T_2 * ) ( V_117 -> V_119 + 64 ) ;
T_2 V_120 = * ( T_2 * ) ( V_117 -> V_119 + 35 ) ;
T_2 V_121 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_36 ;
V_36 = ( V_118 >> 6 & 1 ) + 1 ;
V_121 = V_38 -> V_122 [ V_33 ] [ V_36 - 1 ] [ V_120 ] ;
* ( T_2 * ) ( V_117 -> V_119 + 35 ) = V_121 ;
}
static void F_39 ( struct V_31 * V_32 , struct V_116 * V_117 ,
T_2 V_33 )
{
struct V_123 * V_124 = V_117 -> V_119 + 8 ;
enum V_125 V_126 = F_40 ( * ( V_127 * ) V_117 -> V_119 ) ;
T_3 V_128 = ( F_40 ( V_124 -> V_129 ) >> 16 ) & 0xff ;
int V_36 ;
if ( V_130 == V_128 ) {
V_36 = ( V_124 -> V_131 . V_132 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) )
V_124 -> V_131 . V_133 =
F_42 ( V_32 , V_33 , V_36 ) | 0x80 ;
else
V_124 -> V_131 . V_133 = V_33 | 0x80 ;
} else if ( V_134 == V_128 || V_135 == V_128 || V_136 == V_128 ) {
if ( V_126 & V_137 ) {
V_36 = ( V_124 -> V_131 . V_132 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) ) {
V_124 -> V_131 . V_133 +=
F_42 ( V_32 , V_33 , V_36 ) ;
V_124 -> V_131 . V_133 &= 0x7f ;
} else {
V_124 -> V_131 . V_133 = V_33 & 0x7F ;
}
}
if ( V_126 & V_138 ) {
V_36 = ( V_124 -> V_139 . V_132 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) ) {
V_124 -> V_139 . V_133 +=
F_42 ( V_32 , V_33 , V_36 ) ;
V_124 -> V_139 . V_133 &= 0x7f ;
} else {
V_124 -> V_139 . V_133 = V_33 & 0x7F ;
}
}
}
}
static int F_43 ( struct V_31 * V_32 ,
struct V_116 * V_117 ,
T_2 V_33 , T_3 V_140 )
{
struct V_123 * V_141 = V_117 -> V_119 + 8 ;
struct V_142 * V_143 ;
struct V_37 * V_38 ;
T_3 V_144 ;
int V_36 , V_44 = 0 ;
V_36 = ( V_141 -> V_131 . V_132 & 0x40 ) ? 2 : 1 ;
V_38 = V_37 ( V_32 ) ;
V_143 = & V_38 -> V_41 . V_42 . V_145 [ V_33 ] . V_146 [ V_36 ] ;
V_144 = ( F_40 ( V_141 -> V_129 ) >> 16 ) & 0xff ;
V_44 = F_44 ( V_32 , V_141 , V_33 , V_36 ) ;
if ( V_44 )
goto V_60;
if ( V_147 != V_143 -> V_2 . V_148 ) {
if ( F_45 ( V_32 , V_140 ) )
return 0 ;
if ( V_144 == V_130 ||
( V_144 == V_149 && F_41 ( V_32 , V_36 ) ) ) {
if ( V_32 -> V_63 . V_150 & V_151 ) {
* ( V_127 * ) V_117 -> V_119 =
F_46 ( F_40 ( * ( V_127 * ) V_117 -> V_119 ) |
V_152 ) ;
V_141 -> V_153 &= ~ F_46 ( V_154 ) ;
} else {
struct V_155 V_156 = { . V_129 = 0 } ;
V_44 = F_47 ( V_32 , V_140 , V_157 , & V_156 ) ;
if ( V_44 )
goto V_60;
}
}
V_141 -> V_131 . V_158 &=
V_159 ;
if ( V_143 -> V_2 . V_160 == V_161 &&
V_32 -> V_63 . V_162 & V_163 ) {
V_141 -> V_131 . V_158 |=
V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 ;
} else if ( 0 != V_143 -> V_2 . V_148 ) {
if ( V_143 -> V_2 . V_170 == F_48 ( V_171 ) ) {
V_141 -> V_131 . V_158 |=
V_165 |
V_164 |
V_167 |
V_168 ;
} else {
V_141 -> V_131 . V_158 |=
V_164 |
V_167 |
V_168 ;
}
} else {
V_141 -> V_131 . V_158 |=
V_164 |
V_169 ;
}
V_141 -> V_131 . V_172 |= V_173 ;
V_141 -> V_131 . V_174 = V_143 -> V_175 ;
V_141 -> V_131 . V_176 |= V_177 ;
if ( V_143 -> V_2 . V_170 == F_48 ( V_171 ) )
V_141 -> V_131 . V_176 |= V_178 ;
else
V_141 -> V_131 . V_176 |= V_179 ;
V_141 -> V_131 . V_180 |= V_181 | V_182 ;
V_141 -> V_131 . V_132 &= 0xC7 ;
V_141 -> V_131 . V_132 |= ( V_143 -> V_2 . V_183 ) << 3 ;
V_141 -> V_184 = V_143 -> V_2 . V_184 ;
}
if ( V_143 -> V_2 . V_185 ) {
V_141 -> V_131 . V_180 |= V_186 ;
V_141 -> V_131 . V_187 = ( 0x80 & V_141 -> V_131 . V_187 ) + V_143 -> V_188 ;
}
V_60:
return V_44 ;
}
static int F_49 ( struct V_31 * V_32 )
{
return V_32 -> V_63 . V_79 - 1 ;
}
static const char * F_50 ( enum V_18 V_86 )
{
switch ( V_86 ) {
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
return F_2 ( & V_38 -> V_41 . V_42 . V_43 . V_95 [ type ] ,
V_7 ) ;
}
static int F_52 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type ,
void * V_11 , const char * V_189 )
{
struct V_10 * V_190 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_51 ( V_32 , V_7 , type ) ;
if ( ! V_190 ) {
V_44 = - V_191 ;
goto exit;
}
if ( V_190 -> V_2 == V_192 ) {
F_10 ( V_32 ,
L_31 ,
V_189 , V_33 , V_7 , F_50 ( type ) ,
V_190 -> V_189 ) ;
V_44 = - V_193 ;
goto exit;
}
if ( V_190 -> V_194 != V_33 ) {
V_44 = - V_195 ;
goto exit;
}
V_190 -> V_196 = V_190 -> V_2 ;
V_190 -> V_2 = V_192 ;
V_190 -> V_189 = V_189 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_190 ;
exit:
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
int F_56 ( struct V_31 * V_32 ,
enum V_18 type ,
T_1 V_7 , int * V_33 )
{
struct V_10 * V_190 ;
int V_44 = - V_197 ;
int V_198 = V_7 ;
if ( type == V_20 )
V_198 &= 0x7fffff ;
F_9 ( F_54 ( V_32 ) ) ;
V_190 = F_51 ( V_32 , V_198 , type ) ;
if ( V_190 ) {
* V_33 = V_190 -> V_194 ;
V_44 = 0 ;
}
F_11 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static void F_57 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_190 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_51 ( V_32 , V_7 , type ) ;
if ( V_190 ) {
V_190 -> V_2 = V_190 -> V_196 ;
V_190 -> V_189 = L_32 ;
}
F_55 ( F_54 ( V_32 ) ) ;
}
static int F_58 ( struct V_31 * V_32 , T_2 V_33 , int V_36 ,
int V_199 )
{
struct V_10 * V_190 ;
struct V_200 * V_201 ;
int V_202 = 0 ;
if ( V_199 == F_59 ( V_32 ) )
return V_202 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_51 ( V_32 , V_199 , V_28 ) ;
if ( ! V_190 || V_190 -> V_194 != V_33 ) {
V_202 = - V_53 ;
} else {
V_201 = F_60 ( V_190 , struct V_200 , V_203 ) ;
if ( ! V_201 -> V_36 )
V_201 -> V_36 = V_36 ;
}
F_55 ( F_54 ( V_32 ) ) ;
return V_202 ;
}
static int F_61 ( struct V_31 * V_32 ,
struct V_123 * V_141 , T_2 V_33 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_206 ;
struct V_200 * V_201 ;
T_1 V_207 = F_59 ( V_32 ) ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
F_62 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_201 = F_60 ( V_206 , struct V_200 , V_203 ) ;
if ( V_36 == V_201 -> V_36 ) {
V_141 -> V_131 . V_199 = V_201 -> V_203 . V_7 ;
F_55 ( F_54 ( V_32 ) ) ;
return 0 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
V_44 = F_63 ( V_32 , V_33 , V_208 , 0 , 0 , & V_207 ,
V_36 ) ;
if ( V_44 == - V_197 ) {
V_44 = 0 ;
} else if ( V_44 && V_44 != - V_209 ) {
F_64 ( V_32 , L_33 ,
V_210 , V_33 , V_44 ) ;
} else {
V_141 -> V_131 . V_199 = V_207 ;
F_24 ( V_32 , L_34 ,
V_210 , V_33 , V_141 -> V_131 . V_199 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_44 ( struct V_31 * V_32 , struct V_123 * V_141 ,
T_2 V_33 , int V_36 )
{
if ( V_141 -> V_131 . V_199 != F_59 ( V_32 ) )
return F_58 ( V_32 , V_33 , V_36 ,
V_141 -> V_131 . V_199 ) ;
return F_61 ( V_32 , V_141 , V_33 , V_36 ) ;
}
static struct V_10 * F_65 ( int V_198 )
{
struct V_211 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_212 ;
V_202 -> V_213 = V_198 ;
F_22 ( & V_202 -> V_214 ) ;
F_26 ( & V_202 -> V_215 ) ;
F_66 ( & V_202 -> V_216 , 0 ) ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_67 ( int V_198 , int V_217 )
{
struct V_218 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_217 = V_217 ;
V_202 -> V_203 . V_2 = V_4 ;
F_66 ( & V_202 -> V_216 , 0 ) ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_68 ( int V_198 , int V_219 )
{
struct V_220 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_221 ;
V_202 -> V_219 = V_219 ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_69 ( int V_198 )
{
struct V_222 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_223 ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_70 ( int V_198 )
{
struct V_224 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_225 ;
F_66 ( & V_202 -> V_216 , 0 ) ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_71 ( int V_198 )
{
struct V_226 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_227 ;
F_66 ( & V_202 -> V_216 , 0 ) ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_72 ( int V_198 , int V_36 )
{
struct V_200 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_228 ;
V_202 -> V_36 = V_36 ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_73 ( int V_198 )
{
struct V_229 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_230 ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_74 ( T_1 V_198 , int V_140 )
{
struct V_231 * V_202 ;
V_202 = F_21 ( sizeof *V_202 , V_90 ) ;
if ( ! V_202 )
return NULL ;
V_202 -> V_203 . V_7 = V_198 ;
V_202 -> V_203 . V_2 = V_232 ;
V_202 -> V_140 = V_140 ;
return & V_202 -> V_203 ;
}
static struct V_10 * F_75 ( T_1 V_198 , enum V_18 type , int V_33 ,
int V_233 )
{
struct V_10 * V_202 ;
switch ( type ) {
case V_20 :
V_202 = F_65 ( V_198 ) ;
break;
case V_23 :
V_202 = F_68 ( V_198 , V_233 ) ;
break;
case V_24 :
V_202 = F_67 ( V_198 , V_233 ) ;
break;
case V_27 :
V_202 = F_69 ( V_198 ) ;
break;
case V_21 :
V_202 = F_70 ( V_198 ) ;
break;
case V_22 :
V_202 = F_71 ( V_198 ) ;
break;
case V_25 :
F_76 ( L_35 ) ;
return NULL ;
case V_28 :
V_202 = F_72 ( V_198 , V_233 ) ;
break;
case V_30 :
V_202 = F_73 ( V_198 ) ;
break;
case V_29 :
V_202 = F_74 ( V_198 , V_233 ) ;
break;
default:
return NULL ;
}
if ( V_202 )
V_202 -> V_194 = V_33 ;
return V_202 ;
}
int F_77 ( struct V_31 * V_32 , int V_33 , int V_36 ,
struct V_234 * V_235 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_206 ;
struct V_200 * V_201 ;
int * V_236 ;
int V_84 = 0 , V_44 = 0 ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
V_236 = F_78 ( V_32 -> V_63 . V_81 ,
sizeof( * V_236 ) , V_90 ) ;
if ( ! V_236 )
return - V_91 ;
F_53 ( F_54 ( V_32 ) ) ;
F_62 (tmp,
&tracker->slave_list[slave].res_list[RES_COUNTER],
list) {
V_201 = F_60 ( V_206 , struct V_200 , V_203 ) ;
if ( V_201 -> V_36 == V_36 ) {
V_236 [ V_84 ] = ( int ) V_206 -> V_7 ;
V_84 ++ ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
V_236 [ V_84 ] = - 1 ;
V_84 = 0 ;
while ( V_236 [ V_84 ] != - 1 ) {
V_44 = F_79 ( V_32 , V_236 [ V_84 ] , V_235 ,
0 ) ;
if ( V_44 ) {
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
goto V_237;
}
V_84 ++ ;
}
V_237:
F_31 ( V_236 ) ;
return 0 ;
}
static int F_80 ( struct V_31 * V_32 , int V_33 , T_1 V_238 , int V_35 ,
enum V_18 type , int V_233 )
{
int V_84 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_10 * * V_239 ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_205 -> V_95 [ type ] ;
V_239 = F_21 ( V_35 * sizeof *V_239 , V_90 ) ;
if ( ! V_239 )
return - V_91 ;
for ( V_84 = 0 ; V_84 < V_35 ; ++ V_84 ) {
V_239 [ V_84 ] = F_75 ( V_238 + V_84 , type , V_33 , V_233 ) ;
if ( ! V_239 [ V_84 ] ) {
for ( -- V_84 ; V_84 >= 0 ; -- V_84 )
F_31 ( V_239 [ V_84 ] ) ;
F_31 ( V_239 ) ;
return - V_91 ;
}
}
F_53 ( F_54 ( V_32 ) ) ;
for ( V_84 = 0 ; V_84 < V_35 ; ++ V_84 ) {
if ( F_51 ( V_32 , V_238 + V_84 , type ) ) {
V_44 = - V_17 ;
goto V_240;
}
V_44 = F_4 ( V_6 , V_239 [ V_84 ] ) ;
if ( V_44 )
goto V_240;
F_81 ( & V_239 [ V_84 ] -> V_241 ,
& V_205 -> V_88 [ V_33 ] . V_93 [ type ] ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
F_31 ( V_239 ) ;
return 0 ;
V_240:
for ( -- V_84 ; V_84 >= 0 ; -- V_84 ) {
F_82 ( & V_239 [ V_84 ] -> V_9 , V_6 ) ;
F_83 ( & V_239 [ V_84 ] -> V_241 ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
for ( V_84 = 0 ; V_84 < V_35 ; ++ V_84 )
F_31 ( V_239 [ V_84 ] ) ;
F_31 ( V_239 ) ;
return V_44 ;
}
static int F_84 ( struct V_211 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_242 || F_85 ( & V_11 -> V_216 ) ||
! F_86 ( & V_11 -> V_214 ) ) {
F_76 ( L_36 ,
V_11 -> V_203 . V_2 , F_85 ( & V_11 -> V_216 ) ) ;
return - V_193 ;
} else if ( V_11 -> V_203 . V_2 != V_212 ) {
return - V_195 ;
}
return 0 ;
}
static int F_87 ( struct V_218 * V_11 , int V_217 )
{
if ( V_11 -> V_203 . V_2 == V_3 ||
F_85 ( & V_11 -> V_216 ) ) {
F_88 ( L_37 ,
V_210 , __LINE__ ,
F_1 ( V_11 -> V_203 . V_2 ) ,
F_85 ( & V_11 -> V_216 ) ) ;
return - V_193 ;
} else if ( V_11 -> V_203 . V_2 != V_4 )
return - V_195 ;
else if ( V_11 -> V_217 != V_217 )
return - V_53 ;
return 0 ;
}
static int F_89 ( struct V_220 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_243 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_221 )
return - V_195 ;
return 0 ;
}
static int F_90 ( struct V_222 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_243 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_221 )
return - V_195 ;
return 0 ;
}
static int F_91 ( struct V_200 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_244 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_228 )
return - V_195 ;
return 0 ;
}
static int F_92 ( struct V_229 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_245 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_230 )
return - V_195 ;
return 0 ;
}
static int F_93 ( struct V_231 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_246 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_232 )
return - V_195 ;
return 0 ;
}
static int F_94 ( struct V_224 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_247 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_225 )
return - V_195 ;
return 0 ;
}
static int F_95 ( struct V_226 * V_11 )
{
if ( V_11 -> V_203 . V_2 == V_248 )
return - V_193 ;
else if ( V_11 -> V_203 . V_2 != V_227 )
return - V_195 ;
return 0 ;
}
static int F_96 ( struct V_10 * V_11 , enum V_18 type , int V_233 )
{
switch ( type ) {
case V_20 :
return F_84 ( (struct V_211 * ) V_11 ) ;
case V_21 :
return F_94 ( (struct V_224 * ) V_11 ) ;
case V_22 :
return F_95 ( (struct V_226 * ) V_11 ) ;
case V_23 :
return F_89 ( (struct V_220 * ) V_11 ) ;
case V_24 :
return F_87 ( (struct V_218 * ) V_11 , V_233 ) ;
case V_25 :
return - V_249 ;
case V_27 :
return F_90 ( (struct V_222 * ) V_11 ) ;
case V_28 :
return F_91 ( (struct V_200 * ) V_11 ) ;
case V_30 :
return F_92 ( (struct V_229 * ) V_11 ) ;
case V_29 :
return F_93 ( (struct V_231 * ) V_11 ) ;
default:
return - V_53 ;
}
}
static int F_97 ( struct V_31 * V_32 , int V_33 , T_1 V_238 , int V_35 ,
enum V_18 type , int V_233 )
{
T_1 V_84 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_190 ;
F_53 ( F_54 ( V_32 ) ) ;
for ( V_84 = V_238 ; V_84 < V_238 + V_35 ; ++ V_84 ) {
V_190 = F_2 ( & V_205 -> V_95 [ type ] , V_84 ) ;
if ( ! V_190 ) {
V_44 = - V_197 ;
goto V_60;
}
if ( V_190 -> V_194 != V_33 ) {
V_44 = - V_195 ;
goto V_60;
}
V_44 = F_96 ( V_190 , type , V_233 ) ;
if ( V_44 )
goto V_60;
}
for ( V_84 = V_238 ; V_84 < V_238 + V_35 ; ++ V_84 ) {
V_190 = F_2 ( & V_205 -> V_95 [ type ] , V_84 ) ;
F_82 ( & V_190 -> V_9 , & V_205 -> V_95 [ type ] ) ;
F_98 ( & V_190 -> V_241 ) ;
F_31 ( V_190 ) ;
}
V_44 = 0 ;
V_60:
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_99 ( struct V_31 * V_32 , int V_33 , int V_140 ,
enum V_250 V_2 , struct V_211 * * V_67 ,
int V_251 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_211 * V_190 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ V_20 ] , V_140 ) ;
if ( ! V_190 )
V_44 = - V_197 ;
else if ( V_190 -> V_203 . V_194 != V_33 )
V_44 = - V_195 ;
else {
switch ( V_2 ) {
case V_242 :
F_24 ( V_32 , L_38 ,
V_210 , V_190 -> V_203 . V_7 ) ;
V_44 = - V_193 ;
break;
case V_212 :
if ( V_190 -> V_203 . V_2 == V_252 && ! V_251 )
break;
F_24 ( V_32 , L_39 , V_190 -> V_203 . V_7 ) ;
V_44 = - V_53 ;
break;
case V_252 :
if ( ( V_190 -> V_203 . V_2 == V_212 && V_251 ) ||
V_190 -> V_203 . V_2 == V_253 )
break;
else {
F_24 ( V_32 , L_39 ,
V_190 -> V_203 . V_7 ) ;
V_44 = - V_53 ;
}
break;
case V_253 :
if ( V_190 -> V_203 . V_2 != V_252 )
V_44 = - V_53 ;
break;
default:
V_44 = - V_53 ;
}
if ( ! V_44 ) {
V_190 -> V_203 . V_196 = V_190 -> V_203 . V_2 ;
V_190 -> V_203 . V_254 = V_2 ;
V_190 -> V_203 . V_2 = V_242 ;
if ( V_67 )
* V_67 = V_190 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_100 ( struct V_31 * V_32 , int V_33 , int V_255 ,
enum V_256 V_2 , struct V_220 * * V_78 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_220 * V_190 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ V_23 ] , V_255 ) ;
if ( ! V_190 )
V_44 = - V_197 ;
else if ( V_190 -> V_203 . V_194 != V_33 )
V_44 = - V_195 ;
else {
switch ( V_2 ) {
case V_243 :
V_44 = - V_53 ;
break;
case V_221 :
if ( V_190 -> V_203 . V_2 != V_257 )
V_44 = - V_53 ;
break;
case V_257 :
if ( V_190 -> V_203 . V_2 != V_221 &&
V_190 -> V_203 . V_2 != V_258 )
V_44 = - V_53 ;
break;
case V_258 :
if ( V_190 -> V_203 . V_2 != V_257 )
V_44 = - V_53 ;
break;
default:
V_44 = - V_53 ;
}
if ( ! V_44 ) {
V_190 -> V_203 . V_196 = V_190 -> V_203 . V_2 ;
V_190 -> V_203 . V_254 = V_2 ;
V_190 -> V_203 . V_2 = V_243 ;
if ( V_78 )
* V_78 = V_190 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_101 ( struct V_31 * V_32 , int V_33 , int V_255 ,
enum V_259 V_2 , struct V_222 * * V_260 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_222 * V_190 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ V_27 ] , V_255 ) ;
if ( ! V_190 )
V_44 = - V_197 ;
else if ( V_190 -> V_203 . V_194 != V_33 )
V_44 = - V_195 ;
else {
switch ( V_2 ) {
case V_261 :
V_44 = - V_53 ;
break;
case V_223 :
if ( V_190 -> V_203 . V_2 != V_262 )
V_44 = - V_53 ;
break;
case V_262 :
if ( V_190 -> V_203 . V_2 != V_223 )
V_44 = - V_53 ;
break;
default:
V_44 = - V_53 ;
}
if ( ! V_44 ) {
V_190 -> V_203 . V_196 = V_190 -> V_203 . V_2 ;
V_190 -> V_203 . V_254 = V_2 ;
V_190 -> V_203 . V_2 = V_261 ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
if ( ! V_44 && V_260 )
* V_260 = V_190 ;
return V_44 ;
}
static int F_102 ( struct V_31 * V_32 , int V_33 , int V_263 ,
enum V_264 V_2 , struct V_224 * * V_70 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_224 * V_190 ;
int V_44 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ V_21 ] , V_263 ) ;
if ( ! V_190 ) {
V_44 = - V_197 ;
} else if ( V_190 -> V_203 . V_194 != V_33 ) {
V_44 = - V_195 ;
} else if ( V_2 == V_225 ) {
if ( V_190 -> V_203 . V_2 != V_265 )
V_44 = - V_53 ;
else if ( F_85 ( & V_190 -> V_216 ) )
V_44 = - V_193 ;
else
V_44 = 0 ;
} else if ( V_2 != V_265 || V_190 -> V_203 . V_2 != V_225 ) {
V_44 = - V_53 ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
V_190 -> V_203 . V_196 = V_190 -> V_203 . V_2 ;
V_190 -> V_203 . V_254 = V_2 ;
V_190 -> V_203 . V_2 = V_247 ;
if ( V_70 )
* V_70 = V_190 ;
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_103 ( struct V_31 * V_32 , int V_33 , int V_255 ,
enum V_266 V_2 , struct V_226 * * V_73 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_226 * V_190 ;
int V_44 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ V_22 ] , V_255 ) ;
if ( ! V_190 ) {
V_44 = - V_197 ;
} else if ( V_190 -> V_203 . V_194 != V_33 ) {
V_44 = - V_195 ;
} else if ( V_2 == V_227 ) {
if ( V_190 -> V_203 . V_2 != V_267 )
V_44 = - V_53 ;
else if ( F_85 ( & V_190 -> V_216 ) )
V_44 = - V_193 ;
} else if ( V_2 != V_267 || V_190 -> V_203 . V_2 != V_227 ) {
V_44 = - V_53 ;
}
if ( ! V_44 ) {
V_190 -> V_203 . V_196 = V_190 -> V_203 . V_2 ;
V_190 -> V_203 . V_254 = V_2 ;
V_190 -> V_203 . V_2 = V_248 ;
if ( V_73 )
* V_73 = V_190 ;
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static void F_104 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_198 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_190 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ type ] , V_198 ) ;
if ( V_190 && ( V_190 -> V_194 == V_33 ) )
V_190 -> V_2 = V_190 -> V_196 ;
F_55 ( F_54 ( V_32 ) ) ;
}
static void F_105 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_198 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_190 ;
F_53 ( F_54 ( V_32 ) ) ;
V_190 = F_2 ( & V_205 -> V_95 [ type ] , V_198 ) ;
if ( V_190 && ( V_190 -> V_194 == V_33 ) )
V_190 -> V_2 = V_190 -> V_254 ;
F_55 ( F_54 ( V_32 ) ) ;
}
static int F_106 ( struct V_31 * V_32 , int V_33 , int V_140 )
{
return F_45 ( V_32 , V_140 ) &&
( F_107 ( V_32 ) || F_108 ( V_32 , V_33 , V_140 ) ) ;
}
static int F_109 ( struct V_31 * V_32 , int V_140 )
{
return V_140 < V_32 -> V_63 . V_268 [ V_269 ] ;
}
static int F_110 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_44 ;
int V_35 ;
int V_274 ;
int V_238 ;
int V_140 ;
T_2 V_129 ;
switch ( V_270 ) {
case V_208 :
V_35 = F_111 ( & V_272 ) & 0xffffff ;
V_129 = ( F_111 ( & V_272 ) >> 24 ) & V_32 -> V_63 . V_275 ;
V_274 = F_112 ( & V_272 ) ;
V_44 = F_8 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_113 ( V_32 , V_35 , V_274 , & V_238 , V_129 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
return V_44 ;
}
V_44 = F_80 ( V_32 , V_33 , V_238 , V_35 , V_20 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_114 ( V_32 , V_238 , V_35 ) ;
return V_44 ;
}
F_115 ( V_273 , V_238 ) ;
break;
case V_276 :
V_140 = F_111 ( & V_272 ) & 0x7fffff ;
if ( F_106 ( V_32 , V_33 , V_140 ) ) {
V_44 = F_80 ( V_32 , V_33 , V_140 , 1 , V_20 , 0 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_99 ( V_32 , V_33 , V_140 , V_252 ,
NULL , 1 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_109 ( V_32 , V_140 ) ) {
V_44 = F_116 ( V_32 , V_140 ) ;
if ( V_44 ) {
F_104 ( V_32 , V_33 , V_20 , V_140 ) ;
return V_44 ;
}
}
F_105 ( V_32 , V_33 , V_20 , V_140 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_117 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_44 = - V_53 ;
int V_238 ;
int V_217 ;
if ( V_270 != V_277 )
return V_44 ;
V_217 = F_111 ( & V_272 ) ;
V_44 = F_8 ( V_32 , V_33 , V_24 , 1 << V_217 , 0 ) ;
if ( V_44 )
return V_44 ;
V_238 = F_118 ( V_32 , V_217 ) ;
if ( V_238 == - 1 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_217 , 0 ) ;
return - V_91 ;
}
V_44 = F_80 ( V_32 , V_33 , V_238 , 1 , V_24 , V_217 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_217 , 0 ) ;
F_119 ( V_32 , V_238 , V_217 ) ;
} else {
F_115 ( V_273 , V_238 ) ;
}
return V_44 ;
}
static int F_120 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_44 = - V_53 ;
int V_255 ;
int V_198 ;
struct V_220 * V_78 ;
switch ( V_270 ) {
case V_208 :
V_44 = F_8 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
if ( V_44 )
break;
V_255 = F_121 ( V_32 ) ;
if ( V_255 == - 1 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
break;
}
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_80 ( V_32 , V_33 , V_198 , 1 , V_23 , V_255 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_122 ( V_32 , V_255 ) ;
break;
}
F_115 ( V_273 , V_255 ) ;
break;
case V_276 :
V_255 = F_111 ( & V_272 ) ;
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_198 ,
V_257 , & V_78 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_123 ( V_32 , V_78 -> V_219 ) ;
if ( V_44 ) {
F_104 ( V_32 , V_33 , V_23 , V_198 ) ;
return V_44 ;
}
F_105 ( V_32 , V_33 , V_23 , V_198 ) ;
break;
}
return V_44 ;
}
static int F_124 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_263 ;
int V_44 ;
switch ( V_270 ) {
case V_277 :
V_44 = F_8 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_125 ( V_32 , & V_263 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
break;
}
V_44 = F_80 ( V_32 , V_33 , V_263 , 1 , V_21 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_126 ( V_32 , V_263 ) ;
break;
}
F_115 ( V_273 , V_263 ) ;
break;
default:
V_44 = - V_53 ;
}
return V_44 ;
}
static int F_127 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_278 ;
int V_44 ;
switch ( V_270 ) {
case V_277 :
V_44 = F_8 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_128 ( V_32 , & V_278 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
break;
}
V_44 = F_80 ( V_32 , V_33 , V_278 , 1 , V_22 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_129 ( V_32 , V_278 ) ;
break;
}
F_115 ( V_273 , V_278 ) ;
break;
default:
V_44 = - V_53 ;
}
return V_44 ;
}
static int F_130 ( struct V_31 * V_32 , int V_33 , int V_36 ,
T_2 V_279 , T_1 * V_280 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_282 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_25 ] ;
struct V_283 * V_11 , * V_206 ;
F_131 (res, tmp, mac_list, list) {
if ( V_11 -> V_279 == V_279 && V_11 -> V_36 == ( T_2 ) V_36 ) {
* V_280 = V_11 -> V_280 ;
return 0 ;
}
}
return - V_197 ;
}
static int F_132 ( struct V_31 * V_32 , int V_33 , T_1 V_280 , int V_36 , T_2 V_279 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_282 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_25 ] ;
struct V_283 * V_11 , * V_206 ;
F_131 (res, tmp, mac_list, list) {
if ( V_11 -> V_280 == V_280 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_216 ;
return 0 ;
}
}
if ( F_8 ( V_32 , V_33 , V_25 , 1 , V_36 ) )
return - V_53 ;
V_11 = F_21 ( sizeof *V_11 , V_90 ) ;
if ( ! V_11 ) {
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
return - V_91 ;
}
V_11 -> V_280 = V_280 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_279 = V_279 ;
V_11 -> V_216 = 1 ;
F_81 ( & V_11 -> V_241 ,
& V_205 -> V_88 [ V_33 ] . V_93 [ V_25 ] ) ;
return 0 ;
}
static void F_133 ( struct V_31 * V_32 , int V_33 , T_1 V_280 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_282 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_25 ] ;
struct V_283 * V_11 , * V_206 ;
F_131 (res, tmp, mac_list, list) {
if ( V_11 -> V_280 == V_280 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_216 ) {
F_98 ( & V_11 -> V_241 ) ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_282 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_25 ] ;
struct V_283 * V_11 , * V_206 ;
int V_84 ;
F_131 (res, tmp, mac_list, list) {
F_98 ( & V_11 -> V_241 ) ;
for ( V_84 = 0 ; V_84 < V_11 -> V_216 ; V_84 ++ )
F_135 ( V_32 , V_11 -> V_36 , V_11 -> V_280 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_136 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 , int V_284 )
{
int V_44 = - V_53 ;
int V_36 ;
T_1 V_280 ;
T_2 V_279 ;
if ( V_270 != V_277 )
return V_44 ;
V_36 = ! V_284 ? F_111 ( V_273 ) : V_284 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_53 ;
V_280 = V_272 ;
V_44 = F_138 ( V_32 , V_36 , V_280 ) ;
if ( V_44 >= 0 ) {
V_279 = V_44 ;
F_115 ( V_273 , V_44 ) ;
V_44 = 0 ;
}
if ( ! V_44 ) {
V_44 = F_132 ( V_32 , V_33 , V_280 , V_36 , V_279 ) ;
if ( V_44 )
F_135 ( V_32 , V_36 , V_280 ) ;
}
return V_44 ;
}
static int F_139 ( struct V_31 * V_32 , int V_33 , T_4 V_285 ,
int V_36 , int V_174 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_286 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_26 ] ;
struct V_287 * V_11 , * V_206 ;
F_131 (res, tmp, vlan_list, list) {
if ( V_11 -> V_285 == V_285 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_216 ;
return 0 ;
}
}
if ( F_8 ( V_32 , V_33 , V_26 , 1 , V_36 ) )
return - V_53 ;
V_11 = F_21 ( sizeof( * V_11 ) , V_90 ) ;
if ( ! V_11 ) {
F_12 ( V_32 , V_33 , V_26 , 1 , V_36 ) ;
return - V_91 ;
}
V_11 -> V_285 = V_285 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_174 = V_174 ;
V_11 -> V_216 = 1 ;
F_81 ( & V_11 -> V_241 ,
& V_205 -> V_88 [ V_33 ] . V_93 [ V_26 ] ) ;
return 0 ;
}
static void F_140 ( struct V_31 * V_32 , int V_33 , T_4 V_285 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_286 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_26 ] ;
struct V_287 * V_11 , * V_206 ;
F_131 (res, tmp, vlan_list, list) {
if ( V_11 -> V_285 == V_285 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_216 ) {
F_98 ( & V_11 -> V_241 ) ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_286 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_26 ] ;
struct V_287 * V_11 , * V_206 ;
int V_84 ;
F_131 (res, tmp, vlan_list, list) {
F_98 ( & V_11 -> V_241 ) ;
for ( V_84 = 0 ; V_84 < V_11 -> V_216 ; V_84 ++ )
F_141 ( V_32 , V_11 -> V_36 , V_11 -> V_285 ) ;
F_12 ( V_32 , V_33 , V_26 , 1 , V_11 -> V_36 ) ;
F_31 ( V_11 ) ;
}
}
static int F_142 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 , int V_284 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_288 * V_289 = V_38 -> V_41 . V_42 . V_289 ;
int V_44 ;
T_4 V_285 ;
int V_174 ;
int V_36 ;
V_36 = ! V_284 ? F_111 ( V_273 ) : V_284 ;
if ( ! V_36 || V_270 != V_277 )
return - V_53 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_53 ;
if ( ! V_284 && V_36 > 0 && V_36 <= V_32 -> V_63 . V_101 ) {
V_289 [ V_33 ] . V_290 = true ;
return 0 ;
}
V_285 = ( T_4 ) V_272 ;
V_44 = F_143 ( V_32 , V_36 , V_285 , & V_174 ) ;
if ( ! V_44 ) {
F_115 ( V_273 , ( T_3 ) V_174 ) ;
V_44 = F_139 ( V_32 , V_33 , V_285 , V_36 , V_174 ) ;
if ( V_44 )
F_141 ( V_32 , V_36 , V_285 ) ;
}
return V_44 ;
}
static int F_63 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 , int V_36 )
{
T_3 V_255 ;
int V_44 ;
if ( V_270 != V_208 )
return - V_53 ;
V_44 = F_8 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_144 ( V_32 , & V_255 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
V_44 = F_80 ( V_32 , V_33 , V_255 , 1 , V_28 , V_36 ) ;
if ( V_44 ) {
F_145 ( V_32 , V_255 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
} else {
F_115 ( V_273 , V_255 ) ;
}
return V_44 ;
}
static int F_146 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
T_3 V_291 ;
int V_44 ;
if ( V_270 != V_208 )
return - V_53 ;
V_44 = F_147 ( V_32 , & V_291 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_80 ( V_32 , V_33 , V_291 , 1 , V_30 , 0 ) ;
if ( V_44 )
F_148 ( V_32 , V_291 ) ;
else
F_115 ( V_273 , V_291 ) ;
return V_44 ;
}
int F_149 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_296 = V_293 -> V_297 ;
switch ( V_293 -> V_298 & 0xFF ) {
case V_20 :
V_44 = F_110 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_24 :
V_44 = F_117 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_23 :
V_44 = F_120 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_21 :
V_44 = F_124 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_22 :
V_44 = F_127 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_25 :
V_44 = F_136 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ,
( V_293 -> V_298 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_142 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ,
( V_293 -> V_298 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_63 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 , 0 ) ;
break;
case V_30 :
V_44 = F_146 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_150 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 )
{
int V_44 ;
int V_35 ;
int V_238 ;
int V_140 ;
switch ( V_270 ) {
case V_208 :
V_238 = F_111 ( & V_272 ) & 0x7fffff ;
V_35 = F_112 ( & V_272 ) ;
V_44 = F_97 ( V_32 , V_33 , V_238 , V_35 , V_20 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_114 ( V_32 , V_238 , V_35 ) ;
break;
case V_276 :
V_140 = F_111 ( & V_272 ) & 0x7fffff ;
V_44 = F_99 ( V_32 , V_33 , V_140 , V_212 ,
NULL , 0 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_109 ( V_32 , V_140 ) )
F_151 ( V_32 , V_140 ) ;
F_105 ( V_32 , V_33 , V_20 , V_140 ) ;
if ( F_106 ( V_32 , V_33 , V_140 ) )
V_44 = F_97 ( V_32 , V_33 , V_140 , 1 , V_20 , 0 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_152 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_44 = - V_53 ;
int V_238 ;
int V_217 ;
if ( V_270 != V_277 )
return V_44 ;
V_238 = F_111 ( & V_272 ) ;
V_217 = F_112 ( & V_272 ) ;
V_44 = F_97 ( V_32 , V_33 , V_238 , 1 , V_24 , V_217 ) ;
if ( ! V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_217 , 0 ) ;
F_119 ( V_32 , V_238 , V_217 ) ;
}
return V_44 ;
}
static int F_153 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 )
{
int V_44 = - V_53 ;
int V_255 ;
int V_198 ;
struct V_220 * V_78 ;
switch ( V_270 ) {
case V_208 :
V_255 = F_111 ( & V_272 ) ;
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_154 ( V_32 , V_33 , V_198 , V_23 , & V_78 ) ;
if ( V_44 )
break;
V_255 = V_78 -> V_219 ;
F_57 ( V_32 , V_33 , V_198 , V_23 ) ;
V_44 = F_97 ( V_32 , V_33 , V_198 , 1 , V_23 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_122 ( V_32 , V_255 ) ;
break;
case V_276 :
V_255 = F_111 ( & V_272 ) ;
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_198 ,
V_221 , & V_78 ) ;
if ( V_44 )
return V_44 ;
F_155 ( V_32 , V_78 -> V_219 ) ;
F_105 ( V_32 , V_33 , V_23 , V_198 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_156 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_263 ;
int V_44 ;
switch ( V_270 ) {
case V_277 :
V_263 = F_111 ( & V_272 ) ;
V_44 = F_97 ( V_32 , V_33 , V_263 , 1 , V_21 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_126 ( V_32 , V_263 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_157 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_278 ;
int V_44 ;
switch ( V_270 ) {
case V_277 :
V_278 = F_111 ( & V_272 ) ;
V_44 = F_97 ( V_32 , V_33 , V_278 , 1 , V_22 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_129 ( V_32 , V_278 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_158 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 , int V_284 )
{
int V_36 ;
int V_44 = 0 ;
switch ( V_270 ) {
case V_277 :
V_36 = ! V_284 ? F_111 ( V_273 ) : V_284 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_53 ;
F_133 ( V_32 , V_33 , V_272 , V_36 ) ;
F_135 ( V_32 , V_36 , V_272 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_159 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 , int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_288 * V_289 = V_38 -> V_41 . V_42 . V_289 ;
int V_44 = 0 ;
V_36 = F_137 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_53 ;
switch ( V_270 ) {
case V_277 :
if ( V_289 [ V_33 ] . V_290 )
return 0 ;
if ( ! V_36 )
return - V_53 ;
F_140 ( V_32 , V_33 , V_272 , V_36 ) ;
F_141 ( V_32 , V_36 , V_272 ) ;
break;
default:
V_44 = - V_53 ;
break;
}
return V_44 ;
}
static int F_160 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_255 ;
int V_44 ;
if ( V_270 != V_208 )
return - V_53 ;
V_255 = F_111 ( & V_272 ) ;
if ( V_255 == F_59 ( V_32 ) )
return 0 ;
V_44 = F_97 ( V_32 , V_33 , V_255 , 1 , V_28 , 0 ) ;
if ( V_44 )
return V_44 ;
F_145 ( V_32 , V_255 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
static int F_161 ( struct V_31 * V_32 , int V_33 , int V_270 , int V_271 ,
T_1 V_272 , T_1 * V_273 )
{
int V_291 ;
int V_44 ;
if ( V_270 != V_208 )
return - V_53 ;
V_291 = F_111 ( & V_272 ) ;
V_44 = F_97 ( V_32 , V_33 , V_291 , 1 , V_30 , 0 ) ;
if ( V_44 )
return V_44 ;
F_148 ( V_32 , V_291 ) ;
return V_44 ;
}
int F_162 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 = - V_53 ;
int V_296 = V_293 -> V_297 ;
switch ( V_293 -> V_298 & 0xFF ) {
case V_20 :
V_44 = F_150 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 ) ;
break;
case V_24 :
V_44 = F_152 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_23 :
V_44 = F_153 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 ) ;
break;
case V_21 :
V_44 = F_156 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_22 :
V_44 = F_157 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_25 :
V_44 = F_158 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ,
( V_293 -> V_298 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_159 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ,
( V_293 -> V_298 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_160 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
break;
case V_30 :
V_44 = F_161 ( V_32 , V_33 , V_293 -> V_297 , V_296 ,
V_293 -> V_272 , & V_293 -> V_273 ) ;
default:
break;
}
return V_44 ;
}
static int F_163 ( struct V_299 * V_78 )
{
return ( F_40 ( V_78 -> V_129 ) >> 9 ) & 1 ;
}
static int F_164 ( struct V_299 * V_78 )
{
return ( int ) F_165 ( V_78 -> V_300 ) & 0xfffffff8 ;
}
static int F_166 ( struct V_299 * V_78 )
{
return F_40 ( V_78 -> V_301 ) ;
}
static T_3 F_167 ( struct V_299 * V_78 )
{
return F_40 ( V_78 -> V_302 ) & 0x00ffffff ;
}
static int F_168 ( struct V_299 * V_78 )
{
return F_40 ( V_78 -> V_302 ) & V_303 ;
}
static int F_169 ( struct V_299 * V_78 )
{
return F_40 ( V_78 -> V_129 ) & V_304 ;
}
static int F_170 ( struct V_299 * V_78 )
{
return F_40 ( V_78 -> V_129 ) & V_305 ;
}
static int F_171 ( struct V_123 * V_141 )
{
return F_40 ( V_141 -> V_306 ) & 0xfffffff8 ;
}
static int F_172 ( struct V_307 * V_308 )
{
return F_40 ( V_308 -> V_306 ) & 0xfffffff8 ;
}
static int F_173 ( struct V_123 * V_141 )
{
int V_309 = ( V_141 -> V_310 & 0x3f ) + 12 ;
int V_311 = ( V_141 -> V_312 >> 3 ) & 0xf ;
int V_313 = V_141 -> V_312 & 7 ;
int V_314 = ( V_141 -> V_315 >> 3 ) & 0xf ;
int V_316 = V_141 -> V_315 & 7 ;
int V_73 = ( F_40 ( V_141 -> V_278 ) >> 24 ) & 1 ;
int V_317 = ( F_40 ( V_141 -> V_129 ) >> 13 ) & 1 ;
T_3 V_128 = ( F_40 ( V_141 -> V_129 ) >> 16 ) & 0xff ;
int V_318 = ( V_128 == V_135 ) ? 1 : 0 ;
int V_319 ;
int V_320 ;
int V_321 ;
int V_322 ;
int V_323 = ( F_40 ( V_141 -> V_324 ) >> 6 ) & 0x3f ;
V_319 = 1 << ( V_311 + V_313 + 4 ) ;
V_320 = ( V_73 | V_317 | V_318 ) ? 0 : ( 1 << ( V_314 + V_316 + 4 ) ) ;
V_322 = V_319 + V_320 ;
V_321 =
F_174 ( ( V_322 + ( V_323 << 6 ) ) >>
V_309 ) ;
return V_321 ;
}
static int F_175 ( struct V_31 * V_32 , int V_33 , int V_325 ,
int V_326 , struct V_218 * V_76 )
{
int V_327 = V_76 -> V_203 . V_7 ;
int V_328 = ( 1 << V_76 -> V_217 ) ;
if ( V_325 < V_327 || V_325 + V_326 > V_327 + V_328 )
return - V_195 ;
return 0 ;
}
int F_176 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_255 = V_293 -> V_298 ;
struct V_218 * V_76 ;
struct V_220 * V_78 = NULL ;
int V_329 = F_164 ( V_117 -> V_119 ) / V_32 -> V_63 . V_330 ;
int V_331 ;
int V_198 ;
T_3 V_332 ;
int V_333 ;
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_198 , V_258 , & V_78 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_170 ( V_117 -> V_119 ) ) {
V_44 = - V_195 ;
goto V_334;
}
V_332 = F_167 ( V_117 -> V_119 ) ;
V_333 = ( V_332 >> 17 ) & 0x7f ;
if ( V_333 != 0 && -- V_333 != V_33 ) {
V_44 = - V_195 ;
goto V_334;
}
if ( F_168 ( V_117 -> V_119 ) ) {
if ( F_169 ( V_117 -> V_119 ) ) {
V_44 = - V_195 ;
goto V_334;
}
if ( ! F_170 ( V_117 -> V_119 ) ) {
V_44 = - V_195 ;
goto V_334;
}
}
V_331 = F_163 ( V_117 -> V_119 ) ;
if ( ! V_331 ) {
V_44 = F_154 ( V_32 , V_33 , V_329 , V_24 , & V_76 ) ;
if ( V_44 )
goto V_334;
V_44 = F_175 ( V_32 , V_33 , V_329 ,
F_166 ( V_117 -> V_119 ) , V_76 ) ;
if ( V_44 )
goto V_335;
V_78 -> V_76 = V_76 ;
}
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_335;
if ( ! V_331 ) {
F_178 ( & V_76 -> V_216 ) ;
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
}
F_105 ( V_32 , V_33 , V_23 , V_198 ) ;
return 0 ;
V_335:
if ( ! V_331 )
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
V_334:
F_104 ( V_32 , V_33 , V_23 , V_198 ) ;
return V_44 ;
}
int F_179 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_255 = V_293 -> V_298 ;
struct V_220 * V_78 ;
int V_198 ;
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_100 ( V_32 , V_33 , V_198 , V_257 , & V_78 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_334;
if ( V_78 -> V_76 )
F_180 ( & V_78 -> V_76 -> V_216 ) ;
F_105 ( V_32 , V_33 , V_23 , V_198 ) ;
return 0 ;
V_334:
F_104 ( V_32 , V_33 , V_23 , V_198 ) ;
return V_44 ;
}
int F_181 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_255 = V_293 -> V_298 ;
struct V_220 * V_78 ;
int V_198 ;
V_198 = V_255 & F_49 ( V_32 ) ;
V_44 = F_154 ( V_32 , V_33 , V_198 , V_23 , & V_78 ) ;
if ( V_44 )
return V_44 ;
if ( V_78 -> V_203 . V_196 == V_257 ) {
struct V_299 * V_336 = F_182 (
& V_37 ( V_32 ) -> V_337 . V_338 ,
V_78 -> V_219 , NULL ) ;
if ( NULL == V_336 || NULL == V_294 -> V_119 ) {
V_44 = - V_53 ;
goto V_60;
}
memcpy ( V_294 -> V_119 , V_336 , sizeof( * V_336 ) ) ;
V_44 = 0 ;
} else if ( V_78 -> V_203 . V_196 == V_258 ) {
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
} else {
V_44 = - V_193 ;
goto V_60;
}
V_60:
F_57 ( V_32 , V_33 , V_198 , V_23 ) ;
return V_44 ;
}
static int F_183 ( struct V_123 * V_141 )
{
return F_40 ( V_141 -> V_339 ) & 0xffffff ;
}
static int F_184 ( struct V_123 * V_141 )
{
return F_40 ( V_141 -> V_340 ) & 0xffffff ;
}
static T_3 F_185 ( struct V_123 * V_141 )
{
return F_40 ( V_141 -> V_278 ) & 0x1ffffff ;
}
static void F_186 ( struct V_31 * V_32 , struct V_292 * V_293 ,
struct V_123 * V_341 )
{
T_3 V_140 = V_293 -> V_298 & 0xffffff ;
T_3 V_342 = 0 ;
if ( F_187 ( V_32 , V_140 , & V_342 ) )
return;
V_341 -> V_342 = F_46 ( V_342 ) ;
}
int F_188 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_140 = V_293 -> V_298 & 0x7fffff ;
struct V_218 * V_76 ;
struct V_211 * V_67 ;
struct V_123 * V_141 = V_117 -> V_119 + 8 ;
int V_329 = F_171 ( V_141 ) / V_32 -> V_63 . V_330 ;
int V_343 = F_173 ( V_141 ) ;
struct V_224 * V_344 ;
struct V_224 * V_345 ;
int V_346 = F_183 ( V_141 ) ;
int V_347 = F_184 ( V_141 ) ;
T_3 V_278 = F_185 ( V_141 ) & 0xffffff ;
int V_348 = ( F_185 ( V_141 ) >> 24 ) & 1 ;
struct V_226 * V_73 ;
int V_213 = F_40 ( V_141 -> V_213 ) & 0xffffff ;
V_44 = F_189 ( V_32 , V_33 , V_141 , V_117 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_99 ( V_32 , V_33 , V_140 , V_253 , & V_67 , 0 ) ;
if ( V_44 )
return V_44 ;
V_67 -> V_213 = V_213 ;
V_67 -> V_132 = 0 ;
V_67 -> V_153 = 0 ;
V_67 -> V_158 = 0 ;
V_67 -> V_172 = 0 ;
V_67 -> V_349 = 0 ;
V_67 -> V_174 = 0 ;
V_67 -> V_180 = 0 ;
V_67 -> V_350 = F_40 ( V_141 -> V_129 ) ;
V_44 = F_154 ( V_32 , V_33 , V_329 , V_24 , & V_76 ) ;
if ( V_44 )
goto V_334;
V_44 = F_175 ( V_32 , V_33 , V_329 , V_343 , V_76 ) ;
if ( V_44 )
goto V_351;
V_44 = F_154 ( V_32 , V_33 , V_346 , V_21 , & V_344 ) ;
if ( V_44 )
goto V_351;
if ( V_347 != V_346 ) {
V_44 = F_154 ( V_32 , V_33 , V_347 , V_21 , & V_345 ) ;
if ( V_44 )
goto V_352;
} else
V_345 = V_344 ;
if ( V_348 ) {
V_44 = F_154 ( V_32 , V_33 , V_278 , V_22 , & V_73 ) ;
if ( V_44 )
goto V_353;
}
F_186 ( V_32 , V_293 , V_141 ) ;
F_38 ( V_32 , V_33 , V_117 ) ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_354;
F_178 ( & V_76 -> V_216 ) ;
V_67 -> V_76 = V_76 ;
F_178 ( & V_344 -> V_216 ) ;
V_67 -> V_344 = V_344 ;
F_178 ( & V_345 -> V_216 ) ;
V_67 -> V_345 = V_345 ;
if ( V_347 != V_346 )
F_57 ( V_32 , V_33 , V_347 , V_21 ) ;
if ( V_348 ) {
F_178 ( & V_73 -> V_216 ) ;
F_57 ( V_32 , V_33 , V_278 , V_22 ) ;
V_67 -> V_73 = V_73 ;
}
V_67 -> V_153 = V_141 -> V_153 ;
F_57 ( V_32 , V_33 , V_346 , V_21 ) ;
F_57 ( V_32 , V_33 , V_329 , V_24 ) ;
F_105 ( V_32 , V_33 , V_20 , V_140 ) ;
return 0 ;
V_354:
if ( V_348 )
F_57 ( V_32 , V_33 , V_278 , V_22 ) ;
V_353:
if ( V_347 != V_346 )
F_57 ( V_32 , V_33 , V_347 , V_21 ) ;
V_352:
F_57 ( V_32 , V_33 , V_346 , V_21 ) ;
V_351:
F_57 ( V_32 , V_33 , V_329 , V_24 ) ;
V_334:
F_104 ( V_32 , V_33 , V_20 , V_140 ) ;
return V_44 ;
}
static int F_190 ( struct V_355 * V_356 )
{
return F_40 ( V_356 -> V_306 ) & 0xfffffff8 ;
}
static int F_191 ( struct V_355 * V_356 )
{
int V_357 = V_356 -> V_357 & 0x1f ;
int V_309 = ( V_356 -> V_310 & 0x3f ) + 12 ;
if ( V_357 + 5 < V_309 )
return 1 ;
return 1 << ( V_357 + 5 - V_309 ) ;
}
static int F_192 ( struct V_358 * V_359 )
{
return F_40 ( V_359 -> V_306 ) & 0xfffffff8 ;
}
static int F_193 ( struct V_358 * V_359 )
{
int V_360 = ( F_40 ( V_359 -> V_361 ) >> 24 ) & 0x1f ;
int V_309 = ( V_359 -> V_310 & 0x3f ) + 12 ;
if ( V_360 + 5 < V_309 )
return 1 ;
return 1 << ( V_360 + 5 - V_309 ) ;
}
int F_194 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_362 = V_293 -> V_298 ;
int V_7 = ( V_33 << 10 ) | V_362 ;
struct V_355 * V_356 = V_117 -> V_119 ;
int V_329 = F_190 ( V_356 ) / V_32 -> V_63 . V_330 ;
int V_343 = F_191 ( V_356 ) ;
struct V_222 * V_260 ;
struct V_218 * V_76 ;
V_44 = F_80 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_101 ( V_32 , V_33 , V_7 , V_262 , & V_260 ) ;
if ( V_44 )
goto V_363;
V_44 = F_154 ( V_32 , V_33 , V_329 , V_24 , & V_76 ) ;
if ( V_44 )
goto V_364;
V_44 = F_175 ( V_32 , V_33 , V_329 , V_343 , V_76 ) ;
if ( V_44 )
goto V_365;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_365;
F_178 ( & V_76 -> V_216 ) ;
V_260 -> V_76 = V_76 ;
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_27 , V_7 ) ;
return 0 ;
V_365:
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
V_364:
F_104 ( V_32 , V_33 , V_27 , V_7 ) ;
V_363:
F_97 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return V_44 ;
}
int F_195 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
T_2 V_366 = V_293 -> V_297 ;
if ( V_366 != 1 )
return - V_195 ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
return V_44 ;
}
static int F_196 ( struct V_31 * V_32 , int V_33 , int V_325 ,
int V_367 , struct V_218 * * V_11 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_218 * V_76 ;
int V_44 = - V_53 ;
F_53 ( F_54 ( V_32 ) ) ;
F_62 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_175 ( V_32 , V_33 , V_325 , V_367 , V_76 ) ) {
* V_11 = V_76 ;
V_76 -> V_203 . V_196 = V_76 -> V_203 . V_2 ;
V_76 -> V_203 . V_2 = V_3 ;
V_44 = 0 ;
break;
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_44 ;
}
static int F_197 ( struct V_31 * V_32 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
enum V_368 V_369 , T_2 V_33 )
{
T_3 V_144 ;
T_3 V_140 ;
struct V_123 * V_124 ;
enum V_125 V_126 ;
int V_36 ;
int V_370 ;
V_124 = V_117 -> V_119 + 8 ;
V_144 = ( F_40 ( V_124 -> V_129 ) >> 16 ) & 0xff ;
V_126 = F_40 ( * ( V_127 * ) V_117 -> V_119 ) ;
if ( V_33 != F_14 ( V_32 ) ) {
V_124 -> V_324 &= ~ V_371 ;
if ( V_124 -> V_372 )
return - V_195 ;
}
switch ( V_144 ) {
case V_134 :
case V_135 :
case V_136 :
switch ( V_369 ) {
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
if ( V_33 != F_14 ( V_32 ) ) {
if ( V_126 & V_137 ) {
V_36 = ( V_124 -> V_131 . V_132 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_63 . V_378 [ V_36 ] != V_379 )
V_370 = F_198 ( V_32 , V_33 , V_36 ) ;
else
V_370 = 1 ;
if ( V_124 -> V_131 . V_133 >= V_370 )
return - V_53 ;
}
if ( V_126 & V_138 ) {
V_36 = ( V_124 -> V_139 . V_132 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_63 . V_378 [ V_36 ] != V_379 )
V_370 = F_198 ( V_32 , V_33 , V_36 ) ;
else
V_370 = 1 ;
if ( V_124 -> V_139 . V_133 >= V_370 )
return - V_53 ;
}
}
break;
default:
break;
}
break;
case V_149 :
V_140 = V_293 -> V_298 & 0x7fffff ;
V_36 = ( V_124 -> V_131 . V_132 >> 6 & 1 ) + 1 ;
if ( V_369 == V_373 &&
V_33 != F_14 ( V_32 ) &&
F_45 ( V_32 , V_140 ) &&
! F_199 ( V_32 , V_33 , V_36 ) ) {
F_64 ( V_32 , L_40 ,
V_210 , V_33 , V_36 ) ;
return - V_195 ;
}
break;
default:
break;
}
return 0 ;
}
int F_200 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
struct V_380 V_76 ;
T_5 * V_381 = V_117 -> V_119 ;
T_1 * V_382 = ( T_1 * ) V_381 ;
int V_84 ;
struct V_218 * V_383 = NULL ;
int V_325 = F_165 ( V_381 [ 0 ] ) ;
int V_384 = V_293 -> V_298 ;
int V_44 ;
V_44 = F_196 ( V_32 , V_33 , V_325 , V_384 , & V_383 ) ;
if ( V_44 )
return V_44 ;
V_76 . V_385 = 0 ;
V_76 . V_217 = 0 ;
V_76 . V_309 = 0 ;
for ( V_84 = 0 ; V_84 < V_384 ; ++ V_84 )
V_382 [ V_84 + 2 ] = ( F_165 ( V_381 [ V_84 + 2 ] ) & ~ 1ULL ) ;
V_44 = F_201 ( V_32 , & V_76 , F_165 ( V_381 [ 0 ] ) , V_384 ,
( ( T_1 * ) V_381 + 2 ) ) ;
if ( V_383 )
F_57 ( V_32 , V_33 , V_383 -> V_203 . V_7 , V_24 ) ;
return V_44 ;
}
int F_202 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_362 = V_293 -> V_298 ;
int V_7 = V_362 | ( V_33 << 10 ) ;
struct V_222 * V_260 ;
int V_44 ;
V_44 = F_101 ( V_32 , V_33 , V_7 , V_223 , & V_260 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_260 -> V_76 -> V_203 . V_7 , V_24 , NULL ) ;
if ( V_44 )
goto V_334;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_335;
F_180 ( & V_260 -> V_76 -> V_216 ) ;
F_57 ( V_32 , V_33 , V_260 -> V_76 -> V_203 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_27 , V_7 ) ;
F_97 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return 0 ;
V_335:
F_57 ( V_32 , V_33 , V_260 -> V_76 -> V_203 . V_7 , V_24 ) ;
V_334:
F_104 ( V_32 , V_33 , V_27 , V_7 ) ;
return V_44 ;
}
int F_203 ( struct V_31 * V_32 , int V_33 , struct V_386 * V_387 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_388 * V_389 ;
struct V_116 * V_390 ;
T_3 V_298 = 0 ;
int V_44 ;
int V_7 ;
struct V_222 * V_391 ;
if ( ! V_38 -> V_41 . V_42 . V_289 )
return - V_53 ;
if ( V_33 < 0 || V_33 > V_32 -> V_51 -> V_52 ||
V_33 == V_32 -> V_63 . V_114 ||
! V_38 -> V_41 . V_42 . V_289 [ V_33 ] . V_392 )
return 0 ;
V_389 = & V_38 -> V_41 . V_42 . V_289 [ V_33 ] . V_389 [ V_387 -> type ] ;
if ( V_389 -> V_362 < 0 )
return 0 ;
F_35 ( & V_38 -> V_41 . V_42 . V_393 [ V_33 ] ) ;
V_7 = ( V_33 << 10 ) | V_389 -> V_362 ;
V_44 = F_154 ( V_32 , V_33 , V_7 , V_27 , & V_391 ) ;
if ( V_44 )
goto V_394;
if ( V_391 -> V_203 . V_196 != V_262 ) {
V_44 = - V_53 ;
goto V_395;
}
V_390 = F_204 ( V_32 ) ;
if ( F_205 ( V_390 ) ) {
V_44 = F_206 ( V_390 ) ;
goto V_395;
}
if ( V_387 -> type == V_396 ) {
++ V_389 -> V_397 ;
V_387 -> V_398 . V_271 . V_397 = F_207 ( V_389 -> V_397 ) ;
}
memcpy ( V_390 -> V_119 , ( T_2 * ) V_387 , 28 ) ;
V_298 = ( V_33 & 0xff ) | ( ( V_389 -> V_362 & 0x3ff ) << 16 ) ;
V_44 = F_208 ( V_32 , V_390 -> V_399 , V_298 , 0 ,
V_400 , V_401 ,
V_402 ) ;
F_57 ( V_32 , V_33 , V_7 , V_27 ) ;
F_37 ( & V_38 -> V_41 . V_42 . V_393 [ V_33 ] ) ;
F_209 ( V_32 , V_390 ) ;
return V_44 ;
V_395:
F_57 ( V_32 , V_33 , V_7 , V_27 ) ;
V_394:
F_37 ( & V_38 -> V_41 . V_42 . V_393 [ V_33 ] ) ;
return V_44 ;
}
int F_210 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_362 = V_293 -> V_298 ;
int V_7 = V_362 | ( V_33 << 10 ) ;
struct V_222 * V_260 ;
int V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_7 , V_27 , & V_260 ) ;
if ( V_44 )
return V_44 ;
if ( V_260 -> V_203 . V_196 != V_262 ) {
V_44 = - V_53 ;
goto V_335;
}
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_335:
F_57 ( V_32 , V_33 , V_7 , V_27 ) ;
return V_44 ;
}
int F_211 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_263 = V_293 -> V_298 ;
struct V_358 * V_359 = V_117 -> V_119 ;
int V_329 = F_192 ( V_359 ) / V_32 -> V_63 . V_330 ;
struct V_224 * V_70 = NULL ;
struct V_218 * V_76 ;
V_44 = F_102 ( V_32 , V_33 , V_263 , V_265 , & V_70 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_329 , V_24 , & V_76 ) ;
if ( V_44 )
goto V_364;
V_44 = F_175 ( V_32 , V_33 , V_329 , F_193 ( V_359 ) , V_76 ) ;
if ( V_44 )
goto V_365;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_365;
F_178 ( & V_76 -> V_216 ) ;
V_70 -> V_76 = V_76 ;
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_21 , V_263 ) ;
return 0 ;
V_365:
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
V_364:
F_104 ( V_32 , V_33 , V_21 , V_263 ) ;
return V_44 ;
}
int F_212 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_263 = V_293 -> V_298 ;
struct V_224 * V_70 = NULL ;
V_44 = F_102 ( V_32 , V_33 , V_263 , V_225 , & V_70 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_364;
F_180 ( & V_70 -> V_76 -> V_216 ) ;
F_105 ( V_32 , V_33 , V_21 , V_263 ) ;
return 0 ;
V_364:
F_104 ( V_32 , V_33 , V_21 , V_263 ) ;
return V_44 ;
}
int F_213 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_263 = V_293 -> V_298 ;
struct V_224 * V_70 ;
int V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_263 , V_21 , & V_70 ) ;
if ( V_44 )
return V_44 ;
if ( V_70 -> V_203 . V_196 != V_265 )
goto V_335;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_335:
F_57 ( V_32 , V_33 , V_263 , V_21 ) ;
return V_44 ;
}
static int F_214 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 ,
struct V_224 * V_70 )
{
int V_44 ;
struct V_218 * V_403 ;
struct V_218 * V_76 ;
struct V_358 * V_359 = V_117 -> V_119 ;
int V_329 = F_192 ( V_359 ) / V_32 -> V_63 . V_330 ;
V_44 = F_154 ( V_32 , V_33 , V_70 -> V_76 -> V_203 . V_7 , V_24 , & V_403 ) ;
if ( V_44 )
return V_44 ;
if ( V_403 != V_70 -> V_76 ) {
V_44 = - V_53 ;
goto V_335;
}
V_44 = F_154 ( V_32 , V_33 , V_329 , V_24 , & V_76 ) ;
if ( V_44 )
goto V_335;
V_44 = F_175 ( V_32 , V_33 , V_329 , F_193 ( V_359 ) , V_76 ) ;
if ( V_44 )
goto V_404;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_404;
F_180 ( & V_403 -> V_216 ) ;
F_57 ( V_32 , V_33 , V_403 -> V_203 . V_7 , V_24 ) ;
F_178 ( & V_76 -> V_216 ) ;
V_70 -> V_76 = V_76 ;
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
return 0 ;
V_404:
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
V_335:
F_57 ( V_32 , V_33 , V_403 -> V_203 . V_7 , V_24 ) ;
return V_44 ;
}
int F_215 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_263 = V_293 -> V_298 ;
struct V_224 * V_70 ;
int V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_263 , V_21 , & V_70 ) ;
if ( V_44 )
return V_44 ;
if ( V_70 -> V_203 . V_196 != V_265 )
goto V_335;
if ( V_293 -> V_297 == 0 ) {
V_44 = F_214 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 , V_70 ) ;
goto V_335;
}
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_335:
F_57 ( V_32 , V_33 , V_263 , V_21 ) ;
return V_44 ;
}
static int F_216 ( struct V_307 * V_308 )
{
int V_405 = ( F_40 ( V_308 -> V_406 ) >> 24 ) & 0xf ;
int V_316 = V_308 -> V_407 & 7 ;
int V_309 = ( V_308 -> V_310 & 0x3f ) + 12 ;
if ( V_405 + V_316 + 4 < V_309 )
return 1 ;
return 1 << ( V_405 + V_316 + 4 - V_309 ) ;
}
int F_217 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_278 = V_293 -> V_298 ;
struct V_218 * V_76 ;
struct V_226 * V_73 = NULL ;
struct V_307 * V_308 = V_117 -> V_119 ;
int V_329 = F_172 ( V_308 ) / V_32 -> V_63 . V_330 ;
if ( V_278 != ( F_40 ( V_308 -> V_406 ) & 0xffffff ) )
return - V_53 ;
V_44 = F_103 ( V_32 , V_33 , V_278 , V_267 , & V_73 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_154 ( V_32 , V_33 , V_329 , V_24 , & V_76 ) ;
if ( V_44 )
goto V_334;
V_44 = F_175 ( V_32 , V_33 , V_329 , F_216 ( V_308 ) ,
V_76 ) ;
if ( V_44 )
goto V_351;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_351;
F_178 ( & V_76 -> V_216 ) ;
V_73 -> V_76 = V_76 ;
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
F_105 ( V_32 , V_33 , V_22 , V_278 ) ;
return 0 ;
V_351:
F_57 ( V_32 , V_33 , V_76 -> V_203 . V_7 , V_24 ) ;
V_334:
F_104 ( V_32 , V_33 , V_22 , V_278 ) ;
return V_44 ;
}
int F_218 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_278 = V_293 -> V_298 ;
struct V_226 * V_73 = NULL ;
V_44 = F_103 ( V_32 , V_33 , V_278 , V_227 , & V_73 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_334;
F_180 ( & V_73 -> V_76 -> V_216 ) ;
if ( V_73 -> V_70 )
F_180 ( & V_73 -> V_70 -> V_216 ) ;
F_105 ( V_32 , V_33 , V_22 , V_278 ) ;
return 0 ;
V_334:
F_104 ( V_32 , V_33 , V_22 , V_278 ) ;
return V_44 ;
}
int F_219 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_278 = V_293 -> V_298 ;
struct V_226 * V_73 ;
V_44 = F_154 ( V_32 , V_33 , V_278 , V_22 , & V_73 ) ;
if ( V_44 )
return V_44 ;
if ( V_73 -> V_203 . V_196 != V_267 ) {
V_44 = - V_193 ;
goto V_60;
}
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_60:
F_57 ( V_32 , V_33 , V_278 , V_22 ) ;
return V_44 ;
}
int F_220 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_278 = V_293 -> V_298 ;
struct V_226 * V_73 ;
V_44 = F_154 ( V_32 , V_33 , V_278 , V_22 , & V_73 ) ;
if ( V_44 )
return V_44 ;
if ( V_73 -> V_203 . V_196 != V_267 ) {
V_44 = - V_193 ;
goto V_60;
}
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_60:
F_57 ( V_32 , V_33 , V_278 , V_22 ) ;
return V_44 ;
}
int F_221 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_140 = V_293 -> V_298 & 0x7fffff ;
struct V_211 * V_67 ;
V_44 = F_154 ( V_32 , V_33 , V_140 , V_20 , & V_67 ) ;
if ( V_44 )
return V_44 ;
if ( V_67 -> V_203 . V_196 != V_253 ) {
V_44 = - V_193 ;
goto V_60;
}
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_60:
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
}
int F_222 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
struct V_123 * V_341 = V_117 -> V_119 + 8 ;
F_186 ( V_32 , V_293 , V_341 ) ;
F_38 ( V_32 , V_33 , V_117 ) ;
return F_221 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
}
static int F_189 ( struct V_31 * V_32 , int V_33 ,
struct V_123 * V_141 ,
struct V_116 * V_117 )
{
enum V_125 V_126 = F_40 ( * ( V_127 * ) V_117 -> V_119 ) ;
T_2 V_408 ;
int V_36 = F_137 (
V_32 , V_33 , ( V_141 -> V_131 . V_132 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_36 < 0 )
return - V_53 ;
V_408 = ( V_141 -> V_131 . V_132 & ~ ( 1 << 6 ) ) |
( ( V_36 & 1 ) << 6 ) ;
if ( V_126 & ( V_137 | V_409 ) ||
V_141 -> V_131 . V_132 || F_41 ( V_32 , V_36 + 1 ) ) {
V_141 -> V_131 . V_132 = V_408 ;
}
if ( V_126 & V_138 ) {
V_36 = F_137 (
V_32 , V_33 , ( V_141 -> V_139 . V_132 >> 6 & 1 )
+ 1 ) - 1 ;
if ( V_36 < 0 )
return - V_53 ;
V_141 -> V_139 . V_132 =
( V_141 -> V_139 . V_132 & ~ ( 1 << 6 ) ) |
( V_36 & 1 ) << 6 ;
}
return 0 ;
}
static int F_223 ( struct V_31 * V_32 , int V_33 ,
struct V_123 * V_141 ,
struct V_116 * V_117 )
{
T_1 V_280 ;
int V_36 ;
T_3 V_128 = ( F_40 ( V_141 -> V_129 ) >> 16 ) & 0xff ;
T_2 V_118 = * ( T_2 * ) ( V_117 -> V_119 + 64 ) ;
T_2 V_410 ;
V_36 = ( V_118 >> 6 & 1 ) + 1 ;
if ( F_41 ( V_32 , V_36 ) && ( V_128 != V_149 ) ) {
V_410 = V_141 -> V_131 . V_187 & 0x7f ;
if ( F_130 ( V_32 , V_33 , V_36 , V_410 , & V_280 ) )
return - V_197 ;
}
return 0 ;
}
int F_224 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
struct V_123 * V_141 = V_117 -> V_119 + 8 ;
int V_140 = V_293 -> V_298 & 0x7fffff ;
struct V_211 * V_67 ;
T_2 V_411 ;
T_2 V_412 = V_141 -> V_131 . V_158 ;
T_2 V_413 = V_141 -> V_131 . V_172 ;
T_2 V_414 = V_141 -> V_131 . V_176 ;
T_2 V_415 = V_141 -> V_131 . V_174 ;
T_2 V_416 = V_141 -> V_131 . V_180 ;
V_44 = F_189 ( V_32 , V_33 , V_141 , V_117 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_293 , V_117 , V_373 , V_33 ) ;
if ( V_44 )
return V_44 ;
if ( F_223 ( V_32 , V_33 , V_141 , V_117 ) )
return - V_53 ;
F_38 ( V_32 , V_33 , V_117 ) ;
F_39 ( V_32 , V_117 , ( T_2 ) V_33 ) ;
F_186 ( V_32 , V_293 , V_141 ) ;
V_411 = V_141 -> V_131 . V_132 ;
V_44 = F_154 ( V_32 , V_33 , V_140 , V_20 , & V_67 ) ;
if ( V_44 )
return V_44 ;
if ( V_67 -> V_203 . V_196 != V_253 ) {
V_44 = - V_193 ;
goto V_60;
}
V_44 = F_43 ( V_32 , V_117 , V_33 , V_140 ) ;
if ( V_44 )
goto V_60;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
V_60:
if ( ! V_44 ) {
V_67 -> V_132 = V_411 ;
V_67 -> V_158 = V_412 ;
V_67 -> V_172 = V_413 ;
V_67 -> V_349 = V_414 ;
V_67 -> V_174 = V_415 ;
V_67 -> V_180 = V_416 ;
}
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
}
int F_225 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
struct V_123 * V_341 = V_117 -> V_119 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_341 , V_117 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_293 , V_117 , V_374 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_117 ) ;
F_39 ( V_32 , V_117 , ( T_2 ) V_33 ) ;
F_186 ( V_32 , V_293 , V_341 ) ;
return F_221 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
}
int F_226 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
struct V_123 * V_341 = V_117 -> V_119 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_341 , V_117 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_293 , V_117 , V_375 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_38 ( V_32 , V_33 , V_117 ) ;
F_39 ( V_32 , V_117 , ( T_2 ) V_33 ) ;
F_186 ( V_32 , V_293 , V_341 ) ;
return F_221 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
}
int F_227 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
struct V_123 * V_341 = V_117 -> V_119 + 8 ;
int V_44 = F_189 ( V_32 , V_33 , V_341 , V_117 ) ;
if ( V_44 )
return V_44 ;
F_186 ( V_32 , V_293 , V_341 ) ;
return F_221 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
}
int F_228 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
struct V_123 * V_341 = V_117 -> V_119 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_341 , V_117 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_293 , V_117 , V_376 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_186 ( V_32 , V_293 , V_341 ) ;
F_39 ( V_32 , V_117 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_117 ) ;
return F_221 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
}
int F_229 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
struct V_123 * V_341 = V_117 -> V_119 + 8 ;
V_44 = F_189 ( V_32 , V_33 , V_341 , V_117 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_197 ( V_32 , V_293 , V_117 , V_377 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_186 ( V_32 , V_293 , V_341 ) ;
F_39 ( V_32 , V_117 , ( T_2 ) V_33 ) ;
F_38 ( V_32 , V_33 , V_117 ) ;
return F_221 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
}
int F_230 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_140 = V_293 -> V_298 & 0x7fffff ;
struct V_211 * V_67 ;
V_44 = F_99 ( V_32 , V_33 , V_140 , V_252 , & V_67 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
if ( V_44 )
goto V_334;
F_180 ( & V_67 -> V_76 -> V_216 ) ;
F_180 ( & V_67 -> V_344 -> V_216 ) ;
F_180 ( & V_67 -> V_345 -> V_216 ) ;
if ( V_67 -> V_73 )
F_180 ( & V_67 -> V_73 -> V_216 ) ;
F_105 ( V_32 , V_33 , V_20 , V_140 ) ;
return 0 ;
V_334:
F_104 ( V_32 , V_33 , V_20 , V_140 ) ;
return V_44 ;
}
static struct V_417 * F_231 ( struct V_31 * V_32 , int V_33 ,
struct V_211 * V_418 , T_2 * V_419 )
{
struct V_417 * V_11 ;
F_62 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_419 , V_419 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_232 ( struct V_31 * V_32 , int V_33 , struct V_211 * V_418 ,
T_2 * V_419 , enum V_420 V_421 ,
enum V_422 V_423 , T_1 V_424 )
{
struct V_417 * V_11 ;
int V_44 ;
V_11 = F_21 ( sizeof *V_11 , V_90 ) ;
if ( ! V_11 )
return - V_91 ;
F_53 ( & V_418 -> V_215 ) ;
if ( F_231 ( V_32 , V_33 , V_418 , V_419 ) ) {
F_31 ( V_11 ) ;
V_44 = - V_17 ;
} else {
memcpy ( V_11 -> V_419 , V_419 , 16 ) ;
V_11 -> V_421 = V_421 ;
V_11 -> V_423 = V_423 ;
V_11 -> V_424 = V_424 ;
F_81 ( & V_11 -> V_241 , & V_418 -> V_214 ) ;
V_44 = 0 ;
}
F_55 ( & V_418 -> V_215 ) ;
return V_44 ;
}
static int F_233 ( struct V_31 * V_32 , int V_33 , struct V_211 * V_418 ,
T_2 * V_419 , enum V_420 V_421 ,
enum V_422 V_423 , T_1 * V_424 )
{
struct V_417 * V_11 ;
int V_44 ;
F_53 ( & V_418 -> V_215 ) ;
V_11 = F_231 ( V_32 , V_33 , V_418 , V_419 ) ;
if ( ! V_11 || V_11 -> V_421 != V_421 || V_11 -> V_423 != V_423 )
V_44 = - V_53 ;
else {
* V_424 = V_11 -> V_424 ;
F_98 ( & V_11 -> V_241 ) ;
F_31 ( V_11 ) ;
V_44 = 0 ;
}
F_55 ( & V_418 -> V_215 ) ;
return V_44 ;
}
static int F_234 ( struct V_31 * V_32 , int V_33 , struct V_425 * V_67 ,
T_2 V_419 [ 16 ] , int V_426 , enum V_420 V_421 ,
enum V_422 type , T_1 * V_424 )
{
switch ( V_32 -> V_63 . V_427 ) {
case V_428 : {
int V_36 = F_137 ( V_32 , V_33 , V_419 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return F_235 ( V_32 , V_67 , V_419 , V_36 ,
V_426 , V_421 ,
V_424 ) ;
}
case V_429 :
if ( V_421 == V_430 ) {
int V_36 = F_137 ( V_32 , V_33 , V_419 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
V_419 [ 5 ] = V_36 ;
}
return F_236 ( V_32 , V_67 , V_419 ,
V_426 , V_421 , type ) ;
default:
return - V_53 ;
}
}
static int F_237 ( struct V_31 * V_32 , struct V_425 * V_67 ,
T_2 V_419 [ 16 ] , enum V_420 V_421 ,
enum V_422 type , T_1 V_424 )
{
switch ( V_32 -> V_63 . V_427 ) {
case V_428 :
return F_238 ( V_32 , V_424 ) ;
case V_429 :
return F_239 ( V_32 , V_67 , V_419 , V_421 , type ) ;
default:
return - V_53 ;
}
}
static int F_240 ( struct V_31 * V_32 , int V_33 ,
T_2 * V_419 , enum V_420 V_421 )
{
int V_431 ;
if ( V_421 != V_430 )
return 0 ;
if ( V_32 -> V_63 . V_427 == V_429 ||
V_32 -> V_63 . V_427 == V_428 ) {
V_431 = F_137 ( V_32 , V_33 , V_419 [ 5 ] ) ;
if ( V_431 < 0 )
return - V_53 ;
V_419 [ 5 ] = V_431 ;
}
return 0 ;
}
int F_241 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
struct V_425 V_67 ;
T_2 * V_419 = V_117 -> V_119 ;
enum V_420 V_421 = ( V_293 -> V_298 >> 28 ) & 0x7 ;
int V_44 ;
int V_140 ;
struct V_211 * V_418 ;
T_1 V_424 = 0 ;
int V_432 = V_293 -> V_297 ;
int V_426 = V_293 -> V_298 >> 31 ;
T_2 V_433 = 2 ;
enum V_422 type = ( V_419 [ 7 ] & V_433 ) >> 1 ;
V_140 = V_293 -> V_298 & 0xffffff ;
V_44 = F_154 ( V_32 , V_33 , V_140 , V_20 , & V_418 ) ;
if ( V_44 )
return V_44 ;
V_67 . V_140 = V_140 ;
if ( V_432 ) {
V_44 = F_234 ( V_32 , V_33 , & V_67 , V_419 , V_426 , V_421 ,
type , & V_424 ) ;
if ( V_44 ) {
F_76 ( L_41 , V_140 ) ;
goto V_335;
}
V_44 = F_232 ( V_32 , V_33 , V_418 , V_419 , V_421 , type , V_424 ) ;
if ( V_44 )
goto V_434;
} else {
V_44 = F_240 ( V_32 , V_33 , V_419 , V_421 ) ;
if ( V_44 )
goto V_335;
V_44 = F_233 ( V_32 , V_33 , V_418 , V_419 , V_421 , type , & V_424 ) ;
if ( V_44 )
goto V_335;
V_44 = F_237 ( V_32 , & V_67 , V_419 , V_421 , type , V_424 ) ;
if ( V_44 )
F_76 ( L_42 ,
V_140 , V_424 ) ;
}
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
V_434:
F_237 ( V_32 , & V_67 , V_419 , V_421 , type , V_424 ) ;
V_335:
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
}
static int F_242 ( int V_33 , struct V_435 * V_436 ,
struct V_281 * V_437 )
{
struct V_283 * V_11 , * V_206 ;
T_5 V_438 ;
if ( ! F_243 ( V_436 -> V_439 . V_440 ) &&
! F_244 ( V_436 -> V_439 . V_440 ) ) {
F_131 (res, tmp, rlist, list) {
V_438 = F_245 ( V_11 -> V_280 << 16 ) ;
if ( F_246 ( ( T_2 * ) & V_438 , V_436 -> V_439 . V_440 ) )
return 0 ;
}
F_76 ( L_43 ,
V_436 -> V_439 . V_440 , V_33 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_247 ( struct V_31 * V_32 , int V_33 ,
struct V_116 * V_117 ,
struct V_281 * V_437 , int V_441 )
{
struct V_283 * V_11 , * V_206 ;
T_2 V_36 ;
struct V_442 * V_443 ;
struct V_444 * V_436 ;
struct V_445 * V_446 ;
struct V_447 * V_448 ;
T_5 V_438 = 0 ;
T_5 V_449 = F_245 ( V_450 << 16 ) ;
V_443 = (struct V_442 * ) V_117 -> V_119 ;
V_36 = V_443 -> V_36 ;
V_436 = (struct V_444 * ) ( V_443 + 1 ) ;
switch ( V_441 ) {
case V_451 :
V_446 =
(struct V_445 * ) ( V_436 + 1 ) ;
memmove ( V_446 , V_436 ,
sizeof( * V_446 ) + sizeof( * V_448 ) ) ;
break;
case V_452 :
case V_453 :
V_448 = (struct V_447 * )
( V_436 + 1 ) ;
memmove ( V_448 , V_436 , sizeof( * V_448 ) ) ;
break;
default:
return - V_53 ;
}
F_131 (res, tmp, rlist, list) {
if ( V_36 == V_11 -> V_36 ) {
V_438 = F_245 ( V_11 -> V_280 << 16 ) ;
break;
}
}
if ( ! V_438 ) {
F_76 ( L_44 ,
V_36 ) ;
return - V_53 ;
}
memset ( V_436 , 0 , sizeof( * V_436 ) ) ;
V_436 -> V_326 = sizeof( * V_436 ) >> 2 ;
V_436 -> V_198 = F_207 ( V_454 [ V_455 ] ) ;
memcpy ( V_436 -> V_440 , & V_438 , V_456 ) ;
memcpy ( V_436 -> V_457 , & V_449 , V_456 ) ;
return 0 ;
}
int F_248 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_458 )
{
int V_44 ;
T_3 V_140 = V_293 -> V_298 & 0xffffff ;
struct V_211 * V_418 ;
T_1 V_280 ;
unsigned V_36 ;
T_1 V_459 ;
struct V_460 * V_271 ;
int V_279 ;
V_271 = (struct V_460 * ) V_117 -> V_119 ;
V_459 = F_165 ( V_271 -> V_461 ) ;
if ( V_271 -> V_462 || V_271 -> V_463 ||
( V_459 & ~ V_464 ) )
return - V_195 ;
if ( ( V_459 &
( 1ULL << V_465 ) ) &&
! ( V_32 -> V_63 . V_162 &
V_466 ) ) {
F_10 ( V_32 , L_45 ,
V_33 ) ;
return - V_249 ;
}
V_44 = F_154 ( V_32 , V_33 , V_140 , V_20 , & V_418 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_46 , V_140 , V_33 ) ;
return V_44 ;
}
V_36 = ( V_418 -> V_132 >> 6 & 1 ) + 1 ;
if ( V_459 & ( 1ULL << V_467 ) ) {
V_279 = V_271 -> V_468 . V_131 . V_187 ;
V_44 = F_130 ( V_32 , V_33 , V_36 ,
V_279 , & V_280 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_47 ,
V_140 , V_279 ) ;
goto V_469;
}
}
V_44 = F_208 ( V_32 , V_117 -> V_399 ,
V_293 -> V_298 , 0 ,
V_470 , V_471 ,
V_402 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_48 , V_140 ) ;
goto V_469;
}
V_469:
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
}
static T_3 F_249 ( void * V_472 )
{
T_3 V_326 = sizeof( struct V_442 ) ;
struct V_435 * V_473 ;
V_473 = (struct V_435 * ) ( V_472 + V_326 ) ;
while ( V_473 -> V_326 ) {
V_326 += V_473 -> V_326 * sizeof( T_3 ) ;
V_473 += 1 ;
}
return V_326 ;
}
int F_250 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_437 = & V_205 -> V_88 [ V_33 ] . V_93 [ V_25 ] ;
int V_44 ;
int V_140 ;
struct V_211 * V_418 ;
struct V_442 * V_443 ;
struct V_435 * V_473 ;
int V_441 ;
struct V_231 * V_474 ;
T_3 V_475 ;
if ( V_32 -> V_63 . V_427 !=
V_428 )
return - V_249 ;
V_443 = (struct V_442 * ) V_117 -> V_119 ;
V_44 = F_137 ( V_32 , V_33 , V_443 -> V_36 ) ;
if ( V_44 <= 0 )
return - V_53 ;
V_443 -> V_36 = V_44 ;
V_140 = F_40 ( V_443 -> V_140 ) & 0xffffff ;
V_44 = F_154 ( V_32 , V_33 , V_140 , V_20 , & V_418 ) ;
if ( V_44 ) {
F_76 ( L_49 , V_140 ) ;
return V_44 ;
}
V_473 = (struct V_435 * ) ( V_443 + 1 ) ;
V_441 = F_251 ( F_252 ( V_473 -> V_198 ) ) ;
if ( V_441 == V_455 )
F_253 ( V_443 , V_473 ) ;
switch ( V_441 ) {
case V_455 :
if ( F_242 ( V_33 , V_473 , V_437 ) ) {
V_44 = - V_53 ;
goto V_476;
}
break;
case V_477 :
break;
case V_451 :
case V_452 :
case V_453 :
F_254 ( L_50 ) ;
if ( F_247 ( V_32 , V_33 , V_117 , V_437 , V_441 ) ) {
V_44 = - V_53 ;
goto V_476;
}
V_293 -> V_298 +=
sizeof( struct V_444 ) >> 2 ;
break;
default:
F_76 ( L_51 ) ;
V_44 = - V_53 ;
goto V_476;
}
V_44 = F_255 ( V_32 , V_117 -> V_399 , & V_293 -> V_273 ,
V_293 -> V_298 , 0 ,
V_478 , V_471 ,
V_402 ) ;
if ( V_44 )
goto V_476;
V_44 = F_80 ( V_32 , V_33 , V_293 -> V_273 , 1 , V_29 , V_140 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_52 ) ;
goto V_479;
}
V_44 = F_154 ( V_32 , V_33 , V_293 -> V_273 , V_29 , & V_474 ) ;
if ( V_44 )
goto V_479;
V_475 = F_249 ( V_117 -> V_119 ) ;
V_474 -> V_480 = F_25 ( V_475 , V_90 ) ;
if ( ! V_474 -> V_480 ) {
V_44 = - V_91 ;
goto V_481;
}
V_474 -> V_482 = V_475 ;
V_474 -> V_483 = 0 ;
memcpy ( V_474 -> V_480 , V_117 -> V_119 , V_475 ) ;
V_443 = (struct V_442 * ) V_474 -> V_480 ;
if ( V_443 -> V_36 == 1 )
V_443 -> V_36 = 2 ;
else
V_443 -> V_36 = 1 ;
if ( F_256 ( V_32 ) )
F_257 ( V_32 , V_474 ) ;
F_178 ( & V_418 -> V_216 ) ;
V_481:
F_57 ( V_32 , V_33 , V_293 -> V_273 , V_29 ) ;
V_479:
if ( V_44 )
F_208 ( V_32 , V_293 -> V_273 , 0 , 0 ,
V_484 , V_471 ,
V_402 ) ;
V_476:
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
}
static int F_258 ( struct V_31 * V_32 , struct V_231 * V_485 )
{
int V_44 ;
V_44 = F_97 ( V_32 , V_485 -> V_203 . V_194 , V_485 -> V_203 . V_7 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_53 ) ;
return V_44 ;
}
F_208 ( V_32 , V_485 -> V_203 . V_7 , 0 , 0 , V_484 ,
V_471 , V_402 ) ;
return 0 ;
}
int F_259 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
struct V_211 * V_418 ;
struct V_231 * V_474 ;
T_1 V_486 ;
int V_140 ;
if ( V_32 -> V_63 . V_427 !=
V_428 )
return - V_249 ;
V_44 = F_154 ( V_32 , V_33 , V_293 -> V_272 , V_29 , & V_474 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_474 -> V_480 ) {
F_64 ( V_32 , L_54 ) ;
F_57 ( V_32 , V_33 , V_293 -> V_272 , V_29 ) ;
return - V_53 ;
}
V_486 = V_474 -> V_483 ;
F_31 ( V_474 -> V_480 ) ;
V_140 = V_474 -> V_140 ;
F_57 ( V_32 , V_33 , V_293 -> V_272 , V_29 ) ;
V_44 = F_154 ( V_32 , V_33 , V_140 , V_20 , & V_418 ) ;
if ( V_44 )
return V_44 ;
if ( V_486 && F_256 ( V_32 ) ) {
V_44 = F_154 ( V_32 , V_33 , V_486 , V_29 , & V_474 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_55 ) ;
} else {
F_57 ( V_32 , V_33 , V_486 , V_29 ) ;
F_258 ( V_32 , V_474 ) ;
}
}
V_44 = F_97 ( V_32 , V_33 , V_293 -> V_272 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_64 ( V_32 , L_53 ) ;
goto V_60;
}
V_44 = F_208 ( V_32 , V_293 -> V_272 , 0 , 0 ,
V_484 , V_471 ,
V_402 ) ;
if ( ! V_44 )
F_180 ( & V_418 -> V_216 ) ;
V_60:
F_57 ( V_32 , V_33 , V_140 , V_20 ) ;
return V_44 ;
}
int F_260 ( struct V_31 * V_32 , int V_33 ,
struct V_292 * V_293 ,
struct V_116 * V_117 ,
struct V_116 * V_294 ,
struct V_295 * V_271 )
{
int V_44 ;
int V_255 = V_293 -> V_298 & 0xffff ;
V_44 = F_154 ( V_32 , V_33 , V_255 , V_28 , NULL ) ;
if ( V_44 )
return V_44 ;
V_44 = F_177 ( V_32 , V_33 , V_293 , V_117 , V_294 , V_271 ) ;
F_57 ( V_32 , V_33 , V_255 , V_28 ) ;
return V_44 ;
}
static void F_261 ( struct V_31 * V_32 , int V_33 , struct V_211 * V_418 )
{
struct V_417 * V_487 ;
struct V_417 * V_206 ;
struct V_425 V_67 ;
F_131 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_32 -> V_63 . V_427 ) {
case V_428 :
F_238 ( V_32 , V_487 -> V_424 ) ;
break;
case V_429 :
V_67 . V_140 = V_418 -> V_213 ;
( void ) F_239 ( V_32 , & V_67 , V_487 -> V_419 ,
V_487 -> V_421 , V_487 -> V_423 ) ;
break;
}
F_98 ( & V_487 -> V_241 ) ;
F_31 ( V_487 ) ;
}
}
static int F_262 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_488 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_437 = & V_205 -> V_88 [ V_33 ] . V_93 [ type ] ;
struct V_10 * V_190 ;
struct V_10 * V_206 ;
int V_489 ;
V_489 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (r, tmp, rlist, list) {
if ( V_190 -> V_194 == V_33 ) {
if ( ! V_190 -> V_490 ) {
if ( V_190 -> V_2 == V_192 ) {
if ( V_488 )
F_24 ( V_32 ,
L_56 ,
F_7 ( type ) ,
V_190 -> V_7 ) ;
++ V_489 ;
} else {
V_190 -> V_196 = V_190 -> V_2 ;
V_190 -> V_2 = V_192 ;
V_190 -> V_490 = 1 ;
}
}
}
}
F_55 ( F_54 ( V_32 ) ) ;
return V_489 ;
}
static int F_263 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type )
{
unsigned long V_491 ;
int V_489 ;
V_491 = V_492 ;
do {
V_489 = F_262 ( V_32 , V_33 , type , 0 ) ;
if ( F_264 ( V_492 , V_491 + 5 * V_493 ) )
break;
if ( V_489 )
F_265 () ;
} while ( V_489 );
if ( V_489 )
V_489 = F_262 ( V_32 , V_33 , type , 1 ) ;
return V_489 ;
}
static void F_266 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_494 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_20 ] ;
struct V_211 * V_67 ;
struct V_211 * V_206 ;
int V_2 ;
T_1 V_272 ;
int V_140 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_20 ) ;
if ( V_44 )
F_10 ( V_32 , L_57 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (qp, tmp, qp_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_67 -> V_203 . V_194 == V_33 ) {
V_140 = V_67 -> V_203 . V_7 ;
F_261 ( V_32 , V_33 , V_67 ) ;
V_2 = V_67 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_212 :
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_67 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_20 ] ) ;
F_98 ( & V_67 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
if ( ! F_106 ( V_32 , V_33 , V_140 ) ) {
F_114 ( V_32 , V_140 , 1 ) ;
F_12 ( V_32 , V_33 ,
V_20 , 1 , 0 ) ;
}
F_31 ( V_67 ) ;
V_2 = 0 ;
break;
case V_252 :
if ( ! F_106 ( V_32 , V_33 , V_140 ) )
F_151 ( V_32 , V_140 ) ;
V_2 = V_212 ;
break;
case V_253 :
V_272 = V_33 ;
V_44 = F_208 ( V_32 , V_272 ,
V_67 -> V_213 , 2 ,
V_495 ,
V_471 ,
V_402 ) ;
if ( V_44 )
F_24 ( V_32 , L_58 ,
V_33 , V_67 -> V_213 ) ;
F_180 ( & V_67 -> V_344 -> V_216 ) ;
F_180 ( & V_67 -> V_345 -> V_216 ) ;
F_180 ( & V_67 -> V_76 -> V_216 ) ;
if ( V_67 -> V_73 )
F_180 ( & V_67 -> V_73 -> V_216 ) ;
V_2 = V_252 ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_496 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_22 ] ;
struct V_226 * V_73 ;
struct V_226 * V_206 ;
int V_2 ;
T_1 V_272 ;
F_268 ( V_497 ) ;
int V_278 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_22 ) ;
if ( V_44 )
F_10 ( V_32 , L_59 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (srq, tmp, srq_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_73 -> V_203 . V_194 == V_33 ) {
V_278 = V_73 -> V_203 . V_7 ;
V_2 = V_73 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_227 :
F_129 ( V_32 , V_278 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_73 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_22 ] ) ;
F_98 ( & V_73 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_22 , 1 , 0 ) ;
F_31 ( V_73 ) ;
V_2 = 0 ;
break;
case V_267 :
V_272 = V_33 ;
V_44 = F_208 ( V_32 , V_272 , V_278 , 1 ,
V_498 ,
V_471 ,
V_402 ) ;
if ( V_44 )
F_24 ( V_32 , L_60 ,
V_33 , V_278 ) ;
F_180 ( & V_73 -> V_76 -> V_216 ) ;
if ( V_73 -> V_70 )
F_180 ( & V_73 -> V_70 -> V_216 ) ;
V_2 = V_227 ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_499 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_21 ] ;
struct V_224 * V_70 ;
struct V_224 * V_206 ;
int V_2 ;
T_1 V_272 ;
F_268 ( V_497 ) ;
int V_263 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_21 ) ;
if ( V_44 )
F_10 ( V_32 , L_61 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (cq, tmp, cq_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_70 -> V_203 . V_194 == V_33 && ! F_85 ( & V_70 -> V_216 ) ) {
V_263 = V_70 -> V_203 . V_7 ;
V_2 = V_70 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_225 :
F_126 ( V_32 , V_263 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_70 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_21 ] ) ;
F_98 ( & V_70 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_21 , 1 , 0 ) ;
F_31 ( V_70 ) ;
V_2 = 0 ;
break;
case V_265 :
V_272 = V_33 ;
V_44 = F_208 ( V_32 , V_272 , V_263 , 1 ,
V_500 ,
V_471 ,
V_402 ) ;
if ( V_44 )
F_24 ( V_32 , L_62 ,
V_33 , V_263 ) ;
F_180 ( & V_70 -> V_76 -> V_216 ) ;
V_2 = V_225 ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_501 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_23 ] ;
struct V_220 * V_78 ;
struct V_220 * V_206 ;
int V_2 ;
T_1 V_272 ;
F_268 ( V_497 ) ;
int V_502 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_23 ) ;
if ( V_44 )
F_10 ( V_32 , L_63 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (mpt, tmp, mpt_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_78 -> V_203 . V_194 == V_33 ) {
V_502 = V_78 -> V_203 . V_7 ;
V_2 = V_78 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_221 :
F_122 ( V_32 , V_78 -> V_219 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_78 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_23 ] ) ;
F_98 ( & V_78 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_23 , 1 , 0 ) ;
F_31 ( V_78 ) ;
V_2 = 0 ;
break;
case V_257 :
F_155 ( V_32 , V_78 -> V_219 ) ;
V_2 = V_221 ;
break;
case V_258 :
V_272 = V_33 ;
V_44 = F_208 ( V_32 , V_272 , V_502 , 0 ,
V_503 ,
V_471 ,
V_402 ) ;
if ( V_44 )
F_24 ( V_32 , L_64 ,
V_33 , V_502 ) ;
if ( V_78 -> V_76 )
F_180 ( & V_78 -> V_76 -> V_216 ) ;
V_2 = V_257 ;
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
struct V_204 * V_205 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_504 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_24 ] ;
struct V_218 * V_76 ;
struct V_218 * V_206 ;
int V_2 ;
F_268 ( V_497 ) ;
int V_238 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_24 ) ;
if ( V_44 )
F_10 ( V_32 , L_65 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (mtt, tmp, mtt_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_76 -> V_203 . V_194 == V_33 ) {
V_238 = V_76 -> V_203 . V_7 ;
V_2 = V_76 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_119 ( V_32 , V_238 ,
V_76 -> V_217 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_76 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_24 ] ) ;
F_98 ( & V_76 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_12 ( V_32 , V_33 , V_24 ,
1 << V_76 -> V_217 , 0 ) ;
F_31 ( V_76 ) ;
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
static int F_257 ( struct V_31 * V_32 , struct V_231 * V_485 )
{
struct V_116 * V_390 ;
int V_44 ;
struct V_231 * V_505 ;
T_1 V_424 ;
V_390 = F_204 ( V_32 ) ;
if ( F_205 ( V_390 ) )
return F_206 ( V_390 ) ;
if ( ! V_485 -> V_480 ) {
F_64 ( V_32 , L_66 ) ;
return - V_53 ;
}
memcpy ( V_390 -> V_119 , V_485 -> V_480 , V_485 -> V_482 ) ;
V_44 = F_255 ( V_32 , V_390 -> V_399 , & V_424 , V_485 -> V_482 >> 2 , 0 ,
V_478 , V_471 ,
V_402 ) ;
F_209 ( V_32 , V_390 ) ;
if ( V_44 )
goto V_44;
V_44 = F_80 ( V_32 , V_485 -> V_203 . V_194 , V_424 , 1 , V_29 , V_485 -> V_140 ) ;
if ( V_44 )
goto V_479;
V_44 = F_154 ( V_32 , V_485 -> V_203 . V_194 , V_424 , V_29 , & V_505 ) ;
if ( V_44 )
goto V_506;
V_485 -> V_483 = V_424 ;
V_505 -> V_483 = 0 ;
V_505 -> V_482 = 0 ;
V_505 -> V_480 = NULL ;
F_57 ( V_32 , V_485 -> V_203 . V_194 , V_424 , V_29 ) ;
return 0 ;
V_506:
F_97 ( V_32 , V_485 -> V_203 . V_194 , V_424 , 1 , V_29 , 0 ) ;
V_479:
F_208 ( V_32 , V_424 , 0 , 0 , V_484 ,
V_471 , V_402 ) ;
V_44:
return V_44 ;
}
static int F_272 ( struct V_31 * V_32 , bool V_507 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_205 -> V_95 [ V_29 ] ;
struct V_8 * V_508 ;
struct V_231 * V_485 ;
int V_44 = 0 ;
F_268 ( V_509 ) ;
for ( V_508 = F_273 ( V_6 ) ; V_508 ; V_508 = F_274 ( V_508 ) ) {
V_485 = F_3 ( V_508 , struct V_231 , V_203 . V_9 ) ;
if ( ( V_507 && V_485 -> V_482 ) ||
( ! V_507 && ! V_485 -> V_482 ) )
F_81 ( & V_485 -> V_509 , & V_509 ) ;
}
F_62 (fs_rule, &mirr_list, mirr_list) {
if ( V_507 )
V_44 += F_257 ( V_32 , V_485 ) ;
else
V_44 += F_258 ( V_32 , V_485 ) ;
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
struct V_204 * V_205 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_510 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_29 ] ;
struct V_231 * V_485 ;
struct V_231 * V_206 ;
int V_2 ;
T_1 V_238 ;
int V_44 ;
V_44 = F_263 ( V_32 , V_33 , V_29 ) ;
if ( V_44 )
F_10 ( V_32 , L_67 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (fs_rule, tmp, fs_rule_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_485 -> V_203 . V_194 == V_33 ) {
V_238 = V_485 -> V_203 . V_7 ;
V_2 = V_485 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_232 :
V_44 = F_208 ( V_32 , V_238 , 0 , 0 ,
V_484 ,
V_471 ,
V_402 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_485 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_29 ] ) ;
F_98 ( & V_485 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_31 ( V_485 ) ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_511 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_27 ] ;
struct V_222 * V_260 ;
struct V_222 * V_206 ;
int V_44 ;
int V_2 ;
F_268 ( V_497 ) ;
int V_362 ;
V_44 = F_263 ( V_32 , V_33 , V_27 ) ;
if ( V_44 )
F_10 ( V_32 , L_68 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (eq, tmp, eq_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_260 -> V_203 . V_194 == V_33 ) {
V_362 = V_260 -> V_203 . V_7 ;
V_2 = V_260 -> V_203 . V_196 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_223 :
F_53 ( F_54 ( V_32 ) ) ;
F_82 ( & V_260 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_27 ] ) ;
F_98 ( & V_260 -> V_203 . V_241 ) ;
F_55 ( F_54 ( V_32 ) ) ;
F_31 ( V_260 ) ;
V_2 = 0 ;
break;
case V_262 :
V_44 = F_208 ( V_32 , V_33 , V_362 & 0x3ff ,
1 , V_512 ,
V_471 ,
V_402 ) ;
if ( V_44 )
F_24 ( V_32 , L_69 ,
V_33 , V_362 & 0x3ff ) ;
F_180 ( & V_260 -> V_76 -> V_216 ) ;
V_2 = V_223 ;
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
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_513 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_28 ] ;
struct V_200 * V_201 ;
struct V_200 * V_206 ;
int V_44 ;
int * V_236 = NULL ;
int V_84 , V_85 ;
V_44 = F_263 ( V_32 , V_33 , V_28 ) ;
if ( V_44 )
F_10 ( V_32 , L_70 ,
V_33 ) ;
V_236 = F_78 ( V_32 -> V_63 . V_81 ,
sizeof( * V_236 ) , V_90 ) ;
if ( ! V_236 )
return;
do {
V_84 = 0 ;
V_85 = 0 ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (counter, tmp, counter_list, com.list) {
if ( V_201 -> V_203 . V_194 == V_33 ) {
V_236 [ V_84 ++ ] = V_201 -> V_203 . V_7 ;
F_82 ( & V_201 -> V_203 . V_9 ,
& V_205 -> V_95 [ V_28 ] ) ;
F_98 ( & V_201 -> V_203 . V_241 ) ;
F_31 ( V_201 ) ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
while ( V_85 < V_84 ) {
F_145 ( V_32 , V_236 [ V_85 ++ ] ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
}
} while ( V_84 );
F_31 ( V_236 ) ;
}
static void F_280 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_204 * V_205 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_514 =
& V_205 -> V_88 [ V_33 ] . V_93 [ V_30 ] ;
struct V_229 * V_515 ;
struct V_229 * V_206 ;
int V_44 ;
int V_291 ;
V_44 = F_263 ( V_32 , V_33 , V_30 ) ;
if ( V_44 )
F_10 ( V_32 , L_71 ,
V_33 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_515 -> V_203 . V_194 == V_33 ) {
V_291 = V_515 -> V_203 . V_7 ;
F_82 ( & V_515 -> V_203 . V_9 , & V_205 -> V_95 [ V_30 ] ) ;
F_98 ( & V_515 -> V_203 . V_241 ) ;
F_31 ( V_515 ) ;
F_148 ( V_32 , V_291 ) ;
}
}
F_55 ( F_54 ( V_32 ) ) ;
}
void F_33 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
F_34 ( V_32 , V_33 ) ;
F_35 ( & V_38 -> V_41 . V_42 . V_43 . V_88 [ V_33 ] . V_94 ) ;
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
F_37 ( & V_38 -> V_41 . V_42 . V_43 . V_88 [ V_33 ] . V_94 ) ;
}
static void F_281 ( struct V_460 * V_516 ,
struct V_517 * V_518 )
{
V_516 -> V_462 |= F_245 ( 1ULL << V_519 ) ;
V_516 -> V_468 . V_184 = V_518 -> V_184 ;
}
void F_282 ( struct V_520 * V_521 )
{
struct V_517 * V_518 =
F_60 ( V_521 , struct V_517 , V_518 ) ;
struct V_116 * V_390 ;
struct V_460 * V_522 ;
struct V_31 * V_32 = & V_518 -> V_38 -> V_32 ;
struct V_204 * V_205 =
& V_518 -> V_38 -> V_41 . V_42 . V_43 ;
struct V_281 * V_494 =
& V_205 -> V_88 [ V_518 -> V_33 ] . V_93 [ V_20 ] ;
struct V_211 * V_67 ;
struct V_211 * V_206 ;
T_1 V_523 =
( ( 1ULL << V_524 ) |
( 1ULL << V_525 ) |
( 1ULL << V_526 ) |
( 1ULL << V_527 ) |
( 1ULL << V_528 ) |
( 1ULL << V_529 ) ) ;
T_1 V_530 = ( ( 1ULL << V_531 ) |
( 1ULL << V_532 ) |
( 1ULL << V_533 ) |
( 1ULL << V_534 ) |
( 1ULL << V_535 ) |
( 1ULL << V_536 ) |
( 1ULL << V_537 ) |
( 1ULL << V_538 ) ) ;
int V_44 ;
int V_36 , V_539 = 0 ;
T_2 V_158 ;
if ( F_16 ( V_32 ) ) {
F_10 ( V_32 , L_72 ,
V_518 -> V_33 ) ;
goto V_60;
}
V_390 = F_204 ( V_32 ) ;
if ( F_205 ( V_390 ) )
goto V_60;
if ( V_518 -> V_129 & V_540 )
V_158 = V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 ;
else if ( ! V_518 -> V_541 )
V_158 = V_164 |
V_169 ;
else if ( V_518 -> V_170 == F_48 ( V_171 ) )
V_158 = V_165 |
V_164 |
V_167 |
V_168 ;
else
V_158 = V_164 |
V_167 |
V_168 ;
V_522 = V_390 -> V_119 ;
V_522 -> V_462 = F_245 ( 1ULL << V_542 ) ;
F_53 ( F_54 ( V_32 ) ) ;
F_131 (qp, tmp, qp_list, com.list) {
F_55 ( F_54 ( V_32 ) ) ;
if ( V_67 -> V_203 . V_194 == V_518 -> V_33 ) {
if ( V_67 -> V_203 . V_196 != V_253 ||
! V_67 -> V_132 ||
F_45 ( V_32 , V_67 -> V_213 ) ||
V_67 -> V_350 & ( 1 << V_543 ) ) {
F_53 ( F_54 ( V_32 ) ) ;
continue;
}
V_36 = ( V_67 -> V_132 >> 6 & 1 ) + 1 ;
if ( V_36 != V_518 -> V_36 ) {
F_53 ( F_54 ( V_32 ) ) ;
continue;
}
if ( V_134 == ( ( V_67 -> V_350 >> 16 ) & 0xff ) )
V_522 -> V_461 = F_245 ( V_530 ) ;
else
V_522 -> V_461 =
F_245 ( V_530 | V_523 ) ;
if ( V_518 -> V_541 == V_147 ) {
V_522 -> V_468 . V_153 = V_67 -> V_153 ;
V_522 -> V_468 . V_131 . V_158 = V_67 -> V_158 ;
V_522 -> V_468 . V_131 . V_172 = V_67 -> V_172 ;
V_522 -> V_468 . V_131 . V_174 = V_67 -> V_174 ;
V_522 -> V_468 . V_131 . V_176 = V_67 -> V_349 ;
V_522 -> V_468 . V_131 . V_180 = V_67 -> V_180 ;
V_522 -> V_468 . V_131 . V_132 =
V_67 -> V_132 ;
} else {
V_522 -> V_468 . V_153 = V_67 -> V_153 & ~ F_46 ( V_154 ) ;
V_522 -> V_468 . V_131 . V_158 = V_158 ;
V_522 -> V_468 . V_131 . V_174 = V_518 -> V_544 ;
V_522 -> V_468 . V_131 . V_172 =
V_67 -> V_172 | V_173 ;
V_522 -> V_468 . V_131 . V_176 =
V_67 -> V_349 | V_177 ;
if ( V_518 -> V_170 == F_48 ( V_171 ) )
V_522 -> V_468 . V_131 . V_176 |= V_178 ;
else
V_522 -> V_468 . V_131 . V_176 |= V_179 ;
V_522 -> V_468 . V_131 . V_180 =
V_67 -> V_180 | V_181 | V_182 ;
V_522 -> V_468 . V_131 . V_132 =
V_67 -> V_132 & 0xC7 ;
V_522 -> V_468 . V_131 . V_132 |=
( ( V_518 -> V_545 & 0x7 ) << 3 ) ;
if ( V_32 -> V_63 . V_162 &
V_546 )
F_281 ( V_522 , V_518 ) ;
}
V_44 = F_208 ( V_32 , V_390 -> V_399 ,
V_67 -> V_213 & 0xffffff ,
0 , V_470 ,
V_547 , V_402 ) ;
if ( V_44 ) {
F_283 ( V_32 , L_73 ,
V_518 -> V_33 , V_36 , V_67 -> V_213 , V_44 ) ;
V_539 ++ ;
}
}
F_53 ( F_54 ( V_32 ) ) ;
}
F_55 ( F_54 ( V_32 ) ) ;
F_209 ( V_32 , V_390 ) ;
if ( V_539 )
F_64 ( V_32 , L_74 ,
V_539 , V_518 -> V_33 , V_518 -> V_36 ) ;
if ( V_518 -> V_129 & V_548 && ! V_539 &&
V_549 != V_518 -> V_550 )
F_141 ( & V_518 -> V_38 -> V_32 , V_518 -> V_36 ,
V_518 -> V_551 ) ;
V_60:
F_31 ( V_518 ) ;
return;
}
