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
if ( V_14 -> V_22 ) {
if ( V_14 -> V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_14 -> V_22 -> V_23 . V_24 ;
struct V_27 * V_29 = (struct V_27 * )
& V_14 -> V_22 -> V_23 . V_30 ;
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_1
L_2
L_3 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_31 . V_20 ,
( int ) V_14 -> V_32 . V_33 ,
V_14 -> V_18 . V_19 . V_34 & V_35 ,
V_14 -> V_22 -> V_36 , ( int ) V_14 -> V_22 -> V_23 . V_33 ,
& V_28 -> V_37 , F_5 ( V_28 -> V_38 ) ,
& V_29 -> V_37 , F_5 ( V_29 -> V_38 ) ) ;
} else {
struct V_39 * V_40 = (struct V_39 * )
& V_14 -> V_22 -> V_23 . V_24 ;
struct V_39 * V_41 = (struct V_39 * )
& V_14 -> V_22 -> V_23 . V_30 ;
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_1
L_2
L_4 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_31 . V_20 ,
( int ) V_14 -> V_32 . V_33 ,
V_14 -> V_18 . V_19 . V_34 & V_35 ,
V_14 -> V_22 -> V_36 , ( int ) V_14 -> V_22 -> V_23 . V_33 ,
& V_40 -> V_42 ,
F_5 ( V_40 -> V_43 ) ,
& V_41 -> V_42 ,
F_5 ( V_41 -> V_43 ) ) ;
}
} else
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_5 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_31 . V_20 ,
( int ) V_14 -> V_32 . V_33 ,
V_14 -> V_18 . V_19 . V_34 & V_35 ) ;
if ( V_17 < V_16 )
V_15 -> V_12 += V_17 ;
return 0 ;
}
static int F_6 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_15 = V_5 -> V_11 ;
if ( ! V_15 ) {
F_7 ( V_45 L_6 , V_46 ) ;
return 0 ;
}
F_8 ( V_15 -> V_6 ) ;
F_9 ( V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_15 ;
int V_47 = 0 ;
int V_7 = 1 ;
V_15 = F_11 ( sizeof *V_15 , V_48 ) ;
if ( ! V_15 ) {
V_47 = - V_49 ;
goto V_50;
}
V_15 -> V_51 = V_44 -> V_52 ;
V_15 -> V_12 = 0 ;
F_12 ( & V_15 -> V_51 -> V_53 ) ;
F_13 ( & V_15 -> V_51 -> V_54 , F_1 , & V_7 ) ;
F_14 ( & V_15 -> V_51 -> V_53 ) ;
V_15 -> V_21 = V_7 * 128 ;
V_15 -> V_6 = F_15 ( V_15 -> V_21 ) ;
if ( ! V_15 -> V_6 ) {
V_47 = - V_49 ;
goto V_55;
}
F_12 ( & V_15 -> V_51 -> V_53 ) ;
F_13 ( & V_15 -> V_51 -> V_54 , F_4 , V_15 ) ;
F_14 ( & V_15 -> V_51 -> V_53 ) ;
V_15 -> V_6 [ V_15 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_15 ;
goto V_50;
V_55:
F_9 ( V_15 ) ;
V_50:
return V_47 ;
}
static int F_16 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_9 * V_56 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_56 -> V_21 - V_56 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
V_17 = snprintf ( V_56 -> V_6 + V_56 -> V_12 , V_16 , L_7 , V_1 << 8 ) ;
if ( V_17 < V_16 )
V_56 -> V_12 += V_17 ;
return 0 ;
}
static int F_17 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_56 = V_5 -> V_11 ;
if ( ! V_56 ) {
F_7 ( V_45 L_8 , V_46 ) ;
return 0 ;
}
F_9 ( V_56 -> V_6 ) ;
F_9 ( V_56 ) ;
return 0 ;
}
static int F_18 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_56 ;
int V_47 = 0 ;
int V_7 = 1 ;
V_56 = F_11 ( sizeof *V_56 , V_48 ) ;
if ( ! V_56 ) {
V_47 = - V_49 ;
goto V_50;
}
V_56 -> V_51 = V_44 -> V_52 ;
V_56 -> V_12 = 0 ;
F_12 ( & V_56 -> V_51 -> V_53 ) ;
F_13 ( & V_56 -> V_51 -> V_57 , F_1 , & V_7 ) ;
F_14 ( & V_56 -> V_51 -> V_53 ) ;
V_56 -> V_21 = V_7 * sizeof( L_9 ) ;
V_56 -> V_6 = F_11 ( V_56 -> V_21 , V_48 ) ;
if ( ! V_56 -> V_6 ) {
V_47 = - V_49 ;
goto V_55;
}
F_12 ( & V_56 -> V_51 -> V_53 ) ;
F_13 ( & V_56 -> V_51 -> V_57 , F_16 , V_56 ) ;
F_14 ( & V_56 -> V_51 -> V_53 ) ;
V_56 -> V_6 [ V_56 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_56 ;
goto V_50;
V_55:
F_9 ( V_56 ) ;
V_50:
return V_47 ;
}
static int F_19 ( struct V_58 * V_59 , void * V_60 )
{
struct V_61 * V_62 = V_59 -> V_63 ;
F_20 ( V_59 , L_10 , L_11 , L_12 ,
L_13 , L_14 ) ;
F_20 ( V_59 , L_15 ,
V_62 -> V_64 . V_65 . V_66 . V_67 , V_62 -> V_64 . V_65 . V_66 . V_68 ,
V_62 -> V_64 . V_65 . V_66 . V_69 , V_62 -> V_64 . V_65 . V_66 . V_70 ) ;
F_20 ( V_59 , L_16 ,
V_62 -> V_64 . V_65 . V_20 . V_67 , V_62 -> V_64 . V_65 . V_20 . V_68 ,
V_62 -> V_64 . V_65 . V_20 . V_69 , V_62 -> V_64 . V_65 . V_20 . V_70 ) ;
F_20 ( V_59 , L_17 ,
V_62 -> V_64 . V_65 . V_71 . V_67 , V_62 -> V_64 . V_65 . V_71 . V_68 ,
V_62 -> V_64 . V_65 . V_71 . V_69 , V_62 -> V_64 . V_65 . V_71 . V_70 ) ;
F_20 ( V_59 , L_18 ,
V_62 -> V_64 . V_65 . V_72 . V_67 , V_62 -> V_64 . V_65 . V_72 . V_68 ,
V_62 -> V_64 . V_65 . V_72 . V_69 , V_62 -> V_64 . V_65 . V_72 . V_70 ) ;
F_20 ( V_59 , L_19 ,
V_62 -> V_64 . V_65 . V_73 . V_67 , V_62 -> V_64 . V_65 . V_73 . V_68 ,
V_62 -> V_64 . V_65 . V_73 . V_69 , V_62 -> V_64 . V_65 . V_73 . V_70 ) ;
F_20 ( V_59 , L_20 ,
V_62 -> V_64 . V_65 . V_74 . V_67 , V_62 -> V_64 . V_65 . V_74 . V_68 ,
V_62 -> V_64 . V_65 . V_74 . V_69 , V_62 -> V_64 . V_65 . V_74 . V_70 ) ;
F_20 ( V_59 , L_21 , V_62 -> V_64 . V_65 . V_75 ) ;
F_20 ( V_59 , L_22 , V_62 -> V_64 . V_65 . V_76 ) ;
F_20 ( V_59 , L_23 , V_62 -> V_64 . V_65 . V_77 ) ;
F_20 ( V_59 , L_24 ,
V_78 [ V_62 -> V_79 ] ,
V_62 -> V_64 . V_65 . V_80 ) ;
F_20 ( V_59 , L_25 , V_62 -> V_64 . V_65 . V_81 ) ;
F_20 ( V_59 , L_26 ,
V_62 -> V_64 . V_65 . V_82 ) ;
F_20 ( V_59 , L_27 ,
V_62 -> V_64 . V_65 . V_83 ) ;
return 0 ;
}
static int F_21 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
return F_22 ( V_5 , F_19 , V_44 -> V_52 ) ;
}
static T_1 F_23 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_12 )
{
struct V_61 * V_62 = ( (struct V_58 * ) V_5 -> V_11 ) -> V_63 ;
F_24 ( & V_62 -> V_64 . V_65 . V_53 ) ;
V_62 -> V_64 . V_65 . V_66 . V_69 = 0 ;
V_62 -> V_64 . V_65 . V_66 . V_70 = 0 ;
V_62 -> V_64 . V_65 . V_20 . V_69 = 0 ;
V_62 -> V_64 . V_65 . V_20 . V_70 = 0 ;
V_62 -> V_64 . V_65 . V_71 . V_69 = 0 ;
V_62 -> V_64 . V_65 . V_71 . V_70 = 0 ;
V_62 -> V_64 . V_65 . V_72 . V_69 = 0 ;
V_62 -> V_64 . V_65 . V_72 . V_70 = 0 ;
V_62 -> V_64 . V_65 . V_73 . V_69 = 0 ;
V_62 -> V_64 . V_65 . V_73 . V_70 = 0 ;
V_62 -> V_64 . V_65 . V_74 . V_69 = 0 ;
V_62 -> V_64 . V_65 . V_74 . V_70 = 0 ;
V_62 -> V_64 . V_65 . V_75 = 0 ;
V_62 -> V_64 . V_65 . V_76 = 0 ;
V_62 -> V_64 . V_65 . V_77 = 0 ;
V_62 -> V_64 . V_65 . V_80 = 0 ;
V_62 -> V_64 . V_65 . V_81 = 0 ;
V_62 -> V_64 . V_65 . V_82 = 0 ;
V_62 -> V_64 . V_65 . V_83 = 0 ;
F_25 ( & V_62 -> V_64 . V_65 . V_53 ) ;
return V_7 ;
}
static int F_26 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_84 * V_22 = V_2 ;
struct V_9 * V_85 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_85 -> V_21 - V_85 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_22 -> V_23 . V_24 ;
struct V_27 * V_29 = (struct V_27 * )
& V_22 -> V_23 . V_30 ;
V_17 = snprintf ( V_85 -> V_6 + V_85 -> V_12 , V_16 ,
L_28
L_29
L_30 ,
V_22 , V_22 -> V_23 . V_86 , V_22 -> V_23 . V_14 ,
( int ) V_22 -> V_23 . V_33 , V_22 -> V_23 . V_34 ,
V_22 -> V_23 . V_87 , V_22 -> V_36 , V_22 -> V_88 ,
& V_28 -> V_37 , F_5 ( V_28 -> V_38 ) ,
& V_29 -> V_37 , F_5 ( V_29 -> V_38 ) ) ;
} else {
struct V_39 * V_40 = (struct V_39 * )
& V_22 -> V_23 . V_24 ;
struct V_39 * V_41 = (struct V_39 * )
& V_22 -> V_23 . V_30 ;
V_17 = snprintf ( V_85 -> V_6 + V_85 -> V_12 , V_16 ,
L_28
L_29
L_31 ,
V_22 , V_22 -> V_23 . V_86 , V_22 -> V_23 . V_14 ,
( int ) V_22 -> V_23 . V_33 , V_22 -> V_23 . V_34 ,
V_22 -> V_23 . V_87 , V_22 -> V_36 , V_22 -> V_88 ,
& V_40 -> V_42 , F_5 ( V_40 -> V_43 ) ,
& V_41 -> V_42 , F_5 ( V_41 -> V_43 ) ) ;
}
if ( V_17 < V_16 )
V_85 -> V_12 += V_17 ;
return 0 ;
}
static int F_27 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_89 * V_22 = V_2 ;
struct V_9 * V_85 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_85 -> V_21 - V_85 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_22 -> V_23 . V_24 ;
V_17 = snprintf ( V_85 -> V_6 + V_85 -> V_12 , V_16 ,
L_32
L_33 ,
V_22 , V_22 -> V_23 . V_86 , ( int ) V_22 -> V_23 . V_33 ,
V_22 -> V_23 . V_34 , V_22 -> V_90 , V_22 -> V_91 ,
& V_28 -> V_37 , F_5 ( V_28 -> V_38 ) ) ;
} else {
struct V_39 * V_40 = (struct V_39 * )
& V_22 -> V_23 . V_24 ;
V_17 = snprintf ( V_85 -> V_6 + V_85 -> V_12 , V_16 ,
L_32
L_34 ,
V_22 , V_22 -> V_23 . V_86 , ( int ) V_22 -> V_23 . V_33 ,
V_22 -> V_23 . V_34 , V_22 -> V_90 , V_22 -> V_91 ,
& V_40 -> V_42 , F_5 ( V_40 -> V_43 ) ) ;
}
if ( V_17 < V_16 )
V_85 -> V_12 += V_17 ;
return 0 ;
}
static int F_28 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_85 = V_5 -> V_11 ;
if ( ! V_85 ) {
F_29 ( L_6 , V_46 ) ;
return 0 ;
}
F_8 ( V_85 -> V_6 ) ;
F_9 ( V_85 ) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_85 ;
int V_47 = 0 ;
int V_7 = 1 ;
V_85 = F_11 ( sizeof( * V_85 ) , V_48 ) ;
if ( ! V_85 ) {
V_47 = - V_49 ;
goto V_50;
}
V_85 -> V_51 = V_44 -> V_52 ;
V_85 -> V_12 = 0 ;
F_12 ( & V_85 -> V_51 -> V_53 ) ;
F_13 ( & V_85 -> V_51 -> V_92 , F_1 , & V_7 ) ;
F_13 ( & V_85 -> V_51 -> V_93 , F_1 , & V_7 ) ;
F_13 ( & V_85 -> V_51 -> V_94 , F_1 , & V_7 ) ;
F_14 ( & V_85 -> V_51 -> V_53 ) ;
V_85 -> V_21 = V_7 * 160 ;
V_85 -> V_6 = F_15 ( V_85 -> V_21 ) ;
if ( ! V_85 -> V_6 ) {
V_47 = - V_49 ;
goto V_55;
}
F_12 ( & V_85 -> V_51 -> V_53 ) ;
F_13 ( & V_85 -> V_51 -> V_92 , F_26 , V_85 ) ;
F_13 ( & V_85 -> V_51 -> V_93 , F_26 , V_85 ) ;
F_13 ( & V_85 -> V_51 -> V_94 , F_27 , V_85 ) ;
F_14 ( & V_85 -> V_51 -> V_53 ) ;
V_5 -> V_11 = V_85 ;
goto V_50;
V_55:
F_9 ( V_85 ) ;
V_50:
return V_47 ;
}
static int F_31 ( struct V_61 * V_51 )
{
struct V_95 * V_96 ;
if ( ! V_51 -> V_97 )
return - 1 ;
V_96 = F_32 ( L_35 , V_98 , V_51 -> V_97 ,
( void * ) V_51 , & V_99 ) ;
if ( V_96 && V_96 -> V_100 )
V_96 -> V_100 -> V_101 = 4096 ;
V_96 = F_32 ( L_36 , V_98 , V_51 -> V_97 ,
( void * ) V_51 , & V_102 ) ;
if ( V_96 && V_96 -> V_100 )
V_96 -> V_100 -> V_101 = 4096 ;
V_96 = F_32 ( L_37 , V_98 , V_51 -> V_97 ,
( void * ) V_51 , & V_103 ) ;
if ( V_96 && V_96 -> V_100 )
V_96 -> V_100 -> V_101 = 4096 ;
V_96 = F_32 ( L_38 , V_98 , V_51 -> V_97 ,
( void * ) V_51 , & V_104 ) ;
if ( V_96 && V_96 -> V_100 )
V_96 -> V_100 -> V_101 = 4096 ;
return 0 ;
}
void F_33 ( struct V_105 * V_64 ,
struct V_106 * V_107 )
{
struct V_108 * V_12 , * V_109 ;
struct V_110 * V_111 ;
F_24 ( & V_107 -> V_53 ) ;
F_34 (pos, nxt, &uctx->qpids) {
V_111 = F_35 ( V_12 , struct V_110 , V_111 ) ;
F_36 ( & V_111 -> V_111 ) ;
if ( ! ( V_111 -> V_20 & V_64 -> V_112 ) ) {
F_37 ( & V_64 -> V_113 . V_114 ,
V_111 -> V_20 ) ;
F_24 ( & V_64 -> V_65 . V_53 ) ;
V_64 -> V_65 . V_20 . V_68 -= V_64 -> V_112 + 1 ;
F_25 ( & V_64 -> V_65 . V_53 ) ;
}
F_9 ( V_111 ) ;
}
F_34 (pos, nxt, &uctx->qpids) {
V_111 = F_35 ( V_12 , struct V_110 , V_111 ) ;
F_36 ( & V_111 -> V_111 ) ;
F_9 ( V_111 ) ;
}
F_25 ( & V_107 -> V_53 ) ;
}
void F_38 ( struct V_105 * V_64 ,
struct V_106 * V_107 )
{
F_39 ( & V_107 -> V_115 ) ;
F_39 ( & V_107 -> V_116 ) ;
F_40 ( & V_107 -> V_53 ) ;
}
static int F_41 ( struct V_105 * V_64 )
{
int V_117 ;
F_38 ( V_64 , & V_64 -> V_107 ) ;
V_64 -> V_118 = V_119 - F_42 ( V_64 -> V_120 . V_121 ) ;
V_64 -> V_112 = V_64 -> V_120 . V_121 - 1 ;
V_64 -> V_122 = V_119 - F_42 ( V_64 -> V_120 . V_123 ) ;
V_64 -> V_124 = V_64 -> V_120 . V_123 - 1 ;
F_43 ( L_39
L_40
L_41 ,
V_46 , F_44 ( V_64 -> V_120 . V_125 ) , V_64 -> V_120 . V_126 -> V_71 . V_127 ,
V_64 -> V_120 . V_126 -> V_71 . V_128 , F_45 ( V_64 ) ,
V_64 -> V_120 . V_126 -> V_72 . V_127 ,
V_64 -> V_120 . V_126 -> V_72 . V_128 , V_64 -> V_120 . V_126 -> V_31 . V_127 ,
V_64 -> V_120 . V_126 -> V_31 . V_128 ,
V_64 -> V_120 . V_126 -> V_14 . V_127 ,
V_64 -> V_120 . V_126 -> V_14 . V_128 ,
V_64 -> V_120 . V_126 -> V_129 . V_127 ,
V_64 -> V_120 . V_126 -> V_129 . V_128 ) ;
F_43 ( L_42
L_43 ,
( unsigned ) F_46 ( V_64 -> V_120 . V_125 , 2 ) ,
( void * ) ( unsigned long ) F_47 ( V_64 -> V_120 . V_125 , 2 ) ,
V_64 -> V_120 . V_130 ,
V_64 -> V_120 . V_131 ,
V_64 -> V_118 , V_64 -> V_112 ,
V_64 -> V_122 , V_64 -> V_124 ) ;
if ( F_45 ( V_64 ) == 0 ) {
V_117 = - V_132 ;
goto V_55;
}
V_64 -> V_65 . V_66 . V_67 = V_133 ;
V_64 -> V_65 . V_71 . V_67 = V_64 -> V_120 . V_126 -> V_71 . V_128 ;
V_64 -> V_65 . V_72 . V_67 = V_64 -> V_120 . V_126 -> V_72 . V_128 ;
V_64 -> V_65 . V_73 . V_67 = V_64 -> V_120 . V_126 -> V_31 . V_128 ;
V_64 -> V_65 . V_74 . V_67 = V_64 -> V_120 . V_126 -> V_134 . V_128 ;
V_64 -> V_65 . V_20 . V_67 = V_64 -> V_120 . V_126 -> V_14 . V_128 ;
V_117 = F_48 ( V_64 , F_45 ( V_64 ) , V_133 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_44 , err) ;
goto V_55;
}
V_117 = F_49 ( V_64 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_45 , err) ;
goto V_135;
}
V_117 = F_50 ( V_64 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_46 , err) ;
goto V_136;
}
V_117 = F_51 ( V_64 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_47 , err) ;
goto V_137;
}
return 0 ;
V_137:
F_52 ( V_64 ) ;
V_136:
F_53 ( V_64 ) ;
V_135:
F_54 ( & V_64 -> V_113 ) ;
V_55:
return V_117 ;
}
static void F_55 ( struct V_105 * V_64 )
{
F_53 ( V_64 ) ;
F_52 ( V_64 ) ;
F_54 ( & V_64 -> V_113 ) ;
}
static void F_56 ( struct V_138 * V_139 )
{
F_55 ( & V_139 -> V_62 -> V_64 ) ;
F_57 ( & V_139 -> V_62 -> V_140 ) ;
F_57 ( & V_139 -> V_62 -> V_54 ) ;
F_57 ( & V_139 -> V_62 -> V_57 ) ;
F_57 ( & V_139 -> V_62 -> V_92 ) ;
F_57 ( & V_139 -> V_62 -> V_94 ) ;
F_57 ( & V_139 -> V_62 -> V_93 ) ;
F_58 ( V_139 -> V_62 -> V_64 . V_141 ) ;
F_59 ( & V_139 -> V_62 -> V_142 ) ;
V_139 -> V_62 = NULL ;
}
static void F_60 ( struct V_138 * V_139 )
{
F_43 ( L_48 , V_46 , V_139 -> V_62 ) ;
F_61 ( V_139 -> V_62 ) ;
F_56 ( V_139 ) ;
}
static int F_62 ( const struct V_143 * V_144 )
{
return V_144 -> V_126 -> V_71 . V_128 > 0 && V_144 -> V_126 -> V_72 . V_128 > 0 &&
V_144 -> V_126 -> V_31 . V_128 > 0 && V_144 -> V_126 -> V_14 . V_128 > 0 &&
V_144 -> V_126 -> V_129 . V_128 > 0 ;
}
static struct V_61 * F_63 ( const struct V_143 * V_144 )
{
struct V_61 * V_51 ;
int V_47 ;
if ( ! F_62 ( V_144 ) ) {
F_7 (KERN_INFO MOD L_49 ,
pci_name(infop->pdev)) ;
return F_64 ( - V_145 ) ;
}
if ( ! F_65 ( V_144 ) )
F_29 ( L_50 ,
F_44 ( V_144 -> V_125 ) ) ;
if ( ! F_66 ( V_144 -> V_146 ) ) {
if ( ! V_147 ) {
V_148 = 100000 ;
F_29 ( L_51 ) ;
}
if ( ! V_149 ) {
V_150 = - 1 ;
F_29 ( L_52 ) ;
}
}
V_51 = (struct V_61 * ) F_67 ( sizeof( * V_51 ) ) ;
if ( ! V_51 ) {
F_7 (KERN_ERR MOD L_53 ) ;
return F_64 ( - V_49 ) ;
}
V_51 -> V_64 . V_120 = * V_144 ;
V_51 -> V_64 . V_151 = F_47 ( V_51 -> V_64 . V_120 . V_125 , 2 ) +
( F_46 ( V_51 -> V_64 . V_120 . V_125 , 2 ) -
F_68 ( V_51 -> V_64 . V_120 . V_126 -> V_134 . V_128 ) ) ;
V_51 -> V_64 . V_141 = F_69 ( V_51 -> V_64 . V_151 ,
V_51 -> V_64 . V_120 . V_126 -> V_134 . V_128 ) ;
F_43 (KERN_INFO MOD L_54
L_55 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_47 = F_41 ( & V_51 -> V_64 ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_56 , ret) ;
F_59 ( & V_51 -> V_142 ) ;
return F_64 ( V_47 ) ;
}
F_70 ( & V_51 -> V_140 ) ;
F_70 ( & V_51 -> V_54 ) ;
F_70 ( & V_51 -> V_57 ) ;
F_70 ( & V_51 -> V_92 ) ;
F_70 ( & V_51 -> V_94 ) ;
F_70 ( & V_51 -> V_93 ) ;
F_71 ( & V_51 -> V_53 ) ;
F_40 ( & V_51 -> V_64 . V_65 . V_53 ) ;
F_40 ( & V_51 -> V_152 ) ;
if ( V_153 ) {
V_51 -> V_97 = F_72 (
F_44 ( V_51 -> V_64 . V_120 . V_125 ) ,
V_153 ) ;
F_31 ( V_51 ) ;
}
return V_51 ;
}
static void * F_73 ( const struct V_143 * V_144 )
{
struct V_138 * V_139 ;
static int V_154 ;
int V_155 ;
if ( ! V_154 ++ )
F_29 ( L_57 ,
V_156 ) ;
V_139 = F_74 ( sizeof *V_139 , V_48 ) ;
if ( ! V_139 ) {
V_139 = F_64 ( - V_49 ) ;
goto V_50;
}
V_139 -> V_120 = * V_144 ;
F_43 ( L_58 ,
V_46 , F_44 ( V_139 -> V_120 . V_125 ) ,
V_139 -> V_120 . V_157 , V_139 -> V_120 . V_158 ,
V_139 -> V_120 . V_159 , V_139 -> V_120 . V_160 ) ;
F_24 ( & V_161 ) ;
F_75 ( & V_139 -> V_111 , & V_162 ) ;
F_25 ( & V_161 ) ;
for ( V_155 = 0 ; V_155 < V_139 -> V_120 . V_158 ; V_155 ++ )
F_43 ( L_59 , V_155 , V_139 -> V_120 . V_163 [ V_155 ] ) ;
V_50:
return V_139 ;
}
static inline struct V_164 * F_76 ( const struct V_165 * V_166 ,
const T_5 * V_167 ,
T_6 V_168 )
{
struct V_164 * V_169 ;
V_169 = F_77 ( V_166 -> V_170 + sizeof( struct V_171 ) +
sizeof( struct V_172 ) - V_168 , V_173 ) ;
if ( F_78 ( ! V_169 ) )
return NULL ;
F_79 ( V_169 , V_166 -> V_170 + sizeof( struct V_171 ) +
sizeof( struct V_172 ) - V_168 ) ;
F_80 ( V_169 , V_167 , sizeof( struct V_171 ) +
sizeof( struct V_172 ) ) ;
F_81 ( V_169 , sizeof( struct V_172 ) +
sizeof( struct V_171 ) ,
V_166 -> V_174 + V_168 ,
V_166 -> V_170 - V_168 ) ;
return V_169 ;
}
static inline int F_82 ( struct V_61 * V_62 , const struct V_165 * V_166 ,
const T_5 * V_167 )
{
unsigned int V_175 = * ( V_176 * ) V_167 ;
struct V_164 * V_169 ;
if ( V_175 != V_177 )
goto V_50;
V_169 = F_76 ( V_166 , V_167 , V_62 -> V_64 . V_120 . V_178 ) ;
if ( V_169 == NULL )
goto V_50;
if ( V_179 [ V_175 ] == NULL ) {
F_29 ( L_60 , V_46 ,
V_175 ) ;
F_83 ( V_169 ) ;
goto V_50;
}
V_179 [ V_175 ] ( V_62 , V_169 ) ;
return 1 ;
V_50:
return 0 ;
}
static int F_84 ( void * V_180 , const T_5 * V_167 ,
const struct V_165 * V_166 )
{
struct V_138 * V_139 = V_180 ;
struct V_61 * V_62 = V_139 -> V_62 ;
struct V_164 * V_169 ;
V_176 V_175 ;
if ( V_166 == NULL ) {
unsigned int V_181 = 64 - sizeof( struct V_182 ) - 8 ;
V_169 = F_77 ( 256 , V_173 ) ;
if ( ! V_169 )
goto V_183;
F_79 ( V_169 , V_181 ) ;
F_80 ( V_169 , & V_167 [ 1 ] , V_181 ) ;
} else if ( V_166 == V_184 ) {
const struct V_182 * V_185 = ( void * ) V_167 ;
T_6 V_20 = F_85 ( V_185 -> V_186 ) ;
F_86 ( V_62 , V_20 ) ;
return 0 ;
} else if ( F_78 ( * ( V_176 * ) V_167 != * ( V_176 * ) V_166 -> V_174 ) ) {
if ( F_82 ( V_62 , V_166 , V_167 ) )
return 0 ;
F_29 ( L_61 \
L_62 ,
F_44 ( V_139 -> V_120 . V_125 ) , V_166 -> V_174 ,
( unsigned long long ) F_87 ( * V_167 ) ,
( unsigned long long ) F_87 (
* ( V_187 T_5 * ) V_166 -> V_174 ) ,
V_166 -> V_170 ) ;
return 0 ;
} else {
V_169 = F_88 ( V_166 , 128 , 128 ) ;
if ( F_78 ( ! V_169 ) )
goto V_183;
}
V_175 = * ( V_176 * ) V_167 ;
if ( V_179 [ V_175 ] )
V_179 [ V_175 ] ( V_62 , V_169 ) ;
else
F_29 ( L_60 , V_46 ,
V_175 ) ;
return 0 ;
V_183:
return - 1 ;
}
static int F_89 ( void * V_180 , enum V_188 V_189 )
{
struct V_138 * V_139 = V_180 ;
F_43 ( L_63 , V_46 , V_189 ) ;
switch ( V_189 ) {
case V_190 :
F_7 (KERN_INFO MOD L_64 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_139 -> V_62 ) {
int V_47 ;
V_139 -> V_62 = F_63 ( & V_139 -> V_120 ) ;
if ( F_90 ( V_139 -> V_62 ) ) {
F_7 (KERN_ERR MOD
L_65 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_139 -> V_62 = NULL ;
break;
}
V_47 = F_91 ( V_139 -> V_62 ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD
L_66 ,
pci_name(ctx->lldi.pdev), ret) ;
F_56 ( V_139 ) ;
}
}
break;
case V_191 :
F_7 (KERN_INFO MOD L_67 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_139 -> V_62 )
F_60 ( V_139 ) ;
break;
case V_192 :
F_7 (KERN_INFO MOD L_68 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_139 -> V_62 ) {
struct V_193 V_194 ;
V_139 -> V_62 -> V_64 . V_34 |= V_195 ;
memset ( & V_194 , 0 , sizeof V_194 ) ;
V_194 . V_194 = V_196 ;
V_194 . V_197 = & V_139 -> V_62 -> V_142 ;
F_92 ( & V_194 ) ;
F_60 ( V_139 ) ;
}
break;
case V_198 :
F_7 (KERN_INFO MOD L_69 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_139 -> V_62 )
F_60 ( V_139 ) ;
break;
}
return 0 ;
}
static int F_93 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_94 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_95 ( struct V_138 * V_139 )
{
F_12 ( & V_139 -> V_62 -> V_53 ) ;
if ( V_139 -> V_62 -> V_79 == V_199 ) {
V_139 -> V_62 -> V_64 . V_65 . V_80 ++ ;
V_139 -> V_62 -> V_79 = V_200 ;
F_13 ( & V_139 -> V_62 -> V_54 , F_93 , NULL ) ;
}
F_14 ( & V_139 -> V_62 -> V_53 ) ;
}
static int F_96 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_97 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_98 ( struct V_138 * V_139 )
{
F_12 ( & V_139 -> V_62 -> V_53 ) ;
if ( V_139 -> V_62 -> V_201 <= V_148 &&
V_139 -> V_62 -> V_79 == V_200 ) {
V_139 -> V_62 -> V_79 = V_199 ;
V_139 -> V_62 -> V_64 . V_65 . V_80 ++ ;
F_13 ( & V_139 -> V_62 -> V_54 , F_96 , NULL ) ;
}
F_14 ( & V_139 -> V_62 -> V_53 ) ;
}
static int F_99 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_202 * V_203 = V_3 ;
struct V_13 * V_14 = V_2 ;
F_100 ( & V_14 -> V_204 ) ;
V_203 -> V_205 [ V_203 -> V_206 ++ ] = V_14 ;
return 0 ;
}
static int F_101 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_102 ( struct V_202 V_202 )
{
int V_206 ;
for ( V_206 = 0 ; V_206 < V_202 . V_206 ; V_206 ++ )
F_103 ( & V_202 . V_205 [ V_206 ] -> V_204 ) ;
}
static void F_104 ( struct V_138 * V_139 , struct V_202 * V_202 )
{
int V_206 ;
int V_47 ;
for ( V_206 = 0 ; V_206 < V_202 -> V_206 ; V_206 ++ ) {
struct V_13 * V_14 = V_202 -> V_205 [ V_206 ] ;
V_47 = F_105 ( V_14 -> V_207 -> V_64 . V_120 . V_208 [ 0 ] ,
V_14 -> V_18 . V_19 . V_20 ,
F_106 ( & V_14 -> V_18 ) ,
F_107 ( & V_14 -> V_18 ) ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_70
L_71
L_72 ,
pci_name(ctx->lldi.pdev), qp->wq.sq.qid) ;
return;
}
V_47 = F_105 ( V_14 -> V_207 -> V_64 . V_120 . V_208 [ 0 ] ,
V_14 -> V_18 . V_31 . V_20 ,
F_108 ( & V_14 -> V_18 ) ,
F_109 ( & V_14 -> V_18 ) ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_70
L_71
L_73 ,
pci_name(ctx->lldi.pdev), qp->wq.rq.qid) ;
return;
}
while ( F_110 ( V_14 -> V_207 -> V_64 . V_120 . V_208 [ 0 ] , 1 ) > 0 ) {
F_111 ( V_209 ) ;
F_112 ( F_113 ( 10 ) ) ;
}
}
}
static void F_114 ( struct V_138 * V_139 )
{
int V_7 = 0 ;
struct V_202 V_202 ;
int V_47 ;
F_24 ( & V_139 -> V_62 -> V_152 ) ;
F_12 ( & V_139 -> V_62 -> V_53 ) ;
V_139 -> V_62 -> V_79 = V_210 ;
V_139 -> V_62 -> V_64 . V_65 . V_80 ++ ;
F_13 ( & V_139 -> V_62 -> V_54 , F_93 , NULL ) ;
F_14 ( & V_139 -> V_62 -> V_53 ) ;
F_111 ( V_209 ) ;
F_112 ( F_113 ( 1000 ) ) ;
while ( F_110 ( V_139 -> V_62 -> V_64 . V_120 . V_208 [ 0 ] , 1 ) > 0 ) {
F_111 ( V_209 ) ;
F_112 ( F_113 ( 10 ) ) ;
}
V_47 = F_115 ( V_139 -> V_62 -> V_64 . V_120 . V_208 [ 0 ] ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_74 ,
pci_name(ctx->lldi.pdev)) ;
goto V_50;
}
F_12 ( & V_139 -> V_62 -> V_53 ) ;
F_13 ( & V_139 -> V_62 -> V_54 , F_101 , & V_7 ) ;
V_202 . V_205 = F_74 ( V_7 * sizeof * V_202 . V_205 , V_173 ) ;
if ( ! V_202 . V_205 ) {
F_7 (KERN_ERR MOD L_74 ,
pci_name(ctx->lldi.pdev)) ;
F_14 ( & V_139 -> V_62 -> V_53 ) ;
goto V_50;
}
V_202 . V_206 = 0 ;
F_13 ( & V_139 -> V_62 -> V_54 , F_99 , & V_202 ) ;
F_14 ( & V_139 -> V_62 -> V_53 ) ;
F_104 ( V_139 , & V_202 ) ;
F_102 ( V_202 ) ;
F_9 ( V_202 . V_205 ) ;
while ( F_110 ( V_139 -> V_62 -> V_64 . V_120 . V_208 [ 0 ] , 1 ) > 0 ) {
F_111 ( V_209 ) ;
F_112 ( F_113 ( 10 ) ) ;
}
F_12 ( & V_139 -> V_62 -> V_53 ) ;
if ( V_139 -> V_62 -> V_201 > V_148 )
V_139 -> V_62 -> V_79 = V_200 ;
else {
V_139 -> V_62 -> V_79 = V_199 ;
F_13 ( & V_139 -> V_62 -> V_54 , F_96 , NULL ) ;
}
V_139 -> V_62 -> V_64 . V_65 . V_80 ++ ;
F_14 ( & V_139 -> V_62 -> V_53 ) ;
V_50:
F_25 ( & V_139 -> V_62 -> V_152 ) ;
}
static int F_116 ( void * V_180 , enum V_211 V_212 , ... )
{
struct V_138 * V_139 = V_180 ;
switch ( V_212 ) {
case V_213 :
F_95 ( V_139 ) ;
F_24 ( & V_139 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_139 -> V_62 -> V_64 . V_65 . V_75 ++ ;
F_25 ( & V_139 -> V_62 -> V_64 . V_65 . V_53 ) ;
break;
case V_214 :
F_98 ( V_139 ) ;
F_24 ( & V_139 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_139 -> V_62 -> V_64 . V_65 . V_76 ++ ;
F_25 ( & V_139 -> V_62 -> V_64 . V_65 . V_53 ) ;
break;
case V_215 :
F_114 ( V_139 ) ;
F_24 ( & V_139 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_139 -> V_62 -> V_64 . V_65 . V_77 ++ ;
F_25 ( & V_139 -> V_62 -> V_64 . V_65 . V_53 ) ;
break;
default:
F_7 (KERN_WARNING MOD L_75 ,
pci_name(ctx->lldi.pdev), control) ;
break;
}
return 0 ;
}
static int T_7 F_117 ( void )
{
int V_117 ;
V_117 = F_118 () ;
if ( V_117 )
return V_117 ;
V_153 = F_72 ( V_216 , NULL ) ;
if ( ! V_153 )
F_7 (KERN_WARNING MOD
L_76 ) ;
F_119 ( V_217 , & V_218 ) ;
return 0 ;
}
static void T_8 F_120 ( void )
{
struct V_138 * V_139 , * V_219 ;
F_24 ( & V_161 ) ;
F_121 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_139 -> V_62 )
F_60 ( V_139 ) ;
F_9 ( V_139 ) ;
}
F_25 ( & V_161 ) ;
F_122 ( V_217 ) ;
F_123 () ;
F_124 ( V_153 ) ;
}
