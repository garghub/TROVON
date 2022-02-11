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
static inline struct V_9 * F_12 ( struct V_1 * V_2 , int V_10 )
{
return V_2 -> V_10 [ V_10 ] ;
}
static inline int F_13 ( struct V_1 * V_2 ,
struct V_11 * V_11 , const void * V_12 )
{
void * V_13 ;
if ( ! V_12 )
return 1 ;
V_13 = F_14 ( V_11 ) ;
if ( V_12 < V_13 || V_12 >= V_13 + V_11 -> V_14 * V_2 -> V_15 ||
( V_12 - V_13 ) % V_2 -> V_15 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_15 ( struct V_1 * V_2 , void * V_12 )
{
return * ( void * * ) ( V_12 + V_2 -> V_16 ) ;
}
static void F_16 ( const struct V_1 * V_2 , void * V_12 )
{
F_17 ( V_12 + V_2 -> V_16 ) ;
}
static inline void * F_18 ( struct V_1 * V_2 , void * V_12 )
{
void * V_5 ;
#ifdef F_19
F_20 ( & V_5 , ( void * * ) ( V_12 + V_2 -> V_16 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_15 ( V_2 , V_12 ) ;
#endif
return V_5 ;
}
static inline void F_21 ( struct V_1 * V_2 , void * V_12 , void * V_17 )
{
* ( void * * ) ( V_12 + V_2 -> V_16 ) = V_17 ;
}
static inline int F_22 ( void * V_5 , struct V_1 * V_2 , void * V_18 )
{
return ( V_5 - V_18 ) / V_2 -> V_15 ;
}
static inline T_1 F_23 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_19 | V_20 ) )
return V_2 -> V_21 ;
#endif
if ( V_2 -> V_3 & ( V_22 | V_23 ) )
return V_2 -> V_24 ;
return V_2 -> V_15 ;
}
static inline int F_24 ( int V_25 , unsigned long V_15 , int V_26 )
{
return ( ( V_27 << V_25 ) - V_26 ) / V_15 ;
}
static inline struct V_28 F_25 ( int V_25 ,
unsigned long V_15 , int V_26 )
{
struct V_28 V_29 = {
( V_25 << V_30 ) + F_24 (order, size, reserved)
} ;
return V_29 ;
}
static inline int F_26 ( struct V_28 V_29 )
{
return V_29 . V_29 >> V_30 ;
}
static inline int F_27 ( struct V_28 V_29 )
{
return V_29 . V_29 & V_31 ;
}
static T_2 void F_28 ( struct V_11 * V_11 )
{
F_29 ( V_32 , & V_11 -> V_3 ) ;
}
static T_2 void F_30 ( struct V_11 * V_11 )
{
F_31 ( V_32 , & V_11 -> V_3 ) ;
}
static inline void F_32 ( struct V_11 * V_11 , unsigned long V_33 )
{
struct V_11 V_34 ;
V_34 . V_35 = V_33 ;
V_11 -> V_36 = V_34 . V_36 ;
V_11 -> V_24 = V_34 . V_24 ;
V_11 -> V_14 = V_34 . V_14 ;
}
static inline bool F_33 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_37 , unsigned long V_38 ,
void * V_39 , unsigned long V_33 ,
const char * V_40 )
{
F_34 ( ! F_35 () ) ;
#if F_36 ( V_41 ) && \
F_36 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_37 ( & V_11 -> V_44 , & V_11 -> V_35 ,
V_37 , V_38 ,
V_39 , V_33 ) )
return 1 ;
} else
#endif
{
F_28 ( V_11 ) ;
if ( V_11 -> V_44 == V_37 &&
V_11 -> V_35 == V_38 ) {
V_11 -> V_44 = V_39 ;
F_32 ( V_11 , V_33 ) ;
F_30 ( V_11 ) ;
return 1 ;
}
F_30 ( V_11 ) ;
}
F_38 () ;
F_9 ( V_2 , V_45 ) ;
#ifdef F_39
F_40 ( L_1 , V_40 , V_2 -> V_46 ) ;
#endif
return 0 ;
}
static inline bool F_41 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_37 , unsigned long V_38 ,
void * V_39 , unsigned long V_33 ,
const char * V_40 )
{
#if F_36 ( V_41 ) && \
F_36 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_37 ( & V_11 -> V_44 , & V_11 -> V_35 ,
V_37 , V_38 ,
V_39 , V_33 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_28 ( V_11 ) ;
if ( V_11 -> V_44 == V_37 &&
V_11 -> V_35 == V_38 ) {
V_11 -> V_44 = V_39 ;
F_32 ( V_11 , V_33 ) ;
F_30 ( V_11 ) ;
F_43 ( V_3 ) ;
return 1 ;
}
F_30 ( V_11 ) ;
F_43 ( V_3 ) ;
}
F_38 () ;
F_9 ( V_2 , V_45 ) ;
#ifdef F_39
F_40 ( L_1 , V_40 , V_2 -> V_46 ) ;
#endif
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long * V_47 )
{
void * V_5 ;
void * V_18 = F_14 ( V_11 ) ;
for ( V_5 = V_11 -> V_44 ; V_5 ; V_5 = F_15 ( V_2 , V_5 ) )
F_45 ( F_22 ( V_5 , V_2 , V_18 ) , V_47 ) ;
}
static void F_46 ( char * V_48 , T_3 * V_18 , unsigned int V_49 )
{
F_47 ( V_50 , V_48 , V_51 , 16 , 1 , V_18 ,
V_49 , 1 ) ;
}
static struct V_52 * F_48 ( struct V_1 * V_2 , void * V_12 ,
enum V_53 V_54 )
{
struct V_52 * V_5 ;
if ( V_2 -> V_16 )
V_5 = V_12 + V_2 -> V_16 + sizeof( void * ) ;
else
V_5 = V_12 + V_2 -> V_24 ;
return V_5 + V_54 ;
}
static void F_49 ( struct V_1 * V_2 , void * V_12 ,
enum V_53 V_54 , unsigned long V_18 )
{
struct V_52 * V_5 = F_48 ( V_2 , V_12 , V_54 ) ;
if ( V_18 ) {
#ifdef F_50
struct V_55 V_56 ;
int V_57 ;
V_56 . V_58 = 0 ;
V_56 . V_59 = V_60 ;
V_56 . V_61 = V_5 -> V_62 ;
V_56 . V_63 = 3 ;
F_51 ( & V_56 ) ;
if ( V_56 . V_58 != 0 &&
V_56 . V_61 [ V_56 . V_58 - 1 ] == V_64 )
V_56 . V_58 -- ;
for ( V_57 = V_56 . V_58 ; V_57 < V_60 ; V_57 ++ )
V_5 -> V_62 [ V_57 ] = 0 ;
#endif
V_5 -> V_18 = V_18 ;
V_5 -> V_65 = F_52 () ;
V_5 -> V_66 = V_67 -> V_66 ;
V_5 -> V_68 = V_69 ;
} else
memset ( V_5 , 0 , sizeof( struct V_52 ) ) ;
}
static void F_53 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_49 ( V_2 , V_12 , V_70 , 0UL ) ;
F_49 ( V_2 , V_12 , V_71 , 0UL ) ;
}
static void F_54 ( const char * V_2 , struct V_52 * V_72 )
{
if ( ! V_72 -> V_18 )
return;
F_55 ( L_2 ,
V_2 , ( void * ) V_72 -> V_18 , V_69 - V_72 -> V_68 , V_72 -> V_65 , V_72 -> V_66 ) ;
#ifdef F_50
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
if ( V_72 -> V_62 [ V_57 ] )
F_55 ( L_3 , ( void * ) V_72 -> V_62 [ V_57 ] ) ;
else
break;
}
#endif
}
static void F_56 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_54 ( L_4 , F_48 ( V_2 , V_12 , V_71 ) ) ;
F_54 ( L_5 , F_48 ( V_2 , V_12 , V_70 ) ) ;
}
static void F_57 ( struct V_11 * V_11 )
{
F_55 ( L_6 ,
V_11 , V_11 -> V_14 , V_11 -> V_24 , V_11 -> V_44 , V_11 -> V_3 ) ;
}
static void F_58 ( struct V_1 * V_2 , char * V_73 , ... )
{
struct V_74 V_75 ;
T_4 args ;
va_start ( args , V_73 ) ;
V_75 . V_73 = V_73 ;
V_75 . V_76 = & args ;
F_55 ( L_7 ) ;
F_55 ( L_8 , V_2 -> V_46 , F_59 () , & V_75 ) ;
F_55 ( L_9 ) ;
F_60 ( V_77 , V_78 ) ;
va_end ( args ) ;
}
static void F_61 ( struct V_1 * V_2 , char * V_73 , ... )
{
struct V_74 V_75 ;
T_4 args ;
va_start ( args , V_73 ) ;
V_75 . V_73 = V_73 ;
V_75 . V_76 = & args ;
F_55 ( L_10 , V_2 -> V_46 , & V_75 ) ;
va_end ( args ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned int V_79 ;
T_3 * V_18 = F_14 ( V_11 ) ;
F_56 ( V_2 , V_5 ) ;
F_57 ( V_11 ) ;
F_55 ( L_11 ,
V_5 , V_5 - V_18 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_18 + 16 )
F_46 ( L_12 , V_5 - 16 , 16 ) ;
F_46 ( L_13 , V_5 , F_63 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_19 )
F_46 ( L_14 , V_5 + V_2 -> V_21 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
if ( V_2 -> V_16 )
V_79 = V_2 -> V_16 + sizeof( void * ) ;
else
V_79 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_79 += 2 * sizeof( struct V_52 ) ;
if ( V_79 != V_2 -> V_15 )
F_46 ( L_15 , V_5 + V_79 , V_2 -> V_15 - V_79 ) ;
F_64 () ;
}
static void F_65 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_80 )
{
F_58 ( V_2 , L_16 , V_80 ) ;
F_62 ( V_2 , V_11 , V_12 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_73 , ... )
{
T_4 args ;
char V_81 [ 100 ] ;
va_start ( args , V_73 ) ;
vsnprintf ( V_81 , sizeof( V_81 ) , V_73 , args ) ;
va_end ( args ) ;
F_58 ( V_2 , L_16 , V_81 ) ;
F_57 ( V_11 ) ;
F_64 () ;
}
static void F_67 ( struct V_1 * V_2 , void * V_12 , T_3 V_82 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_83 ) {
memset ( V_5 , V_84 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_85 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_82 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_68 ( struct V_1 * V_2 , char * V_86 , T_3 V_87 ,
void * V_88 , void * V_89 )
{
F_61 ( V_2 , L_17 , V_88 , V_89 - 1 , V_87 ) ;
memset ( V_88 , V_87 , V_89 - V_88 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_90 ,
T_3 * V_91 , unsigned int V_92 , unsigned int V_93 )
{
T_3 * V_94 ;
T_3 * V_95 ;
V_94 = F_70 ( V_91 , V_92 , V_93 ) ;
if ( ! V_94 )
return 1 ;
V_95 = V_91 + V_93 ;
while ( V_95 > V_94 && V_95 [ - 1 ] == V_92 )
V_95 -- ;
F_58 ( V_2 , L_18 , V_90 ) ;
F_55 ( L_19 ,
V_94 , V_95 - 1 , V_94 [ 0 ] , V_92 ) ;
F_62 ( V_2 , V_11 , V_12 ) ;
F_68 ( V_2 , V_90 , V_92 , V_94 , V_95 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_79 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_79 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_79 += 2 * sizeof( struct V_52 ) ;
if ( V_2 -> V_15 == V_79 )
return 1 ;
return F_69 ( V_2 , V_11 , V_5 , L_20 ,
V_5 + V_79 , V_96 , V_2 -> V_15 - V_79 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_91 ;
T_3 * V_94 ;
T_3 * V_95 ;
int V_49 ;
int V_97 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_91 = F_14 ( V_11 ) ;
V_49 = ( V_27 << F_73 ( V_11 ) ) - V_2 -> V_26 ;
V_95 = V_91 + V_49 ;
V_97 = V_49 % V_2 -> V_15 ;
if ( ! V_97 )
return 1 ;
V_94 = F_70 ( V_95 - V_97 , V_96 , V_97 ) ;
if ( ! V_94 )
return 1 ;
while ( V_95 > V_94 && V_95 [ - 1 ] == V_96 )
V_95 -- ;
F_66 ( V_2 , V_11 , L_21 , V_94 , V_95 - 1 ) ;
F_46 ( L_15 , V_95 - V_97 , V_97 ) ;
F_68 ( V_2 , L_22 , V_96 , V_95 - V_97 , V_95 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_82 )
{
T_3 * V_5 = V_12 ;
T_3 * V_98 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_69 ( V_2 , V_11 , V_12 , L_23 ,
V_98 , V_82 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_69 ( V_2 , V_11 , V_5 , L_24 ,
V_98 , V_96 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_82 != V_99 && ( V_2 -> V_3 & V_83 ) &&
( ! F_69 ( V_2 , V_11 , V_5 , L_25 , V_5 ,
V_84 , V_2 -> V_21 - 1 ) ||
! F_69 ( V_2 , V_11 , V_5 , L_25 ,
V_5 + V_2 -> V_21 - 1 , V_85 , 1 ) ) )
return 0 ;
F_71 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_82 == V_99 )
return 1 ;
if ( ! F_13 ( V_2 , V_11 , F_15 ( V_2 , V_5 ) ) ) {
F_65 ( V_2 , V_11 , V_5 , L_26 ) ;
F_21 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_100 ;
F_34 ( ! F_35 () ) ;
if ( ! F_76 ( V_11 ) ) {
F_66 ( V_2 , V_11 , L_27 ) ;
return 0 ;
}
V_100 = F_24 ( F_73 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_100 ) {
F_66 ( V_2 , V_11 , L_28 ,
V_2 -> V_46 , V_11 -> V_14 , V_100 ) ;
return 0 ;
}
if ( V_11 -> V_24 > V_11 -> V_14 ) {
F_66 ( V_2 , V_11 , L_29 ,
V_2 -> V_46 , V_11 -> V_24 , V_11 -> V_14 ) ;
return 0 ;
}
F_72 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_101 )
{
int V_102 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_103 ;
V_17 = V_11 -> V_44 ;
while ( V_17 && V_102 <= V_11 -> V_14 ) {
if ( V_17 == V_101 )
return 1 ;
if ( ! F_13 ( V_2 , V_11 , V_17 ) ) {
if ( V_12 ) {
F_65 ( V_2 , V_11 , V_12 ,
L_30 ) ;
F_21 ( V_2 , V_12 , NULL ) ;
} else {
F_66 ( V_2 , V_11 , L_26 ) ;
V_11 -> V_44 = NULL ;
V_11 -> V_24 = V_11 -> V_14 ;
F_61 ( V_2 , L_31 ) ;
return 0 ;
}
break;
}
V_12 = V_17 ;
V_17 = F_15 ( V_2 , V_12 ) ;
V_102 ++ ;
}
V_103 = F_24 ( F_73 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_103 > V_104 )
V_103 = V_104 ;
if ( V_11 -> V_14 != V_103 ) {
F_66 ( V_2 , V_11 , L_32
L_33 , V_11 -> V_14 , V_103 ) ;
V_11 -> V_14 = V_103 ;
F_61 ( V_2 , L_34 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_102 ) {
F_66 ( V_2 , V_11 , L_35
L_36 , V_11 -> V_24 , V_11 -> V_14 - V_102 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_102 ;
F_61 ( V_2 , L_37 ) ;
}
return V_101 == NULL ;
}
static void V_56 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_54 )
{
if ( V_2 -> V_3 & V_105 ) {
F_40 ( L_38 ,
V_2 -> V_46 ,
V_54 ? L_39 : L_40 ,
V_12 , V_11 -> V_24 ,
V_11 -> V_44 ) ;
if ( ! V_54 )
F_46 ( L_13 , ( void * ) V_12 ,
V_2 -> V_21 ) ;
F_64 () ;
}
}
static inline void F_78 ( void * V_106 , T_1 V_15 , T_5 V_3 )
{
F_79 ( V_106 , V_15 , 1 , V_3 ) ;
}
static inline void F_80 ( const void * V_29 )
{
F_81 ( V_29 ) ;
}
static inline int F_82 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_107 ;
F_83 ( V_3 ) ;
F_84 ( V_3 & V_108 ) ;
return F_85 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_86 ( struct V_1 * V_2 ,
T_5 V_3 , void * V_12 )
{
V_3 &= V_107 ;
F_87 ( V_2 , V_3 , V_12 , F_23 ( V_2 ) ) ;
F_88 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_89 ( struct V_1 * V_2 , void * V_29 )
{
F_90 ( V_29 , V_2 -> V_3 ) ;
#if F_36 ( V_109 ) || F_36 ( V_110 )
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_91 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_92 ( V_29 , V_2 -> V_21 ) ;
F_43 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_111 ) )
F_93 ( V_29 , V_2 -> V_21 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_9 * V_40 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_95 ( & V_40 -> V_112 ) ;
F_96 ( & V_11 -> V_113 , & V_40 -> V_114 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_9 * V_40 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_95 ( & V_40 -> V_112 ) ;
F_98 ( & V_11 -> V_113 ) ;
}
static inline unsigned long F_99 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
return F_100 ( & V_40 -> V_115 ) ;
}
static inline unsigned long F_101 ( struct V_9 * V_40 )
{
return F_100 ( & V_40 -> V_115 ) ;
}
static inline void F_102 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( F_103 ( V_40 ) ) {
F_104 ( & V_40 -> V_115 ) ;
F_105 ( V_14 , & V_40 -> V_116 ) ;
}
}
static inline void F_106 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
F_107 ( & V_40 -> V_115 ) ;
F_108 ( V_14 , & V_40 -> V_116 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_83 ) ) )
return;
F_67 ( V_2 , V_12 , V_117 ) ;
F_53 ( V_2 , V_12 ) ;
}
static T_6 int F_110 ( struct V_1 * V_2 ,
struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_75 ( V_2 , V_11 ) )
goto V_118;
if ( ! F_13 ( V_2 , V_11 , V_12 ) ) {
F_65 ( V_2 , V_11 , V_12 , L_41 ) ;
goto V_118;
}
if ( ! F_74 ( V_2 , V_11 , V_12 , V_117 ) )
goto V_118;
if ( V_2 -> V_3 & V_23 )
F_49 ( V_2 , V_12 , V_71 , V_18 ) ;
V_56 ( V_2 , V_11 , V_12 , 1 ) ;
F_67 ( V_2 , V_12 , V_99 ) ;
return 1 ;
V_118:
if ( F_76 ( V_11 ) ) {
F_61 ( V_2 , L_42 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_44 = NULL ;
}
return 0 ;
}
int T_7 F_111 ( char * V_119 )
{
V_120 = V_121 ;
if ( * V_119 ++ != '=' || ! * V_119 )
goto V_122;
if ( * V_119 == ',' )
goto V_123;
if ( tolower ( * V_119 ) == 'o' ) {
V_124 = 1 ;
goto V_122;
}
V_120 = 0 ;
if ( * V_119 == '-' )
goto V_122;
for (; * V_119 && * V_119 != ',' ; V_119 ++ ) {
switch ( tolower ( * V_119 ) ) {
case 'f' :
V_120 |= V_125 ;
break;
case 'z' :
V_120 |= V_19 ;
break;
case 'p' :
V_120 |= V_20 ;
break;
case 'u' :
V_120 |= V_23 ;
break;
case 't' :
V_120 |= V_105 ;
break;
case 'a' :
V_120 |= V_126 ;
break;
default:
F_55 ( L_43 ,
* V_119 ) ;
}
}
V_123:
if ( * V_119 == ',' )
V_127 = V_119 + 1 ;
V_122:
return 1 ;
}
static unsigned long F_112 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_46 ,
void (* F_113)( void * ) )
{
if ( V_120 && ( ! V_127 || ( V_46 &&
! strncmp ( V_127 , V_46 , strlen ( V_127 ) ) ) ) )
V_3 |= V_120 ;
return V_3 ;
}
static inline void F_109 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 ) {}
static inline int F_110 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 , unsigned long V_18 ) { return 0 ; }
static inline struct V_9 * F_114 (
struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
unsigned long V_18 , unsigned long * V_3 ) { return NULL ; }
static inline int F_72 ( struct V_1 * V_2 , struct V_11 * V_11 )
{ return 1 ; }
static inline int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_82 ) { return 1 ; }
static inline void F_94 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_11 * V_11 ) {}
static inline void F_97 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_11 * V_11 ) {}
static inline unsigned long F_112 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_46 ,
void (* F_113)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_99 ( struct V_1 * V_2 , int V_10 )
{ return 0 ; }
static inline unsigned long F_101 ( struct V_9 * V_40 )
{ return 0 ; }
static inline void F_102 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_106 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_78 ( void * V_106 , T_1 V_15 , T_5 V_3 )
{
F_79 ( V_106 , V_15 , 1 , V_3 ) ;
}
static inline void F_80 ( const void * V_29 )
{
F_81 ( V_29 ) ;
}
static inline int F_82 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_86 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_12 )
{
F_88 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 ,
V_3 & V_107 ) ;
}
static inline void F_89 ( struct V_1 * V_2 , void * V_29 )
{
F_90 ( V_29 , V_2 -> V_3 ) ;
}
static inline struct V_11 * F_115 ( struct V_1 * V_2 ,
T_5 V_3 , int V_10 , struct V_28 V_128 )
{
struct V_11 * V_11 ;
int V_25 = F_26 ( V_128 ) ;
V_3 |= V_129 ;
if ( F_116 ( V_2 , V_3 , V_25 ) )
return NULL ;
if ( V_10 == V_130 )
V_11 = F_117 ( V_3 , V_25 ) ;
else
V_11 = F_118 ( V_10 , V_3 , V_25 ) ;
if ( ! V_11 )
F_119 ( V_2 , V_25 ) ;
return V_11 ;
}
static struct V_11 * F_120 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_128 = V_2 -> V_128 ;
T_5 V_131 ;
V_3 &= V_107 ;
if ( V_3 & V_108 )
F_121 () ;
V_3 |= V_2 -> V_132 ;
V_131 = ( V_3 | V_133 | V_134 ) & ~ V_135 ;
V_11 = F_115 ( V_2 , V_131 , V_10 , V_128 ) ;
if ( F_3 ( ! V_11 ) ) {
V_128 = V_2 -> V_136 ;
V_131 = V_3 ;
V_11 = F_115 ( V_2 , V_131 , V_10 , V_128 ) ;
if ( V_11 )
F_9 ( V_2 , V_137 ) ;
}
if ( V_138 && V_11
&& ! ( V_2 -> V_3 & ( V_139 | V_121 ) ) ) {
int V_140 = 1 << F_26 ( V_128 ) ;
F_122 ( V_11 , F_26 ( V_128 ) , V_131 , V_10 ) ;
if ( V_2 -> F_113 )
F_123 ( V_11 , V_140 ) ;
else
F_124 ( V_11 , V_140 ) ;
}
if ( V_3 & V_108 )
F_125 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_27 ( V_128 ) ;
F_126 ( F_127 ( V_11 ) ,
( V_2 -> V_3 & V_141 ) ?
V_142 : V_143 ,
1 << F_26 ( V_128 ) ) ;
return V_11 ;
}
static void F_128 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_109 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_113 ) )
V_2 -> F_113 ( V_12 ) ;
}
static struct V_11 * F_129 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_91 ;
void * V_144 ;
void * V_5 ;
int V_25 ;
F_130 ( V_3 & V_145 ) ;
V_11 = F_120 ( V_2 ,
V_3 & ( V_146 | V_147 ) , V_10 ) ;
if ( ! V_11 )
goto V_122;
V_25 = F_73 ( V_11 ) ;
F_102 ( V_2 , F_131 ( V_11 ) , V_11 -> V_14 ) ;
V_11 -> V_148 = V_2 ;
F_132 ( V_11 ) ;
if ( V_11 -> V_149 )
F_133 ( V_11 ) ;
V_91 = F_14 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_91 , V_96 , V_27 << V_25 ) ;
V_144 = V_91 ;
F_134 (p, s, start, page->objects) {
F_128 ( V_2 , V_11 , V_144 ) ;
F_21 ( V_2 , V_144 , V_5 ) ;
V_144 = V_5 ;
}
F_128 ( V_2 , V_11 , V_144 ) ;
F_21 ( V_2 , V_144 , NULL ) ;
V_11 -> V_44 = V_91 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_36 = 1 ;
V_122:
return V_11 ;
}
static void F_135 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_73 ( V_11 ) ;
int V_140 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_72 ( V_2 , V_11 ) ;
F_134 (p, s, page_address(page),
page->objects)
F_74 ( V_2 , V_11 , V_5 , V_117 ) ;
}
F_136 ( V_11 , F_73 ( V_11 ) ) ;
F_126 ( F_127 ( V_11 ) ,
( V_2 -> V_3 & V_141 ) ?
V_142 : V_143 ,
- V_140 ) ;
F_137 ( V_11 ) ;
F_138 ( V_11 ) ;
F_139 ( V_11 ) ;
if ( V_67 -> V_150 )
V_67 -> V_150 -> V_151 += V_140 ;
F_140 ( V_11 , V_25 ) ;
F_119 ( V_2 , V_25 ) ;
}
static void F_141 ( struct V_152 * V_153 )
{
struct V_11 * V_11 ;
if ( V_154 )
V_11 = F_142 ( V_153 ) ;
else
V_11 = F_143 ( (struct V_155 * ) V_153 , struct V_11 , V_113 ) ;
F_135 ( V_11 -> V_148 , V_11 ) ;
}
static void F_144 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_152 * V_156 ;
if ( V_154 ) {
int V_25 = F_73 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_34 ( V_2 -> V_26 != sizeof( * V_156 ) ) ;
V_156 = F_14 ( V_11 ) + V_16 ;
} else {
V_156 = ( void * ) & V_11 -> V_113 ;
}
F_145 ( V_156 , F_141 ) ;
} else
F_135 ( V_2 , V_11 ) ;
}
static void F_146 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_106 ( V_2 , F_131 ( V_11 ) , V_11 -> V_14 ) ;
F_144 ( V_2 , V_11 ) ;
}
static inline void
F_147 ( struct V_9 * V_40 , struct V_11 * V_11 , int V_157 )
{
V_40 -> V_158 ++ ;
if ( V_157 == V_159 )
F_148 ( & V_11 -> V_113 , & V_40 -> V_160 ) ;
else
F_96 ( & V_11 -> V_113 , & V_40 -> V_160 ) ;
}
static inline void F_149 ( struct V_9 * V_40 ,
struct V_11 * V_11 , int V_157 )
{
F_95 ( & V_40 -> V_112 ) ;
F_147 ( V_40 , V_11 , V_157 ) ;
}
static inline void
F_150 ( struct V_9 * V_40 , struct V_11 * V_11 )
{
F_98 ( & V_11 -> V_113 ) ;
V_40 -> V_158 -- ;
}
static inline void F_151 ( struct V_9 * V_40 ,
struct V_11 * V_11 )
{
F_95 ( & V_40 -> V_112 ) ;
F_150 ( V_40 , V_11 ) ;
}
static inline void * F_152 ( struct V_1 * V_2 ,
struct V_9 * V_40 , struct V_11 * V_11 ,
int V_161 , int * V_14 )
{
void * V_44 ;
unsigned long V_35 ;
struct V_11 V_162 ;
F_95 ( & V_40 -> V_112 ) ;
V_44 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
V_162 . V_35 = V_35 ;
* V_14 = V_162 . V_14 - V_162 . V_24 ;
if ( V_161 ) {
V_162 . V_24 = V_11 -> V_14 ;
V_162 . V_44 = NULL ;
} else {
V_162 . V_44 = V_44 ;
}
F_34 ( V_162 . V_36 ) ;
V_162 . V_36 = 1 ;
if ( ! F_33 ( V_2 , V_11 ,
V_44 , V_35 ,
V_162 . V_44 , V_162 . V_35 ,
L_44 ) )
return NULL ;
F_151 ( V_40 , V_11 ) ;
F_153 ( ! V_44 ) ;
return V_44 ;
}
static void * F_154 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_163 * V_164 , T_5 V_3 )
{
struct V_11 * V_11 , * V_165 ;
void * V_12 = NULL ;
int V_166 = 0 ;
int V_14 ;
if ( ! V_40 || ! V_40 -> V_158 )
return NULL ;
F_155 ( & V_40 -> V_112 ) ;
F_156 (page, page2, &n->partial, lru) {
void * V_72 ;
if ( ! F_157 ( V_11 , V_3 ) )
continue;
V_72 = F_152 ( V_2 , V_40 , V_11 , V_12 == NULL , & V_14 ) ;
if ( ! V_72 )
break;
V_166 += V_14 ;
if ( ! V_12 ) {
V_164 -> V_11 = V_11 ;
F_9 ( V_2 , V_167 ) ;
V_12 = V_72 ;
} else {
F_158 ( V_2 , V_11 , 0 ) ;
F_9 ( V_2 , V_168 ) ;
}
if ( ! F_4 ( V_2 )
|| V_166 > V_2 -> V_169 / 2 )
break;
}
F_159 ( & V_40 -> V_112 ) ;
return V_12 ;
}
static void * F_160 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_163 * V_164 )
{
#ifdef F_161
struct V_170 * V_170 ;
struct V_171 * V_172 ;
struct V_173 * V_173 ;
enum V_174 V_175 = F_162 ( V_3 ) ;
void * V_12 ;
unsigned int V_176 ;
if ( ! V_2 -> V_177 ||
F_163 () % 1024 > V_2 -> V_177 )
return NULL ;
do {
V_176 = F_164 () ;
V_170 = F_165 ( F_166 () , V_3 ) ;
F_167 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_40 ;
V_40 = F_12 ( V_2 , F_168 ( V_173 ) ) ;
if ( V_40 && F_169 ( V_173 , V_3 ) &&
V_40 -> V_158 > V_2 -> V_178 ) {
V_12 = F_154 ( V_2 , V_40 , V_164 , V_3 ) ;
if ( V_12 ) {
return V_12 ;
}
}
}
} while ( F_170 ( V_176 ) );
#endif
return NULL ;
}
static void * F_171 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_163 * V_164 )
{
void * V_12 ;
int V_179 = ( V_10 == V_130 ) ? F_172 () : V_10 ;
V_12 = F_154 ( V_2 , F_12 ( V_2 , V_179 ) , V_164 , V_3 ) ;
if ( V_12 || V_10 != V_130 )
return V_12 ;
return F_160 ( V_2 , V_3 , V_164 ) ;
}
static inline unsigned long F_173 ( unsigned long V_180 )
{
return V_180 + V_181 ;
}
static inline unsigned int F_174 ( unsigned long V_180 )
{
return V_180 % V_181 ;
}
static inline unsigned long F_175 ( unsigned long V_180 )
{
return V_180 / V_181 ;
}
static inline unsigned int F_176 ( int V_65 )
{
return V_65 ;
}
static inline void F_177 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_180 )
{
#ifdef F_39
unsigned long V_182 = F_178 ( V_2 -> V_8 -> V_180 ) ;
F_40 ( L_45 , V_40 , V_2 -> V_46 ) ;
#ifdef F_179
if ( F_174 ( V_180 ) != F_174 ( V_182 ) )
F_180 ( L_46 ,
F_174 ( V_180 ) , F_174 ( V_182 ) ) ;
else
#endif
if ( F_175 ( V_180 ) != F_175 ( V_182 ) )
F_180 ( L_47 ,
F_175 ( V_180 ) , F_175 ( V_182 ) ) ;
else
F_180 ( L_48 ,
V_182 , V_180 , F_173 ( V_180 ) ) ;
#endif
F_9 ( V_2 , V_183 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
int V_65 ;
F_182 (cpu)
F_183 ( V_2 -> V_8 , V_65 ) -> V_180 = F_176 ( V_65 ) ;
}
static void F_184 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_44 )
{
enum T_8 { V_184 , V_185 , V_186 , V_187 };
struct V_9 * V_40 = F_12 ( V_2 , F_131 ( V_11 ) ) ;
int V_188 = 0 ;
enum T_8 V_189 = V_184 , V_190 = V_184 ;
void * V_191 ;
int V_157 = V_192 ;
struct V_11 V_162 ;
struct V_11 V_193 ;
if ( V_11 -> V_44 ) {
F_9 ( V_2 , V_194 ) ;
V_157 = V_159 ;
}
while ( V_44 && ( V_191 = F_15 ( V_2 , V_44 ) ) ) {
void * V_195 ;
unsigned long V_35 ;
do {
V_195 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
F_21 ( V_2 , V_44 , V_195 ) ;
V_162 . V_35 = V_35 ;
V_162 . V_24 -- ;
F_34 ( ! V_162 . V_36 ) ;
} while ( ! F_33 ( V_2 , V_11 ,
V_195 , V_35 ,
V_44 , V_162 . V_35 ,
L_49 ) );
V_44 = V_191 ;
}
V_196:
V_193 . V_44 = V_11 -> V_44 ;
V_193 . V_35 = V_11 -> V_35 ;
F_34 ( ! V_193 . V_36 ) ;
V_162 . V_35 = V_193 . V_35 ;
if ( V_44 ) {
V_162 . V_24 -- ;
F_21 ( V_2 , V_44 , V_193 . V_44 ) ;
V_162 . V_44 = V_44 ;
} else
V_162 . V_44 = V_193 . V_44 ;
V_162 . V_36 = 0 ;
if ( ! V_162 . V_24 && V_40 -> V_158 >= V_2 -> V_178 )
V_190 = V_187 ;
else if ( V_162 . V_44 ) {
V_190 = V_185 ;
if ( ! V_188 ) {
V_188 = 1 ;
F_155 ( & V_40 -> V_112 ) ;
}
} else {
V_190 = V_186 ;
if ( F_1 ( V_2 ) && ! V_188 ) {
V_188 = 1 ;
F_155 ( & V_40 -> V_112 ) ;
}
}
if ( V_189 != V_190 ) {
if ( V_189 == V_185 )
F_151 ( V_40 , V_11 ) ;
else if ( V_189 == V_186 )
F_97 ( V_2 , V_40 , V_11 ) ;
if ( V_190 == V_185 ) {
F_149 ( V_40 , V_11 , V_157 ) ;
F_9 ( V_2 , V_157 ) ;
} else if ( V_190 == V_186 ) {
F_9 ( V_2 , V_197 ) ;
F_94 ( V_2 , V_40 , V_11 ) ;
}
}
V_189 = V_190 ;
if ( ! F_33 ( V_2 , V_11 ,
V_193 . V_44 , V_193 . V_35 ,
V_162 . V_44 , V_162 . V_35 ,
L_50 ) )
goto V_196;
if ( V_188 )
F_159 ( & V_40 -> V_112 ) ;
if ( V_190 == V_187 ) {
F_9 ( V_2 , V_198 ) ;
F_146 ( V_2 , V_11 ) ;
F_9 ( V_2 , V_199 ) ;
}
}
static void F_185 ( struct V_1 * V_2 ,
struct V_163 * V_164 )
{
#ifdef F_5
struct V_9 * V_40 = NULL , * V_200 = NULL ;
struct V_11 * V_11 , * V_201 = NULL ;
while ( ( V_11 = V_164 -> V_160 ) ) {
struct V_11 V_162 ;
struct V_11 V_193 ;
V_164 -> V_160 = V_11 -> V_202 ;
V_200 = F_12 ( V_2 , F_131 ( V_11 ) ) ;
if ( V_40 != V_200 ) {
if ( V_40 )
F_159 ( & V_40 -> V_112 ) ;
V_40 = V_200 ;
F_155 ( & V_40 -> V_112 ) ;
}
do {
V_193 . V_44 = V_11 -> V_44 ;
V_193 . V_35 = V_11 -> V_35 ;
F_34 ( ! V_193 . V_36 ) ;
V_162 . V_35 = V_193 . V_35 ;
V_162 . V_44 = V_193 . V_44 ;
V_162 . V_36 = 0 ;
} while ( ! F_33 ( V_2 , V_11 ,
V_193 . V_44 , V_193 . V_35 ,
V_162 . V_44 , V_162 . V_35 ,
L_50 ) );
if ( F_3 ( ! V_162 . V_24 && V_40 -> V_158 >= V_2 -> V_178 ) ) {
V_11 -> V_202 = V_201 ;
V_201 = V_11 ;
} else {
F_149 ( V_40 , V_11 , V_159 ) ;
F_9 ( V_2 , V_203 ) ;
}
}
if ( V_40 )
F_159 ( & V_40 -> V_112 ) ;
while ( V_201 ) {
V_11 = V_201 ;
V_201 = V_201 -> V_202 ;
F_9 ( V_2 , V_198 ) ;
F_146 ( V_2 , V_11 ) ;
F_9 ( V_2 , V_199 ) ;
}
#endif
}
static void F_158 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_204 )
{
#ifdef F_5
struct V_11 * V_205 ;
int V_140 ;
int V_206 ;
do {
V_140 = 0 ;
V_206 = 0 ;
V_205 = F_186 ( V_2 -> V_8 -> V_160 ) ;
if ( V_205 ) {
V_206 = V_205 -> V_206 ;
V_140 = V_205 -> V_140 ;
if ( V_204 && V_206 > V_2 -> V_169 ) {
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_185 ( V_2 , F_187 ( V_2 -> V_8 ) ) ;
F_43 ( V_3 ) ;
V_205 = NULL ;
V_206 = 0 ;
V_140 = 0 ;
F_9 ( V_2 , V_207 ) ;
}
}
V_140 ++ ;
V_206 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_140 = V_140 ;
V_11 -> V_206 = V_206 ;
V_11 -> V_202 = V_205 ;
} while ( F_188 ( V_2 -> V_8 -> V_160 , V_205 , V_11 )
!= V_205 );
#endif
}
static inline void F_189 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
F_9 ( V_2 , V_208 ) ;
F_184 ( V_2 , V_164 -> V_11 , V_164 -> V_44 ) ;
V_164 -> V_180 = F_173 ( V_164 -> V_180 ) ;
V_164 -> V_11 = NULL ;
V_164 -> V_44 = NULL ;
}
static inline void F_190 ( struct V_1 * V_2 , int V_65 )
{
struct V_163 * V_164 = F_183 ( V_2 -> V_8 , V_65 ) ;
if ( F_103 ( V_164 ) ) {
if ( V_164 -> V_11 )
F_189 ( V_2 , V_164 ) ;
F_185 ( V_2 , V_164 ) ;
}
}
static void F_191 ( void * V_209 )
{
struct V_1 * V_2 = V_209 ;
F_190 ( V_2 , F_52 () ) ;
}
static bool F_192 ( int V_65 , void * V_210 )
{
struct V_1 * V_2 = V_210 ;
struct V_163 * V_164 = F_183 ( V_2 -> V_8 , V_65 ) ;
return V_164 -> V_11 || V_164 -> V_160 ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_194 ( F_192 , F_191 , V_2 , 1 , V_211 ) ;
}
static inline int F_195 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_161
if ( ! V_11 || ( V_10 != V_130 && F_131 ( V_11 ) != V_10 ) )
return 0 ;
#endif
return 1 ;
}
static int F_196 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static inline unsigned long F_197 ( struct V_9 * V_40 )
{
return F_100 ( & V_40 -> V_116 ) ;
}
static unsigned long F_198 ( struct V_9 * V_40 ,
int (* F_199)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_200 ( & V_40 -> V_112 , V_3 ) ;
F_201 (page, &n->partial, lru)
V_29 += F_199 ( V_11 ) ;
F_202 ( & V_40 -> V_112 , V_3 ) ;
return V_29 ;
}
static T_6 void
F_203 ( struct V_1 * V_2 , T_5 V_212 , int V_213 )
{
#ifdef F_2
static F_204 ( V_214 , V_215 ,
V_216 ) ;
int V_10 ;
if ( ( V_212 & V_133 ) || ! F_205 ( & V_214 ) )
return;
F_180 ( L_51 ,
V_213 , V_212 ) ;
F_180 ( L_52 ,
V_2 -> V_46 , V_2 -> V_21 , V_2 -> V_15 , F_26 ( V_2 -> V_128 ) ,
F_26 ( V_2 -> V_136 ) ) ;
if ( F_26 ( V_2 -> V_136 ) > F_206 ( V_2 -> V_21 ) )
F_180 ( L_53 ,
V_2 -> V_46 ) ;
F_207 (node) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
unsigned long V_115 ;
unsigned long V_217 ;
unsigned long V_218 ;
if ( ! V_40 )
continue;
V_218 = F_198 ( V_40 , F_196 ) ;
V_115 = F_101 ( V_40 ) ;
V_217 = F_197 ( V_40 ) ;
F_180 ( L_54 ,
V_10 , V_115 , V_217 , V_218 ) ;
}
#endif
}
static inline void * F_208 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_163 * * V_219 )
{
void * V_44 ;
struct V_163 * V_164 = * V_219 ;
struct V_11 * V_11 ;
V_44 = F_171 ( V_2 , V_3 , V_10 , V_164 ) ;
if ( V_44 )
return V_44 ;
V_11 = F_129 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_164 = F_209 ( V_2 -> V_8 ) ;
if ( V_164 -> V_11 )
F_189 ( V_2 , V_164 ) ;
V_44 = V_11 -> V_44 ;
V_11 -> V_44 = NULL ;
F_9 ( V_2 , V_220 ) ;
V_164 -> V_11 = V_11 ;
* V_219 = V_164 ;
} else
V_44 = NULL ;
return V_44 ;
}
static inline bool F_157 ( struct V_11 * V_11 , T_5 V_212 )
{
if ( F_3 ( F_210 ( V_11 ) ) )
return F_211 ( V_212 ) ;
return true ;
}
static inline void * F_212 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_162 ;
unsigned long V_35 ;
void * V_44 ;
do {
V_44 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
V_162 . V_35 = V_35 ;
F_34 ( ! V_162 . V_36 ) ;
V_162 . V_24 = V_11 -> V_14 ;
V_162 . V_36 = V_44 != NULL ;
} while ( ! F_33 ( V_2 , V_11 ,
V_44 , V_35 ,
NULL , V_162 . V_35 ,
L_55 ) );
return V_44 ;
}
static void * F_213 ( struct V_1 * V_2 , T_5 V_212 , int V_10 ,
unsigned long V_18 , struct V_163 * V_164 )
{
void * V_44 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_42 ( V_3 ) ;
#ifdef F_179
V_164 = F_187 ( V_2 -> V_8 ) ;
#endif
V_11 = V_164 -> V_11 ;
if ( ! V_11 )
goto F_129;
V_196:
if ( F_3 ( ! F_195 ( V_11 , V_10 ) ) ) {
F_9 ( V_2 , V_221 ) ;
F_184 ( V_2 , V_11 , V_164 -> V_44 ) ;
V_164 -> V_11 = NULL ;
V_164 -> V_44 = NULL ;
goto F_129;
}
if ( F_3 ( ! F_157 ( V_11 , V_212 ) ) ) {
F_184 ( V_2 , V_11 , V_164 -> V_44 ) ;
V_164 -> V_11 = NULL ;
V_164 -> V_44 = NULL ;
goto F_129;
}
V_44 = V_164 -> V_44 ;
if ( V_44 )
goto V_222;
V_44 = F_212 ( V_2 , V_11 ) ;
if ( ! V_44 ) {
V_164 -> V_11 = NULL ;
F_9 ( V_2 , V_223 ) ;
goto F_129;
}
F_9 ( V_2 , V_224 ) ;
V_222:
F_34 ( ! V_164 -> V_11 -> V_36 ) ;
V_164 -> V_44 = F_15 ( V_2 , V_44 ) ;
V_164 -> V_180 = F_173 ( V_164 -> V_180 ) ;
F_43 ( V_3 ) ;
return V_44 ;
F_129:
if ( V_164 -> V_160 ) {
V_11 = V_164 -> V_11 = V_164 -> V_160 ;
V_164 -> V_160 = V_11 -> V_202 ;
F_9 ( V_2 , V_225 ) ;
V_164 -> V_44 = NULL ;
goto V_196;
}
V_44 = F_208 ( V_2 , V_212 , V_10 , & V_164 ) ;
if ( F_3 ( ! V_44 ) ) {
F_203 ( V_2 , V_212 , V_10 ) ;
F_43 ( V_3 ) ;
return NULL ;
}
V_11 = V_164 -> V_11 ;
if ( F_103 ( ! F_1 ( V_2 ) && F_157 ( V_11 , V_212 ) ) )
goto V_222;
if ( F_1 ( V_2 ) &&
! F_110 ( V_2 , V_11 , V_44 , V_18 ) )
goto F_129;
F_184 ( V_2 , V_11 , F_15 ( V_2 , V_44 ) ) ;
V_164 -> V_11 = NULL ;
V_164 -> V_44 = NULL ;
F_43 ( V_3 ) ;
return V_44 ;
}
static T_2 void * F_214 ( struct V_1 * V_2 ,
T_5 V_212 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_163 * V_164 ;
struct V_11 * V_11 ;
unsigned long V_180 ;
if ( F_82 ( V_2 , V_212 ) )
return NULL ;
V_2 = F_215 ( V_2 , V_212 ) ;
V_196:
F_216 () ;
V_164 = F_187 ( V_2 -> V_8 ) ;
V_180 = V_164 -> V_180 ;
F_217 () ;
V_12 = V_164 -> V_44 ;
V_11 = V_164 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_195 ( V_11 , V_10 ) ) ) {
V_12 = F_213 ( V_2 , V_212 , V_10 , V_18 , V_164 ) ;
F_9 ( V_2 , V_226 ) ;
} else {
void * V_227 = F_18 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_218 (
V_2 -> V_8 -> V_44 , V_2 -> V_8 -> V_180 ,
V_12 , V_180 ,
V_227 , F_173 ( V_180 ) ) ) ) {
F_177 ( L_56 , V_2 , V_180 ) ;
goto V_196;
}
F_16 ( V_2 , V_227 ) ;
F_9 ( V_2 , V_228 ) ;
}
if ( F_3 ( V_212 & V_229 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_86 ( V_2 , V_212 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_219 ( struct V_1 * V_2 ,
T_5 V_212 , unsigned long V_18 )
{
return F_214 ( V_2 , V_212 , V_130 , V_18 ) ;
}
void * F_220 ( struct V_1 * V_2 , T_5 V_212 )
{
void * V_230 = F_219 ( V_2 , V_212 , V_231 ) ;
F_221 ( V_231 , V_230 , V_2 -> V_21 ,
V_2 -> V_15 , V_212 ) ;
return V_230 ;
}
void * F_222 ( struct V_1 * V_2 , T_5 V_212 , T_1 V_15 )
{
void * V_230 = F_219 ( V_2 , V_212 , V_231 ) ;
F_223 ( V_231 , V_230 , V_15 , V_2 -> V_15 , V_212 ) ;
return V_230 ;
}
void * F_224 ( struct V_1 * V_2 , T_5 V_212 , int V_10 )
{
void * V_230 = F_214 ( V_2 , V_212 , V_10 , V_231 ) ;
F_225 ( V_231 , V_230 ,
V_2 -> V_21 , V_2 -> V_15 , V_212 , V_10 ) ;
return V_230 ;
}
void * F_226 ( struct V_1 * V_2 ,
T_5 V_212 ,
int V_10 , T_1 V_15 )
{
void * V_230 = F_214 ( V_2 , V_212 , V_10 , V_231 ) ;
F_227 ( V_231 , V_230 ,
V_15 , V_2 -> V_15 , V_212 , V_10 ) ;
return V_230 ;
}
static void F_228 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_195 ;
void * * V_12 = ( void * ) V_29 ;
int V_232 ;
struct V_11 V_162 ;
unsigned long V_35 ;
struct V_9 * V_40 = NULL ;
unsigned long V_233 ( V_3 ) ;
F_9 ( V_2 , V_234 ) ;
if ( F_1 ( V_2 ) &&
! ( V_40 = F_114 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_40 ) ) {
F_202 ( & V_40 -> V_112 , V_3 ) ;
V_40 = NULL ;
}
V_195 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
F_21 ( V_2 , V_12 , V_195 ) ;
V_162 . V_35 = V_35 ;
V_232 = V_162 . V_36 ;
V_162 . V_24 -- ;
if ( ( ! V_162 . V_24 || ! V_195 ) && ! V_232 ) {
if ( F_4 ( V_2 ) && ! V_195 ) {
V_162 . V_36 = 1 ;
} else {
V_40 = F_12 ( V_2 , F_131 ( V_11 ) ) ;
F_200 ( & V_40 -> V_112 , V_3 ) ;
}
}
} while ( ! F_41 ( V_2 , V_11 ,
V_195 , V_35 ,
V_12 , V_162 . V_35 ,
L_57 ) );
if ( F_103 ( ! V_40 ) ) {
if ( V_162 . V_36 && ! V_232 ) {
F_158 ( V_2 , V_11 , 1 ) ;
F_9 ( V_2 , V_235 ) ;
}
if ( V_232 )
F_9 ( V_2 , V_236 ) ;
return;
}
if ( F_3 ( ! V_162 . V_24 && V_40 -> V_158 >= V_2 -> V_178 ) )
goto V_237;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_195 ) ) {
if ( F_1 ( V_2 ) )
F_97 ( V_2 , V_40 , V_11 ) ;
F_149 ( V_40 , V_11 , V_159 ) ;
F_9 ( V_2 , V_203 ) ;
}
F_202 ( & V_40 -> V_112 , V_3 ) ;
return;
V_237:
if ( V_195 ) {
F_151 ( V_40 , V_11 ) ;
F_9 ( V_2 , V_238 ) ;
} else {
F_97 ( V_2 , V_40 , V_11 ) ;
}
F_202 ( & V_40 -> V_112 , V_3 ) ;
F_9 ( V_2 , V_199 ) ;
F_146 ( V_2 , V_11 ) ;
}
static T_2 void F_229 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_163 * V_164 ;
unsigned long V_180 ;
F_89 ( V_2 , V_29 ) ;
V_196:
F_216 () ;
V_164 = F_187 ( V_2 -> V_8 ) ;
V_180 = V_164 -> V_180 ;
F_217 () ;
if ( F_103 ( V_11 == V_164 -> V_11 ) ) {
F_21 ( V_2 , V_12 , V_164 -> V_44 ) ;
if ( F_3 ( ! F_218 (
V_2 -> V_8 -> V_44 , V_2 -> V_8 -> V_180 ,
V_164 -> V_44 , V_180 ,
V_12 , F_173 ( V_180 ) ) ) ) {
F_177 ( L_58 , V_2 , V_180 ) ;
goto V_196;
}
F_9 ( V_2 , V_239 ) ;
} else
F_228 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_230 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_231 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_229 ( V_2 , F_142 ( V_29 ) , V_29 , V_231 ) ;
F_232 ( V_231 , V_29 ) ;
}
static inline int F_233 ( int V_15 , int V_240 ,
int V_241 , int V_242 , int V_26 )
{
int V_25 ;
int V_243 ;
int V_244 = V_245 ;
if ( F_24 ( V_244 , V_15 , V_26 ) > V_104 )
return F_206 ( V_15 * V_104 ) - 1 ;
for ( V_25 = F_234 ( V_244 ,
F_235 ( V_240 * V_15 - 1 ) - V_246 ) ;
V_25 <= V_241 ; V_25 ++ ) {
unsigned long V_247 = V_27 << V_25 ;
if ( V_247 < V_240 * V_15 + V_26 )
continue;
V_243 = ( V_247 - V_26 ) % V_15 ;
if ( V_243 <= V_247 / V_242 )
break;
}
return V_25 ;
}
static inline int F_236 ( int V_15 , int V_26 )
{
int V_25 ;
int V_240 ;
int V_248 ;
int V_103 ;
V_240 = V_249 ;
if ( ! V_240 )
V_240 = 4 * ( F_235 ( V_250 ) + 1 ) ;
V_103 = F_24 ( V_251 , V_15 , V_26 ) ;
V_240 = V_136 ( V_240 , V_103 ) ;
while ( V_240 > 1 ) {
V_248 = 16 ;
while ( V_248 >= 4 ) {
V_25 = F_233 ( V_15 , V_240 ,
V_251 , V_248 , V_26 ) ;
if ( V_25 <= V_251 )
return V_25 ;
V_248 /= 2 ;
}
V_240 -- ;
}
V_25 = F_233 ( V_15 , 1 , V_251 , 1 , V_26 ) ;
if ( V_25 <= V_251 )
return V_25 ;
V_25 = F_233 ( V_15 , 1 , V_252 , 1 , V_26 ) ;
if ( V_25 < V_252 )
return V_25 ;
return - V_253 ;
}
static void
F_237 ( struct V_9 * V_40 )
{
V_40 -> V_158 = 0 ;
F_238 ( & V_40 -> V_112 ) ;
F_239 ( & V_40 -> V_160 ) ;
#ifdef F_2
F_240 ( & V_40 -> V_115 , 0 ) ;
F_240 ( & V_40 -> V_116 , 0 ) ;
F_239 ( & V_40 -> V_114 ) ;
#endif
}
static inline int F_241 ( struct V_1 * V_2 )
{
F_242 ( V_254 <
V_255 * sizeof( struct V_163 ) ) ;
V_2 -> V_8 = F_243 ( sizeof( struct V_163 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_181 ( V_2 ) ;
return 1 ;
}
static void F_244 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_40 ;
F_130 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_129 ( V_9 , V_256 , V_10 ) ;
F_130 ( ! V_11 ) ;
if ( F_131 ( V_11 ) != V_10 ) {
F_55 ( L_59 , V_10 ) ;
F_55 ( L_60 ) ;
}
V_40 = V_11 -> V_44 ;
F_130 ( ! V_40 ) ;
V_11 -> V_44 = F_15 ( V_9 , V_40 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_36 = 0 ;
V_9 -> V_10 [ V_10 ] = V_40 ;
#ifdef F_2
F_67 ( V_9 , V_40 , V_99 ) ;
F_53 ( V_9 , V_40 ) ;
#endif
F_237 ( V_40 ) ;
F_102 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_147 ( V_40 , V_11 , V_192 ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
int V_10 ;
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = V_2 -> V_10 [ V_10 ] ;
if ( V_40 )
F_230 ( V_9 , V_40 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_247 ( struct V_1 * V_2 )
{
int V_10 ;
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 ;
if ( V_257 == V_258 ) {
F_244 ( V_10 ) ;
continue;
}
V_40 = F_224 ( V_9 ,
V_259 , V_10 ) ;
if ( ! V_40 ) {
F_245 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_40 ;
F_237 ( V_40 ) ;
}
return 1 ;
}
static void F_248 ( struct V_1 * V_2 , unsigned long V_136 )
{
if ( V_136 < V_260 )
V_136 = V_260 ;
else if ( V_136 > V_261 )
V_136 = V_261 ;
V_2 -> V_178 = V_136 ;
}
static int F_249 ( struct V_1 * V_2 , int V_262 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_250 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_113 )
V_2 -> V_3 |= V_83 ;
else
V_2 -> V_3 &= ~ V_83 ;
if ( ( V_3 & V_19 ) && V_15 == V_2 -> V_21 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_24 = V_15 ;
if ( ( ( V_3 & ( V_22 | V_20 ) ) ||
V_2 -> F_113 ) ) {
V_2 -> V_16 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_23 )
V_15 += 2 * sizeof( struct V_52 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_15 = F_250 ( V_15 , V_2 -> V_263 ) ;
V_2 -> V_15 = V_15 ;
if ( V_262 >= 0 )
V_25 = V_262 ;
else
V_25 = F_236 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_132 = 0 ;
if ( V_25 )
V_2 -> V_132 |= V_264 ;
if ( V_2 -> V_3 & V_265 )
V_2 -> V_132 |= V_266 ;
if ( V_2 -> V_3 & V_141 )
V_2 -> V_132 |= V_267 ;
V_2 -> V_128 = F_25 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_136 = F_25 ( F_206 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_27 ( V_2 -> V_128 ) > F_27 ( V_2 -> F_234 ) )
V_2 -> F_234 = V_2 -> V_128 ;
return ! ! F_27 ( V_2 -> V_128 ) ;
}
static int F_251 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_112 ( V_2 -> V_15 , V_3 , V_2 -> V_46 , V_2 -> F_113 ) ;
V_2 -> V_26 = 0 ;
if ( V_154 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_152 ) ;
if ( ! F_249 ( V_2 , - 1 ) )
goto error;
if ( V_124 ) {
if ( F_206 ( V_2 -> V_15 ) > F_206 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_268 ;
V_2 -> V_16 = 0 ;
if ( ! F_249 ( V_2 , - 1 ) )
goto error;
}
}
#if F_36 ( V_41 ) && \
F_36 ( V_42 )
if ( F_252 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_43 ;
#endif
F_248 ( V_2 , F_253 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_4 ( V_2 ) )
V_2 -> V_169 = 0 ;
else if ( V_2 -> V_15 >= V_27 )
V_2 -> V_169 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_169 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_169 = 13 ;
else
V_2 -> V_169 = 30 ;
#ifdef F_161
V_2 -> V_177 = 1000 ;
#endif
if ( ! F_247 ( V_2 ) )
goto error;
if ( F_241 ( V_2 ) )
return 0 ;
F_245 ( V_2 ) ;
error:
if ( V_3 & V_269 )
F_254 ( L_61
L_62 ,
V_2 -> V_46 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_26 ( V_2 -> V_128 ) , V_2 -> V_16 , V_3 ) ;
return - V_270 ;
}
static void F_255 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_48 )
{
#ifdef F_2
void * V_18 = F_14 ( V_11 ) ;
void * V_5 ;
unsigned long * V_47 = F_256 ( F_257 ( V_11 -> V_14 ) *
sizeof( long ) , V_211 ) ;
if ( ! V_47 )
return;
F_66 ( V_2 , V_11 , V_48 , V_2 -> V_46 ) ;
F_28 ( V_11 ) ;
F_44 ( V_2 , V_11 , V_47 ) ;
F_134 (p, s, addr, page->objects) {
if ( ! F_258 ( F_22 ( V_5 , V_2 , V_18 ) , V_47 ) ) {
F_55 ( L_63 , V_5 , V_5 - V_18 ) ;
F_56 ( V_2 , V_5 ) ;
}
}
F_30 ( V_11 ) ;
F_259 ( V_47 ) ;
#endif
}
static void F_260 ( struct V_1 * V_2 , struct V_9 * V_40 )
{
struct V_11 * V_11 , * V_153 ;
F_156 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_150 ( V_40 , V_11 ) ;
F_146 ( V_2 , V_11 ) ;
} else {
F_255 ( V_2 , V_11 ,
L_64 ) ;
}
}
}
static inline int F_261 ( struct V_1 * V_2 )
{
int V_10 ;
F_193 ( V_2 ) ;
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
F_260 ( V_2 , V_40 ) ;
if ( V_40 -> V_158 || F_99 ( V_2 , V_10 ) )
return 1 ;
}
F_262 ( V_2 -> V_8 ) ;
F_245 ( V_2 ) ;
return 0 ;
}
int F_263 ( struct V_1 * V_2 )
{
return F_261 ( V_2 ) ;
}
static int T_7 F_264 ( char * V_119 )
{
F_265 ( & V_119 , & V_245 ) ;
return 1 ;
}
static int T_7 F_266 ( char * V_119 )
{
F_265 ( & V_119 , & V_251 ) ;
V_251 = V_136 ( V_251 , V_252 - 1 ) ;
return 1 ;
}
static int T_7 F_267 ( char * V_119 )
{
F_265 ( & V_119 , & V_249 ) ;
return 1 ;
}
static int T_7 F_268 ( char * V_119 )
{
V_271 = 1 ;
return 1 ;
}
void * F_269 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_15 > V_272 ) )
return F_270 ( V_15 , V_3 ) ;
V_2 = F_271 ( V_15 , V_3 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_230 = F_219 ( V_2 , V_3 , V_231 ) ;
F_223 ( V_231 , V_230 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_230 ;
}
static void * F_273 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_106 = NULL ;
V_3 |= V_264 | V_129 ;
V_11 = F_274 ( V_10 , V_3 , F_206 ( V_15 ) ) ;
if ( V_11 )
V_106 = F_14 ( V_11 ) ;
F_78 ( V_106 , V_15 , V_3 ) ;
return V_106 ;
}
void * F_275 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_15 > V_272 ) ) {
V_230 = F_273 ( V_15 , V_3 , V_10 ) ;
F_227 ( V_231 , V_230 ,
V_15 , V_27 << F_206 ( V_15 ) ,
V_3 , V_10 ) ;
return V_230 ;
}
V_2 = F_271 ( V_15 , V_3 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_230 = F_214 ( V_2 , V_3 , V_10 , V_231 ) ;
F_227 ( V_231 , V_230 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_230 ;
}
T_1 F_276 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_273 ) )
return 0 ;
V_11 = F_142 ( V_12 ) ;
if ( F_3 ( ! F_76 ( V_11 ) ) ) {
F_153 ( ! F_277 ( V_11 ) ) ;
return V_27 << F_73 ( V_11 ) ;
}
return F_23 ( V_11 -> V_148 ) ;
}
void F_259 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_278 ( V_231 , V_29 ) ;
if ( F_3 ( F_272 ( V_29 ) ) )
return;
V_11 = F_142 ( V_29 ) ;
if ( F_3 ( ! F_76 ( V_11 ) ) ) {
F_130 ( ! F_277 ( V_11 ) ) ;
F_80 ( V_29 ) ;
F_279 ( V_11 , F_73 ( V_11 ) ) ;
return;
}
F_229 ( V_11 -> V_148 , V_11 , V_12 , V_231 ) ;
}
int F_280 ( struct V_1 * V_2 )
{
int V_10 ;
int V_57 ;
struct V_9 * V_40 ;
struct V_11 * V_11 ;
struct V_11 * V_72 ;
int V_14 = F_27 ( V_2 -> F_234 ) ;
struct V_155 * V_274 =
F_281 ( sizeof( struct V_155 ) * V_14 , V_259 ) ;
unsigned long V_3 ;
if ( ! V_274 )
return - V_275 ;
F_193 ( V_2 ) ;
F_246 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_10 ) ;
if ( ! V_40 -> V_158 )
continue;
for ( V_57 = 0 ; V_57 < V_14 ; V_57 ++ )
F_239 ( V_274 + V_57 ) ;
F_200 ( & V_40 -> V_112 , V_3 ) ;
F_156 (page, t, &n->partial, lru) {
F_282 ( & V_11 -> V_113 , V_274 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_40 -> V_158 -- ;
}
for ( V_57 = V_14 - 1 ; V_57 > 0 ; V_57 -- )
F_283 ( V_274 + V_57 , V_40 -> V_160 . V_276 ) ;
F_202 ( & V_40 -> V_112 , V_3 ) ;
F_156 (page, t, slabs_by_inuse, lru)
F_146 ( V_2 , V_11 ) ;
}
F_259 ( V_274 ) ;
return 0 ;
}
static int F_284 ( void * V_277 )
{
struct V_1 * V_2 ;
F_285 ( & V_278 ) ;
F_201 (s, &slab_caches, list)
F_280 ( V_2 ) ;
F_286 ( & V_278 ) ;
return 0 ;
}
static void F_287 ( void * V_277 )
{
struct V_9 * V_40 ;
struct V_1 * V_2 ;
struct V_279 * V_280 = V_277 ;
int V_281 ;
V_281 = V_280 -> V_282 ;
if ( V_281 < 0 )
return;
F_285 ( & V_278 ) ;
F_201 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_281 ) ;
if ( V_40 ) {
F_130 ( F_99 ( V_2 , V_281 ) ) ;
V_2 -> V_10 [ V_281 ] = NULL ;
F_230 ( V_9 , V_40 ) ;
}
}
F_286 ( & V_278 ) ;
}
static int F_288 ( void * V_277 )
{
struct V_9 * V_40 ;
struct V_1 * V_2 ;
struct V_279 * V_280 = V_277 ;
int V_213 = V_280 -> V_282 ;
int V_230 = 0 ;
if ( V_213 < 0 )
return 0 ;
F_285 ( & V_278 ) ;
F_201 (s, &slab_caches, list) {
V_40 = F_220 ( V_9 , V_259 ) ;
if ( ! V_40 ) {
V_230 = - V_275 ;
goto V_122;
}
F_237 ( V_40 ) ;
V_2 -> V_10 [ V_213 ] = V_40 ;
}
V_122:
F_286 ( & V_278 ) ;
return V_230 ;
}
static int F_289 ( struct V_283 * V_284 ,
unsigned long V_285 , void * V_277 )
{
int V_230 = 0 ;
switch ( V_285 ) {
case V_286 :
V_230 = F_288 ( V_277 ) ;
break;
case V_287 :
V_230 = F_284 ( V_277 ) ;
break;
case V_288 :
case V_289 :
F_287 ( V_277 ) ;
break;
case V_290 :
case V_291 :
break;
}
if ( V_230 )
V_230 = F_290 ( V_230 ) ;
else
V_230 = V_292 ;
return V_230 ;
}
static struct V_1 * T_7 F_291 ( struct V_1 * V_293 )
{
int V_10 ;
struct V_1 * V_2 = F_292 ( V_1 , V_256 ) ;
memcpy ( V_2 , V_293 , V_1 -> V_21 ) ;
F_190 ( V_2 , F_52 () ) ;
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_40 ) {
F_201 (p, &n->partial, lru)
V_5 -> V_148 = V_2 ;
#ifdef F_2
F_201 (p, &n->full, lru)
V_5 -> V_148 = V_2 ;
#endif
}
}
F_96 ( & V_2 -> V_294 , & V_295 ) ;
return V_2 ;
}
void T_7 F_293 ( void )
{
static V_296 struct V_1 V_297 ,
V_298 ;
if ( F_294 () )
V_251 = 0 ;
V_9 = & V_298 ;
V_1 = & V_297 ;
F_295 ( V_9 , L_65 ,
sizeof( struct V_9 ) , V_299 ) ;
F_296 ( & V_300 ) ;
V_257 = V_301 ;
F_295 ( V_1 , L_66 ,
F_297 ( struct V_1 , V_10 ) +
V_302 * sizeof( struct V_9 * ) ,
V_299 ) ;
V_1 = F_291 ( & V_297 ) ;
V_9 = F_291 ( & V_298 ) ;
F_298 ( 0 ) ;
#ifdef F_299
F_300 ( & V_303 ) ;
#endif
F_40 ( L_67 ,
F_301 () ,
V_245 , V_251 , V_249 ,
V_250 , V_302 ) ;
}
void T_7 F_302 ( void )
{
}
static int F_303 ( struct V_1 * V_2 )
{
if ( V_271 || ( V_2 -> V_3 & V_304 ) )
return 1 ;
if ( ! F_304 ( V_2 ) )
return 1 ;
if ( V_2 -> F_113 )
return 1 ;
if ( V_2 -> V_305 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_305 ( T_1 V_15 , T_1 V_263 ,
unsigned long V_3 , const char * V_46 , void (* F_113)( void * ) )
{
struct V_1 * V_2 ;
if ( V_271 || ( V_3 & V_304 ) )
return NULL ;
if ( F_113 )
return NULL ;
V_15 = F_250 ( V_15 , sizeof( void * ) ) ;
V_263 = F_306 ( V_3 , V_263 , V_15 ) ;
V_15 = F_250 ( V_15 , V_263 ) ;
V_3 = F_112 ( V_15 , V_3 , V_46 , NULL ) ;
F_201 (s, &slab_caches, list) {
if ( F_303 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_306 ) != ( V_2 -> V_3 & V_306 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_263 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_307 ( const char * V_46 , T_1 V_15 , T_1 V_263 ,
unsigned long V_3 , void (* F_113)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_305 ( V_15 , V_263 , V_3 , V_46 , F_113 ) ;
if ( V_2 ) {
int V_57 ;
struct V_1 * V_164 ;
V_2 -> V_305 ++ ;
V_2 -> V_21 = F_234 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_308 ( int , V_2 -> V_24 , F_250 ( V_15 , sizeof( void * ) ) ) ;
F_309 (i) {
V_164 = F_310 ( V_2 , V_57 ) ;
if ( ! V_164 )
continue;
V_164 -> V_21 = V_2 -> V_21 ;
V_164 -> V_24 = F_308 ( int , V_164 -> V_24 ,
F_250 ( V_15 , sizeof( void * ) ) ) ;
}
if ( F_7 ( V_2 , V_46 ) ) {
V_2 -> V_305 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_311 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_307 ;
V_307 = F_251 ( V_2 , V_3 ) ;
if ( V_307 )
return V_307 ;
if ( V_257 <= V_308 )
return 0 ;
F_8 ( V_2 ) ;
V_307 = F_6 ( V_2 ) ;
if ( V_307 )
F_261 ( V_2 ) ;
return V_307 ;
}
static int F_312 ( struct V_283 * V_309 ,
unsigned long V_285 , void * V_310 )
{
long V_65 = ( long ) V_310 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_285 ) {
case V_311 :
case V_312 :
case V_313 :
case V_314 :
F_285 ( & V_278 ) ;
F_201 (s, &slab_caches, list) {
F_42 ( V_3 ) ;
F_190 ( V_2 , V_65 ) ;
F_43 ( V_3 ) ;
}
F_286 ( & V_278 ) ;
break;
default:
break;
}
return V_292 ;
}
void * F_313 ( T_1 V_15 , T_5 V_212 , unsigned long V_315 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_15 > V_272 ) )
return F_270 ( V_15 , V_212 ) ;
V_2 = F_271 ( V_15 , V_212 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_230 = F_219 ( V_2 , V_212 , V_315 ) ;
F_223 ( V_315 , V_230 , V_15 , V_2 -> V_15 , V_212 ) ;
return V_230 ;
}
void * F_314 ( T_1 V_15 , T_5 V_212 ,
int V_10 , unsigned long V_315 )
{
struct V_1 * V_2 ;
void * V_230 ;
if ( F_3 ( V_15 > V_272 ) ) {
V_230 = F_273 ( V_15 , V_212 , V_10 ) ;
F_227 ( V_315 , V_230 ,
V_15 , V_27 << F_206 ( V_15 ) ,
V_212 , V_10 ) ;
return V_230 ;
}
V_2 = F_271 ( V_15 , V_212 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_230 = F_214 ( V_2 , V_212 , V_10 , V_315 ) ;
F_227 ( V_315 , V_230 , V_15 , V_2 -> V_15 , V_212 , V_10 ) ;
return V_230 ;
}
static int F_315 ( struct V_11 * V_11 )
{
return V_11 -> V_24 ;
}
static int F_316 ( struct V_11 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_317 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_47 )
{
void * V_5 ;
void * V_18 = F_14 ( V_11 ) ;
if ( ! F_75 ( V_2 , V_11 ) ||
! F_77 ( V_2 , V_11 , NULL ) )
return 0 ;
F_318 ( V_47 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_47 ) ;
F_134 (p, s, addr, page->objects) {
if ( F_258 ( F_22 ( V_5 , V_2 , V_18 ) , V_47 ) )
if ( ! F_74 ( V_2 , V_11 , V_5 , V_117 ) )
return 0 ;
}
F_134 (p, s, addr, page->objects)
if ( ! F_258 ( F_22 ( V_5 , V_2 , V_18 ) , V_47 ) )
if ( ! F_74 ( V_2 , V_11 , V_5 , V_99 ) )
return 0 ;
return 1 ;
}
static void F_319 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_47 )
{
F_28 ( V_11 ) ;
F_317 ( V_2 , V_11 , V_47 ) ;
F_30 ( V_11 ) ;
}
static int F_320 ( struct V_1 * V_2 ,
struct V_9 * V_40 , unsigned long * V_47 )
{
unsigned long V_316 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_200 ( & V_40 -> V_112 , V_3 ) ;
F_201 (page, &n->partial, lru) {
F_319 ( V_2 , V_11 , V_47 ) ;
V_316 ++ ;
}
if ( V_316 != V_40 -> V_158 )
F_55 ( L_68 ,
V_2 -> V_46 , V_316 , V_40 -> V_158 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_122;
F_201 (page, &n->full, lru) {
F_319 ( V_2 , V_11 , V_47 ) ;
V_316 ++ ;
}
if ( V_316 != F_100 ( & V_40 -> V_115 ) )
F_55 ( L_69 ,
V_2 -> V_46 , V_316 , F_100 ( & V_40 -> V_115 ) ) ;
V_122:
F_202 ( & V_40 -> V_112 , V_3 ) ;
return V_316 ;
}
static long F_321 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_316 = 0 ;
unsigned long * V_47 = F_281 ( F_257 ( F_27 ( V_2 -> F_234 ) ) *
sizeof( unsigned long ) , V_259 ) ;
if ( ! V_47 )
return - V_275 ;
F_193 ( V_2 ) ;
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
V_316 += F_320 ( V_2 , V_40 , V_47 ) ;
}
F_259 ( V_47 ) ;
return V_316 ;
}
static void F_322 ( struct V_317 * V_72 )
{
if ( V_72 -> F_234 )
F_323 ( ( unsigned long ) V_72 -> V_318 ,
F_206 ( sizeof( struct V_319 ) * V_72 -> F_234 ) ) ;
}
static int F_324 ( struct V_317 * V_72 , unsigned long F_234 , T_5 V_3 )
{
struct V_319 * V_189 ;
int V_25 ;
V_25 = F_206 ( sizeof( struct V_319 ) * F_234 ) ;
V_189 = ( void * ) F_325 ( V_3 , V_25 ) ;
if ( ! V_189 )
return 0 ;
if ( V_72 -> V_316 ) {
memcpy ( V_189 , V_72 -> V_318 , sizeof( struct V_319 ) * V_72 -> V_316 ) ;
F_322 ( V_72 ) ;
}
V_72 -> F_234 = F_234 ;
V_72 -> V_318 = V_189 ;
return 1 ;
}
static int F_326 ( struct V_317 * V_72 , struct V_1 * V_2 ,
const struct V_52 * V_52 )
{
long V_91 , V_95 , V_320 ;
struct V_319 * V_189 ;
unsigned long V_321 ;
unsigned long V_322 = V_69 - V_52 -> V_68 ;
V_91 = - 1 ;
V_95 = V_72 -> V_316 ;
for ( ; ; ) {
V_320 = V_91 + ( V_95 - V_91 + 1 ) / 2 ;
if ( V_320 == V_95 )
break;
V_321 = V_72 -> V_318 [ V_320 ] . V_18 ;
if ( V_52 -> V_18 == V_321 ) {
V_189 = & V_72 -> V_318 [ V_320 ] ;
V_189 -> V_316 ++ ;
if ( V_52 -> V_68 ) {
V_189 -> V_323 += V_322 ;
if ( V_322 < V_189 -> V_324 )
V_189 -> V_324 = V_322 ;
if ( V_322 > V_189 -> V_325 )
V_189 -> V_325 = V_322 ;
if ( V_52 -> V_66 < V_189 -> V_326 )
V_189 -> V_326 = V_52 -> V_66 ;
if ( V_52 -> V_66 > V_189 -> V_327 )
V_189 -> V_327 = V_52 -> V_66 ;
F_327 ( V_52 -> V_65 ,
F_328 ( V_189 -> V_328 ) ) ;
}
F_329 ( F_131 ( F_330 ( V_52 ) ) , V_189 -> V_329 ) ;
return 1 ;
}
if ( V_52 -> V_18 < V_321 )
V_95 = V_320 ;
else
V_91 = V_320 ;
}
if ( V_72 -> V_316 >= V_72 -> F_234 && ! F_324 ( V_72 , 2 * V_72 -> F_234 , V_211 ) )
return 0 ;
V_189 = V_72 -> V_318 + V_320 ;
if ( V_320 < V_72 -> V_316 )
memmove ( V_189 + 1 , V_189 ,
( V_72 -> V_316 - V_320 ) * sizeof( struct V_319 ) ) ;
V_72 -> V_316 ++ ;
V_189 -> V_316 = 1 ;
V_189 -> V_18 = V_52 -> V_18 ;
V_189 -> V_323 = V_322 ;
V_189 -> V_324 = V_322 ;
V_189 -> V_325 = V_322 ;
V_189 -> V_326 = V_52 -> V_66 ;
V_189 -> V_327 = V_52 -> V_66 ;
F_331 ( F_328 ( V_189 -> V_328 ) ) ;
F_327 ( V_52 -> V_65 , F_328 ( V_189 -> V_328 ) ) ;
F_332 ( V_189 -> V_329 ) ;
F_329 ( F_131 ( F_330 ( V_52 ) ) , V_189 -> V_329 ) ;
return 1 ;
}
static void F_333 ( struct V_317 * V_72 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_53 V_54 ,
unsigned long * V_47 )
{
void * V_18 = F_14 ( V_11 ) ;
void * V_5 ;
F_318 ( V_47 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_47 ) ;
F_134 (p, s, addr, page->objects)
if ( ! F_258 ( F_22 ( V_5 , V_2 , V_18 ) , V_47 ) )
F_326 ( V_72 , V_2 , F_48 ( V_2 , V_5 , V_54 ) ) ;
}
static int F_334 ( struct V_1 * V_2 , char * V_81 ,
enum V_53 V_54 )
{
int V_330 = 0 ;
unsigned long V_57 ;
struct V_317 V_72 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_47 = F_281 ( F_257 ( F_27 ( V_2 -> F_234 ) ) *
sizeof( unsigned long ) , V_259 ) ;
if ( ! V_47 || ! F_324 ( & V_72 , V_27 / sizeof( struct V_319 ) ,
V_331 ) ) {
F_259 ( V_47 ) ;
return sprintf ( V_81 , L_70 ) ;
}
F_193 ( V_2 ) ;
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_100 ( & V_40 -> V_115 ) )
continue;
F_200 ( & V_40 -> V_112 , V_3 ) ;
F_201 (page, &n->partial, lru)
F_333 ( & V_72 , V_2 , V_11 , V_54 , V_47 ) ;
F_201 (page, &n->full, lru)
F_333 ( & V_72 , V_2 , V_11 , V_54 , V_47 ) ;
F_202 ( & V_40 -> V_112 , V_3 ) ;
}
for ( V_57 = 0 ; V_57 < V_72 . V_316 ; V_57 ++ ) {
struct V_319 * V_189 = & V_72 . V_318 [ V_57 ] ;
if ( V_330 > V_27 - V_332 - 100 )
break;
V_330 += sprintf ( V_81 + V_330 , L_71 , V_189 -> V_316 ) ;
if ( V_189 -> V_18 )
V_330 += sprintf ( V_81 + V_330 , L_72 , ( void * ) V_189 -> V_18 ) ;
else
V_330 += sprintf ( V_81 + V_330 , L_73 ) ;
if ( V_189 -> V_323 != V_189 -> V_324 ) {
V_330 += sprintf ( V_81 + V_330 , L_74 ,
V_189 -> V_324 ,
( long ) F_335 ( V_189 -> V_323 , V_189 -> V_316 ) ,
V_189 -> V_325 ) ;
} else
V_330 += sprintf ( V_81 + V_330 , L_75 ,
V_189 -> V_324 ) ;
if ( V_189 -> V_326 != V_189 -> V_327 )
V_330 += sprintf ( V_81 + V_330 , L_76 ,
V_189 -> V_326 , V_189 -> V_327 ) ;
else
V_330 += sprintf ( V_81 + V_330 , L_77 ,
V_189 -> V_326 ) ;
if ( F_336 () > 1 &&
! F_337 ( F_328 ( V_189 -> V_328 ) ) &&
V_330 < V_27 - 60 ) {
V_330 += sprintf ( V_81 + V_330 , L_78 ) ;
V_330 += F_338 ( V_81 + V_330 ,
V_27 - V_330 - 50 ,
F_328 ( V_189 -> V_328 ) ) ;
}
if ( V_333 > 1 && ! F_339 ( V_189 -> V_329 ) &&
V_330 < V_27 - 60 ) {
V_330 += sprintf ( V_81 + V_330 , L_79 ) ;
V_330 += F_340 ( V_81 + V_330 ,
V_27 - V_330 - 50 ,
V_189 -> V_329 ) ;
}
V_330 += sprintf ( V_81 + V_330 , L_80 ) ;
}
F_322 ( & V_72 ) ;
F_259 ( V_47 ) ;
if ( ! V_72 . V_316 )
V_330 += sprintf ( V_81 , L_81 ) ;
return V_330 ;
}
static void F_341 ( void )
{
T_3 * V_5 ;
F_242 ( V_334 > 16 || V_255 < 10 ) ;
F_55 ( L_82 ) ;
F_55 ( L_83 ) ;
F_55 ( L_84 ) ;
V_5 = F_256 ( 16 , V_259 ) ;
V_5 [ 16 ] = 0x12 ;
F_55 ( L_85 ,
V_5 + 16 ) ;
F_321 ( V_335 [ 4 ] ) ;
V_5 = F_256 ( 32 , V_259 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_55 ( L_86 ,
V_5 ) ;
F_55 ( L_87 ) ;
F_321 ( V_335 [ 5 ] ) ;
V_5 = F_256 ( 64 , V_259 ) ;
V_5 += 64 + ( F_163 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_55 ( L_88 ,
V_5 ) ;
F_55 ( L_87 ) ;
F_321 ( V_335 [ 6 ] ) ;
F_55 ( L_89 ) ;
V_5 = F_256 ( 128 , V_259 ) ;
F_259 ( V_5 ) ;
* V_5 = 0x78 ;
F_55 ( L_90 , V_5 ) ;
F_321 ( V_335 [ 7 ] ) ;
V_5 = F_256 ( 256 , V_259 ) ;
F_259 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_55 ( L_91 , V_5 ) ;
F_321 ( V_335 [ 8 ] ) ;
V_5 = F_256 ( 512 , V_259 ) ;
F_259 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_55 ( L_92 , V_5 ) ;
F_321 ( V_335 [ 9 ] ) ;
}
static void F_341 ( void ) {}
static T_9 F_342 ( struct V_1 * V_2 ,
char * V_81 , unsigned long V_3 )
{
unsigned long V_336 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_329 ;
V_329 = F_256 ( sizeof( unsigned long ) * V_302 , V_259 ) ;
if ( ! V_329 )
return - V_275 ;
if ( V_3 & V_337 ) {
int V_65 ;
F_182 (cpu) {
struct V_163 * V_164 = F_183 ( V_2 -> V_8 ,
V_65 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_343 ( V_164 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_131 ( V_11 ) ;
if ( V_3 & V_338 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_339 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
V_11 = F_343 ( V_164 -> V_160 ) ;
if ( V_11 ) {
V_10 = F_131 ( V_11 ) ;
if ( V_3 & V_338 )
F_344 ( 1 ) ;
else if ( V_3 & V_339 )
F_344 ( 1 ) ;
else
V_29 = V_11 -> V_140 ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
}
}
}
F_345 () ;
#ifdef F_2
if ( V_3 & V_340 ) {
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( V_3 & V_338 )
V_29 = F_100 ( & V_40 -> V_116 ) ;
else if ( V_3 & V_339 )
V_29 = F_100 ( & V_40 -> V_116 ) -
F_198 ( V_40 , F_196 ) ;
else
V_29 = F_100 ( & V_40 -> V_115 ) ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_341 ) {
F_246 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( V_3 & V_338 )
V_29 = F_198 ( V_40 , F_316 ) ;
else if ( V_3 & V_339 )
V_29 = F_198 ( V_40 , F_315 ) ;
else
V_29 = V_40 -> V_158 ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_81 , L_93 , V_336 ) ;
#ifdef F_161
F_246 (node, N_NORMAL_MEMORY)
if ( V_329 [ V_10 ] )
V_29 += sprintf ( V_81 + V_29 , L_94 ,
V_10 , V_329 [ V_10 ] ) ;
#endif
F_346 () ;
F_259 ( V_329 ) ;
return V_29 + sprintf ( V_81 + V_29 , L_80 ) ;
}
static int F_347 ( struct V_1 * V_2 )
{
int V_10 ;
F_207 (node) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( ! V_40 )
continue;
if ( F_100 ( & V_40 -> V_116 ) )
return 1 ;
}
return 0 ;
}
static T_9 F_348 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , V_2 -> V_15 ) ;
}
static T_9 F_349 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , V_2 -> V_263 ) ;
}
static T_9 F_350 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , V_2 -> V_21 ) ;
}
static T_9 F_351 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , F_27 ( V_2 -> V_128 ) ) ;
}
static T_9 F_352 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
unsigned long V_25 ;
int V_307 ;
V_307 = F_353 ( V_81 , 10 , & V_25 ) ;
if ( V_307 )
return V_307 ;
if ( V_25 > V_251 || V_25 < V_245 )
return - V_270 ;
F_249 ( V_2 , V_25 ) ;
return V_49 ;
}
static T_9 F_354 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , F_26 ( V_2 -> V_128 ) ) ;
}
static T_9 F_355 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_96 , V_2 -> V_178 ) ;
}
static T_9 F_356 ( struct V_1 * V_2 , const char * V_81 ,
T_1 V_49 )
{
unsigned long V_136 ;
int V_307 ;
V_307 = F_353 ( V_81 , 10 , & V_136 ) ;
if ( V_307 )
return V_307 ;
F_248 ( V_2 , V_136 ) ;
return V_49 ;
}
static T_9 F_357 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_97 , V_2 -> V_169 ) ;
}
static T_9 F_358 ( struct V_1 * V_2 , const char * V_81 ,
T_1 V_49 )
{
unsigned long V_14 ;
int V_307 ;
V_307 = F_353 ( V_81 , 10 , & V_14 ) ;
if ( V_307 )
return V_307 ;
if ( V_14 && ! F_4 ( V_2 ) )
return - V_270 ;
V_2 -> V_169 = V_14 ;
F_193 ( V_2 ) ;
return V_49 ;
}
static T_9 F_359 ( struct V_1 * V_2 , char * V_81 )
{
if ( ! V_2 -> F_113 )
return 0 ;
return sprintf ( V_81 , L_98 , V_2 -> F_113 ) ;
}
static T_9 F_360 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , V_2 -> V_305 - 1 ) ;
}
static T_9 F_361 ( struct V_1 * V_2 , char * V_81 )
{
return F_342 ( V_2 , V_81 , V_341 ) ;
}
static T_9 F_362 ( struct V_1 * V_2 , char * V_81 )
{
return F_342 ( V_2 , V_81 , V_337 ) ;
}
static T_9 F_363 ( struct V_1 * V_2 , char * V_81 )
{
return F_342 ( V_2 , V_81 , V_340 | V_339 ) ;
}
static T_9 F_364 ( struct V_1 * V_2 , char * V_81 )
{
return F_342 ( V_2 , V_81 , V_341 | V_339 ) ;
}
static T_9 F_365 ( struct V_1 * V_2 , char * V_81 )
{
int V_14 = 0 ;
int V_140 = 0 ;
int V_65 ;
int V_330 ;
F_366 (cpu) {
struct V_11 * V_11 = F_183 ( V_2 -> V_8 , V_65 ) -> V_160 ;
if ( V_11 ) {
V_140 += V_11 -> V_140 ;
V_14 += V_11 -> V_206 ;
}
}
V_330 = sprintf ( V_81 , L_99 , V_14 , V_140 ) ;
#ifdef F_299
F_366 (cpu) {
struct V_11 * V_11 = F_183 ( V_2 -> V_8 , V_65 ) -> V_160 ;
if ( V_11 && V_330 < V_27 - 20 )
V_330 += sprintf ( V_81 + V_330 , L_100 , V_65 ,
V_11 -> V_206 , V_11 -> V_140 ) ;
}
#endif
return V_330 + sprintf ( V_81 + V_330 , L_80 ) ;
}
static T_9 F_367 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_141 ) ) ;
}
static T_9 F_368 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
V_2 -> V_3 &= ~ V_141 ;
if ( V_81 [ 0 ] == '1' )
V_2 -> V_3 |= V_141 ;
return V_49 ;
}
static T_9 F_369 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_299 ) ) ;
}
static T_9 F_370 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_265 ) ) ;
}
static T_9 F_371 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_9 F_372 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , V_2 -> V_26 ) ;
}
static T_9 F_373 ( struct V_1 * V_2 , char * V_81 )
{
return F_342 ( V_2 , V_81 , V_340 ) ;
}
static T_9 F_374 ( struct V_1 * V_2 , char * V_81 )
{
return F_342 ( V_2 , V_81 , V_340 | V_338 ) ;
}
static T_9 F_375 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_125 ) ) ;
}
static T_9 F_376 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
V_2 -> V_3 &= ~ V_125 ;
if ( V_81 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_125 ;
}
return V_49 ;
}
static T_9 F_377 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_105 ) ) ;
}
static T_9 F_378 ( struct V_1 * V_2 , const char * V_81 ,
T_1 V_49 )
{
V_2 -> V_3 &= ~ V_105 ;
if ( V_81 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_105 ;
}
return V_49 ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_9 F_380 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
if ( F_347 ( V_2 ) )
return - V_342 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_81 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_19 ;
}
F_249 ( V_2 , - 1 ) ;
return V_49 ;
}
static T_9 F_381 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_382 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
if ( F_347 ( V_2 ) )
return - V_342 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_81 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_20 ;
}
F_249 ( V_2 , - 1 ) ;
return V_49 ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_9 F_384 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
if ( F_347 ( V_2 ) )
return - V_342 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_81 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_23 ;
}
F_249 ( V_2 , - 1 ) ;
return V_49 ;
}
static T_9 F_385 ( struct V_1 * V_2 , char * V_81 )
{
return 0 ;
}
static T_9 F_386 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
int V_230 = - V_270 ;
if ( V_81 [ 0 ] == '1' ) {
V_230 = F_321 ( V_2 ) ;
if ( V_230 >= 0 )
V_230 = V_49 ;
}
return V_230 ;
}
static T_9 F_387 ( struct V_1 * V_2 , char * V_81 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_253 ;
return F_334 ( V_2 , V_81 , V_71 ) ;
}
static T_9 F_388 ( struct V_1 * V_2 , char * V_81 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_253 ;
return F_334 ( V_2 , V_81 , V_70 ) ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , ! ! ( V_2 -> V_3 & V_126 ) ) ;
}
static T_9 F_390 ( struct V_1 * V_2 , const char * V_81 ,
T_1 V_49 )
{
V_2 -> V_3 &= ~ V_126 ;
if ( V_81 [ 0 ] == '1' )
V_2 -> V_3 |= V_126 ;
return V_49 ;
}
static T_9 F_391 ( struct V_1 * V_2 , char * V_81 )
{
return 0 ;
}
static T_9 F_392 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
if ( V_81 [ 0 ] == '1' ) {
int V_343 = F_393 ( V_2 ) ;
if ( V_343 )
return V_343 ;
} else
return - V_270 ;
return V_49 ;
}
static T_9 F_394 ( struct V_1 * V_2 , char * V_81 )
{
return sprintf ( V_81 , L_95 , V_2 -> V_177 / 10 ) ;
}
static T_9 F_395 ( struct V_1 * V_2 ,
const char * V_81 , T_1 V_49 )
{
unsigned long V_344 ;
int V_307 ;
V_307 = F_353 ( V_81 , 10 , & V_344 ) ;
if ( V_307 )
return V_307 ;
if ( V_344 <= 100 )
V_2 -> V_177 = V_344 * 10 ;
return V_49 ;
}
static int F_396 ( struct V_1 * V_2 , char * V_81 , enum V_6 V_7 )
{
unsigned long V_345 = 0 ;
int V_65 ;
int V_330 ;
int * V_87 = F_281 ( V_250 * sizeof( int ) , V_259 ) ;
if ( ! V_87 )
return - V_275 ;
F_366 (cpu) {
unsigned V_29 = F_183 ( V_2 -> V_8 , V_65 ) -> F_9 [ V_7 ] ;
V_87 [ V_65 ] = V_29 ;
V_345 += V_29 ;
}
V_330 = sprintf ( V_81 , L_93 , V_345 ) ;
#ifdef F_299
F_366 (cpu) {
if ( V_87 [ V_65 ] && V_330 < V_27 - 20 )
V_330 += sprintf ( V_81 + V_330 , L_101 , V_65 , V_87 [ V_65 ] ) ;
}
#endif
F_259 ( V_87 ) ;
return V_330 + sprintf ( V_81 + V_330 , L_80 ) ;
}
static void F_397 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_65 ;
F_366 (cpu)
F_183 ( V_2 -> V_8 , V_65 ) -> F_9 [ V_7 ] = 0 ;
}
static T_9 F_398 ( struct V_346 * V_347 ,
struct V_348 * V_349 ,
char * V_81 )
{
struct V_350 * V_348 ;
struct V_1 * V_2 ;
int V_307 ;
V_348 = F_399 ( V_349 ) ;
V_2 = F_400 ( V_347 ) ;
if ( ! V_348 -> V_351 )
return - V_352 ;
V_307 = V_348 -> V_351 ( V_2 , V_81 ) ;
return V_307 ;
}
static T_9 F_401 ( struct V_346 * V_347 ,
struct V_348 * V_349 ,
const char * V_81 , T_1 V_330 )
{
struct V_350 * V_348 ;
struct V_1 * V_2 ;
int V_307 ;
V_348 = F_399 ( V_349 ) ;
V_2 = F_400 ( V_347 ) ;
if ( ! V_348 -> V_353 )
return - V_352 ;
V_307 = V_348 -> V_353 ( V_2 , V_81 , V_330 ) ;
#ifdef F_402
if ( V_257 >= V_354 && V_307 >= 0 && F_304 ( V_2 ) ) {
int V_57 ;
F_285 ( & V_278 ) ;
if ( V_2 -> V_355 < V_330 )
V_2 -> V_355 = V_330 ;
F_309 (i) {
struct V_1 * V_164 = F_310 ( V_2 , V_57 ) ;
if ( V_164 )
V_348 -> V_353 ( V_164 , V_81 , V_330 ) ;
}
F_286 ( & V_278 ) ;
}
#endif
return V_307 ;
}
static void F_8 ( struct V_1 * V_2 )
{
#ifdef F_402
int V_57 ;
char * V_356 = NULL ;
struct V_1 * V_357 ;
if ( F_304 ( V_2 ) )
return;
V_357 = V_2 -> V_358 -> V_357 ;
if ( ! V_357 -> V_355 )
return;
for ( V_57 = 0 ; V_57 < F_403 ( V_359 ) ; V_57 ++ ) {
char V_360 [ 64 ] ;
char * V_81 ;
struct V_350 * V_349 = F_399 ( V_359 [ V_57 ] ) ;
if ( ! V_349 || ! V_349 -> V_353 || ! V_349 -> V_351 )
continue;
if ( V_356 )
V_81 = V_356 ;
else if ( V_357 -> V_355 < F_403 ( V_360 ) )
V_81 = V_360 ;
else {
V_356 = ( char * ) F_404 ( V_259 ) ;
if ( F_153 ( ! V_356 ) )
continue;
V_81 = V_356 ;
}
V_349 -> V_351 ( V_357 , V_81 ) ;
V_349 -> V_353 ( V_2 , V_81 , strlen ( V_81 ) ) ;
}
if ( V_356 )
F_405 ( ( unsigned long ) V_356 ) ;
#endif
}
static void F_406 ( struct V_346 * V_361 )
{
F_407 ( F_400 ( V_361 ) ) ;
}
static int F_408 ( struct V_362 * V_362 , struct V_346 * V_347 )
{
struct V_363 * V_364 = F_409 ( V_347 ) ;
if ( V_364 == & V_365 )
return 1 ;
return 0 ;
}
static inline struct V_362 * F_410 ( struct V_1 * V_2 )
{
#ifdef F_402
if ( ! F_304 ( V_2 ) )
return V_2 -> V_358 -> V_357 -> V_366 ;
#endif
return V_367 ;
}
static char * F_411 ( struct V_1 * V_2 )
{
char * V_46 = F_281 ( V_368 , V_259 ) ;
char * V_5 = V_46 ;
F_130 ( ! V_46 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_265 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_141 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_125 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_139 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_46 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_102 , V_2 -> V_15 ) ;
#ifdef F_402
if ( ! F_304 ( V_2 ) )
V_5 += sprintf ( V_5 , L_103 ,
F_412 ( V_2 -> V_358 -> V_369 ) ) ;
#endif
F_130 ( V_5 > V_46 + V_368 - 1 ) ;
return V_46 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_307 ;
const char * V_46 ;
int V_370 = F_303 ( V_2 ) ;
if ( V_370 ) {
F_413 ( & V_367 -> V_347 , V_2 -> V_46 ) ;
V_46 = V_2 -> V_46 ;
} else {
V_46 = F_411 ( V_2 ) ;
}
V_2 -> V_347 . V_362 = F_410 ( V_2 ) ;
V_307 = F_414 ( & V_2 -> V_347 , & V_365 , NULL , L_16 , V_46 ) ;
if ( V_307 )
goto V_371;
V_307 = F_415 ( & V_2 -> V_347 , & V_372 ) ;
if ( V_307 )
goto V_373;
#ifdef F_402
if ( F_304 ( V_2 ) ) {
V_2 -> V_366 = F_416 ( L_104 , NULL , & V_2 -> V_347 ) ;
if ( ! V_2 -> V_366 ) {
V_307 = - V_275 ;
goto V_373;
}
}
#endif
F_417 ( & V_2 -> V_347 , V_374 ) ;
if ( ! V_370 ) {
F_7 ( V_2 , V_2 -> V_46 ) ;
}
V_122:
if ( ! V_370 )
F_259 ( V_46 ) ;
return V_307 ;
V_373:
F_418 ( & V_2 -> V_347 ) ;
V_371:
F_419 ( & V_2 -> V_347 ) ;
goto V_122;
}
void F_420 ( struct V_1 * V_2 )
{
if ( V_257 < V_354 )
return;
#ifdef F_402
F_421 ( V_2 -> V_366 ) ;
#endif
F_417 ( & V_2 -> V_347 , V_375 ) ;
F_418 ( & V_2 -> V_347 ) ;
F_419 ( & V_2 -> V_347 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_46 )
{
struct V_376 * V_377 ;
if ( V_257 == V_354 ) {
F_413 ( & V_367 -> V_347 , V_46 ) ;
return F_422 ( & V_367 -> V_347 , & V_2 -> V_347 , V_46 ) ;
}
V_377 = F_281 ( sizeof( struct V_376 ) , V_259 ) ;
if ( ! V_377 )
return - V_275 ;
V_377 -> V_2 = V_2 ;
V_377 -> V_46 = V_46 ;
V_377 -> V_202 = V_378 ;
V_378 = V_377 ;
return 0 ;
}
static int T_7 F_423 ( void )
{
struct V_1 * V_2 ;
int V_307 ;
F_285 ( & V_278 ) ;
V_367 = F_416 ( L_105 , & V_379 , V_380 ) ;
if ( ! V_367 ) {
F_286 ( & V_278 ) ;
F_55 ( L_106 ) ;
return - V_253 ;
}
V_257 = V_354 ;
F_201 (s, &slab_caches, list) {
V_307 = F_6 ( V_2 ) ;
if ( V_307 )
F_55 ( L_107 ,
V_2 -> V_46 ) ;
}
while ( V_378 ) {
struct V_376 * V_377 = V_378 ;
V_378 = V_378 -> V_202 ;
V_307 = F_7 ( V_377 -> V_2 , V_377 -> V_46 ) ;
if ( V_307 )
F_55 ( L_108 ,
V_377 -> V_46 ) ;
F_259 ( V_377 ) ;
}
F_286 ( & V_278 ) ;
F_341 () ;
return 0 ;
}
void F_424 ( struct V_1 * V_2 , struct V_381 * V_382 )
{
unsigned long V_115 = 0 ;
unsigned long V_217 = 0 ;
unsigned long V_218 = 0 ;
int V_10 ;
F_207 (node) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( ! V_40 )
continue;
V_115 += F_101 ( V_40 ) ;
V_217 += F_197 ( V_40 ) ;
V_218 += F_198 ( V_40 , F_196 ) ;
}
V_382 -> V_383 = V_217 - V_218 ;
V_382 -> V_384 = V_217 ;
V_382 -> V_385 = V_115 ;
V_382 -> V_386 = V_115 ;
V_382 -> V_387 = F_27 ( V_2 -> V_128 ) ;
V_382 -> V_388 = F_26 ( V_2 -> V_128 ) ;
}
void F_425 ( struct V_389 * V_190 , struct V_1 * V_2 )
{
}
T_9 F_426 ( struct V_390 * V_390 , const char T_10 * V_356 ,
T_1 V_316 , T_11 * V_391 )
{
return - V_352 ;
}
