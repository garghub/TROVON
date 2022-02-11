static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = V_4 -> V_10 ++ ;
if ( F_4 ( V_9 >= F_5 ( V_4 -> V_11 ) ) )
return - V_12 ;
V_4 -> V_11 [ V_9 ] = V_8 ;
return V_9 ;
}
void T_1 * F_6 ( struct V_13 * V_14 , const char * V_15 ,
const char * V_16 )
{
struct V_17 * V_18 ;
unsigned long V_19 ;
void T_1 * V_20 ;
if ( V_15 )
V_18 = F_7 ( V_14 , V_21 , V_15 ) ;
else
V_18 = F_8 ( V_14 , V_21 , 0 ) ;
if ( ! V_18 ) {
F_9 ( & V_14 -> V_2 , L_1 , V_15 ) ;
return F_10 ( - V_12 ) ;
}
V_19 = F_11 ( V_18 ) ;
V_20 = F_12 ( & V_14 -> V_2 , V_18 -> V_22 , V_19 ) ;
if ( ! V_20 ) {
F_9 ( & V_14 -> V_2 , L_2 , V_15 ) ;
return F_10 ( - V_23 ) ;
}
if ( V_24 )
F_13 ( V_25 L_3 , V_16 , V_20 , V_19 ) ;
return V_20 ;
}
void F_14 ( T_2 V_26 , void T_1 * V_27 )
{
if ( V_24 )
F_13 ( V_25 L_4 , V_27 , V_26 ) ;
F_15 ( V_26 , V_27 ) ;
}
T_2 F_16 ( const void T_1 * V_27 )
{
T_2 V_28 = F_17 ( V_27 ) ;
if ( V_24 )
F_13 ( V_29 L_5 , V_27 , V_28 ) ;
return V_28 ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_19 ( V_31 ,
struct V_32 , V_31 ) ;
struct V_3 * V_4 = F_19 ( V_33 ,
struct V_3 , V_34 ) ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 , * V_39 ;
unsigned long V_40 ;
F_20 ( & V_33 -> V_41 , V_40 ) ;
F_21 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_22 ( & V_38 -> V_42 ) ;
F_23 ( & V_33 -> V_41 , V_40 ) ;
if ( V_38 -> V_43 )
V_36 -> V_44 -> V_45 ( V_36 ,
V_4 -> V_46 [ V_38 -> V_47 ] ) ;
else
V_36 -> V_44 -> V_48 ( V_36 ,
V_4 -> V_46 [ V_38 -> V_47 ] ) ;
F_24 ( V_38 ) ;
F_20 ( & V_33 -> V_41 , V_40 ) ;
}
F_23 ( & V_33 -> V_41 , V_40 ) ;
}
static int F_25 ( struct V_3 * V_4 ,
int V_47 , bool V_43 )
{
struct V_32 * V_33 = & V_4 -> V_34 ;
struct V_37 * V_38 ;
unsigned long V_40 ;
V_38 = F_26 ( sizeof( * V_38 ) , V_49 ) ;
if ( ! V_38 )
return - V_23 ;
V_38 -> V_47 = V_47 ;
V_38 -> V_43 = V_43 ;
F_20 ( & V_33 -> V_41 , V_40 ) ;
F_27 ( & V_38 -> V_42 , & V_33 -> V_50 ) ;
F_23 ( & V_33 -> V_41 , V_40 ) ;
F_28 ( V_4 -> V_51 , & V_33 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_52 * V_53 = V_4 -> V_53 ;
struct V_32 * V_33 = & V_4 -> V_34 ;
struct V_37 * V_38 , * V_39 ;
F_30 ( & V_33 -> V_31 ) ;
F_21 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_22 ( & V_38 -> V_42 ) ;
F_24 ( V_38 ) ;
}
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_2 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 -> V_2 ) ;
F_37 ( V_4 -> V_51 ) ;
F_38 ( V_4 -> V_51 ) ;
if ( V_36 ) {
F_39 ( V_2 -> V_2 ) ;
V_36 -> V_44 -> V_54 ( V_36 ) ;
}
if ( V_53 ) {
F_40 ( & V_2 -> V_55 ) ;
V_53 -> V_44 -> V_56 ( V_53 ) ;
F_41 ( & V_2 -> V_55 ) ;
V_53 -> V_44 -> V_54 ( V_53 ) ;
}
if ( V_4 -> V_57 . V_58 ) {
F_42 ( V_59 ) ;
F_43 ( V_60 , & V_59 ) ;
F_44 ( & V_4 -> V_57 . V_61 ) ;
F_45 ( V_2 -> V_2 , V_4 -> V_57 . V_19 , NULL ,
V_4 -> V_57 . V_58 , & V_59 ) ;
}
F_46 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_5 = NULL ;
F_24 ( V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_13 * V_14 )
{
#ifdef F_48
static const struct V_62 V_63 [] = { {
. V_64 = L_6 ,
. V_26 = ( void * ) 5 ,
} , {
} } ;
struct V_65 * V_2 = & V_14 -> V_2 ;
const struct V_62 * V_66 ;
V_66 = F_49 ( V_63 , V_2 -> V_67 ) ;
if ( V_66 )
return ( int ) ( unsigned long ) V_66 -> V_26 ;
#endif
return 4 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_19 = 0 ;
int V_68 = 0 ;
#ifdef F_48
struct V_69 * V_42 ;
V_42 = F_51 ( V_2 -> V_2 -> V_67 , L_7 , 0 ) ;
if ( V_42 ) {
struct V_17 V_70 ;
V_68 = F_52 ( V_42 , 0 , & V_70 ) ;
if ( V_68 )
return V_68 ;
V_19 = V_70 . V_71 - V_70 . V_22 ;
F_53 ( L_8 , V_19 , & V_70 . V_22 ) ;
} else
#endif
if ( ! F_54 ( & V_72 ) ) {
F_53 ( L_9 , V_57 ) ;
V_19 = F_55 ( V_57 , NULL ) ;
}
if ( V_19 ) {
F_42 ( V_59 ) ;
void * V_73 ;
V_4 -> V_57 . V_19 = V_19 ;
F_56 ( & V_4 -> V_57 . V_61 , 0 , ( V_19 >> V_74 ) - 1 ) ;
F_43 ( V_60 , & V_59 ) ;
F_43 ( V_75 , & V_59 ) ;
V_73 = F_57 ( V_2 -> V_2 , V_19 ,
& V_4 -> V_57 . V_58 , V_76 , & V_59 ) ;
if ( ! V_73 ) {
F_9 ( V_2 -> V_2 , L_10 ) ;
V_4 -> V_57 . V_58 = 0 ;
return - V_23 ;
}
F_58 ( V_2 -> V_2 , L_11 ,
( V_77 ) V_4 -> V_57 . V_58 ,
( V_77 ) ( V_4 -> V_57 . V_58 + V_19 ) ) ;
}
return V_68 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned long V_40 )
{
struct V_13 * V_14 = V_2 -> V_78 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_68 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_76 ) ;
if ( ! V_4 ) {
F_9 ( V_2 -> V_2 , L_12 ) ;
return - V_23 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_51 = F_60 ( L_13 , 0 ) ;
F_61 ( & V_4 -> V_79 ) ;
F_61 ( & V_4 -> V_80 ) ;
F_62 ( & V_4 -> V_81 ) ;
F_62 ( & V_4 -> V_82 ) ;
F_62 ( & V_4 -> V_34 . V_50 ) ;
F_63 ( & V_4 -> V_34 . V_31 , F_18 ) ;
F_64 ( & V_4 -> V_34 . V_41 ) ;
F_65 ( V_2 ) ;
F_66 ( V_14 , V_2 ) ;
V_68 = F_67 ( V_2 -> V_2 , V_2 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_50 ( V_2 ) ;
if ( V_68 )
goto V_83;
switch ( F_47 ( V_14 ) ) {
case 4 :
V_36 = F_68 ( V_2 ) ;
break;
case 5 :
V_36 = F_69 ( V_2 ) ;
break;
default:
V_36 = F_10 ( - V_84 ) ;
break;
}
if ( F_70 ( V_36 ) ) {
F_9 ( V_2 -> V_2 , L_14 ) ;
V_68 = F_71 ( V_36 ) ;
goto V_83;
}
V_4 -> V_36 = V_36 ;
if ( V_36 ) {
F_72 ( V_2 -> V_2 ) ;
V_68 = V_36 -> V_44 -> V_85 ( V_36 ) ;
if ( V_68 ) {
F_9 ( V_2 -> V_2 , L_15 , V_68 ) ;
goto V_83;
}
}
V_2 -> V_86 . V_44 = & V_87 ;
V_68 = F_73 ( V_2 , V_4 -> V_88 ) ;
if ( V_68 < 0 ) {
F_9 ( V_2 -> V_2 , L_16 ) ;
goto V_83;
}
F_34 ( V_2 -> V_2 ) ;
V_68 = F_74 ( V_2 , F_75 ( V_2 -> V_78 , 0 ) ) ;
F_36 ( V_2 -> V_2 ) ;
if ( V_68 < 0 ) {
F_9 ( V_2 -> V_2 , L_17 ) ;
goto V_83;
}
F_76 ( V_2 ) ;
#ifdef F_77
if ( V_6 )
V_4 -> V_6 = F_78 ( V_2 ) ;
#endif
V_68 = F_79 ( V_2 ) ;
if ( V_68 )
goto V_83;
F_80 ( V_2 ) ;
return 0 ;
V_83:
F_29 ( V_2 ) ;
return V_68 ;
}
static void F_81 ( struct V_1 * V_2 )
{
static F_82 ( V_89 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( & V_89 ) ;
if ( ! V_4 -> V_53 )
V_4 -> V_53 = F_83 ( V_2 ) ;
F_41 ( & V_89 ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_92 * V_93 ;
F_81 ( V_2 ) ;
V_93 = F_26 ( sizeof( * V_93 ) , V_76 ) ;
if ( ! V_93 )
return - V_23 ;
V_91 -> V_94 = V_93 ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( V_36 )
V_36 -> V_44 -> V_95 ( V_36 , V_91 ) ;
F_40 ( & V_2 -> V_55 ) ;
if ( V_93 == V_4 -> V_96 )
V_4 -> V_96 = NULL ;
F_41 ( & V_2 -> V_55 ) ;
F_24 ( V_93 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_87 ( V_4 -> V_6 ) ;
}
static T_3 F_88 ( int V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_89 ( ! V_36 ) ;
return V_36 -> V_44 -> V_97 ( V_36 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_89 ( ! V_36 ) ;
V_36 -> V_44 -> V_99 ( V_36 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_89 ( ! V_36 ) ;
return V_36 -> V_44 -> V_100 ( V_36 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_89 ( ! V_36 ) ;
V_36 -> V_44 -> V_101 ( V_36 ) ;
}
static int F_93 ( struct V_1 * V_2 , unsigned int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return - V_103 ;
F_94 ( L_18 , V_2 , V_102 ) ;
return F_25 ( V_4 , V_102 , true ) ;
}
static void F_95 ( struct V_1 * V_2 , unsigned int V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return;
F_94 ( L_18 , V_2 , V_102 ) ;
F_25 ( V_4 , V_102 , false ) ;
}
static int F_96 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_53 = V_4 -> V_53 ;
if ( V_53 ) {
F_97 ( V_105 , L_19 , V_53 -> V_15 ) ;
V_53 -> V_44 -> V_106 ( V_53 , V_105 ) ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_53 = V_4 -> V_53 ;
if ( V_53 ) {
F_97 ( V_105 , L_20 , V_53 -> V_15 ) ;
F_99 ( & V_53 -> V_107 , V_105 ) ;
}
F_97 ( V_105 , L_21 ) ;
F_99 ( & V_4 -> V_81 , V_105 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
return F_101 ( V_105 , & V_2 -> V_108 -> V_109 ) ;
}
static int F_102 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_110 * V_111 , * V_112 = NULL ;
if ( V_4 -> V_6 ) {
F_97 ( V_105 , L_22 ) ;
V_112 = V_4 -> V_6 -> V_111 ;
F_103 ( V_112 , V_105 ) ;
}
F_40 ( & V_2 -> V_86 . V_113 ) ;
F_104 (fb, &dev->mode_config.fb_list, head) {
if ( V_111 == V_112 )
continue;
F_97 ( V_105 , L_23 ) ;
F_103 ( V_111 , V_105 ) ;
}
F_41 ( & V_2 -> V_86 . V_113 ) ;
return 0 ;
}
static int F_105 ( struct V_104 * V_105 , void * V_98 )
{
struct V_114 * V_42 = (struct V_114 * ) V_105 -> V_115 ;
struct V_1 * V_2 = V_42 -> V_116 -> V_2 ;
int (* V_106)( struct V_1 * V_2 , struct V_104 * V_105 ) =
V_42 -> V_117 -> V_26 ;
int V_68 ;
V_68 = F_106 ( & V_2 -> V_55 ) ;
if ( V_68 )
return V_68 ;
V_68 = V_106 ( V_2 , V_105 ) ;
F_41 ( & V_2 -> V_55 ) ;
return V_68 ;
}
static int F_107 ( struct V_118 * V_116 )
{
int V_68 ;
if ( ! V_116 )
return 0 ;
V_68 = F_108 ( V_116 ) ;
if ( V_68 ) {
F_9 ( V_116 -> V_2 -> V_2 , L_24 ) ;
return V_68 ;
}
V_68 = F_109 ( V_116 ) ;
if ( V_68 ) {
F_9 ( V_116 -> V_2 -> V_2 , L_25 ) ;
return V_68 ;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_68 ;
V_68 = F_107 ( V_2 -> V_119 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_107 ( V_2 -> V_120 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_107 ( V_2 -> V_121 ) ;
return V_68 ;
}
static int F_110 ( struct V_118 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_2 ;
int V_68 ;
V_68 = F_111 ( V_122 ,
F_5 ( V_122 ) ,
V_116 -> V_123 , V_116 ) ;
if ( V_68 ) {
F_9 ( V_2 -> V_2 , L_26 ) ;
return V_68 ;
}
return 0 ;
}
static void F_112 ( struct V_118 * V_116 )
{
F_113 ( V_122 ,
F_5 ( V_122 ) , V_116 ) ;
if ( ! V_116 -> V_2 -> V_5 )
return;
F_114 ( V_116 ) ;
F_115 ( V_116 ) ;
}
int F_116 ( struct V_1 * V_2 , V_77 V_124 ,
T_4 * V_125 , bool V_126 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_68 ;
if ( ! V_4 -> V_53 )
return 0 ;
if ( V_124 > V_4 -> V_53 -> V_127 ) {
F_117 ( L_27 ,
V_124 , V_4 -> V_53 -> V_127 ) ;
return - V_12 ;
}
if ( ! V_125 ) {
V_68 = F_118 ( V_2 , V_124 ) ? 0 : - V_128 ;
} else {
T_4 V_129 = F_119 () ;
unsigned long V_130 ;
if ( F_120 ( * V_125 , V_129 ) < 0 ) {
V_130 = 0 ;
} else {
T_4 V_131 = F_121 ( * V_125 , V_129 ) ;
struct V_132 V_133 = F_122 ( V_131 ) ;
V_130 = F_123 ( & V_133 ) ;
}
if ( V_126 )
V_68 = F_124 ( V_4 -> V_79 ,
F_118 ( V_2 , V_124 ) ,
V_130 ) ;
else
V_68 = F_125 ( V_4 -> V_79 ,
F_118 ( V_2 , V_124 ) ,
V_130 ) ;
if ( V_68 == 0 ) {
F_94 ( L_28 ,
V_124 , V_4 -> V_134 ) ;
V_68 = - V_135 ;
} else if ( V_68 != - V_136 ) {
V_68 = 0 ;
}
}
return V_68 ;
}
int F_126 ( struct V_1 * V_2 ,
struct V_137 * V_138 , V_77 V_124 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_68 = 0 ;
F_40 ( & V_2 -> V_55 ) ;
if ( ! F_127 ( & V_138 -> V_31 . V_139 ) ) {
V_68 = - V_12 ;
} else if ( V_124 > V_4 -> V_134 ) {
V_138 -> V_124 = V_124 ;
F_27 ( & V_138 -> V_31 . V_139 , & V_4 -> V_82 ) ;
} else {
F_28 ( V_4 -> V_51 , & V_138 -> V_31 ) ;
}
F_41 ( & V_2 -> V_55 ) ;
return V_68 ;
}
void F_128 ( struct V_1 * V_2 , V_77 V_124 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( & V_2 -> V_55 ) ;
V_4 -> V_134 = F_129 ( V_124 , V_4 -> V_134 ) ;
while ( ! F_127 ( & V_4 -> V_82 ) ) {
struct V_137 * V_138 ;
V_138 = F_130 ( & V_4 -> V_82 ,
struct V_137 , V_31 . V_139 ) ;
if ( V_138 -> V_124 > V_4 -> V_134 )
break;
F_131 ( & V_138 -> V_31 . V_139 ) ;
F_28 ( V_4 -> V_51 , & V_138 -> V_31 ) ;
}
F_41 ( & V_2 -> V_55 ) ;
F_132 ( & V_4 -> V_79 ) ;
}
void F_133 ( struct V_30 * V_31 )
{
struct V_137 * V_138 = F_19 ( V_31 , struct V_137 , V_31 ) ;
V_138 -> V_140 ( V_138 ) ;
}
static int F_134 ( struct V_1 * V_2 , void * V_26 ,
struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_141 * args = V_26 ;
struct V_52 * V_53 ;
if ( args -> V_102 != V_142 )
return - V_12 ;
V_53 = V_4 -> V_53 ;
if ( ! V_53 )
return - V_103 ;
return V_53 -> V_44 -> V_143 ( V_53 , args -> V_144 , & args -> V_145 ) ;
}
static int F_135 ( struct V_1 * V_2 , void * V_26 ,
struct V_90 * V_91 )
{
struct V_146 * args = V_26 ;
if ( args -> V_40 & ~ V_147 ) {
F_117 ( L_29 , args -> V_40 ) ;
return - V_12 ;
}
return F_136 ( V_2 , V_91 , args -> V_19 ,
args -> V_40 , & args -> V_148 ) ;
}
static inline T_4 F_137 ( struct V_149 V_125 )
{
return F_138 ( V_125 . V_150 , V_125 . V_151 ) ;
}
static int F_139 ( struct V_1 * V_2 , void * V_26 ,
struct V_90 * V_91 )
{
struct V_152 * args = V_26 ;
struct V_153 * V_154 ;
T_4 V_125 = F_137 ( args -> V_125 ) ;
int V_68 ;
if ( args -> V_155 & ~ V_156 ) {
F_117 ( L_30 , args -> V_155 ) ;
return - V_12 ;
}
V_154 = F_140 ( V_2 , V_91 , args -> V_148 ) ;
if ( ! V_154 )
return - V_157 ;
V_68 = F_141 ( V_154 , args -> V_155 , & V_125 ) ;
F_142 ( V_154 ) ;
return V_68 ;
}
static int F_143 ( struct V_1 * V_2 , void * V_26 ,
struct V_90 * V_91 )
{
struct V_158 * args = V_26 ;
struct V_153 * V_154 ;
int V_68 ;
V_154 = F_140 ( V_2 , V_91 , args -> V_148 ) ;
if ( ! V_154 )
return - V_157 ;
V_68 = F_144 ( V_154 ) ;
F_142 ( V_154 ) ;
return V_68 ;
}
static int F_145 ( struct V_1 * V_2 , void * V_26 ,
struct V_90 * V_91 )
{
struct V_159 * args = V_26 ;
struct V_153 * V_154 ;
int V_68 = 0 ;
if ( args -> V_160 )
return - V_12 ;
V_154 = F_140 ( V_2 , V_91 , args -> V_148 ) ;
if ( ! V_154 )
return - V_157 ;
args -> V_161 = F_146 ( V_154 ) ;
F_142 ( V_154 ) ;
return V_68 ;
}
static int F_147 ( struct V_1 * V_2 , void * V_26 ,
struct V_90 * V_91 )
{
struct V_162 * args = V_26 ;
T_4 V_125 = F_137 ( args -> V_125 ) ;
if ( args -> V_160 ) {
F_117 ( L_31 , args -> V_160 ) ;
return - V_12 ;
}
return F_116 ( V_2 , args -> V_124 , & V_125 , true ) ;
}
static int F_148 ( struct V_65 * V_2 )
{
struct V_1 * V_163 = F_149 ( V_2 ) ;
F_150 ( V_163 ) ;
return 0 ;
}
static int F_151 ( struct V_65 * V_2 )
{
struct V_1 * V_163 = F_149 ( V_2 ) ;
F_152 ( V_163 ) ;
return 0 ;
}
static int F_153 ( struct V_65 * V_2 , void * V_26 )
{
return V_2 -> V_67 == V_26 ;
}
static int F_154 ( struct V_65 * V_2 , struct V_164 * * V_165 ,
const char * V_15 )
{
struct V_69 * V_166 = V_2 -> V_67 ;
unsigned V_167 ;
for ( V_167 = 0 ; ; V_167 ++ ) {
struct V_69 * V_42 ;
V_42 = F_51 ( V_166 , V_15 , V_167 ) ;
if ( ! V_42 )
break;
F_155 ( V_2 , V_165 , F_153 , V_42 ) ;
}
return 0 ;
}
static int F_156 ( struct V_65 * V_2 , void * V_26 )
{
return V_2 == V_26 ;
}
static int F_157 ( struct V_65 * V_2 )
{
return F_158 ( & V_168 , F_159 ( V_2 ) ) ;
}
static void F_160 ( struct V_65 * V_2 )
{
F_161 ( F_162 ( F_159 ( V_2 ) ) ) ;
}
static int F_163 ( struct V_13 * V_14 )
{
struct V_164 * V_66 = NULL ;
#ifdef F_48
F_154 ( & V_14 -> V_2 , & V_66 , L_32 ) ;
F_154 ( & V_14 -> V_2 , & V_66 , L_33 ) ;
#else
static const char * V_169 [] = {
L_34 , L_35 ,
} ;
int V_167 ;
F_94 ( L_36 ) ;
for ( V_167 = 0 ; V_167 < F_5 ( V_169 ) ; V_167 ++ ) {
struct V_65 * V_2 ;
V_2 = F_164 ( & V_72 ,
NULL , V_169 [ V_167 ] ) ;
if ( ! V_2 ) {
F_58 ( & V_14 -> V_2 , L_37 , V_169 [ V_167 ] ) ;
return - V_170 ;
}
F_155 ( & V_14 -> V_2 , & V_66 , F_156 , V_2 ) ;
}
#endif
V_14 -> V_2 . V_171 = F_165 ( 32 ) ;
return F_166 ( & V_14 -> V_2 , & V_172 , V_66 ) ;
}
static int F_167 ( struct V_13 * V_14 )
{
F_168 ( & V_14 -> V_2 , & V_172 ) ;
return 0 ;
}
static int T_5 F_169 ( void )
{
F_94 ( L_38 ) ;
F_170 () ;
F_171 () ;
F_172 () ;
F_173 () ;
return F_174 ( & V_173 ) ;
}
static void T_6 F_175 ( void )
{
F_94 ( L_39 ) ;
F_176 ( & V_173 ) ;
F_177 () ;
F_178 () ;
F_179 () ;
F_180 () ;
}
