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
F_13 ( V_25 L_3 , V_16 , ( V_26 ) V_20 , V_19 ) ;
return V_20 ;
}
void F_14 ( V_26 V_27 , void T_1 * V_28 )
{
if ( V_24 )
F_13 ( V_25 L_4 , ( V_26 ) V_28 , V_27 ) ;
F_15 ( V_27 , V_28 ) ;
}
V_26 F_16 ( const void T_1 * V_28 )
{
V_26 V_29 = F_17 ( V_28 ) ;
if ( V_24 )
F_13 ( V_30 L_5 , ( V_26 ) V_28 , V_29 ) ;
return V_29 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_34 ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 -> V_2 ) ;
F_25 ( V_4 -> V_35 ) ;
F_26 ( V_4 -> V_35 ) ;
if ( V_32 ) {
F_27 ( V_2 -> V_2 ) ;
V_32 -> V_36 -> V_37 ( V_32 ) ;
}
if ( V_34 ) {
F_28 ( & V_2 -> V_38 ) ;
V_34 -> V_36 -> V_39 ( V_34 ) ;
V_34 -> V_36 -> V_37 ( V_34 ) ;
F_29 ( & V_2 -> V_38 ) ;
}
if ( V_4 -> V_40 . V_41 ) {
F_30 ( V_42 ) ;
F_31 ( V_43 , & V_42 ) ;
F_32 ( & V_4 -> V_40 . V_44 ) ;
F_33 ( V_2 -> V_2 , V_4 -> V_40 . V_19 , NULL ,
V_4 -> V_40 . V_41 , & V_42 ) ;
}
F_34 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_5 = NULL ;
F_35 ( V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_13 * V_14 )
{
#ifdef F_37
static const struct V_45 V_46 [] = { {
. V_47 = L_6 ,
. V_27 = ( void * ) 5 ,
} , {
} } ;
struct V_48 * V_2 = & V_14 -> V_2 ;
const struct V_45 * V_49 ;
V_49 = F_38 ( V_46 , V_2 -> V_50 ) ;
if ( V_49 )
return ( int ) V_49 -> V_27 ;
#endif
return 4 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_51 )
{
struct V_13 * V_14 = V_2 -> V_52 ;
struct V_3 * V_4 ;
struct V_31 * V_32 ;
int V_53 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 ) {
F_9 ( V_2 -> V_2 , L_7 ) ;
return - V_23 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_35 = F_41 ( L_8 , 0 ) ;
F_42 ( & V_4 -> V_55 ) ;
F_43 ( & V_4 -> V_56 ) ;
F_43 ( & V_4 -> V_57 ) ;
F_44 ( V_2 ) ;
if ( ! F_45 ( & V_58 ) ) {
F_30 ( V_42 ) ;
unsigned long V_19 ;
void * V_59 ;
F_46 ( L_9 , V_40 ) ;
V_19 = F_47 ( V_40 , NULL ) ;
V_4 -> V_40 . V_19 = V_19 ;
F_48 ( & V_4 -> V_40 . V_44 , 0 , ( V_19 >> V_60 ) - 1 ) ;
F_31 ( V_43 , & V_42 ) ;
F_31 ( V_61 , & V_42 ) ;
V_59 = F_49 ( V_2 -> V_2 , V_19 ,
& V_4 -> V_40 . V_41 , V_54 , & V_42 ) ;
if ( ! V_59 ) {
F_9 ( V_2 -> V_2 , L_10 ) ;
V_4 -> V_40 . V_41 = 0 ;
V_53 = - V_23 ;
goto V_62;
}
F_50 ( V_2 -> V_2 , L_11 ,
( V_63 ) V_4 -> V_40 . V_41 ,
( V_63 ) ( V_4 -> V_40 . V_41 + V_19 ) ) ;
}
F_51 ( V_14 , V_2 ) ;
V_53 = F_52 ( V_2 -> V_2 , V_2 ) ;
if ( V_53 )
return V_53 ;
switch ( F_36 ( V_14 ) ) {
case 4 :
V_32 = F_53 ( V_2 ) ;
break;
case 5 :
V_32 = F_54 ( V_2 ) ;
break;
default:
V_32 = F_10 ( - V_64 ) ;
break;
}
if ( F_55 ( V_32 ) ) {
F_9 ( V_2 -> V_2 , L_12 ) ;
V_53 = F_56 ( V_32 ) ;
goto V_62;
}
V_4 -> V_32 = V_32 ;
if ( V_32 ) {
F_57 ( V_2 -> V_2 ) ;
V_53 = V_32 -> V_36 -> V_65 ( V_32 ) ;
if ( V_53 ) {
F_9 ( V_2 -> V_2 , L_13 , V_53 ) ;
goto V_62;
}
}
V_2 -> V_66 . V_67 = 0 ;
V_2 -> V_66 . V_68 = 0 ;
V_2 -> V_66 . V_69 = 2048 ;
V_2 -> V_66 . V_70 = 2048 ;
V_2 -> V_66 . V_36 = & V_71 ;
V_53 = F_58 ( V_2 , 1 ) ;
if ( V_53 < 0 ) {
F_9 ( V_2 -> V_2 , L_14 ) ;
goto V_62;
}
F_22 ( V_2 -> V_2 ) ;
V_53 = F_59 ( V_2 , F_60 ( V_2 -> V_52 , 0 ) ) ;
F_24 ( V_2 -> V_2 ) ;
if ( V_53 < 0 ) {
F_9 ( V_2 -> V_2 , L_15 ) ;
goto V_62;
}
#ifdef F_61
V_4 -> V_6 = F_62 ( V_2 ) ;
#endif
V_53 = F_63 ( V_2 ) ;
if ( V_53 )
goto V_62;
F_64 ( V_2 ) ;
return 0 ;
V_62:
F_18 ( V_2 ) ;
return V_53 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 ;
if ( V_4 -> V_34 )
return;
F_28 ( & V_2 -> V_38 ) ;
V_34 = F_66 ( V_2 ) ;
if ( F_55 ( V_34 ) ) {
F_67 ( V_2 -> V_2 , L_16 ) ;
V_34 = NULL ;
}
if ( V_34 ) {
int V_53 ;
V_34 -> V_36 -> V_72 ( V_34 ) ;
V_53 = V_34 -> V_36 -> V_65 ( V_34 ) ;
if ( V_53 ) {
F_9 ( V_2 -> V_2 , L_17 , V_53 ) ;
V_34 -> V_36 -> V_37 ( V_34 ) ;
V_34 = NULL ;
} else {
F_68 ( V_34 ) ;
}
}
V_4 -> V_34 = V_34 ;
F_29 ( & V_2 -> V_38 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_75 * V_76 ;
F_65 ( V_2 ) ;
V_76 = F_40 ( sizeof( * V_76 ) , V_54 ) ;
if ( ! V_76 )
return - V_23 ;
V_74 -> V_77 = V_76 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_75 * V_76 = V_74 -> V_77 ;
struct V_31 * V_32 = V_4 -> V_32 ;
if ( V_32 )
V_32 -> V_36 -> V_78 ( V_32 , V_74 ) ;
F_28 ( & V_2 -> V_38 ) ;
if ( V_76 == V_4 -> V_79 )
V_4 -> V_79 = NULL ;
F_29 ( & V_2 -> V_38 ) ;
F_35 ( V_76 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_72 ( V_4 -> V_6 ) ;
}
static T_2 F_73 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
return V_32 -> V_36 -> V_80 ( V_32 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
V_32 -> V_36 -> V_82 ( V_32 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
return V_32 -> V_36 -> V_83 ( V_32 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
V_32 -> V_36 -> V_84 ( V_32 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_85 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
if ( ! V_32 )
return - V_86 ;
F_46 ( L_18 , V_2 , V_85 ) ;
return V_32 -> V_36 -> V_87 ( V_32 , V_4 -> V_88 [ V_85 ] ) ;
}
static void F_79 ( struct V_1 * V_2 , int V_85 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
if ( ! V_32 )
return;
F_46 ( L_18 , V_2 , V_85 ) ;
V_32 -> V_36 -> V_89 ( V_32 , V_4 -> V_88 [ V_85 ] ) ;
}
static int F_80 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 = V_4 -> V_34 ;
if ( V_34 ) {
F_81 ( V_91 , L_19 , V_34 -> V_15 ) ;
V_34 -> V_36 -> V_92 ( V_34 , V_91 ) ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 = V_4 -> V_34 ;
if ( V_34 ) {
F_81 ( V_91 , L_20 , V_34 -> V_15 ) ;
F_83 ( & V_34 -> V_93 , V_91 ) ;
}
F_81 ( V_91 , L_21 ) ;
F_83 ( & V_4 -> V_56 , V_91 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
return F_85 ( V_91 , & V_2 -> V_94 -> V_95 ) ;
}
static int F_86 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_96 * V_97 , * V_98 = NULL ;
if ( V_4 -> V_6 ) {
F_81 ( V_91 , L_22 ) ;
V_98 = V_4 -> V_6 -> V_97 ;
F_87 ( V_98 , V_91 ) ;
}
F_28 ( & V_2 -> V_66 . V_99 ) ;
F_88 (fb, &dev->mode_config.fb_list, head) {
if ( V_97 == V_98 )
continue;
F_81 ( V_91 , L_23 ) ;
F_87 ( V_97 , V_91 ) ;
}
F_29 ( & V_2 -> V_66 . V_99 ) ;
return 0 ;
}
static int F_89 ( struct V_90 * V_91 , void * V_81 )
{
struct V_100 * V_101 = (struct V_100 * ) V_91 -> V_102 ;
struct V_1 * V_2 = V_101 -> V_103 -> V_2 ;
int (* V_92)( struct V_1 * V_2 , struct V_90 * V_91 ) =
V_101 -> V_104 -> V_27 ;
int V_53 ;
V_53 = F_90 ( & V_2 -> V_38 ) ;
if ( V_53 )
return V_53 ;
V_53 = V_92 ( V_2 , V_91 ) ;
F_29 ( & V_2 -> V_38 ) ;
return V_53 ;
}
static int F_91 ( struct V_105 * V_103 )
{
int V_53 ;
if ( ! V_103 )
return 0 ;
V_53 = F_92 ( V_103 ) ;
if ( V_53 ) {
F_9 ( V_103 -> V_2 -> V_2 , L_24 ) ;
return V_53 ;
}
V_53 = F_93 ( V_103 ) ;
if ( V_53 ) {
F_9 ( V_103 -> V_2 -> V_2 , L_25 ) ;
return V_53 ;
}
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
int V_53 ;
V_53 = F_91 ( V_2 -> V_106 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_91 ( V_2 -> V_107 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_91 ( V_2 -> V_108 ) ;
return V_53 ;
}
static int F_94 ( struct V_105 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_2 ;
int V_53 ;
V_53 = F_95 ( V_109 ,
F_5 ( V_109 ) ,
V_103 -> V_110 , V_103 ) ;
if ( V_53 ) {
F_9 ( V_2 -> V_2 , L_26 ) ;
return V_53 ;
}
return 0 ;
}
static void F_96 ( struct V_105 * V_103 )
{
F_97 ( V_109 ,
F_5 ( V_109 ) , V_103 ) ;
if ( ! V_103 -> V_2 -> V_5 )
return;
F_98 ( V_103 ) ;
F_99 ( V_103 ) ;
}
int F_100 ( struct V_1 * V_2 , V_63 V_111 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_53 ;
if ( ! V_4 -> V_34 )
return 0 ;
if ( V_111 > V_4 -> V_34 -> V_114 ) {
F_101 ( L_27 ,
V_111 , V_4 -> V_34 -> V_114 ) ;
return - V_12 ;
}
if ( ! V_113 ) {
V_53 = F_102 ( V_2 , V_111 ) ? 0 : - V_115 ;
} else {
unsigned long V_116 = F_103 ( V_113 ) ;
unsigned long V_117 = V_118 ;
unsigned long V_119 ;
if ( F_104 ( V_117 , V_116 ) )
V_119 = 0 ;
else
V_119 = V_116 - V_117 ;
V_53 = F_105 ( V_4 -> V_55 ,
F_102 ( V_2 , V_111 ) ,
V_119 ) ;
if ( V_53 == 0 ) {
F_46 ( L_28 ,
V_111 , V_4 -> V_120 ) ;
V_53 = - V_121 ;
} else if ( V_53 != - V_122 ) {
V_53 = 0 ;
}
}
return V_53 ;
}
void F_106 ( struct V_1 * V_2 , V_63 V_111 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_28 ( & V_2 -> V_38 ) ;
V_4 -> V_120 = F_107 ( V_111 , V_4 -> V_120 ) ;
while ( ! F_108 ( & V_4 -> V_57 ) ) {
struct V_123 * V_124 ;
V_124 = F_109 ( & V_4 -> V_57 ,
struct V_123 , V_125 . V_126 ) ;
if ( V_124 -> V_111 > V_4 -> V_120 )
break;
F_110 ( & V_124 -> V_125 . V_126 ) ;
F_111 ( V_4 -> V_35 , & V_124 -> V_125 ) ;
}
F_29 ( & V_2 -> V_38 ) ;
F_112 ( & V_4 -> V_55 ) ;
}
void F_113 ( struct V_127 * V_125 )
{
struct V_123 * V_124 = F_114 ( V_125 , struct V_123 , V_125 ) ;
V_124 -> V_128 ( V_124 ) ;
}
static int F_115 ( struct V_1 * V_2 , void * V_27 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_129 * args = V_27 ;
struct V_33 * V_34 ;
if ( args -> V_130 != V_131 )
return - V_12 ;
V_34 = V_4 -> V_34 ;
if ( ! V_34 )
return - V_86 ;
return V_34 -> V_36 -> V_132 ( V_34 , args -> V_133 , & args -> V_134 ) ;
}
static int F_116 ( struct V_1 * V_2 , void * V_27 ,
struct V_73 * V_74 )
{
struct V_135 * args = V_27 ;
if ( args -> V_51 & ~ V_136 ) {
F_101 ( L_29 , args -> V_51 ) ;
return - V_12 ;
}
return F_117 ( V_2 , V_74 , args -> V_19 ,
args -> V_51 , & args -> V_137 ) ;
}
static int F_118 ( struct V_1 * V_2 , void * V_27 ,
struct V_73 * V_74 )
{
struct V_138 * args = V_27 ;
struct V_139 * V_140 ;
int V_53 ;
if ( args -> V_141 & ~ V_142 ) {
F_101 ( L_30 , args -> V_141 ) ;
return - V_12 ;
}
V_140 = F_119 ( V_2 , V_74 , args -> V_137 ) ;
if ( ! V_140 )
return - V_143 ;
V_53 = F_120 ( V_140 , args -> V_141 , & F_121 ( args -> V_113 ) ) ;
F_122 ( V_140 ) ;
return V_53 ;
}
static int F_123 ( struct V_1 * V_2 , void * V_27 ,
struct V_73 * V_74 )
{
struct V_144 * args = V_27 ;
struct V_139 * V_140 ;
int V_53 ;
V_140 = F_119 ( V_2 , V_74 , args -> V_137 ) ;
if ( ! V_140 )
return - V_143 ;
V_53 = F_124 ( V_140 ) ;
F_122 ( V_140 ) ;
return V_53 ;
}
static int F_125 ( struct V_1 * V_2 , void * V_27 ,
struct V_73 * V_74 )
{
struct V_145 * args = V_27 ;
struct V_139 * V_140 ;
int V_53 = 0 ;
if ( args -> V_146 )
return - V_12 ;
V_140 = F_119 ( V_2 , V_74 , args -> V_137 ) ;
if ( ! V_140 )
return - V_143 ;
args -> V_147 = F_126 ( V_140 ) ;
F_122 ( V_140 ) ;
return V_53 ;
}
static int F_127 ( struct V_1 * V_2 , void * V_27 ,
struct V_73 * V_74 )
{
struct V_148 * args = V_27 ;
if ( args -> V_146 ) {
F_101 ( L_31 , args -> V_146 ) ;
return - V_12 ;
}
return F_100 ( V_2 , args -> V_111 ,
& F_121 ( args -> V_113 ) ) ;
}
static int F_128 ( struct V_48 * V_2 )
{
struct V_1 * V_149 = F_129 ( V_2 ) ;
F_130 ( V_149 ) ;
return 0 ;
}
static int F_131 ( struct V_48 * V_2 )
{
struct V_1 * V_149 = F_129 ( V_2 ) ;
F_132 ( V_149 ) ;
return 0 ;
}
static int F_133 ( struct V_48 * V_2 , void * V_27 )
{
return V_2 -> V_50 == V_27 ;
}
static int F_134 ( struct V_48 * V_150 , struct V_150 * V_91 )
{
struct V_151 * V_152 = V_150 -> V_50 ;
unsigned V_153 ;
int V_53 ;
for ( V_153 = 0 ; ; V_153 ++ ) {
struct V_151 * V_101 ;
V_101 = F_135 ( V_152 , L_32 , V_153 ) ;
if ( ! V_101 )
break;
V_53 = F_136 ( V_91 , F_133 , V_101 ) ;
F_137 ( V_101 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_138 ( struct V_48 * V_2 , void * V_27 )
{
return V_2 == V_27 ;
}
static int F_134 ( struct V_48 * V_150 , struct V_150 * V_91 )
{
static const char * V_154 [] = {
L_33 , L_34 ,
} ;
int V_153 ;
F_46 ( L_35 ) ;
for ( V_153 = 0 ; V_153 < F_5 ( V_154 ) ; V_153 ++ ) {
struct V_48 * V_2 ;
int V_53 ;
V_2 = F_139 ( & V_58 ,
NULL , V_154 [ V_153 ] ) ;
if ( ! V_2 ) {
F_50 ( V_150 , L_36 , V_154 [ V_153 ] ) ;
return - V_155 ;
}
V_53 = F_136 ( V_91 , F_138 , V_2 ) ;
if ( V_53 ) {
F_46 ( L_37 , V_53 ) ;
return V_53 ;
}
}
return 0 ;
}
static int F_140 ( struct V_48 * V_2 )
{
return F_141 ( & V_156 , F_142 ( V_2 ) ) ;
}
static void F_143 ( struct V_48 * V_2 )
{
F_144 ( F_145 ( F_142 ( V_2 ) ) ) ;
}
static int F_146 ( struct V_13 * V_14 )
{
V_14 -> V_2 . V_157 = F_147 ( 32 ) ;
return F_148 ( & V_14 -> V_2 , & V_158 ) ;
}
static int F_149 ( struct V_13 * V_14 )
{
F_150 ( & V_14 -> V_2 , & V_158 ) ;
return 0 ;
}
static int T_3 F_151 ( void )
{
F_46 ( L_38 ) ;
F_152 () ;
F_153 () ;
return F_154 ( & V_159 ) ;
}
static void T_4 F_155 ( void )
{
F_46 ( L_39 ) ;
F_156 ( & V_159 ) ;
F_157 () ;
F_158 () ;
}
