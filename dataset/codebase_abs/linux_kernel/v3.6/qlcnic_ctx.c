static T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 ;
do {
F_2 ( 1 ) ;
if ( ++ V_4 > V_5 )
return V_6 ;
V_3 = F_3 ( V_2 , V_7 ) ;
} while ( ! F_4 ( V_3 ) );
return V_3 ;
}
void
F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
T_1 V_3 ;
T_1 V_10 ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
V_10 = F_6 ( V_14 -> V_15 ,
V_2 -> V_16 ) ;
if ( F_7 ( V_2 ) ) {
V_9 -> V_3 . V_9 = V_17 ;
return;
}
F_8 ( V_2 , V_18 , V_10 ) ;
F_8 ( V_2 , V_19 , V_9 -> V_20 . V_21 ) ;
F_8 ( V_2 , V_22 , V_9 -> V_20 . V_23 ) ;
F_8 ( V_2 , V_24 , V_9 -> V_20 . V_25 ) ;
F_8 ( V_2 , V_7 ,
F_9 ( V_9 -> V_20 . V_9 ) ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 == V_6 ) {
F_10 ( & V_12 -> V_26 , L_1 ) ;
V_9 -> V_3 . V_9 = V_17 ;
} else if ( V_3 == V_27 ) {
V_9 -> V_3 . V_9 = F_3 ( V_2 , V_19 ) ;
switch ( V_9 -> V_3 . V_9 ) {
case V_28 :
F_10 ( & V_12 -> V_26 , L_2 ,
V_9 -> V_3 . V_9 ) ;
break;
case V_29 :
case V_30 :
F_10 ( & V_12 -> V_26 ,
L_3 ,
V_9 -> V_3 . V_9 ) ;
break;
case V_31 :
F_10 ( & V_12 -> V_26 ,
L_4 ,
V_9 -> V_3 . V_9 ) ;
break;
case V_32 :
F_10 ( & V_12 -> V_26 ,
L_5 ,
V_9 -> V_3 . V_9 ) ;
break;
case V_17 :
F_10 ( & V_12 -> V_26 , L_6 ,
V_9 -> V_3 . V_9 ) ;
break;
default:
F_10 ( & V_12 -> V_26 , L_7 ,
V_9 -> V_3 . V_9 ) ;
}
} else if ( V_3 == V_33 ) {
V_9 -> V_3 . V_9 = V_34 ;
if ( V_9 -> V_3 . V_23 )
V_9 -> V_3 . V_23 = F_3 ( V_2 ,
V_22 ) ;
if ( V_9 -> V_3 . V_25 )
V_9 -> V_3 . V_25 = F_3 ( V_2 ,
V_24 ) ;
}
if ( V_9 -> V_3 . V_21 )
V_9 -> V_3 . V_21 = F_3 ( V_2 , V_19 ) ;
F_11 ( V_2 ) ;
}
static T_2 F_12 ( T_2 * V_35 , T_3 V_36 )
{
T_4 V_37 = 0 ;
int V_38 = V_36 / sizeof( T_2 ) ;
while ( V_38 -- > 0 )
V_37 += * V_35 ++ ;
while ( V_37 >> 32 )
V_37 = ( V_37 & 0xFFFFFFFF ) + ( V_37 >> 32 ) ;
return ~ V_37 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_39 , V_40 ;
T_3 V_36 ;
void * V_41 ;
T_1 V_42 , V_43 , * V_44 , * V_45 ;
struct V_8 V_9 ;
struct V_13 * V_14 ;
struct V_46 * V_47 , * V_48 ;
T_5 V_49 = 0 ;
V_14 = V_2 -> V_14 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_50 ;
memset ( & V_9 . V_3 , 1 , sizeof( struct V_51 ) ) ;
F_5 ( V_2 , & V_9 ) ;
if ( V_9 . V_3 . V_9 != V_34 ) {
F_14 ( & V_2 -> V_12 -> V_26 ,
L_8 , V_9 . V_3 . V_9 ) ;
V_39 = - V_52 ;
return V_39 ;
}
V_36 = V_9 . V_3 . V_23 ;
V_42 = V_9 . V_3 . V_25 ;
if ( ! V_36 )
return - V_52 ;
V_41 = F_15 ( & V_2 -> V_12 -> V_26 , V_36 ,
& V_49 , V_53 ) ;
if ( ! V_41 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_9 ) ;
return - V_54 ;
}
memset ( & V_9 . V_3 , 0 , sizeof( struct V_51 ) ) ;
V_9 . V_20 . V_9 = V_55 ;
V_9 . V_20 . V_21 = F_16 ( V_49 ) ;
V_9 . V_20 . V_23 = F_17 ( V_49 ) ;
V_9 . V_20 . V_25 = V_36 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 != V_34 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_10 , V_39 ) ;
V_39 = - V_52 ;
goto error;
}
V_48 = V_41 ;
V_43 = F_12 ( ( T_2 * ) V_41 , V_36 ) ;
if ( V_43 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_11 ) ;
V_39 = - V_52 ;
goto error;
}
V_14 -> V_56 . V_47 = F_18 ( V_36 ) ;
if ( ! V_14 -> V_56 . V_47 ) {
V_39 = - V_52 ;
goto error;
}
V_45 = V_41 ;
V_44 = ( T_1 * ) V_14 -> V_56 . V_47 ;
for ( V_40 = 0 ; V_40 < V_36 / sizeof( T_1 ) ; V_40 ++ )
* V_44 ++ = F_19 ( * V_45 ++ ) ;
V_47 = V_14 -> V_56 . V_47 ;
V_47 -> V_57 = V_58 ;
V_14 -> V_56 . V_59 = 1 ;
error:
F_20 ( & V_2 -> V_12 -> V_26 , V_36 , V_41 , V_49 ) ;
return V_39 ;
}
int
F_21 ( struct V_1 * V_2 , int V_60 )
{
struct V_8 V_9 ;
struct V_61 * V_62 = V_2 -> V_62 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_63 ;
V_9 . V_20 . V_21 = V_62 -> V_64 ;
V_9 . V_20 . V_23 = V_60 ;
V_9 . V_20 . V_25 = 0 ;
if ( V_62 -> V_65 == V_66 ) {
F_5 ( V_2 , & V_9 ) ;
if ( V_9 . V_3 . V_9 ) {
F_10 ( & V_2 -> V_12 -> V_26 , L_12 ) ;
return - V_52 ;
}
}
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 )
{
void * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_8 V_9 ;
T_5 V_84 , V_85 ;
T_6 V_86 ;
T_7 V_40 , V_87 , V_88 ;
T_8 V_89 , V_90 ;
T_1 V_91 , V_92 , V_93 , V_94 ;
int V_39 ;
struct V_61 * V_62 = V_2 -> V_62 ;
V_87 = V_2 -> V_95 ;
V_88 = V_2 -> V_96 ;
V_89 =
F_23 ( struct V_68 , V_87 ,
V_88 ) ;
V_90 =
F_24 ( struct V_70 , V_87 ,
V_88 ) ;
V_67 = F_15 ( & V_2 -> V_12 -> V_26 , V_89 ,
& V_84 , V_53 ) ;
if ( V_67 == NULL )
return - V_54 ;
V_69 = V_67 ;
V_67 = F_15 ( & V_2 -> V_12 -> V_26 , V_90 ,
& V_85 , V_53 ) ;
if ( V_67 == NULL ) {
V_39 = - V_54 ;
goto V_97;
}
V_71 = V_67 ;
V_69 -> V_98 = F_25 ( V_85 ) ;
V_91 = ( V_99 | V_100
| V_101 ) ;
V_91 |= ( V_102 | V_103 ) ;
if ( V_2 -> V_104 & V_105 )
V_91 |= V_106 ;
V_69 -> V_107 = F_26 ( struct V_68 ,
V_108 ) ;
V_69 -> V_109 = V_88 - 1 ;
V_69 -> V_110 [ 0 ] = F_27 ( V_91 ) ;
V_69 -> V_111 =
F_27 ( V_112 ) ;
V_69 -> V_113 =
F_27 ( V_114 ) ;
V_69 -> V_115 = F_28 ( V_87 ) ;
V_69 -> V_116 = F_28 ( V_88 ) ;
V_69 -> V_117 = 0 ;
V_93 = F_29 ( V_69 -> V_117 ) +
( sizeof( struct V_72 ) * V_87 ) ;
V_69 -> V_118 = F_27 ( V_93 ) ;
V_73 = (struct V_72 * ) ( V_69 -> V_119 +
F_29 ( V_69 -> V_117 ) ) ;
for ( V_40 = 0 ; V_40 < V_87 ; V_40 ++ ) {
V_81 = & V_62 -> V_120 [ V_40 ] ;
V_81 -> V_121 = 0 ;
V_73 [ V_40 ] . V_122 = F_25 ( V_81 -> V_86 ) ;
V_73 [ V_40 ] . V_123 = F_27 ( V_81 -> V_124 ) ;
V_73 [ V_40 ] . V_125 = F_27 ( V_40 ) ;
V_73 [ V_40 ] . V_126 = F_25 ( V_81 -> V_127 ) ;
}
V_75 = (struct V_74 * ) ( V_69 -> V_119 +
F_29 ( V_69 -> V_118 ) ) ;
for ( V_40 = 0 ; V_40 < V_88 ; V_40 ++ ) {
V_83 = & V_62 -> V_128 [ V_40 ] ;
V_83 -> V_129 = 0 ;
memset ( V_83 -> V_130 , 0 , F_30 ( V_83 ) ) ;
V_75 [ V_40 ] . V_122 = F_25 ( V_83 -> V_86 ) ;
V_75 [ V_40 ] . V_123 = F_27 ( V_83 -> V_124 ) ;
V_75 [ V_40 ] . V_131 = F_28 ( V_40 ) ;
}
V_86 = V_84 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_21 = ( T_1 ) ( V_86 >> 32 ) ;
V_9 . V_20 . V_23 = ( T_1 ) ( V_86 & 0xffffffff ) ;
V_9 . V_20 . V_25 = V_89 ;
V_9 . V_20 . V_9 = V_132 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_13 , V_39 ) ;
goto V_133;
}
V_77 = ( (struct V_76 * )
& V_71 -> V_119 [ F_29 ( V_71 -> V_117 ) ] ) ;
for ( V_40 = 0 ; V_40 < F_31 ( V_71 -> V_115 ) ; V_40 ++ ) {
V_81 = & V_62 -> V_120 [ V_40 ] ;
V_92 = F_29 ( V_77 [ V_40 ] . V_134 ) ;
V_81 -> V_135 = V_2 -> V_14 -> V_136 + V_92 ;
}
V_79 = ( (struct V_78 * )
& V_71 -> V_119 [ F_29 ( V_71 -> V_118 ) ] ) ;
for ( V_40 = 0 ; V_40 < F_31 ( V_71 -> V_116 ) ; V_40 ++ ) {
V_83 = & V_62 -> V_128 [ V_40 ] ;
V_92 = F_29 ( V_79 [ V_40 ] . V_137 ) ;
V_94 = F_29 ( V_79 [ V_40 ] . V_138 ) ;
V_83 -> V_139 = V_2 -> V_14 -> V_136 + V_92 ;
V_83 -> V_140 = V_2 -> V_14 -> V_136 + V_94 ;
}
V_62 -> V_65 = F_29 ( V_71 -> V_141 ) ;
V_62 -> V_64 = F_31 ( V_71 -> V_64 ) ;
V_62 -> V_142 = V_71 -> V_142 ;
V_133:
F_20 ( & V_2 -> V_12 -> V_26 , V_90 , V_71 ,
V_85 ) ;
V_97:
F_20 ( & V_2 -> V_12 -> V_26 , V_89 , V_69 , V_84 ) ;
return V_39 ;
}
static void
F_32 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
struct V_61 * V_62 = V_2 -> V_62 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_21 = V_62 -> V_64 ;
V_9 . V_20 . V_23 = V_143 ;
V_9 . V_20 . V_25 = 0 ;
V_9 . V_20 . V_9 = V_144 ;
F_5 ( V_2 , & V_9 ) ;
if ( V_9 . V_3 . V_9 )
F_10 ( & V_2 -> V_12 -> V_26 ,
L_14 ) ;
V_62 -> V_65 = V_145 ;
}
static int
F_33 ( struct V_1 * V_2 )
{
struct V_146 * V_69 ;
struct V_147 * V_148 ;
struct V_149 * V_71 ;
void * V_150 , * V_151 ;
T_8 V_89 , V_90 ;
T_1 V_152 ;
struct V_8 V_9 ;
int V_39 ;
T_6 V_86 ;
T_5 V_153 , V_154 ;
struct V_155 * V_156 = V_2 -> V_156 ;
V_156 -> V_121 = 0 ;
V_156 -> V_157 = 0 ;
* ( V_156 -> V_158 ) = 0 ;
V_89 = F_34 ( struct V_146 ) ;
V_150 = F_15 ( & V_2 -> V_12 -> V_26 , V_89 ,
& V_153 , V_53 ) ;
if ( ! V_150 )
return - V_54 ;
V_90 = F_35 ( struct V_149 ) ;
V_151 = F_15 ( & V_2 -> V_12 -> V_26 , V_90 ,
& V_154 , V_53 ) ;
if ( ! V_151 ) {
V_39 = - V_54 ;
goto V_97;
}
memset ( V_150 , 0 , V_89 ) ;
V_69 = V_150 ;
memset ( V_151 , 0 , V_90 ) ;
V_71 = V_151 ;
V_69 -> V_98 = F_25 ( V_154 ) ;
V_152 = ( V_99 | V_100 |
V_159 ) ;
V_69 -> V_110 [ 0 ] = F_27 ( V_152 ) ;
V_69 -> V_111 =
F_27 ( V_112 ) ;
V_69 -> V_160 = 0 ;
V_69 -> V_131 = 0 ;
V_69 -> V_161 = F_25 ( V_156 -> V_162 ) ;
V_148 = & V_69 -> V_163 ;
V_148 -> V_122 = F_25 ( V_156 -> V_86 ) ;
V_148 -> V_123 = F_27 ( V_156 -> V_124 ) ;
V_86 = V_153 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_21 = ( T_1 ) ( V_86 >> 32 ) ;
V_9 . V_20 . V_23 = ( ( T_1 ) V_86 & 0xffffffff ) ;
V_9 . V_20 . V_25 = V_89 ;
V_9 . V_20 . V_9 = V_164 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 == V_34 ) {
V_152 = F_29 ( V_71 -> V_163 . V_134 ) ;
V_156 -> V_165 = V_2 -> V_14 -> V_136 + V_152 ;
V_2 -> V_166 =
F_31 ( V_71 -> V_64 ) ;
} else {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_15 , V_39 ) ;
V_39 = - V_52 ;
}
F_20 ( & V_2 -> V_12 -> V_26 , V_90 , V_151 ,
V_154 ) ;
V_97:
F_20 ( & V_2 -> V_12 -> V_26 , V_89 , V_150 , V_153 ) ;
return V_39 ;
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_21 = V_2 -> V_166 ;
V_9 . V_20 . V_23 = V_143 ;
V_9 . V_20 . V_25 = 0 ;
V_9 . V_20 . V_9 = V_167 ;
F_5 ( V_2 , & V_9 ) ;
if ( V_9 . V_3 . V_9 )
F_10 ( & V_2 -> V_12 -> V_26 ,
L_16 ) ;
}
int
F_37 ( struct V_1 * V_2 , T_1 V_168 )
{
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_21 = V_168 ;
V_9 . V_20 . V_9 = V_169 ;
F_5 ( V_2 , & V_9 ) ;
return V_9 . V_3 . V_9 ;
}
int F_38 ( struct V_1 * V_2 )
{
void * V_67 ;
int V_39 ;
int V_170 ;
struct V_61 * V_62 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_155 * V_156 ;
struct V_11 * V_12 = V_2 -> V_12 ;
V_62 = V_2 -> V_62 ;
V_156 = V_2 -> V_156 ;
V_156 -> V_158 = ( V_171 * ) F_15 ( & V_12 -> V_26 ,
sizeof( T_1 ) , & V_156 -> V_162 , V_53 ) ;
if ( V_156 -> V_158 == NULL ) {
F_10 ( & V_12 -> V_26 , L_17 ) ;
return - V_54 ;
}
V_67 = F_15 ( & V_12 -> V_26 , F_39 ( V_156 ) ,
& V_156 -> V_86 , V_53 ) ;
if ( V_67 == NULL ) {
F_10 ( & V_12 -> V_26 , L_18 ) ;
V_39 = - V_54 ;
goto V_172;
}
V_156 -> V_130 = V_67 ;
for ( V_170 = 0 ; V_170 < V_2 -> V_95 ; V_170 ++ ) {
V_81 = & V_62 -> V_120 [ V_170 ] ;
V_67 = F_15 ( & V_2 -> V_12 -> V_26 ,
F_40 ( V_81 ) ,
& V_81 -> V_86 , V_53 ) ;
if ( V_67 == NULL ) {
F_10 ( & V_12 -> V_26 ,
L_19 , V_170 ) ;
V_39 = - V_54 ;
goto V_172;
}
V_81 -> V_130 = V_67 ;
}
for ( V_170 = 0 ; V_170 < V_2 -> V_96 ; V_170 ++ ) {
V_83 = & V_62 -> V_128 [ V_170 ] ;
V_67 = F_15 ( & V_2 -> V_12 -> V_26 ,
F_30 ( V_83 ) ,
& V_83 -> V_86 , V_53 ) ;
if ( V_67 == NULL ) {
F_10 ( & V_12 -> V_26 ,
L_20 , V_170 ) ;
V_39 = - V_54 ;
goto V_172;
}
V_83 -> V_130 = V_67 ;
}
return 0 ;
V_172:
F_41 ( V_2 ) ;
return V_39 ;
}
int F_42 ( struct V_1 * V_2 )
{
int V_39 ;
if ( V_2 -> V_104 & V_173 ) {
F_43 ( V_2 -> V_12 ) ;
V_2 -> V_104 &= ~ V_173 ;
}
V_39 = F_22 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_33 ( V_2 ) ;
if ( V_39 ) {
F_32 ( V_2 ) ;
return V_39 ;
}
F_44 ( V_174 , & V_2 -> V_65 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( F_46 ( V_174 , & V_2 -> V_65 ) ) {
F_32 ( V_2 ) ;
F_36 ( V_2 ) ;
F_2 ( 20 ) ;
}
}
void F_41 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_155 * V_156 ;
int V_170 ;
V_62 = V_2 -> V_62 ;
V_156 = V_2 -> V_156 ;
if ( V_156 -> V_158 != NULL ) {
F_20 ( & V_2 -> V_12 -> V_26 ,
sizeof( T_1 ) ,
V_156 -> V_158 ,
V_156 -> V_162 ) ;
V_156 -> V_158 = NULL ;
}
if ( V_156 -> V_130 != NULL ) {
F_20 ( & V_2 -> V_12 -> V_26 ,
F_39 ( V_156 ) ,
V_156 -> V_130 , V_156 -> V_86 ) ;
V_156 -> V_130 = NULL ;
}
for ( V_170 = 0 ; V_170 < V_2 -> V_95 ; V_170 ++ ) {
V_81 = & V_62 -> V_120 [ V_170 ] ;
if ( V_81 -> V_130 != NULL ) {
F_20 ( & V_2 -> V_12 -> V_26 ,
F_40 ( V_81 ) ,
V_81 -> V_130 ,
V_81 -> V_86 ) ;
V_81 -> V_130 = NULL ;
}
}
for ( V_170 = 0 ; V_170 < V_2 -> V_96 ; V_170 ++ ) {
V_83 = & V_62 -> V_128 [ V_170 ] ;
if ( V_83 -> V_130 != NULL ) {
F_20 ( & V_2 -> V_12 -> V_26 ,
F_30 ( V_83 ) ,
V_83 -> V_130 ,
V_83 -> V_86 ) ;
V_83 -> V_130 = NULL ;
}
}
}
int F_47 ( struct V_1 * V_2 , T_7 * V_175 )
{
int V_39 ;
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_21 = V_2 -> V_14 -> V_15 | V_176 ;
V_9 . V_20 . V_9 = V_177 ;
V_9 . V_3 . V_21 = V_9 . V_3 . V_23 = 1 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 == V_34 )
F_48 ( V_2 , V_9 . V_3 . V_21 , V_9 . V_3 . V_23 , 0 , V_175 ) ;
else {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_21 , V_39 ) ;
V_39 = - V_52 ;
}
return V_39 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_178 * V_179 , T_7 V_180 )
{
int V_39 ;
T_5 V_181 ;
struct V_178 * V_182 ;
void * V_183 ;
struct V_8 V_9 ;
T_8 V_184 = sizeof( struct V_178 ) ;
V_183 = F_15 ( & V_2 -> V_12 -> V_26 , V_184 ,
& V_181 , V_53 ) ;
if ( ! V_183 )
return - V_54 ;
memset ( V_183 , 0 , V_184 ) ;
V_182 = V_183 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_185 ;
V_9 . V_20 . V_21 = F_17 ( V_181 ) ;
V_9 . V_20 . V_23 = F_16 ( V_181 ) ;
V_9 . V_20 . V_25 = ( V_180 << 16 | V_184 ) ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 == V_34 ) {
V_179 -> V_15 = F_31 ( V_182 -> V_15 ) ;
V_179 -> V_186 = F_31 ( V_182 -> V_186 ) ;
V_179 -> V_187 = F_31 ( V_182 -> V_187 ) ;
V_179 -> V_188 = F_31 ( V_182 -> V_188 ) ;
V_179 -> V_189 = F_31 ( V_182 -> V_189 ) ;
V_179 -> V_190 = F_31 ( V_182 -> V_190 ) ;
V_179 -> V_191 = F_31 ( V_182 -> V_191 ) ;
V_179 -> V_192 = F_31 ( V_182 -> V_192 ) ;
V_179 -> V_110 = F_29 ( V_182 -> V_110 ) ;
V_179 -> V_193 = F_31 ( V_182 -> V_193 ) ;
F_14 ( & V_2 -> V_12 -> V_26 ,
L_22
L_23
L_24 ,
V_179 -> V_187 , V_179 -> V_188 ,
V_179 -> V_189 , V_179 -> V_190 ,
V_179 -> V_191 , V_179 -> V_192 ,
V_179 -> V_193 , V_179 -> V_110 ) ;
} else {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_25 , V_39 ) ;
V_39 = - V_52 ;
}
F_20 ( & V_2 -> V_12 -> V_26 , V_184 , V_183 ,
V_181 ) ;
return V_39 ;
}
int F_50 ( struct V_1 * V_2 , struct V_178 * V_194 )
{
int V_39 = - V_52 ;
T_5 V_181 ;
void * V_183 ;
struct V_8 V_9 ;
struct V_178 * V_182 ;
T_8 V_184 = sizeof( struct V_178 ) ;
if ( V_2 -> V_186 != V_195 )
return V_39 ;
V_183 = F_15 ( & V_2 -> V_12 -> V_26 , V_184 ,
& V_181 , V_53 ) ;
if ( ! V_183 )
return - V_54 ;
memset ( V_183 , 0 , V_184 ) ;
V_182 = V_183 ;
V_182 -> V_15 = F_28 ( V_194 -> V_15 ) ;
V_182 -> V_186 = F_28 ( V_194 -> V_186 ) ;
V_182 -> V_187 = F_28 ( V_194 -> V_187 ) ;
V_182 -> V_188 = F_28 ( V_194 -> V_188 ) ;
V_182 -> V_110 = F_27 ( V_194 -> V_110 ) ;
V_182 -> V_196 = V_194 -> V_196 ;
V_182 -> V_189 = F_28 ( V_194 -> V_189 ) ;
V_182 -> V_190 = F_28 ( V_194 -> V_190 ) ;
V_182 -> V_191 = F_28 ( V_194 -> V_191 ) ;
V_182 -> V_192 = F_28 ( V_194 -> V_192 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_197 ;
V_9 . V_20 . V_21 = F_17 ( V_181 ) ;
V_9 . V_20 . V_23 = F_16 ( V_181 ) ;
V_9 . V_20 . V_25 = ( ( V_194 -> V_15 << 16 ) | V_184 ) ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 != V_34 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_26 , V_39 ) ;
V_39 = - V_52 ;
}
F_20 ( & V_2 -> V_12 -> V_26 , V_184 , V_183 ,
V_181 ) ;
return V_39 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_198 * V_199 )
{
int V_39 = 0 , V_40 ;
struct V_8 V_9 ;
T_5 V_200 ;
struct V_198 * V_201 ;
void * V_202 ;
T_8 V_203 = sizeof( struct V_198 ) ;
T_8 V_204 = V_203 * V_205 ;
V_202 = F_15 ( & V_2 -> V_12 -> V_26 , V_204 ,
& V_200 , V_53 ) ;
if ( ! V_202 )
return - V_54 ;
memset ( V_202 , 0 , V_204 ) ;
V_201 = V_202 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_206 ;
V_9 . V_20 . V_21 = F_17 ( V_200 ) ;
V_9 . V_20 . V_23 = F_16 ( V_200 ) ;
V_9 . V_20 . V_25 = V_204 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 == V_34 ) {
for ( V_40 = 0 ; V_40 < V_205 ; V_40 ++ , V_201 ++ , V_199 ++ ) {
V_199 -> V_207 = F_31 ( V_201 -> V_207 ) ;
V_199 -> V_208 = F_31 ( V_201 -> V_208 ) ;
V_199 -> type = F_31 ( V_201 -> type ) ;
V_199 -> V_209 =
F_31 ( V_201 -> V_209 ) ;
V_199 -> V_210 =
F_31 ( V_201 -> V_210 ) ;
V_199 -> V_211 =
F_31 ( V_201 -> V_211 ) ;
memcpy ( V_199 -> V_175 , V_201 -> V_175 , V_212 ) ;
}
} else {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_27 , V_39 ) ;
V_39 = - V_52 ;
}
F_20 ( & V_2 -> V_12 -> V_26 , V_204 , V_202 ,
V_200 ) ;
return V_39 ;
}
int F_52 ( struct V_1 * V_2 , T_7 V_207 ,
T_7 V_213 , T_7 V_15 )
{
int V_39 = - V_52 ;
T_1 V_21 ;
struct V_8 V_9 ;
if ( V_2 -> V_186 != V_195 ||
! ( V_2 -> V_214 [ V_207 ] . V_104 & V_215 ) )
return V_39 ;
V_21 = V_207 | ( V_213 ? V_216 : 0 ) ;
V_21 |= V_15 << 8 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_217 ;
V_9 . V_20 . V_21 = V_21 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 != V_34 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_28 ,
V_15 , V_207 ) ;
} else {
F_14 ( & V_2 -> V_12 -> V_26 ,
L_29 ,
V_207 , V_15 ) ;
}
return V_39 ;
}
int F_53 ( struct V_1 * V_2 , const T_7 V_218 ,
const T_7 V_219 , struct V_220 * V_221 ) {
T_8 V_222 = sizeof( struct V_220 ) ;
struct V_220 * V_223 ;
T_5 V_224 ;
void * V_225 ;
T_1 V_21 ;
struct V_8 V_9 ;
int V_39 ;
if ( V_221 == NULL )
return - V_54 ;
if ( V_2 -> V_186 != V_195 &&
V_218 != V_2 -> V_14 -> V_15 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_30 , V_218 ) ;
return - V_52 ;
}
V_225 = F_15 ( & V_2 -> V_12 -> V_26 , V_222 ,
& V_224 , V_53 ) ;
if ( ! V_225 ) {
F_10 ( & V_2 -> V_12 -> V_26 , L_31 ) ;
return - V_54 ;
}
memset ( V_225 , 0 , V_222 ) ;
V_21 = V_218 | V_226 << 8 | V_227 << 12 ;
V_21 |= V_219 << 15 | V_222 << 16 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_228 ;
V_9 . V_20 . V_21 = V_21 ;
V_9 . V_20 . V_23 = F_17 ( V_224 ) ;
V_9 . V_20 . V_25 = F_16 ( V_224 ) ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( ! V_39 ) {
V_223 = V_225 ;
V_221 -> V_64 = F_31 ( V_223 -> V_64 ) ;
V_221 -> V_42 = F_31 ( V_223 -> V_42 ) ;
V_221 -> V_229 = F_31 ( V_223 -> V_229 ) ;
V_221 -> V_230 =
F_54 ( V_223 -> V_230 ) ;
V_221 -> V_231 =
F_54 ( V_223 -> V_231 ) ;
V_221 -> V_232 = F_54 ( V_223 -> V_232 ) ;
V_221 -> V_233 = F_54 ( V_223 -> V_233 ) ;
V_221 -> V_234 = F_54 ( V_223 -> V_234 ) ;
V_221 -> V_235 = F_54 ( V_223 -> V_235 ) ;
V_221 -> V_236 = F_54 ( V_223 -> V_236 ) ;
}
F_20 ( & V_2 -> V_12 -> V_26 , V_222 , V_225 ,
V_224 ) ;
return V_39 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_237 * V_238 )
{
struct V_237 * V_223 ;
struct V_8 V_9 ;
T_8 V_222 = sizeof( struct V_237 ) ;
T_5 V_224 ;
void * V_225 ;
int V_39 ;
V_225 = F_15 ( & V_2 -> V_12 -> V_26 , V_222 ,
& V_224 , V_53 ) ;
if ( ! V_225 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_32 , V_239 ) ;
return - V_54 ;
}
memset ( V_225 , 0 , V_222 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_240 ;
V_9 . V_20 . V_21 = V_222 << 16 ;
V_9 . V_20 . V_23 = F_17 ( V_224 ) ;
V_9 . V_20 . V_25 = F_16 ( V_224 ) ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( ! V_39 ) {
V_223 = V_225 ;
V_238 -> V_241 = F_54 ( V_223 -> V_241 ) ;
V_238 -> V_242 = F_54 ( V_223 -> V_242 ) ;
V_238 -> V_243 =
F_54 ( V_223 -> V_243 ) ;
V_238 -> V_244 =
F_54 ( V_223 -> V_244 ) ;
V_238 -> V_245 = F_54 ( V_223 -> V_245 ) ;
V_238 -> V_246 = F_54 ( V_223 -> V_246 ) ;
V_238 -> V_247 =
F_54 ( V_223 -> V_247 ) ;
V_238 -> V_248 =
F_54 ( V_223 -> V_248 ) ;
V_238 -> V_249 =
F_54 ( V_223 -> V_249 ) ;
V_238 -> V_250 =
F_54 ( V_223 -> V_250 ) ;
V_238 -> V_251 = F_54 ( V_223 -> V_251 ) ;
V_238 -> V_252 = F_54 ( V_223 -> V_252 ) ;
V_238 -> V_253 = F_54 ( V_223 -> V_253 ) ;
}
F_20 ( & V_2 -> V_12 -> V_26 , V_222 , V_225 ,
V_224 ) ;
return V_39 ;
}
int F_56 ( struct V_1 * V_2 , const T_7 V_214 ,
const T_7 V_219 , struct V_220 * V_221 ) {
struct V_220 V_254 ;
T_7 V_40 ;
int V_255 = - V_52 ;
if ( V_221 == NULL )
return - V_54 ;
if ( V_2 -> V_186 != V_195 )
return - V_52 ;
if ( V_2 -> V_256 == NULL )
return - V_52 ;
memset ( V_221 , 0 , sizeof( T_6 ) ) ;
V_221 -> V_232 = V_257 ;
V_221 -> V_230 = V_257 ;
V_221 -> V_231 = V_257 ;
V_221 -> V_233 = V_257 ;
V_221 -> V_235 = V_257 ;
V_221 -> V_234 = V_257 ;
V_221 -> V_236 = V_257 ;
V_221 -> V_64 = V_214 ;
for ( V_40 = 0 ; V_40 < V_205 ; V_40 ++ ) {
if ( V_2 -> V_256 [ V_40 ] . V_258 != V_214 )
continue;
memset ( & V_254 , 0 , sizeof( struct V_220 ) ) ;
if ( F_53 ( V_2 , V_40 , V_219 , & V_254 ) )
continue;
V_221 -> V_229 = V_254 . V_229 ;
V_221 -> V_42 = V_254 . V_42 ;
F_57 ( V_221 -> V_232 ,
V_254 . V_232 ) ;
F_57 ( V_221 -> V_230 ,
V_254 . V_230 ) ;
F_57 ( V_221 -> V_231 ,
V_254 . V_231 ) ;
F_57 ( V_221 -> V_233 ,
V_254 . V_233 ) ;
F_57 ( V_221 -> V_235 ,
V_254 . V_235 ) ;
F_57 ( V_221 -> V_234 ,
V_254 . V_234 ) ;
F_57 ( V_221 -> V_236 ,
V_254 . V_236 ) ;
V_255 = 0 ;
}
return V_255 ;
}
int F_58 ( struct V_1 * V_2 , const T_7 V_259 ,
const T_7 V_260 , const T_7 V_219 )
{
T_1 V_21 ;
struct V_8 V_9 ;
if ( V_2 -> V_186 != V_195 )
return - V_52 ;
if ( V_259 == V_227 ) {
if ( V_260 >= V_205 )
goto V_261;
} else if ( V_259 == V_262 ) {
if ( V_260 >= V_263 )
goto V_261;
} else {
goto V_261;
}
if ( V_219 > V_264 )
goto V_261;
V_21 = V_260 | V_226 << 8 | V_259 << 12 ;
V_21 |= V_265 | V_219 << 15 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_228 ;
V_9 . V_20 . V_21 = V_21 ;
F_5 ( V_2 , & V_9 ) ;
return V_9 . V_3 . V_9 ;
V_261:
F_10 ( & V_2 -> V_12 -> V_26 , L_33
L_34 , V_259 , V_260 , V_219 ) ;
return - V_52 ;
}
static int
F_59 ( struct V_1 * V_2 ,
T_1 * V_21 , T_1 * V_23 )
{
int V_39 = - V_52 ;
struct V_8 V_9 ;
T_7 V_15 ;
V_15 = ( * V_21 >> 8 ) ;
V_9 . V_20 . V_9 = V_266 ;
V_9 . V_20 . V_21 = * V_21 ;
V_9 . V_3 . V_21 = V_9 . V_3 . V_23 = 1 ;
F_5 ( V_2 , & V_9 ) ;
* V_21 = V_9 . V_3 . V_21 ;
* V_23 = V_9 . V_3 . V_23 ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 == V_34 ) {
F_14 ( & V_2 -> V_12 -> V_26 ,
L_35 , V_15 ) ;
} else {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_36 ,
V_15 ) ;
}
return V_39 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
int V_39 = - V_52 ;
T_1 V_21 , V_23 = 0 ;
struct V_8 V_9 ;
T_7 V_15 ;
if ( V_2 -> V_186 != V_195 )
return V_39 ;
V_15 = V_268 -> V_15 ;
V_21 = ( V_2 -> V_256 [ V_15 ] . V_258 & V_269 ) ;
V_21 |= ( V_15 << 8 ) ;
if ( F_59 ( V_2 , & V_21 , & V_23 ) )
return V_39 ;
V_21 &= ~ ( 0x0ff << 8 ) ;
V_21 |= ( V_15 << 8 ) ;
V_21 &= ~ ( V_270 | V_271 ) ;
switch ( V_268 -> V_186 ) {
case V_272 :
V_21 |= ( V_216 | V_273 | V_274 ) ;
V_23 |= ( V_269 | V_275 ) ;
if ( V_2 -> V_110 & V_276 )
V_23 |= ( V_270 | V_271 ) ;
if ( ! ( V_268 -> V_277 ) )
V_21 &= ~ V_216 ;
if ( ! ( V_268 -> V_278 ) )
V_21 &= ~ V_273 ;
if ( ! ( V_268 -> V_279 ) )
V_21 &= ~ V_274 ;
if ( ! ( V_268 -> V_280 ) )
V_23 &= ~ V_269 ;
if ( ! ( V_268 -> V_281 & V_269 ) )
V_23 &= ~ ( V_275 | V_270 | V_271 ) ;
if ( ! ( V_268 -> V_281 & V_275 ) )
V_23 &= ~ V_270 ;
if ( ! ( V_268 -> V_281 & V_270 ) )
V_23 &= ~ V_271 ;
break;
case V_282 :
V_21 |= ( V_270 | V_283 ) ;
V_21 |= ( V_268 -> V_284 << 16 ) ;
break;
case V_285 :
V_21 |= ( V_271 | V_283 ) ;
V_21 &= ~ ( 0x0ffff << 16 ) ;
break;
default:
return V_39 ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_20 . V_9 = V_286 ;
V_9 . V_20 . V_21 = V_21 ;
V_9 . V_20 . V_23 = V_23 ;
F_5 ( V_2 , & V_9 ) ;
V_39 = V_9 . V_3 . V_9 ;
if ( V_39 != V_34 ) {
F_10 ( & V_2 -> V_12 -> V_26 ,
L_37 , V_15 ) ;
} else {
F_14 ( & V_2 -> V_12 -> V_26 ,
L_38 , V_15 ) ;
}
return V_39 ;
}
int
F_61 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
T_1 V_21 , V_23 ;
T_7 V_258 ;
if ( V_2 -> V_186 == V_195 )
V_258 = V_2 -> V_256 [ V_268 -> V_15 ] . V_258 ;
else
V_258 = V_2 -> V_287 ;
V_21 = V_258 ;
V_21 |= ( V_268 -> V_15 << 8 ) ;
if ( F_59 ( V_2 , & V_21 , & V_23 ) )
return - V_52 ;
V_268 -> V_277 = ! ! ( V_21 & V_216 ) ;
V_268 -> V_288 = ! ! ( V_21 & V_283 ) ;
V_268 -> V_278 = ! ! ( V_21 & V_273 ) ;
V_268 -> V_279 = ! ! ( V_21 & V_274 ) ;
V_268 -> V_284 = F_62 ( V_21 >> 16 ) ;
V_268 -> V_280 = ( V_23 & 0x1 ) ;
V_268 -> V_281 = ( ( V_23 >> 1 ) & 0x7 ) ;
return 0 ;
}
