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
static inline void F_9 ( struct V_1 * V_2 ) { }
static inline void F_10 ( const struct V_1 * V_2 , enum V_6 V_7 )
{
#ifdef F_11
F_12 ( V_2 -> V_8 -> F_10 [ V_7 ] ) ;
#endif
}
static inline struct V_9 * F_13 ( struct V_1 * V_2 , int V_10 )
{
return V_2 -> V_10 [ V_10 ] ;
}
static inline int F_14 ( struct V_1 * V_2 ,
struct V_11 * V_11 , const void * V_12 )
{
void * V_13 ;
if ( ! V_12 )
return 1 ;
V_13 = F_15 ( V_11 ) ;
if ( V_12 < V_13 || V_12 >= V_13 + V_11 -> V_14 * V_2 -> V_15 ||
( V_12 - V_13 ) % V_2 -> V_15 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_16 ( struct V_1 * V_2 , void * V_12 )
{
return * ( void * * ) ( V_12 + V_2 -> V_16 ) ;
}
static void F_17 ( const struct V_1 * V_2 , void * V_12 )
{
F_18 ( V_12 + V_2 -> V_16 ) ;
}
static inline void * F_19 ( struct V_1 * V_2 , void * V_12 )
{
void * V_5 ;
#ifdef F_20
F_21 ( & V_5 , ( void * * ) ( V_12 + V_2 -> V_16 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_16 ( V_2 , V_12 ) ;
#endif
return V_5 ;
}
static inline void F_22 ( struct V_1 * V_2 , void * V_12 , void * V_17 )
{
* ( void * * ) ( V_12 + V_2 -> V_16 ) = V_17 ;
}
static inline int F_23 ( void * V_5 , struct V_1 * V_2 , void * V_18 )
{
return ( V_5 - V_18 ) / V_2 -> V_15 ;
}
static inline T_1 F_24 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_19 | V_20 ) )
return V_2 -> V_21 ;
#endif
if ( V_2 -> V_3 & ( V_22 | V_23 ) )
return V_2 -> V_24 ;
return V_2 -> V_15 ;
}
static inline int F_25 ( int V_25 , unsigned long V_15 , int V_26 )
{
return ( ( V_27 << V_25 ) - V_26 ) / V_15 ;
}
static inline struct V_28 F_26 ( int V_25 ,
unsigned long V_15 , int V_26 )
{
struct V_28 V_29 = {
( V_25 << V_30 ) + F_25 (order, size, reserved)
} ;
return V_29 ;
}
static inline int F_27 ( struct V_28 V_29 )
{
return V_29 . V_29 >> V_30 ;
}
static inline int F_28 ( struct V_28 V_29 )
{
return V_29 . V_29 & V_31 ;
}
static T_2 void F_29 ( struct V_11 * V_11 )
{
F_30 ( V_32 , & V_11 -> V_3 ) ;
}
static T_2 void F_31 ( struct V_11 * V_11 )
{
F_32 ( V_32 , & V_11 -> V_3 ) ;
}
static inline bool F_33 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_33 , unsigned long V_34 ,
void * V_35 , unsigned long V_36 ,
const char * V_37 )
{
F_34 ( ! F_35 () ) ;
#if F_36 ( V_38 ) && \
F_36 ( V_39 )
if ( V_2 -> V_3 & V_40 ) {
if ( F_37 ( & V_11 -> V_41 , & V_11 -> V_42 ,
V_33 , V_34 ,
V_35 , V_36 ) )
return 1 ;
} else
#endif
{
F_29 ( V_11 ) ;
if ( V_11 -> V_41 == V_33 &&
V_11 -> V_42 == V_34 ) {
V_11 -> V_41 = V_35 ;
V_11 -> V_42 = V_36 ;
F_31 ( V_11 ) ;
return 1 ;
}
F_31 ( V_11 ) ;
}
F_38 () ;
F_10 ( V_2 , V_43 ) ;
#ifdef F_39
F_40 ( V_44 L_1 , V_37 , V_2 -> V_45 ) ;
#endif
return 0 ;
}
static inline bool F_41 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_33 , unsigned long V_34 ,
void * V_35 , unsigned long V_36 ,
const char * V_37 )
{
#if F_36 ( V_38 ) && \
F_36 ( V_39 )
if ( V_2 -> V_3 & V_40 ) {
if ( F_37 ( & V_11 -> V_41 , & V_11 -> V_42 ,
V_33 , V_34 ,
V_35 , V_36 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_29 ( V_11 ) ;
if ( V_11 -> V_41 == V_33 &&
V_11 -> V_42 == V_34 ) {
V_11 -> V_41 = V_35 ;
V_11 -> V_42 = V_36 ;
F_31 ( V_11 ) ;
F_43 ( V_3 ) ;
return 1 ;
}
F_31 ( V_11 ) ;
F_43 ( V_3 ) ;
}
F_38 () ;
F_10 ( V_2 , V_43 ) ;
#ifdef F_39
F_40 ( V_44 L_1 , V_37 , V_2 -> V_45 ) ;
#endif
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long * V_46 )
{
void * V_5 ;
void * V_18 = F_15 ( V_11 ) ;
for ( V_5 = V_11 -> V_41 ; V_5 ; V_5 = F_16 ( V_2 , V_5 ) )
F_45 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) ;
}
static void F_46 ( char * V_47 , T_3 * V_18 , unsigned int V_48 )
{
F_47 ( V_49 , V_47 , V_50 , 16 , 1 , V_18 ,
V_48 , 1 ) ;
}
static struct V_51 * F_48 ( struct V_1 * V_2 , void * V_12 ,
enum V_52 V_53 )
{
struct V_51 * V_5 ;
if ( V_2 -> V_16 )
V_5 = V_12 + V_2 -> V_16 + sizeof( void * ) ;
else
V_5 = V_12 + V_2 -> V_24 ;
return V_5 + V_53 ;
}
static void F_49 ( struct V_1 * V_2 , void * V_12 ,
enum V_52 V_53 , unsigned long V_18 )
{
struct V_51 * V_5 = F_48 ( V_2 , V_12 , V_53 ) ;
if ( V_18 ) {
#ifdef F_50
struct V_54 V_55 ;
int V_56 ;
V_55 . V_57 = 0 ;
V_55 . V_58 = V_59 ;
V_55 . V_60 = V_5 -> V_61 ;
V_55 . V_62 = 3 ;
F_51 ( & V_55 ) ;
if ( V_55 . V_57 != 0 &&
V_55 . V_60 [ V_55 . V_57 - 1 ] == V_63 )
V_55 . V_57 -- ;
for ( V_56 = V_55 . V_57 ; V_56 < V_59 ; V_56 ++ )
V_5 -> V_61 [ V_56 ] = 0 ;
#endif
V_5 -> V_18 = V_18 ;
V_5 -> V_64 = F_52 () ;
V_5 -> V_65 = V_66 -> V_65 ;
V_5 -> V_67 = V_68 ;
} else
memset ( V_5 , 0 , sizeof( struct V_51 ) ) ;
}
static void F_53 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_49 ( V_2 , V_12 , V_69 , 0UL ) ;
F_49 ( V_2 , V_12 , V_70 , 0UL ) ;
}
static void F_54 ( const char * V_2 , struct V_51 * V_71 )
{
if ( ! V_71 -> V_18 )
return;
F_40 ( V_49 L_2 ,
V_2 , ( void * ) V_71 -> V_18 , V_68 - V_71 -> V_67 , V_71 -> V_64 , V_71 -> V_65 ) ;
#ifdef F_50
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_59 ; V_56 ++ )
if ( V_71 -> V_61 [ V_56 ] )
F_40 ( V_49 L_3 , ( void * ) V_71 -> V_61 [ V_56 ] ) ;
else
break;
}
#endif
}
static void F_55 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_54 ( L_4 , F_48 ( V_2 , V_12 , V_70 ) ) ;
F_54 ( L_5 , F_48 ( V_2 , V_12 , V_69 ) ) ;
}
static void F_56 ( struct V_11 * V_11 )
{
F_40 ( V_49
L_6 ,
V_11 , V_11 -> V_14 , V_11 -> V_24 , V_11 -> V_41 , V_11 -> V_3 ) ;
}
static void F_57 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_40 ( V_49 L_7
L_8 ) ;
F_40 ( V_49 L_9 , V_2 -> V_45 , F_58 () , V_73 ) ;
F_40 ( V_49 L_10
L_11 ) ;
F_59 ( V_74 , V_75 ) ;
}
static void F_60 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_40 ( V_49 L_12 , V_2 -> V_45 , V_73 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned int V_76 ;
T_3 * V_18 = F_15 ( V_11 ) ;
F_55 ( V_2 , V_5 ) ;
F_56 ( V_11 ) ;
F_40 ( V_49 L_13 ,
V_5 , V_5 - V_18 , F_16 ( V_2 , V_5 ) ) ;
if ( V_5 > V_18 + 16 )
F_46 ( L_14 , V_5 - 16 , 16 ) ;
F_46 ( L_15 , V_5 , F_62 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_19 )
F_46 ( L_16 , V_5 + V_2 -> V_21 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
if ( V_2 -> V_16 )
V_76 = V_2 -> V_16 + sizeof( void * ) ;
else
V_76 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_76 += 2 * sizeof( struct V_51 ) ;
if ( V_76 != V_2 -> V_15 )
F_46 ( L_17 , V_5 + V_76 , V_2 -> V_15 - V_76 ) ;
F_63 () ;
}
static void F_64 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_77 )
{
F_57 ( V_2 , L_18 , V_77 ) ;
F_61 ( V_2 , V_11 , V_12 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_57 ( V_2 , L_18 , V_73 ) ;
F_56 ( V_11 ) ;
F_63 () ;
}
static void F_66 ( struct V_1 * V_2 , void * V_12 , T_3 V_78 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_79 ) {
memset ( V_5 , V_80 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_81 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_78 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_67 ( struct V_1 * V_2 , char * V_82 , T_3 V_83 ,
void * V_84 , void * V_85 )
{
F_60 ( V_2 , L_19 , V_84 , V_85 - 1 , V_83 ) ;
memset ( V_84 , V_83 , V_85 - V_84 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_86 ,
T_3 * V_87 , unsigned int V_88 , unsigned int V_89 )
{
T_3 * V_90 ;
T_3 * V_91 ;
V_90 = F_69 ( V_87 , V_88 , V_89 ) ;
if ( ! V_90 )
return 1 ;
V_91 = V_87 + V_89 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_88 )
V_91 -- ;
F_57 ( V_2 , L_20 , V_86 ) ;
F_40 ( V_49 L_21 ,
V_90 , V_91 - 1 , V_90 [ 0 ] , V_88 ) ;
F_61 ( V_2 , V_11 , V_12 ) ;
F_67 ( V_2 , V_86 , V_88 , V_90 , V_91 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_76 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_76 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_76 += 2 * sizeof( struct V_51 ) ;
if ( V_2 -> V_15 == V_76 )
return 1 ;
return F_68 ( V_2 , V_11 , V_5 , L_22 ,
V_5 + V_76 , V_92 , V_2 -> V_15 - V_76 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_87 ;
T_3 * V_90 ;
T_3 * V_91 ;
int V_48 ;
int V_93 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_87 = F_15 ( V_11 ) ;
V_48 = ( V_27 << F_72 ( V_11 ) ) - V_2 -> V_26 ;
V_91 = V_87 + V_48 ;
V_93 = V_48 % V_2 -> V_15 ;
if ( ! V_93 )
return 1 ;
V_90 = F_69 ( V_91 - V_93 , V_92 , V_93 ) ;
if ( ! V_90 )
return 1 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_92 )
V_91 -- ;
F_65 ( V_2 , V_11 , L_23 , V_90 , V_91 - 1 ) ;
F_46 ( L_17 , V_91 - V_93 , V_93 ) ;
F_67 ( V_2 , L_24 , V_92 , V_91 - V_93 , V_91 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_78 )
{
T_3 * V_5 = V_12 ;
T_3 * V_94 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_68 ( V_2 , V_11 , V_12 , L_25 ,
V_94 , V_78 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_68 ( V_2 , V_11 , V_5 , L_26 ,
V_94 , V_92 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_78 != V_95 && ( V_2 -> V_3 & V_79 ) &&
( ! F_68 ( V_2 , V_11 , V_5 , L_27 , V_5 ,
V_80 , V_2 -> V_21 - 1 ) ||
! F_68 ( V_2 , V_11 , V_5 , L_27 ,
V_5 + V_2 -> V_21 - 1 , V_81 , 1 ) ) )
return 0 ;
F_70 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_78 == V_95 )
return 1 ;
if ( ! F_14 ( V_2 , V_11 , F_16 ( V_2 , V_5 ) ) ) {
F_64 ( V_2 , V_11 , V_5 , L_28 ) ;
F_22 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_96 ;
F_34 ( ! F_35 () ) ;
if ( ! F_75 ( V_11 ) ) {
F_65 ( V_2 , V_11 , L_29 ) ;
return 0 ;
}
V_96 = F_25 ( F_72 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_96 ) {
F_65 ( V_2 , V_11 , L_30 ,
V_2 -> V_45 , V_11 -> V_14 , V_96 ) ;
return 0 ;
}
if ( V_11 -> V_24 > V_11 -> V_14 ) {
F_65 ( V_2 , V_11 , L_31 ,
V_2 -> V_45 , V_11 -> V_24 , V_11 -> V_14 ) ;
return 0 ;
}
F_71 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_97 )
{
int V_98 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_99 ;
V_17 = V_11 -> V_41 ;
while ( V_17 && V_98 <= V_11 -> V_14 ) {
if ( V_17 == V_97 )
return 1 ;
if ( ! F_14 ( V_2 , V_11 , V_17 ) ) {
if ( V_12 ) {
F_64 ( V_2 , V_11 , V_12 ,
L_32 ) ;
F_22 ( V_2 , V_12 , NULL ) ;
} else {
F_65 ( V_2 , V_11 , L_28 ) ;
V_11 -> V_41 = NULL ;
V_11 -> V_24 = V_11 -> V_14 ;
F_60 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_12 = V_17 ;
V_17 = F_16 ( V_2 , V_12 ) ;
V_98 ++ ;
}
V_99 = F_25 ( F_72 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_99 > V_100 )
V_99 = V_100 ;
if ( V_11 -> V_14 != V_99 ) {
F_65 ( V_2 , V_11 , L_34
L_35 , V_11 -> V_14 , V_99 ) ;
V_11 -> V_14 = V_99 ;
F_60 ( V_2 , L_36 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_98 ) {
F_65 ( V_2 , V_11 , L_37
L_38 , V_11 -> V_24 , V_11 -> V_14 - V_98 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_98 ;
F_60 ( V_2 , L_39 ) ;
}
return V_97 == NULL ;
}
static void V_55 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_53 )
{
if ( V_2 -> V_3 & V_101 ) {
F_40 ( V_44 L_40 ,
V_2 -> V_45 ,
V_53 ? L_41 : L_42 ,
V_12 , V_11 -> V_24 ,
V_11 -> V_41 ) ;
if ( ! V_53 )
F_46 ( L_15 , ( void * ) V_12 ,
V_2 -> V_21 ) ;
F_63 () ;
}
}
static inline void F_77 ( void * V_102 , T_1 V_15 , T_5 V_3 )
{
F_78 ( V_102 , V_15 , 1 , V_3 ) ;
}
static inline void F_79 ( const void * V_29 )
{
F_80 ( V_29 ) ;
}
static inline int F_81 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_103 ;
F_82 ( V_3 ) ;
F_83 ( V_3 & V_104 ) ;
return F_84 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_85 ( struct V_1 * V_2 ,
T_5 V_3 , void * V_12 )
{
V_3 &= V_103 ;
F_86 ( V_2 , V_3 , V_12 , F_24 ( V_2 ) ) ;
F_87 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_88 ( struct V_1 * V_2 , void * V_29 )
{
F_89 ( V_29 , V_2 -> V_3 ) ;
#if F_36 ( V_105 ) || F_36 ( V_106 )
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_90 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_91 ( V_29 , V_2 -> V_21 ) ;
F_43 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_107 ) )
F_92 ( V_29 , V_2 -> V_21 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_94 ( & V_11 -> V_108 , & V_37 -> V_109 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_96 ( & V_11 -> V_108 ) ;
}
static inline unsigned long F_97 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
return F_98 ( & V_37 -> V_110 ) ;
}
static inline unsigned long F_99 ( struct V_9 * V_37 )
{
return F_98 ( & V_37 -> V_110 ) ;
}
static inline void F_100 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( F_101 ( V_37 ) ) {
F_102 ( & V_37 -> V_110 ) ;
F_103 ( V_14 , & V_37 -> V_111 ) ;
}
}
static inline void F_104 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
F_105 ( & V_37 -> V_110 ) ;
F_106 ( V_14 , & V_37 -> V_111 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_79 ) ) )
return;
F_66 ( V_2 , V_12 , V_112 ) ;
F_53 ( V_2 , V_12 ) ;
}
static T_6 int F_108 ( struct V_1 * V_2 ,
struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_74 ( V_2 , V_11 ) )
goto V_113;
if ( ! F_14 ( V_2 , V_11 , V_12 ) ) {
F_64 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_113;
}
if ( ! F_73 ( V_2 , V_11 , V_12 , V_112 ) )
goto V_113;
if ( V_2 -> V_3 & V_23 )
F_49 ( V_2 , V_12 , V_70 , V_18 ) ;
V_55 ( V_2 , V_11 , V_12 , 1 ) ;
F_66 ( V_2 , V_12 , V_95 ) ;
return 1 ;
V_113:
if ( F_75 ( V_11 ) ) {
F_60 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_41 = NULL ;
}
return 0 ;
}
int T_7 F_109 ( char * V_114 )
{
V_115 = V_116 ;
if ( * V_114 ++ != '=' || ! * V_114 )
goto V_117;
if ( * V_114 == ',' )
goto V_118;
if ( tolower ( * V_114 ) == 'o' ) {
V_119 = 1 ;
goto V_117;
}
V_115 = 0 ;
if ( * V_114 == '-' )
goto V_117;
for (; * V_114 && * V_114 != ',' ; V_114 ++ ) {
switch ( tolower ( * V_114 ) ) {
case 'f' :
V_115 |= V_120 ;
break;
case 'z' :
V_115 |= V_19 ;
break;
case 'p' :
V_115 |= V_20 ;
break;
case 'u' :
V_115 |= V_23 ;
break;
case 't' :
V_115 |= V_101 ;
break;
case 'a' :
V_115 |= V_121 ;
break;
default:
F_40 ( V_49 L_45
L_46 , * V_114 ) ;
}
}
V_118:
if ( * V_114 == ',' )
V_122 = V_114 + 1 ;
V_117:
return 1 ;
}
static unsigned long F_110 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_111)( void * ) )
{
if ( V_115 && ( ! V_122 || ( V_45 &&
! strncmp ( V_122 , V_45 , strlen ( V_122 ) ) ) ) )
V_3 |= V_115 ;
return V_3 ;
}
static inline void F_107 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 ) {}
static inline int F_108 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 , unsigned long V_18 ) { return 0 ; }
static inline struct V_9 * F_112 (
struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
unsigned long V_18 , unsigned long * V_3 ) { return NULL ; }
static inline int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 )
{ return 1 ; }
static inline int F_73 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_78 ) { return 1 ; }
static inline void F_93 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_11 * V_11 ) {}
static inline void F_95 ( struct V_1 * V_2 , struct V_11 * V_11 ) {}
static inline unsigned long F_110 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_111)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_97 ( struct V_1 * V_2 , int V_10 )
{ return 0 ; }
static inline unsigned long F_99 ( struct V_9 * V_37 )
{ return 0 ; }
static inline void F_100 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_104 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_77 ( void * V_102 , T_1 V_15 , T_5 V_3 )
{
F_78 ( V_102 , V_15 , 1 , V_3 ) ;
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
V_3 & V_103 ) ;
}
static inline void F_88 ( struct V_1 * V_2 , void * V_29 )
{
F_89 ( V_29 , V_2 -> V_3 ) ;
}
static inline struct V_11 * F_113 ( T_5 V_3 , int V_10 ,
struct V_28 V_123 )
{
int V_25 = F_27 ( V_123 ) ;
V_3 |= V_124 ;
if ( V_10 == V_125 )
return F_114 ( V_3 , V_25 ) ;
else
return F_115 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_116 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_123 = V_2 -> V_123 ;
T_5 V_126 ;
V_3 &= V_103 ;
if ( V_3 & V_104 )
F_117 () ;
V_3 |= V_2 -> V_127 ;
V_126 = ( V_3 | V_128 | V_129 ) & ~ V_130 ;
V_11 = F_113 ( V_126 , V_10 , V_123 ) ;
if ( F_3 ( ! V_11 ) ) {
V_123 = V_2 -> V_131 ;
V_11 = F_113 ( V_3 , V_10 , V_123 ) ;
if ( V_11 )
F_10 ( V_2 , V_132 ) ;
}
if ( V_133 && V_11
&& ! ( V_2 -> V_3 & ( V_134 | V_116 ) ) ) {
int V_135 = 1 << F_27 ( V_123 ) ;
F_118 ( V_11 , F_27 ( V_123 ) , V_3 , V_10 ) ;
if ( V_2 -> F_111 )
F_119 ( V_11 , V_135 ) ;
else
F_120 ( V_11 , V_135 ) ;
}
if ( V_3 & V_104 )
F_121 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_28 ( V_123 ) ;
F_122 ( F_123 ( V_11 ) ,
( V_2 -> V_3 & V_136 ) ?
V_137 : V_138 ,
1 << F_27 ( V_123 ) ) ;
return V_11 ;
}
static void F_124 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_107 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_111 ) )
V_2 -> F_111 ( V_12 ) ;
}
static struct V_11 * F_125 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_87 ;
void * V_139 ;
void * V_5 ;
int V_25 ;
F_126 ( V_3 & V_140 ) ;
V_11 = F_116 ( V_2 ,
V_3 & ( V_141 | V_142 ) , V_10 ) ;
if ( ! V_11 )
goto V_117;
V_25 = F_72 ( V_11 ) ;
F_100 ( V_2 , F_127 ( V_11 ) , V_11 -> V_14 ) ;
F_128 ( V_2 , V_25 ) ;
V_11 -> V_143 = V_2 ;
F_129 ( V_11 ) ;
if ( V_11 -> V_144 )
F_130 ( V_11 ) ;
V_87 = F_15 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_87 , V_92 , V_27 << V_25 ) ;
V_139 = V_87 ;
F_131 (p, s, start, page->objects) {
F_124 ( V_2 , V_11 , V_139 ) ;
F_22 ( V_2 , V_139 , V_5 ) ;
V_139 = V_5 ;
}
F_124 ( V_2 , V_11 , V_139 ) ;
F_22 ( V_2 , V_139 , NULL ) ;
V_11 -> V_41 = V_87 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_145 = 1 ;
V_117:
return V_11 ;
}
static void F_132 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_72 ( V_11 ) ;
int V_135 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_71 ( V_2 , V_11 ) ;
F_131 (p, s, page_address(page),
page->objects)
F_73 ( V_2 , V_11 , V_5 , V_112 ) ;
}
F_133 ( V_11 , F_72 ( V_11 ) ) ;
F_122 ( F_123 ( V_11 ) ,
( V_2 -> V_3 & V_136 ) ?
V_137 : V_138 ,
- V_135 ) ;
F_134 ( V_11 ) ;
F_135 ( V_11 ) ;
F_136 ( V_2 , V_25 ) ;
F_137 ( V_11 ) ;
if ( V_66 -> V_146 )
V_66 -> V_146 -> V_147 += V_135 ;
F_138 ( V_11 , V_25 ) ;
}
static void F_139 ( struct V_148 * V_149 )
{
struct V_11 * V_11 ;
if ( V_150 )
V_11 = F_140 ( V_149 ) ;
else
V_11 = F_141 ( (struct V_151 * ) V_149 , struct V_11 , V_108 ) ;
F_132 ( V_11 -> V_143 , V_11 ) ;
}
static void F_142 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_148 * V_152 ;
if ( V_150 ) {
int V_25 = F_72 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_34 ( V_2 -> V_26 != sizeof( * V_152 ) ) ;
V_152 = F_15 ( V_11 ) + V_16 ;
} else {
V_152 = ( void * ) & V_11 -> V_108 ;
}
F_143 ( V_152 , F_139 ) ;
} else
F_132 ( V_2 , V_11 ) ;
}
static void F_144 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_104 ( V_2 , F_127 ( V_11 ) , V_11 -> V_14 ) ;
F_142 ( V_2 , V_11 ) ;
}
static inline void F_145 ( struct V_9 * V_37 ,
struct V_11 * V_11 , int V_153 )
{
V_37 -> V_154 ++ ;
if ( V_153 == V_155 )
F_146 ( & V_11 -> V_108 , & V_37 -> V_156 ) ;
else
F_94 ( & V_11 -> V_108 , & V_37 -> V_156 ) ;
}
static inline void F_147 ( struct V_9 * V_37 ,
struct V_11 * V_11 )
{
F_96 ( & V_11 -> V_108 ) ;
V_37 -> V_154 -- ;
}
static inline void * F_148 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 ,
int V_157 , int * V_14 )
{
void * V_41 ;
unsigned long V_42 ;
struct V_11 V_158 ;
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_158 . V_42 = V_42 ;
* V_14 = V_158 . V_14 - V_158 . V_24 ;
if ( V_157 ) {
V_158 . V_24 = V_11 -> V_14 ;
V_158 . V_41 = NULL ;
} else {
V_158 . V_41 = V_41 ;
}
F_34 ( V_158 . V_145 ) ;
V_158 . V_145 = 1 ;
if ( ! F_33 ( V_2 , V_11 ,
V_41 , V_42 ,
V_158 . V_41 , V_158 . V_42 ,
L_47 ) )
return NULL ;
F_147 ( V_37 , V_11 ) ;
F_149 ( ! V_41 ) ;
return V_41 ;
}
static void * F_150 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_159 * V_160 , T_5 V_3 )
{
struct V_11 * V_11 , * V_161 ;
void * V_12 = NULL ;
int V_162 = 0 ;
int V_14 ;
if ( ! V_37 || ! V_37 -> V_154 )
return NULL ;
F_151 ( & V_37 -> V_163 ) ;
F_152 (page, page2, &n->partial, lru) {
void * V_71 ;
if ( ! F_153 ( V_11 , V_3 ) )
continue;
V_71 = F_148 ( V_2 , V_37 , V_11 , V_12 == NULL , & V_14 ) ;
if ( ! V_71 )
break;
V_162 += V_14 ;
if ( ! V_12 ) {
V_160 -> V_11 = V_11 ;
F_10 ( V_2 , V_164 ) ;
V_12 = V_71 ;
} else {
F_154 ( V_2 , V_11 , 0 ) ;
F_10 ( V_2 , V_165 ) ;
}
if ( ! F_4 ( V_2 )
|| V_162 > V_2 -> V_166 / 2 )
break;
}
F_155 ( & V_37 -> V_163 ) ;
return V_12 ;
}
static void * F_156 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_159 * V_160 )
{
#ifdef F_157
struct V_167 * V_167 ;
struct V_168 * V_169 ;
struct V_170 * V_170 ;
enum V_171 V_172 = F_158 ( V_3 ) ;
void * V_12 ;
unsigned int V_173 ;
if ( ! V_2 -> V_174 ||
F_159 () % 1024 > V_2 -> V_174 )
return NULL ;
do {
V_173 = F_160 () ;
V_167 = F_161 ( F_162 () , V_3 ) ;
F_163 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_37 ;
V_37 = F_13 ( V_2 , F_164 ( V_170 ) ) ;
if ( V_37 && F_165 ( V_170 , V_3 ) &&
V_37 -> V_154 > V_2 -> V_175 ) {
V_12 = F_150 ( V_2 , V_37 , V_160 , V_3 ) ;
if ( V_12 ) {
F_166 ( V_173 ) ;
return V_12 ;
}
}
}
} while ( ! F_166 ( V_173 ) );
#endif
return NULL ;
}
static void * F_167 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_159 * V_160 )
{
void * V_12 ;
int V_176 = ( V_10 == V_125 ) ? F_168 () : V_10 ;
V_12 = F_150 ( V_2 , F_13 ( V_2 , V_176 ) , V_160 , V_3 ) ;
if ( V_12 || V_10 != V_125 )
return V_12 ;
return F_156 ( V_2 , V_3 , V_160 ) ;
}
static inline unsigned long F_169 ( unsigned long V_177 )
{
return V_177 + V_178 ;
}
static inline unsigned int F_170 ( unsigned long V_177 )
{
return V_177 % V_178 ;
}
static inline unsigned long F_171 ( unsigned long V_177 )
{
return V_177 / V_178 ;
}
static inline unsigned int F_172 ( int V_64 )
{
return V_64 ;
}
static inline void F_173 ( const char * V_37 ,
const struct V_1 * V_2 , unsigned long V_177 )
{
#ifdef F_39
unsigned long V_179 = F_174 ( V_2 -> V_8 -> V_177 ) ;
F_40 ( V_44 L_48 , V_37 , V_2 -> V_45 ) ;
#ifdef F_175
if ( F_170 ( V_177 ) != F_170 ( V_179 ) )
F_40 ( L_49 ,
F_170 ( V_177 ) , F_170 ( V_179 ) ) ;
else
#endif
if ( F_171 ( V_177 ) != F_171 ( V_179 ) )
F_40 ( L_50 ,
F_171 ( V_177 ) , F_171 ( V_179 ) ) ;
else
F_40 ( L_51 ,
V_179 , V_177 , F_169 ( V_177 ) ) ;
#endif
F_10 ( V_2 , V_180 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
int V_64 ;
F_177 (cpu)
F_178 ( V_2 -> V_8 , V_64 ) -> V_177 = F_172 ( V_64 ) ;
}
static void F_179 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_41 )
{
enum T_8 { V_181 , V_182 , V_183 , V_184 };
struct V_9 * V_37 = F_13 ( V_2 , F_127 ( V_11 ) ) ;
int V_185 = 0 ;
enum T_8 V_186 = V_181 , V_187 = V_181 ;
void * V_188 ;
int V_153 = V_189 ;
struct V_11 V_158 ;
struct V_11 V_190 ;
if ( V_11 -> V_41 ) {
F_10 ( V_2 , V_191 ) ;
V_153 = V_155 ;
}
while ( V_41 && ( V_188 = F_16 ( V_2 , V_41 ) ) ) {
void * V_192 ;
unsigned long V_42 ;
do {
V_192 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_22 ( V_2 , V_41 , V_192 ) ;
V_158 . V_42 = V_42 ;
V_158 . V_24 -- ;
F_34 ( ! V_158 . V_145 ) ;
} while ( ! F_33 ( V_2 , V_11 ,
V_192 , V_42 ,
V_41 , V_158 . V_42 ,
L_52 ) );
V_41 = V_188 ;
}
V_193:
V_190 . V_41 = V_11 -> V_41 ;
V_190 . V_42 = V_11 -> V_42 ;
F_34 ( ! V_190 . V_145 ) ;
V_158 . V_42 = V_190 . V_42 ;
if ( V_41 ) {
V_158 . V_24 -- ;
F_22 ( V_2 , V_41 , V_190 . V_41 ) ;
V_158 . V_41 = V_41 ;
} else
V_158 . V_41 = V_190 . V_41 ;
V_158 . V_145 = 0 ;
if ( ! V_158 . V_24 && V_37 -> V_154 > V_2 -> V_175 )
V_187 = V_184 ;
else if ( V_158 . V_41 ) {
V_187 = V_182 ;
if ( ! V_185 ) {
V_185 = 1 ;
F_151 ( & V_37 -> V_163 ) ;
}
} else {
V_187 = V_183 ;
if ( F_1 ( V_2 ) && ! V_185 ) {
V_185 = 1 ;
F_151 ( & V_37 -> V_163 ) ;
}
}
if ( V_186 != V_187 ) {
if ( V_186 == V_182 )
F_147 ( V_37 , V_11 ) ;
else if ( V_186 == V_183 )
F_95 ( V_2 , V_11 ) ;
if ( V_187 == V_182 ) {
F_145 ( V_37 , V_11 , V_153 ) ;
F_10 ( V_2 , V_153 ) ;
} else if ( V_187 == V_183 ) {
F_10 ( V_2 , V_194 ) ;
F_93 ( V_2 , V_37 , V_11 ) ;
}
}
V_186 = V_187 ;
if ( ! F_33 ( V_2 , V_11 ,
V_190 . V_41 , V_190 . V_42 ,
V_158 . V_41 , V_158 . V_42 ,
L_53 ) )
goto V_193;
if ( V_185 )
F_155 ( & V_37 -> V_163 ) ;
if ( V_187 == V_184 ) {
F_10 ( V_2 , V_195 ) ;
F_144 ( V_2 , V_11 ) ;
F_10 ( V_2 , V_196 ) ;
}
}
static void F_180 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
#ifdef F_5
struct V_9 * V_37 = NULL , * V_197 = NULL ;
struct V_11 * V_11 , * V_198 = NULL ;
while ( ( V_11 = V_160 -> V_156 ) ) {
struct V_11 V_158 ;
struct V_11 V_190 ;
V_160 -> V_156 = V_11 -> V_199 ;
V_197 = F_13 ( V_2 , F_127 ( V_11 ) ) ;
if ( V_37 != V_197 ) {
if ( V_37 )
F_155 ( & V_37 -> V_163 ) ;
V_37 = V_197 ;
F_151 ( & V_37 -> V_163 ) ;
}
do {
V_190 . V_41 = V_11 -> V_41 ;
V_190 . V_42 = V_11 -> V_42 ;
F_34 ( ! V_190 . V_145 ) ;
V_158 . V_42 = V_190 . V_42 ;
V_158 . V_41 = V_190 . V_41 ;
V_158 . V_145 = 0 ;
} while ( ! F_33 ( V_2 , V_11 ,
V_190 . V_41 , V_190 . V_42 ,
V_158 . V_41 , V_158 . V_42 ,
L_53 ) );
if ( F_3 ( ! V_158 . V_24 && V_37 -> V_154 > V_2 -> V_175 ) ) {
V_11 -> V_199 = V_198 ;
V_198 = V_11 ;
} else {
F_145 ( V_37 , V_11 , V_155 ) ;
F_10 ( V_2 , V_200 ) ;
}
}
if ( V_37 )
F_155 ( & V_37 -> V_163 ) ;
while ( V_198 ) {
V_11 = V_198 ;
V_198 = V_198 -> V_199 ;
F_10 ( V_2 , V_195 ) ;
F_144 ( V_2 , V_11 ) ;
F_10 ( V_2 , V_196 ) ;
}
#endif
}
static void F_154 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_201 )
{
#ifdef F_5
struct V_11 * V_202 ;
int V_135 ;
int V_203 ;
do {
V_135 = 0 ;
V_203 = 0 ;
V_202 = F_181 ( V_2 -> V_8 -> V_156 ) ;
if ( V_202 ) {
V_203 = V_202 -> V_203 ;
V_135 = V_202 -> V_135 ;
if ( V_201 && V_203 > V_2 -> V_166 ) {
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_180 ( V_2 , F_182 ( V_2 -> V_8 ) ) ;
F_43 ( V_3 ) ;
V_202 = NULL ;
V_203 = 0 ;
V_135 = 0 ;
F_10 ( V_2 , V_204 ) ;
}
}
V_135 ++ ;
V_203 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_135 = V_135 ;
V_11 -> V_203 = V_203 ;
V_11 -> V_199 = V_202 ;
} while ( F_183 ( V_2 -> V_8 -> V_156 , V_202 , V_11 )
!= V_202 );
#endif
}
static inline void F_184 ( struct V_1 * V_2 , struct V_159 * V_160 )
{
F_10 ( V_2 , V_205 ) ;
F_179 ( V_2 , V_160 -> V_11 , V_160 -> V_41 ) ;
V_160 -> V_177 = F_169 ( V_160 -> V_177 ) ;
V_160 -> V_11 = NULL ;
V_160 -> V_41 = NULL ;
}
static inline void F_185 ( struct V_1 * V_2 , int V_64 )
{
struct V_159 * V_160 = F_178 ( V_2 -> V_8 , V_64 ) ;
if ( F_101 ( V_160 ) ) {
if ( V_160 -> V_11 )
F_184 ( V_2 , V_160 ) ;
F_180 ( V_2 , V_160 ) ;
}
}
static void F_186 ( void * V_206 )
{
struct V_1 * V_2 = V_206 ;
F_185 ( V_2 , F_52 () ) ;
}
static bool F_187 ( int V_64 , void * V_207 )
{
struct V_1 * V_2 = V_207 ;
struct V_159 * V_160 = F_178 ( V_2 -> V_8 , V_64 ) ;
return V_160 -> V_11 || V_160 -> V_156 ;
}
static void F_188 ( struct V_1 * V_2 )
{
F_189 ( F_187 , F_186 , V_2 , 1 , V_208 ) ;
}
static inline int F_190 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_157
if ( ! V_11 || ( V_10 != V_125 && F_127 ( V_11 ) != V_10 ) )
return 0 ;
#endif
return 1 ;
}
static int F_191 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static unsigned long F_192 ( struct V_9 * V_37 ,
int (* F_193)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_194 ( & V_37 -> V_163 , V_3 ) ;
F_195 (page, &n->partial, lru)
V_29 += F_193 ( V_11 ) ;
F_196 ( & V_37 -> V_163 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_197 ( struct V_9 * V_37 )
{
#ifdef F_2
return F_98 ( & V_37 -> V_111 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_198 ( struct V_1 * V_2 , T_5 V_209 , int V_210 )
{
int V_10 ;
F_40 ( V_211
L_54 ,
V_210 , V_209 ) ;
F_40 ( V_211 L_55
L_56 , V_2 -> V_45 , V_2 -> V_21 ,
V_2 -> V_15 , F_27 ( V_2 -> V_123 ) , F_27 ( V_2 -> V_131 ) ) ;
if ( F_27 ( V_2 -> V_131 ) > F_199 ( V_2 -> V_21 ) )
F_40 ( V_211 L_57
L_58 , V_2 -> V_45 ) ;
F_200 (node) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
unsigned long V_110 ;
unsigned long V_212 ;
unsigned long V_213 ;
if ( ! V_37 )
continue;
V_213 = F_192 ( V_37 , F_191 ) ;
V_110 = F_99 ( V_37 ) ;
V_212 = F_197 ( V_37 ) ;
F_40 ( V_211
L_59 ,
V_10 , V_110 , V_212 , V_213 ) ;
}
}
static inline void * F_201 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_159 * * V_214 )
{
void * V_41 ;
struct V_159 * V_160 = * V_214 ;
struct V_11 * V_11 ;
V_41 = F_167 ( V_2 , V_3 , V_10 , V_160 ) ;
if ( V_41 )
return V_41 ;
V_11 = F_125 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_160 = F_202 ( V_2 -> V_8 ) ;
if ( V_160 -> V_11 )
F_184 ( V_2 , V_160 ) ;
V_41 = V_11 -> V_41 ;
V_11 -> V_41 = NULL ;
F_10 ( V_2 , V_215 ) ;
V_160 -> V_11 = V_11 ;
* V_214 = V_160 ;
} else
V_41 = NULL ;
return V_41 ;
}
static inline bool F_153 ( struct V_11 * V_11 , T_5 V_209 )
{
if ( F_3 ( F_203 ( V_11 ) ) )
return F_204 ( V_209 ) ;
return true ;
}
static inline void * F_205 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_158 ;
unsigned long V_42 ;
void * V_41 ;
do {
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_158 . V_42 = V_42 ;
F_34 ( ! V_158 . V_145 ) ;
V_158 . V_24 = V_11 -> V_14 ;
V_158 . V_145 = V_41 != NULL ;
} while ( ! F_33 ( V_2 , V_11 ,
V_41 , V_42 ,
NULL , V_158 . V_42 ,
L_60 ) );
return V_41 ;
}
static void * F_206 ( struct V_1 * V_2 , T_5 V_209 , int V_10 ,
unsigned long V_18 , struct V_159 * V_160 )
{
void * V_41 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_42 ( V_3 ) ;
#ifdef F_175
V_160 = F_182 ( V_2 -> V_8 ) ;
#endif
V_11 = V_160 -> V_11 ;
if ( ! V_11 )
goto F_125;
V_193:
if ( F_3 ( ! F_190 ( V_11 , V_10 ) ) ) {
F_10 ( V_2 , V_216 ) ;
F_179 ( V_2 , V_11 , V_160 -> V_41 ) ;
V_160 -> V_11 = NULL ;
V_160 -> V_41 = NULL ;
goto F_125;
}
if ( F_3 ( ! F_153 ( V_11 , V_209 ) ) ) {
F_179 ( V_2 , V_11 , V_160 -> V_41 ) ;
V_160 -> V_11 = NULL ;
V_160 -> V_41 = NULL ;
goto F_125;
}
V_41 = V_160 -> V_41 ;
if ( V_41 )
goto V_217;
F_10 ( V_2 , V_218 ) ;
V_41 = F_205 ( V_2 , V_11 ) ;
if ( ! V_41 ) {
V_160 -> V_11 = NULL ;
F_10 ( V_2 , V_219 ) ;
goto F_125;
}
F_10 ( V_2 , V_220 ) ;
V_217:
F_34 ( ! V_160 -> V_11 -> V_145 ) ;
V_160 -> V_41 = F_16 ( V_2 , V_41 ) ;
V_160 -> V_177 = F_169 ( V_160 -> V_177 ) ;
F_43 ( V_3 ) ;
return V_41 ;
F_125:
if ( V_160 -> V_156 ) {
V_11 = V_160 -> V_11 = V_160 -> V_156 ;
V_160 -> V_156 = V_11 -> V_199 ;
F_10 ( V_2 , V_221 ) ;
V_160 -> V_41 = NULL ;
goto V_193;
}
V_41 = F_201 ( V_2 , V_209 , V_10 , & V_160 ) ;
if ( F_3 ( ! V_41 ) ) {
if ( ! ( V_209 & V_128 ) && F_207 () )
F_198 ( V_2 , V_209 , V_10 ) ;
F_43 ( V_3 ) ;
return NULL ;
}
V_11 = V_160 -> V_11 ;
if ( F_101 ( ! F_1 ( V_2 ) && F_153 ( V_11 , V_209 ) ) )
goto V_217;
if ( F_1 ( V_2 ) &&
! F_108 ( V_2 , V_11 , V_41 , V_18 ) )
goto F_125;
F_179 ( V_2 , V_11 , F_16 ( V_2 , V_41 ) ) ;
V_160 -> V_11 = NULL ;
V_160 -> V_41 = NULL ;
F_43 ( V_3 ) ;
return V_41 ;
}
static T_2 void * F_208 ( struct V_1 * V_2 ,
T_5 V_209 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_159 * V_160 ;
struct V_11 * V_11 ;
unsigned long V_177 ;
if ( F_81 ( V_2 , V_209 ) )
return NULL ;
V_2 = F_209 ( V_2 , V_209 ) ;
V_193:
F_210 () ;
V_160 = F_202 ( V_2 -> V_8 ) ;
V_177 = V_160 -> V_177 ;
F_211 () ;
V_12 = V_160 -> V_41 ;
V_11 = V_160 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_190 ( V_11 , V_10 ) ) )
V_12 = F_206 ( V_2 , V_209 , V_10 , V_18 , V_160 ) ;
else {
void * V_222 = F_19 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_212 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_177 ,
V_12 , V_177 ,
V_222 , F_169 ( V_177 ) ) ) ) {
F_173 ( L_61 , V_2 , V_177 ) ;
goto V_193;
}
F_17 ( V_2 , V_222 ) ;
F_10 ( V_2 , V_223 ) ;
}
if ( F_3 ( V_209 & V_224 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_85 ( V_2 , V_209 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_213 ( struct V_1 * V_2 ,
T_5 V_209 , unsigned long V_18 )
{
return F_208 ( V_2 , V_209 , V_125 , V_18 ) ;
}
void * F_214 ( struct V_1 * V_2 , T_5 V_209 )
{
void * V_225 = F_213 ( V_2 , V_209 , V_226 ) ;
F_215 ( V_226 , V_225 , V_2 -> V_21 ,
V_2 -> V_15 , V_209 ) ;
return V_225 ;
}
void * F_216 ( struct V_1 * V_2 , T_5 V_209 , T_1 V_15 )
{
void * V_225 = F_213 ( V_2 , V_209 , V_226 ) ;
F_217 ( V_226 , V_225 , V_15 , V_2 -> V_15 , V_209 ) ;
return V_225 ;
}
void * F_218 ( struct V_1 * V_2 , T_5 V_209 , int V_10 )
{
void * V_225 = F_208 ( V_2 , V_209 , V_10 , V_226 ) ;
F_219 ( V_226 , V_225 ,
V_2 -> V_21 , V_2 -> V_15 , V_209 , V_10 ) ;
return V_225 ;
}
void * F_220 ( struct V_1 * V_2 ,
T_5 V_209 ,
int V_10 , T_1 V_15 )
{
void * V_225 = F_208 ( V_2 , V_209 , V_10 , V_226 ) ;
F_221 ( V_226 , V_225 ,
V_15 , V_2 -> V_15 , V_209 , V_10 ) ;
return V_225 ;
}
static void F_222 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_192 ;
void * * V_12 = ( void * ) V_29 ;
int V_227 ;
struct V_11 V_158 ;
unsigned long V_42 ;
struct V_9 * V_37 = NULL ;
unsigned long V_228 ( V_3 ) ;
F_10 ( V_2 , V_229 ) ;
if ( F_1 ( V_2 ) &&
! ( V_37 = F_112 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_37 ) ) {
F_196 ( & V_37 -> V_163 , V_3 ) ;
V_37 = NULL ;
}
V_192 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_22 ( V_2 , V_12 , V_192 ) ;
V_158 . V_42 = V_42 ;
V_227 = V_158 . V_145 ;
V_158 . V_24 -- ;
if ( ( ! V_158 . V_24 || ! V_192 ) && ! V_227 ) {
if ( F_4 ( V_2 ) && ! V_192 )
V_158 . V_145 = 1 ;
else {
V_37 = F_13 ( V_2 , F_127 ( V_11 ) ) ;
F_194 ( & V_37 -> V_163 , V_3 ) ;
}
}
} while ( ! F_41 ( V_2 , V_11 ,
V_192 , V_42 ,
V_12 , V_158 . V_42 ,
L_62 ) );
if ( F_101 ( ! V_37 ) ) {
if ( V_158 . V_145 && ! V_227 ) {
F_154 ( V_2 , V_11 , 1 ) ;
F_10 ( V_2 , V_230 ) ;
}
if ( V_227 )
F_10 ( V_2 , V_231 ) ;
return;
}
if ( F_3 ( ! V_158 . V_24 && V_37 -> V_154 > V_2 -> V_175 ) )
goto V_232;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_192 ) ) {
if ( F_1 ( V_2 ) )
F_95 ( V_2 , V_11 ) ;
F_145 ( V_37 , V_11 , V_155 ) ;
F_10 ( V_2 , V_200 ) ;
}
F_196 ( & V_37 -> V_163 , V_3 ) ;
return;
V_232:
if ( V_192 ) {
F_147 ( V_37 , V_11 ) ;
F_10 ( V_2 , V_233 ) ;
} else
F_95 ( V_2 , V_11 ) ;
F_196 ( & V_37 -> V_163 , V_3 ) ;
F_10 ( V_2 , V_196 ) ;
F_144 ( V_2 , V_11 ) ;
}
static T_2 void F_223 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_159 * V_160 ;
unsigned long V_177 ;
F_88 ( V_2 , V_29 ) ;
V_193:
F_210 () ;
V_160 = F_202 ( V_2 -> V_8 ) ;
V_177 = V_160 -> V_177 ;
F_211 () ;
if ( F_101 ( V_11 == V_160 -> V_11 ) ) {
F_22 ( V_2 , V_12 , V_160 -> V_41 ) ;
if ( F_3 ( ! F_212 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_177 ,
V_160 -> V_41 , V_177 ,
V_12 , F_169 ( V_177 ) ) ) ) {
F_173 ( L_63 , V_2 , V_177 ) ;
goto V_193;
}
F_10 ( V_2 , V_234 ) ;
} else
F_222 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_224 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_225 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_223 ( V_2 , F_140 ( V_29 ) , V_29 , V_226 ) ;
F_226 ( V_226 , V_29 ) ;
}
static inline int F_227 ( int V_15 , int V_235 ,
int V_236 , int V_237 , int V_26 )
{
int V_25 ;
int V_238 ;
int V_239 = V_240 ;
if ( F_25 ( V_239 , V_15 , V_26 ) > V_100 )
return F_199 ( V_15 * V_100 ) - 1 ;
for ( V_25 = F_228 ( V_239 ,
F_229 ( V_235 * V_15 - 1 ) - V_241 ) ;
V_25 <= V_236 ; V_25 ++ ) {
unsigned long V_242 = V_27 << V_25 ;
if ( V_242 < V_235 * V_15 + V_26 )
continue;
V_238 = ( V_242 - V_26 ) % V_15 ;
if ( V_238 <= V_242 / V_237 )
break;
}
return V_25 ;
}
static inline int F_230 ( int V_15 , int V_26 )
{
int V_25 ;
int V_235 ;
int V_243 ;
int V_99 ;
V_235 = V_244 ;
if ( ! V_235 )
V_235 = 4 * ( F_229 ( V_245 ) + 1 ) ;
V_99 = F_25 ( V_246 , V_15 , V_26 ) ;
V_235 = V_131 ( V_235 , V_99 ) ;
while ( V_235 > 1 ) {
V_243 = 16 ;
while ( V_243 >= 4 ) {
V_25 = F_227 ( V_15 , V_235 ,
V_246 , V_243 , V_26 ) ;
if ( V_25 <= V_246 )
return V_25 ;
V_243 /= 2 ;
}
V_235 -- ;
}
V_25 = F_227 ( V_15 , 1 , V_246 , 1 , V_26 ) ;
if ( V_25 <= V_246 )
return V_25 ;
V_25 = F_227 ( V_15 , 1 , V_247 , 1 , V_26 ) ;
if ( V_25 < V_247 )
return V_25 ;
return - V_248 ;
}
static void
F_231 ( struct V_9 * V_37 )
{
V_37 -> V_154 = 0 ;
F_232 ( & V_37 -> V_163 ) ;
F_233 ( & V_37 -> V_156 ) ;
#ifdef F_2
F_234 ( & V_37 -> V_110 , 0 ) ;
F_234 ( & V_37 -> V_111 , 0 ) ;
F_233 ( & V_37 -> V_109 ) ;
#endif
}
static inline int F_235 ( struct V_1 * V_2 )
{
F_236 ( V_249 <
V_250 * sizeof( struct V_159 ) ) ;
V_2 -> V_8 = F_237 ( sizeof( struct V_159 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_176 ( V_2 ) ;
return 1 ;
}
static void F_238 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_37 ;
F_126 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_125 ( V_9 , V_251 , V_10 ) ;
F_126 ( ! V_11 ) ;
if ( F_127 ( V_11 ) != V_10 ) {
F_40 ( V_49 L_64
L_65 , V_10 ) ;
F_40 ( V_49 L_66
L_67 ) ;
}
V_37 = V_11 -> V_41 ;
F_126 ( ! V_37 ) ;
V_11 -> V_41 = F_16 ( V_9 , V_37 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_145 = 0 ;
V_9 -> V_10 [ V_10 ] = V_37 ;
#ifdef F_2
F_66 ( V_9 , V_37 , V_95 ) ;
F_53 ( V_9 , V_37 ) ;
#endif
F_231 ( V_37 ) ;
F_100 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_145 ( V_37 , V_11 , V_189 ) ;
}
static void F_239 ( struct V_1 * V_2 )
{
int V_10 ;
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = V_2 -> V_10 [ V_10 ] ;
if ( V_37 )
F_224 ( V_9 , V_37 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_241 ( struct V_1 * V_2 )
{
int V_10 ;
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 ;
if ( V_252 == V_253 ) {
F_238 ( V_10 ) ;
continue;
}
V_37 = F_218 ( V_9 ,
V_254 , V_10 ) ;
if ( ! V_37 ) {
F_239 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_37 ;
F_231 ( V_37 ) ;
}
return 1 ;
}
static void F_242 ( struct V_1 * V_2 , unsigned long V_131 )
{
if ( V_131 < V_255 )
V_131 = V_255 ;
else if ( V_131 > V_256 )
V_131 = V_256 ;
V_2 -> V_175 = V_131 ;
}
static int F_243 ( struct V_1 * V_2 , int V_257 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_244 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_111 )
V_2 -> V_3 |= V_79 ;
else
V_2 -> V_3 &= ~ V_79 ;
if ( ( V_3 & V_19 ) && V_15 == V_2 -> V_21 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_24 = V_15 ;
if ( ( ( V_3 & ( V_22 | V_20 ) ) ||
V_2 -> F_111 ) ) {
V_2 -> V_16 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_23 )
V_15 += 2 * sizeof( struct V_51 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_15 = F_244 ( V_15 , V_2 -> V_258 ) ;
V_2 -> V_15 = V_15 ;
if ( V_257 >= 0 )
V_25 = V_257 ;
else
V_25 = F_230 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_127 = 0 ;
if ( V_25 )
V_2 -> V_127 |= V_259 ;
if ( V_2 -> V_3 & V_260 )
V_2 -> V_127 |= V_261 ;
if ( V_2 -> V_3 & V_136 )
V_2 -> V_127 |= V_262 ;
V_2 -> V_123 = F_26 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_131 = F_26 ( F_199 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_28 ( V_2 -> V_123 ) > F_28 ( V_2 -> F_228 ) )
V_2 -> F_228 = V_2 -> V_123 ;
return ! ! F_28 ( V_2 -> V_123 ) ;
}
static int F_245 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_110 ( V_2 -> V_15 , V_3 , V_2 -> V_45 , V_2 -> F_111 ) ;
V_2 -> V_26 = 0 ;
if ( V_150 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_148 ) ;
if ( ! F_243 ( V_2 , - 1 ) )
goto error;
if ( V_119 ) {
if ( F_199 ( V_2 -> V_15 ) > F_199 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_263 ;
V_2 -> V_16 = 0 ;
if ( ! F_243 ( V_2 , - 1 ) )
goto error;
}
}
#if F_36 ( V_38 ) && \
F_36 ( V_39 )
if ( F_246 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_40 ;
#endif
F_242 ( V_2 , F_247 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_4 ( V_2 ) )
V_2 -> V_166 = 0 ;
else if ( V_2 -> V_15 >= V_27 )
V_2 -> V_166 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_166 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_166 = 13 ;
else
V_2 -> V_166 = 30 ;
#ifdef F_157
V_2 -> V_174 = 1000 ;
#endif
if ( ! F_241 ( V_2 ) )
goto error;
if ( F_235 ( V_2 ) )
return 0 ;
F_239 ( V_2 ) ;
error:
if ( V_3 & V_264 )
F_248 ( L_68
L_69 ,
V_2 -> V_45 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_27 ( V_2 -> V_123 ) , V_2 -> V_16 , V_3 ) ;
return - V_265 ;
}
static void F_249 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_47 )
{
#ifdef F_2
void * V_18 = F_15 ( V_11 ) ;
void * V_5 ;
unsigned long * V_46 = F_250 ( F_251 ( V_11 -> V_14 ) *
sizeof( long ) , V_208 ) ;
if ( ! V_46 )
return;
F_65 ( V_2 , V_11 , V_47 , V_2 -> V_45 ) ;
F_29 ( V_11 ) ;
F_44 ( V_2 , V_11 , V_46 ) ;
F_131 (p, s, addr, page->objects) {
if ( ! F_252 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) ) {
F_40 ( V_49 L_70 ,
V_5 , V_5 - V_18 ) ;
F_55 ( V_2 , V_5 ) ;
}
}
F_31 ( V_11 ) ;
F_253 ( V_46 ) ;
#endif
}
static void F_254 ( struct V_1 * V_2 , struct V_9 * V_37 )
{
struct V_11 * V_11 , * V_149 ;
F_152 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_147 ( V_37 , V_11 ) ;
F_144 ( V_2 , V_11 ) ;
} else {
F_249 ( V_2 , V_11 ,
L_71 ) ;
}
}
}
static inline int F_255 ( struct V_1 * V_2 )
{
int V_10 ;
F_188 ( V_2 ) ;
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
F_254 ( V_2 , V_37 ) ;
if ( V_37 -> V_154 || F_97 ( V_2 , V_10 ) )
return 1 ;
}
F_256 ( V_2 -> V_8 ) ;
F_239 ( V_2 ) ;
return 0 ;
}
int F_257 ( struct V_1 * V_2 )
{
int V_266 = F_255 ( V_2 ) ;
if ( ! V_266 ) {
F_258 ( & V_267 ) ;
F_8 ( V_2 ) ;
F_259 ( & V_267 ) ;
}
return V_266 ;
}
static int T_7 F_260 ( char * V_114 )
{
F_261 ( & V_114 , & V_240 ) ;
return 1 ;
}
static int T_7 F_262 ( char * V_114 )
{
F_261 ( & V_114 , & V_246 ) ;
V_246 = V_131 ( V_246 , V_247 - 1 ) ;
return 1 ;
}
static int T_7 F_263 ( char * V_114 )
{
F_261 ( & V_114 , & V_244 ) ;
return 1 ;
}
static int T_7 F_264 ( char * V_114 )
{
V_268 = 1 ;
return 1 ;
}
void * F_265 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_225 ;
if ( F_3 ( V_15 > V_269 ) )
return F_266 ( V_15 , V_3 ) ;
V_2 = F_267 ( V_15 , V_3 ) ;
if ( F_3 ( F_268 ( V_2 ) ) )
return V_2 ;
V_225 = F_213 ( V_2 , V_3 , V_226 ) ;
F_217 ( V_226 , V_225 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_225 ;
}
static void * F_269 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_102 = NULL ;
V_3 |= V_259 | V_124 | V_270 ;
V_11 = F_270 ( V_10 , V_3 , F_199 ( V_15 ) ) ;
if ( V_11 )
V_102 = F_15 ( V_11 ) ;
F_77 ( V_102 , V_15 , V_3 ) ;
return V_102 ;
}
void * F_271 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_225 ;
if ( F_3 ( V_15 > V_269 ) ) {
V_225 = F_269 ( V_15 , V_3 , V_10 ) ;
F_221 ( V_226 , V_225 ,
V_15 , V_27 << F_199 ( V_15 ) ,
V_3 , V_10 ) ;
return V_225 ;
}
V_2 = F_267 ( V_15 , V_3 ) ;
if ( F_3 ( F_268 ( V_2 ) ) )
return V_2 ;
V_225 = F_208 ( V_2 , V_3 , V_10 , V_226 ) ;
F_221 ( V_226 , V_225 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_225 ;
}
T_1 F_272 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_271 ) )
return 0 ;
V_11 = F_140 ( V_12 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
F_149 ( ! F_273 ( V_11 ) ) ;
return V_27 << F_72 ( V_11 ) ;
}
return F_24 ( V_11 -> V_143 ) ;
}
void F_253 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_274 ( V_226 , V_29 ) ;
if ( F_3 ( F_268 ( V_29 ) ) )
return;
V_11 = F_140 ( V_29 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
F_126 ( ! F_273 ( V_11 ) ) ;
F_79 ( V_29 ) ;
F_138 ( V_11 , F_72 ( V_11 ) ) ;
return;
}
F_223 ( V_11 -> V_143 , V_11 , V_12 , V_226 ) ;
}
int F_275 ( struct V_1 * V_2 )
{
int V_10 ;
int V_56 ;
struct V_9 * V_37 ;
struct V_11 * V_11 ;
struct V_11 * V_71 ;
int V_14 = F_28 ( V_2 -> F_228 ) ;
struct V_151 * V_272 =
F_276 ( sizeof( struct V_151 ) * V_14 , V_254 ) ;
unsigned long V_3 ;
if ( ! V_272 )
return - V_273 ;
F_188 ( V_2 ) ;
F_240 (node, N_NORMAL_MEMORY) {
V_37 = F_13 ( V_2 , V_10 ) ;
if ( ! V_37 -> V_154 )
continue;
for ( V_56 = 0 ; V_56 < V_14 ; V_56 ++ )
F_233 ( V_272 + V_56 ) ;
F_194 ( & V_37 -> V_163 , V_3 ) ;
F_152 (page, t, &n->partial, lru) {
F_277 ( & V_11 -> V_108 , V_272 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_37 -> V_154 -- ;
}
for ( V_56 = V_14 - 1 ; V_56 > 0 ; V_56 -- )
F_278 ( V_272 + V_56 , V_37 -> V_156 . V_274 ) ;
F_196 ( & V_37 -> V_163 , V_3 ) ;
F_152 (page, t, slabs_by_inuse, lru)
F_144 ( V_2 , V_11 ) ;
}
F_253 ( V_272 ) ;
return 0 ;
}
static int F_279 ( void * V_275 )
{
struct V_1 * V_2 ;
F_259 ( & V_267 ) ;
F_195 (s, &slab_caches, list)
F_275 ( V_2 ) ;
F_258 ( & V_267 ) ;
return 0 ;
}
static void F_280 ( void * V_275 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_276 * V_277 = V_275 ;
int V_278 ;
V_278 = V_277 -> V_279 ;
if ( V_278 < 0 )
return;
F_259 ( & V_267 ) ;
F_195 (s, &slab_caches, list) {
V_37 = F_13 ( V_2 , V_278 ) ;
if ( V_37 ) {
F_126 ( F_97 ( V_2 , V_278 ) ) ;
V_2 -> V_10 [ V_278 ] = NULL ;
F_224 ( V_9 , V_37 ) ;
}
}
F_258 ( & V_267 ) ;
}
static int F_281 ( void * V_275 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_276 * V_277 = V_275 ;
int V_210 = V_277 -> V_279 ;
int V_225 = 0 ;
if ( V_210 < 0 )
return 0 ;
F_259 ( & V_267 ) ;
F_195 (s, &slab_caches, list) {
V_37 = F_214 ( V_9 , V_254 ) ;
if ( ! V_37 ) {
V_225 = - V_273 ;
goto V_117;
}
F_231 ( V_37 ) ;
V_2 -> V_10 [ V_210 ] = V_37 ;
}
V_117:
F_258 ( & V_267 ) ;
return V_225 ;
}
static int F_282 ( struct V_280 * V_281 ,
unsigned long V_282 , void * V_275 )
{
int V_225 = 0 ;
switch ( V_282 ) {
case V_283 :
V_225 = F_281 ( V_275 ) ;
break;
case V_284 :
V_225 = F_279 ( V_275 ) ;
break;
case V_285 :
case V_286 :
F_280 ( V_275 ) ;
break;
case V_287 :
case V_288 :
break;
}
if ( V_225 )
V_225 = F_283 ( V_225 ) ;
else
V_225 = V_289 ;
return V_225 ;
}
static struct V_1 * T_7 F_284 ( struct V_1 * V_290 )
{
int V_10 ;
struct V_1 * V_2 = F_285 ( V_1 , V_251 ) ;
memcpy ( V_2 , V_290 , V_1 -> V_21 ) ;
F_185 ( V_2 , F_52 () ) ;
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_37 ) {
F_195 (p, &n->partial, lru)
V_5 -> V_143 = V_2 ;
#ifdef F_2
F_195 (p, &n->full, lru)
V_5 -> V_143 = V_2 ;
#endif
}
}
F_94 ( & V_2 -> V_291 , & V_292 ) ;
return V_2 ;
}
void T_7 F_286 ( void )
{
static V_293 struct V_1 V_294 ,
V_295 ;
if ( F_287 () )
V_246 = 0 ;
V_9 = & V_295 ;
V_1 = & V_294 ;
F_288 ( V_9 , L_72 ,
sizeof( struct V_9 ) , V_296 ) ;
F_289 ( & V_297 ) ;
V_252 = V_298 ;
F_288 ( V_1 , L_73 ,
F_290 ( struct V_1 , V_10 ) +
V_299 * sizeof( struct V_9 * ) ,
V_296 ) ;
V_1 = F_284 ( & V_294 ) ;
V_9 = F_284 ( & V_295 ) ;
F_291 ( 0 ) ;
#ifdef F_292
F_293 ( & V_300 ) ;
#endif
F_40 ( V_44
L_74
L_75 ,
F_294 () ,
V_240 , V_246 , V_244 ,
V_245 , V_299 ) ;
}
void T_7 F_295 ( void )
{
}
static int F_296 ( struct V_1 * V_2 )
{
if ( V_268 || ( V_2 -> V_3 & V_301 ) )
return 1 ;
if ( V_2 -> F_111 )
return 1 ;
if ( V_2 -> V_302 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_297 ( struct V_303 * V_304 , T_1 V_15 ,
T_1 V_258 , unsigned long V_3 , const char * V_45 ,
void (* F_111)( void * ) )
{
struct V_1 * V_2 ;
if ( V_268 || ( V_3 & V_301 ) )
return NULL ;
if ( F_111 )
return NULL ;
V_15 = F_244 ( V_15 , sizeof( void * ) ) ;
V_258 = F_298 ( V_3 , V_258 , V_15 ) ;
V_15 = F_244 ( V_15 , V_258 ) ;
V_3 = F_110 ( V_15 , V_3 , V_45 , NULL ) ;
F_195 (s, &slab_caches, list) {
if ( F_296 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_305 ) != ( V_2 -> V_3 & V_305 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_258 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
if ( ! F_299 ( V_2 , V_304 ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_300 ( struct V_303 * V_304 , const char * V_45 , T_1 V_15 ,
T_1 V_258 , unsigned long V_3 , void (* F_111)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_297 ( V_304 , V_15 , V_258 , V_3 , V_45 , F_111 ) ;
if ( V_2 ) {
V_2 -> V_302 ++ ;
V_2 -> V_21 = F_228 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_301 ( int , V_2 -> V_24 , F_244 ( V_15 , sizeof( void * ) ) ) ;
if ( F_7 ( V_2 , V_45 ) ) {
V_2 -> V_302 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_302 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_306 ;
V_306 = F_245 ( V_2 , V_3 ) ;
if ( V_306 )
return V_306 ;
if ( V_252 <= V_307 )
return 0 ;
F_9 ( V_2 ) ;
F_258 ( & V_267 ) ;
V_306 = F_6 ( V_2 ) ;
F_259 ( & V_267 ) ;
if ( V_306 )
F_255 ( V_2 ) ;
return V_306 ;
}
static int F_303 ( struct V_280 * V_308 ,
unsigned long V_282 , void * V_309 )
{
long V_64 = ( long ) V_309 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_282 ) {
case V_310 :
case V_311 :
case V_312 :
case V_313 :
F_259 ( & V_267 ) ;
F_195 (s, &slab_caches, list) {
F_42 ( V_3 ) ;
F_185 ( V_2 , V_64 ) ;
F_43 ( V_3 ) ;
}
F_258 ( & V_267 ) ;
break;
default:
break;
}
return V_289 ;
}
void * F_304 ( T_1 V_15 , T_5 V_209 , unsigned long V_314 )
{
struct V_1 * V_2 ;
void * V_225 ;
if ( F_3 ( V_15 > V_269 ) )
return F_266 ( V_15 , V_209 ) ;
V_2 = F_267 ( V_15 , V_209 ) ;
if ( F_3 ( F_268 ( V_2 ) ) )
return V_2 ;
V_225 = F_213 ( V_2 , V_209 , V_314 ) ;
F_217 ( V_314 , V_225 , V_15 , V_2 -> V_15 , V_209 ) ;
return V_225 ;
}
void * F_305 ( T_1 V_15 , T_5 V_209 ,
int V_10 , unsigned long V_314 )
{
struct V_1 * V_2 ;
void * V_225 ;
if ( F_3 ( V_15 > V_269 ) ) {
V_225 = F_269 ( V_15 , V_209 , V_10 ) ;
F_221 ( V_314 , V_225 ,
V_15 , V_27 << F_199 ( V_15 ) ,
V_209 , V_10 ) ;
return V_225 ;
}
V_2 = F_267 ( V_15 , V_209 ) ;
if ( F_3 ( F_268 ( V_2 ) ) )
return V_2 ;
V_225 = F_208 ( V_2 , V_209 , V_10 , V_314 ) ;
F_221 ( V_314 , V_225 , V_15 , V_2 -> V_15 , V_209 , V_10 ) ;
return V_225 ;
}
static int F_306 ( struct V_11 * V_11 )
{
return V_11 -> V_24 ;
}
static int F_307 ( struct V_11 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_308 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_18 = F_15 ( V_11 ) ;
if ( ! F_74 ( V_2 , V_11 ) ||
! F_76 ( V_2 , V_11 , NULL ) )
return 0 ;
F_309 ( V_46 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_46 ) ;
F_131 (p, s, addr, page->objects) {
if ( F_252 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_73 ( V_2 , V_11 , V_5 , V_112 ) )
return 0 ;
}
F_131 (p, s, addr, page->objects)
if ( ! F_252 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_73 ( V_2 , V_11 , V_5 , V_95 ) )
return 0 ;
return 1 ;
}
static void F_310 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
F_29 ( V_11 ) ;
F_308 ( V_2 , V_11 , V_46 ) ;
F_31 ( V_11 ) ;
}
static int F_311 ( struct V_1 * V_2 ,
struct V_9 * V_37 , unsigned long * V_46 )
{
unsigned long V_315 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_194 ( & V_37 -> V_163 , V_3 ) ;
F_195 (page, &n->partial, lru) {
F_310 ( V_2 , V_11 , V_46 ) ;
V_315 ++ ;
}
if ( V_315 != V_37 -> V_154 )
F_40 ( V_49 L_76
L_77 , V_2 -> V_45 , V_315 , V_37 -> V_154 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_117;
F_195 (page, &n->full, lru) {
F_310 ( V_2 , V_11 , V_46 ) ;
V_315 ++ ;
}
if ( V_315 != F_98 ( & V_37 -> V_110 ) )
F_40 ( V_49 L_78
L_77 , V_2 -> V_45 , V_315 ,
F_98 ( & V_37 -> V_110 ) ) ;
V_117:
F_196 ( & V_37 -> V_163 , V_3 ) ;
return V_315 ;
}
static long F_312 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_315 = 0 ;
unsigned long * V_46 = F_276 ( F_251 ( F_28 ( V_2 -> F_228 ) ) *
sizeof( unsigned long ) , V_254 ) ;
if ( ! V_46 )
return - V_273 ;
F_188 ( V_2 ) ;
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
V_315 += F_311 ( V_2 , V_37 , V_46 ) ;
}
F_253 ( V_46 ) ;
return V_315 ;
}
static void F_313 ( struct V_316 * V_71 )
{
if ( V_71 -> F_228 )
F_314 ( ( unsigned long ) V_71 -> V_317 ,
F_199 ( sizeof( struct V_318 ) * V_71 -> F_228 ) ) ;
}
static int F_315 ( struct V_316 * V_71 , unsigned long F_228 , T_5 V_3 )
{
struct V_318 * V_186 ;
int V_25 ;
V_25 = F_199 ( sizeof( struct V_318 ) * F_228 ) ;
V_186 = ( void * ) F_316 ( V_3 , V_25 ) ;
if ( ! V_186 )
return 0 ;
if ( V_71 -> V_315 ) {
memcpy ( V_186 , V_71 -> V_317 , sizeof( struct V_318 ) * V_71 -> V_315 ) ;
F_313 ( V_71 ) ;
}
V_71 -> F_228 = F_228 ;
V_71 -> V_317 = V_186 ;
return 1 ;
}
static int F_317 ( struct V_316 * V_71 , struct V_1 * V_2 ,
const struct V_51 * V_51 )
{
long V_87 , V_91 , V_319 ;
struct V_318 * V_186 ;
unsigned long V_320 ;
unsigned long V_321 = V_68 - V_51 -> V_67 ;
V_87 = - 1 ;
V_91 = V_71 -> V_315 ;
for ( ; ; ) {
V_319 = V_87 + ( V_91 - V_87 + 1 ) / 2 ;
if ( V_319 == V_91 )
break;
V_320 = V_71 -> V_317 [ V_319 ] . V_18 ;
if ( V_51 -> V_18 == V_320 ) {
V_186 = & V_71 -> V_317 [ V_319 ] ;
V_186 -> V_315 ++ ;
if ( V_51 -> V_67 ) {
V_186 -> V_322 += V_321 ;
if ( V_321 < V_186 -> V_323 )
V_186 -> V_323 = V_321 ;
if ( V_321 > V_186 -> V_324 )
V_186 -> V_324 = V_321 ;
if ( V_51 -> V_65 < V_186 -> V_325 )
V_186 -> V_325 = V_51 -> V_65 ;
if ( V_51 -> V_65 > V_186 -> V_326 )
V_186 -> V_326 = V_51 -> V_65 ;
F_318 ( V_51 -> V_64 ,
F_319 ( V_186 -> V_327 ) ) ;
}
F_320 ( F_127 ( F_321 ( V_51 ) ) , V_186 -> V_328 ) ;
return 1 ;
}
if ( V_51 -> V_18 < V_320 )
V_91 = V_319 ;
else
V_87 = V_319 ;
}
if ( V_71 -> V_315 >= V_71 -> F_228 && ! F_315 ( V_71 , 2 * V_71 -> F_228 , V_208 ) )
return 0 ;
V_186 = V_71 -> V_317 + V_319 ;
if ( V_319 < V_71 -> V_315 )
memmove ( V_186 + 1 , V_186 ,
( V_71 -> V_315 - V_319 ) * sizeof( struct V_318 ) ) ;
V_71 -> V_315 ++ ;
V_186 -> V_315 = 1 ;
V_186 -> V_18 = V_51 -> V_18 ;
V_186 -> V_322 = V_321 ;
V_186 -> V_323 = V_321 ;
V_186 -> V_324 = V_321 ;
V_186 -> V_325 = V_51 -> V_65 ;
V_186 -> V_326 = V_51 -> V_65 ;
F_322 ( F_319 ( V_186 -> V_327 ) ) ;
F_318 ( V_51 -> V_64 , F_319 ( V_186 -> V_327 ) ) ;
F_323 ( V_186 -> V_328 ) ;
F_320 ( F_127 ( F_321 ( V_51 ) ) , V_186 -> V_328 ) ;
return 1 ;
}
static void F_324 ( struct V_316 * V_71 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_52 V_53 ,
unsigned long * V_46 )
{
void * V_18 = F_15 ( V_11 ) ;
void * V_5 ;
F_309 ( V_46 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_46 ) ;
F_131 (p, s, addr, page->objects)
if ( ! F_252 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) )
F_317 ( V_71 , V_2 , F_48 ( V_2 , V_5 , V_53 ) ) ;
}
static int F_325 ( struct V_1 * V_2 , char * V_73 ,
enum V_52 V_53 )
{
int V_329 = 0 ;
unsigned long V_56 ;
struct V_316 V_71 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_46 = F_276 ( F_251 ( F_28 ( V_2 -> F_228 ) ) *
sizeof( unsigned long ) , V_254 ) ;
if ( ! V_46 || ! F_315 ( & V_71 , V_27 / sizeof( struct V_318 ) ,
V_330 ) ) {
F_253 ( V_46 ) ;
return sprintf ( V_73 , L_79 ) ;
}
F_188 ( V_2 ) ;
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_98 ( & V_37 -> V_110 ) )
continue;
F_194 ( & V_37 -> V_163 , V_3 ) ;
F_195 (page, &n->partial, lru)
F_324 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_195 (page, &n->full, lru)
F_324 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_196 ( & V_37 -> V_163 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_315 ; V_56 ++ ) {
struct V_318 * V_186 = & V_71 . V_317 [ V_56 ] ;
if ( V_329 > V_27 - V_331 - 100 )
break;
V_329 += sprintf ( V_73 + V_329 , L_80 , V_186 -> V_315 ) ;
if ( V_186 -> V_18 )
V_329 += sprintf ( V_73 + V_329 , L_81 , ( void * ) V_186 -> V_18 ) ;
else
V_329 += sprintf ( V_73 + V_329 , L_82 ) ;
if ( V_186 -> V_322 != V_186 -> V_323 ) {
V_329 += sprintf ( V_73 + V_329 , L_83 ,
V_186 -> V_323 ,
( long ) F_326 ( V_186 -> V_322 , V_186 -> V_315 ) ,
V_186 -> V_324 ) ;
} else
V_329 += sprintf ( V_73 + V_329 , L_84 ,
V_186 -> V_323 ) ;
if ( V_186 -> V_325 != V_186 -> V_326 )
V_329 += sprintf ( V_73 + V_329 , L_85 ,
V_186 -> V_325 , V_186 -> V_326 ) ;
else
V_329 += sprintf ( V_73 + V_329 , L_86 ,
V_186 -> V_325 ) ;
if ( F_327 () > 1 &&
! F_328 ( F_319 ( V_186 -> V_327 ) ) &&
V_329 < V_27 - 60 ) {
V_329 += sprintf ( V_73 + V_329 , L_87 ) ;
V_329 += F_329 ( V_73 + V_329 ,
V_27 - V_329 - 50 ,
F_319 ( V_186 -> V_327 ) ) ;
}
if ( V_332 > 1 && ! F_330 ( V_186 -> V_328 ) &&
V_329 < V_27 - 60 ) {
V_329 += sprintf ( V_73 + V_329 , L_88 ) ;
V_329 += F_331 ( V_73 + V_329 ,
V_27 - V_329 - 50 ,
V_186 -> V_328 ) ;
}
V_329 += sprintf ( V_73 + V_329 , L_89 ) ;
}
F_313 ( & V_71 ) ;
F_253 ( V_46 ) ;
if ( ! V_71 . V_315 )
V_329 += sprintf ( V_73 , L_90 ) ;
return V_329 ;
}
static void F_332 ( void )
{
T_3 * V_5 ;
F_236 ( V_333 > 16 || V_250 < 10 ) ;
F_40 ( V_49 L_91 ) ;
F_40 ( V_49 L_92 ) ;
F_40 ( V_49 L_93 ) ;
V_5 = F_250 ( 16 , V_254 ) ;
V_5 [ 16 ] = 0x12 ;
F_40 ( V_49 L_94
L_95 , V_5 + 16 ) ;
F_312 ( V_334 [ 4 ] ) ;
V_5 = F_250 ( 32 , V_254 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_40 ( V_49 L_96
L_97 , V_5 ) ;
F_40 ( V_49
L_98 ) ;
F_312 ( V_334 [ 5 ] ) ;
V_5 = F_250 ( 64 , V_254 ) ;
V_5 += 64 + ( F_159 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_40 ( V_49 L_99 ,
V_5 ) ;
F_40 ( V_49
L_98 ) ;
F_312 ( V_334 [ 6 ] ) ;
F_40 ( V_49 L_100 ) ;
V_5 = F_250 ( 128 , V_254 ) ;
F_253 ( V_5 ) ;
* V_5 = 0x78 ;
F_40 ( V_49 L_101 , V_5 ) ;
F_312 ( V_334 [ 7 ] ) ;
V_5 = F_250 ( 256 , V_254 ) ;
F_253 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_40 ( V_49 L_102 ,
V_5 ) ;
F_312 ( V_334 [ 8 ] ) ;
V_5 = F_250 ( 512 , V_254 ) ;
F_253 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_40 ( V_49 L_103 , V_5 ) ;
F_312 ( V_334 [ 9 ] ) ;
}
static void F_332 ( void ) {}
static T_9 F_333 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_335 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_328 ;
V_328 = F_250 ( sizeof( unsigned long ) * V_299 , V_254 ) ;
if ( ! V_328 )
return - V_273 ;
if ( V_3 & V_336 ) {
int V_64 ;
F_177 (cpu) {
struct V_159 * V_160 = F_178 ( V_2 -> V_8 ,
V_64 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_334 ( V_160 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_127 ( V_11 ) ;
if ( V_3 & V_337 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_338 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_335 += V_29 ;
V_328 [ V_10 ] += V_29 ;
V_11 = F_334 ( V_160 -> V_156 ) ;
if ( V_11 ) {
V_29 = V_11 -> V_203 ;
V_335 += V_29 ;
V_328 [ V_10 ] += V_29 ;
}
}
}
F_335 () ;
#ifdef F_2
if ( V_3 & V_339 ) {
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( V_3 & V_337 )
V_29 = F_98 ( & V_37 -> V_111 ) ;
else if ( V_3 & V_338 )
V_29 = F_98 ( & V_37 -> V_111 ) -
F_192 ( V_37 , F_191 ) ;
else
V_29 = F_98 ( & V_37 -> V_110 ) ;
V_335 += V_29 ;
V_328 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_340 ) {
F_240 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( V_3 & V_337 )
V_29 = F_192 ( V_37 , F_307 ) ;
else if ( V_3 & V_338 )
V_29 = F_192 ( V_37 , F_306 ) ;
else
V_29 = V_37 -> V_154 ;
V_335 += V_29 ;
V_328 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_73 , L_104 , V_335 ) ;
#ifdef F_157
F_240 (node, N_NORMAL_MEMORY)
if ( V_328 [ V_10 ] )
V_29 += sprintf ( V_73 + V_29 , L_105 ,
V_10 , V_328 [ V_10 ] ) ;
#endif
F_336 () ;
F_253 ( V_328 ) ;
return V_29 + sprintf ( V_73 + V_29 , L_89 ) ;
}
static int F_337 ( struct V_1 * V_2 )
{
int V_10 ;
F_200 (node) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
if ( F_98 ( & V_37 -> V_111 ) )
return 1 ;
}
return 0 ;
}
static T_9 F_338 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , V_2 -> V_15 ) ;
}
static T_9 F_339 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , V_2 -> V_258 ) ;
}
static T_9 F_340 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , V_2 -> V_21 ) ;
}
static T_9 F_341 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , F_28 ( V_2 -> V_123 ) ) ;
}
static T_9 F_342 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_25 ;
int V_306 ;
V_306 = F_343 ( V_73 , 10 , & V_25 ) ;
if ( V_306 )
return V_306 ;
if ( V_25 > V_246 || V_25 < V_240 )
return - V_265 ;
F_243 ( V_2 , V_25 ) ;
return V_48 ;
}
static T_9 F_344 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , F_27 ( V_2 -> V_123 ) ) ;
}
static T_9 F_345 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_175 ) ;
}
static T_9 F_346 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_131 ;
int V_306 ;
V_306 = F_343 ( V_73 , 10 , & V_131 ) ;
if ( V_306 )
return V_306 ;
F_242 ( V_2 , V_131 ) ;
return V_48 ;
}
static T_9 F_347 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_108 , V_2 -> V_166 ) ;
}
static T_9 F_348 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_14 ;
int V_306 ;
V_306 = F_343 ( V_73 , 10 , & V_14 ) ;
if ( V_306 )
return V_306 ;
if ( V_14 && ! F_4 ( V_2 ) )
return - V_265 ;
V_2 -> V_166 = V_14 ;
F_188 ( V_2 ) ;
return V_48 ;
}
static T_9 F_349 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! V_2 -> F_111 )
return 0 ;
return sprintf ( V_73 , L_109 , V_2 -> F_111 ) ;
}
static T_9 F_350 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , V_2 -> V_302 - 1 ) ;
}
static T_9 F_351 ( struct V_1 * V_2 , char * V_73 )
{
return F_333 ( V_2 , V_73 , V_340 ) ;
}
static T_9 F_352 ( struct V_1 * V_2 , char * V_73 )
{
return F_333 ( V_2 , V_73 , V_336 ) ;
}
static T_9 F_353 ( struct V_1 * V_2 , char * V_73 )
{
return F_333 ( V_2 , V_73 , V_339 | V_338 ) ;
}
static T_9 F_354 ( struct V_1 * V_2 , char * V_73 )
{
return F_333 ( V_2 , V_73 , V_340 | V_338 ) ;
}
static T_9 F_355 ( struct V_1 * V_2 , char * V_73 )
{
int V_14 = 0 ;
int V_135 = 0 ;
int V_64 ;
int V_329 ;
F_356 (cpu) {
struct V_11 * V_11 = F_178 ( V_2 -> V_8 , V_64 ) -> V_156 ;
if ( V_11 ) {
V_135 += V_11 -> V_135 ;
V_14 += V_11 -> V_203 ;
}
}
V_329 = sprintf ( V_73 , L_110 , V_14 , V_135 ) ;
#ifdef F_292
F_356 (cpu) {
struct V_11 * V_11 = F_178 ( V_2 -> V_8 , V_64 ) -> V_156 ;
if ( V_11 && V_329 < V_27 - 20 )
V_329 += sprintf ( V_73 + V_329 , L_111 , V_64 ,
V_11 -> V_203 , V_11 -> V_135 ) ;
}
#endif
return V_329 + sprintf ( V_73 + V_329 , L_89 ) ;
}
static T_9 F_357 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_136 ) ) ;
}
static T_9 F_358 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_136 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_136 ;
return V_48 ;
}
static T_9 F_359 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_296 ) ) ;
}
static T_9 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_260 ) ) ;
}
static T_9 F_361 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_9 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , V_2 -> V_26 ) ;
}
static T_9 F_363 ( struct V_1 * V_2 , char * V_73 )
{
return F_333 ( V_2 , V_73 , V_339 ) ;
}
static T_9 F_364 ( struct V_1 * V_2 , char * V_73 )
{
return F_333 ( V_2 , V_73 , V_339 | V_337 ) ;
}
static T_9 F_365 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_120 ) ) ;
}
static T_9 F_366 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_120 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_120 ;
}
return V_48 ;
}
static T_9 F_367 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_9 F_368 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_101 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_101 ;
}
return V_48 ;
}
static T_9 F_369 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_9 F_370 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_337 ( V_2 ) )
return - V_341 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_19 ;
}
F_243 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_9 F_371 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_372 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_337 ( V_2 ) )
return - V_341 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_20 ;
}
F_243 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_9 F_373 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_9 F_374 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_337 ( V_2 ) )
return - V_341 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_23 ;
}
F_243 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_9 F_375 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_9 F_376 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
int V_225 = - V_265 ;
if ( V_73 [ 0 ] == '1' ) {
V_225 = F_312 ( V_2 ) ;
if ( V_225 >= 0 )
V_225 = V_48 ;
}
return V_225 ;
}
static T_9 F_377 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_248 ;
return F_325 ( V_2 , V_73 , V_70 ) ;
}
static T_9 F_378 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_248 ;
return F_325 ( V_2 , V_73 , V_69 ) ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , ! ! ( V_2 -> V_3 & V_121 ) ) ;
}
static T_9 F_380 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_121 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_121 ;
return V_48 ;
}
static T_9 F_381 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_9 F_382 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( V_73 [ 0 ] == '1' ) {
int V_266 = F_275 ( V_2 ) ;
if ( V_266 )
return V_266 ;
} else
return - V_265 ;
return V_48 ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_106 , V_2 -> V_174 / 10 ) ;
}
static T_9 F_384 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_342 ;
int V_306 ;
V_306 = F_343 ( V_73 , 10 , & V_342 ) ;
if ( V_306 )
return V_306 ;
if ( V_342 <= 100 )
V_2 -> V_174 = V_342 * 10 ;
return V_48 ;
}
static int F_385 ( struct V_1 * V_2 , char * V_73 , enum V_6 V_7 )
{
unsigned long V_343 = 0 ;
int V_64 ;
int V_329 ;
int * V_83 = F_276 ( V_245 * sizeof( int ) , V_254 ) ;
if ( ! V_83 )
return - V_273 ;
F_356 (cpu) {
unsigned V_29 = F_178 ( V_2 -> V_8 , V_64 ) -> F_10 [ V_7 ] ;
V_83 [ V_64 ] = V_29 ;
V_343 += V_29 ;
}
V_329 = sprintf ( V_73 , L_104 , V_343 ) ;
#ifdef F_292
F_356 (cpu) {
if ( V_83 [ V_64 ] && V_329 < V_27 - 20 )
V_329 += sprintf ( V_73 + V_329 , L_112 , V_64 , V_83 [ V_64 ] ) ;
}
#endif
F_253 ( V_83 ) ;
return V_329 + sprintf ( V_73 + V_329 , L_89 ) ;
}
static void F_386 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_64 ;
F_356 (cpu)
F_178 ( V_2 -> V_8 , V_64 ) -> F_10 [ V_7 ] = 0 ;
}
static T_9 F_387 ( struct V_344 * V_345 ,
struct V_346 * V_347 ,
char * V_73 )
{
struct V_348 * V_346 ;
struct V_1 * V_2 ;
int V_306 ;
V_346 = F_388 ( V_347 ) ;
V_2 = F_389 ( V_345 ) ;
if ( ! V_346 -> V_349 )
return - V_350 ;
V_306 = V_346 -> V_349 ( V_2 , V_73 ) ;
return V_306 ;
}
static T_9 F_390 ( struct V_344 * V_345 ,
struct V_346 * V_347 ,
const char * V_73 , T_1 V_329 )
{
struct V_348 * V_346 ;
struct V_1 * V_2 ;
int V_306 ;
V_346 = F_388 ( V_347 ) ;
V_2 = F_389 ( V_345 ) ;
if ( ! V_346 -> V_351 )
return - V_350 ;
V_306 = V_346 -> V_351 ( V_2 , V_73 , V_329 ) ;
#ifdef F_391
if ( V_252 >= V_352 && V_306 >= 0 && F_392 ( V_2 ) ) {
int V_56 ;
F_259 ( & V_267 ) ;
if ( V_2 -> V_353 < V_329 )
V_2 -> V_353 = V_329 ;
F_393 (i) {
struct V_1 * V_160 = F_394 ( V_2 , V_56 ) ;
if ( V_160 )
V_346 -> V_351 ( V_160 , V_73 , V_329 ) ;
}
F_258 ( & V_267 ) ;
}
#endif
return V_306 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_391
int V_56 ;
char * V_354 = NULL ;
if ( ! F_392 ( V_2 ) )
return;
if ( ! V_2 -> V_353 )
return;
for ( V_56 = 0 ; V_56 < F_395 ( V_355 ) ; V_56 ++ ) {
char V_356 [ 64 ] ;
char * V_73 ;
struct V_348 * V_347 = F_388 ( V_355 [ V_56 ] ) ;
if ( ! V_347 || ! V_347 -> V_351 || ! V_347 -> V_349 )
continue;
if ( V_354 )
V_73 = V_354 ;
else if ( V_2 -> V_353 < F_395 ( V_356 ) )
V_73 = V_356 ;
else {
V_354 = ( char * ) F_396 ( V_254 ) ;
if ( F_149 ( ! V_354 ) )
continue;
V_73 = V_354 ;
}
V_347 -> V_349 ( V_2 -> V_357 -> V_358 , V_73 ) ;
V_347 -> V_351 ( V_2 , V_73 , strlen ( V_73 ) ) ;
}
if ( V_354 )
F_397 ( ( unsigned long ) V_354 ) ;
#endif
}
static int F_398 ( struct V_359 * V_359 , struct V_344 * V_345 )
{
struct V_360 * V_361 = F_399 ( V_345 ) ;
if ( V_361 == & V_362 )
return 1 ;
return 0 ;
}
static char * F_400 ( struct V_1 * V_2 )
{
char * V_45 = F_276 ( V_363 , V_254 ) ;
char * V_5 = V_45 ;
F_126 ( ! V_45 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_260 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_136 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_120 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_134 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_45 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_113 , V_2 -> V_15 ) ;
#ifdef F_391
if ( ! F_392 ( V_2 ) )
V_5 += sprintf ( V_5 , L_114 ,
F_401 ( V_2 -> V_357 -> V_304 ) ) ;
#endif
F_126 ( V_5 > V_45 + V_363 - 1 ) ;
return V_45 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_306 ;
const char * V_45 ;
int V_364 = F_296 ( V_2 ) ;
if ( V_364 ) {
F_402 ( & V_365 -> V_345 , V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
} else {
V_45 = F_400 ( V_2 ) ;
}
V_2 -> V_345 . V_359 = V_365 ;
V_306 = F_403 ( & V_2 -> V_345 , & V_362 , NULL , V_45 ) ;
if ( V_306 ) {
F_404 ( & V_2 -> V_345 ) ;
return V_306 ;
}
V_306 = F_405 ( & V_2 -> V_345 , & V_366 ) ;
if ( V_306 ) {
F_406 ( & V_2 -> V_345 ) ;
F_404 ( & V_2 -> V_345 ) ;
return V_306 ;
}
F_407 ( & V_2 -> V_345 , V_367 ) ;
if ( ! V_364 ) {
F_7 ( V_2 , V_2 -> V_45 ) ;
F_253 ( V_45 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_252 < V_352 )
return;
F_407 ( & V_2 -> V_345 , V_368 ) ;
F_406 ( & V_2 -> V_345 ) ;
F_404 ( & V_2 -> V_345 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_45 )
{
struct V_369 * V_370 ;
if ( V_252 == V_352 ) {
F_402 ( & V_365 -> V_345 , V_45 ) ;
return F_408 ( & V_365 -> V_345 , & V_2 -> V_345 , V_45 ) ;
}
V_370 = F_276 ( sizeof( struct V_369 ) , V_254 ) ;
if ( ! V_370 )
return - V_273 ;
V_370 -> V_2 = V_2 ;
V_370 -> V_45 = V_45 ;
V_370 -> V_199 = V_371 ;
V_371 = V_370 ;
return 0 ;
}
static int T_7 F_409 ( void )
{
struct V_1 * V_2 ;
int V_306 ;
F_259 ( & V_267 ) ;
V_365 = F_410 ( L_115 , & V_372 , V_373 ) ;
if ( ! V_365 ) {
F_258 ( & V_267 ) ;
F_40 ( V_49 L_116 ) ;
return - V_248 ;
}
V_252 = V_352 ;
F_195 (s, &slab_caches, list) {
V_306 = F_6 ( V_2 ) ;
if ( V_306 )
F_40 ( V_49 L_117
L_118 , V_2 -> V_45 ) ;
}
while ( V_371 ) {
struct V_369 * V_370 = V_371 ;
V_371 = V_371 -> V_199 ;
V_306 = F_7 ( V_370 -> V_2 , V_370 -> V_45 ) ;
if ( V_306 )
F_40 ( V_49 L_119
L_120 , V_370 -> V_45 ) ;
F_253 ( V_370 ) ;
}
F_258 ( & V_267 ) ;
F_332 () ;
return 0 ;
}
void F_411 ( struct V_1 * V_2 , struct V_374 * V_375 )
{
unsigned long V_110 = 0 ;
unsigned long V_212 = 0 ;
unsigned long V_213 = 0 ;
int V_10 ;
F_200 (node) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
V_110 += F_99 ( V_37 ) ;
V_212 += F_197 ( V_37 ) ;
V_213 += F_192 ( V_37 , F_191 ) ;
}
V_375 -> V_376 = V_212 - V_213 ;
V_375 -> V_377 = V_212 ;
V_375 -> V_378 = V_110 ;
V_375 -> V_379 = V_110 ;
V_375 -> V_380 = F_28 ( V_2 -> V_123 ) ;
V_375 -> V_381 = F_27 ( V_2 -> V_123 ) ;
}
void F_412 ( struct V_382 * V_187 , struct V_1 * V_2 )
{
}
T_9 F_413 ( struct V_383 * V_383 , const char T_10 * V_354 ,
T_1 V_315 , T_11 * V_384 )
{
return - V_350 ;
}
