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
struct V_45 V_83 ;
int V_84 = 0 ;
V_63 = V_5 -> V_21 -> V_22 ;
V_50 = V_2 -> V_26 -> V_85 ( V_2 ) ;
V_81 = V_61 ;
if ( V_5 -> V_43 == V_44 ) {
F_9 ( V_5 , (struct V_45 * ) & V_82 ) ;
if ( ( V_5 -> V_86 . V_87 & V_88 ) &&
( V_2 -> V_26 -> V_89 ) )
V_2 -> V_26 -> V_89 ( V_2 , & V_83 ) ;
}
if ( V_50 == V_90 ) {
F_8 ( V_2 ) ;
return - V_71 ;
}
if ( V_50 >= V_5 -> V_17 ) {
if ( F_23 () ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_16 ( V_2 ) ;
F_12 ( V_91 L_7
L_8 ,
V_36 , V_50 , V_5 -> V_17 ,
V_5 -> V_62 ) ;
}
V_50 = 0 ;
}
V_50 -= V_50 % V_5 -> V_92 ;
if ( F_11 ( V_2 , V_93 ) )
F_14 ( V_2 , V_50 , V_51 ) ;
V_77 = V_5 -> V_64 ;
V_3 = V_77 + V_50 ;
if ( V_51 ) {
V_79 = V_5 -> V_94 + V_5 -> V_62 ;
if ( V_79 > V_3 ) {
V_78 = V_81 - V_5 -> V_95 ;
if ( V_78 > V_5 -> V_96 / 2 ) {
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 ) {
V_77 = 0 ;
V_84 ++ ;
}
V_3 = V_77 + V_50 ;
goto V_97;
}
}
}
if ( V_3 < V_63 ) {
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 ) {
V_77 = 0 ;
V_84 ++ ;
}
V_3 = V_77 + V_50 ;
}
V_97:
V_79 = V_3 - V_63 ;
if ( V_79 < 0 )
V_79 += V_5 -> V_10 ;
if ( F_11 ( V_2 , V_51 ?
V_98 : V_99 ) ) {
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
if ( V_5 -> V_100 ) {
T_2 V_101 ;
V_80 = V_81 - V_5 -> V_95 ;
if ( V_80 < V_5 -> V_96 / 2 )
goto V_102;
V_78 = V_80 - V_79 * V_103 / V_5 -> V_104 ;
V_101 = V_5 -> V_96 / 2 + 1 ;
while ( V_78 > V_101 ) {
V_79 += V_5 -> V_17 ;
V_77 += V_5 -> V_17 ;
if ( V_77 >= V_5 -> V_10 ) {
V_77 = 0 ;
V_84 ++ ;
}
V_3 = V_77 + V_50 ;
V_78 -= V_5 -> V_96 ;
}
goto V_102;
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
if ( ! F_11 ( V_2 , V_105 ) )
goto V_106;
if ( V_5 -> V_86 . V_87 & V_107 )
goto V_106;
V_78 = V_79 ;
if ( V_78 < V_5 -> V_108 )
goto V_106;
V_78 -= V_5 -> V_108 ;
V_80 = V_81 - V_5 -> V_95 ;
if ( ( ( V_78 * V_103 ) / V_5 -> V_104 ) > V_80 + V_103 / 100 ) {
V_79 = V_80 /
( ( ( V_5 -> V_62 * V_103 ) / V_5 -> V_104 )
+ V_103 / 100 ) ;
V_3 = V_63 ;
V_77 = V_79 ;
while ( V_79 > 0 ) {
V_3 += V_5 -> V_62 ;
if ( V_3 >= V_5 -> V_10 ) {
V_3 -= V_5 -> V_10 ;
V_84 -- ;
}
V_79 -- ;
}
F_24 ( V_2 ,
L_17
L_18
L_19 ,
V_51 ? L_5 : L_6 ,
( long ) V_50 , ( long ) V_78 ,
( long ) V_5 -> V_62 , V_80 ,
( ( V_78 * V_103 ) / V_5 -> V_104 ) , V_77 ,
( unsigned long ) V_63 ,
( unsigned long ) V_3 ) ;
V_79 = 0 ;
V_77 = V_3 - ( V_3 % V_5 -> V_17 ) ;
}
V_106:
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
V_102:
if ( V_5 -> V_21 -> V_22 == V_3 )
return 0 ;
if ( V_2 -> V_42 == V_67 &&
V_5 -> V_9 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_51 ) {
V_79 = V_3 - V_5 -> V_94 ;
if ( V_79 < 0 )
V_79 += V_5 -> V_10 ;
V_79 -= ( T_1 ) V_79 % V_5 -> V_62 ;
V_5 -> V_94 += V_79 ;
if ( V_5 -> V_94 >= V_5 -> V_10 )
V_5 -> V_94 -= V_5 -> V_10 ;
}
V_5 -> V_64 = V_77 ;
V_5 -> V_21 -> V_22 = V_3 ;
V_5 -> V_95 = V_81 ;
if ( V_84 ) {
F_3 ( V_84 != 1 ) ;
V_5 -> V_109 += V_5 -> V_10 ;
}
if ( V_5 -> V_43 == V_44 ) {
V_5 -> V_21 -> V_46 = V_82 ;
if ( ! ( V_5 -> V_86 . V_87 & V_88 ) ) {
T_4 V_110 , V_111 ;
if ( V_2 -> V_42 == V_67 )
V_110 = V_5 -> V_109
+ V_5 -> V_21 -> V_22
- V_5 -> V_108 ;
else
V_110 = V_5 -> V_109
+ V_5 -> V_21 -> V_22
+ V_5 -> V_108 ;
V_111 = F_25 ( V_110 * 1000000000LL ,
V_5 -> V_104 ) ;
V_83 = F_26 ( V_111 ) ;
}
V_5 -> V_21 -> V_83 = V_83 ;
}
return F_17 ( V_2 , V_5 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , 0 ) ;
}
void F_28 ( struct V_112 * V_38 , int V_113 ,
const struct V_114 * V_26 )
{
struct V_115 * V_42 = & V_38 -> V_116 [ V_113 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_42 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_117 )
V_2 -> V_26 = V_26 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_118 . V_119 [ 0 ] = V_2 -> V_38 -> V_39 -> V_40 ;
V_5 -> V_118 . V_119 [ 1 ] = - 1 ;
V_5 -> V_118 . V_119 [ 2 ] = - 1 ;
V_5 -> V_118 . V_119 [ 3 ] = - 1 ;
}
static inline unsigned int F_30 ( unsigned int V_120 , unsigned int V_121 ,
unsigned int * V_122 )
{
if ( V_121 == 0 ) {
* V_122 = 0 ;
return V_123 ;
}
* V_122 = V_120 % V_121 ;
return V_120 / V_121 ;
}
static inline unsigned int F_31 ( unsigned int V_120 , unsigned int V_121 )
{
if ( V_121 == 0 )
return V_123 ;
return V_120 / V_121 ;
}
static inline unsigned int F_32 ( unsigned int V_120 , unsigned int V_121 )
{
unsigned int V_122 ;
unsigned int V_124 ;
if ( V_121 == 0 )
return V_123 ;
V_124 = F_30 ( V_120 , V_121 , & V_122 ) ;
if ( V_122 )
++ V_124 ;
return V_124 ;
}
static inline unsigned int F_33 ( unsigned int V_120 , unsigned int V_121 )
{
if ( V_120 == 0 )
return 0 ;
if ( F_31 ( V_123 , V_120 ) < V_121 )
return V_123 ;
return V_120 * V_121 ;
}
static inline unsigned int F_34 ( unsigned int V_120 , unsigned int V_121 ,
unsigned int V_33 , unsigned int * V_122 )
{
T_5 V_12 = ( T_5 ) V_120 * V_121 ;
if ( V_33 == 0 ) {
F_3 ( ! V_12 ) ;
* V_122 = 0 ;
return V_123 ;
}
V_12 = F_35 ( V_12 , V_33 , V_122 ) ;
if ( V_12 >= V_123 ) {
* V_122 = 0 ;
return V_123 ;
}
return V_12 ;
}
int F_36 ( struct V_125 * V_126 , const struct V_125 * V_127 )
{
int V_128 = 0 ;
if ( F_3 ( F_37 ( V_126 ) ) )
return - V_129 ;
if ( V_126 -> V_130 < V_127 -> V_130 ) {
V_126 -> V_130 = V_127 -> V_130 ;
V_126 -> V_131 = V_127 -> V_131 ;
V_128 = 1 ;
} else if ( V_126 -> V_130 == V_127 -> V_130 && ! V_126 -> V_131 && V_127 -> V_131 ) {
V_126 -> V_131 = 1 ;
V_128 = 1 ;
}
if ( V_126 -> V_132 > V_127 -> V_132 ) {
V_126 -> V_132 = V_127 -> V_132 ;
V_126 -> V_133 = V_127 -> V_133 ;
V_128 = 1 ;
} else if ( V_126 -> V_132 == V_127 -> V_132 && ! V_126 -> V_133 && V_127 -> V_133 ) {
V_126 -> V_133 = 1 ;
V_128 = 1 ;
}
if ( ! V_126 -> integer && V_127 -> integer ) {
V_126 -> integer = 1 ;
V_128 = 1 ;
}
if ( V_126 -> integer ) {
if ( V_126 -> V_131 ) {
V_126 -> V_130 ++ ;
V_126 -> V_131 = 0 ;
}
if ( V_126 -> V_133 ) {
V_126 -> V_132 -- ;
V_126 -> V_133 = 0 ;
}
} else if ( ! V_126 -> V_131 && ! V_126 -> V_133 && V_126 -> V_130 == V_126 -> V_132 )
V_126 -> integer = 1 ;
if ( F_38 ( V_126 ) ) {
F_39 ( V_126 ) ;
return - V_129 ;
}
return V_128 ;
}
static int F_40 ( struct V_125 * V_126 )
{
if ( F_3 ( F_37 ( V_126 ) ) )
return - V_129 ;
if ( F_41 ( V_126 ) )
return 0 ;
V_126 -> V_132 = V_126 -> V_130 ;
V_126 -> V_133 = V_126 -> V_131 ;
if ( V_126 -> V_133 )
V_126 -> V_132 ++ ;
return 1 ;
}
static int F_42 ( struct V_125 * V_126 )
{
if ( F_3 ( F_37 ( V_126 ) ) )
return - V_129 ;
if ( F_41 ( V_126 ) )
return 0 ;
V_126 -> V_130 = V_126 -> V_132 ;
V_126 -> V_131 = V_126 -> V_133 ;
if ( V_126 -> V_131 )
V_126 -> V_130 -- ;
return 1 ;
}
void F_43 ( const struct V_125 * V_120 , const struct V_125 * V_121 , struct V_125 * V_33 )
{
if ( V_120 -> V_134 || V_121 -> V_134 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_134 = 0 ;
V_33 -> V_130 = F_33 ( V_120 -> V_130 , V_121 -> V_130 ) ;
V_33 -> V_131 = ( V_120 -> V_131 || V_121 -> V_131 ) ;
V_33 -> V_132 = F_33 ( V_120 -> V_132 , V_121 -> V_132 ) ;
V_33 -> V_133 = ( V_120 -> V_133 || V_121 -> V_133 ) ;
V_33 -> integer = ( V_120 -> integer && V_121 -> integer ) ;
}
void F_44 ( const struct V_125 * V_120 , const struct V_125 * V_121 , struct V_125 * V_33 )
{
unsigned int V_122 ;
if ( V_120 -> V_134 || V_121 -> V_134 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_134 = 0 ;
V_33 -> V_130 = F_30 ( V_120 -> V_130 , V_121 -> V_132 , & V_122 ) ;
V_33 -> V_131 = ( V_122 || V_120 -> V_131 || V_121 -> V_133 ) ;
if ( V_121 -> V_130 > 0 ) {
V_33 -> V_132 = F_30 ( V_120 -> V_132 , V_121 -> V_130 , & V_122 ) ;
if ( V_122 ) {
V_33 -> V_132 ++ ;
V_33 -> V_133 = 1 ;
} else
V_33 -> V_133 = ( V_120 -> V_133 || V_121 -> V_131 ) ;
} else {
V_33 -> V_132 = V_123 ;
V_33 -> V_133 = 0 ;
}
V_33 -> integer = 0 ;
}
void F_45 ( const struct V_125 * V_120 , const struct V_125 * V_121 ,
unsigned int V_135 , struct V_125 * V_33 )
{
unsigned int V_122 ;
if ( V_120 -> V_134 || V_121 -> V_134 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_134 = 0 ;
V_33 -> V_130 = F_34 ( V_120 -> V_130 , V_121 -> V_130 , V_135 , & V_122 ) ;
V_33 -> V_131 = ( V_122 || V_120 -> V_131 || V_121 -> V_131 ) ;
V_33 -> V_132 = F_34 ( V_120 -> V_132 , V_121 -> V_132 , V_135 , & V_122 ) ;
if ( V_122 ) {
V_33 -> V_132 ++ ;
V_33 -> V_133 = 1 ;
} else
V_33 -> V_133 = ( V_120 -> V_133 || V_121 -> V_133 ) ;
V_33 -> integer = 0 ;
}
void F_46 ( const struct V_125 * V_120 , unsigned int V_135 ,
const struct V_125 * V_121 , struct V_125 * V_33 )
{
unsigned int V_122 ;
if ( V_120 -> V_134 || V_121 -> V_134 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_134 = 0 ;
V_33 -> V_130 = F_34 ( V_120 -> V_130 , V_135 , V_121 -> V_132 , & V_122 ) ;
V_33 -> V_131 = ( V_122 || V_120 -> V_131 || V_121 -> V_133 ) ;
if ( V_121 -> V_130 > 0 ) {
V_33 -> V_132 = F_34 ( V_120 -> V_132 , V_135 , V_121 -> V_130 , & V_122 ) ;
if ( V_122 ) {
V_33 -> V_132 ++ ;
V_33 -> V_133 = 1 ;
} else
V_33 -> V_133 = ( V_120 -> V_133 || V_121 -> V_131 ) ;
} else {
V_33 -> V_132 = V_123 ;
V_33 -> V_133 = 0 ;
}
V_33 -> integer = 0 ;
}
int F_47 ( struct V_125 * V_126 ,
unsigned int V_136 , struct V_137 * V_138 ,
unsigned int * V_139 , unsigned int * V_140 )
{
unsigned int V_141 , V_142 ;
int V_143 ;
unsigned int V_135 ;
struct V_125 V_144 ;
int V_28 ;
unsigned int V_145 , V_146 ;
int V_147 ;
V_141 = V_142 = V_143 = 0 ;
for ( V_135 = 0 ; V_135 < V_136 ; ++ V_135 ) {
unsigned int V_148 = V_138 [ V_135 ] . V_148 ;
unsigned int V_149 ;
unsigned int V_124 = V_126 -> V_130 ;
int V_150 ;
if ( V_124 == 0 )
V_124 = 1 ;
V_149 = F_32 ( V_148 , V_124 ) ;
if ( V_149 < V_138 [ V_135 ] . V_151 )
continue;
if ( V_149 > V_138 [ V_135 ] . V_152 )
V_149 = V_138 [ V_135 ] . V_152 ;
else {
unsigned int V_122 ;
V_122 = ( V_149 - V_138 [ V_135 ] . V_151 ) % V_138 [ V_135 ] . V_153 ;
if ( V_122 != 0 )
V_149 -= V_122 ;
}
V_150 = V_148 - V_124 * V_149 ;
if ( V_150 < 0 )
V_150 = - V_150 ;
if ( V_141 == 0 ||
V_150 * V_142 < V_143 * V_149 ) {
V_143 = V_150 ;
V_142 = V_149 ;
V_141 = V_148 ;
}
}
if ( V_142 == 0 ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
V_144 . V_130 = F_31 ( V_141 , V_142 ) ;
V_144 . V_131 = ! ! ( V_141 % V_142 ) ;
V_145 = V_141 ;
V_147 = V_143 ;
V_146 = V_142 ;
V_141 = V_142 = V_143 = 0 ;
for ( V_135 = 0 ; V_135 < V_136 ; ++ V_135 ) {
unsigned int V_148 = V_138 [ V_135 ] . V_148 ;
unsigned int V_149 ;
unsigned int V_124 = V_126 -> V_132 ;
int V_150 ;
if ( V_124 == 0 ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
V_149 = F_31 ( V_148 , V_124 ) ;
if ( V_149 > V_138 [ V_135 ] . V_152 )
continue;
if ( V_149 < V_138 [ V_135 ] . V_151 )
V_149 = V_138 [ V_135 ] . V_151 ;
else {
unsigned int V_122 ;
V_122 = ( V_149 - V_138 [ V_135 ] . V_151 ) % V_138 [ V_135 ] . V_153 ;
if ( V_122 != 0 )
V_149 += V_138 [ V_135 ] . V_153 - V_122 ;
}
V_150 = V_124 * V_149 - V_148 ;
if ( V_150 < 0 )
V_150 = - V_150 ;
if ( V_141 == 0 ||
V_150 * V_142 < V_143 * V_149 ) {
V_143 = V_150 ;
V_142 = V_149 ;
V_141 = V_148 ;
}
}
if ( V_142 == 0 ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
V_144 . V_132 = F_32 ( V_141 , V_142 ) ;
V_144 . V_133 = ! ! ( V_141 % V_142 ) ;
V_144 . integer = 0 ;
V_28 = F_36 ( V_126 , & V_144 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_41 ( V_126 ) ) {
if ( V_143 * V_146 < V_147 * V_142 ) {
V_145 = V_141 ;
V_146 = V_142 ;
}
if ( V_139 )
* V_139 = V_145 ;
if ( V_140 )
* V_140 = V_146 ;
}
return V_28 ;
}
static int F_48 ( struct V_125 * V_126 ,
unsigned int V_136 , struct V_154 * V_138 ,
unsigned int * V_139 , unsigned int * V_140 )
{
unsigned int V_141 , V_143 , V_142 ;
unsigned int V_135 ;
struct V_125 V_144 ;
int V_28 ;
V_141 = V_142 = V_143 = 0 ;
for ( V_135 = 0 ; V_135 < V_136 ; ++ V_135 ) {
unsigned int V_148 ;
unsigned int V_149 = V_138 [ V_135 ] . V_149 ;
unsigned int V_124 = V_126 -> V_130 ;
int V_150 ;
V_148 = F_33 ( V_124 , V_149 ) ;
if ( V_148 > V_138 [ V_135 ] . V_155 )
continue;
if ( V_148 < V_138 [ V_135 ] . V_156 )
V_148 = V_138 [ V_135 ] . V_155 ;
else {
unsigned int V_122 ;
V_122 = ( V_148 - V_138 [ V_135 ] . V_156 ) % V_138 [ V_135 ] . V_157 ;
if ( V_122 != 0 )
V_148 += V_138 [ V_135 ] . V_157 - V_122 ;
}
V_150 = V_148 - V_124 * V_149 ;
if ( V_141 == 0 ||
V_150 * V_142 < V_143 * V_149 ) {
V_143 = V_150 ;
V_142 = V_149 ;
V_141 = V_148 ;
}
}
if ( V_142 == 0 ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
V_144 . V_130 = F_31 ( V_141 , V_142 ) ;
V_144 . V_131 = ! ! ( V_141 % V_142 ) ;
V_141 = V_142 = V_143 = 0 ;
for ( V_135 = 0 ; V_135 < V_136 ; ++ V_135 ) {
unsigned int V_148 ;
unsigned int V_149 = V_138 [ V_135 ] . V_149 ;
unsigned int V_124 = V_126 -> V_132 ;
int V_150 ;
V_148 = F_33 ( V_124 , V_149 ) ;
if ( V_148 < V_138 [ V_135 ] . V_156 )
continue;
if ( V_148 > V_138 [ V_135 ] . V_155 )
V_148 = V_138 [ V_135 ] . V_155 ;
else {
unsigned int V_122 ;
V_122 = ( V_148 - V_138 [ V_135 ] . V_156 ) % V_138 [ V_135 ] . V_157 ;
if ( V_122 != 0 )
V_148 -= V_122 ;
}
V_150 = V_124 * V_149 - V_148 ;
if ( V_141 == 0 ||
V_150 * V_142 < V_143 * V_149 ) {
V_143 = V_150 ;
V_142 = V_149 ;
V_141 = V_148 ;
}
}
if ( V_142 == 0 ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
V_144 . V_132 = F_32 ( V_141 , V_142 ) ;
V_144 . V_133 = ! ! ( V_141 % V_142 ) ;
V_144 . integer = 0 ;
V_28 = F_36 ( V_126 , & V_144 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_41 ( V_126 ) ) {
if ( V_139 )
* V_139 = V_141 ;
if ( V_140 )
* V_140 = V_142 ;
}
return V_28 ;
}
int F_49 ( struct V_125 * V_126 , unsigned int V_158 ,
const unsigned int * V_159 , unsigned int V_160 )
{
unsigned int V_135 ;
struct V_125 V_161 ;
if ( ! V_158 ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
F_50 ( & V_161 ) ;
V_161 . V_130 = V_123 ;
V_161 . V_132 = 0 ;
for ( V_135 = 0 ; V_135 < V_158 ; V_135 ++ ) {
if ( V_160 && ! ( V_160 & ( 1 << V_135 ) ) )
continue;
if ( ! F_51 ( V_126 , V_159 [ V_135 ] ) )
continue;
V_161 . V_130 = V_130 ( V_161 . V_130 , V_159 [ V_135 ] ) ;
V_161 . V_132 = V_132 ( V_161 . V_132 , V_159 [ V_135 ] ) ;
}
return F_36 ( V_126 , & V_161 ) ;
}
static int F_52 ( struct V_125 * V_126 , unsigned int V_130 , unsigned int V_162 )
{
unsigned int V_12 ;
int V_128 = 0 ;
V_12 = ( V_126 -> V_130 - V_130 ) % V_162 ;
if ( V_12 != 0 || V_126 -> V_131 ) {
V_126 -> V_130 += V_162 - V_12 ;
V_128 = 1 ;
}
V_12 = ( V_126 -> V_132 - V_130 ) % V_162 ;
if ( V_12 != 0 || V_126 -> V_133 ) {
V_126 -> V_132 -= V_12 ;
V_128 = 1 ;
}
if ( F_38 ( V_126 ) ) {
V_126 -> V_134 = 1 ;
return - V_129 ;
}
return V_128 ;
}
int F_53 ( struct V_4 * V_5 , unsigned int V_163 ,
int V_164 ,
T_6 V_165 , void * V_166 ,
int V_167 , ... )
{
struct V_168 * V_169 = & V_5 -> V_170 ;
struct V_171 * V_33 ;
unsigned int V_135 ;
T_7 args ;
va_start ( args , V_167 ) ;
if ( V_169 -> V_172 >= V_169 -> V_173 ) {
struct V_171 * V_174 ;
unsigned int V_175 = V_169 -> V_173 + 16 ;
V_174 = F_54 ( V_175 , sizeof( * V_33 ) , V_176 ) ;
if ( ! V_174 ) {
va_end ( args ) ;
return - V_177 ;
}
if ( V_169 -> V_178 ) {
memcpy ( V_174 , V_169 -> V_178 ,
V_169 -> V_172 * sizeof( * V_33 ) ) ;
F_55 ( V_169 -> V_178 ) ;
}
V_169 -> V_178 = V_174 ;
V_169 -> V_173 = V_175 ;
}
V_33 = & V_169 -> V_178 [ V_169 -> V_172 ] ;
V_33 -> V_163 = V_163 ;
V_33 -> V_165 = V_165 ;
V_33 -> V_164 = V_164 ;
V_33 -> V_166 = V_166 ;
V_135 = 0 ;
while ( 1 ) {
if ( F_3 ( V_135 >= F_56 ( V_33 -> V_179 ) ) ) {
va_end ( args ) ;
return - V_129 ;
}
V_33 -> V_179 [ V_135 ++ ] = V_167 ;
if ( V_167 < 0 )
break;
V_167 = va_arg ( args , int ) ;
}
V_169 -> V_172 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_57 ( struct V_4 * V_5 , T_8 V_164 ,
T_9 V_160 )
{
struct V_168 * V_169 = & V_5 -> V_170 ;
struct V_180 * V_181 = F_58 ( V_169 , V_164 ) ;
* V_181 -> V_182 &= V_160 ;
memset ( V_181 -> V_182 + 1 , 0 , ( V_183 - 32 ) / 8 ) ;
if ( * V_181 -> V_182 == 0 )
return - V_129 ;
return 0 ;
}
int F_59 ( struct V_4 * V_5 , T_8 V_164 ,
T_5 V_160 )
{
struct V_168 * V_169 = & V_5 -> V_170 ;
struct V_180 * V_181 = F_58 ( V_169 , V_164 ) ;
V_181 -> V_182 [ 0 ] &= ( T_9 ) V_160 ;
V_181 -> V_182 [ 1 ] &= ( T_9 ) ( V_160 >> 32 ) ;
memset ( V_181 -> V_182 + 2 , 0 , ( V_183 - 64 ) / 8 ) ;
if ( ! V_181 -> V_182 [ 0 ] && ! V_181 -> V_182 [ 1 ] )
return - V_129 ;
return 0 ;
}
int F_60 ( struct V_4 * V_5 , T_8 V_164 )
{
struct V_168 * V_169 = & V_5 -> V_170 ;
return F_61 ( F_62 ( V_169 , V_164 ) ) ;
}
int F_63 ( struct V_4 * V_5 , T_8 V_164 ,
unsigned int V_130 , unsigned int V_132 )
{
struct V_168 * V_169 = & V_5 -> V_170 ;
struct V_125 V_144 ;
V_144 . V_130 = V_130 ;
V_144 . V_132 = V_132 ;
V_144 . V_131 = V_144 . V_133 = 0 ;
V_144 . integer = 0 ;
return F_36 ( F_62 ( V_169 , V_164 ) , & V_144 ) ;
}
static int F_64 ( struct V_184 * V_185 ,
struct V_171 * V_186 )
{
struct V_187 * V_159 = V_186 -> V_166 ;
return F_49 ( F_65 ( V_185 , V_186 -> V_164 ) , V_159 -> V_158 , V_159 -> V_159 , V_159 -> V_160 ) ;
}
int V_187 ( struct V_4 * V_5 ,
unsigned int V_163 ,
T_8 V_164 ,
const struct V_187 * V_188 )
{
return F_53 ( V_5 , V_163 , V_164 ,
F_64 , ( void * ) V_188 ,
V_164 , - 1 ) ;
}
static int F_66 ( struct V_184 * V_185 ,
struct V_171 * V_186 )
{
struct V_189 * V_122 = V_186 -> V_166 ;
unsigned int V_148 = 0 , V_149 = 0 ;
int V_28 ;
V_28 = F_47 ( F_65 ( V_185 , V_186 -> V_164 ) ,
V_122 -> V_190 , V_122 -> V_138 , & V_148 , & V_149 ) ;
if ( V_28 >= 0 && V_149 && V_186 -> V_164 == V_191 ) {
V_185 -> V_192 = V_148 ;
V_185 -> V_193 = V_149 ;
}
return V_28 ;
}
int V_189 ( struct V_4 * V_5 ,
unsigned int V_163 ,
T_8 V_164 ,
struct V_189 * V_122 )
{
return F_53 ( V_5 , V_163 , V_164 ,
F_66 , V_122 ,
V_164 , - 1 ) ;
}
static int F_67 ( struct V_184 * V_185 ,
struct V_171 * V_186 )
{
struct V_194 * V_122 = V_186 -> V_166 ;
unsigned int V_148 = 0 , V_149 = 0 ;
int V_28 = F_48 ( F_65 ( V_185 , V_186 -> V_164 ) ,
V_122 -> V_190 , V_122 -> V_138 , & V_148 , & V_149 ) ;
if ( V_28 >= 0 && V_149 && V_186 -> V_164 == V_191 ) {
V_185 -> V_192 = V_148 ;
V_185 -> V_193 = V_149 ;
}
return V_28 ;
}
int V_194 ( struct V_4 * V_5 ,
unsigned int V_163 ,
T_8 V_164 ,
struct V_194 * V_122 )
{
return F_53 ( V_5 , V_163 , V_164 ,
F_67 , V_122 ,
V_164 , - 1 ) ;
}
static int F_68 ( struct V_184 * V_185 ,
struct V_171 * V_186 )
{
unsigned int V_188 = ( unsigned long ) V_186 -> V_166 ;
int V_195 = V_188 & 0xffff ;
unsigned int V_196 = V_188 >> 16 ;
struct V_125 * V_126 = F_65 ( V_185 , V_197 ) ;
if ( F_41 ( V_126 ) && F_69 ( V_126 ) == V_195 )
V_185 -> V_196 = V_196 ;
return 0 ;
}
int F_70 ( struct V_4 * V_5 ,
unsigned int V_163 ,
unsigned int V_195 ,
unsigned int V_196 )
{
unsigned long V_188 = ( V_196 << 16 ) | V_195 ;
return F_53 ( V_5 , V_163 , - 1 ,
F_68 ,
( void * ) V_188 ,
V_197 , - 1 ) ;
}
static int F_71 ( struct V_184 * V_185 ,
struct V_171 * V_186 )
{
unsigned long V_162 = ( unsigned long ) V_186 -> V_166 ;
return F_52 ( F_65 ( V_185 , V_186 -> V_164 ) , 0 , V_162 ) ;
}
int F_72 ( struct V_4 * V_5 ,
unsigned int V_163 ,
T_8 V_164 ,
unsigned long V_162 )
{
return F_53 ( V_5 , V_163 , V_164 ,
F_71 , ( void * ) V_162 ,
V_164 , - 1 ) ;
}
static int F_73 ( struct V_184 * V_185 , struct V_171 * V_186 )
{
static unsigned int V_198 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_49 ( F_65 ( V_185 , V_186 -> V_164 ) ,
F_56 ( V_198 ) , V_198 , 0 ) ;
}
int F_74 ( struct V_4 * V_5 ,
unsigned int V_163 ,
T_8 V_164 )
{
return F_53 ( V_5 , V_163 , V_164 ,
F_73 , NULL ,
V_164 , - 1 ) ;
}
static int F_75 ( struct V_184 * V_185 ,
struct V_171 * V_186 )
{
unsigned int V_199 = ( unsigned int ) ( V_200 ) V_186 -> V_166 ;
struct V_125 * V_104 ;
V_104 = F_65 ( V_185 , V_191 ) ;
return F_49 ( V_104 , 1 , & V_199 , 0 ) ;
}
int F_76 ( struct V_4 * V_5 ,
unsigned int V_199 )
{
return F_53 ( V_5 , V_201 ,
V_191 ,
F_75 ,
( void * ) ( V_200 ) V_199 ,
V_191 , - 1 ) ;
}
static void F_77 ( struct V_184 * V_185 ,
T_8 V_164 )
{
if ( F_78 ( V_164 ) ) {
F_79 ( F_80 ( V_185 , V_164 ) ) ;
V_185 -> V_202 |= 1 << V_164 ;
V_185 -> V_203 |= 1 << V_164 ;
return;
}
if ( F_81 ( V_164 ) ) {
F_50 ( F_65 ( V_185 , V_164 ) ) ;
V_185 -> V_202 |= 1 << V_164 ;
V_185 -> V_203 |= 1 << V_164 ;
return;
}
F_82 () ;
}
void F_83 ( struct V_184 * V_185 )
{
unsigned int V_135 ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
for ( V_135 = V_204 ; V_135 <= V_205 ; V_135 ++ )
F_77 ( V_185 , V_135 ) ;
for ( V_135 = V_206 ; V_135 <= V_207 ; V_135 ++ )
F_77 ( V_185 , V_135 ) ;
V_185 -> V_87 = ~ 0U ;
}
int F_84 ( const struct V_184 * V_185 ,
T_8 V_164 , int * V_208 )
{
if ( F_78 ( V_164 ) ) {
const struct V_180 * V_160 = F_85 ( V_185 , V_164 ) ;
if ( ! F_86 ( V_160 ) )
return - V_129 ;
if ( V_208 )
* V_208 = 0 ;
return F_87 ( V_160 ) ;
}
if ( F_81 ( V_164 ) ) {
const struct V_125 * V_126 = F_88 ( V_185 , V_164 ) ;
if ( ! F_41 ( V_126 ) )
return - V_129 ;
if ( V_208 )
* V_208 = V_126 -> V_131 ;
return F_69 ( V_126 ) ;
}
return - V_129 ;
}
void F_89 ( struct V_184 * V_185 ,
T_8 V_164 )
{
if ( F_78 ( V_164 ) ) {
F_90 ( F_80 ( V_185 , V_164 ) ) ;
V_185 -> V_202 |= 1 << V_164 ;
V_185 -> V_203 |= 1 << V_164 ;
} else if ( F_81 ( V_164 ) ) {
F_39 ( F_65 ( V_185 , V_164 ) ) ;
V_185 -> V_202 |= 1 << V_164 ;
V_185 -> V_203 |= 1 << V_164 ;
} else {
F_82 () ;
}
}
static int F_91 ( struct V_184 * V_185 ,
T_8 V_164 )
{
int V_128 ;
if ( F_78 ( V_164 ) )
V_128 = F_92 ( F_80 ( V_185 , V_164 ) ) ;
else if ( F_81 ( V_164 ) )
V_128 = F_40 ( F_65 ( V_185 , V_164 ) ) ;
else
return - V_129 ;
if ( V_128 ) {
V_185 -> V_202 |= 1 << V_164 ;
V_185 -> V_203 |= 1 << V_164 ;
}
return V_128 ;
}
int F_93 ( struct V_1 * V_38 ,
struct V_184 * V_185 ,
T_8 V_164 , int * V_208 )
{
int V_128 = F_91 ( V_185 , V_164 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( V_185 -> V_203 ) {
int V_28 = F_94 ( V_38 , V_185 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_84 ( V_185 , V_164 , V_208 ) ;
}
static int F_95 ( struct V_184 * V_185 ,
T_8 V_164 )
{
int V_128 ;
if ( F_78 ( V_164 ) )
V_128 = F_96 ( F_80 ( V_185 , V_164 ) ) ;
else if ( F_81 ( V_164 ) )
V_128 = F_42 ( F_65 ( V_185 , V_164 ) ) ;
else
return - V_129 ;
if ( V_128 ) {
V_185 -> V_202 |= 1 << V_164 ;
V_185 -> V_203 |= 1 << V_164 ;
}
return V_128 ;
}
int F_97 ( struct V_1 * V_38 ,
struct V_184 * V_185 ,
T_8 V_164 , int * V_208 )
{
int V_128 = F_95 ( V_185 , V_164 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( V_185 -> V_203 ) {
int V_28 = F_94 ( V_38 , V_185 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_84 ( V_185 , V_164 , V_208 ) ;
}
int F_98 ( struct V_1 * V_38 ,
struct V_184 * V_185 )
{
static int V_209 [] = {
V_210 ,
V_211 ,
V_212 ,
V_213 ,
V_191 ,
V_214 ,
V_215 ,
V_216 ,
- 1
} ;
int V_28 , * V_127 ;
for ( V_127 = V_209 ; * V_127 != - 1 ; V_127 ++ ) {
if ( * V_127 != V_215 )
V_28 = F_93 ( V_38 , V_185 , * V_127 , NULL ) ;
else
V_28 = F_97 ( V_38 , V_185 , * V_127 , NULL ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
void * V_217 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_218 ;
F_100 ( V_2 , V_218 ) ;
if ( F_101 ( V_2 ) &&
F_27 ( V_2 ) >= 0 )
V_5 -> V_21 -> V_22 %= V_5 -> V_17 ;
else {
V_5 -> V_21 -> V_22 = 0 ;
V_5 -> V_109 = 0 ;
}
F_102 ( V_2 , V_218 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
void * V_217 )
{
struct V_219 * V_87 = V_217 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_195 ;
if ( ! ( V_5 -> V_87 & V_220 ) ) {
V_87 -> V_221 = - 1 ;
return 0 ;
}
V_195 = F_104 ( V_5 -> V_31 ) ;
if ( V_195 < 0 )
return V_195 ;
V_87 -> V_221 = 0 ;
switch ( V_5 -> V_23 ) {
case V_25 :
case V_24 :
V_87 -> V_222 = V_87 -> V_223 * V_195 ;
V_87 -> V_162 = V_5 -> V_32 * V_195 ;
break;
case V_224 :
case V_225 :
{
T_3 V_226 = V_5 -> V_35 / V_5 -> V_32 ;
V_87 -> V_222 = V_87 -> V_223 * V_226 * 8 ;
V_87 -> V_162 = V_195 ;
break;
}
default:
F_82 () ;
break;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 ,
void * V_217 )
{
struct V_184 * V_185 = V_217 ;
T_10 V_31 ;
int V_32 , V_195 ;
V_185 -> V_227 = V_2 -> V_5 -> V_86 . V_227 ;
if ( ! ( V_2 -> V_5 -> V_86 . V_87 & V_228 ) ) {
V_31 = F_106 ( V_185 ) ;
V_32 = F_107 ( V_185 ) ;
V_195 = F_104 ( V_31 ) ;
V_185 -> V_227 /= V_195 * V_32 ;
}
return 0 ;
}
int F_108 ( struct V_1 * V_2 ,
unsigned int V_229 , void * V_217 )
{
switch ( V_229 ) {
case V_230 :
return 0 ;
case V_231 :
return F_99 ( V_2 , V_217 ) ;
case V_232 :
return F_103 ( V_2 , V_217 ) ;
case V_233 :
return F_105 ( V_2 , V_217 ) ;
}
return - V_234 ;
}
void F_109 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_218 ;
if ( F_110 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_235 )
V_5 -> V_235 ( V_2 ) ;
F_100 ( V_2 , V_218 ) ;
if ( ! F_101 ( V_2 ) ||
F_22 ( V_2 , 1 ) < 0 )
goto V_236;
if ( V_2 -> V_237 )
F_111 ( V_2 -> V_238 , 1 ) ;
V_236:
F_102 ( V_2 , V_218 ) ;
if ( V_5 -> V_239 )
V_5 -> V_239 ( V_2 ) ;
F_112 ( & V_5 -> V_240 , V_241 , V_242 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
T_1 * V_243 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_244 = V_2 -> V_42 == V_67 ;
T_11 V_245 ;
int V_28 = 0 ;
T_1 V_20 = 0 ;
long V_246 , V_247 ;
F_114 ( & V_245 , V_248 ) ;
F_115 ( V_249 ) ;
F_116 ( & V_5 -> V_74 , & V_245 ) ;
if ( V_5 -> V_100 )
V_246 = V_250 ;
else {
V_246 = 10 ;
if ( V_5 -> V_104 ) {
long V_144 = V_5 -> V_62 * 2 / V_5 -> V_104 ;
V_246 = V_132 ( V_144 , V_246 ) ;
}
V_246 = F_117 ( V_246 * 1000 ) ;
}
for (; ; ) {
if ( F_118 ( V_248 ) ) {
V_28 = - V_251 ;
break;
}
if ( V_244 )
V_20 = F_18 ( V_5 ) ;
else
V_20 = F_19 ( V_5 ) ;
if ( V_20 >= V_5 -> V_73 )
break;
F_119 ( V_2 ) ;
V_247 = F_120 ( V_246 ) ;
F_121 ( V_2 ) ;
F_115 ( V_249 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_252 :
V_28 = - V_253 ;
goto V_254;
case V_47 :
V_28 = - V_71 ;
goto V_254;
case V_70 :
if ( V_244 )
V_28 = - V_71 ;
else
V_20 = 0 ;
goto V_254;
case V_255 :
case V_256 :
case V_257 :
V_28 = - V_258 ;
goto V_254;
case V_259 :
continue;
}
if ( ! V_247 ) {
F_12 ( L_22 ,
V_244 ? L_23 : L_24 ) ;
V_28 = - V_260 ;
break;
}
}
V_254:
F_115 ( V_261 ) ;
F_122 ( & V_5 -> V_74 , & V_245 ) ;
* V_243 = V_20 ;
return V_28 ;
}
static int F_123 ( struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned long V_263 , unsigned int V_264 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_12 * V_265 = ( char T_12 * ) V_263 + F_4 ( V_5 , V_264 ) ;
if ( V_2 -> V_26 -> V_266 ) {
if ( ( V_28 = V_2 -> V_26 -> V_266 ( V_2 , - 1 , V_262 , V_265 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_262 ) ;
if ( F_124 ( V_29 , V_265 , F_4 ( V_5 , V_6 ) ) )
return - V_267 ;
}
return 0 ;
}
static T_2 F_125 ( struct V_1 * V_2 ,
unsigned long V_263 ,
T_1 V_226 ,
int V_268 ,
T_13 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_269 = 0 ;
T_1 V_221 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_226 == 0 )
return 0 ;
F_121 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_270 :
case V_271 :
case V_259 :
break;
case V_47 :
V_28 = - V_71 ;
goto V_272;
case V_252 :
V_28 = - V_253 ;
goto V_272;
default:
V_28 = - V_258 ;
goto V_272;
}
V_5 -> V_73 = V_5 -> V_14 -> V_75 ? : 1 ;
if ( V_5 -> V_21 -> V_69 == V_271 )
F_27 ( V_2 ) ;
V_20 = F_18 ( V_5 ) ;
while ( V_226 > 0 ) {
T_1 V_6 , V_15 , V_273 ;
T_1 V_274 ;
if ( ! V_20 ) {
if ( V_268 ) {
V_28 = - V_275 ;
goto V_272;
}
V_5 -> V_73 = F_126 ( T_1 , V_226 ,
V_5 -> V_14 -> V_75 ? : 1 ) ;
V_28 = F_113 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_272;
}
V_6 = V_226 > V_20 ? V_20 : V_226 ;
V_274 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_274 )
V_6 = V_274 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_73 = 0 ;
F_119 ( V_2 ) ;
return - V_129 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_273 = V_15 % V_5 -> V_17 ;
F_119 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_273 , V_263 , V_221 , V_6 ) ;
F_121 ( V_2 ) ;
if ( V_28 < 0 )
goto V_272;
switch ( V_5 -> V_21 -> V_69 ) {
case V_47 :
V_28 = - V_71 ;
goto V_272;
case V_252 :
V_28 = - V_253 ;
goto V_272;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_276 )
V_2 -> V_26 -> V_276 ( V_2 ) ;
V_221 += V_6 ;
V_226 -= V_6 ;
V_269 += V_6 ;
V_20 -= V_6 ;
if ( V_5 -> V_21 -> V_69 == V_270 &&
F_2 ( V_5 ) >= ( T_2 ) V_5 -> V_277 ) {
V_28 = F_127 ( V_2 ) ;
if ( V_28 < 0 )
goto V_272;
}
}
V_272:
V_5 -> V_73 = 0 ;
if ( V_269 > 0 && V_28 >= 0 )
F_17 ( V_2 , V_5 ) ;
F_119 ( V_2 ) ;
return V_269 > 0 ? ( T_2 ) V_269 : V_28 ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_110 ( V_2 ) )
return - V_234 ;
V_5 = V_2 -> V_5 ;
if ( F_3 ( ! V_2 -> V_26 -> V_266 && ! V_5 -> V_30 ) )
return - V_129 ;
if ( V_5 -> V_21 -> V_69 == V_255 )
return - V_258 ;
return 0 ;
}
T_2 F_129 ( struct V_1 * V_2 , const void T_12 * V_265 , T_1 V_226 )
{
struct V_4 * V_5 ;
int V_268 ;
int V_28 ;
V_28 = F_128 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_268 = ! ! ( V_2 -> V_278 & V_279 ) ;
if ( V_5 -> V_23 != V_24 &&
V_5 -> V_32 > 1 )
return - V_129 ;
return F_125 ( V_2 , ( unsigned long ) V_265 , V_226 , V_268 ,
F_123 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned long V_263 , unsigned int V_264 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_12 * * V_280 = ( void T_12 * * ) V_263 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_266 ) {
if ( F_3 ( ! V_2 -> V_26 -> V_27 ) )
return - V_129 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_280 ) {
if ( * V_280 == NULL ) {
if ( ( V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_262 , V_6 ) ) < 0 )
return V_28 ;
} else {
char T_12 * V_265 = * V_280 + F_6 ( V_5 , V_264 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_266 ( V_2 , V_33 , V_262 , V_265 , V_6 ) ) < 0 )
return V_28 ;
}
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_280 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_262 ) ;
if ( * V_280 == NULL ) {
F_5 ( V_5 -> V_31 , V_29 , V_6 ) ;
} else {
char T_12 * V_265 = * V_280 + F_6 ( V_5 , V_264 ) ;
if ( F_124 ( V_29 , V_265 , F_6 ( V_5 , V_6 ) ) )
return - V_267 ;
}
}
}
return 0 ;
}
T_2 F_131 ( struct V_1 * V_2 ,
void T_12 * * V_280 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_268 ;
int V_28 ;
V_28 = F_128 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_268 = ! ! ( V_2 -> V_278 & V_279 ) ;
if ( V_5 -> V_23 != V_225 )
return - V_129 ;
return F_125 ( V_2 , ( unsigned long ) V_280 , V_6 ,
V_268 , F_130 ) ;
}
static int F_132 ( struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned long V_263 , unsigned int V_264 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_12 * V_265 = ( char T_12 * ) V_263 + F_4 ( V_5 , V_264 ) ;
if ( V_2 -> V_26 -> V_266 ) {
if ( ( V_28 = V_2 -> V_26 -> V_266 ( V_2 , - 1 , V_262 , V_265 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_262 ) ;
if ( F_133 ( V_265 , V_29 , F_4 ( V_5 , V_6 ) ) )
return - V_267 ;
}
return 0 ;
}
static T_2 F_134 ( struct V_1 * V_2 ,
unsigned long V_263 ,
T_1 V_226 ,
int V_268 ,
T_13 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_269 = 0 ;
T_1 V_221 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_226 == 0 )
return 0 ;
F_121 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_69 ) {
case V_270 :
if ( V_226 >= V_5 -> V_277 ) {
V_28 = F_127 ( V_2 ) ;
if ( V_28 < 0 )
goto V_272;
}
break;
case V_70 :
case V_271 :
case V_259 :
break;
case V_47 :
V_28 = - V_71 ;
goto V_272;
case V_252 :
V_28 = - V_253 ;
goto V_272;
default:
V_28 = - V_258 ;
goto V_272;
}
V_5 -> V_73 = V_5 -> V_14 -> V_75 ? : 1 ;
if ( V_5 -> V_21 -> V_69 == V_271 )
F_27 ( V_2 ) ;
V_20 = F_19 ( V_5 ) ;
while ( V_226 > 0 ) {
T_1 V_6 , V_15 , V_273 ;
T_1 V_274 ;
if ( ! V_20 ) {
if ( V_5 -> V_21 -> V_69 ==
V_70 ) {
F_10 ( V_2 , V_256 ) ;
goto V_272;
}
if ( V_268 ) {
V_28 = - V_275 ;
goto V_272;
}
V_5 -> V_73 = F_126 ( T_1 , V_226 ,
V_5 -> V_14 -> V_75 ? : 1 ) ;
V_28 = F_113 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_272;
if ( ! V_20 )
continue;
}
V_6 = V_226 > V_20 ? V_20 : V_226 ;
V_274 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_274 )
V_6 = V_274 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_73 = 0 ;
F_119 ( V_2 ) ;
return - V_129 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_273 = V_15 % V_5 -> V_17 ;
F_119 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_273 , V_263 , V_221 , V_6 ) ;
F_121 ( V_2 ) ;
if ( V_28 < 0 )
goto V_272;
switch ( V_5 -> V_21 -> V_69 ) {
case V_47 :
V_28 = - V_71 ;
goto V_272;
case V_252 :
V_28 = - V_253 ;
goto V_272;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_276 )
V_2 -> V_26 -> V_276 ( V_2 ) ;
V_221 += V_6 ;
V_226 -= V_6 ;
V_269 += V_6 ;
V_20 -= V_6 ;
}
V_272:
V_5 -> V_73 = 0 ;
if ( V_269 > 0 && V_28 >= 0 )
F_17 ( V_2 , V_5 ) ;
F_119 ( V_2 ) ;
return V_269 > 0 ? ( T_2 ) V_269 : V_28 ;
}
T_2 F_135 ( struct V_1 * V_2 , void T_12 * V_265 , T_1 V_226 )
{
struct V_4 * V_5 ;
int V_268 ;
int V_28 ;
V_28 = F_128 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_268 = ! ! ( V_2 -> V_278 & V_279 ) ;
if ( V_5 -> V_23 != V_24 )
return - V_129 ;
return F_134 ( V_2 , ( unsigned long ) V_265 , V_226 , V_268 , F_132 ) ;
}
static int F_136 ( struct V_1 * V_2 ,
unsigned int V_262 ,
unsigned long V_263 , unsigned int V_264 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_12 * * V_280 = ( void T_12 * * ) V_263 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_266 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_280 ) {
char T_12 * V_265 ;
if ( * V_280 == NULL )
continue;
V_265 = * V_280 + F_6 ( V_5 , V_264 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_266 ( V_2 , V_33 , V_262 , V_265 , V_6 ) ) < 0 )
return V_28 ;
}
} else {
T_1 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_280 ) {
char * V_29 ;
char T_12 * V_265 ;
if ( * V_280 == NULL )
continue;
V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_262 ) ;
V_265 = * V_280 + F_6 ( V_5 , V_264 ) ;
if ( F_133 ( V_265 , V_29 , F_6 ( V_5 , V_6 ) ) )
return - V_267 ;
}
}
return 0 ;
}
T_2 F_137 ( struct V_1 * V_2 ,
void T_12 * * V_280 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_268 ;
int V_28 ;
V_28 = F_128 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 -> V_69 == V_255 )
return - V_258 ;
V_268 = ! ! ( V_2 -> V_278 & V_279 ) ;
if ( V_5 -> V_23 != V_225 )
return - V_129 ;
return F_134 ( V_2 , ( unsigned long ) V_280 , V_6 , V_268 , F_136 ) ;
}
static bool F_138 ( const struct V_281 * V_87 , int V_282 )
{
if ( V_282 > V_87 -> V_283 )
return false ;
return ! V_87 -> V_284 || ( V_87 -> V_284 & ( 1U << V_282 ) ) ;
}
static int F_139 ( struct V_285 * V_286 ,
struct V_287 * V_288 )
{
struct V_281 * V_87 = F_140 ( V_286 ) ;
V_288 -> type = V_289 ;
V_288 -> V_158 = 0 ;
V_288 -> V_158 = V_87 -> V_283 ;
V_288 -> V_290 . integer . V_130 = 0 ;
V_288 -> V_290 . integer . V_132 = V_291 ;
return 0 ;
}
static int F_141 ( struct V_285 * V_286 ,
struct V_292 * V_293 )
{
struct V_281 * V_87 = F_140 ( V_286 ) ;
unsigned int V_60 = F_142 ( V_286 , & V_293 -> V_294 ) ;
struct V_1 * V_2 ;
const struct V_295 * V_296 ;
if ( F_3 ( ! V_87 -> V_297 ) )
return - V_129 ;
V_2 = F_143 ( V_87 , V_60 ) ;
if ( ! V_2 )
return - V_298 ;
memset ( V_293 -> V_290 . integer . V_290 , 0 ,
sizeof( V_293 -> V_290 . integer . V_290 ) ) ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_296 = V_87 -> V_297 ; V_296 -> V_32 ; V_296 ++ ) {
int V_126 ;
if ( V_296 -> V_32 == V_2 -> V_5 -> V_32 &&
F_138 ( V_87 , V_296 -> V_32 ) ) {
for ( V_126 = 0 ; V_126 < V_296 -> V_32 ; V_126 ++ )
V_293 -> V_290 . integer . V_290 [ V_126 ] = V_296 -> V_296 [ V_126 ] ;
return 0 ;
}
}
return - V_129 ;
}
static int F_144 ( struct V_285 * V_286 , int V_299 ,
unsigned int V_226 , unsigned int T_12 * V_300 )
{
struct V_281 * V_87 = F_140 ( V_286 ) ;
const struct V_295 * V_296 ;
unsigned int T_12 * V_301 ;
int V_33 , V_158 = 0 ;
if ( F_3 ( ! V_87 -> V_297 ) )
return - V_129 ;
if ( V_226 < 8 )
return - V_177 ;
if ( F_145 ( V_302 , V_300 ) )
return - V_267 ;
V_226 -= 8 ;
V_301 = V_300 + 2 ;
for ( V_296 = V_87 -> V_297 ; V_296 -> V_32 ; V_296 ++ ) {
int V_303 = V_296 -> V_32 * 4 ;
if ( ! F_138 ( V_87 , V_296 -> V_32 ) )
continue;
if ( V_226 < 8 )
return - V_177 ;
if ( F_145 ( V_304 , V_301 ) ||
F_145 ( V_303 , V_301 + 1 ) )
return - V_267 ;
V_301 += 2 ;
V_226 -= 8 ;
V_158 += 8 ;
if ( V_226 < V_303 )
return - V_177 ;
V_226 -= V_303 ;
V_158 += V_303 ;
for ( V_33 = 0 ; V_33 < V_296 -> V_32 ; V_33 ++ ) {
if ( F_145 ( V_296 -> V_296 [ V_33 ] , V_301 ) )
return - V_267 ;
V_301 ++ ;
}
}
if ( F_145 ( V_158 , V_300 + 1 ) )
return - V_267 ;
return 0 ;
}
static void F_146 ( struct V_285 * V_286 )
{
struct V_281 * V_87 = F_140 ( V_286 ) ;
V_87 -> V_38 -> V_116 [ V_87 -> V_42 ] . V_305 = NULL ;
F_55 ( V_87 ) ;
}
int F_147 ( struct V_112 * V_38 , int V_42 ,
const struct V_295 * V_297 ,
int V_283 ,
unsigned long V_306 ,
struct V_281 * * V_307 )
{
struct V_281 * V_87 ;
struct V_308 V_309 = {
. V_310 = V_311 ,
. V_23 = V_312 |
V_313 |
V_314 ,
. V_87 = F_139 ,
. V_315 = F_141 ,
. V_300 . V_33 = F_144 ,
} ;
int V_28 ;
V_87 = F_15 ( sizeof( * V_87 ) , V_176 ) ;
if ( ! V_87 )
return - V_177 ;
V_87 -> V_38 = V_38 ;
V_87 -> V_42 = V_42 ;
V_87 -> V_297 = V_297 ;
V_87 -> V_283 = V_283 ;
if ( V_42 == V_67 )
V_309 . V_36 = L_25 ;
else
V_309 . V_36 = L_26 ;
V_309 . V_41 = V_38 -> V_41 ;
V_309 . V_158 = V_38 -> V_116 [ V_42 ] . V_316 ;
V_309 . V_306 = V_306 ;
V_87 -> V_317 = F_148 ( & V_309 , V_87 ) ;
if ( ! V_87 -> V_317 ) {
F_55 ( V_87 ) ;
return - V_177 ;
}
V_87 -> V_317 -> V_318 = F_146 ;
V_28 = F_149 ( V_38 -> V_39 , V_87 -> V_317 ) ;
if ( V_28 < 0 )
return V_28 ;
V_38 -> V_116 [ V_42 ] . V_305 = V_87 -> V_317 ;
if ( V_307 )
* V_307 = V_87 ;
return 0 ;
}
