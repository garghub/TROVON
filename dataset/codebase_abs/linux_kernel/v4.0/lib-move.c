int
F_1 ( T_1 V_1 , unsigned int V_2 )
{
T_2 * V_3 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
struct V_4 V_7 ;
F_2 ( V_8 . V_9 ) ;
if ( V_2 != 0 ) {
F_3 ( V_3 , sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return - V_10 ;
V_3 -> V_11 = V_1 ;
V_3 -> V_12 = V_2 ;
F_4 ( 0 ) ;
F_5 ( & V_3 -> V_13 , & V_8 . V_14 ) ;
F_6 ( 0 ) ;
return 0 ;
}
F_7 ( & V_7 ) ;
F_4 ( 0 ) ;
F_8 (el, next, &the_lnet.ln_test_peers) {
V_3 = F_9 ( V_5 , T_2 , V_13 ) ;
if ( V_3 -> V_12 == 0 ||
V_1 == V_15 ||
V_3 -> V_11 == V_1 ) {
F_10 ( & V_3 -> V_13 ) ;
F_11 ( & V_3 -> V_13 , & V_7 ) ;
}
}
F_6 ( 0 ) ;
while ( ! F_12 ( & V_7 ) ) {
V_3 = F_9 ( V_7 . V_6 , T_2 , V_13 ) ;
F_10 ( & V_3 -> V_13 ) ;
F_13 ( V_3 , sizeof( * V_3 ) ) ;
}
return 0 ;
}
static int
F_14 ( T_1 V_1 , int V_16 )
{
T_2 * V_3 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
struct V_4 V_7 ;
int V_17 = 0 ;
F_7 ( & V_7 ) ;
F_4 ( 0 ) ;
F_8 (el, next, &the_lnet.ln_test_peers) {
V_3 = F_9 ( V_5 , T_2 , V_13 ) ;
if ( V_3 -> V_12 == 0 ) {
if ( V_16 ) {
F_10 ( & V_3 -> V_13 ) ;
F_11 ( & V_3 -> V_13 , & V_7 ) ;
}
continue;
}
if ( V_3 -> V_11 == V_15 ||
V_1 == V_3 -> V_11 ) {
V_17 = 1 ;
if ( V_3 -> V_12 != V_18 ) {
V_3 -> V_12 -- ;
if ( V_16 &&
V_3 -> V_12 == 0 ) {
F_10 ( & V_3 -> V_13 ) ;
F_11 ( & V_3 -> V_13 , & V_7 ) ;
}
}
break;
}
}
F_6 ( 0 ) ;
while ( ! F_12 ( & V_7 ) ) {
V_3 = F_9 ( V_7 . V_6 , T_2 , V_13 ) ;
F_10 ( & V_3 -> V_13 ) ;
F_13 ( V_3 , sizeof( * V_3 ) ) ;
}
return V_17 ;
}
unsigned int
F_15 ( unsigned int V_19 , struct V_20 * V_21 )
{
unsigned int V_22 = 0 ;
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
if ( V_22 == 0 )
return;
F_2 ( V_24 > 0 ) ;
while ( V_26 >= V_25 -> V_23 ) {
V_26 -= V_25 -> V_23 ;
V_25 ++ ;
V_24 -- ;
F_2 ( V_24 > 0 ) ;
}
F_2 ( V_27 > 0 ) ;
while ( V_29 >= V_28 -> V_23 ) {
V_29 -= V_28 -> V_23 ;
V_28 ++ ;
V_27 -- ;
F_2 ( V_27 > 0 ) ;
}
do {
F_2 ( V_24 > 0 ) ;
F_2 ( V_27 > 0 ) ;
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
if ( V_37 == 0 )
return 0 ;
F_2 ( V_34 > 0 ) ;
while ( V_36 >= V_35 -> V_23 ) {
V_36 -= V_35 -> V_23 ;
V_34 -- ;
V_35 ++ ;
F_2 ( V_34 > 0 ) ;
}
V_19 = 1 ;
for (; ; ) {
F_2 ( V_34 > 0 ) ;
F_2 ( ( int ) V_19 <= V_32 ) ;
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
if ( V_22 == 0 )
return;
F_2 ( ! F_21 () ) ;
F_2 ( V_24 > 0 ) ;
while ( V_26 >= V_25 -> V_40 ) {
V_26 -= V_25 -> V_40 ;
V_25 ++ ;
V_24 -- ;
F_2 ( V_24 > 0 ) ;
}
F_2 ( V_27 > 0 ) ;
while ( V_29 >= V_28 -> V_40 ) {
V_29 -= V_28 -> V_40 ;
V_28 ++ ;
V_27 -- ;
F_2 ( V_27 > 0 ) ;
}
do {
F_2 ( V_24 > 0 ) ;
F_2 ( V_27 > 0 ) ;
V_30 = F_17 ( V_25 -> V_40 - V_26 ,
V_28 -> V_40 - V_29 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
if ( V_41 == NULL )
V_41 = ( ( char * ) F_22 ( V_25 -> V_43 ) ) +
V_25 -> V_44 + V_26 ;
if ( V_42 == NULL )
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
if ( V_41 != NULL )
F_23 ( V_25 -> V_43 ) ;
if ( V_42 != NULL )
F_23 ( V_28 -> V_43 ) ;
}
void
F_24 ( unsigned int V_19 , struct V_20 * V_21 , unsigned int V_45 ,
unsigned int V_46 , T_3 * V_39 ,
unsigned int V_47 , unsigned int V_22 )
{
unsigned int V_30 ;
char * V_48 = NULL ;
if ( V_22 == 0 )
return;
F_2 ( ! F_21 () ) ;
F_2 ( V_19 > 0 ) ;
while ( V_45 >= V_21 -> V_23 ) {
V_45 -= V_21 -> V_23 ;
V_21 ++ ;
V_19 -- ;
F_2 ( V_19 > 0 ) ;
}
F_2 ( V_46 > 0 ) ;
while ( V_47 >= V_39 -> V_40 ) {
V_47 -= V_39 -> V_40 ;
V_39 ++ ;
V_46 -- ;
F_2 ( V_46 > 0 ) ;
}
do {
F_2 ( V_19 > 0 ) ;
F_2 ( V_46 > 0 ) ;
V_30 = F_17 ( V_21 -> V_23 - V_45 ,
( V_49 ) V_39 -> V_40 - V_47 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
if ( V_48 == NULL )
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
if ( V_48 != NULL )
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
if ( V_22 == 0 )
return;
F_2 ( ! F_21 () ) ;
F_2 ( V_46 > 0 ) ;
while ( V_47 >= V_39 -> V_40 ) {
V_47 -= V_39 -> V_40 ;
V_39 ++ ;
V_46 -- ;
F_2 ( V_46 > 0 ) ;
}
F_2 ( V_19 > 0 ) ;
while ( V_45 >= V_21 -> V_23 ) {
V_45 -= V_21 -> V_23 ;
V_21 ++ ;
V_19 -- ;
F_2 ( V_19 > 0 ) ;
}
do {
F_2 ( V_46 > 0 ) ;
F_2 ( V_19 > 0 ) ;
V_30 = F_17 ( ( V_49 ) V_39 -> V_40 - V_47 ,
V_21 -> V_23 - V_45 ) ;
V_30 = F_17 ( V_30 , V_22 ) ;
if ( V_48 == NULL )
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
if ( V_48 != NULL )
F_23 ( V_39 -> V_43 ) ;
}
int
F_26 ( int V_32 , T_3 * V_33 ,
int V_34 , T_3 * V_35 ,
unsigned int V_36 , unsigned int V_37 )
{
unsigned int V_38 ;
unsigned int V_19 ;
if ( V_37 == 0 )
return 0 ;
F_2 ( V_34 > 0 ) ;
while ( V_36 >= V_35 -> V_40 ) {
V_36 -= V_35 -> V_40 ;
V_34 -- ;
V_35 ++ ;
F_2 ( V_34 > 0 ) ;
}
V_19 = 1 ;
for (; ; ) {
F_2 ( V_34 > 0 ) ;
F_2 ( ( int ) V_19 <= V_32 ) ;
V_38 = V_35 -> V_40 - V_36 ;
V_33 -> V_43 = V_35 -> V_43 ;
V_33 -> V_44 = V_35 -> V_44 + V_36 ;
if ( V_37 <= V_38 ) {
V_33 -> V_40 = V_37 ;
F_2 ( V_33 -> V_44 + V_33 -> V_40
<= V_50 ) ;
return V_19 ;
}
V_33 -> V_40 = V_38 ;
F_2 ( V_33 -> V_44 + V_33 -> V_40 <= V_50 ) ;
V_37 -= V_38 ;
V_33 ++ ;
V_35 ++ ;
V_19 ++ ;
V_34 -- ;
V_36 = 0 ;
}
}
static void
F_27 ( T_4 * V_51 , void * V_52 , T_5 * V_53 , int V_54 ,
unsigned int V_36 , unsigned int V_55 , unsigned int V_56 )
{
unsigned int V_19 = 0 ;
struct V_20 * V_21 = NULL ;
T_3 * V_39 = NULL ;
int V_57 ;
F_2 ( ! F_21 () ) ;
F_2 ( V_55 == 0 || V_53 != NULL ) ;
if ( V_53 != NULL ) {
F_2 ( V_53 -> V_58 ) ;
F_2 ( ! V_53 -> V_59 ) ;
F_2 ( V_56 == V_53 -> V_60 ) ;
F_2 ( V_55 <= V_53 -> V_60 ) ;
F_2 ( V_53 -> V_61 == V_36 ) ;
F_2 ( V_53 -> V_62 == V_55 ) ;
V_53 -> V_58 = 0 ;
if ( V_55 != 0 ) {
V_19 = V_53 -> V_63 ;
V_21 = V_53 -> V_64 ;
V_39 = V_53 -> V_65 ;
F_2 ( V_19 > 0 ) ;
F_2 ( ( V_21 == NULL ) != ( V_39 == NULL ) ) ;
}
}
V_57 = ( V_51 -> V_66 -> V_67 ) ( V_51 , V_52 , V_53 , V_54 ,
V_19 , V_21 , V_39 , V_36 , V_55 , V_56 ) ;
if ( V_57 < 0 )
F_28 ( V_51 , V_53 , V_57 ) ;
}
static void
F_29 ( T_5 * V_53 )
{
T_6 * V_68 = V_53 -> V_69 ;
F_2 ( V_53 -> V_60 > 0 ) ;
F_2 ( ! V_53 -> V_70 ) ;
F_2 ( V_68 != NULL ) ;
F_2 ( V_53 -> V_63 == 0 ) ;
F_2 ( V_53 -> V_64 == NULL ) ;
F_2 ( V_53 -> V_65 == NULL ) ;
V_53 -> V_63 = V_68 -> V_71 ;
if ( ( V_68 -> V_72 & V_73 ) != 0 )
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
if ( V_37 != 0 )
F_29 ( V_53 ) ;
memset ( & V_53 -> V_78 , 0 , sizeof( V_53 -> V_78 ) ) ;
V_53 -> V_78 . type = F_31 ( type ) ;
V_53 -> V_78 . V_79 = F_32 ( V_75 . V_1 ) ;
V_53 -> V_78 . V_80 = F_31 ( V_75 . V_81 ) ;
V_53 -> V_78 . V_82 = F_31 ( V_8 . V_83 ) ;
V_53 -> V_78 . V_84 = F_31 ( V_37 ) ;
}
static void
F_33 ( T_4 * V_51 , T_5 * V_53 )
{
void * V_85 = V_53 -> V_86 ;
int V_57 ;
F_2 ( ! F_21 () ) ;
F_2 ( F_34 ( F_35 ( V_51 -> V_87 ) ) == V_88 ||
( V_53 -> V_89 && V_53 -> V_90 ) ) ;
V_57 = ( V_51 -> V_66 -> V_91 ) ( V_51 , V_85 , V_53 ) ;
if ( V_57 < 0 )
F_28 ( V_51 , V_53 , V_57 ) ;
}
static int
F_36 ( T_4 * V_51 , T_5 * V_53 )
{
int V_57 ;
F_2 ( ! V_53 -> V_59 ) ;
F_2 ( V_53 -> V_58 ) ;
F_2 ( ! V_53 -> V_92 ) ;
F_2 ( V_51 -> V_66 -> V_93 != NULL ) ;
V_53 -> V_92 = 1 ;
V_57 = ( V_51 -> V_66 -> V_93 ) ( V_51 , V_53 -> V_86 , V_53 ,
& V_53 -> V_86 ) ;
if ( V_57 != 0 ) {
F_37 ( L_1 ,
F_38 ( V_53 -> V_94 -> V_95 ) ,
F_39 ( V_53 -> V_77 ) , V_57 ) ;
F_2 ( V_57 < 0 ) ;
}
return V_57 ;
}
static void
F_40 ( T_4 * V_51 , T_8 * V_96 )
{
unsigned long V_97 = 0 ;
F_2 ( F_41 ( V_96 ) ) ;
F_2 ( V_51 -> V_66 -> V_98 != NULL ) ;
F_6 ( V_96 -> V_99 ) ;
( V_51 -> V_66 -> V_98 ) ( V_51 , V_96 -> V_95 , & V_97 ) ;
F_4 ( V_96 -> V_99 ) ;
V_96 -> V_100 = F_42 () ;
if ( V_97 != 0 )
V_96 -> V_101 = V_97 ;
}
static inline int
F_43 ( T_8 * V_96 , unsigned long V_102 )
{
int V_103 ;
unsigned long V_104 ;
F_2 ( F_41 ( V_96 ) ) ;
if ( ! V_96 -> V_105 && V_96 -> V_106 > 0 &&
F_44 ( V_96 -> V_107 , V_96 -> V_101 ) )
return 0 ;
V_104 = F_45 ( V_96 -> V_101 ,
F_46 ( V_96 -> V_108 -> V_109 ) ) ;
V_103 = F_47 ( V_104 , V_102 ) ;
if ( V_103 && ! V_96 -> V_105 &&
! ( F_48 ( V_96 ) && V_96 -> V_106 == 0 ) )
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
if ( V_96 -> V_100 != 0 ) {
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
F_2 ( ! V_113 || V_53 -> V_120 ) ;
F_2 ( ! V_53 -> V_58 ) ;
F_2 ( V_53 -> V_121 ) ;
if ( ( V_53 -> V_77 . V_81 & V_122 ) == 0 &&
F_50 ( V_96 ) == 0 ) {
V_8 . V_123 [ V_115 ] -> V_124 ++ ;
V_8 . V_123 [ V_115 ] -> V_125 += V_53 -> V_60 ;
F_6 ( V_115 ) ;
F_54 ( L_3 ,
F_39 ( V_53 -> V_77 ) ) ;
if ( V_113 )
F_28 ( V_51 , V_53 , - V_126 ) ;
F_4 ( V_115 ) ;
return V_126 ;
}
if ( V_53 -> V_69 != NULL &&
( V_53 -> V_69 -> V_127 & V_128 ) != 0 ) {
F_6 ( V_115 ) ;
F_54 ( L_4 ,
F_39 ( V_53 -> V_77 ) ) ;
if ( V_113 )
F_28 ( V_51 , V_53 , - V_129 ) ;
F_4 ( V_115 ) ;
return V_129 ;
}
if ( ! V_53 -> V_90 ) {
F_2 ( ( V_96 -> V_130 < 0 ) ==
! F_12 ( & V_96 -> V_131 ) ) ;
V_53 -> V_90 = 1 ;
V_96 -> V_132 += V_53 -> V_60 + sizeof( V_133 ) ;
V_96 -> V_130 -- ;
if ( V_96 -> V_130 < V_96 -> V_134 )
V_96 -> V_134 = V_96 -> V_130 ;
if ( V_96 -> V_130 < 0 ) {
V_53 -> V_120 = 1 ;
F_5 ( & V_53 -> V_135 , & V_96 -> V_131 ) ;
return V_136 ;
}
}
if ( ! V_53 -> V_89 ) {
F_2 ( ( V_118 -> V_137 < 0 ) ==
! F_12 ( & V_118 -> V_138 ) ) ;
V_53 -> V_89 = 1 ;
V_118 -> V_137 -- ;
if ( V_118 -> V_137 < V_118 -> V_139 )
V_118 -> V_139 = V_118 -> V_137 ;
if ( V_118 -> V_137 < 0 ) {
V_53 -> V_120 = 1 ;
F_5 ( & V_53 -> V_135 , & V_118 -> V_138 ) ;
return V_136 ;
}
}
if ( V_113 ) {
F_6 ( V_115 ) ;
F_33 ( V_51 , V_53 ) ;
F_4 ( V_115 ) ;
}
return 0 ;
}
static T_9 *
F_55 ( T_5 * V_53 )
{
T_9 * V_140 ;
int V_115 ;
F_2 ( V_53 -> V_141 ) ;
V_115 = V_53 -> V_142 ;
V_140 = & V_8 . V_143 [ V_115 ] [ 0 ] ;
F_2 ( V_53 -> V_60 <= V_144 ) ;
while ( V_53 -> V_60 > ( unsigned int ) V_140 -> V_145 * V_50 ) {
V_140 ++ ;
F_2 ( V_140 < & V_8 . V_143 [ V_115 ] [ V_146 ] ) ;
}
return V_140 ;
}
static int
F_56 ( T_5 * V_53 , int V_147 )
{
T_8 * V_96 = V_53 -> V_94 ;
T_9 * V_140 ;
T_10 * V_148 ;
F_2 ( V_53 -> V_64 == NULL ) ;
F_2 ( V_53 -> V_65 == NULL ) ;
F_2 ( V_53 -> V_63 == 0 ) ;
F_2 ( V_53 -> V_70 ) ;
F_2 ( V_53 -> V_58 ) ;
F_2 ( ! V_53 -> V_59 ) ;
F_2 ( ! V_147 || V_53 -> V_149 ) ;
if ( ! V_53 -> V_150 ) {
F_2 ( ( V_96 -> V_151 < 0 ) ==
! F_12 ( & V_96 -> V_152 ) ) ;
V_53 -> V_150 = 1 ;
V_96 -> V_151 -- ;
if ( V_96 -> V_151 < V_96 -> V_153 )
V_96 -> V_153 = V_96 -> V_151 ;
if ( V_96 -> V_151 < 0 ) {
F_2 ( V_53 -> V_92 ) ;
V_53 -> V_149 = 1 ;
F_5 ( & V_53 -> V_135 , & V_96 -> V_152 ) ;
return V_136 ;
}
}
V_140 = F_55 ( V_53 ) ;
if ( ! V_53 -> V_154 ) {
F_2 ( ( V_140 -> V_155 < 0 ) ==
! F_12 ( & V_140 -> V_156 ) ) ;
V_53 -> V_154 = 1 ;
V_140 -> V_155 -- ;
if ( V_140 -> V_155 < V_140 -> V_157 )
V_140 -> V_157 = V_140 -> V_155 ;
if ( V_140 -> V_155 < 0 ) {
F_2 ( V_53 -> V_92 ) ;
V_53 -> V_149 = 1 ;
F_5 ( & V_53 -> V_135 , & V_140 -> V_156 ) ;
return V_136 ;
}
}
F_2 ( ! F_12 ( & V_140 -> V_158 ) ) ;
V_148 = F_9 ( V_140 -> V_158 . V_6 , T_10 , V_159 ) ;
F_10 ( & V_148 -> V_159 ) ;
V_53 -> V_63 = V_140 -> V_145 ;
V_53 -> V_65 = & V_148 -> V_160 [ 0 ] ;
if ( V_147 ) {
int V_115 = V_53 -> V_142 ;
F_6 ( V_115 ) ;
F_27 ( V_96 -> V_108 , V_53 -> V_86 , V_53 , 1 ,
0 , V_53 -> V_60 , V_53 -> V_60 ) ;
F_4 ( V_115 ) ;
}
return 0 ;
}
void
F_57 ( T_5 * V_53 )
{
T_8 * V_161 = V_53 -> V_114 ;
T_5 * V_162 ;
if ( V_53 -> V_89 ) {
struct V_163 * V_51 = V_161 -> V_108 ;
struct V_117 * V_118 = V_51 -> V_119 [ V_53 -> V_116 ] ;
V_53 -> V_89 = 0 ;
F_2 ( ( V_118 -> V_137 < 0 ) ==
! F_12 ( & V_118 -> V_138 ) ) ;
V_118 -> V_137 ++ ;
if ( V_118 -> V_137 <= 0 ) {
V_162 = F_9 ( V_118 -> V_138 . V_6 ,
T_5 , V_135 ) ;
F_10 ( & V_162 -> V_135 ) ;
F_2 ( V_162 -> V_114 -> V_108 == V_51 ) ;
F_2 ( V_162 -> V_120 ) ;
( void ) F_53 ( V_162 , 1 ) ;
}
}
if ( V_53 -> V_90 ) {
V_53 -> V_90 = 0 ;
F_2 ( ( V_161 -> V_130 < 0 ) ==
! F_12 ( & V_161 -> V_131 ) ) ;
V_161 -> V_132 -= V_53 -> V_60 + sizeof( V_133 ) ;
F_2 ( V_161 -> V_132 >= 0 ) ;
V_161 -> V_130 ++ ;
if ( V_161 -> V_130 <= 0 ) {
V_162 = F_9 ( V_161 -> V_131 . V_6 ,
T_5 , V_135 ) ;
F_10 ( & V_162 -> V_135 ) ;
F_2 ( V_162 -> V_114 == V_161 ) ;
F_2 ( V_162 -> V_120 ) ;
( void ) F_53 ( V_162 , 1 ) ;
}
}
if ( V_161 != NULL ) {
V_53 -> V_114 = NULL ;
F_58 ( V_161 ) ;
}
}
void
F_59 ( T_5 * V_53 )
{
T_8 * V_164 = V_53 -> V_94 ;
T_5 * V_162 ;
if ( V_53 -> V_154 ) {
T_10 * V_148 ;
T_9 * V_140 ;
F_2 ( V_53 -> V_65 != NULL ) ;
V_148 = F_9 ( V_53 -> V_65 , T_10 , V_160 [ 0 ] ) ;
V_140 = V_148 -> V_165 ;
F_2 ( V_140 == F_55 ( V_53 ) ) ;
V_53 -> V_65 = NULL ;
V_53 -> V_154 = 0 ;
F_2 ( ( V_140 -> V_155 < 0 ) ==
! F_12 ( & V_140 -> V_156 ) ) ;
F_2 ( ( V_140 -> V_155 > 0 ) ==
! F_12 ( & V_140 -> V_158 ) ) ;
F_11 ( & V_148 -> V_159 , & V_140 -> V_158 ) ;
V_140 -> V_155 ++ ;
if ( V_140 -> V_155 <= 0 ) {
V_162 = F_9 ( V_140 -> V_156 . V_6 ,
T_5 , V_135 ) ;
F_10 ( & V_162 -> V_135 ) ;
( void ) F_56 ( V_162 , 1 ) ;
}
}
if ( V_53 -> V_150 ) {
V_53 -> V_150 = 0 ;
F_2 ( ( V_164 -> V_151 < 0 ) ==
! F_12 ( & V_164 -> V_152 ) ) ;
V_164 -> V_151 ++ ;
if ( V_164 -> V_151 <= 0 ) {
V_162 = F_9 ( V_164 -> V_152 . V_6 ,
T_5 , V_135 ) ;
F_10 ( & V_162 -> V_135 ) ;
( void ) F_56 ( V_162 , 1 ) ;
}
}
if ( V_164 != NULL ) {
V_53 -> V_94 = NULL ;
F_58 ( V_164 ) ;
}
}
static int
F_60 ( T_11 * V_166 , T_11 * V_167 )
{
T_8 * V_168 = V_166 -> V_169 ;
T_8 * V_170 = V_167 -> V_169 ;
if ( V_166 -> V_171 < V_167 -> V_171 )
return 1 ;
if ( V_166 -> V_171 > V_167 -> V_171 )
return - 1 ;
if ( V_166 -> V_172 < V_167 -> V_172 )
return 1 ;
if ( V_166 -> V_172 > V_167 -> V_172 )
return - 1 ;
if ( V_168 -> V_132 < V_170 -> V_132 )
return 1 ;
if ( V_168 -> V_132 > V_170 -> V_132 )
return - 1 ;
if ( V_168 -> V_130 > V_170 -> V_130 )
return 1 ;
if ( V_168 -> V_130 < V_170 -> V_130 )
return - 1 ;
if ( V_166 -> V_173 - V_167 -> V_173 <= 0 )
return 1 ;
return - 1 ;
}
static T_8 *
F_61 ( T_4 * V_51 , T_1 V_75 , T_1 V_174 )
{
T_12 * V_175 ;
T_11 * V_176 ;
T_11 * V_177 ;
T_11 * V_178 ;
struct V_179 * V_180 ;
struct V_179 * V_96 ;
int V_57 ;
V_175 = F_62 ( F_35 ( V_75 ) ) ;
if ( V_175 == NULL )
return NULL ;
V_180 = NULL ;
V_177 = V_178 = NULL ;
F_63 (rtr, &rnet->lrn_routes, lr_list) {
V_96 = V_176 -> V_169 ;
if ( ! V_96 -> V_105 ||
( ( V_96 -> V_181 & V_182 ) != 0 &&
V_176 -> V_183 != 0 ) )
continue;
if ( V_51 != NULL && V_96 -> V_108 != V_51 )
continue;
if ( V_96 -> V_95 == V_174 )
return V_96 ;
if ( V_180 == NULL ) {
V_177 = V_178 = V_176 ;
V_180 = V_96 ;
continue;
}
if ( V_178 -> V_173 - V_176 -> V_173 < 0 )
V_178 = V_176 ;
V_57 = F_60 ( V_176 , V_177 ) ;
if ( V_57 < 0 )
continue;
V_177 = V_176 ;
V_180 = V_96 ;
}
if ( V_177 != NULL )
V_177 -> V_173 = V_178 -> V_173 + 1 ;
return V_180 ;
}
int
F_64 ( T_1 V_184 , T_5 * V_53 , T_1 V_174 )
{
T_1 V_185 = V_53 -> V_77 . V_1 ;
struct V_163 * V_186 ;
struct V_163 * V_187 ;
struct V_179 * V_96 ;
int V_115 ;
int V_188 ;
int V_57 ;
F_2 ( V_53 -> V_114 == NULL ) ;
F_2 ( ! V_53 -> V_59 ) ;
F_2 ( ! V_53 -> V_189 ) ;
F_2 ( ! V_53 -> V_58 ) ;
V_53 -> V_59 = 1 ;
F_2 ( ! V_53 -> V_121 ) ;
V_115 = F_65 ( V_174 == V_15 ? V_185 : V_174 ) ;
V_190:
F_4 ( V_115 ) ;
if ( V_8 . V_191 ) {
F_6 ( V_115 ) ;
return - V_192 ;
}
if ( V_184 == V_15 ) {
V_186 = NULL ;
} else {
V_186 = F_66 ( V_184 , V_115 ) ;
if ( V_186 == NULL ) {
F_6 ( V_115 ) ;
F_67 ( L_5 ,
F_38 ( V_185 ) ,
F_38 ( V_184 ) ) ;
return - V_193 ;
}
F_2 ( ! V_53 -> V_70 ) ;
}
V_187 = F_68 ( F_35 ( V_185 ) , V_115 ) ;
if ( V_187 != NULL ) {
if ( V_186 == NULL ) {
V_186 = V_187 ;
V_184 = V_186 -> V_87 ;
} else if ( V_186 == V_187 ) {
F_69 ( V_187 , V_115 ) ;
} else {
F_69 ( V_187 , V_115 ) ;
F_69 ( V_186 , V_115 ) ;
F_6 ( V_115 ) ;
F_67 ( L_6 ,
F_38 ( V_185 ) ,
F_38 ( V_184 ) ) ;
return - V_193 ;
}
F_2 ( V_184 != V_15 ) ;
F_70 ( V_53 , V_115 ) ;
if ( ! V_53 -> V_70 )
V_53 -> V_78 . V_184 = F_32 ( V_184 ) ;
if ( V_186 == V_8 . V_194 ) {
F_6 ( V_115 ) ;
F_33 ( V_186 , V_53 ) ;
F_4 ( V_115 ) ;
F_69 ( V_186 , V_115 ) ;
F_6 ( V_115 ) ;
return 0 ;
}
V_57 = F_71 ( & V_96 , V_185 , V_115 ) ;
F_69 ( V_186 , V_115 ) ;
if ( V_57 != 0 ) {
F_6 ( V_115 ) ;
F_67 ( L_7 , V_57 ,
F_38 ( V_185 ) ) ;
return V_57 ;
}
F_2 ( V_96 -> V_108 == V_186 ) ;
} else {
V_96 = F_61 ( V_186 , V_185 , V_174 ) ;
if ( V_96 == NULL ) {
if ( V_186 != NULL )
F_69 ( V_186 , V_115 ) ;
F_6 ( V_115 ) ;
F_67 ( L_8 ,
F_39 ( V_53 -> V_77 ) ,
F_38 ( V_184 ) ) ;
return - V_126 ;
}
if ( V_174 != V_96 -> V_95 ) {
V_188 = F_72 ( V_96 -> V_95 ) ;
if ( V_188 != V_115 ) {
if ( V_186 != NULL )
F_69 ( V_186 , V_115 ) ;
F_6 ( V_115 ) ;
V_174 = V_96 -> V_95 ;
V_115 = V_188 ;
goto V_190;
}
}
F_73 ( V_195 , L_9 ,
F_38 ( V_185 ) , F_38 ( V_96 -> V_95 ) ,
F_74 ( V_53 -> V_76 ) , V_53 -> V_60 ) ;
if ( V_186 == NULL ) {
V_186 = V_96 -> V_108 ;
V_184 = V_186 -> V_87 ;
} else {
F_2 ( V_186 == V_96 -> V_108 ) ;
F_69 ( V_186 , V_115 ) ;
}
F_75 ( V_96 ) ;
F_2 ( V_184 != V_15 ) ;
F_70 ( V_53 , V_115 ) ;
if ( ! V_53 -> V_70 ) {
V_53 -> V_78 . V_184 = F_32 ( V_184 ) ;
}
V_53 -> V_189 = 1 ;
V_53 -> V_77 . V_1 = V_96 -> V_95 ;
V_53 -> V_77 . V_81 = V_196 ;
}
F_2 ( ! V_53 -> V_90 ) ;
F_2 ( ! V_53 -> V_89 ) ;
F_2 ( V_53 -> V_114 == NULL ) ;
V_53 -> V_114 = V_96 ;
V_57 = F_53 ( V_53 , 0 ) ;
F_6 ( V_115 ) ;
if ( V_57 == V_126 || V_57 == V_129 )
return - V_57 ;
if ( V_57 == 0 )
F_33 ( V_186 , V_53 ) ;
return 0 ;
}
static void
F_76 ( T_4 * V_51 , int V_115 , void * V_52 , unsigned int V_22 )
{
F_4 ( V_115 ) ;
V_8 . V_123 [ V_115 ] -> V_124 ++ ;
V_8 . V_123 [ V_115 ] -> V_125 += V_22 ;
F_6 ( V_115 ) ;
F_27 ( V_51 , V_52 , NULL , 0 , 0 , 0 , V_22 ) ;
}
static void
F_77 ( T_4 * V_51 , T_5 * V_53 )
{
V_133 * V_197 = & V_53 -> V_78 ;
if ( V_53 -> V_62 != 0 )
F_29 ( V_53 ) ;
F_78 ( V_53 , V_198 ) ;
V_53 -> V_199 = ( ! F_79 ( & V_197 -> V_53 . V_200 . V_201 ) &&
( V_53 -> V_69 -> V_72 & V_202 ) == 0 ) ;
F_27 ( V_51 , V_53 -> V_86 , V_53 , V_53 -> V_149 ,
V_53 -> V_61 , V_53 -> V_62 , V_197 -> V_84 ) ;
}
static int
F_80 ( T_4 * V_51 , T_5 * V_53 )
{
V_133 * V_197 = & V_53 -> V_78 ;
struct V_203 V_204 ;
int V_57 ;
V_197 -> V_53 . V_200 . V_205 = F_81 ( V_197 -> V_53 . V_200 . V_205 ) ;
V_197 -> V_53 . V_200 . V_206 = F_82 ( V_197 -> V_53 . V_200 . V_206 ) ;
V_197 -> V_53 . V_200 . V_36 = F_82 ( V_197 -> V_53 . V_200 . V_36 ) ;
V_204 . V_207 . V_1 = V_197 -> V_184 ;
V_204 . V_207 . V_81 = V_197 -> V_82 ;
V_204 . V_208 = V_209 ;
V_204 . V_210 = V_197 -> V_53 . V_200 . V_206 ;
V_204 . V_211 = V_197 -> V_84 ;
V_204 . V_212 = V_197 -> V_53 . V_200 . V_36 ;
V_204 . V_213 = V_197 -> V_53 . V_200 . V_205 ;
V_53 -> V_92 = V_51 -> V_66 -> V_93 == NULL ;
V_190:
V_57 = F_83 ( & V_204 , V_53 ) ;
switch ( V_57 ) {
default:
F_84 () ;
case V_214 :
F_77 ( V_51 , V_53 ) ;
return 0 ;
case V_215 :
if ( V_53 -> V_149 )
return 0 ;
V_57 = F_36 ( V_51 , V_53 ) ;
if ( V_57 == 0 )
goto V_190;
case V_216 :
F_54 ( L_10 ,
F_39 ( V_204 . V_207 ) , V_204 . V_210 ,
V_204 . V_213 , V_204 . V_212 , V_204 . V_211 , V_57 ) ;
return V_217 ;
}
}
static int
F_85 ( T_4 * V_51 , T_5 * V_53 , int V_218 )
{
struct V_203 V_204 ;
V_133 * V_197 = & V_53 -> V_78 ;
T_13 V_219 ;
int V_57 ;
V_197 -> V_53 . V_220 . V_205 = F_81 ( V_197 -> V_53 . V_220 . V_205 ) ;
V_197 -> V_53 . V_220 . V_206 = F_82 ( V_197 -> V_53 . V_220 . V_206 ) ;
V_197 -> V_53 . V_220 . V_221 = F_82 ( V_197 -> V_53 . V_220 . V_221 ) ;
V_197 -> V_53 . V_220 . V_222 = F_82 ( V_197 -> V_53 . V_220 . V_222 ) ;
V_204 . V_207 . V_1 = V_197 -> V_184 ;
V_204 . V_207 . V_81 = V_197 -> V_82 ;
V_204 . V_208 = V_223 ;
V_204 . V_210 = V_197 -> V_53 . V_220 . V_206 ;
V_204 . V_211 = V_197 -> V_53 . V_220 . V_221 ;
V_204 . V_212 = V_197 -> V_53 . V_220 . V_222 ;
V_204 . V_213 = V_197 -> V_53 . V_220 . V_205 ;
V_57 = F_83 ( & V_204 , V_53 ) ;
if ( V_57 == V_216 ) {
F_54 ( L_11 ,
F_39 ( V_204 . V_207 ) , V_204 . V_210 ,
V_204 . V_213 , V_204 . V_212 , V_204 . V_211 ) ;
return V_217 ;
}
F_2 ( V_57 == V_214 ) ;
F_78 ( V_53 , V_224 ) ;
V_219 = V_197 -> V_53 . V_220 . V_225 ;
F_30 ( V_53 , V_226 , V_204 . V_207 ,
V_53 -> V_61 , V_53 -> V_62 ) ;
V_53 -> V_78 . V_53 . V_227 . V_228 = V_219 ;
if ( V_218 ) {
F_27 ( V_51 , V_53 -> V_86 , V_53 , 0 ,
V_53 -> V_61 , V_53 -> V_60 , V_53 -> V_60 ) ;
return 0 ;
}
F_27 ( V_51 , V_53 -> V_86 , NULL , 0 , 0 , 0 , 0 ) ;
V_53 -> V_58 = 0 ;
V_57 = F_64 ( V_51 -> V_87 , V_53 , V_15 ) ;
if ( V_57 < 0 ) {
F_37 ( L_12 ,
F_38 ( V_51 -> V_87 ) ,
F_39 ( V_204 . V_207 ) , V_57 ) ;
F_28 ( V_51 , V_53 , V_57 ) ;
}
return 0 ;
}
static int
F_86 ( T_4 * V_51 , T_5 * V_53 )
{
void * V_52 = V_53 -> V_86 ;
V_133 * V_197 = & V_53 -> V_78 ;
T_7 V_35 = { 0 } ;
T_6 * V_68 ;
int V_229 ;
int V_230 ;
int V_115 ;
V_115 = F_87 ( V_197 -> V_53 . V_227 . V_228 . V_231 ) ;
F_88 ( V_115 ) ;
V_35 . V_1 = V_197 -> V_184 ;
V_35 . V_81 = V_197 -> V_82 ;
V_68 = F_89 ( & V_197 -> V_53 . V_227 . V_228 ) ;
if ( V_68 == NULL || V_68 -> V_232 == 0 || V_68 -> V_233 != NULL ) {
F_54 ( L_13 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
( V_68 == NULL ) ? L_14 : L_15 ,
V_197 -> V_53 . V_227 . V_228 . V_234 ,
V_197 -> V_53 . V_227 . V_228 . V_231 ) ;
if ( V_68 != NULL && V_68 -> V_233 != NULL )
F_37 ( L_16 ,
V_68 -> V_233 -> V_235 ) ;
F_90 ( V_115 ) ;
return V_217 ;
}
F_2 ( V_68 -> V_236 == 0 ) ;
V_229 = V_197 -> V_84 ;
V_230 = F_91 ( int , V_229 , V_68 -> V_237 ) ;
if ( V_230 < V_229 &&
( V_68 -> V_72 & V_238 ) == 0 ) {
F_54 ( L_17 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
V_229 , V_197 -> V_53 . V_227 . V_228 . V_231 ,
V_230 ) ;
F_90 ( V_115 ) ;
return V_217 ;
}
F_73 ( V_195 , L_18 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
V_230 , V_229 , V_197 -> V_53 . V_227 . V_228 . V_231 ) ;
F_92 ( V_53 , V_68 , 0 , V_230 ) ;
if ( V_230 != 0 )
F_29 ( V_53 ) ;
F_90 ( V_115 ) ;
F_78 ( V_53 , V_239 ) ;
F_27 ( V_51 , V_52 , V_53 , 0 , 0 , V_230 , V_229 ) ;
return 0 ;
}
static int
F_93 ( T_4 * V_51 , T_5 * V_53 )
{
V_133 * V_197 = & V_53 -> V_78 ;
T_7 V_35 = { 0 } ;
T_6 * V_68 ;
int V_115 ;
V_35 . V_1 = V_197 -> V_184 ;
V_35 . V_81 = V_197 -> V_82 ;
V_197 -> V_53 . V_240 . V_205 = F_81 ( V_197 -> V_53 . V_240 . V_205 ) ;
V_197 -> V_53 . V_240 . V_230 = F_82 ( V_197 -> V_53 . V_240 . V_230 ) ;
V_115 = F_87 ( V_197 -> V_53 . V_240 . V_228 . V_231 ) ;
F_88 ( V_115 ) ;
V_68 = F_89 ( & V_197 -> V_53 . V_240 . V_228 ) ;
if ( V_68 == NULL || V_68 -> V_232 == 0 || V_68 -> V_233 != NULL ) {
F_73 ( V_195 ,
L_19 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
( V_68 == NULL ) ? L_14 : L_15 ,
V_197 -> V_53 . V_240 . V_228 . V_234 ,
V_197 -> V_53 . V_240 . V_228 . V_231 ) ;
if ( V_68 != NULL && V_68 -> V_233 != NULL )
F_37 ( L_20 ,
V_68 -> V_233 -> V_235 ) ;
F_90 ( V_115 ) ;
return V_217 ;
}
F_73 ( V_195 , L_21 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_35 ) ,
V_197 -> V_53 . V_240 . V_228 . V_231 ) ;
F_92 ( V_53 , V_68 , 0 , 0 ) ;
F_90 ( V_115 ) ;
F_78 ( V_53 , V_241 ) ;
F_27 ( V_51 , V_53 -> V_86 , V_53 , 0 , 0 , 0 , V_53 -> V_60 ) ;
return 0 ;
}
static int
F_94 ( T_4 * V_51 , T_5 * V_53 )
{
int V_57 = 0 ;
if ( V_53 -> V_94 -> V_151 <= 0 ||
F_55 ( V_53 ) -> V_155 <= 0 ) {
if ( V_51 -> V_66 -> V_93 == NULL ) {
V_53 -> V_92 = 1 ;
} else {
F_6 ( V_53 -> V_142 ) ;
V_57 = F_36 ( V_51 , V_53 ) ;
F_4 ( V_53 -> V_142 ) ;
}
}
if ( V_57 == 0 )
V_57 = F_56 ( V_53 , 0 ) ;
return V_57 ;
}
char *
F_74 ( int type )
{
switch ( type ) {
case V_242 :
return L_22 ;
case V_243 :
return L_23 ;
case V_244 :
return L_24 ;
case V_226 :
return L_25 ;
case V_245 :
return L_26 ;
default:
return L_27 ;
}
}
void
F_95 ( V_133 * V_197 )
{
T_7 V_35 = { 0 } ;
T_7 V_33 = { 0 } ;
char * V_246 = F_74 ( V_197 -> type ) ;
V_35 . V_1 = V_197 -> V_184 ;
V_35 . V_81 = V_197 -> V_82 ;
V_33 . V_1 = V_197 -> V_79 ;
V_33 . V_81 = V_197 -> V_80 ;
F_52 ( L_28 , V_197 , V_246 ) ;
F_52 ( L_29 , F_39 ( V_35 ) ) ;
F_52 ( L_30 , F_39 ( V_33 ) ) ;
switch ( V_197 -> type ) {
default:
break;
case V_243 :
F_52 ( L_31 ,
V_197 -> V_53 . V_200 . V_206 ,
V_197 -> V_53 . V_200 . V_201 . V_234 ,
V_197 -> V_53 . V_200 . V_201 . V_231 ,
V_197 -> V_53 . V_200 . V_205 ) ;
F_52 ( L_32 ,
V_197 -> V_84 , V_197 -> V_53 . V_200 . V_36 ,
V_197 -> V_53 . V_200 . V_247 ) ;
break;
case V_244 :
F_52 ( L_33 ,
V_197 -> V_53 . V_220 . V_206 ,
V_197 -> V_53 . V_220 . V_225 . V_234 ,
V_197 -> V_53 . V_220 . V_225 . V_231 ,
V_197 -> V_53 . V_220 . V_205 ) ;
F_52 ( L_34 ,
V_197 -> V_53 . V_220 . V_221 ,
V_197 -> V_53 . V_220 . V_222 ) ;
break;
case V_242 :
F_52 ( L_35 ,
V_197 -> V_53 . V_240 . V_228 . V_234 ,
V_197 -> V_53 . V_240 . V_228 . V_231 ,
V_197 -> V_53 . V_240 . V_230 ) ;
break;
case V_226 :
F_52 ( L_36 ,
V_197 -> V_53 . V_227 . V_228 . V_234 ,
V_197 -> V_53 . V_227 . V_228 . V_231 ,
V_197 -> V_84 ) ;
}
}
int
F_96 ( T_4 * V_51 , V_133 * V_197 , T_1 V_248 ,
void * V_52 , int V_249 )
{
int V_57 = 0 ;
int V_115 ;
int V_250 ;
struct V_251 * V_53 ;
T_14 V_80 ;
T_1 V_79 ;
T_1 V_184 ;
T_15 V_84 ;
T_15 type ;
F_2 ( ! F_21 () ) ;
type = F_82 ( V_197 -> type ) ;
V_184 = F_81 ( V_197 -> V_184 ) ;
V_79 = F_81 ( V_197 -> V_79 ) ;
V_80 = F_82 ( V_197 -> V_80 ) ;
V_84 = F_82 ( V_197 -> V_84 ) ;
V_250 = ( V_51 -> V_87 == V_79 ) ;
V_115 = F_65 ( V_248 ) ;
switch ( type ) {
case V_242 :
case V_244 :
if ( V_84 > 0 ) {
F_37 ( L_37 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) ,
F_74 ( type ) , V_84 ) ;
return - V_252 ;
}
break;
case V_243 :
case V_226 :
if ( V_84 >
( T_15 ) ( V_250 ? V_253 : V_144 ) ) {
F_37 ( L_38 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) ,
F_74 ( type ) ,
V_84 ,
V_250 ? V_253 : V_144 ) ;
return - V_252 ;
}
break;
default:
F_37 ( L_39 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) , type ) ;
return - V_252 ;
}
if ( V_8 . V_254 &&
V_51 -> V_255 != F_97 () ) {
F_98 ( V_51 ) ;
V_51 -> V_255 = F_97 () ;
if ( V_51 -> V_256 != NULL &&
V_51 -> V_256 -> V_257 == V_258 )
V_51 -> V_256 -> V_257 = V_259 ;
F_99 ( V_51 ) ;
}
if ( ! V_250 ) {
if ( F_35 ( V_79 ) == F_35 ( V_51 -> V_87 ) ) {
F_37 ( L_40 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) ,
F_38 ( V_79 ) ) ;
return - V_252 ;
}
if ( F_100 ( V_79 ) ) {
F_37 ( L_41 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) ,
F_38 ( V_79 ) ) ;
return - V_252 ;
}
if ( V_249 && type == V_244 ) {
F_37 ( L_42 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) ,
F_38 ( V_79 ) ) ;
return - V_252 ;
}
if ( ! V_8 . V_254 ) {
F_37 ( L_43 ,
F_38 ( V_248 ) ,
F_38 ( V_184 ) ,
F_38 ( V_79 ) ) ;
goto V_260;
}
}
if ( ! F_12 ( & V_8 . V_14 ) &&
F_14 ( V_184 , 0 ) ) {
F_37 ( L_44 ,
F_38 ( V_248 ) , F_38 ( V_184 ) ,
F_74 ( type ) ) ;
goto V_260;
}
V_53 = F_101 () ;
if ( V_53 == NULL ) {
F_37 ( L_45 ,
F_38 ( V_248 ) , F_38 ( V_184 ) ,
F_74 ( type ) ) ;
goto V_260;
}
V_53 -> V_76 = type ;
V_53 -> V_86 = V_52 ;
V_53 -> V_58 = 1 ;
V_53 -> V_60 = V_53 -> V_62 = V_84 ;
V_53 -> V_61 = 0 ;
V_53 -> V_78 = * V_197 ;
V_53 -> V_261 = V_248 ;
if ( ! V_250 ) {
V_53 -> V_77 . V_81 = V_80 ;
V_53 -> V_77 . V_1 = V_79 ;
V_53 -> V_70 = 1 ;
} else {
V_53 -> V_78 . type = type ;
V_53 -> V_78 . V_184 = V_184 ;
V_53 -> V_78 . V_82 = F_82 ( V_53 -> V_78 . V_82 ) ;
V_53 -> V_78 . V_79 = V_79 ;
V_53 -> V_78 . V_80 = V_80 ;
V_53 -> V_78 . V_84 = V_84 ;
}
F_4 ( V_115 ) ;
V_57 = F_71 ( & V_53 -> V_94 , V_248 , V_115 ) ;
if ( V_57 != 0 ) {
F_6 ( V_115 ) ;
F_37 ( L_46 ,
F_38 ( V_248 ) , F_38 ( V_184 ) ,
F_74 ( type ) , V_57 ) ;
F_102 ( V_53 ) ;
goto V_260;
}
if ( F_48 ( V_53 -> V_94 ) ) {
F_103 ( V_53 -> V_94 ) ;
if ( V_262 &&
F_35 ( V_184 ) != F_35 ( V_248 ) ) {
F_104 ( V_53 -> V_94 ,
F_35 ( V_184 ) ) ;
}
}
F_70 ( V_53 , V_115 ) ;
if ( ! V_250 ) {
V_57 = F_94 ( V_51 , V_53 ) ;
F_6 ( V_115 ) ;
if ( V_57 < 0 )
goto V_263;
if ( V_57 == 0 ) {
F_27 ( V_51 , V_53 -> V_86 , V_53 , 0 ,
0 , V_84 , V_84 ) ;
}
return 0 ;
}
F_6 ( V_115 ) ;
switch ( type ) {
case V_242 :
V_57 = F_93 ( V_51 , V_53 ) ;
break;
case V_243 :
V_57 = F_80 ( V_51 , V_53 ) ;
break;
case V_244 :
V_57 = F_85 ( V_51 , V_53 , V_249 ) ;
break;
case V_226 :
V_57 = F_86 ( V_51 , V_53 ) ;
break;
default:
F_2 ( 0 ) ;
V_57 = - V_252 ;
goto V_263;
}
if ( V_57 == 0 )
return 0 ;
F_2 ( V_57 == V_217 ) ;
V_263:
F_2 ( V_53 -> V_69 == NULL ) ;
F_28 ( V_51 , V_53 , V_57 ) ;
V_260:
F_76 ( V_51 , V_115 , V_52 , V_84 ) ;
return 0 ;
}
void
F_105 ( struct V_4 * V_264 , char * V_265 )
{
while ( ! F_12 ( V_264 ) ) {
T_7 V_266 = { 0 } ;
T_5 * V_53 ;
V_53 = F_9 ( V_264 -> V_6 , T_5 , V_135 ) ;
F_10 ( & V_53 -> V_135 ) ;
V_266 . V_1 = V_53 -> V_78 . V_184 ;
V_266 . V_81 = V_53 -> V_78 . V_82 ;
F_2 ( V_53 -> V_69 == NULL ) ;
F_2 ( V_53 -> V_149 ) ;
F_2 ( V_53 -> V_94 != NULL ) ;
F_2 ( V_53 -> V_78 . type == V_243 ) ;
F_52 ( L_47 ,
F_39 ( V_266 ) ,
V_53 -> V_78 . V_53 . V_200 . V_206 ,
V_53 -> V_78 . V_53 . V_200 . V_205 ,
V_53 -> V_78 . V_53 . V_200 . V_36 ,
V_53 -> V_78 . V_84 , V_265 ) ;
F_76 ( V_53 -> V_94 -> V_108 ,
V_53 -> V_94 -> V_99 ,
V_53 -> V_86 , V_53 -> V_60 ) ;
F_28 ( V_53 -> V_94 -> V_108 , V_53 , - V_217 ) ;
}
}
void
F_106 ( struct V_4 * V_264 )
{
while ( ! F_12 ( V_264 ) ) {
T_5 * V_53 ;
T_7 V_266 ;
V_53 = F_9 ( V_264 -> V_6 , T_5 , V_135 ) ;
F_10 ( & V_53 -> V_135 ) ;
V_266 . V_1 = V_53 -> V_78 . V_184 ;
V_266 . V_81 = V_53 -> V_78 . V_82 ;
F_2 ( V_53 -> V_149 ) ;
F_2 ( V_53 -> V_69 != NULL ) ;
F_2 ( V_53 -> V_94 != NULL ) ;
F_2 ( V_53 -> V_78 . type == V_243 ) ;
F_73 ( V_195 , L_48 ,
F_39 ( V_266 ) , V_53 -> V_78 . V_53 . V_200 . V_206 ,
V_53 -> V_78 . V_53 . V_200 . V_205 ,
V_53 -> V_78 . V_53 . V_200 . V_36 ,
V_53 -> V_78 . V_84 ) ;
F_77 ( V_53 -> V_94 -> V_108 , V_53 ) ;
}
}
int
F_107 ( T_1 V_267 , T_16 V_268 , T_17 V_240 ,
T_7 V_75 , unsigned int V_269 ,
T_18 V_205 , unsigned int V_36 ,
T_18 V_247 )
{
struct V_251 * V_53 ;
struct V_270 * V_68 ;
int V_115 ;
int V_57 ;
F_2 ( V_8 . V_9 ) ;
F_2 ( V_8 . V_271 > 0 ) ;
if ( ! F_12 ( & V_8 . V_14 ) &&
F_14 ( V_75 . V_1 , 1 ) ) {
F_37 ( L_49 ,
F_39 ( V_75 ) ) ;
return - V_272 ;
}
V_53 = F_101 () ;
if ( V_53 == NULL ) {
F_37 ( L_50 ,
F_39 ( V_75 ) ) ;
return - V_10 ;
}
V_53 -> V_273 = ! ! F_108 () ;
V_115 = F_87 ( V_268 . V_274 ) ;
F_88 ( V_115 ) ;
V_68 = F_109 ( & V_268 ) ;
if ( V_68 == NULL || V_68 -> V_232 == 0 || V_68 -> V_233 != NULL ) {
F_37 ( L_51 ,
V_205 , V_269 , F_39 ( V_75 ) ,
V_68 == NULL ? - 1 : V_68 -> V_232 ) ;
if ( V_68 != NULL && V_68 -> V_233 != NULL )
F_37 ( L_20 ,
V_68 -> V_233 -> V_235 ) ;
F_90 ( V_115 ) ;
F_102 ( V_53 ) ;
return - V_217 ;
}
F_73 ( V_195 , L_52 , F_39 ( V_75 ) ) ;
F_92 ( V_53 , V_68 , 0 , 0 ) ;
F_30 ( V_53 , V_243 , V_75 , 0 , V_68 -> V_237 ) ;
V_53 -> V_78 . V_53 . V_200 . V_205 = F_32 ( V_205 ) ;
V_53 -> V_78 . V_53 . V_200 . V_206 = F_31 ( V_269 ) ;
V_53 -> V_78 . V_53 . V_200 . V_36 = F_31 ( V_36 ) ;
V_53 -> V_78 . V_53 . V_200 . V_247 = V_247 ;
if ( V_240 == V_275 ) {
V_53 -> V_78 . V_53 . V_200 . V_201 . V_234 =
V_8 . V_276 ;
V_53 -> V_78 . V_53 . V_200 . V_201 . V_231 =
V_68 -> V_277 . V_278 ;
} else {
V_53 -> V_78 . V_53 . V_200 . V_201 . V_234 =
V_279 ;
V_53 -> V_78 . V_53 . V_200 . V_201 . V_231 =
V_279 ;
}
F_90 ( V_115 ) ;
F_78 ( V_53 , V_280 ) ;
V_57 = F_64 ( V_267 , V_53 , V_15 ) ;
if ( V_57 != 0 ) {
F_54 ( L_53 ,
F_39 ( V_75 ) , V_57 ) ;
F_28 ( NULL , V_53 , V_57 ) ;
}
return 0 ;
}
T_5 *
F_110 ( T_4 * V_51 , T_5 * V_281 )
{
struct V_251 * V_53 = F_101 () ;
struct V_270 * V_282 = V_281 -> V_69 ;
T_7 V_283 = V_281 -> V_77 ;
int V_115 ;
F_2 ( ! V_281 -> V_189 ) ;
F_2 ( ! V_281 -> V_70 ) ;
V_115 = F_87 ( V_282 -> V_277 . V_278 ) ;
F_88 ( V_115 ) ;
F_2 ( V_282 -> V_284 > 0 ) ;
if ( V_53 == NULL ) {
F_37 ( L_54 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_283 ) ) ;
goto V_260;
}
if ( V_282 -> V_232 == 0 ) {
F_37 ( L_55 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_283 ) ,
V_282 ) ;
F_90 ( V_115 ) ;
goto V_260;
}
F_2 ( V_282 -> V_236 == 0 ) ;
F_73 ( V_195 , L_56 ,
F_38 ( V_51 -> V_87 ) , F_39 ( V_283 ) , V_282 ) ;
V_53 -> V_261 = V_283 . V_1 ;
V_53 -> V_76 = V_244 ;
V_53 -> V_78 . V_184 = V_283 . V_1 ;
V_53 -> V_78 . V_84 = V_282 -> V_237 ;
V_53 -> V_58 = 1 ;
F_92 ( V_53 , V_282 , V_282 -> V_236 , V_282 -> V_237 ) ;
F_90 ( V_115 ) ;
V_115 = F_65 ( V_283 . V_1 ) ;
F_4 ( V_115 ) ;
F_70 ( V_53 , V_115 ) ;
F_6 ( V_115 ) ;
F_78 ( V_53 , V_239 ) ;
return V_53 ;
V_260:
V_115 = F_65 ( V_283 . V_1 ) ;
F_4 ( V_115 ) ;
V_8 . V_123 [ V_115 ] -> V_124 ++ ;
V_8 . V_123 [ V_115 ] -> V_125 += V_282 -> V_237 ;
F_6 ( V_115 ) ;
if ( V_53 != NULL )
F_102 ( V_53 ) ;
return NULL ;
}
void
F_111 ( T_4 * V_51 , T_5 * V_227 , unsigned int V_37 )
{
F_2 ( V_227 != NULL ) ;
F_2 ( V_227 -> V_76 == V_244 ) ;
F_2 ( V_227 -> V_285 . type == V_239 ) ;
F_2 ( V_37 <= V_227 -> V_285 . V_230 ) ;
V_227 -> V_285 . V_230 = V_37 ;
}
int
F_112 ( T_1 V_267 , T_16 V_268 ,
T_7 V_75 , unsigned int V_269 ,
T_18 V_205 , unsigned int V_36 )
{
struct V_251 * V_53 ;
struct V_270 * V_68 ;
int V_115 ;
int V_57 ;
F_2 ( V_8 . V_9 ) ;
F_2 ( V_8 . V_271 > 0 ) ;
if ( ! F_12 ( & V_8 . V_14 ) &&
F_14 ( V_75 . V_1 , 1 ) ) {
F_37 ( L_57 ,
F_39 ( V_75 ) ) ;
return - V_272 ;
}
V_53 = F_101 () ;
if ( V_53 == NULL ) {
F_37 ( L_58 ,
F_39 ( V_75 ) ) ;
return - V_10 ;
}
V_115 = F_87 ( V_268 . V_274 ) ;
F_88 ( V_115 ) ;
V_68 = F_109 ( & V_268 ) ;
if ( V_68 == NULL || V_68 -> V_232 == 0 || V_68 -> V_233 != NULL ) {
F_37 ( L_59 ,
V_205 , V_269 , F_39 ( V_75 ) ,
V_68 == NULL ? - 1 : V_68 -> V_232 ) ;
if ( V_68 != NULL && V_68 -> V_233 != NULL )
F_37 ( L_16 ,
V_68 -> V_233 -> V_235 ) ;
F_90 ( V_115 ) ;
F_102 ( V_53 ) ;
return - V_217 ;
}
F_73 ( V_195 , L_60 , F_39 ( V_75 ) ) ;
F_92 ( V_53 , V_68 , 0 , 0 ) ;
F_30 ( V_53 , V_244 , V_75 , 0 , 0 ) ;
V_53 -> V_78 . V_53 . V_220 . V_205 = F_32 ( V_205 ) ;
V_53 -> V_78 . V_53 . V_220 . V_206 = F_31 ( V_269 ) ;
V_53 -> V_78 . V_53 . V_220 . V_222 = F_31 ( V_36 ) ;
V_53 -> V_78 . V_53 . V_220 . V_221 = F_31 ( V_68 -> V_237 ) ;
V_53 -> V_78 . V_53 . V_220 . V_225 . V_234 =
V_8 . V_276 ;
V_53 -> V_78 . V_53 . V_220 . V_225 . V_231 =
V_68 -> V_277 . V_278 ;
F_90 ( V_115 ) ;
F_78 ( V_53 , V_280 ) ;
V_57 = F_64 ( V_267 , V_53 , V_15 ) ;
if ( V_57 < 0 ) {
F_54 ( L_61 ,
F_39 ( V_75 ) , V_57 ) ;
F_28 ( NULL , V_53 , V_57 ) ;
}
return 0 ;
}
int
F_113 ( T_1 V_286 , T_1 * V_287 , T_15 * V_288 )
{
struct V_4 * V_289 ;
struct V_163 * V_51 ;
T_12 * V_175 ;
T_15 V_290 = F_35 ( V_286 ) ;
int V_291 ;
int V_115 ;
T_15 V_292 = 2 ;
struct V_4 * V_293 ;
F_2 ( V_8 . V_9 ) ;
F_2 ( V_8 . V_271 > 0 ) ;
V_115 = F_114 () ;
F_115 (e, &the_lnet.ln_nis) {
V_51 = F_9 ( V_289 , T_4 , V_294 ) ;
if ( V_51 -> V_87 == V_286 ) {
if ( V_287 != NULL )
* V_287 = V_286 ;
if ( V_288 != NULL ) {
if ( F_34 ( F_35 ( V_286 ) ) == V_88 )
* V_288 = 0 ;
else
* V_288 = 1 ;
}
F_6 ( V_115 ) ;
return V_295 ? 0 : 1 ;
}
if ( F_35 ( V_51 -> V_87 ) == V_290 ) {
if ( V_287 != NULL )
* V_287 = V_51 -> V_87 ;
if ( V_288 != NULL )
* V_288 = V_292 ;
F_6 ( V_115 ) ;
return 1 ;
}
V_292 ++ ;
}
V_293 = F_116 ( V_290 ) ;
F_115 (e, rn_list) {
V_175 = F_9 ( V_289 , T_12 , V_296 ) ;
if ( V_175 -> V_297 == V_290 ) {
T_11 * V_298 ;
T_11 * V_299 = NULL ;
F_2 ( ! F_12 ( & V_175 -> V_300 ) ) ;
F_63 (route, &rnet->lrn_routes,
lr_list) {
if ( V_299 == NULL ||
V_298 -> V_172 < V_299 -> V_172 )
V_299 = V_298 ;
}
F_2 ( V_299 != NULL ) ;
V_291 = V_299 -> V_172 ;
if ( V_287 != NULL )
* V_287 = V_299 -> V_169 -> V_108 -> V_87 ;
if ( V_288 != NULL )
* V_288 = V_292 ;
F_6 ( V_115 ) ;
return V_291 + 1 ;
}
V_292 ++ ;
}
F_6 ( V_115 ) ;
return - V_126 ;
}
int
F_117 ( T_7 V_266 , int V_301 )
{
return 0 ;
}
