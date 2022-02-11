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
static int F_36 ( struct V_1 * V_2 )
{
T_2 V_101 [ V_102 ] ;
T_2 V_103 ;
T_2 V_104 = 0 ;
int V_21 ;
T_3 V_8 ;
V_21 = F_35 ( V_2 , & V_103 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 , L_12 ,
V_30 , V_21 ) ;
return 0 ;
}
if ( V_103 != V_100 ) {
V_21 = F_17 ( V_2 ,
V_98 +
V_105 ,
sizeof( V_101 ) , V_101 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_13 ,
V_30 , V_21 ) ;
return 0 ;
}
F_37 ( & V_2 -> V_17 -> V_19 ,
L_14 , V_30 ,
V_103 ) ;
} else {
V_21 = F_17 ( V_2 ,
V_106 , V_9 ,
V_101 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_11 , V_30 ,
V_21 ) ;
return 0 ;
}
F_37 ( & V_2 -> V_17 -> V_19 , L_15 ,
V_30 ) ;
}
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 ) {
if ( V_101 [ V_8 ] & V_11 )
continue;
++ V_104 ;
}
if ( V_104 )
return V_104 ;
F_38 ( & V_2 -> V_17 -> V_19 , L_16 ,
V_30 ) ;
return 4 ;
}
static void F_39 ( struct V_107 * V_108 ,
struct V_3 * V_4 ,
struct V_109 * V_110 )
{
T_2 V_111 = 0 ;
int V_21 ;
T_4 V_112 ;
if ( F_40 ( V_108 ) == V_113 )
F_32 ( V_4 , 0 , V_89 | V_90 ) ;
else if ( V_110 && ( V_110 -> V_114 & V_115 ) == V_113 )
F_32 ( V_4 , V_89 | V_90 , 0 ) ;
if ( F_41 ( V_108 ) ) {
V_111 |= V_116 ;
if ( ! F_42 ( V_108 ) )
V_111 |= V_117 ;
if ( F_43 ( V_108 ) )
V_111 |= V_118 ;
}
if ( F_44 ( V_108 ) )
V_111 |= V_119 ;
switch ( F_45 ( V_108 ) ) {
case V_120 :
V_111 |= V_121 ;
break;
case V_122 :
V_111 |= V_123 ;
break;
case V_124 :
V_111 |= V_125 ;
break;
default:
case V_126 :
V_111 |= V_127 ;
break;
}
V_112 = F_46 ( V_108 ) ;
if ( ! V_112 )
return;
if ( V_112 > V_82 ) {
if ( V_110 )
V_112 = F_47 ( V_110 ) ;
else
V_112 = V_128 ;
F_48 ( V_108 , V_112 , V_112 ) ;
}
F_37 ( & V_4 -> V_19 , L_17 , V_30 , V_112 ) ;
V_21 = F_31 ( V_4 , V_112 , V_111 ) ;
if ( V_21 < 0 ) {
F_7 ( & V_4 -> V_19 , L_18 ,
V_30 , V_21 ) ;
}
}
static int F_49 ( struct V_1 * V_2 , T_5 V_62 )
{
return F_50 ( V_2 -> V_4 [ 0 ] , V_62 ) ;
}
static void F_51 ( struct V_3 * V_4 , T_2 V_129 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
struct V_107 * V_108 ;
unsigned long V_62 ;
T_2 V_130 ;
if ( ! ( V_129 & V_131 ) )
return;
F_22 ( & V_34 -> V_132 , V_62 ) ;
V_130 = V_34 -> V_133 ;
V_34 -> V_133 = V_129 ;
F_24 ( & V_34 -> V_132 , V_62 ) ;
F_37 ( & V_4 -> V_19 , L_19 , V_30 , V_130 ,
V_129 ) ;
if ( V_129 & V_134 )
V_4 -> V_135 . V_136 ++ ;
if ( V_129 & V_137 )
V_4 -> V_135 . V_138 ++ ;
if ( V_129 & V_139 )
V_4 -> V_135 . V_140 ++ ;
if ( V_129 & V_141 )
V_4 -> V_135 . V_142 ++ ;
F_52 ( & V_4 -> V_4 . V_143 ) ;
if ( ! ( V_129 & V_139 ) )
return;
F_37 ( & V_4 -> V_19 , L_20 ,
V_30 , V_34 -> V_35 , V_130 , V_129 ) ;
V_108 = F_53 ( & V_4 -> V_4 ) ;
if ( ! V_108 )
return;
F_54 ( V_4 , V_108 , V_129 & V_144 ) ;
F_55 ( V_108 ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
unsigned long V_62 ;
int V_21 ;
T_2 V_129 ;
V_21 = F_13 ( V_4 , V_145 , & V_129 ) ;
if ( V_21 )
return V_21 ;
F_22 ( & V_34 -> V_132 , V_62 ) ;
V_34 -> V_133 = V_129 ;
F_24 ( & V_34 -> V_132 , V_62 ) ;
return 0 ;
}
static int F_57 ( struct V_107 * V_108 , struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 -> V_2 ) ;
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_21 ;
V_21 = F_11 ( V_4 ,
V_81 , V_79 |
V_146 | V_147 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_21 , V_30 ,
V_21 ) ;
return V_21 ;
}
if ( V_108 )
F_39 ( V_108 , V_4 , NULL ) ;
V_21 = F_56 ( V_4 ) ;
if ( V_21 )
return V_21 ;
F_33 ( & V_6 -> V_148 ) ;
if ( ! V_6 -> V_149 ) {
V_21 = F_49 ( V_4 -> V_2 , V_23 ) ;
if ( V_21 )
goto exit;
}
V_6 -> V_149 ++ ;
exit:
F_34 ( & V_6 -> V_148 ) ;
F_27 ( V_64 , & V_34 -> V_65 ) ;
return V_21 ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 -> V_2 ) ;
struct V_3 * V_150 = V_4 -> V_2 -> V_4 [ 0 ] ;
unsigned long V_62 ;
T_3 V_8 ;
F_59 ( V_4 -> V_66 [ 0 ] ) ;
F_22 ( & V_4 -> V_59 , V_62 ) ;
F_60 ( & V_4 -> V_57 ) ;
F_24 ( & V_4 -> V_59 , V_62 ) ;
F_33 ( & V_6 -> V_148 ) ;
V_6 -> V_149 -- ;
if ( ! V_6 -> V_149 ) {
for ( V_8 = 0 ; V_8 < F_61 ( V_150 -> V_151 ) ; ++ V_8 )
F_59 ( V_150 -> V_151 [ V_8 ] ) ;
}
F_34 ( & V_6 -> V_148 ) ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_152 T_6 * V_153 )
{
struct V_33 * V_34 ;
struct V_152 V_22 ;
V_34 = F_12 ( V_4 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . type = V_154 ;
V_22 . V_4 = V_4 -> V_12 ;
V_22 . line = V_4 -> V_155 ;
V_22 . V_156 = V_82 ;
if ( F_63 ( V_153 , & V_22 , sizeof( * V_153 ) ) )
return - V_157 ;
return 0 ;
}
static int F_64 ( struct V_107 * V_108 , unsigned int V_158 ,
unsigned long V_159 )
{
struct V_3 * V_4 = V_108 -> V_160 ;
struct V_152 T_6 * V_43 = (struct V_152 T_6 * ) V_159 ;
switch ( V_158 ) {
case V_161 :
return F_62 ( V_4 , V_43 ) ;
default:
break;
}
return - V_162 ;
}
static void F_65 ( struct V_3 * V_4 ,
T_2 * V_15 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_35 = V_15 [ 0 ] ;
T_3 V_47 = 0 ;
T_3 V_8 ;
char V_163 ;
int V_21 ;
T_2 V_164 ;
switch ( V_15 [ 1 ] ) {
case V_165 :
F_27 ( V_64 , & V_34 -> V_65 ) ;
V_21 = F_21 ( V_4 , V_166 ) ;
if ( V_21 )
F_7 ( & V_4 -> V_19 , L_22 , V_30 ) ;
return;
case V_167 :
F_51 ( V_4 , V_15 [ 3 ] ) ;
return;
case V_168 :
V_47 = V_15 [ 2 ] ;
if ( V_47 > V_169 ) {
F_7 ( & V_4 -> V_19 ,
L_23 ,
V_30 , V_35 , V_47 ,
V_169 ) ;
return;
}
break;
default:
F_38 ( & V_4 -> V_19 , L_24 , V_30 ,
V_15 [ 1 ] ) ;
return;
}
for ( V_8 = 4 ; V_8 < 4 + V_47 ; V_8 += 2 ) {
V_163 = V_170 ;
V_164 = V_15 [ V_8 + 1 ] ;
if ( V_164 & V_171 ) {
if ( V_164 & V_172 ) {
V_163 = V_173 ;
V_4 -> V_135 . V_174 ++ ;
F_66 ( V_4 ) ;
} else if ( V_164 & V_175 ) {
V_163 = V_176 ;
V_4 -> V_135 . V_177 ++ ;
} else if ( V_164 & V_178 ) {
V_163 = V_179 ;
V_4 -> V_135 . V_180 ++ ;
}
if ( V_164 & V_181 ) {
V_4 -> V_135 . V_182 ++ ;
F_67 ( & V_4 -> V_4 , 0 ,
V_183 ) ;
}
}
if ( V_4 -> V_4 . V_184 && V_4 -> V_185 ) {
if ( F_68 ( V_4 , V_15 [ V_8 ] ) )
continue;
}
F_67 ( & V_4 -> V_4 , V_15 [ V_8 ] , V_163 ) ;
}
F_69 ( & V_4 -> V_4 ) ;
}
static void F_70 ( struct V_61 * V_61 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_2 * V_43 ;
int V_186 ;
int V_187 ;
T_3 V_8 ;
if ( ! V_61 -> V_188 ||
V_61 -> V_188 % V_55 ) {
return;
}
V_4 = V_61 -> V_189 ;
V_2 = V_4 -> V_2 ;
V_43 = V_61 -> V_190 ;
V_6 = F_2 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_61 -> V_188 ; V_8 += V_55 ) {
V_186 = V_43 [ V_8 ] ;
if ( V_186 >= V_9 ) {
F_7 ( & V_4 -> V_19 ,
L_25 ,
V_30 , V_186 , V_9 ) ;
continue;
}
V_187 = V_6 -> V_191 [ V_186 ] ;
V_4 = V_2 -> V_4 [ V_187 ] ;
if ( F_71 ( & V_4 -> V_4 ) )
F_65 ( V_4 , & V_43 [ V_8 ] ) ;
}
}
static void F_72 ( struct V_61 * V_61 )
{
struct V_3 * V_4 = V_61 -> V_189 ;
switch ( V_61 -> V_21 ) {
case 0 :
break;
case - V_192 :
case - V_193 :
case - V_194 :
F_37 ( & V_4 -> V_19 , L_26 ,
V_30 , V_61 -> V_21 ) ;
return;
case - V_195 :
F_7 ( & V_4 -> V_19 , L_26 ,
V_30 , V_61 -> V_21 ) ;
return;
default:
F_37 ( & V_4 -> V_19 , L_27 ,
V_30 , V_61 -> V_21 ) ;
break;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_196 ;
int V_197 ;
T_3 V_8 ;
for ( V_8 = 1 ; V_8 < V_2 -> V_198 ; ++ V_8 ) {
V_196 = V_2 -> V_4 [ 0 ] -> V_199 ;
V_197 = V_2 -> V_4 [ 0 ] -> V_200 ;
V_4 = V_2 -> V_4 [ V_8 ] ;
if ( F_74 ( & V_4 -> V_57 , V_201 , V_23 ) )
return - V_24 ;
V_4 -> V_200 = V_197 ;
V_4 -> V_199 = V_196 ;
V_4 -> V_66 [ 0 ] = F_75 ( 0 , V_23 ) ;
if ( ! V_4 -> V_66 [ 0 ] )
return - V_24 ;
V_4 -> V_67 [ 0 ] = F_76 ( V_197 , V_23 ) ;
if ( ! V_4 -> V_67 [ 0 ] )
return - V_24 ;
F_77 ( V_4 -> V_66 [ 0 ] , V_2 -> V_19 ,
F_78 ( V_2 -> V_19 ,
V_196 ) ,
V_4 -> V_67 [ 0 ] , V_197 ,
V_2 -> type -> V_202 , V_4 ) ;
V_4 -> V_203 = V_4 -> V_66 [ 0 ] ;
V_4 -> V_204 = V_4 -> V_67 [ 0 ] ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
const struct V_205 * V_206 )
{
struct V_207 * V_208 ;
struct V_209 * V_210 ;
struct V_211 * V_19 ;
int V_212 = 0 ;
int V_213 = 0 ;
int V_214 = 0 ;
int V_215 = 0 ;
int V_8 ;
V_19 = & V_2 -> V_17 -> V_19 ;
V_210 = V_2 -> V_17 -> V_216 ;
for ( V_8 = 0 ; V_8 < V_210 -> V_217 . V_218 ; ++ V_8 ) {
V_208 = & V_210 -> V_208 [ V_8 ] . V_217 ;
if ( F_80 ( V_208 ) ) {
++ V_212 ;
V_214 = F_81 ( V_208 ) ;
}
if ( F_82 ( V_208 ) ) {
++ V_213 ;
V_215 = F_81 ( V_208 ) ;
}
}
if ( V_212 != 1 || V_213 != 1 ) {
F_7 ( V_19 , L_28 ) ;
return - V_13 ;
}
if ( V_215 != V_69 ||
V_214 != V_219 ) {
F_7 ( V_19 , L_29 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_97 = 0 ;
int V_21 ;
int V_8 ;
V_6 = F_84 ( & V_2 -> V_17 -> V_19 ,
sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 )
return - V_24 ;
F_85 ( V_2 , V_6 ) ;
F_86 ( & V_6 -> V_148 ) ;
V_21 = F_73 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_35 ( V_2 , & V_6 -> V_103 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 , L_12 ,
V_30 , V_21 ) ;
return V_21 ;
}
if ( V_6 -> V_103 == V_100 ) {
V_21 = F_17 ( V_2 ,
V_106 ,
V_220 ,
V_6 -> V_10 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_30 ,
V_30 , V_21 ) ;
return V_21 ;
}
} else {
V_21 = F_17 ( V_2 ,
V_98 +
V_105 ,
sizeof( V_6 -> V_10 ) ,
V_6 -> V_10 ) ;
if ( V_21 ) {
F_7 ( & V_2 -> V_17 -> V_19 ,
L_31 ,
V_30 , V_6 -> V_103 ,
V_21 ) ;
return V_21 ;
}
}
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 ) {
if ( V_6 -> V_10 [ V_8 ] & V_11 )
continue;
V_6 -> V_191 [ V_8 ] = V_97 ++ ;
F_37 ( & V_2 -> V_17 -> V_19 ,
L_32 , V_30 , V_8 ,
V_6 -> V_191 [ V_8 ] ) ;
}
return 0 ;
}
static int F_87 ( struct V_3 * V_4 )
{
struct V_33 * V_34 ;
int V_221 ;
V_34 = F_84 ( & V_4 -> V_19 , sizeof( * V_34 ) , V_23 ) ;
if ( ! V_34 )
return - V_24 ;
F_88 ( & V_34 -> V_132 ) ;
F_86 ( & V_34 -> V_91 ) ;
V_221 = F_1 ( V_4 -> V_2 , V_4 ) ;
if ( V_221 < 0 )
return V_221 ;
V_34 -> V_35 = V_221 ;
F_89 ( V_4 , V_34 ) ;
F_37 ( & V_4 -> V_19 , L_33 , V_30 ,
V_4 -> V_12 , V_34 -> V_35 ) ;
return 0 ;
}
static int F_90 ( struct V_107 * V_108 )
{
struct V_3 * V_4 = V_108 -> V_160 ;
struct V_33 * V_34 = F_12 ( V_4 ) ;
int V_21 ;
int V_222 ;
T_2 V_129 ;
T_2 V_223 ;
V_21 = F_13 ( V_4 , V_145 , & V_129 ) ;
if ( V_21 )
return V_21 ;
F_33 ( & V_34 -> V_91 ) ;
V_223 = V_34 -> V_93 ;
F_34 ( & V_34 -> V_91 ) ;
V_222 = ( V_223 & V_94 ? V_89 : 0 ) |
( V_223 & V_95 ? V_90 : 0 ) |
( V_129 & V_224 ? V_225 : 0 ) |
( V_129 & V_144 ? V_226 : 0 ) |
( V_129 & V_227 ? V_228 : 0 ) |
( V_129 & V_229 ? V_230 : 0 ) ;
return V_222 ;
}
static int F_91 ( struct V_107 * V_108 , unsigned int V_87 ,
unsigned int V_88 )
{
struct V_3 * V_4 = V_108 -> V_160 ;
return F_32 ( V_4 , V_87 , V_88 ) ;
}
static void F_92 ( struct V_3 * V_4 , int V_231 )
{
if ( V_231 )
F_32 ( V_4 , V_89 | V_90 , 0 ) ;
else
F_32 ( V_4 , 0 , V_89 | V_90 ) ;
}
static int F_93 ( struct V_107 * V_108 , struct V_3 * V_4 ,
const T_2 * V_43 , int V_7 )
{
int V_232 , V_21 ;
if ( ! V_7 )
return 0 ;
V_232 = F_94 ( & V_4 -> V_57 , V_43 , V_7 ,
& V_4 -> V_59 ) ;
V_21 = F_21 ( V_4 , V_166 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_22 , V_30 ) ;
return V_21 ;
}
return V_232 ;
}
static bool F_95 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = F_12 ( V_4 ) ;
return F_96 ( V_64 , & V_34 -> V_65 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_2 ( V_2 ) ;
struct V_3 * V_4 ;
int error = 0 ;
int V_21 ;
T_3 V_8 ;
F_33 ( & V_6 -> V_148 ) ;
if ( V_6 -> V_149 ) {
V_21 = F_49 ( V_2 , V_233 ) ;
if ( V_21 ) {
F_34 ( & V_6 -> V_148 ) ;
return V_21 ;
}
}
F_34 ( & V_6 -> V_148 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_198 ; V_8 ++ ) {
V_4 = V_2 -> V_4 [ V_8 ] ;
if ( ! F_71 ( & V_4 -> V_4 ) )
continue;
V_21 = F_21 ( V_4 , V_233 ) ;
if ( V_21 ) {
F_7 ( & V_4 -> V_19 , L_22 , V_30 ) ;
++ error ;
}
}
if ( error )
return - V_29 ;
return 0 ;
}
