int
F_1 ( T_1 V_1 , unsigned int V_2 )
{
T_2 * V_3 ;
T_2 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
struct V_5 V_8 ;
if ( V_2 ) {
F_2 ( V_3 , sizeof( * V_3 ) ) ;
if ( ! V_3 )
return - V_9 ;
V_3 -> V_10 = V_1 ;
V_3 -> V_11 = V_2 ;
F_3 ( 0 ) ;
F_4 ( & V_3 -> V_12 , & V_13 . V_14 ) ;
F_5 ( 0 ) ;
return 0 ;
}
F_6 ( & V_8 ) ;
F_3 ( 0 ) ;
F_7 (el, next, &the_lnet.ln_test_peers) {
V_3 = F_8 ( V_6 , T_2 , V_12 ) ;
if ( ! V_3 -> V_11 ||
V_1 == V_15 ||
V_3 -> V_10 == V_1 ) {
F_9 ( & V_3 -> V_12 ) ;
F_10 ( & V_3 -> V_12 , & V_8 ) ;
}
}
F_5 ( 0 ) ;
F_11 (tp, temp, &cull, tp_list) {
F_9 ( & V_3 -> V_12 ) ;
F_12 ( V_3 , sizeof( * V_3 ) ) ;
}
return 0 ;
}
static int
F_13 ( T_1 V_1 , int V_16 )
{
T_2 * V_3 ;
T_2 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
struct V_5 V_8 ;
int V_17 = 0 ;
F_6 ( & V_8 ) ;
F_3 ( 0 ) ;
F_7 (el, next, &the_lnet.ln_test_peers) {
V_3 = F_8 ( V_6 , T_2 , V_12 ) ;
if ( ! V_3 -> V_11 ) {
if ( V_16 ) {
F_9 ( & V_3 -> V_12 ) ;
F_10 ( & V_3 -> V_12 , & V_8 ) ;
}
continue;
}
if ( V_3 -> V_10 == V_15 ||
V_1 == V_3 -> V_10 ) {
V_17 = 1 ;
if ( V_3 -> V_11 != V_18 ) {
V_3 -> V_11 -- ;
if ( V_16 &&
! V_3 -> V_11 ) {
F_9 ( & V_3 -> V_12 ) ;
F_10 ( & V_3 -> V_12 , & V_8 ) ;
}
}
break;
}
}
F_5 ( 0 ) ;
F_11 (tp, temp, &cull, tp_list) {
F_9 ( & V_3 -> V_12 ) ;
F_12 ( V_3 , sizeof( * V_3 ) ) ;
}
return V_17 ;
}
unsigned int
F_14 ( unsigned int V_19 , struct V_20 * V_21 )
{
unsigned int V_22 = 0 ;
F_15 ( ! V_19 || V_21 ) ;
while ( V_19 -- > 0 )
V_22 += ( V_21 ++ ) -> V_23 ;
return V_22 ;
}
void
F_16 ( unsigned int V_24 , struct V_20 * V_25 , unsigned int V_26 ,
unsigned int V_27 , struct V_20 * V_28 , unsigned int V_29 ,
unsigned int V_22 )
{
unsigned int V_30 ;
if ( ! V_22 )
return;
F_15 ( V_24 > 0 ) ;
while ( V_26 >= V_25 -> V_23 ) {
V_26 -= V_25 -> V_23 ;
V_25 ++ ;
V_24 -- ;
F_15 ( V_24 > 0 ) ;
}
F_15 ( V_27 > 0 ) ;
while ( V_29 >= V_28 -> V_23 ) {
V_29 -= V_28 -> V_23 ;
V_28 ++ ;
V_27 -- ;
F_15 ( V_27 > 0 ) ;
}
do {
F_15 ( V_24 > 0 ) ;
F_15 ( V_27 > 0 ) ;
V_30 = F_17 ( V_25 -> V_23 - V_26 ,
V_28 -> V_23 - V_29 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
memcpy ( ( char * ) V_25 -> V_31 + V_26 ,
( char * ) V_28 -> V_31 + V_29 , V_30 ) ;
V_22 -= V_30 ;
if ( V_25 -> V_23 > V_26 + V_30 ) {
V_26 += V_30 ;
} else {
V_25 ++ ;
V_24 -- ;
V_26 = 0 ;
}
if ( V_28 -> V_23 > V_29 + V_30 ) {
V_29 += V_30 ;
} else {
V_28 ++ ;
V_27 -- ;
V_29 = 0 ;
}
} while ( V_22 > 0 );
}
int
F_18 ( int V_32 , struct V_20 * V_33 ,
int V_34 , struct V_20 * V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
unsigned int V_38 ;
unsigned int V_19 ;
if ( ! V_37 )
return 0 ;
F_15 ( V_34 > 0 ) ;
while ( V_36 >= V_35 -> V_23 ) {
V_36 -= V_35 -> V_23 ;
V_34 -- ;
V_35 ++ ;
F_15 ( V_34 > 0 ) ;
}
V_19 = 1 ;
for (; ; ) {
F_15 ( V_34 > 0 ) ;
F_15 ( ( int ) V_19 <= V_32 ) ;
V_38 = V_35 -> V_23 - V_36 ;
V_33 -> V_31 = ( ( char * ) V_35 -> V_31 ) + V_36 ;
if ( V_37 <= V_38 ) {
V_33 -> V_23 = V_37 ;
return V_19 ;
}
V_33 -> V_23 = V_38 ;
V_37 -= V_38 ;
V_33 ++ ;
V_35 ++ ;
V_19 ++ ;
V_34 -- ;
V_36 = 0 ;
}
}
unsigned int
F_19 ( unsigned int V_19 , T_3 * V_39 )
{
unsigned int V_22 = 0 ;
F_15 ( ! V_19 || V_39 ) ;
while ( V_19 -- > 0 )
V_22 += ( V_39 ++ ) -> V_40 ;
return V_22 ;
}
void
F_20 ( unsigned int V_24 , T_3 * V_25 , unsigned int V_26 ,
unsigned int V_27 , T_3 * V_28 , unsigned int V_29 ,
unsigned int V_22 )
{
unsigned int V_30 ;
char * V_41 = NULL ;
char * V_42 = NULL ;
if ( ! V_22 )
return;
F_15 ( ! F_21 () ) ;
F_15 ( V_24 > 0 ) ;
while ( V_26 >= V_25 -> V_40 ) {
V_26 -= V_25 -> V_40 ;
V_25 ++ ;
V_24 -- ;
F_15 ( V_24 > 0 ) ;
}
F_15 ( V_27 > 0 ) ;
while ( V_29 >= V_28 -> V_40 ) {
V_29 -= V_28 -> V_40 ;
V_28 ++ ;
V_27 -- ;
F_15 ( V_27 > 0 ) ;
}
do {
F_15 ( V_24 > 0 ) ;
F_15 ( V_27 > 0 ) ;
V_30 = F_17 ( V_25 -> V_40 - V_26 ,
V_28 -> V_40 - V_29 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
if ( ! V_41 )
V_41 = ( ( char * ) F_22 ( V_25 -> V_43 ) ) +
V_25 -> V_44 + V_26 ;
if ( ! V_42 )
V_42 = ( ( char * ) F_22 ( V_28 -> V_43 ) ) +
V_28 -> V_44 + V_29 ;
memcpy ( V_41 , V_42 , V_30 ) ;
V_22 -= V_30 ;
if ( V_25 -> V_40 > V_26 + V_30 ) {
V_41 += V_30 ;
V_26 += V_30 ;
} else {
F_23 ( V_25 -> V_43 ) ;
V_41 = NULL ;
V_25 ++ ;
V_24 -- ;
V_26 = 0 ;
}
if ( V_28 -> V_40 > V_29 + V_30 ) {
V_42 += V_30 ;
V_29 += V_30 ;
} else {
F_23 ( V_28 -> V_43 ) ;
V_42 = NULL ;
V_28 ++ ;
V_27 -- ;
V_29 = 0 ;
}
} while ( V_22 > 0 );
if ( V_41 )
F_23 ( V_25 -> V_43 ) ;
if ( V_42 )
F_23 ( V_28 -> V_43 ) ;
}
void
F_24 ( unsigned int V_19 , struct V_20 * V_21 , unsigned int V_45 ,
unsigned int V_46 , T_3 * V_39 ,
unsigned int V_47 , unsigned int V_22 )
{
unsigned int V_30 ;
char * V_48 = NULL ;
if ( ! V_22 )
return;
F_15 ( ! F_21 () ) ;
F_15 ( V_19 > 0 ) ;
while ( V_45 >= V_21 -> V_23 ) {
V_45 -= V_21 -> V_23 ;
V_21 ++ ;
V_19 -- ;
F_15 ( V_19 > 0 ) ;
}
F_15 ( V_46 > 0 ) ;
while ( V_47 >= V_39 -> V_40 ) {
V_47 -= V_39 -> V_40 ;
V_39 ++ ;
V_46 -- ;
F_15 ( V_46 > 0 ) ;
}
do {
F_15 ( V_19 > 0 ) ;
F_15 ( V_46 > 0 ) ;
V_30 = F_17 ( V_21 -> V_23 - V_45 ,
( V_49 ) V_39 -> V_40 - V_47 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
if ( ! V_48 )
V_48 = ( ( char * ) F_22 ( V_39 -> V_43 ) ) +
V_39 -> V_44 + V_47 ;
memcpy ( ( char * ) V_21 -> V_31 + V_45 , V_48 , V_30 ) ;
V_22 -= V_30 ;
if ( V_21 -> V_23 > V_45 + V_30 ) {
V_45 += V_30 ;
} else {
V_21 ++ ;
V_19 -- ;
V_45 = 0 ;
}
if ( V_39 -> V_40 > V_47 + V_30 ) {
V_48 += V_30 ;
V_47 += V_30 ;
} else {
F_23 ( V_39 -> V_43 ) ;
V_48 = NULL ;
V_39 ++ ;
V_46 -- ;
V_47 = 0 ;
}
} while ( V_22 > 0 );
if ( V_48 )
F_23 ( V_39 -> V_43 ) ;
}
void
F_25 ( unsigned int V_46 , T_3 * V_39 ,
unsigned int V_47 , unsigned int V_19 ,
struct V_20 * V_21 , unsigned int V_45 ,
unsigned int V_22 )
{
unsigned int V_30 ;
char * V_48 = NULL ;
if ( ! V_22 )
return;
F_15 ( ! F_21 () ) ;
F_15 ( V_46 > 0 ) ;
while ( V_47 >= V_39 -> V_40 ) {
V_47 -= V_39 -> V_40 ;
V_39 ++ ;
V_46 -- ;
F_15 ( V_46 > 0 ) ;
}
F_15 ( V_19 > 0 ) ;
while ( V_45 >= V_21 -> V_23 ) {
V_45 -= V_21 -> V_23 ;
V_21 ++ ;
V_19 -- ;
F_15 ( V_19 > 0 ) ;
}
do {
F_15 ( V_46 > 0 ) ;
F_15 ( V_19 > 0 ) ;
V_30 = F_17 ( ( V_49 ) V_39 -> V_40 - V_47 ,
V_21 -> V_23 - V_45 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
if ( ! V_48 )
V_48 = ( ( char * ) F_22 ( V_39 -> V_43 ) ) +
V_39 -> V_44 + V_47 ;
memcpy ( V_48 , ( char * ) V_21 -> V_31 + V_45 , V_30 ) ;
V_22 -= V_30 ;
if ( V_39 -> V_40 > V_47 + V_30 ) {
V_48 += V_30 ;
V_47 += V_30 ;
} else {
F_23 ( V_39 -> V_43 ) ;
V_48 = NULL ;
V_39 ++ ;
V_46 -- ;
V_47 = 0 ;
}
if ( V_21 -> V_23 > V_45 + V_30 ) {
V_45 += V_30 ;
} else {
V_21 ++ ;
V_19 -- ;
V_45 = 0 ;
}
} while ( V_22 > 0 );
if ( V_48 )
F_23 ( V_39 -> V_43 ) ;
}
int
F_26 ( int V_32 , T_3 * V_33 ,
int V_34 , T_3 * V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
unsigned int V_38 ;
unsigned int V_19 ;
if ( ! V_37 )
return 0 ;
F_15 ( V_34 > 0 ) ;
while ( V_36 >= V_35 -> V_40 ) {
V_36 -= V_35 -> V_40 ;
V_34 -- ;
V_35 ++ ;
F_15 ( V_34 > 0 ) ;
}
V_19 = 1 ;
for (; ; ) {
F_15 ( V_34 > 0 ) ;
F_15 ( ( int ) V_19 <= V_32 ) ;
V_38 = V_35 -> V_40 - V_36 ;
V_33 -> V_43 = V_35 -> V_43 ;
V_33 -> V_44 = V_35 -> V_44 + V_36 ;
if ( V_37 <= V_38 ) {
V_33 -> V_40 = V_37 ;
F_15 ( V_33 -> V_44 + V_33 -> V_40
<= V_50 ) ;
return V_19 ;
}
V_33 -> V_40 = V_38 ;
F_15 ( V_33 -> V_44 + V_33 -> V_40 <= V_50 ) ;
V_37 -= V_38 ;
V_33 ++ ;
V_35 ++ ;
V_19 ++ ;
V_34 -- ;
V_36 = 0 ;
}
}
void
F_27 ( T_4 * V_51 , void * V_52 , T_5 * V_53 , int V_54 ,
unsigned int V_36 , unsigned int V_55 , unsigned int V_56 )
{
unsigned int V_19 = 0 ;
struct V_20 * V_21 = NULL ;
T_3 * V_39 = NULL ;
int V_57 ;
F_15 ( ! F_21 () ) ;
F_15 ( ! V_55 || V_53 ) ;
if ( V_53 ) {
F_15 ( V_53 -> V_58 ) ;
F_15 ( ! V_53 -> V_59 ) ;
F_15 ( V_56 == V_53 -> V_60 ) ;
F_15 ( V_55 <= V_53 -> V_60 ) ;
F_15 ( V_53 -> V_61 == V_36 ) ;
F_15 ( V_53 -> V_62 == V_55 ) ;
V_53 -> V_58 = 0 ;
if ( V_55 ) {
V_19 = V_53 -> V_63 ;
V_21 = V_53 -> V_64 ;
V_39 = V_53 -> V_65 ;
F_15 ( V_19 > 0 ) ;
F_15 ( ! V_21 != ! V_39 ) ;
}
}
V_57 = V_51 -> V_66 -> V_67 ( V_51 , V_52 , V_53 , V_54 ,
V_19 , V_21 , V_39 , V_36 , V_55 , V_56 ) ;
if ( V_57 < 0 )
F_28 ( V_51 , V_53 , V_57 ) ;
}
static void
F_29 ( T_5 * V_53 )
{
T_6 * V_68 = V_53 -> V_69 ;
F_15 ( V_53 -> V_60 > 0 ) ;
F_15 ( ! V_53 -> V_70 ) ;
F_15 ( V_68 ) ;
F_15 ( ! V_53 -> V_63 ) ;
F_15 ( ! V_53 -> V_64 ) ;
F_15 ( ! V_53 -> V_65 ) ;
V_53 -> V_63 = V_68 -> V_71 ;
if ( V_68 -> V_72 & V_73 )
V_53 -> V_65 = V_68 -> V_74 . V_39 ;
else
V_53 -> V_64 = V_68 -> V_74 . V_21 ;
}
void
F_30 ( T_5 * V_53 , int type , T_7 V_75 ,
unsigned int V_36 , unsigned int V_37 )
{
V_53 -> V_76 = type ;
V_53 -> V_77 = V_75 ;
V_53 -> V_60 = V_37 ;
V_53 -> V_61 = V_36 ;
if ( V_37 )
F_29 ( V_53 ) ;
memset ( & V_53 -> V_78 , 0 , sizeof( V_53 -> V_78 ) ) ;
V_53 -> V_78 . type = F_31 ( type ) ;
V_53 -> V_78 . V_79 = F_32 ( V_75 . V_1 ) ;
V_53 -> V_78 . V_80 = F_31 ( V_75 . V_81 ) ;
V_53 -> V_78 . V_82 = F_31 ( V_13 . V_83 ) ;
V_53 -> V_78 . V_84 = F_31 ( V_37 ) ;
}
static void
F_33 ( T_4 * V_51 , T_5 * V_53 )
{
void * V_85 = V_53 -> V_86 ;
int V_57 ;
F_15 ( ! F_21 () ) ;
F_15 ( F_34 ( F_35 ( V_51 -> V_87 ) ) == V_88 ||
( V_53 -> V_89 && V_53 -> V_90 ) ) ;
V_57 = V_51 -> V_66 -> V_91 ( V_51 , V_85 , V_53 ) ;
if ( V_57 < 0 )
F_28 ( V_51 , V_53 , V_57 ) ;
}
static int
F_36 ( T_4 * V_51 , T_5 * V_53 )
{
int V_57 ;
F_15 ( ! V_53 -> V_59 ) ;
F_15 ( V_53 -> V_58 ) ;
F_15 ( ! V_53 -> V_92 ) ;
F_15 ( V_51 -> V_66 -> V_93 ) ;
V_53 -> V_92 = 1 ;
V_57 = V_51 -> V_66 -> V_93 ( V_51 , V_53 -> V_86 , V_53 ,
& V_53 -> V_86 ) ;
if ( V_57 ) {
F_37 ( L_1 ,
F_38 ( V_53 -> V_94 -> V_95 ) ,
F_39 ( V_53 -> V_77 ) , V_57 ) ;
F_15 ( V_57 < 0 ) ;
}
return V_57 ;
}
static void
F_40 ( T_4 * V_51 , T_8 * V_96 )
{
unsigned long V_97 = 0 ;
F_15 ( F_41 ( V_96 ) ) ;
F_15 ( V_51 -> V_66 -> V_98 ) ;
F_5 ( V_96 -> V_99 ) ;
V_51 -> V_66 -> V_98 ( V_51 , V_96 -> V_95 , & V_97 ) ;
F_3 ( V_96 -> V_99 ) ;
V_96 -> V_100 = F_42 () ;
if ( V_97 )
V_96 -> V_101 = V_97 ;
}
static inline int
F_43 ( T_8 * V_96 , unsigned long V_102 )
{
int V_103 ;
unsigned long V_104 ;
F_15 ( F_41 ( V_96 ) ) ;
if ( ! V_96 -> V_105 && V_96 -> V_106 > 0 &&
F_44 ( V_96 -> V_107 , V_96 -> V_101 ) )
return 0 ;
V_104 = F_45 ( V_96 -> V_101 ,
F_46 ( V_96 -> V_108 -> V_109 ) ) ;
V_103 = F_47 ( V_104 , V_102 ) ;
if ( V_103 && ! V_96 -> V_105 &&
! ( F_48 ( V_96 ) && ! V_96 -> V_106 ) )
F_49 ( V_96 , 0 , 1 , V_96 -> V_101 ) ;
return V_103 ;
}
static int
F_50 ( T_8 * V_96 )
{
unsigned long V_102 = F_42 () ;
if ( ! F_41 ( V_96 ) )
return - V_110 ;
if ( F_43 ( V_96 , V_102 ) )
return 1 ;
if ( V_96 -> V_100 ) {
static const int V_111 = 1 ;
unsigned long V_112 =
F_45 ( V_96 -> V_100 ,
F_46 ( V_111 ) ) ;
if ( F_51 ( V_102 , V_112 ) ) {
if ( V_96 -> V_105 )
F_52 ( L_2 ,
F_38 ( V_96 -> V_95 ) ,
( int ) V_102 , ( int ) V_112 ,
V_111 ,
V_96 -> V_108 -> V_109 ) ;
return 0 ;
}
}
F_40 ( V_96 -> V_108 , V_96 ) ;
if ( F_43 ( V_96 , V_102 ) )
return 1 ;
F_49 ( V_96 , 0 , 0 , V_96 -> V_101 ) ;
return 0 ;
}
static int
F_53 ( T_5 * V_53 , int V_113 )
{
T_8 * V_96 = V_53 -> V_114 ;
T_4 * V_51 = V_96 -> V_108 ;
int V_115 = V_53 -> V_116 ;
struct V_117 * V_118 = V_51 -> V_119 [ V_115 ] ;
F_15 ( ! V_113 || V_53 -> V_120 ) ;
F_15 ( ! V_53 -> V_58 ) ;
F_15 ( V_53 -> V_121 ) ;
if ( ! ( V_53 -> V_77 . V_81 & V_122 ) &&
! F_50 ( V_96 ) ) {
V_13 . V_123 [ V_115 ] -> V_124 ++ ;
V_13 . V_123 [ V_115 ] -> V_125 += V_53 -> V_60 ;
F_5 ( V_115 ) ;
F_54 ( L_3 ,
F_39 ( V_53 -> V_77 ) ) ;
if ( V_113 )
F_28 ( V_51 , V_53 , - V_126 ) ;
F_3 ( V_115 ) ;
return - V_126 ;
}
if ( V_53 -> V_69 &&
( V_53 -> V_69 -> V_127 & V_128 ) ) {
F_5 ( V_115 ) ;
F_54 ( L_4 ,
F_39 ( V_53 -> V_77 ) ) ;
if ( V_113 )
F_28 ( V_51 , V_53 , - V_129 ) ;
F_3 ( V_115 ) ;
return - V_129 ;
}
if ( ! V_53 -> V_90 ) {
F_15 ( ( V_96 -> V_130 < 0 ) ==
! F_55 ( & V_96 -> V_131 ) ) ;
V_53 -> V_90 = 1 ;
V_96 -> V_132 += V_53 -> V_60 + sizeof( V_133 ) ;
V_96 -> V_130 -- ;
if ( V_96 -> V_130 < V_96 -> V_134 )
V_96 -> V_134 = V_96 -> V_130 ;
if ( V_96 -> V_130 < 0 ) {
V_53 -> V_120 = 1 ;
F_4 ( & V_53 -> V_135 , & V_96 -> V_131 ) ;
return V_136 ;
}
}
if ( ! V_53 -> V_89 ) {
F_15 ( ( V_118 -> V_137 < 0 ) ==
! F_55 ( & V_118 -> V_138 ) ) ;
V_53 -> V_89 = 1 ;
V_118 -> V_137 -- ;
if ( V_118 -> V_137 < V_118 -> V_139 )
V_118 -> V_139 = V_118 -> V_137 ;
if ( V_118 -> V_137 < 0 ) {
V_53 -> V_120 = 1 ;
F_4 ( & V_53 -> V_135 , & V_118 -> V_138 ) ;
return V_136 ;
}
}
if ( V_113 ) {
F_5 ( V_115 ) ;
F_33 ( V_51 , V_53 ) ;
F_3 ( V_115 ) ;
}
return V_140 ;
}
static T_9 *
F_56 ( T_5 * V_53 )
{
T_9 * V_141 ;
int V_115 ;
F_15 ( V_53 -> V_142 ) ;
V_115 = V_53 -> V_143 ;
V_141 = & V_13 . V_144 [ V_115 ] [ 0 ] ;
F_15 ( V_53 -> V_60 <= V_145 ) ;
while ( V_53 -> V_60 > ( unsigned int ) V_141 -> V_146 * V_50 ) {
V_141 ++ ;
F_15 ( V_141 < & V_13 . V_144 [ V_115 ] [ V_147 ] ) ;
}
return V_141 ;
}
static int
F_57 ( T_5 * V_53 , int V_148 )
{
T_8 * V_96 = V_53 -> V_94 ;
T_9 * V_141 ;
T_10 * V_149 ;
F_15 ( ! V_53 -> V_64 ) ;
F_15 ( ! V_53 -> V_65 ) ;
F_15 ( ! V_53 -> V_63 ) ;
F_15 ( V_53 -> V_70 ) ;
F_15 ( V_53 -> V_58 ) ;
F_15 ( ! V_53 -> V_59 ) ;
F_15 ( ! V_148 || V_53 -> V_150 ) ;
if ( ! V_53 -> V_151 ) {
F_15 ( ( V_96 -> V_152 < 0 ) ==
! F_55 ( & V_96 -> V_153 ) ) ;
V_53 -> V_151 = 1 ;
V_96 -> V_152 -- ;
if ( V_96 -> V_152 < V_96 -> V_154 )
V_96 -> V_154 = V_96 -> V_152 ;
if ( V_96 -> V_152 < 0 ) {
F_15 ( V_53 -> V_92 ) ;
V_53 -> V_150 = 1 ;
F_4 ( & V_53 -> V_135 , & V_96 -> V_153 ) ;
return V_136 ;
}
}
V_141 = F_56 ( V_53 ) ;
if ( ! V_53 -> V_155 ) {
V_53 -> V_155 = 1 ;
V_141 -> V_156 -- ;
if ( V_141 -> V_156 < V_141 -> V_157 )
V_141 -> V_157 = V_141 -> V_156 ;
if ( V_141 -> V_156 < 0 ) {
F_15 ( V_53 -> V_92 ) ;
V_53 -> V_150 = 1 ;
F_4 ( & V_53 -> V_135 , & V_141 -> V_158 ) ;
return V_136 ;
}
}
F_15 ( ! F_55 ( & V_141 -> V_159 ) ) ;
V_149 = F_8 ( V_141 -> V_159 . V_7 , T_10 , V_160 ) ;
F_9 ( & V_149 -> V_160 ) ;
V_53 -> V_63 = V_141 -> V_146 ;
V_53 -> V_65 = & V_149 -> V_161 [ 0 ] ;
if ( V_148 ) {
int V_115 = V_53 -> V_143 ;
F_5 ( V_115 ) ;
F_27 ( V_96 -> V_108 , V_53 -> V_86 , V_53 , 1 ,
0 , V_53 -> V_60 , V_53 -> V_60 ) ;
F_3 ( V_115 ) ;
}
return V_140 ;
}
void
F_58 ( T_5 * V_53 )
{
T_8 * V_162 = V_53 -> V_114 ;
T_5 * V_163 ;
if ( V_53 -> V_89 ) {
struct V_164 * V_51 = V_162 -> V_108 ;
struct V_117 * V_118 = V_51 -> V_119 [ V_53 -> V_116 ] ;
V_53 -> V_89 = 0 ;
F_15 ( ( V_118 -> V_137 < 0 ) ==
! F_55 ( & V_118 -> V_138 ) ) ;
V_118 -> V_137 ++ ;
if ( V_118 -> V_137 <= 0 ) {
V_163 = F_8 ( V_118 -> V_138 . V_7 ,
T_5 , V_135 ) ;
F_9 ( & V_163 -> V_135 ) ;
F_15 ( V_163 -> V_114 -> V_108 == V_51 ) ;
F_15 ( V_163 -> V_120 ) ;
( void ) F_53 ( V_163 , 1 ) ;
}
}
if ( V_53 -> V_90 ) {
V_53 -> V_90 = 0 ;
F_15 ( ( V_162 -> V_130 < 0 ) ==
! F_55 ( & V_162 -> V_131 ) ) ;
V_162 -> V_132 -= V_53 -> V_60 + sizeof( V_133 ) ;
F_15 ( V_162 -> V_132 >= 0 ) ;
V_162 -> V_130 ++ ;
if ( V_162 -> V_130 <= 0 ) {
V_163 = F_8 ( V_162 -> V_131 . V_7 ,
T_5 , V_135 ) ;
F_9 ( & V_163 -> V_135 ) ;
F_15 ( V_163 -> V_114 == V_162 ) ;
F_15 ( V_163 -> V_120 ) ;
( void ) F_53 ( V_163 , 1 ) ;
}
}
if ( V_162 ) {
V_53 -> V_114 = NULL ;
F_59 ( V_162 ) ;
}
}
void
F_60 ( T_9 * V_141 )
{
T_5 * V_53 ;
if ( F_55 ( & V_141 -> V_158 ) )
return;
V_53 = F_8 ( V_141 -> V_158 . V_7 ,
T_5 , V_135 ) ;
F_9 ( & V_53 -> V_135 ) ;
( void ) F_57 ( V_53 , 1 ) ;
}
void
F_61 ( struct V_5 * V_165 , int V_115 )
{
struct V_5 V_166 ;
T_5 * V_53 ;
T_5 * V_167 ;
F_6 ( & V_166 ) ;
F_62 ( V_165 , & V_166 ) ;
F_5 ( V_115 ) ;
F_11 (msg, tmp, &drop, msg_list) {
F_27 ( V_53 -> V_94 -> V_108 , V_53 -> V_86 , NULL ,
0 , 0 , 0 , V_53 -> V_78 . V_84 ) ;
F_63 ( & V_53 -> V_135 ) ;
F_28 ( NULL , V_53 , - V_129 ) ;
}
F_3 ( V_115 ) ;
}
void
F_64 ( T_5 * V_53 )
{
T_8 * V_168 = V_53 -> V_94 ;
T_5 * V_163 ;
if ( V_53 -> V_155 ) {
T_10 * V_149 ;
T_9 * V_141 ;
F_15 ( V_53 -> V_65 ) ;
V_149 = F_8 ( V_53 -> V_65 , T_10 , V_161 [ 0 ] ) ;
V_141 = V_149 -> V_169 ;
V_53 -> V_65 = NULL ;
V_53 -> V_155 = 0 ;
F_15 ( V_141 == F_56 ( V_53 ) ) ;
F_15 ( ( V_141 -> V_156 > 0 ) ==
! F_55 ( & V_141 -> V_159 ) ) ;
if ( ! V_13 . V_170 ) {
F_65 ( V_149 , V_141 -> V_146 ) ;
goto V_171;
}
if ( F_66 ( V_141 -> V_156 >= V_141 -> V_172 ) ) {
F_65 ( V_149 , V_141 -> V_146 ) ;
V_141 -> V_173 -- ;
} else {
F_10 ( & V_149 -> V_160 , & V_141 -> V_159 ) ;
V_141 -> V_156 ++ ;
if ( V_141 -> V_156 <= 0 )
F_60 ( V_141 ) ;
}
}
V_171:
if ( V_53 -> V_151 ) {
V_53 -> V_151 = 0 ;
F_15 ( ( V_168 -> V_152 < 0 ) ==
! F_55 ( & V_168 -> V_153 ) ) ;
V_168 -> V_152 ++ ;
if ( ! V_13 . V_170 ) {
F_61 ( & V_168 -> V_153 ,
V_53 -> V_143 ) ;
} else if ( V_168 -> V_152 <= 0 ) {
V_163 = F_8 ( V_168 -> V_153 . V_7 ,
T_5 , V_135 ) ;
F_9 ( & V_163 -> V_135 ) ;
( void ) F_57 ( V_163 , 1 ) ;
}
}
if ( V_168 ) {
V_53 -> V_94 = NULL ;
F_59 ( V_168 ) ;
}
}
static int
F_67 ( T_11 * V_174 , T_11 * V_175 )
{
T_8 * V_176 = V_174 -> V_177 ;
T_8 * V_178 = V_175 -> V_177 ;
int V_179 = ( V_174 -> V_180 == V_181 ) ? 1 : V_174 -> V_180 ;
int V_182 = ( V_175 -> V_180 == V_181 ) ? 1 : V_175 -> V_180 ;
if ( V_174 -> V_183 < V_175 -> V_183 )
return 1 ;
if ( V_174 -> V_183 > V_175 -> V_183 )
return - V_184 ;
if ( V_179 < V_182 )
return 1 ;
if ( V_179 > V_182 )
return - V_184 ;
if ( V_176 -> V_132 < V_178 -> V_132 )
return 1 ;
if ( V_176 -> V_132 > V_178 -> V_132 )
return - V_184 ;
if ( V_176 -> V_130 > V_178 -> V_130 )
return 1 ;
if ( V_176 -> V_130 < V_178 -> V_130 )
return - V_184 ;
if ( V_174 -> V_185 - V_175 -> V_185 <= 0 )
return 1 ;
return - V_184 ;
}
static T_8 *
F_68 ( T_4 * V_51 , T_1 V_75 , T_1 V_186 )
{
T_12 * V_187 ;
T_11 * V_188 ;
T_11 * V_189 ;
T_11 * V_190 ;
struct V_191 * V_192 ;
struct V_191 * V_96 ;
int V_57 ;
V_187 = F_69 ( F_35 ( V_75 ) ) ;
if ( ! V_187 )
return NULL ;
V_192 = NULL ;
V_189 = NULL ;
V_190 = NULL ;
F_70 (route, &rnet->lrn_routes, lr_list) {
V_96 = V_188 -> V_177 ;
if ( ! F_71 ( V_188 ) )
continue;
if ( V_51 && V_96 -> V_108 != V_51 )
continue;
if ( V_96 -> V_95 == V_186 )
return V_96 ;
if ( ! V_192 ) {
V_189 = V_188 ;
V_190 = V_188 ;
V_192 = V_96 ;
continue;
}
if ( V_190 -> V_185 - V_188 -> V_185 < 0 )
V_190 = V_188 ;
V_57 = F_67 ( V_188 , V_189 ) ;
if ( V_57 < 0 )
continue;
V_189 = V_188 ;
V_192 = V_96 ;
}
if ( V_189 )
V_189 -> V_185 = V_190 -> V_185 + 1 ;
return V_192 ;
}
int
F_72 ( T_1 V_193 , T_5 * V_53 , T_1 V_186 )
{
T_1 V_194 = V_53 -> V_77 . V_1 ;
struct V_164 * V_195 ;
struct V_164 * V_196 ;
struct V_191 * V_96 ;
int V_115 ;
int V_197 ;
int V_57 ;
F_15 ( ! V_53 -> V_114 ) ;
F_15 ( ! V_53 -> V_59 ) ;
F_15 ( ! V_53 -> V_198 ) ;
F_15 ( ! V_53 -> V_58 ) ;
V_53 -> V_59 = 1 ;
F_15 ( ! V_53 -> V_121 ) ;
V_115 = F_73 ( V_186 == V_15 ? V_194 : V_186 ) ;
V_199:
F_3 ( V_115 ) ;
if ( V_13 . V_200 ) {
F_5 ( V_115 ) ;
return - V_201 ;
}
if ( V_193 == V_15 ) {
V_195 = NULL ;
} else {
V_195 = F_74 ( V_193 , V_115 ) ;
if ( ! V_195 ) {
F_5 ( V_115 ) ;
F_75 ( L_5 ,
F_38 ( V_194 ) ,
F_38 ( V_193 ) ) ;
return - V_202 ;
}
F_15 ( ! V_53 -> V_70 ) ;
}
V_196 = F_76 ( F_35 ( V_194 ) , V_115 ) ;
if ( V_196 ) {
if ( ! V_195 ) {
V_195 = V_196 ;
V_193 = V_195 -> V_87 ;
} else if ( V_195 == V_196 ) {
F_77 ( V_196 , V_115 ) ;
} else {
F_77 ( V_196 , V_115 ) ;
F_77 ( V_195 , V_115 ) ;
F_5 ( V_115 ) ;
F_75 ( L_6 ,
F_38 ( V_194 ) ,
F_38 ( V_193 ) ) ;
return - V_202 ;
}
F_15 ( V_193 != V_15 ) ;
F_78 ( V_53 , V_115 ) ;
if ( ! V_53 -> V_70 )
V_53 -> V_78 . V_193 = F_32 ( V_193 ) ;
if ( V_195 == V_13 . V_203 ) {
F_5 ( V_115 ) ;
F_33 ( V_195 , V_53 ) ;
F_3 ( V_115 ) ;
F_77 ( V_195 , V_115 ) ;
F_5 ( V_115 ) ;
return 0 ;
}
V_57 = F_79 ( & V_96 , V_194 , V_115 ) ;
F_77 ( V_195 , V_115 ) ;
if ( V_57 ) {
F_5 ( V_115 ) ;
F_75 ( L_7 , V_57 ,
F_38 ( V_194 ) ) ;
return V_57 ;
}
F_15 ( V_96 -> V_108 == V_195 ) ;
} else {
V_96 = F_68 ( V_195 , V_194 , V_186 ) ;
if ( ! V_96 ) {
if ( V_195 )
F_77 ( V_195 , V_115 ) ;
F_5 ( V_115 ) ;
F_75 ( L_8 ,
F_39 ( V_53 -> V_77 ) ,
F_38 ( V_193 ) ) ;
return - V_126 ;
}
if ( V_186 != V_96 -> V_95 ) {
V_197 = F_80 ( V_96 -> V_95 ) ;
if ( V_197 != V_115 ) {
if ( V_195 )
F_77 ( V_195 , V_115 ) ;
F_5 ( V_115 ) ;
V_186 = V_96 -> V_95 ;
V_115 = V_197 ;
goto V_199;
}
}
F_81 ( V_204 , L_9 ,
F_38 ( V_194 ) , F_38 ( V_96 -> V_95 ) ,
F_82 ( V_53 -> V_76 ) , V_53 -> V_60 ) ;
if ( ! V_195 ) {
V_195 = V_96 -> V_108 ;
V_193 = V_195 -> V_87 ;
} else {
F_15 ( V_195 == V_96 -> V_108 ) ;
F_77 ( V_195 , V_115 ) ;
}
F_83 ( V_96 ) ;
F_15 ( V_193 != V_15 ) ;
F_78 ( V_53 , V_115 ) ;
if ( ! V_53 -> V_70 ) {
V_53 -> V_78 . V_193 = F_32 ( V_193 ) ;
}
V_53 -> V_198 = 1 ;
V_53 -> V_77 . V_1 = V_96 -> V_95 ;
V_53 -> V_77 . V_81 = V_205 ;
}
F_15 ( ! V_53 -> V_90 ) ;
F_15 ( ! V_53 -> V_89 ) ;
F_15 ( ! V_53 -> V_114 ) ;
V_53 -> V_114 = V_96 ;
V_57 = F_53 ( V_53 , 0 ) ;
F_5 ( V_115 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 == V_140 )
F_33 ( V_195 , V_53 ) ;
return 0 ;
}
void
F_84 ( T_4 * V_51 , int V_115 , void * V_52 , unsigned int V_22 )
{
F_3 ( V_115 ) ;
V_13 . V_123 [ V_115 ] -> V_124 ++ ;
V_13 . V_123 [ V_115 ] -> V_125 += V_22 ;
F_5 ( V_115 ) ;
F_27 ( V_51 , V_52 , NULL , 0 , 0 , 0 , V_22 ) ;
}
static void
F_85 ( T_4 * V_51 , T_5 * V_53 )
{
V_133 * V_206 = & V_53 -> V_78 ;
if ( V_53 -> V_62 )
F_29 ( V_53 ) ;
F_86 ( V_53 , V_207 ) ;
V_53 -> V_208 = ! F_87 ( & V_206 -> V_53 . V_209 . V_210 ) &&
! ( V_53 -> V_69 -> V_72 & V_211 ) ;
F_27 ( V_51 , V_53 -> V_86 , V_53 , V_53 -> V_150 ,
V_53 -> V_61 , V_53 -> V_62 , V_206 -> V_84 ) ;
}
static int
F_88 ( T_4 * V_51 , T_5 * V_53 )
{
V_133 * V_206 = & V_53 -> V_78 ;
struct V_212 V_213 ;
bool V_214 ;
int V_57 ;
V_206 -> V_53 . V_209 . V_215 = F_89 ( V_206 -> V_53 . V_209 . V_215 ) ;
V_206 -> V_53 . V_209 . V_216 = F_90 ( V_206 -> V_53 . V_209 . V_216 ) ;
V_206 -> V_53 . V_209 . V_36 = F_90 ( V_206 -> V_53 . V_209 . V_36 ) ;
V_213 . V_217 . V_1 = V_206 -> V_193 ;
V_213 . V_217 . V_81 = V_206 -> V_82 ;
V_213 . V_218 = V_219 ;
V_213 . V_220 = V_206 -> V_53 . V_209 . V_216 ;
V_213 . V_221 = V_206 -> V_84 ;
V_213 . V_222 = V_206 -> V_53 . V_209 . V_36 ;
V_213 . V_223 = V_206 -> V_53 . V_209 . V_215 ;
V_53 -> V_92 = ! V_51 -> V_66 -> V_93 ;
V_214 = V_53 -> V_92 ;
V_199:
V_57 = F_91 ( & V_213 , V_53 ) ;
switch ( V_57 ) {
default:
F_92 () ;
case V_224 :
F_85 ( V_51 , V_53 ) ;
return 0 ;
case V_225 :
if ( V_214 )
return 0 ;
V_57 = F_36 ( V_51 , V_53 ) ;
if ( ! V_57 ) {
V_214 = true ;
goto V_199;
}
case V_226 :
F_54 ( L_10 ,
F_39 ( V_213 . V_217 ) , V_213 . V_220 ,
V_213 . V_223 , V_213 . V_222 , V_213 . V_221 , V_57 ) ;
return - V_227 ;
}
}
static int
F_93 ( T_4 * V_51 , T_5 * V_53 , int V_228 )
{
struct V_212 V_213 ;
V_133 * V_206 = & V_53 -> V_78 ;
T_13 V_229 ;
int V_57 ;
V_206 -> V_53 . V_230 . V_215 = F_89 ( V_206 -> V_53 . V_230 . V_215 ) ;
V_206 -> V_53 . V_230 . V_216 = F_90 ( V_206 -> V_53 . V_230 . V_216 ) ;
V_206 -> V_53 . V_230 . V_231 = F_90 ( V_206 -> V_53 . V_230 . V_231 ) ;
V_206 -> V_53 . V_230 . V_232 = F_90 ( V_206 -> V_53 . V_230 . V_232 ) ;
V_213 . V_217 . V_1 = V_206 -> V_193 ;
V_213 . V_217 . V_81 = V_206 -> V_82 ;
V_213 . V_218 = V_233 ;
V_213 . V_220 = V_206 -> V_53 . V_230 . V_216 ;
V_213 . V_221 = V_206 -> V_53 . V_230 . V_231 ;
V_213 . V_222 = V_206 -> V_53 . V_230 . V_232 ;
V_213 . V_223 = V_206 -> V_53 . V_230 . V_215 ;
V_57 = F_91 ( & V_213 , V_53 ) ;
if ( V_57 == V_226 ) {
F_54 ( L_11 ,
F_39 ( V_213 . V_217 ) , V_213 . V_220 ,
V_213 . V_223 , V_213 . V_222 , V_213 . V_221 ) ;
return - V_227 ;
}
F_15 ( V_57 == V_224 ) ;
F_86 ( V_53 , V_234 ) ;
V_229 = V_206 -> V_53 . V_230 . V_235 ;
F_30 ( V_53 , V_236 , V_213 . V_217 ,
V_53 -> V_61 , V_53 -> V_62 ) ;
V_53 -> V_78 . V_53 . V_237 . V_238 = V_229 ;
if ( V_228 ) {
F_27 ( V_51 , V_53 -> V_86 , V_53 , 0 ,
V_53 -> V_61 , V_53 -> V_60 , V_53 -> V_60 ) ;
return 0 ;
}
F_27 ( V_51 , V_53 -> V_86 , NULL , 0 , 0 , 0 , 0 ) ;
V_53 -> V_58 = 0 ;
V_57 = F_72 ( V_51 -> V_87 , V_53 , V_15 ) ;
if ( V_57 < 0 ) {
F_37 ( L_12 ,
F_38 ( V_51 -> V_87 ) ,
F_39 ( V_213 . V_217 ) , V_57 ) ;
F_28 ( V_51 , V_53 , V_57 ) ;
}
return 0 ;
}
static int
F_94 ( T_4 * V_51 , T_5 * V_53 )
{
void * V_52 = V_53 -> V_86 ;
V_133 * V_206 = & V_53 -> V_78 ;
T_7 V_35 = { 0 } ;
T_6 * V_68 ;
int V_239 ;
int V_240 ;
int V_115 ;
V_115 = F_95 ( V_206 -> V_53 . V_237 . V_238 . V_241 ) ;
F_96 ( V_115 ) ;
V_35 . V_1 = V_206 -> V_193 ;
V_35 . V_81 = V_206 -> V_82 ;
V_68 = F_97 ( & V_206 -> V_53 . V_237 . V_238 ) ;
if ( ! V_68 || ! V_68 -> V_242 || V_68 -> V_243 ) {
F_54 ( L_13 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
! V_68 ? L_14 : L_15 ,
V_206 -> V_53 . V_237 . V_238 . V_244 ,
V_206 -> V_53 . V_237 . V_238 . V_241 ) ;
if ( V_68 && V_68 -> V_243 )
F_37 ( L_16 ,
V_68 -> V_243 -> V_245 ) ;
F_98 ( V_115 ) ;
return - V_227 ;
}
F_15 ( ! V_68 -> V_246 ) ;
V_239 = V_206 -> V_84 ;
V_240 = F_99 ( V_247 , V_239 , V_68 -> V_248 ) ;
if ( V_240 < V_239 &&
! ( V_68 -> V_72 & V_249 ) ) {
F_54 ( L_17 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
V_239 , V_206 -> V_53 . V_237 . V_238 . V_241 ,
V_240 ) ;
F_98 ( V_115 ) ;
return - V_227 ;
}
F_81 ( V_204 , L_18 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
V_240 , V_239 , V_206 -> V_53 . V_237 . V_238 . V_241 ) ;
F_100 ( V_53 , V_68 , 0 , V_240 ) ;
if ( V_240 )
F_29 ( V_53 ) ;
F_98 ( V_115 ) ;
F_86 ( V_53 , V_250 ) ;
F_27 ( V_51 , V_52 , V_53 , 0 , 0 , V_240 , V_239 ) ;
return 0 ;
}
static int
F_101 ( T_4 * V_51 , T_5 * V_53 )
{
V_133 * V_206 = & V_53 -> V_78 ;
T_7 V_35 = { 0 } ;
T_6 * V_68 ;
int V_115 ;
V_35 . V_1 = V_206 -> V_193 ;
V_35 . V_81 = V_206 -> V_82 ;
V_206 -> V_53 . V_251 . V_215 = F_89 ( V_206 -> V_53 . V_251 . V_215 ) ;
V_206 -> V_53 . V_251 . V_240 = F_90 ( V_206 -> V_53 . V_251 . V_240 ) ;
V_115 = F_95 ( V_206 -> V_53 . V_251 . V_238 . V_241 ) ;
F_96 ( V_115 ) ;
V_68 = F_97 ( & V_206 -> V_53 . V_251 . V_238 ) ;
if ( ! V_68 || ! V_68 -> V_242 || V_68 -> V_243 ) {
F_81 ( V_204 ,
L_19 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
! V_68 ? L_14 : L_15 ,
V_206 -> V_53 . V_251 . V_238 . V_244 ,
V_206 -> V_53 . V_251 . V_238 . V_241 ) ;
if ( V_68 && V_68 -> V_243 )
F_37 ( L_20 ,
V_68 -> V_243 -> V_245 ) ;
F_98 ( V_115 ) ;
return - V_227 ;
}
F_81 ( V_204 , L_21 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
V_206 -> V_53 . V_251 . V_238 . V_241 ) ;
F_100 ( V_53 , V_68 , 0 , 0 ) ;
F_98 ( V_115 ) ;
F_86 ( V_53 , V_252 ) ;
F_27 ( V_51 , V_53 -> V_86 , V_53 , 0 , 0 , 0 , V_53 -> V_60 ) ;
return 0 ;
}
int
F_102 ( T_4 * V_51 , T_5 * V_53 )
{
int V_57 = 0 ;
if ( ! V_13 . V_170 )
return - V_129 ;
if ( V_53 -> V_94 -> V_152 <= 0 ||
F_56 ( V_53 ) -> V_156 <= 0 ) {
if ( ! V_51 -> V_66 -> V_93 ) {
V_53 -> V_92 = 1 ;
} else {
F_5 ( V_53 -> V_143 ) ;
V_57 = F_36 ( V_51 , V_53 ) ;
F_3 ( V_53 -> V_143 ) ;
}
}
if ( ! V_57 )
V_57 = F_57 ( V_53 , 0 ) ;
return V_57 ;
}
int
F_103 ( T_4 * V_51 , T_5 * V_53 )
{
int V_57 ;
switch ( V_53 -> V_76 ) {
case V_253 :
V_57 = F_101 ( V_51 , V_53 ) ;
break;
case V_254 :
V_57 = F_88 ( V_51 , V_53 ) ;
break;
case V_255 :
V_57 = F_93 ( V_51 , V_53 , V_53 -> V_256 ) ;
break;
case V_236 :
V_57 = F_94 ( V_51 , V_53 ) ;
break;
default:
F_15 ( 0 ) ;
return - V_257 ;
}
F_15 ( ! V_57 || V_57 == - V_227 ) ;
return V_57 ;
}
char *
F_82 ( int type )
{
switch ( type ) {
case V_253 :
return L_22 ;
case V_254 :
return L_23 ;
case V_255 :
return L_24 ;
case V_236 :
return L_25 ;
case V_258 :
return L_26 ;
default:
return L_27 ;
}
}
void
F_104 ( V_133 * V_206 )
{
T_7 V_35 = { 0 } ;
T_7 V_33 = { 0 } ;
char * V_259 = F_82 ( V_206 -> type ) ;
V_35 . V_1 = V_206 -> V_193 ;
V_35 . V_81 = V_206 -> V_82 ;
V_33 . V_1 = V_206 -> V_79 ;
V_33 . V_81 = V_206 -> V_80 ;
F_52 ( L_28 , V_206 , V_259 ) ;
F_52 ( L_29 , F_39 ( V_35 ) ) ;
F_52 ( L_30 , F_39 ( V_33 ) ) ;
switch ( V_206 -> type ) {
default:
break;
case V_254 :
F_52 ( L_31 ,
V_206 -> V_53 . V_209 . V_216 ,
V_206 -> V_53 . V_209 . V_210 . V_244 ,
V_206 -> V_53 . V_209 . V_210 . V_241 ,
V_206 -> V_53 . V_209 . V_215 ) ;
F_52 ( L_32 ,
V_206 -> V_84 , V_206 -> V_53 . V_209 . V_36 ,
V_206 -> V_53 . V_209 . V_260 ) ;
break;
case V_255 :
F_52 ( L_33 ,
V_206 -> V_53 . V_230 . V_216 ,
V_206 -> V_53 . V_230 . V_235 . V_244 ,
V_206 -> V_53 . V_230 . V_235 . V_241 ,
V_206 -> V_53 . V_230 . V_215 ) ;
F_52 ( L_34 ,
V_206 -> V_53 . V_230 . V_231 ,
V_206 -> V_53 . V_230 . V_232 ) ;
break;
case V_253 :
F_52 ( L_35 ,
V_206 -> V_53 . V_251 . V_238 . V_244 ,
V_206 -> V_53 . V_251 . V_238 . V_241 ,
V_206 -> V_53 . V_251 . V_240 ) ;
break;
case V_236 :
F_52 ( L_36 ,
V_206 -> V_53 . V_237 . V_238 . V_244 ,
V_206 -> V_53 . V_237 . V_238 . V_241 ,
V_206 -> V_84 ) ;
}
}
int
F_105 ( T_4 * V_51 , V_133 * V_206 , T_1 V_261 ,
void * V_52 , int V_262 )
{
int V_57 = 0 ;
int V_115 ;
int V_263 ;
struct V_264 * V_53 ;
T_14 V_80 ;
T_1 V_79 ;
T_1 V_193 ;
T_15 V_84 ;
T_15 type ;
F_15 ( ! F_21 () ) ;
type = F_90 ( V_206 -> type ) ;
V_193 = F_89 ( V_206 -> V_193 ) ;
V_79 = F_89 ( V_206 -> V_79 ) ;
V_80 = F_90 ( V_206 -> V_80 ) ;
V_84 = F_90 ( V_206 -> V_84 ) ;
V_263 = ( V_51 -> V_87 == V_79 ) ;
V_115 = F_73 ( V_261 ) ;
switch ( type ) {
case V_253 :
case V_255 :
if ( V_84 > 0 ) {
F_37 ( L_37 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) ,
F_82 ( type ) , V_84 ) ;
return - V_257 ;
}
break;
case V_254 :
case V_236 :
if ( V_84 >
( T_15 ) ( V_263 ? V_265 : V_145 ) ) {
F_37 ( L_38 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) ,
F_82 ( type ) ,
V_84 ,
V_263 ? V_265 : V_145 ) ;
return - V_257 ;
}
break;
default:
F_37 ( L_39 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) , type ) ;
return - V_257 ;
}
if ( V_13 . V_170 &&
V_51 -> V_266 != F_106 () ) {
F_107 ( V_51 ) ;
V_51 -> V_266 = F_106 () ;
if ( V_51 -> V_267 &&
V_51 -> V_267 -> V_268 == V_269 )
V_51 -> V_267 -> V_268 = V_270 ;
F_108 ( V_51 ) ;
}
if ( ! V_263 ) {
if ( F_35 ( V_79 ) == F_35 ( V_51 -> V_87 ) ) {
F_37 ( L_40 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) ,
F_38 ( V_79 ) ) ;
return - V_257 ;
}
if ( F_109 ( V_79 ) ) {
F_37 ( L_41 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) ,
F_38 ( V_79 ) ) ;
return - V_257 ;
}
if ( V_262 && type == V_255 ) {
F_37 ( L_42 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) ,
F_38 ( V_79 ) ) ;
return - V_257 ;
}
if ( ! V_13 . V_170 ) {
F_37 ( L_43 ,
F_38 ( V_261 ) ,
F_38 ( V_193 ) ,
F_38 ( V_79 ) ) ;
goto V_166;
}
}
if ( ! F_55 ( & V_13 . V_14 ) &&
F_13 ( V_193 , 0 ) ) {
F_37 ( L_44 ,
F_38 ( V_261 ) , F_38 ( V_193 ) ,
F_82 ( type ) ) ;
goto V_166;
}
if ( ! F_55 ( & V_13 . V_271 ) &&
F_110 ( V_206 ) ) {
F_81 ( V_204 , L_45 ,
F_38 ( V_261 ) , F_38 ( V_193 ) ,
F_38 ( V_79 ) , F_82 ( type ) ) ;
goto V_166;
}
V_53 = F_111 () ;
if ( ! V_53 ) {
F_37 ( L_46 ,
F_38 ( V_261 ) , F_38 ( V_193 ) ,
F_82 ( type ) ) ;
goto V_166;
}
V_53 -> V_76 = type ;
V_53 -> V_86 = V_52 ;
V_53 -> V_58 = 1 ;
V_53 -> V_256 = V_262 ;
V_53 -> V_62 = V_84 ;
V_53 -> V_60 = V_84 ;
V_53 -> V_61 = 0 ;
V_53 -> V_78 = * V_206 ;
V_53 -> V_272 = V_261 ;
if ( ! V_263 ) {
V_53 -> V_77 . V_81 = V_80 ;
V_53 -> V_77 . V_1 = V_79 ;
V_53 -> V_70 = 1 ;
} else {
V_53 -> V_78 . type = type ;
V_53 -> V_78 . V_193 = V_193 ;
V_53 -> V_78 . V_82 = F_90 ( V_53 -> V_78 . V_82 ) ;
V_53 -> V_78 . V_79 = V_79 ;
V_53 -> V_78 . V_80 = V_80 ;
V_53 -> V_78 . V_84 = V_84 ;
}
F_3 ( V_115 ) ;
V_57 = F_79 ( & V_53 -> V_94 , V_261 , V_115 ) ;
if ( V_57 ) {
F_5 ( V_115 ) ;
F_37 ( L_47 ,
F_38 ( V_261 ) , F_38 ( V_193 ) ,
F_82 ( type ) , V_57 ) ;
F_112 ( V_53 ) ;
goto V_166;
}
if ( F_48 ( V_53 -> V_94 ) ) {
F_113 ( V_53 -> V_94 ) ;
if ( V_273 &&
F_35 ( V_193 ) != F_35 ( V_261 ) ) {
F_114 ( V_53 -> V_94 ,
F_35 ( V_193 ) ) ;
}
}
F_78 ( V_53 , V_115 ) ;
if ( F_66 ( ! F_55 ( & V_13 . V_274 ) &&
F_115 ( V_206 , V_53 ) ) ) {
F_5 ( V_115 ) ;
return 0 ;
}
if ( ! V_263 ) {
V_57 = F_102 ( V_51 , V_53 ) ;
F_5 ( V_115 ) ;
if ( V_57 < 0 )
goto V_275;
if ( V_57 == V_140 ) {
F_27 ( V_51 , V_53 -> V_86 , V_53 , 0 ,
0 , V_84 , V_84 ) ;
}
return 0 ;
}
F_5 ( V_115 ) ;
V_57 = F_103 ( V_51 , V_53 ) ;
if ( V_57 )
goto V_275;
return 0 ;
V_275:
F_15 ( ! V_53 -> V_69 ) ;
F_28 ( V_51 , V_53 , V_57 ) ;
V_166:
F_84 ( V_51 , V_115 , V_52 , V_84 ) ;
return 0 ;
}
void
F_116 ( struct V_5 * V_276 , char * V_277 )
{
while ( ! F_55 ( V_276 ) ) {
T_7 V_278 = { 0 } ;
T_5 * V_53 ;
V_53 = F_8 ( V_276 -> V_7 , T_5 , V_135 ) ;
F_9 ( & V_53 -> V_135 ) ;
V_278 . V_1 = V_53 -> V_78 . V_193 ;
V_278 . V_81 = V_53 -> V_78 . V_82 ;
F_15 ( ! V_53 -> V_69 ) ;
F_15 ( V_53 -> V_150 ) ;
F_15 ( V_53 -> V_94 ) ;
F_15 ( V_53 -> V_78 . type == V_254 ) ;
F_52 ( L_48 ,
F_39 ( V_278 ) ,
V_53 -> V_78 . V_53 . V_209 . V_216 ,
V_53 -> V_78 . V_53 . V_209 . V_215 ,
V_53 -> V_78 . V_53 . V_209 . V_36 ,
V_53 -> V_78 . V_84 , V_277 ) ;
F_84 ( V_53 -> V_94 -> V_108 ,
V_53 -> V_94 -> V_99 ,
V_53 -> V_86 , V_53 -> V_60 ) ;
F_28 ( V_53 -> V_94 -> V_108 , V_53 , - V_227 ) ;
}
}
void
F_117 ( struct V_5 * V_276 )
{
while ( ! F_55 ( V_276 ) ) {
T_5 * V_53 ;
T_7 V_278 ;
V_53 = F_8 ( V_276 -> V_7 , T_5 , V_135 ) ;
F_9 ( & V_53 -> V_135 ) ;
V_278 . V_1 = V_53 -> V_78 . V_193 ;
V_278 . V_81 = V_53 -> V_78 . V_82 ;
F_15 ( V_53 -> V_150 ) ;
F_15 ( V_53 -> V_69 ) ;
F_15 ( V_53 -> V_94 ) ;
F_15 ( V_53 -> V_78 . type == V_254 ) ;
F_81 ( V_204 , L_49 ,
F_39 ( V_278 ) , V_53 -> V_78 . V_53 . V_209 . V_216 ,
V_53 -> V_78 . V_53 . V_209 . V_215 ,
V_53 -> V_78 . V_53 . V_209 . V_36 ,
V_53 -> V_78 . V_84 ) ;
F_85 ( V_53 -> V_94 -> V_108 , V_53 ) ;
}
}
int
F_118 ( T_1 V_279 , T_16 V_280 , T_17 V_251 ,
T_7 V_75 , unsigned int V_281 ,
T_18 V_215 , unsigned int V_36 ,
T_18 V_260 )
{
struct V_264 * V_53 ;
struct V_282 * V_68 ;
int V_115 ;
int V_57 ;
F_15 ( V_13 . V_283 > 0 ) ;
if ( ! F_55 ( & V_13 . V_14 ) &&
F_13 ( V_75 . V_1 , 1 ) ) {
F_37 ( L_50 ,
F_39 ( V_75 ) ) ;
return - V_284 ;
}
V_53 = F_111 () ;
if ( ! V_53 ) {
F_37 ( L_51 ,
F_39 ( V_75 ) ) ;
return - V_9 ;
}
V_53 -> V_285 = ! ! F_119 () ;
V_115 = F_95 ( V_280 . V_286 ) ;
F_96 ( V_115 ) ;
V_68 = F_120 ( & V_280 ) ;
if ( ! V_68 || ! V_68 -> V_242 || V_68 -> V_243 ) {
F_37 ( L_52 ,
V_215 , V_281 , F_39 ( V_75 ) ,
! V_68 ? - 1 : V_68 -> V_242 ) ;
if ( V_68 && V_68 -> V_243 )
F_37 ( L_20 ,
V_68 -> V_243 -> V_245 ) ;
F_98 ( V_115 ) ;
F_112 ( V_53 ) ;
return - V_227 ;
}
F_81 ( V_204 , L_53 , F_39 ( V_75 ) ) ;
F_100 ( V_53 , V_68 , 0 , 0 ) ;
F_30 ( V_53 , V_254 , V_75 , 0 , V_68 -> V_248 ) ;
V_53 -> V_78 . V_53 . V_209 . V_215 = F_32 ( V_215 ) ;
V_53 -> V_78 . V_53 . V_209 . V_216 = F_31 ( V_281 ) ;
V_53 -> V_78 . V_53 . V_209 . V_36 = F_31 ( V_36 ) ;
V_53 -> V_78 . V_53 . V_209 . V_260 = V_260 ;
if ( V_251 == V_287 ) {
V_53 -> V_78 . V_53 . V_209 . V_210 . V_244 =
V_13 . V_288 ;
V_53 -> V_78 . V_53 . V_209 . V_210 . V_241 =
V_68 -> V_289 . V_290 ;
} else {
V_53 -> V_78 . V_53 . V_209 . V_210 . V_244 =
V_291 ;
V_53 -> V_78 . V_53 . V_209 . V_210 . V_241 =
V_291 ;
}
F_98 ( V_115 ) ;
F_86 ( V_53 , V_292 ) ;
V_57 = F_72 ( V_279 , V_53 , V_15 ) ;
if ( V_57 ) {
F_54 ( L_54 ,
F_39 ( V_75 ) , V_57 ) ;
F_28 ( NULL , V_53 , V_57 ) ;
}
return 0 ;
}
T_5 *
F_121 ( T_4 * V_51 , T_5 * V_293 )
{
struct V_264 * V_53 = F_111 () ;
struct V_282 * V_294 = V_293 -> V_69 ;
T_7 V_295 = V_293 -> V_77 ;
int V_115 ;
F_15 ( ! V_293 -> V_198 ) ;
F_15 ( ! V_293 -> V_70 ) ;
if ( ! V_53 ) {
F_37 ( L_55 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_295 ) ) ;
goto V_166;
}
V_115 = F_95 ( V_294 -> V_289 . V_290 ) ;
F_96 ( V_115 ) ;
F_15 ( V_294 -> V_296 > 0 ) ;
if ( ! V_294 -> V_242 ) {
F_37 ( L_56 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_295 ) ,
V_294 ) ;
F_98 ( V_115 ) ;
goto V_166;
}
F_15 ( ! V_294 -> V_246 ) ;
F_81 ( V_204 , L_57 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_295 ) , V_294 ) ;
V_53 -> V_272 = V_295 . V_1 ;
V_53 -> V_76 = V_255 ;
V_53 -> V_78 . V_193 = V_295 . V_1 ;
V_53 -> V_78 . V_84 = V_294 -> V_248 ;
V_53 -> V_58 = 1 ;
F_100 ( V_53 , V_294 , V_294 -> V_246 , V_294 -> V_248 ) ;
F_98 ( V_115 ) ;
V_115 = F_73 ( V_295 . V_1 ) ;
F_3 ( V_115 ) ;
F_78 ( V_53 , V_115 ) ;
F_5 ( V_115 ) ;
F_86 ( V_53 , V_250 ) ;
return V_53 ;
V_166:
V_115 = F_73 ( V_295 . V_1 ) ;
F_3 ( V_115 ) ;
V_13 . V_123 [ V_115 ] -> V_124 ++ ;
V_13 . V_123 [ V_115 ] -> V_125 += V_294 -> V_248 ;
F_5 ( V_115 ) ;
if ( V_53 )
F_112 ( V_53 ) ;
return NULL ;
}
void
F_122 ( T_4 * V_51 , T_5 * V_237 , unsigned int V_37 )
{
F_15 ( V_237 ) ;
F_15 ( V_237 -> V_76 == V_255 ) ;
F_15 ( V_237 -> V_297 . type == V_250 ) ;
F_15 ( V_37 <= V_237 -> V_297 . V_240 ) ;
V_237 -> V_297 . V_240 = V_37 ;
}
int
F_123 ( T_1 V_279 , T_16 V_280 ,
T_7 V_75 , unsigned int V_281 ,
T_18 V_215 , unsigned int V_36 )
{
struct V_264 * V_53 ;
struct V_282 * V_68 ;
int V_115 ;
int V_57 ;
F_15 ( V_13 . V_283 > 0 ) ;
if ( ! F_55 ( & V_13 . V_14 ) &&
F_13 ( V_75 . V_1 , 1 ) ) {
F_37 ( L_58 ,
F_39 ( V_75 ) ) ;
return - V_284 ;
}
V_53 = F_111 () ;
if ( ! V_53 ) {
F_37 ( L_59 ,
F_39 ( V_75 ) ) ;
return - V_9 ;
}
V_115 = F_95 ( V_280 . V_286 ) ;
F_96 ( V_115 ) ;
V_68 = F_120 ( & V_280 ) ;
if ( ! V_68 || ! V_68 -> V_242 || V_68 -> V_243 ) {
F_37 ( L_60 ,
V_215 , V_281 , F_39 ( V_75 ) ,
! V_68 ? - 1 : V_68 -> V_242 ) ;
if ( V_68 && V_68 -> V_243 )
F_37 ( L_16 ,
V_68 -> V_243 -> V_245 ) ;
F_98 ( V_115 ) ;
F_112 ( V_53 ) ;
return - V_227 ;
}
F_81 ( V_204 , L_61 , F_39 ( V_75 ) ) ;
F_100 ( V_53 , V_68 , 0 , 0 ) ;
F_30 ( V_53 , V_255 , V_75 , 0 , 0 ) ;
V_53 -> V_78 . V_53 . V_230 . V_215 = F_32 ( V_215 ) ;
V_53 -> V_78 . V_53 . V_230 . V_216 = F_31 ( V_281 ) ;
V_53 -> V_78 . V_53 . V_230 . V_232 = F_31 ( V_36 ) ;
V_53 -> V_78 . V_53 . V_230 . V_231 = F_31 ( V_68 -> V_248 ) ;
V_53 -> V_78 . V_53 . V_230 . V_235 . V_244 =
V_13 . V_288 ;
V_53 -> V_78 . V_53 . V_230 . V_235 . V_241 =
V_68 -> V_289 . V_290 ;
F_98 ( V_115 ) ;
F_86 ( V_53 , V_292 ) ;
V_57 = F_72 ( V_279 , V_53 , V_15 ) ;
if ( V_57 < 0 ) {
F_54 ( L_62 ,
F_39 ( V_75 ) , V_57 ) ;
F_28 ( NULL , V_53 , V_57 ) ;
}
return 0 ;
}
int
F_124 ( T_1 V_298 , T_1 * V_299 , T_15 * V_300 )
{
struct V_5 * V_301 ;
struct V_164 * V_51 ;
T_12 * V_187 ;
T_15 V_302 = F_35 ( V_298 ) ;
int V_303 ;
int V_115 ;
T_15 V_304 = 2 ;
struct V_5 * V_305 ;
F_15 ( V_13 . V_283 > 0 ) ;
V_115 = F_125 () ;
F_126 (e, &the_lnet.ln_nis) {
V_51 = F_8 ( V_301 , T_4 , V_306 ) ;
if ( V_51 -> V_87 == V_298 ) {
if ( V_299 )
* V_299 = V_298 ;
if ( V_300 ) {
if ( F_34 ( F_35 ( V_298 ) ) == V_88 )
* V_300 = 0 ;
else
* V_300 = 1 ;
}
F_5 ( V_115 ) ;
return V_307 ? 0 : 1 ;
}
if ( F_35 ( V_51 -> V_87 ) == V_302 ) {
if ( V_299 )
* V_299 = V_51 -> V_87 ;
if ( V_300 )
* V_300 = V_304 ;
F_5 ( V_115 ) ;
return 1 ;
}
V_304 ++ ;
}
V_305 = F_127 ( V_302 ) ;
F_126 (e, rn_list) {
V_187 = F_8 ( V_301 , T_12 , V_308 ) ;
if ( V_187 -> V_309 == V_302 ) {
T_11 * V_188 ;
T_11 * V_310 = NULL ;
T_15 V_311 = V_181 ;
T_15 V_312 ;
F_15 ( ! F_55 ( & V_187 -> V_313 ) ) ;
F_70 (route, &rnet->lrn_routes,
lr_list) {
V_312 = V_188 -> V_180 ;
if ( V_312 == V_181 )
V_312 = 1 ;
if ( ! V_310 ||
V_312 < V_311 ) {
V_310 = V_188 ;
V_311 = V_312 ;
}
}
F_15 ( V_310 ) ;
V_303 = V_311 ;
if ( V_299 )
* V_299 = V_310 -> V_177 -> V_108 -> V_87 ;
if ( V_300 )
* V_300 = V_304 ;
F_5 ( V_115 ) ;
return V_303 + 1 ;
}
V_304 ++ ;
}
F_5 ( V_115 ) ;
return - V_126 ;
}
