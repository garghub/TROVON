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
if ( V_3 -> V_9 > V_11 &&
F_3 ( V_6 ) )
F_4 ( V_6 ) ;
break;
case - V_12 :
case - V_13 :
case - V_14 :
return;
default:
F_5 ( V_6 , L_1 , V_1 -> V_8 ) ;
break;
}
V_7 = F_6 ( V_1 , V_15 ) ;
if ( V_7 == - V_16 )
F_7 ( V_6 ) ;
else if ( V_7 )
F_8 ( V_6 , L_2 , V_7 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
struct V_24 * V_25 = & V_3 -> V_6 -> V_25 ;
V_22 = F_10 ( V_3 -> V_6 , & V_20 ) ;
if ( V_22 == NULL )
return;
V_20 -> V_26 = F_11 ( V_18 -> V_18 . V_27 . V_28 ) ;
V_20 -> V_29 = F_12 ( V_18 -> V_18 . V_27 . V_30 & 0xF ) ;
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
V_25 -> V_37 ++ ;
V_25 -> V_38 += V_20 -> V_29 ;
F_13 ( V_22 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_24 * V_25 = & V_3 -> V_6 -> V_25 ;
V_22 = F_15 ( V_3 -> V_6 , & V_20 ) ;
if ( V_22 == NULL )
return;
if ( V_18 -> type == V_39 ) {
T_1 V_40 = V_18 -> V_18 . V_41 ;
if ( V_40 & V_42 ) {
V_3 -> V_43 . V_40 = V_44 ;
V_20 -> V_26 |= V_45 ;
V_3 -> V_43 . V_46 . V_47 ++ ;
F_16 ( V_3 -> V_6 ) ;
} else if ( V_40 & V_48 ) {
V_3 -> V_43 . V_40 = V_49 ;
V_3 -> V_43 . V_46 . V_50 ++ ;
} else {
V_3 -> V_43 . V_40 = V_51 ;
V_3 -> V_43 . V_46 . V_52 ++ ;
}
} else if ( V_18 -> type == V_53 ) {
T_1 V_54 = V_18 -> V_18 . error . V_55 . V_56 . V_57 . V_54 ;
T_1 V_58 = V_18 -> V_18 . error . V_55 . V_56 . V_57 . V_58 ;
T_1 V_59 = V_18 -> V_18 . error . V_55 . V_56 . V_57 . V_59 ;
V_3 -> V_43 . V_46 . V_60 ++ ;
V_25 -> V_61 ++ ;
V_20 -> V_26 |= V_62 | V_63 ;
switch ( V_54 & V_64 ) {
case V_65 :
V_20 -> V_36 [ 2 ] |= V_66 ;
break;
case V_67 :
V_20 -> V_36 [ 2 ] |= V_68 ;
break;
case V_69 :
V_20 -> V_36 [ 2 ] |= V_70 ;
break;
default:
V_20 -> V_36 [ 3 ] = V_54 & V_71 ;
break;
}
if ( ( V_54 & V_72 ) == 0 )
V_20 -> V_36 [ 2 ] |= V_73 ;
if ( V_3 -> V_43 . V_40 == V_49 ||
V_3 -> V_43 . V_40 == V_74 ) {
V_20 -> V_36 [ 1 ] = ( V_58 > V_59 ) ?
V_75 : V_76 ;
}
} else if ( V_18 -> type == V_77 ) {
V_20 -> V_26 |= V_78 ;
V_20 -> V_36 [ 1 ] = V_79 ;
V_25 -> V_80 ++ ;
V_25 -> V_61 ++ ;
}
V_25 -> V_37 ++ ;
V_25 -> V_38 += V_20 -> V_29 ;
F_13 ( V_22 ) ;
}
static void F_17 ( struct V_1 * V_1 )
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
case - V_13 :
return;
default:
F_5 ( V_6 , L_3 , V_1 -> V_8 ) ;
goto V_82;
}
if ( V_1 -> V_83 > V_84 ) {
struct V_17 * V_18 ;
T_1 * V_85 = V_1 -> V_86 ;
T_1 V_87 , V_88 ;
V_87 = V_85 [ 0 ] & ~ 0x80 ;
V_88 = V_84 ;
while ( V_87 ) {
V_18 = (struct V_17 * ) & V_85 [ V_88 ] ;
switch ( V_18 -> type ) {
case V_39 :
F_14 ( V_3 , V_18 ) ;
break;
case V_89 :
case V_31 :
case V_34 :
case V_32 :
F_9 ( V_3 , V_18 ) ;
break;
case V_53 :
F_14 ( V_3 , V_18 ) ;
break;
case V_77 :
F_14 ( V_3 , V_18 ) ;
break;
}
V_88 += V_90 + V_18 -> V_30 ;
V_87 -- ;
if ( V_88 > V_1 -> V_91 ) {
F_8 ( V_6 , L_4 ) ;
break;
}
}
}
V_82:
F_18 ( V_1 , V_3 -> V_92 , F_19 ( V_3 -> V_92 , 2 ) ,
V_1 -> V_86 , V_93 ,
F_17 , V_3 ) ;
V_81 = F_6 ( V_1 , V_15 ) ;
if ( V_81 == - V_16 )
F_7 ( V_6 ) ;
else if ( V_81 )
F_8 ( V_6 ,
L_5 , V_81 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_94 * V_4 = V_1 -> V_4 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
F_21 ( ! V_4 ) ;
V_3 = V_4 -> V_3 ;
V_6 = V_3 -> V_6 ;
F_22 ( V_1 -> V_3 , V_1 -> V_91 ,
V_1 -> V_86 , V_1 -> V_95 ) ;
F_23 ( & V_3 -> V_96 ) ;
if ( ! F_2 ( V_6 ) )
return;
if ( V_1 -> V_8 )
F_5 ( V_6 , L_6 , V_1 -> V_8 ) ;
F_24 ( V_6 ) ;
V_6 -> V_25 . V_97 ++ ;
V_6 -> V_25 . V_98 += V_4 -> V_99 ;
F_25 ( V_6 , V_4 -> V_100 ) ;
V_4 -> V_100 = V_101 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_83 ;
memcpy ( & V_3 -> V_102 [ V_84 ] , V_18 ,
V_18 -> V_30 + V_90 ) ;
memset ( & V_3 -> V_102 [ 0 ] , 0 , V_84 ) ;
return F_27 ( V_3 -> V_92 , F_28 ( V_3 -> V_92 , 2 ) ,
& V_3 -> V_102 [ 0 ] ,
V_18 -> V_30 + V_90 + V_84 ,
& V_83 , 1000 ) ;
}
static int F_29 ( struct V_2 * V_3 , T_1 V_103 )
{
V_3 -> V_104 . V_18 . V_105 . V_106 . V_57 . V_103 = V_103 ;
return F_26 ( V_3 , & V_3 -> V_104 ) ;
}
static int F_30 ( struct V_2 * V_3 , T_1 V_107 )
{
struct V_17 V_108 ;
V_108 . type = V_109 ;
V_108 . V_30 = V_90 + 1 ;
V_108 . V_110 = 0 ;
V_108 . V_18 . V_111 [ 0 ] = V_107 ;
return F_26 ( V_3 , & V_108 ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
int V_7 , V_23 ;
V_3 -> V_10 [ 0 ] = 0 ;
V_3 -> V_9 = 50 ;
for ( V_23 = 0 ; V_23 < V_112 ; V_23 ++ ) {
struct V_1 * V_1 = NULL ;
T_1 * V_113 = NULL ;
V_1 = F_32 ( 0 , V_114 ) ;
if ( ! V_1 ) {
F_8 ( V_6 , L_7 ) ;
V_7 = - V_115 ;
break;
}
V_113 = F_33 ( V_3 -> V_92 , V_93 , V_114 ,
& V_1 -> V_95 ) ;
if ( ! V_113 ) {
F_8 ( V_6 , L_8 ) ;
F_34 ( V_1 ) ;
V_7 = - V_115 ;
break;
}
F_18 ( V_1 , V_3 -> V_92 , F_19 ( V_3 -> V_92 , 2 ) ,
V_113 , V_93 ,
F_17 , V_3 ) ;
V_1 -> V_116 |= V_117 ;
F_35 ( V_1 , & V_3 -> V_118 ) ;
V_7 = F_6 ( V_1 , V_114 ) ;
if ( V_7 ) {
F_36 ( V_1 ) ;
F_22 ( V_3 -> V_92 , V_93 , V_113 ,
V_1 -> V_95 ) ;
F_34 ( V_1 ) ;
break;
}
F_34 ( V_1 ) ;
}
if ( V_23 == 0 ) {
F_37 ( V_6 , L_9 ) ;
return V_7 ;
}
if ( V_23 < V_112 )
F_37 ( V_6 , L_10 ) ;
F_38 ( V_3 -> V_119 , V_3 -> V_92 ,
F_39 ( V_3 -> V_92 , 1 ) ,
V_3 -> V_10 ,
V_120 ,
F_1 , V_3 , 1 ) ;
V_7 = F_6 ( V_3 -> V_119 , V_114 ) ;
if ( V_7 ) {
F_37 ( V_6 , L_11 , V_7 ) ;
return V_7 ;
}
V_7 = F_30 ( V_3 , V_121 | V_122 ) ;
if ( V_7 )
goto V_123;
V_7 = F_30 ( V_3 , V_124 | V_122 ) ;
if ( V_7 )
goto V_123;
V_7 = F_30 ( V_3 , V_125 | V_122 ) ;
if ( V_7 )
goto V_123;
V_7 = F_29 ( V_3 , V_126 ) ;
if ( V_7 )
goto V_123;
V_3 -> V_43 . V_40 = V_51 ;
return 0 ;
V_123:
F_37 ( V_6 , L_12 , V_7 ) ;
return V_7 ;
}
static void F_40 ( struct V_2 * V_3 )
{
int V_23 ;
F_41 ( V_3 -> V_119 ) ;
F_42 ( & V_3 -> V_118 ) ;
F_42 ( & V_3 -> V_127 ) ;
F_43 ( & V_3 -> V_96 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_101 ; V_23 ++ )
V_3 -> V_128 [ V_23 ] . V_100 = V_101 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_45 ( V_6 ) ;
int V_7 ;
V_7 = F_29 ( V_3 , V_129 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_46 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_31 ( V_3 ) ;
if ( V_7 ) {
if ( V_7 == - V_16 )
F_7 ( V_3 -> V_6 ) ;
F_37 ( V_6 , L_13 , V_7 ) ;
F_47 ( V_6 ) ;
return V_7 ;
}
F_48 ( V_6 ) ;
return 0 ;
}
static T_2 F_49 ( struct V_21 * V_22 , struct V_5 * V_6 )
{
struct V_2 * V_3 = F_45 ( V_6 ) ;
struct V_94 * V_4 = NULL ;
struct V_24 * V_25 = & V_6 -> V_25 ;
struct V_19 * V_20 = (struct V_19 * ) V_22 -> V_36 ;
struct V_17 * V_18 ;
struct V_1 * V_1 ;
T_1 * V_113 ;
int V_23 , V_7 ;
T_3 V_130 = V_84 + V_90
+ sizeof( struct V_131 ) ;
if ( F_50 ( V_6 , V_22 ) )
return V_132 ;
V_1 = F_32 ( 0 , V_15 ) ;
if ( ! V_1 ) {
F_8 ( V_6 , L_7 ) ;
goto V_133;
}
V_113 = F_33 ( V_3 -> V_92 , V_130 , V_15 , & V_1 -> V_95 ) ;
if ( ! V_113 ) {
F_8 ( V_6 , L_8 ) ;
F_34 ( V_1 ) ;
goto V_133;
}
V_18 = (struct V_17 * ) & V_113 [ V_84 ] ;
V_18 -> V_18 . V_27 . V_28 = F_51 ( V_20 -> V_26 & V_134 ) ;
V_18 -> V_18 . V_27 . V_30 = V_20 -> V_29 ;
if ( V_20 -> V_26 & V_35 ) {
V_18 -> type = V_20 -> V_26 & V_33 ?
V_135 : V_136 ;
V_18 -> V_30 = V_137 ;
} else {
V_18 -> type = V_20 -> V_26 & V_33 ?
V_138 : V_139 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_29 ; V_23 ++ )
V_18 -> V_18 . V_27 . V_18 [ V_23 ] = V_20 -> V_36 [ V_23 ] ;
V_18 -> V_30 = V_137 + V_20 -> V_29 ;
}
for ( V_23 = 0 ; V_23 < V_101 ; V_23 ++ ) {
if ( V_3 -> V_128 [ V_23 ] . V_100 == V_101 ) {
V_4 = & V_3 -> V_128 [ V_23 ] ;
break;
}
}
if ( ! V_4 ) {
F_22 ( V_3 -> V_92 , V_130 , V_113 , V_1 -> V_95 ) ;
F_34 ( V_1 ) ;
F_37 ( V_6 , L_14 ) ;
return V_140 ;
}
V_4 -> V_3 = V_3 ;
V_4 -> V_100 = V_23 ;
V_4 -> V_99 = V_20 -> V_29 ;
F_18 ( V_1 , V_3 -> V_92 , F_28 ( V_3 -> V_92 , 2 ) , V_113 ,
V_130 , F_20 , V_4 ) ;
V_1 -> V_116 |= V_117 ;
F_35 ( V_1 , & V_3 -> V_127 ) ;
F_52 ( V_22 , V_6 , V_4 -> V_100 ) ;
F_53 ( & V_3 -> V_96 ) ;
V_7 = F_6 ( V_1 , V_15 ) ;
if ( F_54 ( V_7 ) ) {
F_55 ( V_6 , V_4 -> V_100 ) ;
F_36 ( V_1 ) ;
F_22 ( V_3 -> V_92 , V_130 , V_113 , V_1 -> V_95 ) ;
F_56 ( V_22 ) ;
F_23 ( & V_3 -> V_96 ) ;
if ( V_7 == - V_16 ) {
F_7 ( V_6 ) ;
} else {
F_37 ( V_6 , L_15 , V_7 ) ;
V_25 -> V_141 ++ ;
}
} else {
F_24 ( V_6 ) ;
if ( F_57 ( & V_3 -> V_96 ) >= V_101 ||
V_3 -> V_9 < V_142 ) {
F_58 ( V_6 ) ;
}
}
F_34 ( V_1 ) ;
return V_132 ;
V_133:
F_56 ( V_22 ) ;
V_25 -> V_141 ++ ;
return V_132 ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_45 ( V_6 ) ;
F_40 ( V_3 ) ;
F_58 ( V_6 ) ;
if ( F_29 ( V_3 , V_129 ) )
F_37 ( V_6 , L_16 ) ;
F_47 ( V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 , enum V_143 V_103 )
{
struct V_2 * V_3 = F_45 ( V_6 ) ;
switch ( V_103 ) {
case V_144 :
if ( F_29 ( V_3 , V_126 ) )
F_37 ( V_6 , L_17 ) ;
if ( F_3 ( V_6 ) )
F_4 ( V_6 ) ;
break;
default:
return - V_145 ;
}
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_45 ( V_6 ) ;
struct V_146 * V_147 = & V_3 -> V_43 . V_148 ;
T_1 V_149 , V_150 ;
V_149 = ( ( V_147 -> V_151 - 1 ) & 0x3f ) | ( ( ( V_147 -> V_152 - 1 ) & 0x3 ) << 6 ) ;
V_150 = ( ( V_147 -> V_153 + V_147 -> V_154 - 1 ) & 0xf ) |
( ( ( V_147 -> V_155 - 1 ) & 0x7 ) << 4 ) ;
if ( V_3 -> V_43 . V_156 & V_157 )
V_150 |= 0x80 ;
F_5 ( V_6 , L_18 , V_149 , V_150 ) ;
V_3 -> V_104 . V_18 . V_105 . V_106 . V_57 . V_149 = V_149 ;
V_3 -> V_104 . V_18 . V_105 . V_106 . V_57 . V_150 = V_150 ;
return F_26 ( V_3 , & V_3 -> V_104 ) ;
}
static void F_62 ( struct V_17 * V_18 )
{
struct V_158 * V_57 =
& V_18 -> V_18 . V_105 . V_106 . V_57 ;
V_18 -> type = V_159 ;
V_18 -> V_30 = sizeof( struct V_160 ) ;
V_18 -> V_110 = 0 ;
V_18 -> V_18 . V_105 . V_161 = V_162 ;
V_57 -> V_163 = 0x00 ;
V_57 -> V_164 = 0x00 ;
V_57 -> V_165 = 0x00 ;
V_57 -> V_166 = 0x00 ;
V_57 -> V_167 = 0xFF ;
V_57 -> V_168 = 0xFF ;
V_57 -> V_169 = 0xFF ;
V_57 -> V_170 = 0xFF ;
V_57 -> V_149 = 0 ;
V_57 -> V_150 = 0 ;
V_57 -> V_171 = V_172 ;
V_57 -> V_103 = V_129 ;
}
static int F_63 ( struct V_173 * V_174 ,
const struct V_175 * V_28 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
int V_23 , V_7 = - V_115 ;
V_6 = F_64 ( sizeof( struct V_2 ) , V_101 ) ;
if ( ! V_6 ) {
F_65 ( & V_174 -> V_3 , L_19 ) ;
return - V_115 ;
}
V_3 = F_45 ( V_6 ) ;
V_3 -> V_92 = F_66 ( V_174 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_43 . V_40 = V_176 ;
V_3 -> V_43 . clock . V_177 = V_178 ;
V_3 -> V_43 . V_179 = & V_180 ;
V_3 -> V_43 . V_181 = F_61 ;
V_3 -> V_43 . V_182 = F_60 ;
V_3 -> V_43 . V_183 = V_157 ;
V_6 -> V_184 = & V_185 ;
V_6 -> V_186 |= V_187 ;
F_67 ( & V_3 -> V_118 ) ;
F_67 ( & V_3 -> V_127 ) ;
F_43 ( & V_3 -> V_96 , 0 ) ;
for ( V_23 = 0 ; V_23 < V_101 ; V_23 ++ )
V_3 -> V_128 [ V_23 ] . V_100 = V_101 ;
V_3 -> V_119 = F_32 ( 0 , V_114 ) ;
if ( ! V_3 -> V_119 ) {
F_65 ( & V_174 -> V_3 , L_20 ) ;
goto V_188;
}
V_3 -> V_10 = F_68 ( V_120 , V_114 ) ;
if ( ! V_3 -> V_10 )
goto V_189;
V_3 -> V_102 = F_68 ( V_84 +
sizeof( struct V_17 ) , V_114 ) ;
if ( ! V_3 -> V_102 )
goto V_190;
F_69 ( V_174 , V_3 ) ;
F_70 ( V_6 , & V_174 -> V_3 ) ;
F_62 ( & V_3 -> V_104 ) ;
V_7 = F_26 ( V_3 , & V_3 -> V_104 ) ;
if ( V_7 ) {
F_8 ( V_6 , L_21 , V_7 ) ;
goto V_191;
}
V_7 = F_71 ( V_6 ) ;
if ( V_7 ) {
F_8 ( V_6 , L_22 , V_7 ) ;
goto V_191;
}
return 0 ;
V_191:
F_72 ( V_3 -> V_102 ) ;
V_190:
F_72 ( V_3 -> V_10 ) ;
V_189:
F_34 ( V_3 -> V_119 ) ;
V_188:
F_73 ( V_6 ) ;
return V_7 ;
}
static void F_74 ( struct V_173 * V_174 )
{
struct V_2 * V_3 = F_75 ( V_174 ) ;
F_69 ( V_174 , NULL ) ;
if ( V_3 ) {
F_76 ( V_3 -> V_6 ) ;
F_73 ( V_3 -> V_6 ) ;
F_40 ( V_3 ) ;
F_34 ( V_3 -> V_119 ) ;
F_72 ( V_3 -> V_10 ) ;
}
}
