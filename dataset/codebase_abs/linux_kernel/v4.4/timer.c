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
static int F_38 ( void * V_54 , enum V_64 V_65 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_65 ) {
case V_66 :
F_39 ( V_28 ) ;
F_40 ( V_28 , & V_67 ) ;
return 1 ;
default:
return 0 ;
}
}
static void F_41 ( unsigned long V_68 )
{
F_42 ( 1 ) ;
}
static int F_43 ( void * V_54 , enum V_64 V_65 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_65 ) {
case V_69 :
if ( V_28 -> V_48 . V_70 == NULL &&
V_28 -> V_48 . V_71 == V_72 ) {
F_40 ( V_28 , & V_67 ) ;
F_44 ( V_28 , & V_67 ) ;
return 0 ;
} else {
F_45 ( V_28 , F_41 , 0 ) ;
return 1 ;
}
return 0 ;
case V_66 :
F_42 ( 1 ) ;
default:
return 0 ;
}
}
static int F_46 ( void * V_54 , enum V_64 V_65 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_65 ) {
case V_66 :
F_39 ( V_28 ) ;
F_47 ( V_28 , & V_67 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_48 ( void * V_54 , enum V_64 V_65 )
{
struct V_27 * V_28 = V_54 ;
switch ( V_65 ) {
case V_69 :
if ( V_28 -> V_48 . V_71 == V_72 ) {
F_40 ( V_28 , & V_67 ) ;
return 0 ;
} else {
F_45 ( V_28 , F_41 , 0 ) ;
return 1 ;
}
default:
return 0 ;
}
}
static inline void F_49 ( struct V_27 * V_28 )
{
F_40 ( V_28 , & V_67 ) ;
}
static inline void F_50 ( struct V_27 * V_28 )
{
F_44 ( V_28 , & V_67 ) ;
}
static inline void F_51 ( struct V_27 * V_28 )
{
F_52 ( V_28 , & V_67 ) ;
}
static inline void F_53 ( struct V_27 * V_28 )
{
F_47 ( V_28 , & V_67 ) ;
}
static inline void F_54 ( struct V_27 * V_28 )
{
F_55 ( V_28 , & V_67 ) ;
}
void F_56 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_73 , struct V_74 * V_75 )
{
F_57 ( V_28 , & V_67 ) ;
F_58 ( V_28 , V_50 , V_73 , V_75 ) ;
}
void F_59 ( struct V_27 * V_28 )
{
F_47 ( V_28 , & V_67 ) ;
}
static inline void F_49 ( struct V_27 * V_28 ) { }
static inline void F_50 ( struct V_27 * V_28 ) { }
static inline void F_51 ( struct V_27 * V_28 ) { }
static inline void F_54 ( struct V_27 * V_28 ) { }
static inline void F_60 ( struct V_27 * V_28 )
{
F_49 ( V_28 ) ;
F_61 ( V_28 ) ;
}
static inline void
F_62 ( struct V_27 * V_28 , unsigned long V_31 )
{
F_50 ( V_28 ) ;
F_63 ( V_28 , V_31 , V_28 -> V_50 ) ;
}
static inline void F_64 ( struct V_27 * V_28 )
{
F_51 ( V_28 ) ;
F_65 ( V_28 ) ;
}
static inline void F_66 ( struct V_27 * V_28 )
{
F_54 ( V_28 ) ;
}
static void F_58 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_73 , struct V_74 * V_75 )
{
V_28 -> V_48 . V_70 = NULL ;
V_28 -> V_50 = V_50 | F_19 () ;
V_28 -> V_30 = - 1 ;
#ifdef F_67
V_28 -> V_55 = NULL ;
V_28 -> V_60 = - 1 ;
memset ( V_28 -> V_56 , 0 , V_59 ) ;
#endif
F_68 ( & V_28 -> V_76 , V_73 , V_75 , 0 ) ;
}
void F_69 ( struct V_27 * V_28 , unsigned int V_50 ,
const char * V_73 , struct V_74 * V_75 )
{
F_60 ( V_28 ) ;
F_58 ( V_28 , V_50 , V_73 , V_75 ) ;
}
static inline void F_70 ( struct V_27 * V_28 , bool V_77 )
{
struct V_78 * V_48 = & V_28 -> V_48 ;
F_64 ( V_28 ) ;
F_71 ( V_48 ) ;
if ( V_77 )
V_48 -> V_70 = NULL ;
V_48 -> V_71 = V_79 ;
}
static inline void
F_72 ( struct V_27 * V_28 , struct V_18 * V_19 )
{
F_70 ( V_28 , true ) ;
if ( ! ( V_28 -> V_50 & V_51 ) )
V_19 -> V_52 -- ;
V_19 -> V_49 -- ;
}
static int F_73 ( struct V_27 * V_28 , struct V_18 * V_19 ,
bool V_77 )
{
if ( ! F_74 ( V_28 ) )
return 0 ;
F_70 ( V_28 , V_77 ) ;
if ( ! ( V_28 -> V_50 & V_51 ) ) {
V_19 -> V_52 -- ;
if ( V_28 -> V_31 == V_19 -> V_53 )
V_19 -> V_53 = V_19 -> V_33 ;
}
if ( ! -- V_19 -> V_49 )
V_19 -> V_33 = V_26 ;
return 1 ;
}
static struct V_18 * F_75 ( struct V_27 * V_28 ,
unsigned long * V_50 )
__acquires( V_28 -> V_19 -> V_80 )
{
for (; ; ) {
T_4 V_81 = V_28 -> V_50 ;
struct V_18 * V_19 ;
if ( ! ( V_81 & V_82 ) ) {
V_19 = F_12 ( & V_6 , V_81 & V_83 ) ;
F_76 ( & V_19 -> V_80 , * V_50 ) ;
if ( V_28 -> V_50 == V_81 )
return V_19 ;
F_77 ( & V_19 -> V_80 , * V_50 ) ;
}
F_78 () ;
}
}
static inline int
F_79 ( struct V_27 * V_28 , unsigned long V_31 ,
bool V_84 , int V_20 )
{
struct V_18 * V_19 , * V_85 ;
unsigned long V_50 ;
int V_17 = 0 ;
F_80 ( V_28 ) ;
F_81 ( ! V_28 -> V_63 ) ;
V_19 = F_75 ( V_28 , & V_50 ) ;
V_17 = F_73 ( V_28 , V_19 , false ) ;
if ( ! V_17 && V_84 )
goto V_86;
F_62 ( V_28 , V_31 ) ;
V_85 = F_10 ( V_19 , V_20 ) ;
if ( V_19 != V_85 ) {
if ( F_35 ( V_19 -> V_87 != V_28 ) ) {
V_28 -> V_50 |= V_82 ;
F_82 ( & V_19 -> V_80 ) ;
V_19 = V_85 ;
F_83 ( & V_19 -> V_80 ) ;
F_84 ( V_28 -> V_50 ,
( V_28 -> V_50 & ~ V_88 ) | V_19 -> V_5 ) ;
}
}
V_28 -> V_31 = V_31 ;
F_28 ( V_19 , V_28 ) ;
V_86:
F_77 ( & V_19 -> V_80 , V_50 ) ;
return V_17 ;
}
int F_85 ( struct V_27 * V_28 , unsigned long V_31 )
{
return F_79 ( V_28 , V_31 , true , V_89 ) ;
}
static inline
unsigned long F_86 ( struct V_27 * V_28 , unsigned long V_31 )
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
V_92 = F_87 ( V_91 ) ;
V_91 = ( 1UL << V_92 ) - 1 ;
V_90 = V_90 & ~ ( V_91 ) ;
return V_90 ;
}
int F_88 ( struct V_27 * V_28 , unsigned long V_31 )
{
V_31 = F_86 ( V_28 , V_31 ) ;
if ( F_74 ( V_28 ) && V_28 -> V_31 == V_31 )
return 1 ;
return F_79 ( V_28 , V_31 , false , V_89 ) ;
}
int F_89 ( struct V_27 * V_28 , unsigned long V_31 )
{
if ( V_28 -> V_31 == V_31 && F_74 ( V_28 ) )
return 1 ;
return F_79 ( V_28 , V_31 , false , V_94 ) ;
}
void F_90 ( struct V_27 * V_28 )
{
F_81 ( F_74 ( V_28 ) ) ;
F_88 ( V_28 , V_28 -> V_31 ) ;
}
void F_91 ( struct V_27 * V_28 , int V_5 )
{
struct V_18 * V_85 = F_12 ( & V_6 , V_5 ) ;
struct V_18 * V_19 ;
unsigned long V_50 ;
F_80 ( V_28 ) ;
F_81 ( F_74 ( V_28 ) || ! V_28 -> V_63 ) ;
V_19 = F_75 ( V_28 , & V_50 ) ;
if ( V_19 != V_85 ) {
V_28 -> V_50 |= V_82 ;
F_82 ( & V_19 -> V_80 ) ;
V_19 = V_85 ;
F_83 ( & V_19 -> V_80 ) ;
F_84 ( V_28 -> V_50 ,
( V_28 -> V_50 & ~ V_88 ) | V_5 ) ;
}
F_62 ( V_28 , V_28 -> V_31 ) ;
F_28 ( V_19 , V_28 ) ;
F_77 ( & V_19 -> V_80 , V_50 ) ;
}
int F_92 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
unsigned long V_50 ;
int V_17 = 0 ;
F_66 ( V_28 ) ;
F_93 ( V_28 ) ;
if ( F_74 ( V_28 ) ) {
V_19 = F_75 ( V_28 , & V_50 ) ;
V_17 = F_73 ( V_28 , V_19 , true ) ;
F_77 ( & V_19 -> V_80 , V_50 ) ;
}
return V_17 ;
}
int F_94 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
unsigned long V_50 ;
int V_17 = - 1 ;
F_66 ( V_28 ) ;
V_19 = F_75 ( V_28 , & V_50 ) ;
if ( V_19 -> V_87 != V_28 ) {
F_93 ( V_28 ) ;
V_17 = F_73 ( V_28 , V_19 , true ) ;
}
F_77 ( & V_19 -> V_80 , V_50 ) ;
return V_17 ;
}
int F_39 ( struct V_27 * V_28 )
{
#ifdef F_95
unsigned long V_50 ;
F_96 ( V_50 ) ;
F_97 ( & V_28 -> V_76 ) ;
F_98 ( & V_28 -> V_76 ) ;
F_99 ( V_50 ) ;
#endif
F_42 ( F_100 () && ! ( V_28 -> V_50 & V_95 ) ) ;
for (; ; ) {
int V_17 = F_94 ( V_28 ) ;
if ( V_17 >= 0 )
return V_17 ;
F_78 () ;
}
}
static int F_101 ( struct V_18 * V_19 , struct V_96 * V_97 , int V_98 )
{
struct V_27 * V_28 ;
struct V_78 * V_99 ;
struct V_34 V_100 ;
F_102 ( V_97 -> V_35 + V_98 , & V_100 ) ;
F_103 (timer, tmp, &tv_list, entry) {
F_26 ( V_19 , V_28 ) ;
}
return V_98 ;
}
static void F_104 ( struct V_27 * V_28 , void (* F_105)( unsigned long ) ,
unsigned long V_68 )
{
int V_101 = F_106 () ;
#ifdef F_95
struct V_76 V_76 ;
F_107 ( & V_76 , & V_28 -> V_76 ) ;
#endif
F_97 ( & V_76 ) ;
F_108 ( V_28 ) ;
F_105 ( V_68 ) ;
F_109 ( V_28 ) ;
F_98 ( & V_76 ) ;
if ( V_101 != F_106 () ) {
F_110 ( 1 , L_1 ,
F_105 , V_101 , F_106 () ) ;
F_111 ( V_101 ) ;
}
}
static inline void F_112 ( struct V_18 * V_19 )
{
struct V_27 * V_28 ;
F_113 ( & V_19 -> V_80 ) ;
while ( F_114 ( V_26 , V_19 -> V_33 ) ) {
struct V_34 V_102 ;
struct V_34 * V_103 = & V_102 ;
int V_98 ;
if ( ! V_19 -> V_49 ) {
V_19 -> V_33 = V_26 ;
break;
}
V_98 = V_19 -> V_33 & V_38 ;
if ( ! V_98 &&
( ! F_101 ( V_19 , & V_19 -> V_43 , F_115 ( 0 ) ) ) &&
( ! F_101 ( V_19 , & V_19 -> V_44 , F_115 ( 1 ) ) ) &&
! F_101 ( V_19 , & V_19 -> V_45 , F_115 ( 2 ) ) )
F_101 ( V_19 , & V_19 -> V_47 , F_115 ( 3 ) ) ;
++ V_19 -> V_33 ;
F_102 ( V_19 -> V_39 . V_35 + V_98 , V_103 ) ;
while ( ! F_116 ( V_103 ) ) {
void (* F_105)( unsigned long );
unsigned long V_68 ;
bool V_104 ;
V_28 = F_117 ( V_103 -> V_105 , struct V_27 , V_48 ) ;
F_105 = V_28 -> V_63 ;
V_68 = V_28 -> V_68 ;
V_104 = V_28 -> V_50 & V_95 ;
F_33 ( V_28 ) ;
V_19 -> V_87 = V_28 ;
F_72 ( V_28 , V_19 ) ;
if ( V_104 ) {
F_82 ( & V_19 -> V_80 ) ;
F_104 ( V_28 , F_105 , V_68 ) ;
F_83 ( & V_19 -> V_80 ) ;
} else {
F_118 ( & V_19 -> V_80 ) ;
F_104 ( V_28 , F_105 , V_68 ) ;
F_113 ( & V_19 -> V_80 ) ;
}
}
}
V_19 -> V_87 = NULL ;
F_118 ( & V_19 -> V_80 ) ;
}
static unsigned long F_119 ( struct V_18 * V_19 )
{
unsigned long V_33 = V_19 -> V_33 ;
unsigned long V_31 = V_33 + V_106 ;
int V_98 , V_107 , V_108 , V_109 = 0 ;
struct V_27 * V_110 ;
struct V_96 * V_111 [ 4 ] ;
V_98 = V_107 = V_33 & V_38 ;
do {
F_120 (nte, base->tv1.vec + slot, entry) {
if ( V_110 -> V_50 & V_51 )
continue;
V_109 = 1 ;
V_31 = V_110 -> V_31 ;
if ( ! V_98 || V_107 < V_98 )
goto F_101;
return V_31 ;
}
V_107 = ( V_107 + 1 ) & V_38 ;
} while ( V_107 != V_98 );
F_101:
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
F_120 (nte, varp->vec + slot, entry) {
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
static T_5 F_121 ( T_5 V_114 , T_5 V_31 )
{
T_5 V_115 = F_122 () ;
if ( V_31 <= V_115 )
return V_31 ;
if ( V_115 <= V_114 )
return V_114 ;
return F_123 ( V_115 , V_116 ) * V_116 ;
}
T_5 F_124 ( unsigned long V_117 , T_5 V_114 )
{
struct V_18 * V_19 = F_11 ( & V_6 ) ;
T_5 V_31 = V_118 ;
unsigned long V_115 ;
if ( F_125 ( F_126 () ) )
return V_31 ;
F_83 ( & V_19 -> V_80 ) ;
if ( V_19 -> V_52 ) {
if ( F_127 ( V_19 -> V_53 , V_19 -> V_33 ) )
V_19 -> V_53 = F_119 ( V_19 ) ;
V_115 = V_19 -> V_53 ;
if ( F_127 ( V_115 , V_117 ) )
V_31 = V_114 ;
else
V_31 = V_114 + ( V_115 - V_117 ) * V_116 ;
}
F_82 ( & V_19 -> V_80 ) ;
return F_121 ( V_114 , V_31 ) ;
}
void F_128 ( int V_119 )
{
struct V_120 * V_121 = V_57 ;
F_129 ( V_121 , V_119 ) ;
F_130 () ;
F_131 ( V_119 ) ;
#ifdef F_132
if ( F_100 () )
F_133 () ;
#endif
F_134 () ;
F_135 ( V_121 ) ;
}
static void F_136 ( struct V_122 * V_123 )
{
struct V_18 * V_19 = F_11 ( & V_6 ) ;
if ( F_114 ( V_26 , V_19 -> V_33 ) )
F_112 ( V_19 ) ;
}
void F_130 ( void )
{
F_137 () ;
F_138 ( V_124 ) ;
}
static void F_139 ( unsigned long V_125 )
{
F_140 ( (struct V_120 * ) V_125 ) ;
}
signed long T_6 F_141 ( signed long V_126 )
{
struct V_27 V_28 ;
unsigned long V_127 ;
switch ( V_126 )
{
case V_128 :
F_142 () ;
goto V_129;
default:
if ( V_126 < 0 ) {
F_143 ( V_130 L_2
L_3 , V_126 ) ;
F_144 () ;
V_57 -> V_65 = V_131 ;
goto V_129;
}
}
V_127 = V_126 + V_26 ;
F_145 ( & V_28 , F_139 , ( unsigned long ) V_57 ) ;
F_79 ( & V_28 , V_127 , false , V_89 ) ;
F_142 () ;
F_146 ( & V_28 ) ;
F_59 ( & V_28 ) ;
V_126 = V_127 - V_26 ;
V_129:
return V_126 < 0 ? 0 : V_126 ;
}
signed long T_6 F_147 ( signed long V_126 )
{
F_148 ( V_132 ) ;
return F_141 ( V_126 ) ;
}
signed long T_6 F_149 ( signed long V_126 )
{
F_148 ( V_133 ) ;
return F_141 ( V_126 ) ;
}
signed long T_6 F_150 ( signed long V_126 )
{
F_148 ( V_134 ) ;
return F_141 ( V_126 ) ;
}
static void F_151 ( struct V_18 * V_85 , struct V_34 * V_103 )
{
struct V_27 * V_28 ;
int V_5 = V_85 -> V_5 ;
while ( ! F_116 ( V_103 ) ) {
V_28 = F_117 ( V_103 -> V_105 , struct V_27 , V_48 ) ;
F_70 ( V_28 , false ) ;
V_28 -> V_50 = ( V_28 -> V_50 & ~ V_88 ) | V_5 ;
F_28 ( V_85 , V_28 ) ;
}
}
static void F_152 ( int V_5 )
{
struct V_18 * V_135 ;
struct V_18 * V_85 ;
int V_37 ;
F_81 ( F_153 ( V_5 ) ) ;
V_135 = F_12 ( & V_6 , V_5 ) ;
V_85 = F_154 ( & V_6 ) ;
F_113 ( & V_85 -> V_80 ) ;
F_155 ( & V_135 -> V_80 , V_136 ) ;
F_81 ( V_135 -> V_87 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
F_151 ( V_85 , V_135 -> V_39 . V_35 + V_37 ) ;
for ( V_37 = 0 ; V_37 < V_113 ; V_37 ++ ) {
F_151 ( V_85 , V_135 -> V_43 . V_35 + V_37 ) ;
F_151 ( V_85 , V_135 -> V_44 . V_35 + V_37 ) ;
F_151 ( V_85 , V_135 -> V_45 . V_35 + V_37 ) ;
F_151 ( V_85 , V_135 -> V_47 . V_35 + V_37 ) ;
}
V_135 -> V_52 = 0 ;
V_135 -> V_49 = 0 ;
F_82 ( & V_135 -> V_80 ) ;
F_118 ( & V_85 -> V_80 ) ;
F_156 ( & V_6 ) ;
}
static int F_157 ( struct V_137 * V_138 ,
unsigned long V_139 , void * V_140 )
{
switch ( V_139 ) {
case V_141 :
case V_142 :
F_152 ( ( long ) V_140 ) ;
break;
default:
break;
}
return V_143 ;
}
static inline void F_158 ( void )
{
F_159 ( F_157 , 0 ) ;
}
static inline void F_158 ( void ) { }
static void T_7 F_160 ( int V_5 )
{
struct V_18 * V_19 = F_12 ( & V_6 , V_5 ) ;
V_19 -> V_5 = V_5 ;
F_161 ( & V_19 -> V_80 ) ;
V_19 -> V_33 = V_26 ;
V_19 -> V_53 = V_19 -> V_33 ;
}
static void T_7 F_162 ( void )
{
int V_5 ;
F_3 (cpu)
F_160 ( V_5 ) ;
}
void T_7 F_163 ( void )
{
F_162 () ;
F_164 () ;
F_158 () ;
F_165 ( V_124 , F_136 ) ;
}
void F_166 ( unsigned int V_144 )
{
unsigned long V_126 = F_167 ( V_144 ) + 1 ;
while ( V_126 )
V_126 = F_150 ( V_126 ) ;
}
unsigned long F_168 ( unsigned int V_144 )
{
unsigned long V_126 = F_167 ( V_144 ) + 1 ;
while ( V_126 && ! F_169 ( V_57 ) )
V_126 = F_147 ( V_126 ) ;
return F_170 ( V_126 ) ;
}
static void T_6 F_171 ( unsigned long V_145 , unsigned long V_146 )
{
T_8 V_147 ;
unsigned long V_93 ;
V_147 = F_172 ( 0 , V_145 * V_148 ) ;
V_93 = ( V_146 - V_145 ) * V_148 ;
F_173 ( & V_147 , V_93 , V_149 ) ;
}
void T_6 F_174 ( unsigned long V_145 , unsigned long V_146 )
{
F_148 ( V_134 ) ;
F_171 ( V_145 , V_146 ) ;
}
