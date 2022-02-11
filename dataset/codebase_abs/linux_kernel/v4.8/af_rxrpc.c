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
F_13 ( L_2 ,
F_14 ( V_15 -> V_25 . sin . V_31 ) ,
& V_15 -> V_25 . sin . V_32 ) ;
V_17 = F_12 ( struct V_14 , V_25 . sin . V_33 ) ;
break;
case V_34 :
default:
return - V_21 ;
}
if ( V_17 < V_16 )
memset ( ( void * ) V_15 + V_17 , 0 , V_16 - V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_35 * V_1 , struct V_36 * V_37 , int V_16 )
{
struct V_14 * V_15 = (struct V_14 * ) V_37 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_38 * V_39 ;
struct V_12 * V_13 = F_16 ( V_2 ) , * V_40 ;
int V_41 ;
F_4 ( L_3 , V_13 , V_37 , V_16 ) ;
V_41 = F_11 ( V_13 , V_15 , V_16 ) ;
if ( V_41 < 0 )
goto error;
F_17 ( & V_13 -> V_2 ) ;
if ( V_13 -> V_2 . V_42 != V_43 ) {
V_41 = - V_18 ;
goto V_44;
}
memcpy ( & V_13 -> V_15 , V_15 , sizeof( V_13 -> V_15 ) ) ;
V_39 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_39 ) ) {
V_41 = F_20 ( V_39 ) ;
goto V_44;
}
if ( V_13 -> V_15 . V_45 ) {
F_21 ( & V_39 -> V_46 ) ;
F_22 (prx, &local->services, listen_link) {
if ( V_40 -> V_15 . V_45 == V_13 -> V_15 . V_45 )
goto V_47;
}
V_13 -> V_39 = V_39 ;
F_23 ( & V_13 -> V_48 , & V_39 -> V_49 ) ;
F_24 ( & V_39 -> V_46 ) ;
V_13 -> V_2 . V_42 = V_50 ;
} else {
V_13 -> V_39 = V_39 ;
V_13 -> V_2 . V_42 = V_51 ;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
V_47:
F_24 ( & V_39 -> V_46 ) ;
F_27 ( V_39 ) ;
V_41 = - V_52 ;
V_44:
F_25 ( & V_13 -> V_2 ) ;
error:
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_28 ( struct V_35 * V_1 , int V_53 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
unsigned int V_54 ;
int V_41 ;
F_4 ( L_6 , V_13 , V_53 ) ;
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_41 = - V_55 ;
break;
case V_50 :
ASSERT ( V_13 -> V_39 != NULL ) ;
V_54 = F_29 ( V_56 ) ;
V_41 = - V_18 ;
if ( V_53 == V_57 )
V_53 = V_54 ;
else if ( V_53 < 0 || V_53 > V_54 )
break;
V_2 -> V_58 = V_53 ;
V_13 -> V_2 . V_42 = V_59 ;
V_41 = 0 ;
break;
default:
V_41 = - V_60 ;
break;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
struct V_61 * F_30 ( struct V_35 * V_1 ,
struct V_14 * V_15 ,
struct V_62 * V_62 ,
unsigned long V_63 ,
T_1 V_64 )
{
struct V_65 V_66 ;
struct V_61 * V_67 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_7 , F_31 ( V_62 ) , V_63 ) ;
V_41 = F_11 ( V_13 , V_15 , sizeof( * V_15 ) ) ;
if ( V_41 < 0 )
return F_32 ( V_41 ) ;
F_17 ( & V_13 -> V_2 ) ;
if ( ! V_62 )
V_62 = V_13 -> V_62 ;
if ( V_62 && ! V_62 -> V_68 . V_69 [ 0 ] )
V_62 = NULL ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_39 = V_13 -> V_39 ;
V_66 . V_62 = V_62 ;
V_66 . V_70 = 0 ;
V_66 . V_71 = false ;
V_66 . V_72 = V_15 -> V_45 ;
V_67 = F_33 ( V_13 , & V_66 , V_15 , V_63 , V_64 ) ;
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_8 , V_67 ) ;
return V_67 ;
}
void F_34 ( struct V_61 * V_67 )
{
F_4 ( L_9 , V_67 -> V_73 , F_2 ( & V_67 -> V_74 ) ) ;
F_35 ( V_67 -> V_35 , V_67 ) ;
F_36 ( V_67 ) ;
}
void F_37 ( struct V_35 * V_1 ,
T_2 V_75 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
F_4 ( L_10 ) ;
V_13 -> V_75 = V_75 ;
}
static int F_38 ( struct V_35 * V_1 , struct V_36 * V_76 ,
int V_77 , int V_78 )
{
struct V_14 * V_15 = (struct V_14 * ) V_76 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_11 , V_13 , V_76 , V_77 , V_78 ) ;
V_41 = F_11 ( V_13 , V_15 , V_77 ) ;
if ( V_41 < 0 ) {
F_26 ( L_12 , V_41 ) ;
return V_41 ;
}
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_79 ;
if ( F_39 ( V_80 , & V_13 -> V_78 ) )
goto error;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_13 -> V_2 . V_42 = V_81 ;
case V_81 :
case V_51 :
break;
default:
V_41 = - V_60 ;
goto error;
}
V_13 -> V_82 = * V_15 ;
F_40 ( V_80 , & V_13 -> V_78 ) ;
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static int F_41 ( struct V_35 * V_1 , struct V_83 * V_84 , V_4 V_16 )
{
struct V_38 * V_39 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_13 , V_13 -> V_2 . V_42 , V_16 ) ;
if ( V_84 -> V_85 & V_86 )
return - V_87 ;
if ( V_84 -> V_88 ) {
V_41 = F_11 ( V_13 , V_84 -> V_88 , V_84 -> V_89 ) ;
if ( V_41 < 0 ) {
F_26 ( L_12 , V_41 ) ;
return V_41 ;
}
}
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_39 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_39 ) ) {
V_41 = F_20 ( V_39 ) ;
goto V_44;
}
V_13 -> V_39 = V_39 ;
V_13 -> V_2 . V_42 = V_81 ;
case V_81 :
case V_51 :
if ( ! V_84 -> V_88 &&
F_39 ( V_80 , & V_13 -> V_78 ) ) {
V_84 -> V_88 = & V_13 -> V_82 ;
V_84 -> V_89 = sizeof( V_13 -> V_82 ) ;
}
case V_50 :
case V_59 :
V_41 = F_42 ( V_13 , V_84 , V_16 ) ;
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
static int F_43 ( struct V_35 * V_1 , int V_90 , int V_91 ,
char T_3 * V_92 , unsigned int V_93 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned int V_94 ;
int V_41 ;
F_4 ( L_14 , V_90 , V_91 , V_93 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_87 ;
if ( V_90 == V_95 ) {
switch ( V_91 ) {
case V_96 :
V_41 = - V_18 ;
if ( V_93 != 0 )
goto error;
V_41 = - V_79 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_13 -> V_71 = true ;
goto V_97;
case V_98 :
V_41 = - V_18 ;
if ( V_13 -> V_62 )
goto error;
V_41 = - V_79 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_44 ( V_13 , V_92 , V_93 ) ;
goto error;
case V_99 :
V_41 = - V_18 ;
if ( V_13 -> V_62 )
goto error;
V_41 = - V_79 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_45 ( V_13 , V_92 , V_93 ) ;
goto error;
case V_100 :
V_41 = - V_18 ;
if ( V_93 != sizeof( unsigned int ) )
goto error;
V_41 = - V_79 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_46 ( V_94 ,
( unsigned int T_3 * ) V_92 ) ;
if ( V_41 < 0 )
goto error;
V_41 = - V_18 ;
if ( V_94 > V_101 )
goto error;
V_13 -> V_94 = V_94 ;
goto V_97;
default:
break;
}
}
V_97:
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static unsigned int F_47 ( struct V_102 * V_102 , struct V_35 * V_1 ,
T_4 * V_9 )
{
unsigned int V_103 ;
struct V_1 * V_2 = V_1 -> V_2 ;
F_48 ( V_102 , F_49 ( V_2 ) , V_9 ) ;
V_103 = 0 ;
if ( ! F_50 ( & V_2 -> V_104 ) )
V_103 |= V_105 | V_106 ;
if ( F_1 ( V_2 ) )
V_103 |= V_107 | V_108 ;
return V_103 ;
}
static int F_51 ( struct V_109 * V_109 , struct V_35 * V_1 , int V_110 ,
int V_111 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_110 ) ;
if ( ! F_52 ( V_109 , & V_112 ) )
return - V_21 ;
if ( V_110 != V_113 )
return - V_114 ;
if ( V_1 -> type != V_23 )
return - V_24 ;
V_1 -> V_115 = & V_116 ;
V_1 -> V_117 = V_118 ;
V_2 = F_53 ( V_109 , V_119 , V_120 , & V_121 , V_111 ) ;
if ( ! V_2 )
return - V_122 ;
F_54 ( V_1 , V_2 ) ;
V_2 -> V_42 = V_43 ;
V_2 -> V_123 = F_3 ;
V_2 -> V_58 = 0 ;
V_2 -> V_124 = V_125 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_28 = V_110 ;
V_13 -> V_126 = V_127 ;
F_55 ( & V_13 -> V_48 ) ;
F_55 ( & V_13 -> V_128 ) ;
F_55 ( & V_13 -> V_129 ) ;
F_56 ( & V_13 -> V_130 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_26 ( L_15 , V_13 ) ;
return 0 ;
}
static void V_125 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_57 ( & V_2 -> V_104 ) ;
F_58 ( F_2 ( & V_2 -> V_3 ) ) ;
F_58 ( ! F_59 ( V_2 ) ) ;
F_58 ( V_2 -> V_131 ) ;
if ( ! F_60 ( V_2 , V_132 ) ) {
F_61 ( L_16 , V_2 ) ;
return;
}
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_17 , V_2 , V_2 -> V_42 , F_2 ( & V_2 -> V_133 ) ) ;
F_63 ( V_2 ) ;
V_2 -> V_134 = V_135 ;
F_64 ( & V_2 -> V_104 . V_136 ) ;
V_2 -> V_42 = V_137 ;
F_65 ( & V_2 -> V_104 . V_136 ) ;
F_66 ( V_13 -> V_48 . V_138 , != , V_139 ) ;
if ( ! F_67 ( & V_13 -> V_48 ) ) {
F_21 ( & V_13 -> V_39 -> V_46 ) ;
F_68 ( & V_13 -> V_48 ) ;
F_24 ( & V_13 -> V_39 -> V_46 ) ;
}
F_69 ( V_13 ) ;
F_70 ( V_140 ) ;
F_57 ( & V_2 -> V_104 ) ;
F_27 ( V_13 -> V_39 ) ;
V_13 -> V_39 = NULL ;
F_71 ( V_13 -> V_62 ) ;
V_13 -> V_62 = NULL ;
F_71 ( V_13 -> V_141 ) ;
V_13 -> V_141 = NULL ;
F_72 ( V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
}
static int F_73 ( struct V_35 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_18 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_62 ( V_2 ) ;
}
static int T_5 F_74 ( void )
{
int V_41 = - 1 ;
F_75 ( sizeof( struct V_142 ) > F_76 ( struct V_143 , V_144 ) ) ;
V_145 = F_77 () ;
V_41 = - V_122 ;
V_146 = F_78 (
L_19 , sizeof( struct V_61 ) , 0 ,
V_147 , NULL ) ;
if ( ! V_146 ) {
F_79 ( L_20 ) ;
goto V_148;
}
V_140 = F_80 ( L_21 , 0 , 1 ) ;
if ( ! V_140 ) {
F_79 ( L_22 ) ;
goto V_149;
}
V_41 = F_81 () ;
if ( V_41 < 0 ) {
F_82 ( L_23 ) ;
goto V_150;
}
V_41 = F_83 ( & V_121 , 1 ) ;
if ( V_41 < 0 ) {
F_82 ( L_24 ) ;
goto V_151;
}
V_41 = F_84 ( & V_152 ) ;
if ( V_41 < 0 ) {
F_82 ( L_25 ) ;
goto V_153;
}
V_41 = F_85 ( & V_154 ) ;
if ( V_41 < 0 ) {
F_82 ( L_26 ) ;
goto V_155;
}
V_41 = F_85 ( & V_156 ) ;
if ( V_41 < 0 ) {
F_82 ( L_27 ) ;
goto V_157;
}
V_41 = F_86 () ;
if ( V_41 < 0 ) {
F_82 ( L_28 ) ;
goto V_158;
}
#ifdef F_87
F_88 ( L_29 , 0 , V_112 . V_159 , & V_160 ) ;
F_88 ( L_30 , 0 , V_112 . V_159 ,
& V_161 ) ;
#endif
return 0 ;
V_158:
F_89 ( & V_156 ) ;
V_157:
F_89 ( & V_154 ) ;
V_155:
F_90 ( V_119 ) ;
V_153:
F_91 ( & V_121 ) ;
V_151:
F_92 () ;
V_150:
F_93 ( V_140 ) ;
V_149:
F_94 ( V_146 ) ;
V_148:
return V_41 ;
}
static void T_6 F_95 ( void )
{
F_4 ( L_10 ) ;
F_96 () ;
F_89 ( & V_156 ) ;
F_89 ( & V_154 ) ;
F_90 ( V_119 ) ;
F_91 ( & V_121 ) ;
F_97 () ;
F_98 () ;
F_66 ( F_2 ( & V_162 ) , == , 0 ) ;
F_99 () ;
F_100 ( L_30 , V_112 . V_159 ) ;
F_100 ( L_29 , V_112 . V_159 ) ;
F_93 ( V_140 ) ;
F_92 () ;
F_94 ( V_146 ) ;
F_26 ( L_10 ) ;
}
