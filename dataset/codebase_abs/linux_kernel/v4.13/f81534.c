static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 -> V_2 ) ;
int V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 ) {
if ( V_6 -> V_10 [ V_8 ] & V_11 )
continue;
if ( V_4 -> V_12 == V_7 )
return V_8 ;
++ V_7 ;
}
return - V_13 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_14 , T_2 V_15 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_3 V_7 = V_20 ;
int V_21 ;
T_2 * V_22 ;
V_22 = F_4 ( sizeof( T_2 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
* V_22 = V_15 ;
while ( V_7 -- ) {
V_21 = F_5 ( V_19 , F_6 ( V_19 , 0 ) ,
V_25 ,
V_26 | V_27 ,
V_14 , 0 , V_22 , sizeof( T_2 ) ,
V_28 ) ;
if ( V_21 > 0 ) {
V_21 = 0 ;
break;
} else if ( V_21 == 0 ) {
V_21 = - V_29 ;
}
}
if ( V_21 < 0 ) {
F_7 ( & V_17 -> V_19 , L_1 ,
V_30 , V_14 , V_15 , V_21 ) ;
}
F_8 ( V_22 ) ;
return V_21 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_14 , T_2 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
T_3 V_7 = V_20 ;
int V_21 ;
T_2 * V_22 ;
V_22 = F_4 ( sizeof( T_2 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
while ( V_7 -- ) {
V_21 = F_5 ( V_19 , F_10 ( V_19 , 0 ) ,
V_25 ,
V_26 | V_31 ,
V_14 , 0 , V_22 , sizeof( T_2 ) ,
V_28 ) ;
if ( V_21 > 0 ) {
V_21 = 0 ;
break;
} else if ( V_21 == 0 ) {
V_21 = - V_29 ;
}
}
if ( V_21 < 0 ) {
F_7 ( & V_17 -> V_19 , L_2 , V_30 ,
V_14 , V_21 ) ;
goto V_32;
}
* V_15 = * V_22 ;
V_32:
F_8 ( V_22 ) ;
return V_21 ;
}
static int F_11 ( struct V_3 * V_4 , T_1 V_14 ,
T_2 V_15 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
return F_3 ( V_4 -> V_2 ,
V_14 + V_34 -> V_35 * V_36 , V_15 ) ;
}
static int F_13 ( struct V_3 * V_4 , T_1 V_14 ,
T_2 * V_15 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
return F_9 ( V_4 -> V_2 ,
V_14 + V_34 -> V_35 * V_36 , V_15 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_3 V_7 = V_37 ;
T_2 V_22 ;
int V_21 ;
do {
V_21 = F_9 ( V_2 , V_38 ,
& V_22 ) ;
if ( V_21 )
return V_21 ;
if ( V_22 & V_39 )
continue;
if ( V_22 & V_40 )
break;
} while ( -- V_7 );
if ( ! V_7 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_3 ,
V_30 ) ;
return - V_29 ;
}
return F_3 ( V_2 , V_38 ,
V_22 & ~ V_40 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_14 ,
T_2 * V_15 )
{
int V_21 ;
V_21 = F_9 ( V_2 , V_14 , V_15 ) ;
if ( V_21 )
return V_21 ;
return F_14 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_14 , T_2 V_15 )
{
int V_21 ;
V_21 = F_3 ( V_2 , V_14 , V_15 ) ;
if ( V_21 )
return V_21 ;
return F_14 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_4 V_41 ,
T_3 V_42 , T_2 * V_43 )
{
T_2 V_44 [ V_45 ] ;
T_3 V_46 = 0 ;
T_3 V_47 ;
T_3 V_7 ;
int V_21 ;
int V_48 ;
T_1 V_49 ;
V_21 = F_16 ( V_2 , V_50 ,
V_51 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_50 ,
( V_41 >> 16 ) & 0xff ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_50 ,
( V_41 >> 8 ) & 0xff ) ;
if ( V_21 )
return V_21 ;
V_21 = F_16 ( V_2 , V_50 ,
( V_41 >> 0 ) & 0xff ) ;
if ( V_21 )
return V_21 ;
do {
V_47 = F_18 ( T_3 , V_45 , V_42 ) ;
for ( V_7 = 0 ; V_7 < V_47 ; ++ V_7 ) {
if ( V_42 <= V_45 &&
V_47 == V_7 + 1 )
V_49 = V_52 ;
else
V_49 = V_50 ;
V_21 = F_16 ( V_2 , V_49 ,
0xf1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_15 ( V_2 ,
V_53 ,
& V_44 [ V_7 ] ) ;
if ( V_21 )
return V_21 ;
V_48 = V_7 + V_46 * V_45 ;
V_43 [ V_48 ] = V_44 [ V_7 ] ;
}
V_42 -= V_47 ;
++ V_46 ;
} while ( V_42 );
return 0 ;
}
static void F_19 ( struct V_3 * V_4 , T_2 * V_43 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_35 = V_34 -> V_35 ;
T_2 V_54 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 ) {
V_43 [ V_8 * V_55 ] = V_8 ;
V_43 [ V_8 * V_55 + 1 ] = V_56 ;
V_43 [ V_8 * V_55 + 2 ] = 0 ;
V_43 [ V_8 * V_55 + 3 ] = 0 ;
}
V_54 = F_20 ( & V_4 -> V_57 ,
& V_43 [ V_35 * V_55 + 4 ] ,
V_58 , & V_4 -> V_59 ) ;
V_43 [ V_35 * V_55 + 2 ] = V_54 ;
}
static int F_21 ( struct V_3 * V_4 , T_5 V_60 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
struct V_61 * V_61 ;
unsigned long V_62 ;
int V_63 ;
F_22 ( & V_4 -> V_59 , V_62 ) ;
if ( F_23 ( & V_4 -> V_57 ) ) {
F_24 ( & V_4 -> V_59 , V_62 ) ;
return 0 ;
}
F_24 ( & V_4 -> V_59 , V_62 ) ;
if ( ! F_25 ( V_64 , & V_34 -> V_65 ) )
return 0 ;
V_61 = V_4 -> V_66 [ 0 ] ;
F_19 ( V_4 , V_4 -> V_67 [ 0 ] ) ;
V_61 -> V_68 = V_69 ;
V_63 = F_26 ( V_61 , V_60 ) ;
if ( V_63 ) {
F_27 ( V_64 , & V_34 -> V_65 ) ;
F_7 ( & V_4 -> V_19 , L_4 , V_30 ,
V_63 ) ;
return V_63 ;
}
F_28 ( V_4 ) ;
return 0 ;
}
static T_4 F_29 ( T_4 V_70 , T_4 V_71 )
{
if ( ! V_70 )
return 0 ;
return F_30 ( V_71 , V_70 ) ;
}
static int F_31 ( struct V_3 * V_4 , T_4 V_70 ,
T_2 V_72 )
{
T_4 V_73 ;
int V_21 ;
T_2 V_74 ;
if ( V_70 <= 1200 )
V_74 = V_75 ;
else
V_74 = V_76 ;
V_21 = F_11 ( V_4 , V_77 , V_74 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_5 , V_30 ) ;
return V_21 ;
}
if ( V_70 <= 1200 )
V_74 = V_78 | V_79 ;
else
V_74 = V_80 | V_79 ;
V_21 = F_11 ( V_4 , V_81 ,
V_74 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_6 , V_30 ) ;
return V_21 ;
}
V_73 = F_29 ( V_70 , V_82 ) ;
V_74 = V_83 ;
V_21 = F_11 ( V_4 , V_84 ,
V_74 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_7 , V_30 ) ;
return V_21 ;
}
V_74 = V_73 & 0xff ;
V_21 = F_11 ( V_4 , V_85 , V_74 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_8 , V_30 ) ;
return V_21 ;
}
V_74 = ( V_73 >> 8 ) & 0xff ;
V_21 = F_11 ( V_4 , V_86 , V_74 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_9 , V_30 ) ;
return V_21 ;
}
V_21 = F_11 ( V_4 , V_84 , V_72 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_7 , V_30 ) ;
return V_21 ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , unsigned int V_87 ,
unsigned int V_88 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_21 ;
T_2 V_22 ;
if ( ( ( V_87 | V_88 ) & ( V_89 | V_90 ) ) == 0 )
return 0 ;
F_33 ( & V_34 -> V_91 ) ;
V_88 &= ~ V_87 ;
V_22 = V_92 | V_34 -> V_93 ;
if ( V_88 & V_89 )
V_22 &= ~ V_94 ;
if ( V_88 & V_90 )
V_22 &= ~ V_95 ;
if ( V_87 & V_89 )
V_22 |= V_94 ;
if ( V_87 & V_90 )
V_22 |= V_95 ;
V_21 = F_11 ( V_4 , V_96 , V_22 ) ;
if ( V_21 < 0 ) {
F_7 ( & V_4 -> V_19 , L_10 , V_30 ) ;
F_34 ( & V_34 -> V_91 ) ;
return V_21 ;
}
V_34 -> V_93 = V_22 ;
F_34 ( & V_34 -> V_91 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 * V_97 )
{
T_2 V_22 ;
int V_21 ;
V_21 = F_17 ( V_2 , V_98 , 1 ,
& V_22 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 , L_11 ,
V_30 , V_21 ) ;
return V_21 ;
}
if ( V_22 == V_99 )
* V_97 = 0 ;
else
* V_97 = V_100 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_103 * V_19 = & V_2 -> V_17 -> V_19 ;
int V_104 = F_37 ( V_102 -> V_105 [ 0 ] ) ;
int V_106 = F_37 ( V_102 -> V_107 [ 0 ] ) ;
T_2 V_108 [ V_109 ] ;
T_2 V_110 ;
T_2 V_111 = 0 ;
int V_21 ;
T_3 V_8 ;
if ( V_106 != V_69 ||
V_104 != V_112 ) {
F_7 ( V_19 , L_12 ) ;
return - V_13 ;
}
V_21 = F_35 ( V_2 , & V_110 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 , L_13 ,
V_30 , V_21 ) ;
return V_21 ;
}
if ( V_110 != V_100 ) {
V_21 = F_17 ( V_2 ,
V_98 +
V_113 ,
sizeof( V_108 ) , V_108 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_14 ,
V_30 , V_21 ) ;
return V_21 ;
}
F_38 ( & V_2 -> V_17 -> V_19 ,
L_15 , V_30 ,
V_110 ) ;
} else {
V_21 = F_17 ( V_2 ,
V_114 , V_9 ,
V_108 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_11 , V_30 ,
V_21 ) ;
return V_21 ;
}
F_38 ( & V_2 -> V_17 -> V_19 , L_16 ,
V_30 ) ;
}
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 ) {
if ( V_108 [ V_8 ] & V_11 )
continue;
++ V_111 ;
}
if ( ! V_111 ) {
F_39 ( & V_2 -> V_17 -> V_19 ,
L_17 ) ;
V_111 = 4 ;
}
F_40 ( F_41 ( V_102 -> V_107 ) < V_9 ) ;
for ( V_8 = 1 ; V_8 < V_111 ; ++ V_8 )
V_102 -> V_107 [ V_8 ] = V_102 -> V_107 [ 0 ] ;
V_102 -> V_115 = V_111 ;
return V_111 ;
}
static void F_42 ( struct V_116 * V_117 ,
struct V_3 * V_4 ,
struct V_118 * V_119 )
{
T_2 V_120 = 0 ;
int V_21 ;
T_4 V_121 ;
if ( F_43 ( V_117 ) == V_122 )
F_32 ( V_4 , 0 , V_89 | V_90 ) ;
else if ( V_119 && ( V_119 -> V_123 & V_124 ) == V_122 )
F_32 ( V_4 , V_89 | V_90 , 0 ) ;
if ( F_44 ( V_117 ) ) {
V_120 |= V_125 ;
if ( ! F_45 ( V_117 ) )
V_120 |= V_126 ;
if ( F_46 ( V_117 ) )
V_120 |= V_127 ;
}
if ( F_47 ( V_117 ) )
V_120 |= V_128 ;
switch ( F_48 ( V_117 ) ) {
case V_129 :
V_120 |= V_130 ;
break;
case V_131 :
V_120 |= V_132 ;
break;
case V_133 :
V_120 |= V_134 ;
break;
default:
case V_135 :
V_120 |= V_136 ;
break;
}
V_121 = F_49 ( V_117 ) ;
if ( ! V_121 )
return;
if ( V_121 > V_82 ) {
if ( V_119 )
V_121 = F_50 ( V_119 ) ;
else
V_121 = V_137 ;
F_51 ( V_117 , V_121 , V_121 ) ;
}
F_38 ( & V_4 -> V_19 , L_18 , V_30 , V_121 ) ;
V_21 = F_31 ( V_4 , V_121 , V_120 ) ;
if ( V_21 < 0 ) {
F_7 ( & V_4 -> V_19 , L_19 ,
V_30 , V_21 ) ;
}
}
static int F_52 ( struct V_1 * V_2 , T_5 V_62 )
{
return F_53 ( V_2 -> V_4 [ 0 ] , V_62 ) ;
}
static void F_54 ( struct V_3 * V_4 , T_2 V_138 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
struct V_116 * V_117 ;
unsigned long V_62 ;
T_2 V_139 ;
if ( ! ( V_138 & V_140 ) )
return;
F_22 ( & V_34 -> V_141 , V_62 ) ;
V_139 = V_34 -> V_142 ;
V_34 -> V_142 = V_138 ;
F_24 ( & V_34 -> V_141 , V_62 ) ;
F_38 ( & V_4 -> V_19 , L_20 , V_30 , V_139 ,
V_138 ) ;
if ( V_138 & V_143 )
V_4 -> V_144 . V_145 ++ ;
if ( V_138 & V_146 )
V_4 -> V_144 . V_147 ++ ;
if ( V_138 & V_148 )
V_4 -> V_144 . V_149 ++ ;
if ( V_138 & V_150 )
V_4 -> V_144 . V_151 ++ ;
F_55 ( & V_4 -> V_4 . V_152 ) ;
if ( ! ( V_138 & V_148 ) )
return;
F_38 ( & V_4 -> V_19 , L_21 ,
V_30 , V_34 -> V_35 , V_139 , V_138 ) ;
V_117 = F_56 ( & V_4 -> V_4 ) ;
if ( ! V_117 )
return;
F_57 ( V_4 , V_117 , V_138 & V_153 ) ;
F_58 ( V_117 ) ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
unsigned long V_62 ;
int V_21 ;
T_2 V_138 ;
V_21 = F_13 ( V_4 , V_154 , & V_138 ) ;
if ( V_21 )
return V_21 ;
F_22 ( & V_34 -> V_141 , V_62 ) ;
V_34 -> V_142 = V_138 ;
F_24 ( & V_34 -> V_141 , V_62 ) ;
return 0 ;
}
static int F_60 ( struct V_116 * V_117 , struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 -> V_2 ) ;
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_21 ;
V_21 = F_11 ( V_4 ,
V_81 , V_79 |
V_155 | V_156 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_22 , V_30 ,
V_21 ) ;
return V_21 ;
}
if ( V_117 )
F_42 ( V_117 , V_4 , NULL ) ;
V_21 = F_59 ( V_4 ) ;
if ( V_21 )
return V_21 ;
F_33 ( & V_6 -> V_157 ) ;
if ( ! V_6 -> V_158 ) {
V_21 = F_52 ( V_4 -> V_2 , V_23 ) ;
if ( V_21 )
goto exit;
}
V_6 -> V_158 ++ ;
exit:
F_34 ( & V_6 -> V_157 ) ;
F_27 ( V_64 , & V_34 -> V_65 ) ;
return V_21 ;
}
static void F_61 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 -> V_2 ) ;
struct V_3 * V_159 = V_4 -> V_2 -> V_4 [ 0 ] ;
unsigned long V_62 ;
T_3 V_8 ;
F_62 ( V_4 -> V_66 [ 0 ] ) ;
F_22 ( & V_4 -> V_59 , V_62 ) ;
F_63 ( & V_4 -> V_57 ) ;
F_24 ( & V_4 -> V_59 , V_62 ) ;
F_33 ( & V_6 -> V_157 ) ;
V_6 -> V_158 -- ;
if ( ! V_6 -> V_158 ) {
for ( V_8 = 0 ; V_8 < F_41 ( V_159 -> V_160 ) ; ++ V_8 )
F_62 ( V_159 -> V_160 [ V_8 ] ) ;
}
F_34 ( & V_6 -> V_157 ) ;
}
static int F_64 ( struct V_3 * V_4 ,
struct V_161 T_6 * V_162 )
{
struct V_33 * V_34 ;
struct V_161 V_22 ;
V_34 = F_12 ( V_4 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . type = V_163 ;
V_22 . V_4 = V_4 -> V_12 ;
V_22 . line = V_4 -> V_164 ;
V_22 . V_165 = V_82 ;
if ( F_65 ( V_162 , & V_22 , sizeof( * V_162 ) ) )
return - V_166 ;
return 0 ;
}
static int F_66 ( struct V_116 * V_117 , unsigned int V_167 ,
unsigned long V_168 )
{
struct V_3 * V_4 = V_117 -> V_169 ;
struct V_161 T_6 * V_43 = (struct V_161 T_6 * ) V_168 ;
switch ( V_167 ) {
case V_170 :
return F_64 ( V_4 , V_43 ) ;
default:
break;
}
return - V_171 ;
}
static void F_67 ( struct V_3 * V_4 ,
T_2 * V_15 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_35 = V_15 [ 0 ] ;
T_3 V_47 = 0 ;
T_3 V_8 ;
char V_172 ;
int V_21 ;
T_2 V_173 ;
switch ( V_15 [ 1 ] ) {
case V_174 :
F_27 ( V_64 , & V_34 -> V_65 ) ;
V_21 = F_21 ( V_4 , V_175 ) ;
if ( V_21 )
F_7 ( & V_4 -> V_19 , L_23 , V_30 ) ;
return;
case V_176 :
F_54 ( V_4 , V_15 [ 3 ] ) ;
return;
case V_177 :
V_47 = V_15 [ 2 ] ;
if ( V_47 > V_178 ) {
F_7 ( & V_4 -> V_19 ,
L_24 ,
V_30 , V_35 , V_47 ,
V_178 ) ;
return;
}
break;
default:
F_39 ( & V_4 -> V_19 , L_25 , V_30 ,
V_15 [ 1 ] ) ;
return;
}
for ( V_8 = 4 ; V_8 < 4 + V_47 ; V_8 += 2 ) {
V_172 = V_179 ;
V_173 = V_15 [ V_8 + 1 ] ;
if ( V_173 & V_180 ) {
if ( V_173 & V_181 ) {
V_172 = V_182 ;
V_4 -> V_144 . V_183 ++ ;
F_68 ( V_4 ) ;
} else if ( V_173 & V_184 ) {
V_172 = V_185 ;
V_4 -> V_144 . V_186 ++ ;
} else if ( V_173 & V_187 ) {
V_172 = V_188 ;
V_4 -> V_144 . V_189 ++ ;
}
if ( V_173 & V_190 ) {
V_4 -> V_144 . V_191 ++ ;
F_69 ( & V_4 -> V_4 , 0 ,
V_192 ) ;
}
}
if ( V_4 -> V_4 . V_193 && V_4 -> V_194 ) {
if ( F_70 ( V_4 , V_15 [ V_8 ] ) )
continue;
}
F_69 ( & V_4 -> V_4 , V_15 [ V_8 ] , V_172 ) ;
}
F_71 ( & V_4 -> V_4 ) ;
}
static void F_72 ( struct V_61 * V_61 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 * V_43 ;
int V_195 ;
int V_196 ;
T_3 V_8 ;
if ( ! V_61 -> V_197 ||
V_61 -> V_197 % V_55 ) {
return;
}
V_4 = V_61 -> V_198 ;
V_2 = V_4 -> V_2 ;
V_43 = V_61 -> V_199 ;
V_6 = F_2 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_61 -> V_197 ; V_8 += V_55 ) {
V_195 = V_43 [ V_8 ] ;
if ( V_195 >= V_9 ) {
F_7 ( & V_4 -> V_19 ,
L_26 ,
V_30 , V_195 , V_9 ) ;
continue;
}
V_196 = V_6 -> V_200 [ V_195 ] ;
V_4 = V_2 -> V_4 [ V_196 ] ;
if ( F_73 ( & V_4 -> V_4 ) )
F_67 ( V_4 , & V_43 [ V_8 ] ) ;
}
}
static void F_74 ( struct V_61 * V_61 )
{
struct V_3 * V_4 = V_61 -> V_198 ;
switch ( V_61 -> V_21 ) {
case 0 :
break;
case - V_201 :
case - V_202 :
case - V_203 :
F_38 ( & V_4 -> V_19 , L_27 ,
V_30 , V_61 -> V_21 ) ;
return;
case - V_204 :
F_7 ( & V_4 -> V_19 , L_27 ,
V_30 , V_61 -> V_21 ) ;
return;
default:
F_38 ( & V_4 -> V_19 , L_28 ,
V_30 , V_61 -> V_21 ) ;
break;
}
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_97 = 0 ;
int V_21 ;
int V_8 ;
V_6 = F_76 ( & V_2 -> V_17 -> V_19 ,
sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 )
return - V_24 ;
F_77 ( V_2 , V_6 ) ;
F_78 ( & V_6 -> V_157 ) ;
V_21 = F_35 ( V_2 , & V_6 -> V_110 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 , L_13 ,
V_30 , V_21 ) ;
return V_21 ;
}
if ( V_6 -> V_110 == V_100 ) {
V_21 = F_17 ( V_2 ,
V_114 ,
V_205 ,
V_6 -> V_10 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_29 ,
V_30 , V_21 ) ;
return V_21 ;
}
} else {
V_21 = F_17 ( V_2 ,
V_98 +
V_113 ,
sizeof( V_6 -> V_10 ) ,
V_6 -> V_10 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_30 ,
V_30 , V_6 -> V_110 ,
V_21 ) ;
return V_21 ;
}
}
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 ) {
if ( V_6 -> V_10 [ V_8 ] & V_11 )
continue;
V_6 -> V_200 [ V_8 ] = V_97 ++ ;
F_38 ( & V_2 -> V_17 -> V_19 ,
L_31 , V_30 , V_8 ,
V_6 -> V_200 [ V_8 ] ) ;
}
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_33 * V_34 ;
int V_206 ;
V_34 = F_76 ( & V_4 -> V_19 , sizeof( * V_34 ) , V_23 ) ;
if ( ! V_34 )
return - V_24 ;
F_80 ( & V_34 -> V_141 ) ;
F_78 ( & V_34 -> V_91 ) ;
V_206 = F_1 ( V_4 -> V_2 , V_4 ) ;
if ( V_206 < 0 )
return V_206 ;
V_34 -> V_35 = V_206 ;
F_81 ( V_4 , V_34 ) ;
F_38 ( & V_4 -> V_19 , L_32 , V_30 ,
V_4 -> V_12 , V_34 -> V_35 ) ;
return 0 ;
}
static int F_82 ( struct V_116 * V_117 )
{
struct V_3 * V_4 = V_117 -> V_169 ;
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_21 ;
int V_207 ;
T_2 V_138 ;
T_2 V_208 ;
V_21 = F_13 ( V_4 , V_154 , & V_138 ) ;
if ( V_21 )
return V_21 ;
F_33 ( & V_34 -> V_91 ) ;
V_208 = V_34 -> V_93 ;
F_34 ( & V_34 -> V_91 ) ;
V_207 = ( V_208 & V_94 ? V_89 : 0 ) |
( V_208 & V_95 ? V_90 : 0 ) |
( V_138 & V_209 ? V_210 : 0 ) |
( V_138 & V_153 ? V_211 : 0 ) |
( V_138 & V_212 ? V_213 : 0 ) |
( V_138 & V_214 ? V_215 : 0 ) ;
return V_207 ;
}
static int F_83 ( struct V_116 * V_117 , unsigned int V_87 ,
unsigned int V_88 )
{
struct V_3 * V_4 = V_117 -> V_169 ;
return F_32 ( V_4 , V_87 , V_88 ) ;
}
static void F_84 ( struct V_3 * V_4 , int V_216 )
{
if ( V_216 )
F_32 ( V_4 , V_89 | V_90 , 0 ) ;
else
F_32 ( V_4 , 0 , V_89 | V_90 ) ;
}
static int F_85 ( struct V_116 * V_117 , struct V_3 * V_4 ,
const T_2 * V_43 , int V_7 )
{
int V_217 , V_21 ;
if ( ! V_7 )
return 0 ;
V_217 = F_86 ( & V_4 -> V_57 , V_43 , V_7 ,
& V_4 -> V_59 ) ;
V_21 = F_21 ( V_4 , V_175 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_23 , V_30 ) ;
return V_21 ;
}
return V_217 ;
}
static bool F_87 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
return F_88 ( V_64 , & V_34 -> V_65 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_2 ( V_2 ) ;
struct V_3 * V_4 ;
int error = 0 ;
int V_21 ;
T_3 V_8 ;
F_33 ( & V_6 -> V_157 ) ;
if ( V_6 -> V_158 ) {
V_21 = F_52 ( V_2 , V_218 ) ;
if ( V_21 ) {
F_34 ( & V_6 -> V_157 ) ;
return V_21 ;
}
}
F_34 ( & V_6 -> V_157 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_219 ; V_8 ++ ) {
V_4 = V_2 -> V_4 [ V_8 ] ;
if ( ! F_73 ( & V_4 -> V_4 ) )
continue;
V_21 = F_21 ( V_4 , V_218 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_23 , V_30 ) ;
++ error ;
}
}
if ( error )
return - V_29 ;
return 0 ;
}
