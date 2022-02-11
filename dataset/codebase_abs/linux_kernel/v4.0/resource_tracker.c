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
if ( V_37 > V_6 -> V_54 -> V_55 )
return - V_48 ;
F_10 ( & V_43 -> V_56 ) ;
V_49 = ( V_7 > 0 ) ?
V_43 -> V_49 [ ( V_7 - 1 ) *
( V_6 -> V_54 -> V_55 + 1 ) + V_37 ] :
V_43 -> V_49 [ V_37 ] ;
free = ( V_7 > 0 ) ? V_43 -> V_57 [ V_7 - 1 ] :
V_43 -> V_58 ;
V_50 = ( V_7 > 0 ) ? V_43 -> V_59 [ V_7 - 1 ] :
V_43 -> V_60 ;
V_51 = V_43 -> V_51 [ V_37 ] ;
if ( V_49 + V_39 > V_43 -> V_61 [ V_37 ] ) {
F_11 ( V_6 , L_16 ,
V_37 , V_7 , F_8 ( V_38 ) , V_39 ,
V_49 , V_43 -> V_61 [ V_37 ] ) ;
goto V_62;
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
V_43 -> V_49 [ ( V_7 - 1 ) *
( V_6 -> V_54 -> V_55 + 1 ) + V_37 ] += V_39 ;
V_43 -> V_57 [ V_7 - 1 ] -= V_39 ;
V_43 -> V_59 [ V_7 - 1 ] -= V_53 ;
} else {
V_43 -> V_49 [ V_37 ] += V_39 ;
V_43 -> V_58 -= V_39 ;
V_43 -> V_60 -= V_53 ;
}
}
V_62:
F_12 ( & V_43 -> V_56 ) ;
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
if ( V_37 > V_6 -> V_54 -> V_55 )
return;
F_10 ( & V_43 -> V_56 ) ;
V_49 = ( V_7 > 0 ) ?
V_43 -> V_49 [ ( V_7 - 1 ) *
( V_6 -> V_54 -> V_55 + 1 ) + V_37 ] :
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
V_43 -> V_49 [ ( V_7 - 1 ) *
( V_6 -> V_54 -> V_55 + 1 ) + V_37 ] -= V_39 ;
V_43 -> V_57 [ V_7 - 1 ] += V_39 ;
V_43 -> V_59 [ V_7 - 1 ] += V_53 ;
} else {
V_43 -> V_49 [ V_37 ] -= V_39 ;
V_43 -> V_58 += V_39 ;
V_43 -> V_60 += V_53 ;
}
F_12 ( & V_43 -> V_56 ) ;
return;
}
static inline void F_14 ( struct V_5 * V_6 ,
struct V_42 * V_43 ,
enum V_24 V_38 ,
int V_63 , int V_64 )
{
V_43 -> V_51 [ V_63 ] = V_64 /
( 2 * ( V_6 -> V_54 -> V_55 + 1 ) ) ;
V_43 -> V_61 [ V_63 ] = ( V_64 / 2 ) + V_43 -> V_51 [ V_63 ] ;
if ( V_63 == F_15 ( V_6 ) ) {
V_43 -> V_58 = V_64 ;
if ( V_38 == V_30 ) {
V_43 -> V_58 += V_6 -> V_8 . V_65 ;
V_43 -> V_51 [ V_63 ] += V_6 -> V_8 . V_65 ;
V_43 -> V_61 [ V_63 ] += V_6 -> V_8 . V_65 ;
}
}
}
void F_16 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_66 ;
if ( F_17 ( V_6 ) )
return;
if ( ! F_18 ( V_6 ) ) {
V_6 -> V_67 . V_68 = V_6 -> V_8 . V_69 - V_6 -> V_8 . V_70 -
F_19 ( V_6 ) ;
V_6 -> V_67 . V_71 = V_6 -> V_8 . V_72 - V_6 -> V_8 . V_73 ;
V_6 -> V_67 . V_74 = V_6 -> V_8 . V_75 - V_6 -> V_8 . V_76 ;
V_6 -> V_67 . V_77 = V_6 -> V_8 . V_78 - V_6 -> V_8 . V_65 ;
V_6 -> V_67 . V_79 = V_6 -> V_8 . V_80 - V_6 -> V_8 . V_81 ;
return;
}
V_66 = F_15 ( V_6 ) ;
V_6 -> V_67 . V_68 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_26 ] . V_61 [ V_66 ] ;
V_6 -> V_67 . V_71 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_27 ] . V_61 [ V_66 ] ;
V_6 -> V_67 . V_74 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_28 ] . V_61 [ V_66 ] ;
V_6 -> V_67 . V_77 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_30 ] . V_61 [ V_66 ] ;
V_6 -> V_67 . V_79 =
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_29 ] . V_61 [ V_66 ] ;
}
int F_20 ( struct V_5 * V_6 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_82 , V_83 ;
int V_84 ;
V_41 -> V_44 . V_45 . V_46 . V_85 =
F_21 ( V_6 -> V_86 * sizeof( struct V_85 ) ,
V_87 ) ;
if ( ! V_41 -> V_44 . V_45 . V_46 . V_85 )
return - V_88 ;
for ( V_82 = 0 ; V_82 < V_6 -> V_86 ; V_82 ++ ) {
for ( V_84 = 0 ; V_84 < V_89 ; ++ V_84 )
F_22 ( & V_41 -> V_44 . V_45 . V_46 .
V_85 [ V_82 ] . V_90 [ V_84 ] ) ;
F_23 ( & V_41 -> V_44 . V_45 . V_46 . V_85 [ V_82 ] . V_91 ) ;
}
F_24 ( V_6 , L_18 ,
V_6 -> V_86 ) ;
for ( V_82 = 0 ; V_82 < V_89 ; V_82 ++ )
V_41 -> V_44 . V_45 . V_46 . V_92 [ V_82 ] = V_93 ;
for ( V_82 = 0 ; V_82 < V_89 ; V_82 ++ ) {
struct V_42 * V_43 =
& V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] ;
V_43 -> V_61 = F_25 ( ( V_6 -> V_54 -> V_55 + 1 ) *
sizeof( int ) , V_87 ) ;
V_43 -> V_51 = F_25 ( ( V_6 -> V_54 -> V_55 + 1 ) *
sizeof( int ) , V_87 ) ;
if ( V_82 == V_31 || V_82 == V_32 )
V_43 -> V_49 = F_21 ( V_94 *
( V_6 -> V_54 -> V_55
+ 1 ) *
sizeof( int ) , V_87 ) ;
else
V_43 -> V_49 = F_21 ( ( V_6 -> V_54 ->
V_55 + 1 ) *
sizeof( int ) , V_87 ) ;
if ( ! V_43 -> V_61 || ! V_43 -> V_51 ||
! V_43 -> V_49 )
goto V_95;
F_26 ( & V_43 -> V_56 ) ;
for ( V_84 = 0 ; V_84 < V_6 -> V_54 -> V_55 + 1 ; V_84 ++ ) {
struct V_96 V_97 =
F_27 ( V_6 , V_84 ) ;
switch ( V_82 ) {
case V_26 :
F_14 ( V_6 , V_43 , V_26 ,
V_84 , V_6 -> V_8 . V_69 -
V_6 -> V_8 . V_70 -
F_19 ( V_6 ) ) ;
break;
case V_27 :
F_14 ( V_6 , V_43 , V_27 ,
V_84 , V_6 -> V_8 . V_72 -
V_6 -> V_8 . V_73 ) ;
break;
case V_28 :
F_14 ( V_6 , V_43 , V_28 ,
V_84 , V_6 -> V_8 . V_75 -
V_6 -> V_8 . V_76 ) ;
break;
case V_29 :
F_14 ( V_6 , V_43 , V_29 ,
V_84 , V_6 -> V_8 . V_80 -
V_6 -> V_8 . V_81 ) ;
break;
case V_30 :
F_14 ( V_6 , V_43 , V_30 ,
V_84 , V_6 -> V_8 . V_78 -
V_6 -> V_8 . V_65 ) ;
break;
case V_31 :
if ( V_84 == F_15 ( V_6 ) ) {
int V_98 = 0 ;
for ( V_83 = 0 ; V_83 < V_6 -> V_8 . V_99 ;
V_83 ++ ) {
struct V_100 V_101 =
F_28 ( V_6 , V_83 + 1 ) ;
unsigned V_102 =
F_29 ( V_101 . V_103 ,
V_6 -> V_8 . V_99 ) - 1 ;
if ( V_98 < V_102 )
V_98 =
V_102 ;
}
V_43 -> V_61 [ V_84 ] =
V_104 -
2 * V_98 ;
V_43 -> V_51 [ V_84 ] = 2 ;
for ( V_83 = 0 ; V_83 < V_94 ; V_83 ++ )
V_43 -> V_57 [ V_83 ] =
V_104 ;
} else {
V_43 -> V_61 [ V_84 ] = V_104 ;
V_43 -> V_51 [ V_84 ] = 2 ;
}
break;
case V_32 :
if ( V_84 == F_15 ( V_6 ) ) {
V_43 -> V_61 [ V_84 ] = V_105 ;
V_43 -> V_51 [ V_84 ] = V_105 / 2 ;
for ( V_83 = 0 ; V_83 < V_94 ; V_83 ++ )
V_43 -> V_57 [ V_83 ] =
V_43 -> V_61 [ V_84 ] ;
} else {
V_43 -> V_61 [ V_84 ] = V_105 / 2 ;
V_43 -> V_51 [ V_84 ] = 0 ;
}
break;
case V_34 :
V_43 -> V_61 [ V_84 ] = V_6 -> V_8 . V_106 ;
V_43 -> V_51 [ V_84 ] = 0 ;
if ( V_84 == F_15 ( V_6 ) )
V_43 -> V_58 = V_43 -> V_61 [ V_84 ] ;
break;
default:
break;
}
if ( V_82 == V_31 || V_82 == V_32 ) {
for ( V_83 = 0 ; V_83 < V_6 -> V_8 . V_99 ; V_83 ++ )
if ( F_30 ( V_83 , V_97 . V_107 ) )
V_43 -> V_59 [ V_83 ] +=
V_43 -> V_51 [ V_84 ] ;
} else {
V_43 -> V_60 += V_43 -> V_51 [ V_84 ] ;
}
}
}
F_26 ( & V_41 -> V_44 . V_45 . V_46 . V_108 ) ;
return 0 ;
V_95:
for ( V_82 = 0 ; V_82 < V_89 ; V_82 ++ ) {
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_49 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_49 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_51 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_51 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_61 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_61 = NULL ;
}
return - V_88 ;
}
void F_32 ( struct V_5 * V_6 ,
enum V_109 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_82 ;
if ( V_41 -> V_44 . V_45 . V_46 . V_85 ) {
if ( type != V_110 ) {
for ( V_82 = 0 ; V_82 < V_6 -> V_86 ; V_82 ++ ) {
if ( type == V_111 ||
V_6 -> V_8 . V_112 != V_82 )
F_33 ( V_6 , V_82 ) ;
}
V_82 = V_6 -> V_8 . V_112 ;
F_34 ( V_6 , V_82 ) ;
F_35 ( & V_41 -> V_44 . V_45 . V_46 . V_85 [ V_82 ] . V_91 ) ;
F_36 ( V_6 , V_82 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_46 . V_85 [ V_82 ] . V_91 ) ;
}
if ( type != V_113 ) {
for ( V_82 = 0 ; V_82 < V_89 ; V_82 ++ ) {
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_49 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_49 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_51 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_51 = NULL ;
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_61 ) ;
V_41 -> V_44 . V_45 . V_46 . V_43 [ V_82 ] . V_61 = NULL ;
}
F_31 ( V_41 -> V_44 . V_45 . V_46 . V_85 ) ;
V_41 -> V_44 . V_45 . V_46 . V_85 = NULL ;
}
}
}
static void F_38 ( struct V_5 * V_6 , int V_37 ,
struct V_114 * V_115 )
{
T_2 V_116 = * ( T_2 * ) ( V_115 -> V_117 + 64 ) ;
T_2 V_118 = * ( T_2 * ) ( V_115 -> V_117 + 35 ) ;
T_2 V_119 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
int V_7 ;
V_7 = ( V_116 >> 6 & 1 ) + 1 ;
V_119 = V_41 -> V_120 [ V_37 ] [ V_7 - 1 ] [ V_118 ] ;
* ( T_2 * ) ( V_115 -> V_117 + 35 ) = V_119 ;
}
static void F_39 ( struct V_5 * V_6 , struct V_114 * V_115 ,
T_2 V_37 )
{
struct V_121 * V_122 = V_115 -> V_117 + 8 ;
enum V_123 V_124 = F_40 ( * ( V_125 * ) V_115 -> V_117 ) ;
T_3 V_126 = ( F_40 ( V_122 -> V_127 ) >> 16 ) & 0xff ;
int V_7 ;
if ( V_128 == V_126 ) {
V_7 = ( V_122 -> V_129 . V_130 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) )
V_122 -> V_129 . V_131 =
F_41 ( V_6 , V_37 , V_7 ) | 0x80 ;
else
V_122 -> V_129 . V_131 = V_37 | 0x80 ;
} else if ( V_132 == V_126 || V_133 == V_126 || V_134 == V_126 ) {
if ( V_124 & V_135 ) {
V_7 = ( V_122 -> V_129 . V_130 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) ) {
V_122 -> V_129 . V_131 +=
F_41 ( V_6 , V_37 , V_7 ) ;
V_122 -> V_129 . V_131 &= 0x7f ;
} else {
V_122 -> V_129 . V_131 = V_37 & 0x7F ;
}
}
if ( V_124 & V_136 ) {
V_7 = ( V_122 -> V_137 . V_130 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) ) {
V_122 -> V_137 . V_131 +=
F_41 ( V_6 , V_37 , V_7 ) ;
V_122 -> V_137 . V_131 &= 0x7f ;
} else {
V_122 -> V_137 . V_131 = V_37 & 0x7F ;
}
}
}
}
static int F_42 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
T_2 V_37 , T_3 V_138 )
{
struct V_121 * V_139 = V_115 -> V_117 + 8 ;
struct V_140 * V_141 ;
struct V_40 * V_41 ;
T_3 V_142 ;
int V_7 , V_47 = 0 ;
V_7 = ( V_139 -> V_129 . V_130 & 0x40 ) ? 2 : 1 ;
V_41 = V_40 ( V_6 ) ;
V_141 = & V_41 -> V_44 . V_45 . V_143 [ V_37 ] . V_144 [ V_7 ] ;
V_142 = ( F_40 ( V_139 -> V_127 ) >> 16 ) & 0xff ;
if ( V_145 != V_141 -> V_2 . V_146 ) {
if ( F_43 ( V_6 , V_138 ) )
return 0 ;
if ( V_142 == V_128 ||
( V_142 == V_147 && F_2 ( V_6 , V_7 ) ) ) {
if ( V_6 -> V_8 . V_148 & V_149 ) {
* ( V_125 * ) V_115 -> V_117 =
F_44 ( F_40 ( * ( V_125 * ) V_115 -> V_117 ) |
V_150 ) ;
V_139 -> V_151 &= ~ F_44 ( V_152 ) ;
} else {
struct V_153 V_154 = { . V_127 = 0 } ;
V_47 = F_45 ( V_6 , V_138 , V_155 , & V_154 ) ;
if ( V_47 )
goto V_62;
}
}
if ( V_141 -> V_2 . V_156 == V_157 &&
V_6 -> V_8 . V_158 & V_159 ) {
V_139 -> V_129 . V_160 =
V_161 |
V_162 |
V_163 |
V_164 |
V_165 |
V_166 ;
} else if ( 0 != V_141 -> V_2 . V_146 ) {
V_139 -> V_129 . V_160 =
V_161 |
V_164 |
V_165 ;
} else {
V_139 -> V_129 . V_160 =
V_161 |
V_166 ;
}
V_139 -> V_129 . V_167 |= V_168 ;
V_139 -> V_129 . V_169 = V_141 -> V_170 ;
V_139 -> V_129 . V_171 |= V_172 | V_173 ;
V_139 -> V_129 . V_174 |= V_175 | V_176 ;
V_139 -> V_129 . V_130 &= 0xC7 ;
V_139 -> V_129 . V_130 |= ( V_141 -> V_2 . V_177 ) << 3 ;
}
if ( V_141 -> V_2 . V_178 ) {
V_139 -> V_129 . V_174 |= V_179 ;
V_139 -> V_129 . V_180 = ( 0x80 & V_139 -> V_129 . V_180 ) + V_141 -> V_181 ;
}
V_62:
return V_47 ;
}
static int F_46 ( struct V_5 * V_6 )
{
return V_6 -> V_8 . V_80 - 1 ;
}
static void * F_47 ( struct V_5 * V_6 , T_1 V_13 ,
enum V_24 type )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
return F_3 ( & V_41 -> V_44 . V_45 . V_46 . V_92 [ type ] ,
V_13 ) ;
}
static int F_48 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type ,
void * V_17 )
{
struct V_16 * V_182 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_47 ( V_6 , V_13 , type ) ;
if ( ! V_182 ) {
V_47 = - V_183 ;
goto exit;
}
if ( V_182 -> V_2 == V_184 ) {
V_47 = - V_185 ;
goto exit;
}
if ( V_182 -> V_186 != V_37 ) {
V_47 = - V_187 ;
goto exit;
}
V_182 -> V_188 = V_182 -> V_2 ;
V_182 -> V_2 = V_184 ;
if ( V_17 )
* ( (struct V_16 * * ) V_17 ) = V_182 ;
exit:
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
int F_52 ( struct V_5 * V_6 ,
enum V_24 type ,
T_1 V_13 , int * V_37 )
{
struct V_16 * V_182 ;
int V_47 = - V_189 ;
int V_190 = V_13 ;
if ( type == V_26 )
V_190 &= 0x7fffff ;
F_10 ( F_50 ( V_6 ) ) ;
V_182 = F_47 ( V_6 , V_190 , type ) ;
if ( V_182 ) {
* V_37 = V_182 -> V_186 ;
V_47 = 0 ;
}
F_12 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static void F_53 ( struct V_5 * V_6 , int V_37 , T_1 V_13 ,
enum V_24 type )
{
struct V_16 * V_182 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_47 ( V_6 , V_13 , type ) ;
if ( V_182 )
V_182 -> V_2 = V_182 -> V_188 ;
F_51 ( F_50 ( V_6 ) ) ;
}
static struct V_16 * F_54 ( int V_190 )
{
struct V_191 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_194 ;
V_192 -> V_195 = V_190 ;
F_22 ( & V_192 -> V_196 ) ;
F_26 ( & V_192 -> V_197 ) ;
F_55 ( & V_192 -> V_198 , 0 ) ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_56 ( int V_190 , int V_199 )
{
struct V_200 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_199 = V_199 ;
V_192 -> V_193 . V_2 = V_4 ;
F_55 ( & V_192 -> V_198 , 0 ) ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_57 ( int V_190 , int V_201 )
{
struct V_202 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_203 ;
V_192 -> V_201 = V_201 ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_58 ( int V_190 )
{
struct V_204 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_205 ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_59 ( int V_190 )
{
struct V_206 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_207 ;
F_55 ( & V_192 -> V_198 , 0 ) ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_60 ( int V_190 )
{
struct V_208 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_209 ;
F_55 ( & V_192 -> V_198 , 0 ) ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_61 ( int V_190 )
{
struct V_210 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_211 ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_62 ( int V_190 )
{
struct V_212 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_213 ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_63 ( T_1 V_190 , int V_138 )
{
struct V_214 * V_192 ;
V_192 = F_21 ( sizeof *V_192 , V_87 ) ;
if ( ! V_192 )
return NULL ;
V_192 -> V_193 . V_13 = V_190 ;
V_192 -> V_193 . V_2 = V_215 ;
V_192 -> V_138 = V_138 ;
return & V_192 -> V_193 ;
}
static struct V_16 * F_64 ( T_1 V_190 , enum V_24 type , int V_37 ,
int V_216 )
{
struct V_16 * V_192 ;
switch ( type ) {
case V_26 :
V_192 = F_54 ( V_190 ) ;
break;
case V_29 :
V_192 = F_57 ( V_190 , V_216 ) ;
break;
case V_30 :
V_192 = F_56 ( V_190 , V_216 ) ;
break;
case V_33 :
V_192 = F_58 ( V_190 ) ;
break;
case V_27 :
V_192 = F_59 ( V_190 ) ;
break;
case V_28 :
V_192 = F_60 ( V_190 ) ;
break;
case V_31 :
F_65 ( L_19 ) ;
return NULL ;
case V_34 :
V_192 = F_61 ( V_190 ) ;
break;
case V_36 :
V_192 = F_62 ( V_190 ) ;
break;
case V_35 :
V_192 = F_63 ( V_190 , V_216 ) ;
break;
default:
return NULL ;
}
if ( V_192 )
V_192 -> V_186 = V_37 ;
return V_192 ;
}
static int F_66 ( struct V_5 * V_6 , int V_37 , T_1 V_217 , int V_39 ,
enum V_24 type , int V_216 )
{
int V_82 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_16 * * V_218 ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_11 * V_12 = & V_220 -> V_92 [ type ] ;
V_218 = F_21 ( V_39 * sizeof *V_218 , V_87 ) ;
if ( ! V_218 )
return - V_88 ;
for ( V_82 = 0 ; V_82 < V_39 ; ++ V_82 ) {
V_218 [ V_82 ] = F_64 ( V_217 + V_82 , type , V_37 , V_216 ) ;
if ( ! V_218 [ V_82 ] ) {
for ( -- V_82 ; V_82 >= 0 ; -- V_82 )
F_31 ( V_218 [ V_82 ] ) ;
F_31 ( V_218 ) ;
return - V_88 ;
}
}
F_49 ( F_50 ( V_6 ) ) ;
for ( V_82 = 0 ; V_82 < V_39 ; ++ V_82 ) {
if ( F_47 ( V_6 , V_217 + V_82 , type ) ) {
V_47 = - V_23 ;
goto V_221;
}
V_47 = F_5 ( V_12 , V_218 [ V_82 ] ) ;
if ( V_47 )
goto V_221;
F_67 ( & V_218 [ V_82 ] -> V_222 ,
& V_220 -> V_85 [ V_37 ] . V_90 [ type ] ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
F_31 ( V_218 ) ;
return 0 ;
V_221:
for ( -- V_82 ; V_82 >= V_217 ; -- V_82 )
F_68 ( & V_218 [ V_82 ] -> V_15 , V_12 ) ;
F_51 ( F_50 ( V_6 ) ) ;
for ( V_82 = 0 ; V_82 < V_39 ; ++ V_82 )
F_31 ( V_218 [ V_82 ] ) ;
F_31 ( V_218 ) ;
return V_47 ;
}
static int F_69 ( struct V_191 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_223 || F_70 ( & V_17 -> V_198 ) ||
! F_71 ( & V_17 -> V_196 ) ) {
F_65 ( L_20 ,
V_17 -> V_193 . V_2 , F_70 ( & V_17 -> V_198 ) ) ;
return - V_185 ;
} else if ( V_17 -> V_193 . V_2 != V_194 ) {
return - V_187 ;
}
return 0 ;
}
static int F_72 ( struct V_200 * V_17 , int V_199 )
{
if ( V_17 -> V_193 . V_2 == V_3 ||
F_70 ( & V_17 -> V_198 ) ) {
F_73 ( L_21 ,
V_224 , __LINE__ ,
F_1 ( V_17 -> V_193 . V_2 ) ,
F_70 ( & V_17 -> V_198 ) ) ;
return - V_185 ;
} else if ( V_17 -> V_193 . V_2 != V_4 )
return - V_187 ;
else if ( V_17 -> V_199 != V_199 )
return - V_48 ;
return 0 ;
}
static int F_74 ( struct V_202 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_225 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_203 )
return - V_187 ;
return 0 ;
}
static int F_75 ( struct V_204 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_225 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_203 )
return - V_187 ;
return 0 ;
}
static int F_76 ( struct V_210 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_226 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_211 )
return - V_187 ;
return 0 ;
}
static int F_77 ( struct V_212 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_227 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_213 )
return - V_187 ;
return 0 ;
}
static int F_78 ( struct V_214 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_228 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_215 )
return - V_187 ;
return 0 ;
}
static int F_79 ( struct V_206 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_229 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_207 )
return - V_187 ;
return 0 ;
}
static int F_80 ( struct V_208 * V_17 )
{
if ( V_17 -> V_193 . V_2 == V_230 )
return - V_185 ;
else if ( V_17 -> V_193 . V_2 != V_209 )
return - V_187 ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 , enum V_24 type , int V_216 )
{
switch ( type ) {
case V_26 :
return F_69 ( (struct V_191 * ) V_17 ) ;
case V_27 :
return F_79 ( (struct V_206 * ) V_17 ) ;
case V_28 :
return F_80 ( (struct V_208 * ) V_17 ) ;
case V_29 :
return F_74 ( (struct V_202 * ) V_17 ) ;
case V_30 :
return F_72 ( (struct V_200 * ) V_17 , V_216 ) ;
case V_31 :
return - V_231 ;
case V_33 :
return F_75 ( (struct V_204 * ) V_17 ) ;
case V_34 :
return F_76 ( (struct V_210 * ) V_17 ) ;
case V_36 :
return F_77 ( (struct V_212 * ) V_17 ) ;
case V_35 :
return F_78 ( (struct V_214 * ) V_17 ) ;
default:
return - V_48 ;
}
}
static int F_82 ( struct V_5 * V_6 , int V_37 , T_1 V_217 , int V_39 ,
enum V_24 type , int V_216 )
{
T_1 V_82 ;
int V_47 ;
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_182 ;
F_49 ( F_50 ( V_6 ) ) ;
for ( V_82 = V_217 ; V_82 < V_217 + V_39 ; ++ V_82 ) {
V_182 = F_3 ( & V_220 -> V_92 [ type ] , V_82 ) ;
if ( ! V_182 ) {
V_47 = - V_189 ;
goto V_62;
}
if ( V_182 -> V_186 != V_37 ) {
V_47 = - V_187 ;
goto V_62;
}
V_47 = F_81 ( V_182 , type , V_216 ) ;
if ( V_47 )
goto V_62;
}
for ( V_82 = V_217 ; V_82 < V_217 + V_39 ; ++ V_82 ) {
V_182 = F_3 ( & V_220 -> V_92 [ type ] , V_82 ) ;
F_68 ( & V_182 -> V_15 , & V_220 -> V_92 [ type ] ) ;
F_83 ( & V_182 -> V_222 ) ;
F_31 ( V_182 ) ;
}
V_47 = 0 ;
V_62:
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_84 ( struct V_5 * V_6 , int V_37 , int V_138 ,
enum V_232 V_2 , struct V_191 * * V_68 ,
int V_233 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_191 * V_182 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ V_26 ] , V_138 ) ;
if ( ! V_182 )
V_47 = - V_189 ;
else if ( V_182 -> V_193 . V_186 != V_37 )
V_47 = - V_187 ;
else {
switch ( V_2 ) {
case V_223 :
F_24 ( V_6 , L_22 ,
V_224 , V_182 -> V_193 . V_13 ) ;
V_47 = - V_185 ;
break;
case V_194 :
if ( V_182 -> V_193 . V_2 == V_234 && ! V_233 )
break;
F_24 ( V_6 , L_23 , V_182 -> V_193 . V_13 ) ;
V_47 = - V_48 ;
break;
case V_234 :
if ( ( V_182 -> V_193 . V_2 == V_194 && V_233 ) ||
V_182 -> V_193 . V_2 == V_235 )
break;
else {
F_24 ( V_6 , L_23 ,
V_182 -> V_193 . V_13 ) ;
V_47 = - V_48 ;
}
break;
case V_235 :
if ( V_182 -> V_193 . V_2 != V_234 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_182 -> V_193 . V_188 = V_182 -> V_193 . V_2 ;
V_182 -> V_193 . V_236 = V_2 ;
V_182 -> V_193 . V_2 = V_223 ;
if ( V_68 )
* V_68 = V_182 ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_85 ( struct V_5 * V_6 , int V_37 , int V_237 ,
enum V_238 V_2 , struct V_202 * * V_79 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_202 * V_182 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ V_29 ] , V_237 ) ;
if ( ! V_182 )
V_47 = - V_189 ;
else if ( V_182 -> V_193 . V_186 != V_37 )
V_47 = - V_187 ;
else {
switch ( V_2 ) {
case V_225 :
V_47 = - V_48 ;
break;
case V_203 :
if ( V_182 -> V_193 . V_2 != V_239 )
V_47 = - V_48 ;
break;
case V_239 :
if ( V_182 -> V_193 . V_2 != V_203 &&
V_182 -> V_193 . V_2 != V_240 )
V_47 = - V_48 ;
break;
case V_240 :
if ( V_182 -> V_193 . V_2 != V_239 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_182 -> V_193 . V_188 = V_182 -> V_193 . V_2 ;
V_182 -> V_193 . V_236 = V_2 ;
V_182 -> V_193 . V_2 = V_225 ;
if ( V_79 )
* V_79 = V_182 ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_86 ( struct V_5 * V_6 , int V_37 , int V_237 ,
enum V_241 V_2 , struct V_204 * * V_242 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_204 * V_182 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ V_33 ] , V_237 ) ;
if ( ! V_182 )
V_47 = - V_189 ;
else if ( V_182 -> V_193 . V_186 != V_37 )
V_47 = - V_187 ;
else {
switch ( V_2 ) {
case V_243 :
V_47 = - V_48 ;
break;
case V_205 :
if ( V_182 -> V_193 . V_2 != V_244 )
V_47 = - V_48 ;
break;
case V_244 :
if ( V_182 -> V_193 . V_2 != V_205 )
V_47 = - V_48 ;
break;
default:
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_182 -> V_193 . V_188 = V_182 -> V_193 . V_2 ;
V_182 -> V_193 . V_236 = V_2 ;
V_182 -> V_193 . V_2 = V_243 ;
if ( V_242 )
* V_242 = V_182 ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_87 ( struct V_5 * V_6 , int V_37 , int V_245 ,
enum V_246 V_2 , struct V_206 * * V_71 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_206 * V_182 ;
int V_47 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ V_27 ] , V_245 ) ;
if ( ! V_182 ) {
V_47 = - V_189 ;
} else if ( V_182 -> V_193 . V_186 != V_37 ) {
V_47 = - V_187 ;
} else if ( V_2 == V_207 ) {
if ( V_182 -> V_193 . V_2 != V_247 )
V_47 = - V_48 ;
else if ( F_70 ( & V_182 -> V_198 ) )
V_47 = - V_185 ;
else
V_47 = 0 ;
} else if ( V_2 != V_247 || V_182 -> V_193 . V_2 != V_207 ) {
V_47 = - V_48 ;
} else {
V_47 = 0 ;
}
if ( ! V_47 ) {
V_182 -> V_193 . V_188 = V_182 -> V_193 . V_2 ;
V_182 -> V_193 . V_236 = V_2 ;
V_182 -> V_193 . V_2 = V_229 ;
if ( V_71 )
* V_71 = V_182 ;
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_88 ( struct V_5 * V_6 , int V_37 , int V_237 ,
enum V_248 V_2 , struct V_208 * * V_74 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_208 * V_182 ;
int V_47 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ V_28 ] , V_237 ) ;
if ( ! V_182 ) {
V_47 = - V_189 ;
} else if ( V_182 -> V_193 . V_186 != V_37 ) {
V_47 = - V_187 ;
} else if ( V_2 == V_209 ) {
if ( V_182 -> V_193 . V_2 != V_249 )
V_47 = - V_48 ;
else if ( F_70 ( & V_182 -> V_198 ) )
V_47 = - V_185 ;
} else if ( V_2 != V_249 || V_182 -> V_193 . V_2 != V_209 ) {
V_47 = - V_48 ;
}
if ( ! V_47 ) {
V_182 -> V_193 . V_188 = V_182 -> V_193 . V_2 ;
V_182 -> V_193 . V_236 = V_2 ;
V_182 -> V_193 . V_2 = V_230 ;
if ( V_74 )
* V_74 = V_182 ;
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static void F_89 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_190 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_182 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ type ] , V_190 ) ;
if ( V_182 && ( V_182 -> V_186 == V_37 ) )
V_182 -> V_2 = V_182 -> V_188 ;
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_90 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_190 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_16 * V_182 ;
F_49 ( F_50 ( V_6 ) ) ;
V_182 = F_3 ( & V_220 -> V_92 [ type ] , V_190 ) ;
if ( V_182 && ( V_182 -> V_186 == V_37 ) )
V_182 -> V_2 = V_182 -> V_236 ;
F_51 ( F_50 ( V_6 ) ) ;
}
static int F_91 ( struct V_5 * V_6 , int V_37 , int V_138 )
{
return F_43 ( V_6 , V_138 ) &&
( F_92 ( V_6 ) || F_93 ( V_6 , V_37 , V_138 ) ) ;
}
static int F_94 ( struct V_5 * V_6 , int V_138 )
{
return V_138 < V_6 -> V_8 . V_250 [ V_251 ] ;
}
static int F_95 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_47 ;
int V_39 ;
int V_256 ;
int V_217 ;
int V_138 ;
T_2 V_127 ;
switch ( V_252 ) {
case V_257 :
V_39 = F_96 ( & V_254 ) & 0xffffff ;
V_127 = ( F_96 ( & V_254 ) >> 24 ) & V_6 -> V_8 . V_258 ;
V_256 = F_97 ( & V_254 ) ;
V_47 = F_9 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_98 ( V_6 , V_39 , V_256 , & V_217 , V_127 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
return V_47 ;
}
V_47 = F_66 ( V_6 , V_37 , V_217 , V_39 , V_26 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_99 ( V_6 , V_217 , V_39 ) ;
return V_47 ;
}
F_100 ( V_255 , V_217 ) ;
break;
case V_259 :
V_138 = F_96 ( & V_254 ) & 0x7fffff ;
if ( F_91 ( V_6 , V_37 , V_138 ) ) {
V_47 = F_66 ( V_6 , V_37 , V_138 , 1 , V_26 , 0 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_84 ( V_6 , V_37 , V_138 , V_234 ,
NULL , 1 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_94 ( V_6 , V_138 ) ) {
V_47 = F_101 ( V_6 , V_138 , V_87 ) ;
if ( V_47 ) {
F_89 ( V_6 , V_37 , V_26 , V_138 ) ;
return V_47 ;
}
}
F_90 ( V_6 , V_37 , V_26 , V_138 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_102 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_47 = - V_48 ;
int V_217 ;
int V_199 ;
if ( V_252 != V_260 )
return V_47 ;
V_199 = F_96 ( & V_254 ) ;
V_47 = F_9 ( V_6 , V_37 , V_30 , 1 << V_199 , 0 ) ;
if ( V_47 )
return V_47 ;
V_217 = F_103 ( V_6 , V_199 ) ;
if ( V_217 == - 1 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_199 , 0 ) ;
return - V_88 ;
}
V_47 = F_66 ( V_6 , V_37 , V_217 , 1 , V_30 , V_199 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_199 , 0 ) ;
F_104 ( V_6 , V_217 , V_199 ) ;
} else {
F_100 ( V_255 , V_217 ) ;
}
return V_47 ;
}
static int F_105 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_47 = - V_48 ;
int V_237 ;
int V_190 ;
struct V_202 * V_79 ;
switch ( V_252 ) {
case V_257 :
V_47 = F_9 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
if ( V_47 )
break;
V_237 = F_106 ( V_6 ) ;
if ( V_237 == - 1 ) {
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
break;
}
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_66 ( V_6 , V_37 , V_190 , 1 , V_29 , V_237 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_107 ( V_6 , V_237 ) ;
break;
}
F_100 ( V_255 , V_237 ) ;
break;
case V_259 :
V_237 = F_96 ( & V_254 ) ;
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_190 ,
V_239 , & V_79 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_108 ( V_6 , V_79 -> V_201 , V_87 ) ;
if ( V_47 ) {
F_89 ( V_6 , V_37 , V_29 , V_190 ) ;
return V_47 ;
}
F_90 ( V_6 , V_37 , V_29 , V_190 ) ;
break;
}
return V_47 ;
}
static int F_109 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_245 ;
int V_47 ;
switch ( V_252 ) {
case V_260 :
V_47 = F_9 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_110 ( V_6 , & V_245 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
break;
}
V_47 = F_66 ( V_6 , V_37 , V_245 , 1 , V_27 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_111 ( V_6 , V_245 ) ;
break;
}
F_100 ( V_255 , V_245 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_112 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_261 ;
int V_47 ;
switch ( V_252 ) {
case V_260 :
V_47 = F_9 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
if ( V_47 )
break;
V_47 = F_113 ( V_6 , & V_261 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
break;
}
V_47 = F_66 ( V_6 , V_37 , V_261 , 1 , V_28 , 0 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_114 ( V_6 , V_261 ) ;
break;
}
F_100 ( V_255 , V_261 ) ;
break;
default:
V_47 = - V_48 ;
}
return V_47 ;
}
static int F_115 ( struct V_5 * V_6 , int V_37 , int V_7 ,
T_2 V_262 , T_1 * V_263 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_265 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_31 ] ;
struct V_266 * V_17 , * V_267 ;
F_116 (res, tmp, mac_list, list) {
if ( V_17 -> V_262 == V_262 && V_17 -> V_7 == ( T_2 ) V_7 ) {
* V_263 = V_17 -> V_263 ;
return 0 ;
}
}
return - V_189 ;
}
static int F_117 ( struct V_5 * V_6 , int V_37 , T_1 V_263 , int V_7 , T_2 V_262 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_265 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_31 ] ;
struct V_266 * V_17 , * V_267 ;
F_116 (res, tmp, mac_list, list) {
if ( V_17 -> V_263 == V_263 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_198 ;
return 0 ;
}
}
if ( F_9 ( V_6 , V_37 , V_31 , 1 , V_7 ) )
return - V_48 ;
V_17 = F_21 ( sizeof *V_17 , V_87 ) ;
if ( ! V_17 ) {
F_13 ( V_6 , V_37 , V_31 , 1 , V_7 ) ;
return - V_88 ;
}
V_17 -> V_263 = V_263 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_262 = V_262 ;
V_17 -> V_198 = 1 ;
F_67 ( & V_17 -> V_222 ,
& V_220 -> V_85 [ V_37 ] . V_90 [ V_31 ] ) ;
return 0 ;
}
static void F_118 ( struct V_5 * V_6 , int V_37 , T_1 V_263 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_265 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_31 ] ;
struct V_266 * V_17 , * V_267 ;
F_116 (res, tmp, mac_list, list) {
if ( V_17 -> V_263 == V_263 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_198 ) {
F_83 ( & V_17 -> V_222 ) ;
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
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_265 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_31 ] ;
struct V_266 * V_17 , * V_267 ;
int V_82 ;
F_116 (res, tmp, mac_list, list) {
F_83 ( & V_17 -> V_222 ) ;
for ( V_82 = 0 ; V_82 < V_17 -> V_198 ; V_82 ++ )
F_120 ( V_6 , V_17 -> V_7 , V_17 -> V_263 ) ;
F_13 ( V_6 , V_37 , V_31 , 1 , V_17 -> V_7 ) ;
F_31 ( V_17 ) ;
}
}
static int F_121 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 , int V_268 )
{
int V_47 = - V_48 ;
int V_7 ;
T_1 V_263 ;
T_2 V_262 ;
if ( V_252 != V_260 )
return V_47 ;
V_7 = ! V_268 ? F_96 ( V_255 ) : V_268 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
V_263 = V_254 ;
V_47 = F_123 ( V_6 , V_7 , V_263 ) ;
if ( V_47 >= 0 ) {
V_262 = V_47 ;
F_100 ( V_255 , V_47 ) ;
V_47 = 0 ;
}
if ( ! V_47 ) {
V_47 = F_117 ( V_6 , V_37 , V_263 , V_7 , V_262 ) ;
if ( V_47 )
F_120 ( V_6 , V_7 , V_263 ) ;
}
return V_47 ;
}
static int F_124 ( struct V_5 * V_6 , int V_37 , T_4 V_269 ,
int V_7 , int V_169 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_270 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_32 ] ;
struct V_271 * V_17 , * V_267 ;
F_116 (res, tmp, vlan_list, list) {
if ( V_17 -> V_269 == V_269 && V_17 -> V_7 == ( T_2 ) V_7 ) {
++ V_17 -> V_198 ;
return 0 ;
}
}
if ( F_9 ( V_6 , V_37 , V_32 , 1 , V_7 ) )
return - V_48 ;
V_17 = F_21 ( sizeof( * V_17 ) , V_87 ) ;
if ( ! V_17 ) {
F_13 ( V_6 , V_37 , V_32 , 1 , V_7 ) ;
return - V_88 ;
}
V_17 -> V_269 = V_269 ;
V_17 -> V_7 = ( T_2 ) V_7 ;
V_17 -> V_169 = V_169 ;
V_17 -> V_198 = 1 ;
F_67 ( & V_17 -> V_222 ,
& V_220 -> V_85 [ V_37 ] . V_90 [ V_32 ] ) ;
return 0 ;
}
static void F_125 ( struct V_5 * V_6 , int V_37 , T_4 V_269 ,
int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_270 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_32 ] ;
struct V_271 * V_17 , * V_267 ;
F_116 (res, tmp, vlan_list, list) {
if ( V_17 -> V_269 == V_269 && V_17 -> V_7 == ( T_2 ) V_7 ) {
if ( ! -- V_17 -> V_198 ) {
F_83 ( & V_17 -> V_222 ) ;
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
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_270 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_32 ] ;
struct V_271 * V_17 , * V_267 ;
int V_82 ;
F_116 (res, tmp, vlan_list, list) {
F_83 ( & V_17 -> V_222 ) ;
for ( V_82 = 0 ; V_82 < V_17 -> V_198 ; V_82 ++ )
F_126 ( V_6 , V_17 -> V_7 , V_17 -> V_269 ) ;
F_13 ( V_6 , V_37 , V_32 , 1 , V_17 -> V_7 ) ;
F_31 ( V_17 ) ;
}
}
static int F_127 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 , int V_268 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_272 * V_273 = V_41 -> V_44 . V_45 . V_273 ;
int V_47 ;
T_4 V_269 ;
int V_169 ;
int V_7 ;
V_7 = ! V_268 ? F_96 ( V_255 ) : V_268 ;
if ( ! V_7 || V_252 != V_260 )
return - V_48 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
if ( ! V_268 && V_7 > 0 && V_7 <= V_6 -> V_8 . V_99 ) {
V_273 [ V_37 ] . V_274 = true ;
return 0 ;
}
V_269 = ( T_4 ) V_254 ;
V_47 = F_128 ( V_6 , V_7 , V_269 , & V_169 ) ;
if ( ! V_47 ) {
F_100 ( V_255 , ( T_3 ) V_169 ) ;
V_47 = F_124 ( V_6 , V_37 , V_269 , V_7 , V_169 ) ;
if ( V_47 )
F_126 ( V_6 , V_7 , V_269 ) ;
}
return V_47 ;
}
static int F_129 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
T_3 V_237 ;
int V_47 ;
if ( V_252 != V_257 )
return - V_48 ;
V_47 = F_9 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_130 ( V_6 , & V_237 ) ;
if ( V_47 ) {
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
V_47 = F_66 ( V_6 , V_37 , V_237 , 1 , V_34 , 0 ) ;
if ( V_47 ) {
F_131 ( V_6 , V_237 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
} else {
F_100 ( V_255 , V_237 ) ;
}
return V_47 ;
}
static int F_132 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
T_3 V_275 ;
int V_47 ;
if ( V_252 != V_257 )
return - V_48 ;
V_47 = F_133 ( V_6 , & V_275 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_66 ( V_6 , V_37 , V_275 , 1 , V_36 , 0 ) ;
if ( V_47 )
F_134 ( V_6 , V_275 ) ;
else
F_100 ( V_255 , V_275 ) ;
return V_47 ;
}
int F_135 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_280 = V_277 -> V_281 ;
switch ( V_277 -> V_282 & 0xFF ) {
case V_26 :
V_47 = F_95 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_30 :
V_47 = F_102 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_29 :
V_47 = F_105 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_27 :
V_47 = F_109 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_28 :
V_47 = F_112 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_31 :
V_47 = F_121 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ,
( V_277 -> V_282 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_127 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ,
( V_277 -> V_282 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_129 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_36 :
V_47 = F_132 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_136 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 )
{
int V_47 ;
int V_39 ;
int V_217 ;
int V_138 ;
switch ( V_252 ) {
case V_257 :
V_217 = F_96 ( & V_254 ) & 0x7fffff ;
V_39 = F_97 ( & V_254 ) ;
V_47 = F_82 ( V_6 , V_37 , V_217 , V_39 , V_26 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_26 , V_39 , 0 ) ;
F_99 ( V_6 , V_217 , V_39 ) ;
break;
case V_259 :
V_138 = F_96 ( & V_254 ) & 0x7fffff ;
V_47 = F_84 ( V_6 , V_37 , V_138 , V_194 ,
NULL , 0 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_94 ( V_6 , V_138 ) )
F_137 ( V_6 , V_138 ) ;
F_90 ( V_6 , V_37 , V_26 , V_138 ) ;
if ( F_91 ( V_6 , V_37 , V_138 ) )
V_47 = F_82 ( V_6 , V_37 , V_138 , 1 , V_26 , 0 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_138 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_47 = - V_48 ;
int V_217 ;
int V_199 ;
if ( V_252 != V_260 )
return V_47 ;
V_217 = F_96 ( & V_254 ) ;
V_199 = F_97 ( & V_254 ) ;
V_47 = F_82 ( V_6 , V_37 , V_217 , 1 , V_30 , V_199 ) ;
if ( ! V_47 ) {
F_13 ( V_6 , V_37 , V_30 , 1 << V_199 , 0 ) ;
F_104 ( V_6 , V_217 , V_199 ) ;
}
return V_47 ;
}
static int F_139 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 )
{
int V_47 = - V_48 ;
int V_237 ;
int V_190 ;
struct V_202 * V_79 ;
switch ( V_252 ) {
case V_257 :
V_237 = F_96 ( & V_254 ) ;
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_48 ( V_6 , V_37 , V_190 , V_29 , & V_79 ) ;
if ( V_47 )
break;
V_237 = V_79 -> V_201 ;
F_53 ( V_6 , V_37 , V_190 , V_29 ) ;
V_47 = F_82 ( V_6 , V_37 , V_190 , 1 , V_29 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_29 , 1 , 0 ) ;
F_107 ( V_6 , V_237 ) ;
break;
case V_259 :
V_237 = F_96 ( & V_254 ) ;
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_190 ,
V_203 , & V_79 ) ;
if ( V_47 )
return V_47 ;
F_140 ( V_6 , V_79 -> V_201 ) ;
F_90 ( V_6 , V_37 , V_29 , V_190 ) ;
return V_47 ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_141 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_245 ;
int V_47 ;
switch ( V_252 ) {
case V_260 :
V_245 = F_96 ( & V_254 ) ;
V_47 = F_82 ( V_6 , V_37 , V_245 , 1 , V_27 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_27 , 1 , 0 ) ;
F_111 ( V_6 , V_245 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_142 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_261 ;
int V_47 ;
switch ( V_252 ) {
case V_260 :
V_261 = F_96 ( & V_254 ) ;
V_47 = F_82 ( V_6 , V_37 , V_261 , 1 , V_28 , 0 ) ;
if ( V_47 )
break;
F_13 ( V_6 , V_37 , V_28 , 1 , 0 ) ;
F_114 ( V_6 , V_261 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_143 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 , int V_268 )
{
int V_7 ;
int V_47 = 0 ;
switch ( V_252 ) {
case V_260 :
V_7 = ! V_268 ? F_96 ( V_255 ) : V_268 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
F_118 ( V_6 , V_37 , V_254 , V_7 ) ;
F_120 ( V_6 , V_7 , V_254 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_144 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 , int V_7 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_272 * V_273 = V_41 -> V_44 . V_45 . V_273 ;
int V_47 = 0 ;
V_7 = F_122 (
V_6 , V_37 , V_7 ) ;
if ( V_7 < 0 )
return - V_48 ;
switch ( V_252 ) {
case V_260 :
if ( V_273 [ V_37 ] . V_274 )
return 0 ;
if ( ! V_7 )
return - V_48 ;
F_125 ( V_6 , V_37 , V_254 , V_7 ) ;
F_126 ( V_6 , V_7 , V_254 ) ;
break;
default:
V_47 = - V_48 ;
break;
}
return V_47 ;
}
static int F_145 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_237 ;
int V_47 ;
if ( V_252 != V_257 )
return - V_48 ;
V_237 = F_96 ( & V_254 ) ;
V_47 = F_82 ( V_6 , V_37 , V_237 , 1 , V_34 , 0 ) ;
if ( V_47 )
return V_47 ;
F_131 ( V_6 , V_237 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
return V_47 ;
}
static int F_146 ( struct V_5 * V_6 , int V_37 , int V_252 , int V_253 ,
T_1 V_254 , T_1 * V_255 )
{
int V_275 ;
int V_47 ;
if ( V_252 != V_257 )
return - V_48 ;
V_275 = F_96 ( & V_254 ) ;
V_47 = F_82 ( V_6 , V_37 , V_275 , 1 , V_36 , 0 ) ;
if ( V_47 )
return V_47 ;
F_134 ( V_6 , V_275 ) ;
return V_47 ;
}
int F_147 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 = - V_48 ;
int V_280 = V_277 -> V_281 ;
switch ( V_277 -> V_282 & 0xFF ) {
case V_26 :
V_47 = F_136 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 ) ;
break;
case V_30 :
V_47 = F_138 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_29 :
V_47 = F_139 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 ) ;
break;
case V_27 :
V_47 = F_141 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_28 :
V_47 = F_142 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_31 :
V_47 = F_143 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ,
( V_277 -> V_282 >> 8 ) & 0xFF ) ;
break;
case V_32 :
V_47 = F_144 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ,
( V_277 -> V_282 >> 8 ) & 0xFF ) ;
break;
case V_34 :
V_47 = F_145 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
break;
case V_36 :
V_47 = F_146 ( V_6 , V_37 , V_277 -> V_281 , V_280 ,
V_277 -> V_254 , & V_277 -> V_255 ) ;
default:
break;
}
return V_47 ;
}
static int F_148 ( struct V_283 * V_79 )
{
return ( F_40 ( V_79 -> V_127 ) >> 9 ) & 1 ;
}
static int F_149 ( struct V_283 * V_79 )
{
return ( int ) F_150 ( V_79 -> V_284 ) & 0xfffffff8 ;
}
static int F_151 ( struct V_283 * V_79 )
{
return F_40 ( V_79 -> V_285 ) ;
}
static T_3 F_152 ( struct V_283 * V_79 )
{
return F_40 ( V_79 -> V_286 ) & 0x00ffffff ;
}
static int F_153 ( struct V_283 * V_79 )
{
return F_40 ( V_79 -> V_286 ) & V_287 ;
}
static int F_154 ( struct V_283 * V_79 )
{
return F_40 ( V_79 -> V_127 ) & V_288 ;
}
static int F_155 ( struct V_283 * V_79 )
{
return F_40 ( V_79 -> V_127 ) & V_289 ;
}
static int F_156 ( struct V_121 * V_139 )
{
return F_40 ( V_139 -> V_290 ) & 0xfffffff8 ;
}
static int F_157 ( struct V_291 * V_292 )
{
return F_40 ( V_292 -> V_290 ) & 0xfffffff8 ;
}
static int F_158 ( struct V_121 * V_139 )
{
int V_293 = ( V_139 -> V_294 & 0x3f ) + 12 ;
int V_295 = ( V_139 -> V_296 >> 3 ) & 0xf ;
int V_297 = V_139 -> V_296 & 7 ;
int V_298 = ( V_139 -> V_299 >> 3 ) & 0xf ;
int V_300 = V_139 -> V_299 & 7 ;
int V_74 = ( F_40 ( V_139 -> V_261 ) >> 24 ) & 1 ;
int V_301 = ( F_40 ( V_139 -> V_127 ) >> 13 ) & 1 ;
T_3 V_126 = ( F_40 ( V_139 -> V_127 ) >> 16 ) & 0xff ;
int V_302 = ( V_126 == V_133 ) ? 1 : 0 ;
int V_303 ;
int V_304 ;
int V_305 ;
int V_306 ;
int V_307 = ( F_40 ( V_139 -> V_308 ) >> 6 ) & 0x3f ;
V_303 = 1 << ( V_295 + V_297 + 4 ) ;
V_304 = ( V_74 | V_301 | V_302 ) ? 0 : ( 1 << ( V_298 + V_300 + 4 ) ) ;
V_306 = V_303 + V_304 ;
V_305 =
F_159 ( ( V_306 + ( V_307 << 6 ) ) >>
V_293 ) ;
return V_305 ;
}
static int F_160 ( struct V_5 * V_6 , int V_37 , int V_309 ,
int V_310 , struct V_200 * V_77 )
{
int V_311 = V_77 -> V_193 . V_13 ;
int V_312 = ( 1 << V_77 -> V_199 ) ;
if ( V_309 < V_311 || V_309 + V_310 > V_311 + V_312 )
return - V_187 ;
return 0 ;
}
int F_161 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_237 = V_277 -> V_282 ;
struct V_200 * V_77 ;
struct V_202 * V_79 ;
int V_313 = F_149 ( V_115 -> V_117 ) / V_6 -> V_8 . V_314 ;
int V_315 ;
int V_190 ;
T_3 V_316 ;
int V_317 ;
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_190 , V_240 , & V_79 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_155 ( V_115 -> V_117 ) ) {
V_47 = - V_187 ;
goto V_318;
}
V_316 = F_152 ( V_115 -> V_117 ) ;
V_317 = ( V_316 >> 17 ) & 0x7f ;
if ( V_317 != 0 && -- V_317 != V_37 ) {
V_47 = - V_187 ;
goto V_318;
}
if ( F_153 ( V_115 -> V_117 ) ) {
if ( F_154 ( V_115 -> V_117 ) ) {
V_47 = - V_187 ;
goto V_318;
}
if ( ! F_155 ( V_115 -> V_117 ) ) {
V_47 = - V_187 ;
goto V_318;
}
}
V_315 = F_148 ( V_115 -> V_117 ) ;
if ( ! V_315 ) {
V_47 = F_48 ( V_6 , V_37 , V_313 , V_30 , & V_77 ) ;
if ( V_47 )
goto V_318;
V_47 = F_160 ( V_6 , V_37 , V_313 ,
F_151 ( V_115 -> V_117 ) , V_77 ) ;
if ( V_47 )
goto V_319;
V_79 -> V_77 = V_77 ;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_319;
if ( ! V_315 ) {
F_163 ( & V_77 -> V_198 ) ;
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
}
F_90 ( V_6 , V_37 , V_29 , V_190 ) ;
return 0 ;
V_319:
if ( ! V_315 )
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
V_318:
F_89 ( V_6 , V_37 , V_29 , V_190 ) ;
return V_47 ;
}
int F_164 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_237 = V_277 -> V_282 ;
struct V_202 * V_79 ;
int V_190 ;
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_85 ( V_6 , V_37 , V_190 , V_239 , & V_79 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_318;
if ( V_79 -> V_77 )
F_165 ( & V_79 -> V_77 -> V_198 ) ;
F_90 ( V_6 , V_37 , V_29 , V_190 ) ;
return 0 ;
V_318:
F_89 ( V_6 , V_37 , V_29 , V_190 ) ;
return V_47 ;
}
int F_166 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_237 = V_277 -> V_282 ;
struct V_202 * V_79 ;
int V_190 ;
V_190 = V_237 & F_46 ( V_6 ) ;
V_47 = F_48 ( V_6 , V_37 , V_190 , V_29 , & V_79 ) ;
if ( V_47 )
return V_47 ;
if ( V_79 -> V_193 . V_188 == V_239 ) {
struct V_283 * V_320 = F_167 (
& V_40 ( V_6 ) -> V_321 . V_322 ,
V_79 -> V_201 , NULL ) ;
if ( NULL == V_320 || NULL == V_278 -> V_117 ) {
V_47 = - V_48 ;
goto V_62;
}
memcpy ( V_278 -> V_117 , V_320 , sizeof( * V_320 ) ) ;
V_47 = 0 ;
} else if ( V_79 -> V_193 . V_188 == V_240 ) {
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
} else {
V_47 = - V_185 ;
goto V_62;
}
V_62:
F_53 ( V_6 , V_37 , V_190 , V_29 ) ;
return V_47 ;
}
static int F_168 ( struct V_121 * V_139 )
{
return F_40 ( V_139 -> V_323 ) & 0xffffff ;
}
static int F_169 ( struct V_121 * V_139 )
{
return F_40 ( V_139 -> V_324 ) & 0xffffff ;
}
static T_3 F_170 ( struct V_121 * V_139 )
{
return F_40 ( V_139 -> V_261 ) & 0x1ffffff ;
}
static void F_171 ( struct V_5 * V_6 , struct V_276 * V_277 ,
struct V_121 * V_325 )
{
T_3 V_138 = V_277 -> V_282 & 0xffffff ;
T_3 V_326 = 0 ;
if ( F_172 ( V_6 , V_138 , & V_326 ) )
return;
V_325 -> V_326 = F_44 ( V_326 ) ;
}
int F_173 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_138 = V_277 -> V_282 & 0x7fffff ;
struct V_200 * V_77 ;
struct V_191 * V_68 ;
struct V_121 * V_139 = V_115 -> V_117 + 8 ;
int V_313 = F_156 ( V_139 ) / V_6 -> V_8 . V_314 ;
int V_327 = F_158 ( V_139 ) ;
struct V_206 * V_328 ;
struct V_206 * V_329 ;
int V_330 = F_168 ( V_139 ) ;
int V_331 = F_169 ( V_139 ) ;
T_3 V_261 = F_170 ( V_139 ) & 0xffffff ;
int V_332 = ( F_170 ( V_139 ) >> 24 ) & 1 ;
struct V_208 * V_74 ;
int V_195 = F_40 ( V_139 -> V_195 ) & 0xffffff ;
V_47 = F_84 ( V_6 , V_37 , V_138 , V_235 , & V_68 , 0 ) ;
if ( V_47 )
return V_47 ;
V_68 -> V_195 = V_195 ;
V_68 -> V_130 = 0 ;
V_68 -> V_151 = 0 ;
V_68 -> V_160 = 0 ;
V_68 -> V_167 = 0 ;
V_68 -> V_333 = 0 ;
V_68 -> V_169 = 0 ;
V_68 -> V_174 = 0 ;
V_68 -> V_334 = F_40 ( V_139 -> V_127 ) ;
V_47 = F_48 ( V_6 , V_37 , V_313 , V_30 , & V_77 ) ;
if ( V_47 )
goto V_318;
V_47 = F_160 ( V_6 , V_37 , V_313 , V_327 , V_77 ) ;
if ( V_47 )
goto V_335;
V_47 = F_48 ( V_6 , V_37 , V_330 , V_27 , & V_328 ) ;
if ( V_47 )
goto V_335;
if ( V_331 != V_330 ) {
V_47 = F_48 ( V_6 , V_37 , V_331 , V_27 , & V_329 ) ;
if ( V_47 )
goto V_336;
} else
V_329 = V_328 ;
if ( V_332 ) {
V_47 = F_48 ( V_6 , V_37 , V_261 , V_28 , & V_74 ) ;
if ( V_47 )
goto V_337;
}
F_171 ( V_6 , V_277 , V_139 ) ;
F_38 ( V_6 , V_37 , V_115 ) ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_338;
F_163 ( & V_77 -> V_198 ) ;
V_68 -> V_77 = V_77 ;
F_163 ( & V_328 -> V_198 ) ;
V_68 -> V_328 = V_328 ;
F_163 ( & V_329 -> V_198 ) ;
V_68 -> V_329 = V_329 ;
if ( V_331 != V_330 )
F_53 ( V_6 , V_37 , V_331 , V_27 ) ;
if ( V_332 ) {
F_163 ( & V_74 -> V_198 ) ;
F_53 ( V_6 , V_37 , V_261 , V_28 ) ;
V_68 -> V_74 = V_74 ;
}
F_53 ( V_6 , V_37 , V_330 , V_27 ) ;
F_53 ( V_6 , V_37 , V_313 , V_30 ) ;
F_90 ( V_6 , V_37 , V_26 , V_138 ) ;
return 0 ;
V_338:
if ( V_332 )
F_53 ( V_6 , V_37 , V_261 , V_28 ) ;
V_337:
if ( V_331 != V_330 )
F_53 ( V_6 , V_37 , V_331 , V_27 ) ;
V_336:
F_53 ( V_6 , V_37 , V_330 , V_27 ) ;
V_335:
F_53 ( V_6 , V_37 , V_313 , V_30 ) ;
V_318:
F_89 ( V_6 , V_37 , V_26 , V_138 ) ;
return V_47 ;
}
static int F_174 ( struct V_339 * V_340 )
{
return F_40 ( V_340 -> V_290 ) & 0xfffffff8 ;
}
static int F_175 ( struct V_339 * V_340 )
{
int V_341 = V_340 -> V_341 & 0x1f ;
int V_293 = ( V_340 -> V_294 & 0x3f ) + 12 ;
if ( V_341 + 5 < V_293 )
return 1 ;
return 1 << ( V_341 + 5 - V_293 ) ;
}
static int F_176 ( struct V_342 * V_343 )
{
return F_40 ( V_343 -> V_290 ) & 0xfffffff8 ;
}
static int F_177 ( struct V_342 * V_343 )
{
int V_344 = ( F_40 ( V_343 -> V_345 ) >> 24 ) & 0x1f ;
int V_293 = ( V_343 -> V_294 & 0x3f ) + 12 ;
if ( V_344 + 5 < V_293 )
return 1 ;
return 1 << ( V_344 + 5 - V_293 ) ;
}
int F_178 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_346 = V_277 -> V_282 ;
int V_13 = ( V_37 << 8 ) | V_346 ;
struct V_339 * V_340 = V_115 -> V_117 ;
int V_313 = F_174 ( V_340 ) / V_6 -> V_8 . V_314 ;
int V_327 = F_175 ( V_340 ) ;
struct V_204 * V_242 ;
struct V_200 * V_77 ;
V_47 = F_66 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_86 ( V_6 , V_37 , V_13 , V_244 , & V_242 ) ;
if ( V_47 )
goto V_347;
V_47 = F_48 ( V_6 , V_37 , V_313 , V_30 , & V_77 ) ;
if ( V_47 )
goto V_348;
V_47 = F_160 ( V_6 , V_37 , V_313 , V_327 , V_77 ) ;
if ( V_47 )
goto V_349;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_349;
F_163 ( & V_77 -> V_198 ) ;
V_242 -> V_77 = V_77 ;
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_33 , V_13 ) ;
return 0 ;
V_349:
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
V_348:
F_89 ( V_6 , V_37 , V_33 , V_13 ) ;
V_347:
F_82 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return V_47 ;
}
int F_179 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
T_2 V_350 = V_277 -> V_281 ;
if ( V_350 != 1 )
return - V_187 ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
return V_47 ;
}
static int F_180 ( struct V_5 * V_6 , int V_37 , int V_309 ,
int V_351 , struct V_200 * * V_17 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_200 * V_77 ;
int V_47 = - V_48 ;
F_49 ( F_50 ( V_6 ) ) ;
F_181 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_160 ( V_6 , V_37 , V_309 , V_351 , V_77 ) ) {
* V_17 = V_77 ;
V_77 -> V_193 . V_188 = V_77 -> V_193 . V_2 ;
V_77 -> V_193 . V_2 = V_3 ;
V_47 = 0 ;
break;
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_47 ;
}
static int F_182 ( struct V_5 * V_6 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
enum V_352 V_353 , T_2 V_37 )
{
T_3 V_142 ;
T_3 V_138 ;
struct V_121 * V_122 ;
enum V_123 V_124 ;
int V_7 ;
int V_354 ;
V_122 = V_115 -> V_117 + 8 ;
V_142 = ( F_40 ( V_122 -> V_127 ) >> 16 ) & 0xff ;
V_124 = F_40 ( * ( V_125 * ) V_115 -> V_117 ) ;
if ( V_37 != F_15 ( V_6 ) )
V_122 -> V_308 &= ~ V_355 ;
switch ( V_142 ) {
case V_132 :
case V_133 :
case V_134 :
switch ( V_353 ) {
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
if ( V_37 != F_15 ( V_6 ) )
if ( V_124 & V_135 ) {
V_7 = ( V_122 -> V_129 . V_130 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_354 = F_183 ( V_6 , V_37 , V_7 ) ;
else
V_354 = 1 ;
if ( V_122 -> V_129 . V_131 >= V_354 )
return - V_48 ;
}
if ( V_124 & V_136 ) {
V_7 = ( V_122 -> V_137 . V_130 >> 6 & 1 ) + 1 ;
if ( V_6 -> V_8 . V_9 [ V_7 ] != V_10 )
V_354 = F_183 ( V_6 , V_37 , V_7 ) ;
else
V_354 = 1 ;
if ( V_122 -> V_137 . V_131 >= V_354 )
return - V_48 ;
}
break;
default:
break;
}
break;
case V_147 :
V_138 = V_277 -> V_282 & 0x7fffff ;
V_7 = ( V_122 -> V_129 . V_130 >> 6 & 1 ) + 1 ;
if ( V_353 == V_356 &&
V_37 != F_15 ( V_6 ) &&
F_43 ( V_6 , V_138 ) &&
! F_184 ( V_6 , V_37 , V_7 ) ) {
F_185 ( V_6 , L_24 ,
V_224 , V_37 , V_7 ) ;
return - V_187 ;
}
break;
default:
break;
}
return 0 ;
}
int F_186 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
struct V_361 V_77 ;
T_5 * V_362 = V_115 -> V_117 ;
T_1 * V_363 = ( T_1 * ) V_362 ;
int V_82 ;
struct V_200 * V_364 = NULL ;
int V_309 = F_150 ( V_362 [ 0 ] ) ;
int V_365 = V_277 -> V_282 ;
int V_47 ;
V_47 = F_180 ( V_6 , V_37 , V_309 , V_365 , & V_364 ) ;
if ( V_47 )
return V_47 ;
V_77 . V_366 = 0 ;
V_77 . V_199 = 0 ;
V_77 . V_293 = 0 ;
for ( V_82 = 0 ; V_82 < V_365 ; ++ V_82 )
V_363 [ V_82 + 2 ] = ( F_150 ( V_362 [ V_82 + 2 ] ) & ~ 1ULL ) ;
V_47 = F_187 ( V_6 , & V_77 , F_150 ( V_362 [ 0 ] ) , V_365 ,
( ( T_1 * ) V_362 + 2 ) ) ;
if ( V_364 )
F_53 ( V_6 , V_37 , V_364 -> V_193 . V_13 , V_30 ) ;
return V_47 ;
}
int F_188 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_346 = V_277 -> V_282 ;
int V_13 = V_346 | ( V_37 << 8 ) ;
struct V_204 * V_242 ;
int V_47 ;
V_47 = F_86 ( V_6 , V_37 , V_13 , V_205 , & V_242 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_242 -> V_77 -> V_193 . V_13 , V_30 , NULL ) ;
if ( V_47 )
goto V_318;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_319;
F_165 ( & V_242 -> V_77 -> V_198 ) ;
F_53 ( V_6 , V_37 , V_242 -> V_77 -> V_193 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_33 , V_13 ) ;
F_82 ( V_6 , V_37 , V_13 , 1 , V_33 , 0 ) ;
return 0 ;
V_319:
F_53 ( V_6 , V_37 , V_242 -> V_77 -> V_193 . V_13 , V_30 ) ;
V_318:
F_89 ( V_6 , V_37 , V_33 , V_13 ) ;
return V_47 ;
}
int F_189 ( struct V_5 * V_6 , int V_37 , struct V_367 * V_368 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_369 * V_370 ;
struct V_114 * V_371 ;
T_3 V_282 = 0 ;
int V_47 ;
int V_13 ;
struct V_204 * V_372 ;
if ( ! V_41 -> V_44 . V_45 . V_273 )
return - V_48 ;
if ( V_37 < 0 || V_37 > V_6 -> V_54 -> V_55 ||
V_37 == V_6 -> V_8 . V_112 ||
! V_41 -> V_44 . V_45 . V_273 [ V_37 ] . V_373 )
return 0 ;
V_370 = & V_41 -> V_44 . V_45 . V_273 [ V_37 ] . V_370 [ V_368 -> type ] ;
if ( V_370 -> V_346 < 0 )
return 0 ;
F_35 ( & V_41 -> V_44 . V_45 . V_374 [ V_37 ] ) ;
V_13 = ( V_37 << 8 ) | V_370 -> V_346 ;
V_47 = F_48 ( V_6 , V_37 , V_13 , V_33 , & V_372 ) ;
if ( V_47 )
goto V_375;
if ( V_372 -> V_193 . V_188 != V_244 ) {
V_47 = - V_48 ;
goto V_376;
}
V_371 = F_190 ( V_6 ) ;
if ( F_191 ( V_371 ) ) {
V_47 = F_192 ( V_371 ) ;
goto V_376;
}
if ( V_368 -> type == V_377 ) {
++ V_370 -> V_378 ;
V_368 -> V_379 . V_253 . V_378 = F_193 ( V_370 -> V_378 ) ;
}
memcpy ( V_371 -> V_117 , ( T_2 * ) V_368 , 28 ) ;
V_282 = ( V_37 & 0xff ) | ( ( V_370 -> V_346 & 0xff ) << 16 ) ;
V_47 = F_194 ( V_6 , V_371 -> V_380 , V_282 , 0 ,
V_381 , V_382 ,
V_383 ) ;
F_53 ( V_6 , V_37 , V_13 , V_33 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_374 [ V_37 ] ) ;
F_195 ( V_6 , V_371 ) ;
return V_47 ;
V_376:
F_53 ( V_6 , V_37 , V_13 , V_33 ) ;
V_375:
F_37 ( & V_41 -> V_44 . V_45 . V_374 [ V_37 ] ) ;
return V_47 ;
}
int F_196 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_346 = V_277 -> V_282 ;
int V_13 = V_346 | ( V_37 << 8 ) ;
struct V_204 * V_242 ;
int V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_13 , V_33 , & V_242 ) ;
if ( V_47 )
return V_47 ;
if ( V_242 -> V_193 . V_188 != V_244 ) {
V_47 = - V_48 ;
goto V_319;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_319:
F_53 ( V_6 , V_37 , V_13 , V_33 ) ;
return V_47 ;
}
int F_197 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_245 = V_277 -> V_282 ;
struct V_342 * V_343 = V_115 -> V_117 ;
int V_313 = F_176 ( V_343 ) / V_6 -> V_8 . V_314 ;
struct V_206 * V_71 ;
struct V_200 * V_77 ;
V_47 = F_87 ( V_6 , V_37 , V_245 , V_247 , & V_71 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_313 , V_30 , & V_77 ) ;
if ( V_47 )
goto V_348;
V_47 = F_160 ( V_6 , V_37 , V_313 , F_177 ( V_343 ) , V_77 ) ;
if ( V_47 )
goto V_349;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_349;
F_163 ( & V_77 -> V_198 ) ;
V_71 -> V_77 = V_77 ;
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_27 , V_245 ) ;
return 0 ;
V_349:
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
V_348:
F_89 ( V_6 , V_37 , V_27 , V_245 ) ;
return V_47 ;
}
int F_198 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_245 = V_277 -> V_282 ;
struct V_206 * V_71 ;
V_47 = F_87 ( V_6 , V_37 , V_245 , V_207 , & V_71 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_348;
F_165 ( & V_71 -> V_77 -> V_198 ) ;
F_90 ( V_6 , V_37 , V_27 , V_245 ) ;
return 0 ;
V_348:
F_89 ( V_6 , V_37 , V_27 , V_245 ) ;
return V_47 ;
}
int F_199 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_245 = V_277 -> V_282 ;
struct V_206 * V_71 ;
int V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_245 , V_27 , & V_71 ) ;
if ( V_47 )
return V_47 ;
if ( V_71 -> V_193 . V_188 != V_247 )
goto V_319;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_319:
F_53 ( V_6 , V_37 , V_245 , V_27 ) ;
return V_47 ;
}
static int F_200 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 ,
struct V_206 * V_71 )
{
int V_47 ;
struct V_200 * V_384 ;
struct V_200 * V_77 ;
struct V_342 * V_343 = V_115 -> V_117 ;
int V_313 = F_176 ( V_343 ) / V_6 -> V_8 . V_314 ;
V_47 = F_48 ( V_6 , V_37 , V_71 -> V_77 -> V_193 . V_13 , V_30 , & V_384 ) ;
if ( V_47 )
return V_47 ;
if ( V_384 != V_71 -> V_77 ) {
V_47 = - V_48 ;
goto V_319;
}
V_47 = F_48 ( V_6 , V_37 , V_313 , V_30 , & V_77 ) ;
if ( V_47 )
goto V_319;
V_47 = F_160 ( V_6 , V_37 , V_313 , F_177 ( V_343 ) , V_77 ) ;
if ( V_47 )
goto V_385;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_385;
F_165 ( & V_384 -> V_198 ) ;
F_53 ( V_6 , V_37 , V_384 -> V_193 . V_13 , V_30 ) ;
F_163 ( & V_77 -> V_198 ) ;
V_71 -> V_77 = V_77 ;
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
return 0 ;
V_385:
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
V_319:
F_53 ( V_6 , V_37 , V_384 -> V_193 . V_13 , V_30 ) ;
return V_47 ;
}
int F_201 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_245 = V_277 -> V_282 ;
struct V_206 * V_71 ;
int V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_245 , V_27 , & V_71 ) ;
if ( V_47 )
return V_47 ;
if ( V_71 -> V_193 . V_188 != V_247 )
goto V_319;
if ( V_277 -> V_281 == 0 ) {
V_47 = F_200 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 , V_71 ) ;
goto V_319;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_319:
F_53 ( V_6 , V_37 , V_245 , V_27 ) ;
return V_47 ;
}
static int F_202 ( struct V_291 * V_292 )
{
int V_386 = ( F_40 ( V_292 -> V_387 ) >> 24 ) & 0xf ;
int V_300 = V_292 -> V_388 & 7 ;
int V_293 = ( V_292 -> V_294 & 0x3f ) + 12 ;
if ( V_386 + V_300 + 4 < V_293 )
return 1 ;
return 1 << ( V_386 + V_300 + 4 - V_293 ) ;
}
int F_203 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_261 = V_277 -> V_282 ;
struct V_200 * V_77 ;
struct V_208 * V_74 ;
struct V_291 * V_292 = V_115 -> V_117 ;
int V_313 = F_157 ( V_292 ) / V_6 -> V_8 . V_314 ;
if ( V_261 != ( F_40 ( V_292 -> V_387 ) & 0xffffff ) )
return - V_48 ;
V_47 = F_88 ( V_6 , V_37 , V_261 , V_249 , & V_74 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_313 , V_30 , & V_77 ) ;
if ( V_47 )
goto V_318;
V_47 = F_160 ( V_6 , V_37 , V_313 , F_202 ( V_292 ) ,
V_77 ) ;
if ( V_47 )
goto V_335;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_335;
F_163 ( & V_77 -> V_198 ) ;
V_74 -> V_77 = V_77 ;
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
F_90 ( V_6 , V_37 , V_28 , V_261 ) ;
return 0 ;
V_335:
F_53 ( V_6 , V_37 , V_77 -> V_193 . V_13 , V_30 ) ;
V_318:
F_89 ( V_6 , V_37 , V_28 , V_261 ) ;
return V_47 ;
}
int F_204 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_261 = V_277 -> V_282 ;
struct V_208 * V_74 ;
V_47 = F_88 ( V_6 , V_37 , V_261 , V_209 , & V_74 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_318;
F_165 ( & V_74 -> V_77 -> V_198 ) ;
if ( V_74 -> V_71 )
F_165 ( & V_74 -> V_71 -> V_198 ) ;
F_90 ( V_6 , V_37 , V_28 , V_261 ) ;
return 0 ;
V_318:
F_89 ( V_6 , V_37 , V_28 , V_261 ) ;
return V_47 ;
}
int F_205 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_261 = V_277 -> V_282 ;
struct V_208 * V_74 ;
V_47 = F_48 ( V_6 , V_37 , V_261 , V_28 , & V_74 ) ;
if ( V_47 )
return V_47 ;
if ( V_74 -> V_193 . V_188 != V_249 ) {
V_47 = - V_185 ;
goto V_62;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_62:
F_53 ( V_6 , V_37 , V_261 , V_28 ) ;
return V_47 ;
}
int F_206 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_261 = V_277 -> V_282 ;
struct V_208 * V_74 ;
V_47 = F_48 ( V_6 , V_37 , V_261 , V_28 , & V_74 ) ;
if ( V_47 )
return V_47 ;
if ( V_74 -> V_193 . V_188 != V_249 ) {
V_47 = - V_185 ;
goto V_62;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_62:
F_53 ( V_6 , V_37 , V_261 , V_28 ) ;
return V_47 ;
}
int F_207 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_138 = V_277 -> V_282 & 0x7fffff ;
struct V_191 * V_68 ;
V_47 = F_48 ( V_6 , V_37 , V_138 , V_26 , & V_68 ) ;
if ( V_47 )
return V_47 ;
if ( V_68 -> V_193 . V_188 != V_235 ) {
V_47 = - V_185 ;
goto V_62;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_62:
F_53 ( V_6 , V_37 , V_138 , V_26 ) ;
return V_47 ;
}
int F_208 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
struct V_121 * V_325 = V_115 -> V_117 + 8 ;
F_171 ( V_6 , V_277 , V_325 ) ;
F_38 ( V_6 , V_37 , V_115 ) ;
return F_207 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
}
static int F_209 ( struct V_5 * V_6 , int V_37 ,
struct V_121 * V_139 ,
struct V_114 * V_115 )
{
enum V_123 V_124 = F_40 ( * ( V_125 * ) V_115 -> V_117 ) ;
T_2 V_389 ;
int V_7 = F_122 (
V_6 , V_37 , ( V_139 -> V_129 . V_130 >> 6 & 1 ) + 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_389 = ( V_139 -> V_129 . V_130 & ~ ( 1 << 6 ) ) |
( ( V_7 & 1 ) << 6 ) ;
if ( V_124 & V_135 ||
F_2 ( V_6 , V_7 + 1 ) ) {
V_139 -> V_129 . V_130 = V_389 ;
}
if ( V_124 & V_136 ) {
V_7 = F_122 (
V_6 , V_37 , ( V_139 -> V_137 . V_130 >> 6 & 1 )
+ 1 ) - 1 ;
if ( V_7 < 0 )
return - V_48 ;
V_139 -> V_137 . V_130 =
( V_139 -> V_137 . V_130 & ~ ( 1 << 6 ) ) |
( V_7 & 1 ) << 6 ;
}
return 0 ;
}
static int F_210 ( struct V_5 * V_6 , int V_37 ,
struct V_121 * V_139 ,
struct V_114 * V_115 )
{
T_1 V_263 ;
int V_7 ;
T_3 V_126 = ( F_40 ( V_139 -> V_127 ) >> 16 ) & 0xff ;
T_2 V_116 = * ( T_2 * ) ( V_115 -> V_117 + 64 ) ;
T_2 V_390 ;
V_7 = ( V_116 >> 6 & 1 ) + 1 ;
if ( F_2 ( V_6 , V_7 ) && ( V_126 != V_147 ) ) {
V_390 = V_139 -> V_129 . V_180 & 0x7f ;
if ( F_115 ( V_6 , V_37 , V_7 , V_390 , & V_263 ) )
return - V_189 ;
}
return 0 ;
}
int F_211 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
struct V_121 * V_139 = V_115 -> V_117 + 8 ;
int V_138 = V_277 -> V_282 & 0x7fffff ;
struct V_191 * V_68 ;
T_2 V_391 ;
V_125 V_392 = V_139 -> V_151 ;
T_2 V_393 = V_139 -> V_129 . V_160 ;
T_2 V_394 = V_139 -> V_129 . V_167 ;
T_2 V_395 = V_139 -> V_129 . V_171 ;
T_2 V_396 = V_139 -> V_129 . V_169 ;
T_2 V_397 = V_139 -> V_129 . V_174 ;
V_47 = F_209 ( V_6 , V_37 , V_139 , V_115 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_277 , V_115 , V_356 , V_37 ) ;
if ( V_47 )
return V_47 ;
if ( F_210 ( V_6 , V_37 , V_139 , V_115 ) )
return - V_48 ;
F_38 ( V_6 , V_37 , V_115 ) ;
F_39 ( V_6 , V_115 , ( T_2 ) V_37 ) ;
F_171 ( V_6 , V_277 , V_139 ) ;
V_391 = V_139 -> V_129 . V_130 ;
V_47 = F_42 ( V_6 , V_115 , V_37 , V_138 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_48 ( V_6 , V_37 , V_138 , V_26 , & V_68 ) ;
if ( V_47 )
return V_47 ;
if ( V_68 -> V_193 . V_188 != V_235 ) {
V_47 = - V_185 ;
goto V_62;
}
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
V_62:
if ( ! V_47 ) {
V_68 -> V_130 = V_391 ;
V_68 -> V_151 = V_392 ;
V_68 -> V_160 = V_393 ;
V_68 -> V_167 = V_394 ;
V_68 -> V_333 = V_395 ;
V_68 -> V_169 = V_396 ;
V_68 -> V_174 = V_397 ;
}
F_53 ( V_6 , V_37 , V_138 , V_26 ) ;
return V_47 ;
}
int F_212 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
struct V_121 * V_325 = V_115 -> V_117 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_325 , V_115 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_277 , V_115 , V_357 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_38 ( V_6 , V_37 , V_115 ) ;
F_39 ( V_6 , V_115 , ( T_2 ) V_37 ) ;
F_171 ( V_6 , V_277 , V_325 ) ;
return F_207 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
}
int F_213 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
struct V_121 * V_325 = V_115 -> V_117 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_325 , V_115 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_277 , V_115 , V_358 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_38 ( V_6 , V_37 , V_115 ) ;
F_39 ( V_6 , V_115 , ( T_2 ) V_37 ) ;
F_171 ( V_6 , V_277 , V_325 ) ;
return F_207 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
}
int F_214 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
struct V_121 * V_325 = V_115 -> V_117 + 8 ;
int V_47 = F_209 ( V_6 , V_37 , V_325 , V_115 ) ;
if ( V_47 )
return V_47 ;
F_171 ( V_6 , V_277 , V_325 ) ;
return F_207 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
}
int F_215 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
struct V_121 * V_325 = V_115 -> V_117 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_325 , V_115 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_277 , V_115 , V_359 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_171 ( V_6 , V_277 , V_325 ) ;
F_39 ( V_6 , V_115 , ( T_2 ) V_37 ) ;
F_38 ( V_6 , V_37 , V_115 ) ;
return F_207 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
}
int F_216 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
struct V_121 * V_325 = V_115 -> V_117 + 8 ;
V_47 = F_209 ( V_6 , V_37 , V_325 , V_115 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_182 ( V_6 , V_277 , V_115 , V_360 , V_37 ) ;
if ( V_47 )
return V_47 ;
F_171 ( V_6 , V_277 , V_325 ) ;
F_39 ( V_6 , V_115 , ( T_2 ) V_37 ) ;
F_38 ( V_6 , V_37 , V_115 ) ;
return F_207 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
}
int F_217 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_138 = V_277 -> V_282 & 0x7fffff ;
struct V_191 * V_68 ;
V_47 = F_84 ( V_6 , V_37 , V_138 , V_234 , & V_68 , 0 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
if ( V_47 )
goto V_318;
F_165 ( & V_68 -> V_77 -> V_198 ) ;
F_165 ( & V_68 -> V_328 -> V_198 ) ;
F_165 ( & V_68 -> V_329 -> V_198 ) ;
if ( V_68 -> V_74 )
F_165 ( & V_68 -> V_74 -> V_198 ) ;
F_90 ( V_6 , V_37 , V_26 , V_138 ) ;
return 0 ;
V_318:
F_89 ( V_6 , V_37 , V_26 , V_138 ) ;
return V_47 ;
}
static struct V_398 * F_218 ( struct V_5 * V_6 , int V_37 ,
struct V_191 * V_399 , T_2 * V_400 )
{
struct V_398 * V_17 ;
F_181 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_17 -> V_400 , V_400 , 16 ) )
return V_17 ;
}
return NULL ;
}
static int F_219 ( struct V_5 * V_6 , int V_37 , struct V_191 * V_399 ,
T_2 * V_400 , enum V_401 V_402 ,
enum V_403 V_404 , T_1 V_405 )
{
struct V_398 * V_17 ;
int V_47 ;
V_17 = F_21 ( sizeof *V_17 , V_87 ) ;
if ( ! V_17 )
return - V_88 ;
F_49 ( & V_399 -> V_197 ) ;
if ( F_218 ( V_6 , V_37 , V_399 , V_400 ) ) {
F_31 ( V_17 ) ;
V_47 = - V_23 ;
} else {
memcpy ( V_17 -> V_400 , V_400 , 16 ) ;
V_17 -> V_402 = V_402 ;
V_17 -> V_404 = V_404 ;
V_17 -> V_405 = V_405 ;
F_67 ( & V_17 -> V_222 , & V_399 -> V_196 ) ;
V_47 = 0 ;
}
F_51 ( & V_399 -> V_197 ) ;
return V_47 ;
}
static int F_220 ( struct V_5 * V_6 , int V_37 , struct V_191 * V_399 ,
T_2 * V_400 , enum V_401 V_402 ,
enum V_403 V_404 , T_1 * V_405 )
{
struct V_398 * V_17 ;
int V_47 ;
F_49 ( & V_399 -> V_197 ) ;
V_17 = F_218 ( V_6 , V_37 , V_399 , V_400 ) ;
if ( ! V_17 || V_17 -> V_402 != V_402 || V_17 -> V_404 != V_404 )
V_47 = - V_48 ;
else {
* V_405 = V_17 -> V_405 ;
F_83 ( & V_17 -> V_222 ) ;
F_31 ( V_17 ) ;
V_47 = 0 ;
}
F_51 ( & V_399 -> V_197 ) ;
return V_47 ;
}
static int F_221 ( struct V_5 * V_6 , int V_37 , struct V_406 * V_68 ,
T_2 V_400 [ 16 ] , int V_407 , enum V_401 V_402 ,
enum V_403 type , T_1 * V_405 )
{
switch ( V_6 -> V_8 . V_408 ) {
case V_409 : {
int V_7 = F_122 ( V_6 , V_37 , V_400 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
return F_222 ( V_6 , V_68 , V_400 , V_7 ,
V_407 , V_402 ,
V_405 ) ;
}
case V_410 :
if ( V_402 == V_411 ) {
int V_7 = F_122 ( V_6 , V_37 , V_400 [ 5 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_400 [ 5 ] = V_7 ;
}
return F_223 ( V_6 , V_68 , V_400 ,
V_407 , V_402 , type ) ;
default:
return - V_48 ;
}
}
static int F_224 ( struct V_5 * V_6 , struct V_406 * V_68 ,
T_2 V_400 [ 16 ] , enum V_401 V_402 ,
enum V_403 type , T_1 V_405 )
{
switch ( V_6 -> V_8 . V_408 ) {
case V_409 :
return F_225 ( V_6 , V_405 ) ;
case V_410 :
return F_226 ( V_6 , V_68 , V_400 , V_402 , type ) ;
default:
return - V_48 ;
}
}
static int F_227 ( struct V_5 * V_6 , int V_37 ,
T_2 * V_400 , enum V_401 V_402 )
{
int V_412 ;
if ( V_402 != V_411 )
return 0 ;
if ( V_6 -> V_8 . V_408 == V_410 ||
V_6 -> V_8 . V_408 == V_409 ) {
V_412 = F_122 ( V_6 , V_37 , V_400 [ 5 ] ) ;
if ( V_412 < 0 )
return - V_48 ;
V_400 [ 5 ] = V_412 ;
}
return 0 ;
}
int F_228 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
struct V_406 V_68 ;
T_2 * V_400 = V_115 -> V_117 ;
enum V_401 V_402 = ( V_277 -> V_282 >> 28 ) & 0x7 ;
int V_47 ;
int V_138 ;
struct V_191 * V_399 ;
T_1 V_405 = 0 ;
int V_413 = V_277 -> V_281 ;
int V_407 = V_277 -> V_282 >> 31 ;
T_2 V_414 = 2 ;
enum V_403 type = ( V_400 [ 7 ] & V_414 ) >> 1 ;
V_138 = V_277 -> V_282 & 0xffffff ;
V_47 = F_48 ( V_6 , V_37 , V_138 , V_26 , & V_399 ) ;
if ( V_47 )
return V_47 ;
V_68 . V_138 = V_138 ;
if ( V_413 ) {
V_47 = F_221 ( V_6 , V_37 , & V_68 , V_400 , V_407 , V_402 ,
type , & V_405 ) ;
if ( V_47 ) {
F_65 ( L_25 , V_138 ) ;
goto V_319;
}
V_47 = F_219 ( V_6 , V_37 , V_399 , V_400 , V_402 , type , V_405 ) ;
if ( V_47 )
goto V_415;
} else {
V_47 = F_227 ( V_6 , V_37 , V_400 , V_402 ) ;
if ( V_47 )
goto V_319;
V_47 = F_220 ( V_6 , V_37 , V_399 , V_400 , V_402 , type , & V_405 ) ;
if ( V_47 )
goto V_319;
V_47 = F_224 ( V_6 , & V_68 , V_400 , V_402 , type , V_405 ) ;
if ( V_47 )
F_65 ( L_26 ,
V_138 , V_405 ) ;
}
F_53 ( V_6 , V_37 , V_138 , V_26 ) ;
return V_47 ;
V_415:
F_224 ( V_6 , & V_68 , V_400 , V_402 , type , V_405 ) ;
V_319:
F_53 ( V_6 , V_37 , V_138 , V_26 ) ;
return V_47 ;
}
static int F_229 ( int V_37 , struct V_416 * V_417 ,
struct V_264 * V_418 )
{
struct V_266 * V_17 , * V_267 ;
T_5 V_419 ;
if ( ! F_230 ( V_417 -> V_420 . V_421 ) &&
! F_231 ( V_417 -> V_420 . V_421 ) ) {
F_116 (res, tmp, rlist, list) {
V_419 = F_232 ( V_17 -> V_263 << 16 ) ;
if ( F_233 ( ( T_2 * ) & V_419 , V_417 -> V_420 . V_421 ) )
return 0 ;
}
F_65 ( L_27 ,
V_417 -> V_420 . V_421 , V_37 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_234 ( struct V_5 * V_6 , int V_37 ,
struct V_114 * V_115 ,
struct V_264 * V_418 , int V_422 )
{
struct V_266 * V_17 , * V_267 ;
T_2 V_7 ;
struct V_423 * V_424 ;
struct V_425 * V_417 ;
struct V_426 * V_427 ;
struct V_428 * V_429 ;
T_5 V_419 = 0 ;
T_5 V_430 = F_232 ( V_431 << 16 ) ;
V_424 = (struct V_423 * ) V_115 -> V_117 ;
V_7 = V_424 -> V_7 ;
V_417 = (struct V_425 * ) ( V_424 + 1 ) ;
switch ( V_422 ) {
case V_432 :
V_427 =
(struct V_426 * ) ( V_417 + 1 ) ;
memmove ( V_427 , V_417 ,
sizeof( * V_427 ) + sizeof( * V_429 ) ) ;
break;
case V_433 :
case V_434 :
V_429 = (struct V_428 * )
( V_417 + 1 ) ;
memmove ( V_429 , V_417 , sizeof( * V_429 ) ) ;
break;
default:
return - V_48 ;
}
F_116 (res, tmp, rlist, list) {
if ( V_7 == V_17 -> V_7 ) {
V_419 = F_232 ( V_17 -> V_263 << 16 ) ;
break;
}
}
if ( ! V_419 ) {
F_65 ( L_28 ,
V_7 ) ;
return - V_48 ;
}
memset ( V_417 , 0 , sizeof( * V_417 ) ) ;
V_417 -> V_310 = sizeof( * V_417 ) >> 2 ;
V_417 -> V_190 = F_193 ( V_435 [ V_436 ] ) ;
memcpy ( V_417 -> V_421 , & V_419 , V_437 ) ;
memcpy ( V_417 -> V_438 , & V_430 , V_437 ) ;
return 0 ;
}
int F_235 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_439 )
{
int V_47 ;
T_3 V_138 = V_277 -> V_282 & 0xffffff ;
struct V_191 * V_399 ;
T_1 V_263 ;
unsigned V_7 ;
T_1 V_440 ;
struct V_441 * V_253 ;
int V_262 ;
V_253 = (struct V_441 * ) V_115 -> V_117 ;
V_440 = F_150 ( V_253 -> V_442 ) ;
if ( V_253 -> V_443 || V_253 -> V_444 ||
( V_440 & ~ V_445 ) )
return - V_187 ;
V_47 = F_48 ( V_6 , V_37 , V_138 , V_26 , & V_399 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_29 , V_138 , V_37 ) ;
return V_47 ;
}
V_7 = ( V_399 -> V_130 >> 6 & 1 ) + 1 ;
if ( V_440 & ( 1ULL << V_446 ) ) {
V_262 = V_253 -> V_447 . V_129 . V_180 ;
V_47 = F_115 ( V_6 , V_37 , V_7 ,
V_262 , & V_263 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_30 ,
V_138 , V_262 ) ;
goto V_448;
}
}
V_47 = F_194 ( V_6 , V_115 -> V_380 ,
V_277 -> V_282 , 0 ,
V_449 , V_450 ,
V_383 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_31 , V_138 ) ;
goto V_448;
}
V_448:
F_53 ( V_6 , V_37 , V_138 , V_26 ) ;
return V_47 ;
}
int F_236 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_418 = & V_220 -> V_85 [ V_37 ] . V_90 [ V_31 ] ;
int V_47 ;
int V_138 ;
struct V_191 * V_399 ;
struct V_423 * V_424 ;
struct V_416 * V_451 ;
int V_422 ;
if ( V_6 -> V_8 . V_408 !=
V_409 )
return - V_452 ;
V_424 = (struct V_423 * ) V_115 -> V_117 ;
V_424 -> V_7 = F_122 ( V_6 , V_37 , V_424 -> V_7 ) ;
if ( V_424 -> V_7 <= 0 )
return - V_48 ;
V_138 = F_40 ( V_424 -> V_138 ) & 0xffffff ;
V_47 = F_48 ( V_6 , V_37 , V_138 , V_26 , & V_399 ) ;
if ( V_47 ) {
F_65 ( L_32 , V_138 ) ;
return V_47 ;
}
V_451 = (struct V_416 * ) ( V_424 + 1 ) ;
V_422 = F_237 ( F_238 ( V_451 -> V_190 ) ) ;
switch ( V_422 ) {
case V_436 :
if ( F_229 ( V_37 , V_451 , V_418 ) ) {
V_47 = - V_48 ;
goto V_453;
}
break;
case V_454 :
break;
case V_432 :
case V_433 :
case V_434 :
F_239 ( L_33 ) ;
if ( F_234 ( V_6 , V_37 , V_115 , V_418 , V_422 ) ) {
V_47 = - V_48 ;
goto V_453;
}
V_277 -> V_282 +=
sizeof( struct V_425 ) >> 2 ;
break;
default:
F_65 ( L_34 ) ;
V_47 = - V_48 ;
goto V_453;
}
V_47 = F_240 ( V_6 , V_115 -> V_380 , & V_277 -> V_255 ,
V_277 -> V_282 , 0 ,
V_455 , V_450 ,
V_383 ) ;
if ( V_47 )
goto V_453;
V_47 = F_66 ( V_6 , V_37 , V_277 -> V_255 , 1 , V_35 , V_138 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_35 ) ;
F_194 ( V_6 , V_277 -> V_255 , 0 , 0 ,
V_456 , V_450 ,
V_383 ) ;
goto V_453;
}
F_163 ( & V_399 -> V_198 ) ;
V_453:
F_53 ( V_6 , V_37 , V_138 , V_26 ) ;
return V_47 ;
}
int F_241 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
struct V_191 * V_399 ;
struct V_214 * V_457 ;
if ( V_6 -> V_8 . V_408 !=
V_409 )
return - V_452 ;
V_47 = F_48 ( V_6 , V_37 , V_277 -> V_254 , V_35 , & V_457 ) ;
if ( V_47 )
return V_47 ;
F_53 ( V_6 , V_37 , V_277 -> V_254 , V_35 ) ;
V_47 = F_48 ( V_6 , V_37 , V_457 -> V_138 , V_26 , & V_399 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_82 ( V_6 , V_37 , V_277 -> V_254 , 1 , V_35 , 0 ) ;
if ( V_47 ) {
F_185 ( V_6 , L_36 ) ;
goto V_62;
}
V_47 = F_194 ( V_6 , V_277 -> V_254 , 0 , 0 ,
V_456 , V_450 ,
V_383 ) ;
if ( ! V_47 )
F_165 ( & V_399 -> V_198 ) ;
V_62:
F_53 ( V_6 , V_37 , V_457 -> V_138 , V_26 ) ;
return V_47 ;
}
int F_242 ( struct V_5 * V_6 , int V_37 ,
struct V_276 * V_277 ,
struct V_114 * V_115 ,
struct V_114 * V_278 ,
struct V_279 * V_253 )
{
int V_47 ;
int V_237 = V_277 -> V_282 & 0xffff ;
V_47 = F_48 ( V_6 , V_37 , V_237 , V_34 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_162 ( V_6 , V_37 , V_277 , V_115 , V_278 , V_253 ) ;
F_53 ( V_6 , V_37 , V_237 , V_34 ) ;
return V_47 ;
}
static void F_243 ( struct V_5 * V_6 , int V_37 , struct V_191 * V_399 )
{
struct V_398 * V_458 ;
struct V_398 * V_267 ;
struct V_406 V_68 ;
F_116 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_6 -> V_8 . V_408 ) {
case V_409 :
F_225 ( V_6 , V_458 -> V_405 ) ;
break;
case V_410 :
V_68 . V_138 = V_399 -> V_195 ;
( void ) F_226 ( V_6 , & V_68 , V_458 -> V_400 ,
V_458 -> V_402 , V_458 -> V_404 ) ;
break;
}
F_83 ( & V_458 -> V_222 ) ;
F_31 ( V_458 ) ;
}
}
static int F_244 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type , int V_459 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_418 = & V_220 -> V_85 [ V_37 ] . V_90 [ type ] ;
struct V_16 * V_182 ;
struct V_16 * V_267 ;
int V_460 ;
V_460 = 0 ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (r, tmp, rlist, list) {
if ( V_182 -> V_186 == V_37 ) {
if ( ! V_182 -> V_461 ) {
if ( V_182 -> V_2 == V_184 ) {
if ( V_459 )
F_24 ( V_6 ,
L_37 ,
F_8 ( type ) ,
V_182 -> V_13 ) ;
++ V_460 ;
} else {
V_182 -> V_188 = V_182 -> V_2 ;
V_182 -> V_2 = V_184 ;
V_182 -> V_461 = 1 ;
}
}
}
}
F_51 ( F_50 ( V_6 ) ) ;
return V_460 ;
}
static int F_245 ( struct V_5 * V_6 , int V_37 ,
enum V_24 type )
{
unsigned long V_462 ;
int V_460 ;
V_462 = V_463 ;
do {
V_460 = F_244 ( V_6 , V_37 , type , 0 ) ;
if ( F_246 ( V_463 , V_462 + 5 * V_464 ) )
break;
if ( V_460 )
F_247 () ;
} while ( V_460 );
if ( V_460 )
V_460 = F_244 ( V_6 , V_37 , type , 1 ) ;
return V_460 ;
}
static void F_248 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_465 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_26 ] ;
struct V_191 * V_68 ;
struct V_191 * V_267 ;
int V_2 ;
T_1 V_254 ;
int V_138 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_26 ) ;
if ( V_47 )
F_11 ( V_6 , L_38 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (qp, tmp, qp_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_68 -> V_193 . V_186 == V_37 ) {
V_138 = V_68 -> V_193 . V_13 ;
F_243 ( V_6 , V_37 , V_68 ) ;
V_2 = V_68 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_194 :
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_68 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_26 ] ) ;
F_83 ( & V_68 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
if ( ! F_91 ( V_6 , V_37 , V_138 ) ) {
F_99 ( V_6 , V_138 , 1 ) ;
F_13 ( V_6 , V_37 ,
V_26 , 1 , 0 ) ;
}
F_31 ( V_68 ) ;
V_2 = 0 ;
break;
case V_234 :
if ( ! F_91 ( V_6 , V_37 , V_138 ) )
F_137 ( V_6 , V_138 ) ;
V_2 = V_194 ;
break;
case V_235 :
V_254 = V_37 ;
V_47 = F_194 ( V_6 , V_254 ,
V_68 -> V_195 , 2 ,
V_466 ,
V_450 ,
V_383 ) ;
if ( V_47 )
F_24 ( V_6 , L_39 ,
V_37 , V_68 -> V_195 ) ;
F_165 ( & V_68 -> V_328 -> V_198 ) ;
F_165 ( & V_68 -> V_329 -> V_198 ) ;
F_165 ( & V_68 -> V_77 -> V_198 ) ;
if ( V_68 -> V_74 )
F_165 ( & V_68 -> V_74 -> V_198 ) ;
V_2 = V_234 ;
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
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_467 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_28 ] ;
struct V_208 * V_74 ;
struct V_208 * V_267 ;
int V_2 ;
T_1 V_254 ;
F_250 ( V_468 ) ;
int V_261 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_28 ) ;
if ( V_47 )
F_11 ( V_6 , L_40 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (srq, tmp, srq_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_74 -> V_193 . V_186 == V_37 ) {
V_261 = V_74 -> V_193 . V_13 ;
V_2 = V_74 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_209 :
F_114 ( V_6 , V_261 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_74 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_28 ] ) ;
F_83 ( & V_74 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_28 , 1 , 0 ) ;
F_31 ( V_74 ) ;
V_2 = 0 ;
break;
case V_249 :
V_254 = V_37 ;
V_47 = F_194 ( V_6 , V_254 , V_261 , 1 ,
V_469 ,
V_450 ,
V_383 ) ;
if ( V_47 )
F_24 ( V_6 , L_41 ,
V_37 , V_261 ) ;
F_165 ( & V_74 -> V_77 -> V_198 ) ;
if ( V_74 -> V_71 )
F_165 ( & V_74 -> V_71 -> V_198 ) ;
V_2 = V_209 ;
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
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_470 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_27 ] ;
struct V_206 * V_71 ;
struct V_206 * V_267 ;
int V_2 ;
T_1 V_254 ;
F_250 ( V_468 ) ;
int V_245 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_27 ) ;
if ( V_47 )
F_11 ( V_6 , L_42 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (cq, tmp, cq_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_71 -> V_193 . V_186 == V_37 && ! F_70 ( & V_71 -> V_198 ) ) {
V_245 = V_71 -> V_193 . V_13 ;
V_2 = V_71 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_207 :
F_111 ( V_6 , V_245 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_71 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_27 ] ) ;
F_83 ( & V_71 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_27 , 1 , 0 ) ;
F_31 ( V_71 ) ;
V_2 = 0 ;
break;
case V_247 :
V_254 = V_37 ;
V_47 = F_194 ( V_6 , V_254 , V_245 , 1 ,
V_471 ,
V_450 ,
V_383 ) ;
if ( V_47 )
F_24 ( V_6 , L_43 ,
V_37 , V_245 ) ;
F_165 ( & V_71 -> V_77 -> V_198 ) ;
V_2 = V_207 ;
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
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_472 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_29 ] ;
struct V_202 * V_79 ;
struct V_202 * V_267 ;
int V_2 ;
T_1 V_254 ;
F_250 ( V_468 ) ;
int V_473 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_29 ) ;
if ( V_47 )
F_11 ( V_6 , L_44 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (mpt, tmp, mpt_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_79 -> V_193 . V_186 == V_37 ) {
V_473 = V_79 -> V_193 . V_13 ;
V_2 = V_79 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_203 :
F_107 ( V_6 , V_79 -> V_201 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_79 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_29 ] ) ;
F_83 ( & V_79 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 ,
V_29 , 1 , 0 ) ;
F_31 ( V_79 ) ;
V_2 = 0 ;
break;
case V_239 :
F_140 ( V_6 , V_79 -> V_201 ) ;
V_2 = V_203 ;
break;
case V_240 :
V_254 = V_37 ;
V_47 = F_194 ( V_6 , V_254 , V_473 , 0 ,
V_474 ,
V_450 ,
V_383 ) ;
if ( V_47 )
F_24 ( V_6 , L_45 ,
V_37 , V_473 ) ;
if ( V_79 -> V_77 )
F_165 ( & V_79 -> V_77 -> V_198 ) ;
V_2 = V_239 ;
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
struct V_219 * V_220 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_475 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_30 ] ;
struct V_200 * V_77 ;
struct V_200 * V_267 ;
int V_2 ;
F_250 ( V_468 ) ;
int V_217 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_30 ) ;
if ( V_47 )
F_11 ( V_6 , L_46 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (mtt, tmp, mtt_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_77 -> V_193 . V_186 == V_37 ) {
V_217 = V_77 -> V_193 . V_13 ;
V_2 = V_77 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_104 ( V_6 , V_217 ,
V_77 -> V_199 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_77 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_30 ] ) ;
F_83 ( & V_77 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_13 ( V_6 , V_37 , V_30 ,
1 << V_77 -> V_199 , 0 ) ;
F_31 ( V_77 ) ;
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
struct V_219 * V_220 =
& V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_476 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_35 ] ;
struct V_214 * V_477 ;
struct V_214 * V_267 ;
int V_2 ;
T_1 V_217 ;
int V_47 ;
V_47 = F_245 ( V_6 , V_37 , V_35 ) ;
if ( V_47 )
F_11 ( V_6 , L_47 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (fs_rule, tmp, fs_rule_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_477 -> V_193 . V_186 == V_37 ) {
V_217 = V_477 -> V_193 . V_13 ;
V_2 = V_477 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_215 :
V_47 = F_194 ( V_6 , V_217 , 0 , 0 ,
V_456 ,
V_450 ,
V_383 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_477 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_35 ] ) ;
F_83 ( & V_477 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_31 ( V_477 ) ;
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
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_478 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_33 ] ;
struct V_204 * V_242 ;
struct V_204 * V_267 ;
int V_47 ;
int V_2 ;
F_250 ( V_468 ) ;
int V_346 ;
V_47 = F_245 ( V_6 , V_37 , V_33 ) ;
if ( V_47 )
F_11 ( V_6 , L_48 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (eq, tmp, eq_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_242 -> V_193 . V_186 == V_37 ) {
V_346 = V_242 -> V_193 . V_13 ;
V_2 = V_242 -> V_193 . V_188 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_205 :
F_49 ( F_50 ( V_6 ) ) ;
F_68 ( & V_242 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_33 ] ) ;
F_83 ( & V_242 -> V_193 . V_222 ) ;
F_51 ( F_50 ( V_6 ) ) ;
F_31 ( V_242 ) ;
V_2 = 0 ;
break;
case V_244 :
V_47 = F_194 ( V_6 , V_37 , V_346 & 0xff ,
1 , V_479 ,
V_450 ,
V_383 ) ;
if ( V_47 )
F_24 ( V_6 , L_49 ,
V_37 , V_346 ) ;
F_165 ( & V_242 -> V_77 -> V_198 ) ;
V_2 = V_205 ;
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
static void F_256 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_480 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_34 ] ;
struct V_210 * V_481 ;
struct V_210 * V_267 ;
int V_47 ;
int V_237 ;
V_47 = F_245 ( V_6 , V_37 , V_34 ) ;
if ( V_47 )
F_11 ( V_6 , L_50 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (counter, tmp, counter_list, com.list) {
if ( V_481 -> V_193 . V_186 == V_37 ) {
V_237 = V_481 -> V_193 . V_13 ;
F_68 ( & V_481 -> V_193 . V_15 ,
& V_220 -> V_92 [ V_34 ] ) ;
F_83 ( & V_481 -> V_193 . V_222 ) ;
F_31 ( V_481 ) ;
F_131 ( V_6 , V_237 ) ;
F_13 ( V_6 , V_37 , V_34 , 1 , 0 ) ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
}
static void F_257 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
struct V_219 * V_220 = & V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_482 =
& V_220 -> V_85 [ V_37 ] . V_90 [ V_36 ] ;
struct V_212 * V_483 ;
struct V_212 * V_267 ;
int V_47 ;
int V_275 ;
V_47 = F_245 ( V_6 , V_37 , V_36 ) ;
if ( V_47 )
F_11 ( V_6 , L_51 ,
V_37 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_483 -> V_193 . V_186 == V_37 ) {
V_275 = V_483 -> V_193 . V_13 ;
F_68 ( & V_483 -> V_193 . V_15 , & V_220 -> V_92 [ V_36 ] ) ;
F_83 ( & V_483 -> V_193 . V_222 ) ;
F_31 ( V_483 ) ;
F_134 ( V_6 , V_275 ) ;
}
}
F_51 ( F_50 ( V_6 ) ) ;
}
void F_33 ( struct V_5 * V_6 , int V_37 )
{
struct V_40 * V_41 = V_40 ( V_6 ) ;
F_34 ( V_6 , V_37 ) ;
F_35 ( & V_41 -> V_44 . V_45 . V_46 . V_85 [ V_37 ] . V_91 ) ;
F_36 ( V_6 , V_37 ) ;
F_119 ( V_6 , V_37 ) ;
F_254 ( V_6 , V_37 ) ;
F_248 ( V_6 , V_37 ) ;
F_249 ( V_6 , V_37 ) ;
F_251 ( V_6 , V_37 ) ;
F_252 ( V_6 , V_37 ) ;
F_255 ( V_6 , V_37 ) ;
F_253 ( V_6 , V_37 ) ;
F_256 ( V_6 , V_37 ) ;
F_257 ( V_6 , V_37 ) ;
F_37 ( & V_41 -> V_44 . V_45 . V_46 . V_85 [ V_37 ] . V_91 ) ;
}
void F_258 ( struct V_484 * V_485 )
{
struct V_486 * V_487 =
F_4 ( V_485 , struct V_486 , V_487 ) ;
struct V_114 * V_371 ;
struct V_441 * V_488 ;
struct V_5 * V_6 = & V_487 -> V_41 -> V_6 ;
struct V_219 * V_220 =
& V_487 -> V_41 -> V_44 . V_45 . V_46 ;
struct V_264 * V_465 =
& V_220 -> V_85 [ V_487 -> V_37 ] . V_90 [ V_26 ] ;
struct V_191 * V_68 ;
struct V_191 * V_267 ;
T_1 V_489 =
( ( 1ULL << V_490 ) |
( 1ULL << V_491 ) |
( 1ULL << V_492 ) |
( 1ULL << V_493 ) |
( 1ULL << V_494 ) |
( 1ULL << V_495 ) ) ;
T_1 V_496 = ( ( 1ULL << V_497 ) |
( 1ULL << V_498 ) |
( 1ULL << V_499 ) |
( 1ULL << V_500 ) |
( 1ULL << V_501 ) |
( 1ULL << V_502 ) |
( 1ULL << V_503 ) ) ;
int V_47 ;
int V_7 , V_504 = 0 ;
T_2 V_160 ;
if ( F_17 ( V_6 ) ) {
F_11 ( V_6 , L_52 ,
V_487 -> V_37 ) ;
goto V_62;
}
V_371 = F_190 ( V_6 ) ;
if ( F_191 ( V_371 ) )
goto V_62;
if ( V_487 -> V_127 & V_505 )
V_160 = V_161 |
V_162 |
V_163 |
V_164 |
V_165 |
V_166 ;
else if ( ! V_487 -> V_506 )
V_160 = V_161 |
V_166 ;
else
V_160 = V_161 |
V_164 |
V_165 ;
V_488 = V_371 -> V_117 ;
V_488 -> V_443 = F_232 ( 1ULL << V_507 ) ;
F_49 ( F_50 ( V_6 ) ) ;
F_116 (qp, tmp, qp_list, com.list) {
F_51 ( F_50 ( V_6 ) ) ;
if ( V_68 -> V_193 . V_186 == V_487 -> V_37 ) {
if ( V_68 -> V_193 . V_188 != V_235 ||
! V_68 -> V_130 ||
F_43 ( V_6 , V_68 -> V_195 ) ||
V_68 -> V_334 & ( 1 << V_508 ) ) {
F_49 ( F_50 ( V_6 ) ) ;
continue;
}
V_7 = ( V_68 -> V_130 >> 6 & 1 ) + 1 ;
if ( V_7 != V_487 -> V_7 ) {
F_49 ( F_50 ( V_6 ) ) ;
continue;
}
if ( V_132 == ( ( V_68 -> V_334 >> 16 ) & 0xff ) )
V_488 -> V_442 = F_232 ( V_496 ) ;
else
V_488 -> V_442 =
F_232 ( V_496 | V_489 ) ;
if ( V_487 -> V_506 == V_145 ) {
V_488 -> V_447 . V_151 = V_68 -> V_151 ;
V_488 -> V_447 . V_129 . V_160 = V_68 -> V_160 ;
V_488 -> V_447 . V_129 . V_167 = V_68 -> V_167 ;
V_488 -> V_447 . V_129 . V_169 = V_68 -> V_169 ;
V_488 -> V_447 . V_129 . V_171 = V_68 -> V_333 ;
V_488 -> V_447 . V_129 . V_174 = V_68 -> V_174 ;
V_488 -> V_447 . V_129 . V_130 =
V_68 -> V_130 ;
} else {
V_488 -> V_447 . V_151 = V_68 -> V_151 & ~ F_44 ( V_152 ) ;
V_488 -> V_447 . V_129 . V_160 = V_160 ;
V_488 -> V_447 . V_129 . V_169 = V_487 -> V_509 ;
V_488 -> V_447 . V_129 . V_167 =
V_68 -> V_167 | V_168 ;
V_488 -> V_447 . V_129 . V_171 =
V_68 -> V_333 | V_172 | V_173 ;
V_488 -> V_447 . V_129 . V_174 =
V_68 -> V_174 | V_175 | V_176 ;
V_488 -> V_447 . V_129 . V_130 =
V_68 -> V_130 & 0xC7 ;
V_488 -> V_447 . V_129 . V_130 |=
( ( V_487 -> V_510 & 0x7 ) << 3 ) ;
}
V_47 = F_194 ( V_6 , V_371 -> V_380 ,
V_68 -> V_195 & 0xffffff ,
0 , V_449 ,
V_511 , V_383 ) ;
if ( V_47 ) {
F_259 ( V_6 , L_53 ,
V_487 -> V_37 , V_7 , V_68 -> V_195 , V_47 ) ;
V_504 ++ ;
}
}
F_49 ( F_50 ( V_6 ) ) ;
}
F_51 ( F_50 ( V_6 ) ) ;
F_195 ( V_6 , V_371 ) ;
if ( V_504 )
F_185 ( V_6 , L_54 ,
V_504 , V_487 -> V_37 , V_487 -> V_7 ) ;
if ( V_487 -> V_127 & V_512 && ! V_504 &&
V_513 != V_487 -> V_514 )
F_126 ( & V_487 -> V_41 -> V_6 , V_487 -> V_7 ,
V_487 -> V_515 ) ;
V_62:
F_31 ( V_487 ) ;
return;
}
