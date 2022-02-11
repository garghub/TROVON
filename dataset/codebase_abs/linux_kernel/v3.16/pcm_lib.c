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
F_12 ( V_2 -> V_38 , L_2 , V_36 ) ;
F_13 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_49 , int V_50 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_51 * log = V_5 -> V_52 ;
struct V_53 * V_54 ;
if ( log == NULL ) {
log = F_15 ( sizeof( * log ) , V_55 ) ;
if ( log == NULL )
return;
V_5 -> V_52 = log ;
} else {
if ( F_11 ( V_2 , V_56 ) && log -> V_57 )
return;
}
V_54 = & log -> V_58 [ log -> V_59 ] ;
V_54 -> V_50 = V_50 ;
V_54 -> V_60 = V_60 ;
V_54 -> V_49 = V_49 ;
V_54 -> V_61 = V_5 -> V_61 ;
V_54 -> V_17 = V_5 -> V_17 ;
V_54 -> V_62 = V_5 -> V_21 -> V_22 ;
V_54 -> V_63 = V_5 -> V_63 ;
log -> V_59 = ( log -> V_59 + 1 ) % V_64 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_51 * log = V_2 -> V_5 -> V_52 ;
struct V_53 * V_54 ;
char V_36 [ 16 ] ;
unsigned int V_59 ;
int V_65 ;
if ( log == NULL )
return;
if ( F_11 ( V_2 , V_56 ) && log -> V_57 )
return;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
for ( V_65 = 0 , V_59 = log -> V_59 ; V_65 < V_64 ; V_65 ++ ) {
V_54 = & log -> V_58 [ V_59 ] ;
if ( V_54 -> V_61 == 0 )
break;
F_17 ( L_3
L_4 ,
V_36 , V_54 -> V_50 ? L_5 : L_6 ,
V_54 -> V_60 ,
( unsigned long ) V_54 -> V_49 ,
( unsigned long ) V_54 -> V_61 ,
( unsigned long ) V_54 -> V_17 ,
( unsigned long ) V_54 -> V_62 ,
( unsigned long ) V_54 -> V_63 ) ;
V_59 ++ ;
V_59 %= V_64 ;
}
log -> V_57 = 1 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_1 V_20 ;
if ( V_2 -> V_42 == V_66 )
V_20 = F_19 ( V_5 ) ;
else
V_20 = F_20 ( V_5 ) ;
if ( V_20 > V_5 -> V_67 )
V_5 -> V_67 = V_20 ;
if ( V_5 -> V_21 -> V_68 == V_69 ) {
if ( V_20 >= V_5 -> V_17 ) {
F_21 ( V_2 ) ;
return - V_70 ;
}
} else {
if ( V_20 >= V_5 -> V_71 ) {
F_8 ( V_2 ) ;
return - V_70 ;
}
}
if ( V_5 -> V_72 ) {
if ( V_20 >= V_5 -> V_72 )
F_22 ( & V_5 -> V_73 ) ;
} else if ( V_20 >= V_5 -> V_14 -> V_74 )
F_22 ( & V_5 -> V_75 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_50 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_49 ;
T_1 V_62 , V_3 , V_76 ;
T_2 V_77 , V_78 ;
unsigned long V_79 ;
unsigned long V_80 ;
struct V_45 V_81 ;
struct V_45 V_82 ;
int V_83 = 0 ;
V_62 = V_5 -> V_21 -> V_22 ;
V_49 = V_2 -> V_26 -> V_84 ( V_2 ) ;
V_80 = V_60 ;
if ( V_5 -> V_43 == V_44 ) {
F_9 ( V_5 , (struct V_45 * ) & V_81 ) ;
if ( ( V_5 -> V_85 . V_86 & V_87 ) &&
( V_2 -> V_26 -> V_88 ) )
V_2 -> V_26 -> V_88 ( V_2 , & V_82 ) ;
}
if ( V_49 == V_89 ) {
F_8 ( V_2 ) ;
return - V_70 ;
}
if ( V_49 >= V_5 -> V_17 ) {
if ( F_24 () ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_16 ( V_2 ) ;
F_25 ( V_2 -> V_38 ,
L_7 ,
V_36 , V_49 , V_5 -> V_17 ,
V_5 -> V_61 ) ;
}
V_49 = 0 ;
}
V_49 -= V_49 % V_5 -> V_90 ;
if ( F_11 ( V_2 , V_91 ) )
F_14 ( V_2 , V_49 , V_50 ) ;
V_76 = V_5 -> V_63 ;
V_3 = V_76 + V_49 ;
if ( V_50 ) {
V_78 = V_5 -> V_92 + V_5 -> V_61 ;
if ( V_78 > V_3 ) {
V_77 = V_80 - V_5 -> V_93 ;
if ( V_77 > V_5 -> V_94 / 2 ) {
V_76 += V_5 -> V_17 ;
if ( V_76 >= V_5 -> V_10 ) {
V_76 = 0 ;
V_83 ++ ;
}
V_3 = V_76 + V_49 ;
goto V_95;
}
}
}
if ( V_3 < V_62 ) {
V_76 += V_5 -> V_17 ;
if ( V_76 >= V_5 -> V_10 ) {
V_76 = 0 ;
V_83 ++ ;
}
V_3 = V_76 + V_49 ;
}
V_95:
V_78 = V_3 - V_62 ;
if ( V_78 < 0 )
V_78 += V_5 -> V_10 ;
if ( F_11 ( V_2 , V_50 ?
V_96 : V_97 ) ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_26 ( V_2 -> V_38 ,
L_8 ,
V_50 ? L_9 : L_10 ,
V_36 ,
( unsigned int ) V_49 ,
( unsigned int ) V_5 -> V_61 ,
( unsigned int ) V_5 -> V_17 ,
( unsigned long ) V_78 ,
( unsigned long ) V_62 ,
( unsigned long ) V_3 ,
( unsigned long ) V_5 -> V_63 ) ;
}
if ( V_5 -> V_98 ) {
T_2 V_99 ;
V_79 = V_80 - V_5 -> V_93 ;
if ( V_79 < V_5 -> V_94 / 2 )
goto V_100;
V_77 = V_79 - V_78 * V_101 / V_5 -> V_102 ;
V_99 = V_5 -> V_94 / 2 + 1 ;
while ( V_77 > V_99 ) {
V_78 += V_5 -> V_17 ;
V_76 += V_5 -> V_17 ;
if ( V_76 >= V_5 -> V_10 ) {
V_76 = 0 ;
V_83 ++ ;
}
V_3 = V_76 + V_49 ;
V_77 -= V_5 -> V_94 ;
}
goto V_100;
}
if ( V_78 >= V_5 -> V_17 + V_5 -> V_61 ) {
F_27 ( V_2 ,
L_11
L_12
L_13 ,
V_50 ? L_5 : L_14 ,
V_2 -> V_42 , ( long ) V_49 ,
( long ) V_3 , ( long ) V_62 ) ;
return 0 ;
}
if ( ! F_11 ( V_2 , V_103 ) )
goto V_104;
if ( V_5 -> V_85 . V_86 & V_105 )
goto V_104;
V_77 = V_78 ;
if ( V_77 < V_5 -> V_106 )
goto V_104;
V_77 -= V_5 -> V_106 ;
V_79 = V_80 - V_5 -> V_93 ;
if ( ( ( V_77 * V_101 ) / V_5 -> V_102 ) > V_79 + V_101 / 100 ) {
V_78 = V_79 /
( ( ( V_5 -> V_61 * V_101 ) / V_5 -> V_102 )
+ V_101 / 100 ) ;
V_3 = V_62 ;
V_76 = V_78 ;
while ( V_78 > 0 ) {
V_3 += V_5 -> V_61 ;
if ( V_3 >= V_5 -> V_10 ) {
V_3 -= V_5 -> V_10 ;
V_83 -- ;
}
V_78 -- ;
}
F_27 ( V_2 ,
L_15
L_16
L_17 ,
V_50 ? L_5 : L_6 ,
( long ) V_49 , ( long ) V_77 ,
( long ) V_5 -> V_61 , V_79 ,
( ( V_77 * V_101 ) / V_5 -> V_102 ) , V_76 ,
( unsigned long ) V_62 ,
( unsigned long ) V_3 ) ;
V_78 = 0 ;
V_76 = V_3 - ( V_3 % V_5 -> V_17 ) ;
}
V_104:
if ( V_78 > V_5 -> V_61 + V_5 -> V_61 / 2 ) {
F_27 ( V_2 ,
L_18
L_19
L_13 ,
V_50 ? L_5 : L_6 ,
V_2 -> V_42 , ( long ) V_78 ,
( long ) V_3 ,
( long ) V_62 ) ;
}
V_100:
if ( V_5 -> V_21 -> V_22 == V_3 )
return 0 ;
if ( V_2 -> V_42 == V_66 &&
V_5 -> V_9 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_50 ) {
V_78 = V_3 - V_5 -> V_92 ;
if ( V_78 < 0 )
V_78 += V_5 -> V_10 ;
V_78 -= ( T_1 ) V_78 % V_5 -> V_61 ;
V_5 -> V_92 += V_78 ;
if ( V_5 -> V_92 >= V_5 -> V_10 )
V_5 -> V_92 -= V_5 -> V_10 ;
}
V_5 -> V_63 = V_76 ;
V_5 -> V_21 -> V_22 = V_3 ;
V_5 -> V_93 = V_80 ;
if ( V_83 ) {
F_3 ( V_83 != 1 ) ;
V_5 -> V_107 += V_5 -> V_10 ;
}
if ( V_5 -> V_43 == V_44 ) {
V_5 -> V_21 -> V_46 = V_81 ;
if ( ! ( V_5 -> V_85 . V_86 & V_87 ) ) {
T_4 V_108 , V_109 ;
if ( V_2 -> V_42 == V_66 )
V_108 = V_5 -> V_107
+ V_5 -> V_21 -> V_22
- V_5 -> V_106 ;
else
V_108 = V_5 -> V_107
+ V_5 -> V_21 -> V_22
+ V_5 -> V_106 ;
V_109 = F_28 ( V_108 * 1000000000LL ,
V_5 -> V_102 ) ;
V_82 = F_29 ( V_109 ) ;
}
V_5 -> V_21 -> V_82 = V_82 ;
}
return F_18 ( V_2 , V_5 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , 0 ) ;
}
void F_31 ( struct V_110 * V_38 , int V_111 ,
const struct V_112 * V_26 )
{
struct V_113 * V_42 = & V_38 -> V_114 [ V_111 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_42 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_115 )
V_2 -> V_26 = V_26 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_116 . V_117 [ 0 ] = V_2 -> V_38 -> V_39 -> V_40 ;
V_5 -> V_116 . V_117 [ 1 ] = - 1 ;
V_5 -> V_116 . V_117 [ 2 ] = - 1 ;
V_5 -> V_116 . V_117 [ 3 ] = - 1 ;
}
static inline unsigned int F_33 ( unsigned int V_118 , unsigned int V_119 ,
unsigned int * V_120 )
{
if ( V_119 == 0 ) {
* V_120 = 0 ;
return V_121 ;
}
* V_120 = V_118 % V_119 ;
return V_118 / V_119 ;
}
static inline unsigned int F_34 ( unsigned int V_118 , unsigned int V_119 )
{
if ( V_119 == 0 )
return V_121 ;
return V_118 / V_119 ;
}
static inline unsigned int F_35 ( unsigned int V_118 , unsigned int V_119 )
{
unsigned int V_120 ;
unsigned int V_122 ;
if ( V_119 == 0 )
return V_121 ;
V_122 = F_33 ( V_118 , V_119 , & V_120 ) ;
if ( V_120 )
++ V_122 ;
return V_122 ;
}
static inline unsigned int F_36 ( unsigned int V_118 , unsigned int V_119 )
{
if ( V_118 == 0 )
return 0 ;
if ( F_34 ( V_121 , V_118 ) < V_119 )
return V_121 ;
return V_118 * V_119 ;
}
static inline unsigned int F_37 ( unsigned int V_118 , unsigned int V_119 ,
unsigned int V_33 , unsigned int * V_120 )
{
T_5 V_12 = ( T_5 ) V_118 * V_119 ;
if ( V_33 == 0 ) {
F_3 ( ! V_12 ) ;
* V_120 = 0 ;
return V_121 ;
}
V_12 = F_38 ( V_12 , V_33 , V_120 ) ;
if ( V_12 >= V_121 ) {
* V_120 = 0 ;
return V_121 ;
}
return V_12 ;
}
int F_39 ( struct V_123 * V_124 , const struct V_123 * V_125 )
{
int V_126 = 0 ;
if ( F_3 ( F_40 ( V_124 ) ) )
return - V_127 ;
if ( V_124 -> V_128 < V_125 -> V_128 ) {
V_124 -> V_128 = V_125 -> V_128 ;
V_124 -> V_129 = V_125 -> V_129 ;
V_126 = 1 ;
} else if ( V_124 -> V_128 == V_125 -> V_128 && ! V_124 -> V_129 && V_125 -> V_129 ) {
V_124 -> V_129 = 1 ;
V_126 = 1 ;
}
if ( V_124 -> V_130 > V_125 -> V_130 ) {
V_124 -> V_130 = V_125 -> V_130 ;
V_124 -> V_131 = V_125 -> V_131 ;
V_126 = 1 ;
} else if ( V_124 -> V_130 == V_125 -> V_130 && ! V_124 -> V_131 && V_125 -> V_131 ) {
V_124 -> V_131 = 1 ;
V_126 = 1 ;
}
if ( ! V_124 -> integer && V_125 -> integer ) {
V_124 -> integer = 1 ;
V_126 = 1 ;
}
if ( V_124 -> integer ) {
if ( V_124 -> V_129 ) {
V_124 -> V_128 ++ ;
V_124 -> V_129 = 0 ;
}
if ( V_124 -> V_131 ) {
V_124 -> V_130 -- ;
V_124 -> V_131 = 0 ;
}
} else if ( ! V_124 -> V_129 && ! V_124 -> V_131 && V_124 -> V_128 == V_124 -> V_130 )
V_124 -> integer = 1 ;
if ( F_41 ( V_124 ) ) {
F_42 ( V_124 ) ;
return - V_127 ;
}
return V_126 ;
}
static int F_43 ( struct V_123 * V_124 )
{
if ( F_3 ( F_40 ( V_124 ) ) )
return - V_127 ;
if ( F_44 ( V_124 ) )
return 0 ;
V_124 -> V_130 = V_124 -> V_128 ;
V_124 -> V_131 = V_124 -> V_129 ;
if ( V_124 -> V_131 )
V_124 -> V_130 ++ ;
return 1 ;
}
static int F_45 ( struct V_123 * V_124 )
{
if ( F_3 ( F_40 ( V_124 ) ) )
return - V_127 ;
if ( F_44 ( V_124 ) )
return 0 ;
V_124 -> V_128 = V_124 -> V_130 ;
V_124 -> V_129 = V_124 -> V_131 ;
if ( V_124 -> V_129 )
V_124 -> V_128 -- ;
return 1 ;
}
void F_46 ( const struct V_123 * V_118 , const struct V_123 * V_119 , struct V_123 * V_33 )
{
if ( V_118 -> V_132 || V_119 -> V_132 ) {
F_42 ( V_33 ) ;
return;
}
V_33 -> V_132 = 0 ;
V_33 -> V_128 = F_36 ( V_118 -> V_128 , V_119 -> V_128 ) ;
V_33 -> V_129 = ( V_118 -> V_129 || V_119 -> V_129 ) ;
V_33 -> V_130 = F_36 ( V_118 -> V_130 , V_119 -> V_130 ) ;
V_33 -> V_131 = ( V_118 -> V_131 || V_119 -> V_131 ) ;
V_33 -> integer = ( V_118 -> integer && V_119 -> integer ) ;
}
void F_47 ( const struct V_123 * V_118 , const struct V_123 * V_119 , struct V_123 * V_33 )
{
unsigned int V_120 ;
if ( V_118 -> V_132 || V_119 -> V_132 ) {
F_42 ( V_33 ) ;
return;
}
V_33 -> V_132 = 0 ;
V_33 -> V_128 = F_33 ( V_118 -> V_128 , V_119 -> V_130 , & V_120 ) ;
V_33 -> V_129 = ( V_120 || V_118 -> V_129 || V_119 -> V_131 ) ;
if ( V_119 -> V_128 > 0 ) {
V_33 -> V_130 = F_33 ( V_118 -> V_130 , V_119 -> V_128 , & V_120 ) ;
if ( V_120 ) {
V_33 -> V_130 ++ ;
V_33 -> V_131 = 1 ;
} else
V_33 -> V_131 = ( V_118 -> V_131 || V_119 -> V_129 ) ;
} else {
V_33 -> V_130 = V_121 ;
V_33 -> V_131 = 0 ;
}
V_33 -> integer = 0 ;
}
void F_48 ( const struct V_123 * V_118 , const struct V_123 * V_119 ,
unsigned int V_133 , struct V_123 * V_33 )
{
unsigned int V_120 ;
if ( V_118 -> V_132 || V_119 -> V_132 ) {
F_42 ( V_33 ) ;
return;
}
V_33 -> V_132 = 0 ;
V_33 -> V_128 = F_37 ( V_118 -> V_128 , V_119 -> V_128 , V_133 , & V_120 ) ;
V_33 -> V_129 = ( V_120 || V_118 -> V_129 || V_119 -> V_129 ) ;
V_33 -> V_130 = F_37 ( V_118 -> V_130 , V_119 -> V_130 , V_133 , & V_120 ) ;
if ( V_120 ) {
V_33 -> V_130 ++ ;
V_33 -> V_131 = 1 ;
} else
V_33 -> V_131 = ( V_118 -> V_131 || V_119 -> V_131 ) ;
V_33 -> integer = 0 ;
}
void F_49 ( const struct V_123 * V_118 , unsigned int V_133 ,
const struct V_123 * V_119 , struct V_123 * V_33 )
{
unsigned int V_120 ;
if ( V_118 -> V_132 || V_119 -> V_132 ) {
F_42 ( V_33 ) ;
return;
}
V_33 -> V_132 = 0 ;
V_33 -> V_128 = F_37 ( V_118 -> V_128 , V_133 , V_119 -> V_130 , & V_120 ) ;
V_33 -> V_129 = ( V_120 || V_118 -> V_129 || V_119 -> V_131 ) ;
if ( V_119 -> V_128 > 0 ) {
V_33 -> V_130 = F_37 ( V_118 -> V_130 , V_133 , V_119 -> V_128 , & V_120 ) ;
if ( V_120 ) {
V_33 -> V_130 ++ ;
V_33 -> V_131 = 1 ;
} else
V_33 -> V_131 = ( V_118 -> V_131 || V_119 -> V_129 ) ;
} else {
V_33 -> V_130 = V_121 ;
V_33 -> V_131 = 0 ;
}
V_33 -> integer = 0 ;
}
int F_50 ( struct V_123 * V_124 ,
unsigned int V_134 , struct V_135 * V_136 ,
unsigned int * V_137 , unsigned int * V_138 )
{
unsigned int V_139 , V_140 ;
int V_141 ;
unsigned int V_133 ;
struct V_123 V_142 ;
int V_28 ;
unsigned int V_143 , V_144 ;
int V_145 ;
V_139 = V_140 = V_141 = 0 ;
for ( V_133 = 0 ; V_133 < V_134 ; ++ V_133 ) {
unsigned int V_146 = V_136 [ V_133 ] . V_146 ;
unsigned int V_147 ;
unsigned int V_122 = V_124 -> V_128 ;
int V_148 ;
if ( V_122 == 0 )
V_122 = 1 ;
V_147 = F_35 ( V_146 , V_122 ) ;
if ( V_147 < V_136 [ V_133 ] . V_149 )
continue;
if ( V_147 > V_136 [ V_133 ] . V_150 )
V_147 = V_136 [ V_133 ] . V_150 ;
else {
unsigned int V_120 ;
V_120 = ( V_147 - V_136 [ V_133 ] . V_149 ) % V_136 [ V_133 ] . V_151 ;
if ( V_120 != 0 )
V_147 -= V_120 ;
}
V_148 = V_146 - V_122 * V_147 ;
if ( V_148 < 0 )
V_148 = - V_148 ;
if ( V_139 == 0 ||
V_148 * V_140 < V_141 * V_147 ) {
V_141 = V_148 ;
V_140 = V_147 ;
V_139 = V_146 ;
}
}
if ( V_140 == 0 ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
V_142 . V_128 = F_34 ( V_139 , V_140 ) ;
V_142 . V_129 = ! ! ( V_139 % V_140 ) ;
V_143 = V_139 ;
V_145 = V_141 ;
V_144 = V_140 ;
V_139 = V_140 = V_141 = 0 ;
for ( V_133 = 0 ; V_133 < V_134 ; ++ V_133 ) {
unsigned int V_146 = V_136 [ V_133 ] . V_146 ;
unsigned int V_147 ;
unsigned int V_122 = V_124 -> V_130 ;
int V_148 ;
if ( V_122 == 0 ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
V_147 = F_34 ( V_146 , V_122 ) ;
if ( V_147 > V_136 [ V_133 ] . V_150 )
continue;
if ( V_147 < V_136 [ V_133 ] . V_149 )
V_147 = V_136 [ V_133 ] . V_149 ;
else {
unsigned int V_120 ;
V_120 = ( V_147 - V_136 [ V_133 ] . V_149 ) % V_136 [ V_133 ] . V_151 ;
if ( V_120 != 0 )
V_147 += V_136 [ V_133 ] . V_151 - V_120 ;
}
V_148 = V_122 * V_147 - V_146 ;
if ( V_148 < 0 )
V_148 = - V_148 ;
if ( V_139 == 0 ||
V_148 * V_140 < V_141 * V_147 ) {
V_141 = V_148 ;
V_140 = V_147 ;
V_139 = V_146 ;
}
}
if ( V_140 == 0 ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
V_142 . V_130 = F_35 ( V_139 , V_140 ) ;
V_142 . V_131 = ! ! ( V_139 % V_140 ) ;
V_142 . integer = 0 ;
V_28 = F_39 ( V_124 , & V_142 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_44 ( V_124 ) ) {
if ( V_141 * V_144 < V_145 * V_140 ) {
V_143 = V_139 ;
V_144 = V_140 ;
}
if ( V_137 )
* V_137 = V_143 ;
if ( V_138 )
* V_138 = V_144 ;
}
return V_28 ;
}
static int F_51 ( struct V_123 * V_124 ,
unsigned int V_134 , struct V_152 * V_136 ,
unsigned int * V_137 , unsigned int * V_138 )
{
unsigned int V_139 , V_141 , V_140 ;
unsigned int V_133 ;
struct V_123 V_142 ;
int V_28 ;
V_139 = V_140 = V_141 = 0 ;
for ( V_133 = 0 ; V_133 < V_134 ; ++ V_133 ) {
unsigned int V_146 ;
unsigned int V_147 = V_136 [ V_133 ] . V_147 ;
unsigned int V_122 = V_124 -> V_128 ;
int V_148 ;
V_146 = F_36 ( V_122 , V_147 ) ;
if ( V_146 > V_136 [ V_133 ] . V_153 )
continue;
if ( V_146 < V_136 [ V_133 ] . V_154 )
V_146 = V_136 [ V_133 ] . V_153 ;
else {
unsigned int V_120 ;
V_120 = ( V_146 - V_136 [ V_133 ] . V_154 ) % V_136 [ V_133 ] . V_155 ;
if ( V_120 != 0 )
V_146 += V_136 [ V_133 ] . V_155 - V_120 ;
}
V_148 = V_146 - V_122 * V_147 ;
if ( V_139 == 0 ||
V_148 * V_140 < V_141 * V_147 ) {
V_141 = V_148 ;
V_140 = V_147 ;
V_139 = V_146 ;
}
}
if ( V_140 == 0 ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
V_142 . V_128 = F_34 ( V_139 , V_140 ) ;
V_142 . V_129 = ! ! ( V_139 % V_140 ) ;
V_139 = V_140 = V_141 = 0 ;
for ( V_133 = 0 ; V_133 < V_134 ; ++ V_133 ) {
unsigned int V_146 ;
unsigned int V_147 = V_136 [ V_133 ] . V_147 ;
unsigned int V_122 = V_124 -> V_130 ;
int V_148 ;
V_146 = F_36 ( V_122 , V_147 ) ;
if ( V_146 < V_136 [ V_133 ] . V_154 )
continue;
if ( V_146 > V_136 [ V_133 ] . V_153 )
V_146 = V_136 [ V_133 ] . V_153 ;
else {
unsigned int V_120 ;
V_120 = ( V_146 - V_136 [ V_133 ] . V_154 ) % V_136 [ V_133 ] . V_155 ;
if ( V_120 != 0 )
V_146 -= V_120 ;
}
V_148 = V_122 * V_147 - V_146 ;
if ( V_139 == 0 ||
V_148 * V_140 < V_141 * V_147 ) {
V_141 = V_148 ;
V_140 = V_147 ;
V_139 = V_146 ;
}
}
if ( V_140 == 0 ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
V_142 . V_130 = F_35 ( V_139 , V_140 ) ;
V_142 . V_131 = ! ! ( V_139 % V_140 ) ;
V_142 . integer = 0 ;
V_28 = F_39 ( V_124 , & V_142 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_44 ( V_124 ) ) {
if ( V_137 )
* V_137 = V_139 ;
if ( V_138 )
* V_138 = V_140 ;
}
return V_28 ;
}
int F_52 ( struct V_123 * V_124 , unsigned int V_156 ,
const unsigned int * V_157 , unsigned int V_158 )
{
unsigned int V_133 ;
struct V_123 V_159 ;
if ( ! V_156 ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
F_53 ( & V_159 ) ;
V_159 . V_128 = V_121 ;
V_159 . V_130 = 0 ;
for ( V_133 = 0 ; V_133 < V_156 ; V_133 ++ ) {
if ( V_158 && ! ( V_158 & ( 1 << V_133 ) ) )
continue;
if ( ! F_54 ( V_124 , V_157 [ V_133 ] ) )
continue;
V_159 . V_128 = V_128 ( V_159 . V_128 , V_157 [ V_133 ] ) ;
V_159 . V_130 = V_130 ( V_159 . V_130 , V_157 [ V_133 ] ) ;
}
return F_39 ( V_124 , & V_159 ) ;
}
static int F_55 ( struct V_123 * V_124 , unsigned int V_128 , unsigned int V_160 )
{
unsigned int V_12 ;
int V_126 = 0 ;
V_12 = ( V_124 -> V_128 - V_128 ) % V_160 ;
if ( V_12 != 0 || V_124 -> V_129 ) {
V_124 -> V_128 += V_160 - V_12 ;
V_126 = 1 ;
}
V_12 = ( V_124 -> V_130 - V_128 ) % V_160 ;
if ( V_12 != 0 || V_124 -> V_131 ) {
V_124 -> V_130 -= V_12 ;
V_126 = 1 ;
}
if ( F_41 ( V_124 ) ) {
V_124 -> V_132 = 1 ;
return - V_127 ;
}
return V_126 ;
}
int F_56 ( struct V_4 * V_5 , unsigned int V_161 ,
int V_162 ,
T_6 V_163 , void * V_164 ,
int V_165 , ... )
{
struct V_166 * V_167 = & V_5 -> V_168 ;
struct V_169 * V_33 ;
unsigned int V_133 ;
T_7 args ;
va_start ( args , V_165 ) ;
if ( V_167 -> V_170 >= V_167 -> V_171 ) {
struct V_169 * V_172 ;
unsigned int V_173 = V_167 -> V_171 + 16 ;
V_172 = F_57 ( V_173 , sizeof( * V_33 ) , V_174 ) ;
if ( ! V_172 ) {
va_end ( args ) ;
return - V_175 ;
}
if ( V_167 -> V_176 ) {
memcpy ( V_172 , V_167 -> V_176 ,
V_167 -> V_170 * sizeof( * V_33 ) ) ;
F_58 ( V_167 -> V_176 ) ;
}
V_167 -> V_176 = V_172 ;
V_167 -> V_171 = V_173 ;
}
V_33 = & V_167 -> V_176 [ V_167 -> V_170 ] ;
V_33 -> V_161 = V_161 ;
V_33 -> V_163 = V_163 ;
V_33 -> V_162 = V_162 ;
V_33 -> V_164 = V_164 ;
V_133 = 0 ;
while ( 1 ) {
if ( F_3 ( V_133 >= F_59 ( V_33 -> V_177 ) ) ) {
va_end ( args ) ;
return - V_127 ;
}
V_33 -> V_177 [ V_133 ++ ] = V_165 ;
if ( V_165 < 0 )
break;
V_165 = va_arg ( args , int ) ;
}
V_167 -> V_170 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_60 ( struct V_4 * V_5 , T_8 V_162 ,
T_9 V_158 )
{
struct V_166 * V_167 = & V_5 -> V_168 ;
struct V_178 * V_179 = F_61 ( V_167 , V_162 ) ;
* V_179 -> V_180 &= V_158 ;
memset ( V_179 -> V_180 + 1 , 0 , ( V_181 - 32 ) / 8 ) ;
if ( * V_179 -> V_180 == 0 )
return - V_127 ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 , T_8 V_162 ,
T_5 V_158 )
{
struct V_166 * V_167 = & V_5 -> V_168 ;
struct V_178 * V_179 = F_61 ( V_167 , V_162 ) ;
V_179 -> V_180 [ 0 ] &= ( T_9 ) V_158 ;
V_179 -> V_180 [ 1 ] &= ( T_9 ) ( V_158 >> 32 ) ;
memset ( V_179 -> V_180 + 2 , 0 , ( V_181 - 64 ) / 8 ) ;
if ( ! V_179 -> V_180 [ 0 ] && ! V_179 -> V_180 [ 1 ] )
return - V_127 ;
return 0 ;
}
int F_63 ( struct V_4 * V_5 , T_8 V_162 )
{
struct V_166 * V_167 = & V_5 -> V_168 ;
return F_64 ( F_65 ( V_167 , V_162 ) ) ;
}
int F_66 ( struct V_4 * V_5 , T_8 V_162 ,
unsigned int V_128 , unsigned int V_130 )
{
struct V_166 * V_167 = & V_5 -> V_168 ;
struct V_123 V_142 ;
V_142 . V_128 = V_128 ;
V_142 . V_130 = V_130 ;
V_142 . V_129 = V_142 . V_131 = 0 ;
V_142 . integer = 0 ;
return F_39 ( F_65 ( V_167 , V_162 ) , & V_142 ) ;
}
static int F_67 ( struct V_182 * V_183 ,
struct V_169 * V_184 )
{
struct V_185 * V_157 = V_184 -> V_164 ;
return F_52 ( F_68 ( V_183 , V_184 -> V_162 ) , V_157 -> V_156 , V_157 -> V_157 , V_157 -> V_158 ) ;
}
int V_185 ( struct V_4 * V_5 ,
unsigned int V_161 ,
T_8 V_162 ,
const struct V_185 * V_186 )
{
return F_56 ( V_5 , V_161 , V_162 ,
F_67 , ( void * ) V_186 ,
V_162 , - 1 ) ;
}
static int F_69 ( struct V_182 * V_183 ,
struct V_169 * V_184 )
{
struct V_187 * V_120 = V_184 -> V_164 ;
unsigned int V_146 = 0 , V_147 = 0 ;
int V_28 ;
V_28 = F_50 ( F_68 ( V_183 , V_184 -> V_162 ) ,
V_120 -> V_188 , V_120 -> V_136 , & V_146 , & V_147 ) ;
if ( V_28 >= 0 && V_147 && V_184 -> V_162 == V_189 ) {
V_183 -> V_190 = V_146 ;
V_183 -> V_191 = V_147 ;
}
return V_28 ;
}
int V_187 ( struct V_4 * V_5 ,
unsigned int V_161 ,
T_8 V_162 ,
struct V_187 * V_120 )
{
return F_56 ( V_5 , V_161 , V_162 ,
F_69 , V_120 ,
V_162 , - 1 ) ;
}
static int F_70 ( struct V_182 * V_183 ,
struct V_169 * V_184 )
{
struct V_192 * V_120 = V_184 -> V_164 ;
unsigned int V_146 = 0 , V_147 = 0 ;
int V_28 = F_51 ( F_68 ( V_183 , V_184 -> V_162 ) ,
V_120 -> V_188 , V_120 -> V_136 , & V_146 , & V_147 ) ;
if ( V_28 >= 0 && V_147 && V_184 -> V_162 == V_189 ) {
V_183 -> V_190 = V_146 ;
V_183 -> V_191 = V_147 ;
}
return V_28 ;
}
int V_192 ( struct V_4 * V_5 ,
unsigned int V_161 ,
T_8 V_162 ,
struct V_192 * V_120 )
{
return F_56 ( V_5 , V_161 , V_162 ,
F_70 , V_120 ,
V_162 , - 1 ) ;
}
static int F_71 ( struct V_182 * V_183 ,
struct V_169 * V_184 )
{
unsigned int V_186 = ( unsigned long ) V_184 -> V_164 ;
int V_193 = V_186 & 0xffff ;
unsigned int V_194 = V_186 >> 16 ;
struct V_123 * V_124 = F_68 ( V_183 , V_195 ) ;
if ( F_44 ( V_124 ) && F_72 ( V_124 ) == V_193 )
V_183 -> V_194 = V_194 ;
return 0 ;
}
int F_73 ( struct V_4 * V_5 ,
unsigned int V_161 ,
unsigned int V_193 ,
unsigned int V_194 )
{
unsigned long V_186 = ( V_194 << 16 ) | V_193 ;
return F_56 ( V_5 , V_161 , - 1 ,
F_71 ,
( void * ) V_186 ,
V_195 , - 1 ) ;
}
static int F_74 ( struct V_182 * V_183 ,
struct V_169 * V_184 )
{
unsigned long V_160 = ( unsigned long ) V_184 -> V_164 ;
return F_55 ( F_68 ( V_183 , V_184 -> V_162 ) , 0 , V_160 ) ;
}
int F_75 ( struct V_4 * V_5 ,
unsigned int V_161 ,
T_8 V_162 ,
unsigned long V_160 )
{
return F_56 ( V_5 , V_161 , V_162 ,
F_74 , ( void * ) V_160 ,
V_162 , - 1 ) ;
}
static int F_76 ( struct V_182 * V_183 , struct V_169 * V_184 )
{
static unsigned int V_196 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_52 ( F_68 ( V_183 , V_184 -> V_162 ) ,
F_59 ( V_196 ) , V_196 , 0 ) ;
}
int F_77 ( struct V_4 * V_5 ,
unsigned int V_161 ,
T_8 V_162 )
{
return F_56 ( V_5 , V_161 , V_162 ,
F_76 , NULL ,
V_162 , - 1 ) ;
}
static int F_78 ( struct V_182 * V_183 ,
struct V_169 * V_184 )
{
unsigned int V_197 = ( unsigned int ) ( V_198 ) V_184 -> V_164 ;
struct V_123 * V_102 ;
V_102 = F_68 ( V_183 , V_189 ) ;
return F_52 ( V_102 , 1 , & V_197 , 0 ) ;
}
int F_79 ( struct V_4 * V_5 ,
unsigned int V_197 )
{
return F_56 ( V_5 , V_199 ,
V_189 ,
F_78 ,
( void * ) ( V_198 ) V_197 ,
V_189 , - 1 ) ;
}
static void F_80 ( struct V_182 * V_183 ,
T_8 V_162 )
{
if ( F_81 ( V_162 ) ) {
F_82 ( F_83 ( V_183 , V_162 ) ) ;
V_183 -> V_200 |= 1 << V_162 ;
V_183 -> V_201 |= 1 << V_162 ;
return;
}
if ( F_84 ( V_162 ) ) {
F_53 ( F_68 ( V_183 , V_162 ) ) ;
V_183 -> V_200 |= 1 << V_162 ;
V_183 -> V_201 |= 1 << V_162 ;
return;
}
F_85 () ;
}
void F_86 ( struct V_182 * V_183 )
{
unsigned int V_133 ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
for ( V_133 = V_202 ; V_133 <= V_203 ; V_133 ++ )
F_80 ( V_183 , V_133 ) ;
for ( V_133 = V_204 ; V_133 <= V_205 ; V_133 ++ )
F_80 ( V_183 , V_133 ) ;
V_183 -> V_86 = ~ 0U ;
}
int F_87 ( const struct V_182 * V_183 ,
T_8 V_162 , int * V_206 )
{
if ( F_81 ( V_162 ) ) {
const struct V_178 * V_158 = F_88 ( V_183 , V_162 ) ;
if ( ! F_89 ( V_158 ) )
return - V_127 ;
if ( V_206 )
* V_206 = 0 ;
return F_90 ( V_158 ) ;
}
if ( F_84 ( V_162 ) ) {
const struct V_123 * V_124 = F_91 ( V_183 , V_162 ) ;
if ( ! F_44 ( V_124 ) )
return - V_127 ;
if ( V_206 )
* V_206 = V_124 -> V_129 ;
return F_72 ( V_124 ) ;
}
return - V_127 ;
}
void F_92 ( struct V_182 * V_183 ,
T_8 V_162 )
{
if ( F_81 ( V_162 ) ) {
F_93 ( F_83 ( V_183 , V_162 ) ) ;
V_183 -> V_200 |= 1 << V_162 ;
V_183 -> V_201 |= 1 << V_162 ;
} else if ( F_84 ( V_162 ) ) {
F_42 ( F_68 ( V_183 , V_162 ) ) ;
V_183 -> V_200 |= 1 << V_162 ;
V_183 -> V_201 |= 1 << V_162 ;
} else {
F_85 () ;
}
}
static int F_94 ( struct V_182 * V_183 ,
T_8 V_162 )
{
int V_126 ;
if ( F_81 ( V_162 ) )
V_126 = F_95 ( F_83 ( V_183 , V_162 ) ) ;
else if ( F_84 ( V_162 ) )
V_126 = F_43 ( F_68 ( V_183 , V_162 ) ) ;
else
return - V_127 ;
if ( V_126 ) {
V_183 -> V_200 |= 1 << V_162 ;
V_183 -> V_201 |= 1 << V_162 ;
}
return V_126 ;
}
int F_96 ( struct V_1 * V_38 ,
struct V_182 * V_183 ,
T_8 V_162 , int * V_206 )
{
int V_126 = F_94 ( V_183 , V_162 ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_183 -> V_201 ) {
int V_28 = F_97 ( V_38 , V_183 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_87 ( V_183 , V_162 , V_206 ) ;
}
static int F_98 ( struct V_182 * V_183 ,
T_8 V_162 )
{
int V_126 ;
if ( F_81 ( V_162 ) )
V_126 = F_99 ( F_83 ( V_183 , V_162 ) ) ;
else if ( F_84 ( V_162 ) )
V_126 = F_45 ( F_68 ( V_183 , V_162 ) ) ;
else
return - V_127 ;
if ( V_126 ) {
V_183 -> V_200 |= 1 << V_162 ;
V_183 -> V_201 |= 1 << V_162 ;
}
return V_126 ;
}
int F_100 ( struct V_1 * V_38 ,
struct V_182 * V_183 ,
T_8 V_162 , int * V_206 )
{
int V_126 = F_98 ( V_183 , V_162 ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_183 -> V_201 ) {
int V_28 = F_97 ( V_38 , V_183 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_87 ( V_183 , V_162 , V_206 ) ;
}
int F_101 ( struct V_1 * V_38 ,
struct V_182 * V_183 )
{
static int V_207 [] = {
V_208 ,
V_209 ,
V_210 ,
V_211 ,
V_189 ,
V_212 ,
V_213 ,
V_214 ,
- 1
} ;
int V_28 , * V_125 ;
for ( V_125 = V_207 ; * V_125 != - 1 ; V_125 ++ ) {
if ( * V_125 != V_213 )
V_28 = F_96 ( V_38 , V_183 , * V_125 , NULL ) ;
else
V_28 = F_100 ( V_38 , V_183 , * V_125 , NULL ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
void * V_215 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_216 ;
F_103 ( V_2 , V_216 ) ;
if ( F_104 ( V_2 ) &&
F_30 ( V_2 ) >= 0 )
V_5 -> V_21 -> V_22 %= V_5 -> V_17 ;
else {
V_5 -> V_21 -> V_22 = 0 ;
V_5 -> V_107 = 0 ;
}
F_105 ( V_2 , V_216 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
void * V_215 )
{
struct V_217 * V_86 = V_215 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_193 ;
if ( ! ( V_5 -> V_86 & V_218 ) ) {
V_86 -> V_219 = - 1 ;
return 0 ;
}
V_193 = F_107 ( V_5 -> V_31 ) ;
if ( V_193 < 0 )
return V_193 ;
V_86 -> V_219 = 0 ;
switch ( V_5 -> V_23 ) {
case V_25 :
case V_24 :
V_86 -> V_220 = V_86 -> V_221 * V_193 ;
V_86 -> V_160 = V_5 -> V_32 * V_193 ;
break;
case V_222 :
case V_223 :
{
T_3 V_224 = V_5 -> V_35 / V_5 -> V_32 ;
V_86 -> V_220 = V_86 -> V_221 * V_224 * 8 ;
V_86 -> V_160 = V_193 ;
break;
}
default:
F_85 () ;
break;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
void * V_215 )
{
struct V_182 * V_183 = V_215 ;
T_10 V_31 ;
int V_32 , V_193 ;
V_183 -> V_225 = V_2 -> V_5 -> V_85 . V_225 ;
if ( ! ( V_2 -> V_5 -> V_85 . V_86 & V_226 ) ) {
V_31 = F_109 ( V_183 ) ;
V_32 = F_110 ( V_183 ) ;
V_193 = F_107 ( V_31 ) ;
V_183 -> V_225 /= V_193 * V_32 ;
}
return 0 ;
}
int F_111 ( struct V_1 * V_2 ,
unsigned int V_227 , void * V_215 )
{
switch ( V_227 ) {
case V_228 :
return 0 ;
case V_229 :
return F_102 ( V_2 , V_215 ) ;
case V_230 :
return F_106 ( V_2 , V_215 ) ;
case V_231 :
return F_108 ( V_2 , V_215 ) ;
}
return - V_232 ;
}
void F_112 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_216 ;
if ( F_113 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_233 )
V_5 -> V_233 ( V_2 ) ;
F_103 ( V_2 , V_216 ) ;
if ( ! F_104 ( V_2 ) ||
F_23 ( V_2 , 1 ) < 0 )
goto V_234;
if ( V_2 -> V_235 )
F_114 ( V_2 -> V_236 , 1 ) ;
V_234:
F_105 ( V_2 , V_216 ) ;
if ( V_5 -> V_237 )
V_5 -> V_237 ( V_2 ) ;
F_115 ( & V_5 -> V_238 , V_239 , V_240 ) ;
}
static int F_116 ( struct V_1 * V_2 ,
T_1 * V_241 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_242 = V_2 -> V_42 == V_66 ;
T_11 V_243 ;
int V_28 = 0 ;
T_1 V_20 = 0 ;
long V_244 , V_245 ;
F_117 ( & V_243 , V_246 ) ;
F_118 ( V_247 ) ;
F_119 ( & V_5 -> V_73 , & V_243 ) ;
if ( V_5 -> V_98 )
V_244 = V_248 ;
else {
V_244 = 10 ;
if ( V_5 -> V_102 ) {
long V_142 = V_5 -> V_61 * 2 / V_5 -> V_102 ;
V_244 = V_130 ( V_142 , V_244 ) ;
}
V_244 = F_120 ( V_244 * 1000 ) ;
}
for (; ; ) {
if ( F_121 ( V_246 ) ) {
V_28 = - V_249 ;
break;
}
if ( V_242 )
V_20 = F_19 ( V_5 ) ;
else
V_20 = F_20 ( V_5 ) ;
if ( V_20 >= V_5 -> V_72 )
break;
F_122 ( V_2 ) ;
V_245 = F_123 ( V_244 ) ;
F_124 ( V_2 ) ;
F_118 ( V_247 ) ;
switch ( V_5 -> V_21 -> V_68 ) {
case V_250 :
V_28 = - V_251 ;
goto V_252;
case V_47 :
V_28 = - V_70 ;
goto V_252;
case V_69 :
if ( V_242 )
V_28 = - V_70 ;
else
V_20 = 0 ;
goto V_252;
case V_253 :
case V_254 :
case V_255 :
V_28 = - V_256 ;
goto V_252;
case V_257 :
continue;
}
if ( ! V_245 ) {
F_26 ( V_2 -> V_38 ,
L_20 ,
V_242 ? L_21 : L_22 ) ;
V_28 = - V_258 ;
break;
}
}
V_252:
F_118 ( V_259 ) ;
F_125 ( & V_5 -> V_73 , & V_243 ) ;
* V_241 = V_20 ;
return V_28 ;
}
static int F_126 ( struct V_1 * V_2 ,
unsigned int V_260 ,
unsigned long V_261 , unsigned int V_262 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_12 * V_263 = ( char T_12 * ) V_261 + F_4 ( V_5 , V_262 ) ;
if ( V_2 -> V_26 -> V_264 ) {
if ( ( V_28 = V_2 -> V_26 -> V_264 ( V_2 , - 1 , V_260 , V_263 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_260 ) ;
if ( F_127 ( V_29 , V_263 , F_4 ( V_5 , V_6 ) ) )
return - V_265 ;
}
return 0 ;
}
static T_2 F_128 ( struct V_1 * V_2 ,
unsigned long V_261 ,
T_1 V_224 ,
int V_266 ,
T_13 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_267 = 0 ;
T_1 V_219 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_224 == 0 )
return 0 ;
F_124 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_68 ) {
case V_268 :
case V_269 :
case V_257 :
break;
case V_47 :
V_28 = - V_70 ;
goto V_270;
case V_250 :
V_28 = - V_251 ;
goto V_270;
default:
V_28 = - V_256 ;
goto V_270;
}
V_5 -> V_72 = V_5 -> V_14 -> V_74 ? : 1 ;
if ( V_5 -> V_21 -> V_68 == V_269 )
F_30 ( V_2 ) ;
V_20 = F_19 ( V_5 ) ;
while ( V_224 > 0 ) {
T_1 V_6 , V_15 , V_271 ;
T_1 V_272 ;
if ( ! V_20 ) {
if ( V_266 ) {
V_28 = - V_273 ;
goto V_270;
}
V_5 -> V_72 = F_129 ( T_1 , V_224 ,
V_5 -> V_14 -> V_74 ? : 1 ) ;
V_28 = F_116 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_270;
}
V_6 = V_224 > V_20 ? V_20 : V_224 ;
V_272 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_272 )
V_6 = V_272 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_72 = 0 ;
F_122 ( V_2 ) ;
return - V_127 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_271 = V_15 % V_5 -> V_17 ;
F_122 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_271 , V_261 , V_219 , V_6 ) ;
F_124 ( V_2 ) ;
if ( V_28 < 0 )
goto V_270;
switch ( V_5 -> V_21 -> V_68 ) {
case V_47 :
V_28 = - V_70 ;
goto V_270;
case V_250 :
V_28 = - V_251 ;
goto V_270;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_274 )
V_2 -> V_26 -> V_274 ( V_2 ) ;
V_219 += V_6 ;
V_224 -= V_6 ;
V_267 += V_6 ;
V_20 -= V_6 ;
if ( V_5 -> V_21 -> V_68 == V_268 &&
F_2 ( V_5 ) >= ( T_2 ) V_5 -> V_275 ) {
V_28 = F_130 ( V_2 ) ;
if ( V_28 < 0 )
goto V_270;
}
}
V_270:
V_5 -> V_72 = 0 ;
if ( V_267 > 0 && V_28 >= 0 )
F_18 ( V_2 , V_5 ) ;
F_122 ( V_2 ) ;
return V_267 > 0 ? ( T_2 ) V_267 : V_28 ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_113 ( V_2 ) )
return - V_232 ;
V_5 = V_2 -> V_5 ;
if ( F_3 ( ! V_2 -> V_26 -> V_264 && ! V_5 -> V_30 ) )
return - V_127 ;
if ( V_5 -> V_21 -> V_68 == V_253 )
return - V_256 ;
return 0 ;
}
T_2 F_132 ( struct V_1 * V_2 , const void T_12 * V_263 , T_1 V_224 )
{
struct V_4 * V_5 ;
int V_266 ;
int V_28 ;
V_28 = F_131 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_266 = ! ! ( V_2 -> V_276 & V_277 ) ;
if ( V_5 -> V_23 != V_24 &&
V_5 -> V_32 > 1 )
return - V_127 ;
return F_128 ( V_2 , ( unsigned long ) V_263 , V_224 , V_266 ,
F_126 ) ;
}
static int F_133 ( struct V_1 * V_2 ,
unsigned int V_260 ,
unsigned long V_261 , unsigned int V_262 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_12 * * V_278 = ( void T_12 * * ) V_261 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_264 ) {
if ( F_3 ( ! V_2 -> V_26 -> V_27 ) )
return - V_127 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_278 ) {
if ( * V_278 == NULL ) {
if ( ( V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_260 , V_6 ) ) < 0 )
return V_28 ;
} else {
char T_12 * V_263 = * V_278 + F_6 ( V_5 , V_262 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_264 ( V_2 , V_33 , V_260 , V_263 , V_6 ) ) < 0 )
return V_28 ;
}
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_278 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_260 ) ;
if ( * V_278 == NULL ) {
F_5 ( V_5 -> V_31 , V_29 , V_6 ) ;
} else {
char T_12 * V_263 = * V_278 + F_6 ( V_5 , V_262 ) ;
if ( F_127 ( V_29 , V_263 , F_6 ( V_5 , V_6 ) ) )
return - V_265 ;
}
}
}
return 0 ;
}
T_2 F_134 ( struct V_1 * V_2 ,
void T_12 * * V_278 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_266 ;
int V_28 ;
V_28 = F_131 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_266 = ! ! ( V_2 -> V_276 & V_277 ) ;
if ( V_5 -> V_23 != V_223 )
return - V_127 ;
return F_128 ( V_2 , ( unsigned long ) V_278 , V_6 ,
V_266 , F_133 ) ;
}
static int F_135 ( struct V_1 * V_2 ,
unsigned int V_260 ,
unsigned long V_261 , unsigned int V_262 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_12 * V_263 = ( char T_12 * ) V_261 + F_4 ( V_5 , V_262 ) ;
if ( V_2 -> V_26 -> V_264 ) {
if ( ( V_28 = V_2 -> V_26 -> V_264 ( V_2 , - 1 , V_260 , V_263 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_260 ) ;
if ( F_136 ( V_263 , V_29 , F_4 ( V_5 , V_6 ) ) )
return - V_265 ;
}
return 0 ;
}
static T_2 F_137 ( struct V_1 * V_2 ,
unsigned long V_261 ,
T_1 V_224 ,
int V_266 ,
T_13 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_267 = 0 ;
T_1 V_219 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_224 == 0 )
return 0 ;
F_124 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_68 ) {
case V_268 :
if ( V_224 >= V_5 -> V_275 ) {
V_28 = F_130 ( V_2 ) ;
if ( V_28 < 0 )
goto V_270;
}
break;
case V_69 :
case V_269 :
case V_257 :
break;
case V_47 :
V_28 = - V_70 ;
goto V_270;
case V_250 :
V_28 = - V_251 ;
goto V_270;
default:
V_28 = - V_256 ;
goto V_270;
}
V_5 -> V_72 = V_5 -> V_14 -> V_74 ? : 1 ;
if ( V_5 -> V_21 -> V_68 == V_269 )
F_30 ( V_2 ) ;
V_20 = F_20 ( V_5 ) ;
while ( V_224 > 0 ) {
T_1 V_6 , V_15 , V_271 ;
T_1 V_272 ;
if ( ! V_20 ) {
if ( V_5 -> V_21 -> V_68 ==
V_69 ) {
F_10 ( V_2 , V_254 ) ;
goto V_270;
}
if ( V_266 ) {
V_28 = - V_273 ;
goto V_270;
}
V_5 -> V_72 = F_129 ( T_1 , V_224 ,
V_5 -> V_14 -> V_74 ? : 1 ) ;
V_28 = F_116 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_270;
if ( ! V_20 )
continue;
}
V_6 = V_224 > V_20 ? V_20 : V_224 ;
V_272 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_272 )
V_6 = V_272 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_72 = 0 ;
F_122 ( V_2 ) ;
return - V_127 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_271 = V_15 % V_5 -> V_17 ;
F_122 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_271 , V_261 , V_219 , V_6 ) ;
F_124 ( V_2 ) ;
if ( V_28 < 0 )
goto V_270;
switch ( V_5 -> V_21 -> V_68 ) {
case V_47 :
V_28 = - V_70 ;
goto V_270;
case V_250 :
V_28 = - V_251 ;
goto V_270;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_274 )
V_2 -> V_26 -> V_274 ( V_2 ) ;
V_219 += V_6 ;
V_224 -= V_6 ;
V_267 += V_6 ;
V_20 -= V_6 ;
}
V_270:
V_5 -> V_72 = 0 ;
if ( V_267 > 0 && V_28 >= 0 )
F_18 ( V_2 , V_5 ) ;
F_122 ( V_2 ) ;
return V_267 > 0 ? ( T_2 ) V_267 : V_28 ;
}
T_2 F_138 ( struct V_1 * V_2 , void T_12 * V_263 , T_1 V_224 )
{
struct V_4 * V_5 ;
int V_266 ;
int V_28 ;
V_28 = F_131 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_266 = ! ! ( V_2 -> V_276 & V_277 ) ;
if ( V_5 -> V_23 != V_24 )
return - V_127 ;
return F_137 ( V_2 , ( unsigned long ) V_263 , V_224 , V_266 , F_135 ) ;
}
static int F_139 ( struct V_1 * V_2 ,
unsigned int V_260 ,
unsigned long V_261 , unsigned int V_262 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_12 * * V_278 = ( void T_12 * * ) V_261 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_264 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_278 ) {
char T_12 * V_263 ;
if ( * V_278 == NULL )
continue;
V_263 = * V_278 + F_6 ( V_5 , V_262 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_264 ( V_2 , V_33 , V_260 , V_263 , V_6 ) ) < 0 )
return V_28 ;
}
} else {
T_1 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_278 ) {
char * V_29 ;
char T_12 * V_263 ;
if ( * V_278 == NULL )
continue;
V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_260 ) ;
V_263 = * V_278 + F_6 ( V_5 , V_262 ) ;
if ( F_136 ( V_263 , V_29 , F_6 ( V_5 , V_6 ) ) )
return - V_265 ;
}
}
return 0 ;
}
T_2 F_140 ( struct V_1 * V_2 ,
void T_12 * * V_278 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_266 ;
int V_28 ;
V_28 = F_131 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 -> V_68 == V_253 )
return - V_256 ;
V_266 = ! ! ( V_2 -> V_276 & V_277 ) ;
if ( V_5 -> V_23 != V_223 )
return - V_127 ;
return F_137 ( V_2 , ( unsigned long ) V_278 , V_6 , V_266 , F_139 ) ;
}
static bool F_141 ( const struct V_279 * V_86 , int V_280 )
{
if ( V_280 > V_86 -> V_281 )
return false ;
return ! V_86 -> V_282 || ( V_86 -> V_282 & ( 1U << V_280 ) ) ;
}
static int F_142 ( struct V_283 * V_284 ,
struct V_285 * V_286 )
{
struct V_279 * V_86 = F_143 ( V_284 ) ;
V_286 -> type = V_287 ;
V_286 -> V_156 = 0 ;
V_286 -> V_156 = V_86 -> V_281 ;
V_286 -> V_288 . integer . V_128 = 0 ;
V_286 -> V_288 . integer . V_130 = V_289 ;
return 0 ;
}
static int F_144 ( struct V_283 * V_284 ,
struct V_290 * V_291 )
{
struct V_279 * V_86 = F_143 ( V_284 ) ;
unsigned int V_59 = F_145 ( V_284 , & V_291 -> V_292 ) ;
struct V_1 * V_2 ;
const struct V_293 * V_294 ;
if ( F_3 ( ! V_86 -> V_295 ) )
return - V_127 ;
V_2 = F_146 ( V_86 , V_59 ) ;
if ( ! V_2 )
return - V_296 ;
memset ( V_291 -> V_288 . integer . V_288 , 0 ,
sizeof( V_291 -> V_288 . integer . V_288 ) ) ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_294 = V_86 -> V_295 ; V_294 -> V_32 ; V_294 ++ ) {
int V_124 ;
if ( V_294 -> V_32 == V_2 -> V_5 -> V_32 &&
F_141 ( V_86 , V_294 -> V_32 ) ) {
for ( V_124 = 0 ; V_124 < V_294 -> V_32 ; V_124 ++ )
V_291 -> V_288 . integer . V_288 [ V_124 ] = V_294 -> V_294 [ V_124 ] ;
return 0 ;
}
}
return - V_127 ;
}
static int F_147 ( struct V_283 * V_284 , int V_297 ,
unsigned int V_224 , unsigned int T_12 * V_298 )
{
struct V_279 * V_86 = F_143 ( V_284 ) ;
const struct V_293 * V_294 ;
unsigned int T_12 * V_299 ;
int V_33 , V_156 = 0 ;
if ( F_3 ( ! V_86 -> V_295 ) )
return - V_127 ;
if ( V_224 < 8 )
return - V_175 ;
if ( F_148 ( V_300 , V_298 ) )
return - V_265 ;
V_224 -= 8 ;
V_299 = V_298 + 2 ;
for ( V_294 = V_86 -> V_295 ; V_294 -> V_32 ; V_294 ++ ) {
int V_301 = V_294 -> V_32 * 4 ;
if ( ! F_141 ( V_86 , V_294 -> V_32 ) )
continue;
if ( V_224 < 8 )
return - V_175 ;
if ( F_148 ( V_302 , V_299 ) ||
F_148 ( V_301 , V_299 + 1 ) )
return - V_265 ;
V_299 += 2 ;
V_224 -= 8 ;
V_156 += 8 ;
if ( V_224 < V_301 )
return - V_175 ;
V_224 -= V_301 ;
V_156 += V_301 ;
for ( V_33 = 0 ; V_33 < V_294 -> V_32 ; V_33 ++ ) {
if ( F_148 ( V_294 -> V_294 [ V_33 ] , V_299 ) )
return - V_265 ;
V_299 ++ ;
}
}
if ( F_148 ( V_156 , V_298 + 1 ) )
return - V_265 ;
return 0 ;
}
static void F_149 ( struct V_283 * V_284 )
{
struct V_279 * V_86 = F_143 ( V_284 ) ;
V_86 -> V_38 -> V_114 [ V_86 -> V_42 ] . V_303 = NULL ;
F_58 ( V_86 ) ;
}
int F_150 ( struct V_110 * V_38 , int V_42 ,
const struct V_293 * V_295 ,
int V_281 ,
unsigned long V_304 ,
struct V_279 * * V_305 )
{
struct V_279 * V_86 ;
struct V_306 V_307 = {
. V_308 = V_309 ,
. V_23 = V_310 |
V_311 |
V_312 ,
. V_86 = F_142 ,
. V_313 = F_144 ,
. V_298 . V_33 = F_147 ,
} ;
int V_28 ;
V_86 = F_15 ( sizeof( * V_86 ) , V_174 ) ;
if ( ! V_86 )
return - V_175 ;
V_86 -> V_38 = V_38 ;
V_86 -> V_42 = V_42 ;
V_86 -> V_295 = V_295 ;
V_86 -> V_281 = V_281 ;
if ( V_42 == V_66 )
V_307 . V_36 = L_23 ;
else
V_307 . V_36 = L_24 ;
V_307 . V_41 = V_38 -> V_41 ;
V_307 . V_156 = V_38 -> V_114 [ V_42 ] . V_314 ;
V_307 . V_304 = V_304 ;
V_86 -> V_315 = F_151 ( & V_307 , V_86 ) ;
if ( ! V_86 -> V_315 ) {
F_58 ( V_86 ) ;
return - V_175 ;
}
V_86 -> V_315 -> V_316 = F_149 ;
V_28 = F_152 ( V_38 -> V_39 , V_86 -> V_315 ) ;
if ( V_28 < 0 )
return V_28 ;
V_38 -> V_114 [ V_42 ] . V_303 = V_86 -> V_315 ;
if ( V_305 )
* V_305 = V_86 ;
return 0 ;
}
