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
static inline void F_10 ( struct V_1 * V_2 ) { }
static inline void F_11 ( const struct V_1 * V_2 , enum V_8 V_9 )
{
#ifdef F_12
F_13 ( V_2 -> V_10 -> F_11 [ V_9 ] ) ;
#endif
}
static inline void * F_14 ( const struct V_1 * V_2 , void * V_11 ,
unsigned long V_12 )
{
#ifdef F_15
return ( void * ) ( ( unsigned long ) V_11 ^ V_2 -> V_13 ^ V_12 ) ;
#else
return V_11 ;
#endif
}
static inline void * F_16 ( const struct V_1 * V_2 ,
void * V_12 )
{
return F_14 ( V_2 , ( void * ) * ( unsigned long * ) ( V_12 ) ,
( unsigned long ) V_12 ) ;
}
static inline void * F_17 ( struct V_1 * V_2 , void * V_14 )
{
return F_16 ( V_2 , V_14 + V_2 -> V_15 ) ;
}
static void F_18 ( const struct V_1 * V_2 , void * V_14 )
{
if ( V_14 )
F_19 ( F_16 ( V_2 , V_14 + V_2 -> V_15 ) ) ;
}
static inline void * F_20 ( struct V_1 * V_2 , void * V_14 )
{
unsigned long V_16 ;
void * V_5 ;
if ( ! F_21 () )
return F_17 ( V_2 , V_14 ) ;
V_16 = ( unsigned long ) V_14 + V_2 -> V_15 ;
F_22 ( & V_5 , ( void * * ) V_16 , sizeof( V_5 ) ) ;
return F_14 ( V_2 , V_5 , V_16 ) ;
}
static inline void F_23 ( struct V_1 * V_2 , void * V_14 , void * V_17 )
{
unsigned long V_18 = ( unsigned long ) V_14 + V_2 -> V_15 ;
#ifdef F_15
F_24 ( V_14 == V_17 ) ;
#endif
* ( void * * ) V_18 = F_14 ( V_2 , V_17 , V_18 ) ;
}
static inline int F_25 ( void * V_5 , struct V_1 * V_2 , void * V_19 )
{
return ( V_5 - V_19 ) / V_2 -> V_20 ;
}
static inline int F_26 ( int V_21 , unsigned long V_20 , int V_22 )
{
return ( ( V_23 << V_21 ) - V_22 ) / V_20 ;
}
static inline struct V_24 F_27 ( int V_21 ,
unsigned long V_20 , int V_22 )
{
struct V_24 V_25 = {
( V_21 << V_26 ) + F_26 (order, size, reserved)
} ;
return V_25 ;
}
static inline int F_28 ( struct V_24 V_25 )
{
return V_25 . V_25 >> V_26 ;
}
static inline int F_29 ( struct V_24 V_25 )
{
return V_25 . V_25 & V_27 ;
}
static T_1 void F_30 ( struct V_28 * V_28 )
{
F_31 ( F_32 ( V_28 ) , V_28 ) ;
F_33 ( V_29 , & V_28 -> V_3 ) ;
}
static T_1 void F_34 ( struct V_28 * V_28 )
{
F_31 ( F_32 ( V_28 ) , V_28 ) ;
F_35 ( V_29 , & V_28 -> V_3 ) ;
}
static inline void F_36 ( struct V_28 * V_28 , unsigned long V_30 )
{
struct V_28 V_31 ;
V_31 . V_32 = V_30 ;
V_28 -> V_33 = V_31 . V_33 ;
V_28 -> V_34 = V_31 . V_34 ;
V_28 -> V_35 = V_31 . V_35 ;
}
static inline bool F_37 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_30 ,
const char * V_39 )
{
F_38 ( ! F_39 () ) ;
#if F_40 ( V_40 ) && \
F_40 ( V_41 )
if ( V_2 -> V_3 & V_42 ) {
if ( F_41 ( & V_28 -> V_43 , & V_28 -> V_32 ,
V_36 , V_37 ,
V_38 , V_30 ) )
return true ;
} else
#endif
{
F_30 ( V_28 ) ;
if ( V_28 -> V_43 == V_36 &&
V_28 -> V_32 == V_37 ) {
V_28 -> V_43 = V_38 ;
F_36 ( V_28 , V_30 ) ;
F_34 ( V_28 ) ;
return true ;
}
F_34 ( V_28 ) ;
}
F_42 () ;
F_11 ( V_2 , V_44 ) ;
#ifdef F_43
F_44 ( L_1 , V_39 , V_2 -> V_45 ) ;
#endif
return false ;
}
static inline bool F_45 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_30 ,
const char * V_39 )
{
#if F_40 ( V_40 ) && \
F_40 ( V_41 )
if ( V_2 -> V_3 & V_42 ) {
if ( F_41 ( & V_28 -> V_43 , & V_28 -> V_32 ,
V_36 , V_37 ,
V_38 , V_30 ) )
return true ;
} else
#endif
{
unsigned long V_3 ;
F_46 ( V_3 ) ;
F_30 ( V_28 ) ;
if ( V_28 -> V_43 == V_36 &&
V_28 -> V_32 == V_37 ) {
V_28 -> V_43 = V_38 ;
F_36 ( V_28 , V_30 ) ;
F_34 ( V_28 ) ;
F_47 ( V_3 ) ;
return true ;
}
F_34 ( V_28 ) ;
F_47 ( V_3 ) ;
}
F_42 () ;
F_11 ( V_2 , V_44 ) ;
#ifdef F_43
F_44 ( L_1 , V_39 , V_2 -> V_45 ) ;
#endif
return false ;
}
static void F_48 ( struct V_1 * V_2 , struct V_28 * V_28 , unsigned long * V_46 )
{
void * V_5 ;
void * V_19 = F_49 ( V_28 ) ;
for ( V_5 = V_28 -> V_43 ; V_5 ; V_5 = F_17 ( V_2 , V_5 ) )
F_50 ( F_25 ( V_5 , V_2 , V_19 ) , V_46 ) ;
}
static inline int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_6 )
return V_2 -> V_20 - V_2 -> V_7 ;
return V_2 -> V_20 ;
}
static inline void * F_52 ( struct V_1 * V_2 , void * V_5 )
{
if ( V_2 -> V_3 & V_6 )
V_5 -= V_2 -> V_7 ;
return V_5 ;
}
static inline void F_53 ( void )
{
F_54 () ;
}
static inline void F_55 ( void )
{
F_56 () ;
}
static inline int F_57 ( struct V_1 * V_2 ,
struct V_28 * V_28 , void * V_14 )
{
void * V_47 ;
if ( ! V_14 )
return 1 ;
V_47 = F_49 ( V_28 ) ;
V_14 = F_52 ( V_2 , V_14 ) ;
if ( V_14 < V_47 || V_14 >= V_47 + V_28 -> V_35 * V_2 -> V_20 ||
( V_14 - V_47 ) % V_2 -> V_20 ) {
return 0 ;
}
return 1 ;
}
static void F_58 ( char * V_48 , char * V_49 , T_2 * V_19 ,
unsigned int V_50 )
{
F_53 () ;
F_59 ( V_48 , V_49 , V_51 , 16 , 1 , V_19 ,
V_50 , 1 ) ;
F_55 () ;
}
static struct V_52 * F_60 ( struct V_1 * V_2 , void * V_14 ,
enum V_53 V_54 )
{
struct V_52 * V_5 ;
if ( V_2 -> V_15 )
V_5 = V_14 + V_2 -> V_15 + sizeof( void * ) ;
else
V_5 = V_14 + V_2 -> V_34 ;
return V_5 + V_54 ;
}
static void F_61 ( struct V_1 * V_2 , void * V_14 ,
enum V_53 V_54 , unsigned long V_19 )
{
struct V_52 * V_5 = F_60 ( V_2 , V_14 , V_54 ) ;
if ( V_19 ) {
#ifdef F_62
struct V_55 V_56 ;
int V_57 ;
V_56 . V_58 = 0 ;
V_56 . V_59 = V_60 ;
V_56 . V_61 = V_5 -> V_62 ;
V_56 . V_63 = 3 ;
F_53 () ;
F_63 ( & V_56 ) ;
F_55 () ;
if ( V_56 . V_58 != 0 &&
V_56 . V_61 [ V_56 . V_58 - 1 ] == V_64 )
V_56 . V_58 -- ;
for ( V_57 = V_56 . V_58 ; V_57 < V_60 ; V_57 ++ )
V_5 -> V_62 [ V_57 ] = 0 ;
#endif
V_5 -> V_19 = V_19 ;
V_5 -> V_65 = F_64 () ;
V_5 -> V_66 = V_67 -> V_66 ;
V_5 -> V_68 = V_69 ;
} else
memset ( V_5 , 0 , sizeof( struct V_52 ) ) ;
}
static void F_65 ( struct V_1 * V_2 , void * V_14 )
{
if ( ! ( V_2 -> V_3 & V_70 ) )
return;
F_61 ( V_2 , V_14 , V_71 , 0UL ) ;
F_61 ( V_2 , V_14 , V_72 , 0UL ) ;
}
static void F_66 ( const char * V_2 , struct V_52 * V_73 )
{
if ( ! V_73 -> V_19 )
return;
F_67 ( L_2 ,
V_2 , ( void * ) V_73 -> V_19 , V_69 - V_73 -> V_68 , V_73 -> V_65 , V_73 -> V_66 ) ;
#ifdef F_62
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
if ( V_73 -> V_62 [ V_57 ] )
F_67 ( L_3 , ( void * ) V_73 -> V_62 [ V_57 ] ) ;
else
break;
}
#endif
}
static void F_68 ( struct V_1 * V_2 , void * V_14 )
{
if ( ! ( V_2 -> V_3 & V_70 ) )
return;
F_66 ( L_4 , F_60 ( V_2 , V_14 , V_72 ) ) ;
F_66 ( L_5 , F_60 ( V_2 , V_14 , V_71 ) ) ;
}
static void F_69 ( struct V_28 * V_28 )
{
F_67 ( L_6 ,
V_28 , V_28 -> V_35 , V_28 -> V_34 , V_28 -> V_43 , V_28 -> V_3 ) ;
}
static void F_70 ( struct V_1 * V_2 , char * V_74 , ... )
{
struct V_75 V_76 ;
T_3 args ;
va_start ( args , V_74 ) ;
V_76 . V_74 = V_74 ;
V_76 . V_77 = & args ;
F_67 ( L_7 ) ;
F_67 ( L_8 , V_2 -> V_45 , F_71 () , & V_76 ) ;
F_67 ( L_9 ) ;
F_72 ( V_78 , V_79 ) ;
va_end ( args ) ;
}
static void F_73 ( struct V_1 * V_2 , char * V_74 , ... )
{
struct V_75 V_76 ;
T_3 args ;
va_start ( args , V_74 ) ;
V_76 . V_74 = V_74 ;
V_76 . V_77 = & args ;
F_67 ( L_10 , V_2 -> V_45 , & V_76 ) ;
va_end ( args ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_28 * V_28 , T_2 * V_5 )
{
unsigned int V_80 ;
T_2 * V_19 = F_49 ( V_28 ) ;
F_68 ( V_2 , V_5 ) ;
F_69 ( V_28 ) ;
F_67 ( L_11 ,
V_5 , V_5 - V_19 , F_17 ( V_2 , V_5 ) ) ;
if ( V_2 -> V_3 & V_6 )
F_58 ( V_81 , L_12 , V_5 - V_2 -> V_7 ,
V_2 -> V_7 ) ;
else if ( V_5 > V_19 + 16 )
F_58 ( V_81 , L_13 , V_5 - 16 , 16 ) ;
F_58 ( V_81 , L_14 , V_5 ,
F_75 (unsigned long, s->object_size, PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_6 )
F_58 ( V_81 , L_12 , V_5 + V_2 -> V_82 ,
V_2 -> V_34 - V_2 -> V_82 ) ;
if ( V_2 -> V_15 )
V_80 = V_2 -> V_15 + sizeof( void * ) ;
else
V_80 = V_2 -> V_34 ;
if ( V_2 -> V_3 & V_70 )
V_80 += 2 * sizeof( struct V_52 ) ;
V_80 += F_76 ( V_2 ) ;
if ( V_80 != F_51 ( V_2 ) )
F_58 ( V_81 , L_15 , V_5 + V_80 ,
F_51 ( V_2 ) - V_80 ) ;
F_77 () ;
}
void F_78 ( struct V_1 * V_2 , struct V_28 * V_28 ,
T_2 * V_14 , char * V_83 )
{
F_70 ( V_2 , L_16 , V_83 ) ;
F_74 ( V_2 , V_28 , V_14 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_28 * V_28 ,
const char * V_74 , ... )
{
T_3 args ;
char V_84 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_84 , sizeof( V_84 ) , V_74 , args ) ;
va_end ( args ) ;
F_70 ( V_2 , L_16 , V_84 ) ;
F_69 ( V_28 ) ;
F_77 () ;
}
static void F_80 ( struct V_1 * V_2 , void * V_14 , T_2 V_85 )
{
T_2 * V_5 = V_14 ;
if ( V_2 -> V_3 & V_6 )
memset ( V_5 - V_2 -> V_7 , V_85 , V_2 -> V_7 ) ;
if ( V_2 -> V_3 & V_86 ) {
memset ( V_5 , V_87 , V_2 -> V_82 - 1 ) ;
V_5 [ V_2 -> V_82 - 1 ] = V_88 ;
}
if ( V_2 -> V_3 & V_6 )
memset ( V_5 + V_2 -> V_82 , V_85 , V_2 -> V_34 - V_2 -> V_82 ) ;
}
static void F_81 ( struct V_1 * V_2 , char * V_89 , T_2 V_90 ,
void * V_91 , void * V_92 )
{
F_73 ( V_2 , L_17 , V_91 , V_92 - 1 , V_90 ) ;
memset ( V_91 , V_90 , V_92 - V_91 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_28 * V_28 ,
T_2 * V_14 , char * V_93 ,
T_2 * V_94 , unsigned int V_95 , unsigned int V_96 )
{
T_2 * V_97 ;
T_2 * V_98 ;
F_53 () ;
V_97 = F_83 ( V_94 , V_95 , V_96 ) ;
F_55 () ;
if ( ! V_97 )
return 1 ;
V_98 = V_94 + V_96 ;
while ( V_98 > V_97 && V_98 [ - 1 ] == V_95 )
V_98 -- ;
F_70 ( V_2 , L_18 , V_93 ) ;
F_67 ( L_19 ,
V_97 , V_98 - 1 , V_97 [ 0 ] , V_95 ) ;
F_74 ( V_2 , V_28 , V_14 ) ;
F_81 ( V_2 , V_93 , V_95 , V_97 , V_98 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_28 * V_28 , T_2 * V_5 )
{
unsigned long V_80 = V_2 -> V_34 ;
if ( V_2 -> V_15 )
V_80 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_70 )
V_80 += 2 * sizeof( struct V_52 ) ;
V_80 += F_76 ( V_2 ) ;
if ( F_51 ( V_2 ) == V_80 )
return 1 ;
return F_82 ( V_2 , V_28 , V_5 , L_20 ,
V_5 + V_80 , V_99 , F_51 ( V_2 ) - V_80 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
T_2 * V_94 ;
T_2 * V_97 ;
T_2 * V_98 ;
int V_50 ;
int V_100 ;
if ( ! ( V_2 -> V_3 & V_101 ) )
return 1 ;
V_94 = F_49 ( V_28 ) ;
V_50 = ( V_23 << F_86 ( V_28 ) ) - V_2 -> V_22 ;
V_98 = V_94 + V_50 ;
V_100 = V_50 % V_2 -> V_20 ;
if ( ! V_100 )
return 1 ;
F_53 () ;
V_97 = F_83 ( V_98 - V_100 , V_99 , V_100 ) ;
F_55 () ;
if ( ! V_97 )
return 1 ;
while ( V_98 > V_97 && V_98 [ - 1 ] == V_99 )
V_98 -- ;
F_79 ( V_2 , V_28 , L_21 , V_97 , V_98 - 1 ) ;
F_58 ( V_81 , L_15 , V_98 - V_100 , V_100 ) ;
F_81 ( V_2 , L_22 , V_99 , V_98 - V_100 , V_98 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_14 , T_2 V_85 )
{
T_2 * V_5 = V_14 ;
T_2 * V_102 = V_14 + V_2 -> V_82 ;
if ( V_2 -> V_3 & V_6 ) {
if ( ! F_82 ( V_2 , V_28 , V_14 , L_23 ,
V_14 - V_2 -> V_7 , V_85 , V_2 -> V_7 ) )
return 0 ;
if ( ! F_82 ( V_2 , V_28 , V_14 , L_23 ,
V_102 , V_85 , V_2 -> V_34 - V_2 -> V_82 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_101 ) && V_2 -> V_82 < V_2 -> V_34 ) {
F_82 ( V_2 , V_28 , V_5 , L_24 ,
V_102 , V_99 ,
V_2 -> V_34 - V_2 -> V_82 ) ;
}
}
if ( V_2 -> V_3 & V_101 ) {
if ( V_85 != V_103 && ( V_2 -> V_3 & V_86 ) &&
( ! F_82 ( V_2 , V_28 , V_5 , L_25 , V_5 ,
V_87 , V_2 -> V_82 - 1 ) ||
! F_82 ( V_2 , V_28 , V_5 , L_25 ,
V_5 + V_2 -> V_82 - 1 , V_88 , 1 ) ) )
return 0 ;
F_84 ( V_2 , V_28 , V_5 ) ;
}
if ( ! V_2 -> V_15 && V_85 == V_103 )
return 1 ;
if ( ! F_57 ( V_2 , V_28 , F_17 ( V_2 , V_5 ) ) ) {
F_78 ( V_2 , V_28 , V_5 , L_26 ) ;
F_23 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
int V_104 ;
F_38 ( ! F_39 () ) ;
if ( ! F_89 ( V_28 ) ) {
F_79 ( V_2 , V_28 , L_27 ) ;
return 0 ;
}
V_104 = F_26 ( F_86 ( V_28 ) , V_2 -> V_20 , V_2 -> V_22 ) ;
if ( V_28 -> V_35 > V_104 ) {
F_79 ( V_2 , V_28 , L_28 ,
V_28 -> V_35 , V_104 ) ;
return 0 ;
}
if ( V_28 -> V_34 > V_28 -> V_35 ) {
F_79 ( V_2 , V_28 , L_29 ,
V_28 -> V_34 , V_28 -> V_35 ) ;
return 0 ;
}
F_85 ( V_2 , V_28 ) ;
return 1 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_28 * V_28 , void * V_105 )
{
int V_106 = 0 ;
void * V_17 ;
void * V_14 = NULL ;
int V_107 ;
V_17 = V_28 -> V_43 ;
while ( V_17 && V_106 <= V_28 -> V_35 ) {
if ( V_17 == V_105 )
return 1 ;
if ( ! F_57 ( V_2 , V_28 , V_17 ) ) {
if ( V_14 ) {
F_78 ( V_2 , V_28 , V_14 ,
L_30 ) ;
F_23 ( V_2 , V_14 , NULL ) ;
} else {
F_79 ( V_2 , V_28 , L_26 ) ;
V_28 -> V_43 = NULL ;
V_28 -> V_34 = V_28 -> V_35 ;
F_73 ( V_2 , L_31 ) ;
return 0 ;
}
break;
}
V_14 = V_17 ;
V_17 = F_17 ( V_2 , V_14 ) ;
V_106 ++ ;
}
V_107 = F_26 ( F_86 ( V_28 ) , V_2 -> V_20 , V_2 -> V_22 ) ;
if ( V_107 > V_108 )
V_107 = V_108 ;
if ( V_28 -> V_35 != V_107 ) {
F_79 ( V_2 , V_28 , L_32 ,
V_28 -> V_35 , V_107 ) ;
V_28 -> V_35 = V_107 ;
F_73 ( V_2 , L_33 ) ;
}
if ( V_28 -> V_34 != V_28 -> V_35 - V_106 ) {
F_79 ( V_2 , V_28 , L_34 ,
V_28 -> V_34 , V_28 -> V_35 - V_106 ) ;
V_28 -> V_34 = V_28 -> V_35 - V_106 ;
F_73 ( V_2 , L_35 ) ;
}
return V_105 == NULL ;
}
static void V_56 ( struct V_1 * V_2 , struct V_28 * V_28 , void * V_14 ,
int V_54 )
{
if ( V_2 -> V_3 & V_109 ) {
F_44 ( L_36 ,
V_2 -> V_45 ,
V_54 ? L_37 : L_38 ,
V_14 , V_28 -> V_34 ,
V_28 -> V_43 ) ;
if ( ! V_54 )
F_58 ( V_110 , L_14 , ( void * ) V_14 ,
V_2 -> V_82 ) ;
F_77 () ;
}
}
static void F_91 ( struct V_1 * V_2 ,
struct V_111 * V_39 , struct V_28 * V_28 )
{
if ( ! ( V_2 -> V_3 & V_70 ) )
return;
F_92 ( & V_39 -> V_112 ) ;
F_93 ( & V_28 -> V_113 , & V_39 -> V_114 ) ;
}
static void F_94 ( struct V_1 * V_2 , struct V_111 * V_39 , struct V_28 * V_28 )
{
if ( ! ( V_2 -> V_3 & V_70 ) )
return;
F_92 ( & V_39 -> V_112 ) ;
F_95 ( & V_28 -> V_113 ) ;
}
static inline unsigned long F_96 ( struct V_1 * V_2 , int V_115 )
{
struct V_111 * V_39 = F_97 ( V_2 , V_115 ) ;
return F_98 ( & V_39 -> V_116 ) ;
}
static inline unsigned long F_99 ( struct V_111 * V_39 )
{
return F_98 ( & V_39 -> V_116 ) ;
}
static inline void F_100 ( struct V_1 * V_2 , int V_115 , int V_35 )
{
struct V_111 * V_39 = F_97 ( V_2 , V_115 ) ;
if ( F_101 ( V_39 ) ) {
F_102 ( & V_39 -> V_116 ) ;
F_103 ( V_35 , & V_39 -> V_117 ) ;
}
}
static inline void F_104 ( struct V_1 * V_2 , int V_115 , int V_35 )
{
struct V_111 * V_39 = F_97 ( V_2 , V_115 ) ;
F_105 ( & V_39 -> V_116 ) ;
F_106 ( V_35 , & V_39 -> V_117 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_14 )
{
if ( ! ( V_2 -> V_3 & ( V_70 | V_6 | V_86 ) ) )
return;
F_80 ( V_2 , V_14 , V_118 ) ;
F_65 ( V_2 , V_14 ) ;
}
static inline int F_108 ( struct V_1 * V_2 ,
struct V_28 * V_28 ,
void * V_14 , unsigned long V_19 )
{
if ( ! F_88 ( V_2 , V_28 ) )
return 0 ;
if ( ! F_57 ( V_2 , V_28 , V_14 ) ) {
F_78 ( V_2 , V_28 , V_14 , L_39 ) ;
return 0 ;
}
if ( ! F_87 ( V_2 , V_28 , V_14 , V_118 ) )
return 0 ;
return 1 ;
}
static T_4 int F_109 ( struct V_1 * V_2 ,
struct V_28 * V_28 ,
void * V_14 , unsigned long V_19 )
{
if ( V_2 -> V_3 & V_119 ) {
if ( ! F_108 ( V_2 , V_28 , V_14 , V_19 ) )
goto V_120;
}
if ( V_2 -> V_3 & V_70 )
F_61 ( V_2 , V_14 , V_72 , V_19 ) ;
V_56 ( V_2 , V_28 , V_14 , 1 ) ;
F_80 ( V_2 , V_14 , V_103 ) ;
return 1 ;
V_120:
if ( F_89 ( V_28 ) ) {
F_73 ( V_2 , L_40 ) ;
V_28 -> V_34 = V_28 -> V_35 ;
V_28 -> V_43 = NULL ;
}
return 0 ;
}
static inline int F_110 ( struct V_1 * V_2 ,
struct V_28 * V_28 , void * V_14 , unsigned long V_19 )
{
if ( ! F_57 ( V_2 , V_28 , V_14 ) ) {
F_79 ( V_2 , V_28 , L_41 , V_14 ) ;
return 0 ;
}
if ( F_90 ( V_2 , V_28 , V_14 ) ) {
F_78 ( V_2 , V_28 , V_14 , L_42 ) ;
return 0 ;
}
if ( ! F_87 ( V_2 , V_28 , V_14 , V_103 ) )
return 0 ;
if ( F_3 ( V_2 != V_28 -> V_121 ) ) {
if ( ! F_89 ( V_28 ) ) {
F_79 ( V_2 , V_28 , L_43 ,
V_14 ) ;
} else if ( ! V_28 -> V_121 ) {
F_67 ( L_44 ,
V_14 ) ;
F_77 () ;
} else
F_78 ( V_2 , V_28 , V_14 ,
L_45 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_111 (
struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_122 , void * V_123 , int V_124 ,
unsigned long V_19 )
{
struct V_111 * V_39 = F_97 ( V_2 , F_112 ( V_28 ) ) ;
void * V_14 = V_122 ;
int V_125 = 0 ;
unsigned long V_126 ( V_3 ) ;
int V_127 = 0 ;
F_113 ( & V_39 -> V_112 , V_3 ) ;
F_30 ( V_28 ) ;
if ( V_2 -> V_3 & V_119 ) {
if ( ! F_88 ( V_2 , V_28 ) )
goto V_128;
}
V_129:
V_125 ++ ;
if ( V_2 -> V_3 & V_119 ) {
if ( ! F_110 ( V_2 , V_28 , V_14 , V_19 ) )
goto V_128;
}
if ( V_2 -> V_3 & V_70 )
F_61 ( V_2 , V_14 , V_71 , V_19 ) ;
V_56 ( V_2 , V_28 , V_14 , 0 ) ;
F_80 ( V_2 , V_14 , V_118 ) ;
if ( V_14 != V_123 ) {
V_14 = F_17 ( V_2 , V_14 ) ;
goto V_129;
}
V_127 = 1 ;
V_128:
if ( V_125 != V_124 )
F_79 ( V_2 , V_28 , L_46 ,
V_124 , V_125 ) ;
F_34 ( V_28 ) ;
F_114 ( & V_39 -> V_112 , V_3 ) ;
if ( ! V_127 )
F_73 ( V_2 , L_47 , V_14 ) ;
return V_127 ;
}
static int T_5 F_115 ( char * V_130 )
{
V_131 = V_132 ;
if ( * V_130 ++ != '=' || ! * V_130 )
goto V_128;
if ( * V_130 == ',' )
goto V_133;
V_131 = 0 ;
if ( * V_130 == '-' )
goto V_128;
for (; * V_130 && * V_130 != ',' ; V_130 ++ ) {
switch ( tolower ( * V_130 ) ) {
case 'f' :
V_131 |= V_119 ;
break;
case 'z' :
V_131 |= V_6 ;
break;
case 'p' :
V_131 |= V_101 ;
break;
case 'u' :
V_131 |= V_70 ;
break;
case 't' :
V_131 |= V_109 ;
break;
case 'a' :
V_131 |= V_134 ;
break;
case 'o' :
V_135 = 1 ;
break;
default:
F_67 ( L_48 ,
* V_130 ) ;
}
}
V_133:
if ( * V_130 == ',' )
V_136 = V_130 + 1 ;
V_128:
return 1 ;
}
unsigned long F_116 ( unsigned long V_82 ,
unsigned long V_3 , const char * V_45 ,
void (* F_117)( void * ) )
{
if ( V_131 && ( ! V_136 || ( V_45 &&
! strncmp ( V_136 , V_45 , strlen ( V_136 ) ) ) ) )
V_3 |= V_131 ;
return V_3 ;
}
static inline void F_107 ( struct V_1 * V_2 ,
struct V_28 * V_28 , void * V_14 ) {}
static inline int F_109 ( struct V_1 * V_2 ,
struct V_28 * V_28 , void * V_14 , unsigned long V_19 ) { return 0 ; }
static inline int F_111 (
struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_122 , void * V_123 , int V_124 ,
unsigned long V_19 ) { return 0 ; }
static inline int F_85 ( struct V_1 * V_2 , struct V_28 * V_28 )
{ return 1 ; }
static inline int F_87 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_14 , T_2 V_85 ) { return 1 ; }
static inline void F_91 ( struct V_1 * V_2 , struct V_111 * V_39 ,
struct V_28 * V_28 ) {}
static inline void F_94 ( struct V_1 * V_2 , struct V_111 * V_39 ,
struct V_28 * V_28 ) {}
unsigned long F_116 ( unsigned long V_82 ,
unsigned long V_3 , const char * V_45 ,
void (* F_117)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_96 ( struct V_1 * V_2 , int V_115 )
{ return 0 ; }
static inline unsigned long F_99 ( struct V_111 * V_39 )
{ return 0 ; }
static inline void F_100 ( struct V_1 * V_2 , int V_115 ,
int V_35 ) {}
static inline void F_104 ( struct V_1 * V_2 , int V_115 ,
int V_35 ) {}
static inline void F_118 ( void * V_11 , T_6 V_20 , T_7 V_3 )
{
F_119 ( V_11 , V_20 , 1 , V_3 ) ;
F_120 ( V_11 , V_20 , V_3 ) ;
}
static inline void F_121 ( const void * V_25 )
{
F_122 ( V_25 ) ;
F_123 ( V_25 ) ;
}
static inline void * F_124 ( struct V_1 * V_2 , void * V_25 )
{
void * V_137 ;
F_125 ( V_25 , V_2 -> V_3 ) ;
#if F_40 ( V_138 ) || F_40 ( V_139 )
{
unsigned long V_3 ;
F_46 ( V_3 ) ;
F_126 ( V_2 , V_25 , V_2 -> V_82 ) ;
F_127 ( V_25 , V_2 -> V_82 ) ;
F_47 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_140 ) )
F_128 ( V_25 , V_2 -> V_82 ) ;
V_137 = F_17 ( V_2 , V_25 ) ;
F_129 ( V_2 , V_25 ) ;
return V_137 ;
}
static inline void F_130 ( struct V_1 * V_2 ,
void * V_122 , void * V_123 )
{
#if F_40 ( V_138 ) || \
F_40 ( V_139 ) || \
F_40 ( V_141 ) || \
F_40 ( V_142 ) || \
F_40 ( V_143 )
void * V_14 = V_122 ;
void * V_144 = V_123 ? : V_122 ;
void * V_137 ;
do {
V_137 = F_124 ( V_2 , V_14 ) ;
} while ( ( V_14 != V_144 ) && ( V_14 = V_137 ) );
#endif
}
static void F_131 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_14 )
{
F_107 ( V_2 , V_28 , V_14 ) ;
F_132 ( V_2 , V_14 ) ;
if ( F_3 ( V_2 -> F_117 ) ) {
F_133 ( V_2 , V_14 ) ;
V_2 -> F_117 ( V_14 ) ;
F_134 ( V_2 , V_14 ) ;
}
}
static inline struct V_28 * F_135 ( struct V_1 * V_2 ,
T_7 V_3 , int V_115 , struct V_24 V_145 )
{
struct V_28 * V_28 ;
int V_21 = F_28 ( V_145 ) ;
V_3 |= V_146 ;
if ( V_115 == V_147 )
V_28 = F_136 ( V_3 , V_21 ) ;
else
V_28 = F_137 ( V_115 , V_3 , V_21 ) ;
if ( V_28 && F_138 ( V_28 , V_3 , V_21 , V_2 ) ) {
F_139 ( V_28 , V_21 ) ;
V_28 = NULL ;
}
return V_28 ;
}
static int F_140 ( struct V_1 * V_2 )
{
int V_148 ;
unsigned long V_57 , V_149 = F_29 ( V_2 -> V_145 ) ;
if ( V_2 -> V_150 )
return 0 ;
V_148 = F_141 ( V_2 , V_149 , V_151 ) ;
if ( V_148 ) {
F_67 ( L_49 ,
V_2 -> V_45 ) ;
return V_148 ;
}
if ( V_2 -> V_150 ) {
for ( V_57 = 0 ; V_57 < V_149 ; V_57 ++ )
V_2 -> V_150 [ V_57 ] *= V_2 -> V_20 ;
}
return 0 ;
}
static void T_5 F_142 ( void )
{
struct V_1 * V_2 ;
F_143 ( & V_152 ) ;
F_144 (s, &slab_caches, list)
F_140 ( V_2 ) ;
F_145 ( & V_152 ) ;
}
static void * F_146 ( struct V_1 * V_2 , struct V_28 * V_28 ,
unsigned long * V_153 , void * V_94 ,
unsigned long V_154 ,
unsigned long V_155 )
{
unsigned int V_156 ;
do {
V_156 = V_2 -> V_150 [ * V_153 ] ;
* V_153 += 1 ;
if ( * V_153 >= V_155 )
* V_153 = 0 ;
} while ( F_3 ( V_156 >= V_154 ) );
return ( char * ) V_94 + V_156 ;
}
static bool F_147 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
void * V_94 ;
void * V_157 ;
void * V_158 ;
unsigned long V_156 , V_153 , V_154 , V_155 ;
if ( V_28 -> V_35 < 2 || ! V_2 -> V_150 )
return false ;
V_155 = F_29 ( V_2 -> V_145 ) ;
V_153 = F_148 () % V_155 ;
V_154 = V_28 -> V_35 * V_2 -> V_20 ;
V_94 = F_4 ( V_2 , F_49 ( V_28 ) ) ;
V_157 = F_146 ( V_2 , V_28 , & V_153 , V_94 , V_154 ,
V_155 ) ;
V_28 -> V_43 = V_157 ;
for ( V_156 = 1 ; V_156 < V_28 -> V_35 ; V_156 ++ ) {
F_131 ( V_2 , V_28 , V_157 ) ;
V_158 = F_146 ( V_2 , V_28 , & V_153 , V_94 , V_154 ,
V_155 ) ;
F_23 ( V_2 , V_157 , V_158 ) ;
V_157 = V_158 ;
}
F_131 ( V_2 , V_28 , V_157 ) ;
F_23 ( V_2 , V_157 , NULL ) ;
return true ;
}
static inline int F_140 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_142 ( void ) { }
static inline bool F_147 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
return false ;
}
static struct V_28 * F_149 ( struct V_1 * V_2 , T_7 V_3 , int V_115 )
{
struct V_28 * V_28 ;
struct V_24 V_145 = V_2 -> V_145 ;
T_7 V_159 ;
void * V_94 , * V_5 ;
int V_156 , V_21 ;
bool V_160 ;
V_3 &= V_161 ;
if ( F_150 ( V_3 ) )
F_151 () ;
V_3 |= V_2 -> V_162 ;
V_159 = ( V_3 | V_163 | V_164 ) & ~ V_165 ;
if ( ( V_159 & V_166 ) && F_28 ( V_145 ) > F_28 ( V_2 -> V_167 ) )
V_159 = ( V_159 | V_168 ) & ~ ( V_169 | V_165 ) ;
V_28 = F_135 ( V_2 , V_159 , V_115 , V_145 ) ;
if ( F_3 ( ! V_28 ) ) {
V_145 = V_2 -> V_167 ;
V_159 = V_3 ;
V_28 = F_135 ( V_2 , V_159 , V_115 , V_145 ) ;
if ( F_3 ( ! V_28 ) )
goto V_128;
F_11 ( V_2 , V_170 ) ;
}
if ( V_171 &&
! ( V_2 -> V_3 & ( V_172 | V_132 ) ) ) {
int V_173 = 1 << F_28 ( V_145 ) ;
F_152 ( V_28 , F_28 ( V_145 ) , V_159 , V_115 ) ;
if ( V_2 -> F_117 )
F_153 ( V_28 , V_173 ) ;
else
F_154 ( V_28 , V_173 ) ;
}
V_28 -> V_35 = F_29 ( V_145 ) ;
V_21 = F_86 ( V_28 ) ;
V_28 -> V_121 = V_2 ;
F_155 ( V_28 ) ;
if ( F_156 ( V_28 ) )
F_157 ( V_28 ) ;
V_94 = F_49 ( V_28 ) ;
if ( F_3 ( V_2 -> V_3 & V_101 ) )
memset ( V_94 , V_99 , V_23 << V_21 ) ;
F_158 ( V_28 ) ;
V_160 = F_147 ( V_2 , V_28 ) ;
if ( ! V_160 ) {
F_159 (p, idx, s, start, page->objects) {
F_131 ( V_2 , V_28 , V_5 ) ;
if ( F_101 ( V_156 < V_28 -> V_35 ) )
F_23 ( V_2 , V_5 , V_5 + V_2 -> V_20 ) ;
else
F_23 ( V_2 , V_5 , NULL ) ;
}
V_28 -> V_43 = F_4 ( V_2 , V_94 ) ;
}
V_28 -> V_34 = V_28 -> V_35 ;
V_28 -> V_33 = 1 ;
V_128:
if ( F_150 ( V_3 ) )
F_160 () ;
if ( ! V_28 )
return NULL ;
F_161 ( V_28 ,
( V_2 -> V_3 & V_174 ) ?
V_175 : V_176 ,
1 << F_28 ( V_145 ) ) ;
F_100 ( V_2 , F_112 ( V_28 ) , V_28 -> V_35 ) ;
return V_28 ;
}
static struct V_28 * F_162 ( struct V_1 * V_2 , T_7 V_3 , int V_115 )
{
if ( F_3 ( V_3 & V_177 ) ) {
T_7 V_178 = V_3 & V_177 ;
V_3 &= ~ V_177 ;
F_163 ( L_50 ,
V_178 , & V_178 , V_3 , & V_3 ) ;
F_77 () ;
}
return F_149 ( V_2 ,
V_3 & ( V_179 | V_180 ) , V_115 ) ;
}
static void F_164 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
int V_21 = F_86 ( V_28 ) ;
int V_173 = 1 << V_21 ;
if ( V_2 -> V_3 & V_119 ) {
void * V_5 ;
F_85 ( V_2 , V_28 ) ;
F_165 (p, s, page_address(page),
page->objects)
F_87 ( V_2 , V_28 , V_5 , V_118 ) ;
}
F_166 ( V_28 , F_86 ( V_28 ) ) ;
F_161 ( V_28 ,
( V_2 -> V_3 & V_174 ) ?
V_175 : V_176 ,
- V_173 ) ;
F_167 ( V_28 ) ;
F_168 ( V_28 ) ;
F_169 ( V_28 ) ;
if ( V_67 -> V_181 )
V_67 -> V_181 -> V_182 += V_173 ;
F_170 ( V_28 , V_21 , V_2 ) ;
F_139 ( V_28 , V_21 ) ;
}
static void F_171 ( struct V_183 * V_184 )
{
struct V_28 * V_28 ;
if ( V_185 )
V_28 = F_172 ( V_184 ) ;
else
V_28 = F_173 ( (struct V_186 * ) V_184 , struct V_28 , V_113 ) ;
F_164 ( V_28 -> V_121 , V_28 ) ;
}
static void F_174 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
if ( F_3 ( V_2 -> V_3 & V_187 ) ) {
struct V_183 * V_122 ;
if ( V_185 ) {
int V_21 = F_86 ( V_28 ) ;
int V_15 = ( V_23 << V_21 ) - V_2 -> V_22 ;
F_38 ( V_2 -> V_22 != sizeof( * V_122 ) ) ;
V_122 = F_49 ( V_28 ) + V_15 ;
} else {
V_122 = & V_28 -> V_183 ;
}
F_175 ( V_122 , F_171 ) ;
} else
F_164 ( V_2 , V_28 ) ;
}
static void F_176 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
F_104 ( V_2 , F_112 ( V_28 ) , V_28 -> V_35 ) ;
F_174 ( V_2 , V_28 ) ;
}
static inline void
F_177 ( struct V_111 * V_39 , struct V_28 * V_28 , int V_123 )
{
V_39 -> V_188 ++ ;
if ( V_123 == V_189 )
F_178 ( & V_28 -> V_113 , & V_39 -> V_190 ) ;
else
F_93 ( & V_28 -> V_113 , & V_39 -> V_190 ) ;
}
static inline void F_179 ( struct V_111 * V_39 ,
struct V_28 * V_28 , int V_123 )
{
F_92 ( & V_39 -> V_112 ) ;
F_177 ( V_39 , V_28 , V_123 ) ;
}
static inline void F_180 ( struct V_111 * V_39 ,
struct V_28 * V_28 )
{
F_92 ( & V_39 -> V_112 ) ;
F_95 ( & V_28 -> V_113 ) ;
V_39 -> V_188 -- ;
}
static inline void * F_181 ( struct V_1 * V_2 ,
struct V_111 * V_39 , struct V_28 * V_28 ,
int V_191 , int * V_35 )
{
void * V_43 ;
unsigned long V_32 ;
struct V_28 V_192 ;
F_92 ( & V_39 -> V_112 ) ;
V_43 = V_28 -> V_43 ;
V_32 = V_28 -> V_32 ;
V_192 . V_32 = V_32 ;
* V_35 = V_192 . V_35 - V_192 . V_34 ;
if ( V_191 ) {
V_192 . V_34 = V_28 -> V_35 ;
V_192 . V_43 = NULL ;
} else {
V_192 . V_43 = V_43 ;
}
F_38 ( V_192 . V_33 ) ;
V_192 . V_33 = 1 ;
if ( ! F_37 ( V_2 , V_28 ,
V_43 , V_32 ,
V_192 . V_43 , V_192 . V_32 ,
L_51 ) )
return NULL ;
F_180 ( V_39 , V_28 ) ;
F_182 ( ! V_43 ) ;
return V_43 ;
}
static void * F_183 ( struct V_1 * V_2 , struct V_111 * V_39 ,
struct V_193 * V_194 , T_7 V_3 )
{
struct V_28 * V_28 , * V_195 ;
void * V_14 = NULL ;
int V_196 = 0 ;
int V_35 ;
if ( ! V_39 || ! V_39 -> V_188 )
return NULL ;
F_184 ( & V_39 -> V_112 ) ;
F_185 (page, page2, &n->partial, lru) {
void * V_73 ;
if ( ! F_186 ( V_28 , V_3 ) )
continue;
V_73 = F_181 ( V_2 , V_39 , V_28 , V_14 == NULL , & V_35 ) ;
if ( ! V_73 )
break;
V_196 += V_35 ;
if ( ! V_14 ) {
V_194 -> V_28 = V_28 ;
F_11 ( V_2 , V_197 ) ;
V_14 = V_73 ;
} else {
F_187 ( V_2 , V_28 , 0 ) ;
F_11 ( V_2 , V_198 ) ;
}
if ( ! F_5 ( V_2 )
|| V_196 > F_188 ( V_2 ) / 2 )
break;
}
F_189 ( & V_39 -> V_112 ) ;
return V_14 ;
}
static void * F_190 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_193 * V_194 )
{
#ifdef F_191
struct V_199 * V_199 ;
struct V_200 * V_201 ;
struct V_202 * V_202 ;
enum V_203 V_204 = F_192 ( V_3 ) ;
void * V_14 ;
unsigned int V_205 ;
if ( ! V_2 -> V_206 ||
F_193 () % 1024 > V_2 -> V_206 )
return NULL ;
do {
V_205 = F_194 () ;
V_199 = F_195 ( F_196 () , V_3 ) ;
F_197 (zone, z, zonelist, high_zoneidx) {
struct V_111 * V_39 ;
V_39 = F_97 ( V_2 , F_198 ( V_202 ) ) ;
if ( V_39 && F_199 ( V_202 , V_3 ) &&
V_39 -> V_188 > V_2 -> V_207 ) {
V_14 = F_183 ( V_2 , V_39 , V_194 , V_3 ) ;
if ( V_14 ) {
return V_14 ;
}
}
}
} while ( F_200 ( V_205 ) );
#endif
return NULL ;
}
static void * F_201 ( struct V_1 * V_2 , T_7 V_3 , int V_115 ,
struct V_193 * V_194 )
{
void * V_14 ;
int V_208 = V_115 ;
if ( V_115 == V_147 )
V_208 = F_202 () ;
else if ( ! F_203 ( V_115 ) )
V_208 = F_204 ( V_115 ) ;
V_14 = F_183 ( V_2 , F_97 ( V_2 , V_208 ) , V_194 , V_3 ) ;
if ( V_14 || V_115 != V_147 )
return V_14 ;
return F_190 ( V_2 , V_3 , V_194 ) ;
}
static inline unsigned long F_205 ( unsigned long V_209 )
{
return V_209 + V_210 ;
}
static inline unsigned int F_206 ( unsigned long V_209 )
{
return V_209 % V_210 ;
}
static inline unsigned long F_207 ( unsigned long V_209 )
{
return V_209 / V_210 ;
}
static inline unsigned int F_208 ( int V_65 )
{
return V_65 ;
}
static inline void F_209 ( const char * V_39 ,
const struct V_1 * V_2 , unsigned long V_209 )
{
#ifdef F_43
unsigned long V_211 = F_210 ( V_2 -> V_10 -> V_209 ) ;
F_44 ( L_52 , V_39 , V_2 -> V_45 ) ;
#ifdef F_211
if ( F_206 ( V_209 ) != F_206 ( V_211 ) )
F_163 ( L_53 ,
F_206 ( V_209 ) , F_206 ( V_211 ) ) ;
else
#endif
if ( F_207 ( V_209 ) != F_207 ( V_211 ) )
F_163 ( L_54 ,
F_207 ( V_209 ) , F_207 ( V_211 ) ) ;
else
F_163 ( L_55 ,
V_211 , V_209 , F_205 ( V_209 ) ) ;
#endif
F_11 ( V_2 , V_212 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
int V_65 ;
F_213 (cpu)
F_214 ( V_2 -> V_10 , V_65 ) -> V_209 = F_208 ( V_65 ) ;
}
static void F_215 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_43 , struct V_193 * V_194 )
{
enum T_8 { V_213 , V_214 , V_215 , V_216 };
struct V_111 * V_39 = F_97 ( V_2 , F_112 ( V_28 ) ) ;
int V_217 = 0 ;
enum T_8 V_218 = V_213 , V_219 = V_213 ;
void * V_220 ;
int V_123 = V_221 ;
struct V_28 V_192 ;
struct V_28 V_222 ;
if ( V_28 -> V_43 ) {
F_11 ( V_2 , V_223 ) ;
V_123 = V_189 ;
}
while ( V_43 && ( V_220 = F_17 ( V_2 , V_43 ) ) ) {
void * V_224 ;
unsigned long V_32 ;
do {
V_224 = V_28 -> V_43 ;
V_32 = V_28 -> V_32 ;
F_23 ( V_2 , V_43 , V_224 ) ;
V_192 . V_32 = V_32 ;
V_192 . V_34 -- ;
F_38 ( ! V_192 . V_33 ) ;
} while ( ! F_37 ( V_2 , V_28 ,
V_224 , V_32 ,
V_43 , V_192 . V_32 ,
L_56 ) );
V_43 = V_220 ;
}
V_225:
V_222 . V_43 = V_28 -> V_43 ;
V_222 . V_32 = V_28 -> V_32 ;
F_38 ( ! V_222 . V_33 ) ;
V_192 . V_32 = V_222 . V_32 ;
if ( V_43 ) {
V_192 . V_34 -- ;
F_23 ( V_2 , V_43 , V_222 . V_43 ) ;
V_192 . V_43 = V_43 ;
} else
V_192 . V_43 = V_222 . V_43 ;
V_192 . V_33 = 0 ;
if ( ! V_192 . V_34 && V_39 -> V_188 >= V_2 -> V_207 )
V_219 = V_216 ;
else if ( V_192 . V_43 ) {
V_219 = V_214 ;
if ( ! V_217 ) {
V_217 = 1 ;
F_184 ( & V_39 -> V_112 ) ;
}
} else {
V_219 = V_215 ;
if ( F_1 ( V_2 ) && ! V_217 ) {
V_217 = 1 ;
F_184 ( & V_39 -> V_112 ) ;
}
}
if ( V_218 != V_219 ) {
if ( V_218 == V_214 )
F_180 ( V_39 , V_28 ) ;
else if ( V_218 == V_215 )
F_94 ( V_2 , V_39 , V_28 ) ;
if ( V_219 == V_214 ) {
F_179 ( V_39 , V_28 , V_123 ) ;
F_11 ( V_2 , V_123 ) ;
} else if ( V_219 == V_215 ) {
F_11 ( V_2 , V_226 ) ;
F_91 ( V_2 , V_39 , V_28 ) ;
}
}
V_218 = V_219 ;
if ( ! F_37 ( V_2 , V_28 ,
V_222 . V_43 , V_222 . V_32 ,
V_192 . V_43 , V_192 . V_32 ,
L_57 ) )
goto V_225;
if ( V_217 )
F_189 ( & V_39 -> V_112 ) ;
if ( V_219 == V_216 ) {
F_11 ( V_2 , V_227 ) ;
F_176 ( V_2 , V_28 ) ;
F_11 ( V_2 , V_228 ) ;
}
V_194 -> V_28 = NULL ;
V_194 -> V_43 = NULL ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
#ifdef F_6
struct V_111 * V_39 = NULL , * V_229 = NULL ;
struct V_28 * V_28 , * V_230 = NULL ;
while ( ( V_28 = V_194 -> V_190 ) ) {
struct V_28 V_192 ;
struct V_28 V_222 ;
V_194 -> V_190 = V_28 -> V_158 ;
V_229 = F_97 ( V_2 , F_112 ( V_28 ) ) ;
if ( V_39 != V_229 ) {
if ( V_39 )
F_189 ( & V_39 -> V_112 ) ;
V_39 = V_229 ;
F_184 ( & V_39 -> V_112 ) ;
}
do {
V_222 . V_43 = V_28 -> V_43 ;
V_222 . V_32 = V_28 -> V_32 ;
F_38 ( ! V_222 . V_33 ) ;
V_192 . V_32 = V_222 . V_32 ;
V_192 . V_43 = V_222 . V_43 ;
V_192 . V_33 = 0 ;
} while ( ! F_37 ( V_2 , V_28 ,
V_222 . V_43 , V_222 . V_32 ,
V_192 . V_43 , V_192 . V_32 ,
L_57 ) );
if ( F_3 ( ! V_192 . V_34 && V_39 -> V_188 >= V_2 -> V_207 ) ) {
V_28 -> V_158 = V_230 ;
V_230 = V_28 ;
} else {
F_179 ( V_39 , V_28 , V_189 ) ;
F_11 ( V_2 , V_231 ) ;
}
}
if ( V_39 )
F_189 ( & V_39 -> V_112 ) ;
while ( V_230 ) {
V_28 = V_230 ;
V_230 = V_230 -> V_158 ;
F_11 ( V_2 , V_227 ) ;
F_176 ( V_2 , V_28 ) ;
F_11 ( V_2 , V_228 ) ;
}
#endif
}
static void F_187 ( struct V_1 * V_2 , struct V_28 * V_28 , int V_232 )
{
#ifdef F_6
struct V_28 * V_233 ;
int V_173 ;
int V_234 ;
F_217 () ;
do {
V_173 = 0 ;
V_234 = 0 ;
V_233 = F_218 ( V_2 -> V_10 -> V_190 ) ;
if ( V_233 ) {
V_234 = V_233 -> V_234 ;
V_173 = V_233 -> V_173 ;
if ( V_232 && V_234 > V_2 -> V_235 ) {
unsigned long V_3 ;
F_46 ( V_3 ) ;
F_216 ( V_2 , F_219 ( V_2 -> V_10 ) ) ;
F_47 ( V_3 ) ;
V_233 = NULL ;
V_234 = 0 ;
V_173 = 0 ;
F_11 ( V_2 , V_236 ) ;
}
}
V_173 ++ ;
V_234 += V_28 -> V_35 - V_28 -> V_34 ;
V_28 -> V_173 = V_173 ;
V_28 -> V_234 = V_234 ;
V_28 -> V_158 = V_233 ;
} while ( F_220 ( V_2 -> V_10 -> V_190 , V_233 , V_28 )
!= V_233 );
if ( F_3 ( ! V_2 -> V_235 ) ) {
unsigned long V_3 ;
F_46 ( V_3 ) ;
F_216 ( V_2 , F_219 ( V_2 -> V_10 ) ) ;
F_47 ( V_3 ) ;
}
F_221 () ;
#endif
}
static inline void F_222 ( struct V_1 * V_2 , struct V_193 * V_194 )
{
F_11 ( V_2 , V_237 ) ;
F_215 ( V_2 , V_194 -> V_28 , V_194 -> V_43 , V_194 ) ;
V_194 -> V_209 = F_205 ( V_194 -> V_209 ) ;
}
static inline void F_223 ( struct V_1 * V_2 , int V_65 )
{
struct V_193 * V_194 = F_214 ( V_2 -> V_10 , V_65 ) ;
if ( F_101 ( V_194 ) ) {
if ( V_194 -> V_28 )
F_222 ( V_2 , V_194 ) ;
F_216 ( V_2 , V_194 ) ;
}
}
static void F_224 ( void * V_238 )
{
struct V_1 * V_2 = V_238 ;
F_223 ( V_2 , F_64 () ) ;
}
static bool F_225 ( int V_65 , void * V_239 )
{
struct V_1 * V_2 = V_239 ;
struct V_193 * V_194 = F_214 ( V_2 -> V_10 , V_65 ) ;
return V_194 -> V_28 || F_226 ( V_194 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
F_228 ( F_225 , F_224 , V_2 , 1 , V_240 ) ;
}
static int F_229 ( unsigned int V_65 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
F_143 ( & V_152 ) ;
F_144 (s, &slab_caches, list) {
F_46 ( V_3 ) ;
F_223 ( V_2 , V_65 ) ;
F_47 ( V_3 ) ;
}
F_145 ( & V_152 ) ;
return 0 ;
}
static inline int F_230 ( struct V_28 * V_28 , int V_115 )
{
#ifdef F_191
if ( ! V_28 || ( V_115 != V_147 && F_112 ( V_28 ) != V_115 ) )
return 0 ;
#endif
return 1 ;
}
static int F_231 ( struct V_28 * V_28 )
{
return V_28 -> V_35 - V_28 -> V_34 ;
}
static inline unsigned long F_232 ( struct V_111 * V_39 )
{
return F_98 ( & V_39 -> V_117 ) ;
}
static unsigned long F_233 ( struct V_111 * V_39 ,
int (* F_234)( struct V_28 * ) )
{
unsigned long V_3 ;
unsigned long V_25 = 0 ;
struct V_28 * V_28 ;
F_113 ( & V_39 -> V_112 , V_3 ) ;
F_144 (page, &n->partial, lru)
V_25 += F_234 ( V_28 ) ;
F_114 ( & V_39 -> V_112 , V_3 ) ;
return V_25 ;
}
static T_4 void
F_235 ( struct V_1 * V_2 , T_7 V_241 , int V_242 )
{
#ifdef F_2
static F_236 ( V_243 , V_244 ,
V_245 ) ;
int V_115 ;
struct V_111 * V_39 ;
if ( ( V_241 & V_163 ) || ! F_237 ( & V_243 ) )
return;
F_163 ( L_58 ,
V_242 , V_241 , & V_241 ) ;
F_163 ( L_59 ,
V_2 -> V_45 , V_2 -> V_82 , V_2 -> V_20 , F_28 ( V_2 -> V_145 ) ,
F_28 ( V_2 -> V_167 ) ) ;
if ( F_28 ( V_2 -> V_167 ) > F_238 ( V_2 -> V_82 ) )
F_163 ( L_60 ,
V_2 -> V_45 ) ;
F_239 (s, node, n) {
unsigned long V_116 ;
unsigned long V_246 ;
unsigned long V_247 ;
V_247 = F_233 ( V_39 , F_231 ) ;
V_116 = F_99 ( V_39 ) ;
V_246 = F_232 ( V_39 ) ;
F_163 ( L_61 ,
V_115 , V_116 , V_246 , V_247 ) ;
}
#endif
}
static inline void * F_240 ( struct V_1 * V_2 , T_7 V_3 ,
int V_115 , struct V_193 * * V_248 )
{
void * V_43 ;
struct V_193 * V_194 = * V_248 ;
struct V_28 * V_28 ;
V_43 = F_201 ( V_2 , V_3 , V_115 , V_194 ) ;
if ( V_43 )
return V_43 ;
V_28 = F_162 ( V_2 , V_3 , V_115 ) ;
if ( V_28 ) {
V_194 = F_241 ( V_2 -> V_10 ) ;
if ( V_194 -> V_28 )
F_222 ( V_2 , V_194 ) ;
V_43 = V_28 -> V_43 ;
V_28 -> V_43 = NULL ;
F_11 ( V_2 , V_249 ) ;
V_194 -> V_28 = V_28 ;
* V_248 = V_194 ;
} else
V_43 = NULL ;
return V_43 ;
}
static inline bool F_186 ( struct V_28 * V_28 , T_7 V_241 )
{
if ( F_3 ( F_242 ( V_28 ) ) )
return F_243 ( V_241 ) ;
return true ;
}
static inline void * F_244 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
struct V_28 V_192 ;
unsigned long V_32 ;
void * V_43 ;
do {
V_43 = V_28 -> V_43 ;
V_32 = V_28 -> V_32 ;
V_192 . V_32 = V_32 ;
F_38 ( ! V_192 . V_33 ) ;
V_192 . V_34 = V_28 -> V_35 ;
V_192 . V_33 = V_43 != NULL ;
} while ( ! F_37 ( V_2 , V_28 ,
V_43 , V_32 ,
NULL , V_192 . V_32 ,
L_62 ) );
return V_43 ;
}
static void * F_245 ( struct V_1 * V_2 , T_7 V_241 , int V_115 ,
unsigned long V_19 , struct V_193 * V_194 )
{
void * V_43 ;
struct V_28 * V_28 ;
V_28 = V_194 -> V_28 ;
if ( ! V_28 )
goto F_162;
V_225:
if ( F_3 ( ! F_230 ( V_28 , V_115 ) ) ) {
int V_208 = V_115 ;
if ( V_115 != V_147 && ! F_203 ( V_115 ) )
V_208 = F_204 ( V_115 ) ;
if ( F_3 ( ! F_230 ( V_28 , V_208 ) ) ) {
F_11 ( V_2 , V_250 ) ;
F_215 ( V_2 , V_28 , V_194 -> V_43 , V_194 ) ;
goto F_162;
}
}
if ( F_3 ( ! F_186 ( V_28 , V_241 ) ) ) {
F_215 ( V_2 , V_28 , V_194 -> V_43 , V_194 ) ;
goto F_162;
}
V_43 = V_194 -> V_43 ;
if ( V_43 )
goto V_251;
V_43 = F_244 ( V_2 , V_28 ) ;
if ( ! V_43 ) {
V_194 -> V_28 = NULL ;
F_11 ( V_2 , V_252 ) ;
goto F_162;
}
F_11 ( V_2 , V_253 ) ;
V_251:
F_38 ( ! V_194 -> V_28 -> V_33 ) ;
V_194 -> V_43 = F_17 ( V_2 , V_43 ) ;
V_194 -> V_209 = F_205 ( V_194 -> V_209 ) ;
return V_43 ;
F_162:
if ( F_226 ( V_194 ) ) {
V_28 = V_194 -> V_28 = F_226 ( V_194 ) ;
F_246 ( V_194 , V_28 ) ;
F_11 ( V_2 , V_254 ) ;
goto V_225;
}
V_43 = F_240 ( V_2 , V_241 , V_115 , & V_194 ) ;
if ( F_3 ( ! V_43 ) ) {
F_235 ( V_2 , V_241 , V_115 ) ;
return NULL ;
}
V_28 = V_194 -> V_28 ;
if ( F_101 ( ! F_1 ( V_2 ) && F_186 ( V_28 , V_241 ) ) )
goto V_251;
if ( F_1 ( V_2 ) &&
! F_109 ( V_2 , V_28 , V_43 , V_19 ) )
goto F_162;
F_215 ( V_2 , V_28 , F_17 ( V_2 , V_43 ) , V_194 ) ;
return V_43 ;
}
static void * F_247 ( struct V_1 * V_2 , T_7 V_241 , int V_115 ,
unsigned long V_19 , struct V_193 * V_194 )
{
void * V_5 ;
unsigned long V_3 ;
F_46 ( V_3 ) ;
#ifdef F_211
V_194 = F_219 ( V_2 -> V_10 ) ;
#endif
V_5 = F_245 ( V_2 , V_241 , V_115 , V_19 , V_194 ) ;
F_47 ( V_3 ) ;
return V_5 ;
}
static T_1 void * F_248 ( struct V_1 * V_2 ,
T_7 V_241 , int V_115 , unsigned long V_19 )
{
void * V_14 ;
struct V_193 * V_194 ;
struct V_28 * V_28 ;
unsigned long V_209 ;
V_2 = F_249 ( V_2 , V_241 ) ;
if ( ! V_2 )
return NULL ;
V_225:
do {
V_209 = F_218 ( V_2 -> V_10 -> V_209 ) ;
V_194 = F_241 ( V_2 -> V_10 ) ;
} while ( F_250 ( F_211 ) &&
F_3 ( V_209 != F_251 ( V_194 -> V_209 ) ) );
F_252 () ;
V_14 = V_194 -> V_43 ;
V_28 = V_194 -> V_28 ;
if ( F_3 ( ! V_14 || ! F_230 ( V_28 , V_115 ) ) ) {
V_14 = F_247 ( V_2 , V_241 , V_115 , V_19 , V_194 ) ;
F_11 ( V_2 , V_255 ) ;
} else {
void * V_129 = F_20 ( V_2 , V_14 ) ;
if ( F_3 ( ! F_253 (
V_2 -> V_10 -> V_43 , V_2 -> V_10 -> V_209 ,
V_14 , V_209 ,
V_129 , F_205 ( V_209 ) ) ) ) {
F_209 ( L_63 , V_2 , V_209 ) ;
goto V_225;
}
F_18 ( V_2 , V_129 ) ;
F_11 ( V_2 , V_256 ) ;
}
if ( F_3 ( V_241 & V_257 ) && V_14 )
memset ( V_14 , 0 , V_2 -> V_82 ) ;
F_254 ( V_2 , V_241 , 1 , & V_14 ) ;
return V_14 ;
}
static T_1 void * F_255 ( struct V_1 * V_2 ,
T_7 V_241 , unsigned long V_19 )
{
return F_248 ( V_2 , V_241 , V_147 , V_19 ) ;
}
void * F_256 ( struct V_1 * V_2 , T_7 V_241 )
{
void * V_127 = F_255 ( V_2 , V_241 , V_258 ) ;
F_257 ( V_258 , V_127 , V_2 -> V_82 ,
V_2 -> V_20 , V_241 ) ;
return V_127 ;
}
void * F_258 ( struct V_1 * V_2 , T_7 V_241 , T_6 V_20 )
{
void * V_127 = F_255 ( V_2 , V_241 , V_258 ) ;
F_259 ( V_258 , V_127 , V_20 , V_2 -> V_20 , V_241 ) ;
F_260 ( V_2 , V_127 , V_20 , V_241 ) ;
return V_127 ;
}
void * F_261 ( struct V_1 * V_2 , T_7 V_241 , int V_115 )
{
void * V_127 = F_248 ( V_2 , V_241 , V_115 , V_258 ) ;
F_262 ( V_258 , V_127 ,
V_2 -> V_82 , V_2 -> V_20 , V_241 , V_115 ) ;
return V_127 ;
}
void * F_263 ( struct V_1 * V_2 ,
T_7 V_241 ,
int V_115 , T_6 V_20 )
{
void * V_127 = F_248 ( V_2 , V_241 , V_115 , V_258 ) ;
F_264 ( V_258 , V_127 ,
V_20 , V_2 -> V_20 , V_241 , V_115 ) ;
F_260 ( V_2 , V_127 , V_20 , V_241 ) ;
return V_127 ;
}
static void F_265 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_122 , void * V_123 , int V_125 ,
unsigned long V_19 )
{
void * V_224 ;
int V_259 ;
struct V_28 V_192 ;
unsigned long V_32 ;
struct V_111 * V_39 = NULL ;
unsigned long V_126 ( V_3 ) ;
F_11 ( V_2 , V_260 ) ;
if ( F_1 ( V_2 ) &&
! F_111 ( V_2 , V_28 , V_122 , V_123 , V_125 , V_19 ) )
return;
do {
if ( F_3 ( V_39 ) ) {
F_114 ( & V_39 -> V_112 , V_3 ) ;
V_39 = NULL ;
}
V_224 = V_28 -> V_43 ;
V_32 = V_28 -> V_32 ;
F_23 ( V_2 , V_123 , V_224 ) ;
V_192 . V_32 = V_32 ;
V_259 = V_192 . V_33 ;
V_192 . V_34 -= V_125 ;
if ( ( ! V_192 . V_34 || ! V_224 ) && ! V_259 ) {
if ( F_5 ( V_2 ) && ! V_224 ) {
V_192 . V_33 = 1 ;
} else {
V_39 = F_97 ( V_2 , F_112 ( V_28 ) ) ;
F_113 ( & V_39 -> V_112 , V_3 ) ;
}
}
} while ( ! F_45 ( V_2 , V_28 ,
V_224 , V_32 ,
V_122 , V_192 . V_32 ,
L_64 ) );
if ( F_101 ( ! V_39 ) ) {
if ( V_192 . V_33 && ! V_259 ) {
F_187 ( V_2 , V_28 , 1 ) ;
F_11 ( V_2 , V_261 ) ;
}
if ( V_259 )
F_11 ( V_2 , V_262 ) ;
return;
}
if ( F_3 ( ! V_192 . V_34 && V_39 -> V_188 >= V_2 -> V_207 ) )
goto V_263;
if ( ! F_5 ( V_2 ) && F_3 ( ! V_224 ) ) {
if ( F_1 ( V_2 ) )
F_94 ( V_2 , V_39 , V_28 ) ;
F_179 ( V_39 , V_28 , V_189 ) ;
F_11 ( V_2 , V_231 ) ;
}
F_114 ( & V_39 -> V_112 , V_3 ) ;
return;
V_263:
if ( V_224 ) {
F_180 ( V_39 , V_28 ) ;
F_11 ( V_2 , V_264 ) ;
} else {
F_94 ( V_2 , V_39 , V_28 ) ;
}
F_114 ( & V_39 -> V_112 , V_3 ) ;
F_11 ( V_2 , V_228 ) ;
F_176 ( V_2 , V_28 ) ;
}
static T_1 void F_266 ( struct V_1 * V_2 ,
struct V_28 * V_28 , void * V_122 , void * V_123 ,
int V_125 , unsigned long V_19 )
{
void * V_144 = V_123 ? : V_122 ;
struct V_193 * V_194 ;
unsigned long V_209 ;
V_225:
do {
V_209 = F_218 ( V_2 -> V_10 -> V_209 ) ;
V_194 = F_241 ( V_2 -> V_10 ) ;
} while ( F_250 ( F_211 ) &&
F_3 ( V_209 != F_251 ( V_194 -> V_209 ) ) );
F_252 () ;
if ( F_101 ( V_28 == V_194 -> V_28 ) ) {
F_23 ( V_2 , V_144 , V_194 -> V_43 ) ;
if ( F_3 ( ! F_253 (
V_2 -> V_10 -> V_43 , V_2 -> V_10 -> V_209 ,
V_194 -> V_43 , V_209 ,
V_122 , F_205 ( V_209 ) ) ) ) {
F_209 ( L_65 , V_2 , V_209 ) ;
goto V_225;
}
F_11 ( V_2 , V_265 ) ;
} else
F_265 ( V_2 , V_28 , V_122 , V_144 , V_125 , V_19 ) ;
}
static T_1 void F_267 ( struct V_1 * V_2 , struct V_28 * V_28 ,
void * V_122 , void * V_123 , int V_125 ,
unsigned long V_19 )
{
F_130 ( V_2 , V_122 , V_123 ) ;
if ( V_2 -> V_3 & V_266 && ! ( V_2 -> V_3 & V_187 ) )
return;
F_266 ( V_2 , V_28 , V_122 , V_123 , V_125 , V_19 ) ;
}
void F_268 ( struct V_1 * V_267 , void * V_25 , unsigned long V_19 )
{
F_266 ( V_267 , F_172 ( V_25 ) , V_25 , NULL , 1 , V_19 ) ;
}
void F_269 ( struct V_1 * V_2 , void * V_25 )
{
V_2 = F_270 ( V_2 , V_25 ) ;
if ( ! V_2 )
return;
F_267 ( V_2 , F_172 ( V_25 ) , V_25 , NULL , 1 , V_258 ) ;
F_271 ( V_258 , V_25 ) ;
}
static inline
int F_272 ( struct V_1 * V_2 , T_6 V_20 ,
void * * V_5 , struct V_268 * V_269 )
{
T_6 V_270 = 0 ;
int V_271 = 3 ;
void * V_14 ;
struct V_28 * V_28 ;
V_269 -> V_28 = NULL ;
do {
V_14 = V_5 [ -- V_20 ] ;
} while ( ! V_14 && V_20 );
if ( ! V_14 )
return 0 ;
V_28 = F_172 ( V_14 ) ;
if ( ! V_2 ) {
if ( F_3 ( ! F_89 ( V_28 ) ) ) {
F_24 ( ! F_273 ( V_28 ) ) ;
F_121 ( V_14 ) ;
F_139 ( V_28 , F_86 ( V_28 ) ) ;
V_5 [ V_20 ] = NULL ;
return V_20 ;
}
V_269 -> V_2 = V_28 -> V_121 ;
} else {
V_269 -> V_2 = F_270 ( V_2 , V_14 ) ;
}
V_269 -> V_28 = V_28 ;
F_23 ( V_269 -> V_2 , V_14 , NULL ) ;
V_269 -> V_123 = V_14 ;
V_269 -> V_43 = V_14 ;
V_5 [ V_20 ] = NULL ;
V_269 -> V_125 = 1 ;
while ( V_20 ) {
V_14 = V_5 [ -- V_20 ] ;
if ( ! V_14 )
continue;
if ( V_269 -> V_28 == F_172 ( V_14 ) ) {
F_23 ( V_269 -> V_2 , V_14 , V_269 -> V_43 ) ;
V_269 -> V_43 = V_14 ;
V_269 -> V_125 ++ ;
V_5 [ V_20 ] = NULL ;
continue;
}
if ( ! -- V_271 )
break;
if ( ! V_270 )
V_270 = V_20 + 1 ;
}
return V_270 ;
}
void F_274 ( struct V_1 * V_2 , T_6 V_20 , void * * V_5 )
{
if ( F_182 ( ! V_20 ) )
return;
do {
struct V_268 V_269 ;
V_20 = F_272 ( V_2 , V_20 , V_5 , & V_269 ) ;
if ( ! V_269 . V_28 )
continue;
F_267 ( V_269 . V_2 , V_269 . V_28 , V_269 . V_43 , V_269 . V_123 , V_269 . V_125 , V_258 ) ;
} while ( F_101 ( V_20 ) );
}
int F_275 ( struct V_1 * V_2 , T_7 V_3 , T_6 V_20 ,
void * * V_5 )
{
struct V_193 * V_194 ;
int V_57 ;
V_2 = F_249 ( V_2 , V_3 ) ;
if ( F_3 ( ! V_2 ) )
return false ;
F_160 () ;
V_194 = F_219 ( V_2 -> V_10 ) ;
for ( V_57 = 0 ; V_57 < V_20 ; V_57 ++ ) {
void * V_14 = V_194 -> V_43 ;
if ( F_3 ( ! V_14 ) ) {
V_5 [ V_57 ] = F_245 ( V_2 , V_3 , V_147 ,
V_258 , V_194 ) ;
if ( F_3 ( ! V_5 [ V_57 ] ) )
goto error;
V_194 = F_219 ( V_2 -> V_10 ) ;
continue;
}
V_194 -> V_43 = F_17 ( V_2 , V_14 ) ;
V_5 [ V_57 ] = V_14 ;
}
V_194 -> V_209 = F_205 ( V_194 -> V_209 ) ;
F_151 () ;
if ( F_3 ( V_3 & V_257 ) ) {
int V_272 ;
for ( V_272 = 0 ; V_272 < V_57 ; V_272 ++ )
memset ( V_5 [ V_272 ] , 0 , V_2 -> V_82 ) ;
}
F_254 ( V_2 , V_3 , V_20 , V_5 ) ;
return V_57 ;
error:
F_151 () ;
F_254 ( V_2 , V_3 , V_57 , V_5 ) ;
F_276 ( V_2 , V_57 , V_5 ) ;
return 0 ;
}
static inline int F_277 ( int V_20 , int V_273 ,
int V_274 , int V_275 , int V_22 )
{
int V_21 ;
int V_276 ;
int V_277 = V_278 ;
if ( F_26 ( V_277 , V_20 , V_22 ) > V_108 )
return F_238 ( V_20 * V_108 ) - 1 ;
for ( V_21 = F_278 ( V_277 , F_238 ( V_273 * V_20 + V_22 ) ) ;
V_21 <= V_274 ; V_21 ++ ) {
unsigned long V_279 = V_23 << V_21 ;
V_276 = ( V_279 - V_22 ) % V_20 ;
if ( V_276 <= V_279 / V_275 )
break;
}
return V_21 ;
}
static inline int F_279 ( int V_20 , int V_22 )
{
int V_21 ;
int V_273 ;
int V_280 ;
int V_107 ;
V_273 = V_281 ;
if ( ! V_273 )
V_273 = 4 * ( F_280 ( V_282 ) + 1 ) ;
V_107 = F_26 ( V_283 , V_20 , V_22 ) ;
V_273 = V_167 ( V_273 , V_107 ) ;
while ( V_273 > 1 ) {
V_280 = 16 ;
while ( V_280 >= 4 ) {
V_21 = F_277 ( V_20 , V_273 ,
V_283 , V_280 , V_22 ) ;
if ( V_21 <= V_283 )
return V_21 ;
V_280 /= 2 ;
}
V_273 -- ;
}
V_21 = F_277 ( V_20 , 1 , V_283 , 1 , V_22 ) ;
if ( V_21 <= V_283 )
return V_21 ;
V_21 = F_277 ( V_20 , 1 , V_284 , 1 , V_22 ) ;
if ( V_21 < V_284 )
return V_21 ;
return - V_285 ;
}
static void
F_281 ( struct V_111 * V_39 )
{
V_39 -> V_188 = 0 ;
F_282 ( & V_39 -> V_112 ) ;
F_283 ( & V_39 -> V_190 ) ;
#ifdef F_2
F_284 ( & V_39 -> V_116 , 0 ) ;
F_284 ( & V_39 -> V_117 , 0 ) ;
F_283 ( & V_39 -> V_114 ) ;
#endif
}
static inline int F_285 ( struct V_1 * V_2 )
{
F_286 ( V_286 <
V_287 * sizeof( struct V_193 ) ) ;
V_2 -> V_10 = F_287 ( sizeof( struct V_193 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_10 )
return 0 ;
F_212 ( V_2 ) ;
return 1 ;
}
static void F_288 ( int V_115 )
{
struct V_28 * V_28 ;
struct V_111 * V_39 ;
F_24 ( V_111 -> V_20 < sizeof( struct V_111 ) ) ;
V_28 = F_162 ( V_111 , V_288 , V_115 ) ;
F_24 ( ! V_28 ) ;
if ( F_112 ( V_28 ) != V_115 ) {
F_67 ( L_66 , V_115 ) ;
F_67 ( L_67 ) ;
}
V_39 = V_28 -> V_43 ;
F_24 ( ! V_39 ) ;
V_28 -> V_43 = F_17 ( V_111 , V_39 ) ;
V_28 -> V_34 = 1 ;
V_28 -> V_33 = 0 ;
V_111 -> V_115 [ V_115 ] = V_39 ;
#ifdef F_2
F_80 ( V_111 , V_39 , V_103 ) ;
F_65 ( V_111 , V_39 ) ;
#endif
F_260 ( V_111 , V_39 , sizeof( struct V_111 ) ,
V_151 ) ;
F_281 ( V_39 ) ;
F_100 ( V_111 , V_115 , V_28 -> V_35 ) ;
F_177 ( V_39 , V_28 , V_221 ) ;
}
static void F_289 ( struct V_1 * V_2 )
{
int V_115 ;
struct V_111 * V_39 ;
F_239 (s, node, n) {
V_2 -> V_115 [ V_115 ] = NULL ;
F_269 ( V_111 , V_39 ) ;
}
}
void F_290 ( struct V_1 * V_2 )
{
F_291 ( V_2 ) ;
F_292 ( V_2 -> V_10 ) ;
F_289 ( V_2 ) ;
}
static int F_293 ( struct V_1 * V_2 )
{
int V_115 ;
F_294 (node, N_NORMAL_MEMORY) {
struct V_111 * V_39 ;
if ( V_289 == V_290 ) {
F_288 ( V_115 ) ;
continue;
}
V_39 = F_261 ( V_111 ,
V_151 , V_115 ) ;
if ( ! V_39 ) {
F_289 ( V_2 ) ;
return 0 ;
}
F_281 ( V_39 ) ;
V_2 -> V_115 [ V_115 ] = V_39 ;
}
return 1 ;
}
static void F_295 ( struct V_1 * V_2 , unsigned long V_167 )
{
if ( V_167 < V_291 )
V_167 = V_291 ;
else if ( V_167 > V_292 )
V_167 = V_292 ;
V_2 -> V_207 = V_167 ;
}
static void F_296 ( struct V_1 * V_2 )
{
#ifdef F_6
if ( ! F_5 ( V_2 ) )
V_2 -> V_235 = 0 ;
else if ( V_2 -> V_20 >= V_23 )
V_2 -> V_235 = 2 ;
else if ( V_2 -> V_20 >= 1024 )
V_2 -> V_235 = 6 ;
else if ( V_2 -> V_20 >= 256 )
V_2 -> V_235 = 13 ;
else
V_2 -> V_235 = 30 ;
#endif
}
static int F_297 ( struct V_1 * V_2 , int V_293 )
{
unsigned long V_3 = V_2 -> V_3 ;
T_6 V_20 = V_2 -> V_82 ;
int V_21 ;
V_20 = F_298 ( V_20 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_101 ) && ! ( V_3 & V_187 ) &&
! V_2 -> F_117 )
V_2 -> V_3 |= V_86 ;
else
V_2 -> V_3 &= ~ V_86 ;
if ( ( V_3 & V_6 ) && V_20 == V_2 -> V_82 )
V_20 += sizeof( void * ) ;
#endif
V_2 -> V_34 = V_20 ;
if ( ( ( V_3 & ( V_187 | V_101 ) ) ||
V_2 -> F_117 ) ) {
V_2 -> V_15 = V_20 ;
V_20 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_70 )
V_20 += 2 * sizeof( struct V_52 ) ;
#endif
F_299 ( V_2 , & V_20 , & V_2 -> V_3 ) ;
#ifdef F_2
if ( V_3 & V_6 ) {
V_20 += sizeof( void * ) ;
V_2 -> V_7 = sizeof( void * ) ;
V_2 -> V_7 = F_298 ( V_2 -> V_7 , V_2 -> V_294 ) ;
V_20 += V_2 -> V_7 ;
}
#endif
V_20 = F_298 ( V_20 , V_2 -> V_294 ) ;
V_2 -> V_20 = V_20 ;
if ( V_293 >= 0 )
V_21 = V_293 ;
else
V_21 = F_279 ( V_20 , V_2 -> V_22 ) ;
if ( V_21 < 0 )
return 0 ;
V_2 -> V_162 = 0 ;
if ( V_21 )
V_2 -> V_162 |= V_295 ;
if ( V_2 -> V_3 & V_296 )
V_2 -> V_162 |= V_297 ;
if ( V_2 -> V_3 & V_174 )
V_2 -> V_162 |= V_298 ;
V_2 -> V_145 = F_27 ( V_21 , V_20 , V_2 -> V_22 ) ;
V_2 -> V_167 = F_27 ( F_238 ( V_20 ) , V_20 , V_2 -> V_22 ) ;
if ( F_29 ( V_2 -> V_145 ) > F_29 ( V_2 -> F_278 ) )
V_2 -> F_278 = V_2 -> V_145 ;
return ! ! F_29 ( V_2 -> V_145 ) ;
}
static int F_300 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_116 ( V_2 -> V_20 , V_3 , V_2 -> V_45 , V_2 -> F_117 ) ;
V_2 -> V_22 = 0 ;
#ifdef F_15
V_2 -> V_13 = F_301 () ;
#endif
if ( V_185 && ( V_2 -> V_3 & V_187 ) )
V_2 -> V_22 = sizeof( struct V_183 ) ;
if ( ! F_297 ( V_2 , - 1 ) )
goto error;
if ( V_135 ) {
if ( F_238 ( V_2 -> V_20 ) > F_238 ( V_2 -> V_82 ) ) {
V_2 -> V_3 &= ~ V_299 ;
V_2 -> V_15 = 0 ;
if ( ! F_297 ( V_2 , - 1 ) )
goto error;
}
}
#if F_40 ( V_40 ) && \
F_40 ( V_41 )
if ( F_302 () && ( V_2 -> V_3 & V_300 ) == 0 )
V_2 -> V_3 |= V_42 ;
#endif
F_295 ( V_2 , F_303 ( V_2 -> V_20 ) / 2 ) ;
F_296 ( V_2 ) ;
#ifdef F_191
V_2 -> V_206 = 1000 ;
#endif
if ( V_289 >= V_301 ) {
if ( F_140 ( V_2 ) )
goto error;
}
if ( ! F_293 ( V_2 ) )
goto error;
if ( F_285 ( V_2 ) )
return 0 ;
F_289 ( V_2 ) ;
error:
if ( V_3 & V_302 )
F_304 ( L_68 ,
V_2 -> V_45 , ( unsigned long ) V_2 -> V_20 , V_2 -> V_20 ,
F_28 ( V_2 -> V_145 ) , V_2 -> V_15 , V_3 ) ;
return - V_303 ;
}
static void F_305 ( struct V_1 * V_2 , struct V_28 * V_28 ,
const char * V_49 )
{
#ifdef F_2
void * V_19 = F_49 ( V_28 ) ;
void * V_5 ;
unsigned long * V_46 = F_306 ( F_307 ( V_28 -> V_35 ) *
sizeof( long ) , V_240 ) ;
if ( ! V_46 )
return;
F_79 ( V_2 , V_28 , V_49 , V_2 -> V_45 ) ;
F_30 ( V_28 ) ;
F_48 ( V_2 , V_28 , V_46 ) ;
F_165 (p, s, addr, page->objects) {
if ( ! F_308 ( F_25 ( V_5 , V_2 , V_19 ) , V_46 ) ) {
F_67 ( L_69 , V_5 , V_5 - V_19 ) ;
F_68 ( V_2 , V_5 ) ;
}
}
F_34 ( V_28 ) ;
F_309 ( V_46 ) ;
#endif
}
static void F_310 ( struct V_1 * V_2 , struct V_111 * V_39 )
{
F_311 ( V_304 ) ;
struct V_28 * V_28 , * V_184 ;
F_24 ( F_39 () ) ;
F_312 ( & V_39 -> V_112 ) ;
F_185 (page, h, &n->partial, lru) {
if ( ! V_28 -> V_34 ) {
F_180 ( V_39 , V_28 ) ;
F_93 ( & V_28 -> V_113 , & V_304 ) ;
} else {
F_305 ( V_2 , V_28 ,
L_70 ) ;
}
}
F_313 ( & V_39 -> V_112 ) ;
F_185 (page, h, &discard, lru)
F_176 ( V_2 , V_28 ) ;
}
int F_314 ( struct V_1 * V_2 )
{
int V_115 ;
struct V_111 * V_39 ;
F_227 ( V_2 ) ;
F_239 (s, node, n) {
F_310 ( V_2 , V_39 ) ;
if ( V_39 -> V_188 || F_96 ( V_2 , V_115 ) )
return 1 ;
}
F_10 ( V_2 ) ;
return 0 ;
}
static int T_5 F_315 ( char * V_130 )
{
F_316 ( & V_130 , & V_278 ) ;
return 1 ;
}
static int T_5 F_317 ( char * V_130 )
{
F_316 ( & V_130 , & V_283 ) ;
V_283 = V_167 ( V_283 , V_284 - 1 ) ;
return 1 ;
}
static int T_5 F_318 ( char * V_130 )
{
F_316 ( & V_130 , & V_281 ) ;
return 1 ;
}
void * F_319 ( T_6 V_20 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_127 ;
if ( F_3 ( V_20 > V_305 ) )
return F_320 ( V_20 , V_3 ) ;
V_2 = F_321 ( V_20 , V_3 ) ;
if ( F_3 ( F_322 ( V_2 ) ) )
return V_2 ;
V_127 = F_255 ( V_2 , V_3 , V_258 ) ;
F_259 ( V_258 , V_127 , V_20 , V_2 -> V_20 , V_3 ) ;
F_260 ( V_2 , V_127 , V_20 , V_3 ) ;
return V_127 ;
}
static void * F_323 ( T_6 V_20 , T_7 V_3 , int V_115 )
{
struct V_28 * V_28 ;
void * V_11 = NULL ;
V_3 |= V_295 | V_146 ;
V_28 = F_324 ( V_115 , V_3 , F_238 ( V_20 ) ) ;
if ( V_28 )
V_11 = F_49 ( V_28 ) ;
F_118 ( V_11 , V_20 , V_3 ) ;
return V_11 ;
}
void * F_325 ( T_6 V_20 , T_7 V_3 , int V_115 )
{
struct V_1 * V_2 ;
void * V_127 ;
if ( F_3 ( V_20 > V_305 ) ) {
V_127 = F_323 ( V_20 , V_3 , V_115 ) ;
F_264 ( V_258 , V_127 ,
V_20 , V_23 << F_238 ( V_20 ) ,
V_3 , V_115 ) ;
return V_127 ;
}
V_2 = F_321 ( V_20 , V_3 ) ;
if ( F_3 ( F_322 ( V_2 ) ) )
return V_2 ;
V_127 = F_248 ( V_2 , V_3 , V_115 , V_258 ) ;
F_264 ( V_258 , V_127 , V_20 , V_2 -> V_20 , V_3 , V_115 ) ;
F_260 ( V_2 , V_127 , V_20 , V_3 ) ;
return V_127 ;
}
const char * F_326 ( const void * V_11 , unsigned long V_39 ,
struct V_28 * V_28 )
{
struct V_1 * V_2 ;
unsigned long V_15 ;
T_6 V_82 ;
V_2 = V_28 -> V_121 ;
V_82 = F_327 ( V_2 ) ;
if ( V_11 < F_49 ( V_28 ) )
return V_2 -> V_45 ;
V_15 = ( V_11 - F_49 ( V_28 ) ) % V_2 -> V_20 ;
if ( F_1 ( V_2 ) && V_2 -> V_3 & V_6 ) {
if ( V_15 < V_2 -> V_7 )
return V_2 -> V_45 ;
V_15 -= V_2 -> V_7 ;
}
if ( V_15 <= V_82 && V_39 <= V_82 - V_15 )
return NULL ;
return V_2 -> V_45 ;
}
static T_6 F_328 ( const void * V_14 )
{
struct V_28 * V_28 ;
if ( F_3 ( V_14 == V_306 ) )
return 0 ;
V_28 = F_172 ( V_14 ) ;
if ( F_3 ( ! F_89 ( V_28 ) ) ) {
F_182 ( ! F_273 ( V_28 ) ) ;
return V_23 << F_86 ( V_28 ) ;
}
return F_327 ( V_28 -> V_121 ) ;
}
T_6 F_329 ( const void * V_14 )
{
T_6 V_20 = F_328 ( V_14 ) ;
F_330 ( V_14 , V_20 ) ;
return V_20 ;
}
void F_309 ( const void * V_25 )
{
struct V_28 * V_28 ;
void * V_14 = ( void * ) V_25 ;
F_331 ( V_258 , V_25 ) ;
if ( F_3 ( F_322 ( V_25 ) ) )
return;
V_28 = F_172 ( V_25 ) ;
if ( F_3 ( ! F_89 ( V_28 ) ) ) {
F_24 ( ! F_273 ( V_28 ) ) ;
F_121 ( V_25 ) ;
F_139 ( V_28 , F_86 ( V_28 ) ) ;
return;
}
F_267 ( V_28 -> V_121 , V_28 , V_14 , NULL , 1 , V_258 ) ;
}
int F_332 ( struct V_1 * V_2 )
{
int V_115 ;
int V_57 ;
struct V_111 * V_39 ;
struct V_28 * V_28 ;
struct V_28 * V_73 ;
struct V_186 V_304 ;
struct V_186 V_307 [ V_308 ] ;
unsigned long V_3 ;
int V_127 = 0 ;
F_227 ( V_2 ) ;
F_239 (s, node, n) {
F_283 ( & V_304 ) ;
for ( V_57 = 0 ; V_57 < V_308 ; V_57 ++ )
F_283 ( V_307 + V_57 ) ;
F_113 ( & V_39 -> V_112 , V_3 ) ;
F_185 (page, t, &n->partial, lru) {
int free = V_28 -> V_35 - V_28 -> V_34 ;
F_252 () ;
F_24 ( free <= 0 ) ;
if ( free == V_28 -> V_35 ) {
F_333 ( & V_28 -> V_113 , & V_304 ) ;
V_39 -> V_188 -- ;
} else if ( free <= V_308 )
F_333 ( & V_28 -> V_113 , V_307 + free - 1 ) ;
}
for ( V_57 = V_308 - 1 ; V_57 >= 0 ; V_57 -- )
F_334 ( V_307 + V_57 , & V_39 -> V_190 ) ;
F_114 ( & V_39 -> V_112 , V_3 ) ;
F_185 (page, t, &discard, lru)
F_176 ( V_2 , V_28 ) ;
if ( F_96 ( V_2 , V_115 ) )
V_127 = 1 ;
}
return V_127 ;
}
static void F_335 ( struct V_1 * V_2 )
{
if ( ! F_332 ( V_2 ) )
F_10 ( V_2 ) ;
}
void F_336 ( struct V_1 * V_2 )
{
F_337 ( V_2 , 0 ) ;
V_2 -> V_207 = 0 ;
F_338 ( V_2 , F_335 ) ;
}
static int F_339 ( void * V_309 )
{
struct V_1 * V_2 ;
F_143 ( & V_152 ) ;
F_144 (s, &slab_caches, list)
F_332 ( V_2 ) ;
F_145 ( & V_152 ) ;
return 0 ;
}
static void F_340 ( void * V_309 )
{
struct V_111 * V_39 ;
struct V_1 * V_2 ;
struct V_310 * V_311 = V_309 ;
int V_312 ;
V_312 = V_311 -> V_313 ;
if ( V_312 < 0 )
return;
F_143 ( & V_152 ) ;
F_144 (s, &slab_caches, list) {
V_39 = F_97 ( V_2 , V_312 ) ;
if ( V_39 ) {
F_24 ( F_96 ( V_2 , V_312 ) ) ;
V_2 -> V_115 [ V_312 ] = NULL ;
F_269 ( V_111 , V_39 ) ;
}
}
F_145 ( & V_152 ) ;
}
static int F_341 ( void * V_309 )
{
struct V_111 * V_39 ;
struct V_1 * V_2 ;
struct V_310 * V_311 = V_309 ;
int V_242 = V_311 -> V_313 ;
int V_127 = 0 ;
if ( V_242 < 0 )
return 0 ;
F_143 ( & V_152 ) ;
F_144 (s, &slab_caches, list) {
V_39 = F_256 ( V_111 , V_151 ) ;
if ( ! V_39 ) {
V_127 = - V_314 ;
goto V_128;
}
F_281 ( V_39 ) ;
V_2 -> V_115 [ V_242 ] = V_39 ;
}
V_128:
F_145 ( & V_152 ) ;
return V_127 ;
}
static int F_342 ( struct V_315 * V_316 ,
unsigned long V_317 , void * V_309 )
{
int V_127 = 0 ;
switch ( V_317 ) {
case V_318 :
V_127 = F_341 ( V_309 ) ;
break;
case V_319 :
V_127 = F_339 ( V_309 ) ;
break;
case V_320 :
case V_321 :
F_340 ( V_309 ) ;
break;
case V_322 :
case V_323 :
break;
}
if ( V_127 )
V_127 = F_343 ( V_127 ) ;
else
V_127 = V_324 ;
return V_127 ;
}
static struct V_1 * T_5 F_344 ( struct V_1 * V_325 )
{
int V_115 ;
struct V_1 * V_2 = F_345 ( V_1 , V_288 ) ;
struct V_111 * V_39 ;
memcpy ( V_2 , V_325 , V_1 -> V_82 ) ;
F_223 ( V_2 , F_64 () ) ;
F_239 (s, node, n) {
struct V_28 * V_5 ;
F_144 (p, &n->partial, lru)
V_5 -> V_121 = V_2 ;
#ifdef F_2
F_144 (p, &n->full, lru)
V_5 -> V_121 = V_2 ;
#endif
}
F_346 ( V_2 ) ;
F_93 ( & V_2 -> V_326 , & V_327 ) ;
F_347 ( V_2 ) ;
return V_2 ;
}
void T_5 F_348 ( void )
{
static V_328 struct V_1 V_329 ,
V_330 ;
if ( F_349 () )
V_283 = 0 ;
V_111 = & V_330 ;
V_1 = & V_329 ;
F_350 ( V_111 , L_71 ,
sizeof( struct V_111 ) , V_331 ) ;
F_351 ( & V_332 ) ;
V_289 = V_333 ;
F_350 ( V_1 , L_72 ,
F_352 ( struct V_1 , V_115 ) +
V_334 * sizeof( struct V_111 * ) ,
V_331 ) ;
V_1 = F_344 ( & V_329 ) ;
V_111 = F_344 ( & V_330 ) ;
F_353 () ;
F_354 ( 0 ) ;
F_142 () ;
F_355 ( V_335 , L_73 , NULL ,
F_229 ) ;
F_44 ( L_74 ,
F_356 () ,
V_278 , V_283 , V_281 ,
V_282 , V_334 ) ;
}
void T_5 F_357 ( void )
{
}
struct V_1 *
F_358 ( const char * V_45 , T_6 V_20 , T_6 V_294 ,
unsigned long V_3 , void (* F_117)( void * ) )
{
struct V_1 * V_2 , * V_194 ;
V_2 = F_359 ( V_20 , V_294 , V_3 , V_45 , F_117 ) ;
if ( V_2 ) {
V_2 -> V_336 ++ ;
V_2 -> V_82 = F_278 ( V_2 -> V_82 , ( int ) V_20 ) ;
V_2 -> V_34 = F_360 ( int , V_2 -> V_34 , F_298 ( V_20 , sizeof( void * ) ) ) ;
F_361 (c, s) {
V_194 -> V_82 = V_2 -> V_82 ;
V_194 -> V_34 = F_360 ( int , V_194 -> V_34 ,
F_298 ( V_20 , sizeof( void * ) ) ) ;
}
if ( F_8 ( V_2 , V_45 ) ) {
V_2 -> V_336 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_362 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_148 ;
V_148 = F_300 ( V_2 , V_3 ) ;
if ( V_148 )
return V_148 ;
if ( V_289 <= V_301 )
return 0 ;
F_9 ( V_2 ) ;
V_148 = F_7 ( V_2 ) ;
if ( V_148 )
F_290 ( V_2 ) ;
return V_148 ;
}
void * F_363 ( T_6 V_20 , T_7 V_241 , unsigned long V_337 )
{
struct V_1 * V_2 ;
void * V_127 ;
if ( F_3 ( V_20 > V_305 ) )
return F_320 ( V_20 , V_241 ) ;
V_2 = F_321 ( V_20 , V_241 ) ;
if ( F_3 ( F_322 ( V_2 ) ) )
return V_2 ;
V_127 = F_255 ( V_2 , V_241 , V_337 ) ;
F_259 ( V_337 , V_127 , V_20 , V_2 -> V_20 , V_241 ) ;
return V_127 ;
}
void * F_364 ( T_6 V_20 , T_7 V_241 ,
int V_115 , unsigned long V_337 )
{
struct V_1 * V_2 ;
void * V_127 ;
if ( F_3 ( V_20 > V_305 ) ) {
V_127 = F_323 ( V_20 , V_241 , V_115 ) ;
F_264 ( V_337 , V_127 ,
V_20 , V_23 << F_238 ( V_20 ) ,
V_241 , V_115 ) ;
return V_127 ;
}
V_2 = F_321 ( V_20 , V_241 ) ;
if ( F_3 ( F_322 ( V_2 ) ) )
return V_2 ;
V_127 = F_248 ( V_2 , V_241 , V_115 , V_337 ) ;
F_264 ( V_337 , V_127 , V_20 , V_2 -> V_20 , V_241 , V_115 ) ;
return V_127 ;
}
static int F_365 ( struct V_28 * V_28 )
{
return V_28 -> V_34 ;
}
static int F_366 ( struct V_28 * V_28 )
{
return V_28 -> V_35 ;
}
static int F_367 ( struct V_1 * V_2 , struct V_28 * V_28 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_19 = F_49 ( V_28 ) ;
if ( ! F_88 ( V_2 , V_28 ) ||
! F_90 ( V_2 , V_28 , NULL ) )
return 0 ;
F_368 ( V_46 , V_28 -> V_35 ) ;
F_48 ( V_2 , V_28 , V_46 ) ;
F_165 (p, s, addr, page->objects) {
if ( F_308 ( F_25 ( V_5 , V_2 , V_19 ) , V_46 ) )
if ( ! F_87 ( V_2 , V_28 , V_5 , V_118 ) )
return 0 ;
}
F_165 (p, s, addr, page->objects)
if ( ! F_308 ( F_25 ( V_5 , V_2 , V_19 ) , V_46 ) )
if ( ! F_87 ( V_2 , V_28 , V_5 , V_103 ) )
return 0 ;
return 1 ;
}
static void F_369 ( struct V_1 * V_2 , struct V_28 * V_28 ,
unsigned long * V_46 )
{
F_30 ( V_28 ) ;
F_367 ( V_2 , V_28 , V_46 ) ;
F_34 ( V_28 ) ;
}
static int F_370 ( struct V_1 * V_2 ,
struct V_111 * V_39 , unsigned long * V_46 )
{
unsigned long V_149 = 0 ;
struct V_28 * V_28 ;
unsigned long V_3 ;
F_113 ( & V_39 -> V_112 , V_3 ) ;
F_144 (page, &n->partial, lru) {
F_369 ( V_2 , V_28 , V_46 ) ;
V_149 ++ ;
}
if ( V_149 != V_39 -> V_188 )
F_67 ( L_75 ,
V_2 -> V_45 , V_149 , V_39 -> V_188 ) ;
if ( ! ( V_2 -> V_3 & V_70 ) )
goto V_128;
F_144 (page, &n->full, lru) {
F_369 ( V_2 , V_28 , V_46 ) ;
V_149 ++ ;
}
if ( V_149 != F_98 ( & V_39 -> V_116 ) )
F_67 ( L_76 ,
V_2 -> V_45 , V_149 , F_98 ( & V_39 -> V_116 ) ) ;
V_128:
F_114 ( & V_39 -> V_112 , V_3 ) ;
return V_149 ;
}
static long F_371 ( struct V_1 * V_2 )
{
int V_115 ;
unsigned long V_149 = 0 ;
unsigned long * V_46 = F_372 ( F_307 ( F_29 ( V_2 -> F_278 ) ) *
sizeof( unsigned long ) , V_151 ) ;
struct V_111 * V_39 ;
if ( ! V_46 )
return - V_314 ;
F_227 ( V_2 ) ;
F_239 (s, node, n)
V_149 += F_370 ( V_2 , V_39 , V_46 ) ;
F_309 ( V_46 ) ;
return V_149 ;
}
static void F_373 ( struct V_338 * V_73 )
{
if ( V_73 -> F_278 )
F_374 ( ( unsigned long ) V_73 -> V_339 ,
F_238 ( sizeof( struct V_340 ) * V_73 -> F_278 ) ) ;
}
static int F_375 ( struct V_338 * V_73 , unsigned long F_278 , T_7 V_3 )
{
struct V_340 * V_218 ;
int V_21 ;
V_21 = F_238 ( sizeof( struct V_340 ) * F_278 ) ;
V_218 = ( void * ) F_376 ( V_3 , V_21 ) ;
if ( ! V_218 )
return 0 ;
if ( V_73 -> V_149 ) {
memcpy ( V_218 , V_73 -> V_339 , sizeof( struct V_340 ) * V_73 -> V_149 ) ;
F_373 ( V_73 ) ;
}
V_73 -> F_278 = F_278 ;
V_73 -> V_339 = V_218 ;
return 1 ;
}
static int F_377 ( struct V_338 * V_73 , struct V_1 * V_2 ,
const struct V_52 * V_52 )
{
long V_94 , V_98 , V_153 ;
struct V_340 * V_218 ;
unsigned long V_341 ;
unsigned long V_342 = V_69 - V_52 -> V_68 ;
V_94 = - 1 ;
V_98 = V_73 -> V_149 ;
for ( ; ; ) {
V_153 = V_94 + ( V_98 - V_94 + 1 ) / 2 ;
if ( V_153 == V_98 )
break;
V_341 = V_73 -> V_339 [ V_153 ] . V_19 ;
if ( V_52 -> V_19 == V_341 ) {
V_218 = & V_73 -> V_339 [ V_153 ] ;
V_218 -> V_149 ++ ;
if ( V_52 -> V_68 ) {
V_218 -> V_343 += V_342 ;
if ( V_342 < V_218 -> V_344 )
V_218 -> V_344 = V_342 ;
if ( V_342 > V_218 -> V_345 )
V_218 -> V_345 = V_342 ;
if ( V_52 -> V_66 < V_218 -> V_346 )
V_218 -> V_346 = V_52 -> V_66 ;
if ( V_52 -> V_66 > V_218 -> V_347 )
V_218 -> V_347 = V_52 -> V_66 ;
F_378 ( V_52 -> V_65 ,
F_379 ( V_218 -> V_348 ) ) ;
}
F_380 ( F_112 ( F_381 ( V_52 ) ) , V_218 -> V_349 ) ;
return 1 ;
}
if ( V_52 -> V_19 < V_341 )
V_98 = V_153 ;
else
V_94 = V_153 ;
}
if ( V_73 -> V_149 >= V_73 -> F_278 && ! F_375 ( V_73 , 2 * V_73 -> F_278 , V_240 ) )
return 0 ;
V_218 = V_73 -> V_339 + V_153 ;
if ( V_153 < V_73 -> V_149 )
memmove ( V_218 + 1 , V_218 ,
( V_73 -> V_149 - V_153 ) * sizeof( struct V_340 ) ) ;
V_73 -> V_149 ++ ;
V_218 -> V_149 = 1 ;
V_218 -> V_19 = V_52 -> V_19 ;
V_218 -> V_343 = V_342 ;
V_218 -> V_344 = V_342 ;
V_218 -> V_345 = V_342 ;
V_218 -> V_346 = V_52 -> V_66 ;
V_218 -> V_347 = V_52 -> V_66 ;
F_382 ( F_379 ( V_218 -> V_348 ) ) ;
F_378 ( V_52 -> V_65 , F_379 ( V_218 -> V_348 ) ) ;
F_383 ( V_218 -> V_349 ) ;
F_380 ( F_112 ( F_381 ( V_52 ) ) , V_218 -> V_349 ) ;
return 1 ;
}
static void F_384 ( struct V_338 * V_73 , struct V_1 * V_2 ,
struct V_28 * V_28 , enum V_53 V_54 ,
unsigned long * V_46 )
{
void * V_19 = F_49 ( V_28 ) ;
void * V_5 ;
F_368 ( V_46 , V_28 -> V_35 ) ;
F_48 ( V_2 , V_28 , V_46 ) ;
F_165 (p, s, addr, page->objects)
if ( ! F_308 ( F_25 ( V_5 , V_2 , V_19 ) , V_46 ) )
F_377 ( V_73 , V_2 , F_60 ( V_2 , V_5 , V_54 ) ) ;
}
static int F_385 ( struct V_1 * V_2 , char * V_84 ,
enum V_53 V_54 )
{
int V_350 = 0 ;
unsigned long V_57 ;
struct V_338 V_73 = { 0 , 0 , NULL } ;
int V_115 ;
unsigned long * V_46 = F_372 ( F_307 ( F_29 ( V_2 -> F_278 ) ) *
sizeof( unsigned long ) , V_151 ) ;
struct V_111 * V_39 ;
if ( ! V_46 || ! F_375 ( & V_73 , V_23 / sizeof( struct V_340 ) ,
V_151 ) ) {
F_309 ( V_46 ) ;
return sprintf ( V_84 , L_77 ) ;
}
F_227 ( V_2 ) ;
F_239 (s, node, n) {
unsigned long V_3 ;
struct V_28 * V_28 ;
if ( ! F_98 ( & V_39 -> V_116 ) )
continue;
F_113 ( & V_39 -> V_112 , V_3 ) ;
F_144 (page, &n->partial, lru)
F_384 ( & V_73 , V_2 , V_28 , V_54 , V_46 ) ;
F_144 (page, &n->full, lru)
F_384 ( & V_73 , V_2 , V_28 , V_54 , V_46 ) ;
F_114 ( & V_39 -> V_112 , V_3 ) ;
}
for ( V_57 = 0 ; V_57 < V_73 . V_149 ; V_57 ++ ) {
struct V_340 * V_218 = & V_73 . V_339 [ V_57 ] ;
if ( V_350 > V_23 - V_351 - 100 )
break;
V_350 += sprintf ( V_84 + V_350 , L_78 , V_218 -> V_149 ) ;
if ( V_218 -> V_19 )
V_350 += sprintf ( V_84 + V_350 , L_79 , ( void * ) V_218 -> V_19 ) ;
else
V_350 += sprintf ( V_84 + V_350 , L_80 ) ;
if ( V_218 -> V_343 != V_218 -> V_344 ) {
V_350 += sprintf ( V_84 + V_350 , L_81 ,
V_218 -> V_344 ,
( long ) F_386 ( V_218 -> V_343 , V_218 -> V_149 ) ,
V_218 -> V_345 ) ;
} else
V_350 += sprintf ( V_84 + V_350 , L_82 ,
V_218 -> V_344 ) ;
if ( V_218 -> V_346 != V_218 -> V_347 )
V_350 += sprintf ( V_84 + V_350 , L_83 ,
V_218 -> V_346 , V_218 -> V_347 ) ;
else
V_350 += sprintf ( V_84 + V_350 , L_84 ,
V_218 -> V_346 ) ;
if ( F_387 () > 1 &&
! F_388 ( F_379 ( V_218 -> V_348 ) ) &&
V_350 < V_23 - 60 )
V_350 += F_389 ( V_84 + V_350 , V_23 - V_350 - 50 ,
L_85 ,
F_390 ( F_379 ( V_218 -> V_348 ) ) ) ;
if ( V_352 > 1 && ! F_391 ( V_218 -> V_349 ) &&
V_350 < V_23 - 60 )
V_350 += F_389 ( V_84 + V_350 , V_23 - V_350 - 50 ,
L_86 ,
F_392 ( & V_218 -> V_349 ) ) ;
V_350 += sprintf ( V_84 + V_350 , L_87 ) ;
}
F_373 ( & V_73 ) ;
F_309 ( V_46 ) ;
if ( ! V_73 . V_149 )
V_350 += sprintf ( V_84 , L_88 ) ;
return V_350 ;
}
static void T_5 F_393 ( void )
{
T_2 * V_5 ;
F_286 ( V_353 > 16 || V_287 < 10 ) ;
F_67 ( L_89 ) ;
F_67 ( L_90 ) ;
F_67 ( L_91 ) ;
V_5 = F_306 ( 16 , V_151 ) ;
V_5 [ 16 ] = 0x12 ;
F_67 ( L_92 ,
V_5 + 16 ) ;
F_371 ( V_354 [ 4 ] ) ;
V_5 = F_306 ( 32 , V_151 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_67 ( L_93 ,
V_5 ) ;
F_67 ( L_94 ) ;
F_371 ( V_354 [ 5 ] ) ;
V_5 = F_306 ( 64 , V_151 ) ;
V_5 += 64 + ( F_193 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_67 ( L_95 ,
V_5 ) ;
F_67 ( L_94 ) ;
F_371 ( V_354 [ 6 ] ) ;
F_67 ( L_96 ) ;
V_5 = F_306 ( 128 , V_151 ) ;
F_309 ( V_5 ) ;
* V_5 = 0x78 ;
F_67 ( L_97 , V_5 ) ;
F_371 ( V_354 [ 7 ] ) ;
V_5 = F_306 ( 256 , V_151 ) ;
F_309 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_67 ( L_98 , V_5 ) ;
F_371 ( V_354 [ 8 ] ) ;
V_5 = F_306 ( 512 , V_151 ) ;
F_309 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_67 ( L_99 , V_5 ) ;
F_371 ( V_354 [ 9 ] ) ;
}
static void F_393 ( void ) {}
static int T_5 F_394 ( char * V_130 )
{
int V_355 ;
if ( F_316 ( & V_130 , & V_355 ) > 0 )
V_356 = V_355 ;
return 1 ;
}
static T_9 F_395 ( struct V_1 * V_2 ,
char * V_84 , unsigned long V_3 )
{
unsigned long V_357 = 0 ;
int V_115 ;
int V_25 ;
unsigned long * V_349 ;
V_349 = F_306 ( sizeof( unsigned long ) * V_334 , V_151 ) ;
if ( ! V_349 )
return - V_314 ;
if ( V_3 & V_358 ) {
int V_65 ;
F_213 (cpu) {
struct V_193 * V_194 = F_214 ( V_2 -> V_10 ,
V_65 ) ;
int V_115 ;
struct V_28 * V_28 ;
V_28 = F_251 ( V_194 -> V_28 ) ;
if ( ! V_28 )
continue;
V_115 = F_112 ( V_28 ) ;
if ( V_3 & V_359 )
V_25 = V_28 -> V_35 ;
else if ( V_3 & V_360 )
V_25 = V_28 -> V_34 ;
else
V_25 = 1 ;
V_357 += V_25 ;
V_349 [ V_115 ] += V_25 ;
V_28 = F_396 ( V_194 ) ;
if ( V_28 ) {
V_115 = F_112 ( V_28 ) ;
if ( V_3 & V_359 )
F_397 ( 1 ) ;
else if ( V_3 & V_360 )
F_397 ( 1 ) ;
else
V_25 = V_28 -> V_173 ;
V_357 += V_25 ;
V_349 [ V_115 ] += V_25 ;
}
}
}
F_398 () ;
#ifdef F_2
if ( V_3 & V_361 ) {
struct V_111 * V_39 ;
F_239 (s, node, n) {
if ( V_3 & V_359 )
V_25 = F_98 ( & V_39 -> V_117 ) ;
else if ( V_3 & V_360 )
V_25 = F_98 ( & V_39 -> V_117 ) -
F_233 ( V_39 , F_231 ) ;
else
V_25 = F_98 ( & V_39 -> V_116 ) ;
V_357 += V_25 ;
V_349 [ V_115 ] += V_25 ;
}
} else
#endif
if ( V_3 & V_362 ) {
struct V_111 * V_39 ;
F_239 (s, node, n) {
if ( V_3 & V_359 )
V_25 = F_233 ( V_39 , F_366 ) ;
else if ( V_3 & V_360 )
V_25 = F_233 ( V_39 , F_365 ) ;
else
V_25 = V_39 -> V_188 ;
V_357 += V_25 ;
V_349 [ V_115 ] += V_25 ;
}
}
V_25 = sprintf ( V_84 , L_100 , V_357 ) ;
#ifdef F_191
for ( V_115 = 0 ; V_115 < V_334 ; V_115 ++ )
if ( V_349 [ V_115 ] )
V_25 += sprintf ( V_84 + V_25 , L_101 ,
V_115 , V_349 [ V_115 ] ) ;
#endif
F_399 () ;
F_309 ( V_349 ) ;
return V_25 + sprintf ( V_84 + V_25 , L_87 ) ;
}
static int F_400 ( struct V_1 * V_2 )
{
int V_115 ;
struct V_111 * V_39 ;
F_239 (s, node, n)
if ( F_98 ( & V_39 -> V_117 ) )
return 1 ;
return 0 ;
}
static T_9 F_401 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , V_2 -> V_20 ) ;
}
static T_9 F_402 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , V_2 -> V_294 ) ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , V_2 -> V_82 ) ;
}
static T_9 F_404 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , F_29 ( V_2 -> V_145 ) ) ;
}
static T_9 F_405 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
unsigned long V_21 ;
int V_148 ;
V_148 = F_406 ( V_84 , 10 , & V_21 ) ;
if ( V_148 )
return V_148 ;
if ( V_21 > V_283 || V_21 < V_278 )
return - V_303 ;
F_297 ( V_2 , V_21 ) ;
return V_50 ;
}
static T_9 F_407 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , F_28 ( V_2 -> V_145 ) ) ;
}
static T_9 F_408 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_103 , V_2 -> V_207 ) ;
}
static T_9 F_409 ( struct V_1 * V_2 , const char * V_84 ,
T_6 V_50 )
{
unsigned long V_167 ;
int V_148 ;
V_148 = F_406 ( V_84 , 10 , & V_167 ) ;
if ( V_148 )
return V_148 ;
F_295 ( V_2 , V_167 ) ;
return V_50 ;
}
static T_9 F_410 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_104 , F_188 ( V_2 ) ) ;
}
static T_9 F_411 ( struct V_1 * V_2 , const char * V_84 ,
T_6 V_50 )
{
unsigned long V_35 ;
int V_148 ;
V_148 = F_406 ( V_84 , 10 , & V_35 ) ;
if ( V_148 )
return V_148 ;
if ( V_35 && ! F_5 ( V_2 ) )
return - V_303 ;
F_337 ( V_2 , V_35 ) ;
F_227 ( V_2 ) ;
return V_50 ;
}
static T_9 F_412 ( struct V_1 * V_2 , char * V_84 )
{
if ( ! V_2 -> F_117 )
return 0 ;
return sprintf ( V_84 , L_105 , V_2 -> F_117 ) ;
}
static T_9 F_413 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , V_2 -> V_336 < 0 ? 0 : V_2 -> V_336 - 1 ) ;
}
static T_9 F_414 ( struct V_1 * V_2 , char * V_84 )
{
return F_395 ( V_2 , V_84 , V_362 ) ;
}
static T_9 F_415 ( struct V_1 * V_2 , char * V_84 )
{
return F_395 ( V_2 , V_84 , V_358 ) ;
}
static T_9 F_416 ( struct V_1 * V_2 , char * V_84 )
{
return F_395 ( V_2 , V_84 , V_361 | V_360 ) ;
}
static T_9 F_417 ( struct V_1 * V_2 , char * V_84 )
{
return F_395 ( V_2 , V_84 , V_362 | V_360 ) ;
}
static T_9 F_418 ( struct V_1 * V_2 , char * V_84 )
{
int V_35 = 0 ;
int V_173 = 0 ;
int V_65 ;
int V_350 ;
F_419 (cpu) {
struct V_28 * V_28 ;
V_28 = F_226 ( F_214 ( V_2 -> V_10 , V_65 ) ) ;
if ( V_28 ) {
V_173 += V_28 -> V_173 ;
V_35 += V_28 -> V_234 ;
}
}
V_350 = sprintf ( V_84 , L_106 , V_35 , V_173 ) ;
#ifdef F_420
F_419 (cpu) {
struct V_28 * V_28 ;
V_28 = F_226 ( F_214 ( V_2 -> V_10 , V_65 ) ) ;
if ( V_28 && V_350 < V_23 - 20 )
V_350 += sprintf ( V_84 + V_350 , L_107 , V_65 ,
V_28 -> V_234 , V_28 -> V_173 ) ;
}
#endif
return V_350 + sprintf ( V_84 + V_350 , L_87 ) ;
}
static T_9 F_421 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_174 ) ) ;
}
static T_9 F_422 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
V_2 -> V_3 &= ~ V_174 ;
if ( V_84 [ 0 ] == '1' )
V_2 -> V_3 |= V_174 ;
return V_50 ;
}
static T_9 F_423 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_331 ) ) ;
}
static T_9 F_424 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_296 ) ) ;
}
static T_9 F_425 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_187 ) ) ;
}
static T_9 F_426 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , V_2 -> V_22 ) ;
}
static T_9 F_427 ( struct V_1 * V_2 , char * V_84 )
{
return F_395 ( V_2 , V_84 , V_361 ) ;
}
static T_9 F_428 ( struct V_1 * V_2 , char * V_84 )
{
return F_395 ( V_2 , V_84 , V_361 | V_359 ) ;
}
static T_9 F_429 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_9 F_430 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
V_2 -> V_3 &= ~ V_119 ;
if ( V_84 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_42 ;
V_2 -> V_3 |= V_119 ;
}
return V_50 ;
}
static T_9 F_431 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_109 ) ) ;
}
static T_9 F_432 ( struct V_1 * V_2 , const char * V_84 ,
T_6 V_50 )
{
if ( V_2 -> V_336 > 1 )
return - V_303 ;
V_2 -> V_3 &= ~ V_109 ;
if ( V_84 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_42 ;
V_2 -> V_3 |= V_109 ;
}
return V_50 ;
}
static T_9 F_433 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_6 ) ) ;
}
static T_9 F_434 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
if ( F_400 ( V_2 ) )
return - V_363 ;
V_2 -> V_3 &= ~ V_6 ;
if ( V_84 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_6 ;
}
F_297 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_435 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_9 F_436 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
if ( F_400 ( V_2 ) )
return - V_363 ;
V_2 -> V_3 &= ~ V_101 ;
if ( V_84 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_101 ;
}
F_297 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_437 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_70 ) ) ;
}
static T_9 F_438 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
if ( F_400 ( V_2 ) )
return - V_363 ;
V_2 -> V_3 &= ~ V_70 ;
if ( V_84 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_42 ;
V_2 -> V_3 |= V_70 ;
}
F_297 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_439 ( struct V_1 * V_2 , char * V_84 )
{
return 0 ;
}
static T_9 F_440 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
int V_127 = - V_303 ;
if ( V_84 [ 0 ] == '1' ) {
V_127 = F_371 ( V_2 ) ;
if ( V_127 >= 0 )
V_127 = V_50 ;
}
return V_127 ;
}
static T_9 F_441 ( struct V_1 * V_2 , char * V_84 )
{
if ( ! ( V_2 -> V_3 & V_70 ) )
return - V_285 ;
return F_385 ( V_2 , V_84 , V_72 ) ;
}
static T_9 F_442 ( struct V_1 * V_2 , char * V_84 )
{
if ( ! ( V_2 -> V_3 & V_70 ) )
return - V_285 ;
return F_385 ( V_2 , V_84 , V_71 ) ;
}
static T_9 F_443 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , ! ! ( V_2 -> V_3 & V_134 ) ) ;
}
static T_9 F_444 ( struct V_1 * V_2 , const char * V_84 ,
T_6 V_50 )
{
if ( V_2 -> V_336 > 1 )
return - V_303 ;
V_2 -> V_3 &= ~ V_134 ;
if ( V_84 [ 0 ] == '1' )
V_2 -> V_3 |= V_134 ;
return V_50 ;
}
static T_9 F_445 ( struct V_1 * V_2 , char * V_84 )
{
return 0 ;
}
static T_9 F_446 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
if ( V_84 [ 0 ] == '1' )
F_447 ( V_2 ) ;
else
return - V_303 ;
return V_50 ;
}
static T_9 F_448 ( struct V_1 * V_2 , char * V_84 )
{
return sprintf ( V_84 , L_102 , V_2 -> V_206 / 10 ) ;
}
static T_9 F_449 ( struct V_1 * V_2 ,
const char * V_84 , T_6 V_50 )
{
unsigned long V_364 ;
int V_148 ;
V_148 = F_406 ( V_84 , 10 , & V_364 ) ;
if ( V_148 )
return V_148 ;
if ( V_364 <= 100 )
V_2 -> V_206 = V_364 * 10 ;
return V_50 ;
}
static int F_450 ( struct V_1 * V_2 , char * V_84 , enum V_8 V_9 )
{
unsigned long V_365 = 0 ;
int V_65 ;
int V_350 ;
int * V_90 = F_372 ( V_282 * sizeof( int ) , V_151 ) ;
if ( ! V_90 )
return - V_314 ;
F_419 (cpu) {
unsigned V_25 = F_214 ( V_2 -> V_10 , V_65 ) -> F_11 [ V_9 ] ;
V_90 [ V_65 ] = V_25 ;
V_365 += V_25 ;
}
V_350 = sprintf ( V_84 , L_100 , V_365 ) ;
#ifdef F_420
F_419 (cpu) {
if ( V_90 [ V_65 ] && V_350 < V_23 - 20 )
V_350 += sprintf ( V_84 + V_350 , L_108 , V_65 , V_90 [ V_65 ] ) ;
}
#endif
F_309 ( V_90 ) ;
return V_350 + sprintf ( V_84 + V_350 , L_87 ) ;
}
static void F_451 ( struct V_1 * V_2 , enum V_8 V_9 )
{
int V_65 ;
F_419 (cpu)
F_214 ( V_2 -> V_10 , V_65 ) -> F_11 [ V_9 ] = 0 ;
}
static T_9 F_452 ( struct V_366 * V_367 ,
struct V_368 * V_369 ,
char * V_84 )
{
struct V_370 * V_368 ;
struct V_1 * V_2 ;
int V_148 ;
V_368 = F_453 ( V_369 ) ;
V_2 = F_454 ( V_367 ) ;
if ( ! V_368 -> V_371 )
return - V_372 ;
V_148 = V_368 -> V_371 ( V_2 , V_84 ) ;
return V_148 ;
}
static T_9 F_455 ( struct V_366 * V_367 ,
struct V_368 * V_369 ,
const char * V_84 , T_6 V_350 )
{
struct V_370 * V_368 ;
struct V_1 * V_2 ;
int V_148 ;
V_368 = F_453 ( V_369 ) ;
V_2 = F_454 ( V_367 ) ;
if ( ! V_368 -> V_373 )
return - V_372 ;
V_148 = V_368 -> V_373 ( V_2 , V_84 , V_350 ) ;
#ifdef F_456
if ( V_289 >= V_374 && V_148 >= 0 && F_457 ( V_2 ) ) {
struct V_1 * V_194 ;
F_143 ( & V_152 ) ;
if ( V_2 -> V_375 < V_350 )
V_2 -> V_375 = V_350 ;
F_361 (c, s)
V_368 -> V_373 ( V_194 , V_84 , V_350 ) ;
F_145 ( & V_152 ) ;
}
#endif
return V_148 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_456
int V_57 ;
char * V_376 = NULL ;
struct V_1 * V_377 ;
if ( F_457 ( V_2 ) )
return;
V_377 = V_2 -> V_378 . V_377 ;
if ( ! V_377 -> V_375 )
return;
for ( V_57 = 0 ; V_57 < F_458 ( V_379 ) ; V_57 ++ ) {
char V_380 [ 64 ] ;
char * V_84 ;
struct V_370 * V_369 = F_453 ( V_379 [ V_57 ] ) ;
T_9 V_350 ;
if ( ! V_369 || ! V_369 -> V_373 || ! V_369 -> V_371 )
continue;
if ( V_376 )
V_84 = V_376 ;
else if ( V_377 -> V_375 < F_458 ( V_380 ) )
V_84 = V_380 ;
else {
V_376 = ( char * ) F_459 ( V_151 ) ;
if ( F_182 ( ! V_376 ) )
continue;
V_84 = V_376 ;
}
V_350 = V_369 -> V_371 ( V_377 , V_84 ) ;
if ( V_350 > 0 )
V_369 -> V_373 ( V_2 , V_84 , V_350 ) ;
}
if ( V_376 )
F_460 ( ( unsigned long ) V_376 ) ;
#endif
}
static void F_461 ( struct V_366 * V_381 )
{
F_462 ( F_454 ( V_381 ) ) ;
}
static int F_463 ( struct V_382 * V_382 , struct V_366 * V_367 )
{
struct V_383 * V_384 = F_464 ( V_367 ) ;
if ( V_384 == & V_385 )
return 1 ;
return 0 ;
}
static inline struct V_382 * F_465 ( struct V_1 * V_2 )
{
#ifdef F_456
if ( ! F_457 ( V_2 ) )
return V_2 -> V_378 . V_377 -> V_386 ;
#endif
return V_387 ;
}
static char * F_466 ( struct V_1 * V_2 )
{
char * V_45 = F_372 ( V_388 , V_151 ) ;
char * V_5 = V_45 ;
F_24 ( ! V_45 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_296 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_174 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_119 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_172 ) )
* V_5 ++ = 't' ;
if ( V_2 -> V_3 & V_389 )
* V_5 ++ = 'A' ;
if ( V_5 != V_45 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_109 , V_2 -> V_20 ) ;
F_24 ( V_5 > V_45 + V_388 - 1 ) ;
return V_45 ;
}
static void F_467 ( struct V_390 * V_391 )
{
struct V_1 * V_2 =
F_173 ( V_391 , struct V_1 , V_392 ) ;
if ( ! V_2 -> V_367 . V_393 )
goto V_128;
#ifdef F_456
F_468 ( V_2 -> V_386 ) ;
#endif
F_469 ( & V_2 -> V_367 , V_394 ) ;
F_470 ( & V_2 -> V_367 ) ;
V_128:
F_471 ( & V_2 -> V_367 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_148 ;
const char * V_45 ;
struct V_382 * V_382 = F_465 ( V_2 ) ;
int V_395 = F_472 ( V_2 ) ;
F_473 ( & V_2 -> V_392 , F_467 ) ;
if ( ! V_382 ) {
F_474 ( & V_2 -> V_367 , & V_385 ) ;
return 0 ;
}
if ( V_395 ) {
F_475 ( & V_387 -> V_367 , V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
} else {
V_45 = F_466 ( V_2 ) ;
}
V_2 -> V_367 . V_382 = V_382 ;
V_148 = F_476 ( & V_2 -> V_367 , & V_385 , NULL , L_16 , V_45 ) ;
if ( V_148 )
goto V_128;
V_148 = F_477 ( & V_2 -> V_367 , & V_396 ) ;
if ( V_148 )
goto V_397;
#ifdef F_456
if ( F_457 ( V_2 ) && V_356 ) {
V_2 -> V_386 = F_478 ( L_110 , NULL , & V_2 -> V_367 ) ;
if ( ! V_2 -> V_386 ) {
V_148 = - V_314 ;
goto V_397;
}
}
#endif
F_469 ( & V_2 -> V_367 , V_398 ) ;
if ( ! V_395 ) {
F_8 ( V_2 , V_2 -> V_45 ) ;
}
V_128:
if ( ! V_395 )
F_309 ( V_45 ) ;
return V_148 ;
V_397:
F_470 ( & V_2 -> V_367 ) ;
goto V_128;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_289 < V_374 )
return;
F_479 ( & V_2 -> V_367 ) ;
F_480 ( & V_2 -> V_392 ) ;
}
void F_481 ( struct V_1 * V_2 )
{
if ( V_289 >= V_374 )
F_471 ( & V_2 -> V_367 ) ;
}
static int F_8 ( struct V_1 * V_2 , const char * V_45 )
{
struct V_399 * V_400 ;
if ( V_289 == V_374 ) {
F_475 ( & V_387 -> V_367 , V_45 ) ;
return F_482 ( & V_387 -> V_367 , & V_2 -> V_367 , V_45 ) ;
}
V_400 = F_372 ( sizeof( struct V_399 ) , V_151 ) ;
if ( ! V_400 )
return - V_314 ;
V_400 -> V_2 = V_2 ;
V_400 -> V_45 = V_45 ;
V_400 -> V_158 = V_401 ;
V_401 = V_400 ;
return 0 ;
}
static int T_5 F_483 ( void )
{
struct V_1 * V_2 ;
int V_148 ;
F_143 ( & V_152 ) ;
V_387 = F_478 ( L_111 , & V_402 , V_403 ) ;
if ( ! V_387 ) {
F_145 ( & V_152 ) ;
F_67 ( L_112 ) ;
return - V_285 ;
}
V_289 = V_374 ;
F_144 (s, &slab_caches, list) {
V_148 = F_7 ( V_2 ) ;
if ( V_148 )
F_67 ( L_113 ,
V_2 -> V_45 ) ;
}
while ( V_401 ) {
struct V_399 * V_400 = V_401 ;
V_401 = V_401 -> V_158 ;
V_148 = F_8 ( V_400 -> V_2 , V_400 -> V_45 ) ;
if ( V_148 )
F_67 ( L_114 ,
V_400 -> V_45 ) ;
F_309 ( V_400 ) ;
}
F_145 ( & V_152 ) ;
F_393 () ;
return 0 ;
}
void F_484 ( struct V_1 * V_2 , struct V_404 * V_405 )
{
unsigned long V_116 = 0 ;
unsigned long V_246 = 0 ;
unsigned long V_247 = 0 ;
int V_115 ;
struct V_111 * V_39 ;
F_239 (s, node, n) {
V_116 += F_99 ( V_39 ) ;
V_246 += F_232 ( V_39 ) ;
V_247 += F_233 ( V_39 , F_231 ) ;
}
V_405 -> V_406 = V_246 - V_247 ;
V_405 -> V_407 = V_246 ;
V_405 -> V_408 = V_116 ;
V_405 -> V_409 = V_116 ;
V_405 -> V_410 = F_29 ( V_2 -> V_145 ) ;
V_405 -> V_411 = F_28 ( V_2 -> V_145 ) ;
}
void F_485 ( struct V_412 * V_219 , struct V_1 * V_2 )
{
}
T_9 F_486 ( struct V_413 * V_413 , const char T_10 * V_376 ,
T_6 V_149 , T_11 * V_414 )
{
return - V_372 ;
}
