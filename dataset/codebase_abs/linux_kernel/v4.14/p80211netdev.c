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
F_16 ( V_5 -> V_2 , L_1 , V_34 ) ;
return V_35 ;
}
static void F_17 ( unsigned long V_36 )
{
struct V_4 * V_5 = (struct V_4 * ) V_36 ;
struct V_16 * V_17 = NULL ;
struct V_1 * V_37 = V_5 -> V_2 ;
while ( ( V_17 = F_18 ( & V_5 -> V_18 ) ) ) {
if ( V_5 -> V_11 == V_12 ) {
if ( V_37 -> type != V_38 ) {
V_17 -> V_37 = V_37 ;
F_19 ( V_17 ) ;
V_17 -> V_39 = V_40 ;
V_17 -> V_41 = V_42 ;
V_17 -> V_43 = F_20 ( V_44 ) ;
V_37 -> V_30 . V_31 ++ ;
V_37 -> V_30 . V_32 += V_17 -> V_33 ;
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
int V_45 = - 1 ;
struct V_4 * V_5 = V_2 -> V_6 ;
union V_46 V_46 ;
struct V_47 V_48 ;
V_48 . V_22 = NULL ;
if ( ! V_17 )
return V_49 ;
if ( V_5 -> V_11 != V_12 ) {
V_3 = 1 ;
goto V_50;
}
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
if ( F_23 ( V_2 ) ) {
F_16 ( V_2 , L_2 ) ;
V_3 = 1 ;
goto V_50;
}
F_5 ( V_2 ) ;
switch ( V_5 -> V_51 ) {
case V_52 :
case V_53 :
case V_54 :
break;
default:
if ( F_24 ( V_17 -> V_43 ) != V_44 ) {
F_3 ( V_5 -> V_2 ) ;
F_25 ( V_2 , L_3 ) ;
V_2 -> V_30 . V_55 ++ ;
V_3 = 0 ;
goto V_50;
}
break;
}
if ( F_24 ( V_17 -> V_43 ) == V_44 ) {
if ( ! F_26 ( V_56 ) ) {
V_3 = 1 ;
goto V_50;
}
memcpy ( & V_46 , V_17 -> V_22 , sizeof( V_46 ) ) ;
F_27 ( V_17 , sizeof( V_46 ) ) ;
} else {
if ( F_28
( V_5 , V_5 -> V_29 , V_17 , & V_46 ,
& V_48 ) != 0 ) {
F_16 ( V_2 , L_4 ,
V_5 -> V_29 ) ;
V_3 = 1 ;
goto V_50;
}
}
if ( ! V_5 -> V_57 ) {
V_3 = 1 ;
goto V_50;
}
F_29 ( V_2 ) ;
V_2 -> V_30 . V_58 ++ ;
V_2 -> V_30 . V_59 += V_17 -> V_33 ;
V_45 = V_5 -> V_57 ( V_5 , V_17 , & V_46 , & V_48 ) ;
if ( V_45 == 0 ) {
F_30 ( V_5 -> V_2 ) ;
V_3 = V_49 ;
} else if ( V_45 == 1 ) {
F_16 ( V_2 , L_5 ) ;
V_3 = V_49 ;
} else if ( V_45 == 2 ) {
F_16 ( V_2 , L_6 ) ;
V_3 = V_60 ;
} else {
F_16 ( V_2 , L_7 ) ;
V_3 = V_60 ;
}
V_50:
if ( ( V_48 . V_22 ) && ( V_48 . V_22 != V_17 -> V_22 ) )
F_31 ( V_48 . V_22 ) ;
if ( ! V_3 )
F_21 ( V_17 ) ;
return V_3 ;
}
static void F_32 ( struct V_1 * V_37 )
{
struct V_4 * V_5 = V_37 -> V_6 ;
if ( V_5 -> V_61 )
V_5 -> V_61 ( V_5 , V_37 ) ;
}
static int F_33 ( struct V_4 * V_5 ,
void T_1 * V_62 )
{
T_2 V_63 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
if ( F_34 ( & V_63 , V_62 , sizeof( V_63 ) ) )
return - V_68 ;
switch ( V_63 ) {
case V_69 :
V_65 . V_70 = V_63 ;
snprintf ( V_65 . V_71 , sizeof( V_65 . V_71 ) , L_8 ,
V_5 -> V_72 ) ;
snprintf ( V_65 . V_73 , sizeof( V_65 . V_73 ) , L_9 ,
V_74 ) ;
if ( F_35 ( V_62 , & V_65 , sizeof( V_65 ) ) )
return - V_68 ;
return 0 ;
#ifdef F_36
case F_36 :
V_67 . V_70 = V_63 ;
if ( V_5 -> V_75 &&
( V_5 -> V_51 != V_76 ) ) {
V_67 . V_22 = 1 ;
} else {
V_67 . V_22 = 0 ;
}
if ( F_35 ( V_62 , & V_67 , sizeof( V_67 ) ) )
return - V_68 ;
return 0 ;
#endif
}
return - V_77 ;
}
static int F_37 ( struct V_1 * V_37 ,
struct V_78 * V_79 , int V_70 )
{
int V_3 = 0 ;
struct V_80 * V_81 = (struct V_80 * ) V_79 ;
struct V_4 * V_5 = V_37 -> V_6 ;
T_3 * V_82 ;
F_16 ( V_37 , L_10 , V_70 , V_81 -> V_33 ) ;
#ifdef F_38
if ( V_70 == F_38 ) {
V_3 =
F_33 ( V_5 , ( void T_1 * ) V_79 -> V_83 ) ;
goto V_84;
}
#endif
if ( V_81 -> V_85 != V_86 ) {
V_3 = - V_87 ;
goto V_84;
}
if ( V_70 == V_88 ) {
V_3 = 0 ;
goto V_84;
} else if ( V_70 != V_89 ) {
V_3 = - V_87 ;
goto V_84;
}
V_82 = F_39 ( V_81 -> V_33 , V_90 ) ;
if ( V_82 ) {
if ( F_34 ( V_82 , ( void T_1 * ) V_81 -> V_22 , V_81 -> V_33 ) )
V_3 = - V_68 ;
else
V_3 = F_40 ( V_5 , V_82 ) ;
if ( V_3 == 0 ) {
if ( F_35
( ( void T_1 * ) V_81 -> V_22 , V_82 , V_81 -> V_33 ) ) {
V_3 = - V_68 ;
}
}
F_41 ( V_82 ) ;
} else {
V_3 = - V_91 ;
}
V_84:
return V_3 ;
}
static int F_42 ( struct V_1 * V_37 , void * V_92 )
{
struct V_93 * V_94 = V_92 ;
struct V_95 V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
int V_3 ;
if ( F_43 ( V_37 ) )
return - V_103 ;
V_98 = & V_96 . V_104 ;
V_100 = (struct V_99 * ) & V_98 -> V_22 ;
V_102 = & V_96 . V_102 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_105 = V_106 ;
V_96 . V_107 = sizeof( V_96 ) ;
memcpy ( V_96 . V_108 ,
( (struct V_4 * ) V_37 -> V_6 ) -> V_109 , V_110 - 1 ) ;
V_98 -> V_111 = V_112 ;
V_98 -> V_113 = V_114 ;
V_98 -> V_33 = sizeof( V_98 -> V_22 ) ;
V_100 -> V_111 = V_115 ;
V_100 -> V_113 = V_114 ;
V_100 -> V_33 = sizeof( V_100 -> V_22 ) ;
V_100 -> V_22 . V_33 = V_116 ;
memcpy ( & V_100 -> V_22 . V_22 , V_94 -> V_117 , V_116 ) ;
V_102 -> V_111 = V_118 ;
V_102 -> V_113 = V_119 ;
V_102 -> V_33 = sizeof( V_102 -> V_22 ) ;
V_102 -> V_22 = 0 ;
V_3 = F_40 ( V_37 -> V_6 , ( T_3 * ) & V_96 ) ;
if ( V_3 != 0 || V_102 -> V_22 != V_120 ) {
F_44 ( V_37 , L_11 ) ;
V_3 = - V_121 ;
} else {
memcpy ( V_37 -> V_27 , V_94 -> V_117 , V_37 -> V_122 ) ;
}
return V_3 ;
}
int F_45 ( struct V_4 * V_5 , struct V_123 * V_124 )
{
int V_3 = 0 ;
struct V_1 * V_2 ;
struct V_125 * V_125 ;
struct V_126 * V_127 ;
V_5 -> V_11 = V_15 ;
V_5 -> V_29 = V_128 ;
V_5 -> V_51 = V_76 ;
F_46 ( & V_5 -> V_18 ) ;
F_47 ( & V_5 -> V_19 ,
F_17 , ( unsigned long ) V_5 ) ;
V_125 = F_48 ( V_124 , V_5 ) ;
if ( ! V_125 ) {
F_49 ( V_124 , L_12 ) ;
return 1 ;
}
V_2 = F_50 ( sizeof( struct V_126 ) , L_13 ,
V_129 , V_130 ) ;
if ( ! V_2 ) {
F_49 ( V_124 , L_14 ) ;
F_51 ( V_125 ) ;
V_3 = 1 ;
} else {
V_5 -> V_2 = V_2 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_131 = & V_132 ;
V_127 = F_52 ( V_2 ) ;
V_127 -> V_125 = V_125 ;
V_127 -> V_133 = V_134 ;
V_2 -> V_135 = V_127 ;
V_2 -> V_136 = 68 ;
V_2 -> V_137 = ( 2312 - 20 - 8 ) ;
F_5 ( V_2 ) ;
F_53 ( V_2 ) ;
}
return V_3 ;
}
void F_54 ( struct V_4 * V_5 )
{
struct V_126 * V_127 ;
F_55 ( & V_5 -> V_19 ) ;
if ( V_5 -> V_2 ) {
V_127 = F_52 ( V_5 -> V_2 ) ;
if ( V_127 -> V_125 )
F_51 ( V_127 -> V_125 ) ;
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
V_5 -> V_138 = 1 ;
if ( V_5 -> V_11 == V_12 )
F_5 ( V_5 -> V_2 ) ;
F_62 ( V_5 -> V_2 ) ;
}
static int F_10 ( struct V_4 * V_5 , T_4 V_23 )
{
T_4 V_139 ;
T_4 V_140 ;
int V_141 = 0 ;
V_139 = F_63 ( V_23 ) ;
V_140 = F_64 ( V_23 ) ;
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch ( V_139 ) {
case V_142 :
if ( ( V_5 -> V_2 -> V_25 & V_143 ) ||
( V_5 -> V_2 -> V_25 & V_26 ) ) {
V_141 = 1 ;
break;
}
F_16 ( V_5 -> V_2 , L_15 ) ;
V_5 -> V_144 . V_145 ++ ;
switch ( V_140 ) {
case V_146 :
V_5 -> V_144 . V_147 ++ ;
break;
case V_148 :
V_5 -> V_144 . V_149 ++ ;
break;
case V_150 :
V_5 -> V_144 . V_151 ++ ;
break;
case V_152 :
V_5 -> V_144 . V_153 ++ ;
break;
case V_154 :
V_5 -> V_144 . V_155 ++ ;
break;
case V_156 :
V_5 -> V_144 . V_157 ++ ;
break;
case V_158 :
V_5 -> V_144 . V_159 ++ ;
break;
case V_160 :
V_5 -> V_144 . V_161 ++ ;
break;
case V_162 :
V_5 -> V_144 . V_163 ++ ;
break;
case V_164 :
V_5 -> V_144 . V_165 ++ ;
break;
case V_166 :
V_5 -> V_144 . V_167 ++ ;
break;
default:
V_5 -> V_144 . V_168 ++ ;
break;
}
V_141 = 2 ;
break;
case V_169 :
if ( ( V_5 -> V_2 -> V_25 & V_143 ) ||
( V_5 -> V_2 -> V_25 & V_26 ) ) {
V_141 = 1 ;
break;
}
F_16 ( V_5 -> V_2 , L_16 ) ;
V_5 -> V_144 . V_170 ++ ;
switch ( V_140 ) {
case V_171 :
V_5 -> V_144 . V_172 ++ ;
break;
case V_173 :
V_5 -> V_144 . V_174 ++ ;
break;
case V_175 :
V_5 -> V_144 . V_176 ++ ;
break;
case V_177 :
V_5 -> V_144 . V_178 ++ ;
break;
case V_179 :
V_5 -> V_144 . V_180 ++ ;
break;
case V_181 :
V_5 -> V_144 . V_182 ++ ;
break;
default:
V_5 -> V_144 . V_183 ++ ;
break;
}
V_141 = 2 ;
break;
case V_184 :
V_5 -> V_144 . V_22 ++ ;
switch ( V_140 ) {
case V_185 :
V_5 -> V_144 . V_186 ++ ;
break;
case V_187 :
V_5 -> V_144 . V_188 ++ ;
break;
case V_189 :
V_5 -> V_144 . V_190 ++ ;
break;
case V_191 :
V_5 -> V_144 . V_192 ++ ;
break;
case V_193 :
F_16 ( V_5 -> V_2 , L_17 ) ;
V_5 -> V_144 . null ++ ;
break;
case V_194 :
F_16 ( V_5 -> V_2 , L_18 ) ;
V_5 -> V_144 . V_195 ++ ;
break;
case V_196 :
F_16 ( V_5 -> V_2 , L_19 ) ;
V_5 -> V_144 . V_197 ++ ;
break;
case V_198 :
F_16 ( V_5 -> V_2 , L_20 ) ;
V_5 -> V_144 . V_199 ++ ;
break;
default:
V_5 -> V_144 . V_200 ++ ;
break;
}
break;
}
return V_141 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_201 ) {
V_5 -> V_201 ( V_5 ) ;
} else {
F_66 ( V_2 , L_21 ,
V_5 -> V_72 ) ;
F_30 ( V_5 -> V_2 ) ;
}
}
