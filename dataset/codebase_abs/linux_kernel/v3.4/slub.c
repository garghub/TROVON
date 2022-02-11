static inline int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return F_3 ( V_2 -> V_3 & V_4 ) ;
#else
return 0 ;
#endif
}
static inline int F_4 ( struct V_1 * V_2 ) { return 0 ; }
static inline int F_5 ( struct V_1 * V_2 , const char * V_5 )
{ return 0 ; }
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static inline void F_8 ( const struct V_1 * V_2 , enum V_7 V_8 )
{
#ifdef F_9
F_10 ( V_2 -> V_9 -> F_8 [ V_8 ] ) ;
#endif
}
int F_11 ( void )
{
return V_10 >= V_11 ;
}
static inline struct V_12 * F_12 ( struct V_1 * V_2 , int V_13 )
{
return V_2 -> V_13 [ V_13 ] ;
}
static inline int F_13 ( struct V_1 * V_2 ,
struct V_14 * V_14 , const void * V_15 )
{
void * V_16 ;
if ( ! V_15 )
return 1 ;
V_16 = F_14 ( V_14 ) ;
if ( V_15 < V_16 || V_15 >= V_16 + V_14 -> V_17 * V_2 -> V_18 ||
( V_15 - V_16 ) % V_2 -> V_18 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_15 ( struct V_1 * V_2 , void * V_15 )
{
return * ( void * * ) ( V_15 + V_2 -> V_19 ) ;
}
static void F_16 ( const struct V_1 * V_2 , void * V_15 )
{
F_17 ( V_15 + V_2 -> V_19 ) ;
}
static inline void * F_18 ( struct V_1 * V_2 , void * V_15 )
{
void * V_5 ;
#ifdef F_19
F_20 ( & V_5 , ( void * * ) ( V_15 + V_2 -> V_19 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_15 ( V_2 , V_15 ) ;
#endif
return V_5 ;
}
static inline void F_21 ( struct V_1 * V_2 , void * V_15 , void * V_20 )
{
* ( void * * ) ( V_15 + V_2 -> V_19 ) = V_20 ;
}
static inline int F_22 ( void * V_5 , struct V_1 * V_2 , void * V_21 )
{
return ( V_5 - V_21 ) / V_2 -> V_18 ;
}
static inline T_1 F_23 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_22 | V_23 ) )
return V_2 -> V_24 ;
#endif
if ( V_2 -> V_3 & ( V_25 | V_26 ) )
return V_2 -> V_27 ;
return V_2 -> V_18 ;
}
static inline int F_24 ( int V_28 , unsigned long V_18 , int V_29 )
{
return ( ( V_30 << V_28 ) - V_29 ) / V_18 ;
}
static inline struct V_31 F_25 ( int V_28 ,
unsigned long V_18 , int V_29 )
{
struct V_31 V_32 = {
( V_28 << V_33 ) + F_24 (order, size, reserved)
} ;
return V_32 ;
}
static inline int F_26 ( struct V_31 V_32 )
{
return V_32 . V_32 >> V_33 ;
}
static inline int F_27 ( struct V_31 V_32 )
{
return V_32 . V_32 & V_34 ;
}
static T_2 void F_28 ( struct V_14 * V_14 )
{
F_29 ( V_35 , & V_14 -> V_3 ) ;
}
static T_2 void F_30 ( struct V_14 * V_14 )
{
F_31 ( V_35 , & V_14 -> V_3 ) ;
}
static inline bool F_32 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_39 ,
const char * V_40 )
{
F_33 ( ! F_34 () ) ;
#if F_35 ( V_41 ) && \
F_35 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_36 ( & V_14 -> V_44 , & V_14 -> V_45 ,
V_36 , V_37 ,
V_38 , V_39 ) )
return 1 ;
} else
#endif
{
F_28 ( V_14 ) ;
if ( V_14 -> V_44 == V_36 && V_14 -> V_45 == V_37 ) {
V_14 -> V_44 = V_38 ;
V_14 -> V_45 = V_39 ;
F_30 ( V_14 ) ;
return 1 ;
}
F_30 ( V_14 ) ;
}
F_37 () ;
F_8 ( V_2 , V_46 ) ;
#ifdef F_38
F_39 ( V_47 L_1 , V_40 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static inline bool F_40 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_39 ,
const char * V_40 )
{
#if F_35 ( V_41 ) && \
F_35 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_36 ( & V_14 -> V_44 , & V_14 -> V_45 ,
V_36 , V_37 ,
V_38 , V_39 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_28 ( V_14 ) ;
if ( V_14 -> V_44 == V_36 && V_14 -> V_45 == V_37 ) {
V_14 -> V_44 = V_38 ;
V_14 -> V_45 = V_39 ;
F_30 ( V_14 ) ;
F_42 ( V_3 ) ;
return 1 ;
}
F_30 ( V_14 ) ;
F_42 ( V_3 ) ;
}
F_37 () ;
F_8 ( V_2 , V_46 ) ;
#ifdef F_38
F_39 ( V_47 L_1 , V_40 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_14 * V_14 , unsigned long * V_48 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
for ( V_5 = V_14 -> V_44 ; V_5 ; V_5 = F_15 ( V_2 , V_5 ) )
F_44 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) ;
}
static void F_45 ( char * V_49 , T_3 * V_21 , unsigned int V_50 )
{
F_46 ( V_51 , V_49 , V_52 , 16 , 1 , V_21 ,
V_50 , 1 ) ;
}
static struct V_53 * F_47 ( struct V_1 * V_2 , void * V_15 ,
enum V_54 V_55 )
{
struct V_53 * V_5 ;
if ( V_2 -> V_19 )
V_5 = V_15 + V_2 -> V_19 + sizeof( void * ) ;
else
V_5 = V_15 + V_2 -> V_27 ;
return V_5 + V_55 ;
}
static void F_48 ( struct V_1 * V_2 , void * V_15 ,
enum V_54 V_55 , unsigned long V_21 )
{
struct V_53 * V_5 = F_47 ( V_2 , V_15 , V_55 ) ;
if ( V_21 ) {
#ifdef F_49
struct V_56 V_57 ;
int V_58 ;
V_57 . V_59 = 0 ;
V_57 . V_60 = V_61 ;
V_57 . V_62 = V_5 -> V_63 ;
V_57 . V_64 = 3 ;
F_50 ( & V_57 ) ;
if ( V_57 . V_59 != 0 &&
V_57 . V_62 [ V_57 . V_59 - 1 ] == V_65 )
V_57 . V_59 -- ;
for ( V_58 = V_57 . V_59 ; V_58 < V_61 ; V_58 ++ )
V_5 -> V_63 [ V_58 ] = 0 ;
#endif
V_5 -> V_21 = V_21 ;
V_5 -> V_66 = F_51 () ;
V_5 -> V_67 = V_68 -> V_67 ;
V_5 -> V_69 = V_70 ;
} else
memset ( V_5 , 0 , sizeof( struct V_53 ) ) ;
}
static void F_52 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_48 ( V_2 , V_15 , V_71 , 0UL ) ;
F_48 ( V_2 , V_15 , V_72 , 0UL ) ;
}
static void F_53 ( const char * V_2 , struct V_53 * V_73 )
{
if ( ! V_73 -> V_21 )
return;
F_39 ( V_51 L_2 ,
V_2 , ( void * ) V_73 -> V_21 , V_70 - V_73 -> V_69 , V_73 -> V_66 , V_73 -> V_67 ) ;
#ifdef F_49
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 ; V_58 ++ )
if ( V_73 -> V_63 [ V_58 ] )
F_39 ( V_51 L_3 , ( void * ) V_73 -> V_63 [ V_58 ] ) ;
else
break;
}
#endif
}
static void F_54 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_53 ( L_4 , F_47 ( V_2 , V_15 , V_72 ) ) ;
F_53 ( L_5 , F_47 ( V_2 , V_15 , V_71 ) ) ;
}
static void F_55 ( struct V_14 * V_14 )
{
F_39 ( V_51 L_6 ,
V_14 , V_14 -> V_17 , V_14 -> V_27 , V_14 -> V_44 , V_14 -> V_3 ) ;
}
static void F_56 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_39 ( V_51 L_7
L_8 ) ;
F_39 ( V_51 L_9 , V_2 -> V_6 , F_57 () , V_75 ) ;
F_39 ( V_51 L_10
L_11 ) ;
}
static void F_58 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_39 ( V_51 L_12 , V_2 -> V_6 , V_75 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned int V_76 ;
T_3 * V_21 = F_14 ( V_14 ) ;
F_54 ( V_2 , V_5 ) ;
F_55 ( V_14 ) ;
F_39 ( V_51 L_13 ,
V_5 , V_5 - V_21 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_21 + 16 )
F_45 ( L_14 , V_5 - 16 , 16 ) ;
F_45 ( L_15 , V_5 , F_60 (unsigned long, s->objsize,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_22 )
F_45 ( L_16 , V_5 + V_2 -> V_24 ,
V_2 -> V_27 - V_2 -> V_24 ) ;
if ( V_2 -> V_19 )
V_76 = V_2 -> V_19 + sizeof( void * ) ;
else
V_76 = V_2 -> V_27 ;
if ( V_2 -> V_3 & V_26 )
V_76 += 2 * sizeof( struct V_53 ) ;
if ( V_76 != V_2 -> V_18 )
F_45 ( L_17 , V_5 + V_76 , V_2 -> V_18 - V_76 ) ;
F_61 () ;
}
static void F_62 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_77 )
{
F_56 ( V_2 , L_18 , V_77 ) ;
F_59 ( V_2 , V_14 , V_15 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_14 * V_14 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_56 ( V_2 , L_18 , V_75 ) ;
F_55 ( V_14 ) ;
F_61 () ;
}
static void F_64 ( struct V_1 * V_2 , void * V_15 , T_3 V_78 )
{
T_3 * V_5 = V_15 ;
if ( V_2 -> V_3 & V_79 ) {
memset ( V_5 , V_80 , V_2 -> V_24 - 1 ) ;
V_5 [ V_2 -> V_24 - 1 ] = V_81 ;
}
if ( V_2 -> V_3 & V_22 )
memset ( V_5 + V_2 -> V_24 , V_78 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
static void F_65 ( struct V_1 * V_2 , char * V_82 , T_3 V_83 ,
void * V_84 , void * V_85 )
{
F_58 ( V_2 , L_19 , V_84 , V_85 - 1 , V_83 ) ;
memset ( V_84 , V_83 , V_85 - V_84 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_86 ,
T_3 * V_87 , unsigned int V_88 , unsigned int V_89 )
{
T_3 * V_90 ;
T_3 * V_91 ;
V_90 = F_67 ( V_87 , V_88 , V_89 ) ;
if ( ! V_90 )
return 1 ;
V_91 = V_87 + V_89 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_88 )
V_91 -- ;
F_56 ( V_2 , L_20 , V_86 ) ;
F_39 ( V_51 L_21 ,
V_90 , V_91 - 1 , V_90 [ 0 ] , V_88 ) ;
F_59 ( V_2 , V_14 , V_15 ) ;
F_65 ( V_2 , V_86 , V_88 , V_90 , V_91 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned long V_76 = V_2 -> V_27 ;
if ( V_2 -> V_19 )
V_76 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_26 )
V_76 += 2 * sizeof( struct V_53 ) ;
if ( V_2 -> V_18 == V_76 )
return 1 ;
return F_66 ( V_2 , V_14 , V_5 , L_22 ,
V_5 + V_76 , V_92 , V_2 -> V_18 - V_76 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
T_3 * V_87 ;
T_3 * V_90 ;
T_3 * V_91 ;
int V_50 ;
int V_93 ;
if ( ! ( V_2 -> V_3 & V_23 ) )
return 1 ;
V_87 = F_14 ( V_14 ) ;
V_50 = ( V_30 << F_70 ( V_14 ) ) - V_2 -> V_29 ;
V_91 = V_87 + V_50 ;
V_93 = V_50 % V_2 -> V_18 ;
if ( ! V_93 )
return 1 ;
V_90 = F_67 ( V_91 - V_93 , V_92 , V_93 ) ;
if ( ! V_90 )
return 1 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_92 )
V_91 -- ;
F_63 ( V_2 , V_14 , L_23 , V_90 , V_91 - 1 ) ;
F_45 ( L_17 , V_91 - V_93 , V_93 ) ;
F_65 ( V_2 , L_24 , V_92 , V_91 - V_93 , V_91 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_78 )
{
T_3 * V_5 = V_15 ;
T_3 * V_94 = V_15 + V_2 -> V_24 ;
if ( V_2 -> V_3 & V_22 ) {
if ( ! F_66 ( V_2 , V_14 , V_15 , L_25 ,
V_94 , V_78 , V_2 -> V_27 - V_2 -> V_24 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_23 ) && V_2 -> V_24 < V_2 -> V_27 ) {
F_66 ( V_2 , V_14 , V_5 , L_26 ,
V_94 , V_92 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
}
if ( V_2 -> V_3 & V_23 ) {
if ( V_78 != V_95 && ( V_2 -> V_3 & V_79 ) &&
( ! F_66 ( V_2 , V_14 , V_5 , L_27 , V_5 ,
V_80 , V_2 -> V_24 - 1 ) ||
! F_66 ( V_2 , V_14 , V_5 , L_27 ,
V_5 + V_2 -> V_24 - 1 , V_81 , 1 ) ) )
return 0 ;
F_68 ( V_2 , V_14 , V_5 ) ;
}
if ( ! V_2 -> V_19 && V_78 == V_95 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , F_15 ( V_2 , V_5 ) ) ) {
F_62 ( V_2 , V_14 , V_5 , L_28 ) ;
F_21 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_96 ;
F_33 ( ! F_34 () ) ;
if ( ! F_73 ( V_14 ) ) {
F_63 ( V_2 , V_14 , L_29 ) ;
return 0 ;
}
V_96 = F_24 ( F_70 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_14 -> V_17 > V_96 ) {
F_63 ( V_2 , V_14 , L_30 ,
V_2 -> V_6 , V_14 -> V_17 , V_96 ) ;
return 0 ;
}
if ( V_14 -> V_27 > V_14 -> V_17 ) {
F_63 ( V_2 , V_14 , L_31 ,
V_2 -> V_6 , V_14 -> V_27 , V_14 -> V_17 ) ;
return 0 ;
}
F_69 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_97 )
{
int V_98 = 0 ;
void * V_20 ;
void * V_15 = NULL ;
unsigned long V_99 ;
V_20 = V_14 -> V_44 ;
while ( V_20 && V_98 <= V_14 -> V_17 ) {
if ( V_20 == V_97 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , V_20 ) ) {
if ( V_15 ) {
F_62 ( V_2 , V_14 , V_15 ,
L_32 ) ;
F_21 ( V_2 , V_15 , NULL ) ;
break;
} else {
F_63 ( V_2 , V_14 , L_28 ) ;
V_14 -> V_44 = NULL ;
V_14 -> V_27 = V_14 -> V_17 ;
F_58 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_15 = V_20 ;
V_20 = F_15 ( V_2 , V_15 ) ;
V_98 ++ ;
}
V_99 = F_24 ( F_70 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_99 > V_100 )
V_99 = V_100 ;
if ( V_14 -> V_17 != V_99 ) {
F_63 ( V_2 , V_14 , L_34
L_35 , V_14 -> V_17 , V_99 ) ;
V_14 -> V_17 = V_99 ;
F_58 ( V_2 , L_36 ) ;
}
if ( V_14 -> V_27 != V_14 -> V_17 - V_98 ) {
F_63 ( V_2 , V_14 , L_37
L_38 , V_14 -> V_27 , V_14 -> V_17 - V_98 ) ;
V_14 -> V_27 = V_14 -> V_17 - V_98 ;
F_58 ( V_2 , L_39 ) ;
}
return V_97 == NULL ;
}
static void V_57 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_15 ,
int V_55 )
{
if ( V_2 -> V_3 & V_101 ) {
F_39 ( V_47 L_40 ,
V_2 -> V_6 ,
V_55 ? L_41 : L_42 ,
V_15 , V_14 -> V_27 ,
V_14 -> V_44 ) ;
if ( ! V_55 )
F_45 ( L_15 , ( void * ) V_15 , V_2 -> V_24 ) ;
F_61 () ;
}
}
static inline int F_75 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_102 ;
F_76 ( V_3 ) ;
F_77 ( V_3 & V_103 ) ;
return F_78 ( V_2 -> V_24 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_79 ( struct V_1 * V_2 , T_5 V_3 , void * V_15 )
{
V_3 &= V_102 ;
F_80 ( V_2 , V_3 , V_15 , F_23 ( V_2 ) ) ;
F_81 ( V_15 , V_2 -> V_24 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_82 ( struct V_1 * V_2 , void * V_32 )
{
F_83 ( V_32 , V_2 -> V_3 ) ;
#if F_35 ( V_104 ) || F_35 ( V_105 )
{
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_84 ( V_2 , V_32 , V_2 -> V_24 ) ;
F_85 ( V_32 , V_2 -> V_24 ) ;
F_42 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_106 ) )
F_86 ( V_32 , V_2 -> V_24 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_88 ( & V_14 -> V_107 , & V_40 -> V_108 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_90 ( & V_14 -> V_107 ) ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_13 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
return F_92 ( & V_40 -> V_109 ) ;
}
static inline unsigned long F_93 ( struct V_12 * V_40 )
{
return F_92 ( & V_40 -> V_109 ) ;
}
static inline void F_94 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_40 ) {
F_95 ( & V_40 -> V_109 ) ;
F_96 ( V_17 , & V_40 -> V_110 ) ;
}
}
static inline void F_97 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_98 ( & V_40 -> V_109 ) ;
F_99 ( V_17 , & V_40 -> V_110 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
if ( ! ( V_2 -> V_3 & ( V_26 | V_22 | V_79 ) ) )
return;
F_64 ( V_2 , V_15 , V_111 ) ;
F_52 ( V_2 , V_15 ) ;
}
static T_6 int F_101 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , unsigned long V_21 )
{
if ( ! F_72 ( V_2 , V_14 ) )
goto V_112;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_62 ( V_2 , V_14 , V_15 , L_43 ) ;
goto V_112;
}
if ( ! F_71 ( V_2 , V_14 , V_15 , V_111 ) )
goto V_112;
if ( V_2 -> V_3 & V_26 )
F_48 ( V_2 , V_15 , V_72 , V_21 ) ;
V_57 ( V_2 , V_14 , V_15 , 1 ) ;
F_64 ( V_2 , V_15 , V_95 ) ;
return 1 ;
V_112:
if ( F_73 ( V_14 ) ) {
F_58 ( V_2 , L_44 ) ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_44 = NULL ;
}
return 0 ;
}
static T_6 int F_102 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 )
{
unsigned long V_3 ;
int V_113 = 0 ;
F_41 ( V_3 ) ;
F_28 ( V_14 ) ;
if ( ! F_72 ( V_2 , V_14 ) )
goto V_114;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_63 ( V_2 , V_14 , L_45 , V_15 ) ;
goto V_114;
}
if ( F_74 ( V_2 , V_14 , V_15 ) ) {
F_62 ( V_2 , V_14 , V_15 , L_46 ) ;
goto V_114;
}
if ( ! F_71 ( V_2 , V_14 , V_15 , V_95 ) )
goto V_115;
if ( F_3 ( V_2 != V_14 -> V_116 ) ) {
if ( ! F_73 ( V_14 ) ) {
F_63 ( V_2 , V_14 , L_47
L_48 , V_15 ) ;
} else if ( ! V_14 -> V_116 ) {
F_39 ( V_51
L_49 ,
V_15 ) ;
F_61 () ;
} else
F_62 ( V_2 , V_14 , V_15 ,
L_50 ) ;
goto V_114;
}
if ( V_2 -> V_3 & V_26 )
F_48 ( V_2 , V_15 , V_71 , V_21 ) ;
V_57 ( V_2 , V_14 , V_15 , 0 ) ;
F_64 ( V_2 , V_15 , V_111 ) ;
V_113 = 1 ;
V_115:
F_30 ( V_14 ) ;
F_42 ( V_3 ) ;
return V_113 ;
V_114:
F_58 ( V_2 , L_51 , V_15 ) ;
goto V_115;
}
static int T_7 F_103 ( char * V_117 )
{
V_118 = V_119 ;
if ( * V_117 ++ != '=' || ! * V_117 )
goto V_115;
if ( * V_117 == ',' )
goto V_120;
if ( tolower ( * V_117 ) == 'o' ) {
V_121 = 1 ;
goto V_115;
}
V_118 = 0 ;
if ( * V_117 == '-' )
goto V_115;
for (; * V_117 && * V_117 != ',' ; V_117 ++ ) {
switch ( tolower ( * V_117 ) ) {
case 'f' :
V_118 |= V_122 ;
break;
case 'z' :
V_118 |= V_22 ;
break;
case 'p' :
V_118 |= V_23 ;
break;
case 'u' :
V_118 |= V_26 ;
break;
case 't' :
V_118 |= V_101 ;
break;
case 'a' :
V_118 |= V_123 ;
break;
default:
F_39 ( V_51 L_52
L_53 , * V_117 ) ;
}
}
V_120:
if ( * V_117 == ',' )
V_124 = V_117 + 1 ;
V_115:
return 1 ;
}
static unsigned long F_104 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_105)( void * ) )
{
if ( V_118 && ( ! V_124 ||
! strncmp ( V_124 , V_6 , strlen ( V_124 ) ) ) )
V_3 |= V_118 ;
return V_3 ;
}
static inline void F_100 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 ) {}
static inline int F_101 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_102 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_69 ( struct V_1 * V_2 , struct V_14 * V_14 )
{ return 1 ; }
static inline int F_71 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_78 ) { return 1 ; }
static inline void F_87 ( struct V_1 * V_2 , struct V_12 * V_40 ,
struct V_14 * V_14 ) {}
static inline void F_89 ( struct V_1 * V_2 , struct V_14 * V_14 ) {}
static inline unsigned long F_104 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_105)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_13 )
{ return 0 ; }
static inline unsigned long F_93 ( struct V_12 * V_40 )
{ return 0 ; }
static inline void F_94 ( struct V_1 * V_2 , int V_13 ,
int V_17 ) {}
static inline void F_97 ( struct V_1 * V_2 , int V_13 ,
int V_17 ) {}
static inline int F_75 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_79 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_15 ) {}
static inline void F_82 ( struct V_1 * V_2 , void * V_32 ) {}
static inline struct V_14 * F_106 ( T_5 V_3 , int V_13 ,
struct V_31 V_125 )
{
int V_28 = F_26 ( V_125 ) ;
V_3 |= V_126 ;
if ( V_13 == V_127 )
return F_107 ( V_3 , V_28 ) ;
else
return F_108 ( V_13 , V_3 , V_28 ) ;
}
static struct V_14 * F_109 ( struct V_1 * V_2 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
struct V_31 V_125 = V_2 -> V_125 ;
T_5 V_128 ;
V_3 &= V_102 ;
if ( V_3 & V_103 )
F_110 () ;
V_3 |= V_2 -> V_129 ;
V_128 = ( V_3 | V_130 | V_131 ) & ~ V_132 ;
V_14 = F_106 ( V_128 , V_13 , V_125 ) ;
if ( F_3 ( ! V_14 ) ) {
V_125 = V_2 -> V_133 ;
V_14 = F_106 ( V_3 , V_13 , V_125 ) ;
if ( V_14 )
F_8 ( V_2 , V_134 ) ;
}
if ( V_3 & V_103 )
F_111 () ;
if ( ! V_14 )
return NULL ;
if ( V_135
&& ! ( V_2 -> V_3 & ( V_136 | V_119 ) ) ) {
int V_137 = 1 << F_26 ( V_125 ) ;
F_112 ( V_14 , F_26 ( V_125 ) , V_3 , V_13 ) ;
if ( V_2 -> F_105 )
F_113 ( V_14 , V_137 ) ;
else
F_114 ( V_14 , V_137 ) ;
}
V_14 -> V_17 = F_27 ( V_125 ) ;
F_115 ( F_116 ( V_14 ) ,
( V_2 -> V_3 & V_138 ) ?
V_139 : V_140 ,
1 << F_26 ( V_125 ) ) ;
return V_14 ;
}
static void F_117 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
F_100 ( V_2 , V_14 , V_15 ) ;
if ( F_3 ( V_2 -> F_105 ) )
V_2 -> F_105 ( V_15 ) ;
}
static struct V_14 * F_118 ( struct V_1 * V_2 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_87 ;
void * V_141 ;
void * V_5 ;
F_119 ( V_3 & V_142 ) ;
V_14 = F_109 ( V_2 ,
V_3 & ( V_143 | V_144 ) , V_13 ) ;
if ( ! V_14 )
goto V_115;
F_94 ( V_2 , F_120 ( V_14 ) , V_14 -> V_17 ) ;
V_14 -> V_116 = V_2 ;
V_14 -> V_3 |= 1 << V_145 ;
V_87 = F_14 ( V_14 ) ;
if ( F_3 ( V_2 -> V_3 & V_23 ) )
memset ( V_87 , V_92 , V_30 << F_70 ( V_14 ) ) ;
V_141 = V_87 ;
F_121 (p, s, start, page->objects) {
F_117 ( V_2 , V_14 , V_141 ) ;
F_21 ( V_2 , V_141 , V_5 ) ;
V_141 = V_5 ;
}
F_117 ( V_2 , V_14 , V_141 ) ;
F_21 ( V_2 , V_141 , NULL ) ;
V_14 -> V_44 = V_87 ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_146 = 1 ;
V_115:
return V_14 ;
}
static void F_122 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_28 = F_70 ( V_14 ) ;
int V_137 = 1 << V_28 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_69 ( V_2 , V_14 ) ;
F_121 (p, s, page_address(page),
page->objects)
F_71 ( V_2 , V_14 , V_5 , V_111 ) ;
}
F_123 ( V_14 , F_70 ( V_14 ) ) ;
F_115 ( F_116 ( V_14 ) ,
( V_2 -> V_3 & V_138 ) ?
V_139 : V_140 ,
- V_137 ) ;
F_124 ( V_14 ) ;
F_125 ( V_14 ) ;
if ( V_68 -> V_147 )
V_68 -> V_147 -> V_148 += V_137 ;
F_126 ( V_14 , V_28 ) ;
}
static void F_127 ( struct V_149 * V_150 )
{
struct V_14 * V_14 ;
if ( V_151 )
V_14 = F_128 ( V_150 ) ;
else
V_14 = F_129 ( (struct V_152 * ) V_150 , struct V_14 , V_107 ) ;
F_122 ( V_14 -> V_116 , V_14 ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( F_3 ( V_2 -> V_3 & V_25 ) ) {
struct V_149 * V_153 ;
if ( V_151 ) {
int V_28 = F_70 ( V_14 ) ;
int V_19 = ( V_30 << V_28 ) - V_2 -> V_29 ;
F_33 ( V_2 -> V_29 != sizeof( * V_153 ) ) ;
V_153 = F_14 ( V_14 ) + V_19 ;
} else {
V_153 = ( void * ) & V_14 -> V_107 ;
}
F_131 ( V_153 , F_127 ) ;
} else
F_122 ( V_2 , V_14 ) ;
}
static void F_132 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
F_97 ( V_2 , F_120 ( V_14 ) , V_14 -> V_17 ) ;
F_130 ( V_2 , V_14 ) ;
}
static inline void F_133 ( struct V_12 * V_40 ,
struct V_14 * V_14 , int V_154 )
{
V_40 -> V_155 ++ ;
if ( V_154 == V_156 )
F_134 ( & V_14 -> V_107 , & V_40 -> V_157 ) ;
else
F_88 ( & V_14 -> V_107 , & V_40 -> V_157 ) ;
}
static inline void F_135 ( struct V_12 * V_40 ,
struct V_14 * V_14 )
{
F_90 ( & V_14 -> V_107 ) ;
V_40 -> V_155 -- ;
}
static inline void * F_136 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 ,
int V_158 )
{
void * V_44 ;
unsigned long V_45 ;
struct V_14 V_159 ;
do {
V_44 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
V_159 . V_45 = V_45 ;
if ( V_158 )
V_159 . V_27 = V_14 -> V_17 ;
F_33 ( V_159 . V_146 ) ;
V_159 . V_146 = 1 ;
} while ( ! F_32 ( V_2 , V_14 ,
V_44 , V_45 ,
NULL , V_159 . V_45 ,
L_54 ) );
F_135 ( V_40 , V_14 ) ;
return V_44 ;
}
static void * F_137 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_160 * V_161 )
{
struct V_14 * V_14 , * V_162 ;
void * V_15 = NULL ;
if ( ! V_40 || ! V_40 -> V_155 )
return NULL ;
F_138 ( & V_40 -> V_163 ) ;
F_139 (page, page2, &n->partial, lru) {
void * V_73 = F_136 ( V_2 , V_40 , V_14 , V_15 == NULL ) ;
int V_164 ;
if ( ! V_73 )
break;
if ( ! V_15 ) {
V_161 -> V_14 = V_14 ;
V_161 -> V_13 = F_120 ( V_14 ) ;
F_8 ( V_2 , V_165 ) ;
V_15 = V_73 ;
V_164 = V_14 -> V_17 - V_14 -> V_27 ;
} else {
V_14 -> V_44 = V_73 ;
V_164 = F_140 ( V_2 , V_14 , 0 ) ;
F_8 ( V_2 , V_166 ) ;
}
if ( F_1 ( V_2 ) || V_164 > V_2 -> V_167 / 2 )
break;
}
F_141 ( & V_40 -> V_163 ) ;
return V_15 ;
}
static struct V_14 * F_142 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_160 * V_161 )
{
#ifdef F_143
struct V_168 * V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_171 ;
enum V_172 V_173 = F_144 ( V_3 ) ;
void * V_15 ;
unsigned int V_174 ;
if ( ! V_2 -> V_175 ||
F_145 () % 1024 > V_2 -> V_175 )
return NULL ;
do {
V_174 = F_146 () ;
V_168 = F_147 ( F_148 ( V_68 -> V_176 ) , V_3 ) ;
F_149 (zone, z, zonelist, high_zoneidx) {
struct V_12 * V_40 ;
V_40 = F_12 ( V_2 , F_150 ( V_171 ) ) ;
if ( V_40 && F_151 ( V_171 , V_3 ) &&
V_40 -> V_155 > V_2 -> V_177 ) {
V_15 = F_137 ( V_2 , V_40 , V_161 ) ;
if ( V_15 ) {
F_152 ( V_174 ) ;
return V_15 ;
}
}
}
} while ( ! F_152 ( V_174 ) );
#endif
return NULL ;
}
static void * F_153 ( struct V_1 * V_2 , T_5 V_3 , int V_13 ,
struct V_160 * V_161 )
{
void * V_15 ;
int V_178 = ( V_13 == V_127 ) ? F_154 () : V_13 ;
V_15 = F_137 ( V_2 , F_12 ( V_2 , V_178 ) , V_161 ) ;
if ( V_15 || V_13 != V_127 )
return V_15 ;
return F_142 ( V_2 , V_3 , V_161 ) ;
}
static inline unsigned long F_155 ( unsigned long V_179 )
{
return V_179 + V_180 ;
}
static inline unsigned int F_156 ( unsigned long V_179 )
{
return V_179 % V_180 ;
}
static inline unsigned long F_157 ( unsigned long V_179 )
{
return V_179 / V_180 ;
}
static inline unsigned int F_158 ( int V_66 )
{
return V_66 ;
}
static inline void F_159 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_179 )
{
#ifdef F_38
unsigned long V_181 = F_160 ( V_2 -> V_9 -> V_179 ) ;
F_39 ( V_47 L_55 , V_40 , V_2 -> V_6 ) ;
#ifdef F_161
if ( F_156 ( V_179 ) != F_156 ( V_181 ) )
F_39 ( L_56 ,
F_156 ( V_179 ) , F_156 ( V_181 ) ) ;
else
#endif
if ( F_157 ( V_179 ) != F_157 ( V_181 ) )
F_39 ( L_57 ,
F_157 ( V_179 ) , F_157 ( V_181 ) ) ;
else
F_39 ( L_58 ,
V_181 , V_179 , F_155 ( V_179 ) ) ;
#endif
F_8 ( V_2 , V_182 ) ;
}
void F_162 ( struct V_1 * V_2 )
{
int V_66 ;
F_163 (cpu)
F_164 ( V_2 -> V_9 , V_66 ) -> V_179 = F_158 ( V_66 ) ;
}
static void F_165 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
enum T_8 { V_183 , V_184 , V_185 , V_186 };
struct V_14 * V_14 = V_161 -> V_14 ;
struct V_12 * V_40 = F_12 ( V_2 , F_120 ( V_14 ) ) ;
int V_187 = 0 ;
enum T_8 V_188 = V_183 , V_189 = V_183 ;
void * V_44 ;
void * V_190 ;
int V_154 = V_191 ;
struct V_14 V_159 ;
struct V_14 V_192 ;
if ( V_14 -> V_44 ) {
F_8 ( V_2 , V_193 ) ;
V_154 = V_156 ;
}
V_161 -> V_179 = F_155 ( V_161 -> V_179 ) ;
V_161 -> V_14 = NULL ;
V_44 = V_161 -> V_44 ;
V_161 -> V_44 = NULL ;
while ( V_44 && ( V_190 = F_15 ( V_2 , V_44 ) ) ) {
void * V_194 ;
unsigned long V_45 ;
do {
V_194 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
F_21 ( V_2 , V_44 , V_194 ) ;
V_159 . V_45 = V_45 ;
V_159 . V_27 -- ;
F_33 ( ! V_159 . V_146 ) ;
} while ( ! F_32 ( V_2 , V_14 ,
V_194 , V_45 ,
V_44 , V_159 . V_45 ,
L_59 ) );
V_44 = V_190 ;
}
V_195:
V_192 . V_44 = V_14 -> V_44 ;
V_192 . V_45 = V_14 -> V_45 ;
F_33 ( ! V_192 . V_146 ) ;
V_159 . V_45 = V_192 . V_45 ;
if ( V_44 ) {
V_159 . V_27 -- ;
F_21 ( V_2 , V_44 , V_192 . V_44 ) ;
V_159 . V_44 = V_44 ;
} else
V_159 . V_44 = V_192 . V_44 ;
V_159 . V_146 = 0 ;
if ( ! V_159 . V_27 && V_40 -> V_155 > V_2 -> V_177 )
V_189 = V_186 ;
else if ( V_159 . V_44 ) {
V_189 = V_184 ;
if ( ! V_187 ) {
V_187 = 1 ;
F_138 ( & V_40 -> V_163 ) ;
}
} else {
V_189 = V_185 ;
if ( F_1 ( V_2 ) && ! V_187 ) {
V_187 = 1 ;
F_138 ( & V_40 -> V_163 ) ;
}
}
if ( V_188 != V_189 ) {
if ( V_188 == V_184 )
F_135 ( V_40 , V_14 ) ;
else if ( V_188 == V_185 )
F_89 ( V_2 , V_14 ) ;
if ( V_189 == V_184 ) {
F_133 ( V_40 , V_14 , V_154 ) ;
F_8 ( V_2 , V_154 ) ;
} else if ( V_189 == V_185 ) {
F_8 ( V_2 , V_196 ) ;
F_87 ( V_2 , V_40 , V_14 ) ;
}
}
V_188 = V_189 ;
if ( ! F_32 ( V_2 , V_14 ,
V_192 . V_44 , V_192 . V_45 ,
V_159 . V_44 , V_159 . V_45 ,
L_60 ) )
goto V_195;
if ( V_187 )
F_141 ( & V_40 -> V_163 ) ;
if ( V_189 == V_186 ) {
F_8 ( V_2 , V_197 ) ;
F_132 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_198 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_12 * V_40 = NULL ;
struct V_160 * V_161 = F_167 ( V_2 -> V_9 ) ;
struct V_14 * V_14 , * V_199 = NULL ;
while ( ( V_14 = V_161 -> V_157 ) ) {
enum T_8 { V_184 , V_186 };
enum T_8 V_188 , V_189 ;
struct V_14 V_159 ;
struct V_14 V_192 ;
V_161 -> V_157 = V_14 -> V_200 ;
V_188 = V_186 ;
do {
V_192 . V_44 = V_14 -> V_44 ;
V_192 . V_45 = V_14 -> V_45 ;
F_33 ( ! V_192 . V_146 ) ;
V_159 . V_45 = V_192 . V_45 ;
V_159 . V_44 = V_192 . V_44 ;
V_159 . V_146 = 0 ;
if ( ! V_159 . V_27 && ( ! V_40 || V_40 -> V_155 > V_2 -> V_177 ) )
V_189 = V_186 ;
else {
struct V_12 * V_201 = F_12 ( V_2 ,
F_120 ( V_14 ) ) ;
V_189 = V_184 ;
if ( V_40 != V_201 ) {
if ( V_40 )
F_141 ( & V_40 -> V_163 ) ;
V_40 = V_201 ;
F_138 ( & V_40 -> V_163 ) ;
}
}
if ( V_188 != V_189 ) {
if ( V_188 == V_184 ) {
F_135 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_202 ) ;
} else {
F_133 ( V_40 , V_14 ,
V_156 ) ;
F_8 ( V_2 , V_203 ) ;
}
V_188 = V_189 ;
}
} while ( ! F_40 ( V_2 , V_14 ,
V_192 . V_44 , V_192 . V_45 ,
V_159 . V_44 , V_159 . V_45 ,
L_60 ) );
if ( V_189 == V_186 ) {
V_14 -> V_200 = V_199 ;
V_199 = V_14 ;
}
}
if ( V_40 )
F_141 ( & V_40 -> V_163 ) ;
while ( V_199 ) {
V_14 = V_199 ;
V_199 = V_199 -> V_200 ;
F_8 ( V_2 , V_197 ) ;
F_132 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_198 ) ;
}
}
int F_140 ( struct V_1 * V_2 , struct V_14 * V_14 , int V_204 )
{
struct V_14 * V_205 ;
int V_137 ;
int V_206 ;
do {
V_137 = 0 ;
V_206 = 0 ;
V_205 = F_168 ( V_2 -> V_9 -> V_157 ) ;
if ( V_205 ) {
V_206 = V_205 -> V_206 ;
V_137 = V_205 -> V_137 ;
if ( V_204 && V_206 > V_2 -> V_167 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_166 ( V_2 ) ;
F_42 ( V_3 ) ;
V_206 = 0 ;
V_137 = 0 ;
F_8 ( V_2 , V_207 ) ;
}
}
V_137 ++ ;
V_206 += V_14 -> V_17 - V_14 -> V_27 ;
V_14 -> V_137 = V_137 ;
V_14 -> V_206 = V_206 ;
V_14 -> V_200 = V_205 ;
} while ( F_169 ( V_2 -> V_9 -> V_157 , V_205 , V_14 ) != V_205 );
return V_206 ;
}
static inline void F_170 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
F_8 ( V_2 , V_208 ) ;
F_165 ( V_2 , V_161 ) ;
}
static inline void F_171 ( struct V_1 * V_2 , int V_66 )
{
struct V_160 * V_161 = F_164 ( V_2 -> V_9 , V_66 ) ;
if ( F_172 ( V_161 ) ) {
if ( V_161 -> V_14 )
F_170 ( V_2 , V_161 ) ;
F_166 ( V_2 ) ;
}
}
static void F_173 ( void * V_209 )
{
struct V_1 * V_2 = V_209 ;
F_171 ( V_2 , F_51 () ) ;
}
static bool F_174 ( int V_66 , void * V_210 )
{
struct V_1 * V_2 = V_210 ;
struct V_160 * V_161 = F_164 ( V_2 -> V_9 , V_66 ) ;
return V_161 -> V_14 || V_161 -> V_157 ;
}
static void F_175 ( struct V_1 * V_2 )
{
F_176 ( F_174 , F_173 , V_2 , 1 , V_211 ) ;
}
static inline int F_177 ( struct V_160 * V_161 , int V_13 )
{
#ifdef F_143
if ( V_13 != V_127 && V_161 -> V_13 != V_13 )
return 0 ;
#endif
return 1 ;
}
static int F_178 ( struct V_14 * V_14 )
{
return V_14 -> V_17 - V_14 -> V_27 ;
}
static unsigned long F_179 ( struct V_12 * V_40 ,
int (* F_180)( struct V_14 * ) )
{
unsigned long V_3 ;
unsigned long V_32 = 0 ;
struct V_14 * V_14 ;
F_181 ( & V_40 -> V_163 , V_3 ) ;
F_182 (page, &n->partial, lru)
V_32 += F_180 ( V_14 ) ;
F_183 ( & V_40 -> V_163 , V_3 ) ;
return V_32 ;
}
static inline unsigned long F_184 ( struct V_12 * V_40 )
{
#ifdef F_2
return F_92 ( & V_40 -> V_110 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_185 ( struct V_1 * V_2 , T_5 V_212 , int V_213 )
{
int V_13 ;
F_39 ( V_214
L_61 ,
V_213 , V_212 ) ;
F_39 ( V_214 L_62
L_63 , V_2 -> V_6 , V_2 -> V_24 ,
V_2 -> V_18 , F_26 ( V_2 -> V_125 ) , F_26 ( V_2 -> V_133 ) ) ;
if ( F_26 ( V_2 -> V_133 ) > F_186 ( V_2 -> V_24 ) )
F_39 ( V_214 L_64
L_65 , V_2 -> V_6 ) ;
F_187 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_109 ;
unsigned long V_215 ;
unsigned long V_216 ;
if ( ! V_40 )
continue;
V_216 = F_179 ( V_40 , F_178 ) ;
V_109 = F_93 ( V_40 ) ;
V_215 = F_184 ( V_40 ) ;
F_39 ( V_214
L_66 ,
V_13 , V_109 , V_215 , V_216 ) ;
}
}
static inline void * F_188 ( struct V_1 * V_2 , T_5 V_3 ,
int V_13 , struct V_160 * * V_217 )
{
void * V_15 ;
struct V_160 * V_161 ;
struct V_14 * V_14 = F_118 ( V_2 , V_3 , V_13 ) ;
if ( V_14 ) {
V_161 = F_189 ( V_2 -> V_9 ) ;
if ( V_161 -> V_14 )
F_170 ( V_2 , V_161 ) ;
V_15 = V_14 -> V_44 ;
V_14 -> V_44 = NULL ;
F_8 ( V_2 , V_218 ) ;
V_161 -> V_13 = F_120 ( V_14 ) ;
V_161 -> V_14 = V_14 ;
* V_217 = V_161 ;
} else
V_15 = NULL ;
return V_15 ;
}
static inline void * F_190 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_14 V_159 ;
unsigned long V_45 ;
void * V_44 ;
do {
V_44 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
V_159 . V_45 = V_45 ;
F_33 ( ! V_159 . V_146 ) ;
V_159 . V_27 = V_14 -> V_17 ;
V_159 . V_146 = V_44 != NULL ;
} while ( ! F_40 ( V_2 , V_14 ,
V_44 , V_45 ,
NULL , V_159 . V_45 ,
L_67 ) );
return V_44 ;
}
static void * F_191 ( struct V_1 * V_2 , T_5 V_212 , int V_13 ,
unsigned long V_21 , struct V_160 * V_161 )
{
void * * V_15 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_161
V_161 = F_167 ( V_2 -> V_9 ) ;
#endif
if ( ! V_161 -> V_14 )
goto F_118;
V_195:
if ( F_3 ( ! F_177 ( V_161 , V_13 ) ) ) {
F_8 ( V_2 , V_219 ) ;
F_165 ( V_2 , V_161 ) ;
goto F_118;
}
V_15 = V_161 -> V_44 ;
if ( V_15 )
goto V_220;
F_8 ( V_2 , V_221 ) ;
V_15 = F_190 ( V_2 , V_161 -> V_14 ) ;
if ( ! V_15 ) {
V_161 -> V_14 = NULL ;
F_8 ( V_2 , V_222 ) ;
goto F_118;
}
F_8 ( V_2 , V_223 ) ;
V_220:
V_161 -> V_44 = F_15 ( V_2 , V_15 ) ;
V_161 -> V_179 = F_155 ( V_161 -> V_179 ) ;
F_42 ( V_3 ) ;
return V_15 ;
F_118:
if ( V_161 -> V_157 ) {
V_161 -> V_14 = V_161 -> V_157 ;
V_161 -> V_157 = V_161 -> V_14 -> V_200 ;
V_161 -> V_13 = F_120 ( V_161 -> V_14 ) ;
F_8 ( V_2 , V_224 ) ;
V_161 -> V_44 = NULL ;
goto V_195;
}
V_15 = F_153 ( V_2 , V_212 , V_13 , V_161 ) ;
if ( F_3 ( ! V_15 ) ) {
V_15 = F_188 ( V_2 , V_212 , V_13 , & V_161 ) ;
if ( F_3 ( ! V_15 ) ) {
if ( ! ( V_212 & V_130 ) && F_192 () )
F_185 ( V_2 , V_212 , V_13 ) ;
F_42 ( V_3 ) ;
return NULL ;
}
}
if ( F_172 ( ! F_1 ( V_2 ) ) )
goto V_220;
if ( ! F_101 ( V_2 , V_161 -> V_14 , V_15 , V_21 ) )
goto F_118;
V_161 -> V_44 = F_15 ( V_2 , V_15 ) ;
F_165 ( V_2 , V_161 ) ;
V_161 -> V_13 = V_127 ;
F_42 ( V_3 ) ;
return V_15 ;
}
static T_2 void * F_193 ( struct V_1 * V_2 ,
T_5 V_212 , int V_13 , unsigned long V_21 )
{
void * * V_15 ;
struct V_160 * V_161 ;
unsigned long V_179 ;
if ( F_75 ( V_2 , V_212 ) )
return NULL ;
V_195:
V_161 = F_189 ( V_2 -> V_9 ) ;
V_179 = V_161 -> V_179 ;
F_194 () ;
V_15 = V_161 -> V_44 ;
if ( F_3 ( ! V_15 || ! F_177 ( V_161 , V_13 ) ) )
V_15 = F_191 ( V_2 , V_212 , V_13 , V_21 , V_161 ) ;
else {
void * V_225 = F_18 ( V_2 , V_15 ) ;
if ( F_3 ( ! F_195 (
V_2 -> V_9 -> V_44 , V_2 -> V_9 -> V_179 ,
V_15 , V_179 ,
V_225 , F_155 ( V_179 ) ) ) ) {
F_159 ( L_68 , V_2 , V_179 ) ;
goto V_195;
}
F_16 ( V_2 , V_225 ) ;
F_8 ( V_2 , V_226 ) ;
}
if ( F_3 ( V_212 & V_227 ) && V_15 )
memset ( V_15 , 0 , V_2 -> V_24 ) ;
F_79 ( V_2 , V_212 , V_15 ) ;
return V_15 ;
}
void * F_196 ( struct V_1 * V_2 , T_5 V_212 )
{
void * V_228 = F_193 ( V_2 , V_212 , V_127 , V_229 ) ;
F_197 ( V_229 , V_228 , V_2 -> V_24 , V_2 -> V_18 , V_212 ) ;
return V_228 ;
}
void * F_198 ( struct V_1 * V_2 , T_5 V_212 , T_1 V_18 )
{
void * V_228 = F_193 ( V_2 , V_212 , V_127 , V_229 ) ;
F_199 ( V_229 , V_228 , V_18 , V_2 -> V_18 , V_212 ) ;
return V_228 ;
}
void * F_200 ( T_1 V_18 , T_5 V_3 , unsigned int V_28 )
{
void * V_228 = F_201 ( V_18 , V_3 , V_28 ) ;
F_199 ( V_229 , V_228 , V_18 , V_30 << V_28 , V_3 ) ;
return V_228 ;
}
void * F_202 ( struct V_1 * V_2 , T_5 V_212 , int V_13 )
{
void * V_228 = F_193 ( V_2 , V_212 , V_13 , V_229 ) ;
F_203 ( V_229 , V_228 ,
V_2 -> V_24 , V_2 -> V_18 , V_212 , V_13 ) ;
return V_228 ;
}
void * F_204 ( struct V_1 * V_2 ,
T_5 V_212 ,
int V_13 , T_1 V_18 )
{
void * V_228 = F_193 ( V_2 , V_212 , V_13 , V_229 ) ;
F_205 ( V_229 , V_228 ,
V_18 , V_2 -> V_18 , V_212 , V_13 ) ;
return V_228 ;
}
static void F_206 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_32 , unsigned long V_21 )
{
void * V_194 ;
void * * V_15 = ( void * ) V_32 ;
int V_230 ;
int V_27 ;
struct V_14 V_159 ;
unsigned long V_45 ;
struct V_12 * V_40 = NULL ;
unsigned long V_231 ( V_3 ) ;
F_8 ( V_2 , V_232 ) ;
if ( F_1 ( V_2 ) && ! F_102 ( V_2 , V_14 , V_32 , V_21 ) )
return;
do {
V_194 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
F_21 ( V_2 , V_15 , V_194 ) ;
V_159 . V_45 = V_45 ;
V_230 = V_159 . V_146 ;
V_159 . V_27 -- ;
if ( ( ! V_159 . V_27 || ! V_194 ) && ! V_230 && ! V_40 ) {
if ( ! F_1 ( V_2 ) && ! V_194 )
V_159 . V_146 = 1 ;
else {
V_40 = F_12 ( V_2 , F_120 ( V_14 ) ) ;
F_181 ( & V_40 -> V_163 , V_3 ) ;
}
}
V_27 = V_159 . V_27 ;
} while ( ! F_40 ( V_2 , V_14 ,
V_194 , V_45 ,
V_15 , V_159 . V_45 ,
L_69 ) );
if ( F_172 ( ! V_40 ) ) {
if ( V_159 . V_146 && ! V_230 ) {
F_140 ( V_2 , V_14 , 1 ) ;
F_8 ( V_2 , V_233 ) ;
}
if ( V_230 )
F_8 ( V_2 , V_234 ) ;
return;
}
if ( V_230 )
F_8 ( V_2 , V_234 ) ;
else {
if ( F_3 ( ! V_27 && V_40 -> V_155 > V_2 -> V_177 ) )
goto V_235;
if ( F_3 ( ! V_194 ) ) {
F_89 ( V_2 , V_14 ) ;
F_133 ( V_40 , V_14 , V_156 ) ;
F_8 ( V_2 , V_203 ) ;
}
}
F_183 ( & V_40 -> V_163 , V_3 ) ;
return;
V_235:
if ( V_194 ) {
F_135 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_202 ) ;
} else
F_89 ( V_2 , V_14 ) ;
F_183 ( & V_40 -> V_163 , V_3 ) ;
F_8 ( V_2 , V_198 ) ;
F_132 ( V_2 , V_14 ) ;
}
static T_2 void F_207 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_32 , unsigned long V_21 )
{
void * * V_15 = ( void * ) V_32 ;
struct V_160 * V_161 ;
unsigned long V_179 ;
F_82 ( V_2 , V_32 ) ;
V_195:
V_161 = F_189 ( V_2 -> V_9 ) ;
V_179 = V_161 -> V_179 ;
F_194 () ;
if ( F_172 ( V_14 == V_161 -> V_14 ) ) {
F_21 ( V_2 , V_15 , V_161 -> V_44 ) ;
if ( F_3 ( ! F_195 (
V_2 -> V_9 -> V_44 , V_2 -> V_9 -> V_179 ,
V_161 -> V_44 , V_179 ,
V_15 , F_155 ( V_179 ) ) ) ) {
F_159 ( L_70 , V_2 , V_179 ) ;
goto V_195;
}
F_8 ( V_2 , V_236 ) ;
} else
F_206 ( V_2 , V_14 , V_32 , V_21 ) ;
}
void F_208 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_14 ;
V_14 = F_128 ( V_32 ) ;
F_207 ( V_2 , V_14 , V_32 , V_229 ) ;
F_209 ( V_229 , V_32 ) ;
}
static inline int F_210 ( int V_18 , int V_237 ,
int V_238 , int V_239 , int V_29 )
{
int V_28 ;
int V_240 ;
int V_241 = V_242 ;
if ( F_24 ( V_241 , V_18 , V_29 ) > V_100 )
return F_186 ( V_18 * V_100 ) - 1 ;
for ( V_28 = F_211 ( V_241 ,
F_212 ( V_237 * V_18 - 1 ) - V_243 ) ;
V_28 <= V_238 ; V_28 ++ ) {
unsigned long V_244 = V_30 << V_28 ;
if ( V_244 < V_237 * V_18 + V_29 )
continue;
V_240 = ( V_244 - V_29 ) % V_18 ;
if ( V_240 <= V_244 / V_239 )
break;
}
return V_28 ;
}
static inline int F_213 ( int V_18 , int V_29 )
{
int V_28 ;
int V_237 ;
int V_245 ;
int V_99 ;
V_237 = V_246 ;
if ( ! V_237 )
V_237 = 4 * ( F_212 ( V_247 ) + 1 ) ;
V_99 = F_24 ( V_248 , V_18 , V_29 ) ;
V_237 = V_133 ( V_237 , V_99 ) ;
while ( V_237 > 1 ) {
V_245 = 16 ;
while ( V_245 >= 4 ) {
V_28 = F_210 ( V_18 , V_237 ,
V_248 , V_245 , V_29 ) ;
if ( V_28 <= V_248 )
return V_28 ;
V_245 /= 2 ;
}
V_237 -- ;
}
V_28 = F_210 ( V_18 , 1 , V_248 , 1 , V_29 ) ;
if ( V_28 <= V_248 )
return V_28 ;
V_28 = F_210 ( V_18 , 1 , V_249 , 1 , V_29 ) ;
if ( V_28 < V_249 )
return V_28 ;
return - V_250 ;
}
static unsigned long F_214 ( unsigned long V_3 ,
unsigned long V_251 , unsigned long V_18 )
{
if ( V_3 & V_252 ) {
unsigned long V_253 = F_215 () ;
while ( V_18 <= V_253 / 2 )
V_253 /= 2 ;
V_251 = F_211 ( V_251 , V_253 ) ;
}
if ( V_251 < V_254 )
V_251 = V_254 ;
return F_216 ( V_251 , sizeof( void * ) ) ;
}
static void
F_217 ( struct V_12 * V_40 , struct V_1 * V_2 )
{
V_40 -> V_155 = 0 ;
F_218 ( & V_40 -> V_163 ) ;
F_219 ( & V_40 -> V_157 ) ;
#ifdef F_2
F_220 ( & V_40 -> V_109 , 0 ) ;
F_220 ( & V_40 -> V_110 , 0 ) ;
F_219 ( & V_40 -> V_108 ) ;
#endif
}
static inline int F_221 ( struct V_1 * V_2 )
{
F_222 ( V_255 <
V_256 * sizeof( struct V_160 ) ) ;
V_2 -> V_9 = F_223 ( sizeof( struct V_160 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_162 ( V_2 ) ;
return 1 ;
}
static void F_224 ( int V_13 )
{
struct V_14 * V_14 ;
struct V_12 * V_40 ;
F_119 ( V_12 -> V_18 < sizeof( struct V_12 ) ) ;
V_14 = F_118 ( V_12 , V_257 , V_13 ) ;
F_119 ( ! V_14 ) ;
if ( F_120 ( V_14 ) != V_13 ) {
F_39 ( V_51 L_71
L_72 , V_13 ) ;
F_39 ( V_51 L_73
L_74 ) ;
}
V_40 = V_14 -> V_44 ;
F_119 ( ! V_40 ) ;
V_14 -> V_44 = F_15 ( V_12 , V_40 ) ;
V_14 -> V_27 = 1 ;
V_14 -> V_146 = 0 ;
V_12 -> V_13 [ V_13 ] = V_40 ;
#ifdef F_2
F_64 ( V_12 , V_40 , V_95 ) ;
F_52 ( V_12 , V_40 ) ;
#endif
F_217 ( V_40 , V_12 ) ;
F_94 ( V_12 , V_13 , V_14 -> V_17 ) ;
F_133 ( V_40 , V_14 , V_191 ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
int V_13 ;
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = V_2 -> V_13 [ V_13 ] ;
if ( V_40 )
F_208 ( V_12 , V_40 ) ;
V_2 -> V_13 [ V_13 ] = NULL ;
}
}
static int F_227 ( struct V_1 * V_2 )
{
int V_13 ;
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 ;
if ( V_10 == V_258 ) {
F_224 ( V_13 ) ;
continue;
}
V_40 = F_202 ( V_12 ,
V_259 , V_13 ) ;
if ( ! V_40 ) {
F_225 ( V_2 ) ;
return 0 ;
}
V_2 -> V_13 [ V_13 ] = V_40 ;
F_217 ( V_40 , V_2 ) ;
}
return 1 ;
}
static void F_228 ( struct V_1 * V_2 , unsigned long V_133 )
{
if ( V_133 < V_260 )
V_133 = V_260 ;
else if ( V_133 > V_261 )
V_133 = V_261 ;
V_2 -> V_177 = V_133 ;
}
static int F_229 ( struct V_1 * V_2 , int V_262 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_18 = V_2 -> V_24 ;
unsigned long V_251 = V_2 -> V_251 ;
int V_28 ;
V_18 = F_216 ( V_18 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_23 ) && ! ( V_3 & V_25 ) &&
! V_2 -> F_105 )
V_2 -> V_3 |= V_79 ;
else
V_2 -> V_3 &= ~ V_79 ;
if ( ( V_3 & V_22 ) && V_18 == V_2 -> V_24 )
V_18 += sizeof( void * ) ;
#endif
V_2 -> V_27 = V_18 ;
if ( ( ( V_3 & ( V_25 | V_23 ) ) ||
V_2 -> F_105 ) ) {
V_2 -> V_19 = V_18 ;
V_18 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_26 )
V_18 += 2 * sizeof( struct V_53 ) ;
if ( V_3 & V_22 )
V_18 += sizeof( void * ) ;
#endif
V_251 = F_214 ( V_3 , V_251 , V_2 -> V_24 ) ;
V_2 -> V_251 = V_251 ;
V_18 = F_216 ( V_18 , V_251 ) ;
V_2 -> V_18 = V_18 ;
if ( V_262 >= 0 )
V_28 = V_262 ;
else
V_28 = F_213 ( V_18 , V_2 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
V_2 -> V_129 = 0 ;
if ( V_28 )
V_2 -> V_129 |= V_263 ;
if ( V_2 -> V_3 & V_264 )
V_2 -> V_129 |= V_265 ;
if ( V_2 -> V_3 & V_138 )
V_2 -> V_129 |= V_266 ;
V_2 -> V_125 = F_25 ( V_28 , V_18 , V_2 -> V_29 ) ;
V_2 -> V_133 = F_25 ( F_186 ( V_18 ) , V_18 , V_2 -> V_29 ) ;
if ( F_27 ( V_2 -> V_125 ) > F_27 ( V_2 -> F_211 ) )
V_2 -> F_211 = V_2 -> V_125 ;
return ! ! F_27 ( V_2 -> V_125 ) ;
}
static int F_230 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_18 ,
T_1 V_251 , unsigned long V_3 ,
void (* F_105)( void * ) )
{
memset ( V_2 , 0 , V_267 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_105 = F_105 ;
V_2 -> V_24 = V_18 ;
V_2 -> V_251 = V_251 ;
V_2 -> V_3 = F_104 ( V_18 , V_3 , V_6 , F_105 ) ;
V_2 -> V_29 = 0 ;
if ( V_151 && ( V_2 -> V_3 & V_25 ) )
V_2 -> V_29 = sizeof( struct V_149 ) ;
if ( ! F_229 ( V_2 , - 1 ) )
goto error;
if ( V_121 ) {
if ( F_186 ( V_2 -> V_18 ) > F_186 ( V_2 -> V_24 ) ) {
V_2 -> V_3 &= ~ V_268 ;
V_2 -> V_19 = 0 ;
if ( ! F_229 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_41 ) && \
F_35 ( V_42 )
if ( F_231 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_43 ;
#endif
F_228 ( V_2 , F_232 ( V_2 -> V_18 ) / 2 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_167 = 0 ;
else if ( V_2 -> V_18 >= V_30 )
V_2 -> V_167 = 2 ;
else if ( V_2 -> V_18 >= 1024 )
V_2 -> V_167 = 6 ;
else if ( V_2 -> V_18 >= 256 )
V_2 -> V_167 = 13 ;
else
V_2 -> V_167 = 30 ;
V_2 -> V_269 = 1 ;
#ifdef F_143
V_2 -> V_175 = 1000 ;
#endif
if ( ! F_227 ( V_2 ) )
goto error;
if ( F_221 ( V_2 ) )
return 1 ;
F_225 ( V_2 ) ;
error:
if ( V_3 & V_270 )
F_233 ( L_75
L_76 ,
V_2 -> V_6 , ( unsigned long ) V_18 , V_2 -> V_18 , F_26 ( V_2 -> V_125 ) ,
V_2 -> V_19 , V_3 ) ;
return 0 ;
}
unsigned int F_234 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
static void F_235 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const char * V_49 )
{
#ifdef F_2
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
unsigned long * V_48 = F_236 ( F_237 ( V_14 -> V_17 ) *
sizeof( long ) , V_211 ) ;
if ( ! V_48 )
return;
F_63 ( V_2 , V_14 , L_18 , V_49 ) ;
F_28 ( V_14 ) ;
F_43 ( V_2 , V_14 , V_48 ) ;
F_121 (p, s, addr, page->objects) {
if ( ! F_238 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) ) {
F_39 ( V_51 L_77 ,
V_5 , V_5 - V_21 ) ;
F_54 ( V_2 , V_5 ) ;
}
}
F_30 ( V_14 ) ;
F_7 ( V_48 ) ;
#endif
}
static void F_239 ( struct V_1 * V_2 , struct V_12 * V_40 )
{
struct V_14 * V_14 , * V_150 ;
F_139 (page, h, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_135 ( V_40 , V_14 ) ;
F_132 ( V_2 , V_14 ) ;
} else {
F_235 ( V_2 , V_14 ,
L_78 ) ;
}
}
}
static inline int F_240 ( struct V_1 * V_2 )
{
int V_13 ;
F_175 ( V_2 ) ;
F_241 ( V_2 -> V_9 ) ;
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_239 ( V_2 , V_40 ) ;
if ( V_40 -> V_155 || F_91 ( V_2 , V_13 ) )
return 1 ;
}
F_225 ( V_2 ) ;
return 0 ;
}
void F_242 ( struct V_1 * V_2 )
{
F_243 ( & V_271 ) ;
V_2 -> V_269 -- ;
if ( ! V_2 -> V_269 ) {
F_90 ( & V_2 -> V_272 ) ;
F_244 ( & V_271 ) ;
if ( F_240 ( V_2 ) ) {
F_39 ( V_51 L_79
L_80 , V_2 -> V_6 , V_273 ) ;
F_61 () ;
}
if ( V_2 -> V_3 & V_25 )
F_245 () ;
F_6 ( V_2 ) ;
} else
F_244 ( & V_271 ) ;
}
static int T_7 F_246 ( char * V_117 )
{
F_247 ( & V_117 , & V_242 ) ;
return 1 ;
}
static int T_7 F_248 ( char * V_117 )
{
F_247 ( & V_117 , & V_248 ) ;
V_248 = V_133 ( V_248 , V_249 - 1 ) ;
return 1 ;
}
static int T_7 F_249 ( char * V_117 )
{
F_247 ( & V_117 , & V_246 ) ;
return 1 ;
}
static int T_7 F_250 ( char * V_117 )
{
V_274 = 1 ;
return 1 ;
}
static struct V_1 * T_7 F_251 ( const char * V_6 ,
int V_18 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_196 ( V_1 , V_257 ) ;
if ( ! F_230 ( V_2 , V_6 , V_18 , V_275 ,
V_3 , NULL ) )
goto F_233;
F_88 ( & V_2 -> V_272 , & V_276 ) ;
return V_2 ;
F_233:
F_233 ( L_81 , V_6 , V_18 ) ;
return NULL ;
}
static inline int F_252 ( T_1 V_89 )
{
return ( V_89 - 1 ) / 8 ;
}
static struct V_1 * F_253 ( T_1 V_18 , T_5 V_3 )
{
int V_277 ;
if ( V_18 <= 192 ) {
if ( ! V_18 )
return V_278 ;
V_277 = V_279 [ F_252 ( V_18 ) ] ;
} else
V_277 = F_212 ( V_18 - 1 ) ;
#ifdef F_254
if ( F_3 ( ( V_3 & V_265 ) ) )
return V_280 [ V_277 ] ;
#endif
return V_281 [ V_277 ] ;
}
void * F_255 ( T_1 V_18 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_228 ;
if ( F_3 ( V_18 > V_282 ) )
return F_256 ( V_18 , V_3 ) ;
V_2 = F_253 ( V_18 , V_3 ) ;
if ( F_3 ( F_257 ( V_2 ) ) )
return V_2 ;
V_228 = F_193 ( V_2 , V_3 , V_127 , V_229 ) ;
F_199 ( V_229 , V_228 , V_18 , V_2 -> V_18 , V_3 ) ;
return V_228 ;
}
static void * F_258 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_283 = NULL ;
V_3 |= V_263 | V_126 ;
V_14 = F_259 ( V_13 , V_3 , F_186 ( V_18 ) ) ;
if ( V_14 )
V_283 = F_14 ( V_14 ) ;
F_260 ( V_283 , V_18 , 1 , V_3 ) ;
return V_283 ;
}
void * F_261 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_1 * V_2 ;
void * V_228 ;
if ( F_3 ( V_18 > V_282 ) ) {
V_228 = F_258 ( V_18 , V_3 , V_13 ) ;
F_205 ( V_229 , V_228 ,
V_18 , V_30 << F_186 ( V_18 ) ,
V_3 , V_13 ) ;
return V_228 ;
}
V_2 = F_253 ( V_18 , V_3 ) ;
if ( F_3 ( F_257 ( V_2 ) ) )
return V_2 ;
V_228 = F_193 ( V_2 , V_3 , V_13 , V_229 ) ;
F_205 ( V_229 , V_228 , V_18 , V_2 -> V_18 , V_3 , V_13 ) ;
return V_228 ;
}
T_1 F_262 ( const void * V_15 )
{
struct V_14 * V_14 ;
if ( F_3 ( V_15 == V_278 ) )
return 0 ;
V_14 = F_128 ( V_15 ) ;
if ( F_3 ( ! F_73 ( V_14 ) ) ) {
F_263 ( ! F_264 ( V_14 ) ) ;
return V_30 << F_70 ( V_14 ) ;
}
return F_23 ( V_14 -> V_116 ) ;
}
bool F_265 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
unsigned long V_3 ;
bool V_284 ;
if ( F_3 ( F_257 ( V_32 ) ) )
return false ;
F_41 ( V_3 ) ;
V_14 = F_128 ( V_32 ) ;
if ( F_3 ( ! F_73 ( V_14 ) ) ) {
V_284 = true ;
goto V_285;
}
F_28 ( V_14 ) ;
if ( F_74 ( V_14 -> V_116 , V_14 , V_15 ) ) {
F_62 ( V_14 -> V_116 , V_14 , V_15 , L_82 ) ;
V_284 = false ;
} else {
V_284 = true ;
}
F_30 ( V_14 ) ;
V_285:
F_42 ( V_3 ) ;
return V_284 ;
}
void F_7 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
F_266 ( V_229 , V_32 ) ;
if ( F_3 ( F_257 ( V_32 ) ) )
return;
V_14 = F_128 ( V_32 ) ;
if ( F_3 ( ! F_73 ( V_14 ) ) ) {
F_119 ( ! F_264 ( V_14 ) ) ;
F_267 ( V_32 ) ;
F_268 ( V_14 ) ;
return;
}
F_207 ( V_14 -> V_116 , V_14 , V_15 , V_229 ) ;
}
int F_269 ( struct V_1 * V_2 )
{
int V_13 ;
int V_58 ;
struct V_12 * V_40 ;
struct V_14 * V_14 ;
struct V_14 * V_73 ;
int V_17 = F_27 ( V_2 -> F_211 ) ;
struct V_152 * V_286 =
F_270 ( sizeof( struct V_152 ) * V_17 , V_259 ) ;
unsigned long V_3 ;
if ( ! V_286 )
return - V_287 ;
F_175 ( V_2 ) ;
F_226 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 -> V_155 )
continue;
for ( V_58 = 0 ; V_58 < V_17 ; V_58 ++ )
F_219 ( V_286 + V_58 ) ;
F_181 ( & V_40 -> V_163 , V_3 ) ;
F_139 (page, t, &n->partial, lru) {
F_271 ( & V_14 -> V_107 , V_286 + V_14 -> V_27 ) ;
if ( ! V_14 -> V_27 )
V_40 -> V_155 -- ;
}
for ( V_58 = V_17 - 1 ; V_58 > 0 ; V_58 -- )
F_272 ( V_286 + V_58 , V_40 -> V_157 . V_288 ) ;
F_183 ( & V_40 -> V_163 , V_3 ) ;
F_139 (page, t, slabs_by_inuse, lru)
F_132 ( V_2 , V_14 ) ;
}
F_7 ( V_286 ) ;
return 0 ;
}
static int F_273 ( void * V_289 )
{
struct V_1 * V_2 ;
F_274 ( & V_271 ) ;
F_182 (s, &slab_caches, list)
F_269 ( V_2 ) ;
F_275 ( & V_271 ) ;
return 0 ;
}
static void F_276 ( void * V_289 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_290 * V_291 = V_289 ;
int V_292 ;
V_292 = V_291 -> V_293 ;
if ( V_292 < 0 )
return;
F_274 ( & V_271 ) ;
F_182 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_292 ) ;
if ( V_40 ) {
F_119 ( F_91 ( V_2 , V_292 ) ) ;
V_2 -> V_13 [ V_292 ] = NULL ;
F_208 ( V_12 , V_40 ) ;
}
}
F_275 ( & V_271 ) ;
}
static int F_277 ( void * V_289 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_290 * V_291 = V_289 ;
int V_213 = V_291 -> V_293 ;
int V_228 = 0 ;
if ( V_213 < 0 )
return 0 ;
F_274 ( & V_271 ) ;
F_182 (s, &slab_caches, list) {
V_40 = F_196 ( V_12 , V_259 ) ;
if ( ! V_40 ) {
V_228 = - V_287 ;
goto V_115;
}
F_217 ( V_40 , V_2 ) ;
V_2 -> V_13 [ V_213 ] = V_40 ;
}
V_115:
F_275 ( & V_271 ) ;
return V_228 ;
}
static int F_278 ( struct V_294 * V_295 ,
unsigned long V_296 , void * V_289 )
{
int V_228 = 0 ;
switch ( V_296 ) {
case V_297 :
V_228 = F_277 ( V_289 ) ;
break;
case V_298 :
V_228 = F_273 ( V_289 ) ;
break;
case V_299 :
case V_300 :
F_276 ( V_289 ) ;
break;
case V_301 :
case V_302 :
break;
}
if ( V_228 )
V_228 = F_279 ( V_228 ) ;
else
V_228 = V_303 ;
return V_228 ;
}
static void T_7 F_280 ( struct V_1 * V_2 )
{
int V_13 ;
F_88 ( & V_2 -> V_272 , & V_276 ) ;
V_2 -> V_269 = - 1 ;
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
struct V_14 * V_5 ;
if ( V_40 ) {
F_182 (p, &n->partial, lru)
V_5 -> V_116 = V_2 ;
#ifdef F_2
F_182 (p, &n->full, lru)
V_5 -> V_116 = V_2 ;
#endif
}
}
}
void T_7 F_281 ( void )
{
int V_58 ;
int V_304 = 0 ;
struct V_1 * V_305 ;
int V_28 ;
struct V_1 * V_306 ;
unsigned long V_307 ;
if ( F_282 () )
V_248 = 0 ;
V_267 = F_283 ( struct V_1 , V_13 ) +
V_308 * sizeof( struct V_12 * ) ;
V_307 = F_216 ( V_267 , F_215 () ) ;
V_28 = F_186 ( 2 * V_307 ) ;
V_1 = ( void * ) F_284 ( V_257 , V_28 ) ;
V_12 = ( void * ) V_1 + V_307 ;
F_230 ( V_12 , L_83 ,
sizeof( struct V_12 ) ,
0 , V_252 | V_270 , NULL ) ;
F_285 ( F_278 , V_309 ) ;
V_10 = V_310 ;
V_305 = V_1 ;
F_230 ( V_1 , L_84 , V_267 ,
0 , V_252 | V_270 , NULL ) ;
V_1 = F_196 ( V_1 , V_257 ) ;
memcpy ( V_1 , V_305 , V_267 ) ;
V_306 = V_12 ;
V_12 = F_196 ( V_1 , V_257 ) ;
memcpy ( V_12 , V_306 , V_267 ) ;
F_280 ( V_12 ) ;
V_304 ++ ;
F_280 ( V_1 ) ;
V_304 ++ ;
F_286 ( ( unsigned long ) V_305 , V_28 ) ;
F_222 ( V_311 > 256 ||
( V_311 & ( V_311 - 1 ) ) ) ;
for ( V_58 = 8 ; V_58 < V_311 ; V_58 += 8 ) {
int V_312 = F_252 ( V_58 ) ;
if ( V_312 >= F_287 ( V_279 ) )
break;
V_279 [ V_312 ] = V_313 ;
}
if ( V_311 == 64 ) {
for ( V_58 = 64 + 8 ; V_58 <= 96 ; V_58 += 8 )
V_279 [ F_252 ( V_58 ) ] = 7 ;
} else if ( V_311 == 128 ) {
for ( V_58 = 128 + 8 ; V_58 <= 192 ; V_58 += 8 )
V_279 [ F_252 ( V_58 ) ] = 8 ;
}
if ( V_311 <= 32 ) {
V_281 [ 1 ] = F_251 ( L_85 , 96 , 0 ) ;
V_304 ++ ;
}
if ( V_311 <= 64 ) {
V_281 [ 2 ] = F_251 ( L_86 , 192 , 0 ) ;
V_304 ++ ;
}
for ( V_58 = V_313 ; V_58 < V_256 ; V_58 ++ ) {
V_281 [ V_58 ] = F_251 ( L_87 , 1 << V_58 , 0 ) ;
V_304 ++ ;
}
V_10 = V_11 ;
if ( V_311 <= 32 ) {
V_281 [ 1 ] -> V_6 = F_288 ( V_281 [ 1 ] -> V_6 , V_257 ) ;
F_119 ( ! V_281 [ 1 ] -> V_6 ) ;
}
if ( V_311 <= 64 ) {
V_281 [ 2 ] -> V_6 = F_288 ( V_281 [ 2 ] -> V_6 , V_257 ) ;
F_119 ( ! V_281 [ 2 ] -> V_6 ) ;
}
for ( V_58 = V_313 ; V_58 < V_256 ; V_58 ++ ) {
char * V_2 = F_289 ( V_257 , L_88 , 1 << V_58 ) ;
F_119 ( ! V_2 ) ;
V_281 [ V_58 ] -> V_6 = V_2 ;
}
#ifdef F_290
F_291 ( & V_314 ) ;
#endif
#ifdef F_254
for ( V_58 = 0 ; V_58 < V_256 ; V_58 ++ ) {
struct V_1 * V_2 = V_281 [ V_58 ] ;
if ( V_2 && V_2 -> V_18 ) {
char * V_6 = F_289 ( V_257 ,
L_89 , V_2 -> V_24 ) ;
F_119 ( ! V_6 ) ;
V_280 [ V_58 ] = F_251 ( V_6 ,
V_2 -> V_24 , V_264 ) ;
}
}
#endif
F_39 ( V_47
L_90
L_91 ,
V_304 , F_215 () ,
V_242 , V_248 , V_246 ,
V_247 , V_308 ) ;
}
void T_7 F_292 ( void )
{
}
static int F_293 ( struct V_1 * V_2 )
{
if ( V_274 || ( V_2 -> V_3 & V_315 ) )
return 1 ;
if ( V_2 -> F_105 )
return 1 ;
if ( V_2 -> V_269 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_294 ( T_1 V_18 ,
T_1 V_251 , unsigned long V_3 , const char * V_6 ,
void (* F_105)( void * ) )
{
struct V_1 * V_2 ;
if ( V_274 || ( V_3 & V_315 ) )
return NULL ;
if ( F_105 )
return NULL ;
V_18 = F_216 ( V_18 , sizeof( void * ) ) ;
V_251 = F_214 ( V_3 , V_251 , V_18 ) ;
V_18 = F_216 ( V_18 , V_251 ) ;
V_3 = F_104 ( V_18 , V_3 , V_6 , NULL ) ;
F_182 (s, &slab_caches, list) {
if ( F_293 ( V_2 ) )
continue;
if ( V_18 > V_2 -> V_18 )
continue;
if ( ( V_3 & V_316 ) != ( V_2 -> V_3 & V_316 ) )
continue;
if ( ( V_2 -> V_18 & ~ ( V_251 - 1 ) ) != V_2 -> V_18 )
continue;
if ( V_2 -> V_18 - V_18 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_295 ( const char * V_6 , T_1 V_18 ,
T_1 V_251 , unsigned long V_3 , void (* F_105)( void * ) )
{
struct V_1 * V_2 ;
char * V_40 ;
if ( F_263 ( ! V_6 ) )
return NULL ;
F_243 ( & V_271 ) ;
V_2 = F_294 ( V_18 , V_251 , V_3 , V_6 , F_105 ) ;
if ( V_2 ) {
V_2 -> V_269 ++ ;
V_2 -> V_24 = F_211 ( V_2 -> V_24 , ( int ) V_18 ) ;
V_2 -> V_27 = F_296 ( int , V_2 -> V_27 , F_216 ( V_18 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_269 -- ;
goto V_317;
}
F_244 ( & V_271 ) ;
return V_2 ;
}
V_40 = F_288 ( V_6 , V_259 ) ;
if ( ! V_40 )
goto V_317;
V_2 = F_270 ( V_267 , V_259 ) ;
if ( V_2 ) {
if ( F_230 ( V_2 , V_40 ,
V_18 , V_251 , V_3 , F_105 ) ) {
F_88 ( & V_2 -> V_272 , & V_276 ) ;
F_244 ( & V_271 ) ;
if ( F_4 ( V_2 ) ) {
F_243 ( & V_271 ) ;
F_90 ( & V_2 -> V_272 ) ;
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
goto V_317;
}
return V_2 ;
}
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
}
V_317:
F_244 ( & V_271 ) ;
if ( V_3 & V_270 )
F_233 ( L_92 , V_6 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int T_9 F_297 ( struct V_294 * V_318 ,
unsigned long V_296 , void * V_319 )
{
long V_66 = ( long ) V_319 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_296 ) {
case V_320 :
case V_321 :
case V_322 :
case V_323 :
F_274 ( & V_271 ) ;
F_182 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_171 ( V_2 , V_66 ) ;
F_42 ( V_3 ) ;
}
F_275 ( & V_271 ) ;
break;
default:
break;
}
return V_303 ;
}
void * F_298 ( T_1 V_18 , T_5 V_212 , unsigned long V_324 )
{
struct V_1 * V_2 ;
void * V_228 ;
if ( F_3 ( V_18 > V_282 ) )
return F_256 ( V_18 , V_212 ) ;
V_2 = F_253 ( V_18 , V_212 ) ;
if ( F_3 ( F_257 ( V_2 ) ) )
return V_2 ;
V_228 = F_193 ( V_2 , V_212 , V_127 , V_324 ) ;
F_199 ( V_324 , V_228 , V_18 , V_2 -> V_18 , V_212 ) ;
return V_228 ;
}
void * F_299 ( T_1 V_18 , T_5 V_212 ,
int V_13 , unsigned long V_324 )
{
struct V_1 * V_2 ;
void * V_228 ;
if ( F_3 ( V_18 > V_282 ) ) {
V_228 = F_258 ( V_18 , V_212 , V_13 ) ;
F_205 ( V_324 , V_228 ,
V_18 , V_30 << F_186 ( V_18 ) ,
V_212 , V_13 ) ;
return V_228 ;
}
V_2 = F_253 ( V_18 , V_212 ) ;
if ( F_3 ( F_257 ( V_2 ) ) )
return V_2 ;
V_228 = F_193 ( V_2 , V_212 , V_13 , V_324 ) ;
F_205 ( V_324 , V_228 , V_18 , V_2 -> V_18 , V_212 , V_13 ) ;
return V_228 ;
}
static int F_300 ( struct V_14 * V_14 )
{
return V_14 -> V_27 ;
}
static int F_301 ( struct V_14 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_302 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_48 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
if ( ! F_72 ( V_2 , V_14 ) ||
! F_74 ( V_2 , V_14 , NULL ) )
return 0 ;
F_303 ( V_48 , V_14 -> V_17 ) ;
F_43 ( V_2 , V_14 , V_48 ) ;
F_121 (p, s, addr, page->objects) {
if ( F_238 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) )
if ( ! F_71 ( V_2 , V_14 , V_5 , V_111 ) )
return 0 ;
}
F_121 (p, s, addr, page->objects)
if ( ! F_238 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) )
if ( ! F_71 ( V_2 , V_14 , V_5 , V_95 ) )
return 0 ;
return 1 ;
}
static void F_304 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_48 )
{
F_28 ( V_14 ) ;
F_302 ( V_2 , V_14 , V_48 ) ;
F_30 ( V_14 ) ;
}
static int F_305 ( struct V_1 * V_2 ,
struct V_12 * V_40 , unsigned long * V_48 )
{
unsigned long V_325 = 0 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_181 ( & V_40 -> V_163 , V_3 ) ;
F_182 (page, &n->partial, lru) {
F_304 ( V_2 , V_14 , V_48 ) ;
V_325 ++ ;
}
if ( V_325 != V_40 -> V_155 )
F_39 ( V_51 L_93
L_94 , V_2 -> V_6 , V_325 , V_40 -> V_155 ) ;
if ( ! ( V_2 -> V_3 & V_26 ) )
goto V_115;
F_182 (page, &n->full, lru) {
F_304 ( V_2 , V_14 , V_48 ) ;
V_325 ++ ;
}
if ( V_325 != F_92 ( & V_40 -> V_109 ) )
F_39 ( V_51 L_95
L_94 , V_2 -> V_6 , V_325 ,
F_92 ( & V_40 -> V_109 ) ) ;
V_115:
F_183 ( & V_40 -> V_163 , V_3 ) ;
return V_325 ;
}
static long F_306 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_325 = 0 ;
unsigned long * V_48 = F_270 ( F_237 ( F_27 ( V_2 -> F_211 ) ) *
sizeof( unsigned long ) , V_259 ) ;
if ( ! V_48 )
return - V_287 ;
F_175 ( V_2 ) ;
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
V_325 += F_305 ( V_2 , V_40 , V_48 ) ;
}
F_7 ( V_48 ) ;
return V_325 ;
}
static void F_307 ( struct V_326 * V_73 )
{
if ( V_73 -> F_211 )
F_286 ( ( unsigned long ) V_73 -> V_327 ,
F_186 ( sizeof( struct V_328 ) * V_73 -> F_211 ) ) ;
}
static int F_308 ( struct V_326 * V_73 , unsigned long F_211 , T_5 V_3 )
{
struct V_328 * V_188 ;
int V_28 ;
V_28 = F_186 ( sizeof( struct V_328 ) * F_211 ) ;
V_188 = ( void * ) F_284 ( V_3 , V_28 ) ;
if ( ! V_188 )
return 0 ;
if ( V_73 -> V_325 ) {
memcpy ( V_188 , V_73 -> V_327 , sizeof( struct V_328 ) * V_73 -> V_325 ) ;
F_307 ( V_73 ) ;
}
V_73 -> F_211 = F_211 ;
V_73 -> V_327 = V_188 ;
return 1 ;
}
static int F_309 ( struct V_326 * V_73 , struct V_1 * V_2 ,
const struct V_53 * V_53 )
{
long V_87 , V_91 , V_329 ;
struct V_328 * V_188 ;
unsigned long V_330 ;
unsigned long V_331 = V_70 - V_53 -> V_69 ;
V_87 = - 1 ;
V_91 = V_73 -> V_325 ;
for ( ; ; ) {
V_329 = V_87 + ( V_91 - V_87 + 1 ) / 2 ;
if ( V_329 == V_91 )
break;
V_330 = V_73 -> V_327 [ V_329 ] . V_21 ;
if ( V_53 -> V_21 == V_330 ) {
V_188 = & V_73 -> V_327 [ V_329 ] ;
V_188 -> V_325 ++ ;
if ( V_53 -> V_69 ) {
V_188 -> V_332 += V_331 ;
if ( V_331 < V_188 -> V_333 )
V_188 -> V_333 = V_331 ;
if ( V_331 > V_188 -> V_334 )
V_188 -> V_334 = V_331 ;
if ( V_53 -> V_67 < V_188 -> V_335 )
V_188 -> V_335 = V_53 -> V_67 ;
if ( V_53 -> V_67 > V_188 -> V_336 )
V_188 -> V_336 = V_53 -> V_67 ;
F_310 ( V_53 -> V_66 ,
F_311 ( V_188 -> V_337 ) ) ;
}
F_312 ( F_120 ( F_313 ( V_53 ) ) , V_188 -> V_338 ) ;
return 1 ;
}
if ( V_53 -> V_21 < V_330 )
V_91 = V_329 ;
else
V_87 = V_329 ;
}
if ( V_73 -> V_325 >= V_73 -> F_211 && ! F_308 ( V_73 , 2 * V_73 -> F_211 , V_211 ) )
return 0 ;
V_188 = V_73 -> V_327 + V_329 ;
if ( V_329 < V_73 -> V_325 )
memmove ( V_188 + 1 , V_188 ,
( V_73 -> V_325 - V_329 ) * sizeof( struct V_328 ) ) ;
V_73 -> V_325 ++ ;
V_188 -> V_325 = 1 ;
V_188 -> V_21 = V_53 -> V_21 ;
V_188 -> V_332 = V_331 ;
V_188 -> V_333 = V_331 ;
V_188 -> V_334 = V_331 ;
V_188 -> V_335 = V_53 -> V_67 ;
V_188 -> V_336 = V_53 -> V_67 ;
F_314 ( F_311 ( V_188 -> V_337 ) ) ;
F_310 ( V_53 -> V_66 , F_311 ( V_188 -> V_337 ) ) ;
F_315 ( V_188 -> V_338 ) ;
F_312 ( F_120 ( F_313 ( V_53 ) ) , V_188 -> V_338 ) ;
return 1 ;
}
static void F_316 ( struct V_326 * V_73 , struct V_1 * V_2 ,
struct V_14 * V_14 , enum V_54 V_55 ,
unsigned long * V_48 )
{
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
F_303 ( V_48 , V_14 -> V_17 ) ;
F_43 ( V_2 , V_14 , V_48 ) ;
F_121 (p, s, addr, page->objects)
if ( ! F_238 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) )
F_309 ( V_73 , V_2 , F_47 ( V_2 , V_5 , V_55 ) ) ;
}
static int F_317 ( struct V_1 * V_2 , char * V_75 ,
enum V_54 V_55 )
{
int V_339 = 0 ;
unsigned long V_58 ;
struct V_326 V_73 = { 0 , 0 , NULL } ;
int V_13 ;
unsigned long * V_48 = F_270 ( F_237 ( F_27 ( V_2 -> F_211 ) ) *
sizeof( unsigned long ) , V_259 ) ;
if ( ! V_48 || ! F_308 ( & V_73 , V_30 / sizeof( struct V_328 ) ,
V_340 ) ) {
F_7 ( V_48 ) ;
return sprintf ( V_75 , L_96 ) ;
}
F_175 ( V_2 ) ;
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_3 ;
struct V_14 * V_14 ;
if ( ! F_92 ( & V_40 -> V_109 ) )
continue;
F_181 ( & V_40 -> V_163 , V_3 ) ;
F_182 (page, &n->partial, lru)
F_316 ( & V_73 , V_2 , V_14 , V_55 , V_48 ) ;
F_182 (page, &n->full, lru)
F_316 ( & V_73 , V_2 , V_14 , V_55 , V_48 ) ;
F_183 ( & V_40 -> V_163 , V_3 ) ;
}
for ( V_58 = 0 ; V_58 < V_73 . V_325 ; V_58 ++ ) {
struct V_328 * V_188 = & V_73 . V_327 [ V_58 ] ;
if ( V_339 > V_30 - V_341 - 100 )
break;
V_339 += sprintf ( V_75 + V_339 , L_97 , V_188 -> V_325 ) ;
if ( V_188 -> V_21 )
V_339 += sprintf ( V_75 + V_339 , L_98 , ( void * ) V_188 -> V_21 ) ;
else
V_339 += sprintf ( V_75 + V_339 , L_99 ) ;
if ( V_188 -> V_332 != V_188 -> V_333 ) {
V_339 += sprintf ( V_75 + V_339 , L_100 ,
V_188 -> V_333 ,
( long ) F_318 ( V_188 -> V_332 , V_188 -> V_325 ) ,
V_188 -> V_334 ) ;
} else
V_339 += sprintf ( V_75 + V_339 , L_101 ,
V_188 -> V_333 ) ;
if ( V_188 -> V_335 != V_188 -> V_336 )
V_339 += sprintf ( V_75 + V_339 , L_102 ,
V_188 -> V_335 , V_188 -> V_336 ) ;
else
V_339 += sprintf ( V_75 + V_339 , L_103 ,
V_188 -> V_335 ) ;
if ( F_319 () > 1 &&
! F_320 ( F_311 ( V_188 -> V_337 ) ) &&
V_339 < V_30 - 60 ) {
V_339 += sprintf ( V_75 + V_339 , L_104 ) ;
V_339 += F_321 ( V_75 + V_339 , V_30 - V_339 - 50 ,
F_311 ( V_188 -> V_337 ) ) ;
}
if ( V_342 > 1 && ! F_322 ( V_188 -> V_338 ) &&
V_339 < V_30 - 60 ) {
V_339 += sprintf ( V_75 + V_339 , L_105 ) ;
V_339 += F_323 ( V_75 + V_339 , V_30 - V_339 - 50 ,
V_188 -> V_338 ) ;
}
V_339 += sprintf ( V_75 + V_339 , L_106 ) ;
}
F_307 ( & V_73 ) ;
F_7 ( V_48 ) ;
if ( ! V_73 . V_325 )
V_339 += sprintf ( V_75 , L_107 ) ;
return V_339 ;
}
static void F_324 ( void )
{
T_3 * V_5 ;
F_222 ( V_311 > 16 || V_256 < 10 ) ;
F_39 ( V_51 L_108 ) ;
F_39 ( V_51 L_109 ) ;
F_39 ( V_51 L_110 ) ;
V_5 = F_236 ( 16 , V_259 ) ;
V_5 [ 16 ] = 0x12 ;
F_39 ( V_51 L_111
L_112 , V_5 + 16 ) ;
F_306 ( V_281 [ 4 ] ) ;
V_5 = F_236 ( 32 , V_259 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_39 ( V_51 L_113
L_114 , V_5 ) ;
F_39 ( V_51
L_115 ) ;
F_306 ( V_281 [ 5 ] ) ;
V_5 = F_236 ( 64 , V_259 ) ;
V_5 += 64 + ( F_145 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_39 ( V_51 L_116 ,
V_5 ) ;
F_39 ( V_51
L_115 ) ;
F_306 ( V_281 [ 6 ] ) ;
F_39 ( V_51 L_117 ) ;
V_5 = F_236 ( 128 , V_259 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_39 ( V_51 L_118 , V_5 ) ;
F_306 ( V_281 [ 7 ] ) ;
V_5 = F_236 ( 256 , V_259 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_39 ( V_51 L_119 ,
V_5 ) ;
F_306 ( V_281 [ 8 ] ) ;
V_5 = F_236 ( 512 , V_259 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_39 ( V_51 L_120 , V_5 ) ;
F_306 ( V_281 [ 9 ] ) ;
}
static void F_324 ( void ) {}
static T_10 F_325 ( struct V_1 * V_2 ,
char * V_75 , unsigned long V_3 )
{
unsigned long V_343 = 0 ;
int V_13 ;
int V_32 ;
unsigned long * V_338 ;
unsigned long * V_344 ;
V_338 = F_236 ( 2 * sizeof( unsigned long ) * V_308 , V_259 ) ;
if ( ! V_338 )
return - V_287 ;
V_344 = V_338 + V_308 ;
if ( V_3 & V_345 ) {
int V_66 ;
F_163 (cpu) {
struct V_160 * V_161 = F_164 ( V_2 -> V_9 , V_66 ) ;
int V_13 = F_326 ( V_161 -> V_13 ) ;
struct V_14 * V_14 ;
if ( V_13 < 0 )
continue;
V_14 = F_326 ( V_161 -> V_14 ) ;
if ( V_14 ) {
if ( V_3 & V_346 )
V_32 = V_14 -> V_17 ;
else if ( V_3 & V_347 )
V_32 = V_14 -> V_27 ;
else
V_32 = 1 ;
V_343 += V_32 ;
V_338 [ V_13 ] += V_32 ;
}
V_14 = V_161 -> V_157 ;
if ( V_14 ) {
V_32 = V_14 -> V_206 ;
V_343 += V_32 ;
V_338 [ V_13 ] += V_32 ;
}
V_344 [ V_13 ] ++ ;
}
}
F_327 () ;
#ifdef F_2
if ( V_3 & V_348 ) {
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_346 )
V_32 = F_92 ( & V_40 -> V_110 ) ;
else if ( V_3 & V_347 )
V_32 = F_92 ( & V_40 -> V_110 ) -
F_179 ( V_40 , F_178 ) ;
else
V_32 = F_92 ( & V_40 -> V_109 ) ;
V_343 += V_32 ;
V_338 [ V_13 ] += V_32 ;
}
} else
#endif
if ( V_3 & V_349 ) {
F_226 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_346 )
V_32 = F_179 ( V_40 , F_301 ) ;
else if ( V_3 & V_347 )
V_32 = F_179 ( V_40 , F_300 ) ;
else
V_32 = V_40 -> V_155 ;
V_343 += V_32 ;
V_338 [ V_13 ] += V_32 ;
}
}
V_32 = sprintf ( V_75 , L_121 , V_343 ) ;
#ifdef F_143
F_226 (node, N_NORMAL_MEMORY)
if ( V_338 [ V_13 ] )
V_32 += sprintf ( V_75 + V_32 , L_122 ,
V_13 , V_338 [ V_13 ] ) ;
#endif
F_328 () ;
F_7 ( V_338 ) ;
return V_32 + sprintf ( V_75 + V_32 , L_106 ) ;
}
static int F_329 ( struct V_1 * V_2 )
{
int V_13 ;
F_187 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
if ( F_92 ( & V_40 -> V_110 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_330 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_18 ) ;
}
static T_10 F_331 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_251 ) ;
}
static T_10 F_332 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_24 ) ;
}
static T_10 F_333 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , F_27 ( V_2 -> V_125 ) ) ;
}
static T_10 F_334 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_28 ;
int V_317 ;
V_317 = F_335 ( V_75 , 10 , & V_28 ) ;
if ( V_317 )
return V_317 ;
if ( V_28 > V_248 || V_28 < V_242 )
return - V_350 ;
F_229 ( V_2 , V_28 ) ;
return V_50 ;
}
static T_10 F_336 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , F_26 ( V_2 -> V_125 ) ) ;
}
static T_10 F_337 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_124 , V_2 -> V_177 ) ;
}
static T_10 F_338 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_133 ;
int V_317 ;
V_317 = F_335 ( V_75 , 10 , & V_133 ) ;
if ( V_317 )
return V_317 ;
F_228 ( V_2 , V_133 ) ;
return V_50 ;
}
static T_10 F_339 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_125 , V_2 -> V_167 ) ;
}
static T_10 F_340 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_17 ;
int V_317 ;
V_317 = F_335 ( V_75 , 10 , & V_17 ) ;
if ( V_317 )
return V_317 ;
if ( V_17 && F_1 ( V_2 ) )
return - V_350 ;
V_2 -> V_167 = V_17 ;
F_175 ( V_2 ) ;
return V_50 ;
}
static T_10 F_341 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! V_2 -> F_105 )
return 0 ;
return sprintf ( V_75 , L_126 , V_2 -> F_105 ) ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_269 - 1 ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , char * V_75 )
{
return F_325 ( V_2 , V_75 , V_349 ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_75 )
{
return F_325 ( V_2 , V_75 , V_345 ) ;
}
static T_10 F_345 ( struct V_1 * V_2 , char * V_75 )
{
return F_325 ( V_2 , V_75 , V_348 | V_347 ) ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_75 )
{
return F_325 ( V_2 , V_75 , V_349 | V_347 ) ;
}
static T_10 F_347 ( struct V_1 * V_2 , char * V_75 )
{
int V_17 = 0 ;
int V_137 = 0 ;
int V_66 ;
int V_339 ;
F_348 (cpu) {
struct V_14 * V_14 = F_164 ( V_2 -> V_9 , V_66 ) -> V_157 ;
if ( V_14 ) {
V_137 += V_14 -> V_137 ;
V_17 += V_14 -> V_206 ;
}
}
V_339 = sprintf ( V_75 , L_127 , V_17 , V_137 ) ;
#ifdef F_290
F_348 (cpu) {
struct V_14 * V_14 = F_164 ( V_2 -> V_9 , V_66 ) -> V_157 ;
if ( V_14 && V_339 < V_30 - 20 )
V_339 += sprintf ( V_75 + V_339 , L_128 , V_66 ,
V_14 -> V_206 , V_14 -> V_137 ) ;
}
#endif
return V_339 + sprintf ( V_75 + V_339 , L_106 ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_138 ) ) ;
}
static T_10 F_350 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_138 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_138 ;
return V_50 ;
}
static T_10 F_351 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_252 ) ) ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_264 ) ) ;
}
static T_10 F_353 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_25 ) ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_29 ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , char * V_75 )
{
return F_325 ( V_2 , V_75 , V_348 ) ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_75 )
{
return F_325 ( V_2 , V_75 , V_348 | V_346 ) ;
}
static T_10 F_357 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_122 ) ) ;
}
static T_10 F_358 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_122 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_122 ;
}
return V_50 ;
}
static T_10 F_359 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_10 F_360 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_101 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_101 ;
}
return V_50 ;
}
static T_10 F_361 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_362 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_329 ( V_2 ) )
return - V_351 ;
V_2 -> V_3 &= ~ V_22 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_22 ;
}
F_229 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_363 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_364 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_329 ( V_2 ) )
return - V_351 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_23 ;
}
F_229 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_365 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_26 ) ) ;
}
static T_10 F_366 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_329 ( V_2 ) )
return - V_351 ;
V_2 -> V_3 &= ~ V_26 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_26 ;
}
F_229 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_367 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_10 F_368 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
int V_228 = - V_350 ;
if ( V_75 [ 0 ] == '1' ) {
V_228 = F_306 ( V_2 ) ;
if ( V_228 >= 0 )
V_228 = V_50 ;
}
return V_228 ;
}
static T_10 F_369 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_250 ;
return F_317 ( V_2 , V_75 , V_72 ) ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_250 ;
return F_317 ( V_2 , V_75 , V_71 ) ;
}
static T_10 F_371 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_123 ) ) ;
}
static T_10 F_372 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_123 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_123 ;
return V_50 ;
}
static T_10 F_373 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_10 F_374 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( V_75 [ 0 ] == '1' ) {
int V_113 = F_269 ( V_2 ) ;
if ( V_113 )
return V_113 ;
} else
return - V_350 ;
return V_50 ;
}
static T_10 F_375 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_175 / 10 ) ;
}
static T_10 F_376 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_352 ;
int V_317 ;
V_317 = F_335 ( V_75 , 10 , & V_352 ) ;
if ( V_317 )
return V_317 ;
if ( V_352 <= 100 )
V_2 -> V_175 = V_352 * 10 ;
return V_50 ;
}
static int F_377 ( struct V_1 * V_2 , char * V_75 , enum V_7 V_8 )
{
unsigned long V_353 = 0 ;
int V_66 ;
int V_339 ;
int * V_83 = F_270 ( V_247 * sizeof( int ) , V_259 ) ;
if ( ! V_83 )
return - V_287 ;
F_348 (cpu) {
unsigned V_32 = F_164 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] ;
V_83 [ V_66 ] = V_32 ;
V_353 += V_32 ;
}
V_339 = sprintf ( V_75 , L_121 , V_353 ) ;
#ifdef F_290
F_348 (cpu) {
if ( V_83 [ V_66 ] && V_339 < V_30 - 20 )
V_339 += sprintf ( V_75 + V_339 , L_129 , V_66 , V_83 [ V_66 ] ) ;
}
#endif
F_7 ( V_83 ) ;
return V_339 + sprintf ( V_75 + V_339 , L_106 ) ;
}
static void F_378 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_66 ;
F_348 (cpu)
F_164 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] = 0 ;
}
static T_10 F_379 ( struct V_354 * V_355 ,
struct V_356 * V_357 ,
char * V_75 )
{
struct V_358 * V_356 ;
struct V_1 * V_2 ;
int V_317 ;
V_356 = F_380 ( V_357 ) ;
V_2 = F_381 ( V_355 ) ;
if ( ! V_356 -> V_359 )
return - V_360 ;
V_317 = V_356 -> V_359 ( V_2 , V_75 ) ;
return V_317 ;
}
static T_10 F_382 ( struct V_354 * V_355 ,
struct V_356 * V_357 ,
const char * V_75 , T_1 V_339 )
{
struct V_358 * V_356 ;
struct V_1 * V_2 ;
int V_317 ;
V_356 = F_380 ( V_357 ) ;
V_2 = F_381 ( V_355 ) ;
if ( ! V_356 -> V_361 )
return - V_360 ;
V_317 = V_356 -> V_361 ( V_2 , V_75 , V_339 ) ;
return V_317 ;
}
static void F_383 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_381 ( V_355 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_384 ( struct V_362 * V_362 , struct V_354 * V_355 )
{
struct V_363 * V_364 = F_385 ( V_355 ) ;
if ( V_364 == & V_365 )
return 1 ;
return 0 ;
}
static char * F_386 ( struct V_1 * V_2 )
{
char * V_6 = F_270 ( V_366 , V_259 ) ;
char * V_5 = V_6 ;
F_119 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_264 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_138 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_122 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_136 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_6 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_130 , V_2 -> V_18 ) ;
F_119 ( V_5 > V_6 + V_366 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_317 ;
const char * V_6 ;
int V_367 ;
if ( V_10 < V_368 )
return 0 ;
V_367 = F_293 ( V_2 ) ;
if ( V_367 ) {
F_387 ( & V_369 -> V_355 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_386 ( V_2 ) ;
}
V_2 -> V_355 . V_362 = V_369 ;
V_317 = F_388 ( & V_2 -> V_355 , & V_365 , NULL , V_6 ) ;
if ( V_317 ) {
F_389 ( & V_2 -> V_355 ) ;
return V_317 ;
}
V_317 = F_390 ( & V_2 -> V_355 , & V_370 ) ;
if ( V_317 ) {
F_391 ( & V_2 -> V_355 ) ;
F_389 ( & V_2 -> V_355 ) ;
return V_317 ;
}
F_392 ( & V_2 -> V_355 , V_371 ) ;
if ( ! V_367 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_10 < V_368 )
return;
F_392 ( & V_2 -> V_355 , V_372 ) ;
F_391 ( & V_2 -> V_355 ) ;
F_389 ( & V_2 -> V_355 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_373 * V_374 ;
if ( V_10 == V_368 ) {
F_387 ( & V_369 -> V_355 , V_6 ) ;
return F_393 ( & V_369 -> V_355 , & V_2 -> V_355 , V_6 ) ;
}
V_374 = F_270 ( sizeof( struct V_373 ) , V_259 ) ;
if ( ! V_374 )
return - V_287 ;
V_374 -> V_2 = V_2 ;
V_374 -> V_6 = V_6 ;
V_374 -> V_200 = V_375 ;
V_375 = V_374 ;
return 0 ;
}
static int T_7 F_394 ( void )
{
struct V_1 * V_2 ;
int V_317 ;
F_243 ( & V_271 ) ;
V_369 = F_395 ( L_131 , & V_376 , V_377 ) ;
if ( ! V_369 ) {
F_244 ( & V_271 ) ;
F_39 ( V_51 L_132 ) ;
return - V_250 ;
}
V_10 = V_368 ;
F_182 (s, &slab_caches, list) {
V_317 = F_4 ( V_2 ) ;
if ( V_317 )
F_39 ( V_51 L_133
L_134 , V_2 -> V_6 ) ;
}
while ( V_375 ) {
struct V_373 * V_374 = V_375 ;
V_375 = V_375 -> V_200 ;
V_317 = F_5 ( V_374 -> V_2 , V_374 -> V_6 ) ;
if ( V_317 )
F_39 ( V_51 L_135
L_136 , V_2 -> V_6 ) ;
F_7 ( V_374 ) ;
}
F_244 ( & V_271 ) ;
F_324 () ;
return 0 ;
}
static void F_396 ( struct V_378 * V_189 )
{
F_397 ( V_189 , L_137 ) ;
F_397 ( V_189 , L_138
L_139 ) ;
F_397 ( V_189 , L_140 ) ;
F_397 ( V_189 , L_141 ) ;
F_398 ( V_189 , '\n' ) ;
}
static void * F_399 ( struct V_378 * V_189 , T_11 * V_329 )
{
T_11 V_40 = * V_329 ;
F_274 ( & V_271 ) ;
if ( ! V_40 )
F_396 ( V_189 ) ;
return F_400 ( & V_276 , * V_329 ) ;
}
static void * F_401 ( struct V_378 * V_189 , void * V_5 , T_11 * V_329 )
{
return F_402 ( V_5 , & V_276 , V_329 ) ;
}
static void F_403 ( struct V_378 * V_189 , void * V_5 )
{
F_275 ( & V_271 ) ;
}
static int F_404 ( struct V_378 * V_189 , void * V_5 )
{
unsigned long V_379 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_380 = 0 ;
unsigned long V_215 = 0 ;
unsigned long V_216 = 0 ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_405 ( V_5 , struct V_1 , V_272 ) ;
F_187 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
V_379 += V_40 -> V_155 ;
V_109 += F_92 ( & V_40 -> V_109 ) ;
V_215 += F_92 ( & V_40 -> V_110 ) ;
V_216 += F_179 ( V_40 , F_178 ) ;
}
V_380 = V_215 - V_216 ;
F_406 ( V_189 , L_142 , V_2 -> V_6 , V_380 ,
V_215 , V_2 -> V_18 , F_27 ( V_2 -> V_125 ) ,
( 1 << F_26 ( V_2 -> V_125 ) ) ) ;
F_406 ( V_189 , L_143 , 0 , 0 , 0 ) ;
F_406 ( V_189 , L_144 , V_109 , V_109 ,
0UL ) ;
F_398 ( V_189 , '\n' ) ;
return 0 ;
}
static int F_407 ( struct V_381 * V_381 , struct V_382 * V_382 )
{
return F_408 ( V_382 , & V_383 ) ;
}
static int T_7 F_409 ( void )
{
F_410 ( L_145 , V_384 , NULL , & V_385 ) ;
return 0 ;
}
