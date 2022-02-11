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
if ( V_15 -> V_25 . V_28 != V_13 -> V_29 )
return - V_21 ;
switch ( V_15 -> V_25 . V_28 ) {
case V_30 :
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
V_13 -> V_39 = V_39 ;
if ( V_15 -> V_45 ) {
F_21 ( & V_39 -> V_46 ) ;
F_22 (prx, &local->services, listen_link) {
if ( V_40 -> V_15 . V_45 == V_15 -> V_45 )
goto V_47;
}
F_23 ( & V_13 -> V_48 , & V_39 -> V_49 ) ;
F_24 ( & V_39 -> V_46 ) ;
V_13 -> V_2 . V_42 = V_50 ;
} else {
V_13 -> V_2 . V_42 = V_51 ;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
V_47:
V_41 = - V_52 ;
F_24 ( & V_39 -> V_46 ) ;
V_44:
F_25 ( & V_13 -> V_2 ) ;
error:
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_27 ( struct V_35 * V_1 , int V_53 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_41 ;
F_4 ( L_6 , V_13 , V_53 ) ;
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
V_41 = - V_54 ;
break;
case V_51 :
case V_55 :
default:
V_41 = - V_56 ;
break;
case V_50 :
ASSERT ( V_13 -> V_39 != NULL ) ;
V_2 -> V_57 = V_53 ;
V_13 -> V_2 . V_42 = V_58 ;
V_41 = 0 ;
break;
}
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static struct V_59 * F_28 ( struct V_35 * V_1 ,
struct V_36 * V_60 ,
int V_61 , int V_62 ,
T_1 V_63 )
{
struct V_14 * V_15 = (struct V_14 * ) V_60 ;
struct V_59 * V_64 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
struct V_65 * V_66 ;
F_4 ( L_7 , V_13 , V_60 , V_61 , V_62 ) ;
ASSERT ( V_13 -> V_39 != NULL ) ;
ASSERT ( V_13 -> V_2 . V_42 > V_43 ) ;
if ( V_13 -> V_15 . V_22 != V_15 -> V_22 )
return F_29 ( - V_24 ) ;
if ( V_13 -> V_15 . V_25 . V_28 != V_15 -> V_25 . V_28 )
return F_29 ( - V_21 ) ;
V_66 = F_30 ( V_15 , V_63 ) ;
if ( F_19 ( V_66 ) )
return F_31 ( V_66 ) ;
V_64 = F_32 ( V_13 -> V_39 , V_66 , V_63 ) ;
F_33 ( V_66 ) ;
F_26 ( L_8 , V_64 ) ;
return V_64 ;
}
struct V_67 * F_34 ( struct V_35 * V_1 ,
struct V_14 * V_15 ,
struct V_68 * V_68 ,
unsigned long V_69 ,
T_1 V_63 )
{
struct V_70 * V_71 ;
struct V_59 * V_64 ;
struct V_67 * V_72 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
F_4 ( L_9 , F_35 ( V_68 ) , V_69 ) ;
F_17 ( & V_13 -> V_2 ) ;
if ( V_15 ) {
V_64 = F_28 ( V_1 , (struct V_36 * ) V_15 ,
sizeof( * V_15 ) , 0 , V_63 ) ;
if ( F_19 ( V_64 ) ) {
V_72 = F_31 ( V_64 ) ;
V_64 = NULL ;
goto V_73;
}
} else {
V_64 = V_13 -> V_64 ;
if ( ! V_64 ) {
V_72 = F_29 ( - V_74 ) ;
goto V_73;
}
F_36 ( & V_64 -> V_75 ) ;
}
if ( ! V_15 )
V_15 = & V_13 -> V_15 ;
if ( ! V_68 )
V_68 = V_13 -> V_68 ;
if ( V_68 && ! V_68 -> V_76 . V_77 [ 0 ] )
V_68 = NULL ;
V_71 = F_37 ( V_13 , V_64 , V_68 , V_15 -> V_45 , V_63 ) ;
if ( F_19 ( V_71 ) ) {
V_72 = F_31 ( V_71 ) ;
goto V_78;
}
V_72 = F_38 ( V_13 , V_64 , V_71 , V_69 , true ,
V_63 ) ;
F_39 ( V_64 , V_71 ) ;
V_78:
F_40 ( V_64 ) ;
V_73:
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_8 , V_72 ) ;
return V_72 ;
}
void F_41 ( struct V_67 * V_72 )
{
F_4 ( L_10 , V_72 -> V_79 , F_2 ( & V_72 -> V_75 ) ) ;
F_42 ( V_72 -> V_35 , V_72 ) ;
F_43 ( V_72 ) ;
}
void F_44 ( struct V_35 * V_1 ,
T_2 V_80 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
F_4 ( L_11 ) ;
V_13 -> V_80 = V_80 ;
}
static int F_45 ( struct V_35 * V_1 , struct V_36 * V_60 ,
int V_61 , int V_62 )
{
struct V_14 * V_15 = (struct V_14 * ) V_60 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_59 * V_64 ;
struct V_38 * V_39 ;
struct V_12 * V_13 = F_16 ( V_2 ) ;
int V_41 ;
F_4 ( L_7 , V_13 , V_60 , V_61 , V_62 ) ;
V_41 = F_11 ( V_13 , V_15 , V_61 ) ;
if ( V_41 < 0 ) {
F_26 ( L_12 , V_41 ) ;
return V_41 ;
}
F_17 ( & V_13 -> V_2 ) ;
switch ( V_13 -> V_2 . V_42 ) {
case V_43 :
F_46 ( V_13 -> V_39 , == , NULL ) ;
V_13 -> V_15 . V_19 = V_20 ;
V_13 -> V_15 . V_45 = 0 ;
V_13 -> V_15 . V_22 = V_15 -> V_22 ;
V_13 -> V_15 . V_26 = sizeof( V_27 ) ;
V_13 -> V_15 . V_25 . V_28 = V_15 -> V_25 . V_28 ;
V_39 = F_18 ( & V_13 -> V_15 ) ;
if ( F_19 ( V_39 ) ) {
F_25 ( & V_13 -> V_2 ) ;
return F_20 ( V_39 ) ;
}
V_13 -> V_39 = V_39 ;
V_13 -> V_2 . V_42 = V_51 ;
case V_51 :
break;
case V_55 :
F_25 ( & V_13 -> V_2 ) ;
return - V_81 ;
default:
F_25 ( & V_13 -> V_2 ) ;
return - V_56 ;
}
V_64 = F_28 ( V_1 , V_60 , V_61 , V_62 ,
V_82 ) ;
if ( F_19 ( V_64 ) ) {
F_25 ( & V_13 -> V_2 ) ;
F_26 ( L_13 , F_20 ( V_64 ) ) ;
return F_20 ( V_64 ) ;
}
V_13 -> V_64 = V_64 ;
V_13 -> V_2 . V_42 = V_55 ;
F_25 ( & V_13 -> V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_35 * V_1 , struct V_83 * V_84 , V_4 V_16 )
{
struct V_59 * V_64 ;
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
int V_41 ;
F_4 ( L_14 , V_13 -> V_2 . V_42 , V_16 ) ;
if ( V_84 -> V_85 & V_86 )
return - V_87 ;
if ( V_84 -> V_88 ) {
V_41 = F_11 ( V_13 , V_84 -> V_88 , V_84 -> V_89 ) ;
if ( V_41 < 0 ) {
F_26 ( L_12 , V_41 ) ;
return V_41 ;
}
}
V_64 = NULL ;
F_17 ( & V_13 -> V_2 ) ;
if ( V_84 -> V_88 ) {
V_41 = - V_81 ;
V_64 = F_28 ( V_1 , V_84 -> V_88 ,
V_84 -> V_89 , 0 , V_82 ) ;
if ( F_19 ( V_64 ) ) {
V_41 = F_20 ( V_64 ) ;
V_64 = NULL ;
goto V_78;
}
} else {
V_64 = V_13 -> V_64 ;
if ( V_64 )
F_36 ( & V_64 -> V_75 ) ;
}
switch ( V_13 -> V_2 . V_42 ) {
case V_58 :
if ( ! V_84 -> V_88 ) {
V_41 = F_48 ( V_13 , V_84 , V_16 ) ;
break;
}
case V_50 :
case V_51 :
if ( ! V_84 -> V_88 ) {
V_41 = - V_74 ;
break;
}
case V_55 :
V_41 = F_49 ( V_13 , V_64 , V_84 , V_16 ) ;
break;
default:
V_41 = - V_74 ;
break;
}
V_78:
F_25 ( & V_13 -> V_2 ) ;
if ( V_64 )
F_40 ( V_64 ) ;
F_26 ( L_5 , V_41 ) ;
return V_41 ;
}
static int F_50 ( struct V_35 * V_1 , int V_90 , int V_91 ,
char T_3 * V_92 , unsigned int V_93 )
{
struct V_12 * V_13 = F_16 ( V_1 -> V_2 ) ;
unsigned int V_94 ;
int V_41 ;
F_4 ( L_15 , V_90 , V_91 , V_93 ) ;
F_17 ( & V_13 -> V_2 ) ;
V_41 = - V_87 ;
if ( V_90 == V_95 ) {
switch ( V_91 ) {
case V_96 :
V_41 = - V_18 ;
if ( V_93 != 0 )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
F_51 ( V_97 , & V_13 -> V_62 ) ;
goto V_98;
case V_99 :
V_41 = - V_18 ;
if ( V_13 -> V_68 )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_52 ( V_13 , V_92 , V_93 ) ;
goto error;
case V_100 :
V_41 = - V_18 ;
if ( V_13 -> V_68 )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_53 ( V_13 , V_92 , V_93 ) ;
goto error;
case V_101 :
V_41 = - V_18 ;
if ( V_93 != sizeof( unsigned int ) )
goto error;
V_41 = - V_81 ;
if ( V_13 -> V_2 . V_42 != V_43 )
goto error;
V_41 = F_54 ( V_94 ,
( unsigned int T_3 * ) V_92 ) ;
if ( V_41 < 0 )
goto error;
V_41 = - V_18 ;
if ( V_94 > V_102 )
goto error;
V_13 -> V_94 = V_94 ;
goto V_98;
default:
break;
}
}
V_98:
V_41 = 0 ;
error:
F_25 ( & V_13 -> V_2 ) ;
return V_41 ;
}
static unsigned int F_55 ( struct V_103 * V_103 , struct V_35 * V_1 ,
T_4 * V_9 )
{
unsigned int V_104 ;
struct V_1 * V_2 = V_1 -> V_2 ;
F_56 ( V_103 , F_57 ( V_2 ) , V_9 ) ;
V_104 = 0 ;
if ( ! F_58 ( & V_2 -> V_105 ) )
V_104 |= V_106 | V_107 ;
if ( F_1 ( V_2 ) )
V_104 |= V_108 | V_109 ;
return V_104 ;
}
static int F_59 ( struct V_110 * V_110 , struct V_35 * V_1 , int V_111 ,
int V_112 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
F_4 ( L_6 , V_1 , V_111 ) ;
if ( ! F_60 ( V_110 , & V_113 ) )
return - V_21 ;
if ( V_111 != V_114 )
return - V_115 ;
if ( V_1 -> type != V_23 )
return - V_24 ;
V_1 -> V_116 = & V_117 ;
V_1 -> V_118 = V_119 ;
V_2 = F_61 ( V_110 , V_120 , V_82 , & V_121 , V_112 ) ;
if ( ! V_2 )
return - V_122 ;
F_62 ( V_1 , V_2 ) ;
V_2 -> V_42 = V_43 ;
V_2 -> V_123 = F_3 ;
V_2 -> V_57 = V_124 ;
V_2 -> V_125 = V_126 ;
V_13 = F_16 ( V_2 ) ;
V_13 -> V_29 = V_111 ;
V_13 -> V_127 = V_128 ;
F_63 ( & V_13 -> V_48 ) ;
F_63 ( & V_13 -> V_129 ) ;
F_63 ( & V_13 -> V_130 ) ;
F_64 ( & V_13 -> V_131 ) ;
memset ( & V_13 -> V_15 , 0 , sizeof( V_13 -> V_15 ) ) ;
F_26 ( L_16 , V_13 ) ;
return 0 ;
}
static void V_126 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
F_65 ( & V_2 -> V_105 ) ;
F_66 ( F_2 ( & V_2 -> V_3 ) ) ;
F_66 ( ! F_67 ( V_2 ) ) ;
F_66 ( V_2 -> V_132 ) ;
if ( ! F_68 ( V_2 , V_133 ) ) {
F_69 ( L_17 , V_2 ) ;
return;
}
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_16 ( V_2 ) ;
F_4 ( L_18 , V_2 , V_2 -> V_42 , F_2 ( & V_2 -> V_134 ) ) ;
F_71 ( V_2 ) ;
V_2 -> V_135 = V_136 ;
F_72 ( & V_2 -> V_105 . V_137 ) ;
V_2 -> V_42 = V_138 ;
F_73 ( & V_2 -> V_105 . V_137 ) ;
F_46 ( V_13 -> V_48 . V_139 , != , V_140 ) ;
if ( ! F_74 ( & V_13 -> V_48 ) ) {
F_21 ( & V_13 -> V_39 -> V_46 ) ;
F_75 ( & V_13 -> V_48 ) ;
F_24 ( & V_13 -> V_39 -> V_46 ) ;
}
F_76 ( V_13 ) ;
F_77 ( V_141 ) ;
F_65 ( & V_2 -> V_105 ) ;
if ( V_13 -> V_142 ) {
F_78 ( V_13 -> V_142 ) ;
V_13 -> V_142 = NULL ;
}
if ( V_13 -> V_71 ) {
F_39 ( V_13 -> V_64 , V_13 -> V_71 ) ;
V_13 -> V_71 = NULL ;
}
if ( V_13 -> V_64 ) {
F_40 ( V_13 -> V_64 ) ;
V_13 -> V_64 = NULL ;
}
if ( V_13 -> V_39 ) {
F_79 ( V_13 -> V_39 ) ;
V_13 -> V_39 = NULL ;
}
F_80 ( V_13 -> V_68 ) ;
V_13 -> V_68 = NULL ;
F_80 ( V_13 -> V_143 ) ;
V_13 -> V_143 = NULL ;
F_81 ( V_2 ) ;
F_26 ( L_4 ) ;
return 0 ;
}
static int F_82 ( struct V_35 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
F_4 ( L_19 , V_1 , V_2 ) ;
if ( ! V_2 )
return 0 ;
V_1 -> V_2 = NULL ;
return F_70 ( V_2 ) ;
}
static int T_5 F_83 ( void )
{
int V_41 = - 1 ;
F_84 ( sizeof( struct V_144 ) > F_85 ( struct V_145 , V_146 ) ) ;
V_147 = F_86 () ;
V_41 = - V_122 ;
V_148 = F_87 (
L_20 , sizeof( struct V_67 ) , 0 ,
V_149 , NULL ) ;
if ( ! V_148 ) {
F_69 ( V_150 L_21 ) ;
goto V_151;
}
V_141 = F_88 ( L_22 , 0 , 1 ) ;
if ( ! V_141 ) {
F_69 ( V_150 L_23 ) ;
goto V_152;
}
V_41 = F_89 () ;
if ( V_41 < 0 ) {
F_69 ( V_153 L_24 ) ;
goto V_154;
}
V_41 = F_90 ( & V_121 , 1 ) ;
if ( V_41 < 0 ) {
F_69 ( V_153 L_25 ) ;
goto V_155;
}
V_41 = F_91 ( & V_156 ) ;
if ( V_41 < 0 ) {
F_69 ( V_153 L_26 ) ;
goto V_157;
}
V_41 = F_92 ( & V_158 ) ;
if ( V_41 < 0 ) {
F_69 ( V_153 L_27 ) ;
goto V_159;
}
V_41 = F_92 ( & V_160 ) ;
if ( V_41 < 0 ) {
F_69 ( V_153 L_28 ) ;
goto V_161;
}
V_41 = F_93 () ;
if ( V_41 < 0 ) {
F_69 ( V_153 L_29 ) ;
goto V_162;
}
#ifdef F_94
F_95 ( L_30 , 0 , V_113 . V_163 , & V_164 ) ;
F_95 ( L_31 , 0 , V_113 . V_163 ,
& V_165 ) ;
#endif
return 0 ;
V_162:
F_96 ( & V_160 ) ;
V_161:
F_96 ( & V_158 ) ;
V_159:
F_97 ( V_120 ) ;
V_157:
F_98 ( & V_121 ) ;
V_155:
F_99 ( V_141 ) ;
V_154:
F_100 () ;
V_152:
F_101 ( V_148 ) ;
V_151:
return V_41 ;
}
static void T_6 F_102 ( void )
{
F_4 ( L_11 ) ;
F_103 () ;
F_96 ( & V_160 ) ;
F_96 ( & V_158 ) ;
F_97 ( V_120 ) ;
F_98 ( & V_121 ) ;
F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
F_46 ( F_2 ( & V_166 ) , == , 0 ) ;
F_13 ( L_32 ) ;
F_77 ( V_141 ) ;
F_109 ( L_31 , V_113 . V_163 ) ;
F_109 ( L_30 , V_113 . V_163 ) ;
F_99 ( V_141 ) ;
F_100 () ;
F_101 ( V_148 ) ;
F_26 ( L_11 ) ;
}
