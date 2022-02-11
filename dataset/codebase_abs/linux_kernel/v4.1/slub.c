static inline int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return F_3 ( V_2 -> V_3 & V_4 ) ;
#else
return 0 ;
#endif
}
static inline bool F_4 ( struct V_1 * V_2 )
{
#ifdef F_5
return ! F_1 ( V_2 ) ;
#else
return false ;
#endif
}
static inline int F_6 ( struct V_1 * V_2 ) { return 0 ; }
static inline int F_7 ( struct V_1 * V_2 , const char * V_5 )
{ return 0 ; }
static inline void F_8 ( struct V_1 * V_2 ) { }
static inline void F_9 ( const struct V_1 * V_2 , enum V_6 V_7 )
{
#ifdef F_10
F_11 ( V_2 -> V_8 -> F_9 [ V_7 ] ) ;
#endif
}
static inline int F_12 ( struct V_1 * V_2 ,
struct V_9 * V_9 , const void * V_10 )
{
void * V_11 ;
if ( ! V_10 )
return 1 ;
V_11 = F_13 ( V_9 ) ;
if ( V_10 < V_11 || V_10 >= V_11 + V_9 -> V_12 * V_2 -> V_13 ||
( V_10 - V_11 ) % V_2 -> V_13 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_14 ( struct V_1 * V_2 , void * V_10 )
{
return * ( void * * ) ( V_10 + V_2 -> V_14 ) ;
}
static void F_15 ( const struct V_1 * V_2 , void * V_10 )
{
F_16 ( V_10 + V_2 -> V_14 ) ;
}
static inline void * F_17 ( struct V_1 * V_2 , void * V_10 )
{
void * V_5 ;
#ifdef F_18
F_19 ( & V_5 , ( void * * ) ( V_10 + V_2 -> V_14 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_14 ( V_2 , V_10 ) ;
#endif
return V_5 ;
}
static inline void F_20 ( struct V_1 * V_2 , void * V_10 , void * V_15 )
{
* ( void * * ) ( V_10 + V_2 -> V_14 ) = V_15 ;
}
static inline int F_21 ( void * V_5 , struct V_1 * V_2 , void * V_16 )
{
return ( V_5 - V_16 ) / V_2 -> V_13 ;
}
static inline T_1 F_22 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_17 | V_18 ) )
return V_2 -> V_19 ;
#endif
if ( V_2 -> V_3 & ( V_20 | V_21 ) )
return V_2 -> V_22 ;
return V_2 -> V_13 ;
}
static inline int F_23 ( int V_23 , unsigned long V_13 , int V_24 )
{
return ( ( V_25 << V_23 ) - V_24 ) / V_13 ;
}
static inline struct V_26 F_24 ( int V_23 ,
unsigned long V_13 , int V_24 )
{
struct V_26 V_27 = {
( V_23 << V_28 ) + F_23 (order, size, reserved)
} ;
return V_27 ;
}
static inline int F_25 ( struct V_26 V_27 )
{
return V_27 . V_27 >> V_28 ;
}
static inline int F_26 ( struct V_26 V_27 )
{
return V_27 . V_27 & V_29 ;
}
static T_2 void F_27 ( struct V_9 * V_9 )
{
F_28 ( V_30 , & V_9 -> V_3 ) ;
}
static T_2 void F_29 ( struct V_9 * V_9 )
{
F_30 ( V_30 , & V_9 -> V_3 ) ;
}
static inline void F_31 ( struct V_9 * V_9 , unsigned long V_31 )
{
struct V_9 V_32 ;
V_32 . V_33 = V_31 ;
V_9 -> V_34 = V_32 . V_34 ;
V_9 -> V_22 = V_32 . V_22 ;
V_9 -> V_12 = V_32 . V_12 ;
}
static inline bool F_32 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_35 , unsigned long V_36 ,
void * V_37 , unsigned long V_31 ,
const char * V_38 )
{
F_33 ( ! F_34 () ) ;
#if F_35 ( V_39 ) && \
F_35 ( V_40 )
if ( V_2 -> V_3 & V_41 ) {
if ( F_36 ( & V_9 -> V_42 , & V_9 -> V_33 ,
V_35 , V_36 ,
V_37 , V_31 ) )
return true ;
} else
#endif
{
F_27 ( V_9 ) ;
if ( V_9 -> V_42 == V_35 &&
V_9 -> V_33 == V_36 ) {
V_9 -> V_42 = V_37 ;
F_31 ( V_9 , V_31 ) ;
F_29 ( V_9 ) ;
return true ;
}
F_29 ( V_9 ) ;
}
F_37 () ;
F_9 ( V_2 , V_43 ) ;
#ifdef F_38
F_39 ( L_1 , V_38 , V_2 -> V_44 ) ;
#endif
return false ;
}
static inline bool F_40 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_35 , unsigned long V_36 ,
void * V_37 , unsigned long V_31 ,
const char * V_38 )
{
#if F_35 ( V_39 ) && \
F_35 ( V_40 )
if ( V_2 -> V_3 & V_41 ) {
if ( F_36 ( & V_9 -> V_42 , & V_9 -> V_33 ,
V_35 , V_36 ,
V_37 , V_31 ) )
return true ;
} else
#endif
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_27 ( V_9 ) ;
if ( V_9 -> V_42 == V_35 &&
V_9 -> V_33 == V_36 ) {
V_9 -> V_42 = V_37 ;
F_31 ( V_9 , V_31 ) ;
F_29 ( V_9 ) ;
F_42 ( V_3 ) ;
return true ;
}
F_29 ( V_9 ) ;
F_42 ( V_3 ) ;
}
F_37 () ;
F_9 ( V_2 , V_43 ) ;
#ifdef F_38
F_39 ( L_1 , V_38 , V_2 -> V_44 ) ;
#endif
return false ;
}
static void F_43 ( struct V_1 * V_2 , struct V_9 * V_9 , unsigned long * V_45 )
{
void * V_5 ;
void * V_16 = F_13 ( V_9 ) ;
for ( V_5 = V_9 -> V_42 ; V_5 ; V_5 = F_14 ( V_2 , V_5 ) )
F_44 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) ;
}
static inline void F_45 ( void )
{
F_46 () ;
}
static inline void F_47 ( void )
{
F_48 () ;
}
static void F_49 ( char * V_46 , T_3 * V_16 , unsigned int V_47 )
{
F_45 () ;
F_50 ( V_48 , V_46 , V_49 , 16 , 1 , V_16 ,
V_47 , 1 ) ;
F_47 () ;
}
static struct V_50 * F_51 ( struct V_1 * V_2 , void * V_10 ,
enum V_51 V_52 )
{
struct V_50 * V_5 ;
if ( V_2 -> V_14 )
V_5 = V_10 + V_2 -> V_14 + sizeof( void * ) ;
else
V_5 = V_10 + V_2 -> V_22 ;
return V_5 + V_52 ;
}
static void F_52 ( struct V_1 * V_2 , void * V_10 ,
enum V_51 V_52 , unsigned long V_16 )
{
struct V_50 * V_5 = F_51 ( V_2 , V_10 , V_52 ) ;
if ( V_16 ) {
#ifdef F_53
struct V_53 V_54 ;
int V_55 ;
V_54 . V_56 = 0 ;
V_54 . V_57 = V_58 ;
V_54 . V_59 = V_5 -> V_60 ;
V_54 . V_61 = 3 ;
F_45 () ;
F_54 ( & V_54 ) ;
F_47 () ;
if ( V_54 . V_56 != 0 &&
V_54 . V_59 [ V_54 . V_56 - 1 ] == V_62 )
V_54 . V_56 -- ;
for ( V_55 = V_54 . V_56 ; V_55 < V_58 ; V_55 ++ )
V_5 -> V_60 [ V_55 ] = 0 ;
#endif
V_5 -> V_16 = V_16 ;
V_5 -> V_63 = F_55 () ;
V_5 -> V_64 = V_65 -> V_64 ;
V_5 -> V_66 = V_67 ;
} else
memset ( V_5 , 0 , sizeof( struct V_50 ) ) ;
}
static void F_56 ( struct V_1 * V_2 , void * V_10 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return;
F_52 ( V_2 , V_10 , V_68 , 0UL ) ;
F_52 ( V_2 , V_10 , V_69 , 0UL ) ;
}
static void F_57 ( const char * V_2 , struct V_50 * V_70 )
{
if ( ! V_70 -> V_16 )
return;
F_58 ( L_2 ,
V_2 , ( void * ) V_70 -> V_16 , V_67 - V_70 -> V_66 , V_70 -> V_63 , V_70 -> V_64 ) ;
#ifdef F_53
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_58 ; V_55 ++ )
if ( V_70 -> V_60 [ V_55 ] )
F_58 ( L_3 , ( void * ) V_70 -> V_60 [ V_55 ] ) ;
else
break;
}
#endif
}
static void F_59 ( struct V_1 * V_2 , void * V_10 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return;
F_57 ( L_4 , F_51 ( V_2 , V_10 , V_69 ) ) ;
F_57 ( L_5 , F_51 ( V_2 , V_10 , V_68 ) ) ;
}
static void F_60 ( struct V_9 * V_9 )
{
F_58 ( L_6 ,
V_9 , V_9 -> V_12 , V_9 -> V_22 , V_9 -> V_42 , V_9 -> V_3 ) ;
}
static void F_61 ( struct V_1 * V_2 , char * V_71 , ... )
{
struct V_72 V_73 ;
T_4 args ;
va_start ( args , V_71 ) ;
V_73 . V_71 = V_71 ;
V_73 . V_74 = & args ;
F_58 ( L_7 ) ;
F_58 ( L_8 , V_2 -> V_44 , F_62 () , & V_73 ) ;
F_58 ( L_9 ) ;
F_63 ( V_75 , V_76 ) ;
va_end ( args ) ;
}
static void F_64 ( struct V_1 * V_2 , char * V_71 , ... )
{
struct V_72 V_73 ;
T_4 args ;
va_start ( args , V_71 ) ;
V_73 . V_71 = V_71 ;
V_73 . V_74 = & args ;
F_58 ( L_10 , V_2 -> V_44 , & V_73 ) ;
va_end ( args ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_9 * V_9 , T_3 * V_5 )
{
unsigned int V_77 ;
T_3 * V_16 = F_13 ( V_9 ) ;
F_59 ( V_2 , V_5 ) ;
F_60 ( V_9 ) ;
F_58 ( L_11 ,
V_5 , V_5 - V_16 , F_14 ( V_2 , V_5 ) ) ;
if ( V_5 > V_16 + 16 )
F_49 ( L_12 , V_5 - 16 , 16 ) ;
F_49 ( L_13 , V_5 , F_66 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_17 )
F_49 ( L_14 , V_5 + V_2 -> V_19 ,
V_2 -> V_22 - V_2 -> V_19 ) ;
if ( V_2 -> V_14 )
V_77 = V_2 -> V_14 + sizeof( void * ) ;
else
V_77 = V_2 -> V_22 ;
if ( V_2 -> V_3 & V_21 )
V_77 += 2 * sizeof( struct V_50 ) ;
if ( V_77 != V_2 -> V_13 )
F_49 ( L_15 , V_5 + V_77 , V_2 -> V_13 - V_77 ) ;
F_67 () ;
}
void F_68 ( struct V_1 * V_2 , struct V_9 * V_9 ,
T_3 * V_10 , char * V_78 )
{
F_61 ( V_2 , L_16 , V_78 ) ;
F_65 ( V_2 , V_9 , V_10 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_9 * V_9 ,
const char * V_71 , ... )
{
T_4 args ;
char V_79 [ 100 ] ;
va_start ( args , V_71 ) ;
vsnprintf ( V_79 , sizeof( V_79 ) , V_71 , args ) ;
va_end ( args ) ;
F_61 ( V_2 , L_16 , V_79 ) ;
F_60 ( V_9 ) ;
F_67 () ;
}
static void F_70 ( struct V_1 * V_2 , void * V_10 , T_3 V_80 )
{
T_3 * V_5 = V_10 ;
if ( V_2 -> V_3 & V_81 ) {
memset ( V_5 , V_82 , V_2 -> V_19 - 1 ) ;
V_5 [ V_2 -> V_19 - 1 ] = V_83 ;
}
if ( V_2 -> V_3 & V_17 )
memset ( V_5 + V_2 -> V_19 , V_80 , V_2 -> V_22 - V_2 -> V_19 ) ;
}
static void F_71 ( struct V_1 * V_2 , char * V_84 , T_3 V_85 ,
void * V_86 , void * V_87 )
{
F_64 ( V_2 , L_17 , V_86 , V_87 - 1 , V_85 ) ;
memset ( V_86 , V_85 , V_87 - V_86 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_9 * V_9 ,
T_3 * V_10 , char * V_88 ,
T_3 * V_89 , unsigned int V_90 , unsigned int V_91 )
{
T_3 * V_92 ;
T_3 * V_93 ;
F_45 () ;
V_92 = F_73 ( V_89 , V_90 , V_91 ) ;
F_47 () ;
if ( ! V_92 )
return 1 ;
V_93 = V_89 + V_91 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_90 )
V_93 -- ;
F_61 ( V_2 , L_18 , V_88 ) ;
F_58 ( L_19 ,
V_92 , V_93 - 1 , V_92 [ 0 ] , V_90 ) ;
F_65 ( V_2 , V_9 , V_10 ) ;
F_71 ( V_2 , V_88 , V_90 , V_92 , V_93 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_9 * V_9 , T_3 * V_5 )
{
unsigned long V_77 = V_2 -> V_22 ;
if ( V_2 -> V_14 )
V_77 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_21 )
V_77 += 2 * sizeof( struct V_50 ) ;
if ( V_2 -> V_13 == V_77 )
return 1 ;
return F_72 ( V_2 , V_9 , V_5 , L_20 ,
V_5 + V_77 , V_94 , V_2 -> V_13 - V_77 ) ;
}
static int F_75 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
T_3 * V_89 ;
T_3 * V_92 ;
T_3 * V_93 ;
int V_47 ;
int V_95 ;
if ( ! ( V_2 -> V_3 & V_18 ) )
return 1 ;
V_89 = F_13 ( V_9 ) ;
V_47 = ( V_25 << F_76 ( V_9 ) ) - V_2 -> V_24 ;
V_93 = V_89 + V_47 ;
V_95 = V_47 % V_2 -> V_13 ;
if ( ! V_95 )
return 1 ;
F_45 () ;
V_92 = F_73 ( V_93 - V_95 , V_94 , V_95 ) ;
F_47 () ;
if ( ! V_92 )
return 1 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_94 )
V_93 -- ;
F_69 ( V_2 , V_9 , L_21 , V_92 , V_93 - 1 ) ;
F_49 ( L_15 , V_93 - V_95 , V_95 ) ;
F_71 ( V_2 , L_22 , V_94 , V_93 - V_95 , V_93 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_10 , T_3 V_80 )
{
T_3 * V_5 = V_10 ;
T_3 * V_96 = V_10 + V_2 -> V_19 ;
if ( V_2 -> V_3 & V_17 ) {
if ( ! F_72 ( V_2 , V_9 , V_10 , L_23 ,
V_96 , V_80 , V_2 -> V_22 - V_2 -> V_19 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_18 ) && V_2 -> V_19 < V_2 -> V_22 ) {
F_72 ( V_2 , V_9 , V_5 , L_24 ,
V_96 , V_94 ,
V_2 -> V_22 - V_2 -> V_19 ) ;
}
}
if ( V_2 -> V_3 & V_18 ) {
if ( V_80 != V_97 && ( V_2 -> V_3 & V_81 ) &&
( ! F_72 ( V_2 , V_9 , V_5 , L_25 , V_5 ,
V_82 , V_2 -> V_19 - 1 ) ||
! F_72 ( V_2 , V_9 , V_5 , L_25 ,
V_5 + V_2 -> V_19 - 1 , V_83 , 1 ) ) )
return 0 ;
F_74 ( V_2 , V_9 , V_5 ) ;
}
if ( ! V_2 -> V_14 && V_80 == V_97 )
return 1 ;
if ( ! F_12 ( V_2 , V_9 , F_14 ( V_2 , V_5 ) ) ) {
F_68 ( V_2 , V_9 , V_5 , L_26 ) ;
F_20 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_98 ;
F_33 ( ! F_34 () ) ;
if ( ! F_79 ( V_9 ) ) {
F_69 ( V_2 , V_9 , L_27 ) ;
return 0 ;
}
V_98 = F_23 ( F_76 ( V_9 ) , V_2 -> V_13 , V_2 -> V_24 ) ;
if ( V_9 -> V_12 > V_98 ) {
F_69 ( V_2 , V_9 , L_28 ,
V_9 -> V_12 , V_98 ) ;
return 0 ;
}
if ( V_9 -> V_22 > V_9 -> V_12 ) {
F_69 ( V_2 , V_9 , L_29 ,
V_9 -> V_22 , V_9 -> V_12 ) ;
return 0 ;
}
F_75 ( V_2 , V_9 ) ;
return 1 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_9 * V_9 , void * V_99 )
{
int V_100 = 0 ;
void * V_15 ;
void * V_10 = NULL ;
int V_101 ;
V_15 = V_9 -> V_42 ;
while ( V_15 && V_100 <= V_9 -> V_12 ) {
if ( V_15 == V_99 )
return 1 ;
if ( ! F_12 ( V_2 , V_9 , V_15 ) ) {
if ( V_10 ) {
F_68 ( V_2 , V_9 , V_10 ,
L_30 ) ;
F_20 ( V_2 , V_10 , NULL ) ;
} else {
F_69 ( V_2 , V_9 , L_26 ) ;
V_9 -> V_42 = NULL ;
V_9 -> V_22 = V_9 -> V_12 ;
F_64 ( V_2 , L_31 ) ;
return 0 ;
}
break;
}
V_10 = V_15 ;
V_15 = F_14 ( V_2 , V_10 ) ;
V_100 ++ ;
}
V_101 = F_23 ( F_76 ( V_9 ) , V_2 -> V_13 , V_2 -> V_24 ) ;
if ( V_101 > V_102 )
V_101 = V_102 ;
if ( V_9 -> V_12 != V_101 ) {
F_69 ( V_2 , V_9 , L_32
L_33 , V_9 -> V_12 , V_101 ) ;
V_9 -> V_12 = V_101 ;
F_64 ( V_2 , L_34 ) ;
}
if ( V_9 -> V_22 != V_9 -> V_12 - V_100 ) {
F_69 ( V_2 , V_9 , L_35
L_36 , V_9 -> V_22 , V_9 -> V_12 - V_100 ) ;
V_9 -> V_22 = V_9 -> V_12 - V_100 ;
F_64 ( V_2 , L_37 ) ;
}
return V_99 == NULL ;
}
static void V_54 ( struct V_1 * V_2 , struct V_9 * V_9 , void * V_10 ,
int V_52 )
{
if ( V_2 -> V_3 & V_103 ) {
F_39 ( L_38 ,
V_2 -> V_44 ,
V_52 ? L_39 : L_40 ,
V_10 , V_9 -> V_22 ,
V_9 -> V_42 ) ;
if ( ! V_52 )
F_49 ( L_13 , ( void * ) V_10 ,
V_2 -> V_19 ) ;
F_67 () ;
}
}
static void F_81 ( struct V_1 * V_2 ,
struct V_104 * V_38 , struct V_9 * V_9 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return;
F_82 ( & V_38 -> V_105 ) ;
F_83 ( & V_9 -> V_106 , & V_38 -> V_107 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_104 * V_38 , struct V_9 * V_9 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return;
F_82 ( & V_38 -> V_105 ) ;
F_85 ( & V_9 -> V_106 ) ;
}
static inline unsigned long F_86 ( struct V_1 * V_2 , int V_108 )
{
struct V_104 * V_38 = F_87 ( V_2 , V_108 ) ;
return F_88 ( & V_38 -> V_109 ) ;
}
static inline unsigned long F_89 ( struct V_104 * V_38 )
{
return F_88 ( & V_38 -> V_109 ) ;
}
static inline void F_90 ( struct V_1 * V_2 , int V_108 , int V_12 )
{
struct V_104 * V_38 = F_87 ( V_2 , V_108 ) ;
if ( F_91 ( V_38 ) ) {
F_92 ( & V_38 -> V_109 ) ;
F_93 ( V_12 , & V_38 -> V_110 ) ;
}
}
static inline void F_94 ( struct V_1 * V_2 , int V_108 , int V_12 )
{
struct V_104 * V_38 = F_87 ( V_2 , V_108 ) ;
F_95 ( & V_38 -> V_109 ) ;
F_96 ( V_12 , & V_38 -> V_110 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_10 )
{
if ( ! ( V_2 -> V_3 & ( V_21 | V_17 | V_81 ) ) )
return;
F_70 ( V_2 , V_10 , V_111 ) ;
F_56 ( V_2 , V_10 ) ;
}
static T_5 int F_98 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
void * V_10 , unsigned long V_16 )
{
if ( ! F_78 ( V_2 , V_9 ) )
goto V_112;
if ( ! F_12 ( V_2 , V_9 , V_10 ) ) {
F_68 ( V_2 , V_9 , V_10 , L_41 ) ;
goto V_112;
}
if ( ! F_77 ( V_2 , V_9 , V_10 , V_111 ) )
goto V_112;
if ( V_2 -> V_3 & V_21 )
F_52 ( V_2 , V_10 , V_69 , V_16 ) ;
V_54 ( V_2 , V_9 , V_10 , 1 ) ;
F_70 ( V_2 , V_10 , V_97 ) ;
return 1 ;
V_112:
if ( F_79 ( V_9 ) ) {
F_64 ( V_2 , L_42 ) ;
V_9 -> V_22 = V_9 -> V_12 ;
V_9 -> V_42 = NULL ;
}
return 0 ;
}
int T_6 F_99 ( char * V_113 )
{
V_114 = V_115 ;
if ( * V_113 ++ != '=' || ! * V_113 )
goto V_116;
if ( * V_113 == ',' )
goto V_117;
V_114 = 0 ;
if ( * V_113 == '-' )
goto V_116;
for (; * V_113 && * V_113 != ',' ; V_113 ++ ) {
switch ( tolower ( * V_113 ) ) {
case 'f' :
V_114 |= V_118 ;
break;
case 'z' :
V_114 |= V_17 ;
break;
case 'p' :
V_114 |= V_18 ;
break;
case 'u' :
V_114 |= V_21 ;
break;
case 't' :
V_114 |= V_103 ;
break;
case 'a' :
V_114 |= V_119 ;
break;
case 'o' :
V_120 = 1 ;
break;
default:
F_58 ( L_43 ,
* V_113 ) ;
}
}
V_117:
if ( * V_113 == ',' )
V_121 = V_113 + 1 ;
V_116:
return 1 ;
}
unsigned long F_100 ( unsigned long V_19 ,
unsigned long V_3 , const char * V_44 ,
void (* F_101)( void * ) )
{
if ( V_114 && ( ! V_121 || ( V_44 &&
! strncmp ( V_121 , V_44 , strlen ( V_121 ) ) ) ) )
V_3 |= V_114 ;
return V_3 ;
}
static inline void F_97 ( struct V_1 * V_2 ,
struct V_9 * V_9 , void * V_10 ) {}
static inline int F_98 ( struct V_1 * V_2 ,
struct V_9 * V_9 , void * V_10 , unsigned long V_16 ) { return 0 ; }
static inline struct V_104 * F_102 (
struct V_1 * V_2 , struct V_9 * V_9 , void * V_10 ,
unsigned long V_16 , unsigned long * V_3 ) { return NULL ; }
static inline int F_75 ( struct V_1 * V_2 , struct V_9 * V_9 )
{ return 1 ; }
static inline int F_77 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_10 , T_3 V_80 ) { return 1 ; }
static inline void F_81 ( struct V_1 * V_2 , struct V_104 * V_38 ,
struct V_9 * V_9 ) {}
static inline void F_84 ( struct V_1 * V_2 , struct V_104 * V_38 ,
struct V_9 * V_9 ) {}
unsigned long F_100 ( unsigned long V_19 ,
unsigned long V_3 , const char * V_44 ,
void (* F_101)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_86 ( struct V_1 * V_2 , int V_108 )
{ return 0 ; }
static inline unsigned long F_89 ( struct V_104 * V_38 )
{ return 0 ; }
static inline void F_90 ( struct V_1 * V_2 , int V_108 ,
int V_12 ) {}
static inline void F_94 ( struct V_1 * V_2 , int V_108 ,
int V_12 ) {}
static inline void F_103 ( void * V_122 , T_1 V_13 , T_7 V_3 )
{
F_104 ( V_122 , V_13 , 1 , V_3 ) ;
F_105 ( V_122 , V_13 ) ;
}
static inline void F_106 ( const void * V_27 )
{
F_107 ( V_27 ) ;
F_108 ( V_27 ) ;
}
static inline struct V_1 * F_109 ( struct V_1 * V_2 ,
T_7 V_3 )
{
V_3 &= V_123 ;
F_110 ( V_3 ) ;
F_111 ( V_3 & V_124 ) ;
if ( F_112 ( V_2 -> V_19 , V_3 , V_2 -> V_3 ) )
return NULL ;
return F_113 ( V_2 , V_3 ) ;
}
static inline void F_114 ( struct V_1 * V_2 ,
T_7 V_3 , void * V_10 )
{
V_3 &= V_123 ;
F_115 ( V_2 , V_3 , V_10 , F_22 ( V_2 ) ) ;
F_116 ( V_10 , V_2 -> V_19 , 1 , V_2 -> V_3 , V_3 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 , V_10 ) ;
}
static inline void F_119 ( struct V_1 * V_2 , void * V_27 )
{
F_120 ( V_27 , V_2 -> V_3 ) ;
#if F_35 ( V_125 ) || F_35 ( V_126 )
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_121 ( V_2 , V_27 , V_2 -> V_19 ) ;
F_122 ( V_27 , V_2 -> V_19 ) ;
F_42 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_127 ) )
F_123 ( V_27 , V_2 -> V_19 ) ;
F_124 ( V_2 , V_27 ) ;
}
static inline struct V_9 * F_125 ( struct V_1 * V_2 ,
T_7 V_3 , int V_108 , struct V_26 V_128 )
{
struct V_9 * V_9 ;
int V_23 = F_25 ( V_128 ) ;
V_3 |= V_129 ;
if ( F_126 ( V_2 , V_3 , V_23 ) )
return NULL ;
if ( V_108 == V_130 )
V_9 = F_127 ( V_3 , V_23 ) ;
else
V_9 = F_128 ( V_108 , V_3 , V_23 ) ;
if ( ! V_9 )
F_129 ( V_2 , V_23 ) ;
return V_9 ;
}
static struct V_9 * F_130 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
struct V_9 * V_9 ;
struct V_26 V_128 = V_2 -> V_128 ;
T_7 V_131 ;
V_3 &= V_123 ;
if ( V_3 & V_124 )
F_131 () ;
V_3 |= V_2 -> V_132 ;
V_131 = ( V_3 | V_133 | V_134 ) & ~ V_135 ;
V_9 = F_125 ( V_2 , V_131 , V_108 , V_128 ) ;
if ( F_3 ( ! V_9 ) ) {
V_128 = V_2 -> V_136 ;
V_131 = V_3 ;
V_9 = F_125 ( V_2 , V_131 , V_108 , V_128 ) ;
if ( V_9 )
F_9 ( V_2 , V_137 ) ;
}
if ( V_138 && V_9
&& ! ( V_2 -> V_3 & ( V_139 | V_115 ) ) ) {
int V_140 = 1 << F_25 ( V_128 ) ;
F_132 ( V_9 , F_25 ( V_128 ) , V_131 , V_108 ) ;
if ( V_2 -> F_101 )
F_133 ( V_9 , V_140 ) ;
else
F_134 ( V_9 , V_140 ) ;
}
if ( V_3 & V_124 )
F_135 () ;
if ( ! V_9 )
return NULL ;
V_9 -> V_12 = F_26 ( V_128 ) ;
F_136 ( F_137 ( V_9 ) ,
( V_2 -> V_3 & V_141 ) ?
V_142 : V_143 ,
1 << F_25 ( V_128 ) ) ;
return V_9 ;
}
static void F_138 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_10 )
{
F_97 ( V_2 , V_9 , V_10 ) ;
if ( F_3 ( V_2 -> F_101 ) ) {
F_139 ( V_2 , V_10 ) ;
V_2 -> F_101 ( V_10 ) ;
F_140 ( V_2 , V_10 ) ;
}
}
static struct V_9 * F_141 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
struct V_9 * V_9 ;
void * V_89 ;
void * V_5 ;
int V_23 ;
int V_144 ;
if ( F_3 ( V_3 & V_145 ) ) {
F_142 ( L_44 , V_3 & V_145 ) ;
F_143 () ;
}
V_9 = F_130 ( V_2 ,
V_3 & ( V_146 | V_147 ) , V_108 ) ;
if ( ! V_9 )
goto V_116;
V_23 = F_76 ( V_9 ) ;
F_90 ( V_2 , F_144 ( V_9 ) , V_9 -> V_12 ) ;
V_9 -> V_148 = V_2 ;
F_145 ( V_9 ) ;
if ( V_9 -> V_149 )
F_146 ( V_9 ) ;
V_89 = F_13 ( V_9 ) ;
if ( F_3 ( V_2 -> V_3 & V_18 ) )
memset ( V_89 , V_94 , V_25 << V_23 ) ;
F_147 ( V_9 ) ;
F_148 (p, idx, s, start, page->objects) {
F_138 ( V_2 , V_9 , V_5 ) ;
if ( F_91 ( V_144 < V_9 -> V_12 ) )
F_20 ( V_2 , V_5 , V_5 + V_2 -> V_13 ) ;
else
F_20 ( V_2 , V_5 , NULL ) ;
}
V_9 -> V_42 = V_89 ;
V_9 -> V_22 = V_9 -> V_12 ;
V_9 -> V_34 = 1 ;
V_116:
return V_9 ;
}
static void F_149 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_23 = F_76 ( V_9 ) ;
int V_140 = 1 << V_23 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_75 ( V_2 , V_9 ) ;
F_150 (p, s, page_address(page),
page->objects)
F_77 ( V_2 , V_9 , V_5 , V_111 ) ;
}
F_151 ( V_9 , F_76 ( V_9 ) ) ;
F_136 ( F_137 ( V_9 ) ,
( V_2 -> V_3 & V_141 ) ?
V_142 : V_143 ,
- V_140 ) ;
F_152 ( V_9 ) ;
F_153 ( V_9 ) ;
F_154 ( V_9 ) ;
if ( V_65 -> V_150 )
V_65 -> V_150 -> V_151 += V_140 ;
F_155 ( V_9 , V_23 ) ;
F_129 ( V_2 , V_23 ) ;
}
static void F_156 ( struct V_152 * V_153 )
{
struct V_9 * V_9 ;
if ( V_154 )
V_9 = F_157 ( V_153 ) ;
else
V_9 = F_158 ( (struct V_155 * ) V_153 , struct V_9 , V_106 ) ;
F_149 ( V_9 -> V_148 , V_9 ) ;
}
static void F_159 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
if ( F_3 ( V_2 -> V_3 & V_20 ) ) {
struct V_152 * V_156 ;
if ( V_154 ) {
int V_23 = F_76 ( V_9 ) ;
int V_14 = ( V_25 << V_23 ) - V_2 -> V_24 ;
F_33 ( V_2 -> V_24 != sizeof( * V_156 ) ) ;
V_156 = F_13 ( V_9 ) + V_14 ;
} else {
V_156 = ( void * ) & V_9 -> V_106 ;
}
F_160 ( V_156 , F_156 ) ;
} else
F_149 ( V_2 , V_9 ) ;
}
static void F_161 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
F_94 ( V_2 , F_144 ( V_9 ) , V_9 -> V_12 ) ;
F_159 ( V_2 , V_9 ) ;
}
static inline void
F_162 ( struct V_104 * V_38 , struct V_9 * V_9 , int V_157 )
{
V_38 -> V_158 ++ ;
if ( V_157 == V_159 )
F_163 ( & V_9 -> V_106 , & V_38 -> V_160 ) ;
else
F_83 ( & V_9 -> V_106 , & V_38 -> V_160 ) ;
}
static inline void F_164 ( struct V_104 * V_38 ,
struct V_9 * V_9 , int V_157 )
{
F_82 ( & V_38 -> V_105 ) ;
F_162 ( V_38 , V_9 , V_157 ) ;
}
static inline void
F_165 ( struct V_104 * V_38 , struct V_9 * V_9 )
{
F_85 ( & V_9 -> V_106 ) ;
V_38 -> V_158 -- ;
}
static inline void F_166 ( struct V_104 * V_38 ,
struct V_9 * V_9 )
{
F_82 ( & V_38 -> V_105 ) ;
F_165 ( V_38 , V_9 ) ;
}
static inline void * F_167 ( struct V_1 * V_2 ,
struct V_104 * V_38 , struct V_9 * V_9 ,
int V_161 , int * V_12 )
{
void * V_42 ;
unsigned long V_33 ;
struct V_9 V_162 ;
F_82 ( & V_38 -> V_105 ) ;
V_42 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
V_162 . V_33 = V_33 ;
* V_12 = V_162 . V_12 - V_162 . V_22 ;
if ( V_161 ) {
V_162 . V_22 = V_9 -> V_12 ;
V_162 . V_42 = NULL ;
} else {
V_162 . V_42 = V_42 ;
}
F_33 ( V_162 . V_34 ) ;
V_162 . V_34 = 1 ;
if ( ! F_32 ( V_2 , V_9 ,
V_42 , V_33 ,
V_162 . V_42 , V_162 . V_33 ,
L_45 ) )
return NULL ;
F_166 ( V_38 , V_9 ) ;
F_168 ( ! V_42 ) ;
return V_42 ;
}
static void * F_169 ( struct V_1 * V_2 , struct V_104 * V_38 ,
struct V_163 * V_164 , T_7 V_3 )
{
struct V_9 * V_9 , * V_165 ;
void * V_10 = NULL ;
int V_166 = 0 ;
int V_12 ;
if ( ! V_38 || ! V_38 -> V_158 )
return NULL ;
F_170 ( & V_38 -> V_105 ) ;
F_171 (page, page2, &n->partial, lru) {
void * V_70 ;
if ( ! F_172 ( V_9 , V_3 ) )
continue;
V_70 = F_167 ( V_2 , V_38 , V_9 , V_10 == NULL , & V_12 ) ;
if ( ! V_70 )
break;
V_166 += V_12 ;
if ( ! V_10 ) {
V_164 -> V_9 = V_9 ;
F_9 ( V_2 , V_167 ) ;
V_10 = V_70 ;
} else {
F_173 ( V_2 , V_9 , 0 ) ;
F_9 ( V_2 , V_168 ) ;
}
if ( ! F_4 ( V_2 )
|| V_166 > V_2 -> V_169 / 2 )
break;
}
F_174 ( & V_38 -> V_105 ) ;
return V_10 ;
}
static void * F_175 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_163 * V_164 )
{
#ifdef F_176
struct V_170 * V_170 ;
struct V_171 * V_172 ;
struct V_173 * V_173 ;
enum V_174 V_175 = F_177 ( V_3 ) ;
void * V_10 ;
unsigned int V_176 ;
if ( ! V_2 -> V_177 ||
F_178 () % 1024 > V_2 -> V_177 )
return NULL ;
do {
V_176 = F_179 () ;
V_170 = F_180 ( F_181 () , V_3 ) ;
F_182 (zone, z, zonelist, high_zoneidx) {
struct V_104 * V_38 ;
V_38 = F_87 ( V_2 , F_183 ( V_173 ) ) ;
if ( V_38 && F_184 ( V_173 , V_3 ) &&
V_38 -> V_158 > V_2 -> V_178 ) {
V_10 = F_169 ( V_2 , V_38 , V_164 , V_3 ) ;
if ( V_10 ) {
return V_10 ;
}
}
}
} while ( F_185 ( V_176 ) );
#endif
return NULL ;
}
static void * F_186 ( struct V_1 * V_2 , T_7 V_3 , int V_108 ,
struct V_163 * V_164 )
{
void * V_10 ;
int V_179 = V_108 ;
if ( V_108 == V_130 )
V_179 = F_187 () ;
else if ( ! F_188 ( V_108 ) )
V_179 = F_189 ( V_108 ) ;
V_10 = F_169 ( V_2 , F_87 ( V_2 , V_179 ) , V_164 , V_3 ) ;
if ( V_10 || V_108 != V_130 )
return V_10 ;
return F_175 ( V_2 , V_3 , V_164 ) ;
}
static inline unsigned long F_190 ( unsigned long V_180 )
{
return V_180 + V_181 ;
}
static inline unsigned int F_191 ( unsigned long V_180 )
{
return V_180 % V_181 ;
}
static inline unsigned long F_192 ( unsigned long V_180 )
{
return V_180 / V_181 ;
}
static inline unsigned int F_193 ( int V_63 )
{
return V_63 ;
}
static inline void F_194 ( const char * V_38 ,
const struct V_1 * V_2 , unsigned long V_180 )
{
#ifdef F_38
unsigned long V_182 = F_195 ( V_2 -> V_8 -> V_180 ) ;
F_39 ( L_46 , V_38 , V_2 -> V_44 ) ;
#ifdef F_196
if ( F_191 ( V_180 ) != F_191 ( V_182 ) )
F_197 ( L_47 ,
F_191 ( V_180 ) , F_191 ( V_182 ) ) ;
else
#endif
if ( F_192 ( V_180 ) != F_192 ( V_182 ) )
F_197 ( L_48 ,
F_192 ( V_180 ) , F_192 ( V_182 ) ) ;
else
F_197 ( L_49 ,
V_182 , V_180 , F_190 ( V_180 ) ) ;
#endif
F_9 ( V_2 , V_183 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
int V_63 ;
F_199 (cpu)
F_200 ( V_2 -> V_8 , V_63 ) -> V_180 = F_193 ( V_63 ) ;
}
static void F_201 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_42 )
{
enum T_8 { V_184 , V_185 , V_186 , V_187 };
struct V_104 * V_38 = F_87 ( V_2 , F_144 ( V_9 ) ) ;
int V_188 = 0 ;
enum T_8 V_189 = V_184 , V_190 = V_184 ;
void * V_191 ;
int V_157 = V_192 ;
struct V_9 V_162 ;
struct V_9 V_193 ;
if ( V_9 -> V_42 ) {
F_9 ( V_2 , V_194 ) ;
V_157 = V_159 ;
}
while ( V_42 && ( V_191 = F_14 ( V_2 , V_42 ) ) ) {
void * V_195 ;
unsigned long V_33 ;
do {
V_195 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
F_20 ( V_2 , V_42 , V_195 ) ;
V_162 . V_33 = V_33 ;
V_162 . V_22 -- ;
F_33 ( ! V_162 . V_34 ) ;
} while ( ! F_32 ( V_2 , V_9 ,
V_195 , V_33 ,
V_42 , V_162 . V_33 ,
L_50 ) );
V_42 = V_191 ;
}
V_196:
V_193 . V_42 = V_9 -> V_42 ;
V_193 . V_33 = V_9 -> V_33 ;
F_33 ( ! V_193 . V_34 ) ;
V_162 . V_33 = V_193 . V_33 ;
if ( V_42 ) {
V_162 . V_22 -- ;
F_20 ( V_2 , V_42 , V_193 . V_42 ) ;
V_162 . V_42 = V_42 ;
} else
V_162 . V_42 = V_193 . V_42 ;
V_162 . V_34 = 0 ;
if ( ! V_162 . V_22 && V_38 -> V_158 >= V_2 -> V_178 )
V_190 = V_187 ;
else if ( V_162 . V_42 ) {
V_190 = V_185 ;
if ( ! V_188 ) {
V_188 = 1 ;
F_170 ( & V_38 -> V_105 ) ;
}
} else {
V_190 = V_186 ;
if ( F_1 ( V_2 ) && ! V_188 ) {
V_188 = 1 ;
F_170 ( & V_38 -> V_105 ) ;
}
}
if ( V_189 != V_190 ) {
if ( V_189 == V_185 )
F_166 ( V_38 , V_9 ) ;
else if ( V_189 == V_186 )
F_84 ( V_2 , V_38 , V_9 ) ;
if ( V_190 == V_185 ) {
F_164 ( V_38 , V_9 , V_157 ) ;
F_9 ( V_2 , V_157 ) ;
} else if ( V_190 == V_186 ) {
F_9 ( V_2 , V_197 ) ;
F_81 ( V_2 , V_38 , V_9 ) ;
}
}
V_189 = V_190 ;
if ( ! F_32 ( V_2 , V_9 ,
V_193 . V_42 , V_193 . V_33 ,
V_162 . V_42 , V_162 . V_33 ,
L_51 ) )
goto V_196;
if ( V_188 )
F_174 ( & V_38 -> V_105 ) ;
if ( V_190 == V_187 ) {
F_9 ( V_2 , V_198 ) ;
F_161 ( V_2 , V_9 ) ;
F_9 ( V_2 , V_199 ) ;
}
}
static void F_202 ( struct V_1 * V_2 ,
struct V_163 * V_164 )
{
#ifdef F_5
struct V_104 * V_38 = NULL , * V_200 = NULL ;
struct V_9 * V_9 , * V_201 = NULL ;
while ( ( V_9 = V_164 -> V_160 ) ) {
struct V_9 V_162 ;
struct V_9 V_193 ;
V_164 -> V_160 = V_9 -> V_202 ;
V_200 = F_87 ( V_2 , F_144 ( V_9 ) ) ;
if ( V_38 != V_200 ) {
if ( V_38 )
F_174 ( & V_38 -> V_105 ) ;
V_38 = V_200 ;
F_170 ( & V_38 -> V_105 ) ;
}
do {
V_193 . V_42 = V_9 -> V_42 ;
V_193 . V_33 = V_9 -> V_33 ;
F_33 ( ! V_193 . V_34 ) ;
V_162 . V_33 = V_193 . V_33 ;
V_162 . V_42 = V_193 . V_42 ;
V_162 . V_34 = 0 ;
} while ( ! F_32 ( V_2 , V_9 ,
V_193 . V_42 , V_193 . V_33 ,
V_162 . V_42 , V_162 . V_33 ,
L_51 ) );
if ( F_3 ( ! V_162 . V_22 && V_38 -> V_158 >= V_2 -> V_178 ) ) {
V_9 -> V_202 = V_201 ;
V_201 = V_9 ;
} else {
F_164 ( V_38 , V_9 , V_159 ) ;
F_9 ( V_2 , V_203 ) ;
}
}
if ( V_38 )
F_174 ( & V_38 -> V_105 ) ;
while ( V_201 ) {
V_9 = V_201 ;
V_201 = V_201 -> V_202 ;
F_9 ( V_2 , V_198 ) ;
F_161 ( V_2 , V_9 ) ;
F_9 ( V_2 , V_199 ) ;
}
#endif
}
static void F_173 ( struct V_1 * V_2 , struct V_9 * V_9 , int V_204 )
{
#ifdef F_5
struct V_9 * V_205 ;
int V_140 ;
int V_206 ;
F_203 () ;
do {
V_140 = 0 ;
V_206 = 0 ;
V_205 = F_204 ( V_2 -> V_8 -> V_160 ) ;
if ( V_205 ) {
V_206 = V_205 -> V_206 ;
V_140 = V_205 -> V_140 ;
if ( V_204 && V_206 > V_2 -> V_169 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_202 ( V_2 , F_205 ( V_2 -> V_8 ) ) ;
F_42 ( V_3 ) ;
V_205 = NULL ;
V_206 = 0 ;
V_140 = 0 ;
F_9 ( V_2 , V_207 ) ;
}
}
V_140 ++ ;
V_206 += V_9 -> V_12 - V_9 -> V_22 ;
V_9 -> V_140 = V_140 ;
V_9 -> V_206 = V_206 ;
V_9 -> V_202 = V_205 ;
} while ( F_206 ( V_2 -> V_8 -> V_160 , V_205 , V_9 )
!= V_205 );
if ( F_3 ( ! V_2 -> V_169 ) ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_202 ( V_2 , F_205 ( V_2 -> V_8 ) ) ;
F_42 ( V_3 ) ;
}
F_207 () ;
#endif
}
static inline void F_208 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
F_9 ( V_2 , V_208 ) ;
F_201 ( V_2 , V_164 -> V_9 , V_164 -> V_42 ) ;
V_164 -> V_180 = F_190 ( V_164 -> V_180 ) ;
V_164 -> V_9 = NULL ;
V_164 -> V_42 = NULL ;
}
static inline void F_209 ( struct V_1 * V_2 , int V_63 )
{
struct V_163 * V_164 = F_200 ( V_2 -> V_8 , V_63 ) ;
if ( F_91 ( V_164 ) ) {
if ( V_164 -> V_9 )
F_208 ( V_2 , V_164 ) ;
F_202 ( V_2 , V_164 ) ;
}
}
static void F_210 ( void * V_209 )
{
struct V_1 * V_2 = V_209 ;
F_209 ( V_2 , F_55 () ) ;
}
static bool F_211 ( int V_63 , void * V_210 )
{
struct V_1 * V_2 = V_210 ;
struct V_163 * V_164 = F_200 ( V_2 -> V_8 , V_63 ) ;
return V_164 -> V_9 || V_164 -> V_160 ;
}
static void F_212 ( struct V_1 * V_2 )
{
F_213 ( F_211 , F_210 , V_2 , 1 , V_211 ) ;
}
static inline int F_214 ( struct V_9 * V_9 , int V_108 )
{
#ifdef F_176
if ( ! V_9 || ( V_108 != V_130 && F_144 ( V_9 ) != V_108 ) )
return 0 ;
#endif
return 1 ;
}
static int F_215 ( struct V_9 * V_9 )
{
return V_9 -> V_12 - V_9 -> V_22 ;
}
static inline unsigned long F_216 ( struct V_104 * V_38 )
{
return F_88 ( & V_38 -> V_110 ) ;
}
static unsigned long F_217 ( struct V_104 * V_38 ,
int (* F_218)( struct V_9 * ) )
{
unsigned long V_3 ;
unsigned long V_27 = 0 ;
struct V_9 * V_9 ;
F_219 ( & V_38 -> V_105 , V_3 ) ;
F_220 (page, &n->partial, lru)
V_27 += F_218 ( V_9 ) ;
F_221 ( & V_38 -> V_105 , V_3 ) ;
return V_27 ;
}
static T_5 void
F_222 ( struct V_1 * V_2 , T_7 V_212 , int V_213 )
{
#ifdef F_2
static F_223 ( V_214 , V_215 ,
V_216 ) ;
int V_108 ;
struct V_104 * V_38 ;
if ( ( V_212 & V_133 ) || ! F_224 ( & V_214 ) )
return;
F_197 ( L_52 ,
V_213 , V_212 ) ;
F_197 ( L_53 ,
V_2 -> V_44 , V_2 -> V_19 , V_2 -> V_13 , F_25 ( V_2 -> V_128 ) ,
F_25 ( V_2 -> V_136 ) ) ;
if ( F_25 ( V_2 -> V_136 ) > F_225 ( V_2 -> V_19 ) )
F_197 ( L_54 ,
V_2 -> V_44 ) ;
F_226 (s, node, n) {
unsigned long V_109 ;
unsigned long V_217 ;
unsigned long V_218 ;
V_218 = F_217 ( V_38 , F_215 ) ;
V_109 = F_89 ( V_38 ) ;
V_217 = F_216 ( V_38 ) ;
F_197 ( L_55 ,
V_108 , V_109 , V_217 , V_218 ) ;
}
#endif
}
static inline void * F_227 ( struct V_1 * V_2 , T_7 V_3 ,
int V_108 , struct V_163 * * V_219 )
{
void * V_42 ;
struct V_163 * V_164 = * V_219 ;
struct V_9 * V_9 ;
V_42 = F_186 ( V_2 , V_3 , V_108 , V_164 ) ;
if ( V_42 )
return V_42 ;
V_9 = F_141 ( V_2 , V_3 , V_108 ) ;
if ( V_9 ) {
V_164 = F_228 ( V_2 -> V_8 ) ;
if ( V_164 -> V_9 )
F_208 ( V_2 , V_164 ) ;
V_42 = V_9 -> V_42 ;
V_9 -> V_42 = NULL ;
F_9 ( V_2 , V_220 ) ;
V_164 -> V_9 = V_9 ;
* V_219 = V_164 ;
} else
V_42 = NULL ;
return V_42 ;
}
static inline bool F_172 ( struct V_9 * V_9 , T_7 V_212 )
{
if ( F_3 ( F_229 ( V_9 ) ) )
return F_230 ( V_212 ) ;
return true ;
}
static inline void * F_231 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_9 V_162 ;
unsigned long V_33 ;
void * V_42 ;
do {
V_42 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
V_162 . V_33 = V_33 ;
F_33 ( ! V_162 . V_34 ) ;
V_162 . V_22 = V_9 -> V_12 ;
V_162 . V_34 = V_42 != NULL ;
} while ( ! F_32 ( V_2 , V_9 ,
V_42 , V_33 ,
NULL , V_162 . V_33 ,
L_56 ) );
return V_42 ;
}
static void * F_232 ( struct V_1 * V_2 , T_7 V_212 , int V_108 ,
unsigned long V_16 , struct V_163 * V_164 )
{
void * V_42 ;
struct V_9 * V_9 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_196
V_164 = F_205 ( V_2 -> V_8 ) ;
#endif
V_9 = V_164 -> V_9 ;
if ( ! V_9 )
goto F_141;
V_196:
if ( F_3 ( ! F_214 ( V_9 , V_108 ) ) ) {
int V_179 = V_108 ;
if ( V_108 != V_130 && ! F_188 ( V_108 ) )
V_179 = F_189 ( V_108 ) ;
if ( F_3 ( ! F_214 ( V_9 , V_179 ) ) ) {
F_9 ( V_2 , V_221 ) ;
F_201 ( V_2 , V_9 , V_164 -> V_42 ) ;
V_164 -> V_9 = NULL ;
V_164 -> V_42 = NULL ;
goto F_141;
}
}
if ( F_3 ( ! F_172 ( V_9 , V_212 ) ) ) {
F_201 ( V_2 , V_9 , V_164 -> V_42 ) ;
V_164 -> V_9 = NULL ;
V_164 -> V_42 = NULL ;
goto F_141;
}
V_42 = V_164 -> V_42 ;
if ( V_42 )
goto V_222;
V_42 = F_231 ( V_2 , V_9 ) ;
if ( ! V_42 ) {
V_164 -> V_9 = NULL ;
F_9 ( V_2 , V_223 ) ;
goto F_141;
}
F_9 ( V_2 , V_224 ) ;
V_222:
F_33 ( ! V_164 -> V_9 -> V_34 ) ;
V_164 -> V_42 = F_14 ( V_2 , V_42 ) ;
V_164 -> V_180 = F_190 ( V_164 -> V_180 ) ;
F_42 ( V_3 ) ;
return V_42 ;
F_141:
if ( V_164 -> V_160 ) {
V_9 = V_164 -> V_9 = V_164 -> V_160 ;
V_164 -> V_160 = V_9 -> V_202 ;
F_9 ( V_2 , V_225 ) ;
V_164 -> V_42 = NULL ;
goto V_196;
}
V_42 = F_227 ( V_2 , V_212 , V_108 , & V_164 ) ;
if ( F_3 ( ! V_42 ) ) {
F_222 ( V_2 , V_212 , V_108 ) ;
F_42 ( V_3 ) ;
return NULL ;
}
V_9 = V_164 -> V_9 ;
if ( F_91 ( ! F_1 ( V_2 ) && F_172 ( V_9 , V_212 ) ) )
goto V_222;
if ( F_1 ( V_2 ) &&
! F_98 ( V_2 , V_9 , V_42 , V_16 ) )
goto F_141;
F_201 ( V_2 , V_9 , F_14 ( V_2 , V_42 ) ) ;
V_164 -> V_9 = NULL ;
V_164 -> V_42 = NULL ;
F_42 ( V_3 ) ;
return V_42 ;
}
static T_2 void * F_233 ( struct V_1 * V_2 ,
T_7 V_212 , int V_108 , unsigned long V_16 )
{
void * * V_10 ;
struct V_163 * V_164 ;
struct V_9 * V_9 ;
unsigned long V_180 ;
V_2 = F_109 ( V_2 , V_212 ) ;
if ( ! V_2 )
return NULL ;
V_196:
do {
V_180 = F_204 ( V_2 -> V_8 -> V_180 ) ;
V_164 = F_228 ( V_2 -> V_8 ) ;
} while ( F_234 ( F_196 ) &&
F_3 ( V_180 != F_235 ( V_164 -> V_180 ) ) );
F_236 () ;
V_10 = V_164 -> V_42 ;
V_9 = V_164 -> V_9 ;
if ( F_3 ( ! V_10 || ! F_214 ( V_9 , V_108 ) ) ) {
V_10 = F_232 ( V_2 , V_212 , V_108 , V_16 , V_164 ) ;
F_9 ( V_2 , V_226 ) ;
} else {
void * V_227 = F_17 ( V_2 , V_10 ) ;
if ( F_3 ( ! F_237 (
V_2 -> V_8 -> V_42 , V_2 -> V_8 -> V_180 ,
V_10 , V_180 ,
V_227 , F_190 ( V_180 ) ) ) ) {
F_194 ( L_57 , V_2 , V_180 ) ;
goto V_196;
}
F_15 ( V_2 , V_227 ) ;
F_9 ( V_2 , V_228 ) ;
}
if ( F_3 ( V_212 & V_229 ) && V_10 )
memset ( V_10 , 0 , V_2 -> V_19 ) ;
F_114 ( V_2 , V_212 , V_10 ) ;
return V_10 ;
}
static T_2 void * F_238 ( struct V_1 * V_2 ,
T_7 V_212 , unsigned long V_16 )
{
return F_233 ( V_2 , V_212 , V_130 , V_16 ) ;
}
void * F_239 ( struct V_1 * V_2 , T_7 V_212 )
{
void * V_230 = F_238 ( V_2 , V_212 , V_231 ) ;
F_240 ( V_231 , V_230 , V_2 -> V_19 ,
V_2 -> V_13 , V_212 ) ;
return V_230 ;
}
void * F_241 ( struct V_1 * V_2 , T_7 V_212 , T_1 V_13 )
{
void * V_230 = F_238 ( V_2 , V_212 , V_231 ) ;
F_242 ( V_231 , V_230 , V_13 , V_2 -> V_13 , V_212 ) ;
F_243 ( V_2 , V_230 , V_13 ) ;
return V_230 ;
}
void * F_244 ( struct V_1 * V_2 , T_7 V_212 , int V_108 )
{
void * V_230 = F_233 ( V_2 , V_212 , V_108 , V_231 ) ;
F_245 ( V_231 , V_230 ,
V_2 -> V_19 , V_2 -> V_13 , V_212 , V_108 ) ;
return V_230 ;
}
void * F_246 ( struct V_1 * V_2 ,
T_7 V_212 ,
int V_108 , T_1 V_13 )
{
void * V_230 = F_233 ( V_2 , V_212 , V_108 , V_231 ) ;
F_247 ( V_231 , V_230 ,
V_13 , V_2 -> V_13 , V_212 , V_108 ) ;
F_243 ( V_2 , V_230 , V_13 ) ;
return V_230 ;
}
static void F_248 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_27 , unsigned long V_16 )
{
void * V_195 ;
void * * V_10 = ( void * ) V_27 ;
int V_232 ;
struct V_9 V_162 ;
unsigned long V_33 ;
struct V_104 * V_38 = NULL ;
unsigned long V_233 ( V_3 ) ;
F_9 ( V_2 , V_234 ) ;
if ( F_1 ( V_2 ) &&
! ( V_38 = F_102 ( V_2 , V_9 , V_27 , V_16 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_38 ) ) {
F_221 ( & V_38 -> V_105 , V_3 ) ;
V_38 = NULL ;
}
V_195 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
F_20 ( V_2 , V_10 , V_195 ) ;
V_162 . V_33 = V_33 ;
V_232 = V_162 . V_34 ;
V_162 . V_22 -- ;
if ( ( ! V_162 . V_22 || ! V_195 ) && ! V_232 ) {
if ( F_4 ( V_2 ) && ! V_195 ) {
V_162 . V_34 = 1 ;
} else {
V_38 = F_87 ( V_2 , F_144 ( V_9 ) ) ;
F_219 ( & V_38 -> V_105 , V_3 ) ;
}
}
} while ( ! F_40 ( V_2 , V_9 ,
V_195 , V_33 ,
V_10 , V_162 . V_33 ,
L_58 ) );
if ( F_91 ( ! V_38 ) ) {
if ( V_162 . V_34 && ! V_232 ) {
F_173 ( V_2 , V_9 , 1 ) ;
F_9 ( V_2 , V_235 ) ;
}
if ( V_232 )
F_9 ( V_2 , V_236 ) ;
return;
}
if ( F_3 ( ! V_162 . V_22 && V_38 -> V_158 >= V_2 -> V_178 ) )
goto V_237;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_195 ) ) {
if ( F_1 ( V_2 ) )
F_84 ( V_2 , V_38 , V_9 ) ;
F_164 ( V_38 , V_9 , V_159 ) ;
F_9 ( V_2 , V_203 ) ;
}
F_221 ( & V_38 -> V_105 , V_3 ) ;
return;
V_237:
if ( V_195 ) {
F_166 ( V_38 , V_9 ) ;
F_9 ( V_2 , V_238 ) ;
} else {
F_84 ( V_2 , V_38 , V_9 ) ;
}
F_221 ( & V_38 -> V_105 , V_3 ) ;
F_9 ( V_2 , V_199 ) ;
F_161 ( V_2 , V_9 ) ;
}
static T_2 void F_249 ( struct V_1 * V_2 ,
struct V_9 * V_9 , void * V_27 , unsigned long V_16 )
{
void * * V_10 = ( void * ) V_27 ;
struct V_163 * V_164 ;
unsigned long V_180 ;
F_119 ( V_2 , V_27 ) ;
V_196:
do {
V_180 = F_204 ( V_2 -> V_8 -> V_180 ) ;
V_164 = F_228 ( V_2 -> V_8 ) ;
} while ( F_234 ( F_196 ) &&
F_3 ( V_180 != F_235 ( V_164 -> V_180 ) ) );
F_236 () ;
if ( F_91 ( V_9 == V_164 -> V_9 ) ) {
F_20 ( V_2 , V_10 , V_164 -> V_42 ) ;
if ( F_3 ( ! F_237 (
V_2 -> V_8 -> V_42 , V_2 -> V_8 -> V_180 ,
V_164 -> V_42 , V_180 ,
V_10 , F_190 ( V_180 ) ) ) ) {
F_194 ( L_59 , V_2 , V_180 ) ;
goto V_196;
}
F_9 ( V_2 , V_239 ) ;
} else
F_248 ( V_2 , V_9 , V_27 , V_16 ) ;
}
void F_250 ( struct V_1 * V_2 , void * V_27 )
{
V_2 = F_251 ( V_2 , V_27 ) ;
if ( ! V_2 )
return;
F_249 ( V_2 , F_157 ( V_27 ) , V_27 , V_231 ) ;
F_252 ( V_231 , V_27 ) ;
}
static inline int F_253 ( int V_13 , int V_240 ,
int V_241 , int V_242 , int V_24 )
{
int V_23 ;
int V_243 ;
int V_244 = V_245 ;
if ( F_23 ( V_244 , V_13 , V_24 ) > V_102 )
return F_225 ( V_13 * V_102 ) - 1 ;
for ( V_23 = F_254 ( V_244 ,
F_255 ( V_240 * V_13 - 1 ) - V_246 ) ;
V_23 <= V_241 ; V_23 ++ ) {
unsigned long V_247 = V_25 << V_23 ;
if ( V_247 < V_240 * V_13 + V_24 )
continue;
V_243 = ( V_247 - V_24 ) % V_13 ;
if ( V_243 <= V_247 / V_242 )
break;
}
return V_23 ;
}
static inline int F_256 ( int V_13 , int V_24 )
{
int V_23 ;
int V_240 ;
int V_248 ;
int V_101 ;
V_240 = V_249 ;
if ( ! V_240 )
V_240 = 4 * ( F_255 ( V_250 ) + 1 ) ;
V_101 = F_23 ( V_251 , V_13 , V_24 ) ;
V_240 = V_136 ( V_240 , V_101 ) ;
while ( V_240 > 1 ) {
V_248 = 16 ;
while ( V_248 >= 4 ) {
V_23 = F_253 ( V_13 , V_240 ,
V_251 , V_248 , V_24 ) ;
if ( V_23 <= V_251 )
return V_23 ;
V_248 /= 2 ;
}
V_240 -- ;
}
V_23 = F_253 ( V_13 , 1 , V_251 , 1 , V_24 ) ;
if ( V_23 <= V_251 )
return V_23 ;
V_23 = F_253 ( V_13 , 1 , V_252 , 1 , V_24 ) ;
if ( V_23 < V_252 )
return V_23 ;
return - V_253 ;
}
static void
F_257 ( struct V_104 * V_38 )
{
V_38 -> V_158 = 0 ;
F_258 ( & V_38 -> V_105 ) ;
F_259 ( & V_38 -> V_160 ) ;
#ifdef F_2
F_260 ( & V_38 -> V_109 , 0 ) ;
F_260 ( & V_38 -> V_110 , 0 ) ;
F_259 ( & V_38 -> V_107 ) ;
#endif
}
static inline int F_261 ( struct V_1 * V_2 )
{
F_262 ( V_254 <
V_255 * sizeof( struct V_163 ) ) ;
V_2 -> V_8 = F_263 ( sizeof( struct V_163 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_198 ( V_2 ) ;
return 1 ;
}
static void F_264 ( int V_108 )
{
struct V_9 * V_9 ;
struct V_104 * V_38 ;
F_265 ( V_104 -> V_13 < sizeof( struct V_104 ) ) ;
V_9 = F_141 ( V_104 , V_256 , V_108 ) ;
F_265 ( ! V_9 ) ;
if ( F_144 ( V_9 ) != V_108 ) {
F_58 ( L_60 , V_108 ) ;
F_58 ( L_61 ) ;
}
V_38 = V_9 -> V_42 ;
F_265 ( ! V_38 ) ;
V_9 -> V_42 = F_14 ( V_104 , V_38 ) ;
V_9 -> V_22 = 1 ;
V_9 -> V_34 = 0 ;
V_104 -> V_108 [ V_108 ] = V_38 ;
#ifdef F_2
F_70 ( V_104 , V_38 , V_97 ) ;
F_56 ( V_104 , V_38 ) ;
#endif
F_243 ( V_104 , V_38 , sizeof( struct V_104 ) ) ;
F_257 ( V_38 ) ;
F_90 ( V_104 , V_108 , V_9 -> V_12 ) ;
F_162 ( V_38 , V_9 , V_192 ) ;
}
static void F_266 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_38 ;
F_226 (s, node, n) {
F_250 ( V_104 , V_38 ) ;
V_2 -> V_108 [ V_108 ] = NULL ;
}
}
static int F_267 ( struct V_1 * V_2 )
{
int V_108 ;
F_268 (node, N_NORMAL_MEMORY) {
struct V_104 * V_38 ;
if ( V_257 == V_258 ) {
F_264 ( V_108 ) ;
continue;
}
V_38 = F_244 ( V_104 ,
V_259 , V_108 ) ;
if ( ! V_38 ) {
F_266 ( V_2 ) ;
return 0 ;
}
V_2 -> V_108 [ V_108 ] = V_38 ;
F_257 ( V_38 ) ;
}
return 1 ;
}
static void F_269 ( struct V_1 * V_2 , unsigned long V_136 )
{
if ( V_136 < V_260 )
V_136 = V_260 ;
else if ( V_136 > V_261 )
V_136 = V_261 ;
V_2 -> V_178 = V_136 ;
}
static int F_270 ( struct V_1 * V_2 , int V_262 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_13 = V_2 -> V_19 ;
int V_23 ;
V_13 = F_271 ( V_13 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_18 ) && ! ( V_3 & V_20 ) &&
! V_2 -> F_101 )
V_2 -> V_3 |= V_81 ;
else
V_2 -> V_3 &= ~ V_81 ;
if ( ( V_3 & V_17 ) && V_13 == V_2 -> V_19 )
V_13 += sizeof( void * ) ;
#endif
V_2 -> V_22 = V_13 ;
if ( ( ( V_3 & ( V_20 | V_18 ) ) ||
V_2 -> F_101 ) ) {
V_2 -> V_14 = V_13 ;
V_13 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_21 )
V_13 += 2 * sizeof( struct V_50 ) ;
if ( V_3 & V_17 )
V_13 += sizeof( void * ) ;
#endif
V_13 = F_271 ( V_13 , V_2 -> V_263 ) ;
V_2 -> V_13 = V_13 ;
if ( V_262 >= 0 )
V_23 = V_262 ;
else
V_23 = F_256 ( V_13 , V_2 -> V_24 ) ;
if ( V_23 < 0 )
return 0 ;
V_2 -> V_132 = 0 ;
if ( V_23 )
V_2 -> V_132 |= V_264 ;
if ( V_2 -> V_3 & V_265 )
V_2 -> V_132 |= V_266 ;
if ( V_2 -> V_3 & V_141 )
V_2 -> V_132 |= V_267 ;
V_2 -> V_128 = F_24 ( V_23 , V_13 , V_2 -> V_24 ) ;
V_2 -> V_136 = F_24 ( F_225 ( V_13 ) , V_13 , V_2 -> V_24 ) ;
if ( F_26 ( V_2 -> V_128 ) > F_26 ( V_2 -> F_254 ) )
V_2 -> F_254 = V_2 -> V_128 ;
return ! ! F_26 ( V_2 -> V_128 ) ;
}
static int F_272 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_100 ( V_2 -> V_13 , V_3 , V_2 -> V_44 , V_2 -> F_101 ) ;
V_2 -> V_24 = 0 ;
if ( V_154 && ( V_2 -> V_3 & V_20 ) )
V_2 -> V_24 = sizeof( struct V_152 ) ;
if ( ! F_270 ( V_2 , - 1 ) )
goto error;
if ( V_120 ) {
if ( F_225 ( V_2 -> V_13 ) > F_225 ( V_2 -> V_19 ) ) {
V_2 -> V_3 &= ~ V_268 ;
V_2 -> V_14 = 0 ;
if ( ! F_270 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_39 ) && \
F_35 ( V_40 )
if ( F_273 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_41 ;
#endif
F_269 ( V_2 , F_274 ( V_2 -> V_13 ) / 2 ) ;
if ( ! F_4 ( V_2 ) )
V_2 -> V_169 = 0 ;
else if ( V_2 -> V_13 >= V_25 )
V_2 -> V_169 = 2 ;
else if ( V_2 -> V_13 >= 1024 )
V_2 -> V_169 = 6 ;
else if ( V_2 -> V_13 >= 256 )
V_2 -> V_169 = 13 ;
else
V_2 -> V_169 = 30 ;
#ifdef F_176
V_2 -> V_177 = 1000 ;
#endif
if ( ! F_267 ( V_2 ) )
goto error;
if ( F_261 ( V_2 ) )
return 0 ;
F_266 ( V_2 ) ;
error:
if ( V_3 & V_269 )
F_275 ( L_62
L_63 ,
V_2 -> V_44 , ( unsigned long ) V_2 -> V_13 , V_2 -> V_13 ,
F_25 ( V_2 -> V_128 ) , V_2 -> V_14 , V_3 ) ;
return - V_270 ;
}
static void F_276 ( struct V_1 * V_2 , struct V_9 * V_9 ,
const char * V_46 )
{
#ifdef F_2
void * V_16 = F_13 ( V_9 ) ;
void * V_5 ;
unsigned long * V_45 = F_277 ( F_278 ( V_9 -> V_12 ) *
sizeof( long ) , V_211 ) ;
if ( ! V_45 )
return;
F_69 ( V_2 , V_9 , V_46 , V_2 -> V_44 ) ;
F_27 ( V_9 ) ;
F_43 ( V_2 , V_9 , V_45 ) ;
F_150 (p, s, addr, page->objects) {
if ( ! F_279 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) ) {
F_58 ( L_64 , V_5 , V_5 - V_16 ) ;
F_59 ( V_2 , V_5 ) ;
}
}
F_29 ( V_9 ) ;
F_280 ( V_45 ) ;
#endif
}
static void F_281 ( struct V_1 * V_2 , struct V_104 * V_38 )
{
struct V_9 * V_9 , * V_153 ;
F_171 (page, h, &n->partial, lru) {
if ( ! V_9 -> V_22 ) {
F_165 ( V_38 , V_9 ) ;
F_161 ( V_2 , V_9 ) ;
} else {
F_276 ( V_2 , V_9 ,
L_65 ) ;
}
}
}
static inline int F_282 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_38 ;
F_212 ( V_2 ) ;
F_226 (s, node, n) {
F_281 ( V_2 , V_38 ) ;
if ( V_38 -> V_158 || F_86 ( V_2 , V_108 ) )
return 1 ;
}
F_283 ( V_2 -> V_8 ) ;
F_266 ( V_2 ) ;
return 0 ;
}
int F_284 ( struct V_1 * V_2 )
{
return F_282 ( V_2 ) ;
}
static int T_6 F_285 ( char * V_113 )
{
F_286 ( & V_113 , & V_245 ) ;
return 1 ;
}
static int T_6 F_287 ( char * V_113 )
{
F_286 ( & V_113 , & V_251 ) ;
V_251 = V_136 ( V_251 , V_252 - 1 ) ;
return 1 ;
}
static int T_6 F_288 ( char * V_113 )
{
F_286 ( & V_113 , & V_249 ) ;
return 1 ;
}
void * F_289 ( T_1 V_13 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_13 > V_271 ) )
return F_290 ( V_13 , V_3 ) ;
V_2 = F_291 ( V_13 , V_3 ) ;
if ( F_3 ( F_292 ( V_2 ) ) )
return V_2 ;
V_230 = F_238 ( V_2 , V_3 , V_231 ) ;
F_242 ( V_231 , V_230 , V_13 , V_2 -> V_13 , V_3 ) ;
F_243 ( V_2 , V_230 , V_13 ) ;
return V_230 ;
}
static void * F_293 ( T_1 V_13 , T_7 V_3 , int V_108 )
{
struct V_9 * V_9 ;
void * V_122 = NULL ;
V_3 |= V_264 | V_129 ;
V_9 = F_294 ( V_108 , V_3 , F_225 ( V_13 ) ) ;
if ( V_9 )
V_122 = F_13 ( V_9 ) ;
F_103 ( V_122 , V_13 , V_3 ) ;
return V_122 ;
}
void * F_295 ( T_1 V_13 , T_7 V_3 , int V_108 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_13 > V_271 ) ) {
V_230 = F_293 ( V_13 , V_3 , V_108 ) ;
F_247 ( V_231 , V_230 ,
V_13 , V_25 << F_225 ( V_13 ) ,
V_3 , V_108 ) ;
return V_230 ;
}
V_2 = F_291 ( V_13 , V_3 ) ;
if ( F_3 ( F_292 ( V_2 ) ) )
return V_2 ;
V_230 = F_233 ( V_2 , V_3 , V_108 , V_231 ) ;
F_247 ( V_231 , V_230 , V_13 , V_2 -> V_13 , V_3 , V_108 ) ;
F_243 ( V_2 , V_230 , V_13 ) ;
return V_230 ;
}
static T_1 F_296 ( const void * V_10 )
{
struct V_9 * V_9 ;
if ( F_3 ( V_10 == V_272 ) )
return 0 ;
V_9 = F_157 ( V_10 ) ;
if ( F_3 ( ! F_79 ( V_9 ) ) ) {
F_168 ( ! F_297 ( V_9 ) ) ;
return V_25 << F_76 ( V_9 ) ;
}
return F_22 ( V_9 -> V_148 ) ;
}
T_1 F_298 ( const void * V_10 )
{
T_1 V_13 = F_296 ( V_10 ) ;
F_299 ( V_10 , V_13 ) ;
return V_13 ;
}
void F_280 ( const void * V_27 )
{
struct V_9 * V_9 ;
void * V_10 = ( void * ) V_27 ;
F_300 ( V_231 , V_27 ) ;
if ( F_3 ( F_292 ( V_27 ) ) )
return;
V_9 = F_157 ( V_27 ) ;
if ( F_3 ( ! F_79 ( V_9 ) ) ) {
F_265 ( ! F_297 ( V_9 ) ) ;
F_106 ( V_27 ) ;
F_301 ( V_9 , F_76 ( V_9 ) ) ;
return;
}
F_249 ( V_9 -> V_148 , V_9 , V_10 , V_231 ) ;
}
int F_302 ( struct V_1 * V_2 , bool V_273 )
{
int V_108 ;
int V_55 ;
struct V_104 * V_38 ;
struct V_9 * V_9 ;
struct V_9 * V_70 ;
struct V_155 V_274 ;
struct V_155 V_275 [ V_276 ] ;
unsigned long V_3 ;
int V_230 = 0 ;
if ( V_273 ) {
V_2 -> V_169 = 0 ;
V_2 -> V_178 = 0 ;
F_303 () ;
}
F_212 ( V_2 ) ;
F_226 (s, node, n) {
F_259 ( & V_274 ) ;
for ( V_55 = 0 ; V_55 < V_276 ; V_55 ++ )
F_259 ( V_275 + V_55 ) ;
F_219 ( & V_38 -> V_105 , V_3 ) ;
F_171 (page, t, &n->partial, lru) {
int free = V_9 -> V_12 - V_9 -> V_22 ;
F_236 () ;
F_265 ( free <= 0 ) ;
if ( free == V_9 -> V_12 ) {
F_304 ( & V_9 -> V_106 , & V_274 ) ;
V_38 -> V_158 -- ;
} else if ( free <= V_276 )
F_304 ( & V_9 -> V_106 , V_275 + free - 1 ) ;
}
for ( V_55 = V_276 - 1 ; V_55 >= 0 ; V_55 -- )
F_305 ( V_275 + V_55 , & V_38 -> V_160 ) ;
F_221 ( & V_38 -> V_105 , V_3 ) ;
F_171 (page, t, &discard, lru)
F_161 ( V_2 , V_9 ) ;
if ( F_86 ( V_2 , V_108 ) )
V_230 = 1 ;
}
return V_230 ;
}
static int F_306 ( void * V_277 )
{
struct V_1 * V_2 ;
F_307 ( & V_278 ) ;
F_220 (s, &slab_caches, list)
F_302 ( V_2 , false ) ;
F_308 ( & V_278 ) ;
return 0 ;
}
static void F_309 ( void * V_277 )
{
struct V_104 * V_38 ;
struct V_1 * V_2 ;
struct V_279 * V_280 = V_277 ;
int V_281 ;
V_281 = V_280 -> V_282 ;
if ( V_281 < 0 )
return;
F_307 ( & V_278 ) ;
F_220 (s, &slab_caches, list) {
V_38 = F_87 ( V_2 , V_281 ) ;
if ( V_38 ) {
F_265 ( F_86 ( V_2 , V_281 ) ) ;
V_2 -> V_108 [ V_281 ] = NULL ;
F_250 ( V_104 , V_38 ) ;
}
}
F_308 ( & V_278 ) ;
}
static int F_310 ( void * V_277 )
{
struct V_104 * V_38 ;
struct V_1 * V_2 ;
struct V_279 * V_280 = V_277 ;
int V_213 = V_280 -> V_282 ;
int V_230 = 0 ;
if ( V_213 < 0 )
return 0 ;
F_307 ( & V_278 ) ;
F_220 (s, &slab_caches, list) {
V_38 = F_239 ( V_104 , V_259 ) ;
if ( ! V_38 ) {
V_230 = - V_283 ;
goto V_116;
}
F_257 ( V_38 ) ;
V_2 -> V_108 [ V_213 ] = V_38 ;
}
V_116:
F_308 ( & V_278 ) ;
return V_230 ;
}
static int F_311 ( struct V_284 * V_285 ,
unsigned long V_286 , void * V_277 )
{
int V_230 = 0 ;
switch ( V_286 ) {
case V_287 :
V_230 = F_310 ( V_277 ) ;
break;
case V_288 :
V_230 = F_306 ( V_277 ) ;
break;
case V_289 :
case V_290 :
F_309 ( V_277 ) ;
break;
case V_291 :
case V_292 :
break;
}
if ( V_230 )
V_230 = F_312 ( V_230 ) ;
else
V_230 = V_293 ;
return V_230 ;
}
static struct V_1 * T_6 F_313 ( struct V_1 * V_294 )
{
int V_108 ;
struct V_1 * V_2 = F_314 ( V_1 , V_256 ) ;
struct V_104 * V_38 ;
memcpy ( V_2 , V_294 , V_1 -> V_19 ) ;
F_209 ( V_2 , F_55 () ) ;
F_226 (s, node, n) {
struct V_9 * V_5 ;
F_220 (p, &n->partial, lru)
V_5 -> V_148 = V_2 ;
#ifdef F_2
F_220 (p, &n->full, lru)
V_5 -> V_148 = V_2 ;
#endif
}
F_315 ( V_2 ) ;
F_83 ( & V_2 -> V_295 , & V_296 ) ;
return V_2 ;
}
void T_6 F_316 ( void )
{
static V_297 struct V_1 V_298 ,
V_299 ;
if ( F_317 () )
V_251 = 0 ;
V_104 = & V_299 ;
V_1 = & V_298 ;
F_318 ( V_104 , L_66 ,
sizeof( struct V_104 ) , V_300 ) ;
F_319 ( & V_301 ) ;
V_257 = V_302 ;
F_318 ( V_1 , L_67 ,
F_320 ( struct V_1 , V_108 ) +
V_303 * sizeof( struct V_104 * ) ,
V_300 ) ;
V_1 = F_313 ( & V_298 ) ;
V_104 = F_313 ( & V_299 ) ;
F_321 ( 0 ) ;
#ifdef F_322
F_323 ( & V_304 ) ;
#endif
F_39 ( L_68 ,
F_324 () ,
V_245 , V_251 , V_249 ,
V_250 , V_303 ) ;
}
void T_6 F_325 ( void )
{
}
struct V_1 *
F_326 ( const char * V_44 , T_1 V_13 , T_1 V_263 ,
unsigned long V_3 , void (* F_101)( void * ) )
{
struct V_1 * V_2 , * V_164 ;
V_2 = F_327 ( V_13 , V_263 , V_3 , V_44 , F_101 ) ;
if ( V_2 ) {
V_2 -> V_305 ++ ;
V_2 -> V_19 = F_254 ( V_2 -> V_19 , ( int ) V_13 ) ;
V_2 -> V_22 = F_328 ( int , V_2 -> V_22 , F_271 ( V_13 , sizeof( void * ) ) ) ;
F_329 (c, s) {
V_164 -> V_19 = V_2 -> V_19 ;
V_164 -> V_22 = F_328 ( int , V_164 -> V_22 ,
F_271 ( V_13 , sizeof( void * ) ) ) ;
}
if ( F_7 ( V_2 , V_44 ) ) {
V_2 -> V_305 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_330 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_306 ;
V_306 = F_272 ( V_2 , V_3 ) ;
if ( V_306 )
return V_306 ;
if ( V_257 <= V_307 )
return 0 ;
F_8 ( V_2 ) ;
V_306 = F_6 ( V_2 ) ;
if ( V_306 )
F_282 ( V_2 ) ;
return V_306 ;
}
static int F_331 ( struct V_284 * V_308 ,
unsigned long V_286 , void * V_309 )
{
long V_63 = ( long ) V_309 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_286 ) {
case V_310 :
case V_311 :
case V_312 :
case V_313 :
F_307 ( & V_278 ) ;
F_220 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_209 ( V_2 , V_63 ) ;
F_42 ( V_3 ) ;
}
F_308 ( & V_278 ) ;
break;
default:
break;
}
return V_293 ;
}
void * F_332 ( T_1 V_13 , T_7 V_212 , unsigned long V_314 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_13 > V_271 ) )
return F_290 ( V_13 , V_212 ) ;
V_2 = F_291 ( V_13 , V_212 ) ;
if ( F_3 ( F_292 ( V_2 ) ) )
return V_2 ;
V_230 = F_238 ( V_2 , V_212 , V_314 ) ;
F_242 ( V_314 , V_230 , V_13 , V_2 -> V_13 , V_212 ) ;
return V_230 ;
}
void * F_333 ( T_1 V_13 , T_7 V_212 ,
int V_108 , unsigned long V_314 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_13 > V_271 ) ) {
V_230 = F_293 ( V_13 , V_212 , V_108 ) ;
F_247 ( V_314 , V_230 ,
V_13 , V_25 << F_225 ( V_13 ) ,
V_212 , V_108 ) ;
return V_230 ;
}
V_2 = F_291 ( V_13 , V_212 ) ;
if ( F_3 ( F_292 ( V_2 ) ) )
return V_2 ;
V_230 = F_233 ( V_2 , V_212 , V_108 , V_314 ) ;
F_247 ( V_314 , V_230 , V_13 , V_2 -> V_13 , V_212 , V_108 ) ;
return V_230 ;
}
static int F_334 ( struct V_9 * V_9 )
{
return V_9 -> V_22 ;
}
static int F_335 ( struct V_9 * V_9 )
{
return V_9 -> V_12 ;
}
static int F_336 ( struct V_1 * V_2 , struct V_9 * V_9 ,
unsigned long * V_45 )
{
void * V_5 ;
void * V_16 = F_13 ( V_9 ) ;
if ( ! F_78 ( V_2 , V_9 ) ||
! F_80 ( V_2 , V_9 , NULL ) )
return 0 ;
F_337 ( V_45 , V_9 -> V_12 ) ;
F_43 ( V_2 , V_9 , V_45 ) ;
F_150 (p, s, addr, page->objects) {
if ( F_279 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) )
if ( ! F_77 ( V_2 , V_9 , V_5 , V_111 ) )
return 0 ;
}
F_150 (p, s, addr, page->objects)
if ( ! F_279 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) )
if ( ! F_77 ( V_2 , V_9 , V_5 , V_97 ) )
return 0 ;
return 1 ;
}
static void F_338 ( struct V_1 * V_2 , struct V_9 * V_9 ,
unsigned long * V_45 )
{
F_27 ( V_9 ) ;
F_336 ( V_2 , V_9 , V_45 ) ;
F_29 ( V_9 ) ;
}
static int F_339 ( struct V_1 * V_2 ,
struct V_104 * V_38 , unsigned long * V_45 )
{
unsigned long V_315 = 0 ;
struct V_9 * V_9 ;
unsigned long V_3 ;
F_219 ( & V_38 -> V_105 , V_3 ) ;
F_220 (page, &n->partial, lru) {
F_338 ( V_2 , V_9 , V_45 ) ;
V_315 ++ ;
}
if ( V_315 != V_38 -> V_158 )
F_58 ( L_69 ,
V_2 -> V_44 , V_315 , V_38 -> V_158 ) ;
if ( ! ( V_2 -> V_3 & V_21 ) )
goto V_116;
F_220 (page, &n->full, lru) {
F_338 ( V_2 , V_9 , V_45 ) ;
V_315 ++ ;
}
if ( V_315 != F_88 ( & V_38 -> V_109 ) )
F_58 ( L_70 ,
V_2 -> V_44 , V_315 , F_88 ( & V_38 -> V_109 ) ) ;
V_116:
F_221 ( & V_38 -> V_105 , V_3 ) ;
return V_315 ;
}
static long F_340 ( struct V_1 * V_2 )
{
int V_108 ;
unsigned long V_315 = 0 ;
unsigned long * V_45 = F_341 ( F_278 ( F_26 ( V_2 -> F_254 ) ) *
sizeof( unsigned long ) , V_259 ) ;
struct V_104 * V_38 ;
if ( ! V_45 )
return - V_283 ;
F_212 ( V_2 ) ;
F_226 (s, node, n)
V_315 += F_339 ( V_2 , V_38 , V_45 ) ;
F_280 ( V_45 ) ;
return V_315 ;
}
static void F_342 ( struct V_316 * V_70 )
{
if ( V_70 -> F_254 )
F_343 ( ( unsigned long ) V_70 -> V_317 ,
F_225 ( sizeof( struct V_318 ) * V_70 -> F_254 ) ) ;
}
static int F_344 ( struct V_316 * V_70 , unsigned long F_254 , T_7 V_3 )
{
struct V_318 * V_189 ;
int V_23 ;
V_23 = F_225 ( sizeof( struct V_318 ) * F_254 ) ;
V_189 = ( void * ) F_345 ( V_3 , V_23 ) ;
if ( ! V_189 )
return 0 ;
if ( V_70 -> V_315 ) {
memcpy ( V_189 , V_70 -> V_317 , sizeof( struct V_318 ) * V_70 -> V_315 ) ;
F_342 ( V_70 ) ;
}
V_70 -> F_254 = F_254 ;
V_70 -> V_317 = V_189 ;
return 1 ;
}
static int F_346 ( struct V_316 * V_70 , struct V_1 * V_2 ,
const struct V_50 * V_50 )
{
long V_89 , V_93 , V_319 ;
struct V_318 * V_189 ;
unsigned long V_320 ;
unsigned long V_321 = V_67 - V_50 -> V_66 ;
V_89 = - 1 ;
V_93 = V_70 -> V_315 ;
for ( ; ; ) {
V_319 = V_89 + ( V_93 - V_89 + 1 ) / 2 ;
if ( V_319 == V_93 )
break;
V_320 = V_70 -> V_317 [ V_319 ] . V_16 ;
if ( V_50 -> V_16 == V_320 ) {
V_189 = & V_70 -> V_317 [ V_319 ] ;
V_189 -> V_315 ++ ;
if ( V_50 -> V_66 ) {
V_189 -> V_322 += V_321 ;
if ( V_321 < V_189 -> V_323 )
V_189 -> V_323 = V_321 ;
if ( V_321 > V_189 -> V_324 )
V_189 -> V_324 = V_321 ;
if ( V_50 -> V_64 < V_189 -> V_325 )
V_189 -> V_325 = V_50 -> V_64 ;
if ( V_50 -> V_64 > V_189 -> V_326 )
V_189 -> V_326 = V_50 -> V_64 ;
F_347 ( V_50 -> V_63 ,
F_348 ( V_189 -> V_327 ) ) ;
}
F_349 ( F_144 ( F_350 ( V_50 ) ) , V_189 -> V_328 ) ;
return 1 ;
}
if ( V_50 -> V_16 < V_320 )
V_93 = V_319 ;
else
V_89 = V_319 ;
}
if ( V_70 -> V_315 >= V_70 -> F_254 && ! F_344 ( V_70 , 2 * V_70 -> F_254 , V_211 ) )
return 0 ;
V_189 = V_70 -> V_317 + V_319 ;
if ( V_319 < V_70 -> V_315 )
memmove ( V_189 + 1 , V_189 ,
( V_70 -> V_315 - V_319 ) * sizeof( struct V_318 ) ) ;
V_70 -> V_315 ++ ;
V_189 -> V_315 = 1 ;
V_189 -> V_16 = V_50 -> V_16 ;
V_189 -> V_322 = V_321 ;
V_189 -> V_323 = V_321 ;
V_189 -> V_324 = V_321 ;
V_189 -> V_325 = V_50 -> V_64 ;
V_189 -> V_326 = V_50 -> V_64 ;
F_351 ( F_348 ( V_189 -> V_327 ) ) ;
F_347 ( V_50 -> V_63 , F_348 ( V_189 -> V_327 ) ) ;
F_352 ( V_189 -> V_328 ) ;
F_349 ( F_144 ( F_350 ( V_50 ) ) , V_189 -> V_328 ) ;
return 1 ;
}
static void F_353 ( struct V_316 * V_70 , struct V_1 * V_2 ,
struct V_9 * V_9 , enum V_51 V_52 ,
unsigned long * V_45 )
{
void * V_16 = F_13 ( V_9 ) ;
void * V_5 ;
F_337 ( V_45 , V_9 -> V_12 ) ;
F_43 ( V_2 , V_9 , V_45 ) ;
F_150 (p, s, addr, page->objects)
if ( ! F_279 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) )
F_346 ( V_70 , V_2 , F_51 ( V_2 , V_5 , V_52 ) ) ;
}
static int F_354 ( struct V_1 * V_2 , char * V_79 ,
enum V_51 V_52 )
{
int V_329 = 0 ;
unsigned long V_55 ;
struct V_316 V_70 = { 0 , 0 , NULL } ;
int V_108 ;
unsigned long * V_45 = F_341 ( F_278 ( F_26 ( V_2 -> F_254 ) ) *
sizeof( unsigned long ) , V_259 ) ;
struct V_104 * V_38 ;
if ( ! V_45 || ! F_344 ( & V_70 , V_25 / sizeof( struct V_318 ) ,
V_330 ) ) {
F_280 ( V_45 ) ;
return sprintf ( V_79 , L_71 ) ;
}
F_212 ( V_2 ) ;
F_226 (s, node, n) {
unsigned long V_3 ;
struct V_9 * V_9 ;
if ( ! F_88 ( & V_38 -> V_109 ) )
continue;
F_219 ( & V_38 -> V_105 , V_3 ) ;
F_220 (page, &n->partial, lru)
F_353 ( & V_70 , V_2 , V_9 , V_52 , V_45 ) ;
F_220 (page, &n->full, lru)
F_353 ( & V_70 , V_2 , V_9 , V_52 , V_45 ) ;
F_221 ( & V_38 -> V_105 , V_3 ) ;
}
for ( V_55 = 0 ; V_55 < V_70 . V_315 ; V_55 ++ ) {
struct V_318 * V_189 = & V_70 . V_317 [ V_55 ] ;
if ( V_329 > V_25 - V_331 - 100 )
break;
V_329 += sprintf ( V_79 + V_329 , L_72 , V_189 -> V_315 ) ;
if ( V_189 -> V_16 )
V_329 += sprintf ( V_79 + V_329 , L_73 , ( void * ) V_189 -> V_16 ) ;
else
V_329 += sprintf ( V_79 + V_329 , L_74 ) ;
if ( V_189 -> V_322 != V_189 -> V_323 ) {
V_329 += sprintf ( V_79 + V_329 , L_75 ,
V_189 -> V_323 ,
( long ) F_355 ( V_189 -> V_322 , V_189 -> V_315 ) ,
V_189 -> V_324 ) ;
} else
V_329 += sprintf ( V_79 + V_329 , L_76 ,
V_189 -> V_323 ) ;
if ( V_189 -> V_325 != V_189 -> V_326 )
V_329 += sprintf ( V_79 + V_329 , L_77 ,
V_189 -> V_325 , V_189 -> V_326 ) ;
else
V_329 += sprintf ( V_79 + V_329 , L_78 ,
V_189 -> V_325 ) ;
if ( F_356 () > 1 &&
! F_357 ( F_348 ( V_189 -> V_327 ) ) &&
V_329 < V_25 - 60 )
V_329 += F_358 ( V_79 + V_329 , V_25 - V_329 - 50 ,
L_79 ,
F_359 ( F_348 ( V_189 -> V_327 ) ) ) ;
if ( V_332 > 1 && ! F_360 ( V_189 -> V_328 ) &&
V_329 < V_25 - 60 )
V_329 += F_358 ( V_79 + V_329 , V_25 - V_329 - 50 ,
L_80 ,
F_361 ( & V_189 -> V_328 ) ) ;
V_329 += sprintf ( V_79 + V_329 , L_81 ) ;
}
F_342 ( & V_70 ) ;
F_280 ( V_45 ) ;
if ( ! V_70 . V_315 )
V_329 += sprintf ( V_79 , L_82 ) ;
return V_329 ;
}
static void T_6 F_362 ( void )
{
T_3 * V_5 ;
F_262 ( V_333 > 16 || V_255 < 10 ) ;
F_58 ( L_83 ) ;
F_58 ( L_84 ) ;
F_58 ( L_85 ) ;
V_5 = F_277 ( 16 , V_259 ) ;
V_5 [ 16 ] = 0x12 ;
F_58 ( L_86 ,
V_5 + 16 ) ;
F_340 ( V_334 [ 4 ] ) ;
V_5 = F_277 ( 32 , V_259 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_58 ( L_87 ,
V_5 ) ;
F_58 ( L_88 ) ;
F_340 ( V_334 [ 5 ] ) ;
V_5 = F_277 ( 64 , V_259 ) ;
V_5 += 64 + ( F_178 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_58 ( L_89 ,
V_5 ) ;
F_58 ( L_88 ) ;
F_340 ( V_334 [ 6 ] ) ;
F_58 ( L_90 ) ;
V_5 = F_277 ( 128 , V_259 ) ;
F_280 ( V_5 ) ;
* V_5 = 0x78 ;
F_58 ( L_91 , V_5 ) ;
F_340 ( V_334 [ 7 ] ) ;
V_5 = F_277 ( 256 , V_259 ) ;
F_280 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_58 ( L_92 , V_5 ) ;
F_340 ( V_334 [ 8 ] ) ;
V_5 = F_277 ( 512 , V_259 ) ;
F_280 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_58 ( L_93 , V_5 ) ;
F_340 ( V_334 [ 9 ] ) ;
}
static void F_362 ( void ) {}
static T_9 F_363 ( struct V_1 * V_2 ,
char * V_79 , unsigned long V_3 )
{
unsigned long V_335 = 0 ;
int V_108 ;
int V_27 ;
unsigned long * V_328 ;
V_328 = F_277 ( sizeof( unsigned long ) * V_303 , V_259 ) ;
if ( ! V_328 )
return - V_283 ;
if ( V_3 & V_336 ) {
int V_63 ;
F_199 (cpu) {
struct V_163 * V_164 = F_200 ( V_2 -> V_8 ,
V_63 ) ;
int V_108 ;
struct V_9 * V_9 ;
V_9 = F_235 ( V_164 -> V_9 ) ;
if ( ! V_9 )
continue;
V_108 = F_144 ( V_9 ) ;
if ( V_3 & V_337 )
V_27 = V_9 -> V_12 ;
else if ( V_3 & V_338 )
V_27 = V_9 -> V_22 ;
else
V_27 = 1 ;
V_335 += V_27 ;
V_328 [ V_108 ] += V_27 ;
V_9 = F_235 ( V_164 -> V_160 ) ;
if ( V_9 ) {
V_108 = F_144 ( V_9 ) ;
if ( V_3 & V_337 )
F_364 ( 1 ) ;
else if ( V_3 & V_338 )
F_364 ( 1 ) ;
else
V_27 = V_9 -> V_140 ;
V_335 += V_27 ;
V_328 [ V_108 ] += V_27 ;
}
}
}
F_365 () ;
#ifdef F_2
if ( V_3 & V_339 ) {
struct V_104 * V_38 ;
F_226 (s, node, n) {
if ( V_3 & V_337 )
V_27 = F_88 ( & V_38 -> V_110 ) ;
else if ( V_3 & V_338 )
V_27 = F_88 ( & V_38 -> V_110 ) -
F_217 ( V_38 , F_215 ) ;
else
V_27 = F_88 ( & V_38 -> V_109 ) ;
V_335 += V_27 ;
V_328 [ V_108 ] += V_27 ;
}
} else
#endif
if ( V_3 & V_340 ) {
struct V_104 * V_38 ;
F_226 (s, node, n) {
if ( V_3 & V_337 )
V_27 = F_217 ( V_38 , F_335 ) ;
else if ( V_3 & V_338 )
V_27 = F_217 ( V_38 , F_334 ) ;
else
V_27 = V_38 -> V_158 ;
V_335 += V_27 ;
V_328 [ V_108 ] += V_27 ;
}
}
V_27 = sprintf ( V_79 , L_94 , V_335 ) ;
#ifdef F_176
for ( V_108 = 0 ; V_108 < V_303 ; V_108 ++ )
if ( V_328 [ V_108 ] )
V_27 += sprintf ( V_79 + V_27 , L_95 ,
V_108 , V_328 [ V_108 ] ) ;
#endif
F_366 () ;
F_280 ( V_328 ) ;
return V_27 + sprintf ( V_79 + V_27 , L_81 ) ;
}
static int F_367 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_38 ;
F_226 (s, node, n)
if ( F_88 ( & V_38 -> V_110 ) )
return 1 ;
return 0 ;
}
static T_9 F_368 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_13 ) ;
}
static T_9 F_369 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_263 ) ;
}
static T_9 F_370 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_19 ) ;
}
static T_9 F_371 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , F_26 ( V_2 -> V_128 ) ) ;
}
static T_9 F_372 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
unsigned long V_23 ;
int V_306 ;
V_306 = F_373 ( V_79 , 10 , & V_23 ) ;
if ( V_306 )
return V_306 ;
if ( V_23 > V_251 || V_23 < V_245 )
return - V_270 ;
F_270 ( V_2 , V_23 ) ;
return V_47 ;
}
static T_9 F_374 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , F_25 ( V_2 -> V_128 ) ) ;
}
static T_9 F_375 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_97 , V_2 -> V_178 ) ;
}
static T_9 F_376 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
unsigned long V_136 ;
int V_306 ;
V_306 = F_373 ( V_79 , 10 , & V_136 ) ;
if ( V_306 )
return V_306 ;
F_269 ( V_2 , V_136 ) ;
return V_47 ;
}
static T_9 F_377 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_98 , V_2 -> V_169 ) ;
}
static T_9 F_378 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
unsigned long V_12 ;
int V_306 ;
V_306 = F_373 ( V_79 , 10 , & V_12 ) ;
if ( V_306 )
return V_306 ;
if ( V_12 && ! F_4 ( V_2 ) )
return - V_270 ;
V_2 -> V_169 = V_12 ;
F_212 ( V_2 ) ;
return V_47 ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! V_2 -> F_101 )
return 0 ;
return sprintf ( V_79 , L_99 , V_2 -> F_101 ) ;
}
static T_9 F_380 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_305 < 0 ? 0 : V_2 -> V_305 - 1 ) ;
}
static T_9 F_381 ( struct V_1 * V_2 , char * V_79 )
{
return F_363 ( V_2 , V_79 , V_340 ) ;
}
static T_9 F_382 ( struct V_1 * V_2 , char * V_79 )
{
return F_363 ( V_2 , V_79 , V_336 ) ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_79 )
{
return F_363 ( V_2 , V_79 , V_339 | V_338 ) ;
}
static T_9 F_384 ( struct V_1 * V_2 , char * V_79 )
{
return F_363 ( V_2 , V_79 , V_340 | V_338 ) ;
}
static T_9 F_385 ( struct V_1 * V_2 , char * V_79 )
{
int V_12 = 0 ;
int V_140 = 0 ;
int V_63 ;
int V_329 ;
F_386 (cpu) {
struct V_9 * V_9 = F_200 ( V_2 -> V_8 , V_63 ) -> V_160 ;
if ( V_9 ) {
V_140 += V_9 -> V_140 ;
V_12 += V_9 -> V_206 ;
}
}
V_329 = sprintf ( V_79 , L_100 , V_12 , V_140 ) ;
#ifdef F_322
F_386 (cpu) {
struct V_9 * V_9 = F_200 ( V_2 -> V_8 , V_63 ) -> V_160 ;
if ( V_9 && V_329 < V_25 - 20 )
V_329 += sprintf ( V_79 + V_329 , L_101 , V_63 ,
V_9 -> V_206 , V_9 -> V_140 ) ;
}
#endif
return V_329 + sprintf ( V_79 + V_329 , L_81 ) ;
}
static T_9 F_387 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_141 ) ) ;
}
static T_9 F_388 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
V_2 -> V_3 &= ~ V_141 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_141 ;
return V_47 ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_300 ) ) ;
}
static T_9 F_390 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_265 ) ) ;
}
static T_9 F_391 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_392 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_24 ) ;
}
static T_9 F_393 ( struct V_1 * V_2 , char * V_79 )
{
return F_363 ( V_2 , V_79 , V_339 ) ;
}
static T_9 F_394 ( struct V_1 * V_2 , char * V_79 )
{
return F_363 ( V_2 , V_79 , V_339 | V_337 ) ;
}
static T_9 F_395 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_118 ) ) ;
}
static T_9 F_396 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
V_2 -> V_3 &= ~ V_118 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_118 ;
}
return V_47 ;
}
static T_9 F_397 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_103 ) ) ;
}
static T_9 F_398 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
if ( V_2 -> V_305 > 1 )
return - V_270 ;
V_2 -> V_3 &= ~ V_103 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_103 ;
}
return V_47 ;
}
static T_9 F_399 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_17 ) ) ;
}
static T_9 F_400 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( F_367 ( V_2 ) )
return - V_341 ;
V_2 -> V_3 &= ~ V_17 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_17 ;
}
F_270 ( V_2 , - 1 ) ;
return V_47 ;
}
static T_9 F_401 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_18 ) ) ;
}
static T_9 F_402 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( F_367 ( V_2 ) )
return - V_341 ;
V_2 -> V_3 &= ~ V_18 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_18 ;
}
F_270 ( V_2 , - 1 ) ;
return V_47 ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_21 ) ) ;
}
static T_9 F_404 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( F_367 ( V_2 ) )
return - V_341 ;
V_2 -> V_3 &= ~ V_21 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_21 ;
}
F_270 ( V_2 , - 1 ) ;
return V_47 ;
}
static T_9 F_405 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_406 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
int V_230 = - V_270 ;
if ( V_79 [ 0 ] == '1' ) {
V_230 = F_340 ( V_2 ) ;
if ( V_230 >= 0 )
V_230 = V_47 ;
}
return V_230 ;
}
static T_9 F_407 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return - V_253 ;
return F_354 ( V_2 , V_79 , V_69 ) ;
}
static T_9 F_408 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return - V_253 ;
return F_354 ( V_2 , V_79 , V_68 ) ;
}
static T_9 F_409 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_9 F_410 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
if ( V_2 -> V_305 > 1 )
return - V_270 ;
V_2 -> V_3 &= ~ V_119 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_119 ;
return V_47 ;
}
static T_9 F_411 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_412 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( V_79 [ 0 ] == '1' )
F_413 ( V_2 ) ;
else
return - V_270 ;
return V_47 ;
}
static T_9 F_414 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_177 / 10 ) ;
}
static T_9 F_415 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
unsigned long V_342 ;
int V_306 ;
V_306 = F_373 ( V_79 , 10 , & V_342 ) ;
if ( V_306 )
return V_306 ;
if ( V_342 <= 100 )
V_2 -> V_177 = V_342 * 10 ;
return V_47 ;
}
static int F_416 ( struct V_1 * V_2 , char * V_79 , enum V_6 V_7 )
{
unsigned long V_343 = 0 ;
int V_63 ;
int V_329 ;
int * V_85 = F_341 ( V_250 * sizeof( int ) , V_259 ) ;
if ( ! V_85 )
return - V_283 ;
F_386 (cpu) {
unsigned V_27 = F_200 ( V_2 -> V_8 , V_63 ) -> F_9 [ V_7 ] ;
V_85 [ V_63 ] = V_27 ;
V_343 += V_27 ;
}
V_329 = sprintf ( V_79 , L_94 , V_343 ) ;
#ifdef F_322
F_386 (cpu) {
if ( V_85 [ V_63 ] && V_329 < V_25 - 20 )
V_329 += sprintf ( V_79 + V_329 , L_102 , V_63 , V_85 [ V_63 ] ) ;
}
#endif
F_280 ( V_85 ) ;
return V_329 + sprintf ( V_79 + V_329 , L_81 ) ;
}
static void F_417 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_63 ;
F_386 (cpu)
F_200 ( V_2 -> V_8 , V_63 ) -> F_9 [ V_7 ] = 0 ;
}
static T_9 F_418 ( struct V_344 * V_345 ,
struct V_346 * V_347 ,
char * V_79 )
{
struct V_348 * V_346 ;
struct V_1 * V_2 ;
int V_306 ;
V_346 = F_419 ( V_347 ) ;
V_2 = F_420 ( V_345 ) ;
if ( ! V_346 -> V_349 )
return - V_350 ;
V_306 = V_346 -> V_349 ( V_2 , V_79 ) ;
return V_306 ;
}
static T_9 F_421 ( struct V_344 * V_345 ,
struct V_346 * V_347 ,
const char * V_79 , T_1 V_329 )
{
struct V_348 * V_346 ;
struct V_1 * V_2 ;
int V_306 ;
V_346 = F_419 ( V_347 ) ;
V_2 = F_420 ( V_345 ) ;
if ( ! V_346 -> V_351 )
return - V_350 ;
V_306 = V_346 -> V_351 ( V_2 , V_79 , V_329 ) ;
#ifdef F_422
if ( V_257 >= V_352 && V_306 >= 0 && F_423 ( V_2 ) ) {
struct V_1 * V_164 ;
F_307 ( & V_278 ) ;
if ( V_2 -> V_353 < V_329 )
V_2 -> V_353 = V_329 ;
F_329 (c, s)
V_346 -> V_351 ( V_164 , V_79 , V_329 ) ;
F_308 ( & V_278 ) ;
}
#endif
return V_306 ;
}
static void F_8 ( struct V_1 * V_2 )
{
#ifdef F_422
int V_55 ;
char * V_354 = NULL ;
struct V_1 * V_355 ;
if ( F_423 ( V_2 ) )
return;
V_355 = V_2 -> V_356 . V_355 ;
if ( ! V_355 -> V_353 )
return;
for ( V_55 = 0 ; V_55 < F_424 ( V_357 ) ; V_55 ++ ) {
char V_358 [ 64 ] ;
char * V_79 ;
struct V_348 * V_347 = F_419 ( V_357 [ V_55 ] ) ;
if ( ! V_347 || ! V_347 -> V_351 || ! V_347 -> V_349 )
continue;
if ( V_354 )
V_79 = V_354 ;
else if ( V_355 -> V_353 < F_424 ( V_358 ) )
V_79 = V_358 ;
else {
V_354 = ( char * ) F_425 ( V_259 ) ;
if ( F_168 ( ! V_354 ) )
continue;
V_79 = V_354 ;
}
V_347 -> V_349 ( V_355 , V_79 ) ;
V_347 -> V_351 ( V_2 , V_79 , strlen ( V_79 ) ) ;
}
if ( V_354 )
F_426 ( ( unsigned long ) V_354 ) ;
#endif
}
static void F_427 ( struct V_344 * V_359 )
{
F_428 ( F_420 ( V_359 ) ) ;
}
static int F_429 ( struct V_360 * V_360 , struct V_344 * V_345 )
{
struct V_361 * V_362 = F_430 ( V_345 ) ;
if ( V_362 == & V_363 )
return 1 ;
return 0 ;
}
static inline struct V_360 * F_431 ( struct V_1 * V_2 )
{
#ifdef F_422
if ( ! F_423 ( V_2 ) )
return V_2 -> V_356 . V_355 -> V_364 ;
#endif
return V_365 ;
}
static char * F_432 ( struct V_1 * V_2 )
{
char * V_44 = F_341 ( V_366 , V_259 ) ;
char * V_5 = V_44 ;
F_265 ( ! V_44 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_265 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_141 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_118 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_139 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_44 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_103 , V_2 -> V_13 ) ;
F_265 ( V_5 > V_44 + V_366 - 1 ) ;
return V_44 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_306 ;
const char * V_44 ;
int V_367 = F_433 ( V_2 ) ;
if ( V_367 ) {
F_434 ( & V_365 -> V_345 , V_2 -> V_44 ) ;
V_44 = V_2 -> V_44 ;
} else {
V_44 = F_432 ( V_2 ) ;
}
V_2 -> V_345 . V_360 = F_431 ( V_2 ) ;
V_306 = F_435 ( & V_2 -> V_345 , & V_363 , NULL , L_16 , V_44 ) ;
if ( V_306 )
goto V_368;
V_306 = F_436 ( & V_2 -> V_345 , & V_369 ) ;
if ( V_306 )
goto V_370;
#ifdef F_422
if ( F_423 ( V_2 ) ) {
V_2 -> V_364 = F_437 ( L_104 , NULL , & V_2 -> V_345 ) ;
if ( ! V_2 -> V_364 ) {
V_306 = - V_283 ;
goto V_370;
}
}
#endif
F_438 ( & V_2 -> V_345 , V_371 ) ;
if ( ! V_367 ) {
F_7 ( V_2 , V_2 -> V_44 ) ;
}
V_116:
if ( ! V_367 )
F_280 ( V_44 ) ;
return V_306 ;
V_370:
F_439 ( & V_2 -> V_345 ) ;
V_368:
F_440 ( & V_2 -> V_345 ) ;
goto V_116;
}
void F_441 ( struct V_1 * V_2 )
{
if ( V_257 < V_352 )
return;
#ifdef F_422
F_442 ( V_2 -> V_364 ) ;
#endif
F_438 ( & V_2 -> V_345 , V_372 ) ;
F_439 ( & V_2 -> V_345 ) ;
F_440 ( & V_2 -> V_345 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_44 )
{
struct V_373 * V_374 ;
if ( V_257 == V_352 ) {
F_434 ( & V_365 -> V_345 , V_44 ) ;
return F_443 ( & V_365 -> V_345 , & V_2 -> V_345 , V_44 ) ;
}
V_374 = F_341 ( sizeof( struct V_373 ) , V_259 ) ;
if ( ! V_374 )
return - V_283 ;
V_374 -> V_2 = V_2 ;
V_374 -> V_44 = V_44 ;
V_374 -> V_202 = V_375 ;
V_375 = V_374 ;
return 0 ;
}
static int T_6 F_444 ( void )
{
struct V_1 * V_2 ;
int V_306 ;
F_307 ( & V_278 ) ;
V_365 = F_437 ( L_105 , & V_376 , V_377 ) ;
if ( ! V_365 ) {
F_308 ( & V_278 ) ;
F_58 ( L_106 ) ;
return - V_253 ;
}
V_257 = V_352 ;
F_220 (s, &slab_caches, list) {
V_306 = F_6 ( V_2 ) ;
if ( V_306 )
F_58 ( L_107 ,
V_2 -> V_44 ) ;
}
while ( V_375 ) {
struct V_373 * V_374 = V_375 ;
V_375 = V_375 -> V_202 ;
V_306 = F_7 ( V_374 -> V_2 , V_374 -> V_44 ) ;
if ( V_306 )
F_58 ( L_108 ,
V_374 -> V_44 ) ;
F_280 ( V_374 ) ;
}
F_308 ( & V_278 ) ;
F_362 () ;
return 0 ;
}
void F_445 ( struct V_1 * V_2 , struct V_378 * V_379 )
{
unsigned long V_109 = 0 ;
unsigned long V_217 = 0 ;
unsigned long V_218 = 0 ;
int V_108 ;
struct V_104 * V_38 ;
F_226 (s, node, n) {
V_109 += F_89 ( V_38 ) ;
V_217 += F_216 ( V_38 ) ;
V_218 += F_217 ( V_38 , F_215 ) ;
}
V_379 -> V_380 = V_217 - V_218 ;
V_379 -> V_381 = V_217 ;
V_379 -> V_382 = V_109 ;
V_379 -> V_383 = V_109 ;
V_379 -> V_384 = F_26 ( V_2 -> V_128 ) ;
V_379 -> V_385 = F_25 ( V_2 -> V_128 ) ;
}
void F_446 ( struct V_386 * V_190 , struct V_1 * V_2 )
{
}
T_9 F_447 ( struct V_387 * V_387 , const char T_10 * V_354 ,
T_1 V_315 , T_11 * V_388 )
{
return - V_350 ;
}
