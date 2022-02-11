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
return;
}
static void F_10 ( unsigned long V_20 )
{
T_2 * V_3 = ( T_2 * ) V_20 ;
struct V_16 * V_17 = NULL ;
T_1 * V_21 = V_3 -> V_1 ;
struct V_22 * V_23 ;
T_3 V_24 ;
while ( ( V_17 = F_11 ( & V_3 -> V_18 ) ) ) {
if ( V_3 -> V_11 == V_12 ) {
if ( V_21 -> type != V_25 ) {
V_17 -> V_21 = V_21 ;
F_12 ( V_17 ) ;
V_17 -> V_26 = V_27 ;
V_17 -> V_28 = V_29 ;
V_17 -> V_30 = F_13 ( V_31 ) ;
V_21 -> V_32 = V_33 ;
V_3 -> V_5 . V_34 ++ ;
V_3 -> V_5 . V_35 += V_17 -> V_36 ;
F_14 ( V_17 ) ;
continue;
} else {
V_23 = (struct V_22 * ) V_17 -> V_37 ;
V_24 = F_15 ( V_23 -> V_24 ) ;
if ( F_16 ( V_3 , V_24 ) ) {
F_17 ( V_17 ) ;
continue;
}
if ( V_3 -> V_1 -> V_38 & V_39 ) {
if ( memcmp
( V_23 -> V_40 , V_3 -> V_1 -> V_41 ,
V_42 ) != 0 ) {
if ( ! ( V_23 -> V_40 [ 0 ] & 0x01 ) ) {
F_17 ( V_17 ) ;
continue;
}
}
}
if ( F_18
( V_3 , V_3 -> V_43 , V_17 ) == 0 ) {
V_17 -> V_21 -> V_32 = V_33 ;
V_3 -> V_5 . V_34 ++ ;
V_3 -> V_5 . V_35 +=
V_17 -> V_36 ;
F_14 ( V_17 ) ;
continue;
}
F_19 ( L_1 ) ;
}
}
F_17 ( V_17 ) ;
}
}
static int F_20 ( struct V_16 * V_17 ,
T_1 * V_1 )
{
int V_6 = 0 ;
int V_44 = - 1 ;
T_2 * V_3 = V_1 -> V_4 ;
union V_45 V_45 ;
struct V_46 V_47 ;
if ( V_17 == NULL )
return V_48 ;
if ( V_3 -> V_11 != V_12 ) {
V_6 = 1 ;
goto V_49;
}
memset ( & V_45 , 0 , sizeof( union V_45 ) ) ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
if ( F_21 ( V_1 ) ) {
F_19 ( L_2 ) ;
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
if ( V_17 -> V_30 != V_31 ) {
F_4 ( V_3 -> V_1 ) ;
F_22 ( V_54
L_3 ) ;
V_3 -> V_5 . V_55 ++ ;
V_6 = 0 ;
goto V_49;
}
break;
}
if ( V_17 -> V_30 == V_31 ) {
if ( ! F_23 ( V_56 ) ) {
V_6 = 1 ;
goto V_49;
}
memcpy ( & V_45 , V_17 -> V_37 , sizeof( union V_45 ) ) ;
F_24 ( V_17 , sizeof( union V_45 ) ) ;
} else {
if ( F_25
( V_3 , V_3 -> V_43 , V_17 , & V_45 ,
& V_47 ) != 0 ) {
F_19 ( L_4 ,
V_3 -> V_43 ) ;
V_6 = 1 ;
goto V_49;
}
}
if ( V_3 -> V_57 == NULL ) {
V_6 = 1 ;
goto V_49;
}
V_1 -> V_58 = V_33 ;
V_3 -> V_5 . V_59 ++ ;
V_3 -> V_5 . V_60 += V_17 -> V_36 ;
V_44 = V_3 -> V_57 ( V_3 , V_17 , & V_45 , & V_47 ) ;
if ( V_44 == 0 ) {
F_26 ( V_3 -> V_1 ) ;
V_6 = V_48 ;
} else if ( V_44 == 1 ) {
F_19 ( L_5 ) ;
V_6 = V_48 ;
} else if ( V_44 == 2 ) {
F_19 ( L_6 ) ;
V_6 = V_61 ;
} else {
F_19 ( L_7 ) ;
V_6 = V_61 ;
}
V_49:
if ( ( V_47 . V_37 ) && ( V_47 . V_37 != V_17 -> V_37 ) )
F_27 ( V_47 . V_37 ) ;
if ( ! V_6 )
F_17 ( V_17 ) ;
return V_6 ;
}
static void F_28 ( T_1 * V_21 )
{
T_2 * V_3 = V_21 -> V_4 ;
if ( V_3 -> V_62 )
V_3 -> V_62 ( V_3 , V_21 ) ;
}
static int F_29 ( T_2 * V_3 , void T_4 * V_63 )
{
T_5 V_64 ;
struct V_65 V_66 ;
struct V_67 V_68 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( F_30 ( & V_64 , V_63 , sizeof( V_64 ) ) )
return - V_69 ;
switch ( V_64 ) {
case V_70 :
V_66 . V_71 = V_64 ;
snprintf ( V_66 . V_72 , sizeof( V_66 . V_72 ) , L_8 ,
V_3 -> V_73 ) ;
snprintf ( V_66 . V_74 , sizeof( V_66 . V_74 ) , L_9 ,
V_75 ) ;
if ( F_31 ( V_63 , & V_66 , sizeof( V_66 ) ) )
return - V_69 ;
return 0 ;
#ifdef F_32
case F_32 :
V_68 . V_71 = V_64 ;
if ( V_3 -> V_76 &&
( V_3 -> V_50 != V_77 ) ) {
V_68 . V_37 = 1 ;
} else {
V_68 . V_37 = 0 ;
}
if ( F_31 ( V_63 , & V_68 , sizeof( V_68 ) ) )
return - V_69 ;
return 0 ;
#endif
}
return - V_78 ;
}
static int F_33 ( T_1 * V_21 , struct V_79 * V_80 , int V_71 )
{
int V_6 = 0 ;
struct V_81 * V_82 = (struct V_81 * ) V_80 ;
T_2 * V_3 = V_21 -> V_4 ;
T_6 * V_83 ;
F_19 ( L_10 , V_71 , V_82 -> V_36 ) ;
#ifdef F_34
if ( V_71 == F_34 ) {
V_6 =
F_29 ( V_3 , ( void T_4 * ) V_80 -> V_84 ) ;
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
V_83 = F_35 ( V_82 -> V_36 , V_91 ) ;
if ( V_83 ) {
if ( F_30 ( V_83 , ( void T_4 * ) V_82 -> V_37 , V_82 -> V_36 ) )
V_6 = - V_69 ;
else
V_6 = F_36 ( V_3 , V_83 ) ;
if ( V_6 == 0 ) {
if ( F_31
( ( void T_4 * ) V_82 -> V_37 , V_83 , V_82 -> V_36 ) ) {
V_6 = - V_69 ;
}
}
F_37 ( V_83 ) ;
} else {
V_6 = - V_92 ;
}
V_85:
return V_6 ;
}
static int F_38 ( T_1 * V_21 , void * V_93 )
{
struct V_94 * V_95 = V_93 ;
struct V_96 V_97 ;
T_7 * V_98 ;
T_8 * V_99 ;
T_9 * V_100 ;
int V_6 = 0 ;
if ( F_39 ( V_21 ) )
return - V_101 ;
V_98 = & V_97 . V_102 ;
V_99 = ( T_8 * ) & V_98 -> V_37 ;
V_100 = & V_97 . V_100 ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
V_97 . V_103 = V_104 ;
V_97 . V_105 = sizeof( struct V_96 ) ;
memcpy ( V_97 . V_106 ,
( ( T_2 * ) V_21 -> V_4 ) -> V_107 , V_108 - 1 ) ;
V_98 -> V_109 = V_110 ;
V_98 -> V_111 = V_112 ;
V_98 -> V_36 = sizeof( V_98 -> V_37 ) ;
V_99 -> V_109 = V_113 ;
V_99 -> V_111 = V_112 ;
V_99 -> V_36 = sizeof( V_99 -> V_37 ) ;
V_99 -> V_37 . V_36 = V_42 ;
memcpy ( & V_99 -> V_37 . V_37 , V_95 -> V_114 , V_42 ) ;
V_100 -> V_109 = V_115 ;
V_100 -> V_111 = V_116 ;
V_100 -> V_36 = sizeof( V_100 -> V_37 ) ;
V_100 -> V_37 = 0 ;
V_6 = F_36 ( V_21 -> V_4 , ( T_6 * ) & V_97 ) ;
if ( V_6 != 0 || V_100 -> V_37 != V_117 ) {
F_22 ( V_118
L_11 ) ;
V_6 = - V_119 ;
} else {
memcpy ( V_21 -> V_41 , V_95 -> V_114 , V_21 -> V_120 ) ;
}
return V_6 ;
}
static int F_40 ( T_1 * V_21 , int V_121 )
{
if ( ( V_121 < 68 ) || ( V_121 > ( 2312 - 20 - 8 ) ) )
return - V_122 ;
V_21 -> V_123 = V_121 ;
return 0 ;
}
int F_41 ( T_2 * V_3 , struct V_124 * V_125 )
{
int V_6 = 0 ;
T_1 * V_1 ;
struct V_126 * V_126 ;
struct V_127 * V_128 ;
V_3 -> V_11 = V_15 ;
V_3 -> V_43 = V_129 ;
V_3 -> V_50 = V_77 ;
F_42 ( & V_3 -> V_18 ) ;
F_43 ( & V_3 -> V_19 ,
F_10 , ( unsigned long ) V_3 ) ;
V_126 = F_44 ( V_125 , V_3 ) ;
if ( V_126 == NULL ) {
F_22 ( V_118 L_12 ) ;
return 1 ;
}
V_1 = F_45 ( sizeof( struct V_127 ) , L_13 ,
V_130 ) ;
if ( V_1 == NULL ) {
F_22 ( V_118 L_14 ) ;
F_46 ( V_126 ) ;
V_6 = 1 ;
} else {
V_3 -> V_1 = V_1 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_131 = & V_132 ;
V_128 = F_47 ( V_1 ) ;
V_128 -> V_126 = V_126 ;
V_128 -> V_133 = V_134 ;
V_1 -> V_135 = V_128 ;
F_6 ( V_1 ) ;
F_48 ( V_1 ) ;
}
return V_6 ;
}
int F_49 ( T_2 * V_3 )
{
struct V_127 * V_128 ;
F_50 ( & V_3 -> V_19 ) ;
if ( V_3 -> V_1 ) {
V_128 = F_47 ( V_3 -> V_1 ) ;
if ( V_128 -> V_126 )
F_46 ( V_128 -> V_126 ) ;
F_51 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
}
return 0 ;
}
int F_52 ( T_2 * V_3 )
{
int V_136 = 0 ;
V_136 = F_53 ( V_3 -> V_1 ) ;
if ( V_136 )
return V_136 ;
return 0 ;
}
int F_54 ( T_2 * V_3 )
{
struct V_16 * V_17 ;
F_55 ( V_3 -> V_1 ) ;
while ( ( V_17 = F_11 ( & V_3 -> V_18 ) ) )
F_17 ( V_17 ) ;
return 0 ;
}
void F_56 ( T_2 * V_3 )
{
V_3 -> V_137 = 1 ;
if ( V_3 -> V_11 == V_12 )
F_6 ( V_3 -> V_1 ) ;
F_57 ( V_3 -> V_1 ) ;
}
static int F_16 ( T_2 * V_3 , T_3 V_24 )
{
T_3 V_138 ;
T_3 V_139 ;
int V_140 = 0 ;
V_138 = F_58 ( V_24 ) ;
V_139 = F_59 ( V_24 ) ;
#if 0
pr_debug("rx_typedrop : ftype=%d fstype=%d.\n", ftype, fstype);
#endif
switch ( V_138 ) {
case V_141 :
if ( ( V_3 -> V_1 -> V_38 & V_142 ) ||
( V_3 -> V_1 -> V_38 & V_39 ) ) {
V_140 = 1 ;
break;
}
F_19 ( L_15 ) ;
V_3 -> V_143 . V_144 ++ ;
switch ( V_139 ) {
case V_145 :
V_3 -> V_143 . V_146 ++ ;
break;
case V_147 :
V_3 -> V_143 . V_148 ++ ;
break;
case V_149 :
V_3 -> V_143 . V_150 ++ ;
break;
case V_151 :
V_3 -> V_143 . V_152 ++ ;
break;
case V_153 :
V_3 -> V_143 . V_154 ++ ;
break;
case V_155 :
V_3 -> V_143 . V_156 ++ ;
break;
case V_157 :
V_3 -> V_143 . V_158 ++ ;
break;
case V_159 :
V_3 -> V_143 . V_160 ++ ;
break;
case V_161 :
V_3 -> V_143 . V_162 ++ ;
break;
case V_163 :
V_3 -> V_143 . V_164 ++ ;
break;
case V_165 :
V_3 -> V_143 . V_166 ++ ;
break;
default:
V_3 -> V_143 . V_167 ++ ;
break;
}
V_140 = 2 ;
break;
case V_168 :
if ( ( V_3 -> V_1 -> V_38 & V_142 ) ||
( V_3 -> V_1 -> V_38 & V_39 ) ) {
V_140 = 1 ;
break;
}
F_19 ( L_16 ) ;
V_3 -> V_143 . V_169 ++ ;
switch ( V_139 ) {
case V_170 :
V_3 -> V_143 . V_171 ++ ;
break;
case V_172 :
V_3 -> V_143 . V_173 ++ ;
break;
case V_174 :
V_3 -> V_143 . V_175 ++ ;
break;
case V_176 :
V_3 -> V_143 . V_177 ++ ;
break;
case V_178 :
V_3 -> V_143 . V_179 ++ ;
break;
case V_180 :
V_3 -> V_143 . V_181 ++ ;
break;
default:
V_3 -> V_143 . V_182 ++ ;
break;
}
V_140 = 2 ;
break;
case V_183 :
V_3 -> V_143 . V_37 ++ ;
switch ( V_139 ) {
case V_184 :
V_3 -> V_143 . V_185 ++ ;
break;
case V_186 :
V_3 -> V_143 . V_187 ++ ;
break;
case V_188 :
V_3 -> V_143 . V_189 ++ ;
break;
case V_190 :
V_3 -> V_143 . V_191 ++ ;
break;
case V_192 :
F_19 ( L_17 ) ;
V_3 -> V_143 . null ++ ;
break;
case V_193 :
F_19 ( L_18 ) ;
V_3 -> V_143 . V_194 ++ ;
break;
case V_195 :
F_19 ( L_19 ) ;
V_3 -> V_143 . V_196 ++ ;
break;
case V_197 :
F_19 ( L_20 ) ;
V_3 -> V_143 . V_198 ++ ;
break;
default:
V_3 -> V_143 . V_199 ++ ;
break;
}
break;
}
return V_140 ;
}
static void F_60 ( T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_200 ) {
V_3 -> V_200 ( V_3 ) ;
} else {
F_22 ( V_201 L_21 ,
V_3 -> V_73 ) ;
F_26 ( V_3 -> V_1 ) ;
}
}
