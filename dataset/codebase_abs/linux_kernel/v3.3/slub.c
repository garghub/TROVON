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
static inline void * F_16 ( struct V_1 * V_2 , void * V_15 )
{
void * V_5 ;
#ifdef F_17
F_18 ( & V_5 , ( void * * ) ( V_15 + V_2 -> V_19 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_15 ( V_2 , V_15 ) ;
#endif
return V_5 ;
}
static inline void F_19 ( struct V_1 * V_2 , void * V_15 , void * V_20 )
{
* ( void * * ) ( V_15 + V_2 -> V_19 ) = V_20 ;
}
static inline int F_20 ( void * V_5 , struct V_1 * V_2 , void * V_21 )
{
return ( V_5 - V_21 ) / V_2 -> V_18 ;
}
static inline T_1 F_21 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_22 | V_23 ) )
return V_2 -> V_24 ;
#endif
if ( V_2 -> V_3 & ( V_25 | V_26 ) )
return V_2 -> V_27 ;
return V_2 -> V_18 ;
}
static inline int F_22 ( int V_28 , unsigned long V_18 , int V_29 )
{
return ( ( V_30 << V_28 ) - V_29 ) / V_18 ;
}
static inline struct V_31 F_23 ( int V_28 ,
unsigned long V_18 , int V_29 )
{
struct V_31 V_32 = {
( V_28 << V_33 ) + F_22 (order, size, reserved)
} ;
return V_32 ;
}
static inline int F_24 ( struct V_31 V_32 )
{
return V_32 . V_32 >> V_33 ;
}
static inline int F_25 ( struct V_31 V_32 )
{
return V_32 . V_32 & V_34 ;
}
static T_2 void F_26 ( struct V_14 * V_14 )
{
F_27 ( V_35 , & V_14 -> V_3 ) ;
}
static T_2 void F_28 ( struct V_14 * V_14 )
{
F_29 ( V_35 , & V_14 -> V_3 ) ;
}
static inline bool F_30 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_39 ,
const char * V_40 )
{
F_31 ( ! F_32 () ) ;
#if F_33 ( V_41 ) && \
F_33 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_34 ( & V_14 -> V_44 , & V_14 -> V_45 ,
V_36 , V_37 ,
V_38 , V_39 ) )
return 1 ;
} else
#endif
{
F_26 ( V_14 ) ;
if ( V_14 -> V_44 == V_36 && V_14 -> V_45 == V_37 ) {
V_14 -> V_44 = V_38 ;
V_14 -> V_45 = V_39 ;
F_28 ( V_14 ) ;
return 1 ;
}
F_28 ( V_14 ) ;
}
F_35 () ;
F_8 ( V_2 , V_46 ) ;
#ifdef F_36
F_37 ( V_47 L_1 , V_40 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static inline bool F_38 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_39 ,
const char * V_40 )
{
#if F_33 ( V_41 ) && \
F_33 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_34 ( & V_14 -> V_44 , & V_14 -> V_45 ,
V_36 , V_37 ,
V_38 , V_39 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_26 ( V_14 ) ;
if ( V_14 -> V_44 == V_36 && V_14 -> V_45 == V_37 ) {
V_14 -> V_44 = V_38 ;
V_14 -> V_45 = V_39 ;
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
return 1 ;
}
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
}
F_35 () ;
F_8 ( V_2 , V_46 ) ;
#ifdef F_36
F_37 ( V_47 L_1 , V_40 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_14 * V_14 , unsigned long * V_48 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
for ( V_5 = V_14 -> V_44 ; V_5 ; V_5 = F_15 ( V_2 , V_5 ) )
F_42 ( F_20 ( V_5 , V_2 , V_21 ) , V_48 ) ;
}
static void F_43 ( char * V_49 , T_3 * V_21 , unsigned int V_50 )
{
F_44 ( V_51 , V_49 , V_52 , 16 , 1 , V_21 ,
V_50 , 1 ) ;
}
static struct V_53 * F_45 ( struct V_1 * V_2 , void * V_15 ,
enum V_54 V_55 )
{
struct V_53 * V_5 ;
if ( V_2 -> V_19 )
V_5 = V_15 + V_2 -> V_19 + sizeof( void * ) ;
else
V_5 = V_15 + V_2 -> V_27 ;
return V_5 + V_55 ;
}
static void F_46 ( struct V_1 * V_2 , void * V_15 ,
enum V_54 V_55 , unsigned long V_21 )
{
struct V_53 * V_5 = F_45 ( V_2 , V_15 , V_55 ) ;
if ( V_21 ) {
#ifdef F_47
struct V_56 V_57 ;
int V_58 ;
V_57 . V_59 = 0 ;
V_57 . V_60 = V_61 ;
V_57 . V_62 = V_5 -> V_63 ;
V_57 . V_64 = 3 ;
F_48 ( & V_57 ) ;
if ( V_57 . V_59 != 0 &&
V_57 . V_62 [ V_57 . V_59 - 1 ] == V_65 )
V_57 . V_59 -- ;
for ( V_58 = V_57 . V_59 ; V_58 < V_61 ; V_58 ++ )
V_5 -> V_63 [ V_58 ] = 0 ;
#endif
V_5 -> V_21 = V_21 ;
V_5 -> V_66 = F_49 () ;
V_5 -> V_67 = V_68 -> V_67 ;
V_5 -> V_69 = V_70 ;
} else
memset ( V_5 , 0 , sizeof( struct V_53 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_46 ( V_2 , V_15 , V_71 , 0UL ) ;
F_46 ( V_2 , V_15 , V_72 , 0UL ) ;
}
static void F_51 ( const char * V_2 , struct V_53 * V_73 )
{
if ( ! V_73 -> V_21 )
return;
F_37 ( V_51 L_2 ,
V_2 , ( void * ) V_73 -> V_21 , V_70 - V_73 -> V_69 , V_73 -> V_66 , V_73 -> V_67 ) ;
#ifdef F_47
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 ; V_58 ++ )
if ( V_73 -> V_63 [ V_58 ] )
F_37 ( V_51 L_3 , ( void * ) V_73 -> V_63 [ V_58 ] ) ;
else
break;
}
#endif
}
static void F_52 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_51 ( L_4 , F_45 ( V_2 , V_15 , V_72 ) ) ;
F_51 ( L_5 , F_45 ( V_2 , V_15 , V_71 ) ) ;
}
static void F_53 ( struct V_14 * V_14 )
{
F_37 ( V_51 L_6 ,
V_14 , V_14 -> V_17 , V_14 -> V_27 , V_14 -> V_44 , V_14 -> V_3 ) ;
}
static void F_54 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_37 ( V_51 L_7
L_8 ) ;
F_37 ( V_51 L_9 , V_2 -> V_6 , F_55 () , V_75 ) ;
F_37 ( V_51 L_10
L_11 ) ;
}
static void F_56 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_37 ( V_51 L_12 , V_2 -> V_6 , V_75 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned int V_76 ;
T_3 * V_21 = F_14 ( V_14 ) ;
F_52 ( V_2 , V_5 ) ;
F_53 ( V_14 ) ;
F_37 ( V_51 L_13 ,
V_5 , V_5 - V_21 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_21 + 16 )
F_43 ( L_14 , V_5 - 16 , 16 ) ;
F_43 ( L_15 , V_5 , F_58 (unsigned long, s->objsize,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_22 )
F_43 ( L_16 , V_5 + V_2 -> V_24 ,
V_2 -> V_27 - V_2 -> V_24 ) ;
if ( V_2 -> V_19 )
V_76 = V_2 -> V_19 + sizeof( void * ) ;
else
V_76 = V_2 -> V_27 ;
if ( V_2 -> V_3 & V_26 )
V_76 += 2 * sizeof( struct V_53 ) ;
if ( V_76 != V_2 -> V_18 )
F_43 ( L_17 , V_5 + V_76 , V_2 -> V_18 - V_76 ) ;
F_59 () ;
}
static void F_60 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_77 )
{
F_54 ( V_2 , L_18 , V_77 ) ;
F_57 ( V_2 , V_14 , V_15 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_14 * V_14 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_54 ( V_2 , L_18 , V_75 ) ;
F_53 ( V_14 ) ;
F_59 () ;
}
static void F_62 ( struct V_1 * V_2 , void * V_15 , T_3 V_78 )
{
T_3 * V_5 = V_15 ;
if ( V_2 -> V_3 & V_79 ) {
memset ( V_5 , V_80 , V_2 -> V_24 - 1 ) ;
V_5 [ V_2 -> V_24 - 1 ] = V_81 ;
}
if ( V_2 -> V_3 & V_22 )
memset ( V_5 + V_2 -> V_24 , V_78 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
static void F_63 ( struct V_1 * V_2 , char * V_82 , T_3 V_83 ,
void * V_84 , void * V_85 )
{
F_56 ( V_2 , L_19 , V_84 , V_85 - 1 , V_83 ) ;
memset ( V_84 , V_83 , V_85 - V_84 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_86 ,
T_3 * V_87 , unsigned int V_88 , unsigned int V_89 )
{
T_3 * V_90 ;
T_3 * V_91 ;
V_90 = F_65 ( V_87 , V_88 , V_89 ) ;
if ( ! V_90 )
return 1 ;
V_91 = V_87 + V_89 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_88 )
V_91 -- ;
F_54 ( V_2 , L_20 , V_86 ) ;
F_37 ( V_51 L_21 ,
V_90 , V_91 - 1 , V_90 [ 0 ] , V_88 ) ;
F_57 ( V_2 , V_14 , V_15 ) ;
F_63 ( V_2 , V_86 , V_88 , V_90 , V_91 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned long V_76 = V_2 -> V_27 ;
if ( V_2 -> V_19 )
V_76 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_26 )
V_76 += 2 * sizeof( struct V_53 ) ;
if ( V_2 -> V_18 == V_76 )
return 1 ;
return F_64 ( V_2 , V_14 , V_5 , L_22 ,
V_5 + V_76 , V_92 , V_2 -> V_18 - V_76 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
T_3 * V_87 ;
T_3 * V_90 ;
T_3 * V_91 ;
int V_50 ;
int V_93 ;
if ( ! ( V_2 -> V_3 & V_23 ) )
return 1 ;
V_87 = F_14 ( V_14 ) ;
V_50 = ( V_30 << F_68 ( V_14 ) ) - V_2 -> V_29 ;
V_91 = V_87 + V_50 ;
V_93 = V_50 % V_2 -> V_18 ;
if ( ! V_93 )
return 1 ;
V_90 = F_65 ( V_91 - V_93 , V_92 , V_93 ) ;
if ( ! V_90 )
return 1 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_92 )
V_91 -- ;
F_61 ( V_2 , V_14 , L_23 , V_90 , V_91 - 1 ) ;
F_43 ( L_17 , V_91 - V_93 , V_93 ) ;
F_63 ( V_2 , L_24 , V_92 , V_91 - V_93 , V_91 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_78 )
{
T_3 * V_5 = V_15 ;
T_3 * V_94 = V_15 + V_2 -> V_24 ;
if ( V_2 -> V_3 & V_22 ) {
if ( ! F_64 ( V_2 , V_14 , V_15 , L_25 ,
V_94 , V_78 , V_2 -> V_27 - V_2 -> V_24 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_23 ) && V_2 -> V_24 < V_2 -> V_27 ) {
F_64 ( V_2 , V_14 , V_5 , L_26 ,
V_94 , V_92 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
}
if ( V_2 -> V_3 & V_23 ) {
if ( V_78 != V_95 && ( V_2 -> V_3 & V_79 ) &&
( ! F_64 ( V_2 , V_14 , V_5 , L_27 , V_5 ,
V_80 , V_2 -> V_24 - 1 ) ||
! F_64 ( V_2 , V_14 , V_5 , L_27 ,
V_5 + V_2 -> V_24 - 1 , V_81 , 1 ) ) )
return 0 ;
F_66 ( V_2 , V_14 , V_5 ) ;
}
if ( ! V_2 -> V_19 && V_78 == V_95 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , F_15 ( V_2 , V_5 ) ) ) {
F_60 ( V_2 , V_14 , V_5 , L_28 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_96 ;
F_31 ( ! F_32 () ) ;
if ( ! F_71 ( V_14 ) ) {
F_61 ( V_2 , V_14 , L_29 ) ;
return 0 ;
}
V_96 = F_22 ( F_68 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_14 -> V_17 > V_96 ) {
F_61 ( V_2 , V_14 , L_30 ,
V_2 -> V_6 , V_14 -> V_17 , V_96 ) ;
return 0 ;
}
if ( V_14 -> V_27 > V_14 -> V_17 ) {
F_61 ( V_2 , V_14 , L_31 ,
V_2 -> V_6 , V_14 -> V_27 , V_14 -> V_17 ) ;
return 0 ;
}
F_67 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_97 )
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
F_60 ( V_2 , V_14 , V_15 ,
L_32 ) ;
F_19 ( V_2 , V_15 , NULL ) ;
break;
} else {
F_61 ( V_2 , V_14 , L_28 ) ;
V_14 -> V_44 = NULL ;
V_14 -> V_27 = V_14 -> V_17 ;
F_56 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_15 = V_20 ;
V_20 = F_15 ( V_2 , V_15 ) ;
V_98 ++ ;
}
V_99 = F_22 ( F_68 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_99 > V_100 )
V_99 = V_100 ;
if ( V_14 -> V_17 != V_99 ) {
F_61 ( V_2 , V_14 , L_34
L_35 , V_14 -> V_17 , V_99 ) ;
V_14 -> V_17 = V_99 ;
F_56 ( V_2 , L_36 ) ;
}
if ( V_14 -> V_27 != V_14 -> V_17 - V_98 ) {
F_61 ( V_2 , V_14 , L_37
L_38 , V_14 -> V_27 , V_14 -> V_17 - V_98 ) ;
V_14 -> V_27 = V_14 -> V_17 - V_98 ;
F_56 ( V_2 , L_39 ) ;
}
return V_97 == NULL ;
}
static void V_57 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_15 ,
int V_55 )
{
if ( V_2 -> V_3 & V_101 ) {
F_37 ( V_47 L_40 ,
V_2 -> V_6 ,
V_55 ? L_41 : L_42 ,
V_15 , V_14 -> V_27 ,
V_14 -> V_44 ) ;
if ( ! V_55 )
F_43 ( L_15 , ( void * ) V_15 , V_2 -> V_24 ) ;
F_59 () ;
}
}
static inline int F_73 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_102 ;
F_74 ( V_3 ) ;
F_75 ( V_3 & V_103 ) ;
return F_76 ( V_2 -> V_24 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_77 ( struct V_1 * V_2 , T_5 V_3 , void * V_15 )
{
V_3 &= V_102 ;
F_78 ( V_2 , V_3 , V_15 , F_21 ( V_2 ) ) ;
F_79 ( V_15 , V_2 -> V_24 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_80 ( struct V_1 * V_2 , void * V_32 )
{
F_81 ( V_32 , V_2 -> V_3 ) ;
#if F_33 ( V_104 ) || F_33 ( V_105 )
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_82 ( V_2 , V_32 , V_2 -> V_24 ) ;
F_83 ( V_32 , V_2 -> V_24 ) ;
F_40 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_106 ) )
F_84 ( V_32 , V_2 -> V_24 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_86 ( & V_14 -> V_107 , & V_40 -> V_108 ) ;
}
static void F_87 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_88 ( & V_14 -> V_107 ) ;
}
static inline unsigned long F_89 ( struct V_1 * V_2 , int V_13 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
return F_90 ( & V_40 -> V_109 ) ;
}
static inline unsigned long F_91 ( struct V_12 * V_40 )
{
return F_90 ( & V_40 -> V_109 ) ;
}
static inline void F_92 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_40 ) {
F_93 ( & V_40 -> V_109 ) ;
F_94 ( V_17 , & V_40 -> V_110 ) ;
}
}
static inline void F_95 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_96 ( & V_40 -> V_109 ) ;
F_97 ( V_17 , & V_40 -> V_110 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
if ( ! ( V_2 -> V_3 & ( V_26 | V_22 | V_79 ) ) )
return;
F_62 ( V_2 , V_15 , V_111 ) ;
F_50 ( V_2 , V_15 ) ;
}
static T_6 int F_99 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , unsigned long V_21 )
{
if ( ! F_70 ( V_2 , V_14 ) )
goto V_112;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_60 ( V_2 , V_14 , V_15 , L_43 ) ;
goto V_112;
}
if ( ! F_69 ( V_2 , V_14 , V_15 , V_111 ) )
goto V_112;
if ( V_2 -> V_3 & V_26 )
F_46 ( V_2 , V_15 , V_72 , V_21 ) ;
V_57 ( V_2 , V_14 , V_15 , 1 ) ;
F_62 ( V_2 , V_15 , V_95 ) ;
return 1 ;
V_112:
if ( F_71 ( V_14 ) ) {
F_56 ( V_2 , L_44 ) ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_44 = NULL ;
}
return 0 ;
}
static T_6 int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 )
{
unsigned long V_3 ;
int V_113 = 0 ;
F_39 ( V_3 ) ;
F_26 ( V_14 ) ;
if ( ! F_70 ( V_2 , V_14 ) )
goto V_114;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_61 ( V_2 , V_14 , L_45 , V_15 ) ;
goto V_114;
}
if ( F_72 ( V_2 , V_14 , V_15 ) ) {
F_60 ( V_2 , V_14 , V_15 , L_46 ) ;
goto V_114;
}
if ( ! F_69 ( V_2 , V_14 , V_15 , V_95 ) )
goto V_115;
if ( F_3 ( V_2 != V_14 -> V_116 ) ) {
if ( ! F_71 ( V_14 ) ) {
F_61 ( V_2 , V_14 , L_47
L_48 , V_15 ) ;
} else if ( ! V_14 -> V_116 ) {
F_37 ( V_51
L_49 ,
V_15 ) ;
F_59 () ;
} else
F_60 ( V_2 , V_14 , V_15 ,
L_50 ) ;
goto V_114;
}
if ( V_2 -> V_3 & V_26 )
F_46 ( V_2 , V_15 , V_71 , V_21 ) ;
V_57 ( V_2 , V_14 , V_15 , 0 ) ;
F_62 ( V_2 , V_15 , V_111 ) ;
V_113 = 1 ;
V_115:
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
return V_113 ;
V_114:
F_56 ( V_2 , L_51 , V_15 ) ;
goto V_115;
}
static int T_7 F_101 ( char * V_117 )
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
F_37 ( V_51 L_52
L_53 , * V_117 ) ;
}
}
V_120:
if ( * V_117 == ',' )
V_124 = V_117 + 1 ;
V_115:
return 1 ;
}
static unsigned long F_102 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
if ( V_118 && ( ! V_124 ||
! strncmp ( V_124 , V_6 , strlen ( V_124 ) ) ) )
V_3 |= V_118 ;
return V_3 ;
}
static inline void F_98 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 ) {}
static inline int F_99 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_67 ( struct V_1 * V_2 , struct V_14 * V_14 )
{ return 1 ; }
static inline int F_69 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_78 ) { return 1 ; }
static inline void F_85 ( struct V_1 * V_2 , struct V_12 * V_40 ,
struct V_14 * V_14 ) {}
static inline void F_87 ( struct V_1 * V_2 , struct V_14 * V_14 ) {}
static inline unsigned long F_102 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_89 ( struct V_1 * V_2 , int V_13 )
{ return 0 ; }
static inline unsigned long F_91 ( struct V_12 * V_40 )
{ return 0 ; }
static inline void F_92 ( struct V_1 * V_2 , int V_13 ,
int V_17 ) {}
static inline void F_95 ( struct V_1 * V_2 , int V_13 ,
int V_17 ) {}
static inline int F_73 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_77 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_15 ) {}
static inline void F_80 ( struct V_1 * V_2 , void * V_32 ) {}
static inline struct V_14 * F_104 ( T_5 V_3 , int V_13 ,
struct V_31 V_125 )
{
int V_28 = F_24 ( V_125 ) ;
V_3 |= V_126 ;
if ( V_13 == V_127 )
return F_105 ( V_3 , V_28 ) ;
else
return F_106 ( V_13 , V_3 , V_28 ) ;
}
static struct V_14 * F_107 ( struct V_1 * V_2 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
struct V_31 V_125 = V_2 -> V_125 ;
T_5 V_128 ;
V_3 &= V_102 ;
if ( V_3 & V_103 )
F_108 () ;
V_3 |= V_2 -> V_129 ;
V_128 = ( V_3 | V_130 | V_131 ) & ~ V_132 ;
V_14 = F_104 ( V_128 , V_13 , V_125 ) ;
if ( F_3 ( ! V_14 ) ) {
V_125 = V_2 -> V_133 ;
V_14 = F_104 ( V_3 , V_13 , V_125 ) ;
if ( V_14 )
F_8 ( V_2 , V_134 ) ;
}
if ( V_3 & V_103 )
F_109 () ;
if ( ! V_14 )
return NULL ;
if ( V_135
&& ! ( V_2 -> V_3 & ( V_136 | V_119 ) ) ) {
int V_137 = 1 << F_24 ( V_125 ) ;
F_110 ( V_14 , F_24 ( V_125 ) , V_3 , V_13 ) ;
if ( V_2 -> F_103 )
F_111 ( V_14 , V_137 ) ;
else
F_112 ( V_14 , V_137 ) ;
}
V_14 -> V_17 = F_25 ( V_125 ) ;
F_113 ( F_114 ( V_14 ) ,
( V_2 -> V_3 & V_138 ) ?
V_139 : V_140 ,
1 << F_24 ( V_125 ) ) ;
return V_14 ;
}
static void F_115 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
F_98 ( V_2 , V_14 , V_15 ) ;
if ( F_3 ( V_2 -> F_103 ) )
V_2 -> F_103 ( V_15 ) ;
}
static struct V_14 * F_116 ( struct V_1 * V_2 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_87 ;
void * V_141 ;
void * V_5 ;
F_117 ( V_3 & V_142 ) ;
V_14 = F_107 ( V_2 ,
V_3 & ( V_143 | V_144 ) , V_13 ) ;
if ( ! V_14 )
goto V_115;
F_92 ( V_2 , F_118 ( V_14 ) , V_14 -> V_17 ) ;
V_14 -> V_116 = V_2 ;
V_14 -> V_3 |= 1 << V_145 ;
V_87 = F_14 ( V_14 ) ;
if ( F_3 ( V_2 -> V_3 & V_23 ) )
memset ( V_87 , V_92 , V_30 << F_68 ( V_14 ) ) ;
V_141 = V_87 ;
F_119 (p, s, start, page->objects) {
F_115 ( V_2 , V_14 , V_141 ) ;
F_19 ( V_2 , V_141 , V_5 ) ;
V_141 = V_5 ;
}
F_115 ( V_2 , V_14 , V_141 ) ;
F_19 ( V_2 , V_141 , NULL ) ;
V_14 -> V_44 = V_87 ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_146 = 1 ;
V_115:
return V_14 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_28 = F_68 ( V_14 ) ;
int V_137 = 1 << V_28 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_67 ( V_2 , V_14 ) ;
F_119 (p, s, page_address(page),
page->objects)
F_69 ( V_2 , V_14 , V_5 , V_111 ) ;
}
F_121 ( V_14 , F_68 ( V_14 ) ) ;
F_113 ( F_114 ( V_14 ) ,
( V_2 -> V_3 & V_138 ) ?
V_139 : V_140 ,
- V_137 ) ;
F_122 ( V_14 ) ;
F_123 ( V_14 ) ;
if ( V_68 -> V_147 )
V_68 -> V_147 -> V_148 += V_137 ;
F_124 ( V_14 , V_28 ) ;
}
static void F_125 ( struct V_149 * V_150 )
{
struct V_14 * V_14 ;
if ( V_151 )
V_14 = F_126 ( V_150 ) ;
else
V_14 = F_127 ( (struct V_152 * ) V_150 , struct V_14 , V_107 ) ;
F_120 ( V_14 -> V_116 , V_14 ) ;
}
static void F_128 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( F_3 ( V_2 -> V_3 & V_25 ) ) {
struct V_149 * V_153 ;
if ( V_151 ) {
int V_28 = F_68 ( V_14 ) ;
int V_19 = ( V_30 << V_28 ) - V_2 -> V_29 ;
F_31 ( V_2 -> V_29 != sizeof( * V_153 ) ) ;
V_153 = F_14 ( V_14 ) + V_19 ;
} else {
V_153 = ( void * ) & V_14 -> V_107 ;
}
F_129 ( V_153 , F_125 ) ;
} else
F_120 ( V_2 , V_14 ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
F_95 ( V_2 , F_118 ( V_14 ) , V_14 -> V_17 ) ;
F_128 ( V_2 , V_14 ) ;
}
static inline void F_131 ( struct V_12 * V_40 ,
struct V_14 * V_14 , int V_154 )
{
V_40 -> V_155 ++ ;
if ( V_154 == V_156 )
F_132 ( & V_14 -> V_107 , & V_40 -> V_157 ) ;
else
F_86 ( & V_14 -> V_107 , & V_40 -> V_157 ) ;
}
static inline void F_133 ( struct V_12 * V_40 ,
struct V_14 * V_14 )
{
F_88 ( & V_14 -> V_107 ) ;
V_40 -> V_155 -- ;
}
static inline void * F_134 ( struct V_1 * V_2 ,
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
F_31 ( V_159 . V_146 ) ;
V_159 . V_146 = 1 ;
} while ( ! F_30 ( V_2 , V_14 ,
V_44 , V_45 ,
NULL , V_159 . V_45 ,
L_54 ) );
F_133 ( V_40 , V_14 ) ;
return V_44 ;
}
static void * F_135 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_160 * V_161 )
{
struct V_14 * V_14 , * V_162 ;
void * V_15 = NULL ;
if ( ! V_40 || ! V_40 -> V_155 )
return NULL ;
F_136 ( & V_40 -> V_163 ) ;
F_137 (page, page2, &n->partial, lru) {
void * V_73 = F_134 ( V_2 , V_40 , V_14 , V_15 == NULL ) ;
int V_164 ;
if ( ! V_73 )
break;
if ( ! V_15 ) {
V_161 -> V_14 = V_14 ;
V_161 -> V_13 = F_118 ( V_14 ) ;
F_8 ( V_2 , V_165 ) ;
V_15 = V_73 ;
V_164 = V_14 -> V_17 - V_14 -> V_27 ;
} else {
V_14 -> V_44 = V_73 ;
V_164 = F_138 ( V_2 , V_14 , 0 ) ;
}
if ( F_1 ( V_2 ) || V_164 > V_2 -> V_166 / 2 )
break;
}
F_139 ( & V_40 -> V_163 ) ;
return V_15 ;
}
static struct V_14 * F_140 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_160 * V_161 )
{
#ifdef F_141
struct V_167 * V_167 ;
struct V_168 * V_169 ;
struct V_170 * V_170 ;
enum V_171 V_172 = F_142 ( V_3 ) ;
void * V_15 ;
if ( ! V_2 -> V_173 ||
F_143 () % 1024 > V_2 -> V_173 )
return NULL ;
F_144 () ;
V_167 = F_145 ( F_146 ( V_68 -> V_174 ) , V_3 ) ;
F_147 (zone, z, zonelist, high_zoneidx) {
struct V_12 * V_40 ;
V_40 = F_12 ( V_2 , F_148 ( V_170 ) ) ;
if ( V_40 && F_149 ( V_170 , V_3 ) &&
V_40 -> V_155 > V_2 -> V_175 ) {
V_15 = F_135 ( V_2 , V_40 , V_161 ) ;
if ( V_15 ) {
F_150 () ;
return V_15 ;
}
}
}
F_150 () ;
#endif
return NULL ;
}
static void * F_151 ( struct V_1 * V_2 , T_5 V_3 , int V_13 ,
struct V_160 * V_161 )
{
void * V_15 ;
int V_176 = ( V_13 == V_127 ) ? F_152 () : V_13 ;
V_15 = F_135 ( V_2 , F_12 ( V_2 , V_176 ) , V_161 ) ;
if ( V_15 || V_13 != V_127 )
return V_15 ;
return F_140 ( V_2 , V_3 , V_161 ) ;
}
static inline unsigned long F_153 ( unsigned long V_177 )
{
return V_177 + V_178 ;
}
static inline unsigned int F_154 ( unsigned long V_177 )
{
return V_177 % V_178 ;
}
static inline unsigned long F_155 ( unsigned long V_177 )
{
return V_177 / V_178 ;
}
static inline unsigned int F_156 ( int V_66 )
{
return V_66 ;
}
static inline void F_157 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_177 )
{
#ifdef F_36
unsigned long V_179 = F_158 ( V_2 -> V_9 -> V_177 ) ;
F_37 ( V_47 L_55 , V_40 , V_2 -> V_6 ) ;
#ifdef F_159
if ( F_154 ( V_177 ) != F_154 ( V_179 ) )
F_37 ( L_56 ,
F_154 ( V_177 ) , F_154 ( V_179 ) ) ;
else
#endif
if ( F_155 ( V_177 ) != F_155 ( V_179 ) )
F_37 ( L_57 ,
F_155 ( V_177 ) , F_155 ( V_179 ) ) ;
else
F_37 ( L_58 ,
V_179 , V_177 , F_153 ( V_177 ) ) ;
#endif
F_8 ( V_2 , V_180 ) ;
}
void F_160 ( struct V_1 * V_2 )
{
int V_66 ;
F_161 (cpu)
F_162 ( V_2 -> V_9 , V_66 ) -> V_177 = F_156 ( V_66 ) ;
}
static void F_163 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
enum T_8 { V_181 , V_182 , V_183 , V_184 };
struct V_14 * V_14 = V_161 -> V_14 ;
struct V_12 * V_40 = F_12 ( V_2 , F_118 ( V_14 ) ) ;
int V_185 = 0 ;
enum T_8 V_186 = V_181 , V_187 = V_181 ;
void * V_44 ;
void * V_188 ;
int V_154 = V_189 ;
struct V_14 V_159 ;
struct V_14 V_190 ;
if ( V_14 -> V_44 ) {
F_8 ( V_2 , V_191 ) ;
V_154 = V_156 ;
}
V_161 -> V_177 = F_153 ( V_161 -> V_177 ) ;
V_161 -> V_14 = NULL ;
V_44 = V_161 -> V_44 ;
V_161 -> V_44 = NULL ;
while ( V_44 && ( V_188 = F_15 ( V_2 , V_44 ) ) ) {
void * V_192 ;
unsigned long V_45 ;
do {
V_192 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
F_19 ( V_2 , V_44 , V_192 ) ;
V_159 . V_45 = V_45 ;
V_159 . V_27 -- ;
F_31 ( ! V_159 . V_146 ) ;
} while ( ! F_30 ( V_2 , V_14 ,
V_192 , V_45 ,
V_44 , V_159 . V_45 ,
L_59 ) );
V_44 = V_188 ;
}
V_193:
V_190 . V_44 = V_14 -> V_44 ;
V_190 . V_45 = V_14 -> V_45 ;
F_31 ( ! V_190 . V_146 ) ;
V_159 . V_45 = V_190 . V_45 ;
if ( V_44 ) {
V_159 . V_27 -- ;
F_19 ( V_2 , V_44 , V_190 . V_44 ) ;
V_159 . V_44 = V_44 ;
} else
V_159 . V_44 = V_190 . V_44 ;
V_159 . V_146 = 0 ;
if ( ! V_159 . V_27 && V_40 -> V_155 > V_2 -> V_175 )
V_187 = V_184 ;
else if ( V_159 . V_44 ) {
V_187 = V_182 ;
if ( ! V_185 ) {
V_185 = 1 ;
F_136 ( & V_40 -> V_163 ) ;
}
} else {
V_187 = V_183 ;
if ( F_1 ( V_2 ) && ! V_185 ) {
V_185 = 1 ;
F_136 ( & V_40 -> V_163 ) ;
}
}
if ( V_186 != V_187 ) {
if ( V_186 == V_182 )
F_133 ( V_40 , V_14 ) ;
else if ( V_186 == V_183 )
F_87 ( V_2 , V_14 ) ;
if ( V_187 == V_182 ) {
F_131 ( V_40 , V_14 , V_154 ) ;
F_8 ( V_2 , V_154 ) ;
} else if ( V_187 == V_183 ) {
F_8 ( V_2 , V_194 ) ;
F_85 ( V_2 , V_40 , V_14 ) ;
}
}
V_186 = V_187 ;
if ( ! F_30 ( V_2 , V_14 ,
V_190 . V_44 , V_190 . V_45 ,
V_159 . V_44 , V_159 . V_45 ,
L_60 ) )
goto V_193;
if ( V_185 )
F_139 ( & V_40 -> V_163 ) ;
if ( V_187 == V_184 ) {
F_8 ( V_2 , V_195 ) ;
F_130 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_196 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_12 * V_40 = NULL ;
struct V_160 * V_161 = F_165 ( V_2 -> V_9 ) ;
struct V_14 * V_14 , * V_197 = NULL ;
while ( ( V_14 = V_161 -> V_157 ) ) {
enum T_8 { V_182 , V_184 };
enum T_8 V_186 , V_187 ;
struct V_14 V_159 ;
struct V_14 V_190 ;
V_161 -> V_157 = V_14 -> V_198 ;
V_186 = V_184 ;
do {
V_190 . V_44 = V_14 -> V_44 ;
V_190 . V_45 = V_14 -> V_45 ;
F_31 ( ! V_190 . V_146 ) ;
V_159 . V_45 = V_190 . V_45 ;
V_159 . V_44 = V_190 . V_44 ;
V_159 . V_146 = 0 ;
if ( ! V_159 . V_27 && ( ! V_40 || V_40 -> V_155 > V_2 -> V_175 ) )
V_187 = V_184 ;
else {
struct V_12 * V_199 = F_12 ( V_2 ,
F_118 ( V_14 ) ) ;
V_187 = V_182 ;
if ( V_40 != V_199 ) {
if ( V_40 )
F_139 ( & V_40 -> V_163 ) ;
V_40 = V_199 ;
F_136 ( & V_40 -> V_163 ) ;
}
}
if ( V_186 != V_187 ) {
if ( V_186 == V_182 ) {
F_133 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_200 ) ;
} else {
F_131 ( V_40 , V_14 ,
V_156 ) ;
F_8 ( V_2 , V_201 ) ;
}
V_186 = V_187 ;
}
} while ( ! F_38 ( V_2 , V_14 ,
V_190 . V_44 , V_190 . V_45 ,
V_159 . V_44 , V_159 . V_45 ,
L_60 ) );
if ( V_187 == V_184 ) {
V_14 -> V_198 = V_197 ;
V_197 = V_14 ;
}
}
if ( V_40 )
F_139 ( & V_40 -> V_163 ) ;
while ( V_197 ) {
V_14 = V_197 ;
V_197 = V_197 -> V_198 ;
F_8 ( V_2 , V_195 ) ;
F_130 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_196 ) ;
}
}
int F_138 ( struct V_1 * V_2 , struct V_14 * V_14 , int V_202 )
{
struct V_14 * V_203 ;
int V_137 ;
int V_204 ;
do {
V_137 = 0 ;
V_204 = 0 ;
V_203 = F_166 ( V_2 -> V_9 -> V_157 ) ;
if ( V_203 ) {
V_204 = V_203 -> V_204 ;
V_137 = V_203 -> V_137 ;
if ( V_202 && V_204 > V_2 -> V_166 ) {
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_164 ( V_2 ) ;
F_40 ( V_3 ) ;
V_204 = 0 ;
V_137 = 0 ;
}
}
V_137 ++ ;
V_204 += V_14 -> V_17 - V_14 -> V_27 ;
V_14 -> V_137 = V_137 ;
V_14 -> V_204 = V_204 ;
V_14 -> V_198 = V_203 ;
} while ( F_167 ( V_2 -> V_9 -> V_157 , V_203 , V_14 ) != V_203 );
F_8 ( V_2 , V_205 ) ;
return V_204 ;
}
static inline void F_168 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
F_8 ( V_2 , V_206 ) ;
F_163 ( V_2 , V_161 ) ;
}
static inline void F_169 ( struct V_1 * V_2 , int V_66 )
{
struct V_160 * V_161 = F_162 ( V_2 -> V_9 , V_66 ) ;
if ( F_170 ( V_161 ) ) {
if ( V_161 -> V_14 )
F_168 ( V_2 , V_161 ) ;
F_164 ( V_2 ) ;
}
}
static void F_171 ( void * V_207 )
{
struct V_1 * V_2 = V_207 ;
F_169 ( V_2 , F_49 () ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_173 ( F_171 , V_2 , 1 ) ;
}
static inline int F_174 ( struct V_160 * V_161 , int V_13 )
{
#ifdef F_141
if ( V_13 != V_127 && V_161 -> V_13 != V_13 )
return 0 ;
#endif
return 1 ;
}
static int F_175 ( struct V_14 * V_14 )
{
return V_14 -> V_17 - V_14 -> V_27 ;
}
static unsigned long F_176 ( struct V_12 * V_40 ,
int (* F_177)( struct V_14 * ) )
{
unsigned long V_3 ;
unsigned long V_32 = 0 ;
struct V_14 * V_14 ;
F_178 ( & V_40 -> V_163 , V_3 ) ;
F_179 (page, &n->partial, lru)
V_32 += F_177 ( V_14 ) ;
F_180 ( & V_40 -> V_163 , V_3 ) ;
return V_32 ;
}
static inline unsigned long F_181 ( struct V_12 * V_40 )
{
#ifdef F_2
return F_90 ( & V_40 -> V_110 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_182 ( struct V_1 * V_2 , T_5 V_208 , int V_209 )
{
int V_13 ;
F_37 ( V_210
L_61 ,
V_209 , V_208 ) ;
F_37 ( V_210 L_62
L_63 , V_2 -> V_6 , V_2 -> V_24 ,
V_2 -> V_18 , F_24 ( V_2 -> V_125 ) , F_24 ( V_2 -> V_133 ) ) ;
if ( F_24 ( V_2 -> V_133 ) > F_183 ( V_2 -> V_24 ) )
F_37 ( V_210 L_64
L_65 , V_2 -> V_6 ) ;
F_184 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_109 ;
unsigned long V_211 ;
unsigned long V_212 ;
if ( ! V_40 )
continue;
V_212 = F_176 ( V_40 , F_175 ) ;
V_109 = F_91 ( V_40 ) ;
V_211 = F_181 ( V_40 ) ;
F_37 ( V_210
L_66 ,
V_13 , V_109 , V_211 , V_212 ) ;
}
}
static inline void * F_185 ( struct V_1 * V_2 , T_5 V_3 ,
int V_13 , struct V_160 * * V_213 )
{
void * V_15 ;
struct V_160 * V_161 ;
struct V_14 * V_14 = F_116 ( V_2 , V_3 , V_13 ) ;
if ( V_14 ) {
V_161 = F_186 ( V_2 -> V_9 ) ;
if ( V_161 -> V_14 )
F_168 ( V_2 , V_161 ) ;
V_15 = V_14 -> V_44 ;
V_14 -> V_44 = NULL ;
F_8 ( V_2 , V_214 ) ;
V_161 -> V_13 = F_118 ( V_14 ) ;
V_161 -> V_14 = V_14 ;
* V_213 = V_161 ;
} else
V_15 = NULL ;
return V_15 ;
}
static inline void * F_187 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_14 V_159 ;
unsigned long V_45 ;
void * V_44 ;
do {
V_44 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
V_159 . V_45 = V_45 ;
F_31 ( ! V_159 . V_146 ) ;
V_159 . V_27 = V_14 -> V_17 ;
V_159 . V_146 = V_44 != NULL ;
} while ( ! F_38 ( V_2 , V_14 ,
V_44 , V_45 ,
NULL , V_159 . V_45 ,
L_67 ) );
return V_44 ;
}
static void * F_188 ( struct V_1 * V_2 , T_5 V_208 , int V_13 ,
unsigned long V_21 , struct V_160 * V_161 )
{
void * * V_15 ;
unsigned long V_3 ;
F_39 ( V_3 ) ;
#ifdef F_159
V_161 = F_165 ( V_2 -> V_9 ) ;
#endif
if ( ! V_161 -> V_14 )
goto F_116;
V_193:
if ( F_3 ( ! F_174 ( V_161 , V_13 ) ) ) {
F_8 ( V_2 , V_215 ) ;
F_163 ( V_2 , V_161 ) ;
goto F_116;
}
V_15 = V_161 -> V_44 ;
if ( V_15 )
goto V_216;
F_8 ( V_2 , V_217 ) ;
V_15 = F_187 ( V_2 , V_161 -> V_14 ) ;
if ( ! V_15 ) {
V_161 -> V_14 = NULL ;
F_8 ( V_2 , V_218 ) ;
goto F_116;
}
F_8 ( V_2 , V_219 ) ;
V_216:
V_161 -> V_44 = F_15 ( V_2 , V_15 ) ;
V_161 -> V_177 = F_153 ( V_161 -> V_177 ) ;
F_40 ( V_3 ) ;
return V_15 ;
F_116:
if ( V_161 -> V_157 ) {
V_161 -> V_14 = V_161 -> V_157 ;
V_161 -> V_157 = V_161 -> V_14 -> V_198 ;
V_161 -> V_13 = F_118 ( V_161 -> V_14 ) ;
F_8 ( V_2 , V_220 ) ;
V_161 -> V_44 = NULL ;
goto V_193;
}
V_15 = F_151 ( V_2 , V_208 , V_13 , V_161 ) ;
if ( F_3 ( ! V_15 ) ) {
V_15 = F_185 ( V_2 , V_208 , V_13 , & V_161 ) ;
if ( F_3 ( ! V_15 ) ) {
if ( ! ( V_208 & V_130 ) && F_189 () )
F_182 ( V_2 , V_208 , V_13 ) ;
F_40 ( V_3 ) ;
return NULL ;
}
}
if ( F_170 ( ! F_1 ( V_2 ) ) )
goto V_216;
if ( ! F_99 ( V_2 , V_161 -> V_14 , V_15 , V_21 ) )
goto F_116;
V_161 -> V_44 = F_15 ( V_2 , V_15 ) ;
F_163 ( V_2 , V_161 ) ;
V_161 -> V_13 = V_127 ;
F_40 ( V_3 ) ;
return V_15 ;
}
static T_2 void * F_190 ( struct V_1 * V_2 ,
T_5 V_208 , int V_13 , unsigned long V_21 )
{
void * * V_15 ;
struct V_160 * V_161 ;
unsigned long V_177 ;
if ( F_73 ( V_2 , V_208 ) )
return NULL ;
V_193:
V_161 = F_186 ( V_2 -> V_9 ) ;
V_177 = V_161 -> V_177 ;
F_191 () ;
V_15 = V_161 -> V_44 ;
if ( F_3 ( ! V_15 || ! F_174 ( V_161 , V_13 ) ) )
V_15 = F_188 ( V_2 , V_208 , V_13 , V_21 , V_161 ) ;
else {
if ( F_3 ( ! F_192 (
V_2 -> V_9 -> V_44 , V_2 -> V_9 -> V_177 ,
V_15 , V_177 ,
F_16 ( V_2 , V_15 ) , F_153 ( V_177 ) ) ) ) {
F_157 ( L_68 , V_2 , V_177 ) ;
goto V_193;
}
F_8 ( V_2 , V_221 ) ;
}
if ( F_3 ( V_208 & V_222 ) && V_15 )
memset ( V_15 , 0 , V_2 -> V_24 ) ;
F_77 ( V_2 , V_208 , V_15 ) ;
return V_15 ;
}
void * F_193 ( struct V_1 * V_2 , T_5 V_208 )
{
void * V_223 = F_190 ( V_2 , V_208 , V_127 , V_224 ) ;
F_194 ( V_224 , V_223 , V_2 -> V_24 , V_2 -> V_18 , V_208 ) ;
return V_223 ;
}
void * F_195 ( struct V_1 * V_2 , T_5 V_208 , T_1 V_18 )
{
void * V_223 = F_190 ( V_2 , V_208 , V_127 , V_224 ) ;
F_196 ( V_224 , V_223 , V_18 , V_2 -> V_18 , V_208 ) ;
return V_223 ;
}
void * F_197 ( T_1 V_18 , T_5 V_3 , unsigned int V_28 )
{
void * V_223 = F_198 ( V_18 , V_3 , V_28 ) ;
F_196 ( V_224 , V_223 , V_18 , V_30 << V_28 , V_3 ) ;
return V_223 ;
}
void * F_199 ( struct V_1 * V_2 , T_5 V_208 , int V_13 )
{
void * V_223 = F_190 ( V_2 , V_208 , V_13 , V_224 ) ;
F_200 ( V_224 , V_223 ,
V_2 -> V_24 , V_2 -> V_18 , V_208 , V_13 ) ;
return V_223 ;
}
void * F_201 ( struct V_1 * V_2 ,
T_5 V_208 ,
int V_13 , T_1 V_18 )
{
void * V_223 = F_190 ( V_2 , V_208 , V_13 , V_224 ) ;
F_202 ( V_224 , V_223 ,
V_18 , V_2 -> V_18 , V_208 , V_13 ) ;
return V_223 ;
}
static void F_203 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_32 , unsigned long V_21 )
{
void * V_192 ;
void * * V_15 = ( void * ) V_32 ;
int V_225 ;
int V_27 ;
struct V_14 V_159 ;
unsigned long V_45 ;
struct V_12 * V_40 = NULL ;
unsigned long V_226 ( V_3 ) ;
F_8 ( V_2 , V_227 ) ;
if ( F_1 ( V_2 ) && ! F_100 ( V_2 , V_14 , V_32 , V_21 ) )
return;
do {
V_192 = V_14 -> V_44 ;
V_45 = V_14 -> V_45 ;
F_19 ( V_2 , V_15 , V_192 ) ;
V_159 . V_45 = V_45 ;
V_225 = V_159 . V_146 ;
V_159 . V_27 -- ;
if ( ( ! V_159 . V_27 || ! V_192 ) && ! V_225 && ! V_40 ) {
if ( ! F_1 ( V_2 ) && ! V_192 )
V_159 . V_146 = 1 ;
else {
V_40 = F_12 ( V_2 , F_118 ( V_14 ) ) ;
F_178 ( & V_40 -> V_163 , V_3 ) ;
}
}
V_27 = V_159 . V_27 ;
} while ( ! F_38 ( V_2 , V_14 ,
V_192 , V_45 ,
V_15 , V_159 . V_45 ,
L_69 ) );
if ( F_170 ( ! V_40 ) ) {
if ( V_159 . V_146 && ! V_225 )
F_138 ( V_2 , V_14 , 1 ) ;
if ( V_225 )
F_8 ( V_2 , V_228 ) ;
return;
}
if ( V_225 )
F_8 ( V_2 , V_228 ) ;
else {
if ( F_3 ( ! V_27 && V_40 -> V_155 > V_2 -> V_175 ) )
goto V_229;
if ( F_3 ( ! V_192 ) ) {
F_87 ( V_2 , V_14 ) ;
F_131 ( V_40 , V_14 , V_156 ) ;
F_8 ( V_2 , V_201 ) ;
}
}
F_180 ( & V_40 -> V_163 , V_3 ) ;
return;
V_229:
if ( V_192 ) {
F_133 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_200 ) ;
} else
F_87 ( V_2 , V_14 ) ;
F_180 ( & V_40 -> V_163 , V_3 ) ;
F_8 ( V_2 , V_196 ) ;
F_130 ( V_2 , V_14 ) ;
}
static T_2 void F_204 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_32 , unsigned long V_21 )
{
void * * V_15 = ( void * ) V_32 ;
struct V_160 * V_161 ;
unsigned long V_177 ;
F_80 ( V_2 , V_32 ) ;
V_193:
V_161 = F_186 ( V_2 -> V_9 ) ;
V_177 = V_161 -> V_177 ;
F_191 () ;
if ( F_170 ( V_14 == V_161 -> V_14 ) ) {
F_19 ( V_2 , V_15 , V_161 -> V_44 ) ;
if ( F_3 ( ! F_192 (
V_2 -> V_9 -> V_44 , V_2 -> V_9 -> V_177 ,
V_161 -> V_44 , V_177 ,
V_15 , F_153 ( V_177 ) ) ) ) {
F_157 ( L_70 , V_2 , V_177 ) ;
goto V_193;
}
F_8 ( V_2 , V_230 ) ;
} else
F_203 ( V_2 , V_14 , V_32 , V_21 ) ;
}
void F_205 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_14 ;
V_14 = F_126 ( V_32 ) ;
F_204 ( V_2 , V_14 , V_32 , V_224 ) ;
F_206 ( V_224 , V_32 ) ;
}
static inline int F_207 ( int V_18 , int V_231 ,
int V_232 , int V_233 , int V_29 )
{
int V_28 ;
int V_234 ;
int V_235 = V_236 ;
if ( F_22 ( V_235 , V_18 , V_29 ) > V_100 )
return F_183 ( V_18 * V_100 ) - 1 ;
for ( V_28 = F_208 ( V_235 ,
F_209 ( V_231 * V_18 - 1 ) - V_237 ) ;
V_28 <= V_232 ; V_28 ++ ) {
unsigned long V_238 = V_30 << V_28 ;
if ( V_238 < V_231 * V_18 + V_29 )
continue;
V_234 = ( V_238 - V_29 ) % V_18 ;
if ( V_234 <= V_238 / V_233 )
break;
}
return V_28 ;
}
static inline int F_210 ( int V_18 , int V_29 )
{
int V_28 ;
int V_231 ;
int V_239 ;
int V_99 ;
V_231 = V_240 ;
if ( ! V_231 )
V_231 = 4 * ( F_209 ( V_241 ) + 1 ) ;
V_99 = F_22 ( V_242 , V_18 , V_29 ) ;
V_231 = V_133 ( V_231 , V_99 ) ;
while ( V_231 > 1 ) {
V_239 = 16 ;
while ( V_239 >= 4 ) {
V_28 = F_207 ( V_18 , V_231 ,
V_242 , V_239 , V_29 ) ;
if ( V_28 <= V_242 )
return V_28 ;
V_239 /= 2 ;
}
V_231 -- ;
}
V_28 = F_207 ( V_18 , 1 , V_242 , 1 , V_29 ) ;
if ( V_28 <= V_242 )
return V_28 ;
V_28 = F_207 ( V_18 , 1 , V_243 , 1 , V_29 ) ;
if ( V_28 < V_243 )
return V_28 ;
return - V_244 ;
}
static unsigned long F_211 ( unsigned long V_3 ,
unsigned long V_245 , unsigned long V_18 )
{
if ( V_3 & V_246 ) {
unsigned long V_247 = F_212 () ;
while ( V_18 <= V_247 / 2 )
V_247 /= 2 ;
V_245 = F_208 ( V_245 , V_247 ) ;
}
if ( V_245 < V_248 )
V_245 = V_248 ;
return F_213 ( V_245 , sizeof( void * ) ) ;
}
static void
F_214 ( struct V_12 * V_40 , struct V_1 * V_2 )
{
V_40 -> V_155 = 0 ;
F_215 ( & V_40 -> V_163 ) ;
F_216 ( & V_40 -> V_157 ) ;
#ifdef F_2
F_217 ( & V_40 -> V_109 , 0 ) ;
F_217 ( & V_40 -> V_110 , 0 ) ;
F_216 ( & V_40 -> V_108 ) ;
#endif
}
static inline int F_218 ( struct V_1 * V_2 )
{
F_219 ( V_249 <
V_250 * sizeof( struct V_160 ) ) ;
V_2 -> V_9 = F_220 ( sizeof( struct V_160 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_160 ( V_2 ) ;
return 1 ;
}
static void F_221 ( int V_13 )
{
struct V_14 * V_14 ;
struct V_12 * V_40 ;
F_117 ( V_12 -> V_18 < sizeof( struct V_12 ) ) ;
V_14 = F_116 ( V_12 , V_251 , V_13 ) ;
F_117 ( ! V_14 ) ;
if ( F_118 ( V_14 ) != V_13 ) {
F_37 ( V_51 L_71
L_72 , V_13 ) ;
F_37 ( V_51 L_73
L_74 ) ;
}
V_40 = V_14 -> V_44 ;
F_117 ( ! V_40 ) ;
V_14 -> V_44 = F_15 ( V_12 , V_40 ) ;
V_14 -> V_27 = 1 ;
V_14 -> V_146 = 0 ;
V_12 -> V_13 [ V_13 ] = V_40 ;
#ifdef F_2
F_62 ( V_12 , V_40 , V_95 ) ;
F_50 ( V_12 , V_40 ) ;
#endif
F_214 ( V_40 , V_12 ) ;
F_92 ( V_12 , V_13 , V_14 -> V_17 ) ;
F_131 ( V_40 , V_14 , V_189 ) ;
}
static void F_222 ( struct V_1 * V_2 )
{
int V_13 ;
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = V_2 -> V_13 [ V_13 ] ;
if ( V_40 )
F_205 ( V_12 , V_40 ) ;
V_2 -> V_13 [ V_13 ] = NULL ;
}
}
static int F_224 ( struct V_1 * V_2 )
{
int V_13 ;
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 ;
if ( V_10 == V_252 ) {
F_221 ( V_13 ) ;
continue;
}
V_40 = F_199 ( V_12 ,
V_253 , V_13 ) ;
if ( ! V_40 ) {
F_222 ( V_2 ) ;
return 0 ;
}
V_2 -> V_13 [ V_13 ] = V_40 ;
F_214 ( V_40 , V_2 ) ;
}
return 1 ;
}
static void F_225 ( struct V_1 * V_2 , unsigned long V_133 )
{
if ( V_133 < V_254 )
V_133 = V_254 ;
else if ( V_133 > V_255 )
V_133 = V_255 ;
V_2 -> V_175 = V_133 ;
}
static int F_226 ( struct V_1 * V_2 , int V_256 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_18 = V_2 -> V_24 ;
unsigned long V_245 = V_2 -> V_245 ;
int V_28 ;
V_18 = F_213 ( V_18 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_23 ) && ! ( V_3 & V_25 ) &&
! V_2 -> F_103 )
V_2 -> V_3 |= V_79 ;
else
V_2 -> V_3 &= ~ V_79 ;
if ( ( V_3 & V_22 ) && V_18 == V_2 -> V_24 )
V_18 += sizeof( void * ) ;
#endif
V_2 -> V_27 = V_18 ;
if ( ( ( V_3 & ( V_25 | V_23 ) ) ||
V_2 -> F_103 ) ) {
V_2 -> V_19 = V_18 ;
V_18 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_26 )
V_18 += 2 * sizeof( struct V_53 ) ;
if ( V_3 & V_22 )
V_18 += sizeof( void * ) ;
#endif
V_245 = F_211 ( V_3 , V_245 , V_2 -> V_24 ) ;
V_2 -> V_245 = V_245 ;
V_18 = F_213 ( V_18 , V_245 ) ;
V_2 -> V_18 = V_18 ;
if ( V_256 >= 0 )
V_28 = V_256 ;
else
V_28 = F_210 ( V_18 , V_2 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
V_2 -> V_129 = 0 ;
if ( V_28 )
V_2 -> V_129 |= V_257 ;
if ( V_2 -> V_3 & V_258 )
V_2 -> V_129 |= V_259 ;
if ( V_2 -> V_3 & V_138 )
V_2 -> V_129 |= V_260 ;
V_2 -> V_125 = F_23 ( V_28 , V_18 , V_2 -> V_29 ) ;
V_2 -> V_133 = F_23 ( F_183 ( V_18 ) , V_18 , V_2 -> V_29 ) ;
if ( F_25 ( V_2 -> V_125 ) > F_25 ( V_2 -> F_208 ) )
V_2 -> F_208 = V_2 -> V_125 ;
return ! ! F_25 ( V_2 -> V_125 ) ;
}
static int F_227 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_18 ,
T_1 V_245 , unsigned long V_3 ,
void (* F_103)( void * ) )
{
memset ( V_2 , 0 , V_261 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_103 = F_103 ;
V_2 -> V_24 = V_18 ;
V_2 -> V_245 = V_245 ;
V_2 -> V_3 = F_102 ( V_18 , V_3 , V_6 , F_103 ) ;
V_2 -> V_29 = 0 ;
if ( V_151 && ( V_2 -> V_3 & V_25 ) )
V_2 -> V_29 = sizeof( struct V_149 ) ;
if ( ! F_226 ( V_2 , - 1 ) )
goto error;
if ( V_121 ) {
if ( F_183 ( V_2 -> V_18 ) > F_183 ( V_2 -> V_24 ) ) {
V_2 -> V_3 &= ~ V_262 ;
V_2 -> V_19 = 0 ;
if ( ! F_226 ( V_2 , - 1 ) )
goto error;
}
}
#if F_33 ( V_41 ) && \
F_33 ( V_42 )
if ( F_228 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_43 ;
#endif
F_225 ( V_2 , F_229 ( V_2 -> V_18 ) / 2 ) ;
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
V_2 -> V_263 = 1 ;
#ifdef F_141
V_2 -> V_173 = 1000 ;
#endif
if ( ! F_224 ( V_2 ) )
goto error;
if ( F_218 ( V_2 ) )
return 1 ;
F_222 ( V_2 ) ;
error:
if ( V_3 & V_264 )
F_230 ( L_75
L_76 ,
V_2 -> V_6 , ( unsigned long ) V_18 , V_2 -> V_18 , F_24 ( V_2 -> V_125 ) ,
V_2 -> V_19 , V_3 ) ;
return 0 ;
}
unsigned int F_231 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
static void F_232 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const char * V_49 )
{
#ifdef F_2
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
unsigned long * V_48 = F_233 ( F_234 ( V_14 -> V_17 ) *
sizeof( long ) , V_265 ) ;
if ( ! V_48 )
return;
F_61 ( V_2 , V_14 , L_18 , V_49 ) ;
F_26 ( V_14 ) ;
F_41 ( V_2 , V_14 , V_48 ) ;
F_119 (p, s, addr, page->objects) {
if ( ! F_235 ( F_20 ( V_5 , V_2 , V_21 ) , V_48 ) ) {
F_37 ( V_51 L_77 ,
V_5 , V_5 - V_21 ) ;
F_52 ( V_2 , V_5 ) ;
}
}
F_28 ( V_14 ) ;
F_7 ( V_48 ) ;
#endif
}
static void F_236 ( struct V_1 * V_2 , struct V_12 * V_40 )
{
struct V_14 * V_14 , * V_150 ;
F_137 (page, h, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_133 ( V_40 , V_14 ) ;
F_130 ( V_2 , V_14 ) ;
} else {
F_232 ( V_2 , V_14 ,
L_78 ) ;
}
}
}
static inline int F_237 ( struct V_1 * V_2 )
{
int V_13 ;
F_172 ( V_2 ) ;
F_238 ( V_2 -> V_9 ) ;
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_236 ( V_2 , V_40 ) ;
if ( V_40 -> V_155 || F_89 ( V_2 , V_13 ) )
return 1 ;
}
F_222 ( V_2 ) ;
return 0 ;
}
void F_239 ( struct V_1 * V_2 )
{
F_240 ( & V_266 ) ;
V_2 -> V_263 -- ;
if ( ! V_2 -> V_263 ) {
F_88 ( & V_2 -> V_267 ) ;
F_241 ( & V_266 ) ;
if ( F_237 ( V_2 ) ) {
F_37 ( V_51 L_79
L_80 , V_2 -> V_6 , V_268 ) ;
F_59 () ;
}
if ( V_2 -> V_3 & V_25 )
F_242 () ;
F_6 ( V_2 ) ;
} else
F_241 ( & V_266 ) ;
}
static int T_7 F_243 ( char * V_117 )
{
F_244 ( & V_117 , & V_236 ) ;
return 1 ;
}
static int T_7 F_245 ( char * V_117 )
{
F_244 ( & V_117 , & V_242 ) ;
V_242 = V_133 ( V_242 , V_243 - 1 ) ;
return 1 ;
}
static int T_7 F_246 ( char * V_117 )
{
F_244 ( & V_117 , & V_240 ) ;
return 1 ;
}
static int T_7 F_247 ( char * V_117 )
{
V_269 = 1 ;
return 1 ;
}
static struct V_1 * T_7 F_248 ( const char * V_6 ,
int V_18 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_193 ( V_1 , V_251 ) ;
if ( ! F_227 ( V_2 , V_6 , V_18 , V_270 ,
V_3 , NULL ) )
goto F_230;
F_86 ( & V_2 -> V_267 , & V_271 ) ;
return V_2 ;
F_230:
F_230 ( L_81 , V_6 , V_18 ) ;
return NULL ;
}
static inline int F_249 ( T_1 V_89 )
{
return ( V_89 - 1 ) / 8 ;
}
static struct V_1 * F_250 ( T_1 V_18 , T_5 V_3 )
{
int V_272 ;
if ( V_18 <= 192 ) {
if ( ! V_18 )
return V_273 ;
V_272 = V_274 [ F_249 ( V_18 ) ] ;
} else
V_272 = F_209 ( V_18 - 1 ) ;
#ifdef F_251
if ( F_3 ( ( V_3 & V_259 ) ) )
return V_275 [ V_272 ] ;
#endif
return V_276 [ V_272 ] ;
}
void * F_252 ( T_1 V_18 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_18 > V_277 ) )
return F_253 ( V_18 , V_3 ) ;
V_2 = F_250 ( V_18 , V_3 ) ;
if ( F_3 ( F_254 ( V_2 ) ) )
return V_2 ;
V_223 = F_190 ( V_2 , V_3 , V_127 , V_224 ) ;
F_196 ( V_224 , V_223 , V_18 , V_2 -> V_18 , V_3 ) ;
return V_223 ;
}
static void * F_255 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_278 = NULL ;
V_3 |= V_257 | V_126 ;
V_14 = F_256 ( V_13 , V_3 , F_183 ( V_18 ) ) ;
if ( V_14 )
V_278 = F_14 ( V_14 ) ;
F_257 ( V_278 , V_18 , 1 , V_3 ) ;
return V_278 ;
}
void * F_258 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_18 > V_277 ) ) {
V_223 = F_255 ( V_18 , V_3 , V_13 ) ;
F_202 ( V_224 , V_223 ,
V_18 , V_30 << F_183 ( V_18 ) ,
V_3 , V_13 ) ;
return V_223 ;
}
V_2 = F_250 ( V_18 , V_3 ) ;
if ( F_3 ( F_254 ( V_2 ) ) )
return V_2 ;
V_223 = F_190 ( V_2 , V_3 , V_13 , V_224 ) ;
F_202 ( V_224 , V_223 , V_18 , V_2 -> V_18 , V_3 , V_13 ) ;
return V_223 ;
}
T_1 F_259 ( const void * V_15 )
{
struct V_14 * V_14 ;
if ( F_3 ( V_15 == V_273 ) )
return 0 ;
V_14 = F_126 ( V_15 ) ;
if ( F_3 ( ! F_71 ( V_14 ) ) ) {
F_260 ( ! F_261 ( V_14 ) ) ;
return V_30 << F_68 ( V_14 ) ;
}
return F_21 ( V_14 -> V_116 ) ;
}
bool F_262 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
unsigned long V_3 ;
bool V_279 ;
if ( F_3 ( F_254 ( V_32 ) ) )
return false ;
F_39 ( V_3 ) ;
V_14 = F_126 ( V_32 ) ;
if ( F_3 ( ! F_71 ( V_14 ) ) ) {
V_279 = true ;
goto V_280;
}
F_26 ( V_14 ) ;
if ( F_72 ( V_14 -> V_116 , V_14 , V_15 ) ) {
F_60 ( V_14 -> V_116 , V_14 , V_15 , L_82 ) ;
V_279 = false ;
} else {
V_279 = true ;
}
F_28 ( V_14 ) ;
V_280:
F_40 ( V_3 ) ;
return V_279 ;
}
void F_7 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
F_263 ( V_224 , V_32 ) ;
if ( F_3 ( F_254 ( V_32 ) ) )
return;
V_14 = F_126 ( V_32 ) ;
if ( F_3 ( ! F_71 ( V_14 ) ) ) {
F_117 ( ! F_261 ( V_14 ) ) ;
F_264 ( V_32 ) ;
F_265 ( V_14 ) ;
return;
}
F_204 ( V_14 -> V_116 , V_14 , V_15 , V_224 ) ;
}
int F_266 ( struct V_1 * V_2 )
{
int V_13 ;
int V_58 ;
struct V_12 * V_40 ;
struct V_14 * V_14 ;
struct V_14 * V_73 ;
int V_17 = F_25 ( V_2 -> F_208 ) ;
struct V_152 * V_281 =
F_267 ( sizeof( struct V_152 ) * V_17 , V_253 ) ;
unsigned long V_3 ;
if ( ! V_281 )
return - V_282 ;
F_172 ( V_2 ) ;
F_223 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 -> V_155 )
continue;
for ( V_58 = 0 ; V_58 < V_17 ; V_58 ++ )
F_216 ( V_281 + V_58 ) ;
F_178 ( & V_40 -> V_163 , V_3 ) ;
F_137 (page, t, &n->partial, lru) {
F_268 ( & V_14 -> V_107 , V_281 + V_14 -> V_27 ) ;
if ( ! V_14 -> V_27 )
V_40 -> V_155 -- ;
}
for ( V_58 = V_17 - 1 ; V_58 > 0 ; V_58 -- )
F_269 ( V_281 + V_58 , V_40 -> V_157 . V_283 ) ;
F_180 ( & V_40 -> V_163 , V_3 ) ;
F_137 (page, t, slabs_by_inuse, lru)
F_130 ( V_2 , V_14 ) ;
}
F_7 ( V_281 ) ;
return 0 ;
}
static int F_270 ( void * V_284 )
{
struct V_1 * V_2 ;
F_271 ( & V_266 ) ;
F_179 (s, &slab_caches, list)
F_266 ( V_2 ) ;
F_272 ( & V_266 ) ;
return 0 ;
}
static void F_273 ( void * V_284 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_285 * V_286 = V_284 ;
int V_287 ;
V_287 = V_286 -> V_288 ;
if ( V_287 < 0 )
return;
F_271 ( & V_266 ) ;
F_179 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_287 ) ;
if ( V_40 ) {
F_117 ( F_89 ( V_2 , V_287 ) ) ;
V_2 -> V_13 [ V_287 ] = NULL ;
F_205 ( V_12 , V_40 ) ;
}
}
F_272 ( & V_266 ) ;
}
static int F_274 ( void * V_284 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_285 * V_286 = V_284 ;
int V_209 = V_286 -> V_288 ;
int V_223 = 0 ;
if ( V_209 < 0 )
return 0 ;
F_271 ( & V_266 ) ;
F_179 (s, &slab_caches, list) {
V_40 = F_193 ( V_12 , V_253 ) ;
if ( ! V_40 ) {
V_223 = - V_282 ;
goto V_115;
}
F_214 ( V_40 , V_2 ) ;
V_2 -> V_13 [ V_209 ] = V_40 ;
}
V_115:
F_272 ( & V_266 ) ;
return V_223 ;
}
static int F_275 ( struct V_289 * V_290 ,
unsigned long V_291 , void * V_284 )
{
int V_223 = 0 ;
switch ( V_291 ) {
case V_292 :
V_223 = F_274 ( V_284 ) ;
break;
case V_293 :
V_223 = F_270 ( V_284 ) ;
break;
case V_294 :
case V_295 :
F_273 ( V_284 ) ;
break;
case V_296 :
case V_297 :
break;
}
if ( V_223 )
V_223 = F_276 ( V_223 ) ;
else
V_223 = V_298 ;
return V_223 ;
}
static void T_7 F_277 ( struct V_1 * V_2 )
{
int V_13 ;
F_86 ( & V_2 -> V_267 , & V_271 ) ;
V_2 -> V_263 = - 1 ;
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
struct V_14 * V_5 ;
if ( V_40 ) {
F_179 (p, &n->partial, lru)
V_5 -> V_116 = V_2 ;
#ifdef F_2
F_179 (p, &n->full, lru)
V_5 -> V_116 = V_2 ;
#endif
}
}
}
void T_7 F_278 ( void )
{
int V_58 ;
int V_299 = 0 ;
struct V_1 * V_300 ;
int V_28 ;
struct V_1 * V_301 ;
unsigned long V_302 ;
if ( F_279 () )
V_242 = 0 ;
V_261 = F_280 ( struct V_1 , V_13 ) +
V_303 * sizeof( struct V_12 * ) ;
V_302 = F_213 ( V_261 , F_212 () ) ;
V_28 = F_183 ( 2 * V_302 ) ;
V_1 = ( void * ) F_281 ( V_251 , V_28 ) ;
V_12 = ( void * ) V_1 + V_302 ;
F_227 ( V_12 , L_83 ,
sizeof( struct V_12 ) ,
0 , V_246 | V_264 , NULL ) ;
F_282 ( F_275 , V_304 ) ;
V_10 = V_305 ;
V_300 = V_1 ;
F_227 ( V_1 , L_84 , V_261 ,
0 , V_246 | V_264 , NULL ) ;
V_1 = F_193 ( V_1 , V_251 ) ;
memcpy ( V_1 , V_300 , V_261 ) ;
V_301 = V_12 ;
V_12 = F_193 ( V_1 , V_251 ) ;
memcpy ( V_12 , V_301 , V_261 ) ;
F_277 ( V_12 ) ;
V_299 ++ ;
F_277 ( V_1 ) ;
V_299 ++ ;
F_283 ( ( unsigned long ) V_300 , V_28 ) ;
F_219 ( V_306 > 256 ||
( V_306 & ( V_306 - 1 ) ) ) ;
for ( V_58 = 8 ; V_58 < V_306 ; V_58 += 8 ) {
int V_307 = F_249 ( V_58 ) ;
if ( V_307 >= F_284 ( V_274 ) )
break;
V_274 [ V_307 ] = V_308 ;
}
if ( V_306 == 64 ) {
for ( V_58 = 64 + 8 ; V_58 <= 96 ; V_58 += 8 )
V_274 [ F_249 ( V_58 ) ] = 7 ;
} else if ( V_306 == 128 ) {
for ( V_58 = 128 + 8 ; V_58 <= 192 ; V_58 += 8 )
V_274 [ F_249 ( V_58 ) ] = 8 ;
}
if ( V_306 <= 32 ) {
V_276 [ 1 ] = F_248 ( L_85 , 96 , 0 ) ;
V_299 ++ ;
}
if ( V_306 <= 64 ) {
V_276 [ 2 ] = F_248 ( L_86 , 192 , 0 ) ;
V_299 ++ ;
}
for ( V_58 = V_308 ; V_58 < V_250 ; V_58 ++ ) {
V_276 [ V_58 ] = F_248 ( L_87 , 1 << V_58 , 0 ) ;
V_299 ++ ;
}
V_10 = V_11 ;
if ( V_306 <= 32 ) {
V_276 [ 1 ] -> V_6 = F_285 ( V_276 [ 1 ] -> V_6 , V_251 ) ;
F_117 ( ! V_276 [ 1 ] -> V_6 ) ;
}
if ( V_306 <= 64 ) {
V_276 [ 2 ] -> V_6 = F_285 ( V_276 [ 2 ] -> V_6 , V_251 ) ;
F_117 ( ! V_276 [ 2 ] -> V_6 ) ;
}
for ( V_58 = V_308 ; V_58 < V_250 ; V_58 ++ ) {
char * V_2 = F_286 ( V_251 , L_88 , 1 << V_58 ) ;
F_117 ( ! V_2 ) ;
V_276 [ V_58 ] -> V_6 = V_2 ;
}
#ifdef F_287
F_288 ( & V_309 ) ;
#endif
#ifdef F_251
for ( V_58 = 0 ; V_58 < V_250 ; V_58 ++ ) {
struct V_1 * V_2 = V_276 [ V_58 ] ;
if ( V_2 && V_2 -> V_18 ) {
char * V_6 = F_286 ( V_251 ,
L_89 , V_2 -> V_24 ) ;
F_117 ( ! V_6 ) ;
V_275 [ V_58 ] = F_248 ( V_6 ,
V_2 -> V_24 , V_258 ) ;
}
}
#endif
F_37 ( V_47
L_90
L_91 ,
V_299 , F_212 () ,
V_236 , V_242 , V_240 ,
V_241 , V_303 ) ;
}
void T_7 F_289 ( void )
{
}
static int F_290 ( struct V_1 * V_2 )
{
if ( V_269 || ( V_2 -> V_3 & V_310 ) )
return 1 ;
if ( V_2 -> F_103 )
return 1 ;
if ( V_2 -> V_263 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_291 ( T_1 V_18 ,
T_1 V_245 , unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
if ( V_269 || ( V_3 & V_310 ) )
return NULL ;
if ( F_103 )
return NULL ;
V_18 = F_213 ( V_18 , sizeof( void * ) ) ;
V_245 = F_211 ( V_3 , V_245 , V_18 ) ;
V_18 = F_213 ( V_18 , V_245 ) ;
V_3 = F_102 ( V_18 , V_3 , V_6 , NULL ) ;
F_179 (s, &slab_caches, list) {
if ( F_290 ( V_2 ) )
continue;
if ( V_18 > V_2 -> V_18 )
continue;
if ( ( V_3 & V_311 ) != ( V_2 -> V_3 & V_311 ) )
continue;
if ( ( V_2 -> V_18 & ~ ( V_245 - 1 ) ) != V_2 -> V_18 )
continue;
if ( V_2 -> V_18 - V_18 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_292 ( const char * V_6 , T_1 V_18 ,
T_1 V_245 , unsigned long V_3 , void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
char * V_40 ;
if ( F_260 ( ! V_6 ) )
return NULL ;
F_240 ( & V_266 ) ;
V_2 = F_291 ( V_18 , V_245 , V_3 , V_6 , F_103 ) ;
if ( V_2 ) {
V_2 -> V_263 ++ ;
V_2 -> V_24 = F_208 ( V_2 -> V_24 , ( int ) V_18 ) ;
V_2 -> V_27 = F_293 ( int , V_2 -> V_27 , F_213 ( V_18 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_263 -- ;
goto V_312;
}
F_241 ( & V_266 ) ;
return V_2 ;
}
V_40 = F_285 ( V_6 , V_253 ) ;
if ( ! V_40 )
goto V_312;
V_2 = F_267 ( V_261 , V_253 ) ;
if ( V_2 ) {
if ( F_227 ( V_2 , V_40 ,
V_18 , V_245 , V_3 , F_103 ) ) {
F_86 ( & V_2 -> V_267 , & V_271 ) ;
if ( F_4 ( V_2 ) ) {
F_88 ( & V_2 -> V_267 ) ;
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
goto V_312;
}
F_241 ( & V_266 ) ;
return V_2 ;
}
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
}
V_312:
F_241 ( & V_266 ) ;
if ( V_3 & V_264 )
F_230 ( L_92 , V_6 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int T_9 F_294 ( struct V_289 * V_313 ,
unsigned long V_291 , void * V_314 )
{
long V_66 = ( long ) V_314 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_291 ) {
case V_315 :
case V_316 :
case V_317 :
case V_318 :
F_271 ( & V_266 ) ;
F_179 (s, &slab_caches, list) {
F_39 ( V_3 ) ;
F_169 ( V_2 , V_66 ) ;
F_40 ( V_3 ) ;
}
F_272 ( & V_266 ) ;
break;
default:
break;
}
return V_298 ;
}
void * F_295 ( T_1 V_18 , T_5 V_208 , unsigned long V_319 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_18 > V_277 ) )
return F_253 ( V_18 , V_208 ) ;
V_2 = F_250 ( V_18 , V_208 ) ;
if ( F_3 ( F_254 ( V_2 ) ) )
return V_2 ;
V_223 = F_190 ( V_2 , V_208 , V_127 , V_319 ) ;
F_196 ( V_319 , V_223 , V_18 , V_2 -> V_18 , V_208 ) ;
return V_223 ;
}
void * F_296 ( T_1 V_18 , T_5 V_208 ,
int V_13 , unsigned long V_319 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_18 > V_277 ) ) {
V_223 = F_255 ( V_18 , V_208 , V_13 ) ;
F_202 ( V_319 , V_223 ,
V_18 , V_30 << F_183 ( V_18 ) ,
V_208 , V_13 ) ;
return V_223 ;
}
V_2 = F_250 ( V_18 , V_208 ) ;
if ( F_3 ( F_254 ( V_2 ) ) )
return V_2 ;
V_223 = F_190 ( V_2 , V_208 , V_13 , V_319 ) ;
F_202 ( V_319 , V_223 , V_18 , V_2 -> V_18 , V_208 , V_13 ) ;
return V_223 ;
}
static int F_297 ( struct V_14 * V_14 )
{
return V_14 -> V_27 ;
}
static int F_298 ( struct V_14 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_299 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_48 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
if ( ! F_70 ( V_2 , V_14 ) ||
! F_72 ( V_2 , V_14 , NULL ) )
return 0 ;
F_300 ( V_48 , V_14 -> V_17 ) ;
F_41 ( V_2 , V_14 , V_48 ) ;
F_119 (p, s, addr, page->objects) {
if ( F_235 ( F_20 ( V_5 , V_2 , V_21 ) , V_48 ) )
if ( ! F_69 ( V_2 , V_14 , V_5 , V_111 ) )
return 0 ;
}
F_119 (p, s, addr, page->objects)
if ( ! F_235 ( F_20 ( V_5 , V_2 , V_21 ) , V_48 ) )
if ( ! F_69 ( V_2 , V_14 , V_5 , V_95 ) )
return 0 ;
return 1 ;
}
static void F_301 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_48 )
{
F_26 ( V_14 ) ;
F_299 ( V_2 , V_14 , V_48 ) ;
F_28 ( V_14 ) ;
}
static int F_302 ( struct V_1 * V_2 ,
struct V_12 * V_40 , unsigned long * V_48 )
{
unsigned long V_320 = 0 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_178 ( & V_40 -> V_163 , V_3 ) ;
F_179 (page, &n->partial, lru) {
F_301 ( V_2 , V_14 , V_48 ) ;
V_320 ++ ;
}
if ( V_320 != V_40 -> V_155 )
F_37 ( V_51 L_93
L_94 , V_2 -> V_6 , V_320 , V_40 -> V_155 ) ;
if ( ! ( V_2 -> V_3 & V_26 ) )
goto V_115;
F_179 (page, &n->full, lru) {
F_301 ( V_2 , V_14 , V_48 ) ;
V_320 ++ ;
}
if ( V_320 != F_90 ( & V_40 -> V_109 ) )
F_37 ( V_51 L_95
L_94 , V_2 -> V_6 , V_320 ,
F_90 ( & V_40 -> V_109 ) ) ;
V_115:
F_180 ( & V_40 -> V_163 , V_3 ) ;
return V_320 ;
}
static long F_303 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_320 = 0 ;
unsigned long * V_48 = F_267 ( F_234 ( F_25 ( V_2 -> F_208 ) ) *
sizeof( unsigned long ) , V_253 ) ;
if ( ! V_48 )
return - V_282 ;
F_172 ( V_2 ) ;
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
V_320 += F_302 ( V_2 , V_40 , V_48 ) ;
}
F_7 ( V_48 ) ;
return V_320 ;
}
static void F_304 ( struct V_321 * V_73 )
{
if ( V_73 -> F_208 )
F_283 ( ( unsigned long ) V_73 -> V_322 ,
F_183 ( sizeof( struct V_323 ) * V_73 -> F_208 ) ) ;
}
static int F_305 ( struct V_321 * V_73 , unsigned long F_208 , T_5 V_3 )
{
struct V_323 * V_186 ;
int V_28 ;
V_28 = F_183 ( sizeof( struct V_323 ) * F_208 ) ;
V_186 = ( void * ) F_281 ( V_3 , V_28 ) ;
if ( ! V_186 )
return 0 ;
if ( V_73 -> V_320 ) {
memcpy ( V_186 , V_73 -> V_322 , sizeof( struct V_323 ) * V_73 -> V_320 ) ;
F_304 ( V_73 ) ;
}
V_73 -> F_208 = F_208 ;
V_73 -> V_322 = V_186 ;
return 1 ;
}
static int F_306 ( struct V_321 * V_73 , struct V_1 * V_2 ,
const struct V_53 * V_53 )
{
long V_87 , V_91 , V_324 ;
struct V_323 * V_186 ;
unsigned long V_325 ;
unsigned long V_326 = V_70 - V_53 -> V_69 ;
V_87 = - 1 ;
V_91 = V_73 -> V_320 ;
for ( ; ; ) {
V_324 = V_87 + ( V_91 - V_87 + 1 ) / 2 ;
if ( V_324 == V_91 )
break;
V_325 = V_73 -> V_322 [ V_324 ] . V_21 ;
if ( V_53 -> V_21 == V_325 ) {
V_186 = & V_73 -> V_322 [ V_324 ] ;
V_186 -> V_320 ++ ;
if ( V_53 -> V_69 ) {
V_186 -> V_327 += V_326 ;
if ( V_326 < V_186 -> V_328 )
V_186 -> V_328 = V_326 ;
if ( V_326 > V_186 -> V_329 )
V_186 -> V_329 = V_326 ;
if ( V_53 -> V_67 < V_186 -> V_330 )
V_186 -> V_330 = V_53 -> V_67 ;
if ( V_53 -> V_67 > V_186 -> V_331 )
V_186 -> V_331 = V_53 -> V_67 ;
F_307 ( V_53 -> V_66 ,
F_308 ( V_186 -> V_332 ) ) ;
}
F_309 ( F_118 ( F_310 ( V_53 ) ) , V_186 -> V_333 ) ;
return 1 ;
}
if ( V_53 -> V_21 < V_325 )
V_91 = V_324 ;
else
V_87 = V_324 ;
}
if ( V_73 -> V_320 >= V_73 -> F_208 && ! F_305 ( V_73 , 2 * V_73 -> F_208 , V_265 ) )
return 0 ;
V_186 = V_73 -> V_322 + V_324 ;
if ( V_324 < V_73 -> V_320 )
memmove ( V_186 + 1 , V_186 ,
( V_73 -> V_320 - V_324 ) * sizeof( struct V_323 ) ) ;
V_73 -> V_320 ++ ;
V_186 -> V_320 = 1 ;
V_186 -> V_21 = V_53 -> V_21 ;
V_186 -> V_327 = V_326 ;
V_186 -> V_328 = V_326 ;
V_186 -> V_329 = V_326 ;
V_186 -> V_330 = V_53 -> V_67 ;
V_186 -> V_331 = V_53 -> V_67 ;
F_311 ( F_308 ( V_186 -> V_332 ) ) ;
F_307 ( V_53 -> V_66 , F_308 ( V_186 -> V_332 ) ) ;
F_312 ( V_186 -> V_333 ) ;
F_309 ( F_118 ( F_310 ( V_53 ) ) , V_186 -> V_333 ) ;
return 1 ;
}
static void F_313 ( struct V_321 * V_73 , struct V_1 * V_2 ,
struct V_14 * V_14 , enum V_54 V_55 ,
unsigned long * V_48 )
{
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
F_300 ( V_48 , V_14 -> V_17 ) ;
F_41 ( V_2 , V_14 , V_48 ) ;
F_119 (p, s, addr, page->objects)
if ( ! F_235 ( F_20 ( V_5 , V_2 , V_21 ) , V_48 ) )
F_306 ( V_73 , V_2 , F_45 ( V_2 , V_5 , V_55 ) ) ;
}
static int F_314 ( struct V_1 * V_2 , char * V_75 ,
enum V_54 V_55 )
{
int V_334 = 0 ;
unsigned long V_58 ;
struct V_321 V_73 = { 0 , 0 , NULL } ;
int V_13 ;
unsigned long * V_48 = F_267 ( F_234 ( F_25 ( V_2 -> F_208 ) ) *
sizeof( unsigned long ) , V_253 ) ;
if ( ! V_48 || ! F_305 ( & V_73 , V_30 / sizeof( struct V_323 ) ,
V_335 ) ) {
F_7 ( V_48 ) ;
return sprintf ( V_75 , L_96 ) ;
}
F_172 ( V_2 ) ;
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_3 ;
struct V_14 * V_14 ;
if ( ! F_90 ( & V_40 -> V_109 ) )
continue;
F_178 ( & V_40 -> V_163 , V_3 ) ;
F_179 (page, &n->partial, lru)
F_313 ( & V_73 , V_2 , V_14 , V_55 , V_48 ) ;
F_179 (page, &n->full, lru)
F_313 ( & V_73 , V_2 , V_14 , V_55 , V_48 ) ;
F_180 ( & V_40 -> V_163 , V_3 ) ;
}
for ( V_58 = 0 ; V_58 < V_73 . V_320 ; V_58 ++ ) {
struct V_323 * V_186 = & V_73 . V_322 [ V_58 ] ;
if ( V_334 > V_30 - V_336 - 100 )
break;
V_334 += sprintf ( V_75 + V_334 , L_97 , V_186 -> V_320 ) ;
if ( V_186 -> V_21 )
V_334 += sprintf ( V_75 + V_334 , L_98 , ( void * ) V_186 -> V_21 ) ;
else
V_334 += sprintf ( V_75 + V_334 , L_99 ) ;
if ( V_186 -> V_327 != V_186 -> V_328 ) {
V_334 += sprintf ( V_75 + V_334 , L_100 ,
V_186 -> V_328 ,
( long ) F_315 ( V_186 -> V_327 , V_186 -> V_320 ) ,
V_186 -> V_329 ) ;
} else
V_334 += sprintf ( V_75 + V_334 , L_101 ,
V_186 -> V_328 ) ;
if ( V_186 -> V_330 != V_186 -> V_331 )
V_334 += sprintf ( V_75 + V_334 , L_102 ,
V_186 -> V_330 , V_186 -> V_331 ) ;
else
V_334 += sprintf ( V_75 + V_334 , L_103 ,
V_186 -> V_330 ) ;
if ( F_316 () > 1 &&
! F_317 ( F_308 ( V_186 -> V_332 ) ) &&
V_334 < V_30 - 60 ) {
V_334 += sprintf ( V_75 + V_334 , L_104 ) ;
V_334 += F_318 ( V_75 + V_334 , V_30 - V_334 - 50 ,
F_308 ( V_186 -> V_332 ) ) ;
}
if ( V_337 > 1 && ! F_319 ( V_186 -> V_333 ) &&
V_334 < V_30 - 60 ) {
V_334 += sprintf ( V_75 + V_334 , L_105 ) ;
V_334 += F_320 ( V_75 + V_334 , V_30 - V_334 - 50 ,
V_186 -> V_333 ) ;
}
V_334 += sprintf ( V_75 + V_334 , L_106 ) ;
}
F_304 ( & V_73 ) ;
F_7 ( V_48 ) ;
if ( ! V_73 . V_320 )
V_334 += sprintf ( V_75 , L_107 ) ;
return V_334 ;
}
static void F_321 ( void )
{
T_3 * V_5 ;
F_219 ( V_306 > 16 || V_250 < 10 ) ;
F_37 ( V_51 L_108 ) ;
F_37 ( V_51 L_109 ) ;
F_37 ( V_51 L_110 ) ;
V_5 = F_233 ( 16 , V_253 ) ;
V_5 [ 16 ] = 0x12 ;
F_37 ( V_51 L_111
L_112 , V_5 + 16 ) ;
F_303 ( V_276 [ 4 ] ) ;
V_5 = F_233 ( 32 , V_253 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_37 ( V_51 L_113
L_114 , V_5 ) ;
F_37 ( V_51
L_115 ) ;
F_303 ( V_276 [ 5 ] ) ;
V_5 = F_233 ( 64 , V_253 ) ;
V_5 += 64 + ( F_143 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_37 ( V_51 L_116 ,
V_5 ) ;
F_37 ( V_51
L_115 ) ;
F_303 ( V_276 [ 6 ] ) ;
F_37 ( V_51 L_117 ) ;
V_5 = F_233 ( 128 , V_253 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_37 ( V_51 L_118 , V_5 ) ;
F_303 ( V_276 [ 7 ] ) ;
V_5 = F_233 ( 256 , V_253 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_37 ( V_51 L_119 ,
V_5 ) ;
F_303 ( V_276 [ 8 ] ) ;
V_5 = F_233 ( 512 , V_253 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_37 ( V_51 L_120 , V_5 ) ;
F_303 ( V_276 [ 9 ] ) ;
}
static void F_321 ( void ) {}
static T_10 F_322 ( struct V_1 * V_2 ,
char * V_75 , unsigned long V_3 )
{
unsigned long V_338 = 0 ;
int V_13 ;
int V_32 ;
unsigned long * V_333 ;
unsigned long * V_339 ;
V_333 = F_233 ( 2 * sizeof( unsigned long ) * V_303 , V_253 ) ;
if ( ! V_333 )
return - V_282 ;
V_339 = V_333 + V_303 ;
if ( V_3 & V_340 ) {
int V_66 ;
F_161 (cpu) {
struct V_160 * V_161 = F_162 ( V_2 -> V_9 , V_66 ) ;
int V_13 = F_323 ( V_161 -> V_13 ) ;
struct V_14 * V_14 ;
if ( V_13 < 0 )
continue;
V_14 = F_323 ( V_161 -> V_14 ) ;
if ( V_14 ) {
if ( V_3 & V_341 )
V_32 = V_14 -> V_17 ;
else if ( V_3 & V_342 )
V_32 = V_14 -> V_27 ;
else
V_32 = 1 ;
V_338 += V_32 ;
V_333 [ V_13 ] += V_32 ;
}
V_14 = V_161 -> V_157 ;
if ( V_14 ) {
V_32 = V_14 -> V_204 ;
V_338 += V_32 ;
V_333 [ V_13 ] += V_32 ;
}
V_339 [ V_13 ] ++ ;
}
}
F_324 () ;
#ifdef F_2
if ( V_3 & V_343 ) {
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_341 )
V_32 = F_90 ( & V_40 -> V_110 ) ;
else if ( V_3 & V_342 )
V_32 = F_90 ( & V_40 -> V_110 ) -
F_176 ( V_40 , F_175 ) ;
else
V_32 = F_90 ( & V_40 -> V_109 ) ;
V_338 += V_32 ;
V_333 [ V_13 ] += V_32 ;
}
} else
#endif
if ( V_3 & V_344 ) {
F_223 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_341 )
V_32 = F_176 ( V_40 , F_298 ) ;
else if ( V_3 & V_342 )
V_32 = F_176 ( V_40 , F_297 ) ;
else
V_32 = V_40 -> V_155 ;
V_338 += V_32 ;
V_333 [ V_13 ] += V_32 ;
}
}
V_32 = sprintf ( V_75 , L_121 , V_338 ) ;
#ifdef F_141
F_223 (node, N_NORMAL_MEMORY)
if ( V_333 [ V_13 ] )
V_32 += sprintf ( V_75 + V_32 , L_122 ,
V_13 , V_333 [ V_13 ] ) ;
#endif
F_325 () ;
F_7 ( V_333 ) ;
return V_32 + sprintf ( V_75 + V_32 , L_106 ) ;
}
static int F_326 ( struct V_1 * V_2 )
{
int V_13 ;
F_184 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
if ( F_90 ( & V_40 -> V_110 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_327 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_18 ) ;
}
static T_10 F_328 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_245 ) ;
}
static T_10 F_329 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_24 ) ;
}
static T_10 F_330 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , F_25 ( V_2 -> V_125 ) ) ;
}
static T_10 F_331 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_28 ;
int V_312 ;
V_312 = F_332 ( V_75 , 10 , & V_28 ) ;
if ( V_312 )
return V_312 ;
if ( V_28 > V_242 || V_28 < V_236 )
return - V_345 ;
F_226 ( V_2 , V_28 ) ;
return V_50 ;
}
static T_10 F_333 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , F_24 ( V_2 -> V_125 ) ) ;
}
static T_10 F_334 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_124 , V_2 -> V_175 ) ;
}
static T_10 F_335 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_133 ;
int V_312 ;
V_312 = F_332 ( V_75 , 10 , & V_133 ) ;
if ( V_312 )
return V_312 ;
F_225 ( V_2 , V_133 ) ;
return V_50 ;
}
static T_10 F_336 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_125 , V_2 -> V_166 ) ;
}
static T_10 F_337 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_17 ;
int V_312 ;
V_312 = F_332 ( V_75 , 10 , & V_17 ) ;
if ( V_312 )
return V_312 ;
if ( V_17 && F_1 ( V_2 ) )
return - V_345 ;
V_2 -> V_166 = V_17 ;
F_172 ( V_2 ) ;
return V_50 ;
}
static T_10 F_338 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! V_2 -> F_103 )
return 0 ;
return sprintf ( V_75 , L_126 , V_2 -> F_103 ) ;
}
static T_10 F_339 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_263 - 1 ) ;
}
static T_10 F_340 ( struct V_1 * V_2 , char * V_75 )
{
return F_322 ( V_2 , V_75 , V_344 ) ;
}
static T_10 F_341 ( struct V_1 * V_2 , char * V_75 )
{
return F_322 ( V_2 , V_75 , V_340 ) ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_75 )
{
return F_322 ( V_2 , V_75 , V_343 | V_342 ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , char * V_75 )
{
return F_322 ( V_2 , V_75 , V_344 | V_342 ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_75 )
{
int V_17 = 0 ;
int V_137 = 0 ;
int V_66 ;
int V_334 ;
F_345 (cpu) {
struct V_14 * V_14 = F_162 ( V_2 -> V_9 , V_66 ) -> V_157 ;
if ( V_14 ) {
V_137 += V_14 -> V_137 ;
V_17 += V_14 -> V_204 ;
}
}
V_334 = sprintf ( V_75 , L_127 , V_17 , V_137 ) ;
#ifdef F_287
F_345 (cpu) {
struct V_14 * V_14 = F_162 ( V_2 -> V_9 , V_66 ) -> V_157 ;
if ( V_14 && V_334 < V_30 - 20 )
V_334 += sprintf ( V_75 + V_334 , L_128 , V_66 ,
V_14 -> V_204 , V_14 -> V_137 ) ;
}
#endif
return V_334 + sprintf ( V_75 + V_334 , L_106 ) ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_138 ) ) ;
}
static T_10 F_347 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_138 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_138 ;
return V_50 ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_246 ) ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_258 ) ) ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_25 ) ) ;
}
static T_10 F_351 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_29 ) ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_75 )
{
return F_322 ( V_2 , V_75 , V_343 ) ;
}
static T_10 F_353 ( struct V_1 * V_2 , char * V_75 )
{
return F_322 ( V_2 , V_75 , V_343 | V_341 ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_122 ) ) ;
}
static T_10 F_355 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_122 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_122 ;
}
return V_50 ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_10 F_357 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_101 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_101 ;
}
return V_50 ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_359 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_326 ( V_2 ) )
return - V_346 ;
V_2 -> V_3 &= ~ V_22 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_22 ;
}
F_226 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_326 ( V_2 ) )
return - V_346 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_23 ;
}
F_226 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_26 ) ) ;
}
static T_10 F_363 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_326 ( V_2 ) )
return - V_346 ;
V_2 -> V_3 &= ~ V_26 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_26 ;
}
F_226 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_10 F_364 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_10 F_365 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
int V_223 = - V_345 ;
if ( V_75 [ 0 ] == '1' ) {
V_223 = F_303 ( V_2 ) ;
if ( V_223 >= 0 )
V_223 = V_50 ;
}
return V_223 ;
}
static T_10 F_366 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_244 ;
return F_314 ( V_2 , V_75 , V_72 ) ;
}
static T_10 F_367 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_244 ;
return F_314 ( V_2 , V_75 , V_71 ) ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , ! ! ( V_2 -> V_3 & V_123 ) ) ;
}
static T_10 F_369 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_123 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_123 ;
return V_50 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_10 F_371 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( V_75 [ 0 ] == '1' ) {
int V_113 = F_266 ( V_2 ) ;
if ( V_113 )
return V_113 ;
} else
return - V_345 ;
return V_50 ;
}
static T_10 F_372 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_123 , V_2 -> V_173 / 10 ) ;
}
static T_10 F_373 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_347 ;
int V_312 ;
V_312 = F_332 ( V_75 , 10 , & V_347 ) ;
if ( V_312 )
return V_312 ;
if ( V_347 <= 100 )
V_2 -> V_173 = V_347 * 10 ;
return V_50 ;
}
static int F_374 ( struct V_1 * V_2 , char * V_75 , enum V_7 V_8 )
{
unsigned long V_348 = 0 ;
int V_66 ;
int V_334 ;
int * V_83 = F_267 ( V_241 * sizeof( int ) , V_253 ) ;
if ( ! V_83 )
return - V_282 ;
F_345 (cpu) {
unsigned V_32 = F_162 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] ;
V_83 [ V_66 ] = V_32 ;
V_348 += V_32 ;
}
V_334 = sprintf ( V_75 , L_121 , V_348 ) ;
#ifdef F_287
F_345 (cpu) {
if ( V_83 [ V_66 ] && V_334 < V_30 - 20 )
V_334 += sprintf ( V_75 + V_334 , L_129 , V_66 , V_83 [ V_66 ] ) ;
}
#endif
F_7 ( V_83 ) ;
return V_334 + sprintf ( V_75 + V_334 , L_106 ) ;
}
static void F_375 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_66 ;
F_345 (cpu)
F_162 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] = 0 ;
}
static T_10 F_376 ( struct V_349 * V_350 ,
struct V_351 * V_352 ,
char * V_75 )
{
struct V_353 * V_351 ;
struct V_1 * V_2 ;
int V_312 ;
V_351 = F_377 ( V_352 ) ;
V_2 = F_378 ( V_350 ) ;
if ( ! V_351 -> V_354 )
return - V_355 ;
V_312 = V_351 -> V_354 ( V_2 , V_75 ) ;
return V_312 ;
}
static T_10 F_379 ( struct V_349 * V_350 ,
struct V_351 * V_352 ,
const char * V_75 , T_1 V_334 )
{
struct V_353 * V_351 ;
struct V_1 * V_2 ;
int V_312 ;
V_351 = F_377 ( V_352 ) ;
V_2 = F_378 ( V_350 ) ;
if ( ! V_351 -> V_356 )
return - V_355 ;
V_312 = V_351 -> V_356 ( V_2 , V_75 , V_334 ) ;
return V_312 ;
}
static void F_380 ( struct V_349 * V_350 )
{
struct V_1 * V_2 = F_378 ( V_350 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_381 ( struct V_357 * V_357 , struct V_349 * V_350 )
{
struct V_358 * V_359 = F_382 ( V_350 ) ;
if ( V_359 == & V_360 )
return 1 ;
return 0 ;
}
static char * F_383 ( struct V_1 * V_2 )
{
char * V_6 = F_267 ( V_361 , V_253 ) ;
char * V_5 = V_6 ;
F_117 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_258 )
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
F_117 ( V_5 > V_6 + V_361 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_312 ;
const char * V_6 ;
int V_362 ;
if ( V_10 < V_363 )
return 0 ;
V_362 = F_290 ( V_2 ) ;
if ( V_362 ) {
F_384 ( & V_364 -> V_350 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_383 ( V_2 ) ;
}
V_2 -> V_350 . V_357 = V_364 ;
V_312 = F_385 ( & V_2 -> V_350 , & V_360 , NULL , V_6 ) ;
if ( V_312 ) {
F_386 ( & V_2 -> V_350 ) ;
return V_312 ;
}
V_312 = F_387 ( & V_2 -> V_350 , & V_365 ) ;
if ( V_312 ) {
F_388 ( & V_2 -> V_350 ) ;
F_386 ( & V_2 -> V_350 ) ;
return V_312 ;
}
F_389 ( & V_2 -> V_350 , V_366 ) ;
if ( ! V_362 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_10 < V_363 )
return;
F_389 ( & V_2 -> V_350 , V_367 ) ;
F_388 ( & V_2 -> V_350 ) ;
F_386 ( & V_2 -> V_350 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_368 * V_369 ;
if ( V_10 == V_363 ) {
F_384 ( & V_364 -> V_350 , V_6 ) ;
return F_390 ( & V_364 -> V_350 , & V_2 -> V_350 , V_6 ) ;
}
V_369 = F_267 ( sizeof( struct V_368 ) , V_253 ) ;
if ( ! V_369 )
return - V_282 ;
V_369 -> V_2 = V_2 ;
V_369 -> V_6 = V_6 ;
V_369 -> V_198 = V_370 ;
V_370 = V_369 ;
return 0 ;
}
static int T_7 F_391 ( void )
{
struct V_1 * V_2 ;
int V_312 ;
F_240 ( & V_266 ) ;
V_364 = F_392 ( L_131 , & V_371 , V_372 ) ;
if ( ! V_364 ) {
F_241 ( & V_266 ) ;
F_37 ( V_51 L_132 ) ;
return - V_244 ;
}
V_10 = V_363 ;
F_179 (s, &slab_caches, list) {
V_312 = F_4 ( V_2 ) ;
if ( V_312 )
F_37 ( V_51 L_133
L_134 , V_2 -> V_6 ) ;
}
while ( V_370 ) {
struct V_368 * V_369 = V_370 ;
V_370 = V_370 -> V_198 ;
V_312 = F_5 ( V_369 -> V_2 , V_369 -> V_6 ) ;
if ( V_312 )
F_37 ( V_51 L_135
L_136 , V_2 -> V_6 ) ;
F_7 ( V_369 ) ;
}
F_241 ( & V_266 ) ;
F_321 () ;
return 0 ;
}
static void F_393 ( struct V_373 * V_187 )
{
F_394 ( V_187 , L_137 ) ;
F_394 ( V_187 , L_138
L_139 ) ;
F_394 ( V_187 , L_140 ) ;
F_394 ( V_187 , L_141 ) ;
F_395 ( V_187 , '\n' ) ;
}
static void * F_396 ( struct V_373 * V_187 , T_11 * V_324 )
{
T_11 V_40 = * V_324 ;
F_271 ( & V_266 ) ;
if ( ! V_40 )
F_393 ( V_187 ) ;
return F_397 ( & V_271 , * V_324 ) ;
}
static void * F_398 ( struct V_373 * V_187 , void * V_5 , T_11 * V_324 )
{
return F_399 ( V_5 , & V_271 , V_324 ) ;
}
static void F_400 ( struct V_373 * V_187 , void * V_5 )
{
F_272 ( & V_266 ) ;
}
static int F_401 ( struct V_373 * V_187 , void * V_5 )
{
unsigned long V_374 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_375 = 0 ;
unsigned long V_211 = 0 ;
unsigned long V_212 = 0 ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_402 ( V_5 , struct V_1 , V_267 ) ;
F_184 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
V_374 += V_40 -> V_155 ;
V_109 += F_90 ( & V_40 -> V_109 ) ;
V_211 += F_90 ( & V_40 -> V_110 ) ;
V_212 += F_176 ( V_40 , F_175 ) ;
}
V_375 = V_211 - V_212 ;
F_403 ( V_187 , L_142 , V_2 -> V_6 , V_375 ,
V_211 , V_2 -> V_18 , F_25 ( V_2 -> V_125 ) ,
( 1 << F_24 ( V_2 -> V_125 ) ) ) ;
F_403 ( V_187 , L_143 , 0 , 0 , 0 ) ;
F_403 ( V_187 , L_144 , V_109 , V_109 ,
0UL ) ;
F_395 ( V_187 , '\n' ) ;
return 0 ;
}
static int F_404 ( struct V_376 * V_376 , struct V_377 * V_377 )
{
return F_405 ( V_377 , & V_378 ) ;
}
static int T_7 F_406 ( void )
{
F_407 ( L_145 , V_379 , NULL , & V_380 ) ;
return 0 ;
}
