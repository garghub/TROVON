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
if ( V_37 > V_6 -> V_53 )
return - V_48 ;
F_10 ( & V_43 -> V_54 ) ;
V_49 = ( V_7 > 0 ) ?
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_53 + 1 ) + V_37 ] :
V_43 -> V_49 [ V_37 ] ;
free = ( V_7 > 0 ) ? V_43 -> V_55 [ V_7 - 1 ] :
V_43 -> V_56 ;
V_50 = ( V_7 > 0 ) ? V_43 -> V_57 [ V_7 - 1 ] :
V_43 -> V_58 ;
V_51 = V_43 -> V_51 [ V_37 ] ;
if ( V_49 + V_39 > V_43 -> V_59 [ V_37 ] )
goto V_60;
if ( V_49 + V_39 <= V_51 ) {
V_47 = 0 ;
} else {
if ( V_51 - V_49 > 0 )
V_52 = V_39 - ( V_51 - V_49 ) ;
else
V_52 = V_39 ;
if ( free - V_52 > V_50 )
V_47 = 0 ;
}
if ( ! V_47 ) {
if ( V_7 > 0 ) {
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_53 + 1 ) + V_37 ] += V_39 ;
V_43 -> V_55 [ V_7 - 1 ] -= V_39 ;
} else {
V_43 -> V_49 [ V_37 ] += V_39 ;
V_43 -> V_56 -= V_39 ;
}
}
V_60:
F_11 ( & V_43 -> V_54 ) ;
return V_47 ;
}
static inline void F_12 ( struct V_5 * V_6 , int V_37 ,
enum V_24 V_38 , int V_39 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_42 * V_43 =
& V_41 -> V_44 . V_45 . V_46 . V_43 [ V_38 ] ;
if ( V_37 > V_6 -> V_53 )
return;
F_10 ( & V_43 -> V_54 ) ;
if ( V_7 > 0 ) {
V_43 -> V_49 [ ( V_7 - 1 ) * ( V_6 -> V_53 + 1 ) + V_37 ] -= V_39 ;
V_43 -> V_55 [ V_7 - 1 ] += V_39 ;
} else {
V_43 -> V_49 [ V_37 ] -= V_39 ;
V_43 -> V_56 += V_39 ;
}
F_11 ( & V_43 -> V_54 ) ;
return;
}
static inline void F_13 ( struct V_5 * V_6 ,
struct V_42 * V_43 ,
enum V_24 V_38 ,
int V_61 , int V_62 )
{
V_43 -> V_51 [ V_61 ] = V_62 / ( 2 * ( V_6 -> V_53 + 1 ) ) ;
V_43 -> V_59 [ V_61 ] = ( V_62 / 2 ) + V_43 -> V_51 [ V_61 ] ;
if ( V_61 == F_14 ( V_6 ) ) {
V_43 -> V_56 = V_62 ;
if ( V_38 == V_30 ) {
V_43 -> V_56 += V_6 -> V_8 . V_63 ;
V_43 -> V_51 [ V_61 ] += V_6 -> V_8 . V_63 ;
V_43 -> V_59 [ V_61 ] += V_6 -> V_8 . V_63 ;
}
}
}
void F_15 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_64 ;
if ( F_16 ( V_6 ) )
return;
if ( ! F_17 ( V_6 ) ) {
V_6 -> V_65 . V_66 = V_6 -> V_8 . V_67 - V_6 -> V_8 . V_68 -
F_18 ( V_6 ) ;
V_6 -> V_65 . V_69 = V_6 -> V_8 . V_70 - V_6 -> V_8 . V_71 ;
V_6 -> V_65 . V_72 = V_6 -> V_8 . V_73 - V_6 -> V_8 . V_74 ;
V_6 -> V_65 . V_75 = V_6 -> V_8 . V_76 - V_6 -> V_8 . V_63 ;
V_6 -> V_65 . V_77 = V_6 -> V_8 . V_78 - V_6 -> V_8 . V_79 ;
return;
}
V_64 = F_14 ( V_6 ) ;
V_6 -> V_65 . V_66 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_26 ] . V_59 [ V_64 ] ;
V_6 -> V_65 . V_69 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_27 ] . V_59 [ V_64 ] ;
V_6 -> V_65 . V_72 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_28 ] . V_59 [ V_64 ] ;
V_6 -> V_65 . V_75 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_30 ] . V_59 [ V_64 ] ;
V_6 -> V_65 . V_77 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_29 ] . V_59 [ V_64 ] ;
}
int F_19 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_80 , V_81 ;
int V_82 ;
V_41 -> V_44 . V_45 . V_46 . V_83 =
F_20 ( V_6 -> V_84 * sizeof( struct V_83 ) ,
V_85 ) ;
if ( ! V_41 -> V_44 . V_45 . V_46 . V_83 )
return - V_86 ;
for ( V_80 = 0 ; V_80 < V_6 -> V_84 ; V_80 ++ ) {
for ( V_82 = 0 ; V_82 < V_87 ; ++ V_82 )
F_21 ( & V_41 -> V_44 . V_45 . V_46 .
V_83 [ V_80 ] . V_88 [ V_82 ] ) ;
F_22 ( & V_41 -> V_44 . V_45 . V_46 . V_83 [ V_80 ] . V_89 ) ;
}
F_23 ( V_6 , L_16 ,
V_6 -> V_84 ) ;
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ )
V_41 -> V_44 . V_45 . V_46 . V_90 [ V_80 ] = V_91 ;
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
struct V_42 * V_43 =
& V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] ;
V_43 -> V_59 = F_24 ( ( V_6 -> V_53 + 1 ) * sizeof( int ) , V_85 ) ;
V_43 -> V_51 = F_24 ( ( V_6 -> V_53 + 1 ) * sizeof( int ) , V_85 ) ;
if ( V_80 == V_31 || V_80 == V_32 )
V_43 -> V_49 = F_20 ( V_92 *
( V_6 -> V_53 + 1 ) * sizeof( int ) ,
V_85 ) ;
else
V_43 -> V_49 = F_20 ( ( V_6 -> V_53 + 1 ) * sizeof( int ) , V_85 ) ;
if ( ! V_43 -> V_59 || ! V_43 -> V_51 ||
! V_43 -> V_49 )
goto V_93;
F_25 ( & V_43 -> V_54 ) ;
for ( V_82 = 0 ; V_82 < V_6 -> V_53 + 1 ; V_82 ++ ) {
struct V_94 V_95 =
F_26 ( V_6 , V_82 ) ;
switch ( V_80 ) {
case V_26 :
F_13 ( V_6 , V_43 , V_26 ,
V_82 , V_6 -> V_8 . V_67 -
V_6 -> V_8 . V_68 -
F_18 ( V_6 ) ) ;
break;
case V_27 :
F_13 ( V_6 , V_43 , V_27 ,
V_82 , V_6 -> V_8 . V_70 -
V_6 -> V_8 . V_71 ) ;
break;
case V_28 :
F_13 ( V_6 , V_43 , V_28 ,
V_82 , V_6 -> V_8 . V_73 -
V_6 -> V_8 . V_74 ) ;
break;
case V_29 :
F_13 ( V_6 , V_43 , V_29 ,
V_82 , V_6 -> V_8 . V_78 -
V_6 -> V_8 . V_79 ) ;
break;
case V_30 :
F_13 ( V_6 , V_43 , V_30 ,
V_82 , V_6 -> V_8 . V_76 -
V_6 -> V_8 . V_63 ) ;
break;
case V_31 :
if ( V_82 == F_14 ( V_6 ) ) {
int V_96 = 0 ;
for ( V_81 = 0 ; V_81 < V_6 -> V_8 . V_97 ;
V_81 ++ ) {
struct V_98 V_99 =
F_27 ( V_6 , V_81 + 1 ) ;
unsigned V_100 =
F_28 ( V_99 . V_101 ,
V_6 -> V_8 . V_97 ) - 1 ;
if ( V_96 < V_100 )
V_96 =
V_100 ;
}
V_43 -> V_59 [ V_82 ] =
V_102 -
2 * V_96 ;
V_43 -> V_51 [ V_82 ] = 2 ;
for ( V_81 = 0 ; V_81 < V_92 ; V_81 ++ )
V_43 -> V_55 [ V_81 ] =
V_102 ;
} else {
V_43 -> V_59 [ V_82 ] = V_102 ;
V_43 -> V_51 [ V_82 ] = 2 ;
}
break;
case V_32 :
if ( V_82 == F_14 ( V_6 ) ) {
V_43 -> V_59 [ V_82 ] = V_103 ;
V_43 -> V_51 [ V_82 ] = V_103 / 2 ;
for ( V_81 = 0 ; V_81 < V_92 ; V_81 ++ )
V_43 -> V_55 [ V_81 ] =
V_43 -> V_59 [ V_82 ] ;
} else {
V_43 -> V_59 [ V_82 ] = V_103 / 2 ;
V_43 -> V_51 [ V_82 ] = 0 ;
}
break;
case V_34 :
V_43 -> V_59 [ V_82 ] = V_6 -> V_8 . V_104 ;
V_43 -> V_51 [ V_82 ] = 0 ;
if ( V_82 == F_14 ( V_6 ) )
V_43 -> V_56 = V_43 -> V_59 [ V_82 ] ;
break;
default:
break;
}
if ( V_80 == V_31 || V_80 == V_32 ) {
for ( V_81 = 0 ; V_81 < V_6 -> V_8 . V_97 ; V_81 ++ )
if ( F_29 ( V_81 , V_95 . V_105 ) )
V_43 -> V_57 [ V_81 ] +=
V_43 -> V_51 [ V_82 ] ;
} else {
V_43 -> V_58 += V_43 -> V_51 [ V_82 ] ;
}
}
}
F_25 ( & V_41 -> V_44 . V_45 . V_46 . V_106 ) ;
return 0 ;
V_93:
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_49 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_49 = NULL ;
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_51 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_51 = NULL ;
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_59 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_59 = NULL ;
}
return - V_86 ;
}
void F_31 ( struct V_5 * V_6 ,
enum V_107 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_80 ;
if ( V_41 -> V_44 . V_45 . V_46 . V_83 ) {
if ( type != V_108 ) {
for ( V_80 = 0 ; V_80 < V_6 -> V_84 ; V_80 ++ ) {
if ( type == V_109 ||
V_6 -> V_8 . V_110 != V_80 )
F_32 ( V_6 , V_80 ) ;
}
V_80 = V_6 -> V_8 . V_110 ;
F_33 ( V_6 , V_80 ) ;
F_34 ( & V_41 -> V_44 . V_45 . V_46 . V_83 [ V_80 ] . V_89 ) ;
F_35 ( V_6 , V_80 ) ;
F_36 ( & V_41 -> V_44 . V_45 . V_46 . V_83 [ V_80 ] . V_89 ) ;
}
if ( type != V_111 ) {
for ( V_80 = 0 ; V_80 < V_87 ; V_80 ++ ) {
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_49 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_49 = NULL ;
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_51 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_51 = NULL ;
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_59 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_80 ] . V_59 = NULL ;
}
F_30 ( V_41 -> V_44 . V_45 . V_46 . V_83 ) ;
V_41 -> V_44 . V_45 . V_46 . V_83 = NULL ;
}
}
}
static void F_37 ( struct V_5 * V_6 , int V_37 ,
struct V_112 * V_113 )
{
T_2 V_114 = * ( T_2 * ) ( V_113 -> V_115 + 64 ) ;
T_2 V_116 = * ( T_2 * ) ( V_113 -> V_115 + 35 ) ;
T_2 V_117 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_7 ;
V_7 = ( V_114 >> 6 & 1 ) + 1 ;
V_117 = V_41 -> V_118 [ V_37 ] [ V_7 - 1 ] [ V_116 ] ;
* ( T_2 * ) ( V_113 -> V_115 + 35 ) = V_117 ;
}
static void F_38 ( struct V_5 * V_6 , struct V_112 * V_113 ,
T_2 V_37 )
{
struct V_119 * V_120 = V_113 -> V_115 + 8 ;
enum V_121 V_122 = F_39 ( * ( V_123 * ) V_113 -> V_115 ) ;
T_3 V_124 = ( F_39 ( V_120 -> V_125 ) >> 16 ) & 0xff ;
int V_7 ;
if ( V_126 == V_124 ) {
V_7 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) )
V_120 -> V_127 . V_129 =
F_40 ( V_6 , V_37 , V_7 ) | 0x80 ;
else
V_120 -> V_127 . V_129 = V_37 | 0x80 ;
} else if ( V_130 == V_124 || V_131 == V_124 || V_132 == V_124 ) {
if ( V_122 & V_133 ) {
V_7 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) ) {
V_120 -> V_127 . V_129 +=
F_40 ( V_6 , V_37 , V_7 ) ;
V_120 -> V_127 . V_129 &= 0x7f ;
} else {
V_120 -> V_127 . V_129 = V_37 & 0x7F ;
}
}
if ( V_122 & V_134 ) {
V_7 = ( V_120 -> V_135 . V_128 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) ) {
V_120 -> V_135 . V_129 +=
F_40 ( V_6 , V_37 , V_7 ) ;
V_120 -> V_135 . V_129 &= 0x7f ;
} else {
V_120 -> V_135 . V_129 = V_37 & 0x7F ;
}
}
}
}
static int F_41 ( struct V_5 * V_6 ,
struct V_112 * V_113 ,
T_2 V_37 , T_3 V_136 )
{
struct V_119 * V_137 = V_113 -> V_115 + 8 ;
struct V_138 * V_139 ;
struct V_40 * V_41 ;
int V_7 ;
V_7 = ( V_137 -> V_127 . V_128 & 0x40 ) ? 2 : 1 ;
V_41 = V_40 ( V_6 ) ;
V_139 = & V_41 -> V_44 . V_45 . V_140 [ V_37 ] . V_141 [ V_7 ] ;
if ( V_142 != V_139 -> V_2 . V_143 ) {
if ( F_42 ( V_6 , V_136 ) )
return 0 ;
V_137 -> V_144 &= ~ F_43 ( V_145 ) ;
if ( V_139 -> V_2 . V_146 == V_147 &&
V_6 -> V_8 . V_148 & V_149 ) {
V_137 -> V_127 . V_150 =
V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 ;
} else if ( 0 != V_139 -> V_2 . V_143 ) {
V_137 -> V_127 . V_150 =
V_151 |
V_154 |
V_155 ;
} else {
V_137 -> V_127 . V_150 =
V_151 |
V_156 ;
}
V_137 -> V_127 . V_157 |= V_158 ;
V_137 -> V_127 . V_159 = V_139 -> V_160 ;
V_137 -> V_127 . V_161 |= V_162 | V_163 ;
V_137 -> V_127 . V_164 |= V_165 | V_166 ;
V_137 -> V_127 . V_128 &= 0xC7 ;
V_137 -> V_127 . V_128 |= ( V_139 -> V_2 . V_167 ) << 3 ;
}
if ( V_139 -> V_2 . V_168 ) {
V_137 -> V_127 . V_164 |= V_169 ;
V_137 -> V_127 . V_170 = ( 0x80 & V_137 -> V_127 . V_170 ) + V_139 -> V_171 ;
}
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
return V_6 -> V_8 . V_78 - 1 ;
}
static void * F_45 ( struct V_5 * V_6 , T_1 V_13 ,
enum V_24 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
return F_3 ( & V_41 -> V_44 . V_45 . V_46 . V_90 [ type ] ,
V_13 ) ;
}
static int F_46 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type ,
void * V_17 )
{
struct V_16 * V_172 ;
int V_47 = 0 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_45 ( V_6 , V_13 , type ) ;
if ( ! V_172 ) {
V_47 = - V_173 ;
goto exit;
}
if ( V_172 -> V_2 == V_174 ) {
V_47 = - V_175 ;
goto exit;
}
if ( V_172 -> V_176 != V_37 ) {
V_47 = - V_177 ;
goto exit;
}
V_172 -> V_178 = V_172 -> V_2 ;
V_172 -> V_2 = V_174 ;
if ( V_17 )
* ( (struct V_16 * * ) V_17 ) = V_172 ;
exit:
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
int F_50 ( struct V_5 * V_6 ,
enum V_24 type ,
T_1 V_13 , int * V_37 )
{
struct V_16 * V_172 ;
int V_47 = - V_179 ;
int V_180 = V_13 ;
if ( type == V_26 )
V_180 &= 0x7fffff ;
F_10 ( F_48 ( V_6 ) ) ;
V_172 = F_45 ( V_6 , V_180 , type ) ;
if ( V_172 ) {
* V_37 = V_172 -> V_176 ;
V_47 = 0 ;
}
F_11 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static void F_51 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type )
{
struct V_16 * V_172 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_45 ( V_6 , V_13 , type ) ;
if ( V_172 )
V_172 -> V_2 = V_172 -> V_178 ;
F_49 ( F_48 ( V_6 ) ) ;
}
static struct V_16 * F_52 ( int V_180 )
{
struct V_181 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_184 ;
V_182 -> V_185 = V_180 ;
F_21 ( & V_182 -> V_186 ) ;
F_25 ( & V_182 -> V_187 ) ;
F_53 ( & V_182 -> V_188 , 0 ) ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_54 ( int V_180 , int V_189 )
{
struct V_190 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_189 = V_189 ;
V_182 -> V_183 . V_2 = V_4 ;
F_53 ( & V_182 -> V_188 , 0 ) ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_55 ( int V_180 , int V_191 )
{
struct V_192 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_193 ;
V_182 -> V_191 = V_191 ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_56 ( int V_180 )
{
struct V_194 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_195 ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_57 ( int V_180 )
{
struct V_196 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_197 ;
F_53 ( & V_182 -> V_188 , 0 ) ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_58 ( int V_180 )
{
struct V_198 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_199 ;
F_53 ( & V_182 -> V_188 , 0 ) ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_59 ( int V_180 )
{
struct V_200 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_201 ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_60 ( int V_180 )
{
struct V_202 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_203 ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_61 ( T_1 V_180 , int V_136 )
{
struct V_204 * V_182 ;
V_182 = F_20 ( sizeof *V_182 , V_85 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> V_183 . V_13 = V_180 ;
V_182 -> V_183 . V_2 = V_205 ;
V_182 -> V_136 = V_136 ;
return & V_182 -> V_183 ;
}
static struct V_16 * F_62 ( T_1 V_180 , enum V_24 type , int V_37 ,
int V_206 )
{
struct V_16 * V_182 ;
switch ( type ) {
case V_26 :
V_182 = F_52 ( V_180 ) ;
break;
case V_29 :
V_182 = F_55 ( V_180 , V_206 ) ;
break;
case V_30 :
V_182 = F_54 ( V_180 , V_206 ) ;
break;
case V_33 :
V_182 = F_56 ( V_180 ) ;
break;
case V_27 :
V_182 = F_57 ( V_180 ) ;
break;
case V_28 :
V_182 = F_58 ( V_180 ) ;
break;
case V_31 :
F_63 ( V_207 L_17 ) ;
return NULL ;
case V_34 :
V_182 = F_59 ( V_180 ) ;
break;
case V_36 :
V_182 = F_60 ( V_180 ) ;
break;
case V_35 :
V_182 = F_61 ( V_180 , V_206 ) ;
break;
default:
return NULL ;
}
if ( V_182 )
V_182 -> V_176 = V_37 ;
return V_182 ;
}
static int F_64 ( struct V_5 * V_6 , int V_37 , T_1 V_208 , int V_39 ,
enum V_24 type , int V_206 )
{
int V_80 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_16 * * V_209 ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_11 * V_12 = & V_211 -> V_90 [ type ] ;
V_209 = F_20 ( V_39 * sizeof *V_209 , V_85 ) ;
if ( ! V_209 )
return - V_86 ;
for ( V_80 = 0 ; V_80 < V_39 ; ++ V_80 ) {
V_209 [ V_80 ] = F_62 ( V_208 + V_80 , type , V_37 , V_206 ) ;
if ( ! V_209 [ V_80 ] ) {
for ( -- V_80 ; V_80 >= 0 ; -- V_80 )
F_30 ( V_209 [ V_80 ] ) ;
F_30 ( V_209 ) ;
return - V_86 ;
}
}
F_47 ( F_48 ( V_6 ) ) ;
for ( V_80 = 0 ; V_80 < V_39 ; ++ V_80 ) {
if ( F_45 ( V_6 , V_208 + V_80 , type ) ) {
V_47 = - V_23 ;
goto V_212;
}
V_47 = F_5 ( V_12 , V_209 [ V_80 ] ) ;
if ( V_47 )
goto V_212;
F_65 ( & V_209 [ V_80 ] -> V_213 ,
& V_211 -> V_83 [ V_37 ] . V_88 [ type ] ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
F_30 ( V_209 ) ;
return 0 ;
V_212:
for ( -- V_80 ; V_80 >= V_208 ; -- V_80 )
F_66 ( & V_209 [ V_80 ] -> V_15 , V_12 ) ;
F_49 ( F_48 ( V_6 ) ) ;
for ( V_80 = 0 ; V_80 < V_39 ; ++ V_80 )
F_30 ( V_209 [ V_80 ] ) ;
F_30 ( V_209 ) ;
return V_47 ;
}
static int F_67 ( struct V_181 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_214 || F_68 ( & V_17 -> V_188 ) ||
! F_69 ( & V_17 -> V_186 ) ) {
F_70 ( L_18 ,
V_17 -> V_183 . V_2 , F_68 ( & V_17 -> V_188 ) ) ;
return - V_175 ;
} else if ( V_17 -> V_183 . V_2 != V_184 ) {
return - V_177 ;
}
return 0 ;
}
static int F_71 ( struct V_190 * V_17 , int V_189 )
{
if ( V_17 -> V_183 . V_2 == V_3 ||
F_68 ( & V_17 -> V_188 ) ) {
F_63 ( V_215 L_19 ,
V_216 , __LINE__ ,
F_1 ( V_17 -> V_183 . V_2 ) ,
F_68 ( & V_17 -> V_188 ) ) ;
return - V_175 ;
} else if ( V_17 -> V_183 . V_2 != V_4 )
return - V_177 ;
else if ( V_17 -> V_189 != V_189 )
return - V_48 ;
return 0 ;
}
static int F_72 ( struct V_192 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_217 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_193 )
return - V_177 ;
return 0 ;
}
static int F_73 ( struct V_194 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_217 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_193 )
return - V_177 ;
return 0 ;
}
static int F_74 ( struct V_200 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_218 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_201 )
return - V_177 ;
return 0 ;
}
static int F_75 ( struct V_202 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_219 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_203 )
return - V_177 ;
return 0 ;
}
static int F_76 ( struct V_204 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_220 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_205 )
return - V_177 ;
return 0 ;
}
static int F_77 ( struct V_196 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_221 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_197 )
return - V_177 ;
return 0 ;
}
static int F_78 ( struct V_198 * V_17 )
{
if ( V_17 -> V_183 . V_2 == V_222 )
return - V_175 ;
else if ( V_17 -> V_183 . V_2 != V_199 )
return - V_177 ;
return 0 ;
}
static int F_79 ( struct V_16 * V_17 , enum V_24 type , int V_206 )
{
switch ( type ) {
case V_26 :
return F_67 ( (struct V_181 * ) V_17 ) ;
case V_27 :
return F_77 ( (struct V_196 * ) V_17 ) ;
case V_28 :
return F_78 ( (struct V_198 * ) V_17 ) ;
case V_29 :
return F_72 ( (struct V_192 * ) V_17 ) ;
case V_30 :
return F_71 ( (struct V_190 * ) V_17 , V_206 ) ;
case V_31 :
return - V_223 ;
case V_33 :
return F_73 ( (struct V_194 * ) V_17 ) ;
case V_34 :
return F_74 ( (struct V_200 * ) V_17 ) ;
case V_36 :
return F_75 ( (struct V_202 * ) V_17 ) ;
case V_35 :
return F_76 ( (struct V_204 * ) V_17 ) ;
default:
return - V_48 ;
}
}
static int F_80 ( struct V_5 * V_6 , int V_37 , T_1 V_208 , int V_39 ,
enum V_24 type , int V_206 )
{
T_1 V_80 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_172 ;
F_47 ( F_48 ( V_6 ) ) ;
for ( V_80 = V_208 ; V_80 < V_208 + V_39 ; ++ V_80 ) {
V_172 = F_3 ( & V_211 -> V_90 [ type ] , V_80 ) ;
if ( ! V_172 ) {
V_47 = - V_179 ;
goto V_60;
}
if ( V_172 -> V_176 != V_37 ) {
V_47 = - V_177 ;
goto V_60;
}
V_47 = F_79 ( V_172 , type , V_206 ) ;
if ( V_47 )
goto V_60;
}
for ( V_80 = V_208 ; V_80 < V_208 + V_39 ; ++ V_80 ) {
V_172 = F_3 ( & V_211 -> V_90 [ type ] , V_80 ) ;
F_66 ( & V_172 -> V_15 , & V_211 -> V_90 [ type ] ) ;
F_81 ( & V_172 -> V_213 ) ;
F_30 ( V_172 ) ;
}
V_47 = 0 ;
V_60:
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static int F_82 ( struct V_5 * V_6 , int V_37 , int V_136 ,
enum V_224 V_2 , struct V_181 * * V_66 ,
int V_225 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_181 * V_172 ;
int V_47 = 0 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ V_26 ] , V_136 ) ;
if ( ! V_172 )
V_47 = - V_179 ;
else if ( V_172 -> V_183 . V_176 != V_37 )
V_47 = - V_177 ;
else {
switch ( V_2 ) {
case V_214 :
F_23 ( V_6 , L_20 ,
V_216 , V_172 -> V_183 . V_13 ) ;
V_47 = - V_175 ;
break;
case V_184 :
if ( V_172 -> V_183 . V_2 == V_226 && ! V_225 )
break;
F_23 ( V_6 , L_21 , V_172 -> V_183 . V_13 ) ;
V_47 = - V_48 ;
break;
case V_226 :
if ( ( V_172 -> V_183 . V_2 == V_184 && V_225 ) ||
V_172 -> V_183 . V_2 == V_227 )
break;
else {
F_23 ( V_6 , L_21 ,
V_172 -> V_183 . V_13 ) ;
V_47 = - V_48 ;
}
break;
case V_227 :
if ( V_172 -> V_183 . V_2 != V_226 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_172 -> V_183 . V_178 = V_172 -> V_183 . V_2 ;
V_172 -> V_183 . V_228 = V_2 ;
V_172 -> V_183 . V_2 = V_214 ;
if ( V_66 )
* V_66 = V_172 ;
}
}
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static int F_83 ( struct V_5 * V_6 , int V_37 , int V_229 ,
enum V_230 V_2 , struct V_192 * * V_77 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_192 * V_172 ;
int V_47 = 0 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ V_29 ] , V_229 ) ;
if ( ! V_172 )
V_47 = - V_179 ;
else if ( V_172 -> V_183 . V_176 != V_37 )
V_47 = - V_177 ;
else {
switch ( V_2 ) {
case V_217 :
V_47 = - V_48 ;
break;
case V_193 :
if ( V_172 -> V_183 . V_2 != V_231 )
V_47 = - V_48 ;
break;
case V_231 :
if ( V_172 -> V_183 . V_2 != V_193 &&
V_172 -> V_183 . V_2 != V_232 )
V_47 = - V_48 ;
break;
case V_232 :
if ( V_172 -> V_183 . V_2 != V_231 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_172 -> V_183 . V_178 = V_172 -> V_183 . V_2 ;
V_172 -> V_183 . V_228 = V_2 ;
V_172 -> V_183 . V_2 = V_217 ;
if ( V_77 )
* V_77 = V_172 ;
}
}
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static int F_84 ( struct V_5 * V_6 , int V_37 , int V_229 ,
enum V_233 V_2 , struct V_194 * * V_234 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_194 * V_172 ;
int V_47 = 0 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ V_33 ] , V_229 ) ;
if ( ! V_172 )
V_47 = - V_179 ;
else if ( V_172 -> V_183 . V_176 != V_37 )
V_47 = - V_177 ;
else {
switch ( V_2 ) {
case V_235 :
V_47 = - V_48 ;
break;
case V_195 :
if ( V_172 -> V_183 . V_2 != V_236 )
V_47 = - V_48 ;
break;
case V_236 :
if ( V_172 -> V_183 . V_2 != V_195 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_172 -> V_183 . V_178 = V_172 -> V_183 . V_2 ;
V_172 -> V_183 . V_228 = V_2 ;
V_172 -> V_183 . V_2 = V_235 ;
if ( V_234 )
* V_234 = V_172 ;
}
}
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static int F_85 ( struct V_5 * V_6 , int V_37 , int V_237 ,
enum V_238 V_2 , struct V_196 * * V_69 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_196 * V_172 ;
int V_47 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ V_27 ] , V_237 ) ;
if ( ! V_172 ) {
V_47 = - V_179 ;
} else if ( V_172 -> V_183 . V_176 != V_37 ) {
V_47 = - V_177 ;
} else if ( V_2 == V_197 ) {
if ( V_172 -> V_183 . V_2 != V_239 )
V_47 = - V_48 ;
else if ( F_68 ( & V_172 -> V_188 ) )
V_47 = - V_175 ;
else
V_47 = 0 ;
} else if ( V_2 != V_239 || V_172 -> V_183 . V_2 != V_197 ) {
V_47 = - V_48 ;
} else {
V_47 = 0 ;
}
if ( ! V_47 ) {
V_172 -> V_183 . V_178 = V_172 -> V_183 . V_2 ;
V_172 -> V_183 . V_228 = V_2 ;
V_172 -> V_183 . V_2 = V_221 ;
if ( V_69 )
* V_69 = V_172 ;
}
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static int F_86 ( struct V_5 * V_6 , int V_37 , int V_229 ,
enum V_240 V_2 , struct V_198 * * V_72 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_198 * V_172 ;
int V_47 = 0 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ V_28 ] , V_229 ) ;
if ( ! V_172 ) {
V_47 = - V_179 ;
} else if ( V_172 -> V_183 . V_176 != V_37 ) {
V_47 = - V_177 ;
} else if ( V_2 == V_199 ) {
if ( V_172 -> V_183 . V_2 != V_241 )
V_47 = - V_48 ;
else if ( F_68 ( & V_172 -> V_188 ) )
V_47 = - V_175 ;
} else if ( V_2 != V_241 || V_172 -> V_183 . V_2 != V_199 ) {
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_172 -> V_183 . V_178 = V_172 -> V_183 . V_2 ;
V_172 -> V_183 . V_228 = V_2 ;
V_172 -> V_183 . V_2 = V_222 ;
if ( V_72 )
* V_72 = V_172 ;
}
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static void F_87 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_180 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_172 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ type ] , V_180 ) ;
if ( V_172 && ( V_172 -> V_176 == V_37 ) )
V_172 -> V_2 = V_172 -> V_178 ;
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_88 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_180 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_172 ;
F_47 ( F_48 ( V_6 ) ) ;
V_172 = F_3 ( & V_211 -> V_90 [ type ] , V_180 ) ;
if ( V_172 && ( V_172 -> V_176 == V_37 ) )
V_172 -> V_2 = V_172 -> V_228 ;
F_49 ( F_48 ( V_6 ) ) ;
}
static int F_89 ( struct V_5 * V_6 , int V_37 , int V_136 )
{
return F_42 ( V_6 , V_136 ) &&
( F_90 ( V_6 ) || F_91 ( V_6 , V_37 , V_136 ) ) ;
}
static int F_92 ( struct V_5 * V_6 , int V_136 )
{
return V_136 < V_6 -> V_8 . V_242 [ V_243 ] ;
}
static int F_93 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_47 ;
int V_39 ;
int V_248 ;
int V_208 ;
int V_136 ;
switch ( V_244 ) {
case V_249 :
V_39 = F_94 ( & V_246 ) ;
V_248 = F_95 ( & V_246 ) ;
V_47 = F_9 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_96 ( V_6 , V_39 , V_248 , & V_208 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
return V_47 ;
}
V_47 = F_64 ( V_6 , V_37 , V_208 , V_39 , V_26 , 0 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_97 ( V_6 , V_208 , V_39 ) ;
return V_47 ;
}
F_98 ( V_247 , V_208 ) ;
break;
case V_250 :
V_136 = F_94 ( & V_246 ) & 0x7fffff ;
if ( F_89 ( V_6 , V_37 , V_136 ) ) {
V_47 = F_64 ( V_6 , V_37 , V_136 , 1 , V_26 , 0 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_82 ( V_6 , V_37 , V_136 , V_226 ,
NULL , 1 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_92 ( V_6 , V_136 ) ) {
V_47 = F_99 ( V_6 , V_136 ) ;
if ( V_47 ) {
F_87 ( V_6 , V_37 , V_26 , V_136 ) ;
return V_47 ;
}
}
F_88 ( V_6 , V_37 , V_26 , V_136 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_100 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_47 = - V_48 ;
int V_208 ;
int V_189 ;
if ( V_244 != V_251 )
return V_47 ;
V_189 = F_94 ( & V_246 ) ;
V_47 = F_9 ( V_6 , V_37 , V_30 , 1 << V_189 , 0 ) ;
if ( V_47 )
return V_47 ;
V_208 = F_101 ( V_6 , V_189 ) ;
if ( V_208 == - 1 ) {
F_12 ( V_6 , V_37 , V_30 , 1 << V_189 , 0 ) ;
return - V_86 ;
}
V_47 = F_64 ( V_6 , V_37 , V_208 , 1 , V_30 , V_189 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_30 , 1 << V_189 , 0 ) ;
F_102 ( V_6 , V_208 , V_189 ) ;
} else {
F_98 ( V_247 , V_208 ) ;
}
return V_47 ;
}
static int F_103 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_47 = - V_48 ;
int V_229 ;
int V_180 ;
struct V_192 * V_77 ;
switch ( V_244 ) {
case V_249 :
V_47 = F_9 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
if ( V_47 )
break;
V_229 = F_104 ( V_6 ) ;
if ( V_229 == - 1 ) {
F_12 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
break;
}
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_64 ( V_6 , V_37 , V_180 , 1 , V_29 , V_229 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_105 ( V_6 , V_229 ) ;
break;
}
F_98 ( V_247 , V_229 ) ;
break;
case V_250 :
V_229 = F_94 ( & V_246 ) ;
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_83 ( V_6 , V_37 , V_180 ,
V_231 , & V_77 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_106 ( V_6 , V_77 -> V_191 ) ;
if ( V_47 ) {
F_87 ( V_6 , V_37 , V_29 , V_180 ) ;
return V_47 ;
}
F_88 ( V_6 , V_37 , V_29 , V_180 ) ;
break;
}
return V_47 ;
}
static int F_107 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_237 ;
int V_47 ;
switch ( V_244 ) {
case V_251 :
V_47 = F_9 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_108 ( V_6 , & V_237 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
break;
}
V_47 = F_64 ( V_6 , V_37 , V_237 , 1 , V_27 , 0 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_109 ( V_6 , V_237 ) ;
break;
}
F_98 ( V_247 , V_237 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_110 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_252 ;
int V_47 ;
switch ( V_244 ) {
case V_251 :
V_47 = F_9 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_111 ( V_6 , & V_252 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
break;
}
V_47 = F_64 ( V_6 , V_37 , V_252 , 1 , V_28 , 0 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_112 ( V_6 , V_252 ) ;
break;
}
F_98 ( V_247 , V_252 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_113 ( struct V_5 * V_6 , int V_37 , int V_7 ,
T_2 V_253 , T_1 * V_254 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_256 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_31 ] ;
struct V_257 * V_17 , * V_258 ;
F_114 (res, tmp, mac_list, list) {
if ( V_17 -> V_253 == V_253 && V_17 -> V_7 == ( T_2 ) V_7 ) {
* V_254 = V_17 -> V_254 ;
return 0 ;
}
}
return - V_179 ;
}
static int F_115 ( struct V_5 * V_6 , int V_37 , T_1 V_254 , int V_7 , T_2 V_253 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_256 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_31 ] ;
struct V_257 * V_17 , * V_258 ;
F_114 (res, tmp, mac_list, list) {
if ( V_17 -> V_254 == V_254 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_188 ;
return 0 ;
}
}
if ( F_9 ( V_6 , V_37 , V_31 , 1 , V_7 ) )
return - V_48 ;
V_17 = F_20 ( sizeof *V_17 , V_85 ) ;
if ( ! V_17 ) {
F_12 ( V_6 , V_37 , V_31 , 1 , V_7 ) ;
return - V_86 ;
}
V_17 -> V_254 = V_254 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_253 = V_253 ;
V_17 -> V_188 = 1 ;
F_65 ( & V_17 -> V_213 ,
& V_211 -> V_83 [ V_37 ] . V_88 [ V_31 ] ) ;
return 0 ;
}
static void F_116 ( struct V_5 * V_6 , int V_37 , T_1 V_254 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_256 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_31 ] ;
struct V_257 * V_17 , * V_258 ;
F_114 (res, tmp, mac_list, list) {
if ( V_17 -> V_254 == V_254 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_188 ) {
F_81 ( & V_17 -> V_213 ) ;
F_12 ( V_6 , V_37 , V_31 , 1 , V_7 ) ;
F_30 ( V_17 ) ;
}
break;
}
}
}
static void F_117 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_256 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_31 ] ;
struct V_257 * V_17 , * V_258 ;
int V_80 ;
F_114 (res, tmp, mac_list, list) {
F_81 ( & V_17 -> V_213 ) ;
for ( V_80 = 0 ; V_80 < V_17 -> V_188 ; V_80 ++ )
F_118 ( V_6 , V_17 -> V_7 , V_17 -> V_254 ) ;
F_12 ( V_6 , V_37 , V_31 , 1 , V_17 -> V_7 ) ;
F_30 ( V_17 ) ;
}
}
static int F_119 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 , int V_259 )
{
int V_47 = - V_48 ;
int V_7 ;
T_1 V_254 ;
T_2 V_253 ;
if ( V_244 != V_251 )
return V_47 ;
V_7 = ! V_259 ? F_94 ( V_247 ) : V_259 ;
V_7 = F_120 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
V_254 = V_246 ;
V_47 = F_121 ( V_6 , V_7 , V_254 ) ;
if ( V_47 >= 0 ) {
V_253 = V_47 ;
F_98 ( V_247 , V_47 ) ;
V_47 = 0 ;
}
if ( ! V_47 ) {
V_47 = F_115 ( V_6 , V_37 , V_254 , V_7 , V_253 ) ;
if ( V_47 )
F_118 ( V_6 , V_7 , V_254 ) ;
}
return V_47 ;
}
static int F_122 ( struct V_5 * V_6 , int V_37 , T_4 V_260 ,
int V_7 , int V_159 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_261 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_32 ] ;
struct V_262 * V_17 , * V_258 ;
F_114 (res, tmp, vlan_list, list) {
if ( V_17 -> V_260 == V_260 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_188 ;
return 0 ;
}
}
if ( F_9 ( V_6 , V_37 , V_32 , 1 , V_7 ) )
return - V_48 ;
V_17 = F_20 ( sizeof( * V_17 ) , V_85 ) ;
if ( ! V_17 ) {
F_12 ( V_6 , V_37 , V_32 , 1 , V_7 ) ;
return - V_86 ;
}
V_17 -> V_260 = V_260 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_159 = V_159 ;
V_17 -> V_188 = 1 ;
F_65 ( & V_17 -> V_213 ,
& V_211 -> V_83 [ V_37 ] . V_88 [ V_32 ] ) ;
return 0 ;
}
static void F_123 ( struct V_5 * V_6 , int V_37 , T_4 V_260 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_261 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_32 ] ;
struct V_262 * V_17 , * V_258 ;
F_114 (res, tmp, vlan_list, list) {
if ( V_17 -> V_260 == V_260 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_188 ) {
F_81 ( & V_17 -> V_213 ) ;
F_12 ( V_6 , V_37 , V_32 ,
1 , V_7 ) ;
F_30 ( V_17 ) ;
}
break;
}
}
}
static void F_35 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_261 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_32 ] ;
struct V_262 * V_17 , * V_258 ;
int V_80 ;
F_114 (res, tmp, vlan_list, list) {
F_81 ( & V_17 -> V_213 ) ;
for ( V_80 = 0 ; V_80 < V_17 -> V_188 ; V_80 ++ )
F_124 ( V_6 , V_17 -> V_7 , V_17 -> V_260 ) ;
F_12 ( V_6 , V_37 , V_32 , 1 , V_17 -> V_7 ) ;
F_30 ( V_17 ) ;
}
}
static int F_125 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 , int V_259 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_263 * V_264 = V_41 -> V_44 . V_45 . V_264 ;
int V_47 ;
T_4 V_260 ;
int V_159 ;
int V_7 ;
V_7 = ! V_259 ? F_94 ( V_247 ) : V_259 ;
if ( ! V_7 || V_244 != V_251 )
return - V_48 ;
V_7 = F_120 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
if ( ! V_259 && V_7 > 0 && V_7 <= V_6 -> V_8 . V_97 ) {
V_264 [ V_37 ] . V_265 = true ;
return 0 ;
}
V_260 = ( T_4 ) V_246 ;
V_47 = F_126 ( V_6 , V_7 , V_260 , & V_159 ) ;
if ( ! V_47 ) {
F_98 ( V_247 , ( T_3 ) V_159 ) ;
V_47 = F_122 ( V_6 , V_37 , V_260 , V_7 , V_159 ) ;
if ( V_47 )
F_124 ( V_6 , V_7 , V_260 ) ;
}
return V_47 ;
}
static int F_127 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
T_3 V_229 ;
int V_47 ;
if ( V_244 != V_249 )
return - V_48 ;
V_47 = F_9 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_128 ( V_6 , & V_229 ) ;
if ( V_47 ) {
F_12 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
V_47 = F_64 ( V_6 , V_37 , V_229 , 1 , V_34 , 0 ) ;
if ( V_47 ) {
F_129 ( V_6 , V_229 ) ;
F_12 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
} else {
F_98 ( V_247 , V_229 ) ;
}
return V_47 ;
}
static int F_130 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
T_3 V_266 ;
int V_47 ;
if ( V_244 != V_249 )
return - V_48 ;
V_47 = F_131 ( V_6 , & V_266 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_64 ( V_6 , V_37 , V_266 , 1 , V_36 , 0 ) ;
if ( V_47 )
F_132 ( V_6 , V_266 ) ;
else
F_98 ( V_247 , V_266 ) ;
return V_47 ;
}
int F_133 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_271 = V_268 -> V_272 ;
switch ( V_268 -> V_273 & 0xFF ) {
case V_26 :
V_47 = F_93 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_30 :
V_47 = F_100 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_29 :
V_47 = F_103 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_27 :
V_47 = F_107 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_28 :
V_47 = F_110 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_31 :
V_47 = F_119 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ,
( V_268 -> V_273 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_125 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ,
( V_268 -> V_273 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_127 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_36 :
V_47 = F_130 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_134 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 )
{
int V_47 ;
int V_39 ;
int V_208 ;
int V_136 ;
switch ( V_244 ) {
case V_249 :
V_208 = F_94 ( & V_246 ) & 0x7fffff ;
V_39 = F_95 ( & V_246 ) ;
V_47 = F_80 ( V_6 , V_37 , V_208 , V_39 , V_26 , 0 ) ;
if ( V_47 )
break;
F_12 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_97 ( V_6 , V_208 , V_39 ) ;
break;
case V_250 :
V_136 = F_94 ( & V_246 ) & 0x7fffff ;
V_47 = F_82 ( V_6 , V_37 , V_136 , V_184 ,
NULL , 0 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_92 ( V_6 , V_136 ) )
F_135 ( V_6 , V_136 ) ;
F_88 ( V_6 , V_37 , V_26 , V_136 ) ;
if ( F_89 ( V_6 , V_37 , V_136 ) )
V_47 = F_80 ( V_6 , V_37 , V_136 , 1 , V_26 , 0 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_136 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_47 = - V_48 ;
int V_208 ;
int V_189 ;
if ( V_244 != V_251 )
return V_47 ;
V_208 = F_94 ( & V_246 ) ;
V_189 = F_95 ( & V_246 ) ;
V_47 = F_80 ( V_6 , V_37 , V_208 , 1 , V_30 , V_189 ) ;
if ( ! V_47 ) {
F_12 ( V_6 , V_37 , V_30 , 1 << V_189 , 0 ) ;
F_102 ( V_6 , V_208 , V_189 ) ;
}
return V_47 ;
}
static int F_137 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 )
{
int V_47 = - V_48 ;
int V_229 ;
int V_180 ;
struct V_192 * V_77 ;
switch ( V_244 ) {
case V_249 :
V_229 = F_94 ( & V_246 ) ;
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_46 ( V_6 , V_37 , V_180 , V_29 , & V_77 ) ;
if ( V_47 )
break;
V_229 = V_77 -> V_191 ;
F_51 ( V_6 , V_37 , V_180 , V_29 ) ;
V_47 = F_80 ( V_6 , V_37 , V_180 , 1 , V_29 , 0 ) ;
if ( V_47 )
break;
F_12 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_105 ( V_6 , V_229 ) ;
break;
case V_250 :
V_229 = F_94 ( & V_246 ) ;
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_83 ( V_6 , V_37 , V_180 ,
V_193 , & V_77 ) ;
if ( V_47 )
return V_47 ;
F_138 ( V_6 , V_77 -> V_191 ) ;
F_88 ( V_6 , V_37 , V_29 , V_180 ) ;
return V_47 ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_139 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_237 ;
int V_47 ;
switch ( V_244 ) {
case V_251 :
V_237 = F_94 ( & V_246 ) ;
V_47 = F_80 ( V_6 , V_37 , V_237 , 1 , V_27 , 0 ) ;
if ( V_47 )
break;
F_12 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_109 ( V_6 , V_237 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_140 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_252 ;
int V_47 ;
switch ( V_244 ) {
case V_251 :
V_252 = F_94 ( & V_246 ) ;
V_47 = F_80 ( V_6 , V_37 , V_252 , 1 , V_28 , 0 ) ;
if ( V_47 )
break;
F_12 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_112 ( V_6 , V_252 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_141 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 , int V_259 )
{
int V_7 ;
int V_47 = 0 ;
switch ( V_244 ) {
case V_251 :
V_7 = ! V_259 ? F_94 ( V_247 ) : V_259 ;
V_7 = F_120 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
F_116 ( V_6 , V_37 , V_246 , V_7 ) ;
F_118 ( V_6 , V_7 , V_246 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_142 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 , int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_263 * V_264 = V_41 -> V_44 . V_45 . V_264 ;
int V_47 = 0 ;
V_7 = F_120 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
switch ( V_244 ) {
case V_251 :
if ( V_264 [ V_37 ] . V_265 )
return 0 ;
if ( ! V_7 )
return - V_48 ;
F_123 ( V_6 , V_37 , V_246 , V_7 ) ;
F_124 ( V_6 , V_7 , V_246 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_143 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_229 ;
int V_47 ;
if ( V_244 != V_249 )
return - V_48 ;
V_229 = F_94 ( & V_246 ) ;
V_47 = F_80 ( V_6 , V_37 , V_229 , 1 , V_34 , 0 ) ;
if ( V_47 )
return V_47 ;
F_129 ( V_6 , V_229 ) ;
F_12 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
static int F_144 ( struct V_5 * V_6 , int V_37 , int V_244 , int V_245 ,
T_1 V_246 , T_1 * V_247 )
{
int V_266 ;
int V_47 ;
if ( V_244 != V_249 )
return - V_48 ;
V_266 = F_94 ( & V_246 ) ;
V_47 = F_80 ( V_6 , V_37 , V_266 , 1 , V_36 , 0 ) ;
if ( V_47 )
return V_47 ;
F_132 ( V_6 , V_266 ) ;
return V_47 ;
}
int F_145 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 = - V_48 ;
int V_271 = V_268 -> V_272 ;
switch ( V_268 -> V_273 & 0xFF ) {
case V_26 :
V_47 = F_134 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 ) ;
break;
case V_30 :
V_47 = F_136 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_29 :
V_47 = F_137 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 ) ;
break;
case V_27 :
V_47 = F_139 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_28 :
V_47 = F_140 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_31 :
V_47 = F_141 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ,
( V_268 -> V_273 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_142 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ,
( V_268 -> V_273 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_143 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
break;
case V_36 :
V_47 = F_144 ( V_6 , V_37 , V_268 -> V_272 , V_271 ,
V_268 -> V_246 , & V_268 -> V_247 ) ;
default:
break;
}
return V_47 ;
}
static int F_146 ( struct V_274 * V_77 )
{
return ( F_39 ( V_77 -> V_125 ) >> 9 ) & 1 ;
}
static int F_147 ( struct V_274 * V_77 )
{
return ( int ) F_148 ( V_77 -> V_275 ) & 0xfffffff8 ;
}
static int F_149 ( struct V_274 * V_77 )
{
return F_39 ( V_77 -> V_276 ) ;
}
static T_3 F_150 ( struct V_274 * V_77 )
{
return F_39 ( V_77 -> V_277 ) & 0x00ffffff ;
}
static int F_151 ( struct V_274 * V_77 )
{
return F_39 ( V_77 -> V_277 ) & V_278 ;
}
static int F_152 ( struct V_274 * V_77 )
{
return F_39 ( V_77 -> V_125 ) & V_279 ;
}
static int F_153 ( struct V_274 * V_77 )
{
return F_39 ( V_77 -> V_125 ) & V_280 ;
}
static int F_154 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_281 ) & 0xfffffff8 ;
}
static int F_155 ( struct V_282 * V_283 )
{
return F_39 ( V_283 -> V_281 ) & 0xfffffff8 ;
}
static int F_156 ( struct V_119 * V_137 )
{
int V_284 = ( V_137 -> V_285 & 0x3f ) + 12 ;
int V_286 = ( V_137 -> V_287 >> 3 ) & 0xf ;
int V_288 = V_137 -> V_287 & 7 ;
int V_289 = ( V_137 -> V_290 >> 3 ) & 0xf ;
int V_291 = V_137 -> V_290 & 7 ;
int V_72 = ( F_39 ( V_137 -> V_252 ) >> 24 ) & 1 ;
int V_292 = ( F_39 ( V_137 -> V_125 ) >> 13 ) & 1 ;
T_3 V_124 = ( F_39 ( V_137 -> V_125 ) >> 16 ) & 0xff ;
int V_293 = ( V_124 == V_131 ) ? 1 : 0 ;
int V_294 ;
int V_295 ;
int V_296 ;
int V_297 ;
int V_298 = ( F_39 ( V_137 -> V_299 ) >> 6 ) & 0x3f ;
V_294 = 1 << ( V_286 + V_288 + 4 ) ;
V_295 = ( V_72 | V_292 | V_293 ) ? 0 : ( 1 << ( V_289 + V_291 + 4 ) ) ;
V_297 = V_294 + V_295 ;
V_296 =
F_157 ( ( V_297 + ( V_298 << 6 ) ) >>
V_284 ) ;
return V_296 ;
}
static int F_158 ( struct V_5 * V_6 , int V_37 , int V_300 ,
int V_301 , struct V_190 * V_75 )
{
int V_302 = V_75 -> V_183 . V_13 ;
int V_303 = ( 1 << V_75 -> V_189 ) ;
if ( V_300 < V_302 || V_300 + V_301 > V_302 + V_303 )
return - V_177 ;
return 0 ;
}
int F_159 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_229 = V_268 -> V_273 ;
struct V_190 * V_75 ;
struct V_192 * V_77 ;
int V_304 = F_147 ( V_113 -> V_115 ) / V_6 -> V_8 . V_305 ;
int V_306 ;
int V_180 ;
T_3 V_307 ;
int V_308 ;
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_83 ( V_6 , V_37 , V_180 , V_232 , & V_77 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_153 ( V_113 -> V_115 ) ) {
V_47 = - V_177 ;
goto V_309;
}
V_307 = F_150 ( V_113 -> V_115 ) ;
V_308 = ( V_307 >> 17 ) & 0x7f ;
if ( V_308 != 0 && V_308 != V_37 ) {
V_47 = - V_177 ;
goto V_309;
}
if ( F_151 ( V_113 -> V_115 ) ) {
if ( F_152 ( V_113 -> V_115 ) ) {
V_47 = - V_177 ;
goto V_309;
}
if ( ! F_153 ( V_113 -> V_115 ) ) {
V_47 = - V_177 ;
goto V_309;
}
}
V_306 = F_146 ( V_113 -> V_115 ) ;
if ( ! V_306 ) {
V_47 = F_46 ( V_6 , V_37 , V_304 , V_30 , & V_75 ) ;
if ( V_47 )
goto V_309;
V_47 = F_158 ( V_6 , V_37 , V_304 ,
F_149 ( V_113 -> V_115 ) , V_75 ) ;
if ( V_47 )
goto V_310;
V_77 -> V_75 = V_75 ;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_310;
if ( ! V_306 ) {
F_161 ( & V_75 -> V_188 ) ;
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
}
F_88 ( V_6 , V_37 , V_29 , V_180 ) ;
return 0 ;
V_310:
if ( ! V_306 )
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
V_309:
F_87 ( V_6 , V_37 , V_29 , V_180 ) ;
return V_47 ;
}
int F_162 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_229 = V_268 -> V_273 ;
struct V_192 * V_77 ;
int V_180 ;
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_83 ( V_6 , V_37 , V_180 , V_231 , & V_77 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_309;
if ( V_77 -> V_75 )
F_163 ( & V_77 -> V_75 -> V_188 ) ;
F_88 ( V_6 , V_37 , V_29 , V_180 ) ;
return 0 ;
V_309:
F_87 ( V_6 , V_37 , V_29 , V_180 ) ;
return V_47 ;
}
int F_164 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_229 = V_268 -> V_273 ;
struct V_192 * V_77 ;
int V_180 ;
V_180 = V_229 & F_44 ( V_6 ) ;
V_47 = F_46 ( V_6 , V_37 , V_180 , V_29 , & V_77 ) ;
if ( V_47 )
return V_47 ;
if ( V_77 -> V_183 . V_178 != V_232 ) {
V_47 = - V_175 ;
goto V_60;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_60:
F_51 ( V_6 , V_37 , V_180 , V_29 ) ;
return V_47 ;
}
static int F_165 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_311 ) & 0xffffff ;
}
static int F_166 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_312 ) & 0xffffff ;
}
static T_3 F_167 ( struct V_119 * V_137 )
{
return F_39 ( V_137 -> V_252 ) & 0x1ffffff ;
}
static void F_168 ( struct V_5 * V_6 , struct V_267 * V_268 ,
struct V_119 * V_313 )
{
T_3 V_136 = V_268 -> V_273 & 0xffffff ;
T_3 V_314 = 0 ;
if ( F_169 ( V_6 , V_136 , & V_314 ) )
return;
V_313 -> V_314 = F_43 ( V_314 ) ;
}
int F_170 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_136 = V_268 -> V_273 & 0x7fffff ;
struct V_190 * V_75 ;
struct V_181 * V_66 ;
struct V_119 * V_137 = V_113 -> V_115 + 8 ;
int V_304 = F_154 ( V_137 ) / V_6 -> V_8 . V_305 ;
int V_315 = F_156 ( V_137 ) ;
struct V_196 * V_316 ;
struct V_196 * V_317 ;
int V_318 = F_165 ( V_137 ) ;
int V_319 = F_166 ( V_137 ) ;
T_3 V_252 = F_167 ( V_137 ) & 0xffffff ;
int V_320 = ( F_167 ( V_137 ) >> 24 ) & 1 ;
struct V_198 * V_72 ;
int V_185 = F_39 ( V_137 -> V_185 ) & 0xffffff ;
V_47 = F_82 ( V_6 , V_37 , V_136 , V_227 , & V_66 , 0 ) ;
if ( V_47 )
return V_47 ;
V_66 -> V_185 = V_185 ;
V_66 -> V_128 = 0 ;
V_66 -> V_144 = 0 ;
V_66 -> V_150 = 0 ;
V_66 -> V_157 = 0 ;
V_66 -> V_321 = 0 ;
V_66 -> V_159 = 0 ;
V_66 -> V_164 = 0 ;
V_66 -> V_322 = F_39 ( V_137 -> V_125 ) ;
V_47 = F_46 ( V_6 , V_37 , V_304 , V_30 , & V_75 ) ;
if ( V_47 )
goto V_309;
V_47 = F_158 ( V_6 , V_37 , V_304 , V_315 , V_75 ) ;
if ( V_47 )
goto V_323;
V_47 = F_46 ( V_6 , V_37 , V_318 , V_27 , & V_316 ) ;
if ( V_47 )
goto V_323;
if ( V_319 != V_318 ) {
V_47 = F_46 ( V_6 , V_37 , V_319 , V_27 , & V_317 ) ;
if ( V_47 )
goto V_324;
} else
V_317 = V_316 ;
if ( V_320 ) {
V_47 = F_46 ( V_6 , V_37 , V_252 , V_28 , & V_72 ) ;
if ( V_47 )
goto V_325;
}
F_168 ( V_6 , V_268 , V_137 ) ;
F_37 ( V_6 , V_37 , V_113 ) ;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_326;
F_161 ( & V_75 -> V_188 ) ;
V_66 -> V_75 = V_75 ;
F_161 ( & V_316 -> V_188 ) ;
V_66 -> V_316 = V_316 ;
F_161 ( & V_317 -> V_188 ) ;
V_66 -> V_317 = V_317 ;
if ( V_319 != V_318 )
F_51 ( V_6 , V_37 , V_319 , V_27 ) ;
if ( V_320 ) {
F_161 ( & V_72 -> V_188 ) ;
F_51 ( V_6 , V_37 , V_252 , V_28 ) ;
V_66 -> V_72 = V_72 ;
}
F_51 ( V_6 , V_37 , V_318 , V_27 ) ;
F_51 ( V_6 , V_37 , V_304 , V_30 ) ;
F_88 ( V_6 , V_37 , V_26 , V_136 ) ;
return 0 ;
V_326:
if ( V_320 )
F_51 ( V_6 , V_37 , V_252 , V_28 ) ;
V_325:
if ( V_319 != V_318 )
F_51 ( V_6 , V_37 , V_319 , V_27 ) ;
V_324:
F_51 ( V_6 , V_37 , V_318 , V_27 ) ;
V_323:
F_51 ( V_6 , V_37 , V_304 , V_30 ) ;
V_309:
F_87 ( V_6 , V_37 , V_26 , V_136 ) ;
return V_47 ;
}
static int F_171 ( struct V_327 * V_328 )
{
return F_39 ( V_328 -> V_281 ) & 0xfffffff8 ;
}
static int F_172 ( struct V_327 * V_328 )
{
int V_329 = V_328 -> V_329 & 0x1f ;
int V_284 = ( V_328 -> V_285 & 0x3f ) + 12 ;
if ( V_329 + 5 < V_284 )
return 1 ;
return 1 << ( V_329 + 5 - V_284 ) ;
}
static int F_173 ( struct V_330 * V_331 )
{
return F_39 ( V_331 -> V_281 ) & 0xfffffff8 ;
}
static int F_174 ( struct V_330 * V_331 )
{
int V_332 = ( F_39 ( V_331 -> V_333 ) >> 24 ) & 0x1f ;
int V_284 = ( V_331 -> V_285 & 0x3f ) + 12 ;
if ( V_332 + 5 < V_284 )
return 1 ;
return 1 << ( V_332 + 5 - V_284 ) ;
}
int F_175 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_334 = V_268 -> V_273 ;
int V_13 = ( V_37 << 8 ) | V_334 ;
struct V_327 * V_328 = V_113 -> V_115 ;
int V_304 = F_171 ( V_328 ) / V_6 -> V_8 . V_305 ;
int V_315 = F_172 ( V_328 ) ;
struct V_194 * V_234 ;
struct V_190 * V_75 ;
V_47 = F_64 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_84 ( V_6 , V_37 , V_13 , V_236 , & V_234 ) ;
if ( V_47 )
goto V_335;
V_47 = F_46 ( V_6 , V_37 , V_304 , V_30 , & V_75 ) ;
if ( V_47 )
goto V_336;
V_47 = F_158 ( V_6 , V_37 , V_304 , V_315 , V_75 ) ;
if ( V_47 )
goto V_337;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_337;
F_161 ( & V_75 -> V_188 ) ;
V_234 -> V_75 = V_75 ;
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
F_88 ( V_6 , V_37 , V_33 , V_13 ) ;
return 0 ;
V_337:
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
V_336:
F_87 ( V_6 , V_37 , V_33 , V_13 ) ;
V_335:
F_80 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return V_47 ;
}
static int F_176 ( struct V_5 * V_6 , int V_37 , int V_300 ,
int V_338 , struct V_190 * * V_17 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_190 * V_75 ;
int V_47 = - V_48 ;
F_47 ( F_48 ( V_6 ) ) ;
F_177 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_158 ( V_6 , V_37 , V_300 , V_338 , V_75 ) ) {
* V_17 = V_75 ;
V_75 -> V_183 . V_178 = V_75 -> V_183 . V_2 ;
V_75 -> V_183 . V_2 = V_3 ;
V_47 = 0 ;
break;
}
}
F_49 ( F_48 ( V_6 ) ) ;
return V_47 ;
}
static int F_178 ( struct V_5 * V_6 ,
struct V_112 * V_113 ,
enum V_339 V_340 , T_2 V_37 )
{
T_3 V_341 ;
struct V_119 * V_120 ;
enum V_121 V_122 ;
int V_7 ;
int V_342 ;
V_120 = V_113 -> V_115 + 8 ;
V_341 = ( F_39 ( V_120 -> V_125 ) >> 16 ) & 0xff ;
V_122 = F_39 ( * ( V_123 * ) V_113 -> V_115 ) ;
switch ( V_341 ) {
case V_130 :
case V_131 :
case V_132 :
switch ( V_340 ) {
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
if ( V_37 != F_14 ( V_6 ) )
if ( V_122 & V_133 ) {
V_7 = ( V_120 -> V_127 . V_128 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_342 = F_179 ( V_6 , V_37 , V_7 ) ;
else
V_342 = 1 ;
if ( V_120 -> V_127 . V_129 >= V_342 )
return - V_48 ;
}
if ( V_122 & V_134 ) {
V_7 = ( V_120 -> V_135 . V_128 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_342 = F_179 ( V_6 , V_37 , V_7 ) ;
else
V_342 = 1 ;
if ( V_120 -> V_135 . V_129 >= V_342 )
return - V_48 ;
}
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
int F_180 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
struct V_348 V_75 ;
T_5 * V_349 = V_113 -> V_115 ;
T_1 * V_350 = ( T_1 * ) V_349 ;
int V_80 ;
struct V_190 * V_351 = NULL ;
int V_300 = F_148 ( V_349 [ 0 ] ) ;
int V_352 = V_268 -> V_273 ;
int V_47 ;
V_47 = F_176 ( V_6 , V_37 , V_300 , V_352 , & V_351 ) ;
if ( V_47 )
return V_47 ;
V_75 . V_353 = 0 ;
V_75 . V_189 = 0 ;
V_75 . V_284 = 0 ;
for ( V_80 = 0 ; V_80 < V_352 ; ++ V_80 )
V_350 [ V_80 + 2 ] = ( F_148 ( V_349 [ V_80 + 2 ] ) & ~ 1ULL ) ;
V_47 = F_181 ( V_6 , & V_75 , F_148 ( V_349 [ 0 ] ) , V_352 ,
( ( T_1 * ) V_349 + 2 ) ) ;
if ( V_351 )
F_51 ( V_6 , V_37 , V_351 -> V_183 . V_13 , V_30 ) ;
return V_47 ;
}
int F_182 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_334 = V_268 -> V_273 ;
int V_13 = V_334 | ( V_37 << 8 ) ;
struct V_194 * V_234 ;
int V_47 ;
V_47 = F_84 ( V_6 , V_37 , V_13 , V_195 , & V_234 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_234 -> V_75 -> V_183 . V_13 , V_30 , NULL ) ;
if ( V_47 )
goto V_309;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_310;
F_163 ( & V_234 -> V_75 -> V_188 ) ;
F_51 ( V_6 , V_37 , V_234 -> V_75 -> V_183 . V_13 , V_30 ) ;
F_88 ( V_6 , V_37 , V_33 , V_13 ) ;
F_80 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return 0 ;
V_310:
F_51 ( V_6 , V_37 , V_234 -> V_75 -> V_183 . V_13 , V_30 ) ;
V_309:
F_87 ( V_6 , V_37 , V_33 , V_13 ) ;
return V_47 ;
}
int F_183 ( struct V_5 * V_6 , int V_37 , struct V_354 * V_355 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_356 * V_357 ;
struct V_112 * V_358 ;
T_3 V_273 = 0 ;
int V_47 ;
int V_13 ;
struct V_194 * V_359 ;
if ( ! V_41 -> V_44 . V_45 . V_264 )
return - V_48 ;
V_357 = & V_41 -> V_44 . V_45 . V_264 [ V_37 ] . V_357 [ V_355 -> type ] ;
if ( V_357 -> V_334 < 0 )
return 0 ;
F_34 ( & V_41 -> V_44 . V_45 . V_360 [ V_37 ] ) ;
V_13 = ( V_37 << 8 ) | V_357 -> V_334 ;
V_47 = F_46 ( V_6 , V_37 , V_13 , V_33 , & V_359 ) ;
if ( V_47 )
goto V_361;
if ( V_359 -> V_183 . V_178 != V_236 ) {
V_47 = - V_48 ;
goto V_362;
}
V_358 = F_184 ( V_6 ) ;
if ( F_185 ( V_358 ) ) {
V_47 = F_186 ( V_358 ) ;
goto V_362;
}
if ( V_355 -> type == V_363 ) {
++ V_357 -> V_364 ;
V_355 -> V_365 . V_245 . V_364 = F_187 ( V_357 -> V_364 ) ;
}
memcpy ( V_358 -> V_115 , ( T_2 * ) V_355 , 28 ) ;
V_273 = ( V_37 & 0xff ) | ( ( V_357 -> V_334 & 0xff ) << 16 ) ;
V_47 = F_188 ( V_6 , V_358 -> V_366 , V_273 , 0 ,
V_367 , V_368 ,
V_369 ) ;
F_51 ( V_6 , V_37 , V_13 , V_33 ) ;
F_36 ( & V_41 -> V_44 . V_45 . V_360 [ V_37 ] ) ;
F_189 ( V_6 , V_358 ) ;
return V_47 ;
V_362:
F_51 ( V_6 , V_37 , V_13 , V_33 ) ;
V_361:
F_36 ( & V_41 -> V_44 . V_45 . V_360 [ V_37 ] ) ;
return V_47 ;
}
int F_190 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_334 = V_268 -> V_273 ;
int V_13 = V_334 | ( V_37 << 8 ) ;
struct V_194 * V_234 ;
int V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_13 , V_33 , & V_234 ) ;
if ( V_47 )
return V_47 ;
if ( V_234 -> V_183 . V_178 != V_236 ) {
V_47 = - V_48 ;
goto V_310;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_310:
F_51 ( V_6 , V_37 , V_13 , V_33 ) ;
return V_47 ;
}
int F_191 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_237 = V_268 -> V_273 ;
struct V_330 * V_331 = V_113 -> V_115 ;
int V_304 = F_173 ( V_331 ) / V_6 -> V_8 . V_305 ;
struct V_196 * V_69 ;
struct V_190 * V_75 ;
V_47 = F_85 ( V_6 , V_37 , V_237 , V_239 , & V_69 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_304 , V_30 , & V_75 ) ;
if ( V_47 )
goto V_336;
V_47 = F_158 ( V_6 , V_37 , V_304 , F_174 ( V_331 ) , V_75 ) ;
if ( V_47 )
goto V_337;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_337;
F_161 ( & V_75 -> V_188 ) ;
V_69 -> V_75 = V_75 ;
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
F_88 ( V_6 , V_37 , V_27 , V_237 ) ;
return 0 ;
V_337:
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
V_336:
F_87 ( V_6 , V_37 , V_27 , V_237 ) ;
return V_47 ;
}
int F_192 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_237 = V_268 -> V_273 ;
struct V_196 * V_69 ;
V_47 = F_85 ( V_6 , V_37 , V_237 , V_197 , & V_69 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_336;
F_163 ( & V_69 -> V_75 -> V_188 ) ;
F_88 ( V_6 , V_37 , V_27 , V_237 ) ;
return 0 ;
V_336:
F_87 ( V_6 , V_37 , V_27 , V_237 ) ;
return V_47 ;
}
int F_193 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_237 = V_268 -> V_273 ;
struct V_196 * V_69 ;
int V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_237 , V_27 , & V_69 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 -> V_183 . V_178 != V_239 )
goto V_310;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_310:
F_51 ( V_6 , V_37 , V_237 , V_27 ) ;
return V_47 ;
}
static int F_194 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 ,
struct V_196 * V_69 )
{
int V_47 ;
struct V_190 * V_370 ;
struct V_190 * V_75 ;
struct V_330 * V_331 = V_113 -> V_115 ;
int V_304 = F_173 ( V_331 ) / V_6 -> V_8 . V_305 ;
V_47 = F_46 ( V_6 , V_37 , V_69 -> V_75 -> V_183 . V_13 , V_30 , & V_370 ) ;
if ( V_47 )
return V_47 ;
if ( V_370 != V_69 -> V_75 ) {
V_47 = - V_48 ;
goto V_310;
}
V_47 = F_46 ( V_6 , V_37 , V_304 , V_30 , & V_75 ) ;
if ( V_47 )
goto V_310;
V_47 = F_158 ( V_6 , V_37 , V_304 , F_174 ( V_331 ) , V_75 ) ;
if ( V_47 )
goto V_371;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_371;
F_163 ( & V_370 -> V_188 ) ;
F_51 ( V_6 , V_37 , V_370 -> V_183 . V_13 , V_30 ) ;
F_161 ( & V_75 -> V_188 ) ;
V_69 -> V_75 = V_75 ;
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
return 0 ;
V_371:
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
V_310:
F_51 ( V_6 , V_37 , V_370 -> V_183 . V_13 , V_30 ) ;
return V_47 ;
}
int F_195 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_237 = V_268 -> V_273 ;
struct V_196 * V_69 ;
int V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_237 , V_27 , & V_69 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 -> V_183 . V_178 != V_239 )
goto V_310;
if ( V_268 -> V_272 == 0 ) {
V_47 = F_194 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 , V_69 ) ;
goto V_310;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_310:
F_51 ( V_6 , V_37 , V_237 , V_27 ) ;
return V_47 ;
}
static int F_196 ( struct V_282 * V_283 )
{
int V_372 = ( F_39 ( V_283 -> V_373 ) >> 24 ) & 0xf ;
int V_291 = V_283 -> V_374 & 7 ;
int V_284 = ( V_283 -> V_285 & 0x3f ) + 12 ;
if ( V_372 + V_291 + 4 < V_284 )
return 1 ;
return 1 << ( V_372 + V_291 + 4 - V_284 ) ;
}
int F_197 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_252 = V_268 -> V_273 ;
struct V_190 * V_75 ;
struct V_198 * V_72 ;
struct V_282 * V_283 = V_113 -> V_115 ;
int V_304 = F_155 ( V_283 ) / V_6 -> V_8 . V_305 ;
if ( V_252 != ( F_39 ( V_283 -> V_373 ) & 0xffffff ) )
return - V_48 ;
V_47 = F_86 ( V_6 , V_37 , V_252 , V_241 , & V_72 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_304 , V_30 , & V_75 ) ;
if ( V_47 )
goto V_309;
V_47 = F_158 ( V_6 , V_37 , V_304 , F_196 ( V_283 ) ,
V_75 ) ;
if ( V_47 )
goto V_323;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_323;
F_161 ( & V_75 -> V_188 ) ;
V_72 -> V_75 = V_75 ;
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
F_88 ( V_6 , V_37 , V_28 , V_252 ) ;
return 0 ;
V_323:
F_51 ( V_6 , V_37 , V_75 -> V_183 . V_13 , V_30 ) ;
V_309:
F_87 ( V_6 , V_37 , V_28 , V_252 ) ;
return V_47 ;
}
int F_198 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_252 = V_268 -> V_273 ;
struct V_198 * V_72 ;
V_47 = F_86 ( V_6 , V_37 , V_252 , V_199 , & V_72 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_309;
F_163 ( & V_72 -> V_75 -> V_188 ) ;
if ( V_72 -> V_69 )
F_163 ( & V_72 -> V_69 -> V_188 ) ;
F_88 ( V_6 , V_37 , V_28 , V_252 ) ;
return 0 ;
V_309:
F_87 ( V_6 , V_37 , V_28 , V_252 ) ;
return V_47 ;
}
int F_199 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_252 = V_268 -> V_273 ;
struct V_198 * V_72 ;
V_47 = F_46 ( V_6 , V_37 , V_252 , V_28 , & V_72 ) ;
if ( V_47 )
return V_47 ;
if ( V_72 -> V_183 . V_178 != V_241 ) {
V_47 = - V_175 ;
goto V_60;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_60:
F_51 ( V_6 , V_37 , V_252 , V_28 ) ;
return V_47 ;
}
int F_200 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_252 = V_268 -> V_273 ;
struct V_198 * V_72 ;
V_47 = F_46 ( V_6 , V_37 , V_252 , V_28 , & V_72 ) ;
if ( V_47 )
return V_47 ;
if ( V_72 -> V_183 . V_178 != V_241 ) {
V_47 = - V_175 ;
goto V_60;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_60:
F_51 ( V_6 , V_37 , V_252 , V_28 ) ;
return V_47 ;
}
int F_201 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_136 = V_268 -> V_273 & 0x7fffff ;
struct V_181 * V_66 ;
V_47 = F_46 ( V_6 , V_37 , V_136 , V_26 , & V_66 ) ;
if ( V_47 )
return V_47 ;
if ( V_66 -> V_183 . V_178 != V_227 ) {
V_47 = - V_175 ;
goto V_60;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_60:
F_51 ( V_6 , V_37 , V_136 , V_26 ) ;
return V_47 ;
}
int F_202 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
struct V_119 * V_313 = V_113 -> V_115 + 8 ;
F_168 ( V_6 , V_268 , V_313 ) ;
F_37 ( V_6 , V_37 , V_113 ) ;
return F_201 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
}
static int F_203 ( struct V_5 * V_6 , int V_37 ,
struct V_119 * V_137 ,
struct V_112 * V_113 )
{
enum V_121 V_122 = F_39 ( * ( V_123 * ) V_113 -> V_115 ) ;
T_2 V_375 ;
int V_7 = F_120 (
V_6 , V_37 , ( V_137 -> V_127 . V_128 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_375 = ( V_137 -> V_127 . V_128 & ~ ( 1 << 6 ) ) |
( ( V_7 & 1 ) << 6 ) ;
if ( V_122 & V_133 ||
F_2 ( V_6 , V_7 + 1 ) ) {
V_137 -> V_127 . V_128 = V_375 ;
}
if ( V_122 & V_134 ) {
V_7 = F_120 (
V_6 , V_37 , ( V_137 -> V_135 . V_128 >> 6 & 1 )
+ 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_137 -> V_135 . V_128 =
( V_137 -> V_135 . V_128 & ~ ( 1 << 6 ) ) |
( V_7 & 1 ) << 6 ;
}
return 0 ;
}
static int F_204 ( struct V_5 * V_6 , int V_37 ,
struct V_119 * V_137 ,
struct V_112 * V_113 )
{
T_1 V_254 ;
int V_7 ;
T_3 V_124 = ( F_39 ( V_137 -> V_125 ) >> 16 ) & 0xff ;
T_2 V_114 = * ( T_2 * ) ( V_113 -> V_115 + 64 ) ;
T_2 V_376 ;
V_7 = ( V_114 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) && ( V_124 != V_377 ) ) {
V_376 = V_137 -> V_127 . V_170 & 0x7f ;
if ( F_113 ( V_6 , V_37 , V_7 , V_376 , & V_254 ) )
return - V_179 ;
}
return 0 ;
}
int F_205 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
struct V_119 * V_137 = V_113 -> V_115 + 8 ;
int V_136 = V_268 -> V_273 & 0x7fffff ;
struct V_181 * V_66 ;
T_2 V_378 ;
V_123 V_379 = V_137 -> V_144 ;
T_2 V_380 = V_137 -> V_127 . V_150 ;
T_2 V_381 = V_137 -> V_127 . V_157 ;
T_2 V_382 = V_137 -> V_127 . V_161 ;
T_2 V_383 = V_137 -> V_127 . V_159 ;
T_2 V_384 = V_137 -> V_127 . V_164 ;
V_47 = F_203 ( V_6 , V_37 , V_137 , V_113 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_178 ( V_6 , V_113 , V_343 , V_37 ) ;
if ( V_47 )
return V_47 ;
if ( F_204 ( V_6 , V_37 , V_137 , V_113 ) )
return - V_48 ;
F_37 ( V_6 , V_37 , V_113 ) ;
F_38 ( V_6 , V_113 , ( T_2 ) V_37 ) ;
F_168 ( V_6 , V_268 , V_137 ) ;
V_378 = V_137 -> V_127 . V_128 ;
V_47 = F_41 ( V_6 , V_113 , V_37 , V_136 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_46 ( V_6 , V_37 , V_136 , V_26 , & V_66 ) ;
if ( V_47 )
return V_47 ;
if ( V_66 -> V_183 . V_178 != V_227 ) {
V_47 = - V_175 ;
goto V_60;
}
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
V_60:
if ( ! V_47 ) {
V_66 -> V_128 = V_378 ;
V_66 -> V_144 = V_379 ;
V_66 -> V_150 = V_380 ;
V_66 -> V_157 = V_381 ;
V_66 -> V_321 = V_382 ;
V_66 -> V_159 = V_383 ;
V_66 -> V_164 = V_384 ;
}
F_51 ( V_6 , V_37 , V_136 , V_26 ) ;
return V_47 ;
}
int F_206 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
struct V_119 * V_313 = V_113 -> V_115 + 8 ;
V_47 = F_203 ( V_6 , V_37 , V_313 , V_113 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_178 ( V_6 , V_113 , V_344 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_37 ( V_6 , V_37 , V_113 ) ;
F_38 ( V_6 , V_113 , ( T_2 ) V_37 ) ;
F_168 ( V_6 , V_268 , V_313 ) ;
return F_201 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
}
int F_207 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
struct V_119 * V_313 = V_113 -> V_115 + 8 ;
V_47 = F_203 ( V_6 , V_37 , V_313 , V_113 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_178 ( V_6 , V_113 , V_345 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_37 ( V_6 , V_37 , V_113 ) ;
F_38 ( V_6 , V_113 , ( T_2 ) V_37 ) ;
F_168 ( V_6 , V_268 , V_313 ) ;
return F_201 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
}
int F_208 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
struct V_119 * V_313 = V_113 -> V_115 + 8 ;
int V_47 = F_203 ( V_6 , V_37 , V_313 , V_113 ) ;
if ( V_47 )
return V_47 ;
F_168 ( V_6 , V_268 , V_313 ) ;
return F_201 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
}
int F_209 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
struct V_119 * V_313 = V_113 -> V_115 + 8 ;
V_47 = F_203 ( V_6 , V_37 , V_313 , V_113 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_178 ( V_6 , V_113 , V_346 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_168 ( V_6 , V_268 , V_313 ) ;
F_38 ( V_6 , V_113 , ( T_2 ) V_37 ) ;
F_37 ( V_6 , V_37 , V_113 ) ;
return F_201 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
}
int F_210 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
struct V_119 * V_313 = V_113 -> V_115 + 8 ;
V_47 = F_203 ( V_6 , V_37 , V_313 , V_113 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_178 ( V_6 , V_113 , V_347 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_168 ( V_6 , V_268 , V_313 ) ;
F_38 ( V_6 , V_113 , ( T_2 ) V_37 ) ;
F_37 ( V_6 , V_37 , V_113 ) ;
return F_201 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
}
int F_211 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_136 = V_268 -> V_273 & 0x7fffff ;
struct V_181 * V_66 ;
V_47 = F_82 ( V_6 , V_37 , V_136 , V_226 , & V_66 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
if ( V_47 )
goto V_309;
F_163 ( & V_66 -> V_75 -> V_188 ) ;
F_163 ( & V_66 -> V_316 -> V_188 ) ;
F_163 ( & V_66 -> V_317 -> V_188 ) ;
if ( V_66 -> V_72 )
F_163 ( & V_66 -> V_72 -> V_188 ) ;
F_88 ( V_6 , V_37 , V_26 , V_136 ) ;
return 0 ;
V_309:
F_87 ( V_6 , V_37 , V_26 , V_136 ) ;
return V_47 ;
}
static struct V_385 * F_212 ( struct V_5 * V_6 , int V_37 ,
struct V_181 * V_386 , T_2 * V_387 )
{
struct V_385 * V_17 ;
F_177 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_17 -> V_387 , V_387 , 16 ) )
return V_17 ;
}
return NULL ;
}
static int F_213 ( struct V_5 * V_6 , int V_37 , struct V_181 * V_386 ,
T_2 * V_387 , enum V_388 V_389 ,
enum V_390 V_391 , T_1 V_392 )
{
struct V_385 * V_17 ;
int V_47 ;
V_17 = F_20 ( sizeof *V_17 , V_85 ) ;
if ( ! V_17 )
return - V_86 ;
F_47 ( & V_386 -> V_187 ) ;
if ( F_212 ( V_6 , V_37 , V_386 , V_387 ) ) {
F_30 ( V_17 ) ;
V_47 = - V_23 ;
} else {
memcpy ( V_17 -> V_387 , V_387 , 16 ) ;
V_17 -> V_389 = V_389 ;
V_17 -> V_391 = V_391 ;
V_17 -> V_392 = V_392 ;
F_65 ( & V_17 -> V_213 , & V_386 -> V_186 ) ;
V_47 = 0 ;
}
F_49 ( & V_386 -> V_187 ) ;
return V_47 ;
}
static int F_214 ( struct V_5 * V_6 , int V_37 , struct V_181 * V_386 ,
T_2 * V_387 , enum V_388 V_389 ,
enum V_390 V_391 , T_1 * V_392 )
{
struct V_385 * V_17 ;
int V_47 ;
F_47 ( & V_386 -> V_187 ) ;
V_17 = F_212 ( V_6 , V_37 , V_386 , V_387 ) ;
if ( ! V_17 || V_17 -> V_389 != V_389 || V_17 -> V_391 != V_391 )
V_47 = - V_48 ;
else {
* V_392 = V_17 -> V_392 ;
F_81 ( & V_17 -> V_213 ) ;
F_30 ( V_17 ) ;
V_47 = 0 ;
}
F_49 ( & V_386 -> V_187 ) ;
return V_47 ;
}
static int F_215 ( struct V_5 * V_6 , int V_37 , struct V_393 * V_66 ,
T_2 V_387 [ 16 ] , int V_394 , enum V_388 V_389 ,
enum V_390 type , T_1 * V_392 )
{
switch ( V_6 -> V_8 . V_395 ) {
case V_396 : {
int V_7 = F_120 ( V_6 , V_37 , V_387 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_216 ( V_6 , V_66 , V_387 , V_7 ,
V_394 , V_389 ,
V_392 ) ;
}
case V_397 :
if ( V_389 == V_398 ) {
int V_7 = F_120 ( V_6 , V_37 , V_387 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_387 [ 5 ] = V_7 ;
}
return F_217 ( V_6 , V_66 , V_387 ,
V_394 , V_389 , type ) ;
default:
return - V_48 ;
}
}
static int F_218 ( struct V_5 * V_6 , struct V_393 * V_66 ,
T_2 V_387 [ 16 ] , enum V_388 V_389 ,
enum V_390 type , T_1 V_392 )
{
switch ( V_6 -> V_8 . V_395 ) {
case V_396 :
return F_219 ( V_6 , V_392 ) ;
case V_397 :
return F_220 ( V_6 , V_66 , V_387 , V_389 , type ) ;
default:
return - V_48 ;
}
}
static int F_221 ( struct V_5 * V_6 , int V_37 ,
T_2 * V_387 , enum V_388 V_389 )
{
int V_399 ;
if ( V_389 != V_398 )
return 0 ;
if ( V_6 -> V_8 . V_395 == V_397 ||
V_6 -> V_8 . V_395 == V_396 ) {
V_399 = F_120 ( V_6 , V_37 , V_387 [ 5 ] ) ;
if ( V_399 < 0 )
return - V_48 ;
V_387 [ 5 ] = V_399 ;
}
return 0 ;
}
int F_222 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
struct V_393 V_66 ;
T_2 * V_387 = V_113 -> V_115 ;
enum V_388 V_389 = ( V_268 -> V_273 >> 28 ) & 0x7 ;
int V_47 ;
int V_136 ;
struct V_181 * V_386 ;
T_1 V_392 = 0 ;
int V_400 = V_268 -> V_272 ;
int V_394 = V_268 -> V_273 >> 31 ;
T_2 V_401 = 2 ;
enum V_390 type = ( V_387 [ 7 ] & V_401 ) >> 1 ;
V_136 = V_268 -> V_273 & 0xffffff ;
V_47 = F_46 ( V_6 , V_37 , V_136 , V_26 , & V_386 ) ;
if ( V_47 )
return V_47 ;
V_66 . V_136 = V_136 ;
if ( V_400 ) {
V_47 = F_215 ( V_6 , V_37 , & V_66 , V_387 , V_394 , V_389 ,
type , & V_392 ) ;
if ( V_47 ) {
F_70 ( L_22 , V_136 ) ;
goto V_310;
}
V_47 = F_213 ( V_6 , V_37 , V_386 , V_387 , V_389 , type , V_392 ) ;
if ( V_47 )
goto V_402;
} else {
V_47 = F_221 ( V_6 , V_37 , V_387 , V_389 ) ;
if ( V_47 )
goto V_310;
V_47 = F_214 ( V_6 , V_37 , V_386 , V_387 , V_389 , type , & V_392 ) ;
if ( V_47 )
goto V_310;
V_47 = F_218 ( V_6 , & V_66 , V_387 , V_389 , type , V_392 ) ;
if ( V_47 )
F_70 ( L_23 ,
V_136 , V_392 ) ;
}
F_51 ( V_6 , V_37 , V_136 , V_26 ) ;
return V_47 ;
V_402:
F_218 ( V_6 , & V_66 , V_387 , V_389 , type , V_392 ) ;
V_310:
F_51 ( V_6 , V_37 , V_136 , V_26 ) ;
return V_47 ;
}
static int F_223 ( int V_37 , struct V_403 * V_404 ,
struct V_255 * V_405 )
{
struct V_257 * V_17 , * V_258 ;
T_5 V_406 ;
if ( ! F_224 ( V_404 -> V_407 . V_408 ) &&
! F_225 ( V_404 -> V_407 . V_408 ) ) {
F_114 (res, tmp, rlist, list) {
V_406 = F_226 ( V_17 -> V_254 << 16 ) ;
if ( F_227 ( ( T_2 * ) & V_406 , V_404 -> V_407 . V_408 ) )
return 0 ;
}
F_70 ( L_24 ,
V_404 -> V_407 . V_408 , V_37 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_228 ( struct V_5 * V_6 , int V_37 ,
struct V_112 * V_113 ,
struct V_255 * V_405 , int V_409 )
{
struct V_257 * V_17 , * V_258 ;
T_2 V_7 ;
struct V_410 * V_411 ;
struct V_412 * V_404 ;
struct V_413 * V_414 ;
struct V_415 * V_416 ;
T_5 V_406 = 0 ;
T_5 V_417 = F_226 ( V_418 << 16 ) ;
V_411 = (struct V_410 * ) V_113 -> V_115 ;
V_7 = V_411 -> V_7 ;
V_404 = (struct V_412 * ) ( V_411 + 1 ) ;
switch ( V_409 ) {
case V_419 :
V_414 =
(struct V_413 * ) ( V_404 + 1 ) ;
memmove ( V_414 , V_404 ,
sizeof( * V_414 ) + sizeof( * V_416 ) ) ;
break;
case V_420 :
case V_421 :
V_416 = (struct V_415 * )
( V_404 + 1 ) ;
memmove ( V_416 , V_404 , sizeof( * V_416 ) ) ;
break;
default:
return - V_48 ;
}
F_114 (res, tmp, rlist, list) {
if ( V_7 == V_17 -> V_7 ) {
V_406 = F_226 ( V_17 -> V_254 << 16 ) ;
break;
}
}
if ( ! V_406 ) {
F_70 ( L_25 ,
V_7 ) ;
return - V_48 ;
}
memset ( V_404 , 0 , sizeof( * V_404 ) ) ;
V_404 -> V_301 = sizeof( * V_404 ) >> 2 ;
V_404 -> V_180 = F_187 ( V_422 [ V_423 ] ) ;
memcpy ( V_404 -> V_408 , & V_406 , V_424 ) ;
memcpy ( V_404 -> V_425 , & V_417 , V_424 ) ;
return 0 ;
}
int F_229 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_426 )
{
int V_47 ;
T_3 V_136 = V_268 -> V_273 & 0xffffff ;
struct V_181 * V_386 ;
T_1 V_254 ;
unsigned V_7 ;
T_1 V_427 ;
struct V_428 * V_245 ;
int V_253 ;
V_245 = (struct V_428 * ) V_113 -> V_115 ;
V_427 = F_148 ( V_245 -> V_429 ) ;
if ( V_245 -> V_430 || V_245 -> V_431 ||
( V_427 & ~ V_432 ) )
return - V_177 ;
V_47 = F_46 ( V_6 , V_37 , V_136 , V_26 , & V_386 ) ;
if ( V_47 ) {
F_230 ( V_6 , L_26 , V_136 , V_37 ) ;
return V_47 ;
}
V_7 = ( V_386 -> V_128 >> 6 & 1 ) + 1 ;
V_253 = V_245 -> V_433 . V_127 . V_170 ;
V_47 = F_113 ( V_6 , V_37 , V_7 ,
V_253 , & V_254 ) ;
if ( V_47 ) {
F_230 ( V_6 , L_27 ,
V_136 , V_253 ) ;
goto V_434;
}
V_47 = F_188 ( V_6 , V_113 -> V_366 ,
V_268 -> V_273 , 0 ,
V_435 , V_436 ,
V_369 ) ;
if ( V_47 ) {
F_230 ( V_6 , L_28 , V_136 ) ;
goto V_434;
}
V_434:
F_51 ( V_6 , V_37 , V_136 , V_26 ) ;
return V_47 ;
}
int F_231 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_405 = & V_211 -> V_83 [ V_37 ] . V_88 [ V_31 ] ;
int V_47 ;
int V_136 ;
struct V_181 * V_386 ;
struct V_410 * V_411 ;
struct V_403 * V_437 ;
int V_409 ;
if ( V_6 -> V_8 . V_395 !=
V_396 )
return - V_438 ;
V_411 = (struct V_410 * ) V_113 -> V_115 ;
V_411 -> V_7 = F_120 ( V_6 , V_37 , V_411 -> V_7 ) ;
if ( V_411 -> V_7 <= 0 )
return - V_48 ;
V_136 = F_39 ( V_411 -> V_136 ) & 0xffffff ;
V_47 = F_46 ( V_6 , V_37 , V_136 , V_26 , & V_386 ) ;
if ( V_47 ) {
F_70 ( L_29 , V_136 ) ;
return V_47 ;
}
V_437 = (struct V_403 * ) ( V_411 + 1 ) ;
V_409 = F_232 ( F_233 ( V_437 -> V_180 ) ) ;
switch ( V_409 ) {
case V_423 :
if ( F_223 ( V_37 , V_437 , V_405 ) ) {
V_47 = - V_48 ;
goto V_439;
}
break;
case V_440 :
break;
case V_419 :
case V_420 :
case V_421 :
F_234 ( L_30 ) ;
if ( F_228 ( V_6 , V_37 , V_113 , V_405 , V_409 ) ) {
V_47 = - V_48 ;
goto V_439;
}
V_268 -> V_273 +=
sizeof( struct V_412 ) >> 2 ;
break;
default:
F_70 ( L_31 ) ;
V_47 = - V_48 ;
goto V_439;
}
V_47 = F_235 ( V_6 , V_113 -> V_366 , & V_268 -> V_247 ,
V_268 -> V_273 , 0 ,
V_441 , V_436 ,
V_369 ) ;
if ( V_47 )
goto V_439;
V_47 = F_64 ( V_6 , V_37 , V_268 -> V_247 , 1 , V_35 , V_136 ) ;
if ( V_47 ) {
F_230 ( V_6 , L_32 ) ;
F_188 ( V_6 , V_268 -> V_247 , 0 , 0 ,
V_442 , V_436 ,
V_369 ) ;
goto V_439;
}
F_161 ( & V_386 -> V_188 ) ;
V_439:
F_51 ( V_6 , V_37 , V_136 , V_26 ) ;
return V_47 ;
}
int F_236 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
struct V_181 * V_386 ;
struct V_204 * V_443 ;
if ( V_6 -> V_8 . V_395 !=
V_396 )
return - V_438 ;
V_47 = F_46 ( V_6 , V_37 , V_268 -> V_246 , V_35 , & V_443 ) ;
if ( V_47 )
return V_47 ;
F_51 ( V_6 , V_37 , V_268 -> V_246 , V_35 ) ;
V_47 = F_46 ( V_6 , V_37 , V_443 -> V_136 , V_26 , & V_386 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_80 ( V_6 , V_37 , V_268 -> V_246 , 1 , V_35 , 0 ) ;
if ( V_47 ) {
F_230 ( V_6 , L_33 ) ;
goto V_60;
}
V_47 = F_188 ( V_6 , V_268 -> V_246 , 0 , 0 ,
V_442 , V_436 ,
V_369 ) ;
if ( ! V_47 )
F_163 ( & V_386 -> V_188 ) ;
V_60:
F_51 ( V_6 , V_37 , V_443 -> V_136 , V_26 ) ;
return V_47 ;
}
int F_237 ( struct V_5 * V_6 , int V_37 ,
struct V_267 * V_268 ,
struct V_112 * V_113 ,
struct V_112 * V_269 ,
struct V_270 * V_245 )
{
int V_47 ;
int V_229 = V_268 -> V_273 & 0xffff ;
V_47 = F_46 ( V_6 , V_37 , V_229 , V_34 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_160 ( V_6 , V_37 , V_268 , V_113 , V_269 , V_245 ) ;
F_51 ( V_6 , V_37 , V_229 , V_34 ) ;
return V_47 ;
}
static void F_238 ( struct V_5 * V_6 , int V_37 , struct V_181 * V_386 )
{
struct V_385 * V_444 ;
struct V_385 * V_258 ;
struct V_393 V_66 ;
F_114 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_6 -> V_8 . V_395 ) {
case V_396 :
F_219 ( V_6 , V_444 -> V_392 ) ;
break;
case V_397 :
V_66 . V_136 = V_386 -> V_185 ;
( void ) F_220 ( V_6 , & V_66 , V_444 -> V_387 ,
V_444 -> V_389 , V_444 -> V_391 ) ;
break;
}
F_81 ( & V_444 -> V_213 ) ;
F_30 ( V_444 ) ;
}
}
static int F_239 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_445 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_405 = & V_211 -> V_83 [ V_37 ] . V_88 [ type ] ;
struct V_16 * V_172 ;
struct V_16 * V_258 ;
int V_446 ;
V_446 = 0 ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (r, tmp, rlist, list) {
if ( V_172 -> V_176 == V_37 ) {
if ( ! V_172 -> V_447 ) {
if ( V_172 -> V_2 == V_174 ) {
if ( V_445 )
F_23 ( V_6 ,
L_34 ,
F_8 ( type ) ,
V_172 -> V_13 ) ;
++ V_446 ;
} else {
V_172 -> V_178 = V_172 -> V_2 ;
V_172 -> V_2 = V_174 ;
V_172 -> V_447 = 1 ;
}
}
}
}
F_49 ( F_48 ( V_6 ) ) ;
return V_446 ;
}
static int F_240 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type )
{
unsigned long V_448 ;
int V_446 ;
V_448 = V_449 ;
do {
V_446 = F_239 ( V_6 , V_37 , type , 0 ) ;
if ( F_241 ( V_449 , V_448 + 5 * V_450 ) )
break;
if ( V_446 )
F_242 () ;
} while ( V_446 );
if ( V_446 )
V_446 = F_239 ( V_6 , V_37 , type , 1 ) ;
return V_446 ;
}
static void F_243 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_451 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_26 ] ;
struct V_181 * V_66 ;
struct V_181 * V_258 ;
int V_2 ;
T_1 V_246 ;
int V_136 ;
int V_47 ;
V_47 = F_240 ( V_6 , V_37 , V_26 ) ;
if ( V_47 )
F_244 ( V_6 , L_35
L_36 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (qp, tmp, qp_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_66 -> V_183 . V_176 == V_37 ) {
V_136 = V_66 -> V_183 . V_13 ;
F_238 ( V_6 , V_37 , V_66 ) ;
V_2 = V_66 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_184 :
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_66 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_26 ] ) ;
F_81 ( & V_66 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
if ( ! F_89 ( V_6 , V_37 , V_136 ) ) {
F_97 ( V_6 , V_136 , 1 ) ;
F_12 ( V_6 , V_37 ,
V_26 , 1 , 0 ) ;
}
F_30 ( V_66 ) ;
V_2 = 0 ;
break;
case V_226 :
if ( ! F_89 ( V_6 , V_37 , V_136 ) )
F_135 ( V_6 , V_136 ) ;
V_2 = V_184 ;
break;
case V_227 :
V_246 = V_37 ;
V_47 = F_188 ( V_6 , V_246 ,
V_66 -> V_185 , 2 ,
V_452 ,
V_436 ,
V_369 ) ;
if ( V_47 )
F_23 ( V_6 , L_37
L_38
L_39 , V_37 ,
V_66 -> V_185 ) ;
F_163 ( & V_66 -> V_316 -> V_188 ) ;
F_163 ( & V_66 -> V_317 -> V_188 ) ;
F_163 ( & V_66 -> V_75 -> V_188 ) ;
if ( V_66 -> V_72 )
F_163 ( & V_66 -> V_72 -> V_188 ) ;
V_2 = V_226 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_245 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_453 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_28 ] ;
struct V_198 * V_72 ;
struct V_198 * V_258 ;
int V_2 ;
T_1 V_246 ;
F_246 ( V_454 ) ;
int V_252 ;
int V_47 ;
V_47 = F_240 ( V_6 , V_37 , V_28 ) ;
if ( V_47 )
F_244 ( V_6 , L_40
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (srq, tmp, srq_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_72 -> V_183 . V_176 == V_37 ) {
V_252 = V_72 -> V_183 . V_13 ;
V_2 = V_72 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_199 :
F_112 ( V_6 , V_252 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_72 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_28 ] ) ;
F_81 ( & V_72 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
F_12 ( V_6 , V_37 ,
V_28 , 1 , 0 ) ;
F_30 ( V_72 ) ;
V_2 = 0 ;
break;
case V_241 :
V_246 = V_37 ;
V_47 = F_188 ( V_6 , V_246 , V_252 , 1 ,
V_455 ,
V_436 ,
V_369 ) ;
if ( V_47 )
F_23 ( V_6 , L_42
L_43
L_44 ,
V_37 , V_252 ) ;
F_163 ( & V_72 -> V_75 -> V_188 ) ;
if ( V_72 -> V_69 )
F_163 ( & V_72 -> V_69 -> V_188 ) ;
V_2 = V_199 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_247 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_456 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_27 ] ;
struct V_196 * V_69 ;
struct V_196 * V_258 ;
int V_2 ;
T_1 V_246 ;
F_246 ( V_454 ) ;
int V_237 ;
int V_47 ;
V_47 = F_240 ( V_6 , V_37 , V_27 ) ;
if ( V_47 )
F_244 ( V_6 , L_45
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (cq, tmp, cq_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_69 -> V_183 . V_176 == V_37 && ! F_68 ( & V_69 -> V_188 ) ) {
V_237 = V_69 -> V_183 . V_13 ;
V_2 = V_69 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_197 :
F_109 ( V_6 , V_237 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_69 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_27 ] ) ;
F_81 ( & V_69 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
F_12 ( V_6 , V_37 ,
V_27 , 1 , 0 ) ;
F_30 ( V_69 ) ;
V_2 = 0 ;
break;
case V_239 :
V_246 = V_37 ;
V_47 = F_188 ( V_6 , V_246 , V_237 , 1 ,
V_457 ,
V_436 ,
V_369 ) ;
if ( V_47 )
F_23 ( V_6 , L_46
L_47
L_44 ,
V_37 , V_237 ) ;
F_163 ( & V_69 -> V_75 -> V_188 ) ;
V_2 = V_197 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_248 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_458 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_29 ] ;
struct V_192 * V_77 ;
struct V_192 * V_258 ;
int V_2 ;
T_1 V_246 ;
F_246 ( V_454 ) ;
int V_459 ;
int V_47 ;
V_47 = F_240 ( V_6 , V_37 , V_29 ) ;
if ( V_47 )
F_244 ( V_6 , L_48
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (mpt, tmp, mpt_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_77 -> V_183 . V_176 == V_37 ) {
V_459 = V_77 -> V_183 . V_13 ;
V_2 = V_77 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_193 :
F_105 ( V_6 , V_77 -> V_191 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_77 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_29 ] ) ;
F_81 ( & V_77 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
F_12 ( V_6 , V_37 ,
V_29 , 1 , 0 ) ;
F_30 ( V_77 ) ;
V_2 = 0 ;
break;
case V_231 :
F_138 ( V_6 , V_77 -> V_191 ) ;
V_2 = V_193 ;
break;
case V_232 :
V_246 = V_37 ;
V_47 = F_188 ( V_6 , V_246 , V_459 , 0 ,
V_460 ,
V_436 ,
V_369 ) ;
if ( V_47 )
F_23 ( V_6 , L_49
L_50
L_44 ,
V_37 , V_459 ) ;
if ( V_77 -> V_75 )
F_163 ( & V_77 -> V_75 -> V_188 ) ;
V_2 = V_231 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_249 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_461 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_30 ] ;
struct V_190 * V_75 ;
struct V_190 * V_258 ;
int V_2 ;
F_246 ( V_454 ) ;
int V_208 ;
int V_47 ;
V_47 = F_240 ( V_6 , V_37 , V_30 ) ;
if ( V_47 )
F_244 ( V_6 , L_51
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (mtt, tmp, mtt_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_75 -> V_183 . V_176 == V_37 ) {
V_208 = V_75 -> V_183 . V_13 ;
V_2 = V_75 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_102 ( V_6 , V_208 ,
V_75 -> V_189 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_75 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_30 ] ) ;
F_81 ( & V_75 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
F_12 ( V_6 , V_37 , V_30 ,
1 << V_75 -> V_189 , 0 ) ;
F_30 ( V_75 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_250 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_462 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_35 ] ;
struct V_204 * V_463 ;
struct V_204 * V_258 ;
int V_2 ;
T_1 V_208 ;
int V_47 ;
V_47 = F_240 ( V_6 , V_37 , V_35 ) ;
if ( V_47 )
F_244 ( V_6 , L_52 ,
V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (fs_rule, tmp, fs_rule_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_463 -> V_183 . V_176 == V_37 ) {
V_208 = V_463 -> V_183 . V_13 ;
V_2 = V_463 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_205 :
V_47 = F_188 ( V_6 , V_208 , 0 , 0 ,
V_442 ,
V_436 ,
V_369 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_463 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_35 ] ) ;
F_81 ( & V_463 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
F_30 ( V_463 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_251 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_464 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_33 ] ;
struct V_194 * V_234 ;
struct V_194 * V_258 ;
int V_47 ;
int V_2 ;
F_246 ( V_454 ) ;
int V_334 ;
struct V_112 * V_358 ;
V_47 = F_240 ( V_6 , V_37 , V_33 ) ;
if ( V_47 )
F_244 ( V_6 , L_53
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (eq, tmp, eq_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_234 -> V_183 . V_176 == V_37 ) {
V_334 = V_234 -> V_183 . V_13 ;
V_2 = V_234 -> V_183 . V_178 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_195 :
F_47 ( F_48 ( V_6 ) ) ;
F_66 ( & V_234 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_33 ] ) ;
F_81 ( & V_234 -> V_183 . V_213 ) ;
F_49 ( F_48 ( V_6 ) ) ;
F_30 ( V_234 ) ;
V_2 = 0 ;
break;
case V_236 :
V_358 = F_184 ( V_6 ) ;
if ( F_185 ( V_358 ) ) {
F_242 () ;
continue;
}
V_47 = F_252 ( V_6 , V_37 , 0 ,
V_334 & 0xff , 0 ,
V_465 ,
V_436 ,
V_369 ) ;
if ( V_47 )
F_23 ( V_6 , L_54
L_55
L_44 , V_37 , V_334 ) ;
F_189 ( V_6 , V_358 ) ;
F_163 ( & V_234 -> V_75 -> V_188 ) ;
V_2 = V_195 ;
break;
default:
V_2 = 0 ;
}
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_253 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_466 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_34 ] ;
struct V_200 * V_467 ;
struct V_200 * V_258 ;
int V_47 ;
int V_229 ;
V_47 = F_240 ( V_6 , V_37 , V_34 ) ;
if ( V_47 )
F_244 ( V_6 , L_56
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (counter, tmp, counter_list, com.list) {
if ( V_467 -> V_183 . V_176 == V_37 ) {
V_229 = V_467 -> V_183 . V_13 ;
F_66 ( & V_467 -> V_183 . V_15 ,
& V_211 -> V_90 [ V_34 ] ) ;
F_81 ( & V_467 -> V_183 . V_213 ) ;
F_30 ( V_467 ) ;
F_129 ( V_6 , V_229 ) ;
F_12 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
}
}
F_49 ( F_48 ( V_6 ) ) ;
}
static void F_254 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_210 * V_211 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_468 =
& V_211 -> V_83 [ V_37 ] . V_88 [ V_36 ] ;
struct V_202 * V_469 ;
struct V_202 * V_258 ;
int V_47 ;
int V_266 ;
V_47 = F_240 ( V_6 , V_37 , V_36 ) ;
if ( V_47 )
F_244 ( V_6 , L_57
L_41 , V_37 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_469 -> V_183 . V_176 == V_37 ) {
V_266 = V_469 -> V_183 . V_13 ;
F_66 ( & V_469 -> V_183 . V_15 , & V_211 -> V_90 [ V_36 ] ) ;
F_81 ( & V_469 -> V_183 . V_213 ) ;
F_30 ( V_469 ) ;
F_132 ( V_6 , V_266 ) ;
}
}
F_49 ( F_48 ( V_6 ) ) ;
}
void F_32 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
F_33 ( V_6 , V_37 ) ;
F_34 ( & V_41 -> V_44 . V_45 . V_46 . V_83 [ V_37 ] . V_89 ) ;
F_35 ( V_6 , V_37 ) ;
F_117 ( V_6 , V_37 ) ;
F_250 ( V_6 , V_37 ) ;
F_243 ( V_6 , V_37 ) ;
F_245 ( V_6 , V_37 ) ;
F_247 ( V_6 , V_37 ) ;
F_248 ( V_6 , V_37 ) ;
F_251 ( V_6 , V_37 ) ;
F_249 ( V_6 , V_37 ) ;
F_253 ( V_6 , V_37 ) ;
F_254 ( V_6 , V_37 ) ;
F_36 ( & V_41 -> V_44 . V_45 . V_46 . V_83 [ V_37 ] . V_89 ) ;
}
void F_255 ( struct V_470 * V_471 )
{
struct V_472 * V_473 =
F_4 ( V_471 , struct V_472 , V_473 ) ;
struct V_112 * V_358 ;
struct V_428 * V_474 ;
struct V_5 * V_6 = & V_473 -> V_41 -> V_6 ;
struct V_210 * V_211 =
& V_473 -> V_41 -> V_44 . V_45 . V_46 ;
struct V_255 * V_451 =
& V_211 -> V_83 [ V_473 -> V_37 ] . V_88 [ V_26 ] ;
struct V_181 * V_66 ;
struct V_181 * V_258 ;
T_1 V_475 =
( ( 1ULL << V_476 ) |
( 1ULL << V_477 ) |
( 1ULL << V_478 ) |
( 1ULL << V_479 ) |
( 1ULL << V_480 ) |
( 1ULL << V_481 ) ) ;
T_1 V_482 = ( ( 1ULL << V_483 ) |
( 1ULL << V_484 ) |
( 1ULL << V_485 ) |
( 1ULL << V_486 ) |
( 1ULL << V_487 ) |
( 1ULL << V_488 ) |
( 1ULL << V_489 ) ) ;
int V_47 ;
int V_7 , V_490 = 0 ;
T_2 V_150 ;
if ( F_16 ( V_6 ) ) {
F_244 ( V_6 , L_58 ,
V_473 -> V_37 ) ;
goto V_60;
}
V_358 = F_184 ( V_6 ) ;
if ( F_185 ( V_358 ) )
goto V_60;
if ( V_473 -> V_125 & V_491 )
V_150 = V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 ;
else if ( ! V_473 -> V_492 )
V_150 = V_151 |
V_156 ;
else
V_150 = V_151 |
V_154 |
V_155 ;
V_474 = V_358 -> V_115 ;
V_474 -> V_430 = F_226 ( V_493 ) ;
F_47 ( F_48 ( V_6 ) ) ;
F_114 (qp, tmp, qp_list, com.list) {
F_49 ( F_48 ( V_6 ) ) ;
if ( V_66 -> V_183 . V_176 == V_473 -> V_37 ) {
if ( V_66 -> V_183 . V_178 != V_227 ||
! V_66 -> V_128 ||
F_42 ( V_6 , V_66 -> V_185 ) ||
V_66 -> V_322 & ( 1 << V_494 ) ) {
F_47 ( F_48 ( V_6 ) ) ;
continue;
}
V_7 = ( V_66 -> V_128 >> 6 & 1 ) + 1 ;
if ( V_7 != V_473 -> V_7 ) {
F_47 ( F_48 ( V_6 ) ) ;
continue;
}
if ( V_130 == ( ( V_66 -> V_322 >> 16 ) & 0xff ) )
V_474 -> V_429 = F_226 ( V_482 ) ;
else
V_474 -> V_429 =
F_226 ( V_482 | V_475 ) ;
if ( V_473 -> V_492 == V_142 ) {
V_474 -> V_433 . V_144 = V_66 -> V_144 ;
V_474 -> V_433 . V_127 . V_150 = V_66 -> V_150 ;
V_474 -> V_433 . V_127 . V_157 = V_66 -> V_157 ;
V_474 -> V_433 . V_127 . V_159 = V_66 -> V_159 ;
V_474 -> V_433 . V_127 . V_161 = V_66 -> V_321 ;
V_474 -> V_433 . V_127 . V_164 = V_66 -> V_164 ;
V_474 -> V_433 . V_127 . V_128 =
V_66 -> V_128 ;
} else {
V_474 -> V_433 . V_144 = V_66 -> V_144 & ~ F_43 ( V_145 ) ;
V_474 -> V_433 . V_127 . V_150 = V_150 ;
V_474 -> V_433 . V_127 . V_159 = V_473 -> V_495 ;
V_474 -> V_433 . V_127 . V_157 =
V_66 -> V_157 | V_158 ;
V_474 -> V_433 . V_127 . V_161 =
V_66 -> V_321 | V_162 | V_163 ;
V_474 -> V_433 . V_127 . V_164 =
V_66 -> V_164 | V_165 | V_166 ;
V_474 -> V_433 . V_127 . V_128 =
V_66 -> V_128 & 0xC7 ;
V_474 -> V_433 . V_127 . V_128 |=
( ( V_473 -> V_496 & 0x7 ) << 3 ) ;
}
V_47 = F_188 ( V_6 , V_358 -> V_366 ,
V_66 -> V_185 & 0xffffff ,
0 , V_435 ,
V_497 , V_369 ) ;
if ( V_47 ) {
F_256 ( V_6 , L_59
L_60 ,
V_473 -> V_37 , V_7 , V_66 -> V_185 ,
V_47 ) ;
V_490 ++ ;
}
}
F_47 ( F_48 ( V_6 ) ) ;
}
F_49 ( F_48 ( V_6 ) ) ;
F_189 ( V_6 , V_358 ) ;
if ( V_490 )
F_230 ( V_6 , L_61 ,
V_490 , V_473 -> V_37 , V_473 -> V_7 ) ;
if ( V_473 -> V_125 & V_498 && ! V_490 &&
V_499 != V_473 -> V_500 )
F_124 ( & V_473 -> V_41 -> V_6 , V_473 -> V_7 ,
V_473 -> V_501 ) ;
V_60:
F_30 ( V_473 ) ;
return;
}
