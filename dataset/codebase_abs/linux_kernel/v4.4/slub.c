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
struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_122 , void * V_123 , int V_124 ,
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
static inline void F_103 ( void * V_125 , T_1 V_13 , T_7 V_3 )
{
F_104 ( V_125 , V_13 , 1 , V_3 ) ;
F_105 ( V_125 , V_13 ) ;
}
static inline void F_106 ( const void * V_27 )
{
F_107 ( V_27 ) ;
F_108 ( V_27 ) ;
}
static inline struct V_1 * F_109 ( struct V_1 * V_2 ,
T_7 V_3 )
{
V_3 &= V_126 ;
F_110 ( V_3 ) ;
F_111 ( F_112 ( V_3 ) ) ;
if ( F_113 ( V_2 -> V_19 , V_3 , V_2 -> V_3 ) )
return NULL ;
return F_114 ( V_2 , V_3 ) ;
}
static inline void F_115 ( struct V_1 * V_2 , T_7 V_3 ,
T_1 V_13 , void * * V_5 )
{
T_1 V_55 ;
V_3 &= V_126 ;
for ( V_55 = 0 ; V_55 < V_13 ; V_55 ++ ) {
void * V_10 = V_5 [ V_55 ] ;
F_116 ( V_2 , V_3 , V_10 , F_22 ( V_2 ) ) ;
F_117 ( V_10 , V_2 -> V_19 , 1 ,
V_2 -> V_3 , V_3 ) ;
F_118 ( V_2 , V_10 ) ;
}
F_119 ( V_2 ) ;
}
static inline void F_120 ( struct V_1 * V_2 , void * V_27 )
{
F_121 ( V_27 , V_2 -> V_3 ) ;
#if F_35 ( V_127 ) || F_35 ( V_128 )
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_122 ( V_2 , V_27 , V_2 -> V_19 ) ;
F_123 ( V_27 , V_2 -> V_19 ) ;
F_42 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_129 ) )
F_124 ( V_27 , V_2 -> V_19 ) ;
F_125 ( V_2 , V_27 ) ;
}
static inline void F_126 ( struct V_1 * V_2 ,
void * V_122 , void * V_123 )
{
#if F_35 ( V_127 ) || \
F_35 ( V_128 ) || \
F_35 ( V_130 ) || \
F_35 ( V_131 ) || \
F_35 ( V_132 )
void * V_10 = V_122 ;
void * V_133 = V_123 ? : V_122 ;
do {
F_120 ( V_2 , V_10 ) ;
} while ( ( V_10 != V_133 ) &&
( V_10 = F_14 ( V_2 , V_10 ) ) );
#endif
}
static void F_127 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_10 )
{
F_97 ( V_2 , V_9 , V_10 ) ;
if ( F_3 ( V_2 -> F_101 ) ) {
F_128 ( V_2 , V_10 ) ;
V_2 -> F_101 ( V_10 ) ;
F_129 ( V_2 , V_10 ) ;
}
}
static inline struct V_9 * F_130 ( struct V_1 * V_2 ,
T_7 V_3 , int V_108 , struct V_26 V_134 )
{
struct V_9 * V_9 ;
int V_23 = F_25 ( V_134 ) ;
V_3 |= V_135 ;
if ( V_108 == V_136 )
V_9 = F_131 ( V_3 , V_23 ) ;
else
V_9 = F_132 ( V_108 , V_3 , V_23 ) ;
if ( V_9 && F_133 ( V_9 , V_3 , V_23 , V_2 ) ) {
F_134 ( V_9 , V_23 ) ;
V_9 = NULL ;
}
return V_9 ;
}
static struct V_9 * F_135 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
struct V_9 * V_9 ;
struct V_26 V_134 = V_2 -> V_134 ;
T_7 V_137 ;
void * V_89 , * V_5 ;
int V_138 , V_23 ;
V_3 &= V_126 ;
if ( F_112 ( V_3 ) )
F_136 () ;
V_3 |= V_2 -> V_139 ;
V_137 = ( V_3 | V_140 | V_141 ) & ~ V_142 ;
if ( ( V_137 & V_143 ) && F_25 ( V_134 ) > F_25 ( V_2 -> V_144 ) )
V_137 = ( V_137 | V_145 ) & ~ V_143 ;
V_9 = F_130 ( V_2 , V_137 , V_108 , V_134 ) ;
if ( F_3 ( ! V_9 ) ) {
V_134 = V_2 -> V_144 ;
V_137 = V_3 ;
V_9 = F_130 ( V_2 , V_137 , V_108 , V_134 ) ;
if ( F_3 ( ! V_9 ) )
goto V_116;
F_9 ( V_2 , V_146 ) ;
}
if ( V_147 &&
! ( V_2 -> V_3 & ( V_148 | V_115 ) ) ) {
int V_149 = 1 << F_25 ( V_134 ) ;
F_137 ( V_9 , F_25 ( V_134 ) , V_137 , V_108 ) ;
if ( V_2 -> F_101 )
F_138 ( V_9 , V_149 ) ;
else
F_139 ( V_9 , V_149 ) ;
}
V_9 -> V_12 = F_26 ( V_134 ) ;
V_23 = F_76 ( V_9 ) ;
V_9 -> V_150 = V_2 ;
F_140 ( V_9 ) ;
if ( F_141 ( V_9 ) )
F_142 ( V_9 ) ;
V_89 = F_13 ( V_9 ) ;
if ( F_3 ( V_2 -> V_3 & V_18 ) )
memset ( V_89 , V_94 , V_25 << V_23 ) ;
F_143 ( V_9 ) ;
F_144 (p, idx, s, start, page->objects) {
F_127 ( V_2 , V_9 , V_5 ) ;
if ( F_91 ( V_138 < V_9 -> V_12 ) )
F_20 ( V_2 , V_5 , V_5 + V_2 -> V_13 ) ;
else
F_20 ( V_2 , V_5 , NULL ) ;
}
V_9 -> V_42 = V_89 ;
V_9 -> V_22 = V_9 -> V_12 ;
V_9 -> V_34 = 1 ;
V_116:
if ( F_112 ( V_3 ) )
F_145 () ;
if ( ! V_9 )
return NULL ;
F_146 ( F_147 ( V_9 ) ,
( V_2 -> V_3 & V_151 ) ?
V_152 : V_153 ,
1 << F_25 ( V_134 ) ) ;
F_90 ( V_2 , F_148 ( V_9 ) , V_9 -> V_12 ) ;
return V_9 ;
}
static struct V_9 * F_149 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
if ( F_3 ( V_3 & V_154 ) ) {
F_150 ( L_44 , V_3 & V_154 ) ;
F_151 () ;
}
return F_135 ( V_2 ,
V_3 & ( V_155 | V_156 ) , V_108 ) ;
}
static void F_152 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
int V_23 = F_76 ( V_9 ) ;
int V_149 = 1 << V_23 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_75 ( V_2 , V_9 ) ;
F_153 (p, s, page_address(page),
page->objects)
F_77 ( V_2 , V_9 , V_5 , V_111 ) ;
}
F_154 ( V_9 , F_76 ( V_9 ) ) ;
F_146 ( F_147 ( V_9 ) ,
( V_2 -> V_3 & V_151 ) ?
V_152 : V_153 ,
- V_149 ) ;
F_155 ( V_9 ) ;
F_156 ( V_9 ) ;
F_157 ( V_9 ) ;
if ( V_65 -> V_157 )
V_65 -> V_157 -> V_158 += V_149 ;
F_158 ( V_9 , V_23 ) ;
}
static void F_159 ( struct V_159 * V_160 )
{
struct V_9 * V_9 ;
if ( V_161 )
V_9 = F_160 ( V_160 ) ;
else
V_9 = F_161 ( (struct V_162 * ) V_160 , struct V_9 , V_106 ) ;
F_152 ( V_9 -> V_150 , V_9 ) ;
}
static void F_162 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
if ( F_3 ( V_2 -> V_3 & V_20 ) ) {
struct V_159 * V_122 ;
if ( V_161 ) {
int V_23 = F_76 ( V_9 ) ;
int V_14 = ( V_25 << V_23 ) - V_2 -> V_24 ;
F_33 ( V_2 -> V_24 != sizeof( * V_122 ) ) ;
V_122 = F_13 ( V_9 ) + V_14 ;
} else {
V_122 = & V_9 -> V_159 ;
}
F_163 ( V_122 , F_159 ) ;
} else
F_152 ( V_2 , V_9 ) ;
}
static void F_164 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
F_94 ( V_2 , F_148 ( V_9 ) , V_9 -> V_12 ) ;
F_162 ( V_2 , V_9 ) ;
}
static inline void
F_165 ( struct V_104 * V_38 , struct V_9 * V_9 , int V_123 )
{
V_38 -> V_163 ++ ;
if ( V_123 == V_164 )
F_166 ( & V_9 -> V_106 , & V_38 -> V_165 ) ;
else
F_83 ( & V_9 -> V_106 , & V_38 -> V_165 ) ;
}
static inline void F_167 ( struct V_104 * V_38 ,
struct V_9 * V_9 , int V_123 )
{
F_82 ( & V_38 -> V_105 ) ;
F_165 ( V_38 , V_9 , V_123 ) ;
}
static inline void
F_168 ( struct V_104 * V_38 , struct V_9 * V_9 )
{
F_85 ( & V_9 -> V_106 ) ;
V_38 -> V_163 -- ;
}
static inline void F_169 ( struct V_104 * V_38 ,
struct V_9 * V_9 )
{
F_82 ( & V_38 -> V_105 ) ;
F_168 ( V_38 , V_9 ) ;
}
static inline void * F_170 ( struct V_1 * V_2 ,
struct V_104 * V_38 , struct V_9 * V_9 ,
int V_166 , int * V_12 )
{
void * V_42 ;
unsigned long V_33 ;
struct V_9 V_167 ;
F_82 ( & V_38 -> V_105 ) ;
V_42 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
V_167 . V_33 = V_33 ;
* V_12 = V_167 . V_12 - V_167 . V_22 ;
if ( V_166 ) {
V_167 . V_22 = V_9 -> V_12 ;
V_167 . V_42 = NULL ;
} else {
V_167 . V_42 = V_42 ;
}
F_33 ( V_167 . V_34 ) ;
V_167 . V_34 = 1 ;
if ( ! F_32 ( V_2 , V_9 ,
V_42 , V_33 ,
V_167 . V_42 , V_167 . V_33 ,
L_45 ) )
return NULL ;
F_169 ( V_38 , V_9 ) ;
F_171 ( ! V_42 ) ;
return V_42 ;
}
static void * F_172 ( struct V_1 * V_2 , struct V_104 * V_38 ,
struct V_168 * V_169 , T_7 V_3 )
{
struct V_9 * V_9 , * V_170 ;
void * V_10 = NULL ;
int V_171 = 0 ;
int V_12 ;
if ( ! V_38 || ! V_38 -> V_163 )
return NULL ;
F_173 ( & V_38 -> V_105 ) ;
F_174 (page, page2, &n->partial, lru) {
void * V_70 ;
if ( ! F_175 ( V_9 , V_3 ) )
continue;
V_70 = F_170 ( V_2 , V_38 , V_9 , V_10 == NULL , & V_12 ) ;
if ( ! V_70 )
break;
V_171 += V_12 ;
if ( ! V_10 ) {
V_169 -> V_9 = V_9 ;
F_9 ( V_2 , V_172 ) ;
V_10 = V_70 ;
} else {
F_176 ( V_2 , V_9 , 0 ) ;
F_9 ( V_2 , V_173 ) ;
}
if ( ! F_4 ( V_2 )
|| V_171 > V_2 -> V_174 / 2 )
break;
}
F_177 ( & V_38 -> V_105 ) ;
return V_10 ;
}
static void * F_178 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_168 * V_169 )
{
#ifdef F_179
struct V_175 * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_178 ;
enum V_179 V_180 = F_180 ( V_3 ) ;
void * V_10 ;
unsigned int V_181 ;
if ( ! V_2 -> V_182 ||
F_181 () % 1024 > V_2 -> V_182 )
return NULL ;
do {
V_181 = F_182 () ;
V_175 = F_183 ( F_184 () , V_3 ) ;
F_185 (zone, z, zonelist, high_zoneidx) {
struct V_104 * V_38 ;
V_38 = F_87 ( V_2 , F_186 ( V_178 ) ) ;
if ( V_38 && F_187 ( V_178 , V_3 ) &&
V_38 -> V_163 > V_2 -> V_183 ) {
V_10 = F_172 ( V_2 , V_38 , V_169 , V_3 ) ;
if ( V_10 ) {
return V_10 ;
}
}
}
} while ( F_188 ( V_181 ) );
#endif
return NULL ;
}
static void * F_189 ( struct V_1 * V_2 , T_7 V_3 , int V_108 ,
struct V_168 * V_169 )
{
void * V_10 ;
int V_184 = V_108 ;
if ( V_108 == V_136 )
V_184 = F_190 () ;
else if ( ! F_191 ( V_108 ) )
V_184 = F_192 ( V_108 ) ;
V_10 = F_172 ( V_2 , F_87 ( V_2 , V_184 ) , V_169 , V_3 ) ;
if ( V_10 || V_108 != V_136 )
return V_10 ;
return F_178 ( V_2 , V_3 , V_169 ) ;
}
static inline unsigned long F_193 ( unsigned long V_185 )
{
return V_185 + V_186 ;
}
static inline unsigned int F_194 ( unsigned long V_185 )
{
return V_185 % V_186 ;
}
static inline unsigned long F_195 ( unsigned long V_185 )
{
return V_185 / V_186 ;
}
static inline unsigned int F_196 ( int V_63 )
{
return V_63 ;
}
static inline void F_197 ( const char * V_38 ,
const struct V_1 * V_2 , unsigned long V_185 )
{
#ifdef F_38
unsigned long V_187 = F_198 ( V_2 -> V_8 -> V_185 ) ;
F_39 ( L_46 , V_38 , V_2 -> V_44 ) ;
#ifdef F_199
if ( F_194 ( V_185 ) != F_194 ( V_187 ) )
F_200 ( L_47 ,
F_194 ( V_185 ) , F_194 ( V_187 ) ) ;
else
#endif
if ( F_195 ( V_185 ) != F_195 ( V_187 ) )
F_200 ( L_48 ,
F_195 ( V_185 ) , F_195 ( V_187 ) ) ;
else
F_200 ( L_49 ,
V_187 , V_185 , F_193 ( V_185 ) ) ;
#endif
F_9 ( V_2 , V_188 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
int V_63 ;
F_202 (cpu)
F_203 ( V_2 -> V_8 , V_63 ) -> V_185 = F_196 ( V_63 ) ;
}
static void F_204 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_42 )
{
enum T_8 { V_189 , V_190 , V_191 , V_192 };
struct V_104 * V_38 = F_87 ( V_2 , F_148 ( V_9 ) ) ;
int V_193 = 0 ;
enum T_8 V_194 = V_189 , V_195 = V_189 ;
void * V_196 ;
int V_123 = V_197 ;
struct V_9 V_167 ;
struct V_9 V_198 ;
if ( V_9 -> V_42 ) {
F_9 ( V_2 , V_199 ) ;
V_123 = V_164 ;
}
while ( V_42 && ( V_196 = F_14 ( V_2 , V_42 ) ) ) {
void * V_200 ;
unsigned long V_33 ;
do {
V_200 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
F_20 ( V_2 , V_42 , V_200 ) ;
V_167 . V_33 = V_33 ;
V_167 . V_22 -- ;
F_33 ( ! V_167 . V_34 ) ;
} while ( ! F_32 ( V_2 , V_9 ,
V_200 , V_33 ,
V_42 , V_167 . V_33 ,
L_50 ) );
V_42 = V_196 ;
}
V_201:
V_198 . V_42 = V_9 -> V_42 ;
V_198 . V_33 = V_9 -> V_33 ;
F_33 ( ! V_198 . V_34 ) ;
V_167 . V_33 = V_198 . V_33 ;
if ( V_42 ) {
V_167 . V_22 -- ;
F_20 ( V_2 , V_42 , V_198 . V_42 ) ;
V_167 . V_42 = V_42 ;
} else
V_167 . V_42 = V_198 . V_42 ;
V_167 . V_34 = 0 ;
if ( ! V_167 . V_22 && V_38 -> V_163 >= V_2 -> V_183 )
V_195 = V_192 ;
else if ( V_167 . V_42 ) {
V_195 = V_190 ;
if ( ! V_193 ) {
V_193 = 1 ;
F_173 ( & V_38 -> V_105 ) ;
}
} else {
V_195 = V_191 ;
if ( F_1 ( V_2 ) && ! V_193 ) {
V_193 = 1 ;
F_173 ( & V_38 -> V_105 ) ;
}
}
if ( V_194 != V_195 ) {
if ( V_194 == V_190 )
F_169 ( V_38 , V_9 ) ;
else if ( V_194 == V_191 )
F_84 ( V_2 , V_38 , V_9 ) ;
if ( V_195 == V_190 ) {
F_167 ( V_38 , V_9 , V_123 ) ;
F_9 ( V_2 , V_123 ) ;
} else if ( V_195 == V_191 ) {
F_9 ( V_2 , V_202 ) ;
F_81 ( V_2 , V_38 , V_9 ) ;
}
}
V_194 = V_195 ;
if ( ! F_32 ( V_2 , V_9 ,
V_198 . V_42 , V_198 . V_33 ,
V_167 . V_42 , V_167 . V_33 ,
L_51 ) )
goto V_201;
if ( V_193 )
F_177 ( & V_38 -> V_105 ) ;
if ( V_195 == V_192 ) {
F_9 ( V_2 , V_203 ) ;
F_164 ( V_2 , V_9 ) ;
F_9 ( V_2 , V_204 ) ;
}
}
static void F_205 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
#ifdef F_5
struct V_104 * V_38 = NULL , * V_205 = NULL ;
struct V_9 * V_9 , * V_206 = NULL ;
while ( ( V_9 = V_169 -> V_165 ) ) {
struct V_9 V_167 ;
struct V_9 V_198 ;
V_169 -> V_165 = V_9 -> V_207 ;
V_205 = F_87 ( V_2 , F_148 ( V_9 ) ) ;
if ( V_38 != V_205 ) {
if ( V_38 )
F_177 ( & V_38 -> V_105 ) ;
V_38 = V_205 ;
F_173 ( & V_38 -> V_105 ) ;
}
do {
V_198 . V_42 = V_9 -> V_42 ;
V_198 . V_33 = V_9 -> V_33 ;
F_33 ( ! V_198 . V_34 ) ;
V_167 . V_33 = V_198 . V_33 ;
V_167 . V_42 = V_198 . V_42 ;
V_167 . V_34 = 0 ;
} while ( ! F_32 ( V_2 , V_9 ,
V_198 . V_42 , V_198 . V_33 ,
V_167 . V_42 , V_167 . V_33 ,
L_51 ) );
if ( F_3 ( ! V_167 . V_22 && V_38 -> V_163 >= V_2 -> V_183 ) ) {
V_9 -> V_207 = V_206 ;
V_206 = V_9 ;
} else {
F_167 ( V_38 , V_9 , V_164 ) ;
F_9 ( V_2 , V_208 ) ;
}
}
if ( V_38 )
F_177 ( & V_38 -> V_105 ) ;
while ( V_206 ) {
V_9 = V_206 ;
V_206 = V_206 -> V_207 ;
F_9 ( V_2 , V_203 ) ;
F_164 ( V_2 , V_9 ) ;
F_9 ( V_2 , V_204 ) ;
}
#endif
}
static void F_176 ( struct V_1 * V_2 , struct V_9 * V_9 , int V_209 )
{
#ifdef F_5
struct V_9 * V_210 ;
int V_149 ;
int V_211 ;
F_206 () ;
do {
V_149 = 0 ;
V_211 = 0 ;
V_210 = F_207 ( V_2 -> V_8 -> V_165 ) ;
if ( V_210 ) {
V_211 = V_210 -> V_211 ;
V_149 = V_210 -> V_149 ;
if ( V_209 && V_211 > V_2 -> V_174 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_205 ( V_2 , F_208 ( V_2 -> V_8 ) ) ;
F_42 ( V_3 ) ;
V_210 = NULL ;
V_211 = 0 ;
V_149 = 0 ;
F_9 ( V_2 , V_212 ) ;
}
}
V_149 ++ ;
V_211 += V_9 -> V_12 - V_9 -> V_22 ;
V_9 -> V_149 = V_149 ;
V_9 -> V_211 = V_211 ;
V_9 -> V_207 = V_210 ;
} while ( F_209 ( V_2 -> V_8 -> V_165 , V_210 , V_9 )
!= V_210 );
if ( F_3 ( ! V_2 -> V_174 ) ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_205 ( V_2 , F_208 ( V_2 -> V_8 ) ) ;
F_42 ( V_3 ) ;
}
F_210 () ;
#endif
}
static inline void F_211 ( struct V_1 * V_2 , struct V_168 * V_169 )
{
F_9 ( V_2 , V_213 ) ;
F_204 ( V_2 , V_169 -> V_9 , V_169 -> V_42 ) ;
V_169 -> V_185 = F_193 ( V_169 -> V_185 ) ;
V_169 -> V_9 = NULL ;
V_169 -> V_42 = NULL ;
}
static inline void F_212 ( struct V_1 * V_2 , int V_63 )
{
struct V_168 * V_169 = F_203 ( V_2 -> V_8 , V_63 ) ;
if ( F_91 ( V_169 ) ) {
if ( V_169 -> V_9 )
F_211 ( V_2 , V_169 ) ;
F_205 ( V_2 , V_169 ) ;
}
}
static void F_213 ( void * V_214 )
{
struct V_1 * V_2 = V_214 ;
F_212 ( V_2 , F_55 () ) ;
}
static bool F_214 ( int V_63 , void * V_215 )
{
struct V_1 * V_2 = V_215 ;
struct V_168 * V_169 = F_203 ( V_2 -> V_8 , V_63 ) ;
return V_169 -> V_9 || V_169 -> V_165 ;
}
static void F_215 ( struct V_1 * V_2 )
{
F_216 ( F_214 , F_213 , V_2 , 1 , V_216 ) ;
}
static inline int F_217 ( struct V_9 * V_9 , int V_108 )
{
#ifdef F_179
if ( ! V_9 || ( V_108 != V_136 && F_148 ( V_9 ) != V_108 ) )
return 0 ;
#endif
return 1 ;
}
static int F_218 ( struct V_9 * V_9 )
{
return V_9 -> V_12 - V_9 -> V_22 ;
}
static inline unsigned long F_219 ( struct V_104 * V_38 )
{
return F_88 ( & V_38 -> V_110 ) ;
}
static unsigned long F_220 ( struct V_104 * V_38 ,
int (* F_221)( struct V_9 * ) )
{
unsigned long V_3 ;
unsigned long V_27 = 0 ;
struct V_9 * V_9 ;
F_222 ( & V_38 -> V_105 , V_3 ) ;
F_223 (page, &n->partial, lru)
V_27 += F_221 ( V_9 ) ;
F_224 ( & V_38 -> V_105 , V_3 ) ;
return V_27 ;
}
static T_5 void
F_225 ( struct V_1 * V_2 , T_7 V_217 , int V_218 )
{
#ifdef F_2
static F_226 ( V_219 , V_220 ,
V_221 ) ;
int V_108 ;
struct V_104 * V_38 ;
if ( ( V_217 & V_140 ) || ! F_227 ( & V_219 ) )
return;
F_200 ( L_52 ,
V_218 , V_217 ) ;
F_200 ( L_53 ,
V_2 -> V_44 , V_2 -> V_19 , V_2 -> V_13 , F_25 ( V_2 -> V_134 ) ,
F_25 ( V_2 -> V_144 ) ) ;
if ( F_25 ( V_2 -> V_144 ) > F_228 ( V_2 -> V_19 ) )
F_200 ( L_54 ,
V_2 -> V_44 ) ;
F_229 (s, node, n) {
unsigned long V_109 ;
unsigned long V_222 ;
unsigned long V_223 ;
V_223 = F_220 ( V_38 , F_218 ) ;
V_109 = F_89 ( V_38 ) ;
V_222 = F_219 ( V_38 ) ;
F_200 ( L_55 ,
V_108 , V_109 , V_222 , V_223 ) ;
}
#endif
}
static inline void * F_230 ( struct V_1 * V_2 , T_7 V_3 ,
int V_108 , struct V_168 * * V_224 )
{
void * V_42 ;
struct V_168 * V_169 = * V_224 ;
struct V_9 * V_9 ;
V_42 = F_189 ( V_2 , V_3 , V_108 , V_169 ) ;
if ( V_42 )
return V_42 ;
V_9 = F_149 ( V_2 , V_3 , V_108 ) ;
if ( V_9 ) {
V_169 = F_231 ( V_2 -> V_8 ) ;
if ( V_169 -> V_9 )
F_211 ( V_2 , V_169 ) ;
V_42 = V_9 -> V_42 ;
V_9 -> V_42 = NULL ;
F_9 ( V_2 , V_225 ) ;
V_169 -> V_9 = V_9 ;
* V_224 = V_169 ;
} else
V_42 = NULL ;
return V_42 ;
}
static inline bool F_175 ( struct V_9 * V_9 , T_7 V_217 )
{
if ( F_3 ( F_232 ( V_9 ) ) )
return F_233 ( V_217 ) ;
return true ;
}
static inline void * F_234 ( struct V_1 * V_2 , struct V_9 * V_9 )
{
struct V_9 V_167 ;
unsigned long V_33 ;
void * V_42 ;
do {
V_42 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
V_167 . V_33 = V_33 ;
F_33 ( ! V_167 . V_34 ) ;
V_167 . V_22 = V_9 -> V_12 ;
V_167 . V_34 = V_42 != NULL ;
} while ( ! F_32 ( V_2 , V_9 ,
V_42 , V_33 ,
NULL , V_167 . V_33 ,
L_56 ) );
return V_42 ;
}
static void * F_235 ( struct V_1 * V_2 , T_7 V_217 , int V_108 ,
unsigned long V_16 , struct V_168 * V_169 )
{
void * V_42 ;
struct V_9 * V_9 ;
V_9 = V_169 -> V_9 ;
if ( ! V_9 )
goto F_149;
V_201:
if ( F_3 ( ! F_217 ( V_9 , V_108 ) ) ) {
int V_184 = V_108 ;
if ( V_108 != V_136 && ! F_191 ( V_108 ) )
V_184 = F_192 ( V_108 ) ;
if ( F_3 ( ! F_217 ( V_9 , V_184 ) ) ) {
F_9 ( V_2 , V_226 ) ;
F_204 ( V_2 , V_9 , V_169 -> V_42 ) ;
V_169 -> V_9 = NULL ;
V_169 -> V_42 = NULL ;
goto F_149;
}
}
if ( F_3 ( ! F_175 ( V_9 , V_217 ) ) ) {
F_204 ( V_2 , V_9 , V_169 -> V_42 ) ;
V_169 -> V_9 = NULL ;
V_169 -> V_42 = NULL ;
goto F_149;
}
V_42 = V_169 -> V_42 ;
if ( V_42 )
goto V_227;
V_42 = F_234 ( V_2 , V_9 ) ;
if ( ! V_42 ) {
V_169 -> V_9 = NULL ;
F_9 ( V_2 , V_228 ) ;
goto F_149;
}
F_9 ( V_2 , V_229 ) ;
V_227:
F_33 ( ! V_169 -> V_9 -> V_34 ) ;
V_169 -> V_42 = F_14 ( V_2 , V_42 ) ;
V_169 -> V_185 = F_193 ( V_169 -> V_185 ) ;
return V_42 ;
F_149:
if ( V_169 -> V_165 ) {
V_9 = V_169 -> V_9 = V_169 -> V_165 ;
V_169 -> V_165 = V_9 -> V_207 ;
F_9 ( V_2 , V_230 ) ;
V_169 -> V_42 = NULL ;
goto V_201;
}
V_42 = F_230 ( V_2 , V_217 , V_108 , & V_169 ) ;
if ( F_3 ( ! V_42 ) ) {
F_225 ( V_2 , V_217 , V_108 ) ;
return NULL ;
}
V_9 = V_169 -> V_9 ;
if ( F_91 ( ! F_1 ( V_2 ) && F_175 ( V_9 , V_217 ) ) )
goto V_227;
if ( F_1 ( V_2 ) &&
! F_98 ( V_2 , V_9 , V_42 , V_16 ) )
goto F_149;
F_204 ( V_2 , V_9 , F_14 ( V_2 , V_42 ) ) ;
V_169 -> V_9 = NULL ;
V_169 -> V_42 = NULL ;
return V_42 ;
}
static void * F_236 ( struct V_1 * V_2 , T_7 V_217 , int V_108 ,
unsigned long V_16 , struct V_168 * V_169 )
{
void * V_5 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_199
V_169 = F_208 ( V_2 -> V_8 ) ;
#endif
V_5 = F_235 ( V_2 , V_217 , V_108 , V_16 , V_169 ) ;
F_42 ( V_3 ) ;
return V_5 ;
}
static T_2 void * F_237 ( struct V_1 * V_2 ,
T_7 V_217 , int V_108 , unsigned long V_16 )
{
void * V_10 ;
struct V_168 * V_169 ;
struct V_9 * V_9 ;
unsigned long V_185 ;
V_2 = F_109 ( V_2 , V_217 ) ;
if ( ! V_2 )
return NULL ;
V_201:
do {
V_185 = F_207 ( V_2 -> V_8 -> V_185 ) ;
V_169 = F_231 ( V_2 -> V_8 ) ;
} while ( F_238 ( F_199 ) &&
F_3 ( V_185 != F_239 ( V_169 -> V_185 ) ) );
F_240 () ;
V_10 = V_169 -> V_42 ;
V_9 = V_169 -> V_9 ;
if ( F_3 ( ! V_10 || ! F_217 ( V_9 , V_108 ) ) ) {
V_10 = F_236 ( V_2 , V_217 , V_108 , V_16 , V_169 ) ;
F_9 ( V_2 , V_231 ) ;
} else {
void * V_232 = F_17 ( V_2 , V_10 ) ;
if ( F_3 ( ! F_241 (
V_2 -> V_8 -> V_42 , V_2 -> V_8 -> V_185 ,
V_10 , V_185 ,
V_232 , F_193 ( V_185 ) ) ) ) {
F_197 ( L_57 , V_2 , V_185 ) ;
goto V_201;
}
F_15 ( V_2 , V_232 ) ;
F_9 ( V_2 , V_233 ) ;
}
if ( F_3 ( V_217 & V_234 ) && V_10 )
memset ( V_10 , 0 , V_2 -> V_19 ) ;
F_115 ( V_2 , V_217 , 1 , & V_10 ) ;
return V_10 ;
}
static T_2 void * F_242 ( struct V_1 * V_2 ,
T_7 V_217 , unsigned long V_16 )
{
return F_237 ( V_2 , V_217 , V_136 , V_16 ) ;
}
void * F_243 ( struct V_1 * V_2 , T_7 V_217 )
{
void * V_235 = F_242 ( V_2 , V_217 , V_236 ) ;
F_244 ( V_236 , V_235 , V_2 -> V_19 ,
V_2 -> V_13 , V_217 ) ;
return V_235 ;
}
void * F_245 ( struct V_1 * V_2 , T_7 V_217 , T_1 V_13 )
{
void * V_235 = F_242 ( V_2 , V_217 , V_236 ) ;
F_246 ( V_236 , V_235 , V_13 , V_2 -> V_13 , V_217 ) ;
F_247 ( V_2 , V_235 , V_13 ) ;
return V_235 ;
}
void * F_248 ( struct V_1 * V_2 , T_7 V_217 , int V_108 )
{
void * V_235 = F_237 ( V_2 , V_217 , V_108 , V_236 ) ;
F_249 ( V_236 , V_235 ,
V_2 -> V_19 , V_2 -> V_13 , V_217 , V_108 ) ;
return V_235 ;
}
void * F_250 ( struct V_1 * V_2 ,
T_7 V_217 ,
int V_108 , T_1 V_13 )
{
void * V_235 = F_237 ( V_2 , V_217 , V_108 , V_236 ) ;
F_251 ( V_236 , V_235 ,
V_13 , V_2 -> V_13 , V_217 , V_108 ) ;
F_247 ( V_2 , V_235 , V_13 ) ;
return V_235 ;
}
static void F_252 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_122 , void * V_123 , int V_237 ,
unsigned long V_16 )
{
void * V_200 ;
int V_238 ;
struct V_9 V_167 ;
unsigned long V_33 ;
struct V_104 * V_38 = NULL ;
unsigned long V_239 ( V_3 ) ;
F_9 ( V_2 , V_240 ) ;
if ( F_1 ( V_2 ) &&
! ( V_38 = F_102 ( V_2 , V_9 , V_122 , V_123 , V_237 ,
V_16 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_38 ) ) {
F_224 ( & V_38 -> V_105 , V_3 ) ;
V_38 = NULL ;
}
V_200 = V_9 -> V_42 ;
V_33 = V_9 -> V_33 ;
F_20 ( V_2 , V_123 , V_200 ) ;
V_167 . V_33 = V_33 ;
V_238 = V_167 . V_34 ;
V_167 . V_22 -= V_237 ;
if ( ( ! V_167 . V_22 || ! V_200 ) && ! V_238 ) {
if ( F_4 ( V_2 ) && ! V_200 ) {
V_167 . V_34 = 1 ;
} else {
V_38 = F_87 ( V_2 , F_148 ( V_9 ) ) ;
F_222 ( & V_38 -> V_105 , V_3 ) ;
}
}
} while ( ! F_40 ( V_2 , V_9 ,
V_200 , V_33 ,
V_122 , V_167 . V_33 ,
L_58 ) );
if ( F_91 ( ! V_38 ) ) {
if ( V_167 . V_34 && ! V_238 ) {
F_176 ( V_2 , V_9 , 1 ) ;
F_9 ( V_2 , V_241 ) ;
}
if ( V_238 )
F_9 ( V_2 , V_242 ) ;
return;
}
if ( F_3 ( ! V_167 . V_22 && V_38 -> V_163 >= V_2 -> V_183 ) )
goto V_243;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_200 ) ) {
if ( F_1 ( V_2 ) )
F_84 ( V_2 , V_38 , V_9 ) ;
F_167 ( V_38 , V_9 , V_164 ) ;
F_9 ( V_2 , V_208 ) ;
}
F_224 ( & V_38 -> V_105 , V_3 ) ;
return;
V_243:
if ( V_200 ) {
F_169 ( V_38 , V_9 ) ;
F_9 ( V_2 , V_244 ) ;
} else {
F_84 ( V_2 , V_38 , V_9 ) ;
}
F_224 ( & V_38 -> V_105 , V_3 ) ;
F_9 ( V_2 , V_204 ) ;
F_164 ( V_2 , V_9 ) ;
}
static T_2 void F_253 ( struct V_1 * V_2 , struct V_9 * V_9 ,
void * V_122 , void * V_123 , int V_237 ,
unsigned long V_16 )
{
void * V_133 = V_123 ? : V_122 ;
struct V_168 * V_169 ;
unsigned long V_185 ;
F_126 ( V_2 , V_122 , V_123 ) ;
V_201:
do {
V_185 = F_207 ( V_2 -> V_8 -> V_185 ) ;
V_169 = F_231 ( V_2 -> V_8 ) ;
} while ( F_238 ( F_199 ) &&
F_3 ( V_185 != F_239 ( V_169 -> V_185 ) ) );
F_240 () ;
if ( F_91 ( V_9 == V_169 -> V_9 ) ) {
F_20 ( V_2 , V_133 , V_169 -> V_42 ) ;
if ( F_3 ( ! F_241 (
V_2 -> V_8 -> V_42 , V_2 -> V_8 -> V_185 ,
V_169 -> V_42 , V_185 ,
V_122 , F_193 ( V_185 ) ) ) ) {
F_197 ( L_59 , V_2 , V_185 ) ;
goto V_201;
}
F_9 ( V_2 , V_245 ) ;
} else
F_252 ( V_2 , V_9 , V_122 , V_133 , V_237 , V_16 ) ;
}
void F_254 ( struct V_1 * V_2 , void * V_27 )
{
V_2 = F_255 ( V_2 , V_27 ) ;
if ( ! V_2 )
return;
F_253 ( V_2 , F_160 ( V_27 ) , V_27 , NULL , 1 , V_236 ) ;
F_256 ( V_236 , V_27 ) ;
}
static int F_257 ( struct V_1 * V_2 , T_1 V_13 ,
void * * V_5 , struct V_246 * V_247 )
{
T_1 V_248 = 0 ;
int V_249 = 3 ;
void * V_10 ;
V_247 -> V_9 = NULL ;
do {
V_10 = V_5 [ -- V_13 ] ;
} while ( ! V_10 && V_13 );
if ( ! V_10 )
return 0 ;
F_20 ( V_2 , V_10 , NULL ) ;
V_247 -> V_9 = F_160 ( V_10 ) ;
V_247 -> V_123 = V_10 ;
V_247 -> V_42 = V_10 ;
V_5 [ V_13 ] = NULL ;
V_247 -> V_237 = 1 ;
while ( V_13 ) {
V_10 = V_5 [ -- V_13 ] ;
if ( ! V_10 )
continue;
if ( V_247 -> V_9 == F_160 ( V_10 ) ) {
F_20 ( V_2 , V_10 , V_247 -> V_42 ) ;
V_247 -> V_42 = V_10 ;
V_247 -> V_237 ++ ;
V_5 [ V_13 ] = NULL ;
continue;
}
if ( ! -- V_249 )
break;
if ( ! V_248 )
V_248 = V_13 + 1 ;
}
return V_248 ;
}
void F_258 ( struct V_1 * V_250 , T_1 V_13 , void * * V_5 )
{
if ( F_171 ( ! V_13 ) )
return;
do {
struct V_246 V_247 ;
struct V_1 * V_2 ;
V_2 = F_255 ( V_250 , V_5 [ V_13 - 1 ] ) ;
V_13 = F_257 ( V_2 , V_13 , V_5 , & V_247 ) ;
if ( F_3 ( ! V_247 . V_9 ) )
continue;
F_253 ( V_2 , V_247 . V_9 , V_247 . V_42 , V_247 . V_123 , V_247 . V_237 , V_236 ) ;
} while ( F_91 ( V_13 ) );
}
int F_259 ( struct V_1 * V_2 , T_7 V_3 , T_1 V_13 ,
void * * V_5 )
{
struct V_168 * V_169 ;
int V_55 ;
V_2 = F_109 ( V_2 , V_3 ) ;
if ( F_3 ( ! V_2 ) )
return false ;
F_145 () ;
V_169 = F_208 ( V_2 -> V_8 ) ;
for ( V_55 = 0 ; V_55 < V_13 ; V_55 ++ ) {
void * V_10 = V_169 -> V_42 ;
if ( F_3 ( ! V_10 ) ) {
V_5 [ V_55 ] = F_235 ( V_2 , V_3 , V_136 ,
V_236 , V_169 ) ;
if ( F_3 ( ! V_5 [ V_55 ] ) )
goto error;
V_169 = F_208 ( V_2 -> V_8 ) ;
continue;
}
V_169 -> V_42 = F_14 ( V_2 , V_10 ) ;
V_5 [ V_55 ] = V_10 ;
}
V_169 -> V_185 = F_193 ( V_169 -> V_185 ) ;
F_136 () ;
if ( F_3 ( V_3 & V_234 ) ) {
int V_251 ;
for ( V_251 = 0 ; V_251 < V_55 ; V_251 ++ )
memset ( V_5 [ V_251 ] , 0 , V_2 -> V_19 ) ;
}
F_115 ( V_2 , V_3 , V_13 , V_5 ) ;
return V_55 ;
error:
F_136 () ;
F_115 ( V_2 , V_3 , V_55 , V_5 ) ;
F_260 ( V_2 , V_55 , V_5 ) ;
return 0 ;
}
static inline int F_261 ( int V_13 , int V_252 ,
int V_253 , int V_254 , int V_24 )
{
int V_23 ;
int V_255 ;
int V_256 = V_257 ;
if ( F_23 ( V_256 , V_13 , V_24 ) > V_102 )
return F_228 ( V_13 * V_102 ) - 1 ;
for ( V_23 = F_262 ( V_256 , F_228 ( V_252 * V_13 + V_24 ) ) ;
V_23 <= V_253 ; V_23 ++ ) {
unsigned long V_258 = V_25 << V_23 ;
V_255 = ( V_258 - V_24 ) % V_13 ;
if ( V_255 <= V_258 / V_254 )
break;
}
return V_23 ;
}
static inline int F_263 ( int V_13 , int V_24 )
{
int V_23 ;
int V_252 ;
int V_259 ;
int V_101 ;
V_252 = V_260 ;
if ( ! V_252 )
V_252 = 4 * ( F_264 ( V_261 ) + 1 ) ;
V_101 = F_23 ( V_262 , V_13 , V_24 ) ;
V_252 = V_144 ( V_252 , V_101 ) ;
while ( V_252 > 1 ) {
V_259 = 16 ;
while ( V_259 >= 4 ) {
V_23 = F_261 ( V_13 , V_252 ,
V_262 , V_259 , V_24 ) ;
if ( V_23 <= V_262 )
return V_23 ;
V_259 /= 2 ;
}
V_252 -- ;
}
V_23 = F_261 ( V_13 , 1 , V_262 , 1 , V_24 ) ;
if ( V_23 <= V_262 )
return V_23 ;
V_23 = F_261 ( V_13 , 1 , V_263 , 1 , V_24 ) ;
if ( V_23 < V_263 )
return V_23 ;
return - V_264 ;
}
static void
F_265 ( struct V_104 * V_38 )
{
V_38 -> V_163 = 0 ;
F_266 ( & V_38 -> V_105 ) ;
F_267 ( & V_38 -> V_165 ) ;
#ifdef F_2
F_268 ( & V_38 -> V_109 , 0 ) ;
F_268 ( & V_38 -> V_110 , 0 ) ;
F_267 ( & V_38 -> V_107 ) ;
#endif
}
static inline int F_269 ( struct V_1 * V_2 )
{
F_270 ( V_265 <
V_266 * sizeof( struct V_168 ) ) ;
V_2 -> V_8 = F_271 ( sizeof( struct V_168 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_201 ( V_2 ) ;
return 1 ;
}
static void F_272 ( int V_108 )
{
struct V_9 * V_9 ;
struct V_104 * V_38 ;
F_273 ( V_104 -> V_13 < sizeof( struct V_104 ) ) ;
V_9 = F_149 ( V_104 , V_267 , V_108 ) ;
F_273 ( ! V_9 ) ;
if ( F_148 ( V_9 ) != V_108 ) {
F_58 ( L_60 , V_108 ) ;
F_58 ( L_61 ) ;
}
V_38 = V_9 -> V_42 ;
F_273 ( ! V_38 ) ;
V_9 -> V_42 = F_14 ( V_104 , V_38 ) ;
V_9 -> V_22 = 1 ;
V_9 -> V_34 = 0 ;
V_104 -> V_108 [ V_108 ] = V_38 ;
#ifdef F_2
F_70 ( V_104 , V_38 , V_97 ) ;
F_56 ( V_104 , V_38 ) ;
#endif
F_247 ( V_104 , V_38 , sizeof( struct V_104 ) ) ;
F_265 ( V_38 ) ;
F_90 ( V_104 , V_108 , V_9 -> V_12 ) ;
F_165 ( V_38 , V_9 , V_197 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_38 ;
F_229 (s, node, n) {
F_254 ( V_104 , V_38 ) ;
V_2 -> V_108 [ V_108 ] = NULL ;
}
}
static int F_275 ( struct V_1 * V_2 )
{
int V_108 ;
F_276 (node, N_NORMAL_MEMORY) {
struct V_104 * V_38 ;
if ( V_268 == V_269 ) {
F_272 ( V_108 ) ;
continue;
}
V_38 = F_248 ( V_104 ,
V_270 , V_108 ) ;
if ( ! V_38 ) {
F_274 ( V_2 ) ;
return 0 ;
}
V_2 -> V_108 [ V_108 ] = V_38 ;
F_265 ( V_38 ) ;
}
return 1 ;
}
static void F_277 ( struct V_1 * V_2 , unsigned long V_144 )
{
if ( V_144 < V_271 )
V_144 = V_271 ;
else if ( V_144 > V_272 )
V_144 = V_272 ;
V_2 -> V_183 = V_144 ;
}
static int F_278 ( struct V_1 * V_2 , int V_273 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_13 = V_2 -> V_19 ;
int V_23 ;
V_13 = F_279 ( V_13 , sizeof( void * ) ) ;
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
V_13 = F_279 ( V_13 , V_2 -> V_274 ) ;
V_2 -> V_13 = V_13 ;
if ( V_273 >= 0 )
V_23 = V_273 ;
else
V_23 = F_263 ( V_13 , V_2 -> V_24 ) ;
if ( V_23 < 0 )
return 0 ;
V_2 -> V_139 = 0 ;
if ( V_23 )
V_2 -> V_139 |= V_275 ;
if ( V_2 -> V_3 & V_276 )
V_2 -> V_139 |= V_277 ;
if ( V_2 -> V_3 & V_151 )
V_2 -> V_139 |= V_278 ;
V_2 -> V_134 = F_24 ( V_23 , V_13 , V_2 -> V_24 ) ;
V_2 -> V_144 = F_24 ( F_228 ( V_13 ) , V_13 , V_2 -> V_24 ) ;
if ( F_26 ( V_2 -> V_134 ) > F_26 ( V_2 -> F_262 ) )
V_2 -> F_262 = V_2 -> V_134 ;
return ! ! F_26 ( V_2 -> V_134 ) ;
}
static int F_280 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_100 ( V_2 -> V_13 , V_3 , V_2 -> V_44 , V_2 -> F_101 ) ;
V_2 -> V_24 = 0 ;
if ( V_161 && ( V_2 -> V_3 & V_20 ) )
V_2 -> V_24 = sizeof( struct V_159 ) ;
if ( ! F_278 ( V_2 , - 1 ) )
goto error;
if ( V_120 ) {
if ( F_228 ( V_2 -> V_13 ) > F_228 ( V_2 -> V_19 ) ) {
V_2 -> V_3 &= ~ V_279 ;
V_2 -> V_14 = 0 ;
if ( ! F_278 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_39 ) && \
F_35 ( V_40 )
if ( F_281 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_41 ;
#endif
F_277 ( V_2 , F_282 ( V_2 -> V_13 ) / 2 ) ;
if ( ! F_4 ( V_2 ) )
V_2 -> V_174 = 0 ;
else if ( V_2 -> V_13 >= V_25 )
V_2 -> V_174 = 2 ;
else if ( V_2 -> V_13 >= 1024 )
V_2 -> V_174 = 6 ;
else if ( V_2 -> V_13 >= 256 )
V_2 -> V_174 = 13 ;
else
V_2 -> V_174 = 30 ;
#ifdef F_179
V_2 -> V_182 = 1000 ;
#endif
if ( ! F_275 ( V_2 ) )
goto error;
if ( F_269 ( V_2 ) )
return 0 ;
F_274 ( V_2 ) ;
error:
if ( V_3 & V_280 )
F_283 ( L_62
L_63 ,
V_2 -> V_44 , ( unsigned long ) V_2 -> V_13 , V_2 -> V_13 ,
F_25 ( V_2 -> V_134 ) , V_2 -> V_14 , V_3 ) ;
return - V_281 ;
}
static void F_284 ( struct V_1 * V_2 , struct V_9 * V_9 ,
const char * V_46 )
{
#ifdef F_2
void * V_16 = F_13 ( V_9 ) ;
void * V_5 ;
unsigned long * V_45 = F_285 ( F_286 ( V_9 -> V_12 ) *
sizeof( long ) , V_216 ) ;
if ( ! V_45 )
return;
F_69 ( V_2 , V_9 , V_46 , V_2 -> V_44 ) ;
F_27 ( V_9 ) ;
F_43 ( V_2 , V_9 , V_45 ) ;
F_153 (p, s, addr, page->objects) {
if ( ! F_287 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) ) {
F_58 ( L_64 , V_5 , V_5 - V_16 ) ;
F_59 ( V_2 , V_5 ) ;
}
}
F_29 ( V_9 ) ;
F_288 ( V_45 ) ;
#endif
}
static void F_289 ( struct V_1 * V_2 , struct V_104 * V_38 )
{
struct V_9 * V_9 , * V_160 ;
F_174 (page, h, &n->partial, lru) {
if ( ! V_9 -> V_22 ) {
F_168 ( V_38 , V_9 ) ;
F_164 ( V_2 , V_9 ) ;
} else {
F_284 ( V_2 , V_9 ,
L_65 ) ;
}
}
}
static inline int F_290 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_38 ;
F_215 ( V_2 ) ;
F_229 (s, node, n) {
F_289 ( V_2 , V_38 ) ;
if ( V_38 -> V_163 || F_86 ( V_2 , V_108 ) )
return 1 ;
}
F_291 ( V_2 -> V_8 ) ;
F_274 ( V_2 ) ;
return 0 ;
}
int F_292 ( struct V_1 * V_2 )
{
return F_290 ( V_2 ) ;
}
static int T_6 F_293 ( char * V_113 )
{
F_294 ( & V_113 , & V_257 ) ;
return 1 ;
}
static int T_6 F_295 ( char * V_113 )
{
F_294 ( & V_113 , & V_262 ) ;
V_262 = V_144 ( V_262 , V_263 - 1 ) ;
return 1 ;
}
static int T_6 F_296 ( char * V_113 )
{
F_294 ( & V_113 , & V_260 ) ;
return 1 ;
}
void * F_297 ( T_1 V_13 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_235 ;
if ( F_3 ( V_13 > V_282 ) )
return F_298 ( V_13 , V_3 ) ;
V_2 = F_299 ( V_13 , V_3 ) ;
if ( F_3 ( F_300 ( V_2 ) ) )
return V_2 ;
V_235 = F_242 ( V_2 , V_3 , V_236 ) ;
F_246 ( V_236 , V_235 , V_13 , V_2 -> V_13 , V_3 ) ;
F_247 ( V_2 , V_235 , V_13 ) ;
return V_235 ;
}
static void * F_301 ( T_1 V_13 , T_7 V_3 , int V_108 )
{
struct V_9 * V_9 ;
void * V_125 = NULL ;
V_3 |= V_275 | V_135 ;
V_9 = F_302 ( V_108 , V_3 , F_228 ( V_13 ) ) ;
if ( V_9 )
V_125 = F_13 ( V_9 ) ;
F_103 ( V_125 , V_13 , V_3 ) ;
return V_125 ;
}
void * F_303 ( T_1 V_13 , T_7 V_3 , int V_108 )
{
struct V_1 * V_2 ;
void * V_235 ;
if ( F_3 ( V_13 > V_282 ) ) {
V_235 = F_301 ( V_13 , V_3 , V_108 ) ;
F_251 ( V_236 , V_235 ,
V_13 , V_25 << F_228 ( V_13 ) ,
V_3 , V_108 ) ;
return V_235 ;
}
V_2 = F_299 ( V_13 , V_3 ) ;
if ( F_3 ( F_300 ( V_2 ) ) )
return V_2 ;
V_235 = F_237 ( V_2 , V_3 , V_108 , V_236 ) ;
F_251 ( V_236 , V_235 , V_13 , V_2 -> V_13 , V_3 , V_108 ) ;
F_247 ( V_2 , V_235 , V_13 ) ;
return V_235 ;
}
static T_1 F_304 ( const void * V_10 )
{
struct V_9 * V_9 ;
if ( F_3 ( V_10 == V_283 ) )
return 0 ;
V_9 = F_160 ( V_10 ) ;
if ( F_3 ( ! F_79 ( V_9 ) ) ) {
F_171 ( ! F_305 ( V_9 ) ) ;
return V_25 << F_76 ( V_9 ) ;
}
return F_22 ( V_9 -> V_150 ) ;
}
T_1 F_306 ( const void * V_10 )
{
T_1 V_13 = F_304 ( V_10 ) ;
F_307 ( V_10 , V_13 ) ;
return V_13 ;
}
void F_288 ( const void * V_27 )
{
struct V_9 * V_9 ;
void * V_10 = ( void * ) V_27 ;
F_308 ( V_236 , V_27 ) ;
if ( F_3 ( F_300 ( V_27 ) ) )
return;
V_9 = F_160 ( V_27 ) ;
if ( F_3 ( ! F_79 ( V_9 ) ) ) {
F_273 ( ! F_305 ( V_9 ) ) ;
F_106 ( V_27 ) ;
F_158 ( V_9 , F_76 ( V_9 ) ) ;
return;
}
F_253 ( V_9 -> V_150 , V_9 , V_10 , NULL , 1 , V_236 ) ;
}
int F_309 ( struct V_1 * V_2 , bool V_284 )
{
int V_108 ;
int V_55 ;
struct V_104 * V_38 ;
struct V_9 * V_9 ;
struct V_9 * V_70 ;
struct V_162 V_285 ;
struct V_162 V_286 [ V_287 ] ;
unsigned long V_3 ;
int V_235 = 0 ;
if ( V_284 ) {
V_2 -> V_174 = 0 ;
V_2 -> V_183 = 0 ;
F_310 () ;
}
F_215 ( V_2 ) ;
F_229 (s, node, n) {
F_267 ( & V_285 ) ;
for ( V_55 = 0 ; V_55 < V_287 ; V_55 ++ )
F_267 ( V_286 + V_55 ) ;
F_222 ( & V_38 -> V_105 , V_3 ) ;
F_174 (page, t, &n->partial, lru) {
int free = V_9 -> V_12 - V_9 -> V_22 ;
F_240 () ;
F_273 ( free <= 0 ) ;
if ( free == V_9 -> V_12 ) {
F_311 ( & V_9 -> V_106 , & V_285 ) ;
V_38 -> V_163 -- ;
} else if ( free <= V_287 )
F_311 ( & V_9 -> V_106 , V_286 + free - 1 ) ;
}
for ( V_55 = V_287 - 1 ; V_55 >= 0 ; V_55 -- )
F_312 ( V_286 + V_55 , & V_38 -> V_165 ) ;
F_224 ( & V_38 -> V_105 , V_3 ) ;
F_174 (page, t, &discard, lru)
F_164 ( V_2 , V_9 ) ;
if ( F_86 ( V_2 , V_108 ) )
V_235 = 1 ;
}
return V_235 ;
}
static int F_313 ( void * V_288 )
{
struct V_1 * V_2 ;
F_314 ( & V_289 ) ;
F_223 (s, &slab_caches, list)
F_309 ( V_2 , false ) ;
F_315 ( & V_289 ) ;
return 0 ;
}
static void F_316 ( void * V_288 )
{
struct V_104 * V_38 ;
struct V_1 * V_2 ;
struct V_290 * V_291 = V_288 ;
int V_292 ;
V_292 = V_291 -> V_293 ;
if ( V_292 < 0 )
return;
F_314 ( & V_289 ) ;
F_223 (s, &slab_caches, list) {
V_38 = F_87 ( V_2 , V_292 ) ;
if ( V_38 ) {
F_273 ( F_86 ( V_2 , V_292 ) ) ;
V_2 -> V_108 [ V_292 ] = NULL ;
F_254 ( V_104 , V_38 ) ;
}
}
F_315 ( & V_289 ) ;
}
static int F_317 ( void * V_288 )
{
struct V_104 * V_38 ;
struct V_1 * V_2 ;
struct V_290 * V_291 = V_288 ;
int V_218 = V_291 -> V_293 ;
int V_235 = 0 ;
if ( V_218 < 0 )
return 0 ;
F_314 ( & V_289 ) ;
F_223 (s, &slab_caches, list) {
V_38 = F_243 ( V_104 , V_270 ) ;
if ( ! V_38 ) {
V_235 = - V_294 ;
goto V_116;
}
F_265 ( V_38 ) ;
V_2 -> V_108 [ V_218 ] = V_38 ;
}
V_116:
F_315 ( & V_289 ) ;
return V_235 ;
}
static int F_318 ( struct V_295 * V_296 ,
unsigned long V_297 , void * V_288 )
{
int V_235 = 0 ;
switch ( V_297 ) {
case V_298 :
V_235 = F_317 ( V_288 ) ;
break;
case V_299 :
V_235 = F_313 ( V_288 ) ;
break;
case V_300 :
case V_301 :
F_316 ( V_288 ) ;
break;
case V_302 :
case V_303 :
break;
}
if ( V_235 )
V_235 = F_319 ( V_235 ) ;
else
V_235 = V_304 ;
return V_235 ;
}
static struct V_1 * T_6 F_320 ( struct V_1 * V_305 )
{
int V_108 ;
struct V_1 * V_2 = F_321 ( V_1 , V_267 ) ;
struct V_104 * V_38 ;
memcpy ( V_2 , V_305 , V_1 -> V_19 ) ;
F_212 ( V_2 , F_55 () ) ;
F_229 (s, node, n) {
struct V_9 * V_5 ;
F_223 (p, &n->partial, lru)
V_5 -> V_150 = V_2 ;
#ifdef F_2
F_223 (p, &n->full, lru)
V_5 -> V_150 = V_2 ;
#endif
}
F_322 ( V_2 ) ;
F_83 ( & V_2 -> V_306 , & V_307 ) ;
return V_2 ;
}
void T_6 F_323 ( void )
{
static V_308 struct V_1 V_309 ,
V_310 ;
if ( F_324 () )
V_262 = 0 ;
V_104 = & V_310 ;
V_1 = & V_309 ;
F_325 ( V_104 , L_66 ,
sizeof( struct V_104 ) , V_311 ) ;
F_326 ( & V_312 ) ;
V_268 = V_313 ;
F_325 ( V_1 , L_67 ,
F_327 ( struct V_1 , V_108 ) +
V_314 * sizeof( struct V_104 * ) ,
V_311 ) ;
V_1 = F_320 ( & V_309 ) ;
V_104 = F_320 ( & V_310 ) ;
F_328 () ;
F_329 ( 0 ) ;
#ifdef F_330
F_331 ( & V_315 ) ;
#endif
F_39 ( L_68 ,
F_332 () ,
V_257 , V_262 , V_260 ,
V_261 , V_314 ) ;
}
void T_6 F_333 ( void )
{
}
struct V_1 *
F_334 ( const char * V_44 , T_1 V_13 , T_1 V_274 ,
unsigned long V_3 , void (* F_101)( void * ) )
{
struct V_1 * V_2 , * V_169 ;
V_2 = F_335 ( V_13 , V_274 , V_3 , V_44 , F_101 ) ;
if ( V_2 ) {
V_2 -> V_316 ++ ;
V_2 -> V_19 = F_262 ( V_2 -> V_19 , ( int ) V_13 ) ;
V_2 -> V_22 = F_336 ( int , V_2 -> V_22 , F_279 ( V_13 , sizeof( void * ) ) ) ;
F_337 (c, s) {
V_169 -> V_19 = V_2 -> V_19 ;
V_169 -> V_22 = F_336 ( int , V_169 -> V_22 ,
F_279 ( V_13 , sizeof( void * ) ) ) ;
}
if ( F_7 ( V_2 , V_44 ) ) {
V_2 -> V_316 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_338 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_317 ;
V_317 = F_280 ( V_2 , V_3 ) ;
if ( V_317 )
return V_317 ;
if ( V_268 <= V_318 )
return 0 ;
F_8 ( V_2 ) ;
V_317 = F_6 ( V_2 ) ;
if ( V_317 )
F_290 ( V_2 ) ;
return V_317 ;
}
static int F_339 ( struct V_295 * V_319 ,
unsigned long V_297 , void * V_320 )
{
long V_63 = ( long ) V_320 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_297 ) {
case V_321 :
case V_322 :
case V_323 :
case V_324 :
F_314 ( & V_289 ) ;
F_223 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_212 ( V_2 , V_63 ) ;
F_42 ( V_3 ) ;
}
F_315 ( & V_289 ) ;
break;
default:
break;
}
return V_304 ;
}
void * F_340 ( T_1 V_13 , T_7 V_217 , unsigned long V_325 )
{
struct V_1 * V_2 ;
void * V_235 ;
if ( F_3 ( V_13 > V_282 ) )
return F_298 ( V_13 , V_217 ) ;
V_2 = F_299 ( V_13 , V_217 ) ;
if ( F_3 ( F_300 ( V_2 ) ) )
return V_2 ;
V_235 = F_242 ( V_2 , V_217 , V_325 ) ;
F_246 ( V_325 , V_235 , V_13 , V_2 -> V_13 , V_217 ) ;
return V_235 ;
}
void * F_341 ( T_1 V_13 , T_7 V_217 ,
int V_108 , unsigned long V_325 )
{
struct V_1 * V_2 ;
void * V_235 ;
if ( F_3 ( V_13 > V_282 ) ) {
V_235 = F_301 ( V_13 , V_217 , V_108 ) ;
F_251 ( V_325 , V_235 ,
V_13 , V_25 << F_228 ( V_13 ) ,
V_217 , V_108 ) ;
return V_235 ;
}
V_2 = F_299 ( V_13 , V_217 ) ;
if ( F_3 ( F_300 ( V_2 ) ) )
return V_2 ;
V_235 = F_237 ( V_2 , V_217 , V_108 , V_325 ) ;
F_251 ( V_325 , V_235 , V_13 , V_2 -> V_13 , V_217 , V_108 ) ;
return V_235 ;
}
static int F_342 ( struct V_9 * V_9 )
{
return V_9 -> V_22 ;
}
static int F_343 ( struct V_9 * V_9 )
{
return V_9 -> V_12 ;
}
static int F_344 ( struct V_1 * V_2 , struct V_9 * V_9 ,
unsigned long * V_45 )
{
void * V_5 ;
void * V_16 = F_13 ( V_9 ) ;
if ( ! F_78 ( V_2 , V_9 ) ||
! F_80 ( V_2 , V_9 , NULL ) )
return 0 ;
F_345 ( V_45 , V_9 -> V_12 ) ;
F_43 ( V_2 , V_9 , V_45 ) ;
F_153 (p, s, addr, page->objects) {
if ( F_287 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) )
if ( ! F_77 ( V_2 , V_9 , V_5 , V_111 ) )
return 0 ;
}
F_153 (p, s, addr, page->objects)
if ( ! F_287 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) )
if ( ! F_77 ( V_2 , V_9 , V_5 , V_97 ) )
return 0 ;
return 1 ;
}
static void F_346 ( struct V_1 * V_2 , struct V_9 * V_9 ,
unsigned long * V_45 )
{
F_27 ( V_9 ) ;
F_344 ( V_2 , V_9 , V_45 ) ;
F_29 ( V_9 ) ;
}
static int F_347 ( struct V_1 * V_2 ,
struct V_104 * V_38 , unsigned long * V_45 )
{
unsigned long V_326 = 0 ;
struct V_9 * V_9 ;
unsigned long V_3 ;
F_222 ( & V_38 -> V_105 , V_3 ) ;
F_223 (page, &n->partial, lru) {
F_346 ( V_2 , V_9 , V_45 ) ;
V_326 ++ ;
}
if ( V_326 != V_38 -> V_163 )
F_58 ( L_69 ,
V_2 -> V_44 , V_326 , V_38 -> V_163 ) ;
if ( ! ( V_2 -> V_3 & V_21 ) )
goto V_116;
F_223 (page, &n->full, lru) {
F_346 ( V_2 , V_9 , V_45 ) ;
V_326 ++ ;
}
if ( V_326 != F_88 ( & V_38 -> V_109 ) )
F_58 ( L_70 ,
V_2 -> V_44 , V_326 , F_88 ( & V_38 -> V_109 ) ) ;
V_116:
F_224 ( & V_38 -> V_105 , V_3 ) ;
return V_326 ;
}
static long F_348 ( struct V_1 * V_2 )
{
int V_108 ;
unsigned long V_326 = 0 ;
unsigned long * V_45 = F_349 ( F_286 ( F_26 ( V_2 -> F_262 ) ) *
sizeof( unsigned long ) , V_270 ) ;
struct V_104 * V_38 ;
if ( ! V_45 )
return - V_294 ;
F_215 ( V_2 ) ;
F_229 (s, node, n)
V_326 += F_347 ( V_2 , V_38 , V_45 ) ;
F_288 ( V_45 ) ;
return V_326 ;
}
static void F_350 ( struct V_327 * V_70 )
{
if ( V_70 -> F_262 )
F_351 ( ( unsigned long ) V_70 -> V_328 ,
F_228 ( sizeof( struct V_329 ) * V_70 -> F_262 ) ) ;
}
static int F_352 ( struct V_327 * V_70 , unsigned long F_262 , T_7 V_3 )
{
struct V_329 * V_194 ;
int V_23 ;
V_23 = F_228 ( sizeof( struct V_329 ) * F_262 ) ;
V_194 = ( void * ) F_353 ( V_3 , V_23 ) ;
if ( ! V_194 )
return 0 ;
if ( V_70 -> V_326 ) {
memcpy ( V_194 , V_70 -> V_328 , sizeof( struct V_329 ) * V_70 -> V_326 ) ;
F_350 ( V_70 ) ;
}
V_70 -> F_262 = F_262 ;
V_70 -> V_328 = V_194 ;
return 1 ;
}
static int F_354 ( struct V_327 * V_70 , struct V_1 * V_2 ,
const struct V_50 * V_50 )
{
long V_89 , V_93 , V_330 ;
struct V_329 * V_194 ;
unsigned long V_331 ;
unsigned long V_332 = V_67 - V_50 -> V_66 ;
V_89 = - 1 ;
V_93 = V_70 -> V_326 ;
for ( ; ; ) {
V_330 = V_89 + ( V_93 - V_89 + 1 ) / 2 ;
if ( V_330 == V_93 )
break;
V_331 = V_70 -> V_328 [ V_330 ] . V_16 ;
if ( V_50 -> V_16 == V_331 ) {
V_194 = & V_70 -> V_328 [ V_330 ] ;
V_194 -> V_326 ++ ;
if ( V_50 -> V_66 ) {
V_194 -> V_333 += V_332 ;
if ( V_332 < V_194 -> V_334 )
V_194 -> V_334 = V_332 ;
if ( V_332 > V_194 -> V_335 )
V_194 -> V_335 = V_332 ;
if ( V_50 -> V_64 < V_194 -> V_336 )
V_194 -> V_336 = V_50 -> V_64 ;
if ( V_50 -> V_64 > V_194 -> V_337 )
V_194 -> V_337 = V_50 -> V_64 ;
F_355 ( V_50 -> V_63 ,
F_356 ( V_194 -> V_338 ) ) ;
}
F_357 ( F_148 ( F_358 ( V_50 ) ) , V_194 -> V_339 ) ;
return 1 ;
}
if ( V_50 -> V_16 < V_331 )
V_93 = V_330 ;
else
V_89 = V_330 ;
}
if ( V_70 -> V_326 >= V_70 -> F_262 && ! F_352 ( V_70 , 2 * V_70 -> F_262 , V_216 ) )
return 0 ;
V_194 = V_70 -> V_328 + V_330 ;
if ( V_330 < V_70 -> V_326 )
memmove ( V_194 + 1 , V_194 ,
( V_70 -> V_326 - V_330 ) * sizeof( struct V_329 ) ) ;
V_70 -> V_326 ++ ;
V_194 -> V_326 = 1 ;
V_194 -> V_16 = V_50 -> V_16 ;
V_194 -> V_333 = V_332 ;
V_194 -> V_334 = V_332 ;
V_194 -> V_335 = V_332 ;
V_194 -> V_336 = V_50 -> V_64 ;
V_194 -> V_337 = V_50 -> V_64 ;
F_359 ( F_356 ( V_194 -> V_338 ) ) ;
F_355 ( V_50 -> V_63 , F_356 ( V_194 -> V_338 ) ) ;
F_360 ( V_194 -> V_339 ) ;
F_357 ( F_148 ( F_358 ( V_50 ) ) , V_194 -> V_339 ) ;
return 1 ;
}
static void F_361 ( struct V_327 * V_70 , struct V_1 * V_2 ,
struct V_9 * V_9 , enum V_51 V_52 ,
unsigned long * V_45 )
{
void * V_16 = F_13 ( V_9 ) ;
void * V_5 ;
F_345 ( V_45 , V_9 -> V_12 ) ;
F_43 ( V_2 , V_9 , V_45 ) ;
F_153 (p, s, addr, page->objects)
if ( ! F_287 ( F_21 ( V_5 , V_2 , V_16 ) , V_45 ) )
F_354 ( V_70 , V_2 , F_51 ( V_2 , V_5 , V_52 ) ) ;
}
static int F_362 ( struct V_1 * V_2 , char * V_79 ,
enum V_51 V_52 )
{
int V_340 = 0 ;
unsigned long V_55 ;
struct V_327 V_70 = { 0 , 0 , NULL } ;
int V_108 ;
unsigned long * V_45 = F_349 ( F_286 ( F_26 ( V_2 -> F_262 ) ) *
sizeof( unsigned long ) , V_270 ) ;
struct V_104 * V_38 ;
if ( ! V_45 || ! F_352 ( & V_70 , V_25 / sizeof( struct V_329 ) ,
V_341 ) ) {
F_288 ( V_45 ) ;
return sprintf ( V_79 , L_71 ) ;
}
F_215 ( V_2 ) ;
F_229 (s, node, n) {
unsigned long V_3 ;
struct V_9 * V_9 ;
if ( ! F_88 ( & V_38 -> V_109 ) )
continue;
F_222 ( & V_38 -> V_105 , V_3 ) ;
F_223 (page, &n->partial, lru)
F_361 ( & V_70 , V_2 , V_9 , V_52 , V_45 ) ;
F_223 (page, &n->full, lru)
F_361 ( & V_70 , V_2 , V_9 , V_52 , V_45 ) ;
F_224 ( & V_38 -> V_105 , V_3 ) ;
}
for ( V_55 = 0 ; V_55 < V_70 . V_326 ; V_55 ++ ) {
struct V_329 * V_194 = & V_70 . V_328 [ V_55 ] ;
if ( V_340 > V_25 - V_342 - 100 )
break;
V_340 += sprintf ( V_79 + V_340 , L_72 , V_194 -> V_326 ) ;
if ( V_194 -> V_16 )
V_340 += sprintf ( V_79 + V_340 , L_73 , ( void * ) V_194 -> V_16 ) ;
else
V_340 += sprintf ( V_79 + V_340 , L_74 ) ;
if ( V_194 -> V_333 != V_194 -> V_334 ) {
V_340 += sprintf ( V_79 + V_340 , L_75 ,
V_194 -> V_334 ,
( long ) F_363 ( V_194 -> V_333 , V_194 -> V_326 ) ,
V_194 -> V_335 ) ;
} else
V_340 += sprintf ( V_79 + V_340 , L_76 ,
V_194 -> V_334 ) ;
if ( V_194 -> V_336 != V_194 -> V_337 )
V_340 += sprintf ( V_79 + V_340 , L_77 ,
V_194 -> V_336 , V_194 -> V_337 ) ;
else
V_340 += sprintf ( V_79 + V_340 , L_78 ,
V_194 -> V_336 ) ;
if ( F_364 () > 1 &&
! F_365 ( F_356 ( V_194 -> V_338 ) ) &&
V_340 < V_25 - 60 )
V_340 += F_366 ( V_79 + V_340 , V_25 - V_340 - 50 ,
L_79 ,
F_367 ( F_356 ( V_194 -> V_338 ) ) ) ;
if ( V_343 > 1 && ! F_368 ( V_194 -> V_339 ) &&
V_340 < V_25 - 60 )
V_340 += F_366 ( V_79 + V_340 , V_25 - V_340 - 50 ,
L_80 ,
F_369 ( & V_194 -> V_339 ) ) ;
V_340 += sprintf ( V_79 + V_340 , L_81 ) ;
}
F_350 ( & V_70 ) ;
F_288 ( V_45 ) ;
if ( ! V_70 . V_326 )
V_340 += sprintf ( V_79 , L_82 ) ;
return V_340 ;
}
static void T_6 F_370 ( void )
{
T_3 * V_5 ;
F_270 ( V_344 > 16 || V_266 < 10 ) ;
F_58 ( L_83 ) ;
F_58 ( L_84 ) ;
F_58 ( L_85 ) ;
V_5 = F_285 ( 16 , V_270 ) ;
V_5 [ 16 ] = 0x12 ;
F_58 ( L_86 ,
V_5 + 16 ) ;
F_348 ( V_345 [ 4 ] ) ;
V_5 = F_285 ( 32 , V_270 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_58 ( L_87 ,
V_5 ) ;
F_58 ( L_88 ) ;
F_348 ( V_345 [ 5 ] ) ;
V_5 = F_285 ( 64 , V_270 ) ;
V_5 += 64 + ( F_181 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_58 ( L_89 ,
V_5 ) ;
F_58 ( L_88 ) ;
F_348 ( V_345 [ 6 ] ) ;
F_58 ( L_90 ) ;
V_5 = F_285 ( 128 , V_270 ) ;
F_288 ( V_5 ) ;
* V_5 = 0x78 ;
F_58 ( L_91 , V_5 ) ;
F_348 ( V_345 [ 7 ] ) ;
V_5 = F_285 ( 256 , V_270 ) ;
F_288 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_58 ( L_92 , V_5 ) ;
F_348 ( V_345 [ 8 ] ) ;
V_5 = F_285 ( 512 , V_270 ) ;
F_288 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_58 ( L_93 , V_5 ) ;
F_348 ( V_345 [ 9 ] ) ;
}
static void F_370 ( void ) {}
static T_9 F_371 ( struct V_1 * V_2 ,
char * V_79 , unsigned long V_3 )
{
unsigned long V_346 = 0 ;
int V_108 ;
int V_27 ;
unsigned long * V_339 ;
V_339 = F_285 ( sizeof( unsigned long ) * V_314 , V_270 ) ;
if ( ! V_339 )
return - V_294 ;
if ( V_3 & V_347 ) {
int V_63 ;
F_202 (cpu) {
struct V_168 * V_169 = F_203 ( V_2 -> V_8 ,
V_63 ) ;
int V_108 ;
struct V_9 * V_9 ;
V_9 = F_239 ( V_169 -> V_9 ) ;
if ( ! V_9 )
continue;
V_108 = F_148 ( V_9 ) ;
if ( V_3 & V_348 )
V_27 = V_9 -> V_12 ;
else if ( V_3 & V_349 )
V_27 = V_9 -> V_22 ;
else
V_27 = 1 ;
V_346 += V_27 ;
V_339 [ V_108 ] += V_27 ;
V_9 = F_239 ( V_169 -> V_165 ) ;
if ( V_9 ) {
V_108 = F_148 ( V_9 ) ;
if ( V_3 & V_348 )
F_372 ( 1 ) ;
else if ( V_3 & V_349 )
F_372 ( 1 ) ;
else
V_27 = V_9 -> V_149 ;
V_346 += V_27 ;
V_339 [ V_108 ] += V_27 ;
}
}
}
F_373 () ;
#ifdef F_2
if ( V_3 & V_350 ) {
struct V_104 * V_38 ;
F_229 (s, node, n) {
if ( V_3 & V_348 )
V_27 = F_88 ( & V_38 -> V_110 ) ;
else if ( V_3 & V_349 )
V_27 = F_88 ( & V_38 -> V_110 ) -
F_220 ( V_38 , F_218 ) ;
else
V_27 = F_88 ( & V_38 -> V_109 ) ;
V_346 += V_27 ;
V_339 [ V_108 ] += V_27 ;
}
} else
#endif
if ( V_3 & V_351 ) {
struct V_104 * V_38 ;
F_229 (s, node, n) {
if ( V_3 & V_348 )
V_27 = F_220 ( V_38 , F_343 ) ;
else if ( V_3 & V_349 )
V_27 = F_220 ( V_38 , F_342 ) ;
else
V_27 = V_38 -> V_163 ;
V_346 += V_27 ;
V_339 [ V_108 ] += V_27 ;
}
}
V_27 = sprintf ( V_79 , L_94 , V_346 ) ;
#ifdef F_179
for ( V_108 = 0 ; V_108 < V_314 ; V_108 ++ )
if ( V_339 [ V_108 ] )
V_27 += sprintf ( V_79 + V_27 , L_95 ,
V_108 , V_339 [ V_108 ] ) ;
#endif
F_374 () ;
F_288 ( V_339 ) ;
return V_27 + sprintf ( V_79 + V_27 , L_81 ) ;
}
static int F_375 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_38 ;
F_229 (s, node, n)
if ( F_88 ( & V_38 -> V_110 ) )
return 1 ;
return 0 ;
}
static T_9 F_376 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_13 ) ;
}
static T_9 F_377 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_274 ) ;
}
static T_9 F_378 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_19 ) ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , F_26 ( V_2 -> V_134 ) ) ;
}
static T_9 F_380 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
unsigned long V_23 ;
int V_317 ;
V_317 = F_381 ( V_79 , 10 , & V_23 ) ;
if ( V_317 )
return V_317 ;
if ( V_23 > V_262 || V_23 < V_257 )
return - V_281 ;
F_278 ( V_2 , V_23 ) ;
return V_47 ;
}
static T_9 F_382 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , F_25 ( V_2 -> V_134 ) ) ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_97 , V_2 -> V_183 ) ;
}
static T_9 F_384 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
unsigned long V_144 ;
int V_317 ;
V_317 = F_381 ( V_79 , 10 , & V_144 ) ;
if ( V_317 )
return V_317 ;
F_277 ( V_2 , V_144 ) ;
return V_47 ;
}
static T_9 F_385 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_98 , V_2 -> V_174 ) ;
}
static T_9 F_386 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
unsigned long V_12 ;
int V_317 ;
V_317 = F_381 ( V_79 , 10 , & V_12 ) ;
if ( V_317 )
return V_317 ;
if ( V_12 && ! F_4 ( V_2 ) )
return - V_281 ;
V_2 -> V_174 = V_12 ;
F_215 ( V_2 ) ;
return V_47 ;
}
static T_9 F_387 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! V_2 -> F_101 )
return 0 ;
return sprintf ( V_79 , L_99 , V_2 -> F_101 ) ;
}
static T_9 F_388 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_316 < 0 ? 0 : V_2 -> V_316 - 1 ) ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_79 )
{
return F_371 ( V_2 , V_79 , V_351 ) ;
}
static T_9 F_390 ( struct V_1 * V_2 , char * V_79 )
{
return F_371 ( V_2 , V_79 , V_347 ) ;
}
static T_9 F_391 ( struct V_1 * V_2 , char * V_79 )
{
return F_371 ( V_2 , V_79 , V_350 | V_349 ) ;
}
static T_9 F_392 ( struct V_1 * V_2 , char * V_79 )
{
return F_371 ( V_2 , V_79 , V_351 | V_349 ) ;
}
static T_9 F_393 ( struct V_1 * V_2 , char * V_79 )
{
int V_12 = 0 ;
int V_149 = 0 ;
int V_63 ;
int V_340 ;
F_394 (cpu) {
struct V_9 * V_9 = F_203 ( V_2 -> V_8 , V_63 ) -> V_165 ;
if ( V_9 ) {
V_149 += V_9 -> V_149 ;
V_12 += V_9 -> V_211 ;
}
}
V_340 = sprintf ( V_79 , L_100 , V_12 , V_149 ) ;
#ifdef F_330
F_394 (cpu) {
struct V_9 * V_9 = F_203 ( V_2 -> V_8 , V_63 ) -> V_165 ;
if ( V_9 && V_340 < V_25 - 20 )
V_340 += sprintf ( V_79 + V_340 , L_101 , V_63 ,
V_9 -> V_211 , V_9 -> V_149 ) ;
}
#endif
return V_340 + sprintf ( V_79 + V_340 , L_81 ) ;
}
static T_9 F_395 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_151 ) ) ;
}
static T_9 F_396 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
V_2 -> V_3 &= ~ V_151 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_151 ;
return V_47 ;
}
static T_9 F_397 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_311 ) ) ;
}
static T_9 F_398 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_276 ) ) ;
}
static T_9 F_399 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_400 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_24 ) ;
}
static T_9 F_401 ( struct V_1 * V_2 , char * V_79 )
{
return F_371 ( V_2 , V_79 , V_350 ) ;
}
static T_9 F_402 ( struct V_1 * V_2 , char * V_79 )
{
return F_371 ( V_2 , V_79 , V_350 | V_348 ) ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_118 ) ) ;
}
static T_9 F_404 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
V_2 -> V_3 &= ~ V_118 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_118 ;
}
return V_47 ;
}
static T_9 F_405 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_103 ) ) ;
}
static T_9 F_406 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
if ( V_2 -> V_316 > 1 )
return - V_281 ;
V_2 -> V_3 &= ~ V_103 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_103 ;
}
return V_47 ;
}
static T_9 F_407 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_17 ) ) ;
}
static T_9 F_408 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( F_375 ( V_2 ) )
return - V_352 ;
V_2 -> V_3 &= ~ V_17 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_17 ;
}
F_278 ( V_2 , - 1 ) ;
return V_47 ;
}
static T_9 F_409 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_18 ) ) ;
}
static T_9 F_410 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( F_375 ( V_2 ) )
return - V_352 ;
V_2 -> V_3 &= ~ V_18 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_18 ;
}
F_278 ( V_2 , - 1 ) ;
return V_47 ;
}
static T_9 F_411 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_21 ) ) ;
}
static T_9 F_412 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( F_375 ( V_2 ) )
return - V_352 ;
V_2 -> V_3 &= ~ V_21 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_21 ;
}
F_278 ( V_2 , - 1 ) ;
return V_47 ;
}
static T_9 F_413 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_414 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
int V_235 = - V_281 ;
if ( V_79 [ 0 ] == '1' ) {
V_235 = F_348 ( V_2 ) ;
if ( V_235 >= 0 )
V_235 = V_47 ;
}
return V_235 ;
}
static T_9 F_415 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return - V_264 ;
return F_362 ( V_2 , V_79 , V_69 ) ;
}
static T_9 F_416 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_21 ) )
return - V_264 ;
return F_362 ( V_2 , V_79 , V_68 ) ;
}
static T_9 F_417 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_9 F_418 ( struct V_1 * V_2 , const char * V_79 ,
T_1 V_47 )
{
if ( V_2 -> V_316 > 1 )
return - V_281 ;
V_2 -> V_3 &= ~ V_119 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_119 ;
return V_47 ;
}
static T_9 F_419 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_420 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
if ( V_79 [ 0 ] == '1' )
F_421 ( V_2 ) ;
else
return - V_281 ;
return V_47 ;
}
static T_9 F_422 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_96 , V_2 -> V_182 / 10 ) ;
}
static T_9 F_423 ( struct V_1 * V_2 ,
const char * V_79 , T_1 V_47 )
{
unsigned long V_353 ;
int V_317 ;
V_317 = F_381 ( V_79 , 10 , & V_353 ) ;
if ( V_317 )
return V_317 ;
if ( V_353 <= 100 )
V_2 -> V_182 = V_353 * 10 ;
return V_47 ;
}
static int F_424 ( struct V_1 * V_2 , char * V_79 , enum V_6 V_7 )
{
unsigned long V_354 = 0 ;
int V_63 ;
int V_340 ;
int * V_85 = F_349 ( V_261 * sizeof( int ) , V_270 ) ;
if ( ! V_85 )
return - V_294 ;
F_394 (cpu) {
unsigned V_27 = F_203 ( V_2 -> V_8 , V_63 ) -> F_9 [ V_7 ] ;
V_85 [ V_63 ] = V_27 ;
V_354 += V_27 ;
}
V_340 = sprintf ( V_79 , L_94 , V_354 ) ;
#ifdef F_330
F_394 (cpu) {
if ( V_85 [ V_63 ] && V_340 < V_25 - 20 )
V_340 += sprintf ( V_79 + V_340 , L_102 , V_63 , V_85 [ V_63 ] ) ;
}
#endif
F_288 ( V_85 ) ;
return V_340 + sprintf ( V_79 + V_340 , L_81 ) ;
}
static void F_425 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_63 ;
F_394 (cpu)
F_203 ( V_2 -> V_8 , V_63 ) -> F_9 [ V_7 ] = 0 ;
}
static T_9 F_426 ( struct V_355 * V_356 ,
struct V_357 * V_358 ,
char * V_79 )
{
struct V_359 * V_357 ;
struct V_1 * V_2 ;
int V_317 ;
V_357 = F_427 ( V_358 ) ;
V_2 = F_428 ( V_356 ) ;
if ( ! V_357 -> V_360 )
return - V_361 ;
V_317 = V_357 -> V_360 ( V_2 , V_79 ) ;
return V_317 ;
}
static T_9 F_429 ( struct V_355 * V_356 ,
struct V_357 * V_358 ,
const char * V_79 , T_1 V_340 )
{
struct V_359 * V_357 ;
struct V_1 * V_2 ;
int V_317 ;
V_357 = F_427 ( V_358 ) ;
V_2 = F_428 ( V_356 ) ;
if ( ! V_357 -> V_362 )
return - V_361 ;
V_317 = V_357 -> V_362 ( V_2 , V_79 , V_340 ) ;
#ifdef F_430
if ( V_268 >= V_363 && V_317 >= 0 && F_431 ( V_2 ) ) {
struct V_1 * V_169 ;
F_314 ( & V_289 ) ;
if ( V_2 -> V_364 < V_340 )
V_2 -> V_364 = V_340 ;
F_337 (c, s)
V_357 -> V_362 ( V_169 , V_79 , V_340 ) ;
F_315 ( & V_289 ) ;
}
#endif
return V_317 ;
}
static void F_8 ( struct V_1 * V_2 )
{
#ifdef F_430
int V_55 ;
char * V_365 = NULL ;
struct V_1 * V_366 ;
if ( F_431 ( V_2 ) )
return;
V_366 = V_2 -> V_367 . V_366 ;
if ( ! V_366 -> V_364 )
return;
for ( V_55 = 0 ; V_55 < F_432 ( V_368 ) ; V_55 ++ ) {
char V_369 [ 64 ] ;
char * V_79 ;
struct V_359 * V_358 = F_427 ( V_368 [ V_55 ] ) ;
if ( ! V_358 || ! V_358 -> V_362 || ! V_358 -> V_360 )
continue;
if ( V_365 )
V_79 = V_365 ;
else if ( V_366 -> V_364 < F_432 ( V_369 ) )
V_79 = V_369 ;
else {
V_365 = ( char * ) F_433 ( V_270 ) ;
if ( F_171 ( ! V_365 ) )
continue;
V_79 = V_365 ;
}
V_358 -> V_360 ( V_366 , V_79 ) ;
V_358 -> V_362 ( V_2 , V_79 , strlen ( V_79 ) ) ;
}
if ( V_365 )
F_434 ( ( unsigned long ) V_365 ) ;
#endif
}
static void F_435 ( struct V_355 * V_370 )
{
F_436 ( F_428 ( V_370 ) ) ;
}
static int F_437 ( struct V_371 * V_371 , struct V_355 * V_356 )
{
struct V_372 * V_373 = F_438 ( V_356 ) ;
if ( V_373 == & V_374 )
return 1 ;
return 0 ;
}
static inline struct V_371 * F_439 ( struct V_1 * V_2 )
{
#ifdef F_430
if ( ! F_431 ( V_2 ) )
return V_2 -> V_367 . V_366 -> V_375 ;
#endif
return V_376 ;
}
static char * F_440 ( struct V_1 * V_2 )
{
char * V_44 = F_349 ( V_377 , V_270 ) ;
char * V_5 = V_44 ;
F_273 ( ! V_44 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_276 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_151 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_118 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_148 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_44 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_103 , V_2 -> V_13 ) ;
F_273 ( V_5 > V_44 + V_377 - 1 ) ;
return V_44 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_317 ;
const char * V_44 ;
int V_378 = F_441 ( V_2 ) ;
if ( V_378 ) {
F_442 ( & V_376 -> V_356 , V_2 -> V_44 ) ;
V_44 = V_2 -> V_44 ;
} else {
V_44 = F_440 ( V_2 ) ;
}
V_2 -> V_356 . V_371 = F_439 ( V_2 ) ;
V_317 = F_443 ( & V_2 -> V_356 , & V_374 , NULL , L_16 , V_44 ) ;
if ( V_317 )
goto V_116;
V_317 = F_444 ( & V_2 -> V_356 , & V_379 ) ;
if ( V_317 )
goto V_380;
#ifdef F_430
if ( F_431 ( V_2 ) ) {
V_2 -> V_375 = F_445 ( L_104 , NULL , & V_2 -> V_356 ) ;
if ( ! V_2 -> V_375 ) {
V_317 = - V_294 ;
goto V_380;
}
}
#endif
F_446 ( & V_2 -> V_356 , V_381 ) ;
if ( ! V_378 ) {
F_7 ( V_2 , V_2 -> V_44 ) ;
}
V_116:
if ( ! V_378 )
F_288 ( V_44 ) ;
return V_317 ;
V_380:
F_447 ( & V_2 -> V_356 ) ;
goto V_116;
}
void F_448 ( struct V_1 * V_2 )
{
if ( V_268 < V_363 )
return;
#ifdef F_430
F_449 ( V_2 -> V_375 ) ;
#endif
F_446 ( & V_2 -> V_356 , V_382 ) ;
F_447 ( & V_2 -> V_356 ) ;
F_450 ( & V_2 -> V_356 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_44 )
{
struct V_383 * V_384 ;
if ( V_268 == V_363 ) {
F_442 ( & V_376 -> V_356 , V_44 ) ;
return F_451 ( & V_376 -> V_356 , & V_2 -> V_356 , V_44 ) ;
}
V_384 = F_349 ( sizeof( struct V_383 ) , V_270 ) ;
if ( ! V_384 )
return - V_294 ;
V_384 -> V_2 = V_2 ;
V_384 -> V_44 = V_44 ;
V_384 -> V_207 = V_385 ;
V_385 = V_384 ;
return 0 ;
}
static int T_6 F_452 ( void )
{
struct V_1 * V_2 ;
int V_317 ;
F_314 ( & V_289 ) ;
V_376 = F_445 ( L_105 , & V_386 , V_387 ) ;
if ( ! V_376 ) {
F_315 ( & V_289 ) ;
F_58 ( L_106 ) ;
return - V_264 ;
}
V_268 = V_363 ;
F_223 (s, &slab_caches, list) {
V_317 = F_6 ( V_2 ) ;
if ( V_317 )
F_58 ( L_107 ,
V_2 -> V_44 ) ;
}
while ( V_385 ) {
struct V_383 * V_384 = V_385 ;
V_385 = V_385 -> V_207 ;
V_317 = F_7 ( V_384 -> V_2 , V_384 -> V_44 ) ;
if ( V_317 )
F_58 ( L_108 ,
V_384 -> V_44 ) ;
F_288 ( V_384 ) ;
}
F_315 ( & V_289 ) ;
F_370 () ;
return 0 ;
}
void F_453 ( struct V_1 * V_2 , struct V_388 * V_389 )
{
unsigned long V_109 = 0 ;
unsigned long V_222 = 0 ;
unsigned long V_223 = 0 ;
int V_108 ;
struct V_104 * V_38 ;
F_229 (s, node, n) {
V_109 += F_89 ( V_38 ) ;
V_222 += F_219 ( V_38 ) ;
V_223 += F_220 ( V_38 , F_218 ) ;
}
V_389 -> V_390 = V_222 - V_223 ;
V_389 -> V_391 = V_222 ;
V_389 -> V_392 = V_109 ;
V_389 -> V_393 = V_109 ;
V_389 -> V_394 = F_26 ( V_2 -> V_134 ) ;
V_389 -> V_395 = F_25 ( V_2 -> V_134 ) ;
}
void F_454 ( struct V_396 * V_195 , struct V_1 * V_2 )
{
}
T_9 F_455 ( struct V_397 * V_397 , const char T_10 * V_365 ,
T_1 V_326 , T_11 * V_398 )
{
return - V_361 ;
}
