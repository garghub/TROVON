static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return ( ( unsigned int ) ( unsigned long ) V_2 & V_3 ) ;
}
static inline unsigned int F_2 ( struct V_1 * V_2 )
{
return ( ( unsigned int ) ( unsigned long ) V_2 & V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_1 * V_2 )
{
return ( (struct V_1 * ) ( ( unsigned long ) V_2 & ~ V_5 ) ) ;
}
static inline void
F_4 ( struct V_6 * V_7 , struct V_1 * V_8 )
{
unsigned long V_9 = ( unsigned long ) V_7 -> V_2 & V_5 ;
V_7 -> V_2 = (struct V_1 * ) ( ( unsigned long ) ( V_8 ) | V_9 ) ;
}
static unsigned long F_5 ( unsigned long V_10 , int V_11 ,
bool V_12 )
{
int V_13 ;
unsigned long V_14 = V_10 ;
V_10 += V_11 * 3 ;
V_13 = V_10 % V_15 ;
if ( V_13 < V_15 / 4 && ! V_12 )
V_10 = V_10 - V_13 ;
else
V_10 = V_10 - V_13 + V_15 ;
V_10 -= V_11 * 3 ;
return F_6 ( V_10 ) ? V_10 : V_14 ;
}
unsigned long F_7 ( unsigned long V_10 , int V_11 )
{
return F_5 ( V_10 , V_11 , false ) ;
}
unsigned long F_8 ( unsigned long V_10 , int V_11 )
{
unsigned long j0 = V_16 ;
return F_5 ( V_10 + j0 , V_11 , false ) - j0 ;
}
unsigned long F_9 ( unsigned long V_10 )
{
return F_5 ( V_10 , F_10 () , false ) ;
}
unsigned long F_11 ( unsigned long V_10 )
{
return F_8 ( V_10 , F_10 () ) ;
}
unsigned long F_12 ( unsigned long V_10 , int V_11 )
{
return F_5 ( V_10 , V_11 , true ) ;
}
unsigned long F_13 ( unsigned long V_10 , int V_11 )
{
unsigned long j0 = V_16 ;
return F_5 ( V_10 + j0 , V_11 , true ) - j0 ;
}
unsigned long F_14 ( unsigned long V_10 )
{
return F_5 ( V_10 , F_10 () , true ) ;
}
unsigned long F_15 ( unsigned long V_10 )
{
return F_13 ( V_10 , F_10 () ) ;
}
void F_16 ( struct V_6 * V_7 , int V_17 )
{
V_7 -> V_18 = V_17 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_19 ) {
V_2 -> V_20 = V_16 ;
return true ;
}
return false ;
}
static void
F_18 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_21 = V_7 -> V_21 ;
unsigned long V_22 = V_21 - V_2 -> V_20 ;
struct V_23 * V_24 ;
if ( V_22 < V_25 ) {
int V_26 = V_21 & V_27 ;
V_24 = V_2 -> V_28 . V_24 + V_26 ;
} else if ( V_22 < 1 << ( V_29 + V_30 ) ) {
int V_26 = ( V_21 >> V_29 ) & V_31 ;
V_24 = V_2 -> V_32 . V_24 + V_26 ;
} else if ( V_22 < 1 << ( V_29 + 2 * V_30 ) ) {
int V_26 = ( V_21 >> ( V_29 + V_30 ) ) & V_31 ;
V_24 = V_2 -> V_33 . V_24 + V_26 ;
} else if ( V_22 < 1 << ( V_29 + 3 * V_30 ) ) {
int V_26 = ( V_21 >> ( V_29 + 2 * V_30 ) ) & V_31 ;
V_24 = V_2 -> V_34 . V_24 + V_26 ;
} else if ( ( signed long ) V_22 < 0 ) {
V_24 = V_2 -> V_28 . V_24 + ( V_2 -> V_20 & V_27 ) ;
} else {
int V_26 ;
if ( V_22 > V_35 ) {
V_22 = V_35 ;
V_21 = V_22 + V_2 -> V_20 ;
}
V_26 = ( V_21 >> ( V_29 + 3 * V_30 ) ) & V_31 ;
V_24 = V_2 -> V_36 . V_24 + V_26 ;
}
F_19 ( & V_7 -> V_37 , V_24 ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
( void ) F_17 ( V_2 ) ;
F_18 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
if ( ! V_2 -> V_38 ++ ||
F_21 ( V_7 -> V_21 , V_2 -> V_39 ) )
V_2 -> V_39 = V_7 -> V_21 ;
}
V_2 -> V_19 ++ ;
if ( ! F_1 ( V_2 ) || F_22 ( V_2 -> V_11 ) )
F_23 ( V_2 -> V_11 ) ;
}
void F_24 ( struct V_6 * V_7 , void * V_40 )
{
if ( V_7 -> V_41 )
return;
V_7 -> V_41 = V_40 ;
memcpy ( V_7 -> V_42 , V_43 -> V_44 , V_45 ) ;
V_7 -> V_46 = V_43 -> V_47 ;
}
static void F_25 ( struct V_6 * V_7 )
{
unsigned int V_48 = 0 ;
if ( F_26 ( ! V_7 -> V_41 ) )
return;
if ( F_27 ( F_1 ( V_7 -> V_2 ) ) )
V_48 |= V_49 ;
F_28 ( V_7 , V_7 -> V_46 , V_7 -> V_41 ,
V_7 -> V_50 , V_7 -> V_42 , V_48 ) ;
}
static void F_25 ( struct V_6 * V_7 ) {}
static void * F_29 ( void * V_40 )
{
return ( (struct V_6 * ) V_40 ) -> V_50 ;
}
static int F_30 ( void * V_40 , enum V_51 V_52 )
{
struct V_6 * V_7 = V_40 ;
switch ( V_52 ) {
case V_53 :
F_31 ( V_7 ) ;
F_32 ( V_7 , & V_54 ) ;
return 1 ;
default:
return 0 ;
}
}
static void F_33 ( unsigned long V_55 )
{
F_34 ( 1 ) ;
}
static int F_35 ( void * V_40 , enum V_51 V_52 )
{
struct V_6 * V_7 = V_40 ;
switch ( V_52 ) {
case V_56 :
if ( V_7 -> V_37 . V_57 == NULL &&
V_7 -> V_37 . V_58 == V_59 ) {
F_32 ( V_7 , & V_54 ) ;
F_36 ( V_7 , & V_54 ) ;
return 0 ;
} else {
F_37 ( V_7 , F_33 , 0 ) ;
return 1 ;
}
return 0 ;
case V_53 :
F_34 ( 1 ) ;
default:
return 0 ;
}
}
static int F_38 ( void * V_40 , enum V_51 V_52 )
{
struct V_6 * V_7 = V_40 ;
switch ( V_52 ) {
case V_53 :
F_31 ( V_7 ) ;
F_39 ( V_7 , & V_54 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_40 ( void * V_40 , enum V_51 V_52 )
{
struct V_6 * V_7 = V_40 ;
switch ( V_52 ) {
case V_56 :
if ( V_7 -> V_37 . V_58 == V_59 ) {
F_32 ( V_7 , & V_54 ) ;
return 0 ;
} else {
F_37 ( V_7 , F_33 , 0 ) ;
return 1 ;
}
default:
return 0 ;
}
}
static inline void F_41 ( struct V_6 * V_7 )
{
F_32 ( V_7 , & V_54 ) ;
}
static inline void F_42 ( struct V_6 * V_7 )
{
F_36 ( V_7 , & V_54 ) ;
}
static inline void F_43 ( struct V_6 * V_7 )
{
F_44 ( V_7 , & V_54 ) ;
}
static inline void F_45 ( struct V_6 * V_7 )
{
F_39 ( V_7 , & V_54 ) ;
}
static inline void F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 , & V_54 ) ;
}
void F_48 ( struct V_6 * V_7 , unsigned int V_9 ,
const char * V_60 , struct V_61 * V_62 )
{
F_49 ( V_7 , & V_54 ) ;
F_50 ( V_7 , V_9 , V_60 , V_62 ) ;
}
void F_51 ( struct V_6 * V_7 )
{
F_39 ( V_7 , & V_54 ) ;
}
static inline void F_41 ( struct V_6 * V_7 ) { }
static inline void F_42 ( struct V_6 * V_7 ) { }
static inline void F_43 ( struct V_6 * V_7 ) { }
static inline void F_46 ( struct V_6 * V_7 ) { }
static inline void F_52 ( struct V_6 * V_7 )
{
F_41 ( V_7 ) ;
F_53 ( V_7 ) ;
}
static inline void
F_54 ( struct V_6 * V_7 , unsigned long V_21 )
{
F_42 ( V_7 ) ;
F_55 ( V_7 , V_21 ) ;
}
static inline void F_56 ( struct V_6 * V_7 )
{
F_43 ( V_7 ) ;
F_57 ( V_7 ) ;
}
static inline void F_58 ( struct V_6 * V_7 )
{
F_46 ( V_7 ) ;
}
static void F_50 ( struct V_6 * V_7 , unsigned int V_9 ,
const char * V_60 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_59 ( V_63 ) ;
V_7 -> V_37 . V_57 = NULL ;
V_7 -> V_2 = ( void * ) ( ( unsigned long ) V_2 | V_9 ) ;
V_7 -> V_18 = - 1 ;
#ifdef F_60
V_7 -> V_41 = NULL ;
V_7 -> V_46 = - 1 ;
memset ( V_7 -> V_42 , 0 , V_45 ) ;
#endif
F_61 ( & V_7 -> V_64 , V_60 , V_62 , 0 ) ;
}
void F_62 ( struct V_6 * V_7 , unsigned int V_9 ,
const char * V_60 , struct V_61 * V_62 )
{
F_52 ( V_7 ) ;
F_50 ( V_7 , V_9 , V_60 , V_62 ) ;
}
static inline void F_63 ( struct V_6 * V_7 , bool V_65 )
{
struct V_23 * V_37 = & V_7 -> V_37 ;
F_56 ( V_7 ) ;
F_64 ( V_37 -> V_58 , V_37 -> V_57 ) ;
if ( V_65 )
V_37 -> V_57 = NULL ;
V_37 -> V_58 = V_66 ;
}
static inline void
F_65 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
F_63 ( V_7 , true ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
V_2 -> V_38 -- ;
V_2 -> V_19 -- ;
( void ) F_17 ( V_2 ) ;
}
static int F_66 ( struct V_6 * V_7 , struct V_1 * V_2 ,
bool V_65 )
{
if ( ! F_67 ( V_7 ) )
return 0 ;
F_63 ( V_7 , V_65 ) ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_2 -> V_38 -- ;
if ( V_7 -> V_21 == V_2 -> V_39 )
V_2 -> V_39 = V_2 -> V_20 ;
}
V_2 -> V_19 -- ;
( void ) F_17 ( V_2 ) ;
return 1 ;
}
static struct V_1 * F_68 ( struct V_6 * V_7 ,
unsigned long * V_9 )
__acquires( V_7 -> V_2 -> V_67 )
{
struct V_1 * V_2 ;
for (; ; ) {
struct V_1 * V_68 = V_7 -> V_2 ;
V_2 = F_3 ( V_68 ) ;
if ( F_26 ( V_2 != NULL ) ) {
F_69 ( & V_2 -> V_67 , * V_9 ) ;
if ( F_26 ( V_68 == V_7 -> V_2 ) )
return V_2 ;
F_70 ( & V_2 -> V_67 , * V_9 ) ;
}
F_71 () ;
}
}
static inline int
F_72 ( struct V_6 * V_7 , unsigned long V_21 ,
bool V_69 , int V_70 )
{
struct V_1 * V_2 , * V_8 ;
unsigned long V_9 ;
int V_71 = 0 , V_11 ;
F_73 ( V_7 ) ;
F_74 ( ! V_7 -> V_50 ) ;
V_2 = F_68 ( V_7 , & V_9 ) ;
V_71 = F_66 ( V_7 , V_2 , false ) ;
if ( ! V_71 && V_69 )
goto V_72;
F_54 ( V_7 , V_21 ) ;
V_11 = F_75 ( V_70 ) ;
V_8 = F_76 ( V_63 , V_11 ) ;
if ( V_2 != V_8 ) {
if ( F_26 ( V_2 -> V_73 != V_7 ) ) {
F_4 ( V_7 , NULL ) ;
F_77 ( & V_2 -> V_67 ) ;
V_2 = V_8 ;
F_78 ( & V_2 -> V_67 ) ;
F_4 ( V_7 , V_2 ) ;
}
}
V_7 -> V_21 = V_21 ;
F_20 ( V_2 , V_7 ) ;
V_72:
F_70 ( & V_2 -> V_67 , V_9 ) ;
return V_71 ;
}
int F_79 ( struct V_6 * V_7 , unsigned long V_21 )
{
return F_72 ( V_7 , V_21 , true , V_74 ) ;
}
static inline
unsigned long F_80 ( struct V_6 * V_7 , unsigned long V_21 )
{
unsigned long V_75 , V_76 ;
int V_77 ;
if ( V_7 -> V_18 >= 0 ) {
V_75 = V_21 + V_7 -> V_18 ;
} else {
long V_78 = V_21 - V_16 ;
if ( V_78 < 256 )
return V_21 ;
V_75 = V_21 + V_78 / 256 ;
}
V_76 = V_21 ^ V_75 ;
if ( V_76 == 0 )
return V_21 ;
V_77 = F_81 ( & V_76 , V_79 ) ;
V_76 = ( 1UL << V_77 ) - 1 ;
V_75 = V_75 & ~ ( V_76 ) ;
return V_75 ;
}
int F_82 ( struct V_6 * V_7 , unsigned long V_21 )
{
V_21 = F_80 ( V_7 , V_21 ) ;
if ( F_67 ( V_7 ) && V_7 -> V_21 == V_21 )
return 1 ;
return F_72 ( V_7 , V_21 , false , V_74 ) ;
}
int F_83 ( struct V_6 * V_7 , unsigned long V_21 )
{
if ( V_7 -> V_21 == V_21 && F_67 ( V_7 ) )
return 1 ;
return F_72 ( V_7 , V_21 , false , V_80 ) ;
}
void F_84 ( struct V_6 * V_7 )
{
F_74 ( F_67 ( V_7 ) ) ;
F_82 ( V_7 , V_7 -> V_21 ) ;
}
void F_85 ( struct V_6 * V_7 , int V_11 )
{
struct V_1 * V_2 = F_76 ( V_63 , V_11 ) ;
unsigned long V_9 ;
F_73 ( V_7 ) ;
F_74 ( F_67 ( V_7 ) || ! V_7 -> V_50 ) ;
F_69 ( & V_2 -> V_67 , V_9 ) ;
F_4 ( V_7 , V_2 ) ;
F_54 ( V_7 , V_7 -> V_21 ) ;
F_20 ( V_2 , V_7 ) ;
F_70 ( & V_2 -> V_67 , V_9 ) ;
}
int F_86 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
int V_71 = 0 ;
F_58 ( V_7 ) ;
F_87 ( V_7 ) ;
if ( F_67 ( V_7 ) ) {
V_2 = F_68 ( V_7 , & V_9 ) ;
V_71 = F_66 ( V_7 , V_2 , true ) ;
F_70 ( & V_2 -> V_67 , V_9 ) ;
}
return V_71 ;
}
int F_88 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
int V_71 = - 1 ;
F_58 ( V_7 ) ;
V_2 = F_68 ( V_7 , & V_9 ) ;
if ( V_2 -> V_73 != V_7 ) {
F_87 ( V_7 ) ;
V_71 = F_66 ( V_7 , V_2 , true ) ;
}
F_70 ( & V_2 -> V_67 , V_9 ) ;
return V_71 ;
}
int F_31 ( struct V_6 * V_7 )
{
#ifdef F_89
unsigned long V_9 ;
F_90 ( V_9 ) ;
F_91 ( & V_7 -> V_64 ) ;
F_92 ( & V_7 -> V_64 ) ;
F_93 ( V_9 ) ;
#endif
F_34 ( F_94 () && ! F_2 ( V_7 -> V_2 ) ) ;
for (; ; ) {
int V_71 = F_88 ( V_7 ) ;
if ( V_71 >= 0 )
return V_71 ;
F_71 () ;
}
}
static int F_95 ( struct V_1 * V_2 , struct V_81 * V_82 , int V_83 )
{
struct V_6 * V_7 , * V_84 ;
struct V_23 V_85 ;
F_96 ( V_82 -> V_24 + V_83 , & V_85 ) ;
F_97 (timer, tmp, &tv_list, entry) {
F_74 ( F_3 ( V_7 -> V_2 ) != V_2 ) ;
F_18 ( V_2 , V_7 ) ;
}
return V_83 ;
}
static void F_98 ( struct V_6 * V_7 , void (* F_99)( unsigned long ) ,
unsigned long V_55 )
{
int V_86 = F_100 () ;
#ifdef F_89
struct V_64 V_64 ;
F_101 ( & V_64 , & V_7 -> V_64 ) ;
#endif
F_91 ( & V_64 ) ;
F_102 ( V_7 ) ;
F_99 ( V_55 ) ;
F_103 ( V_7 ) ;
F_92 ( & V_64 ) ;
if ( V_86 != F_100 () ) {
F_104 ( 1 , L_1 ,
F_99 , V_86 , F_100 () ) ;
F_105 ( V_86 ) ;
}
}
static inline void F_106 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_107 ( & V_2 -> V_67 ) ;
if ( F_17 ( V_2 ) ) {
F_108 ( & V_2 -> V_67 ) ;
return;
}
while ( F_109 ( V_16 , V_2 -> V_20 ) ) {
struct V_23 V_87 ;
struct V_23 * V_88 = & V_87 ;
int V_83 = V_2 -> V_20 & V_27 ;
if ( ! V_83 &&
( ! F_95 ( V_2 , & V_2 -> V_32 , F_110 ( 0 ) ) ) &&
( ! F_95 ( V_2 , & V_2 -> V_33 , F_110 ( 1 ) ) ) &&
! F_95 ( V_2 , & V_2 -> V_34 , F_110 ( 2 ) ) )
F_95 ( V_2 , & V_2 -> V_36 , F_110 ( 3 ) ) ;
++ V_2 -> V_20 ;
F_96 ( V_2 -> V_28 . V_24 + V_83 , V_88 ) ;
while ( ! F_111 ( V_88 ) ) {
void (* F_99)( unsigned long );
unsigned long V_55 ;
bool V_89 ;
V_7 = F_112 ( V_88 , struct V_6 , V_37 ) ;
F_99 = V_7 -> V_50 ;
V_55 = V_7 -> V_55 ;
V_89 = F_2 ( V_7 -> V_2 ) ;
F_25 ( V_7 ) ;
V_2 -> V_73 = V_7 ;
F_65 ( V_7 , V_2 ) ;
if ( V_89 ) {
F_77 ( & V_2 -> V_67 ) ;
F_98 ( V_7 , F_99 , V_55 ) ;
F_78 ( & V_2 -> V_67 ) ;
} else {
F_108 ( & V_2 -> V_67 ) ;
F_98 ( V_7 , F_99 , V_55 ) ;
F_107 ( & V_2 -> V_67 ) ;
}
}
}
V_2 -> V_73 = NULL ;
F_108 ( & V_2 -> V_67 ) ;
}
static unsigned long F_113 ( struct V_1 * V_2 )
{
unsigned long V_20 = V_2 -> V_20 ;
unsigned long V_21 = V_20 + V_90 ;
int V_83 , V_91 , V_92 , V_93 = 0 ;
struct V_6 * V_94 ;
struct V_81 * V_95 [ 4 ] ;
V_83 = V_91 = V_20 & V_27 ;
do {
F_114 (nte, base->tv1.vec + slot, entry) {
if ( F_1 ( V_94 -> V_2 ) )
continue;
V_93 = 1 ;
V_21 = V_94 -> V_21 ;
if ( ! V_83 || V_91 < V_83 )
goto F_95;
return V_21 ;
}
V_91 = ( V_91 + 1 ) & V_27 ;
} while ( V_91 != V_83 );
F_95:
if ( V_83 )
V_20 += V_25 - V_83 ;
V_20 >>= V_29 ;
V_95 [ 0 ] = & V_2 -> V_32 ;
V_95 [ 1 ] = & V_2 -> V_33 ;
V_95 [ 2 ] = & V_2 -> V_34 ;
V_95 [ 3 ] = & V_2 -> V_36 ;
for ( V_92 = 0 ; V_92 < 4 ; V_92 ++ ) {
struct V_81 * V_96 = V_95 [ V_92 ] ;
V_83 = V_91 = V_20 & V_31 ;
do {
F_114 (nte, varp->vec + slot, entry) {
if ( F_1 ( V_94 -> V_2 ) )
continue;
V_93 = 1 ;
if ( F_21 ( V_94 -> V_21 , V_21 ) )
V_21 = V_94 -> V_21 ;
}
if ( V_93 ) {
if ( ! V_83 || V_91 < V_83 )
break;
return V_21 ;
}
V_91 = ( V_91 + 1 ) & V_31 ;
} while ( V_91 != V_83 );
if ( V_83 )
V_20 += V_97 - V_83 ;
V_20 >>= V_30 ;
}
return V_21 ;
}
static unsigned long F_115 ( unsigned long V_98 ,
unsigned long V_21 )
{
T_1 V_99 = F_116 () ;
struct V_100 V_101 ;
unsigned long V_78 ;
if ( V_99 . V_102 == V_103 )
return V_21 ;
if ( V_99 . V_102 <= 0 )
return V_98 + 1 ;
V_101 = F_117 ( V_99 ) ;
V_78 = F_118 ( & V_101 ) ;
if ( V_78 > V_90 )
V_78 = V_90 ;
if ( V_78 < 1 )
V_78 = 1 ;
V_98 += V_78 ;
if ( F_21 ( V_98 , V_21 ) )
return V_98 ;
return V_21 ;
}
unsigned long F_119 ( unsigned long V_98 )
{
struct V_1 * V_2 = F_120 ( V_63 ) ;
unsigned long V_21 = V_98 + V_90 ;
if ( F_121 ( F_122 () ) )
return V_21 ;
F_78 ( & V_2 -> V_67 ) ;
if ( V_2 -> V_38 ) {
if ( F_123 ( V_2 -> V_39 , V_2 -> V_20 ) )
V_2 -> V_39 = F_113 ( V_2 ) ;
V_21 = V_2 -> V_39 ;
}
F_77 ( & V_2 -> V_67 ) ;
if ( F_123 ( V_21 , V_98 ) )
return V_98 ;
return F_115 ( V_98 , V_21 ) ;
}
void F_124 ( int V_104 )
{
struct V_105 * V_106 = V_43 ;
F_125 ( V_106 , V_104 ) ;
F_126 () ;
F_127 ( V_104 ) ;
#ifdef F_128
if ( F_94 () )
F_129 () ;
#endif
F_130 () ;
F_131 ( V_106 ) ;
}
static void F_132 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_120 ( V_63 ) ;
F_133 () ;
if ( F_109 ( V_16 , V_2 -> V_20 ) )
F_106 ( V_2 ) ;
}
void F_126 ( void )
{
F_134 () ;
F_135 ( V_109 ) ;
}
static void F_136 ( unsigned long V_110 )
{
F_137 ( (struct V_105 * ) V_110 ) ;
}
signed long T_2 F_138 ( signed long V_111 )
{
struct V_6 V_7 ;
unsigned long V_112 ;
switch ( V_111 )
{
case V_113 :
F_139 () ;
goto V_114;
default:
if ( V_111 < 0 ) {
F_140 ( V_115 L_2
L_3 , V_111 ) ;
F_141 () ;
V_43 -> V_52 = V_116 ;
goto V_114;
}
}
V_112 = V_111 + V_16 ;
F_142 ( & V_7 , F_136 , ( unsigned long ) V_43 ) ;
F_72 ( & V_7 , V_112 , false , V_74 ) ;
F_139 () ;
F_143 ( & V_7 ) ;
F_51 ( & V_7 ) ;
V_111 = V_112 - V_16 ;
V_114:
return V_111 < 0 ? 0 : V_111 ;
}
signed long T_2 F_144 ( signed long V_111 )
{
F_145 ( V_117 ) ;
return F_138 ( V_111 ) ;
}
signed long T_2 F_146 ( signed long V_111 )
{
F_145 ( V_118 ) ;
return F_138 ( V_111 ) ;
}
signed long T_2 F_147 ( signed long V_111 )
{
F_145 ( V_119 ) ;
return F_138 ( V_111 ) ;
}
static int F_148 ( int V_11 )
{
int V_10 ;
struct V_1 * V_2 ;
static char V_120 [ V_121 ] ;
if ( ! V_120 [ V_11 ] ) {
static char V_122 ;
if ( V_122 ) {
V_2 = F_149 ( sizeof( * V_2 ) , V_123 ,
F_150 ( V_11 ) ) ;
if ( ! V_2 )
return - V_124 ;
if ( F_34 ( V_2 != F_3 ( V_2 ) ) ) {
F_151 ( V_2 ) ;
return - V_124 ;
}
F_76 ( V_63 , V_11 ) = V_2 ;
} else {
V_122 = 1 ;
V_2 = & V_125 ;
}
F_152 ( & V_2 -> V_67 ) ;
V_120 [ V_11 ] = 1 ;
V_2 -> V_11 = V_11 ;
} else {
V_2 = F_76 ( V_63 , V_11 ) ;
}
for ( V_10 = 0 ; V_10 < V_97 ; V_10 ++ ) {
F_153 ( V_2 -> V_36 . V_24 + V_10 ) ;
F_153 ( V_2 -> V_34 . V_24 + V_10 ) ;
F_153 ( V_2 -> V_33 . V_24 + V_10 ) ;
F_153 ( V_2 -> V_32 . V_24 + V_10 ) ;
}
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ )
F_153 ( V_2 -> V_28 . V_24 + V_10 ) ;
V_2 -> V_20 = V_16 ;
V_2 -> V_39 = V_2 -> V_20 ;
V_2 -> V_38 = 0 ;
V_2 -> V_19 = 0 ;
return 0 ;
}
static void F_154 ( struct V_1 * V_8 , struct V_23 * V_88 )
{
struct V_6 * V_7 ;
while ( ! F_111 ( V_88 ) ) {
V_7 = F_112 ( V_88 , struct V_6 , V_37 ) ;
F_63 ( V_7 , false ) ;
F_4 ( V_7 , V_8 ) ;
F_20 ( V_8 , V_7 ) ;
}
}
static void F_155 ( int V_11 )
{
struct V_1 * V_126 ;
struct V_1 * V_8 ;
int V_26 ;
F_74 ( F_156 ( V_11 ) ) ;
V_126 = F_76 ( V_63 , V_11 ) ;
V_8 = F_157 ( V_63 ) ;
F_107 ( & V_8 -> V_67 ) ;
F_158 ( & V_126 -> V_67 , V_127 ) ;
F_74 ( V_126 -> V_73 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ )
F_154 ( V_8 , V_126 -> V_28 . V_24 + V_26 ) ;
for ( V_26 = 0 ; V_26 < V_97 ; V_26 ++ ) {
F_154 ( V_8 , V_126 -> V_32 . V_24 + V_26 ) ;
F_154 ( V_8 , V_126 -> V_33 . V_24 + V_26 ) ;
F_154 ( V_8 , V_126 -> V_34 . V_24 + V_26 ) ;
F_154 ( V_8 , V_126 -> V_36 . V_24 + V_26 ) ;
}
F_77 ( & V_126 -> V_67 ) ;
F_108 ( & V_8 -> V_67 ) ;
F_159 ( V_63 ) ;
}
static int F_160 ( struct V_128 * V_129 ,
unsigned long V_130 , void * V_131 )
{
long V_11 = ( long ) V_131 ;
int V_132 ;
switch( V_130 ) {
case V_133 :
case V_134 :
V_132 = F_148 ( V_11 ) ;
if ( V_132 < 0 )
return F_161 ( V_132 ) ;
break;
#ifdef F_162
case V_135 :
case V_136 :
F_155 ( V_11 ) ;
break;
#endif
default:
break;
}
return V_137 ;
}
void T_3 F_163 ( void )
{
int V_132 ;
F_164 ( F_165 ( struct V_1 ) & V_5 ) ;
V_132 = F_160 ( & V_138 , ( unsigned long ) V_133 ,
( void * ) ( long ) F_122 () ) ;
F_74 ( V_132 != V_137 ) ;
F_166 () ;
F_167 ( & V_138 ) ;
F_168 ( V_109 , F_132 ) ;
}
void F_169 ( unsigned int V_139 )
{
unsigned long V_111 = F_170 ( V_139 ) + 1 ;
while ( V_111 )
V_111 = F_147 ( V_111 ) ;
}
unsigned long F_171 ( unsigned int V_139 )
{
unsigned long V_111 = F_170 ( V_139 ) + 1 ;
while ( V_111 && ! F_172 ( V_43 ) )
V_111 = F_144 ( V_111 ) ;
return F_173 ( V_111 ) ;
}
static int T_2 F_174 ( unsigned long V_140 , unsigned long V_141 )
{
T_1 V_142 ;
unsigned long V_78 ;
V_142 = F_175 ( 0 , V_140 * V_143 ) ;
V_78 = ( V_141 - V_140 ) * V_143 ;
return F_176 ( & V_142 , V_78 , V_144 ) ;
}
void F_177 ( unsigned long V_140 , unsigned long V_141 )
{
F_145 ( V_119 ) ;
F_174 ( V_140 , V_141 ) ;
}
