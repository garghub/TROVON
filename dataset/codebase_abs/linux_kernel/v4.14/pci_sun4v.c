static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_7 = 0 ;
}
static long F_3 ( struct V_5 * V_6 , T_1 V_8 )
{
struct V_9 * V_10 = V_6 -> V_2 -> V_11 . V_12 ;
T_1 * V_13 = V_6 -> V_13 ;
T_1 V_14 ;
unsigned long V_15 = V_10 -> V_15 ;
unsigned long V_3 = V_6 -> V_3 ;
unsigned long V_4 = V_6 -> V_4 ;
unsigned long V_7 = V_6 -> V_7 ;
unsigned long V_16 ;
unsigned long V_17 ;
long V_18 ;
if ( V_19 < 2 )
V_3 &= ( V_20 | V_21 ) ;
while ( V_7 != 0 ) {
if ( V_8 <= F_4 ( 32 ) ) {
V_18 = F_5 ( V_15 ,
F_6 ( 0 , V_4 ) ,
V_7 ,
V_3 ,
F_7 ( V_13 ) ) ;
if ( F_8 ( V_18 < 0 ) ) {
F_9 ( L_1 ,
V_22 ,
V_15 ,
F_6 ( 0 , V_4 ) ,
V_7 , V_3 , F_7 ( V_13 ) ,
V_18 ) ;
return - 1 ;
}
} else {
V_14 = F_10 ( V_7 , V_4 ) ,
V_16 = V_10 -> V_23 -> V_24 -> V_25 -> V_16 ;
V_17 = F_11 ( V_15 ,
V_16 ,
V_14 ,
V_3 ,
F_7 ( V_13 ) ,
& V_18 ) ;
if ( F_8 ( V_17 != V_26 ) ) {
F_9 ( L_2 ,
V_22 ,
V_15 , V_16 ,
V_14 , V_3 ,
F_7 ( V_13 ) , V_17 ) ;
return - 1 ;
}
}
V_4 += V_18 ;
V_7 -= V_18 ;
V_13 += V_18 ;
}
V_6 -> V_4 = V_4 ;
V_6 -> V_7 = 0 ;
return 0 ;
}
static inline void F_12 ( unsigned long V_4 , T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
if ( V_6 -> V_4 + V_6 -> V_7 == V_4 )
return;
if ( V_6 -> V_4 != ~ 0UL )
F_3 ( V_6 , V_8 ) ;
V_6 -> V_4 = V_4 ;
}
static inline long F_13 ( T_1 V_27 , T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
F_14 ( V_6 -> V_7 >= V_28 ) ;
V_6 -> V_13 [ V_6 -> V_7 ++ ] = V_27 ;
if ( V_6 -> V_7 == V_28 )
return F_3 ( V_6 , V_8 ) ;
return 0 ;
}
static inline long F_15 ( T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
F_14 ( V_6 -> V_7 >= V_28 ) ;
return F_3 ( V_6 , V_8 ) ;
}
static void * F_16 ( struct V_1 * V_2 , T_2 V_29 ,
T_3 * V_30 , T_4 V_31 ,
unsigned long V_32 )
{
T_1 V_8 ;
unsigned long V_33 , V_34 , V_35 , V_7 , V_36 ;
unsigned long V_3 = 0 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
struct V_37 * V_38 ;
struct V_39 * V_39 ;
void * V_17 ;
long V_4 ;
int V_40 ;
V_29 = F_17 ( V_29 ) ;
V_34 = F_18 ( V_29 ) ;
if ( F_8 ( V_34 >= V_41 ) )
return NULL ;
V_7 = V_29 >> V_42 ;
if ( V_32 & V_43 )
V_3 = V_44 ;
V_40 = V_2 -> V_11 . V_45 ;
V_39 = F_19 ( V_40 , V_31 , V_34 ) ;
if ( F_8 ( ! V_39 ) )
return NULL ;
V_35 = ( unsigned long ) F_20 ( V_39 ) ;
memset ( ( char * ) V_35 , 0 , V_46 << V_34 ) ;
V_23 = V_2 -> V_11 . V_23 ;
V_24 = V_23 -> V_24 ;
V_8 = V_2 -> V_47 ;
if ( V_8 <= F_4 ( 32 ) )
V_38 = & V_23 -> V_38 ;
else
V_38 = & V_24 -> V_38 ;
V_4 = F_21 ( V_2 , V_38 , V_7 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_8 ( V_4 == V_48 ) )
goto V_49;
* V_30 = ( V_38 -> V_50 + ( V_4 << V_42 ) ) ;
V_17 = ( void * ) V_35 ;
V_35 = F_7 ( V_35 ) ;
F_22 ( V_33 ) ;
F_1 ( V_2 ,
( V_20 | V_3 |
V_21 ) ,
V_4 ) ;
for ( V_36 = 0 ; V_36 < V_7 ; V_36 ++ ) {
long V_51 = F_13 ( V_35 + ( V_36 * V_46 ) , V_8 ) ;
if ( F_8 ( V_51 < 0L ) )
goto V_52;
}
if ( F_8 ( F_15 ( V_8 ) < 0L ) )
goto V_52;
F_23 ( V_33 ) ;
return V_17 ;
V_52:
F_23 ( V_33 ) ;
F_24 ( V_38 , * V_30 , V_7 , V_48 ) ;
V_49:
F_25 ( V_35 , V_34 ) ;
return NULL ;
}
unsigned long F_26 ( unsigned long V_15 ,
unsigned long V_16 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 ;
unsigned long V_51 ;
unsigned int V_57 ;
unsigned int V_1 ;
unsigned int V_58 ;
F_27 (pdev, &bus_dev->devices, bus_list) {
if ( V_56 -> V_59 ) {
F_26 ( V_15 , V_16 ,
V_56 -> V_59 ) ;
} else {
V_57 = V_54 -> V_60 ;
V_1 = F_28 ( V_56 -> V_61 ) ;
V_58 = F_29 ( V_56 -> V_61 ) ;
V_51 = F_30 ( V_15 , V_16 ,
F_31 ( V_57 ,
V_1 ,
V_58 ) ) ;
if ( V_51 )
return V_51 ;
}
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned long V_15 ,
T_3 V_62 , unsigned long V_16 ,
unsigned long V_4 , unsigned long V_7 )
{
unsigned long V_18 , V_33 ;
unsigned long V_17 ;
F_22 ( V_33 ) ;
do {
if ( V_62 <= F_4 ( 32 ) ) {
V_18 = F_33 ( V_15 ,
F_6 ( 0 , V_4 ) ,
V_7 ) ;
} else {
V_17 = F_34 ( V_15 , V_16 ,
V_4 , V_7 , & V_18 ) ;
if ( F_8 ( V_17 != V_26 ) ) {
F_9 ( L_3 ,
V_17 ) ;
}
}
V_4 += V_18 ;
V_7 -= V_18 ;
} while ( V_7 != 0 );
F_23 ( V_33 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_29 , void * V_63 ,
T_3 V_62 , unsigned long V_32 )
{
struct V_9 * V_10 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
struct V_37 * V_38 ;
unsigned long V_34 , V_7 , V_4 ;
unsigned long V_16 ;
T_5 V_15 ;
V_7 = F_17 ( V_29 ) >> V_42 ;
V_23 = V_2 -> V_11 . V_23 ;
V_10 = V_2 -> V_11 . V_12 ;
V_24 = V_23 -> V_24 ;
V_15 = V_10 -> V_15 ;
if ( V_62 <= F_4 ( 32 ) ) {
V_38 = & V_23 -> V_38 ;
V_16 = 0 ;
} else {
V_38 = & V_24 -> V_38 ;
V_16 = V_24 -> V_25 -> V_16 ;
}
V_4 = ( ( V_62 - V_38 -> V_50 ) >> V_42 ) ;
F_32 ( V_2 , V_15 , V_62 , V_16 , V_4 , V_7 ) ;
F_24 ( V_38 , V_62 , V_7 , V_48 ) ;
V_34 = F_18 ( V_29 ) ;
if ( V_34 < 10 )
F_25 ( ( unsigned long ) V_63 , V_34 ) ;
}
static T_3 F_36 ( struct V_1 * V_2 , struct V_39 * V_39 ,
unsigned long V_64 , T_2 V_65 ,
enum V_66 V_67 ,
unsigned long V_32 )
{
struct V_23 * V_23 ;
struct V_24 * V_24 ;
struct V_37 * V_38 ;
T_1 V_8 ;
unsigned long V_33 , V_7 , V_68 ;
unsigned long V_69 , V_70 ;
unsigned long V_3 ;
T_3 V_71 , V_17 ;
long V_4 ;
V_23 = V_2 -> V_11 . V_23 ;
V_24 = V_23 -> V_24 ;
if ( F_8 ( V_67 == V_72 ) )
goto V_73;
V_68 = ( unsigned long ) ( F_20 ( V_39 ) + V_64 ) ;
V_7 = F_17 ( V_68 + V_65 ) - ( V_68 & V_74 ) ;
V_7 >>= V_42 ;
V_8 = * V_2 -> V_75 ;
if ( V_8 <= F_4 ( 32 ) )
V_38 = & V_23 -> V_38 ;
else
V_38 = & V_24 -> V_38 ;
V_4 = F_21 ( V_2 , V_38 , V_7 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_8 ( V_4 == V_48 ) )
goto V_73;
V_71 = ( V_38 -> V_50 + ( V_4 << V_42 ) ) ;
V_17 = V_71 | ( V_68 & ~ V_74 ) ;
V_70 = F_7 ( V_68 & V_74 ) ;
V_3 = V_20 ;
if ( V_67 != V_76 )
V_3 |= V_21 ;
if ( V_32 & V_43 )
V_3 |= V_44 ;
F_22 ( V_33 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_69 = 0 ; V_69 < V_7 ; V_69 ++ , V_70 += V_77 ) {
long V_51 = F_13 ( V_70 , V_8 ) ;
if ( F_8 ( V_51 < 0L ) )
goto V_52;
}
if ( F_8 ( F_15 ( V_8 ) < 0L ) )
goto V_52;
F_23 ( V_33 ) ;
return V_17 ;
V_73:
if ( F_37 () )
F_38 ( 1 ) ;
return V_78 ;
V_52:
F_23 ( V_33 ) ;
F_24 ( V_38 , V_71 , V_7 , V_48 ) ;
return V_78 ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_71 ,
T_2 V_65 , enum V_66 V_67 ,
unsigned long V_32 )
{
struct V_9 * V_10 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
struct V_37 * V_38 ;
unsigned long V_7 ;
unsigned long V_16 ;
long V_4 ;
T_5 V_15 ;
if ( F_8 ( V_67 == V_72 ) ) {
if ( F_37 () )
F_38 ( 1 ) ;
return;
}
V_23 = V_2 -> V_11 . V_23 ;
V_10 = V_2 -> V_11 . V_12 ;
V_24 = V_23 -> V_24 ;
V_15 = V_10 -> V_15 ;
V_7 = F_17 ( V_71 + V_65 ) - ( V_71 & V_74 ) ;
V_7 >>= V_42 ;
V_71 &= V_74 ;
if ( V_71 <= F_4 ( 32 ) ) {
V_16 = 0 ;
V_38 = & V_23 -> V_38 ;
} else {
V_16 = V_24 -> V_25 -> V_16 ;
V_38 = & V_24 -> V_38 ;
}
V_4 = ( V_71 - V_38 -> V_50 ) >> V_42 ;
F_32 ( V_2 , V_15 , V_71 , V_16 , V_4 , V_7 ) ;
F_24 ( V_38 , V_71 , V_7 , V_48 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_79 * V_80 ,
int V_81 , enum V_66 V_67 ,
unsigned long V_32 )
{
struct V_79 * V_82 , * V_83 , * V_84 ;
unsigned long V_33 , V_85 , V_3 ;
T_3 V_86 = 0 , V_87 ;
unsigned int V_88 ;
unsigned long V_89 ;
int V_90 , V_91 , V_69 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
struct V_37 * V_38 ;
T_1 V_8 ;
unsigned long V_92 ;
long V_51 ;
F_14 ( V_67 == V_72 ) ;
V_23 = V_2 -> V_11 . V_23 ;
if ( V_81 == 0 || ! V_23 )
return 0 ;
V_24 = V_23 -> V_24 ;
V_3 = V_20 ;
if ( V_67 != V_76 )
V_3 |= V_21 ;
if ( V_32 & V_43 )
V_3 |= V_44 ;
V_83 = V_82 = V_84 = & V_80 [ 0 ] ;
V_90 = 1 ;
V_91 = V_81 ;
V_85 = 0 ;
V_83 -> V_93 = 0 ;
F_22 ( V_33 ) ;
F_1 ( V_2 , V_3 , ~ 0UL ) ;
V_88 = F_41 ( V_2 ) ;
V_89 = F_42 ( F_43 ( V_2 ) + 1 ,
V_77 ) >> V_42 ;
V_8 = * V_2 -> V_75 ;
if ( V_8 <= F_4 ( 32 ) )
V_38 = & V_23 -> V_38 ;
else
V_38 = & V_24 -> V_38 ;
V_92 = V_38 -> V_50 >> V_42 ;
F_44 (sglist, s, nelems, i) {
unsigned long V_94 , V_7 , V_4 , V_95 = 0 , V_96 ;
V_96 = V_82 -> V_97 ;
if ( V_96 == 0 ) {
V_86 = 0 ;
continue;
}
V_94 = ( unsigned long ) F_45 ( V_82 ) ;
V_7 = F_46 ( V_94 , V_96 , V_77 ) ;
V_4 = F_21 ( V_2 , V_38 , V_7 ,
& V_85 , ( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_8 ( V_4 == V_48 ) ) {
F_9 ( L_4 ,
V_38 , V_94 , V_7 ) ;
goto V_98;
}
F_12 ( V_4 , V_8 ) ;
V_87 = V_38 -> V_50 + ( V_4 << V_42 ) ;
V_87 |= ( V_82 -> V_64 & ~ V_74 ) ;
V_94 &= V_74 ;
while ( V_7 -- ) {
V_51 = F_13 ( V_94 , V_8 ) ;
if ( F_8 ( V_51 < 0L ) )
goto V_98;
V_94 += V_77 ;
}
if ( V_84 != V_82 ) {
if ( ( V_87 != V_86 ) ||
( V_83 -> V_93 + V_82 -> V_97 > V_88 ) ||
( F_47 ( V_95 , V_92 ,
V_89 , V_83 , V_82 ) ) ) {
V_84 = V_82 ;
V_90 ++ ;
V_83 = F_48 ( V_83 ) ;
} else {
V_83 -> V_93 += V_82 -> V_97 ;
}
}
if ( V_84 == V_82 ) {
V_83 -> V_99 = V_87 ;
V_83 -> V_93 = V_96 ;
V_95 = V_4 ;
}
V_86 = V_87 + V_96 ;
}
V_51 = F_15 ( V_8 ) ;
if ( F_8 ( V_51 < 0L ) )
goto V_98;
F_23 ( V_33 ) ;
if ( V_90 < V_91 ) {
V_83 = F_48 ( V_83 ) ;
V_83 -> V_99 = V_78 ;
V_83 -> V_93 = 0 ;
}
return V_90 ;
V_98:
F_44 (sglist, s, nelems, i) {
if ( V_82 -> V_93 != 0 ) {
unsigned long V_100 , V_7 ;
V_100 = V_82 -> V_99 & V_74 ;
V_7 = F_46 ( V_82 -> V_99 , V_82 -> V_93 ,
V_77 ) ;
F_24 ( V_38 , V_100 , V_7 ,
V_48 ) ;
V_82 -> V_99 = V_78 ;
V_82 -> V_93 = 0 ;
}
if ( V_82 == V_83 )
break;
}
F_23 ( V_33 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_79 * V_80 ,
int V_81 , enum V_66 V_67 ,
unsigned long V_32 )
{
struct V_9 * V_10 ;
struct V_79 * V_101 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
unsigned long V_33 , V_4 ;
unsigned long V_16 ;
T_5 V_15 ;
F_14 ( V_67 == V_72 ) ;
V_23 = V_2 -> V_11 . V_23 ;
V_10 = V_2 -> V_11 . V_12 ;
V_24 = V_23 -> V_24 ;
V_15 = V_10 -> V_15 ;
F_22 ( V_33 ) ;
V_101 = V_80 ;
while ( V_81 -- ) {
T_3 V_102 = V_101 -> V_99 ;
unsigned int V_103 = V_101 -> V_93 ;
unsigned long V_7 ;
struct V_37 * V_38 ;
unsigned long V_104 = V_42 ;
if ( ! V_103 )
break;
V_7 = F_46 ( V_102 , V_103 , V_77 ) ;
if ( V_102 <= F_4 ( 32 ) ) {
V_16 = 0 ;
V_38 = & V_23 -> V_38 ;
} else {
V_16 = V_24 -> V_25 -> V_16 ;
V_38 = & V_24 -> V_38 ;
}
V_4 = ( ( V_102 - V_38 -> V_50 ) >> V_104 ) ;
F_32 ( V_2 , V_15 , V_102 , V_16 ,
V_4 , V_7 ) ;
F_24 ( V_38 , V_102 , V_7 ,
V_48 ) ;
V_101 = F_48 ( V_101 ) ;
}
F_23 ( V_33 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_105 )
{
struct V_23 * V_23 = V_2 -> V_11 . V_23 ;
T_1 V_106 = V_23 -> V_106 ;
if ( V_105 > F_4 ( 32 ) ) {
if ( V_23 -> V_24 )
V_106 = V_23 -> V_24 -> V_106 ;
else
return 0 ;
}
if ( ( V_105 & V_106 ) == V_106 )
return 1 ;
return F_51 ( F_52 ( V_2 ) , V_105 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_3 V_87 )
{
return V_87 == V_78 ;
}
static void F_54 ( struct V_9 * V_10 , struct V_1 * V_107 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
V_111 = V_10 -> V_112 -> V_2 . V_113 ;
V_109 = F_55 ( V_111 , L_5 , NULL ) ;
V_10 -> V_114 = ( V_109 != NULL ) ;
V_10 -> V_53 = F_56 ( V_10 , V_107 ) ;
}
static unsigned long F_57 ( struct V_9 * V_10 ,
struct V_37 * V_23 )
{
struct V_115 * V_116 ;
unsigned long V_69 , V_117 , V_118 = 0 ;
T_5 V_15 ;
V_15 = V_10 -> V_15 ;
for ( V_117 = 0 ; V_117 < V_23 -> V_119 ; V_117 ++ ) {
V_116 = & ( V_23 -> V_120 [ V_117 ] ) ;
for ( V_69 = V_116 -> V_121 ; V_69 <= V_116 -> V_122 ; V_69 ++ ) {
unsigned long V_17 , V_123 , V_124 ;
V_17 = F_58 ( V_15 ,
F_6 ( 0 , V_69 ) ,
& V_123 , & V_124 ) ;
if ( V_17 == V_26 ) {
if ( F_59 ( V_124 ) ) {
F_33 ( V_15 ,
F_6 ( 0 ,
V_69 ) , 1 ) ;
} else {
V_118 ++ ;
F_60 ( V_69 , V_23 -> V_125 ) ;
}
}
}
}
return V_118 ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_24 * V_24 = V_10 -> V_23 -> V_24 ;
struct V_126 * V_25 ;
void * V_127 ;
T_1 V_128 ;
T_1 V_16 ;
unsigned long V_34 ;
unsigned long V_51 ;
V_25 = F_62 ( sizeof( * V_25 ) , V_129 ) ;
if ( ! V_25 ) {
V_51 = - V_130 ;
goto V_131;
}
V_24 -> V_25 = V_25 ;
V_128 = ( V_24 -> V_29 / V_77 ) * 8 ;
V_34 = F_18 ( V_128 ) ;
V_127 = ( void * ) F_63 ( V_129 | V_132 , V_34 ) ;
if ( ! V_127 ) {
V_51 = - V_130 ;
goto V_133;
}
V_25 -> V_127 = V_127 ;
V_25 -> V_124 = F_7 ( V_127 ) ;
V_25 -> V_134 = V_24 -> V_29 ;
V_25 -> V_135 = V_24 -> V_136 ;
V_25 -> V_128 = V_128 ;
V_25 -> V_137 = V_77 ;
V_51 = F_64 ( V_10 -> V_15 ,
V_25 -> V_124 ,
V_25 -> V_128 ,
V_25 -> V_137 ,
V_25 -> V_135 ,
& V_16 ) ;
if ( V_51 ) {
F_65 ( V_138 L_6 , V_51 ) ;
goto V_139;
}
V_25 -> V_16 = V_16 ;
V_51 = F_26 ( V_10 -> V_15 , V_16 , V_10 -> V_53 ) ;
if ( V_51 ) {
F_65 ( V_138 L_7 , V_51 ) ;
goto V_139;
}
return 0 ;
V_139:
F_25 ( ( unsigned long ) V_127 , V_34 ) ;
V_133:
F_66 ( V_25 ) ;
V_131:
return V_51 ;
}
static int F_67 ( struct V_9 * V_10 )
{
struct V_24 * V_24 = V_10 -> V_23 -> V_24 ;
unsigned long V_51 ;
const T_1 * V_140 ;
T_1 V_141 , V_142 ;
T_1 V_75 ;
const T_5 * V_137 ;
int V_103 ;
V_140 = F_68 ( V_10 -> V_112 -> V_2 . V_113 , L_8 ,
& V_103 ) ;
if ( ! V_140 ) {
F_65 ( V_138 L_9 ) ;
return - V_143 ;
}
V_137 = F_68 ( V_10 -> V_112 -> V_2 . V_113 , L_10 ,
NULL ) ;
if ( ! V_137 ) {
F_65 ( V_138 L_11 ) ;
return - V_143 ;
}
V_24 -> V_140 = (struct V_144 * ) V_140 ;
V_24 -> V_136 = V_24 -> V_140 [ 3 ] . V_136 ;
V_24 -> V_29 = V_145 ;
V_51 = F_61 ( V_10 ) ;
if ( V_51 ) {
F_65 ( V_138 L_12 ) ;
return V_51 ;
}
V_75 = ( F_69 ( V_24 -> V_29 ) - 1UL ) ;
V_142 = V_24 -> V_29 / V_77 ;
V_141 = V_142 / 8 ;
V_24 -> V_38 . V_50 = V_24 -> V_136 ;
V_24 -> V_106 = V_75 ;
V_24 -> V_38 . V_125 = F_62 ( V_141 , V_129 ) ;
if ( ! V_24 -> V_38 . V_125 )
return - V_130 ;
F_70 ( & V_24 -> V_38 , V_142 , V_42 ,
NULL , false ,
0 ,
false ) ;
return 0 ;
}
static int F_71 ( struct V_9 * V_10 )
{
static const T_5 V_146 [] = { 0x80000000 , 0x80000000 } ;
struct V_23 * V_23 = V_10 -> V_23 ;
unsigned long V_147 , V_65 ;
T_5 V_75 , V_148 ;
const T_5 * V_149 ;
V_149 = F_68 ( V_10 -> V_112 -> V_2 . V_113 , L_13 , NULL ) ;
if ( ! V_149 )
V_149 = V_146 ;
if ( ( V_149 [ 0 ] | V_149 [ 1 ] ) & ~ V_74 ) {
F_72 (KERN_ERR PFX L_14 ,
vdma[0], vdma[1]) ;
return - V_143 ;
}
V_75 = ( F_69 ( V_149 [ 1 ] ) - 1UL ) ;
V_147 = V_149 [ 1 ] / V_77 ;
V_148 = V_149 [ 0 ] ;
F_73 ( & V_23 -> V_150 ) ;
V_23 -> V_151 = 1 ;
V_23 -> V_38 . V_50 = V_148 ;
V_23 -> V_106 = V_75 ;
V_65 = ( V_147 + 7 ) / 8 ;
V_65 = ( V_65 + 7UL ) & ~ 7UL ;
V_23 -> V_38 . V_125 = F_62 ( V_65 , V_129 ) ;
if ( ! V_23 -> V_38 . V_125 ) {
F_72 (KERN_ERR PFX L_15 ) ;
return - V_130 ;
}
F_70 ( & V_23 -> V_38 , V_147 , V_42 ,
NULL , false ,
0 ,
false ) ;
V_65 = F_57 ( V_10 , & V_23 -> V_38 ) ;
if ( V_65 )
F_72 ( L_16 ,
V_10 -> V_152 , V_65 ) ;
return 0 ;
}
static int F_74 ( struct V_9 * V_10 , unsigned long V_153 ,
unsigned long * V_154 )
{
unsigned long V_51 , V_155 ;
V_51 = F_75 ( V_10 -> V_15 , V_153 , V_154 ) ;
if ( F_8 ( V_51 ) )
return - V_156 ;
V_155 = V_10 -> V_157 * sizeof( struct V_158 ) ;
if ( F_8 ( * V_154 >= V_155 ) )
return - V_159 ;
return 0 ;
}
static int F_76 ( struct V_9 * V_10 ,
unsigned long V_153 , unsigned long * V_154 ,
unsigned long * V_160 )
{
struct V_158 * V_161 ;
unsigned long V_51 , type ;
V_161 = ( V_10 -> V_162 + ( ( V_153 - V_10 -> V_163 ) *
( V_10 -> V_157 *
sizeof( struct V_158 ) ) ) +
* V_154 ) ;
if ( ( V_161 -> V_164 & V_165 ) == 0 )
return 0 ;
type = ( V_161 -> V_164 & V_165 ) >> V_166 ;
if ( F_8 ( type != V_167 &&
type != V_168 ) )
return - V_143 ;
* V_160 = V_161 -> V_169 ;
V_51 = F_77 ( V_10 -> V_15 ,
V_161 -> V_169 ,
V_170 ) ;
if ( F_8 ( V_51 ) )
return - V_156 ;
V_161 -> V_164 &= ~ V_165 ;
( * V_154 ) += sizeof( struct V_158 ) ;
if ( * V_154 >=
( V_10 -> V_157 * sizeof( struct V_158 ) ) )
* V_154 = 0 ;
return 1 ;
}
static int F_78 ( struct V_9 * V_10 , unsigned long V_153 ,
unsigned long V_154 )
{
unsigned long V_51 ;
V_51 = F_79 ( V_10 -> V_15 , V_153 , V_154 ) ;
if ( F_8 ( V_51 ) )
return - V_143 ;
return 0 ;
}
static int F_80 ( struct V_9 * V_10 , unsigned long V_153 ,
unsigned long V_160 , int V_171 )
{
if ( F_81 ( V_10 -> V_15 , V_160 , V_153 ,
( V_171 ?
V_172 : V_173 ) ) )
return - V_156 ;
if ( F_77 ( V_10 -> V_15 , V_160 , V_170 ) )
return - V_156 ;
if ( F_82 ( V_10 -> V_15 , V_160 , V_174 ) )
return - V_156 ;
return 0 ;
}
static int F_83 ( struct V_9 * V_10 , unsigned long V_160 )
{
unsigned long V_51 , V_153 ;
V_51 = F_84 ( V_10 -> V_15 , V_160 , & V_153 ) ;
if ( V_51 )
return - V_156 ;
F_82 ( V_10 -> V_15 , V_160 , V_175 ) ;
return 0 ;
}
static int F_85 ( struct V_9 * V_10 )
{
unsigned long V_176 , V_177 , V_178 , V_34 ;
int V_69 ;
V_176 = V_10 -> V_157 * sizeof( struct V_158 ) ;
V_177 = ( V_10 -> V_179 * V_176 ) ;
V_34 = F_18 ( V_177 ) ;
V_178 = F_63 ( V_129 | V_180 , V_34 ) ;
if ( V_178 == 0UL ) {
F_72 ( V_181 L_17 ,
V_34 ) ;
return - V_130 ;
}
memset ( ( char * ) V_178 , 0 , V_46 << V_34 ) ;
V_10 -> V_162 = ( void * ) V_178 ;
for ( V_69 = 0 ; V_69 < V_10 -> V_179 ; V_69 ++ ) {
unsigned long V_51 , V_136 = F_7 ( V_178 + ( V_69 * V_176 ) ) ;
unsigned long V_182 , V_183 ;
V_51 = F_86 ( V_10 -> V_15 ,
V_10 -> V_163 + V_69 ,
V_136 , V_10 -> V_157 ) ;
if ( V_51 ) {
F_72 ( V_181 L_18 ,
V_51 ) ;
goto V_184;
}
V_51 = F_87 ( V_10 -> V_15 ,
V_10 -> V_163 + V_69 ,
& V_182 , & V_183 ) ;
if ( V_51 ) {
F_72 ( V_181 L_19 ,
V_51 ) ;
goto V_184;
}
if ( V_182 != V_136 || V_183 != V_10 -> V_157 ) {
F_72 ( V_181 L_20
L_21 ,
V_136 , V_10 -> V_157 ,
V_182 , V_183 ) ;
goto V_184;
}
}
return 0 ;
V_184:
F_25 ( V_178 , V_34 ) ;
return - V_143 ;
}
static void F_88 ( struct V_9 * V_10 )
{
unsigned long V_176 , V_177 , V_178 , V_34 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_10 -> V_179 ; V_69 ++ ) {
unsigned long V_153 = V_10 -> V_163 + V_69 ;
( void ) F_86 ( V_10 -> V_15 , V_153 , 0UL , 0 ) ;
}
V_176 = V_10 -> V_157 * sizeof( struct V_158 ) ;
V_177 = ( V_10 -> V_179 * V_176 ) ;
V_34 = F_18 ( V_177 ) ;
V_178 = ( unsigned long ) V_10 -> V_162 ;
F_25 ( V_178 , V_34 ) ;
V_10 -> V_162 = NULL ;
}
static int F_89 ( struct V_9 * V_10 ,
unsigned long V_153 ,
unsigned long V_185 )
{
unsigned int V_186 = F_90 ( V_10 -> V_15 , V_185 ) ;
if ( ! V_186 )
return - V_130 ;
if ( F_91 ( V_10 -> V_15 , V_153 , V_187 ) )
return - V_143 ;
if ( F_92 ( V_10 -> V_15 , V_153 , V_188 ) )
return - V_143 ;
return V_186 ;
}
static void F_93 ( struct V_9 * V_10 )
{
F_94 ( V_10 , & V_189 ) ;
}
static void F_93 ( struct V_9 * V_10 )
{
}
static int F_95 ( struct V_9 * V_10 ,
struct V_190 * V_112 , T_5 V_15 )
{
struct V_110 * V_111 = V_112 -> V_2 . V_113 ;
int V_51 ;
V_10 -> V_45 = F_96 ( V_111 ) ;
V_10 -> V_191 = & V_192 ;
V_10 -> V_193 = 12 ;
V_10 -> V_194 = V_195 ++ ;
V_10 -> V_112 = V_112 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_152 = V_111 -> V_196 ;
F_72 ( L_22 , V_10 -> V_152 ) ;
F_72 ( L_23 , V_10 -> V_152 , V_10 -> V_45 ) ;
F_97 ( V_10 ) ;
F_98 ( V_10 ) ;
V_51 = F_71 ( V_10 ) ;
if ( V_51 )
return V_51 ;
F_93 ( V_10 ) ;
F_54 ( V_10 , & V_112 -> V_2 ) ;
if ( V_10 -> V_23 -> V_24 ) {
V_51 = F_67 ( V_10 ) ;
if ( V_51 ) {
F_66 ( V_10 -> V_23 -> V_24 ) ;
V_10 -> V_23 -> V_24 = NULL ;
F_65 ( V_138 L_24 , V_51 ) ;
}
}
V_10 -> V_197 = V_198 ;
V_198 = V_10 ;
return 0 ;
}
static int F_99 ( struct V_190 * V_112 )
{
const struct V_199 * V_200 ;
static int V_201 = 0 ;
struct V_9 * V_10 ;
struct V_110 * V_111 ;
struct V_23 * V_23 ;
struct V_24 * V_24 ;
T_5 V_15 ;
int V_69 , V_51 = - V_202 ;
static bool V_203 = true ;
V_111 = V_112 -> V_2 . V_113 ;
if ( ! V_201 ++ ) {
for ( V_69 = 0 ; V_69 < F_100 ( V_204 ) ; V_69 ++ ) {
V_19 = V_204 [ V_69 ] . V_205 ;
V_206 = V_204 [ V_69 ] . V_207 ;
V_51 = F_101 ( V_208 , V_19 ,
& V_206 ) ;
if ( ! V_51 )
break;
}
if ( V_51 ) {
F_65 ( V_138 L_25 , V_51 ) ;
return V_51 ;
}
F_102 ( V_138 L_26 ,
V_19 , V_206 ) ;
V_51 = F_101 ( V_209 , V_210 , & V_211 ) ;
if ( V_51 ) {
V_203 = false ;
} else {
F_102 ( V_138 L_27 ,
V_210 , V_211 ) ;
}
V_212 = & V_213 ;
}
V_200 = F_68 ( V_111 , L_28 , NULL ) ;
V_51 = - V_202 ;
if ( ! V_200 ) {
F_72 (KERN_ERR PFX L_29 ) ;
goto V_131;
}
V_15 = ( V_200 -> V_214 >> 32UL ) & 0x0fffffff ;
V_51 = - V_130 ;
if ( ! V_215 ) {
F_103 (i) {
unsigned long V_39 = F_104 ( V_129 ) ;
if ( ! V_39 )
goto V_131;
F_105 ( V_5 , V_69 ) . V_13 = ( T_1 * ) V_39 ;
}
V_215 = 1 ;
}
V_10 = F_62 ( sizeof( * V_10 ) , V_129 ) ;
if ( ! V_10 ) {
F_72 (KERN_ERR PFX L_30 ) ;
goto V_131;
}
V_23 = F_62 ( sizeof( struct V_23 ) , V_129 ) ;
if ( ! V_23 ) {
F_72 (KERN_ERR PFX L_31 ) ;
goto V_216;
}
V_10 -> V_23 = V_23 ;
V_23 -> V_24 = NULL ;
if ( V_203 ) {
V_24 = F_62 ( sizeof( * V_24 ) , V_129 ) ;
if ( ! V_24 )
F_65 ( V_138 L_32 ) ;
else
V_23 -> V_24 = V_24 ;
}
V_51 = F_95 ( V_10 , V_112 , V_15 ) ;
if ( V_51 )
goto V_217;
F_106 ( & V_112 -> V_2 , V_10 ) ;
return 0 ;
V_217:
F_66 ( V_23 -> V_24 ) ;
F_66 ( V_10 -> V_23 ) ;
V_216:
F_66 ( V_10 ) ;
V_131:
return V_51 ;
}
static int T_6 F_107 ( void )
{
return F_108 ( & V_218 ) ;
}
