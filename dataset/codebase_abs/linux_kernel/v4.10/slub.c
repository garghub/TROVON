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
static void F_53 ( char * V_43 , char * V_44 , T_2 * V_14 ,
unsigned int V_45 )
{
F_48 () ;
F_54 ( V_43 , V_44 , V_46 , 16 , 1 , V_14 ,
V_45 , 1 ) ;
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
F_53 ( V_76 , L_12 , V_5 - V_2 -> V_7 ,
V_2 -> V_7 ) ;
else if ( V_5 > V_14 + 16 )
F_53 ( V_76 , L_13 , V_5 - 16 , 16 ) ;
F_53 ( V_76 , L_14 , V_5 ,
F_70 (unsigned long, s->object_size, PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_6 )
F_53 ( V_76 , L_12 , V_5 + V_2 -> V_77 ,
V_2 -> V_29 - V_2 -> V_77 ) ;
if ( V_2 -> V_12 )
V_75 = V_2 -> V_12 + sizeof( void * ) ;
else
V_75 = V_2 -> V_29 ;
if ( V_2 -> V_3 & V_65 )
V_75 += 2 * sizeof( struct V_47 ) ;
V_75 += F_71 ( V_2 ) ;
if ( V_75 != F_46 ( V_2 ) )
F_53 ( V_76 , L_15 , V_5 + V_75 ,
F_46 ( V_2 ) - V_75 ) ;
F_72 () ;
}
void F_73 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_78 )
{
F_65 ( V_2 , L_16 , V_78 ) ;
F_69 ( V_2 , V_23 , V_11 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_69 , ... )
{
T_3 args ;
char V_79 [ 100 ] ;
va_start ( args , V_69 ) ;
vsnprintf ( V_79 , sizeof( V_79 ) , V_69 , args ) ;
va_end ( args ) ;
F_65 ( V_2 , L_16 , V_79 ) ;
F_64 ( V_23 ) ;
F_72 () ;
}
static void F_75 ( struct V_1 * V_2 , void * V_11 , T_2 V_80 )
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
static void F_76 ( struct V_1 * V_2 , char * V_84 , T_2 V_85 ,
void * V_86 , void * V_87 )
{
F_68 ( V_2 , L_17 , V_86 , V_87 - 1 , V_85 ) ;
memset ( V_86 , V_85 , V_87 - V_86 ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * V_11 , char * V_88 ,
T_2 * V_89 , unsigned int V_90 , unsigned int V_91 )
{
T_2 * V_92 ;
T_2 * V_93 ;
F_48 () ;
V_92 = F_78 ( V_89 , V_90 , V_91 ) ;
F_50 () ;
if ( ! V_92 )
return 1 ;
V_93 = V_89 + V_91 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_90 )
V_93 -- ;
F_65 ( V_2 , L_18 , V_88 ) ;
F_62 ( L_19 ,
V_92 , V_93 - 1 , V_92 [ 0 ] , V_90 ) ;
F_69 ( V_2 , V_23 , V_11 ) ;
F_76 ( V_2 , V_88 , V_90 , V_92 , V_93 ) ;
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
V_5 + V_75 , V_94 , F_46 ( V_2 ) - V_75 ) ;
}
static int F_80 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
T_2 * V_89 ;
T_2 * V_92 ;
T_2 * V_93 ;
int V_45 ;
int V_95 ;
if ( ! ( V_2 -> V_3 & V_96 ) )
return 1 ;
V_89 = F_44 ( V_23 ) ;
V_45 = ( V_18 << F_81 ( V_23 ) ) - V_2 -> V_17 ;
V_93 = V_89 + V_45 ;
V_95 = V_45 % V_2 -> V_15 ;
if ( ! V_95 )
return 1 ;
F_48 () ;
V_92 = F_78 ( V_93 - V_95 , V_94 , V_95 ) ;
F_50 () ;
if ( ! V_92 )
return 1 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_94 )
V_93 -- ;
F_74 ( V_2 , V_23 , L_21 , V_92 , V_93 - 1 ) ;
F_53 ( V_76 , L_15 , V_93 - V_95 , V_95 ) ;
F_76 ( V_2 , L_22 , V_94 , V_93 - V_95 , V_93 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_80 )
{
T_2 * V_5 = V_11 ;
T_2 * V_97 = V_11 + V_2 -> V_77 ;
if ( V_2 -> V_3 & V_6 ) {
if ( ! F_77 ( V_2 , V_23 , V_11 , L_23 ,
V_11 - V_2 -> V_7 , V_80 , V_2 -> V_7 ) )
return 0 ;
if ( ! F_77 ( V_2 , V_23 , V_11 , L_23 ,
V_97 , V_80 , V_2 -> V_29 - V_2 -> V_77 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_96 ) && V_2 -> V_77 < V_2 -> V_29 ) {
F_77 ( V_2 , V_23 , V_5 , L_24 ,
V_97 , V_94 ,
V_2 -> V_29 - V_2 -> V_77 ) ;
}
}
if ( V_2 -> V_3 & V_96 ) {
if ( V_80 != V_98 && ( V_2 -> V_3 & V_81 ) &&
( ! F_77 ( V_2 , V_23 , V_5 , L_25 , V_5 ,
V_82 , V_2 -> V_77 - 1 ) ||
! F_77 ( V_2 , V_23 , V_5 , L_25 ,
V_5 + V_2 -> V_77 - 1 , V_83 , 1 ) ) )
return 0 ;
F_79 ( V_2 , V_23 , V_5 ) ;
}
if ( ! V_2 -> V_12 && V_80 == V_98 )
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
int V_99 ;
F_33 ( ! F_34 () ) ;
if ( ! F_84 ( V_23 ) ) {
F_74 ( V_2 , V_23 , L_27 ) ;
return 0 ;
}
V_99 = F_21 ( F_81 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_23 -> V_30 > V_99 ) {
F_74 ( V_2 , V_23 , L_28 ,
V_23 -> V_30 , V_99 ) ;
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
static int F_85 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_100 )
{
int V_101 = 0 ;
void * V_13 ;
void * V_11 = NULL ;
int V_102 ;
V_13 = V_23 -> V_38 ;
while ( V_13 && V_101 <= V_23 -> V_30 ) {
if ( V_13 == V_100 )
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
V_101 ++ ;
}
V_102 = F_21 ( F_81 ( V_23 ) , V_2 -> V_15 , V_2 -> V_17 ) ;
if ( V_102 > V_103 )
V_102 = V_103 ;
if ( V_23 -> V_30 != V_102 ) {
F_74 ( V_2 , V_23 , L_32 ,
V_23 -> V_30 , V_102 ) ;
V_23 -> V_30 = V_102 ;
F_68 ( V_2 , L_33 ) ;
}
if ( V_23 -> V_29 != V_23 -> V_30 - V_101 ) {
F_74 ( V_2 , V_23 , L_34 ,
V_23 -> V_29 , V_23 -> V_30 - V_101 ) ;
V_23 -> V_29 = V_23 -> V_30 - V_101 ;
F_68 ( V_2 , L_35 ) ;
}
return V_100 == NULL ;
}
static void V_51 ( struct V_1 * V_2 , struct V_23 * V_23 , void * V_11 ,
int V_49 )
{
if ( V_2 -> V_3 & V_104 ) {
F_39 ( L_36 ,
V_2 -> V_40 ,
V_49 ? L_37 : L_38 ,
V_11 , V_23 -> V_29 ,
V_23 -> V_38 ) ;
if ( ! V_49 )
F_53 ( V_105 , L_14 , ( void * ) V_11 ,
V_2 -> V_77 ) ;
F_72 () ;
}
}
static void F_86 ( struct V_1 * V_2 ,
struct V_106 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_87 ( & V_34 -> V_107 ) ;
F_88 ( & V_23 -> V_108 , & V_34 -> V_109 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_106 * V_34 , struct V_23 * V_23 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return;
F_87 ( & V_34 -> V_107 ) ;
F_90 ( & V_23 -> V_108 ) ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_110 )
{
struct V_106 * V_34 = F_92 ( V_2 , V_110 ) ;
return F_93 ( & V_34 -> V_111 ) ;
}
static inline unsigned long F_94 ( struct V_106 * V_34 )
{
return F_93 ( & V_34 -> V_111 ) ;
}
static inline void F_95 ( struct V_1 * V_2 , int V_110 , int V_30 )
{
struct V_106 * V_34 = F_92 ( V_2 , V_110 ) ;
if ( F_96 ( V_34 ) ) {
F_97 ( & V_34 -> V_111 ) ;
F_98 ( V_30 , & V_34 -> V_112 ) ;
}
}
static inline void F_99 ( struct V_1 * V_2 , int V_110 , int V_30 )
{
struct V_106 * V_34 = F_92 ( V_2 , V_110 ) ;
F_100 ( & V_34 -> V_111 ) ;
F_101 ( V_30 , & V_34 -> V_112 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 )
{
if ( ! ( V_2 -> V_3 & ( V_65 | V_6 | V_81 ) ) )
return;
F_75 ( V_2 , V_11 , V_113 ) ;
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
if ( ! F_82 ( V_2 , V_23 , V_11 , V_113 ) )
return 0 ;
return 1 ;
}
static T_4 int F_104 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
void * V_11 , unsigned long V_14 )
{
if ( V_2 -> V_3 & V_114 ) {
if ( ! F_103 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_115;
}
if ( V_2 -> V_3 & V_65 )
F_56 ( V_2 , V_11 , V_67 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 1 ) ;
F_75 ( V_2 , V_11 , V_98 ) ;
return 1 ;
V_115:
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
if ( ! F_82 ( V_2 , V_23 , V_11 , V_98 ) )
return 0 ;
if ( F_3 ( V_2 != V_23 -> V_116 ) ) {
if ( ! F_84 ( V_23 ) ) {
F_74 ( V_2 , V_23 , L_43 ,
V_11 ) ;
} else if ( ! V_23 -> V_116 ) {
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
void * V_117 , void * V_118 , int V_119 ,
unsigned long V_14 )
{
struct V_106 * V_34 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
void * V_11 = V_117 ;
int V_120 = 0 ;
unsigned long V_121 ( V_3 ) ;
int V_122 = 0 ;
F_108 ( & V_34 -> V_107 , V_3 ) ;
F_25 ( V_23 ) ;
if ( V_2 -> V_3 & V_114 ) {
if ( ! F_83 ( V_2 , V_23 ) )
goto V_123;
}
V_124:
V_120 ++ ;
if ( V_2 -> V_3 & V_114 ) {
if ( ! F_105 ( V_2 , V_23 , V_11 , V_14 ) )
goto V_123;
}
if ( V_2 -> V_3 & V_65 )
F_56 ( V_2 , V_11 , V_66 , V_14 ) ;
V_51 ( V_2 , V_23 , V_11 , 0 ) ;
F_75 ( V_2 , V_11 , V_113 ) ;
if ( V_11 != V_118 ) {
V_11 = F_13 ( V_2 , V_11 ) ;
goto V_124;
}
V_122 = 1 ;
V_123:
if ( V_120 != V_119 )
F_74 ( V_2 , V_23 , L_46 ,
V_119 , V_120 ) ;
F_29 ( V_23 ) ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
if ( ! V_122 )
F_68 ( V_2 , L_47 , V_11 ) ;
return V_122 ;
}
static int T_5 F_110 ( char * V_125 )
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
F_62 ( L_48 ,
* V_125 ) ;
}
}
V_128:
if ( * V_125 == ',' )
V_131 = V_125 + 1 ;
V_123:
return 1 ;
}
unsigned long F_111 ( unsigned long V_77 ,
unsigned long V_3 , const char * V_40 ,
void (* F_112)( void * ) )
{
if ( V_126 && ( ! V_131 || ( V_40 &&
! strncmp ( V_131 , V_40 , strlen ( V_131 ) ) ) ) )
V_3 |= V_126 ;
return V_3 ;
}
static inline void F_102 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 ) {}
static inline int F_104 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_11 , unsigned long V_14 ) { return 0 ; }
static inline int F_106 (
struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_119 ,
unsigned long V_14 ) { return 0 ; }
static inline int F_80 ( struct V_1 * V_2 , struct V_23 * V_23 )
{ return 1 ; }
static inline int F_82 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_11 , T_2 V_80 ) { return 1 ; }
static inline void F_86 ( struct V_1 * V_2 , struct V_106 * V_34 ,
struct V_23 * V_23 ) {}
static inline void F_89 ( struct V_1 * V_2 , struct V_106 * V_34 ,
struct V_23 * V_23 ) {}
unsigned long F_111 ( unsigned long V_77 ,
unsigned long V_3 , const char * V_40 ,
void (* F_112)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_110 )
{ return 0 ; }
static inline unsigned long F_94 ( struct V_106 * V_34 )
{ return 0 ; }
static inline void F_95 ( struct V_1 * V_2 , int V_110 ,
int V_30 ) {}
static inline void F_99 ( struct V_1 * V_2 , int V_110 ,
int V_30 ) {}
static inline void F_113 ( void * V_132 , T_6 V_15 , T_7 V_3 )
{
F_114 ( V_132 , V_15 , 1 , V_3 ) ;
F_115 ( V_132 , V_15 , V_3 ) ;
}
static inline void F_116 ( const void * V_20 )
{
F_117 ( V_20 ) ;
F_118 ( V_20 ) ;
}
static inline void * F_119 ( struct V_1 * V_2 , void * V_20 )
{
void * V_133 ;
F_120 ( V_20 , V_2 -> V_3 ) ;
#if F_35 ( V_134 ) || F_35 ( V_135 )
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_121 ( V_2 , V_20 , V_2 -> V_77 ) ;
F_122 ( V_20 , V_2 -> V_77 ) ;
F_42 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_136 ) )
F_123 ( V_20 , V_2 -> V_77 ) ;
V_133 = F_13 ( V_2 , V_20 ) ;
F_124 ( V_2 , V_20 ) ;
return V_133 ;
}
static inline void F_125 ( struct V_1 * V_2 ,
void * V_117 , void * V_118 )
{
#if F_35 ( V_134 ) || \
F_35 ( V_135 ) || \
F_35 ( V_137 ) || \
F_35 ( V_138 ) || \
F_35 ( V_139 )
void * V_11 = V_117 ;
void * V_140 = V_118 ? : V_117 ;
void * V_133 ;
do {
V_133 = F_119 ( V_2 , V_11 ) ;
} while ( ( V_11 != V_140 ) && ( V_11 = V_133 ) );
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
T_7 V_3 , int V_110 , struct V_19 V_141 )
{
struct V_23 * V_23 ;
int V_16 = F_23 ( V_141 ) ;
V_3 |= V_142 ;
if ( V_110 == V_143 )
V_23 = F_131 ( V_3 , V_16 ) ;
else
V_23 = F_132 ( V_110 , V_3 , V_16 ) ;
if ( V_23 && F_133 ( V_23 , V_3 , V_16 , V_2 ) ) {
F_134 ( V_23 , V_16 ) ;
V_23 = NULL ;
}
return V_23 ;
}
static int F_135 ( struct V_1 * V_2 )
{
int V_144 ;
unsigned long V_52 , V_145 = F_24 ( V_2 -> V_141 ) ;
if ( V_2 -> V_146 )
return 0 ;
V_144 = F_136 ( V_2 , V_145 , V_147 ) ;
if ( V_144 ) {
F_62 ( L_49 ,
V_2 -> V_40 ) ;
return V_144 ;
}
if ( V_2 -> V_146 ) {
for ( V_52 = 0 ; V_52 < V_145 ; V_52 ++ )
V_2 -> V_146 [ V_52 ] *= V_2 -> V_15 ;
}
return 0 ;
}
static void T_5 F_137 ( void )
{
struct V_1 * V_2 ;
F_138 ( & V_148 ) ;
F_139 (s, &slab_caches, list)
F_135 ( V_2 ) ;
F_140 ( & V_148 ) ;
}
static void * F_141 ( struct V_1 * V_2 , struct V_23 * V_23 ,
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
static bool F_142 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
void * V_89 ;
void * V_153 ;
void * V_154 ;
unsigned long V_152 , V_149 , V_150 , V_151 ;
if ( V_23 -> V_30 < 2 || ! V_2 -> V_146 )
return false ;
V_151 = F_24 ( V_2 -> V_141 ) ;
V_149 = F_143 () % V_151 ;
V_150 = V_23 -> V_30 * V_2 -> V_15 ;
V_89 = F_4 ( V_2 , F_44 ( V_23 ) ) ;
V_153 = F_141 ( V_2 , V_23 , & V_149 , V_89 , V_150 ,
V_151 ) ;
V_23 -> V_38 = V_153 ;
for ( V_152 = 1 ; V_152 < V_23 -> V_30 ; V_152 ++ ) {
F_126 ( V_2 , V_23 , V_153 ) ;
V_154 = F_141 ( V_2 , V_23 , & V_149 , V_89 , V_150 ,
V_151 ) ;
F_19 ( V_2 , V_153 , V_154 ) ;
V_153 = V_154 ;
}
F_126 ( V_2 , V_23 , V_153 ) ;
F_19 ( V_2 , V_153 , NULL ) ;
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
static struct V_23 * F_144 ( struct V_1 * V_2 , T_7 V_3 , int V_110 )
{
struct V_23 * V_23 ;
struct V_19 V_141 = V_2 -> V_141 ;
T_7 V_155 ;
void * V_89 , * V_5 ;
int V_152 , V_16 ;
bool V_156 ;
V_3 &= V_157 ;
if ( F_145 ( V_3 ) )
F_146 () ;
V_3 |= V_2 -> V_158 ;
V_155 = ( V_3 | V_159 | V_160 ) & ~ V_161 ;
if ( ( V_155 & V_162 ) && F_23 ( V_141 ) > F_23 ( V_2 -> V_163 ) )
V_155 = ( V_155 | V_164 ) & ~ ( V_165 | V_161 ) ;
V_23 = F_130 ( V_2 , V_155 , V_110 , V_141 ) ;
if ( F_3 ( ! V_23 ) ) {
V_141 = V_2 -> V_163 ;
V_155 = V_3 ;
V_23 = F_130 ( V_2 , V_155 , V_110 , V_141 ) ;
if ( F_3 ( ! V_23 ) )
goto V_123;
F_10 ( V_2 , V_166 ) ;
}
if ( V_167 &&
! ( V_2 -> V_3 & ( V_168 | V_127 ) ) ) {
int V_169 = 1 << F_23 ( V_141 ) ;
F_147 ( V_23 , F_23 ( V_141 ) , V_155 , V_110 ) ;
if ( V_2 -> F_112 )
F_148 ( V_23 , V_169 ) ;
else
F_149 ( V_23 , V_169 ) ;
}
V_23 -> V_30 = F_24 ( V_141 ) ;
V_16 = F_81 ( V_23 ) ;
V_23 -> V_116 = V_2 ;
F_150 ( V_23 ) ;
if ( F_151 ( V_23 ) )
F_152 ( V_23 ) ;
V_89 = F_44 ( V_23 ) ;
if ( F_3 ( V_2 -> V_3 & V_96 ) )
memset ( V_89 , V_94 , V_18 << V_16 ) ;
F_153 ( V_23 ) ;
V_156 = F_142 ( V_2 , V_23 ) ;
if ( ! V_156 ) {
F_154 (p, idx, s, start, page->objects) {
F_126 ( V_2 , V_23 , V_5 ) ;
if ( F_96 ( V_152 < V_23 -> V_30 ) )
F_19 ( V_2 , V_5 , V_5 + V_2 -> V_15 ) ;
else
F_19 ( V_2 , V_5 , NULL ) ;
}
V_23 -> V_38 = F_4 ( V_2 , V_89 ) ;
}
V_23 -> V_29 = V_23 -> V_30 ;
V_23 -> V_28 = 1 ;
V_123:
if ( F_145 ( V_3 ) )
F_155 () ;
if ( ! V_23 )
return NULL ;
F_156 ( F_157 ( V_23 ) ,
( V_2 -> V_3 & V_170 ) ?
V_171 : V_172 ,
1 << F_23 ( V_141 ) ) ;
F_95 ( V_2 , F_107 ( V_23 ) , V_23 -> V_30 ) ;
return V_23 ;
}
static struct V_23 * F_158 ( struct V_1 * V_2 , T_7 V_3 , int V_110 )
{
if ( F_3 ( V_3 & V_173 ) ) {
T_7 V_174 = V_3 & V_173 ;
V_3 &= ~ V_173 ;
F_159 ( L_50 ,
V_174 , & V_174 , V_3 , & V_3 ) ;
}
return F_144 ( V_2 ,
V_3 & ( V_175 | V_176 ) , V_110 ) ;
}
static void F_160 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_16 = F_81 ( V_23 ) ;
int V_169 = 1 << V_16 ;
if ( V_2 -> V_3 & V_114 ) {
void * V_5 ;
F_80 ( V_2 , V_23 ) ;
F_161 (p, s, page_address(page),
page->objects)
F_82 ( V_2 , V_23 , V_5 , V_113 ) ;
}
F_162 ( V_23 , F_81 ( V_23 ) ) ;
F_156 ( F_157 ( V_23 ) ,
( V_2 -> V_3 & V_170 ) ?
V_171 : V_172 ,
- V_169 ) ;
F_163 ( V_23 ) ;
F_164 ( V_23 ) ;
F_165 ( V_23 ) ;
if ( V_62 -> V_177 )
V_62 -> V_177 -> V_178 += V_169 ;
F_166 ( V_23 , V_16 , V_2 ) ;
F_134 ( V_23 , V_16 ) ;
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
int V_16 = F_81 ( V_23 ) ;
int V_12 = ( V_18 << V_16 ) - V_2 -> V_17 ;
F_33 ( V_2 -> V_17 != sizeof( * V_117 ) ) ;
V_117 = F_44 ( V_23 ) + V_12 ;
} else {
V_117 = & V_23 -> V_179 ;
}
F_171 ( V_117 , F_167 ) ;
} else
F_160 ( V_2 , V_23 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_99 ( V_2 , F_107 ( V_23 ) , V_23 -> V_30 ) ;
F_170 ( V_2 , V_23 ) ;
}
static inline void
F_173 ( struct V_106 * V_34 , struct V_23 * V_23 , int V_118 )
{
V_34 -> V_184 ++ ;
if ( V_118 == V_185 )
F_174 ( & V_23 -> V_108 , & V_34 -> V_186 ) ;
else
F_88 ( & V_23 -> V_108 , & V_34 -> V_186 ) ;
}
static inline void F_175 ( struct V_106 * V_34 ,
struct V_23 * V_23 , int V_118 )
{
F_87 ( & V_34 -> V_107 ) ;
F_173 ( V_34 , V_23 , V_118 ) ;
}
static inline void F_176 ( struct V_106 * V_34 ,
struct V_23 * V_23 )
{
F_87 ( & V_34 -> V_107 ) ;
F_90 ( & V_23 -> V_108 ) ;
V_34 -> V_184 -- ;
}
static inline void * F_177 ( struct V_1 * V_2 ,
struct V_106 * V_34 , struct V_23 * V_23 ,
int V_187 , int * V_30 )
{
void * V_38 ;
unsigned long V_27 ;
struct V_23 V_188 ;
F_87 ( & V_34 -> V_107 ) ;
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
F_33 ( V_188 . V_28 ) ;
V_188 . V_28 = 1 ;
if ( ! F_32 ( V_2 , V_23 ,
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
F_10 ( V_2 , V_193 ) ;
V_11 = V_68 ;
} else {
F_183 ( V_2 , V_23 , 0 ) ;
F_10 ( V_2 , V_194 ) ;
}
if ( ! F_5 ( V_2 )
|| V_192 > V_2 -> V_195 / 2 )
break;
}
F_184 ( & V_34 -> V_107 ) ;
return V_11 ;
}
static void * F_185 ( struct V_1 * V_2 , T_7 V_3 ,
struct V_189 * V_190 )
{
#ifdef F_186
struct V_196 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_199 ;
enum V_200 V_201 = F_187 ( V_3 ) ;
void * V_11 ;
unsigned int V_202 ;
if ( ! V_2 -> V_203 ||
F_188 () % 1024 > V_2 -> V_203 )
return NULL ;
do {
V_202 = F_189 () ;
V_196 = F_190 ( F_191 () , V_3 ) ;
F_192 (zone, z, zonelist, high_zoneidx) {
struct V_106 * V_34 ;
V_34 = F_92 ( V_2 , F_193 ( V_199 ) ) ;
if ( V_34 && F_194 ( V_199 , V_3 ) &&
V_34 -> V_184 > V_2 -> V_204 ) {
V_11 = F_179 ( V_2 , V_34 , V_190 , V_3 ) ;
if ( V_11 ) {
return V_11 ;
}
}
}
} while ( F_195 ( V_202 ) );
#endif
return NULL ;
}
static void * F_196 ( struct V_1 * V_2 , T_7 V_3 , int V_110 ,
struct V_189 * V_190 )
{
void * V_11 ;
int V_205 = V_110 ;
if ( V_110 == V_143 )
V_205 = F_197 () ;
else if ( ! F_198 ( V_110 ) )
V_205 = F_199 ( V_110 ) ;
V_11 = F_179 ( V_2 , F_92 ( V_2 , V_205 ) , V_190 , V_3 ) ;
if ( V_11 || V_110 != V_143 )
return V_11 ;
return F_185 ( V_2 , V_3 , V_190 ) ;
}
static inline unsigned long F_200 ( unsigned long V_206 )
{
return V_206 + V_207 ;
}
static inline unsigned int F_201 ( unsigned long V_206 )
{
return V_206 % V_207 ;
}
static inline unsigned long F_202 ( unsigned long V_206 )
{
return V_206 / V_207 ;
}
static inline unsigned int F_203 ( int V_60 )
{
return V_60 ;
}
static inline void F_204 ( const char * V_34 ,
const struct V_1 * V_2 , unsigned long V_206 )
{
#ifdef F_38
unsigned long V_208 = F_205 ( V_2 -> V_10 -> V_206 ) ;
F_39 ( L_52 , V_34 , V_2 -> V_40 ) ;
#ifdef F_206
if ( F_201 ( V_206 ) != F_201 ( V_208 ) )
F_159 ( L_53 ,
F_201 ( V_206 ) , F_201 ( V_208 ) ) ;
else
#endif
if ( F_202 ( V_206 ) != F_202 ( V_208 ) )
F_159 ( L_54 ,
F_202 ( V_206 ) , F_202 ( V_208 ) ) ;
else
F_159 ( L_55 ,
V_208 , V_206 , F_200 ( V_206 ) ) ;
#endif
F_10 ( V_2 , V_209 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
int V_60 ;
F_208 (cpu)
F_209 ( V_2 -> V_10 , V_60 ) -> V_206 = F_203 ( V_60 ) ;
}
static void F_210 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_38 )
{
enum T_8 { V_210 , V_211 , V_212 , V_213 };
struct V_106 * V_34 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
int V_214 = 0 ;
enum T_8 V_215 = V_210 , V_216 = V_210 ;
void * V_217 ;
int V_118 = V_218 ;
struct V_23 V_188 ;
struct V_23 V_219 ;
if ( V_23 -> V_38 ) {
F_10 ( V_2 , V_220 ) ;
V_118 = V_185 ;
}
while ( V_38 && ( V_217 = F_13 ( V_2 , V_38 ) ) ) {
void * V_221 ;
unsigned long V_27 ;
do {
V_221 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_19 ( V_2 , V_38 , V_221 ) ;
V_188 . V_27 = V_27 ;
V_188 . V_29 -- ;
F_33 ( ! V_188 . V_28 ) ;
} while ( ! F_32 ( V_2 , V_23 ,
V_221 , V_27 ,
V_38 , V_188 . V_27 ,
L_56 ) );
V_38 = V_217 ;
}
V_222:
V_219 . V_38 = V_23 -> V_38 ;
V_219 . V_27 = V_23 -> V_27 ;
F_33 ( ! V_219 . V_28 ) ;
V_188 . V_27 = V_219 . V_27 ;
if ( V_38 ) {
V_188 . V_29 -- ;
F_19 ( V_2 , V_38 , V_219 . V_38 ) ;
V_188 . V_38 = V_38 ;
} else
V_188 . V_38 = V_219 . V_38 ;
V_188 . V_28 = 0 ;
if ( ! V_188 . V_29 && V_34 -> V_184 >= V_2 -> V_204 )
V_216 = V_213 ;
else if ( V_188 . V_38 ) {
V_216 = V_211 ;
if ( ! V_214 ) {
V_214 = 1 ;
F_180 ( & V_34 -> V_107 ) ;
}
} else {
V_216 = V_212 ;
if ( F_1 ( V_2 ) && ! V_214 ) {
V_214 = 1 ;
F_180 ( & V_34 -> V_107 ) ;
}
}
if ( V_215 != V_216 ) {
if ( V_215 == V_211 )
F_176 ( V_34 , V_23 ) ;
else if ( V_215 == V_212 )
F_89 ( V_2 , V_34 , V_23 ) ;
if ( V_216 == V_211 ) {
F_175 ( V_34 , V_23 , V_118 ) ;
F_10 ( V_2 , V_118 ) ;
} else if ( V_216 == V_212 ) {
F_10 ( V_2 , V_223 ) ;
F_86 ( V_2 , V_34 , V_23 ) ;
}
}
V_215 = V_216 ;
if ( ! F_32 ( V_2 , V_23 ,
V_219 . V_38 , V_219 . V_27 ,
V_188 . V_38 , V_188 . V_27 ,
L_57 ) )
goto V_222;
if ( V_214 )
F_184 ( & V_34 -> V_107 ) ;
if ( V_216 == V_213 ) {
F_10 ( V_2 , V_224 ) ;
F_172 ( V_2 , V_23 ) ;
F_10 ( V_2 , V_225 ) ;
}
}
static void F_211 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
#ifdef F_6
struct V_106 * V_34 = NULL , * V_226 = NULL ;
struct V_23 * V_23 , * V_227 = NULL ;
while ( ( V_23 = V_190 -> V_186 ) ) {
struct V_23 V_188 ;
struct V_23 V_219 ;
V_190 -> V_186 = V_23 -> V_154 ;
V_226 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
if ( V_34 != V_226 ) {
if ( V_34 )
F_184 ( & V_34 -> V_107 ) ;
V_34 = V_226 ;
F_180 ( & V_34 -> V_107 ) ;
}
do {
V_219 . V_38 = V_23 -> V_38 ;
V_219 . V_27 = V_23 -> V_27 ;
F_33 ( ! V_219 . V_28 ) ;
V_188 . V_27 = V_219 . V_27 ;
V_188 . V_38 = V_219 . V_38 ;
V_188 . V_28 = 0 ;
} while ( ! F_32 ( V_2 , V_23 ,
V_219 . V_38 , V_219 . V_27 ,
V_188 . V_38 , V_188 . V_27 ,
L_57 ) );
if ( F_3 ( ! V_188 . V_29 && V_34 -> V_184 >= V_2 -> V_204 ) ) {
V_23 -> V_154 = V_227 ;
V_227 = V_23 ;
} else {
F_175 ( V_34 , V_23 , V_185 ) ;
F_10 ( V_2 , V_228 ) ;
}
}
if ( V_34 )
F_184 ( & V_34 -> V_107 ) ;
while ( V_227 ) {
V_23 = V_227 ;
V_227 = V_227 -> V_154 ;
F_10 ( V_2 , V_224 ) ;
F_172 ( V_2 , V_23 ) ;
F_10 ( V_2 , V_225 ) ;
}
#endif
}
static void F_183 ( struct V_1 * V_2 , struct V_23 * V_23 , int V_229 )
{
#ifdef F_6
struct V_23 * V_230 ;
int V_169 ;
int V_231 ;
F_212 () ;
do {
V_169 = 0 ;
V_231 = 0 ;
V_230 = F_213 ( V_2 -> V_10 -> V_186 ) ;
if ( V_230 ) {
V_231 = V_230 -> V_231 ;
V_169 = V_230 -> V_169 ;
if ( V_229 && V_231 > V_2 -> V_195 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_211 ( V_2 , F_214 ( V_2 -> V_10 ) ) ;
F_42 ( V_3 ) ;
V_230 = NULL ;
V_231 = 0 ;
V_169 = 0 ;
F_10 ( V_2 , V_232 ) ;
}
}
V_169 ++ ;
V_231 += V_23 -> V_30 - V_23 -> V_29 ;
V_23 -> V_169 = V_169 ;
V_23 -> V_231 = V_231 ;
V_23 -> V_154 = V_230 ;
} while ( F_215 ( V_2 -> V_10 -> V_186 , V_230 , V_23 )
!= V_230 );
if ( F_3 ( ! V_2 -> V_195 ) ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_211 ( V_2 , F_214 ( V_2 -> V_10 ) ) ;
F_42 ( V_3 ) ;
}
F_216 () ;
#endif
}
static inline void F_217 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
F_10 ( V_2 , V_233 ) ;
F_210 ( V_2 , V_190 -> V_23 , V_190 -> V_38 ) ;
V_190 -> V_206 = F_200 ( V_190 -> V_206 ) ;
V_190 -> V_23 = NULL ;
V_190 -> V_38 = NULL ;
}
static inline void F_218 ( struct V_1 * V_2 , int V_60 )
{
struct V_189 * V_190 = F_209 ( V_2 -> V_10 , V_60 ) ;
if ( F_96 ( V_190 ) ) {
if ( V_190 -> V_23 )
F_217 ( V_2 , V_190 ) ;
F_211 ( V_2 , V_190 ) ;
}
}
static void F_219 ( void * V_234 )
{
struct V_1 * V_2 = V_234 ;
F_218 ( V_2 , F_59 () ) ;
}
static bool F_220 ( int V_60 , void * V_235 )
{
struct V_1 * V_2 = V_235 ;
struct V_189 * V_190 = F_209 ( V_2 -> V_10 , V_60 ) ;
return V_190 -> V_23 || V_190 -> V_186 ;
}
static void F_221 ( struct V_1 * V_2 )
{
F_222 ( F_220 , F_219 , V_2 , 1 , V_236 ) ;
}
static int F_223 ( unsigned int V_60 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
F_138 ( & V_148 ) ;
F_139 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_218 ( V_2 , V_60 ) ;
F_42 ( V_3 ) ;
}
F_140 ( & V_148 ) ;
return 0 ;
}
static inline int F_224 ( struct V_23 * V_23 , int V_110 )
{
#ifdef F_186
if ( ! V_23 || ( V_110 != V_143 && F_107 ( V_23 ) != V_110 ) )
return 0 ;
#endif
return 1 ;
}
static int F_225 ( struct V_23 * V_23 )
{
return V_23 -> V_30 - V_23 -> V_29 ;
}
static inline unsigned long F_226 ( struct V_106 * V_34 )
{
return F_93 ( & V_34 -> V_112 ) ;
}
static unsigned long F_227 ( struct V_106 * V_34 ,
int (* F_228)( struct V_23 * ) )
{
unsigned long V_3 ;
unsigned long V_20 = 0 ;
struct V_23 * V_23 ;
F_108 ( & V_34 -> V_107 , V_3 ) ;
F_139 (page, &n->partial, lru)
V_20 += F_228 ( V_23 ) ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
return V_20 ;
}
static T_4 void
F_229 ( struct V_1 * V_2 , T_7 V_237 , int V_238 )
{
#ifdef F_2
static F_230 ( V_239 , V_240 ,
V_241 ) ;
int V_110 ;
struct V_106 * V_34 ;
if ( ( V_237 & V_159 ) || ! F_231 ( & V_239 ) )
return;
F_159 ( L_58 ,
V_238 , V_237 , & V_237 ) ;
F_159 ( L_59 ,
V_2 -> V_40 , V_2 -> V_77 , V_2 -> V_15 , F_23 ( V_2 -> V_141 ) ,
F_23 ( V_2 -> V_163 ) ) ;
if ( F_23 ( V_2 -> V_163 ) > F_232 ( V_2 -> V_77 ) )
F_159 ( L_60 ,
V_2 -> V_40 ) ;
F_233 (s, node, n) {
unsigned long V_111 ;
unsigned long V_242 ;
unsigned long V_243 ;
V_243 = F_227 ( V_34 , F_225 ) ;
V_111 = F_94 ( V_34 ) ;
V_242 = F_226 ( V_34 ) ;
F_159 ( L_61 ,
V_110 , V_111 , V_242 , V_243 ) ;
}
#endif
}
static inline void * F_234 ( struct V_1 * V_2 , T_7 V_3 ,
int V_110 , struct V_189 * * V_244 )
{
void * V_38 ;
struct V_189 * V_190 = * V_244 ;
struct V_23 * V_23 ;
V_38 = F_196 ( V_2 , V_3 , V_110 , V_190 ) ;
if ( V_38 )
return V_38 ;
V_23 = F_158 ( V_2 , V_3 , V_110 ) ;
if ( V_23 ) {
V_190 = F_235 ( V_2 -> V_10 ) ;
if ( V_190 -> V_23 )
F_217 ( V_2 , V_190 ) ;
V_38 = V_23 -> V_38 ;
V_23 -> V_38 = NULL ;
F_10 ( V_2 , V_245 ) ;
V_190 -> V_23 = V_23 ;
* V_244 = V_190 ;
} else
V_38 = NULL ;
return V_38 ;
}
static inline bool F_182 ( struct V_23 * V_23 , T_7 V_237 )
{
if ( F_3 ( F_236 ( V_23 ) ) )
return F_237 ( V_237 ) ;
return true ;
}
static inline void * F_238 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_23 V_188 ;
unsigned long V_27 ;
void * V_38 ;
do {
V_38 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
V_188 . V_27 = V_27 ;
F_33 ( ! V_188 . V_28 ) ;
V_188 . V_29 = V_23 -> V_30 ;
V_188 . V_28 = V_38 != NULL ;
} while ( ! F_32 ( V_2 , V_23 ,
V_38 , V_27 ,
NULL , V_188 . V_27 ,
L_62 ) );
return V_38 ;
}
static void * F_239 ( struct V_1 * V_2 , T_7 V_237 , int V_110 ,
unsigned long V_14 , struct V_189 * V_190 )
{
void * V_38 ;
struct V_23 * V_23 ;
V_23 = V_190 -> V_23 ;
if ( ! V_23 )
goto F_158;
V_222:
if ( F_3 ( ! F_224 ( V_23 , V_110 ) ) ) {
int V_205 = V_110 ;
if ( V_110 != V_143 && ! F_198 ( V_110 ) )
V_205 = F_199 ( V_110 ) ;
if ( F_3 ( ! F_224 ( V_23 , V_205 ) ) ) {
F_10 ( V_2 , V_246 ) ;
F_210 ( V_2 , V_23 , V_190 -> V_38 ) ;
V_190 -> V_23 = NULL ;
V_190 -> V_38 = NULL ;
goto F_158;
}
}
if ( F_3 ( ! F_182 ( V_23 , V_237 ) ) ) {
F_210 ( V_2 , V_23 , V_190 -> V_38 ) ;
V_190 -> V_23 = NULL ;
V_190 -> V_38 = NULL ;
goto F_158;
}
V_38 = V_190 -> V_38 ;
if ( V_38 )
goto V_247;
V_38 = F_238 ( V_2 , V_23 ) ;
if ( ! V_38 ) {
V_190 -> V_23 = NULL ;
F_10 ( V_2 , V_248 ) ;
goto F_158;
}
F_10 ( V_2 , V_249 ) ;
V_247:
F_33 ( ! V_190 -> V_23 -> V_28 ) ;
V_190 -> V_38 = F_13 ( V_2 , V_38 ) ;
V_190 -> V_206 = F_200 ( V_190 -> V_206 ) ;
return V_38 ;
F_158:
if ( V_190 -> V_186 ) {
V_23 = V_190 -> V_23 = V_190 -> V_186 ;
V_190 -> V_186 = V_23 -> V_154 ;
F_10 ( V_2 , V_250 ) ;
V_190 -> V_38 = NULL ;
goto V_222;
}
V_38 = F_234 ( V_2 , V_237 , V_110 , & V_190 ) ;
if ( F_3 ( ! V_38 ) ) {
F_229 ( V_2 , V_237 , V_110 ) ;
return NULL ;
}
V_23 = V_190 -> V_23 ;
if ( F_96 ( ! F_1 ( V_2 ) && F_182 ( V_23 , V_237 ) ) )
goto V_247;
if ( F_1 ( V_2 ) &&
! F_104 ( V_2 , V_23 , V_38 , V_14 ) )
goto F_158;
F_210 ( V_2 , V_23 , F_13 ( V_2 , V_38 ) ) ;
V_190 -> V_23 = NULL ;
V_190 -> V_38 = NULL ;
return V_38 ;
}
static void * F_240 ( struct V_1 * V_2 , T_7 V_237 , int V_110 ,
unsigned long V_14 , struct V_189 * V_190 )
{
void * V_5 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_206
V_190 = F_214 ( V_2 -> V_10 ) ;
#endif
V_5 = F_239 ( V_2 , V_237 , V_110 , V_14 , V_190 ) ;
F_42 ( V_3 ) ;
return V_5 ;
}
static T_1 void * F_241 ( struct V_1 * V_2 ,
T_7 V_237 , int V_110 , unsigned long V_14 )
{
void * V_11 ;
struct V_189 * V_190 ;
struct V_23 * V_23 ;
unsigned long V_206 ;
V_2 = F_242 ( V_2 , V_237 ) ;
if ( ! V_2 )
return NULL ;
V_222:
do {
V_206 = F_213 ( V_2 -> V_10 -> V_206 ) ;
V_190 = F_235 ( V_2 -> V_10 ) ;
} while ( F_243 ( F_206 ) &&
F_3 ( V_206 != F_244 ( V_190 -> V_206 ) ) );
F_245 () ;
V_11 = V_190 -> V_38 ;
V_23 = V_190 -> V_23 ;
if ( F_3 ( ! V_11 || ! F_224 ( V_23 , V_110 ) ) ) {
V_11 = F_240 ( V_2 , V_237 , V_110 , V_14 , V_190 ) ;
F_10 ( V_2 , V_251 ) ;
} else {
void * V_124 = F_16 ( V_2 , V_11 ) ;
if ( F_3 ( ! F_246 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_206 ,
V_11 , V_206 ,
V_124 , F_200 ( V_206 ) ) ) ) {
F_204 ( L_63 , V_2 , V_206 ) ;
goto V_222;
}
F_14 ( V_2 , V_124 ) ;
F_10 ( V_2 , V_252 ) ;
}
if ( F_3 ( V_237 & V_253 ) && V_11 )
memset ( V_11 , 0 , V_2 -> V_77 ) ;
F_247 ( V_2 , V_237 , 1 , & V_11 ) ;
return V_11 ;
}
static T_1 void * F_248 ( struct V_1 * V_2 ,
T_7 V_237 , unsigned long V_14 )
{
return F_241 ( V_2 , V_237 , V_143 , V_14 ) ;
}
void * F_249 ( struct V_1 * V_2 , T_7 V_237 )
{
void * V_122 = F_248 ( V_2 , V_237 , V_254 ) ;
F_250 ( V_254 , V_122 , V_2 -> V_77 ,
V_2 -> V_15 , V_237 ) ;
return V_122 ;
}
void * F_251 ( struct V_1 * V_2 , T_7 V_237 , T_6 V_15 )
{
void * V_122 = F_248 ( V_2 , V_237 , V_254 ) ;
F_252 ( V_254 , V_122 , V_15 , V_2 -> V_15 , V_237 ) ;
F_253 ( V_2 , V_122 , V_15 , V_237 ) ;
return V_122 ;
}
void * F_254 ( struct V_1 * V_2 , T_7 V_237 , int V_110 )
{
void * V_122 = F_241 ( V_2 , V_237 , V_110 , V_254 ) ;
F_255 ( V_254 , V_122 ,
V_2 -> V_77 , V_2 -> V_15 , V_237 , V_110 ) ;
return V_122 ;
}
void * F_256 ( struct V_1 * V_2 ,
T_7 V_237 ,
int V_110 , T_6 V_15 )
{
void * V_122 = F_241 ( V_2 , V_237 , V_110 , V_254 ) ;
F_257 ( V_254 , V_122 ,
V_15 , V_2 -> V_15 , V_237 , V_110 ) ;
F_253 ( V_2 , V_122 , V_15 , V_237 ) ;
return V_122 ;
}
static void F_258 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_120 ,
unsigned long V_14 )
{
void * V_221 ;
int V_255 ;
struct V_23 V_188 ;
unsigned long V_27 ;
struct V_106 * V_34 = NULL ;
unsigned long V_121 ( V_3 ) ;
F_10 ( V_2 , V_256 ) ;
if ( F_1 ( V_2 ) &&
! F_106 ( V_2 , V_23 , V_117 , V_118 , V_120 , V_14 ) )
return;
do {
if ( F_3 ( V_34 ) ) {
F_109 ( & V_34 -> V_107 , V_3 ) ;
V_34 = NULL ;
}
V_221 = V_23 -> V_38 ;
V_27 = V_23 -> V_27 ;
F_19 ( V_2 , V_118 , V_221 ) ;
V_188 . V_27 = V_27 ;
V_255 = V_188 . V_28 ;
V_188 . V_29 -= V_120 ;
if ( ( ! V_188 . V_29 || ! V_221 ) && ! V_255 ) {
if ( F_5 ( V_2 ) && ! V_221 ) {
V_188 . V_28 = 1 ;
} else {
V_34 = F_92 ( V_2 , F_107 ( V_23 ) ) ;
F_108 ( & V_34 -> V_107 , V_3 ) ;
}
}
} while ( ! F_40 ( V_2 , V_23 ,
V_221 , V_27 ,
V_117 , V_188 . V_27 ,
L_64 ) );
if ( F_96 ( ! V_34 ) ) {
if ( V_188 . V_28 && ! V_255 ) {
F_183 ( V_2 , V_23 , 1 ) ;
F_10 ( V_2 , V_257 ) ;
}
if ( V_255 )
F_10 ( V_2 , V_258 ) ;
return;
}
if ( F_3 ( ! V_188 . V_29 && V_34 -> V_184 >= V_2 -> V_204 ) )
goto V_259;
if ( ! F_5 ( V_2 ) && F_3 ( ! V_221 ) ) {
if ( F_1 ( V_2 ) )
F_89 ( V_2 , V_34 , V_23 ) ;
F_175 ( V_34 , V_23 , V_185 ) ;
F_10 ( V_2 , V_228 ) ;
}
F_109 ( & V_34 -> V_107 , V_3 ) ;
return;
V_259:
if ( V_221 ) {
F_176 ( V_34 , V_23 ) ;
F_10 ( V_2 , V_260 ) ;
} else {
F_89 ( V_2 , V_34 , V_23 ) ;
}
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_10 ( V_2 , V_225 ) ;
F_172 ( V_2 , V_23 ) ;
}
static T_1 void F_259 ( struct V_1 * V_2 ,
struct V_23 * V_23 , void * V_117 , void * V_118 ,
int V_120 , unsigned long V_14 )
{
void * V_140 = V_118 ? : V_117 ;
struct V_189 * V_190 ;
unsigned long V_206 ;
V_222:
do {
V_206 = F_213 ( V_2 -> V_10 -> V_206 ) ;
V_190 = F_235 ( V_2 -> V_10 ) ;
} while ( F_243 ( F_206 ) &&
F_3 ( V_206 != F_244 ( V_190 -> V_206 ) ) );
F_245 () ;
if ( F_96 ( V_23 == V_190 -> V_23 ) ) {
F_19 ( V_2 , V_140 , V_190 -> V_38 ) ;
if ( F_3 ( ! F_246 (
V_2 -> V_10 -> V_38 , V_2 -> V_10 -> V_206 ,
V_190 -> V_38 , V_206 ,
V_117 , F_200 ( V_206 ) ) ) ) {
F_204 ( L_65 , V_2 , V_206 ) ;
goto V_222;
}
F_10 ( V_2 , V_261 ) ;
} else
F_258 ( V_2 , V_23 , V_117 , V_140 , V_120 , V_14 ) ;
}
static T_1 void F_260 ( struct V_1 * V_2 , struct V_23 * V_23 ,
void * V_117 , void * V_118 , int V_120 ,
unsigned long V_14 )
{
F_125 ( V_2 , V_117 , V_118 ) ;
if ( V_2 -> V_3 & V_262 && ! ( V_2 -> V_3 & V_183 ) )
return;
F_259 ( V_2 , V_23 , V_117 , V_118 , V_120 , V_14 ) ;
}
void F_261 ( struct V_1 * V_263 , void * V_20 , unsigned long V_14 )
{
F_259 ( V_263 , F_168 ( V_20 ) , V_20 , NULL , 1 , V_14 ) ;
}
void F_262 ( struct V_1 * V_2 , void * V_20 )
{
V_2 = F_263 ( V_2 , V_20 ) ;
if ( ! V_2 )
return;
F_260 ( V_2 , F_168 ( V_20 ) , V_20 , NULL , 1 , V_254 ) ;
F_264 ( V_254 , V_20 ) ;
}
static inline
int F_265 ( struct V_1 * V_2 , T_6 V_15 ,
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
if ( F_3 ( ! F_84 ( V_23 ) ) ) {
F_266 ( ! F_267 ( V_23 ) ) ;
F_116 ( V_11 ) ;
F_134 ( V_23 , F_81 ( V_23 ) ) ;
V_5 [ V_15 ] = NULL ;
return V_15 ;
}
V_265 -> V_2 = V_23 -> V_116 ;
} else {
V_265 -> V_2 = F_263 ( V_2 , V_11 ) ;
}
V_265 -> V_23 = V_23 ;
F_19 ( V_265 -> V_2 , V_11 , NULL ) ;
V_265 -> V_118 = V_11 ;
V_265 -> V_38 = V_11 ;
V_5 [ V_15 ] = NULL ;
V_265 -> V_120 = 1 ;
while ( V_15 ) {
V_11 = V_5 [ -- V_15 ] ;
if ( ! V_11 )
continue;
if ( V_265 -> V_23 == F_168 ( V_11 ) ) {
F_19 ( V_265 -> V_2 , V_11 , V_265 -> V_38 ) ;
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
void F_268 ( struct V_1 * V_2 , T_6 V_15 , void * * V_5 )
{
if ( F_178 ( ! V_15 ) )
return;
do {
struct V_264 V_265 ;
V_15 = F_265 ( V_2 , V_15 , V_5 , & V_265 ) ;
if ( ! V_265 . V_23 )
continue;
F_260 ( V_265 . V_2 , V_265 . V_23 , V_265 . V_38 , V_265 . V_118 , V_265 . V_120 , V_254 ) ;
} while ( F_96 ( V_15 ) );
}
int F_269 ( struct V_1 * V_2 , T_7 V_3 , T_6 V_15 ,
void * * V_5 )
{
struct V_189 * V_190 ;
int V_52 ;
V_2 = F_242 ( V_2 , V_3 ) ;
if ( F_3 ( ! V_2 ) )
return false ;
F_155 () ;
V_190 = F_214 ( V_2 -> V_10 ) ;
for ( V_52 = 0 ; V_52 < V_15 ; V_52 ++ ) {
void * V_11 = V_190 -> V_38 ;
if ( F_3 ( ! V_11 ) ) {
V_5 [ V_52 ] = F_239 ( V_2 , V_3 , V_143 ,
V_254 , V_190 ) ;
if ( F_3 ( ! V_5 [ V_52 ] ) )
goto error;
V_190 = F_214 ( V_2 -> V_10 ) ;
continue;
}
V_190 -> V_38 = F_13 ( V_2 , V_11 ) ;
V_5 [ V_52 ] = V_11 ;
}
V_190 -> V_206 = F_200 ( V_190 -> V_206 ) ;
F_146 () ;
if ( F_3 ( V_3 & V_253 ) ) {
int V_268 ;
for ( V_268 = 0 ; V_268 < V_52 ; V_268 ++ )
memset ( V_5 [ V_268 ] , 0 , V_2 -> V_77 ) ;
}
F_247 ( V_2 , V_3 , V_15 , V_5 ) ;
return V_52 ;
error:
F_146 () ;
F_247 ( V_2 , V_3 , V_52 , V_5 ) ;
F_270 ( V_2 , V_52 , V_5 ) ;
return 0 ;
}
static inline int F_271 ( int V_15 , int V_269 ,
int V_270 , int V_271 , int V_17 )
{
int V_16 ;
int V_272 ;
int V_273 = V_274 ;
if ( F_21 ( V_273 , V_15 , V_17 ) > V_103 )
return F_232 ( V_15 * V_103 ) - 1 ;
for ( V_16 = F_272 ( V_273 , F_232 ( V_269 * V_15 + V_17 ) ) ;
V_16 <= V_270 ; V_16 ++ ) {
unsigned long V_275 = V_18 << V_16 ;
V_272 = ( V_275 - V_17 ) % V_15 ;
if ( V_272 <= V_275 / V_271 )
break;
}
return V_16 ;
}
static inline int F_273 ( int V_15 , int V_17 )
{
int V_16 ;
int V_269 ;
int V_276 ;
int V_102 ;
V_269 = V_277 ;
if ( ! V_269 )
V_269 = 4 * ( F_274 ( V_278 ) + 1 ) ;
V_102 = F_21 ( V_279 , V_15 , V_17 ) ;
V_269 = V_163 ( V_269 , V_102 ) ;
while ( V_269 > 1 ) {
V_276 = 16 ;
while ( V_276 >= 4 ) {
V_16 = F_271 ( V_15 , V_269 ,
V_279 , V_276 , V_17 ) ;
if ( V_16 <= V_279 )
return V_16 ;
V_276 /= 2 ;
}
V_269 -- ;
}
V_16 = F_271 ( V_15 , 1 , V_279 , 1 , V_17 ) ;
if ( V_16 <= V_279 )
return V_16 ;
V_16 = F_271 ( V_15 , 1 , V_280 , 1 , V_17 ) ;
if ( V_16 < V_280 )
return V_16 ;
return - V_281 ;
}
static void
F_275 ( struct V_106 * V_34 )
{
V_34 -> V_184 = 0 ;
F_276 ( & V_34 -> V_107 ) ;
F_277 ( & V_34 -> V_186 ) ;
#ifdef F_2
F_278 ( & V_34 -> V_111 , 0 ) ;
F_278 ( & V_34 -> V_112 , 0 ) ;
F_277 ( & V_34 -> V_109 ) ;
#endif
}
static inline int F_279 ( struct V_1 * V_2 )
{
F_280 ( V_282 <
V_283 * sizeof( struct V_189 ) ) ;
V_2 -> V_10 = F_281 ( sizeof( struct V_189 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_10 )
return 0 ;
F_207 ( V_2 ) ;
return 1 ;
}
static void F_282 ( int V_110 )
{
struct V_23 * V_23 ;
struct V_106 * V_34 ;
F_266 ( V_106 -> V_15 < sizeof( struct V_106 ) ) ;
V_23 = F_158 ( V_106 , V_284 , V_110 ) ;
F_266 ( ! V_23 ) ;
if ( F_107 ( V_23 ) != V_110 ) {
F_62 ( L_66 , V_110 ) ;
F_62 ( L_67 ) ;
}
V_34 = V_23 -> V_38 ;
F_266 ( ! V_34 ) ;
V_23 -> V_38 = F_13 ( V_106 , V_34 ) ;
V_23 -> V_29 = 1 ;
V_23 -> V_28 = 0 ;
V_106 -> V_110 [ V_110 ] = V_34 ;
#ifdef F_2
F_75 ( V_106 , V_34 , V_98 ) ;
F_60 ( V_106 , V_34 ) ;
#endif
F_253 ( V_106 , V_34 , sizeof( struct V_106 ) ,
V_147 ) ;
F_275 ( V_34 ) ;
F_95 ( V_106 , V_110 , V_23 -> V_30 ) ;
F_173 ( V_34 , V_23 , V_218 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
int V_110 ;
struct V_106 * V_34 ;
F_233 (s, node, n) {
F_262 ( V_106 , V_34 ) ;
V_2 -> V_110 [ V_110 ] = NULL ;
}
}
void F_284 ( struct V_1 * V_2 )
{
F_285 ( V_2 ) ;
F_286 ( V_2 -> V_10 ) ;
F_283 ( V_2 ) ;
}
static int F_287 ( struct V_1 * V_2 )
{
int V_110 ;
F_288 (node, N_NORMAL_MEMORY) {
struct V_106 * V_34 ;
if ( V_285 == V_286 ) {
F_282 ( V_110 ) ;
continue;
}
V_34 = F_254 ( V_106 ,
V_147 , V_110 ) ;
if ( ! V_34 ) {
F_283 ( V_2 ) ;
return 0 ;
}
V_2 -> V_110 [ V_110 ] = V_34 ;
F_275 ( V_34 ) ;
}
return 1 ;
}
static void F_289 ( struct V_1 * V_2 , unsigned long V_163 )
{
if ( V_163 < V_287 )
V_163 = V_287 ;
else if ( V_163 > V_288 )
V_163 = V_288 ;
V_2 -> V_204 = V_163 ;
}
static int F_290 ( struct V_1 * V_2 , int V_289 )
{
unsigned long V_3 = V_2 -> V_3 ;
T_6 V_15 = V_2 -> V_77 ;
int V_16 ;
V_15 = F_291 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_96 ) && ! ( V_3 & V_183 ) &&
! V_2 -> F_112 )
V_2 -> V_3 |= V_81 ;
else
V_2 -> V_3 &= ~ V_81 ;
if ( ( V_3 & V_6 ) && V_15 == V_2 -> V_77 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_29 = V_15 ;
if ( ( ( V_3 & ( V_183 | V_96 ) ) ||
V_2 -> F_112 ) ) {
V_2 -> V_12 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_65 )
V_15 += 2 * sizeof( struct V_47 ) ;
#endif
F_292 ( V_2 , & V_15 , & V_2 -> V_3 ) ;
#ifdef F_2
if ( V_3 & V_6 ) {
V_15 += sizeof( void * ) ;
V_2 -> V_7 = sizeof( void * ) ;
V_2 -> V_7 = F_291 ( V_2 -> V_7 , V_2 -> V_290 ) ;
V_15 += V_2 -> V_7 ;
}
#endif
V_15 = F_291 ( V_15 , V_2 -> V_290 ) ;
V_2 -> V_15 = V_15 ;
if ( V_289 >= 0 )
V_16 = V_289 ;
else
V_16 = F_273 ( V_15 , V_2 -> V_17 ) ;
if ( V_16 < 0 )
return 0 ;
V_2 -> V_158 = 0 ;
if ( V_16 )
V_2 -> V_158 |= V_291 ;
if ( V_2 -> V_3 & V_292 )
V_2 -> V_158 |= V_293 ;
if ( V_2 -> V_3 & V_170 )
V_2 -> V_158 |= V_294 ;
V_2 -> V_141 = F_22 ( V_16 , V_15 , V_2 -> V_17 ) ;
V_2 -> V_163 = F_22 ( F_232 ( V_15 ) , V_15 , V_2 -> V_17 ) ;
if ( F_24 ( V_2 -> V_141 ) > F_24 ( V_2 -> F_272 ) )
V_2 -> F_272 = V_2 -> V_141 ;
return ! ! F_24 ( V_2 -> V_141 ) ;
}
static int F_293 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_111 ( V_2 -> V_15 , V_3 , V_2 -> V_40 , V_2 -> F_112 ) ;
V_2 -> V_17 = 0 ;
if ( V_181 && ( V_2 -> V_3 & V_183 ) )
V_2 -> V_17 = sizeof( struct V_179 ) ;
if ( ! F_290 ( V_2 , - 1 ) )
goto error;
if ( V_130 ) {
if ( F_232 ( V_2 -> V_15 ) > F_232 ( V_2 -> V_77 ) ) {
V_2 -> V_3 &= ~ V_295 ;
V_2 -> V_12 = 0 ;
if ( ! F_290 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_35 ) && \
F_35 ( V_36 )
if ( F_294 () && ( V_2 -> V_3 & V_296 ) == 0 )
V_2 -> V_3 |= V_37 ;
#endif
F_289 ( V_2 , F_295 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_195 = 0 ;
else if ( V_2 -> V_15 >= V_18 )
V_2 -> V_195 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_195 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_195 = 13 ;
else
V_2 -> V_195 = 30 ;
#ifdef F_186
V_2 -> V_203 = 1000 ;
#endif
if ( V_285 >= V_297 ) {
if ( F_135 ( V_2 ) )
goto error;
}
if ( ! F_287 ( V_2 ) )
goto error;
if ( F_279 ( V_2 ) )
return 0 ;
F_283 ( V_2 ) ;
error:
if ( V_3 & V_298 )
F_296 ( L_68 ,
V_2 -> V_40 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_23 ( V_2 -> V_141 ) , V_2 -> V_12 , V_3 ) ;
return - V_299 ;
}
static void F_297 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const char * V_44 )
{
#ifdef F_2
void * V_14 = F_44 ( V_23 ) ;
void * V_5 ;
unsigned long * V_41 = F_298 ( F_299 ( V_23 -> V_30 ) *
sizeof( long ) , V_236 ) ;
if ( ! V_41 )
return;
F_74 ( V_2 , V_23 , V_44 , V_2 -> V_40 ) ;
F_25 ( V_23 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects) {
if ( ! F_300 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) ) {
F_62 ( L_69 , V_5 , V_5 - V_14 ) ;
F_63 ( V_2 , V_5 ) ;
}
}
F_29 ( V_23 ) ;
F_301 ( V_41 ) ;
#endif
}
static void F_302 ( struct V_1 * V_2 , struct V_106 * V_34 )
{
F_303 ( V_300 ) ;
struct V_23 * V_23 , * V_180 ;
F_266 ( F_34 () ) ;
F_304 ( & V_34 -> V_107 ) ;
F_181 (page, h, &n->partial, lru) {
if ( ! V_23 -> V_29 ) {
F_176 ( V_34 , V_23 ) ;
F_88 ( & V_23 -> V_108 , & V_300 ) ;
} else {
F_297 ( V_2 , V_23 ,
L_70 ) ;
}
}
F_305 ( & V_34 -> V_107 ) ;
F_181 (page, h, &discard, lru)
F_172 ( V_2 , V_23 ) ;
}
int F_306 ( struct V_1 * V_2 )
{
int V_110 ;
struct V_106 * V_34 ;
F_221 ( V_2 ) ;
F_233 (s, node, n) {
F_302 ( V_2 , V_34 ) ;
if ( V_34 -> V_184 || F_91 ( V_2 , V_110 ) )
return 1 ;
}
return 0 ;
}
static int T_5 F_307 ( char * V_125 )
{
F_308 ( & V_125 , & V_274 ) ;
return 1 ;
}
static int T_5 F_309 ( char * V_125 )
{
F_308 ( & V_125 , & V_279 ) ;
V_279 = V_163 ( V_279 , V_280 - 1 ) ;
return 1 ;
}
static int T_5 F_310 ( char * V_125 )
{
F_308 ( & V_125 , & V_277 ) ;
return 1 ;
}
void * F_311 ( T_6 V_15 , T_7 V_3 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) )
return F_312 ( V_15 , V_3 ) ;
V_2 = F_313 ( V_15 , V_3 ) ;
if ( F_3 ( F_314 ( V_2 ) ) )
return V_2 ;
V_122 = F_248 ( V_2 , V_3 , V_254 ) ;
F_252 ( V_254 , V_122 , V_15 , V_2 -> V_15 , V_3 ) ;
F_253 ( V_2 , V_122 , V_15 , V_3 ) ;
return V_122 ;
}
static void * F_315 ( T_6 V_15 , T_7 V_3 , int V_110 )
{
struct V_23 * V_23 ;
void * V_132 = NULL ;
V_3 |= V_291 | V_142 ;
V_23 = F_316 ( V_110 , V_3 , F_232 ( V_15 ) ) ;
if ( V_23 )
V_132 = F_44 ( V_23 ) ;
F_113 ( V_132 , V_15 , V_3 ) ;
return V_132 ;
}
void * F_317 ( T_6 V_15 , T_7 V_3 , int V_110 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) ) {
V_122 = F_315 ( V_15 , V_3 , V_110 ) ;
F_257 ( V_254 , V_122 ,
V_15 , V_18 << F_232 ( V_15 ) ,
V_3 , V_110 ) ;
return V_122 ;
}
V_2 = F_313 ( V_15 , V_3 ) ;
if ( F_3 ( F_314 ( V_2 ) ) )
return V_2 ;
V_122 = F_241 ( V_2 , V_3 , V_110 , V_254 ) ;
F_257 ( V_254 , V_122 , V_15 , V_2 -> V_15 , V_3 , V_110 ) ;
F_253 ( V_2 , V_122 , V_15 , V_3 ) ;
return V_122 ;
}
const char * F_318 ( const void * V_132 , unsigned long V_34 ,
struct V_23 * V_23 )
{
struct V_1 * V_2 ;
unsigned long V_12 ;
T_6 V_77 ;
V_2 = V_23 -> V_116 ;
V_77 = F_319 ( V_2 ) ;
if ( V_132 < F_44 ( V_23 ) )
return V_2 -> V_40 ;
V_12 = ( V_132 - F_44 ( V_23 ) ) % V_2 -> V_15 ;
if ( F_1 ( V_2 ) && V_2 -> V_3 & V_6 ) {
if ( V_12 < V_2 -> V_7 )
return V_2 -> V_40 ;
V_12 -= V_2 -> V_7 ;
}
if ( V_12 <= V_77 && V_34 <= V_77 - V_12 )
return NULL ;
return V_2 -> V_40 ;
}
static T_6 F_320 ( const void * V_11 )
{
struct V_23 * V_23 ;
if ( F_3 ( V_11 == V_302 ) )
return 0 ;
V_23 = F_168 ( V_11 ) ;
if ( F_3 ( ! F_84 ( V_23 ) ) ) {
F_178 ( ! F_267 ( V_23 ) ) ;
return V_18 << F_81 ( V_23 ) ;
}
return F_319 ( V_23 -> V_116 ) ;
}
T_6 F_321 ( const void * V_11 )
{
T_6 V_15 = F_320 ( V_11 ) ;
F_322 ( V_11 , V_15 ) ;
return V_15 ;
}
void F_301 ( const void * V_20 )
{
struct V_23 * V_23 ;
void * V_11 = ( void * ) V_20 ;
F_323 ( V_254 , V_20 ) ;
if ( F_3 ( F_314 ( V_20 ) ) )
return;
V_23 = F_168 ( V_20 ) ;
if ( F_3 ( ! F_84 ( V_23 ) ) ) {
F_266 ( ! F_267 ( V_23 ) ) ;
F_116 ( V_20 ) ;
F_134 ( V_23 , F_81 ( V_23 ) ) ;
return;
}
F_260 ( V_23 -> V_116 , V_23 , V_11 , NULL , 1 , V_254 ) ;
}
int F_324 ( struct V_1 * V_2 )
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
F_221 ( V_2 ) ;
F_233 (s, node, n) {
F_277 ( & V_300 ) ;
for ( V_52 = 0 ; V_52 < V_304 ; V_52 ++ )
F_277 ( V_303 + V_52 ) ;
F_108 ( & V_34 -> V_107 , V_3 ) ;
F_181 (page, t, &n->partial, lru) {
int free = V_23 -> V_30 - V_23 -> V_29 ;
F_245 () ;
F_266 ( free <= 0 ) ;
if ( free == V_23 -> V_30 ) {
F_325 ( & V_23 -> V_108 , & V_300 ) ;
V_34 -> V_184 -- ;
} else if ( free <= V_304 )
F_325 ( & V_23 -> V_108 , V_303 + free - 1 ) ;
}
for ( V_52 = V_304 - 1 ; V_52 >= 0 ; V_52 -- )
F_326 ( V_303 + V_52 , & V_34 -> V_186 ) ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
F_181 (page, t, &discard, lru)
F_172 ( V_2 , V_23 ) ;
if ( F_91 ( V_2 , V_110 ) )
V_122 = 1 ;
}
return V_122 ;
}
static int F_327 ( void * V_305 )
{
struct V_1 * V_2 ;
F_138 ( & V_148 ) ;
F_139 (s, &slab_caches, list)
F_324 ( V_2 ) ;
F_140 ( & V_148 ) ;
return 0 ;
}
static void F_328 ( void * V_305 )
{
struct V_106 * V_34 ;
struct V_1 * V_2 ;
struct V_306 * V_307 = V_305 ;
int V_308 ;
V_308 = V_307 -> V_309 ;
if ( V_308 < 0 )
return;
F_138 ( & V_148 ) ;
F_139 (s, &slab_caches, list) {
V_34 = F_92 ( V_2 , V_308 ) ;
if ( V_34 ) {
F_266 ( F_91 ( V_2 , V_308 ) ) ;
V_2 -> V_110 [ V_308 ] = NULL ;
F_262 ( V_106 , V_34 ) ;
}
}
F_140 ( & V_148 ) ;
}
static int F_329 ( void * V_305 )
{
struct V_106 * V_34 ;
struct V_1 * V_2 ;
struct V_306 * V_307 = V_305 ;
int V_238 = V_307 -> V_309 ;
int V_122 = 0 ;
if ( V_238 < 0 )
return 0 ;
F_138 ( & V_148 ) ;
F_139 (s, &slab_caches, list) {
V_34 = F_249 ( V_106 , V_147 ) ;
if ( ! V_34 ) {
V_122 = - V_310 ;
goto V_123;
}
F_275 ( V_34 ) ;
V_2 -> V_110 [ V_238 ] = V_34 ;
}
V_123:
F_140 ( & V_148 ) ;
return V_122 ;
}
static int F_330 ( struct V_311 * V_312 ,
unsigned long V_313 , void * V_305 )
{
int V_122 = 0 ;
switch ( V_313 ) {
case V_314 :
V_122 = F_329 ( V_305 ) ;
break;
case V_315 :
V_122 = F_327 ( V_305 ) ;
break;
case V_316 :
case V_317 :
F_328 ( V_305 ) ;
break;
case V_318 :
case V_319 :
break;
}
if ( V_122 )
V_122 = F_331 ( V_122 ) ;
else
V_122 = V_320 ;
return V_122 ;
}
static struct V_1 * T_5 F_332 ( struct V_1 * V_321 )
{
int V_110 ;
struct V_1 * V_2 = F_333 ( V_1 , V_284 ) ;
struct V_106 * V_34 ;
memcpy ( V_2 , V_321 , V_1 -> V_77 ) ;
F_218 ( V_2 , F_59 () ) ;
F_233 (s, node, n) {
struct V_23 * V_5 ;
F_139 (p, &n->partial, lru)
V_5 -> V_116 = V_2 ;
#ifdef F_2
F_139 (p, &n->full, lru)
V_5 -> V_116 = V_2 ;
#endif
}
F_334 ( V_2 ) ;
F_88 ( & V_2 -> V_322 , & V_323 ) ;
return V_2 ;
}
void T_5 F_335 ( void )
{
static V_324 struct V_1 V_325 ,
V_326 ;
if ( F_336 () )
V_279 = 0 ;
V_106 = & V_326 ;
V_1 = & V_325 ;
F_337 ( V_106 , L_71 ,
sizeof( struct V_106 ) , V_327 ) ;
F_338 ( & V_328 ) ;
V_285 = V_329 ;
F_337 ( V_1 , L_72 ,
F_339 ( struct V_1 , V_110 ) +
V_330 * sizeof( struct V_106 * ) ,
V_327 ) ;
V_1 = F_332 ( & V_325 ) ;
V_106 = F_332 ( & V_326 ) ;
F_340 () ;
F_341 ( 0 ) ;
F_137 () ;
F_342 ( V_331 , L_73 , NULL ,
F_223 ) ;
F_39 ( L_74 ,
F_343 () ,
V_274 , V_279 , V_277 ,
V_278 , V_330 ) ;
}
void T_5 F_344 ( void )
{
}
struct V_1 *
F_345 ( const char * V_40 , T_6 V_15 , T_6 V_290 ,
unsigned long V_3 , void (* F_112)( void * ) )
{
struct V_1 * V_2 , * V_190 ;
V_2 = F_346 ( V_15 , V_290 , V_3 , V_40 , F_112 ) ;
if ( V_2 ) {
V_2 -> V_332 ++ ;
V_2 -> V_77 = F_272 ( V_2 -> V_77 , ( int ) V_15 ) ;
V_2 -> V_29 = F_347 ( int , V_2 -> V_29 , F_291 ( V_15 , sizeof( void * ) ) ) ;
F_348 (c, s) {
V_190 -> V_77 = V_2 -> V_77 ;
V_190 -> V_29 = F_347 ( int , V_190 -> V_29 ,
F_291 ( V_15 , sizeof( void * ) ) ) ;
}
if ( F_8 ( V_2 , V_40 ) ) {
V_2 -> V_332 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_349 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_144 ;
V_144 = F_293 ( V_2 , V_3 ) ;
if ( V_144 )
return V_144 ;
if ( V_285 <= V_297 )
return 0 ;
F_9 ( V_2 ) ;
V_144 = F_7 ( V_2 ) ;
if ( V_144 )
F_284 ( V_2 ) ;
return V_144 ;
}
void * F_350 ( T_6 V_15 , T_7 V_237 , unsigned long V_333 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) )
return F_312 ( V_15 , V_237 ) ;
V_2 = F_313 ( V_15 , V_237 ) ;
if ( F_3 ( F_314 ( V_2 ) ) )
return V_2 ;
V_122 = F_248 ( V_2 , V_237 , V_333 ) ;
F_252 ( V_333 , V_122 , V_15 , V_2 -> V_15 , V_237 ) ;
return V_122 ;
}
void * F_351 ( T_6 V_15 , T_7 V_237 ,
int V_110 , unsigned long V_333 )
{
struct V_1 * V_2 ;
void * V_122 ;
if ( F_3 ( V_15 > V_301 ) ) {
V_122 = F_315 ( V_15 , V_237 , V_110 ) ;
F_257 ( V_333 , V_122 ,
V_15 , V_18 << F_232 ( V_15 ) ,
V_237 , V_110 ) ;
return V_122 ;
}
V_2 = F_313 ( V_15 , V_237 ) ;
if ( F_3 ( F_314 ( V_2 ) ) )
return V_2 ;
V_122 = F_241 ( V_2 , V_237 , V_110 , V_333 ) ;
F_257 ( V_333 , V_122 , V_15 , V_2 -> V_15 , V_237 , V_110 ) ;
return V_122 ;
}
static int F_352 ( struct V_23 * V_23 )
{
return V_23 -> V_29 ;
}
static int F_353 ( struct V_23 * V_23 )
{
return V_23 -> V_30 ;
}
static int F_354 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
void * V_5 ;
void * V_14 = F_44 ( V_23 ) ;
if ( ! F_83 ( V_2 , V_23 ) ||
! F_85 ( V_2 , V_23 , NULL ) )
return 0 ;
F_355 ( V_41 , V_23 -> V_30 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects) {
if ( F_300 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_82 ( V_2 , V_23 , V_5 , V_113 ) )
return 0 ;
}
F_161 (p, s, addr, page->objects)
if ( ! F_300 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
if ( ! F_82 ( V_2 , V_23 , V_5 , V_98 ) )
return 0 ;
return 1 ;
}
static void F_356 ( struct V_1 * V_2 , struct V_23 * V_23 ,
unsigned long * V_41 )
{
F_25 ( V_23 ) ;
F_354 ( V_2 , V_23 , V_41 ) ;
F_29 ( V_23 ) ;
}
static int F_357 ( struct V_1 * V_2 ,
struct V_106 * V_34 , unsigned long * V_41 )
{
unsigned long V_145 = 0 ;
struct V_23 * V_23 ;
unsigned long V_3 ;
F_108 ( & V_34 -> V_107 , V_3 ) ;
F_139 (page, &n->partial, lru) {
F_356 ( V_2 , V_23 , V_41 ) ;
V_145 ++ ;
}
if ( V_145 != V_34 -> V_184 )
F_62 ( L_75 ,
V_2 -> V_40 , V_145 , V_34 -> V_184 ) ;
if ( ! ( V_2 -> V_3 & V_65 ) )
goto V_123;
F_139 (page, &n->full, lru) {
F_356 ( V_2 , V_23 , V_41 ) ;
V_145 ++ ;
}
if ( V_145 != F_93 ( & V_34 -> V_111 ) )
F_62 ( L_76 ,
V_2 -> V_40 , V_145 , F_93 ( & V_34 -> V_111 ) ) ;
V_123:
F_109 ( & V_34 -> V_107 , V_3 ) ;
return V_145 ;
}
static long F_358 ( struct V_1 * V_2 )
{
int V_110 ;
unsigned long V_145 = 0 ;
unsigned long * V_41 = F_359 ( F_299 ( F_24 ( V_2 -> F_272 ) ) *
sizeof( unsigned long ) , V_147 ) ;
struct V_106 * V_34 ;
if ( ! V_41 )
return - V_310 ;
F_221 ( V_2 ) ;
F_233 (s, node, n)
V_145 += F_357 ( V_2 , V_34 , V_41 ) ;
F_301 ( V_41 ) ;
return V_145 ;
}
static void F_360 ( struct V_334 * V_68 )
{
if ( V_68 -> F_272 )
F_361 ( ( unsigned long ) V_68 -> V_335 ,
F_232 ( sizeof( struct V_336 ) * V_68 -> F_272 ) ) ;
}
static int F_362 ( struct V_334 * V_68 , unsigned long F_272 , T_7 V_3 )
{
struct V_336 * V_215 ;
int V_16 ;
V_16 = F_232 ( sizeof( struct V_336 ) * F_272 ) ;
V_215 = ( void * ) F_363 ( V_3 , V_16 ) ;
if ( ! V_215 )
return 0 ;
if ( V_68 -> V_145 ) {
memcpy ( V_215 , V_68 -> V_335 , sizeof( struct V_336 ) * V_68 -> V_145 ) ;
F_360 ( V_68 ) ;
}
V_68 -> F_272 = F_272 ;
V_68 -> V_335 = V_215 ;
return 1 ;
}
static int F_364 ( struct V_334 * V_68 , struct V_1 * V_2 ,
const struct V_47 * V_47 )
{
long V_89 , V_93 , V_149 ;
struct V_336 * V_215 ;
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
V_215 = & V_68 -> V_335 [ V_149 ] ;
V_215 -> V_145 ++ ;
if ( V_47 -> V_63 ) {
V_215 -> V_339 += V_338 ;
if ( V_338 < V_215 -> V_340 )
V_215 -> V_340 = V_338 ;
if ( V_338 > V_215 -> V_341 )
V_215 -> V_341 = V_338 ;
if ( V_47 -> V_61 < V_215 -> V_342 )
V_215 -> V_342 = V_47 -> V_61 ;
if ( V_47 -> V_61 > V_215 -> V_343 )
V_215 -> V_343 = V_47 -> V_61 ;
F_365 ( V_47 -> V_60 ,
F_366 ( V_215 -> V_344 ) ) ;
}
F_367 ( F_107 ( F_368 ( V_47 ) ) , V_215 -> V_345 ) ;
return 1 ;
}
if ( V_47 -> V_14 < V_337 )
V_93 = V_149 ;
else
V_89 = V_149 ;
}
if ( V_68 -> V_145 >= V_68 -> F_272 && ! F_362 ( V_68 , 2 * V_68 -> F_272 , V_236 ) )
return 0 ;
V_215 = V_68 -> V_335 + V_149 ;
if ( V_149 < V_68 -> V_145 )
memmove ( V_215 + 1 , V_215 ,
( V_68 -> V_145 - V_149 ) * sizeof( struct V_336 ) ) ;
V_68 -> V_145 ++ ;
V_215 -> V_145 = 1 ;
V_215 -> V_14 = V_47 -> V_14 ;
V_215 -> V_339 = V_338 ;
V_215 -> V_340 = V_338 ;
V_215 -> V_341 = V_338 ;
V_215 -> V_342 = V_47 -> V_61 ;
V_215 -> V_343 = V_47 -> V_61 ;
F_369 ( F_366 ( V_215 -> V_344 ) ) ;
F_365 ( V_47 -> V_60 , F_366 ( V_215 -> V_344 ) ) ;
F_370 ( V_215 -> V_345 ) ;
F_367 ( F_107 ( F_368 ( V_47 ) ) , V_215 -> V_345 ) ;
return 1 ;
}
static void F_371 ( struct V_334 * V_68 , struct V_1 * V_2 ,
struct V_23 * V_23 , enum V_48 V_49 ,
unsigned long * V_41 )
{
void * V_14 = F_44 ( V_23 ) ;
void * V_5 ;
F_355 ( V_41 , V_23 -> V_30 ) ;
F_43 ( V_2 , V_23 , V_41 ) ;
F_161 (p, s, addr, page->objects)
if ( ! F_300 ( F_20 ( V_5 , V_2 , V_14 ) , V_41 ) )
F_364 ( V_68 , V_2 , F_55 ( V_2 , V_5 , V_49 ) ) ;
}
static int F_372 ( struct V_1 * V_2 , char * V_79 ,
enum V_48 V_49 )
{
int V_346 = 0 ;
unsigned long V_52 ;
struct V_334 V_68 = { 0 , 0 , NULL } ;
int V_110 ;
unsigned long * V_41 = F_359 ( F_299 ( F_24 ( V_2 -> F_272 ) ) *
sizeof( unsigned long ) , V_147 ) ;
struct V_106 * V_34 ;
if ( ! V_41 || ! F_362 ( & V_68 , V_18 / sizeof( struct V_336 ) ,
V_347 ) ) {
F_301 ( V_41 ) ;
return sprintf ( V_79 , L_77 ) ;
}
F_221 ( V_2 ) ;
F_233 (s, node, n) {
unsigned long V_3 ;
struct V_23 * V_23 ;
if ( ! F_93 ( & V_34 -> V_111 ) )
continue;
F_108 ( & V_34 -> V_107 , V_3 ) ;
F_139 (page, &n->partial, lru)
F_371 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_139 (page, &n->full, lru)
F_371 ( & V_68 , V_2 , V_23 , V_49 , V_41 ) ;
F_109 ( & V_34 -> V_107 , V_3 ) ;
}
for ( V_52 = 0 ; V_52 < V_68 . V_145 ; V_52 ++ ) {
struct V_336 * V_215 = & V_68 . V_335 [ V_52 ] ;
if ( V_346 > V_18 - V_348 - 100 )
break;
V_346 += sprintf ( V_79 + V_346 , L_78 , V_215 -> V_145 ) ;
if ( V_215 -> V_14 )
V_346 += sprintf ( V_79 + V_346 , L_79 , ( void * ) V_215 -> V_14 ) ;
else
V_346 += sprintf ( V_79 + V_346 , L_80 ) ;
if ( V_215 -> V_339 != V_215 -> V_340 ) {
V_346 += sprintf ( V_79 + V_346 , L_81 ,
V_215 -> V_340 ,
( long ) F_373 ( V_215 -> V_339 , V_215 -> V_145 ) ,
V_215 -> V_341 ) ;
} else
V_346 += sprintf ( V_79 + V_346 , L_82 ,
V_215 -> V_340 ) ;
if ( V_215 -> V_342 != V_215 -> V_343 )
V_346 += sprintf ( V_79 + V_346 , L_83 ,
V_215 -> V_342 , V_215 -> V_343 ) ;
else
V_346 += sprintf ( V_79 + V_346 , L_84 ,
V_215 -> V_342 ) ;
if ( F_374 () > 1 &&
! F_375 ( F_366 ( V_215 -> V_344 ) ) &&
V_346 < V_18 - 60 )
V_346 += F_376 ( V_79 + V_346 , V_18 - V_346 - 50 ,
L_85 ,
F_377 ( F_366 ( V_215 -> V_344 ) ) ) ;
if ( V_349 > 1 && ! F_378 ( V_215 -> V_345 ) &&
V_346 < V_18 - 60 )
V_346 += F_376 ( V_79 + V_346 , V_18 - V_346 - 50 ,
L_86 ,
F_379 ( & V_215 -> V_345 ) ) ;
V_346 += sprintf ( V_79 + V_346 , L_87 ) ;
}
F_360 ( & V_68 ) ;
F_301 ( V_41 ) ;
if ( ! V_68 . V_145 )
V_346 += sprintf ( V_79 , L_88 ) ;
return V_346 ;
}
static void T_5 F_380 ( void )
{
T_2 * V_5 ;
F_280 ( V_350 > 16 || V_283 < 10 ) ;
F_62 ( L_89 ) ;
F_62 ( L_90 ) ;
F_62 ( L_91 ) ;
V_5 = F_298 ( 16 , V_147 ) ;
V_5 [ 16 ] = 0x12 ;
F_62 ( L_92 ,
V_5 + 16 ) ;
F_358 ( V_351 [ 4 ] ) ;
V_5 = F_298 ( 32 , V_147 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_62 ( L_93 ,
V_5 ) ;
F_62 ( L_94 ) ;
F_358 ( V_351 [ 5 ] ) ;
V_5 = F_298 ( 64 , V_147 ) ;
V_5 += 64 + ( F_188 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_62 ( L_95 ,
V_5 ) ;
F_62 ( L_94 ) ;
F_358 ( V_351 [ 6 ] ) ;
F_62 ( L_96 ) ;
V_5 = F_298 ( 128 , V_147 ) ;
F_301 ( V_5 ) ;
* V_5 = 0x78 ;
F_62 ( L_97 , V_5 ) ;
F_358 ( V_351 [ 7 ] ) ;
V_5 = F_298 ( 256 , V_147 ) ;
F_301 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_62 ( L_98 , V_5 ) ;
F_358 ( V_351 [ 8 ] ) ;
V_5 = F_298 ( 512 , V_147 ) ;
F_301 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_62 ( L_99 , V_5 ) ;
F_358 ( V_351 [ 9 ] ) ;
}
static void F_380 ( void ) {}
static T_9 F_381 ( struct V_1 * V_2 ,
char * V_79 , unsigned long V_3 )
{
unsigned long V_352 = 0 ;
int V_110 ;
int V_20 ;
unsigned long * V_345 ;
V_345 = F_298 ( sizeof( unsigned long ) * V_330 , V_147 ) ;
if ( ! V_345 )
return - V_310 ;
if ( V_3 & V_353 ) {
int V_60 ;
F_208 (cpu) {
struct V_189 * V_190 = F_209 ( V_2 -> V_10 ,
V_60 ) ;
int V_110 ;
struct V_23 * V_23 ;
V_23 = F_244 ( V_190 -> V_23 ) ;
if ( ! V_23 )
continue;
V_110 = F_107 ( V_23 ) ;
if ( V_3 & V_354 )
V_20 = V_23 -> V_30 ;
else if ( V_3 & V_355 )
V_20 = V_23 -> V_29 ;
else
V_20 = 1 ;
V_352 += V_20 ;
V_345 [ V_110 ] += V_20 ;
V_23 = F_244 ( V_190 -> V_186 ) ;
if ( V_23 ) {
V_110 = F_107 ( V_23 ) ;
if ( V_3 & V_354 )
F_382 ( 1 ) ;
else if ( V_3 & V_355 )
F_382 ( 1 ) ;
else
V_20 = V_23 -> V_169 ;
V_352 += V_20 ;
V_345 [ V_110 ] += V_20 ;
}
}
}
F_383 () ;
#ifdef F_2
if ( V_3 & V_356 ) {
struct V_106 * V_34 ;
F_233 (s, node, n) {
if ( V_3 & V_354 )
V_20 = F_93 ( & V_34 -> V_112 ) ;
else if ( V_3 & V_355 )
V_20 = F_93 ( & V_34 -> V_112 ) -
F_227 ( V_34 , F_225 ) ;
else
V_20 = F_93 ( & V_34 -> V_111 ) ;
V_352 += V_20 ;
V_345 [ V_110 ] += V_20 ;
}
} else
#endif
if ( V_3 & V_357 ) {
struct V_106 * V_34 ;
F_233 (s, node, n) {
if ( V_3 & V_354 )
V_20 = F_227 ( V_34 , F_353 ) ;
else if ( V_3 & V_355 )
V_20 = F_227 ( V_34 , F_352 ) ;
else
V_20 = V_34 -> V_184 ;
V_352 += V_20 ;
V_345 [ V_110 ] += V_20 ;
}
}
V_20 = sprintf ( V_79 , L_100 , V_352 ) ;
#ifdef F_186
for ( V_110 = 0 ; V_110 < V_330 ; V_110 ++ )
if ( V_345 [ V_110 ] )
V_20 += sprintf ( V_79 + V_20 , L_101 ,
V_110 , V_345 [ V_110 ] ) ;
#endif
F_384 () ;
F_301 ( V_345 ) ;
return V_20 + sprintf ( V_79 + V_20 , L_87 ) ;
}
static int F_385 ( struct V_1 * V_2 )
{
int V_110 ;
struct V_106 * V_34 ;
F_233 (s, node, n)
if ( F_93 ( & V_34 -> V_112 ) )
return 1 ;
return 0 ;
}
static T_9 F_386 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_15 ) ;
}
static T_9 F_387 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_290 ) ;
}
static T_9 F_388 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_77 ) ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , F_24 ( V_2 -> V_141 ) ) ;
}
static T_9 F_390 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
unsigned long V_16 ;
int V_144 ;
V_144 = F_391 ( V_79 , 10 , & V_16 ) ;
if ( V_144 )
return V_144 ;
if ( V_16 > V_279 || V_16 < V_274 )
return - V_299 ;
F_290 ( V_2 , V_16 ) ;
return V_45 ;
}
static T_9 F_392 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , F_23 ( V_2 -> V_141 ) ) ;
}
static T_9 F_393 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_103 , V_2 -> V_204 ) ;
}
static T_9 F_394 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
unsigned long V_163 ;
int V_144 ;
V_144 = F_391 ( V_79 , 10 , & V_163 ) ;
if ( V_144 )
return V_144 ;
F_289 ( V_2 , V_163 ) ;
return V_45 ;
}
static T_9 F_395 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_104 , V_2 -> V_195 ) ;
}
static T_9 F_396 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
unsigned long V_30 ;
int V_144 ;
V_144 = F_391 ( V_79 , 10 , & V_30 ) ;
if ( V_144 )
return V_144 ;
if ( V_30 && ! F_5 ( V_2 ) )
return - V_299 ;
V_2 -> V_195 = V_30 ;
F_221 ( V_2 ) ;
return V_45 ;
}
static T_9 F_397 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! V_2 -> F_112 )
return 0 ;
return sprintf ( V_79 , L_105 , V_2 -> F_112 ) ;
}
static T_9 F_398 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_332 < 0 ? 0 : V_2 -> V_332 - 1 ) ;
}
static T_9 F_399 ( struct V_1 * V_2 , char * V_79 )
{
return F_381 ( V_2 , V_79 , V_357 ) ;
}
static T_9 F_400 ( struct V_1 * V_2 , char * V_79 )
{
return F_381 ( V_2 , V_79 , V_353 ) ;
}
static T_9 F_401 ( struct V_1 * V_2 , char * V_79 )
{
return F_381 ( V_2 , V_79 , V_356 | V_355 ) ;
}
static T_9 F_402 ( struct V_1 * V_2 , char * V_79 )
{
return F_381 ( V_2 , V_79 , V_357 | V_355 ) ;
}
static T_9 F_403 ( struct V_1 * V_2 , char * V_79 )
{
int V_30 = 0 ;
int V_169 = 0 ;
int V_60 ;
int V_346 ;
F_404 (cpu) {
struct V_23 * V_23 = F_209 ( V_2 -> V_10 , V_60 ) -> V_186 ;
if ( V_23 ) {
V_169 += V_23 -> V_169 ;
V_30 += V_23 -> V_231 ;
}
}
V_346 = sprintf ( V_79 , L_106 , V_30 , V_169 ) ;
#ifdef F_405
F_404 (cpu) {
struct V_23 * V_23 = F_209 ( V_2 -> V_10 , V_60 ) -> V_186 ;
if ( V_23 && V_346 < V_18 - 20 )
V_346 += sprintf ( V_79 + V_346 , L_107 , V_60 ,
V_23 -> V_231 , V_23 -> V_169 ) ;
}
#endif
return V_346 + sprintf ( V_79 + V_346 , L_87 ) ;
}
static T_9 F_406 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_170 ) ) ;
}
static T_9 F_407 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
V_2 -> V_3 &= ~ V_170 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_170 ;
return V_45 ;
}
static T_9 F_408 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_327 ) ) ;
}
static T_9 F_409 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_292 ) ) ;
}
static T_9 F_410 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_183 ) ) ;
}
static T_9 F_411 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_17 ) ;
}
static T_9 F_412 ( struct V_1 * V_2 , char * V_79 )
{
return F_381 ( V_2 , V_79 , V_356 ) ;
}
static T_9 F_413 ( struct V_1 * V_2 , char * V_79 )
{
return F_381 ( V_2 , V_79 , V_356 | V_354 ) ;
}
static T_9 F_414 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_114 ) ) ;
}
static T_9 F_415 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
V_2 -> V_3 &= ~ V_114 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_114 ;
}
return V_45 ;
}
static T_9 F_416 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_104 ) ) ;
}
static T_9 F_417 ( struct V_1 * V_2 , const char * V_79 ,
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
static T_9 F_418 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_6 ) ) ;
}
static T_9 F_419 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( F_385 ( V_2 ) )
return - V_358 ;
V_2 -> V_3 &= ~ V_6 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_6 ;
}
F_290 ( V_2 , - 1 ) ;
return V_45 ;
}
static T_9 F_420 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_96 ) ) ;
}
static T_9 F_421 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( F_385 ( V_2 ) )
return - V_358 ;
V_2 -> V_3 &= ~ V_96 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 |= V_96 ;
}
F_290 ( V_2 , - 1 ) ;
return V_45 ;
}
static T_9 F_422 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_65 ) ) ;
}
static T_9 F_423 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( F_385 ( V_2 ) )
return - V_358 ;
V_2 -> V_3 &= ~ V_65 ;
if ( V_79 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_37 ;
V_2 -> V_3 |= V_65 ;
}
F_290 ( V_2 , - 1 ) ;
return V_45 ;
}
static T_9 F_424 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_425 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
int V_122 = - V_299 ;
if ( V_79 [ 0 ] == '1' ) {
V_122 = F_358 ( V_2 ) ;
if ( V_122 >= 0 )
V_122 = V_45 ;
}
return V_122 ;
}
static T_9 F_426 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_281 ;
return F_372 ( V_2 , V_79 , V_67 ) ;
}
static T_9 F_427 ( struct V_1 * V_2 , char * V_79 )
{
if ( ! ( V_2 -> V_3 & V_65 ) )
return - V_281 ;
return F_372 ( V_2 , V_79 , V_66 ) ;
}
static T_9 F_428 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , ! ! ( V_2 -> V_3 & V_129 ) ) ;
}
static T_9 F_429 ( struct V_1 * V_2 , const char * V_79 ,
T_6 V_45 )
{
if ( V_2 -> V_332 > 1 )
return - V_299 ;
V_2 -> V_3 &= ~ V_129 ;
if ( V_79 [ 0 ] == '1' )
V_2 -> V_3 |= V_129 ;
return V_45 ;
}
static T_9 F_430 ( struct V_1 * V_2 , char * V_79 )
{
return 0 ;
}
static T_9 F_431 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
if ( V_79 [ 0 ] == '1' )
F_432 ( V_2 ) ;
else
return - V_299 ;
return V_45 ;
}
static T_9 F_433 ( struct V_1 * V_2 , char * V_79 )
{
return sprintf ( V_79 , L_102 , V_2 -> V_203 / 10 ) ;
}
static T_9 F_434 ( struct V_1 * V_2 ,
const char * V_79 , T_6 V_45 )
{
unsigned long V_359 ;
int V_144 ;
V_144 = F_391 ( V_79 , 10 , & V_359 ) ;
if ( V_144 )
return V_144 ;
if ( V_359 <= 100 )
V_2 -> V_203 = V_359 * 10 ;
return V_45 ;
}
static int F_435 ( struct V_1 * V_2 , char * V_79 , enum V_8 V_9 )
{
unsigned long V_360 = 0 ;
int V_60 ;
int V_346 ;
int * V_85 = F_359 ( V_278 * sizeof( int ) , V_147 ) ;
if ( ! V_85 )
return - V_310 ;
F_404 (cpu) {
unsigned V_20 = F_209 ( V_2 -> V_10 , V_60 ) -> F_10 [ V_9 ] ;
V_85 [ V_60 ] = V_20 ;
V_360 += V_20 ;
}
V_346 = sprintf ( V_79 , L_100 , V_360 ) ;
#ifdef F_405
F_404 (cpu) {
if ( V_85 [ V_60 ] && V_346 < V_18 - 20 )
V_346 += sprintf ( V_79 + V_346 , L_108 , V_60 , V_85 [ V_60 ] ) ;
}
#endif
F_301 ( V_85 ) ;
return V_346 + sprintf ( V_79 + V_346 , L_87 ) ;
}
static void F_436 ( struct V_1 * V_2 , enum V_8 V_9 )
{
int V_60 ;
F_404 (cpu)
F_209 ( V_2 -> V_10 , V_60 ) -> F_10 [ V_9 ] = 0 ;
}
static T_9 F_437 ( struct V_361 * V_362 ,
struct V_363 * V_364 ,
char * V_79 )
{
struct V_365 * V_363 ;
struct V_1 * V_2 ;
int V_144 ;
V_363 = F_438 ( V_364 ) ;
V_2 = F_439 ( V_362 ) ;
if ( ! V_363 -> V_366 )
return - V_367 ;
V_144 = V_363 -> V_366 ( V_2 , V_79 ) ;
return V_144 ;
}
static T_9 F_440 ( struct V_361 * V_362 ,
struct V_363 * V_364 ,
const char * V_79 , T_6 V_346 )
{
struct V_365 * V_363 ;
struct V_1 * V_2 ;
int V_144 ;
V_363 = F_438 ( V_364 ) ;
V_2 = F_439 ( V_362 ) ;
if ( ! V_363 -> V_368 )
return - V_367 ;
V_144 = V_363 -> V_368 ( V_2 , V_79 , V_346 ) ;
#ifdef F_441
if ( V_285 >= V_369 && V_144 >= 0 && F_442 ( V_2 ) ) {
struct V_1 * V_190 ;
F_138 ( & V_148 ) ;
if ( V_2 -> V_370 < V_346 )
V_2 -> V_370 = V_346 ;
F_348 (c, s)
V_363 -> V_368 ( V_190 , V_79 , V_346 ) ;
F_140 ( & V_148 ) ;
}
#endif
return V_144 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_441
int V_52 ;
char * V_371 = NULL ;
struct V_1 * V_372 ;
if ( F_442 ( V_2 ) )
return;
V_372 = V_2 -> V_373 . V_372 ;
if ( ! V_372 -> V_370 )
return;
for ( V_52 = 0 ; V_52 < F_443 ( V_374 ) ; V_52 ++ ) {
char V_375 [ 64 ] ;
char * V_79 ;
struct V_365 * V_364 = F_438 ( V_374 [ V_52 ] ) ;
if ( ! V_364 || ! V_364 -> V_368 || ! V_364 -> V_366 )
continue;
if ( V_371 )
V_79 = V_371 ;
else if ( V_372 -> V_370 < F_443 ( V_375 ) )
V_79 = V_375 ;
else {
V_371 = ( char * ) F_444 ( V_147 ) ;
if ( F_178 ( ! V_371 ) )
continue;
V_79 = V_371 ;
}
V_364 -> V_366 ( V_372 , V_79 ) ;
V_364 -> V_368 ( V_2 , V_79 , strlen ( V_79 ) ) ;
}
if ( V_371 )
F_445 ( ( unsigned long ) V_371 ) ;
#endif
}
static void F_446 ( struct V_361 * V_376 )
{
F_447 ( F_439 ( V_376 ) ) ;
}
static int F_448 ( struct V_377 * V_377 , struct V_361 * V_362 )
{
struct V_378 * V_379 = F_449 ( V_362 ) ;
if ( V_379 == & V_380 )
return 1 ;
return 0 ;
}
static inline struct V_377 * F_450 ( struct V_1 * V_2 )
{
#ifdef F_441
if ( ! F_442 ( V_2 ) )
return V_2 -> V_373 . V_372 -> V_381 ;
#endif
return V_382 ;
}
static char * F_451 ( struct V_1 * V_2 )
{
char * V_40 = F_359 ( V_383 , V_147 ) ;
char * V_5 = V_40 ;
F_266 ( ! V_40 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_292 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_170 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_114 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_168 ) )
* V_5 ++ = 't' ;
if ( V_2 -> V_3 & V_384 )
* V_5 ++ = 'A' ;
if ( V_5 != V_40 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_109 , V_2 -> V_15 ) ;
F_266 ( V_5 > V_40 + V_383 - 1 ) ;
return V_40 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_144 ;
const char * V_40 ;
int V_385 = F_452 ( V_2 ) ;
if ( V_385 ) {
F_453 ( & V_382 -> V_362 , V_2 -> V_40 ) ;
V_40 = V_2 -> V_40 ;
} else {
V_40 = F_451 ( V_2 ) ;
}
V_2 -> V_362 . V_377 = F_450 ( V_2 ) ;
V_144 = F_454 ( & V_2 -> V_362 , & V_380 , NULL , L_16 , V_40 ) ;
if ( V_144 )
goto V_123;
V_144 = F_455 ( & V_2 -> V_362 , & V_386 ) ;
if ( V_144 )
goto V_387;
#ifdef F_441
if ( F_442 ( V_2 ) ) {
V_2 -> V_381 = F_456 ( L_110 , NULL , & V_2 -> V_362 ) ;
if ( ! V_2 -> V_381 ) {
V_144 = - V_310 ;
goto V_387;
}
}
#endif
F_457 ( & V_2 -> V_362 , V_388 ) ;
if ( ! V_385 ) {
F_8 ( V_2 , V_2 -> V_40 ) ;
}
V_123:
if ( ! V_385 )
F_301 ( V_40 ) ;
return V_144 ;
V_387:
F_458 ( & V_2 -> V_362 ) ;
goto V_123;
}
void F_459 ( struct V_1 * V_2 )
{
if ( V_285 < V_369 )
return;
#ifdef F_441
F_460 ( V_2 -> V_381 ) ;
#endif
F_457 ( & V_2 -> V_362 , V_389 ) ;
F_458 ( & V_2 -> V_362 ) ;
F_461 ( & V_2 -> V_362 ) ;
}
static int F_8 ( struct V_1 * V_2 , const char * V_40 )
{
struct V_390 * V_391 ;
if ( V_285 == V_369 ) {
F_453 ( & V_382 -> V_362 , V_40 ) ;
return F_462 ( & V_382 -> V_362 , & V_2 -> V_362 , V_40 ) ;
}
V_391 = F_359 ( sizeof( struct V_390 ) , V_147 ) ;
if ( ! V_391 )
return - V_310 ;
V_391 -> V_2 = V_2 ;
V_391 -> V_40 = V_40 ;
V_391 -> V_154 = V_392 ;
V_392 = V_391 ;
return 0 ;
}
static int T_5 F_463 ( void )
{
struct V_1 * V_2 ;
int V_144 ;
F_138 ( & V_148 ) ;
V_382 = F_456 ( L_111 , & V_393 , V_394 ) ;
if ( ! V_382 ) {
F_140 ( & V_148 ) ;
F_62 ( L_112 ) ;
return - V_281 ;
}
V_285 = V_369 ;
F_139 (s, &slab_caches, list) {
V_144 = F_7 ( V_2 ) ;
if ( V_144 )
F_62 ( L_113 ,
V_2 -> V_40 ) ;
}
while ( V_392 ) {
struct V_390 * V_391 = V_392 ;
V_392 = V_392 -> V_154 ;
V_144 = F_8 ( V_391 -> V_2 , V_391 -> V_40 ) ;
if ( V_144 )
F_62 ( L_114 ,
V_391 -> V_40 ) ;
F_301 ( V_391 ) ;
}
F_140 ( & V_148 ) ;
F_380 () ;
return 0 ;
}
void F_464 ( struct V_1 * V_2 , struct V_395 * V_396 )
{
unsigned long V_111 = 0 ;
unsigned long V_242 = 0 ;
unsigned long V_243 = 0 ;
int V_110 ;
struct V_106 * V_34 ;
F_233 (s, node, n) {
V_111 += F_94 ( V_34 ) ;
V_242 += F_226 ( V_34 ) ;
V_243 += F_227 ( V_34 , F_225 ) ;
}
V_396 -> V_397 = V_242 - V_243 ;
V_396 -> V_398 = V_242 ;
V_396 -> V_399 = V_111 ;
V_396 -> V_400 = V_111 ;
V_396 -> V_401 = F_24 ( V_2 -> V_141 ) ;
V_396 -> V_402 = F_23 ( V_2 -> V_141 ) ;
}
void F_465 ( struct V_403 * V_216 , struct V_1 * V_2 )
{
}
T_9 F_466 ( struct V_404 * V_404 , const char T_10 * V_371 ,
T_6 V_145 , T_11 * V_405 )
{
return - V_367 ;
}
