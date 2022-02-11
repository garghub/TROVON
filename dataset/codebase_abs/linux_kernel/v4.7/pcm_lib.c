void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_8 ;
if ( V_5 -> V_9 < V_5 -> V_10 ) {
T_2 V_11 , V_12 ;
if ( V_5 -> V_13 != V_5 -> V_14 -> V_15 ) {
V_12 = V_5 -> V_14 -> V_15 - V_5 -> V_13 ;
if ( V_12 < 0 )
V_12 += V_5 -> V_10 ;
if ( ( T_1 ) V_12 < V_5 -> V_16 )
V_5 -> V_16 -= V_12 ;
else
V_5 -> V_16 = 0 ;
V_5 -> V_13 = V_5 -> V_14 -> V_15 ;
}
if ( V_5 -> V_16 >= V_5 -> V_17 )
return;
V_11 = F_2 ( V_5 ) + V_5 -> V_16 ;
if ( V_11 >= ( T_2 ) V_5 -> V_18 )
return;
V_6 = V_5 -> V_18 - V_11 ;
if ( V_6 > V_5 -> V_9 )
V_6 = V_5 -> V_9 ;
} else {
if ( V_3 == V_19 ) {
T_2 V_20 = F_2 ( V_5 ) ;
if ( V_20 > V_5 -> V_17 )
V_20 = V_5 -> V_17 ;
V_5 -> V_16 = V_20 > 0 ? V_20 : 0 ;
V_5 -> V_13 = ( V_5 -> V_21 -> V_22 +
V_5 -> V_16 ) %
V_5 -> V_10 ;
} else {
V_7 = V_5 -> V_21 -> V_22 ;
V_6 = V_3 - V_7 ;
if ( ( T_2 ) V_6 < 0 )
V_6 += V_5 -> V_10 ;
V_5 -> V_16 -= V_6 ;
if ( ( T_2 ) V_5 -> V_16 < 0 ) {
V_5 -> V_16 = 0 ;
V_5 -> V_13 = V_3 ;
} else {
V_5 -> V_13 = V_7 ;
}
}
V_6 = V_5 -> V_17 - V_5 -> V_16 ;
}
if ( F_3 ( V_6 > V_5 -> V_17 ) )
return;
if ( V_6 == 0 )
return;
V_7 = V_5 -> V_13 % V_5 -> V_17 ;
while ( V_6 > 0 ) {
V_8 = V_7 + V_6 > V_5 -> V_17 ? V_5 -> V_17 - V_7 : V_6 ;
if ( V_5 -> V_23 == V_24 ||
V_5 -> V_23 == V_25 ) {
if ( V_2 -> V_26 -> V_27 ) {
int V_28 ;
V_28 = V_2 -> V_26 -> V_27 ( V_2 , - 1 , V_7 , V_8 ) ;
F_3 ( V_28 < 0 ) ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_7 ) ;
F_5 ( V_5 -> V_31 , V_29 , V_8 * V_5 -> V_32 ) ;
}
} else {
unsigned int V_33 ;
unsigned int V_32 = V_5 -> V_32 ;
if ( V_2 -> V_26 -> V_27 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 ) {
int V_28 ;
V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_7 , V_8 ) ;
F_3 ( V_28 < 0 ) ;
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_7 ) ;
F_5 ( V_5 -> V_31 , V_29 , V_8 ) ;
}
}
}
V_5 -> V_16 += V_8 ;
V_6 -= V_8 ;
V_7 = 0 ;
}
}
void F_7 ( struct V_1 * V_2 ,
char * V_36 , T_3 V_37 )
{
snprintf ( V_36 , V_37 , L_1 ,
V_2 -> V_38 -> V_39 -> V_40 ,
V_2 -> V_38 -> V_41 ,
V_2 -> V_42 ? 'c' : 'p' ,
V_2 -> V_40 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_9 ( V_2 ) ;
if ( V_5 -> V_43 == V_44 )
F_10 ( V_5 , (struct V_45 * ) & V_5 -> V_21 -> V_46 ) ;
F_11 ( V_2 , V_47 ) ;
if ( F_12 ( V_2 , V_48 ) ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_13 ( V_2 -> V_38 , L_2 , V_36 ) ;
F_14 ( V_2 ) ;
}
}
int F_15 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_1 V_20 ;
if ( V_2 -> V_42 == V_49 )
V_20 = F_16 ( V_5 ) ;
else
V_20 = F_17 ( V_5 ) ;
if ( V_20 > V_5 -> V_50 )
V_5 -> V_50 = V_20 ;
if ( V_5 -> V_21 -> V_51 == V_52 ) {
if ( V_20 >= V_5 -> V_17 ) {
F_18 ( V_2 ) ;
return - V_53 ;
}
} else {
if ( V_20 >= V_5 -> V_54 ) {
F_8 ( V_2 ) ;
return - V_53 ;
}
}
if ( V_5 -> V_55 ) {
if ( V_20 >= V_5 -> V_55 )
F_19 ( & V_5 -> V_56 ) ;
} else if ( V_20 >= V_5 -> V_14 -> V_57 )
F_19 ( & V_5 -> V_58 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_45 * V_59 ,
struct V_45 * V_60 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_61 , V_62 ;
struct V_45 V_63 ;
if ( V_5 -> V_43 != V_44 )
return;
if ( ! ( V_2 -> V_26 -> V_64 ) ||
( V_5 -> V_65 . V_66 ==
V_67 ) ) {
V_61 = V_5 -> V_68 + V_5 -> V_21 -> V_22 ;
if ( V_5 -> V_69 . V_70 ) {
if ( V_2 -> V_42 == V_49 )
V_61 -= V_5 -> V_71 ;
else
V_61 += V_5 -> V_71 ;
}
V_62 = F_21 ( V_61 * 1000000000LL ,
V_5 -> V_72 ) ;
* V_60 = F_22 ( V_62 ) ;
}
V_5 -> V_21 -> V_60 = * V_60 ;
V_5 -> V_21 -> V_46 = * V_59 ;
F_10 ( V_2 -> V_5 , (struct V_45 * ) & V_63 ) ;
V_5 -> V_63 = V_63 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_73 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_74 ;
T_1 V_75 , V_3 , V_76 ;
T_2 V_77 , V_78 ;
unsigned long V_79 ;
unsigned long V_80 ;
struct V_45 V_59 ;
struct V_45 V_60 ;
int V_81 = 0 ;
V_75 = V_5 -> V_21 -> V_22 ;
V_74 = V_2 -> V_26 -> V_82 ( V_2 ) ;
V_80 = V_83 ;
if ( V_5 -> V_43 == V_44 ) {
if ( ( V_2 -> V_26 -> V_64 ) &&
( V_5 -> V_69 . V_84 != V_67 ) ) {
V_2 -> V_26 -> V_64 ( V_2 , & V_59 ,
& V_60 ,
& V_5 -> V_69 ,
& V_5 -> V_65 ) ;
if ( V_5 -> V_65 . V_66 == V_67 )
F_10 ( V_5 , (struct V_45 * ) & V_59 ) ;
} else
F_10 ( V_5 , (struct V_45 * ) & V_59 ) ;
}
if ( V_74 == V_85 ) {
F_8 ( V_2 ) ;
return - V_53 ;
}
if ( V_74 >= V_5 -> V_17 ) {
if ( F_24 () ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_25 ( V_2 -> V_38 ,
L_3 ,
V_36 , V_74 , V_5 -> V_17 ,
V_5 -> V_86 ) ;
}
V_74 = 0 ;
}
V_74 -= V_74 % V_5 -> V_87 ;
F_26 ( V_2 , V_74 , V_73 ) ;
V_76 = V_5 -> V_88 ;
V_3 = V_76 + V_74 ;
if ( V_73 ) {
V_78 = V_5 -> V_89 + V_5 -> V_86 ;
if ( V_78 > V_3 ) {
V_77 = V_80 - V_5 -> V_90 ;
if ( V_77 > V_5 -> V_91 / 2 + 1 ) {
V_76 += V_5 -> V_17 ;
if ( V_76 >= V_5 -> V_10 ) {
V_76 = 0 ;
V_81 ++ ;
}
V_3 = V_76 + V_74 ;
goto V_92;
}
}
}
if ( V_3 < V_75 ) {
V_76 += V_5 -> V_17 ;
if ( V_76 >= V_5 -> V_10 ) {
V_76 = 0 ;
V_81 ++ ;
}
V_3 = V_76 + V_74 ;
}
V_92:
V_78 = V_3 - V_75 ;
if ( V_78 < 0 )
V_78 += V_5 -> V_10 ;
if ( V_5 -> V_93 ) {
T_2 V_94 ;
V_79 = V_80 - V_5 -> V_90 ;
if ( V_79 < V_5 -> V_91 / 2 )
goto V_95;
V_77 = V_79 - V_78 * V_96 / V_5 -> V_72 ;
V_94 = V_5 -> V_91 / 2 + 1 ;
while ( V_77 > V_94 ) {
V_78 += V_5 -> V_17 ;
V_76 += V_5 -> V_17 ;
if ( V_76 >= V_5 -> V_10 ) {
V_76 = 0 ;
V_81 ++ ;
}
V_3 = V_76 + V_74 ;
V_77 -= V_5 -> V_91 ;
}
goto V_95;
}
if ( V_78 >= V_5 -> V_17 + V_5 -> V_86 ) {
F_27 ( V_2 , V_73 , L_4 ,
L_5 ,
V_2 -> V_42 , ( long ) V_74 ,
( long ) V_3 , ( long ) V_75 ) ;
return 0 ;
}
if ( ! F_12 ( V_2 , V_97 ) )
goto V_98;
if ( V_5 -> V_99 . V_100 & V_101 )
goto V_98;
V_77 = V_78 ;
if ( V_77 < V_5 -> V_71 )
goto V_98;
V_77 -= V_5 -> V_71 ;
V_79 = V_80 - V_5 -> V_90 ;
if ( ( ( V_77 * V_96 ) / V_5 -> V_72 ) > V_79 + V_96 / 100 ) {
V_78 = V_79 /
( ( ( V_5 -> V_86 * V_96 ) / V_5 -> V_72 )
+ V_96 / 100 ) ;
V_3 = V_75 ;
V_76 = V_78 ;
while ( V_78 > 0 ) {
V_3 += V_5 -> V_86 ;
if ( V_3 >= V_5 -> V_10 ) {
V_3 -= V_5 -> V_10 ;
V_81 -- ;
}
V_78 -- ;
}
F_27 ( V_2 , V_73 , L_6 ,
L_7 ,
( long ) V_74 , ( long ) V_77 ,
( long ) V_5 -> V_86 , V_79 ,
( ( V_77 * V_96 ) / V_5 -> V_72 ) , V_76 ,
( unsigned long ) V_75 ,
( unsigned long ) V_3 ) ;
V_78 = 0 ;
V_76 = V_3 - ( V_3 % V_5 -> V_17 ) ;
}
V_98:
if ( V_78 > V_5 -> V_86 + V_5 -> V_86 / 2 ) {
F_27 ( V_2 , V_73 ,
L_8 ,
L_9 ,
V_2 -> V_42 , ( long ) V_78 ,
( long ) V_3 ,
( long ) V_75 ) ;
}
V_95:
if ( V_5 -> V_21 -> V_22 == V_3 ) {
F_20 ( V_2 , & V_59 , & V_60 ) ;
return 0 ;
}
if ( V_2 -> V_42 == V_49 &&
V_5 -> V_9 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_73 ) {
V_78 = V_3 - V_5 -> V_89 ;
if ( V_78 < 0 )
V_78 += V_5 -> V_10 ;
V_78 -= ( T_1 ) V_78 % V_5 -> V_86 ;
V_5 -> V_89 += V_78 ;
if ( V_5 -> V_89 >= V_5 -> V_10 )
V_5 -> V_89 -= V_5 -> V_10 ;
}
V_5 -> V_88 = V_76 ;
V_5 -> V_21 -> V_22 = V_3 ;
V_5 -> V_90 = V_80 ;
if ( V_81 ) {
F_3 ( V_81 != 1 ) ;
V_5 -> V_68 += V_5 -> V_10 ;
}
F_20 ( V_2 , & V_59 , & V_60 ) ;
return F_15 ( V_2 , V_5 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , 0 ) ;
}
void F_29 ( struct V_102 * V_38 , int V_103 ,
const struct V_104 * V_26 )
{
struct V_105 * V_42 = & V_38 -> V_106 [ V_103 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_42 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_107 )
V_2 -> V_26 = V_26 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_108 . V_109 [ 0 ] = V_2 -> V_38 -> V_39 -> V_40 ;
V_5 -> V_108 . V_109 [ 1 ] = - 1 ;
V_5 -> V_108 . V_109 [ 2 ] = - 1 ;
V_5 -> V_108 . V_109 [ 3 ] = - 1 ;
}
static inline unsigned int F_31 ( unsigned int V_110 , unsigned int V_111 ,
unsigned int * V_112 )
{
if ( V_111 == 0 ) {
* V_112 = 0 ;
return V_113 ;
}
* V_112 = V_110 % V_111 ;
return V_110 / V_111 ;
}
static inline unsigned int F_32 ( unsigned int V_110 , unsigned int V_111 )
{
if ( V_111 == 0 )
return V_113 ;
return V_110 / V_111 ;
}
static inline unsigned int F_33 ( unsigned int V_110 , unsigned int V_111 )
{
unsigned int V_112 ;
unsigned int V_114 ;
if ( V_111 == 0 )
return V_113 ;
V_114 = F_31 ( V_110 , V_111 , & V_112 ) ;
if ( V_112 )
++ V_114 ;
return V_114 ;
}
static inline unsigned int F_34 ( unsigned int V_110 , unsigned int V_111 )
{
if ( V_110 == 0 )
return 0 ;
if ( F_32 ( V_113 , V_110 ) < V_111 )
return V_113 ;
return V_110 * V_111 ;
}
static inline unsigned int F_35 ( unsigned int V_110 , unsigned int V_111 ,
unsigned int V_33 , unsigned int * V_112 )
{
T_5 V_12 = ( T_5 ) V_110 * V_111 ;
if ( V_33 == 0 ) {
F_3 ( ! V_12 ) ;
* V_112 = 0 ;
return V_113 ;
}
V_12 = F_36 ( V_12 , V_33 , V_112 ) ;
if ( V_12 >= V_113 ) {
* V_112 = 0 ;
return V_113 ;
}
return V_12 ;
}
int F_37 ( struct V_115 * V_116 , const struct V_115 * V_117 )
{
int V_118 = 0 ;
if ( F_3 ( F_38 ( V_116 ) ) )
return - V_119 ;
if ( V_116 -> V_120 < V_117 -> V_120 ) {
V_116 -> V_120 = V_117 -> V_120 ;
V_116 -> V_121 = V_117 -> V_121 ;
V_118 = 1 ;
} else if ( V_116 -> V_120 == V_117 -> V_120 && ! V_116 -> V_121 && V_117 -> V_121 ) {
V_116 -> V_121 = 1 ;
V_118 = 1 ;
}
if ( V_116 -> V_122 > V_117 -> V_122 ) {
V_116 -> V_122 = V_117 -> V_122 ;
V_116 -> V_123 = V_117 -> V_123 ;
V_118 = 1 ;
} else if ( V_116 -> V_122 == V_117 -> V_122 && ! V_116 -> V_123 && V_117 -> V_123 ) {
V_116 -> V_123 = 1 ;
V_118 = 1 ;
}
if ( ! V_116 -> integer && V_117 -> integer ) {
V_116 -> integer = 1 ;
V_118 = 1 ;
}
if ( V_116 -> integer ) {
if ( V_116 -> V_121 ) {
V_116 -> V_120 ++ ;
V_116 -> V_121 = 0 ;
}
if ( V_116 -> V_123 ) {
V_116 -> V_122 -- ;
V_116 -> V_123 = 0 ;
}
} else if ( ! V_116 -> V_121 && ! V_116 -> V_123 && V_116 -> V_120 == V_116 -> V_122 )
V_116 -> integer = 1 ;
if ( F_39 ( V_116 ) ) {
F_40 ( V_116 ) ;
return - V_119 ;
}
return V_118 ;
}
static int F_41 ( struct V_115 * V_116 )
{
if ( F_3 ( F_38 ( V_116 ) ) )
return - V_119 ;
if ( F_42 ( V_116 ) )
return 0 ;
V_116 -> V_122 = V_116 -> V_120 ;
V_116 -> V_123 = V_116 -> V_121 ;
if ( V_116 -> V_123 )
V_116 -> V_122 ++ ;
return 1 ;
}
static int F_43 ( struct V_115 * V_116 )
{
if ( F_3 ( F_38 ( V_116 ) ) )
return - V_119 ;
if ( F_42 ( V_116 ) )
return 0 ;
V_116 -> V_120 = V_116 -> V_122 ;
V_116 -> V_121 = V_116 -> V_123 ;
if ( V_116 -> V_121 )
V_116 -> V_120 -- ;
return 1 ;
}
void F_44 ( const struct V_115 * V_110 , const struct V_115 * V_111 , struct V_115 * V_33 )
{
if ( V_110 -> V_124 || V_111 -> V_124 ) {
F_40 ( V_33 ) ;
return;
}
V_33 -> V_124 = 0 ;
V_33 -> V_120 = F_34 ( V_110 -> V_120 , V_111 -> V_120 ) ;
V_33 -> V_121 = ( V_110 -> V_121 || V_111 -> V_121 ) ;
V_33 -> V_122 = F_34 ( V_110 -> V_122 , V_111 -> V_122 ) ;
V_33 -> V_123 = ( V_110 -> V_123 || V_111 -> V_123 ) ;
V_33 -> integer = ( V_110 -> integer && V_111 -> integer ) ;
}
void F_45 ( const struct V_115 * V_110 , const struct V_115 * V_111 , struct V_115 * V_33 )
{
unsigned int V_112 ;
if ( V_110 -> V_124 || V_111 -> V_124 ) {
F_40 ( V_33 ) ;
return;
}
V_33 -> V_124 = 0 ;
V_33 -> V_120 = F_31 ( V_110 -> V_120 , V_111 -> V_122 , & V_112 ) ;
V_33 -> V_121 = ( V_112 || V_110 -> V_121 || V_111 -> V_123 ) ;
if ( V_111 -> V_120 > 0 ) {
V_33 -> V_122 = F_31 ( V_110 -> V_122 , V_111 -> V_120 , & V_112 ) ;
if ( V_112 ) {
V_33 -> V_122 ++ ;
V_33 -> V_123 = 1 ;
} else
V_33 -> V_123 = ( V_110 -> V_123 || V_111 -> V_121 ) ;
} else {
V_33 -> V_122 = V_113 ;
V_33 -> V_123 = 0 ;
}
V_33 -> integer = 0 ;
}
void F_46 ( const struct V_115 * V_110 , const struct V_115 * V_111 ,
unsigned int V_125 , struct V_115 * V_33 )
{
unsigned int V_112 ;
if ( V_110 -> V_124 || V_111 -> V_124 ) {
F_40 ( V_33 ) ;
return;
}
V_33 -> V_124 = 0 ;
V_33 -> V_120 = F_35 ( V_110 -> V_120 , V_111 -> V_120 , V_125 , & V_112 ) ;
V_33 -> V_121 = ( V_112 || V_110 -> V_121 || V_111 -> V_121 ) ;
V_33 -> V_122 = F_35 ( V_110 -> V_122 , V_111 -> V_122 , V_125 , & V_112 ) ;
if ( V_112 ) {
V_33 -> V_122 ++ ;
V_33 -> V_123 = 1 ;
} else
V_33 -> V_123 = ( V_110 -> V_123 || V_111 -> V_123 ) ;
V_33 -> integer = 0 ;
}
void F_47 ( const struct V_115 * V_110 , unsigned int V_125 ,
const struct V_115 * V_111 , struct V_115 * V_33 )
{
unsigned int V_112 ;
if ( V_110 -> V_124 || V_111 -> V_124 ) {
F_40 ( V_33 ) ;
return;
}
V_33 -> V_124 = 0 ;
V_33 -> V_120 = F_35 ( V_110 -> V_120 , V_125 , V_111 -> V_122 , & V_112 ) ;
V_33 -> V_121 = ( V_112 || V_110 -> V_121 || V_111 -> V_123 ) ;
if ( V_111 -> V_120 > 0 ) {
V_33 -> V_122 = F_35 ( V_110 -> V_122 , V_125 , V_111 -> V_120 , & V_112 ) ;
if ( V_112 ) {
V_33 -> V_122 ++ ;
V_33 -> V_123 = 1 ;
} else
V_33 -> V_123 = ( V_110 -> V_123 || V_111 -> V_121 ) ;
} else {
V_33 -> V_122 = V_113 ;
V_33 -> V_123 = 0 ;
}
V_33 -> integer = 0 ;
}
int F_48 ( struct V_115 * V_116 ,
unsigned int V_126 , const struct V_127 * V_128 ,
unsigned int * V_129 , unsigned int * V_130 )
{
unsigned int V_131 , V_132 ;
int V_133 ;
unsigned int V_125 ;
struct V_115 V_134 ;
int V_28 ;
unsigned int V_135 , V_136 ;
int V_137 ;
V_131 = V_132 = V_133 = 0 ;
for ( V_125 = 0 ; V_125 < V_126 ; ++ V_125 ) {
unsigned int V_138 = V_128 [ V_125 ] . V_138 ;
unsigned int V_139 ;
unsigned int V_114 = V_116 -> V_120 ;
int V_140 ;
if ( V_114 == 0 )
V_114 = 1 ;
V_139 = F_33 ( V_138 , V_114 ) ;
if ( V_139 < V_128 [ V_125 ] . V_141 )
continue;
if ( V_139 > V_128 [ V_125 ] . V_142 )
V_139 = V_128 [ V_125 ] . V_142 ;
else {
unsigned int V_112 ;
V_112 = ( V_139 - V_128 [ V_125 ] . V_141 ) % V_128 [ V_125 ] . V_143 ;
if ( V_112 != 0 )
V_139 -= V_112 ;
}
V_140 = V_138 - V_114 * V_139 ;
if ( V_140 < 0 )
V_140 = - V_140 ;
if ( V_131 == 0 ||
V_140 * V_132 < V_133 * V_139 ) {
V_133 = V_140 ;
V_132 = V_139 ;
V_131 = V_138 ;
}
}
if ( V_132 == 0 ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
V_134 . V_120 = F_32 ( V_131 , V_132 ) ;
V_134 . V_121 = ! ! ( V_131 % V_132 ) ;
V_135 = V_131 ;
V_137 = V_133 ;
V_136 = V_132 ;
V_131 = V_132 = V_133 = 0 ;
for ( V_125 = 0 ; V_125 < V_126 ; ++ V_125 ) {
unsigned int V_138 = V_128 [ V_125 ] . V_138 ;
unsigned int V_139 ;
unsigned int V_114 = V_116 -> V_122 ;
int V_140 ;
if ( V_114 == 0 ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
V_139 = F_32 ( V_138 , V_114 ) ;
if ( V_139 > V_128 [ V_125 ] . V_142 )
continue;
if ( V_139 < V_128 [ V_125 ] . V_141 )
V_139 = V_128 [ V_125 ] . V_141 ;
else {
unsigned int V_112 ;
V_112 = ( V_139 - V_128 [ V_125 ] . V_141 ) % V_128 [ V_125 ] . V_143 ;
if ( V_112 != 0 )
V_139 += V_128 [ V_125 ] . V_143 - V_112 ;
}
V_140 = V_114 * V_139 - V_138 ;
if ( V_140 < 0 )
V_140 = - V_140 ;
if ( V_131 == 0 ||
V_140 * V_132 < V_133 * V_139 ) {
V_133 = V_140 ;
V_132 = V_139 ;
V_131 = V_138 ;
}
}
if ( V_132 == 0 ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
V_134 . V_122 = F_33 ( V_131 , V_132 ) ;
V_134 . V_123 = ! ! ( V_131 % V_132 ) ;
V_134 . integer = 0 ;
V_28 = F_37 ( V_116 , & V_134 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_42 ( V_116 ) ) {
if ( V_133 * V_136 < V_137 * V_132 ) {
V_135 = V_131 ;
V_136 = V_132 ;
}
if ( V_129 )
* V_129 = V_135 ;
if ( V_130 )
* V_130 = V_136 ;
}
return V_28 ;
}
static int F_49 ( struct V_115 * V_116 ,
unsigned int V_126 ,
const struct V_144 * V_128 ,
unsigned int * V_129 , unsigned int * V_130 )
{
unsigned int V_131 , V_133 , V_132 ;
unsigned int V_125 ;
struct V_115 V_134 ;
int V_28 ;
V_131 = V_132 = V_133 = 0 ;
for ( V_125 = 0 ; V_125 < V_126 ; ++ V_125 ) {
unsigned int V_138 ;
unsigned int V_139 = V_128 [ V_125 ] . V_139 ;
unsigned int V_114 = V_116 -> V_120 ;
int V_140 ;
V_138 = F_34 ( V_114 , V_139 ) ;
if ( V_138 > V_128 [ V_125 ] . V_145 )
continue;
if ( V_138 < V_128 [ V_125 ] . V_146 )
V_138 = V_128 [ V_125 ] . V_145 ;
else {
unsigned int V_112 ;
V_112 = ( V_138 - V_128 [ V_125 ] . V_146 ) % V_128 [ V_125 ] . V_147 ;
if ( V_112 != 0 )
V_138 += V_128 [ V_125 ] . V_147 - V_112 ;
}
V_140 = V_138 - V_114 * V_139 ;
if ( V_131 == 0 ||
V_140 * V_132 < V_133 * V_139 ) {
V_133 = V_140 ;
V_132 = V_139 ;
V_131 = V_138 ;
}
}
if ( V_132 == 0 ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
V_134 . V_120 = F_32 ( V_131 , V_132 ) ;
V_134 . V_121 = ! ! ( V_131 % V_132 ) ;
V_131 = V_132 = V_133 = 0 ;
for ( V_125 = 0 ; V_125 < V_126 ; ++ V_125 ) {
unsigned int V_138 ;
unsigned int V_139 = V_128 [ V_125 ] . V_139 ;
unsigned int V_114 = V_116 -> V_122 ;
int V_140 ;
V_138 = F_34 ( V_114 , V_139 ) ;
if ( V_138 < V_128 [ V_125 ] . V_146 )
continue;
if ( V_138 > V_128 [ V_125 ] . V_145 )
V_138 = V_128 [ V_125 ] . V_145 ;
else {
unsigned int V_112 ;
V_112 = ( V_138 - V_128 [ V_125 ] . V_146 ) % V_128 [ V_125 ] . V_147 ;
if ( V_112 != 0 )
V_138 -= V_112 ;
}
V_140 = V_114 * V_139 - V_138 ;
if ( V_131 == 0 ||
V_140 * V_132 < V_133 * V_139 ) {
V_133 = V_140 ;
V_132 = V_139 ;
V_131 = V_138 ;
}
}
if ( V_132 == 0 ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
V_134 . V_122 = F_33 ( V_131 , V_132 ) ;
V_134 . V_123 = ! ! ( V_131 % V_132 ) ;
V_134 . integer = 0 ;
V_28 = F_37 ( V_116 , & V_134 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_42 ( V_116 ) ) {
if ( V_129 )
* V_129 = V_131 ;
if ( V_130 )
* V_130 = V_132 ;
}
return V_28 ;
}
int F_50 ( struct V_115 * V_116 , unsigned int V_148 ,
const unsigned int * V_149 , unsigned int V_150 )
{
unsigned int V_125 ;
struct V_115 V_151 ;
if ( ! V_148 ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
F_51 ( & V_151 ) ;
V_151 . V_120 = V_113 ;
V_151 . V_122 = 0 ;
for ( V_125 = 0 ; V_125 < V_148 ; V_125 ++ ) {
if ( V_150 && ! ( V_150 & ( 1 << V_125 ) ) )
continue;
if ( ! F_52 ( V_116 , V_149 [ V_125 ] ) )
continue;
V_151 . V_120 = V_120 ( V_151 . V_120 , V_149 [ V_125 ] ) ;
V_151 . V_122 = V_122 ( V_151 . V_122 , V_149 [ V_125 ] ) ;
}
return F_37 ( V_116 , & V_151 ) ;
}
int F_53 ( struct V_115 * V_116 , unsigned int V_148 ,
const struct V_115 * V_152 , unsigned int V_150 )
{
unsigned int V_125 ;
struct V_115 V_153 ;
struct V_115 V_154 ;
if ( ! V_148 ) {
F_40 ( V_116 ) ;
return - V_119 ;
}
F_51 ( & V_153 ) ;
V_153 . V_120 = V_113 ;
V_153 . V_122 = 0 ;
for ( V_125 = 0 ; V_125 < V_148 ; V_125 ++ ) {
if ( V_150 && ! ( V_150 & ( 1 << V_125 ) ) )
continue;
F_54 ( & V_154 , & V_152 [ V_125 ] ) ;
if ( F_37 ( & V_154 , V_116 ) < 0 )
continue;
if ( F_38 ( & V_154 ) )
continue;
if ( V_154 . V_120 < V_153 . V_120 ) {
V_153 . V_120 = V_154 . V_120 ;
V_153 . V_121 = 1 ;
}
if ( V_154 . V_120 == V_153 . V_120 && ! V_154 . V_121 )
V_153 . V_121 = 0 ;
if ( V_154 . V_122 > V_153 . V_122 ) {
V_153 . V_122 = V_154 . V_122 ;
V_153 . V_123 = 1 ;
}
if ( V_154 . V_122 == V_153 . V_122 && ! V_154 . V_123 )
V_153 . V_123 = 0 ;
}
return F_37 ( V_116 , & V_153 ) ;
}
static int F_55 ( struct V_115 * V_116 , unsigned int V_155 )
{
unsigned int V_12 ;
int V_118 = 0 ;
V_12 = V_116 -> V_120 % V_155 ;
if ( V_12 != 0 || V_116 -> V_121 ) {
V_116 -> V_120 += V_155 - V_12 ;
V_116 -> V_121 = 0 ;
V_118 = 1 ;
}
V_12 = V_116 -> V_122 % V_155 ;
if ( V_12 != 0 || V_116 -> V_123 ) {
V_116 -> V_122 -= V_12 ;
V_116 -> V_123 = 0 ;
V_118 = 1 ;
}
if ( F_39 ( V_116 ) ) {
V_116 -> V_124 = 1 ;
return - V_119 ;
}
return V_118 ;
}
int F_56 ( struct V_4 * V_5 , unsigned int V_156 ,
int V_157 ,
T_6 V_158 , void * V_159 ,
int V_160 , ... )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_164 * V_33 ;
unsigned int V_125 ;
T_7 args ;
va_start ( args , V_160 ) ;
if ( V_162 -> V_165 >= V_162 -> V_166 ) {
struct V_164 * V_167 ;
unsigned int V_168 = V_162 -> V_166 + 16 ;
V_167 = F_57 ( V_168 , sizeof( * V_33 ) , V_169 ) ;
if ( ! V_167 ) {
va_end ( args ) ;
return - V_170 ;
}
if ( V_162 -> V_171 ) {
memcpy ( V_167 , V_162 -> V_171 ,
V_162 -> V_165 * sizeof( * V_33 ) ) ;
F_58 ( V_162 -> V_171 ) ;
}
V_162 -> V_171 = V_167 ;
V_162 -> V_166 = V_168 ;
}
V_33 = & V_162 -> V_171 [ V_162 -> V_165 ] ;
V_33 -> V_156 = V_156 ;
V_33 -> V_158 = V_158 ;
V_33 -> V_157 = V_157 ;
V_33 -> V_159 = V_159 ;
V_125 = 0 ;
while ( 1 ) {
if ( F_3 ( V_125 >= F_59 ( V_33 -> V_172 ) ) ) {
va_end ( args ) ;
return - V_119 ;
}
V_33 -> V_172 [ V_125 ++ ] = V_160 ;
if ( V_160 < 0 )
break;
V_160 = va_arg ( args , int ) ;
}
V_162 -> V_165 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_60 ( struct V_4 * V_5 , T_8 V_157 ,
T_9 V_150 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_173 * V_174 = F_61 ( V_162 , V_157 ) ;
* V_174 -> V_175 &= V_150 ;
memset ( V_174 -> V_175 + 1 , 0 , ( V_176 - 32 ) / 8 ) ;
if ( * V_174 -> V_175 == 0 )
return - V_119 ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 , T_8 V_157 ,
T_5 V_150 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_173 * V_174 = F_61 ( V_162 , V_157 ) ;
V_174 -> V_175 [ 0 ] &= ( T_9 ) V_150 ;
V_174 -> V_175 [ 1 ] &= ( T_9 ) ( V_150 >> 32 ) ;
memset ( V_174 -> V_175 + 2 , 0 , ( V_176 - 64 ) / 8 ) ;
if ( ! V_174 -> V_175 [ 0 ] && ! V_174 -> V_175 [ 1 ] )
return - V_119 ;
return 0 ;
}
int F_63 ( struct V_4 * V_5 , T_8 V_157 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
return F_64 ( F_65 ( V_162 , V_157 ) ) ;
}
int F_66 ( struct V_4 * V_5 , T_8 V_157 ,
unsigned int V_120 , unsigned int V_122 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_115 V_134 ;
V_134 . V_120 = V_120 ;
V_134 . V_122 = V_122 ;
V_134 . V_121 = V_134 . V_123 = 0 ;
V_134 . integer = 0 ;
return F_37 ( F_65 ( V_162 , V_157 ) , & V_134 ) ;
}
static int F_67 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
struct V_180 * V_149 = V_179 -> V_159 ;
return F_50 ( F_68 ( V_178 , V_179 -> V_157 ) , V_149 -> V_148 , V_149 -> V_149 , V_149 -> V_150 ) ;
}
int V_180 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_8 V_157 ,
const struct V_180 * V_181 )
{
return F_56 ( V_5 , V_156 , V_157 ,
F_67 , ( void * ) V_181 ,
V_157 , - 1 ) ;
}
static int F_69 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
struct V_182 * V_112 = V_179 -> V_159 ;
return F_53 ( F_68 ( V_178 , V_179 -> V_157 ) ,
V_112 -> V_148 , V_112 -> V_152 , V_112 -> V_150 ) ;
}
int V_182 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_8 V_157 ,
const struct V_182 * V_112 )
{
return F_56 ( V_5 , V_156 , V_157 ,
F_69 , ( void * ) V_112 ,
V_157 , - 1 ) ;
}
static int F_70 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
const struct V_183 * V_112 = V_179 -> V_159 ;
unsigned int V_138 = 0 , V_139 = 0 ;
int V_28 ;
V_28 = F_48 ( F_68 ( V_178 , V_179 -> V_157 ) ,
V_112 -> V_184 , V_112 -> V_128 , & V_138 , & V_139 ) ;
if ( V_28 >= 0 && V_139 && V_179 -> V_157 == V_185 ) {
V_178 -> V_186 = V_138 ;
V_178 -> V_187 = V_139 ;
}
return V_28 ;
}
int V_183 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_8 V_157 ,
const struct V_183 * V_112 )
{
return F_56 ( V_5 , V_156 , V_157 ,
F_70 , ( void * ) V_112 ,
V_157 , - 1 ) ;
}
static int F_71 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
const struct V_188 * V_112 = V_179 -> V_159 ;
unsigned int V_138 = 0 , V_139 = 0 ;
int V_28 = F_49 ( F_68 ( V_178 , V_179 -> V_157 ) ,
V_112 -> V_184 , V_112 -> V_128 , & V_138 , & V_139 ) ;
if ( V_28 >= 0 && V_139 && V_179 -> V_157 == V_185 ) {
V_178 -> V_186 = V_138 ;
V_178 -> V_187 = V_139 ;
}
return V_28 ;
}
int V_188 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_8 V_157 ,
const struct V_188 * V_112 )
{
return F_56 ( V_5 , V_156 , V_157 ,
F_71 , ( void * ) V_112 ,
V_157 , - 1 ) ;
}
static int F_72 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
unsigned int V_181 = ( unsigned long ) V_179 -> V_159 ;
int V_189 = V_181 & 0xffff ;
unsigned int V_190 = V_181 >> 16 ;
struct V_115 * V_116 = F_68 ( V_178 , V_191 ) ;
if ( ! F_42 ( V_116 ) )
return 0 ;
if ( ( F_73 ( V_116 ) == V_189 ) ||
( V_189 == 0 && F_73 ( V_116 ) > V_190 ) )
V_178 -> V_190 = F_74 ( V_178 -> V_190 , V_190 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_5 ,
unsigned int V_156 ,
unsigned int V_189 ,
unsigned int V_190 )
{
unsigned long V_181 = ( V_190 << 16 ) | V_189 ;
return F_56 ( V_5 , V_156 , - 1 ,
F_72 ,
( void * ) V_181 ,
V_191 , - 1 ) ;
}
static int F_76 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
unsigned long V_155 = ( unsigned long ) V_179 -> V_159 ;
return F_55 ( F_68 ( V_178 , V_179 -> V_157 ) , V_155 ) ;
}
int F_77 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_8 V_157 ,
unsigned long V_155 )
{
return F_56 ( V_5 , V_156 , V_157 ,
F_76 , ( void * ) V_155 ,
V_157 , - 1 ) ;
}
static int F_78 ( struct V_177 * V_178 , struct V_164 * V_179 )
{
static unsigned int V_192 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_50 ( F_68 ( V_178 , V_179 -> V_157 ) ,
F_59 ( V_192 ) , V_192 , 0 ) ;
}
int F_79 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_8 V_157 )
{
return F_56 ( V_5 , V_156 , V_157 ,
F_78 , NULL ,
V_157 , - 1 ) ;
}
static int F_80 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
unsigned int V_193 = ( unsigned int ) ( V_194 ) V_179 -> V_159 ;
struct V_115 * V_72 ;
V_72 = F_68 ( V_178 , V_185 ) ;
return F_50 ( V_72 , 1 , & V_193 , 0 ) ;
}
int F_81 ( struct V_4 * V_5 ,
unsigned int V_193 )
{
return F_56 ( V_5 , V_195 ,
V_185 ,
F_80 ,
( void * ) ( V_194 ) V_193 ,
V_185 , - 1 ) ;
}
static void F_82 ( struct V_177 * V_178 ,
T_8 V_157 )
{
if ( F_83 ( V_157 ) ) {
F_84 ( F_85 ( V_178 , V_157 ) ) ;
V_178 -> V_196 |= 1 << V_157 ;
V_178 -> V_197 |= 1 << V_157 ;
return;
}
if ( F_86 ( V_157 ) ) {
F_51 ( F_68 ( V_178 , V_157 ) ) ;
V_178 -> V_196 |= 1 << V_157 ;
V_178 -> V_197 |= 1 << V_157 ;
return;
}
F_87 () ;
}
void F_88 ( struct V_177 * V_178 )
{
unsigned int V_125 ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
for ( V_125 = V_198 ; V_125 <= V_199 ; V_125 ++ )
F_82 ( V_178 , V_125 ) ;
for ( V_125 = V_200 ; V_125 <= V_201 ; V_125 ++ )
F_82 ( V_178 , V_125 ) ;
V_178 -> V_100 = ~ 0U ;
}
int F_89 ( const struct V_177 * V_178 ,
T_8 V_157 , int * V_202 )
{
if ( F_83 ( V_157 ) ) {
const struct V_173 * V_150 = F_90 ( V_178 , V_157 ) ;
if ( ! F_91 ( V_150 ) )
return - V_119 ;
if ( V_202 )
* V_202 = 0 ;
return F_92 ( V_150 ) ;
}
if ( F_86 ( V_157 ) ) {
const struct V_115 * V_116 = F_93 ( V_178 , V_157 ) ;
if ( ! F_42 ( V_116 ) )
return - V_119 ;
if ( V_202 )
* V_202 = V_116 -> V_121 ;
return F_73 ( V_116 ) ;
}
return - V_119 ;
}
void F_94 ( struct V_177 * V_178 ,
T_8 V_157 )
{
if ( F_83 ( V_157 ) ) {
F_95 ( F_85 ( V_178 , V_157 ) ) ;
V_178 -> V_196 |= 1 << V_157 ;
V_178 -> V_197 |= 1 << V_157 ;
} else if ( F_86 ( V_157 ) ) {
F_40 ( F_68 ( V_178 , V_157 ) ) ;
V_178 -> V_196 |= 1 << V_157 ;
V_178 -> V_197 |= 1 << V_157 ;
} else {
F_87 () ;
}
}
static int F_96 ( struct V_177 * V_178 ,
T_8 V_157 )
{
int V_118 ;
if ( F_83 ( V_157 ) )
V_118 = F_97 ( F_85 ( V_178 , V_157 ) ) ;
else if ( F_86 ( V_157 ) )
V_118 = F_41 ( F_68 ( V_178 , V_157 ) ) ;
else
return - V_119 ;
if ( V_118 ) {
V_178 -> V_196 |= 1 << V_157 ;
V_178 -> V_197 |= 1 << V_157 ;
}
return V_118 ;
}
int F_98 ( struct V_1 * V_38 ,
struct V_177 * V_178 ,
T_8 V_157 , int * V_202 )
{
int V_118 = F_96 ( V_178 , V_157 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_178 -> V_197 ) {
int V_28 = F_99 ( V_38 , V_178 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_89 ( V_178 , V_157 , V_202 ) ;
}
static int F_100 ( struct V_177 * V_178 ,
T_8 V_157 )
{
int V_118 ;
if ( F_83 ( V_157 ) )
V_118 = F_101 ( F_85 ( V_178 , V_157 ) ) ;
else if ( F_86 ( V_157 ) )
V_118 = F_43 ( F_68 ( V_178 , V_157 ) ) ;
else
return - V_119 ;
if ( V_118 ) {
V_178 -> V_196 |= 1 << V_157 ;
V_178 -> V_197 |= 1 << V_157 ;
}
return V_118 ;
}
int F_102 ( struct V_1 * V_38 ,
struct V_177 * V_178 ,
T_8 V_157 , int * V_202 )
{
int V_118 = F_100 ( V_178 , V_157 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_178 -> V_197 ) {
int V_28 = F_99 ( V_38 , V_178 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_89 ( V_178 , V_157 , V_202 ) ;
}
int F_103 ( struct V_1 * V_38 ,
struct V_177 * V_178 )
{
static int V_203 [] = {
V_204 ,
V_205 ,
V_206 ,
V_207 ,
V_185 ,
V_208 ,
V_209 ,
V_210 ,
- 1
} ;
int V_28 , * V_117 ;
for ( V_117 = V_203 ; * V_117 != - 1 ; V_117 ++ ) {
if ( * V_117 != V_209 )
V_28 = F_98 ( V_38 , V_178 , * V_117 , NULL ) ;
else
V_28 = F_102 ( V_38 , V_178 , * V_117 , NULL ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
void * V_211 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_212 ;
F_105 ( V_2 , V_212 ) ;
if ( F_106 ( V_2 ) &&
F_28 ( V_2 ) >= 0 )
V_5 -> V_21 -> V_22 %= V_5 -> V_17 ;
else {
V_5 -> V_21 -> V_22 = 0 ;
V_5 -> V_68 = 0 ;
}
F_107 ( V_2 , V_212 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
void * V_211 )
{
struct V_213 * V_100 = V_211 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_189 ;
if ( ! ( V_5 -> V_100 & V_214 ) ) {
V_100 -> V_215 = - 1 ;
return 0 ;
}
V_189 = F_109 ( V_5 -> V_31 ) ;
if ( V_189 < 0 )
return V_189 ;
V_100 -> V_215 = 0 ;
switch ( V_5 -> V_23 ) {
case V_25 :
case V_24 :
V_100 -> V_216 = V_100 -> V_217 * V_189 ;
V_100 -> V_155 = V_5 -> V_32 * V_189 ;
break;
case V_218 :
case V_219 :
{
T_3 V_220 = V_5 -> V_35 / V_5 -> V_32 ;
V_100 -> V_216 = V_100 -> V_217 * V_220 * 8 ;
V_100 -> V_155 = V_189 ;
break;
}
default:
F_87 () ;
break;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 ,
void * V_211 )
{
struct V_177 * V_178 = V_211 ;
T_10 V_31 ;
int V_32 ;
T_11 V_221 ;
V_178 -> V_222 = V_2 -> V_5 -> V_99 . V_222 ;
if ( ! ( V_2 -> V_5 -> V_99 . V_100 & V_223 ) ) {
V_31 = F_111 ( V_178 ) ;
V_32 = F_112 ( V_178 ) ;
V_221 = F_113 ( V_31 , V_32 ) ;
if ( V_221 > 0 )
V_178 -> V_222 /= ( unsigned ) V_221 ;
}
return 0 ;
}
int F_114 ( struct V_1 * V_2 ,
unsigned int V_224 , void * V_211 )
{
switch ( V_224 ) {
case V_225 :
return 0 ;
case V_226 :
return F_104 ( V_2 , V_211 ) ;
case V_227 :
return F_108 ( V_2 , V_211 ) ;
case V_228 :
return F_110 ( V_2 , V_211 ) ;
}
return - V_229 ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_212 ;
if ( F_116 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
F_105 ( V_2 , V_212 ) ;
if ( ! F_106 ( V_2 ) ||
F_23 ( V_2 , 1 ) < 0 )
goto V_230;
#ifdef F_117
if ( V_2 -> V_231 )
F_118 ( V_2 -> V_232 , 1 ) ;
#endif
V_230:
F_119 ( & V_5 -> V_233 , V_234 , V_235 ) ;
F_107 ( V_2 , V_212 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
T_1 * V_236 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_237 = V_2 -> V_42 == V_49 ;
T_12 V_238 ;
int V_28 = 0 ;
T_1 V_20 = 0 ;
long V_239 , V_240 ;
F_121 ( & V_238 , V_241 ) ;
F_122 ( V_242 ) ;
F_123 ( & V_5 -> V_56 , & V_238 ) ;
if ( V_5 -> V_93 )
V_239 = V_243 ;
else {
V_239 = 10 ;
if ( V_5 -> V_72 ) {
long V_134 = V_5 -> V_86 * 2 / V_5 -> V_72 ;
V_239 = V_122 ( V_134 , V_239 ) ;
}
V_239 = F_124 ( V_239 * 1000 ) ;
}
for (; ; ) {
if ( F_125 ( V_241 ) ) {
V_28 = - V_244 ;
break;
}
if ( V_237 )
V_20 = F_16 ( V_5 ) ;
else
V_20 = F_17 ( V_5 ) ;
if ( V_20 >= V_5 -> V_55 )
break;
F_126 ( V_2 ) ;
V_240 = F_127 ( V_239 ) ;
F_128 ( V_2 ) ;
F_122 ( V_242 ) ;
switch ( V_5 -> V_21 -> V_51 ) {
case V_245 :
V_28 = - V_246 ;
goto V_247;
case V_47 :
V_28 = - V_53 ;
goto V_247;
case V_52 :
if ( V_237 )
V_28 = - V_53 ;
else
V_20 = 0 ;
goto V_247;
case V_248 :
case V_249 :
case V_250 :
V_28 = - V_251 ;
goto V_247;
case V_252 :
continue;
}
if ( ! V_240 ) {
F_129 ( V_2 -> V_38 ,
L_10 ,
V_237 ? L_11 : L_12 ) ;
V_28 = - V_253 ;
break;
}
}
V_247:
F_122 ( V_254 ) ;
F_130 ( & V_5 -> V_56 , & V_238 ) ;
* V_236 = V_20 ;
return V_28 ;
}
static int F_131 ( struct V_1 * V_2 ,
unsigned int V_255 ,
unsigned long V_256 , unsigned int V_257 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_13 * V_258 = ( char T_13 * ) V_256 + F_4 ( V_5 , V_257 ) ;
if ( V_2 -> V_26 -> V_259 ) {
if ( ( V_28 = V_2 -> V_26 -> V_259 ( V_2 , - 1 , V_255 , V_258 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_255 ) ;
if ( F_132 ( V_29 , V_258 , F_4 ( V_5 , V_6 ) ) )
return - V_260 ;
}
return 0 ;
}
static T_2 F_133 ( struct V_1 * V_2 ,
unsigned long V_256 ,
T_1 V_220 ,
int V_261 ,
T_14 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_262 = 0 ;
T_1 V_215 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_220 == 0 )
return 0 ;
F_128 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_51 ) {
case V_263 :
case V_264 :
case V_252 :
break;
case V_47 :
V_28 = - V_53 ;
goto V_265;
case V_245 :
V_28 = - V_246 ;
goto V_265;
default:
V_28 = - V_251 ;
goto V_265;
}
V_5 -> V_55 = V_5 -> V_14 -> V_57 ? : 1 ;
if ( V_5 -> V_21 -> V_51 == V_264 )
F_28 ( V_2 ) ;
V_20 = F_16 ( V_5 ) ;
while ( V_220 > 0 ) {
T_1 V_6 , V_15 , V_266 ;
T_1 V_267 ;
if ( ! V_20 ) {
if ( V_261 ) {
V_28 = - V_268 ;
goto V_265;
}
V_5 -> V_55 = F_134 ( T_1 , V_220 ,
V_5 -> V_14 -> V_57 ? : 1 ) ;
V_28 = F_120 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_265;
}
V_6 = V_220 > V_20 ? V_20 : V_220 ;
V_267 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_267 )
V_6 = V_267 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_55 = 0 ;
F_126 ( V_2 ) ;
return - V_119 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_266 = V_15 % V_5 -> V_17 ;
F_126 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_266 , V_256 , V_215 , V_6 ) ;
F_128 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
switch ( V_5 -> V_21 -> V_51 ) {
case V_47 :
V_28 = - V_53 ;
goto V_265;
case V_245 :
V_28 = - V_246 ;
goto V_265;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_269 )
V_2 -> V_26 -> V_269 ( V_2 ) ;
V_215 += V_6 ;
V_220 -= V_6 ;
V_262 += V_6 ;
V_20 -= V_6 ;
if ( V_5 -> V_21 -> V_51 == V_263 &&
F_2 ( V_5 ) >= ( T_2 ) V_5 -> V_270 ) {
V_28 = F_135 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
}
}
V_265:
V_5 -> V_55 = 0 ;
if ( V_262 > 0 && V_28 >= 0 )
F_15 ( V_2 , V_5 ) ;
F_126 ( V_2 ) ;
return V_262 > 0 ? ( T_2 ) V_262 : V_28 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_116 ( V_2 ) )
return - V_229 ;
V_5 = V_2 -> V_5 ;
if ( F_3 ( ! V_2 -> V_26 -> V_259 && ! V_5 -> V_30 ) )
return - V_119 ;
if ( V_5 -> V_21 -> V_51 == V_248 )
return - V_251 ;
return 0 ;
}
T_2 F_137 ( struct V_1 * V_2 , const void T_13 * V_258 , T_1 V_220 )
{
struct V_4 * V_5 ;
int V_261 ;
int V_28 ;
V_28 = F_136 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_261 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_24 &&
V_5 -> V_32 > 1 )
return - V_119 ;
return F_133 ( V_2 , ( unsigned long ) V_258 , V_220 , V_261 ,
F_131 ) ;
}
static int F_138 ( struct V_1 * V_2 ,
unsigned int V_255 ,
unsigned long V_256 , unsigned int V_257 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_13 * * V_273 = ( void T_13 * * ) V_256 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_259 ) {
if ( F_3 ( ! V_2 -> V_26 -> V_27 ) )
return - V_119 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
if ( * V_273 == NULL ) {
if ( ( V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_255 , V_6 ) ) < 0 )
return V_28 ;
} else {
char T_13 * V_258 = * V_273 + F_6 ( V_5 , V_257 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_259 ( V_2 , V_33 , V_255 , V_258 , V_6 ) ) < 0 )
return V_28 ;
}
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_255 ) ;
if ( * V_273 == NULL ) {
F_5 ( V_5 -> V_31 , V_29 , V_6 ) ;
} else {
char T_13 * V_258 = * V_273 + F_6 ( V_5 , V_257 ) ;
if ( F_132 ( V_29 , V_258 , F_6 ( V_5 , V_6 ) ) )
return - V_260 ;
}
}
}
return 0 ;
}
T_2 F_139 ( struct V_1 * V_2 ,
void T_13 * * V_273 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_261 ;
int V_28 ;
V_28 = F_136 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_261 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_219 )
return - V_119 ;
return F_133 ( V_2 , ( unsigned long ) V_273 , V_6 ,
V_261 , F_138 ) ;
}
static int F_140 ( struct V_1 * V_2 ,
unsigned int V_255 ,
unsigned long V_256 , unsigned int V_257 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_13 * V_258 = ( char T_13 * ) V_256 + F_4 ( V_5 , V_257 ) ;
if ( V_2 -> V_26 -> V_259 ) {
if ( ( V_28 = V_2 -> V_26 -> V_259 ( V_2 , - 1 , V_255 , V_258 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_255 ) ;
if ( F_141 ( V_258 , V_29 , F_4 ( V_5 , V_6 ) ) )
return - V_260 ;
}
return 0 ;
}
static T_2 F_142 ( struct V_1 * V_2 ,
unsigned long V_256 ,
T_1 V_220 ,
int V_261 ,
T_14 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_262 = 0 ;
T_1 V_215 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_220 == 0 )
return 0 ;
F_128 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_51 ) {
case V_263 :
if ( V_220 >= V_5 -> V_270 ) {
V_28 = F_135 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
}
break;
case V_52 :
case V_264 :
case V_252 :
break;
case V_47 :
V_28 = - V_53 ;
goto V_265;
case V_245 :
V_28 = - V_246 ;
goto V_265;
default:
V_28 = - V_251 ;
goto V_265;
}
V_5 -> V_55 = V_5 -> V_14 -> V_57 ? : 1 ;
if ( V_5 -> V_21 -> V_51 == V_264 )
F_28 ( V_2 ) ;
V_20 = F_17 ( V_5 ) ;
while ( V_220 > 0 ) {
T_1 V_6 , V_15 , V_266 ;
T_1 V_267 ;
if ( ! V_20 ) {
if ( V_5 -> V_21 -> V_51 ==
V_52 ) {
F_11 ( V_2 , V_249 ) ;
goto V_265;
}
if ( V_261 ) {
V_28 = - V_268 ;
goto V_265;
}
V_5 -> V_55 = F_134 ( T_1 , V_220 ,
V_5 -> V_14 -> V_57 ? : 1 ) ;
V_28 = F_120 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_265;
if ( ! V_20 )
continue;
}
V_6 = V_220 > V_20 ? V_20 : V_220 ;
V_267 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_267 )
V_6 = V_267 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_55 = 0 ;
F_126 ( V_2 ) ;
return - V_119 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_266 = V_15 % V_5 -> V_17 ;
F_126 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_266 , V_256 , V_215 , V_6 ) ;
F_128 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
switch ( V_5 -> V_21 -> V_51 ) {
case V_47 :
V_28 = - V_53 ;
goto V_265;
case V_245 :
V_28 = - V_246 ;
goto V_265;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_269 )
V_2 -> V_26 -> V_269 ( V_2 ) ;
V_215 += V_6 ;
V_220 -= V_6 ;
V_262 += V_6 ;
V_20 -= V_6 ;
}
V_265:
V_5 -> V_55 = 0 ;
if ( V_262 > 0 && V_28 >= 0 )
F_15 ( V_2 , V_5 ) ;
F_126 ( V_2 ) ;
return V_262 > 0 ? ( T_2 ) V_262 : V_28 ;
}
T_2 F_143 ( struct V_1 * V_2 , void T_13 * V_258 , T_1 V_220 )
{
struct V_4 * V_5 ;
int V_261 ;
int V_28 ;
V_28 = F_136 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_261 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_24 )
return - V_119 ;
return F_142 ( V_2 , ( unsigned long ) V_258 , V_220 , V_261 , F_140 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
unsigned int V_255 ,
unsigned long V_256 , unsigned int V_257 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_13 * * V_273 = ( void T_13 * * ) V_256 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_259 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
char T_13 * V_258 ;
if ( * V_273 == NULL )
continue;
V_258 = * V_273 + F_6 ( V_5 , V_257 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_259 ( V_2 , V_33 , V_255 , V_258 , V_6 ) ) < 0 )
return V_28 ;
}
} else {
T_1 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
char * V_29 ;
char T_13 * V_258 ;
if ( * V_273 == NULL )
continue;
V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_255 ) ;
V_258 = * V_273 + F_6 ( V_5 , V_257 ) ;
if ( F_141 ( V_258 , V_29 , F_6 ( V_5 , V_6 ) ) )
return - V_260 ;
}
}
return 0 ;
}
T_2 F_145 ( struct V_1 * V_2 ,
void T_13 * * V_273 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_261 ;
int V_28 ;
V_28 = F_136 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 -> V_51 == V_248 )
return - V_251 ;
V_261 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_219 )
return - V_119 ;
return F_142 ( V_2 , ( unsigned long ) V_273 , V_6 , V_261 , F_144 ) ;
}
static bool F_146 ( const struct V_274 * V_100 , int V_275 )
{
if ( V_275 > V_100 -> V_276 )
return false ;
return ! V_100 -> V_277 || ( V_100 -> V_277 & ( 1U << V_275 ) ) ;
}
static int F_147 ( struct V_278 * V_279 ,
struct V_280 * V_281 )
{
struct V_274 * V_100 = F_148 ( V_279 ) ;
V_281 -> type = V_282 ;
V_281 -> V_148 = 0 ;
V_281 -> V_148 = V_100 -> V_276 ;
V_281 -> V_283 . integer . V_120 = 0 ;
V_281 -> V_283 . integer . V_122 = V_284 ;
return 0 ;
}
static int F_149 ( struct V_278 * V_279 ,
struct V_285 * V_286 )
{
struct V_274 * V_100 = F_148 ( V_279 ) ;
unsigned int V_287 = F_150 ( V_279 , & V_286 -> V_288 ) ;
struct V_1 * V_2 ;
const struct V_289 * V_290 ;
if ( F_3 ( ! V_100 -> V_291 ) )
return - V_119 ;
V_2 = F_151 ( V_100 , V_287 ) ;
if ( ! V_2 )
return - V_292 ;
memset ( V_286 -> V_283 . integer . V_283 , 0 ,
sizeof( V_286 -> V_283 . integer . V_283 ) ) ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_290 = V_100 -> V_291 ; V_290 -> V_32 ; V_290 ++ ) {
int V_116 ;
if ( V_290 -> V_32 == V_2 -> V_5 -> V_32 &&
F_146 ( V_100 , V_290 -> V_32 ) ) {
for ( V_116 = 0 ; V_116 < V_290 -> V_32 ; V_116 ++ )
V_286 -> V_283 . integer . V_283 [ V_116 ] = V_290 -> V_290 [ V_116 ] ;
return 0 ;
}
}
return - V_119 ;
}
static int F_152 ( struct V_278 * V_279 , int V_293 ,
unsigned int V_220 , unsigned int T_13 * V_294 )
{
struct V_274 * V_100 = F_148 ( V_279 ) ;
const struct V_289 * V_290 ;
unsigned int T_13 * V_295 ;
int V_33 , V_148 = 0 ;
if ( F_3 ( ! V_100 -> V_291 ) )
return - V_119 ;
if ( V_220 < 8 )
return - V_170 ;
if ( F_153 ( V_296 , V_294 ) )
return - V_260 ;
V_220 -= 8 ;
V_295 = V_294 + 2 ;
for ( V_290 = V_100 -> V_291 ; V_290 -> V_32 ; V_290 ++ ) {
int V_297 = V_290 -> V_32 * 4 ;
if ( ! F_146 ( V_100 , V_290 -> V_32 ) )
continue;
if ( V_220 < 8 )
return - V_170 ;
if ( F_153 ( V_298 , V_295 ) ||
F_153 ( V_297 , V_295 + 1 ) )
return - V_260 ;
V_295 += 2 ;
V_220 -= 8 ;
V_148 += 8 ;
if ( V_220 < V_297 )
return - V_170 ;
V_220 -= V_297 ;
V_148 += V_297 ;
for ( V_33 = 0 ; V_33 < V_290 -> V_32 ; V_33 ++ ) {
if ( F_153 ( V_290 -> V_290 [ V_33 ] , V_295 ) )
return - V_260 ;
V_295 ++ ;
}
}
if ( F_153 ( V_148 , V_294 + 1 ) )
return - V_260 ;
return 0 ;
}
static void F_154 ( struct V_278 * V_279 )
{
struct V_274 * V_100 = F_148 ( V_279 ) ;
V_100 -> V_38 -> V_106 [ V_100 -> V_42 ] . V_299 = NULL ;
F_58 ( V_100 ) ;
}
int F_155 ( struct V_102 * V_38 , int V_42 ,
const struct V_289 * V_291 ,
int V_276 ,
unsigned long V_300 ,
struct V_274 * * V_301 )
{
struct V_274 * V_100 ;
struct V_302 V_303 = {
. V_304 = V_305 ,
. V_23 = V_306 |
V_307 |
V_308 ,
. V_100 = F_147 ,
. V_309 = F_149 ,
. V_294 . V_33 = F_152 ,
} ;
int V_28 ;
if ( F_156 ( V_38 -> V_106 [ V_42 ] . V_299 ) )
return - V_310 ;
V_100 = F_157 ( sizeof( * V_100 ) , V_169 ) ;
if ( ! V_100 )
return - V_170 ;
V_100 -> V_38 = V_38 ;
V_100 -> V_42 = V_42 ;
V_100 -> V_291 = V_291 ;
V_100 -> V_276 = V_276 ;
if ( V_42 == V_49 )
V_303 . V_36 = L_13 ;
else
V_303 . V_36 = L_14 ;
V_303 . V_41 = V_38 -> V_41 ;
V_303 . V_148 = V_38 -> V_106 [ V_42 ] . V_311 ;
V_303 . V_300 = V_300 ;
V_100 -> V_312 = F_158 ( & V_303 , V_100 ) ;
if ( ! V_100 -> V_312 ) {
F_58 ( V_100 ) ;
return - V_170 ;
}
V_100 -> V_312 -> V_313 = F_154 ;
V_28 = F_159 ( V_38 -> V_39 , V_100 -> V_312 ) ;
if ( V_28 < 0 )
return V_28 ;
V_38 -> V_106 [ V_42 ] . V_299 = V_100 -> V_312 ;
if ( V_301 )
* V_301 = V_100 ;
return 0 ;
}
