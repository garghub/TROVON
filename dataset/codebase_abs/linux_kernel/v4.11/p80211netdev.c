static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_7 != V_8 )
return - V_9 ;
if ( V_5 -> V_10 ) {
V_3 = V_5 -> V_10 ( V_5 ) ;
if ( V_3 == 0 ) {
F_3 ( V_5 -> V_2 ) ;
V_5 -> V_11 = V_12 ;
}
} else {
V_3 = - V_13 ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_14 )
V_3 = V_5 -> V_14 ( V_5 ) ;
F_5 ( V_5 -> V_2 ) ;
V_5 -> V_11 = V_15 ;
return V_3 ;
}
void F_6 ( struct V_4 * V_5 , struct V_16 * V_17 )
{
F_7 ( & V_5 -> V_18 , V_17 ) ;
F_8 ( & V_5 -> V_19 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
struct V_16 * V_17 )
{
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) V_17 -> V_22 ;
if ( F_10 ( V_5 , F_11 ( V_21 -> V_23 ) ) )
return V_24 ;
if ( V_5 -> V_2 -> V_25 & V_26 ) {
if ( ! F_12 ( V_5 -> V_2 -> V_27 ,
V_21 -> V_28 ) ) {
if ( ! F_13 ( V_21 -> V_28 ) )
return V_24 ;
}
}
if ( F_14 ( V_5 , V_5 -> V_29 , V_17 ) == 0 ) {
V_5 -> V_2 -> V_30 . V_31 ++ ;
V_5 -> V_2 -> V_30 . V_32 += V_17 -> V_33 ;
F_15 ( V_17 ) ;
return 0 ;
}
F_16 ( V_5 -> V_2 , L_1 ) ;
return V_34 ;
}
static void F_17 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
struct V_16 * V_17 = NULL ;
struct V_1 * V_36 = V_5 -> V_2 ;
while ( ( V_17 = F_18 ( & V_5 -> V_18 ) ) ) {
if ( V_5 -> V_11 == V_12 ) {
if ( V_36 -> type != V_37 ) {
V_17 -> V_36 = V_36 ;
F_19 ( V_17 ) ;
V_17 -> V_38 = V_39 ;
V_17 -> V_40 = V_41 ;
V_17 -> V_42 = F_20 ( V_43 ) ;
V_36 -> V_30 . V_31 ++ ;
V_36 -> V_30 . V_32 += V_17 -> V_33 ;
F_15 ( V_17 ) ;
continue;
} else {
if ( ! F_9 ( V_5 , V_17 ) )
continue;
}
}
F_21 ( V_17 ) ;
}
}
static int F_22 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_44 = - 1 ;
struct V_4 * V_5 = V_2 -> V_6 ;
union V_45 V_45 ;
struct V_46 V_47 ;
V_47 . V_22 = NULL ;
if ( ! V_17 )
return V_48 ;
if ( V_5 -> V_11 != V_12 ) {
V_3 = 1 ;
goto V_49;
}
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( F_23 ( V_2 ) ) {
F_16 ( V_2 , L_2 ) ;
V_3 = 1 ;
goto V_49;
}
F_5 ( V_2 ) ;
switch ( V_5 -> V_50 ) {
case V_51 :
case V_52 :
case V_53 :
break;
default:
if ( F_24 ( V_17 -> V_42 ) != V_43 ) {
F_3 ( V_5 -> V_2 ) ;
F_25 ( V_2 , L_3 ) ;
V_2 -> V_30 . V_54 ++ ;
V_3 = 0 ;
goto V_49;
}
break;
}
if ( F_24 ( V_17 -> V_42 ) == V_43 ) {
if ( ! F_26 ( V_55 ) ) {
V_3 = 1 ;
goto V_49;
}
memcpy ( & V_45 , V_17 -> V_22 , sizeof( V_45 ) ) ;
F_27 ( V_17 , sizeof( V_45 ) ) ;
} else {
if ( F_28
( V_5 , V_5 -> V_29 , V_17 , & V_45 ,
& V_47 ) != 0 ) {
F_16 ( V_2 , L_4 ,
V_5 -> V_29 ) ;
V_3 = 1 ;
goto V_49;
}
}
if ( ! V_5 -> V_56 ) {
V_3 = 1 ;
goto V_49;
}
F_29 ( V_2 ) ;
V_2 -> V_30 . V_57 ++ ;
V_2 -> V_30 . V_58 += V_17 -> V_33 ;
V_44 = V_5 -> V_56 ( V_5 , V_17 , & V_45 , & V_47 ) ;
if ( V_44 == 0 ) {
F_30 ( V_5 -> V_2 ) ;
V_3 = V_48 ;
} else if ( V_44 == 1 ) {
F_16 ( V_2 , L_5 ) ;
V_3 = V_48 ;
} else if ( V_44 == 2 ) {
F_16 ( V_2 , L_6 ) ;
V_3 = V_59 ;
} else {
F_16 ( V_2 , L_7 ) ;
V_3 = V_59 ;
}
V_49:
if ( ( V_47 . V_22 ) && ( V_47 . V_22 != V_17 -> V_22 ) )
F_31 ( V_47 . V_22 ) ;
if ( ! V_3 )
F_21 ( V_17 ) ;
return V_3 ;
}
static void F_32 ( struct V_1 * V_36 )
{
struct V_4 * V_5 = V_36 -> V_6 ;
if ( V_5 -> V_60 )
V_5 -> V_60 ( V_5 , V_36 ) ;
}
static int F_33 ( struct V_4 * V_5 ,
void T_1 * V_61 )
{
T_2 V_62 ;
struct V_63 V_64 ;
struct V_65 V_66 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( F_34 ( & V_62 , V_61 , sizeof( V_62 ) ) )
return - V_67 ;
switch ( V_62 ) {
case V_68 :
V_64 . V_69 = V_62 ;
snprintf ( V_64 . V_70 , sizeof( V_64 . V_70 ) , L_8 ,
V_5 -> V_71 ) ;
snprintf ( V_64 . V_72 , sizeof( V_64 . V_72 ) , L_9 ,
V_73 ) ;
if ( F_35 ( V_61 , & V_64 , sizeof( V_64 ) ) )
return - V_67 ;
return 0 ;
#ifdef F_36
case F_36 :
V_66 . V_69 = V_62 ;
if ( V_5 -> V_74 &&
( V_5 -> V_50 != V_75 ) ) {
V_66 . V_22 = 1 ;
} else {
V_66 . V_22 = 0 ;
}
if ( F_35 ( V_61 , & V_66 , sizeof( V_66 ) ) )
return - V_67 ;
return 0 ;
#endif
}
return - V_76 ;
}
static int F_37 ( struct V_1 * V_36 ,
struct V_77 * V_78 , int V_69 )
{
int V_3 = 0 ;
struct V_79 * V_80 = (struct V_79 * ) V_78 ;
struct V_4 * V_5 = V_36 -> V_6 ;
T_3 * V_81 ;
F_16 ( V_36 , L_10 , V_69 , V_80 -> V_33 ) ;
#ifdef F_38
if ( V_69 == F_38 ) {
V_3 =
F_33 ( V_5 , ( void T_1 * ) V_78 -> V_82 ) ;
goto V_83;
}
#endif
if ( V_80 -> V_84 != V_85 ) {
V_3 = - V_86 ;
goto V_83;
}
if ( V_69 == V_87 ) {
V_3 = 0 ;
goto V_83;
} else if ( V_69 != V_88 ) {
V_3 = - V_86 ;
goto V_83;
}
V_81 = F_39 ( V_80 -> V_33 , V_89 ) ;
if ( V_81 ) {
if ( F_34 ( V_81 , ( void T_1 * ) V_80 -> V_22 , V_80 -> V_33 ) )
V_3 = - V_67 ;
else
V_3 = F_40 ( V_5 , V_81 ) ;
if ( V_3 == 0 ) {
if ( F_35
( ( void T_1 * ) V_80 -> V_22 , V_81 , V_80 -> V_33 ) ) {
V_3 = - V_67 ;
}
}
F_41 ( V_81 ) ;
} else {
V_3 = - V_90 ;
}
V_83:
return V_3 ;
}
static int F_42 ( struct V_1 * V_36 , void * V_91 )
{
struct V_92 * V_93 = V_91 ;
struct V_94 V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
int V_3 ;
if ( F_43 ( V_36 ) )
return - V_102 ;
V_97 = & V_95 . V_103 ;
V_99 = (struct V_98 * ) & V_97 -> V_22 ;
V_101 = & V_95 . V_101 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_104 = V_105 ;
V_95 . V_106 = sizeof( V_95 ) ;
memcpy ( V_95 . V_107 ,
( (struct V_4 * ) V_36 -> V_6 ) -> V_108 , V_109 - 1 ) ;
V_97 -> V_110 = V_111 ;
V_97 -> V_112 = V_113 ;
V_97 -> V_33 = sizeof( V_97 -> V_22 ) ;
V_99 -> V_110 = V_114 ;
V_99 -> V_112 = V_113 ;
V_99 -> V_33 = sizeof( V_99 -> V_22 ) ;
V_99 -> V_22 . V_33 = V_115 ;
memcpy ( & V_99 -> V_22 . V_22 , V_93 -> V_116 , V_115 ) ;
V_101 -> V_110 = V_117 ;
V_101 -> V_112 = V_118 ;
V_101 -> V_33 = sizeof( V_101 -> V_22 ) ;
V_101 -> V_22 = 0 ;
V_3 = F_40 ( V_36 -> V_6 , ( T_3 * ) & V_95 ) ;
if ( V_3 != 0 || V_101 -> V_22 != V_119 ) {
F_44 ( V_36 , L_11 ) ;
V_3 = - V_120 ;
} else {
memcpy ( V_36 -> V_27 , V_93 -> V_116 , V_36 -> V_121 ) ;
}
return V_3 ;
}
int F_45 ( struct V_4 * V_5 , struct V_122 * V_123 )
{
int V_3 = 0 ;
struct V_1 * V_2 ;
struct V_124 * V_124 ;
struct V_125 * V_126 ;
V_5 -> V_11 = V_15 ;
V_5 -> V_29 = V_127 ;
V_5 -> V_50 = V_75 ;
F_46 ( & V_5 -> V_18 ) ;
F_47 ( & V_5 -> V_19 ,
F_17 , ( unsigned long ) V_5 ) ;
V_124 = F_48 ( V_123 , V_5 ) ;
if ( ! V_124 ) {
F_49 ( V_123 , L_12 ) ;
return 1 ;
}
V_2 = F_50 ( sizeof( struct V_125 ) , L_13 ,
V_128 , V_129 ) ;
if ( ! V_2 ) {
F_49 ( V_123 , L_14 ) ;
F_51 ( V_124 ) ;
V_3 = 1 ;
} else {
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_130 = & V_131 ;
V_126 = F_52 ( V_2 ) ;
V_126 -> V_124 = V_124 ;
V_126 -> V_132 = V_133 ;
V_2 -> V_134 = V_126 ;
V_2 -> V_135 = 68 ;
V_2 -> V_136 = ( 2312 - 20 - 8 ) ;
F_5 ( V_2 ) ;
F_53 ( V_2 ) ;
}
return V_3 ;
}
void F_54 ( struct V_4 * V_5 )
{
struct V_125 * V_126 ;
F_55 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_2 ) {
V_126 = F_52 ( V_5 -> V_2 ) ;
if ( V_126 -> V_124 )
F_51 ( V_126 -> V_124 ) ;
F_56 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
}
}
int F_57 ( struct V_4 * V_5 )
{
return F_58 ( V_5 -> V_2 ) ;
}
int F_59 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
F_60 ( V_5 -> V_2 ) ;
while ( ( V_17 = F_18 ( & V_5 -> V_18 ) ) )
F_21 ( V_17 ) ;
return 0 ;
}
void F_61 ( struct V_4 * V_5 )
{
V_5 -> V_137 = 1 ;
if ( V_5 -> V_11 == V_12 )
F_5 ( V_5 -> V_2 ) ;
F_62 ( V_5 -> V_2 ) ;
}
static int F_10 ( struct V_4 * V_5 , T_4 V_23 )
{
T_4 V_138 ;
T_4 V_139 ;
int V_140 = 0 ;
V_138 = F_63 ( V_23 ) ;
V_139 = F_64 ( V_23 ) ;
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch ( V_138 ) {
case V_141 :
if ( ( V_5 -> V_2 -> V_25 & V_142 ) ||
( V_5 -> V_2 -> V_25 & V_26 ) ) {
V_140 = 1 ;
break;
}
F_16 ( V_5 -> V_2 , L_15 ) ;
V_5 -> V_143 . V_144 ++ ;
switch ( V_139 ) {
case V_145 :
V_5 -> V_143 . V_146 ++ ;
break;
case V_147 :
V_5 -> V_143 . V_148 ++ ;
break;
case V_149 :
V_5 -> V_143 . V_150 ++ ;
break;
case V_151 :
V_5 -> V_143 . V_152 ++ ;
break;
case V_153 :
V_5 -> V_143 . V_154 ++ ;
break;
case V_155 :
V_5 -> V_143 . V_156 ++ ;
break;
case V_157 :
V_5 -> V_143 . V_158 ++ ;
break;
case V_159 :
V_5 -> V_143 . V_160 ++ ;
break;
case V_161 :
V_5 -> V_143 . V_162 ++ ;
break;
case V_163 :
V_5 -> V_143 . V_164 ++ ;
break;
case V_165 :
V_5 -> V_143 . V_166 ++ ;
break;
default:
V_5 -> V_143 . V_167 ++ ;
break;
}
V_140 = 2 ;
break;
case V_168 :
if ( ( V_5 -> V_2 -> V_25 & V_142 ) ||
( V_5 -> V_2 -> V_25 & V_26 ) ) {
V_140 = 1 ;
break;
}
F_16 ( V_5 -> V_2 , L_16 ) ;
V_5 -> V_143 . V_169 ++ ;
switch ( V_139 ) {
case V_170 :
V_5 -> V_143 . V_171 ++ ;
break;
case V_172 :
V_5 -> V_143 . V_173 ++ ;
break;
case V_174 :
V_5 -> V_143 . V_175 ++ ;
break;
case V_176 :
V_5 -> V_143 . V_177 ++ ;
break;
case V_178 :
V_5 -> V_143 . V_179 ++ ;
break;
case V_180 :
V_5 -> V_143 . V_181 ++ ;
break;
default:
V_5 -> V_143 . V_182 ++ ;
break;
}
V_140 = 2 ;
break;
case V_183 :
V_5 -> V_143 . V_22 ++ ;
switch ( V_139 ) {
case V_184 :
V_5 -> V_143 . V_185 ++ ;
break;
case V_186 :
V_5 -> V_143 . V_187 ++ ;
break;
case V_188 :
V_5 -> V_143 . V_189 ++ ;
break;
case V_190 :
V_5 -> V_143 . V_191 ++ ;
break;
case V_192 :
F_16 ( V_5 -> V_2 , L_17 ) ;
V_5 -> V_143 . null ++ ;
break;
case V_193 :
F_16 ( V_5 -> V_2 , L_18 ) ;
V_5 -> V_143 . V_194 ++ ;
break;
case V_195 :
F_16 ( V_5 -> V_2 , L_19 ) ;
V_5 -> V_143 . V_196 ++ ;
break;
case V_197 :
F_16 ( V_5 -> V_2 , L_20 ) ;
V_5 -> V_143 . V_198 ++ ;
break;
default:
V_5 -> V_143 . V_199 ++ ;
break;
}
break;
}
return V_140 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_200 ) {
V_5 -> V_200 ( V_5 ) ;
} else {
F_66 ( V_2 , L_21 ,
V_5 -> V_71 ) ;
F_30 ( V_5 -> V_2 ) ;
}
}
