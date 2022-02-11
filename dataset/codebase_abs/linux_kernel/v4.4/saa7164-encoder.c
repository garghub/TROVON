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
int F_21 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_33 ;
F_2 ( V_5 , L_10 , V_6 , ( V_58 ) V_12 ) ;
for ( V_33 = 0 ; V_33 < F_22 ( V_59 ) ; V_33 ++ ) {
if ( V_12 & V_59 [ V_33 ] . V_12 )
break;
}
if ( V_33 == F_22 ( V_59 ) )
return - V_60 ;
V_2 -> V_11 = V_59 [ V_33 ] ;
V_2 -> V_61 = V_12 ;
F_5 ( V_2 ) ;
F_2 ( V_5 , L_11 , V_6 , ( V_58 ) V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_62 * V_62 , void * V_63 , T_1 V_12 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
return F_21 ( V_65 -> V_2 , V_12 ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 * V_12 )
{
* V_12 = V_2 -> V_61 ;
return 0 ;
}
static int F_25 ( struct V_62 * V_62 , void * V_63 , T_1 * V_12 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
return F_24 ( V_65 -> V_2 , V_12 ) ;
}
int F_26 ( struct V_62 * V_62 , void * V_63 , struct V_67 * V_33 )
{
static const char * const V_68 [] = {
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18
} ;
int V_16 ;
if ( V_33 -> V_69 >= 7 )
return - V_60 ;
strcpy ( V_33 -> V_70 , V_68 [ V_33 -> V_69 ] ) ;
if ( V_33 -> V_69 == 0 )
V_33 -> type = V_71 ;
else
V_33 -> type = V_72 ;
for ( V_16 = 0 ; V_16 < F_22 ( V_59 ) ; V_16 ++ )
V_33 -> V_61 |= V_59 [ V_16 ] . V_12 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , unsigned int * V_33 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_28 ( V_2 ) != V_73 )
return - V_74 ;
* V_33 = ( V_2 -> V_75 - 1 ) ;
F_2 ( V_5 , L_19 , V_6 , * V_33 ) ;
return 0 ;
}
static int F_29 ( struct V_62 * V_62 , void * V_63 , unsigned int * V_33 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
return F_27 ( V_65 -> V_2 , V_33 ) ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_33 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_19 , V_6 , V_33 ) ;
if ( V_33 >= 7 )
return - V_60 ;
V_2 -> V_75 = V_33 + 1 ;
if ( F_31 ( V_2 ) != V_73 )
return - V_74 ;
return 0 ;
}
static int F_32 ( struct V_62 * V_62 , void * V_63 , unsigned int V_33 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
return F_30 ( V_65 -> V_2 , V_33 ) ;
}
int F_33 ( struct V_62 * V_62 , void * V_63 , struct V_76 * V_77 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_77 -> V_69 )
return - V_60 ;
strcpy ( V_77 -> V_70 , L_12 ) ;
V_77 -> V_78 = V_79 | V_80 ;
V_77 -> V_81 = V_82 ;
V_77 -> V_83 = V_84 ;
F_2 ( V_5 , L_20 , V_77 -> type ) ;
return 0 ;
}
int F_34 ( struct V_62 * V_62 , void * V_63 ,
const struct V_76 * V_77 )
{
if ( 0 != V_77 -> V_69 )
return - V_60 ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
if ( V_86 -> V_87 )
return - V_60 ;
V_86 -> V_88 = V_2 -> V_89 ;
return 0 ;
}
static int F_36 ( struct V_62 * V_62 , void * V_63 ,
struct V_85 * V_86 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
return F_35 ( V_65 -> V_2 , V_86 ) ;
}
int F_37 ( struct V_1 * V_2 ,
const struct V_85 * V_86 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_90 ;
struct V_91 * V_92 ;
struct V_93 V_29 = {
. V_94 = V_95 ,
. V_96 = V_97 ,
. V_61 = V_2 -> V_11 . V_12 ,
. V_88 = V_86 -> V_88
} ;
F_2 ( V_5 , L_21 , V_6 ,
V_86 -> V_88 , V_86 -> V_87 ) ;
if ( V_86 -> V_87 != 0 )
return - V_60 ;
V_2 -> V_89 = F_38 ( V_86 -> V_88 ,
V_82 , V_84 ) ;
if ( V_2 -> V_26 == V_98 )
V_90 = & V_4 -> V_99 [ V_100 ] ;
else if ( V_2 -> V_26 == V_101 )
V_90 = & V_4 -> V_99 [ V_102 ] ;
else
F_15 () ;
V_92 = V_90 -> V_103 . V_104 ;
if ( V_92 && V_92 -> V_105 . V_106 . V_107 )
V_92 -> V_105 . V_106 . V_107 ( V_92 , & V_29 ) ;
else
F_17 ( V_52 L_22 , V_6 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_62 * V_62 , void * V_63 ,
const struct V_85 * V_86 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
return F_37 ( V_65 -> V_2 , V_86 ) ;
}
static int F_40 ( struct V_108 * V_109 )
{
struct V_1 * V_2 =
F_41 ( V_109 -> V_110 , struct V_1 , V_111 ) ;
struct V_112 * V_29 = & V_2 -> V_7 ;
int V_113 = 0 ;
switch ( V_109 -> V_12 ) {
case V_114 :
V_2 -> V_115 = V_109 -> V_116 ;
F_42 ( V_2 , V_117 ) ;
break;
case V_118 :
V_2 -> V_119 = V_109 -> V_116 ;
F_42 ( V_2 , V_120 ) ;
break;
case V_121 :
V_2 -> V_122 = V_109 -> V_116 ;
F_42 ( V_2 , V_123 ) ;
break;
case V_124 :
V_2 -> V_125 = V_109 -> V_116 ;
F_42 ( V_2 , V_126 ) ;
break;
case V_127 :
V_2 -> V_128 = V_109 -> V_116 ;
F_42 ( V_2 , V_129 ) ;
break;
case V_130 :
V_2 -> V_131 = V_109 -> V_116 ;
F_43 ( V_2 , V_2 -> V_131 ) ;
break;
case V_132 :
V_29 -> V_133 = V_109 -> V_116 ;
break;
case V_134 :
V_29 -> V_35 = V_109 -> V_116 ;
break;
case V_135 :
V_29 -> V_136 = V_109 -> V_116 ;
V_113 = F_44 ( V_2 , V_29 -> V_136 ) ;
if ( V_113 != V_73 ) {
F_17 ( V_52 L_23 , V_6 ,
V_113 ) ;
V_113 = - V_74 ;
}
break;
case V_137 :
V_29 -> V_138 = V_109 -> V_116 ;
V_113 = F_45 ( V_2 ) ;
if ( V_113 != V_73 ) {
F_17 ( V_52 L_23 , V_6 ,
V_113 ) ;
V_113 = - V_74 ;
}
break;
case V_139 :
V_29 -> V_140 = V_109 -> V_116 ;
break;
case V_141 :
V_29 -> V_142 = V_109 -> V_116 ;
break;
case V_143 :
V_29 -> V_144 = V_109 -> V_116 ;
break;
case V_145 :
V_29 -> V_146 = V_109 -> V_116 ;
break;
default:
V_113 = - V_60 ;
}
return V_113 ;
}
static int F_46 ( struct V_62 * V_62 , void * V_63 ,
struct V_147 * V_148 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
strcpy ( V_148 -> V_149 , V_4 -> V_70 ) ;
F_47 ( V_148 -> V_150 , V_151 [ V_4 -> V_152 ] . V_70 ,
sizeof( V_148 -> V_150 ) ) ;
sprintf ( V_148 -> V_153 , L_24 , F_48 ( V_4 -> V_154 ) ) ;
V_148 -> V_155 =
V_156 |
V_157 |
V_158 ;
V_148 -> V_159 = V_148 -> V_155 |
V_160 |
V_161 ;
return 0 ;
}
static int F_49 ( struct V_62 * V_62 , void * V_63 ,
struct V_162 * V_86 )
{
if ( V_86 -> V_69 != 0 )
return - V_60 ;
F_47 ( V_86 -> V_163 , L_25 , sizeof( V_86 -> V_163 ) ) ;
V_86 -> V_164 = V_165 ;
return 0 ;
}
static int F_50 ( struct V_62 * V_62 , void * V_63 ,
struct V_166 * V_86 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_2 ;
V_86 -> V_167 . V_168 . V_164 = V_165 ;
V_86 -> V_167 . V_168 . V_169 = 0 ;
V_86 -> V_167 . V_168 . V_170 = V_171 ;
V_86 -> V_167 . V_168 . V_172 = V_173 ;
V_86 -> V_167 . V_168 . V_174 = V_175 ;
V_86 -> V_167 . V_168 . V_8 = V_2 -> V_8 ;
V_86 -> V_167 . V_168 . V_9 = V_2 -> V_9 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_113 ;
V_113 = F_52 ( V_2 , V_176 ) ;
if ( ( V_113 != V_73 ) && ( V_113 != V_177 ) ) {
F_17 ( V_52 L_26 ,
V_6 , V_113 ) ;
V_113 = - V_74 ;
} else {
F_2 ( V_5 , L_27 , V_6 ) ;
V_113 = 0 ;
}
return V_113 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_113 ;
V_113 = F_52 ( V_2 , V_178 ) ;
if ( ( V_113 != V_73 ) && ( V_113 != V_177 ) ) {
F_17 ( V_52 L_28 ,
V_6 , V_113 ) ;
V_113 = - V_74 ;
} else {
F_2 ( V_5 , L_29 , V_6 ) ;
V_113 = 0 ;
}
return V_113 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_113 ;
V_113 = F_52 ( V_2 , V_179 ) ;
if ( ( V_113 != V_73 ) && ( V_113 != V_177 ) ) {
F_17 ( V_52 L_30 ,
V_6 , V_113 ) ;
V_113 = - V_74 ;
} else {
F_2 ( V_5 , L_31 , V_6 ) ;
V_113 = 0 ;
}
return V_113 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_15 , * V_16 ;
int V_113 ;
F_2 ( V_5 , L_32 , V_6 , V_2 -> V_26 ) ;
V_113 = F_54 ( V_2 ) ;
V_113 = F_53 ( V_2 ) ;
V_113 = F_51 ( V_2 ) ;
F_2 ( V_5 , L_33 , V_6 ,
V_2 -> V_26 ) ;
F_7 ( & V_2 -> V_25 ) ;
F_8 (c, n, &port->dmaqueue.list) {
V_22 = F_9 ( V_15 , struct V_21 , V_27 ) ;
V_22 -> V_180 = V_181 ;
V_22 -> V_182 = 0 ;
}
F_8 (c, n, &port->list_buf_used.list) {
V_24 = F_9 ( V_15 , struct V_23 , V_27 ) ;
V_24 -> V_182 = 0 ;
F_56 ( & V_24 -> V_27 , & V_2 -> V_57 . V_27 ) ;
}
F_13 ( & V_2 -> V_25 ) ;
F_6 ( V_2 ) ;
F_2 ( V_5 , L_34 , V_6 , V_2 -> V_26 ) ;
return V_113 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 , V_113 = 0 ;
F_2 ( V_5 , L_32 , V_6 , V_2 -> V_26 ) ;
V_2 -> V_183 = 0 ;
F_14 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_31 = F_52 ( V_2 , V_178 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_177 ) ) {
F_17 ( V_52 L_35 ,
V_6 , V_31 ) ;
V_31 = F_52 ( V_2 , V_176 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_177 ) ) {
F_17 ( V_52 L_36
L_37 , V_6 , V_31 ) ;
}
V_113 = - V_74 ;
goto V_184;
} else
F_2 ( V_5 , L_38 , V_6 ) ;
V_31 = F_52 ( V_2 , V_179 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_177 ) ) {
F_17 ( V_52 L_39 ,
V_6 , V_31 ) ;
V_31 = F_52 ( V_2 , V_176 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_177 ) ) {
F_17 ( V_52 L_40
L_37 , V_6 , V_31 ) ;
}
V_113 = - V_74 ;
goto V_184;
} else
F_2 ( V_5 , L_31 , V_6 ) ;
V_31 = F_52 ( V_2 , V_185 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_177 ) ) {
F_17 ( V_52 L_41 ,
V_6 , V_31 ) ;
V_31 = F_52 ( V_2 , V_176 ) ;
if ( ( V_31 != V_73 ) && ( V_31 != V_177 ) ) {
F_17 ( V_52 L_42
L_37 , V_6 , V_31 ) ;
}
V_113 = - V_74 ;
} else
F_2 ( V_5 , L_43 , V_6 ) ;
V_184:
return V_113 ;
}
static int F_61 ( struct V_62 * V_62 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
V_2 = (struct V_1 * ) F_62 ( F_63 ( V_62 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_65 = F_64 ( sizeof( * V_65 ) , V_186 ) ;
if ( NULL == V_65 )
return - V_53 ;
V_65 -> V_2 = V_2 ;
F_65 ( & V_65 -> V_65 , F_63 ( V_62 ) ) ;
F_66 ( & V_65 -> V_65 ) ;
V_62 -> V_66 = V_65 ;
return 0 ;
}
static int F_67 ( struct V_62 * V_62 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( F_68 ( & V_65 -> V_187 , 1 , 0 ) == 1 ) {
if ( F_69 ( & V_2 -> V_188 ) == 0 ) {
F_55 ( V_2 ) ;
}
}
F_70 ( & V_65 -> V_65 ) ;
F_71 ( & V_65 -> V_65 ) ;
F_72 ( V_65 ) ;
return 0 ;
}
static struct
V_23 * F_73 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_58 V_189 ;
F_7 ( & V_2 -> V_25 ) ;
if ( ! F_74 ( & V_2 -> V_190 . V_27 ) ) {
V_24 = F_75 ( & V_2 -> V_190 . V_27 ,
struct V_23 , V_27 ) ;
if ( V_191 ) {
V_189 = F_76 ( 0 , V_24 -> V_192 , V_24 -> V_193 ) ;
if ( V_189 != V_24 -> V_189 ) {
F_17 ( V_52
L_44 ,
V_6 ,
V_24 , V_24 -> V_189 , V_189 ) ;
}
}
}
F_13 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_45 , V_6 , V_24 ) ;
return V_24 ;
}
static T_2 F_77 ( struct V_62 * V_62 , char T_3 * V_194 ,
T_4 V_195 , T_5 * V_182 )
{
struct V_64 * V_65 = V_62 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_113 = 0 ;
int V_196 , V_197 ;
T_6 * V_17 ;
V_2 -> V_198 = V_2 -> V_199 ;
V_2 -> V_199 = F_78 ( V_200 ) ;
V_2 -> V_198 = V_2 -> V_199 -
V_2 -> V_198 ;
F_79 ( & V_2 -> V_201 ,
V_2 -> V_198 ) ;
if ( * V_182 ) {
F_17 ( V_52 L_46 , V_6 ) ;
return - V_202 ;
}
if ( F_68 ( & V_65 -> V_187 , 0 , 1 ) == 0 ) {
if ( F_80 ( & V_2 -> V_188 ) == 1 ) {
if ( F_20 ( V_2 ) < 0 ) {
F_17 ( V_52 L_47 , V_6 ) ;
return - V_60 ;
}
F_57 ( V_2 ) ;
F_81 ( 200 ) ;
}
}
if ( ( V_62 -> V_203 & V_204 ) == 0 ) {
if ( F_82 ( V_2 -> V_205 ,
F_73 ( V_2 ) ) ) {
F_17 ( V_52 L_48 , V_6 ) ;
return - V_206 ;
}
}
V_24 = F_73 ( V_2 ) ;
while ( ( V_195 > 0 ) && V_24 ) {
V_196 = V_24 -> V_193 - V_24 -> V_182 ;
V_197 = V_196 > V_195 ? V_195 : V_196 ;
V_17 = V_24 -> V_192 + V_24 -> V_182 ;
F_2 ( V_5 ,
L_49 ,
V_6 , ( int ) V_195 , V_197 , V_196 , V_24 , V_24 -> V_182 ) ;
if ( F_83 ( V_194 , V_17 , V_197 ) ) {
F_17 ( V_52 L_50 , V_6 ) ;
if ( ! V_113 ) {
F_17 ( V_52 L_51 , V_6 ) ;
V_113 = - V_207 ;
}
goto V_208;
}
V_24 -> V_182 += V_197 ;
V_195 -= V_197 ;
V_194 += V_197 ;
V_113 += V_197 ;
if ( V_24 -> V_182 > V_24 -> V_193 )
F_17 ( V_52 L_52 ) ;
if ( V_24 -> V_182 == V_24 -> V_193 ) {
V_24 -> V_182 = 0 ;
F_7 ( & V_2 -> V_25 ) ;
F_56 ( & V_24 -> V_27 , & V_2 -> V_57 . V_27 ) ;
F_13 ( & V_2 -> V_25 ) ;
if ( ( V_62 -> V_203 & V_204 ) == 0 ) {
if ( F_82 ( V_2 -> V_205 ,
F_73 ( V_2 ) ) ) {
break;
}
}
V_24 = F_73 ( V_2 ) ;
}
}
V_208:
if ( ! V_113 && ! V_24 )
V_113 = - V_209 ;
return V_113 ;
}
static unsigned int F_84 ( struct V_62 * V_62 , T_7 * V_210 )
{
unsigned long V_211 = F_85 ( V_210 ) ;
struct V_64 * V_65 =
(struct V_64 * ) V_62 -> V_66 ;
struct V_1 * V_2 = V_65 -> V_2 ;
unsigned int V_212 = F_86 ( V_62 , V_210 ) ;
V_2 -> V_213 = V_2 -> V_214 ;
V_2 -> V_214 = F_78 ( V_200 ) ;
V_2 -> V_213 = V_2 -> V_214 -
V_2 -> V_213 ;
F_79 ( & V_2 -> V_215 ,
V_2 -> V_213 ) ;
if ( ! ( V_211 & ( V_216 | V_217 ) ) )
return V_212 ;
if ( F_68 ( & V_65 -> V_187 , 0 , 1 ) == 0 ) {
if ( F_80 ( & V_2 -> V_188 ) == 1 ) {
if ( F_20 ( V_2 ) < 0 )
return V_212 | V_218 ;
F_57 ( V_2 ) ;
F_81 ( 200 ) ;
}
}
if ( ! F_74 ( & V_2 -> V_190 . V_27 ) )
V_212 |= V_216 | V_217 ;
return V_212 ;
}
static struct V_219 * F_87 (
struct V_1 * V_2 ,
struct V_220 * V_154 ,
struct V_219 * V_221 ,
char * type )
{
struct V_219 * V_222 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_222 = F_88 () ;
if ( NULL == V_222 )
return NULL ;
* V_222 = * V_221 ;
snprintf ( V_222 -> V_70 , sizeof( V_222 -> V_70 ) , L_53 , V_4 -> V_70 ,
type , V_151 [ V_4 -> V_152 ] . V_70 ) ;
V_222 -> V_223 = & V_4 -> V_223 ;
V_222 -> V_224 = V_225 ;
return V_222 ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_226 * V_227 = & V_2 -> V_111 ;
int V_31 = - V_32 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( V_2 -> type != V_228 )
F_15 () ;
if ( V_2 -> V_50 . V_229 == 0 ) {
F_17 ( V_52 L_8
L_54 ,
V_6 , V_31 ) ;
V_31 = - V_53 ;
goto V_54;
}
V_2 -> V_11 = V_59 [ 0 ] ;
V_2 -> V_8 = 720 ;
V_2 -> V_75 = 1 ;
V_2 -> V_230 = V_231 ;
V_2 -> V_232 = 0 ;
V_2 -> V_233 = 0 ;
V_2 -> V_89 = V_82 ;
F_90 ( V_227 , 14 ) ;
F_91 ( V_227 , & V_234 ,
V_114 , 0 , 255 , 1 , 127 ) ;
F_91 ( V_227 , & V_234 ,
V_118 , 0 , 255 , 1 , 66 ) ;
F_91 ( V_227 , & V_234 ,
V_121 , 0 , 255 , 1 , 62 ) ;
F_91 ( V_227 , & V_234 ,
V_124 , 0 , 255 , 1 , 128 ) ;
F_91 ( V_227 , & V_234 ,
V_127 , 0x0 , 0x0f , 1 , 8 ) ;
F_91 ( V_227 , & V_234 ,
V_135 , 0x0 , 0x01 , 1 , 0 ) ;
F_91 ( V_227 , & V_234 ,
V_130 , - 83 , 24 , 1 , 20 ) ;
F_91 ( V_227 , & V_234 ,
V_132 ,
V_235 , V_236 ,
100000 , V_237 ) ;
F_92 ( V_227 , & V_234 ,
V_134 ,
V_43 , 0 ,
V_36 ) ;
F_92 ( V_227 , & V_234 ,
V_137 ,
V_238 , 0 ,
V_239 ) ;
F_91 ( V_227 , & V_234 ,
V_145 , 1 , 255 , 1 , 15 ) ;
F_92 ( V_227 , & V_234 ,
V_139 ,
V_240 , 0 ,
V_241 ) ;
F_91 ( V_227 , & V_234 ,
V_141 , 1 , 3 , 1 , 1 ) ;
F_91 ( V_227 , & V_234 ,
V_143 ,
V_235 , V_236 ,
100000 , V_237 ) ;
if ( V_227 -> error ) {
V_31 = V_227 -> error ;
goto V_54;
}
V_2 -> V_61 = V_242 ;
if ( V_2 -> V_11 . V_12 & V_243 )
V_2 -> V_9 = 480 ;
else
V_2 -> V_9 = 576 ;
V_2 -> V_244 = F_87 ( V_2 ,
V_4 -> V_154 , & V_245 , L_55 ) ;
if ( ! V_2 -> V_244 ) {
F_17 ( V_246 L_56 ,
V_4 -> V_70 ) ;
V_31 = - V_53 ;
goto V_54;
}
V_2 -> V_244 -> V_111 = V_227 ;
F_93 ( V_227 ) ;
F_94 ( V_2 -> V_244 , V_2 ) ;
V_31 = F_95 ( V_2 -> V_244 ,
V_247 , - 1 ) ;
if ( V_31 < 0 ) {
F_17 ( V_246 L_57 ,
V_4 -> V_70 ) ;
goto V_54;
}
F_17 ( V_246 L_58 ,
V_4 -> V_70 , V_2 -> V_244 -> V_248 ) ;
F_31 ( V_2 ) ;
F_42 ( V_2 , V_117 ) ;
F_42 ( V_2 , V_120 ) ;
F_42 ( V_2 , V_126 ) ;
F_42 ( V_2 , V_123 ) ;
F_42 ( V_2 , V_129 ) ;
F_44 ( V_2 , 0 ) ;
F_43 ( V_2 , 20 ) ;
F_45 ( V_2 ) ;
F_96 ( V_2 , 0 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
V_31 = 0 ;
V_54:
return V_31 ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_32 , V_6 , V_2 -> V_26 ) ;
if ( V_2 -> type != V_228 )
F_15 () ;
if ( V_2 -> V_244 ) {
if ( V_2 -> V_244 -> V_249 != - 1 )
F_98 ( V_2 -> V_244 ) ;
else
V_225 ( V_2 -> V_244 ) ;
V_2 -> V_244 = NULL ;
}
F_99 ( & V_2 -> V_111 ) ;
F_2 ( V_5 , L_5 , V_6 , V_2 -> V_26 ) ;
}
