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
struct V_27 * V_31 = (struct V_27 * )
& V_14 -> V_22 -> V_23 . V_32 ;
struct V_27 * V_33 = (struct V_27 * )
& V_14 -> V_22 -> V_23 . V_34 ;
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_1
L_2
L_3 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_35 . V_20 ,
( int ) V_14 -> V_36 . V_37 ,
V_14 -> V_18 . V_19 . V_38 & V_39 ,
V_14 -> V_22 -> V_40 , ( int ) V_14 -> V_22 -> V_23 . V_37 ,
& V_28 -> V_41 , F_5 ( V_28 -> V_42 ) ,
F_5 ( V_31 -> V_42 ) ,
& V_29 -> V_41 , F_5 ( V_29 -> V_42 ) ,
F_5 ( V_33 -> V_42 ) ) ;
} else {
struct V_43 * V_44 = (struct V_43 * )
& V_14 -> V_22 -> V_23 . V_24 ;
struct V_43 * V_45 = (struct V_43 * )
& V_14 -> V_22 -> V_23 . V_30 ;
struct V_43 * V_46 =
(struct V_43 * )
& V_14 -> V_22 -> V_23 . V_32 ;
struct V_43 * V_47 =
(struct V_43 * )
& V_14 -> V_22 -> V_23 . V_34 ;
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_1
L_2
L_4 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_35 . V_20 ,
( int ) V_14 -> V_36 . V_37 ,
V_14 -> V_18 . V_19 . V_38 & V_39 ,
V_14 -> V_22 -> V_40 , ( int ) V_14 -> V_22 -> V_23 . V_37 ,
& V_44 -> V_48 ,
F_5 ( V_44 -> V_49 ) ,
F_5 ( V_46 -> V_49 ) ,
& V_45 -> V_48 ,
F_5 ( V_45 -> V_49 ) ,
F_5 ( V_47 -> V_49 ) ) ;
}
} else
V_17 = snprintf ( V_15 -> V_6 + V_15 -> V_12 , V_16 ,
L_5 ,
V_14 -> V_18 . V_19 . V_20 , V_14 -> V_18 . V_35 . V_20 ,
( int ) V_14 -> V_36 . V_37 ,
V_14 -> V_18 . V_19 . V_38 & V_39 ) ;
if ( V_17 < V_16 )
V_15 -> V_12 += V_17 ;
return 0 ;
}
static int F_6 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
struct V_9 * V_15 = V_5 -> V_11 ;
if ( ! V_15 ) {
F_7 ( V_51 L_6 , V_52 ) ;
return 0 ;
}
F_8 ( V_15 -> V_6 ) ;
F_9 ( V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
struct V_9 * V_15 ;
int V_53 = 0 ;
int V_7 = 1 ;
V_15 = F_11 ( sizeof *V_15 , V_54 ) ;
if ( ! V_15 ) {
V_53 = - V_55 ;
goto V_56;
}
V_15 -> V_57 = V_50 -> V_58 ;
V_15 -> V_12 = 0 ;
F_12 ( & V_15 -> V_57 -> V_59 ) ;
F_13 ( & V_15 -> V_57 -> V_60 , F_1 , & V_7 ) ;
F_14 ( & V_15 -> V_57 -> V_59 ) ;
V_15 -> V_21 = V_7 * 128 ;
V_15 -> V_6 = F_15 ( V_15 -> V_21 ) ;
if ( ! V_15 -> V_6 ) {
V_53 = - V_55 ;
goto V_61;
}
F_12 ( & V_15 -> V_57 -> V_59 ) ;
F_13 ( & V_15 -> V_57 -> V_60 , F_4 , V_15 ) ;
F_14 ( & V_15 -> V_57 -> V_59 ) ;
V_15 -> V_6 [ V_15 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_15 ;
goto V_56;
V_61:
F_9 ( V_15 ) ;
V_56:
return V_53 ;
}
static int F_16 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_9 * V_62 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_62 -> V_21 - V_62 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
V_17 = snprintf ( V_62 -> V_6 + V_62 -> V_12 , V_16 , L_7 , V_1 << 8 ) ;
if ( V_17 < V_16 )
V_62 -> V_12 += V_17 ;
return 0 ;
}
static int F_17 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
struct V_9 * V_62 = V_5 -> V_11 ;
if ( ! V_62 ) {
F_7 ( V_51 L_8 , V_52 ) ;
return 0 ;
}
F_9 ( V_62 -> V_6 ) ;
F_9 ( V_62 ) ;
return 0 ;
}
static int F_18 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
struct V_9 * V_62 ;
int V_53 = 0 ;
int V_7 = 1 ;
V_62 = F_11 ( sizeof *V_62 , V_54 ) ;
if ( ! V_62 ) {
V_53 = - V_55 ;
goto V_56;
}
V_62 -> V_57 = V_50 -> V_58 ;
V_62 -> V_12 = 0 ;
F_12 ( & V_62 -> V_57 -> V_59 ) ;
F_13 ( & V_62 -> V_57 -> V_63 , F_1 , & V_7 ) ;
F_14 ( & V_62 -> V_57 -> V_59 ) ;
V_62 -> V_21 = V_7 * sizeof( L_9 ) ;
V_62 -> V_6 = F_11 ( V_62 -> V_21 , V_54 ) ;
if ( ! V_62 -> V_6 ) {
V_53 = - V_55 ;
goto V_61;
}
F_12 ( & V_62 -> V_57 -> V_59 ) ;
F_13 ( & V_62 -> V_57 -> V_63 , F_16 , V_62 ) ;
F_14 ( & V_62 -> V_57 -> V_59 ) ;
V_62 -> V_6 [ V_62 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_62 ;
goto V_56;
V_61:
F_9 ( V_62 ) ;
V_56:
return V_53 ;
}
static int F_19 ( struct V_64 * V_65 , void * V_66 )
{
struct V_67 * V_68 = V_65 -> V_69 ;
F_20 ( V_65 , L_10 , L_11 , L_12 ,
L_13 , L_14 ) ;
F_20 ( V_65 , L_15 ,
V_68 -> V_70 . V_71 . V_72 . V_73 , V_68 -> V_70 . V_71 . V_72 . V_74 ,
V_68 -> V_70 . V_71 . V_72 . V_75 , V_68 -> V_70 . V_71 . V_72 . V_76 ) ;
F_20 ( V_65 , L_16 ,
V_68 -> V_70 . V_71 . V_20 . V_73 , V_68 -> V_70 . V_71 . V_20 . V_74 ,
V_68 -> V_70 . V_71 . V_20 . V_75 , V_68 -> V_70 . V_71 . V_20 . V_76 ) ;
F_20 ( V_65 , L_17 ,
V_68 -> V_70 . V_71 . V_77 . V_73 , V_68 -> V_70 . V_71 . V_77 . V_74 ,
V_68 -> V_70 . V_71 . V_77 . V_75 , V_68 -> V_70 . V_71 . V_77 . V_76 ) ;
F_20 ( V_65 , L_18 ,
V_68 -> V_70 . V_71 . V_78 . V_73 , V_68 -> V_70 . V_71 . V_78 . V_74 ,
V_68 -> V_70 . V_71 . V_78 . V_75 , V_68 -> V_70 . V_71 . V_78 . V_76 ) ;
F_20 ( V_65 , L_19 ,
V_68 -> V_70 . V_71 . V_79 . V_73 , V_68 -> V_70 . V_71 . V_79 . V_74 ,
V_68 -> V_70 . V_71 . V_79 . V_75 , V_68 -> V_70 . V_71 . V_79 . V_76 ) ;
F_20 ( V_65 , L_20 ,
V_68 -> V_70 . V_71 . V_80 . V_73 , V_68 -> V_70 . V_71 . V_80 . V_74 ,
V_68 -> V_70 . V_71 . V_80 . V_75 , V_68 -> V_70 . V_71 . V_80 . V_76 ) ;
F_20 ( V_65 , L_21 , V_68 -> V_70 . V_71 . V_81 ) ;
F_20 ( V_65 , L_22 , V_68 -> V_70 . V_71 . V_82 ) ;
F_20 ( V_65 , L_23 , V_68 -> V_70 . V_71 . V_83 ) ;
F_20 ( V_65 , L_24 ,
V_84 [ V_68 -> V_85 ] ,
V_68 -> V_70 . V_71 . V_86 ,
V_68 -> V_70 . V_71 . V_87 ) ;
F_20 ( V_65 , L_25 , V_68 -> V_70 . V_71 . V_88 ) ;
F_20 ( V_65 , L_26 ,
V_68 -> V_70 . V_71 . V_89 ) ;
F_20 ( V_65 , L_27 ,
V_68 -> V_70 . V_71 . V_90 ) ;
return 0 ;
}
static int F_21 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
return F_22 ( V_5 , F_19 , V_50 -> V_58 ) ;
}
static T_1 F_23 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_12 )
{
struct V_67 * V_68 = ( (struct V_64 * ) V_5 -> V_11 ) -> V_69 ;
F_24 ( & V_68 -> V_70 . V_71 . V_59 ) ;
V_68 -> V_70 . V_71 . V_72 . V_75 = 0 ;
V_68 -> V_70 . V_71 . V_72 . V_76 = 0 ;
V_68 -> V_70 . V_71 . V_20 . V_75 = 0 ;
V_68 -> V_70 . V_71 . V_20 . V_76 = 0 ;
V_68 -> V_70 . V_71 . V_77 . V_75 = 0 ;
V_68 -> V_70 . V_71 . V_77 . V_76 = 0 ;
V_68 -> V_70 . V_71 . V_78 . V_75 = 0 ;
V_68 -> V_70 . V_71 . V_78 . V_76 = 0 ;
V_68 -> V_70 . V_71 . V_79 . V_75 = 0 ;
V_68 -> V_70 . V_71 . V_79 . V_76 = 0 ;
V_68 -> V_70 . V_71 . V_80 . V_75 = 0 ;
V_68 -> V_70 . V_71 . V_80 . V_76 = 0 ;
V_68 -> V_70 . V_71 . V_81 = 0 ;
V_68 -> V_70 . V_71 . V_82 = 0 ;
V_68 -> V_70 . V_71 . V_83 = 0 ;
V_68 -> V_70 . V_71 . V_86 = 0 ;
V_68 -> V_70 . V_71 . V_88 = 0 ;
V_68 -> V_70 . V_71 . V_89 = 0 ;
V_68 -> V_70 . V_71 . V_90 = 0 ;
F_25 ( & V_68 -> V_70 . V_71 . V_59 ) ;
return V_7 ;
}
static int F_26 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_91 * V_22 = V_2 ;
struct V_9 * V_92 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_92 -> V_21 - V_92 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_22 -> V_23 . V_24 ;
struct V_27 * V_29 = (struct V_27 * )
& V_22 -> V_23 . V_30 ;
struct V_27 * V_31 = (struct V_27 * )
& V_22 -> V_23 . V_32 ;
struct V_27 * V_33 = (struct V_27 * )
& V_22 -> V_23 . V_34 ;
V_17 = snprintf ( V_92 -> V_6 + V_92 -> V_12 , V_16 ,
L_28
L_29
L_30 ,
V_22 , V_22 -> V_23 . V_93 , V_22 -> V_23 . V_14 ,
( int ) V_22 -> V_23 . V_37 , V_22 -> V_23 . V_38 ,
V_22 -> V_23 . V_94 , V_22 -> V_40 , V_22 -> V_95 ,
& V_28 -> V_41 , F_5 ( V_28 -> V_42 ) ,
F_5 ( V_31 -> V_42 ) ,
& V_29 -> V_41 , F_5 ( V_29 -> V_42 ) ,
F_5 ( V_33 -> V_42 ) ) ;
} else {
struct V_43 * V_44 = (struct V_43 * )
& V_22 -> V_23 . V_24 ;
struct V_43 * V_45 = (struct V_43 * )
& V_22 -> V_23 . V_30 ;
struct V_43 * V_46 = (struct V_43 * )
& V_22 -> V_23 . V_32 ;
struct V_43 * V_47 = (struct V_43 * )
& V_22 -> V_23 . V_34 ;
V_17 = snprintf ( V_92 -> V_6 + V_92 -> V_12 , V_16 ,
L_28
L_29
L_31 ,
V_22 , V_22 -> V_23 . V_93 , V_22 -> V_23 . V_14 ,
( int ) V_22 -> V_23 . V_37 , V_22 -> V_23 . V_38 ,
V_22 -> V_23 . V_94 , V_22 -> V_40 , V_22 -> V_95 ,
& V_44 -> V_48 , F_5 ( V_44 -> V_49 ) ,
F_5 ( V_46 -> V_49 ) ,
& V_45 -> V_48 , F_5 ( V_45 -> V_49 ) ,
F_5 ( V_47 -> V_49 ) ) ;
}
if ( V_17 < V_16 )
V_92 -> V_12 += V_17 ;
return 0 ;
}
static int F_27 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_96 * V_22 = V_2 ;
struct V_9 * V_92 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_92 -> V_21 - V_92 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_22 -> V_23 . V_24 ;
struct V_27 * V_31 = (struct V_27 * )
& V_22 -> V_23 . V_32 ;
V_17 = snprintf ( V_92 -> V_6 + V_92 -> V_12 , V_16 ,
L_32
L_33 ,
V_22 , V_22 -> V_23 . V_93 , ( int ) V_22 -> V_23 . V_37 ,
V_22 -> V_23 . V_38 , V_22 -> V_97 , V_22 -> V_98 ,
& V_28 -> V_41 , F_5 ( V_28 -> V_42 ) ,
F_5 ( V_31 -> V_42 ) ) ;
} else {
struct V_43 * V_44 = (struct V_43 * )
& V_22 -> V_23 . V_24 ;
struct V_43 * V_46 = (struct V_43 * )
& V_22 -> V_23 . V_32 ;
V_17 = snprintf ( V_92 -> V_6 + V_92 -> V_12 , V_16 ,
L_32
L_34 ,
V_22 , V_22 -> V_23 . V_93 , ( int ) V_22 -> V_23 . V_37 ,
V_22 -> V_23 . V_38 , V_22 -> V_97 , V_22 -> V_98 ,
& V_44 -> V_48 , F_5 ( V_44 -> V_49 ) ,
F_5 ( V_46 -> V_49 ) ) ;
}
if ( V_17 < V_16 )
V_92 -> V_12 += V_17 ;
return 0 ;
}
static int F_28 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
struct V_9 * V_92 = V_5 -> V_11 ;
if ( ! V_92 ) {
F_29 ( L_6 , V_52 ) ;
return 0 ;
}
F_8 ( V_92 -> V_6 ) ;
F_9 ( V_92 ) ;
return 0 ;
}
static int F_30 ( struct V_50 * V_50 , struct V_5 * V_5 )
{
struct V_9 * V_92 ;
int V_53 = 0 ;
int V_7 = 1 ;
V_92 = F_11 ( sizeof( * V_92 ) , V_54 ) ;
if ( ! V_92 ) {
V_53 = - V_55 ;
goto V_56;
}
V_92 -> V_57 = V_50 -> V_58 ;
V_92 -> V_12 = 0 ;
F_12 ( & V_92 -> V_57 -> V_59 ) ;
F_13 ( & V_92 -> V_57 -> V_99 , F_1 , & V_7 ) ;
F_13 ( & V_92 -> V_57 -> V_100 , F_1 , & V_7 ) ;
F_13 ( & V_92 -> V_57 -> V_101 , F_1 , & V_7 ) ;
F_14 ( & V_92 -> V_57 -> V_59 ) ;
V_92 -> V_21 = V_7 * 160 ;
V_92 -> V_6 = F_15 ( V_92 -> V_21 ) ;
if ( ! V_92 -> V_6 ) {
V_53 = - V_55 ;
goto V_61;
}
F_12 ( & V_92 -> V_57 -> V_59 ) ;
F_13 ( & V_92 -> V_57 -> V_99 , F_26 , V_92 ) ;
F_13 ( & V_92 -> V_57 -> V_100 , F_26 , V_92 ) ;
F_13 ( & V_92 -> V_57 -> V_101 , F_27 , V_92 ) ;
F_14 ( & V_92 -> V_57 -> V_59 ) ;
V_5 -> V_11 = V_92 ;
goto V_56;
V_61:
F_9 ( V_92 ) ;
V_56:
return V_53 ;
}
static int F_31 ( struct V_67 * V_57 )
{
struct V_102 * V_103 ;
if ( ! V_57 -> V_104 )
return - 1 ;
V_103 = F_32 ( L_35 , V_105 , V_57 -> V_104 ,
( void * ) V_57 , & V_106 ) ;
if ( V_103 && V_103 -> V_107 )
V_103 -> V_107 -> V_108 = 4096 ;
V_103 = F_32 ( L_36 , V_105 , V_57 -> V_104 ,
( void * ) V_57 , & V_109 ) ;
if ( V_103 && V_103 -> V_107 )
V_103 -> V_107 -> V_108 = 4096 ;
V_103 = F_32 ( L_37 , V_105 , V_57 -> V_104 ,
( void * ) V_57 , & V_110 ) ;
if ( V_103 && V_103 -> V_107 )
V_103 -> V_107 -> V_108 = 4096 ;
V_103 = F_32 ( L_38 , V_105 , V_57 -> V_104 ,
( void * ) V_57 , & V_111 ) ;
if ( V_103 && V_103 -> V_107 )
V_103 -> V_107 -> V_108 = 4096 ;
return 0 ;
}
void F_33 ( struct V_112 * V_70 ,
struct V_113 * V_114 )
{
struct V_115 * V_12 , * V_116 ;
struct V_117 * V_118 ;
F_24 ( & V_114 -> V_59 ) ;
F_34 (pos, nxt, &uctx->qpids) {
V_118 = F_35 ( V_12 , struct V_117 , V_118 ) ;
F_36 ( & V_118 -> V_118 ) ;
if ( ! ( V_118 -> V_20 & V_70 -> V_119 ) ) {
F_37 ( & V_70 -> V_120 . V_121 ,
V_118 -> V_20 ) ;
F_24 ( & V_70 -> V_71 . V_59 ) ;
V_70 -> V_71 . V_20 . V_74 -= V_70 -> V_119 + 1 ;
F_25 ( & V_70 -> V_71 . V_59 ) ;
}
F_9 ( V_118 ) ;
}
F_34 (pos, nxt, &uctx->qpids) {
V_118 = F_35 ( V_12 , struct V_117 , V_118 ) ;
F_36 ( & V_118 -> V_118 ) ;
F_9 ( V_118 ) ;
}
F_25 ( & V_114 -> V_59 ) ;
}
void F_38 ( struct V_112 * V_70 ,
struct V_113 * V_114 )
{
F_39 ( & V_114 -> V_122 ) ;
F_39 ( & V_114 -> V_123 ) ;
F_40 ( & V_114 -> V_59 ) ;
}
static int F_41 ( struct V_112 * V_70 )
{
int V_124 ;
F_38 ( V_70 , & V_70 -> V_114 ) ;
V_70 -> V_125 = V_126 - F_42 ( V_70 -> V_127 . V_128 ) ;
V_70 -> V_119 = V_70 -> V_127 . V_128 - 1 ;
V_70 -> V_129 = V_126 - F_42 ( V_70 -> V_127 . V_130 ) ;
V_70 -> V_131 = V_70 -> V_127 . V_130 - 1 ;
F_43 ( L_39
L_40
L_41 ,
V_52 , F_44 ( V_70 -> V_127 . V_132 ) , V_70 -> V_127 . V_133 -> V_77 . V_134 ,
V_70 -> V_127 . V_133 -> V_77 . V_135 , F_45 ( V_70 ) ,
V_70 -> V_127 . V_133 -> V_78 . V_134 ,
V_70 -> V_127 . V_133 -> V_78 . V_135 , V_70 -> V_127 . V_133 -> V_35 . V_134 ,
V_70 -> V_127 . V_133 -> V_35 . V_135 ,
V_70 -> V_127 . V_133 -> V_14 . V_134 ,
V_70 -> V_127 . V_133 -> V_14 . V_135 ,
V_70 -> V_127 . V_133 -> V_136 . V_134 ,
V_70 -> V_127 . V_133 -> V_136 . V_135 ) ;
F_43 ( L_42
L_43 ,
( unsigned ) F_46 ( V_70 -> V_127 . V_132 , 2 ) ,
( V_137 ) F_47 ( V_70 -> V_127 . V_132 , 2 ) ,
V_70 -> V_127 . V_138 ,
V_70 -> V_127 . V_139 ,
V_70 -> V_125 , V_70 -> V_119 ,
V_70 -> V_129 , V_70 -> V_131 ) ;
if ( F_45 ( V_70 ) == 0 ) {
V_124 = - V_140 ;
goto V_61;
}
V_70 -> V_71 . V_72 . V_73 = V_141 ;
V_70 -> V_71 . V_77 . V_73 = V_70 -> V_127 . V_133 -> V_77 . V_135 ;
V_70 -> V_71 . V_78 . V_73 = V_70 -> V_127 . V_133 -> V_78 . V_135 ;
V_70 -> V_71 . V_79 . V_73 = V_70 -> V_127 . V_133 -> V_35 . V_135 ;
V_70 -> V_71 . V_80 . V_73 = V_70 -> V_127 . V_133 -> V_142 . V_135 ;
V_70 -> V_71 . V_20 . V_73 = V_70 -> V_127 . V_133 -> V_14 . V_135 ;
V_124 = F_48 ( V_70 , F_45 ( V_70 ) , V_141 ) ;
if ( V_124 ) {
F_7 (KERN_ERR MOD L_44 , err) ;
goto V_61;
}
V_124 = F_49 ( V_70 ) ;
if ( V_124 ) {
F_7 (KERN_ERR MOD L_45 , err) ;
goto V_143;
}
V_124 = F_50 ( V_70 ) ;
if ( V_124 ) {
F_7 (KERN_ERR MOD L_46 , err) ;
goto V_144;
}
V_124 = F_51 ( V_70 ) ;
if ( V_124 ) {
F_7 (KERN_ERR MOD L_47 , err) ;
goto V_145;
}
V_70 -> V_146 = (struct V_147 * )
F_52 ( V_54 ) ;
if ( ! V_70 -> V_146 ) {
F_53 ( V_148 L_48 ) ;
goto V_145;
}
V_70 -> V_146 -> V_149 = 0 ;
return 0 ;
V_145:
F_54 ( V_70 ) ;
V_144:
F_55 ( V_70 ) ;
V_143:
F_56 ( & V_70 -> V_120 ) ;
V_61:
return V_124 ;
}
static void F_57 ( struct V_112 * V_70 )
{
F_58 ( ( unsigned long ) V_70 -> V_146 ) ;
F_55 ( V_70 ) ;
F_54 ( V_70 ) ;
F_56 ( & V_70 -> V_120 ) ;
}
static void F_59 ( struct V_150 * V_151 )
{
F_57 ( & V_151 -> V_68 -> V_70 ) ;
F_60 ( & V_151 -> V_68 -> V_152 ) ;
F_60 ( & V_151 -> V_68 -> V_60 ) ;
F_60 ( & V_151 -> V_68 -> V_63 ) ;
F_60 ( & V_151 -> V_68 -> V_99 ) ;
F_60 ( & V_151 -> V_68 -> V_101 ) ;
F_60 ( & V_151 -> V_68 -> V_100 ) ;
if ( V_151 -> V_68 -> V_70 . V_153 )
F_61 ( V_151 -> V_68 -> V_70 . V_153 ) ;
if ( V_151 -> V_68 -> V_70 . V_154 )
F_61 ( V_151 -> V_68 -> V_70 . V_154 ) ;
F_62 ( & V_151 -> V_68 -> V_155 ) ;
V_151 -> V_68 = NULL ;
}
static void F_63 ( struct V_150 * V_151 )
{
F_43 ( L_49 , V_52 , V_151 -> V_68 ) ;
F_64 ( V_151 -> V_68 ) ;
F_59 ( V_151 ) ;
}
static int F_65 ( const struct V_156 * V_157 )
{
return V_157 -> V_133 -> V_77 . V_135 > 0 && V_157 -> V_133 -> V_78 . V_135 > 0 &&
V_157 -> V_133 -> V_35 . V_135 > 0 && V_157 -> V_133 -> V_14 . V_135 > 0 &&
V_157 -> V_133 -> V_136 . V_135 > 0 ;
}
static struct V_67 * F_66 ( const struct V_156 * V_157 )
{
struct V_67 * V_57 ;
int V_53 ;
if ( ! F_65 ( V_157 ) ) {
F_7 (KERN_INFO MOD L_50 ,
pci_name(infop->pdev)) ;
return F_67 ( - V_158 ) ;
}
if ( ! F_68 ( V_157 ) )
F_29 ( L_51 ,
F_44 ( V_157 -> V_132 ) ) ;
V_57 = (struct V_67 * ) F_69 ( sizeof( * V_57 ) ) ;
if ( ! V_57 ) {
F_7 (KERN_ERR MOD L_52 ) ;
return F_67 ( - V_55 ) ;
}
V_57 -> V_70 . V_127 = * V_157 ;
V_57 -> V_70 . V_159 = F_47 ( V_57 -> V_70 . V_127 . V_132 , 2 ) ;
if ( F_70 ( V_57 -> V_70 . V_127 . V_160 ) ) {
V_57 -> V_70 . V_153 = F_71 ( V_57 -> V_70 . V_159 ,
F_46 ( V_57 -> V_70 . V_127 . V_132 , 2 ) ) ;
if ( ! V_57 -> V_70 . V_153 ) {
F_53 ( V_148 L_53 ) ;
F_62 ( & V_57 -> V_155 ) ;
return F_67 ( - V_140 ) ;
}
} else if ( F_68 ( V_157 ) ) {
V_57 -> V_70 . V_161 =
F_47 ( V_57 -> V_70 . V_127 . V_132 , 2 ) +
F_46 ( V_57 -> V_70 . V_127 . V_132 , 2 ) -
F_72 ( V_57 -> V_70 . V_127 . V_133 -> V_142 . V_135 ) ;
V_57 -> V_70 . V_154 = F_71 ( V_57 -> V_70 . V_161 ,
V_57 -> V_70 . V_127 . V_133 -> V_142 . V_135 ) ;
if ( ! V_57 -> V_70 . V_154 ) {
F_53 ( V_148 L_54 ) ;
F_62 ( & V_57 -> V_155 ) ;
return F_67 ( - V_140 ) ;
}
}
F_43 (KERN_INFO MOD L_55
L_56 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_53 = F_41 ( & V_57 -> V_70 ) ;
if ( V_53 ) {
F_7 (KERN_ERR MOD L_57 , ret) ;
F_62 ( & V_57 -> V_155 ) ;
return F_67 ( V_53 ) ;
}
F_73 ( & V_57 -> V_152 ) ;
F_73 ( & V_57 -> V_60 ) ;
F_73 ( & V_57 -> V_63 ) ;
F_73 ( & V_57 -> V_99 ) ;
F_73 ( & V_57 -> V_101 ) ;
F_73 ( & V_57 -> V_100 ) ;
F_74 ( & V_57 -> V_59 ) ;
F_40 ( & V_57 -> V_70 . V_71 . V_59 ) ;
F_40 ( & V_57 -> V_162 ) ;
F_39 ( & V_57 -> V_163 ) ;
if ( V_164 ) {
V_57 -> V_104 = F_75 (
F_44 ( V_57 -> V_70 . V_127 . V_132 ) ,
V_164 ) ;
F_31 ( V_57 ) ;
}
return V_57 ;
}
static void * F_76 ( const struct V_156 * V_157 )
{
struct V_150 * V_151 ;
static int V_165 ;
int V_166 ;
if ( ! V_165 ++ )
F_29 ( L_58 ,
V_167 ) ;
V_151 = F_77 ( sizeof *V_151 , V_54 ) ;
if ( ! V_151 ) {
V_151 = F_67 ( - V_55 ) ;
goto V_56;
}
V_151 -> V_127 = * V_157 ;
F_43 ( L_59 ,
V_52 , F_44 ( V_151 -> V_127 . V_132 ) ,
V_151 -> V_127 . V_168 , V_151 -> V_127 . V_169 ,
V_151 -> V_127 . V_170 , V_151 -> V_127 . V_171 ) ;
F_24 ( & V_172 ) ;
F_78 ( & V_151 -> V_118 , & V_173 ) ;
F_25 ( & V_172 ) ;
for ( V_166 = 0 ; V_166 < V_151 -> V_127 . V_169 ; V_166 ++ )
F_43 ( L_60 , V_166 , V_151 -> V_127 . V_174 [ V_166 ] ) ;
V_56:
return V_151 ;
}
static inline struct V_175 * F_79 ( const struct V_176 * V_177 ,
const T_5 * V_178 ,
T_6 V_179 )
{
struct V_175 * V_180 ;
V_180 = F_80 ( V_177 -> V_181 + sizeof( struct V_182 ) +
sizeof( struct V_183 ) - V_179 , V_184 ) ;
if ( F_81 ( ! V_180 ) )
return NULL ;
F_82 ( V_180 , V_177 -> V_181 + sizeof( struct V_182 ) +
sizeof( struct V_183 ) - V_179 ) ;
F_83 ( V_180 , V_178 , sizeof( struct V_182 ) +
sizeof( struct V_183 ) ) ;
F_84 ( V_180 , sizeof( struct V_183 ) +
sizeof( struct V_182 ) ,
V_177 -> V_185 + V_179 ,
V_177 -> V_181 - V_179 ) ;
return V_180 ;
}
static inline int F_85 ( struct V_67 * V_68 , const struct V_176 * V_177 ,
const T_5 * V_178 )
{
unsigned int V_186 = * ( V_187 * ) V_178 ;
struct V_175 * V_180 ;
if ( V_186 != V_188 )
goto V_56;
V_180 = F_79 ( V_177 , V_178 , V_68 -> V_70 . V_127 . V_189 ) ;
if ( V_180 == NULL )
goto V_56;
if ( V_190 [ V_186 ] == NULL ) {
F_29 ( L_61 , V_52 ,
V_186 ) ;
F_86 ( V_180 ) ;
goto V_56;
}
V_190 [ V_186 ] ( V_68 , V_180 ) ;
return 1 ;
V_56:
return 0 ;
}
static int F_87 ( void * V_191 , const T_5 * V_178 ,
const struct V_176 * V_177 )
{
struct V_150 * V_151 = V_191 ;
struct V_67 * V_68 = V_151 -> V_68 ;
struct V_175 * V_180 ;
V_187 V_186 ;
if ( V_177 == NULL ) {
unsigned int V_192 = 64 - sizeof( struct V_193 ) - 8 ;
V_180 = F_80 ( 256 , V_184 ) ;
if ( ! V_180 )
goto V_194;
F_82 ( V_180 , V_192 ) ;
F_83 ( V_180 , & V_178 [ 1 ] , V_192 ) ;
} else if ( V_177 == V_195 ) {
const struct V_193 * V_196 = ( void * ) V_178 ;
T_6 V_20 = F_88 ( V_196 -> V_197 ) ;
F_89 ( V_68 , V_20 ) ;
return 0 ;
} else if ( F_81 ( * ( V_187 * ) V_178 != * ( V_187 * ) V_177 -> V_185 ) ) {
if ( F_85 ( V_68 , V_177 , V_178 ) )
return 0 ;
F_29 ( L_62 \
L_63 ,
F_44 ( V_151 -> V_127 . V_132 ) , V_177 -> V_185 ,
( unsigned long long ) F_90 ( * V_178 ) ,
( unsigned long long ) F_90 (
* ( V_198 T_5 * ) V_177 -> V_185 ) ,
V_177 -> V_181 ) ;
return 0 ;
} else {
V_180 = F_91 ( V_177 , 128 , 128 ) ;
if ( F_81 ( ! V_180 ) )
goto V_194;
}
V_186 = * ( V_187 * ) V_178 ;
if ( V_190 [ V_186 ] ) {
V_190 [ V_186 ] ( V_68 , V_180 ) ;
} else {
F_29 ( L_61 , V_52 ,
V_186 ) ;
F_86 ( V_180 ) ;
}
return 0 ;
V_194:
return - 1 ;
}
static int F_92 ( void * V_191 , enum V_199 V_200 )
{
struct V_150 * V_151 = V_191 ;
F_43 ( L_64 , V_52 , V_200 ) ;
switch ( V_200 ) {
case V_201 :
F_7 (KERN_INFO MOD L_65 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_151 -> V_68 ) {
int V_53 ;
V_151 -> V_68 = F_66 ( & V_151 -> V_127 ) ;
if ( F_93 ( V_151 -> V_68 ) ) {
F_7 (KERN_ERR MOD
L_66 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_151 -> V_68 = NULL ;
break;
}
V_53 = F_94 ( V_151 -> V_68 ) ;
if ( V_53 ) {
F_7 (KERN_ERR MOD
L_67 ,
pci_name(ctx->lldi.pdev), ret) ;
F_59 ( V_151 ) ;
}
}
break;
case V_202 :
F_7 (KERN_INFO MOD L_68 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_151 -> V_68 )
F_63 ( V_151 ) ;
break;
case V_203 :
F_7 (KERN_INFO MOD L_69 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_151 -> V_68 ) {
struct V_204 V_205 ;
V_151 -> V_68 -> V_70 . V_38 |= V_206 ;
memset ( & V_205 , 0 , sizeof V_205 ) ;
V_205 . V_205 = V_207 ;
V_205 . V_208 = & V_151 -> V_68 -> V_155 ;
F_95 ( & V_205 ) ;
F_63 ( V_151 ) ;
}
break;
case V_209 :
F_7 (KERN_INFO MOD L_70 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_151 -> V_68 )
F_63 ( V_151 ) ;
break;
}
return 0 ;
}
static int F_96 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_97 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_98 ( struct V_150 * V_151 )
{
unsigned long V_38 ;
F_99 ( & V_151 -> V_68 -> V_59 , V_38 ) ;
V_151 -> V_68 -> V_70 . V_71 . V_86 ++ ;
V_151 -> V_68 -> V_85 = V_210 ;
if ( V_151 -> V_68 -> V_70 . V_38 & V_211 )
F_13 ( & V_151 -> V_68 -> V_60 , F_96 , NULL ) ;
else
V_151 -> V_68 -> V_70 . V_146 -> V_149 = 1 ;
F_100 ( & V_151 -> V_68 -> V_59 , V_38 ) ;
}
static int F_101 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_102 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_103 ( struct V_13 * V_14 )
{
F_104 ( & V_14 -> V_59 ) ;
F_105 ( & V_14 -> V_18 , V_14 -> V_18 . V_19 . V_212 ,
F_70 ( V_14 -> V_213 -> V_70 . V_127 . V_160 ) , NULL ) ;
V_14 -> V_18 . V_19 . V_212 = 0 ;
F_106 ( & V_14 -> V_18 , V_14 -> V_18 . V_35 . V_212 ,
F_70 ( V_14 -> V_213 -> V_70 . V_127 . V_160 ) , NULL ) ;
V_14 -> V_18 . V_35 . V_212 = 0 ;
F_107 ( & V_14 -> V_59 ) ;
}
static void F_108 ( struct V_150 * V_151 )
{
int V_166 ;
struct V_13 * V_14 ;
for ( V_166 = 0 ; V_166 < V_214 ; V_166 ++ ) {
V_14 = F_109 ( & V_151 -> V_68 -> V_163 , struct V_13 ,
V_215 ) ;
F_36 ( & V_14 -> V_215 ) ;
F_103 ( V_14 ) ;
if ( F_110 ( & V_151 -> V_68 -> V_163 ) )
break;
}
}
static void F_111 ( struct V_150 * V_151 )
{
F_12 ( & V_151 -> V_68 -> V_59 ) ;
if ( V_151 -> V_68 -> V_85 != V_210 )
goto V_56;
V_151 -> V_68 -> V_85 = V_216 ;
while ( 1 ) {
if ( F_110 ( & V_151 -> V_68 -> V_163 ) ) {
F_112 ( V_151 -> V_68 -> V_85 != V_216 ) ;
V_151 -> V_68 -> V_85 = V_217 ;
V_151 -> V_68 -> V_70 . V_71 . V_86 ++ ;
if ( V_151 -> V_68 -> V_70 . V_38 & V_211 ) {
F_13 ( & V_151 -> V_68 -> V_60 , F_101 ,
NULL ) ;
} else {
V_151 -> V_68 -> V_70 . V_146 -> V_149 = 0 ;
}
break;
} else {
if ( F_113 ( V_151 -> V_68 -> V_70 . V_127 . V_218 [ 0 ] , 1 )
< ( V_151 -> V_68 -> V_70 . V_127 . V_219 <<
V_220 ) ) {
F_108 ( V_151 ) ;
}
if ( ! F_110 ( & V_151 -> V_68 -> V_163 ) ) {
F_14 ( & V_151 -> V_68 -> V_59 ) ;
if ( V_221 ) {
F_114 ( V_222 ) ;
F_115 ( V_221 ) ;
}
F_12 ( & V_151 -> V_68 -> V_59 ) ;
if ( V_151 -> V_68 -> V_85 != V_216 )
break;
}
}
}
V_56:
if ( V_151 -> V_68 -> V_85 != V_217 )
V_151 -> V_68 -> V_70 . V_71 . V_87 ++ ;
F_14 ( & V_151 -> V_68 -> V_59 ) ;
}
static int F_116 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_223 * V_224 = V_3 ;
struct V_13 * V_14 = V_2 ;
F_117 ( & V_14 -> V_225 ) ;
V_224 -> V_226 [ V_224 -> V_227 ++ ] = V_14 ;
return 0 ;
}
static int F_118 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_119 ( struct V_223 * V_223 )
{
int V_227 ;
for ( V_227 = 0 ; V_227 < V_223 -> V_227 ; V_227 ++ )
F_120 ( & V_223 -> V_226 [ V_227 ] -> V_225 ) ;
}
static void F_121 ( struct V_150 * V_151 , struct V_223 * V_223 )
{
int V_227 ;
int V_53 ;
for ( V_227 = 0 ; V_227 < V_223 -> V_227 ; V_227 ++ ) {
struct V_13 * V_14 = V_223 -> V_226 [ V_227 ] ;
F_12 ( & V_14 -> V_213 -> V_59 ) ;
F_104 ( & V_14 -> V_59 ) ;
V_53 = F_122 ( V_14 -> V_213 -> V_70 . V_127 . V_218 [ 0 ] ,
V_14 -> V_18 . V_19 . V_20 ,
F_123 ( & V_14 -> V_18 ) ,
F_124 ( & V_14 -> V_18 ) ) ;
if ( V_53 ) {
F_53 (KERN_ERR MOD L_71
L_72
L_73 ,
pci_name(ctx->lldi.pdev), qp->wq.sq.qid) ;
F_107 ( & V_14 -> V_59 ) ;
F_14 ( & V_14 -> V_213 -> V_59 ) ;
return;
}
V_14 -> V_18 . V_19 . V_212 = 0 ;
V_53 = F_122 ( V_14 -> V_213 -> V_70 . V_127 . V_218 [ 0 ] ,
V_14 -> V_18 . V_35 . V_20 ,
F_125 ( & V_14 -> V_18 ) ,
F_126 ( & V_14 -> V_18 ) ) ;
if ( V_53 ) {
F_53 (KERN_ERR MOD L_71
L_72
L_74 ,
pci_name(ctx->lldi.pdev), qp->wq.rq.qid) ;
F_107 ( & V_14 -> V_59 ) ;
F_14 ( & V_14 -> V_213 -> V_59 ) ;
return;
}
V_14 -> V_18 . V_35 . V_212 = 0 ;
F_107 ( & V_14 -> V_59 ) ;
F_14 ( & V_14 -> V_213 -> V_59 ) ;
while ( F_113 ( V_14 -> V_213 -> V_70 . V_127 . V_218 [ 0 ] , 1 ) > 0 ) {
F_114 ( V_222 ) ;
F_115 ( F_127 ( 10 ) ) ;
}
}
}
static void F_128 ( struct V_150 * V_151 )
{
int V_7 = 0 ;
struct V_223 V_223 ;
int V_53 ;
F_114 ( V_222 ) ;
F_115 ( F_127 ( 1000 ) ) ;
V_53 = F_129 ( V_151 -> V_68 -> V_70 . V_127 . V_218 [ 0 ] ) ;
if ( V_53 ) {
F_7 (KERN_ERR MOD L_75 ,
pci_name(ctx->lldi.pdev)) ;
return;
}
F_12 ( & V_151 -> V_68 -> V_59 ) ;
F_112 ( V_151 -> V_68 -> V_85 != V_210 ) ;
V_151 -> V_68 -> V_85 = V_228 ;
F_13 ( & V_151 -> V_68 -> V_60 , F_118 , & V_7 ) ;
V_223 . V_226 = F_77 ( V_7 * sizeof * V_223 . V_226 , V_184 ) ;
if ( ! V_223 . V_226 ) {
F_7 (KERN_ERR MOD L_75 ,
pci_name(ctx->lldi.pdev)) ;
F_14 ( & V_151 -> V_68 -> V_59 ) ;
return;
}
V_223 . V_227 = 0 ;
F_13 ( & V_151 -> V_68 -> V_60 , F_116 , & V_223 ) ;
F_14 ( & V_151 -> V_68 -> V_59 ) ;
F_121 ( V_151 , & V_223 ) ;
F_119 ( & V_223 ) ;
F_9 ( V_223 . V_226 ) ;
F_12 ( & V_151 -> V_68 -> V_59 ) ;
F_112 ( V_151 -> V_68 -> V_85 != V_228 ) ;
V_151 -> V_68 -> V_85 = V_210 ;
F_14 ( & V_151 -> V_68 -> V_59 ) ;
}
static int F_130 ( void * V_191 , enum V_229 V_230 , ... )
{
struct V_150 * V_151 = V_191 ;
switch ( V_230 ) {
case V_231 :
F_98 ( V_151 ) ;
V_151 -> V_68 -> V_70 . V_71 . V_81 ++ ;
break;
case V_232 :
F_111 ( V_151 ) ;
F_24 ( & V_151 -> V_68 -> V_70 . V_71 . V_59 ) ;
V_151 -> V_68 -> V_70 . V_71 . V_82 ++ ;
F_25 ( & V_151 -> V_68 -> V_70 . V_71 . V_59 ) ;
break;
case V_233 :
F_128 ( V_151 ) ;
F_24 ( & V_151 -> V_68 -> V_70 . V_71 . V_59 ) ;
V_151 -> V_68 -> V_70 . V_71 . V_83 ++ ;
F_25 ( & V_151 -> V_68 -> V_70 . V_71 . V_59 ) ;
break;
default:
F_7 (KERN_WARNING MOD L_76 ,
pci_name(ctx->lldi.pdev), control) ;
break;
}
return 0 ;
}
static int T_7 F_131 ( void )
{
int V_124 ;
V_124 = F_132 () ;
if ( V_124 )
return V_124 ;
V_164 = F_75 ( V_234 , NULL ) ;
if ( ! V_164 )
F_7 (KERN_WARNING MOD
L_77 ) ;
if ( F_133 ( V_235 , V_236 ,
V_237 ) )
F_53 ( L_78
, V_52 , __LINE__ ) ;
V_124 = F_134 ( V_235 ) ;
if ( V_124 ) {
F_53 ( L_79 , V_124 ) ;
F_135 ( V_235 ) ;
F_136 () ;
F_137 ( V_164 ) ;
return V_124 ;
}
F_138 ( V_238 , & V_239 ) ;
return 0 ;
}
static void T_8 F_139 ( void )
{
struct V_150 * V_151 , * V_240 ;
F_24 ( & V_172 ) ;
F_140 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_151 -> V_68 )
F_63 ( V_151 ) ;
F_9 ( V_151 ) ;
}
F_25 ( & V_172 ) ;
F_141 ( V_238 ) ;
F_142 ( V_235 ) ;
F_135 ( V_235 ) ;
F_136 () ;
F_137 ( V_164 ) ;
}
