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
void F_4 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_17 V_18 ;
int V_19 ;
if ( ! V_14 -> V_20 -> V_21 )
return;
V_19 = ( F_5 ( & V_14 -> V_20 -> V_22 ) - 1 ) &
( V_14 -> V_20 -> V_23 - 1 ) ;
V_18 . V_24 = F_6 ( V_14 -> V_20 -> V_25 . V_26 [ 0 ] ) ;
F_7 ( & V_18 . V_27 ) ;
V_18 . V_28 = 1 ;
V_18 . V_29 = F_8 ( V_16 ) ;
if ( F_9 ( V_16 ) ) {
V_18 . V_30 = V_14 -> V_31 . V_30 ;
V_18 . V_32 = F_10 ( V_16 ) ;
V_18 . V_33 = V_14 -> V_31 . V_34 [ V_14 -> V_31 . V_35 ] . V_36 ;
V_18 . V_37 = V_14 -> V_31 . V_34 [ V_14 -> V_31 . V_35 ] . V_38 ;
V_18 . V_39 = F_11 ( V_16 ) ;
} else {
V_18 . V_30 = V_14 -> V_40 . V_30 ;
V_18 . V_32 = V_41 ;
V_18 . V_33 = V_14 -> V_40 . V_42 [ V_14 -> V_40 . V_35 ] . V_36 ;
V_18 . V_37 = V_14 -> V_40 . V_42 [ V_14 -> V_40 . V_35 ] . V_38 ;
V_18 . V_39 = F_12 ( V_16 ) ;
}
V_14 -> V_20 -> V_21 [ V_19 ] = V_18 ;
}
static int F_13 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
struct V_49 V_50 = { 0 , 0 } ;
struct V_17 * V_51 ;
int V_52 = 0 ;
int V_19 , V_53 ;
#define F_14 ( T_5 ) div64_u64((ts) * dev->rdev.lldi.cclk_ps, 1000)
V_19 = F_15 ( & V_47 -> V_20 . V_22 ) &
( V_47 -> V_20 . V_23 - 1 ) ;
V_53 = V_19 - 1 ;
if ( V_53 < 0 )
V_53 = V_47 -> V_20 . V_23 - 1 ;
V_51 = & V_47 -> V_20 . V_21 [ V_19 ] ;
while ( V_19 != V_53 ) {
if ( V_51 -> V_28 ) {
if ( ! V_52 ) {
V_52 = 1 ;
V_50 = V_51 -> V_27 ;
}
F_16 ( V_44 , L_1
L_2
L_3
L_4
L_5 ,
V_19 ,
F_17 ( V_51 -> V_27 ,
V_50 ) . V_54 ,
F_17 ( V_51 -> V_27 ,
V_50 ) . V_55 ,
V_51 -> V_30 , V_51 -> V_32 ,
V_51 -> V_32 == V_41 ?
L_6 : L_7 ,
V_51 -> V_39 ,
F_17 ( V_51 -> V_27 ,
V_51 -> V_33 ) . V_54 ,
F_17 ( V_51 -> V_27 ,
V_51 -> V_33 ) . V_55 ,
V_51 -> V_37 , V_51 -> V_29 ,
V_51 -> V_24 ,
F_14 ( V_51 -> V_24 - V_51 -> V_37 ) ,
F_14 ( V_51 -> V_24 - V_51 -> V_29 ) ) ;
V_50 = V_51 -> V_27 ;
}
V_19 ++ ;
if ( V_19 > ( V_47 -> V_20 . V_23 - 1 ) )
V_19 = 0 ;
V_51 = & V_47 -> V_20 . V_21 [ V_19 ] ;
}
#undef F_14
return 0 ;
}
static int F_18 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
return F_19 ( V_5 , F_13 , V_56 -> V_57 ) ;
}
static T_1 F_20 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_12 )
{
struct V_46 * V_47 = ( (struct V_43 * ) V_5 -> V_11 ) -> V_48 ;
int V_58 ;
if ( V_47 -> V_20 . V_21 )
for ( V_58 = 0 ; V_58 < V_47 -> V_20 . V_23 ; V_58 ++ )
V_47 -> V_20 . V_21 [ V_58 ] . V_28 = 0 ;
return V_7 ;
}
static int F_21 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_59 * V_60 = V_2 ;
struct V_9 * V_61 = V_3 ;
int V_62 ;
int V_63 ;
if ( V_1 != V_60 -> V_14 . V_31 . V_30 )
return 0 ;
V_62 = V_61 -> V_64 - V_61 -> V_12 - 1 ;
if ( V_62 == 0 )
return 1 ;
if ( V_60 -> V_65 ) {
if ( V_60 -> V_65 -> V_66 . V_67 . V_68 == V_69 ) {
struct V_70 * V_71 = (struct V_70 * )
& V_60 -> V_65 -> V_66 . V_67 ;
struct V_70 * V_72 = (struct V_70 * )
& V_60 -> V_65 -> V_66 . V_73 ;
struct V_70 * V_74 = (struct V_70 * )
& V_60 -> V_65 -> V_66 . V_75 ;
struct V_70 * V_76 = (struct V_70 * )
& V_60 -> V_65 -> V_66 . V_77 ;
V_63 = snprintf ( V_61 -> V_6 + V_61 -> V_12 , V_62 ,
L_8
L_9
L_10 ,
V_60 -> V_14 . V_31 . V_30 , V_60 -> V_14 . V_40 . V_30 ,
( int ) V_60 -> V_78 . V_79 ,
V_60 -> V_14 . V_31 . V_80 & V_81 ,
V_60 -> V_65 -> V_82 , ( int ) V_60 -> V_65 -> V_66 . V_79 ,
& V_71 -> V_83 , F_22 ( V_71 -> V_84 ) ,
F_22 ( V_74 -> V_84 ) ,
& V_72 -> V_83 , F_22 ( V_72 -> V_84 ) ,
F_22 ( V_76 -> V_84 ) ) ;
} else {
struct V_85 * V_86 = (struct V_85 * )
& V_60 -> V_65 -> V_66 . V_67 ;
struct V_85 * V_87 = (struct V_85 * )
& V_60 -> V_65 -> V_66 . V_73 ;
struct V_85 * V_88 =
(struct V_85 * )
& V_60 -> V_65 -> V_66 . V_75 ;
struct V_85 * V_89 =
(struct V_85 * )
& V_60 -> V_65 -> V_66 . V_77 ;
V_63 = snprintf ( V_61 -> V_6 + V_61 -> V_12 , V_62 ,
L_8
L_9
L_11 ,
V_60 -> V_14 . V_31 . V_30 , V_60 -> V_14 . V_40 . V_30 ,
( int ) V_60 -> V_78 . V_79 ,
V_60 -> V_14 . V_31 . V_80 & V_81 ,
V_60 -> V_65 -> V_82 , ( int ) V_60 -> V_65 -> V_66 . V_79 ,
& V_86 -> V_90 ,
F_22 ( V_86 -> V_91 ) ,
F_22 ( V_88 -> V_91 ) ,
& V_87 -> V_90 ,
F_22 ( V_87 -> V_91 ) ,
F_22 ( V_89 -> V_91 ) ) ;
}
} else
V_63 = snprintf ( V_61 -> V_6 + V_61 -> V_12 , V_62 ,
L_12 ,
V_60 -> V_14 . V_31 . V_30 , V_60 -> V_14 . V_40 . V_30 ,
( int ) V_60 -> V_78 . V_79 ,
V_60 -> V_14 . V_31 . V_80 & V_81 ) ;
if ( V_63 < V_62 )
V_61 -> V_12 += V_63 ;
return 0 ;
}
static int F_23 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
struct V_9 * V_61 = V_5 -> V_11 ;
if ( ! V_61 ) {
F_24 ( V_92 L_13 , V_93 ) ;
return 0 ;
}
F_25 ( V_61 -> V_6 ) ;
F_26 ( V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
struct V_9 * V_61 ;
int V_7 = 1 ;
V_61 = F_28 ( sizeof *V_61 , V_94 ) ;
if ( ! V_61 )
return - V_95 ;
V_61 -> V_96 = V_56 -> V_57 ;
V_61 -> V_12 = 0 ;
F_29 ( & V_61 -> V_96 -> V_97 ) ;
F_30 ( & V_61 -> V_96 -> V_98 , F_1 , & V_7 ) ;
F_31 ( & V_61 -> V_96 -> V_97 ) ;
V_61 -> V_64 = V_7 * 128 ;
V_61 -> V_6 = F_32 ( V_61 -> V_64 ) ;
if ( ! V_61 -> V_6 ) {
F_26 ( V_61 ) ;
return - V_95 ;
}
F_29 ( & V_61 -> V_96 -> V_97 ) ;
F_30 ( & V_61 -> V_96 -> V_98 , F_21 , V_61 ) ;
F_31 ( & V_61 -> V_96 -> V_97 ) ;
V_61 -> V_6 [ V_61 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_61 ;
return 0 ;
}
static int F_33 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_9 * V_99 = V_3 ;
int V_62 ;
int V_63 ;
struct V_100 V_101 ;
int V_102 ;
V_62 = V_99 -> V_64 - V_99 -> V_12 - 1 ;
if ( V_62 == 0 )
return 1 ;
V_102 = F_34 ( V_99 -> V_96 -> V_20 . V_25 . V_26 [ 0 ] , ( V_103 ) V_1 << 8 ,
( V_104 * ) & V_101 ) ;
if ( V_102 ) {
F_35 ( & V_99 -> V_96 -> V_20 . V_25 . V_105 -> V_47 ,
L_14 , V_93 , V_102 ) ;
return V_102 ;
}
V_63 = snprintf ( V_99 -> V_6 + V_99 -> V_12 , V_62 ,
L_15
L_16 ,
( V_103 ) V_1 << 8 ,
F_36 ( F_37 ( V_101 . V_106 ) ) ,
F_38 ( F_37 ( V_101 . V_106 ) ) ,
F_39 ( F_37 ( V_101 . V_106 ) ) ,
F_40 ( F_37 ( V_101 . V_106 ) ) ,
F_41 ( F_37 ( V_101 . V_107 ) ) ,
F_42 ( F_37 ( V_101 . V_107 ) ) ,
( ( V_108 ) F_37 ( V_101 . V_109 ) << 32 ) | F_37 ( V_101 . V_110 ) ,
( ( V_108 ) F_37 ( V_101 . V_111 ) << 32 ) | F_37 ( V_101 . V_112 ) ) ;
if ( V_63 < V_62 )
V_99 -> V_12 += V_63 ;
return 0 ;
}
static int F_43 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
struct V_9 * V_99 = V_5 -> V_11 ;
if ( ! V_99 ) {
F_24 ( V_92 L_17 , V_93 ) ;
return 0 ;
}
F_25 ( V_99 -> V_6 ) ;
F_26 ( V_99 ) ;
return 0 ;
}
static int F_44 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
struct V_9 * V_99 ;
int V_102 = 0 ;
int V_7 = 1 ;
V_99 = F_28 ( sizeof *V_99 , V_94 ) ;
if ( ! V_99 ) {
V_102 = - V_95 ;
goto V_113;
}
V_99 -> V_96 = V_56 -> V_57 ;
V_99 -> V_12 = 0 ;
F_29 ( & V_99 -> V_96 -> V_97 ) ;
F_30 ( & V_99 -> V_96 -> V_114 , F_1 , & V_7 ) ;
F_31 ( & V_99 -> V_96 -> V_97 ) ;
V_99 -> V_64 = V_7 * 256 ;
V_99 -> V_6 = F_32 ( V_99 -> V_64 ) ;
if ( ! V_99 -> V_6 ) {
V_102 = - V_95 ;
goto V_115;
}
F_29 ( & V_99 -> V_96 -> V_97 ) ;
F_30 ( & V_99 -> V_96 -> V_114 , F_33 , V_99 ) ;
F_31 ( & V_99 -> V_96 -> V_97 ) ;
V_99 -> V_6 [ V_99 -> V_12 ++ ] = 0 ;
V_5 -> V_11 = V_99 ;
goto V_113;
V_115:
F_26 ( V_99 ) ;
V_113:
return V_102 ;
}
static int F_45 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
F_16 ( V_44 , L_18 , L_19 , L_20 ,
L_21 , L_22 ) ;
F_16 ( V_44 , L_23 ,
V_47 -> V_20 . V_116 . V_117 . V_118 , V_47 -> V_20 . V_116 . V_117 . V_119 ,
V_47 -> V_20 . V_116 . V_117 . V_120 , V_47 -> V_20 . V_116 . V_117 . V_121 ) ;
F_16 ( V_44 , L_24 ,
V_47 -> V_20 . V_116 . V_30 . V_118 , V_47 -> V_20 . V_116 . V_30 . V_119 ,
V_47 -> V_20 . V_116 . V_30 . V_120 , V_47 -> V_20 . V_116 . V_30 . V_121 ) ;
F_16 ( V_44 , L_25 ,
V_47 -> V_20 . V_116 . V_122 . V_118 , V_47 -> V_20 . V_116 . V_122 . V_119 ,
V_47 -> V_20 . V_116 . V_122 . V_120 , V_47 -> V_20 . V_116 . V_122 . V_121 ) ;
F_16 ( V_44 , L_26 ,
V_47 -> V_20 . V_116 . V_123 . V_118 , V_47 -> V_20 . V_116 . V_123 . V_119 ,
V_47 -> V_20 . V_116 . V_123 . V_120 , V_47 -> V_20 . V_116 . V_123 . V_121 ) ;
F_16 ( V_44 , L_27 ,
V_47 -> V_20 . V_116 . V_124 . V_118 , V_47 -> V_20 . V_116 . V_124 . V_119 ,
V_47 -> V_20 . V_116 . V_124 . V_120 , V_47 -> V_20 . V_116 . V_124 . V_121 ) ;
F_16 ( V_44 , L_28 ,
V_47 -> V_20 . V_116 . V_125 . V_118 , V_47 -> V_20 . V_116 . V_125 . V_119 ,
V_47 -> V_20 . V_116 . V_125 . V_120 , V_47 -> V_20 . V_116 . V_125 . V_121 ) ;
F_16 ( V_44 , L_29 , V_47 -> V_20 . V_116 . V_126 ) ;
F_16 ( V_44 , L_30 , V_47 -> V_20 . V_116 . V_127 ) ;
F_16 ( V_44 , L_31 , V_47 -> V_20 . V_116 . V_128 ) ;
F_16 ( V_44 , L_32 ,
V_129 [ V_47 -> V_130 ] ,
V_47 -> V_20 . V_116 . V_131 ,
V_47 -> V_20 . V_116 . V_132 ) ;
F_16 ( V_44 , L_33 , V_47 -> V_20 . V_116 . V_133 ) ;
F_16 ( V_44 , L_34 ,
V_47 -> V_20 . V_116 . V_134 ) ;
F_16 ( V_44 , L_35 ,
V_47 -> V_20 . V_116 . V_135 ) ;
F_16 ( V_44 , L_36 , V_47 -> V_20 . V_116 . V_136 ) ;
F_16 ( V_44 , L_37 , V_47 -> V_137 ) ;
return 0 ;
}
static int F_46 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
return F_19 ( V_5 , F_45 , V_56 -> V_57 ) ;
}
static T_1 F_47 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_12 )
{
struct V_46 * V_47 = ( (struct V_43 * ) V_5 -> V_11 ) -> V_48 ;
F_48 ( & V_47 -> V_20 . V_116 . V_97 ) ;
V_47 -> V_20 . V_116 . V_117 . V_120 = 0 ;
V_47 -> V_20 . V_116 . V_117 . V_121 = 0 ;
V_47 -> V_20 . V_116 . V_30 . V_120 = 0 ;
V_47 -> V_20 . V_116 . V_30 . V_121 = 0 ;
V_47 -> V_20 . V_116 . V_122 . V_120 = 0 ;
V_47 -> V_20 . V_116 . V_122 . V_121 = 0 ;
V_47 -> V_20 . V_116 . V_123 . V_120 = 0 ;
V_47 -> V_20 . V_116 . V_123 . V_121 = 0 ;
V_47 -> V_20 . V_116 . V_124 . V_120 = 0 ;
V_47 -> V_20 . V_116 . V_124 . V_121 = 0 ;
V_47 -> V_20 . V_116 . V_125 . V_120 = 0 ;
V_47 -> V_20 . V_116 . V_125 . V_121 = 0 ;
V_47 -> V_20 . V_116 . V_126 = 0 ;
V_47 -> V_20 . V_116 . V_127 = 0 ;
V_47 -> V_20 . V_116 . V_128 = 0 ;
V_47 -> V_20 . V_116 . V_131 = 0 ;
V_47 -> V_20 . V_116 . V_133 = 0 ;
V_47 -> V_20 . V_116 . V_134 = 0 ;
V_47 -> V_20 . V_116 . V_135 = 0 ;
F_49 ( & V_47 -> V_20 . V_116 . V_97 ) ;
return V_7 ;
}
static int F_50 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_138 * V_65 = V_2 ;
struct V_9 * V_139 = V_3 ;
int V_62 ;
int V_63 ;
V_62 = V_139 -> V_64 - V_139 -> V_12 - 1 ;
if ( V_62 == 0 )
return 1 ;
if ( V_65 -> V_66 . V_67 . V_68 == V_69 ) {
struct V_70 * V_71 = (struct V_70 * )
& V_65 -> V_66 . V_67 ;
struct V_70 * V_72 = (struct V_70 * )
& V_65 -> V_66 . V_73 ;
struct V_70 * V_74 = (struct V_70 * )
& V_65 -> V_66 . V_75 ;
struct V_70 * V_76 = (struct V_70 * )
& V_65 -> V_66 . V_77 ;
V_63 = snprintf ( V_139 -> V_6 + V_139 -> V_12 , V_62 ,
L_38
L_39
L_40
L_41 ,
V_65 , V_65 -> V_66 . V_140 , V_65 -> V_66 . V_60 ,
( int ) V_65 -> V_66 . V_79 , V_65 -> V_66 . V_80 ,
V_65 -> V_66 . V_141 , V_65 -> V_82 , V_65 -> V_142 ,
V_65 -> V_116 . V_143 ,
V_65 -> V_116 . V_144 ,
& V_71 -> V_83 , F_22 ( V_71 -> V_84 ) ,
F_22 ( V_74 -> V_84 ) ,
& V_72 -> V_83 , F_22 ( V_72 -> V_84 ) ,
F_22 ( V_76 -> V_84 ) ) ;
} else {
struct V_85 * V_86 = (struct V_85 * )
& V_65 -> V_66 . V_67 ;
struct V_85 * V_87 = (struct V_85 * )
& V_65 -> V_66 . V_73 ;
struct V_85 * V_88 = (struct V_85 * )
& V_65 -> V_66 . V_75 ;
struct V_85 * V_89 = (struct V_85 * )
& V_65 -> V_66 . V_77 ;
V_63 = snprintf ( V_139 -> V_6 + V_139 -> V_12 , V_62 ,
L_38
L_39
L_40
L_42 ,
V_65 , V_65 -> V_66 . V_140 , V_65 -> V_66 . V_60 ,
( int ) V_65 -> V_66 . V_79 , V_65 -> V_66 . V_80 ,
V_65 -> V_66 . V_141 , V_65 -> V_82 , V_65 -> V_142 ,
V_65 -> V_116 . V_143 ,
V_65 -> V_116 . V_144 ,
& V_86 -> V_90 , F_22 ( V_86 -> V_91 ) ,
F_22 ( V_88 -> V_91 ) ,
& V_87 -> V_90 , F_22 ( V_87 -> V_91 ) ,
F_22 ( V_89 -> V_91 ) ) ;
}
if ( V_63 < V_62 )
V_139 -> V_12 += V_63 ;
return 0 ;
}
static int F_51 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_145 * V_65 = V_2 ;
struct V_9 * V_139 = V_3 ;
int V_62 ;
int V_63 ;
V_62 = V_139 -> V_64 - V_139 -> V_12 - 1 ;
if ( V_62 == 0 )
return 1 ;
if ( V_65 -> V_66 . V_67 . V_68 == V_69 ) {
struct V_70 * V_71 = (struct V_70 * )
& V_65 -> V_66 . V_67 ;
struct V_70 * V_74 = (struct V_70 * )
& V_65 -> V_66 . V_75 ;
V_63 = snprintf ( V_139 -> V_6 + V_139 -> V_12 , V_62 ,
L_43
L_44 ,
V_65 , V_65 -> V_66 . V_140 , ( int ) V_65 -> V_66 . V_79 ,
V_65 -> V_66 . V_80 , V_65 -> V_146 , V_65 -> V_147 ,
& V_71 -> V_83 , F_22 ( V_71 -> V_84 ) ,
F_22 ( V_74 -> V_84 ) ) ;
} else {
struct V_85 * V_86 = (struct V_85 * )
& V_65 -> V_66 . V_67 ;
struct V_85 * V_88 = (struct V_85 * )
& V_65 -> V_66 . V_75 ;
V_63 = snprintf ( V_139 -> V_6 + V_139 -> V_12 , V_62 ,
L_43
L_45 ,
V_65 , V_65 -> V_66 . V_140 , ( int ) V_65 -> V_66 . V_79 ,
V_65 -> V_66 . V_80 , V_65 -> V_146 , V_65 -> V_147 ,
& V_86 -> V_90 , F_22 ( V_86 -> V_91 ) ,
F_22 ( V_88 -> V_91 ) ) ;
}
if ( V_63 < V_62 )
V_139 -> V_12 += V_63 ;
return 0 ;
}
static int F_52 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
struct V_9 * V_139 = V_5 -> V_11 ;
if ( ! V_139 ) {
F_53 ( L_13 , V_93 ) ;
return 0 ;
}
F_25 ( V_139 -> V_6 ) ;
F_26 ( V_139 ) ;
return 0 ;
}
static int F_54 ( struct V_56 * V_56 , struct V_5 * V_5 )
{
struct V_9 * V_139 ;
int V_102 = 0 ;
int V_7 = 1 ;
V_139 = F_28 ( sizeof( * V_139 ) , V_94 ) ;
if ( ! V_139 ) {
V_102 = - V_95 ;
goto V_113;
}
V_139 -> V_96 = V_56 -> V_57 ;
V_139 -> V_12 = 0 ;
F_29 ( & V_139 -> V_96 -> V_97 ) ;
F_30 ( & V_139 -> V_96 -> V_148 , F_1 , & V_7 ) ;
F_30 ( & V_139 -> V_96 -> V_149 , F_1 , & V_7 ) ;
F_30 ( & V_139 -> V_96 -> V_150 , F_1 , & V_7 ) ;
F_31 ( & V_139 -> V_96 -> V_97 ) ;
V_139 -> V_64 = V_7 * 240 ;
V_139 -> V_6 = F_32 ( V_139 -> V_64 ) ;
if ( ! V_139 -> V_6 ) {
V_102 = - V_95 ;
goto V_115;
}
F_29 ( & V_139 -> V_96 -> V_97 ) ;
F_30 ( & V_139 -> V_96 -> V_148 , F_50 , V_139 ) ;
F_30 ( & V_139 -> V_96 -> V_149 , F_50 , V_139 ) ;
F_30 ( & V_139 -> V_96 -> V_150 , F_51 , V_139 ) ;
F_31 ( & V_139 -> V_96 -> V_97 ) ;
V_5 -> V_11 = V_139 ;
goto V_113;
V_115:
F_26 ( V_139 ) ;
V_113:
return V_102 ;
}
static int F_55 ( struct V_46 * V_96 )
{
if ( ! V_96 -> V_151 )
return - 1 ;
F_56 ( L_46 , V_152 , V_96 -> V_151 ,
( void * ) V_96 , & V_153 , 4096 ) ;
F_56 ( L_47 , V_152 , V_96 -> V_151 ,
( void * ) V_96 , & V_154 , 4096 ) ;
F_56 ( L_48 , V_152 , V_96 -> V_151 ,
( void * ) V_96 , & V_155 , 4096 ) ;
F_56 ( L_49 , V_152 , V_96 -> V_151 ,
( void * ) V_96 , & V_156 , 4096 ) ;
if ( V_157 )
F_56 ( L_50 , V_152 , V_96 -> V_151 ,
( void * ) V_96 , & V_158 , 4096 ) ;
return 0 ;
}
void F_57 ( struct V_159 * V_20 ,
struct V_160 * V_161 )
{
struct V_162 * V_12 , * V_163 ;
struct V_164 * V_165 ;
F_48 ( & V_161 -> V_97 ) ;
F_58 (pos, nxt, &uctx->qpids) {
V_165 = F_59 ( V_12 , struct V_164 , V_165 ) ;
F_60 ( & V_165 -> V_165 ) ;
if ( ! ( V_165 -> V_30 & V_20 -> V_166 ) ) {
F_61 ( & V_20 -> V_167 . V_168 ,
V_165 -> V_30 ) ;
F_48 ( & V_20 -> V_116 . V_97 ) ;
V_20 -> V_116 . V_30 . V_119 -= V_20 -> V_166 + 1 ;
F_49 ( & V_20 -> V_116 . V_97 ) ;
}
F_26 ( V_165 ) ;
}
F_58 (pos, nxt, &uctx->qpids) {
V_165 = F_59 ( V_12 , struct V_164 , V_165 ) ;
F_60 ( & V_165 -> V_165 ) ;
F_26 ( V_165 ) ;
}
F_49 ( & V_161 -> V_97 ) ;
}
void F_62 ( struct V_159 * V_20 ,
struct V_160 * V_161 )
{
F_63 ( & V_161 -> V_169 ) ;
F_63 ( & V_161 -> V_170 ) ;
F_64 ( & V_161 -> V_97 ) ;
}
static int F_65 ( struct V_159 * V_20 )
{
int V_171 ;
F_62 ( V_20 , & V_20 -> V_161 ) ;
if ( V_20 -> V_25 . V_172 != V_20 -> V_25 . V_173 ) {
F_66 ( V_174 L_51 ,
F_67 ( V_20 -> V_25 . V_105 ) , V_20 -> V_25 . V_172 ,
V_20 -> V_25 . V_173 ) ;
return - V_175 ;
}
if ( V_20 -> V_25 . V_176 -> V_60 . V_177 != V_20 -> V_25 . V_176 -> V_178 . V_177 ||
V_20 -> V_25 . V_176 -> V_60 . V_179 != V_20 -> V_25 . V_176 -> V_178 . V_179 ) {
F_66 ( V_174 L_52
L_53 ,
F_67 ( V_20 -> V_25 . V_105 ) , V_20 -> V_25 . V_176 -> V_60 . V_177 ,
V_20 -> V_25 . V_176 -> V_60 . V_179 , V_20 -> V_25 . V_176 -> V_178 . V_179 ,
V_20 -> V_25 . V_176 -> V_178 . V_179 ) ;
return - V_175 ;
}
V_20 -> V_166 = V_20 -> V_25 . V_172 - 1 ;
V_20 -> V_180 = V_20 -> V_25 . V_173 - 1 ;
F_68 ( L_54
L_55
L_56 ,
V_93 , F_67 ( V_20 -> V_25 . V_105 ) , V_20 -> V_25 . V_176 -> V_122 . V_177 ,
V_20 -> V_25 . V_176 -> V_122 . V_179 , F_69 ( V_20 ) ,
V_20 -> V_25 . V_176 -> V_123 . V_177 ,
V_20 -> V_25 . V_176 -> V_123 . V_179 , V_20 -> V_25 . V_176 -> V_40 . V_177 ,
V_20 -> V_25 . V_176 -> V_40 . V_179 ,
V_20 -> V_25 . V_176 -> V_60 . V_177 ,
V_20 -> V_25 . V_176 -> V_60 . V_179 ,
V_20 -> V_25 . V_176 -> V_178 . V_177 ,
V_20 -> V_25 . V_176 -> V_178 . V_179 ) ;
F_68 ( L_57
L_58 ,
( unsigned ) F_70 ( V_20 -> V_25 . V_105 , 2 ) ,
( void * ) F_71 ( V_20 -> V_25 . V_105 , 2 ) ,
V_20 -> V_25 . V_181 , V_20 -> V_25 . V_182 ,
V_20 -> V_166 , V_20 -> V_180 ) ;
if ( F_69 ( V_20 ) == 0 )
return - V_175 ;
V_20 -> V_116 . V_117 . V_118 = V_183 ;
V_20 -> V_116 . V_122 . V_118 = V_20 -> V_25 . V_176 -> V_122 . V_179 ;
V_20 -> V_116 . V_123 . V_118 = V_20 -> V_25 . V_176 -> V_123 . V_179 ;
V_20 -> V_116 . V_124 . V_118 = V_20 -> V_25 . V_176 -> V_40 . V_179 ;
V_20 -> V_116 . V_125 . V_118 = V_20 -> V_25 . V_176 -> V_184 . V_179 ;
V_20 -> V_116 . V_30 . V_118 = V_20 -> V_25 . V_176 -> V_60 . V_179 ;
V_171 = F_72 ( V_20 , F_69 ( V_20 ) , V_183 ) ;
if ( V_171 ) {
F_24 (KERN_ERR MOD L_59 , err) ;
return V_171 ;
}
V_171 = F_73 ( V_20 ) ;
if ( V_171 ) {
F_24 (KERN_ERR MOD L_60 , err) ;
goto V_185;
}
V_171 = F_74 ( V_20 ) ;
if ( V_171 ) {
F_24 (KERN_ERR MOD L_61 , err) ;
goto V_186;
}
V_171 = F_75 ( V_20 ) ;
if ( V_171 ) {
F_24 (KERN_ERR MOD L_62 , err) ;
goto V_187;
}
V_20 -> V_188 = (struct V_189 * )
F_76 ( V_94 ) ;
if ( ! V_20 -> V_188 )
goto V_190;
V_20 -> V_188 -> V_191 = V_20 -> V_25 . V_176 -> V_60 . V_177 ;
V_20 -> V_188 -> V_192 = V_20 -> V_25 . V_176 -> V_60 . V_179 ;
V_20 -> V_188 -> V_193 = V_20 -> V_25 . V_176 -> V_178 . V_177 ;
V_20 -> V_188 -> V_194 = V_20 -> V_25 . V_176 -> V_178 . V_179 ;
if ( V_157 ) {
V_20 -> V_21 = F_77 ( ( 1 << V_195 ) *
sizeof( * V_20 -> V_21 ) , V_94 ) ;
if ( V_20 -> V_21 ) {
V_20 -> V_23 = 1 << V_195 ;
F_78 ( & V_20 -> V_22 , 0 ) ;
} else {
F_66 ( V_174 L_63 ) ;
}
}
V_20 -> V_188 -> V_196 = 0 ;
return 0 ;
V_190:
F_79 ( V_20 ) ;
V_187:
F_80 ( V_20 ) ;
V_186:
F_81 ( V_20 ) ;
V_185:
F_82 ( & V_20 -> V_167 ) ;
return V_171 ;
}
static void F_83 ( struct V_159 * V_20 )
{
F_26 ( V_20 -> V_21 ) ;
F_84 ( ( unsigned long ) V_20 -> V_188 ) ;
F_81 ( V_20 ) ;
F_80 ( V_20 ) ;
F_82 ( & V_20 -> V_167 ) ;
}
static void F_85 ( struct V_197 * V_198 )
{
F_83 ( & V_198 -> V_47 -> V_20 ) ;
F_86 ( & V_198 -> V_47 -> V_199 ) ;
F_86 ( & V_198 -> V_47 -> V_98 ) ;
F_86 ( & V_198 -> V_47 -> V_114 ) ;
F_86 ( & V_198 -> V_47 -> V_148 ) ;
F_86 ( & V_198 -> V_47 -> V_150 ) ;
F_86 ( & V_198 -> V_47 -> V_149 ) ;
if ( V_198 -> V_47 -> V_20 . V_200 )
F_87 ( V_198 -> V_47 -> V_20 . V_200 ) ;
if ( V_198 -> V_47 -> V_20 . V_201 )
F_87 ( V_198 -> V_47 -> V_20 . V_201 ) ;
F_88 ( & V_198 -> V_47 -> V_202 ) ;
V_198 -> V_47 = NULL ;
}
static void F_89 ( struct V_197 * V_198 )
{
F_68 ( L_64 , V_93 , V_198 -> V_47 ) ;
F_90 ( V_198 -> V_47 ) ;
F_85 ( V_198 ) ;
}
static int F_91 ( const struct V_203 * V_204 )
{
return V_204 -> V_176 -> V_122 . V_179 > 0 && V_204 -> V_176 -> V_123 . V_179 > 0 &&
V_204 -> V_176 -> V_40 . V_179 > 0 && V_204 -> V_176 -> V_60 . V_179 > 0 &&
V_204 -> V_176 -> V_178 . V_179 > 0 ;
}
static struct V_46 * F_92 ( const struct V_203 * V_204 )
{
struct V_46 * V_96 ;
int V_102 ;
if ( ! F_91 ( V_204 ) ) {
F_24 (KERN_INFO MOD L_65 ,
pci_name(infop->pdev)) ;
return F_93 ( - V_205 ) ;
}
if ( ! F_94 ( V_204 ) )
F_53 ( L_66 ,
F_67 ( V_204 -> V_105 ) ) ;
V_96 = (struct V_46 * ) F_95 ( sizeof( * V_96 ) ) ;
if ( ! V_96 ) {
F_24 (KERN_ERR MOD L_67 ) ;
return F_93 ( - V_95 ) ;
}
V_96 -> V_20 . V_25 = * V_204 ;
F_68 ( L_68 ,
V_93 , V_96 -> V_20 . V_25 . V_206 ,
V_96 -> V_20 . V_25 . V_207 ) ;
V_96 -> V_20 . V_208 . V_209 =
V_96 -> V_20 . V_25 . V_206 > 64 ? 2 : 1 ;
V_96 -> V_20 . V_208 . V_210 = 65520 ;
V_96 -> V_20 . V_208 . V_211 = 65520 ;
V_96 -> V_20 . V_208 . V_212 = 8192 -
V_96 -> V_20 . V_208 . V_209 - 1 ;
V_96 -> V_20 . V_208 . V_213 =
V_96 -> V_20 . V_208 . V_210 -
V_96 -> V_20 . V_208 . V_209 - 1 ;
V_96 -> V_20 . V_208 . V_214 =
V_96 -> V_20 . V_208 . V_212 ;
V_96 -> V_20 . V_208 . V_215 =
V_96 -> V_20 . V_208 . V_211 - 2 ;
V_96 -> V_20 . V_208 . V_216 =
V_96 -> V_20 . V_25 . V_207 ;
V_96 -> V_20 . V_217 = F_71 ( V_96 -> V_20 . V_25 . V_105 , 2 ) ;
if ( ! F_96 ( V_96 -> V_20 . V_25 . V_218 ) ) {
V_96 -> V_20 . V_200 = F_97 ( V_96 -> V_20 . V_217 ,
F_70 ( V_96 -> V_20 . V_25 . V_105 , 2 ) ) ;
if ( ! V_96 -> V_20 . V_200 ) {
F_66 ( V_174 L_69 ) ;
F_88 ( & V_96 -> V_202 ) ;
return F_93 ( - V_175 ) ;
}
} else if ( F_94 ( V_204 ) ) {
V_96 -> V_20 . V_219 =
F_71 ( V_96 -> V_20 . V_25 . V_105 , 2 ) +
F_70 ( V_96 -> V_20 . V_25 . V_105 , 2 ) -
F_98 ( V_96 -> V_20 . V_25 . V_176 -> V_184 . V_179 ) ;
V_96 -> V_20 . V_201 = F_97 ( V_96 -> V_20 . V_219 ,
V_96 -> V_20 . V_25 . V_176 -> V_184 . V_179 ) ;
if ( ! V_96 -> V_20 . V_201 ) {
F_66 ( V_174 L_70 ) ;
F_88 ( & V_96 -> V_202 ) ;
return F_93 ( - V_175 ) ;
}
}
F_68 (KERN_INFO MOD L_71
L_72 ,
devp->rdev.lldi.vr->ocq.start, devp->rdev.lldi.vr->ocq.size,
devp->rdev.oc_mw_pa, devp->rdev.oc_mw_kva) ;
V_102 = F_65 ( & V_96 -> V_20 ) ;
if ( V_102 ) {
F_24 (KERN_ERR MOD L_73 , ret) ;
F_88 ( & V_96 -> V_202 ) ;
return F_93 ( V_102 ) ;
}
F_99 ( & V_96 -> V_199 ) ;
F_99 ( & V_96 -> V_98 ) ;
F_99 ( & V_96 -> V_114 ) ;
F_99 ( & V_96 -> V_148 ) ;
F_99 ( & V_96 -> V_150 ) ;
F_99 ( & V_96 -> V_149 ) ;
F_100 ( & V_96 -> V_97 ) ;
F_64 ( & V_96 -> V_20 . V_116 . V_97 ) ;
F_64 ( & V_96 -> V_220 ) ;
F_63 ( & V_96 -> V_221 ) ;
V_96 -> V_137 = V_96 -> V_20 . V_25 . V_222 ;
if ( V_223 ) {
V_96 -> V_151 = F_101 (
F_67 ( V_96 -> V_20 . V_25 . V_105 ) ,
V_223 ) ;
F_55 ( V_96 ) ;
}
return V_96 ;
}
static void * F_102 ( const struct V_203 * V_204 )
{
struct V_197 * V_198 ;
static int V_224 ;
int V_58 ;
if ( ! V_224 ++ )
F_53 ( L_74 ,
V_225 ) ;
V_198 = F_77 ( sizeof *V_198 , V_94 ) ;
if ( ! V_198 ) {
V_198 = F_93 ( - V_95 ) ;
goto V_113;
}
V_198 -> V_25 = * V_204 ;
F_68 ( L_75 ,
V_93 , F_67 ( V_198 -> V_25 . V_105 ) ,
V_198 -> V_25 . V_226 , V_198 -> V_25 . V_227 ,
V_198 -> V_25 . V_228 , V_198 -> V_25 . V_229 ) ;
F_48 ( & V_230 ) ;
F_103 ( & V_198 -> V_165 , & V_231 ) ;
F_49 ( & V_230 ) ;
for ( V_58 = 0 ; V_58 < V_198 -> V_25 . V_227 ; V_58 ++ )
F_68 ( L_76 , V_58 , V_198 -> V_25 . V_232 [ V_58 ] ) ;
V_113:
return V_198 ;
}
static inline struct V_233 * F_104 ( const struct V_234 * V_235 ,
const T_6 * V_236 ,
V_103 V_237 )
{
struct V_233 * V_238 ;
V_238 = F_105 ( V_235 -> V_239 + sizeof( struct V_240 ) +
sizeof( struct V_241 ) - V_237 , V_242 ) ;
if ( F_106 ( ! V_238 ) )
return NULL ;
F_107 ( V_238 , V_235 -> V_239 + sizeof( struct V_240 ) +
sizeof( struct V_241 ) - V_237 ) ;
F_108 ( V_238 , V_236 , sizeof( struct V_240 ) +
sizeof( struct V_241 ) ) ;
F_109 ( V_238 , sizeof( struct V_241 ) +
sizeof( struct V_240 ) ,
V_235 -> V_243 + V_237 ,
V_235 -> V_239 - V_237 ) ;
return V_238 ;
}
static inline int F_110 ( struct V_46 * V_47 , const struct V_234 * V_235 ,
const T_6 * V_236 )
{
unsigned int V_32 = * ( V_244 * ) V_236 ;
struct V_233 * V_238 ;
if ( V_32 != V_245 )
goto V_113;
V_238 = F_104 ( V_235 , V_236 , V_47 -> V_20 . V_25 . V_246 ) ;
if ( V_238 == NULL )
goto V_113;
if ( V_247 [ V_32 ] == NULL ) {
F_53 ( L_77 , V_93 ,
V_32 ) ;
F_111 ( V_238 ) ;
goto V_113;
}
V_247 [ V_32 ] ( V_47 , V_238 ) ;
return 1 ;
V_113:
return 0 ;
}
static int F_112 ( void * V_248 , const T_6 * V_236 ,
const struct V_234 * V_235 )
{
struct V_197 * V_198 = V_248 ;
struct V_46 * V_47 = V_198 -> V_47 ;
struct V_233 * V_238 ;
V_244 V_32 ;
if ( V_235 == NULL ) {
unsigned int V_249 = 64 - sizeof( struct V_250 ) - 8 ;
V_238 = F_105 ( 256 , V_242 ) ;
if ( ! V_238 )
goto V_251;
F_107 ( V_238 , V_249 ) ;
F_108 ( V_238 , & V_236 [ 1 ] , V_249 ) ;
} else if ( V_235 == V_252 ) {
const struct V_250 * V_253 = ( void * ) V_236 ;
V_103 V_30 = F_113 ( V_253 -> V_254 ) ;
F_114 ( V_47 , V_30 ) ;
return 0 ;
} else if ( F_106 ( * ( V_244 * ) V_236 != * ( V_244 * ) V_235 -> V_243 ) ) {
if ( F_110 ( V_47 , V_235 , V_236 ) )
return 0 ;
F_53 ( L_78 \
L_79 ,
F_67 ( V_198 -> V_25 . V_105 ) , V_235 -> V_243 ,
( unsigned long long ) F_115 ( * V_236 ) ,
( unsigned long long ) F_115 (
* ( V_255 T_6 * ) V_235 -> V_243 ) ,
V_235 -> V_239 ) ;
return 0 ;
} else {
V_238 = F_116 ( V_235 , 128 , 128 ) ;
if ( F_106 ( ! V_238 ) )
goto V_251;
}
V_32 = * ( V_244 * ) V_236 ;
if ( V_247 [ V_32 ] ) {
V_247 [ V_32 ] ( V_47 , V_238 ) ;
} else {
F_53 ( L_77 , V_93 ,
V_32 ) ;
F_111 ( V_238 ) ;
}
return 0 ;
V_251:
return - 1 ;
}
static int F_117 ( void * V_248 , enum V_256 V_257 )
{
struct V_197 * V_198 = V_248 ;
F_68 ( L_80 , V_93 , V_257 ) ;
switch ( V_257 ) {
case V_258 :
F_24 (KERN_INFO MOD L_81 , pci_name(ctx->lldi.pdev)) ;
if ( ! V_198 -> V_47 ) {
int V_102 ;
V_198 -> V_47 = F_92 ( & V_198 -> V_25 ) ;
if ( F_118 ( V_198 -> V_47 ) ) {
F_24 (KERN_ERR MOD
L_82 ,
pci_name(ctx->lldi.pdev),
PTR_ERR(ctx->dev)) ;
V_198 -> V_47 = NULL ;
break;
}
V_102 = F_119 ( V_198 -> V_47 ) ;
if ( V_102 ) {
F_24 (KERN_ERR MOD
L_83 ,
pci_name(ctx->lldi.pdev), ret) ;
F_85 ( V_198 ) ;
}
}
break;
case V_259 :
F_24 (KERN_INFO MOD L_84 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_198 -> V_47 )
F_89 ( V_198 ) ;
break;
case V_260 :
F_24 (KERN_INFO MOD L_85 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_198 -> V_47 ) {
struct V_261 V_262 ;
V_198 -> V_47 -> V_20 . V_80 |= V_263 ;
memset ( & V_262 , 0 , sizeof V_262 ) ;
V_262 . V_262 = V_264 ;
V_262 . V_265 = & V_198 -> V_47 -> V_202 ;
F_120 ( & V_262 ) ;
F_89 ( V_198 ) ;
}
break;
case V_266 :
F_24 (KERN_INFO MOD L_86 ,
pci_name(ctx->lldi.pdev)) ;
if ( V_198 -> V_47 )
F_89 ( V_198 ) ;
break;
}
return 0 ;
}
static int F_121 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_59 * V_60 = V_2 ;
F_122 ( & V_60 -> V_14 ) ;
return 0 ;
}
static void F_123 ( struct V_197 * V_198 )
{
unsigned long V_80 ;
F_124 ( & V_198 -> V_47 -> V_97 , V_80 ) ;
V_198 -> V_47 -> V_20 . V_116 . V_131 ++ ;
V_198 -> V_47 -> V_130 = V_267 ;
if ( V_198 -> V_47 -> V_20 . V_80 & V_268 )
F_30 ( & V_198 -> V_47 -> V_98 , F_121 , NULL ) ;
else
V_198 -> V_47 -> V_20 . V_188 -> V_196 = 1 ;
F_125 ( & V_198 -> V_47 -> V_97 , V_80 ) ;
}
static int F_126 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_59 * V_60 = V_2 ;
F_127 ( & V_60 -> V_14 ) ;
return 0 ;
}
static void F_128 ( struct V_59 * V_60 )
{
F_129 ( & V_60 -> V_97 ) ;
F_130 ( & V_60 -> V_14 , V_60 -> V_14 . V_31 . V_269 , NULL ) ;
V_60 -> V_14 . V_31 . V_269 = 0 ;
F_131 ( & V_60 -> V_14 , V_60 -> V_14 . V_40 . V_269 , NULL ) ;
V_60 -> V_14 . V_40 . V_269 = 0 ;
F_132 ( & V_60 -> V_97 ) ;
}
static void F_133 ( struct V_197 * V_198 )
{
int V_58 ;
struct V_59 * V_60 ;
for ( V_58 = 0 ; V_58 < V_270 ; V_58 ++ ) {
V_60 = F_134 ( & V_198 -> V_47 -> V_221 , struct V_59 ,
V_271 ) ;
F_60 ( & V_60 -> V_271 ) ;
F_128 ( V_60 ) ;
if ( F_135 ( & V_198 -> V_47 -> V_221 ) )
break;
}
}
static void F_136 ( struct V_197 * V_198 )
{
F_29 ( & V_198 -> V_47 -> V_97 ) ;
if ( V_198 -> V_47 -> V_130 != V_267 )
goto V_113;
V_198 -> V_47 -> V_130 = V_272 ;
while ( 1 ) {
if ( F_135 ( & V_198 -> V_47 -> V_221 ) ) {
F_137 ( V_198 -> V_47 -> V_130 != V_272 ) ;
V_198 -> V_47 -> V_130 = V_273 ;
V_198 -> V_47 -> V_20 . V_116 . V_131 ++ ;
if ( V_198 -> V_47 -> V_20 . V_80 & V_268 ) {
F_30 ( & V_198 -> V_47 -> V_98 , F_126 ,
NULL ) ;
} else {
V_198 -> V_47 -> V_20 . V_188 -> V_196 = 0 ;
}
break;
} else {
if ( F_138 ( V_198 -> V_47 -> V_20 . V_25 . V_26 [ 0 ] , 1 )
< ( V_198 -> V_47 -> V_20 . V_25 . V_274 <<
V_275 ) ) {
F_133 ( V_198 ) ;
}
if ( ! F_135 ( & V_198 -> V_47 -> V_221 ) ) {
F_31 ( & V_198 -> V_47 -> V_97 ) ;
if ( V_276 ) {
F_139 ( V_277 ) ;
F_140 ( V_276 ) ;
}
F_29 ( & V_198 -> V_47 -> V_97 ) ;
if ( V_198 -> V_47 -> V_130 != V_272 )
break;
}
}
}
V_113:
if ( V_198 -> V_47 -> V_130 != V_273 )
V_198 -> V_47 -> V_20 . V_116 . V_132 ++ ;
F_31 ( & V_198 -> V_47 -> V_97 ) ;
}
static int F_141 ( int V_1 , void * V_2 , void * V_3 )
{
struct V_278 * V_279 = V_3 ;
struct V_59 * V_60 = V_2 ;
F_142 ( & V_60 -> V_280 ) ;
V_279 -> V_281 [ V_279 -> V_19 ++ ] = V_60 ;
return 0 ;
}
static int F_143 ( int V_1 , void * V_2 , void * V_3 )
{
unsigned * V_4 = V_3 ;
( * V_4 ) ++ ;
return 0 ;
}
static void F_144 ( struct V_278 * V_278 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_278 -> V_19 ; V_19 ++ )
F_145 ( & V_278 -> V_281 [ V_19 ] -> V_280 ) ;
}
static void F_146 ( struct V_197 * V_198 , struct V_278 * V_278 )
{
int V_19 ;
int V_102 ;
for ( V_19 = 0 ; V_19 < V_278 -> V_19 ; V_19 ++ ) {
struct V_59 * V_60 = V_278 -> V_281 [ V_19 ] ;
F_29 ( & V_60 -> V_282 -> V_97 ) ;
F_129 ( & V_60 -> V_97 ) ;
V_102 = F_147 ( V_60 -> V_282 -> V_20 . V_25 . V_26 [ 0 ] ,
V_60 -> V_14 . V_31 . V_30 ,
F_148 ( & V_60 -> V_14 ) ,
F_149 ( & V_60 -> V_14 ) ) ;
if ( V_102 ) {
F_66 ( V_174 L_87
L_88
L_89 ,
F_67 ( V_198 -> V_25 . V_105 ) , V_60 -> V_14 . V_31 . V_30 ) ;
F_132 ( & V_60 -> V_97 ) ;
F_31 ( & V_60 -> V_282 -> V_97 ) ;
return;
}
V_60 -> V_14 . V_31 . V_269 = 0 ;
V_102 = F_147 ( V_60 -> V_282 -> V_20 . V_25 . V_26 [ 0 ] ,
V_60 -> V_14 . V_40 . V_30 ,
F_150 ( & V_60 -> V_14 ) ,
F_151 ( & V_60 -> V_14 ) ) ;
if ( V_102 ) {
F_66 ( V_174 L_87
L_88
L_90 ,
F_67 ( V_198 -> V_25 . V_105 ) , V_60 -> V_14 . V_40 . V_30 ) ;
F_132 ( & V_60 -> V_97 ) ;
F_31 ( & V_60 -> V_282 -> V_97 ) ;
return;
}
V_60 -> V_14 . V_40 . V_269 = 0 ;
F_132 ( & V_60 -> V_97 ) ;
F_31 ( & V_60 -> V_282 -> V_97 ) ;
while ( F_138 ( V_60 -> V_282 -> V_20 . V_25 . V_26 [ 0 ] , 1 ) > 0 ) {
F_139 ( V_277 ) ;
F_140 ( F_152 ( 10 ) ) ;
}
}
}
static void F_153 ( struct V_197 * V_198 )
{
int V_7 = 0 ;
struct V_278 V_278 ;
int V_102 ;
F_139 ( V_277 ) ;
F_140 ( F_152 ( 1000 ) ) ;
V_102 = F_154 ( V_198 -> V_47 -> V_20 . V_25 . V_26 [ 0 ] ) ;
if ( V_102 ) {
F_24 (KERN_ERR MOD L_91 ,
pci_name(ctx->lldi.pdev)) ;
return;
}
F_29 ( & V_198 -> V_47 -> V_97 ) ;
F_137 ( V_198 -> V_47 -> V_130 != V_267 ) ;
V_198 -> V_47 -> V_130 = V_283 ;
F_30 ( & V_198 -> V_47 -> V_98 , F_143 , & V_7 ) ;
V_278 . V_281 = F_77 ( V_7 * sizeof * V_278 . V_281 , V_242 ) ;
if ( ! V_278 . V_281 ) {
F_24 (KERN_ERR MOD L_91 ,
pci_name(ctx->lldi.pdev)) ;
F_31 ( & V_198 -> V_47 -> V_97 ) ;
return;
}
V_278 . V_19 = 0 ;
F_30 ( & V_198 -> V_47 -> V_98 , F_141 , & V_278 ) ;
F_31 ( & V_198 -> V_47 -> V_97 ) ;
F_146 ( V_198 , & V_278 ) ;
F_144 ( & V_278 ) ;
F_26 ( V_278 . V_281 ) ;
F_29 ( & V_198 -> V_47 -> V_97 ) ;
F_137 ( V_198 -> V_47 -> V_130 != V_283 ) ;
V_198 -> V_47 -> V_130 = V_267 ;
F_31 ( & V_198 -> V_47 -> V_97 ) ;
}
static int F_155 ( void * V_248 , enum V_284 V_285 , ... )
{
struct V_197 * V_198 = V_248 ;
switch ( V_285 ) {
case V_286 :
F_123 ( V_198 ) ;
V_198 -> V_47 -> V_20 . V_116 . V_126 ++ ;
break;
case V_287 :
F_136 ( V_198 ) ;
F_48 ( & V_198 -> V_47 -> V_20 . V_116 . V_97 ) ;
V_198 -> V_47 -> V_20 . V_116 . V_127 ++ ;
F_49 ( & V_198 -> V_47 -> V_20 . V_116 . V_97 ) ;
break;
case V_288 :
F_153 ( V_198 ) ;
F_48 ( & V_198 -> V_47 -> V_20 . V_116 . V_97 ) ;
V_198 -> V_47 -> V_20 . V_116 . V_128 ++ ;
F_49 ( & V_198 -> V_47 -> V_20 . V_116 . V_97 ) ;
break;
default:
F_24 (KERN_WARNING MOD L_92 ,
pci_name(ctx->lldi.pdev), control) ;
break;
}
return 0 ;
}
static int T_7 F_156 ( void )
{
int V_171 ;
V_171 = F_157 () ;
if ( V_171 )
return V_171 ;
V_223 = F_101 ( V_289 , NULL ) ;
if ( ! V_223 )
F_24 (KERN_WARNING MOD
L_93 ) ;
if ( F_158 ( V_290 , V_291 ,
V_292 ) )
F_66 ( L_94
, V_93 , __LINE__ ) ;
V_171 = F_159 ( V_290 ) ;
if ( V_171 ) {
F_66 ( L_95 , V_171 ) ;
F_160 ( V_290 ) ;
F_161 () ;
F_162 ( V_223 ) ;
return V_171 ;
}
F_163 ( V_293 , & V_294 ) ;
return 0 ;
}
static void T_8 F_164 ( void )
{
struct V_197 * V_198 , * V_295 ;
F_48 ( & V_230 ) ;
F_165 (ctx, tmp, &uld_ctx_list, entry) {
if ( V_198 -> V_47 )
F_89 ( V_198 ) ;
F_26 ( V_198 ) ;
}
F_49 ( & V_230 ) ;
F_166 ( V_293 ) ;
F_167 ( V_290 ) ;
F_160 ( V_290 ) ;
F_161 () ;
F_162 ( V_223 ) ;
}
