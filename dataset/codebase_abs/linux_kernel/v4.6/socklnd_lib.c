int
F_1 ( T_1 * V_1 )
{
int V_2 = F_2 ( V_1 -> V_3 , 1 , & V_1 -> V_4 ,
& V_1 -> V_5 ) ;
F_3 ( ! V_1 -> V_6 ) ;
if ( V_2 ) {
F_4 ( L_1 , V_2 ) ;
return V_2 ;
}
V_2 = F_2 ( V_1 -> V_3 , 0 , & V_1 -> V_7 , NULL ) ;
if ( V_2 ) {
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
return ( ( V_8 & V_13 ) && ( V_8 & V_14 ) ) ;
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
! V_15 -> V_24 . V_25 )
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
V_2 = F_9 ( V_17 , & V_35 , V_29 , V_30 , V_18 ) ;
}
return V_2 ;
}
int
F_10 ( T_1 * V_1 , T_2 * V_15 )
{
struct V_16 * V_17 = V_1 -> V_3 ;
T_3 * V_43 = V_15 -> V_44 ;
int V_2 ;
int V_18 ;
F_3 ( V_15 -> V_45 ) ;
if ( V_15 -> V_24 . V_46 [ 0 ] ) {
struct V_17 * V_9 = V_17 -> V_9 ;
struct V_47 * V_47 = V_43 -> V_48 ;
int V_49 = V_43 -> V_50 ;
int V_51 = V_43 -> V_52 ;
int V_53 = V_37 ;
F_11 ( V_54 , L_3 ,
V_47 , V_49 , V_43 -> V_52 ) ;
if ( ! F_8 ( & V_1 -> V_41 ) ||
V_51 < V_15 -> V_23 )
V_53 |= V_42 ;
if ( V_9 -> V_55 -> V_56 ) {
V_2 = V_9 -> V_55 -> V_56 ( V_9 , V_47 ,
V_49 , V_51 , V_53 ) ;
} else {
V_2 = F_12 ( V_9 , V_47 , V_49 , V_51 , V_53 ) ;
}
} else {
#if V_26 || ! V_57
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_15 -> V_58 ;
#endif
struct V_34 V_35 = { . V_36 = V_37 } ;
int V_38 ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_29 [ V_38 ] . V_59 = F_14 ( V_43 [ V_38 ] . V_48 ) +
V_43 [ V_38 ] . V_50 ;
V_18 += V_29 [ V_38 ] . V_40 = V_43 [ V_38 ] . V_52 ;
}
if ( ! F_8 ( & V_1 -> V_41 ) ||
V_18 < V_15 -> V_23 )
V_35 . V_36 |= V_42 ;
V_2 = F_9 ( V_17 , & V_35 , (struct V_27 * ) V_29 , V_30 , V_18 ) ;
for ( V_38 = 0 ; V_38 < V_30 ; V_38 ++ )
F_15 ( V_43 [ V_38 ] . V_48 ) ;
}
return V_2 ;
}
void
F_16 ( T_1 * V_1 )
{
int V_60 = 1 ;
struct V_16 * V_17 = V_1 -> V_3 ;
F_17 ( V_17 , V_61 , V_62 , ( char * ) & V_60 ,
sizeof( V_60 ) ) ;
}
int
F_18 ( T_1 * V_1 )
{
#if V_63
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_1 -> V_64 ;
#endif
struct V_27 * V_65 = V_1 -> V_66 ;
struct V_34 V_35 = {
. V_36 = 0
} ;
int V_18 ;
int V_38 ;
int V_2 ;
int V_67 ;
int V_68 ;
T_4 V_69 ;
F_3 ( V_30 > 0 ) ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_29 [ V_38 ] = V_65 [ V_38 ] ;
V_18 += V_29 [ V_38 ] . V_40 ;
}
F_3 ( V_18 <= V_1 -> V_70 ) ;
V_2 = F_19 ( V_1 -> V_3 , & V_35 , V_29 , V_30 , V_18 ,
V_37 ) ;
V_69 = 0 ;
if ( V_1 -> V_11 == & V_21 ) {
V_69 = V_1 -> V_71 . V_25 ;
V_1 -> V_71 . V_25 = 0 ;
}
if ( V_69 ) {
for ( V_38 = 0 , V_68 = V_2 ; V_68 > 0 ; V_38 ++ , V_68 -= V_67 ) {
F_3 ( V_38 < V_30 ) ;
V_67 = V_65 [ V_38 ] . V_40 ;
if ( V_67 > V_68 )
V_67 = V_68 ;
V_1 -> V_72 = F_20 ( V_1 -> V_72 ,
V_65 [ V_38 ] . V_59 , V_67 ) ;
}
V_1 -> V_71 . V_25 = V_69 ;
}
return V_2 ;
}
static void
F_21 ( void * V_73 )
{
if ( ! V_73 )
return;
F_22 ( V_73 ) ;
}
static void *
F_23 ( T_3 * V_43 , int V_30 ,
struct V_27 * V_65 , struct V_47 * * V_74 )
{
void * V_73 ;
int V_18 ;
int V_38 ;
if ( ! * V_19 . V_75 || ! V_74 )
return NULL ;
F_3 ( V_30 <= V_76 ) ;
if ( V_30 < 2 ||
V_30 < * V_19 . V_77 )
return NULL ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
if ( ( V_43 [ V_38 ] . V_50 && V_38 > 0 ) ||
( V_43 [ V_38 ] . V_50 + V_43 [ V_38 ] . V_52 != V_78 && V_38 < V_30 - 1 ) )
return NULL ;
V_74 [ V_38 ] = V_43 [ V_38 ] . V_48 ;
V_18 += V_43 [ V_38 ] . V_52 ;
}
V_73 = F_24 ( V_74 , V_30 , V_79 , V_80 ) ;
if ( ! V_73 )
return NULL ;
V_65 -> V_59 = V_73 + V_43 [ 0 ] . V_50 ;
V_65 -> V_40 = V_18 ;
return V_73 ;
}
int
F_25 ( T_1 * V_1 )
{
#if V_63 || ! V_57
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
struct V_47 * * V_74 = NULL ;
unsigned int V_30 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
struct V_47 * * V_74 = V_1 -> V_31 -> V_81 ;
unsigned int V_30 = V_1 -> V_82 ;
#endif
T_3 * V_43 = V_1 -> V_83 ;
struct V_34 V_35 = {
. V_36 = 0
} ;
int V_18 ;
int V_38 ;
int V_2 ;
void * V_84 ;
void * V_73 ;
int V_68 ;
int V_67 ;
int V_85 ;
V_73 = F_23 ( V_43 , V_30 , V_29 , V_74 ) ;
if ( V_73 ) {
V_18 = V_29 [ 0 ] . V_40 ;
V_85 = 1 ;
} else {
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_18 += V_29 [ V_38 ] . V_40 = V_43 [ V_38 ] . V_52 ;
V_29 [ V_38 ] . V_59 = F_14 ( V_43 [ V_38 ] . V_48 ) +
V_43 [ V_38 ] . V_50 ;
}
V_85 = V_30 ;
}
F_3 ( V_18 <= V_1 -> V_70 ) ;
V_2 = F_19 ( V_1 -> V_3 , & V_35 , (struct V_27 * ) V_29 ,
V_85 , V_18 , V_37 ) ;
if ( V_1 -> V_71 . V_25 ) {
for ( V_38 = 0 , V_68 = V_2 ; V_68 > 0 ; V_38 ++ , V_68 -= V_67 ) {
F_3 ( V_38 < V_30 ) ;
V_84 = F_14 ( V_43 [ V_38 ] . V_48 ) + V_43 [ V_38 ] . V_50 ;
V_67 = V_43 [ V_38 ] . V_52 ;
if ( V_67 > V_68 )
V_67 = V_68 ;
V_1 -> V_72 = F_20 ( V_1 -> V_72 ,
V_84 , V_67 ) ;
F_15 ( V_43 [ V_38 ] . V_48 ) ;
}
}
if ( V_73 ) {
F_21 ( V_73 ) ;
} else {
for ( V_38 = 0 ; V_38 < V_30 ; V_38 ++ )
F_15 ( V_43 [ V_38 ] . V_48 ) ;
}
return V_2 ;
}
void
F_7 ( T_2 * V_15 )
{
int V_38 ;
T_4 V_86 ;
void * V_84 ;
F_3 ( V_15 -> V_39 [ 0 ] . V_59 == & V_15 -> V_24 ) ;
F_3 ( V_15 -> V_87 ) ;
F_3 ( V_15 -> V_87 -> V_11 == & V_21 ) ;
V_15 -> V_24 . V_25 = 0 ;
V_86 = F_20 ( ~ 0 , V_15 -> V_39 [ 0 ] . V_59 ,
V_15 -> V_39 [ 0 ] . V_40 ) ;
if ( V_15 -> V_44 ) {
for ( V_38 = 0 ; V_38 < V_15 -> V_58 ; V_38 ++ ) {
V_84 = F_14 ( V_15 -> V_44 [ V_38 ] . V_48 ) +
V_15 -> V_44 [ V_38 ] . V_50 ;
V_86 = F_20 ( V_86 , V_84 , V_15 -> V_44 [ V_38 ] . V_52 ) ;
F_15 ( V_15 -> V_44 [ V_38 ] . V_48 ) ;
}
} else {
for ( V_38 = 1 ; V_38 < V_15 -> V_33 ; V_38 ++ )
V_86 = F_20 ( V_86 , V_15 -> V_39 [ V_38 ] . V_59 ,
V_15 -> V_39 [ V_38 ] . V_40 ) ;
}
if ( * V_19 . V_88 ) {
V_86 ++ ;
* V_19 . V_88 = 0 ;
}
V_15 -> V_24 . V_25 = V_86 ;
}
int
F_26 ( T_1 * V_1 , int * V_89 , int * V_90 , int * V_91 )
{
struct V_16 * V_17 = V_1 -> V_3 ;
int V_92 ;
int V_2 ;
V_2 = F_27 ( V_1 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_6 ) ;
* V_89 = * V_90 = * V_91 = 0 ;
return - V_93 ;
}
V_2 = F_28 ( V_17 , V_89 , V_90 ) ;
if ( ! V_2 ) {
V_92 = sizeof( * V_91 ) ;
V_2 = F_29 ( V_17 , V_61 , V_94 ,
( char * ) V_91 , & V_92 ) ;
}
F_30 ( V_1 ) ;
if ( ! V_2 )
* V_91 = ! * V_91 ;
else
* V_89 = * V_90 = * V_91 = 0 ;
return V_2 ;
}
int
F_31 ( struct V_16 * V_17 )
{
int V_2 ;
int V_95 ;
int V_96 ;
int V_97 ;
int V_98 ;
int V_99 ;
struct V_100 V_100 ;
V_17 -> V_9 -> V_101 = V_102 ;
V_100 . V_103 = 0 ;
V_100 . V_104 = 0 ;
V_2 = F_17 ( V_17 , V_105 , V_106 , ( char * ) & V_100 ,
sizeof( V_100 ) ) ;
if ( V_2 ) {
F_4 ( L_4 , V_2 ) ;
return V_2 ;
}
V_95 = - 1 ;
V_2 = F_17 ( V_17 , V_61 , V_107 , ( char * ) & V_95 ,
sizeof( V_95 ) ) ;
if ( V_2 ) {
F_4 ( L_5 , V_2 ) ;
return V_2 ;
}
if ( ! * V_19 . V_108 ) {
V_95 = 1 ;
V_2 = F_17 ( V_17 , V_61 , V_94 ,
( char * ) & V_95 , sizeof( V_95 ) ) ;
if ( V_2 ) {
F_4 ( L_6 , V_2 ) ;
return V_2 ;
}
}
V_2 = F_32 ( V_17 , * V_19 . V_109 ,
* V_19 . V_110 ) ;
if ( V_2 ) {
F_4 ( L_7 ,
* V_19 . V_109 ,
* V_19 . V_110 , V_2 ) ;
return V_2 ;
}
V_96 = * V_19 . V_111 ;
V_98 = * V_19 . V_112 ;
V_97 = * V_19 . V_113 ;
V_99 = ( V_96 > 0 && V_98 > 0 && V_97 > 0 ) ;
V_95 = ( V_99 ? 1 : 0 ) ;
V_2 = F_17 ( V_17 , V_105 , V_114 , ( char * ) & V_95 ,
sizeof( V_95 ) ) ;
if ( V_2 ) {
F_4 ( L_8 , V_2 ) ;
return V_2 ;
}
if ( ! V_99 )
return 0 ;
V_2 = F_17 ( V_17 , V_61 , V_115 , ( char * ) & V_96 ,
sizeof( V_96 ) ) ;
if ( V_2 ) {
F_4 ( L_9 , V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_17 , V_61 , V_116 ,
( char * ) & V_97 , sizeof( V_97 ) ) ;
if ( V_2 ) {
F_4 ( L_10 , V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_17 , V_61 , V_117 , ( char * ) & V_98 ,
sizeof( V_98 ) ) ;
if ( V_2 ) {
F_4 ( L_11 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
void
F_33 ( T_1 * V_1 )
{
struct V_17 * V_9 ;
struct V_118 * V_119 ;
int V_120 ;
int V_121 = 1 ;
int V_2 ;
V_2 = F_27 ( V_1 ) ;
if ( V_2 )
return;
V_9 = V_1 -> V_3 -> V_9 ;
V_119 = F_34 ( V_9 ) ;
F_35 ( V_9 ) ;
V_120 = V_119 -> V_120 ;
V_119 -> V_120 = 1 ;
F_36 ( V_9 ) ;
V_2 = F_17 ( V_1 -> V_3 , V_61 , V_94 ,
( char * ) & V_121 , sizeof( V_121 ) ) ;
F_3 ( ! V_2 ) ;
F_35 ( V_9 ) ;
V_119 -> V_120 = V_120 ;
F_36 ( V_9 ) ;
F_30 ( V_1 ) ;
}
static void
F_37 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
F_3 ( ! F_38 () ) ;
F_39 ( & V_122 . V_123 ) ;
V_1 = V_9 -> V_124 ;
if ( ! V_1 ) {
F_3 ( V_9 -> V_125 != & F_37 ) ;
V_9 -> V_125 ( V_9 ) ;
} else {
F_40 ( V_1 ) ;
}
F_41 ( & V_122 . V_123 ) ;
}
static void
F_42 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
int V_126 ;
int V_127 ;
F_3 ( ! F_38 () ) ;
F_39 ( & V_122 . V_123 ) ;
V_1 = V_9 -> V_124 ;
V_126 = F_43 ( V_9 ) ;
V_127 = F_44 ( V_9 ) ;
F_11 ( V_54 , L_12 ,
V_9 , V_126 , V_127 , V_1 ,
! V_1 ? L_13 : ( V_1 -> V_128 ?
L_14 : L_15 ) ,
! V_1 ? L_13 : ( V_1 -> V_129 ?
L_16 : L_17 ) ,
! V_1 ? L_13 : ( F_8 ( & V_1 -> V_41 ) ?
L_18 : L_19 ) ) ;
if ( ! V_1 ) {
F_3 ( V_9 -> V_130 != & F_42 ) ;
V_9 -> V_130 ( V_9 ) ;
F_41 ( & V_122 . V_123 ) ;
return;
}
if ( V_126 >= V_127 ) {
F_45 ( V_1 ) ;
F_46 ( V_131 , & V_9 -> V_132 -> V_133 ) ;
}
F_41 ( & V_122 . V_123 ) ;
}
void
F_47 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_1 -> V_134 = V_17 -> V_9 -> V_125 ;
V_1 -> V_135 = V_17 -> V_9 -> V_130 ;
}
void
F_48 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_124 = V_1 ;
V_17 -> V_9 -> V_125 = F_37 ;
V_17 -> V_9 -> V_130 = F_42 ;
return;
}
void
F_49 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_125 = V_1 -> V_134 ;
V_17 -> V_9 -> V_130 = V_1 -> V_135 ;
V_17 -> V_9 -> V_124 = NULL ;
return ;
}
int
F_50 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_5 * V_136 ;
V_136 = V_1 -> V_31 ;
F_51 ( & V_136 -> V_137 ) ;
if ( ! F_52 ( V_131 , & V_1 -> V_3 -> V_133 ) &&
! V_1 -> V_128 ) {
V_2 = - V_138 ;
}
F_53 ( & V_136 -> V_137 ) ;
return V_2 ;
}
