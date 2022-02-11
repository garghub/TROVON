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
if ( V_11 -> V_41 == V_33 && V_11 -> V_42 == V_34 ) {
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
if ( V_11 -> V_41 == V_33 && V_11 -> V_42 == V_34 ) {
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
F_40 ( V_49 L_6 ,
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
static void F_65 ( struct V_1 * V_2 , struct V_11 * V_11 , const char * V_72 , ... )
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
V_94 , V_92 , V_2 -> V_24 - V_2 -> V_21 ) ;
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
break;
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
F_46 ( L_15 , ( void * ) V_12 , V_2 -> V_21 ) ;
F_63 () ;
}
}
static inline int F_77 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_102 ;
F_78 ( V_3 ) ;
F_79 ( V_3 & V_103 ) ;
return F_80 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_81 ( struct V_1 * V_2 , T_5 V_3 , void * V_12 )
{
V_3 &= V_102 ;
F_82 ( V_2 , V_3 , V_12 , F_24 ( V_2 ) ) ;
F_83 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_84 ( struct V_1 * V_2 , void * V_29 )
{
F_85 ( V_29 , V_2 -> V_3 ) ;
#if F_36 ( V_104 ) || F_36 ( V_105 )
{
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_86 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_87 ( V_29 , V_2 -> V_21 ) ;
F_43 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_106 ) )
F_88 ( V_29 , V_2 -> V_21 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_90 ( & V_11 -> V_107 , & V_37 -> V_108 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_92 ( & V_11 -> V_107 ) ;
}
static inline unsigned long F_93 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
return F_94 ( & V_37 -> V_109 ) ;
}
static inline unsigned long F_95 ( struct V_9 * V_37 )
{
return F_94 ( & V_37 -> V_109 ) ;
}
static inline void F_96 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( F_97 ( V_37 ) ) {
F_98 ( & V_37 -> V_109 ) ;
F_99 ( V_14 , & V_37 -> V_110 ) ;
}
}
static inline void F_100 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
F_101 ( & V_37 -> V_109 ) ;
F_102 ( V_14 , & V_37 -> V_110 ) ;
}
static void F_103 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_79 ) ) )
return;
F_66 ( V_2 , V_12 , V_111 ) ;
F_53 ( V_2 , V_12 ) ;
}
static T_6 int F_104 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_74 ( V_2 , V_11 ) )
goto V_112;
if ( ! F_14 ( V_2 , V_11 , V_12 ) ) {
F_64 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_112;
}
if ( ! F_73 ( V_2 , V_11 , V_12 , V_111 ) )
goto V_112;
if ( V_2 -> V_3 & V_23 )
F_49 ( V_2 , V_12 , V_70 , V_18 ) ;
V_55 ( V_2 , V_11 , V_12 , 1 ) ;
F_66 ( V_2 , V_12 , V_95 ) ;
return 1 ;
V_112:
if ( F_75 ( V_11 ) ) {
F_60 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_41 = NULL ;
}
return 0 ;
}
int T_7 F_105 ( char * V_113 )
{
V_114 = V_115 ;
if ( * V_113 ++ != '=' || ! * V_113 )
goto V_116;
if ( * V_113 == ',' )
goto V_117;
if ( tolower ( * V_113 ) == 'o' ) {
V_118 = 1 ;
goto V_116;
}
V_114 = 0 ;
if ( * V_113 == '-' )
goto V_116;
for (; * V_113 && * V_113 != ',' ; V_113 ++ ) {
switch ( tolower ( * V_113 ) ) {
case 'f' :
V_114 |= V_119 ;
break;
case 'z' :
V_114 |= V_19 ;
break;
case 'p' :
V_114 |= V_20 ;
break;
case 'u' :
V_114 |= V_23 ;
break;
case 't' :
V_114 |= V_101 ;
break;
case 'a' :
V_114 |= V_120 ;
break;
default:
F_40 ( V_49 L_45
L_46 , * V_113 ) ;
}
}
V_117:
if ( * V_113 == ',' )
V_121 = V_113 + 1 ;
V_116:
return 1 ;
}
static unsigned long F_106 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_107)( void * ) )
{
if ( V_114 && ( ! V_121 ||
! strncmp ( V_121 , V_45 , strlen ( V_121 ) ) ) )
V_3 |= V_114 ;
return V_3 ;
}
static inline void F_103 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 ) {}
static inline int F_104 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 , unsigned long V_18 ) { return 0 ; }
static inline struct V_9 * F_108 (
struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
unsigned long V_18 , unsigned long * V_3 ) { return NULL ; }
static inline int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 )
{ return 1 ; }
static inline int F_73 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_78 ) { return 1 ; }
static inline void F_89 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_11 * V_11 ) {}
static inline void F_91 ( struct V_1 * V_2 , struct V_11 * V_11 ) {}
static inline unsigned long F_106 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_107)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_93 ( struct V_1 * V_2 , int V_10 )
{ return 0 ; }
static inline unsigned long F_95 ( struct V_9 * V_37 )
{ return 0 ; }
static inline void F_96 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_100 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline int F_77 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_81 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_12 ) {}
static inline void F_84 ( struct V_1 * V_2 , void * V_29 ) {}
static inline struct V_11 * F_109 ( T_5 V_3 , int V_10 ,
struct V_28 V_122 )
{
int V_25 = F_27 ( V_122 ) ;
V_3 |= V_123 ;
if ( V_10 == V_124 )
return F_110 ( V_3 , V_25 ) ;
else
return F_111 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_112 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_122 = V_2 -> V_122 ;
T_5 V_125 ;
V_3 &= V_102 ;
if ( V_3 & V_103 )
F_113 () ;
V_3 |= V_2 -> V_126 ;
V_125 = ( V_3 | V_127 | V_128 ) & ~ V_129 ;
V_11 = F_109 ( V_125 , V_10 , V_122 ) ;
if ( F_3 ( ! V_11 ) ) {
V_122 = V_2 -> V_130 ;
V_11 = F_109 ( V_3 , V_10 , V_122 ) ;
if ( V_11 )
F_10 ( V_2 , V_131 ) ;
}
if ( V_132 && V_11
&& ! ( V_2 -> V_3 & ( V_133 | V_115 ) ) ) {
int V_134 = 1 << F_27 ( V_122 ) ;
F_114 ( V_11 , F_27 ( V_122 ) , V_3 , V_10 ) ;
if ( V_2 -> F_107 )
F_115 ( V_11 , V_134 ) ;
else
F_116 ( V_11 , V_134 ) ;
}
if ( V_3 & V_103 )
F_117 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_28 ( V_122 ) ;
F_118 ( F_119 ( V_11 ) ,
( V_2 -> V_3 & V_135 ) ?
V_136 : V_137 ,
1 << F_27 ( V_122 ) ) ;
return V_11 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_103 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_107 ) )
V_2 -> F_107 ( V_12 ) ;
}
static struct V_11 * F_121 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_87 ;
void * V_138 ;
void * V_5 ;
int V_25 ;
F_122 ( V_3 & V_139 ) ;
V_11 = F_112 ( V_2 ,
V_3 & ( V_140 | V_141 ) , V_10 ) ;
if ( ! V_11 )
goto V_116;
V_25 = F_72 ( V_11 ) ;
F_96 ( V_2 , F_123 ( V_11 ) , V_11 -> V_14 ) ;
F_124 ( V_2 , V_25 ) ;
V_11 -> V_142 = V_2 ;
F_125 ( V_11 ) ;
if ( V_11 -> V_143 )
F_126 ( V_11 ) ;
V_87 = F_15 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_87 , V_92 , V_27 << V_25 ) ;
V_138 = V_87 ;
F_127 (p, s, start, page->objects) {
F_120 ( V_2 , V_11 , V_138 ) ;
F_22 ( V_2 , V_138 , V_5 ) ;
V_138 = V_5 ;
}
F_120 ( V_2 , V_11 , V_138 ) ;
F_22 ( V_2 , V_138 , NULL ) ;
V_11 -> V_41 = V_87 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_144 = 1 ;
V_116:
return V_11 ;
}
static void F_128 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_72 ( V_11 ) ;
int V_134 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_71 ( V_2 , V_11 ) ;
F_127 (p, s, page_address(page),
page->objects)
F_73 ( V_2 , V_11 , V_5 , V_111 ) ;
}
F_129 ( V_11 , F_72 ( V_11 ) ) ;
F_118 ( F_119 ( V_11 ) ,
( V_2 -> V_3 & V_135 ) ?
V_136 : V_137 ,
- V_134 ) ;
F_130 ( V_11 ) ;
F_131 ( V_11 ) ;
F_132 ( V_2 , V_25 ) ;
F_133 ( V_11 ) ;
if ( V_66 -> V_145 )
V_66 -> V_145 -> V_146 += V_134 ;
F_134 ( V_11 , V_25 ) ;
}
static void F_135 ( struct V_147 * V_148 )
{
struct V_11 * V_11 ;
if ( V_149 )
V_11 = F_136 ( V_148 ) ;
else
V_11 = F_137 ( (struct V_150 * ) V_148 , struct V_11 , V_107 ) ;
F_128 ( V_11 -> V_142 , V_11 ) ;
}
static void F_138 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_147 * V_151 ;
if ( V_149 ) {
int V_25 = F_72 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_34 ( V_2 -> V_26 != sizeof( * V_151 ) ) ;
V_151 = F_15 ( V_11 ) + V_16 ;
} else {
V_151 = ( void * ) & V_11 -> V_107 ;
}
F_139 ( V_151 , F_135 ) ;
} else
F_128 ( V_2 , V_11 ) ;
}
static void F_140 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_100 ( V_2 , F_123 ( V_11 ) , V_11 -> V_14 ) ;
F_138 ( V_2 , V_11 ) ;
}
static inline void F_141 ( struct V_9 * V_37 ,
struct V_11 * V_11 , int V_152 )
{
V_37 -> V_153 ++ ;
if ( V_152 == V_154 )
F_142 ( & V_11 -> V_107 , & V_37 -> V_155 ) ;
else
F_90 ( & V_11 -> V_107 , & V_37 -> V_155 ) ;
}
static inline void F_143 ( struct V_9 * V_37 ,
struct V_11 * V_11 )
{
F_92 ( & V_11 -> V_107 ) ;
V_37 -> V_153 -- ;
}
static inline void * F_144 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 ,
int V_156 , int * V_14 )
{
void * V_41 ;
unsigned long V_42 ;
struct V_11 V_157 ;
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_157 . V_42 = V_42 ;
* V_14 = V_157 . V_14 - V_157 . V_24 ;
if ( V_156 ) {
V_157 . V_24 = V_11 -> V_14 ;
V_157 . V_41 = NULL ;
} else {
V_157 . V_41 = V_41 ;
}
F_34 ( V_157 . V_144 ) ;
V_157 . V_144 = 1 ;
if ( ! F_33 ( V_2 , V_11 ,
V_41 , V_42 ,
V_157 . V_41 , V_157 . V_42 ,
L_47 ) )
return NULL ;
F_143 ( V_37 , V_11 ) ;
F_145 ( ! V_41 ) ;
return V_41 ;
}
static void * F_146 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_158 * V_159 , T_5 V_3 )
{
struct V_11 * V_11 , * V_160 ;
void * V_12 = NULL ;
int V_161 = 0 ;
int V_14 ;
if ( ! V_37 || ! V_37 -> V_153 )
return NULL ;
F_147 ( & V_37 -> V_162 ) ;
F_148 (page, page2, &n->partial, lru) {
void * V_71 ;
if ( ! F_149 ( V_11 , V_3 ) )
continue;
V_71 = F_144 ( V_2 , V_37 , V_11 , V_12 == NULL , & V_14 ) ;
if ( ! V_71 )
break;
V_161 += V_14 ;
if ( ! V_12 ) {
V_159 -> V_11 = V_11 ;
F_10 ( V_2 , V_163 ) ;
V_12 = V_71 ;
} else {
F_150 ( V_2 , V_11 , 0 ) ;
F_10 ( V_2 , V_164 ) ;
}
if ( ! F_4 ( V_2 )
|| V_161 > V_2 -> V_165 / 2 )
break;
}
F_151 ( & V_37 -> V_162 ) ;
return V_12 ;
}
static void * F_152 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_158 * V_159 )
{
#ifdef F_153
struct V_166 * V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_169 ;
enum V_170 V_171 = F_154 ( V_3 ) ;
void * V_12 ;
unsigned int V_172 ;
if ( ! V_2 -> V_173 ||
F_155 () % 1024 > V_2 -> V_173 )
return NULL ;
do {
V_172 = F_156 () ;
V_166 = F_157 ( F_158 () , V_3 ) ;
F_159 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_37 ;
V_37 = F_13 ( V_2 , F_160 ( V_169 ) ) ;
if ( V_37 && F_161 ( V_169 , V_3 ) &&
V_37 -> V_153 > V_2 -> V_174 ) {
V_12 = F_146 ( V_2 , V_37 , V_159 , V_3 ) ;
if ( V_12 ) {
F_162 ( V_172 ) ;
return V_12 ;
}
}
}
} while ( ! F_162 ( V_172 ) );
#endif
return NULL ;
}
static void * F_163 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_158 * V_159 )
{
void * V_12 ;
int V_175 = ( V_10 == V_124 ) ? F_164 () : V_10 ;
V_12 = F_146 ( V_2 , F_13 ( V_2 , V_175 ) , V_159 , V_3 ) ;
if ( V_12 || V_10 != V_124 )
return V_12 ;
return F_152 ( V_2 , V_3 , V_159 ) ;
}
static inline unsigned long F_165 ( unsigned long V_176 )
{
return V_176 + V_177 ;
}
static inline unsigned int F_166 ( unsigned long V_176 )
{
return V_176 % V_177 ;
}
static inline unsigned long F_167 ( unsigned long V_176 )
{
return V_176 / V_177 ;
}
static inline unsigned int F_168 ( int V_64 )
{
return V_64 ;
}
static inline void F_169 ( const char * V_37 ,
const struct V_1 * V_2 , unsigned long V_176 )
{
#ifdef F_39
unsigned long V_178 = F_170 ( V_2 -> V_8 -> V_176 ) ;
F_40 ( V_44 L_48 , V_37 , V_2 -> V_45 ) ;
#ifdef F_171
if ( F_166 ( V_176 ) != F_166 ( V_178 ) )
F_40 ( L_49 ,
F_166 ( V_176 ) , F_166 ( V_178 ) ) ;
else
#endif
if ( F_167 ( V_176 ) != F_167 ( V_178 ) )
F_40 ( L_50 ,
F_167 ( V_176 ) , F_167 ( V_178 ) ) ;
else
F_40 ( L_51 ,
V_178 , V_176 , F_165 ( V_176 ) ) ;
#endif
F_10 ( V_2 , V_179 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
int V_64 ;
F_173 (cpu)
F_174 ( V_2 -> V_8 , V_64 ) -> V_176 = F_168 ( V_64 ) ;
}
static void F_175 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_41 )
{
enum T_8 { V_180 , V_181 , V_182 , V_183 };
struct V_9 * V_37 = F_13 ( V_2 , F_123 ( V_11 ) ) ;
int V_184 = 0 ;
enum T_8 V_185 = V_180 , V_186 = V_180 ;
void * V_187 ;
int V_152 = V_188 ;
struct V_11 V_157 ;
struct V_11 V_189 ;
if ( V_11 -> V_41 ) {
F_10 ( V_2 , V_190 ) ;
V_152 = V_154 ;
}
while ( V_41 && ( V_187 = F_16 ( V_2 , V_41 ) ) ) {
void * V_191 ;
unsigned long V_42 ;
do {
V_191 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_22 ( V_2 , V_41 , V_191 ) ;
V_157 . V_42 = V_42 ;
V_157 . V_24 -- ;
F_34 ( ! V_157 . V_144 ) ;
} while ( ! F_33 ( V_2 , V_11 ,
V_191 , V_42 ,
V_41 , V_157 . V_42 ,
L_52 ) );
V_41 = V_187 ;
}
V_192:
V_189 . V_41 = V_11 -> V_41 ;
V_189 . V_42 = V_11 -> V_42 ;
F_34 ( ! V_189 . V_144 ) ;
V_157 . V_42 = V_189 . V_42 ;
if ( V_41 ) {
V_157 . V_24 -- ;
F_22 ( V_2 , V_41 , V_189 . V_41 ) ;
V_157 . V_41 = V_41 ;
} else
V_157 . V_41 = V_189 . V_41 ;
V_157 . V_144 = 0 ;
if ( ! V_157 . V_24 && V_37 -> V_153 > V_2 -> V_174 )
V_186 = V_183 ;
else if ( V_157 . V_41 ) {
V_186 = V_181 ;
if ( ! V_184 ) {
V_184 = 1 ;
F_147 ( & V_37 -> V_162 ) ;
}
} else {
V_186 = V_182 ;
if ( F_1 ( V_2 ) && ! V_184 ) {
V_184 = 1 ;
F_147 ( & V_37 -> V_162 ) ;
}
}
if ( V_185 != V_186 ) {
if ( V_185 == V_181 )
F_143 ( V_37 , V_11 ) ;
else if ( V_185 == V_182 )
F_91 ( V_2 , V_11 ) ;
if ( V_186 == V_181 ) {
F_141 ( V_37 , V_11 , V_152 ) ;
F_10 ( V_2 , V_152 ) ;
} else if ( V_186 == V_182 ) {
F_10 ( V_2 , V_193 ) ;
F_89 ( V_2 , V_37 , V_11 ) ;
}
}
V_185 = V_186 ;
if ( ! F_33 ( V_2 , V_11 ,
V_189 . V_41 , V_189 . V_42 ,
V_157 . V_41 , V_157 . V_42 ,
L_53 ) )
goto V_192;
if ( V_184 )
F_151 ( & V_37 -> V_162 ) ;
if ( V_186 == V_183 ) {
F_10 ( V_2 , V_194 ) ;
F_140 ( V_2 , V_11 ) ;
F_10 ( V_2 , V_195 ) ;
}
}
static void F_176 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
#ifdef F_5
struct V_9 * V_37 = NULL , * V_196 = NULL ;
struct V_11 * V_11 , * V_197 = NULL ;
while ( ( V_11 = V_159 -> V_155 ) ) {
struct V_11 V_157 ;
struct V_11 V_189 ;
V_159 -> V_155 = V_11 -> V_198 ;
V_196 = F_13 ( V_2 , F_123 ( V_11 ) ) ;
if ( V_37 != V_196 ) {
if ( V_37 )
F_151 ( & V_37 -> V_162 ) ;
V_37 = V_196 ;
F_147 ( & V_37 -> V_162 ) ;
}
do {
V_189 . V_41 = V_11 -> V_41 ;
V_189 . V_42 = V_11 -> V_42 ;
F_34 ( ! V_189 . V_144 ) ;
V_157 . V_42 = V_189 . V_42 ;
V_157 . V_41 = V_189 . V_41 ;
V_157 . V_144 = 0 ;
} while ( ! F_33 ( V_2 , V_11 ,
V_189 . V_41 , V_189 . V_42 ,
V_157 . V_41 , V_157 . V_42 ,
L_53 ) );
if ( F_3 ( ! V_157 . V_24 && V_37 -> V_153 > V_2 -> V_174 ) ) {
V_11 -> V_198 = V_197 ;
V_197 = V_11 ;
} else {
F_141 ( V_37 , V_11 , V_154 ) ;
F_10 ( V_2 , V_199 ) ;
}
}
if ( V_37 )
F_151 ( & V_37 -> V_162 ) ;
while ( V_197 ) {
V_11 = V_197 ;
V_197 = V_197 -> V_198 ;
F_10 ( V_2 , V_194 ) ;
F_140 ( V_2 , V_11 ) ;
F_10 ( V_2 , V_195 ) ;
}
#endif
}
static void F_150 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_200 )
{
#ifdef F_5
struct V_11 * V_201 ;
int V_134 ;
int V_202 ;
do {
V_134 = 0 ;
V_202 = 0 ;
V_201 = F_177 ( V_2 -> V_8 -> V_155 ) ;
if ( V_201 ) {
V_202 = V_201 -> V_202 ;
V_134 = V_201 -> V_134 ;
if ( V_200 && V_202 > V_2 -> V_165 ) {
unsigned long V_3 ;
F_42 ( V_3 ) ;
F_176 ( V_2 , F_178 ( V_2 -> V_8 ) ) ;
F_43 ( V_3 ) ;
V_201 = NULL ;
V_202 = 0 ;
V_134 = 0 ;
F_10 ( V_2 , V_203 ) ;
}
}
V_134 ++ ;
V_202 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_134 = V_134 ;
V_11 -> V_202 = V_202 ;
V_11 -> V_198 = V_201 ;
} while ( F_179 ( V_2 -> V_8 -> V_155 , V_201 , V_11 ) != V_201 );
#endif
}
static inline void F_180 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
F_10 ( V_2 , V_204 ) ;
F_175 ( V_2 , V_159 -> V_11 , V_159 -> V_41 ) ;
V_159 -> V_176 = F_165 ( V_159 -> V_176 ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
}
static inline void F_181 ( struct V_1 * V_2 , int V_64 )
{
struct V_158 * V_159 = F_174 ( V_2 -> V_8 , V_64 ) ;
if ( F_97 ( V_159 ) ) {
if ( V_159 -> V_11 )
F_180 ( V_2 , V_159 ) ;
F_176 ( V_2 , V_159 ) ;
}
}
static void F_182 ( void * V_205 )
{
struct V_1 * V_2 = V_205 ;
F_181 ( V_2 , F_52 () ) ;
}
static bool F_183 ( int V_64 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
struct V_158 * V_159 = F_174 ( V_2 -> V_8 , V_64 ) ;
return V_159 -> V_11 || V_159 -> V_155 ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_185 ( F_183 , F_182 , V_2 , 1 , V_207 ) ;
}
static inline int F_186 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_153
if ( ! V_11 || ( V_10 != V_124 && F_123 ( V_11 ) != V_10 ) )
return 0 ;
#endif
return 1 ;
}
static int F_187 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static unsigned long F_188 ( struct V_9 * V_37 ,
int (* F_189)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_190 ( & V_37 -> V_162 , V_3 ) ;
F_191 (page, &n->partial, lru)
V_29 += F_189 ( V_11 ) ;
F_192 ( & V_37 -> V_162 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_193 ( struct V_9 * V_37 )
{
#ifdef F_2
return F_94 ( & V_37 -> V_110 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_194 ( struct V_1 * V_2 , T_5 V_208 , int V_209 )
{
int V_10 ;
F_40 ( V_210
L_54 ,
V_209 , V_208 ) ;
F_40 ( V_210 L_55
L_56 , V_2 -> V_45 , V_2 -> V_21 ,
V_2 -> V_15 , F_27 ( V_2 -> V_122 ) , F_27 ( V_2 -> V_130 ) ) ;
if ( F_27 ( V_2 -> V_130 ) > F_195 ( V_2 -> V_21 ) )
F_40 ( V_210 L_57
L_58 , V_2 -> V_45 ) ;
F_196 (node) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
unsigned long V_109 ;
unsigned long V_211 ;
unsigned long V_212 ;
if ( ! V_37 )
continue;
V_212 = F_188 ( V_37 , F_187 ) ;
V_109 = F_95 ( V_37 ) ;
V_211 = F_193 ( V_37 ) ;
F_40 ( V_210
L_59 ,
V_10 , V_109 , V_211 , V_212 ) ;
}
}
static inline void * F_197 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_158 * * V_213 )
{
void * V_41 ;
struct V_158 * V_159 = * V_213 ;
struct V_11 * V_11 ;
V_41 = F_163 ( V_2 , V_3 , V_10 , V_159 ) ;
if ( V_41 )
return V_41 ;
V_11 = F_121 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_159 = F_198 ( V_2 -> V_8 ) ;
if ( V_159 -> V_11 )
F_180 ( V_2 , V_159 ) ;
V_41 = V_11 -> V_41 ;
V_11 -> V_41 = NULL ;
F_10 ( V_2 , V_214 ) ;
V_159 -> V_11 = V_11 ;
* V_213 = V_159 ;
} else
V_41 = NULL ;
return V_41 ;
}
static inline bool F_149 ( struct V_11 * V_11 , T_5 V_208 )
{
if ( F_3 ( F_199 ( V_11 ) ) )
return F_200 ( V_208 ) ;
return true ;
}
static inline void * F_201 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_157 ;
unsigned long V_42 ;
void * V_41 ;
do {
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_157 . V_42 = V_42 ;
F_34 ( ! V_157 . V_144 ) ;
V_157 . V_24 = V_11 -> V_14 ;
V_157 . V_144 = V_41 != NULL ;
} while ( ! F_33 ( V_2 , V_11 ,
V_41 , V_42 ,
NULL , V_157 . V_42 ,
L_60 ) );
return V_41 ;
}
static void * F_202 ( struct V_1 * V_2 , T_5 V_208 , int V_10 ,
unsigned long V_18 , struct V_158 * V_159 )
{
void * V_41 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_42 ( V_3 ) ;
#ifdef F_171
V_159 = F_178 ( V_2 -> V_8 ) ;
#endif
V_11 = V_159 -> V_11 ;
if ( ! V_11 )
goto F_121;
V_192:
if ( F_3 ( ! F_186 ( V_11 , V_10 ) ) ) {
F_10 ( V_2 , V_215 ) ;
F_175 ( V_2 , V_11 , V_159 -> V_41 ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
goto F_121;
}
if ( F_3 ( ! F_149 ( V_11 , V_208 ) ) ) {
F_175 ( V_2 , V_11 , V_159 -> V_41 ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
goto F_121;
}
V_41 = V_159 -> V_41 ;
if ( V_41 )
goto V_216;
F_10 ( V_2 , V_217 ) ;
V_41 = F_201 ( V_2 , V_11 ) ;
if ( ! V_41 ) {
V_159 -> V_11 = NULL ;
F_10 ( V_2 , V_218 ) ;
goto F_121;
}
F_10 ( V_2 , V_219 ) ;
V_216:
F_34 ( ! V_159 -> V_11 -> V_144 ) ;
V_159 -> V_41 = F_16 ( V_2 , V_41 ) ;
V_159 -> V_176 = F_165 ( V_159 -> V_176 ) ;
F_43 ( V_3 ) ;
return V_41 ;
F_121:
if ( V_159 -> V_155 ) {
V_11 = V_159 -> V_11 = V_159 -> V_155 ;
V_159 -> V_155 = V_11 -> V_198 ;
F_10 ( V_2 , V_220 ) ;
V_159 -> V_41 = NULL ;
goto V_192;
}
V_41 = F_197 ( V_2 , V_208 , V_10 , & V_159 ) ;
if ( F_3 ( ! V_41 ) ) {
if ( ! ( V_208 & V_127 ) && F_203 () )
F_194 ( V_2 , V_208 , V_10 ) ;
F_43 ( V_3 ) ;
return NULL ;
}
V_11 = V_159 -> V_11 ;
if ( F_97 ( ! F_1 ( V_2 ) && F_149 ( V_11 , V_208 ) ) )
goto V_216;
if ( F_1 ( V_2 ) && ! F_104 ( V_2 , V_11 , V_41 , V_18 ) )
goto F_121;
F_175 ( V_2 , V_11 , F_16 ( V_2 , V_41 ) ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
F_43 ( V_3 ) ;
return V_41 ;
}
static T_2 void * F_204 ( struct V_1 * V_2 ,
T_5 V_208 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_158 * V_159 ;
struct V_11 * V_11 ;
unsigned long V_176 ;
if ( F_77 ( V_2 , V_208 ) )
return NULL ;
V_2 = F_205 ( V_2 , V_208 ) ;
V_192:
F_206 () ;
V_159 = F_198 ( V_2 -> V_8 ) ;
V_176 = V_159 -> V_176 ;
F_207 () ;
V_12 = V_159 -> V_41 ;
V_11 = V_159 -> V_11 ;
if ( F_3 ( ! V_12 || ! V_11 || ! F_186 ( V_11 , V_10 ) ) )
V_12 = F_202 ( V_2 , V_208 , V_10 , V_18 , V_159 ) ;
else {
void * V_221 = F_19 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_208 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_176 ,
V_12 , V_176 ,
V_221 , F_165 ( V_176 ) ) ) ) {
F_169 ( L_61 , V_2 , V_176 ) ;
goto V_192;
}
F_17 ( V_2 , V_221 ) ;
F_10 ( V_2 , V_222 ) ;
}
if ( F_3 ( V_208 & V_223 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_81 ( V_2 , V_208 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_209 ( struct V_1 * V_2 ,
T_5 V_208 , unsigned long V_18 )
{
return F_204 ( V_2 , V_208 , V_124 , V_18 ) ;
}
void * F_210 ( struct V_1 * V_2 , T_5 V_208 )
{
void * V_224 = F_209 ( V_2 , V_208 , V_225 ) ;
F_211 ( V_225 , V_224 , V_2 -> V_21 , V_2 -> V_15 , V_208 ) ;
return V_224 ;
}
void * F_212 ( struct V_1 * V_2 , T_5 V_208 , T_1 V_15 )
{
void * V_224 = F_209 ( V_2 , V_208 , V_225 ) ;
F_213 ( V_225 , V_224 , V_15 , V_2 -> V_15 , V_208 ) ;
return V_224 ;
}
void * F_214 ( T_1 V_15 , T_5 V_3 , unsigned int V_25 )
{
void * V_224 = F_215 ( V_15 , V_3 , V_25 ) ;
F_213 ( V_225 , V_224 , V_15 , V_27 << V_25 , V_3 ) ;
return V_224 ;
}
void * F_216 ( struct V_1 * V_2 , T_5 V_208 , int V_10 )
{
void * V_224 = F_204 ( V_2 , V_208 , V_10 , V_225 ) ;
F_217 ( V_225 , V_224 ,
V_2 -> V_21 , V_2 -> V_15 , V_208 , V_10 ) ;
return V_224 ;
}
void * F_218 ( struct V_1 * V_2 ,
T_5 V_208 ,
int V_10 , T_1 V_15 )
{
void * V_224 = F_204 ( V_2 , V_208 , V_10 , V_225 ) ;
F_219 ( V_225 , V_224 ,
V_15 , V_2 -> V_15 , V_208 , V_10 ) ;
return V_224 ;
}
static void F_220 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_191 ;
void * * V_12 = ( void * ) V_29 ;
int V_226 ;
struct V_11 V_157 ;
unsigned long V_42 ;
struct V_9 * V_37 = NULL ;
unsigned long V_227 ( V_3 ) ;
F_10 ( V_2 , V_228 ) ;
if ( F_1 ( V_2 ) &&
! ( V_37 = F_108 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_37 ) ) {
F_192 ( & V_37 -> V_162 , V_3 ) ;
V_37 = NULL ;
}
V_191 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_22 ( V_2 , V_12 , V_191 ) ;
V_157 . V_42 = V_42 ;
V_226 = V_157 . V_144 ;
V_157 . V_24 -- ;
if ( ( ! V_157 . V_24 || ! V_191 ) && ! V_226 ) {
if ( F_4 ( V_2 ) && ! V_191 )
V_157 . V_144 = 1 ;
else {
V_37 = F_13 ( V_2 , F_123 ( V_11 ) ) ;
F_190 ( & V_37 -> V_162 , V_3 ) ;
}
}
} while ( ! F_41 ( V_2 , V_11 ,
V_191 , V_42 ,
V_12 , V_157 . V_42 ,
L_62 ) );
if ( F_97 ( ! V_37 ) ) {
if ( V_157 . V_144 && ! V_226 ) {
F_150 ( V_2 , V_11 , 1 ) ;
F_10 ( V_2 , V_229 ) ;
}
if ( V_226 )
F_10 ( V_2 , V_230 ) ;
return;
}
if ( F_3 ( ! V_157 . V_24 && V_37 -> V_153 > V_2 -> V_174 ) )
goto V_231;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_191 ) ) {
if ( F_1 ( V_2 ) )
F_91 ( V_2 , V_11 ) ;
F_141 ( V_37 , V_11 , V_154 ) ;
F_10 ( V_2 , V_199 ) ;
}
F_192 ( & V_37 -> V_162 , V_3 ) ;
return;
V_231:
if ( V_191 ) {
F_143 ( V_37 , V_11 ) ;
F_10 ( V_2 , V_232 ) ;
} else
F_91 ( V_2 , V_11 ) ;
F_192 ( & V_37 -> V_162 , V_3 ) ;
F_10 ( V_2 , V_195 ) ;
F_140 ( V_2 , V_11 ) ;
}
static T_2 void F_221 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_158 * V_159 ;
unsigned long V_176 ;
F_84 ( V_2 , V_29 ) ;
V_192:
F_206 () ;
V_159 = F_198 ( V_2 -> V_8 ) ;
V_176 = V_159 -> V_176 ;
F_207 () ;
if ( F_97 ( V_11 == V_159 -> V_11 ) ) {
F_22 ( V_2 , V_12 , V_159 -> V_41 ) ;
if ( F_3 ( ! F_208 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_176 ,
V_159 -> V_41 , V_176 ,
V_12 , F_165 ( V_176 ) ) ) ) {
F_169 ( L_63 , V_2 , V_176 ) ;
goto V_192;
}
F_10 ( V_2 , V_233 ) ;
} else
F_220 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_222 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_223 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_221 ( V_2 , F_136 ( V_29 ) , V_29 , V_225 ) ;
F_224 ( V_225 , V_29 ) ;
}
static inline int F_225 ( int V_15 , int V_234 ,
int V_235 , int V_236 , int V_26 )
{
int V_25 ;
int V_237 ;
int V_238 = V_239 ;
if ( F_25 ( V_238 , V_15 , V_26 ) > V_100 )
return F_195 ( V_15 * V_100 ) - 1 ;
for ( V_25 = F_226 ( V_238 ,
F_227 ( V_234 * V_15 - 1 ) - V_240 ) ;
V_25 <= V_235 ; V_25 ++ ) {
unsigned long V_241 = V_27 << V_25 ;
if ( V_241 < V_234 * V_15 + V_26 )
continue;
V_237 = ( V_241 - V_26 ) % V_15 ;
if ( V_237 <= V_241 / V_236 )
break;
}
return V_25 ;
}
static inline int F_228 ( int V_15 , int V_26 )
{
int V_25 ;
int V_234 ;
int V_242 ;
int V_99 ;
V_234 = V_243 ;
if ( ! V_234 )
V_234 = 4 * ( F_227 ( V_244 ) + 1 ) ;
V_99 = F_25 ( V_245 , V_15 , V_26 ) ;
V_234 = V_130 ( V_234 , V_99 ) ;
while ( V_234 > 1 ) {
V_242 = 16 ;
while ( V_242 >= 4 ) {
V_25 = F_225 ( V_15 , V_234 ,
V_245 , V_242 , V_26 ) ;
if ( V_25 <= V_245 )
return V_25 ;
V_242 /= 2 ;
}
V_234 -- ;
}
V_25 = F_225 ( V_15 , 1 , V_245 , 1 , V_26 ) ;
if ( V_25 <= V_245 )
return V_25 ;
V_25 = F_225 ( V_15 , 1 , V_246 , 1 , V_26 ) ;
if ( V_25 < V_246 )
return V_25 ;
return - V_247 ;
}
static void
F_229 ( struct V_9 * V_37 )
{
V_37 -> V_153 = 0 ;
F_230 ( & V_37 -> V_162 ) ;
F_231 ( & V_37 -> V_155 ) ;
#ifdef F_2
F_232 ( & V_37 -> V_109 , 0 ) ;
F_232 ( & V_37 -> V_110 , 0 ) ;
F_231 ( & V_37 -> V_108 ) ;
#endif
}
static inline int F_233 ( struct V_1 * V_2 )
{
F_234 ( V_248 <
V_249 * sizeof( struct V_158 ) ) ;
V_2 -> V_8 = F_235 ( sizeof( struct V_158 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_172 ( V_2 ) ;
return 1 ;
}
static void F_236 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_37 ;
F_122 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_121 ( V_9 , V_250 , V_10 ) ;
F_122 ( ! V_11 ) ;
if ( F_123 ( V_11 ) != V_10 ) {
F_40 ( V_49 L_64
L_65 , V_10 ) ;
F_40 ( V_49 L_66
L_67 ) ;
}
V_37 = V_11 -> V_41 ;
F_122 ( ! V_37 ) ;
V_11 -> V_41 = F_16 ( V_9 , V_37 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_144 = 0 ;
V_9 -> V_10 [ V_10 ] = V_37 ;
#ifdef F_2
F_66 ( V_9 , V_37 , V_95 ) ;
F_53 ( V_9 , V_37 ) ;
#endif
F_229 ( V_37 ) ;
F_96 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_141 ( V_37 , V_11 , V_188 ) ;
}
static void F_237 ( struct V_1 * V_2 )
{
int V_10 ;
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = V_2 -> V_10 [ V_10 ] ;
if ( V_37 )
F_222 ( V_9 , V_37 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_239 ( struct V_1 * V_2 )
{
int V_10 ;
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 ;
if ( V_251 == V_252 ) {
F_236 ( V_10 ) ;
continue;
}
V_37 = F_216 ( V_9 ,
V_253 , V_10 ) ;
if ( ! V_37 ) {
F_237 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_37 ;
F_229 ( V_37 ) ;
}
return 1 ;
}
static void F_240 ( struct V_1 * V_2 , unsigned long V_130 )
{
if ( V_130 < V_254 )
V_130 = V_254 ;
else if ( V_130 > V_255 )
V_130 = V_255 ;
V_2 -> V_174 = V_130 ;
}
static int F_241 ( struct V_1 * V_2 , int V_256 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_242 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_107 )
V_2 -> V_3 |= V_79 ;
else
V_2 -> V_3 &= ~ V_79 ;
if ( ( V_3 & V_19 ) && V_15 == V_2 -> V_21 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_24 = V_15 ;
if ( ( ( V_3 & ( V_22 | V_20 ) ) ||
V_2 -> F_107 ) ) {
V_2 -> V_16 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_23 )
V_15 += 2 * sizeof( struct V_51 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_15 = F_242 ( V_15 , V_2 -> V_257 ) ;
V_2 -> V_15 = V_15 ;
if ( V_256 >= 0 )
V_25 = V_256 ;
else
V_25 = F_228 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_126 = 0 ;
if ( V_25 )
V_2 -> V_126 |= V_258 ;
if ( V_2 -> V_3 & V_259 )
V_2 -> V_126 |= V_260 ;
if ( V_2 -> V_3 & V_135 )
V_2 -> V_126 |= V_261 ;
V_2 -> V_122 = F_26 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_130 = F_26 ( F_195 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_28 ( V_2 -> V_122 ) > F_28 ( V_2 -> F_226 ) )
V_2 -> F_226 = V_2 -> V_122 ;
return ! ! F_28 ( V_2 -> V_122 ) ;
}
static int F_243 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_106 ( V_2 -> V_15 , V_3 , V_2 -> V_45 , V_2 -> F_107 ) ;
V_2 -> V_26 = 0 ;
if ( V_149 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_147 ) ;
if ( ! F_241 ( V_2 , - 1 ) )
goto error;
if ( V_118 ) {
if ( F_195 ( V_2 -> V_15 ) > F_195 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_262 ;
V_2 -> V_16 = 0 ;
if ( ! F_241 ( V_2 , - 1 ) )
goto error;
}
}
#if F_36 ( V_38 ) && \
F_36 ( V_39 )
if ( F_244 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_40 ;
#endif
F_240 ( V_2 , F_245 ( V_2 -> V_15 ) / 2 ) ;
if ( ! F_4 ( V_2 ) )
V_2 -> V_165 = 0 ;
else if ( V_2 -> V_15 >= V_27 )
V_2 -> V_165 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_165 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_165 = 13 ;
else
V_2 -> V_165 = 30 ;
#ifdef F_153
V_2 -> V_173 = 1000 ;
#endif
if ( ! F_239 ( V_2 ) )
goto error;
if ( F_233 ( V_2 ) )
return 0 ;
F_237 ( V_2 ) ;
error:
if ( V_3 & V_263 )
F_246 ( L_68
L_69 ,
V_2 -> V_45 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 , F_27 ( V_2 -> V_122 ) ,
V_2 -> V_16 , V_3 ) ;
return - V_264 ;
}
static void F_247 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_47 )
{
#ifdef F_2
void * V_18 = F_15 ( V_11 ) ;
void * V_5 ;
unsigned long * V_46 = F_248 ( F_249 ( V_11 -> V_14 ) *
sizeof( long ) , V_207 ) ;
if ( ! V_46 )
return;
F_65 ( V_2 , V_11 , V_47 , V_2 -> V_45 ) ;
F_29 ( V_11 ) ;
F_44 ( V_2 , V_11 , V_46 ) ;
F_127 (p, s, addr, page->objects) {
if ( ! F_250 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) ) {
F_40 ( V_49 L_70 ,
V_5 , V_5 - V_18 ) ;
F_55 ( V_2 , V_5 ) ;
}
}
F_31 ( V_11 ) ;
F_251 ( V_46 ) ;
#endif
}
static void F_252 ( struct V_1 * V_2 , struct V_9 * V_37 )
{
struct V_11 * V_11 , * V_148 ;
F_148 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_143 ( V_37 , V_11 ) ;
F_140 ( V_2 , V_11 ) ;
} else {
F_247 ( V_2 , V_11 ,
L_71 ) ;
}
}
}
static inline int F_253 ( struct V_1 * V_2 )
{
int V_10 ;
F_184 ( V_2 ) ;
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
F_252 ( V_2 , V_37 ) ;
if ( V_37 -> V_153 || F_93 ( V_2 , V_10 ) )
return 1 ;
}
F_254 ( V_2 -> V_8 ) ;
F_237 ( V_2 ) ;
return 0 ;
}
int F_255 ( struct V_1 * V_2 )
{
int V_265 = F_253 ( V_2 ) ;
if ( ! V_265 ) {
F_256 ( & V_266 ) ;
F_8 ( V_2 ) ;
F_257 ( & V_266 ) ;
}
return V_265 ;
}
static int T_7 F_258 ( char * V_113 )
{
F_259 ( & V_113 , & V_239 ) ;
return 1 ;
}
static int T_7 F_260 ( char * V_113 )
{
F_259 ( & V_113 , & V_245 ) ;
V_245 = V_130 ( V_245 , V_246 - 1 ) ;
return 1 ;
}
static int T_7 F_261 ( char * V_113 )
{
F_259 ( & V_113 , & V_243 ) ;
return 1 ;
}
static int T_7 F_262 ( char * V_113 )
{
V_267 = 1 ;
return 1 ;
}
void * F_263 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_268 ) )
return F_264 ( V_15 , V_3 ) ;
V_2 = F_265 ( V_15 , V_3 ) ;
if ( F_3 ( F_266 ( V_2 ) ) )
return V_2 ;
V_224 = F_209 ( V_2 , V_3 , V_225 ) ;
F_213 ( V_225 , V_224 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_224 ;
}
static void * F_267 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_269 = NULL ;
V_3 |= V_258 | V_123 | V_270 ;
V_11 = F_268 ( V_10 , V_3 , F_195 ( V_15 ) ) ;
if ( V_11 )
V_269 = F_15 ( V_11 ) ;
F_269 ( V_269 , V_15 , 1 , V_3 ) ;
return V_269 ;
}
void * F_270 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_268 ) ) {
V_224 = F_267 ( V_15 , V_3 , V_10 ) ;
F_219 ( V_225 , V_224 ,
V_15 , V_27 << F_195 ( V_15 ) ,
V_3 , V_10 ) ;
return V_224 ;
}
V_2 = F_265 ( V_15 , V_3 ) ;
if ( F_3 ( F_266 ( V_2 ) ) )
return V_2 ;
V_224 = F_204 ( V_2 , V_3 , V_10 , V_225 ) ;
F_219 ( V_225 , V_224 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_224 ;
}
T_1 F_271 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_271 ) )
return 0 ;
V_11 = F_136 ( V_12 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
F_145 ( ! F_272 ( V_11 ) ) ;
return V_27 << F_72 ( V_11 ) ;
}
return F_24 ( V_11 -> V_142 ) ;
}
bool F_273 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
unsigned long V_3 ;
bool V_272 ;
if ( F_3 ( F_266 ( V_29 ) ) )
return false ;
F_42 ( V_3 ) ;
V_11 = F_136 ( V_29 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
V_272 = true ;
goto V_273;
}
F_29 ( V_11 ) ;
if ( F_76 ( V_11 -> V_142 , V_11 , V_12 ) ) {
F_64 ( V_11 -> V_142 , V_11 , V_12 , L_72 ) ;
V_272 = false ;
} else {
V_272 = true ;
}
F_31 ( V_11 ) ;
V_273:
F_43 ( V_3 ) ;
return V_272 ;
}
void F_251 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_274 ( V_225 , V_29 ) ;
if ( F_3 ( F_266 ( V_29 ) ) )
return;
V_11 = F_136 ( V_29 ) ;
if ( F_3 ( ! F_75 ( V_11 ) ) ) {
F_122 ( ! F_272 ( V_11 ) ) ;
F_275 ( V_29 ) ;
F_134 ( V_11 , F_72 ( V_11 ) ) ;
return;
}
F_221 ( V_11 -> V_142 , V_11 , V_12 , V_225 ) ;
}
int F_276 ( struct V_1 * V_2 )
{
int V_10 ;
int V_56 ;
struct V_9 * V_37 ;
struct V_11 * V_11 ;
struct V_11 * V_71 ;
int V_14 = F_28 ( V_2 -> F_226 ) ;
struct V_150 * V_274 =
F_277 ( sizeof( struct V_150 ) * V_14 , V_253 ) ;
unsigned long V_3 ;
if ( ! V_274 )
return - V_275 ;
F_184 ( V_2 ) ;
F_238 (node, N_NORMAL_MEMORY) {
V_37 = F_13 ( V_2 , V_10 ) ;
if ( ! V_37 -> V_153 )
continue;
for ( V_56 = 0 ; V_56 < V_14 ; V_56 ++ )
F_231 ( V_274 + V_56 ) ;
F_190 ( & V_37 -> V_162 , V_3 ) ;
F_148 (page, t, &n->partial, lru) {
F_278 ( & V_11 -> V_107 , V_274 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_37 -> V_153 -- ;
}
for ( V_56 = V_14 - 1 ; V_56 > 0 ; V_56 -- )
F_279 ( V_274 + V_56 , V_37 -> V_155 . V_276 ) ;
F_192 ( & V_37 -> V_162 , V_3 ) ;
F_148 (page, t, slabs_by_inuse, lru)
F_140 ( V_2 , V_11 ) ;
}
F_251 ( V_274 ) ;
return 0 ;
}
static int F_280 ( void * V_277 )
{
struct V_1 * V_2 ;
F_257 ( & V_266 ) ;
F_191 (s, &slab_caches, list)
F_276 ( V_2 ) ;
F_256 ( & V_266 ) ;
return 0 ;
}
static void F_281 ( void * V_277 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_278 * V_279 = V_277 ;
int V_280 ;
V_280 = V_279 -> V_281 ;
if ( V_280 < 0 )
return;
F_257 ( & V_266 ) ;
F_191 (s, &slab_caches, list) {
V_37 = F_13 ( V_2 , V_280 ) ;
if ( V_37 ) {
F_122 ( F_93 ( V_2 , V_280 ) ) ;
V_2 -> V_10 [ V_280 ] = NULL ;
F_222 ( V_9 , V_37 ) ;
}
}
F_256 ( & V_266 ) ;
}
static int F_282 ( void * V_277 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_278 * V_279 = V_277 ;
int V_209 = V_279 -> V_281 ;
int V_224 = 0 ;
if ( V_209 < 0 )
return 0 ;
F_257 ( & V_266 ) ;
F_191 (s, &slab_caches, list) {
V_37 = F_210 ( V_9 , V_253 ) ;
if ( ! V_37 ) {
V_224 = - V_275 ;
goto V_116;
}
F_229 ( V_37 ) ;
V_2 -> V_10 [ V_209 ] = V_37 ;
}
V_116:
F_256 ( & V_266 ) ;
return V_224 ;
}
static int F_283 ( struct V_282 * V_283 ,
unsigned long V_284 , void * V_277 )
{
int V_224 = 0 ;
switch ( V_284 ) {
case V_285 :
V_224 = F_282 ( V_277 ) ;
break;
case V_286 :
V_224 = F_280 ( V_277 ) ;
break;
case V_287 :
case V_288 :
F_281 ( V_277 ) ;
break;
case V_289 :
case V_290 :
break;
}
if ( V_224 )
V_224 = F_284 ( V_224 ) ;
else
V_224 = V_291 ;
return V_224 ;
}
static struct V_1 * T_7 F_285 ( struct V_1 * V_292 )
{
int V_10 ;
struct V_1 * V_2 = F_286 ( V_1 , V_250 ) ;
memcpy ( V_2 , V_292 , V_1 -> V_21 ) ;
F_181 ( V_2 , F_52 () ) ;
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_37 ) {
F_191 (p, &n->partial, lru)
V_5 -> V_142 = V_2 ;
#ifdef F_2
F_191 (p, &n->full, lru)
V_5 -> V_142 = V_2 ;
#endif
}
}
F_90 ( & V_2 -> V_293 , & V_294 ) ;
return V_2 ;
}
void T_7 F_287 ( void )
{
static V_295 struct V_1 V_296 ,
V_297 ;
if ( F_288 () )
V_245 = 0 ;
V_9 = & V_297 ;
V_1 = & V_296 ;
F_289 ( V_9 , L_73 ,
sizeof( struct V_9 ) , V_298 ) ;
F_290 ( & V_299 ) ;
V_251 = V_300 ;
F_289 ( V_1 , L_74 ,
F_291 ( struct V_1 , V_10 ) +
V_301 * sizeof( struct V_9 * ) ,
V_298 ) ;
V_1 = F_285 ( & V_296 ) ;
V_9 = F_285 ( & V_297 ) ;
F_292 ( 0 ) ;
#ifdef F_293
F_294 ( & V_302 ) ;
#endif
F_40 ( V_44
L_75
L_76 ,
F_295 () ,
V_239 , V_245 , V_243 ,
V_244 , V_301 ) ;
}
void T_7 F_296 ( void )
{
}
static int F_297 ( struct V_1 * V_2 )
{
if ( V_267 || ( V_2 -> V_3 & V_303 ) )
return 1 ;
if ( V_2 -> F_107 )
return 1 ;
if ( V_2 -> V_304 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_298 ( struct V_305 * V_306 , T_1 V_15 ,
T_1 V_257 , unsigned long V_3 , const char * V_45 ,
void (* F_107)( void * ) )
{
struct V_1 * V_2 ;
if ( V_267 || ( V_3 & V_303 ) )
return NULL ;
if ( F_107 )
return NULL ;
V_15 = F_242 ( V_15 , sizeof( void * ) ) ;
V_257 = F_299 ( V_3 , V_257 , V_15 ) ;
V_15 = F_242 ( V_15 , V_257 ) ;
V_3 = F_106 ( V_15 , V_3 , V_45 , NULL ) ;
F_191 (s, &slab_caches, list) {
if ( F_297 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_307 ) != ( V_2 -> V_3 & V_307 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_257 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
if ( ! F_300 ( V_2 , V_306 ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_301 ( struct V_305 * V_306 , const char * V_45 , T_1 V_15 ,
T_1 V_257 , unsigned long V_3 , void (* F_107)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_298 ( V_306 , V_15 , V_257 , V_3 , V_45 , F_107 ) ;
if ( V_2 ) {
V_2 -> V_304 ++ ;
V_2 -> V_21 = F_226 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_302 ( int , V_2 -> V_24 , F_242 ( V_15 , sizeof( void * ) ) ) ;
if ( F_7 ( V_2 , V_45 ) ) {
V_2 -> V_304 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_303 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_308 ;
V_308 = F_243 ( V_2 , V_3 ) ;
if ( V_308 )
return V_308 ;
if ( V_251 <= V_309 )
return 0 ;
F_9 ( V_2 ) ;
F_256 ( & V_266 ) ;
V_308 = F_6 ( V_2 ) ;
F_257 ( & V_266 ) ;
if ( V_308 )
F_253 ( V_2 ) ;
return V_308 ;
}
static int F_304 ( struct V_282 * V_310 ,
unsigned long V_284 , void * V_311 )
{
long V_64 = ( long ) V_311 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_284 ) {
case V_312 :
case V_313 :
case V_314 :
case V_315 :
F_257 ( & V_266 ) ;
F_191 (s, &slab_caches, list) {
F_42 ( V_3 ) ;
F_181 ( V_2 , V_64 ) ;
F_43 ( V_3 ) ;
}
F_256 ( & V_266 ) ;
break;
default:
break;
}
return V_291 ;
}
void * F_305 ( T_1 V_15 , T_5 V_208 , unsigned long V_316 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_268 ) )
return F_264 ( V_15 , V_208 ) ;
V_2 = F_265 ( V_15 , V_208 ) ;
if ( F_3 ( F_266 ( V_2 ) ) )
return V_2 ;
V_224 = F_209 ( V_2 , V_208 , V_316 ) ;
F_213 ( V_316 , V_224 , V_15 , V_2 -> V_15 , V_208 ) ;
return V_224 ;
}
void * F_306 ( T_1 V_15 , T_5 V_208 ,
int V_10 , unsigned long V_316 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_268 ) ) {
V_224 = F_267 ( V_15 , V_208 , V_10 ) ;
F_219 ( V_316 , V_224 ,
V_15 , V_27 << F_195 ( V_15 ) ,
V_208 , V_10 ) ;
return V_224 ;
}
V_2 = F_265 ( V_15 , V_208 ) ;
if ( F_3 ( F_266 ( V_2 ) ) )
return V_2 ;
V_224 = F_204 ( V_2 , V_208 , V_10 , V_316 ) ;
F_219 ( V_316 , V_224 , V_15 , V_2 -> V_15 , V_208 , V_10 ) ;
return V_224 ;
}
static int F_307 ( struct V_11 * V_11 )
{
return V_11 -> V_24 ;
}
static int F_308 ( struct V_11 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_309 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_18 = F_15 ( V_11 ) ;
if ( ! F_74 ( V_2 , V_11 ) ||
! F_76 ( V_2 , V_11 , NULL ) )
return 0 ;
F_310 ( V_46 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_46 ) ;
F_127 (p, s, addr, page->objects) {
if ( F_250 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_73 ( V_2 , V_11 , V_5 , V_111 ) )
return 0 ;
}
F_127 (p, s, addr, page->objects)
if ( ! F_250 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_73 ( V_2 , V_11 , V_5 , V_95 ) )
return 0 ;
return 1 ;
}
static void F_311 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
F_29 ( V_11 ) ;
F_309 ( V_2 , V_11 , V_46 ) ;
F_31 ( V_11 ) ;
}
static int F_312 ( struct V_1 * V_2 ,
struct V_9 * V_37 , unsigned long * V_46 )
{
unsigned long V_317 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_190 ( & V_37 -> V_162 , V_3 ) ;
F_191 (page, &n->partial, lru) {
F_311 ( V_2 , V_11 , V_46 ) ;
V_317 ++ ;
}
if ( V_317 != V_37 -> V_153 )
F_40 ( V_49 L_77
L_78 , V_2 -> V_45 , V_317 , V_37 -> V_153 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_116;
F_191 (page, &n->full, lru) {
F_311 ( V_2 , V_11 , V_46 ) ;
V_317 ++ ;
}
if ( V_317 != F_94 ( & V_37 -> V_109 ) )
F_40 ( V_49 L_79
L_78 , V_2 -> V_45 , V_317 ,
F_94 ( & V_37 -> V_109 ) ) ;
V_116:
F_192 ( & V_37 -> V_162 , V_3 ) ;
return V_317 ;
}
static long F_313 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_317 = 0 ;
unsigned long * V_46 = F_277 ( F_249 ( F_28 ( V_2 -> F_226 ) ) *
sizeof( unsigned long ) , V_253 ) ;
if ( ! V_46 )
return - V_275 ;
F_184 ( V_2 ) ;
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
V_317 += F_312 ( V_2 , V_37 , V_46 ) ;
}
F_251 ( V_46 ) ;
return V_317 ;
}
static void F_314 ( struct V_318 * V_71 )
{
if ( V_71 -> F_226 )
F_315 ( ( unsigned long ) V_71 -> V_319 ,
F_195 ( sizeof( struct V_320 ) * V_71 -> F_226 ) ) ;
}
static int F_316 ( struct V_318 * V_71 , unsigned long F_226 , T_5 V_3 )
{
struct V_320 * V_185 ;
int V_25 ;
V_25 = F_195 ( sizeof( struct V_320 ) * F_226 ) ;
V_185 = ( void * ) F_317 ( V_3 , V_25 ) ;
if ( ! V_185 )
return 0 ;
if ( V_71 -> V_317 ) {
memcpy ( V_185 , V_71 -> V_319 , sizeof( struct V_320 ) * V_71 -> V_317 ) ;
F_314 ( V_71 ) ;
}
V_71 -> F_226 = F_226 ;
V_71 -> V_319 = V_185 ;
return 1 ;
}
static int F_318 ( struct V_318 * V_71 , struct V_1 * V_2 ,
const struct V_51 * V_51 )
{
long V_87 , V_91 , V_321 ;
struct V_320 * V_185 ;
unsigned long V_322 ;
unsigned long V_323 = V_68 - V_51 -> V_67 ;
V_87 = - 1 ;
V_91 = V_71 -> V_317 ;
for ( ; ; ) {
V_321 = V_87 + ( V_91 - V_87 + 1 ) / 2 ;
if ( V_321 == V_91 )
break;
V_322 = V_71 -> V_319 [ V_321 ] . V_18 ;
if ( V_51 -> V_18 == V_322 ) {
V_185 = & V_71 -> V_319 [ V_321 ] ;
V_185 -> V_317 ++ ;
if ( V_51 -> V_67 ) {
V_185 -> V_324 += V_323 ;
if ( V_323 < V_185 -> V_325 )
V_185 -> V_325 = V_323 ;
if ( V_323 > V_185 -> V_326 )
V_185 -> V_326 = V_323 ;
if ( V_51 -> V_65 < V_185 -> V_327 )
V_185 -> V_327 = V_51 -> V_65 ;
if ( V_51 -> V_65 > V_185 -> V_328 )
V_185 -> V_328 = V_51 -> V_65 ;
F_319 ( V_51 -> V_64 ,
F_320 ( V_185 -> V_329 ) ) ;
}
F_321 ( F_123 ( F_322 ( V_51 ) ) , V_185 -> V_330 ) ;
return 1 ;
}
if ( V_51 -> V_18 < V_322 )
V_91 = V_321 ;
else
V_87 = V_321 ;
}
if ( V_71 -> V_317 >= V_71 -> F_226 && ! F_316 ( V_71 , 2 * V_71 -> F_226 , V_207 ) )
return 0 ;
V_185 = V_71 -> V_319 + V_321 ;
if ( V_321 < V_71 -> V_317 )
memmove ( V_185 + 1 , V_185 ,
( V_71 -> V_317 - V_321 ) * sizeof( struct V_320 ) ) ;
V_71 -> V_317 ++ ;
V_185 -> V_317 = 1 ;
V_185 -> V_18 = V_51 -> V_18 ;
V_185 -> V_324 = V_323 ;
V_185 -> V_325 = V_323 ;
V_185 -> V_326 = V_323 ;
V_185 -> V_327 = V_51 -> V_65 ;
V_185 -> V_328 = V_51 -> V_65 ;
F_323 ( F_320 ( V_185 -> V_329 ) ) ;
F_319 ( V_51 -> V_64 , F_320 ( V_185 -> V_329 ) ) ;
F_324 ( V_185 -> V_330 ) ;
F_321 ( F_123 ( F_322 ( V_51 ) ) , V_185 -> V_330 ) ;
return 1 ;
}
static void F_325 ( struct V_318 * V_71 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_52 V_53 ,
unsigned long * V_46 )
{
void * V_18 = F_15 ( V_11 ) ;
void * V_5 ;
F_310 ( V_46 , V_11 -> V_14 ) ;
F_44 ( V_2 , V_11 , V_46 ) ;
F_127 (p, s, addr, page->objects)
if ( ! F_250 ( F_23 ( V_5 , V_2 , V_18 ) , V_46 ) )
F_318 ( V_71 , V_2 , F_48 ( V_2 , V_5 , V_53 ) ) ;
}
static int F_326 ( struct V_1 * V_2 , char * V_73 ,
enum V_52 V_53 )
{
int V_331 = 0 ;
unsigned long V_56 ;
struct V_318 V_71 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_46 = F_277 ( F_249 ( F_28 ( V_2 -> F_226 ) ) *
sizeof( unsigned long ) , V_253 ) ;
if ( ! V_46 || ! F_316 ( & V_71 , V_27 / sizeof( struct V_320 ) ,
V_332 ) ) {
F_251 ( V_46 ) ;
return sprintf ( V_73 , L_80 ) ;
}
F_184 ( V_2 ) ;
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_94 ( & V_37 -> V_109 ) )
continue;
F_190 ( & V_37 -> V_162 , V_3 ) ;
F_191 (page, &n->partial, lru)
F_325 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_191 (page, &n->full, lru)
F_325 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_192 ( & V_37 -> V_162 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_317 ; V_56 ++ ) {
struct V_320 * V_185 = & V_71 . V_319 [ V_56 ] ;
if ( V_331 > V_27 - V_333 - 100 )
break;
V_331 += sprintf ( V_73 + V_331 , L_81 , V_185 -> V_317 ) ;
if ( V_185 -> V_18 )
V_331 += sprintf ( V_73 + V_331 , L_82 , ( void * ) V_185 -> V_18 ) ;
else
V_331 += sprintf ( V_73 + V_331 , L_83 ) ;
if ( V_185 -> V_324 != V_185 -> V_325 ) {
V_331 += sprintf ( V_73 + V_331 , L_84 ,
V_185 -> V_325 ,
( long ) F_327 ( V_185 -> V_324 , V_185 -> V_317 ) ,
V_185 -> V_326 ) ;
} else
V_331 += sprintf ( V_73 + V_331 , L_85 ,
V_185 -> V_325 ) ;
if ( V_185 -> V_327 != V_185 -> V_328 )
V_331 += sprintf ( V_73 + V_331 , L_86 ,
V_185 -> V_327 , V_185 -> V_328 ) ;
else
V_331 += sprintf ( V_73 + V_331 , L_87 ,
V_185 -> V_327 ) ;
if ( F_328 () > 1 &&
! F_329 ( F_320 ( V_185 -> V_329 ) ) &&
V_331 < V_27 - 60 ) {
V_331 += sprintf ( V_73 + V_331 , L_88 ) ;
V_331 += F_330 ( V_73 + V_331 , V_27 - V_331 - 50 ,
F_320 ( V_185 -> V_329 ) ) ;
}
if ( V_334 > 1 && ! F_331 ( V_185 -> V_330 ) &&
V_331 < V_27 - 60 ) {
V_331 += sprintf ( V_73 + V_331 , L_89 ) ;
V_331 += F_332 ( V_73 + V_331 , V_27 - V_331 - 50 ,
V_185 -> V_330 ) ;
}
V_331 += sprintf ( V_73 + V_331 , L_90 ) ;
}
F_314 ( & V_71 ) ;
F_251 ( V_46 ) ;
if ( ! V_71 . V_317 )
V_331 += sprintf ( V_73 , L_91 ) ;
return V_331 ;
}
static void F_333 ( void )
{
T_3 * V_5 ;
F_234 ( V_335 > 16 || V_249 < 10 ) ;
F_40 ( V_49 L_92 ) ;
F_40 ( V_49 L_93 ) ;
F_40 ( V_49 L_94 ) ;
V_5 = F_248 ( 16 , V_253 ) ;
V_5 [ 16 ] = 0x12 ;
F_40 ( V_49 L_95
L_96 , V_5 + 16 ) ;
F_313 ( V_336 [ 4 ] ) ;
V_5 = F_248 ( 32 , V_253 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_40 ( V_49 L_97
L_98 , V_5 ) ;
F_40 ( V_49
L_99 ) ;
F_313 ( V_336 [ 5 ] ) ;
V_5 = F_248 ( 64 , V_253 ) ;
V_5 += 64 + ( F_155 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_40 ( V_49 L_100 ,
V_5 ) ;
F_40 ( V_49
L_99 ) ;
F_313 ( V_336 [ 6 ] ) ;
F_40 ( V_49 L_101 ) ;
V_5 = F_248 ( 128 , V_253 ) ;
F_251 ( V_5 ) ;
* V_5 = 0x78 ;
F_40 ( V_49 L_102 , V_5 ) ;
F_313 ( V_336 [ 7 ] ) ;
V_5 = F_248 ( 256 , V_253 ) ;
F_251 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_40 ( V_49 L_103 ,
V_5 ) ;
F_313 ( V_336 [ 8 ] ) ;
V_5 = F_248 ( 512 , V_253 ) ;
F_251 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_40 ( V_49 L_104 , V_5 ) ;
F_313 ( V_336 [ 9 ] ) ;
}
static void F_333 ( void ) {}
static T_9 F_334 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_337 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_330 ;
unsigned long * V_338 ;
V_330 = F_248 ( 2 * sizeof( unsigned long ) * V_301 , V_253 ) ;
if ( ! V_330 )
return - V_275 ;
V_338 = V_330 + V_301 ;
if ( V_3 & V_339 ) {
int V_64 ;
F_173 (cpu) {
struct V_158 * V_159 = F_174 ( V_2 -> V_8 , V_64 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_335 ( V_159 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_123 ( V_11 ) ;
if ( V_3 & V_340 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_341 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_337 += V_29 ;
V_330 [ V_10 ] += V_29 ;
V_11 = F_335 ( V_159 -> V_155 ) ;
if ( V_11 ) {
V_29 = V_11 -> V_202 ;
V_337 += V_29 ;
V_330 [ V_10 ] += V_29 ;
}
V_338 [ V_10 ] ++ ;
}
}
F_336 () ;
#ifdef F_2
if ( V_3 & V_342 ) {
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( V_3 & V_340 )
V_29 = F_94 ( & V_37 -> V_110 ) ;
else if ( V_3 & V_341 )
V_29 = F_94 ( & V_37 -> V_110 ) -
F_188 ( V_37 , F_187 ) ;
else
V_29 = F_94 ( & V_37 -> V_109 ) ;
V_337 += V_29 ;
V_330 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_343 ) {
F_238 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( V_3 & V_340 )
V_29 = F_188 ( V_37 , F_308 ) ;
else if ( V_3 & V_341 )
V_29 = F_188 ( V_37 , F_307 ) ;
else
V_29 = V_37 -> V_153 ;
V_337 += V_29 ;
V_330 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_73 , L_105 , V_337 ) ;
#ifdef F_153
F_238 (node, N_NORMAL_MEMORY)
if ( V_330 [ V_10 ] )
V_29 += sprintf ( V_73 + V_29 , L_106 ,
V_10 , V_330 [ V_10 ] ) ;
#endif
F_337 () ;
F_251 ( V_330 ) ;
return V_29 + sprintf ( V_73 + V_29 , L_90 ) ;
}
static int F_338 ( struct V_1 * V_2 )
{
int V_10 ;
F_196 (node) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
if ( F_94 ( & V_37 -> V_110 ) )
return 1 ;
}
return 0 ;
}
static T_9 F_339 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_15 ) ;
}
static T_9 F_340 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_257 ) ;
}
static T_9 F_341 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_21 ) ;
}
static T_9 F_342 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , F_28 ( V_2 -> V_122 ) ) ;
}
static T_9 F_343 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_25 ;
int V_308 ;
V_308 = F_344 ( V_73 , 10 , & V_25 ) ;
if ( V_308 )
return V_308 ;
if ( V_25 > V_245 || V_25 < V_239 )
return - V_264 ;
F_241 ( V_2 , V_25 ) ;
return V_48 ;
}
static T_9 F_345 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , F_27 ( V_2 -> V_122 ) ) ;
}
static T_9 F_346 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_108 , V_2 -> V_174 ) ;
}
static T_9 F_347 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_130 ;
int V_308 ;
V_308 = F_344 ( V_73 , 10 , & V_130 ) ;
if ( V_308 )
return V_308 ;
F_240 ( V_2 , V_130 ) ;
return V_48 ;
}
static T_9 F_348 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_109 , V_2 -> V_165 ) ;
}
static T_9 F_349 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_14 ;
int V_308 ;
V_308 = F_344 ( V_73 , 10 , & V_14 ) ;
if ( V_308 )
return V_308 ;
if ( V_14 && ! F_4 ( V_2 ) )
return - V_264 ;
V_2 -> V_165 = V_14 ;
F_184 ( V_2 ) ;
return V_48 ;
}
static T_9 F_350 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! V_2 -> F_107 )
return 0 ;
return sprintf ( V_73 , L_110 , V_2 -> F_107 ) ;
}
static T_9 F_351 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_304 - 1 ) ;
}
static T_9 F_352 ( struct V_1 * V_2 , char * V_73 )
{
return F_334 ( V_2 , V_73 , V_343 ) ;
}
static T_9 F_353 ( struct V_1 * V_2 , char * V_73 )
{
return F_334 ( V_2 , V_73 , V_339 ) ;
}
static T_9 F_354 ( struct V_1 * V_2 , char * V_73 )
{
return F_334 ( V_2 , V_73 , V_342 | V_341 ) ;
}
static T_9 F_355 ( struct V_1 * V_2 , char * V_73 )
{
return F_334 ( V_2 , V_73 , V_343 | V_341 ) ;
}
static T_9 F_356 ( struct V_1 * V_2 , char * V_73 )
{
int V_14 = 0 ;
int V_134 = 0 ;
int V_64 ;
int V_331 ;
F_357 (cpu) {
struct V_11 * V_11 = F_174 ( V_2 -> V_8 , V_64 ) -> V_155 ;
if ( V_11 ) {
V_134 += V_11 -> V_134 ;
V_14 += V_11 -> V_202 ;
}
}
V_331 = sprintf ( V_73 , L_111 , V_14 , V_134 ) ;
#ifdef F_293
F_357 (cpu) {
struct V_11 * V_11 = F_174 ( V_2 -> V_8 , V_64 ) -> V_155 ;
if ( V_11 && V_331 < V_27 - 20 )
V_331 += sprintf ( V_73 + V_331 , L_112 , V_64 ,
V_11 -> V_202 , V_11 -> V_134 ) ;
}
#endif
return V_331 + sprintf ( V_73 + V_331 , L_90 ) ;
}
static T_9 F_358 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_135 ) ) ;
}
static T_9 F_359 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_135 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_135 ;
return V_48 ;
}
static T_9 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_298 ) ) ;
}
static T_9 F_361 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_259 ) ) ;
}
static T_9 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_9 F_363 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_26 ) ;
}
static T_9 F_364 ( struct V_1 * V_2 , char * V_73 )
{
return F_334 ( V_2 , V_73 , V_342 ) ;
}
static T_9 F_365 ( struct V_1 * V_2 , char * V_73 )
{
return F_334 ( V_2 , V_73 , V_342 | V_340 ) ;
}
static T_9 F_366 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_9 F_367 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_119 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_119 ;
}
return V_48 ;
}
static T_9 F_368 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_9 F_369 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_101 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_101 ;
}
return V_48 ;
}
static T_9 F_370 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_9 F_371 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_338 ( V_2 ) )
return - V_344 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_19 ;
}
F_241 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_9 F_372 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_373 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_338 ( V_2 ) )
return - V_344 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_20 ;
}
F_241 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_9 F_374 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_9 F_375 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_338 ( V_2 ) )
return - V_344 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_23 ;
}
F_241 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_9 F_376 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_9 F_377 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
int V_224 = - V_264 ;
if ( V_73 [ 0 ] == '1' ) {
V_224 = F_313 ( V_2 ) ;
if ( V_224 >= 0 )
V_224 = V_48 ;
}
return V_224 ;
}
static T_9 F_378 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_247 ;
return F_326 ( V_2 , V_73 , V_70 ) ;
}
static T_9 F_379 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_247 ;
return F_326 ( V_2 , V_73 , V_69 ) ;
}
static T_9 F_380 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , ! ! ( V_2 -> V_3 & V_120 ) ) ;
}
static T_9 F_381 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_120 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_120 ;
return V_48 ;
}
static T_9 F_382 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_9 F_383 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( V_73 [ 0 ] == '1' ) {
int V_265 = F_276 ( V_2 ) ;
if ( V_265 )
return V_265 ;
} else
return - V_264 ;
return V_48 ;
}
static T_9 F_384 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_107 , V_2 -> V_173 / 10 ) ;
}
static T_9 F_385 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_345 ;
int V_308 ;
V_308 = F_344 ( V_73 , 10 , & V_345 ) ;
if ( V_308 )
return V_308 ;
if ( V_345 <= 100 )
V_2 -> V_173 = V_345 * 10 ;
return V_48 ;
}
static int F_386 ( struct V_1 * V_2 , char * V_73 , enum V_6 V_7 )
{
unsigned long V_346 = 0 ;
int V_64 ;
int V_331 ;
int * V_83 = F_277 ( V_244 * sizeof( int ) , V_253 ) ;
if ( ! V_83 )
return - V_275 ;
F_357 (cpu) {
unsigned V_29 = F_174 ( V_2 -> V_8 , V_64 ) -> F_10 [ V_7 ] ;
V_83 [ V_64 ] = V_29 ;
V_346 += V_29 ;
}
V_331 = sprintf ( V_73 , L_105 , V_346 ) ;
#ifdef F_293
F_357 (cpu) {
if ( V_83 [ V_64 ] && V_331 < V_27 - 20 )
V_331 += sprintf ( V_73 + V_331 , L_113 , V_64 , V_83 [ V_64 ] ) ;
}
#endif
F_251 ( V_83 ) ;
return V_331 + sprintf ( V_73 + V_331 , L_90 ) ;
}
static void F_387 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_64 ;
F_357 (cpu)
F_174 ( V_2 -> V_8 , V_64 ) -> F_10 [ V_7 ] = 0 ;
}
static T_9 F_388 ( struct V_347 * V_348 ,
struct V_349 * V_350 ,
char * V_73 )
{
struct V_351 * V_349 ;
struct V_1 * V_2 ;
int V_308 ;
V_349 = F_389 ( V_350 ) ;
V_2 = F_390 ( V_348 ) ;
if ( ! V_349 -> V_352 )
return - V_353 ;
V_308 = V_349 -> V_352 ( V_2 , V_73 ) ;
return V_308 ;
}
static T_9 F_391 ( struct V_347 * V_348 ,
struct V_349 * V_350 ,
const char * V_73 , T_1 V_331 )
{
struct V_351 * V_349 ;
struct V_1 * V_2 ;
int V_308 ;
V_349 = F_389 ( V_350 ) ;
V_2 = F_390 ( V_348 ) ;
if ( ! V_349 -> V_354 )
return - V_353 ;
V_308 = V_349 -> V_354 ( V_2 , V_73 , V_331 ) ;
#ifdef F_392
if ( V_251 >= V_355 && V_308 >= 0 && F_393 ( V_2 ) ) {
int V_56 ;
F_257 ( & V_266 ) ;
if ( V_2 -> V_356 < V_331 )
V_2 -> V_356 = V_331 ;
F_394 (i) {
struct V_1 * V_159 = F_395 ( V_2 , V_56 ) ;
if ( V_159 )
V_349 -> V_354 ( V_159 , V_73 , V_331 ) ;
}
F_256 ( & V_266 ) ;
}
#endif
return V_308 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_392
int V_56 ;
char * V_357 = NULL ;
if ( ! F_393 ( V_2 ) )
return;
if ( ! V_2 -> V_356 )
return;
for ( V_56 = 0 ; V_56 < F_396 ( V_358 ) ; V_56 ++ ) {
char V_359 [ 64 ] ;
char * V_73 ;
struct V_351 * V_350 = F_389 ( V_358 [ V_56 ] ) ;
if ( ! V_350 || ! V_350 -> V_354 || ! V_350 -> V_352 )
continue;
if ( V_357 )
V_73 = V_357 ;
else if ( V_2 -> V_356 < F_396 ( V_359 ) )
V_73 = V_359 ;
else {
V_357 = ( char * ) F_397 ( V_253 ) ;
if ( F_145 ( ! V_357 ) )
continue;
V_73 = V_357 ;
}
V_350 -> V_352 ( V_2 -> V_360 -> V_361 , V_73 ) ;
V_350 -> V_354 ( V_2 , V_73 , strlen ( V_73 ) ) ;
}
if ( V_357 )
F_398 ( ( unsigned long ) V_357 ) ;
#endif
}
static int F_399 ( struct V_362 * V_362 , struct V_347 * V_348 )
{
struct V_363 * V_364 = F_400 ( V_348 ) ;
if ( V_364 == & V_365 )
return 1 ;
return 0 ;
}
static char * F_401 ( struct V_1 * V_2 )
{
char * V_45 = F_277 ( V_366 , V_253 ) ;
char * V_5 = V_45 ;
F_122 ( ! V_45 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_259 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_135 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_119 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_133 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_45 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_114 , V_2 -> V_15 ) ;
#ifdef F_392
if ( ! F_393 ( V_2 ) )
V_5 += sprintf ( V_5 , L_115 , F_402 ( V_2 -> V_360 -> V_306 ) ) ;
#endif
F_122 ( V_5 > V_45 + V_366 - 1 ) ;
return V_45 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_308 ;
const char * V_45 ;
int V_367 = F_297 ( V_2 ) ;
if ( V_367 ) {
F_403 ( & V_368 -> V_348 , V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
} else {
V_45 = F_401 ( V_2 ) ;
}
V_2 -> V_348 . V_362 = V_368 ;
V_308 = F_404 ( & V_2 -> V_348 , & V_365 , NULL , V_45 ) ;
if ( V_308 ) {
F_405 ( & V_2 -> V_348 ) ;
return V_308 ;
}
V_308 = F_406 ( & V_2 -> V_348 , & V_369 ) ;
if ( V_308 ) {
F_407 ( & V_2 -> V_348 ) ;
F_405 ( & V_2 -> V_348 ) ;
return V_308 ;
}
F_408 ( & V_2 -> V_348 , V_370 ) ;
if ( ! V_367 ) {
F_7 ( V_2 , V_2 -> V_45 ) ;
F_251 ( V_45 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_251 < V_355 )
return;
F_408 ( & V_2 -> V_348 , V_371 ) ;
F_407 ( & V_2 -> V_348 ) ;
F_405 ( & V_2 -> V_348 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_45 )
{
struct V_372 * V_373 ;
if ( V_251 == V_355 ) {
F_403 ( & V_368 -> V_348 , V_45 ) ;
return F_409 ( & V_368 -> V_348 , & V_2 -> V_348 , V_45 ) ;
}
V_373 = F_277 ( sizeof( struct V_372 ) , V_253 ) ;
if ( ! V_373 )
return - V_275 ;
V_373 -> V_2 = V_2 ;
V_373 -> V_45 = V_45 ;
V_373 -> V_198 = V_374 ;
V_374 = V_373 ;
return 0 ;
}
static int T_7 F_410 ( void )
{
struct V_1 * V_2 ;
int V_308 ;
F_257 ( & V_266 ) ;
V_368 = F_411 ( L_116 , & V_375 , V_376 ) ;
if ( ! V_368 ) {
F_256 ( & V_266 ) ;
F_40 ( V_49 L_117 ) ;
return - V_247 ;
}
V_251 = V_355 ;
F_191 (s, &slab_caches, list) {
V_308 = F_6 ( V_2 ) ;
if ( V_308 )
F_40 ( V_49 L_118
L_119 , V_2 -> V_45 ) ;
}
while ( V_374 ) {
struct V_372 * V_373 = V_374 ;
V_374 = V_374 -> V_198 ;
V_308 = F_7 ( V_373 -> V_2 , V_373 -> V_45 ) ;
if ( V_308 )
F_40 ( V_49 L_120
L_121 , V_373 -> V_45 ) ;
F_251 ( V_373 ) ;
}
F_256 ( & V_266 ) ;
F_333 () ;
return 0 ;
}
void F_412 ( struct V_1 * V_2 , struct V_377 * V_378 )
{
unsigned long V_109 = 0 ;
unsigned long V_211 = 0 ;
unsigned long V_212 = 0 ;
int V_10 ;
F_196 (node) {
struct V_9 * V_37 = F_13 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
V_109 += F_95 ( V_37 ) ;
V_211 += F_193 ( V_37 ) ;
V_212 += F_188 ( V_37 , F_187 ) ;
}
V_378 -> V_379 = V_211 - V_212 ;
V_378 -> V_380 = V_211 ;
V_378 -> V_381 = V_109 ;
V_378 -> V_382 = V_109 ;
V_378 -> V_383 = F_28 ( V_2 -> V_122 ) ;
V_378 -> V_384 = F_27 ( V_2 -> V_122 ) ;
}
void F_413 ( struct V_385 * V_186 , struct V_1 * V_2 )
{
}
T_9 F_414 ( struct V_386 * V_386 , const char T_10 * V_357 ,
T_1 V_317 , T_11 * V_387 )
{
return - V_353 ;
}
