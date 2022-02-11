static inline int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return F_3 ( V_2 -> V_3 & V_4 ) ;
#else
return 0 ;
#endif
}
static inline void * F_4 ( struct V_1 * V_2 , void * V_5 )
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
if ( V_75 != F_46 ( V_2 ) )
F_53 ( L_15 , V_5 + V_75 , F_46 ( V_2 ) - V_75 ) ;
F_71 () ;
}
void F_72 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_77 )
{
F_65 ( V_2 , L_16 , V_77 ) ;
F_69 ( V_2 , V_23 , V_11 ) ;
}
static void F_73 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_69 , ... )
{
T_3 args ;
char V_78 [ 100 ] ;
va_start ( args , V_69 ) ;
vsnprintf ( V_78 , sizeof( V_78 ) , V_69 , args ) ;
va_end ( args ) ;
F_65 ( V_2 , L_16 , V_78 ) ;
F_64 ( V_23 ) ;
F_71 () ;
}
static void F_74 ( struct V_1 * V_2 , void * V_11 , T_2 V_79 )
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
static void F_75 ( struct V_1 * V_2 , char * V_83 , T_2 V_84 ,
void * V_85 , void * V_86 )
{
F_68 ( V_2 , L_17 , V_85 , V_86 - 1 , V_84 ) ;
memset ( V_85 , V_84 , V_86 - V_85 ) ;
}
static int F_76 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_87 ,
T_2 * V_88 , unsigned int V_89 , unsigned int V_90 )
{
T_2 * V_91 ;
T_2 * V_92 ;
F_48 () ;
V_91 = F_77 ( V_88 , V_89 , V_90 ) ;
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
F_75 ( V_2 , V_87 , V_89 , V_91 , V_92 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_23 * V_23 , T_2 * V_5 )
{
unsigned long V_75 = V_2 -> V_29 ;
if ( V_2 -> V_12 )
V_75 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_65 )
V_75 += 2 * sizeof( struct V_47 ) ;
if ( F_46 ( V_2 ) == V_75 )
return 1 ;
return F_76 ( V_2 , V_23 , V_5 , L_20 ,
V_5 + V_75 , V_93 , F_46 ( V_2 ) - V_75 ) ;
}
static int F_79 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
T_2 * V_88 ;
T_2 * V_91 ;
T_2 * V_92 ;
int V_44 ;
int V_94 ;
if ( ! ( V_2 -> V_3 & V_95 ) )
return 1 ;
V_88 = F_44 ( V_23 ) ;
V_44 = ( V_18 << F_80 ( V_23 ) ) - V_2 -> V_17 ;
V_92 = V_88 + V_44 ;
V_94 = V_44 % V_2 -> V_15 ;
if ( ! V_94 )
return 1 ;
F_48 () ;
V_91 = F_77 ( V_92 - V_94 , V_93 , V_94 ) ;
F_50 () ;
if ( ! V_91 )
return 1 ;
while ( V_92 > V_91 && V_92 [ - 1 ] == V_93 )
V_92 -- ;
F_73 ( V_2 , V_23 , L_21 , V_91 , V_92 - 1 ) ;
F_53 ( L_15 , V_92 - V_94 , V_94 ) ;
F_75 ( V_2 , L_22 , V_93 , V_92 - V_94 , V_92 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_79 )
{
T_2 * V_5 = V_11 ;
T_2 * V_96 = V_11 + V_2 -> V_76 ;
if ( V_2 -> V_3 & V_6 ) {
if ( ! F_76 ( V_2 , V_23 , V_11 , L_23 ,
V_11 - V_2 -> V_7 , V_79 , V_2 -> V_7 ) )
return 0 ;
if ( ! F_76 ( V_2 , V_23 , V_11 , L_23 ,
V_96 , V_79 , V_2 -> V_29 - V_2 -> V_76 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_95 ) && V_2 -> V_76 < V_2 -> V_29 ) {
F_76 ( V_2 , V_23 , V_5 , L_24 ,
V_96 , V_93 ,
V_2 -> V_29 - V_2 -> V_76 ) ;
}
}
if ( V_2 -> V_3 & V_95 ) {
if ( V_79 != V_97 && ( V_2 -> V_3 & V_80 ) &&
( ! F_76 ( V_2 , V_23 , V_5 , L_25 , V_5 ,
V_81 , V_2 -> V_76 - 1 ) ||
! F_76 ( V_2 , V_23 , V_5 , L_25 ,
V_5 + V_2 -> V_76 - 1 , V_82 , 1 ) ) )
return 0 ;
F_78 ( V_2 , V_23 , V_5 ) ;
}
if ( ! V_2 -> V_12 && V_79 == V_97 )
return 1 ;
if ( ! F_52 ( V_2 , V_23 , F_13 ( V_2 , V_5 ) ) ) {
F_72 ( V_2 , V_23 , V_5 , L_26 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_98 ;
F_33 ( ! F_34 () ) ;
if ( ! F_83 ( V_23 ) ) {
F_73 ( V_2 , V_23 , L_27 ) ;
return 0 ;
}
V_98 = F_21 ( F_80 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_23 -> V_30 > V_98 ) {
F_73 ( V_2 , V_23 , L_28 ,
V_23 -> V_30 , V_98 ) ;
return 0 ;
}
if ( V_23 -> V_29 > V_23 -> V_30 ) {
F_73 ( V_2 , V_23 , L_29 ,
V_23 -> V_29 , V_23 -> V_30 ) ;
return 0 ;
}
F_79 ( V_2 , V_23 ) ;
return 1 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_99 )
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
F_72 ( V_2 , V_23 , V_11 ,
L_30 ) ;
F_19 ( V_2 , V_11 , NULL ) ;
} else {
F_73 ( V_2 , V_23 , L_26 ) ;
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
V_101 = F_21 ( F_80 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_101 > V_102 )
V_101 = V_102 ;
if ( V_23 -> V_30 != V_101 ) {
F_73 ( V_2 , V_23 , L_32 ,
V_23 -> V_30 , V_101 ) ;
V_23 -> V_30 = V_101 ;
F_68 ( V_2 , L_33 ) ;
}
if ( V_23 -> V_29 != V_23 -> V_30 - V_100 ) {
F_73 ( V_2 , V_23 , L_34 ,
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
F_71 () ;
}
}
static void F_85 ( struct V_1 * V_2 ,
struct V_104 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_86 ( & V_34 -> V_105 ) ;
F_87 ( & V_23 -> V_106 , & V_34 -> V_107 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_104 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_86 ( & V_34 -> V_105 ) ;
F_89 ( & V_23 -> V_106 ) ;
}
static inline unsigned long F_90 ( struct V_1 * V_2 , int V_108 )
{
struct V_104 * V_34 = F_91 ( V_2 , V_108 ) ;
return F_92 ( & V_34 -> V_109 ) ;
}
static inline unsigned long F_93 ( struct V_104 * V_34 )
{
return F_92 ( & V_34 -> V_109 ) ;
}
static inline void F_94 ( struct V_1 * V_2 , int V_108 , int V_30 )
{
struct V_104 * V_34 = F_91 ( V_2 , V_108 ) ;
if ( F_95 ( V_34 ) ) {
F_96 ( & V_34 -> V_109 ) ;
F_97 ( V_30 , & V_34 -> V_110 ) ;
}
}
static inline void F_98 ( struct V_1 * V_2 , int V_108 , int V_30 )
{
struct V_104 * V_34 = F_91 ( V_2 , V_108 ) ;
F_99 ( & V_34 -> V_109 ) ;
F_100 ( V_30 , & V_34 -> V_110 ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
if ( ! ( V_2 -> V_3 & ( V_65 | V_6 | V_80 ) ) )
return;
F_74 ( V_2 , V_11 , V_111 ) ;
F_60 ( V_2 , V_11 ) ;
}
static inline int F_102 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( ! F_82 ( V_2 , V_23 ) )
return 0 ;
if ( ! F_52 ( V_2 , V_23 , V_11 ) ) {
F_72 ( V_2 , V_23 , V_11 , L_39 ) ;
return 0 ;
}
if ( ! F_81 ( V_2 , V_23 , V_11 , V_111 ) )
return 0 ;
return 1 ;
}
static T_4 int F_103 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( V_2 -> V_3 & V_112 ) {
if ( ! F_102 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_113;
}
if ( V_2 -> V_3 & V_65 )
F_56 ( V_2 , V_11 , V_67 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 1 ) ;
F_74 ( V_2 , V_11 , V_97 ) ;
return 1 ;
V_113:
if ( F_83 ( V_23 ) ) {
F_68 ( V_2 , L_40 ) ;
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_38 = NULL ;
}
return 0 ;
}
static inline int F_104 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 )
{
if ( ! F_52 ( V_2 , V_23 , V_11 ) ) {
F_73 ( V_2 , V_23 , L_41 , V_11 ) ;
return 0 ;
}
if ( F_84 ( V_2 , V_23 , V_11 ) ) {
F_72 ( V_2 , V_23 , V_11 , L_42 ) ;
return 0 ;
}
if ( ! F_81 ( V_2 , V_23 , V_11 , V_97 ) )
return 0 ;
if ( F_3 ( V_2 != V_23 -> V_114 ) ) {
if ( ! F_83 ( V_23 ) ) {
F_73 ( V_2 , V_23 , L_43 ,
V_11 ) ;
} else if ( ! V_23 -> V_114 ) {
F_62 ( L_44 ,
V_11 ) ;
F_71 () ;
} else
F_72 ( V_2 , V_23 , V_11 ,
L_45 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_105 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_117 ,
unsigned long V_14 )
{
struct V_104 * V_34 = F_91 ( V_2 , F_106 ( V_23 ) ) ;
void * V_11 = V_115 ;
int V_118 = 0 ;
unsigned long V_119 ( V_3 ) ;
int V_120 = 0 ;
F_107 ( & V_34 -> V_105 , V_3 ) ;
F_25 ( V_23 ) ;
if ( V_2 -> V_3 & V_112 ) {
if ( ! F_82 ( V_2 , V_23 ) )
goto V_121;
}
V_122:
V_118 ++ ;
if ( V_2 -> V_3 & V_112 ) {
if ( ! F_104 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_121;
}
if ( V_2 -> V_3 & V_65 )
F_56 ( V_2 , V_11 , V_66 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 0 ) ;
F_74 ( V_2 , V_11 , V_111 ) ;
if ( V_11 != V_116 ) {
V_11 = F_13 ( V_2 , V_11 ) ;
goto V_122;
}
V_120 = 1 ;
V_121:
if ( V_118 != V_117 )
F_73 ( V_2 , V_23 , L_46 ,
V_117 , V_118 ) ;
F_29 ( V_23 ) ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
if ( ! V_120 )
F_68 ( V_2 , L_47 , V_11 ) ;
return V_120 ;
}
static int T_5 F_109 ( char * V_123 )
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
unsigned long F_110 ( unsigned long V_76 ,
unsigned long V_3 , const char * V_40 ,
void (* F_111)( void * ) )
{
if ( V_124 && ( ! V_129 || ( V_40 &&
! strncmp ( V_129 , V_40 , strlen ( V_129 ) ) ) ) )
V_3 |= V_124 ;
return V_3 ;
}
static inline void F_101 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 ) {}
static inline int F_103 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 ) { return 0 ; }
static inline int F_105 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_117 ,
unsigned long V_14 ) { return 0 ; }
static inline int F_79 ( struct V_1 * V_2 , struct V_23 * V_23 )
{ return 1 ; }
static inline int F_81 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_79 ) { return 1 ; }
static inline void F_85 ( struct V_1 * V_2 , struct V_104 * V_34 ,
struct V_23 * V_23 ) {}
static inline void F_88 ( struct V_1 * V_2 , struct V_104 * V_34 ,
struct V_23 * V_23 ) {}
unsigned long F_110 ( unsigned long V_76 ,
unsigned long V_3 , const char * V_40 ,
void (* F_111)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_90 ( struct V_1 * V_2 , int V_108 )
{ return 0 ; }
static inline unsigned long F_93 ( struct V_104 * V_34 )
{ return 0 ; }
static inline void F_94 ( struct V_1 * V_2 , int V_108 ,
int V_30 ) {}
static inline void F_98 ( struct V_1 * V_2 , int V_108 ,
int V_30 ) {}
static inline void F_112 ( void * V_130 , T_6 V_15 , T_7 V_3 )
{
F_113 ( V_130 , V_15 , 1 , V_3 ) ;
F_114 ( V_130 , V_15 , V_3 ) ;
}
static inline void F_115 ( const void * V_20 )
{
F_116 ( V_20 ) ;
F_117 ( V_20 ) ;
}
static inline void F_118 ( struct V_1 * V_2 , void * V_20 )
{
F_119 ( V_20 , V_2 -> V_3 ) ;
#if F_35 ( V_131 ) || F_35 ( V_132 )
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_120 ( V_2 , V_20 , V_2 -> V_76 ) ;
F_121 ( V_20 , V_2 -> V_76 ) ;
F_42 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_133 ) )
F_122 ( V_20 , V_2 -> V_76 ) ;
F_123 ( V_2 , V_20 ) ;
}
static inline void F_124 ( struct V_1 * V_2 ,
void * V_115 , void * V_116 )
{
#if F_35 ( V_131 ) || \
F_35 ( V_132 ) || \
F_35 ( V_134 ) || \
F_35 ( V_135 ) || \
F_35 ( V_136 )
void * V_11 = V_115 ;
void * V_137 = V_116 ? : V_115 ;
do {
F_118 ( V_2 , V_11 ) ;
} while ( ( V_11 != V_137 ) &&
( V_11 = F_13 ( V_2 , V_11 ) ) );
#endif
}
static void F_125 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
F_101 ( V_2 , V_23 , V_11 ) ;
if ( F_3 ( V_2 -> F_111 ) ) {
F_126 ( V_2 , V_11 ) ;
V_2 -> F_111 ( V_11 ) ;
F_127 ( V_2 , V_11 ) ;
}
}
static inline struct V_23 * F_128 ( struct V_1 * V_2 ,
T_7 V_3 , int V_108 , struct V_19 V_138 )
{
struct V_23 * V_23 ;
int V_16 = F_23 ( V_138 ) ;
V_3 |= V_139 ;
if ( V_108 == V_140 )
V_23 = F_129 ( V_3 , V_16 ) ;
else
V_23 = F_130 ( V_108 , V_3 , V_16 ) ;
if ( V_23 && F_131 ( V_23 , V_3 , V_16 , V_2 ) ) {
F_132 ( V_23 , V_16 ) ;
V_23 = NULL ;
}
return V_23 ;
}
static struct V_23 * F_133 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
struct V_23 * V_23 ;
struct V_19 V_138 = V_2 -> V_138 ;
T_7 V_141 ;
void * V_88 , * V_5 ;
int V_142 , V_16 ;
V_3 &= V_143 ;
if ( F_134 ( V_3 ) )
F_135 () ;
V_3 |= V_2 -> V_144 ;
V_141 = ( V_3 | V_145 | V_146 ) & ~ V_147 ;
if ( ( V_141 & V_148 ) && F_23 ( V_138 ) > F_23 ( V_2 -> V_149 ) )
V_141 = ( V_141 | V_150 ) & ~ ( V_151 | V_147 ) ;
V_23 = F_128 ( V_2 , V_141 , V_108 , V_138 ) ;
if ( F_3 ( ! V_23 ) ) {
V_138 = V_2 -> V_149 ;
V_141 = V_3 ;
V_23 = F_128 ( V_2 , V_141 , V_108 , V_138 ) ;
if ( F_3 ( ! V_23 ) )
goto V_121;
F_10 ( V_2 , V_152 ) ;
}
if ( V_153 &&
! ( V_2 -> V_3 & ( V_154 | V_125 ) ) ) {
int V_155 = 1 << F_23 ( V_138 ) ;
F_136 ( V_23 , F_23 ( V_138 ) , V_141 , V_108 ) ;
if ( V_2 -> F_111 )
F_137 ( V_23 , V_155 ) ;
else
F_138 ( V_23 , V_155 ) ;
}
V_23 -> V_30 = F_24 ( V_138 ) ;
V_16 = F_80 ( V_23 ) ;
V_23 -> V_114 = V_2 ;
F_139 ( V_23 ) ;
if ( F_140 ( V_23 ) )
F_141 ( V_23 ) ;
V_88 = F_44 ( V_23 ) ;
if ( F_3 ( V_2 -> V_3 & V_95 ) )
memset ( V_88 , V_93 , V_18 << V_16 ) ;
F_142 ( V_23 ) ;
F_143 (p, idx, s, start, page->objects) {
F_125 ( V_2 , V_23 , V_5 ) ;
if ( F_95 ( V_142 < V_23 -> V_30 ) )
F_19 ( V_2 , V_5 , V_5 + V_2 -> V_15 ) ;
else
F_19 ( V_2 , V_5 , NULL ) ;
}
V_23 -> V_38 = F_4 ( V_2 , V_88 ) ;
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_28 = 1 ;
V_121:
if ( F_134 ( V_3 ) )
F_144 () ;
if ( ! V_23 )
return NULL ;
F_145 ( F_146 ( V_23 ) ,
( V_2 -> V_3 & V_156 ) ?
V_157 : V_158 ,
1 << F_23 ( V_138 ) ) ;
F_94 ( V_2 , F_106 ( V_23 ) , V_23 -> V_30 ) ;
return V_23 ;
}
static struct V_23 * F_147 ( struct V_1 * V_2 , T_7 V_3 , int V_108 )
{
if ( F_3 ( V_3 & V_159 ) ) {
F_148 ( L_49 , V_3 & V_159 ) ;
F_149 () ;
}
return F_133 ( V_2 ,
V_3 & ( V_160 | V_161 ) , V_108 ) ;
}
static void F_150 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_16 = F_80 ( V_23 ) ;
int V_155 = 1 << V_16 ;
if ( V_2 -> V_3 & V_112 ) {
void * V_5 ;
F_79 ( V_2 , V_23 ) ;
F_151 (p, s, page_address(page),
page->objects)
F_81 ( V_2 , V_23 , V_5 , V_111 ) ;
}
F_152 ( V_23 , F_80 ( V_23 ) ) ;
F_145 ( F_146 ( V_23 ) ,
( V_2 -> V_3 & V_156 ) ?
V_157 : V_158 ,
- V_155 ) ;
F_153 ( V_23 ) ;
F_154 ( V_23 ) ;
F_155 ( V_23 ) ;
if ( V_62 -> V_162 )
V_62 -> V_162 -> V_163 += V_155 ;
F_156 ( V_23 , V_16 , V_2 ) ;
F_132 ( V_23 , V_16 ) ;
}
static void F_157 ( struct V_164 * V_165 )
{
struct V_23 * V_23 ;
if ( V_166 )
V_23 = F_158 ( V_165 ) ;
else
V_23 = F_159 ( (struct V_167 * ) V_165 , struct V_23 , V_106 ) ;
F_150 ( V_23 -> V_114 , V_23 ) ;
}
static void F_160 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
if ( F_3 ( V_2 -> V_3 & V_168 ) ) {
struct V_164 * V_115 ;
if ( V_166 ) {
int V_16 = F_80 ( V_23 ) ;
int V_12 = ( V_18 << V_16 ) - V_2 -> V_17 ;
F_33 ( V_2 -> V_17 != sizeof( * V_115 ) ) ;
V_115 = F_44 ( V_23 ) + V_12 ;
} else {
V_115 = & V_23 -> V_164 ;
}
F_161 ( V_115 , F_157 ) ;
} else
F_150 ( V_2 , V_23 ) ;
}
static void F_162 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_98 ( V_2 , F_106 ( V_23 ) , V_23 -> V_30 ) ;
F_160 ( V_2 , V_23 ) ;
}
static inline void
F_163 ( struct V_104 * V_34 , struct V_23 * V_23 , int V_116 )
{
V_34 -> V_169 ++ ;
if ( V_116 == V_170 )
F_164 ( & V_23 -> V_106 , & V_34 -> V_171 ) ;
else
F_87 ( & V_23 -> V_106 , & V_34 -> V_171 ) ;
}
static inline void F_165 ( struct V_104 * V_34 ,
struct V_23 * V_23 , int V_116 )
{
F_86 ( & V_34 -> V_105 ) ;
F_163 ( V_34 , V_23 , V_116 ) ;
}
static inline void F_166 ( struct V_104 * V_34 ,
struct V_23 * V_23 )
{
F_86 ( & V_34 -> V_105 ) ;
F_89 ( & V_23 -> V_106 ) ;
V_34 -> V_169 -- ;
}
static inline void * F_167 ( struct V_1 * V_2 ,
struct V_104 * V_34 , struct V_23 * V_23 ,
int V_172 , int * V_30 )
{
void * V_38 ;
unsigned long V_27 ;
struct V_23 V_173 ;
F_86 ( & V_34 -> V_105 ) ;
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_173 . V_27 = V_27 ;
* V_30 = V_173 . V_30 - V_173 . V_29 ;
if ( V_172 ) {
V_173 . V_29 = V_23 -> V_30 ;
V_173 . V_38 = NULL ;
} else {
V_173 . V_38 = V_38 ;
}
F_33 ( V_173 . V_28 ) ;
V_173 . V_28 = 1 ;
if ( ! F_32 ( V_2 , V_23 ,
V_38 , V_27 ,
V_173 . V_38 , V_173 . V_27 ,
L_50 ) )
return NULL ;
F_166 ( V_34 , V_23 ) ;
F_168 ( ! V_38 ) ;
return V_38 ;
}
static void * F_169 ( struct V_1 * V_2 , struct V_104 * V_34 ,
struct V_174 * V_175 , T_7 V_3 )
{
struct V_23 * V_23 , * V_176 ;
void * V_11 = NULL ;
int V_177 = 0 ;
int V_30 ;
if ( ! V_34 || ! V_34 -> V_169 )
return NULL ;
F_170 ( & V_34 -> V_105 ) ;
F_171 (page, page2, &n->partial, lru) {
void * V_68 ;
if ( ! F_172 ( V_23 , V_3 ) )
continue;
V_68 = F_167 ( V_2 , V_34 , V_23 , V_11 == NULL , & V_30 ) ;
if ( ! V_68 )
break;
V_177 += V_30 ;
if ( ! V_11 ) {
V_175 -> V_23 = V_23 ;
F_10 ( V_2 , V_178 ) ;
V_11 = V_68 ;
} else {
F_173 ( V_2 , V_23 , 0 ) ;
F_10 ( V_2 , V_179 ) ;
}
if ( ! F_5 ( V_2 )
|| V_177 > V_2 -> V_180 / 2 )
break;
}
F_174 ( & V_34 -> V_105 ) ;
return V_11 ;
}
static void * F_175 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_174 * V_175 )
{
#ifdef F_176
struct V_181 * V_181 ;
struct V_182 * V_183 ;
struct V_184 * V_184 ;
enum V_185 V_186 = F_177 ( V_3 ) ;
void * V_11 ;
unsigned int V_187 ;
if ( ! V_2 -> V_188 ||
F_178 () % 1024 > V_2 -> V_188 )
return NULL ;
do {
V_187 = F_179 () ;
V_181 = F_180 ( F_181 () , V_3 ) ;
F_182 (zone, z, zonelist, high_zoneidx) {
struct V_104 * V_34 ;
V_34 = F_91 ( V_2 , F_183 ( V_184 ) ) ;
if ( V_34 && F_184 ( V_184 , V_3 ) &&
V_34 -> V_169 > V_2 -> V_189 ) {
V_11 = F_169 ( V_2 , V_34 , V_175 , V_3 ) ;
if ( V_11 ) {
return V_11 ;
}
}
}
} while ( F_185 ( V_187 ) );
#endif
return NULL ;
}
static void * F_186 ( struct V_1 * V_2 , T_7 V_3 , int V_108 ,
struct V_174 * V_175 )
{
void * V_11 ;
int V_190 = V_108 ;
if ( V_108 == V_140 )
V_190 = F_187 () ;
else if ( ! F_188 ( V_108 ) )
V_190 = F_189 ( V_108 ) ;
V_11 = F_169 ( V_2 , F_91 ( V_2 , V_190 ) , V_175 , V_3 ) ;
if ( V_11 || V_108 != V_140 )
return V_11 ;
return F_175 ( V_2 , V_3 , V_175 ) ;
}
static inline unsigned long F_190 ( unsigned long V_191 )
{
return V_191 + V_192 ;
}
static inline unsigned int F_191 ( unsigned long V_191 )
{
return V_191 % V_192 ;
}
static inline unsigned long F_192 ( unsigned long V_191 )
{
return V_191 / V_192 ;
}
static inline unsigned int F_193 ( int V_60 )
{
return V_60 ;
}
static inline void F_194 ( const char * V_34 ,
const struct V_1 * V_2 , unsigned long V_191 )
{
#ifdef F_38
unsigned long V_193 = F_195 ( V_2 -> V_10 -> V_191 ) ;
F_39 ( L_51 , V_34 , V_2 -> V_40 ) ;
#ifdef F_196
if ( F_191 ( V_191 ) != F_191 ( V_193 ) )
F_197 ( L_52 ,
F_191 ( V_191 ) , F_191 ( V_193 ) ) ;
else
#endif
if ( F_192 ( V_191 ) != F_192 ( V_193 ) )
F_197 ( L_53 ,
F_192 ( V_191 ) , F_192 ( V_193 ) ) ;
else
F_197 ( L_54 ,
V_193 , V_191 , F_190 ( V_191 ) ) ;
#endif
F_10 ( V_2 , V_194 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
int V_60 ;
F_199 (cpu)
F_200 ( V_2 -> V_10 , V_60 ) -> V_191 = F_193 ( V_60 ) ;
}
static void F_201 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_38 )
{
enum T_8 { V_195 , V_196 , V_197 , V_198 };
struct V_104 * V_34 = F_91 ( V_2 , F_106 ( V_23 ) ) ;
int V_199 = 0 ;
enum T_8 V_200 = V_195 , V_201 = V_195 ;
void * V_202 ;
int V_116 = V_203 ;
struct V_23 V_173 ;
struct V_23 V_204 ;
if ( V_23 -> V_38 ) {
F_10 ( V_2 , V_205 ) ;
V_116 = V_170 ;
}
while ( V_38 && ( V_202 = F_13 ( V_2 , V_38 ) ) ) {
void * V_206 ;
unsigned long V_27 ;
do {
V_206 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_19 ( V_2 , V_38 , V_206 ) ;
V_173 . V_27 = V_27 ;
V_173 . V_29 -- ;
F_33 ( ! V_173 . V_28 ) ;
} while ( ! F_32 ( V_2 , V_23 ,
V_206 , V_27 ,
V_38 , V_173 . V_27 ,
L_55 ) );
V_38 = V_202 ;
}
V_207:
V_204 . V_38 = V_23 -> V_38 ;
V_204 . V_27 = V_23 -> V_27 ;
F_33 ( ! V_204 . V_28 ) ;
V_173 . V_27 = V_204 . V_27 ;
if ( V_38 ) {
V_173 . V_29 -- ;
F_19 ( V_2 , V_38 , V_204 . V_38 ) ;
V_173 . V_38 = V_38 ;
} else
V_173 . V_38 = V_204 . V_38 ;
V_173 . V_28 = 0 ;
if ( ! V_173 . V_29 && V_34 -> V_169 >= V_2 -> V_189 )
V_201 = V_198 ;
else if ( V_173 . V_38 ) {
V_201 = V_196 ;
if ( ! V_199 ) {
V_199 = 1 ;
F_170 ( & V_34 -> V_105 ) ;
}
} else {
V_201 = V_197 ;
if ( F_1 ( V_2 ) && ! V_199 ) {
V_199 = 1 ;
F_170 ( & V_34 -> V_105 ) ;
}
}
if ( V_200 != V_201 ) {
if ( V_200 == V_196 )
F_166 ( V_34 , V_23 ) ;
else if ( V_200 == V_197 )
F_88 ( V_2 , V_34 , V_23 ) ;
if ( V_201 == V_196 ) {
F_165 ( V_34 , V_23 , V_116 ) ;
F_10 ( V_2 , V_116 ) ;
} else if ( V_201 == V_197 ) {
F_10 ( V_2 , V_208 ) ;
F_85 ( V_2 , V_34 , V_23 ) ;
}
}
V_200 = V_201 ;
if ( ! F_32 ( V_2 , V_23 ,
V_204 . V_38 , V_204 . V_27 ,
V_173 . V_38 , V_173 . V_27 ,
L_56 ) )
goto V_207;
if ( V_199 )
F_174 ( & V_34 -> V_105 ) ;
if ( V_201 == V_198 ) {
F_10 ( V_2 , V_209 ) ;
F_162 ( V_2 , V_23 ) ;
F_10 ( V_2 , V_210 ) ;
}
}
static void F_202 ( struct V_1 * V_2 ,
struct V_174 * V_175 )
{
#ifdef F_6
struct V_104 * V_34 = NULL , * V_211 = NULL ;
struct V_23 * V_23 , * V_212 = NULL ;
while ( ( V_23 = V_175 -> V_171 ) ) {
struct V_23 V_173 ;
struct V_23 V_204 ;
V_175 -> V_171 = V_23 -> V_213 ;
V_211 = F_91 ( V_2 , F_106 ( V_23 ) ) ;
if ( V_34 != V_211 ) {
if ( V_34 )
F_174 ( & V_34 -> V_105 ) ;
V_34 = V_211 ;
F_170 ( & V_34 -> V_105 ) ;
}
do {
V_204 . V_38 = V_23 -> V_38 ;
V_204 . V_27 = V_23 -> V_27 ;
F_33 ( ! V_204 . V_28 ) ;
V_173 . V_27 = V_204 . V_27 ;
V_173 . V_38 = V_204 . V_38 ;
V_173 . V_28 = 0 ;
} while ( ! F_32 ( V_2 , V_23 ,
V_204 . V_38 , V_204 . V_27 ,
V_173 . V_38 , V_173 . V_27 ,
L_56 ) );
if ( F_3 ( ! V_173 . V_29 && V_34 -> V_169 >= V_2 -> V_189 ) ) {
V_23 -> V_213 = V_212 ;
V_212 = V_23 ;
} else {
F_165 ( V_34 , V_23 , V_170 ) ;
F_10 ( V_2 , V_214 ) ;
}
}
if ( V_34 )
F_174 ( & V_34 -> V_105 ) ;
while ( V_212 ) {
V_23 = V_212 ;
V_212 = V_212 -> V_213 ;
F_10 ( V_2 , V_209 ) ;
F_162 ( V_2 , V_23 ) ;
F_10 ( V_2 , V_210 ) ;
}
#endif
}
static void F_173 ( struct V_1 * V_2 , struct V_23 * V_23 , int V_215 )
{
#ifdef F_6
struct V_23 * V_216 ;
int V_155 ;
int V_217 ;
F_203 () ;
do {
V_155 = 0 ;
V_217 = 0 ;
V_216 = F_204 ( V_2 -> V_10 -> V_171 ) ;
if ( V_216 ) {
V_217 = V_216 -> V_217 ;
V_155 = V_216 -> V_155 ;
if ( V_215 && V_217 > V_2 -> V_180 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_202 ( V_2 , F_205 ( V_2 -> V_10 ) ) ;
F_42 ( V_3 ) ;
V_216 = NULL ;
V_217 = 0 ;
V_155 = 0 ;
F_10 ( V_2 , V_218 ) ;
}
}
V_155 ++ ;
V_217 += V_23 -> V_30 - V_23 -> V_29 ;
V_23 -> V_155 = V_155 ;
V_23 -> V_217 = V_217 ;
V_23 -> V_213 = V_216 ;
} while ( F_206 ( V_2 -> V_10 -> V_171 , V_216 , V_23 )
!= V_216 );
if ( F_3 ( ! V_2 -> V_180 ) ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_202 ( V_2 , F_205 ( V_2 -> V_10 ) ) ;
F_42 ( V_3 ) ;
}
F_207 () ;
#endif
}
static inline void F_208 ( struct V_1 * V_2 , struct V_174 * V_175 )
{
F_10 ( V_2 , V_219 ) ;
F_201 ( V_2 , V_175 -> V_23 , V_175 -> V_38 ) ;
V_175 -> V_191 = F_190 ( V_175 -> V_191 ) ;
V_175 -> V_23 = NULL ;
V_175 -> V_38 = NULL ;
}
static inline void F_209 ( struct V_1 * V_2 , int V_60 )
{
struct V_174 * V_175 = F_200 ( V_2 -> V_10 , V_60 ) ;
if ( F_95 ( V_175 ) ) {
if ( V_175 -> V_23 )
F_208 ( V_2 , V_175 ) ;
F_202 ( V_2 , V_175 ) ;
}
}
static void F_210 ( void * V_220 )
{
struct V_1 * V_2 = V_220 ;
F_209 ( V_2 , F_59 () ) ;
}
static bool F_211 ( int V_60 , void * V_221 )
{
struct V_1 * V_2 = V_221 ;
struct V_174 * V_175 = F_200 ( V_2 -> V_10 , V_60 ) ;
return V_175 -> V_23 || V_175 -> V_171 ;
}
static void F_212 ( struct V_1 * V_2 )
{
F_213 ( F_211 , F_210 , V_2 , 1 , V_222 ) ;
}
static inline int F_214 ( struct V_23 * V_23 , int V_108 )
{
#ifdef F_176
if ( ! V_23 || ( V_108 != V_140 && F_106 ( V_23 ) != V_108 ) )
return 0 ;
#endif
return 1 ;
}
static int F_215 ( struct V_23 * V_23 )
{
return V_23 -> V_30 - V_23 -> V_29 ;
}
static inline unsigned long F_216 ( struct V_104 * V_34 )
{
return F_92 ( & V_34 -> V_110 ) ;
}
static unsigned long F_217 ( struct V_104 * V_34 ,
int (* F_218)( struct V_23 * ) )
{
unsigned long V_3 ;
unsigned long V_20 = 0 ;
struct V_23 * V_23 ;
F_107 ( & V_34 -> V_105 , V_3 ) ;
F_219 (page, &n->partial, lru)
V_20 += F_218 ( V_23 ) ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
return V_20 ;
}
static T_4 void
F_220 ( struct V_1 * V_2 , T_7 V_223 , int V_224 )
{
#ifdef F_2
static F_221 ( V_225 , V_226 ,
V_227 ) ;
int V_108 ;
struct V_104 * V_34 ;
if ( ( V_223 & V_145 ) || ! F_222 ( & V_225 ) )
return;
F_197 ( L_57 ,
V_224 , V_223 , & V_223 ) ;
F_197 ( L_58 ,
V_2 -> V_40 , V_2 -> V_76 , V_2 -> V_15 , F_23 ( V_2 -> V_138 ) ,
F_23 ( V_2 -> V_149 ) ) ;
if ( F_23 ( V_2 -> V_149 ) > F_223 ( V_2 -> V_76 ) )
F_197 ( L_59 ,
V_2 -> V_40 ) ;
F_224 (s, node, n) {
unsigned long V_109 ;
unsigned long V_228 ;
unsigned long V_229 ;
V_229 = F_217 ( V_34 , F_215 ) ;
V_109 = F_93 ( V_34 ) ;
V_228 = F_216 ( V_34 ) ;
F_197 ( L_60 ,
V_108 , V_109 , V_228 , V_229 ) ;
}
#endif
}
static inline void * F_225 ( struct V_1 * V_2 , T_7 V_3 ,
int V_108 , struct V_174 * * V_230 )
{
void * V_38 ;
struct V_174 * V_175 = * V_230 ;
struct V_23 * V_23 ;
V_38 = F_186 ( V_2 , V_3 , V_108 , V_175 ) ;
if ( V_38 )
return V_38 ;
V_23 = F_147 ( V_2 , V_3 , V_108 ) ;
if ( V_23 ) {
V_175 = F_226 ( V_2 -> V_10 ) ;
if ( V_175 -> V_23 )
F_208 ( V_2 , V_175 ) ;
V_38 = V_23 -> V_38 ;
V_23 -> V_38 = NULL ;
F_10 ( V_2 , V_231 ) ;
V_175 -> V_23 = V_23 ;
* V_230 = V_175 ;
} else
V_38 = NULL ;
return V_38 ;
}
static inline bool F_172 ( struct V_23 * V_23 , T_7 V_223 )
{
if ( F_3 ( F_227 ( V_23 ) ) )
return F_228 ( V_223 ) ;
return true ;
}
static inline void * F_229 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_23 V_173 ;
unsigned long V_27 ;
void * V_38 ;
do {
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_173 . V_27 = V_27 ;
F_33 ( ! V_173 . V_28 ) ;
V_173 . V_29 = V_23 -> V_30 ;
V_173 . V_28 = V_38 != NULL ;
} while ( ! F_32 ( V_2 , V_23 ,
V_38 , V_27 ,
NULL , V_173 . V_27 ,
L_61 ) );
return V_38 ;
}
static void * F_230 ( struct V_1 * V_2 , T_7 V_223 , int V_108 ,
unsigned long V_14 , struct V_174 * V_175 )
{
void * V_38 ;
struct V_23 * V_23 ;
V_23 = V_175 -> V_23 ;
if ( ! V_23 )
goto F_147;
V_207:
if ( F_3 ( ! F_214 ( V_23 , V_108 ) ) ) {
int V_190 = V_108 ;
if ( V_108 != V_140 && ! F_188 ( V_108 ) )
V_190 = F_189 ( V_108 ) ;
if ( F_3 ( ! F_214 ( V_23 , V_190 ) ) ) {
F_10 ( V_2 , V_232 ) ;
F_201 ( V_2 , V_23 , V_175 -> V_38 ) ;
V_175 -> V_23 = NULL ;
V_175 -> V_38 = NULL ;
goto F_147;
}
}
if ( F_3 ( ! F_172 ( V_23 , V_223 ) ) ) {
F_201 ( V_2 , V_23 , V_175 -> V_38 ) ;
V_175 -> V_23 = NULL ;
V_175 -> V_38 = NULL ;
goto F_147;
}
V_38 = V_175 -> V_38 ;
if ( V_38 )
goto V_233;
V_38 = F_229 ( V_2 , V_23 ) ;
if ( ! V_38 ) {
V_175 -> V_23 = NULL ;
F_10 ( V_2 , V_234 ) ;
goto F_147;
}
F_10 ( V_2 , V_235 ) ;
V_233:
F_33 ( ! V_175 -> V_23 -> V_28 ) ;
V_175 -> V_38 = F_13 ( V_2 , V_38 ) ;
V_175 -> V_191 = F_190 ( V_175 -> V_191 ) ;
return V_38 ;
F_147:
if ( V_175 -> V_171 ) {
V_23 = V_175 -> V_23 = V_175 -> V_171 ;
V_175 -> V_171 = V_23 -> V_213 ;
F_10 ( V_2 , V_236 ) ;
V_175 -> V_38 = NULL ;
goto V_207;
}
V_38 = F_225 ( V_2 , V_223 , V_108 , & V_175 ) ;
if ( F_3 ( ! V_38 ) ) {
F_220 ( V_2 , V_223 , V_108 ) ;
return NULL ;
}
V_23 = V_175 -> V_23 ;
if ( F_95 ( ! F_1 ( V_2 ) && F_172 ( V_23 , V_223 ) ) )
goto V_233;
if ( F_1 ( V_2 ) &&
! F_103 ( V_2 , V_23 , V_38 , V_14 ) )
goto F_147;
F_201 ( V_2 , V_23 , F_13 ( V_2 , V_38 ) ) ;
V_175 -> V_23 = NULL ;
V_175 -> V_38 = NULL ;
return V_38 ;
}
static void * F_231 ( struct V_1 * V_2 , T_7 V_223 , int V_108 ,
unsigned long V_14 , struct V_174 * V_175 )
{
void * V_5 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_196
V_175 = F_205 ( V_2 -> V_10 ) ;
#endif
V_5 = F_230 ( V_2 , V_223 , V_108 , V_14 , V_175 ) ;
F_42 ( V_3 ) ;
return V_5 ;
}
static T_1 void * F_232 ( struct V_1 * V_2 ,
T_7 V_223 , int V_108 , unsigned long V_14 )
{
void * V_11 ;
struct V_174 * V_175 ;
struct V_23 * V_23 ;
unsigned long V_191 ;
V_2 = F_233 ( V_2 , V_223 ) ;
if ( ! V_2 )
return NULL ;
V_207:
do {
V_191 = F_204 ( V_2 -> V_10 -> V_191 ) ;
V_175 = F_226 ( V_2 -> V_10 ) ;
} while ( F_234 ( F_196 ) &&
F_3 ( V_191 != F_235 ( V_175 -> V_191 ) ) );
F_236 () ;
V_11 = V_175 -> V_38 ;
V_23 = V_175 -> V_23 ;
if ( F_3 ( ! V_11 || ! F_214 ( V_23 , V_108 ) ) ) {
V_11 = F_231 ( V_2 , V_223 , V_108 , V_14 , V_175 ) ;
F_10 ( V_2 , V_237 ) ;
} else {
void * V_122 = F_16 ( V_2 , V_11 ) ;
if ( F_3 ( ! F_237 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_191 ,
V_11 , V_191 ,
V_122 , F_190 ( V_191 ) ) ) ) {
F_194 ( L_62 , V_2 , V_191 ) ;
goto V_207;
}
F_14 ( V_2 , V_122 ) ;
F_10 ( V_2 , V_238 ) ;
}
if ( F_3 ( V_223 & V_239 ) && V_11 )
memset ( V_11 , 0 , V_2 -> V_76 ) ;
F_238 ( V_2 , V_223 , 1 , & V_11 ) ;
return V_11 ;
}
static T_1 void * F_239 ( struct V_1 * V_2 ,
T_7 V_223 , unsigned long V_14 )
{
return F_232 ( V_2 , V_223 , V_140 , V_14 ) ;
}
void * F_240 ( struct V_1 * V_2 , T_7 V_223 )
{
void * V_120 = F_239 ( V_2 , V_223 , V_240 ) ;
F_241 ( V_240 , V_120 , V_2 -> V_76 ,
V_2 -> V_15 , V_223 ) ;
return V_120 ;
}
void * F_242 ( struct V_1 * V_2 , T_7 V_223 , T_6 V_15 )
{
void * V_120 = F_239 ( V_2 , V_223 , V_240 ) ;
F_243 ( V_240 , V_120 , V_15 , V_2 -> V_15 , V_223 ) ;
F_244 ( V_2 , V_120 , V_15 , V_223 ) ;
return V_120 ;
}
void * F_245 ( struct V_1 * V_2 , T_7 V_223 , int V_108 )
{
void * V_120 = F_232 ( V_2 , V_223 , V_108 , V_240 ) ;
F_246 ( V_240 , V_120 ,
V_2 -> V_76 , V_2 -> V_15 , V_223 , V_108 ) ;
return V_120 ;
}
void * F_247 ( struct V_1 * V_2 ,
T_7 V_223 ,
int V_108 , T_6 V_15 )
{
void * V_120 = F_232 ( V_2 , V_223 , V_108 , V_240 ) ;
F_248 ( V_240 , V_120 ,
V_15 , V_2 -> V_15 , V_223 , V_108 ) ;
F_244 ( V_2 , V_120 , V_15 , V_223 ) ;
return V_120 ;
}
static void F_249 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_118 ,
unsigned long V_14 )
{
void * V_206 ;
int V_241 ;
struct V_23 V_173 ;
unsigned long V_27 ;
struct V_104 * V_34 = NULL ;
unsigned long V_119 ( V_3 ) ;
F_10 ( V_2 , V_242 ) ;
if ( F_1 ( V_2 ) &&
! F_105 ( V_2 , V_23 , V_115 , V_116 , V_118 , V_14 ) )
return;
do {
if ( F_3 ( V_34 ) ) {
F_108 ( & V_34 -> V_105 , V_3 ) ;
V_34 = NULL ;
}
V_206 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_19 ( V_2 , V_116 , V_206 ) ;
V_173 . V_27 = V_27 ;
V_241 = V_173 . V_28 ;
V_173 . V_29 -= V_118 ;
if ( ( ! V_173 . V_29 || ! V_206 ) && ! V_241 ) {
if ( F_5 ( V_2 ) && ! V_206 ) {
V_173 . V_28 = 1 ;
} else {
V_34 = F_91 ( V_2 , F_106 ( V_23 ) ) ;
F_107 ( & V_34 -> V_105 , V_3 ) ;
}
}
} while ( ! F_40 ( V_2 , V_23 ,
V_206 , V_27 ,
V_115 , V_173 . V_27 ,
L_63 ) );
if ( F_95 ( ! V_34 ) ) {
if ( V_173 . V_28 && ! V_241 ) {
F_173 ( V_2 , V_23 , 1 ) ;
F_10 ( V_2 , V_243 ) ;
}
if ( V_241 )
F_10 ( V_2 , V_244 ) ;
return;
}
if ( F_3 ( ! V_173 . V_29 && V_34 -> V_169 >= V_2 -> V_189 ) )
goto V_245;
if ( ! F_5 ( V_2 ) && F_3 ( ! V_206 ) ) {
if ( F_1 ( V_2 ) )
F_88 ( V_2 , V_34 , V_23 ) ;
F_165 ( V_34 , V_23 , V_170 ) ;
F_10 ( V_2 , V_214 ) ;
}
F_108 ( & V_34 -> V_105 , V_3 ) ;
return;
V_245:
if ( V_206 ) {
F_166 ( V_34 , V_23 ) ;
F_10 ( V_2 , V_246 ) ;
} else {
F_88 ( V_2 , V_34 , V_23 ) ;
}
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_10 ( V_2 , V_210 ) ;
F_162 ( V_2 , V_23 ) ;
}
static T_1 void F_250 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_115 , void * V_116 , int V_118 ,
unsigned long V_14 )
{
void * V_137 = V_116 ? : V_115 ;
struct V_174 * V_175 ;
unsigned long V_191 ;
F_124 ( V_2 , V_115 , V_116 ) ;
V_207:
do {
V_191 = F_204 ( V_2 -> V_10 -> V_191 ) ;
V_175 = F_226 ( V_2 -> V_10 ) ;
} while ( F_234 ( F_196 ) &&
F_3 ( V_191 != F_235 ( V_175 -> V_191 ) ) );
F_236 () ;
if ( F_95 ( V_23 == V_175 -> V_23 ) ) {
F_19 ( V_2 , V_137 , V_175 -> V_38 ) ;
if ( F_3 ( ! F_237 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_191 ,
V_175 -> V_38 , V_191 ,
V_115 , F_190 ( V_191 ) ) ) ) {
F_194 ( L_64 , V_2 , V_191 ) ;
goto V_207;
}
F_10 ( V_2 , V_247 ) ;
} else
F_249 ( V_2 , V_23 , V_115 , V_137 , V_118 , V_14 ) ;
}
void F_251 ( struct V_1 * V_2 , void * V_20 )
{
V_2 = F_252 ( V_2 , V_20 ) ;
if ( ! V_2 )
return;
F_250 ( V_2 , F_158 ( V_20 ) , V_20 , NULL , 1 , V_240 ) ;
F_253 ( V_240 , V_20 ) ;
}
static inline
int F_254 ( struct V_1 * V_2 , T_6 V_15 ,
void * * V_5 , struct V_248 * V_249 )
{
T_6 V_250 = 0 ;
int V_251 = 3 ;
void * V_11 ;
struct V_23 * V_23 ;
V_249 -> V_23 = NULL ;
do {
V_11 = V_5 [ -- V_15 ] ;
} while ( ! V_11 && V_15 );
if ( ! V_11 )
return 0 ;
V_23 = F_158 ( V_11 ) ;
if ( ! V_2 ) {
if ( F_3 ( ! F_83 ( V_23 ) ) ) {
F_255 ( ! F_256 ( V_23 ) ) ;
F_115 ( V_11 ) ;
F_257 ( V_23 , F_80 ( V_23 ) ) ;
V_5 [ V_15 ] = NULL ;
return V_15 ;
}
V_249 -> V_2 = V_23 -> V_114 ;
} else {
V_249 -> V_2 = F_252 ( V_2 , V_11 ) ;
}
V_249 -> V_23 = V_23 ;
F_19 ( V_249 -> V_2 , V_11 , NULL ) ;
V_249 -> V_116 = V_11 ;
V_249 -> V_38 = V_11 ;
V_5 [ V_15 ] = NULL ;
V_249 -> V_118 = 1 ;
while ( V_15 ) {
V_11 = V_5 [ -- V_15 ] ;
if ( ! V_11 )
continue;
if ( V_249 -> V_23 == F_158 ( V_11 ) ) {
F_19 ( V_249 -> V_2 , V_11 , V_249 -> V_38 ) ;
V_249 -> V_38 = V_11 ;
V_249 -> V_118 ++ ;
V_5 [ V_15 ] = NULL ;
continue;
}
if ( ! -- V_251 )
break;
if ( ! V_250 )
V_250 = V_15 + 1 ;
}
return V_250 ;
}
void F_258 ( struct V_1 * V_2 , T_6 V_15 , void * * V_5 )
{
if ( F_168 ( ! V_15 ) )
return;
do {
struct V_248 V_249 ;
V_15 = F_254 ( V_2 , V_15 , V_5 , & V_249 ) ;
if ( F_3 ( ! V_249 . V_23 ) )
continue;
F_250 ( V_249 . V_2 , V_249 . V_23 , V_249 . V_38 , V_249 . V_116 , V_249 . V_118 , V_240 ) ;
} while ( F_95 ( V_15 ) );
}
int F_259 ( struct V_1 * V_2 , T_7 V_3 , T_6 V_15 ,
void * * V_5 )
{
struct V_174 * V_175 ;
int V_52 ;
V_2 = F_233 ( V_2 , V_3 ) ;
if ( F_3 ( ! V_2 ) )
return false ;
F_144 () ;
V_175 = F_205 ( V_2 -> V_10 ) ;
for ( V_52 = 0 ; V_52 < V_15 ; V_52 ++ ) {
void * V_11 = V_175 -> V_38 ;
if ( F_3 ( ! V_11 ) ) {
V_5 [ V_52 ] = F_230 ( V_2 , V_3 , V_140 ,
V_240 , V_175 ) ;
if ( F_3 ( ! V_5 [ V_52 ] ) )
goto error;
V_175 = F_205 ( V_2 -> V_10 ) ;
continue;
}
V_175 -> V_38 = F_13 ( V_2 , V_11 ) ;
V_5 [ V_52 ] = V_11 ;
}
V_175 -> V_191 = F_190 ( V_175 -> V_191 ) ;
F_135 () ;
if ( F_3 ( V_3 & V_239 ) ) {
int V_252 ;
for ( V_252 = 0 ; V_252 < V_52 ; V_252 ++ )
memset ( V_5 [ V_252 ] , 0 , V_2 -> V_76 ) ;
}
F_238 ( V_2 , V_3 , V_15 , V_5 ) ;
return V_52 ;
error:
F_135 () ;
F_238 ( V_2 , V_3 , V_52 , V_5 ) ;
F_260 ( V_2 , V_52 , V_5 ) ;
return 0 ;
}
static inline int F_261 ( int V_15 , int V_253 ,
int V_254 , int V_255 , int V_17 )
{
int V_16 ;
int V_256 ;
int V_257 = V_258 ;
if ( F_21 ( V_257 , V_15 , V_17 ) > V_102 )
return F_223 ( V_15 * V_102 ) - 1 ;
for ( V_16 = F_262 ( V_257 , F_223 ( V_253 * V_15 + V_17 ) ) ;
V_16 <= V_254 ; V_16 ++ ) {
unsigned long V_259 = V_18 << V_16 ;
V_256 = ( V_259 - V_17 ) % V_15 ;
if ( V_256 <= V_259 / V_255 )
break;
}
return V_16 ;
}
static inline int F_263 ( int V_15 , int V_17 )
{
int V_16 ;
int V_253 ;
int V_260 ;
int V_101 ;
V_253 = V_261 ;
if ( ! V_253 )
V_253 = 4 * ( F_264 ( V_262 ) + 1 ) ;
V_101 = F_21 ( V_263 , V_15 , V_17 ) ;
V_253 = V_149 ( V_253 , V_101 ) ;
while ( V_253 > 1 ) {
V_260 = 16 ;
while ( V_260 >= 4 ) {
V_16 = F_261 ( V_15 , V_253 ,
V_263 , V_260 , V_17 ) ;
if ( V_16 <= V_263 )
return V_16 ;
V_260 /= 2 ;
}
V_253 -- ;
}
V_16 = F_261 ( V_15 , 1 , V_263 , 1 , V_17 ) ;
if ( V_16 <= V_263 )
return V_16 ;
V_16 = F_261 ( V_15 , 1 , V_264 , 1 , V_17 ) ;
if ( V_16 < V_264 )
return V_16 ;
return - V_265 ;
}
static void
F_265 ( struct V_104 * V_34 )
{
V_34 -> V_169 = 0 ;
F_266 ( & V_34 -> V_105 ) ;
F_267 ( & V_34 -> V_171 ) ;
#ifdef F_2
F_268 ( & V_34 -> V_109 , 0 ) ;
F_268 ( & V_34 -> V_110 , 0 ) ;
F_267 ( & V_34 -> V_107 ) ;
#endif
}
static inline int F_269 ( struct V_1 * V_2 )
{
F_270 ( V_266 <
V_267 * sizeof( struct V_174 ) ) ;
V_2 -> V_10 = F_271 ( sizeof( struct V_174 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_10 )
return 0 ;
F_198 ( V_2 ) ;
return 1 ;
}
static void F_272 ( int V_108 )
{
struct V_23 * V_23 ;
struct V_104 * V_34 ;
F_255 ( V_104 -> V_15 < sizeof( struct V_104 ) ) ;
V_23 = F_147 ( V_104 , V_268 , V_108 ) ;
F_255 ( ! V_23 ) ;
if ( F_106 ( V_23 ) != V_108 ) {
F_62 ( L_65 , V_108 ) ;
F_62 ( L_66 ) ;
}
V_34 = V_23 -> V_38 ;
F_255 ( ! V_34 ) ;
V_23 -> V_38 = F_13 ( V_104 , V_34 ) ;
V_23 -> V_29 = 1 ;
V_23 -> V_28 = 0 ;
V_104 -> V_108 [ V_108 ] = V_34 ;
#ifdef F_2
F_74 ( V_104 , V_34 , V_97 ) ;
F_60 ( V_104 , V_34 ) ;
#endif
F_244 ( V_104 , V_34 , sizeof( struct V_104 ) ,
V_269 ) ;
F_265 ( V_34 ) ;
F_94 ( V_104 , V_108 , V_23 -> V_30 ) ;
F_163 ( V_34 , V_23 , V_203 ) ;
}
static void F_273 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_34 ;
F_224 (s, node, n) {
F_251 ( V_104 , V_34 ) ;
V_2 -> V_108 [ V_108 ] = NULL ;
}
}
void F_274 ( struct V_1 * V_2 )
{
F_275 ( V_2 -> V_10 ) ;
F_273 ( V_2 ) ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_108 ;
F_277 (node, N_NORMAL_MEMORY) {
struct V_104 * V_34 ;
if ( V_270 == V_271 ) {
F_272 ( V_108 ) ;
continue;
}
V_34 = F_245 ( V_104 ,
V_269 , V_108 ) ;
if ( ! V_34 ) {
F_273 ( V_2 ) ;
return 0 ;
}
V_2 -> V_108 [ V_108 ] = V_34 ;
F_265 ( V_34 ) ;
}
return 1 ;
}
static void F_278 ( struct V_1 * V_2 , unsigned long V_149 )
{
if ( V_149 < V_272 )
V_149 = V_272 ;
else if ( V_149 > V_273 )
V_149 = V_273 ;
V_2 -> V_189 = V_149 ;
}
static int F_279 ( struct V_1 * V_2 , int V_274 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_76 ;
int V_16 ;
V_15 = F_280 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_95 ) && ! ( V_3 & V_168 ) &&
! V_2 -> F_111 )
V_2 -> V_3 |= V_80 ;
else
V_2 -> V_3 &= ~ V_80 ;
if ( ( V_3 & V_6 ) && V_15 == V_2 -> V_76 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_29 = V_15 ;
if ( ( ( V_3 & ( V_168 | V_95 ) ) ||
V_2 -> F_111 ) ) {
V_2 -> V_12 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_65 )
V_15 += 2 * sizeof( struct V_47 ) ;
if ( V_3 & V_6 ) {
V_15 += sizeof( void * ) ;
V_2 -> V_7 = sizeof( void * ) ;
V_2 -> V_7 = F_280 ( V_2 -> V_7 , V_2 -> V_275 ) ;
V_15 += V_2 -> V_7 ;
}
#endif
V_15 = F_280 ( V_15 , V_2 -> V_275 ) ;
V_2 -> V_15 = V_15 ;
if ( V_274 >= 0 )
V_16 = V_274 ;
else
V_16 = F_263 ( V_15 , V_2 -> V_17 ) ;
if ( V_16 < 0 )
return 0 ;
V_2 -> V_144 = 0 ;
if ( V_16 )
V_2 -> V_144 |= V_276 ;
if ( V_2 -> V_3 & V_277 )
V_2 -> V_144 |= V_278 ;
if ( V_2 -> V_3 & V_156 )
V_2 -> V_144 |= V_279 ;
V_2 -> V_138 = F_22 ( V_16 , V_15 , V_2 -> V_17 ) ;
V_2 -> V_149 = F_22 ( F_223 ( V_15 ) , V_15 , V_2 -> V_17 ) ;
if ( F_24 ( V_2 -> V_138 ) > F_24 ( V_2 -> F_262 ) )
V_2 -> F_262 = V_2 -> V_138 ;
return ! ! F_24 ( V_2 -> V_138 ) ;
}
static int F_281 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_110 ( V_2 -> V_15 , V_3 , V_2 -> V_40 , V_2 -> F_111 ) ;
V_2 -> V_17 = 0 ;
if ( V_166 && ( V_2 -> V_3 & V_168 ) )
V_2 -> V_17 = sizeof( struct V_164 ) ;
if ( ! F_279 ( V_2 , - 1 ) )
goto error;
if ( V_128 ) {
if ( F_223 ( V_2 -> V_15 ) > F_223 ( V_2 -> V_76 ) ) {
V_2 -> V_3 &= ~ V_280 ;
V_2 -> V_12 = 0 ;
if ( ! F_279 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_35 ) && \
F_35 ( V_36 )
if ( F_282 () && ( V_2 -> V_3 & V_281 ) == 0 )
V_2 -> V_3 |= V_37 ;
#endif
F_278 ( V_2 , F_283 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_180 = 0 ;
else if ( V_2 -> V_15 >= V_18 )
V_2 -> V_180 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_180 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_180 = 13 ;
else
V_2 -> V_180 = 30 ;
#ifdef F_176
V_2 -> V_188 = 1000 ;
#endif
if ( ! F_276 ( V_2 ) )
goto error;
if ( F_269 ( V_2 ) )
return 0 ;
F_273 ( V_2 ) ;
error:
if ( V_3 & V_282 )
F_284 ( L_67 ,
V_2 -> V_40 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_23 ( V_2 -> V_138 ) , V_2 -> V_12 , V_3 ) ;
return - V_283 ;
}
static void F_285 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_43 )
{
#ifdef F_2
void * V_14 = F_44 ( V_23 ) ;
void * V_5 ;
unsigned long * V_41 = F_286 ( F_287 ( V_23 -> V_30 ) *
sizeof( long ) , V_222 ) ;
if ( ! V_41 )
return;
F_73 ( V_2 , V_23 , V_43 , V_2 -> V_40 ) ;
F_25 ( V_23 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_151 (p, s, addr, page->objects) {
if ( ! F_288 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) ) {
F_62 ( L_68 , V_5 , V_5 - V_14 ) ;
F_63 ( V_2 , V_5 ) ;
}
}
F_29 ( V_23 ) ;
F_289 ( V_41 ) ;
#endif
}
static void F_290 ( struct V_1 * V_2 , struct V_104 * V_34 )
{
struct V_23 * V_23 , * V_165 ;
F_255 ( F_34 () ) ;
F_291 ( & V_34 -> V_105 ) ;
F_171 (page, h, &n->partial, lru) {
if ( ! V_23 -> V_29 ) {
F_166 ( V_34 , V_23 ) ;
F_162 ( V_2 , V_23 ) ;
} else {
F_285 ( V_2 , V_23 ,
L_69 ) ;
}
}
F_292 ( & V_34 -> V_105 ) ;
}
int F_293 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_34 ;
F_212 ( V_2 ) ;
F_224 (s, node, n) {
F_290 ( V_2 , V_34 ) ;
if ( V_34 -> V_169 || F_90 ( V_2 , V_108 ) )
return 1 ;
}
return 0 ;
}
static int T_5 F_294 ( char * V_123 )
{
F_295 ( & V_123 , & V_258 ) ;
return 1 ;
}
static int T_5 F_296 ( char * V_123 )
{
F_295 ( & V_123 , & V_263 ) ;
V_263 = V_149 ( V_263 , V_264 - 1 ) ;
return 1 ;
}
static int T_5 F_297 ( char * V_123 )
{
F_295 ( & V_123 , & V_261 ) ;
return 1 ;
}
void * F_298 ( T_6 V_15 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_284 ) )
return F_299 ( V_15 , V_3 ) ;
V_2 = F_300 ( V_15 , V_3 ) ;
if ( F_3 ( F_301 ( V_2 ) ) )
return V_2 ;
V_120 = F_239 ( V_2 , V_3 , V_240 ) ;
F_243 ( V_240 , V_120 , V_15 , V_2 -> V_15 , V_3 ) ;
F_244 ( V_2 , V_120 , V_15 , V_3 ) ;
return V_120 ;
}
static void * F_302 ( T_6 V_15 , T_7 V_3 , int V_108 )
{
struct V_23 * V_23 ;
void * V_130 = NULL ;
V_3 |= V_276 | V_139 ;
V_23 = F_303 ( V_108 , V_3 , F_223 ( V_15 ) ) ;
if ( V_23 )
V_130 = F_44 ( V_23 ) ;
F_112 ( V_130 , V_15 , V_3 ) ;
return V_130 ;
}
void * F_304 ( T_6 V_15 , T_7 V_3 , int V_108 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_284 ) ) {
V_120 = F_302 ( V_15 , V_3 , V_108 ) ;
F_248 ( V_240 , V_120 ,
V_15 , V_18 << F_223 ( V_15 ) ,
V_3 , V_108 ) ;
return V_120 ;
}
V_2 = F_300 ( V_15 , V_3 ) ;
if ( F_3 ( F_301 ( V_2 ) ) )
return V_2 ;
V_120 = F_232 ( V_2 , V_3 , V_108 , V_240 ) ;
F_248 ( V_240 , V_120 , V_15 , V_2 -> V_15 , V_3 , V_108 ) ;
F_244 ( V_2 , V_120 , V_15 , V_3 ) ;
return V_120 ;
}
static T_6 F_305 ( const void * V_11 )
{
struct V_23 * V_23 ;
if ( F_3 ( V_11 == V_285 ) )
return 0 ;
V_23 = F_158 ( V_11 ) ;
if ( F_3 ( ! F_83 ( V_23 ) ) ) {
F_168 ( ! F_256 ( V_23 ) ) ;
return V_18 << F_80 ( V_23 ) ;
}
return F_306 ( V_23 -> V_114 ) ;
}
T_6 F_307 ( const void * V_11 )
{
T_6 V_15 = F_305 ( V_11 ) ;
F_308 ( V_11 , V_15 ) ;
return V_15 ;
}
void F_289 ( const void * V_20 )
{
struct V_23 * V_23 ;
void * V_11 = ( void * ) V_20 ;
F_309 ( V_240 , V_20 ) ;
if ( F_3 ( F_301 ( V_20 ) ) )
return;
V_23 = F_158 ( V_20 ) ;
if ( F_3 ( ! F_83 ( V_23 ) ) ) {
F_255 ( ! F_256 ( V_23 ) ) ;
F_115 ( V_20 ) ;
F_257 ( V_23 , F_80 ( V_23 ) ) ;
return;
}
F_250 ( V_23 -> V_114 , V_23 , V_11 , NULL , 1 , V_240 ) ;
}
int F_310 ( struct V_1 * V_2 , bool V_286 )
{
int V_108 ;
int V_52 ;
struct V_104 * V_34 ;
struct V_23 * V_23 ;
struct V_23 * V_68 ;
struct V_167 V_287 ;
struct V_167 V_288 [ V_289 ] ;
unsigned long V_3 ;
int V_120 = 0 ;
if ( V_286 ) {
V_2 -> V_180 = 0 ;
V_2 -> V_189 = 0 ;
F_311 () ;
}
F_212 ( V_2 ) ;
F_224 (s, node, n) {
F_267 ( & V_287 ) ;
for ( V_52 = 0 ; V_52 < V_289 ; V_52 ++ )
F_267 ( V_288 + V_52 ) ;
F_107 ( & V_34 -> V_105 , V_3 ) ;
F_171 (page, t, &n->partial, lru) {
int free = V_23 -> V_30 - V_23 -> V_29 ;
F_236 () ;
F_255 ( free <= 0 ) ;
if ( free == V_23 -> V_30 ) {
F_312 ( & V_23 -> V_106 , & V_287 ) ;
V_34 -> V_169 -- ;
} else if ( free <= V_289 )
F_312 ( & V_23 -> V_106 , V_288 + free - 1 ) ;
}
for ( V_52 = V_289 - 1 ; V_52 >= 0 ; V_52 -- )
F_313 ( V_288 + V_52 , & V_34 -> V_171 ) ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
F_171 (page, t, &discard, lru)
F_162 ( V_2 , V_23 ) ;
if ( F_90 ( V_2 , V_108 ) )
V_120 = 1 ;
}
return V_120 ;
}
static int F_314 ( void * V_290 )
{
struct V_1 * V_2 ;
F_315 ( & V_291 ) ;
F_219 (s, &slab_caches, list)
F_310 ( V_2 , false ) ;
F_316 ( & V_291 ) ;
return 0 ;
}
static void F_317 ( void * V_290 )
{
struct V_104 * V_34 ;
struct V_1 * V_2 ;
struct V_292 * V_293 = V_290 ;
int V_294 ;
V_294 = V_293 -> V_295 ;
if ( V_294 < 0 )
return;
F_315 ( & V_291 ) ;
F_219 (s, &slab_caches, list) {
V_34 = F_91 ( V_2 , V_294 ) ;
if ( V_34 ) {
F_255 ( F_90 ( V_2 , V_294 ) ) ;
V_2 -> V_108 [ V_294 ] = NULL ;
F_251 ( V_104 , V_34 ) ;
}
}
F_316 ( & V_291 ) ;
}
static int F_318 ( void * V_290 )
{
struct V_104 * V_34 ;
struct V_1 * V_2 ;
struct V_292 * V_293 = V_290 ;
int V_224 = V_293 -> V_295 ;
int V_120 = 0 ;
if ( V_224 < 0 )
return 0 ;
F_315 ( & V_291 ) ;
F_219 (s, &slab_caches, list) {
V_34 = F_240 ( V_104 , V_269 ) ;
if ( ! V_34 ) {
V_120 = - V_296 ;
goto V_121;
}
F_265 ( V_34 ) ;
V_2 -> V_108 [ V_224 ] = V_34 ;
}
V_121:
F_316 ( & V_291 ) ;
return V_120 ;
}
static int F_319 ( struct V_297 * V_298 ,
unsigned long V_299 , void * V_290 )
{
int V_120 = 0 ;
switch ( V_299 ) {
case V_300 :
V_120 = F_318 ( V_290 ) ;
break;
case V_301 :
V_120 = F_314 ( V_290 ) ;
break;
case V_302 :
case V_303 :
F_317 ( V_290 ) ;
break;
case V_304 :
case V_305 :
break;
}
if ( V_120 )
V_120 = F_320 ( V_120 ) ;
else
V_120 = V_306 ;
return V_120 ;
}
static struct V_1 * T_5 F_321 ( struct V_1 * V_307 )
{
int V_108 ;
struct V_1 * V_2 = F_322 ( V_1 , V_268 ) ;
struct V_104 * V_34 ;
memcpy ( V_2 , V_307 , V_1 -> V_76 ) ;
F_209 ( V_2 , F_59 () ) ;
F_224 (s, node, n) {
struct V_23 * V_5 ;
F_219 (p, &n->partial, lru)
V_5 -> V_114 = V_2 ;
#ifdef F_2
F_219 (p, &n->full, lru)
V_5 -> V_114 = V_2 ;
#endif
}
F_323 ( V_2 ) ;
F_87 ( & V_2 -> V_308 , & V_309 ) ;
return V_2 ;
}
void T_5 F_324 ( void )
{
static V_310 struct V_1 V_311 ,
V_312 ;
if ( F_325 () )
V_263 = 0 ;
V_104 = & V_312 ;
V_1 = & V_311 ;
F_326 ( V_104 , L_70 ,
sizeof( struct V_104 ) , V_313 ) ;
F_327 ( & V_314 ) ;
V_270 = V_315 ;
F_326 ( V_1 , L_71 ,
F_328 ( struct V_1 , V_108 ) +
V_316 * sizeof( struct V_104 * ) ,
V_313 ) ;
V_1 = F_321 ( & V_311 ) ;
V_104 = F_321 ( & V_312 ) ;
F_329 () ;
F_330 ( 0 ) ;
#ifdef F_331
F_332 ( & V_317 ) ;
#endif
F_39 ( L_72 ,
F_333 () ,
V_258 , V_263 , V_261 ,
V_262 , V_316 ) ;
}
void T_5 F_334 ( void )
{
}
struct V_1 *
F_335 ( const char * V_40 , T_6 V_15 , T_6 V_275 ,
unsigned long V_3 , void (* F_111)( void * ) )
{
struct V_1 * V_2 , * V_175 ;
V_2 = F_336 ( V_15 , V_275 , V_3 , V_40 , F_111 ) ;
if ( V_2 ) {
V_2 -> V_318 ++ ;
V_2 -> V_76 = F_262 ( V_2 -> V_76 , ( int ) V_15 ) ;
V_2 -> V_29 = F_337 ( int , V_2 -> V_29 , F_280 ( V_15 , sizeof( void * ) ) ) ;
F_338 (c, s) {
V_175 -> V_76 = V_2 -> V_76 ;
V_175 -> V_29 = F_337 ( int , V_175 -> V_29 ,
F_280 ( V_15 , sizeof( void * ) ) ) ;
}
if ( F_8 ( V_2 , V_40 ) ) {
V_2 -> V_318 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_339 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_319 ;
V_319 = F_281 ( V_2 , V_3 ) ;
if ( V_319 )
return V_319 ;
if ( V_270 <= V_320 )
return 0 ;
F_9 ( V_2 ) ;
V_319 = F_7 ( V_2 ) ;
if ( V_319 )
F_274 ( V_2 ) ;
return V_319 ;
}
static int F_340 ( struct V_297 * V_321 ,
unsigned long V_299 , void * V_322 )
{
long V_60 = ( long ) V_322 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_299 ) {
case V_323 :
case V_324 :
case V_325 :
case V_326 :
F_315 ( & V_291 ) ;
F_219 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_209 ( V_2 , V_60 ) ;
F_42 ( V_3 ) ;
}
F_316 ( & V_291 ) ;
break;
default:
break;
}
return V_306 ;
}
void * F_341 ( T_6 V_15 , T_7 V_223 , unsigned long V_327 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_284 ) )
return F_299 ( V_15 , V_223 ) ;
V_2 = F_300 ( V_15 , V_223 ) ;
if ( F_3 ( F_301 ( V_2 ) ) )
return V_2 ;
V_120 = F_239 ( V_2 , V_223 , V_327 ) ;
F_243 ( V_327 , V_120 , V_15 , V_2 -> V_15 , V_223 ) ;
return V_120 ;
}
void * F_342 ( T_6 V_15 , T_7 V_223 ,
int V_108 , unsigned long V_327 )
{
struct V_1 * V_2 ;
void * V_120 ;
if ( F_3 ( V_15 > V_284 ) ) {
V_120 = F_302 ( V_15 , V_223 , V_108 ) ;
F_248 ( V_327 , V_120 ,
V_15 , V_18 << F_223 ( V_15 ) ,
V_223 , V_108 ) ;
return V_120 ;
}
V_2 = F_300 ( V_15 , V_223 ) ;
if ( F_3 ( F_301 ( V_2 ) ) )
return V_2 ;
V_120 = F_232 ( V_2 , V_223 , V_108 , V_327 ) ;
F_248 ( V_327 , V_120 , V_15 , V_2 -> V_15 , V_223 , V_108 ) ;
return V_120 ;
}
static int F_343 ( struct V_23 * V_23 )
{
return V_23 -> V_29 ;
}
static int F_344 ( struct V_23 * V_23 )
{
return V_23 -> V_30 ;
}
static int F_345 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
void * V_5 ;
void * V_14 = F_44 ( V_23 ) ;
if ( ! F_82 ( V_2 , V_23 ) ||
! F_84 ( V_2 , V_23 , NULL ) )
return 0 ;
F_346 ( V_41 , V_23 -> V_30 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_151 (p, s, addr, page->objects) {
if ( F_288 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_81 ( V_2 , V_23 , V_5 , V_111 ) )
return 0 ;
}
F_151 (p, s, addr, page->objects)
if ( ! F_288 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_81 ( V_2 , V_23 , V_5 , V_97 ) )
return 0 ;
return 1 ;
}
static void F_347 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
F_25 ( V_23 ) ;
F_345 ( V_2 , V_23 , V_41 ) ;
F_29 ( V_23 ) ;
}
static int F_348 ( struct V_1 * V_2 ,
struct V_104 * V_34 , unsigned long * V_41 )
{
unsigned long V_328 = 0 ;
struct V_23 * V_23 ;
unsigned long V_3 ;
F_107 ( & V_34 -> V_105 , V_3 ) ;
F_219 (page, &n->partial, lru) {
F_347 ( V_2 , V_23 , V_41 ) ;
V_328 ++ ;
}
if ( V_328 != V_34 -> V_169 )
F_62 ( L_73 ,
V_2 -> V_40 , V_328 , V_34 -> V_169 ) ;
if ( ! ( V_2 -> V_3 & V_65 ) )
goto V_121;
F_219 (page, &n->full, lru) {
F_347 ( V_2 , V_23 , V_41 ) ;
V_328 ++ ;
}
if ( V_328 != F_92 ( & V_34 -> V_109 ) )
F_62 ( L_74 ,
V_2 -> V_40 , V_328 , F_92 ( & V_34 -> V_109 ) ) ;
V_121:
F_108 ( & V_34 -> V_105 , V_3 ) ;
return V_328 ;
}
static long F_349 ( struct V_1 * V_2 )
{
int V_108 ;
unsigned long V_328 = 0 ;
unsigned long * V_41 = F_350 ( F_287 ( F_24 ( V_2 -> F_262 ) ) *
sizeof( unsigned long ) , V_269 ) ;
struct V_104 * V_34 ;
if ( ! V_41 )
return - V_296 ;
F_212 ( V_2 ) ;
F_224 (s, node, n)
V_328 += F_348 ( V_2 , V_34 , V_41 ) ;
F_289 ( V_41 ) ;
return V_328 ;
}
static void F_351 ( struct V_329 * V_68 )
{
if ( V_68 -> F_262 )
F_352 ( ( unsigned long ) V_68 -> V_330 ,
F_223 ( sizeof( struct V_331 ) * V_68 -> F_262 ) ) ;
}
static int F_353 ( struct V_329 * V_68 , unsigned long F_262 , T_7 V_3 )
{
struct V_331 * V_200 ;
int V_16 ;
V_16 = F_223 ( sizeof( struct V_331 ) * F_262 ) ;
V_200 = ( void * ) F_354 ( V_3 , V_16 ) ;
if ( ! V_200 )
return 0 ;
if ( V_68 -> V_328 ) {
memcpy ( V_200 , V_68 -> V_330 , sizeof( struct V_331 ) * V_68 -> V_328 ) ;
F_351 ( V_68 ) ;
}
V_68 -> F_262 = F_262 ;
V_68 -> V_330 = V_200 ;
return 1 ;
}
static int F_355 ( struct V_329 * V_68 , struct V_1 * V_2 ,
const struct V_47 * V_47 )
{
long V_88 , V_92 , V_332 ;
struct V_331 * V_200 ;
unsigned long V_333 ;
unsigned long V_334 = V_64 - V_47 -> V_63 ;
V_88 = - 1 ;
V_92 = V_68 -> V_328 ;
for ( ; ; ) {
V_332 = V_88 + ( V_92 - V_88 + 1 ) / 2 ;
if ( V_332 == V_92 )
break;
V_333 = V_68 -> V_330 [ V_332 ] . V_14 ;
if ( V_47 -> V_14 == V_333 ) {
V_200 = & V_68 -> V_330 [ V_332 ] ;
V_200 -> V_328 ++ ;
if ( V_47 -> V_63 ) {
V_200 -> V_335 += V_334 ;
if ( V_334 < V_200 -> V_336 )
V_200 -> V_336 = V_334 ;
if ( V_334 > V_200 -> V_337 )
V_200 -> V_337 = V_334 ;
if ( V_47 -> V_61 < V_200 -> V_338 )
V_200 -> V_338 = V_47 -> V_61 ;
if ( V_47 -> V_61 > V_200 -> V_339 )
V_200 -> V_339 = V_47 -> V_61 ;
F_356 ( V_47 -> V_60 ,
F_357 ( V_200 -> V_340 ) ) ;
}
F_358 ( F_106 ( F_359 ( V_47 ) ) , V_200 -> V_341 ) ;
return 1 ;
}
if ( V_47 -> V_14 < V_333 )
V_92 = V_332 ;
else
V_88 = V_332 ;
}
if ( V_68 -> V_328 >= V_68 -> F_262 && ! F_353 ( V_68 , 2 * V_68 -> F_262 , V_222 ) )
return 0 ;
V_200 = V_68 -> V_330 + V_332 ;
if ( V_332 < V_68 -> V_328 )
memmove ( V_200 + 1 , V_200 ,
( V_68 -> V_328 - V_332 ) * sizeof( struct V_331 ) ) ;
V_68 -> V_328 ++ ;
V_200 -> V_328 = 1 ;
V_200 -> V_14 = V_47 -> V_14 ;
V_200 -> V_335 = V_334 ;
V_200 -> V_336 = V_334 ;
V_200 -> V_337 = V_334 ;
V_200 -> V_338 = V_47 -> V_61 ;
V_200 -> V_339 = V_47 -> V_61 ;
F_360 ( F_357 ( V_200 -> V_340 ) ) ;
F_356 ( V_47 -> V_60 , F_357 ( V_200 -> V_340 ) ) ;
F_361 ( V_200 -> V_341 ) ;
F_358 ( F_106 ( F_359 ( V_47 ) ) , V_200 -> V_341 ) ;
return 1 ;
}
static void F_362 ( struct V_329 * V_68 , struct V_1 * V_2 ,
struct V_23 * V_23 , enum V_48 V_49 ,
unsigned long * V_41 )
{
void * V_14 = F_44 ( V_23 ) ;
void * V_5 ;
F_346 ( V_41 , V_23 -> V_30 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_151 (p, s, addr, page->objects)
if ( ! F_288 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
F_355 ( V_68 , V_2 , F_55 ( V_2 , V_5 , V_49 ) ) ;
}
static int F_363 ( struct V_1 * V_2 , char * V_78 ,
enum V_48 V_49 )
{
int V_342 = 0 ;
unsigned long V_52 ;
struct V_329 V_68 = { 0 , 0 , NULL } ;
int V_108 ;
unsigned long * V_41 = F_350 ( F_287 ( F_24 ( V_2 -> F_262 ) ) *
sizeof( unsigned long ) , V_269 ) ;
struct V_104 * V_34 ;
if ( ! V_41 || ! F_353 ( & V_68 , V_18 / sizeof( struct V_331 ) ,
V_343 ) ) {
F_289 ( V_41 ) ;
return sprintf ( V_78 , L_75 ) ;
}
F_212 ( V_2 ) ;
F_224 (s, node, n) {
unsigned long V_3 ;
struct V_23 * V_23 ;
if ( ! F_92 ( & V_34 -> V_109 ) )
continue;
F_107 ( & V_34 -> V_105 , V_3 ) ;
F_219 (page, &n->partial, lru)
F_362 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_219 (page, &n->full, lru)
F_362 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_108 ( & V_34 -> V_105 , V_3 ) ;
}
for ( V_52 = 0 ; V_52 < V_68 . V_328 ; V_52 ++ ) {
struct V_331 * V_200 = & V_68 . V_330 [ V_52 ] ;
if ( V_342 > V_18 - V_344 - 100 )
break;
V_342 += sprintf ( V_78 + V_342 , L_76 , V_200 -> V_328 ) ;
if ( V_200 -> V_14 )
V_342 += sprintf ( V_78 + V_342 , L_77 , ( void * ) V_200 -> V_14 ) ;
else
V_342 += sprintf ( V_78 + V_342 , L_78 ) ;
if ( V_200 -> V_335 != V_200 -> V_336 ) {
V_342 += sprintf ( V_78 + V_342 , L_79 ,
V_200 -> V_336 ,
( long ) F_364 ( V_200 -> V_335 , V_200 -> V_328 ) ,
V_200 -> V_337 ) ;
} else
V_342 += sprintf ( V_78 + V_342 , L_80 ,
V_200 -> V_336 ) ;
if ( V_200 -> V_338 != V_200 -> V_339 )
V_342 += sprintf ( V_78 + V_342 , L_81 ,
V_200 -> V_338 , V_200 -> V_339 ) ;
else
V_342 += sprintf ( V_78 + V_342 , L_82 ,
V_200 -> V_338 ) ;
if ( F_365 () > 1 &&
! F_366 ( F_357 ( V_200 -> V_340 ) ) &&
V_342 < V_18 - 60 )
V_342 += F_367 ( V_78 + V_342 , V_18 - V_342 - 50 ,
L_83 ,
F_368 ( F_357 ( V_200 -> V_340 ) ) ) ;
if ( V_345 > 1 && ! F_369 ( V_200 -> V_341 ) &&
V_342 < V_18 - 60 )
V_342 += F_367 ( V_78 + V_342 , V_18 - V_342 - 50 ,
L_84 ,
F_370 ( & V_200 -> V_341 ) ) ;
V_342 += sprintf ( V_78 + V_342 , L_85 ) ;
}
F_351 ( & V_68 ) ;
F_289 ( V_41 ) ;
if ( ! V_68 . V_328 )
V_342 += sprintf ( V_78 , L_86 ) ;
return V_342 ;
}
static void T_5 F_371 ( void )
{
T_2 * V_5 ;
F_270 ( V_346 > 16 || V_267 < 10 ) ;
F_62 ( L_87 ) ;
F_62 ( L_88 ) ;
F_62 ( L_89 ) ;
V_5 = F_286 ( 16 , V_269 ) ;
V_5 [ 16 ] = 0x12 ;
F_62 ( L_90 ,
V_5 + 16 ) ;
F_349 ( V_347 [ 4 ] ) ;
V_5 = F_286 ( 32 , V_269 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_62 ( L_91 ,
V_5 ) ;
F_62 ( L_92 ) ;
F_349 ( V_347 [ 5 ] ) ;
V_5 = F_286 ( 64 , V_269 ) ;
V_5 += 64 + ( F_178 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_62 ( L_93 ,
V_5 ) ;
F_62 ( L_92 ) ;
F_349 ( V_347 [ 6 ] ) ;
F_62 ( L_94 ) ;
V_5 = F_286 ( 128 , V_269 ) ;
F_289 ( V_5 ) ;
* V_5 = 0x78 ;
F_62 ( L_95 , V_5 ) ;
F_349 ( V_347 [ 7 ] ) ;
V_5 = F_286 ( 256 , V_269 ) ;
F_289 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_62 ( L_96 , V_5 ) ;
F_349 ( V_347 [ 8 ] ) ;
V_5 = F_286 ( 512 , V_269 ) ;
F_289 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_62 ( L_97 , V_5 ) ;
F_349 ( V_347 [ 9 ] ) ;
}
static void F_371 ( void ) {}
static T_9 F_372 ( struct V_1 * V_2 ,
char * V_78 , unsigned long V_3 )
{
unsigned long V_348 = 0 ;
int V_108 ;
int V_20 ;
unsigned long * V_341 ;
V_341 = F_286 ( sizeof( unsigned long ) * V_316 , V_269 ) ;
if ( ! V_341 )
return - V_296 ;
if ( V_3 & V_349 ) {
int V_60 ;
F_199 (cpu) {
struct V_174 * V_175 = F_200 ( V_2 -> V_10 ,
V_60 ) ;
int V_108 ;
struct V_23 * V_23 ;
V_23 = F_235 ( V_175 -> V_23 ) ;
if ( ! V_23 )
continue;
V_108 = F_106 ( V_23 ) ;
if ( V_3 & V_350 )
V_20 = V_23 -> V_30 ;
else if ( V_3 & V_351 )
V_20 = V_23 -> V_29 ;
else
V_20 = 1 ;
V_348 += V_20 ;
V_341 [ V_108 ] += V_20 ;
V_23 = F_235 ( V_175 -> V_171 ) ;
if ( V_23 ) {
V_108 = F_106 ( V_23 ) ;
if ( V_3 & V_350 )
F_373 ( 1 ) ;
else if ( V_3 & V_351 )
F_373 ( 1 ) ;
else
V_20 = V_23 -> V_155 ;
V_348 += V_20 ;
V_341 [ V_108 ] += V_20 ;
}
}
}
F_374 () ;
#ifdef F_2
if ( V_3 & V_352 ) {
struct V_104 * V_34 ;
F_224 (s, node, n) {
if ( V_3 & V_350 )
V_20 = F_92 ( & V_34 -> V_110 ) ;
else if ( V_3 & V_351 )
V_20 = F_92 ( & V_34 -> V_110 ) -
F_217 ( V_34 , F_215 ) ;
else
V_20 = F_92 ( & V_34 -> V_109 ) ;
V_348 += V_20 ;
V_341 [ V_108 ] += V_20 ;
}
} else
#endif
if ( V_3 & V_353 ) {
struct V_104 * V_34 ;
F_224 (s, node, n) {
if ( V_3 & V_350 )
V_20 = F_217 ( V_34 , F_344 ) ;
else if ( V_3 & V_351 )
V_20 = F_217 ( V_34 , F_343 ) ;
else
V_20 = V_34 -> V_169 ;
V_348 += V_20 ;
V_341 [ V_108 ] += V_20 ;
}
}
V_20 = sprintf ( V_78 , L_98 , V_348 ) ;
#ifdef F_176
for ( V_108 = 0 ; V_108 < V_316 ; V_108 ++ )
if ( V_341 [ V_108 ] )
V_20 += sprintf ( V_78 + V_20 , L_99 ,
V_108 , V_341 [ V_108 ] ) ;
#endif
F_375 () ;
F_289 ( V_341 ) ;
return V_20 + sprintf ( V_78 + V_20 , L_85 ) ;
}
static int F_376 ( struct V_1 * V_2 )
{
int V_108 ;
struct V_104 * V_34 ;
F_224 (s, node, n)
if ( F_92 ( & V_34 -> V_110 ) )
return 1 ;
return 0 ;
}
static T_9 F_377 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , V_2 -> V_15 ) ;
}
static T_9 F_378 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , V_2 -> V_275 ) ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , V_2 -> V_76 ) ;
}
static T_9 F_380 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , F_24 ( V_2 -> V_138 ) ) ;
}
static T_9 F_381 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
unsigned long V_16 ;
int V_319 ;
V_319 = F_382 ( V_78 , 10 , & V_16 ) ;
if ( V_319 )
return V_319 ;
if ( V_16 > V_263 || V_16 < V_258 )
return - V_283 ;
F_279 ( V_2 , V_16 ) ;
return V_44 ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , F_23 ( V_2 -> V_138 ) ) ;
}
static T_9 F_384 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_101 , V_2 -> V_189 ) ;
}
static T_9 F_385 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
unsigned long V_149 ;
int V_319 ;
V_319 = F_382 ( V_78 , 10 , & V_149 ) ;
if ( V_319 )
return V_319 ;
F_278 ( V_2 , V_149 ) ;
return V_44 ;
}
static T_9 F_386 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_102 , V_2 -> V_180 ) ;
}
static T_9 F_387 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
unsigned long V_30 ;
int V_319 ;
V_319 = F_382 ( V_78 , 10 , & V_30 ) ;
if ( V_319 )
return V_319 ;
if ( V_30 && ! F_5 ( V_2 ) )
return - V_283 ;
V_2 -> V_180 = V_30 ;
F_212 ( V_2 ) ;
return V_44 ;
}
static T_9 F_388 ( struct V_1 * V_2 , char * V_78 )
{
if ( ! V_2 -> F_111 )
return 0 ;
return sprintf ( V_78 , L_103 , V_2 -> F_111 ) ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , V_2 -> V_318 < 0 ? 0 : V_2 -> V_318 - 1 ) ;
}
static T_9 F_390 ( struct V_1 * V_2 , char * V_78 )
{
return F_372 ( V_2 , V_78 , V_353 ) ;
}
static T_9 F_391 ( struct V_1 * V_2 , char * V_78 )
{
return F_372 ( V_2 , V_78 , V_349 ) ;
}
static T_9 F_392 ( struct V_1 * V_2 , char * V_78 )
{
return F_372 ( V_2 , V_78 , V_352 | V_351 ) ;
}
static T_9 F_393 ( struct V_1 * V_2 , char * V_78 )
{
return F_372 ( V_2 , V_78 , V_353 | V_351 ) ;
}
static T_9 F_394 ( struct V_1 * V_2 , char * V_78 )
{
int V_30 = 0 ;
int V_155 = 0 ;
int V_60 ;
int V_342 ;
F_395 (cpu) {
struct V_23 * V_23 = F_200 ( V_2 -> V_10 , V_60 ) -> V_171 ;
if ( V_23 ) {
V_155 += V_23 -> V_155 ;
V_30 += V_23 -> V_217 ;
}
}
V_342 = sprintf ( V_78 , L_104 , V_30 , V_155 ) ;
#ifdef F_331
F_395 (cpu) {
struct V_23 * V_23 = F_200 ( V_2 -> V_10 , V_60 ) -> V_171 ;
if ( V_23 && V_342 < V_18 - 20 )
V_342 += sprintf ( V_78 + V_342 , L_105 , V_60 ,
V_23 -> V_217 , V_23 -> V_155 ) ;
}
#endif
return V_342 + sprintf ( V_78 + V_342 , L_85 ) ;
}
static T_9 F_396 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_156 ) ) ;
}
static T_9 F_397 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
V_2 -> V_3 &= ~ V_156 ;
if ( V_78 [ 0 ] == '1' )
V_2 -> V_3 |= V_156 ;
return V_44 ;
}
static T_9 F_398 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_313 ) ) ;
}
static T_9 F_399 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_277 ) ) ;
}
static T_9 F_400 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_168 ) ) ;
}
static T_9 F_401 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , V_2 -> V_17 ) ;
}
static T_9 F_402 ( struct V_1 * V_2 , char * V_78 )
{
return F_372 ( V_2 , V_78 , V_352 ) ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_78 )
{
return F_372 ( V_2 , V_78 , V_352 | V_350 ) ;
}
static T_9 F_404 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_112 ) ) ;
}
static T_9 F_405 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
V_2 -> V_3 &= ~ V_112 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_112 ;
}
return V_44 ;
}
static T_9 F_406 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_103 ) ) ;
}
static T_9 F_407 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
if ( V_2 -> V_318 > 1 )
return - V_283 ;
V_2 -> V_3 &= ~ V_103 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_103 ;
}
return V_44 ;
}
static T_9 F_408 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_6 ) ) ;
}
static T_9 F_409 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( F_376 ( V_2 ) )
return - V_354 ;
V_2 -> V_3 &= ~ V_6 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_6 ;
}
F_279 ( V_2 , - 1 ) ;
return V_44 ;
}
static T_9 F_410 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_95 ) ) ;
}
static T_9 F_411 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( F_376 ( V_2 ) )
return - V_354 ;
V_2 -> V_3 &= ~ V_95 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_95 ;
}
F_279 ( V_2 , - 1 ) ;
return V_44 ;
}
static T_9 F_412 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_65 ) ) ;
}
static T_9 F_413 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( F_376 ( V_2 ) )
return - V_354 ;
V_2 -> V_3 &= ~ V_65 ;
if ( V_78 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_65 ;
}
F_279 ( V_2 , - 1 ) ;
return V_44 ;
}
static T_9 F_414 ( struct V_1 * V_2 , char * V_78 )
{
return 0 ;
}
static T_9 F_415 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
int V_120 = - V_283 ;
if ( V_78 [ 0 ] == '1' ) {
V_120 = F_349 ( V_2 ) ;
if ( V_120 >= 0 )
V_120 = V_44 ;
}
return V_120 ;
}
static T_9 F_416 ( struct V_1 * V_2 , char * V_78 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_265 ;
return F_363 ( V_2 , V_78 , V_67 ) ;
}
static T_9 F_417 ( struct V_1 * V_2 , char * V_78 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_265 ;
return F_363 ( V_2 , V_78 , V_66 ) ;
}
static T_9 F_418 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , ! ! ( V_2 -> V_3 & V_127 ) ) ;
}
static T_9 F_419 ( struct V_1 * V_2 , const char * V_78 ,
T_6 V_44 )
{
if ( V_2 -> V_318 > 1 )
return - V_283 ;
V_2 -> V_3 &= ~ V_127 ;
if ( V_78 [ 0 ] == '1' )
V_2 -> V_3 |= V_127 ;
return V_44 ;
}
static T_9 F_420 ( struct V_1 * V_2 , char * V_78 )
{
return 0 ;
}
static T_9 F_421 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
if ( V_78 [ 0 ] == '1' )
F_422 ( V_2 ) ;
else
return - V_283 ;
return V_44 ;
}
static T_9 F_423 ( struct V_1 * V_2 , char * V_78 )
{
return sprintf ( V_78 , L_100 , V_2 -> V_188 / 10 ) ;
}
static T_9 F_424 ( struct V_1 * V_2 ,
const char * V_78 , T_6 V_44 )
{
unsigned long V_355 ;
int V_319 ;
V_319 = F_382 ( V_78 , 10 , & V_355 ) ;
if ( V_319 )
return V_319 ;
if ( V_355 <= 100 )
V_2 -> V_188 = V_355 * 10 ;
return V_44 ;
}
static int F_425 ( struct V_1 * V_2 , char * V_78 , enum V_8 V_9 )
{
unsigned long V_356 = 0 ;
int V_60 ;
int V_342 ;
int * V_84 = F_350 ( V_262 * sizeof( int ) , V_269 ) ;
if ( ! V_84 )
return - V_296 ;
F_395 (cpu) {
unsigned V_20 = F_200 ( V_2 -> V_10 , V_60 ) -> F_10 [ V_9 ] ;
V_84 [ V_60 ] = V_20 ;
V_356 += V_20 ;
}
V_342 = sprintf ( V_78 , L_98 , V_356 ) ;
#ifdef F_331
F_395 (cpu) {
if ( V_84 [ V_60 ] && V_342 < V_18 - 20 )
V_342 += sprintf ( V_78 + V_342 , L_106 , V_60 , V_84 [ V_60 ] ) ;
}
#endif
F_289 ( V_84 ) ;
return V_342 + sprintf ( V_78 + V_342 , L_85 ) ;
}
static void F_426 ( struct V_1 * V_2 , enum V_8 V_9 )
{
int V_60 ;
F_395 (cpu)
F_200 ( V_2 -> V_10 , V_60 ) -> F_10 [ V_9 ] = 0 ;
}
static T_9 F_427 ( struct V_357 * V_358 ,
struct V_359 * V_360 ,
char * V_78 )
{
struct V_361 * V_359 ;
struct V_1 * V_2 ;
int V_319 ;
V_359 = F_428 ( V_360 ) ;
V_2 = F_429 ( V_358 ) ;
if ( ! V_359 -> V_362 )
return - V_363 ;
V_319 = V_359 -> V_362 ( V_2 , V_78 ) ;
return V_319 ;
}
static T_9 F_430 ( struct V_357 * V_358 ,
struct V_359 * V_360 ,
const char * V_78 , T_6 V_342 )
{
struct V_361 * V_359 ;
struct V_1 * V_2 ;
int V_319 ;
V_359 = F_428 ( V_360 ) ;
V_2 = F_429 ( V_358 ) ;
if ( ! V_359 -> V_364 )
return - V_363 ;
V_319 = V_359 -> V_364 ( V_2 , V_78 , V_342 ) ;
#ifdef F_431
if ( V_270 >= V_365 && V_319 >= 0 && F_432 ( V_2 ) ) {
struct V_1 * V_175 ;
F_315 ( & V_291 ) ;
if ( V_2 -> V_366 < V_342 )
V_2 -> V_366 = V_342 ;
F_338 (c, s)
V_359 -> V_364 ( V_175 , V_78 , V_342 ) ;
F_316 ( & V_291 ) ;
}
#endif
return V_319 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_431
int V_52 ;
char * V_367 = NULL ;
struct V_1 * V_368 ;
if ( F_432 ( V_2 ) )
return;
V_368 = V_2 -> V_369 . V_368 ;
if ( ! V_368 -> V_366 )
return;
for ( V_52 = 0 ; V_52 < F_433 ( V_370 ) ; V_52 ++ ) {
char V_371 [ 64 ] ;
char * V_78 ;
struct V_361 * V_360 = F_428 ( V_370 [ V_52 ] ) ;
if ( ! V_360 || ! V_360 -> V_364 || ! V_360 -> V_362 )
continue;
if ( V_367 )
V_78 = V_367 ;
else if ( V_368 -> V_366 < F_433 ( V_371 ) )
V_78 = V_371 ;
else {
V_367 = ( char * ) F_434 ( V_269 ) ;
if ( F_168 ( ! V_367 ) )
continue;
V_78 = V_367 ;
}
V_360 -> V_362 ( V_368 , V_78 ) ;
V_360 -> V_364 ( V_2 , V_78 , strlen ( V_78 ) ) ;
}
if ( V_367 )
F_435 ( ( unsigned long ) V_367 ) ;
#endif
}
static void F_436 ( struct V_357 * V_372 )
{
F_437 ( F_429 ( V_372 ) ) ;
}
static int F_438 ( struct V_373 * V_373 , struct V_357 * V_358 )
{
struct V_374 * V_375 = F_439 ( V_358 ) ;
if ( V_375 == & V_376 )
return 1 ;
return 0 ;
}
static inline struct V_373 * F_440 ( struct V_1 * V_2 )
{
#ifdef F_431
if ( ! F_432 ( V_2 ) )
return V_2 -> V_369 . V_368 -> V_377 ;
#endif
return V_378 ;
}
static char * F_441 ( struct V_1 * V_2 )
{
char * V_40 = F_350 ( V_379 , V_269 ) ;
char * V_5 = V_40 ;
F_255 ( ! V_40 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_277 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_156 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_112 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_154 ) )
* V_5 ++ = 't' ;
if ( V_2 -> V_3 & V_380 )
* V_5 ++ = 'A' ;
if ( V_5 != V_40 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_107 , V_2 -> V_15 ) ;
F_255 ( V_5 > V_40 + V_379 - 1 ) ;
return V_40 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_319 ;
const char * V_40 ;
int V_381 = F_442 ( V_2 ) ;
if ( V_381 ) {
F_443 ( & V_378 -> V_358 , V_2 -> V_40 ) ;
V_40 = V_2 -> V_40 ;
} else {
V_40 = F_441 ( V_2 ) ;
}
V_2 -> V_358 . V_373 = F_440 ( V_2 ) ;
V_319 = F_444 ( & V_2 -> V_358 , & V_376 , NULL , L_16 , V_40 ) ;
if ( V_319 )
goto V_121;
V_319 = F_445 ( & V_2 -> V_358 , & V_382 ) ;
if ( V_319 )
goto V_383;
#ifdef F_431
if ( F_432 ( V_2 ) ) {
V_2 -> V_377 = F_446 ( L_108 , NULL , & V_2 -> V_358 ) ;
if ( ! V_2 -> V_377 ) {
V_319 = - V_296 ;
goto V_383;
}
}
#endif
F_447 ( & V_2 -> V_358 , V_384 ) ;
if ( ! V_381 ) {
F_8 ( V_2 , V_2 -> V_40 ) ;
}
V_121:
if ( ! V_381 )
F_289 ( V_40 ) ;
return V_319 ;
V_383:
F_448 ( & V_2 -> V_358 ) ;
goto V_121;
}
void F_449 ( struct V_1 * V_2 )
{
if ( V_270 < V_365 )
return;
#ifdef F_431
F_450 ( V_2 -> V_377 ) ;
#endif
F_447 ( & V_2 -> V_358 , V_385 ) ;
F_448 ( & V_2 -> V_358 ) ;
F_451 ( & V_2 -> V_358 ) ;
}
static int F_8 ( struct V_1 * V_2 , const char * V_40 )
{
struct V_386 * V_387 ;
if ( V_270 == V_365 ) {
F_443 ( & V_378 -> V_358 , V_40 ) ;
return F_452 ( & V_378 -> V_358 , & V_2 -> V_358 , V_40 ) ;
}
V_387 = F_350 ( sizeof( struct V_386 ) , V_269 ) ;
if ( ! V_387 )
return - V_296 ;
V_387 -> V_2 = V_2 ;
V_387 -> V_40 = V_40 ;
V_387 -> V_213 = V_388 ;
V_388 = V_387 ;
return 0 ;
}
static int T_5 F_453 ( void )
{
struct V_1 * V_2 ;
int V_319 ;
F_315 ( & V_291 ) ;
V_378 = F_446 ( L_109 , & V_389 , V_390 ) ;
if ( ! V_378 ) {
F_316 ( & V_291 ) ;
F_62 ( L_110 ) ;
return - V_265 ;
}
V_270 = V_365 ;
F_219 (s, &slab_caches, list) {
V_319 = F_7 ( V_2 ) ;
if ( V_319 )
F_62 ( L_111 ,
V_2 -> V_40 ) ;
}
while ( V_388 ) {
struct V_386 * V_387 = V_388 ;
V_388 = V_388 -> V_213 ;
V_319 = F_8 ( V_387 -> V_2 , V_387 -> V_40 ) ;
if ( V_319 )
F_62 ( L_112 ,
V_387 -> V_40 ) ;
F_289 ( V_387 ) ;
}
F_316 ( & V_291 ) ;
F_371 () ;
return 0 ;
}
void F_454 ( struct V_1 * V_2 , struct V_391 * V_392 )
{
unsigned long V_109 = 0 ;
unsigned long V_228 = 0 ;
unsigned long V_229 = 0 ;
int V_108 ;
struct V_104 * V_34 ;
F_224 (s, node, n) {
V_109 += F_93 ( V_34 ) ;
V_228 += F_216 ( V_34 ) ;
V_229 += F_217 ( V_34 , F_215 ) ;
}
V_392 -> V_393 = V_228 - V_229 ;
V_392 -> V_394 = V_228 ;
V_392 -> V_395 = V_109 ;
V_392 -> V_396 = V_109 ;
V_392 -> V_397 = F_24 ( V_2 -> V_138 ) ;
V_392 -> V_398 = F_23 ( V_2 -> V_138 ) ;
}
void F_455 ( struct V_399 * V_201 , struct V_1 * V_2 )
{
}
T_9 F_456 ( struct V_400 * V_400 , const char T_10 * V_367 ,
T_6 V_328 , T_11 * V_401 )
{
return - V_363 ;
}
