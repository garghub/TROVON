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
F_121 ( V_14 ) ;
V_87 = F_14 ( V_14 ) ;
if ( F_3 ( V_2 -> V_3 & V_23 ) )
memset ( V_87 , V_92 , V_30 << F_70 ( V_14 ) ) ;
V_141 = V_87 ;
F_122 (p, s, start, page->objects) {
F_117 ( V_2 , V_14 , V_141 ) ;
F_21 ( V_2 , V_141 , V_5 ) ;
V_141 = V_5 ;
}
F_117 ( V_2 , V_14 , V_141 ) ;
F_21 ( V_2 , V_141 , NULL ) ;
V_14 -> V_44 = V_87 ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_145 = 1 ;
V_115:
return V_14 ;
}
static void F_123 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_28 = F_70 ( V_14 ) ;
int V_137 = 1 << V_28 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_69 ( V_2 , V_14 ) ;
F_122 (p, s, page_address(page),
page->objects)
F_71 ( V_2 , V_14 , V_5 , V_111 ) ;
}
F_124 ( V_14 , F_70 ( V_14 ) ) ;
F_115 ( F_116 ( V_14 ) ,
( V_2 -> V_3 & V_138 ) ?
V_139 : V_140 ,
- V_137 ) ;
F_125 ( V_14 ) ;
F_126 ( V_14 ) ;
if ( V_68 -> V_146 )
V_68 -> V_146 -> V_147 += V_137 ;
F_127 ( V_14 , V_28 ) ;
}
static void F_128 ( struct V_148 * V_149 )
{
struct V_14 * V_14 ;
if ( V_150 )
V_14 = F_129 ( V_149 ) ;
else
V_14 = F_130 ( (struct V_151 * ) V_149 , struct V_14 , V_107 ) ;
F_123 ( V_14 -> V_116 , V_14 ) ;
}
static void F_131 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( F_3 ( V_2 -> V_3 & V_25 ) ) {
struct V_148 * V_152 ;
if ( V_150 ) {
int V_28 = F_70 ( V_14 ) ;
int V_19 = ( V_30 << V_28 ) - V_2 -> V_29 ;
F_33 ( V_2 -> V_29 != sizeof( * V_152 ) ) ;
V_152 = F_14 ( V_14 ) + V_19 ;
} else {
V_152 = ( void * ) & V_14 -> V_107 ;
}
F_132 ( V_152 , F_128 ) ;
} else
F_123 ( V_2 , V_14 ) ;
}
static void F_133 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
F_97 ( V_2 , F_120 ( V_14 ) , V_14 -> V_17 ) ;
F_131 ( V_2 , V_14 ) ;
}
static inline void F_134 ( struct V_12 * V_40 ,
struct V_14 * V_14 , int V_153 )
{
V_40 -> V_154 ++ ;
if ( V_153 == V_155 )
F_135 ( & V_14 -> V_107 , & V_40 -> V_156 ) ;
else
F_88 ( & V_14 -> V_107 , & V_40 -> V_156 ) ;
}
static inline void F_136 ( struct V_12 * V_40 ,
struct V_14 * V_14 )
{
F_90 ( & V_14 -> V_107 ) ;
V_40 -> V_154 -- ;
}
static inline void * F_137 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 ,
int V_157 )
{
void * V_44 ;
unsigned long V_45 ;
struct V_14 V_158 ;
do {
V_44 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
V_158 . V_45 = V_45 ;
if ( V_157 ) {
V_158 . V_27 = V_14 -> V_17 ;
V_158 . V_44 = NULL ;
} else {
V_158 . V_44 = V_44 ;
}
F_33 ( V_158 . V_145 ) ;
V_158 . V_145 = 1 ;
} while ( ! F_32 ( V_2 , V_14 ,
V_44 , V_45 ,
V_158 . V_44 , V_158 . V_45 ,
L_54 ) );
F_136 ( V_40 , V_14 ) ;
return V_44 ;
}
static void * F_138 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_159 * V_160 )
{
struct V_14 * V_14 , * V_161 ;
void * V_15 = NULL ;
if ( ! V_40 || ! V_40 -> V_154 )
return NULL ;
F_139 ( & V_40 -> V_162 ) ;
F_140 (page, page2, &n->partial, lru) {
void * V_73 = F_137 ( V_2 , V_40 , V_14 , V_15 == NULL ) ;
int V_163 ;
if ( ! V_73 )
break;
if ( ! V_15 ) {
V_160 -> V_14 = V_14 ;
V_160 -> V_13 = F_120 ( V_14 ) ;
F_8 ( V_2 , V_164 ) ;
V_15 = V_73 ;
V_163 = V_14 -> V_17 - V_14 -> V_27 ;
} else {
V_163 = F_141 ( V_2 , V_14 , 0 ) ;
F_8 ( V_2 , V_165 ) ;
}
if ( F_1 ( V_2 ) || V_163 > V_2 -> V_166 / 2 )
break;
}
F_142 ( & V_40 -> V_162 ) ;
return V_15 ;
}
static void * F_143 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_159 * V_160 )
{
#ifdef F_144
struct V_167 * V_167 ;
struct V_168 * V_169 ;
struct V_170 * V_170 ;
enum V_171 V_172 = F_145 ( V_3 ) ;
void * V_15 ;
unsigned int V_173 ;
if ( ! V_2 -> V_174 ||
F_146 () % 1024 > V_2 -> V_174 )
return NULL ;
do {
V_173 = F_147 () ;
V_167 = F_148 ( F_149 ( V_68 -> V_175 ) , V_3 ) ;
F_150 (zone, z, zonelist, high_zoneidx) {
struct V_12 * V_40 ;
V_40 = F_12 ( V_2 , F_151 ( V_170 ) ) ;
if ( V_40 && F_152 ( V_170 , V_3 ) &&
V_40 -> V_154 > V_2 -> V_176 ) {
V_15 = F_138 ( V_2 , V_40 , V_160 ) ;
if ( V_15 ) {
F_153 ( V_173 ) ;
return V_15 ;
}
}
}
} while ( ! F_153 ( V_173 ) );
#endif
return NULL ;
}
static void * F_154 ( struct V_1 * V_2 , T_5 V_3 , int V_13 ,
struct V_159 * V_160 )
{
void * V_15 ;
int V_177 = ( V_13 == V_127 ) ? F_155 () : V_13 ;
V_15 = F_138 ( V_2 , F_12 ( V_2 , V_177 ) , V_160 ) ;
if ( V_15 || V_13 != V_127 )
return V_15 ;
return F_143 ( V_2 , V_3 , V_160 ) ;
}
static inline unsigned long F_156 ( unsigned long V_178 )
{
return V_178 + V_179 ;
}
static inline unsigned int F_157 ( unsigned long V_178 )
{
return V_178 % V_179 ;
}
static inline unsigned long F_158 ( unsigned long V_178 )
{
return V_178 / V_179 ;
}
static inline unsigned int F_159 ( int V_66 )
{
return V_66 ;
}
static inline void F_160 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_178 )
{
#ifdef F_38
unsigned long V_180 = F_161 ( V_2 -> V_9 -> V_178 ) ;
F_39 ( V_47 L_55 , V_40 , V_2 -> V_6 ) ;
#ifdef F_162
if ( F_157 ( V_178 ) != F_157 ( V_180 ) )
F_39 ( L_56 ,
F_157 ( V_178 ) , F_157 ( V_180 ) ) ;
else
#endif
if ( F_158 ( V_178 ) != F_158 ( V_180 ) )
F_39 ( L_57 ,
F_158 ( V_178 ) , F_158 ( V_180 ) ) ;
else
F_39 ( L_58 ,
V_180 , V_178 , F_156 ( V_178 ) ) ;
#endif
F_8 ( V_2 , V_181 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
int V_66 ;
F_164 (cpu)
F_165 ( V_2 -> V_9 , V_66 ) -> V_178 = F_159 ( V_66 ) ;
}
static void F_166 ( struct V_1 * V_2 , struct V_159 * V_160 )
{
enum T_8 { V_182 , V_183 , V_184 , V_185 };
struct V_14 * V_14 = V_160 -> V_14 ;
struct V_12 * V_40 = F_12 ( V_2 , F_120 ( V_14 ) ) ;
int V_186 = 0 ;
enum T_8 V_187 = V_182 , V_188 = V_182 ;
void * V_44 ;
void * V_189 ;
int V_153 = V_190 ;
struct V_14 V_158 ;
struct V_14 V_191 ;
if ( V_14 -> V_44 ) {
F_8 ( V_2 , V_192 ) ;
V_153 = V_155 ;
}
V_160 -> V_178 = F_156 ( V_160 -> V_178 ) ;
V_160 -> V_14 = NULL ;
V_44 = V_160 -> V_44 ;
V_160 -> V_44 = NULL ;
while ( V_44 && ( V_189 = F_15 ( V_2 , V_44 ) ) ) {
void * V_193 ;
unsigned long V_45 ;
do {
V_193 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
F_21 ( V_2 , V_44 , V_193 ) ;
V_158 . V_45 = V_45 ;
V_158 . V_27 -- ;
F_33 ( ! V_158 . V_145 ) ;
} while ( ! F_32 ( V_2 , V_14 ,
V_193 , V_45 ,
V_44 , V_158 . V_45 ,
L_59 ) );
V_44 = V_189 ;
}
V_194:
V_191 . V_44 = V_14 -> V_44 ;
V_191 . V_45 = V_14 -> V_45 ;
F_33 ( ! V_191 . V_145 ) ;
V_158 . V_45 = V_191 . V_45 ;
if ( V_44 ) {
V_158 . V_27 -- ;
F_21 ( V_2 , V_44 , V_191 . V_44 ) ;
V_158 . V_44 = V_44 ;
} else
V_158 . V_44 = V_191 . V_44 ;
V_158 . V_145 = 0 ;
if ( ! V_158 . V_27 && V_40 -> V_154 > V_2 -> V_176 )
V_188 = V_185 ;
else if ( V_158 . V_44 ) {
V_188 = V_183 ;
if ( ! V_186 ) {
V_186 = 1 ;
F_139 ( & V_40 -> V_162 ) ;
}
} else {
V_188 = V_184 ;
if ( F_1 ( V_2 ) && ! V_186 ) {
V_186 = 1 ;
F_139 ( & V_40 -> V_162 ) ;
}
}
if ( V_187 != V_188 ) {
if ( V_187 == V_183 )
F_136 ( V_40 , V_14 ) ;
else if ( V_187 == V_184 )
F_89 ( V_2 , V_14 ) ;
if ( V_188 == V_183 ) {
F_134 ( V_40 , V_14 , V_153 ) ;
F_8 ( V_2 , V_153 ) ;
} else if ( V_188 == V_184 ) {
F_8 ( V_2 , V_195 ) ;
F_87 ( V_2 , V_40 , V_14 ) ;
}
}
V_187 = V_188 ;
if ( ! F_32 ( V_2 , V_14 ,
V_191 . V_44 , V_191 . V_45 ,
V_158 . V_44 , V_158 . V_45 ,
L_60 ) )
goto V_194;
if ( V_186 )
F_142 ( & V_40 -> V_162 ) ;
if ( V_188 == V_185 ) {
F_8 ( V_2 , V_196 ) ;
F_133 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_197 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_12 * V_40 = NULL ;
struct V_159 * V_160 = F_168 ( V_2 -> V_9 ) ;
struct V_14 * V_14 , * V_198 = NULL ;
while ( ( V_14 = V_160 -> V_156 ) ) {
enum T_8 { V_183 , V_185 };
enum T_8 V_187 , V_188 ;
struct V_14 V_158 ;
struct V_14 V_191 ;
V_160 -> V_156 = V_14 -> V_199 ;
V_187 = V_185 ;
do {
V_191 . V_44 = V_14 -> V_44 ;
V_191 . V_45 = V_14 -> V_45 ;
F_33 ( ! V_191 . V_145 ) ;
V_158 . V_45 = V_191 . V_45 ;
V_158 . V_44 = V_191 . V_44 ;
V_158 . V_145 = 0 ;
if ( ! V_158 . V_27 && ( ! V_40 || V_40 -> V_154 > V_2 -> V_176 ) )
V_188 = V_185 ;
else {
struct V_12 * V_200 = F_12 ( V_2 ,
F_120 ( V_14 ) ) ;
V_188 = V_183 ;
if ( V_40 != V_200 ) {
if ( V_40 )
F_142 ( & V_40 -> V_162 ) ;
V_40 = V_200 ;
F_139 ( & V_40 -> V_162 ) ;
}
}
if ( V_187 != V_188 ) {
if ( V_187 == V_183 ) {
F_136 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_201 ) ;
} else {
F_134 ( V_40 , V_14 ,
V_155 ) ;
F_8 ( V_2 , V_202 ) ;
}
V_187 = V_188 ;
}
} while ( ! F_40 ( V_2 , V_14 ,
V_191 . V_44 , V_191 . V_45 ,
V_158 . V_44 , V_158 . V_45 ,
L_60 ) );
if ( V_188 == V_185 ) {
V_14 -> V_199 = V_198 ;
V_198 = V_14 ;
}
}
if ( V_40 )
F_142 ( & V_40 -> V_162 ) ;
while ( V_198 ) {
V_14 = V_198 ;
V_198 = V_198 -> V_199 ;
F_8 ( V_2 , V_196 ) ;
F_133 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_197 ) ;
}
}
int F_141 ( struct V_1 * V_2 , struct V_14 * V_14 , int V_203 )
{
struct V_14 * V_204 ;
int V_137 ;
int V_205 ;
do {
V_137 = 0 ;
V_205 = 0 ;
V_204 = F_169 ( V_2 -> V_9 -> V_156 ) ;
if ( V_204 ) {
V_205 = V_204 -> V_205 ;
V_137 = V_204 -> V_137 ;
if ( V_203 && V_205 > V_2 -> V_166 ) {
unsigned long V_3 ;
F_41 ( V_3 ) ;
F_167 ( V_2 ) ;
F_42 ( V_3 ) ;
V_205 = 0 ;
V_137 = 0 ;
F_8 ( V_2 , V_206 ) ;
}
}
V_137 ++ ;
V_205 += V_14 -> V_17 - V_14 -> V_27 ;
V_14 -> V_137 = V_137 ;
V_14 -> V_205 = V_205 ;
V_14 -> V_199 = V_204 ;
} while ( F_170 ( V_2 -> V_9 -> V_156 , V_204 , V_14 ) != V_204 );
return V_205 ;
}
static inline void F_171 ( struct V_1 * V_2 , struct V_159 * V_160 )
{
F_8 ( V_2 , V_207 ) ;
F_166 ( V_2 , V_160 ) ;
}
static inline void F_172 ( struct V_1 * V_2 , int V_66 )
{
struct V_159 * V_160 = F_165 ( V_2 -> V_9 , V_66 ) ;
if ( F_173 ( V_160 ) ) {
if ( V_160 -> V_14 )
F_171 ( V_2 , V_160 ) ;
F_167 ( V_2 ) ;
}
}
static void F_174 ( void * V_208 )
{
struct V_1 * V_2 = V_208 ;
F_172 ( V_2 , F_51 () ) ;
}
static bool F_175 ( int V_66 , void * V_209 )
{
struct V_1 * V_2 = V_209 ;
struct V_159 * V_160 = F_165 ( V_2 -> V_9 , V_66 ) ;
return V_160 -> V_14 || V_160 -> V_156 ;
}
static void F_176 ( struct V_1 * V_2 )
{
F_177 ( F_175 , F_174 , V_2 , 1 , V_210 ) ;
}
static inline int F_178 ( struct V_159 * V_160 , int V_13 )
{
#ifdef F_144
if ( V_13 != V_127 && V_160 -> V_13 != V_13 )
return 0 ;
#endif
return 1 ;
}
static int F_179 ( struct V_14 * V_14 )
{
return V_14 -> V_17 - V_14 -> V_27 ;
}
static unsigned long F_180 ( struct V_12 * V_40 ,
int (* F_181)( struct V_14 * ) )
{
unsigned long V_3 ;
unsigned long V_32 = 0 ;
struct V_14 * V_14 ;
F_182 ( & V_40 -> V_162 , V_3 ) ;
F_183 (page, &n->partial, lru)
V_32 += F_181 ( V_14 ) ;
F_184 ( & V_40 -> V_162 , V_3 ) ;
return V_32 ;
}
static inline unsigned long F_185 ( struct V_12 * V_40 )
{
#ifdef F_2
return F_92 ( & V_40 -> V_110 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_186 ( struct V_1 * V_2 , T_5 V_211 , int V_212 )
{
int V_13 ;
F_39 ( V_213
L_61 ,
V_212 , V_211 ) ;
F_39 ( V_213 L_62
L_63 , V_2 -> V_6 , V_2 -> V_24 ,
V_2 -> V_18 , F_26 ( V_2 -> V_125 ) , F_26 ( V_2 -> V_133 ) ) ;
if ( F_26 ( V_2 -> V_133 ) > F_187 ( V_2 -> V_24 ) )
F_39 ( V_213 L_64
L_65 , V_2 -> V_6 ) ;
F_188 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_109 ;
unsigned long V_214 ;
unsigned long V_215 ;
if ( ! V_40 )
continue;
V_215 = F_180 ( V_40 , F_179 ) ;
V_109 = F_93 ( V_40 ) ;
V_214 = F_185 ( V_40 ) ;
F_39 ( V_213
L_66 ,
V_13 , V_109 , V_214 , V_215 ) ;
}
}
static inline void * F_189 ( struct V_1 * V_2 , T_5 V_3 ,
int V_13 , struct V_159 * * V_216 )
{
void * V_15 ;
struct V_159 * V_160 ;
struct V_14 * V_14 = F_118 ( V_2 , V_3 , V_13 ) ;
if ( V_14 ) {
V_160 = F_190 ( V_2 -> V_9 ) ;
if ( V_160 -> V_14 )
F_171 ( V_2 , V_160 ) ;
V_15 = V_14 -> V_44 ;
V_14 -> V_44 = NULL ;
F_8 ( V_2 , V_217 ) ;
V_160 -> V_13 = F_120 ( V_14 ) ;
V_160 -> V_14 = V_14 ;
* V_216 = V_160 ;
} else
V_15 = NULL ;
return V_15 ;
}
static inline void * F_191 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_14 V_158 ;
unsigned long V_45 ;
void * V_44 ;
do {
V_44 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
V_158 . V_45 = V_45 ;
F_33 ( ! V_158 . V_145 ) ;
V_158 . V_27 = V_14 -> V_17 ;
V_158 . V_145 = V_44 != NULL ;
} while ( ! F_40 ( V_2 , V_14 ,
V_44 , V_45 ,
NULL , V_158 . V_45 ,
L_67 ) );
return V_44 ;
}
static void * F_192 ( struct V_1 * V_2 , T_5 V_211 , int V_13 ,
unsigned long V_21 , struct V_159 * V_160 )
{
void * * V_15 ;
unsigned long V_3 ;
F_41 ( V_3 ) ;
#ifdef F_162
V_160 = F_168 ( V_2 -> V_9 ) ;
#endif
if ( ! V_160 -> V_14 )
goto F_118;
V_194:
if ( F_3 ( ! F_178 ( V_160 , V_13 ) ) ) {
F_8 ( V_2 , V_218 ) ;
F_166 ( V_2 , V_160 ) ;
goto F_118;
}
V_15 = V_160 -> V_44 ;
if ( V_15 )
goto V_219;
F_8 ( V_2 , V_220 ) ;
V_15 = F_191 ( V_2 , V_160 -> V_14 ) ;
if ( ! V_15 ) {
V_160 -> V_14 = NULL ;
F_8 ( V_2 , V_221 ) ;
goto F_118;
}
F_8 ( V_2 , V_222 ) ;
V_219:
V_160 -> V_44 = F_15 ( V_2 , V_15 ) ;
V_160 -> V_178 = F_156 ( V_160 -> V_178 ) ;
F_42 ( V_3 ) ;
return V_15 ;
F_118:
if ( V_160 -> V_156 ) {
V_160 -> V_14 = V_160 -> V_156 ;
V_160 -> V_156 = V_160 -> V_14 -> V_199 ;
V_160 -> V_13 = F_120 ( V_160 -> V_14 ) ;
F_8 ( V_2 , V_223 ) ;
V_160 -> V_44 = NULL ;
goto V_194;
}
V_15 = F_154 ( V_2 , V_211 , V_13 , V_160 ) ;
if ( F_3 ( ! V_15 ) ) {
V_15 = F_189 ( V_2 , V_211 , V_13 , & V_160 ) ;
if ( F_3 ( ! V_15 ) ) {
if ( ! ( V_211 & V_130 ) && F_193 () )
F_186 ( V_2 , V_211 , V_13 ) ;
F_42 ( V_3 ) ;
return NULL ;
}
}
if ( F_173 ( ! F_1 ( V_2 ) ) )
goto V_219;
if ( ! F_101 ( V_2 , V_160 -> V_14 , V_15 , V_21 ) )
goto F_118;
V_160 -> V_44 = F_15 ( V_2 , V_15 ) ;
F_166 ( V_2 , V_160 ) ;
V_160 -> V_13 = V_127 ;
F_42 ( V_3 ) ;
return V_15 ;
}
static T_2 void * F_194 ( struct V_1 * V_2 ,
T_5 V_211 , int V_13 , unsigned long V_21 )
{
void * * V_15 ;
struct V_159 * V_160 ;
unsigned long V_178 ;
if ( F_75 ( V_2 , V_211 ) )
return NULL ;
V_194:
V_160 = F_190 ( V_2 -> V_9 ) ;
V_178 = V_160 -> V_178 ;
F_195 () ;
V_15 = V_160 -> V_44 ;
if ( F_3 ( ! V_15 || ! F_178 ( V_160 , V_13 ) ) )
V_15 = F_192 ( V_2 , V_211 , V_13 , V_21 , V_160 ) ;
else {
void * V_224 = F_18 ( V_2 , V_15 ) ;
if ( F_3 ( ! F_196 (
V_2 -> V_9 -> V_44 , V_2 -> V_9 -> V_178 ,
V_15 , V_178 ,
V_224 , F_156 ( V_178 ) ) ) ) {
F_160 ( L_68 , V_2 , V_178 ) ;
goto V_194;
}
F_16 ( V_2 , V_224 ) ;
F_8 ( V_2 , V_225 ) ;
}
if ( F_3 ( V_211 & V_226 ) && V_15 )
memset ( V_15 , 0 , V_2 -> V_24 ) ;
F_79 ( V_2 , V_211 , V_15 ) ;
return V_15 ;
}
void * F_197 ( struct V_1 * V_2 , T_5 V_211 )
{
void * V_227 = F_194 ( V_2 , V_211 , V_127 , V_228 ) ;
F_198 ( V_228 , V_227 , V_2 -> V_24 , V_2 -> V_18 , V_211 ) ;
return V_227 ;
}
void * F_199 ( struct V_1 * V_2 , T_5 V_211 , T_1 V_18 )
{
void * V_227 = F_194 ( V_2 , V_211 , V_127 , V_228 ) ;
F_200 ( V_228 , V_227 , V_18 , V_2 -> V_18 , V_211 ) ;
return V_227 ;
}
void * F_201 ( T_1 V_18 , T_5 V_3 , unsigned int V_28 )
{
void * V_227 = F_202 ( V_18 , V_3 , V_28 ) ;
F_200 ( V_228 , V_227 , V_18 , V_30 << V_28 , V_3 ) ;
return V_227 ;
}
void * F_203 ( struct V_1 * V_2 , T_5 V_211 , int V_13 )
{
void * V_227 = F_194 ( V_2 , V_211 , V_13 , V_228 ) ;
F_204 ( V_228 , V_227 ,
V_2 -> V_24 , V_2 -> V_18 , V_211 , V_13 ) ;
return V_227 ;
}
void * F_205 ( struct V_1 * V_2 ,
T_5 V_211 ,
int V_13 , T_1 V_18 )
{
void * V_227 = F_194 ( V_2 , V_211 , V_13 , V_228 ) ;
F_206 ( V_228 , V_227 ,
V_18 , V_2 -> V_18 , V_211 , V_13 ) ;
return V_227 ;
}
static void F_207 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_32 , unsigned long V_21 )
{
void * V_193 ;
void * * V_15 = ( void * ) V_32 ;
int V_229 ;
int V_27 ;
struct V_14 V_158 ;
unsigned long V_45 ;
struct V_12 * V_40 = NULL ;
unsigned long V_230 ( V_3 ) ;
F_8 ( V_2 , V_231 ) ;
if ( F_1 ( V_2 ) && ! F_102 ( V_2 , V_14 , V_32 , V_21 ) )
return;
do {
V_193 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
F_21 ( V_2 , V_15 , V_193 ) ;
V_158 . V_45 = V_45 ;
V_229 = V_158 . V_145 ;
V_158 . V_27 -- ;
if ( ( ! V_158 . V_27 || ! V_193 ) && ! V_229 && ! V_40 ) {
if ( ! F_1 ( V_2 ) && ! V_193 )
V_158 . V_145 = 1 ;
else {
V_40 = F_12 ( V_2 , F_120 ( V_14 ) ) ;
F_182 ( & V_40 -> V_162 , V_3 ) ;
}
}
V_27 = V_158 . V_27 ;
} while ( ! F_40 ( V_2 , V_14 ,
V_193 , V_45 ,
V_15 , V_158 . V_45 ,
L_69 ) );
if ( F_173 ( ! V_40 ) ) {
if ( V_158 . V_145 && ! V_229 ) {
F_141 ( V_2 , V_14 , 1 ) ;
F_8 ( V_2 , V_232 ) ;
}
if ( V_229 )
F_8 ( V_2 , V_233 ) ;
return;
}
if ( V_229 )
F_8 ( V_2 , V_233 ) ;
else {
if ( F_3 ( ! V_27 && V_40 -> V_154 > V_2 -> V_176 ) )
goto V_234;
if ( F_3 ( ! V_193 ) ) {
F_89 ( V_2 , V_14 ) ;
F_134 ( V_40 , V_14 , V_155 ) ;
F_8 ( V_2 , V_202 ) ;
}
}
F_184 ( & V_40 -> V_162 , V_3 ) ;
return;
V_234:
if ( V_193 ) {
F_136 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_201 ) ;
} else
F_89 ( V_2 , V_14 ) ;
F_184 ( & V_40 -> V_162 , V_3 ) ;
F_8 ( V_2 , V_197 ) ;
F_133 ( V_2 , V_14 ) ;
}
static T_2 void F_208 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_32 , unsigned long V_21 )
{
void * * V_15 = ( void * ) V_32 ;
struct V_159 * V_160 ;
unsigned long V_178 ;
F_82 ( V_2 , V_32 ) ;
V_194:
V_160 = F_190 ( V_2 -> V_9 ) ;
V_178 = V_160 -> V_178 ;
F_195 () ;
if ( F_173 ( V_14 == V_160 -> V_14 ) ) {
F_21 ( V_2 , V_15 , V_160 -> V_44 ) ;
if ( F_3 ( ! F_196 (
V_2 -> V_9 -> V_44 , V_2 -> V_9 -> V_178 ,
V_160 -> V_44 , V_178 ,
V_15 , F_156 ( V_178 ) ) ) ) {
F_160 ( L_70 , V_2 , V_178 ) ;
goto V_194;
}
F_8 ( V_2 , V_235 ) ;
} else
F_207 ( V_2 , V_14 , V_32 , V_21 ) ;
}
void F_209 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_14 ;
V_14 = F_129 ( V_32 ) ;
F_208 ( V_2 , V_14 , V_32 , V_228 ) ;
F_210 ( V_228 , V_32 ) ;
}
static inline int F_211 ( int V_18 , int V_236 ,
int V_237 , int V_238 , int V_29 )
{
int V_28 ;
int V_239 ;
int V_240 = V_241 ;
if ( F_24 ( V_240 , V_18 , V_29 ) > V_100 )
return F_187 ( V_18 * V_100 ) - 1 ;
for ( V_28 = F_212 ( V_240 ,
F_213 ( V_236 * V_18 - 1 ) - V_242 ) ;
V_28 <= V_237 ; V_28 ++ ) {
unsigned long V_243 = V_30 << V_28 ;
if ( V_243 < V_236 * V_18 + V_29 )
continue;
V_239 = ( V_243 - V_29 ) % V_18 ;
if ( V_239 <= V_243 / V_238 )
break;
}
return V_28 ;
}
static inline int F_214 ( int V_18 , int V_29 )
{
int V_28 ;
int V_236 ;
int V_244 ;
int V_99 ;
V_236 = V_245 ;
if ( ! V_236 )
V_236 = 4 * ( F_213 ( V_246 ) + 1 ) ;
V_99 = F_24 ( V_247 , V_18 , V_29 ) ;
V_236 = V_133 ( V_236 , V_99 ) ;
while ( V_236 > 1 ) {
V_244 = 16 ;
while ( V_244 >= 4 ) {
V_28 = F_211 ( V_18 , V_236 ,
V_247 , V_244 , V_29 ) ;
if ( V_28 <= V_247 )
return V_28 ;
V_244 /= 2 ;
}
V_236 -- ;
}
V_28 = F_211 ( V_18 , 1 , V_247 , 1 , V_29 ) ;
if ( V_28 <= V_247 )
return V_28 ;
V_28 = F_211 ( V_18 , 1 , V_248 , 1 , V_29 ) ;
if ( V_28 < V_248 )
return V_28 ;
return - V_249 ;
}
static unsigned long F_215 ( unsigned long V_3 ,
unsigned long V_250 , unsigned long V_18 )
{
if ( V_3 & V_251 ) {
unsigned long V_252 = F_216 () ;
while ( V_18 <= V_252 / 2 )
V_252 /= 2 ;
V_250 = F_212 ( V_250 , V_252 ) ;
}
if ( V_250 < V_253 )
V_250 = V_253 ;
return F_217 ( V_250 , sizeof( void * ) ) ;
}
static void
F_218 ( struct V_12 * V_40 )
{
V_40 -> V_154 = 0 ;
F_219 ( & V_40 -> V_162 ) ;
F_220 ( & V_40 -> V_156 ) ;
#ifdef F_2
F_221 ( & V_40 -> V_109 , 0 ) ;
F_221 ( & V_40 -> V_110 , 0 ) ;
F_220 ( & V_40 -> V_108 ) ;
#endif
}
static inline int F_222 ( struct V_1 * V_2 )
{
F_223 ( V_254 <
V_255 * sizeof( struct V_159 ) ) ;
V_2 -> V_9 = F_224 ( sizeof( struct V_159 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_163 ( V_2 ) ;
return 1 ;
}
static void F_225 ( int V_13 )
{
struct V_14 * V_14 ;
struct V_12 * V_40 ;
F_119 ( V_12 -> V_18 < sizeof( struct V_12 ) ) ;
V_14 = F_118 ( V_12 , V_256 , V_13 ) ;
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
V_14 -> V_145 = 0 ;
V_12 -> V_13 [ V_13 ] = V_40 ;
#ifdef F_2
F_64 ( V_12 , V_40 , V_95 ) ;
F_52 ( V_12 , V_40 ) ;
#endif
F_218 ( V_40 ) ;
F_94 ( V_12 , V_13 , V_14 -> V_17 ) ;
F_134 ( V_40 , V_14 , V_190 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
int V_13 ;
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = V_2 -> V_13 [ V_13 ] ;
if ( V_40 )
F_209 ( V_12 , V_40 ) ;
V_2 -> V_13 [ V_13 ] = NULL ;
}
}
static int F_228 ( struct V_1 * V_2 )
{
int V_13 ;
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 ;
if ( V_10 == V_257 ) {
F_225 ( V_13 ) ;
continue;
}
V_40 = F_203 ( V_12 ,
V_258 , V_13 ) ;
if ( ! V_40 ) {
F_226 ( V_2 ) ;
return 0 ;
}
V_2 -> V_13 [ V_13 ] = V_40 ;
F_218 ( V_40 ) ;
}
return 1 ;
}
static void F_229 ( struct V_1 * V_2 , unsigned long V_133 )
{
if ( V_133 < V_259 )
V_133 = V_259 ;
else if ( V_133 > V_260 )
V_133 = V_260 ;
V_2 -> V_176 = V_133 ;
}
static int F_230 ( struct V_1 * V_2 , int V_261 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_18 = V_2 -> V_24 ;
unsigned long V_250 = V_2 -> V_250 ;
int V_28 ;
V_18 = F_217 ( V_18 , sizeof( void * ) ) ;
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
V_250 = F_215 ( V_3 , V_250 , V_2 -> V_24 ) ;
V_2 -> V_250 = V_250 ;
V_18 = F_217 ( V_18 , V_250 ) ;
V_2 -> V_18 = V_18 ;
if ( V_261 >= 0 )
V_28 = V_261 ;
else
V_28 = F_214 ( V_18 , V_2 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
V_2 -> V_129 = 0 ;
if ( V_28 )
V_2 -> V_129 |= V_262 ;
if ( V_2 -> V_3 & V_263 )
V_2 -> V_129 |= V_264 ;
if ( V_2 -> V_3 & V_138 )
V_2 -> V_129 |= V_265 ;
V_2 -> V_125 = F_25 ( V_28 , V_18 , V_2 -> V_29 ) ;
V_2 -> V_133 = F_25 ( F_187 ( V_18 ) , V_18 , V_2 -> V_29 ) ;
if ( F_27 ( V_2 -> V_125 ) > F_27 ( V_2 -> F_212 ) )
V_2 -> F_212 = V_2 -> V_125 ;
return ! ! F_27 ( V_2 -> V_125 ) ;
}
static int F_231 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_18 ,
T_1 V_250 , unsigned long V_3 ,
void (* F_105)( void * ) )
{
memset ( V_2 , 0 , V_266 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_105 = F_105 ;
V_2 -> V_24 = V_18 ;
V_2 -> V_250 = V_250 ;
V_2 -> V_3 = F_104 ( V_18 , V_3 , V_6 , F_105 ) ;
V_2 -> V_29 = 0 ;
if ( V_150 && ( V_2 -> V_3 & V_25 ) )
V_2 -> V_29 = sizeof( struct V_148 ) ;
if ( ! F_230 ( V_2 , - 1 ) )
goto error;
if ( V_121 ) {
if ( F_187 ( V_2 -> V_18 ) > F_187 ( V_2 -> V_24 ) ) {
V_2 -> V_3 &= ~ V_267 ;
V_2 -> V_19 = 0 ;
if ( ! F_230 ( V_2 , - 1 ) )
goto error;
}
}
#if F_35 ( V_41 ) && \
F_35 ( V_42 )
if ( F_232 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_43 ;
#endif
F_229 ( V_2 , F_233 ( V_2 -> V_18 ) / 2 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_166 = 0 ;
else if ( V_2 -> V_18 >= V_30 )
V_2 -> V_166 = 2 ;
else if ( V_2 -> V_18 >= 1024 )
V_2 -> V_166 = 6 ;
else if ( V_2 -> V_18 >= 256 )
V_2 -> V_166 = 13 ;
else
V_2 -> V_166 = 30 ;
V_2 -> V_268 = 1 ;
#ifdef F_144
V_2 -> V_174 = 1000 ;
#endif
if ( ! F_228 ( V_2 ) )
goto error;
if ( F_222 ( V_2 ) )
return 1 ;
F_226 ( V_2 ) ;
error:
if ( V_3 & V_269 )
F_234 ( L_75
L_76 ,
V_2 -> V_6 , ( unsigned long ) V_18 , V_2 -> V_18 , F_26 ( V_2 -> V_125 ) ,
V_2 -> V_19 , V_3 ) ;
return 0 ;
}
unsigned int F_235 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
static void F_236 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const char * V_49 )
{
#ifdef F_2
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
unsigned long * V_48 = F_237 ( F_238 ( V_14 -> V_17 ) *
sizeof( long ) , V_210 ) ;
if ( ! V_48 )
return;
F_63 ( V_2 , V_14 , L_18 , V_49 ) ;
F_28 ( V_14 ) ;
F_43 ( V_2 , V_14 , V_48 ) ;
F_122 (p, s, addr, page->objects) {
if ( ! F_239 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) ) {
F_39 ( V_51 L_77 ,
V_5 , V_5 - V_21 ) ;
F_54 ( V_2 , V_5 ) ;
}
}
F_30 ( V_14 ) ;
F_7 ( V_48 ) ;
#endif
}
static void F_240 ( struct V_1 * V_2 , struct V_12 * V_40 )
{
struct V_14 * V_14 , * V_149 ;
F_140 (page, h, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_136 ( V_40 , V_14 ) ;
F_133 ( V_2 , V_14 ) ;
} else {
F_236 ( V_2 , V_14 ,
L_78 ) ;
}
}
}
static inline int F_241 ( struct V_1 * V_2 )
{
int V_13 ;
F_176 ( V_2 ) ;
F_242 ( V_2 -> V_9 ) ;
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_240 ( V_2 , V_40 ) ;
if ( V_40 -> V_154 || F_91 ( V_2 , V_13 ) )
return 1 ;
}
F_226 ( V_2 ) ;
return 0 ;
}
void F_243 ( struct V_1 * V_2 )
{
F_244 ( & V_270 ) ;
V_2 -> V_268 -- ;
if ( ! V_2 -> V_268 ) {
F_90 ( & V_2 -> V_271 ) ;
F_245 ( & V_270 ) ;
if ( F_241 ( V_2 ) ) {
F_39 ( V_51 L_79
L_80 , V_2 -> V_6 , V_272 ) ;
F_61 () ;
}
if ( V_2 -> V_3 & V_25 )
F_246 () ;
F_6 ( V_2 ) ;
} else
F_245 ( & V_270 ) ;
}
static int T_7 F_247 ( char * V_117 )
{
F_248 ( & V_117 , & V_241 ) ;
return 1 ;
}
static int T_7 F_249 ( char * V_117 )
{
F_248 ( & V_117 , & V_247 ) ;
V_247 = V_133 ( V_247 , V_248 - 1 ) ;
return 1 ;
}
static int T_7 F_250 ( char * V_117 )
{
F_248 ( & V_117 , & V_245 ) ;
return 1 ;
}
static int T_7 F_251 ( char * V_117 )
{
V_273 = 1 ;
return 1 ;
}
static struct V_1 * T_7 F_252 ( const char * V_6 ,
int V_18 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_197 ( V_1 , V_256 ) ;
if ( ! F_231 ( V_2 , V_6 , V_18 , V_274 ,
V_3 , NULL ) )
goto F_234;
F_88 ( & V_2 -> V_271 , & V_275 ) ;
return V_2 ;
F_234:
F_234 ( L_81 , V_6 , V_18 ) ;
return NULL ;
}
static inline int F_253 ( T_1 V_89 )
{
return ( V_89 - 1 ) / 8 ;
}
static struct V_1 * F_254 ( T_1 V_18 , T_5 V_3 )
{
int V_276 ;
if ( V_18 <= 192 ) {
if ( ! V_18 )
return V_277 ;
V_276 = V_278 [ F_253 ( V_18 ) ] ;
} else
V_276 = F_213 ( V_18 - 1 ) ;
#ifdef F_255
if ( F_3 ( ( V_3 & V_264 ) ) )
return V_279 [ V_276 ] ;
#endif
return V_280 [ V_276 ] ;
}
void * F_256 ( T_1 V_18 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_227 ;
if ( F_3 ( V_18 > V_281 ) )
return F_257 ( V_18 , V_3 ) ;
V_2 = F_254 ( V_18 , V_3 ) ;
if ( F_3 ( F_258 ( V_2 ) ) )
return V_2 ;
V_227 = F_194 ( V_2 , V_3 , V_127 , V_228 ) ;
F_200 ( V_228 , V_227 , V_18 , V_2 -> V_18 , V_3 ) ;
return V_227 ;
}
static void * F_259 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_282 = NULL ;
V_3 |= V_262 | V_126 ;
V_14 = F_260 ( V_13 , V_3 , F_187 ( V_18 ) ) ;
if ( V_14 )
V_282 = F_14 ( V_14 ) ;
F_261 ( V_282 , V_18 , 1 , V_3 ) ;
return V_282 ;
}
void * F_262 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_1 * V_2 ;
void * V_227 ;
if ( F_3 ( V_18 > V_281 ) ) {
V_227 = F_259 ( V_18 , V_3 , V_13 ) ;
F_206 ( V_228 , V_227 ,
V_18 , V_30 << F_187 ( V_18 ) ,
V_3 , V_13 ) ;
return V_227 ;
}
V_2 = F_254 ( V_18 , V_3 ) ;
if ( F_3 ( F_258 ( V_2 ) ) )
return V_2 ;
V_227 = F_194 ( V_2 , V_3 , V_13 , V_228 ) ;
F_206 ( V_228 , V_227 , V_18 , V_2 -> V_18 , V_3 , V_13 ) ;
return V_227 ;
}
T_1 F_263 ( const void * V_15 )
{
struct V_14 * V_14 ;
if ( F_3 ( V_15 == V_277 ) )
return 0 ;
V_14 = F_129 ( V_15 ) ;
if ( F_3 ( ! F_73 ( V_14 ) ) ) {
F_264 ( ! F_265 ( V_14 ) ) ;
return V_30 << F_70 ( V_14 ) ;
}
return F_23 ( V_14 -> V_116 ) ;
}
bool F_266 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
unsigned long V_3 ;
bool V_283 ;
if ( F_3 ( F_258 ( V_32 ) ) )
return false ;
F_41 ( V_3 ) ;
V_14 = F_129 ( V_32 ) ;
if ( F_3 ( ! F_73 ( V_14 ) ) ) {
V_283 = true ;
goto V_284;
}
F_28 ( V_14 ) ;
if ( F_74 ( V_14 -> V_116 , V_14 , V_15 ) ) {
F_62 ( V_14 -> V_116 , V_14 , V_15 , L_82 ) ;
V_283 = false ;
} else {
V_283 = true ;
}
F_30 ( V_14 ) ;
V_284:
F_42 ( V_3 ) ;
return V_283 ;
}
void F_7 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
F_267 ( V_228 , V_32 ) ;
if ( F_3 ( F_258 ( V_32 ) ) )
return;
V_14 = F_129 ( V_32 ) ;
if ( F_3 ( ! F_73 ( V_14 ) ) ) {
F_119 ( ! F_265 ( V_14 ) ) ;
F_268 ( V_32 ) ;
F_269 ( V_14 ) ;
return;
}
F_208 ( V_14 -> V_116 , V_14 , V_15 , V_228 ) ;
}
int F_270 ( struct V_1 * V_2 )
{
int V_13 ;
int V_58 ;
struct V_12 * V_40 ;
struct V_14 * V_14 ;
struct V_14 * V_73 ;
int V_17 = F_27 ( V_2 -> F_212 ) ;
struct V_151 * V_285 =
F_271 ( sizeof( struct V_151 ) * V_17 , V_258 ) ;
unsigned long V_3 ;
if ( ! V_285 )
return - V_286 ;
F_176 ( V_2 ) ;
F_227 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 -> V_154 )
continue;
for ( V_58 = 0 ; V_58 < V_17 ; V_58 ++ )
F_220 ( V_285 + V_58 ) ;
F_182 ( & V_40 -> V_162 , V_3 ) ;
F_140 (page, t, &n->partial, lru) {
F_272 ( & V_14 -> V_107 , V_285 + V_14 -> V_27 ) ;
if ( ! V_14 -> V_27 )
V_40 -> V_154 -- ;
}
for ( V_58 = V_17 - 1 ; V_58 > 0 ; V_58 -- )
F_273 ( V_285 + V_58 , V_40 -> V_156 . V_287 ) ;
F_184 ( & V_40 -> V_162 , V_3 ) ;
F_140 (page, t, slabs_by_inuse, lru)
F_133 ( V_2 , V_14 ) ;
}
F_7 ( V_285 ) ;
return 0 ;
}
static int F_274 ( void * V_288 )
{
struct V_1 * V_2 ;
F_275 ( & V_270 ) ;
F_183 (s, &slab_caches, list)
F_270 ( V_2 ) ;
F_276 ( & V_270 ) ;
return 0 ;
}
static void F_277 ( void * V_288 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_289 * V_290 = V_288 ;
int V_291 ;
V_291 = V_290 -> V_292 ;
if ( V_291 < 0 )
return;
F_275 ( & V_270 ) ;
F_183 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_291 ) ;
if ( V_40 ) {
F_119 ( F_91 ( V_2 , V_291 ) ) ;
V_2 -> V_13 [ V_291 ] = NULL ;
F_209 ( V_12 , V_40 ) ;
}
}
F_276 ( & V_270 ) ;
}
static int F_278 ( void * V_288 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_289 * V_290 = V_288 ;
int V_212 = V_290 -> V_292 ;
int V_227 = 0 ;
if ( V_212 < 0 )
return 0 ;
F_275 ( & V_270 ) ;
F_183 (s, &slab_caches, list) {
V_40 = F_197 ( V_12 , V_258 ) ;
if ( ! V_40 ) {
V_227 = - V_286 ;
goto V_115;
}
F_218 ( V_40 ) ;
V_2 -> V_13 [ V_212 ] = V_40 ;
}
V_115:
F_276 ( & V_270 ) ;
return V_227 ;
}
static int F_279 ( struct V_293 * V_294 ,
unsigned long V_295 , void * V_288 )
{
int V_227 = 0 ;
switch ( V_295 ) {
case V_296 :
V_227 = F_278 ( V_288 ) ;
break;
case V_297 :
V_227 = F_274 ( V_288 ) ;
break;
case V_298 :
case V_299 :
F_277 ( V_288 ) ;
break;
case V_300 :
case V_301 :
break;
}
if ( V_227 )
V_227 = F_280 ( V_227 ) ;
else
V_227 = V_302 ;
return V_227 ;
}
static void T_7 F_281 ( struct V_1 * V_2 )
{
int V_13 ;
F_88 ( & V_2 -> V_271 , & V_275 ) ;
V_2 -> V_268 = - 1 ;
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
struct V_14 * V_5 ;
if ( V_40 ) {
F_183 (p, &n->partial, lru)
V_5 -> V_116 = V_2 ;
#ifdef F_2
F_183 (p, &n->full, lru)
V_5 -> V_116 = V_2 ;
#endif
}
}
}
void T_7 F_282 ( void )
{
int V_58 ;
int V_303 = 0 ;
struct V_1 * V_304 ;
int V_28 ;
struct V_1 * V_305 ;
unsigned long V_306 ;
if ( F_283 () )
V_247 = 0 ;
V_266 = F_284 ( struct V_1 , V_13 ) +
V_307 * sizeof( struct V_12 * ) ;
V_306 = F_217 ( V_266 , F_216 () ) ;
V_28 = F_187 ( 2 * V_306 ) ;
V_1 = ( void * ) F_285 ( V_256 , V_28 ) ;
V_12 = ( void * ) V_1 + V_306 ;
F_231 ( V_12 , L_83 ,
sizeof( struct V_12 ) ,
0 , V_251 | V_269 , NULL ) ;
F_286 ( F_279 , V_308 ) ;
V_10 = V_309 ;
V_304 = V_1 ;
F_231 ( V_1 , L_84 , V_266 ,
0 , V_251 | V_269 , NULL ) ;
V_1 = F_197 ( V_1 , V_256 ) ;
memcpy ( V_1 , V_304 , V_266 ) ;
V_305 = V_12 ;
V_12 = F_197 ( V_1 , V_256 ) ;
memcpy ( V_12 , V_305 , V_266 ) ;
F_281 ( V_12 ) ;
V_303 ++ ;
F_281 ( V_1 ) ;
V_303 ++ ;
F_287 ( ( unsigned long ) V_304 , V_28 ) ;
F_223 ( V_310 > 256 ||
( V_310 & ( V_310 - 1 ) ) ) ;
for ( V_58 = 8 ; V_58 < V_310 ; V_58 += 8 ) {
int V_311 = F_253 ( V_58 ) ;
if ( V_311 >= F_288 ( V_278 ) )
break;
V_278 [ V_311 ] = V_312 ;
}
if ( V_310 == 64 ) {
for ( V_58 = 64 + 8 ; V_58 <= 96 ; V_58 += 8 )
V_278 [ F_253 ( V_58 ) ] = 7 ;
} else if ( V_310 == 128 ) {
for ( V_58 = 128 + 8 ; V_58 <= 192 ; V_58 += 8 )
V_278 [ F_253 ( V_58 ) ] = 8 ;
}
if ( V_310 <= 32 ) {
V_280 [ 1 ] = F_252 ( L_85 , 96 , 0 ) ;
V_303 ++ ;
}
if ( V_310 <= 64 ) {
V_280 [ 2 ] = F_252 ( L_86 , 192 , 0 ) ;
V_303 ++ ;
}
for ( V_58 = V_312 ; V_58 < V_255 ; V_58 ++ ) {
V_280 [ V_58 ] = F_252 ( L_87 , 1 << V_58 , 0 ) ;
V_303 ++ ;
}
V_10 = V_11 ;
if ( V_310 <= 32 ) {
V_280 [ 1 ] -> V_6 = F_289 ( V_280 [ 1 ] -> V_6 , V_256 ) ;
F_119 ( ! V_280 [ 1 ] -> V_6 ) ;
}
if ( V_310 <= 64 ) {
V_280 [ 2 ] -> V_6 = F_289 ( V_280 [ 2 ] -> V_6 , V_256 ) ;
F_119 ( ! V_280 [ 2 ] -> V_6 ) ;
}
for ( V_58 = V_312 ; V_58 < V_255 ; V_58 ++ ) {
char * V_2 = F_290 ( V_256 , L_88 , 1 << V_58 ) ;
F_119 ( ! V_2 ) ;
V_280 [ V_58 ] -> V_6 = V_2 ;
}
#ifdef F_291
F_292 ( & V_313 ) ;
#endif
#ifdef F_255
for ( V_58 = 0 ; V_58 < V_255 ; V_58 ++ ) {
struct V_1 * V_2 = V_280 [ V_58 ] ;
if ( V_2 && V_2 -> V_18 ) {
char * V_6 = F_290 ( V_256 ,
L_89 , V_2 -> V_24 ) ;
F_119 ( ! V_6 ) ;
V_279 [ V_58 ] = F_252 ( V_6 ,
V_2 -> V_24 , V_263 ) ;
}
}
#endif
F_39 ( V_47
L_90
L_91 ,
V_303 , F_216 () ,
V_241 , V_247 , V_245 ,
V_246 , V_307 ) ;
}
void T_7 F_293 ( void )
{
}
static int F_294 ( struct V_1 * V_2 )
{
if ( V_273 || ( V_2 -> V_3 & V_314 ) )
return 1 ;
if ( V_2 -> F_105 )
return 1 ;
if ( V_2 -> V_268 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_295 ( T_1 V_18 ,
T_1 V_250 , unsigned long V_3 , const char * V_6 ,
void (* F_105)( void * ) )
{
struct V_1 * V_2 ;
if ( V_273 || ( V_3 & V_314 ) )
return NULL ;
if ( F_105 )
return NULL ;
V_18 = F_217 ( V_18 , sizeof( void * ) ) ;
V_250 = F_215 ( V_3 , V_250 , V_18 ) ;
V_18 = F_217 ( V_18 , V_250 ) ;
V_3 = F_104 ( V_18 , V_3 , V_6 , NULL ) ;
F_183 (s, &slab_caches, list) {
if ( F_294 ( V_2 ) )
continue;
if ( V_18 > V_2 -> V_18 )
continue;
if ( ( V_3 & V_315 ) != ( V_2 -> V_3 & V_315 ) )
continue;
if ( ( V_2 -> V_18 & ~ ( V_250 - 1 ) ) != V_2 -> V_18 )
continue;
if ( V_2 -> V_18 - V_18 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_296 ( const char * V_6 , T_1 V_18 ,
T_1 V_250 , unsigned long V_3 , void (* F_105)( void * ) )
{
struct V_1 * V_2 ;
char * V_40 ;
if ( F_264 ( ! V_6 ) )
return NULL ;
F_244 ( & V_270 ) ;
V_2 = F_295 ( V_18 , V_250 , V_3 , V_6 , F_105 ) ;
if ( V_2 ) {
V_2 -> V_268 ++ ;
V_2 -> V_24 = F_212 ( V_2 -> V_24 , ( int ) V_18 ) ;
V_2 -> V_27 = F_297 ( int , V_2 -> V_27 , F_217 ( V_18 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_268 -- ;
goto V_316;
}
F_245 ( & V_270 ) ;
return V_2 ;
}
V_40 = F_289 ( V_6 , V_258 ) ;
if ( ! V_40 )
goto V_316;
V_2 = F_271 ( V_266 , V_258 ) ;
if ( V_2 ) {
if ( F_231 ( V_2 , V_40 ,
V_18 , V_250 , V_3 , F_105 ) ) {
F_88 ( & V_2 -> V_271 , & V_275 ) ;
F_245 ( & V_270 ) ;
if ( F_4 ( V_2 ) ) {
F_244 ( & V_270 ) ;
F_90 ( & V_2 -> V_271 ) ;
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
goto V_316;
}
return V_2 ;
}
F_7 ( V_2 ) ;
}
F_7 ( V_40 ) ;
V_316:
F_245 ( & V_270 ) ;
if ( V_3 & V_269 )
F_234 ( L_92 , V_6 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int T_9 F_298 ( struct V_293 * V_317 ,
unsigned long V_295 , void * V_318 )
{
long V_66 = ( long ) V_318 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_295 ) {
case V_319 :
case V_320 :
case V_321 :
case V_322 :
F_275 ( & V_270 ) ;
F_183 (s, &slab_caches, list) {
F_41 ( V_3 ) ;
F_172 ( V_2 , V_66 ) ;
F_42 ( V_3 ) ;
}
F_276 ( & V_270 ) ;
break;
default:
break;
}
return V_302 ;
}
void * F_299 ( T_1 V_18 , T_5 V_211 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_227 ;
if ( F_3 ( V_18 > V_281 ) )
return F_257 ( V_18 , V_211 ) ;
V_2 = F_254 ( V_18 , V_211 ) ;
if ( F_3 ( F_258 ( V_2 ) ) )
return V_2 ;
V_227 = F_194 ( V_2 , V_211 , V_127 , V_323 ) ;
F_200 ( V_323 , V_227 , V_18 , V_2 -> V_18 , V_211 ) ;
return V_227 ;
}
void * F_300 ( T_1 V_18 , T_5 V_211 ,
int V_13 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_227 ;
if ( F_3 ( V_18 > V_281 ) ) {
V_227 = F_259 ( V_18 , V_211 , V_13 ) ;
F_206 ( V_323 , V_227 ,
V_18 , V_30 << F_187 ( V_18 ) ,
V_211 , V_13 ) ;
return V_227 ;
}
V_2 = F_254 ( V_18 , V_211 ) ;
if ( F_3 ( F_258 ( V_2 ) ) )
return V_2 ;
V_227 = F_194 ( V_2 , V_211 , V_13 , V_323 ) ;
F_206 ( V_323 , V_227 , V_18 , V_2 -> V_18 , V_211 , V_13 ) ;
return V_227 ;
}
static int F_301 ( struct V_14 * V_14 )
{
return V_14 -> V_27 ;
}
static int F_302 ( struct V_14 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_303 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_48 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
if ( ! F_72 ( V_2 , V_14 ) ||
! F_74 ( V_2 , V_14 , NULL ) )
return 0 ;
F_304 ( V_48 , V_14 -> V_17 ) ;
F_43 ( V_2 , V_14 , V_48 ) ;
F_122 (p, s, addr, page->objects) {
if ( F_239 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) )
if ( ! F_71 ( V_2 , V_14 , V_5 , V_111 ) )
return 0 ;
}
F_122 (p, s, addr, page->objects)
if ( ! F_239 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) )
if ( ! F_71 ( V_2 , V_14 , V_5 , V_95 ) )
return 0 ;
return 1 ;
}
static void F_305 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_48 )
{
F_28 ( V_14 ) ;
F_303 ( V_2 , V_14 , V_48 ) ;
F_30 ( V_14 ) ;
}
static int F_306 ( struct V_1 * V_2 ,
struct V_12 * V_40 , unsigned long * V_48 )
{
unsigned long V_324 = 0 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_182 ( & V_40 -> V_162 , V_3 ) ;
F_183 (page, &n->partial, lru) {
F_305 ( V_2 , V_14 , V_48 ) ;
V_324 ++ ;
}
if ( V_324 != V_40 -> V_154 )
F_39 ( V_51 L_93
L_94 , V_2 -> V_6 , V_324 , V_40 -> V_154 ) ;
if ( ! ( V_2 -> V_3 & V_26 ) )
goto V_115;
F_183 (page, &n->full, lru) {
F_305 ( V_2 , V_14 , V_48 ) ;
V_324 ++ ;
}
if ( V_324 != F_92 ( & V_40 -> V_109 ) )
F_39 ( V_51 L_95
L_94 , V_2 -> V_6 , V_324 ,
F_92 ( & V_40 -> V_109 ) ) ;
V_115:
F_184 ( & V_40 -> V_162 , V_3 ) ;
return V_324 ;
}
static long F_307 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_324 = 0 ;
unsigned long * V_48 = F_271 ( F_238 ( F_27 ( V_2 -> F_212 ) ) *
sizeof( unsigned long ) , V_258 ) ;
if ( ! V_48 )
return - V_286 ;
F_176 ( V_2 ) ;
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
V_324 += F_306 ( V_2 , V_40 , V_48 ) ;
}
F_7 ( V_48 ) ;
return V_324 ;
}
static void F_308 ( struct V_325 * V_73 )
{
if ( V_73 -> F_212 )
F_287 ( ( unsigned long ) V_73 -> V_326 ,
F_187 ( sizeof( struct V_327 ) * V_73 -> F_212 ) ) ;
}
static int F_309 ( struct V_325 * V_73 , unsigned long F_212 , T_5 V_3 )
{
struct V_327 * V_187 ;
int V_28 ;
V_28 = F_187 ( sizeof( struct V_327 ) * F_212 ) ;
V_187 = ( void * ) F_285 ( V_3 , V_28 ) ;
if ( ! V_187 )
return 0 ;
if ( V_73 -> V_324 ) {
memcpy ( V_187 , V_73 -> V_326 , sizeof( struct V_327 ) * V_73 -> V_324 ) ;
F_308 ( V_73 ) ;
}
V_73 -> F_212 = F_212 ;
V_73 -> V_326 = V_187 ;
return 1 ;
}
static int F_310 ( struct V_325 * V_73 , struct V_1 * V_2 ,
const struct V_53 * V_53 )
{
long V_87 , V_91 , V_328 ;
struct V_327 * V_187 ;
unsigned long V_329 ;
unsigned long V_330 = V_70 - V_53 -> V_69 ;
V_87 = - 1 ;
V_91 = V_73 -> V_324 ;
for ( ; ; ) {
V_328 = V_87 + ( V_91 - V_87 + 1 ) / 2 ;
if ( V_328 == V_91 )
break;
V_329 = V_73 -> V_326 [ V_328 ] . V_21 ;
if ( V_53 -> V_21 == V_329 ) {
V_187 = & V_73 -> V_326 [ V_328 ] ;
V_187 -> V_324 ++ ;
if ( V_53 -> V_69 ) {
V_187 -> V_331 += V_330 ;
if ( V_330 < V_187 -> V_332 )
V_187 -> V_332 = V_330 ;
if ( V_330 > V_187 -> V_333 )
V_187 -> V_333 = V_330 ;
if ( V_53 -> V_67 < V_187 -> V_334 )
V_187 -> V_334 = V_53 -> V_67 ;
if ( V_53 -> V_67 > V_187 -> V_335 )
V_187 -> V_335 = V_53 -> V_67 ;
F_311 ( V_53 -> V_66 ,
F_312 ( V_187 -> V_336 ) ) ;
}
F_313 ( F_120 ( F_314 ( V_53 ) ) , V_187 -> V_337 ) ;
return 1 ;
}
if ( V_53 -> V_21 < V_329 )
V_91 = V_328 ;
else
V_87 = V_328 ;
}
if ( V_73 -> V_324 >= V_73 -> F_212 && ! F_309 ( V_73 , 2 * V_73 -> F_212 , V_210 ) )
return 0 ;
V_187 = V_73 -> V_326 + V_328 ;
if ( V_328 < V_73 -> V_324 )
memmove ( V_187 + 1 , V_187 ,
( V_73 -> V_324 - V_328 ) * sizeof( struct V_327 ) ) ;
V_73 -> V_324 ++ ;
V_187 -> V_324 = 1 ;
V_187 -> V_21 = V_53 -> V_21 ;
V_187 -> V_331 = V_330 ;
V_187 -> V_332 = V_330 ;
V_187 -> V_333 = V_330 ;
V_187 -> V_334 = V_53 -> V_67 ;
V_187 -> V_335 = V_53 -> V_67 ;
F_315 ( F_312 ( V_187 -> V_336 ) ) ;
F_311 ( V_53 -> V_66 , F_312 ( V_187 -> V_336 ) ) ;
F_316 ( V_187 -> V_337 ) ;
F_313 ( F_120 ( F_314 ( V_53 ) ) , V_187 -> V_337 ) ;
return 1 ;
}
static void F_317 ( struct V_325 * V_73 , struct V_1 * V_2 ,
struct V_14 * V_14 , enum V_54 V_55 ,
unsigned long * V_48 )
{
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
F_304 ( V_48 , V_14 -> V_17 ) ;
F_43 ( V_2 , V_14 , V_48 ) ;
F_122 (p, s, addr, page->objects)
if ( ! F_239 ( F_22 ( V_5 , V_2 , V_21 ) , V_48 ) )
F_310 ( V_73 , V_2 , F_47 ( V_2 , V_5 , V_55 ) ) ;
}
static int F_318 ( struct V_1 * V_2 , char * V_75 ,
enum V_54 V_55 )
{
int V_338 = 0 ;
unsigned long V_58 ;
struct V_325 V_73 = { 0 , 0 , NULL } ;
int V_13 ;
unsigned long * V_48 = F_271 ( F_238 ( F_27 ( V_2 -> F_212 ) ) *
sizeof( unsigned long ) , V_258 ) ;
if ( ! V_48 || ! F_309 ( & V_73 , V_30 / sizeof( struct V_327 ) ,
V_339 ) ) {
F_7 ( V_48 ) ;
return sprintf ( V_75 , L_96 ) ;
}
F_176 ( V_2 ) ;
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_3 ;
struct V_14 * V_14 ;
if ( ! F_92 ( & V_40 -> V_109 ) )
continue;
F_182 ( & V_40 -> V_162 , V_3 ) ;
F_183 (page, &n->partial, lru)
F_317 ( & V_73 , V_2 , V_14 , V_55 , V_48 ) ;
F_183 (page, &n->full, lru)
F_317 ( & V_73 , V_2 , V_14 , V_55 , V_48 ) ;
F_184 ( & V_40 -> V_162 , V_3 ) ;
}
for ( V_58 = 0 ; V_58 < V_73 . V_324 ; V_58 ++ ) {
struct V_327 * V_187 = & V_73 . V_326 [ V_58 ] ;
if ( V_338 > V_30 - V_340 - 100 )
break;
V_338 += sprintf ( V_75 + V_338 , L_97 , V_187 -> V_324 ) ;
if ( V_187 -> V_21 )
V_338 += sprintf ( V_75 + V_338 , L_98 , ( void * ) V_187 -> V_21 ) ;
else
V_338 += sprintf ( V_75 + V_338 , L_99 ) ;
if ( V_187 -> V_331 != V_187 -> V_332 ) {
V_338 += sprintf ( V_75 + V_338 , L_100 ,
V_187 -> V_332 ,
( long ) F_319 ( V_187 -> V_331 , V_187 -> V_324 ) ,
V_187 -> V_333 ) ;
} else
V_338 += sprintf ( V_75 + V_338 , L_101 ,
V_187 -> V_332 ) ;
if ( V_187 -> V_334 != V_187 -> V_335 )
V_338 += sprintf ( V_75 + V_338 , L_102 ,
V_187 -> V_334 , V_187 -> V_335 ) ;
else
V_338 += sprintf ( V_75 + V_338 , L_103 ,
V_187 -> V_334 ) ;
if ( F_320 () > 1 &&
! F_321 ( F_312 ( V_187 -> V_336 ) ) &&
V_338 < V_30 - 60 ) {
V_338 += sprintf ( V_75 + V_338 , L_104 ) ;
V_338 += F_322 ( V_75 + V_338 , V_30 - V_338 - 50 ,
F_312 ( V_187 -> V_336 ) ) ;
}
if ( V_341 > 1 && ! F_323 ( V_187 -> V_337 ) &&
V_338 < V_30 - 60 ) {
V_338 += sprintf ( V_75 + V_338 , L_105 ) ;
V_338 += F_324 ( V_75 + V_338 , V_30 - V_338 - 50 ,
V_187 -> V_337 ) ;
}
V_338 += sprintf ( V_75 + V_338 , L_106 ) ;
}
F_308 ( & V_73 ) ;
F_7 ( V_48 ) ;
if ( ! V_73 . V_324 )
V_338 += sprintf ( V_75 , L_107 ) ;
return V_338 ;
}
static void F_325 ( void )
{
T_3 * V_5 ;
F_223 ( V_310 > 16 || V_255 < 10 ) ;
F_39 ( V_51 L_108 ) ;
F_39 ( V_51 L_109 ) ;
F_39 ( V_51 L_110 ) ;
V_5 = F_237 ( 16 , V_258 ) ;
V_5 [ 16 ] = 0x12 ;
F_39 ( V_51 L_111
L_112 , V_5 + 16 ) ;
F_307 ( V_280 [ 4 ] ) ;
V_5 = F_237 ( 32 , V_258 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_39 ( V_51 L_113
L_114 , V_5 ) ;
F_39 ( V_51
L_115 ) ;
F_307 ( V_280 [ 5 ] ) ;
V_5 = F_237 ( 64 , V_258 ) ;
V_5 += 64 + ( F_146 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_39 ( V_51 L_116 ,
V_5 ) ;
F_39 ( V_51
L_115 ) ;
F_307 ( V_280 [ 6 ] ) ;
F_39 ( V_51 L_117 ) ;
V_5 = F_237 ( 128 , V_258 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_39 ( V_51 L_118 , V_5 ) ;
F_307 ( V_280 [ 7 ] ) ;
V_5 = F_237 ( 256 , V_258 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_39 ( V_51 L_119 ,
V_5 ) ;
F_307 ( V_280 [ 8 ] ) ;
V_5 = F_237 ( 512 , V_258 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_39 ( V_51 L_120 , V_5 ) ;
F_307 ( V_280 [ 9 ] ) ;
}
static void F_325 ( void ) {}
static T_10 F_326 ( struct V_1 * V_2 ,
char * V_75 , unsigned long V_3 )
{
unsigned long V_342 = 0 ;
int V_13 ;
int V_32 ;
unsigned long * V_337 ;
unsigned long * V_343 ;
V_337 = F_237 ( 2 * sizeof( unsigned long ) * V_307 , V_258 ) ;
if ( ! V_337 )
return - V_286 ;
V_343 = V_337 + V_307 ;
if ( V_3 & V_344 ) {
int V_66 ;
F_164 (cpu) {
struct V_159 * V_160 = F_165 ( V_2 -> V_9 , V_66 ) ;
int V_13 = F_327 ( V_160 -> V_13 ) ;
struct V_14 * V_14 ;
if ( V_13 < 0 )
continue;
V_14 = F_327 ( V_160 -> V_14 ) ;
if ( V_14 ) {
if ( V_3 & V_345 )
V_32 = V_14 -> V_17 ;
else if ( V_3 & V_346 )
V_32 = V_14 -> V_27 ;
else
V_32 = 1 ;
V_342 += V_32 ;
V_337 [ V_13 ] += V_32 ;
}
V_14 = V_160 -> V_156 ;
if ( V_14 ) {
V_32 = V_14 -> V_205 ;
V_342 += V_32 ;
V_337 [ V_13 ] += V_32 ;
}
V_343 [ V_13 ] ++ ;
}
}
F_328 () ;
#ifdef F_2
if ( V_3 & V_347 ) {
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_345 )
V_32 = F_92 ( & V_40 -> V_110 ) ;
else if ( V_3 & V_346 )
V_32 = F_92 ( & V_40 -> V_110 ) -
F_180 ( V_40 , F_179 ) ;
else
V_32 = F_92 ( & V_40 -> V_109 ) ;
V_342 += V_32 ;
V_337 [ V_13 ] += V_32 ;
}
} else
#endif
if ( V_3 & V_348 ) {
F_227 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_345 )
V_32 = F_180 ( V_40 , F_302 ) ;
else if ( V_3 & V_346 )
V_32 = F_180 ( V_40 , F_301 ) ;
else
V_32 = V_40 -> V_154 ;
V_342 += V_32 ;
V_337 [ V_13 ] += V_32 ;
}
}
V_32 = sprintf ( V_75 , L_121 , V_342 ) ;
#ifdef F_144
F_227 (node, N_NORMAL_MEMORY)
if ( V_337 [ V_13 ] )
V_32 += sprintf ( V_75 + V_32 , L_122 ,
V_13 , V_337 [ V_13 ] ) ;
#endif
F_329 () ;
F_7 ( V_337 ) ;
return V_32 + sprintf ( V_75 + V_32 , L_106 ) ;
}
static int F_330 ( struct V_1 * V_2 )
{
int V_13 ;
F_188 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
if ( F_92 ( & V_40 -> V_110 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_331 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_18 ) ;
}
static T_10 F_332 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_250 ) ;
}
static T_10 F_333 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_24 ) ;
}
static T_10 F_334 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , F_27 ( V_2 -> V_125 ) ) ;
}
static T_10 F_335 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_28 ;
int V_316 ;
V_316 = F_336 ( V_75 , 10 , & V_28 ) ;
if ( V_316 )
return V_316 ;
if ( V_28 > V_247 || V_28 < V_241 )
return - V_349 ;
F_230 ( V_2 , V_28 ) ;
return V_50 ;
}
static T_10 F_337 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , F_26 ( V_2 -> V_125 ) ) ;
}
static T_10 F_338 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_124 , V_2 -> V_176 ) ;
}
static T_10 F_339 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_133 ;
int V_316 ;
V_316 = F_336 ( V_75 , 10 , & V_133 ) ;
if ( V_316 )
return V_316 ;
F_229 ( V_2 , V_133 ) ;
return V_50 ;
}
static T_10 F_340 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_125 , V_2 -> V_166 ) ;
}
static T_10 F_341 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_17 ;
int V_316 ;
V_316 = F_336 ( V_75 , 10 , & V_17 ) ;
if ( V_316 )
return V_316 ;
if ( V_17 && F_1 ( V_2 ) )
return - V_349 ;
V_2 -> V_166 = V_17 ;
F_176 ( V_2 ) ;
return V_50 ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! V_2 -> F_105 )
return 0 ;
return sprintf ( V_75 , L_126 , V_2 -> F_105 ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_268 - 1 ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_75 )
{
return F_326 ( V_2 , V_75 , V_348 ) ;
}
static T_10 F_345 ( struct V_1 * V_2 , char * V_75 )
{
return F_326 ( V_2 , V_75 , V_344 ) ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_75 )
{
return F_326 ( V_2 , V_75 , V_347 | V_346 ) ;
}
static T_10 F_347 ( struct V_1 * V_2 , char * V_75 )
{
return F_326 ( V_2 , V_75 , V_348 | V_346 ) ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_75 )
{
int V_17 = 0 ;
int V_137 = 0 ;
int V_66 ;
int V_338 ;
F_349 (cpu) {
struct V_14 * V_14 = F_165 ( V_2 -> V_9 , V_66 ) -> V_156 ;
if ( V_14 ) {
V_137 += V_14 -> V_137 ;
V_17 += V_14 -> V_205 ;
}
}
V_338 = sprintf ( V_75 , L_127 , V_17 , V_137 ) ;
#ifdef F_291
F_349 (cpu) {
struct V_14 * V_14 = F_165 ( V_2 -> V_9 , V_66 ) -> V_156 ;
if ( V_14 && V_338 < V_30 - 20 )
V_338 += sprintf ( V_75 + V_338 , L_128 , V_66 ,
V_14 -> V_205 , V_14 -> V_137 ) ;
}
#endif
return V_338 + sprintf ( V_75 + V_338 , L_106 ) ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_138 ) ) ;
}
static T_10 F_351 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_138 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_138 ;
return V_50 ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_251 ) ) ;
}
static T_10 F_353 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_263 ) ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_25 ) ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_29 ) ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_75 )
{
return F_326 ( V_2 , V_75 , V_347 ) ;
}
static T_10 F_357 ( struct V_1 * V_2 , char * V_75 )
{
return F_326 ( V_2 , V_75 , V_347 | V_345 ) ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_122 ) ) ;
}
static T_10 F_359 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_122 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_122 ;
}
return V_50 ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_101 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_101 ;
}
return V_50 ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_363 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_330 ( V_2 ) )
return - V_350 ;
V_2 -> V_3 &= ~ V_22 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_22 ;
}
F_230 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_364 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_365 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_330 ( V_2 ) )
return - V_350 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_23 ;
}
F_230 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_366 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_26 ) ) ;
}
static T_10 F_367 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_330 ( V_2 ) )
return - V_350 ;
V_2 -> V_3 &= ~ V_26 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_26 ;
}
F_230 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_10 F_369 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
int V_227 = - V_349 ;
if ( V_75 [ 0 ] == '1' ) {
V_227 = F_307 ( V_2 ) ;
if ( V_227 >= 0 )
V_227 = V_50 ;
}
return V_227 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_249 ;
return F_318 ( V_2 , V_75 , V_72 ) ;
}
static T_10 F_371 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_249 ;
return F_318 ( V_2 , V_75 , V_71 ) ;
}
static T_10 F_372 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_123 ) ) ;
}
static T_10 F_373 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_123 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_123 ;
return V_50 ;
}
static T_10 F_374 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_10 F_375 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( V_75 [ 0 ] == '1' ) {
int V_113 = F_270 ( V_2 ) ;
if ( V_113 )
return V_113 ;
} else
return - V_349 ;
return V_50 ;
}
static T_10 F_376 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_174 / 10 ) ;
}
static T_10 F_377 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_351 ;
int V_316 ;
V_316 = F_336 ( V_75 , 10 , & V_351 ) ;
if ( V_316 )
return V_316 ;
if ( V_351 <= 100 )
V_2 -> V_174 = V_351 * 10 ;
return V_50 ;
}
static int F_378 ( struct V_1 * V_2 , char * V_75 , enum V_7 V_8 )
{
unsigned long V_352 = 0 ;
int V_66 ;
int V_338 ;
int * V_83 = F_271 ( V_246 * sizeof( int ) , V_258 ) ;
if ( ! V_83 )
return - V_286 ;
F_349 (cpu) {
unsigned V_32 = F_165 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] ;
V_83 [ V_66 ] = V_32 ;
V_352 += V_32 ;
}
V_338 = sprintf ( V_75 , L_121 , V_352 ) ;
#ifdef F_291
F_349 (cpu) {
if ( V_83 [ V_66 ] && V_338 < V_30 - 20 )
V_338 += sprintf ( V_75 + V_338 , L_129 , V_66 , V_83 [ V_66 ] ) ;
}
#endif
F_7 ( V_83 ) ;
return V_338 + sprintf ( V_75 + V_338 , L_106 ) ;
}
static void F_379 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_66 ;
F_349 (cpu)
F_165 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] = 0 ;
}
static T_10 F_380 ( struct V_353 * V_354 ,
struct V_355 * V_356 ,
char * V_75 )
{
struct V_357 * V_355 ;
struct V_1 * V_2 ;
int V_316 ;
V_355 = F_381 ( V_356 ) ;
V_2 = F_382 ( V_354 ) ;
if ( ! V_355 -> V_358 )
return - V_359 ;
V_316 = V_355 -> V_358 ( V_2 , V_75 ) ;
return V_316 ;
}
static T_10 F_383 ( struct V_353 * V_354 ,
struct V_355 * V_356 ,
const char * V_75 , T_1 V_338 )
{
struct V_357 * V_355 ;
struct V_1 * V_2 ;
int V_316 ;
V_355 = F_381 ( V_356 ) ;
V_2 = F_382 ( V_354 ) ;
if ( ! V_355 -> V_360 )
return - V_359 ;
V_316 = V_355 -> V_360 ( V_2 , V_75 , V_338 ) ;
return V_316 ;
}
static void F_384 ( struct V_353 * V_354 )
{
struct V_1 * V_2 = F_382 ( V_354 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_385 ( struct V_361 * V_361 , struct V_353 * V_354 )
{
struct V_362 * V_363 = F_386 ( V_354 ) ;
if ( V_363 == & V_364 )
return 1 ;
return 0 ;
}
static char * F_387 ( struct V_1 * V_2 )
{
char * V_6 = F_271 ( V_365 , V_258 ) ;
char * V_5 = V_6 ;
F_119 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_263 )
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
F_119 ( V_5 > V_6 + V_365 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_316 ;
const char * V_6 ;
int V_366 ;
if ( V_10 < V_367 )
return 0 ;
V_366 = F_294 ( V_2 ) ;
if ( V_366 ) {
F_388 ( & V_368 -> V_354 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_387 ( V_2 ) ;
}
V_2 -> V_354 . V_361 = V_368 ;
V_316 = F_389 ( & V_2 -> V_354 , & V_364 , NULL , V_6 ) ;
if ( V_316 ) {
F_390 ( & V_2 -> V_354 ) ;
return V_316 ;
}
V_316 = F_391 ( & V_2 -> V_354 , & V_369 ) ;
if ( V_316 ) {
F_392 ( & V_2 -> V_354 ) ;
F_390 ( & V_2 -> V_354 ) ;
return V_316 ;
}
F_393 ( & V_2 -> V_354 , V_370 ) ;
if ( ! V_366 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_10 < V_367 )
return;
F_393 ( & V_2 -> V_354 , V_371 ) ;
F_392 ( & V_2 -> V_354 ) ;
F_390 ( & V_2 -> V_354 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_372 * V_373 ;
if ( V_10 == V_367 ) {
F_388 ( & V_368 -> V_354 , V_6 ) ;
return F_394 ( & V_368 -> V_354 , & V_2 -> V_354 , V_6 ) ;
}
V_373 = F_271 ( sizeof( struct V_372 ) , V_258 ) ;
if ( ! V_373 )
return - V_286 ;
V_373 -> V_2 = V_2 ;
V_373 -> V_6 = V_6 ;
V_373 -> V_199 = V_374 ;
V_374 = V_373 ;
return 0 ;
}
static int T_7 F_395 ( void )
{
struct V_1 * V_2 ;
int V_316 ;
F_244 ( & V_270 ) ;
V_368 = F_396 ( L_131 , & V_375 , V_376 ) ;
if ( ! V_368 ) {
F_245 ( & V_270 ) ;
F_39 ( V_51 L_132 ) ;
return - V_249 ;
}
V_10 = V_367 ;
F_183 (s, &slab_caches, list) {
V_316 = F_4 ( V_2 ) ;
if ( V_316 )
F_39 ( V_51 L_133
L_134 , V_2 -> V_6 ) ;
}
while ( V_374 ) {
struct V_372 * V_373 = V_374 ;
V_374 = V_374 -> V_199 ;
V_316 = F_5 ( V_373 -> V_2 , V_373 -> V_6 ) ;
if ( V_316 )
F_39 ( V_51 L_135
L_136 , V_2 -> V_6 ) ;
F_7 ( V_373 ) ;
}
F_245 ( & V_270 ) ;
F_325 () ;
return 0 ;
}
static void F_397 ( struct V_377 * V_188 )
{
F_398 ( V_188 , L_137 ) ;
F_398 ( V_188 , L_138
L_139 ) ;
F_398 ( V_188 , L_140 ) ;
F_398 ( V_188 , L_141 ) ;
F_399 ( V_188 , '\n' ) ;
}
static void * F_400 ( struct V_377 * V_188 , T_11 * V_328 )
{
T_11 V_40 = * V_328 ;
F_275 ( & V_270 ) ;
if ( ! V_40 )
F_397 ( V_188 ) ;
return F_401 ( & V_275 , * V_328 ) ;
}
static void * F_402 ( struct V_377 * V_188 , void * V_5 , T_11 * V_328 )
{
return F_403 ( V_5 , & V_275 , V_328 ) ;
}
static void F_404 ( struct V_377 * V_188 , void * V_5 )
{
F_276 ( & V_270 ) ;
}
static int F_405 ( struct V_377 * V_188 , void * V_5 )
{
unsigned long V_378 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_379 = 0 ;
unsigned long V_214 = 0 ;
unsigned long V_215 = 0 ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_406 ( V_5 , struct V_1 , V_271 ) ;
F_188 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
V_378 += V_40 -> V_154 ;
V_109 += F_92 ( & V_40 -> V_109 ) ;
V_214 += F_92 ( & V_40 -> V_110 ) ;
V_215 += F_180 ( V_40 , F_179 ) ;
}
V_379 = V_214 - V_215 ;
F_407 ( V_188 , L_142 , V_2 -> V_6 , V_379 ,
V_214 , V_2 -> V_18 , F_27 ( V_2 -> V_125 ) ,
( 1 << F_26 ( V_2 -> V_125 ) ) ) ;
F_407 ( V_188 , L_143 , 0 , 0 , 0 ) ;
F_407 ( V_188 , L_144 , V_109 , V_109 ,
0UL ) ;
F_399 ( V_188 , '\n' ) ;
return 0 ;
}
static int F_408 ( struct V_380 * V_380 , struct V_381 * V_381 )
{
return F_409 ( V_381 , & V_382 ) ;
}
static int T_7 F_410 ( void )
{
F_411 ( L_145 , V_383 , NULL , & V_384 ) ;
return 0 ;
}
