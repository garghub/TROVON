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
if ( V_3 -> V_8 ) {
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
if ( V_3 -> V_12 )
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
if ( ! V_15 )
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
if ( F_23 ( V_15 -> V_42 ) != V_43 ) {
F_3 ( V_3 -> V_1 ) ;
F_24 ( V_1 , L_3 ) ;
V_1 -> V_31 . V_54 ++ ;
V_2 = 0 ;
goto V_49;
}
break;
}
if ( F_23 ( V_15 -> V_42 ) == V_43 ) {
if ( ! F_25 ( V_55 ) ) {
V_2 = 1 ;
goto V_49;
}
memcpy ( & V_45 , V_15 -> V_20 , sizeof( union V_45 ) ) ;
F_26 ( V_15 , sizeof( union V_45 ) ) ;
} else {
if ( F_27
( V_3 , V_3 -> V_27 , V_15 , & V_45 ,
& V_47 ) != 0 ) {
F_15 ( V_1 , L_4 ,
V_3 -> V_27 ) ;
V_2 = 1 ;
goto V_49;
}
}
if ( ! V_3 -> V_56 ) {
V_2 = 1 ;
goto V_49;
}
F_28 ( V_1 ) ;
V_1 -> V_31 . V_57 ++ ;
V_1 -> V_31 . V_58 += V_15 -> V_34 ;
V_44 = V_3 -> V_56 ( V_3 , V_15 , & V_45 , & V_47 ) ;
if ( V_44 == 0 ) {
F_29 ( V_3 -> V_1 ) ;
V_2 = V_48 ;
} else if ( V_44 == 1 ) {
F_15 ( V_1 , L_5 ) ;
V_2 = V_48 ;
} else if ( V_44 == 2 ) {
F_15 ( V_1 , L_6 ) ;
V_2 = V_59 ;
} else {
F_15 ( V_1 , L_7 ) ;
V_2 = V_59 ;
}
V_49:
if ( ( V_47 . V_20 ) && ( V_47 . V_20 != V_15 -> V_20 ) )
F_30 ( V_47 . V_20 ) ;
if ( ! V_2 )
F_20 ( V_15 ) ;
return V_2 ;
}
static void F_31 ( T_1 * V_28 )
{
T_2 * V_3 = V_28 -> V_4 ;
if ( V_3 -> V_60 )
V_3 -> V_60 ( V_3 , V_28 ) ;
}
static int F_32 ( T_2 * V_3 , void T_3 * V_61 )
{
T_4 V_62 ;
struct V_63 V_64 ;
struct V_65 V_66 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( F_33 ( & V_62 , V_61 , sizeof( V_62 ) ) )
return - V_67 ;
switch ( V_62 ) {
case V_68 :
V_64 . V_69 = V_62 ;
snprintf ( V_64 . V_70 , sizeof( V_64 . V_70 ) , L_8 ,
V_3 -> V_71 ) ;
snprintf ( V_64 . V_72 , sizeof( V_64 . V_72 ) , L_9 ,
V_73 ) ;
if ( F_34 ( V_61 , & V_64 , sizeof( V_64 ) ) )
return - V_67 ;
return 0 ;
#ifdef F_35
case F_35 :
V_66 . V_69 = V_62 ;
if ( V_3 -> V_74 &&
( V_3 -> V_50 != V_75 ) ) {
V_66 . V_20 = 1 ;
} else {
V_66 . V_20 = 0 ;
}
if ( F_34 ( V_61 , & V_66 , sizeof( V_66 ) ) )
return - V_67 ;
return 0 ;
#endif
}
return - V_76 ;
}
static int F_36 ( T_1 * V_28 , struct V_77 * V_78 , int V_69 )
{
int V_2 = 0 ;
struct V_79 * V_80 = (struct V_79 * ) V_78 ;
T_2 * V_3 = V_28 -> V_4 ;
T_5 * V_81 ;
F_15 ( V_28 , L_10 , V_69 , V_80 -> V_34 ) ;
#ifdef F_37
if ( V_69 == F_37 ) {
V_2 =
F_32 ( V_3 , ( void T_3 * ) V_78 -> V_82 ) ;
goto V_83;
}
#endif
if ( V_80 -> V_84 != V_85 ) {
V_2 = - V_86 ;
goto V_83;
}
if ( V_69 == V_87 ) {
V_2 = 0 ;
goto V_83;
} else if ( V_69 != V_88 ) {
V_2 = - V_86 ;
goto V_83;
}
V_81 = F_38 ( V_80 -> V_34 , V_89 ) ;
if ( V_81 ) {
if ( F_33 ( V_81 , ( void T_3 * ) V_80 -> V_20 , V_80 -> V_34 ) )
V_2 = - V_67 ;
else
V_2 = F_39 ( V_3 , V_81 ) ;
if ( V_2 == 0 ) {
if ( F_34
( ( void T_3 * ) V_80 -> V_20 , V_81 , V_80 -> V_34 ) ) {
V_2 = - V_67 ;
}
}
F_40 ( V_81 ) ;
} else {
V_2 = - V_90 ;
}
V_83:
return V_2 ;
}
static int F_41 ( T_1 * V_28 , void * V_91 )
{
struct V_92 * V_93 = V_91 ;
struct V_94 V_95 ;
T_6 * V_96 ;
T_7 * V_97 ;
T_8 * V_98 ;
int V_2 ;
if ( F_42 ( V_28 ) )
return - V_99 ;
V_96 = & V_95 . V_100 ;
V_97 = ( T_7 * ) & V_96 -> V_20 ;
V_98 = & V_95 . V_98 ;
memset ( & V_95 , 0 , sizeof( struct V_94 ) ) ;
V_95 . V_101 = V_102 ;
V_95 . V_103 = sizeof( struct V_94 ) ;
memcpy ( V_95 . V_104 ,
( ( T_2 * ) V_28 -> V_4 ) -> V_105 , V_106 - 1 ) ;
V_96 -> V_107 = V_108 ;
V_96 -> V_109 = V_110 ;
V_96 -> V_34 = sizeof( V_96 -> V_20 ) ;
V_97 -> V_107 = V_111 ;
V_97 -> V_109 = V_110 ;
V_97 -> V_34 = sizeof( V_97 -> V_20 ) ;
V_97 -> V_20 . V_34 = V_112 ;
memcpy ( & V_97 -> V_20 . V_20 , V_93 -> V_113 , V_112 ) ;
V_98 -> V_107 = V_114 ;
V_98 -> V_109 = V_115 ;
V_98 -> V_34 = sizeof( V_98 -> V_20 ) ;
V_98 -> V_20 = 0 ;
V_2 = F_39 ( V_28 -> V_4 , ( T_5 * ) & V_95 ) ;
if ( V_2 != 0 || V_98 -> V_20 != V_116 ) {
F_43 ( V_28 , L_11 ) ;
V_2 = - V_117 ;
} else {
memcpy ( V_28 -> V_25 , V_93 -> V_113 , V_28 -> V_118 ) ;
}
return V_2 ;
}
static int F_44 ( T_1 * V_28 , int V_119 )
{
if ( ( V_119 < 68 ) || ( V_119 > ( 2312 - 20 - 8 ) ) )
return - V_120 ;
V_28 -> V_121 = V_119 ;
return 0 ;
}
int F_45 ( T_2 * V_3 , struct V_122 * V_123 )
{
int V_2 = 0 ;
T_1 * V_1 ;
struct V_124 * V_124 ;
struct V_125 * V_126 ;
V_3 -> V_9 = V_13 ;
V_3 -> V_27 = V_127 ;
V_3 -> V_50 = V_75 ;
F_46 ( & V_3 -> V_16 ) ;
F_47 ( & V_3 -> V_17 ,
F_16 , ( unsigned long ) V_3 ) ;
V_124 = F_48 ( V_123 , V_3 ) ;
if ( ! V_124 ) {
F_49 ( V_123 , L_12 ) ;
return 1 ;
}
V_1 = F_50 ( sizeof( struct V_125 ) , L_13 ,
V_128 , V_129 ) ;
if ( ! V_1 ) {
F_49 ( V_123 , L_14 ) ;
F_51 ( V_124 ) ;
V_2 = 1 ;
} else {
V_3 -> V_1 = V_1 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_130 = & V_131 ;
V_126 = F_52 ( V_1 ) ;
V_126 -> V_124 = V_124 ;
V_126 -> V_132 = V_133 ;
V_1 -> V_134 = V_126 ;
F_5 ( V_1 ) ;
F_53 ( V_1 ) ;
}
return V_2 ;
}
void F_54 ( T_2 * V_3 )
{
struct V_125 * V_126 ;
F_55 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_1 ) {
V_126 = F_52 ( V_3 -> V_1 ) ;
if ( V_126 -> V_124 )
F_51 ( V_126 -> V_124 ) ;
F_56 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
}
}
int F_57 ( T_2 * V_3 )
{
return F_58 ( V_3 -> V_1 ) ;
}
int F_59 ( T_2 * V_3 )
{
struct V_14 * V_15 ;
F_60 ( V_3 -> V_1 ) ;
while ( ( V_15 = F_17 ( & V_3 -> V_16 ) ) )
F_20 ( V_15 ) ;
return 0 ;
}
void F_61 ( T_2 * V_3 )
{
V_3 -> V_135 = 1 ;
if ( V_3 -> V_9 == V_10 )
F_5 ( V_3 -> V_1 ) ;
F_62 ( V_3 -> V_1 ) ;
}
static int F_10 ( T_2 * V_3 , T_9 V_21 )
{
T_9 V_136 ;
T_9 V_137 ;
int V_138 = 0 ;
V_136 = F_63 ( V_21 ) ;
V_137 = F_64 ( V_21 ) ;
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch ( V_136 ) {
case V_139 :
if ( ( V_3 -> V_1 -> V_23 & V_140 ) ||
( V_3 -> V_1 -> V_23 & V_24 ) ) {
V_138 = 1 ;
break;
}
F_15 ( V_3 -> V_1 , L_15 ) ;
V_3 -> V_141 . V_142 ++ ;
switch ( V_137 ) {
case V_143 :
V_3 -> V_141 . V_144 ++ ;
break;
case V_145 :
V_3 -> V_141 . V_146 ++ ;
break;
case V_147 :
V_3 -> V_141 . V_148 ++ ;
break;
case V_149 :
V_3 -> V_141 . V_150 ++ ;
break;
case V_151 :
V_3 -> V_141 . V_152 ++ ;
break;
case V_153 :
V_3 -> V_141 . V_154 ++ ;
break;
case V_155 :
V_3 -> V_141 . V_156 ++ ;
break;
case V_157 :
V_3 -> V_141 . V_158 ++ ;
break;
case V_159 :
V_3 -> V_141 . V_160 ++ ;
break;
case V_161 :
V_3 -> V_141 . V_162 ++ ;
break;
case V_163 :
V_3 -> V_141 . V_164 ++ ;
break;
default:
V_3 -> V_141 . V_165 ++ ;
break;
}
V_138 = 2 ;
break;
case V_166 :
if ( ( V_3 -> V_1 -> V_23 & V_140 ) ||
( V_3 -> V_1 -> V_23 & V_24 ) ) {
V_138 = 1 ;
break;
}
F_15 ( V_3 -> V_1 , L_16 ) ;
V_3 -> V_141 . V_167 ++ ;
switch ( V_137 ) {
case V_168 :
V_3 -> V_141 . V_169 ++ ;
break;
case V_170 :
V_3 -> V_141 . V_171 ++ ;
break;
case V_172 :
V_3 -> V_141 . V_173 ++ ;
break;
case V_174 :
V_3 -> V_141 . V_175 ++ ;
break;
case V_176 :
V_3 -> V_141 . V_177 ++ ;
break;
case V_178 :
V_3 -> V_141 . V_179 ++ ;
break;
default:
V_3 -> V_141 . V_180 ++ ;
break;
}
V_138 = 2 ;
break;
case V_181 :
V_3 -> V_141 . V_20 ++ ;
switch ( V_137 ) {
case V_182 :
V_3 -> V_141 . V_183 ++ ;
break;
case V_184 :
V_3 -> V_141 . V_185 ++ ;
break;
case V_186 :
V_3 -> V_141 . V_187 ++ ;
break;
case V_188 :
V_3 -> V_141 . V_189 ++ ;
break;
case V_190 :
F_15 ( V_3 -> V_1 , L_17 ) ;
V_3 -> V_141 . null ++ ;
break;
case V_191 :
F_15 ( V_3 -> V_1 , L_18 ) ;
V_3 -> V_141 . V_192 ++ ;
break;
case V_193 :
F_15 ( V_3 -> V_1 , L_19 ) ;
V_3 -> V_141 . V_194 ++ ;
break;
case V_195 :
F_15 ( V_3 -> V_1 , L_20 ) ;
V_3 -> V_141 . V_196 ++ ;
break;
default:
V_3 -> V_141 . V_197 ++ ;
break;
}
break;
}
return V_138 ;
}
static void F_65 ( T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
if ( V_3 -> V_198 ) {
V_3 -> V_198 ( V_3 ) ;
} else {
F_66 ( V_1 , L_21 ,
V_3 -> V_71 ) ;
F_29 ( V_3 -> V_1 ) ;
}
}
