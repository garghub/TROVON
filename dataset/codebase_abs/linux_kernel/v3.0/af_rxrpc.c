static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) < ( V_4 ) V_2 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_5 () ;
if ( F_1 ( V_2 ) ) {
struct V_6 * V_7 = F_6 ( V_2 -> V_8 ) ;
if ( F_7 ( V_7 ) )
F_8 ( & V_7 -> V_9 ) ;
F_9 ( V_2 , V_10 , V_11 ) ;
}
F_10 () ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
int V_16 )
{
if ( V_16 < sizeof( struct V_14 ) )
return - V_17 ;
if ( V_15 -> V_18 != V_19 )
return - V_20 ;
if ( V_15 -> V_21 != V_22 )
return - V_23 ;
V_16 -= F_12 ( struct V_14 , V_24 ) ;
if ( V_15 -> V_25 < sizeof( V_26 ) ||
V_15 -> V_25 > V_16 )
return - V_17 ;
if ( V_15 -> V_24 . V_27 != V_13 -> V_28 )
return - V_20 ;
switch ( V_15 -> V_24 . V_27 ) {
case V_29 :
F_13 ( L_2 ,
F_14 ( V_15 -> V_24 . sin . V_30 ) ,
& V_15 -> V_24 . sin . V_31 ) ;
if ( V_15 -> V_25 > 8 )
memset ( ( void * ) & V_15 -> V_24 + 8 , 0 ,
V_15 -> V_25 - 8 ) ;
break;
case V_32 :
default:
return - V_20 ;
}
return 0 ;
}
static int F_15 ( struct V_33 * V_1 , struct V_34 * V_35 , int V_16 )
{
struct V_14 * V_15 = (struct V_14 * ) V_35 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_36 * V_37 ;
struct V_12 * V_13 = F_16 ( V_2 ) , * V_38 ;
T_1 V_39 ;
int V_40 ;
F_4 ( L_3 , V_13 , V_35 , V_16 ) ;
V_40 = F_11 ( V_13 , V_15 , V_16 ) ;
if ( V_40 < 0 )
goto error;
F_17 ( & V_13 -> V_2 ) ;
if ( V_13 -> V_2 . V_41 != V_42 ) {
V_40 = - V_17 ;
goto V_43;
}
memcpy ( & V_13 -> V_15 , V_15 , sizeof( V_13 -> V_15 ) ) ;
V_37 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_37 ) ) {
V_40 = F_20 ( V_37 ) ;
goto V_43;
}
V_13 -> V_37 = V_37 ;
if ( V_15 -> V_44 ) {
V_39 = F_21 ( V_15 -> V_44 ) ;
F_22 ( & V_37 -> V_45 ) ;
F_23 (prx, &local->services, listen_link) {
if ( V_38 -> V_39 == V_39 )
goto V_46;
}
V_13 -> V_39 = V_39 ;
F_24 ( & V_13 -> V_47 , & V_37 -> V_48 ) ;
F_25 ( & V_37 -> V_45 ) ;
V_13 -> V_2 . V_41 = V_49 ;
} else {
V_13 -> V_2 . V_41 = V_50 ;
}
F_26 ( & V_13 -> V_2 ) ;
F_27 ( L_4 ) ;
return 0 ;
V_46:
V_40 = - V_51 ;
F_25 ( & V_37 -> V_45 ) ;
V_43:
F_26 ( & V_13 -> V_2 ) ;
error:
F_27 ( L_5 , V_40 ) ;
return V_40 ;
}
static int F_28 ( struct V_33 * V_1 , int V_52 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_40 ;
F_4 ( L_6 , V_13 , V_52 ) ;
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_41 ) {
case V_42 :
V_40 = - V_53 ;
break;
case V_50 :
case V_54 :
default:
V_40 = - V_55 ;
break;
case V_49 :
ASSERT ( V_13 -> V_37 != NULL ) ;
V_2 -> V_56 = V_52 ;
V_13 -> V_2 . V_41 = V_57 ;
V_40 = 0 ;
break;
}
F_26 ( & V_13 -> V_2 ) ;
F_27 ( L_5 , V_40 ) ;
return V_40 ;
}
static struct V_58 * F_29 ( struct V_33 * V_1 ,
struct V_34 * V_59 ,
int V_60 , int V_61 ,
T_2 V_62 )
{
struct V_14 * V_15 = (struct V_14 * ) V_59 ;
struct V_58 * V_63 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
struct V_64 * V_65 ;
F_4 ( L_7 , V_13 , V_59 , V_60 , V_61 ) ;
ASSERT ( V_13 -> V_37 != NULL ) ;
ASSERT ( V_13 -> V_2 . V_41 > V_42 ) ;
if ( V_13 -> V_15 . V_21 != V_15 -> V_21 )
return F_30 ( - V_23 ) ;
if ( V_13 -> V_15 . V_24 . V_27 != V_15 -> V_24 . V_27 )
return F_30 ( - V_20 ) ;
V_65 = F_31 ( V_15 , V_62 ) ;
if ( F_19 ( V_65 ) )
return F_32 ( V_65 ) ;
V_63 = F_33 ( V_13 -> V_37 , V_65 , V_62 ) ;
F_34 ( V_65 ) ;
F_27 ( L_8 , V_63 ) ;
return V_63 ;
}
struct V_66 * F_35 ( struct V_33 * V_1 ,
struct V_14 * V_15 ,
struct V_67 * V_67 ,
unsigned long V_68 ,
T_2 V_62 )
{
struct V_69 * V_70 ;
struct V_58 * V_63 ;
struct V_66 * V_71 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
T_1 V_39 ;
F_4 ( L_9 , F_36 ( V_67 ) , V_68 ) ;
F_17 ( & V_13 -> V_2 ) ;
if ( V_15 ) {
V_63 = F_29 ( V_1 , (struct V_34 * ) V_15 ,
sizeof( * V_15 ) , 0 , V_62 ) ;
if ( F_19 ( V_63 ) ) {
V_71 = F_32 ( V_63 ) ;
V_63 = NULL ;
goto V_72;
}
} else {
V_63 = V_13 -> V_63 ;
if ( ! V_63 ) {
V_71 = F_30 ( - V_73 ) ;
goto V_72;
}
F_37 ( & V_63 -> V_74 ) ;
}
V_39 = V_13 -> V_39 ;
if ( V_15 )
V_39 = F_21 ( V_15 -> V_44 ) ;
if ( ! V_67 )
V_67 = V_13 -> V_67 ;
if ( V_67 && ! V_67 -> V_75 . V_76 )
V_67 = NULL ;
V_70 = F_38 ( V_13 , V_63 , V_67 , V_39 , V_62 ) ;
if ( F_19 ( V_70 ) ) {
V_71 = F_32 ( V_70 ) ;
goto V_77;
}
V_71 = F_39 ( V_13 , V_63 , V_70 , V_68 , true ,
V_62 ) ;
F_40 ( V_63 , V_70 ) ;
V_77:
F_41 ( V_63 ) ;
V_72:
F_26 ( & V_13 -> V_2 ) ;
F_27 ( L_8 , V_71 ) ;
return V_71 ;
}
void F_42 ( struct V_66 * V_71 )
{
F_4 ( L_10 , V_71 -> V_78 , F_2 ( & V_71 -> V_74 ) ) ;
F_43 ( V_71 -> V_33 , V_71 ) ;
F_44 ( V_71 ) ;
}
void F_45 ( struct V_33 * V_1 ,
T_3 V_79 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
F_4 ( L_11 ) ;
V_13 -> V_79 = V_79 ;
}
static int F_46 ( struct V_33 * V_1 , struct V_34 * V_59 ,
int V_60 , int V_61 )
{
struct V_14 * V_15 = (struct V_14 * ) V_59 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_58 * V_63 ;
struct V_36 * V_37 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_40 ;
F_4 ( L_7 , V_13 , V_59 , V_60 , V_61 ) ;
V_40 = F_11 ( V_13 , V_15 , V_60 ) ;
if ( V_40 < 0 ) {
F_27 ( L_12 , V_40 ) ;
return V_40 ;
}
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_41 ) {
case V_42 :
F_47 ( V_13 -> V_37 , == , NULL ) ;
V_13 -> V_15 . V_18 = V_19 ;
V_13 -> V_15 . V_44 = 0 ;
V_13 -> V_15 . V_21 = V_15 -> V_21 ;
V_13 -> V_15 . V_25 = sizeof( V_26 ) ;
V_13 -> V_15 . V_24 . V_27 = V_15 -> V_24 . V_27 ;
V_37 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_37 ) ) {
F_26 ( & V_13 -> V_2 ) ;
return F_20 ( V_37 ) ;
}
V_13 -> V_37 = V_37 ;
V_13 -> V_2 . V_41 = V_50 ;
case V_50 :
break;
case V_54 :
F_26 ( & V_13 -> V_2 ) ;
return - V_80 ;
default:
F_26 ( & V_13 -> V_2 ) ;
return - V_55 ;
}
V_63 = F_29 ( V_1 , V_59 , V_60 , V_61 ,
V_81 ) ;
if ( F_19 ( V_63 ) ) {
F_26 ( & V_13 -> V_2 ) ;
F_27 ( L_13 , F_20 ( V_63 ) ) ;
return F_20 ( V_63 ) ;
}
V_13 -> V_63 = V_63 ;
V_13 -> V_39 = F_21 ( V_15 -> V_44 ) ;
V_13 -> V_2 . V_41 = V_54 ;
F_26 ( & V_13 -> V_2 ) ;
return 0 ;
}
static int F_48 ( struct V_82 * V_83 , struct V_33 * V_1 ,
struct V_84 * V_85 , V_4 V_16 )
{
struct V_58 * V_63 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_40 ;
F_4 ( L_14 , V_13 -> V_2 . V_41 , V_16 ) ;
if ( V_85 -> V_86 & V_87 )
return - V_88 ;
if ( V_85 -> V_89 ) {
V_40 = F_11 ( V_13 , V_85 -> V_89 , V_85 -> V_90 ) ;
if ( V_40 < 0 ) {
F_27 ( L_12 , V_40 ) ;
return V_40 ;
}
}
V_63 = NULL ;
F_17 ( & V_13 -> V_2 ) ;
if ( V_85 -> V_89 ) {
V_40 = - V_80 ;
V_63 = F_29 ( V_1 , V_85 -> V_89 ,
V_85 -> V_90 , 0 , V_81 ) ;
if ( F_19 ( V_63 ) ) {
V_40 = F_20 ( V_63 ) ;
V_63 = NULL ;
goto V_77;
}
} else {
V_63 = V_13 -> V_63 ;
if ( V_63 )
F_37 ( & V_63 -> V_74 ) ;
}
switch ( V_13 -> V_2 . V_41 ) {
case V_57 :
if ( ! V_85 -> V_89 ) {
V_40 = F_49 ( V_83 , V_13 , V_85 , V_16 ) ;
break;
}
case V_49 :
case V_50 :
if ( ! V_85 -> V_89 ) {
V_40 = - V_73 ;
break;
}
case V_54 :
V_40 = F_50 ( V_83 , V_13 , V_63 , V_85 , V_16 ) ;
break;
default:
V_40 = - V_73 ;
break;
}
V_77:
F_26 ( & V_13 -> V_2 ) ;
if ( V_63 )
F_41 ( V_63 ) ;
F_27 ( L_5 , V_40 ) ;
return V_40 ;
}
static int F_51 ( struct V_33 * V_1 , int V_91 , int V_92 ,
char T_4 * V_93 , unsigned int V_94 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned V_95 ;
int V_40 ;
F_4 ( L_15 , V_91 , V_92 , V_94 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_40 = - V_88 ;
if ( V_91 == V_96 ) {
switch ( V_92 ) {
case V_97 :
V_40 = - V_17 ;
if ( V_94 != 0 )
goto error;
V_40 = - V_80 ;
if ( V_13 -> V_2 . V_41 != V_42 )
goto error;
F_52 ( V_98 , & V_13 -> V_61 ) ;
goto V_99;
case V_100 :
V_40 = - V_17 ;
if ( V_13 -> V_67 )
goto error;
V_40 = - V_80 ;
if ( V_13 -> V_2 . V_41 != V_42 )
goto error;
V_40 = F_53 ( V_13 , V_93 , V_94 ) ;
goto error;
case V_101 :
V_40 = - V_17 ;
if ( V_13 -> V_67 )
goto error;
V_40 = - V_80 ;
if ( V_13 -> V_2 . V_41 != V_42 )
goto error;
V_40 = F_54 ( V_13 , V_93 , V_94 ) ;
goto error;
case V_102 :
V_40 = - V_17 ;
if ( V_94 != sizeof( unsigned ) )
goto error;
V_40 = - V_80 ;
if ( V_13 -> V_2 . V_41 != V_42 )
goto error;
V_40 = F_55 ( V_95 ,
( unsigned T_4 * ) V_93 ) ;
if ( V_40 < 0 )
goto error;
V_40 = - V_17 ;
if ( V_95 > V_103 )
goto error;
V_13 -> V_95 = V_95 ;
goto V_99;
default:
break;
}
}
V_99:
V_40 = 0 ;
error:
F_26 ( & V_13 -> V_2 ) ;
return V_40 ;
}
static unsigned int F_56 ( struct V_104 * V_104 , struct V_33 * V_1 ,
T_5 * V_9 )
{
unsigned int V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
F_57 ( V_104 , F_58 ( V_2 ) , V_9 ) ;
V_105 = 0 ;
if ( ! F_59 ( & V_2 -> V_106 ) )
V_105 |= V_107 | V_108 ;
if ( F_1 ( V_2 ) )
V_105 |= V_109 | V_110 ;
return V_105 ;
}
static int F_60 ( struct V_111 * V_111 , struct V_33 * V_1 , int V_112 ,
int V_113 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_112 ) ;
if ( ! F_61 ( V_111 , & V_114 ) )
return - V_20 ;
if ( V_112 != V_115 )
return - V_116 ;
if ( V_1 -> type != V_22 )
return - V_23 ;
V_1 -> V_117 = & V_118 ;
V_1 -> V_119 = V_120 ;
V_2 = F_62 ( V_111 , V_121 , V_81 , & V_122 ) ;
if ( ! V_2 )
return - V_123 ;
F_63 ( V_1 , V_2 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_124 = F_3 ;
V_2 -> V_56 = V_125 ;
V_2 -> V_126 = V_127 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_28 = V_112 ;
V_13 -> V_128 = V_129 ;
F_64 ( & V_13 -> V_47 ) ;
F_64 ( & V_13 -> V_130 ) ;
F_64 ( & V_13 -> V_131 ) ;
F_65 ( & V_13 -> V_132 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_27 ( L_16 , V_13 ) ;
return 0 ;
}
static void V_127 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_66 ( & V_2 -> V_106 ) ;
F_67 ( F_2 ( & V_2 -> V_3 ) ) ;
F_67 ( ! F_68 ( V_2 ) ) ;
F_67 ( V_2 -> V_133 ) ;
if ( ! F_69 ( V_2 , V_134 ) ) {
F_70 ( L_17 , V_2 ) ;
return;
}
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_18 , V_2 , V_2 -> V_41 , F_2 ( & V_2 -> V_135 ) ) ;
F_72 ( V_2 ) ;
V_2 -> V_136 = V_137 ;
F_73 ( & V_2 -> V_106 . V_138 ) ;
V_2 -> V_41 = V_139 ;
F_74 ( & V_2 -> V_106 . V_138 ) ;
F_47 ( V_13 -> V_47 . V_140 , != , V_141 ) ;
if ( ! F_75 ( & V_13 -> V_47 ) ) {
F_22 ( & V_13 -> V_37 -> V_45 ) ;
F_76 ( & V_13 -> V_47 ) ;
F_25 ( & V_13 -> V_37 -> V_45 ) ;
}
F_77 ( V_13 ) ;
F_78 ( V_142 ) ;
F_66 ( & V_2 -> V_106 ) ;
if ( V_13 -> V_143 ) {
F_79 ( V_13 -> V_143 ) ;
V_13 -> V_143 = NULL ;
}
if ( V_13 -> V_70 ) {
F_40 ( V_13 -> V_63 , V_13 -> V_70 ) ;
V_13 -> V_70 = NULL ;
}
if ( V_13 -> V_63 ) {
F_41 ( V_13 -> V_63 ) ;
V_13 -> V_63 = NULL ;
}
if ( V_13 -> V_37 ) {
F_80 ( V_13 -> V_37 ) ;
V_13 -> V_37 = NULL ;
}
F_81 ( V_13 -> V_67 ) ;
V_13 -> V_67 = NULL ;
F_81 ( V_13 -> V_144 ) ;
V_13 -> V_144 = NULL ;
F_82 ( V_2 ) ;
F_27 ( L_4 ) ;
return 0 ;
}
static int F_83 ( struct V_33 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_19 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_71 ( V_2 ) ;
}
static int T_6 F_84 ( void )
{
struct V_145 * V_146 ;
int V_40 = - 1 ;
F_85 ( sizeof( struct V_147 ) > sizeof( V_146 -> V_148 ) ) ;
V_149 = F_86 ( F_87 () ) ;
V_40 = - V_123 ;
V_150 = F_88 (
L_20 , sizeof( struct V_66 ) , 0 ,
V_151 , NULL ) ;
if ( ! V_150 ) {
F_70 ( V_152 L_21 ) ;
goto V_153;
}
V_142 = F_89 ( L_22 , 0 , 1 ) ;
if ( ! V_142 ) {
F_70 ( V_152 L_23 ) ;
goto V_154;
}
V_40 = F_90 ( & V_122 , 1 ) ;
if ( V_40 < 0 ) {
F_70 ( V_155 L_24 ) ;
goto V_156;
}
V_40 = F_91 ( & V_157 ) ;
if ( V_40 < 0 ) {
F_70 ( V_155 L_25 ) ;
goto V_158;
}
V_40 = F_92 ( & V_159 ) ;
if ( V_40 < 0 ) {
F_70 ( V_155 L_26 ) ;
goto V_160;
}
V_40 = F_92 ( & V_161 ) ;
if ( V_40 < 0 ) {
F_70 ( V_155 L_27 ) ;
goto V_162;
}
#ifdef F_93
F_94 ( & V_114 , L_28 , 0 , & V_163 ) ;
F_94 ( & V_114 , L_29 , 0 , & V_164 ) ;
#endif
return 0 ;
V_162:
F_95 ( & V_159 ) ;
V_160:
F_96 ( V_121 ) ;
V_158:
F_97 ( & V_122 ) ;
V_156:
F_98 ( V_142 ) ;
V_154:
F_99 ( V_150 ) ;
V_153:
return V_40 ;
}
static void T_7 F_100 ( void )
{
F_4 ( L_11 ) ;
F_95 ( & V_161 ) ;
F_95 ( & V_159 ) ;
F_96 ( V_121 ) ;
F_97 ( & V_122 ) ;
F_101 () ;
F_102 () ;
F_103 () ;
F_104 () ;
F_105 () ;
F_47 ( F_2 ( & V_165 ) , == , 0 ) ;
F_13 ( L_30 ) ;
F_78 ( V_142 ) ;
F_106 ( & V_114 , L_29 ) ;
F_106 ( & V_114 , L_28 ) ;
F_98 ( V_142 ) ;
F_99 ( V_150 ) ;
F_27 ( L_11 ) ;
}
