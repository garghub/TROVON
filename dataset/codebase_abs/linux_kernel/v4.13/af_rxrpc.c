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
struct V_37 * V_38 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
T_1 V_39 = V_15 -> V_40 ;
int V_41 ;
F_4 ( L_3 , V_13 , V_36 , V_16 ) ;
V_41 = F_11 ( V_13 , V_15 , V_16 ) ;
if ( V_41 < 0 )
goto error;
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_15 = * V_15 ;
V_38 = F_18 ( F_19 ( & V_13 -> V_2 ) , & V_13 -> V_15 ) ;
if ( F_20 ( V_38 ) ) {
V_41 = F_21 ( V_38 ) ;
goto V_44;
}
if ( V_39 ) {
F_22 ( & V_38 -> V_45 ) ;
if ( F_23 ( V_38 -> V_46 ) )
goto V_47;
V_13 -> V_38 = V_38 ;
F_24 ( V_38 -> V_46 , V_13 ) ;
F_25 ( & V_38 -> V_45 ) ;
V_13 -> V_2 . V_42 = V_48 ;
} else {
V_13 -> V_38 = V_38 ;
V_13 -> V_2 . V_42 = V_49 ;
}
break;
case V_48 :
V_41 = - V_18 ;
if ( V_39 == 0 )
goto V_44;
V_41 = - V_50 ;
if ( V_39 == V_13 -> V_15 . V_40 )
goto V_44;
V_41 = - V_18 ;
V_15 -> V_40 = V_13 -> V_15 . V_40 ;
if ( memcmp ( V_15 , & V_13 -> V_15 , sizeof( * V_15 ) ) != 0 )
goto V_44;
V_13 -> V_51 = V_39 ;
V_13 -> V_2 . V_42 = V_52 ;
break;
default:
V_41 = - V_18 ;
goto V_44;
}
F_26 ( & V_13 -> V_2 ) ;
F_27 ( L_4 ) ;
return 0 ;
V_47:
F_25 ( & V_38 -> V_45 ) ;
F_28 ( V_38 ) ;
V_41 = - V_50 ;
V_44:
F_26 ( & V_13 -> V_2 ) ;
error:
F_27 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_29 ( struct V_34 * V_1 , int V_53 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_54 , V_55 ;
int V_41 ;
F_4 ( L_6 , V_13 , V_53 ) ;
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_41 = - V_56 ;
break;
case V_48 :
case V_52 :
ASSERT ( V_13 -> V_38 != NULL ) ;
V_54 = F_30 ( V_57 ) ;
V_41 = - V_18 ;
if ( V_53 == V_58 )
V_53 = V_54 ;
else if ( V_53 < 0 || V_53 > V_54 )
break;
V_55 = V_2 -> V_59 ;
V_2 -> V_59 = V_53 ;
V_41 = F_31 ( V_13 , V_60 ) ;
if ( V_41 == 0 )
V_13 -> V_2 . V_42 = V_61 ;
else
V_2 -> V_59 = V_55 ;
break;
case V_61 :
if ( V_53 == 0 ) {
V_13 -> V_2 . V_42 = V_62 ;
V_2 -> V_59 = 0 ;
F_32 ( V_13 ) ;
V_41 = 0 ;
break;
}
default:
V_41 = - V_63 ;
break;
}
F_26 ( & V_13 -> V_2 ) ;
F_27 ( L_5 , V_41 ) ;
return V_41 ;
}
struct V_64 * F_33 ( struct V_34 * V_1 ,
struct V_14 * V_15 ,
struct V_65 * V_65 ,
unsigned long V_66 ,
T_2 V_67 ,
T_3 V_68 ,
T_4 V_69 )
{
struct V_70 V_71 ;
struct V_64 * V_72 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_7 , F_34 ( V_65 ) , V_66 ) ;
V_41 = F_11 ( V_13 , V_15 , sizeof( * V_15 ) ) ;
if ( V_41 < 0 )
return F_35 ( V_41 ) ;
F_17 ( & V_13 -> V_2 ) ;
if ( ! V_65 )
V_65 = V_13 -> V_65 ;
if ( V_65 && ! V_65 -> V_73 . V_74 [ 0 ] )
V_65 = NULL ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_38 = V_13 -> V_38 ;
V_71 . V_65 = V_65 ;
V_71 . V_75 = 0 ;
V_71 . V_76 = false ;
V_71 . V_39 = V_15 -> V_40 ;
V_72 = F_36 ( V_13 , & V_71 , V_15 , V_66 , V_67 ,
V_68 ) ;
if ( ! F_20 ( V_72 ) )
V_72 -> V_69 = V_69 ;
F_37 ( & V_72 -> V_77 ) ;
F_27 ( L_8 , V_72 ) ;
return V_72 ;
}
void F_38 ( struct V_34 * V_1 , struct V_64 * V_72 )
{
F_4 ( L_9 , V_72 -> V_78 , F_39 ( & V_72 -> V_79 ) ) ;
F_40 ( & V_72 -> V_77 ) ;
F_41 ( F_16 ( V_1 -> V_2 ) , V_72 ) ;
F_37 ( & V_72 -> V_77 ) ;
F_42 ( V_72 , V_80 ) ;
}
void F_43 (
struct V_34 * V_1 ,
T_5 V_81 ,
T_6 V_82 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
V_13 -> V_81 = V_81 ;
V_13 -> V_82 = V_82 ;
}
static int F_44 ( struct V_34 * V_1 , struct V_35 * V_83 ,
int V_84 , int V_85 )
{
struct V_14 * V_15 = (struct V_14 * ) V_83 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_10 , V_13 , V_83 , V_84 , V_85 ) ;
V_41 = F_11 ( V_13 , V_15 , V_84 ) ;
if ( V_41 < 0 ) {
F_27 ( L_11 , V_41 ) ;
return V_41 ;
}
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_86 ;
if ( F_45 ( V_87 , & V_13 -> V_85 ) )
goto error;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_2 . V_42 = V_88 ;
case V_88 :
case V_49 :
break;
default:
V_41 = - V_63 ;
goto error;
}
V_13 -> V_89 = * V_15 ;
F_46 ( V_87 , & V_13 -> V_85 ) ;
V_41 = 0 ;
error:
F_26 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_47 ( struct V_34 * V_1 , struct V_90 * V_91 , V_4 V_16 )
{
struct V_37 * V_38 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_12 , V_13 -> V_2 . V_42 , V_16 ) ;
if ( V_91 -> V_92 & V_93 )
return - V_94 ;
if ( V_91 -> V_95 ) {
V_41 = F_11 ( V_13 , V_91 -> V_95 , V_91 -> V_96 ) ;
if ( V_41 < 0 ) {
F_27 ( L_11 , V_41 ) ;
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
V_38 = F_18 ( F_19 ( V_1 -> V_2 ) , & V_13 -> V_15 ) ;
if ( F_20 ( V_38 ) ) {
V_41 = F_21 ( V_38 ) ;
goto V_44;
}
V_13 -> V_38 = V_38 ;
V_13 -> V_2 . V_42 = V_88 ;
case V_88 :
case V_49 :
if ( ! V_91 -> V_95 &&
F_45 ( V_87 , & V_13 -> V_85 ) ) {
V_91 -> V_95 = & V_13 -> V_89 ;
V_91 -> V_96 = sizeof( V_13 -> V_89 ) ;
}
case V_48 :
case V_61 :
V_41 = F_48 ( V_13 , V_91 , V_16 ) ;
goto V_97;
default:
V_41 = - V_18 ;
goto V_44;
}
V_44:
F_26 ( & V_13 -> V_2 ) ;
V_97:
F_27 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_49 ( struct V_34 * V_1 , int V_98 , int V_99 ,
char T_7 * V_100 , unsigned int V_101 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned int V_102 ;
T_1 V_103 [ 2 ] ;
int V_41 ;
F_4 ( L_13 , V_98 , V_99 , V_101 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_94 ;
if ( V_98 == V_104 ) {
switch ( V_99 ) {
case V_105 :
V_41 = - V_18 ;
if ( V_101 != 0 )
goto error;
V_41 = - V_86 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_13 -> V_76 = true ;
goto V_106;
case V_107 :
V_41 = - V_18 ;
if ( V_13 -> V_65 )
goto error;
V_41 = - V_86 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_50 ( V_13 , V_100 , V_101 ) ;
goto error;
case V_108 :
V_41 = - V_18 ;
if ( V_13 -> V_65 )
goto error;
V_41 = - V_86 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_51 ( V_13 , V_100 , V_101 ) ;
goto error;
case V_109 :
V_41 = - V_18 ;
if ( V_101 != sizeof( unsigned int ) )
goto error;
V_41 = - V_86 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_52 ( V_102 ,
( unsigned int T_7 * ) V_100 ) ;
if ( V_41 < 0 )
goto error;
V_41 = - V_18 ;
if ( V_102 > V_110 )
goto error;
V_13 -> V_102 = V_102 ;
goto V_106;
case V_111 :
V_41 = - V_18 ;
if ( V_101 != sizeof( V_103 ) ||
V_13 -> V_103 . V_112 != 0 )
goto error;
V_41 = - V_86 ;
if ( V_13 -> V_2 . V_42 != V_52 )
goto error;
V_41 = - V_113 ;
if ( F_53 ( V_103 , V_100 ,
sizeof( V_103 ) ) != 0 )
goto error;
V_41 = - V_18 ;
if ( ( V_103 [ 0 ] != V_13 -> V_15 . V_40 ||
V_103 [ 1 ] != V_13 -> V_51 ) &&
( V_103 [ 0 ] != V_13 -> V_51 ||
V_103 [ 1 ] != V_13 -> V_15 . V_40 ) )
goto error;
V_13 -> V_103 . V_112 = V_103 [ 0 ] ;
V_13 -> V_103 . V_114 = V_103 [ 1 ] ;
goto V_106;
default:
break;
}
}
V_106:
V_41 = 0 ;
error:
F_26 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_54 ( struct V_34 * V_1 , int V_98 , int V_99 ,
char T_7 * V_100 , int T_7 * V_115 )
{
int V_101 ;
if ( V_98 != V_104 )
return - V_94 ;
if ( F_52 ( V_101 , V_115 ) )
return - V_113 ;
switch ( V_99 ) {
case V_116 :
if ( V_101 < sizeof( int ) )
return - V_117 ;
if ( F_55 ( V_118 - 1 , ( int T_7 * ) V_100 ) ||
F_55 ( sizeof( int ) , V_115 ) )
return - V_113 ;
return 0 ;
default:
return - V_94 ;
}
}
static unsigned int F_56 ( struct V_119 * V_119 , struct V_34 * V_1 ,
T_8 * V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_120 ;
F_57 ( V_119 , F_58 ( V_2 ) , V_9 ) ;
V_120 = 0 ;
if ( ! F_59 ( & V_13 -> V_121 ) )
V_120 |= V_122 | V_123 ;
if ( F_1 ( V_2 ) )
V_120 |= V_124 | V_125 ;
return V_120 ;
}
static int F_60 ( struct V_126 * V_126 , struct V_34 * V_1 , int V_127 ,
int V_128 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_127 ) ;
if ( V_127 != V_129 &&
F_61 ( F_13 ) && V_127 != V_130 )
return - V_131 ;
if ( V_1 -> type != V_23 )
return - V_24 ;
V_1 -> V_132 = & V_133 ;
V_1 -> V_134 = V_135 ;
V_2 = F_62 ( V_126 , V_136 , V_60 , & V_137 , V_128 ) ;
if ( ! V_2 )
return - V_138 ;
F_63 ( V_1 , V_2 ) ;
F_64 ( V_2 , V_139 ) ;
V_2 -> V_42 = V_43 ;
V_2 -> V_140 = F_3 ;
V_2 -> V_59 = 0 ;
V_2 -> V_141 = V_142 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_28 = V_127 ;
V_13 -> V_143 = V_144 ;
F_65 ( & V_13 -> V_145 ) ;
F_66 ( & V_13 -> V_146 ) ;
F_66 ( & V_13 -> V_147 ) ;
F_66 ( & V_13 -> V_121 ) ;
F_67 ( & V_13 -> V_148 ) ;
F_67 ( & V_13 -> V_149 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_27 ( L_14 , V_13 ) ;
return 0 ;
}
static int F_68 ( struct V_34 * V_1 , int V_85 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_41 = 0 ;
F_4 ( L_6 , V_2 , V_85 ) ;
if ( V_85 != V_150 )
return - V_94 ;
if ( V_2 -> V_42 == V_151 )
return - V_152 ;
F_17 ( V_2 ) ;
F_69 ( & V_2 -> V_153 . V_154 ) ;
if ( V_2 -> V_42 < V_151 ) {
V_2 -> V_42 = V_151 ;
V_2 -> V_155 = V_156 ;
} else {
V_41 = - V_152 ;
}
F_70 ( & V_2 -> V_153 . V_154 ) ;
F_32 ( V_13 ) ;
F_26 ( V_2 ) ;
return V_41 ;
}
static void V_142 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_71 ( & V_2 -> V_153 ) ;
F_72 ( F_2 ( & V_2 -> V_3 ) ) ;
F_72 ( ! F_73 ( V_2 ) ) ;
F_72 ( V_2 -> V_157 ) ;
if ( ! F_74 ( V_2 , V_158 ) ) {
F_75 ( L_15 , V_2 ) ;
return;
}
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_16 , V_2 , V_2 -> V_42 , F_2 ( & V_2 -> V_159 ) ) ;
F_77 ( V_2 ) ;
V_2 -> V_155 = V_156 ;
F_69 ( & V_2 -> V_153 . V_154 ) ;
V_2 -> V_42 = V_151 ;
F_70 ( & V_2 -> V_153 . V_154 ) ;
if ( V_13 -> V_38 && F_23 ( V_13 -> V_38 -> V_46 ) == V_13 ) {
F_22 ( & V_13 -> V_38 -> V_45 ) ;
F_24 ( V_13 -> V_38 -> V_46 , NULL ) ;
F_25 ( & V_13 -> V_38 -> V_45 ) ;
}
F_32 ( V_13 ) ;
F_78 ( V_13 ) ;
F_79 ( V_160 ) ;
F_71 ( & V_2 -> V_153 ) ;
F_28 ( V_13 -> V_38 ) ;
V_13 -> V_38 = NULL ;
F_80 ( V_13 -> V_65 ) ;
V_13 -> V_65 = NULL ;
F_80 ( V_13 -> V_161 ) ;
V_13 -> V_161 = NULL ;
F_81 ( V_2 ) ;
F_27 ( L_4 ) ;
return 0 ;
}
static int F_82 ( struct V_34 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_17 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_76 ( V_2 ) ;
}
static int T_9 F_83 ( void )
{
int V_41 = - 1 ;
unsigned int V_162 ;
F_84 ( sizeof( struct V_163 ) > F_85 ( struct V_164 , V_165 ) ) ;
F_86 ( & V_162 , sizeof( V_162 ) ) ;
V_162 &= 0x3fffffff ;
if ( V_162 == 0 )
V_162 = 1 ;
F_87 ( & V_166 , V_162 ) ;
V_41 = - V_138 ;
V_167 = F_88 (
L_18 , sizeof( struct V_64 ) , 0 ,
V_168 , NULL ) ;
if ( ! V_167 ) {
F_89 ( L_19 ) ;
goto V_169;
}
V_160 = F_90 ( L_20 , 0 , 1 ) ;
if ( ! V_160 ) {
F_89 ( L_21 ) ;
goto V_170;
}
V_41 = F_91 () ;
if ( V_41 < 0 ) {
F_92 ( L_22 ) ;
goto V_171;
}
V_41 = F_93 ( & V_172 ) ;
if ( V_41 )
goto V_173;
V_41 = F_94 ( & V_137 , 1 ) ;
if ( V_41 < 0 ) {
F_92 ( L_23 ) ;
goto V_174;
}
V_41 = F_95 ( & V_175 ) ;
if ( V_41 < 0 ) {
F_92 ( L_24 ) ;
goto V_176;
}
V_41 = F_96 ( & V_177 ) ;
if ( V_41 < 0 ) {
F_92 ( L_25 ) ;
goto V_178;
}
V_41 = F_96 ( & V_179 ) ;
if ( V_41 < 0 ) {
F_92 ( L_26 ) ;
goto V_180;
}
V_41 = F_97 () ;
if ( V_41 < 0 ) {
F_92 ( L_27 ) ;
goto V_181;
}
return 0 ;
V_181:
F_98 ( & V_179 ) ;
V_180:
F_98 ( & V_177 ) ;
V_178:
F_99 ( V_136 ) ;
V_176:
F_100 ( & V_137 ) ;
V_174:
F_101 ( & V_172 ) ;
V_173:
F_102 () ;
V_171:
F_103 ( V_160 ) ;
V_170:
F_104 ( V_167 ) ;
V_169:
return V_41 ;
}
static void T_10 F_105 ( void )
{
F_4 ( L_28 ) ;
F_106 () ;
F_98 ( & V_179 ) ;
F_98 ( & V_177 ) ;
F_99 ( V_136 ) ;
F_100 ( & V_137 ) ;
F_101 ( & V_172 ) ;
F_107 ( F_39 ( & V_182 ) , == , 0 ) ;
F_107 ( F_39 ( & V_183 ) , == , 0 ) ;
F_108 () ;
F_109 () ;
F_103 ( V_160 ) ;
F_102 () ;
F_104 ( V_167 ) ;
F_27 ( L_28 ) ;
}
