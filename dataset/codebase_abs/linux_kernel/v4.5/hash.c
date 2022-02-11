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
F_65 ( struct V_4 * V_5 , struct V_18 * V_19 ,
const void * V_51 )
{
return F_61 ( V_5 , V_19 , V_51 , NULL ,
V_90 ) ;
}
struct V_25 *
F_66 ( struct V_4 * V_5 , struct V_18 * V_19 ,
const void * V_51 )
{
return F_61 ( V_5 , V_19 , V_51 , NULL ,
V_91 ) ;
}
static void
F_67 ( struct V_4 * V_5 , struct V_18 * V_92 ,
unsigned V_93 , int V_94 )
{
struct V_48 * V_95 = NULL ;
int V_96 ;
F_68 (bds, n, i) {
if ( V_95 == V_92 [ V_96 ] . V_21 )
continue;
F_41 ( V_95 == NULL ||
V_95 -> V_66 < V_92 [ V_96 ] . V_21 -> V_66 ) ;
F_69 ( V_5 , & V_92 [ V_96 ] , V_94 ) ;
V_95 = V_92 [ V_96 ] . V_21 ;
}
}
static void
F_70 ( struct V_4 * V_5 , struct V_18 * V_92 ,
unsigned V_93 , int V_94 )
{
struct V_48 * V_95 = NULL ;
int V_96 ;
F_68 (bds, n, i) {
if ( V_95 != V_92 [ V_96 ] . V_21 ) {
F_71 ( V_5 , & V_92 [ V_96 ] , V_94 ) ;
V_95 = V_92 [ V_96 ] . V_21 ;
}
}
}
static struct V_25 *
F_72 ( struct V_4 * V_5 , struct V_18 * V_92 ,
unsigned V_93 , const void * V_51 )
{
struct V_25 * V_84 ;
unsigned V_96 ;
F_68 (bds, n, i) {
V_84 = F_61 ( V_5 , & V_92 [ V_96 ] , V_51 , NULL ,
V_90 ) ;
if ( V_84 != NULL )
return V_84 ;
}
return NULL ;
}
static struct V_25 *
F_73 ( struct V_4 * V_5 , struct V_18 * V_92 ,
unsigned V_93 , const void * V_51 ,
struct V_25 * V_26 , int V_97 )
{
struct V_25 * V_84 ;
int V_82 ;
unsigned V_96 ;
F_41 ( V_26 != NULL ) ;
V_82 = ( ! V_97 * V_89 ) | V_91 ;
F_68 (bds, n, i) {
V_84 = F_61 ( V_5 , & V_92 [ V_96 ] , V_51 ,
NULL , V_82 ) ;
if ( V_84 != NULL )
return V_84 ;
}
if ( V_96 == 1 ) {
F_49 ( V_5 , & V_92 [ 0 ] , V_26 ) ;
} else {
struct V_18 V_98 ;
F_42 ( V_5 , V_51 , & V_98 ) ;
F_49 ( V_5 , & V_98 , V_26 ) ;
}
return V_26 ;
}
static struct V_25 *
F_74 ( struct V_4 * V_5 , struct V_18 * V_92 ,
unsigned V_93 , const void * V_51 ,
struct V_25 * V_26 )
{
struct V_25 * V_84 ;
unsigned int V_96 ;
F_68 (bds, n, i) {
V_84 = F_61 ( V_5 , & V_92 [ V_96 ] , V_51 , V_26 ,
V_99 ) ;
if ( V_84 != NULL )
return V_84 ;
}
return NULL ;
}
static void
F_75 ( struct V_18 * V_100 , struct V_18 * V_101 )
{
int V_71 ;
if ( V_101 -> V_21 == NULL )
return;
if ( V_100 -> V_21 == NULL ) {
* V_100 = * V_101 ;
V_101 -> V_21 = NULL ;
return;
}
V_71 = F_60 ( V_100 , V_101 ) ;
if ( V_71 == 0 ) {
V_101 -> V_21 = NULL ;
} else if ( V_71 > 0 ) {
struct V_18 V_102 ;
V_102 = * V_101 ;
* V_101 = * V_100 ;
* V_100 = V_102 ;
}
}
void
F_76 ( struct V_4 * V_5 , const void * V_51 ,
struct V_18 * V_92 )
{
F_39 ( V_5 , V_5 -> V_57 ,
V_5 -> V_53 , V_51 , & V_92 [ 0 ] ) ;
if ( F_43 ( V_5 -> V_56 == NULL ) ) {
V_92 [ 1 ] . V_21 = NULL ;
return;
}
F_41 ( V_5 -> V_54 != 0 ) ;
F_39 ( V_5 , V_5 -> V_56 ,
V_5 -> V_54 , V_51 , & V_92 [ 1 ] ) ;
F_75 ( & V_92 [ 0 ] , & V_92 [ 1 ] ) ;
}
void
F_77 ( struct V_4 * V_5 , struct V_18 * V_92 , int V_94 )
{
F_67 ( V_5 , V_92 , 2 , V_94 ) ;
}
void
F_78 ( struct V_4 * V_5 , struct V_18 * V_92 , int V_94 )
{
F_70 ( V_5 , V_92 , 2 , V_94 ) ;
}
struct V_25 *
F_79 ( struct V_4 * V_5 , struct V_18 * V_92 ,
const void * V_51 )
{
return F_72 ( V_5 , V_92 , 2 , V_51 ) ;
}
struct V_25 *
F_80 ( struct V_4 * V_5 , struct V_18 * V_92 ,
const void * V_51 , struct V_25 * V_26 ,
int V_97 )
{
return F_73 ( V_5 , V_92 , 2 , V_51 ,
V_26 , V_97 ) ;
}
struct V_25 *
F_81 ( struct V_4 * V_5 , struct V_18 * V_92 ,
const void * V_51 , struct V_25 * V_26 )
{
return F_74 ( V_5 , V_92 , 2 , V_51 , V_26 ) ;
}
static void
F_82 ( struct V_48 * * V_103 ,
int V_104 , int V_105 , int V_106 )
{
int V_96 ;
for ( V_96 = V_105 ; V_96 < V_106 ; V_96 ++ ) {
if ( V_103 [ V_96 ] != NULL )
F_83 ( V_103 [ V_96 ] , V_104 ) ;
}
F_83 ( V_103 , sizeof( V_103 [ 0 ] ) * V_106 ) ;
}
static struct V_48 * *
F_84 ( struct V_4 * V_5 , struct V_48 * * V_107 ,
unsigned int V_108 , unsigned int V_109 )
{
struct V_48 * * V_110 ;
int V_96 ;
F_41 ( V_108 == 0 || V_107 != NULL ) ;
if ( V_107 != NULL && V_108 == V_109 )
return V_107 ;
F_85 ( V_110 , sizeof( V_110 [ 0 ] ) * V_109 ) ;
if ( V_110 == NULL )
return NULL ;
if ( V_107 != NULL ) {
memcpy ( V_110 , V_107 ,
F_86 ( V_108 , V_109 ) * sizeof( * V_107 ) ) ;
}
for ( V_96 = V_108 ; V_96 < V_109 ; V_96 ++ ) {
struct V_17 * V_83 ;
struct V_18 V_19 ;
F_85 ( V_110 [ V_96 ] , F_87 ( V_5 ) ) ;
if ( V_110 [ V_96 ] == NULL ) {
F_82 ( V_110 , F_87 ( V_5 ) ,
V_108 , V_109 ) ;
return NULL ;
}
V_110 [ V_96 ] -> V_66 = V_96 ;
V_110 [ V_96 ] -> V_73 = 1 ;
V_110 [ V_96 ] -> V_59 = - 1 ;
V_19 . V_21 = V_110 [ V_96 ] ;
F_88 (hs, &bd, hhead)
F_89 ( V_83 ) ;
if ( F_8 ( V_5 ) ||
F_9 ( V_5 ) )
continue;
if ( F_13 ( V_5 ) )
F_12 ( & V_110 [ V_96 ] -> V_111 . V_11 ) ;
else if ( F_14 ( V_5 ) )
F_10 ( & V_110 [ V_96 ] -> V_111 . V_10 ) ;
else
F_15 () ;
}
return V_110 ;
}
static int F_90 ( T_1 * V_112 )
{
struct V_4 * V_5 = F_25 ( V_112 , struct V_4 , V_70 ) ;
int V_113 ;
int V_114 ;
int V_115 ;
int V_50 ;
F_46 ( & V_5 -> V_64 ) ;
V_113 = V_5 -> V_63 ;
V_114 = V_5 -> V_65 ;
V_115 = V_5 -> V_67 ;
V_50 = V_5 -> V_68 ;
F_47 ( & V_5 -> V_64 ) ;
F_91 ( L_1 ,
V_5 -> V_116 , V_50 , V_113 , V_114 , V_115 ) ;
F_46 ( & V_5 -> V_64 ) ;
V_5 -> V_68 = 0 ;
F_47 ( & V_5 -> V_64 ) ;
return 0 ;
}
static void F_92 ( struct V_4 * V_5 )
{
F_10 ( & V_5 -> V_64 ) ;
F_93 ( & V_5 -> V_70 , V_5 , F_90 ) ;
}
static void F_94 ( struct V_4 * V_5 )
{
if ( F_95 ( V_69 , & V_5 -> V_70 ) )
return;
F_46 ( & V_5 -> V_64 ) ;
while ( V_5 -> V_68 != 0 ) {
F_47 ( & V_5 -> V_64 ) ;
F_96 () ;
F_46 ( & V_5 -> V_64 ) ;
}
F_47 ( & V_5 -> V_64 ) ;
}
static inline void F_92 ( struct V_4 * V_5 ) {}
static inline void F_94 ( struct V_4 * V_5 ) {}
struct V_4 *
F_97 ( char * V_117 , unsigned V_118 , unsigned V_119 ,
unsigned V_120 , unsigned V_121 ,
unsigned V_122 , unsigned V_123 ,
struct V_124 * V_125 , unsigned V_126 )
{
struct V_4 * V_5 ;
int V_127 ;
F_98 ( V_128 < 15 ) ;
F_41 ( V_117 != NULL ) ;
F_41 ( V_125 != NULL ) ;
F_41 ( V_125 -> V_129 ) ;
F_41 ( V_125 -> V_130 ) ;
F_41 ( V_125 -> V_131 ) ;
F_41 ( V_125 -> V_132 ) ;
F_41 ( V_125 -> V_133 != NULL ) ;
F_41 ( V_125 -> V_134 != NULL ) ;
if ( ( V_126 & V_135 ) != 0 )
V_126 |= V_136 ;
F_41 ( V_118 > 0 ) ;
F_41 ( V_118 >= V_120 ) ;
F_41 ( V_119 >= V_118 && V_119 < 31 ) ;
F_41 ( F_99 ( ( V_126 & V_135 ) == 0 , V_118 == V_119 ) ) ;
F_41 ( F_99 ( ( V_126 & V_135 ) != 0 ,
( V_126 & V_137 ) == 0 ) ) ;
F_41 ( F_99 ( ( V_126 & V_138 ) != 0 ,
V_125 -> V_139 != NULL ) ) ;
V_127 = ( V_126 & V_140 ) == 0 ?
V_141 : V_142 ;
F_85 ( V_5 , F_100 ( struct V_4 , V_116 [ V_127 ] ) ) ;
if ( V_5 == NULL )
return NULL ;
F_101 ( V_5 -> V_116 , V_117 , V_127 ) ;
V_5 -> V_143 = V_126 ;
F_102 ( & V_5 -> V_144 , 1 ) ;
F_102 ( & V_5 -> V_75 , 0 ) ;
F_7 ( V_5 ) ;
F_36 ( V_5 ) ;
V_5 -> V_53 = ( V_145 ) V_118 ;
V_5 -> V_146 = ( V_145 ) V_118 ;
V_5 -> V_147 = ( V_145 ) V_119 ;
V_5 -> V_55 = ( V_145 ) V_120 ;
V_5 -> V_148 = V_125 ;
V_5 -> V_149 = V_121 ;
V_5 -> V_54 = 0 ;
F_93 ( & V_5 -> V_150 , V_5 , V_151 ) ;
F_92 ( V_5 ) ;
if ( F_11 ( V_5 ) )
F_103 ( V_5 , V_122 , V_123 ) ;
V_5 -> V_57 = F_84 ( V_5 , NULL , 0 ,
F_104 ( V_5 ) ) ;
if ( V_5 -> V_57 != NULL )
return V_5 ;
F_83 ( V_5 , F_100 ( struct V_4 , V_116 [ V_127 ] ) ) ;
return NULL ;
}
static void
F_105 ( struct V_4 * V_5 )
{
struct V_25 * V_26 ;
struct V_25 * V_152 ;
struct V_18 V_19 ;
int V_96 ;
F_41 ( V_5 != NULL ) ;
F_41 ( ! F_106 ( V_5 ) &&
! F_107 ( V_5 ) ) ;
V_5 -> V_153 = 1 ;
if ( F_11 ( V_5 ) )
F_108 ( V_5 ) ;
F_94 ( V_5 ) ;
F_41 ( V_5 -> V_57 != NULL &&
V_5 -> V_56 == NULL ) ;
F_109 (hs, &bd, i) {
struct V_17 * V_83 ;
F_41 ( V_19 . V_21 != NULL ) ;
F_69 ( V_5 , & V_19 , 1 ) ;
F_88 (hs, &bd, hhead) {
F_110 (hnode, pos, hhead) {
F_111 ( ! F_112 ( V_5 ) ,
L_2 ,
V_5 -> V_116 , V_19 . V_21 -> V_66 ,
V_19 . V_23 , V_19 . V_21 -> V_74 ) ;
F_55 ( V_5 , & V_19 , V_26 ) ;
F_113 ( V_5 , V_26 ) ;
}
}
F_41 ( V_19 . V_21 -> V_74 == 0 ) ;
F_71 ( V_5 , & V_19 , 1 ) ;
F_96 () ;
}
F_41 ( F_56 ( & V_5 -> V_75 ) == 0 ) ;
F_82 ( V_5 -> V_57 , F_87 ( V_5 ) ,
0 , F_104 ( V_5 ) ) ;
V_96 = F_114 ( V_5 ) ?
V_142 : V_141 ;
F_83 ( V_5 , F_100 ( struct V_4 , V_116 [ V_96 ] ) ) ;
}
struct V_4 * F_115 ( struct V_4 * V_5 )
{
if ( F_116 ( & V_5 -> V_144 ) )
return V_5 ;
return NULL ;
}
void F_117 ( struct V_4 * V_5 )
{
if ( F_118 ( & V_5 -> V_144 ) )
F_105 ( V_5 ) ;
}
static inline int
F_119 ( struct V_4 * V_5 )
{
if ( F_8 ( V_5 ) ||
! F_11 ( V_5 ) )
return - V_154 ;
if ( F_50 ( F_106 ( V_5 ) ) )
return - V_155 ;
if ( F_50 ( F_120 ( V_5 ) ) )
return - V_156 ;
if ( F_50 ( F_107 ( V_5 ) ) )
return - V_157 ;
if ( ( V_5 -> V_53 < V_5 -> V_147 ) &&
( F_121 ( V_5 ) > V_5 -> V_158 ) )
return V_5 -> V_53 + 1 ;
if ( ! F_122 ( V_5 ) )
return 0 ;
if ( ( V_5 -> V_53 > V_5 -> V_146 ) &&
( F_121 ( V_5 ) < V_5 -> V_159 ) )
return V_5 -> V_53 - 1 ;
return 0 ;
}
static inline int
F_123 ( struct V_4 * V_5 )
{
return ! F_124 ( V_5 ) &&
F_56 ( & V_5 -> V_75 ) < V_160 ;
}
void
F_125 ( struct V_4 * V_5 , const void * V_51 , struct V_25 * V_26 )
{
struct V_18 V_19 ;
int V_50 ;
F_41 ( F_126 ( V_26 ) ) ;
V_1 ( V_5 , 0 ) ;
F_127 ( V_5 , V_51 , & V_19 , 1 ) ;
F_128 ( V_5 , V_51 , V_26 ) ;
F_49 ( V_5 , & V_19 , V_26 ) ;
F_71 ( V_5 , & V_19 , 1 ) ;
V_50 = F_119 ( V_5 ) ;
F_129 ( V_5 , 0 ) ;
if ( V_50 > 0 )
F_130 ( V_5 , F_123 ( V_5 ) ) ;
}
static struct V_25 *
F_131 ( struct V_4 * V_5 , const void * V_51 ,
struct V_25 * V_26 , int V_97 )
{
struct V_25 * V_84 ;
struct V_18 V_92 [ 2 ] ;
int V_50 = 0 ;
F_41 ( F_126 ( V_26 ) ) ;
V_1 ( V_5 , 0 ) ;
F_132 ( V_5 , V_51 , V_92 , 1 ) ;
F_128 ( V_5 , V_51 , V_26 ) ;
V_84 = F_80 ( V_5 , V_92 , V_51 ,
V_26 , V_97 ) ;
F_78 ( V_5 , V_92 , 1 ) ;
if ( V_84 == V_26 )
V_50 = F_119 ( V_5 ) ;
F_129 ( V_5 , 0 ) ;
if ( V_50 > 0 )
F_130 ( V_5 , F_123 ( V_5 ) ) ;
return V_84 ;
}
int
F_133 ( struct V_4 * V_5 , const void * V_51 ,
struct V_25 * V_26 )
{
return F_131 ( V_5 , V_51 , V_26 , 1 ) != V_26 ?
- V_156 : 0 ;
}
void *
F_134 ( struct V_4 * V_5 , const void * V_51 ,
struct V_25 * V_26 )
{
V_26 = F_131 ( V_5 , V_51 , V_26 , 0 ) ;
return F_135 ( V_5 , V_26 ) ;
}
void *
F_136 ( struct V_4 * V_5 , const void * V_51 , struct V_25 * V_26 )
{
void * V_161 = NULL ;
int V_50 = 0 ;
struct V_18 V_92 [ 2 ] ;
V_1 ( V_5 , 0 ) ;
F_132 ( V_5 , V_51 , V_92 , 1 ) ;
if ( V_26 == NULL || ! F_126 ( V_26 ) ) {
if ( V_92 [ 1 ] . V_21 == NULL && V_26 != NULL ) {
F_55 ( V_5 , & V_92 [ 0 ] , V_26 ) ;
} else {
V_26 = F_81 ( V_5 , V_92 ,
V_51 , V_26 ) ;
}
}
if ( V_26 != NULL ) {
V_161 = F_135 ( V_5 , V_26 ) ;
V_50 = F_119 ( V_5 ) ;
}
F_78 ( V_5 , V_92 , 1 ) ;
F_129 ( V_5 , 0 ) ;
if ( V_50 > 0 )
F_130 ( V_5 , F_123 ( V_5 ) ) ;
return V_161 ;
}
void *
F_137 ( struct V_4 * V_5 , const void * V_51 )
{
return F_136 ( V_5 , V_51 , NULL ) ;
}
void *
F_138 ( struct V_4 * V_5 , const void * V_51 )
{
void * V_161 = NULL ;
struct V_25 * V_26 ;
struct V_18 V_92 [ 2 ] ;
V_1 ( V_5 , 0 ) ;
F_132 ( V_5 , V_51 , V_92 , 0 ) ;
V_26 = F_79 ( V_5 , V_92 , V_51 ) ;
if ( V_26 != NULL )
V_161 = F_135 ( V_5 , V_26 ) ;
F_78 ( V_5 , V_92 , 0 ) ;
F_129 ( V_5 , 0 ) ;
return V_161 ;
}
static void
F_139 ( struct V_4 * V_5 )
{
F_41 ( ! F_106 ( V_5 ) ) ;
if ( ! F_11 ( V_5 ) )
return;
V_5 -> V_162 = 1 ;
V_1 ( V_5 , 1 ) ;
V_5 -> V_163 ++ ;
if ( F_120 ( V_5 ) )
F_140 ( V_5 ) ;
F_129 ( V_5 , 1 ) ;
}
static void
F_141 ( struct V_4 * V_5 )
{
int V_164 ;
int V_50 ;
if ( ! F_11 ( V_5 ) )
return;
V_1 ( V_5 , 1 ) ;
V_164 = -- V_5 -> V_163 ;
V_50 = F_119 ( V_5 ) ;
F_129 ( V_5 , 1 ) ;
if ( V_164 == 0 )
V_5 -> V_162 = 0 ;
if ( V_50 > 0 ) {
F_130 ( V_5 , F_56 ( & V_5 -> V_75 ) <
V_160 ) ;
}
}
static T_2
F_142 ( struct V_4 * V_5 , T_3 V_165 ,
void * V_166 , int V_167 )
{
struct V_25 * V_26 ;
struct V_25 * V_152 ;
struct V_18 V_19 ;
T_2 V_168 = 0 ;
int V_94 = ! ! V_167 ;
int V_169 = 0 ;
int V_96 ;
F_139 ( V_5 ) ;
V_1 ( V_5 , 0 ) ;
F_41 ( ! F_120 ( V_5 ) ) ;
F_109 (hs, &bd, i) {
struct V_17 * V_83 ;
F_69 ( V_5 , & V_19 , V_94 ) ;
if ( V_165 == NULL ) {
V_168 += V_19 . V_21 -> V_74 ;
F_71 ( V_5 , & V_19 , V_94 ) ;
continue;
}
F_88 (hs, &bd, hhead) {
F_110 (hnode, pos, hhead) {
F_143 ( V_5 , & V_19 , V_26 ) ;
V_168 ++ ;
V_169 ++ ;
if ( V_165 ( V_5 , & V_19 , V_26 , V_166 ) ) {
F_71 ( V_5 , & V_19 , V_94 ) ;
goto V_170;
}
}
}
F_71 ( V_5 , & V_19 , V_94 ) ;
if ( V_169 < V_160 )
continue;
V_169 = 0 ;
F_129 ( V_5 , 0 ) ;
F_96 () ;
V_1 ( V_5 , 0 ) ;
}
V_170:
F_129 ( V_5 , 0 ) ;
F_141 ( V_5 ) ;
return V_168 ;
}
static int
F_144 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 , void * V_166 )
{
struct V_171 * V_172 = V_166 ;
if ( V_172 -> V_165 ( F_135 ( V_5 , V_26 ) , V_172 -> V_173 ) )
F_55 ( V_5 , V_19 , V_26 ) ;
return 0 ;
}
void
F_145 ( struct V_4 * V_5 , T_4 V_165 , void * V_166 )
{
struct V_171 V_173 = {
. V_165 = V_165 ,
. V_173 = V_166 ,
} ;
F_142 ( V_5 , F_144 , & V_173 , 1 ) ;
}
void
F_146 ( struct V_4 * V_5 , T_3 V_165 ,
void * V_166 )
{
F_142 ( V_5 , V_165 , V_166 , 0 ) ;
}
void
F_147 ( struct V_4 * V_5 , T_3 V_165 ,
void * V_166 )
{
F_142 ( V_5 , V_165 , V_166 , 1 ) ;
}
static int
F_148 ( struct V_4 * V_5 , struct V_18 * V_19 ,
struct V_25 * V_26 , void * V_166 )
{
* ( int * ) V_166 = 0 ;
return 1 ;
}
int
F_149 ( struct V_4 * V_5 )
{
int V_174 = 1 ;
F_142 ( V_5 , F_148 , & V_174 , 0 ) ;
return V_174 ;
}
T_2
F_150 ( struct V_4 * V_5 )
{
return F_51 ( V_5 ) ?
F_56 ( & V_5 -> V_75 ) :
F_142 ( V_5 , NULL , NULL , 0 ) ;
}
static int
F_151 ( struct V_4 * V_5 , T_3 V_165 ,
void * V_166 )
{
struct V_25 * V_26 ;
struct V_25 * V_102 ;
struct V_18 V_19 ;
T_5 V_175 ;
int V_168 = 0 ;
int V_176 ;
int V_71 ;
int V_96 ;
V_176 = F_152 ( V_5 ) ||
! F_53 ( V_5 ) ||
V_5 -> V_148 -> V_134 == NULL ;
V_1 ( V_5 , 0 ) ;
F_41 ( ! F_120 ( V_5 ) ) ;
F_109 (hs, &bd, i) {
struct V_17 * V_83 ;
F_69 ( V_5 , & V_19 , 0 ) ;
V_175 = F_153 ( & V_19 ) ;
F_88 (hs, &bd, hhead) {
for ( V_26 = V_83 -> V_38 ; V_26 != NULL ; ) {
F_143 ( V_5 , & V_19 , V_26 ) ;
F_54 ( V_5 , V_26 ) ;
F_71 ( V_5 , & V_19 , 0 ) ;
F_129 ( V_5 , 0 ) ;
V_71 = V_165 ( V_5 , & V_19 , V_26 , V_166 ) ;
if ( V_176 )
F_154 ( V_5 , V_26 ) ;
F_96 () ;
V_168 ++ ;
V_1 ( V_5 , 0 ) ;
F_69 ( V_5 , & V_19 , 0 ) ;
if ( ! V_176 ) {
V_102 = V_26 -> V_36 ;
F_58 ( V_5 , V_26 ) ;
V_26 = V_102 ;
} else {
if ( V_175 !=
F_153 ( & V_19 ) )
break;
V_26 = V_26 -> V_36 ;
}
if ( V_71 )
break;
}
if ( V_71 )
break;
}
F_71 ( V_5 , & V_19 , 0 ) ;
if ( V_71 )
break;
}
F_129 ( V_5 , 0 ) ;
return V_168 ;
}
int
F_155 ( struct V_4 * V_5 , T_3 V_165 ,
void * V_166 )
{
if ( F_8 ( V_5 ) ||
F_152 ( V_5 ) ||
! F_53 ( V_5 ) )
return - V_154 ;
if ( V_5 -> V_148 -> V_133 == NULL ||
( V_5 -> V_148 -> V_177 == NULL &&
V_5 -> V_148 -> V_134 == NULL ) )
return - V_154 ;
F_139 ( V_5 ) ;
F_151 ( V_5 , V_165 , V_166 ) ;
F_141 ( V_5 ) ;
return 0 ;
}
int
F_156 ( struct V_4 * V_5 , T_3 V_165 ,
void * V_166 )
{
unsigned V_96 = 0 ;
if ( F_8 ( V_5 ) )
return - V_154 ;
if ( V_5 -> V_148 -> V_133 == NULL ||
( V_5 -> V_148 -> V_177 == NULL &&
V_5 -> V_148 -> V_134 == NULL ) )
return - V_154 ;
F_139 ( V_5 ) ;
while ( F_151 ( V_5 , V_165 , V_166 ) ) {
F_157 ( V_178 , L_3 ,
V_5 -> V_116 , V_96 ++ ) ;
}
F_141 ( V_5 ) ;
return 0 ;
}
void
F_158 ( struct V_4 * V_5 , unsigned V_179 ,
T_3 V_165 , void * V_166 )
{
struct V_17 * V_83 ;
struct V_25 * V_26 ;
struct V_18 V_19 ;
F_139 ( V_5 ) ;
V_1 ( V_5 , 0 ) ;
if ( V_179 >= F_159 ( V_5 ) )
goto V_170;
F_160 ( V_5 , V_179 , & V_19 ) ;
F_69 ( V_5 , & V_19 , 0 ) ;
V_83 = F_62 ( V_5 , & V_19 ) ;
F_63 (hnode, hhead) {
if ( V_165 ( V_5 , & V_19 , V_26 , V_166 ) )
break;
}
F_71 ( V_5 , & V_19 , 0 ) ;
V_170:
F_129 ( V_5 , 0 ) ;
F_141 ( V_5 ) ;
}
void
F_161 ( struct V_4 * V_5 , const void * V_51 ,
T_3 V_165 , void * V_166 )
{
struct V_25 * V_26 ;
struct V_18 V_92 [ 2 ] ;
unsigned int V_96 ;
V_1 ( V_5 , 0 ) ;
F_132 ( V_5 , V_51 , V_92 , 0 ) ;
F_68 (bds, 2 , i) {
struct V_17 * V_180 = F_62 ( V_5 , & V_92 [ V_96 ] ) ;
F_63 (hnode, hlist) {
F_143 ( V_5 , & V_92 [ V_96 ] , V_26 ) ;
if ( F_64 ( V_5 , V_51 , V_26 ) ) {
if ( V_165 ( V_5 , & V_92 [ V_96 ] , V_26 , V_166 ) )
break;
}
}
}
F_78 ( V_5 , V_92 , 0 ) ;
F_129 ( V_5 , 0 ) ;
}
void
F_140 ( struct V_4 * V_5 )
{
int V_96 ;
F_41 ( F_11 ( V_5 ) &&
! F_8 ( V_5 ) ) ;
if ( ! F_120 ( V_5 ) )
return;
if ( F_95 ( V_69 , & V_5 -> V_150 ) ) {
V_5 -> V_54 = 0 ;
return;
}
for ( V_96 = 2 ; F_120 ( V_5 ) ; V_96 ++ ) {
F_129 ( V_5 , 1 ) ;
F_157 ( F_162 ( V_96 >> 3 ) ? V_181 : V_178 ,
L_4 ,
V_5 -> V_116 , V_96 - 1 ) ;
F_96 () ;
V_1 ( V_5 , 1 ) ;
}
}
void
F_108 ( struct V_4 * V_5 )
{
V_1 ( V_5 , 1 ) ;
F_140 ( V_5 ) ;
F_129 ( V_5 , 1 ) ;
}
int
F_130 ( struct V_4 * V_5 , int V_182 )
{
int V_71 ;
F_41 ( F_11 ( V_5 ) && ! F_8 ( V_5 ) ) ;
V_1 ( V_5 , 1 ) ;
V_71 = F_119 ( V_5 ) ;
if ( V_71 <= 0 ) {
F_129 ( V_5 , 1 ) ;
return V_71 ;
}
V_5 -> V_54 = V_71 ;
if ( ! V_182 ) {
F_48 ( V_69 , & V_5 -> V_150 ) ;
F_129 ( V_5 , 1 ) ;
return 0 ;
}
F_129 ( V_5 , 1 ) ;
return V_151 ( & V_5 -> V_150 ) ;
}
static int
F_163 ( struct V_4 * V_5 , struct V_18 * V_183 )
{
struct V_18 V_184 ;
struct V_17 * V_83 ;
struct V_25 * V_26 ;
struct V_25 * V_152 ;
void * V_51 ;
int V_185 = 0 ;
F_88 (hs, old, hhead) {
F_110 (hnode, pos, hhead) {
V_51 = F_164 ( V_5 , V_26 ) ;
F_41 ( V_51 != NULL ) ;
F_143 ( V_5 , V_183 , V_26 ) ;
F_39 ( V_5 , V_5 -> V_56 ,
V_5 -> V_54 , V_51 , & V_184 ) ;
F_59 ( V_5 , V_183 , & V_184 , V_26 ) ;
V_185 ++ ;
}
}
return V_185 ;
}
static int
V_151 ( T_1 * V_112 )
{
struct V_4 * V_5 = F_25 ( V_112 , struct V_4 , V_150 ) ;
struct V_48 * * V_49 ;
struct V_18 V_19 ;
unsigned int V_108 ;
unsigned int V_109 ;
int V_186 ;
int V_168 = 0 ;
int V_71 = 0 ;
int V_96 ;
F_41 ( V_5 != NULL && F_11 ( V_5 ) ) ;
V_1 ( V_5 , 0 ) ;
F_41 ( F_120 ( V_5 ) ) ;
V_108 = F_104 ( V_5 ) ;
V_109 = F_165 ( V_5 ) ;
F_129 ( V_5 , 0 ) ;
V_49 = F_84 ( V_5 , V_5 -> V_57 ,
V_108 , V_109 ) ;
V_1 ( V_5 , 1 ) ;
if ( V_49 == NULL ) {
V_71 = - V_187 ;
goto V_170;
}
if ( V_49 == V_5 -> V_57 ) {
V_49 = NULL ;
goto V_170;
}
V_71 = F_121 ( V_5 ) ;
if ( ( V_71 >= V_5 -> V_159 ) && ( V_71 <= V_5 -> V_158 ) ) {
V_108 = V_109 ;
V_109 = F_104 ( V_5 ) ;
V_71 = - V_156 ;
goto V_170;
}
F_41 ( V_5 -> V_56 == NULL ) ;
V_5 -> V_56 = V_49 ;
V_71 = 0 ;
F_109 (hs, &bd, i) {
if ( F_106 ( V_5 ) ) {
V_71 = - V_155 ;
if ( V_108 < V_109 )
break;
V_5 -> V_56 = NULL ;
V_108 = V_109 ;
V_109 = F_104 ( V_5 ) ;
goto V_170;
}
V_168 += F_163 ( V_5 , & V_19 ) ;
if ( V_168 < V_160 ||
F_107 ( V_5 ) ) {
continue;
}
V_168 = 0 ;
F_129 ( V_5 , 1 ) ;
F_96 () ;
V_1 ( V_5 , 1 ) ;
}
V_5 -> V_188 ++ ;
V_49 = V_5 -> V_57 ;
V_5 -> V_57 = V_5 -> V_56 ;
V_5 -> V_56 = NULL ;
V_5 -> V_53 = V_5 -> V_54 ;
V_170:
V_5 -> V_54 = 0 ;
if ( V_71 == - V_155 )
F_166 ( V_69 , V_112 ) ;
V_186 = F_87 ( V_5 ) ;
F_129 ( V_5 , 1 ) ;
if ( V_49 != NULL )
F_82 ( V_49 , V_186 , V_109 , V_108 ) ;
if ( V_71 != 0 )
F_157 ( V_178 , L_5 , V_71 ) ;
return V_71 == - V_155 ;
}
void F_167 ( struct V_4 * V_5 , const void * V_189 ,
void * V_190 , struct V_25 * V_26 )
{
struct V_18 V_92 [ 3 ] ;
struct V_18 V_191 [ 2 ] ;
struct V_18 V_192 ;
F_41 ( ! F_126 ( V_26 ) ) ;
V_1 ( V_5 , 0 ) ;
F_76 ( V_5 , V_189 , V_191 ) ;
F_42 ( V_5 , V_190 , & V_192 ) ;
V_92 [ 0 ] = V_191 [ 0 ] ;
V_92 [ 1 ] = V_191 [ 1 ] ;
V_92 [ 2 ] = V_192 ;
F_75 ( & V_92 [ 1 ] , & V_92 [ 2 ] ) ;
F_75 ( & V_92 [ 0 ] , & V_92 [ 1 ] ) ;
F_67 ( V_5 , V_92 , 3 , 1 ) ;
if ( F_43 ( V_191 [ 1 ] . V_21 == NULL ) ) {
F_59 ( V_5 , & V_191 [ 0 ] , & V_192 , V_26 ) ;
} else {
F_81 ( V_5 , V_191 , V_189 , V_26 ) ;
F_49 ( V_5 , & V_192 , V_26 ) ;
}
F_168 ( V_5 , V_26 , V_190 ) ;
F_70 ( V_5 , V_92 , 3 , 1 ) ;
F_129 ( V_5 , 0 ) ;
}
void F_169 ( struct V_193 * V_194 )
{
F_170 ( V_194 , L_6 ,
V_142 , L_7 ) ;
}
static struct V_48 * *
F_171 ( struct V_4 * V_5 )
{
if ( V_5 -> V_56 == NULL )
return V_5 -> V_57 ;
F_41 ( V_5 -> V_54 != 0 ) ;
return V_5 -> V_54 > V_5 -> V_53 ?
V_5 -> V_56 : V_5 -> V_57 ;
}
static unsigned int
F_172 ( struct V_4 * V_5 )
{
if ( V_5 -> V_56 == NULL )
return F_104 ( V_5 ) ;
F_41 ( V_5 -> V_54 != 0 ) ;
return V_5 -> V_54 > V_5 -> V_53 ?
F_165 ( V_5 ) : F_104 ( V_5 ) ;
}
void F_173 ( struct V_4 * V_5 , struct V_193 * V_194 )
{
int V_195 [ 8 ] = { 0 , } ;
int V_196 = - 1 ;
int V_197 = - 1 ;
int V_198 = 0 ;
int V_199 ;
int V_96 ;
V_1 ( V_5 , 0 ) ;
V_199 = F_121 ( V_5 ) ;
F_170 ( V_194 , L_8 ,
V_142 , V_5 -> V_116 ,
1 << V_5 -> V_53 , 1 << V_5 -> V_146 ,
1 << V_5 -> V_147 ,
F_174 ( V_199 ) , F_175 ( V_199 ) ,
F_174 ( V_5 -> V_159 ) ,
F_175 ( V_5 -> V_159 ) ,
F_174 ( V_5 -> V_158 ) ,
F_175 ( V_5 -> V_158 ) ,
V_5 -> V_143 , V_5 -> V_188 ) ;
for ( V_96 = 0 ; V_96 < F_172 ( V_5 ) ; V_96 ++ ) {
struct V_18 V_19 ;
V_19 . V_21 = F_171 ( V_5 ) [ V_96 ] ;
F_69 ( V_5 , & V_19 , 0 ) ;
if ( V_196 < V_19 . V_21 -> V_59 ) {
V_196 = V_19 . V_21 -> V_59 ;
V_197 = F_176 ( ~ V_196 ) ;
}
V_198 += V_19 . V_21 -> V_74 ;
V_195 [ F_86 ( F_177 ( V_19 . V_21 -> V_74 / F_45 ( V_199 , 1 ) ) , 7 ) ] ++ ;
F_71 ( V_5 , & V_19 , 0 ) ;
}
F_170 ( V_194 , L_9 , V_198 , V_196 , V_197 ) ;
for ( V_96 = 0 ; V_96 < 8 ; V_96 ++ )
F_170 ( V_194 , L_10 , V_195 [ V_96 ] , ( V_96 == 7 ) ? '\n' : '/' ) ;
F_129 ( V_5 , 0 ) ;
}
