static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 , struct V_9 * V_2 ,
unsigned long V_10 , int V_11 , void * V_12 )
{
F_4 ( L_1 , V_10 , V_11 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_13 = V_4 -> V_14 ++ ;
if ( F_6 ( V_13 >= F_7 ( V_4 -> V_15 ) ) )
return - V_16 ;
V_4 -> V_15 [ V_13 ] = V_8 ;
F_8 ( V_8 , F_3 , V_2 ) ;
return V_13 ;
}
int F_9 ( struct V_1 * V_2 , struct V_7 * V_8 ,
const char * * V_17 , int V_18 )
{
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
struct V_9 * V_21 ( const char * V_22 ) ;
struct V_9 * V_23 = V_21 ( V_17 [ V_19 ] ) ;
if ( ! V_23 )
continue;
V_20 = F_10 ( V_8 , V_23 ) ;
if ( V_20 ) {
F_11 ( V_2 -> V_2 , L_2 , V_17 [ V_19 ] ) ;
return V_20 ;
}
}
return 0 ;
}
void T_1 * F_12 ( struct V_24 * V_25 , const char * V_26 ,
const char * V_27 )
{
struct V_28 * V_29 ;
unsigned long V_30 ;
void T_1 * V_31 ;
if ( V_26 )
V_29 = F_13 ( V_25 , V_32 , V_26 ) ;
else
V_29 = F_14 ( V_25 , V_32 , 0 ) ;
if ( ! V_29 ) {
F_15 ( & V_25 -> V_2 , L_3 , V_26 ) ;
return F_16 ( - V_16 ) ;
}
V_30 = F_17 ( V_29 ) ;
V_31 = F_18 ( & V_25 -> V_2 , V_29 -> V_33 , V_30 ) ;
if ( ! V_31 ) {
F_15 ( & V_25 -> V_2 , L_4 , V_26 ) ;
return F_16 ( - V_34 ) ;
}
if ( V_35 )
F_19 ( V_36 L_5 , V_27 , ( V_37 ) V_31 , V_30 ) ;
return V_31 ;
}
void F_20 ( V_37 V_38 , void T_1 * V_39 )
{
if ( V_35 )
F_19 ( V_36 L_6 , ( V_37 ) V_39 , V_38 ) ;
F_21 ( V_38 , V_39 ) ;
}
V_37 F_22 ( const void T_1 * V_39 )
{
V_37 V_40 = F_23 ( V_39 ) ;
if ( V_35 )
F_19 ( V_41 L_7 , ( V_37 ) V_39 , V_40 ) ;
return V_40 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
struct V_44 * V_45 = V_4 -> V_45 ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_2 ) ;
F_31 ( V_4 -> V_46 ) ;
F_32 ( V_4 -> V_46 ) ;
if ( V_43 ) {
F_33 ( V_2 -> V_2 ) ;
V_43 -> V_47 -> V_48 ( V_43 ) ;
}
if ( V_45 ) {
F_34 ( & V_2 -> V_49 ) ;
V_45 -> V_47 -> V_50 ( V_45 ) ;
V_45 -> V_47 -> V_48 ( V_45 ) ;
F_35 ( & V_2 -> V_49 ) ;
}
V_2 -> V_5 = NULL ;
F_36 ( V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned long V_11 )
{
struct V_24 * V_25 = V_2 -> V_51 ;
struct V_3 * V_4 ;
struct V_42 * V_43 ;
int V_20 ;
V_4 = F_38 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 ) {
F_15 ( V_2 -> V_2 , L_8 ) ;
return - V_34 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_46 = F_39 ( L_9 , 0 ) ;
F_40 ( & V_4 -> V_53 ) ;
F_41 ( & V_4 -> V_54 ) ;
F_41 ( & V_4 -> V_55 ) ;
F_42 ( V_2 ) ;
V_43 = F_43 ( V_2 ) ;
if ( F_44 ( V_43 ) ) {
F_15 ( V_2 -> V_2 , L_10 ) ;
V_20 = F_45 ( V_43 ) ;
goto V_56;
}
V_4 -> V_43 = V_43 ;
if ( V_43 ) {
F_46 ( V_2 -> V_2 ) ;
V_20 = V_43 -> V_47 -> V_57 ( V_43 ) ;
if ( V_20 ) {
F_15 ( V_2 -> V_2 , L_11 , V_20 ) ;
goto V_56;
}
}
V_2 -> V_58 . V_59 = 0 ;
V_2 -> V_58 . V_60 = 0 ;
V_2 -> V_58 . V_61 = 2048 ;
V_2 -> V_58 . V_62 = 2048 ;
V_2 -> V_58 . V_47 = & V_63 ;
V_20 = F_47 ( V_2 , 1 ) ;
if ( V_20 < 0 ) {
F_15 ( V_2 -> V_2 , L_12 ) ;
goto V_56;
}
F_28 ( V_2 -> V_2 ) ;
V_20 = F_48 ( V_2 ) ;
F_30 ( V_2 -> V_2 ) ;
if ( V_20 < 0 ) {
F_15 ( V_2 -> V_2 , L_13 ) ;
goto V_56;
}
F_49 ( V_25 , V_2 ) ;
#ifdef F_50
V_4 -> V_6 = F_51 ( V_2 ) ;
#endif
F_52 ( V_2 ) ;
return 0 ;
V_56:
F_24 ( V_2 ) ;
return V_20 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_44 * V_45 ;
if ( V_4 -> V_45 )
return;
F_34 ( & V_2 -> V_49 ) ;
V_45 = F_54 ( V_2 ) ;
if ( F_44 ( V_45 ) ) {
F_11 ( V_2 -> V_2 , L_14 ) ;
V_45 = NULL ;
}
F_35 ( & V_2 -> V_49 ) ;
if ( V_45 ) {
int V_20 ;
V_45 -> V_47 -> V_64 ( V_45 ) ;
V_20 = V_45 -> V_47 -> V_57 ( V_45 ) ;
if ( V_20 ) {
F_15 ( V_2 -> V_2 , L_15 , V_20 ) ;
V_45 -> V_47 -> V_48 ( V_45 ) ;
V_45 = NULL ;
}
}
V_4 -> V_45 = V_45 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_67 * V_23 ;
F_53 ( V_2 ) ;
V_23 = F_38 ( sizeof( * V_23 ) , V_52 ) ;
if ( ! V_23 )
return - V_34 ;
V_66 -> V_68 = V_23 ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_23 = V_66 -> V_68 ;
struct V_42 * V_43 = V_4 -> V_43 ;
if ( V_43 )
V_43 -> V_47 -> V_69 ( V_43 , V_66 ) ;
F_34 ( & V_2 -> V_49 ) ;
if ( V_23 == V_4 -> V_70 )
V_4 -> V_70 = NULL ;
F_35 ( & V_2 -> V_49 ) ;
F_36 ( V_23 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 ) {
F_58 ( V_2 ) ;
F_59 ( V_4 -> V_6 ) ;
F_60 ( V_2 ) ;
}
}
static T_2 F_61 ( T_3 )
{
struct V_1 * V_2 = V_12 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
F_62 ( ! V_43 ) ;
return V_43 -> V_47 -> V_71 ( V_43 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
F_62 ( ! V_43 ) ;
V_43 -> V_47 -> V_72 ( V_43 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
F_62 ( ! V_43 ) ;
return V_43 -> V_47 -> V_73 ( V_43 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
F_62 ( ! V_43 ) ;
V_43 -> V_47 -> V_74 ( V_43 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
if ( ! V_43 )
return - V_76 ;
F_4 ( L_16 , V_2 , V_75 ) ;
return V_43 -> V_47 -> V_77 ( V_43 , V_4 -> V_78 [ V_75 ] ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_42 * V_43 = V_4 -> V_43 ;
if ( ! V_43 )
return;
F_4 ( L_16 , V_2 , V_75 ) ;
V_43 -> V_47 -> V_79 ( V_43 , V_4 -> V_78 [ V_75 ] ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_44 * V_45 = V_4 -> V_45 ;
if ( V_45 ) {
F_69 ( V_81 , L_17 , V_45 -> V_26 ) ;
V_45 -> V_47 -> V_82 ( V_45 , V_81 ) ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_44 * V_45 = V_4 -> V_45 ;
if ( V_45 ) {
F_69 ( V_81 , L_18 , V_45 -> V_26 ) ;
F_71 ( & V_45 -> V_83 , V_81 ) ;
}
F_69 ( V_81 , L_19 ) ;
F_71 ( & V_4 -> V_54 , V_81 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
return F_73 ( V_81 , V_2 -> V_84 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_85 * V_86 , * V_87 = NULL ;
if ( V_4 -> V_6 ) {
F_69 ( V_81 , L_20 ) ;
V_87 = V_4 -> V_6 -> V_86 ;
F_75 ( V_87 , V_81 ) ;
}
F_34 ( & V_2 -> V_58 . V_88 ) ;
F_76 (fb, &dev->mode_config.fb_list, head) {
if ( V_86 == V_87 )
continue;
F_69 ( V_81 , L_21 ) ;
F_75 ( V_86 , V_81 ) ;
}
F_35 ( & V_2 -> V_58 . V_88 ) ;
return 0 ;
}
static int F_77 ( struct V_80 * V_81 , void * V_12 )
{
struct V_89 * V_90 = (struct V_89 * ) V_81 -> V_91 ;
struct V_1 * V_2 = V_90 -> V_92 -> V_2 ;
int (* V_82)( struct V_1 * V_2 , struct V_80 * V_81 ) =
V_90 -> V_93 -> V_38 ;
int V_20 ;
V_20 = F_78 ( & V_2 -> V_49 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_82 ( V_2 , V_81 ) ;
F_35 ( & V_2 -> V_49 ) ;
return V_20 ;
}
static int F_79 ( struct V_94 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_2 ;
int V_20 ;
V_20 = F_80 ( V_95 ,
F_7 ( V_95 ) ,
V_92 -> V_96 , V_92 ) ;
if ( V_20 ) {
F_15 ( V_2 -> V_2 , L_22 ) ;
return V_20 ;
}
return V_20 ;
}
static void F_81 ( struct V_94 * V_92 )
{
F_82 ( V_95 ,
F_7 ( V_95 ) , V_92 ) ;
}
int F_83 ( struct V_1 * V_2 , T_4 V_97 ,
struct V_98 * V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_20 ;
if ( ! V_4 -> V_45 )
return 0 ;
if ( V_97 > V_4 -> V_45 -> V_100 ) {
F_84 ( L_23 ,
V_97 , V_4 -> V_45 -> V_100 ) ;
return - V_16 ;
}
if ( ! V_99 ) {
V_20 = F_85 ( V_2 , V_97 ) ? 0 : - V_101 ;
} else {
unsigned long V_102 = F_86 ( V_99 ) ;
unsigned long V_103 = V_104 ;
unsigned long V_105 ;
if ( F_87 ( V_103 , V_102 ) )
V_105 = 0 ;
else
V_105 = V_102 - V_103 ;
V_20 = F_88 ( V_4 -> V_53 ,
F_85 ( V_2 , V_97 ) ,
V_105 ) ;
if ( V_20 == 0 ) {
F_4 ( L_24 ,
V_97 , V_4 -> V_106 ) ;
V_20 = - V_107 ;
} else if ( V_20 != - V_108 ) {
V_20 = 0 ;
}
}
return V_20 ;
}
void F_89 ( struct V_1 * V_2 , T_4 V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_34 ( & V_2 -> V_49 ) ;
V_4 -> V_106 = F_90 ( V_97 , V_4 -> V_106 ) ;
while ( ! F_91 ( & V_4 -> V_55 ) ) {
struct V_109 * V_110 ;
V_110 = F_92 ( & V_4 -> V_55 ,
struct V_109 , V_111 . V_112 ) ;
if ( V_110 -> V_97 > V_4 -> V_106 )
break;
F_93 ( & V_110 -> V_111 . V_112 ) ;
F_94 ( V_4 -> V_46 , & V_110 -> V_111 ) ;
}
F_35 ( & V_2 -> V_49 ) ;
F_95 ( & V_4 -> V_53 ) ;
}
void F_96 ( struct V_113 * V_111 )
{
struct V_109 * V_110 = F_97 ( V_111 , struct V_109 , V_111 ) ;
V_110 -> V_114 ( V_110 ) ;
}
static int F_98 ( struct V_1 * V_2 , void * V_38 ,
struct V_65 * V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_115 * args = V_38 ;
struct V_44 * V_45 ;
if ( args -> V_116 != V_117 )
return - V_16 ;
V_45 = V_4 -> V_45 ;
if ( ! V_45 )
return - V_76 ;
return V_45 -> V_47 -> V_118 ( V_45 , args -> V_119 , & args -> V_120 ) ;
}
static int F_99 ( struct V_1 * V_2 , void * V_38 ,
struct V_65 * V_66 )
{
struct V_121 * args = V_38 ;
return F_100 ( V_2 , V_66 , args -> V_30 ,
args -> V_11 , & args -> V_122 ) ;
}
static int F_101 ( struct V_1 * V_2 , void * V_38 ,
struct V_65 * V_66 )
{
struct V_123 * args = V_38 ;
struct V_124 * V_125 ;
int V_20 ;
V_125 = F_102 ( V_2 , V_66 , args -> V_122 ) ;
if ( ! V_125 )
return - V_126 ;
V_20 = F_103 ( V_125 , args -> V_127 , & F_104 ( args -> V_99 ) ) ;
F_105 ( V_125 ) ;
return V_20 ;
}
static int F_106 ( struct V_1 * V_2 , void * V_38 ,
struct V_65 * V_66 )
{
struct V_128 * args = V_38 ;
struct V_124 * V_125 ;
int V_20 ;
V_125 = F_102 ( V_2 , V_66 , args -> V_122 ) ;
if ( ! V_125 )
return - V_126 ;
V_20 = F_107 ( V_125 ) ;
F_105 ( V_125 ) ;
return V_20 ;
}
static int F_108 ( struct V_1 * V_2 , void * V_38 ,
struct V_65 * V_66 )
{
struct V_129 * args = V_38 ;
struct V_124 * V_125 ;
int V_20 = 0 ;
if ( args -> V_130 )
return - V_16 ;
V_125 = F_102 ( V_2 , V_66 , args -> V_122 ) ;
if ( ! V_125 )
return - V_126 ;
args -> V_131 = F_109 ( V_125 ) ;
F_105 ( V_125 ) ;
return V_20 ;
}
static int F_110 ( struct V_1 * V_2 , void * V_38 ,
struct V_65 * V_66 )
{
struct V_132 * args = V_38 ;
return F_83 ( V_2 , args -> V_97 , & F_104 ( args -> V_99 ) ) ;
}
static int F_111 ( struct V_9 * V_2 )
{
struct V_1 * V_133 = F_112 ( V_2 ) ;
F_113 ( V_133 ) ;
return 0 ;
}
static int F_114 ( struct V_9 * V_2 )
{
struct V_1 * V_133 = F_112 ( V_2 ) ;
F_115 ( V_133 ) ;
return 0 ;
}
static int F_116 ( struct V_24 * V_25 )
{
return F_117 ( & V_134 , V_25 ) ;
}
static int F_118 ( struct V_24 * V_25 )
{
F_119 ( & V_134 , V_25 ) ;
return 0 ;
}
static int T_5 F_120 ( void )
{
F_4 ( L_25 ) ;
F_121 () ;
F_122 () ;
return F_123 ( & V_135 ) ;
}
static void T_6 F_124 ( void )
{
F_4 ( L_26 ) ;
F_125 ( & V_135 ) ;
F_126 () ;
F_127 () ;
}
