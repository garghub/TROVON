static int F_1 ( int V_1 , void * V_2 , void * V_3 )
{
int * V_4 = V_3 ;
* V_4 = * V_4 + 1 ;
return 0 ;
}
static T_1 F_2 ( struct V_5 * V_5 , char T_2 * V_6 , T_3 V_7 ,
T_4 * V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return F_3 ( V_6 , V_7 , V_8 , V_10 -> V_6 , V_10 -> V_12 ) ;
}
static int F_4 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
struct V_9 * V_15 = V_3 ;
int V_16 ;
int V_17 ;
if ( V_1 != V_14 -> V_18 . V_19 . V_20 )
return 0 ;
V_16 = V_15 -> V_21 - V_15 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_14 -> V_22 )
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_1
L_2 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_23 . V_20 , ( int ) V_14 -> V_24 . V_25 ,
V_14 -> V_18 . V_19 . V_26 & V_27 ,
V_14 -> V_22 -> V_28 , ( int ) V_14 -> V_22 -> V_29 . V_25 ,
& V_14 -> V_22 -> V_29 . V_30 . V_31 . V_32 ,
F_5 ( V_14 -> V_22 -> V_29 . V_30 . V_33 ) ,
& V_14 -> V_22 -> V_29 . V_34 . V_31 . V_32 ,
F_5 ( V_14 -> V_22 -> V_29 . V_34 . V_33 ) ) ;
else
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_3 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_23 . V_20 ,
( int ) V_14 -> V_24 . V_25 ,
V_14 -> V_18 . V_19 . V_26 & V_27 ) ;
if ( V_17 < V_16 )
V_15 -> V_12 += V_17 ;
return 0 ;
}
static int F_6 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_15 = V_5 -> V_11 ;
if ( ! V_15 ) {
F_7 ( V_36 L_4 , V_37 ) ;
return 0 ;
}
F_8 ( V_15 -> V_6 ) ;
F_9 ( V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_15 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_15 = F_11 ( sizeof *V_15 , V_39 ) ;
if ( ! V_15 ) {
V_38 = - V_40 ;
goto V_41;
}
V_15 -> V_42 = V_35 -> V_43 ;
V_15 -> V_12 = 0 ;
F_12 ( & V_15 -> V_42 -> V_44 ) ;
F_13 ( & V_15 -> V_42 -> V_45 , F_1 , & V_7 ) ;
F_14 ( & V_15 -> V_42 -> V_44 ) ;
V_15 -> V_21 = V_7 * 128 ;
V_15 -> V_6 = F_15 ( V_15 -> V_21 ) ;
if ( ! V_15 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_12 ( & V_15 -> V_42 -> V_44 ) ;
F_13 ( & V_15 -> V_42 -> V_45 , F_4 , V_15 ) ;
F_14 ( & V_15 -> V_42 -> V_44 ) ;
V_15 -> V_6 [ V_15 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_15 ;
goto V_41;
V_46:
F_9 ( V_15 ) ;
V_41:
return V_38 ;
}
static int F_16 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_9 * V_47 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_47 -> V_21 - V_47 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
V_17 = snprintf ( V_47 -> V_6 + V_47 -> V_12 , V_16 , L_5 , V_1 << 8 ) ;
if ( V_17 < V_16 )
V_47 -> V_12 += V_17 ;
return 0 ;
}
static int F_17 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_47 = V_5 -> V_11 ;
if ( ! V_47 ) {
F_7 ( V_36 L_6 , V_37 ) ;
return 0 ;
}
F_9 ( V_47 -> V_6 ) ;
F_9 ( V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_47 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_47 = F_11 ( sizeof *V_47 , V_39 ) ;
if ( ! V_47 ) {
V_38 = - V_40 ;
goto V_41;
}
V_47 -> V_42 = V_35 -> V_43 ;
V_47 -> V_12 = 0 ;
F_12 ( & V_47 -> V_42 -> V_44 ) ;
F_13 ( & V_47 -> V_42 -> V_48 , F_1 , & V_7 ) ;
F_14 ( & V_47 -> V_42 -> V_44 ) ;
V_47 -> V_21 = V_7 * sizeof( L_7 ) ;
V_47 -> V_6 = F_11 ( V_47 -> V_21 , V_39 ) ;
if ( ! V_47 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_12 ( & V_47 -> V_42 -> V_44 ) ;
F_13 ( & V_47 -> V_42 -> V_48 , F_16 , V_47 ) ;
F_14 ( & V_47 -> V_42 -> V_44 ) ;
V_47 -> V_6 [ V_47 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_47 ;
goto V_41;
V_46:
F_9 ( V_47 ) ;
V_41:
return V_38 ;
}
static int F_19 ( struct V_49 * V_50 , void * V_51 )
{
struct V_52 * V_53 = V_50 -> V_54 ;
F_20 ( V_50 , L_8 , L_9 , L_10 ,
L_11 , L_12 ) ;
F_20 ( V_50 , L_13 ,
V_53 -> V_55 . V_56 . V_57 . V_58 , V_53 -> V_55 . V_56 . V_57 . V_59 ,
V_53 -> V_55 . V_56 . V_57 . V_60 , V_53 -> V_55 . V_56 . V_57 . V_61 ) ;
F_20 ( V_50 , L_14 ,
V_53 -> V_55 . V_56 . V_20 . V_58 , V_53 -> V_55 . V_56 . V_20 . V_59 ,
V_53 -> V_55 . V_56 . V_20 . V_60 , V_53 -> V_55 . V_56 . V_20 . V_61 ) ;
F_20 ( V_50 , L_15 ,
V_53 -> V_55 . V_56 . V_62 . V_58 , V_53 -> V_55 . V_56 . V_62 . V_59 ,
V_53 -> V_55 . V_56 . V_62 . V_60 , V_53 -> V_55 . V_56 . V_62 . V_61 ) ;
F_20 ( V_50 , L_16 ,
V_53 -> V_55 . V_56 . V_63 . V_58 , V_53 -> V_55 . V_56 . V_63 . V_59 ,
V_53 -> V_55 . V_56 . V_63 . V_60 , V_53 -> V_55 . V_56 . V_63 . V_61 ) ;
F_20 ( V_50 , L_17 ,
V_53 -> V_55 . V_56 . V_64 . V_58 , V_53 -> V_55 . V_56 . V_64 . V_59 ,
V_53 -> V_55 . V_56 . V_64 . V_60 , V_53 -> V_55 . V_56 . V_64 . V_61 ) ;
F_20 ( V_50 , L_18 ,
V_53 -> V_55 . V_56 . V_65 . V_58 , V_53 -> V_55 . V_56 . V_65 . V_59 ,
V_53 -> V_55 . V_56 . V_65 . V_60 , V_53 -> V_55 . V_56 . V_65 . V_61 ) ;
F_20 ( V_50 , L_19 , V_53 -> V_55 . V_56 . V_66 ) ;
F_20 ( V_50 , L_20 , V_53 -> V_55 . V_56 . V_67 ) ;
F_20 ( V_50 , L_21 , V_53 -> V_55 . V_56 . V_68 ) ;
F_20 ( V_50 , L_22 ,
V_69 [ V_53 -> V_70 ] ,
V_53 -> V_55 . V_56 . V_71 ) ;
F_20 ( V_50 , L_23 , V_53 -> V_55 . V_56 . V_72 ) ;
F_20 ( V_50 , L_24 ,
V_53 -> V_55 . V_56 . V_73 ) ;
F_20 ( V_50 , L_25 ,
V_53 -> V_55 . V_56 . V_74 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
return F_22 ( V_5 , F_19 , V_35 -> V_43 ) ;
}
static T_1 F_23 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_12 )
{
struct V_52 * V_53 = ( (struct V_49 * ) V_5 -> V_11 ) -> V_54 ;
F_24 ( & V_53 -> V_55 . V_56 . V_44 ) ;
V_53 -> V_55 . V_56 . V_57 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_57 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_20 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_20 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_62 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_62 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_63 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_63 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_64 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_64 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_65 . V_60 = 0 ;
V_53 -> V_55 . V_56 . V_65 . V_61 = 0 ;
V_53 -> V_55 . V_56 . V_66 = 0 ;
V_53 -> V_55 . V_56 . V_67 = 0 ;
V_53 -> V_55 . V_56 . V_68 = 0 ;
V_53 -> V_55 . V_56 . V_71 = 0 ;
V_53 -> V_55 . V_56 . V_72 = 0 ;
V_53 -> V_55 . V_56 . V_73 = 0 ;
V_53 -> V_55 . V_56 . V_74 = 0 ;
F_25 ( & V_53 -> V_55 . V_56 . V_44 ) ;
return V_7 ;
}
static int F_26 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_75 * V_22 = V_2 ;
struct V_9 * V_76 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_76 -> V_21 - V_76 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
V_17 = snprintf ( V_76 -> V_6 + V_76 -> V_12 , V_16 ,
L_26
L_27 ,
V_22 , V_22 -> V_29 . V_77 , V_22 -> V_29 . V_14 , ( int ) V_22 -> V_29 . V_25 ,
V_22 -> V_29 . V_26 , V_22 -> V_29 . V_78 , V_22 -> V_28 , V_22 -> V_79 ,
& V_22 -> V_29 . V_30 . V_31 . V_32 ,
F_5 ( V_22 -> V_29 . V_30 . V_33 ) ,
& V_22 -> V_29 . V_34 . V_31 . V_32 ,
F_5 ( V_22 -> V_29 . V_34 . V_33 ) ) ;
if ( V_17 < V_16 )
V_76 -> V_12 += V_17 ;
return 0 ;
}
static int F_27 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_80 * V_22 = V_2 ;
struct V_9 * V_76 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_76 -> V_21 - V_76 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
V_17 = snprintf ( V_76 -> V_6 + V_76 -> V_12 , V_16 ,
L_28
L_29 , V_22 , V_22 -> V_29 . V_77 , ( int ) V_22 -> V_29 . V_25 ,
V_22 -> V_29 . V_26 , V_22 -> V_81 , V_22 -> V_82 ,
& V_22 -> V_29 . V_30 . V_31 . V_32 ,
F_5 ( V_22 -> V_29 . V_30 . V_33 ) ) ;
if ( V_17 < V_16 )
V_76 -> V_12 += V_17 ;
return 0 ;
}
static int F_28 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_76 = V_5 -> V_11 ;
if ( ! V_76 ) {
F_29 ( L_4 , V_37 ) ;
return 0 ;
}
F_8 ( V_76 -> V_6 ) ;
F_9 ( V_76 ) ;
return 0 ;
}
static int F_30 ( struct V_35 * V_35 , struct V_5 * V_5 )
{
struct V_9 * V_76 ;
int V_38 = 0 ;
int V_7 = 1 ;
V_76 = F_11 ( sizeof( * V_76 ) , V_39 ) ;
if ( ! V_76 ) {
V_38 = - V_40 ;
goto V_41;
}
V_76 -> V_42 = V_35 -> V_43 ;
V_76 -> V_12 = 0 ;
F_12 ( & V_76 -> V_42 -> V_44 ) ;
F_13 ( & V_76 -> V_42 -> V_83 , F_1 , & V_7 ) ;
F_13 ( & V_76 -> V_42 -> V_84 , F_1 , & V_7 ) ;
F_13 ( & V_76 -> V_42 -> V_85 , F_1 , & V_7 ) ;
F_14 ( & V_76 -> V_42 -> V_44 ) ;
V_76 -> V_21 = V_7 * 160 ;
V_76 -> V_6 = F_15 ( V_76 -> V_21 ) ;
if ( ! V_76 -> V_6 ) {
V_38 = - V_40 ;
goto V_46;
}
F_12 ( & V_76 -> V_42 -> V_44 ) ;
F_13 ( & V_76 -> V_42 -> V_83 , F_26 , V_76 ) ;
F_13 ( & V_76 -> V_42 -> V_84 , F_26 , V_76 ) ;
F_13 ( & V_76 -> V_42 -> V_85 , F_27 , V_76 ) ;
F_14 ( & V_76 -> V_42 -> V_44 ) ;
V_5 -> V_11 = V_76 ;
goto V_41;
V_46:
F_9 ( V_76 ) ;
V_41:
return V_38 ;
}
static int F_31 ( struct V_52 * V_42 )
{
struct V_86 * V_87 ;
if ( ! V_42 -> V_88 )
return - 1 ;
V_87 = F_32 ( L_30 , V_89 , V_42 -> V_88 ,
( void * ) V_42 , & V_90 ) ;
if ( V_87 && V_87 -> V_91 )
V_87 -> V_91 -> V_92 = 4096 ;
V_87 = F_32 ( L_31 , V_89 , V_42 -> V_88 ,
( void * ) V_42 , & V_93 ) ;
if ( V_87 && V_87 -> V_91 )
V_87 -> V_91 -> V_92 = 4096 ;
V_87 = F_32 ( L_32 , V_89 , V_42 -> V_88 ,
( void * ) V_42 , & V_94 ) ;
if ( V_87 && V_87 -> V_91 )
V_87 -> V_91 -> V_92 = 4096 ;
V_87 = F_32 ( L_33 , V_89 , V_42 -> V_88 ,
( void * ) V_42 , & V_95 ) ;
if ( V_87 && V_87 -> V_91 )
V_87 -> V_91 -> V_92 = 4096 ;
return 0 ;
}
void F_33 ( struct V_96 * V_55 ,
struct V_97 * V_98 )
{
struct V_99 * V_12 , * V_100 ;
struct V_101 * V_102 ;
F_24 ( & V_98 -> V_44 ) ;
F_34 (pos, nxt, &uctx->qpids) {
V_102 = F_35 ( V_12 , struct V_101 , V_102 ) ;
F_36 ( & V_102 -> V_102 ) ;
if ( ! ( V_102 -> V_20 & V_55 -> V_103 ) ) {
F_37 ( & V_55 -> V_104 . V_105 ,
V_102 -> V_20 ) ;
F_24 ( & V_55 -> V_56 . V_44 ) ;
V_55 -> V_56 . V_20 . V_59 -= V_55 -> V_103 + 1 ;
F_25 ( & V_55 -> V_56 . V_44 ) ;
}
F_9 ( V_102 ) ;
}
F_34 (pos, nxt, &uctx->qpids) {
V_102 = F_35 ( V_12 , struct V_101 , V_102 ) ;
F_36 ( & V_102 -> V_102 ) ;
F_9 ( V_102 ) ;
}
F_25 ( & V_98 -> V_44 ) ;
}
void F_38 ( struct V_96 * V_55 ,
struct V_97 * V_98 )
{
F_39 ( & V_98 -> V_106 ) ;
F_39 ( & V_98 -> V_107 ) ;
F_40 ( & V_98 -> V_44 ) ;
}
static int F_41 ( struct V_96 * V_55 )
{
int V_108 ;
F_38 ( V_55 , & V_55 -> V_98 ) ;
V_55 -> V_109 = V_110 - F_42 ( V_55 -> V_111 . V_112 ) ;
V_55 -> V_103 = V_55 -> V_111 . V_112 - 1 ;
V_55 -> V_113 = V_110 - F_42 ( V_55 -> V_111 . V_114 ) ;
V_55 -> V_115 = V_55 -> V_111 . V_114 - 1 ;
F_43 ( L_34
L_35
L_36 ,
V_37 , F_44 ( V_55 -> V_111 . V_116 ) , V_55 -> V_111 . V_117 -> V_62 . V_118 ,
V_55 -> V_111 . V_117 -> V_62 . V_119 , F_45 ( V_55 ) ,
V_55 -> V_111 . V_117 -> V_63 . V_118 ,
V_55 -> V_111 . V_117 -> V_63 . V_119 , V_55 -> V_111 . V_117 -> V_23 . V_118 ,
V_55 -> V_111 . V_117 -> V_23 . V_119 ,
V_55 -> V_111 . V_117 -> V_14 . V_118 ,
V_55 -> V_111 . V_117 -> V_14 . V_119 ,
V_55 -> V_111 . V_117 -> V_120 . V_118 ,
V_55 -> V_111 . V_117 -> V_120 . V_119 ) ;
F_43 ( L_37
L_38 ,
( unsigned ) F_46 ( V_55 -> V_111 . V_116 , 2 ) ,
( void * ) ( unsigned long ) F_47 ( V_55 -> V_111 . V_116 , 2 ) ,
V_55 -> V_111 . V_121 ,
V_55 -> V_111 . V_122 ,
V_55 -> V_109 , V_55 -> V_103 ,
V_55 -> V_113 , V_55 -> V_115 ) ;
if ( F_45 ( V_55 ) == 0 ) {
V_108 = - V_123 ;
goto V_46;
}
V_55 -> V_56 . V_57 . V_58 = V_124 ;
V_55 -> V_56 . V_62 . V_58 = V_55 -> V_111 . V_117 -> V_62 . V_119 ;
V_55 -> V_56 . V_63 . V_58 = V_55 -> V_111 . V_117 -> V_63 . V_119 ;
V_55 -> V_56 . V_64 . V_58 = V_55 -> V_111 . V_117 -> V_23 . V_119 ;
V_55 -> V_56 . V_65 . V_58 = V_55 -> V_111 . V_117 -> V_125 . V_119 ;
V_55 -> V_56 . V_20 . V_58 = V_55 -> V_111 . V_117 -> V_14 . V_119 ;
V_108 = F_48 ( V_55 , F_45 ( V_55 ) , V_124 ) ;
if ( V_108 ) {
F_7 (KERN_ERR MOD L_39 , err) ;
goto V_46;
}
V_108 = F_49 ( V_55 ) ;
if ( V_108 ) {
F_7 (KERN_ERR MOD L_40 , err) ;
goto V_126;
}
V_108 = F_50 ( V_55 ) ;
if ( V_108 ) {
F_7 (KERN_ERR MOD L_41 , err) ;
goto V_127;
}
V_108 = F_51 ( V_55 ) ;
if ( V_108 ) {
F_7 (KERN_ERR MOD L_42 , err) ;
goto V_128;
}
return 0 ;
V_128:
F_52 ( V_55 ) ;
V_127:
F_53 ( V_55 ) ;
V_126:
F_54 ( & V_55 -> V_104 ) ;
V_46:
return V_108 ;
}
static void F_55 ( struct V_96 * V_55 )
{
F_53 ( V_55 ) ;
F_52 ( V_55 ) ;
F_54 ( & V_55 -> V_104 ) ;
}
static void F_56 ( struct V_129 * V_130 )
{
F_55 ( & V_130 -> V_53 -> V_55 ) ;
F_57 ( & V_130 -> V_53 -> V_131 ) ;
F_57 ( & V_130 -> V_53 -> V_45 ) ;
F_57 ( & V_130 -> V_53 -> V_48 ) ;
F_57 ( & V_130 -> V_53 -> V_83 ) ;
F_57 ( & V_130 -> V_53 -> V_85 ) ;
F_57 ( & V_130 -> V_53 -> V_84 ) ;
F_58 ( V_130 -> V_53 -> V_55 . V_132 ) ;
F_59 ( & V_130 -> V_53 -> V_133 ) ;
V_130 -> V_53 = NULL ;
}
static void F_60 ( struct V_129 * V_130 )
{
F_43 ( L_43 , V_37 , V_130 -> V_53 ) ;
F_61 ( V_130 -> V_53 ) ;
F_56 ( V_130 ) ;
}
static int F_62 ( const struct V_134 * V_135 )
{
return V_135 -> V_117 -> V_62 . V_119 > 0 && V_135 -> V_117 -> V_63 . V_119 > 0 &&
V_135 -> V_117 -> V_23 . V_119 > 0 && V_135 -> V_117 -> V_14 . V_119 > 0 &&
V_135 -> V_117 -> V_120 . V_119 > 0 && V_135 -> V_117 -> V_125 . V_119 > 0 ;
}
static struct V_52 * F_63 ( const struct V_134 * V_135 )
{
struct V_52 * V_42 ;
int V_38 ;
if ( ! F_62 ( V_135 ) ) {
F_7 (KERN_INFO MOD L_44 ,
pci_name(infop->pdev)) ;
return F_64 ( - V_136 ) ;
}
V_42 = (struct V_52 * ) F_65 ( sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
F_7 (KERN_ERR MOD L_45 ) ;
return F_64 ( - V_40 ) ;
}
V_42 -> V_55 . V_111 = * V_135 ;
V_42 -> V_55 . V_137 = F_47 ( V_42 -> V_55 . V_111 . V_116 , 2 ) +
( F_46 ( V_42 -> V_55 . V_111 . V_116 , 2 ) -
F_66 ( V_42 -> V_55 . V_111 . V_117 -> V_125 . V_119 ) ) ;
V_42 -> V_55 . V_132 = F_67 ( V_42 -> V_55 . V_137 ,
V_42 -> V_55 . V_111 . V_117 -> V_125 . V_119 ) ;
F_43 (KERN_INFO MOD L_46
L_47 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_38 = F_41 ( & V_42 -> V_55 ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_48 , ret) ;
F_59 ( & V_42 -> V_133 ) ;
return F_64 ( V_38 ) ;
}
F_68 ( & V_42 -> V_131 ) ;
F_68 ( & V_42 -> V_45 ) ;
F_68 ( & V_42 -> V_48 ) ;
F_68 ( & V_42 -> V_83 ) ;
F_68 ( & V_42 -> V_85 ) ;
F_68 ( & V_42 -> V_84 ) ;
F_69 ( & V_42 -> V_44 ) ;
F_40 ( & V_42 -> V_55 . V_56 . V_44 ) ;
F_40 ( & V_42 -> V_138 ) ;
if ( V_139 ) {
V_42 -> V_88 = F_70 (
F_44 ( V_42 -> V_55 . V_111 . V_116 ) ,
V_139 ) ;
F_31 ( V_42 ) ;
}
return V_42 ;
}
static void * F_71 ( const struct V_134 * V_135 )
{
struct V_129 * V_130 ;
static int V_140 ;
int V_141 ;
if ( ! V_140 ++ )
F_7 (KERN_INFO MOD L_49 ,
DRV_VERSION) ;
V_130 = F_72 ( sizeof *V_130 , V_39 ) ;
if ( ! V_130 ) {
V_130 = F_64 ( - V_40 ) ;
goto V_41;
}
V_130 -> V_111 = * V_135 ;
F_43 ( L_50 ,
V_37 , F_44 ( V_130 -> V_111 . V_116 ) ,
V_130 -> V_111 . V_142 , V_130 -> V_111 . V_143 ,
V_130 -> V_111 . V_144 , V_130 -> V_111 . V_145 ) ;
F_24 ( & V_146 ) ;
F_73 ( & V_130 -> V_102 , & V_147 ) ;
F_25 ( & V_146 ) ;
for ( V_141 = 0 ; V_141 < V_130 -> V_111 . V_143 ; V_141 ++ )
F_43 ( L_51 , V_141 , V_130 -> V_111 . V_148 [ V_141 ] ) ;
V_41:
return V_130 ;
}
static inline struct V_149 * F_74 ( const struct V_150 * V_151 ,
const T_5 * V_152 ,
T_6 V_153 )
{
struct V_149 * V_154 ;
V_154 = F_75 ( V_151 -> V_155 + sizeof( struct V_156 ) +
sizeof( struct V_157 ) - V_153 , V_158 ) ;
if ( F_76 ( ! V_154 ) )
return NULL ;
F_77 ( V_154 , V_151 -> V_155 + sizeof( struct V_156 ) +
sizeof( struct V_157 ) - V_153 ) ;
F_78 ( V_154 , V_152 , sizeof( struct V_156 ) +
sizeof( struct V_157 ) ) ;
F_79 ( V_154 , sizeof( struct V_157 ) +
sizeof( struct V_156 ) ,
V_151 -> V_159 + V_153 ,
V_151 -> V_155 - V_153 ) ;
return V_154 ;
}
static inline int F_80 ( struct V_52 * V_53 , const struct V_150 * V_151 ,
const T_5 * V_152 )
{
unsigned int V_160 = * ( V_161 * ) V_152 ;
struct V_149 * V_154 ;
if ( V_160 != V_162 )
goto V_41;
V_154 = F_74 ( V_151 , V_152 , V_53 -> V_55 . V_111 . V_163 ) ;
if ( V_154 == NULL )
goto V_41;
if ( V_164 [ V_160 ] == NULL ) {
F_29 ( L_52 , V_37 ,
V_160 ) ;
F_81 ( V_154 ) ;
goto V_41;
}
V_164 [ V_160 ] ( V_53 , V_154 ) ;
return 1 ;
V_41:
return 0 ;
}
static int F_82 ( void * V_165 , const T_5 * V_152 ,
const struct V_150 * V_151 )
{
struct V_129 * V_130 = V_165 ;
struct V_52 * V_53 = V_130 -> V_53 ;
struct V_149 * V_154 ;
V_161 V_160 ;
if ( V_151 == NULL ) {
unsigned int V_166 = 64 - sizeof( struct V_167 ) - 8 ;
V_154 = F_75 ( 256 , V_158 ) ;
if ( ! V_154 )
goto V_168;
F_77 ( V_154 , V_166 ) ;
F_78 ( V_154 , & V_152 [ 1 ] , V_166 ) ;
} else if ( V_151 == V_169 ) {
const struct V_167 * V_170 = ( void * ) V_152 ;
T_6 V_20 = F_83 ( V_170 -> V_171 ) ;
F_84 ( V_53 , V_20 ) ;
return 0 ;
} else if ( F_76 ( * ( V_161 * ) V_152 != * ( V_161 * ) V_151 -> V_159 ) ) {
if ( F_80 ( V_53 , V_151 , V_152 ) )
return 0 ;
F_29 ( L_53 \
L_54 ,
F_44 ( V_130 -> V_111 . V_116 ) , V_151 -> V_159 ,
( unsigned long long ) F_85 ( * V_152 ) ,
( unsigned long long ) F_85 (
* ( V_172 T_5 * ) V_151 -> V_159 ) ,
V_151 -> V_155 ) ;
return 0 ;
} else {
V_154 = F_86 ( V_151 , 128 , 128 ) ;
if ( F_76 ( ! V_154 ) )
goto V_168;
}
V_160 = * ( V_161 * ) V_152 ;
if ( V_164 [ V_160 ] )
V_164 [ V_160 ] ( V_53 , V_154 ) ;
else
F_29 ( L_52 , V_37 ,
V_160 ) ;
return 0 ;
V_168:
return - 1 ;
}
static int F_87 ( void * V_165 , enum V_173 V_174 )
{
struct V_129 * V_130 = V_165 ;
F_43 ( L_55 , V_37 , V_174 ) ;
switch ( V_174 ) {
case V_175 :
F_7 (KERN_INFO MOD L_56 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_130 -> V_53 ) {
int V_38 ;
V_130 -> V_53 = F_63 ( & V_130 -> V_111 ) ;
if ( F_88 ( V_130 -> V_53 ) ) {
F_7 (KERN_ERR MOD
L_57 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_130 -> V_53 = NULL ;
break;
}
V_38 = F_89 ( V_130 -> V_53 ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD
L_58 ,
pci_name(ctx->lldi.pdev), ret) ;
F_56 ( V_130 ) ;
}
}
break;
case V_176 :
F_7 (KERN_INFO MOD L_59 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_130 -> V_53 )
F_60 ( V_130 ) ;
break;
case V_177 :
F_7 (KERN_INFO MOD L_60 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_130 -> V_53 ) {
struct V_178 V_179 ;
V_130 -> V_53 -> V_55 . V_26 |= V_180 ;
memset ( & V_179 , 0 , sizeof V_179 ) ;
V_179 . V_179 = V_181 ;
V_179 . V_182 = & V_130 -> V_53 -> V_133 ;
F_90 ( & V_179 ) ;
F_60 ( V_130 ) ;
}
break;
case V_183 :
F_7 (KERN_INFO MOD L_61 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_130 -> V_53 )
F_60 ( V_130 ) ;
break;
}
return 0 ;
}
static int F_91 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_92 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_93 ( struct V_129 * V_130 )
{
F_12 ( & V_130 -> V_53 -> V_44 ) ;
if ( V_130 -> V_53 -> V_70 == V_184 ) {
V_130 -> V_53 -> V_55 . V_56 . V_71 ++ ;
V_130 -> V_53 -> V_70 = V_185 ;
F_13 ( & V_130 -> V_53 -> V_45 , F_91 , NULL ) ;
}
F_14 ( & V_130 -> V_53 -> V_44 ) ;
}
static int F_94 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_95 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_96 ( struct V_129 * V_130 )
{
F_12 ( & V_130 -> V_53 -> V_44 ) ;
if ( V_130 -> V_53 -> V_186 <= V_187 &&
V_130 -> V_53 -> V_70 == V_185 ) {
V_130 -> V_53 -> V_70 = V_184 ;
V_130 -> V_53 -> V_55 . V_56 . V_71 ++ ;
F_13 ( & V_130 -> V_53 -> V_45 , F_94 , NULL ) ;
}
F_14 ( & V_130 -> V_53 -> V_44 ) ;
}
static int F_97 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_188 * V_189 = V_3 ;
struct V_13 * V_14 = V_2 ;
F_98 ( & V_14 -> V_190 ) ;
V_189 -> V_191 [ V_189 -> V_192 ++ ] = V_14 ;
return 0 ;
}
static int F_99 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_100 ( struct V_188 V_188 )
{
int V_192 ;
for ( V_192 = 0 ; V_192 < V_188 . V_192 ; V_192 ++ )
F_101 ( & V_188 . V_191 [ V_192 ] -> V_190 ) ;
}
static void F_102 ( struct V_129 * V_130 , struct V_188 * V_188 )
{
int V_192 ;
int V_38 ;
for ( V_192 = 0 ; V_192 < V_188 -> V_192 ; V_192 ++ ) {
struct V_13 * V_14 = V_188 -> V_191 [ V_192 ] ;
V_38 = F_103 ( V_14 -> V_193 -> V_55 . V_111 . V_194 [ 0 ] ,
V_14 -> V_18 . V_19 . V_20 ,
F_104 ( & V_14 -> V_18 ) ,
F_105 ( & V_14 -> V_18 ) ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_62
L_63
L_64 ,
pci_name(ctx->lldi.pdev), qp->wq.sq.qid) ;
return;
}
V_38 = F_103 ( V_14 -> V_193 -> V_55 . V_111 . V_194 [ 0 ] ,
V_14 -> V_18 . V_23 . V_20 ,
F_106 ( & V_14 -> V_18 ) ,
F_107 ( & V_14 -> V_18 ) ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_62
L_63
L_65 ,
pci_name(ctx->lldi.pdev), qp->wq.rq.qid) ;
return;
}
while ( F_108 ( V_14 -> V_193 -> V_55 . V_111 . V_194 [ 0 ] , 1 ) > 0 ) {
F_109 ( V_195 ) ;
F_110 ( F_111 ( 10 ) ) ;
}
}
}
static void F_112 ( struct V_129 * V_130 )
{
int V_7 = 0 ;
struct V_188 V_188 ;
int V_38 ;
F_24 ( & V_130 -> V_53 -> V_138 ) ;
F_12 ( & V_130 -> V_53 -> V_44 ) ;
V_130 -> V_53 -> V_70 = V_196 ;
V_130 -> V_53 -> V_55 . V_56 . V_71 ++ ;
F_13 ( & V_130 -> V_53 -> V_45 , F_91 , NULL ) ;
F_14 ( & V_130 -> V_53 -> V_44 ) ;
F_109 ( V_195 ) ;
F_110 ( F_111 ( 1000 ) ) ;
while ( F_108 ( V_130 -> V_53 -> V_55 . V_111 . V_194 [ 0 ] , 1 ) > 0 ) {
F_109 ( V_195 ) ;
F_110 ( F_111 ( 10 ) ) ;
}
V_38 = F_113 ( V_130 -> V_53 -> V_55 . V_111 . V_194 [ 0 ] ) ;
if ( V_38 ) {
F_7 (KERN_ERR MOD L_66 ,
pci_name(ctx->lldi.pdev)) ;
goto V_41;
}
F_12 ( & V_130 -> V_53 -> V_44 ) ;
F_13 ( & V_130 -> V_53 -> V_45 , F_99 , & V_7 ) ;
V_188 . V_191 = F_72 ( V_7 * sizeof * V_188 . V_191 , V_158 ) ;
if ( ! V_188 . V_191 ) {
F_7 (KERN_ERR MOD L_66 ,
pci_name(ctx->lldi.pdev)) ;
F_14 ( & V_130 -> V_53 -> V_44 ) ;
goto V_41;
}
V_188 . V_192 = 0 ;
F_13 ( & V_130 -> V_53 -> V_45 , F_97 , & V_188 ) ;
F_14 ( & V_130 -> V_53 -> V_44 ) ;
F_102 ( V_130 , & V_188 ) ;
F_100 ( V_188 ) ;
F_9 ( V_188 . V_191 ) ;
while ( F_108 ( V_130 -> V_53 -> V_55 . V_111 . V_194 [ 0 ] , 1 ) > 0 ) {
F_109 ( V_195 ) ;
F_110 ( F_111 ( 10 ) ) ;
}
F_12 ( & V_130 -> V_53 -> V_44 ) ;
if ( V_130 -> V_53 -> V_186 > V_187 )
V_130 -> V_53 -> V_70 = V_185 ;
else {
V_130 -> V_53 -> V_70 = V_184 ;
F_13 ( & V_130 -> V_53 -> V_45 , F_94 , NULL ) ;
}
V_130 -> V_53 -> V_55 . V_56 . V_71 ++ ;
F_14 ( & V_130 -> V_53 -> V_44 ) ;
V_41:
F_25 ( & V_130 -> V_53 -> V_138 ) ;
}
static int F_114 ( void * V_165 , enum V_197 V_198 , ... )
{
struct V_129 * V_130 = V_165 ;
switch ( V_198 ) {
case V_199 :
F_93 ( V_130 ) ;
F_24 ( & V_130 -> V_53 -> V_55 . V_56 . V_44 ) ;
V_130 -> V_53 -> V_55 . V_56 . V_66 ++ ;
F_25 ( & V_130 -> V_53 -> V_55 . V_56 . V_44 ) ;
break;
case V_200 :
F_96 ( V_130 ) ;
F_24 ( & V_130 -> V_53 -> V_55 . V_56 . V_44 ) ;
V_130 -> V_53 -> V_55 . V_56 . V_67 ++ ;
F_25 ( & V_130 -> V_53 -> V_55 . V_56 . V_44 ) ;
break;
case V_201 :
F_112 ( V_130 ) ;
F_24 ( & V_130 -> V_53 -> V_55 . V_56 . V_44 ) ;
V_130 -> V_53 -> V_55 . V_56 . V_68 ++ ;
F_25 ( & V_130 -> V_53 -> V_55 . V_56 . V_44 ) ;
break;
default:
F_7 (KERN_WARNING MOD L_67 ,
pci_name(ctx->lldi.pdev), control) ;
break;
}
return 0 ;
}
static int T_7 F_115 ( void )
{
int V_108 ;
V_108 = F_116 () ;
if ( V_108 )
return V_108 ;
V_139 = F_70 ( V_202 , NULL ) ;
if ( ! V_139 )
F_7 (KERN_WARNING MOD
L_68 ) ;
F_117 ( V_203 , & V_204 ) ;
return 0 ;
}
static void T_8 F_118 ( void )
{
struct V_129 * V_130 , * V_205 ;
F_24 ( & V_146 ) ;
F_119 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_130 -> V_53 )
F_60 ( V_130 ) ;
F_9 ( V_130 ) ;
}
F_25 ( & V_146 ) ;
F_120 ( V_203 ) ;
F_121 () ;
F_122 ( V_139 ) ;
}
