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
struct V_16 * V_17 = V_1 -> V_3 ;
F_17 ( V_17 , V_62 , V_63 ,
( char * ) & V_61 , sizeof ( V_61 ) ) ;
}
int
F_18 ( T_1 * V_1 )
{
#if V_64
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
unsigned int V_30 = 1 ;
#else
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
unsigned int V_30 = V_1 -> V_65 ;
#endif
struct V_27 * V_66 = V_1 -> V_67 ;
struct V_34 V_35 = {
. V_36 = 0
} ;
int V_18 ;
int V_38 ;
int V_2 ;
int V_68 ;
int V_69 ;
T_4 V_70 ;
F_3 ( V_30 > 0 ) ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_29 [ V_38 ] = V_66 [ V_38 ] ;
V_18 += V_29 [ V_38 ] . V_40 ;
}
F_3 ( V_18 <= V_1 -> V_71 ) ;
V_2 = F_19 ( V_1 -> V_3 , & V_35 ,
(struct V_43 * ) V_29 , V_30 , V_18 , V_37 ) ;
V_70 = 0 ;
if ( V_1 -> V_11 == & V_21 ) {
V_70 = V_1 -> V_72 . V_25 ;
V_1 -> V_72 . V_25 = 0 ;
}
if ( V_70 != 0 ) {
for ( V_38 = 0 , V_69 = V_2 ; V_69 > 0 ; V_38 ++ , V_69 -= V_68 ) {
F_3 ( V_38 < V_30 ) ;
V_68 = V_66 [ V_38 ] . V_40 ;
if ( V_68 > V_69 )
V_68 = V_69 ;
V_1 -> V_73 = F_20 ( V_1 -> V_73 ,
V_66 [ V_38 ] . V_60 , V_68 ) ;
}
V_1 -> V_72 . V_25 = V_70 ;
}
return V_2 ;
}
static void
F_21 ( void * V_74 )
{
if ( V_74 == NULL )
return;
F_22 ( V_74 ) ;
}
static void *
F_23 ( T_3 * V_44 , int V_30 ,
struct V_27 * V_66 , struct V_48 * * V_75 )
{
void * V_74 ;
int V_18 ;
int V_38 ;
if ( ! * V_19 . V_76 || V_75 == NULL )
return NULL ;
F_3 ( V_30 <= V_77 ) ;
if ( V_30 < 2 ||
V_30 < * V_19 . V_78 )
return NULL ;
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
if ( ( V_44 [ V_38 ] . V_51 != 0 && V_38 > 0 ) ||
( V_44 [ V_38 ] . V_51 + V_44 [ V_38 ] . V_53 != V_79 && V_38 < V_30 - 1 ) )
return NULL ;
V_75 [ V_38 ] = V_44 [ V_38 ] . V_49 ;
V_18 += V_44 [ V_38 ] . V_53 ;
}
V_74 = F_24 ( V_75 , V_30 , V_80 , V_81 ) ;
if ( V_74 == NULL )
return NULL ;
V_66 -> V_60 = V_74 + V_44 [ 0 ] . V_51 ;
V_66 -> V_40 = V_18 ;
return V_74 ;
}
int
F_25 ( T_1 * V_1 )
{
#if V_64 || ! V_58
struct V_27 V_28 ;
struct V_27 * V_29 = & V_28 ;
struct V_48 * * V_75 = NULL ;
unsigned int V_30 = 1 ;
#else
#ifdef F_13
#warning "XXX risk of kmap deadlock on multiple frags..."
#endif
struct V_27 * V_29 = V_1 -> V_31 -> V_32 ;
struct V_48 * * V_75 = V_1 -> V_31 -> V_82 ;
unsigned int V_30 = V_1 -> V_83 ;
#endif
T_3 * V_44 = V_1 -> V_84 ;
struct V_34 V_35 = {
. V_36 = 0
} ;
int V_18 ;
int V_38 ;
int V_2 ;
void * V_85 ;
void * V_74 ;
int V_69 ;
int V_68 ;
int V_86 ;
V_74 = F_23 ( V_44 , V_30 , V_29 , V_75 ) ;
if ( V_74 != NULL ) {
V_18 = V_29 [ 0 ] . V_40 ;
V_86 = 1 ;
} else {
for ( V_18 = V_38 = 0 ; V_38 < V_30 ; V_38 ++ ) {
V_18 += V_29 [ V_38 ] . V_40 = V_44 [ V_38 ] . V_53 ;
V_29 [ V_38 ] . V_60 = F_14 ( V_44 [ V_38 ] . V_49 ) +
V_44 [ V_38 ] . V_51 ;
}
V_86 = V_30 ;
}
F_3 ( V_18 <= V_1 -> V_71 ) ;
V_2 = F_19 ( V_1 -> V_3 , & V_35 ,
(struct V_43 * ) V_29 , V_86 , V_18 , V_37 ) ;
if ( V_1 -> V_72 . V_25 != 0 ) {
for ( V_38 = 0 , V_69 = V_2 ; V_69 > 0 ; V_38 ++ , V_69 -= V_68 ) {
F_3 ( V_38 < V_30 ) ;
V_85 = F_14 ( V_44 [ V_38 ] . V_49 ) + V_44 [ V_38 ] . V_51 ;
V_68 = V_44 [ V_38 ] . V_53 ;
if ( V_68 > V_69 )
V_68 = V_69 ;
V_1 -> V_73 = F_20 ( V_1 -> V_73 ,
V_85 , V_68 ) ;
F_15 ( V_44 [ V_38 ] . V_49 ) ;
}
}
if ( V_74 != NULL ) {
F_21 ( V_74 ) ;
} else {
for ( V_38 = 0 ; V_38 < V_30 ; V_38 ++ )
F_15 ( V_44 [ V_38 ] . V_49 ) ;
}
return V_2 ;
}
void
F_7 ( T_2 * V_15 )
{
int V_38 ;
T_4 V_87 ;
void * V_85 ;
F_3 ( V_15 -> V_39 [ 0 ] . V_60 == ( void * ) & V_15 -> V_24 ) ;
F_3 ( V_15 -> V_88 != NULL ) ;
F_3 ( V_15 -> V_88 -> V_11 == & V_21 ) ;
V_15 -> V_24 . V_25 = 0 ;
V_87 = F_20 ( ~ 0 , ( void * ) V_15 -> V_39 [ 0 ] . V_60 ,
V_15 -> V_39 [ 0 ] . V_40 ) ;
if ( V_15 -> V_45 != NULL ) {
for ( V_38 = 0 ; V_38 < V_15 -> V_59 ; V_38 ++ ) {
V_85 = F_14 ( V_15 -> V_45 [ V_38 ] . V_49 ) +
V_15 -> V_45 [ V_38 ] . V_51 ;
V_87 = F_20 ( V_87 , V_85 , V_15 -> V_45 [ V_38 ] . V_53 ) ;
F_15 ( V_15 -> V_45 [ V_38 ] . V_49 ) ;
}
} else {
for ( V_38 = 1 ; V_38 < V_15 -> V_33 ; V_38 ++ )
V_87 = F_20 ( V_87 , V_15 -> V_39 [ V_38 ] . V_60 ,
V_15 -> V_39 [ V_38 ] . V_40 ) ;
}
if ( * V_19 . V_89 ) {
V_87 ++ ;
* V_19 . V_89 = 0 ;
}
V_15 -> V_24 . V_25 = V_87 ;
}
int
F_26 ( T_1 * V_1 , int * V_90 , int * V_91 , int * V_92 )
{
struct V_16 * V_17 = V_1 -> V_3 ;
int V_93 ;
int V_2 ;
V_2 = F_27 ( V_1 ) ;
if ( V_2 != 0 ) {
F_3 ( V_1 -> V_6 ) ;
* V_90 = * V_91 = * V_92 = 0 ;
return - V_94 ;
}
V_2 = F_28 ( V_17 , V_90 , V_91 ) ;
if ( V_2 == 0 ) {
V_93 = sizeof( * V_92 ) ;
V_2 = F_29 ( V_17 , V_62 , V_95 ,
( char * ) V_92 , & V_93 ) ;
}
F_30 ( V_1 ) ;
if ( V_2 == 0 )
* V_92 = ! * V_92 ;
else
* V_90 = * V_91 = * V_92 = 0 ;
return V_2 ;
}
int
F_31 ( struct V_16 * V_17 )
{
int V_2 ;
int V_96 ;
int V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
struct V_101 V_101 ;
V_17 -> V_9 -> V_102 = V_103 ;
V_101 . V_104 = 0 ;
V_101 . V_105 = 0 ;
V_2 = F_17 ( V_17 , V_106 , V_107 ,
( char * ) & V_101 , sizeof ( V_101 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_4 , V_2 ) ;
return V_2 ;
}
V_96 = - 1 ;
V_2 = F_17 ( V_17 , V_62 , V_108 ,
( char * ) & V_96 , sizeof ( V_96 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_5 , V_2 ) ;
return V_2 ;
}
if ( ! * V_19 . V_109 ) {
V_96 = 1 ;
V_2 = F_17 ( V_17 , V_62 , V_95 ,
( char * ) & V_96 , sizeof ( V_96 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_6 , V_2 ) ;
return V_2 ;
}
}
V_2 = F_32 ( V_17 ,
* V_19 . V_110 ,
* V_19 . V_111 ) ;
if ( V_2 != 0 ) {
F_4 ( L_7 ,
* V_19 . V_110 ,
* V_19 . V_111 , V_2 ) ;
return V_2 ;
}
V_97 = * V_19 . V_112 ;
V_99 = * V_19 . V_113 ;
V_98 = * V_19 . V_114 ;
V_100 = ( V_97 > 0 && V_99 > 0 && V_98 > 0 ) ;
V_96 = ( V_100 ? 1 : 0 ) ;
V_2 = F_17 ( V_17 , V_106 , V_115 ,
( char * ) & V_96 , sizeof ( V_96 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_8 , V_2 ) ;
return V_2 ;
}
if ( ! V_100 )
return 0 ;
V_2 = F_17 ( V_17 , V_62 , V_116 ,
( char * ) & V_97 , sizeof ( V_97 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_9 , V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_17 , V_62 , V_117 ,
( char * ) & V_98 , sizeof ( V_98 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_10 , V_2 ) ;
return V_2 ;
}
V_2 = F_17 ( V_17 , V_62 , V_118 ,
( char * ) & V_99 , sizeof ( V_99 ) ) ;
if ( V_2 != 0 ) {
F_4 ( L_11 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
void
F_33 ( T_1 * V_1 )
{
struct V_17 * V_9 ;
struct V_119 * V_120 ;
int V_121 ;
int V_122 = 1 ;
int V_2 ;
V_2 = F_27 ( V_1 ) ;
if ( V_2 != 0 )
return;
V_9 = V_1 -> V_3 -> V_9 ;
V_120 = F_34 ( V_9 ) ;
F_35 ( V_9 ) ;
V_121 = V_120 -> V_121 ;
V_120 -> V_121 = 1 ;
F_36 ( V_9 ) ;
V_2 = F_17 ( V_1 -> V_3 , V_62 , V_95 ,
( char * ) & V_122 , sizeof ( V_122 ) ) ;
F_3 ( V_2 == 0 ) ;
F_35 ( V_9 ) ;
V_120 -> V_121 = V_121 ;
F_36 ( V_9 ) ;
F_30 ( V_1 ) ;
}
static void
F_37 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
F_3 ( ! F_38 () ) ;
F_39 ( & V_123 . V_124 ) ;
V_1 = V_9 -> V_125 ;
if ( V_1 == NULL ) {
F_3 ( V_9 -> V_126 != & F_37 ) ;
V_9 -> V_126 ( V_9 ) ;
} else
F_40 ( V_1 ) ;
F_41 ( & V_123 . V_124 ) ;
}
static void
F_42 ( struct V_17 * V_9 )
{
T_1 * V_1 ;
int V_127 ;
int V_128 ;
F_3 ( ! F_38 () ) ;
F_39 ( & V_123 . V_124 ) ;
V_1 = V_9 -> V_125 ;
V_127 = F_43 ( V_9 ) ;
V_128 = F_44 ( V_9 ) ;
F_11 ( V_55 , L_12 ,
V_9 , V_127 , V_128 , V_1 ,
( V_1 == NULL ) ? L_13 : ( V_1 -> V_129 ?
L_14 : L_15 ) ,
( V_1 == NULL ) ? L_13 : ( V_1 -> V_130 ?
L_16 : L_17 ) ,
( V_1 == NULL ) ? L_13 : ( F_8 ( & V_1 -> V_41 ) ?
L_18 : L_19 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_9 -> V_131 != & F_42 ) ;
V_9 -> V_131 ( V_9 ) ;
F_41 ( & V_123 . V_124 ) ;
return;
}
if ( V_127 >= V_128 ) {
F_45 ( V_1 ) ;
F_46 ( V_132 , & V_9 -> V_133 -> V_134 ) ;
}
F_41 ( & V_123 . V_124 ) ;
}
void
F_47 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_1 -> V_135 = V_17 -> V_9 -> V_126 ;
V_1 -> V_136 = V_17 -> V_9 -> V_131 ;
}
void
F_48 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_125 = V_1 ;
V_17 -> V_9 -> V_126 = F_37 ;
V_17 -> V_9 -> V_131 = F_42 ;
return;
}
void
F_49 ( struct V_16 * V_17 , T_1 * V_1 )
{
V_17 -> V_9 -> V_126 = V_1 -> V_135 ;
V_17 -> V_9 -> V_131 = V_1 -> V_136 ;
V_17 -> V_9 -> V_125 = NULL ;
return ;
}
int
F_50 ( T_1 * V_1 )
{
int V_2 = 0 ;
T_5 * V_137 ;
V_137 = V_1 -> V_31 ;
F_51 ( & V_137 -> V_138 ) ;
if ( ! F_52 ( V_132 , & V_1 -> V_3 -> V_134 ) &&
! V_1 -> V_129 ) {
V_2 = - V_139 ;
}
F_53 ( & V_137 -> V_138 ) ;
return V_2 ;
}
