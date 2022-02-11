static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
int V_7 ;
if ( ! F_2 ( V_6 ) )
return;
switch ( V_1 -> V_8 ) {
case 0 :
V_3 -> V_9 = V_3 -> V_10 [ 1 ] ;
break;
case - V_11 :
case - V_12 :
case - V_13 :
return;
default:
F_3 ( V_6 , L_1 , V_1 -> V_8 ) ;
break;
}
V_7 = F_4 ( V_1 , V_14 ) ;
if ( V_7 == - V_15 )
F_5 ( V_6 ) ;
else if ( V_7 )
F_6 ( V_6 , L_2 , V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
struct V_23 * V_24 = & V_3 -> V_6 -> V_24 ;
V_21 = F_8 ( V_3 -> V_6 , & V_19 ) ;
if ( V_21 == NULL )
return;
V_19 -> V_25 = F_9 ( V_17 -> V_17 . V_26 . V_27 ) ;
V_19 -> V_28 = F_10 ( V_17 -> V_17 . V_26 . V_29 & 0xF ) ;
if ( V_17 -> type == V_30 ||
V_17 -> type == V_31 )
V_19 -> V_25 |= V_32 ;
if ( V_17 -> type == V_33 ||
V_17 -> type == V_31 ) {
V_19 -> V_25 |= V_34 ;
} else {
for ( V_22 = 0 ; V_22 < V_19 -> V_28 ; V_22 ++ )
V_19 -> V_35 [ V_22 ] = V_17 -> V_17 . V_26 . V_17 [ V_22 ] ;
}
F_11 ( V_21 ) ;
V_24 -> V_36 ++ ;
V_24 -> V_37 += V_19 -> V_28 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_23 * V_24 = & V_3 -> V_6 -> V_24 ;
V_21 = F_13 ( V_3 -> V_6 , & V_19 ) ;
if ( V_21 == NULL )
return;
if ( V_17 -> type == V_38 ) {
T_1 V_39 = V_17 -> V_17 . V_40 ;
if ( V_39 & V_41 ) {
V_3 -> V_42 . V_39 = V_43 ;
V_19 -> V_25 |= V_44 ;
V_3 -> V_42 . V_45 . V_46 ++ ;
F_14 ( V_3 -> V_6 ) ;
} else if ( V_39 & V_47 ) {
V_3 -> V_42 . V_39 = V_48 ;
V_3 -> V_42 . V_45 . V_49 ++ ;
} else {
V_3 -> V_42 . V_39 = V_50 ;
V_3 -> V_42 . V_45 . V_51 ++ ;
}
} else if ( V_17 -> type == V_52 ) {
T_1 V_53 = V_17 -> V_17 . error . V_54 . V_55 . V_56 . V_53 ;
T_1 V_57 = V_17 -> V_17 . error . V_54 . V_55 . V_56 . V_57 ;
T_1 V_58 = V_17 -> V_17 . error . V_54 . V_55 . V_56 . V_58 ;
V_3 -> V_42 . V_45 . V_59 ++ ;
V_24 -> V_60 ++ ;
V_19 -> V_25 |= V_61 | V_62 ;
switch ( V_53 & V_63 ) {
case V_64 :
V_19 -> V_35 [ 2 ] |= V_65 ;
break;
case V_66 :
V_19 -> V_35 [ 2 ] |= V_67 ;
break;
case V_68 :
V_19 -> V_35 [ 2 ] |= V_69 ;
break;
default:
V_19 -> V_35 [ 2 ] |= V_70 ;
V_19 -> V_35 [ 3 ] = V_53 & V_71 ;
break;
}
if ( ( V_53 & V_72 ) == 0 )
V_19 -> V_35 [ 2 ] |= V_73 ;
if ( V_3 -> V_42 . V_39 == V_48 ||
V_3 -> V_42 . V_39 == V_74 ) {
V_19 -> V_35 [ 1 ] = ( V_57 > V_58 ) ?
V_75 : V_76 ;
}
} else if ( V_17 -> type == V_77 ) {
V_19 -> V_25 |= V_78 ;
V_19 -> V_35 [ 1 ] = V_79 ;
V_24 -> V_80 ++ ;
V_24 -> V_60 ++ ;
}
F_11 ( V_21 ) ;
V_24 -> V_36 ++ ;
V_24 -> V_37 += V_19 -> V_28 ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 ;
int V_81 ;
V_6 = V_3 -> V_6 ;
if ( ! F_2 ( V_6 ) )
return;
switch ( V_1 -> V_8 ) {
case 0 :
break;
case - V_12 :
return;
default:
F_3 ( V_6 , L_3 , V_1 -> V_8 ) ;
goto V_82;
}
if ( V_1 -> V_83 > V_84 ) {
struct V_16 * V_17 ;
T_1 * V_85 = V_1 -> V_86 ;
T_1 V_87 , V_88 ;
V_87 = V_85 [ 0 ] & ~ 0x80 ;
V_88 = V_84 ;
while ( V_87 ) {
V_17 = (struct V_16 * ) & V_85 [ V_88 ] ;
switch ( V_17 -> type ) {
case V_38 :
F_12 ( V_3 , V_17 ) ;
break;
case V_89 :
case V_30 :
case V_33 :
case V_31 :
F_7 ( V_3 , V_17 ) ;
break;
case V_52 :
F_12 ( V_3 , V_17 ) ;
break;
case V_77 :
F_12 ( V_3 , V_17 ) ;
break;
}
V_88 += V_90 + V_17 -> V_29 ;
V_87 -- ;
if ( V_88 > V_1 -> V_91 ) {
F_6 ( V_6 , L_4 ) ;
break;
}
}
}
V_82:
F_16 ( V_1 , V_3 -> V_92 , F_17 ( V_3 -> V_92 , 2 ) ,
V_1 -> V_86 , V_93 ,
F_15 , V_3 ) ;
V_81 = F_4 ( V_1 , V_14 ) ;
if ( V_81 == - V_15 )
F_5 ( V_6 ) ;
else if ( V_81 )
F_6 ( V_6 ,
L_5 , V_81 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_94 * V_4 = V_1 -> V_4 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
F_19 ( ! V_4 ) ;
V_3 = V_4 -> V_3 ;
V_6 = V_3 -> V_6 ;
F_20 ( V_1 -> V_3 , V_1 -> V_91 ,
V_1 -> V_86 , V_1 -> V_95 ) ;
F_21 ( & V_3 -> V_96 ) ;
if ( ! F_2 ( V_6 ) )
return;
if ( V_1 -> V_8 )
F_3 ( V_6 , L_6 , V_1 -> V_8 ) ;
V_6 -> V_97 = V_98 ;
V_6 -> V_24 . V_99 ++ ;
V_6 -> V_24 . V_100 += V_4 -> V_101 ;
F_22 ( V_6 , V_4 -> V_102 ) ;
V_4 -> V_102 = V_103 ;
if ( F_23 ( V_6 ) )
F_24 ( V_6 ) ;
}
static int F_25 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
int V_83 ;
memcpy ( & V_3 -> V_104 [ V_84 ] , V_17 ,
V_17 -> V_29 + V_90 ) ;
memset ( & V_3 -> V_104 [ 0 ] , 0 , V_84 ) ;
return F_26 ( V_3 -> V_92 , F_27 ( V_3 -> V_92 , 2 ) ,
& V_3 -> V_104 [ 0 ] ,
V_17 -> V_29 + V_90 + V_84 ,
& V_83 , 1000 ) ;
}
static int F_28 ( struct V_2 * V_3 , T_1 V_105 )
{
V_3 -> V_106 . V_17 . V_107 . V_108 . V_56 . V_105 = V_105 ;
return F_25 ( V_3 , & V_3 -> V_106 ) ;
}
static int F_29 ( struct V_2 * V_3 , T_1 V_109 )
{
struct V_16 V_110 ;
V_110 . type = V_111 ;
V_110 . V_29 = V_90 + 1 ;
V_110 . V_112 = 0 ;
V_110 . V_17 . V_113 [ 0 ] = V_109 ;
return F_25 ( V_3 , & V_110 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_7 , V_22 ;
V_3 -> V_10 [ 0 ] = 0 ;
V_3 -> V_9 = 15 ;
for ( V_22 = 0 ; V_22 < V_114 ; V_22 ++ ) {
struct V_1 * V_1 = NULL ;
T_1 * V_115 = NULL ;
V_1 = F_31 ( 0 , V_116 ) ;
if ( ! V_1 ) {
F_6 ( V_6 , L_7 ) ;
V_7 = - V_117 ;
break;
}
V_115 = F_32 ( V_3 -> V_92 , V_93 , V_116 ,
& V_1 -> V_95 ) ;
if ( ! V_115 ) {
F_6 ( V_6 , L_8 ) ;
F_33 ( V_1 ) ;
V_7 = - V_117 ;
break;
}
F_16 ( V_1 , V_3 -> V_92 , F_17 ( V_3 -> V_92 , 2 ) ,
V_115 , V_93 ,
F_15 , V_3 ) ;
V_1 -> V_118 |= V_119 ;
F_34 ( V_1 , & V_3 -> V_120 ) ;
V_7 = F_4 ( V_1 , V_116 ) ;
if ( V_7 ) {
F_35 ( V_1 ) ;
F_20 ( V_3 -> V_92 , V_93 , V_115 ,
V_1 -> V_95 ) ;
F_33 ( V_1 ) ;
break;
}
F_33 ( V_1 ) ;
}
if ( V_22 == 0 ) {
F_36 ( V_6 , L_9 ) ;
return V_7 ;
}
if ( V_22 < V_114 )
F_36 ( V_6 , L_10 ) ;
F_37 ( V_3 -> V_121 , V_3 -> V_92 ,
F_38 ( V_3 -> V_92 , 1 ) ,
V_3 -> V_10 ,
V_122 ,
F_1 , V_3 , 1 ) ;
V_7 = F_4 ( V_3 -> V_121 , V_116 ) ;
if ( V_7 ) {
F_36 ( V_6 , L_11 , V_7 ) ;
return V_7 ;
}
V_7 = F_29 ( V_3 , V_123 | V_124 ) ;
if ( V_7 )
goto V_125;
V_7 = F_29 ( V_3 , V_126 | V_124 ) ;
if ( V_7 )
goto V_125;
V_7 = F_29 ( V_3 , V_127 | V_124 ) ;
if ( V_7 )
goto V_125;
V_7 = F_28 ( V_3 , V_128 ) ;
if ( V_7 )
goto V_125;
V_3 -> V_42 . V_39 = V_50 ;
return 0 ;
V_125:
F_36 ( V_6 , L_12 , V_7 ) ;
return V_7 ;
}
static void F_39 ( struct V_2 * V_3 )
{
int V_22 ;
F_40 ( V_3 -> V_121 ) ;
F_41 ( & V_3 -> V_120 ) ;
F_41 ( & V_3 -> V_129 ) ;
F_42 ( & V_3 -> V_96 , 0 ) ;
for ( V_22 = 0 ; V_22 < V_103 ; V_22 ++ )
V_3 -> V_130 [ V_22 ] . V_102 = V_103 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
int V_7 ;
V_7 = F_28 ( V_3 , V_131 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_45 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_30 ( V_3 ) ;
if ( V_7 ) {
if ( V_7 == - V_15 )
F_5 ( V_3 -> V_6 ) ;
F_36 ( V_6 , L_13 , V_7 ) ;
F_46 ( V_6 ) ;
return V_7 ;
}
F_47 ( V_6 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_20 * V_21 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
struct V_94 * V_4 = NULL ;
struct V_23 * V_24 = & V_6 -> V_24 ;
struct V_18 * V_19 = (struct V_18 * ) V_21 -> V_35 ;
struct V_16 * V_17 ;
struct V_1 * V_1 ;
T_1 * V_115 ;
int V_22 , V_7 ;
T_3 V_132 = V_84 + V_90
+ sizeof( struct V_133 ) ;
if ( F_49 ( V_6 , V_21 ) )
return V_134 ;
V_1 = F_31 ( 0 , V_14 ) ;
if ( ! V_1 ) {
F_6 ( V_6 , L_7 ) ;
goto V_135;
}
V_115 = F_32 ( V_3 -> V_92 , V_132 , V_14 , & V_1 -> V_95 ) ;
if ( ! V_115 ) {
F_6 ( V_6 , L_8 ) ;
F_33 ( V_1 ) ;
goto V_135;
}
V_17 = (struct V_16 * ) & V_115 [ V_84 ] ;
V_17 -> V_17 . V_26 . V_27 = V_19 -> V_25 & V_136 ;
V_17 -> V_17 . V_26 . V_29 = V_19 -> V_28 ;
if ( V_19 -> V_25 & V_34 ) {
V_17 -> type = V_19 -> V_25 & V_32 ?
V_137 : V_138 ;
V_17 -> V_29 = V_139 ;
} else {
V_17 -> type = V_19 -> V_25 & V_32 ?
V_140 : V_141 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_28 ; V_22 ++ )
V_17 -> V_17 . V_26 . V_17 [ V_22 ] = V_19 -> V_35 [ V_22 ] ;
V_17 -> V_29 = V_139 + V_19 -> V_28 ;
}
V_17 -> V_17 . V_26 . V_27 = F_50 ( V_17 -> V_17 . V_26 . V_27 ) ;
for ( V_22 = 0 ; V_22 < V_103 ; V_22 ++ ) {
if ( V_3 -> V_130 [ V_22 ] . V_102 == V_103 ) {
V_4 = & V_3 -> V_130 [ V_22 ] ;
break;
}
}
if ( ! V_4 ) {
F_20 ( V_3 -> V_92 , V_132 , V_115 , V_1 -> V_95 ) ;
F_33 ( V_1 ) ;
F_36 ( V_6 , L_14 ) ;
return V_142 ;
}
V_4 -> V_3 = V_3 ;
V_4 -> V_102 = V_22 ;
V_4 -> V_101 = V_19 -> V_28 ;
F_16 ( V_1 , V_3 -> V_92 , F_27 ( V_3 -> V_92 , 2 ) , V_115 ,
V_132 , F_18 , V_4 ) ;
V_1 -> V_118 |= V_119 ;
F_34 ( V_1 , & V_3 -> V_129 ) ;
F_51 ( V_21 , V_6 , V_4 -> V_102 ) ;
F_52 ( & V_3 -> V_96 ) ;
V_7 = F_4 ( V_1 , V_14 ) ;
if ( F_53 ( V_7 ) ) {
F_54 ( V_6 , V_4 -> V_102 ) ;
F_35 ( V_1 ) ;
F_20 ( V_3 -> V_92 , V_132 , V_115 , V_1 -> V_95 ) ;
F_55 ( V_21 ) ;
F_21 ( & V_3 -> V_96 ) ;
if ( V_7 == - V_15 ) {
F_5 ( V_6 ) ;
} else {
F_36 ( V_6 , L_15 , V_7 ) ;
V_24 -> V_143 ++ ;
}
} else {
V_6 -> V_97 = V_98 ;
if ( F_56 ( & V_3 -> V_96 ) >= V_103 ||
V_3 -> V_9 < 5 ) {
F_57 ( V_6 ) ;
}
}
F_33 ( V_1 ) ;
return V_134 ;
V_135:
F_55 ( V_21 ) ;
V_24 -> V_143 ++ ;
return V_134 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
F_39 ( V_3 ) ;
F_57 ( V_6 ) ;
if ( F_28 ( V_3 , V_131 ) )
F_36 ( V_6 , L_16 ) ;
F_46 ( V_6 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , enum V_144 V_105 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
switch ( V_105 ) {
case V_145 :
if ( F_28 ( V_3 , V_128 ) )
F_36 ( V_6 , L_17 ) ;
if ( F_23 ( V_6 ) )
F_24 ( V_6 ) ;
break;
default:
return - V_146 ;
}
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
struct V_147 * V_148 = & V_3 -> V_42 . V_149 ;
T_1 V_150 , V_151 ;
V_150 = ( ( V_148 -> V_152 - 1 ) & 0x3f ) | ( ( ( V_148 -> V_153 - 1 ) & 0x3 ) << 6 ) ;
V_151 = ( ( V_148 -> V_154 + V_148 -> V_155 - 1 ) & 0xf ) |
( ( ( V_148 -> V_156 - 1 ) & 0x7 ) << 4 ) ;
if ( V_3 -> V_42 . V_157 & V_158 )
V_151 |= 0x80 ;
F_3 ( V_6 , L_18 , V_150 , V_151 ) ;
V_3 -> V_106 . V_17 . V_107 . V_108 . V_56 . V_150 = V_150 ;
V_3 -> V_106 . V_17 . V_107 . V_108 . V_56 . V_151 = V_151 ;
return F_25 ( V_3 , & V_3 -> V_106 ) ;
}
static void F_61 ( struct V_16 * V_17 )
{
struct V_159 * V_56 =
& V_17 -> V_17 . V_107 . V_108 . V_56 ;
V_17 -> type = V_160 ;
V_17 -> V_29 = sizeof( struct V_161 ) ;
V_17 -> V_112 = 0 ;
V_17 -> V_17 . V_107 . V_162 = V_163 ;
V_56 -> V_164 = 0x00 ;
V_56 -> V_165 = 0x00 ;
V_56 -> V_166 = 0x00 ;
V_56 -> V_167 = 0x00 ;
V_56 -> V_168 = 0xFF ;
V_56 -> V_169 = 0xFF ;
V_56 -> V_170 = 0xFF ;
V_56 -> V_171 = 0xFF ;
V_56 -> V_150 = 0 ;
V_56 -> V_151 = 0 ;
V_56 -> V_172 = V_173 ;
V_56 -> V_105 = V_131 ;
}
static int F_62 ( struct V_174 * V_175 ,
const struct V_176 * V_27 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
int V_22 , V_7 = - V_117 ;
V_6 = F_63 ( sizeof( struct V_2 ) , V_103 ) ;
if ( ! V_6 ) {
F_64 ( & V_175 -> V_3 , L_19 ) ;
return - V_117 ;
}
V_3 = F_44 ( V_6 ) ;
V_3 -> V_92 = F_65 ( V_175 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_42 . V_39 = V_177 ;
V_3 -> V_42 . clock . V_178 = V_179 ;
V_3 -> V_42 . V_180 = & V_181 ;
V_3 -> V_42 . V_182 = F_60 ;
V_3 -> V_42 . V_183 = F_59 ;
V_3 -> V_42 . V_184 = V_158 ;
V_6 -> V_185 = & V_186 ;
V_6 -> V_187 |= V_188 ;
F_66 ( & V_3 -> V_120 ) ;
F_66 ( & V_3 -> V_129 ) ;
F_42 ( & V_3 -> V_96 , 0 ) ;
for ( V_22 = 0 ; V_22 < V_103 ; V_22 ++ )
V_3 -> V_130 [ V_22 ] . V_102 = V_103 ;
V_3 -> V_121 = F_31 ( 0 , V_116 ) ;
if ( ! V_3 -> V_121 ) {
F_64 ( & V_175 -> V_3 , L_20 ) ;
goto V_189;
}
V_3 -> V_10 = F_67 ( V_122 , V_116 ) ;
if ( ! V_3 -> V_10 )
goto V_190;
V_3 -> V_104 = F_67 ( V_84 +
sizeof( struct V_16 ) , V_116 ) ;
if ( ! V_3 -> V_104 )
goto V_191;
F_68 ( V_175 , V_3 ) ;
F_69 ( V_6 , & V_175 -> V_3 ) ;
F_61 ( & V_3 -> V_106 ) ;
V_7 = F_25 ( V_3 , & V_3 -> V_106 ) ;
if ( V_7 ) {
F_6 ( V_6 , L_21 , V_7 ) ;
goto V_192;
}
V_7 = F_70 ( V_6 ) ;
if ( V_7 ) {
F_6 ( V_6 , L_22 , V_7 ) ;
goto V_192;
}
return 0 ;
V_192:
F_71 ( V_3 -> V_104 ) ;
V_191:
F_71 ( V_3 -> V_10 ) ;
V_190:
F_33 ( V_3 -> V_121 ) ;
V_189:
F_72 ( V_6 ) ;
return V_7 ;
}
static void F_73 ( struct V_174 * V_175 )
{
struct V_2 * V_3 = F_74 ( V_175 ) ;
F_68 ( V_175 , NULL ) ;
if ( V_3 ) {
F_75 ( V_3 -> V_6 ) ;
F_72 ( V_3 -> V_6 ) ;
F_39 ( V_3 ) ;
F_33 ( V_3 -> V_121 ) ;
F_71 ( V_3 -> V_10 ) ;
}
}
