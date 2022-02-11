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
unsigned int V_17 ;
if ( V_16 < sizeof( struct V_14 ) )
return - V_18 ;
if ( V_15 -> V_19 != V_20 )
return - V_21 ;
if ( V_15 -> V_22 != V_23 )
return - V_24 ;
V_16 -= F_12 ( struct V_14 , V_25 ) ;
if ( V_15 -> V_26 < sizeof( V_27 ) ||
V_15 -> V_26 > V_16 )
return - V_18 ;
if ( V_15 -> V_25 . V_28 != V_13 -> V_28 )
return - V_21 ;
switch ( V_15 -> V_25 . V_28 ) {
case V_29 :
if ( V_15 -> V_26 < sizeof( struct V_30 ) )
return - V_18 ;
V_17 = F_12 ( struct V_14 , V_25 . sin . V_31 ) ;
break;
#ifdef F_13
case V_32 :
if ( V_15 -> V_26 < sizeof( struct V_33 ) )
return - V_18 ;
V_17 = F_12 ( struct V_14 , V_25 ) +
sizeof( struct V_33 ) ;
break;
#endif
default:
return - V_21 ;
}
if ( V_17 < V_16 )
memset ( ( void * ) V_15 + V_17 , 0 , V_16 - V_17 ) ;
F_14 ( L_2 , & V_15 -> V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_1 , struct V_35 * V_36 , int V_16 )
{
struct V_14 * V_15 = (struct V_14 * ) V_36 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_37 * V_38 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
T_1 V_39 = V_15 -> V_40 ;
int V_41 ;
F_4 ( L_3 , V_13 , V_36 , V_16 ) ;
V_41 = F_11 ( V_13 , V_15 , V_16 ) ;
if ( V_41 < 0 )
goto error;
F_17 ( & V_13 -> V_2 ) ;
if ( V_13 -> V_2 . V_42 != V_43 ) {
V_41 = - V_18 ;
goto V_44;
}
memcpy ( & V_13 -> V_15 , V_15 , sizeof( V_13 -> V_15 ) ) ;
V_38 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_38 ) ) {
V_41 = F_20 ( V_38 ) ;
goto V_44;
}
if ( V_39 ) {
F_21 ( & V_38 -> V_45 ) ;
if ( F_22 ( V_38 -> V_46 ) )
goto V_47;
V_13 -> V_38 = V_38 ;
F_23 ( V_38 -> V_46 , V_13 ) ;
F_24 ( & V_38 -> V_45 ) ;
V_13 -> V_2 . V_42 = V_48 ;
} else {
V_13 -> V_38 = V_38 ;
V_13 -> V_2 . V_42 = V_49 ;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
V_47:
F_24 ( & V_38 -> V_45 ) ;
F_27 ( V_38 ) ;
V_41 = - V_50 ;
V_44:
F_25 ( & V_13 -> V_2 ) ;
error:
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_28 ( struct V_34 * V_1 , int V_51 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_52 , V_53 ;
int V_41 ;
F_4 ( L_6 , V_13 , V_51 ) ;
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_41 = - V_54 ;
break;
case V_48 :
ASSERT ( V_13 -> V_38 != NULL ) ;
V_52 = F_29 ( V_55 ) ;
V_41 = - V_18 ;
if ( V_51 == V_56 )
V_51 = V_52 ;
else if ( V_51 < 0 || V_51 > V_52 )
break;
V_53 = V_2 -> V_57 ;
V_2 -> V_57 = V_51 ;
V_41 = F_30 ( V_13 , V_58 ) ;
if ( V_41 == 0 )
V_13 -> V_2 . V_42 = V_59 ;
else
V_2 -> V_57 = V_53 ;
break;
default:
V_41 = - V_60 ;
break;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
struct V_61 * F_31 ( struct V_34 * V_1 ,
struct V_14 * V_15 ,
struct V_62 * V_62 ,
unsigned long V_63 ,
T_2 V_64 ,
T_3 V_65 )
{
struct V_66 V_67 ;
struct V_61 * V_68 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_7 , F_32 ( V_62 ) , V_63 ) ;
V_41 = F_11 ( V_13 , V_15 , sizeof( * V_15 ) ) ;
if ( V_41 < 0 )
return F_33 ( V_41 ) ;
F_17 ( & V_13 -> V_2 ) ;
if ( ! V_62 )
V_62 = V_13 -> V_62 ;
if ( V_62 && ! V_62 -> V_69 . V_70 [ 0 ] )
V_62 = NULL ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_38 = V_13 -> V_38 ;
V_67 . V_62 = V_62 ;
V_67 . V_71 = 0 ;
V_67 . V_72 = false ;
V_67 . V_39 = V_15 -> V_40 ;
V_68 = F_34 ( V_13 , & V_67 , V_15 , V_63 , V_64 ) ;
if ( ! F_19 ( V_68 ) )
V_68 -> V_65 = V_65 ;
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_8 , V_68 ) ;
return V_68 ;
}
void F_35 ( struct V_34 * V_1 , struct V_61 * V_68 )
{
F_4 ( L_9 , V_68 -> V_73 , F_2 ( & V_68 -> V_74 ) ) ;
F_36 ( F_16 ( V_1 -> V_2 ) , V_68 ) ;
F_37 ( V_68 , V_75 ) ;
}
void F_38 (
struct V_34 * V_1 ,
T_4 V_76 ,
T_5 V_77 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
V_13 -> V_76 = V_76 ;
V_13 -> V_77 = V_77 ;
}
static int F_39 ( struct V_34 * V_1 , struct V_35 * V_78 ,
int V_79 , int V_80 )
{
struct V_14 * V_15 = (struct V_14 * ) V_78 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_10 , V_13 , V_78 , V_79 , V_80 ) ;
V_41 = F_11 ( V_13 , V_15 , V_79 ) ;
if ( V_41 < 0 ) {
F_26 ( L_11 , V_41 ) ;
return V_41 ;
}
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_81 ;
if ( F_40 ( V_82 , & V_13 -> V_80 ) )
goto error;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_2 . V_42 = V_83 ;
case V_83 :
case V_49 :
break;
default:
V_41 = - V_60 ;
goto error;
}
V_13 -> V_84 = * V_15 ;
F_41 ( V_82 , & V_13 -> V_80 ) ;
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_42 ( struct V_34 * V_1 , struct V_85 * V_86 , V_4 V_16 )
{
struct V_37 * V_38 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_12 , V_13 -> V_2 . V_42 , V_16 ) ;
if ( V_86 -> V_87 & V_88 )
return - V_89 ;
if ( V_86 -> V_90 ) {
V_41 = F_11 ( V_13 , V_86 -> V_90 , V_86 -> V_91 ) ;
if ( V_41 < 0 ) {
F_26 ( L_11 , V_41 ) ;
return V_41 ;
}
}
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_15 . V_19 = V_20 ;
V_13 -> V_15 . V_40 = 0 ;
V_13 -> V_15 . V_22 = V_23 ;
V_13 -> V_15 . V_25 . V_28 = V_13 -> V_28 ;
switch ( V_13 -> V_28 ) {
case V_29 :
V_13 -> V_15 . V_26 = sizeof( struct V_30 ) ;
break;
#ifdef F_13
case V_32 :
V_13 -> V_15 . V_26 = sizeof( struct V_33 ) ;
break;
#endif
default:
V_41 = - V_21 ;
goto V_44;
}
V_38 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_38 ) ) {
V_41 = F_20 ( V_38 ) ;
goto V_44;
}
V_13 -> V_38 = V_38 ;
V_13 -> V_2 . V_42 = V_83 ;
case V_83 :
case V_49 :
if ( ! V_86 -> V_90 &&
F_40 ( V_82 , & V_13 -> V_80 ) ) {
V_86 -> V_90 = & V_13 -> V_84 ;
V_86 -> V_91 = sizeof( V_13 -> V_84 ) ;
}
case V_48 :
case V_59 :
V_41 = F_43 ( V_13 , V_86 , V_16 ) ;
break;
default:
V_41 = - V_18 ;
break;
}
V_44:
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_44 ( struct V_34 * V_1 , int V_92 , int V_93 ,
char T_6 * V_94 , unsigned int V_95 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned int V_96 ;
int V_41 ;
F_4 ( L_13 , V_92 , V_93 , V_95 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_89 ;
if ( V_92 == V_97 ) {
switch ( V_93 ) {
case V_98 :
V_41 = - V_18 ;
if ( V_95 != 0 )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_13 -> V_72 = true ;
goto V_99;
case V_100 :
V_41 = - V_18 ;
if ( V_13 -> V_62 )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_45 ( V_13 , V_94 , V_95 ) ;
goto error;
case V_101 :
V_41 = - V_18 ;
if ( V_13 -> V_62 )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_46 ( V_13 , V_94 , V_95 ) ;
goto error;
case V_102 :
V_41 = - V_18 ;
if ( V_95 != sizeof( unsigned int ) )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_47 ( V_96 ,
( unsigned int T_6 * ) V_94 ) ;
if ( V_41 < 0 )
goto error;
V_41 = - V_18 ;
if ( V_96 > V_103 )
goto error;
V_13 -> V_96 = V_96 ;
goto V_99;
default:
break;
}
}
V_99:
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static unsigned int F_48 ( struct V_104 * V_104 , struct V_34 * V_1 ,
T_7 * V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_105 ;
F_49 ( V_104 , F_50 ( V_2 ) , V_9 ) ;
V_105 = 0 ;
if ( ! F_51 ( & V_13 -> V_106 ) )
V_105 |= V_107 | V_108 ;
if ( F_1 ( V_2 ) )
V_105 |= V_109 | V_110 ;
return V_105 ;
}
static int F_52 ( struct V_111 * V_111 , struct V_34 * V_1 , int V_112 ,
int V_113 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_112 ) ;
if ( ! F_53 ( V_111 , & V_114 ) )
return - V_21 ;
if ( V_112 != V_115 &&
F_54 ( F_13 ) && V_112 != V_116 )
return - V_117 ;
if ( V_1 -> type != V_23 )
return - V_24 ;
V_1 -> V_118 = & V_119 ;
V_1 -> V_120 = V_121 ;
V_2 = F_55 ( V_111 , V_122 , V_58 , & V_123 , V_113 ) ;
if ( ! V_2 )
return - V_124 ;
F_56 ( V_1 , V_2 ) ;
F_57 ( V_2 , V_125 ) ;
V_2 -> V_42 = V_43 ;
V_2 -> V_126 = F_3 ;
V_2 -> V_57 = 0 ;
V_2 -> V_127 = V_128 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_28 = V_112 ;
V_13 -> V_129 = V_130 ;
F_58 ( & V_13 -> V_131 ) ;
F_59 ( & V_13 -> V_132 ) ;
F_59 ( & V_13 -> V_133 ) ;
F_59 ( & V_13 -> V_106 ) ;
F_60 ( & V_13 -> V_134 ) ;
F_60 ( & V_13 -> V_135 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_26 ( L_14 , V_13 ) ;
return 0 ;
}
static int F_61 ( struct V_34 * V_1 , int V_80 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_41 = 0 ;
F_4 ( L_6 , V_2 , V_80 ) ;
if ( V_80 != V_136 )
return - V_89 ;
if ( V_2 -> V_42 == V_137 )
return - V_138 ;
F_17 ( V_2 ) ;
F_62 ( & V_2 -> V_139 . V_140 ) ;
if ( V_2 -> V_42 < V_137 ) {
V_2 -> V_42 = V_137 ;
V_2 -> V_141 = V_142 ;
} else {
V_41 = - V_138 ;
}
F_63 ( & V_2 -> V_139 . V_140 ) ;
F_64 ( V_13 ) ;
F_25 ( V_2 ) ;
return V_41 ;
}
static void V_128 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_65 ( & V_2 -> V_139 ) ;
F_66 ( F_2 ( & V_2 -> V_3 ) ) ;
F_66 ( ! F_67 ( V_2 ) ) ;
F_66 ( V_2 -> V_143 ) ;
if ( ! F_68 ( V_2 , V_144 ) ) {
F_69 ( L_15 , V_2 ) ;
return;
}
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_16 , V_2 , V_2 -> V_42 , F_2 ( & V_2 -> V_145 ) ) ;
F_71 ( V_2 ) ;
V_2 -> V_141 = V_142 ;
F_62 ( & V_2 -> V_139 . V_140 ) ;
V_2 -> V_42 = V_137 ;
F_63 ( & V_2 -> V_139 . V_140 ) ;
if ( V_13 -> V_38 && F_22 ( V_13 -> V_38 -> V_46 ) == V_13 ) {
F_21 ( & V_13 -> V_38 -> V_45 ) ;
F_23 ( V_13 -> V_38 -> V_46 , NULL ) ;
F_24 ( & V_13 -> V_38 -> V_45 ) ;
}
F_64 ( V_13 ) ;
F_72 ( V_13 ) ;
F_73 ( V_146 ) ;
F_65 ( & V_2 -> V_139 ) ;
F_27 ( V_13 -> V_38 ) ;
V_13 -> V_38 = NULL ;
F_74 ( V_13 -> V_62 ) ;
V_13 -> V_62 = NULL ;
F_74 ( V_13 -> V_147 ) ;
V_13 -> V_147 = NULL ;
F_75 ( V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
}
static int F_76 ( struct V_34 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_17 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_70 ( V_2 ) ;
}
static int T_8 F_77 ( void )
{
int V_41 = - 1 ;
unsigned int V_148 ;
F_78 ( sizeof( struct V_149 ) > F_79 ( struct V_150 , V_151 ) ) ;
F_80 ( & V_152 , sizeof( V_152 ) ) ;
V_152 |= V_153 ;
F_80 ( & V_148 , sizeof( V_148 ) ) ;
V_148 &= 0x3fffffff ;
if ( V_148 == 0 )
V_148 = 1 ;
F_81 ( & V_154 , V_148 ) ;
V_41 = - V_124 ;
V_155 = F_82 (
L_18 , sizeof( struct V_61 ) , 0 ,
V_156 , NULL ) ;
if ( ! V_155 ) {
F_83 ( L_19 ) ;
goto V_157;
}
V_146 = F_84 ( L_20 , 0 , 1 ) ;
if ( ! V_146 ) {
F_83 ( L_21 ) ;
goto V_158;
}
V_41 = F_85 () ;
if ( V_41 < 0 ) {
F_86 ( L_22 ) ;
goto V_159;
}
V_41 = F_87 ( & V_123 , 1 ) ;
if ( V_41 < 0 ) {
F_86 ( L_23 ) ;
goto V_160;
}
V_41 = F_88 ( & V_161 ) ;
if ( V_41 < 0 ) {
F_86 ( L_24 ) ;
goto V_162;
}
V_41 = F_89 ( & V_163 ) ;
if ( V_41 < 0 ) {
F_86 ( L_25 ) ;
goto V_164;
}
V_41 = F_89 ( & V_165 ) ;
if ( V_41 < 0 ) {
F_86 ( L_26 ) ;
goto V_166;
}
V_41 = F_90 () ;
if ( V_41 < 0 ) {
F_86 ( L_27 ) ;
goto V_167;
}
#ifdef F_91
F_92 ( L_28 , 0 , V_114 . V_168 , & V_169 ) ;
F_92 ( L_29 , 0 , V_114 . V_168 ,
& V_170 ) ;
#endif
return 0 ;
V_167:
F_93 ( & V_165 ) ;
V_166:
F_93 ( & V_163 ) ;
V_164:
F_94 ( V_122 ) ;
V_162:
F_95 ( & V_123 ) ;
V_160:
F_96 () ;
V_159:
F_97 ( V_146 ) ;
V_158:
F_98 ( V_155 ) ;
V_157:
return V_41 ;
}
static void T_9 F_99 ( void )
{
F_4 ( L_30 ) ;
F_100 () ;
F_93 ( & V_165 ) ;
F_93 ( & V_163 ) ;
F_94 ( V_122 ) ;
F_95 ( & V_123 ) ;
F_101 () ;
F_102 () ;
F_103 ( F_2 ( & V_171 ) , == , 0 ) ;
F_103 ( F_2 ( & V_172 ) , == , 0 ) ;
F_104 () ;
F_105 ( L_29 , V_114 . V_168 ) ;
F_105 ( L_28 , V_114 . V_168 ) ;
F_97 ( V_146 ) ;
F_96 () ;
F_98 ( V_155 ) ;
F_26 ( L_30 ) ;
}
