static inline int
F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 = 0 ;
if ( V_2 ) {
if ( ! F_2 ( & V_1 -> V_4 . V_5 ) )
V_3 = - V_6 ;
} else {
if ( F_3 ( & V_1 -> V_4 . V_5 ) )
V_3 = - V_7 ;
}
return V_3 ;
}
static int
F_4 ( T_1 * V_1 , T_2 * V_8 , T_2 * V_9 )
{
char * V_10 ;
int V_11 ;
int V_12 ;
if ( ! V_8 )
return 0 ;
F_5 ( V_1 , F_6 ( V_13 L_1
L_2 , V_1 -> V_14 , V_8 -> V_15 . V_16 . V_17 ,
V_8 , V_9 ) ) ;
if ( V_1 -> V_4 . V_18 != V_8 -> V_15 . V_16 . V_19 )
goto V_20;
V_1 -> V_4 . V_21 |= V_22 ;
if ( ! V_9 )
goto V_23;
V_1 -> V_4 . V_21 |= V_24 ;
V_12 = F_7 ( V_1 -> V_25 , 4 * V_9 -> V_15 . V_9 . V_26 ) ;
memcpy ( V_1 -> V_4 . V_9 , V_9 , V_12 ) ;
if ( V_9 -> V_15 . V_9 . V_27 || V_9 -> V_15 . V_9 . V_28 )
F_5 ( V_1 , F_6 ( V_13
L_3 , V_1 -> V_14 ,
F_8 ( V_9 -> V_15 . V_9 . V_27 ) ,
F_9 ( V_9 -> V_15 . V_9 . V_28 ) ) ) ;
if ( ( V_8 -> V_15 . V_16 . V_17 == V_29 ) ||
( V_8 -> V_15 . V_16 . V_17 ==
V_30 ) ) {
if ( V_9 -> V_15 . V_31 . V_32 || V_9 -> V_15 . V_31 . V_33 )
F_5 ( V_1 , F_6 ( V_13
L_4
L_5 , V_1 -> V_14 ,
V_9 -> V_15 . V_31 . V_32 ,
V_9 -> V_15 . V_31 . V_33 ,
F_8 ( V_9 -> V_15 . V_31 . V_34 ) ,
F_9 ( V_9 -> V_15 . V_31 . V_35 ) ) ) ;
if ( V_9 -> V_15 . V_31 . V_33 &
V_36 ) {
V_12 = V_8 -> V_15 . V_37 . V_38 ;
V_11 =
F_8 ( V_8 -> V_15 . V_39 . V_40 . V_41 . V_42 . V_43 ) ;
V_10 = ( ( V_44 * ) V_1 -> V_45 +
( V_11 * V_46 ) ) ;
memcpy ( V_1 -> V_4 . V_47 , V_10 , V_12 ) ;
V_1 -> V_4 . V_21 |= V_48 ;
}
}
V_23:
if ( V_1 -> V_4 . V_21 & V_49 ) {
if ( V_8 -> V_15 . V_16 . V_17 == V_50 ) {
F_10 ( V_1 ) ;
V_1 -> V_4 . V_21 &= ~ V_49 ;
F_11 ( & V_1 -> V_4 . V_51 ) ;
if ( V_1 -> V_52 == V_53 )
V_1 -> V_54 ( V_1 ) ;
} else {
V_1 -> V_4 . V_21 &= ~ V_49 ;
F_11 ( & V_1 -> V_4 . V_51 ) ;
}
}
V_20:
if ( V_9 && ( V_9 -> V_15 . V_9 . V_55 &
V_56 ) )
return 0 ;
return 1 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_57 , T_2 * V_58 )
{
if ( ! V_57 )
return 0 ;
F_13 ( V_1 , F_6 ( V_13
L_6 ,
V_1 -> V_14 , V_57 , V_58 ) ) ;
V_1 -> V_59 . V_21 |= V_22 ;
if ( ! V_58 )
goto V_23;
V_1 -> V_59 . V_21 |= V_24 ;
memcpy ( V_1 -> V_59 . V_9 , V_58 ,
F_7 ( V_60 , 4 * V_58 -> V_15 . V_9 . V_26 ) ) ;
V_23:
if ( V_1 -> V_59 . V_21 & V_49 ) {
F_10 ( V_1 ) ;
V_1 -> V_59 . V_21 &= ~ V_49 ;
F_11 ( & V_1 -> V_59 . V_51 ) ;
if ( V_1 -> V_52 == V_53 )
V_1 -> V_54 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
static int
F_14 ( T_1 * V_1 , V_44 V_61 , V_44 V_62 , V_44 V_63 )
{
T_2 * V_57 ;
T_3 * V_64 ;
T_4 * V_65 ;
int V_66 ;
int V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
T_5 V_70 ;
F_15 ( & V_1 -> V_59 . V_5 ) ;
if ( F_16 ( V_1 ) != 0 ) {
F_17 ( & V_1 -> V_59 . V_5 ) ;
return - V_71 ;
}
V_67 = 0 ;
V_57 = F_18 ( V_72 , V_1 ) ;
if ( V_57 == NULL ) {
F_13 ( V_1 ,
F_6 ( V_73 L_7 ,
V_1 -> V_14 ) ) ;
F_10 ( V_1 ) ;
V_67 = - V_74 ;
goto V_75;
}
F_13 ( V_1 , F_6 ( V_13 L_8 ,
V_1 -> V_14 , V_57 ) ) ;
V_64 = ( T_3 * ) V_57 ;
memset ( V_64 , 0 , sizeof( T_3 ) ) ;
V_64 -> V_17 = V_50 ;
V_64 -> V_76 = V_61 ;
if ( ( V_61 == V_77 ) &&
( V_1 -> V_52 == V_78 ) )
V_64 -> V_55 =
V_79 ;
V_64 -> V_80 = V_63 ;
V_64 -> V_81 = V_62 ;
V_64 -> V_82 = 0 ;
V_64 -> V_83 = 0 ;
V_64 -> V_84 = 0 ;
V_64 -> V_85 = 0 ;
for ( V_66 = 0 ; V_66 < 8 ; V_66 ++ )
V_64 -> V_86 [ V_66 ] = 0 ;
for ( V_66 = 0 ; V_66 < 7 ; V_66 ++ )
V_64 -> V_87 [ V_66 ] = 0 ;
switch ( V_1 -> V_52 ) {
case V_78 :
V_68 = 40 ;
break;
case V_53 :
V_68 = 30 ;
break;
case V_88 :
default:
V_68 = 10 ;
break;
}
F_13 ( V_1 ,
F_6 ( V_13 L_9 ,
V_1 -> V_14 , V_61 , V_68 ) ) ;
F_19 (ioc->taskmgmt_cmds.status)
V_69 = V_89 ;
if ( ( V_1 -> V_90 . V_91 & V_92 ) &&
( V_1 -> V_90 . V_93 >= V_94 ) )
F_20 ( V_72 , V_1 , V_57 ) ;
else {
V_67 = F_21 ( V_72 , V_1 ,
sizeof( T_3 ) , ( V_95 * ) V_64 , V_96 ) ;
if ( V_67 != 0 ) {
F_22 ( V_1 ,
F_6 ( V_97
L_10
L_11 , V_1 -> V_14 ,
V_1 , V_57 , V_67 ) ) ;
F_23 ( V_1 , V_57 ) ;
F_10 ( V_1 ) ;
goto V_75;
}
}
V_66 = F_24 ( & V_1 -> V_59 . V_51 , V_68 * V_98 ) ;
if ( ! ( V_1 -> V_59 . V_21 & V_22 ) ) {
F_13 ( V_1 , F_6 ( V_13
L_12 , V_1 -> V_14 ) ) ;
F_23 ( V_1 , V_57 ) ;
F_10 ( V_1 ) ;
if ( V_1 -> V_59 . V_21 & V_99 )
V_67 = 0 ;
else
V_67 = - 1 ;
goto V_75;
}
if ( ! ( V_1 -> V_59 . V_21 & V_24 ) ) {
F_13 ( V_1 , F_6 ( V_13
L_12 , V_1 -> V_14 ) ) ;
V_67 = - 1 ;
goto V_75;
}
V_65 = ( T_4 * ) V_1 -> V_59 . V_9 ;
F_13 ( V_1 , F_6 ( V_13
L_13
L_14
L_15 , V_1 -> V_14 , V_65 -> V_81 ,
V_65 -> V_80 , V_61 ,
F_8 ( V_65 -> V_27 ) ,
F_9 ( V_65 -> V_28 ) ,
V_65 -> V_100 ,
F_9 ( V_65 -> V_101 ) ) ) ;
V_70 = F_8 ( V_65 -> V_27 ) & V_102 ;
if ( V_70 == V_103 ||
V_70 == V_104 ||
V_70 == V_105 )
V_67 = 0 ;
else {
F_13 ( V_1 , F_6 ( V_13
L_12 , V_1 -> V_14 ) ) ;
V_67 = - 1 ;
}
V_75:
F_17 ( & V_1 -> V_59 . V_5 ) ;
F_25 (ioc->taskmgmt_cmds.status)
return V_67 ;
}
static void
F_26 ( T_1 * V_1 , T_2 * V_57 )
{
unsigned long V_106 ;
int V_107 = - 1 ;
T_6 * V_108 = ( T_6 * ) V_57 ;
V_44 V_109 = V_57 -> V_15 . V_16 . V_17 ;
F_13 ( V_1 , F_6 ( V_13 L_16 ,
V_1 -> V_14 , V_110 ) ) ;
if ( V_111 )
F_27 ( V_1 ) ;
F_28 ( & V_1 -> V_112 , V_106 ) ;
if ( V_1 -> V_113 ) {
F_29 ( & V_1 -> V_112 , V_106 ) ;
F_30 (ioc->ioctl_cmds.status)
F_23 ( V_1 , V_57 ) ;
return;
}
F_29 ( & V_1 -> V_112 , V_106 ) ;
F_30 (ioc->ioctl_cmds.status)
if ( V_1 -> V_52 == V_53 ) {
if ( V_109 == V_29 )
V_107 = F_14 ( V_1 ,
V_114 ,
V_108 -> V_81 , V_108 -> V_80 ) ;
else if ( V_109 == V_30 )
V_107 = F_14 ( V_1 ,
V_77 ,
V_108 -> V_81 , 0 ) ;
if ( ! V_107 )
return;
} else {
if ( ( V_109 == V_29 ) ||
( V_109 == V_30 ) )
V_107 = F_14 ( V_1 ,
V_77 ,
V_108 -> V_81 , 0 ) ;
if ( ! V_107 )
return;
}
F_13 ( V_1 , F_6 ( V_13 L_17 ,
V_1 -> V_14 ) ) ;
F_31 ( V_1 , V_96 ) ;
F_23 ( V_1 , V_57 ) ;
}
static int
F_32 ( T_1 * V_1 , int V_115 )
{
switch( V_115 ) {
case V_116 :
F_13 ( V_1 , F_6 ( V_13
L_18 , V_1 -> V_14 , V_110 ) ) ;
break;
case V_117 :
F_13 ( V_1 , F_6 ( V_13
L_19 , V_1 -> V_14 , V_110 ) ) ;
break;
case V_118 :
F_13 ( V_1 , F_6 ( V_13
L_20 , V_1 -> V_14 , V_110 ) ) ;
if ( V_1 -> V_4 . V_21 & V_49 ) {
V_1 -> V_4 . V_21 |= V_99 ;
F_11 ( & V_1 -> V_4 . V_51 ) ;
}
break;
default:
break;
}
return 1 ;
}
static int
F_33 ( T_1 * V_1 , T_7 * V_119 )
{
V_44 V_120 ;
V_120 = F_9 ( V_119 -> V_121 ) & 0xFF ;
F_5 ( V_1 , F_6 ( V_13 L_21 ,
V_1 -> V_14 , V_110 ) ) ;
if( V_122 == NULL )
return 1 ;
if ( V_120 == 0x21 ) {
V_1 -> V_123 = 1 ;
F_5 ( V_1 , F_6 ( V_13 L_22 ,
V_1 -> V_14 ) ) ;
F_34 ( V_1 , F_6 ( V_13
L_22 , V_1 -> V_14 ) ) ;
F_35 ( & V_122 , V_124 , V_125 ) ;
return 1 ;
}
if( V_1 -> V_123 )
return 1 ;
if ( V_1 -> V_126 && ( V_1 -> V_127 & ( 1 << V_120 ) ) ) {
V_1 -> V_123 = 1 ;
F_5 ( V_1 , F_6 ( V_13
L_22 , V_1 -> V_14 ) ) ;
F_34 ( V_1 , F_6 ( V_13
L_22 , V_1 -> V_14 ) ) ;
F_35 ( & V_122 , V_124 , V_125 ) ;
}
return 1 ;
}
static int
F_36 ( struct V_128 * V_128 , struct V_129 * V_130 )
{
F_37 ( - 1 , V_130 , 0 , & V_122 ) ;
return 0 ;
}
static int
F_38 ( int V_131 , struct V_129 * V_130 , int V_132 )
{
T_1 * V_1 ;
int V_133 ;
F_15 ( & V_134 ) ;
F_39 (ioc, &ioc_list, list)
V_1 -> V_123 = 0 ;
V_133 = F_37 ( V_131 , V_130 , V_132 , & V_122 ) ;
F_17 ( & V_134 ) ;
return V_133 ;
}
static long
F_40 ( struct V_129 * V_129 , unsigned int V_135 , unsigned long V_136 )
{
T_8 T_9 * V_137 = ( void T_9 * ) V_136 ;
T_8 V_138 ;
int V_139 ;
unsigned V_140 ;
int V_2 = ( V_129 -> V_141 & V_142 ) ;
int V_133 ;
T_1 * V_143 = NULL ;
if ( F_41 ( & V_138 , V_137 , sizeof( V_138 ) ) ) {
F_6 (KERN_ERR MYNAM L_23
L_24 ,
__FILE__, __LINE__, uhdr) ;
return - V_144 ;
}
V_133 = - V_145 ;
V_140 = V_138 . V_139 & 0xFF ;
if ( ( ( V_139 = F_42 ( V_140 , & V_143 ) ) < 0 ) ||
( V_143 == NULL ) )
return - V_146 ;
if ( ! V_143 -> V_147 ) {
F_6 (KERN_DEBUG MYNAM L_25 ,
__FILE__, __LINE__) ;
return - V_144 ;
}
if ( ( V_135 & ~ V_148 ) == ( V_149 & ~ V_148 ) ) {
return F_43 ( V_136 , F_44 ( V_135 ) ) ;
} else if ( V_135 == V_150 ) {
return F_45 ( V_136 ) ;
} else if ( V_135 == V_151 ) {
return F_46 ( V_136 ) ;
} else if ( V_135 == V_152 ) {
return F_47 ( V_136 ) ;
} else if ( V_135 == V_153 ) {
return F_48 ( V_136 ) ;
} else if ( V_135 == V_154 ) {
return F_49 ( V_136 ) ;
} else if ( V_135 == V_155 ) {
return F_50 ( V_136 ) ;
}
if ( ( V_133 = F_1 ( V_143 , V_2 ) ) != 0 )
return V_133 ;
if ( V_135 == V_156 )
V_133 = F_51 ( V_136 ) ;
else if ( V_135 == V_157 )
V_133 = F_52 ( V_136 ) ;
else if ( V_135 == V_158 )
V_133 = F_53 ( V_136 ) ;
else if ( ( V_135 & ~ V_148 ) == ( V_159 & ~ V_148 ) )
V_133 = F_54 ( V_136 , F_44 ( V_135 ) ) ;
else if ( V_135 == V_160 )
V_133 = F_55 ( V_136 ) ;
else
V_133 = - V_161 ;
F_17 ( & V_143 -> V_4 . V_5 ) ;
return V_133 ;
}
static long
F_56 ( struct V_129 * V_129 , unsigned int V_135 , unsigned long V_136 )
{
long V_133 ;
F_15 ( & V_134 ) ;
V_133 = F_40 ( V_129 , V_135 , V_136 ) ;
F_17 ( & V_134 ) ;
return V_133 ;
}
static int F_53 ( unsigned long V_136 )
{
struct V_162 T_9 * V_163 = ( void T_9 * ) V_136 ;
struct V_162 V_164 ;
T_1 * V_143 ;
if ( F_41 ( & V_164 , V_163 , sizeof( struct V_162 ) ) ) {
F_6 (KERN_ERR MYNAM L_26
L_27 ,
__FILE__, __LINE__, urinfo) ;
return - V_144 ;
}
if ( F_42 ( V_164 . V_16 . V_139 , & V_143 ) < 0 ) {
F_6 (KERN_DEBUG MYNAM L_28 ,
__FILE__, __LINE__, krinfo.hdr.iocnum) ;
return - V_146 ;
}
F_5 ( V_143 , F_6 ( V_13 L_29 ,
V_143 -> V_14 ) ) ;
if ( F_57 ( V_143 , V_96 ) != 0 ) {
F_6 ( V_97 L_30 ,
V_143 -> V_14 , __FILE__ , __LINE__ ) ;
return - 1 ;
}
return 0 ;
}
static int
F_51 ( unsigned long V_136 )
{
struct V_165 T_9 * V_166 = ( void T_9 * ) V_136 ;
struct V_165 V_167 ;
if ( F_41 ( & V_167 , V_166 , sizeof( struct V_165 ) ) ) {
F_6 (KERN_ERR MYNAM L_31
L_32 ,
__FILE__, __LINE__, ufwdl) ;
return - V_144 ;
}
return F_58 ( V_167 . V_139 , V_167 . V_168 , V_167 . V_169 ) ;
}
static int
F_58 ( int V_1 , char T_9 * V_170 , T_10 V_169 )
{
T_11 * V_171 ;
T_2 * V_57 ;
T_1 * V_143 ;
T_12 * V_172 ;
T_13 * V_173 , * V_174 ;
char * V_175 ;
struct V_176 * V_176 ;
struct V_176 * V_177 ;
T_14 V_178 ;
int V_133 ;
int V_179 = 0 ;
int V_180 ;
int V_181 = 0 ;
V_95 V_182 ;
V_95 V_183 ;
int V_184 = 0 ;
int V_185 ;
int V_186 = 0 ;
T_5 V_187 ;
T_15 V_188 = NULL ;
unsigned long V_189 ;
if ( F_42 ( V_1 , & V_143 ) < 0 ) {
F_6 (KERN_DEBUG MYNAM L_33 ,
ioc) ;
return - V_146 ;
} else {
if ( ( V_57 = F_18 ( V_190 , V_143 ) ) == NULL )
return - V_6 ;
}
F_5 ( V_143 , F_6 ( V_13
L_34 , V_143 -> V_14 , V_190 ) ) ;
F_5 ( V_143 , F_6 ( V_13 L_35 ,
V_143 -> V_14 , V_170 ) ) ;
F_5 ( V_143 , F_6 ( V_13 L_36 ,
V_143 -> V_14 , ( int ) V_169 ) ) ;
F_5 ( V_143 , F_6 ( V_13 L_37 ,
V_143 -> V_14 , V_1 ) ) ;
V_171 = ( T_11 * ) V_57 ;
V_172 = ( T_12 * ) & V_171 -> V_191 ;
V_175 = ( char * ) ( V_172 + 1 ) ;
V_171 -> V_192 = V_193 ;
V_171 -> V_83 = 0 ;
V_171 -> V_82 = 0 ;
V_171 -> V_17 = V_194 ;
V_171 -> V_84 [ 0 ] = V_171 -> V_84 [ 1 ] = V_171 -> V_84 [ 2 ] = 0 ;
if ( V_143 -> V_90 . V_93 >= V_94 )
V_171 -> V_55 = V_195 ;
else
V_171 -> V_55 = 0 ;
V_172 -> V_83 = 0 ;
V_172 -> V_196 = 0 ;
V_172 -> V_197 = 12 ;
V_172 -> V_198 = V_199 ;
V_172 -> V_200 = 0 ;
V_172 -> V_201 = 0 ;
V_172 -> V_202 = F_59 ( V_169 ) ;
V_182 = 0x04000000 ;
V_186 = sizeof( V_203 ) + sizeof( T_12 ) ;
if ( ( V_173 = F_60 ( V_169 , V_182 , V_186 ,
& V_179 , & V_176 , & V_178 , V_143 ) ) == NULL )
return - V_74 ;
V_180 = ( V_143 -> V_204 - sizeof( V_203 ) -
sizeof( T_12 ) )
/ V_143 -> V_205 ;
if ( V_179 > V_180 ) {
V_133 = - V_206 ;
goto V_207;
}
F_5 ( V_143 , F_6 ( V_13 L_38 ,
V_143 -> V_14 , V_173 , V_179 ) ) ;
V_133 = - V_144 ;
V_174 = V_173 ;
V_177 = V_176 ;
for ( V_185 = 0 ; V_185 < V_179 ; V_185 ++ ) {
V_183 = ( V_174 -> V_208 & 0x30000000 ) >> 28 ;
if ( V_183 == 0 || V_183 == 3 ) {
;
} else if ( V_174 -> V_209 ) {
V_143 -> V_210 ( V_175 , V_174 -> V_208 , V_174 -> V_209 ) ;
V_181 ++ ;
if ( F_41 ( V_177 -> V_211 , V_170 + V_184 , V_177 -> V_212 ) ) {
F_6 ( V_97 L_31
L_39 ,
V_143 -> V_14 , __FILE__ , __LINE__ , V_181 , V_170 ) ;
goto V_207;
}
V_184 += V_177 -> V_212 ;
}
V_174 ++ ;
V_177 ++ ;
V_175 += V_143 -> V_205 ;
}
F_61 ( V_143 , ( V_95 * ) V_57 , V_179 ) ;
V_188 = NULL ;
F_62 ( V_143 -> V_4 . V_18 , V_171 -> V_19 ) ;
F_19 (iocp->ioctl_cmds.status)
F_63 ( V_190 , V_143 , V_57 ) ;
V_213:
V_189 = F_24 ( & V_143 -> V_4 . V_51 , V_98 * 60 ) ;
if ( ! ( V_143 -> V_4 . V_21 & V_22 ) ) {
V_133 = - V_214 ;
F_6 ( V_73 L_40 , V_143 -> V_14 , V_110 ) ;
if ( V_143 -> V_4 . V_21 & V_99 ) {
F_23 ( V_143 , V_57 ) ;
goto V_207;
}
if ( ! V_189 ) {
F_6 ( V_73
L_41 ,
V_143 -> V_14 , F_64 ( V_143 , 0 ) ) ;
F_26 ( V_143 , V_57 ) ;
} else
goto V_213;
goto V_207;
}
if ( ! ( V_143 -> V_4 . V_21 & V_24 ) ) {
F_6 ( V_73 L_40 , V_143 -> V_14 , V_110 ) ;
F_23 ( V_143 , V_57 ) ;
V_133 = - V_215 ;
goto V_207;
}
if ( V_173 )
F_65 ( V_173 , V_178 , V_176 , V_143 ) ;
V_188 = ( T_15 ) V_143 -> V_4 . V_9 ;
V_187 = F_8 ( V_188 -> V_27 ) & V_102 ;
if ( V_187 == V_105 ) {
F_6 ( V_216 L_42 , V_143 -> V_14 ) ;
return 0 ;
} else if ( V_187 == V_217 ) {
F_6 ( V_73 L_43 ,
V_143 -> V_14 ) ;
F_6 ( V_73 L_44 ,
V_143 -> V_14 ) ;
return - V_218 ;
} else if ( V_187 == V_219 ) {
F_6 ( V_73 L_45 , V_143 -> V_14 ) ;
F_6 ( V_73 L_46 , V_143 -> V_14 ) ;
return - V_220 ;
} else {
F_6 ( V_73 L_47 ,
V_143 -> V_14 , V_187 ) ;
F_6 ( V_73 L_48 , V_143 -> V_14 ) ;
return - V_221 ;
}
return 0 ;
V_207:
F_25 ( V_143 -> V_4 . V_21 ) ;
F_62 ( V_143 -> V_4 . V_18 , 0 ) ;
F_65 ( V_173 , V_178 , V_176 , V_143 ) ;
return V_133 ;
}
static T_13 *
F_60 ( int V_222 , V_95 V_182 , int V_186 , int * V_223 ,
struct V_176 * * V_224 , T_14 * V_225 , T_1 * V_1 )
{
T_13 * V_226 = NULL ;
struct V_176 * V_176 = NULL ;
T_13 * V_173 ;
int V_179 = 0 ;
int V_227 = 0 ;
int V_228 = F_7 ( V_222 , V_229 ) ;
int V_230 = 0 ;
int V_231 ;
T_14 V_232 ;
int V_185 , V_233 ;
int V_234 = V_235 ;
int V_236 ;
* V_223 = 0 ;
* V_224 = NULL ;
V_185 = V_237 / 8 ;
V_176 = F_66 ( V_185 , V_238 ) ;
if ( ! V_176 )
return NULL ;
V_233 = 0 ;
V_226 = F_67 ( V_1 -> V_239 , V_237 , V_225 ) ;
if ( V_226 == NULL )
goto V_240;
if ( V_182 & 0x04000000 )
V_236 = V_241 ;
else
V_236 = V_242 ;
V_173 = V_226 ;
V_234 = ( ( V_1 -> V_204 - V_186 ) / V_1 -> V_205 ) - 1 ;
while ( V_230 < V_222 ) {
V_231 = F_7 ( V_228 , V_222 - V_230 ) ;
V_176 [ V_233 ] . V_212 = V_231 ;
V_176 [ V_233 ] . V_211 = F_67 ( V_1 -> V_239 ,
V_231 ,
& V_232 ) ;
if ( V_176 [ V_233 ] . V_211 == NULL ) {
V_228 = V_228 / 2 ;
if ( V_228 == 0 ) {
F_6 ( V_73 L_49
L_50 , V_1 -> V_14 ) ;
F_6 ( V_73 L_51 ,
V_1 -> V_14 , V_179 ) ;
goto V_240;
}
continue;
} else {
T_14 V_243 ;
V_230 += V_231 ;
V_173 -> V_208 = ( 0x10000000 | V_182 | V_231 ) ;
V_243 = F_68 ( V_1 -> V_239 ,
V_176 [ V_233 ] . V_211 , V_231 , V_236 ) ;
V_173 -> V_209 = V_243 ;
V_227 ++ ;
V_179 ++ ;
V_173 ++ ;
V_233 ++ ;
}
if ( V_230 >= V_222 )
break;
if ( V_227 == V_234 ) {
F_6 ( V_73
L_49 L_52 , V_1 -> V_14 ) ;
F_6 ( V_73 L_53 , V_1 -> V_14 , V_179 ) ;
goto V_240;
}
if ( V_179 * 8 > V_237 ) {
F_6 ( V_73 L_49
L_54 , V_1 -> V_14 ) ;
F_6 ( V_73 L_51 ,
V_1 -> V_14 , V_179 ) ;
goto V_240;
}
}
V_173 [ - 1 ] . V_208 |= 0xC1000000 ;
* V_223 = V_179 ;
* V_224 = V_176 ;
F_5 ( V_1 , F_6 ( V_13 L_55
L_56 , V_1 -> V_14 , V_179 ) ) ;
F_5 ( V_1 , F_6 ( V_13 L_55
L_57 , V_1 -> V_14 , V_228 ) ) ;
return V_226 ;
V_240:
if ( V_226 != NULL ) {
for ( V_185 = 0 ; V_185 < V_179 ; V_185 ++ ) {
T_14 V_243 ;
V_44 * V_211 ;
int V_212 ;
if ( ( V_226 [ V_185 ] . V_208 >> 24 ) == 0x30 )
continue;
V_243 = V_226 [ V_185 ] . V_209 ;
V_211 = V_176 [ V_185 ] . V_211 ;
V_212 = V_176 [ V_185 ] . V_212 ;
F_69 ( V_1 -> V_239 , V_212 , V_211 , V_243 ) ;
}
F_69 ( V_1 -> V_239 , V_237 , V_226 , * V_225 ) ;
}
F_70 ( V_176 ) ;
return NULL ;
}
static void
F_65 ( T_13 * V_173 , T_14 V_178 , struct V_176 * V_176 , T_1 * V_1 )
{
T_13 * V_244 = V_173 ;
struct V_176 * V_177 = V_176 ;
V_95 V_183 ;
int V_236 ;
int V_181 = 0 ;
if ( V_244 -> V_208 & 0x04000000 )
V_236 = V_241 ;
else
V_236 = V_242 ;
V_183 = ( V_244 -> V_208 & 0xF0000000 ) >> 28 ;
while ( ! ( V_183 & 0x4 ) ) {
if ( V_183 == 0 || V_183 == 3 ) {
;
} else if ( V_244 -> V_209 ) {
T_14 V_243 ;
void * V_211 ;
int V_212 ;
V_243 = V_244 -> V_209 ;
V_211 = V_177 -> V_211 ;
V_212 = V_177 -> V_212 ;
F_71 ( V_1 -> V_239 , V_243 , V_212 , V_236 ) ;
F_69 ( V_1 -> V_239 , V_212 , V_211 , V_243 ) ;
V_181 ++ ;
}
V_244 ++ ;
V_177 ++ ;
V_183 = ( F_9 ( V_244 -> V_208 ) & 0xF0000000 ) >> 28 ;
}
if ( V_244 -> V_209 ) {
T_14 V_243 ;
void * V_211 ;
int V_212 ;
V_243 = V_244 -> V_209 ;
V_211 = V_177 -> V_211 ;
V_212 = V_177 -> V_212 ;
F_71 ( V_1 -> V_239 , V_243 , V_212 , V_236 ) ;
F_69 ( V_1 -> V_239 , V_212 , V_211 , V_243 ) ;
V_181 ++ ;
}
F_69 ( V_1 -> V_239 , V_237 , V_173 , V_178 ) ;
F_70 ( V_176 ) ;
F_5 ( V_1 , F_6 ( V_13 L_58 ,
V_1 -> V_14 , V_181 ) ) ;
}
static int
F_43 ( unsigned long V_136 , unsigned int V_245 )
{
struct V_246 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_246 * V_248 ;
T_1 * V_1 ;
struct V_249 * V_250 ;
int V_139 ;
unsigned int V_251 ;
int V_252 ;
struct V_253 * V_254 ;
T_16 * V_255 ;
if ( V_245 == sizeof( struct V_256 ) )
V_252 = 0 ;
else if ( V_245 == sizeof( struct V_257 ) )
V_252 = 1 ;
else if ( V_245 == sizeof( struct V_246 ) )
V_252 = 2 ;
else if ( V_245 == ( sizeof( struct V_256 ) + 12 ) )
V_252 = 0 ;
else
return - V_144 ;
V_248 = F_72 ( V_245 , V_258 ) ;
if ( V_248 == NULL ) {
F_6 (KERN_ERR MYNAM L_59 ,
__FILE__, __LINE__) ;
return - V_74 ;
}
if ( F_41 ( V_248 , V_247 , V_245 ) ) {
F_6 (KERN_ERR MYNAM L_60
L_61 ,
__FILE__, __LINE__, uarg) ;
F_70 ( V_248 ) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 -> V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_62 ,
__FILE__, __LINE__, iocnum) ;
F_70 ( V_248 ) ;
return - V_146 ;
}
if ( V_248 -> V_16 . V_259 != V_245 ) {
F_6 ( V_97 L_60
L_63 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
F_70 ( V_248 ) ;
return - V_144 ;
}
F_5 ( V_1 , F_6 ( V_13 L_64 ,
V_1 -> V_14 ) ) ;
if ( V_1 -> V_52 == V_53 )
V_248 -> V_260 = V_261 ;
else if ( V_1 -> V_52 == V_78 )
V_248 -> V_260 = V_262 ;
else
V_248 -> V_260 = V_263 ;
if ( V_248 -> V_16 . V_251 > 1 ) {
F_70 ( V_248 ) ;
return - V_161 ;
}
V_251 = V_248 -> V_16 . V_251 ;
V_248 -> V_251 = V_251 ;
V_250 = (struct V_249 * ) V_1 -> V_239 ;
V_248 -> V_264 = V_250 -> V_265 ;
V_248 -> V_266 = V_250 -> V_267 ;
V_248 -> V_268 = V_250 -> V_269 ;
V_248 -> V_270 = V_250 -> V_271 ;
if ( V_252 == 1 ) {
V_248 -> V_272 . V_15 . V_273 . V_274 = V_250 -> V_275 -> V_276 ;
V_248 -> V_272 . V_15 . V_273 . V_277 = F_73 ( V_250 -> V_278 ) ;
V_248 -> V_272 . V_15 . V_273 . V_279 = F_74 ( V_250 -> V_278 ) ;
} else if ( V_252 == 2 ) {
V_248 -> V_272 . V_15 . V_273 . V_274 = V_250 -> V_275 -> V_276 ;
V_248 -> V_272 . V_15 . V_273 . V_277 = F_73 ( V_250 -> V_278 ) ;
V_248 -> V_272 . V_15 . V_273 . V_279 = F_74 ( V_250 -> V_278 ) ;
V_248 -> V_272 . V_280 = F_75 ( V_250 -> V_275 ) ;
}
V_248 -> V_281 = 0 ;
if ( V_1 -> V_282 ) {
F_76 (sdev, ioc->sh) {
V_255 = V_254 -> V_283 ;
if ( V_255 == NULL || V_255 -> V_284 == NULL )
continue;
if ( V_255 -> V_284 -> V_285 &
V_286 )
continue;
V_248 -> V_281 ++ ;
}
}
V_248 -> V_287 = V_1 -> V_90 . V_287 . V_288 ;
V_248 -> V_289 = V_1 -> V_290 ;
strncpy ( V_248 -> V_291 , V_292 , V_293 ) ;
V_248 -> V_291 [ V_293 - 1 ] = '\0' ;
V_248 -> V_294 = 0 ;
V_248 -> V_295 = V_1 -> V_296 [ V_251 ] . V_297 ;
V_248 -> V_298 [ 0 ] = V_248 -> V_298 [ 1 ] = 0 ;
if ( F_77 ( ( char T_9 * ) V_136 , V_248 , V_245 ) ) {
F_6 ( V_97 L_60
L_65 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
F_70 ( V_248 ) ;
return - V_144 ;
}
F_70 ( V_248 ) ;
return 0 ;
}
static int
F_45 ( unsigned long V_136 )
{
struct V_299 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_299 V_248 ;
T_1 * V_1 ;
T_16 * V_255 ;
char * V_300 ;
int * V_301 ;
int V_139 ;
int V_281 = 0 ;
int V_302 ;
int V_303 ;
int V_304 ;
V_44 V_251 ;
struct V_253 * V_254 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_299 ) ) ) {
F_6 (KERN_ERR MYNAM L_66
L_67 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_68 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_69 ,
V_1 -> V_14 ) ) ;
V_304 = V_248 . V_16 . V_259 - sizeof( T_8 ) ;
V_303 = V_304 / sizeof( int ) ;
V_251 = V_248 . V_16 . V_251 ;
if ( V_303 <= 0 ) {
F_6 ( V_97 L_70 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
return - V_74 ;
}
V_300 = F_66 ( V_304 , V_258 ) ;
if ( ! V_300 ) {
F_6 ( V_97 L_70 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
return - V_74 ;
}
V_301 = ( int * ) V_300 ;
if ( V_1 -> V_282 ) {
F_76 (sdev, ioc->sh) {
if ( ! V_303 )
continue;
V_255 = V_254 -> V_283 ;
if ( V_255 == NULL || V_255 -> V_284 == NULL )
continue;
if ( V_255 -> V_284 -> V_285 &
V_286 )
continue;
V_302 = ( V_255 -> V_284 -> V_305 ) ? 0x80 : V_255 -> V_302 ;
* V_301 = ( ( ( V_44 ) V_302 << 16 ) + ( V_255 -> V_284 -> V_306 << 8 ) +
( V_255 -> V_284 -> V_307 ) ) ;
V_301 ++ ;
V_281 ++ ;
-- V_303 ;
}
}
V_248 . V_281 = V_281 ;
if ( F_77 ( ( char T_9 * ) V_136 , & V_248 ,
sizeof( struct V_299 ) ) ) {
F_6 ( V_97 L_66
L_71 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
F_70 ( V_300 ) ;
return - V_144 ;
}
if ( F_77 ( V_247 -> V_308 , V_300 , V_304 ) ) {
F_6 ( V_97 L_66
L_71 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_301 ) ;
F_70 ( V_300 ) ;
return - V_144 ;
}
F_70 ( V_300 ) ;
return 0 ;
}
static int
F_46 ( unsigned long V_136 )
{
struct V_309 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_309 V_248 ;
T_1 * V_1 ;
int V_139 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_309 ) ) ) {
F_6 (KERN_ERR MYNAM L_72
L_73 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_74 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_75 ,
V_1 -> V_14 ) ) ;
#ifdef F_78
V_248 . V_310 = V_1 -> V_311 ;
#else
V_248 . V_310 = V_1 -> V_239 -> V_265 ;
#endif
strncpy ( V_248 . V_14 , V_1 -> V_14 , V_312 ) ;
V_248 . V_14 [ V_312 - 1 ] = '\0' ;
strncpy ( V_248 . V_313 , V_1 -> V_314 , V_315 ) ;
V_248 . V_313 [ V_315 - 1 ] = '\0' ;
if ( F_77 ( ( char T_9 * ) V_136 , & V_248 , sizeof( struct V_309 ) ) ) {
F_6 ( V_97 L_72
L_76 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
return - V_144 ;
}
return 0 ;
}
static int
F_47 ( unsigned long V_136 )
{
struct V_316 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_316 V_248 ;
T_1 * V_1 ;
int V_139 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_316 ) ) ) {
F_6 (KERN_ERR MYNAM L_77
L_78 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_79 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_80 ,
V_1 -> V_14 ) ) ;
V_248 . V_317 = V_318 ;
V_248 . V_127 = V_1 -> V_127 ;
if ( F_77 ( ( char T_9 * ) V_136 , & V_248 , sizeof( struct V_316 ) ) ) {
F_6 ( V_97 L_77
L_81 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
return - V_144 ;
}
return 0 ;
}
static int
F_48 ( unsigned long V_136 )
{
struct V_319 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_319 V_248 ;
T_1 * V_1 ;
int V_139 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_319 ) ) ) {
F_6 (KERN_ERR MYNAM L_82
L_83 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_84 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_85 ,
V_1 -> V_14 ) ) ;
if ( V_1 -> V_126 == NULL ) {
int V_12 = V_318 * sizeof( V_320 ) ;
V_1 -> V_126 = F_66 ( V_12 , V_258 ) ;
if ( ! V_1 -> V_126 ) {
F_6 ( V_97
L_86 ,
V_1 -> V_14 ) ;
return - V_74 ;
}
V_1 -> V_321 += V_12 ;
V_1 -> V_322 = 0 ;
}
V_1 -> V_127 = V_248 . V_127 ;
return 0 ;
}
static int
F_49 ( unsigned long V_136 )
{
struct V_323 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_323 V_248 ;
T_1 * V_1 ;
int V_139 ;
int V_304 , V_324 , V_325 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_323 ) ) ) {
F_6 (KERN_ERR MYNAM L_87
L_88 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_89 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_90 ,
V_1 -> V_14 ) ) ;
V_304 = V_248 . V_16 . V_259 - sizeof( T_8 ) ;
V_324 = V_304 / sizeof( V_320 ) ;
V_325 = V_318 < V_324 ? V_318 : V_324 ;
if ( ( V_325 < 1 ) || ! V_1 -> V_126 )
return - V_215 ;
V_1 -> V_123 = 0 ;
V_304 = V_325 * sizeof( V_320 ) ;
if ( F_77 ( V_247 -> V_326 , V_1 -> V_126 , V_304 ) ) {
F_6 ( V_97 L_87
L_91 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_1 -> V_126 ) ;
return - V_144 ;
}
return 0 ;
}
static int
F_50 ( unsigned long V_136 )
{
struct V_327 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_327 V_248 ;
T_1 * V_1 ;
int V_139 ;
int V_328 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_327 ) ) ) {
F_6 (KERN_ERR MYNAM L_92
L_93 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_94 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_95 ,
V_1 -> V_14 ) ) ;
if ( V_1 -> V_329 == NULL )
return 0 ;
F_79 ( V_1 ) ;
V_328 = V_248 . V_330 ;
if ( V_328 & 0x01 )
V_328 += 1 ;
if ( V_328 & 0x02 )
V_328 += 2 ;
F_80 ( V_1 , V_328 ) ;
if ( V_1 -> V_329 == NULL )
return - V_74 ;
if ( F_41 ( V_1 -> V_329 , V_247 -> V_331 , V_328 ) ) {
F_6 ( V_97 L_92
L_96
L_97 , V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
F_79 ( V_1 ) ;
return - V_144 ;
}
V_1 -> V_90 . V_332 = V_328 ;
return 0 ;
}
static int
F_52 ( unsigned long V_136 )
{
struct V_333 T_9 * V_247 = ( void T_9 * ) V_136 ;
struct V_333 V_248 ;
T_1 * V_1 ;
int V_139 ;
int V_3 ;
if ( F_41 ( & V_248 , V_247 , sizeof( struct V_333 ) ) ) {
F_6 (KERN_ERR MYNAM L_98
L_99 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_100 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
V_3 = F_81 ( V_248 , & V_247 -> V_334 ) ;
return V_3 ;
}
static int
F_81 ( struct V_333 V_248 , void T_9 * V_335 )
{
T_1 * V_1 ;
T_2 * V_57 = NULL ;
V_203 * V_16 ;
char * V_336 ;
struct V_176 V_337 ;
struct V_176 V_338 ;
T_14 V_339 ;
T_14 V_340 ;
int V_341 = 0 ;
int V_139 , V_342 ;
int V_12 , V_3 = 0 ;
int V_343 ;
T_5 V_43 ;
T_17 V_68 ;
unsigned long V_189 ;
struct V_253 * V_254 ;
unsigned long V_106 ;
V_44 V_109 ;
V_337 . V_211 = V_338 . V_211 = NULL ;
V_337 . V_212 = V_338 . V_212 = 0 ;
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_101 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_28 ( & V_1 -> V_112 , V_106 ) ;
if ( V_1 -> V_113 ) {
F_29 ( & V_1 -> V_112 , V_106 ) ;
F_6 (KERN_ERR MYNAM L_102
L_103 , __FILE__, __LINE__) ;
return - V_220 ;
}
F_29 ( & V_1 -> V_112 , V_106 ) ;
V_12 = V_248 . V_344 * 4 ;
if ( V_248 . V_345 > 0 )
V_12 += V_1 -> V_205 ;
if ( V_248 . V_346 > 0 )
V_12 += V_1 -> V_205 ;
if ( V_12 > V_1 -> V_204 ) {
F_6 ( V_97 L_102
L_104 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_12 , V_1 -> V_204 ) ;
return - V_144 ;
}
if ( ( V_57 = F_18 ( V_190 , V_1 ) ) == NULL )
return - V_6 ;
V_16 = ( V_203 * ) V_57 ;
V_343 = F_9 ( V_16 -> V_19 ) ;
V_43 = F_8 ( V_57 -> V_15 . V_39 . V_40 . V_41 . V_42 . V_43 ) ;
if ( F_41 ( V_57 , V_335 , V_248 . V_344 * 4 ) ) {
F_6 ( V_97 L_102
L_105 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_335 ) ;
V_109 = - 1 ;
V_3 = - V_144 ;
goto V_347;
}
V_16 -> V_19 = F_59 ( V_343 ) ;
V_109 = V_16 -> V_17 ;
F_5 ( V_1 , F_6 ( V_13 L_106 ,
V_1 -> V_14 , V_16 -> V_17 , V_57 ) ) ;
switch ( V_109 ) {
case V_348 :
case V_349 :
V_248 . V_346 = V_248 . V_345 = 0 ;
break;
case V_350 :
{
T_18 * V_351 ;
V_351 = ( T_18 * ) V_57 ;
F_5 ( V_1 , F_6 ( V_13 L_107
L_108 , V_1 -> V_14 ,
V_351 -> V_352 . V_353 ,
V_351 -> V_354 ,
V_351 -> V_352 . V_355 ,
V_351 -> V_356 ) ) ;
break;
}
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_194 :
case V_361 :
case V_362 :
case V_363 :
break;
case V_29 :
if ( V_1 -> V_282 ) {
T_6 * V_364 = ( T_6 * ) V_57 ;
int V_365 = V_366 ;
int V_367 = 0 ;
int V_368 ;
V_95 V_307 ;
V_307 = ( V_1 -> V_369 == 0 ) ? 256 : V_1 -> V_369 ;
if ( V_364 -> V_80 > V_307 ) {
F_6 ( V_97 L_102
L_109 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
V_3 = - V_146 ;
goto V_347;
}
if ( V_364 -> V_81 >= V_1 -> V_370 ) {
F_6 ( V_97 L_102
L_110 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
V_3 = - V_146 ;
goto V_347;
}
V_364 -> V_55 &= ~ V_371 ;
V_364 -> V_55 |= F_82 ( V_1 ) ;
if ( V_248 . V_372 > V_373 )
V_364 -> V_38 = V_373 ;
else
V_364 -> V_38 = V_248 . V_372 ;
V_364 -> V_374 =
F_59 ( V_1 -> V_375
+ ( V_43 * V_46 ) ) ;
F_76 (sdev, ioc->sh) {
struct V_376 * V_377 = V_376 ( V_254 ) ;
T_19 * V_284 = V_377 -> V_283 ;
if ( V_284 == NULL )
continue;
if ( ( V_364 -> V_80 == V_284 -> V_307 ) &&
( V_364 -> V_81 == V_284 -> V_306 ) &&
( V_284 -> V_285 & V_378 ) )
V_365 = V_379 ;
}
if ( V_248 . V_346 > 0 ) {
V_367 = V_380 ;
V_368 = V_248 . V_346 ;
} else {
V_367 = V_381 ;
V_368 = V_248 . V_345 ;
}
V_364 -> V_382 = F_59 ( V_367 | V_365 ) ;
V_364 -> V_383 = F_59 ( V_368 ) ;
} else {
F_6 ( V_97 L_102
L_111 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
V_3 = - V_144 ;
goto V_347;
}
break;
case V_384 :
break;
case V_385 :
if ( ! V_1 -> V_282 ) {
F_6 ( V_97 L_102
L_111 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
V_3 = - V_144 ;
goto V_347;
}
break;
case V_386 :
break;
case V_30 :
if ( V_1 -> V_282 ) {
T_6 * V_364 = ( T_6 * ) V_57 ;
int V_365 = V_379 ;
int V_367 = V_381 ;
int V_368 ;
V_364 -> V_55 &= ~ V_371 ;
V_364 -> V_55 |= F_82 ( V_1 ) ;
if ( V_248 . V_372 > V_373 )
V_364 -> V_38 = V_373 ;
else
V_364 -> V_38 = V_248 . V_372 ;
V_364 -> V_374 =
F_59 ( V_1 -> V_375
+ ( V_43 * V_46 ) ) ;
if ( V_248 . V_346 > 0 ) {
V_367 = V_380 ;
V_368 = V_248 . V_346 ;
} else {
V_367 = V_381 ;
V_368 = V_248 . V_345 ;
}
V_364 -> V_382 = F_59 ( V_367 | V_365 ) ;
V_364 -> V_383 = F_59 ( V_368 ) ;
} else {
F_6 ( V_97 L_102
L_111 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
V_3 = - V_144 ;
goto V_347;
}
break;
case V_50 :
{
T_3 * V_64 ;
V_64 = ( T_3 * ) V_57 ;
F_5 ( V_1 , F_6 ( V_13
L_112
L_113 ,
V_1 -> V_14 , V_64 -> V_76 , F_9
( V_64 -> V_85 ) , V_64 -> V_55 ,
V_64 -> V_80 , V_64 -> V_81 ) ) ;
break;
}
case V_387 :
{
T_20 * V_388 = ( T_20 * ) V_57 ;
V_95 V_389 , V_390 ;
if ( sizeof( T_14 ) == sizeof( V_391 ) ) {
V_389 = F_59 ( ( V_95 ) ( ( V_391 ) V_1 -> V_392 >> 32 ) ) ;
V_390 = F_59 ( ( V_95 ) ( ( V_391 ) V_1 -> V_393 >> 32 ) ) ;
} else {
V_389 = 0 ;
V_390 = 0 ;
}
if ( ( V_388 -> V_198 != 0 ) || ( V_388 -> V_394 != V_1 -> V_90 . V_394 ) ||
( V_388 -> V_395 != V_1 -> V_90 . V_395 ) ||
( V_388 -> V_396 != F_83 ( V_1 -> V_25 ) ) ||
( V_388 -> V_397 != V_389 ) ||
( V_388 -> V_398 != V_390 ) ) {
F_6 ( V_97 L_102
L_114 ,
V_1 -> V_14 , __FILE__ , __LINE__ ) ;
V_3 = - V_144 ;
goto V_347;
}
}
break;
default:
F_6 ( V_97 L_102
L_115 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_16 -> V_17 ) ;
V_3 = - V_144 ;
goto V_347;
}
V_336 = ( char * ) ( ( ( int * ) V_57 ) + V_248 . V_344 ) ;
V_342 = 0 ;
if ( V_248 . V_346 > 0 )
V_341 ++ ;
if ( V_248 . V_345 > 0 )
V_341 ++ ;
if ( V_341 > 0 ) {
if ( V_248 . V_346 > 0 ) {
if ( V_248 . V_345 > 0 ) {
V_342 = ( V_399 |
V_400 |
V_401 )
<< V_402 ;
} else {
V_342 = V_403 ;
}
V_342 |= V_248 . V_346 ;
V_338 . V_212 = V_248 . V_346 ;
V_338 . V_211 = F_67 (
V_1 -> V_239 , V_338 . V_212 , & V_340 ) ;
if ( V_338 . V_211 == NULL ) {
V_3 = - V_74 ;
goto V_347;
} else {
V_1 -> V_210 ( V_336 , V_342 , V_340 ) ;
V_336 += V_1 -> V_205 ;
if ( F_41 ( V_338 . V_211 ,
V_248 . V_404 ,
V_338 . V_212 ) ) {
F_6 ( V_97
L_116
L_117
L_118 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_248 . V_404 ) ;
V_3 = - V_144 ;
goto V_347;
}
}
}
if ( V_248 . V_345 > 0 ) {
V_342 = V_405 ;
V_342 |= V_248 . V_345 ;
V_337 . V_212 = V_248 . V_345 ;
V_337 . V_211 = F_67 ( V_1 -> V_239 ,
V_337 . V_212 , & V_339 ) ;
if ( V_337 . V_211 == NULL ) {
V_3 = - V_74 ;
goto V_347;
} else {
V_1 -> V_210 ( V_336 , V_342 , V_339 ) ;
}
}
} else {
V_1 -> V_210 ( V_336 , V_342 , ( T_14 ) - 1 ) ;
}
F_62 ( V_1 -> V_4 . V_18 , V_16 -> V_19 ) ;
F_19 (ioc->ioctl_cmds.status)
if ( V_16 -> V_17 == V_50 ) {
F_15 ( & V_1 -> V_59 . V_5 ) ;
if ( F_16 ( V_1 ) != 0 ) {
F_17 ( & V_1 -> V_59 . V_5 ) ;
goto V_347;
}
F_84 ( V_1 , ( V_95 * ) V_57 ) ;
if ( ( V_1 -> V_90 . V_91 & V_92 ) &&
( V_1 -> V_90 . V_93 >= V_94 ) )
F_20 ( V_190 , V_1 , V_57 ) ;
else {
V_3 = F_21 ( V_190 , V_1 ,
sizeof( T_3 ) , ( V_95 * ) V_57 , V_96 ) ;
if ( V_3 != 0 ) {
F_22 ( V_1 , F_6 ( V_97
L_119 ,
V_1 -> V_14 , V_1 , V_57 ) ) ;
F_10 ( V_1 ) ;
V_3 = - V_215 ;
F_17 ( & V_1 -> V_59 . V_5 ) ;
goto V_347;
}
}
} else
F_63 ( V_190 , V_1 , V_57 ) ;
V_68 = ( V_248 . V_68 > 0 ) ? V_248 . V_68 : V_406 ;
V_213:
V_189 = F_24 ( & V_1 -> V_4 . V_51 ,
V_98 * V_68 ) ;
if ( ! ( V_1 -> V_4 . V_21 & V_22 ) ) {
V_3 = - V_214 ;
F_22 ( V_1 , F_6 ( V_97 L_120 ,
V_1 -> V_14 , V_110 ) ) ;
if ( V_1 -> V_4 . V_21 & V_99 ) {
if ( V_109 == V_50 )
F_17 ( & V_1 -> V_59 . V_5 ) ;
goto V_347;
}
if ( ! V_189 ) {
F_6 ( V_73
L_121
L_122 ,
V_1 -> V_14 , F_64 ( V_1 , 0 ) , V_109 ) ;
if ( V_109 == V_50 )
F_17 ( & V_1 -> V_59 . V_5 ) ;
F_26 ( V_1 , V_57 ) ;
V_57 = NULL ;
} else
goto V_213;
goto V_347;
}
if ( V_109 == V_50 )
F_17 ( & V_1 -> V_59 . V_5 ) ;
V_57 = NULL ;
if ( V_1 -> V_4 . V_21 & V_24 ) {
if ( V_248 . V_407 < V_1 -> V_25 ) {
V_12 = F_7 ( V_248 . V_407 ,
4 * V_1 -> V_4 . V_9 [ 2 ] ) ;
} else {
V_12 = F_7 ( V_1 -> V_25 , 4 * V_1 -> V_4 . V_9 [ 2 ] ) ;
}
if ( V_12 > 0 ) {
if ( F_77 ( V_248 . V_408 ,
V_1 -> V_4 . V_9 , V_12 ) ) {
F_6 ( V_97
L_102
L_123 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_248 . V_408 ) ;
V_3 = - V_215 ;
goto V_347;
}
}
}
if ( V_1 -> V_4 . V_21 & V_48 ) {
V_12 = F_7 ( V_248 . V_372 , V_373 ) ;
if ( V_12 > 0 ) {
if ( F_77 ( V_248 . V_409 ,
V_1 -> V_4 . V_47 , V_12 ) ) {
F_6 ( V_97 L_102
L_124 ,
V_1 -> V_14 , __FILE__ , __LINE__ ,
V_248 . V_409 ) ;
V_3 = - V_215 ;
goto V_347;
}
}
}
if ( ( V_1 -> V_4 . V_21 & V_22 ) &&
( V_248 . V_345 > 0 ) && ( V_337 . V_211 ) ) {
if ( F_77 ( V_248 . V_410 ,
V_337 . V_211 , V_248 . V_345 ) ) {
F_6 ( V_97 L_102
L_125 ,
V_1 -> V_14 , __FILE__ , __LINE__ ,
V_248 . V_410 ) ;
V_3 = - V_215 ;
}
}
V_347:
F_25 (ioc->ioctl_cmds.status)
F_62 ( V_1 -> V_4 . V_18 , 0 ) ;
if ( V_338 . V_211 != NULL ) {
F_69 ( V_1 -> V_239 ,
V_338 . V_212 , ( void * ) V_338 . V_211 , V_340 ) ;
}
if ( V_337 . V_211 != NULL ) {
F_69 ( V_1 -> V_239 ,
V_337 . V_212 , ( void * ) V_337 . V_211 , V_339 ) ;
}
if ( V_57 )
F_23 ( V_1 , V_57 ) ;
return V_3 ;
}
static int
F_54 ( unsigned long V_136 , unsigned int V_245 )
{
T_21 T_9 * V_247 = ( void T_9 * ) V_136 ;
T_1 * V_1 ;
struct V_249 * V_250 ;
char * V_411 = NULL ;
T_14 V_412 ;
T_21 V_248 ;
T_22 V_413 ;
T_23 V_16 ;
int V_139 ;
int V_3 , V_252 ;
T_24 * V_414 ;
T_2 * V_57 = NULL ;
V_203 * V_415 ;
unsigned long V_189 ;
int V_67 ;
if ( V_245 == sizeof( T_21 ) )
V_252 = 1 ;
else if ( V_245 == sizeof( V_416 ) )
V_252 = 0 ;
else
return - V_144 ;
if ( F_41 ( & V_248 , V_247 , sizeof( T_21 ) ) ) {
F_6 (KERN_ERR MYNAM L_126
L_127 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_128 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_129 ,
V_1 -> V_14 ) ) ;
V_250 = (struct V_249 * ) V_1 -> V_239 ;
V_248 . V_417 = V_250 -> V_417 ;
V_248 . V_265 = V_250 -> V_265 ;
V_248 . V_418 = V_250 -> V_269 ;
V_248 . V_271 = V_250 -> V_271 ;
V_248 . V_278 = V_250 -> V_278 ;
V_248 . V_275 = V_250 -> V_275 -> V_276 ;
if ( V_1 -> V_282 != NULL )
V_248 . V_419 = V_1 -> V_282 -> V_419 ;
else
V_248 . V_419 = - 1 ;
V_248 . V_420 [ 0 ] = V_1 -> V_90 . V_287 . Struct . V_421 >= 10 ?
( ( V_1 -> V_90 . V_287 . Struct . V_421 / 10 ) + '0' ) : '0' ;
V_248 . V_420 [ 1 ] = ( V_1 -> V_90 . V_287 . Struct . V_421 % 10 ) + '0' ;
V_248 . V_420 [ 2 ] = '.' ;
V_248 . V_420 [ 3 ] = V_1 -> V_90 . V_287 . Struct . V_422 >= 10 ?
( ( V_1 -> V_90 . V_287 . Struct . V_422 / 10 ) + '0' ) : '0' ;
V_248 . V_420 [ 4 ] = ( V_1 -> V_90 . V_287 . Struct . V_422 % 10 ) + '0' ;
V_248 . V_420 [ 5 ] = '.' ;
V_248 . V_420 [ 6 ] = V_1 -> V_90 . V_287 . Struct . V_423 >= 10 ?
( ( V_1 -> V_90 . V_287 . Struct . V_423 / 10 ) + '0' ) : '0' ;
V_248 . V_420 [ 7 ] = ( V_1 -> V_90 . V_287 . Struct . V_423 % 10 ) + '0' ;
V_248 . V_420 [ 8 ] = '.' ;
V_248 . V_420 [ 9 ] = V_1 -> V_90 . V_287 . Struct . V_424 >= 10 ?
( ( V_1 -> V_90 . V_287 . Struct . V_424 / 10 ) + '0' ) : '0' ;
V_248 . V_420 [ 10 ] = ( V_1 -> V_90 . V_287 . Struct . V_424 % 10 ) + '0' ;
V_248 . V_420 [ 11 ] = '\0' ;
V_16 . V_425 = 0 ;
V_16 . V_426 = 0 ;
V_16 . V_355 = 0 ;
V_16 . V_353 = V_427 ;
V_413 . V_428 . V_16 = & V_16 ;
V_413 . V_429 = - 1 ;
V_413 . V_430 = 0 ;
V_413 . V_431 = V_432 ;
V_413 . V_236 = 0 ;
V_413 . V_68 = 10 ;
strncpy ( V_248 . V_433 , L_130 , 24 ) ;
if ( F_85 ( V_1 , & V_413 ) == 0 ) {
if ( V_413 . V_428 . V_16 -> V_426 > 0 ) {
V_413 . V_431 = V_434 ;
V_411 = F_67 ( V_1 -> V_239 , V_16 . V_426 * 4 , & V_412 ) ;
if ( V_411 ) {
V_413 . V_429 = V_412 ;
if ( F_85 ( V_1 , & V_413 ) == 0 ) {
T_25 * V_301 = ( T_25 * ) V_411 ;
if ( strlen ( V_301 -> V_435 ) > 1 ) {
strncpy ( V_248 . V_433 , V_301 -> V_435 , 24 ) ;
V_248 . V_433 [ 24 - 1 ] = '\0' ;
}
}
F_69 ( V_1 -> V_239 , V_16 . V_426 * 4 , V_411 , V_412 ) ;
V_411 = NULL ;
}
}
}
V_3 = F_64 ( V_1 , 1 ) ;
switch ( V_3 ) {
case V_436 :
V_248 . V_437 = V_438 ;
break;
case V_439 :
V_248 . V_437 = V_440 ;
break;
case V_441 :
case V_442 :
default:
V_248 . V_437 = V_443 ;
break;
}
V_248 . V_444 = F_86 ( V_250 , 0 ) ;
if ( ( V_1 -> V_52 == V_53 ) || ( V_1 -> V_52 == V_78 ) )
V_248 . V_445 = V_446 ;
else
V_248 . V_445 = V_447 ;
V_248 . V_448 = 0 ;
V_248 . V_449 = 0 ;
V_248 . V_450 = 0 ;
if ( V_1 -> V_282 != NULL ) {
T_26 * V_451 = F_87 ( V_1 -> V_282 ) ;
if ( V_451 && ( V_252 == 1 ) ) {
V_248 . V_448 = V_1 -> V_448 ;
V_248 . V_449 = V_1 -> V_449 ;
V_248 . V_450 = V_1 -> V_450 ;
}
}
if ( ( V_57 = F_18 ( V_190 , V_1 ) ) == NULL ) {
F_22 ( V_1 , F_6 ( V_73
L_131 , V_1 -> V_14 , V_110 ) ) ;
goto V_23;
}
V_414 = ( T_24 * ) V_57 ;
V_415 = ( V_203 * ) V_57 ;
memset ( V_414 , 0 , sizeof( T_24 ) ) ;
V_414 -> V_17 = V_362 ;
V_414 -> V_452 = V_453 ;
V_414 -> V_19 = V_415 -> V_19 ;
V_414 -> V_198 = V_454 ;
V_414 -> V_455 = 0x01 ;
V_414 -> V_383 = F_83 ( 0x04 ) ;
if ( V_250 -> V_278 & 1 )
V_414 -> V_456 = 0xB2 ;
else
V_414 -> V_456 = 0xB0 ;
V_411 = F_67 ( V_1 -> V_239 , 4 , & V_412 ) ;
if ( ! V_411 )
goto V_23;
V_1 -> V_210 ( ( char * ) & V_414 -> V_191 ,
( V_405 | 4 ) , V_412 ) ;
V_67 = 0 ;
F_62 ( V_1 -> V_4 . V_18 ,
V_414 -> V_19 ) ;
F_19 (ioc->ioctl_cmds.status)
F_63 ( V_190 , V_1 , V_57 ) ;
V_213:
V_189 = F_24 ( & V_1 -> V_4 . V_51 ,
V_98 * V_406 ) ;
if ( ! ( V_1 -> V_4 . V_21 & V_22 ) ) {
V_67 = - V_214 ;
F_6 ( V_73 L_40 , V_1 -> V_14 , V_110 ) ;
if ( V_1 -> V_4 . V_21 & V_99 ) {
F_23 ( V_1 , V_57 ) ;
goto V_23;
}
if ( ! V_189 ) {
F_6 ( V_73
L_132 ,
V_1 -> V_14 , F_64 ( V_1 , 0 ) ) ;
F_26 ( V_1 , V_57 ) ;
} else
goto V_213;
goto V_23;
}
if ( V_1 -> V_4 . V_21 & V_24 )
V_248 . V_298 = * ( V_95 * ) V_411 ;
V_23:
F_25 (ioc->ioctl_cmds.status)
F_62 ( V_1 -> V_4 . V_18 , 0 ) ;
if ( V_411 )
F_69 ( V_1 -> V_239 , 4 , V_411 , V_412 ) ;
if ( F_77 ( ( char T_9 * ) V_136 , & V_248 , sizeof( T_21 ) ) ) {
F_6 ( V_97 L_133
L_134 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
return - V_144 ;
}
return 0 ;
}
static int
F_55 ( unsigned long V_136 )
{
T_27 T_9 * V_247 = ( void T_9 * ) V_136 ;
T_28 * V_457 ;
T_29 * V_458 ;
T_1 * V_1 ;
T_26 * V_451 = NULL ;
T_27 V_248 ;
int V_139 ;
int V_459 ;
T_14 V_460 ;
T_22 V_413 ;
T_23 V_16 ;
int V_461 , V_462 , V_3 = 0 ;
if ( F_41 ( & V_248 , V_247 , sizeof( T_27 ) ) ) {
F_6 (KERN_ERR MYNAM L_135
L_136 ,
__FILE__, __LINE__, uarg) ;
return - V_144 ;
}
if ( ( ( V_139 = F_42 ( V_248 . V_16 . V_139 , & V_1 ) ) < 0 ) ||
( V_1 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_137 ,
__FILE__, __LINE__, iocnum) ;
return - V_146 ;
}
F_5 ( V_1 , F_6 ( V_13 L_138 ,
V_1 -> V_14 ) ) ;
if ( ( V_1 -> V_52 == V_53 ) || ( V_1 -> V_52 == V_78 ) )
return 0 ;
if ( ( V_1 -> V_463 . V_464 == 0 ) || ( V_1 -> V_282 == NULL ) )
return 0 ;
if ( V_1 -> V_282 -> V_419 != V_248 . V_16 . V_465 )
return - V_146 ;
V_459 = V_1 -> V_463 . V_464 * 4 ;
V_457 = ( T_28 * ) F_67 ( V_1 -> V_239 , V_459 , & V_460 ) ;
if ( V_457 ) {
V_16 . V_425 = V_1 -> V_463 . V_466 ;
V_16 . V_426 = V_459 ;
V_16 . V_355 = 0 ;
V_16 . V_353 = V_467 ;
V_413 . V_428 . V_16 = & V_16 ;
V_413 . V_431 = V_434 ;
V_413 . V_236 = 0 ;
V_413 . V_68 = 0 ;
V_413 . V_429 = V_460 ;
V_413 . V_430 = ( V_248 . V_16 . V_306 << 8 ) | V_248 . V_16 . V_307 ;
if ( ( V_3 = F_85 ( V_1 , & V_413 ) ) == 0 ) {
V_462 = F_9 ( V_457 -> V_468 ) ;
V_248 . V_469 = V_462 & V_470 ?
V_447 : V_471 ;
if ( V_462 & V_472 ) {
V_461 = ( V_462 & V_473 ) >> 8 ;
if ( V_461 < 0x09 )
V_248 . V_474 = V_475 ;
else if ( V_461 <= 0x09 )
V_248 . V_474 = V_476 ;
else if ( V_461 <= 0x0A )
V_248 . V_474 = V_477 ;
else if ( V_461 <= 0x0C )
V_248 . V_474 = V_478 ;
else if ( V_461 <= 0x25 )
V_248 . V_474 = V_479 ;
else
V_248 . V_474 = V_480 ;
} else
V_248 . V_474 = V_480 ;
}
F_69 ( V_1 -> V_239 , V_459 , ( V_44 * ) V_457 , V_460 ) ;
}
V_248 . V_481 = - 1 ;
V_248 . V_482 = - 1 ;
V_248 . V_483 = - 1 ;
V_248 . V_484 = - 1 ;
V_16 . V_425 = 0 ;
V_16 . V_426 = 0 ;
V_16 . V_355 = 3 ;
V_16 . V_353 = V_467 ;
V_413 . V_428 . V_16 = & V_16 ;
V_413 . V_431 = V_432 ;
V_413 . V_236 = 0 ;
V_413 . V_68 = 0 ;
V_413 . V_429 = - 1 ;
if ( ( F_85 ( V_1 , & V_413 ) == 0 ) && ( V_413 . V_428 . V_16 -> V_426 > 0 ) ) {
V_413 . V_431 = V_434 ;
V_459 = ( int ) V_413 . V_428 . V_16 -> V_426 * 4 ;
V_458 = ( T_29 * ) F_67 (
V_1 -> V_239 , V_459 , & V_460 ) ;
if ( V_458 ) {
V_413 . V_429 = V_460 ;
V_413 . V_430 = ( V_248 . V_16 . V_306 << 8 ) | V_248 . V_16 . V_307 ;
if ( ( V_3 = F_85 ( V_1 , & V_413 ) ) == 0 ) {
V_248 . V_481 = ( V_95 ) F_8 ( V_458 -> V_485 ) ;
V_248 . V_482 = ( V_95 ) F_8 ( V_458 -> V_486 ) ;
V_248 . V_483 = ( V_95 ) F_8 ( V_458 -> V_487 ) ;
}
F_69 ( V_1 -> V_239 , V_459 , ( V_44 * ) V_458 , V_460 ) ;
}
}
V_451 = F_87 ( V_1 -> V_282 ) ;
if ( V_451 != NULL )
V_248 . V_484 = V_451 -> V_488 [ V_248 . V_16 . V_307 ] ;
if ( F_77 ( ( char T_9 * ) V_136 , & V_248 , sizeof( T_27 ) ) ) {
F_6 ( V_97 L_139
L_71 ,
V_1 -> V_14 , __FILE__ , __LINE__ , V_247 ) ;
return - V_144 ;
}
return 0 ;
}
static int
F_88 ( struct V_129 * V_489 , unsigned int V_135 ,
unsigned long V_136 )
{
struct V_490 V_491 ;
struct V_165 V_492 ;
T_1 * V_143 = NULL ;
int V_139 , V_140 ;
int V_2 = ( V_489 -> V_141 & V_142 ) ;
int V_133 ;
if ( F_41 ( & V_491 , ( char T_9 * ) V_136 , sizeof( V_491 ) ) )
return - V_144 ;
V_140 = V_491 . V_139 & 0xFF ;
if ( ( ( V_139 = F_42 ( V_140 , & V_143 ) ) < 0 ) ||
( V_143 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_140 ,
__LINE__, iocnumX) ;
return - V_146 ;
}
if ( ( V_133 = F_1 ( V_143 , V_2 ) ) != 0 )
return V_133 ;
F_5 ( V_143 , F_6 ( V_13 L_141 ,
V_143 -> V_14 ) ) ;
V_492 . V_139 = V_139 ;
V_492 . V_169 = V_491 . V_169 ;
V_492 . V_168 = F_89 ( V_491 . V_168 ) ;
V_133 = F_58 ( V_492 . V_139 , V_492 . V_168 , V_492 . V_169 ) ;
F_17 ( & V_143 -> V_4 . V_5 ) ;
return V_133 ;
}
static int
F_90 ( struct V_129 * V_489 , unsigned int V_135 ,
unsigned long V_136 )
{
struct V_493 V_494 ;
struct V_493 T_9 * V_247 = (struct V_493 T_9 * ) V_136 ;
struct V_333 V_248 ;
T_1 * V_143 = NULL ;
int V_139 , V_140 ;
int V_2 = ( V_489 -> V_141 & V_142 ) ;
int V_133 ;
if ( F_41 ( & V_494 , ( char T_9 * ) V_136 , sizeof( V_494 ) ) )
return - V_144 ;
V_140 = V_494 . V_16 . V_139 & 0xFF ;
if ( ( ( V_139 = F_42 ( V_140 , & V_143 ) ) < 0 ) ||
( V_143 == NULL ) ) {
F_6 (KERN_DEBUG MYNAM L_142 ,
__LINE__, iocnumX) ;
return - V_146 ;
}
if ( ( V_133 = F_1 ( V_143 , V_2 ) ) != 0 )
return V_133 ;
F_5 ( V_143 , F_6 ( V_13 L_143 ,
V_143 -> V_14 ) ) ;
V_248 . V_16 . V_139 = V_494 . V_16 . V_139 ;
V_248 . V_16 . V_251 = V_494 . V_16 . V_251 ;
V_248 . V_68 = V_494 . V_68 ;
V_248 . V_407 = V_494 . V_407 ;
V_248 . V_345 = V_494 . V_345 ;
V_248 . V_346 = V_494 . V_346 ;
V_248 . V_372 = V_494 . V_372 ;
V_248 . V_344 = V_494 . V_344 ;
V_248 . V_408 = ( char T_9 * ) ( unsigned long ) V_494 . V_408 ;
V_248 . V_410 = ( char T_9 * ) ( unsigned long ) V_494 . V_410 ;
V_248 . V_404 = ( char T_9 * ) ( unsigned long ) V_494 . V_404 ;
V_248 . V_409 = ( char T_9 * ) ( unsigned long ) V_494 . V_409 ;
V_133 = F_81 ( V_248 , & V_247 -> V_334 ) ;
F_17 ( & V_143 -> V_4 . V_5 ) ;
return V_133 ;
}
static long F_91 ( struct V_129 * V_495 , unsigned int V_135 , unsigned long V_136 )
{
long V_133 ;
F_15 ( & V_134 ) ;
switch ( V_135 ) {
case V_149 :
case V_496 :
case V_497 :
case V_150 :
case V_152 :
case V_153 :
case V_154 :
case V_158 :
case V_159 :
case V_160 :
case V_151 :
V_133 = F_40 ( V_495 , V_135 , V_136 ) ;
break;
case V_498 :
V_133 = F_90 ( V_495 , V_135 , V_136 ) ;
break;
case V_499 :
V_133 = F_88 ( V_495 , V_135 , V_136 ) ;
break;
default:
V_133 = - V_500 ;
break;
}
F_17 ( & V_134 ) ;
return V_133 ;
}
static int
F_92 ( struct V_249 * V_250 , const struct V_501 * V_307 )
{
T_1 * V_1 = F_93 ( V_250 ) ;
F_94 ( & V_1 -> V_4 . V_5 ) ;
F_95 ( & V_1 -> V_4 . V_51 ) ;
return 0 ;
}
static void
F_96 ( struct V_249 * V_250 )
{
}
static int T_30 F_97 ( void )
{
int V_502 ;
int V_503 = 1 ;
F_98 ( V_504 , V_505 ) ;
F_99 ( & V_506 , V_507 ) ;
V_502 = F_100 ( & V_508 ) ;
if ( V_502 < 0 ) {
F_6 (KERN_ERR MYNAM L_144 , MPT_MINOR) ;
goto V_509;
}
F_6 (KERN_INFO MYNAM L_145 ) ;
F_6 (KERN_INFO MYNAM L_146 ,
mptctl_miscdev.name, MISC_MAJOR, mptctl_miscdev.minor) ;
++ V_503 ;
V_190 = F_101 ( F_4 , V_507 ,
L_147 ) ;
if ( ! V_190 || V_190 >= V_510 ) {
F_6 (KERN_ERR MYNAM L_148 ) ;
F_102 ( & V_508 ) ;
V_502 = - V_220 ;
goto V_509;
}
V_72 = F_101 ( F_12 , V_507 ,
L_149 ) ;
if ( ! V_72 || V_72 >= V_510 ) {
F_6 (KERN_ERR MYNAM L_148 ) ;
F_103 ( V_190 ) ;
F_102 ( & V_508 ) ;
V_502 = - V_220 ;
goto V_509;
}
F_104 ( V_190 , F_32 ) ;
F_105 ( V_190 , F_33 ) ;
return 0 ;
V_509:
F_106 ( V_507 ) ;
return V_502 ;
}
static void F_107 ( void )
{
F_102 ( & V_508 ) ;
F_6 (KERN_INFO MYNAM L_150 ,
mptctl_miscdev.name, MISC_MAJOR, mptctl_miscdev.minor) ;
F_108 ( V_190 ) ;
F_109 ( V_190 ) ;
F_103 ( V_72 ) ;
F_103 ( V_190 ) ;
F_106 ( V_507 ) ;
}
