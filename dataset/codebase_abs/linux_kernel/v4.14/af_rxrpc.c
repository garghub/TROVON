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
if ( ! F_20 ( V_72 ) ) {
V_72 -> V_69 = V_69 ;
F_37 ( & V_72 -> V_77 ) ;
}
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
int F_43 ( struct V_34 * V_1 , struct V_64 * V_72 ,
enum V_81 * V_82 , T_5 * V_83 )
{
if ( V_72 -> V_84 != V_85 )
return - V_86 ;
F_44 () ;
* V_82 = V_72 -> V_87 ;
* V_83 = V_72 -> V_88 ;
return V_72 -> error ;
}
int F_45 ( struct V_34 * V_1 , struct V_64 * V_72 ,
struct V_14 * V_15 , struct V_65 * V_65 )
{
struct V_70 V_71 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_9 , V_72 -> V_78 , F_39 ( & V_72 -> V_79 ) ) ;
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
F_40 ( & V_72 -> V_77 ) ;
V_41 = F_46 ( V_13 , V_72 ) ;
if ( V_41 == 0 )
V_41 = F_47 ( V_13 , V_72 , & V_71 , V_15 , V_60 ) ;
F_37 ( & V_72 -> V_77 ) ;
F_27 ( L_5 , V_41 ) ;
return V_41 ;
}
void F_48 (
struct V_34 * V_1 ,
T_6 V_89 ,
T_7 V_90 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
V_13 -> V_89 = V_89 ;
V_13 -> V_90 = V_90 ;
}
static int F_49 ( struct V_34 * V_1 , struct V_35 * V_91 ,
int V_92 , int V_93 )
{
struct V_14 * V_15 = (struct V_14 * ) V_91 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_10 , V_13 , V_91 , V_92 , V_93 ) ;
V_41 = F_11 ( V_13 , V_15 , V_92 ) ;
if ( V_41 < 0 ) {
F_27 ( L_11 , V_41 ) ;
return V_41 ;
}
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_94 ;
if ( F_50 ( V_95 , & V_13 -> V_93 ) )
goto error;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_2 . V_42 = V_96 ;
case V_96 :
case V_49 :
break;
default:
V_41 = - V_63 ;
goto error;
}
V_13 -> V_97 = * V_15 ;
F_51 ( V_95 , & V_13 -> V_93 ) ;
V_41 = 0 ;
error:
F_26 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_52 ( struct V_34 * V_1 , struct V_98 * V_99 , V_4 V_16 )
{
struct V_37 * V_38 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_12 , V_13 -> V_2 . V_42 , V_16 ) ;
if ( V_99 -> V_100 & V_101 )
return - V_102 ;
if ( V_99 -> V_103 ) {
V_41 = F_11 ( V_13 , V_99 -> V_103 , V_99 -> V_104 ) ;
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
V_13 -> V_2 . V_42 = V_96 ;
case V_96 :
case V_49 :
if ( ! V_99 -> V_103 &&
F_50 ( V_95 , & V_13 -> V_93 ) ) {
V_99 -> V_103 = & V_13 -> V_97 ;
V_99 -> V_104 = sizeof( V_13 -> V_97 ) ;
}
case V_48 :
case V_61 :
V_41 = F_53 ( V_13 , V_99 , V_16 ) ;
goto V_105;
default:
V_41 = - V_18 ;
goto V_44;
}
V_44:
F_26 ( & V_13 -> V_2 ) ;
V_105:
F_27 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_54 ( struct V_34 * V_1 , int V_106 , int V_107 ,
char T_8 * V_108 , unsigned int V_109 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned int V_110 ;
T_1 V_111 [ 2 ] ;
int V_41 ;
F_4 ( L_13 , V_106 , V_107 , V_109 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_102 ;
if ( V_106 == V_112 ) {
switch ( V_107 ) {
case V_113 :
V_41 = - V_18 ;
if ( V_109 != 0 )
goto error;
V_41 = - V_94 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_13 -> V_76 = true ;
goto V_114;
case V_115 :
V_41 = - V_18 ;
if ( V_13 -> V_65 )
goto error;
V_41 = - V_94 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_55 ( V_13 , V_108 , V_109 ) ;
goto error;
case V_116 :
V_41 = - V_18 ;
if ( V_13 -> V_65 )
goto error;
V_41 = - V_94 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_56 ( V_13 , V_108 , V_109 ) ;
goto error;
case V_117 :
V_41 = - V_18 ;
if ( V_109 != sizeof( unsigned int ) )
goto error;
V_41 = - V_94 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_57 ( V_110 ,
( unsigned int T_8 * ) V_108 ) ;
if ( V_41 < 0 )
goto error;
V_41 = - V_18 ;
if ( V_110 > V_118 )
goto error;
V_13 -> V_110 = V_110 ;
goto V_114;
case V_119 :
V_41 = - V_18 ;
if ( V_109 != sizeof( V_111 ) ||
V_13 -> V_111 . V_120 != 0 )
goto error;
V_41 = - V_94 ;
if ( V_13 -> V_2 . V_42 != V_52 )
goto error;
V_41 = - V_121 ;
if ( F_58 ( V_111 , V_108 ,
sizeof( V_111 ) ) != 0 )
goto error;
V_41 = - V_18 ;
if ( ( V_111 [ 0 ] != V_13 -> V_15 . V_40 ||
V_111 [ 1 ] != V_13 -> V_51 ) &&
( V_111 [ 0 ] != V_13 -> V_51 ||
V_111 [ 1 ] != V_13 -> V_15 . V_40 ) )
goto error;
V_13 -> V_111 . V_120 = V_111 [ 0 ] ;
V_13 -> V_111 . V_122 = V_111 [ 1 ] ;
goto V_114;
default:
break;
}
}
V_114:
V_41 = 0 ;
error:
F_26 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_59 ( struct V_34 * V_1 , int V_106 , int V_107 ,
char T_8 * V_108 , int T_8 * V_123 )
{
int V_109 ;
if ( V_106 != V_112 )
return - V_102 ;
if ( F_57 ( V_109 , V_123 ) )
return - V_121 ;
switch ( V_107 ) {
case V_124 :
if ( V_109 < sizeof( int ) )
return - V_125 ;
if ( F_60 ( V_126 - 1 , ( int T_8 * ) V_108 ) ||
F_60 ( sizeof( int ) , V_123 ) )
return - V_121 ;
return 0 ;
default:
return - V_102 ;
}
}
static unsigned int F_61 ( struct V_127 * V_127 , struct V_34 * V_1 ,
T_9 * V_9 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_128 ;
F_62 ( V_127 , F_63 ( V_2 ) , V_9 ) ;
V_128 = 0 ;
if ( ! F_64 ( & V_13 -> V_129 ) )
V_128 |= V_130 | V_131 ;
if ( F_1 ( V_2 ) )
V_128 |= V_132 | V_133 ;
return V_128 ;
}
static int F_65 ( struct V_134 * V_134 , struct V_34 * V_1 , int V_135 ,
int V_136 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_135 ) ;
if ( V_135 != V_137 &&
F_66 ( F_13 ) && V_135 != V_138 )
return - V_139 ;
if ( V_1 -> type != V_23 )
return - V_24 ;
V_1 -> V_140 = & V_141 ;
V_1 -> V_84 = V_142 ;
V_2 = F_67 ( V_134 , V_143 , V_60 , & V_144 , V_136 ) ;
if ( ! V_2 )
return - V_145 ;
F_68 ( V_1 , V_2 ) ;
F_69 ( V_2 , V_146 ) ;
V_2 -> V_42 = V_43 ;
V_2 -> V_147 = F_3 ;
V_2 -> V_59 = 0 ;
V_2 -> V_148 = V_149 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_28 = V_135 ;
V_13 -> V_150 = V_151 ;
F_70 ( & V_13 -> V_152 ) ;
F_71 ( & V_13 -> V_153 ) ;
F_71 ( & V_13 -> V_154 ) ;
F_71 ( & V_13 -> V_129 ) ;
F_72 ( & V_13 -> V_155 ) ;
F_72 ( & V_13 -> V_156 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_27 ( L_14 , V_13 ) ;
return 0 ;
}
static int F_73 ( struct V_34 * V_1 , int V_93 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_41 = 0 ;
F_4 ( L_6 , V_2 , V_93 ) ;
if ( V_93 != V_157 )
return - V_102 ;
if ( V_2 -> V_42 == V_158 )
return - V_159 ;
F_17 ( V_2 ) ;
F_74 ( & V_2 -> V_160 . V_161 ) ;
if ( V_2 -> V_42 < V_158 ) {
V_2 -> V_42 = V_158 ;
V_2 -> V_162 = V_163 ;
} else {
V_41 = - V_159 ;
}
F_75 ( & V_2 -> V_160 . V_161 ) ;
F_32 ( V_13 ) ;
F_26 ( V_2 ) ;
return V_41 ;
}
static void V_149 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_76 ( & V_2 -> V_160 ) ;
F_77 ( F_2 ( & V_2 -> V_3 ) ) ;
F_77 ( ! F_78 ( V_2 ) ) ;
F_77 ( V_2 -> V_164 ) ;
if ( ! F_79 ( V_2 , V_165 ) ) {
F_80 ( L_15 , V_2 ) ;
return;
}
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_16 , V_2 , V_2 -> V_42 , F_2 ( & V_2 -> V_166 ) ) ;
F_82 ( V_2 ) ;
V_2 -> V_162 = V_163 ;
F_74 ( & V_2 -> V_160 . V_161 ) ;
V_2 -> V_42 = V_158 ;
F_75 ( & V_2 -> V_160 . V_161 ) ;
if ( V_13 -> V_38 && F_23 ( V_13 -> V_38 -> V_46 ) == V_13 ) {
F_22 ( & V_13 -> V_38 -> V_45 ) ;
F_24 ( V_13 -> V_38 -> V_46 , NULL ) ;
F_25 ( & V_13 -> V_38 -> V_45 ) ;
}
F_32 ( V_13 ) ;
F_83 ( V_13 ) ;
F_84 ( V_167 ) ;
F_76 ( & V_2 -> V_160 ) ;
F_28 ( V_13 -> V_38 ) ;
V_13 -> V_38 = NULL ;
F_85 ( V_13 -> V_65 ) ;
V_13 -> V_65 = NULL ;
F_85 ( V_13 -> V_168 ) ;
V_13 -> V_168 = NULL ;
F_86 ( V_2 ) ;
F_27 ( L_4 ) ;
return 0 ;
}
static int F_87 ( struct V_34 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_17 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_81 ( V_2 ) ;
}
static int T_10 F_88 ( void )
{
int V_41 = - 1 ;
unsigned int V_169 ;
F_89 ( sizeof( struct V_170 ) > F_90 ( struct V_171 , V_172 ) ) ;
F_91 ( & V_169 , sizeof( V_169 ) ) ;
V_169 &= 0x3fffffff ;
if ( V_169 == 0 )
V_169 = 1 ;
F_92 ( & V_173 , V_169 ) ;
V_41 = - V_145 ;
V_174 = F_93 (
L_18 , sizeof( struct V_64 ) , 0 ,
V_175 , NULL ) ;
if ( ! V_174 ) {
F_94 ( L_19 ) ;
goto V_176;
}
V_167 = F_95 ( L_20 , 0 , 1 ) ;
if ( ! V_167 ) {
F_94 ( L_21 ) ;
goto V_177;
}
V_41 = F_96 () ;
if ( V_41 < 0 ) {
F_97 ( L_22 ) ;
goto V_178;
}
V_41 = F_98 ( & V_179 ) ;
if ( V_41 )
goto V_180;
V_41 = F_99 ( & V_144 , 1 ) ;
if ( V_41 < 0 ) {
F_97 ( L_23 ) ;
goto V_181;
}
V_41 = F_100 ( & V_182 ) ;
if ( V_41 < 0 ) {
F_97 ( L_24 ) ;
goto V_183;
}
V_41 = F_101 ( & V_184 ) ;
if ( V_41 < 0 ) {
F_97 ( L_25 ) ;
goto V_185;
}
V_41 = F_101 ( & V_186 ) ;
if ( V_41 < 0 ) {
F_97 ( L_26 ) ;
goto V_187;
}
V_41 = F_102 () ;
if ( V_41 < 0 ) {
F_97 ( L_27 ) ;
goto V_188;
}
return 0 ;
V_188:
F_103 ( & V_186 ) ;
V_187:
F_103 ( & V_184 ) ;
V_185:
F_104 ( V_143 ) ;
V_183:
F_105 ( & V_144 ) ;
V_181:
F_106 ( & V_179 ) ;
V_180:
F_107 () ;
V_178:
F_108 ( V_167 ) ;
V_177:
F_109 ( V_174 ) ;
V_176:
return V_41 ;
}
static void T_11 F_110 ( void )
{
F_4 ( L_28 ) ;
F_111 () ;
F_103 ( & V_186 ) ;
F_103 ( & V_184 ) ;
F_104 ( V_143 ) ;
F_105 ( & V_144 ) ;
F_106 ( & V_179 ) ;
F_112 ( F_39 ( & V_189 ) , == , 0 ) ;
F_112 ( F_39 ( & V_190 ) , == , 0 ) ;
F_113 () ;
F_114 () ;
F_108 ( V_167 ) ;
F_107 () ;
F_109 ( V_174 ) ;
F_27 ( L_28 ) ;
}
