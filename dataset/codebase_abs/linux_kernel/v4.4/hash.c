static inline void
F_1 ( union V_1 * V_2 , int V_3 ) {}
static inline void
F_2 ( union V_1 * V_2 , int V_3 ) {}
static inline void
F_3 ( union V_1 * V_2 , int V_3 )
__acquires( &lock->spin
static inline void
F_4 ( union V_1 * V_2 , int V_3 )
__releases( &lock->spin
static inline void
F_5 ( union V_1 * V_2 , int V_3 )
__acquires( &lock->rw
static inline void
F_6 ( union V_1 * V_2 , int V_3 )
__releases( &lock->rw
static void
F_7 ( struct V_4 * V_5 )
{
if ( F_8 ( V_5 ) ) {
V_5 -> V_6 = & V_7 ;
} else if ( F_9 ( V_5 ) ) {
V_5 -> V_6 = & V_8 ;
F_10 ( & V_5 -> V_9 . V_10 ) ;
} else if ( F_11 ( V_5 ) ) {
F_12 ( & V_5 -> V_9 . V_11 ) ;
if ( F_13 ( V_5 ) )
V_5 -> V_6 = & V_12 ;
else if ( F_14 ( V_5 ) )
V_5 -> V_6 = & V_13 ;
else
F_15 () ;
} else {
if ( F_13 ( V_5 ) )
V_5 -> V_6 = & V_14 ;
else if ( F_14 ( V_5 ) )
V_5 -> V_6 = & V_15 ;
else
F_15 () ;
}
}
static int
F_16 ( struct V_4 * V_5 )
{
return sizeof( struct V_16 ) ;
}
static struct V_17 *
F_17 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_16 * V_20 ;
V_20 = (struct V_16 * ) & V_19 -> V_21 -> V_22 [ 0 ] ;
return & V_20 [ V_19 -> V_23 ] . V_24 ;
}
static int
F_18 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
F_19 ( V_26 , F_17 ( V_5 , V_19 ) ) ;
return - 1 ;
}
static int
F_20 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
F_21 ( V_26 ) ;
return - 1 ;
}
static int
F_22 ( struct V_4 * V_5 )
{
return sizeof( struct V_27 ) ;
}
static struct V_17 *
F_23 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_27 * V_20 ;
V_20 = (struct V_27 * ) & V_19 -> V_21 -> V_22 [ 0 ] ;
return & V_20 [ V_19 -> V_23 ] . V_28 ;
}
static int
F_24 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_27 * V_29 ;
V_29 = F_25 ( F_23 ( V_5 , V_19 ) ,
struct V_27 , V_28 ) ;
F_19 ( V_26 , & V_29 -> V_28 ) ;
return ++ V_29 -> V_30 ;
}
static int
F_26 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_27 * V_29 ;
V_29 = F_25 ( F_23 ( V_5 , V_19 ) ,
struct V_27 , V_28 ) ;
F_21 ( V_26 ) ;
return -- V_29 -> V_30 ;
}
static int
F_27 ( struct V_4 * V_5 )
{
return sizeof( struct V_31 ) ;
}
static struct V_17 *
F_28 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_31 * V_20 ;
V_20 = (struct V_31 * ) & V_19 -> V_21 -> V_22 [ 0 ] ;
return & V_20 [ V_19 -> V_23 ] . V_32 ;
}
static int
F_29 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_31 * V_33 ;
V_33 = F_25 ( F_28 ( V_5 , V_19 ) ,
struct V_31 , V_32 ) ;
if ( V_33 -> V_34 != NULL )
F_30 ( V_26 , V_33 -> V_34 ) ;
else
F_19 ( V_26 , & V_33 -> V_32 ) ;
V_33 -> V_34 = V_26 ;
return - 1 ;
}
static int
F_31 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_35 )
{
struct V_31 * V_33 ;
V_33 = F_25 ( F_28 ( V_5 , V_19 ) ,
struct V_31 , V_32 ) ;
if ( V_35 -> V_36 == NULL ) {
V_33 -> V_34 = ( V_35 -> V_37 == & V_33 -> V_32 . V_38 ) ? NULL :
F_25 ( V_35 -> V_37 , struct V_25 , V_36 ) ;
}
F_21 ( V_35 ) ;
return - 1 ;
}
static int
F_32 ( struct V_4 * V_5 )
{
return sizeof( struct V_39 ) ;
}
static struct V_17 *
F_33 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_39 * V_20 ;
V_20 = (struct V_39 * ) & V_19 -> V_21 -> V_22 [ 0 ] ;
return & V_20 [ V_19 -> V_23 ] . V_40 ;
}
static int
F_34 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_39 * V_33 ;
V_33 = F_25 ( F_33 ( V_5 , V_19 ) ,
struct V_39 , V_40 ) ;
if ( V_33 -> V_41 != NULL )
F_30 ( V_26 , V_33 -> V_41 ) ;
else
F_19 ( V_26 , & V_33 -> V_40 ) ;
V_33 -> V_41 = V_26 ;
return ++ V_33 -> V_42 ;
}
static int
F_35 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_35 )
{
struct V_39 * V_33 ;
V_33 = F_25 ( F_33 ( V_5 , V_19 ) ,
struct V_39 , V_40 ) ;
if ( V_35 -> V_36 == NULL ) {
V_33 -> V_41 = ( V_35 -> V_37 == & V_33 -> V_40 . V_38 ) ? NULL :
F_25 ( V_35 -> V_37 , struct V_25 , V_36 ) ;
}
F_21 ( V_35 ) ;
return -- V_33 -> V_42 ;
}
static void
F_36 ( struct V_4 * V_5 )
{
if ( F_37 ( V_5 ) ) {
V_5 -> V_43 = F_38 ( V_5 ) ?
& V_44 : & V_45 ;
} else {
V_5 -> V_43 = F_38 ( V_5 ) ?
& V_46 : & V_47 ;
}
}
static void
F_39 ( struct V_4 * V_5 , struct V_48 * * V_49 ,
unsigned int V_50 , const void * V_51 , struct V_18 * V_19 )
{
unsigned int V_52 = F_40 ( V_5 , V_51 , ( 1U << V_50 ) - 1 ) ;
F_41 ( V_50 == V_5 -> V_53 || V_50 == V_5 -> V_54 ) ;
V_19 -> V_21 = V_49 [ V_52 & ( ( 1U << ( V_50 - V_5 -> V_55 ) ) - 1 ) ] ;
V_19 -> V_23 = V_52 >> ( V_50 - V_5 -> V_55 ) ;
}
void
F_42 ( struct V_4 * V_5 , const void * V_51 , struct V_18 * V_19 )
{
if ( F_43 ( V_5 -> V_56 == NULL ) ) {
F_39 ( V_5 , V_5 -> V_57 ,
V_5 -> V_53 , V_51 , V_19 ) ;
} else {
F_41 ( V_5 -> V_54 != 0 ) ;
F_39 ( V_5 , V_5 -> V_56 ,
V_5 -> V_54 , V_51 , V_19 ) ;
}
}
static inline void
F_44 ( struct V_4 * V_5 , struct V_18 * V_19 , int V_58 )
{
if ( F_43 ( V_58 <= V_19 -> V_21 -> V_59 ) )
return;
V_19 -> V_21 -> V_59 = V_58 ;
# if V_60 >= V_61
if ( F_43 ( V_62 == 0 ||
F_45 ( V_62 , V_5 -> V_63 ) >= V_58 ) )
return;
F_46 ( & V_5 -> V_64 ) ;
V_5 -> V_63 = V_58 ;
V_5 -> V_65 = V_19 -> V_21 -> V_66 ;
V_5 -> V_67 = V_19 -> V_23 ;
V_5 -> V_68 = V_5 -> V_53 ;
F_47 ( & V_5 -> V_64 ) ;
F_48 ( V_69 , & V_5 -> V_70 ) ;
# endif
}
void
F_49 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
int V_71 ;
V_71 = V_5 -> V_43 -> V_72 ( V_5 , V_19 , V_26 ) ;
F_44 ( V_5 , V_19 , V_71 ) ;
V_19 -> V_21 -> V_73 ++ ;
if ( F_50 ( V_19 -> V_21 -> V_73 == 0 ) )
V_19 -> V_21 -> V_73 ++ ;
V_19 -> V_21 -> V_74 ++ ;
if ( F_51 ( V_5 ) )
F_52 ( & V_5 -> V_75 ) ;
if ( ! F_53 ( V_5 ) )
F_54 ( V_5 , V_26 ) ;
}
void
F_55 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 )
{
V_5 -> V_43 -> V_76 ( V_5 , V_19 , V_26 ) ;
F_41 ( V_19 -> V_21 -> V_74 > 0 ) ;
V_19 -> V_21 -> V_74 -- ;
V_19 -> V_21 -> V_73 ++ ;
if ( F_50 ( V_19 -> V_21 -> V_73 == 0 ) )
V_19 -> V_21 -> V_73 ++ ;
if ( F_51 ( V_5 ) ) {
F_41 ( F_56 ( & V_5 -> V_75 ) > 0 ) ;
F_57 ( & V_5 -> V_75 ) ;
}
if ( ! F_53 ( V_5 ) )
F_58 ( V_5 , V_26 ) ;
}
void
F_59 ( struct V_4 * V_5 , struct V_18 * V_77 ,
struct V_18 * V_78 , struct V_25 * V_26 )
{
struct V_48 * V_79 = V_77 -> V_21 ;
struct V_48 * V_80 = V_78 -> V_21 ;
int V_71 ;
if ( F_60 ( V_77 , V_78 ) == 0 )
return;
V_5 -> V_43 -> V_76 ( V_5 , V_77 , V_26 ) ;
V_71 = V_5 -> V_43 -> V_72 ( V_5 , V_78 , V_26 ) ;
F_44 ( V_5 , V_78 , V_71 ) ;
F_41 ( V_79 -> V_74 > 0 ) ;
V_79 -> V_74 -- ;
V_79 -> V_73 ++ ;
if ( F_50 ( V_79 -> V_73 == 0 ) )
V_79 -> V_73 ++ ;
V_80 -> V_74 ++ ;
V_80 -> V_73 ++ ;
if ( F_50 ( V_80 -> V_73 == 0 ) )
V_80 -> V_73 ++ ;
}
static struct V_25 *
F_61 ( struct V_4 * V_5 , struct V_18 * V_19 ,
const void * V_51 , struct V_25 * V_26 ,
enum V_81 V_82 )
{
struct V_17 * V_83 = F_62 ( V_5 , V_19 ) ;
struct V_25 * V_84 ;
struct V_25 * V_85 ;
int V_86 = ( V_82 & V_87 ) != 0 ;
V_85 = V_86 ? NULL : V_26 ;
F_63 (ehnode, hhead) {
if ( ! F_64 ( V_5 , V_51 , V_84 ) )
continue;
if ( V_85 != NULL && V_85 != V_84 )
continue;
if ( ( V_82 & V_88 ) != 0 ) {
F_55 ( V_5 , V_19 , V_84 ) ;
return V_84 ;
}
if ( ( V_82 & V_89 ) != 0 )
F_54 ( V_5 , V_84 ) ;
return V_84 ;
}
if ( ! V_86 )
return NULL ;
F_41 ( V_26 != NULL ) ;
F_49 ( V_5 , V_19 , V_26 ) ;
return V_26 ;
}
struct V_25 *
F_65 ( struct V_4 * V_5 , struct V_18 * V_19 , const void * V_51 )
{
return F_61 ( V_5 , V_19 , V_51 , NULL ,
V_90 ) ;
}
struct V_25 *
F_66 ( struct V_4 * V_5 , struct V_18 * V_19 , const void * V_51 )
{
return F_61 ( V_5 , V_19 , V_51 , NULL ,
V_91 ) ;
}
struct V_25 *
F_67 ( struct V_4 * V_5 , struct V_18 * V_19 ,
const void * V_51 , struct V_25 * V_26 ,
int V_92 )
{
return F_61 ( V_5 , V_19 , V_51 , V_26 ,
( ! V_92 * V_89 ) |
V_93 ) ;
}
struct V_25 *
F_68 ( struct V_4 * V_5 , struct V_18 * V_19 ,
const void * V_51 , struct V_25 * V_26 )
{
return F_61 ( V_5 , V_19 , V_51 , V_26 ,
V_94 ) ;
}
static void
F_69 ( struct V_4 * V_5 , struct V_18 * V_95 ,
unsigned V_96 , int V_97 )
{
struct V_48 * V_98 = NULL ;
int V_99 ;
F_70 (bds, n, i) {
if ( V_98 == V_95 [ V_99 ] . V_21 )
continue;
F_41 ( V_98 == NULL ||
V_98 -> V_66 < V_95 [ V_99 ] . V_21 -> V_66 ) ;
F_71 ( V_5 , & V_95 [ V_99 ] , V_97 ) ;
V_98 = V_95 [ V_99 ] . V_21 ;
}
}
static void
F_72 ( struct V_4 * V_5 , struct V_18 * V_95 ,
unsigned V_96 , int V_97 )
{
struct V_48 * V_98 = NULL ;
int V_99 ;
F_70 (bds, n, i) {
if ( V_98 != V_95 [ V_99 ] . V_21 ) {
F_73 ( V_5 , & V_95 [ V_99 ] , V_97 ) ;
V_98 = V_95 [ V_99 ] . V_21 ;
}
}
}
static struct V_25 *
F_74 ( struct V_4 * V_5 , struct V_18 * V_95 ,
unsigned V_96 , const void * V_51 )
{
struct V_25 * V_84 ;
unsigned V_99 ;
F_70 (bds, n, i) {
V_84 = F_61 ( V_5 , & V_95 [ V_99 ] , V_51 , NULL ,
V_90 ) ;
if ( V_84 != NULL )
return V_84 ;
}
return NULL ;
}
static struct V_25 *
F_75 ( struct V_4 * V_5 ,
struct V_18 * V_95 , unsigned V_96 , const void * V_51 ,
struct V_25 * V_26 , int V_92 )
{
struct V_25 * V_84 ;
int V_82 ;
unsigned V_99 ;
F_41 ( V_26 != NULL ) ;
V_82 = ( ! V_92 * V_89 ) | V_91 ;
F_70 (bds, n, i) {
V_84 = F_61 ( V_5 , & V_95 [ V_99 ] , V_51 ,
NULL , V_82 ) ;
if ( V_84 != NULL )
return V_84 ;
}
if ( V_99 == 1 ) {
F_49 ( V_5 , & V_95 [ 0 ] , V_26 ) ;
} else {
struct V_18 V_100 ;
F_42 ( V_5 , V_51 , & V_100 ) ;
F_49 ( V_5 , & V_100 , V_26 ) ;
}
return V_26 ;
}
static struct V_25 *
F_76 ( struct V_4 * V_5 , struct V_18 * V_95 ,
unsigned V_96 , const void * V_51 ,
struct V_25 * V_26 )
{
struct V_25 * V_84 ;
unsigned V_99 ;
F_70 (bds, n, i) {
V_84 = F_61 ( V_5 , & V_95 [ V_99 ] , V_51 , V_26 ,
V_94 ) ;
if ( V_84 != NULL )
return V_84 ;
}
return NULL ;
}
static void
F_77 ( struct V_18 * V_101 , struct V_18 * V_102 )
{
int V_71 ;
if ( V_102 -> V_21 == NULL )
return;
if ( V_101 -> V_21 == NULL ) {
* V_101 = * V_102 ;
V_102 -> V_21 = NULL ;
return;
}
V_71 = F_60 ( V_101 , V_102 ) ;
if ( V_71 == 0 ) {
V_102 -> V_21 = NULL ;
} else if ( V_71 > 0 ) {
struct V_18 V_103 ;
V_103 = * V_102 ;
* V_102 = * V_101 ;
* V_101 = V_103 ;
}
}
void
F_78 ( struct V_4 * V_5 , const void * V_51 , struct V_18 * V_95 )
{
F_39 ( V_5 , V_5 -> V_57 ,
V_5 -> V_53 , V_51 , & V_95 [ 0 ] ) ;
if ( F_43 ( V_5 -> V_56 == NULL ) ) {
V_95 [ 1 ] . V_21 = NULL ;
return;
}
F_41 ( V_5 -> V_54 != 0 ) ;
F_39 ( V_5 , V_5 -> V_56 ,
V_5 -> V_54 , V_51 , & V_95 [ 1 ] ) ;
F_77 ( & V_95 [ 0 ] , & V_95 [ 1 ] ) ;
}
void
F_79 ( struct V_4 * V_5 , struct V_18 * V_95 , int V_97 )
{
F_69 ( V_5 , V_95 , 2 , V_97 ) ;
}
void
F_80 ( struct V_4 * V_5 , struct V_18 * V_95 , int V_97 )
{
F_72 ( V_5 , V_95 , 2 , V_97 ) ;
}
struct V_25 *
F_81 ( struct V_4 * V_5 , struct V_18 * V_95 ,
const void * V_51 )
{
return F_74 ( V_5 , V_95 , 2 , V_51 ) ;
}
struct V_25 *
F_82 ( struct V_4 * V_5 , struct V_18 * V_95 ,
const void * V_51 , struct V_25 * V_26 ,
int V_92 )
{
return F_75 ( V_5 , V_95 , 2 , V_51 ,
V_26 , V_92 ) ;
}
struct V_25 *
F_83 ( struct V_4 * V_5 , struct V_18 * V_95 ,
const void * V_51 , struct V_25 * V_26 )
{
return F_76 ( V_5 , V_95 , 2 , V_51 , V_26 ) ;
}
static void
F_84 ( struct V_48 * * V_104 ,
int V_105 , int V_106 , int V_107 )
{
int V_99 ;
for ( V_99 = V_106 ; V_99 < V_107 ; V_99 ++ ) {
if ( V_104 [ V_99 ] != NULL )
F_85 ( V_104 [ V_99 ] , V_105 ) ;
}
F_85 ( V_104 , sizeof( V_104 [ 0 ] ) * V_107 ) ;
}
static struct V_48 * *
F_86 ( struct V_4 * V_5 , struct V_48 * * V_108 ,
unsigned int V_109 , unsigned int V_110 )
{
struct V_48 * * V_111 ;
int V_99 ;
F_41 ( V_109 == 0 || V_108 != NULL ) ;
if ( V_108 != NULL && V_109 == V_110 )
return V_108 ;
F_87 ( V_111 , sizeof( V_111 [ 0 ] ) * V_110 ) ;
if ( V_111 == NULL )
return NULL ;
if ( V_108 != NULL ) {
memcpy ( V_111 , V_108 ,
F_88 ( V_109 , V_110 ) * sizeof( * V_108 ) ) ;
}
for ( V_99 = V_109 ; V_99 < V_110 ; V_99 ++ ) {
struct V_17 * V_83 ;
struct V_18 V_19 ;
F_87 ( V_111 [ V_99 ] , F_89 ( V_5 ) ) ;
if ( V_111 [ V_99 ] == NULL ) {
F_84 ( V_111 , F_89 ( V_5 ) ,
V_109 , V_110 ) ;
return NULL ;
}
V_111 [ V_99 ] -> V_66 = V_99 ;
V_111 [ V_99 ] -> V_73 = 1 ;
V_111 [ V_99 ] -> V_59 = - 1 ;
V_19 . V_21 = V_111 [ V_99 ] ;
F_90 (hs, &bd, hhead)
F_91 ( V_83 ) ;
if ( F_8 ( V_5 ) ||
F_9 ( V_5 ) )
continue;
if ( F_13 ( V_5 ) )
F_12 ( & V_111 [ V_99 ] -> V_112 . V_11 ) ;
else if ( F_14 ( V_5 ) )
F_10 ( & V_111 [ V_99 ] -> V_112 . V_10 ) ;
else
F_15 () ;
}
return V_111 ;
}
static int F_92 ( T_1 * V_113 )
{
struct V_4 * V_5 = F_25 ( V_113 , struct V_4 , V_70 ) ;
int V_114 ;
int V_115 ;
int V_116 ;
int V_50 ;
F_46 ( & V_5 -> V_64 ) ;
V_114 = V_5 -> V_63 ;
V_115 = V_5 -> V_65 ;
V_116 = V_5 -> V_67 ;
V_50 = V_5 -> V_68 ;
F_47 ( & V_5 -> V_64 ) ;
F_93 ( L_1 ,
V_5 -> V_117 , V_50 , V_114 , V_115 , V_116 ) ;
F_46 ( & V_5 -> V_64 ) ;
V_5 -> V_68 = 0 ;
F_47 ( & V_5 -> V_64 ) ;
return 0 ;
}
static void F_94 ( struct V_4 * V_5 )
{
F_10 ( & V_5 -> V_64 ) ;
F_95 ( & V_5 -> V_70 , V_5 , F_92 ) ;
}
static void F_96 ( struct V_4 * V_5 )
{
if ( F_97 ( V_69 , & V_5 -> V_70 ) )
return;
F_46 ( & V_5 -> V_64 ) ;
while ( V_5 -> V_68 != 0 ) {
F_47 ( & V_5 -> V_64 ) ;
F_98 () ;
F_46 ( & V_5 -> V_64 ) ;
}
F_47 ( & V_5 -> V_64 ) ;
}
static inline void F_94 ( struct V_4 * V_5 ) {}
static inline void F_96 ( struct V_4 * V_5 ) {}
struct V_4 *
F_99 ( char * V_118 , unsigned V_119 , unsigned V_120 ,
unsigned V_121 , unsigned V_122 ,
unsigned V_123 , unsigned V_124 ,
struct V_125 * V_126 , unsigned V_127 )
{
struct V_4 * V_5 ;
int V_128 ;
F_100 ( V_129 < 15 ) ;
F_41 ( V_118 != NULL ) ;
F_41 ( V_126 != NULL ) ;
F_41 ( V_126 -> V_130 ) ;
F_41 ( V_126 -> V_131 ) ;
F_41 ( V_126 -> V_132 ) ;
F_41 ( V_126 -> V_133 ) ;
F_41 ( V_126 -> V_134 != NULL ) ;
F_41 ( V_126 -> V_135 != NULL ) ;
if ( ( V_127 & V_136 ) != 0 )
V_127 |= V_137 ;
F_41 ( V_119 > 0 ) ;
F_41 ( V_119 >= V_121 ) ;
F_41 ( V_120 >= V_119 && V_120 < 31 ) ;
F_41 ( F_101 ( ( V_127 & V_136 ) == 0 , V_119 == V_120 ) ) ;
F_41 ( F_101 ( ( V_127 & V_136 ) != 0 ,
( V_127 & V_138 ) == 0 ) ) ;
F_41 ( F_101 ( ( V_127 & V_139 ) != 0 ,
V_126 -> V_140 != NULL ) ) ;
V_128 = ( V_127 & V_141 ) == 0 ?
V_142 : V_143 ;
F_87 ( V_5 , F_102 ( struct V_4 , V_117 [ V_128 ] ) ) ;
if ( V_5 == NULL )
return NULL ;
strncpy ( V_5 -> V_117 , V_118 , V_128 ) ;
V_5 -> V_117 [ V_128 - 1 ] = '\0' ;
V_5 -> V_144 = V_127 ;
F_103 ( & V_5 -> V_145 , 1 ) ;
F_103 ( & V_5 -> V_75 , 0 ) ;
F_7 ( V_5 ) ;
F_36 ( V_5 ) ;
V_5 -> V_53 = ( V_146 ) V_119 ;
V_5 -> V_147 = ( V_146 ) V_119 ;
V_5 -> V_148 = ( V_146 ) V_120 ;
V_5 -> V_55 = ( V_146 ) V_121 ;
V_5 -> V_149 = V_126 ;
V_5 -> V_150 = V_122 ;
V_5 -> V_54 = 0 ;
F_95 ( & V_5 -> V_151 , V_5 , V_152 ) ;
F_94 ( V_5 ) ;
if ( F_11 ( V_5 ) )
F_104 ( V_5 , V_123 , V_124 ) ;
V_5 -> V_57 = F_86 ( V_5 , NULL , 0 ,
F_105 ( V_5 ) ) ;
if ( V_5 -> V_57 != NULL )
return V_5 ;
F_85 ( V_5 , F_102 ( struct V_4 , V_117 [ V_128 ] ) ) ;
return NULL ;
}
static void
F_106 ( struct V_4 * V_5 )
{
struct V_25 * V_26 ;
struct V_25 * V_153 ;
struct V_18 V_19 ;
int V_99 ;
F_41 ( V_5 != NULL ) ;
F_41 ( ! F_107 ( V_5 ) &&
! F_108 ( V_5 ) ) ;
V_5 -> V_154 = 1 ;
if ( F_11 ( V_5 ) )
F_109 ( V_5 ) ;
F_96 ( V_5 ) ;
F_41 ( V_5 -> V_57 != NULL &&
V_5 -> V_56 == NULL ) ;
F_110 (hs, &bd, i) {
struct V_17 * V_83 ;
F_41 ( V_19 . V_21 != NULL ) ;
F_71 ( V_5 , & V_19 , 1 ) ;
F_90 (hs, &bd, hhead) {
F_111 (hnode, pos, hhead) {
F_112 ( ! F_113 ( V_5 ) ,
L_2 ,
V_5 -> V_117 , V_19 . V_21 -> V_66 ,
V_19 . V_23 , V_19 . V_21 -> V_74 ) ;
F_55 ( V_5 , & V_19 , V_26 ) ;
F_114 ( V_5 , V_26 ) ;
}
}
F_41 ( V_19 . V_21 -> V_74 == 0 ) ;
F_73 ( V_5 , & V_19 , 1 ) ;
F_98 () ;
}
F_41 ( F_56 ( & V_5 -> V_75 ) == 0 ) ;
F_84 ( V_5 -> V_57 , F_89 ( V_5 ) ,
0 , F_105 ( V_5 ) ) ;
V_99 = F_115 ( V_5 ) ?
V_143 : V_142 ;
F_85 ( V_5 , F_102 ( struct V_4 , V_117 [ V_99 ] ) ) ;
}
struct V_4 * F_116 ( struct V_4 * V_5 )
{
if ( F_117 ( & V_5 -> V_145 ) )
return V_5 ;
return NULL ;
}
void F_118 ( struct V_4 * V_5 )
{
if ( F_119 ( & V_5 -> V_145 ) )
F_106 ( V_5 ) ;
}
static inline int
F_120 ( struct V_4 * V_5 )
{
if ( F_8 ( V_5 ) ||
! F_11 ( V_5 ) )
return - V_155 ;
if ( F_50 ( F_107 ( V_5 ) ) )
return - V_156 ;
if ( F_50 ( F_121 ( V_5 ) ) )
return - V_157 ;
if ( F_50 ( F_108 ( V_5 ) ) )
return - V_158 ;
if ( ( V_5 -> V_53 < V_5 -> V_148 ) &&
( F_122 ( V_5 ) > V_5 -> V_159 ) )
return V_5 -> V_53 + 1 ;
if ( ! F_123 ( V_5 ) )
return 0 ;
if ( ( V_5 -> V_53 > V_5 -> V_147 ) &&
( F_122 ( V_5 ) < V_5 -> V_160 ) )
return V_5 -> V_53 - 1 ;
return 0 ;
}
static inline int
F_124 ( struct V_4 * V_5 )
{
return ! F_125 ( V_5 ) &&
F_56 ( & V_5 -> V_75 ) < V_161 ;
}
void
F_126 ( struct V_4 * V_5 , const void * V_51 , struct V_25 * V_26 )
{
struct V_18 V_19 ;
int V_50 ;
F_41 ( F_127 ( V_26 ) ) ;
V_1 ( V_5 , 0 ) ;
F_128 ( V_5 , V_51 , & V_19 , 1 ) ;
F_129 ( V_5 , V_51 , V_26 ) ;
F_49 ( V_5 , & V_19 , V_26 ) ;
F_73 ( V_5 , & V_19 , 1 ) ;
V_50 = F_120 ( V_5 ) ;
F_130 ( V_5 , 0 ) ;
if ( V_50 > 0 )
F_131 ( V_5 , F_124 ( V_5 ) ) ;
}
static struct V_25 *
F_132 ( struct V_4 * V_5 , const void * V_51 ,
struct V_25 * V_26 , int V_92 )
{
struct V_25 * V_84 ;
struct V_18 V_95 [ 2 ] ;
int V_50 = 0 ;
F_41 ( F_127 ( V_26 ) ) ;
V_1 ( V_5 , 0 ) ;
F_133 ( V_5 , V_51 , V_95 , 1 ) ;
F_129 ( V_5 , V_51 , V_26 ) ;
V_84 = F_82 ( V_5 , V_95 , V_51 ,
V_26 , V_92 ) ;
F_80 ( V_5 , V_95 , 1 ) ;
if ( V_84 == V_26 )
V_50 = F_120 ( V_5 ) ;
F_130 ( V_5 , 0 ) ;
if ( V_50 > 0 )
F_131 ( V_5 , F_124 ( V_5 ) ) ;
return V_84 ;
}
int
F_134 ( struct V_4 * V_5 , const void * V_51 , struct V_25 * V_26 )
{
return F_132 ( V_5 , V_51 , V_26 , 1 ) != V_26 ?
- V_157 : 0 ;
}
void *
F_135 ( struct V_4 * V_5 , const void * V_51 ,
struct V_25 * V_26 )
{
V_26 = F_132 ( V_5 , V_51 , V_26 , 0 ) ;
return F_136 ( V_5 , V_26 ) ;
}
void *
F_137 ( struct V_4 * V_5 , const void * V_51 , struct V_25 * V_26 )
{
void * V_162 = NULL ;
int V_50 = 0 ;
struct V_18 V_95 [ 2 ] ;
V_1 ( V_5 , 0 ) ;
F_133 ( V_5 , V_51 , V_95 , 1 ) ;
if ( V_26 == NULL || ! F_127 ( V_26 ) ) {
if ( V_95 [ 1 ] . V_21 == NULL && V_26 != NULL ) {
F_55 ( V_5 , & V_95 [ 0 ] , V_26 ) ;
} else {
V_26 = F_83 ( V_5 , V_95 ,
V_51 , V_26 ) ;
}
}
if ( V_26 != NULL ) {
V_162 = F_136 ( V_5 , V_26 ) ;
V_50 = F_120 ( V_5 ) ;
}
F_80 ( V_5 , V_95 , 1 ) ;
F_130 ( V_5 , 0 ) ;
if ( V_50 > 0 )
F_131 ( V_5 , F_124 ( V_5 ) ) ;
return V_162 ;
}
void *
F_138 ( struct V_4 * V_5 , const void * V_51 )
{
return F_137 ( V_5 , V_51 , NULL ) ;
}
void *
F_139 ( struct V_4 * V_5 , const void * V_51 )
{
void * V_162 = NULL ;
struct V_25 * V_26 ;
struct V_18 V_95 [ 2 ] ;
V_1 ( V_5 , 0 ) ;
F_133 ( V_5 , V_51 , V_95 , 0 ) ;
V_26 = F_81 ( V_5 , V_95 , V_51 ) ;
if ( V_26 != NULL )
V_162 = F_136 ( V_5 , V_26 ) ;
F_80 ( V_5 , V_95 , 0 ) ;
F_130 ( V_5 , 0 ) ;
return V_162 ;
}
static void
F_140 ( struct V_4 * V_5 ) {
F_41 ( ! F_107 ( V_5 ) ) ;
if ( ! F_11 ( V_5 ) )
return;
V_5 -> V_163 = 1 ;
V_1 ( V_5 , 1 ) ;
V_5 -> V_164 ++ ;
if ( F_121 ( V_5 ) )
F_141 ( V_5 ) ;
F_130 ( V_5 , 1 ) ;
}
static void
F_142 ( struct V_4 * V_5 ) {
int V_165 ;
int V_50 ;
if ( ! F_11 ( V_5 ) )
return;
V_1 ( V_5 , 1 ) ;
V_165 = -- V_5 -> V_164 ;
V_50 = F_120 ( V_5 ) ;
F_130 ( V_5 , 1 ) ;
if ( V_165 == 0 )
V_5 -> V_163 = 0 ;
if ( V_50 > 0 ) {
F_131 ( V_5 , F_56 ( & V_5 -> V_75 ) <
V_161 ) ;
}
}
static T_2
F_143 ( struct V_4 * V_5 , T_3 V_166 ,
void * V_167 , int V_168 ) {
struct V_25 * V_26 ;
struct V_25 * V_153 ;
struct V_18 V_19 ;
T_2 V_169 = 0 ;
int V_97 = ! ! V_168 ;
int V_170 = 0 ;
int V_99 ;
F_140 ( V_5 ) ;
V_1 ( V_5 , 0 ) ;
F_41 ( ! F_121 ( V_5 ) ) ;
F_110 (hs, &bd, i) {
struct V_17 * V_83 ;
F_71 ( V_5 , & V_19 , V_97 ) ;
if ( V_166 == NULL ) {
V_169 += V_19 . V_21 -> V_74 ;
F_73 ( V_5 , & V_19 , V_97 ) ;
continue;
}
F_90 (hs, &bd, hhead) {
F_111 (hnode, pos, hhead) {
F_144 ( V_5 , & V_19 , V_26 ) ;
V_169 ++ ;
V_170 ++ ;
if ( V_166 ( V_5 , & V_19 , V_26 , V_167 ) ) {
F_73 ( V_5 , & V_19 , V_97 ) ;
goto V_171;
}
}
}
F_73 ( V_5 , & V_19 , V_97 ) ;
if ( V_170 < V_161 )
continue;
V_170 = 0 ;
F_130 ( V_5 , 0 ) ;
F_98 () ;
V_1 ( V_5 , 0 ) ;
}
V_171:
F_130 ( V_5 , 0 ) ;
F_142 ( V_5 ) ;
return V_169 ;
}
static int
F_145 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 , void * V_167 )
{
struct V_172 * V_173 = V_167 ;
if ( V_173 -> V_166 ( F_136 ( V_5 , V_26 ) , V_173 -> V_174 ) )
F_55 ( V_5 , V_19 , V_26 ) ;
return 0 ;
}
void
F_146 ( struct V_4 * V_5 , T_4 V_166 , void * V_167 )
{
struct V_172 V_174 = {
. V_166 = V_166 ,
. V_174 = V_167 ,
} ;
F_143 ( V_5 , F_145 , & V_174 , 1 ) ;
}
void
F_147 ( struct V_4 * V_5 ,
T_3 V_166 , void * V_167 )
{
F_143 ( V_5 , V_166 , V_167 , 0 ) ;
}
void
F_148 ( struct V_4 * V_5 ,
T_3 V_166 , void * V_167 ) {
F_143 ( V_5 , V_166 , V_167 , 1 ) ;
}
static int
F_149 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 , void * V_167 )
{
* ( int * ) V_167 = 0 ;
return 1 ;
}
int
F_150 ( struct V_4 * V_5 )
{
int V_175 = 1 ;
F_143 ( V_5 , F_149 , & V_175 , 0 ) ;
return V_175 ;
}
T_2
F_151 ( struct V_4 * V_5 )
{
return F_51 ( V_5 ) ?
F_56 ( & V_5 -> V_75 ) :
F_143 ( V_5 , NULL , NULL , 0 ) ;
}
static int
F_152 ( struct V_4 * V_5 , T_3 V_166 ,
void * V_167 ) {
struct V_25 * V_26 ;
struct V_25 * V_103 ;
struct V_18 V_19 ;
T_5 V_176 ;
int V_169 = 0 ;
int V_177 ;
int V_71 ;
int V_99 ;
V_177 = F_153 ( V_5 ) ||
! F_53 ( V_5 ) ||
V_5 -> V_149 -> V_135 == NULL ;
V_1 ( V_5 , 0 ) ;
F_41 ( ! F_121 ( V_5 ) ) ;
F_110 (hs, &bd, i) {
struct V_17 * V_83 ;
F_71 ( V_5 , & V_19 , 0 ) ;
V_176 = F_154 ( & V_19 ) ;
F_90 (hs, &bd, hhead) {
for ( V_26 = V_83 -> V_38 ; V_26 != NULL ; ) {
F_144 ( V_5 , & V_19 , V_26 ) ;
F_54 ( V_5 , V_26 ) ;
F_73 ( V_5 , & V_19 , 0 ) ;
F_130 ( V_5 , 0 ) ;
V_71 = V_166 ( V_5 , & V_19 , V_26 , V_167 ) ;
if ( V_177 )
F_155 ( V_5 , V_26 ) ;
F_98 () ;
V_169 ++ ;
V_1 ( V_5 , 0 ) ;
F_71 ( V_5 , & V_19 , 0 ) ;
if ( ! V_177 ) {
V_103 = V_26 -> V_36 ;
F_58 ( V_5 , V_26 ) ;
V_26 = V_103 ;
} else {
if ( V_176 !=
F_154 ( & V_19 ) )
break;
V_26 = V_26 -> V_36 ;
}
if ( V_71 )
break;
}
if ( V_71 )
break;
}
F_73 ( V_5 , & V_19 , 0 ) ;
if ( V_71 )
break;
}
F_130 ( V_5 , 0 ) ;
return V_169 ;
}
int
F_156 ( struct V_4 * V_5 ,
T_3 V_166 , void * V_167 ) {
if ( F_8 ( V_5 ) ||
F_153 ( V_5 ) ||
! F_53 ( V_5 ) )
return - V_155 ;
if ( V_5 -> V_149 -> V_134 == NULL ||
( V_5 -> V_149 -> V_178 == NULL &&
V_5 -> V_149 -> V_135 == NULL ) )
return - V_155 ;
F_140 ( V_5 ) ;
F_152 ( V_5 , V_166 , V_167 ) ;
F_142 ( V_5 ) ;
return 0 ;
}
int
F_157 ( struct V_4 * V_5 ,
T_3 V_166 , void * V_167 ) {
unsigned V_99 = 0 ;
if ( F_8 ( V_5 ) )
return - V_155 ;
if ( V_5 -> V_149 -> V_134 == NULL ||
( V_5 -> V_149 -> V_178 == NULL &&
V_5 -> V_149 -> V_135 == NULL ) )
return - V_155 ;
F_140 ( V_5 ) ;
while ( F_152 ( V_5 , V_166 , V_167 ) ) {
F_158 ( V_179 , L_3 ,
V_5 -> V_117 , V_99 ++ ) ;
}
F_142 ( V_5 ) ;
return 0 ;
}
void
F_159 ( struct V_4 * V_5 , unsigned V_180 ,
T_3 V_166 , void * V_167 )
{
struct V_17 * V_83 ;
struct V_25 * V_26 ;
struct V_18 V_19 ;
F_140 ( V_5 ) ;
V_1 ( V_5 , 0 ) ;
if ( V_180 >= F_160 ( V_5 ) )
goto V_171;
F_161 ( V_5 , V_180 , & V_19 ) ;
F_71 ( V_5 , & V_19 , 0 ) ;
V_83 = F_62 ( V_5 , & V_19 ) ;
F_63 (hnode, hhead) {
if ( V_166 ( V_5 , & V_19 , V_26 , V_167 ) )
break;
}
F_73 ( V_5 , & V_19 , 0 ) ;
V_171:
F_130 ( V_5 , 0 ) ;
F_142 ( V_5 ) ;
}
void
F_162 ( struct V_4 * V_5 , const void * V_51 ,
T_3 V_166 , void * V_167 ) {
struct V_25 * V_26 ;
struct V_18 V_95 [ 2 ] ;
unsigned V_99 ;
V_1 ( V_5 , 0 ) ;
F_133 ( V_5 , V_51 , V_95 , 0 ) ;
F_70 (bds, 2 , i) {
struct V_17 * V_181 = F_62 ( V_5 , & V_95 [ V_99 ] ) ;
F_63 (hnode, hlist) {
F_144 ( V_5 , & V_95 [ V_99 ] , V_26 ) ;
if ( F_64 ( V_5 , V_51 , V_26 ) ) {
if ( V_166 ( V_5 , & V_95 [ V_99 ] , V_26 , V_167 ) )
break;
}
}
}
F_80 ( V_5 , V_95 , 0 ) ;
F_130 ( V_5 , 0 ) ;
}
void
F_141 ( struct V_4 * V_5 )
{
int V_99 ;
F_41 ( F_11 ( V_5 ) &&
! F_8 ( V_5 ) ) ;
if ( ! F_121 ( V_5 ) )
return;
if ( F_97 ( V_69 , & V_5 -> V_151 ) ) {
V_5 -> V_54 = 0 ;
return;
}
for ( V_99 = 2 ; F_121 ( V_5 ) ; V_99 ++ ) {
F_130 ( V_5 , 1 ) ;
F_158 ( F_163 ( V_99 >> 3 ) ? V_182 : V_179 ,
L_4 ,
V_5 -> V_117 , V_99 - 1 ) ;
F_98 () ;
V_1 ( V_5 , 1 ) ;
}
}
void
F_109 ( struct V_4 * V_5 )
{
V_1 ( V_5 , 1 ) ;
F_141 ( V_5 ) ;
F_130 ( V_5 , 1 ) ;
}
int
F_131 ( struct V_4 * V_5 , int V_183 )
{
int V_71 ;
F_41 ( F_11 ( V_5 ) && ! F_8 ( V_5 ) ) ;
V_1 ( V_5 , 1 ) ;
V_71 = F_120 ( V_5 ) ;
if ( V_71 <= 0 ) {
F_130 ( V_5 , 1 ) ;
return V_71 ;
}
V_5 -> V_54 = V_71 ;
if ( ! V_183 ) {
F_48 ( V_69 , & V_5 -> V_151 ) ;
F_130 ( V_5 , 1 ) ;
return 0 ;
}
F_130 ( V_5 , 1 ) ;
return V_152 ( & V_5 -> V_151 ) ;
}
static int
F_164 ( struct V_4 * V_5 , struct V_18 * V_184 )
{
struct V_18 V_185 ;
struct V_17 * V_83 ;
struct V_25 * V_26 ;
struct V_25 * V_153 ;
void * V_51 ;
int V_186 = 0 ;
F_90 (hs, old, hhead) {
F_111 (hnode, pos, hhead) {
V_51 = F_165 ( V_5 , V_26 ) ;
F_41 ( V_51 != NULL ) ;
F_144 ( V_5 , V_184 , V_26 ) ;
F_39 ( V_5 , V_5 -> V_56 ,
V_5 -> V_54 , V_51 , & V_185 ) ;
F_59 ( V_5 , V_184 , & V_185 , V_26 ) ;
V_186 ++ ;
}
}
return V_186 ;
}
static int
V_152 ( T_1 * V_113 )
{
struct V_4 * V_5 = F_25 ( V_113 , struct V_4 , V_151 ) ;
struct V_48 * * V_49 ;
struct V_18 V_19 ;
unsigned int V_109 ;
unsigned int V_110 ;
int V_187 ;
int V_169 = 0 ;
int V_71 = 0 ;
int V_99 ;
F_41 ( V_5 != NULL && F_11 ( V_5 ) ) ;
V_1 ( V_5 , 0 ) ;
F_41 ( F_121 ( V_5 ) ) ;
V_109 = F_105 ( V_5 ) ;
V_110 = F_166 ( V_5 ) ;
F_130 ( V_5 , 0 ) ;
V_49 = F_86 ( V_5 , V_5 -> V_57 ,
V_109 , V_110 ) ;
V_1 ( V_5 , 1 ) ;
if ( V_49 == NULL ) {
V_71 = - V_188 ;
goto V_171;
}
if ( V_49 == V_5 -> V_57 ) {
V_49 = NULL ;
goto V_171;
}
V_71 = F_122 ( V_5 ) ;
if ( ( V_71 >= V_5 -> V_160 ) && ( V_71 <= V_5 -> V_159 ) ) {
V_109 = V_110 ;
V_110 = F_105 ( V_5 ) ;
V_71 = - V_157 ;
goto V_171;
}
F_41 ( V_5 -> V_56 == NULL ) ;
V_5 -> V_56 = V_49 ;
V_71 = 0 ;
F_110 (hs, &bd, i) {
if ( F_107 ( V_5 ) ) {
V_71 = - V_156 ;
if ( V_109 < V_110 )
break;
V_5 -> V_56 = NULL ;
V_109 = V_110 ;
V_110 = F_105 ( V_5 ) ;
goto V_171;
}
V_169 += F_164 ( V_5 , & V_19 ) ;
if ( V_169 < V_161 ||
F_108 ( V_5 ) ) {
continue;
}
V_169 = 0 ;
F_130 ( V_5 , 1 ) ;
F_98 () ;
V_1 ( V_5 , 1 ) ;
}
V_5 -> V_189 ++ ;
V_49 = V_5 -> V_57 ;
V_5 -> V_57 = V_5 -> V_56 ;
V_5 -> V_56 = NULL ;
V_5 -> V_53 = V_5 -> V_54 ;
V_171:
V_5 -> V_54 = 0 ;
if ( V_71 == - V_156 )
F_167 ( V_69 , V_113 ) ;
V_187 = F_89 ( V_5 ) ;
F_130 ( V_5 , 1 ) ;
if ( V_49 != NULL )
F_84 ( V_49 , V_187 , V_110 , V_109 ) ;
if ( V_71 != 0 )
F_158 ( V_179 , L_5 , V_71 ) ;
return V_71 == - V_156 ;
}
void F_168 ( struct V_4 * V_5 , const void * V_190 ,
void * V_191 , struct V_25 * V_26 )
{
struct V_18 V_95 [ 3 ] ;
struct V_18 V_192 [ 2 ] ;
struct V_18 V_193 ;
F_41 ( ! F_127 ( V_26 ) ) ;
V_1 ( V_5 , 0 ) ;
F_78 ( V_5 , V_190 , V_192 ) ;
F_42 ( V_5 , V_191 , & V_193 ) ;
V_95 [ 0 ] = V_192 [ 0 ] ;
V_95 [ 1 ] = V_192 [ 1 ] ;
V_95 [ 2 ] = V_193 ;
F_77 ( & V_95 [ 1 ] , & V_95 [ 2 ] ) ;
F_77 ( & V_95 [ 0 ] , & V_95 [ 1 ] ) ;
F_69 ( V_5 , V_95 , 3 , 1 ) ;
if ( F_43 ( V_192 [ 1 ] . V_21 == NULL ) ) {
F_59 ( V_5 , & V_192 [ 0 ] , & V_193 , V_26 ) ;
} else {
F_83 ( V_5 , V_192 , V_190 , V_26 ) ;
F_49 ( V_5 , & V_193 , V_26 ) ;
}
F_169 ( V_5 , V_191 , V_26 ) ;
F_72 ( V_5 , V_95 , 3 , 1 ) ;
F_130 ( V_5 , 0 ) ;
}
void F_170 ( struct V_194 * V_195 )
{
F_171 ( V_195 , L_6 ,
V_143 , L_7 ) ;
}
static struct V_48 * *
F_172 ( struct V_4 * V_5 )
{
if ( V_5 -> V_56 == NULL )
return V_5 -> V_57 ;
F_41 ( V_5 -> V_54 != 0 ) ;
return V_5 -> V_54 > V_5 -> V_53 ?
V_5 -> V_56 : V_5 -> V_57 ;
}
static unsigned int
F_173 ( struct V_4 * V_5 )
{
if ( V_5 -> V_56 == NULL )
return F_105 ( V_5 ) ;
F_41 ( V_5 -> V_54 != 0 ) ;
return V_5 -> V_54 > V_5 -> V_53 ?
F_166 ( V_5 ) : F_105 ( V_5 ) ;
}
void F_174 ( struct V_4 * V_5 , struct V_194 * V_195 )
{
int V_196 [ 8 ] = { 0 , } ;
int V_197 = - 1 ;
int V_198 = - 1 ;
int V_199 = 0 ;
int V_200 ;
int V_99 ;
V_1 ( V_5 , 0 ) ;
V_200 = F_122 ( V_5 ) ;
F_171 ( V_195 , L_8 ,
V_143 , V_5 -> V_117 ,
1 << V_5 -> V_53 , 1 << V_5 -> V_147 ,
1 << V_5 -> V_148 ,
F_175 ( V_200 ) , F_176 ( V_200 ) ,
F_175 ( V_5 -> V_160 ) ,
F_176 ( V_5 -> V_160 ) ,
F_175 ( V_5 -> V_159 ) ,
F_176 ( V_5 -> V_159 ) ,
V_5 -> V_144 , V_5 -> V_189 ) ;
for ( V_99 = 0 ; V_99 < F_173 ( V_5 ) ; V_99 ++ ) {
struct V_18 V_19 ;
V_19 . V_21 = F_172 ( V_5 ) [ V_99 ] ;
F_71 ( V_5 , & V_19 , 0 ) ;
if ( V_197 < V_19 . V_21 -> V_59 ) {
V_197 = V_19 . V_21 -> V_59 ;
V_198 = F_177 ( ~ V_197 ) ;
}
V_199 += V_19 . V_21 -> V_74 ;
V_196 [ F_88 ( F_178 ( V_19 . V_21 -> V_74 / F_45 ( V_200 , 1 ) ) , 7 ) ] ++ ;
F_73 ( V_5 , & V_19 , 0 ) ;
}
F_171 ( V_195 , L_9 , V_199 , V_197 , V_198 ) ;
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ )
F_171 ( V_195 , L_10 , V_196 [ V_99 ] , ( V_99 == 7 ) ? '\n' : '/' ) ;
F_130 ( V_5 , 0 ) ;
}
