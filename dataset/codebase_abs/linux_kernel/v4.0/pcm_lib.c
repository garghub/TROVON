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
static int F_20 ( struct V_1 * V_2 ,
unsigned int V_59 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_60 ;
T_1 V_61 , V_3 , V_62 ;
T_2 V_63 , V_64 ;
unsigned long V_65 ;
unsigned long V_66 ;
struct V_45 V_67 ;
struct V_45 V_68 ;
int V_69 = 0 ;
V_61 = V_5 -> V_21 -> V_22 ;
V_60 = V_2 -> V_26 -> V_70 ( V_2 ) ;
V_66 = V_71 ;
if ( V_5 -> V_43 == V_44 ) {
F_10 ( V_5 , (struct V_45 * ) & V_67 ) ;
if ( ( V_5 -> V_72 . V_73 & V_74 ) &&
( V_2 -> V_26 -> V_75 ) )
V_2 -> V_26 -> V_75 ( V_2 , & V_68 ) ;
}
if ( V_60 == V_76 ) {
F_8 ( V_2 ) ;
return - V_53 ;
}
if ( V_60 >= V_5 -> V_17 ) {
if ( F_21 () ) {
char V_36 [ 16 ] ;
F_7 ( V_2 , V_36 , sizeof( V_36 ) ) ;
F_22 ( V_2 -> V_38 ,
L_3 ,
V_36 , V_60 , V_5 -> V_17 ,
V_5 -> V_77 ) ;
}
V_60 = 0 ;
}
V_60 -= V_60 % V_5 -> V_78 ;
F_23 ( V_2 , V_60 , V_59 ) ;
V_62 = V_5 -> V_79 ;
V_3 = V_62 + V_60 ;
if ( V_59 ) {
V_64 = V_5 -> V_80 + V_5 -> V_77 ;
if ( V_64 > V_3 ) {
V_63 = V_66 - V_5 -> V_81 ;
if ( V_63 > V_5 -> V_82 / 2 ) {
V_62 += V_5 -> V_17 ;
if ( V_62 >= V_5 -> V_10 ) {
V_62 = 0 ;
V_69 ++ ;
}
V_3 = V_62 + V_60 ;
goto V_83;
}
}
}
if ( V_3 < V_61 ) {
V_62 += V_5 -> V_17 ;
if ( V_62 >= V_5 -> V_10 ) {
V_62 = 0 ;
V_69 ++ ;
}
V_3 = V_62 + V_60 ;
}
V_83:
V_64 = V_3 - V_61 ;
if ( V_64 < 0 )
V_64 += V_5 -> V_10 ;
if ( V_5 -> V_84 ) {
T_2 V_85 ;
V_65 = V_66 - V_5 -> V_81 ;
if ( V_65 < V_5 -> V_82 / 2 )
goto V_86;
V_63 = V_65 - V_64 * V_87 / V_5 -> V_88 ;
V_85 = V_5 -> V_82 / 2 + 1 ;
while ( V_63 > V_85 ) {
V_64 += V_5 -> V_17 ;
V_62 += V_5 -> V_17 ;
if ( V_62 >= V_5 -> V_10 ) {
V_62 = 0 ;
V_69 ++ ;
}
V_3 = V_62 + V_60 ;
V_63 -= V_5 -> V_82 ;
}
goto V_86;
}
if ( V_64 >= V_5 -> V_17 + V_5 -> V_77 ) {
F_24 ( V_2 , V_59 , L_4 ,
L_5 ,
V_2 -> V_42 , ( long ) V_60 ,
( long ) V_3 , ( long ) V_61 ) ;
return 0 ;
}
if ( ! F_12 ( V_2 , V_89 ) )
goto V_90;
if ( V_5 -> V_72 . V_73 & V_91 )
goto V_90;
V_63 = V_64 ;
if ( V_63 < V_5 -> V_92 )
goto V_90;
V_63 -= V_5 -> V_92 ;
V_65 = V_66 - V_5 -> V_81 ;
if ( ( ( V_63 * V_87 ) / V_5 -> V_88 ) > V_65 + V_87 / 100 ) {
V_64 = V_65 /
( ( ( V_5 -> V_77 * V_87 ) / V_5 -> V_88 )
+ V_87 / 100 ) ;
V_3 = V_61 ;
V_62 = V_64 ;
while ( V_64 > 0 ) {
V_3 += V_5 -> V_77 ;
if ( V_3 >= V_5 -> V_10 ) {
V_3 -= V_5 -> V_10 ;
V_69 -- ;
}
V_64 -- ;
}
F_24 ( V_2 , V_59 , L_6 ,
L_7 ,
( long ) V_60 , ( long ) V_63 ,
( long ) V_5 -> V_77 , V_65 ,
( ( V_63 * V_87 ) / V_5 -> V_88 ) , V_62 ,
( unsigned long ) V_61 ,
( unsigned long ) V_3 ) ;
V_64 = 0 ;
V_62 = V_3 - ( V_3 % V_5 -> V_17 ) ;
}
V_90:
if ( V_64 > V_5 -> V_77 + V_5 -> V_77 / 2 ) {
F_24 ( V_2 , V_59 ,
L_8 ,
L_9 ,
V_2 -> V_42 , ( long ) V_64 ,
( long ) V_3 ,
( long ) V_61 ) ;
}
V_86:
if ( V_5 -> V_21 -> V_22 == V_3 )
return 0 ;
if ( V_2 -> V_42 == V_49 &&
V_5 -> V_9 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_59 ) {
V_64 = V_3 - V_5 -> V_80 ;
if ( V_64 < 0 )
V_64 += V_5 -> V_10 ;
V_64 -= ( T_1 ) V_64 % V_5 -> V_77 ;
V_5 -> V_80 += V_64 ;
if ( V_5 -> V_80 >= V_5 -> V_10 )
V_5 -> V_80 -= V_5 -> V_10 ;
}
V_5 -> V_79 = V_62 ;
V_5 -> V_21 -> V_22 = V_3 ;
V_5 -> V_81 = V_66 ;
if ( V_69 ) {
F_3 ( V_69 != 1 ) ;
V_5 -> V_93 += V_5 -> V_10 ;
}
if ( V_5 -> V_43 == V_44 ) {
V_5 -> V_21 -> V_46 = V_67 ;
if ( ! ( V_5 -> V_72 . V_73 & V_74 ) ) {
T_4 V_94 , V_95 ;
if ( V_2 -> V_42 == V_49 )
V_94 = V_5 -> V_93
+ V_5 -> V_21 -> V_22
- V_5 -> V_92 ;
else
V_94 = V_5 -> V_93
+ V_5 -> V_21 -> V_22
+ V_5 -> V_92 ;
V_95 = F_25 ( V_94 * 1000000000LL ,
V_5 -> V_88 ) ;
V_68 = F_26 ( V_95 ) ;
}
V_5 -> V_21 -> V_68 = V_68 ;
}
return F_15 ( V_2 , V_5 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , 0 ) ;
}
void F_28 ( struct V_96 * V_38 , int V_97 ,
const struct V_98 * V_26 )
{
struct V_99 * V_42 = & V_38 -> V_100 [ V_97 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_42 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_101 )
V_2 -> V_26 = V_26 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_102 . V_103 [ 0 ] = V_2 -> V_38 -> V_39 -> V_40 ;
V_5 -> V_102 . V_103 [ 1 ] = - 1 ;
V_5 -> V_102 . V_103 [ 2 ] = - 1 ;
V_5 -> V_102 . V_103 [ 3 ] = - 1 ;
}
static inline unsigned int F_30 ( unsigned int V_104 , unsigned int V_105 ,
unsigned int * V_106 )
{
if ( V_105 == 0 ) {
* V_106 = 0 ;
return V_107 ;
}
* V_106 = V_104 % V_105 ;
return V_104 / V_105 ;
}
static inline unsigned int F_31 ( unsigned int V_104 , unsigned int V_105 )
{
if ( V_105 == 0 )
return V_107 ;
return V_104 / V_105 ;
}
static inline unsigned int F_32 ( unsigned int V_104 , unsigned int V_105 )
{
unsigned int V_106 ;
unsigned int V_108 ;
if ( V_105 == 0 )
return V_107 ;
V_108 = F_30 ( V_104 , V_105 , & V_106 ) ;
if ( V_106 )
++ V_108 ;
return V_108 ;
}
static inline unsigned int F_33 ( unsigned int V_104 , unsigned int V_105 )
{
if ( V_104 == 0 )
return 0 ;
if ( F_31 ( V_107 , V_104 ) < V_105 )
return V_107 ;
return V_104 * V_105 ;
}
static inline unsigned int F_34 ( unsigned int V_104 , unsigned int V_105 ,
unsigned int V_33 , unsigned int * V_106 )
{
T_5 V_12 = ( T_5 ) V_104 * V_105 ;
if ( V_33 == 0 ) {
F_3 ( ! V_12 ) ;
* V_106 = 0 ;
return V_107 ;
}
V_12 = F_35 ( V_12 , V_33 , V_106 ) ;
if ( V_12 >= V_107 ) {
* V_106 = 0 ;
return V_107 ;
}
return V_12 ;
}
int F_36 ( struct V_109 * V_110 , const struct V_109 * V_111 )
{
int V_112 = 0 ;
if ( F_3 ( F_37 ( V_110 ) ) )
return - V_113 ;
if ( V_110 -> V_114 < V_111 -> V_114 ) {
V_110 -> V_114 = V_111 -> V_114 ;
V_110 -> V_115 = V_111 -> V_115 ;
V_112 = 1 ;
} else if ( V_110 -> V_114 == V_111 -> V_114 && ! V_110 -> V_115 && V_111 -> V_115 ) {
V_110 -> V_115 = 1 ;
V_112 = 1 ;
}
if ( V_110 -> V_116 > V_111 -> V_116 ) {
V_110 -> V_116 = V_111 -> V_116 ;
V_110 -> V_117 = V_111 -> V_117 ;
V_112 = 1 ;
} else if ( V_110 -> V_116 == V_111 -> V_116 && ! V_110 -> V_117 && V_111 -> V_117 ) {
V_110 -> V_117 = 1 ;
V_112 = 1 ;
}
if ( ! V_110 -> integer && V_111 -> integer ) {
V_110 -> integer = 1 ;
V_112 = 1 ;
}
if ( V_110 -> integer ) {
if ( V_110 -> V_115 ) {
V_110 -> V_114 ++ ;
V_110 -> V_115 = 0 ;
}
if ( V_110 -> V_117 ) {
V_110 -> V_116 -- ;
V_110 -> V_117 = 0 ;
}
} else if ( ! V_110 -> V_115 && ! V_110 -> V_117 && V_110 -> V_114 == V_110 -> V_116 )
V_110 -> integer = 1 ;
if ( F_38 ( V_110 ) ) {
F_39 ( V_110 ) ;
return - V_113 ;
}
return V_112 ;
}
static int F_40 ( struct V_109 * V_110 )
{
if ( F_3 ( F_37 ( V_110 ) ) )
return - V_113 ;
if ( F_41 ( V_110 ) )
return 0 ;
V_110 -> V_116 = V_110 -> V_114 ;
V_110 -> V_117 = V_110 -> V_115 ;
if ( V_110 -> V_117 )
V_110 -> V_116 ++ ;
return 1 ;
}
static int F_42 ( struct V_109 * V_110 )
{
if ( F_3 ( F_37 ( V_110 ) ) )
return - V_113 ;
if ( F_41 ( V_110 ) )
return 0 ;
V_110 -> V_114 = V_110 -> V_116 ;
V_110 -> V_115 = V_110 -> V_117 ;
if ( V_110 -> V_115 )
V_110 -> V_114 -- ;
return 1 ;
}
void F_43 ( const struct V_109 * V_104 , const struct V_109 * V_105 , struct V_109 * V_33 )
{
if ( V_104 -> V_118 || V_105 -> V_118 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_118 = 0 ;
V_33 -> V_114 = F_33 ( V_104 -> V_114 , V_105 -> V_114 ) ;
V_33 -> V_115 = ( V_104 -> V_115 || V_105 -> V_115 ) ;
V_33 -> V_116 = F_33 ( V_104 -> V_116 , V_105 -> V_116 ) ;
V_33 -> V_117 = ( V_104 -> V_117 || V_105 -> V_117 ) ;
V_33 -> integer = ( V_104 -> integer && V_105 -> integer ) ;
}
void F_44 ( const struct V_109 * V_104 , const struct V_109 * V_105 , struct V_109 * V_33 )
{
unsigned int V_106 ;
if ( V_104 -> V_118 || V_105 -> V_118 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_118 = 0 ;
V_33 -> V_114 = F_30 ( V_104 -> V_114 , V_105 -> V_116 , & V_106 ) ;
V_33 -> V_115 = ( V_106 || V_104 -> V_115 || V_105 -> V_117 ) ;
if ( V_105 -> V_114 > 0 ) {
V_33 -> V_116 = F_30 ( V_104 -> V_116 , V_105 -> V_114 , & V_106 ) ;
if ( V_106 ) {
V_33 -> V_116 ++ ;
V_33 -> V_117 = 1 ;
} else
V_33 -> V_117 = ( V_104 -> V_117 || V_105 -> V_115 ) ;
} else {
V_33 -> V_116 = V_107 ;
V_33 -> V_117 = 0 ;
}
V_33 -> integer = 0 ;
}
void F_45 ( const struct V_109 * V_104 , const struct V_109 * V_105 ,
unsigned int V_119 , struct V_109 * V_33 )
{
unsigned int V_106 ;
if ( V_104 -> V_118 || V_105 -> V_118 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_118 = 0 ;
V_33 -> V_114 = F_34 ( V_104 -> V_114 , V_105 -> V_114 , V_119 , & V_106 ) ;
V_33 -> V_115 = ( V_106 || V_104 -> V_115 || V_105 -> V_115 ) ;
V_33 -> V_116 = F_34 ( V_104 -> V_116 , V_105 -> V_116 , V_119 , & V_106 ) ;
if ( V_106 ) {
V_33 -> V_116 ++ ;
V_33 -> V_117 = 1 ;
} else
V_33 -> V_117 = ( V_104 -> V_117 || V_105 -> V_117 ) ;
V_33 -> integer = 0 ;
}
void F_46 ( const struct V_109 * V_104 , unsigned int V_119 ,
const struct V_109 * V_105 , struct V_109 * V_33 )
{
unsigned int V_106 ;
if ( V_104 -> V_118 || V_105 -> V_118 ) {
F_39 ( V_33 ) ;
return;
}
V_33 -> V_118 = 0 ;
V_33 -> V_114 = F_34 ( V_104 -> V_114 , V_119 , V_105 -> V_116 , & V_106 ) ;
V_33 -> V_115 = ( V_106 || V_104 -> V_115 || V_105 -> V_117 ) ;
if ( V_105 -> V_114 > 0 ) {
V_33 -> V_116 = F_34 ( V_104 -> V_116 , V_119 , V_105 -> V_114 , & V_106 ) ;
if ( V_106 ) {
V_33 -> V_116 ++ ;
V_33 -> V_117 = 1 ;
} else
V_33 -> V_117 = ( V_104 -> V_117 || V_105 -> V_115 ) ;
} else {
V_33 -> V_116 = V_107 ;
V_33 -> V_117 = 0 ;
}
V_33 -> integer = 0 ;
}
int F_47 ( struct V_109 * V_110 ,
unsigned int V_120 , struct V_121 * V_122 ,
unsigned int * V_123 , unsigned int * V_124 )
{
unsigned int V_125 , V_126 ;
int V_127 ;
unsigned int V_119 ;
struct V_109 V_128 ;
int V_28 ;
unsigned int V_129 , V_130 ;
int V_131 ;
V_125 = V_126 = V_127 = 0 ;
for ( V_119 = 0 ; V_119 < V_120 ; ++ V_119 ) {
unsigned int V_132 = V_122 [ V_119 ] . V_132 ;
unsigned int V_133 ;
unsigned int V_108 = V_110 -> V_114 ;
int V_134 ;
if ( V_108 == 0 )
V_108 = 1 ;
V_133 = F_32 ( V_132 , V_108 ) ;
if ( V_133 < V_122 [ V_119 ] . V_135 )
continue;
if ( V_133 > V_122 [ V_119 ] . V_136 )
V_133 = V_122 [ V_119 ] . V_136 ;
else {
unsigned int V_106 ;
V_106 = ( V_133 - V_122 [ V_119 ] . V_135 ) % V_122 [ V_119 ] . V_137 ;
if ( V_106 != 0 )
V_133 -= V_106 ;
}
V_134 = V_132 - V_108 * V_133 ;
if ( V_134 < 0 )
V_134 = - V_134 ;
if ( V_125 == 0 ||
V_134 * V_126 < V_127 * V_133 ) {
V_127 = V_134 ;
V_126 = V_133 ;
V_125 = V_132 ;
}
}
if ( V_126 == 0 ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
V_128 . V_114 = F_31 ( V_125 , V_126 ) ;
V_128 . V_115 = ! ! ( V_125 % V_126 ) ;
V_129 = V_125 ;
V_131 = V_127 ;
V_130 = V_126 ;
V_125 = V_126 = V_127 = 0 ;
for ( V_119 = 0 ; V_119 < V_120 ; ++ V_119 ) {
unsigned int V_132 = V_122 [ V_119 ] . V_132 ;
unsigned int V_133 ;
unsigned int V_108 = V_110 -> V_116 ;
int V_134 ;
if ( V_108 == 0 ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
V_133 = F_31 ( V_132 , V_108 ) ;
if ( V_133 > V_122 [ V_119 ] . V_136 )
continue;
if ( V_133 < V_122 [ V_119 ] . V_135 )
V_133 = V_122 [ V_119 ] . V_135 ;
else {
unsigned int V_106 ;
V_106 = ( V_133 - V_122 [ V_119 ] . V_135 ) % V_122 [ V_119 ] . V_137 ;
if ( V_106 != 0 )
V_133 += V_122 [ V_119 ] . V_137 - V_106 ;
}
V_134 = V_108 * V_133 - V_132 ;
if ( V_134 < 0 )
V_134 = - V_134 ;
if ( V_125 == 0 ||
V_134 * V_126 < V_127 * V_133 ) {
V_127 = V_134 ;
V_126 = V_133 ;
V_125 = V_132 ;
}
}
if ( V_126 == 0 ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
V_128 . V_116 = F_32 ( V_125 , V_126 ) ;
V_128 . V_117 = ! ! ( V_125 % V_126 ) ;
V_128 . integer = 0 ;
V_28 = F_36 ( V_110 , & V_128 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_41 ( V_110 ) ) {
if ( V_127 * V_130 < V_131 * V_126 ) {
V_129 = V_125 ;
V_130 = V_126 ;
}
if ( V_123 )
* V_123 = V_129 ;
if ( V_124 )
* V_124 = V_130 ;
}
return V_28 ;
}
static int F_48 ( struct V_109 * V_110 ,
unsigned int V_120 , struct V_138 * V_122 ,
unsigned int * V_123 , unsigned int * V_124 )
{
unsigned int V_125 , V_127 , V_126 ;
unsigned int V_119 ;
struct V_109 V_128 ;
int V_28 ;
V_125 = V_126 = V_127 = 0 ;
for ( V_119 = 0 ; V_119 < V_120 ; ++ V_119 ) {
unsigned int V_132 ;
unsigned int V_133 = V_122 [ V_119 ] . V_133 ;
unsigned int V_108 = V_110 -> V_114 ;
int V_134 ;
V_132 = F_33 ( V_108 , V_133 ) ;
if ( V_132 > V_122 [ V_119 ] . V_139 )
continue;
if ( V_132 < V_122 [ V_119 ] . V_140 )
V_132 = V_122 [ V_119 ] . V_139 ;
else {
unsigned int V_106 ;
V_106 = ( V_132 - V_122 [ V_119 ] . V_140 ) % V_122 [ V_119 ] . V_141 ;
if ( V_106 != 0 )
V_132 += V_122 [ V_119 ] . V_141 - V_106 ;
}
V_134 = V_132 - V_108 * V_133 ;
if ( V_125 == 0 ||
V_134 * V_126 < V_127 * V_133 ) {
V_127 = V_134 ;
V_126 = V_133 ;
V_125 = V_132 ;
}
}
if ( V_126 == 0 ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
V_128 . V_114 = F_31 ( V_125 , V_126 ) ;
V_128 . V_115 = ! ! ( V_125 % V_126 ) ;
V_125 = V_126 = V_127 = 0 ;
for ( V_119 = 0 ; V_119 < V_120 ; ++ V_119 ) {
unsigned int V_132 ;
unsigned int V_133 = V_122 [ V_119 ] . V_133 ;
unsigned int V_108 = V_110 -> V_116 ;
int V_134 ;
V_132 = F_33 ( V_108 , V_133 ) ;
if ( V_132 < V_122 [ V_119 ] . V_140 )
continue;
if ( V_132 > V_122 [ V_119 ] . V_139 )
V_132 = V_122 [ V_119 ] . V_139 ;
else {
unsigned int V_106 ;
V_106 = ( V_132 - V_122 [ V_119 ] . V_140 ) % V_122 [ V_119 ] . V_141 ;
if ( V_106 != 0 )
V_132 -= V_106 ;
}
V_134 = V_108 * V_133 - V_132 ;
if ( V_125 == 0 ||
V_134 * V_126 < V_127 * V_133 ) {
V_127 = V_134 ;
V_126 = V_133 ;
V_125 = V_132 ;
}
}
if ( V_126 == 0 ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
V_128 . V_116 = F_32 ( V_125 , V_126 ) ;
V_128 . V_117 = ! ! ( V_125 % V_126 ) ;
V_128 . integer = 0 ;
V_28 = F_36 ( V_110 , & V_128 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_41 ( V_110 ) ) {
if ( V_123 )
* V_123 = V_125 ;
if ( V_124 )
* V_124 = V_126 ;
}
return V_28 ;
}
int F_49 ( struct V_109 * V_110 , unsigned int V_142 ,
const unsigned int * V_143 , unsigned int V_144 )
{
unsigned int V_119 ;
struct V_109 V_145 ;
if ( ! V_142 ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
F_50 ( & V_145 ) ;
V_145 . V_114 = V_107 ;
V_145 . V_116 = 0 ;
for ( V_119 = 0 ; V_119 < V_142 ; V_119 ++ ) {
if ( V_144 && ! ( V_144 & ( 1 << V_119 ) ) )
continue;
if ( ! F_51 ( V_110 , V_143 [ V_119 ] ) )
continue;
V_145 . V_114 = V_114 ( V_145 . V_114 , V_143 [ V_119 ] ) ;
V_145 . V_116 = V_116 ( V_145 . V_116 , V_143 [ V_119 ] ) ;
}
return F_36 ( V_110 , & V_145 ) ;
}
int F_52 ( struct V_109 * V_110 , unsigned int V_142 ,
const struct V_109 * V_146 , unsigned int V_144 )
{
unsigned int V_119 ;
struct V_109 V_147 ;
struct V_109 V_148 ;
if ( ! V_142 ) {
F_39 ( V_110 ) ;
return - V_113 ;
}
F_50 ( & V_147 ) ;
V_147 . V_114 = V_107 ;
V_147 . V_116 = 0 ;
for ( V_119 = 0 ; V_119 < V_142 ; V_119 ++ ) {
if ( V_144 && ! ( V_144 & ( 1 << V_119 ) ) )
continue;
F_53 ( & V_148 , & V_146 [ V_119 ] ) ;
if ( F_36 ( & V_148 , V_110 ) < 0 )
continue;
if ( F_37 ( & V_148 ) )
continue;
if ( V_148 . V_114 < V_147 . V_114 ) {
V_147 . V_114 = V_148 . V_114 ;
V_147 . V_115 = 1 ;
}
if ( V_148 . V_114 == V_147 . V_114 && ! V_148 . V_115 )
V_147 . V_115 = 0 ;
if ( V_148 . V_116 > V_147 . V_116 ) {
V_147 . V_116 = V_148 . V_116 ;
V_147 . V_117 = 1 ;
}
if ( V_148 . V_116 == V_147 . V_116 && ! V_148 . V_117 )
V_147 . V_117 = 0 ;
}
return F_36 ( V_110 , & V_147 ) ;
}
static int F_54 ( struct V_109 * V_110 , unsigned int V_149 )
{
unsigned int V_12 ;
int V_112 = 0 ;
V_12 = V_110 -> V_114 % V_149 ;
if ( V_12 != 0 || V_110 -> V_115 ) {
V_110 -> V_114 += V_149 - V_12 ;
V_110 -> V_115 = 0 ;
V_112 = 1 ;
}
V_12 = V_110 -> V_116 % V_149 ;
if ( V_12 != 0 || V_110 -> V_117 ) {
V_110 -> V_116 -= V_12 ;
V_110 -> V_117 = 0 ;
V_112 = 1 ;
}
if ( F_38 ( V_110 ) ) {
V_110 -> V_118 = 1 ;
return - V_113 ;
}
return V_112 ;
}
int F_55 ( struct V_4 * V_5 , unsigned int V_150 ,
int V_151 ,
T_6 V_152 , void * V_153 ,
int V_154 , ... )
{
struct V_155 * V_156 = & V_5 -> V_157 ;
struct V_158 * V_33 ;
unsigned int V_119 ;
T_7 args ;
va_start ( args , V_154 ) ;
if ( V_156 -> V_159 >= V_156 -> V_160 ) {
struct V_158 * V_161 ;
unsigned int V_162 = V_156 -> V_160 + 16 ;
V_161 = F_56 ( V_162 , sizeof( * V_33 ) , V_163 ) ;
if ( ! V_161 ) {
va_end ( args ) ;
return - V_164 ;
}
if ( V_156 -> V_165 ) {
memcpy ( V_161 , V_156 -> V_165 ,
V_156 -> V_159 * sizeof( * V_33 ) ) ;
F_57 ( V_156 -> V_165 ) ;
}
V_156 -> V_165 = V_161 ;
V_156 -> V_160 = V_162 ;
}
V_33 = & V_156 -> V_165 [ V_156 -> V_159 ] ;
V_33 -> V_150 = V_150 ;
V_33 -> V_152 = V_152 ;
V_33 -> V_151 = V_151 ;
V_33 -> V_153 = V_153 ;
V_119 = 0 ;
while ( 1 ) {
if ( F_3 ( V_119 >= F_58 ( V_33 -> V_166 ) ) ) {
va_end ( args ) ;
return - V_113 ;
}
V_33 -> V_166 [ V_119 ++ ] = V_154 ;
if ( V_154 < 0 )
break;
V_154 = va_arg ( args , int ) ;
}
V_156 -> V_159 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_59 ( struct V_4 * V_5 , T_8 V_151 ,
T_9 V_144 )
{
struct V_155 * V_156 = & V_5 -> V_157 ;
struct V_167 * V_168 = F_60 ( V_156 , V_151 ) ;
* V_168 -> V_169 &= V_144 ;
memset ( V_168 -> V_169 + 1 , 0 , ( V_170 - 32 ) / 8 ) ;
if ( * V_168 -> V_169 == 0 )
return - V_113 ;
return 0 ;
}
int F_61 ( struct V_4 * V_5 , T_8 V_151 ,
T_5 V_144 )
{
struct V_155 * V_156 = & V_5 -> V_157 ;
struct V_167 * V_168 = F_60 ( V_156 , V_151 ) ;
V_168 -> V_169 [ 0 ] &= ( T_9 ) V_144 ;
V_168 -> V_169 [ 1 ] &= ( T_9 ) ( V_144 >> 32 ) ;
memset ( V_168 -> V_169 + 2 , 0 , ( V_170 - 64 ) / 8 ) ;
if ( ! V_168 -> V_169 [ 0 ] && ! V_168 -> V_169 [ 1 ] )
return - V_113 ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 , T_8 V_151 )
{
struct V_155 * V_156 = & V_5 -> V_157 ;
return F_63 ( F_64 ( V_156 , V_151 ) ) ;
}
int F_65 ( struct V_4 * V_5 , T_8 V_151 ,
unsigned int V_114 , unsigned int V_116 )
{
struct V_155 * V_156 = & V_5 -> V_157 ;
struct V_109 V_128 ;
V_128 . V_114 = V_114 ;
V_128 . V_116 = V_116 ;
V_128 . V_115 = V_128 . V_117 = 0 ;
V_128 . integer = 0 ;
return F_36 ( F_64 ( V_156 , V_151 ) , & V_128 ) ;
}
static int F_66 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
struct V_174 * V_143 = V_173 -> V_153 ;
return F_49 ( F_67 ( V_172 , V_173 -> V_151 ) , V_143 -> V_142 , V_143 -> V_143 , V_143 -> V_144 ) ;
}
int V_174 ( struct V_4 * V_5 ,
unsigned int V_150 ,
T_8 V_151 ,
const struct V_174 * V_175 )
{
return F_55 ( V_5 , V_150 , V_151 ,
F_66 , ( void * ) V_175 ,
V_151 , - 1 ) ;
}
static int F_68 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
struct V_176 * V_106 = V_173 -> V_153 ;
return F_52 ( F_67 ( V_172 , V_173 -> V_151 ) ,
V_106 -> V_142 , V_106 -> V_146 , V_106 -> V_144 ) ;
}
int V_176 ( struct V_4 * V_5 ,
unsigned int V_150 ,
T_8 V_151 ,
const struct V_176 * V_106 )
{
return F_55 ( V_5 , V_150 , V_151 ,
F_68 , ( void * ) V_106 ,
V_151 , - 1 ) ;
}
static int F_69 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
struct V_177 * V_106 = V_173 -> V_153 ;
unsigned int V_132 = 0 , V_133 = 0 ;
int V_28 ;
V_28 = F_47 ( F_67 ( V_172 , V_173 -> V_151 ) ,
V_106 -> V_178 , V_106 -> V_122 , & V_132 , & V_133 ) ;
if ( V_28 >= 0 && V_133 && V_173 -> V_151 == V_179 ) {
V_172 -> V_180 = V_132 ;
V_172 -> V_181 = V_133 ;
}
return V_28 ;
}
int V_177 ( struct V_4 * V_5 ,
unsigned int V_150 ,
T_8 V_151 ,
struct V_177 * V_106 )
{
return F_55 ( V_5 , V_150 , V_151 ,
F_69 , V_106 ,
V_151 , - 1 ) ;
}
static int F_70 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
struct V_182 * V_106 = V_173 -> V_153 ;
unsigned int V_132 = 0 , V_133 = 0 ;
int V_28 = F_48 ( F_67 ( V_172 , V_173 -> V_151 ) ,
V_106 -> V_178 , V_106 -> V_122 , & V_132 , & V_133 ) ;
if ( V_28 >= 0 && V_133 && V_173 -> V_151 == V_179 ) {
V_172 -> V_180 = V_132 ;
V_172 -> V_181 = V_133 ;
}
return V_28 ;
}
int V_182 ( struct V_4 * V_5 ,
unsigned int V_150 ,
T_8 V_151 ,
struct V_182 * V_106 )
{
return F_55 ( V_5 , V_150 , V_151 ,
F_70 , V_106 ,
V_151 , - 1 ) ;
}
static int F_71 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
unsigned int V_175 = ( unsigned long ) V_173 -> V_153 ;
int V_183 = V_175 & 0xffff ;
unsigned int V_184 = V_175 >> 16 ;
struct V_109 * V_110 = F_67 ( V_172 , V_185 ) ;
if ( ! F_41 ( V_110 ) )
return 0 ;
if ( ( F_72 ( V_110 ) == V_183 ) ||
( V_183 == 0 && F_72 ( V_110 ) > V_184 ) )
V_172 -> V_184 = F_73 ( V_172 -> V_184 , V_184 ) ;
return 0 ;
}
int F_74 ( struct V_4 * V_5 ,
unsigned int V_150 ,
unsigned int V_183 ,
unsigned int V_184 )
{
unsigned long V_175 = ( V_184 << 16 ) | V_183 ;
return F_55 ( V_5 , V_150 , - 1 ,
F_71 ,
( void * ) V_175 ,
V_185 , - 1 ) ;
}
static int F_75 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
unsigned long V_149 = ( unsigned long ) V_173 -> V_153 ;
return F_54 ( F_67 ( V_172 , V_173 -> V_151 ) , V_149 ) ;
}
int F_76 ( struct V_4 * V_5 ,
unsigned int V_150 ,
T_8 V_151 ,
unsigned long V_149 )
{
return F_55 ( V_5 , V_150 , V_151 ,
F_75 , ( void * ) V_149 ,
V_151 , - 1 ) ;
}
static int F_77 ( struct V_171 * V_172 , struct V_158 * V_173 )
{
static unsigned int V_186 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_49 ( F_67 ( V_172 , V_173 -> V_151 ) ,
F_58 ( V_186 ) , V_186 , 0 ) ;
}
int F_78 ( struct V_4 * V_5 ,
unsigned int V_150 ,
T_8 V_151 )
{
return F_55 ( V_5 , V_150 , V_151 ,
F_77 , NULL ,
V_151 , - 1 ) ;
}
static int F_79 ( struct V_171 * V_172 ,
struct V_158 * V_173 )
{
unsigned int V_187 = ( unsigned int ) ( V_188 ) V_173 -> V_153 ;
struct V_109 * V_88 ;
V_88 = F_67 ( V_172 , V_179 ) ;
return F_49 ( V_88 , 1 , & V_187 , 0 ) ;
}
int F_80 ( struct V_4 * V_5 ,
unsigned int V_187 )
{
return F_55 ( V_5 , V_189 ,
V_179 ,
F_79 ,
( void * ) ( V_188 ) V_187 ,
V_179 , - 1 ) ;
}
static void F_81 ( struct V_171 * V_172 ,
T_8 V_151 )
{
if ( F_82 ( V_151 ) ) {
F_83 ( F_84 ( V_172 , V_151 ) ) ;
V_172 -> V_190 |= 1 << V_151 ;
V_172 -> V_191 |= 1 << V_151 ;
return;
}
if ( F_85 ( V_151 ) ) {
F_50 ( F_67 ( V_172 , V_151 ) ) ;
V_172 -> V_190 |= 1 << V_151 ;
V_172 -> V_191 |= 1 << V_151 ;
return;
}
F_86 () ;
}
void F_87 ( struct V_171 * V_172 )
{
unsigned int V_119 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
for ( V_119 = V_192 ; V_119 <= V_193 ; V_119 ++ )
F_81 ( V_172 , V_119 ) ;
for ( V_119 = V_194 ; V_119 <= V_195 ; V_119 ++ )
F_81 ( V_172 , V_119 ) ;
V_172 -> V_73 = ~ 0U ;
}
int F_88 ( const struct V_171 * V_172 ,
T_8 V_151 , int * V_196 )
{
if ( F_82 ( V_151 ) ) {
const struct V_167 * V_144 = F_89 ( V_172 , V_151 ) ;
if ( ! F_90 ( V_144 ) )
return - V_113 ;
if ( V_196 )
* V_196 = 0 ;
return F_91 ( V_144 ) ;
}
if ( F_85 ( V_151 ) ) {
const struct V_109 * V_110 = F_92 ( V_172 , V_151 ) ;
if ( ! F_41 ( V_110 ) )
return - V_113 ;
if ( V_196 )
* V_196 = V_110 -> V_115 ;
return F_72 ( V_110 ) ;
}
return - V_113 ;
}
void F_93 ( struct V_171 * V_172 ,
T_8 V_151 )
{
if ( F_82 ( V_151 ) ) {
F_94 ( F_84 ( V_172 , V_151 ) ) ;
V_172 -> V_190 |= 1 << V_151 ;
V_172 -> V_191 |= 1 << V_151 ;
} else if ( F_85 ( V_151 ) ) {
F_39 ( F_67 ( V_172 , V_151 ) ) ;
V_172 -> V_190 |= 1 << V_151 ;
V_172 -> V_191 |= 1 << V_151 ;
} else {
F_86 () ;
}
}
static int F_95 ( struct V_171 * V_172 ,
T_8 V_151 )
{
int V_112 ;
if ( F_82 ( V_151 ) )
V_112 = F_96 ( F_84 ( V_172 , V_151 ) ) ;
else if ( F_85 ( V_151 ) )
V_112 = F_40 ( F_67 ( V_172 , V_151 ) ) ;
else
return - V_113 ;
if ( V_112 ) {
V_172 -> V_190 |= 1 << V_151 ;
V_172 -> V_191 |= 1 << V_151 ;
}
return V_112 ;
}
int F_97 ( struct V_1 * V_38 ,
struct V_171 * V_172 ,
T_8 V_151 , int * V_196 )
{
int V_112 = F_95 ( V_172 , V_151 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_172 -> V_191 ) {
int V_28 = F_98 ( V_38 , V_172 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_88 ( V_172 , V_151 , V_196 ) ;
}
static int F_99 ( struct V_171 * V_172 ,
T_8 V_151 )
{
int V_112 ;
if ( F_82 ( V_151 ) )
V_112 = F_100 ( F_84 ( V_172 , V_151 ) ) ;
else if ( F_85 ( V_151 ) )
V_112 = F_42 ( F_67 ( V_172 , V_151 ) ) ;
else
return - V_113 ;
if ( V_112 ) {
V_172 -> V_190 |= 1 << V_151 ;
V_172 -> V_191 |= 1 << V_151 ;
}
return V_112 ;
}
int F_101 ( struct V_1 * V_38 ,
struct V_171 * V_172 ,
T_8 V_151 , int * V_196 )
{
int V_112 = F_99 ( V_172 , V_151 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_172 -> V_191 ) {
int V_28 = F_98 ( V_38 , V_172 ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return F_88 ( V_172 , V_151 , V_196 ) ;
}
int F_102 ( struct V_1 * V_38 ,
struct V_171 * V_172 )
{
static int V_197 [] = {
V_198 ,
V_199 ,
V_200 ,
V_201 ,
V_179 ,
V_202 ,
V_203 ,
V_204 ,
- 1
} ;
int V_28 , * V_111 ;
for ( V_111 = V_197 ; * V_111 != - 1 ; V_111 ++ ) {
if ( * V_111 != V_203 )
V_28 = F_97 ( V_38 , V_172 , * V_111 , NULL ) ;
else
V_28 = F_101 ( V_38 , V_172 , * V_111 , NULL ) ;
if ( F_3 ( V_28 < 0 ) )
return V_28 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
void * V_205 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_206 ;
F_104 ( V_2 , V_206 ) ;
if ( F_105 ( V_2 ) &&
F_27 ( V_2 ) >= 0 )
V_5 -> V_21 -> V_22 %= V_5 -> V_17 ;
else {
V_5 -> V_21 -> V_22 = 0 ;
V_5 -> V_93 = 0 ;
}
F_106 ( V_2 , V_206 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
void * V_205 )
{
struct V_207 * V_73 = V_205 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_183 ;
if ( ! ( V_5 -> V_73 & V_208 ) ) {
V_73 -> V_209 = - 1 ;
return 0 ;
}
V_183 = F_108 ( V_5 -> V_31 ) ;
if ( V_183 < 0 )
return V_183 ;
V_73 -> V_209 = 0 ;
switch ( V_5 -> V_23 ) {
case V_25 :
case V_24 :
V_73 -> V_210 = V_73 -> V_211 * V_183 ;
V_73 -> V_149 = V_5 -> V_32 * V_183 ;
break;
case V_212 :
case V_213 :
{
T_3 V_214 = V_5 -> V_35 / V_5 -> V_32 ;
V_73 -> V_210 = V_73 -> V_211 * V_214 * 8 ;
V_73 -> V_149 = V_183 ;
break;
}
default:
F_86 () ;
break;
}
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
void * V_205 )
{
struct V_171 * V_172 = V_205 ;
T_10 V_31 ;
int V_32 ;
T_11 V_215 ;
V_172 -> V_216 = V_2 -> V_5 -> V_72 . V_216 ;
if ( ! ( V_2 -> V_5 -> V_72 . V_73 & V_217 ) ) {
V_31 = F_110 ( V_172 ) ;
V_32 = F_111 ( V_172 ) ;
V_215 = F_112 ( V_31 , V_32 ) ;
if ( V_215 > 0 )
V_172 -> V_216 /= ( unsigned ) V_215 ;
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 ,
unsigned int V_218 , void * V_205 )
{
switch ( V_218 ) {
case V_219 :
return 0 ;
case V_220 :
return F_103 ( V_2 , V_205 ) ;
case V_221 :
return F_107 ( V_2 , V_205 ) ;
case V_222 :
return F_109 ( V_2 , V_205 ) ;
}
return - V_223 ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_206 ;
if ( F_115 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_224 )
V_5 -> V_224 ( V_2 ) ;
F_104 ( V_2 , V_206 ) ;
if ( ! F_105 ( V_2 ) ||
F_20 ( V_2 , 1 ) < 0 )
goto V_225;
if ( V_2 -> V_226 )
F_116 ( V_2 -> V_227 , 1 ) ;
V_225:
F_106 ( V_2 , V_206 ) ;
if ( V_5 -> V_228 )
V_5 -> V_228 ( V_2 ) ;
F_117 ( & V_5 -> V_229 , V_230 , V_231 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
T_1 * V_232 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_233 = V_2 -> V_42 == V_49 ;
T_12 V_234 ;
int V_28 = 0 ;
T_1 V_20 = 0 ;
long V_235 , V_236 ;
F_119 ( & V_234 , V_237 ) ;
F_120 ( V_238 ) ;
F_121 ( & V_5 -> V_56 , & V_234 ) ;
if ( V_5 -> V_84 )
V_235 = V_239 ;
else {
V_235 = 10 ;
if ( V_5 -> V_88 ) {
long V_128 = V_5 -> V_77 * 2 / V_5 -> V_88 ;
V_235 = V_116 ( V_128 , V_235 ) ;
}
V_235 = F_122 ( V_235 * 1000 ) ;
}
for (; ; ) {
if ( F_123 ( V_237 ) ) {
V_28 = - V_240 ;
break;
}
if ( V_233 )
V_20 = F_16 ( V_5 ) ;
else
V_20 = F_17 ( V_5 ) ;
if ( V_20 >= V_5 -> V_55 )
break;
F_124 ( V_2 ) ;
V_236 = F_125 ( V_235 ) ;
F_126 ( V_2 ) ;
F_120 ( V_238 ) ;
switch ( V_5 -> V_21 -> V_51 ) {
case V_241 :
V_28 = - V_242 ;
goto V_243;
case V_47 :
V_28 = - V_53 ;
goto V_243;
case V_52 :
if ( V_233 )
V_28 = - V_53 ;
else
V_20 = 0 ;
goto V_243;
case V_244 :
case V_245 :
case V_246 :
V_28 = - V_247 ;
goto V_243;
case V_248 :
continue;
}
if ( ! V_236 ) {
F_127 ( V_2 -> V_38 ,
L_10 ,
V_233 ? L_11 : L_12 ) ;
V_28 = - V_249 ;
break;
}
}
V_243:
F_120 ( V_250 ) ;
F_128 ( & V_5 -> V_56 , & V_234 ) ;
* V_232 = V_20 ;
return V_28 ;
}
static int F_129 ( struct V_1 * V_2 ,
unsigned int V_251 ,
unsigned long V_252 , unsigned int V_253 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_13 * V_254 = ( char T_13 * ) V_252 + F_4 ( V_5 , V_253 ) ;
if ( V_2 -> V_26 -> V_255 ) {
if ( ( V_28 = V_2 -> V_26 -> V_255 ( V_2 , - 1 , V_251 , V_254 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_251 ) ;
if ( F_130 ( V_29 , V_254 , F_4 ( V_5 , V_6 ) ) )
return - V_256 ;
}
return 0 ;
}
static T_2 F_131 ( struct V_1 * V_2 ,
unsigned long V_252 ,
T_1 V_214 ,
int V_257 ,
T_14 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_258 = 0 ;
T_1 V_209 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_214 == 0 )
return 0 ;
F_126 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_51 ) {
case V_259 :
case V_260 :
case V_248 :
break;
case V_47 :
V_28 = - V_53 ;
goto V_261;
case V_241 :
V_28 = - V_242 ;
goto V_261;
default:
V_28 = - V_247 ;
goto V_261;
}
V_5 -> V_55 = V_5 -> V_14 -> V_57 ? : 1 ;
if ( V_5 -> V_21 -> V_51 == V_260 )
F_27 ( V_2 ) ;
V_20 = F_16 ( V_5 ) ;
while ( V_214 > 0 ) {
T_1 V_6 , V_15 , V_262 ;
T_1 V_263 ;
if ( ! V_20 ) {
if ( V_257 ) {
V_28 = - V_264 ;
goto V_261;
}
V_5 -> V_55 = F_132 ( T_1 , V_214 ,
V_5 -> V_14 -> V_57 ? : 1 ) ;
V_28 = F_118 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_261;
}
V_6 = V_214 > V_20 ? V_20 : V_214 ;
V_263 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_263 )
V_6 = V_263 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_55 = 0 ;
F_124 ( V_2 ) ;
return - V_113 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_262 = V_15 % V_5 -> V_17 ;
F_124 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_262 , V_252 , V_209 , V_6 ) ;
F_126 ( V_2 ) ;
if ( V_28 < 0 )
goto V_261;
switch ( V_5 -> V_21 -> V_51 ) {
case V_47 :
V_28 = - V_53 ;
goto V_261;
case V_241 :
V_28 = - V_242 ;
goto V_261;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_265 )
V_2 -> V_26 -> V_265 ( V_2 ) ;
V_209 += V_6 ;
V_214 -= V_6 ;
V_258 += V_6 ;
V_20 -= V_6 ;
if ( V_5 -> V_21 -> V_51 == V_259 &&
F_2 ( V_5 ) >= ( T_2 ) V_5 -> V_266 ) {
V_28 = F_133 ( V_2 ) ;
if ( V_28 < 0 )
goto V_261;
}
}
V_261:
V_5 -> V_55 = 0 ;
if ( V_258 > 0 && V_28 >= 0 )
F_15 ( V_2 , V_5 ) ;
F_124 ( V_2 ) ;
return V_258 > 0 ? ( T_2 ) V_258 : V_28 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_115 ( V_2 ) )
return - V_223 ;
V_5 = V_2 -> V_5 ;
if ( F_3 ( ! V_2 -> V_26 -> V_255 && ! V_5 -> V_30 ) )
return - V_113 ;
if ( V_5 -> V_21 -> V_51 == V_244 )
return - V_247 ;
return 0 ;
}
T_2 F_135 ( struct V_1 * V_2 , const void T_13 * V_254 , T_1 V_214 )
{
struct V_4 * V_5 ;
int V_257 ;
int V_28 ;
V_28 = F_134 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_257 = ! ! ( V_2 -> V_267 & V_268 ) ;
if ( V_5 -> V_23 != V_24 &&
V_5 -> V_32 > 1 )
return - V_113 ;
return F_131 ( V_2 , ( unsigned long ) V_254 , V_214 , V_257 ,
F_129 ) ;
}
static int F_136 ( struct V_1 * V_2 ,
unsigned int V_251 ,
unsigned long V_252 , unsigned int V_253 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_13 * * V_269 = ( void T_13 * * ) V_252 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_255 ) {
if ( F_3 ( ! V_2 -> V_26 -> V_27 ) )
return - V_113 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_269 ) {
if ( * V_269 == NULL ) {
if ( ( V_28 = V_2 -> V_26 -> V_27 ( V_2 , V_33 , V_251 , V_6 ) ) < 0 )
return V_28 ;
} else {
char T_13 * V_254 = * V_269 + F_6 ( V_5 , V_253 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_255 ( V_2 , V_33 , V_251 , V_254 , V_6 ) ) < 0 )
return V_28 ;
}
}
} else {
T_3 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_269 ) {
char * V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_251 ) ;
if ( * V_269 == NULL ) {
F_5 ( V_5 -> V_31 , V_29 , V_6 ) ;
} else {
char T_13 * V_254 = * V_269 + F_6 ( V_5 , V_253 ) ;
if ( F_130 ( V_29 , V_254 , F_6 ( V_5 , V_6 ) ) )
return - V_256 ;
}
}
}
return 0 ;
}
T_2 F_137 ( struct V_1 * V_2 ,
void T_13 * * V_269 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_257 ;
int V_28 ;
V_28 = F_134 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_257 = ! ! ( V_2 -> V_267 & V_268 ) ;
if ( V_5 -> V_23 != V_213 )
return - V_113 ;
return F_131 ( V_2 , ( unsigned long ) V_269 , V_6 ,
V_257 , F_136 ) ;
}
static int F_138 ( struct V_1 * V_2 ,
unsigned int V_251 ,
unsigned long V_252 , unsigned int V_253 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
char T_13 * V_254 = ( char T_13 * ) V_252 + F_4 ( V_5 , V_253 ) ;
if ( V_2 -> V_26 -> V_255 ) {
if ( ( V_28 = V_2 -> V_26 -> V_255 ( V_2 , - 1 , V_251 , V_254 , V_6 ) ) < 0 )
return V_28 ;
} else {
char * V_29 = V_5 -> V_30 + F_4 ( V_5 , V_251 ) ;
if ( F_139 ( V_254 , V_29 , F_4 ( V_5 , V_6 ) ) )
return - V_256 ;
}
return 0 ;
}
static T_2 F_140 ( struct V_1 * V_2 ,
unsigned long V_252 ,
T_1 V_214 ,
int V_257 ,
T_14 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_258 = 0 ;
T_1 V_209 = 0 ;
T_1 V_20 ;
int V_28 = 0 ;
if ( V_214 == 0 )
return 0 ;
F_126 ( V_2 ) ;
switch ( V_5 -> V_21 -> V_51 ) {
case V_259 :
if ( V_214 >= V_5 -> V_266 ) {
V_28 = F_133 ( V_2 ) ;
if ( V_28 < 0 )
goto V_261;
}
break;
case V_52 :
case V_260 :
case V_248 :
break;
case V_47 :
V_28 = - V_53 ;
goto V_261;
case V_241 :
V_28 = - V_242 ;
goto V_261;
default:
V_28 = - V_247 ;
goto V_261;
}
V_5 -> V_55 = V_5 -> V_14 -> V_57 ? : 1 ;
if ( V_5 -> V_21 -> V_51 == V_260 )
F_27 ( V_2 ) ;
V_20 = F_17 ( V_5 ) ;
while ( V_214 > 0 ) {
T_1 V_6 , V_15 , V_262 ;
T_1 V_263 ;
if ( ! V_20 ) {
if ( V_5 -> V_21 -> V_51 ==
V_52 ) {
F_11 ( V_2 , V_245 ) ;
goto V_261;
}
if ( V_257 ) {
V_28 = - V_264 ;
goto V_261;
}
V_5 -> V_55 = F_132 ( T_1 , V_214 ,
V_5 -> V_14 -> V_57 ? : 1 ) ;
V_28 = F_118 ( V_2 , & V_20 ) ;
if ( V_28 < 0 )
goto V_261;
if ( ! V_20 )
continue;
}
V_6 = V_214 > V_20 ? V_20 : V_214 ;
V_263 = V_5 -> V_17 - V_5 -> V_14 -> V_15 % V_5 -> V_17 ;
if ( V_6 > V_263 )
V_6 = V_263 ;
if ( F_3 ( ! V_6 ) ) {
V_5 -> V_55 = 0 ;
F_124 ( V_2 ) ;
return - V_113 ;
}
V_15 = V_5 -> V_14 -> V_15 ;
V_262 = V_15 % V_5 -> V_17 ;
F_124 ( V_2 ) ;
V_28 = V_8 ( V_2 , V_262 , V_252 , V_209 , V_6 ) ;
F_126 ( V_2 ) ;
if ( V_28 < 0 )
goto V_261;
switch ( V_5 -> V_21 -> V_51 ) {
case V_47 :
V_28 = - V_53 ;
goto V_261;
case V_241 :
V_28 = - V_242 ;
goto V_261;
default:
break;
}
V_15 += V_6 ;
if ( V_15 >= V_5 -> V_10 )
V_15 -= V_5 -> V_10 ;
V_5 -> V_14 -> V_15 = V_15 ;
if ( V_2 -> V_26 -> V_265 )
V_2 -> V_26 -> V_265 ( V_2 ) ;
V_209 += V_6 ;
V_214 -= V_6 ;
V_258 += V_6 ;
V_20 -= V_6 ;
}
V_261:
V_5 -> V_55 = 0 ;
if ( V_258 > 0 && V_28 >= 0 )
F_15 ( V_2 , V_5 ) ;
F_124 ( V_2 ) ;
return V_258 > 0 ? ( T_2 ) V_258 : V_28 ;
}
T_2 F_141 ( struct V_1 * V_2 , void T_13 * V_254 , T_1 V_214 )
{
struct V_4 * V_5 ;
int V_257 ;
int V_28 ;
V_28 = F_134 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
V_257 = ! ! ( V_2 -> V_267 & V_268 ) ;
if ( V_5 -> V_23 != V_24 )
return - V_113 ;
return F_140 ( V_2 , ( unsigned long ) V_254 , V_214 , V_257 , F_138 ) ;
}
static int F_142 ( struct V_1 * V_2 ,
unsigned int V_251 ,
unsigned long V_252 , unsigned int V_253 ,
T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_28 ;
void T_13 * * V_269 = ( void T_13 * * ) V_252 ;
int V_32 = V_5 -> V_32 ;
int V_33 ;
if ( V_2 -> V_26 -> V_255 ) {
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_269 ) {
char T_13 * V_254 ;
if ( * V_269 == NULL )
continue;
V_254 = * V_269 + F_6 ( V_5 , V_253 ) ;
if ( ( V_28 = V_2 -> V_26 -> V_255 ( V_2 , V_33 , V_251 , V_254 , V_6 ) ) < 0 )
return V_28 ;
}
} else {
T_1 V_34 = V_5 -> V_35 / V_32 ;
for ( V_33 = 0 ; V_33 < V_32 ; ++ V_33 , ++ V_269 ) {
char * V_29 ;
char T_13 * V_254 ;
if ( * V_269 == NULL )
continue;
V_29 = V_5 -> V_30 + ( V_33 * V_34 ) + F_6 ( V_5 , V_251 ) ;
V_254 = * V_269 + F_6 ( V_5 , V_253 ) ;
if ( F_139 ( V_254 , V_29 , F_6 ( V_5 , V_6 ) ) )
return - V_256 ;
}
}
return 0 ;
}
T_2 F_143 ( struct V_1 * V_2 ,
void T_13 * * V_269 ,
T_1 V_6 )
{
struct V_4 * V_5 ;
int V_257 ;
int V_28 ;
V_28 = F_134 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 -> V_51 == V_244 )
return - V_247 ;
V_257 = ! ! ( V_2 -> V_267 & V_268 ) ;
if ( V_5 -> V_23 != V_213 )
return - V_113 ;
return F_140 ( V_2 , ( unsigned long ) V_269 , V_6 , V_257 , F_142 ) ;
}
static bool F_144 ( const struct V_270 * V_73 , int V_271 )
{
if ( V_271 > V_73 -> V_272 )
return false ;
return ! V_73 -> V_273 || ( V_73 -> V_273 & ( 1U << V_271 ) ) ;
}
static int F_145 ( struct V_274 * V_275 ,
struct V_276 * V_277 )
{
struct V_270 * V_73 = F_146 ( V_275 ) ;
V_277 -> type = V_278 ;
V_277 -> V_142 = 0 ;
V_277 -> V_142 = V_73 -> V_272 ;
V_277 -> V_279 . integer . V_114 = 0 ;
V_277 -> V_279 . integer . V_116 = V_280 ;
return 0 ;
}
static int F_147 ( struct V_274 * V_275 ,
struct V_281 * V_282 )
{
struct V_270 * V_73 = F_146 ( V_275 ) ;
unsigned int V_283 = F_148 ( V_275 , & V_282 -> V_284 ) ;
struct V_1 * V_2 ;
const struct V_285 * V_286 ;
if ( F_3 ( ! V_73 -> V_287 ) )
return - V_113 ;
V_2 = F_149 ( V_73 , V_283 ) ;
if ( ! V_2 )
return - V_288 ;
memset ( V_282 -> V_279 . integer . V_279 , 0 ,
sizeof( V_282 -> V_279 . integer . V_279 ) ) ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_286 = V_73 -> V_287 ; V_286 -> V_32 ; V_286 ++ ) {
int V_110 ;
if ( V_286 -> V_32 == V_2 -> V_5 -> V_32 &&
F_144 ( V_73 , V_286 -> V_32 ) ) {
for ( V_110 = 0 ; V_110 < V_286 -> V_32 ; V_110 ++ )
V_282 -> V_279 . integer . V_279 [ V_110 ] = V_286 -> V_286 [ V_110 ] ;
return 0 ;
}
}
return - V_113 ;
}
static int F_150 ( struct V_274 * V_275 , int V_289 ,
unsigned int V_214 , unsigned int T_13 * V_290 )
{
struct V_270 * V_73 = F_146 ( V_275 ) ;
const struct V_285 * V_286 ;
unsigned int T_13 * V_291 ;
int V_33 , V_142 = 0 ;
if ( F_3 ( ! V_73 -> V_287 ) )
return - V_113 ;
if ( V_214 < 8 )
return - V_164 ;
if ( F_151 ( V_292 , V_290 ) )
return - V_256 ;
V_214 -= 8 ;
V_291 = V_290 + 2 ;
for ( V_286 = V_73 -> V_287 ; V_286 -> V_32 ; V_286 ++ ) {
int V_293 = V_286 -> V_32 * 4 ;
if ( ! F_144 ( V_73 , V_286 -> V_32 ) )
continue;
if ( V_214 < 8 )
return - V_164 ;
if ( F_151 ( V_294 , V_291 ) ||
F_151 ( V_293 , V_291 + 1 ) )
return - V_256 ;
V_291 += 2 ;
V_214 -= 8 ;
V_142 += 8 ;
if ( V_214 < V_293 )
return - V_164 ;
V_214 -= V_293 ;
V_142 += V_293 ;
for ( V_33 = 0 ; V_33 < V_286 -> V_32 ; V_33 ++ ) {
if ( F_151 ( V_286 -> V_286 [ V_33 ] , V_291 ) )
return - V_256 ;
V_291 ++ ;
}
}
if ( F_151 ( V_142 , V_290 + 1 ) )
return - V_256 ;
return 0 ;
}
static void F_152 ( struct V_274 * V_275 )
{
struct V_270 * V_73 = F_146 ( V_275 ) ;
V_73 -> V_38 -> V_100 [ V_73 -> V_42 ] . V_295 = NULL ;
F_57 ( V_73 ) ;
}
int F_153 ( struct V_96 * V_38 , int V_42 ,
const struct V_285 * V_287 ,
int V_272 ,
unsigned long V_296 ,
struct V_270 * * V_297 )
{
struct V_270 * V_73 ;
struct V_298 V_299 = {
. V_300 = V_301 ,
. V_23 = V_302 |
V_303 |
V_304 ,
. V_73 = F_145 ,
. V_305 = F_147 ,
. V_290 . V_33 = F_150 ,
} ;
int V_28 ;
V_73 = F_154 ( sizeof( * V_73 ) , V_163 ) ;
if ( ! V_73 )
return - V_164 ;
V_73 -> V_38 = V_38 ;
V_73 -> V_42 = V_42 ;
V_73 -> V_287 = V_287 ;
V_73 -> V_272 = V_272 ;
if ( V_42 == V_49 )
V_299 . V_36 = L_13 ;
else
V_299 . V_36 = L_14 ;
V_299 . V_41 = V_38 -> V_41 ;
V_299 . V_142 = V_38 -> V_100 [ V_42 ] . V_306 ;
V_299 . V_296 = V_296 ;
V_73 -> V_307 = F_155 ( & V_299 , V_73 ) ;
if ( ! V_73 -> V_307 ) {
F_57 ( V_73 ) ;
return - V_164 ;
}
V_73 -> V_307 -> V_308 = F_152 ;
V_28 = F_156 ( V_38 -> V_39 , V_73 -> V_307 ) ;
if ( V_28 < 0 )
return V_28 ;
V_38 -> V_100 [ V_42 ] . V_295 = V_73 -> V_307 ;
if ( V_297 )
* V_297 = V_73 ;
return 0 ;
}
