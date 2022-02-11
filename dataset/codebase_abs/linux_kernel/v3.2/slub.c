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
#ifdef F_33
if ( V_2 -> V_3 & V_41 ) {
if ( F_34 ( & V_14 -> V_42 ,
V_36 , V_37 ,
V_38 , V_39 ) )
return 1 ;
} else
#endif
{
F_26 ( V_14 ) ;
if ( V_14 -> V_42 == V_36 && V_14 -> V_43 == V_37 ) {
V_14 -> V_42 = V_38 ;
V_14 -> V_43 = V_39 ;
F_28 ( V_14 ) ;
return 1 ;
}
F_28 ( V_14 ) ;
}
F_35 () ;
F_8 ( V_2 , V_44 ) ;
#ifdef F_36
F_37 ( V_45 L_1 , V_40 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static inline bool F_38 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_36 , unsigned long V_37 ,
void * V_38 , unsigned long V_39 ,
const char * V_40 )
{
#ifdef F_33
if ( V_2 -> V_3 & V_41 ) {
if ( F_34 ( & V_14 -> V_42 ,
V_36 , V_37 ,
V_38 , V_39 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_26 ( V_14 ) ;
if ( V_14 -> V_42 == V_36 && V_14 -> V_43 == V_37 ) {
V_14 -> V_42 = V_38 ;
V_14 -> V_43 = V_39 ;
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
return 1 ;
}
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
}
F_35 () ;
F_8 ( V_2 , V_44 ) ;
#ifdef F_36
F_37 ( V_45 L_1 , V_40 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_14 * V_14 , unsigned long * V_46 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
for ( V_5 = V_14 -> V_42 ; V_5 ; V_5 = F_15 ( V_2 , V_5 ) )
F_42 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) ;
}
static void F_43 ( char * V_47 , T_3 * V_21 , unsigned int V_48 )
{
F_44 ( V_49 , V_47 , V_50 , 16 , 1 , V_21 ,
V_48 , 1 ) ;
}
static struct V_51 * F_45 ( struct V_1 * V_2 , void * V_15 ,
enum V_52 V_53 )
{
struct V_51 * V_5 ;
if ( V_2 -> V_19 )
V_5 = V_15 + V_2 -> V_19 + sizeof( void * ) ;
else
V_5 = V_15 + V_2 -> V_27 ;
return V_5 + V_53 ;
}
static void F_46 ( struct V_1 * V_2 , void * V_15 ,
enum V_52 V_53 , unsigned long V_21 )
{
struct V_51 * V_5 = F_45 ( V_2 , V_15 , V_53 ) ;
if ( V_21 ) {
#ifdef F_47
struct V_54 V_55 ;
int V_56 ;
V_55 . V_57 = 0 ;
V_55 . V_58 = V_59 ;
V_55 . V_60 = V_5 -> V_61 ;
V_55 . V_62 = 3 ;
F_48 ( & V_55 ) ;
if ( V_55 . V_57 != 0 &&
V_55 . V_60 [ V_55 . V_57 - 1 ] == V_63 )
V_55 . V_57 -- ;
for ( V_56 = V_55 . V_57 ; V_56 < V_59 ; V_56 ++ )
V_5 -> V_61 [ V_56 ] = 0 ;
#endif
V_5 -> V_21 = V_21 ;
V_5 -> V_64 = F_49 () ;
V_5 -> V_65 = V_66 -> V_65 ;
V_5 -> V_67 = V_68 ;
} else
memset ( V_5 , 0 , sizeof( struct V_51 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_46 ( V_2 , V_15 , V_69 , 0UL ) ;
F_46 ( V_2 , V_15 , V_70 , 0UL ) ;
}
static void F_51 ( const char * V_2 , struct V_51 * V_71 )
{
if ( ! V_71 -> V_21 )
return;
F_37 ( V_49 L_2 ,
V_2 , ( void * ) V_71 -> V_21 , V_68 - V_71 -> V_67 , V_71 -> V_64 , V_71 -> V_65 ) ;
#ifdef F_47
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_59 ; V_56 ++ )
if ( V_71 -> V_61 [ V_56 ] )
F_37 ( V_49 L_3 , ( void * ) V_71 -> V_61 [ V_56 ] ) ;
else
break;
}
#endif
}
static void F_52 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_51 ( L_4 , F_45 ( V_2 , V_15 , V_70 ) ) ;
F_51 ( L_5 , F_45 ( V_2 , V_15 , V_69 ) ) ;
}
static void F_53 ( struct V_14 * V_14 )
{
F_37 ( V_49 L_6 ,
V_14 , V_14 -> V_17 , V_14 -> V_27 , V_14 -> V_42 , V_14 -> V_3 ) ;
}
static void F_54 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_37 ( V_49 L_7
L_8 ) ;
F_37 ( V_49 L_9 , V_2 -> V_6 , V_73 ) ;
F_37 ( V_49 L_10
L_11 ) ;
}
static void F_55 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_37 ( V_49 L_12 , V_2 -> V_6 , V_73 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned int V_74 ;
T_3 * V_21 = F_14 ( V_14 ) ;
F_52 ( V_2 , V_5 ) ;
F_53 ( V_14 ) ;
F_37 ( V_49 L_13 ,
V_5 , V_5 - V_21 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_21 + 16 )
F_43 ( L_14 , V_5 - 16 , 16 ) ;
F_43 ( L_15 , V_5 , F_57 (unsigned long, s->objsize,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_22 )
F_43 ( L_16 , V_5 + V_2 -> V_24 ,
V_2 -> V_27 - V_2 -> V_24 ) ;
if ( V_2 -> V_19 )
V_74 = V_2 -> V_19 + sizeof( void * ) ;
else
V_74 = V_2 -> V_27 ;
if ( V_2 -> V_3 & V_26 )
V_74 += 2 * sizeof( struct V_51 ) ;
if ( V_74 != V_2 -> V_18 )
F_43 ( L_17 , V_5 + V_74 , V_2 -> V_18 - V_74 ) ;
F_58 () ;
}
static void F_59 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_75 )
{
F_54 ( V_2 , L_18 , V_75 ) ;
F_56 ( V_2 , V_14 , V_15 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_14 * V_14 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_54 ( V_2 , L_18 , V_73 ) ;
F_53 ( V_14 ) ;
F_58 () ;
}
static void F_61 ( struct V_1 * V_2 , void * V_15 , T_3 V_76 )
{
T_3 * V_5 = V_15 ;
if ( V_2 -> V_3 & V_77 ) {
memset ( V_5 , V_78 , V_2 -> V_24 - 1 ) ;
V_5 [ V_2 -> V_24 - 1 ] = V_79 ;
}
if ( V_2 -> V_3 & V_22 )
memset ( V_5 + V_2 -> V_24 , V_76 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
static void F_62 ( struct V_1 * V_2 , char * V_80 , T_3 V_81 ,
void * V_82 , void * V_83 )
{
F_55 ( V_2 , L_19 , V_82 , V_83 - 1 , V_81 ) ;
memset ( V_82 , V_81 , V_83 - V_82 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_84 ,
T_3 * V_85 , unsigned int V_86 , unsigned int V_87 )
{
T_3 * V_88 ;
T_3 * V_89 ;
V_88 = F_64 ( V_85 , V_86 , V_87 ) ;
if ( ! V_88 )
return 1 ;
V_89 = V_85 + V_87 ;
while ( V_89 > V_88 && V_89 [ - 1 ] == V_86 )
V_89 -- ;
F_54 ( V_2 , L_20 , V_84 ) ;
F_37 ( V_49 L_21 ,
V_88 , V_89 - 1 , V_88 [ 0 ] , V_86 ) ;
F_56 ( V_2 , V_14 , V_15 ) ;
F_62 ( V_2 , V_84 , V_86 , V_88 , V_89 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned long V_74 = V_2 -> V_27 ;
if ( V_2 -> V_19 )
V_74 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_26 )
V_74 += 2 * sizeof( struct V_51 ) ;
if ( V_2 -> V_18 == V_74 )
return 1 ;
return F_63 ( V_2 , V_14 , V_5 , L_22 ,
V_5 + V_74 , V_90 , V_2 -> V_18 - V_74 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
T_3 * V_85 ;
T_3 * V_88 ;
T_3 * V_89 ;
int V_48 ;
int V_91 ;
if ( ! ( V_2 -> V_3 & V_23 ) )
return 1 ;
V_85 = F_14 ( V_14 ) ;
V_48 = ( V_30 << F_67 ( V_14 ) ) - V_2 -> V_29 ;
V_89 = V_85 + V_48 ;
V_91 = V_48 % V_2 -> V_18 ;
if ( ! V_91 )
return 1 ;
V_88 = F_64 ( V_89 - V_91 , V_90 , V_91 ) ;
if ( ! V_88 )
return 1 ;
while ( V_89 > V_88 && V_89 [ - 1 ] == V_90 )
V_89 -- ;
F_60 ( V_2 , V_14 , L_23 , V_88 , V_89 - 1 ) ;
F_43 ( L_17 , V_89 - V_91 , V_91 ) ;
F_62 ( V_2 , L_24 , V_90 , V_89 - V_91 , V_89 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_76 )
{
T_3 * V_5 = V_15 ;
T_3 * V_92 = V_15 + V_2 -> V_24 ;
if ( V_2 -> V_3 & V_22 ) {
if ( ! F_63 ( V_2 , V_14 , V_15 , L_25 ,
V_92 , V_76 , V_2 -> V_27 - V_2 -> V_24 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_23 ) && V_2 -> V_24 < V_2 -> V_27 ) {
F_63 ( V_2 , V_14 , V_5 , L_26 ,
V_92 , V_90 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
}
if ( V_2 -> V_3 & V_23 ) {
if ( V_76 != V_93 && ( V_2 -> V_3 & V_77 ) &&
( ! F_63 ( V_2 , V_14 , V_5 , L_27 , V_5 ,
V_78 , V_2 -> V_24 - 1 ) ||
! F_63 ( V_2 , V_14 , V_5 , L_27 ,
V_5 + V_2 -> V_24 - 1 , V_79 , 1 ) ) )
return 0 ;
F_65 ( V_2 , V_14 , V_5 ) ;
}
if ( ! V_2 -> V_19 && V_76 == V_93 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , F_15 ( V_2 , V_5 ) ) ) {
F_59 ( V_2 , V_14 , V_5 , L_28 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_94 ;
F_31 ( ! F_32 () ) ;
if ( ! F_70 ( V_14 ) ) {
F_60 ( V_2 , V_14 , L_29 ) ;
return 0 ;
}
V_94 = F_22 ( F_67 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_14 -> V_17 > V_94 ) {
F_60 ( V_2 , V_14 , L_30 ,
V_2 -> V_6 , V_14 -> V_17 , V_94 ) ;
return 0 ;
}
if ( V_14 -> V_27 > V_14 -> V_17 ) {
F_60 ( V_2 , V_14 , L_31 ,
V_2 -> V_6 , V_14 -> V_27 , V_14 -> V_17 ) ;
return 0 ;
}
F_66 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_95 )
{
int V_96 = 0 ;
void * V_20 ;
void * V_15 = NULL ;
unsigned long V_97 ;
V_20 = V_14 -> V_42 ;
while ( V_20 && V_96 <= V_14 -> V_17 ) {
if ( V_20 == V_95 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , V_20 ) ) {
if ( V_15 ) {
F_59 ( V_2 , V_14 , V_15 ,
L_32 ) ;
F_19 ( V_2 , V_15 , NULL ) ;
break;
} else {
F_60 ( V_2 , V_14 , L_28 ) ;
V_14 -> V_42 = NULL ;
V_14 -> V_27 = V_14 -> V_17 ;
F_55 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_15 = V_20 ;
V_20 = F_15 ( V_2 , V_15 ) ;
V_96 ++ ;
}
V_97 = F_22 ( F_67 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_97 > V_98 )
V_97 = V_98 ;
if ( V_14 -> V_17 != V_97 ) {
F_60 ( V_2 , V_14 , L_34
L_35 , V_14 -> V_17 , V_97 ) ;
V_14 -> V_17 = V_97 ;
F_55 ( V_2 , L_36 ) ;
}
if ( V_14 -> V_27 != V_14 -> V_17 - V_96 ) {
F_60 ( V_2 , V_14 , L_37
L_38 , V_14 -> V_27 , V_14 -> V_17 - V_96 ) ;
V_14 -> V_27 = V_14 -> V_17 - V_96 ;
F_55 ( V_2 , L_39 ) ;
}
return V_95 == NULL ;
}
static void V_55 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_15 ,
int V_53 )
{
if ( V_2 -> V_3 & V_99 ) {
F_37 ( V_45 L_40 ,
V_2 -> V_6 ,
V_53 ? L_41 : L_42 ,
V_15 , V_14 -> V_27 ,
V_14 -> V_42 ) ;
if ( ! V_53 )
F_43 ( L_15 , ( void * ) V_15 , V_2 -> V_24 ) ;
F_58 () ;
}
}
static inline int F_72 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_100 ;
F_73 ( V_3 ) ;
F_74 ( V_3 & V_101 ) ;
return F_75 ( V_2 -> V_24 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_76 ( struct V_1 * V_2 , T_5 V_3 , void * V_15 )
{
V_3 &= V_100 ;
F_77 ( V_2 , V_3 , V_15 , F_21 ( V_2 ) ) ;
F_78 ( V_15 , V_2 -> V_24 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_79 ( struct V_1 * V_2 , void * V_32 )
{
F_80 ( V_32 , V_2 -> V_3 ) ;
#if F_81 ( V_102 ) || F_81 ( V_103 )
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_82 ( V_2 , V_32 , V_2 -> V_24 ) ;
F_83 ( V_32 , V_2 -> V_24 ) ;
F_40 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_104 ) )
F_84 ( V_32 , V_2 -> V_24 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_86 ( & V_14 -> V_105 , & V_40 -> V_106 ) ;
}
static void F_87 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_88 ( & V_14 -> V_105 ) ;
}
static inline unsigned long F_89 ( struct V_1 * V_2 , int V_13 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
return F_90 ( & V_40 -> V_107 ) ;
}
static inline unsigned long F_91 ( struct V_12 * V_40 )
{
return F_90 ( & V_40 -> V_107 ) ;
}
static inline void F_92 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_40 ) {
F_93 ( & V_40 -> V_107 ) ;
F_94 ( V_17 , & V_40 -> V_108 ) ;
}
}
static inline void F_95 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_96 ( & V_40 -> V_107 ) ;
F_97 ( V_17 , & V_40 -> V_108 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
if ( ! ( V_2 -> V_3 & ( V_26 | V_22 | V_77 ) ) )
return;
F_61 ( V_2 , V_15 , V_109 ) ;
F_50 ( V_2 , V_15 ) ;
}
static T_6 int F_99 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , unsigned long V_21 )
{
if ( ! F_69 ( V_2 , V_14 ) )
goto V_110;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_59 ( V_2 , V_14 , V_15 , L_43 ) ;
goto V_110;
}
if ( ! F_68 ( V_2 , V_14 , V_15 , V_109 ) )
goto V_110;
if ( V_2 -> V_3 & V_26 )
F_46 ( V_2 , V_15 , V_70 , V_21 ) ;
V_55 ( V_2 , V_14 , V_15 , 1 ) ;
F_61 ( V_2 , V_15 , V_93 ) ;
return 1 ;
V_110:
if ( F_70 ( V_14 ) ) {
F_55 ( V_2 , L_44 ) ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_42 = NULL ;
}
return 0 ;
}
static T_6 int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 )
{
unsigned long V_3 ;
int V_111 = 0 ;
F_39 ( V_3 ) ;
F_26 ( V_14 ) ;
if ( ! F_69 ( V_2 , V_14 ) )
goto V_112;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_60 ( V_2 , V_14 , L_45 , V_15 ) ;
goto V_112;
}
if ( F_71 ( V_2 , V_14 , V_15 ) ) {
F_59 ( V_2 , V_14 , V_15 , L_46 ) ;
goto V_112;
}
if ( ! F_68 ( V_2 , V_14 , V_15 , V_93 ) )
goto V_113;
if ( F_3 ( V_2 != V_14 -> V_114 ) ) {
if ( ! F_70 ( V_14 ) ) {
F_60 ( V_2 , V_14 , L_47
L_48 , V_15 ) ;
} else if ( ! V_14 -> V_114 ) {
F_37 ( V_49
L_49 ,
V_15 ) ;
F_58 () ;
} else
F_59 ( V_2 , V_14 , V_15 ,
L_50 ) ;
goto V_112;
}
if ( V_2 -> V_3 & V_26 )
F_46 ( V_2 , V_15 , V_69 , V_21 ) ;
V_55 ( V_2 , V_14 , V_15 , 0 ) ;
F_61 ( V_2 , V_15 , V_109 ) ;
V_111 = 1 ;
V_113:
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
return V_111 ;
V_112:
F_55 ( V_2 , L_51 , V_15 ) ;
goto V_113;
}
static int T_7 F_101 ( char * V_115 )
{
V_116 = V_117 ;
if ( * V_115 ++ != '=' || ! * V_115 )
goto V_113;
if ( * V_115 == ',' )
goto V_118;
if ( tolower ( * V_115 ) == 'o' ) {
V_119 = 1 ;
goto V_113;
}
V_116 = 0 ;
if ( * V_115 == '-' )
goto V_113;
for (; * V_115 && * V_115 != ',' ; V_115 ++ ) {
switch ( tolower ( * V_115 ) ) {
case 'f' :
V_116 |= V_120 ;
break;
case 'z' :
V_116 |= V_22 ;
break;
case 'p' :
V_116 |= V_23 ;
break;
case 'u' :
V_116 |= V_26 ;
break;
case 't' :
V_116 |= V_99 ;
break;
case 'a' :
V_116 |= V_121 ;
break;
default:
F_37 ( V_49 L_52
L_53 , * V_115 ) ;
}
}
V_118:
if ( * V_115 == ',' )
V_122 = V_115 + 1 ;
V_113:
return 1 ;
}
static unsigned long F_102 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
if ( V_116 && ( ! V_122 ||
! strncmp ( V_122 , V_6 , strlen ( V_122 ) ) ) )
V_3 |= V_116 ;
return V_3 ;
}
static inline void F_98 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 ) {}
static inline int F_99 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_66 ( struct V_1 * V_2 , struct V_14 * V_14 )
{ return 1 ; }
static inline int F_68 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_76 ) { return 1 ; }
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
static inline int F_72 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_76 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_15 ) {}
static inline void F_79 ( struct V_1 * V_2 , void * V_32 ) {}
static inline struct V_14 * F_104 ( T_5 V_3 , int V_13 ,
struct V_31 V_123 )
{
int V_28 = F_24 ( V_123 ) ;
V_3 |= V_124 ;
if ( V_13 == V_125 )
return F_105 ( V_3 , V_28 ) ;
else
return F_106 ( V_13 , V_3 , V_28 ) ;
}
static struct V_14 * F_107 ( struct V_1 * V_2 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
struct V_31 V_123 = V_2 -> V_123 ;
T_5 V_126 ;
V_3 &= V_100 ;
if ( V_3 & V_101 )
F_108 () ;
V_3 |= V_2 -> V_127 ;
V_126 = ( V_3 | V_128 | V_129 ) & ~ V_130 ;
V_14 = F_104 ( V_126 , V_13 , V_123 ) ;
if ( F_3 ( ! V_14 ) ) {
V_123 = V_2 -> V_131 ;
V_14 = F_104 ( V_3 , V_13 , V_123 ) ;
if ( V_14 )
F_8 ( V_2 , V_132 ) ;
}
if ( V_3 & V_101 )
F_109 () ;
if ( ! V_14 )
return NULL ;
if ( V_133
&& ! ( V_2 -> V_3 & ( V_134 | V_117 ) ) ) {
int V_135 = 1 << F_24 ( V_123 ) ;
F_110 ( V_14 , F_24 ( V_123 ) , V_3 , V_13 ) ;
if ( V_2 -> F_103 )
F_111 ( V_14 , V_135 ) ;
else
F_112 ( V_14 , V_135 ) ;
}
V_14 -> V_17 = F_25 ( V_123 ) ;
F_113 ( F_114 ( V_14 ) ,
( V_2 -> V_3 & V_136 ) ?
V_137 : V_138 ,
1 << F_24 ( V_123 ) ) ;
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
void * V_85 ;
void * V_139 ;
void * V_5 ;
F_117 ( V_3 & V_140 ) ;
V_14 = F_107 ( V_2 ,
V_3 & ( V_141 | V_142 ) , V_13 ) ;
if ( ! V_14 )
goto V_113;
F_92 ( V_2 , F_118 ( V_14 ) , V_14 -> V_17 ) ;
V_14 -> V_114 = V_2 ;
V_14 -> V_3 |= 1 << V_143 ;
V_85 = F_14 ( V_14 ) ;
if ( F_3 ( V_2 -> V_3 & V_23 ) )
memset ( V_85 , V_90 , V_30 << F_67 ( V_14 ) ) ;
V_139 = V_85 ;
F_119 (p, s, start, page->objects) {
F_115 ( V_2 , V_14 , V_139 ) ;
F_19 ( V_2 , V_139 , V_5 ) ;
V_139 = V_5 ;
}
F_115 ( V_2 , V_14 , V_139 ) ;
F_19 ( V_2 , V_139 , NULL ) ;
V_14 -> V_42 = V_85 ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_144 = 1 ;
V_113:
return V_14 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_28 = F_67 ( V_14 ) ;
int V_135 = 1 << V_28 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_66 ( V_2 , V_14 ) ;
F_119 (p, s, page_address(page),
page->objects)
F_68 ( V_2 , V_14 , V_5 , V_109 ) ;
}
F_121 ( V_14 , F_67 ( V_14 ) ) ;
F_113 ( F_114 ( V_14 ) ,
( V_2 -> V_3 & V_136 ) ?
V_137 : V_138 ,
- V_135 ) ;
F_122 ( V_14 ) ;
F_123 ( V_14 ) ;
if ( V_66 -> V_145 )
V_66 -> V_145 -> V_146 += V_135 ;
F_124 ( V_14 , V_28 ) ;
}
static void F_125 ( struct V_147 * V_148 )
{
struct V_14 * V_14 ;
if ( V_149 )
V_14 = F_126 ( V_148 ) ;
else
V_14 = F_127 ( (struct V_150 * ) V_148 , struct V_14 , V_105 ) ;
F_120 ( V_14 -> V_114 , V_14 ) ;
}
static void F_128 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( F_3 ( V_2 -> V_3 & V_25 ) ) {
struct V_147 * V_151 ;
if ( V_149 ) {
int V_28 = F_67 ( V_14 ) ;
int V_19 = ( V_30 << V_28 ) - V_2 -> V_29 ;
F_31 ( V_2 -> V_29 != sizeof( * V_151 ) ) ;
V_151 = F_14 ( V_14 ) + V_19 ;
} else {
V_151 = ( void * ) & V_14 -> V_105 ;
}
F_129 ( V_151 , F_125 ) ;
} else
F_120 ( V_2 , V_14 ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
F_95 ( V_2 , F_118 ( V_14 ) , V_14 -> V_17 ) ;
F_128 ( V_2 , V_14 ) ;
}
static inline void F_131 ( struct V_12 * V_40 ,
struct V_14 * V_14 , int V_152 )
{
V_40 -> V_153 ++ ;
if ( V_152 == V_154 )
F_132 ( & V_14 -> V_105 , & V_40 -> V_155 ) ;
else
F_86 ( & V_14 -> V_105 , & V_40 -> V_155 ) ;
}
static inline void F_133 ( struct V_12 * V_40 ,
struct V_14 * V_14 )
{
F_88 ( & V_14 -> V_105 ) ;
V_40 -> V_153 -- ;
}
static inline void * F_134 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 ,
int V_156 )
{
void * V_42 ;
unsigned long V_43 ;
struct V_14 V_157 ;
do {
V_42 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
V_157 . V_43 = V_43 ;
if ( V_156 )
V_157 . V_27 = V_14 -> V_17 ;
F_31 ( V_157 . V_144 ) ;
V_157 . V_144 = 1 ;
} while ( ! F_30 ( V_2 , V_14 ,
V_42 , V_43 ,
NULL , V_157 . V_43 ,
L_54 ) );
F_133 ( V_40 , V_14 ) ;
return V_42 ;
}
static void * F_135 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_158 * V_159 )
{
struct V_14 * V_14 , * V_160 ;
void * V_15 = NULL ;
if ( ! V_40 || ! V_40 -> V_153 )
return NULL ;
F_136 ( & V_40 -> V_161 ) ;
F_137 (page, page2, &n->partial, lru) {
void * V_71 = F_134 ( V_2 , V_40 , V_14 , V_15 == NULL ) ;
int V_162 ;
if ( ! V_71 )
break;
if ( ! V_15 ) {
V_159 -> V_14 = V_14 ;
V_159 -> V_13 = F_118 ( V_14 ) ;
F_8 ( V_2 , V_163 ) ;
V_15 = V_71 ;
V_162 = V_14 -> V_17 - V_14 -> V_27 ;
} else {
V_14 -> V_42 = V_71 ;
V_162 = F_138 ( V_2 , V_14 , 0 ) ;
}
if ( F_1 ( V_2 ) || V_162 > V_2 -> V_164 / 2 )
break;
}
F_139 ( & V_40 -> V_161 ) ;
return V_15 ;
}
static struct V_14 * F_140 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_158 * V_159 )
{
#ifdef F_141
struct V_165 * V_165 ;
struct V_166 * V_167 ;
struct V_168 * V_168 ;
enum V_169 V_170 = F_142 ( V_3 ) ;
void * V_15 ;
if ( ! V_2 -> V_171 ||
F_143 () % 1024 > V_2 -> V_171 )
return NULL ;
F_144 () ;
V_165 = F_145 ( F_146 ( V_66 -> V_172 ) , V_3 ) ;
F_147 (zone, z, zonelist, high_zoneidx) {
struct V_12 * V_40 ;
V_40 = F_12 ( V_2 , F_148 ( V_168 ) ) ;
if ( V_40 && F_149 ( V_168 , V_3 ) &&
V_40 -> V_153 > V_2 -> V_173 ) {
V_15 = F_135 ( V_2 , V_40 , V_159 ) ;
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
struct V_158 * V_159 )
{
void * V_15 ;
int V_174 = ( V_13 == V_125 ) ? F_152 () : V_13 ;
V_15 = F_135 ( V_2 , F_12 ( V_2 , V_174 ) , V_159 ) ;
if ( V_15 || V_13 != V_125 )
return V_15 ;
return F_140 ( V_2 , V_3 , V_159 ) ;
}
static inline unsigned long F_153 ( unsigned long V_175 )
{
return V_175 + V_176 ;
}
static inline unsigned int F_154 ( unsigned long V_175 )
{
return V_175 % V_176 ;
}
static inline unsigned long F_155 ( unsigned long V_175 )
{
return V_175 / V_176 ;
}
static inline unsigned int F_156 ( int V_64 )
{
return V_64 ;
}
static inline void F_157 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_175 )
{
#ifdef F_36
unsigned long V_177 = F_158 ( V_2 -> V_9 -> V_175 ) ;
F_37 ( V_45 L_55 , V_40 , V_2 -> V_6 ) ;
#ifdef F_159
if ( F_154 ( V_175 ) != F_154 ( V_177 ) )
F_37 ( L_56 ,
F_154 ( V_175 ) , F_154 ( V_177 ) ) ;
else
#endif
if ( F_155 ( V_175 ) != F_155 ( V_177 ) )
F_37 ( L_57 ,
F_155 ( V_175 ) , F_155 ( V_177 ) ) ;
else
F_37 ( L_58 ,
V_177 , V_175 , F_153 ( V_175 ) ) ;
#endif
F_8 ( V_2 , V_178 ) ;
}
void F_160 ( struct V_1 * V_2 )
{
int V_64 ;
F_161 (cpu)
F_162 ( V_2 -> V_9 , V_64 ) -> V_175 = F_156 ( V_64 ) ;
}
static void F_163 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
enum T_8 { V_179 , V_180 , V_181 , V_182 };
struct V_14 * V_14 = V_159 -> V_14 ;
struct V_12 * V_40 = F_12 ( V_2 , F_118 ( V_14 ) ) ;
int V_183 = 0 ;
enum T_8 V_184 = V_179 , V_185 = V_179 ;
void * V_42 ;
void * V_186 ;
int V_152 = V_187 ;
struct V_14 V_157 ;
struct V_14 V_188 ;
if ( V_14 -> V_42 ) {
F_8 ( V_2 , V_189 ) ;
V_152 = V_154 ;
}
V_159 -> V_175 = F_153 ( V_159 -> V_175 ) ;
V_159 -> V_14 = NULL ;
V_42 = V_159 -> V_42 ;
V_159 -> V_42 = NULL ;
while ( V_42 && ( V_186 = F_15 ( V_2 , V_42 ) ) ) {
void * V_190 ;
unsigned long V_43 ;
do {
V_190 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
F_19 ( V_2 , V_42 , V_190 ) ;
V_157 . V_43 = V_43 ;
V_157 . V_27 -- ;
F_31 ( ! V_157 . V_144 ) ;
} while ( ! F_30 ( V_2 , V_14 ,
V_190 , V_43 ,
V_42 , V_157 . V_43 ,
L_59 ) );
V_42 = V_186 ;
}
V_191:
V_188 . V_42 = V_14 -> V_42 ;
V_188 . V_43 = V_14 -> V_43 ;
F_31 ( ! V_188 . V_144 ) ;
V_157 . V_43 = V_188 . V_43 ;
if ( V_42 ) {
V_157 . V_27 -- ;
F_19 ( V_2 , V_42 , V_188 . V_42 ) ;
V_157 . V_42 = V_42 ;
} else
V_157 . V_42 = V_188 . V_42 ;
V_157 . V_144 = 0 ;
if ( ! V_157 . V_27 && V_40 -> V_153 > V_2 -> V_173 )
V_185 = V_182 ;
else if ( V_157 . V_42 ) {
V_185 = V_180 ;
if ( ! V_183 ) {
V_183 = 1 ;
F_136 ( & V_40 -> V_161 ) ;
}
} else {
V_185 = V_181 ;
if ( F_1 ( V_2 ) && ! V_183 ) {
V_183 = 1 ;
F_136 ( & V_40 -> V_161 ) ;
}
}
if ( V_184 != V_185 ) {
if ( V_184 == V_180 )
F_133 ( V_40 , V_14 ) ;
else if ( V_184 == V_181 )
F_87 ( V_2 , V_14 ) ;
if ( V_185 == V_180 ) {
F_131 ( V_40 , V_14 , V_152 ) ;
F_8 ( V_2 , V_152 ) ;
} else if ( V_185 == V_181 ) {
F_8 ( V_2 , V_192 ) ;
F_85 ( V_2 , V_40 , V_14 ) ;
}
}
V_184 = V_185 ;
if ( ! F_30 ( V_2 , V_14 ,
V_188 . V_42 , V_188 . V_43 ,
V_157 . V_42 , V_157 . V_43 ,
L_60 ) )
goto V_191;
if ( V_183 )
F_139 ( & V_40 -> V_161 ) ;
if ( V_185 == V_182 ) {
F_8 ( V_2 , V_193 ) ;
F_130 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_194 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_12 * V_40 = NULL ;
struct V_158 * V_159 = F_165 ( V_2 -> V_9 ) ;
struct V_14 * V_14 , * V_195 = NULL ;
while ( ( V_14 = V_159 -> V_155 ) ) {
enum T_8 { V_180 , V_182 };
enum T_8 V_184 , V_185 ;
struct V_14 V_157 ;
struct V_14 V_188 ;
V_159 -> V_155 = V_14 -> V_196 ;
V_184 = V_182 ;
do {
V_188 . V_42 = V_14 -> V_42 ;
V_188 . V_43 = V_14 -> V_43 ;
F_31 ( ! V_188 . V_144 ) ;
V_157 . V_43 = V_188 . V_43 ;
V_157 . V_42 = V_188 . V_42 ;
V_157 . V_144 = 0 ;
if ( ! V_157 . V_27 && ( ! V_40 || V_40 -> V_153 > V_2 -> V_173 ) )
V_185 = V_182 ;
else {
struct V_12 * V_197 = F_12 ( V_2 ,
F_118 ( V_14 ) ) ;
V_185 = V_180 ;
if ( V_40 != V_197 ) {
if ( V_40 )
F_139 ( & V_40 -> V_161 ) ;
V_40 = V_197 ;
F_136 ( & V_40 -> V_161 ) ;
}
}
if ( V_184 != V_185 ) {
if ( V_184 == V_180 )
F_133 ( V_40 , V_14 ) ;
else
F_131 ( V_40 , V_14 ,
V_154 ) ;
V_184 = V_185 ;
}
} while ( ! F_38 ( V_2 , V_14 ,
V_188 . V_42 , V_188 . V_43 ,
V_157 . V_42 , V_157 . V_43 ,
L_60 ) );
if ( V_185 == V_182 ) {
V_14 -> V_196 = V_195 ;
V_195 = V_14 ;
}
}
if ( V_40 )
F_139 ( & V_40 -> V_161 ) ;
while ( V_195 ) {
V_14 = V_195 ;
V_195 = V_195 -> V_196 ;
F_8 ( V_2 , V_193 ) ;
F_130 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_194 ) ;
}
}
int F_138 ( struct V_1 * V_2 , struct V_14 * V_14 , int V_198 )
{
struct V_14 * V_199 ;
int V_135 ;
int V_200 ;
do {
V_135 = 0 ;
V_200 = 0 ;
V_199 = F_166 ( V_2 -> V_9 -> V_155 ) ;
if ( V_199 ) {
V_200 = V_199 -> V_200 ;
V_135 = V_199 -> V_135 ;
if ( V_198 && V_200 > V_2 -> V_164 ) {
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_164 ( V_2 ) ;
F_40 ( V_3 ) ;
V_200 = 0 ;
V_135 = 0 ;
}
}
V_135 ++ ;
V_200 += V_14 -> V_17 - V_14 -> V_27 ;
V_14 -> V_135 = V_135 ;
V_14 -> V_200 = V_200 ;
V_14 -> V_196 = V_199 ;
} while ( F_167 ( V_2 -> V_9 -> V_155 , V_199 , V_14 ) != V_199 );
F_8 ( V_2 , V_201 ) ;
return V_200 ;
}
static inline void F_168 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
F_8 ( V_2 , V_202 ) ;
F_163 ( V_2 , V_159 ) ;
}
static inline void F_169 ( struct V_1 * V_2 , int V_64 )
{
struct V_158 * V_159 = F_162 ( V_2 -> V_9 , V_64 ) ;
if ( F_170 ( V_159 ) ) {
if ( V_159 -> V_14 )
F_168 ( V_2 , V_159 ) ;
F_164 ( V_2 ) ;
}
}
static void F_171 ( void * V_203 )
{
struct V_1 * V_2 = V_203 ;
F_169 ( V_2 , F_49 () ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_173 ( F_171 , V_2 , 1 ) ;
}
static inline int F_174 ( struct V_158 * V_159 , int V_13 )
{
#ifdef F_141
if ( V_13 != V_125 && V_159 -> V_13 != V_13 )
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
F_178 ( & V_40 -> V_161 , V_3 ) ;
F_179 (page, &n->partial, lru)
V_32 += F_177 ( V_14 ) ;
F_180 ( & V_40 -> V_161 , V_3 ) ;
return V_32 ;
}
static inline unsigned long F_181 ( struct V_12 * V_40 )
{
#ifdef F_2
return F_90 ( & V_40 -> V_108 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_182 ( struct V_1 * V_2 , T_5 V_204 , int V_205 )
{
int V_13 ;
F_37 ( V_206
L_61 ,
V_205 , V_204 ) ;
F_37 ( V_206 L_62
L_63 , V_2 -> V_6 , V_2 -> V_24 ,
V_2 -> V_18 , F_24 ( V_2 -> V_123 ) , F_24 ( V_2 -> V_131 ) ) ;
if ( F_24 ( V_2 -> V_131 ) > F_183 ( V_2 -> V_24 ) )
F_37 ( V_206 L_64
L_65 , V_2 -> V_6 ) ;
F_184 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_107 ;
unsigned long V_207 ;
unsigned long V_208 ;
if ( ! V_40 )
continue;
V_208 = F_176 ( V_40 , F_175 ) ;
V_107 = F_91 ( V_40 ) ;
V_207 = F_181 ( V_40 ) ;
F_37 ( V_206
L_66 ,
V_13 , V_107 , V_207 , V_208 ) ;
}
}
static inline void * F_185 ( struct V_1 * V_2 , T_5 V_3 ,
int V_13 , struct V_158 * * V_209 )
{
void * V_15 ;
struct V_158 * V_159 ;
struct V_14 * V_14 = F_116 ( V_2 , V_3 , V_13 ) ;
if ( V_14 ) {
V_159 = F_186 ( V_2 -> V_9 ) ;
if ( V_159 -> V_14 )
F_168 ( V_2 , V_159 ) ;
V_15 = V_14 -> V_42 ;
V_14 -> V_42 = NULL ;
F_8 ( V_2 , V_210 ) ;
V_159 -> V_13 = F_118 ( V_14 ) ;
V_159 -> V_14 = V_14 ;
* V_209 = V_159 ;
} else
V_15 = NULL ;
return V_15 ;
}
static void * F_187 ( struct V_1 * V_2 , T_5 V_204 , int V_13 ,
unsigned long V_21 , struct V_158 * V_159 )
{
void * * V_15 ;
unsigned long V_3 ;
struct V_14 V_157 ;
unsigned long V_43 ;
F_39 ( V_3 ) ;
#ifdef F_159
V_159 = F_165 ( V_2 -> V_9 ) ;
#endif
if ( ! V_159 -> V_14 )
goto F_116;
V_191:
if ( F_3 ( ! F_174 ( V_159 , V_13 ) ) ) {
F_8 ( V_2 , V_211 ) ;
F_163 ( V_2 , V_159 ) ;
goto F_116;
}
F_8 ( V_2 , V_212 ) ;
do {
V_15 = V_159 -> V_14 -> V_42 ;
V_43 = V_159 -> V_14 -> V_43 ;
V_157 . V_43 = V_43 ;
F_31 ( ! V_157 . V_144 ) ;
V_157 . V_27 = V_159 -> V_14 -> V_17 ;
V_157 . V_144 = V_15 != NULL ;
} while ( ! F_30 ( V_2 , V_159 -> V_14 ,
V_15 , V_43 ,
NULL , V_157 . V_43 ,
L_67 ) );
if ( ! V_15 ) {
V_159 -> V_14 = NULL ;
F_8 ( V_2 , V_213 ) ;
goto F_116;
}
F_8 ( V_2 , V_214 ) ;
V_215:
V_159 -> V_42 = F_15 ( V_2 , V_15 ) ;
V_159 -> V_175 = F_153 ( V_159 -> V_175 ) ;
F_40 ( V_3 ) ;
return V_15 ;
F_116:
if ( V_159 -> V_155 ) {
V_159 -> V_14 = V_159 -> V_155 ;
V_159 -> V_155 = V_159 -> V_14 -> V_196 ;
V_159 -> V_13 = F_118 ( V_159 -> V_14 ) ;
F_8 ( V_2 , V_216 ) ;
V_159 -> V_42 = NULL ;
goto V_191;
}
V_15 = F_151 ( V_2 , V_204 , V_13 , V_159 ) ;
if ( F_3 ( ! V_15 ) ) {
V_15 = F_185 ( V_2 , V_204 , V_13 , & V_159 ) ;
if ( F_3 ( ! V_15 ) ) {
if ( ! ( V_204 & V_128 ) && F_188 () )
F_182 ( V_2 , V_204 , V_13 ) ;
F_40 ( V_3 ) ;
return NULL ;
}
}
if ( F_170 ( ! F_1 ( V_2 ) ) )
goto V_215;
if ( ! F_99 ( V_2 , V_159 -> V_14 , V_15 , V_21 ) )
goto F_116;
V_159 -> V_42 = F_15 ( V_2 , V_15 ) ;
F_163 ( V_2 , V_159 ) ;
V_159 -> V_13 = V_125 ;
F_40 ( V_3 ) ;
return V_15 ;
}
static T_2 void * F_189 ( struct V_1 * V_2 ,
T_5 V_204 , int V_13 , unsigned long V_21 )
{
void * * V_15 ;
struct V_158 * V_159 ;
unsigned long V_175 ;
if ( F_72 ( V_2 , V_204 ) )
return NULL ;
V_191:
V_159 = F_186 ( V_2 -> V_9 ) ;
V_175 = V_159 -> V_175 ;
F_190 () ;
V_15 = V_159 -> V_42 ;
if ( F_3 ( ! V_15 || ! F_174 ( V_159 , V_13 ) ) )
V_15 = F_187 ( V_2 , V_204 , V_13 , V_21 , V_159 ) ;
else {
if ( F_3 ( ! F_191 (
V_2 -> V_9 -> V_42 , V_2 -> V_9 -> V_175 ,
V_15 , V_175 ,
F_16 ( V_2 , V_15 ) , F_153 ( V_175 ) ) ) ) {
F_157 ( L_68 , V_2 , V_175 ) ;
goto V_191;
}
F_8 ( V_2 , V_217 ) ;
}
if ( F_3 ( V_204 & V_218 ) && V_15 )
memset ( V_15 , 0 , V_2 -> V_24 ) ;
F_76 ( V_2 , V_204 , V_15 ) ;
return V_15 ;
}
void * F_192 ( struct V_1 * V_2 , T_5 V_204 )
{
void * V_219 = F_189 ( V_2 , V_204 , V_125 , V_220 ) ;
F_193 ( V_220 , V_219 , V_2 -> V_24 , V_2 -> V_18 , V_204 ) ;
return V_219 ;
}
void * F_194 ( struct V_1 * V_2 , T_5 V_204 , T_1 V_18 )
{
void * V_219 = F_189 ( V_2 , V_204 , V_125 , V_220 ) ;
F_195 ( V_220 , V_219 , V_18 , V_2 -> V_18 , V_204 ) ;
return V_219 ;
}
void * F_196 ( T_1 V_18 , T_5 V_3 , unsigned int V_28 )
{
void * V_219 = F_197 ( V_18 , V_3 , V_28 ) ;
F_195 ( V_220 , V_219 , V_18 , V_30 << V_28 , V_3 ) ;
return V_219 ;
}
void * F_198 ( struct V_1 * V_2 , T_5 V_204 , int V_13 )
{
void * V_219 = F_189 ( V_2 , V_204 , V_13 , V_220 ) ;
F_199 ( V_220 , V_219 ,
V_2 -> V_24 , V_2 -> V_18 , V_204 , V_13 ) ;
return V_219 ;
}
void * F_200 ( struct V_1 * V_2 ,
T_5 V_204 ,
int V_13 , T_1 V_18 )
{
void * V_219 = F_189 ( V_2 , V_204 , V_13 , V_220 ) ;
F_201 ( V_220 , V_219 ,
V_18 , V_2 -> V_18 , V_204 , V_13 ) ;
return V_219 ;
}
static void F_202 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_32 , unsigned long V_21 )
{
void * V_190 ;
void * * V_15 = ( void * ) V_32 ;
int V_221 ;
int V_27 ;
struct V_14 V_157 ;
unsigned long V_43 ;
struct V_12 * V_40 = NULL ;
unsigned long V_222 ( V_3 ) ;
F_8 ( V_2 , V_223 ) ;
if ( F_1 ( V_2 ) && ! F_100 ( V_2 , V_14 , V_32 , V_21 ) )
return;
do {
V_190 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
F_19 ( V_2 , V_15 , V_190 ) ;
V_157 . V_43 = V_43 ;
V_221 = V_157 . V_144 ;
V_157 . V_27 -- ;
if ( ( ! V_157 . V_27 || ! V_190 ) && ! V_221 && ! V_40 ) {
if ( ! F_1 ( V_2 ) && ! V_190 )
V_157 . V_144 = 1 ;
else {
V_40 = F_12 ( V_2 , F_118 ( V_14 ) ) ;
F_178 ( & V_40 -> V_161 , V_3 ) ;
}
}
V_27 = V_157 . V_27 ;
} while ( ! F_38 ( V_2 , V_14 ,
V_190 , V_43 ,
V_15 , V_157 . V_43 ,
L_69 ) );
if ( F_170 ( ! V_40 ) ) {
if ( V_157 . V_144 && ! V_221 )
F_138 ( V_2 , V_14 , 1 ) ;
if ( V_221 )
F_8 ( V_2 , V_224 ) ;
return;
}
if ( V_221 )
F_8 ( V_2 , V_224 ) ;
else {
if ( F_3 ( ! V_27 && V_40 -> V_153 > V_2 -> V_173 ) )
goto V_225;
if ( F_3 ( ! V_190 ) ) {
F_87 ( V_2 , V_14 ) ;
F_131 ( V_40 , V_14 , V_154 ) ;
F_8 ( V_2 , V_226 ) ;
}
}
F_180 ( & V_40 -> V_161 , V_3 ) ;
return;
V_225:
if ( V_190 ) {
F_133 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_227 ) ;
} else
F_87 ( V_2 , V_14 ) ;
F_180 ( & V_40 -> V_161 , V_3 ) ;
F_8 ( V_2 , V_194 ) ;
F_130 ( V_2 , V_14 ) ;
}
static T_2 void F_203 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_32 , unsigned long V_21 )
{
void * * V_15 = ( void * ) V_32 ;
struct V_158 * V_159 ;
unsigned long V_175 ;
F_79 ( V_2 , V_32 ) ;
V_191:
V_159 = F_186 ( V_2 -> V_9 ) ;
V_175 = V_159 -> V_175 ;
F_190 () ;
if ( F_170 ( V_14 == V_159 -> V_14 ) ) {
F_19 ( V_2 , V_15 , V_159 -> V_42 ) ;
if ( F_3 ( ! F_191 (
V_2 -> V_9 -> V_42 , V_2 -> V_9 -> V_175 ,
V_159 -> V_42 , V_175 ,
V_15 , F_153 ( V_175 ) ) ) ) {
F_157 ( L_70 , V_2 , V_175 ) ;
goto V_191;
}
F_8 ( V_2 , V_228 ) ;
} else
F_202 ( V_2 , V_14 , V_32 , V_21 ) ;
}
void F_204 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_14 ;
V_14 = F_126 ( V_32 ) ;
F_203 ( V_2 , V_14 , V_32 , V_220 ) ;
F_205 ( V_220 , V_32 ) ;
}
static inline int F_206 ( int V_18 , int V_229 ,
int V_230 , int V_231 , int V_29 )
{
int V_28 ;
int V_232 ;
int V_233 = V_234 ;
if ( F_22 ( V_233 , V_18 , V_29 ) > V_98 )
return F_183 ( V_18 * V_98 ) - 1 ;
for ( V_28 = F_207 ( V_233 ,
F_208 ( V_229 * V_18 - 1 ) - V_235 ) ;
V_28 <= V_230 ; V_28 ++ ) {
unsigned long V_236 = V_30 << V_28 ;
if ( V_236 < V_229 * V_18 + V_29 )
continue;
V_232 = ( V_236 - V_29 ) % V_18 ;
if ( V_232 <= V_236 / V_231 )
break;
}
return V_28 ;
}
static inline int F_209 ( int V_18 , int V_29 )
{
int V_28 ;
int V_229 ;
int V_237 ;
int V_97 ;
V_229 = V_238 ;
if ( ! V_229 )
V_229 = 4 * ( F_208 ( V_239 ) + 1 ) ;
V_97 = F_22 ( V_240 , V_18 , V_29 ) ;
V_229 = V_131 ( V_229 , V_97 ) ;
while ( V_229 > 1 ) {
V_237 = 16 ;
while ( V_237 >= 4 ) {
V_28 = F_206 ( V_18 , V_229 ,
V_240 , V_237 , V_29 ) ;
if ( V_28 <= V_240 )
return V_28 ;
V_237 /= 2 ;
}
V_229 -- ;
}
V_28 = F_206 ( V_18 , 1 , V_240 , 1 , V_29 ) ;
if ( V_28 <= V_240 )
return V_28 ;
V_28 = F_206 ( V_18 , 1 , V_241 , 1 , V_29 ) ;
if ( V_28 < V_241 )
return V_28 ;
return - V_242 ;
}
static unsigned long F_210 ( unsigned long V_3 ,
unsigned long V_243 , unsigned long V_18 )
{
if ( V_3 & V_244 ) {
unsigned long V_245 = F_211 () ;
while ( V_18 <= V_245 / 2 )
V_245 /= 2 ;
V_243 = F_207 ( V_243 , V_245 ) ;
}
if ( V_243 < V_246 )
V_243 = V_246 ;
return F_212 ( V_243 , sizeof( void * ) ) ;
}
static void
F_213 ( struct V_12 * V_40 , struct V_1 * V_2 )
{
V_40 -> V_153 = 0 ;
F_214 ( & V_40 -> V_161 ) ;
F_215 ( & V_40 -> V_155 ) ;
#ifdef F_2
F_216 ( & V_40 -> V_107 , 0 ) ;
F_216 ( & V_40 -> V_108 , 0 ) ;
F_215 ( & V_40 -> V_106 ) ;
#endif
}
static inline int F_217 ( struct V_1 * V_2 )
{
F_218 ( V_247 <
V_248 * sizeof( struct V_158 ) ) ;
V_2 -> V_9 = F_219 ( sizeof( struct V_158 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_160 ( V_2 ) ;
return 1 ;
}
static void F_220 ( int V_13 )
{
struct V_14 * V_14 ;
struct V_12 * V_40 ;
F_117 ( V_12 -> V_18 < sizeof( struct V_12 ) ) ;
V_14 = F_116 ( V_12 , V_249 , V_13 ) ;
F_117 ( ! V_14 ) ;
if ( F_118 ( V_14 ) != V_13 ) {
F_37 ( V_49 L_71
L_72 , V_13 ) ;
F_37 ( V_49 L_73
L_74 ) ;
}
V_40 = V_14 -> V_42 ;
F_117 ( ! V_40 ) ;
V_14 -> V_42 = F_15 ( V_12 , V_40 ) ;
V_14 -> V_27 = 1 ;
V_14 -> V_144 = 0 ;
V_12 -> V_13 [ V_13 ] = V_40 ;
#ifdef F_2
F_61 ( V_12 , V_40 , V_93 ) ;
F_50 ( V_12 , V_40 ) ;
#endif
F_213 ( V_40 , V_12 ) ;
F_92 ( V_12 , V_13 , V_14 -> V_17 ) ;
F_131 ( V_40 , V_14 , V_187 ) ;
}
static void F_221 ( struct V_1 * V_2 )
{
int V_13 ;
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = V_2 -> V_13 [ V_13 ] ;
if ( V_40 )
F_204 ( V_12 , V_40 ) ;
V_2 -> V_13 [ V_13 ] = NULL ;
}
}
static int F_223 ( struct V_1 * V_2 )
{
int V_13 ;
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 ;
if ( V_10 == V_250 ) {
F_220 ( V_13 ) ;
continue;
}
V_40 = F_198 ( V_12 ,
V_251 , V_13 ) ;
if ( ! V_40 ) {
F_221 ( V_2 ) ;
return 0 ;
}
V_2 -> V_13 [ V_13 ] = V_40 ;
F_213 ( V_40 , V_2 ) ;
}
return 1 ;
}
static void F_224 ( struct V_1 * V_2 , unsigned long V_131 )
{
if ( V_131 < V_252 )
V_131 = V_252 ;
else if ( V_131 > V_253 )
V_131 = V_253 ;
V_2 -> V_173 = V_131 ;
}
static int F_225 ( struct V_1 * V_2 , int V_254 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_18 = V_2 -> V_24 ;
unsigned long V_243 = V_2 -> V_243 ;
int V_28 ;
V_18 = F_212 ( V_18 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_23 ) && ! ( V_3 & V_25 ) &&
! V_2 -> F_103 )
V_2 -> V_3 |= V_77 ;
else
V_2 -> V_3 &= ~ V_77 ;
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
V_18 += 2 * sizeof( struct V_51 ) ;
if ( V_3 & V_22 )
V_18 += sizeof( void * ) ;
#endif
V_243 = F_210 ( V_3 , V_243 , V_2 -> V_24 ) ;
V_2 -> V_243 = V_243 ;
V_18 = F_212 ( V_18 , V_243 ) ;
V_2 -> V_18 = V_18 ;
if ( V_254 >= 0 )
V_28 = V_254 ;
else
V_28 = F_209 ( V_18 , V_2 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
V_2 -> V_127 = 0 ;
if ( V_28 )
V_2 -> V_127 |= V_255 ;
if ( V_2 -> V_3 & V_256 )
V_2 -> V_127 |= V_257 ;
if ( V_2 -> V_3 & V_136 )
V_2 -> V_127 |= V_258 ;
V_2 -> V_123 = F_23 ( V_28 , V_18 , V_2 -> V_29 ) ;
V_2 -> V_131 = F_23 ( F_183 ( V_18 ) , V_18 , V_2 -> V_29 ) ;
if ( F_25 ( V_2 -> V_123 ) > F_25 ( V_2 -> F_207 ) )
V_2 -> F_207 = V_2 -> V_123 ;
return ! ! F_25 ( V_2 -> V_123 ) ;
}
static int F_226 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_18 ,
T_1 V_243 , unsigned long V_3 ,
void (* F_103)( void * ) )
{
memset ( V_2 , 0 , V_259 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_103 = F_103 ;
V_2 -> V_24 = V_18 ;
V_2 -> V_243 = V_243 ;
V_2 -> V_3 = F_102 ( V_18 , V_3 , V_6 , F_103 ) ;
V_2 -> V_29 = 0 ;
if ( V_149 && ( V_2 -> V_3 & V_25 ) )
V_2 -> V_29 = sizeof( struct V_147 ) ;
if ( ! F_225 ( V_2 , - 1 ) )
goto error;
if ( V_119 ) {
if ( F_183 ( V_2 -> V_18 ) > F_183 ( V_2 -> V_24 ) ) {
V_2 -> V_3 &= ~ V_260 ;
V_2 -> V_19 = 0 ;
if ( ! F_225 ( V_2 , - 1 ) )
goto error;
}
}
#ifdef F_33
if ( F_227 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_41 ;
#endif
F_224 ( V_2 , F_228 ( V_2 -> V_18 ) / 2 ) ;
if ( V_2 -> V_18 >= V_30 )
V_2 -> V_164 = 2 ;
else if ( V_2 -> V_18 >= 1024 )
V_2 -> V_164 = 6 ;
else if ( V_2 -> V_18 >= 256 )
V_2 -> V_164 = 13 ;
else
V_2 -> V_164 = 30 ;
V_2 -> V_261 = 1 ;
#ifdef F_141
V_2 -> V_171 = 1000 ;
#endif
if ( ! F_223 ( V_2 ) )
goto error;
if ( F_217 ( V_2 ) )
return 1 ;
F_221 ( V_2 ) ;
error:
if ( V_3 & V_262 )
F_229 ( L_75
L_76 ,
V_2 -> V_6 , ( unsigned long ) V_18 , V_2 -> V_18 , F_24 ( V_2 -> V_123 ) ,
V_2 -> V_19 , V_3 ) ;
return 0 ;
}
unsigned int F_230 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
static void F_231 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const char * V_47 )
{
#ifdef F_2
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
unsigned long * V_46 = F_232 ( F_233 ( V_14 -> V_17 ) *
sizeof( long ) , V_263 ) ;
if ( ! V_46 )
return;
F_60 ( V_2 , V_14 , L_18 , V_47 ) ;
F_26 ( V_14 ) ;
F_41 ( V_2 , V_14 , V_46 ) ;
F_119 (p, s, addr, page->objects) {
if ( ! F_234 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) ) {
F_37 ( V_49 L_77 ,
V_5 , V_5 - V_21 ) ;
F_52 ( V_2 , V_5 ) ;
}
}
F_28 ( V_14 ) ;
F_7 ( V_46 ) ;
#endif
}
static void F_235 ( struct V_1 * V_2 , struct V_12 * V_40 )
{
struct V_14 * V_14 , * V_148 ;
F_137 (page, h, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_133 ( V_40 , V_14 ) ;
F_130 ( V_2 , V_14 ) ;
} else {
F_231 ( V_2 , V_14 ,
L_78 ) ;
}
}
}
static inline int F_236 ( struct V_1 * V_2 )
{
int V_13 ;
F_172 ( V_2 ) ;
F_237 ( V_2 -> V_9 ) ;
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_235 ( V_2 , V_40 ) ;
if ( V_40 -> V_153 || F_89 ( V_2 , V_13 ) )
return 1 ;
}
F_221 ( V_2 ) ;
return 0 ;
}
void F_238 ( struct V_1 * V_2 )
{
F_239 ( & V_264 ) ;
V_2 -> V_261 -- ;
if ( ! V_2 -> V_261 ) {
F_88 ( & V_2 -> V_265 ) ;
F_240 ( & V_264 ) ;
if ( F_236 ( V_2 ) ) {
F_37 ( V_49 L_79
L_80 , V_2 -> V_6 , V_266 ) ;
F_58 () ;
}
if ( V_2 -> V_3 & V_25 )
F_241 () ;
F_6 ( V_2 ) ;
} else
F_240 ( & V_264 ) ;
}
static int T_7 F_242 ( char * V_115 )
{
F_243 ( & V_115 , & V_234 ) ;
return 1 ;
}
static int T_7 F_244 ( char * V_115 )
{
F_243 ( & V_115 , & V_240 ) ;
V_240 = V_131 ( V_240 , V_241 - 1 ) ;
return 1 ;
}
static int T_7 F_245 ( char * V_115 )
{
F_243 ( & V_115 , & V_238 ) ;
return 1 ;
}
static int T_7 F_246 ( char * V_115 )
{
V_267 = 1 ;
return 1 ;
}
static struct V_1 * T_7 F_247 ( const char * V_6 ,
int V_18 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_192 ( V_1 , V_249 ) ;
if ( ! F_226 ( V_2 , V_6 , V_18 , V_268 ,
V_3 , NULL ) )
goto F_229;
F_86 ( & V_2 -> V_265 , & V_269 ) ;
return V_2 ;
F_229:
F_229 ( L_81 , V_6 , V_18 ) ;
return NULL ;
}
static inline int F_248 ( T_1 V_87 )
{
return ( V_87 - 1 ) / 8 ;
}
static struct V_1 * F_249 ( T_1 V_18 , T_5 V_3 )
{
int V_270 ;
if ( V_18 <= 192 ) {
if ( ! V_18 )
return V_271 ;
V_270 = V_272 [ F_248 ( V_18 ) ] ;
} else
V_270 = F_208 ( V_18 - 1 ) ;
#ifdef F_250
if ( F_3 ( ( V_3 & V_257 ) ) )
return V_273 [ V_270 ] ;
#endif
return V_274 [ V_270 ] ;
}
void * F_251 ( T_1 V_18 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_219 ;
if ( F_3 ( V_18 > V_275 ) )
return F_252 ( V_18 , V_3 ) ;
V_2 = F_249 ( V_18 , V_3 ) ;
if ( F_3 ( F_253 ( V_2 ) ) )
return V_2 ;
V_219 = F_189 ( V_2 , V_3 , V_125 , V_220 ) ;
F_195 ( V_220 , V_219 , V_18 , V_2 -> V_18 , V_3 ) ;
return V_219 ;
}
static void * F_254 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_276 = NULL ;
V_3 |= V_255 | V_124 ;
V_14 = F_255 ( V_13 , V_3 , F_183 ( V_18 ) ) ;
if ( V_14 )
V_276 = F_14 ( V_14 ) ;
F_256 ( V_276 , V_18 , 1 , V_3 ) ;
return V_276 ;
}
void * F_257 ( T_1 V_18 , T_5 V_3 , int V_13 )
{
struct V_1 * V_2 ;
void * V_219 ;
if ( F_3 ( V_18 > V_275 ) ) {
V_219 = F_254 ( V_18 , V_3 , V_13 ) ;
F_201 ( V_220 , V_219 ,
V_18 , V_30 << F_183 ( V_18 ) ,
V_3 , V_13 ) ;
return V_219 ;
}
V_2 = F_249 ( V_18 , V_3 ) ;
if ( F_3 ( F_253 ( V_2 ) ) )
return V_2 ;
V_219 = F_189 ( V_2 , V_3 , V_13 , V_220 ) ;
F_201 ( V_220 , V_219 , V_18 , V_2 -> V_18 , V_3 , V_13 ) ;
return V_219 ;
}
T_1 F_258 ( const void * V_15 )
{
struct V_14 * V_14 ;
if ( F_3 ( V_15 == V_271 ) )
return 0 ;
V_14 = F_126 ( V_15 ) ;
if ( F_3 ( ! F_70 ( V_14 ) ) ) {
F_259 ( ! F_260 ( V_14 ) ) ;
return V_30 << F_67 ( V_14 ) ;
}
return F_21 ( V_14 -> V_114 ) ;
}
bool F_261 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
unsigned long V_3 ;
bool V_277 ;
if ( F_3 ( F_253 ( V_32 ) ) )
return false ;
F_39 ( V_3 ) ;
V_14 = F_126 ( V_32 ) ;
if ( F_3 ( ! F_70 ( V_14 ) ) ) {
V_277 = true ;
goto V_278;
}
F_26 ( V_14 ) ;
if ( F_71 ( V_14 -> V_114 , V_14 , V_15 ) ) {
F_59 ( V_14 -> V_114 , V_14 , V_15 , L_82 ) ;
V_277 = false ;
} else {
V_277 = true ;
}
F_28 ( V_14 ) ;
V_278:
F_40 ( V_3 ) ;
return V_277 ;
}
void F_7 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
F_262 ( V_220 , V_32 ) ;
if ( F_3 ( F_253 ( V_32 ) ) )
return;
V_14 = F_126 ( V_32 ) ;
if ( F_3 ( ! F_70 ( V_14 ) ) ) {
F_117 ( ! F_260 ( V_14 ) ) ;
F_263 ( V_32 ) ;
F_264 ( V_14 ) ;
return;
}
F_203 ( V_14 -> V_114 , V_14 , V_15 , V_220 ) ;
}
int F_265 ( struct V_1 * V_2 )
{
int V_13 ;
int V_56 ;
struct V_12 * V_40 ;
struct V_14 * V_14 ;
struct V_14 * V_71 ;
int V_17 = F_25 ( V_2 -> F_207 ) ;
struct V_150 * V_279 =
F_266 ( sizeof( struct V_150 ) * V_17 , V_251 ) ;
unsigned long V_3 ;
if ( ! V_279 )
return - V_280 ;
F_172 ( V_2 ) ;
F_222 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 -> V_153 )
continue;
for ( V_56 = 0 ; V_56 < V_17 ; V_56 ++ )
F_215 ( V_279 + V_56 ) ;
F_178 ( & V_40 -> V_161 , V_3 ) ;
F_137 (page, t, &n->partial, lru) {
F_267 ( & V_14 -> V_105 , V_279 + V_14 -> V_27 ) ;
if ( ! V_14 -> V_27 )
V_40 -> V_153 -- ;
}
for ( V_56 = V_17 - 1 ; V_56 > 0 ; V_56 -- )
F_268 ( V_279 + V_56 , V_40 -> V_155 . V_281 ) ;
F_180 ( & V_40 -> V_161 , V_3 ) ;
F_137 (page, t, slabs_by_inuse, lru)
F_130 ( V_2 , V_14 ) ;
}
F_7 ( V_279 ) ;
return 0 ;
}
static int F_269 ( void * V_282 )
{
struct V_1 * V_2 ;
F_270 ( & V_264 ) ;
F_179 (s, &slab_caches, list)
F_265 ( V_2 ) ;
F_271 ( & V_264 ) ;
return 0 ;
}
static void F_272 ( void * V_282 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_283 * V_284 = V_282 ;
int V_285 ;
V_285 = V_284 -> V_286 ;
if ( V_285 < 0 )
return;
F_270 ( & V_264 ) ;
F_179 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_285 ) ;
if ( V_40 ) {
F_117 ( F_89 ( V_2 , V_285 ) ) ;
V_2 -> V_13 [ V_285 ] = NULL ;
F_204 ( V_12 , V_40 ) ;
}
}
F_271 ( & V_264 ) ;
}
static int F_273 ( void * V_282 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_283 * V_284 = V_282 ;
int V_205 = V_284 -> V_286 ;
int V_219 = 0 ;
if ( V_205 < 0 )
return 0 ;
F_270 ( & V_264 ) ;
F_179 (s, &slab_caches, list) {
V_40 = F_192 ( V_12 , V_251 ) ;
if ( ! V_40 ) {
V_219 = - V_280 ;
goto V_113;
}
F_213 ( V_40 , V_2 ) ;
V_2 -> V_13 [ V_205 ] = V_40 ;
}
V_113:
F_271 ( & V_264 ) ;
return V_219 ;
}
static int F_274 ( struct V_287 * V_288 ,
unsigned long V_289 , void * V_282 )
{
int V_219 = 0 ;
switch ( V_289 ) {
case V_290 :
V_219 = F_273 ( V_282 ) ;
break;
case V_291 :
V_219 = F_269 ( V_282 ) ;
break;
case V_292 :
case V_293 :
F_272 ( V_282 ) ;
break;
case V_294 :
case V_295 :
break;
}
if ( V_219 )
V_219 = F_275 ( V_219 ) ;
else
V_219 = V_296 ;
return V_219 ;
}
static void T_7 F_276 ( struct V_1 * V_2 )
{
int V_13 ;
F_86 ( & V_2 -> V_265 , & V_269 ) ;
V_2 -> V_261 = - 1 ;
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
struct V_14 * V_5 ;
if ( V_40 ) {
F_179 (p, &n->partial, lru)
V_5 -> V_114 = V_2 ;
#ifdef F_2
F_179 (p, &n->full, lru)
V_5 -> V_114 = V_2 ;
#endif
}
}
}
void T_7 F_277 ( void )
{
int V_56 ;
int V_297 = 0 ;
struct V_1 * V_298 ;
int V_28 ;
struct V_1 * V_299 ;
unsigned long V_300 ;
V_259 = F_278 ( struct V_1 , V_13 ) +
V_301 * sizeof( struct V_12 * ) ;
V_300 = F_212 ( V_259 , F_211 () ) ;
V_28 = F_183 ( 2 * V_300 ) ;
V_1 = ( void * ) F_279 ( V_249 , V_28 ) ;
V_12 = ( void * ) V_1 + V_300 ;
F_226 ( V_12 , L_83 ,
sizeof( struct V_12 ) ,
0 , V_244 | V_262 , NULL ) ;
F_280 ( F_274 , V_302 ) ;
V_10 = V_303 ;
V_298 = V_1 ;
F_226 ( V_1 , L_84 , V_259 ,
0 , V_244 | V_262 , NULL ) ;
V_1 = F_192 ( V_1 , V_249 ) ;
memcpy ( V_1 , V_298 , V_259 ) ;
V_299 = V_12 ;
V_12 = F_192 ( V_1 , V_249 ) ;
memcpy ( V_12 , V_299 , V_259 ) ;
F_276 ( V_12 ) ;
V_297 ++ ;
F_276 ( V_1 ) ;
V_297 ++ ;
F_281 ( ( unsigned long ) V_298 , V_28 ) ;
F_218 ( V_304 > 256 ||
( V_304 & ( V_304 - 1 ) ) ) ;
for ( V_56 = 8 ; V_56 < V_304 ; V_56 += 8 ) {
int V_305 = F_248 ( V_56 ) ;
if ( V_305 >= F_282 ( V_272 ) )
break;
V_272 [ V_305 ] = V_306 ;
}
if ( V_304 == 64 ) {
for ( V_56 = 64 + 8 ; V_56 <= 96 ; V_56 += 8 )
V_272 [ F_248 ( V_56 ) ] = 7 ;
} else if ( V_304 == 128 ) {
for ( V_56 = 128 + 8 ; V_56 <= 192 ; V_56 += 8 )
V_272 [ F_248 ( V_56 ) ] = 8 ;
}
if ( V_304 <= 32 ) {
V_274 [ 1 ] = F_247 ( L_85 , 96 , 0 ) ;
V_297 ++ ;
}
if ( V_304 <= 64 ) {
V_274 [ 2 ] = F_247 ( L_86 , 192 , 0 ) ;
V_297 ++ ;
}
for ( V_56 = V_306 ; V_56 < V_248 ; V_56 ++ ) {
V_274 [ V_56 ] = F_247 ( L_87 , 1 << V_56 , 0 ) ;
V_297 ++ ;
}
V_10 = V_11 ;
if ( V_304 <= 32 ) {
V_274 [ 1 ] -> V_6 = F_283 ( V_274 [ 1 ] -> V_6 , V_249 ) ;
F_117 ( ! V_274 [ 1 ] -> V_6 ) ;
}
if ( V_304 <= 64 ) {
V_274 [ 2 ] -> V_6 = F_283 ( V_274 [ 2 ] -> V_6 , V_249 ) ;
F_117 ( ! V_274 [ 2 ] -> V_6 ) ;
}
for ( V_56 = V_306 ; V_56 < V_248 ; V_56 ++ ) {
char * V_2 = F_284 ( V_249 , L_88 , 1 << V_56 ) ;
F_117 ( ! V_2 ) ;
V_274 [ V_56 ] -> V_6 = V_2 ;
}
#ifdef F_285
F_286 ( & V_307 ) ;
#endif
#ifdef F_250
for ( V_56 = 0 ; V_56 < V_248 ; V_56 ++ ) {
struct V_1 * V_2 = V_274 [ V_56 ] ;
if ( V_2 && V_2 -> V_18 ) {
char * V_6 = F_284 ( V_249 ,
L_89 , V_2 -> V_24 ) ;
F_117 ( ! V_6 ) ;
V_273 [ V_56 ] = F_247 ( V_6 ,
V_2 -> V_24 , V_256 ) ;
}
}
#endif
F_37 ( V_45
L_90
L_91 ,
V_297 , F_211 () ,
V_234 , V_240 , V_238 ,
V_239 , V_301 ) ;
}
void T_7 F_287 ( void )
{
}
static int F_288 ( struct V_1 * V_2 )
{
if ( V_267 || ( V_2 -> V_3 & V_308 ) )
return 1 ;
if ( V_2 -> F_103 )
return 1 ;
if ( V_2 -> V_261 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_289 ( T_1 V_18 ,
T_1 V_243 , unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
if ( V_267 || ( V_3 & V_308 ) )
return NULL ;
if ( F_103 )
return NULL ;
V_18 = F_212 ( V_18 , sizeof( void * ) ) ;
V_243 = F_210 ( V_3 , V_243 , V_18 ) ;
V_18 = F_212 ( V_18 , V_243 ) ;
V_3 = F_102 ( V_18 , V_3 , V_6 , NULL ) ;
F_179 (s, &slab_caches, list) {
if ( F_288 ( V_2 ) )
continue;
if ( V_18 > V_2 -> V_18 )
continue;
if ( ( V_3 & V_309 ) != ( V_2 -> V_3 & V_309 ) )
continue;
if ( ( V_2 -> V_18 & ~ ( V_243 - 1 ) ) != V_2 -> V_18 )
continue;
if ( V_2 -> V_18 - V_18 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_290 ( const char * V_6 , T_1 V_18 ,
T_1 V_243 , unsigned long V_3 , void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
char * V_40 ;
if ( F_259 ( ! V_6 ) )
return NULL ;
F_239 ( & V_264 ) ;
V_2 = F_289 ( V_18 , V_243 , V_3 , V_6 , F_103 ) ;
if ( V_2 ) {
V_2 -> V_261 ++ ;
V_2 -> V_24 = F_207 ( V_2 -> V_24 , ( int ) V_18 ) ;
V_2 -> V_27 = F_291 ( int , V_2 -> V_27 , F_212 ( V_18 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_261 -- ;
goto V_310;
}
F_240 ( & V_264 ) ;
return V_2 ;
}
V_40 = F_283 ( V_6 , V_251 ) ;
if ( ! V_40 )
goto V_310;
V_2 = F_266 ( V_259 , V_251 ) ;
if ( V_2 ) {
if ( F_226 ( V_2 , V_40 ,
V_18 , V_243 , V_3 , F_103 ) ) {
F_86 ( & V_2 -> V_265 , & V_269 ) ;
if ( F_4 ( V_2 ) ) {
F_88 ( & V_2 -> V_265 ) ;
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
goto V_310;
}
F_240 ( & V_264 ) ;
return V_2 ;
}
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
}
V_310:
F_240 ( & V_264 ) ;
if ( V_3 & V_262 )
F_229 ( L_92 , V_6 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int T_9 F_292 ( struct V_287 * V_311 ,
unsigned long V_289 , void * V_312 )
{
long V_64 = ( long ) V_312 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_289 ) {
case V_313 :
case V_314 :
case V_315 :
case V_316 :
F_270 ( & V_264 ) ;
F_179 (s, &slab_caches, list) {
F_39 ( V_3 ) ;
F_169 ( V_2 , V_64 ) ;
F_40 ( V_3 ) ;
}
F_271 ( & V_264 ) ;
break;
default:
break;
}
return V_296 ;
}
void * F_293 ( T_1 V_18 , T_5 V_204 , unsigned long V_317 )
{
struct V_1 * V_2 ;
void * V_219 ;
if ( F_3 ( V_18 > V_275 ) )
return F_252 ( V_18 , V_204 ) ;
V_2 = F_249 ( V_18 , V_204 ) ;
if ( F_3 ( F_253 ( V_2 ) ) )
return V_2 ;
V_219 = F_189 ( V_2 , V_204 , V_125 , V_317 ) ;
F_195 ( V_317 , V_219 , V_18 , V_2 -> V_18 , V_204 ) ;
return V_219 ;
}
void * F_294 ( T_1 V_18 , T_5 V_204 ,
int V_13 , unsigned long V_317 )
{
struct V_1 * V_2 ;
void * V_219 ;
if ( F_3 ( V_18 > V_275 ) ) {
V_219 = F_254 ( V_18 , V_204 , V_13 ) ;
F_201 ( V_317 , V_219 ,
V_18 , V_30 << F_183 ( V_18 ) ,
V_204 , V_13 ) ;
return V_219 ;
}
V_2 = F_249 ( V_18 , V_204 ) ;
if ( F_3 ( F_253 ( V_2 ) ) )
return V_2 ;
V_219 = F_189 ( V_2 , V_204 , V_13 , V_317 ) ;
F_201 ( V_317 , V_219 , V_18 , V_2 -> V_18 , V_204 , V_13 ) ;
return V_219 ;
}
static int F_295 ( struct V_14 * V_14 )
{
return V_14 -> V_27 ;
}
static int F_296 ( struct V_14 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_297 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
if ( ! F_69 ( V_2 , V_14 ) ||
! F_71 ( V_2 , V_14 , NULL ) )
return 0 ;
F_298 ( V_46 , V_14 -> V_17 ) ;
F_41 ( V_2 , V_14 , V_46 ) ;
F_119 (p, s, addr, page->objects) {
if ( F_234 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) )
if ( ! F_68 ( V_2 , V_14 , V_5 , V_109 ) )
return 0 ;
}
F_119 (p, s, addr, page->objects)
if ( ! F_234 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) )
if ( ! F_68 ( V_2 , V_14 , V_5 , V_93 ) )
return 0 ;
return 1 ;
}
static void F_299 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_46 )
{
F_26 ( V_14 ) ;
F_297 ( V_2 , V_14 , V_46 ) ;
F_28 ( V_14 ) ;
}
static int F_300 ( struct V_1 * V_2 ,
struct V_12 * V_40 , unsigned long * V_46 )
{
unsigned long V_318 = 0 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_178 ( & V_40 -> V_161 , V_3 ) ;
F_179 (page, &n->partial, lru) {
F_299 ( V_2 , V_14 , V_46 ) ;
V_318 ++ ;
}
if ( V_318 != V_40 -> V_153 )
F_37 ( V_49 L_93
L_94 , V_2 -> V_6 , V_318 , V_40 -> V_153 ) ;
if ( ! ( V_2 -> V_3 & V_26 ) )
goto V_113;
F_179 (page, &n->full, lru) {
F_299 ( V_2 , V_14 , V_46 ) ;
V_318 ++ ;
}
if ( V_318 != F_90 ( & V_40 -> V_107 ) )
F_37 ( V_49 L_95
L_94 , V_2 -> V_6 , V_318 ,
F_90 ( & V_40 -> V_107 ) ) ;
V_113:
F_180 ( & V_40 -> V_161 , V_3 ) ;
return V_318 ;
}
static long F_301 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_318 = 0 ;
unsigned long * V_46 = F_266 ( F_233 ( F_25 ( V_2 -> F_207 ) ) *
sizeof( unsigned long ) , V_251 ) ;
if ( ! V_46 )
return - V_280 ;
F_172 ( V_2 ) ;
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
V_318 += F_300 ( V_2 , V_40 , V_46 ) ;
}
F_7 ( V_46 ) ;
return V_318 ;
}
static void F_302 ( struct V_319 * V_71 )
{
if ( V_71 -> F_207 )
F_281 ( ( unsigned long ) V_71 -> V_320 ,
F_183 ( sizeof( struct V_321 ) * V_71 -> F_207 ) ) ;
}
static int F_303 ( struct V_319 * V_71 , unsigned long F_207 , T_5 V_3 )
{
struct V_321 * V_184 ;
int V_28 ;
V_28 = F_183 ( sizeof( struct V_321 ) * F_207 ) ;
V_184 = ( void * ) F_279 ( V_3 , V_28 ) ;
if ( ! V_184 )
return 0 ;
if ( V_71 -> V_318 ) {
memcpy ( V_184 , V_71 -> V_320 , sizeof( struct V_321 ) * V_71 -> V_318 ) ;
F_302 ( V_71 ) ;
}
V_71 -> F_207 = F_207 ;
V_71 -> V_320 = V_184 ;
return 1 ;
}
static int F_304 ( struct V_319 * V_71 , struct V_1 * V_2 ,
const struct V_51 * V_51 )
{
long V_85 , V_89 , V_322 ;
struct V_321 * V_184 ;
unsigned long V_323 ;
unsigned long V_324 = V_68 - V_51 -> V_67 ;
V_85 = - 1 ;
V_89 = V_71 -> V_318 ;
for ( ; ; ) {
V_322 = V_85 + ( V_89 - V_85 + 1 ) / 2 ;
if ( V_322 == V_89 )
break;
V_323 = V_71 -> V_320 [ V_322 ] . V_21 ;
if ( V_51 -> V_21 == V_323 ) {
V_184 = & V_71 -> V_320 [ V_322 ] ;
V_184 -> V_318 ++ ;
if ( V_51 -> V_67 ) {
V_184 -> V_325 += V_324 ;
if ( V_324 < V_184 -> V_326 )
V_184 -> V_326 = V_324 ;
if ( V_324 > V_184 -> V_327 )
V_184 -> V_327 = V_324 ;
if ( V_51 -> V_65 < V_184 -> V_328 )
V_184 -> V_328 = V_51 -> V_65 ;
if ( V_51 -> V_65 > V_184 -> V_329 )
V_184 -> V_329 = V_51 -> V_65 ;
F_305 ( V_51 -> V_64 ,
F_306 ( V_184 -> V_330 ) ) ;
}
F_307 ( F_118 ( F_308 ( V_51 ) ) , V_184 -> V_331 ) ;
return 1 ;
}
if ( V_51 -> V_21 < V_323 )
V_89 = V_322 ;
else
V_85 = V_322 ;
}
if ( V_71 -> V_318 >= V_71 -> F_207 && ! F_303 ( V_71 , 2 * V_71 -> F_207 , V_263 ) )
return 0 ;
V_184 = V_71 -> V_320 + V_322 ;
if ( V_322 < V_71 -> V_318 )
memmove ( V_184 + 1 , V_184 ,
( V_71 -> V_318 - V_322 ) * sizeof( struct V_321 ) ) ;
V_71 -> V_318 ++ ;
V_184 -> V_318 = 1 ;
V_184 -> V_21 = V_51 -> V_21 ;
V_184 -> V_325 = V_324 ;
V_184 -> V_326 = V_324 ;
V_184 -> V_327 = V_324 ;
V_184 -> V_328 = V_51 -> V_65 ;
V_184 -> V_329 = V_51 -> V_65 ;
F_309 ( F_306 ( V_184 -> V_330 ) ) ;
F_305 ( V_51 -> V_64 , F_306 ( V_184 -> V_330 ) ) ;
F_310 ( V_184 -> V_331 ) ;
F_307 ( F_118 ( F_308 ( V_51 ) ) , V_184 -> V_331 ) ;
return 1 ;
}
static void F_311 ( struct V_319 * V_71 , struct V_1 * V_2 ,
struct V_14 * V_14 , enum V_52 V_53 ,
unsigned long * V_46 )
{
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
F_298 ( V_46 , V_14 -> V_17 ) ;
F_41 ( V_2 , V_14 , V_46 ) ;
F_119 (p, s, addr, page->objects)
if ( ! F_234 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) )
F_304 ( V_71 , V_2 , F_45 ( V_2 , V_5 , V_53 ) ) ;
}
static int F_312 ( struct V_1 * V_2 , char * V_73 ,
enum V_52 V_53 )
{
int V_332 = 0 ;
unsigned long V_56 ;
struct V_319 V_71 = { 0 , 0 , NULL } ;
int V_13 ;
unsigned long * V_46 = F_266 ( F_233 ( F_25 ( V_2 -> F_207 ) ) *
sizeof( unsigned long ) , V_251 ) ;
if ( ! V_46 || ! F_303 ( & V_71 , V_30 / sizeof( struct V_321 ) ,
V_333 ) ) {
F_7 ( V_46 ) ;
return sprintf ( V_73 , L_96 ) ;
}
F_172 ( V_2 ) ;
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_3 ;
struct V_14 * V_14 ;
if ( ! F_90 ( & V_40 -> V_107 ) )
continue;
F_178 ( & V_40 -> V_161 , V_3 ) ;
F_179 (page, &n->partial, lru)
F_311 ( & V_71 , V_2 , V_14 , V_53 , V_46 ) ;
F_179 (page, &n->full, lru)
F_311 ( & V_71 , V_2 , V_14 , V_53 , V_46 ) ;
F_180 ( & V_40 -> V_161 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_318 ; V_56 ++ ) {
struct V_321 * V_184 = & V_71 . V_320 [ V_56 ] ;
if ( V_332 > V_30 - V_334 - 100 )
break;
V_332 += sprintf ( V_73 + V_332 , L_97 , V_184 -> V_318 ) ;
if ( V_184 -> V_21 )
V_332 += sprintf ( V_73 + V_332 , L_98 , ( void * ) V_184 -> V_21 ) ;
else
V_332 += sprintf ( V_73 + V_332 , L_99 ) ;
if ( V_184 -> V_325 != V_184 -> V_326 ) {
V_332 += sprintf ( V_73 + V_332 , L_100 ,
V_184 -> V_326 ,
( long ) F_313 ( V_184 -> V_325 , V_184 -> V_318 ) ,
V_184 -> V_327 ) ;
} else
V_332 += sprintf ( V_73 + V_332 , L_101 ,
V_184 -> V_326 ) ;
if ( V_184 -> V_328 != V_184 -> V_329 )
V_332 += sprintf ( V_73 + V_332 , L_102 ,
V_184 -> V_328 , V_184 -> V_329 ) ;
else
V_332 += sprintf ( V_73 + V_332 , L_103 ,
V_184 -> V_328 ) ;
if ( F_314 () > 1 &&
! F_315 ( F_306 ( V_184 -> V_330 ) ) &&
V_332 < V_30 - 60 ) {
V_332 += sprintf ( V_73 + V_332 , L_104 ) ;
V_332 += F_316 ( V_73 + V_332 , V_30 - V_332 - 50 ,
F_306 ( V_184 -> V_330 ) ) ;
}
if ( V_335 > 1 && ! F_317 ( V_184 -> V_331 ) &&
V_332 < V_30 - 60 ) {
V_332 += sprintf ( V_73 + V_332 , L_105 ) ;
V_332 += F_318 ( V_73 + V_332 , V_30 - V_332 - 50 ,
V_184 -> V_331 ) ;
}
V_332 += sprintf ( V_73 + V_332 , L_106 ) ;
}
F_302 ( & V_71 ) ;
F_7 ( V_46 ) ;
if ( ! V_71 . V_318 )
V_332 += sprintf ( V_73 , L_107 ) ;
return V_332 ;
}
static void F_319 ( void )
{
T_3 * V_5 ;
F_218 ( V_304 > 16 || V_248 < 10 ) ;
F_37 ( V_49 L_108 ) ;
F_37 ( V_49 L_109 ) ;
F_37 ( V_49 L_110 ) ;
V_5 = F_232 ( 16 , V_251 ) ;
V_5 [ 16 ] = 0x12 ;
F_37 ( V_49 L_111
L_112 , V_5 + 16 ) ;
F_301 ( V_274 [ 4 ] ) ;
V_5 = F_232 ( 32 , V_251 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_37 ( V_49 L_113
L_114 , V_5 ) ;
F_37 ( V_49
L_115 ) ;
F_301 ( V_274 [ 5 ] ) ;
V_5 = F_232 ( 64 , V_251 ) ;
V_5 += 64 + ( F_143 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_37 ( V_49 L_116 ,
V_5 ) ;
F_37 ( V_49
L_115 ) ;
F_301 ( V_274 [ 6 ] ) ;
F_37 ( V_49 L_117 ) ;
V_5 = F_232 ( 128 , V_251 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_37 ( V_49 L_118 , V_5 ) ;
F_301 ( V_274 [ 7 ] ) ;
V_5 = F_232 ( 256 , V_251 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_37 ( V_49 L_119 ,
V_5 ) ;
F_301 ( V_274 [ 8 ] ) ;
V_5 = F_232 ( 512 , V_251 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_37 ( V_49 L_120 , V_5 ) ;
F_301 ( V_274 [ 9 ] ) ;
}
static void F_319 ( void ) {}
static T_10 F_320 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_336 = 0 ;
int V_13 ;
int V_32 ;
unsigned long * V_331 ;
unsigned long * V_337 ;
V_331 = F_232 ( 2 * sizeof( unsigned long ) * V_301 , V_251 ) ;
if ( ! V_331 )
return - V_280 ;
V_337 = V_331 + V_301 ;
if ( V_3 & V_338 ) {
int V_64 ;
F_161 (cpu) {
struct V_158 * V_159 = F_162 ( V_2 -> V_9 , V_64 ) ;
int V_13 = F_321 ( V_159 -> V_13 ) ;
struct V_14 * V_14 ;
if ( V_13 < 0 )
continue;
V_14 = F_321 ( V_159 -> V_14 ) ;
if ( V_14 ) {
if ( V_3 & V_339 )
V_32 = V_14 -> V_17 ;
else if ( V_3 & V_340 )
V_32 = V_14 -> V_27 ;
else
V_32 = 1 ;
V_336 += V_32 ;
V_331 [ V_13 ] += V_32 ;
}
V_14 = V_159 -> V_155 ;
if ( V_14 ) {
V_32 = V_14 -> V_200 ;
V_336 += V_32 ;
V_331 [ V_13 ] += V_32 ;
}
V_337 [ V_13 ] ++ ;
}
}
F_322 () ;
#ifdef F_2
if ( V_3 & V_341 ) {
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_339 )
V_32 = F_90 ( & V_40 -> V_108 ) ;
else if ( V_3 & V_340 )
V_32 = F_90 ( & V_40 -> V_108 ) -
F_176 ( V_40 , F_175 ) ;
else
V_32 = F_90 ( & V_40 -> V_107 ) ;
V_336 += V_32 ;
V_331 [ V_13 ] += V_32 ;
}
} else
#endif
if ( V_3 & V_342 ) {
F_222 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_339 )
V_32 = F_176 ( V_40 , F_296 ) ;
else if ( V_3 & V_340 )
V_32 = F_176 ( V_40 , F_295 ) ;
else
V_32 = V_40 -> V_153 ;
V_336 += V_32 ;
V_331 [ V_13 ] += V_32 ;
}
}
V_32 = sprintf ( V_73 , L_121 , V_336 ) ;
#ifdef F_141
F_222 (node, N_NORMAL_MEMORY)
if ( V_331 [ V_13 ] )
V_32 += sprintf ( V_73 + V_32 , L_122 ,
V_13 , V_331 [ V_13 ] ) ;
#endif
F_323 () ;
F_7 ( V_331 ) ;
return V_32 + sprintf ( V_73 + V_32 , L_106 ) ;
}
static int F_324 ( struct V_1 * V_2 )
{
int V_13 ;
F_184 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
if ( F_90 ( & V_40 -> V_108 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_325 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_18 ) ;
}
static T_10 F_326 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_243 ) ;
}
static T_10 F_327 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_24 ) ;
}
static T_10 F_328 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , F_25 ( V_2 -> V_123 ) ) ;
}
static T_10 F_329 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_28 ;
int V_310 ;
V_310 = F_330 ( V_73 , 10 , & V_28 ) ;
if ( V_310 )
return V_310 ;
if ( V_28 > V_240 || V_28 < V_234 )
return - V_343 ;
F_225 ( V_2 , V_28 ) ;
return V_48 ;
}
static T_10 F_331 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , F_24 ( V_2 -> V_123 ) ) ;
}
static T_10 F_332 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_124 , V_2 -> V_173 ) ;
}
static T_10 F_333 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_131 ;
int V_310 ;
V_310 = F_330 ( V_73 , 10 , & V_131 ) ;
if ( V_310 )
return V_310 ;
F_224 ( V_2 , V_131 ) ;
return V_48 ;
}
static T_10 F_334 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_125 , V_2 -> V_164 ) ;
}
static T_10 F_335 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_17 ;
int V_310 ;
V_310 = F_330 ( V_73 , 10 , & V_17 ) ;
if ( V_310 )
return V_310 ;
V_2 -> V_164 = V_17 ;
F_172 ( V_2 ) ;
return V_48 ;
}
static T_10 F_336 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! V_2 -> F_103 )
return 0 ;
return sprintf ( V_73 , L_126 , V_2 -> F_103 ) ;
}
static T_10 F_337 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_261 - 1 ) ;
}
static T_10 F_338 ( struct V_1 * V_2 , char * V_73 )
{
return F_320 ( V_2 , V_73 , V_342 ) ;
}
static T_10 F_339 ( struct V_1 * V_2 , char * V_73 )
{
return F_320 ( V_2 , V_73 , V_338 ) ;
}
static T_10 F_340 ( struct V_1 * V_2 , char * V_73 )
{
return F_320 ( V_2 , V_73 , V_341 | V_340 ) ;
}
static T_10 F_341 ( struct V_1 * V_2 , char * V_73 )
{
return F_320 ( V_2 , V_73 , V_342 | V_340 ) ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_73 )
{
int V_17 = 0 ;
int V_135 = 0 ;
int V_64 ;
int V_332 ;
F_343 (cpu) {
struct V_14 * V_14 = F_162 ( V_2 -> V_9 , V_64 ) -> V_155 ;
if ( V_14 ) {
V_135 += V_14 -> V_135 ;
V_17 += V_14 -> V_200 ;
}
}
V_332 = sprintf ( V_73 , L_127 , V_17 , V_135 ) ;
#ifdef F_285
F_343 (cpu) {
struct V_14 * V_14 = F_162 ( V_2 -> V_9 , V_64 ) -> V_155 ;
if ( V_14 && V_332 < V_30 - 20 )
V_332 += sprintf ( V_73 + V_332 , L_128 , V_64 ,
V_14 -> V_200 , V_14 -> V_135 ) ;
}
#endif
return V_332 + sprintf ( V_73 + V_332 , L_106 ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_136 ) ) ;
}
static T_10 F_345 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_136 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_136 ;
return V_48 ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_244 ) ) ;
}
static T_10 F_347 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_256 ) ) ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_25 ) ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_29 ) ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_73 )
{
return F_320 ( V_2 , V_73 , V_341 ) ;
}
static T_10 F_351 ( struct V_1 * V_2 , char * V_73 )
{
return F_320 ( V_2 , V_73 , V_341 | V_339 ) ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_120 ) ) ;
}
static T_10 F_353 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_120 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_120 ;
}
return V_48 ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_99 ) ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_99 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_99 ;
}
return V_48 ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_357 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_324 ( V_2 ) )
return - V_344 ;
V_2 -> V_3 &= ~ V_22 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_22 ;
}
F_225 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_359 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_324 ( V_2 ) )
return - V_344 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_23 ;
}
F_225 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_26 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_324 ( V_2 ) )
return - V_344 ;
V_2 -> V_3 &= ~ V_26 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_26 ;
}
F_225 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_363 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
int V_219 = - V_343 ;
if ( V_73 [ 0 ] == '1' ) {
V_219 = F_301 ( V_2 ) ;
if ( V_219 >= 0 )
V_219 = V_48 ;
}
return V_219 ;
}
static T_10 F_364 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_242 ;
return F_312 ( V_2 , V_73 , V_70 ) ;
}
static T_10 F_365 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_242 ;
return F_312 ( V_2 , V_73 , V_69 ) ;
}
static T_10 F_366 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , ! ! ( V_2 -> V_3 & V_121 ) ) ;
}
static T_10 F_367 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_121 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_121 ;
return V_48 ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_369 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( V_73 [ 0 ] == '1' ) {
int V_111 = F_265 ( V_2 ) ;
if ( V_111 )
return V_111 ;
} else
return - V_343 ;
return V_48 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_171 / 10 ) ;
}
static T_10 F_371 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_345 ;
int V_310 ;
V_310 = F_330 ( V_73 , 10 , & V_345 ) ;
if ( V_310 )
return V_310 ;
if ( V_345 <= 100 )
V_2 -> V_171 = V_345 * 10 ;
return V_48 ;
}
static int F_372 ( struct V_1 * V_2 , char * V_73 , enum V_7 V_8 )
{
unsigned long V_346 = 0 ;
int V_64 ;
int V_332 ;
int * V_81 = F_266 ( V_239 * sizeof( int ) , V_251 ) ;
if ( ! V_81 )
return - V_280 ;
F_343 (cpu) {
unsigned V_32 = F_162 ( V_2 -> V_9 , V_64 ) -> F_8 [ V_8 ] ;
V_81 [ V_64 ] = V_32 ;
V_346 += V_32 ;
}
V_332 = sprintf ( V_73 , L_121 , V_346 ) ;
#ifdef F_285
F_343 (cpu) {
if ( V_81 [ V_64 ] && V_332 < V_30 - 20 )
V_332 += sprintf ( V_73 + V_332 , L_129 , V_64 , V_81 [ V_64 ] ) ;
}
#endif
F_7 ( V_81 ) ;
return V_332 + sprintf ( V_73 + V_332 , L_106 ) ;
}
static void F_373 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_64 ;
F_343 (cpu)
F_162 ( V_2 -> V_9 , V_64 ) -> F_8 [ V_8 ] = 0 ;
}
static T_10 F_374 ( struct V_347 * V_348 ,
struct V_349 * V_350 ,
char * V_73 )
{
struct V_351 * V_349 ;
struct V_1 * V_2 ;
int V_310 ;
V_349 = F_375 ( V_350 ) ;
V_2 = F_376 ( V_348 ) ;
if ( ! V_349 -> V_352 )
return - V_353 ;
V_310 = V_349 -> V_352 ( V_2 , V_73 ) ;
return V_310 ;
}
static T_10 F_377 ( struct V_347 * V_348 ,
struct V_349 * V_350 ,
const char * V_73 , T_1 V_332 )
{
struct V_351 * V_349 ;
struct V_1 * V_2 ;
int V_310 ;
V_349 = F_375 ( V_350 ) ;
V_2 = F_376 ( V_348 ) ;
if ( ! V_349 -> V_354 )
return - V_353 ;
V_310 = V_349 -> V_354 ( V_2 , V_73 , V_332 ) ;
return V_310 ;
}
static void F_378 ( struct V_347 * V_348 )
{
struct V_1 * V_2 = F_376 ( V_348 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_379 ( struct V_355 * V_355 , struct V_347 * V_348 )
{
struct V_356 * V_357 = F_380 ( V_348 ) ;
if ( V_357 == & V_358 )
return 1 ;
return 0 ;
}
static char * F_381 ( struct V_1 * V_2 )
{
char * V_6 = F_266 ( V_359 , V_251 ) ;
char * V_5 = V_6 ;
F_117 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_256 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_136 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_120 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_134 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_6 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_130 , V_2 -> V_18 ) ;
F_117 ( V_5 > V_6 + V_359 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_310 ;
const char * V_6 ;
int V_360 ;
if ( V_10 < V_361 )
return 0 ;
V_360 = F_288 ( V_2 ) ;
if ( V_360 ) {
F_382 ( & V_362 -> V_348 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_381 ( V_2 ) ;
}
V_2 -> V_348 . V_355 = V_362 ;
V_310 = F_383 ( & V_2 -> V_348 , & V_358 , NULL , V_6 ) ;
if ( V_310 ) {
F_384 ( & V_2 -> V_348 ) ;
return V_310 ;
}
V_310 = F_385 ( & V_2 -> V_348 , & V_363 ) ;
if ( V_310 ) {
F_386 ( & V_2 -> V_348 ) ;
F_384 ( & V_2 -> V_348 ) ;
return V_310 ;
}
F_387 ( & V_2 -> V_348 , V_364 ) ;
if ( ! V_360 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_10 < V_361 )
return;
F_387 ( & V_2 -> V_348 , V_365 ) ;
F_386 ( & V_2 -> V_348 ) ;
F_384 ( & V_2 -> V_348 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_366 * V_367 ;
if ( V_10 == V_361 ) {
F_382 ( & V_362 -> V_348 , V_6 ) ;
return F_388 ( & V_362 -> V_348 , & V_2 -> V_348 , V_6 ) ;
}
V_367 = F_266 ( sizeof( struct V_366 ) , V_251 ) ;
if ( ! V_367 )
return - V_280 ;
V_367 -> V_2 = V_2 ;
V_367 -> V_6 = V_6 ;
V_367 -> V_196 = V_368 ;
V_368 = V_367 ;
return 0 ;
}
static int T_7 F_389 ( void )
{
struct V_1 * V_2 ;
int V_310 ;
F_239 ( & V_264 ) ;
V_362 = F_390 ( L_131 , & V_369 , V_370 ) ;
if ( ! V_362 ) {
F_240 ( & V_264 ) ;
F_37 ( V_49 L_132 ) ;
return - V_242 ;
}
V_10 = V_361 ;
F_179 (s, &slab_caches, list) {
V_310 = F_4 ( V_2 ) ;
if ( V_310 )
F_37 ( V_49 L_133
L_134 , V_2 -> V_6 ) ;
}
while ( V_368 ) {
struct V_366 * V_367 = V_368 ;
V_368 = V_368 -> V_196 ;
V_310 = F_5 ( V_367 -> V_2 , V_367 -> V_6 ) ;
if ( V_310 )
F_37 ( V_49 L_135
L_136 , V_2 -> V_6 ) ;
F_7 ( V_367 ) ;
}
F_240 ( & V_264 ) ;
F_319 () ;
return 0 ;
}
static void F_391 ( struct V_371 * V_185 )
{
F_392 ( V_185 , L_137 ) ;
F_392 ( V_185 , L_138
L_139 ) ;
F_392 ( V_185 , L_140 ) ;
F_392 ( V_185 , L_141 ) ;
F_393 ( V_185 , '\n' ) ;
}
static void * F_394 ( struct V_371 * V_185 , T_11 * V_322 )
{
T_11 V_40 = * V_322 ;
F_270 ( & V_264 ) ;
if ( ! V_40 )
F_391 ( V_185 ) ;
return F_395 ( & V_269 , * V_322 ) ;
}
static void * F_396 ( struct V_371 * V_185 , void * V_5 , T_11 * V_322 )
{
return F_397 ( V_5 , & V_269 , V_322 ) ;
}
static void F_398 ( struct V_371 * V_185 , void * V_5 )
{
F_271 ( & V_264 ) ;
}
static int F_399 ( struct V_371 * V_185 , void * V_5 )
{
unsigned long V_372 = 0 ;
unsigned long V_107 = 0 ;
unsigned long V_373 = 0 ;
unsigned long V_207 = 0 ;
unsigned long V_208 = 0 ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_400 ( V_5 , struct V_1 , V_265 ) ;
F_184 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
V_372 += V_40 -> V_153 ;
V_107 += F_90 ( & V_40 -> V_107 ) ;
V_207 += F_90 ( & V_40 -> V_108 ) ;
V_208 += F_176 ( V_40 , F_175 ) ;
}
V_373 = V_207 - V_208 ;
F_401 ( V_185 , L_142 , V_2 -> V_6 , V_373 ,
V_207 , V_2 -> V_18 , F_25 ( V_2 -> V_123 ) ,
( 1 << F_24 ( V_2 -> V_123 ) ) ) ;
F_401 ( V_185 , L_143 , 0 , 0 , 0 ) ;
F_401 ( V_185 , L_144 , V_107 , V_107 ,
0UL ) ;
F_393 ( V_185 , '\n' ) ;
return 0 ;
}
static int F_402 ( struct V_374 * V_374 , struct V_375 * V_375 )
{
return F_403 ( V_375 , & V_376 ) ;
}
static int T_7 F_404 ( void )
{
F_405 ( L_145 , V_377 , NULL , & V_378 ) ;
return 0 ;
}
