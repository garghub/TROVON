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
struct V_62 * V_2 = & V_14 -> V_2 ;
return ( int ) ( unsigned long ) F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_63 * V_42 ;
unsigned long V_19 = 0 ;
int V_64 = 0 ;
V_42 = F_50 ( V_2 -> V_2 -> V_65 , L_6 , 0 ) ;
if ( V_42 ) {
struct V_17 V_66 ;
V_64 = F_51 ( V_42 , 0 , & V_66 ) ;
if ( V_64 )
return V_64 ;
V_19 = V_66 . V_67 - V_66 . V_22 ;
F_52 ( L_7 , V_19 , & V_66 . V_22 ) ;
} else if ( ! F_53 ( & V_68 ) ) {
F_52 ( L_8 , V_57 ) ;
V_19 = F_54 ( V_57 , NULL ) ;
}
if ( V_19 ) {
F_42 ( V_59 ) ;
void * V_69 ;
V_4 -> V_57 . V_19 = V_19 ;
F_55 ( & V_4 -> V_57 . V_61 , 0 , ( V_19 >> V_70 ) - 1 ) ;
F_43 ( V_60 , & V_59 ) ;
F_43 ( V_71 , & V_59 ) ;
V_69 = F_56 ( V_2 -> V_2 , V_19 ,
& V_4 -> V_57 . V_58 , V_72 , & V_59 ) ;
if ( ! V_69 ) {
F_9 ( V_2 -> V_2 , L_9 ) ;
V_4 -> V_57 . V_58 = 0 ;
return - V_23 ;
}
F_57 ( V_2 -> V_2 , L_10 ,
( V_73 ) V_4 -> V_57 . V_58 ,
( V_73 ) ( V_4 -> V_57 . V_58 + V_19 ) ) ;
}
return V_64 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned long V_40 )
{
struct V_13 * V_14 = V_2 -> V_74 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_64 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_72 ) ;
if ( ! V_4 ) {
F_9 ( V_2 -> V_2 , L_11 ) ;
return - V_23 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_51 = F_59 ( L_12 , 0 ) ;
F_60 ( & V_4 -> V_75 ) ;
F_60 ( & V_4 -> V_76 ) ;
F_61 ( & V_4 -> V_77 ) ;
F_61 ( & V_4 -> V_78 ) ;
F_61 ( & V_4 -> V_34 . V_50 ) ;
F_62 ( & V_4 -> V_34 . V_31 , F_18 ) ;
F_63 ( & V_4 -> V_34 . V_41 ) ;
F_64 ( V_2 ) ;
F_65 ( V_14 , V_2 ) ;
V_64 = F_66 ( V_2 -> V_2 , V_2 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_49 ( V_2 ) ;
if ( V_64 )
goto V_79;
switch ( F_47 ( V_14 ) ) {
case 4 :
V_36 = F_67 ( V_2 ) ;
break;
case 5 :
V_36 = F_68 ( V_2 ) ;
break;
default:
V_36 = F_10 ( - V_80 ) ;
break;
}
if ( F_69 ( V_36 ) ) {
F_9 ( V_2 -> V_2 , L_13 ) ;
V_64 = F_70 ( V_36 ) ;
goto V_79;
}
V_4 -> V_36 = V_36 ;
if ( V_36 ) {
F_71 ( V_2 -> V_2 ) ;
V_64 = V_36 -> V_44 -> V_81 ( V_36 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_2 , L_14 , V_64 ) ;
goto V_79;
}
}
V_2 -> V_82 . V_44 = & V_83 ;
V_64 = F_72 ( V_2 , V_4 -> V_84 ) ;
if ( V_64 < 0 ) {
F_9 ( V_2 -> V_2 , L_15 ) ;
goto V_79;
}
F_34 ( V_2 -> V_2 ) ;
V_64 = F_73 ( V_2 , F_74 ( V_2 -> V_74 , 0 ) ) ;
F_36 ( V_2 -> V_2 ) ;
if ( V_64 < 0 ) {
F_9 ( V_2 -> V_2 , L_16 ) ;
goto V_79;
}
F_75 ( V_2 ) ;
#ifdef F_76
if ( V_6 )
V_4 -> V_6 = F_77 ( V_2 ) ;
#endif
V_64 = F_78 ( V_2 ) ;
if ( V_64 )
goto V_79;
F_79 ( V_2 ) ;
return 0 ;
V_79:
F_29 ( V_2 ) ;
return V_64 ;
}
static void F_80 ( struct V_1 * V_2 )
{
static F_81 ( V_85 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( & V_85 ) ;
if ( ! V_4 -> V_53 )
V_4 -> V_53 = F_82 ( V_2 ) ;
F_41 ( & V_85 ) ;
}
static int F_83 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_88 * V_89 ;
F_80 ( V_2 ) ;
V_89 = F_26 ( sizeof( * V_89 ) , V_72 ) ;
if ( ! V_89 )
return - V_23 ;
V_87 -> V_90 = V_89 ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_88 * V_89 = V_87 -> V_90 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( V_36 )
V_36 -> V_44 -> V_91 ( V_36 , V_87 ) ;
F_40 ( & V_2 -> V_55 ) ;
if ( V_89 == V_4 -> V_92 )
V_4 -> V_92 = NULL ;
F_41 ( & V_2 -> V_55 ) ;
F_24 ( V_89 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_86 ( V_4 -> V_6 ) ;
}
static T_3 F_87 ( int V_93 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_88 ( ! V_36 ) ;
return V_36 -> V_44 -> V_93 ( V_36 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_88 ( ! V_36 ) ;
V_36 -> V_44 -> V_95 ( V_36 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_88 ( ! V_36 ) ;
return V_36 -> V_44 -> V_96 ( V_36 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_88 ( ! V_36 ) ;
V_36 -> V_44 -> V_97 ( V_36 ) ;
}
static int F_92 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return - V_99 ;
F_93 ( L_17 , V_2 , V_98 ) ;
return F_25 ( V_4 , V_98 , true ) ;
}
static void F_94 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return;
F_93 ( L_17 , V_2 , V_98 ) ;
F_25 ( V_4 , V_98 , false ) ;
}
static int F_95 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_53 = V_4 -> V_53 ;
if ( V_53 ) {
F_96 ( V_101 , L_18 , V_53 -> V_15 ) ;
V_53 -> V_44 -> V_102 ( V_53 , V_101 ) ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_53 = V_4 -> V_53 ;
if ( V_53 ) {
F_96 ( V_101 , L_19 , V_53 -> V_15 ) ;
F_98 ( & V_53 -> V_103 , V_101 ) ;
}
F_96 ( V_101 , L_20 ) ;
F_98 ( & V_4 -> V_77 , V_101 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
return F_100 ( V_101 , & V_2 -> V_104 -> V_105 ) ;
}
static int F_101 ( struct V_1 * V_2 , struct V_100 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_106 * V_107 , * V_108 = NULL ;
if ( V_4 -> V_6 ) {
F_96 ( V_101 , L_21 ) ;
V_108 = V_4 -> V_6 -> V_107 ;
F_102 ( V_108 , V_101 ) ;
}
F_40 ( & V_2 -> V_82 . V_109 ) ;
F_103 (fb, &dev->mode_config.fb_list, head) {
if ( V_107 == V_108 )
continue;
F_96 ( V_101 , L_22 ) ;
F_102 ( V_107 , V_101 ) ;
}
F_41 ( & V_2 -> V_82 . V_109 ) ;
return 0 ;
}
static int F_104 ( struct V_100 * V_101 , void * V_94 )
{
struct V_110 * V_42 = (struct V_110 * ) V_101 -> V_111 ;
struct V_1 * V_2 = V_42 -> V_112 -> V_2 ;
int (* V_102)( struct V_1 * V_2 , struct V_100 * V_101 ) =
V_42 -> V_113 -> V_26 ;
int V_64 ;
V_64 = F_105 ( & V_2 -> V_55 ) ;
if ( V_64 )
return V_64 ;
V_64 = V_102 ( V_2 , V_101 ) ;
F_41 ( & V_2 -> V_55 ) ;
return V_64 ;
}
static int F_106 ( struct V_114 * V_112 )
{
int V_64 ;
if ( ! V_112 )
return 0 ;
V_64 = F_107 ( V_112 ) ;
if ( V_64 ) {
F_9 ( V_112 -> V_2 -> V_2 , L_23 ) ;
return V_64 ;
}
V_64 = F_108 ( V_112 ) ;
if ( V_64 ) {
F_9 ( V_112 -> V_2 -> V_2 , L_24 ) ;
return V_64 ;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
int V_64 ;
V_64 = F_106 ( V_2 -> V_115 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_106 ( V_2 -> V_116 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_106 ( V_2 -> V_117 ) ;
return V_64 ;
}
static int F_109 ( struct V_114 * V_112 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
int V_64 ;
V_64 = F_110 ( V_118 ,
F_5 ( V_118 ) ,
V_112 -> V_119 , V_112 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_2 , L_25 ) ;
return V_64 ;
}
return 0 ;
}
static void F_111 ( struct V_114 * V_112 )
{
F_112 ( V_118 ,
F_5 ( V_118 ) , V_112 ) ;
if ( ! V_112 -> V_2 -> V_5 )
return;
F_113 ( V_112 ) ;
F_114 ( V_112 ) ;
}
int F_115 ( struct V_1 * V_2 , V_73 V_120 ,
T_4 * V_121 , bool V_122 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 ;
if ( ! V_4 -> V_53 )
return 0 ;
if ( V_120 > V_4 -> V_53 -> V_123 ) {
F_116 ( L_26 ,
V_120 , V_4 -> V_53 -> V_123 ) ;
return - V_12 ;
}
if ( ! V_121 ) {
V_64 = F_117 ( V_2 , V_120 ) ? 0 : - V_124 ;
} else {
T_4 V_125 = F_118 () ;
unsigned long V_126 ;
if ( F_119 ( * V_121 , V_125 ) < 0 ) {
V_126 = 0 ;
} else {
T_4 V_127 = F_120 ( * V_121 , V_125 ) ;
struct V_128 V_129 = F_121 ( V_127 ) ;
V_126 = F_122 ( & V_129 ) ;
}
if ( V_122 )
V_64 = F_123 ( V_4 -> V_75 ,
F_117 ( V_2 , V_120 ) ,
V_126 ) ;
else
V_64 = F_124 ( V_4 -> V_75 ,
F_117 ( V_2 , V_120 ) ,
V_126 ) ;
if ( V_64 == 0 ) {
F_93 ( L_27 ,
V_120 , V_4 -> V_130 ) ;
V_64 = - V_131 ;
} else if ( V_64 != - V_132 ) {
V_64 = 0 ;
}
}
return V_64 ;
}
int F_125 ( struct V_1 * V_2 ,
struct V_133 * V_134 , V_73 V_120 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_64 = 0 ;
F_40 ( & V_2 -> V_55 ) ;
if ( ! F_126 ( & V_134 -> V_31 . V_135 ) ) {
V_64 = - V_12 ;
} else if ( V_120 > V_4 -> V_130 ) {
V_134 -> V_120 = V_120 ;
F_27 ( & V_134 -> V_31 . V_135 , & V_4 -> V_78 ) ;
} else {
F_28 ( V_4 -> V_51 , & V_134 -> V_31 ) ;
}
F_41 ( & V_2 -> V_55 ) ;
return V_64 ;
}
void F_127 ( struct V_1 * V_2 , V_73 V_120 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_40 ( & V_2 -> V_55 ) ;
V_4 -> V_130 = F_128 ( V_120 , V_4 -> V_130 ) ;
while ( ! F_126 ( & V_4 -> V_78 ) ) {
struct V_133 * V_134 ;
V_134 = F_129 ( & V_4 -> V_78 ,
struct V_133 , V_31 . V_135 ) ;
if ( V_134 -> V_120 > V_4 -> V_130 )
break;
F_130 ( & V_134 -> V_31 . V_135 ) ;
F_28 ( V_4 -> V_51 , & V_134 -> V_31 ) ;
}
F_41 ( & V_2 -> V_55 ) ;
F_131 ( & V_4 -> V_75 ) ;
}
void F_132 ( struct V_30 * V_31 )
{
struct V_133 * V_134 = F_19 ( V_31 , struct V_133 , V_31 ) ;
V_134 -> V_136 ( V_134 ) ;
}
static int F_133 ( struct V_1 * V_2 , void * V_26 ,
struct V_86 * V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_137 * args = V_26 ;
struct V_52 * V_53 ;
if ( args -> V_98 != V_138 )
return - V_12 ;
V_53 = V_4 -> V_53 ;
if ( ! V_53 )
return - V_99 ;
return V_53 -> V_44 -> V_139 ( V_53 , args -> V_140 , & args -> V_141 ) ;
}
static int F_134 ( struct V_1 * V_2 , void * V_26 ,
struct V_86 * V_87 )
{
struct V_142 * args = V_26 ;
if ( args -> V_40 & ~ V_143 ) {
F_116 ( L_28 , args -> V_40 ) ;
return - V_12 ;
}
return F_135 ( V_2 , V_87 , args -> V_19 ,
args -> V_40 , & args -> V_144 ) ;
}
static inline T_4 F_136 ( struct V_145 V_121 )
{
return F_137 ( V_121 . V_146 , V_121 . V_147 ) ;
}
static int F_138 ( struct V_1 * V_2 , void * V_26 ,
struct V_86 * V_87 )
{
struct V_148 * args = V_26 ;
struct V_149 * V_150 ;
T_4 V_121 = F_136 ( args -> V_121 ) ;
int V_64 ;
if ( args -> V_151 & ~ V_152 ) {
F_116 ( L_29 , args -> V_151 ) ;
return - V_12 ;
}
V_150 = F_139 ( V_2 , V_87 , args -> V_144 ) ;
if ( ! V_150 )
return - V_153 ;
V_64 = F_140 ( V_150 , args -> V_151 , & V_121 ) ;
F_141 ( V_150 ) ;
return V_64 ;
}
static int F_142 ( struct V_1 * V_2 , void * V_26 ,
struct V_86 * V_87 )
{
struct V_154 * args = V_26 ;
struct V_149 * V_150 ;
int V_64 ;
V_150 = F_139 ( V_2 , V_87 , args -> V_144 ) ;
if ( ! V_150 )
return - V_153 ;
V_64 = F_143 ( V_150 ) ;
F_141 ( V_150 ) ;
return V_64 ;
}
static int F_144 ( struct V_1 * V_2 , void * V_26 ,
struct V_86 * V_87 )
{
struct V_155 * args = V_26 ;
struct V_149 * V_150 ;
int V_64 = 0 ;
if ( args -> V_156 )
return - V_12 ;
V_150 = F_139 ( V_2 , V_87 , args -> V_144 ) ;
if ( ! V_150 )
return - V_153 ;
args -> V_157 = F_145 ( V_150 ) ;
F_141 ( V_150 ) ;
return V_64 ;
}
static int F_146 ( struct V_1 * V_2 , void * V_26 ,
struct V_86 * V_87 )
{
struct V_158 * args = V_26 ;
T_4 V_121 = F_136 ( args -> V_121 ) ;
if ( args -> V_156 ) {
F_116 ( L_30 , args -> V_156 ) ;
return - V_12 ;
}
return F_115 ( V_2 , args -> V_120 , & V_121 , true ) ;
}
static int F_147 ( struct V_62 * V_2 )
{
struct V_1 * V_159 = F_148 ( V_2 ) ;
F_149 ( V_159 ) ;
return 0 ;
}
static int F_150 ( struct V_62 * V_2 )
{
struct V_1 * V_159 = F_148 ( V_2 ) ;
F_151 ( V_159 ) ;
return 0 ;
}
static int F_152 ( struct V_62 * V_2 , void * V_26 )
{
return V_2 -> V_65 == V_26 ;
}
static int F_153 ( struct V_62 * V_2 , struct V_160 * * V_161 ,
const char * V_15 )
{
struct V_63 * V_162 = V_2 -> V_65 ;
unsigned V_163 ;
for ( V_163 = 0 ; ; V_163 ++ ) {
struct V_63 * V_42 ;
V_42 = F_50 ( V_162 , V_15 , V_163 ) ;
if ( ! V_42 )
break;
F_154 ( V_2 , V_161 , F_152 , V_42 ) ;
}
return 0 ;
}
static int F_155 ( struct V_62 * V_2 )
{
return F_156 ( & V_164 , F_157 ( V_2 ) ) ;
}
static void F_158 ( struct V_62 * V_2 )
{
F_159 ( F_160 ( F_157 ( V_2 ) ) ) ;
}
static int F_161 ( struct V_13 * V_14 )
{
struct V_160 * V_165 = NULL ;
F_153 ( & V_14 -> V_2 , & V_165 , L_31 ) ;
F_153 ( & V_14 -> V_2 , & V_165 , L_32 ) ;
V_14 -> V_2 . V_166 = F_162 ( 32 ) ;
return F_163 ( & V_14 -> V_2 , & V_167 , V_165 ) ;
}
static int F_164 ( struct V_13 * V_14 )
{
F_165 ( & V_14 -> V_2 , & V_167 ) ;
return 0 ;
}
static int T_5 F_166 ( void )
{
F_93 ( L_33 ) ;
F_167 () ;
F_168 () ;
F_169 () ;
F_170 () ;
return F_171 ( & V_168 ) ;
}
static void T_6 F_172 ( void )
{
F_93 ( L_34 ) ;
F_173 ( & V_168 ) ;
F_174 () ;
F_175 () ;
F_176 () ;
F_177 () ;
}
