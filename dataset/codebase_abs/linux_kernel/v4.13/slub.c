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
static inline void * F_14 ( struct V_1 * V_2 , void * V_11 )
{
return * ( void * * ) ( V_11 + V_2 -> V_12 ) ;
}
static void F_15 ( const struct V_1 * V_2 , void * V_11 )
{
F_16 ( V_11 + V_2 -> V_12 ) ;
}
static inline void * F_17 ( struct V_1 * V_2 , void * V_11 )
{
void * V_5 ;
if ( ! F_18 () )
return F_14 ( V_2 , V_11 ) ;
F_19 ( & V_5 , ( void * * ) ( V_11 + V_2 -> V_12 ) , sizeof( V_5 ) ) ;
return V_5 ;
}
static inline void F_20 ( struct V_1 * V_2 , void * V_11 , void * V_13 )
{
* ( void * * ) ( V_11 + V_2 -> V_12 ) = V_13 ;
}
static inline int F_21 ( void * V_5 , struct V_1 * V_2 , void * V_14 )
{
return ( V_5 - V_14 ) / V_2 -> V_15 ;
}
static inline int F_22 ( int V_16 , unsigned long V_15 , int V_17 )
{
return ( ( V_18 << V_16 ) - V_17 ) / V_15 ;
}
static inline struct V_19 F_23 ( int V_16 ,
unsigned long V_15 , int V_17 )
{
struct V_19 V_20 = {
( V_16 << V_21 ) + F_22 (order, size, reserved)
} ;
return V_20 ;
}
static inline int F_24 ( struct V_19 V_20 )
{
return V_20 . V_20 >> V_21 ;
}
static inline int F_25 ( struct V_19 V_20 )
{
return V_20 . V_20 & V_22 ;
}
static T_1 void F_26 ( struct V_23 * V_23 )
{
F_27 ( F_28 ( V_23 ) , V_23 ) ;
F_29 ( V_24 , & V_23 -> V_3 ) ;
}
static T_1 void F_30 ( struct V_23 * V_23 )
{
F_27 ( F_28 ( V_23 ) , V_23 ) ;
F_31 ( V_24 , & V_23 -> V_3 ) ;
}
static inline void F_32 ( struct V_23 * V_23 , unsigned long V_25 )
{
struct V_23 V_26 ;
V_26 . V_27 = V_25 ;
V_23 -> V_28 = V_26 . V_28 ;
V_23 -> V_29 = V_26 . V_29 ;
V_23 -> V_30 = V_26 . V_30 ;
}
static inline bool F_33 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_31 , unsigned long V_32 ,
void * V_33 , unsigned long V_25 ,
const char * V_34 )
{
F_34 ( ! F_35 () ) ;
#if F_36 ( V_35 ) && \
F_36 ( V_36 )
if ( V_2 -> V_3 & V_37 ) {
if ( F_37 ( & V_23 -> V_38 , & V_23 -> V_27 ,
V_31 , V_32 ,
V_33 , V_25 ) )
return true ;
} else
#endif
{
F_26 ( V_23 ) ;
if ( V_23 -> V_38 == V_31 &&
V_23 -> V_27 == V_32 ) {
V_23 -> V_38 = V_33 ;
F_32 ( V_23 , V_25 ) ;
F_30 ( V_23 ) ;
return true ;
}
F_30 ( V_23 ) ;
}
F_38 () ;
F_11 ( V_2 , V_39 ) ;
#ifdef F_39
F_40 ( L_1 , V_34 , V_2 -> V_40 ) ;
#endif
return false ;
}
static inline bool F_41 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_31 , unsigned long V_32 ,
void * V_33 , unsigned long V_25 ,
const char * V_34 )
{
#if F_36 ( V_35 ) && \
F_36 ( V_36 )
if ( V_2 -> V_3 & V_37 ) {
if ( F_37 ( & V_23 -> V_38 , & V_23 -> V_27 ,
V_31 , V_32 ,
V_33 , V_25 ) )
return true ;
} else
#endif
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_26 ( V_23 ) ;
if ( V_23 -> V_38 == V_31 &&
V_23 -> V_27 == V_32 ) {
V_23 -> V_38 = V_33 ;
F_32 ( V_23 , V_25 ) ;
F_30 ( V_23 ) ;
F_43 ( V_3 ) ;
return true ;
}
F_30 ( V_23 ) ;
F_43 ( V_3 ) ;
}
F_38 () ;
F_11 ( V_2 , V_39 ) ;
#ifdef F_39
F_40 ( L_1 , V_34 , V_2 -> V_40 ) ;
#endif
return false ;
}
static void F_44 ( struct V_1 * V_2 , struct V_23 * V_23 , unsigned long * V_41 )
{
void * V_5 ;
void * V_14 = F_45 ( V_23 ) ;
for ( V_5 = V_23 -> V_38 ; V_5 ; V_5 = F_14 ( V_2 , V_5 ) )
F_46 ( F_21 ( V_5 , V_2 , V_14 ) , V_41 ) ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_6 )
return V_2 -> V_15 - V_2 -> V_7 ;
return V_2 -> V_15 ;
}
static inline void * F_48 ( struct V_1 * V_2 , void * V_5 )
{
if ( V_2 -> V_3 & V_6 )
V_5 -= V_2 -> V_7 ;
return V_5 ;
}
static inline void F_49 ( void )
{
F_50 () ;
}
static inline void F_51 ( void )
{
F_52 () ;
}
static inline int F_53 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 )
{
void * V_42 ;
if ( ! V_11 )
return 1 ;
V_42 = F_45 ( V_23 ) ;
V_11 = F_48 ( V_2 , V_11 ) ;
if ( V_11 < V_42 || V_11 >= V_42 + V_23 -> V_30 * V_2 -> V_15 ||
( V_11 - V_42 ) % V_2 -> V_15 ) {
return 0 ;
}
return 1 ;
}
static void F_54 ( char * V_43 , char * V_44 , T_2 * V_14 ,
unsigned int V_45 )
{
F_49 () ;
F_55 ( V_43 , V_44 , V_46 , 16 , 1 , V_14 ,
V_45 , 1 ) ;
F_51 () ;
}
static struct V_47 * F_56 ( struct V_1 * V_2 , void * V_11 ,
enum V_48 V_49 )
{
struct V_47 * V_5 ;
if ( V_2 -> V_12 )
V_5 = V_11 + V_2 -> V_12 + sizeof( void * ) ;
else
V_5 = V_11 + V_2 -> V_29 ;
return V_5 + V_49 ;
}
static void F_57 ( struct V_1 * V_2 , void * V_11 ,
enum V_48 V_49 , unsigned long V_14 )
{
struct V_47 * V_5 = F_56 ( V_2 , V_11 , V_49 ) ;
if ( V_14 ) {
#ifdef F_58
struct V_50 V_51 ;
int V_52 ;
V_51 . V_53 = 0 ;
V_51 . V_54 = V_55 ;
V_51 . V_56 = V_5 -> V_57 ;
V_51 . V_58 = 3 ;
F_49 () ;
F_59 ( & V_51 ) ;
F_51 () ;
if ( V_51 . V_53 != 0 &&
V_51 . V_56 [ V_51 . V_53 - 1 ] == V_59 )
V_51 . V_53 -- ;
for ( V_52 = V_51 . V_53 ; V_52 < V_55 ; V_52 ++ )
V_5 -> V_57 [ V_52 ] = 0 ;
#endif
V_5 -> V_14 = V_14 ;
V_5 -> V_60 = F_60 () ;
V_5 -> V_61 = V_62 -> V_61 ;
V_5 -> V_63 = V_64 ;
} else
memset ( V_5 , 0 , sizeof( struct V_47 ) ) ;
}
static void F_61 ( struct V_1 * V_2 , void * V_11 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_57 ( V_2 , V_11 , V_66 , 0UL ) ;
F_57 ( V_2 , V_11 , V_67 , 0UL ) ;
}
static void F_62 ( const char * V_2 , struct V_47 * V_68 )
{
if ( ! V_68 -> V_14 )
return;
F_63 ( L_2 ,
V_2 , ( void * ) V_68 -> V_14 , V_64 - V_68 -> V_63 , V_68 -> V_60 , V_68 -> V_61 ) ;
#ifdef F_58
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ )
if ( V_68 -> V_57 [ V_52 ] )
F_63 ( L_3 , ( void * ) V_68 -> V_57 [ V_52 ] ) ;
else
break;
}
#endif
}
static void F_64 ( struct V_1 * V_2 , void * V_11 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_62 ( L_4 , F_56 ( V_2 , V_11 , V_67 ) ) ;
F_62 ( L_5 , F_56 ( V_2 , V_11 , V_66 ) ) ;
}
static void F_65 ( struct V_23 * V_23 )
{
F_63 ( L_6 ,
V_23 , V_23 -> V_30 , V_23 -> V_29 , V_23 -> V_38 , V_23 -> V_3 ) ;
}
static void F_66 ( struct V_1 * V_2 , char * V_69 , ... )
{
struct V_70 V_71 ;
T_3 args ;
va_start ( args , V_69 ) ;
V_71 . V_69 = V_69 ;
V_71 . V_72 = & args ;
F_63 ( L_7 ) ;
F_63 ( L_8 , V_2 -> V_40 , F_67 () , & V_71 ) ;
F_63 ( L_9 ) ;
F_68 ( V_73 , V_74 ) ;
va_end ( args ) ;
}
static void F_69 ( struct V_1 * V_2 , char * V_69 , ... )
{
struct V_70 V_71 ;
T_3 args ;
va_start ( args , V_69 ) ;
V_71 . V_69 = V_69 ;
V_71 . V_72 = & args ;
F_63 ( L_10 , V_2 -> V_40 , & V_71 ) ;
va_end ( args ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_23 * V_23 , T_2 * V_5 )
{
unsigned int V_75 ;
T_2 * V_14 = F_45 ( V_23 ) ;
F_64 ( V_2 , V_5 ) ;
F_65 ( V_23 ) ;
F_63 ( L_11 ,
V_5 , V_5 - V_14 , F_14 ( V_2 , V_5 ) ) ;
if ( V_2 -> V_3 & V_6 )
F_54 ( V_76 , L_12 , V_5 - V_2 -> V_7 ,
V_2 -> V_7 ) ;
else if ( V_5 > V_14 + 16 )
F_54 ( V_76 , L_13 , V_5 - 16 , 16 ) ;
F_54 ( V_76 , L_14 , V_5 ,
F_71 (unsigned long, s->object_size, PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_6 )
F_54 ( V_76 , L_12 , V_5 + V_2 -> V_77 ,
V_2 -> V_29 - V_2 -> V_77 ) ;
if ( V_2 -> V_12 )
V_75 = V_2 -> V_12 + sizeof( void * ) ;
else
V_75 = V_2 -> V_29 ;
if ( V_2 -> V_3 & V_65 )
V_75 += 2 * sizeof( struct V_47 ) ;
V_75 += F_72 ( V_2 ) ;
if ( V_75 != F_47 ( V_2 ) )
F_54 ( V_76 , L_15 , V_5 + V_75 ,
F_47 ( V_2 ) - V_75 ) ;
F_73 () ;
}
void F_74 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_78 )
{
F_66 ( V_2 , L_16 , V_78 ) ;
F_70 ( V_2 , V_23 , V_11 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_69 , ... )
{
T_3 args ;
char V_79 [ 100 ] ;
va_start ( args , V_69 ) ;
vsnprintf ( V_79 , sizeof( V_79 ) , V_69 , args ) ;
va_end ( args ) ;
F_66 ( V_2 , L_16 , V_79 ) ;
F_65 ( V_23 ) ;
F_73 () ;
}
static void F_76 ( struct V_1 * V_2 , void * V_11 , T_2 V_80 )
{
T_2 * V_5 = V_11 ;
if ( V_2 -> V_3 & V_6 )
memset ( V_5 - V_2 -> V_7 , V_80 , V_2 -> V_7 ) ;
if ( V_2 -> V_3 & V_81 ) {
memset ( V_5 , V_82 , V_2 -> V_77 - 1 ) ;
V_5 [ V_2 -> V_77 - 1 ] = V_83 ;
}
if ( V_2 -> V_3 & V_6 )
memset ( V_5 + V_2 -> V_77 , V_80 , V_2 -> V_29 - V_2 -> V_77 ) ;
}
static void F_77 ( struct V_1 * V_2 , char * V_84 , T_2 V_85 ,
void * V_86 , void * V_87 )
{
F_69 ( V_2 , L_17 , V_86 , V_87 - 1 , V_85 ) ;
memset ( V_86 , V_85 , V_87 - V_86 ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_88 ,
T_2 * V_89 , unsigned int V_90 , unsigned int V_91 )
{
T_2 * V_92 ;
T_2 * V_93 ;
F_49 () ;
V_92 = F_79 ( V_89 , V_90 , V_91 ) ;
F_51 () ;
if ( ! V_92 )
return 1 ;
V_93 = V_89 + V_91 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_90 )
V_93 -- ;
F_66 ( V_2 , L_18 , V_88 ) ;
F_63 ( L_19 ,
V_92 , V_93 - 1 , V_92 [ 0 ] , V_90 ) ;
F_70 ( V_2 , V_23 , V_11 ) ;
F_77 ( V_2 , V_88 , V_90 , V_92 , V_93 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_23 * V_23 , T_2 * V_5 )
{
unsigned long V_75 = V_2 -> V_29 ;
if ( V_2 -> V_12 )
V_75 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_65 )
V_75 += 2 * sizeof( struct V_47 ) ;
V_75 += F_72 ( V_2 ) ;
if ( F_47 ( V_2 ) == V_75 )
return 1 ;
return F_78 ( V_2 , V_23 , V_5 , L_20 ,
V_5 + V_75 , V_94 , F_47 ( V_2 ) - V_75 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
T_2 * V_89 ;
T_2 * V_92 ;
T_2 * V_93 ;
int V_45 ;
int V_95 ;
if ( ! ( V_2 -> V_3 & V_96 ) )
return 1 ;
V_89 = F_45 ( V_23 ) ;
V_45 = ( V_18 << F_82 ( V_23 ) ) - V_2 -> V_17 ;
V_93 = V_89 + V_45 ;
V_95 = V_45 % V_2 -> V_15 ;
if ( ! V_95 )
return 1 ;
F_49 () ;
V_92 = F_79 ( V_93 - V_95 , V_94 , V_95 ) ;
F_51 () ;
if ( ! V_92 )
return 1 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_94 )
V_93 -- ;
F_75 ( V_2 , V_23 , L_21 , V_92 , V_93 - 1 ) ;
F_54 ( V_76 , L_15 , V_93 - V_95 , V_95 ) ;
F_77 ( V_2 , L_22 , V_94 , V_93 - V_95 , V_93 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_80 )
{
T_2 * V_5 = V_11 ;
T_2 * V_97 = V_11 + V_2 -> V_77 ;
if ( V_2 -> V_3 & V_6 ) {
if ( ! F_78 ( V_2 , V_23 , V_11 , L_23 ,
V_11 - V_2 -> V_7 , V_80 , V_2 -> V_7 ) )
return 0 ;
if ( ! F_78 ( V_2 , V_23 , V_11 , L_23 ,
V_97 , V_80 , V_2 -> V_29 - V_2 -> V_77 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_96 ) && V_2 -> V_77 < V_2 -> V_29 ) {
F_78 ( V_2 , V_23 , V_5 , L_24 ,
V_97 , V_94 ,
V_2 -> V_29 - V_2 -> V_77 ) ;
}
}
if ( V_2 -> V_3 & V_96 ) {
if ( V_80 != V_98 && ( V_2 -> V_3 & V_81 ) &&
( ! F_78 ( V_2 , V_23 , V_5 , L_25 , V_5 ,
V_82 , V_2 -> V_77 - 1 ) ||
! F_78 ( V_2 , V_23 , V_5 , L_25 ,
V_5 + V_2 -> V_77 - 1 , V_83 , 1 ) ) )
return 0 ;
F_80 ( V_2 , V_23 , V_5 ) ;
}
if ( ! V_2 -> V_12 && V_80 == V_98 )
return 1 ;
if ( ! F_53 ( V_2 , V_23 , F_14 ( V_2 , V_5 ) ) ) {
F_74 ( V_2 , V_23 , V_5 , L_26 ) ;
F_20 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_99 ;
F_34 ( ! F_35 () ) ;
if ( ! F_85 ( V_23 ) ) {
F_75 ( V_2 , V_23 , L_27 ) ;
return 0 ;
}
V_99 = F_22 ( F_82 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_23 -> V_30 > V_99 ) {
F_75 ( V_2 , V_23 , L_28 ,
V_23 -> V_30 , V_99 ) ;
return 0 ;
}
if ( V_23 -> V_29 > V_23 -> V_30 ) {
F_75 ( V_2 , V_23 , L_29 ,
V_23 -> V_29 , V_23 -> V_30 ) ;
return 0 ;
}
F_81 ( V_2 , V_23 ) ;
return 1 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_100 )
{
int V_101 = 0 ;
void * V_13 ;
void * V_11 = NULL ;
int V_102 ;
V_13 = V_23 -> V_38 ;
while ( V_13 && V_101 <= V_23 -> V_30 ) {
if ( V_13 == V_100 )
return 1 ;
if ( ! F_53 ( V_2 , V_23 , V_13 ) ) {
if ( V_11 ) {
F_74 ( V_2 , V_23 , V_11 ,
L_30 ) ;
F_20 ( V_2 , V_11 , NULL ) ;
} else {
F_75 ( V_2 , V_23 , L_26 ) ;
V_23 -> V_38 = NULL ;
V_23 -> V_29 = V_23 -> V_30 ;
F_69 ( V_2 , L_31 ) ;
return 0 ;
}
break;
}
V_11 = V_13 ;
V_13 = F_14 ( V_2 , V_11 ) ;
V_101 ++ ;
}
V_102 = F_22 ( F_82 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_102 > V_103 )
V_102 = V_103 ;
if ( V_23 -> V_30 != V_102 ) {
F_75 ( V_2 , V_23 , L_32 ,
V_23 -> V_30 , V_102 ) ;
V_23 -> V_30 = V_102 ;
F_69 ( V_2 , L_33 ) ;
}
if ( V_23 -> V_29 != V_23 -> V_30 - V_101 ) {
F_75 ( V_2 , V_23 , L_34 ,
V_23 -> V_29 , V_23 -> V_30 - V_101 ) ;
V_23 -> V_29 = V_23 -> V_30 - V_101 ;
F_69 ( V_2 , L_35 ) ;
}
return V_100 == NULL ;
}
static void V_51 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_11 ,
int V_49 )
{
if ( V_2 -> V_3 & V_104 ) {
F_40 ( L_36 ,
V_2 -> V_40 ,
V_49 ? L_37 : L_38 ,
V_11 , V_23 -> V_29 ,
V_23 -> V_38 ) ;
if ( ! V_49 )
F_54 ( V_105 , L_14 , ( void * ) V_11 ,
V_2 -> V_77 ) ;
F_73 () ;
}
}
static void F_87 ( struct V_1 * V_2 ,
struct V_106 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_88 ( & V_34 -> V_107 ) ;
F_89 ( & V_23 -> V_108 , & V_34 -> V_109 ) ;
}
static void F_90 ( struct V_1 * V_2 , struct V_106 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_88 ( & V_34 -> V_107 ) ;
F_91 ( & V_23 -> V_108 ) ;
}
static inline unsigned long F_92 ( struct V_1 * V_2 , int V_110 )
{
struct V_106 * V_34 = F_93 ( V_2 , V_110 ) ;
return F_94 ( & V_34 -> V_111 ) ;
}
static inline unsigned long F_95 ( struct V_106 * V_34 )
{
return F_94 ( & V_34 -> V_111 ) ;
}
static inline void F_96 ( struct V_1 * V_2 , int V_110 , int V_30 )
{
struct V_106 * V_34 = F_93 ( V_2 , V_110 ) ;
if ( F_97 ( V_34 ) ) {
F_98 ( & V_34 -> V_111 ) ;
F_99 ( V_30 , & V_34 -> V_112 ) ;
}
}
static inline void F_100 ( struct V_1 * V_2 , int V_110 , int V_30 )
{
struct V_106 * V_34 = F_93 ( V_2 , V_110 ) ;
F_101 ( & V_34 -> V_111 ) ;
F_102 ( V_30 , & V_34 -> V_112 ) ;
}
static void F_103 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
if ( ! ( V_2 -> V_3 & ( V_65 | V_6 | V_81 ) ) )
return;
F_76 ( V_2 , V_11 , V_113 ) ;
F_61 ( V_2 , V_11 ) ;
}
static inline int F_104 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( ! F_84 ( V_2 , V_23 ) )
return 0 ;
if ( ! F_53 ( V_2 , V_23 , V_11 ) ) {
F_74 ( V_2 , V_23 , V_11 , L_39 ) ;
return 0 ;
}
if ( ! F_83 ( V_2 , V_23 , V_11 , V_113 ) )
return 0 ;
return 1 ;
}
static T_4 int F_105 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( V_2 -> V_3 & V_114 ) {
if ( ! F_104 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_115;
}
if ( V_2 -> V_3 & V_65 )
F_57 ( V_2 , V_11 , V_67 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 1 ) ;
F_76 ( V_2 , V_11 , V_98 ) ;
return 1 ;
V_115:
if ( F_85 ( V_23 ) ) {
F_69 ( V_2 , L_40 ) ;
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_38 = NULL ;
}
return 0 ;
}
static inline int F_106 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 )
{
if ( ! F_53 ( V_2 , V_23 , V_11 ) ) {
F_75 ( V_2 , V_23 , L_41 , V_11 ) ;
return 0 ;
}
if ( F_86 ( V_2 , V_23 , V_11 ) ) {
F_74 ( V_2 , V_23 , V_11 , L_42 ) ;
return 0 ;
}
if ( ! F_83 ( V_2 , V_23 , V_11 , V_98 ) )
return 0 ;
if ( F_3 ( V_2 != V_23 -> V_116 ) ) {
if ( ! F_85 ( V_23 ) ) {
F_75 ( V_2 , V_23 , L_43 ,
V_11 ) ;
} else if ( ! V_23 -> V_116 ) {
F_63 ( L_44 ,
V_11 ) ;
F_73 () ;
} else
F_74 ( V_2 , V_23 , V_11 ,
L_45 ) ;
return 0 ;
}
return 1 ;
}
static T_4 int F_107 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_119 ,
unsigned long V_14 )
{
struct V_106 * V_34 = F_93 ( V_2 , F_108 ( V_23 ) ) ;
void * V_11 = V_117 ;
int V_120 = 0 ;
unsigned long V_121 ( V_3 ) ;
int V_122 = 0 ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_26 ( V_23 ) ;
if ( V_2 -> V_3 & V_114 ) {
if ( ! F_84 ( V_2 , V_23 ) )
goto V_123;
}
V_124:
V_120 ++ ;
if ( V_2 -> V_3 & V_114 ) {
if ( ! F_106 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_123;
}
if ( V_2 -> V_3 & V_65 )
F_57 ( V_2 , V_11 , V_66 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 0 ) ;
F_76 ( V_2 , V_11 , V_113 ) ;
if ( V_11 != V_118 ) {
V_11 = F_14 ( V_2 , V_11 ) ;
goto V_124;
}
V_122 = 1 ;
V_123:
if ( V_120 != V_119 )
F_75 ( V_2 , V_23 , L_46 ,
V_119 , V_120 ) ;
F_30 ( V_23 ) ;
F_110 ( & V_34 -> V_107 , V_3 ) ;
if ( ! V_122 )
F_69 ( V_2 , L_47 , V_11 ) ;
return V_122 ;
}
static int T_5 F_111 ( char * V_125 )
{
V_126 = V_127 ;
if ( * V_125 ++ != '=' || ! * V_125 )
goto V_123;
if ( * V_125 == ',' )
goto V_128;
V_126 = 0 ;
if ( * V_125 == '-' )
goto V_123;
for (; * V_125 && * V_125 != ',' ; V_125 ++ ) {
switch ( tolower ( * V_125 ) ) {
case 'f' :
V_126 |= V_114 ;
break;
case 'z' :
V_126 |= V_6 ;
break;
case 'p' :
V_126 |= V_96 ;
break;
case 'u' :
V_126 |= V_65 ;
break;
case 't' :
V_126 |= V_104 ;
break;
case 'a' :
V_126 |= V_129 ;
break;
case 'o' :
V_130 = 1 ;
break;
default:
F_63 ( L_48 ,
* V_125 ) ;
}
}
V_128:
if ( * V_125 == ',' )
V_131 = V_125 + 1 ;
V_123:
return 1 ;
}
unsigned long F_112 ( unsigned long V_77 ,
unsigned long V_3 , const char * V_40 ,
void (* F_113)( void * ) )
{
if ( V_126 && ( ! V_131 || ( V_40 &&
! strncmp ( V_131 , V_40 , strlen ( V_131 ) ) ) ) )
V_3 |= V_126 ;
return V_3 ;
}
static inline void F_103 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 ) {}
static inline int F_105 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 ) { return 0 ; }
static inline int F_107 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_119 ,
unsigned long V_14 ) { return 0 ; }
static inline int F_81 ( struct V_1 * V_2 , struct V_23 * V_23 )
{ return 1 ; }
static inline int F_83 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_80 ) { return 1 ; }
static inline void F_87 ( struct V_1 * V_2 , struct V_106 * V_34 ,
struct V_23 * V_23 ) {}
static inline void F_90 ( struct V_1 * V_2 , struct V_106 * V_34 ,
struct V_23 * V_23 ) {}
unsigned long F_112 ( unsigned long V_77 ,
unsigned long V_3 , const char * V_40 ,
void (* F_113)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_92 ( struct V_1 * V_2 , int V_110 )
{ return 0 ; }
static inline unsigned long F_95 ( struct V_106 * V_34 )
{ return 0 ; }
static inline void F_96 ( struct V_1 * V_2 , int V_110 ,
int V_30 ) {}
static inline void F_100 ( struct V_1 * V_2 , int V_110 ,
int V_30 ) {}
static inline void F_114 ( void * V_132 , T_6 V_15 , T_7 V_3 )
{
F_115 ( V_132 , V_15 , 1 , V_3 ) ;
F_116 ( V_132 , V_15 , V_3 ) ;
}
static inline void F_117 ( const void * V_20 )
{
F_118 ( V_20 ) ;
F_119 ( V_20 ) ;
}
static inline void * F_120 ( struct V_1 * V_2 , void * V_20 )
{
void * V_133 ;
F_121 ( V_20 , V_2 -> V_3 ) ;
#if F_36 ( V_134 ) || F_36 ( V_135 )
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_122 ( V_2 , V_20 , V_2 -> V_77 ) ;
F_123 ( V_20 , V_2 -> V_77 ) ;
F_43 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_136 ) )
F_124 ( V_20 , V_2 -> V_77 ) ;
V_133 = F_14 ( V_2 , V_20 ) ;
F_125 ( V_2 , V_20 ) ;
return V_133 ;
}
static inline void F_126 ( struct V_1 * V_2 ,
void * V_117 , void * V_118 )
{
#if F_36 ( V_134 ) || \
F_36 ( V_135 ) || \
F_36 ( V_137 ) || \
F_36 ( V_138 ) || \
F_36 ( V_139 )
void * V_11 = V_117 ;
void * V_140 = V_118 ? : V_117 ;
void * V_133 ;
do {
V_133 = F_120 ( V_2 , V_11 ) ;
} while ( ( V_11 != V_140 ) && ( V_11 = V_133 ) );
#endif
}
static void F_127 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
F_103 ( V_2 , V_23 , V_11 ) ;
F_128 ( V_2 , V_11 ) ;
if ( F_3 ( V_2 -> F_113 ) ) {
F_129 ( V_2 , V_11 ) ;
V_2 -> F_113 ( V_11 ) ;
F_130 ( V_2 , V_11 ) ;
}
}
static inline struct V_23 * F_131 ( struct V_1 * V_2 ,
T_7 V_3 , int V_110 , struct V_19 V_141 )
{
struct V_23 * V_23 ;
int V_16 = F_24 ( V_141 ) ;
V_3 |= V_142 ;
if ( V_110 == V_143 )
V_23 = F_132 ( V_3 , V_16 ) ;
else
V_23 = F_133 ( V_110 , V_3 , V_16 ) ;
if ( V_23 && F_134 ( V_23 , V_3 , V_16 , V_2 ) ) {
F_135 ( V_23 , V_16 ) ;
V_23 = NULL ;
}
return V_23 ;
}
static int F_136 ( struct V_1 * V_2 )
{
int V_144 ;
unsigned long V_52 , V_145 = F_25 ( V_2 -> V_141 ) ;
if ( V_2 -> V_146 )
return 0 ;
V_144 = F_137 ( V_2 , V_145 , V_147 ) ;
if ( V_144 ) {
F_63 ( L_49 ,
V_2 -> V_40 ) ;
return V_144 ;
}
if ( V_2 -> V_146 ) {
for ( V_52 = 0 ; V_52 < V_145 ; V_52 ++ )
V_2 -> V_146 [ V_52 ] *= V_2 -> V_15 ;
}
return 0 ;
}
static void T_5 F_138 ( void )
{
struct V_1 * V_2 ;
F_139 ( & V_148 ) ;
F_140 (s, &slab_caches, list)
F_136 ( V_2 ) ;
F_141 ( & V_148 ) ;
}
static void * F_142 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_149 , void * V_89 ,
unsigned long V_150 ,
unsigned long V_151 )
{
unsigned int V_152 ;
do {
V_152 = V_2 -> V_146 [ * V_149 ] ;
* V_149 += 1 ;
if ( * V_149 >= V_151 )
* V_149 = 0 ;
} while ( F_3 ( V_152 >= V_150 ) );
return ( char * ) V_89 + V_152 ;
}
static bool F_143 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
void * V_89 ;
void * V_153 ;
void * V_154 ;
unsigned long V_152 , V_149 , V_150 , V_151 ;
if ( V_23 -> V_30 < 2 || ! V_2 -> V_146 )
return false ;
V_151 = F_25 ( V_2 -> V_141 ) ;
V_149 = F_144 () % V_151 ;
V_150 = V_23 -> V_30 * V_2 -> V_15 ;
V_89 = F_4 ( V_2 , F_45 ( V_23 ) ) ;
V_153 = F_142 ( V_2 , V_23 , & V_149 , V_89 , V_150 ,
V_151 ) ;
V_23 -> V_38 = V_153 ;
for ( V_152 = 1 ; V_152 < V_23 -> V_30 ; V_152 ++ ) {
F_127 ( V_2 , V_23 , V_153 ) ;
V_154 = F_142 ( V_2 , V_23 , & V_149 , V_89 , V_150 ,
V_151 ) ;
F_20 ( V_2 , V_153 , V_154 ) ;
V_153 = V_154 ;
}
F_127 ( V_2 , V_23 , V_153 ) ;
F_20 ( V_2 , V_153 , NULL ) ;
return true ;
}
static inline int F_136 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_138 ( void ) { }
static inline bool F_143 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
return false ;
}
static struct V_23 * F_145 ( struct V_1 * V_2 , T_7 V_3 , int V_110 )
{
struct V_23 * V_23 ;
struct V_19 V_141 = V_2 -> V_141 ;
T_7 V_155 ;
void * V_89 , * V_5 ;
int V_152 , V_16 ;
bool V_156 ;
V_3 &= V_157 ;
if ( F_146 ( V_3 ) )
F_147 () ;
V_3 |= V_2 -> V_158 ;
V_155 = ( V_3 | V_159 | V_160 ) & ~ V_161 ;
if ( ( V_155 & V_162 ) && F_24 ( V_141 ) > F_24 ( V_2 -> V_163 ) )
V_155 = ( V_155 | V_164 ) & ~ ( V_165 | V_161 ) ;
V_23 = F_131 ( V_2 , V_155 , V_110 , V_141 ) ;
if ( F_3 ( ! V_23 ) ) {
V_141 = V_2 -> V_163 ;
V_155 = V_3 ;
V_23 = F_131 ( V_2 , V_155 , V_110 , V_141 ) ;
if ( F_3 ( ! V_23 ) )
goto V_123;
F_11 ( V_2 , V_166 ) ;
}
if ( V_167 &&
! ( V_2 -> V_3 & ( V_168 | V_127 ) ) ) {
int V_169 = 1 << F_24 ( V_141 ) ;
F_148 ( V_23 , F_24 ( V_141 ) , V_155 , V_110 ) ;
if ( V_2 -> F_113 )
F_149 ( V_23 , V_169 ) ;
else
F_150 ( V_23 , V_169 ) ;
}
V_23 -> V_30 = F_25 ( V_141 ) ;
V_16 = F_82 ( V_23 ) ;
V_23 -> V_116 = V_2 ;
F_151 ( V_23 ) ;
if ( F_152 ( V_23 ) )
F_153 ( V_23 ) ;
V_89 = F_45 ( V_23 ) ;
if ( F_3 ( V_2 -> V_3 & V_96 ) )
memset ( V_89 , V_94 , V_18 << V_16 ) ;
F_154 ( V_23 ) ;
V_156 = F_143 ( V_2 , V_23 ) ;
if ( ! V_156 ) {
F_155 (p, idx, s, start, page->objects) {
F_127 ( V_2 , V_23 , V_5 ) ;
if ( F_97 ( V_152 < V_23 -> V_30 ) )
F_20 ( V_2 , V_5 , V_5 + V_2 -> V_15 ) ;
else
F_20 ( V_2 , V_5 , NULL ) ;
}
V_23 -> V_38 = F_4 ( V_2 , V_89 ) ;
}
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_28 = 1 ;
V_123:
if ( F_146 ( V_3 ) )
F_156 () ;
if ( ! V_23 )
return NULL ;
F_157 ( V_23 ,
( V_2 -> V_3 & V_170 ) ?
V_171 : V_172 ,
1 << F_24 ( V_141 ) ) ;
F_96 ( V_2 , F_108 ( V_23 ) , V_23 -> V_30 ) ;
return V_23 ;
}
static struct V_23 * F_158 ( struct V_1 * V_2 , T_7 V_3 , int V_110 )
{
if ( F_3 ( V_3 & V_173 ) ) {
T_7 V_174 = V_3 & V_173 ;
V_3 &= ~ V_173 ;
F_159 ( L_50 ,
V_174 , & V_174 , V_3 , & V_3 ) ;
F_73 () ;
}
return F_145 ( V_2 ,
V_3 & ( V_175 | V_176 ) , V_110 ) ;
}
static void F_160 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_16 = F_82 ( V_23 ) ;
int V_169 = 1 << V_16 ;
if ( V_2 -> V_3 & V_114 ) {
void * V_5 ;
F_81 ( V_2 , V_23 ) ;
F_161 (p, s, page_address(page),
page->objects)
F_83 ( V_2 , V_23 , V_5 , V_113 ) ;
}
F_162 ( V_23 , F_82 ( V_23 ) ) ;
F_157 ( V_23 ,
( V_2 -> V_3 & V_170 ) ?
V_171 : V_172 ,
- V_169 ) ;
F_163 ( V_23 ) ;
F_164 ( V_23 ) ;
F_165 ( V_23 ) ;
if ( V_62 -> V_177 )
V_62 -> V_177 -> V_178 += V_169 ;
F_166 ( V_23 , V_16 , V_2 ) ;
F_135 ( V_23 , V_16 ) ;
}
static void F_167 ( struct V_179 * V_180 )
{
struct V_23 * V_23 ;
if ( V_181 )
V_23 = F_168 ( V_180 ) ;
else
V_23 = F_169 ( (struct V_182 * ) V_180 , struct V_23 , V_108 ) ;
F_160 ( V_23 -> V_116 , V_23 ) ;
}
static void F_170 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
if ( F_3 ( V_2 -> V_3 & V_183 ) ) {
struct V_179 * V_117 ;
if ( V_181 ) {
int V_16 = F_82 ( V_23 ) ;
int V_12 = ( V_18 << V_16 ) - V_2 -> V_17 ;
F_34 ( V_2 -> V_17 != sizeof( * V_117 ) ) ;
V_117 = F_45 ( V_23 ) + V_12 ;
} else {
V_117 = & V_23 -> V_179 ;
}
F_171 ( V_117 , F_167 ) ;
} else
F_160 ( V_2 , V_23 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_100 ( V_2 , F_108 ( V_23 ) , V_23 -> V_30 ) ;
F_170 ( V_2 , V_23 ) ;
}
static inline void
F_173 ( struct V_106 * V_34 , struct V_23 * V_23 , int V_118 )
{
V_34 -> V_184 ++ ;
if ( V_118 == V_185 )
F_174 ( & V_23 -> V_108 , & V_34 -> V_186 ) ;
else
F_89 ( & V_23 -> V_108 , & V_34 -> V_186 ) ;
}
static inline void F_175 ( struct V_106 * V_34 ,
struct V_23 * V_23 , int V_118 )
{
F_88 ( & V_34 -> V_107 ) ;
F_173 ( V_34 , V_23 , V_118 ) ;
}
static inline void F_176 ( struct V_106 * V_34 ,
struct V_23 * V_23 )
{
F_88 ( & V_34 -> V_107 ) ;
F_91 ( & V_23 -> V_108 ) ;
V_34 -> V_184 -- ;
}
static inline void * F_177 ( struct V_1 * V_2 ,
struct V_106 * V_34 , struct V_23 * V_23 ,
int V_187 , int * V_30 )
{
void * V_38 ;
unsigned long V_27 ;
struct V_23 V_188 ;
F_88 ( & V_34 -> V_107 ) ;
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_188 . V_27 = V_27 ;
* V_30 = V_188 . V_30 - V_188 . V_29 ;
if ( V_187 ) {
V_188 . V_29 = V_23 -> V_30 ;
V_188 . V_38 = NULL ;
} else {
V_188 . V_38 = V_38 ;
}
F_34 ( V_188 . V_28 ) ;
V_188 . V_28 = 1 ;
if ( ! F_33 ( V_2 , V_23 ,
V_38 , V_27 ,
V_188 . V_38 , V_188 . V_27 ,
L_51 ) )
return NULL ;
F_176 ( V_34 , V_23 ) ;
F_178 ( ! V_38 ) ;
return V_38 ;
}
static void * F_179 ( struct V_1 * V_2 , struct V_106 * V_34 ,
struct V_189 * V_190 , T_7 V_3 )
{
struct V_23 * V_23 , * V_191 ;
void * V_11 = NULL ;
int V_192 = 0 ;
int V_30 ;
if ( ! V_34 || ! V_34 -> V_184 )
return NULL ;
F_180 ( & V_34 -> V_107 ) ;
F_181 (page, page2, &n->partial, lru) {
void * V_68 ;
if ( ! F_182 ( V_23 , V_3 ) )
continue;
V_68 = F_177 ( V_2 , V_34 , V_23 , V_11 == NULL , & V_30 ) ;
if ( ! V_68 )
break;
V_192 += V_30 ;
if ( ! V_11 ) {
V_190 -> V_23 = V_23 ;
F_11 ( V_2 , V_193 ) ;
V_11 = V_68 ;
} else {
F_183 ( V_2 , V_23 , 0 ) ;
F_11 ( V_2 , V_194 ) ;
}
if ( ! F_5 ( V_2 )
|| V_192 > F_184 ( V_2 ) / 2 )
break;
}
F_185 ( & V_34 -> V_107 ) ;
return V_11 ;
}
static void * F_186 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_189 * V_190 )
{
#ifdef F_187
struct V_195 * V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_198 ;
enum V_199 V_200 = F_188 ( V_3 ) ;
void * V_11 ;
unsigned int V_201 ;
if ( ! V_2 -> V_202 ||
F_189 () % 1024 > V_2 -> V_202 )
return NULL ;
do {
V_201 = F_190 () ;
V_195 = F_191 ( F_192 () , V_3 ) ;
F_193 (zone, z, zonelist, high_zoneidx) {
struct V_106 * V_34 ;
V_34 = F_93 ( V_2 , F_194 ( V_198 ) ) ;
if ( V_34 && F_195 ( V_198 , V_3 ) &&
V_34 -> V_184 > V_2 -> V_203 ) {
V_11 = F_179 ( V_2 , V_34 , V_190 , V_3 ) ;
if ( V_11 ) {
return V_11 ;
}
}
}
} while ( F_196 ( V_201 ) );
#endif
return NULL ;
}
static void * F_197 ( struct V_1 * V_2 , T_7 V_3 , int V_110 ,
struct V_189 * V_190 )
{
void * V_11 ;
int V_204 = V_110 ;
if ( V_110 == V_143 )
V_204 = F_198 () ;
else if ( ! F_199 ( V_110 ) )
V_204 = F_200 ( V_110 ) ;
V_11 = F_179 ( V_2 , F_93 ( V_2 , V_204 ) , V_190 , V_3 ) ;
if ( V_11 || V_110 != V_143 )
return V_11 ;
return F_186 ( V_2 , V_3 , V_190 ) ;
}
static inline unsigned long F_201 ( unsigned long V_205 )
{
return V_205 + V_206 ;
}
static inline unsigned int F_202 ( unsigned long V_205 )
{
return V_205 % V_206 ;
}
static inline unsigned long F_203 ( unsigned long V_205 )
{
return V_205 / V_206 ;
}
static inline unsigned int F_204 ( int V_60 )
{
return V_60 ;
}
static inline void F_205 ( const char * V_34 ,
const struct V_1 * V_2 , unsigned long V_205 )
{
#ifdef F_39
unsigned long V_207 = F_206 ( V_2 -> V_10 -> V_205 ) ;
F_40 ( L_52 , V_34 , V_2 -> V_40 ) ;
#ifdef F_207
if ( F_202 ( V_205 ) != F_202 ( V_207 ) )
F_159 ( L_53 ,
F_202 ( V_205 ) , F_202 ( V_207 ) ) ;
else
#endif
if ( F_203 ( V_205 ) != F_203 ( V_207 ) )
F_159 ( L_54 ,
F_203 ( V_205 ) , F_203 ( V_207 ) ) ;
else
F_159 ( L_55 ,
V_207 , V_205 , F_201 ( V_205 ) ) ;
#endif
F_11 ( V_2 , V_208 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
int V_60 ;
F_209 (cpu)
F_210 ( V_2 -> V_10 , V_60 ) -> V_205 = F_204 ( V_60 ) ;
}
static void F_211 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_38 , struct V_189 * V_190 )
{
enum T_8 { V_209 , V_210 , V_211 , V_212 };
struct V_106 * V_34 = F_93 ( V_2 , F_108 ( V_23 ) ) ;
int V_213 = 0 ;
enum T_8 V_214 = V_209 , V_215 = V_209 ;
void * V_216 ;
int V_118 = V_217 ;
struct V_23 V_188 ;
struct V_23 V_218 ;
if ( V_23 -> V_38 ) {
F_11 ( V_2 , V_219 ) ;
V_118 = V_185 ;
}
while ( V_38 && ( V_216 = F_14 ( V_2 , V_38 ) ) ) {
void * V_220 ;
unsigned long V_27 ;
do {
V_220 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_20 ( V_2 , V_38 , V_220 ) ;
V_188 . V_27 = V_27 ;
V_188 . V_29 -- ;
F_34 ( ! V_188 . V_28 ) ;
} while ( ! F_33 ( V_2 , V_23 ,
V_220 , V_27 ,
V_38 , V_188 . V_27 ,
L_56 ) );
V_38 = V_216 ;
}
V_221:
V_218 . V_38 = V_23 -> V_38 ;
V_218 . V_27 = V_23 -> V_27 ;
F_34 ( ! V_218 . V_28 ) ;
V_188 . V_27 = V_218 . V_27 ;
if ( V_38 ) {
V_188 . V_29 -- ;
F_20 ( V_2 , V_38 , V_218 . V_38 ) ;
V_188 . V_38 = V_38 ;
} else
V_188 . V_38 = V_218 . V_38 ;
V_188 . V_28 = 0 ;
if ( ! V_188 . V_29 && V_34 -> V_184 >= V_2 -> V_203 )
V_215 = V_212 ;
else if ( V_188 . V_38 ) {
V_215 = V_210 ;
if ( ! V_213 ) {
V_213 = 1 ;
F_180 ( & V_34 -> V_107 ) ;
}
} else {
V_215 = V_211 ;
if ( F_1 ( V_2 ) && ! V_213 ) {
V_213 = 1 ;
F_180 ( & V_34 -> V_107 ) ;
}
}
if ( V_214 != V_215 ) {
if ( V_214 == V_210 )
F_176 ( V_34 , V_23 ) ;
else if ( V_214 == V_211 )
F_90 ( V_2 , V_34 , V_23 ) ;
if ( V_215 == V_210 ) {
F_175 ( V_34 , V_23 , V_118 ) ;
F_11 ( V_2 , V_118 ) ;
} else if ( V_215 == V_211 ) {
F_11 ( V_2 , V_222 ) ;
F_87 ( V_2 , V_34 , V_23 ) ;
}
}
V_214 = V_215 ;
if ( ! F_33 ( V_2 , V_23 ,
V_218 . V_38 , V_218 . V_27 ,
V_188 . V_38 , V_188 . V_27 ,
L_57 ) )
goto V_221;
if ( V_213 )
F_185 ( & V_34 -> V_107 ) ;
if ( V_215 == V_212 ) {
F_11 ( V_2 , V_223 ) ;
F_172 ( V_2 , V_23 ) ;
F_11 ( V_2 , V_224 ) ;
}
V_190 -> V_23 = NULL ;
V_190 -> V_38 = NULL ;
}
static void F_212 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
#ifdef F_6
struct V_106 * V_34 = NULL , * V_225 = NULL ;
struct V_23 * V_23 , * V_226 = NULL ;
while ( ( V_23 = V_190 -> V_186 ) ) {
struct V_23 V_188 ;
struct V_23 V_218 ;
V_190 -> V_186 = V_23 -> V_154 ;
V_225 = F_93 ( V_2 , F_108 ( V_23 ) ) ;
if ( V_34 != V_225 ) {
if ( V_34 )
F_185 ( & V_34 -> V_107 ) ;
V_34 = V_225 ;
F_180 ( & V_34 -> V_107 ) ;
}
do {
V_218 . V_38 = V_23 -> V_38 ;
V_218 . V_27 = V_23 -> V_27 ;
F_34 ( ! V_218 . V_28 ) ;
V_188 . V_27 = V_218 . V_27 ;
V_188 . V_38 = V_218 . V_38 ;
V_188 . V_28 = 0 ;
} while ( ! F_33 ( V_2 , V_23 ,
V_218 . V_38 , V_218 . V_27 ,
V_188 . V_38 , V_188 . V_27 ,
L_57 ) );
if ( F_3 ( ! V_188 . V_29 && V_34 -> V_184 >= V_2 -> V_203 ) ) {
V_23 -> V_154 = V_226 ;
V_226 = V_23 ;
} else {
F_175 ( V_34 , V_23 , V_185 ) ;
F_11 ( V_2 , V_227 ) ;
}
}
if ( V_34 )
F_185 ( & V_34 -> V_107 ) ;
while ( V_226 ) {
V_23 = V_226 ;
V_226 = V_226 -> V_154 ;
F_11 ( V_2 , V_223 ) ;
F_172 ( V_2 , V_23 ) ;
F_11 ( V_2 , V_224 ) ;
}
#endif
}
static void F_183 ( struct V_1 * V_2 , struct V_23 * V_23 , int V_228 )
{
#ifdef F_6
struct V_23 * V_229 ;
int V_169 ;
int V_230 ;
F_213 () ;
do {
V_169 = 0 ;
V_230 = 0 ;
V_229 = F_214 ( V_2 -> V_10 -> V_186 ) ;
if ( V_229 ) {
V_230 = V_229 -> V_230 ;
V_169 = V_229 -> V_169 ;
if ( V_228 && V_230 > V_2 -> V_231 ) {
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_212 ( V_2 , F_215 ( V_2 -> V_10 ) ) ;
F_43 ( V_3 ) ;
V_229 = NULL ;
V_230 = 0 ;
V_169 = 0 ;
F_11 ( V_2 , V_232 ) ;
}
}
V_169 ++ ;
V_230 += V_23 -> V_30 - V_23 -> V_29 ;
V_23 -> V_169 = V_169 ;
V_23 -> V_230 = V_230 ;
V_23 -> V_154 = V_229 ;
} while ( F_216 ( V_2 -> V_10 -> V_186 , V_229 , V_23 )
!= V_229 );
if ( F_3 ( ! V_2 -> V_231 ) ) {
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_212 ( V_2 , F_215 ( V_2 -> V_10 ) ) ;
F_43 ( V_3 ) ;
}
F_217 () ;
#endif
}
static inline void F_218 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
F_11 ( V_2 , V_233 ) ;
F_211 ( V_2 , V_190 -> V_23 , V_190 -> V_38 , V_190 ) ;
V_190 -> V_205 = F_201 ( V_190 -> V_205 ) ;
}
static inline void F_219 ( struct V_1 * V_2 , int V_60 )
{
struct V_189 * V_190 = F_210 ( V_2 -> V_10 , V_60 ) ;
if ( F_97 ( V_190 ) ) {
if ( V_190 -> V_23 )
F_218 ( V_2 , V_190 ) ;
F_212 ( V_2 , V_190 ) ;
}
}
static void F_220 ( void * V_234 )
{
struct V_1 * V_2 = V_234 ;
F_219 ( V_2 , F_60 () ) ;
}
static bool F_221 ( int V_60 , void * V_235 )
{
struct V_1 * V_2 = V_235 ;
struct V_189 * V_190 = F_210 ( V_2 -> V_10 , V_60 ) ;
return V_190 -> V_23 || F_222 ( V_190 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
F_224 ( F_221 , F_220 , V_2 , 1 , V_236 ) ;
}
static int F_225 ( unsigned int V_60 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
F_139 ( & V_148 ) ;
F_140 (s, &slab_caches, list) {
F_42 ( V_3 ) ;
F_219 ( V_2 , V_60 ) ;
F_43 ( V_3 ) ;
}
F_141 ( & V_148 ) ;
return 0 ;
}
static inline int F_226 ( struct V_23 * V_23 , int V_110 )
{
#ifdef F_187
if ( ! V_23 || ( V_110 != V_143 && F_108 ( V_23 ) != V_110 ) )
return 0 ;
#endif
return 1 ;
}
static int F_227 ( struct V_23 * V_23 )
{
return V_23 -> V_30 - V_23 -> V_29 ;
}
static inline unsigned long F_228 ( struct V_106 * V_34 )
{
return F_94 ( & V_34 -> V_112 ) ;
}
static unsigned long F_229 ( struct V_106 * V_34 ,
int (* F_230)( struct V_23 * ) )
{
unsigned long V_3 ;
unsigned long V_20 = 0 ;
struct V_23 * V_23 ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_140 (page, &n->partial, lru)
V_20 += F_230 ( V_23 ) ;
F_110 ( & V_34 -> V_107 , V_3 ) ;
return V_20 ;
}
static T_4 void
F_231 ( struct V_1 * V_2 , T_7 V_237 , int V_238 )
{
#ifdef F_2
static F_232 ( V_239 , V_240 ,
V_241 ) ;
int V_110 ;
struct V_106 * V_34 ;
if ( ( V_237 & V_159 ) || ! F_233 ( & V_239 ) )
return;
F_159 ( L_58 ,
V_238 , V_237 , & V_237 ) ;
F_159 ( L_59 ,
V_2 -> V_40 , V_2 -> V_77 , V_2 -> V_15 , F_24 ( V_2 -> V_141 ) ,
F_24 ( V_2 -> V_163 ) ) ;
if ( F_24 ( V_2 -> V_163 ) > F_234 ( V_2 -> V_77 ) )
F_159 ( L_60 ,
V_2 -> V_40 ) ;
F_235 (s, node, n) {
unsigned long V_111 ;
unsigned long V_242 ;
unsigned long V_243 ;
V_243 = F_229 ( V_34 , F_227 ) ;
V_111 = F_95 ( V_34 ) ;
V_242 = F_228 ( V_34 ) ;
F_159 ( L_61 ,
V_110 , V_111 , V_242 , V_243 ) ;
}
#endif
}
static inline void * F_236 ( struct V_1 * V_2 , T_7 V_3 ,
int V_110 , struct V_189 * * V_244 )
{
void * V_38 ;
struct V_189 * V_190 = * V_244 ;
struct V_23 * V_23 ;
V_38 = F_197 ( V_2 , V_3 , V_110 , V_190 ) ;
if ( V_38 )
return V_38 ;
V_23 = F_158 ( V_2 , V_3 , V_110 ) ;
if ( V_23 ) {
V_190 = F_237 ( V_2 -> V_10 ) ;
if ( V_190 -> V_23 )
F_218 ( V_2 , V_190 ) ;
V_38 = V_23 -> V_38 ;
V_23 -> V_38 = NULL ;
F_11 ( V_2 , V_245 ) ;
V_190 -> V_23 = V_23 ;
* V_244 = V_190 ;
} else
V_38 = NULL ;
return V_38 ;
}
static inline bool F_182 ( struct V_23 * V_23 , T_7 V_237 )
{
if ( F_3 ( F_238 ( V_23 ) ) )
return F_239 ( V_237 ) ;
return true ;
}
static inline void * F_240 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_23 V_188 ;
unsigned long V_27 ;
void * V_38 ;
do {
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_188 . V_27 = V_27 ;
F_34 ( ! V_188 . V_28 ) ;
V_188 . V_29 = V_23 -> V_30 ;
V_188 . V_28 = V_38 != NULL ;
} while ( ! F_33 ( V_2 , V_23 ,
V_38 , V_27 ,
NULL , V_188 . V_27 ,
L_62 ) );
return V_38 ;
}
static void * F_241 ( struct V_1 * V_2 , T_7 V_237 , int V_110 ,
unsigned long V_14 , struct V_189 * V_190 )
{
void * V_38 ;
struct V_23 * V_23 ;
V_23 = V_190 -> V_23 ;
if ( ! V_23 )
goto F_158;
V_221:
if ( F_3 ( ! F_226 ( V_23 , V_110 ) ) ) {
int V_204 = V_110 ;
if ( V_110 != V_143 && ! F_199 ( V_110 ) )
V_204 = F_200 ( V_110 ) ;
if ( F_3 ( ! F_226 ( V_23 , V_204 ) ) ) {
F_11 ( V_2 , V_246 ) ;
F_211 ( V_2 , V_23 , V_190 -> V_38 , V_190 ) ;
goto F_158;
}
}
if ( F_3 ( ! F_182 ( V_23 , V_237 ) ) ) {
F_211 ( V_2 , V_23 , V_190 -> V_38 , V_190 ) ;
goto F_158;
}
V_38 = V_190 -> V_38 ;
if ( V_38 )
goto V_247;
V_38 = F_240 ( V_2 , V_23 ) ;
if ( ! V_38 ) {
V_190 -> V_23 = NULL ;
F_11 ( V_2 , V_248 ) ;
goto F_158;
}
F_11 ( V_2 , V_249 ) ;
V_247:
F_34 ( ! V_190 -> V_23 -> V_28 ) ;
V_190 -> V_38 = F_14 ( V_2 , V_38 ) ;
V_190 -> V_205 = F_201 ( V_190 -> V_205 ) ;
return V_38 ;
F_158:
if ( F_222 ( V_190 ) ) {
V_23 = V_190 -> V_23 = F_222 ( V_190 ) ;
F_242 ( V_190 , V_23 ) ;
F_11 ( V_2 , V_250 ) ;
goto V_221;
}
V_38 = F_236 ( V_2 , V_237 , V_110 , & V_190 ) ;
if ( F_3 ( ! V_38 ) ) {
F_231 ( V_2 , V_237 , V_110 ) ;
return NULL ;
}
V_23 = V_190 -> V_23 ;
if ( F_97 ( ! F_1 ( V_2 ) && F_182 ( V_23 , V_237 ) ) )
goto V_247;
if ( F_1 ( V_2 ) &&
! F_105 ( V_2 , V_23 , V_38 , V_14 ) )
goto F_158;
F_211 ( V_2 , V_23 , F_14 ( V_2 , V_38 ) , V_190 ) ;
return V_38 ;
}
static void * F_243 ( struct V_1 * V_2 , T_7 V_237 , int V_110 ,
unsigned long V_14 , struct V_189 * V_190 )
{
void * V_5 ;
unsigned long V_3 ;
F_42 ( V_3 ) ;
#ifdef F_207
V_190 = F_215 ( V_2 -> V_10 ) ;
#endif
V_5 = F_241 ( V_2 , V_237 , V_110 , V_14 , V_190 ) ;
F_43 ( V_3 ) ;
return V_5 ;
}
static T_1 void * F_244 ( struct V_1 * V_2 ,
T_7 V_237 , int V_110 , unsigned long V_14 )
{
void * V_11 ;
struct V_189 * V_190 ;
struct V_23 * V_23 ;
unsigned long V_205 ;
V_2 = F_245 ( V_2 , V_237 ) ;
if ( ! V_2 )
return NULL ;
V_221:
do {
V_205 = F_214 ( V_2 -> V_10 -> V_205 ) ;
V_190 = F_237 ( V_2 -> V_10 ) ;
} while ( F_246 ( F_207 ) &&
F_3 ( V_205 != F_247 ( V_190 -> V_205 ) ) );
F_248 () ;
V_11 = V_190 -> V_38 ;
V_23 = V_190 -> V_23 ;
if ( F_3 ( ! V_11 || ! F_226 ( V_23 , V_110 ) ) ) {
V_11 = F_243 ( V_2 , V_237 , V_110 , V_14 , V_190 ) ;
F_11 ( V_2 , V_251 ) ;
} else {
void * V_124 = F_17 ( V_2 , V_11 ) ;
if ( F_3 ( ! F_249 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_205 ,
V_11 , V_205 ,
V_124 , F_201 ( V_205 ) ) ) ) {
F_205 ( L_63 , V_2 , V_205 ) ;
goto V_221;
}
F_15 ( V_2 , V_124 ) ;
F_11 ( V_2 , V_252 ) ;
}
if ( F_3 ( V_237 & V_253 ) && V_11 )
memset ( V_11 , 0 , V_2 -> V_77 ) ;
F_250 ( V_2 , V_237 , 1 , & V_11 ) ;
return V_11 ;
}
static T_1 void * F_251 ( struct V_1 * V_2 ,
T_7 V_237 , unsigned long V_14 )
{
return F_244 ( V_2 , V_237 , V_143 , V_14 ) ;
}
void * F_252 ( struct V_1 * V_2 , T_7 V_237 )
{
void * V_122 = F_251 ( V_2 , V_237 , V_254 ) ;
F_253 ( V_254 , V_122 , V_2 -> V_77 ,
V_2 -> V_15 , V_237 ) ;
return V_122 ;
}
void * F_254 ( struct V_1 * V_2 , T_7 V_237 , T_6 V_15 )
{
void * V_122 = F_251 ( V_2 , V_237 , V_254 ) ;
F_255 ( V_254 , V_122 , V_15 , V_2 -> V_15 , V_237 ) ;
F_256 ( V_2 , V_122 , V_15 , V_237 ) ;
return V_122 ;
}
void * F_257 ( struct V_1 * V_2 , T_7 V_237 , int V_110 )
{
void * V_122 = F_244 ( V_2 , V_237 , V_110 , V_254 ) ;
F_258 ( V_254 , V_122 ,
V_2 -> V_77 , V_2 -> V_15 , V_237 , V_110 ) ;
return V_122 ;
}
void * F_259 ( struct V_1 * V_2 ,
T_7 V_237 ,
int V_110 , T_6 V_15 )
{
void * V_122 = F_244 ( V_2 , V_237 , V_110 , V_254 ) ;
F_260 ( V_254 , V_122 ,
V_15 , V_2 -> V_15 , V_237 , V_110 ) ;
F_256 ( V_2 , V_122 , V_15 , V_237 ) ;
return V_122 ;
}
static void F_261 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_120 ,
unsigned long V_14 )
{
void * V_220 ;
int V_255 ;
struct V_23 V_188 ;
unsigned long V_27 ;
struct V_106 * V_34 = NULL ;
unsigned long V_121 ( V_3 ) ;
F_11 ( V_2 , V_256 ) ;
if ( F_1 ( V_2 ) &&
! F_107 ( V_2 , V_23 , V_117 , V_118 , V_120 , V_14 ) )
return;
do {
if ( F_3 ( V_34 ) ) {
F_110 ( & V_34 -> V_107 , V_3 ) ;
V_34 = NULL ;
}
V_220 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_20 ( V_2 , V_118 , V_220 ) ;
V_188 . V_27 = V_27 ;
V_255 = V_188 . V_28 ;
V_188 . V_29 -= V_120 ;
if ( ( ! V_188 . V_29 || ! V_220 ) && ! V_255 ) {
if ( F_5 ( V_2 ) && ! V_220 ) {
V_188 . V_28 = 1 ;
} else {
V_34 = F_93 ( V_2 , F_108 ( V_23 ) ) ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
}
}
} while ( ! F_41 ( V_2 , V_23 ,
V_220 , V_27 ,
V_117 , V_188 . V_27 ,
L_64 ) );
if ( F_97 ( ! V_34 ) ) {
if ( V_188 . V_28 && ! V_255 ) {
F_183 ( V_2 , V_23 , 1 ) ;
F_11 ( V_2 , V_257 ) ;
}
if ( V_255 )
F_11 ( V_2 , V_258 ) ;
return;
}
if ( F_3 ( ! V_188 . V_29 && V_34 -> V_184 >= V_2 -> V_203 ) )
goto V_259;
if ( ! F_5 ( V_2 ) && F_3 ( ! V_220 ) ) {
if ( F_1 ( V_2 ) )
F_90 ( V_2 , V_34 , V_23 ) ;
F_175 ( V_34 , V_23 , V_185 ) ;
F_11 ( V_2 , V_227 ) ;
}
F_110 ( & V_34 -> V_107 , V_3 ) ;
return;
V_259:
if ( V_220 ) {
F_176 ( V_34 , V_23 ) ;
F_11 ( V_2 , V_260 ) ;
} else {
F_90 ( V_2 , V_34 , V_23 ) ;
}
F_110 ( & V_34 -> V_107 , V_3 ) ;
F_11 ( V_2 , V_224 ) ;
F_172 ( V_2 , V_23 ) ;
}
static T_1 void F_262 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_117 , void * V_118 ,
int V_120 , unsigned long V_14 )
{
void * V_140 = V_118 ? : V_117 ;
struct V_189 * V_190 ;
unsigned long V_205 ;
V_221:
do {
V_205 = F_214 ( V_2 -> V_10 -> V_205 ) ;
V_190 = F_237 ( V_2 -> V_10 ) ;
} while ( F_246 ( F_207 ) &&
F_3 ( V_205 != F_247 ( V_190 -> V_205 ) ) );
F_248 () ;
if ( F_97 ( V_23 == V_190 -> V_23 ) ) {
F_20 ( V_2 , V_140 , V_190 -> V_38 ) ;
if ( F_3 ( ! F_249 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_205 ,
V_190 -> V_38 , V_205 ,
V_117 , F_201 ( V_205 ) ) ) ) {
F_205 ( L_65 , V_2 , V_205 ) ;
goto V_221;
}
F_11 ( V_2 , V_261 ) ;
} else
F_261 ( V_2 , V_23 , V_117 , V_140 , V_120 , V_14 ) ;
}
static T_1 void F_263 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_120 ,
unsigned long V_14 )
{
F_126 ( V_2 , V_117 , V_118 ) ;
if ( V_2 -> V_3 & V_262 && ! ( V_2 -> V_3 & V_183 ) )
return;
F_262 ( V_2 , V_23 , V_117 , V_118 , V_120 , V_14 ) ;
}
void F_264 ( struct V_1 * V_263 , void * V_20 , unsigned long V_14 )
{
F_262 ( V_263 , F_168 ( V_20 ) , V_20 , NULL , 1 , V_14 ) ;
}
void F_265 ( struct V_1 * V_2 , void * V_20 )
{
V_2 = F_266 ( V_2 , V_20 ) ;
if ( ! V_2 )
return;
F_263 ( V_2 , F_168 ( V_20 ) , V_20 , NULL , 1 , V_254 ) ;
F_267 ( V_254 , V_20 ) ;
}
static inline
int F_268 ( struct V_1 * V_2 , T_6 V_15 ,
void * * V_5 , struct V_264 * V_265 )
{
T_6 V_266 = 0 ;
int V_267 = 3 ;
void * V_11 ;
struct V_23 * V_23 ;
V_265 -> V_23 = NULL ;
do {
V_11 = V_5 [ -- V_15 ] ;
} while ( ! V_11 && V_15 );
if ( ! V_11 )
return 0 ;
V_23 = F_168 ( V_11 ) ;
if ( ! V_2 ) {
if ( F_3 ( ! F_85 ( V_23 ) ) ) {
F_269 ( ! F_270 ( V_23 ) ) ;
F_117 ( V_11 ) ;
F_135 ( V_23 , F_82 ( V_23 ) ) ;
V_5 [ V_15 ] = NULL ;
return V_15 ;
}
V_265 -> V_2 = V_23 -> V_116 ;
} else {
V_265 -> V_2 = F_266 ( V_2 , V_11 ) ;
}
V_265 -> V_23 = V_23 ;
F_20 ( V_265 -> V_2 , V_11 , NULL ) ;
V_265 -> V_118 = V_11 ;
V_265 -> V_38 = V_11 ;
V_5 [ V_15 ] = NULL ;
V_265 -> V_120 = 1 ;
while ( V_15 ) {
V_11 = V_5 [ -- V_15 ] ;
if ( ! V_11 )
continue;
if ( V_265 -> V_23 == F_168 ( V_11 ) ) {
F_20 ( V_265 -> V_2 , V_11 , V_265 -> V_38 ) ;
V_265 -> V_38 = V_11 ;
V_265 -> V_120 ++ ;
V_5 [ V_15 ] = NULL ;
continue;
}
if ( ! -- V_267 )
break;
if ( ! V_266 )
V_266 = V_15 + 1 ;
}
return V_266 ;
}
void F_271 ( struct V_1 * V_2 , T_6 V_15 , void * * V_5 )
{
if ( F_178 ( ! V_15 ) )
return;
do {
struct V_264 V_265 ;
V_15 = F_268 ( V_2 , V_15 , V_5 , & V_265 ) ;
if ( ! V_265 . V_23 )
continue;
F_263 ( V_265 . V_2 , V_265 . V_23 , V_265 . V_38 , V_265 . V_118 , V_265 . V_120 , V_254 ) ;
} while ( F_97 ( V_15 ) );
}
int F_272 ( struct V_1 * V_2 , T_7 V_3 , T_6 V_15 ,
void * * V_5 )
{
struct V_189 * V_190 ;
int V_52 ;
V_2 = F_245 ( V_2 , V_3 ) ;
if ( F_3 ( ! V_2 ) )
return false ;
F_156 () ;
V_190 = F_215 ( V_2 -> V_10 ) ;
for ( V_52 = 0 ; V_52 < V_15 ; V_52 ++ ) {
void * V_11 = V_190 -> V_38 ;
if ( F_3 ( ! V_11 ) ) {
V_5 [ V_52 ] = F_241 ( V_2 , V_3 , V_143 ,
V_254 , V_190 ) ;
if ( F_3 ( ! V_5 [ V_52 ] ) )
goto error;
V_190 = F_215 ( V_2 -> V_10 ) ;
continue;
}
V_190 -> V_38 = F_14 ( V_2 , V_11 ) ;
V_5 [ V_52 ] = V_11 ;
}
V_190 -> V_205 = F_201 ( V_190 -> V_205 ) ;
F_147 () ;
if ( F_3 ( V_3 & V_253 ) ) {
int V_268 ;
for ( V_268 = 0 ; V_268 < V_52 ; V_268 ++ )
memset ( V_5 [ V_268 ] , 0 , V_2 -> V_77 ) ;
}
F_250 ( V_2 , V_3 , V_15 , V_5 ) ;
return V_52 ;
error:
F_147 () ;
F_250 ( V_2 , V_3 , V_52 , V_5 ) ;
F_273 ( V_2 , V_52 , V_5 ) ;
return 0 ;
}
static inline int F_274 ( int V_15 , int V_269 ,
int V_270 , int V_271 , int V_17 )
{
int V_16 ;
int V_272 ;
int V_273 = V_274 ;
if ( F_22 ( V_273 , V_15 , V_17 ) > V_103 )
return F_234 ( V_15 * V_103 ) - 1 ;
for ( V_16 = F_275 ( V_273 , F_234 ( V_269 * V_15 + V_17 ) ) ;
V_16 <= V_270 ; V_16 ++ ) {
unsigned long V_275 = V_18 << V_16 ;
V_272 = ( V_275 - V_17 ) % V_15 ;
if ( V_272 <= V_275 / V_271 )
break;
}
return V_16 ;
}
static inline int F_276 ( int V_15 , int V_17 )
{
int V_16 ;
int V_269 ;
int V_276 ;
int V_102 ;
V_269 = V_277 ;
if ( ! V_269 )
V_269 = 4 * ( F_277 ( V_278 ) + 1 ) ;
V_102 = F_22 ( V_279 , V_15 , V_17 ) ;
V_269 = V_163 ( V_269 , V_102 ) ;
while ( V_269 > 1 ) {
V_276 = 16 ;
while ( V_276 >= 4 ) {
V_16 = F_274 ( V_15 , V_269 ,
V_279 , V_276 , V_17 ) ;
if ( V_16 <= V_279 )
return V_16 ;
V_276 /= 2 ;
}
V_269 -- ;
}
V_16 = F_274 ( V_15 , 1 , V_279 , 1 , V_17 ) ;
if ( V_16 <= V_279 )
return V_16 ;
V_16 = F_274 ( V_15 , 1 , V_280 , 1 , V_17 ) ;
if ( V_16 < V_280 )
return V_16 ;
return - V_281 ;
}
static void
F_278 ( struct V_106 * V_34 )
{
V_34 -> V_184 = 0 ;
F_279 ( & V_34 -> V_107 ) ;
F_280 ( & V_34 -> V_186 ) ;
#ifdef F_2
F_281 ( & V_34 -> V_111 , 0 ) ;
F_281 ( & V_34 -> V_112 , 0 ) ;
F_280 ( & V_34 -> V_109 ) ;
#endif
}
static inline int F_282 ( struct V_1 * V_2 )
{
F_283 ( V_282 <
V_283 * sizeof( struct V_189 ) ) ;
V_2 -> V_10 = F_284 ( sizeof( struct V_189 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_10 )
return 0 ;
F_208 ( V_2 ) ;
return 1 ;
}
static void F_285 ( int V_110 )
{
struct V_23 * V_23 ;
struct V_106 * V_34 ;
F_269 ( V_106 -> V_15 < sizeof( struct V_106 ) ) ;
V_23 = F_158 ( V_106 , V_284 , V_110 ) ;
F_269 ( ! V_23 ) ;
if ( F_108 ( V_23 ) != V_110 ) {
F_63 ( L_66 , V_110 ) ;
F_63 ( L_67 ) ;
}
V_34 = V_23 -> V_38 ;
F_269 ( ! V_34 ) ;
V_23 -> V_38 = F_14 ( V_106 , V_34 ) ;
V_23 -> V_29 = 1 ;
V_23 -> V_28 = 0 ;
V_106 -> V_110 [ V_110 ] = V_34 ;
#ifdef F_2
F_76 ( V_106 , V_34 , V_98 ) ;
F_61 ( V_106 , V_34 ) ;
#endif
F_256 ( V_106 , V_34 , sizeof( struct V_106 ) ,
V_147 ) ;
F_278 ( V_34 ) ;
F_96 ( V_106 , V_110 , V_23 -> V_30 ) ;
F_173 ( V_34 , V_23 , V_217 ) ;
}
static void F_286 ( struct V_1 * V_2 )
{
int V_110 ;
struct V_106 * V_34 ;
F_235 (s, node, n) {
F_265 ( V_106 , V_34 ) ;
V_2 -> V_110 [ V_110 ] = NULL ;
}
}
void F_287 ( struct V_1 * V_2 )
{
F_288 ( V_2 ) ;
F_289 ( V_2 -> V_10 ) ;
F_286 ( V_2 ) ;
}
static int F_290 ( struct V_1 * V_2 )
{
int V_110 ;
F_291 (node, N_NORMAL_MEMORY) {
struct V_106 * V_34 ;
if ( V_285 == V_286 ) {
F_285 ( V_110 ) ;
continue;
}
V_34 = F_257 ( V_106 ,
V_147 , V_110 ) ;
if ( ! V_34 ) {
F_286 ( V_2 ) ;
return 0 ;
}
V_2 -> V_110 [ V_110 ] = V_34 ;
F_278 ( V_34 ) ;
}
return 1 ;
}
static void F_292 ( struct V_1 * V_2 , unsigned long V_163 )
{
if ( V_163 < V_287 )
V_163 = V_287 ;
else if ( V_163 > V_288 )
V_163 = V_288 ;
V_2 -> V_203 = V_163 ;
}
static void F_293 ( struct V_1 * V_2 )
{
#ifdef F_6
if ( ! F_5 ( V_2 ) )
V_2 -> V_231 = 0 ;
else if ( V_2 -> V_15 >= V_18 )
V_2 -> V_231 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_231 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_231 = 13 ;
else
V_2 -> V_231 = 30 ;
#endif
}
static int F_294 ( struct V_1 * V_2 , int V_289 )
{
unsigned long V_3 = V_2 -> V_3 ;
T_6 V_15 = V_2 -> V_77 ;
int V_16 ;
V_15 = F_295 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_96 ) && ! ( V_3 & V_183 ) &&
! V_2 -> F_113 )
V_2 -> V_3 |= V_81 ;
else
V_2 -> V_3 &= ~ V_81 ;
if ( ( V_3 & V_6 ) && V_15 == V_2 -> V_77 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_29 = V_15 ;
if ( ( ( V_3 & ( V_183 | V_96 ) ) ||
V_2 -> F_113 ) ) {
V_2 -> V_12 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_65 )
V_15 += 2 * sizeof( struct V_47 ) ;
#endif
F_296 ( V_2 , & V_15 , & V_2 -> V_3 ) ;
#ifdef F_2
if ( V_3 & V_6 ) {
V_15 += sizeof( void * ) ;
V_2 -> V_7 = sizeof( void * ) ;
V_2 -> V_7 = F_295 ( V_2 -> V_7 , V_2 -> V_290 ) ;
V_15 += V_2 -> V_7 ;
}
#endif
V_15 = F_295 ( V_15 , V_2 -> V_290 ) ;
V_2 -> V_15 = V_15 ;
if ( V_289 >= 0 )
V_16 = V_289 ;
else
V_16 = F_276 ( V_15 , V_2 -> V_17 ) ;
if ( V_16 < 0 )
return 0 ;
V_2 -> V_158 = 0 ;
if ( V_16 )
V_2 -> V_158 |= V_291 ;
if ( V_2 -> V_3 & V_292 )
V_2 -> V_158 |= V_293 ;
if ( V_2 -> V_3 & V_170 )
V_2 -> V_158 |= V_294 ;
V_2 -> V_141 = F_23 ( V_16 , V_15 , V_2 -> V_17 ) ;
V_2 -> V_163 = F_23 ( F_234 ( V_15 ) , V_15 , V_2 -> V_17 ) ;
if ( F_25 ( V_2 -> V_141 ) > F_25 ( V_2 -> F_275 ) )
V_2 -> F_275 = V_2 -> V_141 ;
return ! ! F_25 ( V_2 -> V_141 ) ;
}
static int F_297 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_112 ( V_2 -> V_15 , V_3 , V_2 -> V_40 , V_2 -> F_113 ) ;
V_2 -> V_17 = 0 ;
if ( V_181 && ( V_2 -> V_3 & V_183 ) )
V_2 -> V_17 = sizeof( struct V_179 ) ;
if ( ! F_294 ( V_2 , - 1 ) )
goto error;
if ( V_130 ) {
if ( F_234 ( V_2 -> V_15 ) > F_234 ( V_2 -> V_77 ) ) {
V_2 -> V_3 &= ~ V_295 ;
V_2 -> V_12 = 0 ;
if ( ! F_294 ( V_2 , - 1 ) )
goto error;
}
}
#if F_36 ( V_35 ) && \
F_36 ( V_36 )
if ( F_298 () && ( V_2 -> V_3 & V_296 ) == 0 )
V_2 -> V_3 |= V_37 ;
#endif
F_292 ( V_2 , F_299 ( V_2 -> V_15 ) / 2 ) ;
F_293 ( V_2 ) ;
#ifdef F_187
V_2 -> V_202 = 1000 ;
#endif
if ( V_285 >= V_297 ) {
if ( F_136 ( V_2 ) )
goto error;
}
if ( ! F_290 ( V_2 ) )
goto error;
if ( F_282 ( V_2 ) )
return 0 ;
F_286 ( V_2 ) ;
error:
if ( V_3 & V_298 )
F_300 ( L_68 ,
V_2 -> V_40 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_24 ( V_2 -> V_141 ) , V_2 -> V_12 , V_3 ) ;
return - V_299 ;
}
static void F_301 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_44 )
{
#ifdef F_2
void * V_14 = F_45 ( V_23 ) ;
void * V_5 ;
unsigned long * V_41 = F_302 ( F_303 ( V_23 -> V_30 ) *
sizeof( long ) , V_236 ) ;
if ( ! V_41 )
return;
F_75 ( V_2 , V_23 , V_44 , V_2 -> V_40 ) ;
F_26 ( V_23 ) ;
F_44 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects) {
if ( ! F_304 ( F_21 ( V_5 , V_2 , V_14 ) , V_41 ) ) {
F_63 ( L_69 , V_5 , V_5 - V_14 ) ;
F_64 ( V_2 , V_5 ) ;
}
}
F_30 ( V_23 ) ;
F_305 ( V_41 ) ;
#endif
}
static void F_306 ( struct V_1 * V_2 , struct V_106 * V_34 )
{
F_307 ( V_300 ) ;
struct V_23 * V_23 , * V_180 ;
F_269 ( F_35 () ) ;
F_308 ( & V_34 -> V_107 ) ;
F_181 (page, h, &n->partial, lru) {
if ( ! V_23 -> V_29 ) {
F_176 ( V_34 , V_23 ) ;
F_89 ( & V_23 -> V_108 , & V_300 ) ;
} else {
F_301 ( V_2 , V_23 ,
L_70 ) ;
}
}
F_309 ( & V_34 -> V_107 ) ;
F_181 (page, h, &discard, lru)
F_172 ( V_2 , V_23 ) ;
}
int F_310 ( struct V_1 * V_2 )
{
int V_110 ;
struct V_106 * V_34 ;
F_223 ( V_2 ) ;
F_235 (s, node, n) {
F_306 ( V_2 , V_34 ) ;
if ( V_34 -> V_184 || F_92 ( V_2 , V_110 ) )
return 1 ;
}
F_10 ( V_2 ) ;
return 0 ;
}
static int T_5 F_311 ( char * V_125 )
{
F_312 ( & V_125 , & V_274 ) ;
return 1 ;
}
static int T_5 F_313 ( char * V_125 )
{
F_312 ( & V_125 , & V_279 ) ;
V_279 = V_163 ( V_279 , V_280 - 1 ) ;
return 1 ;
}
static int T_5 F_314 ( char * V_125 )
{
F_312 ( & V_125 , & V_277 ) ;
return 1 ;
}
void * F_315 ( T_6 V_15 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) )
return F_316 ( V_15 , V_3 ) ;
V_2 = F_317 ( V_15 , V_3 ) ;
if ( F_3 ( F_318 ( V_2 ) ) )
return V_2 ;
V_122 = F_251 ( V_2 , V_3 , V_254 ) ;
F_255 ( V_254 , V_122 , V_15 , V_2 -> V_15 , V_3 ) ;
F_256 ( V_2 , V_122 , V_15 , V_3 ) ;
return V_122 ;
}
static void * F_319 ( T_6 V_15 , T_7 V_3 , int V_110 )
{
struct V_23 * V_23 ;
void * V_132 = NULL ;
V_3 |= V_291 | V_142 ;
V_23 = F_320 ( V_110 , V_3 , F_234 ( V_15 ) ) ;
if ( V_23 )
V_132 = F_45 ( V_23 ) ;
F_114 ( V_132 , V_15 , V_3 ) ;
return V_132 ;
}
void * F_321 ( T_6 V_15 , T_7 V_3 , int V_110 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) ) {
V_122 = F_319 ( V_15 , V_3 , V_110 ) ;
F_260 ( V_254 , V_122 ,
V_15 , V_18 << F_234 ( V_15 ) ,
V_3 , V_110 ) ;
return V_122 ;
}
V_2 = F_317 ( V_15 , V_3 ) ;
if ( F_3 ( F_318 ( V_2 ) ) )
return V_2 ;
V_122 = F_244 ( V_2 , V_3 , V_110 , V_254 ) ;
F_260 ( V_254 , V_122 , V_15 , V_2 -> V_15 , V_3 , V_110 ) ;
F_256 ( V_2 , V_122 , V_15 , V_3 ) ;
return V_122 ;
}
const char * F_322 ( const void * V_132 , unsigned long V_34 ,
struct V_23 * V_23 )
{
struct V_1 * V_2 ;
unsigned long V_12 ;
T_6 V_77 ;
V_2 = V_23 -> V_116 ;
V_77 = F_323 ( V_2 ) ;
if ( V_132 < F_45 ( V_23 ) )
return V_2 -> V_40 ;
V_12 = ( V_132 - F_45 ( V_23 ) ) % V_2 -> V_15 ;
if ( F_1 ( V_2 ) && V_2 -> V_3 & V_6 ) {
if ( V_12 < V_2 -> V_7 )
return V_2 -> V_40 ;
V_12 -= V_2 -> V_7 ;
}
if ( V_12 <= V_77 && V_34 <= V_77 - V_12 )
return NULL ;
return V_2 -> V_40 ;
}
static T_6 F_324 ( const void * V_11 )
{
struct V_23 * V_23 ;
if ( F_3 ( V_11 == V_302 ) )
return 0 ;
V_23 = F_168 ( V_11 ) ;
if ( F_3 ( ! F_85 ( V_23 ) ) ) {
F_178 ( ! F_270 ( V_23 ) ) ;
return V_18 << F_82 ( V_23 ) ;
}
return F_323 ( V_23 -> V_116 ) ;
}
T_6 F_325 ( const void * V_11 )
{
T_6 V_15 = F_324 ( V_11 ) ;
F_326 ( V_11 , V_15 ) ;
return V_15 ;
}
void F_305 ( const void * V_20 )
{
struct V_23 * V_23 ;
void * V_11 = ( void * ) V_20 ;
F_327 ( V_254 , V_20 ) ;
if ( F_3 ( F_318 ( V_20 ) ) )
return;
V_23 = F_168 ( V_20 ) ;
if ( F_3 ( ! F_85 ( V_23 ) ) ) {
F_269 ( ! F_270 ( V_23 ) ) ;
F_117 ( V_20 ) ;
F_135 ( V_23 , F_82 ( V_23 ) ) ;
return;
}
F_263 ( V_23 -> V_116 , V_23 , V_11 , NULL , 1 , V_254 ) ;
}
int F_328 ( struct V_1 * V_2 )
{
int V_110 ;
int V_52 ;
struct V_106 * V_34 ;
struct V_23 * V_23 ;
struct V_23 * V_68 ;
struct V_182 V_300 ;
struct V_182 V_303 [ V_304 ] ;
unsigned long V_3 ;
int V_122 = 0 ;
F_223 ( V_2 ) ;
F_235 (s, node, n) {
F_280 ( & V_300 ) ;
for ( V_52 = 0 ; V_52 < V_304 ; V_52 ++ )
F_280 ( V_303 + V_52 ) ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_181 (page, t, &n->partial, lru) {
int free = V_23 -> V_30 - V_23 -> V_29 ;
F_248 () ;
F_269 ( free <= 0 ) ;
if ( free == V_23 -> V_30 ) {
F_329 ( & V_23 -> V_108 , & V_300 ) ;
V_34 -> V_184 -- ;
} else if ( free <= V_304 )
F_329 ( & V_23 -> V_108 , V_303 + free - 1 ) ;
}
for ( V_52 = V_304 - 1 ; V_52 >= 0 ; V_52 -- )
F_330 ( V_303 + V_52 , & V_34 -> V_186 ) ;
F_110 ( & V_34 -> V_107 , V_3 ) ;
F_181 (page, t, &discard, lru)
F_172 ( V_2 , V_23 ) ;
if ( F_92 ( V_2 , V_110 ) )
V_122 = 1 ;
}
return V_122 ;
}
static void F_331 ( struct V_1 * V_2 )
{
if ( ! F_328 ( V_2 ) )
F_10 ( V_2 ) ;
}
void F_332 ( struct V_1 * V_2 )
{
F_333 ( V_2 , 0 ) ;
V_2 -> V_203 = 0 ;
F_334 ( V_2 , F_331 ) ;
}
static int F_335 ( void * V_305 )
{
struct V_1 * V_2 ;
F_139 ( & V_148 ) ;
F_140 (s, &slab_caches, list)
F_328 ( V_2 ) ;
F_141 ( & V_148 ) ;
return 0 ;
}
static void F_336 ( void * V_305 )
{
struct V_106 * V_34 ;
struct V_1 * V_2 ;
struct V_306 * V_307 = V_305 ;
int V_308 ;
V_308 = V_307 -> V_309 ;
if ( V_308 < 0 )
return;
F_139 ( & V_148 ) ;
F_140 (s, &slab_caches, list) {
V_34 = F_93 ( V_2 , V_308 ) ;
if ( V_34 ) {
F_269 ( F_92 ( V_2 , V_308 ) ) ;
V_2 -> V_110 [ V_308 ] = NULL ;
F_265 ( V_106 , V_34 ) ;
}
}
F_141 ( & V_148 ) ;
}
static int F_337 ( void * V_305 )
{
struct V_106 * V_34 ;
struct V_1 * V_2 ;
struct V_306 * V_307 = V_305 ;
int V_238 = V_307 -> V_309 ;
int V_122 = 0 ;
if ( V_238 < 0 )
return 0 ;
F_139 ( & V_148 ) ;
F_140 (s, &slab_caches, list) {
V_34 = F_252 ( V_106 , V_147 ) ;
if ( ! V_34 ) {
V_122 = - V_310 ;
goto V_123;
}
F_278 ( V_34 ) ;
V_2 -> V_110 [ V_238 ] = V_34 ;
}
V_123:
F_141 ( & V_148 ) ;
return V_122 ;
}
static int F_338 ( struct V_311 * V_312 ,
unsigned long V_313 , void * V_305 )
{
int V_122 = 0 ;
switch ( V_313 ) {
case V_314 :
V_122 = F_337 ( V_305 ) ;
break;
case V_315 :
V_122 = F_335 ( V_305 ) ;
break;
case V_316 :
case V_317 :
F_336 ( V_305 ) ;
break;
case V_318 :
case V_319 :
break;
}
if ( V_122 )
V_122 = F_339 ( V_122 ) ;
else
V_122 = V_320 ;
return V_122 ;
}
static struct V_1 * T_5 F_340 ( struct V_1 * V_321 )
{
int V_110 ;
struct V_1 * V_2 = F_341 ( V_1 , V_284 ) ;
struct V_106 * V_34 ;
memcpy ( V_2 , V_321 , V_1 -> V_77 ) ;
F_219 ( V_2 , F_60 () ) ;
F_235 (s, node, n) {
struct V_23 * V_5 ;
F_140 (p, &n->partial, lru)
V_5 -> V_116 = V_2 ;
#ifdef F_2
F_140 (p, &n->full, lru)
V_5 -> V_116 = V_2 ;
#endif
}
F_342 ( V_2 ) ;
F_89 ( & V_2 -> V_322 , & V_323 ) ;
F_343 ( V_2 ) ;
return V_2 ;
}
void T_5 F_344 ( void )
{
static V_324 struct V_1 V_325 ,
V_326 ;
if ( F_345 () )
V_279 = 0 ;
V_106 = & V_326 ;
V_1 = & V_325 ;
F_346 ( V_106 , L_71 ,
sizeof( struct V_106 ) , V_327 ) ;
F_347 ( & V_328 ) ;
V_285 = V_329 ;
F_346 ( V_1 , L_72 ,
F_348 ( struct V_1 , V_110 ) +
V_330 * sizeof( struct V_106 * ) ,
V_327 ) ;
V_1 = F_340 ( & V_325 ) ;
V_106 = F_340 ( & V_326 ) ;
F_349 () ;
F_350 ( 0 ) ;
F_138 () ;
F_351 ( V_331 , L_73 , NULL ,
F_225 ) ;
F_40 ( L_74 ,
F_352 () ,
V_274 , V_279 , V_277 ,
V_278 , V_330 ) ;
}
void T_5 F_353 ( void )
{
}
struct V_1 *
F_354 ( const char * V_40 , T_6 V_15 , T_6 V_290 ,
unsigned long V_3 , void (* F_113)( void * ) )
{
struct V_1 * V_2 , * V_190 ;
V_2 = F_355 ( V_15 , V_290 , V_3 , V_40 , F_113 ) ;
if ( V_2 ) {
V_2 -> V_332 ++ ;
V_2 -> V_77 = F_275 ( V_2 -> V_77 , ( int ) V_15 ) ;
V_2 -> V_29 = F_356 ( int , V_2 -> V_29 , F_295 ( V_15 , sizeof( void * ) ) ) ;
F_357 (c, s) {
V_190 -> V_77 = V_2 -> V_77 ;
V_190 -> V_29 = F_356 ( int , V_190 -> V_29 ,
F_295 ( V_15 , sizeof( void * ) ) ) ;
}
if ( F_8 ( V_2 , V_40 ) ) {
V_2 -> V_332 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_358 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_144 ;
V_144 = F_297 ( V_2 , V_3 ) ;
if ( V_144 )
return V_144 ;
if ( V_285 <= V_297 )
return 0 ;
F_9 ( V_2 ) ;
V_144 = F_7 ( V_2 ) ;
if ( V_144 )
F_287 ( V_2 ) ;
return V_144 ;
}
void * F_359 ( T_6 V_15 , T_7 V_237 , unsigned long V_333 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) )
return F_316 ( V_15 , V_237 ) ;
V_2 = F_317 ( V_15 , V_237 ) ;
if ( F_3 ( F_318 ( V_2 ) ) )
return V_2 ;
V_122 = F_251 ( V_2 , V_237 , V_333 ) ;
F_255 ( V_333 , V_122 , V_15 , V_2 -> V_15 , V_237 ) ;
return V_122 ;
}
void * F_360 ( T_6 V_15 , T_7 V_237 ,
int V_110 , unsigned long V_333 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) ) {
V_122 = F_319 ( V_15 , V_237 , V_110 ) ;
F_260 ( V_333 , V_122 ,
V_15 , V_18 << F_234 ( V_15 ) ,
V_237 , V_110 ) ;
return V_122 ;
}
V_2 = F_317 ( V_15 , V_237 ) ;
if ( F_3 ( F_318 ( V_2 ) ) )
return V_2 ;
V_122 = F_244 ( V_2 , V_237 , V_110 , V_333 ) ;
F_260 ( V_333 , V_122 , V_15 , V_2 -> V_15 , V_237 , V_110 ) ;
return V_122 ;
}
static int F_361 ( struct V_23 * V_23 )
{
return V_23 -> V_29 ;
}
static int F_362 ( struct V_23 * V_23 )
{
return V_23 -> V_30 ;
}
static int F_363 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
void * V_5 ;
void * V_14 = F_45 ( V_23 ) ;
if ( ! F_84 ( V_2 , V_23 ) ||
! F_86 ( V_2 , V_23 , NULL ) )
return 0 ;
F_364 ( V_41 , V_23 -> V_30 ) ;
F_44 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects) {
if ( F_304 ( F_21 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_83 ( V_2 , V_23 , V_5 , V_113 ) )
return 0 ;
}
F_161 (p, s, addr, page->objects)
if ( ! F_304 ( F_21 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_83 ( V_2 , V_23 , V_5 , V_98 ) )
return 0 ;
return 1 ;
}
static void F_365 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
F_26 ( V_23 ) ;
F_363 ( V_2 , V_23 , V_41 ) ;
F_30 ( V_23 ) ;
}
static int F_366 ( struct V_1 * V_2 ,
struct V_106 * V_34 , unsigned long * V_41 )
{
unsigned long V_145 = 0 ;
struct V_23 * V_23 ;
unsigned long V_3 ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_140 (page, &n->partial, lru) {
F_365 ( V_2 , V_23 , V_41 ) ;
V_145 ++ ;
}
if ( V_145 != V_34 -> V_184 )
F_63 ( L_75 ,
V_2 -> V_40 , V_145 , V_34 -> V_184 ) ;
if ( ! ( V_2 -> V_3 & V_65 ) )
goto V_123;
F_140 (page, &n->full, lru) {
F_365 ( V_2 , V_23 , V_41 ) ;
V_145 ++ ;
}
if ( V_145 != F_94 ( & V_34 -> V_111 ) )
F_63 ( L_76 ,
V_2 -> V_40 , V_145 , F_94 ( & V_34 -> V_111 ) ) ;
V_123:
F_110 ( & V_34 -> V_107 , V_3 ) ;
return V_145 ;
}
static long F_367 ( struct V_1 * V_2 )
{
int V_110 ;
unsigned long V_145 = 0 ;
unsigned long * V_41 = F_368 ( F_303 ( F_25 ( V_2 -> F_275 ) ) *
sizeof( unsigned long ) , V_147 ) ;
struct V_106 * V_34 ;
if ( ! V_41 )
return - V_310 ;
F_223 ( V_2 ) ;
F_235 (s, node, n)
V_145 += F_366 ( V_2 , V_34 , V_41 ) ;
F_305 ( V_41 ) ;
return V_145 ;
}
static void F_369 ( struct V_334 * V_68 )
{
if ( V_68 -> F_275 )
F_370 ( ( unsigned long ) V_68 -> V_335 ,
F_234 ( sizeof( struct V_336 ) * V_68 -> F_275 ) ) ;
}
static int F_371 ( struct V_334 * V_68 , unsigned long F_275 , T_7 V_3 )
{
struct V_336 * V_214 ;
int V_16 ;
V_16 = F_234 ( sizeof( struct V_336 ) * F_275 ) ;
V_214 = ( void * ) F_372 ( V_3 , V_16 ) ;
if ( ! V_214 )
return 0 ;
if ( V_68 -> V_145 ) {
memcpy ( V_214 , V_68 -> V_335 , sizeof( struct V_336 ) * V_68 -> V_145 ) ;
F_369 ( V_68 ) ;
}
V_68 -> F_275 = F_275 ;
V_68 -> V_335 = V_214 ;
return 1 ;
}
static int F_373 ( struct V_334 * V_68 , struct V_1 * V_2 ,
const struct V_47 * V_47 )
{
long V_89 , V_93 , V_149 ;
struct V_336 * V_214 ;
unsigned long V_337 ;
unsigned long V_338 = V_64 - V_47 -> V_63 ;
V_89 = - 1 ;
V_93 = V_68 -> V_145 ;
for ( ; ; ) {
V_149 = V_89 + ( V_93 - V_89 + 1 ) / 2 ;
if ( V_149 == V_93 )
break;
V_337 = V_68 -> V_335 [ V_149 ] . V_14 ;
if ( V_47 -> V_14 == V_337 ) {
V_214 = & V_68 -> V_335 [ V_149 ] ;
V_214 -> V_145 ++ ;
if ( V_47 -> V_63 ) {
V_214 -> V_339 += V_338 ;
if ( V_338 < V_214 -> V_340 )
V_214 -> V_340 = V_338 ;
if ( V_338 > V_214 -> V_341 )
V_214 -> V_341 = V_338 ;
if ( V_47 -> V_61 < V_214 -> V_342 )
V_214 -> V_342 = V_47 -> V_61 ;
if ( V_47 -> V_61 > V_214 -> V_343 )
V_214 -> V_343 = V_47 -> V_61 ;
F_374 ( V_47 -> V_60 ,
F_375 ( V_214 -> V_344 ) ) ;
}
F_376 ( F_108 ( F_377 ( V_47 ) ) , V_214 -> V_345 ) ;
return 1 ;
}
if ( V_47 -> V_14 < V_337 )
V_93 = V_149 ;
else
V_89 = V_149 ;
}
if ( V_68 -> V_145 >= V_68 -> F_275 && ! F_371 ( V_68 , 2 * V_68 -> F_275 , V_236 ) )
return 0 ;
V_214 = V_68 -> V_335 + V_149 ;
if ( V_149 < V_68 -> V_145 )
memmove ( V_214 + 1 , V_214 ,
( V_68 -> V_145 - V_149 ) * sizeof( struct V_336 ) ) ;
V_68 -> V_145 ++ ;
V_214 -> V_145 = 1 ;
V_214 -> V_14 = V_47 -> V_14 ;
V_214 -> V_339 = V_338 ;
V_214 -> V_340 = V_338 ;
V_214 -> V_341 = V_338 ;
V_214 -> V_342 = V_47 -> V_61 ;
V_214 -> V_343 = V_47 -> V_61 ;
F_378 ( F_375 ( V_214 -> V_344 ) ) ;
F_374 ( V_47 -> V_60 , F_375 ( V_214 -> V_344 ) ) ;
F_379 ( V_214 -> V_345 ) ;
F_376 ( F_108 ( F_377 ( V_47 ) ) , V_214 -> V_345 ) ;
return 1 ;
}
static void F_380 ( struct V_334 * V_68 , struct V_1 * V_2 ,
struct V_23 * V_23 , enum V_48 V_49 ,
unsigned long * V_41 )
{
void * V_14 = F_45 ( V_23 ) ;
void * V_5 ;
F_364 ( V_41 , V_23 -> V_30 ) ;
F_44 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects)
if ( ! F_304 ( F_21 ( V_5 , V_2 , V_14 ) , V_41 ) )
F_373 ( V_68 , V_2 , F_56 ( V_2 , V_5 , V_49 ) ) ;
}
static int F_381 ( struct V_1 * V_2 , char * V_79 ,
enum V_48 V_49 )
{
int V_346 = 0 ;
unsigned long V_52 ;
struct V_334 V_68 = { 0 , 0 , NULL } ;
int V_110 ;
unsigned long * V_41 = F_368 ( F_303 ( F_25 ( V_2 -> F_275 ) ) *
sizeof( unsigned long ) , V_147 ) ;
struct V_106 * V_34 ;
if ( ! V_41 || ! F_371 ( & V_68 , V_18 / sizeof( struct V_336 ) ,
V_347 ) ) {
F_305 ( V_41 ) ;
return sprintf ( V_79 , L_77 ) ;
}
F_223 ( V_2 ) ;
F_235 (s, node, n) {
unsigned long V_3 ;
struct V_23 * V_23 ;
if ( ! F_94 ( & V_34 -> V_111 ) )
continue;
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_140 (page, &n->partial, lru)
F_380 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_140 (page, &n->full, lru)
F_380 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_110 ( & V_34 -> V_107 , V_3 ) ;
}
for ( V_52 = 0 ; V_52 < V_68 . V_145 ; V_52 ++ ) {
struct V_336 * V_214 = & V_68 . V_335 [ V_52 ] ;
if ( V_346 > V_18 - V_348 - 100 )
break;
V_346 += sprintf ( V_79 + V_346 , L_78 , V_214 -> V_145 ) ;
if ( V_214 -> V_14 )
V_346 += sprintf ( V_79 + V_346 , L_79 , ( void * ) V_214 -> V_14 ) ;
else
V_346 += sprintf ( V_79 + V_346 , L_80 ) ;
if ( V_214 -> V_339 != V_214 -> V_340 ) {
V_346 += sprintf ( V_79 + V_346 , L_81 ,
V_214 -> V_340 ,
( long ) F_382 ( V_214 -> V_339 , V_214 -> V_145 ) ,
V_214 -> V_341 ) ;
} else
V_346 += sprintf ( V_79 + V_346 , L_82 ,
V_214 -> V_340 ) ;
if ( V_214 -> V_342 != V_214 -> V_343 )
V_346 += sprintf ( V_79 + V_346 , L_83 ,
V_214 -> V_342 , V_214 -> V_343 ) ;
else
V_346 += sprintf ( V_79 + V_346 , L_84 ,
V_214 -> V_342 ) ;
if ( F_383 () > 1 &&
! F_384 ( F_375 ( V_214 -> V_344 ) ) &&
V_346 < V_18 - 60 )
V_346 += F_385 ( V_79 + V_346 , V_18 - V_346 - 50 ,
L_85 ,
F_386 ( F_375 ( V_214 -> V_344 ) ) ) ;
if ( V_349 > 1 && ! F_387 ( V_214 -> V_345 ) &&
V_346 < V_18 - 60 )
V_346 += F_385 ( V_79 + V_346 , V_18 - V_346 - 50 ,
L_86 ,
F_388 ( & V_214 -> V_345 ) ) ;
V_346 += sprintf ( V_79 + V_346 , L_87 ) ;
}
F_369 ( & V_68 ) ;
F_305 ( V_41 ) ;
if ( ! V_68 . V_145 )
V_346 += sprintf ( V_79 , L_88 ) ;
return V_346 ;
}
static void T_5 F_389 ( void )
{
T_2 * V_5 ;
F_283 ( V_350 > 16 || V_283 < 10 ) ;
F_63 ( L_89 ) ;
F_63 ( L_90 ) ;
F_63 ( L_91 ) ;
V_5 = F_302 ( 16 , V_147 ) ;
V_5 [ 16 ] = 0x12 ;
F_63 ( L_92 ,
V_5 + 16 ) ;
F_367 ( V_351 [ 4 ] ) ;
V_5 = F_302 ( 32 , V_147 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_63 ( L_93 ,
V_5 ) ;
F_63 ( L_94 ) ;
F_367 ( V_351 [ 5 ] ) ;
V_5 = F_302 ( 64 , V_147 ) ;
V_5 += 64 + ( F_189 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_63 ( L_95 ,
V_5 ) ;
F_63 ( L_94 ) ;
F_367 ( V_351 [ 6 ] ) ;
F_63 ( L_96 ) ;
V_5 = F_302 ( 128 , V_147 ) ;
F_305 ( V_5 ) ;
* V_5 = 0x78 ;
F_63 ( L_97 , V_5 ) ;
F_367 ( V_351 [ 7 ] ) ;
V_5 = F_302 ( 256 , V_147 ) ;
F_305 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_63 ( L_98 , V_5 ) ;
F_367 ( V_351 [ 8 ] ) ;
V_5 = F_302 ( 512 , V_147 ) ;
F_305 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_63 ( L_99 , V_5 ) ;
F_367 ( V_351 [ 9 ] ) ;
}
static void F_389 ( void ) {}
static int T_5 F_390 ( char * V_125 )
{
int V_352 ;
if ( F_312 ( & V_125 , & V_352 ) > 0 )
V_353 = V_352 ;
return 1 ;
}
static T_9 F_391 ( struct V_1 * V_2 ,
char * V_79 , unsigned long V_3 )
{
unsigned long V_354 = 0 ;
int V_110 ;
int V_20 ;
unsigned long * V_345 ;
V_345 = F_302 ( sizeof( unsigned long ) * V_330 , V_147 ) ;
if ( ! V_345 )
return - V_310 ;
if ( V_3 & V_355 ) {
int V_60 ;
F_209 (cpu) {
struct V_189 * V_190 = F_210 ( V_2 -> V_10 ,
V_60 ) ;
int V_110 ;
struct V_23 * V_23 ;
V_23 = F_247 ( V_190 -> V_23 ) ;
if ( ! V_23 )
continue;
V_110 = F_108 ( V_23 ) ;
if ( V_3 & V_356 )
V_20 = V_23 -> V_30 ;
else if ( V_3 & V_357 )
V_20 = V_23 -> V_29 ;
else
V_20 = 1 ;
V_354 += V_20 ;
V_345 [ V_110 ] += V_20 ;
V_23 = F_392 ( V_190 ) ;
if ( V_23 ) {
V_110 = F_108 ( V_23 ) ;
if ( V_3 & V_356 )
F_393 ( 1 ) ;
else if ( V_3 & V_357 )
F_393 ( 1 ) ;
else
V_20 = V_23 -> V_169 ;
V_354 += V_20 ;
V_345 [ V_110 ] += V_20 ;
}
}
}
F_394 () ;
#ifdef F_2
if ( V_3 & V_358 ) {
struct V_106 * V_34 ;
F_235 (s, node, n) {
if ( V_3 & V_356 )
V_20 = F_94 ( & V_34 -> V_112 ) ;
else if ( V_3 & V_357 )
V_20 = F_94 ( & V_34 -> V_112 ) -
F_229 ( V_34 , F_227 ) ;
else
V_20 = F_94 ( & V_34 -> V_111 ) ;
V_354 += V_20 ;
V_345 [ V_110 ] += V_20 ;
}
} else
#endif
if ( V_3 & V_359 ) {
struct V_106 * V_34 ;
F_235 (s, node, n) {
if ( V_3 & V_356 )
V_20 = F_229 ( V_34 , F_362 ) ;
else if ( V_3 & V_357 )
V_20 = F_229 ( V_34 , F_361 ) ;
else
V_20 = V_34 -> V_184 ;
V_354 += V_20 ;
V_345 [ V_110 ] += V_20 ;
}
}
V_20 = sprintf ( V_79 , L_100 , V_354 ) ;
#ifdef F_187
for ( V_110 = 0 ; V_110 < V_330 ; V_110 ++ )
if ( V_345 [ V_110 ] )
V_20 += sprintf ( V_79 + V_20 , L_101 ,
V_110 , V_345 [ V_110 ] ) ;
#endif
F_395 () ;
F_305 ( V_345 ) ;
return V_20 + sprintf ( V_79 + V_20 , L_87 ) ;
}
static int F_396 ( struct V_1 * V_2 )
{
int V_110 ;
struct V_106 * V_34 ;
F_235 (s, node, n)
if ( F_94 ( & V_34 -> V_112 ) )
return 1 ;
return 0 ;
}
static T_9 F_397 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_15 ) ;
}
static T_9 F_398 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_290 ) ;
}
static T_9 F_399 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_77 ) ;
}
static T_9 F_400 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , F_25 ( V_2 -> V_141 ) ) ;
}
static T_9 F_401 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
unsigned long V_16 ;
int V_144 ;
V_144 = F_402 ( V_79 , 10 , & V_16 ) ;
if ( V_144 )
return V_144 ;
if ( V_16 > V_279 || V_16 < V_274 )
return - V_299 ;
F_294 ( V_2 , V_16 ) ;
return V_45 ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , F_24 ( V_2 -> V_141 ) ) ;
}
static T_9 F_404 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_103 , V_2 -> V_203 ) ;
}
static T_9 F_405 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
unsigned long V_163 ;
int V_144 ;
V_144 = F_402 ( V_79 , 10 , & V_163 ) ;
if ( V_144 )
return V_144 ;
F_292 ( V_2 , V_163 ) ;
return V_45 ;
}
static T_9 F_406 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_104 , F_184 ( V_2 ) ) ;
}
static T_9 F_407 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
unsigned long V_30 ;
int V_144 ;
V_144 = F_402 ( V_79 , 10 , & V_30 ) ;
if ( V_144 )
return V_144 ;
if ( V_30 && ! F_5 ( V_2 ) )
return - V_299 ;
F_333 ( V_2 , V_30 ) ;
F_223 ( V_2 ) ;
return V_45 ;
}
static T_9 F_408 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! V_2 -> F_113 )
return 0 ;
return sprintf ( V_79 , L_105 , V_2 -> F_113 ) ;
}
static T_9 F_409 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_332 < 0 ? 0 : V_2 -> V_332 - 1 ) ;
}
static T_9 F_410 ( struct V_1 * V_2 , char * V_79 )
{
return F_391 ( V_2 , V_79 , V_359 ) ;
}
static T_9 F_411 ( struct V_1 * V_2 , char * V_79 )
{
return F_391 ( V_2 , V_79 , V_355 ) ;
}
static T_9 F_412 ( struct V_1 * V_2 , char * V_79 )
{
return F_391 ( V_2 , V_79 , V_358 | V_357 ) ;
}
static T_9 F_413 ( struct V_1 * V_2 , char * V_79 )
{
return F_391 ( V_2 , V_79 , V_359 | V_357 ) ;
}
static T_9 F_414 ( struct V_1 * V_2 , char * V_79 )
{
int V_30 = 0 ;
int V_169 = 0 ;
int V_60 ;
int V_346 ;
F_415 (cpu) {
struct V_23 * V_23 ;
V_23 = F_222 ( F_210 ( V_2 -> V_10 , V_60 ) ) ;
if ( V_23 ) {
V_169 += V_23 -> V_169 ;
V_30 += V_23 -> V_230 ;
}
}
V_346 = sprintf ( V_79 , L_106 , V_30 , V_169 ) ;
#ifdef F_416
F_415 (cpu) {
struct V_23 * V_23 ;
V_23 = F_222 ( F_210 ( V_2 -> V_10 , V_60 ) ) ;
if ( V_23 && V_346 < V_18 - 20 )
V_346 += sprintf ( V_79 + V_346 , L_107 , V_60 ,
V_23 -> V_230 , V_23 -> V_169 ) ;
}
#endif
return V_346 + sprintf ( V_79 + V_346 , L_87 ) ;
}
static T_9 F_417 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_170 ) ) ;
}
static T_9 F_418 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
V_2 -> V_3 &= ~ V_170 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_170 ;
return V_45 ;
}
static T_9 F_419 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_327 ) ) ;
}
static T_9 F_420 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_292 ) ) ;
}
static T_9 F_421 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_183 ) ) ;
}
static T_9 F_422 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_17 ) ;
}
static T_9 F_423 ( struct V_1 * V_2 , char * V_79 )
{
return F_391 ( V_2 , V_79 , V_358 ) ;
}
static T_9 F_424 ( struct V_1 * V_2 , char * V_79 )
{
return F_391 ( V_2 , V_79 , V_358 | V_356 ) ;
}
static T_9 F_425 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_114 ) ) ;
}
static T_9 F_426 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
V_2 -> V_3 &= ~ V_114 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_114 ;
}
return V_45 ;
}
static T_9 F_427 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_104 ) ) ;
}
static T_9 F_428 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
if ( V_2 -> V_332 > 1 )
return - V_299 ;
V_2 -> V_3 &= ~ V_104 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_104 ;
}
return V_45 ;
}
static T_9 F_429 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_6 ) ) ;
}
static T_9 F_430 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( F_396 ( V_2 ) )
return - V_360 ;
V_2 -> V_3 &= ~ V_6 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_6 ;
}
F_294 ( V_2 , - 1 ) ;
return V_45 ;
}
static T_9 F_431 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_96 ) ) ;
}
static T_9 F_432 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( F_396 ( V_2 ) )
return - V_360 ;
V_2 -> V_3 &= ~ V_96 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_96 ;
}
F_294 ( V_2 , - 1 ) ;
return V_45 ;
}
static T_9 F_433 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_65 ) ) ;
}
static T_9 F_434 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( F_396 ( V_2 ) )
return - V_360 ;
V_2 -> V_3 &= ~ V_65 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_65 ;
}
F_294 ( V_2 , - 1 ) ;
return V_45 ;
}
static T_9 F_435 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_436 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
int V_122 = - V_299 ;
if ( V_79 [ 0 ] == '1' ) {
V_122 = F_367 ( V_2 ) ;
if ( V_122 >= 0 )
V_122 = V_45 ;
}
return V_122 ;
}
static T_9 F_437 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_281 ;
return F_381 ( V_2 , V_79 , V_67 ) ;
}
static T_9 F_438 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_281 ;
return F_381 ( V_2 , V_79 , V_66 ) ;
}
static T_9 F_439 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_129 ) ) ;
}
static T_9 F_440 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
if ( V_2 -> V_332 > 1 )
return - V_299 ;
V_2 -> V_3 &= ~ V_129 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_129 ;
return V_45 ;
}
static T_9 F_441 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_442 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( V_79 [ 0 ] == '1' )
F_443 ( V_2 ) ;
else
return - V_299 ;
return V_45 ;
}
static T_9 F_444 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_202 / 10 ) ;
}
static T_9 F_445 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
unsigned long V_361 ;
int V_144 ;
V_144 = F_402 ( V_79 , 10 , & V_361 ) ;
if ( V_144 )
return V_144 ;
if ( V_361 <= 100 )
V_2 -> V_202 = V_361 * 10 ;
return V_45 ;
}
static int F_446 ( struct V_1 * V_2 , char * V_79 , enum V_8 V_9 )
{
unsigned long V_362 = 0 ;
int V_60 ;
int V_346 ;
int * V_85 = F_368 ( V_278 * sizeof( int ) , V_147 ) ;
if ( ! V_85 )
return - V_310 ;
F_415 (cpu) {
unsigned V_20 = F_210 ( V_2 -> V_10 , V_60 ) -> F_11 [ V_9 ] ;
V_85 [ V_60 ] = V_20 ;
V_362 += V_20 ;
}
V_346 = sprintf ( V_79 , L_100 , V_362 ) ;
#ifdef F_416
F_415 (cpu) {
if ( V_85 [ V_60 ] && V_346 < V_18 - 20 )
V_346 += sprintf ( V_79 + V_346 , L_108 , V_60 , V_85 [ V_60 ] ) ;
}
#endif
F_305 ( V_85 ) ;
return V_346 + sprintf ( V_79 + V_346 , L_87 ) ;
}
static void F_447 ( struct V_1 * V_2 , enum V_8 V_9 )
{
int V_60 ;
F_415 (cpu)
F_210 ( V_2 -> V_10 , V_60 ) -> F_11 [ V_9 ] = 0 ;
}
static T_9 F_448 ( struct V_363 * V_364 ,
struct V_365 * V_366 ,
char * V_79 )
{
struct V_367 * V_365 ;
struct V_1 * V_2 ;
int V_144 ;
V_365 = F_449 ( V_366 ) ;
V_2 = F_450 ( V_364 ) ;
if ( ! V_365 -> V_368 )
return - V_369 ;
V_144 = V_365 -> V_368 ( V_2 , V_79 ) ;
return V_144 ;
}
static T_9 F_451 ( struct V_363 * V_364 ,
struct V_365 * V_366 ,
const char * V_79 , T_6 V_346 )
{
struct V_367 * V_365 ;
struct V_1 * V_2 ;
int V_144 ;
V_365 = F_449 ( V_366 ) ;
V_2 = F_450 ( V_364 ) ;
if ( ! V_365 -> V_370 )
return - V_369 ;
V_144 = V_365 -> V_370 ( V_2 , V_79 , V_346 ) ;
#ifdef F_452
if ( V_285 >= V_371 && V_144 >= 0 && F_453 ( V_2 ) ) {
struct V_1 * V_190 ;
F_139 ( & V_148 ) ;
if ( V_2 -> V_372 < V_346 )
V_2 -> V_372 = V_346 ;
F_357 (c, s)
V_365 -> V_370 ( V_190 , V_79 , V_346 ) ;
F_141 ( & V_148 ) ;
}
#endif
return V_144 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_452
int V_52 ;
char * V_373 = NULL ;
struct V_1 * V_374 ;
if ( F_453 ( V_2 ) )
return;
V_374 = V_2 -> V_375 . V_374 ;
if ( ! V_374 -> V_372 )
return;
for ( V_52 = 0 ; V_52 < F_454 ( V_376 ) ; V_52 ++ ) {
char V_377 [ 64 ] ;
char * V_79 ;
struct V_367 * V_366 = F_449 ( V_376 [ V_52 ] ) ;
T_9 V_346 ;
if ( ! V_366 || ! V_366 -> V_370 || ! V_366 -> V_368 )
continue;
if ( V_373 )
V_79 = V_373 ;
else if ( V_374 -> V_372 < F_454 ( V_377 ) )
V_79 = V_377 ;
else {
V_373 = ( char * ) F_455 ( V_147 ) ;
if ( F_178 ( ! V_373 ) )
continue;
V_79 = V_373 ;
}
V_346 = V_366 -> V_368 ( V_374 , V_79 ) ;
if ( V_346 > 0 )
V_366 -> V_370 ( V_2 , V_79 , V_346 ) ;
}
if ( V_373 )
F_456 ( ( unsigned long ) V_373 ) ;
#endif
}
static void F_457 ( struct V_363 * V_378 )
{
F_458 ( F_450 ( V_378 ) ) ;
}
static int F_459 ( struct V_379 * V_379 , struct V_363 * V_364 )
{
struct V_380 * V_381 = F_460 ( V_364 ) ;
if ( V_381 == & V_382 )
return 1 ;
return 0 ;
}
static inline struct V_379 * F_461 ( struct V_1 * V_2 )
{
#ifdef F_452
if ( ! F_453 ( V_2 ) )
return V_2 -> V_375 . V_374 -> V_383 ;
#endif
return V_384 ;
}
static char * F_462 ( struct V_1 * V_2 )
{
char * V_40 = F_368 ( V_385 , V_147 ) ;
char * V_5 = V_40 ;
F_269 ( ! V_40 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_292 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_170 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_114 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_168 ) )
* V_5 ++ = 't' ;
if ( V_2 -> V_3 & V_386 )
* V_5 ++ = 'A' ;
if ( V_5 != V_40 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_109 , V_2 -> V_15 ) ;
F_269 ( V_5 > V_40 + V_385 - 1 ) ;
return V_40 ;
}
static void F_463 ( struct V_387 * V_388 )
{
struct V_1 * V_2 =
F_169 ( V_388 , struct V_1 , V_389 ) ;
if ( ! V_2 -> V_364 . V_390 )
goto V_123;
#ifdef F_452
F_464 ( V_2 -> V_383 ) ;
#endif
F_465 ( & V_2 -> V_364 , V_391 ) ;
F_466 ( & V_2 -> V_364 ) ;
V_123:
F_467 ( & V_2 -> V_364 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_144 ;
const char * V_40 ;
struct V_379 * V_379 = F_461 ( V_2 ) ;
int V_392 = F_468 ( V_2 ) ;
F_469 ( & V_2 -> V_389 , F_463 ) ;
if ( ! V_379 ) {
F_470 ( & V_2 -> V_364 , & V_382 ) ;
return 0 ;
}
if ( V_392 ) {
F_471 ( & V_384 -> V_364 , V_2 -> V_40 ) ;
V_40 = V_2 -> V_40 ;
} else {
V_40 = F_462 ( V_2 ) ;
}
V_2 -> V_364 . V_379 = V_379 ;
V_144 = F_472 ( & V_2 -> V_364 , & V_382 , NULL , L_16 , V_40 ) ;
if ( V_144 )
goto V_123;
V_144 = F_473 ( & V_2 -> V_364 , & V_393 ) ;
if ( V_144 )
goto V_394;
#ifdef F_452
if ( F_453 ( V_2 ) && V_353 ) {
V_2 -> V_383 = F_474 ( L_110 , NULL , & V_2 -> V_364 ) ;
if ( ! V_2 -> V_383 ) {
V_144 = - V_310 ;
goto V_394;
}
}
#endif
F_465 ( & V_2 -> V_364 , V_395 ) ;
if ( ! V_392 ) {
F_8 ( V_2 , V_2 -> V_40 ) ;
}
V_123:
if ( ! V_392 )
F_305 ( V_40 ) ;
return V_144 ;
V_394:
F_466 ( & V_2 -> V_364 ) ;
goto V_123;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_285 < V_371 )
return;
F_475 ( & V_2 -> V_364 ) ;
F_476 ( & V_2 -> V_389 ) ;
}
void F_477 ( struct V_1 * V_2 )
{
if ( V_285 >= V_371 )
F_467 ( & V_2 -> V_364 ) ;
}
static int F_8 ( struct V_1 * V_2 , const char * V_40 )
{
struct V_396 * V_397 ;
if ( V_285 == V_371 ) {
F_471 ( & V_384 -> V_364 , V_40 ) ;
return F_478 ( & V_384 -> V_364 , & V_2 -> V_364 , V_40 ) ;
}
V_397 = F_368 ( sizeof( struct V_396 ) , V_147 ) ;
if ( ! V_397 )
return - V_310 ;
V_397 -> V_2 = V_2 ;
V_397 -> V_40 = V_40 ;
V_397 -> V_154 = V_398 ;
V_398 = V_397 ;
return 0 ;
}
static int T_5 F_479 ( void )
{
struct V_1 * V_2 ;
int V_144 ;
F_139 ( & V_148 ) ;
V_384 = F_474 ( L_111 , & V_399 , V_400 ) ;
if ( ! V_384 ) {
F_141 ( & V_148 ) ;
F_63 ( L_112 ) ;
return - V_281 ;
}
V_285 = V_371 ;
F_140 (s, &slab_caches, list) {
V_144 = F_7 ( V_2 ) ;
if ( V_144 )
F_63 ( L_113 ,
V_2 -> V_40 ) ;
}
while ( V_398 ) {
struct V_396 * V_397 = V_398 ;
V_398 = V_398 -> V_154 ;
V_144 = F_8 ( V_397 -> V_2 , V_397 -> V_40 ) ;
if ( V_144 )
F_63 ( L_114 ,
V_397 -> V_40 ) ;
F_305 ( V_397 ) ;
}
F_141 ( & V_148 ) ;
F_389 () ;
return 0 ;
}
void F_480 ( struct V_1 * V_2 , struct V_401 * V_402 )
{
unsigned long V_111 = 0 ;
unsigned long V_242 = 0 ;
unsigned long V_243 = 0 ;
int V_110 ;
struct V_106 * V_34 ;
F_235 (s, node, n) {
V_111 += F_95 ( V_34 ) ;
V_242 += F_228 ( V_34 ) ;
V_243 += F_229 ( V_34 , F_227 ) ;
}
V_402 -> V_403 = V_242 - V_243 ;
V_402 -> V_404 = V_242 ;
V_402 -> V_405 = V_111 ;
V_402 -> V_406 = V_111 ;
V_402 -> V_407 = F_25 ( V_2 -> V_141 ) ;
V_402 -> V_408 = F_24 ( V_2 -> V_141 ) ;
}
void F_481 ( struct V_409 * V_215 , struct V_1 * V_2 )
{
}
T_9 F_482 ( struct V_410 * V_410 , const char T_10 * V_373 ,
T_6 V_145 , T_11 * V_411 )
{
return - V_369 ;
}
