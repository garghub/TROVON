static int F_1 ( T_1 * V_1 ,
struct V_2 * V_3 ,
T_2 V_4 , T_2 V_5 , T_2 V_6 , T_2 V_7 ,
int V_8 )
{
int V_9 = 0 , V_10 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_15 * V_16 , V_17 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 ;
T_3 V_22 = F_3 ( V_3 -> V_23 . V_24 ) ;
T_3 V_25 = F_4 ( V_11 -> V_14 , V_6 ) ;
V_9 = F_5 ( V_1 , V_11 , V_4 ,
V_6 , V_7 , V_5 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_27 = F_7 ( V_4 ) ;
V_17 . V_28 = F_8 ( V_5 ) ;
V_17 . V_29 = F_9 ( F_4 ( V_11 -> V_14 ,
V_7 ) ) ;
V_19 = F_10 ( & V_3 -> V_23 ) ;
if ( ! V_19 ) {
V_9 = - V_30 ;
F_6 ( V_9 ) ;
goto V_26;
}
V_9 = F_11 ( F_12 ( V_11 ) , V_19 , V_4 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
V_21 = F_13 ( V_19 ) ;
V_10 = F_14 ( V_21 , V_4 ) ;
if ( V_10 == - 1 ) {
V_9 = F_15 ( V_11 -> V_14 ,
L_1 ,
( unsigned long long ) V_22 , V_4 ) ;
goto V_26;
}
V_16 = & V_21 -> V_31 [ V_10 ] ;
F_16 ( V_8 != V_16 -> V_32 ) ;
V_17 . V_32 = V_8 & ~ V_33 ;
V_9 = F_17 ( V_1 , F_12 ( V_11 ) ,
V_3 -> V_23 . V_34 ,
V_35 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
V_9 = F_18 ( V_1 , & V_3 -> V_23 , V_19 , V_10 ,
& V_17 , V_3 -> V_36 ,
& V_3 -> V_37 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
F_19 ( V_1 , V_3 -> V_23 . V_34 ) ;
V_3 -> V_38 = V_7 ;
if ( V_25 ) {
if ( V_8 & V_33 )
V_9 = F_20 ( V_11 , V_1 ,
F_21 ( V_13 -> V_39 ,
V_25 ) ,
V_5 , V_3 -> V_36 ,
& V_3 -> V_37 , 1 ) ;
else
V_9 = F_22 ( V_13 , V_1 ,
V_25 , V_5 ) ;
}
F_23 ( V_1 , V_11 , 0 ) ;
V_26:
F_24 ( V_19 ) ;
return V_9 ;
}
static int F_25 ( struct V_11 * V_11 ,
struct V_40 * V_23 ,
T_2 V_41 ,
T_2 V_42 ,
struct V_43 * * V_36 ,
struct V_43 * * V_44 ,
int V_45 ,
int * V_46 )
{
int V_9 , V_47 ;
unsigned int V_48 = 2 * V_42 + V_41 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
V_47 = F_26 ( V_23 ) ;
if ( V_47 < 0 ) {
V_9 = V_47 ;
F_6 ( V_9 ) ;
goto V_26;
}
if ( ! V_47 ||
( F_27 ( V_13 ) && V_47 < V_48 ) )
V_45 += F_28 ( V_23 -> V_49 ) ;
V_9 = F_29 ( V_13 , V_45 , V_36 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
if ( V_44 ) {
V_9 = F_30 ( V_13 , V_41 , V_44 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
}
* V_46 += F_31 ( V_13 -> V_39 , V_23 -> V_49 ) ;
F_32 ( 0 , L_2 ,
V_45 , V_41 , * V_46 ) ;
V_26:
if ( V_9 ) {
if ( * V_36 ) {
F_33 ( * V_36 ) ;
* V_36 = NULL ;
}
}
return V_9 ;
}
static int F_34 ( struct V_2 * V_3 ,
T_2 V_4 , T_2 V_50 , T_2 * V_5 , int V_8 )
{
int V_9 , V_46 = 0 , V_45 = 0 , V_51 = V_3 -> V_51 ;
T_1 * V_1 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_11 * V_52 = V_13 -> V_53 ;
struct V_54 * V_55 = NULL ;
T_2 V_38 , V_56 ;
T_3 V_57 = F_4 ( V_11 -> V_14 , V_50 ) ;
if ( ( V_8 & V_33 ) && * V_5 ) {
F_16 ( ! F_35 ( V_11 ) ) ;
F_16 ( ! V_3 -> V_58 ) ;
V_9 = F_36 ( V_13 , V_3 -> V_58 , 1 ,
& V_55 , NULL ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
return V_9 ;
}
V_9 = F_37 ( V_11 ,
V_3 -> V_58 ,
V_57 ,
* V_5 ,
& V_46 ,
& V_45 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
}
V_9 = F_25 ( V_11 , & V_3 -> V_23 , * V_5 , 1 ,
& V_3 -> V_36 ,
& V_3 -> V_44 ,
V_45 , & V_46 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
F_38 ( V_52 ) ;
if ( F_39 ( V_13 ) ) {
V_9 = F_40 ( V_13 ) ;
if ( V_9 < 0 ) {
F_6 ( V_9 ) ;
goto V_59;
}
}
V_1 = F_41 ( V_13 , V_46 ) ;
if ( F_42 ( V_1 ) ) {
V_9 = F_43 ( V_1 ) ;
F_6 ( V_9 ) ;
goto V_59;
}
V_9 = F_44 ( V_1 , V_3 -> V_44 , 1 , * V_5 ,
& V_38 , & V_56 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_60;
}
if ( V_56 != * V_5 ) {
F_32 ( 0 , L_3 , V_56 , * V_5 ) ;
if ( ! V_51 ) {
V_3 -> V_61 -> V_62 &= ~ V_63 ;
V_9 = - V_64 ;
goto V_60;
}
}
F_32 ( 0 , L_4 , V_4 ,
V_50 , V_38 ) ;
V_9 = F_1 ( V_1 , V_3 , V_4 , V_56 , V_50 ,
V_38 , V_8 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
if ( V_51 && ( V_56 != * V_5 ) )
* V_5 = V_56 ;
V_9 = F_45 ( V_11 -> V_14 , V_3 -> V_11 , V_4 , * V_5 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
V_60:
F_46 ( V_13 , V_1 ) ;
V_59:
F_47 ( V_52 ) ;
if ( V_3 -> V_44 ) {
F_33 ( V_3 -> V_44 ) ;
V_3 -> V_44 = NULL ;
}
if ( V_3 -> V_36 ) {
F_33 ( V_3 -> V_36 ) ;
V_3 -> V_36 = NULL ;
}
V_26:
if ( V_55 )
F_48 ( V_13 , V_55 , 1 ) ;
return V_9 ;
}
static int F_49 ( struct V_11 * V_11 ,
T_3 V_65 ,
int type , int V_66 ,
int * V_67 ,
struct V_68 * * V_69 )
{
int V_9 , V_70 , V_71 = 0 ;
T_3 V_72 ;
char V_73 [ 40 ] ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_68 * V_74 = NULL , * V_75 = NULL ;
struct V_76 * V_77 ;
struct V_78 * V_16 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
F_50 ( V_73 , sizeof( V_73 ) , type , V_66 ) ;
V_9 = F_51 ( V_13 -> V_83 , V_73 ,
strlen ( V_73 ) , & V_72 ) ;
if ( V_9 ) {
V_9 = - V_84 ;
goto V_26;
}
V_9 = F_52 ( V_13 , V_72 , 1 , & V_74 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
V_80 = (struct V_79 * ) V_74 -> V_85 ;
V_77 = & ( V_80 -> V_86 . V_87 ) ;
V_16 = & ( V_77 -> V_88 [ 0 ] ) ;
if ( type == V_89 )
V_71 = V_13 -> V_90 -
V_11 -> V_14 -> V_91 ;
if ( ( V_65 < F_53 ( V_16 -> V_92 ) ) ||
( V_65 >= ( ( T_3 ) F_54 ( V_80 -> V_93 . V_94 . V_95 ) <<
V_71 ) ) ) {
V_9 = - V_96 ;
goto V_26;
}
for ( V_70 = 0 ; V_70 < F_55 ( V_77 -> V_97 ) ; V_70 ++ ) {
V_16 = & ( V_77 -> V_88 [ V_70 ] ) ;
if ( ! V_16 )
continue;
V_82 = NULL ;
do {
if ( ! V_82 )
V_72 = F_53 ( V_16 -> V_92 ) ;
else
V_72 = F_53 ( V_82 -> V_98 ) ;
if ( V_75 ) {
F_56 ( V_75 ) ;
V_75 = NULL ;
}
V_9 = F_52 ( V_13 , V_72 , 1 , & V_75 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
V_82 = (struct V_81 * ) V_75 -> V_85 ;
if ( V_65 < ( F_53 ( V_82 -> V_99 ) +
F_55 ( V_82 -> V_100 ) ) ) {
* V_69 = V_75 ;
* V_67 = ( V_65 - V_72 ) >>
V_71 ;
F_32 ( 0 , L_5
L_6 ,
V_72 , F_55 ( V_82 -> V_100 ) ,
* V_67 ) ;
goto V_26;
}
} while ( F_53 ( V_82 -> V_98 ) );
}
V_9 = - V_96 ;
V_26:
F_56 ( V_74 ) ;
return V_9 ;
}
static int F_57 ( struct V_11 * V_11 ,
struct V_101 * V_61 )
{
int V_9 , V_102 = 0 ;
struct V_68 * V_75 = NULL ;
struct V_81 * V_82 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
int V_103 = 1 << ( V_13 -> V_90 -
V_11 -> V_14 -> V_91 ) ;
V_61 -> V_104 = F_58 ( V_11 -> V_14 ,
V_61 -> V_104 ) ;
V_9 = F_49 ( V_11 , V_61 -> V_104 ,
V_89 ,
V_105 ,
& V_102 , & V_75 ) ;
if ( V_9 )
goto V_26;
V_82 = (struct V_81 * ) V_75 -> V_85 ;
if ( V_61 -> V_104 == F_53 ( V_82 -> V_99 ) )
V_61 -> V_104 += V_103 ;
if ( ( F_55 ( V_82 -> V_100 ) - V_102 ) * V_13 -> V_106 <
V_61 -> V_107 ) {
V_9 = - V_96 ;
goto V_26;
}
F_32 ( 0 , L_7 ,
V_61 -> V_104 ) ;
V_26:
F_56 ( V_75 ) ;
return V_9 ;
}
static void F_59 ( struct V_11 * V_11 , struct V_68 * V_108 ,
int * V_102 , T_2 V_109 , T_2 V_110 ,
T_2 * V_50 )
{
int V_70 , V_111 , V_112 = 0 , V_113 = * V_102 ;
struct V_81 * V_114 = (struct V_81 * ) V_108 -> V_85 ;
T_2 V_115 = F_21 ( V_11 -> V_14 ,
F_53 ( V_114 -> V_99 ) ) ;
for ( V_70 = V_113 ; V_70 < F_55 ( V_114 -> V_100 ) ; V_70 ++ ) {
V_111 = F_60 ( V_70 , ( unsigned long * ) V_114 -> V_116 ) ;
if ( V_111 ) {
if ( ( V_70 - V_113 ) > V_110 ) {
* V_50 = 0 ;
break;
}
if ( V_112 )
V_112 = 0 ;
continue;
} else
V_112 ++ ;
if ( V_112 == V_109 ) {
* V_102 = V_70 ;
* V_50 = V_115 + V_70 ;
break;
}
}
F_32 ( 0 , L_8 , * V_50 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
T_2 V_4 , T_2 V_50 , T_2 * V_38 ,
T_2 V_5 , int V_8 )
{
int V_9 , V_46 = 0 , V_45 = 0 , V_102 = 0 ;
T_1 * V_1 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_11 * V_52 = V_13 -> V_53 ;
struct V_11 * V_117 = NULL ;
struct V_68 * V_118 = NULL ;
struct V_68 * V_75 = NULL ;
struct V_81 * V_114 ;
struct V_54 * V_55 = NULL ;
T_2 V_119 = F_21 ( V_11 -> V_14 ,
V_3 -> V_61 -> V_120 ) ;
T_3 V_57 , V_121 ;
V_57 = F_4 ( V_11 -> V_14 , V_50 ) ;
if ( ( V_8 & V_33 ) && V_5 ) {
F_16 ( ! F_35 ( V_11 ) ) ;
F_16 ( ! V_3 -> V_58 ) ;
V_9 = F_36 ( V_13 , V_3 -> V_58 , 1 ,
& V_55 , NULL ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
return V_9 ;
}
V_9 = F_37 ( V_11 ,
V_3 -> V_58 ,
V_57 ,
V_5 ,
& V_46 ,
& V_45 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
}
V_9 = F_25 ( V_11 , & V_3 -> V_23 , V_5 , 1 ,
& V_3 -> V_36 ,
NULL , V_45 , & V_46 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
V_46 += V_122 + 1 ;
V_117 = F_62 ( V_13 , V_89 ,
V_105 ) ;
if ( ! V_117 ) {
F_32 ( V_123 , L_9 ) ;
V_9 = - V_124 ;
goto V_26;
}
F_38 ( V_117 ) ;
V_9 = F_63 ( V_117 , & V_118 , 1 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_125;
}
F_38 ( V_52 ) ;
V_1 = F_41 ( V_13 , V_46 ) ;
if ( F_42 ( V_1 ) ) {
V_9 = F_43 ( V_1 ) ;
F_6 ( V_9 ) ;
goto V_126;
}
V_121 = F_4 ( V_11 -> V_14 , * V_38 ) ;
V_9 = F_49 ( V_11 , V_121 ,
V_89 ,
V_105 ,
& V_102 , & V_75 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_60;
}
F_59 ( V_11 , V_75 , & V_102 , V_5 , V_119 ,
V_38 ) ;
if ( ! * V_38 ) {
V_9 = - V_64 ;
goto V_60;
}
V_9 = F_1 ( V_1 , V_3 , V_4 , V_5 , V_50 ,
* V_38 , V_8 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_60;
}
V_114 = (struct V_81 * ) V_75 -> V_85 ;
V_9 = F_64 ( V_117 , V_1 , V_118 , V_5 ,
F_55 ( V_114 -> V_127 ) ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_60;
}
V_9 = F_65 ( V_1 , V_117 , V_114 , V_75 ,
V_102 , V_5 ) ;
if ( V_9 ) {
F_66 ( V_117 , V_118 , V_5 ,
F_55 ( V_114 -> V_127 ) ) ;
F_6 ( V_9 ) ;
}
V_9 = F_45 ( V_11 -> V_14 , V_3 -> V_11 , V_4 , V_5 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
V_60:
F_46 ( V_13 , V_1 ) ;
F_56 ( V_75 ) ;
V_126:
F_47 ( V_52 ) ;
F_67 ( V_117 , 1 ) ;
V_125:
F_47 ( V_117 ) ;
F_56 ( V_118 ) ;
F_68 ( V_117 ) ;
V_26:
if ( V_3 -> V_36 ) {
F_33 ( V_3 -> V_36 ) ;
V_3 -> V_36 = NULL ;
}
if ( V_55 )
F_48 ( V_13 , V_55 , 1 ) ;
return V_9 ;
}
static void F_69 ( T_2 * V_128 , T_2 * V_129 ,
T_2 V_130 , int * V_131 )
{
if ( ( * V_128 + * V_129 ) < V_130 ) {
* V_129 += * V_128 ;
} else if ( * V_129 == 0 ) {
* V_131 = 1 ;
} else {
* V_128 = V_130 - * V_129 ;
* V_129 = 0 ;
}
}
static int F_70 ( struct V_68 * V_132 ,
struct V_2 * V_3 )
{
int V_9 = 0 , V_133 , V_134 , V_131 = 0 ;
T_2 V_4 , V_50 , V_135 , V_136 , V_128 ;
T_2 V_129 = 0 , V_137 = 0 , V_38 = 0 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_79 * V_138 = (struct V_79 * ) V_132 -> V_85 ;
struct V_101 * V_61 = V_3 -> V_61 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
if ( ( F_71 ( V_11 ) == 0 ) || ( V_61 -> V_107 == 0 ) )
return 0 ;
if ( F_72 ( V_11 ) -> V_139 & V_140 )
return 0 ;
V_3 -> V_58 = F_53 ( V_138 -> V_141 ) ;
F_73 ( & V_3 -> V_23 , F_12 ( V_11 ) , V_132 ) ;
F_74 ( & V_3 -> V_37 ) ;
V_134 = V_3 -> V_142 ;
V_135 = F_75 ( V_13 -> V_39 , V_61 -> V_143 ) ;
V_136 = ( V_61 -> V_143 + V_61 -> V_107 ) >>
V_13 -> V_90 ;
if ( V_136 >= V_135 )
V_136 -= V_135 ;
else
V_136 = 0 ;
if ( V_134 ) {
V_137 = V_61 -> V_120 >> V_13 -> V_90 ;
if ( V_137 <= 1 )
goto V_144;
} else
V_38 = F_21 ( V_11 -> V_14 ,
V_61 -> V_104 ) ;
F_32 ( 0 , L_10
L_11 ,
( unsigned long long ) F_72 ( V_11 ) -> V_145 ,
( unsigned long long ) V_61 -> V_143 ,
( unsigned long long ) V_61 -> V_107 ,
V_135 , V_136 , V_137 ) ;
V_4 = V_135 ;
while ( V_136 ) {
V_9 = F_76 ( V_11 , V_4 , & V_50 , & V_128 ,
& V_133 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_26;
}
if ( V_128 > V_136 )
V_128 = V_136 ;
if ( ! V_50 ) {
if ( V_134 )
V_129 = 0 ;
goto V_146;
}
if ( V_134 ) {
F_69 ( & V_128 , & V_129 ,
V_137 , & V_131 ) ;
if ( V_131 ) {
V_131 = 0 ;
goto V_146;
}
F_32 ( 0 , L_12
L_13 ,
V_4 , V_50 , V_128 , V_129 ) ;
V_9 = F_34 ( V_3 , V_4 , V_50 ,
& V_128 , V_133 ) ;
} else {
V_9 = F_61 ( V_3 , V_4 , V_50 ,
& V_38 , V_128 ,
V_133 ) ;
V_38 += V_128 ;
}
if ( V_9 < 0 ) {
F_6 ( V_9 ) ;
goto V_26;
}
V_3 -> V_147 += V_128 ;
V_146:
V_4 += V_128 ;
V_136 -= V_128 ;
}
V_144:
V_61 -> V_62 |= V_63 ;
V_26:
V_61 -> V_148 = F_77 ( V_13 -> V_39 ,
V_3 -> V_147 ) ;
V_61 -> V_149 = F_77 ( V_13 -> V_39 ,
V_3 -> V_38 ) ;
F_78 ( V_13 , 1 ) ;
F_79 ( V_13 , & V_3 -> V_37 ) ;
return V_9 ;
}
static int V_101 ( struct V_2 * V_3 )
{
int V_150 ;
T_1 * V_1 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_79 * V_138 ;
struct V_68 * V_132 = NULL ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
if ( F_80 ( V_13 ) || F_81 ( V_13 ) )
return - V_151 ;
F_38 ( V_11 ) ;
V_150 = F_82 ( V_11 , 1 ) ;
if ( V_150 ) {
F_6 ( V_150 ) ;
goto V_26;
}
V_150 = F_63 ( V_11 , & V_132 , 1 ) ;
if ( V_150 ) {
F_6 ( V_150 ) ;
goto V_152;
}
F_83 ( & F_72 ( V_11 ) -> V_153 ) ;
V_150 = F_70 ( V_132 , V_3 ) ;
F_84 ( & F_72 ( V_11 ) -> V_153 ) ;
if ( V_150 ) {
F_6 ( V_150 ) ;
goto V_154;
}
V_1 = F_41 ( V_13 , V_122 ) ;
if ( F_42 ( V_1 ) ) {
V_150 = F_43 ( V_1 ) ;
F_6 ( V_150 ) ;
goto V_154;
}
V_150 = F_17 ( V_1 , F_12 ( V_11 ) , V_132 ,
V_35 ) ;
if ( V_150 ) {
F_6 ( V_150 ) ;
goto V_60;
}
V_138 = (struct V_79 * ) V_132 -> V_85 ;
V_11 -> V_155 = F_85 ( V_11 ) ;
V_138 -> V_155 = F_9 ( V_11 -> V_155 . V_156 ) ;
V_138 -> V_157 = F_7 ( V_11 -> V_155 . V_158 ) ;
F_23 ( V_1 , V_11 , 0 ) ;
F_19 ( V_1 , V_132 ) ;
V_60:
F_46 ( V_13 , V_1 ) ;
V_154:
F_56 ( V_132 ) ;
F_67 ( V_11 , 1 ) ;
V_152:
F_86 ( V_11 , 1 ) ;
V_26:
F_47 ( V_11 ) ;
return V_150 ;
}
int F_87 ( struct V_159 * V_160 , void T_4 * V_161 )
{
int V_150 ;
struct V_11 * V_11 = F_88 ( V_160 ) ;
struct V_101 V_61 ;
struct V_2 * V_3 ;
if ( ! V_161 )
return - V_96 ;
V_150 = F_89 ( V_160 ) ;
if ( V_150 )
return V_150 ;
if ( ( ! F_90 ( V_11 -> V_162 ) ) || ! ( V_160 -> V_163 & V_164 ) ) {
V_150 = - V_165 ;
goto V_166;
}
if ( V_11 -> V_167 & ( V_168 | V_169 ) ) {
V_150 = - V_165 ;
goto V_166;
}
V_3 = F_91 ( sizeof( struct V_2 ) , V_170 ) ;
if ( ! V_3 ) {
V_150 = - V_30 ;
F_6 ( V_150 ) ;
goto V_166;
}
V_3 -> V_11 = V_11 ;
V_3 -> V_159 = V_160 ;
if ( F_92 ( & V_61 , V_161 , sizeof( V_61 ) ) ) {
V_150 = - V_171 ;
goto V_172;
}
if ( V_61 . V_143 > F_71 ( V_11 ) ) {
V_150 = - V_96 ;
goto V_172;
}
if ( V_61 . V_143 + V_61 . V_107 > F_71 ( V_11 ) )
V_61 . V_107 = F_71 ( V_11 ) - V_61 . V_143 ;
V_3 -> V_61 = & V_61 ;
if ( V_61 . V_62 & V_173 ) {
V_3 -> V_142 = 1 ;
if ( ! V_61 . V_120 )
V_61 . V_120 = 1024 * 1024 ;
if ( V_61 . V_120 > F_71 ( V_11 ) )
V_61 . V_120 = F_71 ( V_11 ) ;
if ( V_61 . V_62 & V_174 )
V_3 -> V_51 = 1 ;
} else {
V_150 = F_57 ( V_11 , & V_61 ) ;
if ( V_150 )
goto V_175;
}
V_150 = V_101 ( V_3 ) ;
if ( V_150 )
F_6 ( V_150 ) ;
V_175:
if ( F_93 ( V_161 , & V_61 , sizeof( V_61 ) ) )
V_150 = - V_171 ;
V_172:
F_94 ( V_3 ) ;
V_166:
F_95 ( V_160 ) ;
return V_150 ;
}
