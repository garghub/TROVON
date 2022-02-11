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
case V_59 :
if ( V_51 == 0 ) {
V_13 -> V_2 . V_42 = V_60 ;
V_2 -> V_57 = 0 ;
F_31 ( V_13 ) ;
V_41 = 0 ;
break;
}
default:
V_41 = - V_61 ;
break;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
struct V_62 * F_32 ( struct V_34 * V_1 ,
struct V_14 * V_15 ,
struct V_63 * V_63 ,
unsigned long V_64 ,
T_2 V_65 ,
T_3 V_66 )
{
struct V_67 V_68 ;
struct V_62 * V_69 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_7 , F_33 ( V_63 ) , V_64 ) ;
V_41 = F_11 ( V_13 , V_15 , sizeof( * V_15 ) ) ;
if ( V_41 < 0 )
return F_34 ( V_41 ) ;
F_17 ( & V_13 -> V_2 ) ;
if ( ! V_63 )
V_63 = V_13 -> V_63 ;
if ( V_63 && ! V_63 -> V_70 . V_71 [ 0 ] )
V_63 = NULL ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_38 = V_13 -> V_38 ;
V_68 . V_63 = V_63 ;
V_68 . V_72 = 0 ;
V_68 . V_73 = false ;
V_68 . V_39 = V_15 -> V_40 ;
V_69 = F_35 ( V_13 , & V_68 , V_15 , V_64 , V_65 ) ;
if ( ! F_19 ( V_69 ) )
V_69 -> V_66 = V_66 ;
F_36 ( & V_69 -> V_74 ) ;
F_26 ( L_8 , V_69 ) ;
return V_69 ;
}
void F_37 ( struct V_34 * V_1 , struct V_62 * V_69 )
{
F_4 ( L_9 , V_69 -> V_75 , F_2 ( & V_69 -> V_76 ) ) ;
F_38 ( & V_69 -> V_74 ) ;
F_39 ( F_16 ( V_1 -> V_2 ) , V_69 ) ;
F_36 ( & V_69 -> V_74 ) ;
F_40 ( V_69 , V_77 ) ;
}
void F_41 (
struct V_34 * V_1 ,
T_4 V_78 ,
T_5 V_79 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
V_13 -> V_78 = V_78 ;
V_13 -> V_79 = V_79 ;
}
static int F_42 ( struct V_34 * V_1 , struct V_35 * V_80 ,
int V_81 , int V_82 )
{
struct V_14 * V_15 = (struct V_14 * ) V_80 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_10 , V_13 , V_80 , V_81 , V_82 ) ;
V_41 = F_11 ( V_13 , V_15 , V_81 ) ;
if ( V_41 < 0 ) {
F_26 ( L_11 , V_41 ) ;
return V_41 ;
}
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_83 ;
if ( F_43 ( V_84 , & V_13 -> V_82 ) )
goto error;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_2 . V_42 = V_85 ;
case V_85 :
case V_49 :
break;
default:
V_41 = - V_61 ;
goto error;
}
V_13 -> V_86 = * V_15 ;
F_44 ( V_84 , & V_13 -> V_82 ) ;
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_45 ( struct V_34 * V_1 , struct V_87 * V_88 , V_4 V_16 )
{
struct V_37 * V_38 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_12 , V_13 -> V_2 . V_42 , V_16 ) ;
if ( V_88 -> V_89 & V_90 )
return - V_91 ;
if ( V_88 -> V_92 ) {
V_41 = F_11 ( V_13 , V_88 -> V_92 , V_88 -> V_93 ) ;
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
V_13 -> V_2 . V_42 = V_85 ;
case V_85 :
case V_49 :
if ( ! V_88 -> V_92 &&
F_43 ( V_84 , & V_13 -> V_82 ) ) {
V_88 -> V_92 = & V_13 -> V_86 ;
V_88 -> V_93 = sizeof( V_13 -> V_86 ) ;
}
case V_48 :
case V_59 :
V_41 = F_46 ( V_13 , V_88 , V_16 ) ;
goto V_94;
default:
V_41 = - V_18 ;
goto V_44;
}
V_44:
F_25 ( & V_13 -> V_2 ) ;
V_94:
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_47 ( struct V_34 * V_1 , int V_95 , int V_96 ,
char T_6 * V_97 , unsigned int V_98 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned int V_99 ;
int V_41 ;
F_4 ( L_13 , V_95 , V_96 , V_98 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_91 ;
if ( V_95 == V_100 ) {
switch ( V_96 ) {
case V_101 :
V_41 = - V_18 ;
if ( V_98 != 0 )
goto error;
V_41 = - V_83 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_13 -> V_73 = true ;
goto V_102;
case V_103 :
V_41 = - V_18 ;
if ( V_13 -> V_63 )
goto error;
V_41 = - V_83 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_48 ( V_13 , V_97 , V_98 ) ;
goto error;
case V_104 :
V_41 = - V_18 ;
if ( V_13 -> V_63 )
goto error;
V_41 = - V_83 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_49 ( V_13 , V_97 , V_98 ) ;
goto error;
case V_105 :
V_41 = - V_18 ;
if ( V_98 != sizeof( unsigned int ) )
goto error;
V_41 = - V_83 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_50 ( V_99 ,
( unsigned int T_6 * ) V_97 ) ;
if ( V_41 < 0 )
goto error;
V_41 = - V_18 ;
if ( V_99 > V_106 )
goto error;
V_13 -> V_99 = V_99 ;
goto V_102;
default:
break;
}
}
V_102:
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static unsigned int F_51 ( struct V_107 * V_107 , struct V_34 * V_1 ,
T_7 * V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_108 ;
F_52 ( V_107 , F_53 ( V_2 ) , V_9 ) ;
V_108 = 0 ;
if ( ! F_54 ( & V_13 -> V_109 ) )
V_108 |= V_110 | V_111 ;
if ( F_1 ( V_2 ) )
V_108 |= V_112 | V_113 ;
return V_108 ;
}
static int F_55 ( struct V_114 * V_114 , struct V_34 * V_1 , int V_115 ,
int V_116 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_115 ) ;
if ( ! F_56 ( V_114 , & V_117 ) )
return - V_21 ;
if ( V_115 != V_118 &&
F_57 ( F_13 ) && V_115 != V_119 )
return - V_120 ;
if ( V_1 -> type != V_23 )
return - V_24 ;
V_1 -> V_121 = & V_122 ;
V_1 -> V_123 = V_124 ;
V_2 = F_58 ( V_114 , V_125 , V_58 , & V_126 , V_116 ) ;
if ( ! V_2 )
return - V_127 ;
F_59 ( V_1 , V_2 ) ;
F_60 ( V_2 , V_128 ) ;
V_2 -> V_42 = V_43 ;
V_2 -> V_129 = F_3 ;
V_2 -> V_57 = 0 ;
V_2 -> V_130 = V_131 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_28 = V_115 ;
V_13 -> V_132 = V_133 ;
F_61 ( & V_13 -> V_134 ) ;
F_62 ( & V_13 -> V_135 ) ;
F_62 ( & V_13 -> V_136 ) ;
F_62 ( & V_13 -> V_109 ) ;
F_63 ( & V_13 -> V_137 ) ;
F_63 ( & V_13 -> V_138 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_26 ( L_14 , V_13 ) ;
return 0 ;
}
static int F_64 ( struct V_34 * V_1 , int V_82 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_41 = 0 ;
F_4 ( L_6 , V_2 , V_82 ) ;
if ( V_82 != V_139 )
return - V_91 ;
if ( V_2 -> V_42 == V_140 )
return - V_141 ;
F_17 ( V_2 ) ;
F_65 ( & V_2 -> V_142 . V_143 ) ;
if ( V_2 -> V_42 < V_140 ) {
V_2 -> V_42 = V_140 ;
V_2 -> V_144 = V_145 ;
} else {
V_41 = - V_141 ;
}
F_66 ( & V_2 -> V_142 . V_143 ) ;
F_31 ( V_13 ) ;
F_25 ( V_2 ) ;
return V_41 ;
}
static void V_131 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_67 ( & V_2 -> V_142 ) ;
F_68 ( F_2 ( & V_2 -> V_3 ) ) ;
F_68 ( ! F_69 ( V_2 ) ) ;
F_68 ( V_2 -> V_146 ) ;
if ( ! F_70 ( V_2 , V_147 ) ) {
F_71 ( L_15 , V_2 ) ;
return;
}
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_16 , V_2 , V_2 -> V_42 , F_2 ( & V_2 -> V_148 ) ) ;
F_73 ( V_2 ) ;
V_2 -> V_144 = V_145 ;
F_65 ( & V_2 -> V_142 . V_143 ) ;
V_2 -> V_42 = V_140 ;
F_66 ( & V_2 -> V_142 . V_143 ) ;
if ( V_13 -> V_38 && F_22 ( V_13 -> V_38 -> V_46 ) == V_13 ) {
F_21 ( & V_13 -> V_38 -> V_45 ) ;
F_23 ( V_13 -> V_38 -> V_46 , NULL ) ;
F_24 ( & V_13 -> V_38 -> V_45 ) ;
}
F_31 ( V_13 ) ;
F_74 ( V_13 ) ;
F_75 ( V_149 ) ;
F_67 ( & V_2 -> V_142 ) ;
F_27 ( V_13 -> V_38 ) ;
V_13 -> V_38 = NULL ;
F_76 ( V_13 -> V_63 ) ;
V_13 -> V_63 = NULL ;
F_76 ( V_13 -> V_150 ) ;
V_13 -> V_150 = NULL ;
F_77 ( V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
}
static int F_78 ( struct V_34 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_17 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_72 ( V_2 ) ;
}
static int T_8 F_79 ( void )
{
int V_41 = - 1 ;
unsigned int V_151 ;
F_80 ( sizeof( struct V_152 ) > F_81 ( struct V_153 , V_154 ) ) ;
F_82 ( & V_155 , sizeof( V_155 ) ) ;
V_155 |= V_156 ;
F_82 ( & V_151 , sizeof( V_151 ) ) ;
V_151 &= 0x3fffffff ;
if ( V_151 == 0 )
V_151 = 1 ;
F_83 ( & V_157 , V_151 ) ;
V_41 = - V_127 ;
V_158 = F_84 (
L_18 , sizeof( struct V_62 ) , 0 ,
V_159 , NULL ) ;
if ( ! V_158 ) {
F_85 ( L_19 ) ;
goto V_160;
}
V_149 = F_86 ( L_20 , 0 , 1 ) ;
if ( ! V_149 ) {
F_85 ( L_21 ) ;
goto V_161;
}
V_41 = F_87 () ;
if ( V_41 < 0 ) {
F_88 ( L_22 ) ;
goto V_162;
}
V_41 = F_89 ( & V_126 , 1 ) ;
if ( V_41 < 0 ) {
F_88 ( L_23 ) ;
goto V_163;
}
V_41 = F_90 ( & V_164 ) ;
if ( V_41 < 0 ) {
F_88 ( L_24 ) ;
goto V_165;
}
V_41 = F_91 ( & V_166 ) ;
if ( V_41 < 0 ) {
F_88 ( L_25 ) ;
goto V_167;
}
V_41 = F_91 ( & V_168 ) ;
if ( V_41 < 0 ) {
F_88 ( L_26 ) ;
goto V_169;
}
V_41 = F_92 () ;
if ( V_41 < 0 ) {
F_88 ( L_27 ) ;
goto V_170;
}
#ifdef F_93
F_94 ( L_28 , 0 , V_117 . V_171 , & V_172 ) ;
F_94 ( L_29 , 0 , V_117 . V_171 ,
& V_173 ) ;
#endif
return 0 ;
V_170:
F_95 ( & V_168 ) ;
V_169:
F_95 ( & V_166 ) ;
V_167:
F_96 ( V_125 ) ;
V_165:
F_97 ( & V_126 ) ;
V_163:
F_98 () ;
V_162:
F_99 ( V_149 ) ;
V_161:
F_100 ( V_158 ) ;
V_160:
return V_41 ;
}
static void T_9 F_101 ( void )
{
F_4 ( L_30 ) ;
F_102 () ;
F_95 ( & V_168 ) ;
F_95 ( & V_166 ) ;
F_96 ( V_125 ) ;
F_97 ( & V_126 ) ;
F_103 () ;
F_104 () ;
F_105 ( F_2 ( & V_174 ) , == , 0 ) ;
F_105 ( F_2 ( & V_175 ) , == , 0 ) ;
F_106 () ;
F_107 ( L_29 , V_117 . V_171 ) ;
F_107 ( L_28 , V_117 . V_171 ) ;
F_99 ( V_149 ) ;
F_98 () ;
F_100 ( V_158 ) ;
F_26 ( L_30 ) ;
}
