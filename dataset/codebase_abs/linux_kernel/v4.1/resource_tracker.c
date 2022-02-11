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
int F_19 ( struct V_31 * V_32 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_80 , V_81 ;
int V_82 ;
V_38 -> V_41 . V_42 . V_43 . V_83 =
F_20 ( V_32 -> V_84 * sizeof( struct V_83 ) ,
V_85 ) ;
if ( ! V_38 -> V_41 . V_42 . V_43 . V_83 )
return - V_86 ;
for ( V_80 = 0 ; V_80 < V_32 -> V_84 ; V_80 ++ ) {
for ( V_82 = 0 ; V_82 < V_87 ; ++ V_82 )
F_21 ( & V_38 -> V_41 . V_42 . V_43 .
V_83 [ V_80 ] . V_88 [ V_82 ] ) ;
F_22 ( & V_38 -> V_41 . V_42 . V_43 . V_83 [ V_80 ] . V_89 ) ;
}
F_23 ( V_32 , L_18 ,
V_32 -> V_84 ) ;
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ )
V_38 -> V_41 . V_42 . V_43 . V_90 [ V_80 ] = V_91 ;
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
struct V_39 * V_40 =
& V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] ;
V_40 -> V_58 = F_24 ( ( V_32 -> V_51 -> V_52 + 1 ) *
sizeof( int ) , V_85 ) ;
V_40 -> V_48 = F_24 ( ( V_32 -> V_51 -> V_52 + 1 ) *
sizeof( int ) , V_85 ) ;
if ( V_80 == V_25 || V_80 == V_26 )
V_40 -> V_46 = F_20 ( V_92 *
( V_32 -> V_51 -> V_52
+ 1 ) *
sizeof( int ) , V_85 ) ;
else
V_40 -> V_46 = F_20 ( ( V_32 -> V_51 ->
V_52 + 1 ) *
sizeof( int ) , V_85 ) ;
if ( ! V_40 -> V_58 || ! V_40 -> V_48 ||
! V_40 -> V_46 )
goto V_93;
F_25 ( & V_40 -> V_53 ) ;
for ( V_82 = 0 ; V_82 < V_32 -> V_51 -> V_52 + 1 ; V_82 ++ ) {
struct V_94 V_95 =
F_26 ( V_32 , V_82 ) ;
switch ( V_80 ) {
case V_20 :
F_13 ( V_32 , V_40 , V_20 ,
V_82 , V_32 -> V_62 . V_67 -
V_32 -> V_62 . V_68 -
F_18 ( V_32 ) ) ;
break;
case V_21 :
F_13 ( V_32 , V_40 , V_21 ,
V_82 , V_32 -> V_62 . V_70 -
V_32 -> V_62 . V_71 ) ;
break;
case V_22 :
F_13 ( V_32 , V_40 , V_22 ,
V_82 , V_32 -> V_62 . V_73 -
V_32 -> V_62 . V_74 ) ;
break;
case V_23 :
F_13 ( V_32 , V_40 , V_23 ,
V_82 , V_32 -> V_62 . V_78 -
V_32 -> V_62 . V_79 ) ;
break;
case V_24 :
F_13 ( V_32 , V_40 , V_24 ,
V_82 , V_32 -> V_62 . V_76 -
V_32 -> V_62 . V_63 ) ;
break;
case V_25 :
if ( V_82 == F_14 ( V_32 ) ) {
int V_96 = 0 ;
for ( V_81 = 0 ; V_81 < V_32 -> V_62 . V_97 ;
V_81 ++ ) {
struct V_98 V_99 =
F_27 ( V_32 , V_81 + 1 ) ;
unsigned V_100 =
F_28 ( V_99 . V_101 ,
V_32 -> V_62 . V_97 ) - 1 ;
if ( V_96 < V_100 )
V_96 =
V_100 ;
}
V_40 -> V_58 [ V_82 ] =
V_102 -
2 * V_96 ;
V_40 -> V_48 [ V_82 ] = 2 ;
for ( V_81 = 0 ; V_81 < V_92 ; V_81 ++ )
V_40 -> V_54 [ V_81 ] =
V_102 ;
} else {
V_40 -> V_58 [ V_82 ] = V_102 ;
V_40 -> V_48 [ V_82 ] = 2 ;
}
break;
case V_26 :
if ( V_82 == F_14 ( V_32 ) ) {
V_40 -> V_58 [ V_82 ] = V_103 ;
V_40 -> V_48 [ V_82 ] = V_103 / 2 ;
for ( V_81 = 0 ; V_81 < V_92 ; V_81 ++ )
V_40 -> V_54 [ V_81 ] =
V_40 -> V_58 [ V_82 ] ;
} else {
V_40 -> V_58 [ V_82 ] = V_103 / 2 ;
V_40 -> V_48 [ V_82 ] = 0 ;
}
break;
case V_28 :
V_40 -> V_58 [ V_82 ] = V_32 -> V_62 . V_104 ;
V_40 -> V_48 [ V_82 ] = 0 ;
if ( V_82 == F_14 ( V_32 ) )
V_40 -> V_55 = V_40 -> V_58 [ V_82 ] ;
break;
default:
break;
}
if ( V_80 == V_25 || V_80 == V_26 ) {
for ( V_81 = 0 ; V_81 < V_32 -> V_62 . V_97 ; V_81 ++ )
if ( F_29 ( V_81 , V_95 . V_105 ) )
V_40 -> V_56 [ V_81 ] +=
V_40 -> V_48 [ V_82 ] ;
} else {
V_40 -> V_57 += V_40 -> V_48 [ V_82 ] ;
}
}
}
F_25 ( & V_38 -> V_41 . V_42 . V_43 . V_106 ) ;
return 0 ;
V_93:
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_46 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_46 = NULL ;
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_48 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_48 = NULL ;
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_58 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_58 = NULL ;
}
return - V_86 ;
}
void F_31 ( struct V_31 * V_32 ,
enum V_107 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_80 ;
if ( V_38 -> V_41 . V_42 . V_43 . V_83 ) {
if ( type != V_108 ) {
for ( V_80 = 0 ; V_80 < V_32 -> V_84 ; V_80 ++ ) {
if ( type == V_109 ||
V_32 -> V_62 . V_110 != V_80 )
F_32 ( V_32 , V_80 ) ;
}
V_80 = V_32 -> V_62 . V_110 ;
F_33 ( V_32 , V_80 ) ;
F_34 ( & V_38 -> V_41 . V_42 . V_43 . V_83 [ V_80 ] . V_89 ) ;
F_35 ( V_32 , V_80 ) ;
F_36 ( & V_38 -> V_41 . V_42 . V_43 . V_83 [ V_80 ] . V_89 ) ;
}
if ( type != V_111 ) {
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_46 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_46 = NULL ;
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_48 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_48 = NULL ;
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_58 ) ;
V_38 -> V_41 . V_42 . V_43 . V_40 [ V_80 ] . V_58 = NULL ;
}
F_30 ( V_38 -> V_41 . V_42 . V_43 . V_83 ) ;
V_38 -> V_41 . V_42 . V_43 . V_83 = NULL ;
}
}
}
static void F_37 ( struct V_31 * V_32 , int V_33 ,
struct V_112 * V_113 )
{
T_2 V_114 = * ( T_2 * ) ( V_113 -> V_115 + 64 ) ;
T_2 V_116 = * ( T_2 * ) ( V_113 -> V_115 + 35 ) ;
T_2 V_117 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
int V_36 ;
V_36 = ( V_114 >> 6 & 1 ) + 1 ;
V_117 = V_38 -> V_118 [ V_33 ] [ V_36 - 1 ] [ V_116 ] ;
* ( T_2 * ) ( V_113 -> V_115 + 35 ) = V_117 ;
}
static void F_38 ( struct V_31 * V_32 , struct V_112 * V_113 ,
T_2 V_33 )
{
struct V_119 * V_120 = V_113 -> V_115 + 8 ;
enum V_121 V_122 = F_39 ( * ( V_123 * ) V_113 -> V_115 ) ;
T_3 V_124 = ( F_39 ( V_120 -> V_125 ) >> 16 ) & 0xff ;
int V_36 ;
if ( V_126 == V_124 ) {
V_36 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( F_40 ( V_32 , V_36 ) )
V_120 -> V_127 . V_129 =
F_41 ( V_32 , V_33 , V_36 ) | 0x80 ;
else
V_120 -> V_127 . V_129 = V_33 | 0x80 ;
} else if ( V_130 == V_124 || V_131 == V_124 || V_132 == V_124 ) {
if ( V_122 & V_133 ) {
V_36 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( F_40 ( V_32 , V_36 ) ) {
V_120 -> V_127 . V_129 +=
F_41 ( V_32 , V_33 , V_36 ) ;
V_120 -> V_127 . V_129 &= 0x7f ;
} else {
V_120 -> V_127 . V_129 = V_33 & 0x7F ;
}
}
if ( V_122 & V_134 ) {
V_36 = ( V_120 -> V_135 . V_128 >> 6 & 1 ) + 1 ;
if ( F_40 ( V_32 , V_36 ) ) {
V_120 -> V_135 . V_129 +=
F_41 ( V_32 , V_33 , V_36 ) ;
V_120 -> V_135 . V_129 &= 0x7f ;
} else {
V_120 -> V_135 . V_129 = V_33 & 0x7F ;
}
}
}
}
static int F_42 ( struct V_31 * V_32 ,
struct V_112 * V_113 ,
T_2 V_33 , T_3 V_136 )
{
struct V_119 * V_137 = V_113 -> V_115 + 8 ;
struct V_138 * V_139 ;
struct V_37 * V_38 ;
T_3 V_140 ;
int V_36 , V_44 = 0 ;
V_36 = ( V_137 -> V_127 . V_128 & 0x40 ) ? 2 : 1 ;
V_38 = V_37 ( V_32 ) ;
V_139 = & V_38 -> V_41 . V_42 . V_141 [ V_33 ] . V_142 [ V_36 ] ;
V_140 = ( F_39 ( V_137 -> V_125 ) >> 16 ) & 0xff ;
if ( V_143 != V_139 -> V_2 . V_144 ) {
if ( F_43 ( V_32 , V_136 ) )
return 0 ;
if ( V_140 == V_126 ||
( V_140 == V_145 && F_40 ( V_32 , V_36 ) ) ) {
if ( V_32 -> V_62 . V_146 & V_147 ) {
* ( V_123 * ) V_113 -> V_115 =
F_44 ( F_39 ( * ( V_123 * ) V_113 -> V_115 ) |
V_148 ) ;
V_137 -> V_149 &= ~ F_44 ( V_150 ) ;
} else {
struct V_151 V_152 = { . V_125 = 0 } ;
V_44 = F_45 ( V_32 , V_136 , V_153 , & V_152 ) ;
if ( V_44 )
goto V_59;
}
}
if ( V_139 -> V_2 . V_154 == V_155 &&
V_32 -> V_62 . V_156 & V_157 ) {
V_137 -> V_127 . V_158 =
V_159 |
V_160 |
V_161 |
V_162 |
V_163 |
V_164 ;
} else if ( 0 != V_139 -> V_2 . V_144 ) {
V_137 -> V_127 . V_158 =
V_159 |
V_162 |
V_163 ;
} else {
V_137 -> V_127 . V_158 =
V_159 |
V_164 ;
}
V_137 -> V_127 . V_165 |= V_166 ;
V_137 -> V_127 . V_167 = V_139 -> V_168 ;
V_137 -> V_127 . V_169 |= V_170 | V_171 ;
V_137 -> V_127 . V_172 |= V_173 | V_174 ;
V_137 -> V_127 . V_128 &= 0xC7 ;
V_137 -> V_127 . V_128 |= ( V_139 -> V_2 . V_175 ) << 3 ;
V_137 -> V_176 = V_139 -> V_2 . V_176 ;
}
if ( V_139 -> V_2 . V_177 ) {
V_137 -> V_127 . V_172 |= V_178 ;
V_137 -> V_127 . V_179 = ( 0x80 & V_137 -> V_127 . V_179 ) + V_139 -> V_180 ;
}
V_59:
return V_44 ;
}
static int F_46 ( struct V_31 * V_32 )
{
return V_32 -> V_62 . V_78 - 1 ;
}
static void * F_47 ( struct V_31 * V_32 , T_1 V_7 ,
enum V_18 type )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
return F_2 ( & V_38 -> V_41 . V_42 . V_43 . V_90 [ type ] ,
V_7 ) ;
}
static int F_48 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type ,
void * V_11 )
{
struct V_10 * V_181 ;
int V_44 = 0 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_47 ( V_32 , V_7 , type ) ;
if ( ! V_181 ) {
V_44 = - V_182 ;
goto exit;
}
if ( V_181 -> V_2 == V_183 ) {
V_44 = - V_184 ;
goto exit;
}
if ( V_181 -> V_185 != V_33 ) {
V_44 = - V_186 ;
goto exit;
}
V_181 -> V_187 = V_181 -> V_2 ;
V_181 -> V_2 = V_183 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_181 ;
exit:
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
int F_52 ( struct V_31 * V_32 ,
enum V_18 type ,
T_1 V_7 , int * V_33 )
{
struct V_10 * V_181 ;
int V_44 = - V_188 ;
int V_189 = V_7 ;
if ( type == V_20 )
V_189 &= 0x7fffff ;
F_9 ( F_50 ( V_32 ) ) ;
V_181 = F_47 ( V_32 , V_189 , type ) ;
if ( V_181 ) {
* V_33 = V_181 -> V_185 ;
V_44 = 0 ;
}
F_11 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static void F_53 ( struct V_31 * V_32 , int V_33 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_181 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_47 ( V_32 , V_7 , type ) ;
if ( V_181 )
V_181 -> V_2 = V_181 -> V_187 ;
F_51 ( F_50 ( V_32 ) ) ;
}
static struct V_10 * F_54 ( int V_189 )
{
struct V_190 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_193 ;
V_191 -> V_194 = V_189 ;
F_21 ( & V_191 -> V_195 ) ;
F_25 ( & V_191 -> V_196 ) ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_56 ( int V_189 , int V_198 )
{
struct V_199 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_198 = V_198 ;
V_191 -> V_192 . V_2 = V_4 ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_57 ( int V_189 , int V_200 )
{
struct V_201 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_202 ;
V_191 -> V_200 = V_200 ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_58 ( int V_189 )
{
struct V_203 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_204 ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_59 ( int V_189 )
{
struct V_205 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_206 ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_60 ( int V_189 )
{
struct V_207 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_208 ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_61 ( int V_189 )
{
struct V_209 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_210 ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_62 ( int V_189 )
{
struct V_211 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_212 ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_63 ( T_1 V_189 , int V_136 )
{
struct V_213 * V_191 ;
V_191 = F_20 ( sizeof *V_191 , V_85 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_7 = V_189 ;
V_191 -> V_192 . V_2 = V_214 ;
V_191 -> V_136 = V_136 ;
return & V_191 -> V_192 ;
}
static struct V_10 * F_64 ( T_1 V_189 , enum V_18 type , int V_33 ,
int V_215 )
{
struct V_10 * V_191 ;
switch ( type ) {
case V_20 :
V_191 = F_54 ( V_189 ) ;
break;
case V_23 :
V_191 = F_57 ( V_189 , V_215 ) ;
break;
case V_24 :
V_191 = F_56 ( V_189 , V_215 ) ;
break;
case V_27 :
V_191 = F_58 ( V_189 ) ;
break;
case V_21 :
V_191 = F_59 ( V_189 ) ;
break;
case V_22 :
V_191 = F_60 ( V_189 ) ;
break;
case V_25 :
F_65 ( L_19 ) ;
return NULL ;
case V_28 :
V_191 = F_61 ( V_189 ) ;
break;
case V_30 :
V_191 = F_62 ( V_189 ) ;
break;
case V_29 :
V_191 = F_63 ( V_189 , V_215 ) ;
break;
default:
return NULL ;
}
if ( V_191 )
V_191 -> V_185 = V_33 ;
return V_191 ;
}
static int F_66 ( struct V_31 * V_32 , int V_33 , T_1 V_216 , int V_35 ,
enum V_18 type , int V_215 )
{
int V_80 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_10 * * V_217 ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_5 * V_6 = & V_219 -> V_90 [ type ] ;
V_217 = F_20 ( V_35 * sizeof *V_217 , V_85 ) ;
if ( ! V_217 )
return - V_86 ;
for ( V_80 = 0 ; V_80 < V_35 ; ++ V_80 ) {
V_217 [ V_80 ] = F_64 ( V_216 + V_80 , type , V_33 , V_215 ) ;
if ( ! V_217 [ V_80 ] ) {
for ( -- V_80 ; V_80 >= 0 ; -- V_80 )
F_30 ( V_217 [ V_80 ] ) ;
F_30 ( V_217 ) ;
return - V_86 ;
}
}
F_49 ( F_50 ( V_32 ) ) ;
for ( V_80 = 0 ; V_80 < V_35 ; ++ V_80 ) {
if ( F_47 ( V_32 , V_216 + V_80 , type ) ) {
V_44 = - V_17 ;
goto V_220;
}
V_44 = F_4 ( V_6 , V_217 [ V_80 ] ) ;
if ( V_44 )
goto V_220;
F_67 ( & V_217 [ V_80 ] -> V_221 ,
& V_219 -> V_83 [ V_33 ] . V_88 [ type ] ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
F_30 ( V_217 ) ;
return 0 ;
V_220:
for ( -- V_80 ; V_80 >= V_216 ; -- V_80 )
F_68 ( & V_217 [ V_80 ] -> V_9 , V_6 ) ;
F_51 ( F_50 ( V_32 ) ) ;
for ( V_80 = 0 ; V_80 < V_35 ; ++ V_80 )
F_30 ( V_217 [ V_80 ] ) ;
F_30 ( V_217 ) ;
return V_44 ;
}
static int F_69 ( struct V_190 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_222 || F_70 ( & V_11 -> V_197 ) ||
! F_71 ( & V_11 -> V_195 ) ) {
F_65 ( L_20 ,
V_11 -> V_192 . V_2 , F_70 ( & V_11 -> V_197 ) ) ;
return - V_184 ;
} else if ( V_11 -> V_192 . V_2 != V_193 ) {
return - V_186 ;
}
return 0 ;
}
static int F_72 ( struct V_199 * V_11 , int V_198 )
{
if ( V_11 -> V_192 . V_2 == V_3 ||
F_70 ( & V_11 -> V_197 ) ) {
F_73 ( L_21 ,
V_223 , __LINE__ ,
F_1 ( V_11 -> V_192 . V_2 ) ,
F_70 ( & V_11 -> V_197 ) ) ;
return - V_184 ;
} else if ( V_11 -> V_192 . V_2 != V_4 )
return - V_186 ;
else if ( V_11 -> V_198 != V_198 )
return - V_45 ;
return 0 ;
}
static int F_74 ( struct V_201 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_224 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_202 )
return - V_186 ;
return 0 ;
}
static int F_75 ( struct V_203 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_224 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_202 )
return - V_186 ;
return 0 ;
}
static int F_76 ( struct V_209 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_225 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_210 )
return - V_186 ;
return 0 ;
}
static int F_77 ( struct V_211 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_226 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_212 )
return - V_186 ;
return 0 ;
}
static int F_78 ( struct V_213 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_227 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_214 )
return - V_186 ;
return 0 ;
}
static int F_79 ( struct V_205 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_228 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_206 )
return - V_186 ;
return 0 ;
}
static int F_80 ( struct V_207 * V_11 )
{
if ( V_11 -> V_192 . V_2 == V_229 )
return - V_184 ;
else if ( V_11 -> V_192 . V_2 != V_208 )
return - V_186 ;
return 0 ;
}
static int F_81 ( struct V_10 * V_11 , enum V_18 type , int V_215 )
{
switch ( type ) {
case V_20 :
return F_69 ( (struct V_190 * ) V_11 ) ;
case V_21 :
return F_79 ( (struct V_205 * ) V_11 ) ;
case V_22 :
return F_80 ( (struct V_207 * ) V_11 ) ;
case V_23 :
return F_74 ( (struct V_201 * ) V_11 ) ;
case V_24 :
return F_72 ( (struct V_199 * ) V_11 , V_215 ) ;
case V_25 :
return - V_230 ;
case V_27 :
return F_75 ( (struct V_203 * ) V_11 ) ;
case V_28 :
return F_76 ( (struct V_209 * ) V_11 ) ;
case V_30 :
return F_77 ( (struct V_211 * ) V_11 ) ;
case V_29 :
return F_78 ( (struct V_213 * ) V_11 ) ;
default:
return - V_45 ;
}
}
static int F_82 ( struct V_31 * V_32 , int V_33 , T_1 V_216 , int V_35 ,
enum V_18 type , int V_215 )
{
T_1 V_80 ;
int V_44 ;
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_181 ;
F_49 ( F_50 ( V_32 ) ) ;
for ( V_80 = V_216 ; V_80 < V_216 + V_35 ; ++ V_80 ) {
V_181 = F_2 ( & V_219 -> V_90 [ type ] , V_80 ) ;
if ( ! V_181 ) {
V_44 = - V_188 ;
goto V_59;
}
if ( V_181 -> V_185 != V_33 ) {
V_44 = - V_186 ;
goto V_59;
}
V_44 = F_81 ( V_181 , type , V_215 ) ;
if ( V_44 )
goto V_59;
}
for ( V_80 = V_216 ; V_80 < V_216 + V_35 ; ++ V_80 ) {
V_181 = F_2 ( & V_219 -> V_90 [ type ] , V_80 ) ;
F_68 ( & V_181 -> V_9 , & V_219 -> V_90 [ type ] ) ;
F_83 ( & V_181 -> V_221 ) ;
F_30 ( V_181 ) ;
}
V_44 = 0 ;
V_59:
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static int F_84 ( struct V_31 * V_32 , int V_33 , int V_136 ,
enum V_231 V_2 , struct V_190 * * V_66 ,
int V_232 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_190 * V_181 ;
int V_44 = 0 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ V_20 ] , V_136 ) ;
if ( ! V_181 )
V_44 = - V_188 ;
else if ( V_181 -> V_192 . V_185 != V_33 )
V_44 = - V_186 ;
else {
switch ( V_2 ) {
case V_222 :
F_23 ( V_32 , L_22 ,
V_223 , V_181 -> V_192 . V_7 ) ;
V_44 = - V_184 ;
break;
case V_193 :
if ( V_181 -> V_192 . V_2 == V_233 && ! V_232 )
break;
F_23 ( V_32 , L_23 , V_181 -> V_192 . V_7 ) ;
V_44 = - V_45 ;
break;
case V_233 :
if ( ( V_181 -> V_192 . V_2 == V_193 && V_232 ) ||
V_181 -> V_192 . V_2 == V_234 )
break;
else {
F_23 ( V_32 , L_23 ,
V_181 -> V_192 . V_7 ) ;
V_44 = - V_45 ;
}
break;
case V_234 :
if ( V_181 -> V_192 . V_2 != V_233 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_222 ;
if ( V_66 )
* V_66 = V_181 ;
}
}
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static int F_85 ( struct V_31 * V_32 , int V_33 , int V_236 ,
enum V_237 V_2 , struct V_201 * * V_77 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_201 * V_181 ;
int V_44 = 0 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ V_23 ] , V_236 ) ;
if ( ! V_181 )
V_44 = - V_188 ;
else if ( V_181 -> V_192 . V_185 != V_33 )
V_44 = - V_186 ;
else {
switch ( V_2 ) {
case V_224 :
V_44 = - V_45 ;
break;
case V_202 :
if ( V_181 -> V_192 . V_2 != V_238 )
V_44 = - V_45 ;
break;
case V_238 :
if ( V_181 -> V_192 . V_2 != V_202 &&
V_181 -> V_192 . V_2 != V_239 )
V_44 = - V_45 ;
break;
case V_239 :
if ( V_181 -> V_192 . V_2 != V_238 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_224 ;
if ( V_77 )
* V_77 = V_181 ;
}
}
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static int F_86 ( struct V_31 * V_32 , int V_33 , int V_236 ,
enum V_240 V_2 , struct V_203 * * V_241 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_203 * V_181 ;
int V_44 = 0 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ V_27 ] , V_236 ) ;
if ( ! V_181 )
V_44 = - V_188 ;
else if ( V_181 -> V_192 . V_185 != V_33 )
V_44 = - V_186 ;
else {
switch ( V_2 ) {
case V_242 :
V_44 = - V_45 ;
break;
case V_204 :
if ( V_181 -> V_192 . V_2 != V_243 )
V_44 = - V_45 ;
break;
case V_243 :
if ( V_181 -> V_192 . V_2 != V_204 )
V_44 = - V_45 ;
break;
default:
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_242 ;
if ( V_241 )
* V_241 = V_181 ;
}
}
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static int F_87 ( struct V_31 * V_32 , int V_33 , int V_244 ,
enum V_245 V_2 , struct V_205 * * V_69 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_205 * V_181 ;
int V_44 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ V_21 ] , V_244 ) ;
if ( ! V_181 ) {
V_44 = - V_188 ;
} else if ( V_181 -> V_192 . V_185 != V_33 ) {
V_44 = - V_186 ;
} else if ( V_2 == V_206 ) {
if ( V_181 -> V_192 . V_2 != V_246 )
V_44 = - V_45 ;
else if ( F_70 ( & V_181 -> V_197 ) )
V_44 = - V_184 ;
else
V_44 = 0 ;
} else if ( V_2 != V_246 || V_181 -> V_192 . V_2 != V_206 ) {
V_44 = - V_45 ;
} else {
V_44 = 0 ;
}
if ( ! V_44 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_228 ;
if ( V_69 )
* V_69 = V_181 ;
}
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static int F_88 ( struct V_31 * V_32 , int V_33 , int V_236 ,
enum V_247 V_2 , struct V_207 * * V_72 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_207 * V_181 ;
int V_44 = 0 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ V_22 ] , V_236 ) ;
if ( ! V_181 ) {
V_44 = - V_188 ;
} else if ( V_181 -> V_192 . V_185 != V_33 ) {
V_44 = - V_186 ;
} else if ( V_2 == V_208 ) {
if ( V_181 -> V_192 . V_2 != V_248 )
V_44 = - V_45 ;
else if ( F_70 ( & V_181 -> V_197 ) )
V_44 = - V_184 ;
} else if ( V_2 != V_248 || V_181 -> V_192 . V_2 != V_208 ) {
V_44 = - V_45 ;
}
if ( ! V_44 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_229 ;
if ( V_72 )
* V_72 = V_181 ;
}
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static void F_89 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_189 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_181 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ type ] , V_189 ) ;
if ( V_181 && ( V_181 -> V_185 == V_33 ) )
V_181 -> V_2 = V_181 -> V_187 ;
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_90 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_189 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_10 * V_181 ;
F_49 ( F_50 ( V_32 ) ) ;
V_181 = F_2 ( & V_219 -> V_90 [ type ] , V_189 ) ;
if ( V_181 && ( V_181 -> V_185 == V_33 ) )
V_181 -> V_2 = V_181 -> V_235 ;
F_51 ( F_50 ( V_32 ) ) ;
}
static int F_91 ( struct V_31 * V_32 , int V_33 , int V_136 )
{
return F_43 ( V_32 , V_136 ) &&
( F_92 ( V_32 ) || F_93 ( V_32 , V_33 , V_136 ) ) ;
}
static int F_94 ( struct V_31 * V_32 , int V_136 )
{
return V_136 < V_32 -> V_62 . V_249 [ V_250 ] ;
}
static int F_95 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_44 ;
int V_35 ;
int V_255 ;
int V_216 ;
int V_136 ;
T_2 V_125 ;
switch ( V_251 ) {
case V_256 :
V_35 = F_96 ( & V_253 ) & 0xffffff ;
V_125 = ( F_96 ( & V_253 ) >> 24 ) & V_32 -> V_62 . V_257 ;
V_255 = F_97 ( & V_253 ) ;
V_44 = F_8 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_98 ( V_32 , V_35 , V_255 , & V_216 , V_125 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
return V_44 ;
}
V_44 = F_66 ( V_32 , V_33 , V_216 , V_35 , V_20 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_99 ( V_32 , V_216 , V_35 ) ;
return V_44 ;
}
F_100 ( V_254 , V_216 ) ;
break;
case V_258 :
V_136 = F_96 ( & V_253 ) & 0x7fffff ;
if ( F_91 ( V_32 , V_33 , V_136 ) ) {
V_44 = F_66 ( V_32 , V_33 , V_136 , 1 , V_20 , 0 ) ;
if ( V_44 )
return V_44 ;
}
V_44 = F_84 ( V_32 , V_33 , V_136 , V_233 ,
NULL , 1 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_94 ( V_32 , V_136 ) ) {
V_44 = F_101 ( V_32 , V_136 , V_85 ) ;
if ( V_44 ) {
F_89 ( V_32 , V_33 , V_20 , V_136 ) ;
return V_44 ;
}
}
F_90 ( V_32 , V_33 , V_20 , V_136 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_102 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_44 = - V_45 ;
int V_216 ;
int V_198 ;
if ( V_251 != V_259 )
return V_44 ;
V_198 = F_96 ( & V_253 ) ;
V_44 = F_8 ( V_32 , V_33 , V_24 , 1 << V_198 , 0 ) ;
if ( V_44 )
return V_44 ;
V_216 = F_103 ( V_32 , V_198 ) ;
if ( V_216 == - 1 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_198 , 0 ) ;
return - V_86 ;
}
V_44 = F_66 ( V_32 , V_33 , V_216 , 1 , V_24 , V_198 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_198 , 0 ) ;
F_104 ( V_32 , V_216 , V_198 ) ;
} else {
F_100 ( V_254 , V_216 ) ;
}
return V_44 ;
}
static int F_105 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_44 = - V_45 ;
int V_236 ;
int V_189 ;
struct V_201 * V_77 ;
switch ( V_251 ) {
case V_256 :
V_44 = F_8 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
if ( V_44 )
break;
V_236 = F_106 ( V_32 ) ;
if ( V_236 == - 1 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
break;
}
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_66 ( V_32 , V_33 , V_189 , 1 , V_23 , V_236 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_107 ( V_32 , V_236 ) ;
break;
}
F_100 ( V_254 , V_236 ) ;
break;
case V_258 :
V_236 = F_96 ( & V_253 ) ;
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_85 ( V_32 , V_33 , V_189 ,
V_238 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_108 ( V_32 , V_77 -> V_200 , V_85 ) ;
if ( V_44 ) {
F_89 ( V_32 , V_33 , V_23 , V_189 ) ;
return V_44 ;
}
F_90 ( V_32 , V_33 , V_23 , V_189 ) ;
break;
}
return V_44 ;
}
static int F_109 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_244 ;
int V_44 ;
switch ( V_251 ) {
case V_259 :
V_44 = F_8 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_110 ( V_32 , & V_244 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
break;
}
V_44 = F_66 ( V_32 , V_33 , V_244 , 1 , V_21 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_111 ( V_32 , V_244 ) ;
break;
}
F_100 ( V_254 , V_244 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_112 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_260 ;
int V_44 ;
switch ( V_251 ) {
case V_259 :
V_44 = F_8 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
if ( V_44 )
break;
V_44 = F_113 ( V_32 , & V_260 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
break;
}
V_44 = F_66 ( V_32 , V_33 , V_260 , 1 , V_22 , 0 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_114 ( V_32 , V_260 ) ;
break;
}
F_100 ( V_254 , V_260 ) ;
break;
default:
V_44 = - V_45 ;
}
return V_44 ;
}
static int F_115 ( struct V_31 * V_32 , int V_33 , int V_36 ,
T_2 V_261 , T_1 * V_262 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_264 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_25 ] ;
struct V_265 * V_11 , * V_266 ;
F_116 (res, tmp, mac_list, list) {
if ( V_11 -> V_261 == V_261 && V_11 -> V_36 == ( T_2 ) V_36 ) {
* V_262 = V_11 -> V_262 ;
return 0 ;
}
}
return - V_188 ;
}
static int F_117 ( struct V_31 * V_32 , int V_33 , T_1 V_262 , int V_36 , T_2 V_261 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_264 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_25 ] ;
struct V_265 * V_11 , * V_266 ;
F_116 (res, tmp, mac_list, list) {
if ( V_11 -> V_262 == V_262 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_197 ;
return 0 ;
}
}
if ( F_8 ( V_32 , V_33 , V_25 , 1 , V_36 ) )
return - V_45 ;
V_11 = F_20 ( sizeof *V_11 , V_85 ) ;
if ( ! V_11 ) {
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
return - V_86 ;
}
V_11 -> V_262 = V_262 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_261 = V_261 ;
V_11 -> V_197 = 1 ;
F_67 ( & V_11 -> V_221 ,
& V_219 -> V_83 [ V_33 ] . V_88 [ V_25 ] ) ;
return 0 ;
}
static void F_118 ( struct V_31 * V_32 , int V_33 , T_1 V_262 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_264 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_25 ] ;
struct V_265 * V_11 , * V_266 ;
F_116 (res, tmp, mac_list, list) {
if ( V_11 -> V_262 == V_262 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_197 ) {
F_83 ( & V_11 -> V_221 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_36 ) ;
F_30 ( V_11 ) ;
}
break;
}
}
}
static void F_119 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_264 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_25 ] ;
struct V_265 * V_11 , * V_266 ;
int V_80 ;
F_116 (res, tmp, mac_list, list) {
F_83 ( & V_11 -> V_221 ) ;
for ( V_80 = 0 ; V_80 < V_11 -> V_197 ; V_80 ++ )
F_120 ( V_32 , V_11 -> V_36 , V_11 -> V_262 ) ;
F_12 ( V_32 , V_33 , V_25 , 1 , V_11 -> V_36 ) ;
F_30 ( V_11 ) ;
}
}
static int F_121 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_267 )
{
int V_44 = - V_45 ;
int V_36 ;
T_1 V_262 ;
T_2 V_261 ;
if ( V_251 != V_259 )
return V_44 ;
V_36 = ! V_267 ? F_96 ( V_254 ) : V_267 ;
V_36 = F_122 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
V_262 = V_253 ;
V_44 = F_123 ( V_32 , V_36 , V_262 ) ;
if ( V_44 >= 0 ) {
V_261 = V_44 ;
F_100 ( V_254 , V_44 ) ;
V_44 = 0 ;
}
if ( ! V_44 ) {
V_44 = F_117 ( V_32 , V_33 , V_262 , V_36 , V_261 ) ;
if ( V_44 )
F_120 ( V_32 , V_36 , V_262 ) ;
}
return V_44 ;
}
static int F_124 ( struct V_31 * V_32 , int V_33 , T_4 V_268 ,
int V_36 , int V_167 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_269 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_26 ] ;
struct V_270 * V_11 , * V_266 ;
F_116 (res, tmp, vlan_list, list) {
if ( V_11 -> V_268 == V_268 && V_11 -> V_36 == ( T_2 ) V_36 ) {
++ V_11 -> V_197 ;
return 0 ;
}
}
if ( F_8 ( V_32 , V_33 , V_26 , 1 , V_36 ) )
return - V_45 ;
V_11 = F_20 ( sizeof( * V_11 ) , V_85 ) ;
if ( ! V_11 ) {
F_12 ( V_32 , V_33 , V_26 , 1 , V_36 ) ;
return - V_86 ;
}
V_11 -> V_268 = V_268 ;
V_11 -> V_36 = ( T_2 ) V_36 ;
V_11 -> V_167 = V_167 ;
V_11 -> V_197 = 1 ;
F_67 ( & V_11 -> V_221 ,
& V_219 -> V_83 [ V_33 ] . V_88 [ V_26 ] ) ;
return 0 ;
}
static void F_125 ( struct V_31 * V_32 , int V_33 , T_4 V_268 ,
int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_269 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_26 ] ;
struct V_270 * V_11 , * V_266 ;
F_116 (res, tmp, vlan_list, list) {
if ( V_11 -> V_268 == V_268 && V_11 -> V_36 == ( T_2 ) V_36 ) {
if ( ! -- V_11 -> V_197 ) {
F_83 ( & V_11 -> V_221 ) ;
F_12 ( V_32 , V_33 , V_26 ,
1 , V_36 ) ;
F_30 ( V_11 ) ;
}
break;
}
}
}
static void F_35 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_269 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_26 ] ;
struct V_270 * V_11 , * V_266 ;
int V_80 ;
F_116 (res, tmp, vlan_list, list) {
F_83 ( & V_11 -> V_221 ) ;
for ( V_80 = 0 ; V_80 < V_11 -> V_197 ; V_80 ++ )
F_126 ( V_32 , V_11 -> V_36 , V_11 -> V_268 ) ;
F_12 ( V_32 , V_33 , V_26 , 1 , V_11 -> V_36 ) ;
F_30 ( V_11 ) ;
}
}
static int F_127 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_267 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_271 * V_272 = V_38 -> V_41 . V_42 . V_272 ;
int V_44 ;
T_4 V_268 ;
int V_167 ;
int V_36 ;
V_36 = ! V_267 ? F_96 ( V_254 ) : V_267 ;
if ( ! V_36 || V_251 != V_259 )
return - V_45 ;
V_36 = F_122 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
if ( ! V_267 && V_36 > 0 && V_36 <= V_32 -> V_62 . V_97 ) {
V_272 [ V_33 ] . V_273 = true ;
return 0 ;
}
V_268 = ( T_4 ) V_253 ;
V_44 = F_128 ( V_32 , V_36 , V_268 , & V_167 ) ;
if ( ! V_44 ) {
F_100 ( V_254 , ( T_3 ) V_167 ) ;
V_44 = F_124 ( V_32 , V_33 , V_268 , V_36 , V_167 ) ;
if ( V_44 )
F_126 ( V_32 , V_36 , V_268 ) ;
}
return V_44 ;
}
static int F_129 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
T_3 V_236 ;
int V_44 ;
if ( V_251 != V_256 )
return - V_45 ;
V_44 = F_8 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_130 ( V_32 , & V_236 ) ;
if ( V_44 ) {
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
V_44 = F_66 ( V_32 , V_33 , V_236 , 1 , V_28 , 0 ) ;
if ( V_44 ) {
F_131 ( V_32 , V_236 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
} else {
F_100 ( V_254 , V_236 ) ;
}
return V_44 ;
}
static int F_132 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
T_3 V_274 ;
int V_44 ;
if ( V_251 != V_256 )
return - V_45 ;
V_44 = F_133 ( V_32 , & V_274 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_66 ( V_32 , V_33 , V_274 , 1 , V_30 , 0 ) ;
if ( V_44 )
F_134 ( V_32 , V_274 ) ;
else
F_100 ( V_254 , V_274 ) ;
return V_44 ;
}
int F_135 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_279 = V_276 -> V_280 ;
switch ( V_276 -> V_281 & 0xFF ) {
case V_20 :
V_44 = F_95 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_24 :
V_44 = F_102 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_23 :
V_44 = F_105 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_21 :
V_44 = F_109 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_22 :
V_44 = F_112 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_25 :
V_44 = F_121 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_127 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_129 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_30 :
V_44 = F_132 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_136 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 )
{
int V_44 ;
int V_35 ;
int V_216 ;
int V_136 ;
switch ( V_251 ) {
case V_256 :
V_216 = F_96 ( & V_253 ) & 0x7fffff ;
V_35 = F_97 ( & V_253 ) ;
V_44 = F_82 ( V_32 , V_33 , V_216 , V_35 , V_20 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_20 , V_35 , 0 ) ;
F_99 ( V_32 , V_216 , V_35 ) ;
break;
case V_258 :
V_136 = F_96 ( & V_253 ) & 0x7fffff ;
V_44 = F_84 ( V_32 , V_33 , V_136 , V_193 ,
NULL , 0 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_94 ( V_32 , V_136 ) )
F_137 ( V_32 , V_136 ) ;
F_90 ( V_32 , V_33 , V_20 , V_136 ) ;
if ( F_91 ( V_32 , V_33 , V_136 ) )
V_44 = F_82 ( V_32 , V_33 , V_136 , 1 , V_20 , 0 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_138 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_44 = - V_45 ;
int V_216 ;
int V_198 ;
if ( V_251 != V_259 )
return V_44 ;
V_216 = F_96 ( & V_253 ) ;
V_198 = F_97 ( & V_253 ) ;
V_44 = F_82 ( V_32 , V_33 , V_216 , 1 , V_24 , V_198 ) ;
if ( ! V_44 ) {
F_12 ( V_32 , V_33 , V_24 , 1 << V_198 , 0 ) ;
F_104 ( V_32 , V_216 , V_198 ) ;
}
return V_44 ;
}
static int F_139 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 )
{
int V_44 = - V_45 ;
int V_236 ;
int V_189 ;
struct V_201 * V_77 ;
switch ( V_251 ) {
case V_256 :
V_236 = F_96 ( & V_253 ) ;
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_48 ( V_32 , V_33 , V_189 , V_23 , & V_77 ) ;
if ( V_44 )
break;
V_236 = V_77 -> V_200 ;
F_53 ( V_32 , V_33 , V_189 , V_23 ) ;
V_44 = F_82 ( V_32 , V_33 , V_189 , 1 , V_23 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_23 , 1 , 0 ) ;
F_107 ( V_32 , V_236 ) ;
break;
case V_258 :
V_236 = F_96 ( & V_253 ) ;
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_85 ( V_32 , V_33 , V_189 ,
V_202 , & V_77 ) ;
if ( V_44 )
return V_44 ;
F_140 ( V_32 , V_77 -> V_200 ) ;
F_90 ( V_32 , V_33 , V_23 , V_189 ) ;
return V_44 ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_141 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_244 ;
int V_44 ;
switch ( V_251 ) {
case V_259 :
V_244 = F_96 ( & V_253 ) ;
V_44 = F_82 ( V_32 , V_33 , V_244 , 1 , V_21 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_21 , 1 , 0 ) ;
F_111 ( V_32 , V_244 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_142 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_260 ;
int V_44 ;
switch ( V_251 ) {
case V_259 :
V_260 = F_96 ( & V_253 ) ;
V_44 = F_82 ( V_32 , V_33 , V_260 , 1 , V_22 , 0 ) ;
if ( V_44 )
break;
F_12 ( V_32 , V_33 , V_22 , 1 , 0 ) ;
F_114 ( V_32 , V_260 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_143 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_267 )
{
int V_36 ;
int V_44 = 0 ;
switch ( V_251 ) {
case V_259 :
V_36 = ! V_267 ? F_96 ( V_254 ) : V_267 ;
V_36 = F_122 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
F_118 ( V_32 , V_33 , V_253 , V_36 ) ;
F_120 ( V_32 , V_36 , V_253 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_144 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_36 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_271 * V_272 = V_38 -> V_41 . V_42 . V_272 ;
int V_44 = 0 ;
V_36 = F_122 (
V_32 , V_33 , V_36 ) ;
if ( V_36 < 0 )
return - V_45 ;
switch ( V_251 ) {
case V_259 :
if ( V_272 [ V_33 ] . V_273 )
return 0 ;
if ( ! V_36 )
return - V_45 ;
F_125 ( V_32 , V_33 , V_253 , V_36 ) ;
F_126 ( V_32 , V_36 , V_253 ) ;
break;
default:
V_44 = - V_45 ;
break;
}
return V_44 ;
}
static int F_145 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_236 ;
int V_44 ;
if ( V_251 != V_256 )
return - V_45 ;
V_236 = F_96 ( & V_253 ) ;
V_44 = F_82 ( V_32 , V_33 , V_236 , 1 , V_28 , 0 ) ;
if ( V_44 )
return V_44 ;
F_131 ( V_32 , V_236 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
return V_44 ;
}
static int F_146 ( struct V_31 * V_32 , int V_33 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_274 ;
int V_44 ;
if ( V_251 != V_256 )
return - V_45 ;
V_274 = F_96 ( & V_253 ) ;
V_44 = F_82 ( V_32 , V_33 , V_274 , 1 , V_30 , 0 ) ;
if ( V_44 )
return V_44 ;
F_134 ( V_32 , V_274 ) ;
return V_44 ;
}
int F_147 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 = - V_45 ;
int V_279 = V_276 -> V_280 ;
switch ( V_276 -> V_281 & 0xFF ) {
case V_20 :
V_44 = F_136 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 ) ;
break;
case V_24 :
V_44 = F_138 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_23 :
V_44 = F_139 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 ) ;
break;
case V_21 :
V_44 = F_141 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_22 :
V_44 = F_142 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_25 :
V_44 = F_143 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_26 :
V_44 = F_144 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_28 :
V_44 = F_145 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_30 :
V_44 = F_146 ( V_32 , V_33 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
default:
break;
}
return V_44 ;
}
static int F_148 ( struct V_282 * V_77 )
{
return ( F_39 ( V_77 -> V_125 ) >> 9 ) & 1 ;
}
static int F_149 ( struct V_282 * V_77 )
{
return ( int ) F_150 ( V_77 -> V_283 ) & 0xfffffff8 ;
}
static int F_151 ( struct V_282 * V_77 )
{
return F_39 ( V_77 -> V_284 ) ;
}
static T_3 F_152 ( struct V_282 * V_77 )
{
return F_39 ( V_77 -> V_285 ) & 0x00ffffff ;
}
static int F_153 ( struct V_282 * V_77 )
{
return F_39 ( V_77 -> V_285 ) & V_286 ;
}
static int F_154 ( struct V_282 * V_77 )
{
return F_39 ( V_77 -> V_125 ) & V_287 ;
}
static int F_155 ( struct V_282 * V_77 )
{
return F_39 ( V_77 -> V_125 ) & V_288 ;
}
static int F_156 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_289 ) & 0xfffffff8 ;
}
static int F_157 ( struct V_290 * V_291 )
{
return F_39 ( V_291 -> V_289 ) & 0xfffffff8 ;
}
static int F_158 ( struct V_119 * V_137 )
{
int V_292 = ( V_137 -> V_293 & 0x3f ) + 12 ;
int V_294 = ( V_137 -> V_295 >> 3 ) & 0xf ;
int V_296 = V_137 -> V_295 & 7 ;
int V_297 = ( V_137 -> V_298 >> 3 ) & 0xf ;
int V_299 = V_137 -> V_298 & 7 ;
int V_72 = ( F_39 ( V_137 -> V_260 ) >> 24 ) & 1 ;
int V_300 = ( F_39 ( V_137 -> V_125 ) >> 13 ) & 1 ;
T_3 V_124 = ( F_39 ( V_137 -> V_125 ) >> 16 ) & 0xff ;
int V_301 = ( V_124 == V_131 ) ? 1 : 0 ;
int V_302 ;
int V_303 ;
int V_304 ;
int V_305 ;
int V_306 = ( F_39 ( V_137 -> V_307 ) >> 6 ) & 0x3f ;
V_302 = 1 << ( V_294 + V_296 + 4 ) ;
V_303 = ( V_72 | V_300 | V_301 ) ? 0 : ( 1 << ( V_297 + V_299 + 4 ) ) ;
V_305 = V_302 + V_303 ;
V_304 =
F_159 ( ( V_305 + ( V_306 << 6 ) ) >>
V_292 ) ;
return V_304 ;
}
static int F_160 ( struct V_31 * V_32 , int V_33 , int V_308 ,
int V_309 , struct V_199 * V_75 )
{
int V_310 = V_75 -> V_192 . V_7 ;
int V_311 = ( 1 << V_75 -> V_198 ) ;
if ( V_308 < V_310 || V_308 + V_309 > V_310 + V_311 )
return - V_186 ;
return 0 ;
}
int F_161 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_236 = V_276 -> V_281 ;
struct V_199 * V_75 ;
struct V_201 * V_77 ;
int V_312 = F_149 ( V_113 -> V_115 ) / V_32 -> V_62 . V_313 ;
int V_314 ;
int V_189 ;
T_3 V_315 ;
int V_316 ;
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_85 ( V_32 , V_33 , V_189 , V_239 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_155 ( V_113 -> V_115 ) ) {
V_44 = - V_186 ;
goto V_317;
}
V_315 = F_152 ( V_113 -> V_115 ) ;
V_316 = ( V_315 >> 17 ) & 0x7f ;
if ( V_316 != 0 && -- V_316 != V_33 ) {
V_44 = - V_186 ;
goto V_317;
}
if ( F_153 ( V_113 -> V_115 ) ) {
if ( F_154 ( V_113 -> V_115 ) ) {
V_44 = - V_186 ;
goto V_317;
}
if ( ! F_155 ( V_113 -> V_115 ) ) {
V_44 = - V_186 ;
goto V_317;
}
}
V_314 = F_148 ( V_113 -> V_115 ) ;
if ( ! V_314 ) {
V_44 = F_48 ( V_32 , V_33 , V_312 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_317;
V_44 = F_160 ( V_32 , V_33 , V_312 ,
F_151 ( V_113 -> V_115 ) , V_75 ) ;
if ( V_44 )
goto V_318;
V_77 -> V_75 = V_75 ;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_318;
if ( ! V_314 ) {
F_163 ( & V_75 -> V_197 ) ;
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
}
F_90 ( V_32 , V_33 , V_23 , V_189 ) ;
return 0 ;
V_318:
if ( ! V_314 )
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
V_317:
F_89 ( V_32 , V_33 , V_23 , V_189 ) ;
return V_44 ;
}
int F_164 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_236 = V_276 -> V_281 ;
struct V_201 * V_77 ;
int V_189 ;
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_85 ( V_32 , V_33 , V_189 , V_238 , & V_77 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_317;
if ( V_77 -> V_75 )
F_165 ( & V_77 -> V_75 -> V_197 ) ;
F_90 ( V_32 , V_33 , V_23 , V_189 ) ;
return 0 ;
V_317:
F_89 ( V_32 , V_33 , V_23 , V_189 ) ;
return V_44 ;
}
int F_166 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_236 = V_276 -> V_281 ;
struct V_201 * V_77 ;
int V_189 ;
V_189 = V_236 & F_46 ( V_32 ) ;
V_44 = F_48 ( V_32 , V_33 , V_189 , V_23 , & V_77 ) ;
if ( V_44 )
return V_44 ;
if ( V_77 -> V_192 . V_187 == V_238 ) {
struct V_282 * V_319 = F_167 (
& V_37 ( V_32 ) -> V_320 . V_321 ,
V_77 -> V_200 , NULL ) ;
if ( NULL == V_319 || NULL == V_277 -> V_115 ) {
V_44 = - V_45 ;
goto V_59;
}
memcpy ( V_277 -> V_115 , V_319 , sizeof( * V_319 ) ) ;
V_44 = 0 ;
} else if ( V_77 -> V_192 . V_187 == V_239 ) {
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
} else {
V_44 = - V_184 ;
goto V_59;
}
V_59:
F_53 ( V_32 , V_33 , V_189 , V_23 ) ;
return V_44 ;
}
static int F_168 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_322 ) & 0xffffff ;
}
static int F_169 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_323 ) & 0xffffff ;
}
static T_3 F_170 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_260 ) & 0x1ffffff ;
}
static void F_171 ( struct V_31 * V_32 , struct V_275 * V_276 ,
struct V_119 * V_324 )
{
T_3 V_136 = V_276 -> V_281 & 0xffffff ;
T_3 V_325 = 0 ;
if ( F_172 ( V_32 , V_136 , & V_325 ) )
return;
V_324 -> V_325 = F_44 ( V_325 ) ;
}
int F_173 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_136 = V_276 -> V_281 & 0x7fffff ;
struct V_199 * V_75 ;
struct V_190 * V_66 ;
struct V_119 * V_137 = V_113 -> V_115 + 8 ;
int V_312 = F_156 ( V_137 ) / V_32 -> V_62 . V_313 ;
int V_326 = F_158 ( V_137 ) ;
struct V_205 * V_327 ;
struct V_205 * V_328 ;
int V_329 = F_168 ( V_137 ) ;
int V_330 = F_169 ( V_137 ) ;
T_3 V_260 = F_170 ( V_137 ) & 0xffffff ;
int V_331 = ( F_170 ( V_137 ) >> 24 ) & 1 ;
struct V_207 * V_72 ;
int V_194 = F_39 ( V_137 -> V_194 ) & 0xffffff ;
V_44 = F_84 ( V_32 , V_33 , V_136 , V_234 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_66 -> V_194 = V_194 ;
V_66 -> V_128 = 0 ;
V_66 -> V_149 = 0 ;
V_66 -> V_158 = 0 ;
V_66 -> V_165 = 0 ;
V_66 -> V_332 = 0 ;
V_66 -> V_167 = 0 ;
V_66 -> V_172 = 0 ;
V_66 -> V_333 = F_39 ( V_137 -> V_125 ) ;
V_44 = F_48 ( V_32 , V_33 , V_312 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_317;
V_44 = F_160 ( V_32 , V_33 , V_312 , V_326 , V_75 ) ;
if ( V_44 )
goto V_334;
V_44 = F_48 ( V_32 , V_33 , V_329 , V_21 , & V_327 ) ;
if ( V_44 )
goto V_334;
if ( V_330 != V_329 ) {
V_44 = F_48 ( V_32 , V_33 , V_330 , V_21 , & V_328 ) ;
if ( V_44 )
goto V_335;
} else
V_328 = V_327 ;
if ( V_331 ) {
V_44 = F_48 ( V_32 , V_33 , V_260 , V_22 , & V_72 ) ;
if ( V_44 )
goto V_336;
}
F_171 ( V_32 , V_276 , V_137 ) ;
F_37 ( V_32 , V_33 , V_113 ) ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_337;
F_163 ( & V_75 -> V_197 ) ;
V_66 -> V_75 = V_75 ;
F_163 ( & V_327 -> V_197 ) ;
V_66 -> V_327 = V_327 ;
F_163 ( & V_328 -> V_197 ) ;
V_66 -> V_328 = V_328 ;
if ( V_330 != V_329 )
F_53 ( V_32 , V_33 , V_330 , V_21 ) ;
if ( V_331 ) {
F_163 ( & V_72 -> V_197 ) ;
F_53 ( V_32 , V_33 , V_260 , V_22 ) ;
V_66 -> V_72 = V_72 ;
}
F_53 ( V_32 , V_33 , V_329 , V_21 ) ;
F_53 ( V_32 , V_33 , V_312 , V_24 ) ;
F_90 ( V_32 , V_33 , V_20 , V_136 ) ;
return 0 ;
V_337:
if ( V_331 )
F_53 ( V_32 , V_33 , V_260 , V_22 ) ;
V_336:
if ( V_330 != V_329 )
F_53 ( V_32 , V_33 , V_330 , V_21 ) ;
V_335:
F_53 ( V_32 , V_33 , V_329 , V_21 ) ;
V_334:
F_53 ( V_32 , V_33 , V_312 , V_24 ) ;
V_317:
F_89 ( V_32 , V_33 , V_20 , V_136 ) ;
return V_44 ;
}
static int F_174 ( struct V_338 * V_339 )
{
return F_39 ( V_339 -> V_289 ) & 0xfffffff8 ;
}
static int F_175 ( struct V_338 * V_339 )
{
int V_340 = V_339 -> V_340 & 0x1f ;
int V_292 = ( V_339 -> V_293 & 0x3f ) + 12 ;
if ( V_340 + 5 < V_292 )
return 1 ;
return 1 << ( V_340 + 5 - V_292 ) ;
}
static int F_176 ( struct V_341 * V_342 )
{
return F_39 ( V_342 -> V_289 ) & 0xfffffff8 ;
}
static int F_177 ( struct V_341 * V_342 )
{
int V_343 = ( F_39 ( V_342 -> V_344 ) >> 24 ) & 0x1f ;
int V_292 = ( V_342 -> V_293 & 0x3f ) + 12 ;
if ( V_343 + 5 < V_292 )
return 1 ;
return 1 << ( V_343 + 5 - V_292 ) ;
}
int F_178 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_345 = V_276 -> V_281 ;
int V_7 = ( V_33 << 10 ) | V_345 ;
struct V_338 * V_339 = V_113 -> V_115 ;
int V_312 = F_174 ( V_339 ) / V_32 -> V_62 . V_313 ;
int V_326 = F_175 ( V_339 ) ;
struct V_203 * V_241 ;
struct V_199 * V_75 ;
V_44 = F_66 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_86 ( V_32 , V_33 , V_7 , V_243 , & V_241 ) ;
if ( V_44 )
goto V_346;
V_44 = F_48 ( V_32 , V_33 , V_312 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_347;
V_44 = F_160 ( V_32 , V_33 , V_312 , V_326 , V_75 ) ;
if ( V_44 )
goto V_348;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_348;
F_163 ( & V_75 -> V_197 ) ;
V_241 -> V_75 = V_75 ;
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
F_90 ( V_32 , V_33 , V_27 , V_7 ) ;
return 0 ;
V_348:
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
V_347:
F_89 ( V_32 , V_33 , V_27 , V_7 ) ;
V_346:
F_82 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return V_44 ;
}
int F_179 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
T_2 V_349 = V_276 -> V_280 ;
if ( V_349 != 1 )
return - V_186 ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
return V_44 ;
}
static int F_180 ( struct V_31 * V_32 , int V_33 , int V_308 ,
int V_350 , struct V_199 * * V_11 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_199 * V_75 ;
int V_44 = - V_45 ;
F_49 ( F_50 ( V_32 ) ) ;
F_181 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_160 ( V_32 , V_33 , V_308 , V_350 , V_75 ) ) {
* V_11 = V_75 ;
V_75 -> V_192 . V_187 = V_75 -> V_192 . V_2 ;
V_75 -> V_192 . V_2 = V_3 ;
V_44 = 0 ;
break;
}
}
F_51 ( F_50 ( V_32 ) ) ;
return V_44 ;
}
static int F_182 ( struct V_31 * V_32 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
enum V_351 V_352 , T_2 V_33 )
{
T_3 V_140 ;
T_3 V_136 ;
struct V_119 * V_120 ;
enum V_121 V_122 ;
int V_36 ;
int V_353 ;
V_120 = V_113 -> V_115 + 8 ;
V_140 = ( F_39 ( V_120 -> V_125 ) >> 16 ) & 0xff ;
V_122 = F_39 ( * ( V_123 * ) V_113 -> V_115 ) ;
if ( V_33 != F_14 ( V_32 ) ) {
V_120 -> V_307 &= ~ V_354 ;
if ( V_120 -> V_355 )
return - V_186 ;
}
switch ( V_140 ) {
case V_130 :
case V_131 :
case V_132 :
switch ( V_352 ) {
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
if ( V_33 != F_14 ( V_32 ) )
if ( V_122 & V_133 ) {
V_36 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_361 [ V_36 ] != V_362 )
V_353 = F_183 ( V_32 , V_33 , V_36 ) ;
else
V_353 = 1 ;
if ( V_120 -> V_127 . V_129 >= V_353 )
return - V_45 ;
}
if ( V_122 & V_134 ) {
V_36 = ( V_120 -> V_135 . V_128 >> 6 & 1 ) + 1 ;
if ( V_32 -> V_62 . V_361 [ V_36 ] != V_362 )
V_353 = F_183 ( V_32 , V_33 , V_36 ) ;
else
V_353 = 1 ;
if ( V_120 -> V_135 . V_129 >= V_353 )
return - V_45 ;
}
break;
default:
break;
}
break;
case V_145 :
V_136 = V_276 -> V_281 & 0x7fffff ;
V_36 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( V_352 == V_356 &&
V_33 != F_14 ( V_32 ) &&
F_43 ( V_32 , V_136 ) &&
! F_184 ( V_32 , V_33 , V_36 ) ) {
F_185 ( V_32 , L_24 ,
V_223 , V_33 , V_36 ) ;
return - V_186 ;
}
break;
default:
break;
}
return 0 ;
}
int F_186 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
struct V_363 V_75 ;
T_5 * V_364 = V_113 -> V_115 ;
T_1 * V_365 = ( T_1 * ) V_364 ;
int V_80 ;
struct V_199 * V_366 = NULL ;
int V_308 = F_150 ( V_364 [ 0 ] ) ;
int V_367 = V_276 -> V_281 ;
int V_44 ;
V_44 = F_180 ( V_32 , V_33 , V_308 , V_367 , & V_366 ) ;
if ( V_44 )
return V_44 ;
V_75 . V_368 = 0 ;
V_75 . V_198 = 0 ;
V_75 . V_292 = 0 ;
for ( V_80 = 0 ; V_80 < V_367 ; ++ V_80 )
V_365 [ V_80 + 2 ] = ( F_150 ( V_364 [ V_80 + 2 ] ) & ~ 1ULL ) ;
V_44 = F_187 ( V_32 , & V_75 , F_150 ( V_364 [ 0 ] ) , V_367 ,
( ( T_1 * ) V_364 + 2 ) ) ;
if ( V_366 )
F_53 ( V_32 , V_33 , V_366 -> V_192 . V_7 , V_24 ) ;
return V_44 ;
}
int F_188 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_345 = V_276 -> V_281 ;
int V_7 = V_345 | ( V_33 << 10 ) ;
struct V_203 * V_241 ;
int V_44 ;
V_44 = F_86 ( V_32 , V_33 , V_7 , V_204 , & V_241 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_241 -> V_75 -> V_192 . V_7 , V_24 , NULL ) ;
if ( V_44 )
goto V_317;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_318;
F_165 ( & V_241 -> V_75 -> V_197 ) ;
F_53 ( V_32 , V_33 , V_241 -> V_75 -> V_192 . V_7 , V_24 ) ;
F_90 ( V_32 , V_33 , V_27 , V_7 ) ;
F_82 ( V_32 , V_33 , V_7 , 1 , V_27 , 0 ) ;
return 0 ;
V_318:
F_53 ( V_32 , V_33 , V_241 -> V_75 -> V_192 . V_7 , V_24 ) ;
V_317:
F_89 ( V_32 , V_33 , V_27 , V_7 ) ;
return V_44 ;
}
int F_189 ( struct V_31 * V_32 , int V_33 , struct V_369 * V_370 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_371 * V_372 ;
struct V_112 * V_373 ;
T_3 V_281 = 0 ;
int V_44 ;
int V_7 ;
struct V_203 * V_374 ;
if ( ! V_38 -> V_41 . V_42 . V_272 )
return - V_45 ;
if ( V_33 < 0 || V_33 > V_32 -> V_51 -> V_52 ||
V_33 == V_32 -> V_62 . V_110 ||
! V_38 -> V_41 . V_42 . V_272 [ V_33 ] . V_375 )
return 0 ;
V_372 = & V_38 -> V_41 . V_42 . V_272 [ V_33 ] . V_372 [ V_370 -> type ] ;
if ( V_372 -> V_345 < 0 )
return 0 ;
F_34 ( & V_38 -> V_41 . V_42 . V_376 [ V_33 ] ) ;
V_7 = ( V_33 << 10 ) | V_372 -> V_345 ;
V_44 = F_48 ( V_32 , V_33 , V_7 , V_27 , & V_374 ) ;
if ( V_44 )
goto V_377;
if ( V_374 -> V_192 . V_187 != V_243 ) {
V_44 = - V_45 ;
goto V_378;
}
V_373 = F_190 ( V_32 ) ;
if ( F_191 ( V_373 ) ) {
V_44 = F_192 ( V_373 ) ;
goto V_378;
}
if ( V_370 -> type == V_379 ) {
++ V_372 -> V_380 ;
V_370 -> V_381 . V_252 . V_380 = F_193 ( V_372 -> V_380 ) ;
}
memcpy ( V_373 -> V_115 , ( T_2 * ) V_370 , 28 ) ;
V_281 = ( V_33 & 0xff ) | ( ( V_372 -> V_345 & 0x3ff ) << 16 ) ;
V_44 = F_194 ( V_32 , V_373 -> V_382 , V_281 , 0 ,
V_383 , V_384 ,
V_385 ) ;
F_53 ( V_32 , V_33 , V_7 , V_27 ) ;
F_36 ( & V_38 -> V_41 . V_42 . V_376 [ V_33 ] ) ;
F_195 ( V_32 , V_373 ) ;
return V_44 ;
V_378:
F_53 ( V_32 , V_33 , V_7 , V_27 ) ;
V_377:
F_36 ( & V_38 -> V_41 . V_42 . V_376 [ V_33 ] ) ;
return V_44 ;
}
int F_196 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_345 = V_276 -> V_281 ;
int V_7 = V_345 | ( V_33 << 10 ) ;
struct V_203 * V_241 ;
int V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_7 , V_27 , & V_241 ) ;
if ( V_44 )
return V_44 ;
if ( V_241 -> V_192 . V_187 != V_243 ) {
V_44 = - V_45 ;
goto V_318;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_318:
F_53 ( V_32 , V_33 , V_7 , V_27 ) ;
return V_44 ;
}
int F_197 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_244 = V_276 -> V_281 ;
struct V_341 * V_342 = V_113 -> V_115 ;
int V_312 = F_176 ( V_342 ) / V_32 -> V_62 . V_313 ;
struct V_205 * V_69 = NULL ;
struct V_199 * V_75 ;
V_44 = F_87 ( V_32 , V_33 , V_244 , V_246 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_312 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_347;
V_44 = F_160 ( V_32 , V_33 , V_312 , F_177 ( V_342 ) , V_75 ) ;
if ( V_44 )
goto V_348;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_348;
F_163 ( & V_75 -> V_197 ) ;
V_69 -> V_75 = V_75 ;
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
F_90 ( V_32 , V_33 , V_21 , V_244 ) ;
return 0 ;
V_348:
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
V_347:
F_89 ( V_32 , V_33 , V_21 , V_244 ) ;
return V_44 ;
}
int F_198 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_244 = V_276 -> V_281 ;
struct V_205 * V_69 = NULL ;
V_44 = F_87 ( V_32 , V_33 , V_244 , V_206 , & V_69 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_347;
F_165 ( & V_69 -> V_75 -> V_197 ) ;
F_90 ( V_32 , V_33 , V_21 , V_244 ) ;
return 0 ;
V_347:
F_89 ( V_32 , V_33 , V_21 , V_244 ) ;
return V_44 ;
}
int F_199 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_244 = V_276 -> V_281 ;
struct V_205 * V_69 ;
int V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_244 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_192 . V_187 != V_246 )
goto V_318;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_318:
F_53 ( V_32 , V_33 , V_244 , V_21 ) ;
return V_44 ;
}
static int F_200 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 ,
struct V_205 * V_69 )
{
int V_44 ;
struct V_199 * V_386 ;
struct V_199 * V_75 ;
struct V_341 * V_342 = V_113 -> V_115 ;
int V_312 = F_176 ( V_342 ) / V_32 -> V_62 . V_313 ;
V_44 = F_48 ( V_32 , V_33 , V_69 -> V_75 -> V_192 . V_7 , V_24 , & V_386 ) ;
if ( V_44 )
return V_44 ;
if ( V_386 != V_69 -> V_75 ) {
V_44 = - V_45 ;
goto V_318;
}
V_44 = F_48 ( V_32 , V_33 , V_312 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_318;
V_44 = F_160 ( V_32 , V_33 , V_312 , F_177 ( V_342 ) , V_75 ) ;
if ( V_44 )
goto V_387;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_387;
F_165 ( & V_386 -> V_197 ) ;
F_53 ( V_32 , V_33 , V_386 -> V_192 . V_7 , V_24 ) ;
F_163 ( & V_75 -> V_197 ) ;
V_69 -> V_75 = V_75 ;
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
return 0 ;
V_387:
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
V_318:
F_53 ( V_32 , V_33 , V_386 -> V_192 . V_7 , V_24 ) ;
return V_44 ;
}
int F_201 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_244 = V_276 -> V_281 ;
struct V_205 * V_69 ;
int V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_244 , V_21 , & V_69 ) ;
if ( V_44 )
return V_44 ;
if ( V_69 -> V_192 . V_187 != V_246 )
goto V_318;
if ( V_276 -> V_280 == 0 ) {
V_44 = F_200 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 , V_69 ) ;
goto V_318;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_318:
F_53 ( V_32 , V_33 , V_244 , V_21 ) ;
return V_44 ;
}
static int F_202 ( struct V_290 * V_291 )
{
int V_388 = ( F_39 ( V_291 -> V_389 ) >> 24 ) & 0xf ;
int V_299 = V_291 -> V_390 & 7 ;
int V_292 = ( V_291 -> V_293 & 0x3f ) + 12 ;
if ( V_388 + V_299 + 4 < V_292 )
return 1 ;
return 1 << ( V_388 + V_299 + 4 - V_292 ) ;
}
int F_203 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_260 = V_276 -> V_281 ;
struct V_199 * V_75 ;
struct V_207 * V_72 = NULL ;
struct V_290 * V_291 = V_113 -> V_115 ;
int V_312 = F_157 ( V_291 ) / V_32 -> V_62 . V_313 ;
if ( V_260 != ( F_39 ( V_291 -> V_389 ) & 0xffffff ) )
return - V_45 ;
V_44 = F_88 ( V_32 , V_33 , V_260 , V_248 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_312 , V_24 , & V_75 ) ;
if ( V_44 )
goto V_317;
V_44 = F_160 ( V_32 , V_33 , V_312 , F_202 ( V_291 ) ,
V_75 ) ;
if ( V_44 )
goto V_334;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_334;
F_163 ( & V_75 -> V_197 ) ;
V_72 -> V_75 = V_75 ;
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
F_90 ( V_32 , V_33 , V_22 , V_260 ) ;
return 0 ;
V_334:
F_53 ( V_32 , V_33 , V_75 -> V_192 . V_7 , V_24 ) ;
V_317:
F_89 ( V_32 , V_33 , V_22 , V_260 ) ;
return V_44 ;
}
int F_204 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_260 = V_276 -> V_281 ;
struct V_207 * V_72 = NULL ;
V_44 = F_88 ( V_32 , V_33 , V_260 , V_208 , & V_72 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_317;
F_165 ( & V_72 -> V_75 -> V_197 ) ;
if ( V_72 -> V_69 )
F_165 ( & V_72 -> V_69 -> V_197 ) ;
F_90 ( V_32 , V_33 , V_22 , V_260 ) ;
return 0 ;
V_317:
F_89 ( V_32 , V_33 , V_22 , V_260 ) ;
return V_44 ;
}
int F_205 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_260 = V_276 -> V_281 ;
struct V_207 * V_72 ;
V_44 = F_48 ( V_32 , V_33 , V_260 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_192 . V_187 != V_248 ) {
V_44 = - V_184 ;
goto V_59;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_59:
F_53 ( V_32 , V_33 , V_260 , V_22 ) ;
return V_44 ;
}
int F_206 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_260 = V_276 -> V_281 ;
struct V_207 * V_72 ;
V_44 = F_48 ( V_32 , V_33 , V_260 , V_22 , & V_72 ) ;
if ( V_44 )
return V_44 ;
if ( V_72 -> V_192 . V_187 != V_248 ) {
V_44 = - V_184 ;
goto V_59;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_59:
F_53 ( V_32 , V_33 , V_260 , V_22 ) ;
return V_44 ;
}
int F_207 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_136 = V_276 -> V_281 & 0x7fffff ;
struct V_190 * V_66 ;
V_44 = F_48 ( V_32 , V_33 , V_136 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_192 . V_187 != V_234 ) {
V_44 = - V_184 ;
goto V_59;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_59:
F_53 ( V_32 , V_33 , V_136 , V_20 ) ;
return V_44 ;
}
int F_208 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
struct V_119 * V_324 = V_113 -> V_115 + 8 ;
F_171 ( V_32 , V_276 , V_324 ) ;
F_37 ( V_32 , V_33 , V_113 ) ;
return F_207 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
}
static int F_209 ( struct V_31 * V_32 , int V_33 ,
struct V_119 * V_137 ,
struct V_112 * V_113 )
{
enum V_121 V_122 = F_39 ( * ( V_123 * ) V_113 -> V_115 ) ;
T_2 V_391 ;
int V_36 = F_122 (
V_32 , V_33 , ( V_137 -> V_127 . V_128 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_391 = ( V_137 -> V_127 . V_128 & ~ ( 1 << 6 ) ) |
( ( V_36 & 1 ) << 6 ) ;
if ( V_122 & V_133 ||
F_40 ( V_32 , V_36 + 1 ) ) {
V_137 -> V_127 . V_128 = V_391 ;
}
if ( V_122 & V_134 ) {
V_36 = F_122 (
V_32 , V_33 , ( V_137 -> V_135 . V_128 >> 6 & 1 )
+ 1 ) - 1 ;
if ( V_36 < 0 )
return - V_45 ;
V_137 -> V_135 . V_128 =
( V_137 -> V_135 . V_128 & ~ ( 1 << 6 ) ) |
( V_36 & 1 ) << 6 ;
}
return 0 ;
}
static int F_210 ( struct V_31 * V_32 , int V_33 ,
struct V_119 * V_137 ,
struct V_112 * V_113 )
{
T_1 V_262 ;
int V_36 ;
T_3 V_124 = ( F_39 ( V_137 -> V_125 ) >> 16 ) & 0xff ;
T_2 V_114 = * ( T_2 * ) ( V_113 -> V_115 + 64 ) ;
T_2 V_392 ;
V_36 = ( V_114 >> 6 & 1 ) + 1 ;
if ( F_40 ( V_32 , V_36 ) && ( V_124 != V_145 ) ) {
V_392 = V_137 -> V_127 . V_179 & 0x7f ;
if ( F_115 ( V_32 , V_33 , V_36 , V_392 , & V_262 ) )
return - V_188 ;
}
return 0 ;
}
int F_211 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
struct V_119 * V_137 = V_113 -> V_115 + 8 ;
int V_136 = V_276 -> V_281 & 0x7fffff ;
struct V_190 * V_66 ;
T_2 V_393 ;
V_123 V_394 = V_137 -> V_149 ;
T_2 V_395 = V_137 -> V_127 . V_158 ;
T_2 V_396 = V_137 -> V_127 . V_165 ;
T_2 V_397 = V_137 -> V_127 . V_169 ;
T_2 V_398 = V_137 -> V_127 . V_167 ;
T_2 V_399 = V_137 -> V_127 . V_172 ;
V_44 = F_209 ( V_32 , V_33 , V_137 , V_113 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_182 ( V_32 , V_276 , V_113 , V_356 , V_33 ) ;
if ( V_44 )
return V_44 ;
if ( F_210 ( V_32 , V_33 , V_137 , V_113 ) )
return - V_45 ;
F_37 ( V_32 , V_33 , V_113 ) ;
F_38 ( V_32 , V_113 , ( T_2 ) V_33 ) ;
F_171 ( V_32 , V_276 , V_137 ) ;
V_393 = V_137 -> V_127 . V_128 ;
V_44 = F_42 ( V_32 , V_113 , V_33 , V_136 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_48 ( V_32 , V_33 , V_136 , V_20 , & V_66 ) ;
if ( V_44 )
return V_44 ;
if ( V_66 -> V_192 . V_187 != V_234 ) {
V_44 = - V_184 ;
goto V_59;
}
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
V_59:
if ( ! V_44 ) {
V_66 -> V_128 = V_393 ;
V_66 -> V_149 = V_394 ;
V_66 -> V_158 = V_395 ;
V_66 -> V_165 = V_396 ;
V_66 -> V_332 = V_397 ;
V_66 -> V_167 = V_398 ;
V_66 -> V_172 = V_399 ;
}
F_53 ( V_32 , V_33 , V_136 , V_20 ) ;
return V_44 ;
}
int F_212 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
struct V_119 * V_324 = V_113 -> V_115 + 8 ;
V_44 = F_209 ( V_32 , V_33 , V_324 , V_113 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_182 ( V_32 , V_276 , V_113 , V_357 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_37 ( V_32 , V_33 , V_113 ) ;
F_38 ( V_32 , V_113 , ( T_2 ) V_33 ) ;
F_171 ( V_32 , V_276 , V_324 ) ;
return F_207 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
}
int F_213 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
struct V_119 * V_324 = V_113 -> V_115 + 8 ;
V_44 = F_209 ( V_32 , V_33 , V_324 , V_113 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_182 ( V_32 , V_276 , V_113 , V_358 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_37 ( V_32 , V_33 , V_113 ) ;
F_38 ( V_32 , V_113 , ( T_2 ) V_33 ) ;
F_171 ( V_32 , V_276 , V_324 ) ;
return F_207 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
}
int F_214 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
struct V_119 * V_324 = V_113 -> V_115 + 8 ;
int V_44 = F_209 ( V_32 , V_33 , V_324 , V_113 ) ;
if ( V_44 )
return V_44 ;
F_171 ( V_32 , V_276 , V_324 ) ;
return F_207 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
}
int F_215 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
struct V_119 * V_324 = V_113 -> V_115 + 8 ;
V_44 = F_209 ( V_32 , V_33 , V_324 , V_113 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_182 ( V_32 , V_276 , V_113 , V_359 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_171 ( V_32 , V_276 , V_324 ) ;
F_38 ( V_32 , V_113 , ( T_2 ) V_33 ) ;
F_37 ( V_32 , V_33 , V_113 ) ;
return F_207 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
}
int F_216 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
struct V_119 * V_324 = V_113 -> V_115 + 8 ;
V_44 = F_209 ( V_32 , V_33 , V_324 , V_113 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_182 ( V_32 , V_276 , V_113 , V_360 , V_33 ) ;
if ( V_44 )
return V_44 ;
F_171 ( V_32 , V_276 , V_324 ) ;
F_38 ( V_32 , V_113 , ( T_2 ) V_33 ) ;
F_37 ( V_32 , V_33 , V_113 ) ;
return F_207 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
}
int F_217 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_136 = V_276 -> V_281 & 0x7fffff ;
struct V_190 * V_66 ;
V_44 = F_84 ( V_32 , V_33 , V_136 , V_233 , & V_66 , 0 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
if ( V_44 )
goto V_317;
F_165 ( & V_66 -> V_75 -> V_197 ) ;
F_165 ( & V_66 -> V_327 -> V_197 ) ;
F_165 ( & V_66 -> V_328 -> V_197 ) ;
if ( V_66 -> V_72 )
F_165 ( & V_66 -> V_72 -> V_197 ) ;
F_90 ( V_32 , V_33 , V_20 , V_136 ) ;
return 0 ;
V_317:
F_89 ( V_32 , V_33 , V_20 , V_136 ) ;
return V_44 ;
}
static struct V_400 * F_218 ( struct V_31 * V_32 , int V_33 ,
struct V_190 * V_401 , T_2 * V_402 )
{
struct V_400 * V_11 ;
F_181 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_402 , V_402 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_219 ( struct V_31 * V_32 , int V_33 , struct V_190 * V_401 ,
T_2 * V_402 , enum V_403 V_404 ,
enum V_405 V_406 , T_1 V_407 )
{
struct V_400 * V_11 ;
int V_44 ;
V_11 = F_20 ( sizeof *V_11 , V_85 ) ;
if ( ! V_11 )
return - V_86 ;
F_49 ( & V_401 -> V_196 ) ;
if ( F_218 ( V_32 , V_33 , V_401 , V_402 ) ) {
F_30 ( V_11 ) ;
V_44 = - V_17 ;
} else {
memcpy ( V_11 -> V_402 , V_402 , 16 ) ;
V_11 -> V_404 = V_404 ;
V_11 -> V_406 = V_406 ;
V_11 -> V_407 = V_407 ;
F_67 ( & V_11 -> V_221 , & V_401 -> V_195 ) ;
V_44 = 0 ;
}
F_51 ( & V_401 -> V_196 ) ;
return V_44 ;
}
static int F_220 ( struct V_31 * V_32 , int V_33 , struct V_190 * V_401 ,
T_2 * V_402 , enum V_403 V_404 ,
enum V_405 V_406 , T_1 * V_407 )
{
struct V_400 * V_11 ;
int V_44 ;
F_49 ( & V_401 -> V_196 ) ;
V_11 = F_218 ( V_32 , V_33 , V_401 , V_402 ) ;
if ( ! V_11 || V_11 -> V_404 != V_404 || V_11 -> V_406 != V_406 )
V_44 = - V_45 ;
else {
* V_407 = V_11 -> V_407 ;
F_83 ( & V_11 -> V_221 ) ;
F_30 ( V_11 ) ;
V_44 = 0 ;
}
F_51 ( & V_401 -> V_196 ) ;
return V_44 ;
}
static int F_221 ( struct V_31 * V_32 , int V_33 , struct V_408 * V_66 ,
T_2 V_402 [ 16 ] , int V_409 , enum V_403 V_404 ,
enum V_405 type , T_1 * V_407 )
{
switch ( V_32 -> V_62 . V_410 ) {
case V_411 : {
int V_36 = F_122 ( V_32 , V_33 , V_402 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return F_222 ( V_32 , V_66 , V_402 , V_36 ,
V_409 , V_404 ,
V_407 ) ;
}
case V_412 :
if ( V_404 == V_413 ) {
int V_36 = F_122 ( V_32 , V_33 , V_402 [ 5 ] ) ;
if ( V_36 < 0 )
return V_36 ;
V_402 [ 5 ] = V_36 ;
}
return F_223 ( V_32 , V_66 , V_402 ,
V_409 , V_404 , type ) ;
default:
return - V_45 ;
}
}
static int F_224 ( struct V_31 * V_32 , struct V_408 * V_66 ,
T_2 V_402 [ 16 ] , enum V_403 V_404 ,
enum V_405 type , T_1 V_407 )
{
switch ( V_32 -> V_62 . V_410 ) {
case V_411 :
return F_225 ( V_32 , V_407 ) ;
case V_412 :
return F_226 ( V_32 , V_66 , V_402 , V_404 , type ) ;
default:
return - V_45 ;
}
}
static int F_227 ( struct V_31 * V_32 , int V_33 ,
T_2 * V_402 , enum V_403 V_404 )
{
int V_414 ;
if ( V_404 != V_413 )
return 0 ;
if ( V_32 -> V_62 . V_410 == V_412 ||
V_32 -> V_62 . V_410 == V_411 ) {
V_414 = F_122 ( V_32 , V_33 , V_402 [ 5 ] ) ;
if ( V_414 < 0 )
return - V_45 ;
V_402 [ 5 ] = V_414 ;
}
return 0 ;
}
int F_228 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
struct V_408 V_66 ;
T_2 * V_402 = V_113 -> V_115 ;
enum V_403 V_404 = ( V_276 -> V_281 >> 28 ) & 0x7 ;
int V_44 ;
int V_136 ;
struct V_190 * V_401 ;
T_1 V_407 = 0 ;
int V_415 = V_276 -> V_280 ;
int V_409 = V_276 -> V_281 >> 31 ;
T_2 V_416 = 2 ;
enum V_405 type = ( V_402 [ 7 ] & V_416 ) >> 1 ;
V_136 = V_276 -> V_281 & 0xffffff ;
V_44 = F_48 ( V_32 , V_33 , V_136 , V_20 , & V_401 ) ;
if ( V_44 )
return V_44 ;
V_66 . V_136 = V_136 ;
if ( V_415 ) {
V_44 = F_221 ( V_32 , V_33 , & V_66 , V_402 , V_409 , V_404 ,
type , & V_407 ) ;
if ( V_44 ) {
F_65 ( L_25 , V_136 ) ;
goto V_318;
}
V_44 = F_219 ( V_32 , V_33 , V_401 , V_402 , V_404 , type , V_407 ) ;
if ( V_44 )
goto V_417;
} else {
V_44 = F_227 ( V_32 , V_33 , V_402 , V_404 ) ;
if ( V_44 )
goto V_318;
V_44 = F_220 ( V_32 , V_33 , V_401 , V_402 , V_404 , type , & V_407 ) ;
if ( V_44 )
goto V_318;
V_44 = F_224 ( V_32 , & V_66 , V_402 , V_404 , type , V_407 ) ;
if ( V_44 )
F_65 ( L_26 ,
V_136 , V_407 ) ;
}
F_53 ( V_32 , V_33 , V_136 , V_20 ) ;
return V_44 ;
V_417:
F_224 ( V_32 , & V_66 , V_402 , V_404 , type , V_407 ) ;
V_318:
F_53 ( V_32 , V_33 , V_136 , V_20 ) ;
return V_44 ;
}
static int F_229 ( int V_33 , struct V_418 * V_419 ,
struct V_263 * V_420 )
{
struct V_265 * V_11 , * V_266 ;
T_5 V_421 ;
if ( ! F_230 ( V_419 -> V_422 . V_423 ) &&
! F_231 ( V_419 -> V_422 . V_423 ) ) {
F_116 (res, tmp, rlist, list) {
V_421 = F_232 ( V_11 -> V_262 << 16 ) ;
if ( F_233 ( ( T_2 * ) & V_421 , V_419 -> V_422 . V_423 ) )
return 0 ;
}
F_65 ( L_27 ,
V_419 -> V_422 . V_423 , V_33 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_234 ( struct V_31 * V_32 , int V_33 ,
struct V_112 * V_113 ,
struct V_263 * V_420 , int V_424 )
{
struct V_265 * V_11 , * V_266 ;
T_2 V_36 ;
struct V_425 * V_426 ;
struct V_427 * V_419 ;
struct V_428 * V_429 ;
struct V_430 * V_431 ;
T_5 V_421 = 0 ;
T_5 V_432 = F_232 ( V_433 << 16 ) ;
V_426 = (struct V_425 * ) V_113 -> V_115 ;
V_36 = V_426 -> V_36 ;
V_419 = (struct V_427 * ) ( V_426 + 1 ) ;
switch ( V_424 ) {
case V_434 :
V_429 =
(struct V_428 * ) ( V_419 + 1 ) ;
memmove ( V_429 , V_419 ,
sizeof( * V_429 ) + sizeof( * V_431 ) ) ;
break;
case V_435 :
case V_436 :
V_431 = (struct V_430 * )
( V_419 + 1 ) ;
memmove ( V_431 , V_419 , sizeof( * V_431 ) ) ;
break;
default:
return - V_45 ;
}
F_116 (res, tmp, rlist, list) {
if ( V_36 == V_11 -> V_36 ) {
V_421 = F_232 ( V_11 -> V_262 << 16 ) ;
break;
}
}
if ( ! V_421 ) {
F_65 ( L_28 ,
V_36 ) ;
return - V_45 ;
}
memset ( V_419 , 0 , sizeof( * V_419 ) ) ;
V_419 -> V_309 = sizeof( * V_419 ) >> 2 ;
V_419 -> V_189 = F_193 ( V_437 [ V_438 ] ) ;
memcpy ( V_419 -> V_423 , & V_421 , V_439 ) ;
memcpy ( V_419 -> V_440 , & V_432 , V_439 ) ;
return 0 ;
}
int F_235 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_441 )
{
int V_44 ;
T_3 V_136 = V_276 -> V_281 & 0xffffff ;
struct V_190 * V_401 ;
T_1 V_262 ;
unsigned V_36 ;
T_1 V_442 ;
struct V_443 * V_252 ;
int V_261 ;
V_252 = (struct V_443 * ) V_113 -> V_115 ;
V_442 = F_150 ( V_252 -> V_444 ) ;
if ( V_252 -> V_445 || V_252 -> V_446 ||
( V_442 & ~ V_447 ) )
return - V_186 ;
V_44 = F_48 ( V_32 , V_33 , V_136 , V_20 , & V_401 ) ;
if ( V_44 ) {
F_185 ( V_32 , L_29 , V_136 , V_33 ) ;
return V_44 ;
}
V_36 = ( V_401 -> V_128 >> 6 & 1 ) + 1 ;
if ( V_442 & ( 1ULL << V_448 ) ) {
V_261 = V_252 -> V_449 . V_127 . V_179 ;
V_44 = F_115 ( V_32 , V_33 , V_36 ,
V_261 , & V_262 ) ;
if ( V_44 ) {
F_185 ( V_32 , L_30 ,
V_136 , V_261 ) ;
goto V_450;
}
}
V_44 = F_194 ( V_32 , V_113 -> V_382 ,
V_276 -> V_281 , 0 ,
V_451 , V_452 ,
V_385 ) ;
if ( V_44 ) {
F_185 ( V_32 , L_31 , V_136 ) ;
goto V_450;
}
V_450:
F_53 ( V_32 , V_33 , V_136 , V_20 ) ;
return V_44 ;
}
int F_236 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_420 = & V_219 -> V_83 [ V_33 ] . V_88 [ V_25 ] ;
int V_44 ;
int V_136 ;
struct V_190 * V_401 ;
struct V_425 * V_426 ;
struct V_418 * V_453 ;
int V_424 ;
if ( V_32 -> V_62 . V_410 !=
V_411 )
return - V_454 ;
V_426 = (struct V_425 * ) V_113 -> V_115 ;
V_426 -> V_36 = F_122 ( V_32 , V_33 , V_426 -> V_36 ) ;
if ( V_426 -> V_36 <= 0 )
return - V_45 ;
V_136 = F_39 ( V_426 -> V_136 ) & 0xffffff ;
V_44 = F_48 ( V_32 , V_33 , V_136 , V_20 , & V_401 ) ;
if ( V_44 ) {
F_65 ( L_32 , V_136 ) ;
return V_44 ;
}
V_453 = (struct V_418 * ) ( V_426 + 1 ) ;
V_424 = F_237 ( F_238 ( V_453 -> V_189 ) ) ;
switch ( V_424 ) {
case V_438 :
if ( F_229 ( V_33 , V_453 , V_420 ) ) {
V_44 = - V_45 ;
goto V_455;
}
break;
case V_456 :
break;
case V_434 :
case V_435 :
case V_436 :
F_239 ( L_33 ) ;
if ( F_234 ( V_32 , V_33 , V_113 , V_420 , V_424 ) ) {
V_44 = - V_45 ;
goto V_455;
}
V_276 -> V_281 +=
sizeof( struct V_427 ) >> 2 ;
break;
default:
F_65 ( L_34 ) ;
V_44 = - V_45 ;
goto V_455;
}
V_44 = F_240 ( V_32 , V_113 -> V_382 , & V_276 -> V_254 ,
V_276 -> V_281 , 0 ,
V_457 , V_452 ,
V_385 ) ;
if ( V_44 )
goto V_455;
V_44 = F_66 ( V_32 , V_33 , V_276 -> V_254 , 1 , V_29 , V_136 ) ;
if ( V_44 ) {
F_185 ( V_32 , L_35 ) ;
F_194 ( V_32 , V_276 -> V_254 , 0 , 0 ,
V_458 , V_452 ,
V_385 ) ;
goto V_455;
}
F_163 ( & V_401 -> V_197 ) ;
V_455:
F_53 ( V_32 , V_33 , V_136 , V_20 ) ;
return V_44 ;
}
int F_241 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
struct V_190 * V_401 ;
struct V_213 * V_459 ;
if ( V_32 -> V_62 . V_410 !=
V_411 )
return - V_454 ;
V_44 = F_48 ( V_32 , V_33 , V_276 -> V_253 , V_29 , & V_459 ) ;
if ( V_44 )
return V_44 ;
F_53 ( V_32 , V_33 , V_276 -> V_253 , V_29 ) ;
V_44 = F_48 ( V_32 , V_33 , V_459 -> V_136 , V_20 , & V_401 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_82 ( V_32 , V_33 , V_276 -> V_253 , 1 , V_29 , 0 ) ;
if ( V_44 ) {
F_185 ( V_32 , L_36 ) ;
goto V_59;
}
V_44 = F_194 ( V_32 , V_276 -> V_253 , 0 , 0 ,
V_458 , V_452 ,
V_385 ) ;
if ( ! V_44 )
F_165 ( & V_401 -> V_197 ) ;
V_59:
F_53 ( V_32 , V_33 , V_459 -> V_136 , V_20 ) ;
return V_44 ;
}
int F_242 ( struct V_31 * V_32 , int V_33 ,
struct V_275 * V_276 ,
struct V_112 * V_113 ,
struct V_112 * V_277 ,
struct V_278 * V_252 )
{
int V_44 ;
int V_236 = V_276 -> V_281 & 0xffff ;
V_44 = F_48 ( V_32 , V_33 , V_236 , V_28 , NULL ) ;
if ( V_44 )
return V_44 ;
V_44 = F_162 ( V_32 , V_33 , V_276 , V_113 , V_277 , V_252 ) ;
F_53 ( V_32 , V_33 , V_236 , V_28 ) ;
return V_44 ;
}
static void F_243 ( struct V_31 * V_32 , int V_33 , struct V_190 * V_401 )
{
struct V_400 * V_460 ;
struct V_400 * V_266 ;
struct V_408 V_66 ;
F_116 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_32 -> V_62 . V_410 ) {
case V_411 :
F_225 ( V_32 , V_460 -> V_407 ) ;
break;
case V_412 :
V_66 . V_136 = V_401 -> V_194 ;
( void ) F_226 ( V_32 , & V_66 , V_460 -> V_402 ,
V_460 -> V_404 , V_460 -> V_406 ) ;
break;
}
F_83 ( & V_460 -> V_221 ) ;
F_30 ( V_460 ) ;
}
}
static int F_244 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type , int V_461 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_420 = & V_219 -> V_83 [ V_33 ] . V_88 [ type ] ;
struct V_10 * V_181 ;
struct V_10 * V_266 ;
int V_462 ;
V_462 = 0 ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (r, tmp, rlist, list) {
if ( V_181 -> V_185 == V_33 ) {
if ( ! V_181 -> V_463 ) {
if ( V_181 -> V_2 == V_183 ) {
if ( V_461 )
F_23 ( V_32 ,
L_37 ,
F_7 ( type ) ,
V_181 -> V_7 ) ;
++ V_462 ;
} else {
V_181 -> V_187 = V_181 -> V_2 ;
V_181 -> V_2 = V_183 ;
V_181 -> V_463 = 1 ;
}
}
}
}
F_51 ( F_50 ( V_32 ) ) ;
return V_462 ;
}
static int F_245 ( struct V_31 * V_32 , int V_33 ,
enum V_18 type )
{
unsigned long V_464 ;
int V_462 ;
V_464 = V_465 ;
do {
V_462 = F_244 ( V_32 , V_33 , type , 0 ) ;
if ( F_246 ( V_465 , V_464 + 5 * V_466 ) )
break;
if ( V_462 )
F_247 () ;
} while ( V_462 );
if ( V_462 )
V_462 = F_244 ( V_32 , V_33 , type , 1 ) ;
return V_462 ;
}
static void F_248 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_467 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_20 ] ;
struct V_190 * V_66 ;
struct V_190 * V_266 ;
int V_2 ;
T_1 V_253 ;
int V_136 ;
int V_44 ;
V_44 = F_245 ( V_32 , V_33 , V_20 ) ;
if ( V_44 )
F_10 ( V_32 , L_38 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (qp, tmp, qp_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_66 -> V_192 . V_185 == V_33 ) {
V_136 = V_66 -> V_192 . V_7 ;
F_243 ( V_32 , V_33 , V_66 ) ;
V_2 = V_66 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_193 :
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_66 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_20 ] ) ;
F_83 ( & V_66 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
if ( ! F_91 ( V_32 , V_33 , V_136 ) ) {
F_99 ( V_32 , V_136 , 1 ) ;
F_12 ( V_32 , V_33 ,
V_20 , 1 , 0 ) ;
}
F_30 ( V_66 ) ;
V_2 = 0 ;
break;
case V_233 :
if ( ! F_91 ( V_32 , V_33 , V_136 ) )
F_137 ( V_32 , V_136 ) ;
V_2 = V_193 ;
break;
case V_234 :
V_253 = V_33 ;
V_44 = F_194 ( V_32 , V_253 ,
V_66 -> V_194 , 2 ,
V_468 ,
V_452 ,
V_385 ) ;
if ( V_44 )
F_23 ( V_32 , L_39 ,
V_33 , V_66 -> V_194 ) ;
F_165 ( & V_66 -> V_327 -> V_197 ) ;
F_165 ( & V_66 -> V_328 -> V_197 ) ;
F_165 ( & V_66 -> V_75 -> V_197 ) ;
if ( V_66 -> V_72 )
F_165 ( & V_66 -> V_72 -> V_197 ) ;
V_2 = V_233 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_249 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_469 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_22 ] ;
struct V_207 * V_72 ;
struct V_207 * V_266 ;
int V_2 ;
T_1 V_253 ;
F_250 ( V_470 ) ;
int V_260 ;
int V_44 ;
V_44 = F_245 ( V_32 , V_33 , V_22 ) ;
if ( V_44 )
F_10 ( V_32 , L_40 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (srq, tmp, srq_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_72 -> V_192 . V_185 == V_33 ) {
V_260 = V_72 -> V_192 . V_7 ;
V_2 = V_72 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_208 :
F_114 ( V_32 , V_260 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_72 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_22 ] ) ;
F_83 ( & V_72 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_22 , 1 , 0 ) ;
F_30 ( V_72 ) ;
V_2 = 0 ;
break;
case V_248 :
V_253 = V_33 ;
V_44 = F_194 ( V_32 , V_253 , V_260 , 1 ,
V_471 ,
V_452 ,
V_385 ) ;
if ( V_44 )
F_23 ( V_32 , L_41 ,
V_33 , V_260 ) ;
F_165 ( & V_72 -> V_75 -> V_197 ) ;
if ( V_72 -> V_69 )
F_165 ( & V_72 -> V_69 -> V_197 ) ;
V_2 = V_208 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_251 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_472 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_21 ] ;
struct V_205 * V_69 ;
struct V_205 * V_266 ;
int V_2 ;
T_1 V_253 ;
F_250 ( V_470 ) ;
int V_244 ;
int V_44 ;
V_44 = F_245 ( V_32 , V_33 , V_21 ) ;
if ( V_44 )
F_10 ( V_32 , L_42 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (cq, tmp, cq_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_69 -> V_192 . V_185 == V_33 && ! F_70 ( & V_69 -> V_197 ) ) {
V_244 = V_69 -> V_192 . V_7 ;
V_2 = V_69 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_206 :
F_111 ( V_32 , V_244 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_69 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_21 ] ) ;
F_83 ( & V_69 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_21 , 1 , 0 ) ;
F_30 ( V_69 ) ;
V_2 = 0 ;
break;
case V_246 :
V_253 = V_33 ;
V_44 = F_194 ( V_32 , V_253 , V_244 , 1 ,
V_473 ,
V_452 ,
V_385 ) ;
if ( V_44 )
F_23 ( V_32 , L_43 ,
V_33 , V_244 ) ;
F_165 ( & V_69 -> V_75 -> V_197 ) ;
V_2 = V_206 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_252 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_474 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_23 ] ;
struct V_201 * V_77 ;
struct V_201 * V_266 ;
int V_2 ;
T_1 V_253 ;
F_250 ( V_470 ) ;
int V_475 ;
int V_44 ;
V_44 = F_245 ( V_32 , V_33 , V_23 ) ;
if ( V_44 )
F_10 ( V_32 , L_44 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (mpt, tmp, mpt_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_77 -> V_192 . V_185 == V_33 ) {
V_475 = V_77 -> V_192 . V_7 ;
V_2 = V_77 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_202 :
F_107 ( V_32 , V_77 -> V_200 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_77 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_23 ] ) ;
F_83 ( & V_77 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
F_12 ( V_32 , V_33 ,
V_23 , 1 , 0 ) ;
F_30 ( V_77 ) ;
V_2 = 0 ;
break;
case V_238 :
F_140 ( V_32 , V_77 -> V_200 ) ;
V_2 = V_202 ;
break;
case V_239 :
V_253 = V_33 ;
V_44 = F_194 ( V_32 , V_253 , V_475 , 0 ,
V_476 ,
V_452 ,
V_385 ) ;
if ( V_44 )
F_23 ( V_32 , L_45 ,
V_33 , V_475 ) ;
if ( V_77 -> V_75 )
F_165 ( & V_77 -> V_75 -> V_197 ) ;
V_2 = V_238 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_253 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_477 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_24 ] ;
struct V_199 * V_75 ;
struct V_199 * V_266 ;
int V_2 ;
F_250 ( V_470 ) ;
int V_216 ;
int V_44 ;
V_44 = F_245 ( V_32 , V_33 , V_24 ) ;
if ( V_44 )
F_10 ( V_32 , L_46 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (mtt, tmp, mtt_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_75 -> V_192 . V_185 == V_33 ) {
V_216 = V_75 -> V_192 . V_7 ;
V_2 = V_75 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_104 ( V_32 , V_216 ,
V_75 -> V_198 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_75 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_24 ] ) ;
F_83 ( & V_75 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
F_12 ( V_32 , V_33 , V_24 ,
1 << V_75 -> V_198 , 0 ) ;
F_30 ( V_75 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_254 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 =
& V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_478 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_29 ] ;
struct V_213 * V_479 ;
struct V_213 * V_266 ;
int V_2 ;
T_1 V_216 ;
int V_44 ;
V_44 = F_245 ( V_32 , V_33 , V_29 ) ;
if ( V_44 )
F_10 ( V_32 , L_47 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (fs_rule, tmp, fs_rule_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_479 -> V_192 . V_185 == V_33 ) {
V_216 = V_479 -> V_192 . V_7 ;
V_2 = V_479 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_214 :
V_44 = F_194 ( V_32 , V_216 , 0 , 0 ,
V_458 ,
V_452 ,
V_385 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_479 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_29 ] ) ;
F_83 ( & V_479 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
F_30 ( V_479 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_255 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_480 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_27 ] ;
struct V_203 * V_241 ;
struct V_203 * V_266 ;
int V_44 ;
int V_2 ;
F_250 ( V_470 ) ;
int V_345 ;
V_44 = F_245 ( V_32 , V_33 , V_27 ) ;
if ( V_44 )
F_10 ( V_32 , L_48 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (eq, tmp, eq_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_241 -> V_192 . V_185 == V_33 ) {
V_345 = V_241 -> V_192 . V_7 ;
V_2 = V_241 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_204 :
F_49 ( F_50 ( V_32 ) ) ;
F_68 ( & V_241 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_27 ] ) ;
F_83 ( & V_241 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_32 ) ) ;
F_30 ( V_241 ) ;
V_2 = 0 ;
break;
case V_243 :
V_44 = F_194 ( V_32 , V_33 , V_345 & 0x3ff ,
1 , V_481 ,
V_452 ,
V_385 ) ;
if ( V_44 )
F_23 ( V_32 , L_49 ,
V_33 , V_345 & 0x3ff ) ;
F_165 ( & V_241 -> V_75 -> V_197 ) ;
V_2 = V_204 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_256 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_482 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_28 ] ;
struct V_209 * V_483 ;
struct V_209 * V_266 ;
int V_44 ;
int V_236 ;
V_44 = F_245 ( V_32 , V_33 , V_28 ) ;
if ( V_44 )
F_10 ( V_32 , L_50 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (counter, tmp, counter_list, com.list) {
if ( V_483 -> V_192 . V_185 == V_33 ) {
V_236 = V_483 -> V_192 . V_7 ;
F_68 ( & V_483 -> V_192 . V_9 ,
& V_219 -> V_90 [ V_28 ] ) ;
F_83 ( & V_483 -> V_192 . V_221 ) ;
F_30 ( V_483 ) ;
F_131 ( V_32 , V_236 ) ;
F_12 ( V_32 , V_33 , V_28 , 1 , 0 ) ;
}
}
F_51 ( F_50 ( V_32 ) ) ;
}
static void F_257 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
struct V_218 * V_219 = & V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_484 =
& V_219 -> V_83 [ V_33 ] . V_88 [ V_30 ] ;
struct V_211 * V_485 ;
struct V_211 * V_266 ;
int V_44 ;
int V_274 ;
V_44 = F_245 ( V_32 , V_33 , V_30 ) ;
if ( V_44 )
F_10 ( V_32 , L_51 ,
V_33 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_485 -> V_192 . V_185 == V_33 ) {
V_274 = V_485 -> V_192 . V_7 ;
F_68 ( & V_485 -> V_192 . V_9 , & V_219 -> V_90 [ V_30 ] ) ;
F_83 ( & V_485 -> V_192 . V_221 ) ;
F_30 ( V_485 ) ;
F_134 ( V_32 , V_274 ) ;
}
}
F_51 ( F_50 ( V_32 ) ) ;
}
void F_32 ( struct V_31 * V_32 , int V_33 )
{
struct V_37 * V_38 = V_37 ( V_32 ) ;
F_33 ( V_32 , V_33 ) ;
F_34 ( & V_38 -> V_41 . V_42 . V_43 . V_83 [ V_33 ] . V_89 ) ;
F_35 ( V_32 , V_33 ) ;
F_119 ( V_32 , V_33 ) ;
F_254 ( V_32 , V_33 ) ;
F_248 ( V_32 , V_33 ) ;
F_249 ( V_32 , V_33 ) ;
F_251 ( V_32 , V_33 ) ;
F_252 ( V_32 , V_33 ) ;
F_255 ( V_32 , V_33 ) ;
F_253 ( V_32 , V_33 ) ;
F_256 ( V_32 , V_33 ) ;
F_257 ( V_32 , V_33 ) ;
F_36 ( & V_38 -> V_41 . V_42 . V_43 . V_83 [ V_33 ] . V_89 ) ;
}
void F_258 ( struct V_486 * V_487 )
{
struct V_488 * V_489 =
F_3 ( V_487 , struct V_488 , V_489 ) ;
struct V_112 * V_373 ;
struct V_443 * V_490 ;
struct V_31 * V_32 = & V_489 -> V_38 -> V_32 ;
struct V_218 * V_219 =
& V_489 -> V_38 -> V_41 . V_42 . V_43 ;
struct V_263 * V_467 =
& V_219 -> V_83 [ V_489 -> V_33 ] . V_88 [ V_20 ] ;
struct V_190 * V_66 ;
struct V_190 * V_266 ;
T_1 V_491 =
( ( 1ULL << V_492 ) |
( 1ULL << V_493 ) |
( 1ULL << V_494 ) |
( 1ULL << V_495 ) |
( 1ULL << V_496 ) |
( 1ULL << V_497 ) ) ;
T_1 V_498 = ( ( 1ULL << V_499 ) |
( 1ULL << V_500 ) |
( 1ULL << V_501 ) |
( 1ULL << V_502 ) |
( 1ULL << V_503 ) |
( 1ULL << V_504 ) |
( 1ULL << V_505 ) ) ;
int V_44 ;
int V_36 , V_506 = 0 ;
T_2 V_158 ;
if ( F_16 ( V_32 ) ) {
F_10 ( V_32 , L_52 ,
V_489 -> V_33 ) ;
goto V_59;
}
V_373 = F_190 ( V_32 ) ;
if ( F_191 ( V_373 ) )
goto V_59;
if ( V_489 -> V_125 & V_507 )
V_158 = V_159 |
V_160 |
V_161 |
V_162 |
V_163 |
V_164 ;
else if ( ! V_489 -> V_508 )
V_158 = V_159 |
V_164 ;
else
V_158 = V_159 |
V_162 |
V_163 ;
V_490 = V_373 -> V_115 ;
V_490 -> V_445 = F_232 ( 1ULL << V_509 ) ;
F_49 ( F_50 ( V_32 ) ) ;
F_116 (qp, tmp, qp_list, com.list) {
F_51 ( F_50 ( V_32 ) ) ;
if ( V_66 -> V_192 . V_185 == V_489 -> V_33 ) {
if ( V_66 -> V_192 . V_187 != V_234 ||
! V_66 -> V_128 ||
F_43 ( V_32 , V_66 -> V_194 ) ||
V_66 -> V_333 & ( 1 << V_510 ) ) {
F_49 ( F_50 ( V_32 ) ) ;
continue;
}
V_36 = ( V_66 -> V_128 >> 6 & 1 ) + 1 ;
if ( V_36 != V_489 -> V_36 ) {
F_49 ( F_50 ( V_32 ) ) ;
continue;
}
if ( V_130 == ( ( V_66 -> V_333 >> 16 ) & 0xff ) )
V_490 -> V_444 = F_232 ( V_498 ) ;
else
V_490 -> V_444 =
F_232 ( V_498 | V_491 ) ;
if ( V_489 -> V_508 == V_143 ) {
V_490 -> V_449 . V_149 = V_66 -> V_149 ;
V_490 -> V_449 . V_127 . V_158 = V_66 -> V_158 ;
V_490 -> V_449 . V_127 . V_165 = V_66 -> V_165 ;
V_490 -> V_449 . V_127 . V_167 = V_66 -> V_167 ;
V_490 -> V_449 . V_127 . V_169 = V_66 -> V_332 ;
V_490 -> V_449 . V_127 . V_172 = V_66 -> V_172 ;
V_490 -> V_449 . V_127 . V_128 =
V_66 -> V_128 ;
} else {
V_490 -> V_449 . V_149 = V_66 -> V_149 & ~ F_44 ( V_150 ) ;
V_490 -> V_449 . V_127 . V_158 = V_158 ;
V_490 -> V_449 . V_127 . V_167 = V_489 -> V_511 ;
V_490 -> V_449 . V_127 . V_165 =
V_66 -> V_165 | V_166 ;
V_490 -> V_449 . V_127 . V_169 =
V_66 -> V_332 | V_170 | V_171 ;
V_490 -> V_449 . V_127 . V_172 =
V_66 -> V_172 | V_173 | V_174 ;
V_490 -> V_449 . V_127 . V_128 =
V_66 -> V_128 & 0xC7 ;
V_490 -> V_449 . V_127 . V_128 |=
( ( V_489 -> V_512 & 0x7 ) << 3 ) ;
V_490 -> V_445 |=
F_232 ( 1ULL <<
V_513 ) ;
V_490 -> V_449 . V_176 =
V_489 -> V_176 ;
}
V_44 = F_194 ( V_32 , V_373 -> V_382 ,
V_66 -> V_194 & 0xffffff ,
0 , V_451 ,
V_514 , V_385 ) ;
if ( V_44 ) {
F_259 ( V_32 , L_53 ,
V_489 -> V_33 , V_36 , V_66 -> V_194 , V_44 ) ;
V_506 ++ ;
}
}
F_49 ( F_50 ( V_32 ) ) ;
}
F_51 ( F_50 ( V_32 ) ) ;
F_195 ( V_32 , V_373 ) ;
if ( V_506 )
F_185 ( V_32 , L_54 ,
V_506 , V_489 -> V_33 , V_489 -> V_36 ) ;
if ( V_489 -> V_125 & V_515 && ! V_506 &&
V_516 != V_489 -> V_517 )
F_126 ( & V_489 -> V_38 -> V_32 , V_489 -> V_36 ,
V_489 -> V_518 ) ;
V_59:
F_30 ( V_489 ) ;
return;
}
