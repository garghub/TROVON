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
static int F_10 ( T_2 * V_3 , struct V_16 * V_17 )
{
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) V_17 -> V_22 ;
if ( F_11 ( V_3 , V_21 -> V_23 ) )
return V_24 ;
if ( V_3 -> V_1 -> V_25 & V_26 ) {
if ( ! F_12 ( V_3 -> V_1 -> V_27 ,
V_21 -> V_28 ) ) {
if ( ! F_13 ( V_21 -> V_28 ) )
return V_24 ;
}
}
if ( F_14 ( V_3 , V_3 -> V_29 , V_17 ) == 0 ) {
V_17 -> V_30 -> V_31 = V_32 ;
V_3 -> V_5 . V_33 ++ ;
V_3 -> V_5 . V_34 += V_17 -> V_35 ;
F_15 ( V_17 ) ;
return 0 ;
}
F_16 ( V_3 -> V_1 , L_1 ) ;
return V_36 ;
}
static void F_17 ( unsigned long V_37 )
{
T_2 * V_3 = ( T_2 * ) V_37 ;
struct V_16 * V_17 = NULL ;
T_1 * V_30 = V_3 -> V_1 ;
while ( ( V_17 = F_18 ( & V_3 -> V_18 ) ) ) {
if ( V_3 -> V_11 == V_12 ) {
if ( V_30 -> type != V_38 ) {
V_17 -> V_30 = V_30 ;
F_19 ( V_17 ) ;
V_17 -> V_39 = V_40 ;
V_17 -> V_41 = V_42 ;
V_17 -> V_43 = F_20 ( V_44 ) ;
V_30 -> V_31 = V_32 ;
V_3 -> V_5 . V_33 ++ ;
V_3 -> V_5 . V_34 += V_17 -> V_35 ;
F_15 ( V_17 ) ;
continue;
} else {
if ( ! F_10 ( V_3 , V_17 ) )
continue;
}
}
F_21 ( V_17 ) ;
}
}
static int F_22 ( struct V_16 * V_17 ,
T_1 * V_1 )
{
int V_6 = 0 ;
int V_45 = - 1 ;
T_2 * V_3 = V_1 -> V_4 ;
union V_46 V_46 ;
struct V_47 V_48 ;
V_48 . V_22 = NULL ;
if ( V_17 == NULL )
return V_49 ;
if ( V_3 -> V_11 != V_12 ) {
V_6 = 1 ;
goto V_50;
}
memset ( & V_46 , 0 , sizeof( union V_46 ) ) ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
if ( F_23 ( V_1 ) ) {
F_16 ( V_1 , L_2 ) ;
V_6 = 1 ;
goto V_50;
}
F_6 ( V_1 ) ;
switch ( V_3 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
break;
default:
if ( V_17 -> V_43 != V_44 ) {
F_4 ( V_3 -> V_1 ) ;
F_24 ( V_1 , L_3 ) ;
V_3 -> V_5 . V_55 ++ ;
V_6 = 0 ;
goto V_50;
}
break;
}
if ( V_17 -> V_43 == V_44 ) {
if ( ! F_25 ( V_56 ) ) {
V_6 = 1 ;
goto V_50;
}
memcpy ( & V_46 , V_17 -> V_22 , sizeof( union V_46 ) ) ;
F_26 ( V_17 , sizeof( union V_46 ) ) ;
} else {
if ( F_27
( V_3 , V_3 -> V_29 , V_17 , & V_46 ,
& V_48 ) != 0 ) {
F_16 ( V_1 , L_4 ,
V_3 -> V_29 ) ;
V_6 = 1 ;
goto V_50;
}
}
if ( V_3 -> V_57 == NULL ) {
V_6 = 1 ;
goto V_50;
}
V_1 -> V_58 = V_32 ;
V_3 -> V_5 . V_59 ++ ;
V_3 -> V_5 . V_60 += V_17 -> V_35 ;
V_45 = V_3 -> V_57 ( V_3 , V_17 , & V_46 , & V_48 ) ;
if ( V_45 == 0 ) {
F_28 ( V_3 -> V_1 ) ;
V_6 = V_49 ;
} else if ( V_45 == 1 ) {
F_16 ( V_1 , L_5 ) ;
V_6 = V_49 ;
} else if ( V_45 == 2 ) {
F_16 ( V_1 , L_6 ) ;
V_6 = V_61 ;
} else {
F_16 ( V_1 , L_7 ) ;
V_6 = V_61 ;
}
V_50:
if ( ( V_48 . V_22 ) && ( V_48 . V_22 != V_17 -> V_22 ) )
F_29 ( V_48 . V_22 ) ;
if ( ! V_6 )
F_21 ( V_17 ) ;
return V_6 ;
}
static void F_30 ( T_1 * V_30 )
{
T_2 * V_3 = V_30 -> V_4 ;
if ( V_3 -> V_62 )
V_3 -> V_62 ( V_3 , V_30 ) ;
}
static int F_31 ( T_2 * V_3 , void T_3 * V_63 )
{
T_4 V_64 ;
struct V_65 V_66 ;
struct V_67 V_68 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( F_32 ( & V_64 , V_63 , sizeof( V_64 ) ) )
return - V_69 ;
switch ( V_64 ) {
case V_70 :
V_66 . V_71 = V_64 ;
snprintf ( V_66 . V_72 , sizeof( V_66 . V_72 ) , L_8 ,
V_3 -> V_73 ) ;
snprintf ( V_66 . V_74 , sizeof( V_66 . V_74 ) , L_9 ,
V_75 ) ;
if ( F_33 ( V_63 , & V_66 , sizeof( V_66 ) ) )
return - V_69 ;
return 0 ;
#ifdef F_34
case F_34 :
V_68 . V_71 = V_64 ;
if ( V_3 -> V_76 &&
( V_3 -> V_51 != V_77 ) ) {
V_68 . V_22 = 1 ;
} else {
V_68 . V_22 = 0 ;
}
if ( F_33 ( V_63 , & V_68 , sizeof( V_68 ) ) )
return - V_69 ;
return 0 ;
#endif
}
return - V_78 ;
}
static int F_35 ( T_1 * V_30 , struct V_79 * V_80 , int V_71 )
{
int V_6 = 0 ;
struct V_81 * V_82 = (struct V_81 * ) V_80 ;
T_2 * V_3 = V_30 -> V_4 ;
T_5 * V_83 ;
F_16 ( V_30 , L_10 , V_71 , V_82 -> V_35 ) ;
#ifdef F_36
if ( V_71 == F_36 ) {
V_6 =
F_31 ( V_3 , ( void T_3 * ) V_80 -> V_84 ) ;
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
V_83 = F_37 ( V_82 -> V_35 , V_91 ) ;
if ( V_83 ) {
if ( F_32 ( V_83 , ( void T_3 * ) V_82 -> V_22 , V_82 -> V_35 ) )
V_6 = - V_69 ;
else
V_6 = F_38 ( V_3 , V_83 ) ;
if ( V_6 == 0 ) {
if ( F_33
( ( void T_3 * ) V_82 -> V_22 , V_83 , V_82 -> V_35 ) ) {
V_6 = - V_69 ;
}
}
F_39 ( V_83 ) ;
} else {
V_6 = - V_92 ;
}
V_85:
return V_6 ;
}
static int F_40 ( T_1 * V_30 , void * V_93 )
{
struct V_94 * V_95 = V_93 ;
struct V_96 V_97 ;
T_6 * V_98 ;
T_7 * V_99 ;
T_8 * V_100 ;
int V_6 ;
if ( F_41 ( V_30 ) )
return - V_101 ;
V_98 = & V_97 . V_102 ;
V_99 = ( T_7 * ) & V_98 -> V_22 ;
V_100 = & V_97 . V_100 ;
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
V_97 . V_103 = V_104 ;
V_97 . V_105 = sizeof( struct V_96 ) ;
memcpy ( V_97 . V_106 ,
( ( T_2 * ) V_30 -> V_4 ) -> V_107 , V_108 - 1 ) ;
V_98 -> V_109 = V_110 ;
V_98 -> V_111 = V_112 ;
V_98 -> V_35 = sizeof( V_98 -> V_22 ) ;
V_99 -> V_109 = V_113 ;
V_99 -> V_111 = V_112 ;
V_99 -> V_35 = sizeof( V_99 -> V_22 ) ;
V_99 -> V_22 . V_35 = V_114 ;
memcpy ( & V_99 -> V_22 . V_22 , V_95 -> V_115 , V_114 ) ;
V_100 -> V_109 = V_116 ;
V_100 -> V_111 = V_117 ;
V_100 -> V_35 = sizeof( V_100 -> V_22 ) ;
V_100 -> V_22 = 0 ;
V_6 = F_38 ( V_30 -> V_4 , ( T_5 * ) & V_97 ) ;
if ( V_6 != 0 || V_100 -> V_22 != V_118 ) {
F_42 ( V_30 , L_11 ) ;
V_6 = - V_119 ;
} else {
memcpy ( V_30 -> V_27 , V_95 -> V_115 , V_30 -> V_120 ) ;
}
return V_6 ;
}
static int F_43 ( T_1 * V_30 , int V_121 )
{
if ( ( V_121 < 68 ) || ( V_121 > ( 2312 - 20 - 8 ) ) )
return - V_122 ;
V_30 -> V_123 = V_121 ;
return 0 ;
}
int F_44 ( T_2 * V_3 , struct V_124 * V_125 )
{
int V_6 = 0 ;
T_1 * V_1 ;
struct V_126 * V_126 ;
struct V_127 * V_128 ;
V_3 -> V_11 = V_15 ;
V_3 -> V_29 = V_129 ;
V_3 -> V_51 = V_77 ;
F_45 ( & V_3 -> V_18 ) ;
F_46 ( & V_3 -> V_19 ,
F_17 , ( unsigned long ) V_3 ) ;
V_126 = F_47 ( V_125 , V_3 ) ;
if ( V_126 == NULL ) {
F_48 ( V_125 , L_12 ) ;
return 1 ;
}
V_1 = F_49 ( sizeof( struct V_127 ) , L_13 ,
V_130 ) ;
if ( V_1 == NULL ) {
F_48 ( V_125 , L_14 ) ;
F_50 ( V_126 ) ;
V_6 = 1 ;
} else {
V_3 -> V_1 = V_1 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_131 = & V_132 ;
V_128 = F_51 ( V_1 ) ;
V_128 -> V_126 = V_126 ;
V_128 -> V_133 = V_134 ;
V_1 -> V_135 = V_128 ;
F_6 ( V_1 ) ;
F_52 ( V_1 ) ;
}
return V_6 ;
}
void F_53 ( T_2 * V_3 )
{
struct V_127 * V_128 ;
F_54 ( & V_3 -> V_19 ) ;
if ( V_3 -> V_1 ) {
V_128 = F_51 ( V_3 -> V_1 ) ;
if ( V_128 -> V_126 )
F_50 ( V_128 -> V_126 ) ;
F_55 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
}
}
int F_56 ( T_2 * V_3 )
{
return F_57 ( V_3 -> V_1 ) ;
}
int F_58 ( T_2 * V_3 )
{
struct V_16 * V_17 ;
F_59 ( V_3 -> V_1 ) ;
while ( ( V_17 = F_18 ( & V_3 -> V_18 ) ) )
F_21 ( V_17 ) ;
return 0 ;
}
void F_60 ( T_2 * V_3 )
{
V_3 -> V_136 = 1 ;
if ( V_3 -> V_11 == V_12 )
F_6 ( V_3 -> V_1 ) ;
F_61 ( V_3 -> V_1 ) ;
}
static int F_11 ( T_2 * V_3 , T_9 V_23 )
{
T_9 V_137 ;
T_9 V_138 ;
int V_139 = 0 ;
V_137 = F_62 ( V_23 ) ;
V_138 = F_63 ( V_23 ) ;
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch ( V_137 ) {
case V_140 :
if ( ( V_3 -> V_1 -> V_25 & V_141 ) ||
( V_3 -> V_1 -> V_25 & V_26 ) ) {
V_139 = 1 ;
break;
}
F_16 ( V_3 -> V_1 , L_15 ) ;
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
if ( ( V_3 -> V_1 -> V_25 & V_141 ) ||
( V_3 -> V_1 -> V_25 & V_26 ) ) {
V_139 = 1 ;
break;
}
F_16 ( V_3 -> V_1 , L_16 ) ;
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
V_3 -> V_142 . V_22 ++ ;
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
F_16 ( V_3 -> V_1 , L_17 ) ;
V_3 -> V_142 . null ++ ;
break;
case V_192 :
F_16 ( V_3 -> V_1 , L_18 ) ;
V_3 -> V_142 . V_193 ++ ;
break;
case V_194 :
F_16 ( V_3 -> V_1 , L_19 ) ;
V_3 -> V_142 . V_195 ++ ;
break;
case V_196 :
F_16 ( V_3 -> V_1 , L_20 ) ;
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
static void F_64 ( T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_199 ) {
V_3 -> V_199 ( V_3 ) ;
} else {
F_65 ( V_1 , L_21 ,
V_3 -> V_73 ) ;
F_28 ( V_3 -> V_1 ) ;
}
}
