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
static void F_7 ( struct V_1 * V_2 ,
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
V_63 = V_5 -> V_21 -> V_22 ;
V_50 = V_2 -> V_26 -> V_81 ( V_2 ) ;
if ( V_50 == V_82 ) {
F_8 ( V_2 ) ;
return - V_71 ;
}
if ( V_50 >= V_5 -> V_17 ) {
if ( F_23 () ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_16 ( V_2 ) ;
F_12 ( V_83 L_7
L_8 ,
V_36 , V_50 , V_5 -> V_17 ,
V_5 -> V_62 ) ;
}
V_50 = 0 ;
}
V_50 -= V_50 % V_5 -> V_84 ;
if ( F_11 ( V_2 , V_85 ) )
F_14 ( V_2 , V_50 , V_51 ) ;
V_77 = V_5 -> V_64 ;
V_3 = V_77 + V_50 ;
if ( V_51 ) {
V_79 = V_5 -> V_86 + V_5 -> V_62 ;
if ( V_79 > V_3 ) {
V_78 = V_61 - V_5 -> V_87 ;
if ( V_78 > V_5 -> V_88 / 2 ) {
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 )
V_77 = 0 ;
V_3 = V_77 + V_50 ;
goto V_89;
}
}
}
if ( V_3 < V_63 ) {
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 )
V_77 = 0 ;
V_3 = V_77 + V_50 ;
}
V_89:
V_79 = V_3 - V_63 ;
if ( V_79 < 0 )
V_79 += V_5 -> V_10 ;
if ( F_11 ( V_2 , V_51 ?
V_90 : V_91 ) ) {
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
if ( V_5 -> V_92 ) {
T_2 V_93 ;
V_80 = V_61 - V_5 -> V_87 ;
if ( V_80 < V_5 -> V_88 / 2 )
goto V_94;
V_78 = V_80 - V_79 * V_95 / V_5 -> V_96 ;
V_93 = V_5 -> V_88 / 2 + 1 ;
while ( V_78 > V_93 ) {
V_79 += V_5 -> V_17 ;
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 )
V_77 = 0 ;
V_3 = V_77 + V_50 ;
V_78 -= V_5 -> V_88 ;
}
goto V_94;
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
if ( ! F_11 ( V_2 , V_97 ) )
goto V_98;
if ( V_5 -> V_99 . V_100 & V_101 )
goto V_98;
V_78 = V_79 ;
if ( V_78 < V_5 -> V_102 )
goto V_98;
V_78 -= V_5 -> V_102 ;
V_80 = V_61 - V_5 -> V_87 ;
if ( ( ( V_78 * V_95 ) / V_5 -> V_96 ) > V_80 + V_95 / 100 ) {
V_79 = V_80 /
( ( ( V_5 -> V_62 * V_95 ) / V_5 -> V_96 )
+ V_95 / 100 ) ;
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
( ( V_78 * V_95 ) / V_5 -> V_96 ) , V_77 ,
( unsigned long ) V_63 ,
( unsigned long ) V_3 ) ;
V_79 = 0 ;
V_77 = V_3 - ( V_3 % V_5 -> V_17 ) ;
}
V_98:
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
V_94:
if ( V_5 -> V_21 -> V_22 == V_3 )
return 0 ;
if ( V_2 -> V_42 == V_67 &&
V_5 -> V_9 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_51 ) {
V_79 = V_3 - V_5 -> V_86 ;
if ( V_79 < 0 )
V_79 += V_5 -> V_10 ;
V_79 -= ( T_1 ) V_79 % V_5 -> V_62 ;
V_5 -> V_86 += V_79 ;
if ( V_5 -> V_86 >= V_5 -> V_10 )
V_5 -> V_86 -= V_5 -> V_10 ;
}
V_5 -> V_64 = V_77 ;
V_5 -> V_21 -> V_22 = V_3 ;
V_5 -> V_87 = V_61 ;
if ( V_5 -> V_43 == V_44 )
F_9 ( V_5 , (struct V_45 * ) & V_5 -> V_21 -> V_46 ) ;
return F_17 ( V_2 , V_5 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , 0 ) ;
}
void F_26 ( struct V_103 * V_38 , int V_104 , struct V_105 * V_26 )
{
struct V_106 * V_42 = & V_38 -> V_107 [ V_104 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_42 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_108 )
V_2 -> V_26 = V_26 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_109 . V_110 [ 0 ] = V_2 -> V_38 -> V_39 -> V_40 ;
V_5 -> V_109 . V_110 [ 1 ] = - 1 ;
V_5 -> V_109 . V_110 [ 2 ] = - 1 ;
V_5 -> V_109 . V_110 [ 3 ] = - 1 ;
}
static inline unsigned int F_28 ( unsigned int V_111 , unsigned int V_112 ,
unsigned int * V_113 )
{
if ( V_112 == 0 ) {
* V_113 = 0 ;
return V_114 ;
}
* V_113 = V_111 % V_112 ;
return V_111 / V_112 ;
}
static inline unsigned int F_29 ( unsigned int V_111 , unsigned int V_112 )
{
if ( V_112 == 0 )
return V_114 ;
return V_111 / V_112 ;
}
static inline unsigned int F_30 ( unsigned int V_111 , unsigned int V_112 )
{
unsigned int V_113 ;
unsigned int V_115 ;
if ( V_112 == 0 )
return V_114 ;
V_115 = F_28 ( V_111 , V_112 , & V_113 ) ;
if ( V_113 )
++ V_115 ;
return V_115 ;
}
static inline unsigned int F_31 ( unsigned int V_111 , unsigned int V_112 )
{
if ( V_111 == 0 )
return 0 ;
if ( F_29 ( V_114 , V_111 ) < V_112 )
return V_114 ;
return V_111 * V_112 ;
}
static inline unsigned int F_32 ( unsigned int V_111 , unsigned int V_112 ,
unsigned int V_33 , unsigned int * V_113 )
{
T_4 V_12 = ( T_4 ) V_111 * V_112 ;
if ( V_33 == 0 ) {
F_3 ( ! V_12 ) ;
* V_113 = 0 ;
return V_114 ;
}
V_12 = F_33 ( V_12 , V_33 , V_113 ) ;
if ( V_12 >= V_114 ) {
* V_113 = 0 ;
return V_114 ;
}
return V_12 ;
}
int F_34 ( struct V_116 * V_117 , const struct V_116 * V_118 )
{
int V_119 = 0 ;
if ( F_3 ( F_35 ( V_117 ) ) )
return - V_120 ;
if ( V_117 -> V_121 < V_118 -> V_121 ) {
V_117 -> V_121 = V_118 -> V_121 ;
V_117 -> V_122 = V_118 -> V_122 ;
V_119 = 1 ;
} else if ( V_117 -> V_121 == V_118 -> V_121 && ! V_117 -> V_122 && V_118 -> V_122 ) {
V_117 -> V_122 = 1 ;
V_119 = 1 ;
}
if ( V_117 -> V_123 > V_118 -> V_123 ) {
V_117 -> V_123 = V_118 -> V_123 ;
V_117 -> V_124 = V_118 -> V_124 ;
V_119 = 1 ;
} else if ( V_117 -> V_123 == V_118 -> V_123 && ! V_117 -> V_124 && V_118 -> V_124 ) {
V_117 -> V_124 = 1 ;
V_119 = 1 ;
}
if ( ! V_117 -> integer && V_118 -> integer ) {
V_117 -> integer = 1 ;
V_119 = 1 ;
}
if ( V_117 -> integer ) {
if ( V_117 -> V_122 ) {
V_117 -> V_121 ++ ;
V_117 -> V_122 = 0 ;
}
if ( V_117 -> V_124 ) {
V_117 -> V_123 -- ;
V_117 -> V_124 = 0 ;
}
} else if ( ! V_117 -> V_122 && ! V_117 -> V_124 && V_117 -> V_121 == V_117 -> V_123 )
V_117 -> integer = 1 ;
if ( F_36 ( V_117 ) ) {
F_37 ( V_117 ) ;
return - V_120 ;
}
return V_119 ;
}
static int F_38 ( struct V_116 * V_117 )
{
if ( F_3 ( F_35 ( V_117 ) ) )
return - V_120 ;
if ( F_39 ( V_117 ) )
return 0 ;
V_117 -> V_123 = V_117 -> V_121 ;
V_117 -> V_124 = V_117 -> V_122 ;
if ( V_117 -> V_124 )
V_117 -> V_123 ++ ;
return 1 ;
}
static int F_40 ( struct V_116 * V_117 )
{
if ( F_3 ( F_35 ( V_117 ) ) )
return - V_120 ;
if ( F_39 ( V_117 ) )
return 0 ;
V_117 -> V_121 = V_117 -> V_123 ;
V_117 -> V_122 = V_117 -> V_124 ;
if ( V_117 -> V_122 )
V_117 -> V_121 -- ;
return 1 ;
}
void F_41 ( const struct V_116 * V_111 , const struct V_116 * V_112 , struct V_116 * V_33 )
{
if ( V_111 -> V_125 || V_112 -> V_125 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_125 = 0 ;
V_33 -> V_121 = F_31 ( V_111 -> V_121 , V_112 -> V_121 ) ;
V_33 -> V_122 = ( V_111 -> V_122 || V_112 -> V_122 ) ;
V_33 -> V_123 = F_31 ( V_111 -> V_123 , V_112 -> V_123 ) ;
V_33 -> V_124 = ( V_111 -> V_124 || V_112 -> V_124 ) ;
V_33 -> integer = ( V_111 -> integer && V_112 -> integer ) ;
}
void F_42 ( const struct V_116 * V_111 , const struct V_116 * V_112 , struct V_116 * V_33 )
{
unsigned int V_113 ;
if ( V_111 -> V_125 || V_112 -> V_125 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_125 = 0 ;
V_33 -> V_121 = F_28 ( V_111 -> V_121 , V_112 -> V_123 , & V_113 ) ;
V_33 -> V_122 = ( V_113 || V_111 -> V_122 || V_112 -> V_124 ) ;
if ( V_112 -> V_121 > 0 ) {
V_33 -> V_123 = F_28 ( V_111 -> V_123 , V_112 -> V_121 , & V_113 ) ;
if ( V_113 ) {
V_33 -> V_123 ++ ;
V_33 -> V_124 = 1 ;
} else
V_33 -> V_124 = ( V_111 -> V_124 || V_112 -> V_122 ) ;
} else {
V_33 -> V_123 = V_114 ;
V_33 -> V_124 = 0 ;
}
V_33 -> integer = 0 ;
}
void F_43 ( const struct V_116 * V_111 , const struct V_116 * V_112 ,
unsigned int V_126 , struct V_116 * V_33 )
{
unsigned int V_113 ;
if ( V_111 -> V_125 || V_112 -> V_125 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_125 = 0 ;
V_33 -> V_121 = F_32 ( V_111 -> V_121 , V_112 -> V_121 , V_126 , & V_113 ) ;
V_33 -> V_122 = ( V_113 || V_111 -> V_122 || V_112 -> V_122 ) ;
V_33 -> V_123 = F_32 ( V_111 -> V_123 , V_112 -> V_123 , V_126 , & V_113 ) ;
if ( V_113 ) {
V_33 -> V_123 ++ ;
V_33 -> V_124 = 1 ;
} else
V_33 -> V_124 = ( V_111 -> V_124 || V_112 -> V_124 ) ;
V_33 -> integer = 0 ;
}
void F_44 ( const struct V_116 * V_111 , unsigned int V_126 ,
const struct V_116 * V_112 , struct V_116 * V_33 )
{
unsigned int V_113 ;
if ( V_111 -> V_125 || V_112 -> V_125 ) {
F_37 ( V_33 ) ;
return;
}
V_33 -> V_125 = 0 ;
V_33 -> V_121 = F_32 ( V_111 -> V_121 , V_126 , V_112 -> V_123 , & V_113 ) ;
V_33 -> V_122 = ( V_113 || V_111 -> V_122 || V_112 -> V_124 ) ;
if ( V_112 -> V_121 > 0 ) {
V_33 -> V_123 = F_32 ( V_111 -> V_123 , V_126 , V_112 -> V_121 , & V_113 ) ;
if ( V_113 ) {
V_33 -> V_123 ++ ;
V_33 -> V_124 = 1 ;
} else
V_33 -> V_124 = ( V_111 -> V_124 || V_112 -> V_122 ) ;
} else {
V_33 -> V_123 = V_114 ;
V_33 -> V_124 = 0 ;
}
V_33 -> integer = 0 ;
}
int F_45 ( struct V_116 * V_117 ,
unsigned int V_127 , struct V_128 * V_129 ,
unsigned int * V_130 , unsigned int * V_131 )
{
unsigned int V_132 , V_133 ;
int V_134 ;
unsigned int V_126 ;
struct V_116 V_135 ;
int V_28 ;
unsigned int V_136 , V_137 ;
int V_138 ;
V_132 = V_133 = V_134 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
unsigned int V_139 = V_129 [ V_126 ] . V_139 ;
unsigned int V_140 ;
unsigned int V_115 = V_117 -> V_121 ;
int V_141 ;
if ( V_115 == 0 )
V_115 = 1 ;
V_140 = F_30 ( V_139 , V_115 ) ;
if ( V_140 < V_129 [ V_126 ] . V_142 )
continue;
if ( V_140 > V_129 [ V_126 ] . V_143 )
V_140 = V_129 [ V_126 ] . V_143 ;
else {
unsigned int V_113 ;
V_113 = ( V_140 - V_129 [ V_126 ] . V_142 ) % V_129 [ V_126 ] . V_144 ;
if ( V_113 != 0 )
V_140 -= V_113 ;
}
V_141 = V_139 - V_115 * V_140 ;
if ( V_141 < 0 )
V_141 = - V_141 ;
if ( V_132 == 0 ||
V_141 * V_133 < V_134 * V_140 ) {
V_134 = V_141 ;
V_133 = V_140 ;
V_132 = V_139 ;
}
}
if ( V_133 == 0 ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
V_135 . V_121 = F_29 ( V_132 , V_133 ) ;
V_135 . V_122 = ! ! ( V_132 % V_133 ) ;
V_136 = V_132 ;
V_138 = V_134 ;
V_137 = V_133 ;
V_132 = V_133 = V_134 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
unsigned int V_139 = V_129 [ V_126 ] . V_139 ;
unsigned int V_140 ;
unsigned int V_115 = V_117 -> V_123 ;
int V_141 ;
if ( V_115 == 0 ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
V_140 = F_29 ( V_139 , V_115 ) ;
if ( V_140 > V_129 [ V_126 ] . V_143 )
continue;
if ( V_140 < V_129 [ V_126 ] . V_142 )
V_140 = V_129 [ V_126 ] . V_142 ;
else {
unsigned int V_113 ;
V_113 = ( V_140 - V_129 [ V_126 ] . V_142 ) % V_129 [ V_126 ] . V_144 ;
if ( V_113 != 0 )
V_140 += V_129 [ V_126 ] . V_144 - V_113 ;
}
V_141 = V_115 * V_140 - V_139 ;
if ( V_141 < 0 )
V_141 = - V_141 ;
if ( V_132 == 0 ||
V_141 * V_133 < V_134 * V_140 ) {
V_134 = V_141 ;
V_133 = V_140 ;
V_132 = V_139 ;
}
}
if ( V_133 == 0 ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
V_135 . V_123 = F_30 ( V_132 , V_133 ) ;
V_135 . V_124 = ! ! ( V_132 % V_133 ) ;
V_135 . integer = 0 ;
V_28 = F_34 ( V_117 , & V_135 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_39 ( V_117 ) ) {
if ( V_134 * V_137 < V_138 * V_133 ) {
V_136 = V_132 ;
V_137 = V_133 ;
}
if ( V_130 )
* V_130 = V_136 ;
if ( V_131 )
* V_131 = V_137 ;
}
return V_28 ;
}
static int F_46 ( struct V_116 * V_117 ,
unsigned int V_127 , struct V_145 * V_129 ,
unsigned int * V_130 , unsigned int * V_131 )
{
unsigned int V_132 , V_134 , V_133 ;
unsigned int V_126 ;
struct V_116 V_135 ;
int V_28 ;
V_132 = V_133 = V_134 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
unsigned int V_139 ;
unsigned int V_140 = V_129 [ V_126 ] . V_140 ;
unsigned int V_115 = V_117 -> V_121 ;
int V_141 ;
V_139 = F_31 ( V_115 , V_140 ) ;
if ( V_139 > V_129 [ V_126 ] . V_146 )
continue;
if ( V_139 < V_129 [ V_126 ] . V_147 )
V_139 = V_129 [ V_126 ] . V_146 ;
else {
unsigned int V_113 ;
V_113 = ( V_139 - V_129 [ V_126 ] . V_147 ) % V_129 [ V_126 ] . V_148 ;
if ( V_113 != 0 )
V_139 += V_129 [ V_126 ] . V_148 - V_113 ;
}
V_141 = V_139 - V_115 * V_140 ;
if ( V_132 == 0 ||
V_141 * V_133 < V_134 * V_140 ) {
V_134 = V_141 ;
V_133 = V_140 ;
V_132 = V_139 ;
}
}
if ( V_133 == 0 ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
V_135 . V_121 = F_29 ( V_132 , V_133 ) ;
V_135 . V_122 = ! ! ( V_132 % V_133 ) ;
V_132 = V_133 = V_134 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
unsigned int V_139 ;
unsigned int V_140 = V_129 [ V_126 ] . V_140 ;
unsigned int V_115 = V_117 -> V_123 ;
int V_141 ;
V_139 = F_31 ( V_115 , V_140 ) ;
if ( V_139 < V_129 [ V_126 ] . V_147 )
continue;
if ( V_139 > V_129 [ V_126 ] . V_146 )
V_139 = V_129 [ V_126 ] . V_146 ;
else {
unsigned int V_113 ;
V_113 = ( V_139 - V_129 [ V_126 ] . V_147 ) % V_129 [ V_126 ] . V_148 ;
if ( V_113 != 0 )
V_139 -= V_113 ;
}
V_141 = V_115 * V_140 - V_139 ;
if ( V_132 == 0 ||
V_141 * V_133 < V_134 * V_140 ) {
V_134 = V_141 ;
V_133 = V_140 ;
V_132 = V_139 ;
}
}
if ( V_133 == 0 ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
V_135 . V_123 = F_30 ( V_132 , V_133 ) ;
V_135 . V_124 = ! ! ( V_132 % V_133 ) ;
V_135 . integer = 0 ;
V_28 = F_34 ( V_117 , & V_135 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_39 ( V_117 ) ) {
if ( V_130 )
* V_130 = V_132 ;
if ( V_131 )
* V_131 = V_133 ;
}
return V_28 ;
}
int F_47 ( struct V_116 * V_117 , unsigned int V_149 , unsigned int * V_150 , unsigned int V_151 )
{
unsigned int V_126 ;
struct V_116 V_152 ;
if ( ! V_149 ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
F_48 ( & V_152 ) ;
V_152 . V_121 = V_114 ;
V_152 . V_123 = 0 ;
for ( V_126 = 0 ; V_126 < V_149 ; V_126 ++ ) {
if ( V_151 && ! ( V_151 & ( 1 << V_126 ) ) )
continue;
if ( ! F_49 ( V_117 , V_150 [ V_126 ] ) )
continue;
V_152 . V_121 = V_121 ( V_152 . V_121 , V_150 [ V_126 ] ) ;
V_152 . V_123 = V_123 ( V_152 . V_123 , V_150 [ V_126 ] ) ;
}
return F_34 ( V_117 , & V_152 ) ;
}
static int F_50 ( struct V_116 * V_117 , unsigned int V_121 , unsigned int V_153 )
{
unsigned int V_12 ;
int V_119 = 0 ;
V_12 = ( V_117 -> V_121 - V_121 ) % V_153 ;
if ( V_12 != 0 || V_117 -> V_122 ) {
V_117 -> V_121 += V_153 - V_12 ;
V_119 = 1 ;
}
V_12 = ( V_117 -> V_123 - V_121 ) % V_153 ;
if ( V_12 != 0 || V_117 -> V_124 ) {
V_117 -> V_123 -= V_12 ;
V_119 = 1 ;
}
if ( F_36 ( V_117 ) ) {
V_117 -> V_125 = 1 ;
return - V_120 ;
}
return V_119 ;
}
int F_51 ( struct V_4 * V_5 , unsigned int V_154 ,
int V_155 ,
T_5 V_156 , void * V_157 ,
int V_158 , ... )
{
struct V_159 * V_160 = & V_5 -> V_161 ;
struct V_162 * V_33 ;
unsigned int V_126 ;
T_6 args ;
va_start ( args , V_158 ) ;
if ( V_160 -> V_163 >= V_160 -> V_164 ) {
struct V_162 * V_165 ;
unsigned int V_166 = V_160 -> V_164 + 16 ;
V_165 = F_52 ( V_166 , sizeof( * V_33 ) , V_167 ) ;
if ( ! V_165 ) {
va_end ( args ) ;
return - V_168 ;
}
if ( V_160 -> V_169 ) {
memcpy ( V_165 , V_160 -> V_169 ,
V_160 -> V_163 * sizeof( * V_33 ) ) ;
F_53 ( V_160 -> V_169 ) ;
}
V_160 -> V_169 = V_165 ;
V_160 -> V_164 = V_166 ;
}
V_33 = & V_160 -> V_169 [ V_160 -> V_163 ] ;
V_33 -> V_154 = V_154 ;
V_33 -> V_156 = V_156 ;
V_33 -> V_155 = V_155 ;
V_33 -> V_157 = V_157 ;
V_126 = 0 ;
while ( 1 ) {
if ( F_3 ( V_126 >= F_54 ( V_33 -> V_170 ) ) ) {
va_end ( args ) ;
return - V_120 ;
}
V_33 -> V_170 [ V_126 ++ ] = V_158 ;
if ( V_158 < 0 )
break;
V_158 = va_arg ( args , int ) ;
}
V_160 -> V_163 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_55 ( struct V_4 * V_5 , T_7 V_155 ,
T_8 V_151 )
{
struct V_159 * V_160 = & V_5 -> V_161 ;
struct V_171 * V_172 = F_56 ( V_160 , V_155 ) ;
* V_172 -> V_173 &= V_151 ;
memset ( V_172 -> V_173 + 1 , 0 , ( V_174 - 32 ) / 8 ) ;
if ( * V_172 -> V_173 == 0 )
return - V_120 ;
return 0 ;
}
int F_57 ( struct V_4 * V_5 , T_7 V_155 ,
T_4 V_151 )
{
struct V_159 * V_160 = & V_5 -> V_161 ;
struct V_171 * V_172 = F_56 ( V_160 , V_155 ) ;
V_172 -> V_173 [ 0 ] &= ( T_8 ) V_151 ;
V_172 -> V_173 [ 1 ] &= ( T_8 ) ( V_151 >> 32 ) ;
memset ( V_172 -> V_173 + 2 , 0 , ( V_174 - 64 ) / 8 ) ;
if ( ! V_172 -> V_173 [ 0 ] && ! V_172 -> V_173 [ 1 ] )
return - V_120 ;
return 0 ;
}
int F_58 ( struct V_4 * V_5 , T_7 V_155 )
{
struct V_159 * V_160 = & V_5 -> V_161 ;
return F_59 ( F_60 ( V_160 , V_155 ) ) ;
}
int F_61 ( struct V_4 * V_5 , T_7 V_155 ,
unsigned int V_121 , unsigned int V_123 )
{
struct V_159 * V_160 = & V_5 -> V_161 ;
struct V_116 V_135 ;
V_135 . V_121 = V_121 ;
V_135 . V_123 = V_123 ;
V_135 . V_122 = V_135 . V_124 = 0 ;
V_135 . integer = 0 ;
return F_34 ( F_60 ( V_160 , V_155 ) , & V_135 ) ;
}
static int F_62 ( struct V_175 * V_176 ,
struct V_162 * V_177 )
{
struct V_178 * V_150 = V_177 -> V_157 ;
return F_47 ( F_63 ( V_176 , V_177 -> V_155 ) , V_150 -> V_149 , V_150 -> V_150 , V_150 -> V_151 ) ;
}
int V_178 ( struct V_4 * V_5 ,
unsigned int V_154 ,
T_7 V_155 ,
struct V_178 * V_179 )
{
return F_51 ( V_5 , V_154 , V_155 ,
F_62 , V_179 ,
V_155 , - 1 ) ;
}
static int F_64 ( struct V_175 * V_176 ,
struct V_162 * V_177 )
{
struct V_180 * V_113 = V_177 -> V_157 ;
unsigned int V_139 = 0 , V_140 = 0 ;
int V_28 ;
V_28 = F_45 ( F_63 ( V_176 , V_177 -> V_155 ) ,
V_113 -> V_181 , V_113 -> V_129 , & V_139 , & V_140 ) ;
if ( V_28 >= 0 && V_140 && V_177 -> V_155 == V_182 ) {
V_176 -> V_183 = V_139 ;
V_176 -> V_184 = V_140 ;
}
return V_28 ;
}
int V_180 ( struct V_4 * V_5 ,
unsigned int V_154 ,
T_7 V_155 ,
struct V_180 * V_113 )
{
return F_51 ( V_5 , V_154 , V_155 ,
F_64 , V_113 ,
V_155 , - 1 ) ;
}
static int F_65 ( struct V_175 * V_176 ,
struct V_162 * V_177 )
{
struct V_185 * V_113 = V_177 -> V_157 ;
unsigned int V_139 = 0 , V_140 = 0 ;
int V_28 = F_46 ( F_63 ( V_176 , V_177 -> V_155 ) ,
V_113 -> V_181 , V_113 -> V_129 , & V_139 , & V_140 ) ;
if ( V_28 >= 0 && V_140 && V_177 -> V_155 == V_182 ) {
V_176 -> V_183 = V_139 ;
V_176 -> V_184 = V_140 ;
}
return V_28 ;
}
int V_185 ( struct V_4 * V_5 ,
unsigned int V_154 ,
T_7 V_155 ,
struct V_185 * V_113 )
{
return F_51 ( V_5 , V_154 , V_155 ,
F_65 , V_113 ,
V_155 , - 1 ) ;
}
static int F_66 ( struct V_175 * V_176 ,
struct V_162 * V_177 )
{
unsigned int V_179 = ( unsigned long ) V_177 -> V_157 ;
int V_186 = V_179 & 0xffff ;
unsigned int V_187 = V_179 >> 16 ;
struct V_116 * V_117 = F_63 ( V_176 , V_188 ) ;
if ( F_39 ( V_117 ) && F_67 ( V_117 ) == V_186 )
V_176 -> V_187 = V_187 ;
return 0 ;
}
int F_68 ( struct V_4 * V_5 ,
unsigned int V_154 ,
unsigned int V_186 ,
unsigned int V_187 )
{
unsigned long V_179 = ( V_187 << 16 ) | V_186 ;
return F_51 ( V_5 , V_154 , - 1 ,
F_66 ,
( void * ) V_179 ,
V_188 , - 1 ) ;
}
static int F_69 ( struct V_175 * V_176 ,
struct V_162 * V_177 )
{
unsigned long V_153 = ( unsigned long ) V_177 -> V_157 ;
return F_50 ( F_63 ( V_176 , V_177 -> V_155 ) , 0 , V_153 ) ;
}
int F_70 ( struct V_4 * V_5 ,
unsigned int V_154 ,
T_7 V_155 ,
unsigned long V_153 )
{
return F_51 ( V_5 , V_154 , V_155 ,
F_69 , ( void * ) V_153 ,
V_155 , - 1 ) ;
}
static int F_71 ( struct V_175 * V_176 , struct V_162 * V_177 )
{
static unsigned int V_189 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_47 ( F_63 ( V_176 , V_177 -> V_155 ) ,
F_54 ( V_189 ) , V_189 , 0 ) ;
}
int F_72 ( struct V_4 * V_5 ,
unsigned int V_154 ,
T_7 V_155 )
{
return F_51 ( V_5 , V_154 , V_155 ,
F_71 , NULL ,
V_155 , - 1 ) ;
}
static void F_73 ( struct V_175 * V_176 ,
T_7 V_155 )
{
if ( F_74 ( V_155 ) ) {
F_75 ( F_76 ( V_176 , V_155 ) ) ;
V_176 -> V_190 |= 1 << V_155 ;
V_176 -> V_191 |= 1 << V_155 ;
return;
}
if ( F_77 ( V_155 ) ) {
F_48 ( F_63 ( V_176 , V_155 ) ) ;
V_176 -> V_190 |= 1 << V_155 ;
V_176 -> V_191 |= 1 << V_155 ;
return;
}
F_78 () ;
}
void F_79 ( struct V_175 * V_176 )
{
unsigned int V_126 ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
for ( V_126 = V_192 ; V_126 <= V_193 ; V_126 ++ )
F_73 ( V_176 , V_126 ) ;
for ( V_126 = V_194 ; V_126 <= V_195 ; V_126 ++ )
F_73 ( V_176 , V_126 ) ;
V_176 -> V_100 = ~ 0U ;
}
int F_80 ( const struct V_175 * V_176 ,
T_7 V_155 , int * V_196 )
{
if ( F_74 ( V_155 ) ) {
const struct V_171 * V_151 = F_81 ( V_176 , V_155 ) ;
if ( ! F_82 ( V_151 ) )
return - V_120 ;
if ( V_196 )
* V_196 = 0 ;
return F_83 ( V_151 ) ;
}
if ( F_77 ( V_155 ) ) {
const struct V_116 * V_117 = F_84 ( V_176 , V_155 ) ;
if ( ! F_39 ( V_117 ) )
return - V_120 ;
if ( V_196 )
* V_196 = V_117 -> V_122 ;
return F_67 ( V_117 ) ;
}
return - V_120 ;
}
void F_85 ( struct V_175 * V_176 ,
T_7 V_155 )
{
if ( F_74 ( V_155 ) ) {
F_86 ( F_76 ( V_176 , V_155 ) ) ;
V_176 -> V_190 |= 1 << V_155 ;
V_176 -> V_191 |= 1 << V_155 ;
} else if ( F_77 ( V_155 ) ) {
F_37 ( F_63 ( V_176 , V_155 ) ) ;
V_176 -> V_190 |= 1 << V_155 ;
V_176 -> V_191 |= 1 << V_155 ;
} else {
F_78 () ;
}
}
static int F_87 ( struct V_175 * V_176 ,
T_7 V_155 )
{
int V_119 ;
if ( F_74 ( V_155 ) )
V_119 = F_88 ( F_76 ( V_176 , V_155 ) ) ;
else if ( F_77 ( V_155 ) )
V_119 = F_38 ( F_63 ( V_176 , V_155 ) ) ;
else
return - V_120 ;
if ( V_119 ) {
V_176 -> V_190 |= 1 << V_155 ;
V_176 -> V_191 |= 1 << V_155 ;
}
return V_119 ;
}
int F_89 ( struct V_1 * V_38 ,
struct V_175 * V_176 ,
T_7 V_155 , int * V_196 )
{
int V_119 = F_87 ( V_176 , V_155 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_176 -> V_191 ) {
int V_28 = F_90 ( V_38 , V_176 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_80 ( V_176 , V_155 , V_196 ) ;
}
static int F_91 ( struct V_175 * V_176 ,
T_7 V_155 )
{
int V_119 ;
if ( F_74 ( V_155 ) )
V_119 = F_92 ( F_76 ( V_176 , V_155 ) ) ;
else if ( F_77 ( V_155 ) )
V_119 = F_40 ( F_63 ( V_176 , V_155 ) ) ;
else
return - V_120 ;
if ( V_119 ) {
V_176 -> V_190 |= 1 << V_155 ;
V_176 -> V_191 |= 1 << V_155 ;
}
return V_119 ;
}
int F_93 ( struct V_1 * V_38 ,
struct V_175 * V_176 ,
T_7 V_155 , int * V_196 )
{
int V_119 = F_91 ( V_176 , V_155 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_176 -> V_191 ) {
int V_28 = F_90 ( V_38 , V_176 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_80 ( V_176 , V_155 , V_196 ) ;
}
int F_94 ( struct V_1 * V_38 ,
struct V_175 * V_176 )
{
static int V_197 [] = {
V_198 ,
V_199 ,
V_200 ,
V_201 ,
V_182 ,
V_202 ,
V_203 ,
V_204 ,
- 1
} ;
int V_28 , * V_118 ;
for ( V_118 = V_197 ; * V_118 != - 1 ; V_118 ++ ) {
if ( * V_118 != V_203 )
V_28 = F_89 ( V_38 , V_176 , * V_118 , NULL ) ;
else
V_28 = F_93 ( V_38 , V_176 , * V_118 , NULL ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
void * V_205 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_206 ;
F_96 ( V_2 , V_206 ) ;
if ( F_97 ( V_2 ) &&
F_25 ( V_2 ) >= 0 )
V_5 -> V_21 -> V_22 %= V_5 -> V_17 ;
else
V_5 -> V_21 -> V_22 = 0 ;
F_98 ( V_2 , V_206 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
void * V_205 )
{
struct V_207 * V_100 = V_205 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_186 ;
if ( ! ( V_5 -> V_100 & V_208 ) ) {
V_100 -> V_209 = - 1 ;
return 0 ;
}
V_186 = F_100 ( V_5 -> V_31 ) ;
if ( V_186 < 0 )
return V_186 ;
V_100 -> V_209 = 0 ;
switch ( V_5 -> V_23 ) {
case V_25 :
case V_24 :
V_100 -> V_210 = V_100 -> V_211 * V_186 ;
V_100 -> V_153 = V_5 -> V_32 * V_186 ;
break;
case V_212 :
case V_213 :
{
T_3 V_214 = V_5 -> V_35 / V_5 -> V_32 ;
V_100 -> V_210 = V_100 -> V_211 * V_214 * 8 ;
V_100 -> V_153 = V_186 ;
break;
}
default:
F_78 () ;
break;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
void * V_205 )
{
struct V_175 * V_176 = V_205 ;
T_9 V_31 ;
int V_32 , V_186 ;
V_176 -> V_215 = V_2 -> V_5 -> V_99 . V_215 ;
if ( ! ( V_2 -> V_5 -> V_99 . V_100 & V_216 ) ) {
V_31 = F_102 ( V_176 ) ;
V_32 = F_103 ( V_176 ) ;
V_186 = F_100 ( V_31 ) ;
V_176 -> V_215 /= V_186 * V_32 ;
}
return 0 ;
}
int F_104 ( struct V_1 * V_2 ,
unsigned int V_217 , void * V_205 )
{
switch ( V_217 ) {
case V_218 :
return 0 ;
case V_219 :
return F_95 ( V_2 , V_205 ) ;
case V_220 :
return F_99 ( V_2 , V_205 ) ;
case V_221 :
return F_101 ( V_2 , V_205 ) ;
}
return - V_222 ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_206 ;
if ( F_106 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_223 )
V_5 -> V_223 ( V_2 ) ;
F_96 ( V_2 , V_206 ) ;
if ( ! F_97 ( V_2 ) ||
F_22 ( V_2 , 1 ) < 0 )
goto V_224;
if ( V_2 -> V_225 )
F_107 ( V_2 -> V_226 , 1 ) ;
V_224:
F_98 ( V_2 , V_206 ) ;
if ( V_5 -> V_227 )
V_5 -> V_227 ( V_2 ) ;
F_108 ( & V_5 -> V_228 , V_229 , V_230 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
T_1 * V_231 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_232 = V_2 -> V_42 == V_67 ;
T_10 V_233 ;
int V_28 = 0 ;
T_1 V_20 = 0 ;
long V_234 , V_235 ;
if ( V_5 -> V_92 )
V_234 = V_236 ;
else {
V_234 = 10 ;
if ( V_5 -> V_96 ) {
long V_135 = V_5 -> V_62 * 2 / V_5 -> V_96 ;
V_234 = V_123 ( V_135 , V_234 ) ;
}
V_234 = F_110 ( V_234 * 1000 ) ;
}
F_111 ( & V_233 , V_237 ) ;
F_112 ( & V_5 -> V_74 , & V_233 ) ;
for (; ; ) {
if ( F_113 ( V_237 ) ) {
V_28 = - V_238 ;
break;
}
F_114 ( V_2 ) ;
V_235 = F_115 ( V_234 ) ;
F_116 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_239 :
V_28 = - V_240 ;
goto V_241;
case V_47 :
V_28 = - V_71 ;
goto V_241;
case V_70 :
if ( V_232 )
V_28 = - V_71 ;
else
V_20 = 0 ;
goto V_241;
case V_242 :
case V_243 :
case V_244 :
V_28 = - V_245 ;
goto V_241;
}
if ( ! V_235 ) {
F_12 ( L_22 ,
V_232 ? L_23 : L_24 ) ;
V_28 = - V_246 ;
break;
}
if ( V_232 )
V_20 = F_18 ( V_5 ) ;
else
V_20 = F_19 ( V_5 ) ;
if ( V_20 >= V_5 -> V_73 )
break;
}
V_241:
F_117 ( & V_5 -> V_74 , & V_233 ) ;
* V_231 = V_20 ;
return V_28 ;
}
static int F_118 ( struct V_1 * V_2 ,
unsigned int V_247 ,
unsigned long V_248 , unsigned int V_249 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_11 * V_250 = ( char T_11 * ) V_248 + F_4 ( V_5 , V_249 ) ;
if ( V_2 -> V_26 -> V_251 ) {
if ( ( V_28 = V_2 -> V_26 -> V_251 ( V_2 , - 1 , V_247 , V_250 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_247 ) ;
if ( F_119 ( V_29 , V_250 , F_4 ( V_5 , V_6 ) ) )
return - V_252 ;
}
return 0 ;
}
static T_2 F_120 ( struct V_1 * V_2 ,
unsigned long V_248 ,
T_1 V_214 ,
int V_253 ,
T_12 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_254 = 0 ;
T_1 V_209 = 0 ;
int V_28 = 0 ;
if ( V_214 == 0 )
return 0 ;
F_116 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_255 :
case V_256 :
case V_257 :
break;
case V_47 :
V_28 = - V_71 ;
goto V_258;
case V_239 :
V_28 = - V_240 ;
goto V_258;
default:
V_28 = - V_245 ;
goto V_258;
}
V_5 -> V_73 = V_5 -> V_14 -> V_75 ? : 1 ;
while ( V_214 > 0 ) {
T_1 V_6 , V_15 , V_259 ;
T_1 V_20 ;
T_1 V_260 ;
if ( V_5 -> V_21 -> V_69 == V_256 )
F_25 ( V_2 ) ;
V_20 = F_18 ( V_5 ) ;
if ( ! V_20 ) {
if ( V_253 ) {
V_28 = - V_261 ;
goto V_258;
}
V_5 -> V_73 = F_121 ( T_1 , V_214 ,
V_5 -> V_14 -> V_75 ? : 1 ) ;
V_28 = F_109 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_258;
}
V_6 = V_214 > V_20 ? V_20 : V_214 ;
V_260 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_260 )
V_6 = V_260 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_73 = 0 ;
F_114 ( V_2 ) ;
return - V_120 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_259 = V_15 % V_5 -> V_17 ;
F_114 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_259 , V_248 , V_209 , V_6 ) ;
F_116 ( V_2 ) ;
if ( V_28 < 0 )
goto V_258;
switch ( V_5 -> V_21 -> V_69 ) {
case V_47 :
V_28 = - V_71 ;
goto V_258;
case V_239 :
V_28 = - V_240 ;
goto V_258;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_262 )
V_2 -> V_26 -> V_262 ( V_2 ) ;
V_209 += V_6 ;
V_214 -= V_6 ;
V_254 += V_6 ;
if ( V_5 -> V_21 -> V_69 == V_255 &&
F_2 ( V_5 ) >= ( T_2 ) V_5 -> V_263 ) {
V_28 = F_122 ( V_2 ) ;
if ( V_28 < 0 )
goto V_258;
}
}
V_258:
V_5 -> V_73 = 0 ;
if ( V_254 > 0 && V_28 >= 0 )
F_17 ( V_2 , V_5 ) ;
F_114 ( V_2 ) ;
return V_254 > 0 ? ( T_2 ) V_254 : V_28 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_106 ( V_2 ) )
return - V_222 ;
V_5 = V_2 -> V_5 ;
if ( F_3 ( ! V_2 -> V_26 -> V_251 && ! V_5 -> V_30 ) )
return - V_120 ;
if ( V_5 -> V_21 -> V_69 == V_242 )
return - V_245 ;
return 0 ;
}
T_2 F_124 ( struct V_1 * V_2 , const void T_11 * V_250 , T_1 V_214 )
{
struct V_4 * V_5 ;
int V_253 ;
int V_28 ;
V_28 = F_123 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_253 = ! ! ( V_2 -> V_264 & V_265 ) ;
if ( V_5 -> V_23 != V_24 &&
V_5 -> V_32 > 1 )
return - V_120 ;
return F_120 ( V_2 , ( unsigned long ) V_250 , V_214 , V_253 ,
F_118 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
unsigned int V_247 ,
unsigned long V_248 , unsigned int V_249 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_11 * * V_266 = ( void T_11 * * ) V_248 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_251 ) {
if ( F_3 ( ! V_2 -> V_26 -> V_27 ) )
return - V_120 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_266 ) {
if ( * V_266 == NULL ) {
if ( ( V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_247 , V_6 ) ) < 0 )
return V_28 ;
} else {
char T_11 * V_250 = * V_266 + F_6 ( V_5 , V_249 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_251 ( V_2 , V_33 , V_247 , V_250 , V_6 ) ) < 0 )
return V_28 ;
}
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_266 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_247 ) ;
if ( * V_266 == NULL ) {
F_5 ( V_5 -> V_31 , V_29 , V_6 ) ;
} else {
char T_11 * V_250 = * V_266 + F_6 ( V_5 , V_249 ) ;
if ( F_119 ( V_29 , V_250 , F_6 ( V_5 , V_6 ) ) )
return - V_252 ;
}
}
}
return 0 ;
}
T_2 F_126 ( struct V_1 * V_2 ,
void T_11 * * V_266 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_253 ;
int V_28 ;
V_28 = F_123 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_253 = ! ! ( V_2 -> V_264 & V_265 ) ;
if ( V_5 -> V_23 != V_213 )
return - V_120 ;
return F_120 ( V_2 , ( unsigned long ) V_266 , V_6 ,
V_253 , F_125 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
unsigned int V_247 ,
unsigned long V_248 , unsigned int V_249 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_11 * V_250 = ( char T_11 * ) V_248 + F_4 ( V_5 , V_249 ) ;
if ( V_2 -> V_26 -> V_251 ) {
if ( ( V_28 = V_2 -> V_26 -> V_251 ( V_2 , - 1 , V_247 , V_250 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_247 ) ;
if ( F_128 ( V_250 , V_29 , F_4 ( V_5 , V_6 ) ) )
return - V_252 ;
}
return 0 ;
}
static T_2 F_129 ( struct V_1 * V_2 ,
unsigned long V_248 ,
T_1 V_214 ,
int V_253 ,
T_12 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_254 = 0 ;
T_1 V_209 = 0 ;
int V_28 = 0 ;
if ( V_214 == 0 )
return 0 ;
F_116 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_255 :
if ( V_214 >= V_5 -> V_263 ) {
V_28 = F_122 ( V_2 ) ;
if ( V_28 < 0 )
goto V_258;
}
break;
case V_70 :
case V_256 :
case V_257 :
break;
case V_47 :
V_28 = - V_71 ;
goto V_258;
case V_239 :
V_28 = - V_240 ;
goto V_258;
default:
V_28 = - V_245 ;
goto V_258;
}
V_5 -> V_73 = V_5 -> V_14 -> V_75 ? : 1 ;
while ( V_214 > 0 ) {
T_1 V_6 , V_15 , V_259 ;
T_1 V_20 ;
T_1 V_260 ;
if ( V_5 -> V_21 -> V_69 == V_256 )
F_25 ( V_2 ) ;
V_20 = F_19 ( V_5 ) ;
if ( ! V_20 ) {
if ( V_5 -> V_21 -> V_69 ==
V_70 ) {
F_10 ( V_2 , V_243 ) ;
goto V_258;
}
if ( V_253 ) {
V_28 = - V_261 ;
goto V_258;
}
V_5 -> V_73 = F_121 ( T_1 , V_214 ,
V_5 -> V_14 -> V_75 ? : 1 ) ;
V_28 = F_109 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_258;
if ( ! V_20 )
continue;
}
V_6 = V_214 > V_20 ? V_20 : V_214 ;
V_260 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_260 )
V_6 = V_260 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_73 = 0 ;
F_114 ( V_2 ) ;
return - V_120 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_259 = V_15 % V_5 -> V_17 ;
F_114 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_259 , V_248 , V_209 , V_6 ) ;
F_116 ( V_2 ) ;
if ( V_28 < 0 )
goto V_258;
switch ( V_5 -> V_21 -> V_69 ) {
case V_47 :
V_28 = - V_71 ;
goto V_258;
case V_239 :
V_28 = - V_240 ;
goto V_258;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_262 )
V_2 -> V_26 -> V_262 ( V_2 ) ;
V_209 += V_6 ;
V_214 -= V_6 ;
V_254 += V_6 ;
}
V_258:
V_5 -> V_73 = 0 ;
if ( V_254 > 0 && V_28 >= 0 )
F_17 ( V_2 , V_5 ) ;
F_114 ( V_2 ) ;
return V_254 > 0 ? ( T_2 ) V_254 : V_28 ;
}
T_2 F_130 ( struct V_1 * V_2 , void T_11 * V_250 , T_1 V_214 )
{
struct V_4 * V_5 ;
int V_253 ;
int V_28 ;
V_28 = F_123 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_253 = ! ! ( V_2 -> V_264 & V_265 ) ;
if ( V_5 -> V_23 != V_24 )
return - V_120 ;
return F_129 ( V_2 , ( unsigned long ) V_250 , V_214 , V_253 , F_127 ) ;
}
static int F_131 ( struct V_1 * V_2 ,
unsigned int V_247 ,
unsigned long V_248 , unsigned int V_249 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_11 * * V_266 = ( void T_11 * * ) V_248 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_251 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_266 ) {
char T_11 * V_250 ;
if ( * V_266 == NULL )
continue;
V_250 = * V_266 + F_6 ( V_5 , V_249 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_251 ( V_2 , V_33 , V_247 , V_250 , V_6 ) ) < 0 )
return V_28 ;
}
} else {
T_1 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_266 ) {
char * V_29 ;
char T_11 * V_250 ;
if ( * V_266 == NULL )
continue;
V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_247 ) ;
V_250 = * V_266 + F_6 ( V_5 , V_249 ) ;
if ( F_128 ( V_250 , V_29 , F_6 ( V_5 , V_6 ) ) )
return - V_252 ;
}
}
return 0 ;
}
T_2 F_132 ( struct V_1 * V_2 ,
void T_11 * * V_266 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_253 ;
int V_28 ;
V_28 = F_123 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 -> V_69 == V_242 )
return - V_245 ;
V_253 = ! ! ( V_2 -> V_264 & V_265 ) ;
if ( V_5 -> V_23 != V_213 )
return - V_120 ;
return F_129 ( V_2 , ( unsigned long ) V_266 , V_6 , V_253 , F_131 ) ;
}
