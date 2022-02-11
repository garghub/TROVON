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
( V_130 ) F_47 ( V_64 -> V_120 . V_125 , 2 ) ,
V_64 -> V_120 . V_131 ,
V_64 -> V_120 . V_132 ,
V_64 -> V_118 , V_64 -> V_112 ,
V_64 -> V_122 , V_64 -> V_124 ) ;
if ( F_45 ( V_64 ) == 0 ) {
V_117 = - V_133 ;
goto V_55;
}
V_64 -> V_65 . V_66 . V_67 = V_134 ;
V_64 -> V_65 . V_71 . V_67 = V_64 -> V_120 . V_126 -> V_71 . V_128 ;
V_64 -> V_65 . V_72 . V_67 = V_64 -> V_120 . V_126 -> V_72 . V_128 ;
V_64 -> V_65 . V_73 . V_67 = V_64 -> V_120 . V_126 -> V_31 . V_128 ;
V_64 -> V_65 . V_74 . V_67 = V_64 -> V_120 . V_126 -> V_135 . V_128 ;
V_64 -> V_65 . V_20 . V_67 = V_64 -> V_120 . V_126 -> V_14 . V_128 ;
V_117 = F_48 ( V_64 , F_45 ( V_64 ) , V_134 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_44 , err) ;
goto V_55;
}
V_117 = F_49 ( V_64 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_45 , err) ;
goto V_136;
}
V_117 = F_50 ( V_64 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_46 , err) ;
goto V_137;
}
V_117 = F_51 ( V_64 ) ;
if ( V_117 ) {
F_7 (KERN_ERR MOD L_47 , err) ;
goto V_138;
}
return 0 ;
V_138:
F_52 ( V_64 ) ;
V_137:
F_53 ( V_64 ) ;
V_136:
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
static void F_56 ( struct V_139 * V_140 )
{
F_55 ( & V_140 -> V_62 -> V_64 ) ;
F_57 ( & V_140 -> V_62 -> V_141 ) ;
F_57 ( & V_140 -> V_62 -> V_54 ) ;
F_57 ( & V_140 -> V_62 -> V_57 ) ;
F_57 ( & V_140 -> V_62 -> V_92 ) ;
F_57 ( & V_140 -> V_62 -> V_94 ) ;
F_57 ( & V_140 -> V_62 -> V_93 ) ;
F_58 ( V_140 -> V_62 -> V_64 . V_142 ) ;
F_59 ( & V_140 -> V_62 -> V_143 ) ;
V_140 -> V_62 = NULL ;
}
static void F_60 ( struct V_139 * V_140 )
{
F_43 ( L_48 , V_46 , V_140 -> V_62 ) ;
F_61 ( V_140 -> V_62 ) ;
F_56 ( V_140 ) ;
}
static int F_62 ( const struct V_144 * V_145 )
{
return V_145 -> V_126 -> V_71 . V_128 > 0 && V_145 -> V_126 -> V_72 . V_128 > 0 &&
V_145 -> V_126 -> V_31 . V_128 > 0 && V_145 -> V_126 -> V_14 . V_128 > 0 &&
V_145 -> V_126 -> V_129 . V_128 > 0 ;
}
static struct V_61 * F_63 ( const struct V_144 * V_145 )
{
struct V_61 * V_51 ;
int V_47 ;
if ( ! F_62 ( V_145 ) ) {
F_7 (KERN_INFO MOD L_49 ,
pci_name(infop->pdev)) ;
return F_64 ( - V_146 ) ;
}
if ( ! F_65 ( V_145 ) )
F_29 ( L_50 ,
F_44 ( V_145 -> V_125 ) ) ;
if ( ! F_66 ( V_145 -> V_147 ) ) {
if ( ! V_148 ) {
V_149 = 100000 ;
F_29 ( L_51 ) ;
}
if ( ! V_150 ) {
V_151 = - 1 ;
F_29 ( L_52 ) ;
}
}
V_51 = (struct V_61 * ) F_67 ( sizeof( * V_51 ) ) ;
if ( ! V_51 ) {
F_7 (KERN_ERR MOD L_53 ) ;
return F_64 ( - V_49 ) ;
}
V_51 -> V_64 . V_120 = * V_145 ;
V_51 -> V_64 . V_152 = F_47 ( V_51 -> V_64 . V_120 . V_125 , 2 ) +
( F_46 ( V_51 -> V_64 . V_120 . V_125 , 2 ) -
F_68 ( V_51 -> V_64 . V_120 . V_126 -> V_135 . V_128 ) ) ;
V_51 -> V_64 . V_142 = F_69 ( V_51 -> V_64 . V_152 ,
V_51 -> V_64 . V_120 . V_126 -> V_135 . V_128 ) ;
F_43 (KERN_INFO MOD L_54
L_55 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_47 = F_41 ( & V_51 -> V_64 ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_56 , ret) ;
F_59 ( & V_51 -> V_143 ) ;
return F_64 ( V_47 ) ;
}
F_70 ( & V_51 -> V_141 ) ;
F_70 ( & V_51 -> V_54 ) ;
F_70 ( & V_51 -> V_57 ) ;
F_70 ( & V_51 -> V_92 ) ;
F_70 ( & V_51 -> V_94 ) ;
F_70 ( & V_51 -> V_93 ) ;
F_71 ( & V_51 -> V_53 ) ;
F_40 ( & V_51 -> V_64 . V_65 . V_53 ) ;
F_40 ( & V_51 -> V_153 ) ;
if ( V_154 ) {
V_51 -> V_97 = F_72 (
F_44 ( V_51 -> V_64 . V_120 . V_125 ) ,
V_154 ) ;
F_31 ( V_51 ) ;
}
return V_51 ;
}
static void * F_73 ( const struct V_144 * V_145 )
{
struct V_139 * V_140 ;
static int V_155 ;
int V_156 ;
if ( ! V_155 ++ )
F_29 ( L_57 ,
V_157 ) ;
V_140 = F_74 ( sizeof *V_140 , V_48 ) ;
if ( ! V_140 ) {
V_140 = F_64 ( - V_49 ) ;
goto V_50;
}
V_140 -> V_120 = * V_145 ;
F_43 ( L_58 ,
V_46 , F_44 ( V_140 -> V_120 . V_125 ) ,
V_140 -> V_120 . V_158 , V_140 -> V_120 . V_159 ,
V_140 -> V_120 . V_160 , V_140 -> V_120 . V_161 ) ;
F_24 ( & V_162 ) ;
F_75 ( & V_140 -> V_111 , & V_163 ) ;
F_25 ( & V_162 ) ;
for ( V_156 = 0 ; V_156 < V_140 -> V_120 . V_159 ; V_156 ++ )
F_43 ( L_59 , V_156 , V_140 -> V_120 . V_164 [ V_156 ] ) ;
V_50:
return V_140 ;
}
static inline struct V_165 * F_76 ( const struct V_166 * V_167 ,
const T_5 * V_168 ,
T_6 V_169 )
{
struct V_165 * V_170 ;
V_170 = F_77 ( V_167 -> V_171 + sizeof( struct V_172 ) +
sizeof( struct V_173 ) - V_169 , V_174 ) ;
if ( F_78 ( ! V_170 ) )
return NULL ;
F_79 ( V_170 , V_167 -> V_171 + sizeof( struct V_172 ) +
sizeof( struct V_173 ) - V_169 ) ;
F_80 ( V_170 , V_168 , sizeof( struct V_172 ) +
sizeof( struct V_173 ) ) ;
F_81 ( V_170 , sizeof( struct V_173 ) +
sizeof( struct V_172 ) ,
V_167 -> V_175 + V_169 ,
V_167 -> V_171 - V_169 ) ;
return V_170 ;
}
static inline int F_82 ( struct V_61 * V_62 , const struct V_166 * V_167 ,
const T_5 * V_168 )
{
unsigned int V_176 = * ( V_177 * ) V_168 ;
struct V_165 * V_170 ;
if ( V_176 != V_178 )
goto V_50;
V_170 = F_76 ( V_167 , V_168 , V_62 -> V_64 . V_120 . V_179 ) ;
if ( V_170 == NULL )
goto V_50;
if ( V_180 [ V_176 ] == NULL ) {
F_29 ( L_60 , V_46 ,
V_176 ) ;
F_83 ( V_170 ) ;
goto V_50;
}
V_180 [ V_176 ] ( V_62 , V_170 ) ;
return 1 ;
V_50:
return 0 ;
}
static int F_84 ( void * V_181 , const T_5 * V_168 ,
const struct V_166 * V_167 )
{
struct V_139 * V_140 = V_181 ;
struct V_61 * V_62 = V_140 -> V_62 ;
struct V_165 * V_170 ;
V_177 V_176 ;
if ( V_167 == NULL ) {
unsigned int V_182 = 64 - sizeof( struct V_183 ) - 8 ;
V_170 = F_77 ( 256 , V_174 ) ;
if ( ! V_170 )
goto V_184;
F_79 ( V_170 , V_182 ) ;
F_80 ( V_170 , & V_168 [ 1 ] , V_182 ) ;
} else if ( V_167 == V_185 ) {
const struct V_183 * V_186 = ( void * ) V_168 ;
T_6 V_20 = F_85 ( V_186 -> V_187 ) ;
F_86 ( V_62 , V_20 ) ;
return 0 ;
} else if ( F_78 ( * ( V_177 * ) V_168 != * ( V_177 * ) V_167 -> V_175 ) ) {
if ( F_82 ( V_62 , V_167 , V_168 ) )
return 0 ;
F_29 ( L_61 \
L_62 ,
F_44 ( V_140 -> V_120 . V_125 ) , V_167 -> V_175 ,
( unsigned long long ) F_87 ( * V_168 ) ,
( unsigned long long ) F_87 (
* ( V_188 T_5 * ) V_167 -> V_175 ) ,
V_167 -> V_171 ) ;
return 0 ;
} else {
V_170 = F_88 ( V_167 , 128 , 128 ) ;
if ( F_78 ( ! V_170 ) )
goto V_184;
}
V_176 = * ( V_177 * ) V_168 ;
if ( V_180 [ V_176 ] )
V_180 [ V_176 ] ( V_62 , V_170 ) ;
else
F_29 ( L_60 , V_46 ,
V_176 ) ;
return 0 ;
V_184:
return - 1 ;
}
static int F_89 ( void * V_181 , enum V_189 V_190 )
{
struct V_139 * V_140 = V_181 ;
F_43 ( L_63 , V_46 , V_190 ) ;
switch ( V_190 ) {
case V_191 :
F_7 (KERN_INFO MOD L_64 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_140 -> V_62 ) {
int V_47 ;
V_140 -> V_62 = F_63 ( & V_140 -> V_120 ) ;
if ( F_90 ( V_140 -> V_62 ) ) {
F_7 (KERN_ERR MOD
L_65 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_140 -> V_62 = NULL ;
break;
}
V_47 = F_91 ( V_140 -> V_62 ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD
L_66 ,
pci_name(ctx->lldi.pdev), ret) ;
F_56 ( V_140 ) ;
}
}
break;
case V_192 :
F_7 (KERN_INFO MOD L_67 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_140 -> V_62 )
F_60 ( V_140 ) ;
break;
case V_193 :
F_7 (KERN_INFO MOD L_68 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_140 -> V_62 ) {
struct V_194 V_195 ;
V_140 -> V_62 -> V_64 . V_34 |= V_196 ;
memset ( & V_195 , 0 , sizeof V_195 ) ;
V_195 . V_195 = V_197 ;
V_195 . V_198 = & V_140 -> V_62 -> V_143 ;
F_92 ( & V_195 ) ;
F_60 ( V_140 ) ;
}
break;
case V_199 :
F_7 (KERN_INFO MOD L_69 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_140 -> V_62 )
F_60 ( V_140 ) ;
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
static void F_95 ( struct V_139 * V_140 )
{
F_12 ( & V_140 -> V_62 -> V_53 ) ;
if ( V_140 -> V_62 -> V_79 == V_200 ) {
V_140 -> V_62 -> V_64 . V_65 . V_80 ++ ;
V_140 -> V_62 -> V_79 = V_201 ;
F_13 ( & V_140 -> V_62 -> V_54 , F_93 , NULL ) ;
}
F_14 ( & V_140 -> V_62 -> V_53 ) ;
}
static int F_96 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_97 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_98 ( struct V_139 * V_140 )
{
F_12 ( & V_140 -> V_62 -> V_53 ) ;
if ( V_140 -> V_62 -> V_202 <= V_149 &&
V_140 -> V_62 -> V_79 == V_201 ) {
V_140 -> V_62 -> V_79 = V_200 ;
V_140 -> V_62 -> V_64 . V_65 . V_80 ++ ;
F_13 ( & V_140 -> V_62 -> V_54 , F_96 , NULL ) ;
}
F_14 ( & V_140 -> V_62 -> V_53 ) ;
}
static int F_99 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_203 * V_204 = V_3 ;
struct V_13 * V_14 = V_2 ;
F_100 ( & V_14 -> V_205 ) ;
V_204 -> V_206 [ V_204 -> V_207 ++ ] = V_14 ;
return 0 ;
}
static int F_101 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_102 ( struct V_203 V_203 )
{
int V_207 ;
for ( V_207 = 0 ; V_207 < V_203 . V_207 ; V_207 ++ )
F_103 ( & V_203 . V_206 [ V_207 ] -> V_205 ) ;
}
static void F_104 ( struct V_139 * V_140 , struct V_203 * V_203 )
{
int V_207 ;
int V_47 ;
for ( V_207 = 0 ; V_207 < V_203 -> V_207 ; V_207 ++ ) {
struct V_13 * V_14 = V_203 -> V_206 [ V_207 ] ;
V_47 = F_105 ( V_14 -> V_208 -> V_64 . V_120 . V_209 [ 0 ] ,
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
V_47 = F_105 ( V_14 -> V_208 -> V_64 . V_120 . V_209 [ 0 ] ,
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
while ( F_110 ( V_14 -> V_208 -> V_64 . V_120 . V_209 [ 0 ] , 1 ) > 0 ) {
F_111 ( V_210 ) ;
F_112 ( F_113 ( 10 ) ) ;
}
}
}
static void F_114 ( struct V_139 * V_140 )
{
int V_7 = 0 ;
struct V_203 V_203 ;
int V_47 ;
F_24 ( & V_140 -> V_62 -> V_153 ) ;
F_12 ( & V_140 -> V_62 -> V_53 ) ;
V_140 -> V_62 -> V_79 = V_211 ;
V_140 -> V_62 -> V_64 . V_65 . V_80 ++ ;
F_13 ( & V_140 -> V_62 -> V_54 , F_93 , NULL ) ;
F_14 ( & V_140 -> V_62 -> V_53 ) ;
F_111 ( V_210 ) ;
F_112 ( F_113 ( 1000 ) ) ;
while ( F_110 ( V_140 -> V_62 -> V_64 . V_120 . V_209 [ 0 ] , 1 ) > 0 ) {
F_111 ( V_210 ) ;
F_112 ( F_113 ( 10 ) ) ;
}
V_47 = F_115 ( V_140 -> V_62 -> V_64 . V_120 . V_209 [ 0 ] ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_74 ,
pci_name(ctx->lldi.pdev)) ;
goto V_50;
}
F_12 ( & V_140 -> V_62 -> V_53 ) ;
F_13 ( & V_140 -> V_62 -> V_54 , F_101 , & V_7 ) ;
V_203 . V_206 = F_74 ( V_7 * sizeof * V_203 . V_206 , V_174 ) ;
if ( ! V_203 . V_206 ) {
F_7 (KERN_ERR MOD L_74 ,
pci_name(ctx->lldi.pdev)) ;
F_14 ( & V_140 -> V_62 -> V_53 ) ;
goto V_50;
}
V_203 . V_207 = 0 ;
F_13 ( & V_140 -> V_62 -> V_54 , F_99 , & V_203 ) ;
F_14 ( & V_140 -> V_62 -> V_53 ) ;
F_104 ( V_140 , & V_203 ) ;
F_102 ( V_203 ) ;
F_9 ( V_203 . V_206 ) ;
while ( F_110 ( V_140 -> V_62 -> V_64 . V_120 . V_209 [ 0 ] , 1 ) > 0 ) {
F_111 ( V_210 ) ;
F_112 ( F_113 ( 10 ) ) ;
}
F_12 ( & V_140 -> V_62 -> V_53 ) ;
if ( V_140 -> V_62 -> V_202 > V_149 )
V_140 -> V_62 -> V_79 = V_201 ;
else {
V_140 -> V_62 -> V_79 = V_200 ;
F_13 ( & V_140 -> V_62 -> V_54 , F_96 , NULL ) ;
}
V_140 -> V_62 -> V_64 . V_65 . V_80 ++ ;
F_14 ( & V_140 -> V_62 -> V_53 ) ;
V_50:
F_25 ( & V_140 -> V_62 -> V_153 ) ;
}
static int F_116 ( void * V_181 , enum V_212 V_213 , ... )
{
struct V_139 * V_140 = V_181 ;
switch ( V_213 ) {
case V_214 :
F_95 ( V_140 ) ;
F_24 ( & V_140 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_140 -> V_62 -> V_64 . V_65 . V_75 ++ ;
F_25 ( & V_140 -> V_62 -> V_64 . V_65 . V_53 ) ;
break;
case V_215 :
F_98 ( V_140 ) ;
F_24 ( & V_140 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_140 -> V_62 -> V_64 . V_65 . V_76 ++ ;
F_25 ( & V_140 -> V_62 -> V_64 . V_65 . V_53 ) ;
break;
case V_216 :
F_114 ( V_140 ) ;
F_24 ( & V_140 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_140 -> V_62 -> V_64 . V_65 . V_77 ++ ;
F_25 ( & V_140 -> V_62 -> V_64 . V_65 . V_53 ) ;
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
V_154 = F_72 ( V_217 , NULL ) ;
if ( ! V_154 )
F_7 (KERN_WARNING MOD
L_76 ) ;
F_119 ( V_218 , & V_219 ) ;
return 0 ;
}
static void T_8 F_120 ( void )
{
struct V_139 * V_140 , * V_220 ;
F_24 ( & V_162 ) ;
F_121 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_140 -> V_62 )
F_60 ( V_140 ) ;
F_9 ( V_140 ) ;
}
F_25 ( & V_162 ) ;
F_122 ( V_218 ) ;
F_123 () ;
F_124 ( V_154 ) ;
}
