static int F_1 ( T_1 * V_1 )
{
return 0 ;
}
static struct V_2 * F_2 ( T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
return & ( V_3 -> V_5 ) ;
}
static int F_3 ( T_1 * V_1 )
{
int V_6 = 0 ;
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_7 != V_8 )
return - V_9 ;
if ( V_3 -> V_10 != NULL ) {
V_6 = V_3 -> V_10 ( V_3 ) ;
if ( V_6 == 0 ) {
F_4 ( V_3 -> V_1 ) ;
V_3 -> V_11 = V_12 ;
}
} else {
V_6 = - V_13 ;
}
return V_6 ;
}
static int F_5 ( T_1 * V_1 )
{
int V_6 = 0 ;
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_14 != NULL )
V_6 = V_3 -> V_14 ( V_3 ) ;
F_6 ( V_3 -> V_1 ) ;
V_3 -> V_11 = V_15 ;
return V_6 ;
}
void F_7 ( T_2 * V_3 , struct V_16 * V_17 )
{
F_8 ( & V_3 -> V_18 , V_17 ) ;
F_9 ( & V_3 -> V_19 ) ;
}
static void F_10 ( unsigned long V_20 )
{
T_2 * V_3 = ( T_2 * ) V_20 ;
struct V_16 * V_17 = NULL ;
T_1 * V_21 = V_3 -> V_1 ;
struct V_22 * V_23 ;
while ( ( V_17 = F_11 ( & V_3 -> V_18 ) ) ) {
if ( V_3 -> V_11 == V_12 ) {
if ( V_21 -> type != V_24 ) {
V_17 -> V_21 = V_21 ;
F_12 ( V_17 ) ;
V_17 -> V_25 = V_26 ;
V_17 -> V_27 = V_28 ;
V_17 -> V_29 = F_13 ( V_30 ) ;
V_21 -> V_31 = V_32 ;
V_3 -> V_5 . V_33 ++ ;
V_3 -> V_5 . V_34 += V_17 -> V_35 ;
F_14 ( V_17 ) ;
continue;
} else {
V_23 = (struct V_22 * ) V_17 -> V_36 ;
if ( F_15 ( V_3 , V_23 -> V_37 ) ) {
F_16 ( V_17 ) ;
continue;
}
if ( V_3 -> V_1 -> V_38 & V_39 ) {
if ( memcmp
( V_23 -> V_40 , V_3 -> V_1 -> V_41 ,
V_42 ) != 0 ) {
if ( ! ( V_23 -> V_40 [ 0 ] & 0x01 ) ) {
F_16 ( V_17 ) ;
continue;
}
}
}
if ( F_17
( V_3 , V_3 -> V_43 , V_17 ) == 0 ) {
V_17 -> V_21 -> V_31 = V_32 ;
V_3 -> V_5 . V_33 ++ ;
V_3 -> V_5 . V_34 +=
V_17 -> V_35 ;
F_14 ( V_17 ) ;
continue;
}
F_18 ( L_1 ) ;
}
}
F_16 ( V_17 ) ;
}
}
static int F_19 ( struct V_16 * V_17 ,
T_1 * V_1 )
{
int V_6 = 0 ;
int V_44 = - 1 ;
T_2 * V_3 = V_1 -> V_4 ;
union V_45 V_45 ;
struct V_46 V_47 ;
V_47 . V_36 = NULL ;
if ( V_17 == NULL )
return V_48 ;
if ( V_3 -> V_11 != V_12 ) {
V_6 = 1 ;
goto V_49;
}
memset ( & V_45 , 0 , sizeof( union V_45 ) ) ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
if ( F_20 ( V_1 ) ) {
F_18 ( L_2 ) ;
V_6 = 1 ;
goto V_49;
}
F_6 ( V_1 ) ;
switch ( V_3 -> V_50 ) {
case V_51 :
case V_52 :
case V_53 :
break;
default:
if ( V_17 -> V_29 != V_30 ) {
F_4 ( V_3 -> V_1 ) ;
F_21 ( V_54
L_3 ) ;
V_3 -> V_5 . V_55 ++ ;
V_6 = 0 ;
goto V_49;
}
break;
}
if ( V_17 -> V_29 == V_30 ) {
if ( ! F_22 ( V_56 ) ) {
V_6 = 1 ;
goto V_49;
}
memcpy ( & V_45 , V_17 -> V_36 , sizeof( union V_45 ) ) ;
F_23 ( V_17 , sizeof( union V_45 ) ) ;
} else {
if ( F_24
( V_3 , V_3 -> V_43 , V_17 , & V_45 ,
& V_47 ) != 0 ) {
F_18 ( L_4 ,
V_3 -> V_43 ) ;
V_6 = 1 ;
goto V_49;
}
}
if ( V_3 -> V_57 == NULL ) {
V_6 = 1 ;
goto V_49;
}
V_1 -> V_58 = V_32 ;
V_3 -> V_5 . V_59 ++ ;
V_3 -> V_5 . V_60 += V_17 -> V_35 ;
V_44 = V_3 -> V_57 ( V_3 , V_17 , & V_45 , & V_47 ) ;
if ( V_44 == 0 ) {
F_25 ( V_3 -> V_1 ) ;
V_6 = V_48 ;
} else if ( V_44 == 1 ) {
F_18 ( L_5 ) ;
V_6 = V_48 ;
} else if ( V_44 == 2 ) {
F_18 ( L_6 ) ;
V_6 = V_61 ;
} else {
F_18 ( L_7 ) ;
V_6 = V_61 ;
}
V_49:
if ( ( V_47 . V_36 ) && ( V_47 . V_36 != V_17 -> V_36 ) )
F_26 ( V_47 . V_36 ) ;
if ( ! V_6 )
F_16 ( V_17 ) ;
return V_6 ;
}
static void F_27 ( T_1 * V_21 )
{
T_2 * V_3 = V_21 -> V_4 ;
if ( V_3 -> V_62 )
V_3 -> V_62 ( V_3 , V_21 ) ;
}
static int F_28 ( T_2 * V_3 , void T_3 * V_63 )
{
T_4 V_64 ;
struct V_65 V_66 ;
struct V_67 V_68 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( F_29 ( & V_64 , V_63 , sizeof( V_64 ) ) )
return - V_69 ;
switch ( V_64 ) {
case V_70 :
V_66 . V_71 = V_64 ;
snprintf ( V_66 . V_72 , sizeof( V_66 . V_72 ) , L_8 ,
V_3 -> V_73 ) ;
snprintf ( V_66 . V_74 , sizeof( V_66 . V_74 ) , L_9 ,
V_75 ) ;
if ( F_30 ( V_63 , & V_66 , sizeof( V_66 ) ) )
return - V_69 ;
return 0 ;
#ifdef F_31
case F_31 :
V_68 . V_71 = V_64 ;
if ( V_3 -> V_76 &&
( V_3 -> V_50 != V_77 ) ) {
V_68 . V_36 = 1 ;
} else {
V_68 . V_36 = 0 ;
}
if ( F_30 ( V_63 , & V_68 , sizeof( V_68 ) ) )
return - V_69 ;
return 0 ;
#endif
}
return - V_78 ;
}
static int F_32 ( T_1 * V_21 , struct V_79 * V_80 , int V_71 )
{
int V_6 = 0 ;
struct V_81 * V_82 = (struct V_81 * ) V_80 ;
T_2 * V_3 = V_21 -> V_4 ;
T_5 * V_83 ;
F_18 ( L_10 , V_71 , V_82 -> V_35 ) ;
#ifdef F_33
if ( V_71 == F_33 ) {
V_6 =
F_28 ( V_3 , ( void T_3 * ) V_80 -> V_84 ) ;
goto V_85;
}
#endif
if ( V_82 -> V_86 != V_87 ) {
V_6 = - V_88 ;
goto V_85;
}
if ( V_71 == V_89 ) {
V_6 = 0 ;
goto V_85;
} else if ( V_71 != V_90 ) {
V_6 = - V_88 ;
goto V_85;
}
V_83 = F_34 ( V_82 -> V_35 , V_91 ) ;
if ( V_83 ) {
if ( F_29 ( V_83 , ( void T_3 * ) V_82 -> V_36 , V_82 -> V_35 ) )
V_6 = - V_69 ;
else
V_6 = F_35 ( V_3 , V_83 ) ;
if ( V_6 == 0 ) {
if ( F_30
( ( void T_3 * ) V_82 -> V_36 , V_83 , V_82 -> V_35 ) ) {
V_6 = - V_69 ;
}
}
F_36 ( V_83 ) ;
} else {
V_6 = - V_92 ;
}
V_85:
return V_6 ;
}
static int F_37 ( T_1 * V_21 , void * V_93 )
{
struct V_94 * V_95 = V_93 ;
struct V_96 V_97 ;
T_6 * V_98 ;
T_7 * V_99 ;
T_8 * V_100 ;
int V_6 ;
if ( F_38 ( V_21 ) )
return - V_101 ;
V_98 = & V_97 . V_102 ;
V_99 = ( T_7 * ) & V_98 -> V_36 ;
V_100 = & V_97 . V_100 ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
V_97 . V_103 = V_104 ;
V_97 . V_105 = sizeof( struct V_96 ) ;
memcpy ( V_97 . V_106 ,
( ( T_2 * ) V_21 -> V_4 ) -> V_107 , V_108 - 1 ) ;
V_98 -> V_109 = V_110 ;
V_98 -> V_111 = V_112 ;
V_98 -> V_35 = sizeof( V_98 -> V_36 ) ;
V_99 -> V_109 = V_113 ;
V_99 -> V_111 = V_112 ;
V_99 -> V_35 = sizeof( V_99 -> V_36 ) ;
V_99 -> V_36 . V_35 = V_42 ;
memcpy ( & V_99 -> V_36 . V_36 , V_95 -> V_114 , V_42 ) ;
V_100 -> V_109 = V_115 ;
V_100 -> V_111 = V_116 ;
V_100 -> V_35 = sizeof( V_100 -> V_36 ) ;
V_100 -> V_36 = 0 ;
V_6 = F_35 ( V_21 -> V_4 , ( T_5 * ) & V_97 ) ;
if ( V_6 != 0 || V_100 -> V_36 != V_117 ) {
F_21 ( V_118
L_11 ) ;
V_6 = - V_119 ;
} else {
memcpy ( V_21 -> V_41 , V_95 -> V_114 , V_21 -> V_120 ) ;
}
return V_6 ;
}
static int F_39 ( T_1 * V_21 , int V_121 )
{
if ( ( V_121 < 68 ) || ( V_121 > ( 2312 - 20 - 8 ) ) )
return - V_122 ;
V_21 -> V_123 = V_121 ;
return 0 ;
}
int F_40 ( T_2 * V_3 , struct V_124 * V_125 )
{
int V_6 = 0 ;
T_1 * V_1 ;
struct V_126 * V_126 ;
struct V_127 * V_128 ;
V_3 -> V_11 = V_15 ;
V_3 -> V_43 = V_129 ;
V_3 -> V_50 = V_77 ;
F_41 ( & V_3 -> V_18 ) ;
F_42 ( & V_3 -> V_19 ,
F_10 , ( unsigned long ) V_3 ) ;
V_126 = F_43 ( V_125 , V_3 ) ;
if ( V_126 == NULL ) {
F_21 ( V_118 L_12 ) ;
return 1 ;
}
V_1 = F_44 ( sizeof( struct V_127 ) , L_13 ,
V_130 ) ;
if ( V_1 == NULL ) {
F_21 ( V_118 L_14 ) ;
F_45 ( V_126 ) ;
V_6 = 1 ;
} else {
V_3 -> V_1 = V_1 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_131 = & V_132 ;
V_128 = F_46 ( V_1 ) ;
V_128 -> V_126 = V_126 ;
V_128 -> V_133 = V_134 ;
V_1 -> V_135 = V_128 ;
F_6 ( V_1 ) ;
F_47 ( V_1 ) ;
}
return V_6 ;
}
void F_48 ( T_2 * V_3 )
{
struct V_127 * V_128 ;
F_49 ( & V_3 -> V_19 ) ;
if ( V_3 -> V_1 ) {
V_128 = F_46 ( V_3 -> V_1 ) ;
if ( V_128 -> V_126 )
F_45 ( V_128 -> V_126 ) ;
F_50 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
}
}
int F_51 ( T_2 * V_3 )
{
return F_52 ( V_3 -> V_1 ) ;
}
int F_53 ( T_2 * V_3 )
{
struct V_16 * V_17 ;
F_54 ( V_3 -> V_1 ) ;
while ( ( V_17 = F_11 ( & V_3 -> V_18 ) ) )
F_16 ( V_17 ) ;
return 0 ;
}
void F_55 ( T_2 * V_3 )
{
V_3 -> V_136 = 1 ;
if ( V_3 -> V_11 == V_12 )
F_6 ( V_3 -> V_1 ) ;
F_56 ( V_3 -> V_1 ) ;
}
static int F_15 ( T_2 * V_3 , T_9 V_37 )
{
T_9 V_137 ;
T_9 V_138 ;
int V_139 = 0 ;
V_137 = F_57 ( V_37 ) ;
V_138 = F_58 ( V_37 ) ;
#if 0
pr_debug("rx_typedrop : ftype=%d fstype=%d.\n", ftype, fstype);
#endif
switch ( V_137 ) {
case V_140 :
if ( ( V_3 -> V_1 -> V_38 & V_141 ) ||
( V_3 -> V_1 -> V_38 & V_39 ) ) {
V_139 = 1 ;
break;
}
F_18 ( L_15 ) ;
V_3 -> V_142 . V_143 ++ ;
switch ( V_138 ) {
case V_144 :
V_3 -> V_142 . V_145 ++ ;
break;
case V_146 :
V_3 -> V_142 . V_147 ++ ;
break;
case V_148 :
V_3 -> V_142 . V_149 ++ ;
break;
case V_150 :
V_3 -> V_142 . V_151 ++ ;
break;
case V_152 :
V_3 -> V_142 . V_153 ++ ;
break;
case V_154 :
V_3 -> V_142 . V_155 ++ ;
break;
case V_156 :
V_3 -> V_142 . V_157 ++ ;
break;
case V_158 :
V_3 -> V_142 . V_159 ++ ;
break;
case V_160 :
V_3 -> V_142 . V_161 ++ ;
break;
case V_162 :
V_3 -> V_142 . V_163 ++ ;
break;
case V_164 :
V_3 -> V_142 . V_165 ++ ;
break;
default:
V_3 -> V_142 . V_166 ++ ;
break;
}
V_139 = 2 ;
break;
case V_167 :
if ( ( V_3 -> V_1 -> V_38 & V_141 ) ||
( V_3 -> V_1 -> V_38 & V_39 ) ) {
V_139 = 1 ;
break;
}
F_18 ( L_16 ) ;
V_3 -> V_142 . V_168 ++ ;
switch ( V_138 ) {
case V_169 :
V_3 -> V_142 . V_170 ++ ;
break;
case V_171 :
V_3 -> V_142 . V_172 ++ ;
break;
case V_173 :
V_3 -> V_142 . V_174 ++ ;
break;
case V_175 :
V_3 -> V_142 . V_176 ++ ;
break;
case V_177 :
V_3 -> V_142 . V_178 ++ ;
break;
case V_179 :
V_3 -> V_142 . V_180 ++ ;
break;
default:
V_3 -> V_142 . V_181 ++ ;
break;
}
V_139 = 2 ;
break;
case V_182 :
V_3 -> V_142 . V_36 ++ ;
switch ( V_138 ) {
case V_183 :
V_3 -> V_142 . V_184 ++ ;
break;
case V_185 :
V_3 -> V_142 . V_186 ++ ;
break;
case V_187 :
V_3 -> V_142 . V_188 ++ ;
break;
case V_189 :
V_3 -> V_142 . V_190 ++ ;
break;
case V_191 :
F_18 ( L_17 ) ;
V_3 -> V_142 . null ++ ;
break;
case V_192 :
F_18 ( L_18 ) ;
V_3 -> V_142 . V_193 ++ ;
break;
case V_194 :
F_18 ( L_19 ) ;
V_3 -> V_142 . V_195 ++ ;
break;
case V_196 :
F_18 ( L_20 ) ;
V_3 -> V_142 . V_197 ++ ;
break;
default:
V_3 -> V_142 . V_198 ++ ;
break;
}
break;
}
return V_139 ;
}
static void F_59 ( T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_199 ) {
V_3 -> V_199 ( V_3 ) ;
} else {
F_21 ( V_200 L_21 ,
V_3 -> V_73 ) ;
F_25 ( V_3 -> V_1 ) ;
}
}
