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
V_9 = F_5 ( V_1 , V_3 -> V_26 , V_4 ,
V_6 , V_7 , V_5 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_28 = F_7 ( V_4 ) ;
V_17 . V_29 = F_8 ( V_5 ) ;
V_17 . V_30 = F_9 ( F_4 ( V_11 -> V_14 ,
V_7 ) ) ;
V_19 = F_10 ( & V_3 -> V_23 ) ;
if ( ! V_19 ) {
V_9 = - V_31 ;
F_6 ( V_9 ) ;
goto V_27;
}
V_9 = F_11 ( F_12 ( V_11 ) , V_19 , V_4 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_21 = F_13 ( V_19 ) ;
V_10 = F_14 ( V_21 , V_4 ) ;
if ( V_10 == - 1 || V_10 >= F_15 ( V_21 -> V_32 ) ) {
F_16 ( V_11 -> V_14 ,
L_1
L_2 ,
( unsigned long long ) V_22 , V_4 ) ;
V_9 = - V_33 ;
goto V_27;
}
V_16 = & V_21 -> V_34 [ V_10 ] ;
F_17 ( V_8 != V_16 -> V_35 ) ;
V_17 . V_35 = V_8 & ~ V_36 ;
V_9 = F_18 ( V_1 , F_12 ( V_11 ) ,
V_3 -> V_23 . V_37 ,
V_38 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_9 = F_19 ( V_1 , & V_3 -> V_23 , V_19 , V_10 ,
& V_17 , V_3 -> V_39 ,
& V_3 -> V_40 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
F_20 ( V_1 , V_3 -> V_23 . V_37 ) ;
V_3 -> V_41 = V_7 ;
if ( V_25 ) {
if ( V_8 & V_36 )
V_9 = F_21 ( V_11 , V_1 ,
F_22 ( V_13 -> V_42 ,
V_25 ) ,
V_5 , V_3 -> V_39 ,
& V_3 -> V_40 , 1 ) ;
else
V_9 = F_23 ( V_13 , V_1 ,
V_25 , V_5 ) ;
}
V_27:
return V_9 ;
}
static int F_24 ( struct V_11 * V_11 ,
struct V_43 * V_23 ,
T_2 V_44 ,
T_2 V_45 ,
struct V_46 * * V_39 ,
struct V_46 * * V_47 ,
int V_48 ,
int * V_49 )
{
int V_9 , V_50 ;
unsigned int V_51 = 2 * V_45 + V_44 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
V_50 = F_25 ( V_13 , V_23 ) ;
if ( V_50 < 0 ) {
V_9 = V_50 ;
F_6 ( V_9 ) ;
goto V_27;
}
if ( ! V_50 ||
( F_26 ( V_13 ) && V_50 < V_51 ) )
V_48 += F_27 ( V_23 -> V_52 ) ;
V_9 = F_28 ( V_13 , V_48 , V_39 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
if ( V_47 ) {
V_9 = F_29 ( V_13 , V_44 , V_47 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
}
* V_49 += F_30 ( V_13 -> V_42 , V_23 -> V_52 ,
V_44 + 2 ) ;
F_31 ( 0 , L_3 ,
V_48 , V_44 , * V_49 ) ;
V_27:
if ( V_9 ) {
if ( * V_39 ) {
F_32 ( * V_39 ) ;
* V_39 = NULL ;
}
}
return V_9 ;
}
static int F_33 ( struct V_2 * V_3 ,
T_2 V_4 , T_2 V_53 , T_2 * V_5 , int V_8 )
{
int V_9 , V_49 = 0 , V_48 = 0 , V_54 = V_3 -> V_54 ;
T_1 * V_1 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_11 * V_55 = V_13 -> V_56 ;
struct V_57 * V_58 = NULL ;
T_2 V_41 , V_59 ;
T_3 V_60 = F_4 ( V_11 -> V_14 , V_53 ) ;
if ( ( V_8 & V_36 ) && * V_5 ) {
F_17 ( ! ( F_34 ( V_11 ) -> V_61 &
V_62 ) ) ;
F_17 ( ! V_3 -> V_63 ) ;
V_9 = F_35 ( V_13 , V_3 -> V_63 , 1 ,
& V_58 , NULL ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
return V_9 ;
}
V_9 = F_36 ( V_11 ,
V_3 -> V_63 ,
V_60 ,
* V_5 ,
& V_49 ,
& V_48 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
}
V_9 = F_24 ( V_11 , & V_3 -> V_23 , * V_5 , 1 ,
& V_3 -> V_39 ,
& V_3 -> V_47 ,
V_48 , & V_49 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
F_37 ( & V_55 -> V_64 ) ;
if ( F_38 ( V_13 ) ) {
V_9 = F_39 ( V_13 ) ;
if ( V_9 < 0 ) {
F_6 ( V_9 ) ;
goto V_65;
}
}
V_1 = F_40 ( V_13 , V_49 ) ;
if ( F_41 ( V_1 ) ) {
V_9 = F_42 ( V_1 ) ;
F_6 ( V_9 ) ;
goto V_65;
}
V_9 = F_43 ( V_1 , V_3 -> V_47 , 1 , * V_5 ,
& V_41 , & V_59 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_66;
}
if ( V_59 != * V_5 ) {
F_31 ( 0 , L_4 , V_59 , * V_5 ) ;
if ( ! V_54 ) {
V_3 -> V_67 -> V_68 &= ~ V_69 ;
V_9 = - V_70 ;
goto V_66;
}
}
F_31 ( 0 , L_5 , V_4 ,
V_53 , V_41 ) ;
V_9 = F_1 ( V_1 , V_3 , V_4 , V_59 , V_53 ,
V_41 , V_8 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
if ( V_54 && ( V_59 != * V_5 ) )
* V_5 = V_59 ;
V_9 = F_44 ( V_11 -> V_14 , V_3 -> V_11 , V_4 , * V_5 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
V_66:
F_45 ( V_13 , V_1 ) ;
V_65:
F_46 ( & V_55 -> V_64 ) ;
if ( V_3 -> V_47 ) {
F_32 ( V_3 -> V_47 ) ;
V_3 -> V_47 = NULL ;
}
if ( V_3 -> V_39 ) {
F_32 ( V_3 -> V_39 ) ;
V_3 -> V_39 = NULL ;
}
V_27:
if ( V_58 )
F_47 ( V_13 , V_58 , 1 ) ;
return V_9 ;
}
static int F_48 ( struct V_11 * V_11 ,
T_3 V_71 ,
int type , int V_72 ,
int * V_73 ,
struct V_74 * * V_75 )
{
int V_9 , V_76 , V_77 = 0 ;
T_3 V_78 ;
char V_79 [ 40 ] ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_74 * V_80 = NULL , * V_81 = NULL ;
struct V_82 * V_83 ;
struct V_84 * V_16 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
F_49 ( V_79 , sizeof( V_79 ) , type , V_72 ) ;
V_9 = F_50 ( V_13 -> V_89 , V_79 ,
strlen ( V_79 ) , & V_78 ) ;
if ( V_9 ) {
V_9 = - V_90 ;
goto V_27;
}
V_9 = F_51 ( V_13 , V_78 , 1 , & V_80 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_86 = (struct V_85 * ) V_80 -> V_91 ;
V_83 = & ( V_86 -> V_92 . V_93 ) ;
V_16 = & ( V_83 -> V_94 [ 0 ] ) ;
if ( type == V_95 )
V_77 = V_13 -> V_96 -
V_11 -> V_14 -> V_97 ;
if ( ( V_71 < F_52 ( V_16 -> V_98 ) ) ||
( V_71 >= ( F_53 ( V_86 -> V_99 . V_100 . V_101 ) <<
V_77 ) ) ) {
V_9 = - V_102 ;
goto V_27;
}
for ( V_76 = 0 ; V_76 < F_15 ( V_83 -> V_103 ) ; V_76 ++ ) {
V_16 = & ( V_83 -> V_94 [ V_76 ] ) ;
if ( ! V_16 )
continue;
V_88 = NULL ;
do {
if ( ! V_88 )
V_78 = F_52 ( V_16 -> V_98 ) ;
else
V_78 = F_52 ( V_88 -> V_104 ) ;
if ( V_81 ) {
F_54 ( V_81 ) ;
V_81 = NULL ;
}
V_9 = F_51 ( V_13 , V_78 , 1 , & V_81 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_88 = (struct V_87 * ) V_81 -> V_91 ;
if ( V_71 < ( F_52 ( V_88 -> V_105 ) +
F_15 ( V_88 -> V_106 ) ) ) {
* V_75 = V_81 ;
* V_73 = ( V_71 - V_78 ) >>
V_77 ;
F_31 ( 0 , L_6
L_7 ,
V_78 , F_15 ( V_88 -> V_106 ) ,
* V_73 ) ;
goto V_27;
}
} while ( F_52 ( V_88 -> V_104 ) );
}
V_9 = - V_102 ;
V_27:
F_54 ( V_80 ) ;
return V_9 ;
}
static int F_55 ( struct V_11 * V_11 ,
struct V_107 * V_67 )
{
int V_9 , V_108 = 0 ;
struct V_74 * V_81 = NULL ;
struct V_87 * V_88 = NULL ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
int V_109 = 1 << ( V_13 -> V_96 -
V_11 -> V_14 -> V_97 ) ;
V_67 -> V_110 = F_56 ( V_11 -> V_14 ,
V_67 -> V_110 ) ;
if ( V_67 -> V_110 == F_52 ( V_88 -> V_105 ) )
V_67 -> V_110 += V_109 ;
V_9 = F_48 ( V_11 , V_67 -> V_110 ,
V_95 ,
V_111 ,
& V_108 , & V_81 ) ;
if ( V_9 )
goto V_27;
V_88 = (struct V_87 * ) V_81 -> V_91 ;
if ( ( F_15 ( V_88 -> V_106 ) - V_108 ) * V_13 -> V_112 <
V_67 -> V_113 ) {
V_9 = - V_102 ;
goto V_27;
}
F_31 ( 0 , L_8 ,
V_67 -> V_110 ) ;
V_27:
F_54 ( V_81 ) ;
return V_9 ;
}
static void F_57 ( struct V_11 * V_11 , struct V_74 * V_114 ,
int * V_108 , T_2 V_115 , T_2 V_116 ,
T_2 * V_53 )
{
int V_76 , V_117 , V_118 = 0 , V_119 = * V_108 ;
struct V_87 * V_120 = (struct V_87 * ) V_114 -> V_91 ;
T_2 V_121 = F_22 ( V_11 -> V_14 ,
F_52 ( V_120 -> V_105 ) ) ;
for ( V_76 = V_119 ; V_76 < F_15 ( V_120 -> V_106 ) ; V_76 ++ ) {
V_117 = F_58 ( V_76 , ( unsigned long * ) V_120 -> V_122 ) ;
if ( V_117 ) {
if ( ( V_76 - V_119 ) > V_116 ) {
* V_53 = 0 ;
break;
}
if ( V_118 )
V_118 = 0 ;
continue;
} else
V_118 ++ ;
if ( V_118 == V_115 ) {
* V_108 = V_76 ;
* V_53 = V_121 + V_76 ;
break;
}
}
F_31 ( 0 , L_9 , * V_53 ) ;
}
static int F_59 ( struct V_11 * V_11 ,
T_1 * V_1 ,
struct V_74 * V_123 ,
T_2 V_124 ,
T_4 V_125 )
{
int V_9 ;
T_2 V_126 ;
struct V_85 * V_127 = (struct V_85 * ) V_123 -> V_91 ;
struct V_82 * V_83 =
(struct V_82 * ) & V_127 -> V_92 . V_93 ;
V_9 = F_18 ( V_1 , F_12 ( V_11 ) , V_123 ,
V_38 ) ;
if ( V_9 < 0 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_126 = F_53 ( V_127 -> V_99 . V_100 . V_128 ) ;
V_127 -> V_99 . V_100 . V_128 = F_7 ( V_124 + V_126 ) ;
F_60 ( & V_83 -> V_94 [ V_125 ] . V_129 , - V_124 ) ;
F_20 ( V_1 , V_123 ) ;
V_27:
return V_9 ;
}
static inline int F_61 ( T_1 * V_1 ,
struct V_11 * V_130 ,
struct V_87 * V_88 ,
struct V_74 * V_131 ,
unsigned int V_132 ,
unsigned int V_124 )
{
int V_133 ;
void * V_134 = V_88 -> V_122 ;
int V_135 = V_38 ;
F_17 ( ! F_62 ( V_88 ) ) ;
F_17 ( F_15 ( V_88 -> V_136 ) < V_124 ) ;
F_31 ( 0 , L_10 , V_132 ,
V_124 ) ;
if ( F_63 ( V_130 ) )
V_135 = V_137 ;
V_133 = F_64 ( V_1 ,
F_12 ( V_130 ) ,
V_131 ,
V_135 ) ;
if ( V_133 < 0 ) {
F_6 ( V_133 ) ;
goto V_138;
}
F_65 ( & V_88 -> V_136 , - V_124 ) ;
if ( F_15 ( V_88 -> V_136 ) > F_15 ( V_88 -> V_106 ) ) {
F_16 ( V_130 -> V_14 , L_11
L_12 ,
( unsigned long long ) F_52 ( V_88 -> V_105 ) ,
F_15 ( V_88 -> V_106 ) ,
F_15 ( V_88 -> V_136 ) , V_124 ) ;
return - V_33 ;
}
while ( V_124 -- )
F_66 ( V_132 ++ , V_134 ) ;
F_20 ( V_1 , V_131 ) ;
V_138:
return V_133 ;
}
static int F_67 ( struct V_2 * V_3 ,
T_2 V_4 , T_2 V_53 , T_2 * V_41 ,
T_2 V_5 , int V_8 )
{
int V_9 , V_49 = 0 , V_48 = 0 , V_108 = 0 ;
T_1 * V_1 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
struct V_11 * V_55 = V_13 -> V_56 ;
struct V_11 * V_139 = NULL ;
struct V_74 * V_140 = NULL ;
struct V_74 * V_81 = NULL ;
struct V_87 * V_120 ;
struct V_57 * V_58 = NULL ;
T_2 V_141 = F_22 ( V_11 -> V_14 ,
V_3 -> V_67 -> V_142 ) ;
T_3 V_60 , V_143 ;
V_60 = F_4 ( V_11 -> V_14 , V_53 ) ;
if ( ( V_8 & V_36 ) && V_5 ) {
F_17 ( ! ( F_34 ( V_11 ) -> V_61 &
V_62 ) ) ;
F_17 ( ! V_3 -> V_63 ) ;
V_9 = F_35 ( V_13 , V_3 -> V_63 , 1 ,
& V_58 , NULL ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
return V_9 ;
}
V_9 = F_36 ( V_11 ,
V_3 -> V_63 ,
V_60 ,
V_5 ,
& V_49 ,
& V_48 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
}
V_9 = F_24 ( V_11 , & V_3 -> V_23 , V_5 , 1 ,
& V_3 -> V_39 ,
NULL , V_48 , & V_49 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_49 += V_144 + 1 ;
V_139 = F_68 ( V_13 , V_95 ,
V_111 ) ;
if ( ! V_139 ) {
F_31 ( V_145 , L_13 ) ;
V_9 = - V_146 ;
goto V_27;
}
F_37 ( & V_139 -> V_64 ) ;
V_9 = F_69 ( V_139 , & V_140 , 1 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_147;
}
F_37 ( & V_55 -> V_64 ) ;
V_1 = F_40 ( V_13 , V_49 ) ;
if ( F_41 ( V_1 ) ) {
V_9 = F_42 ( V_1 ) ;
F_6 ( V_9 ) ;
goto V_148;
}
V_143 = F_4 ( V_11 -> V_14 , * V_41 ) ;
V_9 = F_48 ( V_11 , V_143 ,
V_95 ,
V_111 ,
& V_108 , & V_81 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_66;
}
F_57 ( V_11 , V_81 , & V_108 , V_5 , V_141 ,
V_41 ) ;
if ( ! * V_41 ) {
V_9 = - V_70 ;
goto V_66;
}
V_9 = F_1 ( V_1 , V_3 , V_4 , V_5 , V_53 ,
* V_41 , V_8 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_66;
}
V_120 = (struct V_87 * ) V_81 -> V_91 ;
V_9 = F_59 ( V_139 , V_1 , V_140 , V_5 ,
F_15 ( V_120 -> V_149 ) ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_66;
}
V_9 = F_61 ( V_1 , V_139 , V_120 , V_81 ,
V_108 , V_5 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
V_9 = F_44 ( V_11 -> V_14 , V_3 -> V_11 , V_4 , V_5 ) ;
if ( V_9 )
F_6 ( V_9 ) ;
V_66:
F_45 ( V_13 , V_1 ) ;
F_54 ( V_81 ) ;
V_148:
F_46 ( & V_55 -> V_64 ) ;
F_70 ( V_139 , 1 ) ;
V_147:
F_46 ( & V_139 -> V_64 ) ;
F_54 ( V_140 ) ;
F_71 ( V_139 ) ;
V_27:
if ( V_3 -> V_39 ) {
F_32 ( V_3 -> V_39 ) ;
V_3 -> V_39 = NULL ;
}
if ( V_58 )
F_47 ( V_13 , V_58 , 1 ) ;
return V_9 ;
}
static void F_72 ( T_2 * V_150 , T_2 * V_151 ,
T_2 V_152 , int * V_153 )
{
if ( ( * V_150 + * V_151 ) < V_152 ) {
* V_151 += * V_150 ;
} else if ( * V_151 == 0 ) {
* V_153 = 1 ;
} else {
* V_150 = V_152 - * V_151 ;
* V_151 = 0 ;
}
}
static int F_73 ( struct V_74 * V_123 ,
struct V_2 * V_3 )
{
int V_9 = 0 , V_154 , V_155 , V_153 = 0 ;
T_2 V_4 , V_53 , V_156 , V_157 , V_150 ;
T_2 V_151 = 0 , V_158 = 0 , V_41 = 0 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_85 * V_127 = (struct V_85 * ) V_123 -> V_91 ;
struct V_107 * V_67 = V_3 -> V_67 ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
if ( ( V_11 -> V_159 == 0 ) || ( V_67 -> V_113 == 0 ) )
return 0 ;
if ( F_34 ( V_11 ) -> V_61 & V_160 )
return 0 ;
V_3 -> V_63 = F_52 ( V_127 -> V_161 ) ;
F_74 ( & V_3 -> V_23 , F_12 ( V_11 ) , V_123 ) ;
F_75 ( & V_3 -> V_40 ) ;
V_155 = V_3 -> V_162 ;
V_156 = F_76 ( V_13 -> V_42 , V_67 -> V_163 ) ;
V_157 = ( V_67 -> V_163 + V_67 -> V_113 ) >>
V_13 -> V_96 ;
if ( V_157 >= V_156 )
V_157 -= V_156 ;
else
V_157 = 0 ;
if ( V_155 ) {
V_158 = V_67 -> V_142 >> V_13 -> V_96 ;
if ( V_158 <= 1 )
goto V_164;
} else
V_41 = F_22 ( V_11 -> V_14 ,
V_67 -> V_110 ) ;
F_31 ( 0 , L_14
L_15 ,
( unsigned long long ) F_34 ( V_11 ) -> V_165 ,
( unsigned long long ) V_67 -> V_163 ,
( unsigned long long ) V_67 -> V_113 ,
V_156 , V_157 , V_158 ) ;
V_4 = V_156 ;
while ( V_157 ) {
V_9 = F_77 ( V_11 , V_4 , & V_53 , & V_150 ,
& V_154 ) ;
if ( V_9 ) {
F_6 ( V_9 ) ;
goto V_27;
}
if ( V_150 > V_157 )
V_150 = V_157 ;
if ( ! V_53 ) {
if ( V_155 )
V_151 = 0 ;
goto V_166;
}
if ( V_155 ) {
F_72 ( & V_150 , & V_151 ,
V_158 , & V_153 ) ;
if ( V_153 ) {
V_153 = 0 ;
goto V_166;
}
F_31 ( 0 , L_16
L_17 ,
V_4 , V_53 , V_150 , V_151 ) ;
V_9 = F_33 ( V_3 , V_4 , V_53 ,
& V_150 , V_154 ) ;
} else {
V_9 = F_67 ( V_3 , V_4 , V_53 ,
& V_41 , V_150 ,
V_154 ) ;
V_41 += V_150 ;
}
if ( V_9 < 0 ) {
F_6 ( V_9 ) ;
goto V_27;
}
V_3 -> V_167 += V_150 ;
V_166:
V_4 += V_150 ;
V_157 -= V_150 ;
}
V_164:
V_67 -> V_68 |= V_69 ;
V_27:
V_67 -> V_168 = F_78 ( V_13 -> V_42 ,
V_3 -> V_167 ) ;
V_67 -> V_169 = F_78 ( V_13 -> V_42 ,
V_3 -> V_41 ) ;
F_79 ( V_13 , 1 ) ;
F_80 ( V_13 , & V_3 -> V_40 ) ;
return V_9 ;
}
static int V_107 ( struct V_2 * V_3 )
{
int V_133 ;
T_1 * V_1 ;
struct V_11 * V_11 = V_3 -> V_11 ;
struct V_85 * V_127 ;
struct V_74 * V_123 = NULL ;
struct V_12 * V_13 = F_2 ( V_11 -> V_14 ) ;
if ( ! V_11 )
return - V_90 ;
if ( F_81 ( V_13 ) || F_82 ( V_13 ) )
return - V_33 ;
F_37 ( & V_11 -> V_64 ) ;
V_133 = F_83 ( V_11 , 1 ) ;
if ( V_133 ) {
F_6 ( V_133 ) ;
goto V_27;
}
V_133 = F_69 ( V_11 , & V_123 , 1 ) ;
if ( V_133 ) {
F_6 ( V_133 ) ;
goto V_170;
}
F_84 ( & F_34 ( V_11 ) -> V_171 ) ;
V_133 = F_73 ( V_123 , V_3 ) ;
F_85 ( & F_34 ( V_11 ) -> V_171 ) ;
if ( V_133 ) {
F_6 ( V_133 ) ;
goto V_172;
}
V_1 = F_40 ( V_13 , V_144 ) ;
if ( F_41 ( V_1 ) ) {
V_133 = F_42 ( V_1 ) ;
F_6 ( V_133 ) ;
goto V_172;
}
V_133 = F_18 ( V_1 , F_12 ( V_11 ) , V_123 ,
V_38 ) ;
if ( V_133 ) {
F_6 ( V_133 ) ;
goto V_66;
}
V_127 = (struct V_85 * ) V_123 -> V_91 ;
V_11 -> V_173 = V_174 ;
V_127 -> V_173 = F_9 ( V_11 -> V_173 . V_175 ) ;
V_127 -> V_176 = F_7 ( V_11 -> V_173 . V_177 ) ;
F_20 ( V_1 , V_123 ) ;
V_66:
F_45 ( V_13 , V_1 ) ;
V_172:
F_54 ( V_123 ) ;
F_70 ( V_11 , 1 ) ;
V_170:
F_86 ( V_11 , 1 ) ;
V_27:
F_46 ( & V_11 -> V_64 ) ;
return V_133 ;
}
int F_87 ( struct V_26 * V_178 , void T_5 * V_179 )
{
int V_133 ;
struct V_11 * V_11 = F_88 ( V_178 ) ;
struct V_107 V_67 ;
struct V_2 * V_3 = NULL ;
V_133 = F_89 ( V_178 ) ;
if ( V_133 )
return V_133 ;
if ( ( ! F_90 ( V_11 -> V_180 ) ) || ! ( V_178 -> V_181 & V_182 ) )
goto V_27;
if ( V_11 -> V_183 & ( V_184 | V_185 ) ) {
V_133 = - V_186 ;
goto V_27;
}
V_3 = F_91 ( sizeof( struct V_2 ) , V_187 ) ;
if ( ! V_3 ) {
V_133 = - V_31 ;
F_6 ( V_133 ) ;
goto V_27;
}
V_3 -> V_11 = V_11 ;
V_3 -> V_26 = V_178 ;
if ( V_179 ) {
if ( F_92 ( & V_67 , V_179 , sizeof( V_67 ) ) ) {
V_133 = - V_188 ;
goto V_27;
}
} else {
V_133 = - V_102 ;
goto V_27;
}
if ( V_67 . V_163 > F_93 ( V_11 ) )
goto V_27;
if ( V_67 . V_163 + V_67 . V_113 > F_93 ( V_11 ) )
V_67 . V_113 = F_93 ( V_11 ) - V_67 . V_163 ;
V_3 -> V_67 = & V_67 ;
if ( V_67 . V_68 & V_189 ) {
V_3 -> V_162 = 1 ;
if ( ! V_67 . V_142 )
V_67 . V_142 = 1024 * 1024 ;
if ( V_67 . V_142 > F_93 ( V_11 ) )
V_67 . V_142 = F_93 ( V_11 ) ;
if ( V_67 . V_68 & V_190 )
V_3 -> V_54 = 1 ;
} else {
V_133 = F_55 ( V_11 , & V_67 ) ;
if ( V_133 )
goto V_27;
}
V_133 = V_107 ( V_3 ) ;
if ( V_133 )
F_6 ( V_133 ) ;
V_27:
if ( V_179 ) {
if ( F_94 ( V_179 , & V_67 , sizeof( V_67 ) ) )
V_133 = - V_188 ;
}
F_95 ( V_3 ) ;
F_96 ( V_178 ) ;
return V_133 ;
}
