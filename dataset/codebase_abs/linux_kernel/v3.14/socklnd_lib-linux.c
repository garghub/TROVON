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
struct V_34 V_35 = {
. V_36 = NULL ,
. V_37 = 0 ,
. V_38 = V_29 ,
. V_39 = V_30 ,
. V_40 = NULL ,
. V_41 = 0 ,
. V_42 = V_43
} ;
T_3 V_44 = F_8 () ;
int V_45 ;
for ( V_18 = V_45 = 0 ; V_45 < V_30 ; V_45 ++ ) {
V_29 [ V_45 ] = V_15 -> V_46 [ V_45 ] ;
V_18 += V_29 [ V_45 ] . V_47 ;
}
if ( ! F_9 ( & V_1 -> V_48 ) ||
V_18 < V_15 -> V_23 )
V_35 . V_42 |= V_49 ;
F_10 ( V_50 ) ;
V_2 = F_11 ( V_17 , & V_35 , V_18 ) ;
F_10 ( V_44 ) ;
}
return V_2 ;
}
int
F_12 ( T_1 * V_1 , T_2 * V_15 )
{
struct V_16 * V_17 = V_1 -> V_3 ;
T_4 * V_51 = V_15 -> V_52 ;
int V_2 ;
int V_18 ;
F_3 ( V_15 -> V_53 != NULL ) ;
if ( V_15 -> V_24 . V_54 [ 0 ] != 0 ) {
struct V_17 * V_9 = V_17 -> V_9 ;
struct V_55 * V_55 = V_51 -> V_56 ;
int V_57 = V_51 -> V_58 ;
int V_59 = V_51 -> V_60 ;
int V_61 = V_43 ;
F_13 ( V_62 , L_3 ,
V_55 , V_57 , V_51 -> V_60 ) ;
if ( ! F_9 ( & V_1 -> V_48 ) ||
V_59 < V_15 -> V_23 )
V_61 |= V_49 ;
if ( V_9 -> V_63 -> V_64 != NULL ) {
V_2 = V_9 -> V_63 -> V_64 ( V_9 , V_55 ,
V_57 , V_59 , V_61 ) ;
} else {
V_2 = F_14 ( V_9 , V_55 , V_57 , V_59 ,
V_61 ) ;
}
} else {
#if V_26 || ! V_65
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
#ifdef F_15
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_15 -> V_66 ;
#endif
struct V_34 V_35 = {
. V_36 = NULL ,
. V_37 = 0 ,
. V_38 = V_29 ,
. V_39 = V_30 ,
. V_40 = NULL ,
. V_41 = 0 ,
. V_42 = V_43
} ;
T_3 V_44 = F_8 () ;
int V_45 ;
for ( V_18 = V_45 = 0 ; V_45 < V_30 ; V_45 ++ ) {
V_29 [ V_45 ] . V_67 = F_16 ( V_51 [ V_45 ] . V_56 ) +
V_51 [ V_45 ] . V_58 ;
V_18 += V_29 [ V_45 ] . V_47 = V_51 [ V_45 ] . V_60 ;
}
if ( ! F_9 ( & V_1 -> V_48 ) ||
V_18 < V_15 -> V_23 )
V_35 . V_42 |= V_49 ;
F_10 ( V_50 ) ;
V_2 = F_11 ( V_17 , & V_35 , V_18 ) ;
F_10 ( V_44 ) ;
for ( V_45 = 0 ; V_45 < V_30 ; V_45 ++ )
F_17 ( V_51 [ V_45 ] . V_56 ) ;
}
return V_2 ;
}
void
F_18 ( T_1 * V_1 )
{
int V_68 = 1 ;
T_3 V_44 = F_8 () ;
struct V_16 * V_17 = V_1 -> V_3 ;
F_10 ( V_50 ) ;
V_17 -> V_69 -> V_70 ( V_17 , V_71 , V_72 ,
( char * ) & V_68 , sizeof ( V_68 ) ) ;
F_10 ( V_44 ) ;
}
int
F_19 ( T_1 * V_1 )
{
#if V_73
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_1 -> V_74 ;
#endif
struct V_27 * V_75 = V_1 -> V_76 ;
struct V_34 V_35 = {
. V_36 = NULL ,
. V_37 = 0 ,
. V_38 = V_29 ,
. V_39 = V_30 ,
. V_40 = NULL ,
. V_41 = 0 ,
. V_42 = 0
} ;
T_3 V_44 = F_8 () ;
int V_18 ;
int V_45 ;
int V_2 ;
int V_77 ;
int V_78 ;
T_5 V_79 ;
F_3 ( V_30 > 0 ) ;
for ( V_18 = V_45 = 0 ; V_45 < V_30 ; V_45 ++ ) {
V_29 [ V_45 ] = V_75 [ V_45 ] ;
V_18 += V_29 [ V_45 ] . V_47 ;
}
F_3 ( V_18 <= V_1 -> V_80 ) ;
F_10 ( V_50 ) ;
V_2 = F_20 ( V_1 -> V_3 , & V_35 , V_18 , V_43 ) ;
F_10 ( V_44 ) ;
V_79 = 0 ;
if ( V_1 -> V_11 == & V_21 ) {
V_79 = V_1 -> V_81 . V_25 ;
V_1 -> V_81 . V_25 = 0 ;
}
if ( V_79 != 0 ) {
for ( V_45 = 0 , V_78 = V_2 ; V_78 > 0 ; V_45 ++ , V_78 -= V_77 ) {
F_3 ( V_45 < V_30 ) ;
V_77 = V_75 [ V_45 ] . V_47 ;
if ( V_77 > V_78 )
V_77 = V_78 ;
V_1 -> V_82 = F_21 ( V_1 -> V_82 ,
V_75 [ V_45 ] . V_67 , V_77 ) ;
}
V_1 -> V_81 . V_25 = V_79 ;
}
return V_2 ;
}
static void
F_22 ( void * V_83 )
{
if ( V_83 == NULL )
return;
F_23 ( V_83 ) ;
}
static void *
F_24 ( T_4 * V_51 , int V_30 ,
struct V_27 * V_75 , struct V_55 * * V_84 )
{
void * V_83 ;
int V_18 ;
int V_45 ;
if ( ! * V_19 . V_85 || V_84 == NULL )
return NULL ;
F_3 ( V_30 <= V_86 ) ;
if ( V_30 < 2 ||
V_30 < * V_19 . V_87 )
return NULL ;
for ( V_18 = V_45 = 0 ; V_45 < V_30 ; V_45 ++ ) {
if ( ( V_51 [ V_45 ] . V_58 != 0 && V_45 > 0 ) ||
( V_51 [ V_45 ] . V_58 + V_51 [ V_45 ] . V_60 != V_88 && V_45 < V_30 - 1 ) )
return NULL ;
V_84 [ V_45 ] = V_51 [ V_45 ] . V_56 ;
V_18 += V_51 [ V_45 ] . V_60 ;
}
V_83 = F_25 ( V_84 , V_30 , V_89 , V_90 ) ;
if ( V_83 == NULL )
return NULL ;
V_75 -> V_67 = V_83 + V_51 [ 0 ] . V_58 ;
V_75 -> V_47 = V_18 ;
return V_83 ;
}
int
F_26 ( T_1 * V_1 )
{
#if V_73 || ! V_65
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
struct V_55 * * V_84 = NULL ;
unsigned int V_30 = 1 ;
#else
#ifdef F_15
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
struct V_55 * * V_84 = V_1 -> V_31 -> V_91 ;
unsigned int V_30 = V_1 -> V_92 ;
#endif
T_4 * V_51 = V_1 -> V_93 ;
struct V_34 V_35 = {
. V_36 = NULL ,
. V_37 = 0 ,
. V_38 = V_29 ,
. V_40 = NULL ,
. V_41 = 0 ,
. V_42 = 0
} ;
T_3 V_44 = F_8 () ;
int V_18 ;
int V_45 ;
int V_2 ;
void * V_94 ;
void * V_83 ;
int V_78 ;
int V_77 ;
if ( ( V_83 = F_24 ( V_51 , V_30 , V_29 , V_84 ) ) != NULL ) {
V_18 = V_29 [ 0 ] . V_47 ;
V_35 . V_39 = 1 ;
} else {
for ( V_18 = V_45 = 0 ; V_45 < V_30 ; V_45 ++ ) {
V_18 += V_29 [ V_45 ] . V_47 = V_51 [ V_45 ] . V_60 ;
V_29 [ V_45 ] . V_67 = F_16 ( V_51 [ V_45 ] . V_56 ) +
V_51 [ V_45 ] . V_58 ;
}
V_35 . V_39 = V_30 ;
}
F_3 ( V_18 <= V_1 -> V_80 ) ;
F_10 ( V_50 ) ;
V_2 = F_20 ( V_1 -> V_3 , & V_35 , V_18 , V_43 ) ;
F_10 ( V_44 ) ;
if ( V_1 -> V_81 . V_25 != 0 ) {
for ( V_45 = 0 , V_78 = V_2 ; V_78 > 0 ; V_45 ++ , V_78 -= V_77 ) {
F_3 ( V_45 < V_30 ) ;
V_94 = F_16 ( V_51 [ V_45 ] . V_56 ) + V_51 [ V_45 ] . V_58 ;
V_77 = V_51 [ V_45 ] . V_60 ;
if ( V_77 > V_78 )
V_77 = V_78 ;
V_1 -> V_82 = F_21 ( V_1 -> V_82 ,
V_94 , V_77 ) ;
F_17 ( V_51 [ V_45 ] . V_56 ) ;
}
}
if ( V_83 != NULL ) {
F_22 ( V_83 ) ;
} else {
for ( V_45 = 0 ; V_45 < V_30 ; V_45 ++ )
F_17 ( V_51 [ V_45 ] . V_56 ) ;
}
return ( V_2 ) ;
}
void
F_7 ( T_2 * V_15 )
{
int V_45 ;
T_5 V_95 ;
void * V_94 ;
F_3 ( V_15 -> V_46 [ 0 ] . V_67 == ( void * ) & V_15 -> V_24 ) ;
F_3 ( V_15 -> V_96 != NULL ) ;
F_3 ( V_15 -> V_96 -> V_11 == & V_21 ) ;
V_15 -> V_24 . V_25 = 0 ;
V_95 = F_21 ( ~ 0 , ( void * ) V_15 -> V_46 [ 0 ] . V_67 ,
V_15 -> V_46 [ 0 ] . V_47 ) ;
if ( V_15 -> V_52 != NULL ) {
for ( V_45 = 0 ; V_45 < V_15 -> V_66 ; V_45 ++ ) {
V_94 = F_16 ( V_15 -> V_52 [ V_45 ] . V_56 ) +
V_15 -> V_52 [ V_45 ] . V_58 ;
V_95 = F_21 ( V_95 , V_94 , V_15 -> V_52 [ V_45 ] . V_60 ) ;
F_17 ( V_15 -> V_52 [ V_45 ] . V_56 ) ;
}
} else {
for ( V_45 = 1 ; V_45 < V_15 -> V_33 ; V_45 ++ )
V_95 = F_21 ( V_95 , V_15 -> V_46 [ V_45 ] . V_67 ,
V_15 -> V_46 [ V_45 ] . V_47 ) ;
}
if ( * V_19 . V_97 ) {
V_95 ++ ;
* V_19 . V_97 = 0 ;
}
V_15 -> V_24 . V_25 = V_95 ;
}
int
F_27 ( T_1 * V_1 , int * V_98 , int * V_99 , int * V_100 )
{
T_3 V_44 = F_8 () ;
struct V_16 * V_17 = V_1 -> V_3 ;
int V_101 ;
int V_2 ;
V_2 = F_28 ( V_1 ) ;
if ( V_2 != 0 ) {
F_3 ( V_1 -> V_6 ) ;
* V_98 = * V_99 = * V_100 = 0 ;
return ( - V_102 ) ;
}
V_2 = F_29 ( V_17 , V_98 , V_99 ) ;
if ( V_2 == 0 ) {
V_101 = sizeof( * V_100 ) ;
F_10 ( V_50 ) ;
V_2 = V_17 -> V_69 -> V_103 ( V_17 , V_71 , V_104 ,
( char * ) V_100 , & V_101 ) ;
F_10 ( V_44 ) ;
}
F_30 ( V_1 ) ;
if ( V_2 == 0 )
* V_100 = ! * V_100 ;
else
* V_98 = * V_99 = * V_100 = 0 ;
return ( V_2 ) ;
}
int
F_31 ( struct V_16 * V_17 )
{
T_3 V_44 = F_8 () ;
int V_2 ;
int V_105 ;
int V_106 ;
int V_107 ;
int V_108 ;
int V_109 ;
struct V_110 V_110 ;
V_17 -> V_9 -> V_111 = V_112 ;
V_110 . V_113 = 0 ;
V_110 . V_114 = 0 ;
F_10 ( V_50 ) ;
V_2 = F_32 ( V_17 , V_115 , V_116 ,
( char * ) & V_110 , sizeof ( V_110 ) ) ;
F_10 ( V_44 ) ;
if ( V_2 != 0 ) {
F_4 ( L_4 , V_2 ) ;
return ( V_2 ) ;
}
V_105 = - 1 ;
F_10 ( V_50 ) ;
V_2 = V_17 -> V_69 -> V_70 ( V_17 , V_71 , V_117 ,
( char * ) & V_105 , sizeof ( V_105 ) ) ;
F_10 ( V_44 ) ;
if ( V_2 != 0 ) {
F_4 ( L_5 , V_2 ) ;
return ( V_2 ) ;
}
if ( ! * V_19 . V_118 ) {
V_105 = 1 ;
F_10 ( V_50 ) ;
V_2 = V_17 -> V_69 -> V_70 ( V_17 , V_71 , V_104 ,
( char * ) & V_105 , sizeof ( V_105 ) ) ;
F_10 ( V_44 ) ;
if ( V_2 != 0 ) {
F_4 ( L_6 , V_2 ) ;
return ( V_2 ) ;
}
}
V_2 = F_33 ( V_17 ,
* V_19 . V_119 ,
* V_19 . V_120 ) ;
if ( V_2 != 0 ) {
F_4 ( L_7 ,
* V_19 . V_119 ,
* V_19 . V_120 , V_2 ) ;
return ( V_2 ) ;
}
V_106 = * V_19 . V_121 ;
V_108 = * V_19 . V_122 ;
V_107 = * V_19 . V_123 ;
V_109 = ( V_106 > 0 && V_108 > 0 && V_107 > 0 ) ;
V_105 = ( V_109 ? 1 : 0 ) ;
F_10 ( V_50 ) ;
V_2 = F_32 ( V_17 , V_115 , V_124 ,
( char * ) & V_105 , sizeof ( V_105 ) ) ;
F_10 ( V_44 ) ;
if ( V_2 != 0 ) {
F_4 ( L_8 , V_2 ) ;
return ( V_2 ) ;
}
if ( ! V_109 )
return ( 0 ) ;
F_10 ( V_50 ) ;
V_2 = V_17 -> V_69 -> V_70 ( V_17 , V_71 , V_125 ,
( char * ) & V_106 , sizeof ( V_106 ) ) ;
F_10 ( V_44 ) ;
if ( V_2 != 0 ) {
F_4 ( L_9 , V_2 ) ;
return ( V_2 ) ;
}
F_10 ( V_50 ) ;
V_2 = V_17 -> V_69 -> V_70 ( V_17 , V_71 , V_126 ,
( char * ) & V_107 , sizeof ( V_107 ) ) ;
F_10 ( V_44 ) ;
if ( V_2 != 0 ) {
F_4 ( L_10 , V_2 ) ;
return ( V_2 ) ;
}
F_10 ( V_50 ) ;
V_2 = V_17 -> V_69 -> V_70 ( V_17 , V_71 , V_127 ,
( char * ) & V_108 , sizeof ( V_108 ) ) ;
F_10 ( V_44 ) ;
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
struct V_128 * V_129 ;
int V_130 ;
int V_131 = 1 ;
int V_2 ;
T_3 V_44 ;
V_2 = F_28 ( V_1 ) ;
if ( V_2 != 0 )
return;
V_9 = V_1 -> V_3 -> V_9 ;
V_129 = F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
V_130 = V_129 -> V_130 ;
V_129 -> V_130 = 1 ;
F_37 ( V_9 ) ;
V_44 = F_8 () ;
F_10 ( V_50 ) ;
V_2 = V_9 -> V_63 -> V_70 ( V_9 , V_71 , V_104 ,
( char * ) & V_131 , sizeof ( V_131 ) ) ;
F_3 ( V_2 == 0 ) ;
F_10 ( V_44 ) ;
F_36 ( V_9 ) ;
V_129 -> V_130 = V_130 ;
F_37 ( V_9 ) ;
F_30 ( V_1 ) ;
}
static void
F_38 ( struct V_17 * V_9 , int V_132 )
{
T_1 * V_1 ;
F_3 ( ! F_39 () ) ;
F_40 ( & V_133 . V_134 ) ;
V_1 = V_9 -> V_135 ;
if ( V_1 == NULL ) {
F_3 ( V_9 -> V_136 != & F_38 ) ;
V_9 -> V_136 ( V_9 , V_132 ) ;
} else
F_41 ( V_1 ) ;
F_42 ( & V_133 . V_134 ) ;
}
static void
F_43 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
int V_137 ;
int V_138 ;
F_3 ( ! F_39 () ) ;
F_40 ( & V_133 . V_134 ) ;
V_1 = V_9 -> V_135 ;
V_137 = F_44 ( V_9 ) ;
V_138 = F_45 ( V_9 ) ;
F_13 ( V_62 , L_12 ,
V_9 , V_137 , V_138 , V_1 ,
( V_1 == NULL ) ? L_13 : ( V_1 -> V_139 ?
L_14 : L_15 ) ,
( V_1 == NULL ) ? L_13 : ( V_1 -> V_140 ?
L_16 : L_17 ) ,
( V_1 == NULL ) ? L_13 : ( F_9 ( & V_1 -> V_48 ) ?
L_18 : L_19 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_9 -> V_141 != & F_43 ) ;
V_9 -> V_141 ( V_9 ) ;
F_42 ( & V_133 . V_134 ) ;
return;
}
if ( V_137 >= V_138 ) {
F_46 ( V_1 ) ;
F_47 ( V_142 , & V_9 -> V_143 -> V_144 ) ;
}
F_42 ( & V_133 . V_134 ) ;
}
void
F_48 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_1 -> V_145 = V_17 -> V_9 -> V_136 ;
V_1 -> V_146 = V_17 -> V_9 -> V_141 ;
}
void
F_49 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_135 = V_1 ;
V_17 -> V_9 -> V_136 = F_38 ;
V_17 -> V_9 -> V_141 = F_43 ;
return;
}
void
F_50 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_136 = V_1 -> V_145 ;
V_17 -> V_9 -> V_141 = V_1 -> V_146 ;
V_17 -> V_9 -> V_135 = NULL ;
return ;
}
int
F_51 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_6 * V_147 ;
V_147 = V_1 -> V_31 ;
F_52 ( & V_147 -> V_148 ) ;
if ( ! F_53 ( V_1 -> V_3 ) &&
! V_1 -> V_139 ) {
V_2 = - V_149 ;
}
F_54 ( & V_147 -> V_148 ) ;
return V_2 ;
}
