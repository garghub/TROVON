int
F_1 ( T_1 * V_1 )
{
int V_2 = F_2 ( V_1 -> V_3 , 1 ,
& V_1 -> V_4 ,
& V_1 -> V_5 ) ;
F_3 ( ! V_1 -> V_6 ) ;
if ( V_2 != 0 ) {
F_4 ( L_1 , V_2 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 -> V_3 , 0 ,
& V_1 -> V_7 , NULL ) ;
if ( V_2 != 0 ) {
F_4 ( L_2 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
int
F_5 ( T_1 * V_1 )
{
int V_8 = V_1 -> V_3 -> V_9 -> V_10 ;
if ( V_1 -> V_11 == & V_12 )
return 0 ;
return ( ( V_8 & V_13 ) != 0 && ( V_8 & V_14 ) != 0 ) ;
}
int
F_6 ( T_1 * V_1 , T_2 * V_15 )
{
struct V_16 * V_17 = V_1 -> V_3 ;
int V_18 ;
int V_2 ;
if ( * V_19 . V_20 &&
V_1 -> V_11 == & V_21 &&
V_15 -> V_22 == V_15 -> V_23 &&
V_15 -> V_24 . V_25 == 0 )
F_7 ( V_15 ) ;
{
#if V_26
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_15 -> V_33 ;
#endif
struct V_34 V_35 = { . V_36 = V_37 } ;
int V_38 ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_29 [ V_38 ] = V_15 -> V_39 [ V_38 ] ;
V_18 += V_29 [ V_38 ] . V_40 ;
}
if ( ! F_8 ( & V_1 -> V_41 ) ||
V_18 < V_15 -> V_23 )
V_35 . V_36 |= V_42 ;
V_2 = F_9 ( V_17 , & V_35 , (struct V_43 * ) V_29 , V_30 , V_18 ) ;
}
return V_2 ;
}
int
F_10 ( T_1 * V_1 , T_2 * V_15 )
{
struct V_16 * V_17 = V_1 -> V_3 ;
T_3 * V_44 = V_15 -> V_45 ;
int V_2 ;
int V_18 ;
F_3 ( V_15 -> V_46 != NULL ) ;
if ( V_15 -> V_24 . V_47 [ 0 ] != 0 ) {
struct V_17 * V_9 = V_17 -> V_9 ;
struct V_48 * V_48 = V_44 -> V_49 ;
int V_50 = V_44 -> V_51 ;
int V_52 = V_44 -> V_53 ;
int V_54 = V_37 ;
F_11 ( V_55 , L_3 ,
V_48 , V_50 , V_44 -> V_53 ) ;
if ( ! F_8 ( & V_1 -> V_41 ) ||
V_52 < V_15 -> V_23 )
V_54 |= V_42 ;
if ( V_9 -> V_56 -> V_57 != NULL ) {
V_2 = V_9 -> V_56 -> V_57 ( V_9 , V_48 ,
V_50 , V_52 , V_54 ) ;
} else {
V_2 = F_12 ( V_9 , V_48 , V_50 , V_52 ,
V_54 ) ;
}
} else {
#if V_26 || ! V_58
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_15 -> V_59 ;
#endif
struct V_34 V_35 = { . V_36 = V_37 } ;
int V_38 ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_29 [ V_38 ] . V_60 = F_14 ( V_44 [ V_38 ] . V_49 ) +
V_44 [ V_38 ] . V_51 ;
V_18 += V_29 [ V_38 ] . V_40 = V_44 [ V_38 ] . V_53 ;
}
if ( ! F_8 ( & V_1 -> V_41 ) ||
V_18 < V_15 -> V_23 )
V_35 . V_36 |= V_42 ;
V_2 = F_9 ( V_17 , & V_35 , (struct V_43 * ) V_29 , V_30 , V_18 ) ;
for ( V_38 = 0 ; V_38 < V_30 ; V_38 ++ )
F_15 ( V_44 [ V_38 ] . V_49 ) ;
}
return V_2 ;
}
void
F_16 ( T_1 * V_1 )
{
int V_61 = 1 ;
T_4 V_62 = F_17 () ;
struct V_16 * V_17 = V_1 -> V_3 ;
F_18 ( V_63 ) ;
V_17 -> V_64 -> V_65 ( V_17 , V_66 , V_67 ,
( char * ) & V_61 , sizeof ( V_61 ) ) ;
F_18 ( V_62 ) ;
}
int
F_19 ( T_1 * V_1 )
{
#if V_68
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_1 -> V_69 ;
#endif
struct V_27 * V_70 = V_1 -> V_71 ;
struct V_34 V_35 = {
. V_36 = 0
} ;
int V_18 ;
int V_38 ;
int V_2 ;
int V_72 ;
int V_73 ;
T_5 V_74 ;
F_3 ( V_30 > 0 ) ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_29 [ V_38 ] = V_70 [ V_38 ] ;
V_18 += V_29 [ V_38 ] . V_40 ;
}
F_3 ( V_18 <= V_1 -> V_75 ) ;
V_2 = F_20 ( V_1 -> V_3 , & V_35 ,
(struct V_43 * ) V_29 , V_30 , V_18 , V_37 ) ;
V_74 = 0 ;
if ( V_1 -> V_11 == & V_21 ) {
V_74 = V_1 -> V_76 . V_25 ;
V_1 -> V_76 . V_25 = 0 ;
}
if ( V_74 != 0 ) {
for ( V_38 = 0 , V_73 = V_2 ; V_73 > 0 ; V_38 ++ , V_73 -= V_72 ) {
F_3 ( V_38 < V_30 ) ;
V_72 = V_70 [ V_38 ] . V_40 ;
if ( V_72 > V_73 )
V_72 = V_73 ;
V_1 -> V_77 = F_21 ( V_1 -> V_77 ,
V_70 [ V_38 ] . V_60 , V_72 ) ;
}
V_1 -> V_76 . V_25 = V_74 ;
}
return V_2 ;
}
static void
F_22 ( void * V_78 )
{
if ( V_78 == NULL )
return;
F_23 ( V_78 ) ;
}
static void *
F_24 ( T_3 * V_44 , int V_30 ,
struct V_27 * V_70 , struct V_48 * * V_79 )
{
void * V_78 ;
int V_18 ;
int V_38 ;
if ( ! * V_19 . V_80 || V_79 == NULL )
return NULL ;
F_3 ( V_30 <= V_81 ) ;
if ( V_30 < 2 ||
V_30 < * V_19 . V_82 )
return NULL ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
if ( ( V_44 [ V_38 ] . V_51 != 0 && V_38 > 0 ) ||
( V_44 [ V_38 ] . V_51 + V_44 [ V_38 ] . V_53 != V_83 && V_38 < V_30 - 1 ) )
return NULL ;
V_79 [ V_38 ] = V_44 [ V_38 ] . V_49 ;
V_18 += V_44 [ V_38 ] . V_53 ;
}
V_78 = F_25 ( V_79 , V_30 , V_84 , V_85 ) ;
if ( V_78 == NULL )
return NULL ;
V_70 -> V_60 = V_78 + V_44 [ 0 ] . V_51 ;
V_70 -> V_40 = V_18 ;
return V_78 ;
}
int
F_26 ( T_1 * V_1 )
{
#if V_68 || ! V_58
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
struct V_48 * * V_79 = NULL ;
unsigned int V_30 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
struct V_48 * * V_79 = V_1 -> V_31 -> V_86 ;
unsigned int V_30 = V_1 -> V_87 ;
#endif
T_3 * V_44 = V_1 -> V_88 ;
struct V_34 V_35 = {
. V_36 = 0
} ;
int V_18 ;
int V_38 ;
int V_2 ;
void * V_89 ;
void * V_78 ;
int V_73 ;
int V_72 ;
int V_90 ;
V_78 = F_24 ( V_44 , V_30 , V_29 , V_79 ) ;
if ( V_78 != NULL ) {
V_18 = V_29 [ 0 ] . V_40 ;
V_90 = 1 ;
} else {
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_18 += V_29 [ V_38 ] . V_40 = V_44 [ V_38 ] . V_53 ;
V_29 [ V_38 ] . V_60 = F_14 ( V_44 [ V_38 ] . V_49 ) +
V_44 [ V_38 ] . V_51 ;
}
V_90 = V_30 ;
}
F_3 ( V_18 <= V_1 -> V_75 ) ;
V_2 = F_20 ( V_1 -> V_3 , & V_35 ,
(struct V_43 * ) V_29 , V_90 , V_18 , V_37 ) ;
if ( V_1 -> V_76 . V_25 != 0 ) {
for ( V_38 = 0 , V_73 = V_2 ; V_73 > 0 ; V_38 ++ , V_73 -= V_72 ) {
F_3 ( V_38 < V_30 ) ;
V_89 = F_14 ( V_44 [ V_38 ] . V_49 ) + V_44 [ V_38 ] . V_51 ;
V_72 = V_44 [ V_38 ] . V_53 ;
if ( V_72 > V_73 )
V_72 = V_73 ;
V_1 -> V_77 = F_21 ( V_1 -> V_77 ,
V_89 , V_72 ) ;
F_15 ( V_44 [ V_38 ] . V_49 ) ;
}
}
if ( V_78 != NULL ) {
F_22 ( V_78 ) ;
} else {
for ( V_38 = 0 ; V_38 < V_30 ; V_38 ++ )
F_15 ( V_44 [ V_38 ] . V_49 ) ;
}
return ( V_2 ) ;
}
void
F_7 ( T_2 * V_15 )
{
int V_38 ;
T_5 V_91 ;
void * V_89 ;
F_3 ( V_15 -> V_39 [ 0 ] . V_60 == ( void * ) & V_15 -> V_24 ) ;
F_3 ( V_15 -> V_92 != NULL ) ;
F_3 ( V_15 -> V_92 -> V_11 == & V_21 ) ;
V_15 -> V_24 . V_25 = 0 ;
V_91 = F_21 ( ~ 0 , ( void * ) V_15 -> V_39 [ 0 ] . V_60 ,
V_15 -> V_39 [ 0 ] . V_40 ) ;
if ( V_15 -> V_45 != NULL ) {
for ( V_38 = 0 ; V_38 < V_15 -> V_59 ; V_38 ++ ) {
V_89 = F_14 ( V_15 -> V_45 [ V_38 ] . V_49 ) +
V_15 -> V_45 [ V_38 ] . V_51 ;
V_91 = F_21 ( V_91 , V_89 , V_15 -> V_45 [ V_38 ] . V_53 ) ;
F_15 ( V_15 -> V_45 [ V_38 ] . V_49 ) ;
}
} else {
for ( V_38 = 1 ; V_38 < V_15 -> V_33 ; V_38 ++ )
V_91 = F_21 ( V_91 , V_15 -> V_39 [ V_38 ] . V_60 ,
V_15 -> V_39 [ V_38 ] . V_40 ) ;
}
if ( * V_19 . V_93 ) {
V_91 ++ ;
* V_19 . V_93 = 0 ;
}
V_15 -> V_24 . V_25 = V_91 ;
}
int
F_27 ( T_1 * V_1 , int * V_94 , int * V_95 , int * V_96 )
{
T_4 V_62 = F_17 () ;
struct V_16 * V_17 = V_1 -> V_3 ;
int V_97 ;
int V_2 ;
V_2 = F_28 ( V_1 ) ;
if ( V_2 != 0 ) {
F_3 ( V_1 -> V_6 ) ;
* V_94 = * V_95 = * V_96 = 0 ;
return ( - V_98 ) ;
}
V_2 = F_29 ( V_17 , V_94 , V_95 ) ;
if ( V_2 == 0 ) {
V_97 = sizeof( * V_96 ) ;
F_18 ( V_63 ) ;
V_2 = V_17 -> V_64 -> V_99 ( V_17 , V_66 , V_100 ,
( char * ) V_96 , & V_97 ) ;
F_18 ( V_62 ) ;
}
F_30 ( V_1 ) ;
if ( V_2 == 0 )
* V_96 = ! * V_96 ;
else
* V_94 = * V_95 = * V_96 = 0 ;
return ( V_2 ) ;
}
int
F_31 ( struct V_16 * V_17 )
{
T_4 V_62 = F_17 () ;
int V_2 ;
int V_101 ;
int V_102 ;
int V_103 ;
int V_104 ;
int V_105 ;
struct V_106 V_106 ;
V_17 -> V_9 -> V_107 = V_108 ;
V_106 . V_109 = 0 ;
V_106 . V_110 = 0 ;
F_18 ( V_63 ) ;
V_2 = F_32 ( V_17 , V_111 , V_112 ,
( char * ) & V_106 , sizeof ( V_106 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_4 , V_2 ) ;
return ( V_2 ) ;
}
V_101 = - 1 ;
F_18 ( V_63 ) ;
V_2 = V_17 -> V_64 -> V_65 ( V_17 , V_66 , V_113 ,
( char * ) & V_101 , sizeof ( V_101 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_5 , V_2 ) ;
return ( V_2 ) ;
}
if ( ! * V_19 . V_114 ) {
V_101 = 1 ;
F_18 ( V_63 ) ;
V_2 = V_17 -> V_64 -> V_65 ( V_17 , V_66 , V_100 ,
( char * ) & V_101 , sizeof ( V_101 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_6 , V_2 ) ;
return ( V_2 ) ;
}
}
V_2 = F_33 ( V_17 ,
* V_19 . V_115 ,
* V_19 . V_116 ) ;
if ( V_2 != 0 ) {
F_4 ( L_7 ,
* V_19 . V_115 ,
* V_19 . V_116 , V_2 ) ;
return ( V_2 ) ;
}
V_102 = * V_19 . V_117 ;
V_104 = * V_19 . V_118 ;
V_103 = * V_19 . V_119 ;
V_105 = ( V_102 > 0 && V_104 > 0 && V_103 > 0 ) ;
V_101 = ( V_105 ? 1 : 0 ) ;
F_18 ( V_63 ) ;
V_2 = F_32 ( V_17 , V_111 , V_120 ,
( char * ) & V_101 , sizeof ( V_101 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_8 , V_2 ) ;
return ( V_2 ) ;
}
if ( ! V_105 )
return ( 0 ) ;
F_18 ( V_63 ) ;
V_2 = V_17 -> V_64 -> V_65 ( V_17 , V_66 , V_121 ,
( char * ) & V_102 , sizeof ( V_102 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_9 , V_2 ) ;
return ( V_2 ) ;
}
F_18 ( V_63 ) ;
V_2 = V_17 -> V_64 -> V_65 ( V_17 , V_66 , V_122 ,
( char * ) & V_103 , sizeof ( V_103 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_10 , V_2 ) ;
return ( V_2 ) ;
}
F_18 ( V_63 ) ;
V_2 = V_17 -> V_64 -> V_65 ( V_17 , V_66 , V_123 ,
( char * ) & V_104 , sizeof ( V_104 ) ) ;
F_18 ( V_62 ) ;
if ( V_2 != 0 ) {
F_4 ( L_11 , V_2 ) ;
return ( V_2 ) ;
}
return ( 0 ) ;
}
void
F_34 ( T_1 * V_1 )
{
struct V_17 * V_9 ;
struct V_124 * V_125 ;
int V_126 ;
int V_127 = 1 ;
int V_2 ;
T_4 V_62 ;
V_2 = F_28 ( V_1 ) ;
if ( V_2 != 0 )
return;
V_9 = V_1 -> V_3 -> V_9 ;
V_125 = F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
V_126 = V_125 -> V_126 ;
V_125 -> V_126 = 1 ;
F_37 ( V_9 ) ;
V_62 = F_17 () ;
F_18 ( V_63 ) ;
V_2 = V_9 -> V_56 -> V_65 ( V_9 , V_66 , V_100 ,
( char * ) & V_127 , sizeof ( V_127 ) ) ;
F_3 ( V_2 == 0 ) ;
F_18 ( V_62 ) ;
F_36 ( V_9 ) ;
V_125 -> V_126 = V_126 ;
F_37 ( V_9 ) ;
F_30 ( V_1 ) ;
}
static void
F_38 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
F_3 ( ! F_39 () ) ;
F_40 ( & V_128 . V_129 ) ;
V_1 = V_9 -> V_130 ;
if ( V_1 == NULL ) {
F_3 ( V_9 -> V_131 != & F_38 ) ;
V_9 -> V_131 ( V_9 ) ;
} else
F_41 ( V_1 ) ;
F_42 ( & V_128 . V_129 ) ;
}
static void
F_43 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
int V_132 ;
int V_133 ;
F_3 ( ! F_39 () ) ;
F_40 ( & V_128 . V_129 ) ;
V_1 = V_9 -> V_130 ;
V_132 = F_44 ( V_9 ) ;
V_133 = F_45 ( V_9 ) ;
F_11 ( V_55 , L_12 ,
V_9 , V_132 , V_133 , V_1 ,
( V_1 == NULL ) ? L_13 : ( V_1 -> V_134 ?
L_14 : L_15 ) ,
( V_1 == NULL ) ? L_13 : ( V_1 -> V_135 ?
L_16 : L_17 ) ,
( V_1 == NULL ) ? L_13 : ( F_8 ( & V_1 -> V_41 ) ?
L_18 : L_19 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_9 -> V_136 != & F_43 ) ;
V_9 -> V_136 ( V_9 ) ;
F_42 ( & V_128 . V_129 ) ;
return;
}
if ( V_132 >= V_133 ) {
F_46 ( V_1 ) ;
F_47 ( V_137 , & V_9 -> V_138 -> V_139 ) ;
}
F_42 ( & V_128 . V_129 ) ;
}
void
F_48 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_1 -> V_140 = V_17 -> V_9 -> V_131 ;
V_1 -> V_141 = V_17 -> V_9 -> V_136 ;
}
void
F_49 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_130 = V_1 ;
V_17 -> V_9 -> V_131 = F_38 ;
V_17 -> V_9 -> V_136 = F_43 ;
return;
}
void
F_50 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_131 = V_1 -> V_140 ;
V_17 -> V_9 -> V_136 = V_1 -> V_141 ;
V_17 -> V_9 -> V_130 = NULL ;
return ;
}
int
F_51 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_6 * V_142 ;
V_142 = V_1 -> V_31 ;
F_52 ( & V_142 -> V_143 ) ;
if ( ! F_53 ( V_1 -> V_3 ) &&
! V_1 -> V_134 ) {
V_2 = - V_144 ;
}
F_54 ( & V_142 -> V_143 ) ;
return V_2 ;
}
