static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if( ! V_5 ) {
F_3 ( 1 ) ;
return;
}
F_4 ( V_5 ,
V_6 ,
17 ,
V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if( ! V_5 ) {
F_3 ( 1 ) ;
return;
}
F_4 ( V_5 ,
V_8 ,
5 ,
V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if( ! V_5 ) {
F_3 ( 1 ) ;
return;
}
F_4 ( V_5 ,
V_9 ,
4 ,
V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if( ! V_5 ) {
F_3 ( 1 ) ;
return;
}
F_4 ( V_5 ,
V_10 ,
3 ,
V_7 ) ;
}
void F_8 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
T_1 V_15 = 0 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
{
if ( ( F_9 ( V_13 ) & V_14 ) == V_14 )
break;
F_10 ( 100 ) ;
}
if ( V_15 == V_16 )
F_11 ( V_12 -> V_12 ,
L_1 ,
V_13 ) ;
}
void F_12 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_5 -> V_12 ;
struct V_17 * V_18 = V_12 -> V_19 ;
T_1 V_20 ;
if( ! V_5 ) {
F_3 ( 1 ) ;
return;
}
F_13 ( V_5 ,
V_21 ,
0xd8 ,
1 ,
V_7 ) ;
F_13 ( V_5 ,
V_22 ,
0x33 ,
1 ,
V_7 ) ;
F_1 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , V_3 ) ;
V_20 = V_23 | V_24 | V_25 ;
if ( V_26 == 1 || V_27 == 1 )
V_20 |= V_24 | V_28 | V_29 ;
if ( V_26 == 1 )
V_20 |= V_30 ;
V_18 -> V_31 = V_20 ;
F_13 ( V_5 ,
V_32 ,
( V_33 ) V_20 ,
1 ,
V_7 ) ;
if ( V_27 == 0 )
return;
F_13 ( V_5 ,
V_34 ,
V_35 ,
1 ,
V_7 ) ;
}
void F_14 ( struct V_11 * V_12 , int V_3 , int V_36 )
{
struct V_4 * V_5 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
T_1 V_20 ;
int V_37 ;
if ( ! V_12 || ( V_3 != 0 && V_3 != 2 ) ) {
F_11 ( V_12 -> V_12 , L_2 ) ;
return;
}
V_37 = F_15 ( V_12 , 0 ) ;
V_18 = V_12 -> V_19 ;
if( V_3 )
V_2 = V_18 -> V_38 [ 1 ] ;
else
V_2 = V_18 -> V_38 [ 0 ] ;
V_5 = F_2 ( V_2 ) ;
if( ! V_5 ) {
F_3 ( 1 ) ;
return;
}
V_20 = ( ( V_36 * 0xff ) / V_39 ) & 0xff ;
F_16 ( V_12 -> V_12 ,
L_3 , V_3 , V_20 ) ;
if( V_37 == V_40 || V_37 == V_41 ) {
F_13 ( V_5 ,
V_42 ,
( V_33 ) V_20 ,
1 ,
V_7 ) ;
} else {
F_13 ( V_5 ,
V_21 ,
( V_33 ) V_20 ,
1 ,
V_7 ) ;
if ( V_36 == 0 )
V_20 = 0 ;
else
V_20 = V_18 -> V_31 ;
F_13 ( V_5 ,
V_32 ,
( V_33 ) V_20 ,
1 ,
V_7 ) ;
}
}
void F_17 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_12 ;
T_1 V_43 = V_3 ? V_44 : 0 ;
int V_45 = 100 ;
if ( ! V_2 ) {
F_3 ( 1 ) ;
return;
}
V_12 = V_2 -> V_12 ;
if ( ! F_18 ( V_12 , true ) ) {
F_11 ( V_12 -> V_12 , L_4 ) ;
return;
}
if( ! ( F_9 ( V_46 + V_43 ) & V_47 ) )
goto V_48;
if( F_9 ( V_49 + V_43 ) & V_50 ) {
F_19 ( ( V_49 + V_43 ) ,
( F_9 ( V_49 + V_43 ) | V_50 ) ) ;
}
F_19 ( ( V_51 + V_43 ) , V_52 ) ;
while( ! ( F_9 ( V_49 + V_43 ) & V_50 ) ) {
V_45 -- ;
if( ! V_45 ) {
F_11 ( V_12 -> V_12 , L_5 ) ;
break;
}
}
F_20 ( 100 ) ;
F_19 ( ( V_46 + V_43 ) ,
( F_9 ( V_46 + V_43 ) & ~ V_47 ) ) ;
V_48:
F_21 ( V_12 ) ;
}
void F_22 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_12 ;
T_1 V_43 = V_3 ? V_44 : 0 ;
int V_45 = 100 ;
if ( ! V_2 ) {
F_3 ( 1 ) ;
return;
}
V_12 = V_2 -> V_12 ;
F_16 ( V_12 -> V_12 , L_6 , V_3 ) ;
if ( ! F_18 ( V_12 , true ) ) {
F_11 ( V_12 -> V_12 , L_4 ) ;
return;
}
if( ( F_9 ( V_46 + V_43 ) & V_47 ) )
goto V_53;
if( V_2 -> type == V_54 ) {
if( F_9 ( V_49 + V_43 ) & V_50 ) {
F_19 ( ( V_49 + V_43 ) , V_50 ) ;
}
F_19 ( ( V_51 + V_43 ) , V_55 ) ;
while( ! ( F_9 ( V_49 + V_43 ) & V_50 ) ) {
V_45 -- ;
if( ! V_45 ) {
F_11 ( V_12 -> V_12 , L_5 ) ;
break;
}
}
F_20 ( 100 ) ;
}
F_19 ( ( V_46 + V_43 ) ,
( F_9 ( V_46 + V_43 ) | V_47 ) ) ;
V_53:
F_21 ( V_12 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
V_33 V_56 ,
T_1 * V_57 ,
V_33 V_58 )
{
struct V_4 * V_5
= F_2 ( V_2 ) ;
if ( ! V_5 || ! V_57 ) {
F_24 ( L_2 ) ;
return - V_59 ;
}
if ( V_58 == V_60 )
return F_25 ( V_5 , V_56 , V_57 , 1 ) ;
else if ( V_58 == V_61 )
return F_26 ( V_5 , V_56 , V_57 , 1 ) ;
else
return - V_59 ;
}
int F_27 ( struct V_1 * V_2 ,
T_1 * V_62 ,
V_33 V_58 )
{
if ( ! V_2 || ! V_62 ) {
F_24 ( L_2 ) ;
return - V_59 ;
}
return F_23 ( V_2 , 0x0a , V_62 , V_58 ) ;
}
int F_28 ( struct V_1 * V_2 ,
T_1 * V_63 ,
V_33 V_58 )
{
if ( ! V_2 || ! V_63 ) {
F_24 ( L_2 ) ;
return - V_59 ;
}
return F_23 ( V_2 , 0x0f , V_63 ,
V_58 ) ;
}
void F_29 ( struct V_1 * V_2 , int V_3 )
{
if( ! V_2 || ( ( V_3 != 0 ) && ( V_3 != 2 ) ) ) {
F_3 ( 1 ) ;
return;
}
if( V_2 -> type )
F_30 ( V_2 , V_3 ) ;
else
F_31 ( V_2 , V_3 ) ;
}
static void F_32 ( struct V_64 * V_65 )
{
}
static void F_33 ( struct V_64 * V_65 )
{
}
static enum V_66 F_34 ( struct V_64 * V_65 , bool V_67 )
{
struct V_68 * V_69
= F_35 ( V_65 ) ;
struct V_70 * V_71
= F_36 ( V_69 ) ;
return V_71 -> V_72 ;
}
static int F_37 ( struct V_64 * V_65 ,
struct V_73 * V_74 ,
T_2 V_75 )
{
struct V_76 * V_77 = V_65 -> V_77 ;
if ( ! strcmp ( V_74 -> V_78 , L_7 ) && V_77 ) {
struct V_79 * V_80 = F_38 ( V_77 -> V_81 ) ;
bool V_82 ;
T_2 V_83 ;
if ( ! V_80 )
goto V_84;
switch ( V_75 ) {
case V_85 :
break;
case V_86 :
break;
case V_87 :
break;
default:
goto V_84;
}
if ( F_39 ( V_65 , V_74 , & V_83 ) )
goto V_84;
if ( V_83 == V_75 )
goto V_88;
if ( F_40 ( V_65 , V_74 , V_75 ) )
goto V_84;
V_82 = ( V_83 == V_86 ) ||
( V_75 == V_86 ) ;
if ( V_80 -> V_89 . V_90 != 0 &&
V_80 -> V_89 . V_91 != 0 ) {
if ( V_82 ) {
if ( ! F_41 ( V_77 -> V_81 , & V_80 -> V_89 ,
V_77 -> V_81 -> V_92 , V_77 -> V_81 -> V_93 , V_77 -> V_81 -> V_94 ) )
goto V_84;
} else {
struct V_95 * V_96 = V_77 -> V_97 ;
V_96 -> V_98 ( V_77 , & V_80 -> V_89 ,
& V_80 -> V_99 ) ;
}
}
#ifdef F_42
} else if ( ! strcmp ( V_74 -> V_78 , L_8 ) && V_77 ) {
struct V_17 * V_18 = V_77 -> V_12 -> V_19 ;
struct V_100 * V_101 = V_18 -> V_100 ;
F_16 ( V_77 -> V_12 -> V_12 , L_9 , ( int ) V_75 ) ;
if ( F_40 ( V_65 , V_74 , V_75 ) )
goto V_84;
else {
F_16 ( V_77 -> V_12 -> V_12 ,
L_10 , ( int ) V_75 ) ;
if ( V_101 ) {
V_101 -> V_102 . V_103 = V_75 ;
F_43 ( V_101 ) ;
}
}
#endif
}
V_88:
return 0 ;
V_84:
return - 1 ;
}
static void F_44 ( struct V_64 * V_65 )
{
struct V_68 * V_69 = F_35 ( V_65 ) ;
struct V_70 * V_71 = F_36 ( V_69 ) ;
struct V_4 * V_5 ;
if( ! V_71 )
return;
F_45 ( V_65 ) ;
F_46 ( V_65 ) ;
V_5 = V_71 -> V_104 ;
F_47 ( V_5 ) ;
F_48 ( V_71 ) ;
}
static int F_49 ( struct V_64 * V_65 )
{
struct V_68 * V_69 = F_35 ( V_65 ) ;
struct V_70 * V_71 = F_36 ( V_69 ) ;
struct V_1 * V_2 = F_50 ( V_71 ) ;
struct V_105 * V_106 = V_2 -> V_106 ;
struct V_105 * V_107 = NULL ;
struct V_11 * V_12 = V_65 -> V_12 ;
V_65 -> V_108 . V_109 = 0 ;
V_65 -> V_108 . V_110 = 200 ;
V_65 -> V_108 . V_111 = 0 ;
V_65 -> V_108 . V_112 = 200 ;
if( V_106 ) {
F_16 ( V_12 -> V_12 , L_11 ,
V_106 -> V_90 , V_106 -> V_91 ) ;
V_107 = F_51 ( V_12 , V_106 ) ;
F_52 ( V_65 , V_107 ) ;
return 1 ;
}
F_11 ( V_12 -> V_12 , L_12 ) ;
return 0 ;
}
static int F_53 ( struct V_64 * V_65 , struct V_105 * V_62 )
{
struct V_68 * V_69 = F_35 ( V_65 ) ;
struct V_70 * V_71 = F_36 ( V_69 ) ;
struct V_1 * V_2 = F_50 ( V_71 ) ;
struct V_105 * V_106 = V_2 -> V_106 ;
F_16 ( V_65 -> V_12 -> V_12 , L_13 ,
V_62 , V_106 ) ;
if( V_62 -> V_113 & V_114 )
return V_115 ;
if( V_62 -> V_113 & V_116 )
return V_117 ;
if( V_106 ) {
if( V_62 -> V_90 != V_106 -> V_90 )
return V_118 ;
if( V_62 -> V_91 != V_106 -> V_91 )
return V_118 ;
}
F_16 ( V_65 -> V_12 -> V_12 , L_14 ) ;
return V_119 ;
}
static void F_54 ( struct V_64 * V_65 , int V_62 )
{
#ifdef F_55
struct V_11 * V_12 = V_65 -> V_12 ;
struct V_17 * V_18 = V_12 -> V_19 ;
bool V_120 , V_121 ;
#endif
F_56 ( V_65 , V_62 ) ;
#ifdef F_55
if( F_57 ( V_12 ) ) {
V_120 = V_18 -> V_122 ;
V_121 = V_18 -> V_123 ;
} else {
V_120 = V_18 -> V_124 ;
V_121 = V_18 -> V_125 ;
}
if( ! V_120 && ! V_121 && ! ( F_9 ( V_126 )
& V_127 ) ) {
if( V_18 -> V_128 )
F_58 ( & V_12 -> V_129 -> V_12 ) ;
}
#if 0
if(!dev_priv->rpm_enabled && !mdfld_panel_dpi(dev))
ospm_runtime_pm_allow(dev);
#endif
#endif
}
static struct V_76 * F_59 (
struct V_64 * V_65 )
{
struct V_68 * V_69 = F_35 ( V_65 ) ;
struct V_70 * V_71 = F_36 ( V_69 ) ;
struct V_1 * V_2 = F_50 ( V_71 ) ;
struct V_130 * V_77 = NULL ;
if( V_2 -> type == V_131 )
V_77 = V_2 -> V_132 [ V_131 ] ;
else if ( V_2 -> type == V_54 )
V_77 = V_2 -> V_132 [ V_54 ] ;
F_16 ( V_65 -> V_12 -> V_12 , L_15 , V_77 ) ;
if( ! V_77 ) {
F_11 ( V_65 -> V_12 -> V_12 ,
L_16 , V_2 -> type ) ;
return NULL ;
}
V_2 -> V_77 = V_77 ;
return & V_77 -> V_133 ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_1 * V_134 , int V_3 )
{
if( ! V_12 || ! V_134 ) {
F_3 ( 1 ) ;
return - V_59 ;
}
V_134 -> V_135 = 24 ;
V_134 -> type = F_57 ( V_12 ) ;
V_134 -> V_136 = 2 ;
V_134 -> V_137 = 0 ;
if ( F_15 ( V_12 , V_3 ) == V_40 ) {
V_134 -> V_138 = V_139 ;
} else {
V_134 -> V_138 = V_140 ;
}
return 0 ;
}
struct V_105 *
F_61 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_105 * V_62 ;
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_141 * V_142 = & V_18 -> V_143 . V_144 ;
bool V_145 = false ;
V_62 = F_62 ( sizeof( * V_62 ) , V_146 ) ;
if ( ! V_62 ) {
F_11 ( V_12 -> V_12 , L_17 ) ;
return NULL ;
}
if ( V_145 ) {
F_16 ( V_12 -> V_12 , L_18 ) ;
V_62 -> V_90 = ( V_142 -> V_147 << 8 ) | V_142 -> V_148 ;
V_62 -> V_91 = ( V_142 -> V_149 << 8 ) | V_142 -> V_150 ;
V_62 -> V_151 = V_62 -> V_90 + \
( ( V_142 -> V_152 << 8 ) | \
V_142 -> V_153 ) ;
V_62 -> V_154 = V_62 -> V_151 + \
( ( V_142 -> V_155 << 8 ) | \
V_142 -> V_156 ) ;
V_62 -> V_157 = V_62 -> V_90 + ( ( V_142 -> V_158 << 8 ) | \
V_142 -> V_159 ) ;
V_62 -> V_160 = \
V_62 -> V_91 + ( ( V_142 -> V_161 << 8 ) | \
V_142 -> V_162 ) ;
V_62 -> V_163 = \
V_62 -> V_160 + ( ( V_142 -> V_164 << 8 ) | \
V_142 -> V_165 ) ;
V_62 -> V_166 = V_62 -> V_91 + \
( ( V_142 -> V_167 << 8 ) | V_142 -> V_168 ) ;
V_62 -> clock = V_142 -> V_169 * 10 ;
} else {
if( V_2 -> type == V_54 ) {
if ( F_15 ( V_12 , V_3 ) == V_40 ) {
V_62 -> V_90 = 480 ;
V_62 -> V_91 = 854 ;
V_62 -> V_151 = 487 ;
V_62 -> V_154 = 490 ;
V_62 -> V_157 = 499 ;
V_62 -> V_160 = 861 ;
V_62 -> V_163 = 865 ;
V_62 -> V_166 = 873 ;
V_62 -> clock = 33264 ;
} else {
V_62 -> V_90 = 864 ;
V_62 -> V_91 = 480 ;
V_62 -> V_151 = 873 ;
V_62 -> V_154 = 876 ;
V_62 -> V_157 = 887 ;
V_62 -> V_160 = 487 ;
V_62 -> V_163 = 490 ;
V_62 -> V_166 = 499 ;
V_62 -> clock = 33264 ;
}
} else if( V_2 -> type == V_131 ) {
V_62 -> V_90 = 864 ;
V_62 -> V_91 = 480 ;
V_62 -> V_151 = 872 ;
V_62 -> V_154 = 876 ;
V_62 -> V_157 = 884 ;
V_62 -> V_160 = 482 ;
V_62 -> V_163 = 494 ;
V_62 -> V_166 = 486 ;
V_62 -> clock = 25777 ;
}
}
F_63 ( V_62 ) ;
F_64 ( V_62 , 0 ) ;
V_62 -> type |= V_170 ;
return V_62 ;
}
int F_65 ( int V_3 )
{
unsigned V_171 ;
int V_172 = 0 ;
switch ( V_3 ) {
case 0 :
V_171 = 128 ;
break;
case 2 :
V_171 = 34 ;
break;
default:
F_24 ( L_19 ) ;
return - V_59 ;
}
V_172 = F_66 ( V_171 , L_20 ) ;
if ( V_172 ) {
F_24 ( L_21 ) ;
return V_172 ;
}
V_172 = F_67 ( V_171 , 1 ) ;
if ( V_172 ) {
F_24 ( L_22 ) ;
goto V_173;
}
F_68 ( 128 ) ;
V_173:
if ( F_69 ( V_171 ) )
F_70 ( V_171 ) ;
return V_172 ;
}
void F_71 ( struct V_11 * V_12 ,
int V_3 ,
struct V_1 * V_134 ,
struct V_174 * V_175 ,
struct V_174 * V_176 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
struct V_68 * V_69 ;
struct V_64 * V_65 ;
struct V_130 * V_77 ;
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_177 V_178 ;
T_1 V_179 , V_180 ;
F_16 ( V_12 -> V_12 , L_23 , V_3 ) ;
if( ! V_12 || ( ( V_3 != 0 ) && ( V_3 != 2 ) ) ) {
F_3 ( 1 ) ;
return;
}
V_71 = F_62 ( sizeof( struct V_70 ) , V_146 ) ;
if( ! V_71 ) {
F_24 ( L_24 ) ;
return;
}
V_71 -> V_3 = V_3 ;
if( V_134 ) {
V_2 = V_134 ;
} else {
V_2 = F_62 ( sizeof( struct V_1 ) , V_146 ) ;
if( ! V_2 ) {
F_11 ( V_12 -> V_12 ,
L_25 ) ;
goto V_181;
}
F_60 ( V_12 , V_2 , V_3 ) ;
}
V_71 -> V_182 = V_2 ;
V_2 -> V_183 = 1 ;
V_2 -> V_12 = V_12 ;
if( V_2 -> type == V_131 ) {
V_2 -> V_106 = V_175 -> V_184 ( V_12 ) ;
if( V_175 -> V_185 ( V_12 , V_3 , & V_178 ) )
goto V_181;
} else if( V_2 -> type == V_54 ) {
V_2 -> V_106 = V_176 -> V_184 ( V_12 ) ;
if( V_176 -> V_185 ( V_12 , V_3 , & V_178 ) )
goto V_181;
}
V_179 = V_178 . V_179 ;
V_180 = V_178 . V_180 ;
V_2 -> V_62 = V_2 -> V_106 ;
V_2 -> V_65 = V_71 ;
if( ! V_2 -> V_106 ) {
F_11 ( V_12 -> V_12 , L_26 ) ;
goto V_181;
}
if( V_3 && V_18 -> V_38 [ 0 ] ) {
V_2 -> V_186 = 0 ;
V_18 -> V_38 [ 1 ] = V_2 ;
} else if( V_3 == 0 ) {
V_2 -> V_186 = 1 ;
V_18 -> V_38 [ 0 ] = V_2 ;
} else {
F_11 ( V_12 -> V_12 , L_27 ) ;
goto V_181;
}
V_69 = & V_71 -> V_133 ;
V_69 -> type = ( V_3 == 0 ) ? V_187 : V_188 ;
V_65 = & V_69 -> V_133 ;
F_72 ( V_12 , V_65 , & V_189 ,
V_190 ) ;
F_73 ( V_65 , & V_191 ) ;
V_65 -> V_108 . V_192 = V_193 ;
V_65 -> V_108 . V_179 = V_179 ;
V_65 -> V_108 . V_180 = V_180 ;
V_65 -> V_194 = false ;
V_65 -> V_195 = false ;
F_74 ( V_65 , V_12 -> V_196 . V_197 , V_85 ) ;
F_74 ( V_65 , V_18 -> V_198 , V_39 ) ;
if ( F_75 ( V_71 , V_3 ) ) {
F_24 ( L_28 , V_3 ) ;
goto V_181;
}
if ( V_175 ) {
V_77 = F_76 ( V_12 , V_71 , V_175 ) ;
if( ! V_77 ) {
F_11 ( V_12 -> V_12 , L_29 ) ;
goto V_199;
}
V_77 -> V_182 = V_2 ;
V_2 -> V_132 [ V_131 ] = V_77 ;
}
if( V_176 ) {
V_77 = F_77 ( V_12 , V_71 , V_176 ) ;
if( ! V_77 ) {
F_11 ( V_12 -> V_12 , L_30 ) ;
goto V_199;
}
V_77 -> V_182 = V_2 ;
V_2 -> V_132 [ V_54 ] = V_77 ;
}
F_78 ( V_65 ) ;
return;
V_199:
F_47 ( V_71 -> V_104 ) ;
F_46 ( V_65 ) ;
F_48 ( V_2 -> V_106 ) ;
F_48 ( V_2 ) ;
V_181:
F_48 ( V_71 ) ;
}
