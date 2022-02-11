static int F_1 ( T_1 * V_1 )
{
return 0 ;
}
static int F_2 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_5 != V_6 )
return - V_7 ;
if ( V_3 -> V_8 != NULL ) {
V_2 = V_3 -> V_8 ( V_3 ) ;
if ( V_2 == 0 ) {
F_3 ( V_3 -> V_1 ) ;
V_3 -> V_9 = V_10 ;
}
} else {
V_2 = - V_11 ;
}
return V_2 ;
}
static int F_4 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_12 != NULL )
V_2 = V_3 -> V_12 ( V_3 ) ;
F_5 ( V_3 -> V_1 ) ;
V_3 -> V_9 = V_13 ;
return V_2 ;
}
void F_6 ( T_2 * V_3 , struct V_14 * V_15 )
{
F_7 ( & V_3 -> V_16 , V_15 ) ;
F_8 ( & V_3 -> V_17 ) ;
}
static int F_9 ( T_2 * V_3 , struct V_14 * V_15 )
{
struct V_18 * V_19 ;
V_19 = (struct V_18 * ) V_15 -> V_20 ;
if ( F_10 ( V_3 , V_19 -> V_21 ) )
return V_22 ;
if ( V_3 -> V_1 -> V_23 & V_24 ) {
if ( ! F_11 ( V_3 -> V_1 -> V_25 ,
V_19 -> V_26 ) ) {
if ( ! F_12 ( V_19 -> V_26 ) )
return V_22 ;
}
}
if ( F_13 ( V_3 , V_3 -> V_27 , V_15 ) == 0 ) {
V_15 -> V_28 -> V_29 = V_30 ;
V_3 -> V_1 -> V_31 . V_32 ++ ;
V_3 -> V_1 -> V_31 . V_33 += V_15 -> V_34 ;
F_14 ( V_15 ) ;
return 0 ;
}
F_15 ( V_3 -> V_1 , L_1 ) ;
return V_35 ;
}
static void F_16 ( unsigned long V_36 )
{
T_2 * V_3 = ( T_2 * ) V_36 ;
struct V_14 * V_15 = NULL ;
T_1 * V_28 = V_3 -> V_1 ;
while ( ( V_15 = F_17 ( & V_3 -> V_16 ) ) ) {
if ( V_3 -> V_9 == V_10 ) {
if ( V_28 -> type != V_37 ) {
V_15 -> V_28 = V_28 ;
F_18 ( V_15 ) ;
V_15 -> V_38 = V_39 ;
V_15 -> V_40 = V_41 ;
V_15 -> V_42 = F_19 ( V_43 ) ;
V_28 -> V_29 = V_30 ;
V_28 -> V_31 . V_32 ++ ;
V_28 -> V_31 . V_33 += V_15 -> V_34 ;
F_14 ( V_15 ) ;
continue;
} else {
if ( ! F_9 ( V_3 , V_15 ) )
continue;
}
}
F_20 ( V_15 ) ;
}
}
static int F_21 ( struct V_14 * V_15 ,
T_1 * V_1 )
{
int V_2 = 0 ;
int V_44 = - 1 ;
T_2 * V_3 = V_1 -> V_4 ;
union V_45 V_45 ;
struct V_46 V_47 ;
V_47 . V_20 = NULL ;
if ( V_15 == NULL )
return V_48 ;
if ( V_3 -> V_9 != V_10 ) {
V_2 = 1 ;
goto V_49;
}
memset ( & V_45 , 0 , sizeof( union V_45 ) ) ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
if ( F_22 ( V_1 ) ) {
F_15 ( V_1 , L_2 ) ;
V_2 = 1 ;
goto V_49;
}
F_5 ( V_1 ) ;
switch ( V_3 -> V_50 ) {
case V_51 :
case V_52 :
case V_53 :
break;
default:
if ( V_15 -> V_42 != V_43 ) {
F_3 ( V_3 -> V_1 ) ;
F_23 ( V_1 , L_3 ) ;
V_1 -> V_31 . V_54 ++ ;
V_2 = 0 ;
goto V_49;
}
break;
}
if ( V_15 -> V_42 == V_43 ) {
if ( ! F_24 ( V_55 ) ) {
V_2 = 1 ;
goto V_49;
}
memcpy ( & V_45 , V_15 -> V_20 , sizeof( union V_45 ) ) ;
F_25 ( V_15 , sizeof( union V_45 ) ) ;
} else {
if ( F_26
( V_3 , V_3 -> V_27 , V_15 , & V_45 ,
& V_47 ) != 0 ) {
F_15 ( V_1 , L_4 ,
V_3 -> V_27 ) ;
V_2 = 1 ;
goto V_49;
}
}
if ( V_3 -> V_56 == NULL ) {
V_2 = 1 ;
goto V_49;
}
V_1 -> V_57 = V_30 ;
V_1 -> V_31 . V_58 ++ ;
V_1 -> V_31 . V_59 += V_15 -> V_34 ;
V_44 = V_3 -> V_56 ( V_3 , V_15 , & V_45 , & V_47 ) ;
if ( V_44 == 0 ) {
F_27 ( V_3 -> V_1 ) ;
V_2 = V_48 ;
} else if ( V_44 == 1 ) {
F_15 ( V_1 , L_5 ) ;
V_2 = V_48 ;
} else if ( V_44 == 2 ) {
F_15 ( V_1 , L_6 ) ;
V_2 = V_60 ;
} else {
F_15 ( V_1 , L_7 ) ;
V_2 = V_60 ;
}
V_49:
if ( ( V_47 . V_20 ) && ( V_47 . V_20 != V_15 -> V_20 ) )
F_28 ( V_47 . V_20 ) ;
if ( ! V_2 )
F_20 ( V_15 ) ;
return V_2 ;
}
static void F_29 ( T_1 * V_28 )
{
T_2 * V_3 = V_28 -> V_4 ;
if ( V_3 -> V_61 )
V_3 -> V_61 ( V_3 , V_28 ) ;
}
static int F_30 ( T_2 * V_3 , void T_3 * V_62 )
{
T_4 V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
if ( F_31 ( & V_63 , V_62 , sizeof( V_63 ) ) )
return - V_68 ;
switch ( V_63 ) {
case V_69 :
V_65 . V_70 = V_63 ;
snprintf ( V_65 . V_71 , sizeof( V_65 . V_71 ) , L_8 ,
V_3 -> V_72 ) ;
snprintf ( V_65 . V_73 , sizeof( V_65 . V_73 ) , L_9 ,
V_74 ) ;
if ( F_32 ( V_62 , & V_65 , sizeof( V_65 ) ) )
return - V_68 ;
return 0 ;
#ifdef F_33
case F_33 :
V_67 . V_70 = V_63 ;
if ( V_3 -> V_75 &&
( V_3 -> V_50 != V_76 ) ) {
V_67 . V_20 = 1 ;
} else {
V_67 . V_20 = 0 ;
}
if ( F_32 ( V_62 , & V_67 , sizeof( V_67 ) ) )
return - V_68 ;
return 0 ;
#endif
}
return - V_77 ;
}
static int F_34 ( T_1 * V_28 , struct V_78 * V_79 , int V_70 )
{
int V_2 = 0 ;
struct V_80 * V_81 = (struct V_80 * ) V_79 ;
T_2 * V_3 = V_28 -> V_4 ;
T_5 * V_82 ;
F_15 ( V_28 , L_10 , V_70 , V_81 -> V_34 ) ;
#ifdef F_35
if ( V_70 == F_35 ) {
V_2 =
F_30 ( V_3 , ( void T_3 * ) V_79 -> V_83 ) ;
goto V_84;
}
#endif
if ( V_81 -> V_85 != V_86 ) {
V_2 = - V_87 ;
goto V_84;
}
if ( V_70 == V_88 ) {
V_2 = 0 ;
goto V_84;
} else if ( V_70 != V_89 ) {
V_2 = - V_87 ;
goto V_84;
}
V_82 = F_36 ( V_81 -> V_34 , V_90 ) ;
if ( V_82 ) {
if ( F_31 ( V_82 , ( void T_3 * ) V_81 -> V_20 , V_81 -> V_34 ) )
V_2 = - V_68 ;
else
V_2 = F_37 ( V_3 , V_82 ) ;
if ( V_2 == 0 ) {
if ( F_32
( ( void T_3 * ) V_81 -> V_20 , V_82 , V_81 -> V_34 ) ) {
V_2 = - V_68 ;
}
}
F_38 ( V_82 ) ;
} else {
V_2 = - V_91 ;
}
V_84:
return V_2 ;
}
static int F_39 ( T_1 * V_28 , void * V_92 )
{
struct V_93 * V_94 = V_92 ;
struct V_95 V_96 ;
T_6 * V_97 ;
T_7 * V_98 ;
T_8 * V_99 ;
int V_2 ;
if ( F_40 ( V_28 ) )
return - V_100 ;
V_97 = & V_96 . V_101 ;
V_98 = ( T_7 * ) & V_97 -> V_20 ;
V_99 = & V_96 . V_99 ;
memset ( & V_96 , 0 , sizeof( struct V_95 ) ) ;
V_96 . V_102 = V_103 ;
V_96 . V_104 = sizeof( struct V_95 ) ;
memcpy ( V_96 . V_105 ,
( ( T_2 * ) V_28 -> V_4 ) -> V_106 , V_107 - 1 ) ;
V_97 -> V_108 = V_109 ;
V_97 -> V_110 = V_111 ;
V_97 -> V_34 = sizeof( V_97 -> V_20 ) ;
V_98 -> V_108 = V_112 ;
V_98 -> V_110 = V_111 ;
V_98 -> V_34 = sizeof( V_98 -> V_20 ) ;
V_98 -> V_20 . V_34 = V_113 ;
memcpy ( & V_98 -> V_20 . V_20 , V_94 -> V_114 , V_113 ) ;
V_99 -> V_108 = V_115 ;
V_99 -> V_110 = V_116 ;
V_99 -> V_34 = sizeof( V_99 -> V_20 ) ;
V_99 -> V_20 = 0 ;
V_2 = F_37 ( V_28 -> V_4 , ( T_5 * ) & V_96 ) ;
if ( V_2 != 0 || V_99 -> V_20 != V_117 ) {
F_41 ( V_28 , L_11 ) ;
V_2 = - V_118 ;
} else {
memcpy ( V_28 -> V_25 , V_94 -> V_114 , V_28 -> V_119 ) ;
}
return V_2 ;
}
static int F_42 ( T_1 * V_28 , int V_120 )
{
if ( ( V_120 < 68 ) || ( V_120 > ( 2312 - 20 - 8 ) ) )
return - V_121 ;
V_28 -> V_122 = V_120 ;
return 0 ;
}
int F_43 ( T_2 * V_3 , struct V_123 * V_124 )
{
int V_2 = 0 ;
T_1 * V_1 ;
struct V_125 * V_125 ;
struct V_126 * V_127 ;
V_3 -> V_9 = V_13 ;
V_3 -> V_27 = V_128 ;
V_3 -> V_50 = V_76 ;
F_44 ( & V_3 -> V_16 ) ;
F_45 ( & V_3 -> V_17 ,
F_16 , ( unsigned long ) V_3 ) ;
V_125 = F_46 ( V_124 , V_3 ) ;
if ( V_125 == NULL ) {
F_47 ( V_124 , L_12 ) ;
return 1 ;
}
V_1 = F_48 ( sizeof( struct V_126 ) , L_13 ,
V_129 , V_130 ) ;
if ( V_1 == NULL ) {
F_47 ( V_124 , L_14 ) ;
F_49 ( V_125 ) ;
V_2 = 1 ;
} else {
V_3 -> V_1 = V_1 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_131 = & V_132 ;
V_127 = F_50 ( V_1 ) ;
V_127 -> V_125 = V_125 ;
V_127 -> V_133 = V_134 ;
V_1 -> V_135 = V_127 ;
F_5 ( V_1 ) ;
F_51 ( V_1 ) ;
}
return V_2 ;
}
void F_52 ( T_2 * V_3 )
{
struct V_126 * V_127 ;
F_53 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_1 ) {
V_127 = F_50 ( V_3 -> V_1 ) ;
if ( V_127 -> V_125 )
F_49 ( V_127 -> V_125 ) ;
F_54 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
}
}
int F_55 ( T_2 * V_3 )
{
return F_56 ( V_3 -> V_1 ) ;
}
int F_57 ( T_2 * V_3 )
{
struct V_14 * V_15 ;
F_58 ( V_3 -> V_1 ) ;
while ( ( V_15 = F_17 ( & V_3 -> V_16 ) ) )
F_20 ( V_15 ) ;
return 0 ;
}
void F_59 ( T_2 * V_3 )
{
V_3 -> V_136 = 1 ;
if ( V_3 -> V_9 == V_10 )
F_5 ( V_3 -> V_1 ) ;
F_60 ( V_3 -> V_1 ) ;
}
static int F_10 ( T_2 * V_3 , T_9 V_21 )
{
T_9 V_137 ;
T_9 V_138 ;
int V_139 = 0 ;
V_137 = F_61 ( V_21 ) ;
V_138 = F_62 ( V_21 ) ;
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch ( V_137 ) {
case V_140 :
if ( ( V_3 -> V_1 -> V_23 & V_141 ) ||
( V_3 -> V_1 -> V_23 & V_24 ) ) {
V_139 = 1 ;
break;
}
F_15 ( V_3 -> V_1 , L_15 ) ;
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
if ( ( V_3 -> V_1 -> V_23 & V_141 ) ||
( V_3 -> V_1 -> V_23 & V_24 ) ) {
V_139 = 1 ;
break;
}
F_15 ( V_3 -> V_1 , L_16 ) ;
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
V_3 -> V_142 . V_20 ++ ;
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
F_15 ( V_3 -> V_1 , L_17 ) ;
V_3 -> V_142 . null ++ ;
break;
case V_192 :
F_15 ( V_3 -> V_1 , L_18 ) ;
V_3 -> V_142 . V_193 ++ ;
break;
case V_194 :
F_15 ( V_3 -> V_1 , L_19 ) ;
V_3 -> V_142 . V_195 ++ ;
break;
case V_196 :
F_15 ( V_3 -> V_1 , L_20 ) ;
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
static void F_63 ( T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_199 ) {
V_3 -> V_199 ( V_3 ) ;
} else {
F_64 ( V_1 , L_21 ,
V_3 -> V_72 ) ;
F_27 ( V_3 -> V_1 ) ;
}
}
