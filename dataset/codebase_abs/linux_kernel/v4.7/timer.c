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
void * V_62 ;
V_62 = F_34 ( V_28 -> V_55 ) ;
if ( F_35 ( ! V_62 ) )
return;
F_36 ( V_28 , V_28 -> V_60 , V_62 ,
V_28 -> V_63 , V_28 -> V_56 ,
V_28 -> V_50 ) ;
}
static void F_33 ( struct V_27 * V_28 ) {}
static void * F_37 ( void * V_54 )
{
return ( (struct V_27 * ) V_54 ) -> V_63 ;
}
static bool F_38 ( void * V_54 )
{
struct V_27 * V_28 = V_54 ;
return ( V_28 -> V_48 . V_64 == NULL &&
V_28 -> V_48 . V_65 == V_66 ) ;
}
static bool F_39 ( void * V_54 , enum V_67 V_68 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_68 ) {
case V_69 :
F_40 ( V_28 ) ;
F_41 ( V_28 , & V_70 ) ;
return true ;
default:
return false ;
}
}
static void F_42 ( unsigned long V_71 )
{
F_43 ( 1 ) ;
}
static bool F_44 ( void * V_54 , enum V_67 V_68 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_68 ) {
case V_72 :
F_45 ( V_28 , F_42 , 0 ) ;
return true ;
case V_69 :
F_43 ( 1 ) ;
default:
return false ;
}
}
static bool F_46 ( void * V_54 , enum V_67 V_68 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_68 ) {
case V_69 :
F_40 ( V_28 ) ;
F_47 ( V_28 , & V_70 ) ;
return true ;
default:
return false ;
}
}
static bool F_48 ( void * V_54 , enum V_67 V_68 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_68 ) {
case V_72 :
F_45 ( V_28 , F_42 , 0 ) ;
return true ;
default:
return false ;
}
}
static inline void F_49 ( struct V_27 * V_28 )
{
F_41 ( V_28 , & V_70 ) ;
}
static inline void F_50 ( struct V_27 * V_28 )
{
F_51 ( V_28 , & V_70 ) ;
}
static inline void F_52 ( struct V_27 * V_28 )
{
F_53 ( V_28 , & V_70 ) ;
}
static inline void F_54 ( struct V_27 * V_28 )
{
F_47 ( V_28 , & V_70 ) ;
}
static inline void F_55 ( struct V_27 * V_28 )
{
F_56 ( V_28 , & V_70 ) ;
}
void F_57 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_73 , struct V_74 * V_75 )
{
F_58 ( V_28 , & V_70 ) ;
F_59 ( V_28 , V_50 , V_73 , V_75 ) ;
}
void F_60 ( struct V_27 * V_28 )
{
F_47 ( V_28 , & V_70 ) ;
}
static inline void F_49 ( struct V_27 * V_28 ) { }
static inline void F_50 ( struct V_27 * V_28 ) { }
static inline void F_52 ( struct V_27 * V_28 ) { }
static inline void F_55 ( struct V_27 * V_28 ) { }
static inline void F_61 ( struct V_27 * V_28 )
{
F_49 ( V_28 ) ;
F_62 ( V_28 ) ;
}
static inline void
F_63 ( struct V_27 * V_28 , unsigned long V_31 )
{
F_50 ( V_28 ) ;
F_64 ( V_28 , V_31 , V_28 -> V_50 ) ;
}
static inline void F_65 ( struct V_27 * V_28 )
{
F_52 ( V_28 ) ;
F_66 ( V_28 ) ;
}
static inline void F_67 ( struct V_27 * V_28 )
{
F_55 ( V_28 ) ;
}
static void F_59 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_73 , struct V_74 * V_75 )
{
V_28 -> V_48 . V_64 = NULL ;
V_28 -> V_50 = V_50 | F_19 () ;
V_28 -> V_30 = - 1 ;
#ifdef F_68
V_28 -> V_55 = NULL ;
V_28 -> V_60 = - 1 ;
memset ( V_28 -> V_56 , 0 , V_59 ) ;
#endif
F_69 ( & V_28 -> V_76 , V_73 , V_75 , 0 ) ;
}
void F_70 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_73 , struct V_74 * V_75 )
{
F_61 ( V_28 ) ;
F_59 ( V_28 , V_50 , V_73 , V_75 ) ;
}
static inline void F_71 ( struct V_27 * V_28 , bool V_77 )
{
struct V_78 * V_48 = & V_28 -> V_48 ;
F_65 ( V_28 ) ;
F_72 ( V_48 ) ;
if ( V_77 )
V_48 -> V_64 = NULL ;
V_48 -> V_65 = V_79 ;
}
static inline void
F_73 ( struct V_27 * V_28 , struct V_18 * V_19 )
{
F_71 ( V_28 , true ) ;
if ( ! ( V_28 -> V_50 & V_51 ) )
V_19 -> V_52 -- ;
V_19 -> V_49 -- ;
}
static int F_74 ( struct V_27 * V_28 , struct V_18 * V_19 ,
bool V_77 )
{
if ( ! F_75 ( V_28 ) )
return 0 ;
F_71 ( V_28 , V_77 ) ;
if ( ! ( V_28 -> V_50 & V_51 ) ) {
V_19 -> V_52 -- ;
if ( V_28 -> V_31 == V_19 -> V_53 )
V_19 -> V_53 = V_19 -> V_33 ;
}
if ( ! -- V_19 -> V_49 )
V_19 -> V_33 = V_26 ;
return 1 ;
}
static struct V_18 * F_76 ( struct V_27 * V_28 ,
unsigned long * V_50 )
__acquires( V_28 -> V_19 -> V_80 )
{
for (; ; ) {
T_4 V_81 = V_28 -> V_50 ;
struct V_18 * V_19 ;
if ( ! ( V_81 & V_82 ) ) {
V_19 = F_12 ( & V_6 , V_81 & V_83 ) ;
F_77 ( & V_19 -> V_80 , * V_50 ) ;
if ( V_28 -> V_50 == V_81 )
return V_19 ;
F_78 ( & V_19 -> V_80 , * V_50 ) ;
}
F_79 () ;
}
}
static inline int
F_80 ( struct V_27 * V_28 , unsigned long V_31 ,
bool V_84 , int V_20 )
{
struct V_18 * V_19 , * V_85 ;
unsigned long V_50 ;
int V_17 = 0 ;
F_81 ( V_28 ) ;
F_82 ( ! V_28 -> V_63 ) ;
V_19 = F_76 ( V_28 , & V_50 ) ;
V_17 = F_74 ( V_28 , V_19 , false ) ;
if ( ! V_17 && V_84 )
goto V_86;
F_63 ( V_28 , V_31 ) ;
V_85 = F_10 ( V_19 , V_20 ) ;
if ( V_19 != V_85 ) {
if ( F_35 ( V_19 -> V_87 != V_28 ) ) {
V_28 -> V_50 |= V_82 ;
F_83 ( & V_19 -> V_80 ) ;
V_19 = V_85 ;
F_84 ( & V_19 -> V_80 ) ;
F_85 ( V_28 -> V_50 ,
( V_28 -> V_50 & ~ V_88 ) | V_19 -> V_5 ) ;
}
}
V_28 -> V_31 = V_31 ;
F_28 ( V_19 , V_28 ) ;
V_86:
F_78 ( & V_19 -> V_80 , V_50 ) ;
return V_17 ;
}
int F_86 ( struct V_27 * V_28 , unsigned long V_31 )
{
return F_80 ( V_28 , V_31 , true , V_89 ) ;
}
static inline
unsigned long F_87 ( struct V_27 * V_28 , unsigned long V_31 )
{
unsigned long V_90 , V_91 ;
int V_92 ;
if ( V_28 -> V_30 >= 0 ) {
V_90 = V_31 + V_28 -> V_30 ;
} else {
long V_93 = V_31 - V_26 ;
if ( V_93 < 256 )
return V_31 ;
V_90 = V_31 + V_93 / 256 ;
}
V_91 = V_31 ^ V_90 ;
if ( V_91 == 0 )
return V_31 ;
V_92 = F_88 ( V_91 ) ;
V_91 = ( 1UL << V_92 ) - 1 ;
V_90 = V_90 & ~ ( V_91 ) ;
return V_90 ;
}
int F_89 ( struct V_27 * V_28 , unsigned long V_31 )
{
V_31 = F_87 ( V_28 , V_31 ) ;
if ( F_75 ( V_28 ) && V_28 -> V_31 == V_31 )
return 1 ;
return F_80 ( V_28 , V_31 , false , V_89 ) ;
}
int F_90 ( struct V_27 * V_28 , unsigned long V_31 )
{
if ( V_28 -> V_31 == V_31 && F_75 ( V_28 ) )
return 1 ;
return F_80 ( V_28 , V_31 , false , V_94 ) ;
}
void F_91 ( struct V_27 * V_28 )
{
F_82 ( F_75 ( V_28 ) ) ;
F_89 ( V_28 , V_28 -> V_31 ) ;
}
void F_92 ( struct V_27 * V_28 , int V_5 )
{
struct V_18 * V_85 = F_12 ( & V_6 , V_5 ) ;
struct V_18 * V_19 ;
unsigned long V_50 ;
F_81 ( V_28 ) ;
F_82 ( F_75 ( V_28 ) || ! V_28 -> V_63 ) ;
V_19 = F_76 ( V_28 , & V_50 ) ;
if ( V_19 != V_85 ) {
V_28 -> V_50 |= V_82 ;
F_83 ( & V_19 -> V_80 ) ;
V_19 = V_85 ;
F_84 ( & V_19 -> V_80 ) ;
F_85 ( V_28 -> V_50 ,
( V_28 -> V_50 & ~ V_88 ) | V_5 ) ;
}
F_63 ( V_28 , V_28 -> V_31 ) ;
F_28 ( V_19 , V_28 ) ;
F_78 ( & V_19 -> V_80 , V_50 ) ;
}
int F_93 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
unsigned long V_50 ;
int V_17 = 0 ;
F_67 ( V_28 ) ;
F_94 ( V_28 ) ;
if ( F_75 ( V_28 ) ) {
V_19 = F_76 ( V_28 , & V_50 ) ;
V_17 = F_74 ( V_28 , V_19 , true ) ;
F_78 ( & V_19 -> V_80 , V_50 ) ;
}
return V_17 ;
}
int F_95 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
unsigned long V_50 ;
int V_17 = - 1 ;
F_67 ( V_28 ) ;
V_19 = F_76 ( V_28 , & V_50 ) ;
if ( V_19 -> V_87 != V_28 ) {
F_94 ( V_28 ) ;
V_17 = F_74 ( V_28 , V_19 , true ) ;
}
F_78 ( & V_19 -> V_80 , V_50 ) ;
return V_17 ;
}
int F_40 ( struct V_27 * V_28 )
{
#ifdef F_96
unsigned long V_50 ;
F_97 ( V_50 ) ;
F_98 ( & V_28 -> V_76 ) ;
F_99 ( & V_28 -> V_76 ) ;
F_100 ( V_50 ) ;
#endif
F_43 ( F_101 () && ! ( V_28 -> V_50 & V_95 ) ) ;
for (; ; ) {
int V_17 = F_95 ( V_28 ) ;
if ( V_17 >= 0 )
return V_17 ;
F_79 () ;
}
}
static int F_102 ( struct V_18 * V_19 , struct V_96 * V_97 , int V_98 )
{
struct V_27 * V_28 ;
struct V_78 * V_99 ;
struct V_34 V_100 ;
F_103 ( V_97 -> V_35 + V_98 , & V_100 ) ;
F_104 (timer, tmp, &tv_list, entry) {
F_26 ( V_19 , V_28 ) ;
}
return V_98 ;
}
static void F_105 ( struct V_27 * V_28 , void (* F_106)( unsigned long ) ,
unsigned long V_71 )
{
int V_101 = F_107 () ;
#ifdef F_96
struct V_76 V_76 ;
F_108 ( & V_76 , & V_28 -> V_76 ) ;
#endif
F_98 ( & V_76 ) ;
F_109 ( V_28 ) ;
F_106 ( V_71 ) ;
F_110 ( V_28 ) ;
F_99 ( & V_76 ) ;
if ( V_101 != F_107 () ) {
F_111 ( 1 , L_1 ,
F_106 , V_101 , F_107 () ) ;
F_112 ( V_101 ) ;
}
}
static inline void F_113 ( struct V_18 * V_19 )
{
struct V_27 * V_28 ;
F_114 ( & V_19 -> V_80 ) ;
while ( F_115 ( V_26 , V_19 -> V_33 ) ) {
struct V_34 V_102 ;
struct V_34 * V_103 = & V_102 ;
int V_98 ;
if ( ! V_19 -> V_49 ) {
V_19 -> V_33 = V_26 ;
break;
}
V_98 = V_19 -> V_33 & V_38 ;
if ( ! V_98 &&
( ! F_102 ( V_19 , & V_19 -> V_43 , F_116 ( 0 ) ) ) &&
( ! F_102 ( V_19 , & V_19 -> V_44 , F_116 ( 1 ) ) ) &&
! F_102 ( V_19 , & V_19 -> V_45 , F_116 ( 2 ) ) )
F_102 ( V_19 , & V_19 -> V_47 , F_116 ( 3 ) ) ;
++ V_19 -> V_33 ;
F_103 ( V_19 -> V_39 . V_35 + V_98 , V_103 ) ;
while ( ! F_117 ( V_103 ) ) {
void (* F_106)( unsigned long );
unsigned long V_71 ;
bool V_104 ;
V_28 = F_118 ( V_103 -> V_105 , struct V_27 , V_48 ) ;
F_106 = V_28 -> V_63 ;
V_71 = V_28 -> V_71 ;
V_104 = V_28 -> V_50 & V_95 ;
F_33 ( V_28 ) ;
V_19 -> V_87 = V_28 ;
F_73 ( V_28 , V_19 ) ;
if ( V_104 ) {
F_83 ( & V_19 -> V_80 ) ;
F_105 ( V_28 , F_106 , V_71 ) ;
F_84 ( & V_19 -> V_80 ) ;
} else {
F_119 ( & V_19 -> V_80 ) ;
F_105 ( V_28 , F_106 , V_71 ) ;
F_114 ( & V_19 -> V_80 ) ;
}
}
}
V_19 -> V_87 = NULL ;
F_119 ( & V_19 -> V_80 ) ;
}
static unsigned long F_120 ( struct V_18 * V_19 )
{
unsigned long V_33 = V_19 -> V_33 ;
unsigned long V_31 = V_33 + V_106 ;
int V_98 , V_107 , V_108 , V_109 = 0 ;
struct V_27 * V_110 ;
struct V_96 * V_111 [ 4 ] ;
V_98 = V_107 = V_33 & V_38 ;
do {
F_121 (nte, base->tv1.vec + slot, entry) {
if ( V_110 -> V_50 & V_51 )
continue;
V_109 = 1 ;
V_31 = V_110 -> V_31 ;
if ( ! V_98 || V_107 < V_98 )
goto F_102;
return V_31 ;
}
V_107 = ( V_107 + 1 ) & V_38 ;
} while ( V_107 != V_98 );
F_102:
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
F_121 (nte, varp->vec + slot, entry) {
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
static T_5 F_122 ( T_5 V_114 , T_5 V_31 )
{
T_5 V_115 = F_123 () ;
if ( V_31 <= V_115 )
return V_31 ;
if ( V_115 <= V_114 )
return V_114 ;
return F_124 ( V_115 , V_116 ) * V_116 ;
}
T_5 F_125 ( unsigned long V_117 , T_5 V_114 )
{
struct V_18 * V_19 = F_11 ( & V_6 ) ;
T_5 V_31 = V_118 ;
unsigned long V_115 ;
if ( F_126 ( F_127 () ) )
return V_31 ;
F_84 ( & V_19 -> V_80 ) ;
if ( V_19 -> V_52 ) {
if ( F_128 ( V_19 -> V_53 , V_19 -> V_33 ) )
V_19 -> V_53 = F_120 ( V_19 ) ;
V_115 = V_19 -> V_53 ;
if ( F_128 ( V_115 , V_117 ) )
V_31 = V_114 ;
else
V_31 = V_114 + ( V_115 - V_117 ) * V_116 ;
}
F_83 ( & V_19 -> V_80 ) ;
return F_122 ( V_114 , V_31 ) ;
}
void F_129 ( int V_119 )
{
struct V_120 * V_121 = V_57 ;
F_130 ( V_121 , V_119 ) ;
F_131 () ;
F_132 ( V_119 ) ;
#ifdef F_133
if ( F_101 () )
F_134 () ;
#endif
F_135 () ;
F_136 ( V_121 ) ;
}
static void F_137 ( struct V_122 * V_123 )
{
struct V_18 * V_19 = F_11 ( & V_6 ) ;
if ( F_115 ( V_26 , V_19 -> V_33 ) )
F_113 ( V_19 ) ;
}
void F_131 ( void )
{
F_138 () ;
F_139 ( V_124 ) ;
}
static void F_140 ( unsigned long V_125 )
{
F_141 ( (struct V_120 * ) V_125 ) ;
}
signed long T_6 F_142 ( signed long V_126 )
{
struct V_27 V_28 ;
unsigned long V_127 ;
switch ( V_126 )
{
case V_128 :
F_143 () ;
goto V_129;
default:
if ( V_126 < 0 ) {
F_144 ( V_130 L_2
L_3 , V_126 ) ;
F_145 () ;
V_57 -> V_68 = V_131 ;
goto V_129;
}
}
V_127 = V_126 + V_26 ;
F_146 ( & V_28 , F_140 , ( unsigned long ) V_57 ) ;
F_80 ( & V_28 , V_127 , false , V_89 ) ;
F_143 () ;
F_147 ( & V_28 ) ;
F_60 ( & V_28 ) ;
V_126 = V_127 - V_26 ;
V_129:
return V_126 < 0 ? 0 : V_126 ;
}
signed long T_6 F_148 ( signed long V_126 )
{
F_149 ( V_132 ) ;
return F_142 ( V_126 ) ;
}
signed long T_6 F_150 ( signed long V_126 )
{
F_149 ( V_133 ) ;
return F_142 ( V_126 ) ;
}
signed long T_6 F_151 ( signed long V_126 )
{
F_149 ( V_134 ) ;
return F_142 ( V_126 ) ;
}
signed long T_6 F_152 ( signed long V_126 )
{
F_149 ( V_135 ) ;
return F_142 ( V_126 ) ;
}
static void F_153 ( struct V_18 * V_85 , struct V_34 * V_103 )
{
struct V_27 * V_28 ;
int V_5 = V_85 -> V_5 ;
while ( ! F_117 ( V_103 ) ) {
V_28 = F_118 ( V_103 -> V_105 , struct V_27 , V_48 ) ;
F_71 ( V_28 , false ) ;
V_28 -> V_50 = ( V_28 -> V_50 & ~ V_88 ) | V_5 ;
F_28 ( V_85 , V_28 ) ;
}
}
static void F_154 ( int V_5 )
{
struct V_18 * V_136 ;
struct V_18 * V_85 ;
int V_37 ;
F_82 ( F_155 ( V_5 ) ) ;
V_136 = F_12 ( & V_6 , V_5 ) ;
V_85 = F_156 ( & V_6 ) ;
F_114 ( & V_85 -> V_80 ) ;
F_157 ( & V_136 -> V_80 , V_137 ) ;
F_82 ( V_136 -> V_87 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
F_153 ( V_85 , V_136 -> V_39 . V_35 + V_37 ) ;
for ( V_37 = 0 ; V_37 < V_113 ; V_37 ++ ) {
F_153 ( V_85 , V_136 -> V_43 . V_35 + V_37 ) ;
F_153 ( V_85 , V_136 -> V_44 . V_35 + V_37 ) ;
F_153 ( V_85 , V_136 -> V_45 . V_35 + V_37 ) ;
F_153 ( V_85 , V_136 -> V_47 . V_35 + V_37 ) ;
}
V_136 -> V_52 = 0 ;
V_136 -> V_49 = 0 ;
F_83 ( & V_136 -> V_80 ) ;
F_119 ( & V_85 -> V_80 ) ;
F_158 ( & V_6 ) ;
}
static int F_159 ( struct V_138 * V_139 ,
unsigned long V_140 , void * V_141 )
{
switch ( V_140 ) {
case V_142 :
case V_143 :
F_154 ( ( long ) V_141 ) ;
break;
default:
break;
}
return V_144 ;
}
static inline void F_160 ( void )
{
F_161 ( F_159 , 0 ) ;
}
static inline void F_160 ( void ) { }
static void T_7 F_162 ( int V_5 )
{
struct V_18 * V_19 = F_12 ( & V_6 , V_5 ) ;
V_19 -> V_5 = V_5 ;
F_163 ( & V_19 -> V_80 ) ;
V_19 -> V_33 = V_26 ;
V_19 -> V_53 = V_19 -> V_33 ;
}
static void T_7 F_164 ( void )
{
int V_5 ;
F_3 (cpu)
F_162 ( V_5 ) ;
}
void T_7 F_165 ( void )
{
F_164 () ;
F_166 () ;
F_160 () ;
F_167 ( V_124 , F_137 ) ;
}
void F_168 ( unsigned int V_145 )
{
unsigned long V_126 = F_169 ( V_145 ) + 1 ;
while ( V_126 )
V_126 = F_151 ( V_126 ) ;
}
unsigned long F_170 ( unsigned int V_145 )
{
unsigned long V_126 = F_169 ( V_145 ) + 1 ;
while ( V_126 && ! F_171 ( V_57 ) )
V_126 = F_148 ( V_126 ) ;
return F_172 ( V_126 ) ;
}
static void T_6 F_173 ( unsigned long V_146 , unsigned long V_147 )
{
T_8 V_148 ;
T_5 V_93 ;
V_148 = F_174 ( 0 , V_146 * V_149 ) ;
V_93 = ( T_5 ) ( V_147 - V_146 ) * V_149 ;
F_175 ( & V_148 , V_93 , V_150 ) ;
}
void T_6 F_176 ( unsigned long V_146 , unsigned long V_147 )
{
F_149 ( V_134 ) ;
F_173 ( V_146 , V_147 ) ;
}
