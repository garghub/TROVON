static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_2 -> V_7 . V_8 = V_2 -> V_8 ;
V_2 -> V_7 . V_9 = V_2 -> V_9 ;
V_2 -> V_7 . V_10 =
( V_2 -> V_11 . V_12 & V_13 ) != 0 ;
F_3 ( V_2 ) ;
F_4 ( V_2 , V_2 -> V_11 . V_12 ) ;
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_16 , * V_17 , * V_18 , * V_19 , * V_20 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
F_7 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_2 , V_6 , V_2 -> V_26 ) ;
F_8 (c, n, &port->dmaqueue.list) {
V_22 = F_9 ( V_15 , struct V_21 , V_27 ) ;
F_10 ( V_15 ) ;
F_11 ( V_22 ) ;
}
F_2 ( V_5 , L_3 , V_6 , V_2 -> V_26 ) ;
F_8 (p, q, &port->list_buf_used.list) {
V_24 = F_9 ( V_17 , struct V_23 , V_27 ) ;
F_10 ( V_17 ) ;
F_12 ( V_24 ) ;
}
F_2 ( V_5 , L_4 , V_6 , V_2 -> V_26 ) ;
F_8 (l, v, &port->list_buf_free.list) {
V_24 = F_9 ( V_19 , struct V_23 , V_27 ) ;
F_10 ( V_19 ) ;
F_12 ( V_24 ) ;
}
F_13 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_5 , V_6 , V_2 -> V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_28 * V_29 = & V_2 -> V_30 ;
int V_31 = - V_32 , V_33 ;
int V_34 = 0 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( V_2 -> V_7 . V_35 ==
V_36 ) {
F_2 ( V_5 ,
L_6 ,
V_6 ) ;
V_29 -> V_37 = 128 ;
V_29 -> V_38 = 256 ;
V_29 -> V_39 = 128 ;
V_29 -> V_40 = 2 +
( ( V_41 * 128 ) / V_42 ) ;
} else
if ( V_2 -> V_7 . V_35 ==
V_43 ) {
F_2 ( V_5 ,
L_7 ,
V_6 ) ;
V_29 -> V_37 = 188 ;
V_29 -> V_38 = 312 ;
V_29 -> V_39 = 188 ;
V_29 -> V_40 = 2 +
( ( V_44 * 188 ) / V_42 ) ;
} else
F_15 () ;
V_29 -> V_45 = 8 ;
V_29 -> V_46 = 0 ;
V_29 -> V_47 = NULL ;
V_29 -> V_48 = NULL ;
V_29 -> V_49 = V_2 -> V_50 . V_51 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_50 . V_51 ; V_33 ++ ) {
V_22 = F_16 ( V_2 ,
V_29 -> V_38 *
V_29 -> V_39 ) ;
if ( ! V_22 ) {
F_17 ( V_52 L_8
L_9 ,
V_6 , V_31 ) ;
V_31 = - V_53 ;
goto V_54;
} else {
F_7 ( & V_2 -> V_25 ) ;
F_18 ( & V_22 -> V_27 , & V_2 -> V_55 . V_27 ) ;
F_13 ( & V_2 -> V_25 ) ;
}
}
V_34 = V_29 -> V_38 * V_29 -> V_39 ;
if ( V_56 < 16 )
V_56 = 16 ;
if ( V_56 > 512 )
V_56 = 512 ;
for ( V_33 = 0 ; V_33 < V_56 ; V_33 ++ ) {
V_24 = F_19 ( V_4 , V_34 ) ;
if ( V_24 ) {
F_7 ( & V_2 -> V_25 ) ;
F_18 ( & V_24 -> V_27 , & V_2 -> V_57 . V_27 ) ;
F_13 ( & V_2 -> V_25 ) ;
}
}
V_31 = 0 ;
V_54:
return V_31 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_58 * V_58 , void * V_59 , T_1 * V_12 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_33 ;
F_2 ( V_5 , L_10 , V_6 , ( V_63 ) * V_12 ) ;
for ( V_33 = 0 ; V_33 < F_22 ( V_64 ) ; V_33 ++ ) {
if ( * V_12 & V_64 [ V_33 ] . V_12 )
break;
}
if ( V_33 == F_22 ( V_64 ) )
return - V_65 ;
V_2 -> V_11 = V_64 [ V_33 ] ;
F_5 ( V_2 ) ;
F_2 ( V_5 , L_11 , V_6 , ( V_63 ) * V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_58 * V_58 , void * V_59 ,
struct V_66 * V_33 )
{
int V_16 ;
char * V_67 [] = { L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18 } ;
if ( V_33 -> V_68 >= 7 )
return - V_65 ;
strcpy ( V_33 -> V_69 , V_67 [ V_33 -> V_68 ] ) ;
if ( V_33 -> V_68 == 0 )
V_33 -> type = V_70 ;
else
V_33 -> type = V_71 ;
for ( V_16 = 0 ; V_16 < F_22 ( V_64 ) ; V_16 ++ )
V_33 -> V_72 |= V_64 [ V_16 ] . V_12 ;
return 0 ;
}
static int F_24 ( struct V_58 * V_58 , void * V_59 , unsigned int * V_33 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_25 ( V_2 ) != V_73 )
return - V_74 ;
* V_33 = ( V_2 -> V_75 - 1 ) ;
F_2 ( V_5 , L_19 , V_6 , * V_33 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_58 , void * V_59 , unsigned int V_33 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_19 , V_6 , V_33 ) ;
if ( V_33 >= 7 )
return - V_65 ;
V_2 -> V_75 = V_33 + 1 ;
if ( F_27 ( V_2 ) != V_73 )
return - V_74 ;
return 0 ;
}
static int F_28 ( struct V_58 * V_58 , void * V_59 ,
struct V_76 * V_77 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_77 -> V_68 )
return - V_65 ;
strcpy ( V_77 -> V_69 , L_12 ) ;
V_77 -> type = V_78 ;
V_77 -> V_79 = V_80 | V_81 ;
F_2 ( V_5 , L_20 , V_77 -> type ) ;
return 0 ;
}
static int F_29 ( struct V_58 * V_58 , void * V_59 ,
struct V_76 * V_77 )
{
return 0 ;
}
static int F_30 ( struct V_58 * V_58 , void * V_59 ,
struct V_82 * V_83 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
V_83 -> type = V_78 ;
V_83 -> V_84 = V_2 -> V_85 ;
return 0 ;
}
static int F_31 ( struct V_58 * V_58 , void * V_59 ,
struct V_82 * V_83 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_86 ;
struct V_87 * V_88 ;
struct V_89 V_29 = {
. V_90 = V_78 ,
. V_91 = V_92 ,
. V_72 = V_2 -> V_11 . V_12 ,
. V_84 = V_83 -> V_84
} ;
F_2 ( V_5 , L_21 , V_6 ,
V_83 -> V_84 , V_83 -> V_93 ) ;
if ( V_83 -> V_93 != 0 )
return - V_65 ;
if ( V_83 -> type != V_78 )
return - V_65 ;
V_2 -> V_85 = V_83 -> V_84 ;
if ( V_2 -> V_26 == V_94 )
V_86 = & V_4 -> V_95 [ V_96 ] ;
else
if ( V_2 -> V_26 == V_97 )
V_86 = & V_4 -> V_95 [ V_98 ] ;
else
F_15 () ;
V_88 = V_86 -> V_99 . V_100 ;
if ( V_88 && V_88 -> V_101 . V_102 . V_103 )
V_88 -> V_101 . V_102 . V_103 ( V_88 , & V_29 ) ;
else
F_17 ( V_52 L_22 , V_6 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_58 * V_58 , void * V_59 ,
struct V_104 * V_105 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_23 , V_6 ,
V_105 -> V_12 , V_105 -> V_106 ) ;
switch ( V_105 -> V_12 ) {
case V_107 :
V_105 -> V_106 = V_2 -> V_108 ;
break;
case V_109 :
V_105 -> V_106 = V_2 -> V_110 ;
break;
case V_111 :
V_105 -> V_106 = V_2 -> V_112 ;
break;
case V_113 :
V_105 -> V_106 = V_2 -> V_114 ;
break;
case V_115 :
V_105 -> V_106 = V_2 -> V_116 ;
break;
case V_117 :
V_105 -> V_106 = V_2 -> V_118 ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_33 ( struct V_58 * V_58 , void * V_59 ,
struct V_104 * V_105 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_119 = 0 ;
F_2 ( V_5 , L_23 , V_6 ,
V_105 -> V_12 , V_105 -> V_106 ) ;
switch ( V_105 -> V_12 ) {
case V_107 :
if ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 <= 255 ) ) {
V_2 -> V_108 = V_105 -> V_106 ;
F_34 ( V_2 ,
V_120 ) ;
} else
V_119 = - V_65 ;
break;
case V_109 :
if ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 <= 255 ) ) {
V_2 -> V_110 = V_105 -> V_106 ;
F_34 ( V_2 , V_121 ) ;
} else
V_119 = - V_65 ;
break;
case V_111 :
if ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 <= 255 ) ) {
V_2 -> V_112 = V_105 -> V_106 ;
F_34 ( V_2 ,
V_122 ) ;
} else
V_119 = - V_65 ;
break;
case V_113 :
if ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 <= 255 ) ) {
V_2 -> V_114 = V_105 -> V_106 ;
F_34 ( V_2 , V_123 ) ;
} else
V_119 = - V_65 ;
break;
case V_115 :
if ( ( V_105 -> V_106 >= 0 ) && ( V_105 -> V_106 <= 255 ) ) {
V_2 -> V_116 = V_105 -> V_106 ;
F_34 ( V_2 , V_124 ) ;
} else
V_119 = - V_65 ;
break;
case V_117 :
if ( ( V_105 -> V_106 >= - 83 ) && ( V_105 -> V_106 <= 24 ) ) {
V_2 -> V_118 = V_105 -> V_106 ;
F_35 ( V_2 , V_2 -> V_118 ) ;
} else
V_119 = - V_65 ;
break;
default:
V_119 = - V_65 ;
}
return V_119 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_127 * V_29 = & V_2 -> V_7 ;
switch ( V_126 -> V_12 ) {
case V_128 :
V_126 -> V_106 = V_29 -> V_129 ;
break;
case V_130 :
V_126 -> V_106 = V_29 -> V_35 ;
break;
case V_131 :
V_126 -> V_106 = V_29 -> V_132 ;
break;
case V_133 :
V_126 -> V_106 = V_29 -> V_134 ;
break;
case V_135 :
V_126 -> V_106 = V_29 -> V_136 ;
break;
case V_137 :
V_126 -> V_106 = V_29 -> V_138 ;
break;
case V_139 :
V_126 -> V_106 = V_29 -> V_140 ;
break;
case V_141 :
V_126 -> V_106 = V_29 -> V_142 ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_37 ( struct V_58 * V_58 , void * V_59 ,
struct V_143 * V_144 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
int V_33 , V_145 = 0 ;
if ( V_144 -> V_146 == V_147 ) {
for ( V_33 = 0 ; V_33 < V_144 -> V_148 ; V_33 ++ ) {
struct V_125 * V_126 = V_144 -> V_149 + V_33 ;
V_145 = F_36 ( V_2 , V_126 ) ;
if ( V_145 ) {
V_144 -> V_150 = V_33 ;
break;
}
}
return V_145 ;
}
return - V_65 ;
}
static int F_38 ( struct V_125 * V_126 , int V_151 )
{
int V_119 = - V_65 ;
switch ( V_126 -> V_12 ) {
case V_128 :
if ( ( V_126 -> V_106 >= V_152 ) &&
( V_126 -> V_106 <= V_153 ) )
V_119 = 0 ;
break;
case V_130 :
if ( ( V_126 -> V_106 == V_36 ) ||
( V_126 -> V_106 == V_43 ) )
V_119 = 0 ;
break;
case V_131 :
if ( ( V_126 -> V_106 >= 0 ) &&
( V_126 -> V_106 <= 1 ) )
V_119 = 0 ;
break;
case V_133 :
if ( ( V_126 -> V_106 >= V_154 ) &&
( V_126 -> V_106 <= V_155 ) )
V_119 = 0 ;
break;
case V_141 :
if ( ( V_126 -> V_106 >= 0 ) &&
( V_126 -> V_106 <= 255 ) )
V_119 = 0 ;
break;
case V_135 :
if ( ( V_126 -> V_106 == V_156 ) ||
( V_126 -> V_106 == V_157 ) )
V_119 = 0 ;
break;
case V_137 :
if ( ( V_126 -> V_106 >= 1 ) &&
( V_126 -> V_106 <= 3 ) )
V_119 = 0 ;
break;
case V_139 :
if ( ( V_126 -> V_106 >= V_152 ) &&
( V_126 -> V_106 <= V_153 ) )
V_119 = 0 ;
break;
default:
V_119 = - V_65 ;
}
return V_119 ;
}
static int F_39 ( struct V_58 * V_58 , void * V_59 ,
struct V_143 * V_144 )
{
int V_33 , V_145 = 0 ;
if ( V_144 -> V_146 == V_147 ) {
for ( V_33 = 0 ; V_33 < V_144 -> V_148 ; V_33 ++ ) {
struct V_125 * V_126 = V_144 -> V_149 + V_33 ;
V_145 = F_38 ( V_126 , 0 ) ;
if ( V_145 ) {
V_144 -> V_150 = V_33 ;
break;
}
}
return V_145 ;
}
return - V_65 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_127 * V_29 = & V_2 -> V_7 ;
int V_119 = 0 ;
switch ( V_126 -> V_12 ) {
case V_128 :
V_29 -> V_129 = V_126 -> V_106 ;
break;
case V_130 :
V_29 -> V_35 = V_126 -> V_106 ;
break;
case V_131 :
V_29 -> V_132 = V_126 -> V_106 ;
V_119 = F_41 ( V_2 , V_29 -> V_132 ) ;
if ( V_119 != V_73 ) {
F_17 ( V_52 L_24 , V_6 ,
V_119 ) ;
V_119 = - V_74 ;
}
break;
case V_133 :
V_29 -> V_134 = V_126 -> V_106 ;
V_119 = F_42 ( V_2 ) ;
if ( V_119 != V_73 ) {
F_17 ( V_52 L_24 , V_6 ,
V_119 ) ;
V_119 = - V_74 ;
}
break;
case V_135 :
V_29 -> V_136 = V_126 -> V_106 ;
break;
case V_137 :
V_29 -> V_138 = V_126 -> V_106 ;
break;
case V_139 :
V_29 -> V_140 = V_126 -> V_106 ;
break;
case V_141 :
V_29 -> V_142 = V_126 -> V_106 ;
break;
default:
return - V_65 ;
}
return V_119 ;
}
static int F_43 ( struct V_58 * V_58 , void * V_59 ,
struct V_143 * V_144 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
int V_33 , V_145 = 0 ;
if ( V_144 -> V_146 == V_147 ) {
for ( V_33 = 0 ; V_33 < V_144 -> V_148 ; V_33 ++ ) {
struct V_125 * V_126 = V_144 -> V_149 + V_33 ;
V_145 = F_38 ( V_126 , 0 ) ;
if ( V_145 ) {
V_144 -> V_150 = V_33 ;
break;
}
V_145 = F_40 ( V_2 , V_126 ) ;
if ( V_145 ) {
V_144 -> V_150 = V_33 ;
break;
}
}
return V_145 ;
}
return - V_65 ;
}
static int F_44 ( struct V_58 * V_58 , void * V_59 ,
struct V_158 * V_159 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
strcpy ( V_159 -> V_160 , V_4 -> V_69 ) ;
F_45 ( V_159 -> V_161 , V_162 [ V_4 -> V_163 ] . V_69 ,
sizeof( V_159 -> V_161 ) ) ;
sprintf ( V_159 -> V_164 , L_25 , F_46 ( V_4 -> V_165 ) ) ;
V_159 -> V_166 =
V_167 |
V_168 |
0 ;
V_159 -> V_166 |= V_169 ;
V_159 -> V_170 = 0 ;
return 0 ;
}
static int F_47 ( struct V_58 * V_58 , void * V_59 ,
struct V_171 * V_83 )
{
if ( V_83 -> V_68 != 0 )
return - V_65 ;
F_45 ( V_83 -> V_172 , L_26 , sizeof( V_83 -> V_172 ) ) ;
V_83 -> V_173 = V_174 ;
return 0 ;
}
static int F_48 ( struct V_58 * V_58 , void * V_59 ,
struct V_175 * V_83 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_83 -> V_176 . V_177 . V_173 = V_174 ;
V_83 -> V_176 . V_177 . V_178 = 0 ;
V_83 -> V_176 . V_177 . V_179 =
V_2 -> V_180 * V_2 -> V_181 ;
V_83 -> V_176 . V_177 . V_182 = 0 ;
V_83 -> V_176 . V_177 . V_8 = V_2 -> V_8 ;
V_83 -> V_176 . V_177 . V_9 = V_2 -> V_9 ;
F_2 ( V_5 , L_27 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_49 ( struct V_58 * V_58 , void * V_59 ,
struct V_175 * V_83 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_83 -> V_176 . V_177 . V_173 = V_174 ;
V_83 -> V_176 . V_177 . V_178 = 0 ;
V_83 -> V_176 . V_177 . V_179 =
V_2 -> V_180 * V_2 -> V_181 ;
V_83 -> V_176 . V_177 . V_182 = 0 ;
F_2 ( V_5 , L_28 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_50 ( struct V_58 * V_58 , void * V_59 ,
struct V_175 * V_83 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_83 -> V_176 . V_177 . V_173 = V_174 ;
V_83 -> V_176 . V_177 . V_178 = 0 ;
V_83 -> V_176 . V_177 . V_179 =
V_2 -> V_180 * V_2 -> V_181 ;
V_83 -> V_176 . V_177 . V_182 = 0 ;
F_2 ( V_5 , L_29 ,
V_83 -> V_176 . V_177 . V_8 , V_83 -> V_176 . V_177 . V_9 , V_83 -> V_176 . V_177 . V_183 ) ;
return 0 ;
}
static int F_51 ( struct V_58 * V_58 , void * V_59 )
{
return 0 ;
}
static int F_52 ( struct V_127 * V_29 ,
struct V_184 * V_15 )
{
switch ( V_15 -> V_12 ) {
case V_107 :
return F_53 ( V_15 , 0x0 , 0xff , 1 , 127 ) ;
case V_109 :
return F_53 ( V_15 , 0x0 , 0xff , 1 , 66 ) ;
case V_111 :
return F_53 ( V_15 , 0x0 , 0xff , 1 , 62 ) ;
case V_113 :
return F_53 ( V_15 , 0x0 , 0xff , 1 , 128 ) ;
case V_115 :
return F_53 ( V_15 , 0x0 , 0x0f , 1 , 8 ) ;
case V_131 :
return F_53 ( V_15 , 0x0 , 0x01 , 1 , 0 ) ;
case V_117 :
return F_53 ( V_15 , - 83 , 24 , 1 , 20 ) ;
case V_128 :
return F_53 ( V_15 ,
V_152 , V_153 ,
100000 , V_185 ) ;
case V_130 :
return F_53 ( V_15 ,
V_36 ,
V_43 ,
1 , V_36 ) ;
case V_133 :
return F_53 ( V_15 ,
V_154 ,
V_155 ,
1 , V_186 ) ;
case V_141 :
return F_53 ( V_15 , 1 , 255 , 1 , 15 ) ;
case V_135 :
return F_53 ( V_15 ,
V_156 ,
V_157 ,
1 , V_156 ) ;
case V_137 :
return F_53 ( V_15 ,
1 , 3 , 1 , 1 ) ;
case V_139 :
return F_53 ( V_15 ,
V_152 , V_153 ,
100000 , V_185 ) ;
default:
return - V_65 ;
}
}
static int F_54 ( struct V_58 * V_58 , void * V_59 ,
struct V_184 * V_15 )
{
struct V_60 * V_61 = V_59 ;
struct V_1 * V_2 = V_61 -> V_2 ;
int V_33 , V_187 ;
V_63 V_12 = V_15 -> V_12 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_187 = ! ! ( V_12 & V_188 ) ;
V_15 -> V_12 = V_12 & ~ V_188 ;
for ( V_33 = 0 ; V_33 < F_22 ( V_189 ) ; V_33 ++ ) {
if ( V_187 ) {
if ( V_15 -> V_12 < V_189 [ V_33 ] )
V_15 -> V_12 = V_189 [ V_33 ] ;
else
continue;
}
if ( V_15 -> V_12 == V_189 [ V_33 ] )
return F_52 ( & V_2 -> V_7 , V_15 ) ;
if ( V_15 -> V_12 < V_189 [ V_33 ] )
break;
}
return - V_65 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_119 ;
V_119 = F_56 ( V_2 , V_190 ) ;
if ( ( V_119 != V_73 ) && ( V_119 != V_191 ) ) {
F_17 ( V_52 L_30 ,
V_6 , V_119 ) ;
V_119 = - V_74 ;
} else {
F_2 ( V_5 , L_31 , V_6 ) ;
V_119 = 0 ;
}
return V_119 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_119 ;
V_119 = F_56 ( V_2 , V_192 ) ;
if ( ( V_119 != V_73 ) && ( V_119 != V_191 ) ) {
F_17 ( V_52 L_32 ,
V_6 , V_119 ) ;
V_119 = - V_74 ;
} else {
F_2 ( V_5 , L_33 , V_6 ) ;
V_119 = 0 ;
}
return V_119 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_119 ;
V_119 = F_56 ( V_2 , V_193 ) ;
if ( ( V_119 != V_73 ) && ( V_119 != V_191 ) ) {
F_17 ( V_52 L_34 ,
V_6 , V_119 ) ;
V_119 = - V_74 ;
} else {
F_2 ( V_5 , L_35 , V_6 ) ;
V_119 = 0 ;
}
return V_119 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_15 , * V_16 ;
int V_119 ;
F_2 ( V_5 , L_36 , V_6 , V_2 -> V_26 ) ;
V_119 = F_58 ( V_2 ) ;
V_119 = F_57 ( V_2 ) ;
V_119 = F_55 ( V_2 ) ;
F_2 ( V_5 , L_37 , V_6 ,
V_2 -> V_26 ) ;
F_7 ( & V_2 -> V_25 ) ;
F_8 (c, n, &port->dmaqueue.list) {
V_22 = F_9 ( V_15 , struct V_21 , V_27 ) ;
V_22 -> V_194 = V_195 ;
V_22 -> V_196 = 0 ;
}
F_8 (c, n, &port->list_buf_used.list) {
V_24 = F_9 ( V_15 , struct V_23 , V_27 ) ;
V_24 -> V_196 = 0 ;
F_60 ( & V_24 -> V_27 , & V_2 -> V_57 . V_27 ) ;
}
F_13 ( & V_2 -> V_25 ) ;
F_6 ( V_2 ) ;
F_2 ( V_5 , L_38 , V_6 , V_2 -> V_26 ) ;
return V_119 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 , V_119 = 0 ;
F_2 ( V_5 , L_36 , V_6 , V_2 -> V_26 ) ;
V_2 -> V_197 = 0 ;
F_14 ( V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
V_31 = F_56 ( V_2 , V_192 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_191 ) ) {
F_17 ( V_52 L_39 ,
V_6 , V_31 ) ;
V_31 = F_56 ( V_2 , V_190 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_191 ) ) {
F_17 ( V_52 L_40
L_41 , V_6 , V_31 ) ;
}
V_119 = - V_74 ;
goto V_198;
} else
F_2 ( V_5 , L_42 , V_6 ) ;
V_31 = F_56 ( V_2 , V_193 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_191 ) ) {
F_17 ( V_52 L_43 ,
V_6 , V_31 ) ;
V_31 = F_56 ( V_2 , V_190 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_191 ) ) {
F_17 ( V_52 L_44
L_41 , V_6 , V_31 ) ;
}
V_119 = - V_74 ;
goto V_198;
} else
F_2 ( V_5 , L_35 , V_6 ) ;
V_31 = F_56 ( V_2 , V_199 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_191 ) ) {
F_17 ( V_52 L_45 ,
V_6 , V_31 ) ;
V_31 = F_56 ( V_2 , V_190 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_191 ) ) {
F_17 ( V_52 L_46
L_41 , V_6 , V_31 ) ;
}
V_119 = - V_74 ;
} else
F_2 ( V_5 , L_47 , V_6 ) ;
V_198:
return V_119 ;
}
static int F_65 ( struct V_58 * V_58 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
V_2 = (struct V_1 * ) F_66 ( F_67 ( V_58 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_61 = F_68 ( sizeof( * V_61 ) , V_200 ) ;
if ( NULL == V_61 )
return - V_53 ;
V_58 -> V_62 = V_61 ;
V_61 -> V_2 = V_2 ;
return 0 ;
}
static int F_69 ( struct V_58 * V_58 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( F_70 ( & V_61 -> V_201 , 1 , 0 ) == 1 ) {
if ( F_71 ( & V_2 -> V_202 ) == 0 ) {
F_59 ( V_2 ) ;
}
}
V_58 -> V_62 = NULL ;
F_72 ( V_61 ) ;
return 0 ;
}
struct V_23 * F_73 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_63 V_203 ;
F_7 ( & V_2 -> V_25 ) ;
if ( ! F_74 ( & V_2 -> V_204 . V_27 ) ) {
V_24 = F_75 ( & V_2 -> V_204 . V_27 ,
struct V_23 , V_27 ) ;
if ( V_205 ) {
V_203 = F_76 ( 0 , V_24 -> V_206 , V_24 -> V_207 ) ;
if ( V_203 != V_24 -> V_203 ) {
F_17 ( V_52
L_48 ,
V_6 ,
V_24 , V_24 -> V_203 , V_203 ) ;
}
}
}
F_13 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_49 , V_6 , V_24 ) ;
return V_24 ;
}
static T_2 F_77 ( struct V_58 * V_58 , char T_3 * V_208 ,
T_4 V_148 , T_5 * V_196 )
{
struct V_60 * V_61 = V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_119 = 0 ;
int V_209 , V_210 ;
T_6 * V_17 ;
V_2 -> V_211 = V_2 -> V_212 ;
V_2 -> V_212 = F_78 ( V_213 ) ;
V_2 -> V_211 = V_2 -> V_212 -
V_2 -> V_211 ;
F_79 ( & V_2 -> V_214 ,
V_2 -> V_211 ) ;
if ( * V_196 ) {
F_17 ( V_52 L_50 , V_6 ) ;
return - V_215 ;
}
if ( F_70 ( & V_61 -> V_201 , 0 , 1 ) == 0 ) {
if ( F_80 ( & V_2 -> V_202 ) == 1 ) {
if ( F_20 ( V_2 ) < 0 ) {
F_17 ( V_52 L_51 , V_6 ) ;
return - V_65 ;
}
F_61 ( V_2 ) ;
F_81 ( 200 ) ;
}
}
if ( ( V_58 -> V_216 & V_217 ) == 0 ) {
if ( F_82 ( V_2 -> V_218 ,
F_73 ( V_2 ) ) ) {
F_17 ( V_52 L_52 , V_6 ) ;
return - V_219 ;
}
}
V_24 = F_73 ( V_2 ) ;
while ( ( V_148 > 0 ) && V_24 ) {
V_209 = V_24 -> V_207 - V_24 -> V_196 ;
V_210 = V_209 > V_148 ? V_148 : V_209 ;
V_17 = V_24 -> V_206 + V_24 -> V_196 ;
F_2 ( V_5 ,
L_53 ,
V_6 , ( int ) V_148 , V_210 , V_209 , V_24 , V_24 -> V_196 ) ;
if ( F_83 ( V_208 , V_17 , V_210 ) ) {
F_17 ( V_52 L_54 , V_6 ) ;
if ( ! V_119 ) {
F_17 ( V_52 L_55 , V_6 ) ;
V_119 = - V_220 ;
}
goto V_145;
}
V_24 -> V_196 += V_210 ;
V_148 -= V_210 ;
V_208 += V_210 ;
V_119 += V_210 ;
if ( V_24 -> V_196 > V_24 -> V_207 )
F_17 ( V_52 L_56 ) ;
if ( V_24 -> V_196 == V_24 -> V_207 ) {
V_24 -> V_196 = 0 ;
F_7 ( & V_2 -> V_25 ) ;
F_60 ( & V_24 -> V_27 , & V_2 -> V_57 . V_27 ) ;
F_13 ( & V_2 -> V_25 ) ;
if ( ( V_58 -> V_216 & V_217 ) == 0 ) {
if ( F_82 ( V_2 -> V_218 ,
F_73 ( V_2 ) ) ) {
break;
}
}
V_24 = F_73 ( V_2 ) ;
}
}
V_145:
if ( ! V_119 && ! V_24 )
V_119 = - V_221 ;
return V_119 ;
}
static unsigned int F_84 ( struct V_58 * V_58 , T_7 * V_222 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_58 -> V_62 ;
struct V_1 * V_2 = V_61 -> V_2 ;
unsigned int V_223 = 0 ;
V_2 -> V_224 = V_2 -> V_225 ;
V_2 -> V_225 = F_78 ( V_213 ) ;
V_2 -> V_224 = V_2 -> V_225 -
V_2 -> V_224 ;
F_79 ( & V_2 -> V_226 ,
V_2 -> V_224 ) ;
if ( ! F_85 ( V_2 -> V_227 ) )
return - V_74 ;
if ( F_70 ( & V_61 -> V_201 , 0 , 1 ) == 0 ) {
if ( F_80 ( & V_2 -> V_202 ) == 1 ) {
if ( F_20 ( V_2 ) < 0 )
return - V_65 ;
F_61 ( V_2 ) ;
F_81 ( 200 ) ;
}
}
if ( ( V_58 -> V_216 & V_217 ) == 0 ) {
if ( F_82 ( V_2 -> V_218 ,
F_73 ( V_2 ) ) ) {
return - V_219 ;
}
}
if ( ! F_74 ( & V_2 -> V_204 . V_27 ) )
V_223 |= V_228 | V_229 ;
return V_223 ;
}
int F_86 ( struct V_58 * V_58 , void * V_61 ,
struct V_230 * V_231 )
{
struct V_1 * V_2 = ( (struct V_60 * ) V_61 ) -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
return 0 ;
}
int F_87 ( struct V_58 * V_58 , void * V_61 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = ( (struct V_60 * ) V_61 ) -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( ! F_88 ( V_234 ) )
return - V_235 ;
return 0 ;
}
int F_89 ( struct V_58 * V_58 , void * V_61 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = ( (struct V_60 * ) V_61 ) -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( ! F_88 ( V_234 ) )
return - V_235 ;
return 0 ;
}
static struct V_236 * F_90 (
struct V_1 * V_2 ,
struct V_237 * V_165 ,
struct V_236 * V_238 ,
char * type )
{
struct V_236 * V_239 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_239 = F_91 () ;
if ( NULL == V_239 )
return NULL ;
* V_239 = * V_238 ;
snprintf ( V_239 -> V_69 , sizeof( V_239 -> V_69 ) , L_57 , V_4 -> V_69 ,
type , V_162 [ V_4 -> V_163 ] . V_69 ) ;
V_239 -> V_240 = & V_165 -> V_4 ;
V_239 -> V_241 = V_242 ;
return V_239 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 = - V_32 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( V_2 -> type != V_243 )
F_15 () ;
if ( V_2 -> V_50 . V_244 == 0 ) {
F_17 ( V_52 L_8
L_58 ,
V_6 , V_31 ) ;
V_31 = - V_53 ;
goto V_54;
}
V_2 -> V_11 = V_64 [ 0 ] ;
V_2 -> V_8 = 720 ;
V_2 -> V_75 = 1 ;
V_2 -> V_245 = V_246 ;
V_2 -> V_247 = 0 ;
V_2 -> V_248 = 0 ;
V_2 -> V_108 = 127 ;
V_2 -> V_110 = 66 ;
V_2 -> V_114 = 128 ;
V_2 -> V_112 = 62 ;
V_2 -> V_116 = 8 ;
V_2 -> V_7 . V_129 = V_185 ;
V_2 -> V_7 . V_140 = V_185 ;
V_2 -> V_7 . V_136 = V_157 ;
V_2 -> V_7 . V_35 = V_36 ;
V_2 -> V_7 . V_132 = 0 ;
V_2 -> V_7 . V_134 = V_186 ;
V_2 -> V_7 . V_138 = 1 ;
V_2 -> V_7 . V_142 = V_249 ;
if ( V_2 -> V_11 . V_12 & V_250 )
V_2 -> V_9 = 480 ;
else
V_2 -> V_9 = 576 ;
V_2 -> V_227 = F_90 ( V_2 ,
V_4 -> V_165 , & V_251 , L_59 ) ;
if ( ! V_2 -> V_227 ) {
F_17 ( V_252 L_60 ,
V_4 -> V_69 ) ;
V_31 = - V_53 ;
goto V_54;
}
F_93 ( V_2 -> V_227 , V_2 ) ;
V_31 = F_94 ( V_2 -> V_227 ,
V_253 , - 1 ) ;
if ( V_31 < 0 ) {
F_17 ( V_252 L_61 ,
V_4 -> V_69 ) ;
goto V_54;
}
F_17 ( V_252 L_62 ,
V_4 -> V_69 , V_2 -> V_227 -> V_254 ) ;
F_27 ( V_2 ) ;
F_34 ( V_2 , V_120 ) ;
F_34 ( V_2 , V_121 ) ;
F_34 ( V_2 , V_123 ) ;
F_34 ( V_2 , V_122 ) ;
F_34 ( V_2 , V_124 ) ;
F_41 ( V_2 , 0 ) ;
F_35 ( V_2 , 20 ) ;
F_42 ( V_2 ) ;
F_95 ( V_2 , 0 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
V_31 = 0 ;
V_54:
return V_31 ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_36 , V_6 , V_2 -> V_26 ) ;
if ( V_2 -> type != V_243 )
F_15 () ;
if ( V_2 -> V_227 ) {
if ( V_2 -> V_227 -> V_255 != - 1 )
F_97 ( V_2 -> V_227 ) ;
else
V_242 ( V_2 -> V_227 ) ;
V_2 -> V_227 = NULL ;
}
F_2 ( V_5 , L_5 , V_6 , V_2 -> V_26 ) ;
}
