static long F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_8 == NULL || V_8 -> V_12 == NULL )
return - V_13 ;
V_10 = V_8 -> V_12 ;
F_4 ( & V_10 -> V_14 ) ;
if ( V_2 == V_15 ) {
V_11 = F_5 ( V_10 ,
(struct V_16 V_17 * ) V_3 ) ;
goto V_18;
}
if ( ! V_10 -> V_19 ) {
F_6 ( L_1 , V_10 -> V_4 ) ;
V_11 = - V_13 ;
goto V_18;
}
switch ( V_2 ) {
case V_20 :
V_11 = F_7 ( V_10 ,
(struct V_21 V_17 * ) V_3 ) ;
break;
case V_22 :
V_11 = F_8 ( V_10 , (struct V_23 V_17 * ) V_3 ,
V_1 ) ;
break;
case V_24 :
V_11 = F_9 ( V_10 ,
(struct V_25 V_17 * ) V_3 ,
V_1 ) ;
break;
case V_26 :
V_11 = F_10 ( V_10 , ( void V_17 * ) V_3 ) ;
break;
case V_27 :
V_11 = F_11 ( V_10 , ( void V_17 * ) V_3 ) ;
break;
case V_28 :
V_11 = F_12 ( V_10 ,
(struct V_29 V_17 * ) V_3 ,
V_1 ) ;
break;
case V_30 :
V_11 = F_13 ( V_10 , V_3 , V_1 ) ;
break;
case V_31 :
V_11 = F_14 ( V_10 , V_3 , V_1 ) ;
break;
case V_32 :
V_11 = F_15 ( V_10 , V_3 , V_1 ) ;
break;
case V_33 :
V_11 = F_16 ( V_10 , (struct V_34 V_17 * ) V_3 , V_1 ) ;
break;
case V_35 :
V_11 = F_17 ( V_10 , (struct V_34 V_17 * ) V_3 ,
V_1 ) ;
break;
case V_36 :
V_11 = F_18 ( V_10 ,
(struct V_37 V_17 * ) V_3 ,
V_1 ) ;
break;
case V_38 :
V_11 = F_19 ( V_10 , (struct V_39 V_17 * ) V_3 ,
V_1 ) ;
break;
case V_40 :
V_11 = F_20 ( V_10 , V_3 , V_1 ) ;
break;
default:
V_11 = - V_41 ;
break;
}
V_18:
F_21 ( & V_10 -> V_14 ) ;
return V_11 ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_16 V_17 * V_3 )
{
struct V_16 V_42 ;
int V_43 ;
unsigned char * V_44 = NULL ;
int V_45 ;
if ( ! F_22 ( V_46 ) )
return - V_47 ;
if ( V_3 == NULL ) {
if ( F_23 ( V_10 ) )
return - V_48 ;
if ( V_10 -> V_19 ) {
struct V_49 * V_50 = V_10 -> V_51 -> V_49 ;
F_24 ( V_10 ) ;
F_25 ( V_50 ) ;
}
return 0 ;
}
if ( F_26 ( & V_42 , V_3 , sizeof( struct V_16 ) ) )
return - V_52 ;
V_42 . V_53 [ V_54 - 1 ] = 0 ;
if ( F_27 ( V_42 . V_55 , 0 ) &&
V_42 . V_55 [ V_56 ] ) {
int V_57 ;
V_45 = V_42 . V_55 [ V_56 ] ;
if ( V_45 < 0 )
return - V_52 ;
V_44 = F_28 ( V_45 ) ;
if ( ! V_44 )
return - V_58 ;
if ( F_26 ( V_44 ,
F_27 ( V_42 . V_55 , 0 ) , V_45 ) ) {
F_29 ( V_44 ) ;
return - V_52 ;
}
V_42 . V_55 [ V_59 ] =
( unsigned long ) V_44 ;
if ( sizeof( void * ) > sizeof( int ) ) {
V_57 = sizeof( int ) * 8 ;
V_42 . V_55 [ V_60 ] =
( ( unsigned long ) V_44 ) >> V_57 ;
} else
V_42 . V_55 [ V_60 ] = 0 ;
}
V_43 = F_30 ( V_10 , & V_42 ) ;
if ( V_43 == 0 ) {
if ( ! F_31 ( V_10 -> V_51 -> V_49 ) ) {
F_24 ( V_10 ) ;
return - V_61 ;
}
}
if ( V_44 )
F_29 ( V_44 ) ;
return V_43 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_21 V_17 * V_3 )
{
struct V_21 V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_67 = 0 ;
if ( F_26 ( & V_62 , V_3 , sizeof( struct V_21 ) ) )
return - V_52 ;
if ( V_62 . V_68 >= V_10 -> V_69 || V_62 . V_68 < 0 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_62 . V_68 ;
V_64 = V_66 -> V_64 ;
if ( ! V_64 ) {
F_6 ( L_2 ) ;
V_62 . V_72 = 0 ;
V_62 . V_73 = 0 ;
goto V_74;
}
if ( V_62 . V_73 ) {
if ( ! F_22 ( V_46 ) )
return - V_47 ;
V_64 -> V_75 = V_62 . V_73 ;
}
if ( V_62 . V_72 ) {
V_67 = F_32 ( V_10 , V_66 , V_64 , V_62 . V_72 ) ;
if ( V_67 < 0 )
return V_67 ;
}
V_62 . V_72 = V_64 -> V_76 ;
V_62 . V_73 = V_64 -> V_75 ;
V_74:
if ( F_33 ( V_3 , & V_62 , sizeof( struct V_21 ) ) )
return - V_52 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_23 V_17 * V_3 ,
struct V_1 * V_1 )
{
struct V_23 V_77 ;
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_65 * V_78 =
F_34 ( V_8 ) ;
struct V_65 * V_79 =
F_35 ( V_8 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_80 = V_81 ;
V_77 . V_82 = V_10 -> V_69 ;
F_36 ( V_77 . V_83 , V_10 -> V_51 -> V_83 , V_54 ) ;
F_36 ( V_77 . V_53 , V_10 -> V_53 , V_54 ) ;
if ( V_78 )
V_77 . V_84 = V_78 - V_10 -> V_71 ;
else
V_77 . V_84 = - 1 ;
if ( V_79 )
V_77 . V_85 = V_79 - V_10 -> V_71 ;
else
V_77 . V_85 = - 1 ;
if ( F_33 ( V_3 , & V_77 , sizeof( struct V_23 ) ) )
return - V_52 ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_25 V_17 * V_3 , void * V_1 )
{
int V_43 , V_86 ;
struct V_25 * V_87 , * V_88 ;
struct V_65 * V_66 ;
V_87 =
F_37 ( V_10 -> V_69 , sizeof( struct V_25 ) ,
V_89 ) ;
if ( ! V_87 )
return - V_58 ;
for ( V_86 = 0 ; V_86 < V_10 -> V_69 ; V_86 ++ ) {
V_66 = V_10 -> V_71 + V_86 ;
V_88 = V_87 + V_86 ;
V_88 -> type = V_66 -> type ;
V_88 -> V_90 = V_66 -> V_90 ;
V_88 -> V_91 = V_66 -> V_92 ;
if ( F_38 ( V_66 ) & V_93 )
V_88 -> V_91 |= V_94 ;
#define F_39 5
V_88 -> V_95 = F_39 ;
V_88 -> V_96 = V_66 -> V_96 ;
V_88 -> V_97 = V_66 -> V_97 ;
if ( V_66 -> V_98 ) {
V_88 -> V_99 =
( V_86 << 24 ) | ( 0 << 16 ) | ( V_66 -> V_98 -> V_100 ) ;
} else {
V_88 -> V_99 = 0 ;
}
V_88 -> V_101 = V_66 -> V_101 ;
if ( V_66 -> V_102 )
V_88 -> V_91 |= V_103 ;
if ( V_66 -> V_102 == V_1 )
V_88 -> V_91 |= V_104 ;
if ( V_66 -> V_105 )
V_88 -> V_91 |= V_106 ;
if ( V_66 -> V_105 == V_1 )
V_88 -> V_91 |= V_107 ;
if ( ! V_66 -> V_97 && V_66 -> V_108 )
V_88 -> V_91 |= V_109 ;
if ( V_66 -> V_110 )
V_88 -> V_91 |= V_111 ;
if ( V_66 -> V_112 )
V_88 -> V_91 |= V_113 ;
if ( V_66 -> V_114 )
V_88 -> V_91 |= V_115 ;
if ( V_66 -> V_116 != & V_117 )
V_88 -> V_118 = V_119 ;
else
V_88 -> V_118 = V_120 ;
V_88 -> V_121 = V_66 -> V_121 ;
}
V_43 = F_33 ( V_3 , V_87 ,
V_10 -> V_69 * sizeof( struct V_25 ) ) ;
F_40 ( V_87 ) ;
return V_43 ? - V_52 : 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_122 V_17 * V_3 )
{
struct V_65 * V_66 ;
struct V_122 V_42 ;
if ( F_26 ( & V_42 , V_3 , sizeof( struct V_122 ) ) )
return - V_52 ;
if ( V_42 . V_123 >= V_10 -> V_69 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_42 . V_123 ;
if ( V_42 . V_108 ) {
if ( V_66 -> V_97 || ! V_66 -> V_108 )
return - V_70 ;
if ( F_33 ( V_42 . V_108 , V_66 -> V_108 ,
V_66 -> V_90 * sizeof( unsigned int ) ) )
return - V_52 ;
}
if ( V_42 . V_110 ) {
if ( ! V_66 -> V_110 )
return - V_70 ;
if ( F_33 ( V_42 . V_110 , V_66 -> V_110 ,
V_66 -> V_90 * sizeof( unsigned int ) ) )
return - V_52 ;
}
if ( V_42 . V_124 ) {
int V_86 ;
if ( ! V_66 -> V_112 )
return - V_70 ;
for ( V_86 = 0 ; V_86 < V_66 -> V_90 ; V_86 ++ ) {
int V_125 ;
V_125 = ( V_10 -> V_4 << 28 ) | ( V_42 . V_123 << 24 ) | ( V_86 << 16 ) |
( V_66 -> V_112 [ V_86 ] -> V_100 ) ;
if ( F_41 ( V_125 , V_42 . V_124 + V_86 ) )
return - V_52 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_29 V_17 * V_3 , void * V_1 )
{
struct V_29 V_126 ;
struct V_65 * V_66 ;
struct V_63 * V_64 ;
if ( F_26 ( & V_126 , V_3 , sizeof( struct V_29 ) ) )
return - V_52 ;
if ( V_126 . V_68 >= V_10 -> V_69 || V_126 . V_68 < 0 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_126 . V_68 ;
if ( V_66 -> V_105 && V_66 -> V_105 != V_1 )
return - V_127 ;
V_64 = V_66 -> V_64 ;
if ( ! V_64 ) {
F_6 ( L_2 ) ;
V_126 . V_128 = 0 ;
V_126 . V_129 = 0 ;
V_126 . V_130 = 0 ;
V_126 . V_131 = 0 ;
V_126 . V_132 = 0 ;
V_126 . V_133 = 0 ;
goto V_74;
}
if ( ! V_66 -> V_102 ) {
V_126 . V_132 = 0 ;
V_126 . V_133 = 0 ;
goto V_134;
}
if ( V_66 -> V_102 != V_1 )
return - V_127 ;
if ( V_126 . V_132 && ( V_66 -> V_92 & V_135 ) ) {
V_126 . V_132 = F_42 ( V_64 , V_126 . V_132 ) ;
F_43 ( V_64 , V_126 . V_132 ) ;
if ( ! ( F_38 ( V_66 ) & ( V_136 |
V_93 ) )
&& V_64 -> V_130 == V_64 -> V_131 ) {
F_44 ( V_10 , V_66 ) ;
}
}
if ( V_126 . V_133 && ( V_66 -> V_92 & V_137 ) ) {
V_126 . V_133 =
F_45 ( V_64 , V_126 . V_133 ) ;
F_46 ( V_64 , V_126 . V_133 ) ;
}
V_134:
V_126 . V_130 = V_64 -> V_130 ;
V_126 . V_128 = V_64 -> V_128 ;
V_126 . V_131 = V_64 -> V_131 ;
V_126 . V_129 = V_64 -> V_129 ;
V_74:
if ( F_33 ( V_3 , & V_126 , sizeof( struct V_29 ) ) )
return - V_52 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 ,
struct V_37 V_17 * V_3 , void * V_1 )
{
struct V_37 V_138 ;
struct V_39 * V_139 = NULL ;
unsigned int * V_140 = NULL ;
int V_86 = 0 ;
int V_43 = 0 ;
if ( F_26 ( & V_138 , V_3 , sizeof( struct V_37 ) ) )
return - V_52 ;
V_140 = F_47 ( sizeof( unsigned int ) * V_141 , V_89 ) ;
if ( ! V_140 ) {
F_6 ( L_3 ) ;
V_43 = - V_58 ;
goto error;
}
V_139 =
F_47 ( sizeof( struct V_39 ) * V_138 . V_142 , V_89 ) ;
if ( ! V_139 ) {
F_6 ( L_3 ) ;
V_43 = - V_58 ;
goto error;
}
if ( F_26 ( V_139 , V_138 . V_139 ,
sizeof( struct V_39 ) * V_138 . V_142 ) ) {
F_6 ( L_4 ) ;
V_43 = - V_52 ;
goto error;
}
for ( V_86 = 0 ; V_86 < V_138 . V_142 ; V_86 ++ ) {
if ( V_139 [ V_86 ] . V_143 > V_141 ) {
F_6 ( L_5 ) ;
V_43 = - V_70 ;
goto error;
}
if ( V_139 [ V_86 ] . V_144 & V_145 ) {
if ( F_26 ( V_140 , V_139 [ V_86 ] . V_140 ,
V_139 [ V_86 ] . V_143 * sizeof( unsigned int ) ) ) {
F_6 ( L_4 ) ;
V_43 = - V_52 ;
goto error;
}
}
V_43 = F_48 ( V_10 , V_139 + V_86 , V_140 , V_1 ) ;
if ( V_43 < 0 )
goto error;
if ( V_139 [ V_86 ] . V_144 & V_146 ) {
if ( F_33 ( V_139 [ V_86 ] . V_140 , V_140 ,
V_139 [ V_86 ] . V_143 * sizeof( unsigned int ) ) ) {
F_6 ( L_6 ) ;
V_43 = - V_52 ;
goto error;
}
}
if ( F_49 () )
F_50 () ;
}
error:
F_40 ( V_139 ) ;
F_40 ( V_140 ) ;
if ( V_43 < 0 )
return V_43 ;
return V_86 ;
}
static int F_51 ( struct V_39 * V_144 ,
unsigned int * V_140 )
{
if ( V_144 -> V_143 < 1 )
return - V_70 ;
switch ( V_140 [ 0 ] ) {
case V_147 :
case V_148 :
case V_149 :
case V_150 :
if ( V_144 -> V_143 == 1 )
return 0 ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
if ( V_144 -> V_143 == 2 )
return 0 ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
if ( V_144 -> V_143 == 3 )
return 0 ;
break;
case V_174 :
case V_175 :
if ( V_144 -> V_143 == 5 )
return 0 ;
break;
default:
F_52 ( V_176
L_7
L_8
L_9
L_10 , V_140 [ 0 ] , V_177 ,
__FILE__ , V_144 -> V_143 ) ;
return 0 ;
break;
}
return - V_70 ;
}
static int F_48 ( struct V_9 * V_10 , struct V_39 * V_144 ,
unsigned int * V_140 , void * V_1 )
{
struct V_65 * V_66 ;
int V_43 = 0 ;
int V_86 ;
if ( V_144 -> V_144 & V_178 ) {
switch ( V_144 -> V_144 ) {
case V_179 :
{
struct V_180 V_181 ;
if ( V_144 -> V_143 != 2 ) {
V_43 = - V_70 ;
break;
}
F_53 ( & V_181 ) ;
V_140 [ 0 ] = V_181 . V_182 ;
V_140 [ 1 ] = V_181 . V_183 ;
V_43 = 2 ;
break;
}
case V_184 :
if ( V_144 -> V_143 != 1 || V_140 [ 0 ] >= 100000 ) {
V_43 = - V_70 ;
break;
}
F_54 ( V_140 [ 0 ] / 1000 ) ;
V_43 = 1 ;
break;
case V_185 :
if ( V_144 -> V_143 != 1 ) {
V_43 = - V_70 ;
break;
}
if ( V_144 -> V_123 >= V_10 -> V_69 ) {
F_6 ( L_11 ,
V_144 -> V_123 ) ;
V_43 = - V_70 ;
break;
}
V_66 = V_10 -> V_71 + V_144 -> V_123 ;
if ( ! V_66 -> V_64 ) {
F_6 ( L_12 ) ;
V_43 = - V_70 ;
break;
}
if ( ! V_66 -> V_64 -> V_186 ) {
F_6 ( L_13 ) ;
V_43 = - V_187 ;
break;
}
V_43 = V_66 -> V_64 -> V_186 ( V_10 , V_66 , V_144 -> V_140 [ 0 ] ) ;
if ( V_43 >= 0 )
V_43 = 1 ;
break;
default:
F_6 ( L_14 ) ;
V_43 = - V_70 ;
break;
}
} else {
unsigned int V_97 ;
if ( V_144 -> V_123 >= V_10 -> V_69 ) {
F_6 ( L_15 , V_144 -> V_123 ) ;
V_43 = - V_70 ;
goto V_188;
}
V_66 = V_10 -> V_71 + V_144 -> V_123 ;
if ( V_66 -> type == V_189 ) {
F_6 ( L_11 , V_144 -> V_123 ) ;
V_43 = - V_190 ;
goto V_188;
}
if ( V_66 -> V_105 && V_66 -> V_105 != V_1 ) {
F_6 ( L_16 ) ;
V_43 = - V_127 ;
goto V_188;
}
V_43 = F_55 ( V_66 , 1 , & V_144 -> V_191 ) ;
if ( V_43 < 0 ) {
V_43 = - V_70 ;
F_6 ( L_17 ) ;
goto V_188;
}
if ( V_66 -> V_102 ) {
V_43 = - V_48 ;
goto V_188;
}
V_66 -> V_102 = & F_48 ;
switch ( V_144 -> V_144 ) {
case V_192 :
V_43 = V_66 -> V_193 ( V_10 , V_66 , V_144 , V_140 ) ;
break;
case V_194 :
V_97 = V_66 -> V_108
? V_66 -> V_108 [ F_56 ( V_144 -> V_191 ) ]
: V_66 -> V_97 ;
for ( V_86 = 0 ; V_86 < V_144 -> V_143 ; ++ V_86 ) {
if ( V_140 [ V_86 ] > V_97 ) {
V_43 = - V_70 ;
F_6 ( L_18 ) ;
break;
}
}
if ( V_43 == 0 )
V_43 = V_66 -> V_195 ( V_10 , V_66 , V_144 , V_140 ) ;
break;
case V_196 :
if ( V_144 -> V_143 != 2 ) {
V_43 = - V_70 ;
} else {
unsigned int V_197 ;
unsigned int V_198 ;
V_198 = V_140 [ 0 ] ;
if ( V_66 -> V_90 <= 32 ) {
V_197 = F_56 ( V_144 -> V_191 ) ;
if ( V_197 > 0 ) {
V_144 -> V_191 = 0 ;
V_140 [ 0 ] <<= V_197 ;
V_140 [ 1 ] <<= V_197 ;
}
} else
V_197 = 0 ;
V_43 = V_66 -> V_116 ( V_10 , V_66 , V_144 , V_140 ) ;
V_140 [ 0 ] = V_198 ;
if ( V_197 > 0 )
V_140 [ 1 ] >>= V_197 ;
}
break;
case V_199 :
V_43 = F_51 ( V_144 , V_140 ) ;
if ( V_43 )
break;
V_43 = V_66 -> V_200 ( V_10 , V_66 , V_144 , V_140 ) ;
break;
default:
V_43 = - V_70 ;
break;
}
V_66 -> V_102 = NULL ;
}
V_188:
return V_43 ;
}
static int F_19 ( struct V_9 * V_10 ,
struct V_39 V_17 * V_3 , void * V_1 )
{
struct V_39 V_144 ;
unsigned int * V_140 = NULL ;
int V_43 = 0 ;
V_140 = F_47 ( sizeof( unsigned int ) * V_141 , V_89 ) ;
if ( ! V_140 ) {
V_43 = - V_58 ;
goto error;
}
if ( F_26 ( & V_144 , V_3 , sizeof( struct V_39 ) ) ) {
V_43 = - V_52 ;
goto error;
}
if ( V_144 . V_143 > V_141 )
V_144 . V_143 = V_141 ;
if ( V_144 . V_144 & V_145 ) {
if ( F_26 ( V_140 ,
V_144 . V_140 ,
V_144 . V_143 * sizeof( unsigned int ) ) ) {
V_43 = - V_52 ;
goto error;
}
}
V_43 = F_48 ( V_10 , & V_144 , V_140 , V_1 ) ;
if ( V_43 < 0 )
goto error;
if ( V_144 . V_144 & V_146 ) {
if ( F_33 ( V_144 . V_140 ,
V_140 ,
V_144 . V_143 * sizeof( unsigned int ) ) ) {
V_43 = - V_52 ;
goto error;
}
}
V_43 = V_144 . V_143 ;
error:
F_40 ( V_140 ) ;
return V_43 ;
}
static void F_57 ( struct V_65 * V_66 ,
unsigned V_201 , unsigned V_202 )
{
unsigned long V_101 ;
F_58 ( & V_66 -> V_203 , V_101 ) ;
V_66 -> V_204 &= ~ V_201 ;
V_66 -> V_204 |= ( V_202 & V_201 ) ;
F_59 ( & V_66 -> V_203 , V_101 ) ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_34 V_17 * V_2 , void * V_1 )
{
struct V_34 V_205 ;
struct V_65 * V_66 ;
struct V_63 * V_64 ;
int V_43 = 0 ;
unsigned int V_17 * V_206 = NULL ;
if ( F_26 ( & V_205 , V_2 , sizeof( struct V_34 ) ) ) {
F_6 ( L_19 ) ;
return - V_52 ;
}
V_206 = V_205 . V_207 ;
if ( V_205 . V_123 >= V_10 -> V_69 ) {
F_6 ( L_20 , V_205 . V_123 ) ;
return - V_13 ;
}
V_66 = V_10 -> V_71 + V_205 . V_123 ;
V_64 = V_66 -> V_64 ;
if ( V_66 -> type == V_189 ) {
F_6 ( L_21 , V_205 . V_123 ) ;
return - V_190 ;
}
if ( ! V_66 -> V_114 || ! V_66 -> V_208 || ! V_66 -> V_64 ) {
F_6 ( L_22 ,
V_205 . V_123 ) ;
return - V_190 ;
}
if ( V_66 -> V_105 && V_66 -> V_105 != V_1 ) {
F_6 ( L_23 ) ;
return - V_127 ;
}
if ( V_66 -> V_102 ) {
F_6 ( L_24 ) ;
return - V_48 ;
}
V_66 -> V_102 = V_1 ;
if ( V_205 . V_209 > V_66 -> V_96 ) {
F_6 ( L_25 ,
V_205 . V_209 , V_66 -> V_96 ) ;
V_43 = - V_70 ;
goto V_210;
}
if ( V_205 . V_209 < 1 ) {
F_6 ( L_26 ,
V_205 . V_209 ) ;
V_43 = - V_70 ;
goto V_210;
}
F_40 ( V_64 -> V_2 . V_207 ) ;
V_64 -> V_2 = V_205 ;
V_64 -> V_2 . V_140 = NULL ;
V_64 -> V_2 . V_207 =
F_47 ( V_64 -> V_2 . V_209 * sizeof( int ) , V_89 ) ;
if ( ! V_64 -> V_2 . V_207 ) {
F_6 ( L_27 ) ;
V_43 = - V_58 ;
goto V_210;
}
if ( F_26 ( V_64 -> V_2 . V_207 , V_205 . V_207 ,
V_64 -> V_2 . V_209 * sizeof( int ) ) ) {
F_6 ( L_28 ) ;
V_43 = - V_52 ;
goto V_210;
}
V_43 = F_55 ( V_66 ,
V_64 -> V_2 . V_209 ,
V_64 -> V_2 . V_207 ) ;
if ( V_43 < 0 ) {
F_6 ( L_29 ) ;
goto V_210;
}
V_43 = V_66 -> V_208 ( V_10 , V_66 , & V_64 -> V_2 ) ;
if ( V_64 -> V_2 . V_101 & V_211 || V_43 ) {
F_6 ( L_30 , V_43 ) ;
V_205 = V_64 -> V_2 ;
V_205 . V_207 = V_206 ;
V_205 . V_140 = NULL ;
if ( F_33 ( V_2 , & V_205 , sizeof( struct V_34 ) ) ) {
F_6 ( L_31 ) ;
V_43 = - V_52 ;
goto V_210;
}
V_43 = - V_187 ;
goto V_210;
}
if ( ! V_64 -> V_76 ) {
V_43 = - V_58 ;
F_6 ( L_32 ) ;
goto V_210;
}
F_60 ( V_64 ) ;
V_64 -> V_212 =
V_213 | V_214 | V_215 |
V_216 ;
if ( V_64 -> V_2 . V_101 & V_217 )
V_64 -> V_212 |= V_218 ;
F_57 ( V_66 , ~ 0 , V_219 | V_93 ) ;
V_43 = V_66 -> V_114 ( V_10 , V_66 ) ;
if ( V_43 == 0 )
return 0 ;
V_210:
F_44 ( V_10 , V_66 ) ;
return V_43 ;
}
static int F_17 ( struct V_9 * V_10 ,
struct V_34 V_17 * V_3 , void * V_1 )
{
struct V_34 V_205 ;
struct V_65 * V_66 ;
int V_43 = 0 ;
unsigned int * V_207 = NULL ;
unsigned int V_17 * V_206 = NULL ;
if ( F_26 ( & V_205 , V_3 , sizeof( struct V_34 ) ) ) {
F_6 ( L_19 ) ;
return - V_52 ;
}
V_206 = V_205 . V_207 ;
if ( V_205 . V_123 >= V_10 -> V_69 ) {
F_6 ( L_20 , V_205 . V_123 ) ;
return - V_13 ;
}
V_66 = V_10 -> V_71 + V_205 . V_123 ;
if ( V_66 -> type == V_189 ) {
F_6 ( L_21 , V_205 . V_123 ) ;
return - V_190 ;
}
if ( ! V_66 -> V_114 || ! V_66 -> V_208 ) {
F_6 ( L_22 ,
V_205 . V_123 ) ;
return - V_190 ;
}
if ( V_205 . V_209 > V_66 -> V_96 ) {
F_6 ( L_33 ,
V_205 . V_209 , V_66 -> V_96 ) ;
V_43 = - V_70 ;
goto V_210;
}
if ( V_205 . V_207 ) {
V_207 =
F_47 ( V_205 . V_209 * sizeof( int ) , V_89 ) ;
if ( ! V_207 ) {
F_6 ( L_27 ) ;
V_43 = - V_58 ;
goto V_210;
}
if ( F_26 ( V_207 , V_205 . V_207 ,
V_205 . V_209 * sizeof( int ) ) ) {
F_6 ( L_28 ) ;
V_43 = - V_52 ;
goto V_210;
}
V_43 = F_55 ( V_66 , V_205 . V_209 , V_207 ) ;
if ( V_43 < 0 ) {
F_6 ( L_29 ) ;
goto V_210;
}
V_205 . V_207 = V_207 ;
}
V_43 = V_66 -> V_208 ( V_10 , V_66 , & V_205 ) ;
V_205 . V_207 = V_206 ;
if ( F_33 ( V_3 , & V_205 , sizeof( struct V_34 ) ) ) {
F_6 ( L_19 ) ;
V_43 = - V_52 ;
goto V_210;
}
V_210:
F_40 ( V_207 ) ;
return V_43 ;
}
static int F_13 ( struct V_9 * V_10 , unsigned int V_3 ,
void * V_1 )
{
int V_43 = 0 ;
unsigned long V_101 ;
struct V_65 * V_66 ;
if ( V_3 >= V_10 -> V_69 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_3 ;
F_58 ( & V_66 -> V_203 , V_101 ) ;
if ( V_66 -> V_102 || V_66 -> V_105 )
V_43 = - V_48 ;
else
V_66 -> V_105 = V_1 ;
F_59 ( & V_66 -> V_203 , V_101 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_43 ;
}
static int F_14 ( struct V_9 * V_10 , unsigned int V_3 ,
void * V_1 )
{
struct V_65 * V_66 ;
if ( V_3 >= V_10 -> V_69 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_3 ;
if ( V_66 -> V_102 )
return - V_48 ;
if ( V_66 -> V_105 && V_66 -> V_105 != V_1 )
return - V_127 ;
if ( V_66 -> V_105 == V_1 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_66 -> V_105 = NULL ;
}
return 0 ;
}
static int F_15 ( struct V_9 * V_10 , unsigned int V_3 ,
void * V_1 )
{
struct V_65 * V_66 ;
if ( V_3 >= V_10 -> V_69 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_3 ;
if ( V_66 -> V_64 == NULL )
return - V_70 ;
if ( V_66 -> V_105 && V_66 -> V_105 != V_1 )
return - V_127 ;
if ( ! V_66 -> V_102 )
return 0 ;
if ( V_66 -> V_102 != V_1 )
return - V_48 ;
return F_61 ( V_10 , V_66 ) ;
}
static int F_20 ( struct V_9 * V_10 , unsigned int V_3 ,
void * V_1 )
{
struct V_65 * V_66 ;
if ( V_3 >= V_10 -> V_69 )
return - V_70 ;
V_66 = V_10 -> V_71 + V_3 ;
if ( V_66 -> V_105 && V_66 -> V_105 != V_1 )
return - V_127 ;
if ( ! V_66 -> V_102 )
return 0 ;
if ( V_66 -> V_102 != V_1 )
return - V_48 ;
if ( V_66 -> V_220 )
return V_66 -> V_220 ( V_10 , V_66 ) ;
return - V_70 ;
}
static int F_61 ( struct V_9 * V_10 , struct V_65 * V_66 )
{
int V_43 = 0 ;
if ( ( F_38 ( V_66 ) & V_93 ) && V_66 -> V_221 )
V_43 = V_66 -> V_221 ( V_10 , V_66 ) ;
F_44 ( V_10 , V_66 ) ;
return V_43 ;
}
static void F_62 ( struct V_222 * V_223 )
{
struct V_63 * V_64 ;
struct V_9 * V_10 ;
V_64 = V_223 -> V_224 ;
V_10 = V_64 -> V_68 -> V_12 ;
F_4 ( & V_10 -> V_14 ) ;
V_64 -> V_225 -- ;
F_21 ( & V_10 -> V_14 ) ;
}
static int F_63 ( struct V_1 * V_1 , struct V_222 * V_226 )
{
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_12 ;
struct V_63 * V_64 = NULL ;
unsigned long V_227 = V_226 -> V_228 ;
unsigned long V_72 ;
int V_229 ;
int V_86 ;
int V_67 ;
struct V_65 * V_66 ;
F_4 ( & V_10 -> V_14 ) ;
if ( ! V_10 -> V_19 ) {
F_6 ( L_34 , V_10 -> V_4 ) ;
V_67 = - V_13 ;
goto V_18;
}
if ( V_226 -> V_230 & V_231 )
V_66 = F_35 ( V_8 ) ;
else
V_66 = F_34 ( V_8 ) ;
if ( V_66 == NULL ) {
V_67 = - V_70 ;
goto V_18;
}
V_64 = V_66 -> V_64 ;
if ( V_64 == NULL ) {
V_67 = - V_70 ;
goto V_18;
}
if ( V_226 -> V_232 != 0 ) {
F_6 ( L_35 ) ;
V_67 = - V_70 ;
goto V_18;
}
V_72 = V_226 -> V_233 - V_226 -> V_228 ;
if ( V_72 > V_64 -> V_76 ) {
V_67 = - V_52 ;
goto V_18;
}
if ( V_72 & ( ~ V_234 ) ) {
V_67 = - V_52 ;
goto V_18;
}
V_229 = V_72 >> V_235 ;
for ( V_86 = 0 ; V_86 < V_229 ; ++ V_86 ) {
if ( F_64 ( V_226 , V_227 ,
F_65 ( F_66
( V_64 -> V_236
[ V_86 ] . V_237 ) ) , V_238 ,
V_239 ) ) {
V_67 = - V_187 ;
goto V_18;
}
V_227 += V_238 ;
}
V_226 -> V_240 = & V_241 ;
V_226 -> V_224 = V_64 ;
V_64 -> V_225 ++ ;
V_67 = 0 ;
V_18:
F_21 ( & V_10 -> V_14 ) ;
return V_67 ;
}
static unsigned int F_67 ( struct V_1 * V_1 , T_1 * V_242 )
{
unsigned int V_201 = 0 ;
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_12 ;
struct V_65 * V_78 ;
struct V_65 * V_79 ;
F_4 ( & V_10 -> V_14 ) ;
if ( ! V_10 -> V_19 ) {
F_6 ( L_34 , V_10 -> V_4 ) ;
F_21 ( & V_10 -> V_14 ) ;
return 0 ;
}
V_201 = 0 ;
V_78 = F_34 ( V_8 ) ;
if ( V_78 ) {
F_68 ( V_1 , & V_78 -> V_64 -> V_243 , V_242 ) ;
if ( ! V_78 -> V_102
|| F_69 ( V_78 -> V_64 ) > 0
|| ! ( F_38 ( V_78 ) &
V_93 ) ) {
V_201 |= V_244 | V_245 ;
}
}
V_79 = F_35 ( V_8 ) ;
if ( V_79 ) {
F_68 ( V_1 , & V_79 -> V_64 -> V_243 , V_242 ) ;
F_45 ( V_79 -> V_64 ,
V_79 -> V_64 -> V_76 ) ;
if ( ! V_79 -> V_102
|| ! ( F_38 ( V_79 ) &
V_93 )
|| F_70 ( V_79 -> V_64 ) >=
F_71 ( V_79 -> V_64 -> V_68 ) ) {
V_201 |= V_246 | V_247 ;
}
}
F_21 ( & V_10 -> V_14 ) ;
return V_201 ;
}
static T_2 F_72 ( struct V_1 * V_1 , const char V_17 * V_248 ,
T_3 V_249 , T_4 * V_250 )
{
struct V_65 * V_66 ;
struct V_63 * V_64 ;
int V_143 , V_251 , V_252 = 0 , V_67 = 0 ;
F_73 ( V_242 , V_253 ) ;
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_12 ;
if ( ! V_10 -> V_19 ) {
F_6 ( L_34 , V_10 -> V_4 ) ;
V_67 = - V_13 ;
goto V_18;
}
V_66 = F_35 ( V_8 ) ;
if ( V_66 == NULL ) {
V_67 = - V_190 ;
goto V_18;
}
V_64 = V_66 -> V_64 ;
if ( ! V_249 ) {
V_67 = 0 ;
goto V_18;
}
if ( ! V_66 -> V_102 ) {
V_67 = 0 ;
goto V_18;
}
if ( V_66 -> V_102 != V_1 ) {
V_67 = - V_127 ;
goto V_18;
}
F_74 ( & V_64 -> V_243 , & V_242 ) ;
while ( V_249 > 0 && ! V_67 ) {
F_75 ( V_254 ) ;
if ( ! ( F_38 ( V_66 ) & V_93 ) ) {
if ( V_252 == 0 ) {
if ( F_38 ( V_66 ) &
V_136 ) {
V_67 = - V_255 ;
} else {
V_67 = 0 ;
}
F_44 ( V_10 , V_66 ) ;
}
break;
}
V_143 = V_249 ;
V_251 = V_143 ;
if ( V_64 -> V_128 + V_251 > V_64 -> V_76 )
V_251 = V_64 -> V_76 - V_64 -> V_128 ;
F_45 ( V_64 , V_64 -> V_76 ) ;
if ( V_251 > F_70 ( V_64 ) )
V_251 = F_70 ( V_64 ) ;
if ( V_251 < V_143 )
V_143 = V_251 ;
if ( V_143 == 0 ) {
if ( V_1 -> V_256 & V_257 ) {
V_67 = - V_187 ;
break;
}
if ( F_76 ( V_253 ) ) {
V_67 = - V_258 ;
break;
}
F_50 () ;
if ( ! V_66 -> V_102 )
break;
if ( V_66 -> V_102 != V_1 ) {
V_67 = - V_127 ;
break;
}
continue;
}
V_251 = F_26 ( V_64 -> V_259 + V_64 -> V_128 ,
V_248 , V_143 ) ;
if ( V_251 ) {
V_143 -= V_251 ;
V_67 = - V_52 ;
}
F_46 ( V_64 , V_143 ) ;
V_252 += V_143 ;
V_249 -= V_143 ;
V_248 += V_143 ;
break;
}
F_75 ( V_260 ) ;
F_77 ( & V_64 -> V_243 , & V_242 ) ;
V_18:
return V_252 ? V_252 : V_67 ;
}
static T_2 F_78 ( struct V_1 * V_1 , char V_17 * V_248 , T_3 V_249 ,
T_4 * V_250 )
{
struct V_65 * V_66 ;
struct V_63 * V_64 ;
int V_143 , V_251 , V_252 = 0 , V_67 = 0 ;
F_73 ( V_242 , V_253 ) ;
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_12 ;
if ( ! V_10 -> V_19 ) {
F_6 ( L_34 , V_10 -> V_4 ) ;
V_67 = - V_13 ;
goto V_18;
}
V_66 = F_34 ( V_8 ) ;
if ( V_66 == NULL ) {
V_67 = - V_190 ;
goto V_18;
}
V_64 = V_66 -> V_64 ;
if ( ! V_249 ) {
V_67 = 0 ;
goto V_18;
}
if ( ! V_66 -> V_102 ) {
V_67 = 0 ;
goto V_18;
}
if ( V_66 -> V_102 != V_1 ) {
V_67 = - V_127 ;
goto V_18;
}
F_74 ( & V_64 -> V_243 , & V_242 ) ;
while ( V_249 > 0 && ! V_67 ) {
F_75 ( V_254 ) ;
V_143 = V_249 ;
V_251 = F_69 ( V_64 ) ;
if ( V_64 -> V_129 + V_251 > V_64 -> V_76 )
V_251 = V_64 -> V_76 - V_64 -> V_129 ;
if ( V_251 < V_143 )
V_143 = V_251 ;
if ( V_143 == 0 ) {
if ( ! ( F_38 ( V_66 ) & V_93 ) ) {
F_44 ( V_10 , V_66 ) ;
if ( F_38 ( V_66 ) &
V_136 ) {
V_67 = - V_255 ;
} else {
V_67 = 0 ;
}
break;
}
if ( V_1 -> V_256 & V_257 ) {
V_67 = - V_187 ;
break;
}
if ( F_76 ( V_253 ) ) {
V_67 = - V_258 ;
break;
}
F_50 () ;
if ( ! V_66 -> V_102 ) {
V_67 = 0 ;
break;
}
if ( V_66 -> V_102 != V_1 ) {
V_67 = - V_127 ;
break;
}
continue;
}
V_251 = F_33 ( V_248 , V_64 -> V_259 +
V_64 -> V_129 , V_143 ) ;
if ( V_251 ) {
V_143 -= V_251 ;
V_67 = - V_52 ;
}
F_42 ( V_64 , V_143 ) ;
F_43 ( V_64 , V_143 ) ;
V_252 += V_143 ;
V_249 -= V_143 ;
V_248 += V_143 ;
break;
}
if ( ! ( F_38 ( V_66 ) & ( V_136 | V_93 ) ) &&
V_64 -> V_131 - V_64 -> V_130 == 0 ) {
F_44 ( V_10 , V_66 ) ;
}
F_75 ( V_260 ) ;
F_77 ( & V_64 -> V_243 , & V_242 ) ;
V_18:
return V_252 ? V_252 : V_67 ;
}
void F_44 ( struct V_9 * V_10 , struct V_65 * V_66 )
{
struct V_63 * V_64 = V_66 -> V_64 ;
F_57 ( V_66 , V_93 , 0 ) ;
if ( V_64 ) {
F_60 ( V_64 ) ;
V_64 -> V_186 = NULL ;
} else {
F_52 ( V_261
L_36 ) ;
}
V_66 -> V_102 = NULL ;
}
static int F_79 ( struct V_262 * V_262 , struct V_1 * V_1 )
{
const unsigned V_4 = F_2 ( V_262 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 =
V_8 ? V_8 -> V_12 : NULL ;
if ( V_10 == NULL ) {
F_6 ( L_37 ) ;
return - V_13 ;
}
F_4 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_19 )
goto V_263;
if ( ! F_22 ( V_264 ) && V_10 -> V_265 ) {
F_6 ( L_38 ) ;
F_21 ( & V_10 -> V_14 ) ;
return - V_13 ;
}
if ( F_22 ( V_264 ) && V_10 -> V_265 )
goto V_263;
V_10 -> V_265 = 1 ;
#ifdef F_80
F_21 ( & V_10 -> V_14 ) ;
F_81 ( L_39 , V_266 , V_10 -> V_4 ) ;
F_4 ( & V_10 -> V_14 ) ;
#endif
V_10 -> V_265 = 0 ;
if ( ! V_10 -> V_19 && ! F_22 ( V_264 ) ) {
F_6 ( L_40 ) ;
F_21 ( & V_10 -> V_14 ) ;
return - V_13 ;
}
V_263:
F_82 ( V_267 ) ;
if ( V_10 -> V_19 ) {
if ( ! F_31 ( V_10 -> V_51 -> V_49 ) ) {
F_25 ( V_267 ) ;
F_21 ( & V_10 -> V_14 ) ;
return - V_61 ;
}
}
if ( V_10 -> V_19 && V_10 -> V_268 == 0 && V_10 -> V_269 ) {
int V_11 = V_10 -> V_269 ( V_10 ) ;
if ( V_11 < 0 ) {
F_25 ( V_10 -> V_51 -> V_49 ) ;
F_25 ( V_267 ) ;
F_21 ( & V_10 -> V_14 ) ;
return V_11 ;
}
}
V_10 -> V_268 ++ ;
F_21 ( & V_10 -> V_14 ) ;
return 0 ;
}
static int F_83 ( struct V_262 * V_262 , struct V_1 * V_1 )
{
const unsigned V_4 = F_2 ( V_262 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_12 ;
struct V_65 * V_66 = NULL ;
int V_86 ;
F_4 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_71 ) {
for ( V_86 = 0 ; V_86 < V_10 -> V_69 ; V_86 ++ ) {
V_66 = V_10 -> V_71 + V_86 ;
if ( V_66 -> V_102 == V_1 )
F_61 ( V_10 , V_66 ) ;
if ( V_66 -> V_105 == V_1 )
V_66 -> V_105 = NULL ;
}
}
if ( V_10 -> V_19 && V_10 -> V_268 == 1 && V_10 -> V_270 )
V_10 -> V_270 ( V_10 ) ;
F_25 ( V_267 ) ;
if ( V_10 -> V_19 )
F_25 ( V_10 -> V_51 -> V_49 ) ;
V_10 -> V_268 -- ;
F_21 ( & V_10 -> V_14 ) ;
if ( V_1 -> V_256 & V_271 )
F_84 ( - 1 , V_1 , 0 ) ;
return 0 ;
}
static int F_84 ( int V_272 , struct V_1 * V_1 , int V_273 )
{
const unsigned V_4 = F_2 ( V_1 -> V_5 -> V_6 ) ;
struct V_7 * V_8 =
F_3 ( V_4 ) ;
struct V_9 * V_10 = V_8 -> V_12 ;
return F_85 ( V_272 , V_1 , V_273 , & V_10 -> V_274 ) ;
}
static void F_86 ( void )
{
unsigned V_86 ;
for ( V_86 = 0 ; V_86 < V_275 ; V_86 ++ )
F_87 ( V_86 ) ;
}
static int T_5 F_88 ( void )
{
int V_86 ;
int V_67 ;
F_52 ( V_276 L_41 V_277
L_42 ) ;
if ( V_275 < 0 ||
V_275 > V_278 ) {
F_52 ( V_261 L_43
L_44
L_45 , V_278 ) ;
return - V_70 ;
}
if ( V_279 == 0 && V_275 == 0 )
V_275 = 16 ;
memset ( V_280 , 0 ,
sizeof( struct V_7 * ) * V_281 ) ;
V_67 = F_89 ( F_90 ( V_266 , 0 ) ,
V_281 , L_46 ) ;
if ( V_67 )
return - V_190 ;
F_91 ( & V_282 , & V_283 ) ;
V_282 . V_284 = V_267 ;
F_92 ( & V_282 . V_285 , L_46 ) ;
if ( F_93 ( & V_282 , F_90 ( V_266 , 0 ) , V_281 ) ) {
F_94 ( F_90 ( V_266 , 0 ) ,
V_281 ) ;
return - V_190 ;
}
V_286 = F_95 ( V_267 , L_46 ) ;
if ( F_96 ( V_286 ) ) {
F_52 ( V_261 L_47 ) ;
F_97 ( & V_282 ) ;
F_94 ( F_90 ( V_266 , 0 ) ,
V_281 ) ;
return F_98 ( V_286 ) ;
}
F_99 () ;
for ( V_86 = 0 ; V_86 < V_275 ; V_86 ++ ) {
int V_4 ;
V_4 = F_100 ( NULL ) ;
if ( V_4 < 0 ) {
F_86 () ;
F_97 ( & V_282 ) ;
F_94 ( F_90 ( V_266 , 0 ) ,
V_281 ) ;
return V_4 ;
}
}
return 0 ;
}
static void T_6 F_101 ( void )
{
int V_86 ;
F_86 () ;
for ( V_86 = 0 ; V_86 < V_281 ; ++ V_86 )
F_102 ( V_280 [ V_86 ] ) ;
F_103 ( V_286 ) ;
F_97 ( & V_282 ) ;
F_94 ( F_90 ( V_266 , 0 ) , V_281 ) ;
F_104 () ;
}
void F_105 ( const struct V_9 * V_10 , const char * V_66 )
{
F_52 ( V_261 L_48 , V_10 -> V_4 ,
V_10 -> V_51 -> V_83 , V_66 ) ;
}
void F_106 ( struct V_9 * V_10 , struct V_65 * V_66 )
{
struct V_63 * V_64 = V_66 -> V_64 ;
unsigned V_204 = 0 ;
unsigned V_287 = 0 ;
if ( ( F_38 ( V_66 ) & V_93 ) == 0 )
return;
if ( V_66 ->
V_64 -> V_288 & ( V_213 | V_215 |
V_216 ) ) {
V_287 |= V_93 ;
}
if ( V_66 -> V_64 -> V_288 & ( V_215 | V_216 ) ) {
V_287 |= V_136 ;
V_204 |= V_136 ;
}
if ( V_287 ) {
F_57 ( V_66 , V_287 , V_204 ) ;
}
if ( V_64 -> V_212 & V_66 -> V_64 -> V_288 ) {
if ( F_38 ( V_66 ) & V_219 ) {
F_107 ( & V_64 -> V_243 ) ;
if ( V_66 -> V_92 & V_135 )
F_108 ( & V_10 -> V_274 , V_289 , V_290 ) ;
if ( V_66 -> V_92 & V_137 )
F_108 ( & V_10 -> V_274 , V_289 , V_291 ) ;
} else {
if ( V_64 -> V_292 )
V_64 -> V_292 ( V_66 -> V_64 -> V_288 , V_64 -> V_293 ) ;
}
}
V_66 -> V_64 -> V_288 = 0 ;
}
unsigned F_38 ( struct V_65 * V_66 )
{
unsigned long V_101 ;
unsigned V_204 ;
F_58 ( & V_66 -> V_203 , V_101 ) ;
V_204 = V_66 -> V_204 ;
F_59 ( & V_66 -> V_203 , V_101 ) ;
return V_204 ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_65 * V_66 ;
int V_86 ;
if ( ! V_10 -> V_19 )
return 0 ;
for ( V_86 = 0 ; V_86 < V_10 -> V_69 ; V_86 ++ ) {
V_66 = V_10 -> V_71 + V_86 ;
if ( V_66 -> V_102 )
return 1 ;
if ( V_66 -> V_64 && V_66 -> V_64 -> V_225 )
return 1 ;
}
return 0 ;
}
static void F_109 ( struct V_9 * V_10 )
{
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
F_110 ( & V_10 -> V_294 ) ;
F_111 ( & V_10 -> V_14 ) ;
V_10 -> V_4 = - 1 ;
}
static void F_112 ( struct V_9 * V_10 )
{
if ( V_10 == NULL )
return;
F_4 ( & V_10 -> V_14 ) ;
F_24 ( V_10 ) ;
F_21 ( & V_10 -> V_14 ) ;
F_113 ( & V_10 -> V_14 ) ;
}
int F_100 ( struct V_12 * V_295 )
{
unsigned long V_101 ;
struct V_7 * V_296 ;
struct V_12 * V_297 ;
unsigned V_86 ;
int V_67 ;
V_296 = F_114 ( sizeof( struct V_7 ) , V_89 ) ;
if ( V_296 == NULL )
return - V_58 ;
V_296 -> V_12 = F_114 ( sizeof( struct V_9 ) , V_89 ) ;
if ( V_296 -> V_12 == NULL ) {
F_40 ( V_296 ) ;
return - V_58 ;
}
F_109 ( V_296 -> V_12 ) ;
F_58 ( & V_298 , V_101 ) ;
for ( V_86 = 0 ; V_86 < V_278 ; ++ V_86 ) {
if ( V_280 [ V_86 ] == NULL ) {
V_280 [ V_86 ] = V_296 ;
break;
}
}
F_59 ( & V_298 , V_101 ) ;
if ( V_86 == V_278 ) {
F_112 ( V_296 -> V_12 ) ;
F_40 ( V_296 -> V_12 ) ;
F_40 ( V_296 ) ;
F_52 ( V_261
L_49
L_50 ) ;
return - V_48 ;
}
V_296 -> V_12 -> V_4 = V_86 ;
V_297 = F_115 ( V_286 , V_295 ,
F_90 ( V_266 , V_86 ) , NULL , L_51 , V_86 ) ;
if ( ! F_96 ( V_297 ) )
V_296 -> V_12 -> V_299 = V_297 ;
F_116 ( V_297 , V_296 ) ;
V_67 = F_117 ( V_297 , & V_300 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_300 . V_301 . V_302 ) ;
F_87 ( V_86 ) ;
return V_67 ;
}
V_67 = F_117 ( V_297 , & V_303 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_303 . V_301 . V_302 ) ;
F_87 ( V_86 ) ;
return V_67 ;
}
V_67 = F_117 ( V_297 , & V_304 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_304 . V_301 . V_302 ) ;
F_87 ( V_86 ) ;
return V_67 ;
}
V_67 = F_117 ( V_297 , & V_305 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_305 . V_301 . V_302 ) ;
F_87 ( V_86 ) ;
return V_67 ;
}
return V_86 ;
}
void F_87 ( unsigned V_4 )
{
unsigned long V_101 ;
struct V_7 * V_296 ;
F_102 ( V_4 >= V_278 ) ;
F_58 ( & V_298 , V_101 ) ;
V_296 = V_280 [ V_4 ] ;
V_280 [ V_4 ] = NULL ;
F_59 ( & V_298 , V_101 ) ;
if ( V_296 ) {
struct V_9 * V_10 = V_296 -> V_12 ;
if ( V_10 ) {
if ( V_10 -> V_299 ) {
F_118 ( V_286 ,
F_90 ( V_266 , V_10 -> V_4 ) ) ;
}
F_112 ( V_10 ) ;
F_40 ( V_10 ) ;
}
F_40 ( V_296 ) ;
}
}
int F_119 ( struct V_9 * V_10 ,
struct V_65 * V_66 )
{
unsigned long V_101 ;
struct V_7 * V_296 ;
struct V_12 * V_297 ;
unsigned V_86 ;
int V_67 ;
V_296 = F_47 ( sizeof( struct V_7 ) , V_89 ) ;
if ( V_296 == NULL )
return - V_58 ;
V_296 -> V_12 = V_10 ;
V_296 -> V_84 = V_66 ;
V_296 -> V_85 = V_66 ;
F_58 ( & V_298 , V_101 ) ;
for ( V_86 = V_306 ; V_86 < V_281 ; ++ V_86 ) {
if ( V_280 [ V_86 ] == NULL ) {
V_280 [ V_86 ] = V_296 ;
break;
}
}
F_59 ( & V_298 , V_101 ) ;
if ( V_86 == V_281 ) {
F_40 ( V_296 ) ;
F_52 ( V_261
L_49
L_50 ) ;
return - V_48 ;
}
V_66 -> V_4 = V_86 ;
V_297 = F_115 ( V_286 , V_10 -> V_299 ,
F_90 ( V_266 , V_86 ) , NULL , L_54 ,
V_10 -> V_4 , ( int ) ( V_66 - V_10 -> V_71 ) ) ;
if ( ! F_96 ( V_297 ) )
V_66 -> V_299 = V_297 ;
F_116 ( V_297 , V_296 ) ;
V_67 = F_117 ( V_297 , & V_300 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_300 . V_301 . V_302 ) ;
F_120 ( V_66 ) ;
return V_67 ;
}
V_67 = F_117 ( V_297 , & V_303 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_303 . V_301 . V_302 ) ;
F_120 ( V_66 ) ;
return V_67 ;
}
V_67 = F_117 ( V_297 , & V_304 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_304 . V_301 . V_302 ) ;
F_120 ( V_66 ) ;
return V_67 ;
}
V_67 = F_117 ( V_297 , & V_305 ) ;
if ( V_67 ) {
F_52 ( V_261
L_52
L_53 ,
V_305 . V_301 . V_302 ) ;
F_120 ( V_66 ) ;
return V_67 ;
}
return V_86 ;
}
void F_120 ( struct V_65 * V_66 )
{
unsigned long V_101 ;
struct V_7 * V_296 ;
if ( V_66 == NULL )
return;
if ( V_66 -> V_4 < 0 )
return;
F_102 ( V_66 -> V_4 >= V_281 ) ;
F_102 ( V_66 -> V_4 < V_306 ) ;
F_58 ( & V_298 , V_101 ) ;
V_296 = V_280 [ V_66 -> V_4 ] ;
V_280 [ V_66 -> V_4 ] = NULL ;
F_59 ( & V_298 , V_101 ) ;
if ( V_66 -> V_299 ) {
F_118 ( V_286 , F_90 ( V_266 , V_66 -> V_4 ) ) ;
V_66 -> V_299 = NULL ;
}
F_40 ( V_296 ) ;
}
struct V_7 * F_3 ( unsigned V_4 )
{
unsigned long V_101 ;
struct V_7 * V_296 ;
F_102 ( V_4 >= V_281 ) ;
F_58 ( & V_298 , V_101 ) ;
V_296 = V_280 [ V_4 ] ;
F_59 ( & V_298 , V_101 ) ;
return V_296 ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_65 * V_66 ,
struct V_63 * V_64 , unsigned V_307 )
{
int V_67 ;
if ( V_307 > V_64 -> V_75 )
return - V_47 ;
if ( V_66 -> V_102 ) {
F_6 ( L_55 ) ;
return - V_48 ;
}
if ( V_64 -> V_225 ) {
F_6 ( L_56 ) ;
return - V_48 ;
}
if ( ! V_64 -> V_259 )
return - V_70 ;
V_307 = ( V_307 + V_238 - 1 ) & V_234 ;
V_67 = F_121 ( V_10 , V_66 , V_307 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_66 -> V_308 ) {
V_67 = V_66 -> V_308 ( V_10 , V_66 , V_307 ) ;
if ( V_67 < 0 )
return V_67 ;
}
F_6 ( L_57 ,
V_10 -> V_4 , ( int ) ( V_66 - V_10 -> V_71 ) , V_64 -> V_76 ) ;
return 0 ;
}
static T_2 F_122 ( struct V_12 * V_10 ,
struct V_309 * V_301 , char * V_248 )
{
T_2 V_67 ;
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned V_310 = 0 ;
struct V_65 * const V_84 =
F_34 ( V_296 ) ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_84 &&
( V_84 -> V_92 & V_135 ) &&
V_84 -> V_64 ) {
V_310 = V_84 -> V_64 -> V_75 /
V_311 ;
}
V_67 = snprintf ( V_248 , V_238 , L_58 , V_310 ) ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return V_67 ;
}
static T_2 F_124 ( struct V_12 * V_10 ,
struct V_309 * V_301 ,
const char * V_248 , T_3 V_252 )
{
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned long V_312 ;
T_7 V_313 ;
struct V_65 * const V_84 =
F_34 ( V_296 ) ;
if ( F_125 ( V_248 , 10 , & V_312 ) )
return - V_70 ;
if ( V_312 != ( V_314 ) V_312 )
return - V_70 ;
V_313 = ( ( T_7 ) V_312 ) * V_311 ;
if ( V_313 != ( V_314 ) V_313 )
return - V_70 ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_84 == NULL ||
( V_84 -> V_92 & V_135 ) == 0 ||
V_84 -> V_64 == NULL ) {
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return - V_70 ;
}
V_84 -> V_64 -> V_75 = V_313 ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return V_252 ;
}
static T_2 F_126 ( struct V_12 * V_10 ,
struct V_309 * V_301 , char * V_248 )
{
T_2 V_67 ;
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned V_315 = 0 ;
struct V_65 * const V_84 =
F_34 ( V_296 ) ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_84 &&
( V_84 -> V_92 & V_135 ) &&
V_84 -> V_64 ) {
V_315 = V_84 -> V_64 -> V_76 /
V_311 ;
}
V_67 = snprintf ( V_248 , V_238 , L_58 , V_315 ) ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return V_67 ;
}
static T_2 F_127 ( struct V_12 * V_10 ,
struct V_309 * V_301 ,
const char * V_248 , T_3 V_252 )
{
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned long V_316 ;
T_7 V_307 ;
int V_67 ;
struct V_65 * const V_84 =
F_34 ( V_296 ) ;
if ( F_125 ( V_248 , 10 , & V_316 ) )
return - V_70 ;
if ( V_316 != ( V_314 ) V_316 )
return - V_70 ;
V_307 = ( ( T_7 ) V_316 ) * V_311 ;
if ( V_307 != ( V_314 ) V_307 )
return - V_70 ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_84 == NULL ||
( V_84 -> V_92 & V_135 ) == 0 ||
V_84 -> V_64 == NULL ) {
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return - V_70 ;
}
V_67 = F_32 ( V_296 -> V_12 , V_84 ,
V_84 -> V_64 , V_307 ) ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_67 < 0 )
return V_67 ;
return V_252 ;
}
static T_2 F_128 ( struct V_12 * V_10 ,
struct V_309 * V_301 ,
char * V_248 )
{
T_2 V_67 ;
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned V_310 = 0 ;
struct V_65 * const V_85 =
F_35 ( V_296 ) ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_85 &&
( V_85 -> V_92 & V_137 ) &&
V_85 -> V_64 ) {
V_310 = V_85 -> V_64 -> V_75 /
V_311 ;
}
V_67 = snprintf ( V_248 , V_238 , L_58 , V_310 ) ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return V_67 ;
}
static T_2 F_129 ( struct V_12 * V_10 ,
struct V_309 * V_301 ,
const char * V_248 , T_3 V_252 )
{
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned long V_312 ;
T_7 V_313 ;
struct V_65 * const V_85 =
F_35 ( V_296 ) ;
if ( F_125 ( V_248 , 10 , & V_312 ) )
return - V_70 ;
if ( V_312 != ( V_314 ) V_312 )
return - V_70 ;
V_313 = ( ( T_7 ) V_312 ) * V_311 ;
if ( V_313 != ( V_314 ) V_313 )
return - V_70 ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_85 == NULL ||
( V_85 -> V_92 & V_137 ) == 0 ||
V_85 -> V_64 == NULL ) {
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return - V_70 ;
}
V_85 -> V_64 -> V_75 = V_313 ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return V_252 ;
}
static T_2 F_130 ( struct V_12 * V_10 ,
struct V_309 * V_301 , char * V_248 )
{
T_2 V_67 ;
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned V_315 = 0 ;
struct V_65 * const V_85 =
F_35 ( V_296 ) ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_85 &&
( V_85 -> V_92 & V_137 ) &&
V_85 -> V_64 ) {
V_315 = V_85 -> V_64 -> V_76 /
V_311 ;
}
V_67 = snprintf ( V_248 , V_238 , L_58 , V_315 ) ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return V_67 ;
}
static T_2 F_131 ( struct V_12 * V_10 ,
struct V_309 * V_301 ,
const char * V_248 , T_3 V_252 )
{
struct V_7 * V_296 = F_123 ( V_10 ) ;
unsigned long V_316 ;
T_7 V_307 ;
int V_67 ;
struct V_65 * const V_85 =
F_35 ( V_296 ) ;
if ( F_125 ( V_248 , 10 , & V_316 ) )
return - V_70 ;
if ( V_316 != ( V_314 ) V_316 )
return - V_70 ;
V_307 = ( ( T_7 ) V_316 ) * V_311 ;
if ( V_307 != ( V_314 ) V_307 )
return - V_70 ;
F_4 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_85 == NULL ||
( V_85 -> V_92 & V_137 ) == 0 ||
V_85 -> V_64 == NULL ) {
F_21 ( & V_296 -> V_12 -> V_14 ) ;
return - V_70 ;
}
V_67 = F_32 ( V_296 -> V_12 , V_85 ,
V_85 -> V_64 , V_307 ) ;
F_21 ( & V_296 -> V_12 -> V_14 ) ;
if ( V_67 < 0 )
return V_67 ;
return V_252 ;
}
