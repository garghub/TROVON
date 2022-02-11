void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_8 ;
int V_9 ;
if ( V_5 -> V_10 < V_5 -> V_11 ) {
T_2 V_12 , V_13 ;
T_1 V_14 = F_2 ( V_5 -> V_15 -> V_14 ) ;
if ( V_5 -> V_16 != V_14 ) {
V_13 = V_14 - V_5 -> V_16 ;
if ( V_13 < 0 )
V_13 += V_5 -> V_11 ;
if ( ( T_1 ) V_13 < V_5 -> V_17 )
V_5 -> V_17 -= V_13 ;
else
V_5 -> V_17 = 0 ;
V_5 -> V_16 = V_14 ;
}
if ( V_5 -> V_17 >= V_5 -> V_18 )
return;
V_12 = F_3 ( V_5 ) + V_5 -> V_17 ;
if ( V_12 >= ( T_2 ) V_5 -> V_19 )
return;
V_6 = V_5 -> V_19 - V_12 ;
if ( V_6 > V_5 -> V_10 )
V_6 = V_5 -> V_10 ;
} else {
if ( V_3 == V_20 ) {
T_2 V_21 = F_3 ( V_5 ) ;
if ( V_21 > V_5 -> V_18 )
V_21 = V_5 -> V_18 ;
V_5 -> V_17 = V_21 > 0 ? V_21 : 0 ;
V_5 -> V_16 = ( V_5 -> V_22 -> V_23 +
V_5 -> V_17 ) %
V_5 -> V_11 ;
} else {
V_7 = V_5 -> V_22 -> V_23 ;
V_6 = V_3 - V_7 ;
if ( ( T_2 ) V_6 < 0 )
V_6 += V_5 -> V_11 ;
V_5 -> V_17 -= V_6 ;
if ( ( T_2 ) V_5 -> V_17 < 0 ) {
V_5 -> V_17 = 0 ;
V_5 -> V_16 = V_3 ;
} else {
V_5 -> V_16 = V_7 ;
}
}
V_6 = V_5 -> V_18 - V_5 -> V_17 ;
}
if ( F_4 ( V_6 > V_5 -> V_18 ) )
return;
if ( V_6 == 0 )
return;
V_7 = V_5 -> V_16 % V_5 -> V_18 ;
while ( V_6 > 0 ) {
V_8 = V_7 + V_6 > V_5 -> V_18 ? V_5 -> V_18 - V_7 : V_6 ;
V_9 = F_5 ( V_2 , V_7 , V_8 ) ;
F_4 ( V_9 < 0 ) ;
V_5 -> V_17 += V_8 ;
V_6 -= V_8 ;
V_7 = 0 ;
}
}
void F_6 ( struct V_1 * V_2 ,
char * V_24 , T_3 V_25 )
{
snprintf ( V_24 , V_25 , L_1 ,
V_2 -> V_26 -> V_27 -> V_28 ,
V_2 -> V_26 -> V_29 ,
V_2 -> V_30 ? 'c' : 'p' ,
V_2 -> V_28 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_8 ( V_2 ) ;
if ( V_5 -> V_31 == V_32 )
F_9 ( V_5 , (struct V_33 * ) & V_5 -> V_22 -> V_34 ) ;
F_10 ( V_2 , V_35 ) ;
if ( F_11 ( V_2 , V_36 ) ) {
char V_24 [ 16 ] ;
F_6 ( V_2 , V_24 , sizeof( V_24 ) ) ;
F_12 ( V_2 -> V_26 , L_2 , V_24 ) ;
F_13 ( V_2 ) ;
}
}
int F_14 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_1 V_21 ;
if ( V_2 -> V_30 == V_37 )
V_21 = F_15 ( V_5 ) ;
else
V_21 = F_16 ( V_5 ) ;
if ( V_21 > V_5 -> V_38 )
V_5 -> V_38 = V_21 ;
if ( V_5 -> V_22 -> V_39 == V_40 ) {
if ( V_21 >= V_5 -> V_18 ) {
F_17 ( V_2 ) ;
return - V_41 ;
}
} else {
if ( V_21 >= V_5 -> V_42 ) {
F_7 ( V_2 ) ;
return - V_41 ;
}
}
if ( V_5 -> V_43 ) {
if ( V_21 >= V_5 -> V_43 )
F_18 ( & V_5 -> V_44 ) ;
} else if ( V_21 >= V_5 -> V_15 -> V_45 )
F_18 ( & V_5 -> V_46 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_33 * V_47 ,
struct V_33 * V_48 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_4 V_49 , V_50 ;
struct V_33 V_51 ;
if ( V_5 -> V_31 != V_32 )
return;
if ( ! ( V_2 -> V_52 -> V_53 ) ||
( V_5 -> V_54 . V_55 ==
V_56 ) ) {
V_49 = V_5 -> V_57 + V_5 -> V_22 -> V_23 ;
if ( V_5 -> V_58 . V_59 ) {
if ( V_2 -> V_30 == V_37 )
V_49 -= V_5 -> V_60 ;
else
V_49 += V_5 -> V_60 ;
}
V_50 = F_20 ( V_49 * 1000000000LL ,
V_5 -> V_61 ) ;
* V_48 = F_21 ( V_50 ) ;
}
V_5 -> V_22 -> V_48 = * V_48 ;
V_5 -> V_22 -> V_34 = * V_47 ;
F_9 ( V_2 -> V_5 , (struct V_33 * ) & V_51 ) ;
V_5 -> V_51 = V_51 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_63 ;
T_1 V_64 , V_3 , V_65 ;
T_2 V_66 , V_67 ;
unsigned long V_68 ;
unsigned long V_69 ;
struct V_33 V_47 ;
struct V_33 V_48 ;
int V_70 = 0 ;
V_64 = V_5 -> V_22 -> V_23 ;
V_63 = V_2 -> V_52 -> V_71 ( V_2 ) ;
V_69 = V_72 ;
if ( V_5 -> V_31 == V_32 ) {
if ( ( V_2 -> V_52 -> V_53 ) &&
( V_5 -> V_58 . V_73 != V_56 ) ) {
V_2 -> V_52 -> V_53 ( V_2 , & V_47 ,
& V_48 ,
& V_5 -> V_58 ,
& V_5 -> V_54 ) ;
if ( V_5 -> V_54 . V_55 == V_56 )
F_9 ( V_5 , (struct V_33 * ) & V_47 ) ;
} else
F_9 ( V_5 , (struct V_33 * ) & V_47 ) ;
}
if ( V_63 == V_74 ) {
F_7 ( V_2 ) ;
return - V_41 ;
}
if ( V_63 >= V_5 -> V_18 ) {
if ( F_23 () ) {
char V_24 [ 16 ] ;
F_6 ( V_2 , V_24 , sizeof( V_24 ) ) ;
F_24 ( V_2 -> V_26 ,
L_3 ,
V_24 , V_63 , V_5 -> V_18 ,
V_5 -> V_75 ) ;
}
V_63 = 0 ;
}
V_63 -= V_63 % V_5 -> V_76 ;
F_25 ( V_2 , V_63 , V_62 ) ;
V_65 = V_5 -> V_77 ;
V_3 = V_65 + V_63 ;
if ( V_62 ) {
V_67 = V_5 -> V_78 + V_5 -> V_75 ;
if ( V_67 > V_3 ) {
V_66 = V_69 - V_5 -> V_79 ;
if ( V_66 > V_5 -> V_80 / 2 + 1 ) {
V_65 += V_5 -> V_18 ;
if ( V_65 >= V_5 -> V_11 ) {
V_65 = 0 ;
V_70 ++ ;
}
V_3 = V_65 + V_63 ;
goto V_81;
}
}
}
if ( V_3 < V_64 ) {
V_65 += V_5 -> V_18 ;
if ( V_65 >= V_5 -> V_11 ) {
V_65 = 0 ;
V_70 ++ ;
}
V_3 = V_65 + V_63 ;
}
V_81:
V_67 = V_3 - V_64 ;
if ( V_67 < 0 )
V_67 += V_5 -> V_11 ;
if ( V_5 -> V_82 ) {
T_2 V_83 ;
V_68 = V_69 - V_5 -> V_79 ;
if ( V_68 < V_5 -> V_80 / 2 )
goto V_84;
V_66 = V_68 - V_67 * V_85 / V_5 -> V_61 ;
V_83 = V_5 -> V_80 / 2 + 1 ;
while ( V_66 > V_83 ) {
V_67 += V_5 -> V_18 ;
V_65 += V_5 -> V_18 ;
if ( V_65 >= V_5 -> V_11 ) {
V_65 = 0 ;
V_70 ++ ;
}
V_3 = V_65 + V_63 ;
V_66 -= V_5 -> V_80 ;
}
goto V_84;
}
if ( V_67 >= V_5 -> V_18 + V_5 -> V_75 ) {
F_26 ( V_2 , V_62 , L_4 ,
L_5 ,
V_2 -> V_30 , ( long ) V_63 ,
( long ) V_3 , ( long ) V_64 ) ;
return 0 ;
}
if ( ! F_11 ( V_2 , V_86 ) )
goto V_87;
if ( V_5 -> V_88 . V_89 & V_90 )
goto V_87;
V_66 = V_67 ;
if ( V_66 < V_5 -> V_60 )
goto V_87;
V_66 -= V_5 -> V_60 ;
V_68 = V_69 - V_5 -> V_79 ;
if ( ( ( V_66 * V_85 ) / V_5 -> V_61 ) > V_68 + V_85 / 100 ) {
V_67 = V_68 /
( ( ( V_5 -> V_75 * V_85 ) / V_5 -> V_61 )
+ V_85 / 100 ) ;
V_3 = V_64 ;
V_65 = V_67 ;
while ( V_67 > 0 ) {
V_3 += V_5 -> V_75 ;
if ( V_3 >= V_5 -> V_11 ) {
V_3 -= V_5 -> V_11 ;
V_70 -- ;
}
V_67 -- ;
}
F_26 ( V_2 , V_62 , L_6 ,
L_7 ,
( long ) V_63 , ( long ) V_66 ,
( long ) V_5 -> V_75 , V_68 ,
( ( V_66 * V_85 ) / V_5 -> V_61 ) , V_65 ,
( unsigned long ) V_64 ,
( unsigned long ) V_3 ) ;
V_67 = 0 ;
V_65 = V_3 - ( V_3 % V_5 -> V_18 ) ;
}
V_87:
if ( V_67 > V_5 -> V_75 + V_5 -> V_75 / 2 ) {
F_26 ( V_2 , V_62 ,
L_8 ,
L_9 ,
V_2 -> V_30 , ( long ) V_67 ,
( long ) V_3 ,
( long ) V_64 ) ;
}
V_84:
if ( V_5 -> V_22 -> V_23 == V_3 ) {
F_19 ( V_2 , & V_47 , & V_48 ) ;
return 0 ;
}
if ( V_2 -> V_30 == V_37 &&
V_5 -> V_10 > 0 )
F_1 ( V_2 , V_3 ) ;
if ( V_62 ) {
V_67 = V_3 - V_5 -> V_78 ;
if ( V_67 < 0 )
V_67 += V_5 -> V_11 ;
V_67 -= ( T_1 ) V_67 % V_5 -> V_75 ;
V_5 -> V_78 += V_67 ;
if ( V_5 -> V_78 >= V_5 -> V_11 )
V_5 -> V_78 -= V_5 -> V_11 ;
}
V_5 -> V_77 = V_65 ;
V_5 -> V_22 -> V_23 = V_3 ;
V_5 -> V_79 = V_69 ;
if ( V_70 ) {
F_4 ( V_70 != 1 ) ;
V_5 -> V_57 += V_5 -> V_11 ;
}
F_19 ( V_2 , & V_47 , & V_48 ) ;
return F_14 ( V_2 , V_5 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , 0 ) ;
}
void F_28 ( struct V_91 * V_26 , int V_92 ,
const struct V_93 * V_52 )
{
struct V_94 * V_30 = & V_26 -> V_95 [ V_92 ] ;
struct V_1 * V_2 ;
for ( V_2 = V_30 -> V_2 ; V_2 != NULL ; V_2 = V_2 -> V_96 )
V_2 -> V_52 = V_52 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_97 . V_98 [ 0 ] = V_2 -> V_26 -> V_27 -> V_28 ;
V_5 -> V_97 . V_98 [ 1 ] = - 1 ;
V_5 -> V_97 . V_98 [ 2 ] = - 1 ;
V_5 -> V_97 . V_98 [ 3 ] = - 1 ;
}
static inline unsigned int F_30 ( unsigned int V_99 , unsigned int V_100 ,
unsigned int * V_101 )
{
if ( V_100 == 0 ) {
* V_101 = 0 ;
return V_102 ;
}
* V_101 = V_99 % V_100 ;
return V_99 / V_100 ;
}
static inline unsigned int F_31 ( unsigned int V_99 , unsigned int V_100 )
{
if ( V_100 == 0 )
return V_102 ;
return V_99 / V_100 ;
}
static inline unsigned int F_32 ( unsigned int V_99 , unsigned int V_100 )
{
unsigned int V_101 ;
unsigned int V_103 ;
if ( V_100 == 0 )
return V_102 ;
V_103 = F_30 ( V_99 , V_100 , & V_101 ) ;
if ( V_101 )
++ V_103 ;
return V_103 ;
}
static inline unsigned int F_33 ( unsigned int V_99 , unsigned int V_100 )
{
if ( V_99 == 0 )
return 0 ;
if ( F_31 ( V_102 , V_99 ) < V_100 )
return V_102 ;
return V_99 * V_100 ;
}
static inline unsigned int F_34 ( unsigned int V_99 , unsigned int V_100 ,
unsigned int V_104 , unsigned int * V_101 )
{
T_5 V_13 = ( T_5 ) V_99 * V_100 ;
if ( V_104 == 0 ) {
F_4 ( ! V_13 ) ;
* V_101 = 0 ;
return V_102 ;
}
V_13 = F_35 ( V_13 , V_104 , V_101 ) ;
if ( V_13 >= V_102 ) {
* V_101 = 0 ;
return V_102 ;
}
return V_13 ;
}
int F_36 ( struct V_105 * V_106 , const struct V_105 * V_107 )
{
int V_108 = 0 ;
if ( F_4 ( F_37 ( V_106 ) ) )
return - V_109 ;
if ( V_106 -> V_110 < V_107 -> V_110 ) {
V_106 -> V_110 = V_107 -> V_110 ;
V_106 -> V_111 = V_107 -> V_111 ;
V_108 = 1 ;
} else if ( V_106 -> V_110 == V_107 -> V_110 && ! V_106 -> V_111 && V_107 -> V_111 ) {
V_106 -> V_111 = 1 ;
V_108 = 1 ;
}
if ( V_106 -> V_112 > V_107 -> V_112 ) {
V_106 -> V_112 = V_107 -> V_112 ;
V_106 -> V_113 = V_107 -> V_113 ;
V_108 = 1 ;
} else if ( V_106 -> V_112 == V_107 -> V_112 && ! V_106 -> V_113 && V_107 -> V_113 ) {
V_106 -> V_113 = 1 ;
V_108 = 1 ;
}
if ( ! V_106 -> integer && V_107 -> integer ) {
V_106 -> integer = 1 ;
V_108 = 1 ;
}
if ( V_106 -> integer ) {
if ( V_106 -> V_111 ) {
V_106 -> V_110 ++ ;
V_106 -> V_111 = 0 ;
}
if ( V_106 -> V_113 ) {
V_106 -> V_112 -- ;
V_106 -> V_113 = 0 ;
}
} else if ( ! V_106 -> V_111 && ! V_106 -> V_113 && V_106 -> V_110 == V_106 -> V_112 )
V_106 -> integer = 1 ;
if ( F_38 ( V_106 ) ) {
F_39 ( V_106 ) ;
return - V_109 ;
}
return V_108 ;
}
static int F_40 ( struct V_105 * V_106 )
{
if ( F_4 ( F_37 ( V_106 ) ) )
return - V_109 ;
if ( F_41 ( V_106 ) )
return 0 ;
V_106 -> V_112 = V_106 -> V_110 ;
V_106 -> V_113 = V_106 -> V_111 ;
if ( V_106 -> V_113 )
V_106 -> V_112 ++ ;
return 1 ;
}
static int F_42 ( struct V_105 * V_106 )
{
if ( F_4 ( F_37 ( V_106 ) ) )
return - V_109 ;
if ( F_41 ( V_106 ) )
return 0 ;
V_106 -> V_110 = V_106 -> V_112 ;
V_106 -> V_111 = V_106 -> V_113 ;
if ( V_106 -> V_111 )
V_106 -> V_110 -- ;
return 1 ;
}
void F_43 ( const struct V_105 * V_99 , const struct V_105 * V_100 , struct V_105 * V_104 )
{
if ( V_99 -> V_114 || V_100 -> V_114 ) {
F_39 ( V_104 ) ;
return;
}
V_104 -> V_114 = 0 ;
V_104 -> V_110 = F_33 ( V_99 -> V_110 , V_100 -> V_110 ) ;
V_104 -> V_111 = ( V_99 -> V_111 || V_100 -> V_111 ) ;
V_104 -> V_112 = F_33 ( V_99 -> V_112 , V_100 -> V_112 ) ;
V_104 -> V_113 = ( V_99 -> V_113 || V_100 -> V_113 ) ;
V_104 -> integer = ( V_99 -> integer && V_100 -> integer ) ;
}
void F_44 ( const struct V_105 * V_99 , const struct V_105 * V_100 , struct V_105 * V_104 )
{
unsigned int V_101 ;
if ( V_99 -> V_114 || V_100 -> V_114 ) {
F_39 ( V_104 ) ;
return;
}
V_104 -> V_114 = 0 ;
V_104 -> V_110 = F_30 ( V_99 -> V_110 , V_100 -> V_112 , & V_101 ) ;
V_104 -> V_111 = ( V_101 || V_99 -> V_111 || V_100 -> V_113 ) ;
if ( V_100 -> V_110 > 0 ) {
V_104 -> V_112 = F_30 ( V_99 -> V_112 , V_100 -> V_110 , & V_101 ) ;
if ( V_101 ) {
V_104 -> V_112 ++ ;
V_104 -> V_113 = 1 ;
} else
V_104 -> V_113 = ( V_99 -> V_113 || V_100 -> V_111 ) ;
} else {
V_104 -> V_112 = V_102 ;
V_104 -> V_113 = 0 ;
}
V_104 -> integer = 0 ;
}
void F_45 ( const struct V_105 * V_99 , const struct V_105 * V_100 ,
unsigned int V_115 , struct V_105 * V_104 )
{
unsigned int V_101 ;
if ( V_99 -> V_114 || V_100 -> V_114 ) {
F_39 ( V_104 ) ;
return;
}
V_104 -> V_114 = 0 ;
V_104 -> V_110 = F_34 ( V_99 -> V_110 , V_100 -> V_110 , V_115 , & V_101 ) ;
V_104 -> V_111 = ( V_101 || V_99 -> V_111 || V_100 -> V_111 ) ;
V_104 -> V_112 = F_34 ( V_99 -> V_112 , V_100 -> V_112 , V_115 , & V_101 ) ;
if ( V_101 ) {
V_104 -> V_112 ++ ;
V_104 -> V_113 = 1 ;
} else
V_104 -> V_113 = ( V_99 -> V_113 || V_100 -> V_113 ) ;
V_104 -> integer = 0 ;
}
void F_46 ( const struct V_105 * V_99 , unsigned int V_115 ,
const struct V_105 * V_100 , struct V_105 * V_104 )
{
unsigned int V_101 ;
if ( V_99 -> V_114 || V_100 -> V_114 ) {
F_39 ( V_104 ) ;
return;
}
V_104 -> V_114 = 0 ;
V_104 -> V_110 = F_34 ( V_99 -> V_110 , V_115 , V_100 -> V_112 , & V_101 ) ;
V_104 -> V_111 = ( V_101 || V_99 -> V_111 || V_100 -> V_113 ) ;
if ( V_100 -> V_110 > 0 ) {
V_104 -> V_112 = F_34 ( V_99 -> V_112 , V_115 , V_100 -> V_110 , & V_101 ) ;
if ( V_101 ) {
V_104 -> V_112 ++ ;
V_104 -> V_113 = 1 ;
} else
V_104 -> V_113 = ( V_99 -> V_113 || V_100 -> V_111 ) ;
} else {
V_104 -> V_112 = V_102 ;
V_104 -> V_113 = 0 ;
}
V_104 -> integer = 0 ;
}
int F_47 ( struct V_105 * V_106 ,
unsigned int V_116 , const struct V_117 * V_118 ,
unsigned int * V_119 , unsigned int * V_120 )
{
unsigned int V_121 , V_122 ;
int V_123 ;
unsigned int V_115 ;
struct V_105 V_124 ;
int V_9 ;
unsigned int V_125 , V_126 ;
int V_127 ;
V_121 = V_122 = V_123 = 0 ;
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 ) {
unsigned int V_128 = V_118 [ V_115 ] . V_128 ;
unsigned int V_129 ;
unsigned int V_103 = V_106 -> V_110 ;
int V_130 ;
if ( V_103 == 0 )
V_103 = 1 ;
V_129 = F_32 ( V_128 , V_103 ) ;
if ( V_129 < V_118 [ V_115 ] . V_131 )
continue;
if ( V_129 > V_118 [ V_115 ] . V_132 )
V_129 = V_118 [ V_115 ] . V_132 ;
else {
unsigned int V_101 ;
V_101 = ( V_129 - V_118 [ V_115 ] . V_131 ) % V_118 [ V_115 ] . V_133 ;
if ( V_101 != 0 )
V_129 -= V_101 ;
}
V_130 = V_128 - V_103 * V_129 ;
if ( V_130 < 0 )
V_130 = - V_130 ;
if ( V_121 == 0 ||
V_130 * V_122 < V_123 * V_129 ) {
V_123 = V_130 ;
V_122 = V_129 ;
V_121 = V_128 ;
}
}
if ( V_122 == 0 ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
V_124 . V_110 = F_31 ( V_121 , V_122 ) ;
V_124 . V_111 = ! ! ( V_121 % V_122 ) ;
V_125 = V_121 ;
V_127 = V_123 ;
V_126 = V_122 ;
V_121 = V_122 = V_123 = 0 ;
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 ) {
unsigned int V_128 = V_118 [ V_115 ] . V_128 ;
unsigned int V_129 ;
unsigned int V_103 = V_106 -> V_112 ;
int V_130 ;
if ( V_103 == 0 ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
V_129 = F_31 ( V_128 , V_103 ) ;
if ( V_129 > V_118 [ V_115 ] . V_132 )
continue;
if ( V_129 < V_118 [ V_115 ] . V_131 )
V_129 = V_118 [ V_115 ] . V_131 ;
else {
unsigned int V_101 ;
V_101 = ( V_129 - V_118 [ V_115 ] . V_131 ) % V_118 [ V_115 ] . V_133 ;
if ( V_101 != 0 )
V_129 += V_118 [ V_115 ] . V_133 - V_101 ;
}
V_130 = V_103 * V_129 - V_128 ;
if ( V_130 < 0 )
V_130 = - V_130 ;
if ( V_121 == 0 ||
V_130 * V_122 < V_123 * V_129 ) {
V_123 = V_130 ;
V_122 = V_129 ;
V_121 = V_128 ;
}
}
if ( V_122 == 0 ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
V_124 . V_112 = F_32 ( V_121 , V_122 ) ;
V_124 . V_113 = ! ! ( V_121 % V_122 ) ;
V_124 . integer = 0 ;
V_9 = F_36 ( V_106 , & V_124 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( F_41 ( V_106 ) ) {
if ( V_123 * V_126 < V_127 * V_122 ) {
V_125 = V_121 ;
V_126 = V_122 ;
}
if ( V_119 )
* V_119 = V_125 ;
if ( V_120 )
* V_120 = V_126 ;
}
return V_9 ;
}
static int F_48 ( struct V_105 * V_106 ,
unsigned int V_116 ,
const struct V_134 * V_118 ,
unsigned int * V_119 , unsigned int * V_120 )
{
unsigned int V_121 , V_123 , V_122 ;
unsigned int V_115 ;
struct V_105 V_124 ;
int V_9 ;
V_121 = V_122 = V_123 = 0 ;
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 ) {
unsigned int V_128 ;
unsigned int V_129 = V_118 [ V_115 ] . V_129 ;
unsigned int V_103 = V_106 -> V_110 ;
int V_130 ;
V_128 = F_33 ( V_103 , V_129 ) ;
if ( V_128 > V_118 [ V_115 ] . V_135 )
continue;
if ( V_128 < V_118 [ V_115 ] . V_136 )
V_128 = V_118 [ V_115 ] . V_135 ;
else {
unsigned int V_101 ;
V_101 = ( V_128 - V_118 [ V_115 ] . V_136 ) % V_118 [ V_115 ] . V_137 ;
if ( V_101 != 0 )
V_128 += V_118 [ V_115 ] . V_137 - V_101 ;
}
V_130 = V_128 - V_103 * V_129 ;
if ( V_121 == 0 ||
V_130 * V_122 < V_123 * V_129 ) {
V_123 = V_130 ;
V_122 = V_129 ;
V_121 = V_128 ;
}
}
if ( V_122 == 0 ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
V_124 . V_110 = F_31 ( V_121 , V_122 ) ;
V_124 . V_111 = ! ! ( V_121 % V_122 ) ;
V_121 = V_122 = V_123 = 0 ;
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 ) {
unsigned int V_128 ;
unsigned int V_129 = V_118 [ V_115 ] . V_129 ;
unsigned int V_103 = V_106 -> V_112 ;
int V_130 ;
V_128 = F_33 ( V_103 , V_129 ) ;
if ( V_128 < V_118 [ V_115 ] . V_136 )
continue;
if ( V_128 > V_118 [ V_115 ] . V_135 )
V_128 = V_118 [ V_115 ] . V_135 ;
else {
unsigned int V_101 ;
V_101 = ( V_128 - V_118 [ V_115 ] . V_136 ) % V_118 [ V_115 ] . V_137 ;
if ( V_101 != 0 )
V_128 -= V_101 ;
}
V_130 = V_103 * V_129 - V_128 ;
if ( V_121 == 0 ||
V_130 * V_122 < V_123 * V_129 ) {
V_123 = V_130 ;
V_122 = V_129 ;
V_121 = V_128 ;
}
}
if ( V_122 == 0 ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
V_124 . V_112 = F_32 ( V_121 , V_122 ) ;
V_124 . V_113 = ! ! ( V_121 % V_122 ) ;
V_124 . integer = 0 ;
V_9 = F_36 ( V_106 , & V_124 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( F_41 ( V_106 ) ) {
if ( V_119 )
* V_119 = V_121 ;
if ( V_120 )
* V_120 = V_122 ;
}
return V_9 ;
}
int F_49 ( struct V_105 * V_106 , unsigned int V_138 ,
const unsigned int * V_139 , unsigned int V_140 )
{
unsigned int V_115 ;
struct V_105 V_141 ;
if ( ! V_138 ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
F_50 ( & V_141 ) ;
V_141 . V_110 = V_102 ;
V_141 . V_112 = 0 ;
for ( V_115 = 0 ; V_115 < V_138 ; V_115 ++ ) {
if ( V_140 && ! ( V_140 & ( 1 << V_115 ) ) )
continue;
if ( ! F_51 ( V_106 , V_139 [ V_115 ] ) )
continue;
V_141 . V_110 = V_110 ( V_141 . V_110 , V_139 [ V_115 ] ) ;
V_141 . V_112 = V_112 ( V_141 . V_112 , V_139 [ V_115 ] ) ;
}
return F_36 ( V_106 , & V_141 ) ;
}
int F_52 ( struct V_105 * V_106 , unsigned int V_138 ,
const struct V_105 * V_142 , unsigned int V_140 )
{
unsigned int V_115 ;
struct V_105 V_143 ;
struct V_105 V_144 ;
if ( ! V_138 ) {
F_39 ( V_106 ) ;
return - V_109 ;
}
F_50 ( & V_143 ) ;
V_143 . V_110 = V_102 ;
V_143 . V_112 = 0 ;
for ( V_115 = 0 ; V_115 < V_138 ; V_115 ++ ) {
if ( V_140 && ! ( V_140 & ( 1 << V_115 ) ) )
continue;
F_53 ( & V_144 , & V_142 [ V_115 ] ) ;
if ( F_36 ( & V_144 , V_106 ) < 0 )
continue;
if ( F_37 ( & V_144 ) )
continue;
if ( V_144 . V_110 < V_143 . V_110 ) {
V_143 . V_110 = V_144 . V_110 ;
V_143 . V_111 = 1 ;
}
if ( V_144 . V_110 == V_143 . V_110 && ! V_144 . V_111 )
V_143 . V_111 = 0 ;
if ( V_144 . V_112 > V_143 . V_112 ) {
V_143 . V_112 = V_144 . V_112 ;
V_143 . V_113 = 1 ;
}
if ( V_144 . V_112 == V_143 . V_112 && ! V_144 . V_113 )
V_143 . V_113 = 0 ;
}
return F_36 ( V_106 , & V_143 ) ;
}
static int F_54 ( struct V_105 * V_106 , unsigned int V_145 )
{
unsigned int V_13 ;
int V_108 = 0 ;
V_13 = V_106 -> V_110 % V_145 ;
if ( V_13 != 0 || V_106 -> V_111 ) {
V_106 -> V_110 += V_145 - V_13 ;
V_106 -> V_111 = 0 ;
V_108 = 1 ;
}
V_13 = V_106 -> V_112 % V_145 ;
if ( V_13 != 0 || V_106 -> V_113 ) {
V_106 -> V_112 -= V_13 ;
V_106 -> V_113 = 0 ;
V_108 = 1 ;
}
if ( F_38 ( V_106 ) ) {
V_106 -> V_114 = 1 ;
return - V_109 ;
}
return V_108 ;
}
int F_55 ( struct V_4 * V_5 , unsigned int V_146 ,
int V_147 ,
T_6 V_148 , void * V_149 ,
int V_150 , ... )
{
struct V_151 * V_152 = & V_5 -> V_153 ;
struct V_154 * V_104 ;
unsigned int V_115 ;
T_7 args ;
va_start ( args , V_150 ) ;
if ( V_152 -> V_155 >= V_152 -> V_156 ) {
struct V_154 * V_157 ;
unsigned int V_158 = V_152 -> V_156 + 16 ;
V_157 = F_56 ( V_158 , sizeof( * V_104 ) , V_159 ) ;
if ( ! V_157 ) {
va_end ( args ) ;
return - V_160 ;
}
if ( V_152 -> V_161 ) {
memcpy ( V_157 , V_152 -> V_161 ,
V_152 -> V_155 * sizeof( * V_104 ) ) ;
F_57 ( V_152 -> V_161 ) ;
}
V_152 -> V_161 = V_157 ;
V_152 -> V_156 = V_158 ;
}
V_104 = & V_152 -> V_161 [ V_152 -> V_155 ] ;
V_104 -> V_146 = V_146 ;
V_104 -> V_148 = V_148 ;
V_104 -> V_147 = V_147 ;
V_104 -> V_149 = V_149 ;
V_115 = 0 ;
while ( 1 ) {
if ( F_4 ( V_115 >= F_58 ( V_104 -> V_162 ) ) ) {
va_end ( args ) ;
return - V_109 ;
}
V_104 -> V_162 [ V_115 ++ ] = V_150 ;
if ( V_150 < 0 )
break;
V_150 = va_arg ( args , int ) ;
}
V_152 -> V_155 ++ ;
va_end ( args ) ;
return 0 ;
}
int F_59 ( struct V_4 * V_5 , T_8 V_147 ,
T_9 V_140 )
{
struct V_151 * V_152 = & V_5 -> V_153 ;
struct V_163 * V_164 = F_60 ( V_152 , V_147 ) ;
* V_164 -> V_165 &= V_140 ;
memset ( V_164 -> V_165 + 1 , 0 , ( V_166 - 32 ) / 8 ) ;
if ( * V_164 -> V_165 == 0 )
return - V_109 ;
return 0 ;
}
int F_61 ( struct V_4 * V_5 , T_8 V_147 ,
T_5 V_140 )
{
struct V_151 * V_152 = & V_5 -> V_153 ;
struct V_163 * V_164 = F_60 ( V_152 , V_147 ) ;
V_164 -> V_165 [ 0 ] &= ( T_9 ) V_140 ;
V_164 -> V_165 [ 1 ] &= ( T_9 ) ( V_140 >> 32 ) ;
memset ( V_164 -> V_165 + 2 , 0 , ( V_166 - 64 ) / 8 ) ;
if ( ! V_164 -> V_165 [ 0 ] && ! V_164 -> V_165 [ 1 ] )
return - V_109 ;
return 0 ;
}
int F_62 ( struct V_4 * V_5 , T_8 V_147 )
{
struct V_151 * V_152 = & V_5 -> V_153 ;
return F_63 ( F_64 ( V_152 , V_147 ) ) ;
}
int F_65 ( struct V_4 * V_5 , T_8 V_147 ,
unsigned int V_110 , unsigned int V_112 )
{
struct V_151 * V_152 = & V_5 -> V_153 ;
struct V_105 V_124 ;
V_124 . V_110 = V_110 ;
V_124 . V_112 = V_112 ;
V_124 . V_111 = V_124 . V_113 = 0 ;
V_124 . integer = 0 ;
return F_36 ( F_64 ( V_152 , V_147 ) , & V_124 ) ;
}
static int F_66 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
struct V_170 * V_139 = V_169 -> V_149 ;
return F_49 ( F_67 ( V_168 , V_169 -> V_147 ) , V_139 -> V_138 , V_139 -> V_139 , V_139 -> V_140 ) ;
}
int V_170 ( struct V_4 * V_5 ,
unsigned int V_146 ,
T_8 V_147 ,
const struct V_170 * V_171 )
{
return F_55 ( V_5 , V_146 , V_147 ,
F_66 , ( void * ) V_171 ,
V_147 , - 1 ) ;
}
static int F_68 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
struct V_172 * V_101 = V_169 -> V_149 ;
return F_52 ( F_67 ( V_168 , V_169 -> V_147 ) ,
V_101 -> V_138 , V_101 -> V_142 , V_101 -> V_140 ) ;
}
int V_172 ( struct V_4 * V_5 ,
unsigned int V_146 ,
T_8 V_147 ,
const struct V_172 * V_101 )
{
return F_55 ( V_5 , V_146 , V_147 ,
F_68 , ( void * ) V_101 ,
V_147 , - 1 ) ;
}
static int F_69 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
const struct V_173 * V_101 = V_169 -> V_149 ;
unsigned int V_128 = 0 , V_129 = 0 ;
int V_9 ;
V_9 = F_47 ( F_67 ( V_168 , V_169 -> V_147 ) ,
V_101 -> V_174 , V_101 -> V_118 , & V_128 , & V_129 ) ;
if ( V_9 >= 0 && V_129 && V_169 -> V_147 == V_175 ) {
V_168 -> V_176 = V_128 ;
V_168 -> V_177 = V_129 ;
}
return V_9 ;
}
int V_173 ( struct V_4 * V_5 ,
unsigned int V_146 ,
T_8 V_147 ,
const struct V_173 * V_101 )
{
return F_55 ( V_5 , V_146 , V_147 ,
F_69 , ( void * ) V_101 ,
V_147 , - 1 ) ;
}
static int F_70 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
const struct V_178 * V_101 = V_169 -> V_149 ;
unsigned int V_128 = 0 , V_129 = 0 ;
int V_9 = F_48 ( F_67 ( V_168 , V_169 -> V_147 ) ,
V_101 -> V_174 , V_101 -> V_118 , & V_128 , & V_129 ) ;
if ( V_9 >= 0 && V_129 && V_169 -> V_147 == V_175 ) {
V_168 -> V_176 = V_128 ;
V_168 -> V_177 = V_129 ;
}
return V_9 ;
}
int V_178 ( struct V_4 * V_5 ,
unsigned int V_146 ,
T_8 V_147 ,
const struct V_178 * V_101 )
{
return F_55 ( V_5 , V_146 , V_147 ,
F_70 , ( void * ) V_101 ,
V_147 , - 1 ) ;
}
static int F_71 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
unsigned int V_171 = ( unsigned long ) V_169 -> V_149 ;
int V_179 = V_171 & 0xffff ;
unsigned int V_180 = V_171 >> 16 ;
const struct V_105 * V_106 =
F_72 ( V_168 , V_181 ) ;
if ( ! F_41 ( V_106 ) )
return 0 ;
if ( ( F_73 ( V_106 ) == V_179 ) ||
( V_179 == 0 && F_73 ( V_106 ) > V_180 ) )
V_168 -> V_180 = F_74 ( V_168 -> V_180 , V_180 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_5 ,
unsigned int V_146 ,
unsigned int V_179 ,
unsigned int V_180 )
{
unsigned long V_171 = ( V_180 << 16 ) | V_179 ;
return F_55 ( V_5 , V_146 , - 1 ,
F_71 ,
( void * ) V_171 ,
V_181 , - 1 ) ;
}
static int F_76 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
unsigned long V_145 = ( unsigned long ) V_169 -> V_149 ;
return F_54 ( F_67 ( V_168 , V_169 -> V_147 ) , V_145 ) ;
}
int F_77 ( struct V_4 * V_5 ,
unsigned int V_146 ,
T_8 V_147 ,
unsigned long V_145 )
{
return F_55 ( V_5 , V_146 , V_147 ,
F_76 , ( void * ) V_145 ,
V_147 , - 1 ) ;
}
static int F_78 ( struct V_167 * V_168 , struct V_154 * V_169 )
{
static unsigned int V_182 [] = {
1 << 0 , 1 << 1 , 1 << 2 , 1 << 3 , 1 << 4 , 1 << 5 , 1 << 6 , 1 << 7 ,
1 << 8 , 1 << 9 , 1 << 10 , 1 << 11 , 1 << 12 , 1 << 13 , 1 << 14 , 1 << 15 ,
1 << 16 , 1 << 17 , 1 << 18 , 1 << 19 , 1 << 20 , 1 << 21 , 1 << 22 , 1 << 23 ,
1 << 24 , 1 << 25 , 1 << 26 , 1 << 27 , 1 << 28 , 1 << 29 , 1 << 30
} ;
return F_49 ( F_67 ( V_168 , V_169 -> V_147 ) ,
F_58 ( V_182 ) , V_182 , 0 ) ;
}
int F_79 ( struct V_4 * V_5 ,
unsigned int V_146 ,
T_8 V_147 )
{
return F_55 ( V_5 , V_146 , V_147 ,
F_78 , NULL ,
V_147 , - 1 ) ;
}
static int F_80 ( struct V_167 * V_168 ,
struct V_154 * V_169 )
{
unsigned int V_183 = ( unsigned int ) ( V_184 ) V_169 -> V_149 ;
struct V_105 * V_61 ;
V_61 = F_67 ( V_168 , V_175 ) ;
return F_49 ( V_61 , 1 , & V_183 , 0 ) ;
}
int F_81 ( struct V_4 * V_5 ,
unsigned int V_183 )
{
return F_55 ( V_5 , V_185 ,
V_175 ,
F_80 ,
( void * ) ( V_184 ) V_183 ,
V_175 , - 1 ) ;
}
static void F_82 ( struct V_167 * V_168 ,
T_8 V_147 )
{
if ( F_83 ( V_147 ) ) {
F_84 ( F_85 ( V_168 , V_147 ) ) ;
V_168 -> V_186 |= 1 << V_147 ;
V_168 -> V_187 |= 1 << V_147 ;
return;
}
if ( F_86 ( V_147 ) ) {
F_50 ( F_67 ( V_168 , V_147 ) ) ;
V_168 -> V_186 |= 1 << V_147 ;
V_168 -> V_187 |= 1 << V_147 ;
return;
}
F_87 () ;
}
void F_88 ( struct V_167 * V_168 )
{
unsigned int V_115 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
for ( V_115 = V_188 ; V_115 <= V_189 ; V_115 ++ )
F_82 ( V_168 , V_115 ) ;
for ( V_115 = V_190 ; V_115 <= V_191 ; V_115 ++ )
F_82 ( V_168 , V_115 ) ;
V_168 -> V_89 = ~ 0U ;
}
int F_89 ( const struct V_167 * V_168 ,
T_8 V_147 , int * V_192 )
{
if ( F_83 ( V_147 ) ) {
const struct V_163 * V_140 = F_90 ( V_168 , V_147 ) ;
if ( ! F_91 ( V_140 ) )
return - V_109 ;
if ( V_192 )
* V_192 = 0 ;
return F_92 ( V_140 ) ;
}
if ( F_86 ( V_147 ) ) {
const struct V_105 * V_106 = F_72 ( V_168 , V_147 ) ;
if ( ! F_41 ( V_106 ) )
return - V_109 ;
if ( V_192 )
* V_192 = V_106 -> V_111 ;
return F_73 ( V_106 ) ;
}
return - V_109 ;
}
void F_93 ( struct V_167 * V_168 ,
T_8 V_147 )
{
if ( F_83 ( V_147 ) ) {
F_94 ( F_85 ( V_168 , V_147 ) ) ;
V_168 -> V_186 |= 1 << V_147 ;
V_168 -> V_187 |= 1 << V_147 ;
} else if ( F_86 ( V_147 ) ) {
F_39 ( F_67 ( V_168 , V_147 ) ) ;
V_168 -> V_186 |= 1 << V_147 ;
V_168 -> V_187 |= 1 << V_147 ;
} else {
F_87 () ;
}
}
static int F_95 ( struct V_167 * V_168 ,
T_8 V_147 )
{
int V_108 ;
if ( F_83 ( V_147 ) )
V_108 = F_96 ( F_85 ( V_168 , V_147 ) ) ;
else if ( F_86 ( V_147 ) )
V_108 = F_40 ( F_67 ( V_168 , V_147 ) ) ;
else
return - V_109 ;
if ( V_108 ) {
V_168 -> V_186 |= 1 << V_147 ;
V_168 -> V_187 |= 1 << V_147 ;
}
return V_108 ;
}
int F_97 ( struct V_1 * V_26 ,
struct V_167 * V_168 ,
T_8 V_147 , int * V_192 )
{
int V_108 = F_95 ( V_168 , V_147 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_168 -> V_187 ) {
int V_9 = F_98 ( V_26 , V_168 ) ;
if ( F_4 ( V_9 < 0 ) )
return V_9 ;
}
return F_89 ( V_168 , V_147 , V_192 ) ;
}
static int F_99 ( struct V_167 * V_168 ,
T_8 V_147 )
{
int V_108 ;
if ( F_83 ( V_147 ) )
V_108 = F_100 ( F_85 ( V_168 , V_147 ) ) ;
else if ( F_86 ( V_147 ) )
V_108 = F_42 ( F_67 ( V_168 , V_147 ) ) ;
else
return - V_109 ;
if ( V_108 ) {
V_168 -> V_186 |= 1 << V_147 ;
V_168 -> V_187 |= 1 << V_147 ;
}
return V_108 ;
}
int F_101 ( struct V_1 * V_26 ,
struct V_167 * V_168 ,
T_8 V_147 , int * V_192 )
{
int V_108 = F_99 ( V_168 , V_147 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_168 -> V_187 ) {
int V_9 = F_98 ( V_26 , V_168 ) ;
if ( F_4 ( V_9 < 0 ) )
return V_9 ;
}
return F_89 ( V_168 , V_147 , V_192 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
void * V_193 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_194 ;
F_103 ( V_2 , V_194 ) ;
if ( F_104 ( V_2 ) &&
F_27 ( V_2 ) >= 0 )
V_5 -> V_22 -> V_23 %= V_5 -> V_18 ;
else {
V_5 -> V_22 -> V_23 = 0 ;
V_5 -> V_57 = 0 ;
}
F_105 ( V_2 , V_194 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
void * V_193 )
{
struct V_195 * V_89 = V_193 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_179 ;
if ( ! ( V_5 -> V_89 & V_196 ) ) {
V_89 -> V_197 = - 1 ;
return 0 ;
}
V_179 = F_107 ( V_5 -> V_198 ) ;
if ( V_179 < 0 )
return V_179 ;
V_89 -> V_197 = 0 ;
switch ( V_5 -> V_199 ) {
case V_200 :
case V_201 :
V_89 -> V_202 = V_89 -> V_203 * V_179 ;
V_89 -> V_145 = V_5 -> V_204 * V_179 ;
break;
case V_205 :
case V_206 :
{
T_3 V_207 = V_5 -> V_208 / V_5 -> V_204 ;
V_89 -> V_202 = V_89 -> V_203 * V_207 * 8 ;
V_89 -> V_145 = V_179 ;
break;
}
default:
F_87 () ;
break;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
void * V_193 )
{
struct V_167 * V_168 = V_193 ;
T_10 V_198 ;
int V_204 ;
T_11 V_209 ;
V_168 -> V_210 = V_2 -> V_5 -> V_88 . V_210 ;
if ( ! ( V_2 -> V_5 -> V_88 . V_89 & V_211 ) ) {
V_198 = F_109 ( V_168 ) ;
V_204 = F_110 ( V_168 ) ;
V_209 = F_111 ( V_198 , V_204 ) ;
if ( V_209 > 0 )
V_168 -> V_210 /= ( unsigned ) V_209 ;
}
return 0 ;
}
int F_112 ( struct V_1 * V_2 ,
unsigned int V_212 , void * V_193 )
{
switch ( V_212 ) {
case V_213 :
return F_102 ( V_2 , V_193 ) ;
case V_214 :
return F_106 ( V_2 , V_193 ) ;
case V_215 :
return F_108 ( V_2 , V_193 ) ;
}
return - V_216 ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_194 ;
if ( F_114 ( V_2 ) )
return;
V_5 = V_2 -> V_5 ;
F_103 ( V_2 , V_194 ) ;
if ( ! F_104 ( V_2 ) ||
F_22 ( V_2 , 1 ) < 0 )
goto V_217;
#ifdef F_115
if ( V_2 -> V_218 )
F_116 ( V_2 -> V_219 , 1 ) ;
#endif
V_217:
F_117 ( & V_5 -> V_220 , V_221 , V_222 ) ;
F_105 ( V_2 , V_194 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
T_1 * V_223 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_224 = V_2 -> V_30 == V_37 ;
T_12 V_225 ;
int V_9 = 0 ;
T_1 V_21 = 0 ;
long V_226 , V_227 ;
F_119 ( & V_225 , V_228 ) ;
F_120 ( V_229 ) ;
F_121 ( & V_5 -> V_44 , & V_225 ) ;
if ( V_5 -> V_82 )
V_226 = V_230 ;
else {
V_226 = 10 ;
if ( V_5 -> V_61 ) {
long V_124 = V_5 -> V_75 * 2 / V_5 -> V_61 ;
V_226 = V_112 ( V_124 , V_226 ) ;
}
V_226 = F_122 ( V_226 * 1000 ) ;
}
for (; ; ) {
if ( F_123 ( V_228 ) ) {
V_9 = - V_231 ;
break;
}
if ( V_224 )
V_21 = F_15 ( V_5 ) ;
else
V_21 = F_16 ( V_5 ) ;
if ( V_21 >= V_5 -> V_43 )
break;
F_124 ( V_2 ) ;
V_227 = F_125 ( V_226 ) ;
F_126 ( V_2 ) ;
F_120 ( V_229 ) ;
switch ( V_5 -> V_22 -> V_39 ) {
case V_232 :
V_9 = - V_233 ;
goto V_234;
case V_35 :
V_9 = - V_41 ;
goto V_234;
case V_40 :
if ( V_224 )
V_9 = - V_41 ;
else
V_21 = 0 ;
goto V_234;
case V_235 :
case V_236 :
case V_237 :
V_9 = - V_238 ;
goto V_234;
case V_239 :
continue;
}
if ( ! V_227 ) {
F_127 ( V_2 -> V_26 ,
L_10 ,
V_224 ? L_11 : L_12 ) ;
V_9 = - V_240 ;
break;
}
}
V_234:
F_120 ( V_241 ) ;
F_128 ( & V_5 -> V_44 , & V_225 ) ;
* V_223 = V_21 ;
return V_9 ;
}
static void * F_129 ( struct V_4 * V_5 ,
int V_203 , unsigned long V_242 )
{
return V_5 -> V_243 + V_242 +
V_203 * ( V_5 -> V_208 / V_5 -> V_204 ) ;
}
static int F_130 ( struct V_1 * V_2 ,
int V_203 , unsigned long V_242 ,
void * V_244 , unsigned long V_245 )
{
if ( F_131 ( F_129 ( V_2 -> V_5 , V_203 , V_242 ) ,
( void V_246 * ) V_244 , V_245 ) )
return - V_247 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 ,
int V_203 , unsigned long V_242 ,
void * V_244 , unsigned long V_245 )
{
memcpy ( F_129 ( V_2 -> V_5 , V_203 , V_242 ) , V_244 , V_245 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , int V_203 ,
unsigned long V_242 , void * V_244 , unsigned long V_245 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_30 != V_37 )
return 0 ;
if ( V_2 -> V_52 -> F_133 )
return V_2 -> V_52 -> F_133 ( V_2 , V_203 ,
V_242 , V_245 ) ;
F_134 ( V_5 -> V_198 ,
F_129 ( V_5 , V_203 , V_242 ) ,
F_135 ( V_5 , V_245 ) ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 ,
int V_203 , unsigned long V_242 ,
void * V_244 , unsigned long V_245 )
{
if ( F_137 ( ( void V_246 * ) V_244 ,
F_129 ( V_2 -> V_5 , V_203 , V_242 ) ,
V_245 ) )
return - V_247 ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 ,
int V_203 , unsigned long V_242 ,
void * V_244 , unsigned long V_245 )
{
memcpy ( V_244 , F_129 ( V_2 -> V_5 , V_203 , V_242 ) , V_245 ) ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 ,
T_1 V_242 , void * V_248 ,
T_1 V_249 ,
T_1 V_6 ,
T_13 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_242 = F_140 ( V_5 , V_242 ) ;
V_249 = F_140 ( V_5 , V_249 ) ;
V_6 = F_140 ( V_5 , V_6 ) ;
return V_8 ( V_2 , 0 , V_242 , V_248 + V_249 , V_6 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
T_1 V_242 , void * V_248 ,
T_1 V_249 ,
T_1 V_6 ,
T_13 V_8 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_204 = V_5 -> V_204 ;
void * * V_250 = V_248 ;
int V_104 , V_9 ;
V_249 = F_142 ( V_5 , V_249 ) ;
V_6 = F_142 ( V_5 , V_6 ) ;
V_242 = F_142 ( V_5 , V_242 ) ;
for ( V_104 = 0 ; V_104 < V_204 ; ++ V_104 , ++ V_250 ) {
if ( ! V_248 || ! * V_250 )
V_9 = F_133 ( V_2 , V_104 , V_242 , NULL , V_6 ) ;
else
V_9 = V_8 ( V_2 , V_104 , V_242 , * V_250 + V_249 ,
V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_249 , T_1 V_6 )
{
if ( V_2 -> V_5 -> V_199 == V_201 ||
V_2 -> V_5 -> V_199 == V_200 )
return F_139 ( V_2 , V_249 , NULL , 0 , V_6 ,
F_133 ) ;
else
return F_141 ( V_2 , V_249 , NULL , 0 , V_6 ,
F_133 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( F_114 ( V_2 ) )
return - V_216 ;
V_5 = V_2 -> V_5 ;
if ( F_4 ( ! V_2 -> V_52 -> V_251 && ! V_5 -> V_243 ) )
return - V_109 ;
if ( V_5 -> V_22 -> V_39 == V_235 )
return - V_238 ;
return 0 ;
}
static int F_144 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_22 -> V_39 ) {
case V_252 :
case V_253 :
case V_239 :
return 0 ;
case V_35 :
return - V_41 ;
case V_232 :
return - V_233 ;
default:
return - V_238 ;
}
}
int F_145 ( struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_254 = V_5 -> V_15 -> V_14 ;
int V_255 ;
if ( V_254 == V_14 )
return 0 ;
V_5 -> V_15 -> V_14 = V_14 ;
if ( V_2 -> V_52 -> V_256 ) {
V_255 = V_2 -> V_52 -> V_256 ( V_2 ) ;
if ( V_255 < 0 ) {
V_5 -> V_15 -> V_14 = V_254 ;
return V_255 ;
}
}
F_146 ( V_2 , V_254 , V_14 ) ;
return 0 ;
}
T_2 F_147 ( struct V_1 * V_2 ,
void * V_248 , bool V_257 ,
T_1 V_207 , bool V_258 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_259 = 0 ;
T_1 V_197 = 0 ;
T_1 V_21 ;
T_14 V_260 ;
T_13 V_8 ;
bool V_261 ;
bool V_224 ;
int V_9 ;
V_9 = F_143 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_224 = V_2 -> V_30 == V_37 ;
if ( V_257 ) {
if ( V_5 -> V_199 != V_201 &&
V_5 -> V_204 > 1 )
return - V_109 ;
V_260 = F_139 ;
} else {
if ( V_5 -> V_199 != V_206 )
return - V_109 ;
V_260 = F_141 ;
}
if ( ! V_248 ) {
if ( V_224 )
V_8 = F_133 ;
else
return - V_109 ;
} else if ( V_258 ) {
if ( V_2 -> V_52 -> V_262 )
V_8 = V_2 -> V_52 -> V_262 ;
else
V_8 = V_224 ?
F_132 : F_138 ;
} else {
if ( V_2 -> V_52 -> V_251 )
V_8 = ( T_13 ) V_2 -> V_52 -> V_251 ;
else
V_8 = V_224 ?
F_130 : F_136 ;
}
if ( V_207 == 0 )
return 0 ;
V_261 = ! ! ( V_2 -> V_263 & V_264 ) ;
F_126 ( V_2 ) ;
V_9 = F_144 ( V_5 ) ;
if ( V_9 < 0 )
goto V_265;
if ( ! V_224 &&
V_5 -> V_22 -> V_39 == V_252 &&
V_207 >= V_5 -> V_266 ) {
V_9 = F_148 ( V_2 ) ;
if ( V_9 < 0 )
goto V_265;
}
V_5 -> V_43 = V_5 -> V_15 -> V_45 ? : 1 ;
if ( V_5 -> V_22 -> V_39 == V_253 )
F_27 ( V_2 ) ;
if ( V_224 )
V_21 = F_15 ( V_5 ) ;
else
V_21 = F_16 ( V_5 ) ;
while ( V_207 > 0 ) {
T_1 V_6 , V_14 , V_267 ;
T_1 V_268 ;
if ( ! V_21 ) {
if ( ! V_224 &&
V_5 -> V_22 -> V_39 == V_40 ) {
F_10 ( V_2 , V_236 ) ;
goto V_265;
}
if ( V_261 ) {
V_9 = - V_269 ;
goto V_265;
}
V_5 -> V_43 = F_149 ( T_1 , V_207 ,
V_5 -> V_15 -> V_45 ? : 1 ) ;
V_9 = F_118 ( V_2 , & V_21 ) ;
if ( V_9 < 0 )
goto V_265;
if ( ! V_21 )
continue;
}
V_6 = V_207 > V_21 ? V_21 : V_207 ;
V_14 = F_2 ( V_5 -> V_15 -> V_14 ) ;
V_267 = V_14 % V_5 -> V_18 ;
V_268 = V_5 -> V_18 - V_267 ;
if ( V_6 > V_268 )
V_6 = V_268 ;
if ( F_4 ( ! V_6 ) ) {
V_5 -> V_43 = 0 ;
F_124 ( V_2 ) ;
return - V_109 ;
}
F_124 ( V_2 ) ;
V_9 = V_260 ( V_2 , V_267 , V_248 , V_197 , V_6 ,
V_8 ) ;
F_126 ( V_2 ) ;
if ( V_9 < 0 )
goto V_265;
V_9 = F_144 ( V_5 ) ;
if ( V_9 < 0 )
goto V_265;
V_14 += V_6 ;
if ( V_14 >= V_5 -> V_11 )
V_14 -= V_5 -> V_11 ;
V_9 = F_145 ( V_2 , V_14 ) ;
if ( V_9 < 0 )
goto V_265;
V_197 += V_6 ;
V_207 -= V_6 ;
V_259 += V_6 ;
V_21 -= V_6 ;
if ( V_224 &&
V_5 -> V_22 -> V_39 == V_252 &&
F_3 ( V_5 ) >= ( T_2 ) V_5 -> V_266 ) {
V_9 = F_148 ( V_2 ) ;
if ( V_9 < 0 )
goto V_265;
}
}
V_265:
V_5 -> V_43 = 0 ;
if ( V_259 > 0 && V_9 >= 0 )
F_14 ( V_2 , V_5 ) ;
F_124 ( V_2 ) ;
return V_259 > 0 ? ( T_2 ) V_259 : V_9 ;
}
static bool F_150 ( const struct V_270 * V_89 , int V_271 )
{
if ( V_271 > V_89 -> V_272 )
return false ;
return ! V_89 -> V_273 || ( V_89 -> V_273 & ( 1U << V_271 ) ) ;
}
static int F_151 ( struct V_274 * V_275 ,
struct V_276 * V_277 )
{
struct V_270 * V_89 = F_152 ( V_275 ) ;
V_277 -> type = V_278 ;
V_277 -> V_138 = 0 ;
V_277 -> V_138 = V_89 -> V_272 ;
V_277 -> V_279 . integer . V_110 = 0 ;
V_277 -> V_279 . integer . V_112 = V_280 ;
return 0 ;
}
static int F_153 ( struct V_274 * V_275 ,
struct V_281 * V_282 )
{
struct V_270 * V_89 = F_152 ( V_275 ) ;
unsigned int V_283 = F_154 ( V_275 , & V_282 -> V_284 ) ;
struct V_1 * V_2 ;
const struct V_285 * V_286 ;
if ( ! V_89 -> V_287 )
return - V_109 ;
V_2 = F_155 ( V_89 , V_283 ) ;
if ( ! V_2 )
return - V_288 ;
memset ( V_282 -> V_279 . integer . V_279 , 0 ,
sizeof( V_282 -> V_279 . integer . V_279 ) ) ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_286 = V_89 -> V_287 ; V_286 -> V_204 ; V_286 ++ ) {
int V_106 ;
if ( V_286 -> V_204 == V_2 -> V_5 -> V_204 &&
F_150 ( V_89 , V_286 -> V_204 ) ) {
for ( V_106 = 0 ; V_106 < V_286 -> V_204 ; V_106 ++ )
V_282 -> V_279 . integer . V_279 [ V_106 ] = V_286 -> V_286 [ V_106 ] ;
return 0 ;
}
}
return - V_109 ;
}
static int F_156 ( struct V_274 * V_275 , int V_289 ,
unsigned int V_207 , unsigned int V_246 * V_290 )
{
struct V_270 * V_89 = F_152 ( V_275 ) ;
const struct V_285 * V_286 ;
unsigned int V_246 * V_291 ;
int V_104 , V_138 = 0 ;
if ( ! V_89 -> V_287 )
return - V_109 ;
if ( V_207 < 8 )
return - V_160 ;
if ( F_157 ( V_292 , V_290 ) )
return - V_247 ;
V_207 -= 8 ;
V_291 = V_290 + 2 ;
for ( V_286 = V_89 -> V_287 ; V_286 -> V_204 ; V_286 ++ ) {
int V_293 = V_286 -> V_204 * 4 ;
if ( ! F_150 ( V_89 , V_286 -> V_204 ) )
continue;
if ( V_207 < 8 )
return - V_160 ;
if ( F_157 ( V_294 , V_291 ) ||
F_157 ( V_293 , V_291 + 1 ) )
return - V_247 ;
V_291 += 2 ;
V_207 -= 8 ;
V_138 += 8 ;
if ( V_207 < V_293 )
return - V_160 ;
V_207 -= V_293 ;
V_138 += V_293 ;
for ( V_104 = 0 ; V_104 < V_286 -> V_204 ; V_104 ++ ) {
if ( F_157 ( V_286 -> V_286 [ V_104 ] , V_291 ) )
return - V_247 ;
V_291 ++ ;
}
}
if ( F_157 ( V_138 , V_290 + 1 ) )
return - V_247 ;
return 0 ;
}
static void F_158 ( struct V_274 * V_275 )
{
struct V_270 * V_89 = F_152 ( V_275 ) ;
V_89 -> V_26 -> V_95 [ V_89 -> V_30 ] . V_295 = NULL ;
F_57 ( V_89 ) ;
}
int F_159 ( struct V_91 * V_26 , int V_30 ,
const struct V_285 * V_287 ,
int V_272 ,
unsigned long V_296 ,
struct V_270 * * V_297 )
{
struct V_270 * V_89 ;
struct V_298 V_299 = {
. V_300 = V_301 ,
. V_199 = V_302 |
V_303 |
V_304 ,
. V_89 = F_151 ,
. V_305 = F_153 ,
. V_290 . V_104 = F_156 ,
} ;
int V_9 ;
if ( F_160 ( V_26 -> V_95 [ V_30 ] . V_295 ) )
return - V_306 ;
V_89 = F_161 ( sizeof( * V_89 ) , V_159 ) ;
if ( ! V_89 )
return - V_160 ;
V_89 -> V_26 = V_26 ;
V_89 -> V_30 = V_30 ;
V_89 -> V_287 = V_287 ;
V_89 -> V_272 = V_272 ;
if ( V_30 == V_37 )
V_299 . V_24 = L_13 ;
else
V_299 . V_24 = L_14 ;
V_299 . V_29 = V_26 -> V_29 ;
V_299 . V_138 = V_26 -> V_95 [ V_30 ] . V_307 ;
V_299 . V_296 = V_296 ;
V_89 -> V_308 = F_162 ( & V_299 , V_89 ) ;
if ( ! V_89 -> V_308 ) {
F_57 ( V_89 ) ;
return - V_160 ;
}
V_89 -> V_308 -> V_309 = F_158 ;
V_9 = F_163 ( V_26 -> V_27 , V_89 -> V_308 ) ;
if ( V_9 < 0 )
return V_9 ;
V_26 -> V_95 [ V_30 ] . V_295 = V_89 -> V_308 ;
if ( V_297 )
* V_297 = V_89 ;
return 0 ;
}
