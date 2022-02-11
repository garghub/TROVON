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
V_62 -> V_64 . V_65 . V_80 ,
V_62 -> V_64 . V_65 . V_81 ) ;
F_20 ( V_59 , L_25 , V_62 -> V_64 . V_65 . V_82 ) ;
F_20 ( V_59 , L_26 ,
V_62 -> V_64 . V_65 . V_83 ) ;
F_20 ( V_59 , L_27 ,
V_62 -> V_64 . V_65 . V_84 ) ;
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
V_62 -> V_64 . V_65 . V_82 = 0 ;
V_62 -> V_64 . V_65 . V_83 = 0 ;
V_62 -> V_64 . V_65 . V_84 = 0 ;
F_25 ( & V_62 -> V_64 . V_65 . V_53 ) ;
return V_7 ;
}
static int F_26 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_85 * V_22 = V_2 ;
struct V_9 * V_86 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_86 -> V_21 - V_86 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_22 -> V_23 . V_24 ;
struct V_27 * V_29 = (struct V_27 * )
& V_22 -> V_23 . V_30 ;
V_17 = snprintf ( V_86 -> V_6 + V_86 -> V_12 , V_16 ,
L_28
L_29
L_30 ,
V_22 , V_22 -> V_23 . V_87 , V_22 -> V_23 . V_14 ,
( int ) V_22 -> V_23 . V_33 , V_22 -> V_23 . V_34 ,
V_22 -> V_23 . V_88 , V_22 -> V_36 , V_22 -> V_89 ,
& V_28 -> V_37 , F_5 ( V_28 -> V_38 ) ,
& V_29 -> V_37 , F_5 ( V_29 -> V_38 ) ) ;
} else {
struct V_39 * V_40 = (struct V_39 * )
& V_22 -> V_23 . V_24 ;
struct V_39 * V_41 = (struct V_39 * )
& V_22 -> V_23 . V_30 ;
V_17 = snprintf ( V_86 -> V_6 + V_86 -> V_12 , V_16 ,
L_28
L_29
L_31 ,
V_22 , V_22 -> V_23 . V_87 , V_22 -> V_23 . V_14 ,
( int ) V_22 -> V_23 . V_33 , V_22 -> V_23 . V_34 ,
V_22 -> V_23 . V_88 , V_22 -> V_36 , V_22 -> V_89 ,
& V_40 -> V_42 , F_5 ( V_40 -> V_43 ) ,
& V_41 -> V_42 , F_5 ( V_41 -> V_43 ) ) ;
}
if ( V_17 < V_16 )
V_86 -> V_12 += V_17 ;
return 0 ;
}
static int F_27 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_90 * V_22 = V_2 ;
struct V_9 * V_86 = V_3 ;
int V_16 ;
int V_17 ;
V_16 = V_86 -> V_21 - V_86 -> V_12 - 1 ;
if ( V_16 == 0 )
return 1 ;
if ( V_22 -> V_23 . V_24 . V_25 == V_26 ) {
struct V_27 * V_28 = (struct V_27 * )
& V_22 -> V_23 . V_24 ;
V_17 = snprintf ( V_86 -> V_6 + V_86 -> V_12 , V_16 ,
L_32
L_33 ,
V_22 , V_22 -> V_23 . V_87 , ( int ) V_22 -> V_23 . V_33 ,
V_22 -> V_23 . V_34 , V_22 -> V_91 , V_22 -> V_92 ,
& V_28 -> V_37 , F_5 ( V_28 -> V_38 ) ) ;
} else {
struct V_39 * V_40 = (struct V_39 * )
& V_22 -> V_23 . V_24 ;
V_17 = snprintf ( V_86 -> V_6 + V_86 -> V_12 , V_16 ,
L_32
L_34 ,
V_22 , V_22 -> V_23 . V_87 , ( int ) V_22 -> V_23 . V_33 ,
V_22 -> V_23 . V_34 , V_22 -> V_91 , V_22 -> V_92 ,
& V_40 -> V_42 , F_5 ( V_40 -> V_43 ) ) ;
}
if ( V_17 < V_16 )
V_86 -> V_12 += V_17 ;
return 0 ;
}
static int F_28 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_86 = V_5 -> V_11 ;
if ( ! V_86 ) {
F_29 ( L_6 , V_46 ) ;
return 0 ;
}
F_8 ( V_86 -> V_6 ) ;
F_9 ( V_86 ) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_9 * V_86 ;
int V_47 = 0 ;
int V_7 = 1 ;
V_86 = F_11 ( sizeof( * V_86 ) , V_48 ) ;
if ( ! V_86 ) {
V_47 = - V_49 ;
goto V_50;
}
V_86 -> V_51 = V_44 -> V_52 ;
V_86 -> V_12 = 0 ;
F_12 ( & V_86 -> V_51 -> V_53 ) ;
F_13 ( & V_86 -> V_51 -> V_93 , F_1 , & V_7 ) ;
F_13 ( & V_86 -> V_51 -> V_94 , F_1 , & V_7 ) ;
F_13 ( & V_86 -> V_51 -> V_95 , F_1 , & V_7 ) ;
F_14 ( & V_86 -> V_51 -> V_53 ) ;
V_86 -> V_21 = V_7 * 160 ;
V_86 -> V_6 = F_15 ( V_86 -> V_21 ) ;
if ( ! V_86 -> V_6 ) {
V_47 = - V_49 ;
goto V_55;
}
F_12 ( & V_86 -> V_51 -> V_53 ) ;
F_13 ( & V_86 -> V_51 -> V_93 , F_26 , V_86 ) ;
F_13 ( & V_86 -> V_51 -> V_94 , F_26 , V_86 ) ;
F_13 ( & V_86 -> V_51 -> V_95 , F_27 , V_86 ) ;
F_14 ( & V_86 -> V_51 -> V_53 ) ;
V_5 -> V_11 = V_86 ;
goto V_50;
V_55:
F_9 ( V_86 ) ;
V_50:
return V_47 ;
}
static int F_31 ( struct V_61 * V_51 )
{
struct V_96 * V_97 ;
if ( ! V_51 -> V_98 )
return - 1 ;
V_97 = F_32 ( L_35 , V_99 , V_51 -> V_98 ,
( void * ) V_51 , & V_100 ) ;
if ( V_97 && V_97 -> V_101 )
V_97 -> V_101 -> V_102 = 4096 ;
V_97 = F_32 ( L_36 , V_99 , V_51 -> V_98 ,
( void * ) V_51 , & V_103 ) ;
if ( V_97 && V_97 -> V_101 )
V_97 -> V_101 -> V_102 = 4096 ;
V_97 = F_32 ( L_37 , V_99 , V_51 -> V_98 ,
( void * ) V_51 , & V_104 ) ;
if ( V_97 && V_97 -> V_101 )
V_97 -> V_101 -> V_102 = 4096 ;
V_97 = F_32 ( L_38 , V_99 , V_51 -> V_98 ,
( void * ) V_51 , & V_105 ) ;
if ( V_97 && V_97 -> V_101 )
V_97 -> V_101 -> V_102 = 4096 ;
return 0 ;
}
void F_33 ( struct V_106 * V_64 ,
struct V_107 * V_108 )
{
struct V_109 * V_12 , * V_110 ;
struct V_111 * V_112 ;
F_24 ( & V_108 -> V_53 ) ;
F_34 (pos, nxt, &uctx->qpids) {
V_112 = F_35 ( V_12 , struct V_111 , V_112 ) ;
F_36 ( & V_112 -> V_112 ) ;
if ( ! ( V_112 -> V_20 & V_64 -> V_113 ) ) {
F_37 ( & V_64 -> V_114 . V_115 ,
V_112 -> V_20 ) ;
F_24 ( & V_64 -> V_65 . V_53 ) ;
V_64 -> V_65 . V_20 . V_68 -= V_64 -> V_113 + 1 ;
F_25 ( & V_64 -> V_65 . V_53 ) ;
}
F_9 ( V_112 ) ;
}
F_34 (pos, nxt, &uctx->qpids) {
V_112 = F_35 ( V_12 , struct V_111 , V_112 ) ;
F_36 ( & V_112 -> V_112 ) ;
F_9 ( V_112 ) ;
}
F_25 ( & V_108 -> V_53 ) ;
}
void F_38 ( struct V_106 * V_64 ,
struct V_107 * V_108 )
{
F_39 ( & V_108 -> V_116 ) ;
F_39 ( & V_108 -> V_117 ) ;
F_40 ( & V_108 -> V_53 ) ;
}
static int F_41 ( struct V_106 * V_64 )
{
int V_118 ;
F_38 ( V_64 , & V_64 -> V_108 ) ;
V_64 -> V_119 = V_120 - F_42 ( V_64 -> V_121 . V_122 ) ;
V_64 -> V_113 = V_64 -> V_121 . V_122 - 1 ;
V_64 -> V_123 = V_120 - F_42 ( V_64 -> V_121 . V_124 ) ;
V_64 -> V_125 = V_64 -> V_121 . V_124 - 1 ;
F_43 ( L_39
L_40
L_41 ,
V_46 , F_44 ( V_64 -> V_121 . V_126 ) , V_64 -> V_121 . V_127 -> V_71 . V_128 ,
V_64 -> V_121 . V_127 -> V_71 . V_129 , F_45 ( V_64 ) ,
V_64 -> V_121 . V_127 -> V_72 . V_128 ,
V_64 -> V_121 . V_127 -> V_72 . V_129 , V_64 -> V_121 . V_127 -> V_31 . V_128 ,
V_64 -> V_121 . V_127 -> V_31 . V_129 ,
V_64 -> V_121 . V_127 -> V_14 . V_128 ,
V_64 -> V_121 . V_127 -> V_14 . V_129 ,
V_64 -> V_121 . V_127 -> V_130 . V_128 ,
V_64 -> V_121 . V_127 -> V_130 . V_129 ) ;
F_43 ( L_42
L_43 ,
( unsigned ) F_46 ( V_64 -> V_121 . V_126 , 2 ) ,
( V_131 ) F_47 ( V_64 -> V_121 . V_126 , 2 ) ,
V_64 -> V_121 . V_132 ,
V_64 -> V_121 . V_133 ,
V_64 -> V_119 , V_64 -> V_113 ,
V_64 -> V_123 , V_64 -> V_125 ) ;
if ( F_45 ( V_64 ) == 0 ) {
V_118 = - V_134 ;
goto V_55;
}
V_64 -> V_65 . V_66 . V_67 = V_135 ;
V_64 -> V_65 . V_71 . V_67 = V_64 -> V_121 . V_127 -> V_71 . V_129 ;
V_64 -> V_65 . V_72 . V_67 = V_64 -> V_121 . V_127 -> V_72 . V_129 ;
V_64 -> V_65 . V_73 . V_67 = V_64 -> V_121 . V_127 -> V_31 . V_129 ;
V_64 -> V_65 . V_74 . V_67 = V_64 -> V_121 . V_127 -> V_136 . V_129 ;
V_64 -> V_65 . V_20 . V_67 = V_64 -> V_121 . V_127 -> V_14 . V_129 ;
V_118 = F_48 ( V_64 , F_45 ( V_64 ) , V_135 ) ;
if ( V_118 ) {
F_7 (KERN_ERR MOD L_44 , err) ;
goto V_55;
}
V_118 = F_49 ( V_64 ) ;
if ( V_118 ) {
F_7 (KERN_ERR MOD L_45 , err) ;
goto V_137;
}
V_118 = F_50 ( V_64 ) ;
if ( V_118 ) {
F_7 (KERN_ERR MOD L_46 , err) ;
goto V_138;
}
V_118 = F_51 ( V_64 ) ;
if ( V_118 ) {
F_7 (KERN_ERR MOD L_47 , err) ;
goto V_139;
}
V_64 -> V_140 = (struct V_141 * )
F_52 ( V_48 ) ;
if ( ! V_64 -> V_140 ) {
F_53 ( V_142 L_48 ) ;
goto V_139;
}
return 0 ;
V_139:
F_54 ( V_64 ) ;
V_138:
F_55 ( V_64 ) ;
V_137:
F_56 ( & V_64 -> V_114 ) ;
V_55:
return V_118 ;
}
static void F_57 ( struct V_106 * V_64 )
{
F_58 ( ( unsigned long ) V_64 -> V_140 ) ;
F_55 ( V_64 ) ;
F_54 ( V_64 ) ;
F_56 ( & V_64 -> V_114 ) ;
}
static void F_59 ( struct V_143 * V_144 )
{
F_57 ( & V_144 -> V_62 -> V_64 ) ;
F_60 ( & V_144 -> V_62 -> V_145 ) ;
F_60 ( & V_144 -> V_62 -> V_54 ) ;
F_60 ( & V_144 -> V_62 -> V_57 ) ;
F_60 ( & V_144 -> V_62 -> V_93 ) ;
F_60 ( & V_144 -> V_62 -> V_95 ) ;
F_60 ( & V_144 -> V_62 -> V_94 ) ;
if ( V_144 -> V_62 -> V_64 . V_146 )
F_61 ( V_144 -> V_62 -> V_64 . V_146 ) ;
if ( V_144 -> V_62 -> V_64 . V_147 )
F_61 ( V_144 -> V_62 -> V_64 . V_147 ) ;
F_62 ( & V_144 -> V_62 -> V_148 ) ;
V_144 -> V_62 = NULL ;
}
static void F_63 ( struct V_143 * V_144 )
{
F_43 ( L_49 , V_46 , V_144 -> V_62 ) ;
F_64 ( V_144 -> V_62 ) ;
F_59 ( V_144 ) ;
}
static int F_65 ( const struct V_149 * V_150 )
{
return V_150 -> V_127 -> V_71 . V_129 > 0 && V_150 -> V_127 -> V_72 . V_129 > 0 &&
V_150 -> V_127 -> V_31 . V_129 > 0 && V_150 -> V_127 -> V_14 . V_129 > 0 &&
V_150 -> V_127 -> V_130 . V_129 > 0 ;
}
static struct V_61 * F_66 ( const struct V_149 * V_150 )
{
struct V_61 * V_51 ;
int V_47 ;
if ( ! F_65 ( V_150 ) ) {
F_7 (KERN_INFO MOD L_50 ,
pci_name(infop->pdev)) ;
return F_67 ( - V_151 ) ;
}
if ( ! F_68 ( V_150 ) )
F_29 ( L_51 ,
F_44 ( V_150 -> V_126 ) ) ;
V_51 = (struct V_61 * ) F_69 ( sizeof( * V_51 ) ) ;
if ( ! V_51 ) {
F_7 (KERN_ERR MOD L_52 ) ;
return F_67 ( - V_49 ) ;
}
V_51 -> V_64 . V_121 = * V_150 ;
V_51 -> V_64 . V_152 = F_47 ( V_51 -> V_64 . V_121 . V_126 , 2 ) ;
if ( F_70 ( V_51 -> V_64 . V_121 . V_153 ) ) {
V_51 -> V_64 . V_146 = F_71 ( V_51 -> V_64 . V_152 ,
F_46 ( V_51 -> V_64 . V_121 . V_126 , 2 ) ) ;
if ( ! V_51 -> V_64 . V_146 ) {
F_53 ( V_142 L_53 ) ;
return F_67 ( - V_134 ) ;
}
} else if ( F_68 ( V_150 ) ) {
V_51 -> V_64 . V_154 =
F_47 ( V_51 -> V_64 . V_121 . V_126 , 2 ) +
F_46 ( V_51 -> V_64 . V_121 . V_126 , 2 ) -
F_72 ( V_51 -> V_64 . V_121 . V_127 -> V_136 . V_129 ) ;
V_51 -> V_64 . V_147 = F_71 ( V_51 -> V_64 . V_154 ,
V_51 -> V_64 . V_121 . V_127 -> V_136 . V_129 ) ;
if ( ! V_51 -> V_64 . V_147 ) {
F_53 ( V_142 L_54 ) ;
return F_67 ( - V_134 ) ;
}
}
F_43 (KERN_INFO MOD L_55
L_56 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_47 = F_41 ( & V_51 -> V_64 ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_57 , ret) ;
F_62 ( & V_51 -> V_148 ) ;
return F_67 ( V_47 ) ;
}
F_73 ( & V_51 -> V_145 ) ;
F_73 ( & V_51 -> V_54 ) ;
F_73 ( & V_51 -> V_57 ) ;
F_73 ( & V_51 -> V_93 ) ;
F_73 ( & V_51 -> V_95 ) ;
F_73 ( & V_51 -> V_94 ) ;
F_74 ( & V_51 -> V_53 ) ;
F_40 ( & V_51 -> V_64 . V_65 . V_53 ) ;
F_40 ( & V_51 -> V_155 ) ;
F_39 ( & V_51 -> V_156 ) ;
if ( V_157 ) {
V_51 -> V_98 = F_75 (
F_44 ( V_51 -> V_64 . V_121 . V_126 ) ,
V_157 ) ;
F_31 ( V_51 ) ;
}
return V_51 ;
}
static void * F_76 ( const struct V_149 * V_150 )
{
struct V_143 * V_144 ;
static int V_158 ;
int V_159 ;
if ( ! V_158 ++ )
F_29 ( L_58 ,
V_160 ) ;
V_144 = F_77 ( sizeof *V_144 , V_48 ) ;
if ( ! V_144 ) {
V_144 = F_67 ( - V_49 ) ;
goto V_50;
}
V_144 -> V_121 = * V_150 ;
F_43 ( L_59 ,
V_46 , F_44 ( V_144 -> V_121 . V_126 ) ,
V_144 -> V_121 . V_161 , V_144 -> V_121 . V_162 ,
V_144 -> V_121 . V_163 , V_144 -> V_121 . V_164 ) ;
F_24 ( & V_165 ) ;
F_78 ( & V_144 -> V_112 , & V_166 ) ;
F_25 ( & V_165 ) ;
for ( V_159 = 0 ; V_159 < V_144 -> V_121 . V_162 ; V_159 ++ )
F_43 ( L_60 , V_159 , V_144 -> V_121 . V_167 [ V_159 ] ) ;
V_50:
return V_144 ;
}
static inline struct V_168 * F_79 ( const struct V_169 * V_170 ,
const T_5 * V_171 ,
T_6 V_172 )
{
struct V_168 * V_173 ;
V_173 = F_80 ( V_170 -> V_174 + sizeof( struct V_175 ) +
sizeof( struct V_176 ) - V_172 , V_177 ) ;
if ( F_81 ( ! V_173 ) )
return NULL ;
F_82 ( V_173 , V_170 -> V_174 + sizeof( struct V_175 ) +
sizeof( struct V_176 ) - V_172 ) ;
F_83 ( V_173 , V_171 , sizeof( struct V_175 ) +
sizeof( struct V_176 ) ) ;
F_84 ( V_173 , sizeof( struct V_176 ) +
sizeof( struct V_175 ) ,
V_170 -> V_178 + V_172 ,
V_170 -> V_174 - V_172 ) ;
return V_173 ;
}
static inline int F_85 ( struct V_61 * V_62 , const struct V_169 * V_170 ,
const T_5 * V_171 )
{
unsigned int V_179 = * ( V_180 * ) V_171 ;
struct V_168 * V_173 ;
if ( V_179 != V_181 )
goto V_50;
V_173 = F_79 ( V_170 , V_171 , V_62 -> V_64 . V_121 . V_182 ) ;
if ( V_173 == NULL )
goto V_50;
if ( V_183 [ V_179 ] == NULL ) {
F_29 ( L_61 , V_46 ,
V_179 ) ;
F_86 ( V_173 ) ;
goto V_50;
}
V_183 [ V_179 ] ( V_62 , V_173 ) ;
return 1 ;
V_50:
return 0 ;
}
static int F_87 ( void * V_184 , const T_5 * V_171 ,
const struct V_169 * V_170 )
{
struct V_143 * V_144 = V_184 ;
struct V_61 * V_62 = V_144 -> V_62 ;
struct V_168 * V_173 ;
V_180 V_179 ;
if ( V_170 == NULL ) {
unsigned int V_185 = 64 - sizeof( struct V_186 ) - 8 ;
V_173 = F_80 ( 256 , V_177 ) ;
if ( ! V_173 )
goto V_187;
F_82 ( V_173 , V_185 ) ;
F_83 ( V_173 , & V_171 [ 1 ] , V_185 ) ;
} else if ( V_170 == V_188 ) {
const struct V_186 * V_189 = ( void * ) V_171 ;
T_6 V_20 = F_88 ( V_189 -> V_190 ) ;
F_89 ( V_62 , V_20 ) ;
return 0 ;
} else if ( F_81 ( * ( V_180 * ) V_171 != * ( V_180 * ) V_170 -> V_178 ) ) {
if ( F_85 ( V_62 , V_170 , V_171 ) )
return 0 ;
F_29 ( L_62 \
L_63 ,
F_44 ( V_144 -> V_121 . V_126 ) , V_170 -> V_178 ,
( unsigned long long ) F_90 ( * V_171 ) ,
( unsigned long long ) F_90 (
* ( V_191 T_5 * ) V_170 -> V_178 ) ,
V_170 -> V_174 ) ;
return 0 ;
} else {
V_173 = F_91 ( V_170 , 128 , 128 ) ;
if ( F_81 ( ! V_173 ) )
goto V_187;
}
V_179 = * ( V_180 * ) V_171 ;
if ( V_183 [ V_179 ] ) {
V_183 [ V_179 ] ( V_62 , V_173 ) ;
} else {
F_29 ( L_61 , V_46 ,
V_179 ) ;
F_86 ( V_173 ) ;
}
return 0 ;
V_187:
return - 1 ;
}
static int F_92 ( void * V_184 , enum V_192 V_193 )
{
struct V_143 * V_144 = V_184 ;
F_43 ( L_64 , V_46 , V_193 ) ;
switch ( V_193 ) {
case V_194 :
F_7 (KERN_INFO MOD L_65 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_144 -> V_62 ) {
int V_47 ;
V_144 -> V_62 = F_66 ( & V_144 -> V_121 ) ;
if ( F_93 ( V_144 -> V_62 ) ) {
F_7 (KERN_ERR MOD
L_66 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_144 -> V_62 = NULL ;
break;
}
V_47 = F_94 ( V_144 -> V_62 ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD
L_67 ,
pci_name(ctx->lldi.pdev), ret) ;
F_59 ( V_144 ) ;
}
}
break;
case V_195 :
F_7 (KERN_INFO MOD L_68 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_144 -> V_62 )
F_63 ( V_144 ) ;
break;
case V_196 :
F_7 (KERN_INFO MOD L_69 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_144 -> V_62 ) {
struct V_197 V_198 ;
V_144 -> V_62 -> V_64 . V_34 |= V_199 ;
memset ( & V_198 , 0 , sizeof V_198 ) ;
V_198 . V_198 = V_200 ;
V_198 . V_201 = & V_144 -> V_62 -> V_148 ;
F_95 ( & V_198 ) ;
F_63 ( V_144 ) ;
}
break;
case V_202 :
F_7 (KERN_INFO MOD L_70 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_144 -> V_62 )
F_63 ( V_144 ) ;
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
static void F_98 ( struct V_143 * V_144 )
{
unsigned long V_34 ;
F_99 ( & V_144 -> V_62 -> V_53 , V_34 ) ;
V_144 -> V_62 -> V_64 . V_65 . V_80 ++ ;
V_144 -> V_62 -> V_79 = V_203 ;
if ( V_144 -> V_62 -> V_64 . V_34 & V_204 )
F_13 ( & V_144 -> V_62 -> V_54 , F_96 , NULL ) ;
else
V_144 -> V_62 -> V_64 . V_140 -> V_205 = 1 ;
F_100 ( & V_144 -> V_62 -> V_53 , V_34 ) ;
}
static int F_101 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_13 * V_14 = V_2 ;
F_102 ( & V_14 -> V_18 ) ;
return 0 ;
}
static void F_103 ( struct V_13 * V_14 )
{
F_104 ( & V_14 -> V_53 ) ;
F_105 ( & V_14 -> V_18 , V_14 -> V_18 . V_19 . V_206 ,
F_70 ( V_14 -> V_207 -> V_64 . V_121 . V_153 ) , NULL ) ;
V_14 -> V_18 . V_19 . V_206 = 0 ;
F_106 ( & V_14 -> V_18 , V_14 -> V_18 . V_31 . V_206 ,
F_70 ( V_14 -> V_207 -> V_64 . V_121 . V_153 ) , NULL ) ;
V_14 -> V_18 . V_31 . V_206 = 0 ;
F_107 ( & V_14 -> V_53 ) ;
}
static void F_108 ( struct V_143 * V_144 )
{
int V_159 ;
struct V_13 * V_14 ;
for ( V_159 = 0 ; V_159 < V_208 ; V_159 ++ ) {
V_14 = F_109 ( & V_144 -> V_62 -> V_156 , struct V_13 ,
V_209 ) ;
F_36 ( & V_14 -> V_209 ) ;
F_103 ( V_14 ) ;
if ( F_110 ( & V_144 -> V_62 -> V_156 ) )
break;
}
}
static void F_111 ( struct V_143 * V_144 )
{
F_12 ( & V_144 -> V_62 -> V_53 ) ;
if ( V_144 -> V_62 -> V_79 != V_203 )
goto V_50;
V_144 -> V_62 -> V_79 = V_210 ;
while ( 1 ) {
if ( F_110 ( & V_144 -> V_62 -> V_156 ) ) {
F_112 ( V_144 -> V_62 -> V_79 != V_210 ) ;
V_144 -> V_62 -> V_79 = V_211 ;
V_144 -> V_62 -> V_64 . V_65 . V_80 ++ ;
if ( V_144 -> V_62 -> V_64 . V_34 & V_204 ) {
F_13 ( & V_144 -> V_62 -> V_54 , F_101 ,
NULL ) ;
} else {
V_144 -> V_62 -> V_64 . V_140 -> V_205 = 0 ;
}
break;
} else {
if ( F_113 ( V_144 -> V_62 -> V_64 . V_121 . V_212 [ 0 ] , 1 )
< ( V_144 -> V_62 -> V_64 . V_121 . V_213 <<
V_214 ) ) {
F_108 ( V_144 ) ;
}
if ( ! F_110 ( & V_144 -> V_62 -> V_156 ) ) {
F_14 ( & V_144 -> V_62 -> V_53 ) ;
if ( V_215 ) {
F_114 ( V_216 ) ;
F_115 ( V_215 ) ;
}
F_12 ( & V_144 -> V_62 -> V_53 ) ;
if ( V_144 -> V_62 -> V_79 != V_210 )
break;
}
}
}
V_50:
if ( V_144 -> V_62 -> V_79 != V_211 )
V_144 -> V_62 -> V_64 . V_65 . V_81 ++ ;
F_14 ( & V_144 -> V_62 -> V_53 ) ;
}
static int F_116 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_217 * V_218 = V_3 ;
struct V_13 * V_14 = V_2 ;
F_117 ( & V_14 -> V_219 ) ;
V_218 -> V_220 [ V_218 -> V_221 ++ ] = V_14 ;
return 0 ;
}
static int F_118 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_119 ( struct V_217 * V_217 )
{
int V_221 ;
for ( V_221 = 0 ; V_221 < V_217 -> V_221 ; V_221 ++ )
F_120 ( & V_217 -> V_220 [ V_221 ] -> V_219 ) ;
}
static void F_121 ( struct V_143 * V_144 , struct V_217 * V_217 )
{
int V_221 ;
int V_47 ;
for ( V_221 = 0 ; V_221 < V_217 -> V_221 ; V_221 ++ ) {
struct V_13 * V_14 = V_217 -> V_220 [ V_221 ] ;
F_12 ( & V_14 -> V_207 -> V_53 ) ;
F_104 ( & V_14 -> V_53 ) ;
V_47 = F_122 ( V_14 -> V_207 -> V_64 . V_121 . V_212 [ 0 ] ,
V_14 -> V_18 . V_19 . V_20 ,
F_123 ( & V_14 -> V_18 ) ,
F_124 ( & V_14 -> V_18 ) ) ;
if ( V_47 ) {
F_53 (KERN_ERR MOD L_71
L_72
L_73 ,
pci_name(ctx->lldi.pdev), qp->wq.sq.qid) ;
F_107 ( & V_14 -> V_53 ) ;
F_14 ( & V_14 -> V_207 -> V_53 ) ;
return;
}
V_14 -> V_18 . V_19 . V_206 = 0 ;
V_47 = F_122 ( V_14 -> V_207 -> V_64 . V_121 . V_212 [ 0 ] ,
V_14 -> V_18 . V_31 . V_20 ,
F_125 ( & V_14 -> V_18 ) ,
F_126 ( & V_14 -> V_18 ) ) ;
if ( V_47 ) {
F_53 (KERN_ERR MOD L_71
L_72
L_74 ,
pci_name(ctx->lldi.pdev), qp->wq.rq.qid) ;
F_107 ( & V_14 -> V_53 ) ;
F_14 ( & V_14 -> V_207 -> V_53 ) ;
return;
}
V_14 -> V_18 . V_31 . V_206 = 0 ;
F_107 ( & V_14 -> V_53 ) ;
F_14 ( & V_14 -> V_207 -> V_53 ) ;
while ( F_113 ( V_14 -> V_207 -> V_64 . V_121 . V_212 [ 0 ] , 1 ) > 0 ) {
F_114 ( V_216 ) ;
F_115 ( F_127 ( 10 ) ) ;
}
}
}
static void F_128 ( struct V_143 * V_144 )
{
int V_7 = 0 ;
struct V_217 V_217 ;
int V_47 ;
F_114 ( V_216 ) ;
F_115 ( F_127 ( 1000 ) ) ;
V_47 = F_129 ( V_144 -> V_62 -> V_64 . V_121 . V_212 [ 0 ] ) ;
if ( V_47 ) {
F_7 (KERN_ERR MOD L_75 ,
pci_name(ctx->lldi.pdev)) ;
return;
}
F_12 ( & V_144 -> V_62 -> V_53 ) ;
F_112 ( V_144 -> V_62 -> V_79 != V_203 ) ;
V_144 -> V_62 -> V_79 = V_222 ;
F_13 ( & V_144 -> V_62 -> V_54 , F_118 , & V_7 ) ;
V_217 . V_220 = F_77 ( V_7 * sizeof * V_217 . V_220 , V_177 ) ;
if ( ! V_217 . V_220 ) {
F_7 (KERN_ERR MOD L_75 ,
pci_name(ctx->lldi.pdev)) ;
F_14 ( & V_144 -> V_62 -> V_53 ) ;
return;
}
V_217 . V_221 = 0 ;
F_13 ( & V_144 -> V_62 -> V_54 , F_116 , & V_217 ) ;
F_14 ( & V_144 -> V_62 -> V_53 ) ;
F_121 ( V_144 , & V_217 ) ;
F_119 ( & V_217 ) ;
F_9 ( V_217 . V_220 ) ;
F_12 ( & V_144 -> V_62 -> V_53 ) ;
F_112 ( V_144 -> V_62 -> V_79 != V_222 ) ;
V_144 -> V_62 -> V_79 = V_203 ;
F_14 ( & V_144 -> V_62 -> V_53 ) ;
}
static int F_130 ( void * V_184 , enum V_223 V_224 , ... )
{
struct V_143 * V_144 = V_184 ;
switch ( V_224 ) {
case V_225 :
F_98 ( V_144 ) ;
V_144 -> V_62 -> V_64 . V_65 . V_75 ++ ;
break;
case V_226 :
F_111 ( V_144 ) ;
F_24 ( & V_144 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_144 -> V_62 -> V_64 . V_65 . V_76 ++ ;
F_25 ( & V_144 -> V_62 -> V_64 . V_65 . V_53 ) ;
break;
case V_227 :
F_128 ( V_144 ) ;
F_24 ( & V_144 -> V_62 -> V_64 . V_65 . V_53 ) ;
V_144 -> V_62 -> V_64 . V_65 . V_77 ++ ;
F_25 ( & V_144 -> V_62 -> V_64 . V_65 . V_53 ) ;
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
int V_118 ;
V_118 = F_132 () ;
if ( V_118 )
return V_118 ;
V_157 = F_75 ( V_228 , NULL ) ;
if ( ! V_157 )
F_7 (KERN_WARNING MOD
L_77 ) ;
F_133 ( V_229 , & V_230 ) ;
return 0 ;
}
static void T_8 F_134 ( void )
{
struct V_143 * V_144 , * V_231 ;
F_24 ( & V_165 ) ;
F_135 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_144 -> V_62 )
F_63 ( V_144 ) ;
F_9 ( V_144 ) ;
}
F_25 ( & V_165 ) ;
F_136 ( V_229 ) ;
F_137 () ;
F_138 ( V_157 ) ;
}
