static inline int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return F_3 ( V_2 -> V_3 & V_4 ) ;
#else
return 0 ;
#endif
}
void * F_4 ( struct V_1 * V_2 , void * V_5 )
{
if ( F_1 ( V_2 ) && V_2 -> V_3 & V_6 )
V_5 += V_2 -> V_7 ;
return V_5 ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
#ifdef F_6
return ! F_1 ( V_2 ) ;
#else
return false ;
#endif
}
static inline int F_7 ( struct V_1 * V_2 ) { return 0 ; }
static inline int F_8 ( struct V_1 * V_2 , const char * V_5 )
{ return 0 ; }
static inline void F_9 ( struct V_1 * V_2 ) { }
static inline void F_10 ( const struct V_1 * V_2 , enum V_8 V_9 )
{
#ifdef F_11
F_12 ( V_2 -> V_10 -> F_10 [ V_9 ] ) ;
#endif
}
static inline void * F_13 ( struct V_1 * V_2 , void * V_11 )
{
return * ( void * * ) ( V_11 + V_2 -> V_12 ) ;
}
static void F_14 ( const struct V_1 * V_2 , void * V_11 )
{
F_15 ( V_11 + V_2 -> V_12 ) ;
}
static inline void * F_16 ( struct V_1 * V_2 , void * V_11 )
{
void * V_5 ;
if ( ! F_17 () )
return F_13 ( V_2 , V_11 ) ;
F_18 ( & V_5 , ( void * * ) ( V_11 + V_2 -> V_12 ) , sizeof( V_5 ) ) ;
return V_5 ;
}
static inline void F_19 ( struct V_1 * V_2 , void * V_11 , void * V_13 )
{
* ( void * * ) ( V_11 + V_2 -> V_12 ) = V_13 ;
}
static inline int F_20 ( void * V_5 , struct V_1 * V_2 , void * V_14 )
{
return ( V_5 - V_14 ) / V_2 -> V_15 ;
}
static inline int F_21 ( int V_16 , unsigned long V_15 , int V_17 )
{
return ( ( V_18 << V_16 ) - V_17 ) / V_15 ;
}
static inline struct V_19 F_22 ( int V_16 ,
unsigned long V_15 , int V_17 )
{
struct V_19 V_20 = {
( V_16 << V_21 ) + F_21 (order, size, reserved)
} ;
return V_20 ;
}
static inline int F_23 ( struct V_19 V_20 )
{
return V_20 . V_20 >> V_21 ;
}
static inline int F_24 ( struct V_19 V_20 )
{
return V_20 . V_20 & V_22 ;
}
static T_1 void F_25 ( struct V_23 * V_23 )
{
F_26 ( F_27 ( V_23 ) , V_23 ) ;
F_28 ( V_24 , & V_23 -> V_3 ) ;
}
static T_1 void F_29 ( struct V_23 * V_23 )
{
F_26 ( F_27 ( V_23 ) , V_23 ) ;
F_30 ( V_24 , & V_23 -> V_3 ) ;
}
static inline void F_31 ( struct V_23 * V_23 , unsigned long V_25 )
{
struct V_23 V_26 ;
V_26 . V_27 = V_25 ;
V_23 -> V_28 = V_26 . V_28 ;
V_23 -> V_29 = V_26 . V_29 ;
V_23 -> V_30 = V_26 . V_30 ;
}
static inline bool F_32 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_31 , unsigned long V_32 ,
void * V_33 , unsigned long V_25 ,
const char * V_34 )
{
F_33 ( ! F_34 () ) ;
#if F_35 ( V_35 ) && \
F_35 ( V_36 )
if ( V_2 -> V_3 & V_37 ) {
if ( F_36 ( & V_23 -> V_38 , & V_23 -> V_27 ,
V_31 , V_32 ,
V_33 , V_25 ) )
return true ;
} else
#endif
{
F_25 ( V_23 ) ;
if ( V_23 -> V_38 == V_31 &&
V_23 -> V_27 == V_32 ) {
V_23 -> V_38 = V_33 ;
F_31 ( V_23 , V_25 ) ;
F_29 ( V_23 ) ;
return true ;
}
F_29 ( V_23 ) ;
}
F_37 () ;
F_10 ( V_2 , V_39 ) ;
#ifdef F_38
F_39 ( L_1 , V_34 , V_2 -> V_40 ) ;
#endif
return false ;
}
static inline bool F_40 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_31 , unsigned long V_32 ,
void * V_33 , unsigned long V_25 ,
const char * V_34 )
{
#if F_35 ( V_35 ) && \
F_35 ( V_36 )
if ( V_2 -> V_3 & V_37 ) {
if ( F_36 ( & V_23 -> V_38 , & V_23 -> V_27 ,
V_31 , V_32 ,
V_33 , V_25 ) )
return true ;
} else
#endif
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_25 ( V_23 ) ;
if ( V_23 -> V_38 == V_31 &&
V_23 -> V_27 == V_32 ) {
V_23 -> V_38 = V_33 ;
F_31 ( V_23 , V_25 ) ;
F_29 ( V_23 ) ;
F_42 ( V_3 ) ;
return true ;
}
F_29 ( V_23 ) ;
F_42 ( V_3 ) ;
}
F_37 () ;
F_10 ( V_2 , V_39 ) ;
#ifdef F_38
F_39 ( L_1 , V_34 , V_2 -> V_40 ) ;
#endif
return false ;
}
static void F_43 ( struct V_1 * V_2 , struct V_23 * V_23 , unsigned long * V_41 )
{
void * V_5 ;
void * V_14 = F_44 ( V_23 ) ;
for ( V_5 = V_23 -> V_38 ; V_5 ; V_5 = F_13 ( V_2 , V_5 ) )
F_45 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_6 )
return V_2 -> V_15 - V_2 -> V_7 ;
return V_2 -> V_15 ;
}
static inline void * F_47 ( struct V_1 * V_2 , void * V_5 )
{
if ( V_2 -> V_3 & V_6 )
V_5 -= V_2 -> V_7 ;
return V_5 ;
}
static inline void F_48 ( void )
{
F_49 () ;
}
static inline void F_50 ( void )
{
F_51 () ;
}
static inline int F_52 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 )
{
void * V_42 ;
if ( ! V_11 )
return 1 ;
V_42 = F_44 ( V_23 ) ;
V_11 = F_47 ( V_2 , V_11 ) ;
if ( V_11 < V_42 || V_11 >= V_42 + V_23 -> V_30 * V_2 -> V_15 ||
( V_11 - V_42 ) % V_2 -> V_15 ) {
return 0 ;
}
return 1 ;
}
static void F_53 ( char * V_43 , T_2 * V_14 , unsigned int V_44 )
{
F_48 () ;
F_54 ( V_45 , V_43 , V_46 , 16 , 1 , V_14 ,
V_44 , 1 ) ;
F_50 () ;
}
static struct V_47 * F_55 ( struct V_1 * V_2 , void * V_11 ,
enum V_48 V_49 )
{
struct V_47 * V_5 ;
if ( V_2 -> V_12 )
V_5 = V_11 + V_2 -> V_12 + sizeof( void * ) ;
else
V_5 = V_11 + V_2 -> V_29 ;
return V_5 + V_49 ;
}
static void F_56 ( struct V_1 * V_2 , void * V_11 ,
enum V_48 V_49 , unsigned long V_14 )
{
struct V_47 * V_5 = F_55 ( V_2 , V_11 , V_49 ) ;
if ( V_14 ) {
#ifdef F_57
struct V_50 V_51 ;
int V_52 ;
V_51 . V_53 = 0 ;
V_51 . V_54 = V_55 ;
V_51 . V_56 = V_5 -> V_57 ;
V_51 . V_58 = 3 ;
F_48 () ;
F_58 ( & V_51 ) ;
F_50 () ;
if ( V_51 . V_53 != 0 &&
V_51 . V_56 [ V_51 . V_53 - 1 ] == V_59 )
V_51 . V_53 -- ;
for ( V_52 = V_51 . V_53 ; V_52 < V_55 ; V_52 ++ )
V_5 -> V_57 [ V_52 ] = 0 ;
#endif
V_5 -> V_14 = V_14 ;
V_5 -> V_60 = F_59 () ;
V_5 -> V_61 = V_62 -> V_61 ;
V_5 -> V_63 = V_64 ;
} else
memset ( V_5 , 0 , sizeof( struct V_47 ) ) ;
}
static void F_60 ( struct V_1 * V_2 , void * V_11 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_56 ( V_2 , V_11 , V_66 , 0UL ) ;
F_56 ( V_2 , V_11 , V_67 , 0UL ) ;
}
static void F_61 ( const char * V_2 , struct V_47 * V_68 )
{
if ( ! V_68 -> V_14 )
return;
F_62 ( L_2 ,
V_2 , ( void * ) V_68 -> V_14 , V_64 - V_68 -> V_63 , V_68 -> V_60 , V_68 -> V_61 ) ;
#ifdef F_57
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ )
if ( V_68 -> V_57 [ V_52 ] )
F_62 ( L_3 , ( void * ) V_68 -> V_57 [ V_52 ] ) ;
else
break;
}
#endif
}
static void F_63 ( struct V_1 * V_2 , void * V_11 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_61 ( L_4 , F_55 ( V_2 , V_11 , V_67 ) ) ;
F_61 ( L_5 , F_55 ( V_2 , V_11 , V_66 ) ) ;
}
static void F_64 ( struct V_23 * V_23 )
{
F_62 ( L_6 ,
V_23 , V_23 -> V_30 , V_23 -> V_29 , V_23 -> V_38 , V_23 -> V_3 ) ;
}
static void F_65 ( struct V_1 * V_2 , char * V_69 , ... )
{
struct V_70 V_71 ;
T_3 args ;
va_start ( args , V_69 ) ;
V_71 . V_69 = V_69 ;
V_71 . V_72 = & args ;
F_62 ( L_7 ) ;
F_62 ( L_8 , V_2 -> V_40 , F_66 () , & V_71 ) ;
F_62 ( L_9 ) ;
F_67 ( V_73 , V_74 ) ;
va_end ( args ) ;
}
static void F_68 ( struct V_1 * V_2 , char * V_69 , ... )
{
struct V_70 V_71 ;
T_3 args ;
va_start ( args , V_69 ) ;
V_71 . V_69 = V_69 ;
V_71 . V_72 = & args ;
F_62 ( L_10 , V_2 -> V_40 , & V_71 ) ;
va_end ( args ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_23 * V_23 , T_2 * V_5 )
{
unsigned int V_75 ;
T_2 * V_14 = F_44 ( V_23 ) ;
F_63 ( V_2 , V_5 ) ;
F_64 ( V_23 ) ;
F_62 ( L_11 ,
V_5 , V_5 - V_14 , F_13 ( V_2 , V_5 ) ) ;
if ( V_2 -> V_3 & V_6 )
F_53 ( L_12 , V_5 - V_2 -> V_7 , V_2 -> V_7 ) ;
else if ( V_5 > V_14 + 16 )
F_53 ( L_13 , V_5 - 16 , 16 ) ;
F_53 ( L_14 , V_5 , F_70 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_6 )
F_53 ( L_12 , V_5 + V_2 -> V_76 ,
V_2 -> V_29 - V_2 -> V_76 ) ;
if ( V_2 -> V_12 )
V_75 = V_2 -> V_12 + sizeof( void * ) ;
else
V_75 = V_2 -> V_29 ;
if ( V_2 -> V_3 & V_65 )
V_75 += 2 * sizeof( struct V_47 ) ;
V_75 += F_71 ( V_2 ) ;
if ( V_75 != F_46 ( V_2 ) )
F_53 ( L_15 , V_5 + V_75 , F_46 ( V_2 ) - V_75 ) ;
F_72 () ;
}
void F_73 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_77 )
{
F_65 ( V_2 , L_16 , V_77 ) ;
F_69 ( V_2 , V_23 , V_11 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_69 , ... )
{
T_3 args ;
char V_78 [ 100 ] ;
va_start ( args , V_69 ) ;
vsnprintf ( V_78 , sizeof( V_78 ) , V_69 , args ) ;
va_end ( args ) ;
F_65 ( V_2 , L_16 , V_78 ) ;
F_64 ( V_23 ) ;
F_72 () ;
}
static void F_75 ( struct V_1 * V_2 , void * V_11 , T_2 V_79 )
{
T_2 * V_5 = V_11 ;
if ( V_2 -> V_3 & V_6 )
memset ( V_5 - V_2 -> V_7 , V_79 , V_2 -> V_7 ) ;
if ( V_2 -> V_3 & V_80 ) {
memset ( V_5 , V_81 , V_2 -> V_76 - 1 ) ;
V_5 [ V_2 -> V_76 - 1 ] = V_82 ;
}
if ( V_2 -> V_3 & V_6 )
memset ( V_5 + V_2 -> V_76 , V_79 , V_2 -> V_29 - V_2 -> V_76 ) ;
}
static void F_76 ( struct V_1 * V_2 , char * V_83 , T_2 V_84 ,
void * V_85 , void * V_86 )
{
F_68 ( V_2 , L_17 , V_85 , V_86 - 1 , V_84 ) ;
memset ( V_85 , V_84 , V_86 - V_85 ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_87 ,
T_2 * V_88 , unsigned int V_89 , unsigned int V_90 )
{
T_2 * V_91 ;
T_2 * V_92 ;
F_48 () ;
V_91 = F_78 ( V_88 , V_89 , V_90 ) ;
F_50 () ;
if ( ! V_91 )
return 1 ;
V_92 = V_88 + V_90 ;
while ( V_92 > V_91 && V_92 [ - 1 ] == V_89 )
V_92 -- ;
F_65 ( V_2 , L_18 , V_87 ) ;
F_62 ( L_19 ,
V_91 , V_92 - 1 , V_91 [ 0 ] , V_89 ) ;
F_69 ( V_2 , V_23 , V_11 ) ;
F_76 ( V_2 , V_87 , V_89 , V_91 , V_92 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_23 * V_23 , T_2 * V_5 )
{
unsigned long V_75 = V_2 -> V_29 ;
if ( V_2 -> V_12 )
V_75 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_65 )
V_75 += 2 * sizeof( struct V_47 ) ;
V_75 += F_71 ( V_2 ) ;
if ( F_46 ( V_2 ) == V_75 )
return 1 ;
return F_77 ( V_2 , V_23 , V_5 , L_20 ,
V_5 + V_75 , V_93 , F_46 ( V_2 ) - V_75 ) ;
}
static int F_80 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
T_2 * V_88 ;
T_2 * V_91 ;
T_2 * V_92 ;
int V_44 ;
int V_94 ;
if ( ! ( V_2 -> V_3 & V_95 ) )
return 1 ;
V_88 = F_44 ( V_23 ) ;
V_44 = ( V_18 << F_81 ( V_23 ) ) - V_2 -> V_17 ;
V_92 = V_88 + V_44 ;
V_94 = V_44 % V_2 -> V_15 ;
if ( ! V_94 )
return 1 ;
F_48 () ;
V_91 = F_78 ( V_92 - V_94 , V_93 , V_94 ) ;
F_50 () ;
if ( ! V_91 )
return 1 ;
while ( V_92 > V_91 && V_92 [ - 1 ] == V_93 )
V_92 -- ;
F_74 ( V_2 , V_23 , L_21 , V_91 , V_92 - 1 ) ;
F_53 ( L_15 , V_92 - V_94 , V_94 ) ;
F_76 ( V_2 , L_22 , V_93 , V_92 - V_94 , V_92 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_79 )
{
T_2 * V_5 = V_11 ;
T_2 * V_96 = V_11 + V_2 -> V_76 ;
if ( V_2 -> V_3 & V_6 ) {
if ( ! F_77 ( V_2 , V_23 , V_11 , L_23 ,
V_11 - V_2 -> V_7 , V_79 , V_2 -> V_7 ) )
return 0 ;
if ( ! F_77 ( V_2 , V_23 , V_11 , L_23 ,
V_96 , V_79 , V_2 -> V_29 - V_2 -> V_76 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_95 ) && V_2 -> V_76 < V_2 -> V_29 ) {
F_77 ( V_2 , V_23 , V_5 , L_24 ,
V_96 , V_93 ,
V_2 -> V_29 - V_2 -> V_76 ) ;
}
}
if ( V_2 -> V_3 & V_95 ) {
if ( V_79 != V_97 && ( V_2 -> V_3 & V_80 ) &&
( ! F_77 ( V_2 , V_23 , V_5 , L_25 , V_5 ,
V_81 , V_2 -> V_76 - 1 ) ||
! F_77 ( V_2 , V_23 , V_5 , L_25 ,
V_5 + V_2 -> V_76 - 1 , V_82 , 1 ) ) )
return 0 ;
F_79 ( V_2 , V_23 , V_5 ) ;
}
if ( ! V_2 -> V_12 && V_79 == V_97 )
return 1 ;
if ( ! F_52 ( V_2 , V_23 , F_13 ( V_2 , V_5 ) ) ) {
F_73 ( V_2 , V_23 , V_5 , L_26 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_98 ;
F_33 ( ! F_34 () ) ;
if ( ! F_84 ( V_23 ) ) {
F_74 ( V_2 , V_23 , L_27 ) ;
return 0 ;
}
V_98 = F_21 ( F_81 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_23 -> V_30 > V_98 ) {
F_74 ( V_2 , V_23 , L_28 ,
V_23 -> V_30 , V_98 ) ;
return 0 ;
}
if ( V_23 -> V_29 > V_23 -> V_30 ) {
F_74 ( V_2 , V_23 , L_29 ,
V_23 -> V_29 , V_23 -> V_30 ) ;
return 0 ;
}
F_80 ( V_2 , V_23 ) ;
return 1 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_99 )
{
int V_100 = 0 ;
void * V_13 ;
void * V_11 = NULL ;
int V_101 ;
V_13 = V_23 -> V_38 ;
while ( V_13 && V_100 <= V_23 -> V_30 ) {
if ( V_13 == V_99 )
return 1 ;
if ( ! F_52 ( V_2 , V_23 , V_13 ) ) {
if ( V_11 ) {
F_73 ( V_2 , V_23 , V_11 ,
L_30 ) ;
F_19 ( V_2 , V_11 , NULL ) ;
} else {
F_74 ( V_2 , V_23 , L_26 ) ;
V_23 -> V_38 = NULL ;
V_23 -> V_29 = V_23 -> V_30 ;
F_68 ( V_2 , L_31 ) ;
return 0 ;
}
break;
}
V_11 = V_13 ;
V_13 = F_13 ( V_2 , V_11 ) ;
V_100 ++ ;
}
V_101 = F_21 ( F_81 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_101 > V_102 )
V_101 = V_102 ;
if ( V_23 -> V_30 != V_101 ) {
F_74 ( V_2 , V_23 , L_32 ,
V_23 -> V_30 , V_101 ) ;
V_23 -> V_30 = V_101 ;
F_68 ( V_2 , L_33 ) ;
}
if ( V_23 -> V_29 != V_23 -> V_30 - V_100 ) {
F_74 ( V_2 , V_23 , L_34 ,
V_23 -> V_29 , V_23 -> V_30 - V_100 ) ;
V_23 -> V_29 = V_23 -> V_30 - V_100 ;
F_68 ( V_2 , L_35 ) ;
}
return V_99 == NULL ;
}
static void V_51 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_11 ,
int V_49 )
{
if ( V_2 -> V_3 & V_103 ) {
F_39 ( L_36 ,
V_2 -> V_40 ,
V_49 ? L_37 : L_38 ,
V_11 , V_23 -> V_29 ,
V_23 -> V_38 ) ;
if ( ! V_49 )
F_53 ( L_14 , ( void * ) V_11 ,
V_2 -> V_76 ) ;
F_72 () ;
}
}
static void F_86 ( struct V_1 * V_2 ,
struct V_104 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_87 ( & V_34 -> V_105 ) ;
F_88 ( & V_23 -> V_106 , & V_34 -> V_107 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_104 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_87 ( & V_34 -> V_105 ) ;
F_90 ( & V_23 -> V_106 ) ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_108 )
{
struct V_104 * V_34 = F_92 ( V_2 , V_108 ) ;
return F_93 ( & V_34 -> V_109 ) ;
}
static inline unsigned long F_94 ( struct V_104 * V_34 )
{
return F_93 ( & V_34 -> V_109 ) ;
}
static inline void F_95 ( struct V_1 * V_2 , int V_108 , int V_30 )
{
struct V_104 * V_34 = F_92 ( V_2 , V_108 ) ;
if ( F_96 ( V_34 ) ) {
F_97 ( & V_34 -> V_109 ) ;
F_98 ( V_30 , & V_34 -> V_110 ) ;
}
}
static inline void F_99 ( struct V_1 * V_2 , int V_108 , int V_30 )
{
struct V_104 * V_34 = F_92 ( V_2 , V_108 ) ;
F_100 ( & V_34 -> V_109 ) ;
F_101 ( V_30 , & V_34 -> V_110 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
if ( ! ( V_2 -> V_3 & ( V_65 | V_6 | V_80 ) ) )
return;
F_75 ( V_2 , V_11 , V_111 ) ;
F_60 ( V_2 , V_11 ) ;
}
static inline int F_103 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( ! F_83 ( V_2 , V_23 ) )
return 0 ;
if ( ! F_52 ( V_2 , V_23 , V_11 ) ) {
F_73 ( V_2 , V_23 , V_11 , L_39 ) ;
return 0 ;
}
if ( ! F_82 ( V_2 , V_23 , V_11 , V_111 ) )
return 0 ;
return 1 ;
}
static T_4 int F_104 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( V_2 -> V_3 & V_112 ) {
if ( ! F_103 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_113;
}
if ( V_2 -> V_3 & V_65 )
F_56 ( V_2 , V_11 , V_67 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 1 ) ;
F_75 ( V_2 , V_11 , V_97 ) ;
return 1 ;
V_113:
if ( F_84 ( V_23 ) ) {
F_68 ( V_2 , L_40 ) ;
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_38 = NULL ;
}
return 0 ;
}
static inline int F_105 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 )
{
if ( ! F_52 ( V_2 , V_23 , V_11 ) ) {
F_74 ( V_2 , V_23 , L_41 , V_11 ) ;
return 0 ;
}
if ( F_85 ( V_2 , V_23 , V_11 ) ) {
F_73 ( V_2 , V_23 , V_11 , L_42 ) ;
return 0 ;
}
if ( ! F_82 ( V_2 , V_23 , V_11 , V_97 ) )
return 0 ;
if ( F_3 ( V_2 != V_23 -> V_114 ) ) {
if ( ! F_84 ( V_23 ) ) {
F_74 ( V_2 , V_23 , L_43 ,
V_11 ) ;
} else if ( ! V_23 -> V_114 ) {
F_62 ( L_44 ,
V_11 ) ;
F_72 () ;
} else
F_73 ( V_2 , V_23 , V_11 ,
L_45 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_106 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_117 ,
unsigned long V_14 )
{
struct V_104 * V_34 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
void * V_11 = V_115 ;
int V_118 = 0 ;
unsigned long V_119 ( V_3 ) ;
int V_120 = 0 ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_25 ( V_23 ) ;
if ( V_2 -> V_3 & V_112 ) {
if ( ! F_83 ( V_2 , V_23 ) )
goto V_121;
}
V_122:
V_118 ++ ;
if ( V_2 -> V_3 & V_112 ) {
if ( ! F_105 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_121;
}
if ( V_2 -> V_3 & V_65 )
F_56 ( V_2 , V_11 , V_66 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 0 ) ;
F_75 ( V_2 , V_11 , V_111 ) ;
if ( V_11 != V_116 ) {
V_11 = F_13 ( V_2 , V_11 ) ;
goto V_122;
}
V_120 = 1 ;
V_121:
if ( V_118 != V_117 )
F_74 ( V_2 , V_23 , L_46 ,
V_117 , V_118 ) ;
F_29 ( V_23 ) ;
F_109 ( & V_34 -> V_105 , V_3 ) ;
if ( ! V_120 )
F_68 ( V_2 , L_47 , V_11 ) ;
return V_120 ;
}
static int T_5 F_110 ( char * V_123 )
{
V_124 = V_125 ;
if ( * V_123 ++ != '=' || ! * V_123 )
goto V_121;
if ( * V_123 == ',' )
goto V_126;
V_124 = 0 ;
if ( * V_123 == '-' )
goto V_121;
for (; * V_123 && * V_123 != ',' ; V_123 ++ ) {
switch ( tolower ( * V_123 ) ) {
case 'f' :
V_124 |= V_112 ;
break;
case 'z' :
V_124 |= V_6 ;
break;
case 'p' :
V_124 |= V_95 ;
break;
case 'u' :
V_124 |= V_65 ;
break;
case 't' :
V_124 |= V_103 ;
break;
case 'a' :
V_124 |= V_127 ;
break;
case 'o' :
V_128 = 1 ;
break;
default:
F_62 ( L_48 ,
* V_123 ) ;
}
}
V_126:
if ( * V_123 == ',' )
V_129 = V_123 + 1 ;
V_121:
return 1 ;
}
unsigned long F_111 ( unsigned long V_76 ,
unsigned long V_3 , const char * V_40 ,
void (* F_112)( void * ) )
{
if ( V_124 && ( ! V_129 || ( V_40 &&
! strncmp ( V_129 , V_40 , strlen ( V_129 ) ) ) ) )
V_3 |= V_124 ;
return V_3 ;
}
static inline void F_102 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 ) {}
static inline int F_104 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 ) { return 0 ; }
static inline int F_106 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_117 ,
unsigned long V_14 ) { return 0 ; }
static inline int F_80 ( struct V_1 * V_2 , struct V_23 * V_23 )
{ return 1 ; }
static inline int F_82 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_79 ) { return 1 ; }
static inline void F_86 ( struct V_1 * V_2 , struct V_104 * V_34 ,
struct V_23 * V_23 ) {}
static inline void F_89 ( struct V_1 * V_2 , struct V_104 * V_34 ,
struct V_23 * V_23 ) {}
unsigned long F_111 ( unsigned long V_76 ,
unsigned long V_3 , const char * V_40 ,
void (* F_112)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_108 )
{ return 0 ; }
static inline unsigned long F_94 ( struct V_104 * V_34 )
{ return 0 ; }
static inline void F_95 ( struct V_1 * V_2 , int V_108 ,
int V_30 ) {}
static inline void F_99 ( struct V_1 * V_2 , int V_108 ,
int V_30 ) {}
static inline void F_113 ( void * V_130 , T_6 V_15 , T_7 V_3 )
{
F_114 ( V_130 , V_15 , 1 , V_3 ) ;
F_115 ( V_130 , V_15 , V_3 ) ;
}
static inline void F_116 ( const void * V_20 )
{
F_117 ( V_20 ) ;
F_118 ( V_20 ) ;
}
static inline void * F_119 ( struct V_1 * V_2 , void * V_20 )
{
void * V_131 ;
F_120 ( V_20 , V_2 -> V_3 ) ;
#if F_35 ( V_132 ) || F_35 ( V_133 )
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_121 ( V_2 , V_20 , V_2 -> V_76 ) ;
F_122 ( V_20 , V_2 -> V_76 ) ;
F_42 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_134 ) )
F_123 ( V_20 , V_2 -> V_76 ) ;
V_131 = F_13 ( V_2 , V_20 ) ;
F_124 ( V_2 , V_20 ) ;
return V_131 ;
}
static inline void F_125 ( struct V_1 * V_2 ,
void * V_115 , void * V_116 )
{
#if F_35 ( V_132 ) || \
F_35 ( V_133 ) || \
F_35 ( V_135 ) || \
F_35 ( V_136 ) || \
F_35 ( V_137 )
void * V_11 = V_115 ;
void * V_138 = V_116 ? : V_115 ;
void * V_131 ;
do {
V_131 = F_119 ( V_2 , V_11 ) ;
} while ( ( V_11 != V_138 ) && ( V_11 = V_131 ) );
#endif
}
static void F_126 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
F_102 ( V_2 , V_23 , V_11 ) ;
F_127 ( V_2 , V_11 ) ;
if ( F_3 ( V_2 -> F_112 ) ) {
F_128 ( V_2 , V_11 ) ;
V_2 -> F_112 ( V_11 ) ;
F_129 ( V_2 , V_11 ) ;
}
}
static inline struct V_23 * F_130 ( struct V_1 * V_2 ,
T_7 V_3 , int V_108 , struct V_19 V_139 )
{
struct V_23 * V_23 ;
int V_16 = F_23 ( V_139 ) ;
V_3 |= V_140 ;
if ( V_108 == V_141 )
V_23 = F_131 ( V_3 , V_16 ) ;
else
V_23 = F_132 ( V_108 , V_3 , V_16 ) ;
if ( V_23 && F_133 ( V_23 , V_3 , V_16 , V_2 ) ) {
F_134 ( V_23 , V_16 ) ;
V_23 = NULL ;
}
return V_23 ;
}
static int F_135 ( struct V_1 * V_2 )
{
int V_142 ;
unsigned long V_52 , V_143 = F_24 ( V_2 -> V_139 ) ;
V_142 = F_136 ( V_2 , V_143 , V_144 ) ;
if ( V_142 ) {
F_62 ( L_49 ,
V_2 -> V_40 ) ;
return V_142 ;
}
if ( V_2 -> V_145 ) {
for ( V_52 = 0 ; V_52 < V_143 ; V_52 ++ )
V_2 -> V_145 [ V_52 ] *= V_2 -> V_15 ;
}
return 0 ;
}
static void T_5 F_137 ( void )
{
struct V_1 * V_2 ;
F_138 ( & V_146 ) ;
F_139 (s, &slab_caches, list)
F_135 ( V_2 ) ;
F_140 ( & V_146 ) ;
}
static void * F_141 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_147 , void * V_88 ,
unsigned long V_148 ,
unsigned long V_149 )
{
unsigned int V_150 ;
do {
V_150 = V_2 -> V_145 [ * V_147 ] ;
* V_147 += 1 ;
if ( * V_147 >= V_149 )
* V_147 = 0 ;
} while ( F_3 ( V_150 >= V_148 ) );
return ( char * ) V_88 + V_150 ;
}
static bool F_142 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
void * V_88 ;
void * V_151 ;
void * V_152 ;
unsigned long V_150 , V_147 , V_148 , V_149 ;
if ( V_23 -> V_30 < 2 || ! V_2 -> V_145 )
return false ;
V_149 = F_24 ( V_2 -> V_139 ) ;
V_147 = F_143 () % V_149 ;
V_148 = V_23 -> V_30 * V_2 -> V_15 ;
V_88 = F_4 ( V_2 , F_44 ( V_23 ) ) ;
V_151 = F_141 ( V_2 , V_23 , & V_147 , V_88 , V_148 ,
V_149 ) ;
V_23 -> V_38 = V_151 ;
for ( V_150 = 1 ; V_150 < V_23 -> V_30 ; V_150 ++ ) {
F_126 ( V_2 , V_23 , V_151 ) ;
V_152 = F_141 ( V_2 , V_23 , & V_147 , V_88 , V_148 ,
V_149 ) ;
F_19 ( V_2 , V_151 , V_152 ) ;
V_151 = V_152 ;
}
F_126 ( V_2 , V_23 , V_151 ) ;
F_19 ( V_2 , V_151 , NULL ) ;
return true ;
}
static inline int F_135 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_137 ( void ) { }
static inline bool F_142 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
return false ;
}
static struct V_23 * F_144 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
struct V_23 * V_23 ;
struct V_19 V_139 = V_2 -> V_139 ;
T_7 V_153 ;
void * V_88 , * V_5 ;
int V_150 , V_16 ;
bool V_154 ;
V_3 &= V_155 ;
if ( F_145 ( V_3 ) )
F_146 () ;
V_3 |= V_2 -> V_156 ;
V_153 = ( V_3 | V_157 | V_158 ) & ~ V_159 ;
if ( ( V_153 & V_160 ) && F_23 ( V_139 ) > F_23 ( V_2 -> V_161 ) )
V_153 = ( V_153 | V_162 ) & ~ ( V_163 | V_159 ) ;
V_23 = F_130 ( V_2 , V_153 , V_108 , V_139 ) ;
if ( F_3 ( ! V_23 ) ) {
V_139 = V_2 -> V_161 ;
V_153 = V_3 ;
V_23 = F_130 ( V_2 , V_153 , V_108 , V_139 ) ;
if ( F_3 ( ! V_23 ) )
goto V_121;
F_10 ( V_2 , V_164 ) ;
}
if ( V_165 &&
! ( V_2 -> V_3 & ( V_166 | V_125 ) ) ) {
int V_167 = 1 << F_23 ( V_139 ) ;
F_147 ( V_23 , F_23 ( V_139 ) , V_153 , V_108 ) ;
if ( V_2 -> F_112 )
F_148 ( V_23 , V_167 ) ;
else
F_149 ( V_23 , V_167 ) ;
}
V_23 -> V_30 = F_24 ( V_139 ) ;
V_16 = F_81 ( V_23 ) ;
V_23 -> V_114 = V_2 ;
F_150 ( V_23 ) ;
if ( F_151 ( V_23 ) )
F_152 ( V_23 ) ;
V_88 = F_44 ( V_23 ) ;
if ( F_3 ( V_2 -> V_3 & V_95 ) )
memset ( V_88 , V_93 , V_18 << V_16 ) ;
F_153 ( V_23 ) ;
V_154 = F_142 ( V_2 , V_23 ) ;
if ( ! V_154 ) {
F_154 (p, idx, s, start, page->objects) {
F_126 ( V_2 , V_23 , V_5 ) ;
if ( F_96 ( V_150 < V_23 -> V_30 ) )
F_19 ( V_2 , V_5 , V_5 + V_2 -> V_15 ) ;
else
F_19 ( V_2 , V_5 , NULL ) ;
}
V_23 -> V_38 = F_4 ( V_2 , V_88 ) ;
}
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_28 = 1 ;
V_121:
if ( F_145 ( V_3 ) )
F_155 () ;
if ( ! V_23 )
return NULL ;
F_156 ( F_157 ( V_23 ) ,
( V_2 -> V_3 & V_168 ) ?
V_169 : V_170 ,
1 << F_23 ( V_139 ) ) ;
F_95 ( V_2 , F_107 ( V_23 ) , V_23 -> V_30 ) ;
return V_23 ;
}
static struct V_23 * F_158 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
if ( F_3 ( V_3 & V_171 ) ) {
T_7 V_172 = V_3 & V_171 ;
V_3 &= ~ V_171 ;
F_159 ( L_50 ,
V_172 , & V_172 , V_3 , & V_3 ) ;
}
return F_144 ( V_2 ,
V_3 & ( V_173 | V_174 ) , V_108 ) ;
}
static void F_160 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_16 = F_81 ( V_23 ) ;
int V_167 = 1 << V_16 ;
if ( V_2 -> V_3 & V_112 ) {
void * V_5 ;
F_80 ( V_2 , V_23 ) ;
F_161 (p, s, page_address(page),
page->objects)
F_82 ( V_2 , V_23 , V_5 , V_111 ) ;
}
F_162 ( V_23 , F_81 ( V_23 ) ) ;
F_156 ( F_157 ( V_23 ) ,
( V_2 -> V_3 & V_168 ) ?
V_169 : V_170 ,
- V_167 ) ;
F_163 ( V_23 ) ;
F_164 ( V_23 ) ;
F_165 ( V_23 ) ;
if ( V_62 -> V_175 )
V_62 -> V_175 -> V_176 += V_167 ;
F_166 ( V_23 , V_16 , V_2 ) ;
F_134 ( V_23 , V_16 ) ;
}
static void F_167 ( struct V_177 * V_178 )
{
struct V_23 * V_23 ;
if ( V_179 )
V_23 = F_168 ( V_178 ) ;
else
V_23 = F_169 ( (struct V_180 * ) V_178 , struct V_23 , V_106 ) ;
F_160 ( V_23 -> V_114 , V_23 ) ;
}
static void F_170 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
if ( F_3 ( V_2 -> V_3 & V_181 ) ) {
struct V_177 * V_115 ;
if ( V_179 ) {
int V_16 = F_81 ( V_23 ) ;
int V_12 = ( V_18 << V_16 ) - V_2 -> V_17 ;
F_33 ( V_2 -> V_17 != sizeof( * V_115 ) ) ;
V_115 = F_44 ( V_23 ) + V_12 ;
} else {
V_115 = & V_23 -> V_177 ;
}
F_171 ( V_115 , F_167 ) ;
} else
F_160 ( V_2 , V_23 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_99 ( V_2 , F_107 ( V_23 ) , V_23 -> V_30 ) ;
F_170 ( V_2 , V_23 ) ;
}
static inline void
F_173 ( struct V_104 * V_34 , struct V_23 * V_23 , int V_116 )
{
V_34 -> V_182 ++ ;
if ( V_116 == V_183 )
F_174 ( & V_23 -> V_106 , & V_34 -> V_184 ) ;
else
F_88 ( & V_23 -> V_106 , & V_34 -> V_184 ) ;
}
static inline void F_175 ( struct V_104 * V_34 ,
struct V_23 * V_23 , int V_116 )
{
F_87 ( & V_34 -> V_105 ) ;
F_173 ( V_34 , V_23 , V_116 ) ;
}
static inline void F_176 ( struct V_104 * V_34 ,
struct V_23 * V_23 )
{
F_87 ( & V_34 -> V_105 ) ;
F_90 ( & V_23 -> V_106 ) ;
V_34 -> V_182 -- ;
}
static inline void * F_177 ( struct V_1 * V_2 ,
struct V_104 * V_34 , struct V_23 * V_23 ,
int V_185 , int * V_30 )
{
void * V_38 ;
unsigned long V_27 ;
struct V_23 V_186 ;
F_87 ( & V_34 -> V_105 ) ;
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_186 . V_27 = V_27 ;
* V_30 = V_186 . V_30 - V_186 . V_29 ;
if ( V_185 ) {
V_186 . V_29 = V_23 -> V_30 ;
V_186 . V_38 = NULL ;
} else {
V_186 . V_38 = V_38 ;
}
F_33 ( V_186 . V_28 ) ;
V_186 . V_28 = 1 ;
if ( ! F_32 ( V_2 , V_23 ,
V_38 , V_27 ,
V_186 . V_38 , V_186 . V_27 ,
L_51 ) )
return NULL ;
F_176 ( V_34 , V_23 ) ;
F_178 ( ! V_38 ) ;
return V_38 ;
}
static void * F_179 ( struct V_1 * V_2 , struct V_104 * V_34 ,
struct V_187 * V_188 , T_7 V_3 )
{
struct V_23 * V_23 , * V_189 ;
void * V_11 = NULL ;
int V_190 = 0 ;
int V_30 ;
if ( ! V_34 || ! V_34 -> V_182 )
return NULL ;
F_180 ( & V_34 -> V_105 ) ;
F_181 (page, page2, &n->partial, lru) {
void * V_68 ;
if ( ! F_182 ( V_23 , V_3 ) )
continue;
V_68 = F_177 ( V_2 , V_34 , V_23 , V_11 == NULL , & V_30 ) ;
if ( ! V_68 )
break;
V_190 += V_30 ;
if ( ! V_11 ) {
V_188 -> V_23 = V_23 ;
F_10 ( V_2 , V_191 ) ;
V_11 = V_68 ;
} else {
F_183 ( V_2 , V_23 , 0 ) ;
F_10 ( V_2 , V_192 ) ;
}
if ( ! F_5 ( V_2 )
|| V_190 > V_2 -> V_193 / 2 )
break;
}
F_184 ( & V_34 -> V_105 ) ;
return V_11 ;
}
static void * F_185 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_187 * V_188 )
{
#ifdef F_186
struct V_194 * V_194 ;
struct V_195 * V_196 ;
struct V_197 * V_197 ;
enum V_198 V_199 = F_187 ( V_3 ) ;
void * V_11 ;
unsigned int V_200 ;
if ( ! V_2 -> V_201 ||
F_188 () % 1024 > V_2 -> V_201 )
return NULL ;
do {
V_200 = F_189 () ;
V_194 = F_190 ( F_191 () , V_3 ) ;
F_192 (zone, z, zonelist, high_zoneidx) {
struct V_104 * V_34 ;
V_34 = F_92 ( V_2 , F_193 ( V_197 ) ) ;
if ( V_34 && F_194 ( V_197 , V_3 ) &&
V_34 -> V_182 > V_2 -> V_202 ) {
V_11 = F_179 ( V_2 , V_34 , V_188 , V_3 ) ;
if ( V_11 ) {
return V_11 ;
}
}
}
} while ( F_195 ( V_200 ) );
#endif
return NULL ;
}
static void * F_196 ( struct V_1 * V_2 , T_7 V_3 , int V_108 ,
struct V_187 * V_188 )
{
void * V_11 ;
int V_203 = V_108 ;
if ( V_108 == V_141 )
V_203 = F_197 () ;
else if ( ! F_198 ( V_108 ) )
V_203 = F_199 ( V_108 ) ;
V_11 = F_179 ( V_2 , F_92 ( V_2 , V_203 ) , V_188 , V_3 ) ;
if ( V_11 || V_108 != V_141 )
return V_11 ;
return F_185 ( V_2 , V_3 , V_188 ) ;
}
static inline unsigned long F_200 ( unsigned long V_204 )
{
return V_204 + V_205 ;
}
static inline unsigned int F_201 ( unsigned long V_204 )
{
return V_204 % V_205 ;
}
static inline unsigned long F_202 ( unsigned long V_204 )
{
return V_204 / V_205 ;
}
static inline unsigned int F_203 ( int V_60 )
{
return V_60 ;
}
static inline void F_204 ( const char * V_34 ,
const struct V_1 * V_2 , unsigned long V_204 )
{
#ifdef F_38
unsigned long V_206 = F_205 ( V_2 -> V_10 -> V_204 ) ;
F_39 ( L_52 , V_34 , V_2 -> V_40 ) ;
#ifdef F_206
if ( F_201 ( V_204 ) != F_201 ( V_206 ) )
F_159 ( L_53 ,
F_201 ( V_204 ) , F_201 ( V_206 ) ) ;
else
#endif
if ( F_202 ( V_204 ) != F_202 ( V_206 ) )
F_159 ( L_54 ,
F_202 ( V_204 ) , F_202 ( V_206 ) ) ;
else
F_159 ( L_55 ,
V_206 , V_204 , F_200 ( V_204 ) ) ;
#endif
F_10 ( V_2 , V_207 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
int V_60 ;
F_208 (cpu)
F_209 ( V_2 -> V_10 , V_60 ) -> V_204 = F_203 ( V_60 ) ;
}
static void F_210 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_38 )
{
enum T_8 { V_208 , V_209 , V_210 , V_211 };
struct V_104 * V_34 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
int V_212 = 0 ;
enum T_8 V_213 = V_208 , V_214 = V_208 ;
void * V_215 ;
int V_116 = V_216 ;
struct V_23 V_186 ;
struct V_23 V_217 ;
if ( V_23 -> V_38 ) {
F_10 ( V_2 , V_218 ) ;
V_116 = V_183 ;
}
while ( V_38 && ( V_215 = F_13 ( V_2 , V_38 ) ) ) {
void * V_219 ;
unsigned long V_27 ;
do {
V_219 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_19 ( V_2 , V_38 , V_219 ) ;
V_186 . V_27 = V_27 ;
V_186 . V_29 -- ;
F_33 ( ! V_186 . V_28 ) ;
} while ( ! F_32 ( V_2 , V_23 ,
V_219 , V_27 ,
V_38 , V_186 . V_27 ,
L_56 ) );
V_38 = V_215 ;
}
V_220:
V_217 . V_38 = V_23 -> V_38 ;
V_217 . V_27 = V_23 -> V_27 ;
F_33 ( ! V_217 . V_28 ) ;
V_186 . V_27 = V_217 . V_27 ;
if ( V_38 ) {
V_186 . V_29 -- ;
F_19 ( V_2 , V_38 , V_217 . V_38 ) ;
V_186 . V_38 = V_38 ;
} else
V_186 . V_38 = V_217 . V_38 ;
V_186 . V_28 = 0 ;
if ( ! V_186 . V_29 && V_34 -> V_182 >= V_2 -> V_202 )
V_214 = V_211 ;
else if ( V_186 . V_38 ) {
V_214 = V_209 ;
if ( ! V_212 ) {
V_212 = 1 ;
F_180 ( & V_34 -> V_105 ) ;
}
} else {
V_214 = V_210 ;
if ( F_1 ( V_2 ) && ! V_212 ) {
V_212 = 1 ;
F_180 ( & V_34 -> V_105 ) ;
}
}
if ( V_213 != V_214 ) {
if ( V_213 == V_209 )
F_176 ( V_34 , V_23 ) ;
else if ( V_213 == V_210 )
F_89 ( V_2 , V_34 , V_23 ) ;
if ( V_214 == V_209 ) {
F_175 ( V_34 , V_23 , V_116 ) ;
F_10 ( V_2 , V_116 ) ;
} else if ( V_214 == V_210 ) {
F_10 ( V_2 , V_221 ) ;
F_86 ( V_2 , V_34 , V_23 ) ;
}
}
V_213 = V_214 ;
if ( ! F_32 ( V_2 , V_23 ,
V_217 . V_38 , V_217 . V_27 ,
V_186 . V_38 , V_186 . V_27 ,
L_57 ) )
goto V_220;
if ( V_212 )
F_184 ( & V_34 -> V_105 ) ;
if ( V_214 == V_211 ) {
F_10 ( V_2 , V_222 ) ;
F_172 ( V_2 , V_23 ) ;
F_10 ( V_2 , V_223 ) ;
}
}
static void F_211 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
#ifdef F_6
struct V_104 * V_34 = NULL , * V_224 = NULL ;
struct V_23 * V_23 , * V_225 = NULL ;
while ( ( V_23 = V_188 -> V_184 ) ) {
struct V_23 V_186 ;
struct V_23 V_217 ;
V_188 -> V_184 = V_23 -> V_152 ;
V_224 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
if ( V_34 != V_224 ) {
if ( V_34 )
F_184 ( & V_34 -> V_105 ) ;
V_34 = V_224 ;
F_180 ( & V_34 -> V_105 ) ;
}
do {
V_217 . V_38 = V_23 -> V_38 ;
V_217 . V_27 = V_23 -> V_27 ;
F_33 ( ! V_217 . V_28 ) ;
V_186 . V_27 = V_217 . V_27 ;
V_186 . V_38 = V_217 . V_38 ;
V_186 . V_28 = 0 ;
} while ( ! F_32 ( V_2 , V_23 ,
V_217 . V_38 , V_217 . V_27 ,
V_186 . V_38 , V_186 . V_27 ,
L_57 ) );
if ( F_3 ( ! V_186 . V_29 && V_34 -> V_182 >= V_2 -> V_202 ) ) {
V_23 -> V_152 = V_225 ;
V_225 = V_23 ;
} else {
F_175 ( V_34 , V_23 , V_183 ) ;
F_10 ( V_2 , V_226 ) ;
}
}
if ( V_34 )
F_184 ( & V_34 -> V_105 ) ;
while ( V_225 ) {
V_23 = V_225 ;
V_225 = V_225 -> V_152 ;
F_10 ( V_2 , V_222 ) ;
F_172 ( V_2 , V_23 ) ;
F_10 ( V_2 , V_223 ) ;
}
#endif
}
static void F_183 ( struct V_1 * V_2 , struct V_23 * V_23 , int V_227 )
{
#ifdef F_6
struct V_23 * V_228 ;
int V_167 ;
int V_229 ;
F_212 () ;
do {
V_167 = 0 ;
V_229 = 0 ;
V_228 = F_213 ( V_2 -> V_10 -> V_184 ) ;
if ( V_228 ) {
V_229 = V_228 -> V_229 ;
V_167 = V_228 -> V_167 ;
if ( V_227 && V_229 > V_2 -> V_193 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_211 ( V_2 , F_214 ( V_2 -> V_10 ) ) ;
F_42 ( V_3 ) ;
V_228 = NULL ;
V_229 = 0 ;
V_167 = 0 ;
F_10 ( V_2 , V_230 ) ;
}
}
V_167 ++ ;
V_229 += V_23 -> V_30 - V_23 -> V_29 ;
V_23 -> V_167 = V_167 ;
V_23 -> V_229 = V_229 ;
V_23 -> V_152 = V_228 ;
} while ( F_215 ( V_2 -> V_10 -> V_184 , V_228 , V_23 )
!= V_228 );
if ( F_3 ( ! V_2 -> V_193 ) ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_211 ( V_2 , F_214 ( V_2 -> V_10 ) ) ;
F_42 ( V_3 ) ;
}
F_216 () ;
#endif
}
static inline void F_217 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
F_10 ( V_2 , V_231 ) ;
F_210 ( V_2 , V_188 -> V_23 , V_188 -> V_38 ) ;
V_188 -> V_204 = F_200 ( V_188 -> V_204 ) ;
V_188 -> V_23 = NULL ;
V_188 -> V_38 = NULL ;
}
static inline void F_218 ( struct V_1 * V_2 , int V_60 )
{
struct V_187 * V_188 = F_209 ( V_2 -> V_10 , V_60 ) ;
if ( F_96 ( V_188 ) ) {
if ( V_188 -> V_23 )
F_217 ( V_2 , V_188 ) ;
F_211 ( V_2 , V_188 ) ;
}
}
static void F_219 ( void * V_232 )
{
struct V_1 * V_2 = V_232 ;
F_218 ( V_2 , F_59 () ) ;
}
static bool F_220 ( int V_60 , void * V_233 )
{
struct V_1 * V_2 = V_233 ;
struct V_187 * V_188 = F_209 ( V_2 -> V_10 , V_60 ) ;
return V_188 -> V_23 || V_188 -> V_184 ;
}
static void F_221 ( struct V_1 * V_2 )
{
F_222 ( F_220 , F_219 , V_2 , 1 , V_234 ) ;
}
static inline int F_223 ( struct V_23 * V_23 , int V_108 )
{
#ifdef F_186
if ( ! V_23 || ( V_108 != V_141 && F_107 ( V_23 ) != V_108 ) )
return 0 ;
#endif
return 1 ;
}
static int F_224 ( struct V_23 * V_23 )
{
return V_23 -> V_30 - V_23 -> V_29 ;
}
static inline unsigned long F_225 ( struct V_104 * V_34 )
{
return F_93 ( & V_34 -> V_110 ) ;
}
static unsigned long F_226 ( struct V_104 * V_34 ,
int (* F_227)( struct V_23 * ) )
{
unsigned long V_3 ;
unsigned long V_20 = 0 ;
struct V_23 * V_23 ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_139 (page, &n->partial, lru)
V_20 += F_227 ( V_23 ) ;
F_109 ( & V_34 -> V_105 , V_3 ) ;
return V_20 ;
}
static T_4 void
F_228 ( struct V_1 * V_2 , T_7 V_235 , int V_236 )
{
#ifdef F_2
static F_229 ( V_237 , V_238 ,
V_239 ) ;
int V_108 ;
struct V_104 * V_34 ;
if ( ( V_235 & V_157 ) || ! F_230 ( & V_237 ) )
return;
F_159 ( L_58 ,
V_236 , V_235 , & V_235 ) ;
F_159 ( L_59 ,
V_2 -> V_40 , V_2 -> V_76 , V_2 -> V_15 , F_23 ( V_2 -> V_139 ) ,
F_23 ( V_2 -> V_161 ) ) ;
if ( F_23 ( V_2 -> V_161 ) > F_231 ( V_2 -> V_76 ) )
F_159 ( L_60 ,
V_2 -> V_40 ) ;
F_232 (s, node, n) {
unsigned long V_109 ;
unsigned long V_240 ;
unsigned long V_241 ;
V_241 = F_226 ( V_34 , F_224 ) ;
V_109 = F_94 ( V_34 ) ;
V_240 = F_225 ( V_34 ) ;
F_159 ( L_61 ,
V_108 , V_109 , V_240 , V_241 ) ;
}
#endif
}
static inline void * F_233 ( struct V_1 * V_2 , T_7 V_3 ,
int V_108 , struct V_187 * * V_242 )
{
void * V_38 ;
struct V_187 * V_188 = * V_242 ;
struct V_23 * V_23 ;
V_38 = F_196 ( V_2 , V_3 , V_108 , V_188 ) ;
if ( V_38 )
return V_38 ;
V_23 = F_158 ( V_2 , V_3 , V_108 ) ;
if ( V_23 ) {
V_188 = F_234 ( V_2 -> V_10 ) ;
if ( V_188 -> V_23 )
F_217 ( V_2 , V_188 ) ;
V_38 = V_23 -> V_38 ;
V_23 -> V_38 = NULL ;
F_10 ( V_2 , V_243 ) ;
V_188 -> V_23 = V_23 ;
* V_242 = V_188 ;
} else
V_38 = NULL ;
return V_38 ;
}
static inline bool F_182 ( struct V_23 * V_23 , T_7 V_235 )
{
if ( F_3 ( F_235 ( V_23 ) ) )
return F_236 ( V_235 ) ;
return true ;
}
static inline void * F_237 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_23 V_186 ;
unsigned long V_27 ;
void * V_38 ;
do {
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_186 . V_27 = V_27 ;
F_33 ( ! V_186 . V_28 ) ;
V_186 . V_29 = V_23 -> V_30 ;
V_186 . V_28 = V_38 != NULL ;
} while ( ! F_32 ( V_2 , V_23 ,
V_38 , V_27 ,
NULL , V_186 . V_27 ,
L_62 ) );
return V_38 ;
}
static void * F_238 ( struct V_1 * V_2 , T_7 V_235 , int V_108 ,
unsigned long V_14 , struct V_187 * V_188 )
{
void * V_38 ;
struct V_23 * V_23 ;
V_23 = V_188 -> V_23 ;
if ( ! V_23 )
goto F_158;
V_220:
if ( F_3 ( ! F_223 ( V_23 , V_108 ) ) ) {
int V_203 = V_108 ;
if ( V_108 != V_141 && ! F_198 ( V_108 ) )
V_203 = F_199 ( V_108 ) ;
if ( F_3 ( ! F_223 ( V_23 , V_203 ) ) ) {
F_10 ( V_2 , V_244 ) ;
F_210 ( V_2 , V_23 , V_188 -> V_38 ) ;
V_188 -> V_23 = NULL ;
V_188 -> V_38 = NULL ;
goto F_158;
}
}
if ( F_3 ( ! F_182 ( V_23 , V_235 ) ) ) {
F_210 ( V_2 , V_23 , V_188 -> V_38 ) ;
V_188 -> V_23 = NULL ;
V_188 -> V_38 = NULL ;
goto F_158;
}
V_38 = V_188 -> V_38 ;
if ( V_38 )
goto V_245;
V_38 = F_237 ( V_2 , V_23 ) ;
if ( ! V_38 ) {
V_188 -> V_23 = NULL ;
F_10 ( V_2 , V_246 ) ;
goto F_158;
}
F_10 ( V_2 , V_247 ) ;
V_245:
F_33 ( ! V_188 -> V_23 -> V_28 ) ;
V_188 -> V_38 = F_13 ( V_2 , V_38 ) ;
V_188 -> V_204 = F_200 ( V_188 -> V_204 ) ;
return V_38 ;
F_158:
if ( V_188 -> V_184 ) {
V_23 = V_188 -> V_23 = V_188 -> V_184 ;
V_188 -> V_184 = V_23 -> V_152 ;
F_10 ( V_2 , V_248 ) ;
V_188 -> V_38 = NULL ;
goto V_220;
}
V_38 = F_233 ( V_2 , V_235 , V_108 , & V_188 ) ;
if ( F_3 ( ! V_38 ) ) {
F_228 ( V_2 , V_235 , V_108 ) ;
return NULL ;
}
V_23 = V_188 -> V_23 ;
if ( F_96 ( ! F_1 ( V_2 ) && F_182 ( V_23 , V_235 ) ) )
goto V_245;
if ( F_1 ( V_2 ) &&
! F_104 ( V_2 , V_23 , V_38 , V_14 ) )
goto F_158;
F_210 ( V_2 , V_23 , F_13 ( V_2 , V_38 ) ) ;
V_188 -> V_23 = NULL ;
V_188 -> V_38 = NULL ;
return V_38 ;
}
static void * F_239 ( struct V_1 * V_2 , T_7 V_235 , int V_108 ,
unsigned long V_14 , struct V_187 * V_188 )
{
void * V_5 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_206
V_188 = F_214 ( V_2 -> V_10 ) ;
#endif
V_5 = F_238 ( V_2 , V_235 , V_108 , V_14 , V_188 ) ;
F_42 ( V_3 ) ;
return V_5 ;
}
static T_1 void * F_240 ( struct V_1 * V_2 ,
T_7 V_235 , int V_108 , unsigned long V_14 )
{
void * V_11 ;
struct V_187 * V_188 ;
struct V_23 * V_23 ;
unsigned long V_204 ;
V_2 = F_241 ( V_2 , V_235 ) ;
if ( ! V_2 )
return NULL ;
V_220:
do {
V_204 = F_213 ( V_2 -> V_10 -> V_204 ) ;
V_188 = F_234 ( V_2 -> V_10 ) ;
} while ( F_242 ( F_206 ) &&
F_3 ( V_204 != F_243 ( V_188 -> V_204 ) ) );
F_244 () ;
V_11 = V_188 -> V_38 ;
V_23 = V_188 -> V_23 ;
if ( F_3 ( ! V_11 || ! F_223 ( V_23 , V_108 ) ) ) {
V_11 = F_239 ( V_2 , V_235 , V_108 , V_14 , V_188 ) ;
F_10 ( V_2 , V_249 ) ;
} else {
void * V_122 = F_16 ( V_2 , V_11 ) ;
if ( F_3 ( ! F_245 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_204 ,
V_11 , V_204 ,
V_122 , F_200 ( V_204 ) ) ) ) {
F_204 ( L_63 , V_2 , V_204 ) ;
goto V_220;
}
F_14 ( V_2 , V_122 ) ;
F_10 ( V_2 , V_250 ) ;
}
if ( F_3 ( V_235 & V_251 ) && V_11 )
memset ( V_11 , 0 , V_2 -> V_76 ) ;
F_246 ( V_2 , V_235 , 1 , & V_11 ) ;
return V_11 ;
}
static T_1 void * F_247 ( struct V_1 * V_2 ,
T_7 V_235 , unsigned long V_14 )
{
return F_240 ( V_2 , V_235 , V_141 , V_14 ) ;
}
void * F_248 ( struct V_1 * V_2 , T_7 V_235 )
{
void * V_120 = F_247 ( V_2 , V_235 , V_252 ) ;
F_249 ( V_252 , V_120 , V_2 -> V_76 ,
V_2 -> V_15 , V_235 ) ;
return V_120 ;
}
void * F_250 ( struct V_1 * V_2 , T_7 V_235 , T_6 V_15 )
{
void * V_120 = F_247 ( V_2 , V_235 , V_252 ) ;
F_251 ( V_252 , V_120 , V_15 , V_2 -> V_15 , V_235 ) ;
F_252 ( V_2 , V_120 , V_15 , V_235 ) ;
return V_120 ;
}
void * F_253 ( struct V_1 * V_2 , T_7 V_235 , int V_108 )
{
void * V_120 = F_240 ( V_2 , V_235 , V_108 , V_252 ) ;
F_254 ( V_252 , V_120 ,
V_2 -> V_76 , V_2 -> V_15 , V_235 , V_108 ) ;
return V_120 ;
}
void * F_255 ( struct V_1 * V_2 ,
T_7 V_235 ,
int V_108 , T_6 V_15 )
{
void * V_120 = F_240 ( V_2 , V_235 , V_108 , V_252 ) ;
F_256 ( V_252 , V_120 ,
V_15 , V_2 -> V_15 , V_235 , V_108 ) ;
F_252 ( V_2 , V_120 , V_15 , V_235 ) ;
return V_120 ;
}
static void F_257 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_118 ,
unsigned long V_14 )
{
void * V_219 ;
int V_253 ;
struct V_23 V_186 ;
unsigned long V_27 ;
struct V_104 * V_34 = NULL ;
unsigned long V_119 ( V_3 ) ;
F_10 ( V_2 , V_254 ) ;
if ( F_1 ( V_2 ) &&
! F_106 ( V_2 , V_23 , V_115 , V_116 , V_118 , V_14 ) )
return;
do {
if ( F_3 ( V_34 ) ) {
F_109 ( & V_34 -> V_105 , V_3 ) ;
V_34 = NULL ;
}
V_219 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_19 ( V_2 , V_116 , V_219 ) ;
V_186 . V_27 = V_27 ;
V_253 = V_186 . V_28 ;
V_186 . V_29 -= V_118 ;
if ( ( ! V_186 . V_29 || ! V_219 ) && ! V_253 ) {
if ( F_5 ( V_2 ) && ! V_219 ) {
V_186 . V_28 = 1 ;
} else {
V_34 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
}
}
} while ( ! F_40 ( V_2 , V_23 ,
V_219 , V_27 ,
V_115 , V_186 . V_27 ,
L_64 ) );
if ( F_96 ( ! V_34 ) ) {
if ( V_186 . V_28 && ! V_253 ) {
F_183 ( V_2 , V_23 , 1 ) ;
F_10 ( V_2 , V_255 ) ;
}
if ( V_253 )
F_10 ( V_2 , V_256 ) ;
return;
}
if ( F_3 ( ! V_186 . V_29 && V_34 -> V_182 >= V_2 -> V_202 ) )
goto V_257;
if ( ! F_5 ( V_2 ) && F_3 ( ! V_219 ) ) {
if ( F_1 ( V_2 ) )
F_89 ( V_2 , V_34 , V_23 ) ;
F_175 ( V_34 , V_23 , V_183 ) ;
F_10 ( V_2 , V_226 ) ;
}
F_109 ( & V_34 -> V_105 , V_3 ) ;
return;
V_257:
if ( V_219 ) {
F_176 ( V_34 , V_23 ) ;
F_10 ( V_2 , V_258 ) ;
} else {
F_89 ( V_2 , V_34 , V_23 ) ;
}
F_109 ( & V_34 -> V_105 , V_3 ) ;
F_10 ( V_2 , V_223 ) ;
F_172 ( V_2 , V_23 ) ;
}
static T_1 void F_258 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_115 , void * V_116 ,
int V_118 , unsigned long V_14 )
{
void * V_138 = V_116 ? : V_115 ;
struct V_187 * V_188 ;
unsigned long V_204 ;
V_220:
do {
V_204 = F_213 ( V_2 -> V_10 -> V_204 ) ;
V_188 = F_234 ( V_2 -> V_10 ) ;
} while ( F_242 ( F_206 ) &&
F_3 ( V_204 != F_243 ( V_188 -> V_204 ) ) );
F_244 () ;
if ( F_96 ( V_23 == V_188 -> V_23 ) ) {
F_19 ( V_2 , V_138 , V_188 -> V_38 ) ;
if ( F_3 ( ! F_245 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_204 ,
V_188 -> V_38 , V_204 ,
V_115 , F_200 ( V_204 ) ) ) ) {
F_204 ( L_65 , V_2 , V_204 ) ;
goto V_220;
}
F_10 ( V_2 , V_259 ) ;
} else
F_257 ( V_2 , V_23 , V_115 , V_138 , V_118 , V_14 ) ;
}
static T_1 void F_259 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_118 ,
unsigned long V_14 )
{
F_125 ( V_2 , V_115 , V_116 ) ;
if ( V_2 -> V_3 & V_260 && ! ( V_2 -> V_3 & V_181 ) )
return;
F_258 ( V_2 , V_23 , V_115 , V_116 , V_118 , V_14 ) ;
}
void F_260 ( struct V_1 * V_261 , void * V_20 , unsigned long V_14 )
{
F_258 ( V_261 , F_168 ( V_20 ) , V_20 , NULL , 1 , V_14 ) ;
}
void F_261 ( struct V_1 * V_2 , void * V_20 )
{
V_2 = F_262 ( V_2 , V_20 ) ;
if ( ! V_2 )
return;
F_259 ( V_2 , F_168 ( V_20 ) , V_20 , NULL , 1 , V_252 ) ;
F_263 ( V_252 , V_20 ) ;
}
static inline
int F_264 ( struct V_1 * V_2 , T_6 V_15 ,
void * * V_5 , struct V_262 * V_263 )
{
T_6 V_264 = 0 ;
int V_265 = 3 ;
void * V_11 ;
struct V_23 * V_23 ;
V_263 -> V_23 = NULL ;
do {
V_11 = V_5 [ -- V_15 ] ;
} while ( ! V_11 && V_15 );
if ( ! V_11 )
return 0 ;
V_23 = F_168 ( V_11 ) ;
if ( ! V_2 ) {
if ( F_3 ( ! F_84 ( V_23 ) ) ) {
F_265 ( ! F_266 ( V_23 ) ) ;
F_116 ( V_11 ) ;
F_134 ( V_23 , F_81 ( V_23 ) ) ;
V_5 [ V_15 ] = NULL ;
return V_15 ;
}
V_263 -> V_2 = V_23 -> V_114 ;
} else {
V_263 -> V_2 = F_262 ( V_2 , V_11 ) ;
}
V_263 -> V_23 = V_23 ;
F_19 ( V_263 -> V_2 , V_11 , NULL ) ;
V_263 -> V_116 = V_11 ;
V_263 -> V_38 = V_11 ;
V_5 [ V_15 ] = NULL ;
V_263 -> V_118 = 1 ;
while ( V_15 ) {
V_11 = V_5 [ -- V_15 ] ;
if ( ! V_11 )
continue;
if ( V_263 -> V_23 == F_168 ( V_11 ) ) {
F_19 ( V_263 -> V_2 , V_11 , V_263 -> V_38 ) ;
V_263 -> V_38 = V_11 ;
V_263 -> V_118 ++ ;
V_5 [ V_15 ] = NULL ;
continue;
}
if ( ! -- V_265 )
break;
if ( ! V_264 )
V_264 = V_15 + 1 ;
}
return V_264 ;
}
void F_267 ( struct V_1 * V_2 , T_6 V_15 , void * * V_5 )
{
if ( F_178 ( ! V_15 ) )
return;
do {
struct V_262 V_263 ;
V_15 = F_264 ( V_2 , V_15 , V_5 , & V_263 ) ;
if ( F_3 ( ! V_263 . V_23 ) )
continue;
F_259 ( V_263 . V_2 , V_263 . V_23 , V_263 . V_38 , V_263 . V_116 , V_263 . V_118 , V_252 ) ;
} while ( F_96 ( V_15 ) );
}
int F_268 ( struct V_1 * V_2 , T_7 V_3 , T_6 V_15 ,
void * * V_5 )
{
struct V_187 * V_188 ;
int V_52 ;
V_2 = F_241 ( V_2 , V_3 ) ;
if ( F_3 ( ! V_2 ) )
return false ;
F_155 () ;
V_188 = F_214 ( V_2 -> V_10 ) ;
for ( V_52 = 0 ; V_52 < V_15 ; V_52 ++ ) {
void * V_11 = V_188 -> V_38 ;
if ( F_3 ( ! V_11 ) ) {
V_5 [ V_52 ] = F_238 ( V_2 , V_3 , V_141 ,
V_252 , V_188 ) ;
if ( F_3 ( ! V_5 [ V_52 ] ) )
goto error;
V_188 = F_214 ( V_2 -> V_10 ) ;
continue;
}
V_188 -> V_38 = F_13 ( V_2 , V_11 ) ;
V_5 [ V_52 ] = V_11 ;
}
V_188 -> V_204 = F_200 ( V_188 -> V_204 ) ;
F_146 () ;
if ( F_3 ( V_3 & V_251 ) ) {
int V_266 ;
for ( V_266 = 0 ; V_266 < V_52 ; V_266 ++ )
memset ( V_5 [ V_266 ] , 0 , V_2 -> V_76 ) ;
}
F_246 ( V_2 , V_3 , V_15 , V_5 ) ;
return V_52 ;
error:
F_146 () ;
F_246 ( V_2 , V_3 , V_52 , V_5 ) ;
F_269 ( V_2 , V_52 , V_5 ) ;
return 0 ;
}
static inline int F_270 ( int V_15 , int V_267 ,
int V_268 , int V_269 , int V_17 )
{
int V_16 ;
int V_270 ;
int V_271 = V_272 ;
if ( F_21 ( V_271 , V_15 , V_17 ) > V_102 )
return F_231 ( V_15 * V_102 ) - 1 ;
for ( V_16 = F_271 ( V_271 , F_231 ( V_267 * V_15 + V_17 ) ) ;
V_16 <= V_268 ; V_16 ++ ) {
unsigned long V_273 = V_18 << V_16 ;
V_270 = ( V_273 - V_17 ) % V_15 ;
if ( V_270 <= V_273 / V_269 )
break;
}
return V_16 ;
}
static inline int F_272 ( int V_15 , int V_17 )
{
int V_16 ;
int V_267 ;
int V_274 ;
int V_101 ;
V_267 = V_275 ;
if ( ! V_267 )
V_267 = 4 * ( F_273 ( V_276 ) + 1 ) ;
V_101 = F_21 ( V_277 , V_15 , V_17 ) ;
V_267 = V_161 ( V_267 , V_101 ) ;
while ( V_267 > 1 ) {
V_274 = 16 ;
while ( V_274 >= 4 ) {
V_16 = F_270 ( V_15 , V_267 ,
V_277 , V_274 , V_17 ) ;
if ( V_16 <= V_277 )
return V_16 ;
V_274 /= 2 ;
}
V_267 -- ;
}
V_16 = F_270 ( V_15 , 1 , V_277 , 1 , V_17 ) ;
if ( V_16 <= V_277 )
return V_16 ;
V_16 = F_270 ( V_15 , 1 , V_278 , 1 , V_17 ) ;
if ( V_16 < V_278 )
return V_16 ;
return - V_279 ;
}
static void
F_274 ( struct V_104 * V_34 )
{
V_34 -> V_182 = 0 ;
F_275 ( & V_34 -> V_105 ) ;
F_276 ( & V_34 -> V_184 ) ;
#ifdef F_2
F_277 ( & V_34 -> V_109 , 0 ) ;
F_277 ( & V_34 -> V_110 , 0 ) ;
F_276 ( & V_34 -> V_107 ) ;
#endif
}
static inline int F_278 ( struct V_1 * V_2 )
{
F_279 ( V_280 <
V_281 * sizeof( struct V_187 ) ) ;
V_2 -> V_10 = F_280 ( sizeof( struct V_187 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_10 )
return 0 ;
F_207 ( V_2 ) ;
return 1 ;
}
static void F_281 ( int V_108 )
{
struct V_23 * V_23 ;
struct V_104 * V_34 ;
F_265 ( V_104 -> V_15 < sizeof( struct V_104 ) ) ;
V_23 = F_158 ( V_104 , V_282 , V_108 ) ;
F_265 ( ! V_23 ) ;
if ( F_107 ( V_23 ) != V_108 ) {
F_62 ( L_66 , V_108 ) ;
F_62 ( L_67 ) ;
}
V_34 = V_23 -> V_38 ;
F_265 ( ! V_34 ) ;
V_23 -> V_38 = F_13 ( V_104 , V_34 ) ;
V_23 -> V_29 = 1 ;
V_23 -> V_28 = 0 ;
V_104 -> V_108 [ V_108 ] = V_34 ;
#ifdef F_2
F_75 ( V_104 , V_34 , V_97 ) ;
F_60 ( V_104 , V_34 ) ;
#endif
F_252 ( V_104 , V_34 , sizeof( struct V_104 ) ,
V_144 ) ;
F_274 ( V_34 ) ;
F_95 ( V_104 , V_108 , V_23 -> V_30 ) ;
F_173 ( V_34 , V_23 , V_216 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_34 ;
F_232 (s, node, n) {
F_261 ( V_104 , V_34 ) ;
V_2 -> V_108 [ V_108 ] = NULL ;
}
}
void F_283 ( struct V_1 * V_2 )
{
F_284 ( V_2 ) ;
F_285 ( V_2 -> V_10 ) ;
F_282 ( V_2 ) ;
}
static int F_286 ( struct V_1 * V_2 )
{
int V_108 ;
F_287 (node, N_NORMAL_MEMORY) {
struct V_104 * V_34 ;
if ( V_283 == V_284 ) {
F_281 ( V_108 ) ;
continue;
}
V_34 = F_253 ( V_104 ,
V_144 , V_108 ) ;
if ( ! V_34 ) {
F_282 ( V_2 ) ;
return 0 ;
}
V_2 -> V_108 [ V_108 ] = V_34 ;
F_274 ( V_34 ) ;
}
return 1 ;
}
static void F_288 ( struct V_1 * V_2 , unsigned long V_161 )
{
if ( V_161 < V_285 )
V_161 = V_285 ;
else if ( V_161 > V_286 )
V_161 = V_286 ;
V_2 -> V_202 = V_161 ;
}
static int F_289 ( struct V_1 * V_2 , int V_287 )
{
unsigned long V_3 = V_2 -> V_3 ;
T_6 V_15 = V_2 -> V_76 ;
int V_16 ;
V_15 = F_290 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_95 ) && ! ( V_3 & V_181 ) &&
! V_2 -> F_112 )
V_2 -> V_3 |= V_80 ;
else
V_2 -> V_3 &= ~ V_80 ;
if ( ( V_3 & V_6 ) && V_15 == V_2 -> V_76 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_29 = V_15 ;
if ( ( ( V_3 & ( V_181 | V_95 ) ) ||
V_2 -> F_112 ) ) {
V_2 -> V_12 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_65 )
V_15 += 2 * sizeof( struct V_47 ) ;
#endif
F_291 ( V_2 , & V_15 , & V_2 -> V_3 ) ;
#ifdef F_2
if ( V_3 & V_6 ) {
V_15 += sizeof( void * ) ;
V_2 -> V_7 = sizeof( void * ) ;
V_2 -> V_7 = F_290 ( V_2 -> V_7 , V_2 -> V_288 ) ;
V_15 += V_2 -> V_7 ;
}
#endif
V_15 = F_290 ( V_15 , V_2 -> V_288 ) ;
V_2 -> V_15 = V_15 ;
if ( V_287 >= 0 )
V_16 = V_287 ;
else
V_16 = F_272 ( V_15 , V_2 -> V_17 ) ;
if ( V_16 < 0 )
return 0 ;
V_2 -> V_156 = 0 ;
if ( V_16 )
V_2 -> V_156 |= V_289 ;
if ( V_2 -> V_3 & V_290 )
V_2 -> V_156 |= V_291 ;
if ( V_2 -> V_3 & V_168 )
V_2 -> V_156 |= V_292 ;
V_2 -> V_139 = F_22 ( V_16 , V_15 , V_2 -> V_17 ) ;
V_2 -> V_161 = F_22 ( F_231 ( V_15 ) , V_15 , V_2 -> V_17 ) ;
if ( F_24 ( V_2 -> V_139 ) > F_24 ( V_2 -> F_271 ) )
V_2 -> F_271 = V_2 -> V_139 ;
return ! ! F_24 ( V_2 -> V_139 ) ;
}
static int F_292 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_111 ( V_2 -> V_15 , V_3 , V_2 -> V_40 , V_2 -> F_112 ) ;
V_2 -> V_17 = 0 ;
if ( V_179 && ( V_2 -> V_3 & V_181 ) )
V_2 -> V_17 = sizeof( struct V_177 ) ;
if ( ! F_289 ( V_2 , - 1 ) )
goto error;
if ( V_128 ) {
if ( F_231 ( V_2 -> V_15 ) > F_231 ( V_2 -> V_76 ) ) {
V_2 -> V_3 &= ~ V_293 ;
V_2 -> V_12 = 0 ;
if ( ! F_289 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_35 ) && \
F_35 ( V_36 )
if ( F_293 () && ( V_2 -> V_3 & V_294 ) == 0 )
V_2 -> V_3 |= V_37 ;
#endif
F_288 ( V_2 , F_294 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_193 = 0 ;
else if ( V_2 -> V_15 >= V_18 )
V_2 -> V_193 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_193 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_193 = 13 ;
else
V_2 -> V_193 = 30 ;
#ifdef F_186
V_2 -> V_201 = 1000 ;
#endif
if ( V_283 >= V_295 ) {
if ( F_135 ( V_2 ) )
goto error;
}
if ( ! F_286 ( V_2 ) )
goto error;
if ( F_278 ( V_2 ) )
return 0 ;
F_282 ( V_2 ) ;
error:
if ( V_3 & V_296 )
F_295 ( L_68 ,
V_2 -> V_40 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_23 ( V_2 -> V_139 ) , V_2 -> V_12 , V_3 ) ;
return - V_297 ;
}
static void F_296 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_43 )
{
#ifdef F_2
void * V_14 = F_44 ( V_23 ) ;
void * V_5 ;
unsigned long * V_41 = F_297 ( F_298 ( V_23 -> V_30 ) *
sizeof( long ) , V_234 ) ;
if ( ! V_41 )
return;
F_74 ( V_2 , V_23 , V_43 , V_2 -> V_40 ) ;
F_25 ( V_23 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects) {
if ( ! F_299 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) ) {
F_62 ( L_69 , V_5 , V_5 - V_14 ) ;
F_63 ( V_2 , V_5 ) ;
}
}
F_29 ( V_23 ) ;
F_300 ( V_41 ) ;
#endif
}
static void F_301 ( struct V_1 * V_2 , struct V_104 * V_34 )
{
F_302 ( V_298 ) ;
struct V_23 * V_23 , * V_178 ;
F_265 ( F_34 () ) ;
F_303 ( & V_34 -> V_105 ) ;
F_181 (page, h, &n->partial, lru) {
if ( ! V_23 -> V_29 ) {
F_176 ( V_34 , V_23 ) ;
F_88 ( & V_23 -> V_106 , & V_298 ) ;
} else {
F_296 ( V_2 , V_23 ,
L_70 ) ;
}
}
F_304 ( & V_34 -> V_105 ) ;
F_181 (page, h, &discard, lru)
F_172 ( V_2 , V_23 ) ;
}
int F_305 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_34 ;
F_221 ( V_2 ) ;
F_232 (s, node, n) {
F_301 ( V_2 , V_34 ) ;
if ( V_34 -> V_182 || F_91 ( V_2 , V_108 ) )
return 1 ;
}
return 0 ;
}
static int T_5 F_306 ( char * V_123 )
{
F_307 ( & V_123 , & V_272 ) ;
return 1 ;
}
static int T_5 F_308 ( char * V_123 )
{
F_307 ( & V_123 , & V_277 ) ;
V_277 = V_161 ( V_277 , V_278 - 1 ) ;
return 1 ;
}
static int T_5 F_309 ( char * V_123 )
{
F_307 ( & V_123 , & V_275 ) ;
return 1 ;
}
void * F_310 ( T_6 V_15 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_299 ) )
return F_311 ( V_15 , V_3 ) ;
V_2 = F_312 ( V_15 , V_3 ) ;
if ( F_3 ( F_313 ( V_2 ) ) )
return V_2 ;
V_120 = F_247 ( V_2 , V_3 , V_252 ) ;
F_251 ( V_252 , V_120 , V_15 , V_2 -> V_15 , V_3 ) ;
F_252 ( V_2 , V_120 , V_15 , V_3 ) ;
return V_120 ;
}
static void * F_314 ( T_6 V_15 , T_7 V_3 , int V_108 )
{
struct V_23 * V_23 ;
void * V_130 = NULL ;
V_3 |= V_289 | V_140 ;
V_23 = F_315 ( V_108 , V_3 , F_231 ( V_15 ) ) ;
if ( V_23 )
V_130 = F_44 ( V_23 ) ;
F_113 ( V_130 , V_15 , V_3 ) ;
return V_130 ;
}
void * F_316 ( T_6 V_15 , T_7 V_3 , int V_108 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_299 ) ) {
V_120 = F_314 ( V_15 , V_3 , V_108 ) ;
F_256 ( V_252 , V_120 ,
V_15 , V_18 << F_231 ( V_15 ) ,
V_3 , V_108 ) ;
return V_120 ;
}
V_2 = F_312 ( V_15 , V_3 ) ;
if ( F_3 ( F_313 ( V_2 ) ) )
return V_2 ;
V_120 = F_240 ( V_2 , V_3 , V_108 , V_252 ) ;
F_256 ( V_252 , V_120 , V_15 , V_2 -> V_15 , V_3 , V_108 ) ;
F_252 ( V_2 , V_120 , V_15 , V_3 ) ;
return V_120 ;
}
const char * F_317 ( const void * V_130 , unsigned long V_34 ,
struct V_23 * V_23 )
{
struct V_1 * V_2 ;
unsigned long V_12 ;
T_6 V_76 ;
V_2 = V_23 -> V_114 ;
V_76 = F_318 ( V_2 ) ;
if ( V_130 < F_44 ( V_23 ) )
return V_2 -> V_40 ;
V_12 = ( V_130 - F_44 ( V_23 ) ) % V_2 -> V_15 ;
if ( F_1 ( V_2 ) && V_2 -> V_3 & V_6 ) {
if ( V_12 < V_2 -> V_7 )
return V_2 -> V_40 ;
V_12 -= V_2 -> V_7 ;
}
if ( V_12 <= V_76 && V_34 <= V_76 - V_12 )
return NULL ;
return V_2 -> V_40 ;
}
static T_6 F_319 ( const void * V_11 )
{
struct V_23 * V_23 ;
if ( F_3 ( V_11 == V_300 ) )
return 0 ;
V_23 = F_168 ( V_11 ) ;
if ( F_3 ( ! F_84 ( V_23 ) ) ) {
F_178 ( ! F_266 ( V_23 ) ) ;
return V_18 << F_81 ( V_23 ) ;
}
return F_318 ( V_23 -> V_114 ) ;
}
T_6 F_320 ( const void * V_11 )
{
T_6 V_15 = F_319 ( V_11 ) ;
F_321 ( V_11 , V_15 ) ;
return V_15 ;
}
void F_300 ( const void * V_20 )
{
struct V_23 * V_23 ;
void * V_11 = ( void * ) V_20 ;
F_322 ( V_252 , V_20 ) ;
if ( F_3 ( F_313 ( V_20 ) ) )
return;
V_23 = F_168 ( V_20 ) ;
if ( F_3 ( ! F_84 ( V_23 ) ) ) {
F_265 ( ! F_266 ( V_23 ) ) ;
F_116 ( V_20 ) ;
F_134 ( V_23 , F_81 ( V_23 ) ) ;
return;
}
F_259 ( V_23 -> V_114 , V_23 , V_11 , NULL , 1 , V_252 ) ;
}
int F_323 ( struct V_1 * V_2 , bool V_301 )
{
int V_108 ;
int V_52 ;
struct V_104 * V_34 ;
struct V_23 * V_23 ;
struct V_23 * V_68 ;
struct V_180 V_298 ;
struct V_180 V_302 [ V_303 ] ;
unsigned long V_3 ;
int V_120 = 0 ;
if ( V_301 ) {
V_2 -> V_193 = 0 ;
V_2 -> V_202 = 0 ;
F_324 () ;
}
F_221 ( V_2 ) ;
F_232 (s, node, n) {
F_276 ( & V_298 ) ;
for ( V_52 = 0 ; V_52 < V_303 ; V_52 ++ )
F_276 ( V_302 + V_52 ) ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_181 (page, t, &n->partial, lru) {
int free = V_23 -> V_30 - V_23 -> V_29 ;
F_244 () ;
F_265 ( free <= 0 ) ;
if ( free == V_23 -> V_30 ) {
F_325 ( & V_23 -> V_106 , & V_298 ) ;
V_34 -> V_182 -- ;
} else if ( free <= V_303 )
F_325 ( & V_23 -> V_106 , V_302 + free - 1 ) ;
}
for ( V_52 = V_303 - 1 ; V_52 >= 0 ; V_52 -- )
F_326 ( V_302 + V_52 , & V_34 -> V_184 ) ;
F_109 ( & V_34 -> V_105 , V_3 ) ;
F_181 (page, t, &discard, lru)
F_172 ( V_2 , V_23 ) ;
if ( F_91 ( V_2 , V_108 ) )
V_120 = 1 ;
}
return V_120 ;
}
static int F_327 ( void * V_304 )
{
struct V_1 * V_2 ;
F_138 ( & V_146 ) ;
F_139 (s, &slab_caches, list)
F_323 ( V_2 , false ) ;
F_140 ( & V_146 ) ;
return 0 ;
}
static void F_328 ( void * V_304 )
{
struct V_104 * V_34 ;
struct V_1 * V_2 ;
struct V_305 * V_306 = V_304 ;
int V_307 ;
V_307 = V_306 -> V_308 ;
if ( V_307 < 0 )
return;
F_138 ( & V_146 ) ;
F_139 (s, &slab_caches, list) {
V_34 = F_92 ( V_2 , V_307 ) ;
if ( V_34 ) {
F_265 ( F_91 ( V_2 , V_307 ) ) ;
V_2 -> V_108 [ V_307 ] = NULL ;
F_261 ( V_104 , V_34 ) ;
}
}
F_140 ( & V_146 ) ;
}
static int F_329 ( void * V_304 )
{
struct V_104 * V_34 ;
struct V_1 * V_2 ;
struct V_305 * V_306 = V_304 ;
int V_236 = V_306 -> V_308 ;
int V_120 = 0 ;
if ( V_236 < 0 )
return 0 ;
F_138 ( & V_146 ) ;
F_139 (s, &slab_caches, list) {
V_34 = F_248 ( V_104 , V_144 ) ;
if ( ! V_34 ) {
V_120 = - V_309 ;
goto V_121;
}
F_274 ( V_34 ) ;
V_2 -> V_108 [ V_236 ] = V_34 ;
}
V_121:
F_140 ( & V_146 ) ;
return V_120 ;
}
static int F_330 ( struct V_310 * V_311 ,
unsigned long V_312 , void * V_304 )
{
int V_120 = 0 ;
switch ( V_312 ) {
case V_313 :
V_120 = F_329 ( V_304 ) ;
break;
case V_314 :
V_120 = F_327 ( V_304 ) ;
break;
case V_315 :
case V_316 :
F_328 ( V_304 ) ;
break;
case V_317 :
case V_318 :
break;
}
if ( V_120 )
V_120 = F_331 ( V_120 ) ;
else
V_120 = V_319 ;
return V_120 ;
}
static struct V_1 * T_5 F_332 ( struct V_1 * V_320 )
{
int V_108 ;
struct V_1 * V_2 = F_333 ( V_1 , V_282 ) ;
struct V_104 * V_34 ;
memcpy ( V_2 , V_320 , V_1 -> V_76 ) ;
F_218 ( V_2 , F_59 () ) ;
F_232 (s, node, n) {
struct V_23 * V_5 ;
F_139 (p, &n->partial, lru)
V_5 -> V_114 = V_2 ;
#ifdef F_2
F_139 (p, &n->full, lru)
V_5 -> V_114 = V_2 ;
#endif
}
F_334 ( V_2 ) ;
F_88 ( & V_2 -> V_321 , & V_322 ) ;
return V_2 ;
}
void T_5 F_335 ( void )
{
static V_323 struct V_1 V_324 ,
V_325 ;
if ( F_336 () )
V_277 = 0 ;
V_104 = & V_325 ;
V_1 = & V_324 ;
F_337 ( V_104 , L_71 ,
sizeof( struct V_104 ) , V_326 ) ;
F_338 ( & V_327 ) ;
V_283 = V_328 ;
F_337 ( V_1 , L_72 ,
F_339 ( struct V_1 , V_108 ) +
V_329 * sizeof( struct V_104 * ) ,
V_326 ) ;
V_1 = F_332 ( & V_324 ) ;
V_104 = F_332 ( & V_325 ) ;
F_340 () ;
F_341 ( 0 ) ;
F_137 () ;
#ifdef F_342
F_343 ( & V_330 ) ;
#endif
F_39 ( L_73 ,
F_344 () ,
V_272 , V_277 , V_275 ,
V_276 , V_329 ) ;
}
void T_5 F_345 ( void )
{
}
struct V_1 *
F_346 ( const char * V_40 , T_6 V_15 , T_6 V_288 ,
unsigned long V_3 , void (* F_112)( void * ) )
{
struct V_1 * V_2 , * V_188 ;
V_2 = F_347 ( V_15 , V_288 , V_3 , V_40 , F_112 ) ;
if ( V_2 ) {
V_2 -> V_331 ++ ;
V_2 -> V_76 = F_271 ( V_2 -> V_76 , ( int ) V_15 ) ;
V_2 -> V_29 = F_348 ( int , V_2 -> V_29 , F_290 ( V_15 , sizeof( void * ) ) ) ;
F_349 (c, s) {
V_188 -> V_76 = V_2 -> V_76 ;
V_188 -> V_29 = F_348 ( int , V_188 -> V_29 ,
F_290 ( V_15 , sizeof( void * ) ) ) ;
}
if ( F_8 ( V_2 , V_40 ) ) {
V_2 -> V_331 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_350 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_142 ;
V_142 = F_292 ( V_2 , V_3 ) ;
if ( V_142 )
return V_142 ;
if ( V_283 <= V_295 )
return 0 ;
F_9 ( V_2 ) ;
V_142 = F_7 ( V_2 ) ;
if ( V_142 )
F_283 ( V_2 ) ;
return V_142 ;
}
static int F_351 ( struct V_310 * V_332 ,
unsigned long V_312 , void * V_333 )
{
long V_60 = ( long ) V_333 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_312 ) {
case V_334 :
case V_335 :
case V_336 :
case V_337 :
F_138 ( & V_146 ) ;
F_139 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_218 ( V_2 , V_60 ) ;
F_42 ( V_3 ) ;
}
F_140 ( & V_146 ) ;
break;
default:
break;
}
return V_319 ;
}
void * F_352 ( T_6 V_15 , T_7 V_235 , unsigned long V_338 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_299 ) )
return F_311 ( V_15 , V_235 ) ;
V_2 = F_312 ( V_15 , V_235 ) ;
if ( F_3 ( F_313 ( V_2 ) ) )
return V_2 ;
V_120 = F_247 ( V_2 , V_235 , V_338 ) ;
F_251 ( V_338 , V_120 , V_15 , V_2 -> V_15 , V_235 ) ;
return V_120 ;
}
void * F_353 ( T_6 V_15 , T_7 V_235 ,
int V_108 , unsigned long V_338 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_299 ) ) {
V_120 = F_314 ( V_15 , V_235 , V_108 ) ;
F_256 ( V_338 , V_120 ,
V_15 , V_18 << F_231 ( V_15 ) ,
V_235 , V_108 ) ;
return V_120 ;
}
V_2 = F_312 ( V_15 , V_235 ) ;
if ( F_3 ( F_313 ( V_2 ) ) )
return V_2 ;
V_120 = F_240 ( V_2 , V_235 , V_108 , V_338 ) ;
F_256 ( V_338 , V_120 , V_15 , V_2 -> V_15 , V_235 , V_108 ) ;
return V_120 ;
}
static int F_354 ( struct V_23 * V_23 )
{
return V_23 -> V_29 ;
}
static int F_355 ( struct V_23 * V_23 )
{
return V_23 -> V_30 ;
}
static int F_356 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
void * V_5 ;
void * V_14 = F_44 ( V_23 ) ;
if ( ! F_83 ( V_2 , V_23 ) ||
! F_85 ( V_2 , V_23 , NULL ) )
return 0 ;
F_357 ( V_41 , V_23 -> V_30 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects) {
if ( F_299 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_82 ( V_2 , V_23 , V_5 , V_111 ) )
return 0 ;
}
F_161 (p, s, addr, page->objects)
if ( ! F_299 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_82 ( V_2 , V_23 , V_5 , V_97 ) )
return 0 ;
return 1 ;
}
static void F_358 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
F_25 ( V_23 ) ;
F_356 ( V_2 , V_23 , V_41 ) ;
F_29 ( V_23 ) ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_104 * V_34 , unsigned long * V_41 )
{
unsigned long V_143 = 0 ;
struct V_23 * V_23 ;
unsigned long V_3 ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_139 (page, &n->partial, lru) {
F_358 ( V_2 , V_23 , V_41 ) ;
V_143 ++ ;
}
if ( V_143 != V_34 -> V_182 )
F_62 ( L_74 ,
V_2 -> V_40 , V_143 , V_34 -> V_182 ) ;
if ( ! ( V_2 -> V_3 & V_65 ) )
goto V_121;
F_139 (page, &n->full, lru) {
F_358 ( V_2 , V_23 , V_41 ) ;
V_143 ++ ;
}
if ( V_143 != F_93 ( & V_34 -> V_109 ) )
F_62 ( L_75 ,
V_2 -> V_40 , V_143 , F_93 ( & V_34 -> V_109 ) ) ;
V_121:
F_109 ( & V_34 -> V_105 , V_3 ) ;
return V_143 ;
}
static long F_360 ( struct V_1 * V_2 )
{
int V_108 ;
unsigned long V_143 = 0 ;
unsigned long * V_41 = F_361 ( F_298 ( F_24 ( V_2 -> F_271 ) ) *
sizeof( unsigned long ) , V_144 ) ;
struct V_104 * V_34 ;
if ( ! V_41 )
return - V_309 ;
F_221 ( V_2 ) ;
F_232 (s, node, n)
V_143 += F_359 ( V_2 , V_34 , V_41 ) ;
F_300 ( V_41 ) ;
return V_143 ;
}
static void F_362 ( struct V_339 * V_68 )
{
if ( V_68 -> F_271 )
F_363 ( ( unsigned long ) V_68 -> V_340 ,
F_231 ( sizeof( struct V_341 ) * V_68 -> F_271 ) ) ;
}
static int F_364 ( struct V_339 * V_68 , unsigned long F_271 , T_7 V_3 )
{
struct V_341 * V_213 ;
int V_16 ;
V_16 = F_231 ( sizeof( struct V_341 ) * F_271 ) ;
V_213 = ( void * ) F_365 ( V_3 , V_16 ) ;
if ( ! V_213 )
return 0 ;
if ( V_68 -> V_143 ) {
memcpy ( V_213 , V_68 -> V_340 , sizeof( struct V_341 ) * V_68 -> V_143 ) ;
F_362 ( V_68 ) ;
}
V_68 -> F_271 = F_271 ;
V_68 -> V_340 = V_213 ;
return 1 ;
}
static int F_366 ( struct V_339 * V_68 , struct V_1 * V_2 ,
const struct V_47 * V_47 )
{
long V_88 , V_92 , V_147 ;
struct V_341 * V_213 ;
unsigned long V_342 ;
unsigned long V_343 = V_64 - V_47 -> V_63 ;
V_88 = - 1 ;
V_92 = V_68 -> V_143 ;
for ( ; ; ) {
V_147 = V_88 + ( V_92 - V_88 + 1 ) / 2 ;
if ( V_147 == V_92 )
break;
V_342 = V_68 -> V_340 [ V_147 ] . V_14 ;
if ( V_47 -> V_14 == V_342 ) {
V_213 = & V_68 -> V_340 [ V_147 ] ;
V_213 -> V_143 ++ ;
if ( V_47 -> V_63 ) {
V_213 -> V_344 += V_343 ;
if ( V_343 < V_213 -> V_345 )
V_213 -> V_345 = V_343 ;
if ( V_343 > V_213 -> V_346 )
V_213 -> V_346 = V_343 ;
if ( V_47 -> V_61 < V_213 -> V_347 )
V_213 -> V_347 = V_47 -> V_61 ;
if ( V_47 -> V_61 > V_213 -> V_348 )
V_213 -> V_348 = V_47 -> V_61 ;
F_367 ( V_47 -> V_60 ,
F_368 ( V_213 -> V_349 ) ) ;
}
F_369 ( F_107 ( F_370 ( V_47 ) ) , V_213 -> V_350 ) ;
return 1 ;
}
if ( V_47 -> V_14 < V_342 )
V_92 = V_147 ;
else
V_88 = V_147 ;
}
if ( V_68 -> V_143 >= V_68 -> F_271 && ! F_364 ( V_68 , 2 * V_68 -> F_271 , V_234 ) )
return 0 ;
V_213 = V_68 -> V_340 + V_147 ;
if ( V_147 < V_68 -> V_143 )
memmove ( V_213 + 1 , V_213 ,
( V_68 -> V_143 - V_147 ) * sizeof( struct V_341 ) ) ;
V_68 -> V_143 ++ ;
V_213 -> V_143 = 1 ;
V_213 -> V_14 = V_47 -> V_14 ;
V_213 -> V_344 = V_343 ;
V_213 -> V_345 = V_343 ;
V_213 -> V_346 = V_343 ;
V_213 -> V_347 = V_47 -> V_61 ;
V_213 -> V_348 = V_47 -> V_61 ;
F_371 ( F_368 ( V_213 -> V_349 ) ) ;
F_367 ( V_47 -> V_60 , F_368 ( V_213 -> V_349 ) ) ;
F_372 ( V_213 -> V_350 ) ;
F_369 ( F_107 ( F_370 ( V_47 ) ) , V_213 -> V_350 ) ;
return 1 ;
}
static void F_373 ( struct V_339 * V_68 , struct V_1 * V_2 ,
struct V_23 * V_23 , enum V_48 V_49 ,
unsigned long * V_41 )
{
void * V_14 = F_44 ( V_23 ) ;
void * V_5 ;
F_357 ( V_41 , V_23 -> V_30 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects)
if ( ! F_299 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
F_366 ( V_68 , V_2 , F_55 ( V_2 , V_5 , V_49 ) ) ;
}
static int F_374 ( struct V_1 * V_2 , char * V_78 ,
enum V_48 V_49 )
{
int V_351 = 0 ;
unsigned long V_52 ;
struct V_339 V_68 = { 0 , 0 , NULL } ;
int V_108 ;
unsigned long * V_41 = F_361 ( F_298 ( F_24 ( V_2 -> F_271 ) ) *
sizeof( unsigned long ) , V_144 ) ;
struct V_104 * V_34 ;
if ( ! V_41 || ! F_364 ( & V_68 , V_18 / sizeof( struct V_341 ) ,
V_352 ) ) {
F_300 ( V_41 ) ;
return sprintf ( V_78 , L_76 ) ;
}
F_221 ( V_2 ) ;
F_232 (s, node, n) {
unsigned long V_3 ;
struct V_23 * V_23 ;
if ( ! F_93 ( & V_34 -> V_109 ) )
continue;
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_139 (page, &n->partial, lru)
F_373 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_139 (page, &n->full, lru)
F_373 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_109 ( & V_34 -> V_105 , V_3 ) ;
}
for ( V_52 = 0 ; V_52 < V_68 . V_143 ; V_52 ++ ) {
struct V_341 * V_213 = & V_68 . V_340 [ V_52 ] ;
if ( V_351 > V_18 - V_353 - 100 )
break;
V_351 += sprintf ( V_78 + V_351 , L_77 , V_213 -> V_143 ) ;
if ( V_213 -> V_14 )
V_351 += sprintf ( V_78 + V_351 , L_78 , ( void * ) V_213 -> V_14 ) ;
else
V_351 += sprintf ( V_78 + V_351 , L_79 ) ;
if ( V_213 -> V_344 != V_213 -> V_345 ) {
V_351 += sprintf ( V_78 + V_351 , L_80 ,
V_213 -> V_345 ,
( long ) F_375 ( V_213 -> V_344 , V_213 -> V_143 ) ,
V_213 -> V_346 ) ;
} else
V_351 += sprintf ( V_78 + V_351 , L_81 ,
V_213 -> V_345 ) ;
if ( V_213 -> V_347 != V_213 -> V_348 )
V_351 += sprintf ( V_78 + V_351 , L_82 ,
V_213 -> V_347 , V_213 -> V_348 ) ;
else
V_351 += sprintf ( V_78 + V_351 , L_83 ,
V_213 -> V_347 ) ;
if ( F_376 () > 1 &&
! F_377 ( F_368 ( V_213 -> V_349 ) ) &&
V_351 < V_18 - 60 )
V_351 += F_378 ( V_78 + V_351 , V_18 - V_351 - 50 ,
L_84 ,
F_379 ( F_368 ( V_213 -> V_349 ) ) ) ;
if ( V_354 > 1 && ! F_380 ( V_213 -> V_350 ) &&
V_351 < V_18 - 60 )
V_351 += F_378 ( V_78 + V_351 , V_18 - V_351 - 50 ,
L_85 ,
F_381 ( & V_213 -> V_350 ) ) ;
V_351 += sprintf ( V_78 + V_351 , L_86 ) ;
}
F_362 ( & V_68 ) ;
F_300 ( V_41 ) ;
if ( ! V_68 . V_143 )
V_351 += sprintf ( V_78 , L_87 ) ;
return V_351 ;
}
static void T_5 F_382 ( void )
{
T_2 * V_5 ;
F_279 ( V_355 > 16 || V_281 < 10 ) ;
F_62 ( L_88 ) ;
F_62 ( L_89 ) ;
F_62 ( L_90 ) ;
V_5 = F_297 ( 16 , V_144 ) ;
V_5 [ 16 ] = 0x12 ;
F_62 ( L_91 ,
V_5 + 16 ) ;
F_360 ( V_356 [ 4 ] ) ;
V_5 = F_297 ( 32 , V_144 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_62 ( L_92 ,
V_5 ) ;
F_62 ( L_93 ) ;
F_360 ( V_356 [ 5 ] ) ;
V_5 = F_297 ( 64 , V_144 ) ;
V_5 += 64 + ( F_188 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_62 ( L_94 ,
V_5 ) ;
F_62 ( L_93 ) ;
F_360 ( V_356 [ 6 ] ) ;
F_62 ( L_95 ) ;
V_5 = F_297 ( 128 , V_144 ) ;
F_300 ( V_5 ) ;
* V_5 = 0x78 ;
F_62 ( L_96 , V_5 ) ;
F_360 ( V_356 [ 7 ] ) ;
V_5 = F_297 ( 256 , V_144 ) ;
F_300 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_62 ( L_97 , V_5 ) ;
F_360 ( V_356 [ 8 ] ) ;
V_5 = F_297 ( 512 , V_144 ) ;
F_300 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_62 ( L_98 , V_5 ) ;
F_360 ( V_356 [ 9 ] ) ;
}
static void F_382 ( void ) {}
static T_9 F_383 ( struct V_1 * V_2 ,
char * V_78 , unsigned long V_3 )
{
unsigned long V_357 = 0 ;
int V_108 ;
int V_20 ;
unsigned long * V_350 ;
V_350 = F_297 ( sizeof( unsigned long ) * V_329 , V_144 ) ;
if ( ! V_350 )
return - V_309 ;
if ( V_3 & V_358 ) {
int V_60 ;
F_208 (cpu) {
struct V_187 * V_188 = F_209 ( V_2 -> V_10 ,
V_60 ) ;
int V_108 ;
struct V_23 * V_23 ;
V_23 = F_243 ( V_188 -> V_23 ) ;
if ( ! V_23 )
continue;
V_108 = F_107 ( V_23 ) ;
if ( V_3 & V_359 )
V_20 = V_23 -> V_30 ;
else if ( V_3 & V_360 )
V_20 = V_23 -> V_29 ;
else
V_20 = 1 ;
V_357 += V_20 ;
V_350 [ V_108 ] += V_20 ;
V_23 = F_243 ( V_188 -> V_184 ) ;
if ( V_23 ) {
V_108 = F_107 ( V_23 ) ;
if ( V_3 & V_359 )
F_384 ( 1 ) ;
else if ( V_3 & V_360 )
F_384 ( 1 ) ;
else
V_20 = V_23 -> V_167 ;
V_357 += V_20 ;
V_350 [ V_108 ] += V_20 ;
}
}
}
F_385 () ;
#ifdef F_2
if ( V_3 & V_361 ) {
struct V_104 * V_34 ;
F_232 (s, node, n) {
if ( V_3 & V_359 )
V_20 = F_93 ( & V_34 -> V_110 ) ;
else if ( V_3 & V_360 )
V_20 = F_93 ( & V_34 -> V_110 ) -
F_226 ( V_34 , F_224 ) ;
else
V_20 = F_93 ( & V_34 -> V_109 ) ;
V_357 += V_20 ;
V_350 [ V_108 ] += V_20 ;
}
} else
#endif
if ( V_3 & V_362 ) {
struct V_104 * V_34 ;
F_232 (s, node, n) {
if ( V_3 & V_359 )
V_20 = F_226 ( V_34 , F_355 ) ;
else if ( V_3 & V_360 )
V_20 = F_226 ( V_34 , F_354 ) ;
else
V_20 = V_34 -> V_182 ;
V_357 += V_20 ;
V_350 [ V_108 ] += V_20 ;
}
}
V_20 = sprintf ( V_78 , L_99 , V_357 ) ;
#ifdef F_186
for ( V_108 = 0 ; V_108 < V_329 ; V_108 ++ )
if ( V_350 [ V_108 ] )
V_20 += sprintf ( V_78 + V_20 , L_100 ,
V_108 , V_350 [ V_108 ] ) ;
#endif
F_386 () ;
F_300 ( V_350 ) ;
return V_20 + sprintf ( V_78 + V_20 , L_86 ) ;
}
static int F_387 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_34 ;
F_232 (s, node, n)
if ( F_93 ( & V_34 -> V_110 ) )
return 1 ;
return 0 ;
}
static T_9 F_388 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_15 ) ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_288 ) ;
}
static T_9 F_390 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_76 ) ;
}
static T_9 F_391 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , F_24 ( V_2 -> V_139 ) ) ;
}
static T_9 F_392 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
unsigned long V_16 ;
int V_142 ;
V_142 = F_393 ( V_78 , 10 , & V_16 ) ;
if ( V_142 )
return V_142 ;
if ( V_16 > V_277 || V_16 < V_272 )
return - V_297 ;
F_289 ( V_2 , V_16 ) ;
return V_44 ;
}
static T_9 F_394 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , F_23 ( V_2 -> V_139 ) ) ;
}
static T_9 F_395 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_102 , V_2 -> V_202 ) ;
}
static T_9 F_396 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
unsigned long V_161 ;
int V_142 ;
V_142 = F_393 ( V_78 , 10 , & V_161 ) ;
if ( V_142 )
return V_142 ;
F_288 ( V_2 , V_161 ) ;
return V_44 ;
}
static T_9 F_397 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_103 , V_2 -> V_193 ) ;
}
static T_9 F_398 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
unsigned long V_30 ;
int V_142 ;
V_142 = F_393 ( V_78 , 10 , & V_30 ) ;
if ( V_142 )
return V_142 ;
if ( V_30 && ! F_5 ( V_2 ) )
return - V_297 ;
V_2 -> V_193 = V_30 ;
F_221 ( V_2 ) ;
return V_44 ;
}
static T_9 F_399 ( struct V_1 * V_2 , char * V_78 )
{
if ( ! V_2 -> F_112 )
return 0 ;
return sprintf ( V_78 , L_104 , V_2 -> F_112 ) ;
}
static T_9 F_400 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_331 < 0 ? 0 : V_2 -> V_331 - 1 ) ;
}
static T_9 F_401 ( struct V_1 * V_2 , char * V_78 )
{
return F_383 ( V_2 , V_78 , V_362 ) ;
}
static T_9 F_402 ( struct V_1 * V_2 , char * V_78 )
{
return F_383 ( V_2 , V_78 , V_358 ) ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_78 )
{
return F_383 ( V_2 , V_78 , V_361 | V_360 ) ;
}
static T_9 F_404 ( struct V_1 * V_2 , char * V_78 )
{
return F_383 ( V_2 , V_78 , V_362 | V_360 ) ;
}
static T_9 F_405 ( struct V_1 * V_2 , char * V_78 )
{
int V_30 = 0 ;
int V_167 = 0 ;
int V_60 ;
int V_351 ;
F_406 (cpu) {
struct V_23 * V_23 = F_209 ( V_2 -> V_10 , V_60 ) -> V_184 ;
if ( V_23 ) {
V_167 += V_23 -> V_167 ;
V_30 += V_23 -> V_229 ;
}
}
V_351 = sprintf ( V_78 , L_105 , V_30 , V_167 ) ;
#ifdef F_342
F_406 (cpu) {
struct V_23 * V_23 = F_209 ( V_2 -> V_10 , V_60 ) -> V_184 ;
if ( V_23 && V_351 < V_18 - 20 )
V_351 += sprintf ( V_78 + V_351 , L_106 , V_60 ,
V_23 -> V_229 , V_23 -> V_167 ) ;
}
#endif
return V_351 + sprintf ( V_78 + V_351 , L_86 ) ;
}
static T_9 F_407 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_168 ) ) ;
}
static T_9 F_408 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
V_2 -> V_3 &= ~ V_168 ;
if ( V_78 [ 0 ] == '1' )
V_2 -> V_3 |= V_168 ;
return V_44 ;
}
static T_9 F_409 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_326 ) ) ;
}
static T_9 F_410 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_290 ) ) ;
}
static T_9 F_411 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_181 ) ) ;
}
static T_9 F_412 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_17 ) ;
}
static T_9 F_413 ( struct V_1 * V_2 , char * V_78 )
{
return F_383 ( V_2 , V_78 , V_361 ) ;
}
static T_9 F_414 ( struct V_1 * V_2 , char * V_78 )
{
return F_383 ( V_2 , V_78 , V_361 | V_359 ) ;
}
static T_9 F_415 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_112 ) ) ;
}
static T_9 F_416 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
V_2 -> V_3 &= ~ V_112 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_112 ;
}
return V_44 ;
}
static T_9 F_417 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_103 ) ) ;
}
static T_9 F_418 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
if ( V_2 -> V_331 > 1 )
return - V_297 ;
V_2 -> V_3 &= ~ V_103 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_103 ;
}
return V_44 ;
}
static T_9 F_419 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_6 ) ) ;
}
static T_9 F_420 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( F_387 ( V_2 ) )
return - V_363 ;
V_2 -> V_3 &= ~ V_6 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_6 ;
}
F_289 ( V_2 , - 1 ) ;
return V_44 ;
}
static T_9 F_421 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_95 ) ) ;
}
static T_9 F_422 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( F_387 ( V_2 ) )
return - V_363 ;
V_2 -> V_3 &= ~ V_95 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_95 ;
}
F_289 ( V_2 , - 1 ) ;
return V_44 ;
}
static T_9 F_423 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_65 ) ) ;
}
static T_9 F_424 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( F_387 ( V_2 ) )
return - V_363 ;
V_2 -> V_3 &= ~ V_65 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_65 ;
}
F_289 ( V_2 , - 1 ) ;
return V_44 ;
}
static T_9 F_425 ( struct V_1 * V_2 , char * V_78 )
{
return 0 ;
}
static T_9 F_426 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
int V_120 = - V_297 ;
if ( V_78 [ 0 ] == '1' ) {
V_120 = F_360 ( V_2 ) ;
if ( V_120 >= 0 )
V_120 = V_44 ;
}
return V_120 ;
}
static T_9 F_427 ( struct V_1 * V_2 , char * V_78 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_279 ;
return F_374 ( V_2 , V_78 , V_67 ) ;
}
static T_9 F_428 ( struct V_1 * V_2 , char * V_78 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_279 ;
return F_374 ( V_2 , V_78 , V_66 ) ;
}
static T_9 F_429 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , ! ! ( V_2 -> V_3 & V_127 ) ) ;
}
static T_9 F_430 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
if ( V_2 -> V_331 > 1 )
return - V_297 ;
V_2 -> V_3 &= ~ V_127 ;
if ( V_78 [ 0 ] == '1' )
V_2 -> V_3 |= V_127 ;
return V_44 ;
}
static T_9 F_431 ( struct V_1 * V_2 , char * V_78 )
{
return 0 ;
}
static T_9 F_432 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( V_78 [ 0 ] == '1' )
F_433 ( V_2 ) ;
else
return - V_297 ;
return V_44 ;
}
static T_9 F_434 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_201 / 10 ) ;
}
static T_9 F_435 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
unsigned long V_364 ;
int V_142 ;
V_142 = F_393 ( V_78 , 10 , & V_364 ) ;
if ( V_142 )
return V_142 ;
if ( V_364 <= 100 )
V_2 -> V_201 = V_364 * 10 ;
return V_44 ;
}
static int F_436 ( struct V_1 * V_2 , char * V_78 , enum V_8 V_9 )
{
unsigned long V_365 = 0 ;
int V_60 ;
int V_351 ;
int * V_84 = F_361 ( V_276 * sizeof( int ) , V_144 ) ;
if ( ! V_84 )
return - V_309 ;
F_406 (cpu) {
unsigned V_20 = F_209 ( V_2 -> V_10 , V_60 ) -> F_10 [ V_9 ] ;
V_84 [ V_60 ] = V_20 ;
V_365 += V_20 ;
}
V_351 = sprintf ( V_78 , L_99 , V_365 ) ;
#ifdef F_342
F_406 (cpu) {
if ( V_84 [ V_60 ] && V_351 < V_18 - 20 )
V_351 += sprintf ( V_78 + V_351 , L_107 , V_60 , V_84 [ V_60 ] ) ;
}
#endif
F_300 ( V_84 ) ;
return V_351 + sprintf ( V_78 + V_351 , L_86 ) ;
}
static void F_437 ( struct V_1 * V_2 , enum V_8 V_9 )
{
int V_60 ;
F_406 (cpu)
F_209 ( V_2 -> V_10 , V_60 ) -> F_10 [ V_9 ] = 0 ;
}
static T_9 F_438 ( struct V_366 * V_367 ,
struct V_368 * V_369 ,
char * V_78 )
{
struct V_370 * V_368 ;
struct V_1 * V_2 ;
int V_142 ;
V_368 = F_439 ( V_369 ) ;
V_2 = F_440 ( V_367 ) ;
if ( ! V_368 -> V_371 )
return - V_372 ;
V_142 = V_368 -> V_371 ( V_2 , V_78 ) ;
return V_142 ;
}
static T_9 F_441 ( struct V_366 * V_367 ,
struct V_368 * V_369 ,
const char * V_78 , T_6 V_351 )
{
struct V_370 * V_368 ;
struct V_1 * V_2 ;
int V_142 ;
V_368 = F_439 ( V_369 ) ;
V_2 = F_440 ( V_367 ) ;
if ( ! V_368 -> V_373 )
return - V_372 ;
V_142 = V_368 -> V_373 ( V_2 , V_78 , V_351 ) ;
#ifdef F_442
if ( V_283 >= V_374 && V_142 >= 0 && F_443 ( V_2 ) ) {
struct V_1 * V_188 ;
F_138 ( & V_146 ) ;
if ( V_2 -> V_375 < V_351 )
V_2 -> V_375 = V_351 ;
F_349 (c, s)
V_368 -> V_373 ( V_188 , V_78 , V_351 ) ;
F_140 ( & V_146 ) ;
}
#endif
return V_142 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_442
int V_52 ;
char * V_376 = NULL ;
struct V_1 * V_377 ;
if ( F_443 ( V_2 ) )
return;
V_377 = V_2 -> V_378 . V_377 ;
if ( ! V_377 -> V_375 )
return;
for ( V_52 = 0 ; V_52 < F_444 ( V_379 ) ; V_52 ++ ) {
char V_380 [ 64 ] ;
char * V_78 ;
struct V_370 * V_369 = F_439 ( V_379 [ V_52 ] ) ;
if ( ! V_369 || ! V_369 -> V_373 || ! V_369 -> V_371 )
continue;
if ( V_376 )
V_78 = V_376 ;
else if ( V_377 -> V_375 < F_444 ( V_380 ) )
V_78 = V_380 ;
else {
V_376 = ( char * ) F_445 ( V_144 ) ;
if ( F_178 ( ! V_376 ) )
continue;
V_78 = V_376 ;
}
V_369 -> V_371 ( V_377 , V_78 ) ;
V_369 -> V_373 ( V_2 , V_78 , strlen ( V_78 ) ) ;
}
if ( V_376 )
F_446 ( ( unsigned long ) V_376 ) ;
#endif
}
static void F_447 ( struct V_366 * V_381 )
{
F_448 ( F_440 ( V_381 ) ) ;
}
static int F_449 ( struct V_382 * V_382 , struct V_366 * V_367 )
{
struct V_383 * V_384 = F_450 ( V_367 ) ;
if ( V_384 == & V_385 )
return 1 ;
return 0 ;
}
static inline struct V_382 * F_451 ( struct V_1 * V_2 )
{
#ifdef F_442
if ( ! F_443 ( V_2 ) )
return V_2 -> V_378 . V_377 -> V_386 ;
#endif
return V_387 ;
}
static char * F_452 ( struct V_1 * V_2 )
{
char * V_40 = F_361 ( V_388 , V_144 ) ;
char * V_5 = V_40 ;
F_265 ( ! V_40 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_290 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_168 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_112 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_166 ) )
* V_5 ++ = 't' ;
if ( V_2 -> V_3 & V_389 )
* V_5 ++ = 'A' ;
if ( V_5 != V_40 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_108 , V_2 -> V_15 ) ;
F_265 ( V_5 > V_40 + V_388 - 1 ) ;
return V_40 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_142 ;
const char * V_40 ;
int V_390 = F_453 ( V_2 ) ;
if ( V_390 ) {
F_454 ( & V_387 -> V_367 , V_2 -> V_40 ) ;
V_40 = V_2 -> V_40 ;
} else {
V_40 = F_452 ( V_2 ) ;
}
V_2 -> V_367 . V_382 = F_451 ( V_2 ) ;
V_142 = F_455 ( & V_2 -> V_367 , & V_385 , NULL , L_16 , V_40 ) ;
if ( V_142 )
goto V_121;
V_142 = F_456 ( & V_2 -> V_367 , & V_391 ) ;
if ( V_142 )
goto V_392;
#ifdef F_442
if ( F_443 ( V_2 ) ) {
V_2 -> V_386 = F_457 ( L_109 , NULL , & V_2 -> V_367 ) ;
if ( ! V_2 -> V_386 ) {
V_142 = - V_309 ;
goto V_392;
}
}
#endif
F_458 ( & V_2 -> V_367 , V_393 ) ;
if ( ! V_390 ) {
F_8 ( V_2 , V_2 -> V_40 ) ;
}
V_121:
if ( ! V_390 )
F_300 ( V_40 ) ;
return V_142 ;
V_392:
F_459 ( & V_2 -> V_367 ) ;
goto V_121;
}
void F_460 ( struct V_1 * V_2 )
{
if ( V_283 < V_374 )
return;
#ifdef F_442
F_461 ( V_2 -> V_386 ) ;
#endif
F_458 ( & V_2 -> V_367 , V_394 ) ;
F_459 ( & V_2 -> V_367 ) ;
F_462 ( & V_2 -> V_367 ) ;
}
static int F_8 ( struct V_1 * V_2 , const char * V_40 )
{
struct V_395 * V_396 ;
if ( V_283 == V_374 ) {
F_454 ( & V_387 -> V_367 , V_40 ) ;
return F_463 ( & V_387 -> V_367 , & V_2 -> V_367 , V_40 ) ;
}
V_396 = F_361 ( sizeof( struct V_395 ) , V_144 ) ;
if ( ! V_396 )
return - V_309 ;
V_396 -> V_2 = V_2 ;
V_396 -> V_40 = V_40 ;
V_396 -> V_152 = V_397 ;
V_397 = V_396 ;
return 0 ;
}
static int T_5 F_464 ( void )
{
struct V_1 * V_2 ;
int V_142 ;
F_138 ( & V_146 ) ;
V_387 = F_457 ( L_110 , & V_398 , V_399 ) ;
if ( ! V_387 ) {
F_140 ( & V_146 ) ;
F_62 ( L_111 ) ;
return - V_279 ;
}
V_283 = V_374 ;
F_139 (s, &slab_caches, list) {
V_142 = F_7 ( V_2 ) ;
if ( V_142 )
F_62 ( L_112 ,
V_2 -> V_40 ) ;
}
while ( V_397 ) {
struct V_395 * V_396 = V_397 ;
V_397 = V_397 -> V_152 ;
V_142 = F_8 ( V_396 -> V_2 , V_396 -> V_40 ) ;
if ( V_142 )
F_62 ( L_113 ,
V_396 -> V_40 ) ;
F_300 ( V_396 ) ;
}
F_140 ( & V_146 ) ;
F_382 () ;
return 0 ;
}
void F_465 ( struct V_1 * V_2 , struct V_400 * V_401 )
{
unsigned long V_109 = 0 ;
unsigned long V_240 = 0 ;
unsigned long V_241 = 0 ;
int V_108 ;
struct V_104 * V_34 ;
F_232 (s, node, n) {
V_109 += F_94 ( V_34 ) ;
V_240 += F_225 ( V_34 ) ;
V_241 += F_226 ( V_34 , F_224 ) ;
}
V_401 -> V_402 = V_240 - V_241 ;
V_401 -> V_403 = V_240 ;
V_401 -> V_404 = V_109 ;
V_401 -> V_405 = V_109 ;
V_401 -> V_406 = F_24 ( V_2 -> V_139 ) ;
V_401 -> V_407 = F_23 ( V_2 -> V_139 ) ;
}
void F_466 ( struct V_408 * V_214 , struct V_1 * V_2 )
{
}
T_9 F_467 ( struct V_409 * V_409 , const char T_10 * V_376 ,
T_6 V_143 , T_11 * V_410 )
{
return - V_372 ;
}
