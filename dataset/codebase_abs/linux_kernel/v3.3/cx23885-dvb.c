static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_8 = 188 * 4 ;
V_6 -> V_9 = 32 ;
* V_4 = V_6 -> V_8 * V_6 -> V_9 ;
* V_3 = 32 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 , enum V_12 V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_3 ( V_2 , V_6 , (struct V_14 * ) V_11 , V_13 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_5 ( V_6 , (struct V_14 * ) V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_7 ( V_2 , (struct V_14 * ) V_11 ) ;
}
static void F_8 ( struct V_5 * V_6 , int V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_17 = & V_6 -> V_20 ;
if ( V_17 -> V_21 <= 1 )
V_19 = F_9 ( V_17 , 1 ) ;
else
V_19 = F_9 ( V_17 , V_17 -> V_21 ) ;
if ( V_19 && V_19 -> V_22 . V_23 && V_19 -> V_22 . V_23 -> V_24 . V_25 )
V_19 -> V_22 . V_23 -> V_24 . V_25 ( V_19 -> V_22 . V_23 , V_15 ) ;
F_10 ( V_19 -> V_22 . V_23 ) ;
}
static int F_10 ( struct V_26 * V_19 )
{
struct V_27 * V_28 = & V_19 -> V_29 ;
struct V_5 * V_6 = V_19 -> V_22 -> V_30 ;
struct V_31 * V_32 = V_6 -> V_32 ;
switch ( V_32 -> V_33 ) {
case V_34 :
switch ( V_28 -> V_35 ) {
case V_36 :
F_11 ( V_32 , V_37 ) ;
break;
case V_38 :
case V_39 :
default:
F_12 ( V_32 , V_37 ) ;
break;
}
break;
case V_40 :
case V_41 :
F_12 ( V_32 , V_42 ) ;
break;
}
return 0 ;
}
int F_13 ( void * V_43 , int V_44 , int V_45 , int V_46 )
{
struct V_31 * V_32 = (struct V_31 * ) V_43 ;
unsigned long V_47 = V_48 + F_14 ( 1 ) ;
T_1 V_49 = 0 ;
V_49 = F_15 ( V_50 ) ;
if ( V_46 )
F_16 ( V_51 , V_52 ) ;
else {
F_17 ( V_51 , V_52 ) ;
V_49 &= ~ V_52 ;
V_49 |= ( V_45 & V_52 ) ;
}
if ( V_44 )
V_49 |= V_53 ;
else
V_49 &= ~ V_53 ;
V_49 &= ~ V_54 ;
if ( V_46 )
V_49 = ( V_49 & ~ V_55 ) | V_56 ;
else
V_49 = ( V_49 & ~ V_56 ) | V_55 ;
F_18 ( V_50 , V_49 ) ;
for (; ; ) {
V_49 = F_15 ( V_50 ) ;
if ( ( V_49 & V_57 ) == 0 )
break;
if ( F_19 ( V_48 , V_47 ) )
break;
F_20 ( 1 ) ;
}
F_16 ( V_50 , V_55 | V_56 | V_54 ) ;
if ( V_46 )
return V_49 & V_52 ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = V_6 -> V_32 ;
struct V_58 * V_59 = NULL , * V_60 = NULL ;
struct V_18 * V_61 , * V_62 = NULL ;
int V_63 = 0 ;
int V_64 ;
V_61 = F_9 ( & V_6 -> V_20 , 1 ) ;
if ( ! V_61 )
return - V_65 ;
V_61 -> V_22 . V_66 = V_32 -> V_66 ;
V_6 -> V_20 . V_21 = 0 ;
V_6 -> V_67 = F_8 ;
switch ( V_32 -> V_33 ) {
case V_68 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_69 ,
& V_70 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_72 , V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_73 , 0 ) ;
}
break;
case V_74 :
case V_34 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_75 ,
& V_76 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 1 ] . V_71 ,
& V_78 ) ;
}
break;
case V_79 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_80 ,
& V_81 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 1 ] . V_71 ,
& V_82 ) ;
}
break;
case V_83 :
V_59 = & V_32 -> V_59 [ 0 ] ;
switch ( V_84 ) {
case 1 :
V_61 -> V_22 . V_23 =
F_22 ( V_69 ,
& V_85 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_86 , V_61 -> V_22 . V_23 ,
& V_32 -> V_59 [ 1 ] . V_71 , 0x42 ,
& V_87 ) ;
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 1 ] . V_71 ,
& V_82 ) ;
}
break;
case 0 :
default:
V_61 -> V_22 . V_23 =
F_22 ( V_69 ,
& V_70 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
F_22 ( V_72 , V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_73 , 0 ) ;
break;
}
break;
case V_88 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_69 ,
& V_89 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_72 , V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_73 , 0 ) ;
}
break;
case V_90 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_91 ,
& V_92 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_93 , V_61 -> V_22 . V_23 ,
& V_59 -> V_71 , 0x61 ,
V_94 ) ;
}
break;
case V_95 :
V_59 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_69 ,
& V_96 ,
& V_32 -> V_59 [ 0 ] . V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
F_22 ( V_97 , V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_98 ) ;
break;
case V_99 :
V_59 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_69 ,
& V_100 ,
& V_32 -> V_59 [ 0 ] . V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
struct V_26 * V_19 ;
struct V_101 V_102 = {
. V_71 = & V_59 -> V_71 ,
. V_103 = 0x61 ,
} ;
static struct V_104 V_105 = {
. V_106 = V_107 ,
. V_108 = 64 ,
. V_109 = V_110 ,
} ;
V_19 = F_22 ( V_111 ,
V_61 -> V_22 . V_23 , & V_102 ) ;
if ( V_19 != NULL && V_19 -> V_24 . V_112 . V_113 != NULL )
V_19 -> V_24 . V_112 . V_113 ( V_19 , & V_105 ) ;
}
break;
case V_114 :
case V_115 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_116 ,
& V_117 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_86 , V_61 -> V_22 . V_23 ,
& V_32 -> V_59 [ 1 ] . V_71 , 0x42 ,
& V_87 ) ;
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 1 ] . V_71 ,
& V_118 ) ;
}
break;
case V_119 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_116 ,
& V_120 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 1 ] . V_71 ,
& V_121 ) ;
}
break;
case V_122 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_123 ,
& V_59 -> V_71 ,
0x12 , & V_124 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
struct V_26 * V_19 ;
struct V_101 V_102 = {
. V_71 = & V_32 -> V_59 [ 1 ] . V_71 ,
. V_103 = 0x64 ,
} ;
static struct V_104 V_105 = {
. V_106 = V_125 ,
. V_108 = 64 ,
. V_109 = V_126 ,
. type = V_127 ,
} ;
V_19 = F_22 ( V_111 ,
V_61 -> V_22 . V_23 , & V_102 ) ;
if ( V_19 != NULL && V_19 -> V_24 . V_112 . V_113 != NULL )
V_19 -> V_24 . V_112 . V_113 ( V_19 , & V_105 ) ;
}
break;
case V_128 :
V_59 = & V_32 -> V_59 [ V_6 -> V_129 - 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_69 ,
& V_130 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 == NULL )
V_61 -> V_22 . V_23 = F_22 ( V_80 ,
& V_131 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
F_22 ( V_97 , V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_132 ) ;
break;
case V_133 : {
V_59 = & V_32 -> V_59 [ V_6 -> V_129 - 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_134 ,
& V_135 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
struct V_26 * V_19 ;
struct V_101 V_102 = {
. V_71 = & V_59 -> V_71 ,
. V_103 = 0x61 ,
} ;
static struct V_104 V_105 = {
. V_106 = V_107 ,
. V_108 = 64 ,
. V_109 = V_136 ,
} ;
V_19 = F_22 ( V_111 , V_61 -> V_22 . V_23 ,
& V_102 ) ;
if ( V_19 != NULL && V_19 -> V_24 . V_112 . V_113 != NULL )
V_19 -> V_24 . V_112 . V_113 ( V_19 , & V_105 ) ;
}
break;
}
case V_137 :
case V_138 :
case V_139 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_134 ,
& V_135 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
struct V_26 * V_19 ;
struct V_101 V_102 = {
. V_71 = & V_32 -> V_59 [ 1 ] . V_71 ,
. V_103 = 0x61 ,
} ;
static struct V_104 V_105 = {
. V_106 = V_107 ,
. V_108 = 64 ,
. V_109 = V_136 ,
} ;
V_19 = F_22 ( V_111 , V_61 -> V_22 . V_23 ,
& V_102 ) ;
if ( V_19 != NULL && V_19 -> V_24 . V_112 . V_113 != NULL )
V_19 -> V_24 . V_112 . V_113 ( V_19 , & V_105 ) ;
}
break;
case V_140 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_134 ,
& V_135 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
struct V_26 * V_19 ;
struct V_141 V_102 = {
. V_142 = 0x61 ,
. V_143 = 0 ,
. V_144 = 134 ,
. V_145 = 1 ,
. V_146 = 4560
} ;
V_19 = F_22 ( V_147 , V_61 -> V_22 . V_23 ,
& V_32 -> V_59 [ 1 ] . V_71 , & V_102 ) ;
if ( ! V_19 ) {
F_23 ( V_148 L_1 ,
V_32 -> V_66 ) ;
goto V_149;
}
}
break;
case V_150 :
V_59 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_151 ,
& V_152 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
V_61 -> V_22 . V_23 -> V_24 . V_153 = V_154 ;
break;
case V_155 :
V_59 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_156 ,
& V_157 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
V_61 -> V_22 . V_23 -> V_24 . V_153 = V_154 ;
break;
case V_158 :
V_59 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_151 ,
& V_159 ,
& V_59 -> V_71 ) ;
break;
case V_160 :
V_59 = & V_32 -> V_59 [ 0 ] ;
switch ( V_6 -> V_129 ) {
case 1 :
V_61 -> V_22 . V_23 = F_22 ( V_161 ,
& V_162 ,
& V_59 -> V_71 , 0 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
if ( F_22 ( V_163 ,
V_61 -> V_22 . V_23 ,
& V_164 ,
& V_59 -> V_71 ) ) {
if ( ! F_22 ( V_165 ,
V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
V_166 | V_167 ,
V_168 , 0x09 ) )
F_23 ( V_148
L_2 ) ;
}
}
break;
case 2 :
V_61 -> V_22 . V_23 = F_22 ( V_161 ,
& V_162 ,
& V_59 -> V_71 , 1 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
if ( F_22 ( V_163 ,
V_61 -> V_22 . V_23 ,
& V_169 ,
& V_59 -> V_71 ) ) {
if ( ! F_22 ( V_165 ,
V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
V_166 | V_167 ,
V_168 , 0x0a ) )
F_23 ( V_148
L_2 ) ;
}
}
break;
}
break;
case V_40 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_60 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_170 ,
& V_171 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_97 ,
V_61 -> V_22 . V_23 ,
& V_60 -> V_71 ,
& V_172 ) ;
}
break;
case V_41 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_60 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_170 ,
& V_173 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_97 ,
V_61 -> V_22 . V_23 ,
& V_60 -> V_71 ,
& V_174 ) ;
}
break;
case V_175 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_80 ,
& V_81 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 0 ] . V_71 ,
& V_82 ) ;
V_77 ( & V_32 -> V_176 . V_177 ,
0x60 , & V_32 -> V_59 [ 1 ] . V_71 ,
& V_82 ) ;
break;
case V_178 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_80 ,
& V_81 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL )
F_22 ( V_77 , V_61 -> V_22 . V_23 ,
0x60 , & V_32 -> V_59 [ 0 ] . V_71 ,
& V_82 ) ;
break;
case V_179 :
switch ( V_6 -> V_129 ) {
case 1 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_180 ,
& V_181 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_182 ,
V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_183 ) ;
}
break;
case 2 :
V_59 = & V_32 -> V_59 [ 1 ] ;
V_61 -> V_22 . V_23 = F_22 ( V_180 ,
& V_184 ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
F_22 ( V_182 ,
V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_185 ) ;
}
break;
}
break;
case V_186 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_63 = 1 ;
V_6 -> V_20 . V_21 = 0 ;
V_61 -> V_22 . V_23 = F_22 ( V_187 ,
& V_188 [ V_6 -> V_129 - 1 ] ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
if ( NULL == F_22 ( V_97 ,
V_61 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_189 [ V_6 -> V_129 - 1 ] ) )
goto V_149;
V_61 -> V_22 . V_23 -> V_24 . V_112 . V_190 ( V_61 -> V_22 . V_23 ) ;
}
V_62 = F_9 ( & V_6 -> V_20 , 2 ) ;
if ( V_62 == NULL )
goto V_149;
V_62 -> V_22 . V_23 = F_22 ( V_191 ,
& V_188 [ V_6 -> V_129 - 1 ] ,
& V_59 -> V_71 ) ;
if ( V_62 -> V_22 . V_23 != NULL ) {
V_62 -> V_22 . V_23 -> V_192 = 1 ;
if ( NULL == F_22 ( V_97 ,
V_62 -> V_22 . V_23 ,
& V_59 -> V_71 ,
& V_189 [ V_6 -> V_129 - 1 ] ) )
goto V_149;
}
break;
case V_193 :
V_59 = & V_32 -> V_59 [ 0 ] ;
V_60 = & V_32 -> V_59 [ 1 ] ;
switch ( V_6 -> V_129 ) {
case 1 :
V_61 -> V_22 . V_23 = F_22 ( V_194 ,
& V_195 [ 0 ] ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
if ( ! F_22 ( V_196 ,
V_61 -> V_22 . V_23 ,
& V_197 [ 0 ] ,
& V_60 -> V_71 ) )
goto V_149;
}
break;
case 2 :
V_61 -> V_22 . V_23 = F_22 ( V_194 ,
& V_195 [ 1 ] ,
& V_59 -> V_71 ) ;
if ( V_61 -> V_22 . V_23 != NULL ) {
if ( ! F_22 ( V_196 ,
V_61 -> V_22 . V_23 ,
& V_197 [ 1 ] ,
& V_60 -> V_71 ) )
goto V_149;
}
break;
}
break;
default:
F_23 ( V_198 L_3
L_4 ,
V_32 -> V_66 ) ;
break;
}
if ( ( NULL == V_61 -> V_22 . V_23 ) || ( V_62 && NULL == V_62 -> V_22 . V_23 ) ) {
F_23 ( V_148 L_5 ,
V_32 -> V_66 ) ;
goto V_149;
}
V_61 -> V_22 . V_23 -> V_199 = V_200 ;
if ( V_62 )
V_62 -> V_22 . V_23 -> V_199 = V_200 ;
#if 0
fe0->dvb.frontend->ops.ts_bus_ctrl = cx23885_dvb_bus_ctrl;
if (fe1)
fe1->dvb.frontend->ops.ts_bus_ctrl = cx23885_dvb_bus_ctrl;
#endif
F_24 ( V_32 , V_201 , V_202 , 0 ) ;
if ( V_61 -> V_22 . V_23 -> V_24 . V_203 . V_204 )
V_61 -> V_22 . V_23 -> V_24 . V_203 . V_204 ( V_61 -> V_22 . V_23 ) ;
V_64 = F_25 ( & V_6 -> V_20 , V_205 , V_6 ,
& V_32 -> V_206 -> V_32 , V_207 , V_63 ,
NULL ) ;
if ( V_64 )
goto V_149;
switch ( V_32 -> V_33 ) {
case V_160 : {
static struct V_208 V_209 ;
F_26 ( & V_32 -> V_59 [ 0 ] . V_71 , & V_209 ) ;
memcpy ( V_6 -> V_20 . V_210 . V_211 ,
V_209 . V_6 [ V_6 -> V_129 - 1 ] . V_212 , 6 ) ;
F_23 ( V_198 L_6 ,
V_6 -> V_129 , V_6 -> V_20 . V_210 . V_211 ) ;
F_27 ( V_6 ) ;
break;
}
case V_186 : {
struct V_213 V_214 = {
. V_32 = V_32 ,
. V_210 = & V_6 -> V_20 . V_210 ,
. V_215 = & V_61 -> V_22 . V_215 ,
. V_216 = F_13 ,
} ;
F_28 ( & V_214 , V_6 -> V_129 ) ;
break;
}
case V_155 : {
T_2 V_217 [ 256 ] ;
if ( V_6 -> V_129 != 1 )
break;
V_32 -> V_59 [ 0 ] . V_218 . V_219 = 0xa0 >> 1 ;
F_29 ( & V_32 -> V_59 [ 0 ] . V_218 , V_217 , sizeof( V_217 ) ) ;
F_23 ( V_198 L_7 , V_217 + 0xa0 ) ;
memcpy ( V_6 -> V_20 . V_210 . V_211 , V_217 + 0xa0 , 6 ) ;
break;
}
}
return V_64 ;
V_149:
V_6 -> V_67 = NULL ;
F_30 ( & V_6 -> V_20 ) ;
return - V_65 ;
}
int F_31 ( struct V_5 * V_6 )
{
struct V_18 * V_61 ;
struct V_31 * V_32 = V_6 -> V_32 ;
int V_220 , V_221 ;
F_23 ( V_198 L_8 , V_222 ,
V_6 -> V_223 ) ;
for ( V_221 = 1 ; V_221 <= V_6 -> V_223 ; V_221 ++ ) {
if ( F_32 (
& V_6 -> V_20 , V_221 ) == NULL ) {
F_23 ( V_148 L_9 , V_222 ) ;
return - V_224 ;
}
V_61 = F_9 ( & V_6 -> V_20 , V_221 ) ;
if ( ! V_61 )
V_220 = - V_65 ;
F_33 ( 1 , L_10 , V_222 ) ;
F_33 ( 1 , L_11 ,
V_32 -> V_33 ,
V_32 -> V_66 ,
V_32 -> V_225 ,
V_32 -> V_226 ) ;
V_220 = - V_227 ;
F_23 ( V_198 L_12 , V_32 -> V_66 ) ;
F_34 ( & V_61 -> V_22 . V_228 , & V_229 ,
& V_32 -> V_206 -> V_32 , & V_6 -> V_230 ,
V_231 , V_232 ,
sizeof( struct V_14 ) , V_6 , NULL ) ;
}
V_220 = F_21 ( V_6 ) ;
if ( V_220 != 0 )
F_23 ( V_148 L_13 ,
V_222 , V_220 ) ;
return V_220 ;
}
int F_35 ( struct V_5 * V_6 )
{
struct V_18 * V_61 ;
V_61 = F_9 ( & V_6 -> V_20 , 1 ) ;
if ( V_61 && V_61 -> V_22 . V_23 )
F_36 ( & V_6 -> V_20 ) ;
switch ( V_6 -> V_32 -> V_33 ) {
case V_160 :
F_37 ( V_6 ) ;
break;
case V_186 :
F_38 ( V_6 -> V_32 , V_6 -> V_129 ) ;
break;
}
V_6 -> V_67 = NULL ;
return 0 ;
}
