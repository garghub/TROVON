int
F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 -> V_4 , 1 , & V_2 -> V_5 ,
& V_2 -> V_6 ) ;
F_3 ( ! V_2 -> V_7 ) ;
if ( V_3 ) {
F_4 ( L_1 , V_3 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_4 , 0 , & V_2 -> V_8 , NULL ) ;
if ( V_3 ) {
F_4 ( L_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
int
F_5 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_4 -> V_10 -> V_11 ;
if ( V_2 -> V_12 == & V_13 )
return 0 ;
return ( ( V_9 & V_14 ) && ( V_9 & V_15 ) ) ;
}
int
F_6 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_2 -> V_4 ;
int V_20 ;
int V_3 ;
if ( * V_21 . V_22 &&
V_2 -> V_12 == & V_23 &&
V_17 -> V_24 == V_17 -> V_25 &&
! V_17 -> V_26 . V_27 )
F_7 ( V_17 ) ;
{
#if V_28
struct V_29 V_30 ;
struct V_29 * V_31 = & V_30 ;
unsigned int V_32 = 1 ;
#else
struct V_29 * V_31 = V_2 -> V_33 -> V_34 ;
unsigned int V_32 = V_17 -> V_35 ;
#endif
struct V_36 V_37 = { . V_38 = V_39 } ;
int V_40 ;
for ( V_20 = V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
V_31 [ V_40 ] = V_17 -> V_41 [ V_40 ] ;
V_20 += V_31 [ V_40 ] . V_42 ;
}
if ( ! F_8 ( & V_2 -> V_43 ) ||
V_20 < V_17 -> V_25 )
V_37 . V_38 |= V_44 ;
V_3 = F_9 ( V_19 , & V_37 , V_31 , V_32 , V_20 ) ;
}
return V_3 ;
}
int
F_10 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_2 -> V_4 ;
T_1 * V_45 = V_17 -> V_46 ;
int V_3 ;
int V_20 ;
F_3 ( V_17 -> V_47 ) ;
if ( V_17 -> V_26 . V_48 [ 0 ] ) {
struct V_19 * V_10 = V_19 -> V_10 ;
struct V_49 * V_49 = V_45 -> V_50 ;
int V_51 = V_45 -> V_52 ;
int V_53 = V_45 -> V_54 ;
int V_55 = V_39 ;
F_11 ( V_56 , L_3 ,
V_49 , V_51 , V_45 -> V_54 ) ;
if ( ! F_8 ( & V_2 -> V_43 ) ||
V_53 < V_17 -> V_25 )
V_55 |= V_44 ;
if ( V_10 -> V_57 -> V_58 ) {
V_3 = V_10 -> V_57 -> V_58 ( V_10 , V_49 ,
V_51 , V_53 , V_55 ) ;
} else {
V_3 = F_12 ( V_10 , V_49 , V_51 , V_53 , V_55 ) ;
}
} else {
#if V_28 || ! V_59
struct V_29 V_30 ;
struct V_29 * V_31 = & V_30 ;
unsigned int V_32 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_29 * V_31 = V_2 -> V_33 -> V_34 ;
unsigned int V_32 = V_17 -> V_60 ;
#endif
struct V_36 V_37 = { . V_38 = V_39 } ;
int V_40 ;
for ( V_20 = V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
V_31 [ V_40 ] . V_61 = F_14 ( V_45 [ V_40 ] . V_50 ) +
V_45 [ V_40 ] . V_52 ;
V_20 += V_31 [ V_40 ] . V_42 = V_45 [ V_40 ] . V_54 ;
}
if ( ! F_8 ( & V_2 -> V_43 ) ||
V_20 < V_17 -> V_25 )
V_37 . V_38 |= V_44 ;
V_3 = F_9 ( V_19 , & V_37 , (struct V_29 * ) V_31 , V_32 , V_20 ) ;
for ( V_40 = 0 ; V_40 < V_32 ; V_40 ++ )
F_15 ( V_45 [ V_40 ] . V_50 ) ;
}
return V_3 ;
}
void
F_16 ( struct V_1 * V_2 )
{
int V_62 = 1 ;
struct V_18 * V_19 = V_2 -> V_4 ;
F_17 ( V_19 , V_63 , V_64 , ( char * ) & V_62 ,
sizeof( V_62 ) ) ;
}
int
F_18 ( struct V_1 * V_2 )
{
#if V_65
struct V_29 V_30 ;
struct V_29 * V_31 = & V_30 ;
unsigned int V_32 = 1 ;
#else
struct V_29 * V_31 = V_2 -> V_33 -> V_34 ;
unsigned int V_32 = V_2 -> V_66 ;
#endif
struct V_29 * V_67 = V_2 -> V_68 ;
struct V_36 V_37 = {
. V_38 = 0
} ;
int V_20 ;
int V_40 ;
int V_3 ;
int V_69 ;
int V_70 ;
T_2 V_71 ;
F_3 ( V_32 > 0 ) ;
for ( V_20 = V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
V_31 [ V_40 ] = V_67 [ V_40 ] ;
V_20 += V_31 [ V_40 ] . V_42 ;
}
F_3 ( V_20 <= V_2 -> V_72 ) ;
V_3 = F_19 ( V_2 -> V_4 , & V_37 , V_31 , V_32 , V_20 ,
V_39 ) ;
V_71 = 0 ;
if ( V_2 -> V_12 == & V_23 ) {
V_71 = V_2 -> V_73 . V_27 ;
V_2 -> V_73 . V_27 = 0 ;
}
if ( V_71 ) {
for ( V_40 = 0 , V_70 = V_3 ; V_70 > 0 ; V_40 ++ , V_70 -= V_69 ) {
F_3 ( V_40 < V_32 ) ;
V_69 = V_67 [ V_40 ] . V_42 ;
if ( V_69 > V_70 )
V_69 = V_70 ;
V_2 -> V_74 = F_20 ( V_2 -> V_74 ,
V_67 [ V_40 ] . V_61 , V_69 ) ;
}
V_2 -> V_73 . V_27 = V_71 ;
}
return V_3 ;
}
static void
F_21 ( void * V_75 )
{
if ( ! V_75 )
return;
F_22 ( V_75 ) ;
}
static void *
F_23 ( T_1 * V_45 , int V_32 ,
struct V_29 * V_67 , struct V_49 * * V_76 )
{
void * V_75 ;
int V_20 ;
int V_40 ;
if ( ! * V_21 . V_77 || ! V_76 )
return NULL ;
F_3 ( V_32 <= V_78 ) ;
if ( V_32 < 2 ||
V_32 < * V_21 . V_79 )
return NULL ;
for ( V_20 = V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
if ( ( V_45 [ V_40 ] . V_52 && V_40 > 0 ) ||
( V_45 [ V_40 ] . V_52 + V_45 [ V_40 ] . V_54 != V_80 && V_40 < V_32 - 1 ) )
return NULL ;
V_76 [ V_40 ] = V_45 [ V_40 ] . V_50 ;
V_20 += V_45 [ V_40 ] . V_54 ;
}
V_75 = F_24 ( V_76 , V_32 , V_81 , V_82 ) ;
if ( ! V_75 )
return NULL ;
V_67 -> V_61 = V_75 + V_45 [ 0 ] . V_52 ;
V_67 -> V_42 = V_20 ;
return V_75 ;
}
int
F_25 ( struct V_1 * V_2 )
{
#if V_65 || ! V_59
struct V_29 V_30 ;
struct V_29 * V_31 = & V_30 ;
struct V_49 * * V_76 = NULL ;
unsigned int V_32 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_29 * V_31 = V_2 -> V_33 -> V_34 ;
struct V_49 * * V_76 = V_2 -> V_33 -> V_83 ;
unsigned int V_32 = V_2 -> V_84 ;
#endif
T_1 * V_45 = V_2 -> V_85 ;
struct V_36 V_37 = {
. V_38 = 0
} ;
int V_20 ;
int V_40 ;
int V_3 ;
void * V_86 ;
void * V_75 ;
int V_70 ;
int V_69 ;
int V_87 ;
V_75 = F_23 ( V_45 , V_32 , V_31 , V_76 ) ;
if ( V_75 ) {
V_20 = V_31 [ 0 ] . V_42 ;
V_87 = 1 ;
} else {
for ( V_20 = V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
V_20 += V_31 [ V_40 ] . V_42 = V_45 [ V_40 ] . V_54 ;
V_31 [ V_40 ] . V_61 = F_14 ( V_45 [ V_40 ] . V_50 ) +
V_45 [ V_40 ] . V_52 ;
}
V_87 = V_32 ;
}
F_3 ( V_20 <= V_2 -> V_72 ) ;
V_3 = F_19 ( V_2 -> V_4 , & V_37 , (struct V_29 * ) V_31 ,
V_87 , V_20 , V_39 ) ;
if ( V_2 -> V_73 . V_27 ) {
for ( V_40 = 0 , V_70 = V_3 ; V_70 > 0 ; V_40 ++ , V_70 -= V_69 ) {
F_3 ( V_40 < V_32 ) ;
V_86 = F_14 ( V_45 [ V_40 ] . V_50 ) + V_45 [ V_40 ] . V_52 ;
V_69 = V_45 [ V_40 ] . V_54 ;
if ( V_69 > V_70 )
V_69 = V_70 ;
V_2 -> V_74 = F_20 ( V_2 -> V_74 ,
V_86 , V_69 ) ;
F_15 ( V_45 [ V_40 ] . V_50 ) ;
}
}
if ( V_75 ) {
F_21 ( V_75 ) ;
} else {
for ( V_40 = 0 ; V_40 < V_32 ; V_40 ++ )
F_15 ( V_45 [ V_40 ] . V_50 ) ;
}
return V_3 ;
}
void
F_7 ( struct V_16 * V_17 )
{
int V_40 ;
T_2 V_88 ;
void * V_86 ;
F_3 ( V_17 -> V_41 [ 0 ] . V_61 == & V_17 -> V_26 ) ;
F_3 ( V_17 -> V_89 ) ;
F_3 ( V_17 -> V_89 -> V_12 == & V_23 ) ;
V_17 -> V_26 . V_27 = 0 ;
V_88 = F_20 ( ~ 0 , V_17 -> V_41 [ 0 ] . V_61 ,
V_17 -> V_41 [ 0 ] . V_42 ) ;
if ( V_17 -> V_46 ) {
for ( V_40 = 0 ; V_40 < V_17 -> V_60 ; V_40 ++ ) {
V_86 = F_14 ( V_17 -> V_46 [ V_40 ] . V_50 ) +
V_17 -> V_46 [ V_40 ] . V_52 ;
V_88 = F_20 ( V_88 , V_86 , V_17 -> V_46 [ V_40 ] . V_54 ) ;
F_15 ( V_17 -> V_46 [ V_40 ] . V_50 ) ;
}
} else {
for ( V_40 = 1 ; V_40 < V_17 -> V_35 ; V_40 ++ )
V_88 = F_20 ( V_88 , V_17 -> V_41 [ V_40 ] . V_61 ,
V_17 -> V_41 [ V_40 ] . V_42 ) ;
}
if ( * V_21 . V_90 ) {
V_88 ++ ;
* V_21 . V_90 = 0 ;
}
V_17 -> V_26 . V_27 = V_88 ;
}
int
F_26 ( struct V_1 * V_2 , int * V_91 , int * V_92 , int * V_93 )
{
struct V_18 * V_19 = V_2 -> V_4 ;
int V_94 ;
int V_3 ;
V_3 = F_27 ( V_2 ) ;
if ( V_3 ) {
F_3 ( V_2 -> V_7 ) ;
* V_91 = * V_92 = * V_93 = 0 ;
return - V_95 ;
}
V_3 = F_28 ( V_19 , V_91 , V_92 ) ;
if ( ! V_3 ) {
V_94 = sizeof( * V_93 ) ;
V_3 = F_29 ( V_19 , V_63 , V_96 ,
( char * ) V_93 , & V_94 ) ;
}
F_30 ( V_2 ) ;
if ( ! V_3 )
* V_93 = ! * V_93 ;
else
* V_91 = * V_92 = * V_93 = 0 ;
return V_3 ;
}
int
F_31 ( struct V_18 * V_19 )
{
int V_3 ;
int V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
int V_101 ;
struct V_102 V_102 ;
V_19 -> V_10 -> V_103 = V_104 ;
V_102 . V_105 = 0 ;
V_102 . V_106 = 0 ;
V_3 = F_17 ( V_19 , V_107 , V_108 , ( char * ) & V_102 ,
sizeof( V_102 ) ) ;
if ( V_3 ) {
F_4 ( L_4 , V_3 ) ;
return V_3 ;
}
V_97 = - 1 ;
V_3 = F_17 ( V_19 , V_63 , V_109 , ( char * ) & V_97 ,
sizeof( V_97 ) ) ;
if ( V_3 ) {
F_4 ( L_5 , V_3 ) ;
return V_3 ;
}
if ( ! * V_21 . V_110 ) {
V_97 = 1 ;
V_3 = F_17 ( V_19 , V_63 , V_96 ,
( char * ) & V_97 , sizeof( V_97 ) ) ;
if ( V_3 ) {
F_4 ( L_6 , V_3 ) ;
return V_3 ;
}
}
V_3 = F_32 ( V_19 , * V_21 . V_111 ,
* V_21 . V_112 ) ;
if ( V_3 ) {
F_4 ( L_7 ,
* V_21 . V_111 ,
* V_21 . V_112 , V_3 ) ;
return V_3 ;
}
V_98 = * V_21 . V_113 ;
V_100 = * V_21 . V_114 ;
V_99 = * V_21 . V_115 ;
V_101 = ( V_98 > 0 && V_100 > 0 && V_99 > 0 ) ;
V_97 = ( V_101 ? 1 : 0 ) ;
V_3 = F_17 ( V_19 , V_107 , V_116 , ( char * ) & V_97 ,
sizeof( V_97 ) ) ;
if ( V_3 ) {
F_4 ( L_8 , V_3 ) ;
return V_3 ;
}
if ( ! V_101 )
return 0 ;
V_3 = F_17 ( V_19 , V_63 , V_117 , ( char * ) & V_98 ,
sizeof( V_98 ) ) ;
if ( V_3 ) {
F_4 ( L_9 , V_3 ) ;
return V_3 ;
}
V_3 = F_17 ( V_19 , V_63 , V_118 ,
( char * ) & V_99 , sizeof( V_99 ) ) ;
if ( V_3 ) {
F_4 ( L_10 , V_3 ) ;
return V_3 ;
}
V_3 = F_17 ( V_19 , V_63 , V_119 , ( char * ) & V_100 ,
sizeof( V_100 ) ) ;
if ( V_3 ) {
F_4 ( L_11 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
void
F_33 ( struct V_1 * V_2 )
{
struct V_19 * V_10 ;
struct V_120 * V_121 ;
int V_122 ;
int V_123 = 1 ;
int V_3 ;
V_3 = F_27 ( V_2 ) ;
if ( V_3 )
return;
V_10 = V_2 -> V_4 -> V_10 ;
V_121 = F_34 ( V_10 ) ;
F_35 ( V_10 ) ;
V_122 = V_121 -> V_122 ;
V_121 -> V_122 = 1 ;
F_36 ( V_10 ) ;
V_3 = F_17 ( V_2 -> V_4 , V_63 , V_96 ,
( char * ) & V_123 , sizeof( V_123 ) ) ;
F_3 ( ! V_3 ) ;
F_35 ( V_10 ) ;
V_121 -> V_122 = V_122 ;
F_36 ( V_10 ) ;
F_30 ( V_2 ) ;
}
static void
F_37 ( struct V_19 * V_10 )
{
struct V_1 * V_2 ;
F_3 ( ! F_38 () ) ;
F_39 ( & V_124 . V_125 ) ;
V_2 = V_10 -> V_126 ;
if ( ! V_2 ) {
F_3 ( V_10 -> V_127 != & F_37 ) ;
V_10 -> V_127 ( V_10 ) ;
} else {
F_40 ( V_2 ) ;
}
F_41 ( & V_124 . V_125 ) ;
}
static void
F_42 ( struct V_19 * V_10 )
{
struct V_1 * V_2 ;
int V_128 ;
int V_129 ;
F_3 ( ! F_38 () ) ;
F_39 ( & V_124 . V_125 ) ;
V_2 = V_10 -> V_126 ;
V_128 = F_43 ( V_10 ) ;
V_129 = F_44 ( V_10 ) ;
F_11 ( V_56 , L_12 ,
V_10 , V_128 , V_129 , V_2 ,
! V_2 ? L_13 : ( V_2 -> V_130 ?
L_14 : L_15 ) ,
! V_2 ? L_13 : ( V_2 -> V_131 ?
L_16 : L_17 ) ,
! V_2 ? L_13 : ( F_8 ( & V_2 -> V_43 ) ?
L_18 : L_19 ) ) ;
if ( ! V_2 ) {
F_3 ( V_10 -> V_132 != & F_42 ) ;
V_10 -> V_132 ( V_10 ) ;
F_41 ( & V_124 . V_125 ) ;
return;
}
if ( V_128 >= V_129 ) {
F_45 ( V_2 ) ;
F_46 ( V_133 , & V_10 -> V_134 -> V_135 ) ;
}
F_41 ( & V_124 . V_125 ) ;
}
void
F_47 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
V_2 -> V_136 = V_19 -> V_10 -> V_127 ;
V_2 -> V_137 = V_19 -> V_10 -> V_132 ;
}
void
F_48 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
V_19 -> V_10 -> V_126 = V_2 ;
V_19 -> V_10 -> V_127 = F_37 ;
V_19 -> V_10 -> V_132 = F_42 ;
}
void
F_49 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
V_19 -> V_10 -> V_127 = V_2 -> V_136 ;
V_19 -> V_10 -> V_132 = V_2 -> V_137 ;
V_19 -> V_10 -> V_126 = NULL ;
}
int
F_50 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_138 * V_139 ;
V_139 = V_2 -> V_33 ;
F_51 ( & V_139 -> V_140 ) ;
if ( ! F_52 ( V_133 , & V_2 -> V_4 -> V_135 ) &&
! V_2 -> V_130 ) {
V_3 = - V_141 ;
}
F_53 ( & V_139 -> V_140 ) ;
return V_3 ;
}
