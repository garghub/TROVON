static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
default: return L_3 ;
}
}
static int F_2 ( struct V_5 * V_6 , int V_7 )
{
return V_6 -> V_8 . V_9 [ V_7 ] == V_10 ? 0 : 1 ;
}
static void * F_3 ( struct V_11 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 = V_12 -> V_14 ;
while ( V_15 ) {
struct V_16 * V_17 = F_4 ( V_15 , struct V_16 ,
V_15 ) ;
if ( V_13 < V_17 -> V_13 )
V_15 = V_15 -> V_18 ;
else if ( V_13 > V_17 -> V_13 )
V_15 = V_15 -> V_19 ;
else
return V_17 ;
}
return NULL ;
}
static int F_5 ( struct V_11 * V_12 , struct V_16 * V_17 )
{
struct V_14 * * V_20 = & ( V_12 -> V_14 ) , * V_21 = NULL ;
while ( * V_20 ) {
struct V_16 * V_22 = F_4 ( * V_20 , struct V_16 ,
V_15 ) ;
V_21 = * V_20 ;
if ( V_17 -> V_13 < V_22 -> V_13 )
V_20 = & ( ( * V_20 ) -> V_18 ) ;
else if ( V_17 -> V_13 > V_22 -> V_13 )
V_20 = & ( ( * V_20 ) -> V_19 ) ;
else
return - V_23 ;
}
F_6 ( & V_17 -> V_15 , V_21 , V_20 ) ;
F_7 ( & V_17 -> V_15 , V_12 ) ;
return 0 ;
}
static const char * F_8 ( enum V_24 V_25 )
{
switch ( V_25 ) {
case V_26 : return L_4 ;
case V_27 : return L_5 ;
case V_28 : return L_6 ;
case V_29 : return L_7 ;
case V_30 : return L_8 ;
case V_31 : return L_9 ;
case V_32 : return L_10 ;
case V_33 : return L_11 ;
case V_34 : return L_12 ;
case V_35 : return L_13 ;
case V_36 : return L_14 ;
default: return L_15 ;
} ;
}
static inline int F_9 ( struct V_5 * V_6 , int V_37 ,
enum V_24 V_38 , int V_39 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_42 * V_43 =
& V_41 -> V_44 . V_45 . V_46 . V_43 [ V_38 ] ;
int V_47 = - V_48 ;
int V_49 , free , V_50 , V_51 , V_52 ;
int V_53 ;
if ( V_37 > V_6 -> V_54 )
return - V_48 ;
F_10 ( & V_43 -> V_55 ) ;
V_49 = ( V_7 > 0 ) ?
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_54 + 1 ) + V_37 ] :
V_43 -> V_49 [ V_37 ] ;
free = ( V_7 > 0 ) ? V_43 -> V_56 [ V_7 - 1 ] :
V_43 -> V_57 ;
V_50 = ( V_7 > 0 ) ? V_43 -> V_58 [ V_7 - 1 ] :
V_43 -> V_59 ;
V_51 = V_43 -> V_51 [ V_37 ] ;
if ( V_49 + V_39 > V_43 -> V_60 [ V_37 ] ) {
F_11 ( V_6 , L_16 ,
V_37 , V_7 , F_8 ( V_38 ) , V_39 ,
V_49 , V_43 -> V_60 [ V_37 ] ) ;
goto V_61;
}
if ( V_49 + V_39 <= V_51 ) {
V_47 = 0 ;
V_53 = V_39 ;
} else {
if ( V_51 - V_49 > 0 )
V_52 = V_39 - ( V_51 - V_49 ) ;
else
V_52 = V_39 ;
V_53 = V_39 - V_52 ;
if ( free - V_52 >= V_50 )
V_47 = 0 ;
else
F_11 ( V_6 , L_17 ,
V_37 , V_7 , F_8 ( V_38 ) , free ,
V_52 , V_50 ) ;
}
if ( ! V_47 ) {
if ( V_7 > 0 ) {
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_54 + 1 ) + V_37 ] += V_39 ;
V_43 -> V_56 [ V_7 - 1 ] -= V_39 ;
V_43 -> V_58 [ V_7 - 1 ] -= V_53 ;
} else {
V_43 -> V_49 [ V_37 ] += V_39 ;
V_43 -> V_57 -= V_39 ;
V_43 -> V_59 -= V_53 ;
}
}
V_61:
F_12 ( & V_43 -> V_55 ) ;
return V_47 ;
}
static inline void F_13 ( struct V_5 * V_6 , int V_37 ,
enum V_24 V_38 , int V_39 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_42 * V_43 =
& V_41 -> V_44 . V_45 . V_46 . V_43 [ V_38 ] ;
int V_49 , V_51 , V_53 ;
if ( V_37 > V_6 -> V_54 )
return;
F_10 ( & V_43 -> V_55 ) ;
V_49 = ( V_7 > 0 ) ?
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_54 + 1 ) + V_37 ] :
V_43 -> V_49 [ V_37 ] ;
V_51 = V_43 -> V_51 [ V_37 ] ;
if ( V_49 - V_39 >= V_51 ) {
V_53 = 0 ;
} else {
if ( V_49 - V_51 > 0 )
V_53 = V_39 - ( V_49 - V_51 ) ;
else
V_53 = V_39 ;
}
if ( V_7 > 0 ) {
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_54 + 1 ) + V_37 ] -= V_39 ;
V_43 -> V_56 [ V_7 - 1 ] += V_39 ;
V_43 -> V_58 [ V_7 - 1 ] += V_53 ;
} else {
V_43 -> V_49 [ V_37 ] -= V_39 ;
V_43 -> V_57 += V_39 ;
V_43 -> V_59 += V_53 ;
}
F_12 ( & V_43 -> V_55 ) ;
return;
}
static inline void F_14 ( struct V_5 * V_6 ,
struct V_42 * V_43 ,
enum V_24 V_38 ,
int V_62 , int V_63 )
{
V_43 -> V_51 [ V_62 ] = V_63 / ( 2 * ( V_6 -> V_54 + 1 ) ) ;
V_43 -> V_60 [ V_62 ] = ( V_63 / 2 ) + V_43 -> V_51 [ V_62 ] ;
if ( V_62 == F_15 ( V_6 ) ) {
V_43 -> V_57 = V_63 ;
if ( V_38 == V_30 ) {
V_43 -> V_57 += V_6 -> V_8 . V_64 ;
V_43 -> V_51 [ V_62 ] += V_6 -> V_8 . V_64 ;
V_43 -> V_60 [ V_62 ] += V_6 -> V_8 . V_64 ;
}
}
}
void F_16 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_65 ;
if ( F_17 ( V_6 ) )
return;
if ( ! F_18 ( V_6 ) ) {
V_6 -> V_66 . V_67 = V_6 -> V_8 . V_68 - V_6 -> V_8 . V_69 -
F_19 ( V_6 ) ;
V_6 -> V_66 . V_70 = V_6 -> V_8 . V_71 - V_6 -> V_8 . V_72 ;
V_6 -> V_66 . V_73 = V_6 -> V_8 . V_74 - V_6 -> V_8 . V_75 ;
V_6 -> V_66 . V_76 = V_6 -> V_8 . V_77 - V_6 -> V_8 . V_64 ;
V_6 -> V_66 . V_78 = V_6 -> V_8 . V_79 - V_6 -> V_8 . V_80 ;
return;
}
V_65 = F_15 ( V_6 ) ;
V_6 -> V_66 . V_67 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_26 ] . V_60 [ V_65 ] ;
V_6 -> V_66 . V_70 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_27 ] . V_60 [ V_65 ] ;
V_6 -> V_66 . V_73 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_28 ] . V_60 [ V_65 ] ;
V_6 -> V_66 . V_76 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_30 ] . V_60 [ V_65 ] ;
V_6 -> V_66 . V_78 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_29 ] . V_60 [ V_65 ] ;
}
int F_20 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_81 , V_82 ;
int V_83 ;
V_41 -> V_44 . V_45 . V_46 . V_84 =
F_21 ( V_6 -> V_85 * sizeof( struct V_84 ) ,
V_86 ) ;
if ( ! V_41 -> V_44 . V_45 . V_46 . V_84 )
return - V_87 ;
for ( V_81 = 0 ; V_81 < V_6 -> V_85 ; V_81 ++ ) {
for ( V_83 = 0 ; V_83 < V_88 ; ++ V_83 )
F_22 ( & V_41 -> V_44 . V_45 . V_46 .
V_84 [ V_81 ] . V_89 [ V_83 ] ) ;
F_23 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_81 ] . V_90 ) ;
}
F_24 ( V_6 , L_18 ,
V_6 -> V_85 ) ;
for ( V_81 = 0 ; V_81 < V_88 ; V_81 ++ )
V_41 -> V_44 . V_45 . V_46 . V_91 [ V_81 ] = V_92 ;
for ( V_81 = 0 ; V_81 < V_88 ; V_81 ++ ) {
struct V_42 * V_43 =
& V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] ;
V_43 -> V_60 = F_25 ( ( V_6 -> V_54 + 1 ) * sizeof( int ) , V_86 ) ;
V_43 -> V_51 = F_25 ( ( V_6 -> V_54 + 1 ) * sizeof( int ) , V_86 ) ;
if ( V_81 == V_31 || V_81 == V_32 )
V_43 -> V_49 = F_21 ( V_93 *
( V_6 -> V_54 + 1 ) * sizeof( int ) ,
V_86 ) ;
else
V_43 -> V_49 = F_21 ( ( V_6 -> V_54 + 1 ) * sizeof( int ) , V_86 ) ;
if ( ! V_43 -> V_60 || ! V_43 -> V_51 ||
! V_43 -> V_49 )
goto V_94;
F_26 ( & V_43 -> V_55 ) ;
for ( V_83 = 0 ; V_83 < V_6 -> V_54 + 1 ; V_83 ++ ) {
struct V_95 V_96 =
F_27 ( V_6 , V_83 ) ;
switch ( V_81 ) {
case V_26 :
F_14 ( V_6 , V_43 , V_26 ,
V_83 , V_6 -> V_8 . V_68 -
V_6 -> V_8 . V_69 -
F_19 ( V_6 ) ) ;
break;
case V_27 :
F_14 ( V_6 , V_43 , V_27 ,
V_83 , V_6 -> V_8 . V_71 -
V_6 -> V_8 . V_72 ) ;
break;
case V_28 :
F_14 ( V_6 , V_43 , V_28 ,
V_83 , V_6 -> V_8 . V_74 -
V_6 -> V_8 . V_75 ) ;
break;
case V_29 :
F_14 ( V_6 , V_43 , V_29 ,
V_83 , V_6 -> V_8 . V_79 -
V_6 -> V_8 . V_80 ) ;
break;
case V_30 :
F_14 ( V_6 , V_43 , V_30 ,
V_83 , V_6 -> V_8 . V_77 -
V_6 -> V_8 . V_64 ) ;
break;
case V_31 :
if ( V_83 == F_15 ( V_6 ) ) {
int V_97 = 0 ;
for ( V_82 = 0 ; V_82 < V_6 -> V_8 . V_98 ;
V_82 ++ ) {
struct V_99 V_100 =
F_28 ( V_6 , V_82 + 1 ) ;
unsigned V_101 =
F_29 ( V_100 . V_102 ,
V_6 -> V_8 . V_98 ) - 1 ;
if ( V_97 < V_101 )
V_97 =
V_101 ;
}
V_43 -> V_60 [ V_83 ] =
V_103 -
2 * V_97 ;
V_43 -> V_51 [ V_83 ] = 2 ;
for ( V_82 = 0 ; V_82 < V_93 ; V_82 ++ )
V_43 -> V_56 [ V_82 ] =
V_103 ;
} else {
V_43 -> V_60 [ V_83 ] = V_103 ;
V_43 -> V_51 [ V_83 ] = 2 ;
}
break;
case V_32 :
if ( V_83 == F_15 ( V_6 ) ) {
V_43 -> V_60 [ V_83 ] = V_104 ;
V_43 -> V_51 [ V_83 ] = V_104 / 2 ;
for ( V_82 = 0 ; V_82 < V_93 ; V_82 ++ )
V_43 -> V_56 [ V_82 ] =
V_43 -> V_60 [ V_83 ] ;
} else {
V_43 -> V_60 [ V_83 ] = V_104 / 2 ;
V_43 -> V_51 [ V_83 ] = 0 ;
}
break;
case V_34 :
V_43 -> V_60 [ V_83 ] = V_6 -> V_8 . V_105 ;
V_43 -> V_51 [ V_83 ] = 0 ;
if ( V_83 == F_15 ( V_6 ) )
V_43 -> V_57 = V_43 -> V_60 [ V_83 ] ;
break;
default:
break;
}
if ( V_81 == V_31 || V_81 == V_32 ) {
for ( V_82 = 0 ; V_82 < V_6 -> V_8 . V_98 ; V_82 ++ )
if ( F_30 ( V_82 , V_96 . V_106 ) )
V_43 -> V_58 [ V_82 ] +=
V_43 -> V_51 [ V_83 ] ;
} else {
V_43 -> V_59 += V_43 -> V_51 [ V_83 ] ;
}
}
}
F_26 ( & V_41 -> V_44 . V_45 . V_46 . V_107 ) ;
return 0 ;
V_94:
for ( V_81 = 0 ; V_81 < V_88 ; V_81 ++ ) {
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_49 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_49 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_51 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_51 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_60 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_60 = NULL ;
}
return - V_87 ;
}
void F_32 ( struct V_5 * V_6 ,
enum V_108 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_81 ;
if ( V_41 -> V_44 . V_45 . V_46 . V_84 ) {
if ( type != V_109 ) {
for ( V_81 = 0 ; V_81 < V_6 -> V_85 ; V_81 ++ ) {
if ( type == V_110 ||
V_6 -> V_8 . V_111 != V_81 )
F_33 ( V_6 , V_81 ) ;
}
V_81 = V_6 -> V_8 . V_111 ;
F_34 ( V_6 , V_81 ) ;
F_35 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_81 ] . V_90 ) ;
F_36 ( V_6 , V_81 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_81 ] . V_90 ) ;
}
if ( type != V_112 ) {
for ( V_81 = 0 ; V_81 < V_88 ; V_81 ++ ) {
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_49 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_49 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_51 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_51 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_60 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_81 ] . V_60 = NULL ;
}
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_84 ) ;
V_41 -> V_44 . V_45 . V_46 . V_84 = NULL ;
}
}
}
static void F_38 ( struct V_5 * V_6 , int V_37 ,
struct V_113 * V_114 )
{
T_2 V_115 = * ( T_2 * ) ( V_114 -> V_116 + 64 ) ;
T_2 V_117 = * ( T_2 * ) ( V_114 -> V_116 + 35 ) ;
T_2 V_118 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_7 ;
V_7 = ( V_115 >> 6 & 1 ) + 1 ;
V_118 = V_41 -> V_119 [ V_37 ] [ V_7 - 1 ] [ V_117 ] ;
* ( T_2 * ) ( V_114 -> V_116 + 35 ) = V_118 ;
}
static void F_39 ( struct V_5 * V_6 , struct V_113 * V_114 ,
T_2 V_37 )
{
struct V_120 * V_121 = V_114 -> V_116 + 8 ;
enum V_122 V_123 = F_40 ( * ( V_124 * ) V_114 -> V_116 ) ;
T_3 V_125 = ( F_40 ( V_121 -> V_126 ) >> 16 ) & 0xff ;
int V_7 ;
if ( V_127 == V_125 ) {
V_7 = ( V_121 -> V_128 . V_129 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) )
V_121 -> V_128 . V_130 =
F_41 ( V_6 , V_37 , V_7 ) | 0x80 ;
else
V_121 -> V_128 . V_130 = V_37 | 0x80 ;
} else if ( V_131 == V_125 || V_132 == V_125 || V_133 == V_125 ) {
if ( V_123 & V_134 ) {
V_7 = ( V_121 -> V_128 . V_129 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) ) {
V_121 -> V_128 . V_130 +=
F_41 ( V_6 , V_37 , V_7 ) ;
V_121 -> V_128 . V_130 &= 0x7f ;
} else {
V_121 -> V_128 . V_130 = V_37 & 0x7F ;
}
}
if ( V_123 & V_135 ) {
V_7 = ( V_121 -> V_136 . V_129 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) ) {
V_121 -> V_136 . V_130 +=
F_41 ( V_6 , V_37 , V_7 ) ;
V_121 -> V_136 . V_130 &= 0x7f ;
} else {
V_121 -> V_136 . V_130 = V_37 & 0x7F ;
}
}
}
}
static int F_42 ( struct V_5 * V_6 ,
struct V_113 * V_114 ,
T_2 V_37 , T_3 V_137 )
{
struct V_120 * V_138 = V_114 -> V_116 + 8 ;
struct V_139 * V_140 ;
struct V_40 * V_41 ;
T_3 V_141 ;
int V_7 ;
V_7 = ( V_138 -> V_128 . V_129 & 0x40 ) ? 2 : 1 ;
V_41 = V_40 ( V_6 ) ;
V_140 = & V_41 -> V_44 . V_45 . V_142 [ V_37 ] . V_143 [ V_7 ] ;
V_141 = ( F_40 ( V_138 -> V_126 ) >> 16 ) & 0xff ;
if ( V_144 != V_140 -> V_2 . V_145 ) {
if ( F_43 ( V_6 , V_137 ) )
return 0 ;
if ( V_141 == V_127 ||
( V_141 == V_146 && F_2 ( V_6 , V_7 ) ) ) {
if ( V_6 -> V_8 . V_147 & V_148 ) {
* ( V_124 * ) V_114 -> V_116 =
F_44 ( F_40 ( * ( V_124 * ) V_114 -> V_116 ) |
V_149 ) ;
V_138 -> V_150 &= ~ F_44 ( V_151 ) ;
} else {
struct V_152 V_153 = { . V_126 = 0 } ;
F_45 ( V_6 , V_137 , V_154 , & V_153 ) ;
}
}
if ( V_140 -> V_2 . V_155 == V_156 &&
V_6 -> V_8 . V_157 & V_158 ) {
V_138 -> V_128 . V_159 =
V_160 |
V_161 |
V_162 |
V_163 |
V_164 |
V_165 ;
} else if ( 0 != V_140 -> V_2 . V_145 ) {
V_138 -> V_128 . V_159 =
V_160 |
V_163 |
V_164 ;
} else {
V_138 -> V_128 . V_159 =
V_160 |
V_165 ;
}
V_138 -> V_128 . V_166 |= V_167 ;
V_138 -> V_128 . V_168 = V_140 -> V_169 ;
V_138 -> V_128 . V_170 |= V_171 | V_172 ;
V_138 -> V_128 . V_173 |= V_174 | V_175 ;
V_138 -> V_128 . V_129 &= 0xC7 ;
V_138 -> V_128 . V_129 |= ( V_140 -> V_2 . V_176 ) << 3 ;
}
if ( V_140 -> V_2 . V_177 ) {
V_138 -> V_128 . V_173 |= V_178 ;
V_138 -> V_128 . V_179 = ( 0x80 & V_138 -> V_128 . V_179 ) + V_140 -> V_180 ;
}
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
return V_6 -> V_8 . V_79 - 1 ;
}
static void * F_47 ( struct V_5 * V_6 , T_1 V_13 ,
enum V_24 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
return F_3 ( & V_41 -> V_44 . V_45 . V_46 . V_91 [ type ] ,
V_13 ) ;
}
static int F_48 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type ,
void * V_17 )
{
struct V_16 * V_181 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_47 ( V_6 , V_13 , type ) ;
if ( ! V_181 ) {
V_47 = - V_182 ;
goto exit;
}
if ( V_181 -> V_2 == V_183 ) {
V_47 = - V_184 ;
goto exit;
}
if ( V_181 -> V_185 != V_37 ) {
V_47 = - V_186 ;
goto exit;
}
V_181 -> V_187 = V_181 -> V_2 ;
V_181 -> V_2 = V_183 ;
if ( V_17 )
* ( (struct V_16 * * ) V_17 ) = V_181 ;
exit:
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
int F_52 ( struct V_5 * V_6 ,
enum V_24 type ,
T_1 V_13 , int * V_37 )
{
struct V_16 * V_181 ;
int V_47 = - V_188 ;
int V_189 = V_13 ;
if ( type == V_26 )
V_189 &= 0x7fffff ;
F_10 ( F_50 ( V_6 ) ) ;
V_181 = F_47 ( V_6 , V_189 , type ) ;
if ( V_181 ) {
* V_37 = V_181 -> V_185 ;
V_47 = 0 ;
}
F_12 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static void F_53 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type )
{
struct V_16 * V_181 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_47 ( V_6 , V_13 , type ) ;
if ( V_181 )
V_181 -> V_2 = V_181 -> V_187 ;
F_51 ( F_50 ( V_6 ) ) ;
}
static struct V_16 * F_54 ( int V_189 )
{
struct V_190 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_193 ;
V_191 -> V_194 = V_189 ;
F_22 ( & V_191 -> V_195 ) ;
F_26 ( & V_191 -> V_196 ) ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_56 ( int V_189 , int V_198 )
{
struct V_199 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_198 = V_198 ;
V_191 -> V_192 . V_2 = V_4 ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_57 ( int V_189 , int V_200 )
{
struct V_201 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_202 ;
V_191 -> V_200 = V_200 ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_58 ( int V_189 )
{
struct V_203 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_204 ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_59 ( int V_189 )
{
struct V_205 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_206 ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_60 ( int V_189 )
{
struct V_207 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_208 ;
F_55 ( & V_191 -> V_197 , 0 ) ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_61 ( int V_189 )
{
struct V_209 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_210 ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_62 ( int V_189 )
{
struct V_211 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_212 ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_63 ( T_1 V_189 , int V_137 )
{
struct V_213 * V_191 ;
V_191 = F_21 ( sizeof *V_191 , V_86 ) ;
if ( ! V_191 )
return NULL ;
V_191 -> V_192 . V_13 = V_189 ;
V_191 -> V_192 . V_2 = V_214 ;
V_191 -> V_137 = V_137 ;
return & V_191 -> V_192 ;
}
static struct V_16 * F_64 ( T_1 V_189 , enum V_24 type , int V_37 ,
int V_215 )
{
struct V_16 * V_191 ;
switch ( type ) {
case V_26 :
V_191 = F_54 ( V_189 ) ;
break;
case V_29 :
V_191 = F_57 ( V_189 , V_215 ) ;
break;
case V_30 :
V_191 = F_56 ( V_189 , V_215 ) ;
break;
case V_33 :
V_191 = F_58 ( V_189 ) ;
break;
case V_27 :
V_191 = F_59 ( V_189 ) ;
break;
case V_28 :
V_191 = F_60 ( V_189 ) ;
break;
case V_31 :
F_65 ( L_19 ) ;
return NULL ;
case V_34 :
V_191 = F_61 ( V_189 ) ;
break;
case V_36 :
V_191 = F_62 ( V_189 ) ;
break;
case V_35 :
V_191 = F_63 ( V_189 , V_215 ) ;
break;
default:
return NULL ;
}
if ( V_191 )
V_191 -> V_185 = V_37 ;
return V_191 ;
}
static int F_66 ( struct V_5 * V_6 , int V_37 , T_1 V_216 , int V_39 ,
enum V_24 type , int V_215 )
{
int V_81 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_16 * * V_217 ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_11 * V_12 = & V_219 -> V_91 [ type ] ;
V_217 = F_21 ( V_39 * sizeof *V_217 , V_86 ) ;
if ( ! V_217 )
return - V_87 ;
for ( V_81 = 0 ; V_81 < V_39 ; ++ V_81 ) {
V_217 [ V_81 ] = F_64 ( V_216 + V_81 , type , V_37 , V_215 ) ;
if ( ! V_217 [ V_81 ] ) {
for ( -- V_81 ; V_81 >= 0 ; -- V_81 )
F_31 ( V_217 [ V_81 ] ) ;
F_31 ( V_217 ) ;
return - V_87 ;
}
}
F_49 ( F_50 ( V_6 ) ) ;
for ( V_81 = 0 ; V_81 < V_39 ; ++ V_81 ) {
if ( F_47 ( V_6 , V_216 + V_81 , type ) ) {
V_47 = - V_23 ;
goto V_220;
}
V_47 = F_5 ( V_12 , V_217 [ V_81 ] ) ;
if ( V_47 )
goto V_220;
F_67 ( & V_217 [ V_81 ] -> V_221 ,
& V_219 -> V_84 [ V_37 ] . V_89 [ type ] ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
F_31 ( V_217 ) ;
return 0 ;
V_220:
for ( -- V_81 ; V_81 >= V_216 ; -- V_81 )
F_68 ( & V_217 [ V_81 ] -> V_15 , V_12 ) ;
F_51 ( F_50 ( V_6 ) ) ;
for ( V_81 = 0 ; V_81 < V_39 ; ++ V_81 )
F_31 ( V_217 [ V_81 ] ) ;
F_31 ( V_217 ) ;
return V_47 ;
}
static int F_69 ( struct V_190 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_222 || F_70 ( & V_17 -> V_197 ) ||
! F_71 ( & V_17 -> V_195 ) ) {
F_65 ( L_20 ,
V_17 -> V_192 . V_2 , F_70 ( & V_17 -> V_197 ) ) ;
return - V_184 ;
} else if ( V_17 -> V_192 . V_2 != V_193 ) {
return - V_186 ;
}
return 0 ;
}
static int F_72 ( struct V_199 * V_17 , int V_198 )
{
if ( V_17 -> V_192 . V_2 == V_3 ||
F_70 ( & V_17 -> V_197 ) ) {
F_73 ( L_21 ,
V_223 , __LINE__ ,
F_1 ( V_17 -> V_192 . V_2 ) ,
F_70 ( & V_17 -> V_197 ) ) ;
return - V_184 ;
} else if ( V_17 -> V_192 . V_2 != V_4 )
return - V_186 ;
else if ( V_17 -> V_198 != V_198 )
return - V_48 ;
return 0 ;
}
static int F_74 ( struct V_201 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_224 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_202 )
return - V_186 ;
return 0 ;
}
static int F_75 ( struct V_203 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_224 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_202 )
return - V_186 ;
return 0 ;
}
static int F_76 ( struct V_209 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_225 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_210 )
return - V_186 ;
return 0 ;
}
static int F_77 ( struct V_211 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_226 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_212 )
return - V_186 ;
return 0 ;
}
static int F_78 ( struct V_213 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_227 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_214 )
return - V_186 ;
return 0 ;
}
static int F_79 ( struct V_205 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_228 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_206 )
return - V_186 ;
return 0 ;
}
static int F_80 ( struct V_207 * V_17 )
{
if ( V_17 -> V_192 . V_2 == V_229 )
return - V_184 ;
else if ( V_17 -> V_192 . V_2 != V_208 )
return - V_186 ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 , enum V_24 type , int V_215 )
{
switch ( type ) {
case V_26 :
return F_69 ( (struct V_190 * ) V_17 ) ;
case V_27 :
return F_79 ( (struct V_205 * ) V_17 ) ;
case V_28 :
return F_80 ( (struct V_207 * ) V_17 ) ;
case V_29 :
return F_74 ( (struct V_201 * ) V_17 ) ;
case V_30 :
return F_72 ( (struct V_199 * ) V_17 , V_215 ) ;
case V_31 :
return - V_230 ;
case V_33 :
return F_75 ( (struct V_203 * ) V_17 ) ;
case V_34 :
return F_76 ( (struct V_209 * ) V_17 ) ;
case V_36 :
return F_77 ( (struct V_211 * ) V_17 ) ;
case V_35 :
return F_78 ( (struct V_213 * ) V_17 ) ;
default:
return - V_48 ;
}
}
static int F_82 ( struct V_5 * V_6 , int V_37 , T_1 V_216 , int V_39 ,
enum V_24 type , int V_215 )
{
T_1 V_81 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_181 ;
F_49 ( F_50 ( V_6 ) ) ;
for ( V_81 = V_216 ; V_81 < V_216 + V_39 ; ++ V_81 ) {
V_181 = F_3 ( & V_219 -> V_91 [ type ] , V_81 ) ;
if ( ! V_181 ) {
V_47 = - V_188 ;
goto V_61;
}
if ( V_181 -> V_185 != V_37 ) {
V_47 = - V_186 ;
goto V_61;
}
V_47 = F_81 ( V_181 , type , V_215 ) ;
if ( V_47 )
goto V_61;
}
for ( V_81 = V_216 ; V_81 < V_216 + V_39 ; ++ V_81 ) {
V_181 = F_3 ( & V_219 -> V_91 [ type ] , V_81 ) ;
F_68 ( & V_181 -> V_15 , & V_219 -> V_91 [ type ] ) ;
F_83 ( & V_181 -> V_221 ) ;
F_31 ( V_181 ) ;
}
V_47 = 0 ;
V_61:
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_84 ( struct V_5 * V_6 , int V_37 , int V_137 ,
enum V_231 V_2 , struct V_190 * * V_67 ,
int V_232 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_190 * V_181 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ V_26 ] , V_137 ) ;
if ( ! V_181 )
V_47 = - V_188 ;
else if ( V_181 -> V_192 . V_185 != V_37 )
V_47 = - V_186 ;
else {
switch ( V_2 ) {
case V_222 :
F_24 ( V_6 , L_22 ,
V_223 , V_181 -> V_192 . V_13 ) ;
V_47 = - V_184 ;
break;
case V_193 :
if ( V_181 -> V_192 . V_2 == V_233 && ! V_232 )
break;
F_24 ( V_6 , L_23 , V_181 -> V_192 . V_13 ) ;
V_47 = - V_48 ;
break;
case V_233 :
if ( ( V_181 -> V_192 . V_2 == V_193 && V_232 ) ||
V_181 -> V_192 . V_2 == V_234 )
break;
else {
F_24 ( V_6 , L_23 ,
V_181 -> V_192 . V_13 ) ;
V_47 = - V_48 ;
}
break;
case V_234 :
if ( V_181 -> V_192 . V_2 != V_233 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_222 ;
if ( V_67 )
* V_67 = V_181 ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_85 ( struct V_5 * V_6 , int V_37 , int V_236 ,
enum V_237 V_2 , struct V_201 * * V_78 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_201 * V_181 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ V_29 ] , V_236 ) ;
if ( ! V_181 )
V_47 = - V_188 ;
else if ( V_181 -> V_192 . V_185 != V_37 )
V_47 = - V_186 ;
else {
switch ( V_2 ) {
case V_224 :
V_47 = - V_48 ;
break;
case V_202 :
if ( V_181 -> V_192 . V_2 != V_238 )
V_47 = - V_48 ;
break;
case V_238 :
if ( V_181 -> V_192 . V_2 != V_202 &&
V_181 -> V_192 . V_2 != V_239 )
V_47 = - V_48 ;
break;
case V_239 :
if ( V_181 -> V_192 . V_2 != V_238 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_224 ;
if ( V_78 )
* V_78 = V_181 ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_86 ( struct V_5 * V_6 , int V_37 , int V_236 ,
enum V_240 V_2 , struct V_203 * * V_241 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_203 * V_181 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ V_33 ] , V_236 ) ;
if ( ! V_181 )
V_47 = - V_188 ;
else if ( V_181 -> V_192 . V_185 != V_37 )
V_47 = - V_186 ;
else {
switch ( V_2 ) {
case V_242 :
V_47 = - V_48 ;
break;
case V_204 :
if ( V_181 -> V_192 . V_2 != V_243 )
V_47 = - V_48 ;
break;
case V_243 :
if ( V_181 -> V_192 . V_2 != V_204 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_242 ;
if ( V_241 )
* V_241 = V_181 ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_87 ( struct V_5 * V_6 , int V_37 , int V_244 ,
enum V_245 V_2 , struct V_205 * * V_70 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_205 * V_181 ;
int V_47 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ V_27 ] , V_244 ) ;
if ( ! V_181 ) {
V_47 = - V_188 ;
} else if ( V_181 -> V_192 . V_185 != V_37 ) {
V_47 = - V_186 ;
} else if ( V_2 == V_206 ) {
if ( V_181 -> V_192 . V_2 != V_246 )
V_47 = - V_48 ;
else if ( F_70 ( & V_181 -> V_197 ) )
V_47 = - V_184 ;
else
V_47 = 0 ;
} else if ( V_2 != V_246 || V_181 -> V_192 . V_2 != V_206 ) {
V_47 = - V_48 ;
} else {
V_47 = 0 ;
}
if ( ! V_47 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_228 ;
if ( V_70 )
* V_70 = V_181 ;
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_88 ( struct V_5 * V_6 , int V_37 , int V_236 ,
enum V_247 V_2 , struct V_207 * * V_73 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_207 * V_181 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ V_28 ] , V_236 ) ;
if ( ! V_181 ) {
V_47 = - V_188 ;
} else if ( V_181 -> V_192 . V_185 != V_37 ) {
V_47 = - V_186 ;
} else if ( V_2 == V_208 ) {
if ( V_181 -> V_192 . V_2 != V_248 )
V_47 = - V_48 ;
else if ( F_70 ( & V_181 -> V_197 ) )
V_47 = - V_184 ;
} else if ( V_2 != V_248 || V_181 -> V_192 . V_2 != V_208 ) {
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_181 -> V_192 . V_187 = V_181 -> V_192 . V_2 ;
V_181 -> V_192 . V_235 = V_2 ;
V_181 -> V_192 . V_2 = V_229 ;
if ( V_73 )
* V_73 = V_181 ;
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static void F_89 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_189 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_181 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ type ] , V_189 ) ;
if ( V_181 && ( V_181 -> V_185 == V_37 ) )
V_181 -> V_2 = V_181 -> V_187 ;
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_90 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_189 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_181 ;
F_49 ( F_50 ( V_6 ) ) ;
V_181 = F_3 ( & V_219 -> V_91 [ type ] , V_189 ) ;
if ( V_181 && ( V_181 -> V_185 == V_37 ) )
V_181 -> V_2 = V_181 -> V_235 ;
F_51 ( F_50 ( V_6 ) ) ;
}
static int F_91 ( struct V_5 * V_6 , int V_37 , int V_137 )
{
return F_43 ( V_6 , V_137 ) &&
( F_92 ( V_6 ) || F_93 ( V_6 , V_37 , V_137 ) ) ;
}
static int F_94 ( struct V_5 * V_6 , int V_137 )
{
return V_137 < V_6 -> V_8 . V_249 [ V_250 ] ;
}
static int F_95 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_47 ;
int V_39 ;
int V_255 ;
int V_216 ;
int V_137 ;
T_2 V_126 ;
switch ( V_251 ) {
case V_256 :
V_39 = F_96 ( & V_253 ) & 0xffffff ;
V_126 = ( F_96 ( & V_253 ) >> 24 ) & V_6 -> V_8 . V_257 ;
V_255 = F_97 ( & V_253 ) ;
V_47 = F_9 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_98 ( V_6 , V_39 , V_255 , & V_216 , V_126 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
return V_47 ;
}
V_47 = F_66 ( V_6 , V_37 , V_216 , V_39 , V_26 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_99 ( V_6 , V_216 , V_39 ) ;
return V_47 ;
}
F_100 ( V_254 , V_216 ) ;
break;
case V_258 :
V_137 = F_96 ( & V_253 ) & 0x7fffff ;
if ( F_91 ( V_6 , V_37 , V_137 ) ) {
V_47 = F_66 ( V_6 , V_37 , V_137 , 1 , V_26 , 0 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_84 ( V_6 , V_37 , V_137 , V_233 ,
NULL , 1 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_94 ( V_6 , V_137 ) ) {
V_47 = F_101 ( V_6 , V_137 , V_86 ) ;
if ( V_47 ) {
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
return V_47 ;
}
}
F_90 ( V_6 , V_37 , V_26 , V_137 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_102 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_47 = - V_48 ;
int V_216 ;
int V_198 ;
if ( V_251 != V_259 )
return V_47 ;
V_198 = F_96 ( & V_253 ) ;
V_47 = F_9 ( V_6 , V_37 , V_30 , 1 << V_198 , 0 ) ;
if ( V_47 )
return V_47 ;
V_216 = F_103 ( V_6 , V_198 ) ;
if ( V_216 == - 1 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_198 , 0 ) ;
return - V_87 ;
}
V_47 = F_66 ( V_6 , V_37 , V_216 , 1 , V_30 , V_198 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_198 , 0 ) ;
F_104 ( V_6 , V_216 , V_198 ) ;
} else {
F_100 ( V_254 , V_216 ) ;
}
return V_47 ;
}
static int F_105 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_47 = - V_48 ;
int V_236 ;
int V_189 ;
struct V_201 * V_78 ;
switch ( V_251 ) {
case V_256 :
V_47 = F_9 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
if ( V_47 )
break;
V_236 = F_106 ( V_6 ) ;
if ( V_236 == - 1 ) {
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
break;
}
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_66 ( V_6 , V_37 , V_189 , 1 , V_29 , V_236 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_107 ( V_6 , V_236 ) ;
break;
}
F_100 ( V_254 , V_236 ) ;
break;
case V_258 :
V_236 = F_96 ( & V_253 ) ;
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_189 ,
V_238 , & V_78 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_108 ( V_6 , V_78 -> V_200 , V_86 ) ;
if ( V_47 ) {
F_89 ( V_6 , V_37 , V_29 , V_189 ) ;
return V_47 ;
}
F_90 ( V_6 , V_37 , V_29 , V_189 ) ;
break;
}
return V_47 ;
}
static int F_109 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_244 ;
int V_47 ;
switch ( V_251 ) {
case V_259 :
V_47 = F_9 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_110 ( V_6 , & V_244 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
break;
}
V_47 = F_66 ( V_6 , V_37 , V_244 , 1 , V_27 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_111 ( V_6 , V_244 ) ;
break;
}
F_100 ( V_254 , V_244 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_112 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_260 ;
int V_47 ;
switch ( V_251 ) {
case V_259 :
V_47 = F_9 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_113 ( V_6 , & V_260 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
break;
}
V_47 = F_66 ( V_6 , V_37 , V_260 , 1 , V_28 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_114 ( V_6 , V_260 ) ;
break;
}
F_100 ( V_254 , V_260 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_115 ( struct V_5 * V_6 , int V_37 , int V_7 ,
T_2 V_261 , T_1 * V_262 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_264 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_265 * V_17 , * V_266 ;
F_116 (res, tmp, mac_list, list) {
if ( V_17 -> V_261 == V_261 && V_17 -> V_7 == ( T_2 ) V_7 ) {
* V_262 = V_17 -> V_262 ;
return 0 ;
}
}
return - V_188 ;
}
static int F_117 ( struct V_5 * V_6 , int V_37 , T_1 V_262 , int V_7 , T_2 V_261 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_264 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_265 * V_17 , * V_266 ;
F_116 (res, tmp, mac_list, list) {
if ( V_17 -> V_262 == V_262 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_197 ;
return 0 ;
}
}
if ( F_9 ( V_6 , V_37 , V_31 , 1 , V_7 ) )
return - V_48 ;
V_17 = F_21 ( sizeof *V_17 , V_86 ) ;
if ( ! V_17 ) {
F_13 ( V_6 , V_37 , V_31 , 1 , V_7 ) ;
return - V_87 ;
}
V_17 -> V_262 = V_262 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_261 = V_261 ;
V_17 -> V_197 = 1 ;
F_67 ( & V_17 -> V_221 ,
& V_219 -> V_84 [ V_37 ] . V_89 [ V_31 ] ) ;
return 0 ;
}
static void F_118 ( struct V_5 * V_6 , int V_37 , T_1 V_262 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_264 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_265 * V_17 , * V_266 ;
F_116 (res, tmp, mac_list, list) {
if ( V_17 -> V_262 == V_262 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_197 ) {
F_83 ( & V_17 -> V_221 ) ;
F_13 ( V_6 , V_37 , V_31 , 1 , V_7 ) ;
F_31 ( V_17 ) ;
}
break;
}
}
}
static void F_119 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_264 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_265 * V_17 , * V_266 ;
int V_81 ;
F_116 (res, tmp, mac_list, list) {
F_83 ( & V_17 -> V_221 ) ;
for ( V_81 = 0 ; V_81 < V_17 -> V_197 ; V_81 ++ )
F_120 ( V_6 , V_17 -> V_7 , V_17 -> V_262 ) ;
F_13 ( V_6 , V_37 , V_31 , 1 , V_17 -> V_7 ) ;
F_31 ( V_17 ) ;
}
}
static int F_121 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_267 )
{
int V_47 = - V_48 ;
int V_7 ;
T_1 V_262 ;
T_2 V_261 ;
if ( V_251 != V_259 )
return V_47 ;
V_7 = ! V_267 ? F_96 ( V_254 ) : V_267 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
V_262 = V_253 ;
V_47 = F_123 ( V_6 , V_7 , V_262 ) ;
if ( V_47 >= 0 ) {
V_261 = V_47 ;
F_100 ( V_254 , V_47 ) ;
V_47 = 0 ;
}
if ( ! V_47 ) {
V_47 = F_117 ( V_6 , V_37 , V_262 , V_7 , V_261 ) ;
if ( V_47 )
F_120 ( V_6 , V_7 , V_262 ) ;
}
return V_47 ;
}
static int F_124 ( struct V_5 * V_6 , int V_37 , T_4 V_268 ,
int V_7 , int V_168 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_269 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_32 ] ;
struct V_270 * V_17 , * V_266 ;
F_116 (res, tmp, vlan_list, list) {
if ( V_17 -> V_268 == V_268 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_197 ;
return 0 ;
}
}
if ( F_9 ( V_6 , V_37 , V_32 , 1 , V_7 ) )
return - V_48 ;
V_17 = F_21 ( sizeof( * V_17 ) , V_86 ) ;
if ( ! V_17 ) {
F_13 ( V_6 , V_37 , V_32 , 1 , V_7 ) ;
return - V_87 ;
}
V_17 -> V_268 = V_268 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_168 = V_168 ;
V_17 -> V_197 = 1 ;
F_67 ( & V_17 -> V_221 ,
& V_219 -> V_84 [ V_37 ] . V_89 [ V_32 ] ) ;
return 0 ;
}
static void F_125 ( struct V_5 * V_6 , int V_37 , T_4 V_268 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_269 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_32 ] ;
struct V_270 * V_17 , * V_266 ;
F_116 (res, tmp, vlan_list, list) {
if ( V_17 -> V_268 == V_268 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_197 ) {
F_83 ( & V_17 -> V_221 ) ;
F_13 ( V_6 , V_37 , V_32 ,
1 , V_7 ) ;
F_31 ( V_17 ) ;
}
break;
}
}
}
static void F_36 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_269 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_32 ] ;
struct V_270 * V_17 , * V_266 ;
int V_81 ;
F_116 (res, tmp, vlan_list, list) {
F_83 ( & V_17 -> V_221 ) ;
for ( V_81 = 0 ; V_81 < V_17 -> V_197 ; V_81 ++ )
F_126 ( V_6 , V_17 -> V_7 , V_17 -> V_268 ) ;
F_13 ( V_6 , V_37 , V_32 , 1 , V_17 -> V_7 ) ;
F_31 ( V_17 ) ;
}
}
static int F_127 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_267 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_271 * V_272 = V_41 -> V_44 . V_45 . V_272 ;
int V_47 ;
T_4 V_268 ;
int V_168 ;
int V_7 ;
V_7 = ! V_267 ? F_96 ( V_254 ) : V_267 ;
if ( ! V_7 || V_251 != V_259 )
return - V_48 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
if ( ! V_267 && V_7 > 0 && V_7 <= V_6 -> V_8 . V_98 ) {
V_272 [ V_37 ] . V_273 = true ;
return 0 ;
}
V_268 = ( T_4 ) V_253 ;
V_47 = F_128 ( V_6 , V_7 , V_268 , & V_168 ) ;
if ( ! V_47 ) {
F_100 ( V_254 , ( T_3 ) V_168 ) ;
V_47 = F_124 ( V_6 , V_37 , V_268 , V_7 , V_168 ) ;
if ( V_47 )
F_126 ( V_6 , V_7 , V_268 ) ;
}
return V_47 ;
}
static int F_129 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
T_3 V_236 ;
int V_47 ;
if ( V_251 != V_256 )
return - V_48 ;
V_47 = F_9 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_130 ( V_6 , & V_236 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
V_47 = F_66 ( V_6 , V_37 , V_236 , 1 , V_34 , 0 ) ;
if ( V_47 ) {
F_131 ( V_6 , V_236 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
} else {
F_100 ( V_254 , V_236 ) ;
}
return V_47 ;
}
static int F_132 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
T_3 V_274 ;
int V_47 ;
if ( V_251 != V_256 )
return - V_48 ;
V_47 = F_133 ( V_6 , & V_274 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_66 ( V_6 , V_37 , V_274 , 1 , V_36 , 0 ) ;
if ( V_47 )
F_134 ( V_6 , V_274 ) ;
else
F_100 ( V_254 , V_274 ) ;
return V_47 ;
}
int F_135 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_279 = V_276 -> V_280 ;
switch ( V_276 -> V_281 & 0xFF ) {
case V_26 :
V_47 = F_95 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_30 :
V_47 = F_102 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_29 :
V_47 = F_105 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_27 :
V_47 = F_109 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_28 :
V_47 = F_112 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_31 :
V_47 = F_121 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_127 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_129 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_36 :
V_47 = F_132 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_136 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 )
{
int V_47 ;
int V_39 ;
int V_216 ;
int V_137 ;
switch ( V_251 ) {
case V_256 :
V_216 = F_96 ( & V_253 ) & 0x7fffff ;
V_39 = F_97 ( & V_253 ) ;
V_47 = F_82 ( V_6 , V_37 , V_216 , V_39 , V_26 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_99 ( V_6 , V_216 , V_39 ) ;
break;
case V_258 :
V_137 = F_96 ( & V_253 ) & 0x7fffff ;
V_47 = F_84 ( V_6 , V_37 , V_137 , V_193 ,
NULL , 0 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_94 ( V_6 , V_137 ) )
F_137 ( V_6 , V_137 ) ;
F_90 ( V_6 , V_37 , V_26 , V_137 ) ;
if ( F_91 ( V_6 , V_37 , V_137 ) )
V_47 = F_82 ( V_6 , V_37 , V_137 , 1 , V_26 , 0 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_138 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_47 = - V_48 ;
int V_216 ;
int V_198 ;
if ( V_251 != V_259 )
return V_47 ;
V_216 = F_96 ( & V_253 ) ;
V_198 = F_97 ( & V_253 ) ;
V_47 = F_82 ( V_6 , V_37 , V_216 , 1 , V_30 , V_198 ) ;
if ( ! V_47 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_198 , 0 ) ;
F_104 ( V_6 , V_216 , V_198 ) ;
}
return V_47 ;
}
static int F_139 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 )
{
int V_47 = - V_48 ;
int V_236 ;
int V_189 ;
struct V_201 * V_78 ;
switch ( V_251 ) {
case V_256 :
V_236 = F_96 ( & V_253 ) ;
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_48 ( V_6 , V_37 , V_189 , V_29 , & V_78 ) ;
if ( V_47 )
break;
V_236 = V_78 -> V_200 ;
F_53 ( V_6 , V_37 , V_189 , V_29 ) ;
V_47 = F_82 ( V_6 , V_37 , V_189 , 1 , V_29 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_107 ( V_6 , V_236 ) ;
break;
case V_258 :
V_236 = F_96 ( & V_253 ) ;
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_189 ,
V_202 , & V_78 ) ;
if ( V_47 )
return V_47 ;
F_140 ( V_6 , V_78 -> V_200 ) ;
F_90 ( V_6 , V_37 , V_29 , V_189 ) ;
return V_47 ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_141 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_244 ;
int V_47 ;
switch ( V_251 ) {
case V_259 :
V_244 = F_96 ( & V_253 ) ;
V_47 = F_82 ( V_6 , V_37 , V_244 , 1 , V_27 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_111 ( V_6 , V_244 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_142 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_260 ;
int V_47 ;
switch ( V_251 ) {
case V_259 :
V_260 = F_96 ( & V_253 ) ;
V_47 = F_82 ( V_6 , V_37 , V_260 , 1 , V_28 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_114 ( V_6 , V_260 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_143 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_267 )
{
int V_7 ;
int V_47 = 0 ;
switch ( V_251 ) {
case V_259 :
V_7 = ! V_267 ? F_96 ( V_254 ) : V_267 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
F_118 ( V_6 , V_37 , V_253 , V_7 ) ;
F_120 ( V_6 , V_7 , V_253 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_144 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 , int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_271 * V_272 = V_41 -> V_44 . V_45 . V_272 ;
int V_47 = 0 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
switch ( V_251 ) {
case V_259 :
if ( V_272 [ V_37 ] . V_273 )
return 0 ;
if ( ! V_7 )
return - V_48 ;
F_125 ( V_6 , V_37 , V_253 , V_7 ) ;
F_126 ( V_6 , V_7 , V_253 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_145 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_236 ;
int V_47 ;
if ( V_251 != V_256 )
return - V_48 ;
V_236 = F_96 ( & V_253 ) ;
V_47 = F_82 ( V_6 , V_37 , V_236 , 1 , V_34 , 0 ) ;
if ( V_47 )
return V_47 ;
F_131 ( V_6 , V_236 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
static int F_146 ( struct V_5 * V_6 , int V_37 , int V_251 , int V_252 ,
T_1 V_253 , T_1 * V_254 )
{
int V_274 ;
int V_47 ;
if ( V_251 != V_256 )
return - V_48 ;
V_274 = F_96 ( & V_253 ) ;
V_47 = F_82 ( V_6 , V_37 , V_274 , 1 , V_36 , 0 ) ;
if ( V_47 )
return V_47 ;
F_134 ( V_6 , V_274 ) ;
return V_47 ;
}
int F_147 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 = - V_48 ;
int V_279 = V_276 -> V_280 ;
switch ( V_276 -> V_281 & 0xFF ) {
case V_26 :
V_47 = F_136 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 ) ;
break;
case V_30 :
V_47 = F_138 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_29 :
V_47 = F_139 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 ) ;
break;
case V_27 :
V_47 = F_141 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_28 :
V_47 = F_142 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_31 :
V_47 = F_143 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_144 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ,
( V_276 -> V_281 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_145 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
break;
case V_36 :
V_47 = F_146 ( V_6 , V_37 , V_276 -> V_280 , V_279 ,
V_276 -> V_253 , & V_276 -> V_254 ) ;
default:
break;
}
return V_47 ;
}
static int F_148 ( struct V_282 * V_78 )
{
return ( F_40 ( V_78 -> V_126 ) >> 9 ) & 1 ;
}
static int F_149 ( struct V_282 * V_78 )
{
return ( int ) F_150 ( V_78 -> V_283 ) & 0xfffffff8 ;
}
static int F_151 ( struct V_282 * V_78 )
{
return F_40 ( V_78 -> V_284 ) ;
}
static T_3 F_152 ( struct V_282 * V_78 )
{
return F_40 ( V_78 -> V_285 ) & 0x00ffffff ;
}
static int F_153 ( struct V_282 * V_78 )
{
return F_40 ( V_78 -> V_285 ) & V_286 ;
}
static int F_154 ( struct V_282 * V_78 )
{
return F_40 ( V_78 -> V_126 ) & V_287 ;
}
static int F_155 ( struct V_282 * V_78 )
{
return F_40 ( V_78 -> V_126 ) & V_288 ;
}
static int F_156 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_289 ) & 0xfffffff8 ;
}
static int F_157 ( struct V_290 * V_291 )
{
return F_40 ( V_291 -> V_289 ) & 0xfffffff8 ;
}
static int F_158 ( struct V_120 * V_138 )
{
int V_292 = ( V_138 -> V_293 & 0x3f ) + 12 ;
int V_294 = ( V_138 -> V_295 >> 3 ) & 0xf ;
int V_296 = V_138 -> V_295 & 7 ;
int V_297 = ( V_138 -> V_298 >> 3 ) & 0xf ;
int V_299 = V_138 -> V_298 & 7 ;
int V_73 = ( F_40 ( V_138 -> V_260 ) >> 24 ) & 1 ;
int V_300 = ( F_40 ( V_138 -> V_126 ) >> 13 ) & 1 ;
T_3 V_125 = ( F_40 ( V_138 -> V_126 ) >> 16 ) & 0xff ;
int V_301 = ( V_125 == V_132 ) ? 1 : 0 ;
int V_302 ;
int V_303 ;
int V_304 ;
int V_305 ;
int V_306 = ( F_40 ( V_138 -> V_307 ) >> 6 ) & 0x3f ;
V_302 = 1 << ( V_294 + V_296 + 4 ) ;
V_303 = ( V_73 | V_300 | V_301 ) ? 0 : ( 1 << ( V_297 + V_299 + 4 ) ) ;
V_305 = V_302 + V_303 ;
V_304 =
F_159 ( ( V_305 + ( V_306 << 6 ) ) >>
V_292 ) ;
return V_304 ;
}
static int F_160 ( struct V_5 * V_6 , int V_37 , int V_308 ,
int V_309 , struct V_199 * V_76 )
{
int V_310 = V_76 -> V_192 . V_13 ;
int V_311 = ( 1 << V_76 -> V_198 ) ;
if ( V_308 < V_310 || V_308 + V_309 > V_310 + V_311 )
return - V_186 ;
return 0 ;
}
int F_161 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_236 = V_276 -> V_281 ;
struct V_199 * V_76 ;
struct V_201 * V_78 ;
int V_312 = F_149 ( V_114 -> V_116 ) / V_6 -> V_8 . V_313 ;
int V_314 ;
int V_189 ;
T_3 V_315 ;
int V_316 ;
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_189 , V_239 , & V_78 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_155 ( V_114 -> V_116 ) ) {
V_47 = - V_186 ;
goto V_317;
}
V_315 = F_152 ( V_114 -> V_116 ) ;
V_316 = ( V_315 >> 17 ) & 0x7f ;
if ( V_316 != 0 && V_316 != V_37 ) {
V_47 = - V_186 ;
goto V_317;
}
if ( F_153 ( V_114 -> V_116 ) ) {
if ( F_154 ( V_114 -> V_116 ) ) {
V_47 = - V_186 ;
goto V_317;
}
if ( ! F_155 ( V_114 -> V_116 ) ) {
V_47 = - V_186 ;
goto V_317;
}
}
V_314 = F_148 ( V_114 -> V_116 ) ;
if ( ! V_314 ) {
V_47 = F_48 ( V_6 , V_37 , V_312 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_317;
V_47 = F_160 ( V_6 , V_37 , V_312 ,
F_151 ( V_114 -> V_116 ) , V_76 ) ;
if ( V_47 )
goto V_318;
V_78 -> V_76 = V_76 ;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_318;
if ( ! V_314 ) {
F_163 ( & V_76 -> V_197 ) ;
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
}
F_90 ( V_6 , V_37 , V_29 , V_189 ) ;
return 0 ;
V_318:
if ( ! V_314 )
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
V_317:
F_89 ( V_6 , V_37 , V_29 , V_189 ) ;
return V_47 ;
}
int F_164 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_236 = V_276 -> V_281 ;
struct V_201 * V_78 ;
int V_189 ;
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_189 , V_238 , & V_78 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_317;
if ( V_78 -> V_76 )
F_165 ( & V_78 -> V_76 -> V_197 ) ;
F_90 ( V_6 , V_37 , V_29 , V_189 ) ;
return 0 ;
V_317:
F_89 ( V_6 , V_37 , V_29 , V_189 ) ;
return V_47 ;
}
int F_166 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_236 = V_276 -> V_281 ;
struct V_201 * V_78 ;
int V_189 ;
V_189 = V_236 & F_46 ( V_6 ) ;
V_47 = F_48 ( V_6 , V_37 , V_189 , V_29 , & V_78 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 -> V_192 . V_187 == V_238 ) {
struct V_282 * V_319 = F_167 (
& V_40 ( V_6 ) -> V_320 . V_321 ,
V_78 -> V_200 , NULL ) ;
if ( NULL == V_319 || NULL == V_277 -> V_116 ) {
V_47 = - V_48 ;
goto V_61;
}
memcpy ( V_277 -> V_116 , V_319 , sizeof( * V_319 ) ) ;
V_47 = 0 ;
} else if ( V_78 -> V_192 . V_187 == V_239 ) {
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
} else {
V_47 = - V_184 ;
goto V_61;
}
V_61:
F_53 ( V_6 , V_37 , V_189 , V_29 ) ;
return V_47 ;
}
static int F_168 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_322 ) & 0xffffff ;
}
static int F_169 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_323 ) & 0xffffff ;
}
static T_3 F_170 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_260 ) & 0x1ffffff ;
}
static void F_171 ( struct V_5 * V_6 , struct V_275 * V_276 ,
struct V_120 * V_324 )
{
T_3 V_137 = V_276 -> V_281 & 0xffffff ;
T_3 V_325 = 0 ;
if ( F_172 ( V_6 , V_137 , & V_325 ) )
return;
V_324 -> V_325 = F_44 ( V_325 ) ;
}
int F_173 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_137 = V_276 -> V_281 & 0x7fffff ;
struct V_199 * V_76 ;
struct V_190 * V_67 ;
struct V_120 * V_138 = V_114 -> V_116 + 8 ;
int V_312 = F_156 ( V_138 ) / V_6 -> V_8 . V_313 ;
int V_326 = F_158 ( V_138 ) ;
struct V_205 * V_327 ;
struct V_205 * V_328 ;
int V_329 = F_168 ( V_138 ) ;
int V_330 = F_169 ( V_138 ) ;
T_3 V_260 = F_170 ( V_138 ) & 0xffffff ;
int V_331 = ( F_170 ( V_138 ) >> 24 ) & 1 ;
struct V_207 * V_73 ;
int V_194 = F_40 ( V_138 -> V_194 ) & 0xffffff ;
V_47 = F_84 ( V_6 , V_37 , V_137 , V_234 , & V_67 , 0 ) ;
if ( V_47 )
return V_47 ;
V_67 -> V_194 = V_194 ;
V_67 -> V_129 = 0 ;
V_67 -> V_150 = 0 ;
V_67 -> V_159 = 0 ;
V_67 -> V_166 = 0 ;
V_67 -> V_332 = 0 ;
V_67 -> V_168 = 0 ;
V_67 -> V_173 = 0 ;
V_67 -> V_333 = F_40 ( V_138 -> V_126 ) ;
V_47 = F_48 ( V_6 , V_37 , V_312 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_317;
V_47 = F_160 ( V_6 , V_37 , V_312 , V_326 , V_76 ) ;
if ( V_47 )
goto V_334;
V_47 = F_48 ( V_6 , V_37 , V_329 , V_27 , & V_327 ) ;
if ( V_47 )
goto V_334;
if ( V_330 != V_329 ) {
V_47 = F_48 ( V_6 , V_37 , V_330 , V_27 , & V_328 ) ;
if ( V_47 )
goto V_335;
} else
V_328 = V_327 ;
if ( V_331 ) {
V_47 = F_48 ( V_6 , V_37 , V_260 , V_28 , & V_73 ) ;
if ( V_47 )
goto V_336;
}
F_171 ( V_6 , V_276 , V_138 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_337;
F_163 ( & V_76 -> V_197 ) ;
V_67 -> V_76 = V_76 ;
F_163 ( & V_327 -> V_197 ) ;
V_67 -> V_327 = V_327 ;
F_163 ( & V_328 -> V_197 ) ;
V_67 -> V_328 = V_328 ;
if ( V_330 != V_329 )
F_53 ( V_6 , V_37 , V_330 , V_27 ) ;
if ( V_331 ) {
F_163 ( & V_73 -> V_197 ) ;
F_53 ( V_6 , V_37 , V_260 , V_28 ) ;
V_67 -> V_73 = V_73 ;
}
F_53 ( V_6 , V_37 , V_329 , V_27 ) ;
F_53 ( V_6 , V_37 , V_312 , V_30 ) ;
F_90 ( V_6 , V_37 , V_26 , V_137 ) ;
return 0 ;
V_337:
if ( V_331 )
F_53 ( V_6 , V_37 , V_260 , V_28 ) ;
V_336:
if ( V_330 != V_329 )
F_53 ( V_6 , V_37 , V_330 , V_27 ) ;
V_335:
F_53 ( V_6 , V_37 , V_329 , V_27 ) ;
V_334:
F_53 ( V_6 , V_37 , V_312 , V_30 ) ;
V_317:
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
return V_47 ;
}
static int F_174 ( struct V_338 * V_339 )
{
return F_40 ( V_339 -> V_289 ) & 0xfffffff8 ;
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
return F_40 ( V_342 -> V_289 ) & 0xfffffff8 ;
}
static int F_177 ( struct V_341 * V_342 )
{
int V_343 = ( F_40 ( V_342 -> V_344 ) >> 24 ) & 0x1f ;
int V_292 = ( V_342 -> V_293 & 0x3f ) + 12 ;
if ( V_343 + 5 < V_292 )
return 1 ;
return 1 << ( V_343 + 5 - V_292 ) ;
}
int F_178 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_345 = V_276 -> V_281 ;
int V_13 = ( V_37 << 8 ) | V_345 ;
struct V_338 * V_339 = V_114 -> V_116 ;
int V_312 = F_174 ( V_339 ) / V_6 -> V_8 . V_313 ;
int V_326 = F_175 ( V_339 ) ;
struct V_203 * V_241 ;
struct V_199 * V_76 ;
V_47 = F_66 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_86 ( V_6 , V_37 , V_13 , V_243 , & V_241 ) ;
if ( V_47 )
goto V_346;
V_47 = F_48 ( V_6 , V_37 , V_312 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_347;
V_47 = F_160 ( V_6 , V_37 , V_312 , V_326 , V_76 ) ;
if ( V_47 )
goto V_348;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_348;
F_163 ( & V_76 -> V_197 ) ;
V_241 -> V_76 = V_76 ;
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_33 , V_13 ) ;
return 0 ;
V_348:
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
V_347:
F_89 ( V_6 , V_37 , V_33 , V_13 ) ;
V_346:
F_82 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return V_47 ;
}
int F_179 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
T_2 V_349 = V_276 -> V_280 ;
if ( V_349 != 1 )
return - V_186 ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
return V_47 ;
}
static int F_180 ( struct V_5 * V_6 , int V_37 , int V_308 ,
int V_350 , struct V_199 * * V_17 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_199 * V_76 ;
int V_47 = - V_48 ;
F_49 ( F_50 ( V_6 ) ) ;
F_181 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_160 ( V_6 , V_37 , V_308 , V_350 , V_76 ) ) {
* V_17 = V_76 ;
V_76 -> V_192 . V_187 = V_76 -> V_192 . V_2 ;
V_76 -> V_192 . V_2 = V_3 ;
V_47 = 0 ;
break;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_182 ( struct V_5 * V_6 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
enum V_351 V_352 , T_2 V_37 )
{
T_3 V_141 ;
T_3 V_137 ;
struct V_120 * V_121 ;
enum V_122 V_123 ;
int V_7 ;
int V_353 ;
V_121 = V_114 -> V_116 + 8 ;
V_141 = ( F_40 ( V_121 -> V_126 ) >> 16 ) & 0xff ;
V_123 = F_40 ( * ( V_124 * ) V_114 -> V_116 ) ;
switch ( V_141 ) {
case V_131 :
case V_132 :
case V_133 :
switch ( V_352 ) {
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
if ( V_37 != F_15 ( V_6 ) )
if ( V_123 & V_134 ) {
V_7 = ( V_121 -> V_128 . V_129 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_353 = F_183 ( V_6 , V_37 , V_7 ) ;
else
V_353 = 1 ;
if ( V_121 -> V_128 . V_130 >= V_353 )
return - V_48 ;
}
if ( V_123 & V_135 ) {
V_7 = ( V_121 -> V_136 . V_129 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_353 = F_183 ( V_6 , V_37 , V_7 ) ;
else
V_353 = 1 ;
if ( V_121 -> V_136 . V_130 >= V_353 )
return - V_48 ;
}
break;
default:
break;
}
break;
case V_146 :
V_137 = V_276 -> V_281 & 0x7fffff ;
V_7 = ( V_121 -> V_128 . V_129 >> 6 & 1 ) + 1 ;
if ( V_352 == V_354 &&
V_37 != F_15 ( V_6 ) &&
F_43 ( V_6 , V_137 ) &&
! F_184 ( V_6 , V_37 , V_7 ) ) {
F_185 ( V_6 , L_24 ,
V_223 , V_37 , V_7 ) ;
return - V_186 ;
}
break;
default:
break;
}
return 0 ;
}
int F_186 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
struct V_359 V_76 ;
T_5 * V_360 = V_114 -> V_116 ;
T_1 * V_361 = ( T_1 * ) V_360 ;
int V_81 ;
struct V_199 * V_362 = NULL ;
int V_308 = F_150 ( V_360 [ 0 ] ) ;
int V_363 = V_276 -> V_281 ;
int V_47 ;
V_47 = F_180 ( V_6 , V_37 , V_308 , V_363 , & V_362 ) ;
if ( V_47 )
return V_47 ;
V_76 . V_364 = 0 ;
V_76 . V_198 = 0 ;
V_76 . V_292 = 0 ;
for ( V_81 = 0 ; V_81 < V_363 ; ++ V_81 )
V_361 [ V_81 + 2 ] = ( F_150 ( V_360 [ V_81 + 2 ] ) & ~ 1ULL ) ;
V_47 = F_187 ( V_6 , & V_76 , F_150 ( V_360 [ 0 ] ) , V_363 ,
( ( T_1 * ) V_360 + 2 ) ) ;
if ( V_362 )
F_53 ( V_6 , V_37 , V_362 -> V_192 . V_13 , V_30 ) ;
return V_47 ;
}
int F_188 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_345 = V_276 -> V_281 ;
int V_13 = V_345 | ( V_37 << 8 ) ;
struct V_203 * V_241 ;
int V_47 ;
V_47 = F_86 ( V_6 , V_37 , V_13 , V_204 , & V_241 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_241 -> V_76 -> V_192 . V_13 , V_30 , NULL ) ;
if ( V_47 )
goto V_317;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_318;
F_165 ( & V_241 -> V_76 -> V_197 ) ;
F_53 ( V_6 , V_37 , V_241 -> V_76 -> V_192 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_33 , V_13 ) ;
F_82 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return 0 ;
V_318:
F_53 ( V_6 , V_37 , V_241 -> V_76 -> V_192 . V_13 , V_30 ) ;
V_317:
F_89 ( V_6 , V_37 , V_33 , V_13 ) ;
return V_47 ;
}
int F_189 ( struct V_5 * V_6 , int V_37 , struct V_365 * V_366 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_367 * V_368 ;
struct V_113 * V_369 ;
T_3 V_281 = 0 ;
int V_47 ;
int V_13 ;
struct V_203 * V_370 ;
if ( ! V_41 -> V_44 . V_45 . V_272 )
return - V_48 ;
V_368 = & V_41 -> V_44 . V_45 . V_272 [ V_37 ] . V_368 [ V_366 -> type ] ;
if ( V_368 -> V_345 < 0 )
return 0 ;
F_35 ( & V_41 -> V_44 . V_45 . V_371 [ V_37 ] ) ;
V_13 = ( V_37 << 8 ) | V_368 -> V_345 ;
V_47 = F_48 ( V_6 , V_37 , V_13 , V_33 , & V_370 ) ;
if ( V_47 )
goto V_372;
if ( V_370 -> V_192 . V_187 != V_243 ) {
V_47 = - V_48 ;
goto V_373;
}
V_369 = F_190 ( V_6 ) ;
if ( F_191 ( V_369 ) ) {
V_47 = F_192 ( V_369 ) ;
goto V_373;
}
if ( V_366 -> type == V_374 ) {
++ V_368 -> V_375 ;
V_366 -> V_376 . V_252 . V_375 = F_193 ( V_368 -> V_375 ) ;
}
memcpy ( V_369 -> V_116 , ( T_2 * ) V_366 , 28 ) ;
V_281 = ( V_37 & 0xff ) | ( ( V_368 -> V_345 & 0xff ) << 16 ) ;
V_47 = F_194 ( V_6 , V_369 -> V_377 , V_281 , 0 ,
V_378 , V_379 ,
V_380 ) ;
F_53 ( V_6 , V_37 , V_13 , V_33 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_371 [ V_37 ] ) ;
F_195 ( V_6 , V_369 ) ;
return V_47 ;
V_373:
F_53 ( V_6 , V_37 , V_13 , V_33 ) ;
V_372:
F_37 ( & V_41 -> V_44 . V_45 . V_371 [ V_37 ] ) ;
return V_47 ;
}
int F_196 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_345 = V_276 -> V_281 ;
int V_13 = V_345 | ( V_37 << 8 ) ;
struct V_203 * V_241 ;
int V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_13 , V_33 , & V_241 ) ;
if ( V_47 )
return V_47 ;
if ( V_241 -> V_192 . V_187 != V_243 ) {
V_47 = - V_48 ;
goto V_318;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_318:
F_53 ( V_6 , V_37 , V_13 , V_33 ) ;
return V_47 ;
}
int F_197 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_244 = V_276 -> V_281 ;
struct V_341 * V_342 = V_114 -> V_116 ;
int V_312 = F_176 ( V_342 ) / V_6 -> V_8 . V_313 ;
struct V_205 * V_70 ;
struct V_199 * V_76 ;
V_47 = F_87 ( V_6 , V_37 , V_244 , V_246 , & V_70 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_312 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_347;
V_47 = F_160 ( V_6 , V_37 , V_312 , F_177 ( V_342 ) , V_76 ) ;
if ( V_47 )
goto V_348;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_348;
F_163 ( & V_76 -> V_197 ) ;
V_70 -> V_76 = V_76 ;
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_27 , V_244 ) ;
return 0 ;
V_348:
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
V_347:
F_89 ( V_6 , V_37 , V_27 , V_244 ) ;
return V_47 ;
}
int F_198 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_244 = V_276 -> V_281 ;
struct V_205 * V_70 ;
V_47 = F_87 ( V_6 , V_37 , V_244 , V_206 , & V_70 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_347;
F_165 ( & V_70 -> V_76 -> V_197 ) ;
F_90 ( V_6 , V_37 , V_27 , V_244 ) ;
return 0 ;
V_347:
F_89 ( V_6 , V_37 , V_27 , V_244 ) ;
return V_47 ;
}
int F_199 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_244 = V_276 -> V_281 ;
struct V_205 * V_70 ;
int V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_244 , V_27 , & V_70 ) ;
if ( V_47 )
return V_47 ;
if ( V_70 -> V_192 . V_187 != V_246 )
goto V_318;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_318:
F_53 ( V_6 , V_37 , V_244 , V_27 ) ;
return V_47 ;
}
static int F_200 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 ,
struct V_205 * V_70 )
{
int V_47 ;
struct V_199 * V_381 ;
struct V_199 * V_76 ;
struct V_341 * V_342 = V_114 -> V_116 ;
int V_312 = F_176 ( V_342 ) / V_6 -> V_8 . V_313 ;
V_47 = F_48 ( V_6 , V_37 , V_70 -> V_76 -> V_192 . V_13 , V_30 , & V_381 ) ;
if ( V_47 )
return V_47 ;
if ( V_381 != V_70 -> V_76 ) {
V_47 = - V_48 ;
goto V_318;
}
V_47 = F_48 ( V_6 , V_37 , V_312 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_318;
V_47 = F_160 ( V_6 , V_37 , V_312 , F_177 ( V_342 ) , V_76 ) ;
if ( V_47 )
goto V_382;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_382;
F_165 ( & V_381 -> V_197 ) ;
F_53 ( V_6 , V_37 , V_381 -> V_192 . V_13 , V_30 ) ;
F_163 ( & V_76 -> V_197 ) ;
V_70 -> V_76 = V_76 ;
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
return 0 ;
V_382:
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
V_318:
F_53 ( V_6 , V_37 , V_381 -> V_192 . V_13 , V_30 ) ;
return V_47 ;
}
int F_201 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_244 = V_276 -> V_281 ;
struct V_205 * V_70 ;
int V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_244 , V_27 , & V_70 ) ;
if ( V_47 )
return V_47 ;
if ( V_70 -> V_192 . V_187 != V_246 )
goto V_318;
if ( V_276 -> V_280 == 0 ) {
V_47 = F_200 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 , V_70 ) ;
goto V_318;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_318:
F_53 ( V_6 , V_37 , V_244 , V_27 ) ;
return V_47 ;
}
static int F_202 ( struct V_290 * V_291 )
{
int V_383 = ( F_40 ( V_291 -> V_384 ) >> 24 ) & 0xf ;
int V_299 = V_291 -> V_385 & 7 ;
int V_292 = ( V_291 -> V_293 & 0x3f ) + 12 ;
if ( V_383 + V_299 + 4 < V_292 )
return 1 ;
return 1 << ( V_383 + V_299 + 4 - V_292 ) ;
}
int F_203 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_260 = V_276 -> V_281 ;
struct V_199 * V_76 ;
struct V_207 * V_73 ;
struct V_290 * V_291 = V_114 -> V_116 ;
int V_312 = F_157 ( V_291 ) / V_6 -> V_8 . V_313 ;
if ( V_260 != ( F_40 ( V_291 -> V_384 ) & 0xffffff ) )
return - V_48 ;
V_47 = F_88 ( V_6 , V_37 , V_260 , V_248 , & V_73 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_312 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_317;
V_47 = F_160 ( V_6 , V_37 , V_312 , F_202 ( V_291 ) ,
V_76 ) ;
if ( V_47 )
goto V_334;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_334;
F_163 ( & V_76 -> V_197 ) ;
V_73 -> V_76 = V_76 ;
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_28 , V_260 ) ;
return 0 ;
V_334:
F_53 ( V_6 , V_37 , V_76 -> V_192 . V_13 , V_30 ) ;
V_317:
F_89 ( V_6 , V_37 , V_28 , V_260 ) ;
return V_47 ;
}
int F_204 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_260 = V_276 -> V_281 ;
struct V_207 * V_73 ;
V_47 = F_88 ( V_6 , V_37 , V_260 , V_208 , & V_73 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_317;
F_165 ( & V_73 -> V_76 -> V_197 ) ;
if ( V_73 -> V_70 )
F_165 ( & V_73 -> V_70 -> V_197 ) ;
F_90 ( V_6 , V_37 , V_28 , V_260 ) ;
return 0 ;
V_317:
F_89 ( V_6 , V_37 , V_28 , V_260 ) ;
return V_47 ;
}
int F_205 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_260 = V_276 -> V_281 ;
struct V_207 * V_73 ;
V_47 = F_48 ( V_6 , V_37 , V_260 , V_28 , & V_73 ) ;
if ( V_47 )
return V_47 ;
if ( V_73 -> V_192 . V_187 != V_248 ) {
V_47 = - V_184 ;
goto V_61;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_61:
F_53 ( V_6 , V_37 , V_260 , V_28 ) ;
return V_47 ;
}
int F_206 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_260 = V_276 -> V_281 ;
struct V_207 * V_73 ;
V_47 = F_48 ( V_6 , V_37 , V_260 , V_28 , & V_73 ) ;
if ( V_47 )
return V_47 ;
if ( V_73 -> V_192 . V_187 != V_248 ) {
V_47 = - V_184 ;
goto V_61;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_61:
F_53 ( V_6 , V_37 , V_260 , V_28 ) ;
return V_47 ;
}
int F_207 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_137 = V_276 -> V_281 & 0x7fffff ;
struct V_190 * V_67 ;
V_47 = F_48 ( V_6 , V_37 , V_137 , V_26 , & V_67 ) ;
if ( V_47 )
return V_47 ;
if ( V_67 -> V_192 . V_187 != V_234 ) {
V_47 = - V_184 ;
goto V_61;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_61:
F_53 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_208 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
struct V_120 * V_324 = V_114 -> V_116 + 8 ;
F_171 ( V_6 , V_276 , V_324 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
return F_207 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
}
static int F_209 ( struct V_5 * V_6 , int V_37 ,
struct V_120 * V_138 ,
struct V_113 * V_114 )
{
enum V_122 V_123 = F_40 ( * ( V_124 * ) V_114 -> V_116 ) ;
T_2 V_386 ;
int V_7 = F_122 (
V_6 , V_37 , ( V_138 -> V_128 . V_129 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_386 = ( V_138 -> V_128 . V_129 & ~ ( 1 << 6 ) ) |
( ( V_7 & 1 ) << 6 ) ;
if ( V_123 & V_134 ||
F_2 ( V_6 , V_7 + 1 ) ) {
V_138 -> V_128 . V_129 = V_386 ;
}
if ( V_123 & V_135 ) {
V_7 = F_122 (
V_6 , V_37 , ( V_138 -> V_136 . V_129 >> 6 & 1 )
+ 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_138 -> V_136 . V_129 =
( V_138 -> V_136 . V_129 & ~ ( 1 << 6 ) ) |
( V_7 & 1 ) << 6 ;
}
return 0 ;
}
static int F_210 ( struct V_5 * V_6 , int V_37 ,
struct V_120 * V_138 ,
struct V_113 * V_114 )
{
T_1 V_262 ;
int V_7 ;
T_3 V_125 = ( F_40 ( V_138 -> V_126 ) >> 16 ) & 0xff ;
T_2 V_115 = * ( T_2 * ) ( V_114 -> V_116 + 64 ) ;
T_2 V_387 ;
V_7 = ( V_115 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) && ( V_125 != V_146 ) ) {
V_387 = V_138 -> V_128 . V_179 & 0x7f ;
if ( F_115 ( V_6 , V_37 , V_7 , V_387 , & V_262 ) )
return - V_188 ;
}
return 0 ;
}
int F_211 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
struct V_120 * V_138 = V_114 -> V_116 + 8 ;
int V_137 = V_276 -> V_281 & 0x7fffff ;
struct V_190 * V_67 ;
T_2 V_388 ;
V_124 V_389 = V_138 -> V_150 ;
T_2 V_390 = V_138 -> V_128 . V_159 ;
T_2 V_391 = V_138 -> V_128 . V_166 ;
T_2 V_392 = V_138 -> V_128 . V_170 ;
T_2 V_393 = V_138 -> V_128 . V_168 ;
T_2 V_394 = V_138 -> V_128 . V_173 ;
V_47 = F_209 ( V_6 , V_37 , V_138 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_276 , V_114 , V_354 , V_37 ) ;
if ( V_47 )
return V_47 ;
if ( F_210 ( V_6 , V_37 , V_138 , V_114 ) )
return - V_48 ;
F_38 ( V_6 , V_37 , V_114 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_171 ( V_6 , V_276 , V_138 ) ;
V_388 = V_138 -> V_128 . V_129 ;
V_47 = F_42 ( V_6 , V_114 , V_37 , V_137 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_137 , V_26 , & V_67 ) ;
if ( V_47 )
return V_47 ;
if ( V_67 -> V_192 . V_187 != V_234 ) {
V_47 = - V_184 ;
goto V_61;
}
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
V_61:
if ( ! V_47 ) {
V_67 -> V_129 = V_388 ;
V_67 -> V_150 = V_389 ;
V_67 -> V_159 = V_390 ;
V_67 -> V_166 = V_391 ;
V_67 -> V_332 = V_392 ;
V_67 -> V_168 = V_393 ;
V_67 -> V_173 = V_394 ;
}
F_53 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_212 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
struct V_120 * V_324 = V_114 -> V_116 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_324 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_276 , V_114 , V_355 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_38 ( V_6 , V_37 , V_114 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_171 ( V_6 , V_276 , V_324 ) ;
return F_207 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
}
int F_213 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
struct V_120 * V_324 = V_114 -> V_116 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_324 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_276 , V_114 , V_356 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_38 ( V_6 , V_37 , V_114 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_171 ( V_6 , V_276 , V_324 ) ;
return F_207 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
}
int F_214 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
struct V_120 * V_324 = V_114 -> V_116 + 8 ;
int V_47 = F_209 ( V_6 , V_37 , V_324 , V_114 ) ;
if ( V_47 )
return V_47 ;
F_171 ( V_6 , V_276 , V_324 ) ;
return F_207 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
}
int F_215 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
struct V_120 * V_324 = V_114 -> V_116 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_324 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_276 , V_114 , V_357 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_171 ( V_6 , V_276 , V_324 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
return F_207 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
}
int F_216 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
struct V_120 * V_324 = V_114 -> V_116 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_324 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_276 , V_114 , V_358 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_171 ( V_6 , V_276 , V_324 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
return F_207 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
}
int F_217 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_137 = V_276 -> V_281 & 0x7fffff ;
struct V_190 * V_67 ;
V_47 = F_84 ( V_6 , V_37 , V_137 , V_233 , & V_67 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
if ( V_47 )
goto V_317;
F_165 ( & V_67 -> V_76 -> V_197 ) ;
F_165 ( & V_67 -> V_327 -> V_197 ) ;
F_165 ( & V_67 -> V_328 -> V_197 ) ;
if ( V_67 -> V_73 )
F_165 ( & V_67 -> V_73 -> V_197 ) ;
F_90 ( V_6 , V_37 , V_26 , V_137 ) ;
return 0 ;
V_317:
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
return V_47 ;
}
static struct V_395 * F_218 ( struct V_5 * V_6 , int V_37 ,
struct V_190 * V_396 , T_2 * V_397 )
{
struct V_395 * V_17 ;
F_181 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_17 -> V_397 , V_397 , 16 ) )
return V_17 ;
}
return NULL ;
}
static int F_219 ( struct V_5 * V_6 , int V_37 , struct V_190 * V_396 ,
T_2 * V_397 , enum V_398 V_399 ,
enum V_400 V_401 , T_1 V_402 )
{
struct V_395 * V_17 ;
int V_47 ;
V_17 = F_21 ( sizeof *V_17 , V_86 ) ;
if ( ! V_17 )
return - V_87 ;
F_49 ( & V_396 -> V_196 ) ;
if ( F_218 ( V_6 , V_37 , V_396 , V_397 ) ) {
F_31 ( V_17 ) ;
V_47 = - V_23 ;
} else {
memcpy ( V_17 -> V_397 , V_397 , 16 ) ;
V_17 -> V_399 = V_399 ;
V_17 -> V_401 = V_401 ;
V_17 -> V_402 = V_402 ;
F_67 ( & V_17 -> V_221 , & V_396 -> V_195 ) ;
V_47 = 0 ;
}
F_51 ( & V_396 -> V_196 ) ;
return V_47 ;
}
static int F_220 ( struct V_5 * V_6 , int V_37 , struct V_190 * V_396 ,
T_2 * V_397 , enum V_398 V_399 ,
enum V_400 V_401 , T_1 * V_402 )
{
struct V_395 * V_17 ;
int V_47 ;
F_49 ( & V_396 -> V_196 ) ;
V_17 = F_218 ( V_6 , V_37 , V_396 , V_397 ) ;
if ( ! V_17 || V_17 -> V_399 != V_399 || V_17 -> V_401 != V_401 )
V_47 = - V_48 ;
else {
* V_402 = V_17 -> V_402 ;
F_83 ( & V_17 -> V_221 ) ;
F_31 ( V_17 ) ;
V_47 = 0 ;
}
F_51 ( & V_396 -> V_196 ) ;
return V_47 ;
}
static int F_221 ( struct V_5 * V_6 , int V_37 , struct V_403 * V_67 ,
T_2 V_397 [ 16 ] , int V_404 , enum V_398 V_399 ,
enum V_400 type , T_1 * V_402 )
{
switch ( V_6 -> V_8 . V_405 ) {
case V_406 : {
int V_7 = F_122 ( V_6 , V_37 , V_397 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_222 ( V_6 , V_67 , V_397 , V_7 ,
V_404 , V_399 ,
V_402 ) ;
}
case V_407 :
if ( V_399 == V_408 ) {
int V_7 = F_122 ( V_6 , V_37 , V_397 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_397 [ 5 ] = V_7 ;
}
return F_223 ( V_6 , V_67 , V_397 ,
V_404 , V_399 , type ) ;
default:
return - V_48 ;
}
}
static int F_224 ( struct V_5 * V_6 , struct V_403 * V_67 ,
T_2 V_397 [ 16 ] , enum V_398 V_399 ,
enum V_400 type , T_1 V_402 )
{
switch ( V_6 -> V_8 . V_405 ) {
case V_406 :
return F_225 ( V_6 , V_402 ) ;
case V_407 :
return F_226 ( V_6 , V_67 , V_397 , V_399 , type ) ;
default:
return - V_48 ;
}
}
static int F_227 ( struct V_5 * V_6 , int V_37 ,
T_2 * V_397 , enum V_398 V_399 )
{
int V_409 ;
if ( V_399 != V_408 )
return 0 ;
if ( V_6 -> V_8 . V_405 == V_407 ||
V_6 -> V_8 . V_405 == V_406 ) {
V_409 = F_122 ( V_6 , V_37 , V_397 [ 5 ] ) ;
if ( V_409 < 0 )
return - V_48 ;
V_397 [ 5 ] = V_409 ;
}
return 0 ;
}
int F_228 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
struct V_403 V_67 ;
T_2 * V_397 = V_114 -> V_116 ;
enum V_398 V_399 = ( V_276 -> V_281 >> 28 ) & 0x7 ;
int V_47 ;
int V_137 ;
struct V_190 * V_396 ;
T_1 V_402 = 0 ;
int V_410 = V_276 -> V_280 ;
int V_404 = V_276 -> V_281 >> 31 ;
T_2 V_411 = 2 ;
enum V_400 type = ( V_397 [ 7 ] & V_411 ) >> 1 ;
V_137 = V_276 -> V_281 & 0xffffff ;
V_47 = F_48 ( V_6 , V_37 , V_137 , V_26 , & V_396 ) ;
if ( V_47 )
return V_47 ;
V_67 . V_137 = V_137 ;
if ( V_410 ) {
V_47 = F_221 ( V_6 , V_37 , & V_67 , V_397 , V_404 , V_399 ,
type , & V_402 ) ;
if ( V_47 ) {
F_65 ( L_25 , V_137 ) ;
goto V_318;
}
V_47 = F_219 ( V_6 , V_37 , V_396 , V_397 , V_399 , type , V_402 ) ;
if ( V_47 )
goto V_412;
} else {
V_47 = F_227 ( V_6 , V_37 , V_397 , V_399 ) ;
if ( V_47 )
goto V_318;
V_47 = F_220 ( V_6 , V_37 , V_396 , V_397 , V_399 , type , & V_402 ) ;
if ( V_47 )
goto V_318;
V_47 = F_224 ( V_6 , & V_67 , V_397 , V_399 , type , V_402 ) ;
if ( V_47 )
F_65 ( L_26 ,
V_137 , V_402 ) ;
}
F_53 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
V_412:
F_224 ( V_6 , & V_67 , V_397 , V_399 , type , V_402 ) ;
V_318:
F_53 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
static int F_229 ( int V_37 , struct V_413 * V_414 ,
struct V_263 * V_415 )
{
struct V_265 * V_17 , * V_266 ;
T_5 V_416 ;
if ( ! F_230 ( V_414 -> V_417 . V_418 ) &&
! F_231 ( V_414 -> V_417 . V_418 ) ) {
F_116 (res, tmp, rlist, list) {
V_416 = F_232 ( V_17 -> V_262 << 16 ) ;
if ( F_233 ( ( T_2 * ) & V_416 , V_414 -> V_417 . V_418 ) )
return 0 ;
}
F_65 ( L_27 ,
V_414 -> V_417 . V_418 , V_37 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_234 ( struct V_5 * V_6 , int V_37 ,
struct V_113 * V_114 ,
struct V_263 * V_415 , int V_419 )
{
struct V_265 * V_17 , * V_266 ;
T_2 V_7 ;
struct V_420 * V_421 ;
struct V_422 * V_414 ;
struct V_423 * V_424 ;
struct V_425 * V_426 ;
T_5 V_416 = 0 ;
T_5 V_427 = F_232 ( V_428 << 16 ) ;
V_421 = (struct V_420 * ) V_114 -> V_116 ;
V_7 = V_421 -> V_7 ;
V_414 = (struct V_422 * ) ( V_421 + 1 ) ;
switch ( V_419 ) {
case V_429 :
V_424 =
(struct V_423 * ) ( V_414 + 1 ) ;
memmove ( V_424 , V_414 ,
sizeof( * V_424 ) + sizeof( * V_426 ) ) ;
break;
case V_430 :
case V_431 :
V_426 = (struct V_425 * )
( V_414 + 1 ) ;
memmove ( V_426 , V_414 , sizeof( * V_426 ) ) ;
break;
default:
return - V_48 ;
}
F_116 (res, tmp, rlist, list) {
if ( V_7 == V_17 -> V_7 ) {
V_416 = F_232 ( V_17 -> V_262 << 16 ) ;
break;
}
}
if ( ! V_416 ) {
F_65 ( L_28 ,
V_7 ) ;
return - V_48 ;
}
memset ( V_414 , 0 , sizeof( * V_414 ) ) ;
V_414 -> V_309 = sizeof( * V_414 ) >> 2 ;
V_414 -> V_189 = F_193 ( V_432 [ V_433 ] ) ;
memcpy ( V_414 -> V_418 , & V_416 , V_434 ) ;
memcpy ( V_414 -> V_435 , & V_427 , V_434 ) ;
return 0 ;
}
int F_235 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_436 )
{
int V_47 ;
T_3 V_137 = V_276 -> V_281 & 0xffffff ;
struct V_190 * V_396 ;
T_1 V_262 ;
unsigned V_7 ;
T_1 V_437 ;
struct V_438 * V_252 ;
int V_261 ;
V_252 = (struct V_438 * ) V_114 -> V_116 ;
V_437 = F_150 ( V_252 -> V_439 ) ;
if ( V_252 -> V_440 || V_252 -> V_441 ||
( V_437 & ~ V_442 ) )
return - V_186 ;
V_47 = F_48 ( V_6 , V_37 , V_137 , V_26 , & V_396 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_29 , V_137 , V_37 ) ;
return V_47 ;
}
V_7 = ( V_396 -> V_129 >> 6 & 1 ) + 1 ;
if ( V_437 & ( 1ULL << V_443 ) ) {
V_261 = V_252 -> V_444 . V_128 . V_179 ;
V_47 = F_115 ( V_6 , V_37 , V_7 ,
V_261 , & V_262 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_30 ,
V_137 , V_261 ) ;
goto V_445;
}
}
V_47 = F_194 ( V_6 , V_114 -> V_377 ,
V_276 -> V_281 , 0 ,
V_446 , V_447 ,
V_380 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_31 , V_137 ) ;
goto V_445;
}
V_445:
F_53 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_236 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_415 = & V_219 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
int V_47 ;
int V_137 ;
struct V_190 * V_396 ;
struct V_420 * V_421 ;
struct V_413 * V_448 ;
int V_419 ;
if ( V_6 -> V_8 . V_405 !=
V_406 )
return - V_449 ;
V_421 = (struct V_420 * ) V_114 -> V_116 ;
V_421 -> V_7 = F_122 ( V_6 , V_37 , V_421 -> V_7 ) ;
if ( V_421 -> V_7 <= 0 )
return - V_48 ;
V_137 = F_40 ( V_421 -> V_137 ) & 0xffffff ;
V_47 = F_48 ( V_6 , V_37 , V_137 , V_26 , & V_396 ) ;
if ( V_47 ) {
F_65 ( L_32 , V_137 ) ;
return V_47 ;
}
V_448 = (struct V_413 * ) ( V_421 + 1 ) ;
V_419 = F_237 ( F_238 ( V_448 -> V_189 ) ) ;
switch ( V_419 ) {
case V_433 :
if ( F_229 ( V_37 , V_448 , V_415 ) ) {
V_47 = - V_48 ;
goto V_450;
}
break;
case V_451 :
break;
case V_429 :
case V_430 :
case V_431 :
F_239 ( L_33 ) ;
if ( F_234 ( V_6 , V_37 , V_114 , V_415 , V_419 ) ) {
V_47 = - V_48 ;
goto V_450;
}
V_276 -> V_281 +=
sizeof( struct V_422 ) >> 2 ;
break;
default:
F_65 ( L_34 ) ;
V_47 = - V_48 ;
goto V_450;
}
V_47 = F_240 ( V_6 , V_114 -> V_377 , & V_276 -> V_254 ,
V_276 -> V_281 , 0 ,
V_452 , V_447 ,
V_380 ) ;
if ( V_47 )
goto V_450;
V_47 = F_66 ( V_6 , V_37 , V_276 -> V_254 , 1 , V_35 , V_137 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_35 ) ;
F_194 ( V_6 , V_276 -> V_254 , 0 , 0 ,
V_453 , V_447 ,
V_380 ) ;
goto V_450;
}
F_163 ( & V_396 -> V_197 ) ;
V_450:
F_53 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_241 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
struct V_190 * V_396 ;
struct V_213 * V_454 ;
if ( V_6 -> V_8 . V_405 !=
V_406 )
return - V_449 ;
V_47 = F_48 ( V_6 , V_37 , V_276 -> V_253 , V_35 , & V_454 ) ;
if ( V_47 )
return V_47 ;
F_53 ( V_6 , V_37 , V_276 -> V_253 , V_35 ) ;
V_47 = F_48 ( V_6 , V_37 , V_454 -> V_137 , V_26 , & V_396 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_82 ( V_6 , V_37 , V_276 -> V_253 , 1 , V_35 , 0 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_36 ) ;
goto V_61;
}
V_47 = F_194 ( V_6 , V_276 -> V_253 , 0 , 0 ,
V_453 , V_447 ,
V_380 ) ;
if ( ! V_47 )
F_165 ( & V_396 -> V_197 ) ;
V_61:
F_53 ( V_6 , V_37 , V_454 -> V_137 , V_26 ) ;
return V_47 ;
}
int F_242 ( struct V_5 * V_6 , int V_37 ,
struct V_275 * V_276 ,
struct V_113 * V_114 ,
struct V_113 * V_277 ,
struct V_278 * V_252 )
{
int V_47 ;
int V_236 = V_276 -> V_281 & 0xffff ;
V_47 = F_48 ( V_6 , V_37 , V_236 , V_34 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_276 , V_114 , V_277 , V_252 ) ;
F_53 ( V_6 , V_37 , V_236 , V_34 ) ;
return V_47 ;
}
static void F_243 ( struct V_5 * V_6 , int V_37 , struct V_190 * V_396 )
{
struct V_395 * V_455 ;
struct V_395 * V_266 ;
struct V_403 V_67 ;
F_116 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_6 -> V_8 . V_405 ) {
case V_406 :
F_225 ( V_6 , V_455 -> V_402 ) ;
break;
case V_407 :
V_67 . V_137 = V_396 -> V_194 ;
( void ) F_226 ( V_6 , & V_67 , V_455 -> V_397 ,
V_455 -> V_399 , V_455 -> V_401 ) ;
break;
}
F_83 ( & V_455 -> V_221 ) ;
F_31 ( V_455 ) ;
}
}
static int F_244 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_456 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_415 = & V_219 -> V_84 [ V_37 ] . V_89 [ type ] ;
struct V_16 * V_181 ;
struct V_16 * V_266 ;
int V_457 ;
V_457 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (r, tmp, rlist, list) {
if ( V_181 -> V_185 == V_37 ) {
if ( ! V_181 -> V_458 ) {
if ( V_181 -> V_2 == V_183 ) {
if ( V_456 )
F_24 ( V_6 ,
L_37 ,
F_8 ( type ) ,
V_181 -> V_13 ) ;
++ V_457 ;
} else {
V_181 -> V_187 = V_181 -> V_2 ;
V_181 -> V_2 = V_183 ;
V_181 -> V_458 = 1 ;
}
}
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_457 ;
}
static int F_245 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type )
{
unsigned long V_459 ;
int V_457 ;
V_459 = V_460 ;
do {
V_457 = F_244 ( V_6 , V_37 , type , 0 ) ;
if ( F_246 ( V_460 , V_459 + 5 * V_461 ) )
break;
if ( V_457 )
F_247 () ;
} while ( V_457 );
if ( V_457 )
V_457 = F_244 ( V_6 , V_37 , type , 1 ) ;
return V_457 ;
}
static void F_248 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_462 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_26 ] ;
struct V_190 * V_67 ;
struct V_190 * V_266 ;
int V_2 ;
T_1 V_253 ;
int V_137 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_26 ) ;
if ( V_47 )
F_11 ( V_6 , L_38 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (qp, tmp, qp_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_67 -> V_192 . V_185 == V_37 ) {
V_137 = V_67 -> V_192 . V_13 ;
F_243 ( V_6 , V_37 , V_67 ) ;
V_2 = V_67 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_193 :
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_67 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_26 ] ) ;
F_83 ( & V_67 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
if ( ! F_91 ( V_6 , V_37 , V_137 ) ) {
F_99 ( V_6 , V_137 , 1 ) ;
F_13 ( V_6 , V_37 ,
V_26 , 1 , 0 ) ;
}
F_31 ( V_67 ) ;
V_2 = 0 ;
break;
case V_233 :
if ( ! F_91 ( V_6 , V_37 , V_137 ) )
F_137 ( V_6 , V_137 ) ;
V_2 = V_193 ;
break;
case V_234 :
V_253 = V_37 ;
V_47 = F_194 ( V_6 , V_253 ,
V_67 -> V_194 , 2 ,
V_463 ,
V_447 ,
V_380 ) ;
if ( V_47 )
F_24 ( V_6 , L_39 ,
V_37 , V_67 -> V_194 ) ;
F_165 ( & V_67 -> V_327 -> V_197 ) ;
F_165 ( & V_67 -> V_328 -> V_197 ) ;
F_165 ( & V_67 -> V_76 -> V_197 ) ;
if ( V_67 -> V_73 )
F_165 ( & V_67 -> V_73 -> V_197 ) ;
V_2 = V_233 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_249 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_464 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_28 ] ;
struct V_207 * V_73 ;
struct V_207 * V_266 ;
int V_2 ;
T_1 V_253 ;
F_250 ( V_465 ) ;
int V_260 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_28 ) ;
if ( V_47 )
F_11 ( V_6 , L_40 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (srq, tmp, srq_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_73 -> V_192 . V_185 == V_37 ) {
V_260 = V_73 -> V_192 . V_13 ;
V_2 = V_73 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_208 :
F_114 ( V_6 , V_260 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_73 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_28 ] ) ;
F_83 ( & V_73 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_28 , 1 , 0 ) ;
F_31 ( V_73 ) ;
V_2 = 0 ;
break;
case V_248 :
V_253 = V_37 ;
V_47 = F_194 ( V_6 , V_253 , V_260 , 1 ,
V_466 ,
V_447 ,
V_380 ) ;
if ( V_47 )
F_24 ( V_6 , L_41 ,
V_37 , V_260 ) ;
F_165 ( & V_73 -> V_76 -> V_197 ) ;
if ( V_73 -> V_70 )
F_165 ( & V_73 -> V_70 -> V_197 ) ;
V_2 = V_208 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_251 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_467 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_27 ] ;
struct V_205 * V_70 ;
struct V_205 * V_266 ;
int V_2 ;
T_1 V_253 ;
F_250 ( V_465 ) ;
int V_244 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_27 ) ;
if ( V_47 )
F_11 ( V_6 , L_42 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (cq, tmp, cq_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_70 -> V_192 . V_185 == V_37 && ! F_70 ( & V_70 -> V_197 ) ) {
V_244 = V_70 -> V_192 . V_13 ;
V_2 = V_70 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_206 :
F_111 ( V_6 , V_244 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_70 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_27 ] ) ;
F_83 ( & V_70 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_27 , 1 , 0 ) ;
F_31 ( V_70 ) ;
V_2 = 0 ;
break;
case V_246 :
V_253 = V_37 ;
V_47 = F_194 ( V_6 , V_253 , V_244 , 1 ,
V_468 ,
V_447 ,
V_380 ) ;
if ( V_47 )
F_24 ( V_6 , L_43 ,
V_37 , V_244 ) ;
F_165 ( & V_70 -> V_76 -> V_197 ) ;
V_2 = V_206 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_252 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_469 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_29 ] ;
struct V_201 * V_78 ;
struct V_201 * V_266 ;
int V_2 ;
T_1 V_253 ;
F_250 ( V_465 ) ;
int V_470 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_29 ) ;
if ( V_47 )
F_11 ( V_6 , L_44 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (mpt, tmp, mpt_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_78 -> V_192 . V_185 == V_37 ) {
V_470 = V_78 -> V_192 . V_13 ;
V_2 = V_78 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_202 :
F_107 ( V_6 , V_78 -> V_200 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_78 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_29 ] ) ;
F_83 ( & V_78 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_29 , 1 , 0 ) ;
F_31 ( V_78 ) ;
V_2 = 0 ;
break;
case V_238 :
F_140 ( V_6 , V_78 -> V_200 ) ;
V_2 = V_202 ;
break;
case V_239 :
V_253 = V_37 ;
V_47 = F_194 ( V_6 , V_253 , V_470 , 0 ,
V_471 ,
V_447 ,
V_380 ) ;
if ( V_47 )
F_24 ( V_6 , L_45 ,
V_37 , V_470 ) ;
if ( V_78 -> V_76 )
F_165 ( & V_78 -> V_76 -> V_197 ) ;
V_2 = V_238 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_253 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_472 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_30 ] ;
struct V_199 * V_76 ;
struct V_199 * V_266 ;
int V_2 ;
F_250 ( V_465 ) ;
int V_216 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_30 ) ;
if ( V_47 )
F_11 ( V_6 , L_46 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (mtt, tmp, mtt_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_76 -> V_192 . V_185 == V_37 ) {
V_216 = V_76 -> V_192 . V_13 ;
V_2 = V_76 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_104 ( V_6 , V_216 ,
V_76 -> V_198 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_76 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_30 ] ) ;
F_83 ( & V_76 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 , V_30 ,
1 << V_76 -> V_198 , 0 ) ;
F_31 ( V_76 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_254 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_473 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_35 ] ;
struct V_213 * V_474 ;
struct V_213 * V_266 ;
int V_2 ;
T_1 V_216 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_35 ) ;
if ( V_47 )
F_11 ( V_6 , L_47 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (fs_rule, tmp, fs_rule_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_474 -> V_192 . V_185 == V_37 ) {
V_216 = V_474 -> V_192 . V_13 ;
V_2 = V_474 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_214 :
V_47 = F_194 ( V_6 , V_216 , 0 , 0 ,
V_453 ,
V_447 ,
V_380 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_474 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_35 ] ) ;
F_83 ( & V_474 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_31 ( V_474 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_255 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_475 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_33 ] ;
struct V_203 * V_241 ;
struct V_203 * V_266 ;
int V_47 ;
int V_2 ;
F_250 ( V_465 ) ;
int V_345 ;
struct V_113 * V_369 ;
V_47 = F_245 ( V_6 , V_37 , V_33 ) ;
if ( V_47 )
F_11 ( V_6 , L_48 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (eq, tmp, eq_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_241 -> V_192 . V_185 == V_37 ) {
V_345 = V_241 -> V_192 . V_13 ;
V_2 = V_241 -> V_192 . V_187 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_204 :
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_241 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_33 ] ) ;
F_83 ( & V_241 -> V_192 . V_221 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_31 ( V_241 ) ;
V_2 = 0 ;
break;
case V_243 :
V_369 = F_190 ( V_6 ) ;
if ( F_191 ( V_369 ) ) {
F_247 () ;
continue;
}
V_47 = F_256 ( V_6 , V_37 , 0 ,
V_345 & 0xff , 0 ,
V_476 ,
V_447 ,
V_380 ) ;
if ( V_47 )
F_24 ( V_6 , L_49 ,
V_37 , V_345 ) ;
F_195 ( V_6 , V_369 ) ;
F_165 ( & V_241 -> V_76 -> V_197 ) ;
V_2 = V_204 ;
break;
default:
V_2 = 0 ;
}
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_257 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_477 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_34 ] ;
struct V_209 * V_478 ;
struct V_209 * V_266 ;
int V_47 ;
int V_236 ;
V_47 = F_245 ( V_6 , V_37 , V_34 ) ;
if ( V_47 )
F_11 ( V_6 , L_50 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (counter, tmp, counter_list, com.list) {
if ( V_478 -> V_192 . V_185 == V_37 ) {
V_236 = V_478 -> V_192 . V_13 ;
F_68 ( & V_478 -> V_192 . V_15 ,
& V_219 -> V_91 [ V_34 ] ) ;
F_83 ( & V_478 -> V_192 . V_221 ) ;
F_31 ( V_478 ) ;
F_131 ( V_6 , V_236 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_258 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_218 * V_219 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_479 =
& V_219 -> V_84 [ V_37 ] . V_89 [ V_36 ] ;
struct V_211 * V_480 ;
struct V_211 * V_266 ;
int V_47 ;
int V_274 ;
V_47 = F_245 ( V_6 , V_37 , V_36 ) ;
if ( V_47 )
F_11 ( V_6 , L_51 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_480 -> V_192 . V_185 == V_37 ) {
V_274 = V_480 -> V_192 . V_13 ;
F_68 ( & V_480 -> V_192 . V_15 , & V_219 -> V_91 [ V_36 ] ) ;
F_83 ( & V_480 -> V_192 . V_221 ) ;
F_31 ( V_480 ) ;
F_134 ( V_6 , V_274 ) ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
}
void F_33 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
F_34 ( V_6 , V_37 ) ;
F_35 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_37 ] . V_90 ) ;
F_36 ( V_6 , V_37 ) ;
F_119 ( V_6 , V_37 ) ;
F_254 ( V_6 , V_37 ) ;
F_248 ( V_6 , V_37 ) ;
F_249 ( V_6 , V_37 ) ;
F_251 ( V_6 , V_37 ) ;
F_252 ( V_6 , V_37 ) ;
F_255 ( V_6 , V_37 ) ;
F_253 ( V_6 , V_37 ) ;
F_257 ( V_6 , V_37 ) ;
F_258 ( V_6 , V_37 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_37 ] . V_90 ) ;
}
void F_259 ( struct V_481 * V_482 )
{
struct V_483 * V_484 =
F_4 ( V_482 , struct V_483 , V_484 ) ;
struct V_113 * V_369 ;
struct V_438 * V_485 ;
struct V_5 * V_6 = & V_484 -> V_41 -> V_6 ;
struct V_218 * V_219 =
& V_484 -> V_41 -> V_44 . V_45 . V_46 ;
struct V_263 * V_462 =
& V_219 -> V_84 [ V_484 -> V_37 ] . V_89 [ V_26 ] ;
struct V_190 * V_67 ;
struct V_190 * V_266 ;
T_1 V_486 =
( ( 1ULL << V_487 ) |
( 1ULL << V_488 ) |
( 1ULL << V_489 ) |
( 1ULL << V_490 ) |
( 1ULL << V_491 ) |
( 1ULL << V_492 ) ) ;
T_1 V_493 = ( ( 1ULL << V_494 ) |
( 1ULL << V_495 ) |
( 1ULL << V_496 ) |
( 1ULL << V_497 ) |
( 1ULL << V_498 ) |
( 1ULL << V_499 ) |
( 1ULL << V_500 ) ) ;
int V_47 ;
int V_7 , V_501 = 0 ;
T_2 V_159 ;
if ( F_17 ( V_6 ) ) {
F_11 ( V_6 , L_52 ,
V_484 -> V_37 ) ;
goto V_61;
}
V_369 = F_190 ( V_6 ) ;
if ( F_191 ( V_369 ) )
goto V_61;
if ( V_484 -> V_126 & V_502 )
V_159 = V_160 |
V_161 |
V_162 |
V_163 |
V_164 |
V_165 ;
else if ( ! V_484 -> V_503 )
V_159 = V_160 |
V_165 ;
else
V_159 = V_160 |
V_163 |
V_164 ;
V_485 = V_369 -> V_116 ;
V_485 -> V_440 = F_232 ( 1ULL << V_504 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (qp, tmp, qp_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_67 -> V_192 . V_185 == V_484 -> V_37 ) {
if ( V_67 -> V_192 . V_187 != V_234 ||
! V_67 -> V_129 ||
F_43 ( V_6 , V_67 -> V_194 ) ||
V_67 -> V_333 & ( 1 << V_505 ) ) {
F_49 ( F_50 ( V_6 ) ) ;
continue;
}
V_7 = ( V_67 -> V_129 >> 6 & 1 ) + 1 ;
if ( V_7 != V_484 -> V_7 ) {
F_49 ( F_50 ( V_6 ) ) ;
continue;
}
if ( V_131 == ( ( V_67 -> V_333 >> 16 ) & 0xff ) )
V_485 -> V_439 = F_232 ( V_493 ) ;
else
V_485 -> V_439 =
F_232 ( V_493 | V_486 ) ;
if ( V_484 -> V_503 == V_144 ) {
V_485 -> V_444 . V_150 = V_67 -> V_150 ;
V_485 -> V_444 . V_128 . V_159 = V_67 -> V_159 ;
V_485 -> V_444 . V_128 . V_166 = V_67 -> V_166 ;
V_485 -> V_444 . V_128 . V_168 = V_67 -> V_168 ;
V_485 -> V_444 . V_128 . V_170 = V_67 -> V_332 ;
V_485 -> V_444 . V_128 . V_173 = V_67 -> V_173 ;
V_485 -> V_444 . V_128 . V_129 =
V_67 -> V_129 ;
} else {
V_485 -> V_444 . V_150 = V_67 -> V_150 & ~ F_44 ( V_151 ) ;
V_485 -> V_444 . V_128 . V_159 = V_159 ;
V_485 -> V_444 . V_128 . V_168 = V_484 -> V_506 ;
V_485 -> V_444 . V_128 . V_166 =
V_67 -> V_166 | V_167 ;
V_485 -> V_444 . V_128 . V_170 =
V_67 -> V_332 | V_171 | V_172 ;
V_485 -> V_444 . V_128 . V_173 =
V_67 -> V_173 | V_174 | V_175 ;
V_485 -> V_444 . V_128 . V_129 =
V_67 -> V_129 & 0xC7 ;
V_485 -> V_444 . V_128 . V_129 |=
( ( V_484 -> V_507 & 0x7 ) << 3 ) ;
}
V_47 = F_194 ( V_6 , V_369 -> V_377 ,
V_67 -> V_194 & 0xffffff ,
0 , V_446 ,
V_508 , V_380 ) ;
if ( V_47 ) {
F_260 ( V_6 , L_53 ,
V_484 -> V_37 , V_7 , V_67 -> V_194 , V_47 ) ;
V_501 ++ ;
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
F_195 ( V_6 , V_369 ) ;
if ( V_501 )
F_185 ( V_6 , L_54 ,
V_501 , V_484 -> V_37 , V_484 -> V_7 ) ;
if ( V_484 -> V_126 & V_509 && ! V_501 &&
V_510 != V_484 -> V_511 )
F_126 ( & V_484 -> V_41 -> V_6 , V_484 -> V_7 ,
V_484 -> V_512 ) ;
V_61:
F_31 ( V_484 ) ;
return;
}
