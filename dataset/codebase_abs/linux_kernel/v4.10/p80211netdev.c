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
if ( F_10 ( V_5 , V_21 -> V_23 ) )
return V_24 ;
if ( V_5 -> V_2 -> V_25 & V_26 ) {
if ( ! F_11 ( V_5 -> V_2 -> V_27 ,
V_21 -> V_28 ) ) {
if ( ! F_12 ( V_21 -> V_28 ) )
return V_24 ;
}
}
if ( F_13 ( V_5 , V_5 -> V_29 , V_17 ) == 0 ) {
V_17 -> V_30 -> V_31 = V_32 ;
V_5 -> V_2 -> V_33 . V_34 ++ ;
V_5 -> V_2 -> V_33 . V_35 += V_17 -> V_36 ;
F_14 ( V_17 ) ;
return 0 ;
}
F_15 ( V_5 -> V_2 , L_1 ) ;
return V_37 ;
}
static void F_16 ( unsigned long V_38 )
{
struct V_4 * V_5 = (struct V_4 * ) V_38 ;
struct V_16 * V_17 = NULL ;
struct V_1 * V_30 = V_5 -> V_2 ;
while ( ( V_17 = F_17 ( & V_5 -> V_18 ) ) ) {
if ( V_5 -> V_11 == V_12 ) {
if ( V_30 -> type != V_39 ) {
V_17 -> V_30 = V_30 ;
F_18 ( V_17 ) ;
V_17 -> V_40 = V_41 ;
V_17 -> V_42 = V_43 ;
V_17 -> V_44 = F_19 ( V_45 ) ;
V_30 -> V_31 = V_32 ;
V_30 -> V_33 . V_34 ++ ;
V_30 -> V_33 . V_35 += V_17 -> V_36 ;
F_14 ( V_17 ) ;
continue;
} else {
if ( ! F_9 ( V_5 , V_17 ) )
continue;
}
}
F_20 ( V_17 ) ;
}
}
static int F_21 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_46 = - 1 ;
struct V_4 * V_5 = V_2 -> V_6 ;
union V_47 V_47 ;
struct V_48 V_49 ;
V_49 . V_22 = NULL ;
if ( ! V_17 )
return V_50 ;
if ( V_5 -> V_11 != V_12 ) {
V_3 = 1 ;
goto V_51;
}
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( F_22 ( V_2 ) ) {
F_15 ( V_2 , L_2 ) ;
V_3 = 1 ;
goto V_51;
}
F_5 ( V_2 ) ;
switch ( V_5 -> V_52 ) {
case V_53 :
case V_54 :
case V_55 :
break;
default:
if ( F_23 ( V_17 -> V_44 ) != V_45 ) {
F_3 ( V_5 -> V_2 ) ;
F_24 ( V_2 , L_3 ) ;
V_2 -> V_33 . V_56 ++ ;
V_3 = 0 ;
goto V_51;
}
break;
}
if ( F_23 ( V_17 -> V_44 ) == V_45 ) {
if ( ! F_25 ( V_57 ) ) {
V_3 = 1 ;
goto V_51;
}
memcpy ( & V_47 , V_17 -> V_22 , sizeof( V_47 ) ) ;
F_26 ( V_17 , sizeof( V_47 ) ) ;
} else {
if ( F_27
( V_5 , V_5 -> V_29 , V_17 , & V_47 ,
& V_49 ) != 0 ) {
F_15 ( V_2 , L_4 ,
V_5 -> V_29 ) ;
V_3 = 1 ;
goto V_51;
}
}
if ( ! V_5 -> V_58 ) {
V_3 = 1 ;
goto V_51;
}
F_28 ( V_2 ) ;
V_2 -> V_33 . V_59 ++ ;
V_2 -> V_33 . V_60 += V_17 -> V_36 ;
V_46 = V_5 -> V_58 ( V_5 , V_17 , & V_47 , & V_49 ) ;
if ( V_46 == 0 ) {
F_29 ( V_5 -> V_2 ) ;
V_3 = V_50 ;
} else if ( V_46 == 1 ) {
F_15 ( V_2 , L_5 ) ;
V_3 = V_50 ;
} else if ( V_46 == 2 ) {
F_15 ( V_2 , L_6 ) ;
V_3 = V_61 ;
} else {
F_15 ( V_2 , L_7 ) ;
V_3 = V_61 ;
}
V_51:
if ( ( V_49 . V_22 ) && ( V_49 . V_22 != V_17 -> V_22 ) )
F_30 ( V_49 . V_22 ) ;
if ( ! V_3 )
F_20 ( V_17 ) ;
return V_3 ;
}
static void F_31 ( struct V_1 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_6 ;
if ( V_5 -> V_62 )
V_5 -> V_62 ( V_5 , V_30 ) ;
}
static int F_32 ( struct V_4 * V_5 ,
void T_1 * V_63 )
{
T_2 V_64 ;
struct V_65 V_66 ;
struct V_67 V_68 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( F_33 ( & V_64 , V_63 , sizeof( V_64 ) ) )
return - V_69 ;
switch ( V_64 ) {
case V_70 :
V_66 . V_71 = V_64 ;
snprintf ( V_66 . V_72 , sizeof( V_66 . V_72 ) , L_8 ,
V_5 -> V_73 ) ;
snprintf ( V_66 . V_74 , sizeof( V_66 . V_74 ) , L_9 ,
V_75 ) ;
if ( F_34 ( V_63 , & V_66 , sizeof( V_66 ) ) )
return - V_69 ;
return 0 ;
#ifdef F_35
case F_35 :
V_68 . V_71 = V_64 ;
if ( V_5 -> V_76 &&
( V_5 -> V_52 != V_77 ) ) {
V_68 . V_22 = 1 ;
} else {
V_68 . V_22 = 0 ;
}
if ( F_34 ( V_63 , & V_68 , sizeof( V_68 ) ) )
return - V_69 ;
return 0 ;
#endif
}
return - V_78 ;
}
static int F_36 ( struct V_1 * V_30 ,
struct V_79 * V_80 , int V_71 )
{
int V_3 = 0 ;
struct V_81 * V_82 = (struct V_81 * ) V_80 ;
struct V_4 * V_5 = V_30 -> V_6 ;
T_3 * V_83 ;
F_15 ( V_30 , L_10 , V_71 , V_82 -> V_36 ) ;
#ifdef F_37
if ( V_71 == F_37 ) {
V_3 =
F_32 ( V_5 , ( void T_1 * ) V_80 -> V_84 ) ;
goto V_85;
}
#endif
if ( V_82 -> V_86 != V_87 ) {
V_3 = - V_88 ;
goto V_85;
}
if ( V_71 == V_89 ) {
V_3 = 0 ;
goto V_85;
} else if ( V_71 != V_90 ) {
V_3 = - V_88 ;
goto V_85;
}
V_83 = F_38 ( V_82 -> V_36 , V_91 ) ;
if ( V_83 ) {
if ( F_33 ( V_83 , ( void T_1 * ) V_82 -> V_22 , V_82 -> V_36 ) )
V_3 = - V_69 ;
else
V_3 = F_39 ( V_5 , V_83 ) ;
if ( V_3 == 0 ) {
if ( F_34
( ( void T_1 * ) V_82 -> V_22 , V_83 , V_82 -> V_36 ) ) {
V_3 = - V_69 ;
}
}
F_40 ( V_83 ) ;
} else {
V_3 = - V_92 ;
}
V_85:
return V_3 ;
}
static int F_41 ( struct V_1 * V_30 , void * V_93 )
{
struct V_94 * V_95 = V_93 ;
struct V_96 V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
int V_3 ;
if ( F_42 ( V_30 ) )
return - V_104 ;
V_99 = & V_97 . V_105 ;
V_101 = (struct V_100 * ) & V_99 -> V_22 ;
V_103 = & V_97 . V_103 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_106 = V_107 ;
V_97 . V_108 = sizeof( V_97 ) ;
memcpy ( V_97 . V_109 ,
( (struct V_4 * ) V_30 -> V_6 ) -> V_110 , V_111 - 1 ) ;
V_99 -> V_112 = V_113 ;
V_99 -> V_114 = V_115 ;
V_99 -> V_36 = sizeof( V_99 -> V_22 ) ;
V_101 -> V_112 = V_116 ;
V_101 -> V_114 = V_115 ;
V_101 -> V_36 = sizeof( V_101 -> V_22 ) ;
V_101 -> V_22 . V_36 = V_117 ;
memcpy ( & V_101 -> V_22 . V_22 , V_95 -> V_118 , V_117 ) ;
V_103 -> V_112 = V_119 ;
V_103 -> V_114 = V_120 ;
V_103 -> V_36 = sizeof( V_103 -> V_22 ) ;
V_103 -> V_22 = 0 ;
V_3 = F_39 ( V_30 -> V_6 , ( T_3 * ) & V_97 ) ;
if ( V_3 != 0 || V_103 -> V_22 != V_121 ) {
F_43 ( V_30 , L_11 ) ;
V_3 = - V_122 ;
} else {
memcpy ( V_30 -> V_27 , V_95 -> V_118 , V_30 -> V_123 ) ;
}
return V_3 ;
}
int F_44 ( struct V_4 * V_5 , struct V_124 * V_125 )
{
int V_3 = 0 ;
struct V_1 * V_2 ;
struct V_126 * V_126 ;
struct V_127 * V_128 ;
V_5 -> V_11 = V_15 ;
V_5 -> V_29 = V_129 ;
V_5 -> V_52 = V_77 ;
F_45 ( & V_5 -> V_18 ) ;
F_46 ( & V_5 -> V_19 ,
F_16 , ( unsigned long ) V_5 ) ;
V_126 = F_47 ( V_125 , V_5 ) ;
if ( ! V_126 ) {
F_48 ( V_125 , L_12 ) ;
return 1 ;
}
V_2 = F_49 ( sizeof( struct V_127 ) , L_13 ,
V_130 , V_131 ) ;
if ( ! V_2 ) {
F_48 ( V_125 , L_14 ) ;
F_50 ( V_126 ) ;
V_3 = 1 ;
} else {
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_132 = & V_133 ;
V_128 = F_51 ( V_2 ) ;
V_128 -> V_126 = V_126 ;
V_128 -> V_134 = V_135 ;
V_2 -> V_136 = V_128 ;
V_2 -> V_137 = 68 ;
V_2 -> V_138 = ( 2312 - 20 - 8 ) ;
F_5 ( V_2 ) ;
F_52 ( V_2 ) ;
}
return V_3 ;
}
void F_53 ( struct V_4 * V_5 )
{
struct V_127 * V_128 ;
F_54 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_2 ) {
V_128 = F_51 ( V_5 -> V_2 ) ;
if ( V_128 -> V_126 )
F_50 ( V_128 -> V_126 ) ;
F_55 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
}
}
int F_56 ( struct V_4 * V_5 )
{
return F_57 ( V_5 -> V_2 ) ;
}
int F_58 ( struct V_4 * V_5 )
{
struct V_16 * V_17 ;
F_59 ( V_5 -> V_2 ) ;
while ( ( V_17 = F_17 ( & V_5 -> V_18 ) ) )
F_20 ( V_17 ) ;
return 0 ;
}
void F_60 ( struct V_4 * V_5 )
{
V_5 -> V_139 = 1 ;
if ( V_5 -> V_11 == V_12 )
F_5 ( V_5 -> V_2 ) ;
F_61 ( V_5 -> V_2 ) ;
}
static int F_10 ( struct V_4 * V_5 , T_4 V_23 )
{
T_4 V_140 ;
T_4 V_141 ;
int V_142 = 0 ;
V_140 = F_62 ( V_23 ) ;
V_141 = F_63 ( V_23 ) ;
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch ( V_140 ) {
case V_143 :
if ( ( V_5 -> V_2 -> V_25 & V_144 ) ||
( V_5 -> V_2 -> V_25 & V_26 ) ) {
V_142 = 1 ;
break;
}
F_15 ( V_5 -> V_2 , L_15 ) ;
V_5 -> V_145 . V_146 ++ ;
switch ( V_141 ) {
case V_147 :
V_5 -> V_145 . V_148 ++ ;
break;
case V_149 :
V_5 -> V_145 . V_150 ++ ;
break;
case V_151 :
V_5 -> V_145 . V_152 ++ ;
break;
case V_153 :
V_5 -> V_145 . V_154 ++ ;
break;
case V_155 :
V_5 -> V_145 . V_156 ++ ;
break;
case V_157 :
V_5 -> V_145 . V_158 ++ ;
break;
case V_159 :
V_5 -> V_145 . V_160 ++ ;
break;
case V_161 :
V_5 -> V_145 . V_162 ++ ;
break;
case V_163 :
V_5 -> V_145 . V_164 ++ ;
break;
case V_165 :
V_5 -> V_145 . V_166 ++ ;
break;
case V_167 :
V_5 -> V_145 . V_168 ++ ;
break;
default:
V_5 -> V_145 . V_169 ++ ;
break;
}
V_142 = 2 ;
break;
case V_170 :
if ( ( V_5 -> V_2 -> V_25 & V_144 ) ||
( V_5 -> V_2 -> V_25 & V_26 ) ) {
V_142 = 1 ;
break;
}
F_15 ( V_5 -> V_2 , L_16 ) ;
V_5 -> V_145 . V_171 ++ ;
switch ( V_141 ) {
case V_172 :
V_5 -> V_145 . V_173 ++ ;
break;
case V_174 :
V_5 -> V_145 . V_175 ++ ;
break;
case V_176 :
V_5 -> V_145 . V_177 ++ ;
break;
case V_178 :
V_5 -> V_145 . V_179 ++ ;
break;
case V_180 :
V_5 -> V_145 . V_181 ++ ;
break;
case V_182 :
V_5 -> V_145 . V_183 ++ ;
break;
default:
V_5 -> V_145 . V_184 ++ ;
break;
}
V_142 = 2 ;
break;
case V_185 :
V_5 -> V_145 . V_22 ++ ;
switch ( V_141 ) {
case V_186 :
V_5 -> V_145 . V_187 ++ ;
break;
case V_188 :
V_5 -> V_145 . V_189 ++ ;
break;
case V_190 :
V_5 -> V_145 . V_191 ++ ;
break;
case V_192 :
V_5 -> V_145 . V_193 ++ ;
break;
case V_194 :
F_15 ( V_5 -> V_2 , L_17 ) ;
V_5 -> V_145 . null ++ ;
break;
case V_195 :
F_15 ( V_5 -> V_2 , L_18 ) ;
V_5 -> V_145 . V_196 ++ ;
break;
case V_197 :
F_15 ( V_5 -> V_2 , L_19 ) ;
V_5 -> V_145 . V_198 ++ ;
break;
case V_199 :
F_15 ( V_5 -> V_2 , L_20 ) ;
V_5 -> V_145 . V_200 ++ ;
break;
default:
V_5 -> V_145 . V_201 ++ ;
break;
}
break;
}
return V_142 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_202 ) {
V_5 -> V_202 ( V_5 ) ;
} else {
F_65 ( V_2 , L_21 ,
V_5 -> V_73 ) ;
F_29 ( V_5 -> V_2 ) ;
}
}
