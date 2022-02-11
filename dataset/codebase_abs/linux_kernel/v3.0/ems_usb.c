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
F_3 ( V_6 -> V_3 . V_14 , L_1 ,
V_1 -> V_8 ) ;
break;
}
V_7 = F_4 ( V_1 , V_15 ) ;
if ( V_7 == - V_16 )
F_5 ( V_6 ) ;
else if ( V_7 )
F_6 ( V_6 -> V_3 . V_14 ,
L_2 , V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
struct V_24 * V_25 = & V_3 -> V_6 -> V_25 ;
V_22 = F_8 ( V_3 -> V_6 , & V_20 ) ;
if ( V_22 == NULL )
return;
V_20 -> V_26 = F_9 ( V_18 -> V_18 . V_27 . V_28 ) ;
V_20 -> V_29 = F_10 ( V_18 -> V_18 . V_27 . V_30 & 0xF ) ;
if ( V_18 -> type == V_31 ||
V_18 -> type == V_32 )
V_20 -> V_26 |= V_33 ;
if ( V_18 -> type == V_34 ||
V_18 -> type == V_32 ) {
V_20 -> V_26 |= V_35 ;
} else {
for ( V_23 = 0 ; V_23 < V_20 -> V_29 ; V_23 ++ )
V_20 -> V_36 [ V_23 ] = V_18 -> V_18 . V_27 . V_18 [ V_23 ] ;
}
F_11 ( V_22 ) ;
V_25 -> V_37 ++ ;
V_25 -> V_38 += V_20 -> V_29 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_24 * V_25 = & V_3 -> V_6 -> V_25 ;
V_22 = F_13 ( V_3 -> V_6 , & V_20 ) ;
if ( V_22 == NULL )
return;
if ( V_18 -> type == V_39 ) {
T_1 V_40 = V_18 -> V_18 . V_41 ;
if ( V_40 & V_42 ) {
V_3 -> V_43 . V_40 = V_44 ;
V_20 -> V_26 |= V_45 ;
F_14 ( V_3 -> V_6 ) ;
} else if ( V_40 & V_46 ) {
V_3 -> V_43 . V_40 = V_47 ;
V_3 -> V_43 . V_48 . V_49 ++ ;
} else {
V_3 -> V_43 . V_40 = V_50 ;
V_3 -> V_43 . V_48 . V_51 ++ ;
}
} else if ( V_18 -> type == V_52 ) {
T_1 V_53 = V_18 -> V_18 . error . V_54 . V_55 . V_56 . V_53 ;
T_1 V_57 = V_18 -> V_18 . error . V_54 . V_55 . V_56 . V_57 ;
T_1 V_58 = V_18 -> V_18 . error . V_54 . V_55 . V_56 . V_58 ;
V_3 -> V_43 . V_48 . V_59 ++ ;
V_25 -> V_60 ++ ;
V_20 -> V_26 |= V_61 | V_62 ;
switch ( V_53 & V_63 ) {
case V_64 :
V_20 -> V_36 [ 2 ] |= V_65 ;
break;
case V_66 :
V_20 -> V_36 [ 2 ] |= V_67 ;
break;
case V_68 :
V_20 -> V_36 [ 2 ] |= V_69 ;
break;
default:
V_20 -> V_36 [ 2 ] |= V_70 ;
V_20 -> V_36 [ 3 ] = V_53 & V_71 ;
break;
}
if ( ( V_53 & V_72 ) == 0 )
V_20 -> V_36 [ 2 ] |= V_73 ;
if ( V_3 -> V_43 . V_40 == V_47 ||
V_3 -> V_43 . V_40 == V_74 ) {
V_20 -> V_36 [ 1 ] = ( V_57 > V_58 ) ?
V_75 : V_76 ;
}
} else if ( V_18 -> type == V_77 ) {
V_20 -> V_26 |= V_78 ;
V_20 -> V_36 [ 1 ] = V_79 ;
V_25 -> V_80 ++ ;
V_25 -> V_60 ++ ;
}
F_11 ( V_22 ) ;
V_25 -> V_37 ++ ;
V_25 -> V_38 += V_20 -> V_29 ;
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
F_3 ( V_6 -> V_3 . V_14 , L_3 ,
V_1 -> V_8 ) ;
goto V_82;
}
if ( V_1 -> V_83 > V_84 ) {
struct V_17 * V_18 ;
T_1 * V_85 = V_1 -> V_86 ;
T_1 V_87 , V_88 , V_89 ;
V_87 = V_85 [ 0 ] & ~ 0x80 ;
V_88 = V_85 [ 0 ] & 0x80 ;
V_89 = V_84 ;
while ( V_87 ) {
V_18 = (struct V_17 * ) & V_85 [ V_89 ] ;
switch ( V_18 -> type ) {
case V_39 :
F_12 ( V_3 , V_18 ) ;
break;
case V_90 :
case V_31 :
case V_34 :
case V_32 :
F_7 ( V_3 , V_18 ) ;
break;
case V_52 :
F_12 ( V_3 , V_18 ) ;
break;
case V_77 :
F_12 ( V_3 , V_18 ) ;
break;
}
V_89 += V_91 + V_18 -> V_30 ;
V_87 -- ;
if ( V_89 > V_1 -> V_92 ) {
F_6 ( V_6 -> V_3 . V_14 , L_4 ) ;
break;
}
}
}
V_82:
F_16 ( V_1 , V_3 -> V_93 , F_17 ( V_3 -> V_93 , 2 ) ,
V_1 -> V_86 , V_94 ,
F_15 , V_3 ) ;
V_81 = F_4 ( V_1 , V_15 ) ;
if ( V_81 == - V_16 )
F_5 ( V_6 ) ;
else if ( V_81 )
F_6 ( V_6 -> V_3 . V_14 ,
L_5 , V_81 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_95 * V_4 = V_1 -> V_4 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
F_19 ( ! V_4 ) ;
V_3 = V_4 -> V_3 ;
V_6 = V_3 -> V_6 ;
F_20 ( V_1 -> V_3 , V_1 -> V_92 ,
V_1 -> V_86 , V_1 -> V_96 ) ;
F_21 ( & V_3 -> V_97 ) ;
if ( ! F_2 ( V_6 ) )
return;
if ( V_1 -> V_8 )
F_3 ( V_6 -> V_3 . V_14 , L_6 ,
V_1 -> V_8 ) ;
V_6 -> V_98 = V_99 ;
V_6 -> V_25 . V_100 ++ ;
V_6 -> V_25 . V_101 += V_4 -> V_102 ;
F_22 ( V_6 , V_4 -> V_103 ) ;
V_4 -> V_103 = V_104 ;
if ( F_23 ( V_6 ) )
F_24 ( V_6 ) ;
}
static int F_25 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_83 ;
memcpy ( & V_3 -> V_105 [ V_84 ] , V_18 ,
V_18 -> V_30 + V_91 ) ;
memset ( & V_3 -> V_105 [ 0 ] , 0 , V_84 ) ;
return F_26 ( V_3 -> V_93 , F_27 ( V_3 -> V_93 , 2 ) ,
& V_3 -> V_105 [ 0 ] ,
V_18 -> V_30 + V_91 + V_84 ,
& V_83 , 1000 ) ;
}
static int F_28 ( struct V_2 * V_3 , T_1 V_106 )
{
V_3 -> V_107 . V_18 . V_108 . V_109 . V_56 . V_106 = V_106 ;
return F_25 ( V_3 , & V_3 -> V_107 ) ;
}
static int F_29 ( struct V_2 * V_3 , T_1 V_110 )
{
struct V_17 V_111 ;
V_111 . type = V_112 ;
V_111 . V_30 = V_91 + 1 ;
V_111 . V_113 = 0 ;
V_111 . V_18 . V_114 [ 0 ] = V_110 ;
return F_25 ( V_3 , & V_111 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_7 , V_23 ;
V_3 -> V_10 [ 0 ] = 0 ;
V_3 -> V_9 = 15 ;
for ( V_23 = 0 ; V_23 < V_115 ; V_23 ++ ) {
struct V_1 * V_1 = NULL ;
T_1 * V_116 = NULL ;
V_1 = F_31 ( 0 , V_117 ) ;
if ( ! V_1 ) {
F_6 ( V_6 -> V_3 . V_14 ,
L_7 ) ;
return - V_118 ;
}
V_116 = F_32 ( V_3 -> V_93 , V_94 , V_117 ,
& V_1 -> V_96 ) ;
if ( ! V_116 ) {
F_6 ( V_6 -> V_3 . V_14 ,
L_8 ) ;
F_33 ( V_1 ) ;
return - V_118 ;
}
F_16 ( V_1 , V_3 -> V_93 , F_17 ( V_3 -> V_93 , 2 ) ,
V_116 , V_94 ,
F_15 , V_3 ) ;
V_1 -> V_119 |= V_120 ;
F_34 ( V_1 , & V_3 -> V_121 ) ;
V_7 = F_4 ( V_1 , V_117 ) ;
if ( V_7 ) {
if ( V_7 == - V_16 )
F_5 ( V_3 -> V_6 ) ;
F_35 ( V_1 ) ;
F_20 ( V_3 -> V_93 , V_94 , V_116 ,
V_1 -> V_96 ) ;
break;
}
F_33 ( V_1 ) ;
}
if ( V_23 == 0 ) {
F_36 ( V_6 -> V_3 . V_14 , L_9 ) ;
return V_7 ;
}
if ( V_23 < V_115 )
F_36 ( V_6 -> V_3 . V_14 , L_10 ) ;
F_37 ( V_3 -> V_122 , V_3 -> V_93 ,
F_38 ( V_3 -> V_93 , 1 ) ,
V_3 -> V_10 ,
V_123 ,
F_1 , V_3 , 1 ) ;
V_7 = F_4 ( V_3 -> V_122 , V_117 ) ;
if ( V_7 ) {
if ( V_7 == - V_16 )
F_5 ( V_3 -> V_6 ) ;
F_36 ( V_6 -> V_3 . V_14 , L_11 ,
V_7 ) ;
return V_7 ;
}
V_7 = F_29 ( V_3 , V_124 | V_125 ) ;
if ( V_7 )
goto V_126;
V_7 = F_29 ( V_3 , V_127 | V_125 ) ;
if ( V_7 )
goto V_126;
V_7 = F_29 ( V_3 , V_128 | V_125 ) ;
if ( V_7 )
goto V_126;
V_7 = F_28 ( V_3 , V_129 ) ;
if ( V_7 )
goto V_126;
V_3 -> V_43 . V_40 = V_50 ;
return 0 ;
V_126:
if ( V_7 == - V_16 )
F_5 ( V_3 -> V_6 ) ;
F_36 ( V_6 -> V_3 . V_14 , L_12 , V_7 ) ;
return V_7 ;
}
static void F_39 ( struct V_2 * V_3 )
{
int V_23 ;
F_40 ( V_3 -> V_122 ) ;
F_41 ( & V_3 -> V_121 ) ;
F_41 ( & V_3 -> V_130 ) ;
F_42 ( & V_3 -> V_97 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_104 ; V_23 ++ )
V_3 -> V_131 [ V_23 ] . V_103 = V_104 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
int V_7 ;
V_7 = F_28 ( V_3 , V_132 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_45 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_30 ( V_3 ) ;
if ( V_7 ) {
if ( V_7 == - V_16 )
F_5 ( V_3 -> V_6 ) ;
F_36 ( V_6 -> V_3 . V_14 , L_13 ,
V_7 ) ;
F_46 ( V_6 ) ;
return V_7 ;
}
V_3 -> V_133 = V_99 ;
F_47 ( V_6 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_21 * V_22 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
struct V_95 * V_4 = NULL ;
struct V_24 * V_25 = & V_6 -> V_25 ;
struct V_19 * V_20 = (struct V_19 * ) V_22 -> V_36 ;
struct V_17 * V_18 ;
struct V_1 * V_1 ;
T_1 * V_116 ;
int V_23 , V_7 ;
T_3 V_134 = V_84 + V_91
+ sizeof( struct V_135 ) ;
if ( F_49 ( V_6 , V_22 ) )
return V_136 ;
V_1 = F_31 ( 0 , V_15 ) ;
if ( ! V_1 ) {
F_6 ( V_6 -> V_3 . V_14 , L_7 ) ;
goto V_137;
}
V_116 = F_32 ( V_3 -> V_93 , V_134 , V_15 , & V_1 -> V_96 ) ;
if ( ! V_116 ) {
F_6 ( V_6 -> V_3 . V_14 , L_8 ) ;
F_33 ( V_1 ) ;
goto V_137;
}
V_18 = (struct V_17 * ) & V_116 [ V_84 ] ;
V_18 -> V_18 . V_27 . V_28 = V_20 -> V_26 & V_138 ;
V_18 -> V_18 . V_27 . V_30 = V_20 -> V_29 ;
if ( V_20 -> V_26 & V_35 ) {
V_18 -> type = V_20 -> V_26 & V_33 ?
V_139 : V_140 ;
V_18 -> V_30 = V_141 ;
} else {
V_18 -> type = V_20 -> V_26 & V_33 ?
V_142 : V_143 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_29 ; V_23 ++ )
V_18 -> V_18 . V_27 . V_18 [ V_23 ] = V_20 -> V_36 [ V_23 ] ;
V_18 -> V_30 = V_141 + V_20 -> V_29 ;
}
V_18 -> V_18 . V_27 . V_28 = F_50 ( V_18 -> V_18 . V_27 . V_28 ) ;
for ( V_23 = 0 ; V_23 < V_104 ; V_23 ++ ) {
if ( V_3 -> V_131 [ V_23 ] . V_103 == V_104 ) {
V_4 = & V_3 -> V_131 [ V_23 ] ;
break;
}
}
if ( ! V_4 ) {
F_35 ( V_1 ) ;
F_20 ( V_3 -> V_93 , V_134 , V_116 , V_1 -> V_96 ) ;
F_36 ( V_6 -> V_3 . V_14 , L_14 ) ;
return V_144 ;
}
V_4 -> V_3 = V_3 ;
V_4 -> V_103 = V_23 ;
V_4 -> V_102 = V_20 -> V_29 ;
F_16 ( V_1 , V_3 -> V_93 , F_27 ( V_3 -> V_93 , 2 ) , V_116 ,
V_134 , F_18 , V_4 ) ;
V_1 -> V_119 |= V_120 ;
F_34 ( V_1 , & V_3 -> V_130 ) ;
F_51 ( V_22 , V_6 , V_4 -> V_103 ) ;
F_52 ( & V_3 -> V_97 ) ;
V_7 = F_4 ( V_1 , V_15 ) ;
if ( F_53 ( V_7 ) ) {
F_54 ( V_6 , V_4 -> V_103 ) ;
F_35 ( V_1 ) ;
F_20 ( V_3 -> V_93 , V_134 , V_116 , V_1 -> V_96 ) ;
F_55 ( V_22 ) ;
F_21 ( & V_3 -> V_97 ) ;
if ( V_7 == - V_16 ) {
F_5 ( V_6 ) ;
} else {
F_36 ( V_6 -> V_3 . V_14 , L_15 , V_7 ) ;
V_25 -> V_145 ++ ;
}
} else {
V_6 -> V_98 = V_99 ;
if ( F_56 ( & V_3 -> V_97 ) >= V_104 ||
V_3 -> V_9 < 5 ) {
F_57 ( V_6 ) ;
}
}
F_33 ( V_1 ) ;
return V_136 ;
V_137:
F_55 ( V_22 ) ;
V_25 -> V_145 ++ ;
return V_136 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
F_39 ( V_3 ) ;
F_57 ( V_6 ) ;
if ( F_28 ( V_3 , V_132 ) )
F_36 ( V_6 -> V_3 . V_14 , L_16 ) ;
F_46 ( V_6 ) ;
V_3 -> V_133 = 0 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , enum V_146 V_106 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
if ( ! V_3 -> V_133 )
return - V_147 ;
switch ( V_106 ) {
case V_148 :
if ( F_28 ( V_3 , V_129 ) )
F_36 ( V_6 -> V_3 . V_14 , L_17 ) ;
if ( F_23 ( V_6 ) )
F_24 ( V_6 ) ;
break;
default:
return - V_149 ;
}
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_44 ( V_6 ) ;
struct V_150 * V_151 = & V_3 -> V_43 . V_152 ;
T_1 V_153 , V_154 ;
V_153 = ( ( V_151 -> V_155 - 1 ) & 0x3f ) | ( ( ( V_151 -> V_156 - 1 ) & 0x3 ) << 6 ) ;
V_154 = ( ( V_151 -> V_157 + V_151 -> V_158 - 1 ) & 0xf ) |
( ( ( V_151 -> V_159 - 1 ) & 0x7 ) << 4 ) ;
if ( V_3 -> V_43 . V_160 & V_161 )
V_154 |= 0x80 ;
F_3 ( V_6 -> V_3 . V_14 , L_18 ,
V_153 , V_154 ) ;
V_3 -> V_107 . V_18 . V_108 . V_109 . V_56 . V_153 = V_153 ;
V_3 -> V_107 . V_18 . V_108 . V_109 . V_56 . V_154 = V_154 ;
return F_25 ( V_3 , & V_3 -> V_107 ) ;
}
static void F_61 ( struct V_17 * V_18 )
{
struct V_162 * V_56 =
& V_18 -> V_18 . V_108 . V_109 . V_56 ;
V_18 -> type = V_163 ;
V_18 -> V_30 = sizeof( struct V_164 ) ;
V_18 -> V_113 = 0 ;
V_18 -> V_18 . V_108 . V_165 = V_166 ;
V_56 -> V_167 = 0x00 ;
V_56 -> V_168 = 0x00 ;
V_56 -> V_169 = 0x00 ;
V_56 -> V_170 = 0x00 ;
V_56 -> V_171 = 0xFF ;
V_56 -> V_172 = 0xFF ;
V_56 -> V_173 = 0xFF ;
V_56 -> V_174 = 0xFF ;
V_56 -> V_153 = 0 ;
V_56 -> V_154 = 0 ;
V_56 -> V_175 = V_176 ;
V_56 -> V_106 = V_132 ;
}
static int F_62 ( struct V_177 * V_178 ,
const struct V_179 * V_28 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
int V_23 , V_7 = - V_118 ;
V_6 = F_63 ( sizeof( struct V_2 ) , V_104 ) ;
if ( ! V_6 ) {
F_6 ( & V_178 -> V_3 , L_19 ) ;
return - V_118 ;
}
V_3 = F_44 ( V_6 ) ;
V_3 -> V_93 = F_64 ( V_178 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_43 . V_40 = V_180 ;
V_3 -> V_43 . clock . V_181 = V_182 ;
V_3 -> V_43 . V_183 = & V_184 ;
V_3 -> V_43 . V_185 = F_60 ;
V_3 -> V_43 . V_186 = F_59 ;
V_3 -> V_43 . V_187 = V_161 ;
V_6 -> V_188 = & V_189 ;
V_6 -> V_190 |= V_191 ;
F_65 ( & V_3 -> V_121 ) ;
F_65 ( & V_3 -> V_130 ) ;
F_42 ( & V_3 -> V_97 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_104 ; V_23 ++ )
V_3 -> V_131 [ V_23 ] . V_103 = V_104 ;
V_3 -> V_122 = F_31 ( 0 , V_117 ) ;
if ( ! V_3 -> V_122 ) {
F_6 ( & V_178 -> V_3 , L_20 ) ;
goto V_192;
}
V_3 -> V_10 = F_66 ( V_123 , V_117 ) ;
if ( ! V_3 -> V_10 ) {
F_6 ( & V_178 -> V_3 , L_21 ) ;
goto V_193;
}
V_3 -> V_105 = F_66 ( V_84 +
sizeof( struct V_17 ) , V_117 ) ;
if ( ! V_3 -> V_105 ) {
F_6 ( & V_178 -> V_3 , L_22 ) ;
goto V_194;
}
F_67 ( V_178 , V_3 ) ;
F_68 ( V_6 , & V_178 -> V_3 ) ;
F_61 ( & V_3 -> V_107 ) ;
V_7 = F_25 ( V_3 , & V_3 -> V_107 ) ;
if ( V_7 ) {
F_6 ( V_6 -> V_3 . V_14 ,
L_23 , V_7 ) ;
goto V_195;
}
V_7 = F_69 ( V_6 ) ;
if ( V_7 ) {
F_6 ( V_6 -> V_3 . V_14 ,
L_24 , V_7 ) ;
goto V_195;
}
return 0 ;
V_195:
F_70 ( V_3 -> V_105 ) ;
V_194:
F_70 ( V_3 -> V_10 ) ;
V_193:
F_33 ( V_3 -> V_122 ) ;
V_192:
F_71 ( V_6 ) ;
return V_7 ;
}
static void F_72 ( struct V_177 * V_178 )
{
struct V_2 * V_3 = F_73 ( V_178 ) ;
F_67 ( V_178 , NULL ) ;
if ( V_3 ) {
F_74 ( V_3 -> V_6 ) ;
F_71 ( V_3 -> V_6 ) ;
F_39 ( V_3 ) ;
F_33 ( V_3 -> V_122 ) ;
F_70 ( V_3 -> V_10 ) ;
}
}
static int T_4 F_75 ( void )
{
int V_7 ;
F_76 ( V_196 L_25 ) ;
V_7 = F_77 ( & V_197 ) ;
if ( V_7 ) {
V_7 ( L_26 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static void T_5 F_78 ( void )
{
F_79 ( & V_197 ) ;
}
