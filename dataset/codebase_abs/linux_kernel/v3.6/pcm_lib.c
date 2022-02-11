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
if ( V_5 -> V_43 == V_44 )
F_9 ( V_5 , (struct V_45 * ) & V_5 -> V_21 -> V_46 ) ;
F_10 ( V_2 , V_47 ) ;
if ( F_11 ( V_2 , V_48 ) ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_12 ( V_49 L_2 , V_36 ) ;
F_13 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_50 , int V_51 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_52 * log = V_5 -> V_53 ;
struct V_54 * V_55 ;
if ( log == NULL ) {
log = F_15 ( sizeof( * log ) , V_56 ) ;
if ( log == NULL )
return;
V_5 -> V_53 = log ;
} else {
if ( F_11 ( V_2 , V_57 ) && log -> V_58 )
return;
}
V_55 = & log -> V_59 [ log -> V_60 ] ;
V_55 -> V_51 = V_51 ;
V_55 -> V_61 = V_61 ;
V_55 -> V_50 = V_50 ;
V_55 -> V_62 = V_5 -> V_62 ;
V_55 -> V_17 = V_5 -> V_17 ;
V_55 -> V_63 = V_5 -> V_21 -> V_22 ;
V_55 -> V_64 = V_5 -> V_64 ;
log -> V_60 = ( log -> V_60 + 1 ) % V_65 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_52 * log = V_2 -> V_5 -> V_53 ;
struct V_54 * V_55 ;
char V_36 [ 16 ] ;
unsigned int V_60 ;
int V_66 ;
if ( log == NULL )
return;
if ( F_11 ( V_2 , V_57 ) && log -> V_58 )
return;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
for ( V_66 = 0 , V_60 = log -> V_60 ; V_66 < V_65 ; V_66 ++ ) {
V_55 = & log -> V_59 [ V_60 ] ;
if ( V_55 -> V_62 == 0 )
break;
F_12 ( L_3
L_4 ,
V_36 , V_55 -> V_51 ? L_5 : L_6 ,
V_55 -> V_61 ,
( unsigned long ) V_55 -> V_50 ,
( unsigned long ) V_55 -> V_62 ,
( unsigned long ) V_55 -> V_17 ,
( unsigned long ) V_55 -> V_63 ,
( unsigned long ) V_55 -> V_64 ) ;
V_60 ++ ;
V_60 %= V_65 ;
}
log -> V_58 = 1 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_1 V_20 ;
if ( V_2 -> V_42 == V_67 )
V_20 = F_18 ( V_5 ) ;
else
V_20 = F_19 ( V_5 ) ;
if ( V_20 > V_5 -> V_68 )
V_5 -> V_68 = V_20 ;
if ( V_5 -> V_21 -> V_69 == V_70 ) {
if ( V_20 >= V_5 -> V_17 ) {
F_20 ( V_2 ) ;
return - V_71 ;
}
} else {
if ( V_20 >= V_5 -> V_72 ) {
F_8 ( V_2 ) ;
return - V_71 ;
}
}
if ( V_5 -> V_73 ) {
if ( V_20 >= V_5 -> V_73 )
F_21 ( & V_5 -> V_74 ) ;
} else if ( V_20 >= V_5 -> V_14 -> V_75 )
F_21 ( & V_5 -> V_76 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_51 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_50 ;
T_1 V_63 , V_3 , V_77 ;
T_2 V_78 , V_79 ;
unsigned long V_80 ;
unsigned long V_81 ;
struct V_45 V_82 ;
V_63 = V_5 -> V_21 -> V_22 ;
V_50 = V_2 -> V_26 -> V_83 ( V_2 ) ;
V_81 = V_61 ;
if ( V_5 -> V_43 == V_44 )
F_9 ( V_5 , (struct V_45 * ) & V_82 ) ;
if ( V_50 == V_84 ) {
F_8 ( V_2 ) ;
return - V_71 ;
}
if ( V_50 >= V_5 -> V_17 ) {
if ( F_23 () ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_16 ( V_2 ) ;
F_12 ( V_85 L_7
L_8 ,
V_36 , V_50 , V_5 -> V_17 ,
V_5 -> V_62 ) ;
}
V_50 = 0 ;
}
V_50 -= V_50 % V_5 -> V_86 ;
if ( F_11 ( V_2 , V_87 ) )
F_14 ( V_2 , V_50 , V_51 ) ;
V_77 = V_5 -> V_64 ;
V_3 = V_77 + V_50 ;
if ( V_51 ) {
V_79 = V_5 -> V_88 + V_5 -> V_62 ;
if ( V_79 > V_3 ) {
V_78 = V_81 - V_5 -> V_89 ;
if ( V_78 > V_5 -> V_90 / 2 ) {
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 )
V_77 = 0 ;
V_3 = V_77 + V_50 ;
goto V_91;
}
}
}
if ( V_3 < V_63 ) {
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 )
V_77 = 0 ;
V_3 = V_77 + V_50 ;
}
V_91:
V_79 = V_3 - V_63 ;
if ( V_79 < 0 )
V_79 += V_5 -> V_10 ;
if ( F_11 ( V_2 , V_51 ?
V_92 : V_93 ) ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_12 ( L_9
L_10 ,
V_51 ? L_11 : L_12 ,
V_36 ,
( unsigned int ) V_50 ,
( unsigned int ) V_5 -> V_62 ,
( unsigned int ) V_5 -> V_17 ,
( unsigned long ) V_79 ,
( unsigned long ) V_63 ,
( unsigned long ) V_3 ,
( unsigned long ) V_5 -> V_64 ) ;
}
if ( V_5 -> V_94 ) {
T_2 V_95 ;
V_80 = V_81 - V_5 -> V_89 ;
if ( V_80 < V_5 -> V_90 / 2 )
goto V_96;
V_78 = V_80 - V_79 * V_97 / V_5 -> V_98 ;
V_95 = V_5 -> V_90 / 2 + 1 ;
while ( V_78 > V_95 ) {
V_79 += V_5 -> V_17 ;
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 )
V_77 = 0 ;
V_3 = V_77 + V_50 ;
V_78 -= V_5 -> V_90 ;
}
goto V_96;
}
if ( V_79 >= V_5 -> V_17 + V_5 -> V_62 ) {
F_24 ( V_2 ,
L_13
L_14
L_15 ,
V_51 ? L_5 : L_16 ,
V_2 -> V_42 , ( long ) V_50 ,
( long ) V_3 , ( long ) V_63 ) ;
return 0 ;
}
if ( ! F_11 ( V_2 , V_99 ) )
goto V_100;
if ( V_5 -> V_101 . V_102 & V_103 )
goto V_100;
V_78 = V_79 ;
if ( V_78 < V_5 -> V_104 )
goto V_100;
V_78 -= V_5 -> V_104 ;
V_80 = V_81 - V_5 -> V_89 ;
if ( ( ( V_78 * V_97 ) / V_5 -> V_98 ) > V_80 + V_97 / 100 ) {
V_79 = V_80 /
( ( ( V_5 -> V_62 * V_97 ) / V_5 -> V_98 )
+ V_97 / 100 ) ;
V_3 = V_63 ;
V_77 = V_79 ;
while ( V_79 > 0 ) {
V_3 += V_5 -> V_62 ;
if ( V_3 >= V_5 -> V_10 )
V_3 -= V_5 -> V_10 ;
V_79 -- ;
}
F_24 ( V_2 ,
L_17
L_18
L_19 ,
V_51 ? L_5 : L_6 ,
( long ) V_50 , ( long ) V_78 ,
( long ) V_5 -> V_62 , V_80 ,
( ( V_78 * V_97 ) / V_5 -> V_98 ) , V_77 ,
( unsigned long ) V_63 ,
( unsigned long ) V_3 ) ;
V_79 = 0 ;
V_77 = V_3 - ( V_3 % V_5 -> V_17 ) ;
}
V_100:
if ( V_79 > V_5 -> V_62 + V_5 -> V_62 / 2 ) {
F_24 ( V_2 ,
L_20
L_21
L_15 ,
V_51 ? L_5 : L_6 ,
V_2 -> V_42 , ( long ) V_79 ,
( long ) V_3 ,
( long ) V_63 ) ;
}
V_96:
if ( V_5 -> V_21 -> V_22 == V_3 )
return 0 ;
if ( V_2 -> V_42 == V_67 &&
V_5 -> V_9 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_51 ) {
V_79 = V_3 - V_5 -> V_88 ;
if ( V_79 < 0 )
V_79 += V_5 -> V_10 ;
V_79 -= ( T_1 ) V_79 % V_5 -> V_62 ;
V_5 -> V_88 += V_79 ;
if ( V_5 -> V_88 >= V_5 -> V_10 )
V_5 -> V_88 -= V_5 -> V_10 ;
}
V_5 -> V_64 = V_77 ;
V_5 -> V_21 -> V_22 = V_3 ;
V_5 -> V_89 = V_81 ;
if ( V_5 -> V_43 == V_44 )
V_5 -> V_21 -> V_46 = V_82 ;
return F_17 ( V_2 , V_5 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , 0 ) ;
}
void F_26 ( struct V_105 * V_38 , int V_106 , struct V_107 * V_26 )
{
struct V_108 * V_42 = & V_38 -> V_109 [ V_106 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_42 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_110 )
V_2 -> V_26 = V_26 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_111 . V_112 [ 0 ] = V_2 -> V_38 -> V_39 -> V_40 ;
V_5 -> V_111 . V_112 [ 1 ] = - 1 ;
V_5 -> V_111 . V_112 [ 2 ] = - 1 ;
V_5 -> V_111 . V_112 [ 3 ] = - 1 ;
}
static inline unsigned int F_28 ( unsigned int V_113 , unsigned int V_114 ,
unsigned int * V_115 )
{
if ( V_114 == 0 ) {
* V_115 = 0 ;
return V_116 ;
}
* V_115 = V_113 % V_114 ;
return V_113 / V_114 ;
}
static inline unsigned int F_29 ( unsigned int V_113 , unsigned int V_114 )
{
if ( V_114 == 0 )
return V_116 ;
return V_113 / V_114 ;
}
static inline unsigned int F_30 ( unsigned int V_113 , unsigned int V_114 )
{
unsigned int V_115 ;
unsigned int V_117 ;
if ( V_114 == 0 )
return V_116 ;
V_117 = F_28 ( V_113 , V_114 , & V_115 ) ;
if ( V_115 )
++ V_117 ;
return V_117 ;
}
static inline unsigned int F_31 ( unsigned int V_113 , unsigned int V_114 )
{
if ( V_113 == 0 )
return 0 ;
if ( F_29 ( V_116 , V_113 ) < V_114 )
return V_116 ;
return V_113 * V_114 ;
}
static inline unsigned int F_32 ( unsigned int V_113 , unsigned int V_114 ,
unsigned int V_33 , unsigned int * V_115 )
{
T_4 V_12 = ( T_4 ) V_113 * V_114 ;
if ( V_33 == 0 ) {
F_3 ( ! V_12 ) ;
* V_115 = 0 ;
return V_116 ;
}
V_12 = F_33 ( V_12 , V_33 , V_115 ) ;
if ( V_12 >= V_116 ) {
* V_115 = 0 ;
return V_116 ;
}
return V_12 ;
}
int F_34 ( struct V_118 * V_119 , const struct V_118 * V_120 )
{
int V_121 = 0 ;
if ( F_3 ( F_35 ( V_119 ) ) )
return - V_122 ;
if ( V_119 -> V_123 < V_120 -> V_123 ) {
V_119 -> V_123 = V_120 -> V_123 ;
V_119 -> V_124 = V_120 -> V_124 ;
V_121 = 1 ;
} else if ( V_119 -> V_123 == V_120 -> V_123 && ! V_119 -> V_124 && V_120 -> V_124 ) {
V_119 -> V_124 = 1 ;
V_121 = 1 ;
}
if ( V_119 -> V_125 > V_120 -> V_125 ) {
V_119 -> V_125 = V_120 -> V_125 ;
V_119 -> V_126 = V_120 -> V_126 ;
V_121 = 1 ;
} else if ( V_119 -> V_125 == V_120 -> V_125 && ! V_119 -> V_126 && V_120 -> V_126 ) {
V_119 -> V_126 = 1 ;
V_121 = 1 ;
}
if ( ! V_119 -> integer && V_120 -> integer ) {
V_119 -> integer = 1 ;
V_121 = 1 ;
}
if ( V_119 -> integer ) {
if ( V_119 -> V_124 ) {
V_119 -> V_123 ++ ;
V_119 -> V_124 = 0 ;
}
if ( V_119 -> V_126 ) {
V_119 -> V_125 -- ;
V_119 -> V_126 = 0 ;
}
} else if ( ! V_119 -> V_124 && ! V_119 -> V_126 && V_119 -> V_123 == V_119 -> V_125 )
V_119 -> integer = 1 ;
if ( F_36 ( V_119 ) ) {
F_37 ( V_119 ) ;
return - V_122 ;
}
return V_121 ;
}
static int F_38 ( struct V_118 * V_119 )
{
if ( F_3 ( F_35 ( V_119 ) ) )
return - V_122 ;
if ( F_39 ( V_119 ) )
return 0 ;
V_119 -> V_125 = V_119 -> V_123 ;
V_119 -> V_126 = V_119 -> V_124 ;
if ( V_119 -> V_126 )
V_119 -> V_125 ++ ;
return 1 ;
}
static int F_40 ( struct V_118 * V_119 )
{
if ( F_3 ( F_35 ( V_119 ) ) )
return - V_122 ;
if ( F_39 ( V_119 ) )
return 0 ;
V_119 -> V_123 = V_119 -> V_125 ;
V_119 -> V_124 = V_119 -> V_126 ;
if ( V_119 -> V_124 )
V_119 -> V_123 -- ;
return 1 ;
}
void F_41 ( const struct V_118 * V_113 , const struct V_118 * V_114 , struct V_118 * V_33 )
{
if ( V_113 -> V_127 || V_114 -> V_127 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_127 = 0 ;
V_33 -> V_123 = F_31 ( V_113 -> V_123 , V_114 -> V_123 ) ;
V_33 -> V_124 = ( V_113 -> V_124 || V_114 -> V_124 ) ;
V_33 -> V_125 = F_31 ( V_113 -> V_125 , V_114 -> V_125 ) ;
V_33 -> V_126 = ( V_113 -> V_126 || V_114 -> V_126 ) ;
V_33 -> integer = ( V_113 -> integer && V_114 -> integer ) ;
}
void F_42 ( const struct V_118 * V_113 , const struct V_118 * V_114 , struct V_118 * V_33 )
{
unsigned int V_115 ;
if ( V_113 -> V_127 || V_114 -> V_127 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_127 = 0 ;
V_33 -> V_123 = F_28 ( V_113 -> V_123 , V_114 -> V_125 , & V_115 ) ;
V_33 -> V_124 = ( V_115 || V_113 -> V_124 || V_114 -> V_126 ) ;
if ( V_114 -> V_123 > 0 ) {
V_33 -> V_125 = F_28 ( V_113 -> V_125 , V_114 -> V_123 , & V_115 ) ;
if ( V_115 ) {
V_33 -> V_125 ++ ;
V_33 -> V_126 = 1 ;
} else
V_33 -> V_126 = ( V_113 -> V_126 || V_114 -> V_124 ) ;
} else {
V_33 -> V_125 = V_116 ;
V_33 -> V_126 = 0 ;
}
V_33 -> integer = 0 ;
}
void F_43 ( const struct V_118 * V_113 , const struct V_118 * V_114 ,
unsigned int V_128 , struct V_118 * V_33 )
{
unsigned int V_115 ;
if ( V_113 -> V_127 || V_114 -> V_127 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_127 = 0 ;
V_33 -> V_123 = F_32 ( V_113 -> V_123 , V_114 -> V_123 , V_128 , & V_115 ) ;
V_33 -> V_124 = ( V_115 || V_113 -> V_124 || V_114 -> V_124 ) ;
V_33 -> V_125 = F_32 ( V_113 -> V_125 , V_114 -> V_125 , V_128 , & V_115 ) ;
if ( V_115 ) {
V_33 -> V_125 ++ ;
V_33 -> V_126 = 1 ;
} else
V_33 -> V_126 = ( V_113 -> V_126 || V_114 -> V_126 ) ;
V_33 -> integer = 0 ;
}
void F_44 ( const struct V_118 * V_113 , unsigned int V_128 ,
const struct V_118 * V_114 , struct V_118 * V_33 )
{
unsigned int V_115 ;
if ( V_113 -> V_127 || V_114 -> V_127 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_127 = 0 ;
V_33 -> V_123 = F_32 ( V_113 -> V_123 , V_128 , V_114 -> V_125 , & V_115 ) ;
V_33 -> V_124 = ( V_115 || V_113 -> V_124 || V_114 -> V_126 ) ;
if ( V_114 -> V_123 > 0 ) {
V_33 -> V_125 = F_32 ( V_113 -> V_125 , V_128 , V_114 -> V_123 , & V_115 ) ;
if ( V_115 ) {
V_33 -> V_125 ++ ;
V_33 -> V_126 = 1 ;
} else
V_33 -> V_126 = ( V_113 -> V_126 || V_114 -> V_124 ) ;
} else {
V_33 -> V_125 = V_116 ;
V_33 -> V_126 = 0 ;
}
V_33 -> integer = 0 ;
}
int F_45 ( struct V_118 * V_119 ,
unsigned int V_129 , struct V_130 * V_131 ,
unsigned int * V_132 , unsigned int * V_133 )
{
unsigned int V_134 , V_135 ;
int V_136 ;
unsigned int V_128 ;
struct V_118 V_137 ;
int V_28 ;
unsigned int V_138 , V_139 ;
int V_140 ;
V_134 = V_135 = V_136 = 0 ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 ) {
unsigned int V_141 = V_131 [ V_128 ] . V_141 ;
unsigned int V_142 ;
unsigned int V_117 = V_119 -> V_123 ;
int V_143 ;
if ( V_117 == 0 )
V_117 = 1 ;
V_142 = F_30 ( V_141 , V_117 ) ;
if ( V_142 < V_131 [ V_128 ] . V_144 )
continue;
if ( V_142 > V_131 [ V_128 ] . V_145 )
V_142 = V_131 [ V_128 ] . V_145 ;
else {
unsigned int V_115 ;
V_115 = ( V_142 - V_131 [ V_128 ] . V_144 ) % V_131 [ V_128 ] . V_146 ;
if ( V_115 != 0 )
V_142 -= V_115 ;
}
V_143 = V_141 - V_117 * V_142 ;
if ( V_143 < 0 )
V_143 = - V_143 ;
if ( V_134 == 0 ||
V_143 * V_135 < V_136 * V_142 ) {
V_136 = V_143 ;
V_135 = V_142 ;
V_134 = V_141 ;
}
}
if ( V_135 == 0 ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
V_137 . V_123 = F_29 ( V_134 , V_135 ) ;
V_137 . V_124 = ! ! ( V_134 % V_135 ) ;
V_138 = V_134 ;
V_140 = V_136 ;
V_139 = V_135 ;
V_134 = V_135 = V_136 = 0 ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 ) {
unsigned int V_141 = V_131 [ V_128 ] . V_141 ;
unsigned int V_142 ;
unsigned int V_117 = V_119 -> V_125 ;
int V_143 ;
if ( V_117 == 0 ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
V_142 = F_29 ( V_141 , V_117 ) ;
if ( V_142 > V_131 [ V_128 ] . V_145 )
continue;
if ( V_142 < V_131 [ V_128 ] . V_144 )
V_142 = V_131 [ V_128 ] . V_144 ;
else {
unsigned int V_115 ;
V_115 = ( V_142 - V_131 [ V_128 ] . V_144 ) % V_131 [ V_128 ] . V_146 ;
if ( V_115 != 0 )
V_142 += V_131 [ V_128 ] . V_146 - V_115 ;
}
V_143 = V_117 * V_142 - V_141 ;
if ( V_143 < 0 )
V_143 = - V_143 ;
if ( V_134 == 0 ||
V_143 * V_135 < V_136 * V_142 ) {
V_136 = V_143 ;
V_135 = V_142 ;
V_134 = V_141 ;
}
}
if ( V_135 == 0 ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
V_137 . V_125 = F_30 ( V_134 , V_135 ) ;
V_137 . V_126 = ! ! ( V_134 % V_135 ) ;
V_137 . integer = 0 ;
V_28 = F_34 ( V_119 , & V_137 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_39 ( V_119 ) ) {
if ( V_136 * V_139 < V_140 * V_135 ) {
V_138 = V_134 ;
V_139 = V_135 ;
}
if ( V_132 )
* V_132 = V_138 ;
if ( V_133 )
* V_133 = V_139 ;
}
return V_28 ;
}
static int F_46 ( struct V_118 * V_119 ,
unsigned int V_129 , struct V_147 * V_131 ,
unsigned int * V_132 , unsigned int * V_133 )
{
unsigned int V_134 , V_136 , V_135 ;
unsigned int V_128 ;
struct V_118 V_137 ;
int V_28 ;
V_134 = V_135 = V_136 = 0 ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 ) {
unsigned int V_141 ;
unsigned int V_142 = V_131 [ V_128 ] . V_142 ;
unsigned int V_117 = V_119 -> V_123 ;
int V_143 ;
V_141 = F_31 ( V_117 , V_142 ) ;
if ( V_141 > V_131 [ V_128 ] . V_148 )
continue;
if ( V_141 < V_131 [ V_128 ] . V_149 )
V_141 = V_131 [ V_128 ] . V_148 ;
else {
unsigned int V_115 ;
V_115 = ( V_141 - V_131 [ V_128 ] . V_149 ) % V_131 [ V_128 ] . V_150 ;
if ( V_115 != 0 )
V_141 += V_131 [ V_128 ] . V_150 - V_115 ;
}
V_143 = V_141 - V_117 * V_142 ;
if ( V_134 == 0 ||
V_143 * V_135 < V_136 * V_142 ) {
V_136 = V_143 ;
V_135 = V_142 ;
V_134 = V_141 ;
}
}
if ( V_135 == 0 ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
V_137 . V_123 = F_29 ( V_134 , V_135 ) ;
V_137 . V_124 = ! ! ( V_134 % V_135 ) ;
V_134 = V_135 = V_136 = 0 ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 ) {
unsigned int V_141 ;
unsigned int V_142 = V_131 [ V_128 ] . V_142 ;
unsigned int V_117 = V_119 -> V_125 ;
int V_143 ;
V_141 = F_31 ( V_117 , V_142 ) ;
if ( V_141 < V_131 [ V_128 ] . V_149 )
continue;
if ( V_141 > V_131 [ V_128 ] . V_148 )
V_141 = V_131 [ V_128 ] . V_148 ;
else {
unsigned int V_115 ;
V_115 = ( V_141 - V_131 [ V_128 ] . V_149 ) % V_131 [ V_128 ] . V_150 ;
if ( V_115 != 0 )
V_141 -= V_115 ;
}
V_143 = V_117 * V_142 - V_141 ;
if ( V_134 == 0 ||
V_143 * V_135 < V_136 * V_142 ) {
V_136 = V_143 ;
V_135 = V_142 ;
V_134 = V_141 ;
}
}
if ( V_135 == 0 ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
V_137 . V_125 = F_30 ( V_134 , V_135 ) ;
V_137 . V_126 = ! ! ( V_134 % V_135 ) ;
V_137 . integer = 0 ;
V_28 = F_34 ( V_119 , & V_137 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_39 ( V_119 ) ) {
if ( V_132 )
* V_132 = V_134 ;
if ( V_133 )
* V_133 = V_135 ;
}
return V_28 ;
}
int F_47 ( struct V_118 * V_119 , unsigned int V_151 ,
const unsigned int * V_152 , unsigned int V_153 )
{
unsigned int V_128 ;
struct V_118 V_154 ;
if ( ! V_151 ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
F_48 ( & V_154 ) ;
V_154 . V_123 = V_116 ;
V_154 . V_125 = 0 ;
for ( V_128 = 0 ; V_128 < V_151 ; V_128 ++ ) {
if ( V_153 && ! ( V_153 & ( 1 << V_128 ) ) )
continue;
if ( ! F_49 ( V_119 , V_152 [ V_128 ] ) )
continue;
V_154 . V_123 = V_123 ( V_154 . V_123 , V_152 [ V_128 ] ) ;
V_154 . V_125 = V_125 ( V_154 . V_125 , V_152 [ V_128 ] ) ;
}
return F_34 ( V_119 , & V_154 ) ;
}
static int F_50 ( struct V_118 * V_119 , unsigned int V_123 , unsigned int V_155 )
{
unsigned int V_12 ;
int V_121 = 0 ;
V_12 = ( V_119 -> V_123 - V_123 ) % V_155 ;
if ( V_12 != 0 || V_119 -> V_124 ) {
V_119 -> V_123 += V_155 - V_12 ;
V_121 = 1 ;
}
V_12 = ( V_119 -> V_125 - V_123 ) % V_155 ;
if ( V_12 != 0 || V_119 -> V_126 ) {
V_119 -> V_125 -= V_12 ;
V_121 = 1 ;
}
if ( F_36 ( V_119 ) ) {
V_119 -> V_127 = 1 ;
return - V_122 ;
}
return V_121 ;
}
int F_51 ( struct V_4 * V_5 , unsigned int V_156 ,
int V_157 ,
T_5 V_158 , void * V_159 ,
int V_160 , ... )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_164 * V_33 ;
unsigned int V_128 ;
T_6 args ;
va_start ( args , V_160 ) ;
if ( V_162 -> V_165 >= V_162 -> V_166 ) {
struct V_164 * V_167 ;
unsigned int V_168 = V_162 -> V_166 + 16 ;
V_167 = F_52 ( V_168 , sizeof( * V_33 ) , V_169 ) ;
if ( ! V_167 ) {
va_end ( args ) ;
return - V_170 ;
}
if ( V_162 -> V_171 ) {
memcpy ( V_167 , V_162 -> V_171 ,
V_162 -> V_165 * sizeof( * V_33 ) ) ;
F_53 ( V_162 -> V_171 ) ;
}
V_162 -> V_171 = V_167 ;
V_162 -> V_166 = V_168 ;
}
V_33 = & V_162 -> V_171 [ V_162 -> V_165 ] ;
V_33 -> V_156 = V_156 ;
V_33 -> V_158 = V_158 ;
V_33 -> V_157 = V_157 ;
V_33 -> V_159 = V_159 ;
V_128 = 0 ;
while ( 1 ) {
if ( F_3 ( V_128 >= F_54 ( V_33 -> V_172 ) ) ) {
va_end ( args ) ;
return - V_122 ;
}
V_33 -> V_172 [ V_128 ++ ] = V_160 ;
if ( V_160 < 0 )
break;
V_160 = va_arg ( args , int ) ;
}
V_162 -> V_165 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_55 ( struct V_4 * V_5 , T_7 V_157 ,
T_8 V_153 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_173 * V_174 = F_56 ( V_162 , V_157 ) ;
* V_174 -> V_175 &= V_153 ;
memset ( V_174 -> V_175 + 1 , 0 , ( V_176 - 32 ) / 8 ) ;
if ( * V_174 -> V_175 == 0 )
return - V_122 ;
return 0 ;
}
int F_57 ( struct V_4 * V_5 , T_7 V_157 ,
T_4 V_153 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_173 * V_174 = F_56 ( V_162 , V_157 ) ;
V_174 -> V_175 [ 0 ] &= ( T_8 ) V_153 ;
V_174 -> V_175 [ 1 ] &= ( T_8 ) ( V_153 >> 32 ) ;
memset ( V_174 -> V_175 + 2 , 0 , ( V_176 - 64 ) / 8 ) ;
if ( ! V_174 -> V_175 [ 0 ] && ! V_174 -> V_175 [ 1 ] )
return - V_122 ;
return 0 ;
}
int F_58 ( struct V_4 * V_5 , T_7 V_157 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
return F_59 ( F_60 ( V_162 , V_157 ) ) ;
}
int F_61 ( struct V_4 * V_5 , T_7 V_157 ,
unsigned int V_123 , unsigned int V_125 )
{
struct V_161 * V_162 = & V_5 -> V_163 ;
struct V_118 V_137 ;
V_137 . V_123 = V_123 ;
V_137 . V_125 = V_125 ;
V_137 . V_124 = V_137 . V_126 = 0 ;
V_137 . integer = 0 ;
return F_34 ( F_60 ( V_162 , V_157 ) , & V_137 ) ;
}
static int F_62 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
struct V_180 * V_152 = V_179 -> V_159 ;
return F_47 ( F_63 ( V_178 , V_179 -> V_157 ) , V_152 -> V_151 , V_152 -> V_152 , V_152 -> V_153 ) ;
}
int V_180 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_7 V_157 ,
const struct V_180 * V_181 )
{
return F_51 ( V_5 , V_156 , V_157 ,
F_62 , ( void * ) V_181 ,
V_157 , - 1 ) ;
}
static int F_64 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
struct V_182 * V_115 = V_179 -> V_159 ;
unsigned int V_141 = 0 , V_142 = 0 ;
int V_28 ;
V_28 = F_45 ( F_63 ( V_178 , V_179 -> V_157 ) ,
V_115 -> V_183 , V_115 -> V_131 , & V_141 , & V_142 ) ;
if ( V_28 >= 0 && V_142 && V_179 -> V_157 == V_184 ) {
V_178 -> V_185 = V_141 ;
V_178 -> V_186 = V_142 ;
}
return V_28 ;
}
int V_182 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_7 V_157 ,
struct V_182 * V_115 )
{
return F_51 ( V_5 , V_156 , V_157 ,
F_64 , V_115 ,
V_157 , - 1 ) ;
}
static int F_65 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
struct V_187 * V_115 = V_179 -> V_159 ;
unsigned int V_141 = 0 , V_142 = 0 ;
int V_28 = F_46 ( F_63 ( V_178 , V_179 -> V_157 ) ,
V_115 -> V_183 , V_115 -> V_131 , & V_141 , & V_142 ) ;
if ( V_28 >= 0 && V_142 && V_179 -> V_157 == V_184 ) {
V_178 -> V_185 = V_141 ;
V_178 -> V_186 = V_142 ;
}
return V_28 ;
}
int V_187 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_7 V_157 ,
struct V_187 * V_115 )
{
return F_51 ( V_5 , V_156 , V_157 ,
F_65 , V_115 ,
V_157 , - 1 ) ;
}
static int F_66 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
unsigned int V_181 = ( unsigned long ) V_179 -> V_159 ;
int V_188 = V_181 & 0xffff ;
unsigned int V_189 = V_181 >> 16 ;
struct V_118 * V_119 = F_63 ( V_178 , V_190 ) ;
if ( F_39 ( V_119 ) && F_67 ( V_119 ) == V_188 )
V_178 -> V_189 = V_189 ;
return 0 ;
}
int F_68 ( struct V_4 * V_5 ,
unsigned int V_156 ,
unsigned int V_188 ,
unsigned int V_189 )
{
unsigned long V_181 = ( V_189 << 16 ) | V_188 ;
return F_51 ( V_5 , V_156 , - 1 ,
F_66 ,
( void * ) V_181 ,
V_190 , - 1 ) ;
}
static int F_69 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
unsigned long V_155 = ( unsigned long ) V_179 -> V_159 ;
return F_50 ( F_63 ( V_178 , V_179 -> V_157 ) , 0 , V_155 ) ;
}
int F_70 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_7 V_157 ,
unsigned long V_155 )
{
return F_51 ( V_5 , V_156 , V_157 ,
F_69 , ( void * ) V_155 ,
V_157 , - 1 ) ;
}
static int F_71 ( struct V_177 * V_178 , struct V_164 * V_179 )
{
static unsigned int V_191 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_47 ( F_63 ( V_178 , V_179 -> V_157 ) ,
F_54 ( V_191 ) , V_191 , 0 ) ;
}
int F_72 ( struct V_4 * V_5 ,
unsigned int V_156 ,
T_7 V_157 )
{
return F_51 ( V_5 , V_156 , V_157 ,
F_71 , NULL ,
V_157 , - 1 ) ;
}
static int F_73 ( struct V_177 * V_178 ,
struct V_164 * V_179 )
{
unsigned int V_192 = ( unsigned int ) ( V_193 ) V_179 -> V_159 ;
struct V_118 * V_98 ;
V_98 = F_63 ( V_178 , V_184 ) ;
return F_47 ( V_98 , 1 , & V_192 , 0 ) ;
}
int F_74 ( struct V_4 * V_5 ,
unsigned int V_192 )
{
return F_51 ( V_5 , V_194 ,
V_184 ,
F_73 ,
( void * ) ( V_193 ) V_192 ,
V_184 , - 1 ) ;
}
static void F_75 ( struct V_177 * V_178 ,
T_7 V_157 )
{
if ( F_76 ( V_157 ) ) {
F_77 ( F_78 ( V_178 , V_157 ) ) ;
V_178 -> V_195 |= 1 << V_157 ;
V_178 -> V_196 |= 1 << V_157 ;
return;
}
if ( F_79 ( V_157 ) ) {
F_48 ( F_63 ( V_178 , V_157 ) ) ;
V_178 -> V_195 |= 1 << V_157 ;
V_178 -> V_196 |= 1 << V_157 ;
return;
}
F_80 () ;
}
void F_81 ( struct V_177 * V_178 )
{
unsigned int V_128 ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
for ( V_128 = V_197 ; V_128 <= V_198 ; V_128 ++ )
F_75 ( V_178 , V_128 ) ;
for ( V_128 = V_199 ; V_128 <= V_200 ; V_128 ++ )
F_75 ( V_178 , V_128 ) ;
V_178 -> V_102 = ~ 0U ;
}
int F_82 ( const struct V_177 * V_178 ,
T_7 V_157 , int * V_201 )
{
if ( F_76 ( V_157 ) ) {
const struct V_173 * V_153 = F_83 ( V_178 , V_157 ) ;
if ( ! F_84 ( V_153 ) )
return - V_122 ;
if ( V_201 )
* V_201 = 0 ;
return F_85 ( V_153 ) ;
}
if ( F_79 ( V_157 ) ) {
const struct V_118 * V_119 = F_86 ( V_178 , V_157 ) ;
if ( ! F_39 ( V_119 ) )
return - V_122 ;
if ( V_201 )
* V_201 = V_119 -> V_124 ;
return F_67 ( V_119 ) ;
}
return - V_122 ;
}
void F_87 ( struct V_177 * V_178 ,
T_7 V_157 )
{
if ( F_76 ( V_157 ) ) {
F_88 ( F_78 ( V_178 , V_157 ) ) ;
V_178 -> V_195 |= 1 << V_157 ;
V_178 -> V_196 |= 1 << V_157 ;
} else if ( F_79 ( V_157 ) ) {
F_37 ( F_63 ( V_178 , V_157 ) ) ;
V_178 -> V_195 |= 1 << V_157 ;
V_178 -> V_196 |= 1 << V_157 ;
} else {
F_80 () ;
}
}
static int F_89 ( struct V_177 * V_178 ,
T_7 V_157 )
{
int V_121 ;
if ( F_76 ( V_157 ) )
V_121 = F_90 ( F_78 ( V_178 , V_157 ) ) ;
else if ( F_79 ( V_157 ) )
V_121 = F_38 ( F_63 ( V_178 , V_157 ) ) ;
else
return - V_122 ;
if ( V_121 ) {
V_178 -> V_195 |= 1 << V_157 ;
V_178 -> V_196 |= 1 << V_157 ;
}
return V_121 ;
}
int F_91 ( struct V_1 * V_38 ,
struct V_177 * V_178 ,
T_7 V_157 , int * V_201 )
{
int V_121 = F_89 ( V_178 , V_157 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_178 -> V_196 ) {
int V_28 = F_92 ( V_38 , V_178 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_82 ( V_178 , V_157 , V_201 ) ;
}
static int F_93 ( struct V_177 * V_178 ,
T_7 V_157 )
{
int V_121 ;
if ( F_76 ( V_157 ) )
V_121 = F_94 ( F_78 ( V_178 , V_157 ) ) ;
else if ( F_79 ( V_157 ) )
V_121 = F_40 ( F_63 ( V_178 , V_157 ) ) ;
else
return - V_122 ;
if ( V_121 ) {
V_178 -> V_195 |= 1 << V_157 ;
V_178 -> V_196 |= 1 << V_157 ;
}
return V_121 ;
}
int F_95 ( struct V_1 * V_38 ,
struct V_177 * V_178 ,
T_7 V_157 , int * V_201 )
{
int V_121 = F_93 ( V_178 , V_157 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_178 -> V_196 ) {
int V_28 = F_92 ( V_38 , V_178 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_82 ( V_178 , V_157 , V_201 ) ;
}
int F_96 ( struct V_1 * V_38 ,
struct V_177 * V_178 )
{
static int V_202 [] = {
V_203 ,
V_204 ,
V_205 ,
V_206 ,
V_184 ,
V_207 ,
V_208 ,
V_209 ,
- 1
} ;
int V_28 , * V_120 ;
for ( V_120 = V_202 ; * V_120 != - 1 ; V_120 ++ ) {
if ( * V_120 != V_208 )
V_28 = F_91 ( V_38 , V_178 , * V_120 , NULL ) ;
else
V_28 = F_95 ( V_38 , V_178 , * V_120 , NULL ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
void * V_210 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_211 ;
F_98 ( V_2 , V_211 ) ;
if ( F_99 ( V_2 ) &&
F_25 ( V_2 ) >= 0 )
V_5 -> V_21 -> V_22 %= V_5 -> V_17 ;
else
V_5 -> V_21 -> V_22 = 0 ;
F_100 ( V_2 , V_211 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
void * V_210 )
{
struct V_212 * V_102 = V_210 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_188 ;
if ( ! ( V_5 -> V_102 & V_213 ) ) {
V_102 -> V_214 = - 1 ;
return 0 ;
}
V_188 = F_102 ( V_5 -> V_31 ) ;
if ( V_188 < 0 )
return V_188 ;
V_102 -> V_214 = 0 ;
switch ( V_5 -> V_23 ) {
case V_25 :
case V_24 :
V_102 -> V_215 = V_102 -> V_216 * V_188 ;
V_102 -> V_155 = V_5 -> V_32 * V_188 ;
break;
case V_217 :
case V_218 :
{
T_3 V_219 = V_5 -> V_35 / V_5 -> V_32 ;
V_102 -> V_215 = V_102 -> V_216 * V_219 * 8 ;
V_102 -> V_155 = V_188 ;
break;
}
default:
F_80 () ;
break;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
void * V_210 )
{
struct V_177 * V_178 = V_210 ;
T_9 V_31 ;
int V_32 , V_188 ;
V_178 -> V_220 = V_2 -> V_5 -> V_101 . V_220 ;
if ( ! ( V_2 -> V_5 -> V_101 . V_102 & V_221 ) ) {
V_31 = F_104 ( V_178 ) ;
V_32 = F_105 ( V_178 ) ;
V_188 = F_102 ( V_31 ) ;
V_178 -> V_220 /= V_188 * V_32 ;
}
return 0 ;
}
int F_106 ( struct V_1 * V_2 ,
unsigned int V_222 , void * V_210 )
{
switch ( V_222 ) {
case V_223 :
return 0 ;
case V_224 :
return F_97 ( V_2 , V_210 ) ;
case V_225 :
return F_101 ( V_2 , V_210 ) ;
case V_226 :
return F_103 ( V_2 , V_210 ) ;
}
return - V_227 ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_211 ;
if ( F_108 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_228 )
V_5 -> V_228 ( V_2 ) ;
F_98 ( V_2 , V_211 ) ;
if ( ! F_99 ( V_2 ) ||
F_22 ( V_2 , 1 ) < 0 )
goto V_229;
if ( V_2 -> V_230 )
F_109 ( V_2 -> V_231 , 1 ) ;
V_229:
F_100 ( V_2 , V_211 ) ;
if ( V_5 -> V_232 )
V_5 -> V_232 ( V_2 ) ;
F_110 ( & V_5 -> V_233 , V_234 , V_235 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
T_1 * V_236 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_237 = V_2 -> V_42 == V_67 ;
T_10 V_238 ;
int V_28 = 0 ;
T_1 V_20 = 0 ;
long V_239 , V_240 ;
F_112 ( & V_238 , V_241 ) ;
F_113 ( V_242 ) ;
F_114 ( & V_5 -> V_74 , & V_238 ) ;
if ( V_5 -> V_94 )
V_239 = V_243 ;
else {
V_239 = 10 ;
if ( V_5 -> V_98 ) {
long V_137 = V_5 -> V_62 * 2 / V_5 -> V_98 ;
V_239 = V_125 ( V_137 , V_239 ) ;
}
V_239 = F_115 ( V_239 * 1000 ) ;
}
for (; ; ) {
if ( F_116 ( V_241 ) ) {
V_28 = - V_244 ;
break;
}
if ( V_237 )
V_20 = F_18 ( V_5 ) ;
else
V_20 = F_19 ( V_5 ) ;
if ( V_20 >= V_5 -> V_73 )
break;
F_117 ( V_2 ) ;
V_240 = F_118 ( V_239 ) ;
F_119 ( V_2 ) ;
F_113 ( V_242 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_245 :
V_28 = - V_246 ;
goto V_247;
case V_47 :
V_28 = - V_71 ;
goto V_247;
case V_70 :
if ( V_237 )
V_28 = - V_71 ;
else
V_20 = 0 ;
goto V_247;
case V_248 :
case V_249 :
case V_250 :
V_28 = - V_251 ;
goto V_247;
}
if ( ! V_240 ) {
F_12 ( L_22 ,
V_237 ? L_23 : L_24 ) ;
V_28 = - V_252 ;
break;
}
}
V_247:
F_113 ( V_253 ) ;
F_120 ( & V_5 -> V_74 , & V_238 ) ;
* V_236 = V_20 ;
return V_28 ;
}
static int F_121 ( struct V_1 * V_2 ,
unsigned int V_254 ,
unsigned long V_255 , unsigned int V_256 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_11 * V_257 = ( char T_11 * ) V_255 + F_4 ( V_5 , V_256 ) ;
if ( V_2 -> V_26 -> V_258 ) {
if ( ( V_28 = V_2 -> V_26 -> V_258 ( V_2 , - 1 , V_254 , V_257 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_254 ) ;
if ( F_122 ( V_29 , V_257 , F_4 ( V_5 , V_6 ) ) )
return - V_259 ;
}
return 0 ;
}
static T_2 F_123 ( struct V_1 * V_2 ,
unsigned long V_255 ,
T_1 V_219 ,
int V_260 ,
T_12 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_261 = 0 ;
T_1 V_214 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_219 == 0 )
return 0 ;
F_119 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_262 :
case V_263 :
case V_264 :
break;
case V_47 :
V_28 = - V_71 ;
goto V_265;
case V_245 :
V_28 = - V_246 ;
goto V_265;
default:
V_28 = - V_251 ;
goto V_265;
}
V_5 -> V_73 = V_5 -> V_14 -> V_75 ? : 1 ;
if ( V_5 -> V_21 -> V_69 == V_263 )
F_25 ( V_2 ) ;
V_20 = F_18 ( V_5 ) ;
while ( V_219 > 0 ) {
T_1 V_6 , V_15 , V_266 ;
T_1 V_267 ;
if ( ! V_20 ) {
if ( V_260 ) {
V_28 = - V_268 ;
goto V_265;
}
V_5 -> V_73 = F_124 ( T_1 , V_219 ,
V_5 -> V_14 -> V_75 ? : 1 ) ;
V_28 = F_111 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_265;
}
V_6 = V_219 > V_20 ? V_20 : V_219 ;
V_267 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_267 )
V_6 = V_267 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_73 = 0 ;
F_117 ( V_2 ) ;
return - V_122 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_266 = V_15 % V_5 -> V_17 ;
F_117 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_266 , V_255 , V_214 , V_6 ) ;
F_119 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
switch ( V_5 -> V_21 -> V_69 ) {
case V_47 :
V_28 = - V_71 ;
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
V_214 += V_6 ;
V_219 -= V_6 ;
V_261 += V_6 ;
V_20 -= V_6 ;
if ( V_5 -> V_21 -> V_69 == V_262 &&
F_2 ( V_5 ) >= ( T_2 ) V_5 -> V_270 ) {
V_28 = F_125 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
}
}
V_265:
V_5 -> V_73 = 0 ;
if ( V_261 > 0 && V_28 >= 0 )
F_17 ( V_2 , V_5 ) ;
F_117 ( V_2 ) ;
return V_261 > 0 ? ( T_2 ) V_261 : V_28 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_108 ( V_2 ) )
return - V_227 ;
V_5 = V_2 -> V_5 ;
if ( F_3 ( ! V_2 -> V_26 -> V_258 && ! V_5 -> V_30 ) )
return - V_122 ;
if ( V_5 -> V_21 -> V_69 == V_248 )
return - V_251 ;
return 0 ;
}
T_2 F_127 ( struct V_1 * V_2 , const void T_11 * V_257 , T_1 V_219 )
{
struct V_4 * V_5 ;
int V_260 ;
int V_28 ;
V_28 = F_126 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_260 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_24 &&
V_5 -> V_32 > 1 )
return - V_122 ;
return F_123 ( V_2 , ( unsigned long ) V_257 , V_219 , V_260 ,
F_121 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
unsigned int V_254 ,
unsigned long V_255 , unsigned int V_256 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_11 * * V_273 = ( void T_11 * * ) V_255 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_258 ) {
if ( F_3 ( ! V_2 -> V_26 -> V_27 ) )
return - V_122 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
if ( * V_273 == NULL ) {
if ( ( V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_254 , V_6 ) ) < 0 )
return V_28 ;
} else {
char T_11 * V_257 = * V_273 + F_6 ( V_5 , V_256 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_258 ( V_2 , V_33 , V_254 , V_257 , V_6 ) ) < 0 )
return V_28 ;
}
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_254 ) ;
if ( * V_273 == NULL ) {
F_5 ( V_5 -> V_31 , V_29 , V_6 ) ;
} else {
char T_11 * V_257 = * V_273 + F_6 ( V_5 , V_256 ) ;
if ( F_122 ( V_29 , V_257 , F_6 ( V_5 , V_6 ) ) )
return - V_259 ;
}
}
}
return 0 ;
}
T_2 F_129 ( struct V_1 * V_2 ,
void T_11 * * V_273 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_260 ;
int V_28 ;
V_28 = F_126 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_260 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_218 )
return - V_122 ;
return F_123 ( V_2 , ( unsigned long ) V_273 , V_6 ,
V_260 , F_128 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
unsigned int V_254 ,
unsigned long V_255 , unsigned int V_256 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_11 * V_257 = ( char T_11 * ) V_255 + F_4 ( V_5 , V_256 ) ;
if ( V_2 -> V_26 -> V_258 ) {
if ( ( V_28 = V_2 -> V_26 -> V_258 ( V_2 , - 1 , V_254 , V_257 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_254 ) ;
if ( F_131 ( V_257 , V_29 , F_4 ( V_5 , V_6 ) ) )
return - V_259 ;
}
return 0 ;
}
static T_2 F_132 ( struct V_1 * V_2 ,
unsigned long V_255 ,
T_1 V_219 ,
int V_260 ,
T_12 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_261 = 0 ;
T_1 V_214 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_219 == 0 )
return 0 ;
F_119 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_262 :
if ( V_219 >= V_5 -> V_270 ) {
V_28 = F_125 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
}
break;
case V_70 :
case V_263 :
case V_264 :
break;
case V_47 :
V_28 = - V_71 ;
goto V_265;
case V_245 :
V_28 = - V_246 ;
goto V_265;
default:
V_28 = - V_251 ;
goto V_265;
}
V_5 -> V_73 = V_5 -> V_14 -> V_75 ? : 1 ;
if ( V_5 -> V_21 -> V_69 == V_263 )
F_25 ( V_2 ) ;
V_20 = F_19 ( V_5 ) ;
while ( V_219 > 0 ) {
T_1 V_6 , V_15 , V_266 ;
T_1 V_267 ;
if ( ! V_20 ) {
if ( V_5 -> V_21 -> V_69 ==
V_70 ) {
F_10 ( V_2 , V_249 ) ;
goto V_265;
}
if ( V_260 ) {
V_28 = - V_268 ;
goto V_265;
}
V_5 -> V_73 = F_124 ( T_1 , V_219 ,
V_5 -> V_14 -> V_75 ? : 1 ) ;
V_28 = F_111 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_265;
if ( ! V_20 )
continue;
}
V_6 = V_219 > V_20 ? V_20 : V_219 ;
V_267 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_267 )
V_6 = V_267 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_73 = 0 ;
F_117 ( V_2 ) ;
return - V_122 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_266 = V_15 % V_5 -> V_17 ;
F_117 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_266 , V_255 , V_214 , V_6 ) ;
F_119 ( V_2 ) ;
if ( V_28 < 0 )
goto V_265;
switch ( V_5 -> V_21 -> V_69 ) {
case V_47 :
V_28 = - V_71 ;
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
V_214 += V_6 ;
V_219 -= V_6 ;
V_261 += V_6 ;
V_20 -= V_6 ;
}
V_265:
V_5 -> V_73 = 0 ;
if ( V_261 > 0 && V_28 >= 0 )
F_17 ( V_2 , V_5 ) ;
F_117 ( V_2 ) ;
return V_261 > 0 ? ( T_2 ) V_261 : V_28 ;
}
T_2 F_133 ( struct V_1 * V_2 , void T_11 * V_257 , T_1 V_219 )
{
struct V_4 * V_5 ;
int V_260 ;
int V_28 ;
V_28 = F_126 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_260 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_24 )
return - V_122 ;
return F_132 ( V_2 , ( unsigned long ) V_257 , V_219 , V_260 , F_130 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
unsigned int V_254 ,
unsigned long V_255 , unsigned int V_256 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_11 * * V_273 = ( void T_11 * * ) V_255 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_258 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
char T_11 * V_257 ;
if ( * V_273 == NULL )
continue;
V_257 = * V_273 + F_6 ( V_5 , V_256 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_258 ( V_2 , V_33 , V_254 , V_257 , V_6 ) ) < 0 )
return V_28 ;
}
} else {
T_1 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_273 ) {
char * V_29 ;
char T_11 * V_257 ;
if ( * V_273 == NULL )
continue;
V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_254 ) ;
V_257 = * V_273 + F_6 ( V_5 , V_256 ) ;
if ( F_131 ( V_257 , V_29 , F_6 ( V_5 , V_6 ) ) )
return - V_259 ;
}
}
return 0 ;
}
T_2 F_135 ( struct V_1 * V_2 ,
void T_11 * * V_273 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_260 ;
int V_28 ;
V_28 = F_126 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 -> V_69 == V_248 )
return - V_251 ;
V_260 = ! ! ( V_2 -> V_271 & V_272 ) ;
if ( V_5 -> V_23 != V_218 )
return - V_122 ;
return F_132 ( V_2 , ( unsigned long ) V_273 , V_6 , V_260 , F_134 ) ;
}
