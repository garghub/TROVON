void F_1 ( bool V_1 )
{
bool V_2 = V_3 && V_4 ;
unsigned int V_5 ;
if ( F_2 ( V_6 . V_7 ) == V_2 )
return;
F_3 (cpu) {
F_4 ( V_6 . V_7 , V_5 ) = V_2 ;
F_4 ( V_8 . V_7 , V_5 ) = V_2 ;
if ( ! V_1 )
continue;
F_4 ( V_6 . V_9 , V_5 ) = true ;
F_4 ( V_8 . V_9 , V_5 ) = true ;
}
}
int F_5 ( struct V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_14 ,
T_3 * V_15 )
{
static F_6 ( V_16 ) ;
int V_17 ;
F_7 ( & V_16 ) ;
V_17 = F_8 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( ! V_17 && V_12 )
F_1 ( false ) ;
F_9 ( & V_16 ) ;
return V_17 ;
}
static inline struct V_18 * F_10 ( struct V_18 * V_19 ,
int V_20 )
{
if ( V_20 || ! V_19 -> V_7 )
return F_11 ( & V_6 ) ;
return F_12 ( & V_6 , F_13 () ) ;
}
static inline struct V_18 * F_10 ( struct V_18 * V_19 ,
int V_20 )
{
return F_11 ( & V_6 ) ;
}
static unsigned long F_14 ( unsigned long V_21 , int V_5 ,
bool V_22 )
{
int V_23 ;
unsigned long V_24 = V_21 ;
V_21 += V_5 * 3 ;
V_23 = V_21 % V_25 ;
if ( V_23 < V_25 / 4 && ! V_22 )
V_21 = V_21 - V_23 ;
else
V_21 = V_21 - V_23 + V_25 ;
V_21 -= V_5 * 3 ;
return F_15 ( V_21 ) ? V_21 : V_24 ;
}
unsigned long F_16 ( unsigned long V_21 , int V_5 )
{
return F_14 ( V_21 , V_5 , false ) ;
}
unsigned long F_17 ( unsigned long V_21 , int V_5 )
{
unsigned long j0 = V_26 ;
return F_14 ( V_21 + j0 , V_5 , false ) - j0 ;
}
unsigned long F_18 ( unsigned long V_21 )
{
return F_14 ( V_21 , F_19 () , false ) ;
}
unsigned long F_20 ( unsigned long V_21 )
{
return F_17 ( V_21 , F_19 () ) ;
}
unsigned long F_21 ( unsigned long V_21 , int V_5 )
{
return F_14 ( V_21 , V_5 , true ) ;
}
unsigned long F_22 ( unsigned long V_21 , int V_5 )
{
unsigned long j0 = V_26 ;
return F_14 ( V_21 + j0 , V_5 , true ) - j0 ;
}
unsigned long F_23 ( unsigned long V_21 )
{
return F_14 ( V_21 , F_19 () , true ) ;
}
unsigned long F_24 ( unsigned long V_21 )
{
return F_22 ( V_21 , F_19 () ) ;
}
void F_25 ( struct V_27 * V_28 , int V_29 )
{
V_28 -> V_30 = V_29 ;
}
static void
F_26 ( struct V_18 * V_19 , struct V_27 * V_28 )
{
unsigned long V_31 = V_28 -> V_31 ;
unsigned long V_32 = V_31 - V_19 -> V_33 ;
struct V_34 * V_35 ;
if ( V_32 < V_36 ) {
int V_37 = V_31 & V_38 ;
V_35 = V_19 -> V_39 . V_35 + V_37 ;
} else if ( V_32 < 1 << ( V_40 + V_41 ) ) {
int V_37 = ( V_31 >> V_40 ) & V_42 ;
V_35 = V_19 -> V_43 . V_35 + V_37 ;
} else if ( V_32 < 1 << ( V_40 + 2 * V_41 ) ) {
int V_37 = ( V_31 >> ( V_40 + V_41 ) ) & V_42 ;
V_35 = V_19 -> V_44 . V_35 + V_37 ;
} else if ( V_32 < 1 << ( V_40 + 3 * V_41 ) ) {
int V_37 = ( V_31 >> ( V_40 + 2 * V_41 ) ) & V_42 ;
V_35 = V_19 -> V_45 . V_35 + V_37 ;
} else if ( ( signed long ) V_32 < 0 ) {
V_35 = V_19 -> V_39 . V_35 + ( V_19 -> V_33 & V_38 ) ;
} else {
int V_37 ;
if ( V_32 > V_46 ) {
V_32 = V_46 ;
V_31 = V_32 + V_19 -> V_33 ;
}
V_37 = ( V_31 >> ( V_40 + 3 * V_41 ) ) & V_42 ;
V_35 = V_19 -> V_47 . V_35 + V_37 ;
}
F_27 ( & V_28 -> V_48 , V_35 ) ;
}
static void F_28 ( struct V_18 * V_19 , struct V_27 * V_28 )
{
if ( ! V_19 -> V_49 ++ )
V_19 -> V_33 = V_26 ;
F_26 ( V_19 , V_28 ) ;
if ( ! ( V_28 -> V_50 & V_51 ) ) {
if ( ! V_19 -> V_52 ++ ||
F_29 ( V_28 -> V_31 , V_19 -> V_53 ) )
V_19 -> V_53 = V_28 -> V_31 ;
}
if ( V_19 -> V_9 ) {
if ( ! ( V_28 -> V_50 & V_51 ) ||
F_30 ( V_19 -> V_5 ) )
F_31 ( V_19 -> V_5 ) ;
}
}
void F_32 ( struct V_27 * V_28 , void * V_54 )
{
if ( V_28 -> V_55 )
return;
V_28 -> V_55 = V_54 ;
memcpy ( V_28 -> V_56 , V_57 -> V_58 , V_59 ) ;
V_28 -> V_60 = V_57 -> V_61 ;
}
static void F_33 ( struct V_27 * V_28 )
{
if ( F_34 ( ! V_28 -> V_55 ) )
return;
F_35 ( V_28 , V_28 -> V_60 , V_28 -> V_55 ,
V_28 -> V_62 , V_28 -> V_56 ,
V_28 -> V_50 ) ;
}
static void F_33 ( struct V_27 * V_28 ) {}
static void * F_36 ( void * V_54 )
{
return ( (struct V_27 * ) V_54 ) -> V_62 ;
}
static int F_37 ( void * V_54 , enum V_63 V_64 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_64 ) {
case V_65 :
F_38 ( V_28 ) ;
F_39 ( V_28 , & V_66 ) ;
return 1 ;
default:
return 0 ;
}
}
static void F_40 ( unsigned long V_67 )
{
F_41 ( 1 ) ;
}
static int F_42 ( void * V_54 , enum V_63 V_64 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_64 ) {
case V_68 :
if ( V_28 -> V_48 . V_69 == NULL &&
V_28 -> V_48 . V_70 == V_71 ) {
F_39 ( V_28 , & V_66 ) ;
F_43 ( V_28 , & V_66 ) ;
return 0 ;
} else {
F_44 ( V_28 , F_40 , 0 ) ;
return 1 ;
}
return 0 ;
case V_65 :
F_41 ( 1 ) ;
default:
return 0 ;
}
}
static int F_45 ( void * V_54 , enum V_63 V_64 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_64 ) {
case V_65 :
F_38 ( V_28 ) ;
F_46 ( V_28 , & V_66 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_47 ( void * V_54 , enum V_63 V_64 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_64 ) {
case V_68 :
if ( V_28 -> V_48 . V_70 == V_71 ) {
F_39 ( V_28 , & V_66 ) ;
return 0 ;
} else {
F_44 ( V_28 , F_40 , 0 ) ;
return 1 ;
}
default:
return 0 ;
}
}
static inline void F_48 ( struct V_27 * V_28 )
{
F_39 ( V_28 , & V_66 ) ;
}
static inline void F_49 ( struct V_27 * V_28 )
{
F_43 ( V_28 , & V_66 ) ;
}
static inline void F_50 ( struct V_27 * V_28 )
{
F_51 ( V_28 , & V_66 ) ;
}
static inline void F_52 ( struct V_27 * V_28 )
{
F_46 ( V_28 , & V_66 ) ;
}
static inline void F_53 ( struct V_27 * V_28 )
{
F_54 ( V_28 , & V_66 ) ;
}
void F_55 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_72 , struct V_73 * V_74 )
{
F_56 ( V_28 , & V_66 ) ;
F_57 ( V_28 , V_50 , V_72 , V_74 ) ;
}
void F_58 ( struct V_27 * V_28 )
{
F_46 ( V_28 , & V_66 ) ;
}
static inline void F_48 ( struct V_27 * V_28 ) { }
static inline void F_49 ( struct V_27 * V_28 ) { }
static inline void F_50 ( struct V_27 * V_28 ) { }
static inline void F_53 ( struct V_27 * V_28 ) { }
static inline void F_59 ( struct V_27 * V_28 )
{
F_48 ( V_28 ) ;
F_60 ( V_28 ) ;
}
static inline void
F_61 ( struct V_27 * V_28 , unsigned long V_31 )
{
F_49 ( V_28 ) ;
F_62 ( V_28 , V_31 , V_28 -> V_50 ) ;
}
static inline void F_63 ( struct V_27 * V_28 )
{
F_50 ( V_28 ) ;
F_64 ( V_28 ) ;
}
static inline void F_65 ( struct V_27 * V_28 )
{
F_53 ( V_28 ) ;
}
static void F_57 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_72 , struct V_73 * V_74 )
{
V_28 -> V_48 . V_69 = NULL ;
V_28 -> V_50 = V_50 | F_19 () ;
V_28 -> V_30 = - 1 ;
#ifdef F_66
V_28 -> V_55 = NULL ;
V_28 -> V_60 = - 1 ;
memset ( V_28 -> V_56 , 0 , V_59 ) ;
#endif
F_67 ( & V_28 -> V_75 , V_72 , V_74 , 0 ) ;
}
void F_68 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_72 , struct V_73 * V_74 )
{
F_59 ( V_28 ) ;
F_57 ( V_28 , V_50 , V_72 , V_74 ) ;
}
static inline void F_69 ( struct V_27 * V_28 , bool V_76 )
{
struct V_77 * V_48 = & V_28 -> V_48 ;
F_63 ( V_28 ) ;
F_70 ( V_48 ) ;
if ( V_76 )
V_48 -> V_69 = NULL ;
V_48 -> V_70 = V_78 ;
}
static inline void
F_71 ( struct V_27 * V_28 , struct V_18 * V_19 )
{
F_69 ( V_28 , true ) ;
if ( ! ( V_28 -> V_50 & V_51 ) )
V_19 -> V_52 -- ;
V_19 -> V_49 -- ;
}
static int F_72 ( struct V_27 * V_28 , struct V_18 * V_19 ,
bool V_76 )
{
if ( ! F_73 ( V_28 ) )
return 0 ;
F_69 ( V_28 , V_76 ) ;
if ( ! ( V_28 -> V_50 & V_51 ) ) {
V_19 -> V_52 -- ;
if ( V_28 -> V_31 == V_19 -> V_53 )
V_19 -> V_53 = V_19 -> V_33 ;
}
if ( ! -- V_19 -> V_49 )
V_19 -> V_33 = V_26 ;
return 1 ;
}
static struct V_18 * F_74 ( struct V_27 * V_28 ,
unsigned long * V_50 )
__acquires( V_28 -> V_19 -> V_79 )
{
for (; ; ) {
T_4 V_80 = V_28 -> V_50 ;
struct V_18 * V_19 ;
if ( ! ( V_80 & V_81 ) ) {
V_19 = F_12 ( & V_6 , V_80 & V_82 ) ;
F_75 ( & V_19 -> V_79 , * V_50 ) ;
if ( V_28 -> V_50 == V_80 )
return V_19 ;
F_76 ( & V_19 -> V_79 , * V_50 ) ;
}
F_77 () ;
}
}
static inline int
F_78 ( struct V_27 * V_28 , unsigned long V_31 ,
bool V_83 , int V_20 )
{
struct V_18 * V_19 , * V_84 ;
unsigned long V_50 ;
int V_17 = 0 ;
F_79 ( V_28 ) ;
F_80 ( ! V_28 -> V_62 ) ;
V_19 = F_74 ( V_28 , & V_50 ) ;
V_17 = F_72 ( V_28 , V_19 , false ) ;
if ( ! V_17 && V_83 )
goto V_85;
F_61 ( V_28 , V_31 ) ;
V_84 = F_10 ( V_19 , V_20 ) ;
if ( V_19 != V_84 ) {
if ( F_34 ( V_19 -> V_86 != V_28 ) ) {
V_28 -> V_50 |= V_81 ;
F_81 ( & V_19 -> V_79 ) ;
V_19 = V_84 ;
F_82 ( & V_19 -> V_79 ) ;
F_83 ( V_28 -> V_50 ,
( V_28 -> V_50 & ~ V_87 ) | V_19 -> V_5 ) ;
}
}
V_28 -> V_31 = V_31 ;
F_28 ( V_19 , V_28 ) ;
V_85:
F_76 ( & V_19 -> V_79 , V_50 ) ;
return V_17 ;
}
int F_84 ( struct V_27 * V_28 , unsigned long V_31 )
{
return F_78 ( V_28 , V_31 , true , V_88 ) ;
}
static inline
unsigned long F_85 ( struct V_27 * V_28 , unsigned long V_31 )
{
unsigned long V_89 , V_90 ;
int V_91 ;
if ( V_28 -> V_30 >= 0 ) {
V_89 = V_31 + V_28 -> V_30 ;
} else {
long V_92 = V_31 - V_26 ;
if ( V_92 < 256 )
return V_31 ;
V_89 = V_31 + V_92 / 256 ;
}
V_90 = V_31 ^ V_89 ;
if ( V_90 == 0 )
return V_31 ;
V_91 = F_86 ( & V_90 , V_93 ) ;
V_90 = ( 1UL << V_91 ) - 1 ;
V_89 = V_89 & ~ ( V_90 ) ;
return V_89 ;
}
int F_87 ( struct V_27 * V_28 , unsigned long V_31 )
{
V_31 = F_85 ( V_28 , V_31 ) ;
if ( F_73 ( V_28 ) && V_28 -> V_31 == V_31 )
return 1 ;
return F_78 ( V_28 , V_31 , false , V_88 ) ;
}
int F_88 ( struct V_27 * V_28 , unsigned long V_31 )
{
if ( V_28 -> V_31 == V_31 && F_73 ( V_28 ) )
return 1 ;
return F_78 ( V_28 , V_31 , false , V_94 ) ;
}
void F_89 ( struct V_27 * V_28 )
{
F_80 ( F_73 ( V_28 ) ) ;
F_87 ( V_28 , V_28 -> V_31 ) ;
}
void F_90 ( struct V_27 * V_28 , int V_5 )
{
struct V_18 * V_19 = F_12 ( & V_6 , V_5 ) ;
unsigned long V_50 ;
F_79 ( V_28 ) ;
F_80 ( F_73 ( V_28 ) || ! V_28 -> V_62 ) ;
F_75 ( & V_19 -> V_79 , V_50 ) ;
V_28 -> V_50 = ( V_28 -> V_50 & ~ V_87 ) | V_5 ;
F_61 ( V_28 , V_28 -> V_31 ) ;
F_28 ( V_19 , V_28 ) ;
F_76 ( & V_19 -> V_79 , V_50 ) ;
}
int F_91 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
unsigned long V_50 ;
int V_17 = 0 ;
F_65 ( V_28 ) ;
F_92 ( V_28 ) ;
if ( F_73 ( V_28 ) ) {
V_19 = F_74 ( V_28 , & V_50 ) ;
V_17 = F_72 ( V_28 , V_19 , true ) ;
F_76 ( & V_19 -> V_79 , V_50 ) ;
}
return V_17 ;
}
int F_93 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
unsigned long V_50 ;
int V_17 = - 1 ;
F_65 ( V_28 ) ;
V_19 = F_74 ( V_28 , & V_50 ) ;
if ( V_19 -> V_86 != V_28 ) {
F_92 ( V_28 ) ;
V_17 = F_72 ( V_28 , V_19 , true ) ;
}
F_76 ( & V_19 -> V_79 , V_50 ) ;
return V_17 ;
}
int F_38 ( struct V_27 * V_28 )
{
#ifdef F_94
unsigned long V_50 ;
F_95 ( V_50 ) ;
F_96 ( & V_28 -> V_75 ) ;
F_97 ( & V_28 -> V_75 ) ;
F_98 ( V_50 ) ;
#endif
F_41 ( F_99 () && ! ( V_28 -> V_50 & V_95 ) ) ;
for (; ; ) {
int V_17 = F_93 ( V_28 ) ;
if ( V_17 >= 0 )
return V_17 ;
F_77 () ;
}
}
static int F_100 ( struct V_18 * V_19 , struct V_96 * V_97 , int V_98 )
{
struct V_27 * V_28 ;
struct V_77 * V_99 ;
struct V_34 V_100 ;
F_101 ( V_97 -> V_35 + V_98 , & V_100 ) ;
F_102 (timer, tmp, &tv_list, entry) {
F_26 ( V_19 , V_28 ) ;
}
return V_98 ;
}
static void F_103 ( struct V_27 * V_28 , void (* F_104)( unsigned long ) ,
unsigned long V_67 )
{
int V_101 = F_105 () ;
#ifdef F_94
struct V_75 V_75 ;
F_106 ( & V_75 , & V_28 -> V_75 ) ;
#endif
F_96 ( & V_75 ) ;
F_107 ( V_28 ) ;
F_104 ( V_67 ) ;
F_108 ( V_28 ) ;
F_97 ( & V_75 ) ;
if ( V_101 != F_105 () ) {
F_109 ( 1 , L_1 ,
F_104 , V_101 , F_105 () ) ;
F_110 ( V_101 ) ;
}
}
static inline void F_111 ( struct V_18 * V_19 )
{
struct V_27 * V_28 ;
F_112 ( & V_19 -> V_79 ) ;
while ( F_113 ( V_26 , V_19 -> V_33 ) ) {
struct V_34 V_102 ;
struct V_34 * V_103 = & V_102 ;
int V_98 ;
if ( ! V_19 -> V_49 ) {
V_19 -> V_33 = V_26 ;
break;
}
V_98 = V_19 -> V_33 & V_38 ;
if ( ! V_98 &&
( ! F_100 ( V_19 , & V_19 -> V_43 , F_114 ( 0 ) ) ) &&
( ! F_100 ( V_19 , & V_19 -> V_44 , F_114 ( 1 ) ) ) &&
! F_100 ( V_19 , & V_19 -> V_45 , F_114 ( 2 ) ) )
F_100 ( V_19 , & V_19 -> V_47 , F_114 ( 3 ) ) ;
++ V_19 -> V_33 ;
F_101 ( V_19 -> V_39 . V_35 + V_98 , V_103 ) ;
while ( ! F_115 ( V_103 ) ) {
void (* F_104)( unsigned long );
unsigned long V_67 ;
bool V_104 ;
V_28 = F_116 ( V_103 -> V_105 , struct V_27 , V_48 ) ;
F_104 = V_28 -> V_62 ;
V_67 = V_28 -> V_67 ;
V_104 = V_28 -> V_50 & V_95 ;
F_33 ( V_28 ) ;
V_19 -> V_86 = V_28 ;
F_71 ( V_28 , V_19 ) ;
if ( V_104 ) {
F_81 ( & V_19 -> V_79 ) ;
F_103 ( V_28 , F_104 , V_67 ) ;
F_82 ( & V_19 -> V_79 ) ;
} else {
F_117 ( & V_19 -> V_79 ) ;
F_103 ( V_28 , F_104 , V_67 ) ;
F_112 ( & V_19 -> V_79 ) ;
}
}
}
V_19 -> V_86 = NULL ;
F_117 ( & V_19 -> V_79 ) ;
}
static unsigned long F_118 ( struct V_18 * V_19 )
{
unsigned long V_33 = V_19 -> V_33 ;
unsigned long V_31 = V_33 + V_106 ;
int V_98 , V_107 , V_108 , V_109 = 0 ;
struct V_27 * V_110 ;
struct V_96 * V_111 [ 4 ] ;
V_98 = V_107 = V_33 & V_38 ;
do {
F_119 (nte, base->tv1.vec + slot, entry) {
if ( V_110 -> V_50 & V_51 )
continue;
V_109 = 1 ;
V_31 = V_110 -> V_31 ;
if ( ! V_98 || V_107 < V_98 )
goto F_100;
return V_31 ;
}
V_107 = ( V_107 + 1 ) & V_38 ;
} while ( V_107 != V_98 );
F_100:
if ( V_98 )
V_33 += V_36 - V_98 ;
V_33 >>= V_40 ;
V_111 [ 0 ] = & V_19 -> V_43 ;
V_111 [ 1 ] = & V_19 -> V_44 ;
V_111 [ 2 ] = & V_19 -> V_45 ;
V_111 [ 3 ] = & V_19 -> V_47 ;
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
struct V_96 * V_112 = V_111 [ V_108 ] ;
V_98 = V_107 = V_33 & V_42 ;
do {
F_119 (nte, varp->vec + slot, entry) {
if ( V_110 -> V_50 & V_51 )
continue;
V_109 = 1 ;
if ( F_29 ( V_110 -> V_31 , V_31 ) )
V_31 = V_110 -> V_31 ;
}
if ( V_109 ) {
if ( ! V_98 || V_107 < V_98 )
break;
return V_31 ;
}
V_107 = ( V_107 + 1 ) & V_42 ;
} while ( V_107 != V_98 );
if ( V_98 )
V_33 += V_113 - V_98 ;
V_33 >>= V_41 ;
}
return V_31 ;
}
static T_5 F_120 ( T_5 V_114 , T_5 V_31 )
{
T_5 V_115 = F_121 () ;
if ( V_31 <= V_115 )
return V_31 ;
if ( V_115 <= V_114 )
return V_114 ;
return F_122 ( V_115 , V_116 ) * V_116 ;
}
T_5 F_123 ( unsigned long V_117 , T_5 V_114 )
{
struct V_18 * V_19 = F_11 ( & V_6 ) ;
T_5 V_31 = V_118 ;
unsigned long V_115 ;
if ( F_124 ( F_125 () ) )
return V_31 ;
F_82 ( & V_19 -> V_79 ) ;
if ( V_19 -> V_52 ) {
if ( F_126 ( V_19 -> V_53 , V_19 -> V_33 ) )
V_19 -> V_53 = F_118 ( V_19 ) ;
V_115 = V_19 -> V_53 ;
if ( F_126 ( V_115 , V_117 ) )
V_31 = V_114 ;
else
V_31 = V_114 + ( V_115 - V_117 ) * V_116 ;
}
F_81 ( & V_19 -> V_79 ) ;
return F_120 ( V_114 , V_31 ) ;
}
void F_127 ( int V_119 )
{
struct V_120 * V_121 = V_57 ;
F_128 ( V_121 , V_119 ) ;
F_129 () ;
F_130 ( V_119 ) ;
#ifdef F_131
if ( F_99 () )
F_132 () ;
#endif
F_133 () ;
F_134 ( V_121 ) ;
}
static void F_135 ( struct V_122 * V_123 )
{
struct V_18 * V_19 = F_11 ( & V_6 ) ;
if ( F_113 ( V_26 , V_19 -> V_33 ) )
F_111 ( V_19 ) ;
}
void F_129 ( void )
{
F_136 () ;
F_137 ( V_124 ) ;
}
static void F_138 ( unsigned long V_125 )
{
F_139 ( (struct V_120 * ) V_125 ) ;
}
signed long T_6 F_140 ( signed long V_126 )
{
struct V_27 V_28 ;
unsigned long V_127 ;
switch ( V_126 )
{
case V_128 :
F_141 () ;
goto V_129;
default:
if ( V_126 < 0 ) {
F_142 ( V_130 L_2
L_3 , V_126 ) ;
F_143 () ;
V_57 -> V_64 = V_131 ;
goto V_129;
}
}
V_127 = V_126 + V_26 ;
F_144 ( & V_28 , F_138 , ( unsigned long ) V_57 ) ;
F_78 ( & V_28 , V_127 , false , V_88 ) ;
F_141 () ;
F_145 ( & V_28 ) ;
F_58 ( & V_28 ) ;
V_126 = V_127 - V_26 ;
V_129:
return V_126 < 0 ? 0 : V_126 ;
}
signed long T_6 F_146 ( signed long V_126 )
{
F_147 ( V_132 ) ;
return F_140 ( V_126 ) ;
}
signed long T_6 F_148 ( signed long V_126 )
{
F_147 ( V_133 ) ;
return F_140 ( V_126 ) ;
}
signed long T_6 F_149 ( signed long V_126 )
{
F_147 ( V_134 ) ;
return F_140 ( V_126 ) ;
}
static void F_150 ( struct V_18 * V_84 , struct V_34 * V_103 )
{
struct V_27 * V_28 ;
int V_5 = V_84 -> V_5 ;
while ( ! F_115 ( V_103 ) ) {
V_28 = F_116 ( V_103 -> V_105 , struct V_27 , V_48 ) ;
F_69 ( V_28 , false ) ;
V_28 -> V_50 = ( V_28 -> V_50 & ~ V_87 ) | V_5 ;
F_28 ( V_84 , V_28 ) ;
}
}
static void F_151 ( int V_5 )
{
struct V_18 * V_135 ;
struct V_18 * V_84 ;
int V_37 ;
F_80 ( F_152 ( V_5 ) ) ;
V_135 = F_12 ( & V_6 , V_5 ) ;
V_84 = F_153 ( & V_6 ) ;
F_112 ( & V_84 -> V_79 ) ;
F_154 ( & V_135 -> V_79 , V_136 ) ;
F_80 ( V_135 -> V_86 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
F_150 ( V_84 , V_135 -> V_39 . V_35 + V_37 ) ;
for ( V_37 = 0 ; V_37 < V_113 ; V_37 ++ ) {
F_150 ( V_84 , V_135 -> V_43 . V_35 + V_37 ) ;
F_150 ( V_84 , V_135 -> V_44 . V_35 + V_37 ) ;
F_150 ( V_84 , V_135 -> V_45 . V_35 + V_37 ) ;
F_150 ( V_84 , V_135 -> V_47 . V_35 + V_37 ) ;
}
V_135 -> V_52 = 0 ;
V_135 -> V_49 = 0 ;
F_81 ( & V_135 -> V_79 ) ;
F_117 ( & V_84 -> V_79 ) ;
F_155 ( & V_6 ) ;
}
static int F_156 ( struct V_137 * V_138 ,
unsigned long V_139 , void * V_140 )
{
switch ( V_139 ) {
case V_141 :
case V_142 :
F_151 ( ( long ) V_140 ) ;
break;
default:
break;
}
return V_143 ;
}
static inline void F_157 ( void )
{
F_158 ( F_156 , 0 ) ;
}
static inline void F_157 ( void ) { }
static void T_7 F_159 ( int V_5 )
{
struct V_18 * V_19 = F_12 ( & V_6 , V_5 ) ;
V_19 -> V_5 = V_5 ;
F_160 ( & V_19 -> V_79 ) ;
V_19 -> V_33 = V_26 ;
V_19 -> V_53 = V_19 -> V_33 ;
}
static void T_7 F_161 ( void )
{
int V_5 ;
F_3 (cpu)
F_159 ( V_5 ) ;
}
void T_7 F_162 ( void )
{
F_161 () ;
F_163 () ;
F_157 () ;
F_164 ( V_124 , F_135 ) ;
}
void F_165 ( unsigned int V_144 )
{
unsigned long V_126 = F_166 ( V_144 ) + 1 ;
while ( V_126 )
V_126 = F_149 ( V_126 ) ;
}
unsigned long F_167 ( unsigned int V_144 )
{
unsigned long V_126 = F_166 ( V_144 ) + 1 ;
while ( V_126 && ! F_168 ( V_57 ) )
V_126 = F_146 ( V_126 ) ;
return F_169 ( V_126 ) ;
}
static void T_6 F_170 ( unsigned long V_145 , unsigned long V_146 )
{
T_8 V_147 ;
unsigned long V_92 ;
V_147 = F_171 ( 0 , V_145 * V_148 ) ;
V_92 = ( V_146 - V_145 ) * V_148 ;
F_172 ( & V_147 , V_92 , V_149 ) ;
}
void T_6 F_173 ( unsigned long V_145 , unsigned long V_146 )
{
F_147 ( V_134 ) ;
F_170 ( V_145 , V_146 ) ;
}
