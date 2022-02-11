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
F_40 ( V_46 L_1 , V_40 , V_2 -> V_47 ) ;
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
F_40 ( V_46 L_1 , V_40 , V_2 -> V_47 ) ;
#endif
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long * V_48 )
{
void * V_5 ;
void * V_18 = F_14 ( V_11 ) ;
for ( V_5 = V_11 -> V_44 ; V_5 ; V_5 = F_15 ( V_2 , V_5 ) )
F_45 ( F_22 ( V_5 , V_2 , V_18 ) , V_48 ) ;
}
static void F_46 ( char * V_49 , T_3 * V_18 , unsigned int V_50 )
{
F_47 ( V_51 , V_49 , V_52 , 16 , 1 , V_18 ,
V_50 , 1 ) ;
}
static struct V_53 * F_48 ( struct V_1 * V_2 , void * V_12 ,
enum V_54 V_55 )
{
struct V_53 * V_5 ;
if ( V_2 -> V_16 )
V_5 = V_12 + V_2 -> V_16 + sizeof( void * ) ;
else
V_5 = V_12 + V_2 -> V_24 ;
return V_5 + V_55 ;
}
static void F_49 ( struct V_1 * V_2 , void * V_12 ,
enum V_54 V_55 , unsigned long V_18 )
{
struct V_53 * V_5 = F_48 ( V_2 , V_12 , V_55 ) ;
if ( V_18 ) {
#ifdef F_50
struct V_56 V_57 ;
int V_58 ;
V_57 . V_59 = 0 ;
V_57 . V_60 = V_61 ;
V_57 . V_62 = V_5 -> V_63 ;
V_57 . V_64 = 3 ;
F_51 ( & V_57 ) ;
if ( V_57 . V_59 != 0 &&
V_57 . V_62 [ V_57 . V_59 - 1 ] == V_65 )
V_57 . V_59 -- ;
for ( V_58 = V_57 . V_59 ; V_58 < V_61 ; V_58 ++ )
V_5 -> V_63 [ V_58 ] = 0 ;
#endif
V_5 -> V_18 = V_18 ;
V_5 -> V_66 = F_52 () ;
V_5 -> V_67 = V_68 -> V_67 ;
V_5 -> V_69 = V_70 ;
} else
memset ( V_5 , 0 , sizeof( struct V_53 ) ) ;
}
static void F_53 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_49 ( V_2 , V_12 , V_71 , 0UL ) ;
F_49 ( V_2 , V_12 , V_72 , 0UL ) ;
}
static void F_54 ( const char * V_2 , struct V_53 * V_73 )
{
if ( ! V_73 -> V_18 )
return;
F_40 ( V_51 L_2 ,
V_2 , ( void * ) V_73 -> V_18 , V_70 - V_73 -> V_69 , V_73 -> V_66 , V_73 -> V_67 ) ;
#ifdef F_50
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 ; V_58 ++ )
if ( V_73 -> V_63 [ V_58 ] )
F_40 ( V_51 L_3 , ( void * ) V_73 -> V_63 [ V_58 ] ) ;
else
break;
}
#endif
}
static void F_55 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_54 ( L_4 , F_48 ( V_2 , V_12 , V_72 ) ) ;
F_54 ( L_5 , F_48 ( V_2 , V_12 , V_71 ) ) ;
}
static void F_56 ( struct V_11 * V_11 )
{
F_40 ( V_51
L_6 ,
V_11 , V_11 -> V_14 , V_11 -> V_24 , V_11 -> V_44 , V_11 -> V_3 ) ;
}
static void F_57 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_40 ( V_51 L_7
L_8 ) ;
F_40 ( V_51 L_9 , V_2 -> V_47 , F_58 () , V_75 ) ;
F_40 ( V_51 L_10
L_11 ) ;
F_59 ( V_76 , V_77 ) ;
}
static void F_60 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_40 ( V_51 L_12 , V_2 -> V_47 , V_75 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned int V_78 ;
T_3 * V_18 = F_14 ( V_11 ) ;
F_55 ( V_2 , V_5 ) ;
F_56 ( V_11 ) ;
F_40 ( V_51 L_13 ,
V_5 , V_5 - V_18 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_18 + 16 )
F_46 ( L_14 , V_5 - 16 , 16 ) ;
F_46 ( L_15 , V_5 , F_62 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_19 )
F_46 ( L_16 , V_5 + V_2 -> V_21 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
if ( V_2 -> V_16 )
V_78 = V_2 -> V_16 + sizeof( void * ) ;
else
V_78 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_78 += 2 * sizeof( struct V_53 ) ;
if ( V_78 != V_2 -> V_15 )
F_46 ( L_17 , V_5 + V_78 , V_2 -> V_15 - V_78 ) ;
F_63 () ;
}
static void F_64 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_79 )
{
F_57 ( V_2 , L_18 , V_79 ) ;
F_61 ( V_2 , V_11 , V_12 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_57 ( V_2 , L_18 , V_75 ) ;
F_56 ( V_11 ) ;
F_63 () ;
}
static void F_66 ( struct V_1 * V_2 , void * V_12 , T_3 V_80 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_81 ) {
memset ( V_5 , V_82 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_83 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_80 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_67 ( struct V_1 * V_2 , char * V_84 , T_3 V_85 ,
void * V_86 , void * V_87 )
{
F_60 ( V_2 , L_19 , V_86 , V_87 - 1 , V_85 ) ;
memset ( V_86 , V_85 , V_87 - V_86 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_88 ,
T_3 * V_89 , unsigned int V_90 , unsigned int V_91 )
{
T_3 * V_92 ;
T_3 * V_93 ;
V_92 = F_69 ( V_89 , V_90 , V_91 ) ;
if ( ! V_92 )
return 1 ;
V_93 = V_89 + V_91 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_90 )
V_93 -- ;
F_57 ( V_2 , L_20 , V_88 ) ;
F_40 ( V_51 L_21 ,
V_92 , V_93 - 1 , V_92 [ 0 ] , V_90 ) ;
F_61 ( V_2 , V_11 , V_12 ) ;
F_67 ( V_2 , V_88 , V_90 , V_92 , V_93 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_78 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_78 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_78 += 2 * sizeof( struct V_53 ) ;
if ( V_2 -> V_15 == V_78 )
return 1 ;
return F_68 ( V_2 , V_11 , V_5 , L_22 ,
V_5 + V_78 , V_94 , V_2 -> V_15 - V_78 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_89 ;
T_3 * V_92 ;
T_3 * V_93 ;
int V_50 ;
int V_95 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_89 = F_14 ( V_11 ) ;
V_50 = ( V_27 << F_72 ( V_11 ) ) - V_2 -> V_26 ;
V_93 = V_89 + V_50 ;
V_95 = V_50 % V_2 -> V_15 ;
if ( ! V_95 )
return 1 ;
V_92 = F_69 ( V_93 - V_95 , V_94 , V_95 ) ;
if ( ! V_92 )
return 1 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_94 )
V_93 -- ;
F_65 ( V_2 , V_11 , L_23 , V_92 , V_93 - 1 ) ;
F_46 ( L_17 , V_93 - V_95 , V_95 ) ;
F_67 ( V_2 , L_24 , V_94 , V_93 - V_95 , V_93 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_80 )
{
T_3 * V_5 = V_12 ;
T_3 * V_96 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_68 ( V_2 , V_11 , V_12 , L_25 ,
V_96 , V_80 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_68 ( V_2 , V_11 , V_5 , L_26 ,
V_96 , V_94 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_80 != V_97 && ( V_2 -> V_3 & V_81 ) &&
( ! F_68 ( V_2 , V_11 , V_5 , L_27 , V_5 ,
V_82 , V_2 -> V_21 - 1 ) ||
! F_68 ( V_2 , V_11 , V_5 , L_27 ,
V_5 + V_2 -> V_21 - 1 , V_83 , 1 ) ) )
return 0 ;
F_70 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_80 == V_97 )
return 1 ;
if ( ! F_13 ( V_2 , V_11 , F_15 ( V_2 , V_5 ) ) ) {
F_64 ( V_2 , V_11 , V_5 , L_28 ) ;
F_21 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_98 ;
F_34 ( ! F_35 () ) ;
if ( ! F_75 ( V_11 ) ) {
F_65 ( V_2 , V_11 , L_29 ) ;
return 0 ;
}
V_98 = F_24 ( F_72 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_98 ) {
F_65 ( V_2 , V_11 , L_30 ,
V_2 -> V_47 , V_11 -> V_14 , V_98 ) ;
return 0 ;
}
if ( V_11 -> V_24 > V_11 -> V_14 ) {
F_65 ( V_2 , V_11 , L_31 ,
V_2 -> V_47 , V_11 -> V_24 , V_11 -> V_14 ) ;
return 0 ;
}
F_71 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_99 )
{
int V_100 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_101 ;
V_17 = V_11 -> V_44 ;
while ( V_17 && V_100 <= V_11 -> V_14 ) {
if ( V_17 == V_99 )
return 1 ;
if ( ! F_13 ( V_2 , V_11 , V_17 ) ) {
if ( V_12 ) {
F_64 ( V_2 , V_11 , V_12 ,
L_32 ) ;
F_21 ( V_2 , V_12 , NULL ) ;
} else {
F_65 ( V_2 , V_11 , L_28 ) ;
V_11 -> V_44 = NULL ;
V_11 -> V_24 = V_11 -> V_14 ;
F_60 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_12 = V_17 ;
V_17 = F_15 ( V_2 , V_12 ) ;
V_100 ++ ;
}
V_101 = F_24 ( F_72 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_101 > V_102 )
V_101 = V_102 ;
if ( V_11 -> V_14 != V_101 ) {
F_65 ( V_2 , V_11 , L_34
L_35 , V_11 -> V_14 , V_101 ) ;
V_11 -> V_14 = V_101 ;
F_60 ( V_2 , L_36 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_100 ) {
F_65 ( V_2 , V_11 , L_37
L_38 , V_11 -> V_24 , V_11 -> V_14 - V_100 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_100 ;
F_60 ( V_2 , L_39 ) ;
}
return V_99 == NULL ;
}
static void V_57 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_55 )
{
if ( V_2 -> V_3 & V_103 ) {
F_40 ( V_46 L_40 ,
V_2 -> V_47 ,
V_55 ? L_41 : L_42 ,
V_12 , V_11 -> V_24 ,
V_11 -> V_44 ) ;
if ( ! V_55 )
F_46 ( L_15 , ( void * ) V_12 ,
V_2 -> V_21 ) ;
F_63 () ;
}
}
static inline void F_77 ( void * V_104 , T_1 V_15 , T_5 V_3 )
{
F_78 ( V_104 , V_15 , 1 , V_3 ) ;
}
static inline void F_79 ( const void * V_29 )
{
F_80 ( V_29 ) ;
}
static inline int F_81 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_105 ;
F_82 ( V_3 ) ;
F_83 ( V_3 & V_106 ) ;
return F_84 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_85 ( struct V_1 * V_2 ,
T_5 V_3 , void * V_12 )
{
V_3 &= V_105 ;
F_86 ( V_2 , V_3 , V_12 , F_23 ( V_2 ) ) ;
F_87 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_88 ( struct V_1 * V_2 , void * V_29 )
{
F_89 ( V_29 , V_2 -> V_3 ) ;
#if F_36 ( V_107 ) || F_36 ( V_108 )
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_90 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_91 ( V_29 , V_2 -> V_21 ) ;
F_43 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_109 ) )
F_92 ( V_29 , V_2 -> V_21 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_9 * V_40 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_94 ( & V_40 -> V_110 ) ;
F_95 ( & V_11 -> V_111 , & V_40 -> V_112 ) ;
}
static void F_96 ( struct V_1 * V_2 , struct V_9 * V_40 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_94 ( & V_40 -> V_110 ) ;
F_97 ( & V_11 -> V_111 ) ;
}
static inline unsigned long F_98 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
return F_99 ( & V_40 -> V_113 ) ;
}
static inline unsigned long F_100 ( struct V_9 * V_40 )
{
return F_99 ( & V_40 -> V_113 ) ;
}
static inline void F_101 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( F_102 ( V_40 ) ) {
F_103 ( & V_40 -> V_113 ) ;
F_104 ( V_14 , & V_40 -> V_114 ) ;
}
}
static inline void F_105 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
F_106 ( & V_40 -> V_113 ) ;
F_107 ( V_14 , & V_40 -> V_114 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_81 ) ) )
return;
F_66 ( V_2 , V_12 , V_115 ) ;
F_53 ( V_2 , V_12 ) ;
}
static T_6 int F_109 ( struct V_1 * V_2 ,
struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_74 ( V_2 , V_11 ) )
goto V_116;
if ( ! F_13 ( V_2 , V_11 , V_12 ) ) {
F_64 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_116;
}
if ( ! F_73 ( V_2 , V_11 , V_12 , V_115 ) )
goto V_116;
if ( V_2 -> V_3 & V_23 )
F_49 ( V_2 , V_12 , V_72 , V_18 ) ;
V_57 ( V_2 , V_11 , V_12 , 1 ) ;
F_66 ( V_2 , V_12 , V_97 ) ;
return 1 ;
V_116:
if ( F_75 ( V_11 ) ) {
F_60 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_44 = NULL ;
}
return 0 ;
}
int T_7 F_110 ( char * V_117 )
{
V_118 = V_119 ;
if ( * V_117 ++ != '=' || ! * V_117 )
goto V_120;
if ( * V_117 == ',' )
goto V_121;
if ( tolower ( * V_117 ) == 'o' ) {
V_122 = 1 ;
goto V_120;
}
V_118 = 0 ;
if ( * V_117 == '-' )
goto V_120;
for (; * V_117 && * V_117 != ',' ; V_117 ++ ) {
switch ( tolower ( * V_117 ) ) {
case 'f' :
V_118 |= V_123 ;
break;
case 'z' :
V_118 |= V_19 ;
break;
case 'p' :
V_118 |= V_20 ;
break;
case 'u' :
V_118 |= V_23 ;
break;
case 't' :
V_118 |= V_103 ;
break;
case 'a' :
V_118 |= V_124 ;
break;
default:
F_40 ( V_51 L_45
L_46 , * V_117 ) ;
}
}
V_121:
if ( * V_117 == ',' )
V_125 = V_117 + 1 ;
V_120:
return 1 ;
}
static unsigned long F_111 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_47 ,
void (* F_112)( void * ) )
{
if ( V_118 && ( ! V_125 || ( V_47 &&
! strncmp ( V_125 , V_47 , strlen ( V_125 ) ) ) ) )
V_3 |= V_118 ;
return V_3 ;
}
static inline void F_108 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 ) {}
static inline int F_109 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 , unsigned long V_18 ) { return 0 ; }
static inline struct V_9 * F_113 (
struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
unsigned long V_18 , unsigned long * V_3 ) { return NULL ; }
static inline int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 )
{ return 1 ; }
static inline int F_73 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_80 ) { return 1 ; }
static inline void F_93 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_11 * V_11 ) {}
static inline void F_96 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_11 * V_11 ) {}
static inline unsigned long F_111 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_47 ,
void (* F_112)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_98 ( struct V_1 * V_2 , int V_10 )
{ return 0 ; }
static inline unsigned long F_100 ( struct V_9 * V_40 )
{ return 0 ; }
static inline void F_101 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_105 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_77 ( void * V_104 , T_1 V_15 , T_5 V_3 )
{
F_78 ( V_104 , V_15 , 1 , V_3 ) ;
}
static inline void F_79 ( const void * V_29 )
{
F_80 ( V_29 ) ;
}
static inline int F_81 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_85 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_12 )
{
F_87 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 ,
V_3 & V_105 ) ;
}
static inline void F_88 ( struct V_1 * V_2 , void * V_29 )
{
F_89 ( V_29 , V_2 -> V_3 ) ;
}
static inline struct V_11 * F_114 ( T_5 V_3 , int V_10 ,
struct V_28 V_126 )
{
int V_25 = F_26 ( V_126 ) ;
V_3 |= V_127 ;
if ( V_10 == V_128 )
return F_115 ( V_3 , V_25 ) ;
else
return F_116 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_117 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_126 = V_2 -> V_126 ;
T_5 V_129 ;
V_3 &= V_105 ;
if ( V_3 & V_106 )
F_118 () ;
V_3 |= V_2 -> V_130 ;
V_129 = ( V_3 | V_131 | V_132 ) & ~ V_133 ;
V_11 = F_114 ( V_129 , V_10 , V_126 ) ;
if ( F_3 ( ! V_11 ) ) {
V_126 = V_2 -> V_134 ;
V_129 = V_3 ;
V_11 = F_114 ( V_129 , V_10 , V_126 ) ;
if ( V_11 )
F_9 ( V_2 , V_135 ) ;
}
if ( V_136 && V_11
&& ! ( V_2 -> V_3 & ( V_137 | V_119 ) ) ) {
int V_138 = 1 << F_26 ( V_126 ) ;
F_119 ( V_11 , F_26 ( V_126 ) , V_129 , V_10 ) ;
if ( V_2 -> F_112 )
F_120 ( V_11 , V_138 ) ;
else
F_121 ( V_11 , V_138 ) ;
}
if ( V_3 & V_106 )
F_122 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_27 ( V_126 ) ;
F_123 ( F_124 ( V_11 ) ,
( V_2 -> V_3 & V_139 ) ?
V_140 : V_141 ,
1 << F_26 ( V_126 ) ) ;
return V_11 ;
}
static void F_125 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_108 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_112 ) )
V_2 -> F_112 ( V_12 ) ;
}
static struct V_11 * F_126 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_89 ;
void * V_142 ;
void * V_5 ;
int V_25 ;
F_127 ( V_3 & V_143 ) ;
V_11 = F_117 ( V_2 ,
V_3 & ( V_144 | V_145 ) , V_10 ) ;
if ( ! V_11 )
goto V_120;
V_25 = F_72 ( V_11 ) ;
F_101 ( V_2 , F_128 ( V_11 ) , V_11 -> V_14 ) ;
F_129 ( V_2 , V_25 ) ;
V_11 -> V_146 = V_2 ;
F_130 ( V_11 ) ;
if ( V_11 -> V_147 )
F_131 ( V_11 ) ;
V_89 = F_14 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_89 , V_94 , V_27 << V_25 ) ;
V_142 = V_89 ;
F_132 (p, s, start, page->objects) {
F_125 ( V_2 , V_11 , V_142 ) ;
F_21 ( V_2 , V_142 , V_5 ) ;
V_142 = V_5 ;
}
F_125 ( V_2 , V_11 , V_142 ) ;
F_21 ( V_2 , V_142 , NULL ) ;
V_11 -> V_44 = V_89 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_36 = 1 ;
V_120:
return V_11 ;
}
static void F_133 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_72 ( V_11 ) ;
int V_138 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_71 ( V_2 , V_11 ) ;
F_132 (p, s, page_address(page),
page->objects)
F_73 ( V_2 , V_11 , V_5 , V_115 ) ;
}
F_134 ( V_11 , F_72 ( V_11 ) ) ;
F_123 ( F_124 ( V_11 ) ,
( V_2 -> V_3 & V_139 ) ?
V_140 : V_141 ,
- V_138 ) ;
F_135 ( V_11 ) ;
F_136 ( V_11 ) ;
F_137 ( V_2 , V_25 ) ;
F_138 ( V_11 ) ;
if ( V_68 -> V_148 )
V_68 -> V_148 -> V_149 += V_138 ;
F_139 ( V_11 , V_25 ) ;
}
static void F_140 ( struct V_150 * V_151 )
{
struct V_11 * V_11 ;
if ( V_152 )
V_11 = F_141 ( V_151 ) ;
else
V_11 = F_142 ( (struct V_153 * ) V_151 , struct V_11 , V_111 ) ;
F_133 ( V_11 -> V_146 , V_11 ) ;
}
static void F_143 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_150 * V_154 ;
if ( V_152 ) {
int V_25 = F_72 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_34 ( V_2 -> V_26 != sizeof( * V_154 ) ) ;
V_154 = F_14 ( V_11 ) + V_16 ;
} else {
V_154 = ( void * ) & V_11 -> V_111 ;
}
F_144 ( V_154 , F_140 ) ;
} else
F_133 ( V_2 , V_11 ) ;
}
static void F_145 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_105 ( V_2 , F_128 ( V_11 ) , V_11 -> V_14 ) ;
F_143 ( V_2 , V_11 ) ;
}
static inline void
F_146 ( struct V_9 * V_40 , struct V_11 * V_11 , int V_155 )
{
V_40 -> V_156 ++ ;
if ( V_155 == V_157 )
F_147 ( & V_11 -> V_111 , & V_40 -> V_158 ) ;
else
F_95 ( & V_11 -> V_111 , & V_40 -> V_158 ) ;
}
static inline void F_148 ( struct V_9 * V_40 ,
struct V_11 * V_11 , int V_155 )
{
F_94 ( & V_40 -> V_110 ) ;
F_146 ( V_40 , V_11 , V_155 ) ;
}
static inline void
F_149 ( struct V_9 * V_40 , struct V_11 * V_11 )
{
F_97 ( & V_11 -> V_111 ) ;
V_40 -> V_156 -- ;
}
static inline void F_150 ( struct V_9 * V_40 ,
struct V_11 * V_11 )
{
F_94 ( & V_40 -> V_110 ) ;
F_149 ( V_40 , V_11 ) ;
}
static inline void * F_151 ( struct V_1 * V_2 ,
struct V_9 * V_40 , struct V_11 * V_11 ,
int V_159 , int * V_14 )
{
void * V_44 ;
unsigned long V_35 ;
struct V_11 V_160 ;
F_94 ( & V_40 -> V_110 ) ;
V_44 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
V_160 . V_35 = V_35 ;
* V_14 = V_160 . V_14 - V_160 . V_24 ;
if ( V_159 ) {
V_160 . V_24 = V_11 -> V_14 ;
V_160 . V_44 = NULL ;
} else {
V_160 . V_44 = V_44 ;
}
F_34 ( V_160 . V_36 ) ;
V_160 . V_36 = 1 ;
if ( ! F_33 ( V_2 , V_11 ,
V_44 , V_35 ,
V_160 . V_44 , V_160 . V_35 ,
L_47 ) )
return NULL ;
F_150 ( V_40 , V_11 ) ;
F_152 ( ! V_44 ) ;
return V_44 ;
}
static void * F_153 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_161 * V_162 , T_5 V_3 )
{
struct V_11 * V_11 , * V_163 ;
void * V_12 = NULL ;
int V_164 = 0 ;
int V_14 ;
if ( ! V_40 || ! V_40 -> V_156 )
return NULL ;
F_154 ( & V_40 -> V_110 ) ;
F_155 (page, page2, &n->partial, lru) {
void * V_73 ;
if ( ! F_156 ( V_11 , V_3 ) )
continue;
V_73 = F_151 ( V_2 , V_40 , V_11 , V_12 == NULL , & V_14 ) ;
if ( ! V_73 )
break;
V_164 += V_14 ;
if ( ! V_12 ) {
V_162 -> V_11 = V_11 ;
F_9 ( V_2 , V_165 ) ;
V_12 = V_73 ;
} else {
F_157 ( V_2 , V_11 , 0 ) ;
F_9 ( V_2 , V_166 ) ;
}
if ( ! F_4 ( V_2 )
|| V_164 > V_2 -> V_167 / 2 )
break;
}
F_158 ( & V_40 -> V_110 ) ;
return V_12 ;
}
static void * F_159 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_161 * V_162 )
{
#ifdef F_160
struct V_168 * V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_171 ;
enum V_172 V_173 = F_161 ( V_3 ) ;
void * V_12 ;
unsigned int V_174 ;
if ( ! V_2 -> V_175 ||
F_162 () % 1024 > V_2 -> V_175 )
return NULL ;
do {
V_174 = F_163 () ;
V_168 = F_164 ( F_165 () , V_3 ) ;
F_166 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_40 ;
V_40 = F_12 ( V_2 , F_167 ( V_171 ) ) ;
if ( V_40 && F_168 ( V_171 , V_3 ) &&
V_40 -> V_156 > V_2 -> V_176 ) {
V_12 = F_153 ( V_2 , V_40 , V_162 , V_3 ) ;
if ( V_12 ) {
return V_12 ;
}
}
}
} while ( F_169 ( V_174 ) );
#endif
return NULL ;
}
static void * F_170 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_161 * V_162 )
{
void * V_12 ;
int V_177 = ( V_10 == V_128 ) ? F_171 () : V_10 ;
V_12 = F_153 ( V_2 , F_12 ( V_2 , V_177 ) , V_162 , V_3 ) ;
if ( V_12 || V_10 != V_128 )
return V_12 ;
return F_159 ( V_2 , V_3 , V_162 ) ;
}
static inline unsigned long F_172 ( unsigned long V_178 )
{
return V_178 + V_179 ;
}
static inline unsigned int F_173 ( unsigned long V_178 )
{
return V_178 % V_179 ;
}
static inline unsigned long F_174 ( unsigned long V_178 )
{
return V_178 / V_179 ;
}
static inline unsigned int F_175 ( int V_66 )
{
return V_66 ;
}
static inline void F_176 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_178 )
{
#ifdef F_39
unsigned long V_180 = F_177 ( V_2 -> V_8 -> V_178 ) ;
F_40 ( V_46 L_48 , V_40 , V_2 -> V_47 ) ;
#ifdef F_178
if ( F_173 ( V_178 ) != F_173 ( V_180 ) )
F_40 ( L_49 ,
F_173 ( V_178 ) , F_173 ( V_180 ) ) ;
else
#endif
if ( F_174 ( V_178 ) != F_174 ( V_180 ) )
F_40 ( L_50 ,
F_174 ( V_178 ) , F_174 ( V_180 ) ) ;
else
F_40 ( L_51 ,
V_180 , V_178 , F_172 ( V_178 ) ) ;
#endif
F_9 ( V_2 , V_181 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
int V_66 ;
F_180 (cpu)
F_181 ( V_2 -> V_8 , V_66 ) -> V_178 = F_175 ( V_66 ) ;
}
static void F_182 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_44 )
{
enum T_8 { V_182 , V_183 , V_184 , V_185 };
struct V_9 * V_40 = F_12 ( V_2 , F_128 ( V_11 ) ) ;
int V_186 = 0 ;
enum T_8 V_187 = V_182 , V_188 = V_182 ;
void * V_189 ;
int V_155 = V_190 ;
struct V_11 V_160 ;
struct V_11 V_191 ;
if ( V_11 -> V_44 ) {
F_9 ( V_2 , V_192 ) ;
V_155 = V_157 ;
}
while ( V_44 && ( V_189 = F_15 ( V_2 , V_44 ) ) ) {
void * V_193 ;
unsigned long V_35 ;
do {
V_193 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
F_21 ( V_2 , V_44 , V_193 ) ;
V_160 . V_35 = V_35 ;
V_160 . V_24 -- ;
F_34 ( ! V_160 . V_36 ) ;
} while ( ! F_33 ( V_2 , V_11 ,
V_193 , V_35 ,
V_44 , V_160 . V_35 ,
L_52 ) );
V_44 = V_189 ;
}
V_194:
V_191 . V_44 = V_11 -> V_44 ;
V_191 . V_35 = V_11 -> V_35 ;
F_34 ( ! V_191 . V_36 ) ;
V_160 . V_35 = V_191 . V_35 ;
if ( V_44 ) {
V_160 . V_24 -- ;
F_21 ( V_2 , V_44 , V_191 . V_44 ) ;
V_160 . V_44 = V_44 ;
} else
V_160 . V_44 = V_191 . V_44 ;
V_160 . V_36 = 0 ;
if ( ! V_160 . V_24 && V_40 -> V_156 > V_2 -> V_176 )
V_188 = V_185 ;
else if ( V_160 . V_44 ) {
V_188 = V_183 ;
if ( ! V_186 ) {
V_186 = 1 ;
F_154 ( & V_40 -> V_110 ) ;
}
} else {
V_188 = V_184 ;
if ( F_1 ( V_2 ) && ! V_186 ) {
V_186 = 1 ;
F_154 ( & V_40 -> V_110 ) ;
}
}
if ( V_187 != V_188 ) {
if ( V_187 == V_183 )
F_150 ( V_40 , V_11 ) ;
else if ( V_187 == V_184 )
F_96 ( V_2 , V_40 , V_11 ) ;
if ( V_188 == V_183 ) {
F_148 ( V_40 , V_11 , V_155 ) ;
F_9 ( V_2 , V_155 ) ;
} else if ( V_188 == V_184 ) {
F_9 ( V_2 , V_195 ) ;
F_93 ( V_2 , V_40 , V_11 ) ;
}
}
V_187 = V_188 ;
if ( ! F_33 ( V_2 , V_11 ,
V_191 . V_44 , V_191 . V_35 ,
V_160 . V_44 , V_160 . V_35 ,
L_53 ) )
goto V_194;
if ( V_186 )
F_158 ( & V_40 -> V_110 ) ;
if ( V_188 == V_185 ) {
F_9 ( V_2 , V_196 ) ;
F_145 ( V_2 , V_11 ) ;
F_9 ( V_2 , V_197 ) ;
}
}
static void F_183 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
#ifdef F_5
struct V_9 * V_40 = NULL , * V_198 = NULL ;
struct V_11 * V_11 , * V_199 = NULL ;
while ( ( V_11 = V_162 -> V_158 ) ) {
struct V_11 V_160 ;
struct V_11 V_191 ;
V_162 -> V_158 = V_11 -> V_200 ;
V_198 = F_12 ( V_2 , F_128 ( V_11 ) ) ;
if ( V_40 != V_198 ) {
if ( V_40 )
F_158 ( & V_40 -> V_110 ) ;
V_40 = V_198 ;
F_154 ( & V_40 -> V_110 ) ;
}
do {
V_191 . V_44 = V_11 -> V_44 ;
V_191 . V_35 = V_11 -> V_35 ;
F_34 ( ! V_191 . V_36 ) ;
V_160 . V_35 = V_191 . V_35 ;
V_160 . V_44 = V_191 . V_44 ;
V_160 . V_36 = 0 ;
} while ( ! F_33 ( V_2 , V_11 ,
V_191 . V_44 , V_191 . V_35 ,
V_160 . V_44 , V_160 . V_35 ,
L_53 ) );
if ( F_3 ( ! V_160 . V_24 && V_40 -> V_156 > V_2 -> V_176 ) ) {
V_11 -> V_200 = V_199 ;
V_199 = V_11 ;
} else {
F_148 ( V_40 , V_11 , V_157 ) ;
F_9 ( V_2 , V_201 ) ;
}
}
if ( V_40 )
F_158 ( & V_40 -> V_110 ) ;
while ( V_199 ) {
V_11 = V_199 ;
V_199 = V_199 -> V_200 ;
F_9 ( V_2 , V_196 ) ;
F_145 ( V_2 , V_11 ) ;
F_9 ( V_2 , V_197 ) ;
}
#endif
}
static void F_157 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_202 )
{
#ifdef F_5
struct V_11 * V_203 ;
int V_138 ;
int V_204 ;
do {
V_138 = 0 ;
V_204 = 0 ;
V_203 = F_184 ( V_2 -> V_8 -> V_158 ) ;
if ( V_203 ) {
V_204 = V_203 -> V_204 ;
V_138 = V_203 -> V_138 ;
if ( V_202 && V_204 > V_2 -> V_167 ) {
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_183 ( V_2 , F_185 ( V_2 -> V_8 ) ) ;
F_43 ( V_3 ) ;
V_203 = NULL ;
V_204 = 0 ;
V_138 = 0 ;
F_9 ( V_2 , V_205 ) ;
}
}
V_138 ++ ;
V_204 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_138 = V_138 ;
V_11 -> V_204 = V_204 ;
V_11 -> V_200 = V_203 ;
} while ( F_186 ( V_2 -> V_8 -> V_158 , V_203 , V_11 )
!= V_203 );
#endif
}
static inline void F_187 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
F_9 ( V_2 , V_206 ) ;
F_182 ( V_2 , V_162 -> V_11 , V_162 -> V_44 ) ;
V_162 -> V_178 = F_172 ( V_162 -> V_178 ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
}
static inline void F_188 ( struct V_1 * V_2 , int V_66 )
{
struct V_161 * V_162 = F_181 ( V_2 -> V_8 , V_66 ) ;
if ( F_102 ( V_162 ) ) {
if ( V_162 -> V_11 )
F_187 ( V_2 , V_162 ) ;
F_183 ( V_2 , V_162 ) ;
}
}
static void F_189 ( void * V_207 )
{
struct V_1 * V_2 = V_207 ;
F_188 ( V_2 , F_52 () ) ;
}
static bool F_190 ( int V_66 , void * V_208 )
{
struct V_1 * V_2 = V_208 ;
struct V_161 * V_162 = F_181 ( V_2 -> V_8 , V_66 ) ;
return V_162 -> V_11 || V_162 -> V_158 ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_192 ( F_190 , F_189 , V_2 , 1 , V_209 ) ;
}
static inline int F_193 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_160
if ( ! V_11 || ( V_10 != V_128 && F_128 ( V_11 ) != V_10 ) )
return 0 ;
#endif
return 1 ;
}
static int F_194 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static unsigned long F_195 ( struct V_9 * V_40 ,
int (* F_196)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_197 ( & V_40 -> V_110 , V_3 ) ;
F_198 (page, &n->partial, lru)
V_29 += F_196 ( V_11 ) ;
F_199 ( & V_40 -> V_110 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_200 ( struct V_9 * V_40 )
{
#ifdef F_2
return F_99 ( & V_40 -> V_114 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_201 ( struct V_1 * V_2 , T_5 V_210 , int V_211 )
{
int V_10 ;
F_40 ( V_212
L_54 ,
V_211 , V_210 ) ;
F_40 ( V_212 L_55
L_56 , V_2 -> V_47 , V_2 -> V_21 ,
V_2 -> V_15 , F_26 ( V_2 -> V_126 ) , F_26 ( V_2 -> V_134 ) ) ;
if ( F_26 ( V_2 -> V_134 ) > F_202 ( V_2 -> V_21 ) )
F_40 ( V_212 L_57
L_58 , V_2 -> V_47 ) ;
F_203 (node) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
unsigned long V_113 ;
unsigned long V_213 ;
unsigned long V_214 ;
if ( ! V_40 )
continue;
V_214 = F_195 ( V_40 , F_194 ) ;
V_113 = F_100 ( V_40 ) ;
V_213 = F_200 ( V_40 ) ;
F_40 ( V_212
L_59 ,
V_10 , V_113 , V_213 , V_214 ) ;
}
}
static inline void * F_204 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_161 * * V_215 )
{
void * V_44 ;
struct V_161 * V_162 = * V_215 ;
struct V_11 * V_11 ;
V_44 = F_170 ( V_2 , V_3 , V_10 , V_162 ) ;
if ( V_44 )
return V_44 ;
V_11 = F_126 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_162 = F_205 ( V_2 -> V_8 ) ;
if ( V_162 -> V_11 )
F_187 ( V_2 , V_162 ) ;
V_44 = V_11 -> V_44 ;
V_11 -> V_44 = NULL ;
F_9 ( V_2 , V_216 ) ;
V_162 -> V_11 = V_11 ;
* V_215 = V_162 ;
} else
V_44 = NULL ;
return V_44 ;
}
static inline bool F_156 ( struct V_11 * V_11 , T_5 V_210 )
{
if ( F_3 ( F_206 ( V_11 ) ) )
return F_207 ( V_210 ) ;
return true ;
}
static inline void * F_208 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_160 ;
unsigned long V_35 ;
void * V_44 ;
do {
V_44 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
V_160 . V_35 = V_35 ;
F_34 ( ! V_160 . V_36 ) ;
V_160 . V_24 = V_11 -> V_14 ;
V_160 . V_36 = V_44 != NULL ;
} while ( ! F_33 ( V_2 , V_11 ,
V_44 , V_35 ,
NULL , V_160 . V_35 ,
L_60 ) );
return V_44 ;
}
static void * F_209 ( struct V_1 * V_2 , T_5 V_210 , int V_10 ,
unsigned long V_18 , struct V_161 * V_162 )
{
void * V_44 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_42 ( V_3 ) ;
#ifdef F_178
V_162 = F_185 ( V_2 -> V_8 ) ;
#endif
V_11 = V_162 -> V_11 ;
if ( ! V_11 )
goto F_126;
V_194:
if ( F_3 ( ! F_193 ( V_11 , V_10 ) ) ) {
F_9 ( V_2 , V_217 ) ;
F_182 ( V_2 , V_11 , V_162 -> V_44 ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
goto F_126;
}
if ( F_3 ( ! F_156 ( V_11 , V_210 ) ) ) {
F_182 ( V_2 , V_11 , V_162 -> V_44 ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
goto F_126;
}
V_44 = V_162 -> V_44 ;
if ( V_44 )
goto V_218;
F_9 ( V_2 , V_219 ) ;
V_44 = F_208 ( V_2 , V_11 ) ;
if ( ! V_44 ) {
V_162 -> V_11 = NULL ;
F_9 ( V_2 , V_220 ) ;
goto F_126;
}
F_9 ( V_2 , V_221 ) ;
V_218:
F_34 ( ! V_162 -> V_11 -> V_36 ) ;
V_162 -> V_44 = F_15 ( V_2 , V_44 ) ;
V_162 -> V_178 = F_172 ( V_162 -> V_178 ) ;
F_43 ( V_3 ) ;
return V_44 ;
F_126:
if ( V_162 -> V_158 ) {
V_11 = V_162 -> V_11 = V_162 -> V_158 ;
V_162 -> V_158 = V_11 -> V_200 ;
F_9 ( V_2 , V_222 ) ;
V_162 -> V_44 = NULL ;
goto V_194;
}
V_44 = F_204 ( V_2 , V_210 , V_10 , & V_162 ) ;
if ( F_3 ( ! V_44 ) ) {
if ( ! ( V_210 & V_131 ) && F_210 () )
F_201 ( V_2 , V_210 , V_10 ) ;
F_43 ( V_3 ) ;
return NULL ;
}
V_11 = V_162 -> V_11 ;
if ( F_102 ( ! F_1 ( V_2 ) && F_156 ( V_11 , V_210 ) ) )
goto V_218;
if ( F_1 ( V_2 ) &&
! F_109 ( V_2 , V_11 , V_44 , V_18 ) )
goto F_126;
F_182 ( V_2 , V_11 , F_15 ( V_2 , V_44 ) ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
F_43 ( V_3 ) ;
return V_44 ;
}
static T_2 void * F_211 ( struct V_1 * V_2 ,
T_5 V_210 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_161 * V_162 ;
struct V_11 * V_11 ;
unsigned long V_178 ;
if ( F_81 ( V_2 , V_210 ) )
return NULL ;
V_2 = F_212 ( V_2 , V_210 ) ;
V_194:
F_213 () ;
V_162 = F_205 ( V_2 -> V_8 ) ;
V_178 = V_162 -> V_178 ;
F_214 () ;
V_12 = V_162 -> V_44 ;
V_11 = V_162 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_193 ( V_11 , V_10 ) ) )
V_12 = F_209 ( V_2 , V_210 , V_10 , V_18 , V_162 ) ;
else {
void * V_223 = F_18 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_215 (
V_2 -> V_8 -> V_44 , V_2 -> V_8 -> V_178 ,
V_12 , V_178 ,
V_223 , F_172 ( V_178 ) ) ) ) {
F_176 ( L_61 , V_2 , V_178 ) ;
goto V_194;
}
F_16 ( V_2 , V_223 ) ;
F_9 ( V_2 , V_224 ) ;
}
if ( F_3 ( V_210 & V_225 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_85 ( V_2 , V_210 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_216 ( struct V_1 * V_2 ,
T_5 V_210 , unsigned long V_18 )
{
return F_211 ( V_2 , V_210 , V_128 , V_18 ) ;
}
void * F_217 ( struct V_1 * V_2 , T_5 V_210 )
{
void * V_226 = F_216 ( V_2 , V_210 , V_227 ) ;
F_218 ( V_227 , V_226 , V_2 -> V_21 ,
V_2 -> V_15 , V_210 ) ;
return V_226 ;
}
void * F_219 ( struct V_1 * V_2 , T_5 V_210 , T_1 V_15 )
{
void * V_226 = F_216 ( V_2 , V_210 , V_227 ) ;
F_220 ( V_227 , V_226 , V_15 , V_2 -> V_15 , V_210 ) ;
return V_226 ;
}
void * F_221 ( struct V_1 * V_2 , T_5 V_210 , int V_10 )
{
void * V_226 = F_211 ( V_2 , V_210 , V_10 , V_227 ) ;
F_222 ( V_227 , V_226 ,
V_2 -> V_21 , V_2 -> V_15 , V_210 , V_10 ) ;
return V_226 ;
}
void * F_223 ( struct V_1 * V_2 ,
T_5 V_210 ,
int V_10 , T_1 V_15 )
{
void * V_226 = F_211 ( V_2 , V_210 , V_10 , V_227 ) ;
F_224 ( V_227 , V_226 ,
V_15 , V_2 -> V_15 , V_210 , V_10 ) ;
return V_226 ;
}
static void F_225 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_193 ;
void * * V_12 = ( void * ) V_29 ;
int V_228 ;
struct V_11 V_160 ;
unsigned long V_35 ;
struct V_9 * V_40 = NULL ;
unsigned long V_229 ( V_3 ) ;
F_9 ( V_2 , V_230 ) ;
if ( F_1 ( V_2 ) &&
! ( V_40 = F_113 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_40 ) ) {
F_199 ( & V_40 -> V_110 , V_3 ) ;
V_40 = NULL ;
}
V_193 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
F_21 ( V_2 , V_12 , V_193 ) ;
V_160 . V_35 = V_35 ;
V_228 = V_160 . V_36 ;
V_160 . V_24 -- ;
if ( ( ! V_160 . V_24 || ! V_193 ) && ! V_228 ) {
if ( F_4 ( V_2 ) && ! V_193 ) {
V_160 . V_36 = 1 ;
} else {
V_40 = F_12 ( V_2 , F_128 ( V_11 ) ) ;
F_197 ( & V_40 -> V_110 , V_3 ) ;
}
}
} while ( ! F_41 ( V_2 , V_11 ,
V_193 , V_35 ,
V_12 , V_160 . V_35 ,
L_62 ) );
if ( F_102 ( ! V_40 ) ) {
if ( V_160 . V_36 && ! V_228 ) {
F_157 ( V_2 , V_11 , 1 ) ;
F_9 ( V_2 , V_231 ) ;
}
if ( V_228 )
F_9 ( V_2 , V_232 ) ;
return;
}
if ( F_3 ( ! V_160 . V_24 && V_40 -> V_156 > V_2 -> V_176 ) )
goto V_233;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_193 ) ) {
if ( F_1 ( V_2 ) )
F_96 ( V_2 , V_40 , V_11 ) ;
F_148 ( V_40 , V_11 , V_157 ) ;
F_9 ( V_2 , V_201 ) ;
}
F_199 ( & V_40 -> V_110 , V_3 ) ;
return;
V_233:
if ( V_193 ) {
F_150 ( V_40 , V_11 ) ;
F_9 ( V_2 , V_234 ) ;
} else {
F_96 ( V_2 , V_40 , V_11 ) ;
}
F_199 ( & V_40 -> V_110 , V_3 ) ;
F_9 ( V_2 , V_197 ) ;
F_145 ( V_2 , V_11 ) ;
}
static T_2 void F_226 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_161 * V_162 ;
unsigned long V_178 ;
F_88 ( V_2 , V_29 ) ;
V_194:
F_213 () ;
V_162 = F_205 ( V_2 -> V_8 ) ;
V_178 = V_162 -> V_178 ;
F_214 () ;
if ( F_102 ( V_11 == V_162 -> V_11 ) ) {
F_21 ( V_2 , V_12 , V_162 -> V_44 ) ;
if ( F_3 ( ! F_215 (
V_2 -> V_8 -> V_44 , V_2 -> V_8 -> V_178 ,
V_162 -> V_44 , V_178 ,
V_12 , F_172 ( V_178 ) ) ) ) {
F_176 ( L_63 , V_2 , V_178 ) ;
goto V_194;
}
F_9 ( V_2 , V_235 ) ;
} else
F_225 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_227 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_228 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_226 ( V_2 , F_141 ( V_29 ) , V_29 , V_227 ) ;
F_229 ( V_227 , V_29 ) ;
}
static inline int F_230 ( int V_15 , int V_236 ,
int V_237 , int V_238 , int V_26 )
{
int V_25 ;
int V_239 ;
int V_240 = V_241 ;
if ( F_24 ( V_240 , V_15 , V_26 ) > V_102 )
return F_202 ( V_15 * V_102 ) - 1 ;
for ( V_25 = F_231 ( V_240 ,
F_232 ( V_236 * V_15 - 1 ) - V_242 ) ;
V_25 <= V_237 ; V_25 ++ ) {
unsigned long V_243 = V_27 << V_25 ;
if ( V_243 < V_236 * V_15 + V_26 )
continue;
V_239 = ( V_243 - V_26 ) % V_15 ;
if ( V_239 <= V_243 / V_238 )
break;
}
return V_25 ;
}
static inline int F_233 ( int V_15 , int V_26 )
{
int V_25 ;
int V_236 ;
int V_244 ;
int V_101 ;
V_236 = V_245 ;
if ( ! V_236 )
V_236 = 4 * ( F_232 ( V_246 ) + 1 ) ;
V_101 = F_24 ( V_247 , V_15 , V_26 ) ;
V_236 = V_134 ( V_236 , V_101 ) ;
while ( V_236 > 1 ) {
V_244 = 16 ;
while ( V_244 >= 4 ) {
V_25 = F_230 ( V_15 , V_236 ,
V_247 , V_244 , V_26 ) ;
if ( V_25 <= V_247 )
return V_25 ;
V_244 /= 2 ;
}
V_236 -- ;
}
V_25 = F_230 ( V_15 , 1 , V_247 , 1 , V_26 ) ;
if ( V_25 <= V_247 )
return V_25 ;
V_25 = F_230 ( V_15 , 1 , V_248 , 1 , V_26 ) ;
if ( V_25 < V_248 )
return V_25 ;
return - V_249 ;
}
static void
F_234 ( struct V_9 * V_40 )
{
V_40 -> V_156 = 0 ;
F_235 ( & V_40 -> V_110 ) ;
F_236 ( & V_40 -> V_158 ) ;
#ifdef F_2
F_237 ( & V_40 -> V_113 , 0 ) ;
F_237 ( & V_40 -> V_114 , 0 ) ;
F_236 ( & V_40 -> V_112 ) ;
#endif
}
static inline int F_238 ( struct V_1 * V_2 )
{
F_239 ( V_250 <
V_251 * sizeof( struct V_161 ) ) ;
V_2 -> V_8 = F_240 ( sizeof( struct V_161 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_179 ( V_2 ) ;
return 1 ;
}
static void F_241 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_40 ;
F_127 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_126 ( V_9 , V_252 , V_10 ) ;
F_127 ( ! V_11 ) ;
if ( F_128 ( V_11 ) != V_10 ) {
F_40 ( V_51 L_64
L_65 , V_10 ) ;
F_40 ( V_51 L_66
L_67 ) ;
}
V_40 = V_11 -> V_44 ;
F_127 ( ! V_40 ) ;
V_11 -> V_44 = F_15 ( V_9 , V_40 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_36 = 0 ;
V_9 -> V_10 [ V_10 ] = V_40 ;
#ifdef F_2
F_66 ( V_9 , V_40 , V_97 ) ;
F_53 ( V_9 , V_40 ) ;
#endif
F_234 ( V_40 ) ;
F_101 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_146 ( V_40 , V_11 , V_190 ) ;
}
static void F_242 ( struct V_1 * V_2 )
{
int V_10 ;
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = V_2 -> V_10 [ V_10 ] ;
if ( V_40 )
F_227 ( V_9 , V_40 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_244 ( struct V_1 * V_2 )
{
int V_10 ;
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 ;
if ( V_253 == V_254 ) {
F_241 ( V_10 ) ;
continue;
}
V_40 = F_221 ( V_9 ,
V_255 , V_10 ) ;
if ( ! V_40 ) {
F_242 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_40 ;
F_234 ( V_40 ) ;
}
return 1 ;
}
static void F_245 ( struct V_1 * V_2 , unsigned long V_134 )
{
if ( V_134 < V_256 )
V_134 = V_256 ;
else if ( V_134 > V_257 )
V_134 = V_257 ;
V_2 -> V_176 = V_134 ;
}
static int F_246 ( struct V_1 * V_2 , int V_258 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_247 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_112 )
V_2 -> V_3 |= V_81 ;
else
V_2 -> V_3 &= ~ V_81 ;
if ( ( V_3 & V_19 ) && V_15 == V_2 -> V_21 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_24 = V_15 ;
if ( ( ( V_3 & ( V_22 | V_20 ) ) ||
V_2 -> F_112 ) ) {
V_2 -> V_16 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_23 )
V_15 += 2 * sizeof( struct V_53 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_15 = F_247 ( V_15 , V_2 -> V_259 ) ;
V_2 -> V_15 = V_15 ;
if ( V_258 >= 0 )
V_25 = V_258 ;
else
V_25 = F_233 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_130 = 0 ;
if ( V_25 )
V_2 -> V_130 |= V_260 ;
if ( V_2 -> V_3 & V_261 )
V_2 -> V_130 |= V_262 ;
if ( V_2 -> V_3 & V_139 )
V_2 -> V_130 |= V_263 ;
V_2 -> V_126 = F_25 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_134 = F_25 ( F_202 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_27 ( V_2 -> V_126 ) > F_27 ( V_2 -> F_231 ) )
V_2 -> F_231 = V_2 -> V_126 ;
return ! ! F_27 ( V_2 -> V_126 ) ;
}
static int F_248 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_111 ( V_2 -> V_15 , V_3 , V_2 -> V_47 , V_2 -> F_112 ) ;
V_2 -> V_26 = 0 ;
if ( V_152 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_150 ) ;
if ( ! F_246 ( V_2 , - 1 ) )
goto error;
if ( V_122 ) {
if ( F_202 ( V_2 -> V_15 ) > F_202 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_264 ;
V_2 -> V_16 = 0 ;
if ( ! F_246 ( V_2 , - 1 ) )
goto error;
}
}
#if F_36 ( V_41 ) && \
F_36 ( V_42 )
if ( F_249 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_43 ;
#endif
F_245 ( V_2 , F_250 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_4 ( V_2 ) )
V_2 -> V_167 = 0 ;
else if ( V_2 -> V_15 >= V_27 )
V_2 -> V_167 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_167 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_167 = 13 ;
else
V_2 -> V_167 = 30 ;
#ifdef F_160
V_2 -> V_175 = 1000 ;
#endif
if ( ! F_244 ( V_2 ) )
goto error;
if ( F_238 ( V_2 ) )
return 0 ;
F_242 ( V_2 ) ;
error:
if ( V_3 & V_265 )
F_251 ( L_68
L_69 ,
V_2 -> V_47 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_26 ( V_2 -> V_126 ) , V_2 -> V_16 , V_3 ) ;
return - V_266 ;
}
static void F_252 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_49 )
{
#ifdef F_2
void * V_18 = F_14 ( V_11 ) ;
void * V_5 ;
unsigned long * V_48 = F_253 ( F_254 ( V_11 -> V_14 ) *
sizeof( long ) , V_209 ) ;
if ( ! V_48 )
return;
F_65 ( V_2 , V_11 , V_49 , V_2 -> V_47 ) ;
F_28 ( V_11 ) ;
F_44 ( V_2 , V_11 , V_48 ) ;
F_132 (p, s, addr, page->objects) {
if ( ! F_255 ( F_22 ( V_5 , V_2 , V_18 ) , V_48 ) ) {
F_40 ( V_51 L_70 ,
V_5 , V_5 - V_18 ) ;
F_55 ( V_2 , V_5 ) ;
}
}
F_30 ( V_11 ) ;
F_256 ( V_48 ) ;
#endif
}
static void F_257 ( struct V_1 * V_2 , struct V_9 * V_40 )
{
struct V_11 * V_11 , * V_151 ;
F_155 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_149 ( V_40 , V_11 ) ;
F_145 ( V_2 , V_11 ) ;
} else {
F_252 ( V_2 , V_11 ,
L_71 ) ;
}
}
}
static inline int F_258 ( struct V_1 * V_2 )
{
int V_10 ;
F_191 ( V_2 ) ;
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
F_257 ( V_2 , V_40 ) ;
if ( V_40 -> V_156 || F_98 ( V_2 , V_10 ) )
return 1 ;
}
F_259 ( V_2 -> V_8 ) ;
F_242 ( V_2 ) ;
return 0 ;
}
int F_260 ( struct V_1 * V_2 )
{
return F_258 ( V_2 ) ;
}
static int T_7 F_261 ( char * V_117 )
{
F_262 ( & V_117 , & V_241 ) ;
return 1 ;
}
static int T_7 F_263 ( char * V_117 )
{
F_262 ( & V_117 , & V_247 ) ;
V_247 = V_134 ( V_247 , V_248 - 1 ) ;
return 1 ;
}
static int T_7 F_264 ( char * V_117 )
{
F_262 ( & V_117 , & V_245 ) ;
return 1 ;
}
static int T_7 F_265 ( char * V_117 )
{
V_267 = 1 ;
return 1 ;
}
void * F_266 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_268 ) )
return F_267 ( V_15 , V_3 ) ;
V_2 = F_268 ( V_15 , V_3 ) ;
if ( F_3 ( F_269 ( V_2 ) ) )
return V_2 ;
V_226 = F_216 ( V_2 , V_3 , V_227 ) ;
F_220 ( V_227 , V_226 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_226 ;
}
static void * F_270 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_104 = NULL ;
V_3 |= V_260 | V_127 | V_269 ;
V_11 = F_271 ( V_10 , V_3 , F_202 ( V_15 ) ) ;
if ( V_11 )
V_104 = F_14 ( V_11 ) ;
F_77 ( V_104 , V_15 , V_3 ) ;
return V_104 ;
}
void * F_272 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_268 ) ) {
V_226 = F_270 ( V_15 , V_3 , V_10 ) ;
F_224 ( V_227 , V_226 ,
V_15 , V_27 << F_202 ( V_15 ) ,
V_3 , V_10 ) ;
return V_226 ;
}
V_2 = F_268 ( V_15 , V_3 ) ;
if ( F_3 ( F_269 ( V_2 ) ) )
return V_2 ;
V_226 = F_211 ( V_2 , V_3 , V_10 , V_227 ) ;
F_224 ( V_227 , V_226 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_226 ;
}
T_1 F_273 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_270 ) )
return 0 ;
V_11 = F_141 ( V_12 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
F_152 ( ! F_274 ( V_11 ) ) ;
return V_27 << F_72 ( V_11 ) ;
}
return F_23 ( V_11 -> V_146 ) ;
}
void F_256 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_275 ( V_227 , V_29 ) ;
if ( F_3 ( F_269 ( V_29 ) ) )
return;
V_11 = F_141 ( V_29 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
F_127 ( ! F_274 ( V_11 ) ) ;
F_79 ( V_29 ) ;
F_139 ( V_11 , F_72 ( V_11 ) ) ;
return;
}
F_226 ( V_11 -> V_146 , V_11 , V_12 , V_227 ) ;
}
int F_276 ( struct V_1 * V_2 )
{
int V_10 ;
int V_58 ;
struct V_9 * V_40 ;
struct V_11 * V_11 ;
struct V_11 * V_73 ;
int V_14 = F_27 ( V_2 -> F_231 ) ;
struct V_153 * V_271 =
F_277 ( sizeof( struct V_153 ) * V_14 , V_255 ) ;
unsigned long V_3 ;
if ( ! V_271 )
return - V_272 ;
F_191 ( V_2 ) ;
F_243 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_10 ) ;
if ( ! V_40 -> V_156 )
continue;
for ( V_58 = 0 ; V_58 < V_14 ; V_58 ++ )
F_236 ( V_271 + V_58 ) ;
F_197 ( & V_40 -> V_110 , V_3 ) ;
F_155 (page, t, &n->partial, lru) {
F_278 ( & V_11 -> V_111 , V_271 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_40 -> V_156 -- ;
}
for ( V_58 = V_14 - 1 ; V_58 > 0 ; V_58 -- )
F_279 ( V_271 + V_58 , V_40 -> V_158 . V_273 ) ;
F_199 ( & V_40 -> V_110 , V_3 ) ;
F_155 (page, t, slabs_by_inuse, lru)
F_145 ( V_2 , V_11 ) ;
}
F_256 ( V_271 ) ;
return 0 ;
}
static int F_280 ( void * V_274 )
{
struct V_1 * V_2 ;
F_281 ( & V_275 ) ;
F_198 (s, &slab_caches, list)
F_276 ( V_2 ) ;
F_282 ( & V_275 ) ;
return 0 ;
}
static void F_283 ( void * V_274 )
{
struct V_9 * V_40 ;
struct V_1 * V_2 ;
struct V_276 * V_277 = V_274 ;
int V_278 ;
V_278 = V_277 -> V_279 ;
if ( V_278 < 0 )
return;
F_281 ( & V_275 ) ;
F_198 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_278 ) ;
if ( V_40 ) {
F_127 ( F_98 ( V_2 , V_278 ) ) ;
V_2 -> V_10 [ V_278 ] = NULL ;
F_227 ( V_9 , V_40 ) ;
}
}
F_282 ( & V_275 ) ;
}
static int F_284 ( void * V_274 )
{
struct V_9 * V_40 ;
struct V_1 * V_2 ;
struct V_276 * V_277 = V_274 ;
int V_211 = V_277 -> V_279 ;
int V_226 = 0 ;
if ( V_211 < 0 )
return 0 ;
F_281 ( & V_275 ) ;
F_198 (s, &slab_caches, list) {
V_40 = F_217 ( V_9 , V_255 ) ;
if ( ! V_40 ) {
V_226 = - V_272 ;
goto V_120;
}
F_234 ( V_40 ) ;
V_2 -> V_10 [ V_211 ] = V_40 ;
}
V_120:
F_282 ( & V_275 ) ;
return V_226 ;
}
static int F_285 ( struct V_280 * V_281 ,
unsigned long V_282 , void * V_274 )
{
int V_226 = 0 ;
switch ( V_282 ) {
case V_283 :
V_226 = F_284 ( V_274 ) ;
break;
case V_284 :
V_226 = F_280 ( V_274 ) ;
break;
case V_285 :
case V_286 :
F_283 ( V_274 ) ;
break;
case V_287 :
case V_288 :
break;
}
if ( V_226 )
V_226 = F_286 ( V_226 ) ;
else
V_226 = V_289 ;
return V_226 ;
}
static struct V_1 * T_7 F_287 ( struct V_1 * V_290 )
{
int V_10 ;
struct V_1 * V_2 = F_288 ( V_1 , V_252 ) ;
memcpy ( V_2 , V_290 , V_1 -> V_21 ) ;
F_188 ( V_2 , F_52 () ) ;
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_40 ) {
F_198 (p, &n->partial, lru)
V_5 -> V_146 = V_2 ;
#ifdef F_2
F_198 (p, &n->full, lru)
V_5 -> V_146 = V_2 ;
#endif
}
}
F_95 ( & V_2 -> V_291 , & V_292 ) ;
return V_2 ;
}
void T_7 F_289 ( void )
{
static V_293 struct V_1 V_294 ,
V_295 ;
if ( F_290 () )
V_247 = 0 ;
V_9 = & V_295 ;
V_1 = & V_294 ;
F_291 ( V_9 , L_72 ,
sizeof( struct V_9 ) , V_296 ) ;
F_292 ( & V_297 ) ;
V_253 = V_298 ;
F_291 ( V_1 , L_73 ,
F_293 ( struct V_1 , V_10 ) +
V_299 * sizeof( struct V_9 * ) ,
V_296 ) ;
V_1 = F_287 ( & V_294 ) ;
V_9 = F_287 ( & V_295 ) ;
F_294 ( 0 ) ;
#ifdef F_295
F_296 ( & V_300 ) ;
#endif
F_40 ( V_46
L_74
L_75 ,
F_297 () ,
V_241 , V_247 , V_245 ,
V_246 , V_299 ) ;
}
void T_7 F_298 ( void )
{
}
static int F_299 ( struct V_1 * V_2 )
{
if ( V_267 || ( V_2 -> V_3 & V_301 ) )
return 1 ;
if ( ! F_300 ( V_2 ) )
return 1 ;
if ( V_2 -> F_112 )
return 1 ;
if ( V_2 -> V_302 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_301 ( T_1 V_15 , T_1 V_259 ,
unsigned long V_3 , const char * V_47 , void (* F_112)( void * ) )
{
struct V_1 * V_2 ;
if ( V_267 || ( V_3 & V_301 ) )
return NULL ;
if ( F_112 )
return NULL ;
V_15 = F_247 ( V_15 , sizeof( void * ) ) ;
V_259 = F_302 ( V_3 , V_259 , V_15 ) ;
V_15 = F_247 ( V_15 , V_259 ) ;
V_3 = F_111 ( V_15 , V_3 , V_47 , NULL ) ;
F_198 (s, &slab_caches, list) {
if ( F_299 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_303 ) != ( V_2 -> V_3 & V_303 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_259 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_303 ( const char * V_47 , T_1 V_15 , T_1 V_259 ,
unsigned long V_3 , void (* F_112)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_301 ( V_15 , V_259 , V_3 , V_47 , F_112 ) ;
if ( V_2 ) {
int V_58 ;
struct V_1 * V_162 ;
V_2 -> V_302 ++ ;
V_2 -> V_21 = F_231 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_304 ( int , V_2 -> V_24 , F_247 ( V_15 , sizeof( void * ) ) ) ;
F_305 (i) {
V_162 = F_306 ( V_2 , V_58 ) ;
if ( ! V_162 )
continue;
V_162 -> V_21 = V_2 -> V_21 ;
V_162 -> V_24 = F_304 ( int , V_162 -> V_24 ,
F_247 ( V_15 , sizeof( void * ) ) ) ;
}
if ( F_7 ( V_2 , V_47 ) ) {
V_2 -> V_302 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_307 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_304 ;
V_304 = F_248 ( V_2 , V_3 ) ;
if ( V_304 )
return V_304 ;
if ( V_253 <= V_305 )
return 0 ;
F_8 ( V_2 ) ;
V_304 = F_6 ( V_2 ) ;
if ( V_304 )
F_258 ( V_2 ) ;
return V_304 ;
}
static int F_308 ( struct V_280 * V_306 ,
unsigned long V_282 , void * V_307 )
{
long V_66 = ( long ) V_307 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_282 ) {
case V_308 :
case V_309 :
case V_310 :
case V_311 :
F_281 ( & V_275 ) ;
F_198 (s, &slab_caches, list) {
F_42 ( V_3 ) ;
F_188 ( V_2 , V_66 ) ;
F_43 ( V_3 ) ;
}
F_282 ( & V_275 ) ;
break;
default:
break;
}
return V_289 ;
}
void * F_309 ( T_1 V_15 , T_5 V_210 , unsigned long V_312 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_268 ) )
return F_267 ( V_15 , V_210 ) ;
V_2 = F_268 ( V_15 , V_210 ) ;
if ( F_3 ( F_269 ( V_2 ) ) )
return V_2 ;
V_226 = F_216 ( V_2 , V_210 , V_312 ) ;
F_220 ( V_312 , V_226 , V_15 , V_2 -> V_15 , V_210 ) ;
return V_226 ;
}
void * F_310 ( T_1 V_15 , T_5 V_210 ,
int V_10 , unsigned long V_312 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_268 ) ) {
V_226 = F_270 ( V_15 , V_210 , V_10 ) ;
F_224 ( V_312 , V_226 ,
V_15 , V_27 << F_202 ( V_15 ) ,
V_210 , V_10 ) ;
return V_226 ;
}
V_2 = F_268 ( V_15 , V_210 ) ;
if ( F_3 ( F_269 ( V_2 ) ) )
return V_2 ;
V_226 = F_211 ( V_2 , V_210 , V_10 , V_312 ) ;
F_224 ( V_312 , V_226 , V_15 , V_2 -> V_15 , V_210 , V_10 ) ;
return V_226 ;
}
static int F_311 ( struct V_11 * V_11 )
{
return V_11 -> V_24 ;
}
static int F_312 ( struct V_11 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_313 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_48 )
{
void * V_5 ;
void * V_18 = F_14 ( V_11 ) ;
if ( ! F_74 ( V_2 , V_11 ) ||
! F_76 ( V_2 , V_11 , NULL ) )
return 0 ;
F_314 ( V_48 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_48 ) ;
F_132 (p, s, addr, page->objects) {
if ( F_255 ( F_22 ( V_5 , V_2 , V_18 ) , V_48 ) )
if ( ! F_73 ( V_2 , V_11 , V_5 , V_115 ) )
return 0 ;
}
F_132 (p, s, addr, page->objects)
if ( ! F_255 ( F_22 ( V_5 , V_2 , V_18 ) , V_48 ) )
if ( ! F_73 ( V_2 , V_11 , V_5 , V_97 ) )
return 0 ;
return 1 ;
}
static void F_315 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_48 )
{
F_28 ( V_11 ) ;
F_313 ( V_2 , V_11 , V_48 ) ;
F_30 ( V_11 ) ;
}
static int F_316 ( struct V_1 * V_2 ,
struct V_9 * V_40 , unsigned long * V_48 )
{
unsigned long V_313 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_197 ( & V_40 -> V_110 , V_3 ) ;
F_198 (page, &n->partial, lru) {
F_315 ( V_2 , V_11 , V_48 ) ;
V_313 ++ ;
}
if ( V_313 != V_40 -> V_156 )
F_40 ( V_51 L_76
L_77 , V_2 -> V_47 , V_313 , V_40 -> V_156 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_120;
F_198 (page, &n->full, lru) {
F_315 ( V_2 , V_11 , V_48 ) ;
V_313 ++ ;
}
if ( V_313 != F_99 ( & V_40 -> V_113 ) )
F_40 ( V_51 L_78
L_77 , V_2 -> V_47 , V_313 ,
F_99 ( & V_40 -> V_113 ) ) ;
V_120:
F_199 ( & V_40 -> V_110 , V_3 ) ;
return V_313 ;
}
static long F_317 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_313 = 0 ;
unsigned long * V_48 = F_277 ( F_254 ( F_27 ( V_2 -> F_231 ) ) *
sizeof( unsigned long ) , V_255 ) ;
if ( ! V_48 )
return - V_272 ;
F_191 ( V_2 ) ;
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
V_313 += F_316 ( V_2 , V_40 , V_48 ) ;
}
F_256 ( V_48 ) ;
return V_313 ;
}
static void F_318 ( struct V_314 * V_73 )
{
if ( V_73 -> F_231 )
F_319 ( ( unsigned long ) V_73 -> V_315 ,
F_202 ( sizeof( struct V_316 ) * V_73 -> F_231 ) ) ;
}
static int F_320 ( struct V_314 * V_73 , unsigned long F_231 , T_5 V_3 )
{
struct V_316 * V_187 ;
int V_25 ;
V_25 = F_202 ( sizeof( struct V_316 ) * F_231 ) ;
V_187 = ( void * ) F_321 ( V_3 , V_25 ) ;
if ( ! V_187 )
return 0 ;
if ( V_73 -> V_313 ) {
memcpy ( V_187 , V_73 -> V_315 , sizeof( struct V_316 ) * V_73 -> V_313 ) ;
F_318 ( V_73 ) ;
}
V_73 -> F_231 = F_231 ;
V_73 -> V_315 = V_187 ;
return 1 ;
}
static int F_322 ( struct V_314 * V_73 , struct V_1 * V_2 ,
const struct V_53 * V_53 )
{
long V_89 , V_93 , V_317 ;
struct V_316 * V_187 ;
unsigned long V_318 ;
unsigned long V_319 = V_70 - V_53 -> V_69 ;
V_89 = - 1 ;
V_93 = V_73 -> V_313 ;
for ( ; ; ) {
V_317 = V_89 + ( V_93 - V_89 + 1 ) / 2 ;
if ( V_317 == V_93 )
break;
V_318 = V_73 -> V_315 [ V_317 ] . V_18 ;
if ( V_53 -> V_18 == V_318 ) {
V_187 = & V_73 -> V_315 [ V_317 ] ;
V_187 -> V_313 ++ ;
if ( V_53 -> V_69 ) {
V_187 -> V_320 += V_319 ;
if ( V_319 < V_187 -> V_321 )
V_187 -> V_321 = V_319 ;
if ( V_319 > V_187 -> V_322 )
V_187 -> V_322 = V_319 ;
if ( V_53 -> V_67 < V_187 -> V_323 )
V_187 -> V_323 = V_53 -> V_67 ;
if ( V_53 -> V_67 > V_187 -> V_324 )
V_187 -> V_324 = V_53 -> V_67 ;
F_323 ( V_53 -> V_66 ,
F_324 ( V_187 -> V_325 ) ) ;
}
F_325 ( F_128 ( F_326 ( V_53 ) ) , V_187 -> V_326 ) ;
return 1 ;
}
if ( V_53 -> V_18 < V_318 )
V_93 = V_317 ;
else
V_89 = V_317 ;
}
if ( V_73 -> V_313 >= V_73 -> F_231 && ! F_320 ( V_73 , 2 * V_73 -> F_231 , V_209 ) )
return 0 ;
V_187 = V_73 -> V_315 + V_317 ;
if ( V_317 < V_73 -> V_313 )
memmove ( V_187 + 1 , V_187 ,
( V_73 -> V_313 - V_317 ) * sizeof( struct V_316 ) ) ;
V_73 -> V_313 ++ ;
V_187 -> V_313 = 1 ;
V_187 -> V_18 = V_53 -> V_18 ;
V_187 -> V_320 = V_319 ;
V_187 -> V_321 = V_319 ;
V_187 -> V_322 = V_319 ;
V_187 -> V_323 = V_53 -> V_67 ;
V_187 -> V_324 = V_53 -> V_67 ;
F_327 ( F_324 ( V_187 -> V_325 ) ) ;
F_323 ( V_53 -> V_66 , F_324 ( V_187 -> V_325 ) ) ;
F_328 ( V_187 -> V_326 ) ;
F_325 ( F_128 ( F_326 ( V_53 ) ) , V_187 -> V_326 ) ;
return 1 ;
}
static void F_329 ( struct V_314 * V_73 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_54 V_55 ,
unsigned long * V_48 )
{
void * V_18 = F_14 ( V_11 ) ;
void * V_5 ;
F_314 ( V_48 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_48 ) ;
F_132 (p, s, addr, page->objects)
if ( ! F_255 ( F_22 ( V_5 , V_2 , V_18 ) , V_48 ) )
F_322 ( V_73 , V_2 , F_48 ( V_2 , V_5 , V_55 ) ) ;
}
static int F_330 ( struct V_1 * V_2 , char * V_75 ,
enum V_54 V_55 )
{
int V_327 = 0 ;
unsigned long V_58 ;
struct V_314 V_73 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_48 = F_277 ( F_254 ( F_27 ( V_2 -> F_231 ) ) *
sizeof( unsigned long ) , V_255 ) ;
if ( ! V_48 || ! F_320 ( & V_73 , V_27 / sizeof( struct V_316 ) ,
V_328 ) ) {
F_256 ( V_48 ) ;
return sprintf ( V_75 , L_79 ) ;
}
F_191 ( V_2 ) ;
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_99 ( & V_40 -> V_113 ) )
continue;
F_197 ( & V_40 -> V_110 , V_3 ) ;
F_198 (page, &n->partial, lru)
F_329 ( & V_73 , V_2 , V_11 , V_55 , V_48 ) ;
F_198 (page, &n->full, lru)
F_329 ( & V_73 , V_2 , V_11 , V_55 , V_48 ) ;
F_199 ( & V_40 -> V_110 , V_3 ) ;
}
for ( V_58 = 0 ; V_58 < V_73 . V_313 ; V_58 ++ ) {
struct V_316 * V_187 = & V_73 . V_315 [ V_58 ] ;
if ( V_327 > V_27 - V_329 - 100 )
break;
V_327 += sprintf ( V_75 + V_327 , L_80 , V_187 -> V_313 ) ;
if ( V_187 -> V_18 )
V_327 += sprintf ( V_75 + V_327 , L_81 , ( void * ) V_187 -> V_18 ) ;
else
V_327 += sprintf ( V_75 + V_327 , L_82 ) ;
if ( V_187 -> V_320 != V_187 -> V_321 ) {
V_327 += sprintf ( V_75 + V_327 , L_83 ,
V_187 -> V_321 ,
( long ) F_331 ( V_187 -> V_320 , V_187 -> V_313 ) ,
V_187 -> V_322 ) ;
} else
V_327 += sprintf ( V_75 + V_327 , L_84 ,
V_187 -> V_321 ) ;
if ( V_187 -> V_323 != V_187 -> V_324 )
V_327 += sprintf ( V_75 + V_327 , L_85 ,
V_187 -> V_323 , V_187 -> V_324 ) ;
else
V_327 += sprintf ( V_75 + V_327 , L_86 ,
V_187 -> V_323 ) ;
if ( F_332 () > 1 &&
! F_333 ( F_324 ( V_187 -> V_325 ) ) &&
V_327 < V_27 - 60 ) {
V_327 += sprintf ( V_75 + V_327 , L_87 ) ;
V_327 += F_334 ( V_75 + V_327 ,
V_27 - V_327 - 50 ,
F_324 ( V_187 -> V_325 ) ) ;
}
if ( V_330 > 1 && ! F_335 ( V_187 -> V_326 ) &&
V_327 < V_27 - 60 ) {
V_327 += sprintf ( V_75 + V_327 , L_88 ) ;
V_327 += F_336 ( V_75 + V_327 ,
V_27 - V_327 - 50 ,
V_187 -> V_326 ) ;
}
V_327 += sprintf ( V_75 + V_327 , L_89 ) ;
}
F_318 ( & V_73 ) ;
F_256 ( V_48 ) ;
if ( ! V_73 . V_313 )
V_327 += sprintf ( V_75 , L_90 ) ;
return V_327 ;
}
static void F_337 ( void )
{
T_3 * V_5 ;
F_239 ( V_331 > 16 || V_251 < 10 ) ;
F_40 ( V_51 L_91 ) ;
F_40 ( V_51 L_92 ) ;
F_40 ( V_51 L_93 ) ;
V_5 = F_253 ( 16 , V_255 ) ;
V_5 [ 16 ] = 0x12 ;
F_40 ( V_51 L_94
L_95 , V_5 + 16 ) ;
F_317 ( V_332 [ 4 ] ) ;
V_5 = F_253 ( 32 , V_255 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_40 ( V_51 L_96
L_97 , V_5 ) ;
F_40 ( V_51
L_98 ) ;
F_317 ( V_332 [ 5 ] ) ;
V_5 = F_253 ( 64 , V_255 ) ;
V_5 += 64 + ( F_162 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_40 ( V_51 L_99 ,
V_5 ) ;
F_40 ( V_51
L_98 ) ;
F_317 ( V_332 [ 6 ] ) ;
F_40 ( V_51 L_100 ) ;
V_5 = F_253 ( 128 , V_255 ) ;
F_256 ( V_5 ) ;
* V_5 = 0x78 ;
F_40 ( V_51 L_101 , V_5 ) ;
F_317 ( V_332 [ 7 ] ) ;
V_5 = F_253 ( 256 , V_255 ) ;
F_256 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_40 ( V_51 L_102 ,
V_5 ) ;
F_317 ( V_332 [ 8 ] ) ;
V_5 = F_253 ( 512 , V_255 ) ;
F_256 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_40 ( V_51 L_103 , V_5 ) ;
F_317 ( V_332 [ 9 ] ) ;
}
static void F_337 ( void ) {}
static T_9 F_338 ( struct V_1 * V_2 ,
char * V_75 , unsigned long V_3 )
{
unsigned long V_333 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_326 ;
V_326 = F_253 ( sizeof( unsigned long ) * V_299 , V_255 ) ;
if ( ! V_326 )
return - V_272 ;
if ( V_3 & V_334 ) {
int V_66 ;
F_180 (cpu) {
struct V_161 * V_162 = F_181 ( V_2 -> V_8 ,
V_66 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_339 ( V_162 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_128 ( V_11 ) ;
if ( V_3 & V_335 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_336 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_333 += V_29 ;
V_326 [ V_10 ] += V_29 ;
V_11 = F_339 ( V_162 -> V_158 ) ;
if ( V_11 ) {
V_10 = F_128 ( V_11 ) ;
if ( V_3 & V_335 )
F_340 ( 1 ) ;
else if ( V_3 & V_336 )
F_340 ( 1 ) ;
else
V_29 = V_11 -> V_138 ;
V_333 += V_29 ;
V_326 [ V_10 ] += V_29 ;
}
}
}
F_341 () ;
#ifdef F_2
if ( V_3 & V_337 ) {
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( V_3 & V_335 )
V_29 = F_99 ( & V_40 -> V_114 ) ;
else if ( V_3 & V_336 )
V_29 = F_99 ( & V_40 -> V_114 ) -
F_195 ( V_40 , F_194 ) ;
else
V_29 = F_99 ( & V_40 -> V_113 ) ;
V_333 += V_29 ;
V_326 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_338 ) {
F_243 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( V_3 & V_335 )
V_29 = F_195 ( V_40 , F_312 ) ;
else if ( V_3 & V_336 )
V_29 = F_195 ( V_40 , F_311 ) ;
else
V_29 = V_40 -> V_156 ;
V_333 += V_29 ;
V_326 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_75 , L_104 , V_333 ) ;
#ifdef F_160
F_243 (node, N_NORMAL_MEMORY)
if ( V_326 [ V_10 ] )
V_29 += sprintf ( V_75 + V_29 , L_105 ,
V_10 , V_326 [ V_10 ] ) ;
#endif
F_342 () ;
F_256 ( V_326 ) ;
return V_29 + sprintf ( V_75 + V_29 , L_89 ) ;
}
static int F_343 ( struct V_1 * V_2 )
{
int V_10 ;
F_203 (node) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( ! V_40 )
continue;
if ( F_99 ( & V_40 -> V_114 ) )
return 1 ;
}
return 0 ;
}
static T_9 F_344 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_15 ) ;
}
static T_9 F_345 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_259 ) ;
}
static T_9 F_346 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_21 ) ;
}
static T_9 F_347 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , F_27 ( V_2 -> V_126 ) ) ;
}
static T_9 F_348 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_25 ;
int V_304 ;
V_304 = F_349 ( V_75 , 10 , & V_25 ) ;
if ( V_304 )
return V_304 ;
if ( V_25 > V_247 || V_25 < V_241 )
return - V_266 ;
F_246 ( V_2 , V_25 ) ;
return V_50 ;
}
static T_9 F_350 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , F_26 ( V_2 -> V_126 ) ) ;
}
static T_9 F_351 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_107 , V_2 -> V_176 ) ;
}
static T_9 F_352 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_134 ;
int V_304 ;
V_304 = F_349 ( V_75 , 10 , & V_134 ) ;
if ( V_304 )
return V_304 ;
F_245 ( V_2 , V_134 ) ;
return V_50 ;
}
static T_9 F_353 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_108 , V_2 -> V_167 ) ;
}
static T_9 F_354 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_14 ;
int V_304 ;
V_304 = F_349 ( V_75 , 10 , & V_14 ) ;
if ( V_304 )
return V_304 ;
if ( V_14 && ! F_4 ( V_2 ) )
return - V_266 ;
V_2 -> V_167 = V_14 ;
F_191 ( V_2 ) ;
return V_50 ;
}
static T_9 F_355 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! V_2 -> F_112 )
return 0 ;
return sprintf ( V_75 , L_109 , V_2 -> F_112 ) ;
}
static T_9 F_356 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_302 - 1 ) ;
}
static T_9 F_357 ( struct V_1 * V_2 , char * V_75 )
{
return F_338 ( V_2 , V_75 , V_338 ) ;
}
static T_9 F_358 ( struct V_1 * V_2 , char * V_75 )
{
return F_338 ( V_2 , V_75 , V_334 ) ;
}
static T_9 F_359 ( struct V_1 * V_2 , char * V_75 )
{
return F_338 ( V_2 , V_75 , V_337 | V_336 ) ;
}
static T_9 F_360 ( struct V_1 * V_2 , char * V_75 )
{
return F_338 ( V_2 , V_75 , V_338 | V_336 ) ;
}
static T_9 F_361 ( struct V_1 * V_2 , char * V_75 )
{
int V_14 = 0 ;
int V_138 = 0 ;
int V_66 ;
int V_327 ;
F_362 (cpu) {
struct V_11 * V_11 = F_181 ( V_2 -> V_8 , V_66 ) -> V_158 ;
if ( V_11 ) {
V_138 += V_11 -> V_138 ;
V_14 += V_11 -> V_204 ;
}
}
V_327 = sprintf ( V_75 , L_110 , V_14 , V_138 ) ;
#ifdef F_295
F_362 (cpu) {
struct V_11 * V_11 = F_181 ( V_2 -> V_8 , V_66 ) -> V_158 ;
if ( V_11 && V_327 < V_27 - 20 )
V_327 += sprintf ( V_75 + V_327 , L_111 , V_66 ,
V_11 -> V_204 , V_11 -> V_138 ) ;
}
#endif
return V_327 + sprintf ( V_75 + V_327 , L_89 ) ;
}
static T_9 F_363 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_139 ) ) ;
}
static T_9 F_364 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_139 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_139 ;
return V_50 ;
}
static T_9 F_365 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_296 ) ) ;
}
static T_9 F_366 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_261 ) ) ;
}
static T_9 F_367 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_9 F_368 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_26 ) ;
}
static T_9 F_369 ( struct V_1 * V_2 , char * V_75 )
{
return F_338 ( V_2 , V_75 , V_337 ) ;
}
static T_9 F_370 ( struct V_1 * V_2 , char * V_75 )
{
return F_338 ( V_2 , V_75 , V_337 | V_335 ) ;
}
static T_9 F_371 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_123 ) ) ;
}
static T_9 F_372 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_123 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_123 ;
}
return V_50 ;
}
static T_9 F_373 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_103 ) ) ;
}
static T_9 F_374 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_103 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_103 ;
}
return V_50 ;
}
static T_9 F_375 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_9 F_376 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_343 ( V_2 ) )
return - V_339 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_19 ;
}
F_246 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_377 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_378 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_343 ( V_2 ) )
return - V_339 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_20 ;
}
F_246 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_9 F_380 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_343 ( V_2 ) )
return - V_339 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_23 ;
}
F_246 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_381 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_9 F_382 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
int V_226 = - V_266 ;
if ( V_75 [ 0 ] == '1' ) {
V_226 = F_317 ( V_2 ) ;
if ( V_226 >= 0 )
V_226 = V_50 ;
}
return V_226 ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_249 ;
return F_330 ( V_2 , V_75 , V_72 ) ;
}
static T_9 F_384 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_249 ;
return F_330 ( V_2 , V_75 , V_71 ) ;
}
static T_9 F_385 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_124 ) ) ;
}
static T_9 F_386 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_124 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_124 ;
return V_50 ;
}
static T_9 F_387 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_9 F_388 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( V_75 [ 0 ] == '1' ) {
int V_340 = F_276 ( V_2 ) ;
if ( V_340 )
return V_340 ;
} else
return - V_266 ;
return V_50 ;
}
static T_9 F_389 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_175 / 10 ) ;
}
static T_9 F_390 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_341 ;
int V_304 ;
V_304 = F_349 ( V_75 , 10 , & V_341 ) ;
if ( V_304 )
return V_304 ;
if ( V_341 <= 100 )
V_2 -> V_175 = V_341 * 10 ;
return V_50 ;
}
static int F_391 ( struct V_1 * V_2 , char * V_75 , enum V_6 V_7 )
{
unsigned long V_342 = 0 ;
int V_66 ;
int V_327 ;
int * V_85 = F_277 ( V_246 * sizeof( int ) , V_255 ) ;
if ( ! V_85 )
return - V_272 ;
F_362 (cpu) {
unsigned V_29 = F_181 ( V_2 -> V_8 , V_66 ) -> F_9 [ V_7 ] ;
V_85 [ V_66 ] = V_29 ;
V_342 += V_29 ;
}
V_327 = sprintf ( V_75 , L_104 , V_342 ) ;
#ifdef F_295
F_362 (cpu) {
if ( V_85 [ V_66 ] && V_327 < V_27 - 20 )
V_327 += sprintf ( V_75 + V_327 , L_112 , V_66 , V_85 [ V_66 ] ) ;
}
#endif
F_256 ( V_85 ) ;
return V_327 + sprintf ( V_75 + V_327 , L_89 ) ;
}
static void F_392 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_66 ;
F_362 (cpu)
F_181 ( V_2 -> V_8 , V_66 ) -> F_9 [ V_7 ] = 0 ;
}
static T_9 F_393 ( struct V_343 * V_344 ,
struct V_345 * V_346 ,
char * V_75 )
{
struct V_347 * V_345 ;
struct V_1 * V_2 ;
int V_304 ;
V_345 = F_394 ( V_346 ) ;
V_2 = F_395 ( V_344 ) ;
if ( ! V_345 -> V_348 )
return - V_349 ;
V_304 = V_345 -> V_348 ( V_2 , V_75 ) ;
return V_304 ;
}
static T_9 F_396 ( struct V_343 * V_344 ,
struct V_345 * V_346 ,
const char * V_75 , T_1 V_327 )
{
struct V_347 * V_345 ;
struct V_1 * V_2 ;
int V_304 ;
V_345 = F_394 ( V_346 ) ;
V_2 = F_395 ( V_344 ) ;
if ( ! V_345 -> V_350 )
return - V_349 ;
V_304 = V_345 -> V_350 ( V_2 , V_75 , V_327 ) ;
#ifdef F_397
if ( V_253 >= V_351 && V_304 >= 0 && F_300 ( V_2 ) ) {
int V_58 ;
F_281 ( & V_275 ) ;
if ( V_2 -> V_352 < V_327 )
V_2 -> V_352 = V_327 ;
F_305 (i) {
struct V_1 * V_162 = F_306 ( V_2 , V_58 ) ;
if ( V_162 )
V_345 -> V_350 ( V_162 , V_75 , V_327 ) ;
}
F_282 ( & V_275 ) ;
}
#endif
return V_304 ;
}
static void F_8 ( struct V_1 * V_2 )
{
#ifdef F_397
int V_58 ;
char * V_353 = NULL ;
struct V_1 * V_354 ;
if ( F_300 ( V_2 ) )
return;
V_354 = V_2 -> V_355 -> V_354 ;
if ( ! V_354 -> V_352 )
return;
for ( V_58 = 0 ; V_58 < F_398 ( V_356 ) ; V_58 ++ ) {
char V_357 [ 64 ] ;
char * V_75 ;
struct V_347 * V_346 = F_394 ( V_356 [ V_58 ] ) ;
if ( ! V_346 || ! V_346 -> V_350 || ! V_346 -> V_348 )
continue;
if ( V_353 )
V_75 = V_353 ;
else if ( V_354 -> V_352 < F_398 ( V_357 ) )
V_75 = V_357 ;
else {
V_353 = ( char * ) F_399 ( V_255 ) ;
if ( F_152 ( ! V_353 ) )
continue;
V_75 = V_353 ;
}
V_346 -> V_348 ( V_354 , V_75 ) ;
V_346 -> V_350 ( V_2 , V_75 , strlen ( V_75 ) ) ;
}
if ( V_353 )
F_400 ( ( unsigned long ) V_353 ) ;
#endif
}
static void F_401 ( struct V_343 * V_358 )
{
F_402 ( F_395 ( V_358 ) ) ;
}
static int F_403 ( struct V_359 * V_359 , struct V_343 * V_344 )
{
struct V_360 * V_361 = F_404 ( V_344 ) ;
if ( V_361 == & V_362 )
return 1 ;
return 0 ;
}
static inline struct V_359 * F_405 ( struct V_1 * V_2 )
{
#ifdef F_397
if ( ! F_300 ( V_2 ) )
return V_2 -> V_355 -> V_354 -> V_363 ;
#endif
return V_364 ;
}
static char * F_406 ( struct V_1 * V_2 )
{
char * V_47 = F_277 ( V_365 , V_255 ) ;
char * V_5 = V_47 ;
F_127 ( ! V_47 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_261 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_139 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_123 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_137 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_47 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_113 , V_2 -> V_15 ) ;
#ifdef F_397
if ( ! F_300 ( V_2 ) )
V_5 += sprintf ( V_5 , L_114 ,
F_407 ( V_2 -> V_355 -> V_366 ) ) ;
#endif
F_127 ( V_5 > V_47 + V_365 - 1 ) ;
return V_47 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_304 ;
const char * V_47 ;
int V_367 = F_299 ( V_2 ) ;
if ( V_367 ) {
F_408 ( & V_364 -> V_344 , V_2 -> V_47 ) ;
V_47 = V_2 -> V_47 ;
} else {
V_47 = F_406 ( V_2 ) ;
}
V_2 -> V_344 . V_359 = F_405 ( V_2 ) ;
V_304 = F_409 ( & V_2 -> V_344 , & V_362 , NULL , L_18 , V_47 ) ;
if ( V_304 )
goto V_368;
V_304 = F_410 ( & V_2 -> V_344 , & V_369 ) ;
if ( V_304 )
goto V_370;
#ifdef F_397
if ( F_300 ( V_2 ) ) {
V_2 -> V_363 = F_411 ( L_115 , NULL , & V_2 -> V_344 ) ;
if ( ! V_2 -> V_363 ) {
V_304 = - V_272 ;
goto V_370;
}
}
#endif
F_412 ( & V_2 -> V_344 , V_371 ) ;
if ( ! V_367 ) {
F_7 ( V_2 , V_2 -> V_47 ) ;
}
V_120:
if ( ! V_367 )
F_256 ( V_47 ) ;
return V_304 ;
V_370:
F_413 ( & V_2 -> V_344 ) ;
V_368:
F_414 ( & V_2 -> V_344 ) ;
goto V_120;
}
void F_415 ( struct V_1 * V_2 )
{
if ( V_253 < V_351 )
return;
#ifdef F_397
F_416 ( V_2 -> V_363 ) ;
#endif
F_412 ( & V_2 -> V_344 , V_372 ) ;
F_413 ( & V_2 -> V_344 ) ;
F_414 ( & V_2 -> V_344 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_47 )
{
struct V_373 * V_374 ;
if ( V_253 == V_351 ) {
F_408 ( & V_364 -> V_344 , V_47 ) ;
return F_417 ( & V_364 -> V_344 , & V_2 -> V_344 , V_47 ) ;
}
V_374 = F_277 ( sizeof( struct V_373 ) , V_255 ) ;
if ( ! V_374 )
return - V_272 ;
V_374 -> V_2 = V_2 ;
V_374 -> V_47 = V_47 ;
V_374 -> V_200 = V_375 ;
V_375 = V_374 ;
return 0 ;
}
static int T_7 F_418 ( void )
{
struct V_1 * V_2 ;
int V_304 ;
F_281 ( & V_275 ) ;
V_364 = F_411 ( L_116 , & V_376 , V_377 ) ;
if ( ! V_364 ) {
F_282 ( & V_275 ) ;
F_40 ( V_51 L_117 ) ;
return - V_249 ;
}
V_253 = V_351 ;
F_198 (s, &slab_caches, list) {
V_304 = F_6 ( V_2 ) ;
if ( V_304 )
F_40 ( V_51 L_118
L_119 , V_2 -> V_47 ) ;
}
while ( V_375 ) {
struct V_373 * V_374 = V_375 ;
V_375 = V_375 -> V_200 ;
V_304 = F_7 ( V_374 -> V_2 , V_374 -> V_47 ) ;
if ( V_304 )
F_40 ( V_51 L_120
L_121 , V_374 -> V_47 ) ;
F_256 ( V_374 ) ;
}
F_282 ( & V_275 ) ;
F_337 () ;
return 0 ;
}
void F_419 ( struct V_1 * V_2 , struct V_378 * V_379 )
{
unsigned long V_113 = 0 ;
unsigned long V_213 = 0 ;
unsigned long V_214 = 0 ;
int V_10 ;
F_203 (node) {
struct V_9 * V_40 = F_12 ( V_2 , V_10 ) ;
if ( ! V_40 )
continue;
V_113 += F_100 ( V_40 ) ;
V_213 += F_200 ( V_40 ) ;
V_214 += F_195 ( V_40 , F_194 ) ;
}
V_379 -> V_380 = V_213 - V_214 ;
V_379 -> V_381 = V_213 ;
V_379 -> V_382 = V_113 ;
V_379 -> V_383 = V_113 ;
V_379 -> V_384 = F_27 ( V_2 -> V_126 ) ;
V_379 -> V_385 = F_26 ( V_2 -> V_126 ) ;
}
void F_420 ( struct V_386 * V_188 , struct V_1 * V_2 )
{
}
T_9 F_421 ( struct V_387 * V_387 , const char T_10 * V_353 ,
T_1 V_313 , T_11 * V_388 )
{
return - V_349 ;
}
