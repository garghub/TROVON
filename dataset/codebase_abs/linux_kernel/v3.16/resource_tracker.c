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
int V_7 ;
V_7 = ( V_138 -> V_128 . V_129 & 0x40 ) ? 2 : 1 ;
V_41 = V_40 ( V_6 ) ;
V_140 = & V_41 -> V_44 . V_45 . V_141 [ V_37 ] . V_142 [ V_7 ] ;
if ( V_143 != V_140 -> V_2 . V_144 ) {
if ( F_43 ( V_6 , V_137 ) )
return 0 ;
V_138 -> V_145 &= ~ F_44 ( V_146 ) ;
if ( V_140 -> V_2 . V_147 == V_148 &&
V_6 -> V_8 . V_149 & V_150 ) {
V_138 -> V_128 . V_151 =
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 ;
} else if ( 0 != V_140 -> V_2 . V_144 ) {
V_138 -> V_128 . V_151 =
V_152 |
V_155 |
V_156 ;
} else {
V_138 -> V_128 . V_151 =
V_152 |
V_157 ;
}
V_138 -> V_128 . V_158 |= V_159 ;
V_138 -> V_128 . V_160 = V_140 -> V_161 ;
V_138 -> V_128 . V_162 |= V_163 | V_164 ;
V_138 -> V_128 . V_165 |= V_166 | V_167 ;
V_138 -> V_128 . V_129 &= 0xC7 ;
V_138 -> V_128 . V_129 |= ( V_140 -> V_2 . V_168 ) << 3 ;
}
if ( V_140 -> V_2 . V_169 ) {
V_138 -> V_128 . V_165 |= V_170 ;
V_138 -> V_128 . V_171 = ( 0x80 & V_138 -> V_128 . V_171 ) + V_140 -> V_172 ;
}
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
return V_6 -> V_8 . V_79 - 1 ;
}
static void * F_46 ( struct V_5 * V_6 , T_1 V_13 ,
enum V_24 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
return F_3 ( & V_41 -> V_44 . V_45 . V_46 . V_91 [ type ] ,
V_13 ) ;
}
static int F_47 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type ,
void * V_17 )
{
struct V_16 * V_173 ;
int V_47 = 0 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_46 ( V_6 , V_13 , type ) ;
if ( ! V_173 ) {
V_47 = - V_174 ;
goto exit;
}
if ( V_173 -> V_2 == V_175 ) {
V_47 = - V_176 ;
goto exit;
}
if ( V_173 -> V_177 != V_37 ) {
V_47 = - V_178 ;
goto exit;
}
V_173 -> V_179 = V_173 -> V_2 ;
V_173 -> V_2 = V_175 ;
if ( V_17 )
* ( (struct V_16 * * ) V_17 ) = V_173 ;
exit:
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
int F_51 ( struct V_5 * V_6 ,
enum V_24 type ,
T_1 V_13 , int * V_37 )
{
struct V_16 * V_173 ;
int V_47 = - V_180 ;
int V_181 = V_13 ;
if ( type == V_26 )
V_181 &= 0x7fffff ;
F_10 ( F_49 ( V_6 ) ) ;
V_173 = F_46 ( V_6 , V_181 , type ) ;
if ( V_173 ) {
* V_37 = V_173 -> V_177 ;
V_47 = 0 ;
}
F_12 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static void F_52 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type )
{
struct V_16 * V_173 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_46 ( V_6 , V_13 , type ) ;
if ( V_173 )
V_173 -> V_2 = V_173 -> V_179 ;
F_50 ( F_49 ( V_6 ) ) ;
}
static struct V_16 * F_53 ( int V_181 )
{
struct V_182 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_185 ;
V_183 -> V_186 = V_181 ;
F_22 ( & V_183 -> V_187 ) ;
F_26 ( & V_183 -> V_188 ) ;
F_54 ( & V_183 -> V_189 , 0 ) ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_55 ( int V_181 , int V_190 )
{
struct V_191 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_190 = V_190 ;
V_183 -> V_184 . V_2 = V_4 ;
F_54 ( & V_183 -> V_189 , 0 ) ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_56 ( int V_181 , int V_192 )
{
struct V_193 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_194 ;
V_183 -> V_192 = V_192 ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_57 ( int V_181 )
{
struct V_195 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_196 ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_58 ( int V_181 )
{
struct V_197 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_198 ;
F_54 ( & V_183 -> V_189 , 0 ) ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_59 ( int V_181 )
{
struct V_199 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_200 ;
F_54 ( & V_183 -> V_189 , 0 ) ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_60 ( int V_181 )
{
struct V_201 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_202 ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_61 ( int V_181 )
{
struct V_203 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_204 ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_62 ( T_1 V_181 , int V_137 )
{
struct V_205 * V_183 ;
V_183 = F_21 ( sizeof *V_183 , V_86 ) ;
if ( ! V_183 )
return NULL ;
V_183 -> V_184 . V_13 = V_181 ;
V_183 -> V_184 . V_2 = V_206 ;
V_183 -> V_137 = V_137 ;
return & V_183 -> V_184 ;
}
static struct V_16 * F_63 ( T_1 V_181 , enum V_24 type , int V_37 ,
int V_207 )
{
struct V_16 * V_183 ;
switch ( type ) {
case V_26 :
V_183 = F_53 ( V_181 ) ;
break;
case V_29 :
V_183 = F_56 ( V_181 , V_207 ) ;
break;
case V_30 :
V_183 = F_55 ( V_181 , V_207 ) ;
break;
case V_33 :
V_183 = F_57 ( V_181 ) ;
break;
case V_27 :
V_183 = F_58 ( V_181 ) ;
break;
case V_28 :
V_183 = F_59 ( V_181 ) ;
break;
case V_31 :
F_64 ( L_19 ) ;
return NULL ;
case V_34 :
V_183 = F_60 ( V_181 ) ;
break;
case V_36 :
V_183 = F_61 ( V_181 ) ;
break;
case V_35 :
V_183 = F_62 ( V_181 , V_207 ) ;
break;
default:
return NULL ;
}
if ( V_183 )
V_183 -> V_177 = V_37 ;
return V_183 ;
}
static int F_65 ( struct V_5 * V_6 , int V_37 , T_1 V_208 , int V_39 ,
enum V_24 type , int V_207 )
{
int V_81 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_16 * * V_209 ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_11 * V_12 = & V_211 -> V_91 [ type ] ;
V_209 = F_21 ( V_39 * sizeof *V_209 , V_86 ) ;
if ( ! V_209 )
return - V_87 ;
for ( V_81 = 0 ; V_81 < V_39 ; ++ V_81 ) {
V_209 [ V_81 ] = F_63 ( V_208 + V_81 , type , V_37 , V_207 ) ;
if ( ! V_209 [ V_81 ] ) {
for ( -- V_81 ; V_81 >= 0 ; -- V_81 )
F_31 ( V_209 [ V_81 ] ) ;
F_31 ( V_209 ) ;
return - V_87 ;
}
}
F_48 ( F_49 ( V_6 ) ) ;
for ( V_81 = 0 ; V_81 < V_39 ; ++ V_81 ) {
if ( F_46 ( V_6 , V_208 + V_81 , type ) ) {
V_47 = - V_23 ;
goto V_212;
}
V_47 = F_5 ( V_12 , V_209 [ V_81 ] ) ;
if ( V_47 )
goto V_212;
F_66 ( & V_209 [ V_81 ] -> V_213 ,
& V_211 -> V_84 [ V_37 ] . V_89 [ type ] ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
F_31 ( V_209 ) ;
return 0 ;
V_212:
for ( -- V_81 ; V_81 >= V_208 ; -- V_81 )
F_67 ( & V_209 [ V_81 ] -> V_15 , V_12 ) ;
F_50 ( F_49 ( V_6 ) ) ;
for ( V_81 = 0 ; V_81 < V_39 ; ++ V_81 )
F_31 ( V_209 [ V_81 ] ) ;
F_31 ( V_209 ) ;
return V_47 ;
}
static int F_68 ( struct V_182 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_214 || F_69 ( & V_17 -> V_189 ) ||
! F_70 ( & V_17 -> V_187 ) ) {
F_64 ( L_20 ,
V_17 -> V_184 . V_2 , F_69 ( & V_17 -> V_189 ) ) ;
return - V_176 ;
} else if ( V_17 -> V_184 . V_2 != V_185 ) {
return - V_178 ;
}
return 0 ;
}
static int F_71 ( struct V_191 * V_17 , int V_190 )
{
if ( V_17 -> V_184 . V_2 == V_3 ||
F_69 ( & V_17 -> V_189 ) ) {
F_72 ( L_21 ,
V_215 , __LINE__ ,
F_1 ( V_17 -> V_184 . V_2 ) ,
F_69 ( & V_17 -> V_189 ) ) ;
return - V_176 ;
} else if ( V_17 -> V_184 . V_2 != V_4 )
return - V_178 ;
else if ( V_17 -> V_190 != V_190 )
return - V_48 ;
return 0 ;
}
static int F_73 ( struct V_193 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_216 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_194 )
return - V_178 ;
return 0 ;
}
static int F_74 ( struct V_195 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_216 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_194 )
return - V_178 ;
return 0 ;
}
static int F_75 ( struct V_201 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_217 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_202 )
return - V_178 ;
return 0 ;
}
static int F_76 ( struct V_203 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_218 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_204 )
return - V_178 ;
return 0 ;
}
static int F_77 ( struct V_205 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_219 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_206 )
return - V_178 ;
return 0 ;
}
static int F_78 ( struct V_197 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_220 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_198 )
return - V_178 ;
return 0 ;
}
static int F_79 ( struct V_199 * V_17 )
{
if ( V_17 -> V_184 . V_2 == V_221 )
return - V_176 ;
else if ( V_17 -> V_184 . V_2 != V_200 )
return - V_178 ;
return 0 ;
}
static int F_80 ( struct V_16 * V_17 , enum V_24 type , int V_207 )
{
switch ( type ) {
case V_26 :
return F_68 ( (struct V_182 * ) V_17 ) ;
case V_27 :
return F_78 ( (struct V_197 * ) V_17 ) ;
case V_28 :
return F_79 ( (struct V_199 * ) V_17 ) ;
case V_29 :
return F_73 ( (struct V_193 * ) V_17 ) ;
case V_30 :
return F_71 ( (struct V_191 * ) V_17 , V_207 ) ;
case V_31 :
return - V_222 ;
case V_33 :
return F_74 ( (struct V_195 * ) V_17 ) ;
case V_34 :
return F_75 ( (struct V_201 * ) V_17 ) ;
case V_36 :
return F_76 ( (struct V_203 * ) V_17 ) ;
case V_35 :
return F_77 ( (struct V_205 * ) V_17 ) ;
default:
return - V_48 ;
}
}
static int F_81 ( struct V_5 * V_6 , int V_37 , T_1 V_208 , int V_39 ,
enum V_24 type , int V_207 )
{
T_1 V_81 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_173 ;
F_48 ( F_49 ( V_6 ) ) ;
for ( V_81 = V_208 ; V_81 < V_208 + V_39 ; ++ V_81 ) {
V_173 = F_3 ( & V_211 -> V_91 [ type ] , V_81 ) ;
if ( ! V_173 ) {
V_47 = - V_180 ;
goto V_61;
}
if ( V_173 -> V_177 != V_37 ) {
V_47 = - V_178 ;
goto V_61;
}
V_47 = F_80 ( V_173 , type , V_207 ) ;
if ( V_47 )
goto V_61;
}
for ( V_81 = V_208 ; V_81 < V_208 + V_39 ; ++ V_81 ) {
V_173 = F_3 ( & V_211 -> V_91 [ type ] , V_81 ) ;
F_67 ( & V_173 -> V_15 , & V_211 -> V_91 [ type ] ) ;
F_82 ( & V_173 -> V_213 ) ;
F_31 ( V_173 ) ;
}
V_47 = 0 ;
V_61:
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static int F_83 ( struct V_5 * V_6 , int V_37 , int V_137 ,
enum V_223 V_2 , struct V_182 * * V_67 ,
int V_224 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_182 * V_173 ;
int V_47 = 0 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ V_26 ] , V_137 ) ;
if ( ! V_173 )
V_47 = - V_180 ;
else if ( V_173 -> V_184 . V_177 != V_37 )
V_47 = - V_178 ;
else {
switch ( V_2 ) {
case V_214 :
F_24 ( V_6 , L_22 ,
V_215 , V_173 -> V_184 . V_13 ) ;
V_47 = - V_176 ;
break;
case V_185 :
if ( V_173 -> V_184 . V_2 == V_225 && ! V_224 )
break;
F_24 ( V_6 , L_23 , V_173 -> V_184 . V_13 ) ;
V_47 = - V_48 ;
break;
case V_225 :
if ( ( V_173 -> V_184 . V_2 == V_185 && V_224 ) ||
V_173 -> V_184 . V_2 == V_226 )
break;
else {
F_24 ( V_6 , L_23 ,
V_173 -> V_184 . V_13 ) ;
V_47 = - V_48 ;
}
break;
case V_226 :
if ( V_173 -> V_184 . V_2 != V_225 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_173 -> V_184 . V_179 = V_173 -> V_184 . V_2 ;
V_173 -> V_184 . V_227 = V_2 ;
V_173 -> V_184 . V_2 = V_214 ;
if ( V_67 )
* V_67 = V_173 ;
}
}
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static int F_84 ( struct V_5 * V_6 , int V_37 , int V_228 ,
enum V_229 V_2 , struct V_193 * * V_78 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_193 * V_173 ;
int V_47 = 0 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ V_29 ] , V_228 ) ;
if ( ! V_173 )
V_47 = - V_180 ;
else if ( V_173 -> V_184 . V_177 != V_37 )
V_47 = - V_178 ;
else {
switch ( V_2 ) {
case V_216 :
V_47 = - V_48 ;
break;
case V_194 :
if ( V_173 -> V_184 . V_2 != V_230 )
V_47 = - V_48 ;
break;
case V_230 :
if ( V_173 -> V_184 . V_2 != V_194 &&
V_173 -> V_184 . V_2 != V_231 )
V_47 = - V_48 ;
break;
case V_231 :
if ( V_173 -> V_184 . V_2 != V_230 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_173 -> V_184 . V_179 = V_173 -> V_184 . V_2 ;
V_173 -> V_184 . V_227 = V_2 ;
V_173 -> V_184 . V_2 = V_216 ;
if ( V_78 )
* V_78 = V_173 ;
}
}
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static int F_85 ( struct V_5 * V_6 , int V_37 , int V_228 ,
enum V_232 V_2 , struct V_195 * * V_233 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_195 * V_173 ;
int V_47 = 0 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ V_33 ] , V_228 ) ;
if ( ! V_173 )
V_47 = - V_180 ;
else if ( V_173 -> V_184 . V_177 != V_37 )
V_47 = - V_178 ;
else {
switch ( V_2 ) {
case V_234 :
V_47 = - V_48 ;
break;
case V_196 :
if ( V_173 -> V_184 . V_2 != V_235 )
V_47 = - V_48 ;
break;
case V_235 :
if ( V_173 -> V_184 . V_2 != V_196 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_173 -> V_184 . V_179 = V_173 -> V_184 . V_2 ;
V_173 -> V_184 . V_227 = V_2 ;
V_173 -> V_184 . V_2 = V_234 ;
if ( V_233 )
* V_233 = V_173 ;
}
}
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static int F_86 ( struct V_5 * V_6 , int V_37 , int V_236 ,
enum V_237 V_2 , struct V_197 * * V_70 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_197 * V_173 ;
int V_47 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ V_27 ] , V_236 ) ;
if ( ! V_173 ) {
V_47 = - V_180 ;
} else if ( V_173 -> V_184 . V_177 != V_37 ) {
V_47 = - V_178 ;
} else if ( V_2 == V_198 ) {
if ( V_173 -> V_184 . V_2 != V_238 )
V_47 = - V_48 ;
else if ( F_69 ( & V_173 -> V_189 ) )
V_47 = - V_176 ;
else
V_47 = 0 ;
} else if ( V_2 != V_238 || V_173 -> V_184 . V_2 != V_198 ) {
V_47 = - V_48 ;
} else {
V_47 = 0 ;
}
if ( ! V_47 ) {
V_173 -> V_184 . V_179 = V_173 -> V_184 . V_2 ;
V_173 -> V_184 . V_227 = V_2 ;
V_173 -> V_184 . V_2 = V_220 ;
if ( V_70 )
* V_70 = V_173 ;
}
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static int F_87 ( struct V_5 * V_6 , int V_37 , int V_228 ,
enum V_239 V_2 , struct V_199 * * V_73 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_199 * V_173 ;
int V_47 = 0 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ V_28 ] , V_228 ) ;
if ( ! V_173 ) {
V_47 = - V_180 ;
} else if ( V_173 -> V_184 . V_177 != V_37 ) {
V_47 = - V_178 ;
} else if ( V_2 == V_200 ) {
if ( V_173 -> V_184 . V_2 != V_240 )
V_47 = - V_48 ;
else if ( F_69 ( & V_173 -> V_189 ) )
V_47 = - V_176 ;
} else if ( V_2 != V_240 || V_173 -> V_184 . V_2 != V_200 ) {
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_173 -> V_184 . V_179 = V_173 -> V_184 . V_2 ;
V_173 -> V_184 . V_227 = V_2 ;
V_173 -> V_184 . V_2 = V_221 ;
if ( V_73 )
* V_73 = V_173 ;
}
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static void F_88 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_181 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_173 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ type ] , V_181 ) ;
if ( V_173 && ( V_173 -> V_177 == V_37 ) )
V_173 -> V_2 = V_173 -> V_179 ;
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_89 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_181 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_173 ;
F_48 ( F_49 ( V_6 ) ) ;
V_173 = F_3 ( & V_211 -> V_91 [ type ] , V_181 ) ;
if ( V_173 && ( V_173 -> V_177 == V_37 ) )
V_173 -> V_2 = V_173 -> V_227 ;
F_50 ( F_49 ( V_6 ) ) ;
}
static int F_90 ( struct V_5 * V_6 , int V_37 , int V_137 )
{
return F_43 ( V_6 , V_137 ) &&
( F_91 ( V_6 ) || F_92 ( V_6 , V_37 , V_137 ) ) ;
}
static int F_93 ( struct V_5 * V_6 , int V_137 )
{
return V_137 < V_6 -> V_8 . V_241 [ V_242 ] ;
}
static int F_94 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_47 ;
int V_39 ;
int V_247 ;
int V_208 ;
int V_137 ;
switch ( V_243 ) {
case V_248 :
V_39 = F_95 ( & V_245 ) ;
V_247 = F_96 ( & V_245 ) ;
V_47 = F_9 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_97 ( V_6 , V_39 , V_247 , & V_208 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
return V_47 ;
}
V_47 = F_65 ( V_6 , V_37 , V_208 , V_39 , V_26 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_98 ( V_6 , V_208 , V_39 ) ;
return V_47 ;
}
F_99 ( V_246 , V_208 ) ;
break;
case V_249 :
V_137 = F_95 ( & V_245 ) & 0x7fffff ;
if ( F_90 ( V_6 , V_37 , V_137 ) ) {
V_47 = F_65 ( V_6 , V_37 , V_137 , 1 , V_26 , 0 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_83 ( V_6 , V_37 , V_137 , V_225 ,
NULL , 1 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_93 ( V_6 , V_137 ) ) {
V_47 = F_100 ( V_6 , V_137 , V_86 ) ;
if ( V_47 ) {
F_88 ( V_6 , V_37 , V_26 , V_137 ) ;
return V_47 ;
}
}
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_101 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_47 = - V_48 ;
int V_208 ;
int V_190 ;
if ( V_243 != V_250 )
return V_47 ;
V_190 = F_95 ( & V_245 ) ;
V_47 = F_9 ( V_6 , V_37 , V_30 , 1 << V_190 , 0 ) ;
if ( V_47 )
return V_47 ;
V_208 = F_102 ( V_6 , V_190 ) ;
if ( V_208 == - 1 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_190 , 0 ) ;
return - V_87 ;
}
V_47 = F_65 ( V_6 , V_37 , V_208 , 1 , V_30 , V_190 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_190 , 0 ) ;
F_103 ( V_6 , V_208 , V_190 ) ;
} else {
F_99 ( V_246 , V_208 ) ;
}
return V_47 ;
}
static int F_104 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_47 = - V_48 ;
int V_228 ;
int V_181 ;
struct V_193 * V_78 ;
switch ( V_243 ) {
case V_248 :
V_47 = F_9 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
if ( V_47 )
break;
V_228 = F_105 ( V_6 ) ;
if ( V_228 == - 1 ) {
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
break;
}
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_65 ( V_6 , V_37 , V_181 , 1 , V_29 , V_228 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_106 ( V_6 , V_228 ) ;
break;
}
F_99 ( V_246 , V_228 ) ;
break;
case V_249 :
V_228 = F_95 ( & V_245 ) ;
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_84 ( V_6 , V_37 , V_181 ,
V_230 , & V_78 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_107 ( V_6 , V_78 -> V_192 , V_86 ) ;
if ( V_47 ) {
F_88 ( V_6 , V_37 , V_29 , V_181 ) ;
return V_47 ;
}
F_89 ( V_6 , V_37 , V_29 , V_181 ) ;
break;
}
return V_47 ;
}
static int F_108 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_236 ;
int V_47 ;
switch ( V_243 ) {
case V_250 :
V_47 = F_9 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_109 ( V_6 , & V_236 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
break;
}
V_47 = F_65 ( V_6 , V_37 , V_236 , 1 , V_27 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_110 ( V_6 , V_236 ) ;
break;
}
F_99 ( V_246 , V_236 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_111 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_251 ;
int V_47 ;
switch ( V_243 ) {
case V_250 :
V_47 = F_9 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_112 ( V_6 , & V_251 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
break;
}
V_47 = F_65 ( V_6 , V_37 , V_251 , 1 , V_28 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_113 ( V_6 , V_251 ) ;
break;
}
F_99 ( V_246 , V_251 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_114 ( struct V_5 * V_6 , int V_37 , int V_7 ,
T_2 V_252 , T_1 * V_253 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_255 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_256 * V_17 , * V_257 ;
F_115 (res, tmp, mac_list, list) {
if ( V_17 -> V_252 == V_252 && V_17 -> V_7 == ( T_2 ) V_7 ) {
* V_253 = V_17 -> V_253 ;
return 0 ;
}
}
return - V_180 ;
}
static int F_116 ( struct V_5 * V_6 , int V_37 , T_1 V_253 , int V_7 , T_2 V_252 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_255 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_256 * V_17 , * V_257 ;
F_115 (res, tmp, mac_list, list) {
if ( V_17 -> V_253 == V_253 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_189 ;
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
V_17 -> V_253 = V_253 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_252 = V_252 ;
V_17 -> V_189 = 1 ;
F_66 ( & V_17 -> V_213 ,
& V_211 -> V_84 [ V_37 ] . V_89 [ V_31 ] ) ;
return 0 ;
}
static void F_117 ( struct V_5 * V_6 , int V_37 , T_1 V_253 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_255 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_256 * V_17 , * V_257 ;
F_115 (res, tmp, mac_list, list) {
if ( V_17 -> V_253 == V_253 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_189 ) {
F_82 ( & V_17 -> V_213 ) ;
F_13 ( V_6 , V_37 , V_31 , 1 , V_7 ) ;
F_31 ( V_17 ) ;
}
break;
}
}
}
static void F_118 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_255 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
struct V_256 * V_17 , * V_257 ;
int V_81 ;
F_115 (res, tmp, mac_list, list) {
F_82 ( & V_17 -> V_213 ) ;
for ( V_81 = 0 ; V_81 < V_17 -> V_189 ; V_81 ++ )
F_119 ( V_6 , V_17 -> V_7 , V_17 -> V_253 ) ;
F_13 ( V_6 , V_37 , V_31 , 1 , V_17 -> V_7 ) ;
F_31 ( V_17 ) ;
}
}
static int F_120 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 , int V_258 )
{
int V_47 = - V_48 ;
int V_7 ;
T_1 V_253 ;
T_2 V_252 ;
if ( V_243 != V_250 )
return V_47 ;
V_7 = ! V_258 ? F_95 ( V_246 ) : V_258 ;
V_7 = F_121 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
V_253 = V_245 ;
V_47 = F_122 ( V_6 , V_7 , V_253 ) ;
if ( V_47 >= 0 ) {
V_252 = V_47 ;
F_99 ( V_246 , V_47 ) ;
V_47 = 0 ;
}
if ( ! V_47 ) {
V_47 = F_116 ( V_6 , V_37 , V_253 , V_7 , V_252 ) ;
if ( V_47 )
F_119 ( V_6 , V_7 , V_253 ) ;
}
return V_47 ;
}
static int F_123 ( struct V_5 * V_6 , int V_37 , T_4 V_259 ,
int V_7 , int V_160 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_260 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_32 ] ;
struct V_261 * V_17 , * V_257 ;
F_115 (res, tmp, vlan_list, list) {
if ( V_17 -> V_259 == V_259 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_189 ;
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
V_17 -> V_259 = V_259 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_160 = V_160 ;
V_17 -> V_189 = 1 ;
F_66 ( & V_17 -> V_213 ,
& V_211 -> V_84 [ V_37 ] . V_89 [ V_32 ] ) ;
return 0 ;
}
static void F_124 ( struct V_5 * V_6 , int V_37 , T_4 V_259 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_260 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_32 ] ;
struct V_261 * V_17 , * V_257 ;
F_115 (res, tmp, vlan_list, list) {
if ( V_17 -> V_259 == V_259 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_189 ) {
F_82 ( & V_17 -> V_213 ) ;
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
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_260 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_32 ] ;
struct V_261 * V_17 , * V_257 ;
int V_81 ;
F_115 (res, tmp, vlan_list, list) {
F_82 ( & V_17 -> V_213 ) ;
for ( V_81 = 0 ; V_81 < V_17 -> V_189 ; V_81 ++ )
F_125 ( V_6 , V_17 -> V_7 , V_17 -> V_259 ) ;
F_13 ( V_6 , V_37 , V_32 , 1 , V_17 -> V_7 ) ;
F_31 ( V_17 ) ;
}
}
static int F_126 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 , int V_258 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_262 * V_263 = V_41 -> V_44 . V_45 . V_263 ;
int V_47 ;
T_4 V_259 ;
int V_160 ;
int V_7 ;
V_7 = ! V_258 ? F_95 ( V_246 ) : V_258 ;
if ( ! V_7 || V_243 != V_250 )
return - V_48 ;
V_7 = F_121 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
if ( ! V_258 && V_7 > 0 && V_7 <= V_6 -> V_8 . V_98 ) {
V_263 [ V_37 ] . V_264 = true ;
return 0 ;
}
V_259 = ( T_4 ) V_245 ;
V_47 = F_127 ( V_6 , V_7 , V_259 , & V_160 ) ;
if ( ! V_47 ) {
F_99 ( V_246 , ( T_3 ) V_160 ) ;
V_47 = F_123 ( V_6 , V_37 , V_259 , V_7 , V_160 ) ;
if ( V_47 )
F_125 ( V_6 , V_7 , V_259 ) ;
}
return V_47 ;
}
static int F_128 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
T_3 V_228 ;
int V_47 ;
if ( V_243 != V_248 )
return - V_48 ;
V_47 = F_9 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_129 ( V_6 , & V_228 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
V_47 = F_65 ( V_6 , V_37 , V_228 , 1 , V_34 , 0 ) ;
if ( V_47 ) {
F_130 ( V_6 , V_228 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
} else {
F_99 ( V_246 , V_228 ) ;
}
return V_47 ;
}
static int F_131 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
T_3 V_265 ;
int V_47 ;
if ( V_243 != V_248 )
return - V_48 ;
V_47 = F_132 ( V_6 , & V_265 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_65 ( V_6 , V_37 , V_265 , 1 , V_36 , 0 ) ;
if ( V_47 )
F_133 ( V_6 , V_265 ) ;
else
F_99 ( V_246 , V_265 ) ;
return V_47 ;
}
int F_134 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_270 = V_267 -> V_271 ;
switch ( V_267 -> V_272 & 0xFF ) {
case V_26 :
V_47 = F_94 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_30 :
V_47 = F_101 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_29 :
V_47 = F_104 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_27 :
V_47 = F_108 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_28 :
V_47 = F_111 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_31 :
V_47 = F_120 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ,
( V_267 -> V_272 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_126 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ,
( V_267 -> V_272 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_128 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_36 :
V_47 = F_131 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_135 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 )
{
int V_47 ;
int V_39 ;
int V_208 ;
int V_137 ;
switch ( V_243 ) {
case V_248 :
V_208 = F_95 ( & V_245 ) & 0x7fffff ;
V_39 = F_96 ( & V_245 ) ;
V_47 = F_81 ( V_6 , V_37 , V_208 , V_39 , V_26 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_98 ( V_6 , V_208 , V_39 ) ;
break;
case V_249 :
V_137 = F_95 ( & V_245 ) & 0x7fffff ;
V_47 = F_83 ( V_6 , V_37 , V_137 , V_185 ,
NULL , 0 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_93 ( V_6 , V_137 ) )
F_136 ( V_6 , V_137 ) ;
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
if ( F_90 ( V_6 , V_37 , V_137 ) )
V_47 = F_81 ( V_6 , V_37 , V_137 , 1 , V_26 , 0 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_137 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_47 = - V_48 ;
int V_208 ;
int V_190 ;
if ( V_243 != V_250 )
return V_47 ;
V_208 = F_95 ( & V_245 ) ;
V_190 = F_96 ( & V_245 ) ;
V_47 = F_81 ( V_6 , V_37 , V_208 , 1 , V_30 , V_190 ) ;
if ( ! V_47 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_190 , 0 ) ;
F_103 ( V_6 , V_208 , V_190 ) ;
}
return V_47 ;
}
static int F_138 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 )
{
int V_47 = - V_48 ;
int V_228 ;
int V_181 ;
struct V_193 * V_78 ;
switch ( V_243 ) {
case V_248 :
V_228 = F_95 ( & V_245 ) ;
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_47 ( V_6 , V_37 , V_181 , V_29 , & V_78 ) ;
if ( V_47 )
break;
V_228 = V_78 -> V_192 ;
F_52 ( V_6 , V_37 , V_181 , V_29 ) ;
V_47 = F_81 ( V_6 , V_37 , V_181 , 1 , V_29 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_106 ( V_6 , V_228 ) ;
break;
case V_249 :
V_228 = F_95 ( & V_245 ) ;
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_84 ( V_6 , V_37 , V_181 ,
V_194 , & V_78 ) ;
if ( V_47 )
return V_47 ;
F_139 ( V_6 , V_78 -> V_192 ) ;
F_89 ( V_6 , V_37 , V_29 , V_181 ) ;
return V_47 ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_140 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_236 ;
int V_47 ;
switch ( V_243 ) {
case V_250 :
V_236 = F_95 ( & V_245 ) ;
V_47 = F_81 ( V_6 , V_37 , V_236 , 1 , V_27 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_110 ( V_6 , V_236 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_141 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_251 ;
int V_47 ;
switch ( V_243 ) {
case V_250 :
V_251 = F_95 ( & V_245 ) ;
V_47 = F_81 ( V_6 , V_37 , V_251 , 1 , V_28 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_113 ( V_6 , V_251 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_142 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 , int V_258 )
{
int V_7 ;
int V_47 = 0 ;
switch ( V_243 ) {
case V_250 :
V_7 = ! V_258 ? F_95 ( V_246 ) : V_258 ;
V_7 = F_121 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
F_117 ( V_6 , V_37 , V_245 , V_7 ) ;
F_119 ( V_6 , V_7 , V_245 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_143 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 , int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_262 * V_263 = V_41 -> V_44 . V_45 . V_263 ;
int V_47 = 0 ;
V_7 = F_121 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
switch ( V_243 ) {
case V_250 :
if ( V_263 [ V_37 ] . V_264 )
return 0 ;
if ( ! V_7 )
return - V_48 ;
F_124 ( V_6 , V_37 , V_245 , V_7 ) ;
F_125 ( V_6 , V_7 , V_245 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_144 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_228 ;
int V_47 ;
if ( V_243 != V_248 )
return - V_48 ;
V_228 = F_95 ( & V_245 ) ;
V_47 = F_81 ( V_6 , V_37 , V_228 , 1 , V_34 , 0 ) ;
if ( V_47 )
return V_47 ;
F_130 ( V_6 , V_228 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
static int F_145 ( struct V_5 * V_6 , int V_37 , int V_243 , int V_244 ,
T_1 V_245 , T_1 * V_246 )
{
int V_265 ;
int V_47 ;
if ( V_243 != V_248 )
return - V_48 ;
V_265 = F_95 ( & V_245 ) ;
V_47 = F_81 ( V_6 , V_37 , V_265 , 1 , V_36 , 0 ) ;
if ( V_47 )
return V_47 ;
F_133 ( V_6 , V_265 ) ;
return V_47 ;
}
int F_146 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 = - V_48 ;
int V_270 = V_267 -> V_271 ;
switch ( V_267 -> V_272 & 0xFF ) {
case V_26 :
V_47 = F_135 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 ) ;
break;
case V_30 :
V_47 = F_137 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_29 :
V_47 = F_138 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 ) ;
break;
case V_27 :
V_47 = F_140 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_28 :
V_47 = F_141 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_31 :
V_47 = F_142 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ,
( V_267 -> V_272 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_143 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ,
( V_267 -> V_272 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_144 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
break;
case V_36 :
V_47 = F_145 ( V_6 , V_37 , V_267 -> V_271 , V_270 ,
V_267 -> V_245 , & V_267 -> V_246 ) ;
default:
break;
}
return V_47 ;
}
static int F_147 ( struct V_273 * V_78 )
{
return ( F_40 ( V_78 -> V_126 ) >> 9 ) & 1 ;
}
static int F_148 ( struct V_273 * V_78 )
{
return ( int ) F_149 ( V_78 -> V_274 ) & 0xfffffff8 ;
}
static int F_150 ( struct V_273 * V_78 )
{
return F_40 ( V_78 -> V_275 ) ;
}
static T_3 F_151 ( struct V_273 * V_78 )
{
return F_40 ( V_78 -> V_276 ) & 0x00ffffff ;
}
static int F_152 ( struct V_273 * V_78 )
{
return F_40 ( V_78 -> V_276 ) & V_277 ;
}
static int F_153 ( struct V_273 * V_78 )
{
return F_40 ( V_78 -> V_126 ) & V_278 ;
}
static int F_154 ( struct V_273 * V_78 )
{
return F_40 ( V_78 -> V_126 ) & V_279 ;
}
static int F_155 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_280 ) & 0xfffffff8 ;
}
static int F_156 ( struct V_281 * V_282 )
{
return F_40 ( V_282 -> V_280 ) & 0xfffffff8 ;
}
static int F_157 ( struct V_120 * V_138 )
{
int V_283 = ( V_138 -> V_284 & 0x3f ) + 12 ;
int V_285 = ( V_138 -> V_286 >> 3 ) & 0xf ;
int V_287 = V_138 -> V_286 & 7 ;
int V_288 = ( V_138 -> V_289 >> 3 ) & 0xf ;
int V_290 = V_138 -> V_289 & 7 ;
int V_73 = ( F_40 ( V_138 -> V_251 ) >> 24 ) & 1 ;
int V_291 = ( F_40 ( V_138 -> V_126 ) >> 13 ) & 1 ;
T_3 V_125 = ( F_40 ( V_138 -> V_126 ) >> 16 ) & 0xff ;
int V_292 = ( V_125 == V_132 ) ? 1 : 0 ;
int V_293 ;
int V_294 ;
int V_295 ;
int V_296 ;
int V_297 = ( F_40 ( V_138 -> V_298 ) >> 6 ) & 0x3f ;
V_293 = 1 << ( V_285 + V_287 + 4 ) ;
V_294 = ( V_73 | V_291 | V_292 ) ? 0 : ( 1 << ( V_288 + V_290 + 4 ) ) ;
V_296 = V_293 + V_294 ;
V_295 =
F_158 ( ( V_296 + ( V_297 << 6 ) ) >>
V_283 ) ;
return V_295 ;
}
static int F_159 ( struct V_5 * V_6 , int V_37 , int V_299 ,
int V_300 , struct V_191 * V_76 )
{
int V_301 = V_76 -> V_184 . V_13 ;
int V_302 = ( 1 << V_76 -> V_190 ) ;
if ( V_299 < V_301 || V_299 + V_300 > V_301 + V_302 )
return - V_178 ;
return 0 ;
}
int F_160 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_228 = V_267 -> V_272 ;
struct V_191 * V_76 ;
struct V_193 * V_78 ;
int V_303 = F_148 ( V_114 -> V_116 ) / V_6 -> V_8 . V_304 ;
int V_305 ;
int V_181 ;
T_3 V_306 ;
int V_307 ;
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_84 ( V_6 , V_37 , V_181 , V_231 , & V_78 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_154 ( V_114 -> V_116 ) ) {
V_47 = - V_178 ;
goto V_308;
}
V_306 = F_151 ( V_114 -> V_116 ) ;
V_307 = ( V_306 >> 17 ) & 0x7f ;
if ( V_307 != 0 && V_307 != V_37 ) {
V_47 = - V_178 ;
goto V_308;
}
if ( F_152 ( V_114 -> V_116 ) ) {
if ( F_153 ( V_114 -> V_116 ) ) {
V_47 = - V_178 ;
goto V_308;
}
if ( ! F_154 ( V_114 -> V_116 ) ) {
V_47 = - V_178 ;
goto V_308;
}
}
V_305 = F_147 ( V_114 -> V_116 ) ;
if ( ! V_305 ) {
V_47 = F_47 ( V_6 , V_37 , V_303 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_308;
V_47 = F_159 ( V_6 , V_37 , V_303 ,
F_150 ( V_114 -> V_116 ) , V_76 ) ;
if ( V_47 )
goto V_309;
V_78 -> V_76 = V_76 ;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_309;
if ( ! V_305 ) {
F_162 ( & V_76 -> V_189 ) ;
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
}
F_89 ( V_6 , V_37 , V_29 , V_181 ) ;
return 0 ;
V_309:
if ( ! V_305 )
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
V_308:
F_88 ( V_6 , V_37 , V_29 , V_181 ) ;
return V_47 ;
}
int F_163 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_228 = V_267 -> V_272 ;
struct V_193 * V_78 ;
int V_181 ;
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_84 ( V_6 , V_37 , V_181 , V_230 , & V_78 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_308;
if ( V_78 -> V_76 )
F_164 ( & V_78 -> V_76 -> V_189 ) ;
F_89 ( V_6 , V_37 , V_29 , V_181 ) ;
return 0 ;
V_308:
F_88 ( V_6 , V_37 , V_29 , V_181 ) ;
return V_47 ;
}
int F_165 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_228 = V_267 -> V_272 ;
struct V_193 * V_78 ;
int V_181 ;
V_181 = V_228 & F_45 ( V_6 ) ;
V_47 = F_47 ( V_6 , V_37 , V_181 , V_29 , & V_78 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 -> V_184 . V_179 != V_231 ) {
V_47 = - V_176 ;
goto V_61;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_61:
F_52 ( V_6 , V_37 , V_181 , V_29 ) ;
return V_47 ;
}
static int F_166 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_310 ) & 0xffffff ;
}
static int F_167 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_311 ) & 0xffffff ;
}
static T_3 F_168 ( struct V_120 * V_138 )
{
return F_40 ( V_138 -> V_251 ) & 0x1ffffff ;
}
static void F_169 ( struct V_5 * V_6 , struct V_266 * V_267 ,
struct V_120 * V_312 )
{
T_3 V_137 = V_267 -> V_272 & 0xffffff ;
T_3 V_313 = 0 ;
if ( F_170 ( V_6 , V_137 , & V_313 ) )
return;
V_312 -> V_313 = F_44 ( V_313 ) ;
}
int F_171 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_137 = V_267 -> V_272 & 0x7fffff ;
struct V_191 * V_76 ;
struct V_182 * V_67 ;
struct V_120 * V_138 = V_114 -> V_116 + 8 ;
int V_303 = F_155 ( V_138 ) / V_6 -> V_8 . V_304 ;
int V_314 = F_157 ( V_138 ) ;
struct V_197 * V_315 ;
struct V_197 * V_316 ;
int V_317 = F_166 ( V_138 ) ;
int V_318 = F_167 ( V_138 ) ;
T_3 V_251 = F_168 ( V_138 ) & 0xffffff ;
int V_319 = ( F_168 ( V_138 ) >> 24 ) & 1 ;
struct V_199 * V_73 ;
int V_186 = F_40 ( V_138 -> V_186 ) & 0xffffff ;
V_47 = F_83 ( V_6 , V_37 , V_137 , V_226 , & V_67 , 0 ) ;
if ( V_47 )
return V_47 ;
V_67 -> V_186 = V_186 ;
V_67 -> V_129 = 0 ;
V_67 -> V_145 = 0 ;
V_67 -> V_151 = 0 ;
V_67 -> V_158 = 0 ;
V_67 -> V_320 = 0 ;
V_67 -> V_160 = 0 ;
V_67 -> V_165 = 0 ;
V_67 -> V_321 = F_40 ( V_138 -> V_126 ) ;
V_47 = F_47 ( V_6 , V_37 , V_303 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_308;
V_47 = F_159 ( V_6 , V_37 , V_303 , V_314 , V_76 ) ;
if ( V_47 )
goto V_322;
V_47 = F_47 ( V_6 , V_37 , V_317 , V_27 , & V_315 ) ;
if ( V_47 )
goto V_322;
if ( V_318 != V_317 ) {
V_47 = F_47 ( V_6 , V_37 , V_318 , V_27 , & V_316 ) ;
if ( V_47 )
goto V_323;
} else
V_316 = V_315 ;
if ( V_319 ) {
V_47 = F_47 ( V_6 , V_37 , V_251 , V_28 , & V_73 ) ;
if ( V_47 )
goto V_324;
}
F_169 ( V_6 , V_267 , V_138 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_325;
F_162 ( & V_76 -> V_189 ) ;
V_67 -> V_76 = V_76 ;
F_162 ( & V_315 -> V_189 ) ;
V_67 -> V_315 = V_315 ;
F_162 ( & V_316 -> V_189 ) ;
V_67 -> V_316 = V_316 ;
if ( V_318 != V_317 )
F_52 ( V_6 , V_37 , V_318 , V_27 ) ;
if ( V_319 ) {
F_162 ( & V_73 -> V_189 ) ;
F_52 ( V_6 , V_37 , V_251 , V_28 ) ;
V_67 -> V_73 = V_73 ;
}
F_52 ( V_6 , V_37 , V_317 , V_27 ) ;
F_52 ( V_6 , V_37 , V_303 , V_30 ) ;
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
return 0 ;
V_325:
if ( V_319 )
F_52 ( V_6 , V_37 , V_251 , V_28 ) ;
V_324:
if ( V_318 != V_317 )
F_52 ( V_6 , V_37 , V_318 , V_27 ) ;
V_323:
F_52 ( V_6 , V_37 , V_317 , V_27 ) ;
V_322:
F_52 ( V_6 , V_37 , V_303 , V_30 ) ;
V_308:
F_88 ( V_6 , V_37 , V_26 , V_137 ) ;
return V_47 ;
}
static int F_172 ( struct V_326 * V_327 )
{
return F_40 ( V_327 -> V_280 ) & 0xfffffff8 ;
}
static int F_173 ( struct V_326 * V_327 )
{
int V_328 = V_327 -> V_328 & 0x1f ;
int V_283 = ( V_327 -> V_284 & 0x3f ) + 12 ;
if ( V_328 + 5 < V_283 )
return 1 ;
return 1 << ( V_328 + 5 - V_283 ) ;
}
static int F_174 ( struct V_329 * V_330 )
{
return F_40 ( V_330 -> V_280 ) & 0xfffffff8 ;
}
static int F_175 ( struct V_329 * V_330 )
{
int V_331 = ( F_40 ( V_330 -> V_332 ) >> 24 ) & 0x1f ;
int V_283 = ( V_330 -> V_284 & 0x3f ) + 12 ;
if ( V_331 + 5 < V_283 )
return 1 ;
return 1 << ( V_331 + 5 - V_283 ) ;
}
int F_176 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_333 = V_267 -> V_272 ;
int V_13 = ( V_37 << 8 ) | V_333 ;
struct V_326 * V_327 = V_114 -> V_116 ;
int V_303 = F_172 ( V_327 ) / V_6 -> V_8 . V_304 ;
int V_314 = F_173 ( V_327 ) ;
struct V_195 * V_233 ;
struct V_191 * V_76 ;
V_47 = F_65 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_85 ( V_6 , V_37 , V_13 , V_235 , & V_233 ) ;
if ( V_47 )
goto V_334;
V_47 = F_47 ( V_6 , V_37 , V_303 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_335;
V_47 = F_159 ( V_6 , V_37 , V_303 , V_314 , V_76 ) ;
if ( V_47 )
goto V_336;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_336;
F_162 ( & V_76 -> V_189 ) ;
V_233 -> V_76 = V_76 ;
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
F_89 ( V_6 , V_37 , V_33 , V_13 ) ;
return 0 ;
V_336:
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
V_335:
F_88 ( V_6 , V_37 , V_33 , V_13 ) ;
V_334:
F_81 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return V_47 ;
}
static int F_177 ( struct V_5 * V_6 , int V_37 , int V_299 ,
int V_337 , struct V_191 * * V_17 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_191 * V_76 ;
int V_47 = - V_48 ;
F_48 ( F_49 ( V_6 ) ) ;
F_178 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_159 ( V_6 , V_37 , V_299 , V_337 , V_76 ) ) {
* V_17 = V_76 ;
V_76 -> V_184 . V_179 = V_76 -> V_184 . V_2 ;
V_76 -> V_184 . V_2 = V_3 ;
V_47 = 0 ;
break;
}
}
F_50 ( F_49 ( V_6 ) ) ;
return V_47 ;
}
static int F_179 ( struct V_5 * V_6 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
enum V_338 V_339 , T_2 V_37 )
{
T_3 V_340 ;
T_3 V_137 ;
struct V_120 * V_121 ;
enum V_122 V_123 ;
int V_7 ;
int V_341 ;
V_121 = V_114 -> V_116 + 8 ;
V_340 = ( F_40 ( V_121 -> V_126 ) >> 16 ) & 0xff ;
V_123 = F_40 ( * ( V_124 * ) V_114 -> V_116 ) ;
switch ( V_340 ) {
case V_131 :
case V_132 :
case V_133 :
switch ( V_339 ) {
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
if ( V_37 != F_15 ( V_6 ) )
if ( V_123 & V_134 ) {
V_7 = ( V_121 -> V_128 . V_129 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_341 = F_180 ( V_6 , V_37 , V_7 ) ;
else
V_341 = 1 ;
if ( V_121 -> V_128 . V_130 >= V_341 )
return - V_48 ;
}
if ( V_123 & V_135 ) {
V_7 = ( V_121 -> V_136 . V_129 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_341 = F_180 ( V_6 , V_37 , V_7 ) ;
else
V_341 = 1 ;
if ( V_121 -> V_136 . V_130 >= V_341 )
return - V_48 ;
}
break;
default:
break;
}
break;
case V_347 :
V_137 = V_267 -> V_272 & 0x7fffff ;
V_7 = ( V_121 -> V_128 . V_129 >> 6 & 1 ) + 1 ;
if ( V_339 == V_342 &&
V_37 != F_15 ( V_6 ) &&
F_43 ( V_6 , V_137 ) &&
! F_181 ( V_6 , V_37 , V_7 ) ) {
F_182 ( V_6 , L_24 ,
V_215 , V_37 , V_7 ) ;
return - V_178 ;
}
break;
default:
break;
}
return 0 ;
}
int F_183 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
struct V_348 V_76 ;
T_5 * V_349 = V_114 -> V_116 ;
T_1 * V_350 = ( T_1 * ) V_349 ;
int V_81 ;
struct V_191 * V_351 = NULL ;
int V_299 = F_149 ( V_349 [ 0 ] ) ;
int V_352 = V_267 -> V_272 ;
int V_47 ;
V_47 = F_177 ( V_6 , V_37 , V_299 , V_352 , & V_351 ) ;
if ( V_47 )
return V_47 ;
V_76 . V_353 = 0 ;
V_76 . V_190 = 0 ;
V_76 . V_283 = 0 ;
for ( V_81 = 0 ; V_81 < V_352 ; ++ V_81 )
V_350 [ V_81 + 2 ] = ( F_149 ( V_349 [ V_81 + 2 ] ) & ~ 1ULL ) ;
V_47 = F_184 ( V_6 , & V_76 , F_149 ( V_349 [ 0 ] ) , V_352 ,
( ( T_1 * ) V_349 + 2 ) ) ;
if ( V_351 )
F_52 ( V_6 , V_37 , V_351 -> V_184 . V_13 , V_30 ) ;
return V_47 ;
}
int F_185 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_333 = V_267 -> V_272 ;
int V_13 = V_333 | ( V_37 << 8 ) ;
struct V_195 * V_233 ;
int V_47 ;
V_47 = F_85 ( V_6 , V_37 , V_13 , V_196 , & V_233 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_233 -> V_76 -> V_184 . V_13 , V_30 , NULL ) ;
if ( V_47 )
goto V_308;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_309;
F_164 ( & V_233 -> V_76 -> V_189 ) ;
F_52 ( V_6 , V_37 , V_233 -> V_76 -> V_184 . V_13 , V_30 ) ;
F_89 ( V_6 , V_37 , V_33 , V_13 ) ;
F_81 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return 0 ;
V_309:
F_52 ( V_6 , V_37 , V_233 -> V_76 -> V_184 . V_13 , V_30 ) ;
V_308:
F_88 ( V_6 , V_37 , V_33 , V_13 ) ;
return V_47 ;
}
int F_186 ( struct V_5 * V_6 , int V_37 , struct V_354 * V_355 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_356 * V_357 ;
struct V_113 * V_358 ;
T_3 V_272 = 0 ;
int V_47 ;
int V_13 ;
struct V_195 * V_359 ;
if ( ! V_41 -> V_44 . V_45 . V_263 )
return - V_48 ;
V_357 = & V_41 -> V_44 . V_45 . V_263 [ V_37 ] . V_357 [ V_355 -> type ] ;
if ( V_357 -> V_333 < 0 )
return 0 ;
F_35 ( & V_41 -> V_44 . V_45 . V_360 [ V_37 ] ) ;
V_13 = ( V_37 << 8 ) | V_357 -> V_333 ;
V_47 = F_47 ( V_6 , V_37 , V_13 , V_33 , & V_359 ) ;
if ( V_47 )
goto V_361;
if ( V_359 -> V_184 . V_179 != V_235 ) {
V_47 = - V_48 ;
goto V_362;
}
V_358 = F_187 ( V_6 ) ;
if ( F_188 ( V_358 ) ) {
V_47 = F_189 ( V_358 ) ;
goto V_362;
}
if ( V_355 -> type == V_363 ) {
++ V_357 -> V_364 ;
V_355 -> V_365 . V_244 . V_364 = F_190 ( V_357 -> V_364 ) ;
}
memcpy ( V_358 -> V_116 , ( T_2 * ) V_355 , 28 ) ;
V_272 = ( V_37 & 0xff ) | ( ( V_357 -> V_333 & 0xff ) << 16 ) ;
V_47 = F_191 ( V_6 , V_358 -> V_366 , V_272 , 0 ,
V_367 , V_368 ,
V_369 ) ;
F_52 ( V_6 , V_37 , V_13 , V_33 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_360 [ V_37 ] ) ;
F_192 ( V_6 , V_358 ) ;
return V_47 ;
V_362:
F_52 ( V_6 , V_37 , V_13 , V_33 ) ;
V_361:
F_37 ( & V_41 -> V_44 . V_45 . V_360 [ V_37 ] ) ;
return V_47 ;
}
int F_193 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_333 = V_267 -> V_272 ;
int V_13 = V_333 | ( V_37 << 8 ) ;
struct V_195 * V_233 ;
int V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_13 , V_33 , & V_233 ) ;
if ( V_47 )
return V_47 ;
if ( V_233 -> V_184 . V_179 != V_235 ) {
V_47 = - V_48 ;
goto V_309;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_309:
F_52 ( V_6 , V_37 , V_13 , V_33 ) ;
return V_47 ;
}
int F_194 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_236 = V_267 -> V_272 ;
struct V_329 * V_330 = V_114 -> V_116 ;
int V_303 = F_174 ( V_330 ) / V_6 -> V_8 . V_304 ;
struct V_197 * V_70 ;
struct V_191 * V_76 ;
V_47 = F_86 ( V_6 , V_37 , V_236 , V_238 , & V_70 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_303 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_335;
V_47 = F_159 ( V_6 , V_37 , V_303 , F_175 ( V_330 ) , V_76 ) ;
if ( V_47 )
goto V_336;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_336;
F_162 ( & V_76 -> V_189 ) ;
V_70 -> V_76 = V_76 ;
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
F_89 ( V_6 , V_37 , V_27 , V_236 ) ;
return 0 ;
V_336:
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
V_335:
F_88 ( V_6 , V_37 , V_27 , V_236 ) ;
return V_47 ;
}
int F_195 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_236 = V_267 -> V_272 ;
struct V_197 * V_70 ;
V_47 = F_86 ( V_6 , V_37 , V_236 , V_198 , & V_70 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_335;
F_164 ( & V_70 -> V_76 -> V_189 ) ;
F_89 ( V_6 , V_37 , V_27 , V_236 ) ;
return 0 ;
V_335:
F_88 ( V_6 , V_37 , V_27 , V_236 ) ;
return V_47 ;
}
int F_196 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_236 = V_267 -> V_272 ;
struct V_197 * V_70 ;
int V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_236 , V_27 , & V_70 ) ;
if ( V_47 )
return V_47 ;
if ( V_70 -> V_184 . V_179 != V_238 )
goto V_309;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_309:
F_52 ( V_6 , V_37 , V_236 , V_27 ) ;
return V_47 ;
}
static int F_197 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 ,
struct V_197 * V_70 )
{
int V_47 ;
struct V_191 * V_370 ;
struct V_191 * V_76 ;
struct V_329 * V_330 = V_114 -> V_116 ;
int V_303 = F_174 ( V_330 ) / V_6 -> V_8 . V_304 ;
V_47 = F_47 ( V_6 , V_37 , V_70 -> V_76 -> V_184 . V_13 , V_30 , & V_370 ) ;
if ( V_47 )
return V_47 ;
if ( V_370 != V_70 -> V_76 ) {
V_47 = - V_48 ;
goto V_309;
}
V_47 = F_47 ( V_6 , V_37 , V_303 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_309;
V_47 = F_159 ( V_6 , V_37 , V_303 , F_175 ( V_330 ) , V_76 ) ;
if ( V_47 )
goto V_371;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_371;
F_164 ( & V_370 -> V_189 ) ;
F_52 ( V_6 , V_37 , V_370 -> V_184 . V_13 , V_30 ) ;
F_162 ( & V_76 -> V_189 ) ;
V_70 -> V_76 = V_76 ;
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
return 0 ;
V_371:
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
V_309:
F_52 ( V_6 , V_37 , V_370 -> V_184 . V_13 , V_30 ) ;
return V_47 ;
}
int F_198 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_236 = V_267 -> V_272 ;
struct V_197 * V_70 ;
int V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_236 , V_27 , & V_70 ) ;
if ( V_47 )
return V_47 ;
if ( V_70 -> V_184 . V_179 != V_238 )
goto V_309;
if ( V_267 -> V_271 == 0 ) {
V_47 = F_197 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 , V_70 ) ;
goto V_309;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_309:
F_52 ( V_6 , V_37 , V_236 , V_27 ) ;
return V_47 ;
}
static int F_199 ( struct V_281 * V_282 )
{
int V_372 = ( F_40 ( V_282 -> V_373 ) >> 24 ) & 0xf ;
int V_290 = V_282 -> V_374 & 7 ;
int V_283 = ( V_282 -> V_284 & 0x3f ) + 12 ;
if ( V_372 + V_290 + 4 < V_283 )
return 1 ;
return 1 << ( V_372 + V_290 + 4 - V_283 ) ;
}
int F_200 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_251 = V_267 -> V_272 ;
struct V_191 * V_76 ;
struct V_199 * V_73 ;
struct V_281 * V_282 = V_114 -> V_116 ;
int V_303 = F_156 ( V_282 ) / V_6 -> V_8 . V_304 ;
if ( V_251 != ( F_40 ( V_282 -> V_373 ) & 0xffffff ) )
return - V_48 ;
V_47 = F_87 ( V_6 , V_37 , V_251 , V_240 , & V_73 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_303 , V_30 , & V_76 ) ;
if ( V_47 )
goto V_308;
V_47 = F_159 ( V_6 , V_37 , V_303 , F_199 ( V_282 ) ,
V_76 ) ;
if ( V_47 )
goto V_322;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_322;
F_162 ( & V_76 -> V_189 ) ;
V_73 -> V_76 = V_76 ;
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
F_89 ( V_6 , V_37 , V_28 , V_251 ) ;
return 0 ;
V_322:
F_52 ( V_6 , V_37 , V_76 -> V_184 . V_13 , V_30 ) ;
V_308:
F_88 ( V_6 , V_37 , V_28 , V_251 ) ;
return V_47 ;
}
int F_201 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_251 = V_267 -> V_272 ;
struct V_199 * V_73 ;
V_47 = F_87 ( V_6 , V_37 , V_251 , V_200 , & V_73 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_308;
F_164 ( & V_73 -> V_76 -> V_189 ) ;
if ( V_73 -> V_70 )
F_164 ( & V_73 -> V_70 -> V_189 ) ;
F_89 ( V_6 , V_37 , V_28 , V_251 ) ;
return 0 ;
V_308:
F_88 ( V_6 , V_37 , V_28 , V_251 ) ;
return V_47 ;
}
int F_202 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_251 = V_267 -> V_272 ;
struct V_199 * V_73 ;
V_47 = F_47 ( V_6 , V_37 , V_251 , V_28 , & V_73 ) ;
if ( V_47 )
return V_47 ;
if ( V_73 -> V_184 . V_179 != V_240 ) {
V_47 = - V_176 ;
goto V_61;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_61:
F_52 ( V_6 , V_37 , V_251 , V_28 ) ;
return V_47 ;
}
int F_203 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_251 = V_267 -> V_272 ;
struct V_199 * V_73 ;
V_47 = F_47 ( V_6 , V_37 , V_251 , V_28 , & V_73 ) ;
if ( V_47 )
return V_47 ;
if ( V_73 -> V_184 . V_179 != V_240 ) {
V_47 = - V_176 ;
goto V_61;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_61:
F_52 ( V_6 , V_37 , V_251 , V_28 ) ;
return V_47 ;
}
int F_204 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_137 = V_267 -> V_272 & 0x7fffff ;
struct V_182 * V_67 ;
V_47 = F_47 ( V_6 , V_37 , V_137 , V_26 , & V_67 ) ;
if ( V_47 )
return V_47 ;
if ( V_67 -> V_184 . V_179 != V_226 ) {
V_47 = - V_176 ;
goto V_61;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_61:
F_52 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_205 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
struct V_120 * V_312 = V_114 -> V_116 + 8 ;
F_169 ( V_6 , V_267 , V_312 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
return F_204 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
}
static int F_206 ( struct V_5 * V_6 , int V_37 ,
struct V_120 * V_138 ,
struct V_113 * V_114 )
{
enum V_122 V_123 = F_40 ( * ( V_124 * ) V_114 -> V_116 ) ;
T_2 V_375 ;
int V_7 = F_121 (
V_6 , V_37 , ( V_138 -> V_128 . V_129 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_375 = ( V_138 -> V_128 . V_129 & ~ ( 1 << 6 ) ) |
( ( V_7 & 1 ) << 6 ) ;
if ( V_123 & V_134 ||
F_2 ( V_6 , V_7 + 1 ) ) {
V_138 -> V_128 . V_129 = V_375 ;
}
if ( V_123 & V_135 ) {
V_7 = F_121 (
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
static int F_207 ( struct V_5 * V_6 , int V_37 ,
struct V_120 * V_138 ,
struct V_113 * V_114 )
{
T_1 V_253 ;
int V_7 ;
T_3 V_125 = ( F_40 ( V_138 -> V_126 ) >> 16 ) & 0xff ;
T_2 V_115 = * ( T_2 * ) ( V_114 -> V_116 + 64 ) ;
T_2 V_376 ;
V_7 = ( V_115 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) && ( V_125 != V_347 ) ) {
V_376 = V_138 -> V_128 . V_171 & 0x7f ;
if ( F_114 ( V_6 , V_37 , V_7 , V_376 , & V_253 ) )
return - V_180 ;
}
return 0 ;
}
int F_208 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
struct V_120 * V_138 = V_114 -> V_116 + 8 ;
int V_137 = V_267 -> V_272 & 0x7fffff ;
struct V_182 * V_67 ;
T_2 V_377 ;
V_124 V_378 = V_138 -> V_145 ;
T_2 V_379 = V_138 -> V_128 . V_151 ;
T_2 V_380 = V_138 -> V_128 . V_158 ;
T_2 V_381 = V_138 -> V_128 . V_162 ;
T_2 V_382 = V_138 -> V_128 . V_160 ;
T_2 V_383 = V_138 -> V_128 . V_165 ;
V_47 = F_206 ( V_6 , V_37 , V_138 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_179 ( V_6 , V_267 , V_114 , V_342 , V_37 ) ;
if ( V_47 )
return V_47 ;
if ( F_207 ( V_6 , V_37 , V_138 , V_114 ) )
return - V_48 ;
F_38 ( V_6 , V_37 , V_114 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_169 ( V_6 , V_267 , V_138 ) ;
V_377 = V_138 -> V_128 . V_129 ;
V_47 = F_42 ( V_6 , V_114 , V_37 , V_137 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_47 ( V_6 , V_37 , V_137 , V_26 , & V_67 ) ;
if ( V_47 )
return V_47 ;
if ( V_67 -> V_184 . V_179 != V_226 ) {
V_47 = - V_176 ;
goto V_61;
}
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
V_61:
if ( ! V_47 ) {
V_67 -> V_129 = V_377 ;
V_67 -> V_145 = V_378 ;
V_67 -> V_151 = V_379 ;
V_67 -> V_158 = V_380 ;
V_67 -> V_320 = V_381 ;
V_67 -> V_160 = V_382 ;
V_67 -> V_165 = V_383 ;
}
F_52 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_209 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
struct V_120 * V_312 = V_114 -> V_116 + 8 ;
V_47 = F_206 ( V_6 , V_37 , V_312 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_179 ( V_6 , V_267 , V_114 , V_343 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_38 ( V_6 , V_37 , V_114 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_169 ( V_6 , V_267 , V_312 ) ;
return F_204 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
}
int F_210 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
struct V_120 * V_312 = V_114 -> V_116 + 8 ;
V_47 = F_206 ( V_6 , V_37 , V_312 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_179 ( V_6 , V_267 , V_114 , V_344 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_38 ( V_6 , V_37 , V_114 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_169 ( V_6 , V_267 , V_312 ) ;
return F_204 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
}
int F_211 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
struct V_120 * V_312 = V_114 -> V_116 + 8 ;
int V_47 = F_206 ( V_6 , V_37 , V_312 , V_114 ) ;
if ( V_47 )
return V_47 ;
F_169 ( V_6 , V_267 , V_312 ) ;
return F_204 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
}
int F_212 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
struct V_120 * V_312 = V_114 -> V_116 + 8 ;
V_47 = F_206 ( V_6 , V_37 , V_312 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_179 ( V_6 , V_267 , V_114 , V_345 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_169 ( V_6 , V_267 , V_312 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
return F_204 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
}
int F_213 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
struct V_120 * V_312 = V_114 -> V_116 + 8 ;
V_47 = F_206 ( V_6 , V_37 , V_312 , V_114 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_179 ( V_6 , V_267 , V_114 , V_346 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_169 ( V_6 , V_267 , V_312 ) ;
F_39 ( V_6 , V_114 , ( T_2 ) V_37 ) ;
F_38 ( V_6 , V_37 , V_114 ) ;
return F_204 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
}
int F_214 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_137 = V_267 -> V_272 & 0x7fffff ;
struct V_182 * V_67 ;
V_47 = F_83 ( V_6 , V_37 , V_137 , V_225 , & V_67 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
if ( V_47 )
goto V_308;
F_164 ( & V_67 -> V_76 -> V_189 ) ;
F_164 ( & V_67 -> V_315 -> V_189 ) ;
F_164 ( & V_67 -> V_316 -> V_189 ) ;
if ( V_67 -> V_73 )
F_164 ( & V_67 -> V_73 -> V_189 ) ;
F_89 ( V_6 , V_37 , V_26 , V_137 ) ;
return 0 ;
V_308:
F_88 ( V_6 , V_37 , V_26 , V_137 ) ;
return V_47 ;
}
static struct V_384 * F_215 ( struct V_5 * V_6 , int V_37 ,
struct V_182 * V_385 , T_2 * V_386 )
{
struct V_384 * V_17 ;
F_178 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_17 -> V_386 , V_386 , 16 ) )
return V_17 ;
}
return NULL ;
}
static int F_216 ( struct V_5 * V_6 , int V_37 , struct V_182 * V_385 ,
T_2 * V_386 , enum V_387 V_388 ,
enum V_389 V_390 , T_1 V_391 )
{
struct V_384 * V_17 ;
int V_47 ;
V_17 = F_21 ( sizeof *V_17 , V_86 ) ;
if ( ! V_17 )
return - V_87 ;
F_48 ( & V_385 -> V_188 ) ;
if ( F_215 ( V_6 , V_37 , V_385 , V_386 ) ) {
F_31 ( V_17 ) ;
V_47 = - V_23 ;
} else {
memcpy ( V_17 -> V_386 , V_386 , 16 ) ;
V_17 -> V_388 = V_388 ;
V_17 -> V_390 = V_390 ;
V_17 -> V_391 = V_391 ;
F_66 ( & V_17 -> V_213 , & V_385 -> V_187 ) ;
V_47 = 0 ;
}
F_50 ( & V_385 -> V_188 ) ;
return V_47 ;
}
static int F_217 ( struct V_5 * V_6 , int V_37 , struct V_182 * V_385 ,
T_2 * V_386 , enum V_387 V_388 ,
enum V_389 V_390 , T_1 * V_391 )
{
struct V_384 * V_17 ;
int V_47 ;
F_48 ( & V_385 -> V_188 ) ;
V_17 = F_215 ( V_6 , V_37 , V_385 , V_386 ) ;
if ( ! V_17 || V_17 -> V_388 != V_388 || V_17 -> V_390 != V_390 )
V_47 = - V_48 ;
else {
* V_391 = V_17 -> V_391 ;
F_82 ( & V_17 -> V_213 ) ;
F_31 ( V_17 ) ;
V_47 = 0 ;
}
F_50 ( & V_385 -> V_188 ) ;
return V_47 ;
}
static int F_218 ( struct V_5 * V_6 , int V_37 , struct V_392 * V_67 ,
T_2 V_386 [ 16 ] , int V_393 , enum V_387 V_388 ,
enum V_389 type , T_1 * V_391 )
{
switch ( V_6 -> V_8 . V_394 ) {
case V_395 : {
int V_7 = F_121 ( V_6 , V_37 , V_386 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_219 ( V_6 , V_67 , V_386 , V_7 ,
V_393 , V_388 ,
V_391 ) ;
}
case V_396 :
if ( V_388 == V_397 ) {
int V_7 = F_121 ( V_6 , V_37 , V_386 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_386 [ 5 ] = V_7 ;
}
return F_220 ( V_6 , V_67 , V_386 ,
V_393 , V_388 , type ) ;
default:
return - V_48 ;
}
}
static int F_221 ( struct V_5 * V_6 , struct V_392 * V_67 ,
T_2 V_386 [ 16 ] , enum V_387 V_388 ,
enum V_389 type , T_1 V_391 )
{
switch ( V_6 -> V_8 . V_394 ) {
case V_395 :
return F_222 ( V_6 , V_391 ) ;
case V_396 :
return F_223 ( V_6 , V_67 , V_386 , V_388 , type ) ;
default:
return - V_48 ;
}
}
static int F_224 ( struct V_5 * V_6 , int V_37 ,
T_2 * V_386 , enum V_387 V_388 )
{
int V_398 ;
if ( V_388 != V_397 )
return 0 ;
if ( V_6 -> V_8 . V_394 == V_396 ||
V_6 -> V_8 . V_394 == V_395 ) {
V_398 = F_121 ( V_6 , V_37 , V_386 [ 5 ] ) ;
if ( V_398 < 0 )
return - V_48 ;
V_386 [ 5 ] = V_398 ;
}
return 0 ;
}
int F_225 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
struct V_392 V_67 ;
T_2 * V_386 = V_114 -> V_116 ;
enum V_387 V_388 = ( V_267 -> V_272 >> 28 ) & 0x7 ;
int V_47 ;
int V_137 ;
struct V_182 * V_385 ;
T_1 V_391 = 0 ;
int V_399 = V_267 -> V_271 ;
int V_393 = V_267 -> V_272 >> 31 ;
T_2 V_400 = 2 ;
enum V_389 type = ( V_386 [ 7 ] & V_400 ) >> 1 ;
V_137 = V_267 -> V_272 & 0xffffff ;
V_47 = F_47 ( V_6 , V_37 , V_137 , V_26 , & V_385 ) ;
if ( V_47 )
return V_47 ;
V_67 . V_137 = V_137 ;
if ( V_399 ) {
V_47 = F_218 ( V_6 , V_37 , & V_67 , V_386 , V_393 , V_388 ,
type , & V_391 ) ;
if ( V_47 ) {
F_64 ( L_25 , V_137 ) ;
goto V_309;
}
V_47 = F_216 ( V_6 , V_37 , V_385 , V_386 , V_388 , type , V_391 ) ;
if ( V_47 )
goto V_401;
} else {
V_47 = F_224 ( V_6 , V_37 , V_386 , V_388 ) ;
if ( V_47 )
goto V_309;
V_47 = F_217 ( V_6 , V_37 , V_385 , V_386 , V_388 , type , & V_391 ) ;
if ( V_47 )
goto V_309;
V_47 = F_221 ( V_6 , & V_67 , V_386 , V_388 , type , V_391 ) ;
if ( V_47 )
F_64 ( L_26 ,
V_137 , V_391 ) ;
}
F_52 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
V_401:
F_221 ( V_6 , & V_67 , V_386 , V_388 , type , V_391 ) ;
V_309:
F_52 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
static int F_226 ( int V_37 , struct V_402 * V_403 ,
struct V_254 * V_404 )
{
struct V_256 * V_17 , * V_257 ;
T_5 V_405 ;
if ( ! F_227 ( V_403 -> V_406 . V_407 ) &&
! F_228 ( V_403 -> V_406 . V_407 ) ) {
F_115 (res, tmp, rlist, list) {
V_405 = F_229 ( V_17 -> V_253 << 16 ) ;
if ( F_230 ( ( T_2 * ) & V_405 , V_403 -> V_406 . V_407 ) )
return 0 ;
}
F_64 ( L_27 ,
V_403 -> V_406 . V_407 , V_37 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_231 ( struct V_5 * V_6 , int V_37 ,
struct V_113 * V_114 ,
struct V_254 * V_404 , int V_408 )
{
struct V_256 * V_17 , * V_257 ;
T_2 V_7 ;
struct V_409 * V_410 ;
struct V_411 * V_403 ;
struct V_412 * V_413 ;
struct V_414 * V_415 ;
T_5 V_405 = 0 ;
T_5 V_416 = F_229 ( V_417 << 16 ) ;
V_410 = (struct V_409 * ) V_114 -> V_116 ;
V_7 = V_410 -> V_7 ;
V_403 = (struct V_411 * ) ( V_410 + 1 ) ;
switch ( V_408 ) {
case V_418 :
V_413 =
(struct V_412 * ) ( V_403 + 1 ) ;
memmove ( V_413 , V_403 ,
sizeof( * V_413 ) + sizeof( * V_415 ) ) ;
break;
case V_419 :
case V_420 :
V_415 = (struct V_414 * )
( V_403 + 1 ) ;
memmove ( V_415 , V_403 , sizeof( * V_415 ) ) ;
break;
default:
return - V_48 ;
}
F_115 (res, tmp, rlist, list) {
if ( V_7 == V_17 -> V_7 ) {
V_405 = F_229 ( V_17 -> V_253 << 16 ) ;
break;
}
}
if ( ! V_405 ) {
F_64 ( L_28 ,
V_7 ) ;
return - V_48 ;
}
memset ( V_403 , 0 , sizeof( * V_403 ) ) ;
V_403 -> V_300 = sizeof( * V_403 ) >> 2 ;
V_403 -> V_181 = F_190 ( V_421 [ V_422 ] ) ;
memcpy ( V_403 -> V_407 , & V_405 , V_423 ) ;
memcpy ( V_403 -> V_424 , & V_416 , V_423 ) ;
return 0 ;
}
int F_232 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_425 )
{
int V_47 ;
T_3 V_137 = V_267 -> V_272 & 0xffffff ;
struct V_182 * V_385 ;
T_1 V_253 ;
unsigned V_7 ;
T_1 V_426 ;
struct V_427 * V_244 ;
int V_252 ;
V_244 = (struct V_427 * ) V_114 -> V_116 ;
V_426 = F_149 ( V_244 -> V_428 ) ;
if ( V_244 -> V_429 || V_244 -> V_430 ||
( V_426 & ~ V_431 ) )
return - V_178 ;
V_47 = F_47 ( V_6 , V_37 , V_137 , V_26 , & V_385 ) ;
if ( V_47 ) {
F_182 ( V_6 , L_29 , V_137 , V_37 ) ;
return V_47 ;
}
V_7 = ( V_385 -> V_129 >> 6 & 1 ) + 1 ;
V_252 = V_244 -> V_432 . V_128 . V_171 ;
V_47 = F_114 ( V_6 , V_37 , V_7 ,
V_252 , & V_253 ) ;
if ( V_47 ) {
F_182 ( V_6 , L_30 ,
V_137 , V_252 ) ;
goto V_433;
}
V_47 = F_191 ( V_6 , V_114 -> V_366 ,
V_267 -> V_272 , 0 ,
V_434 , V_435 ,
V_369 ) ;
if ( V_47 ) {
F_182 ( V_6 , L_31 , V_137 ) ;
goto V_433;
}
V_433:
F_52 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_233 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_404 = & V_211 -> V_84 [ V_37 ] . V_89 [ V_31 ] ;
int V_47 ;
int V_137 ;
struct V_182 * V_385 ;
struct V_409 * V_410 ;
struct V_402 * V_436 ;
int V_408 ;
if ( V_6 -> V_8 . V_394 !=
V_395 )
return - V_437 ;
V_410 = (struct V_409 * ) V_114 -> V_116 ;
V_410 -> V_7 = F_121 ( V_6 , V_37 , V_410 -> V_7 ) ;
if ( V_410 -> V_7 <= 0 )
return - V_48 ;
V_137 = F_40 ( V_410 -> V_137 ) & 0xffffff ;
V_47 = F_47 ( V_6 , V_37 , V_137 , V_26 , & V_385 ) ;
if ( V_47 ) {
F_64 ( L_32 , V_137 ) ;
return V_47 ;
}
V_436 = (struct V_402 * ) ( V_410 + 1 ) ;
V_408 = F_234 ( F_235 ( V_436 -> V_181 ) ) ;
switch ( V_408 ) {
case V_422 :
if ( F_226 ( V_37 , V_436 , V_404 ) ) {
V_47 = - V_48 ;
goto V_438;
}
break;
case V_439 :
break;
case V_418 :
case V_419 :
case V_420 :
F_236 ( L_33 ) ;
if ( F_231 ( V_6 , V_37 , V_114 , V_404 , V_408 ) ) {
V_47 = - V_48 ;
goto V_438;
}
V_267 -> V_272 +=
sizeof( struct V_411 ) >> 2 ;
break;
default:
F_64 ( L_34 ) ;
V_47 = - V_48 ;
goto V_438;
}
V_47 = F_237 ( V_6 , V_114 -> V_366 , & V_267 -> V_246 ,
V_267 -> V_272 , 0 ,
V_440 , V_435 ,
V_369 ) ;
if ( V_47 )
goto V_438;
V_47 = F_65 ( V_6 , V_37 , V_267 -> V_246 , 1 , V_35 , V_137 ) ;
if ( V_47 ) {
F_182 ( V_6 , L_35 ) ;
F_191 ( V_6 , V_267 -> V_246 , 0 , 0 ,
V_441 , V_435 ,
V_369 ) ;
goto V_438;
}
F_162 ( & V_385 -> V_189 ) ;
V_438:
F_52 ( V_6 , V_37 , V_137 , V_26 ) ;
return V_47 ;
}
int F_238 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
struct V_182 * V_385 ;
struct V_205 * V_442 ;
if ( V_6 -> V_8 . V_394 !=
V_395 )
return - V_437 ;
V_47 = F_47 ( V_6 , V_37 , V_267 -> V_245 , V_35 , & V_442 ) ;
if ( V_47 )
return V_47 ;
F_52 ( V_6 , V_37 , V_267 -> V_245 , V_35 ) ;
V_47 = F_47 ( V_6 , V_37 , V_442 -> V_137 , V_26 , & V_385 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_81 ( V_6 , V_37 , V_267 -> V_245 , 1 , V_35 , 0 ) ;
if ( V_47 ) {
F_182 ( V_6 , L_36 ) ;
goto V_61;
}
V_47 = F_191 ( V_6 , V_267 -> V_245 , 0 , 0 ,
V_441 , V_435 ,
V_369 ) ;
if ( ! V_47 )
F_164 ( & V_385 -> V_189 ) ;
V_61:
F_52 ( V_6 , V_37 , V_442 -> V_137 , V_26 ) ;
return V_47 ;
}
int F_239 ( struct V_5 * V_6 , int V_37 ,
struct V_266 * V_267 ,
struct V_113 * V_114 ,
struct V_113 * V_268 ,
struct V_269 * V_244 )
{
int V_47 ;
int V_228 = V_267 -> V_272 & 0xffff ;
V_47 = F_47 ( V_6 , V_37 , V_228 , V_34 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_161 ( V_6 , V_37 , V_267 , V_114 , V_268 , V_244 ) ;
F_52 ( V_6 , V_37 , V_228 , V_34 ) ;
return V_47 ;
}
static void F_240 ( struct V_5 * V_6 , int V_37 , struct V_182 * V_385 )
{
struct V_384 * V_443 ;
struct V_384 * V_257 ;
struct V_392 V_67 ;
F_115 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_6 -> V_8 . V_394 ) {
case V_395 :
F_222 ( V_6 , V_443 -> V_391 ) ;
break;
case V_396 :
V_67 . V_137 = V_385 -> V_186 ;
( void ) F_223 ( V_6 , & V_67 , V_443 -> V_386 ,
V_443 -> V_388 , V_443 -> V_390 ) ;
break;
}
F_82 ( & V_443 -> V_213 ) ;
F_31 ( V_443 ) ;
}
}
static int F_241 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_444 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_404 = & V_211 -> V_84 [ V_37 ] . V_89 [ type ] ;
struct V_16 * V_173 ;
struct V_16 * V_257 ;
int V_445 ;
V_445 = 0 ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (r, tmp, rlist, list) {
if ( V_173 -> V_177 == V_37 ) {
if ( ! V_173 -> V_446 ) {
if ( V_173 -> V_2 == V_175 ) {
if ( V_444 )
F_24 ( V_6 ,
L_37 ,
F_8 ( type ) ,
V_173 -> V_13 ) ;
++ V_445 ;
} else {
V_173 -> V_179 = V_173 -> V_2 ;
V_173 -> V_2 = V_175 ;
V_173 -> V_446 = 1 ;
}
}
}
}
F_50 ( F_49 ( V_6 ) ) ;
return V_445 ;
}
static int F_242 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type )
{
unsigned long V_447 ;
int V_445 ;
V_447 = V_448 ;
do {
V_445 = F_241 ( V_6 , V_37 , type , 0 ) ;
if ( F_243 ( V_448 , V_447 + 5 * V_449 ) )
break;
if ( V_445 )
F_244 () ;
} while ( V_445 );
if ( V_445 )
V_445 = F_241 ( V_6 , V_37 , type , 1 ) ;
return V_445 ;
}
static void F_245 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_450 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_26 ] ;
struct V_182 * V_67 ;
struct V_182 * V_257 ;
int V_2 ;
T_1 V_245 ;
int V_137 ;
int V_47 ;
V_47 = F_242 ( V_6 , V_37 , V_26 ) ;
if ( V_47 )
F_11 ( V_6 , L_38 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (qp, tmp, qp_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_67 -> V_184 . V_177 == V_37 ) {
V_137 = V_67 -> V_184 . V_13 ;
F_240 ( V_6 , V_37 , V_67 ) ;
V_2 = V_67 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_185 :
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_67 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_26 ] ) ;
F_82 ( & V_67 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
if ( ! F_90 ( V_6 , V_37 , V_137 ) ) {
F_98 ( V_6 , V_137 , 1 ) ;
F_13 ( V_6 , V_37 ,
V_26 , 1 , 0 ) ;
}
F_31 ( V_67 ) ;
V_2 = 0 ;
break;
case V_225 :
if ( ! F_90 ( V_6 , V_37 , V_137 ) )
F_136 ( V_6 , V_137 ) ;
V_2 = V_185 ;
break;
case V_226 :
V_245 = V_37 ;
V_47 = F_191 ( V_6 , V_245 ,
V_67 -> V_186 , 2 ,
V_451 ,
V_435 ,
V_369 ) ;
if ( V_47 )
F_24 ( V_6 , L_39 ,
V_37 , V_67 -> V_186 ) ;
F_164 ( & V_67 -> V_315 -> V_189 ) ;
F_164 ( & V_67 -> V_316 -> V_189 ) ;
F_164 ( & V_67 -> V_76 -> V_189 ) ;
if ( V_67 -> V_73 )
F_164 ( & V_67 -> V_73 -> V_189 ) ;
V_2 = V_225 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_246 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_452 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_28 ] ;
struct V_199 * V_73 ;
struct V_199 * V_257 ;
int V_2 ;
T_1 V_245 ;
F_247 ( V_453 ) ;
int V_251 ;
int V_47 ;
V_47 = F_242 ( V_6 , V_37 , V_28 ) ;
if ( V_47 )
F_11 ( V_6 , L_40 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (srq, tmp, srq_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_73 -> V_184 . V_177 == V_37 ) {
V_251 = V_73 -> V_184 . V_13 ;
V_2 = V_73 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_200 :
F_113 ( V_6 , V_251 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_73 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_28 ] ) ;
F_82 ( & V_73 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_28 , 1 , 0 ) ;
F_31 ( V_73 ) ;
V_2 = 0 ;
break;
case V_240 :
V_245 = V_37 ;
V_47 = F_191 ( V_6 , V_245 , V_251 , 1 ,
V_454 ,
V_435 ,
V_369 ) ;
if ( V_47 )
F_24 ( V_6 , L_41 ,
V_37 , V_251 ) ;
F_164 ( & V_73 -> V_76 -> V_189 ) ;
if ( V_73 -> V_70 )
F_164 ( & V_73 -> V_70 -> V_189 ) ;
V_2 = V_200 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_248 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_455 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_27 ] ;
struct V_197 * V_70 ;
struct V_197 * V_257 ;
int V_2 ;
T_1 V_245 ;
F_247 ( V_453 ) ;
int V_236 ;
int V_47 ;
V_47 = F_242 ( V_6 , V_37 , V_27 ) ;
if ( V_47 )
F_11 ( V_6 , L_42 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (cq, tmp, cq_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_70 -> V_184 . V_177 == V_37 && ! F_69 ( & V_70 -> V_189 ) ) {
V_236 = V_70 -> V_184 . V_13 ;
V_2 = V_70 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_198 :
F_110 ( V_6 , V_236 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_70 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_27 ] ) ;
F_82 ( & V_70 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_27 , 1 , 0 ) ;
F_31 ( V_70 ) ;
V_2 = 0 ;
break;
case V_238 :
V_245 = V_37 ;
V_47 = F_191 ( V_6 , V_245 , V_236 , 1 ,
V_456 ,
V_435 ,
V_369 ) ;
if ( V_47 )
F_24 ( V_6 , L_43 ,
V_37 , V_236 ) ;
F_164 ( & V_70 -> V_76 -> V_189 ) ;
V_2 = V_198 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_249 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_457 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_29 ] ;
struct V_193 * V_78 ;
struct V_193 * V_257 ;
int V_2 ;
T_1 V_245 ;
F_247 ( V_453 ) ;
int V_458 ;
int V_47 ;
V_47 = F_242 ( V_6 , V_37 , V_29 ) ;
if ( V_47 )
F_11 ( V_6 , L_44 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (mpt, tmp, mpt_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_78 -> V_184 . V_177 == V_37 ) {
V_458 = V_78 -> V_184 . V_13 ;
V_2 = V_78 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_194 :
F_106 ( V_6 , V_78 -> V_192 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_78 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_29 ] ) ;
F_82 ( & V_78 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_29 , 1 , 0 ) ;
F_31 ( V_78 ) ;
V_2 = 0 ;
break;
case V_230 :
F_139 ( V_6 , V_78 -> V_192 ) ;
V_2 = V_194 ;
break;
case V_231 :
V_245 = V_37 ;
V_47 = F_191 ( V_6 , V_245 , V_458 , 0 ,
V_459 ,
V_435 ,
V_369 ) ;
if ( V_47 )
F_24 ( V_6 , L_45 ,
V_37 , V_458 ) ;
if ( V_78 -> V_76 )
F_164 ( & V_78 -> V_76 -> V_189 ) ;
V_2 = V_230 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_250 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_460 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_30 ] ;
struct V_191 * V_76 ;
struct V_191 * V_257 ;
int V_2 ;
F_247 ( V_453 ) ;
int V_208 ;
int V_47 ;
V_47 = F_242 ( V_6 , V_37 , V_30 ) ;
if ( V_47 )
F_11 ( V_6 , L_46 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (mtt, tmp, mtt_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_76 -> V_184 . V_177 == V_37 ) {
V_208 = V_76 -> V_184 . V_13 ;
V_2 = V_76 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_103 ( V_6 , V_208 ,
V_76 -> V_190 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_76 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_30 ] ) ;
F_82 ( & V_76 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
F_13 ( V_6 , V_37 , V_30 ,
1 << V_76 -> V_190 , 0 ) ;
F_31 ( V_76 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_251 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_461 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_35 ] ;
struct V_205 * V_462 ;
struct V_205 * V_257 ;
int V_2 ;
T_1 V_208 ;
int V_47 ;
V_47 = F_242 ( V_6 , V_37 , V_35 ) ;
if ( V_47 )
F_11 ( V_6 , L_47 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (fs_rule, tmp, fs_rule_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_462 -> V_184 . V_177 == V_37 ) {
V_208 = V_462 -> V_184 . V_13 ;
V_2 = V_462 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_206 :
V_47 = F_191 ( V_6 , V_208 , 0 , 0 ,
V_441 ,
V_435 ,
V_369 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_462 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_35 ] ) ;
F_82 ( & V_462 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
F_31 ( V_462 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_252 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_463 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_33 ] ;
struct V_195 * V_233 ;
struct V_195 * V_257 ;
int V_47 ;
int V_2 ;
F_247 ( V_453 ) ;
int V_333 ;
struct V_113 * V_358 ;
V_47 = F_242 ( V_6 , V_37 , V_33 ) ;
if ( V_47 )
F_11 ( V_6 , L_48 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (eq, tmp, eq_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_233 -> V_184 . V_177 == V_37 ) {
V_333 = V_233 -> V_184 . V_13 ;
V_2 = V_233 -> V_184 . V_179 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_196 :
F_48 ( F_49 ( V_6 ) ) ;
F_67 ( & V_233 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_33 ] ) ;
F_82 ( & V_233 -> V_184 . V_213 ) ;
F_50 ( F_49 ( V_6 ) ) ;
F_31 ( V_233 ) ;
V_2 = 0 ;
break;
case V_235 :
V_358 = F_187 ( V_6 ) ;
if ( F_188 ( V_358 ) ) {
F_244 () ;
continue;
}
V_47 = F_253 ( V_6 , V_37 , 0 ,
V_333 & 0xff , 0 ,
V_464 ,
V_435 ,
V_369 ) ;
if ( V_47 )
F_24 ( V_6 , L_49 ,
V_37 , V_333 ) ;
F_192 ( V_6 , V_358 ) ;
F_164 ( & V_233 -> V_76 -> V_189 ) ;
V_2 = V_196 ;
break;
default:
V_2 = 0 ;
}
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_254 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_465 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_34 ] ;
struct V_201 * V_466 ;
struct V_201 * V_257 ;
int V_47 ;
int V_228 ;
V_47 = F_242 ( V_6 , V_37 , V_34 ) ;
if ( V_47 )
F_11 ( V_6 , L_50 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (counter, tmp, counter_list, com.list) {
if ( V_466 -> V_184 . V_177 == V_37 ) {
V_228 = V_466 -> V_184 . V_13 ;
F_67 ( & V_466 -> V_184 . V_15 ,
& V_211 -> V_91 [ V_34 ] ) ;
F_82 ( & V_466 -> V_184 . V_213 ) ;
F_31 ( V_466 ) ;
F_130 ( V_6 , V_228 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
}
}
F_50 ( F_49 ( V_6 ) ) ;
}
static void F_255 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_467 =
& V_211 -> V_84 [ V_37 ] . V_89 [ V_36 ] ;
struct V_203 * V_468 ;
struct V_203 * V_257 ;
int V_47 ;
int V_265 ;
V_47 = F_242 ( V_6 , V_37 , V_36 ) ;
if ( V_47 )
F_11 ( V_6 , L_51 ,
V_37 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_468 -> V_184 . V_177 == V_37 ) {
V_265 = V_468 -> V_184 . V_13 ;
F_67 ( & V_468 -> V_184 . V_15 , & V_211 -> V_91 [ V_36 ] ) ;
F_82 ( & V_468 -> V_184 . V_213 ) ;
F_31 ( V_468 ) ;
F_133 ( V_6 , V_265 ) ;
}
}
F_50 ( F_49 ( V_6 ) ) ;
}
void F_33 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
F_34 ( V_6 , V_37 ) ;
F_35 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_37 ] . V_90 ) ;
F_36 ( V_6 , V_37 ) ;
F_118 ( V_6 , V_37 ) ;
F_251 ( V_6 , V_37 ) ;
F_245 ( V_6 , V_37 ) ;
F_246 ( V_6 , V_37 ) ;
F_248 ( V_6 , V_37 ) ;
F_249 ( V_6 , V_37 ) ;
F_252 ( V_6 , V_37 ) ;
F_250 ( V_6 , V_37 ) ;
F_254 ( V_6 , V_37 ) ;
F_255 ( V_6 , V_37 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_46 . V_84 [ V_37 ] . V_90 ) ;
}
void F_256 ( struct V_469 * V_470 )
{
struct V_471 * V_472 =
F_4 ( V_470 , struct V_471 , V_472 ) ;
struct V_113 * V_358 ;
struct V_427 * V_473 ;
struct V_5 * V_6 = & V_472 -> V_41 -> V_6 ;
struct V_210 * V_211 =
& V_472 -> V_41 -> V_44 . V_45 . V_46 ;
struct V_254 * V_450 =
& V_211 -> V_84 [ V_472 -> V_37 ] . V_89 [ V_26 ] ;
struct V_182 * V_67 ;
struct V_182 * V_257 ;
T_1 V_474 =
( ( 1ULL << V_475 ) |
( 1ULL << V_476 ) |
( 1ULL << V_477 ) |
( 1ULL << V_478 ) |
( 1ULL << V_479 ) |
( 1ULL << V_480 ) ) ;
T_1 V_481 = ( ( 1ULL << V_482 ) |
( 1ULL << V_483 ) |
( 1ULL << V_484 ) |
( 1ULL << V_485 ) |
( 1ULL << V_486 ) |
( 1ULL << V_487 ) |
( 1ULL << V_488 ) ) ;
int V_47 ;
int V_7 , V_489 = 0 ;
T_2 V_151 ;
if ( F_17 ( V_6 ) ) {
F_11 ( V_6 , L_52 ,
V_472 -> V_37 ) ;
goto V_61;
}
V_358 = F_187 ( V_6 ) ;
if ( F_188 ( V_358 ) )
goto V_61;
if ( V_472 -> V_126 & V_490 )
V_151 = V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 ;
else if ( ! V_472 -> V_491 )
V_151 = V_152 |
V_157 ;
else
V_151 = V_152 |
V_155 |
V_156 ;
V_473 = V_358 -> V_116 ;
V_473 -> V_429 = F_229 ( V_492 ) ;
F_48 ( F_49 ( V_6 ) ) ;
F_115 (qp, tmp, qp_list, com.list) {
F_50 ( F_49 ( V_6 ) ) ;
if ( V_67 -> V_184 . V_177 == V_472 -> V_37 ) {
if ( V_67 -> V_184 . V_179 != V_226 ||
! V_67 -> V_129 ||
F_43 ( V_6 , V_67 -> V_186 ) ||
V_67 -> V_321 & ( 1 << V_493 ) ) {
F_48 ( F_49 ( V_6 ) ) ;
continue;
}
V_7 = ( V_67 -> V_129 >> 6 & 1 ) + 1 ;
if ( V_7 != V_472 -> V_7 ) {
F_48 ( F_49 ( V_6 ) ) ;
continue;
}
if ( V_131 == ( ( V_67 -> V_321 >> 16 ) & 0xff ) )
V_473 -> V_428 = F_229 ( V_481 ) ;
else
V_473 -> V_428 =
F_229 ( V_481 | V_474 ) ;
if ( V_472 -> V_491 == V_143 ) {
V_473 -> V_432 . V_145 = V_67 -> V_145 ;
V_473 -> V_432 . V_128 . V_151 = V_67 -> V_151 ;
V_473 -> V_432 . V_128 . V_158 = V_67 -> V_158 ;
V_473 -> V_432 . V_128 . V_160 = V_67 -> V_160 ;
V_473 -> V_432 . V_128 . V_162 = V_67 -> V_320 ;
V_473 -> V_432 . V_128 . V_165 = V_67 -> V_165 ;
V_473 -> V_432 . V_128 . V_129 =
V_67 -> V_129 ;
} else {
V_473 -> V_432 . V_145 = V_67 -> V_145 & ~ F_44 ( V_146 ) ;
V_473 -> V_432 . V_128 . V_151 = V_151 ;
V_473 -> V_432 . V_128 . V_160 = V_472 -> V_494 ;
V_473 -> V_432 . V_128 . V_158 =
V_67 -> V_158 | V_159 ;
V_473 -> V_432 . V_128 . V_162 =
V_67 -> V_320 | V_163 | V_164 ;
V_473 -> V_432 . V_128 . V_165 =
V_67 -> V_165 | V_166 | V_167 ;
V_473 -> V_432 . V_128 . V_129 =
V_67 -> V_129 & 0xC7 ;
V_473 -> V_432 . V_128 . V_129 |=
( ( V_472 -> V_495 & 0x7 ) << 3 ) ;
}
V_47 = F_191 ( V_6 , V_358 -> V_366 ,
V_67 -> V_186 & 0xffffff ,
0 , V_434 ,
V_496 , V_369 ) ;
if ( V_47 ) {
F_257 ( V_6 , L_53 ,
V_472 -> V_37 , V_7 , V_67 -> V_186 , V_47 ) ;
V_489 ++ ;
}
}
F_48 ( F_49 ( V_6 ) ) ;
}
F_50 ( F_49 ( V_6 ) ) ;
F_192 ( V_6 , V_358 ) ;
if ( V_489 )
F_182 ( V_6 , L_54 ,
V_489 , V_472 -> V_37 , V_472 -> V_7 ) ;
if ( V_472 -> V_126 & V_497 && ! V_489 &&
V_498 != V_472 -> V_499 )
F_125 ( & V_472 -> V_41 -> V_6 , V_472 -> V_7 ,
V_472 -> V_500 ) ;
V_61:
F_31 ( V_472 ) ;
return;
}
