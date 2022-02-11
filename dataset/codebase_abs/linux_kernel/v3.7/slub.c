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
static inline void F_6 ( struct V_1 * V_2 ) { }
static inline void F_7 ( const struct V_1 * V_2 , enum V_6 V_7 )
{
#ifdef F_8
F_9 ( V_2 -> V_8 -> F_7 [ V_7 ] ) ;
#endif
}
static inline struct V_9 * F_10 ( struct V_1 * V_2 , int V_10 )
{
return V_2 -> V_10 [ V_10 ] ;
}
static inline int F_11 ( struct V_1 * V_2 ,
struct V_11 * V_11 , const void * V_12 )
{
void * V_13 ;
if ( ! V_12 )
return 1 ;
V_13 = F_12 ( V_11 ) ;
if ( V_12 < V_13 || V_12 >= V_13 + V_11 -> V_14 * V_2 -> V_15 ||
( V_12 - V_13 ) % V_2 -> V_15 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_13 ( struct V_1 * V_2 , void * V_12 )
{
return * ( void * * ) ( V_12 + V_2 -> V_16 ) ;
}
static void F_14 ( const struct V_1 * V_2 , void * V_12 )
{
F_15 ( V_12 + V_2 -> V_16 ) ;
}
static inline void * F_16 ( struct V_1 * V_2 , void * V_12 )
{
void * V_5 ;
#ifdef F_17
F_18 ( & V_5 , ( void * * ) ( V_12 + V_2 -> V_16 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_13 ( V_2 , V_12 ) ;
#endif
return V_5 ;
}
static inline void F_19 ( struct V_1 * V_2 , void * V_12 , void * V_17 )
{
* ( void * * ) ( V_12 + V_2 -> V_16 ) = V_17 ;
}
static inline int F_20 ( void * V_5 , struct V_1 * V_2 , void * V_18 )
{
return ( V_5 - V_18 ) / V_2 -> V_15 ;
}
static inline T_1 F_21 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_19 | V_20 ) )
return V_2 -> V_21 ;
#endif
if ( V_2 -> V_3 & ( V_22 | V_23 ) )
return V_2 -> V_24 ;
return V_2 -> V_15 ;
}
static inline int F_22 ( int V_25 , unsigned long V_15 , int V_26 )
{
return ( ( V_27 << V_25 ) - V_26 ) / V_15 ;
}
static inline struct V_28 F_23 ( int V_25 ,
unsigned long V_15 , int V_26 )
{
struct V_28 V_29 = {
( V_25 << V_30 ) + F_22 (order, size, reserved)
} ;
return V_29 ;
}
static inline int F_24 ( struct V_28 V_29 )
{
return V_29 . V_29 >> V_30 ;
}
static inline int F_25 ( struct V_28 V_29 )
{
return V_29 . V_29 & V_31 ;
}
static T_2 void F_26 ( struct V_11 * V_11 )
{
F_27 ( V_32 , & V_11 -> V_3 ) ;
}
static T_2 void F_28 ( struct V_11 * V_11 )
{
F_29 ( V_32 , & V_11 -> V_3 ) ;
}
static inline bool F_30 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_33 , unsigned long V_34 ,
void * V_35 , unsigned long V_36 ,
const char * V_37 )
{
F_31 ( ! F_32 () ) ;
#if F_33 ( V_38 ) && \
F_33 ( V_39 )
if ( V_2 -> V_3 & V_40 ) {
if ( F_34 ( & V_11 -> V_41 , & V_11 -> V_42 ,
V_33 , V_34 ,
V_35 , V_36 ) )
return 1 ;
} else
#endif
{
F_26 ( V_11 ) ;
if ( V_11 -> V_41 == V_33 && V_11 -> V_42 == V_34 ) {
V_11 -> V_41 = V_35 ;
V_11 -> V_42 = V_36 ;
F_28 ( V_11 ) ;
return 1 ;
}
F_28 ( V_11 ) ;
}
F_35 () ;
F_7 ( V_2 , V_43 ) ;
#ifdef F_36
F_37 ( V_44 L_1 , V_37 , V_2 -> V_45 ) ;
#endif
return 0 ;
}
static inline bool F_38 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_33 , unsigned long V_34 ,
void * V_35 , unsigned long V_36 ,
const char * V_37 )
{
#if F_33 ( V_38 ) && \
F_33 ( V_39 )
if ( V_2 -> V_3 & V_40 ) {
if ( F_34 ( & V_11 -> V_41 , & V_11 -> V_42 ,
V_33 , V_34 ,
V_35 , V_36 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_26 ( V_11 ) ;
if ( V_11 -> V_41 == V_33 && V_11 -> V_42 == V_34 ) {
V_11 -> V_41 = V_35 ;
V_11 -> V_42 = V_36 ;
F_28 ( V_11 ) ;
F_40 ( V_3 ) ;
return 1 ;
}
F_28 ( V_11 ) ;
F_40 ( V_3 ) ;
}
F_35 () ;
F_7 ( V_2 , V_43 ) ;
#ifdef F_36
F_37 ( V_44 L_1 , V_37 , V_2 -> V_45 ) ;
#endif
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long * V_46 )
{
void * V_5 ;
void * V_18 = F_12 ( V_11 ) ;
for ( V_5 = V_11 -> V_41 ; V_5 ; V_5 = F_13 ( V_2 , V_5 ) )
F_42 ( F_20 ( V_5 , V_2 , V_18 ) , V_46 ) ;
}
static void F_43 ( char * V_47 , T_3 * V_18 , unsigned int V_48 )
{
F_44 ( V_49 , V_47 , V_50 , 16 , 1 , V_18 ,
V_48 , 1 ) ;
}
static struct V_51 * F_45 ( struct V_1 * V_2 , void * V_12 ,
enum V_52 V_53 )
{
struct V_51 * V_5 ;
if ( V_2 -> V_16 )
V_5 = V_12 + V_2 -> V_16 + sizeof( void * ) ;
else
V_5 = V_12 + V_2 -> V_24 ;
return V_5 + V_53 ;
}
static void F_46 ( struct V_1 * V_2 , void * V_12 ,
enum V_52 V_53 , unsigned long V_18 )
{
struct V_51 * V_5 = F_45 ( V_2 , V_12 , V_53 ) ;
if ( V_18 ) {
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
V_5 -> V_18 = V_18 ;
V_5 -> V_64 = F_49 () ;
V_5 -> V_65 = V_66 -> V_65 ;
V_5 -> V_67 = V_68 ;
} else
memset ( V_5 , 0 , sizeof( struct V_51 ) ) ;
}
static void F_50 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_46 ( V_2 , V_12 , V_69 , 0UL ) ;
F_46 ( V_2 , V_12 , V_70 , 0UL ) ;
}
static void F_51 ( const char * V_2 , struct V_51 * V_71 )
{
if ( ! V_71 -> V_18 )
return;
F_37 ( V_49 L_2 ,
V_2 , ( void * ) V_71 -> V_18 , V_68 - V_71 -> V_67 , V_71 -> V_64 , V_71 -> V_65 ) ;
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
static void F_52 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_51 ( L_4 , F_45 ( V_2 , V_12 , V_70 ) ) ;
F_51 ( L_5 , F_45 ( V_2 , V_12 , V_69 ) ) ;
}
static void F_53 ( struct V_11 * V_11 )
{
F_37 ( V_49 L_6 ,
V_11 , V_11 -> V_14 , V_11 -> V_24 , V_11 -> V_41 , V_11 -> V_3 ) ;
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
F_37 ( V_49 L_9 , V_2 -> V_45 , F_55 () , V_73 ) ;
F_37 ( V_49 L_10
L_11 ) ;
F_56 ( V_74 ) ;
}
static void F_57 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_37 ( V_49 L_12 , V_2 -> V_45 , V_73 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned int V_75 ;
T_3 * V_18 = F_12 ( V_11 ) ;
F_52 ( V_2 , V_5 ) ;
F_53 ( V_11 ) ;
F_37 ( V_49 L_13 ,
V_5 , V_5 - V_18 , F_13 ( V_2 , V_5 ) ) ;
if ( V_5 > V_18 + 16 )
F_43 ( L_14 , V_5 - 16 , 16 ) ;
F_43 ( L_15 , V_5 , F_59 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_19 )
F_43 ( L_16 , V_5 + V_2 -> V_21 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
if ( V_2 -> V_16 )
V_75 = V_2 -> V_16 + sizeof( void * ) ;
else
V_75 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_75 += 2 * sizeof( struct V_51 ) ;
if ( V_75 != V_2 -> V_15 )
F_43 ( L_17 , V_5 + V_75 , V_2 -> V_15 - V_75 ) ;
F_60 () ;
}
static void F_61 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_76 )
{
F_54 ( V_2 , L_18 , V_76 ) ;
F_58 ( V_2 , V_11 , V_12 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_11 , const char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_54 ( V_2 , L_18 , V_73 ) ;
F_53 ( V_11 ) ;
F_60 () ;
}
static void F_63 ( struct V_1 * V_2 , void * V_12 , T_3 V_77 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_78 ) {
memset ( V_5 , V_79 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_80 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_77 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_64 ( struct V_1 * V_2 , char * V_81 , T_3 V_82 ,
void * V_83 , void * V_84 )
{
F_57 ( V_2 , L_19 , V_83 , V_84 - 1 , V_82 ) ;
memset ( V_83 , V_82 , V_84 - V_83 ) ;
}
static int F_65 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_85 ,
T_3 * V_86 , unsigned int V_87 , unsigned int V_88 )
{
T_3 * V_89 ;
T_3 * V_90 ;
V_89 = F_66 ( V_86 , V_87 , V_88 ) ;
if ( ! V_89 )
return 1 ;
V_90 = V_86 + V_88 ;
while ( V_90 > V_89 && V_90 [ - 1 ] == V_87 )
V_90 -- ;
F_54 ( V_2 , L_20 , V_85 ) ;
F_37 ( V_49 L_21 ,
V_89 , V_90 - 1 , V_89 [ 0 ] , V_87 ) ;
F_58 ( V_2 , V_11 , V_12 ) ;
F_64 ( V_2 , V_85 , V_87 , V_89 , V_90 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_75 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_75 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_75 += 2 * sizeof( struct V_51 ) ;
if ( V_2 -> V_15 == V_75 )
return 1 ;
return F_65 ( V_2 , V_11 , V_5 , L_22 ,
V_5 + V_75 , V_91 , V_2 -> V_15 - V_75 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_86 ;
T_3 * V_89 ;
T_3 * V_90 ;
int V_48 ;
int V_92 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_86 = F_12 ( V_11 ) ;
V_48 = ( V_27 << F_69 ( V_11 ) ) - V_2 -> V_26 ;
V_90 = V_86 + V_48 ;
V_92 = V_48 % V_2 -> V_15 ;
if ( ! V_92 )
return 1 ;
V_89 = F_66 ( V_90 - V_92 , V_91 , V_92 ) ;
if ( ! V_89 )
return 1 ;
while ( V_90 > V_89 && V_90 [ - 1 ] == V_91 )
V_90 -- ;
F_62 ( V_2 , V_11 , L_23 , V_89 , V_90 - 1 ) ;
F_43 ( L_17 , V_90 - V_92 , V_92 ) ;
F_64 ( V_2 , L_24 , V_91 , V_90 - V_92 , V_90 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_77 )
{
T_3 * V_5 = V_12 ;
T_3 * V_93 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_65 ( V_2 , V_11 , V_12 , L_25 ,
V_93 , V_77 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_65 ( V_2 , V_11 , V_5 , L_26 ,
V_93 , V_91 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_77 != V_94 && ( V_2 -> V_3 & V_78 ) &&
( ! F_65 ( V_2 , V_11 , V_5 , L_27 , V_5 ,
V_79 , V_2 -> V_21 - 1 ) ||
! F_65 ( V_2 , V_11 , V_5 , L_27 ,
V_5 + V_2 -> V_21 - 1 , V_80 , 1 ) ) )
return 0 ;
F_67 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_77 == V_94 )
return 1 ;
if ( ! F_11 ( V_2 , V_11 , F_13 ( V_2 , V_5 ) ) ) {
F_61 ( V_2 , V_11 , V_5 , L_28 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_95 ;
F_31 ( ! F_32 () ) ;
if ( ! F_72 ( V_11 ) ) {
F_62 ( V_2 , V_11 , L_29 ) ;
return 0 ;
}
V_95 = F_22 ( F_69 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_95 ) {
F_62 ( V_2 , V_11 , L_30 ,
V_2 -> V_45 , V_11 -> V_14 , V_95 ) ;
return 0 ;
}
if ( V_11 -> V_24 > V_11 -> V_14 ) {
F_62 ( V_2 , V_11 , L_31 ,
V_2 -> V_45 , V_11 -> V_24 , V_11 -> V_14 ) ;
return 0 ;
}
F_68 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_96 )
{
int V_97 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_98 ;
V_17 = V_11 -> V_41 ;
while ( V_17 && V_97 <= V_11 -> V_14 ) {
if ( V_17 == V_96 )
return 1 ;
if ( ! F_11 ( V_2 , V_11 , V_17 ) ) {
if ( V_12 ) {
F_61 ( V_2 , V_11 , V_12 ,
L_32 ) ;
F_19 ( V_2 , V_12 , NULL ) ;
break;
} else {
F_62 ( V_2 , V_11 , L_28 ) ;
V_11 -> V_41 = NULL ;
V_11 -> V_24 = V_11 -> V_14 ;
F_57 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_12 = V_17 ;
V_17 = F_13 ( V_2 , V_12 ) ;
V_97 ++ ;
}
V_98 = F_22 ( F_69 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_98 > V_99 )
V_98 = V_99 ;
if ( V_11 -> V_14 != V_98 ) {
F_62 ( V_2 , V_11 , L_34
L_35 , V_11 -> V_14 , V_98 ) ;
V_11 -> V_14 = V_98 ;
F_57 ( V_2 , L_36 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_97 ) {
F_62 ( V_2 , V_11 , L_37
L_38 , V_11 -> V_24 , V_11 -> V_14 - V_97 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_97 ;
F_57 ( V_2 , L_39 ) ;
}
return V_96 == NULL ;
}
static void V_55 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_53 )
{
if ( V_2 -> V_3 & V_100 ) {
F_37 ( V_44 L_40 ,
V_2 -> V_45 ,
V_53 ? L_41 : L_42 ,
V_12 , V_11 -> V_24 ,
V_11 -> V_41 ) ;
if ( ! V_53 )
F_43 ( L_15 , ( void * ) V_12 , V_2 -> V_21 ) ;
F_60 () ;
}
}
static inline int F_74 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_101 ;
F_75 ( V_3 ) ;
F_76 ( V_3 & V_102 ) ;
return F_77 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_78 ( struct V_1 * V_2 , T_5 V_3 , void * V_12 )
{
V_3 &= V_101 ;
F_79 ( V_2 , V_3 , V_12 , F_21 ( V_2 ) ) ;
F_80 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_81 ( struct V_1 * V_2 , void * V_29 )
{
F_82 ( V_29 , V_2 -> V_3 ) ;
#if F_33 ( V_103 ) || F_33 ( V_104 )
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_83 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_84 ( V_29 , V_2 -> V_21 ) ;
F_40 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_105 ) )
F_85 ( V_29 , V_2 -> V_21 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_87 ( & V_11 -> V_106 , & V_37 -> V_107 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_89 ( & V_11 -> V_106 ) ;
}
static inline unsigned long F_90 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
return F_91 ( & V_37 -> V_108 ) ;
}
static inline unsigned long F_92 ( struct V_9 * V_37 )
{
return F_91 ( & V_37 -> V_108 ) ;
}
static inline void F_93 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
if ( V_37 ) {
F_94 ( & V_37 -> V_108 ) ;
F_95 ( V_14 , & V_37 -> V_109 ) ;
}
}
static inline void F_96 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
F_97 ( & V_37 -> V_108 ) ;
F_98 ( V_14 , & V_37 -> V_109 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_78 ) ) )
return;
F_63 ( V_2 , V_12 , V_110 ) ;
F_50 ( V_2 , V_12 ) ;
}
static T_6 int F_100 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_71 ( V_2 , V_11 ) )
goto V_111;
if ( ! F_11 ( V_2 , V_11 , V_12 ) ) {
F_61 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_111;
}
if ( ! F_70 ( V_2 , V_11 , V_12 , V_110 ) )
goto V_111;
if ( V_2 -> V_3 & V_23 )
F_46 ( V_2 , V_12 , V_70 , V_18 ) ;
V_55 ( V_2 , V_11 , V_12 , 1 ) ;
F_63 ( V_2 , V_12 , V_94 ) ;
return 1 ;
V_111:
if ( F_72 ( V_11 ) ) {
F_57 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_41 = NULL ;
}
return 0 ;
}
int T_7 F_101 ( char * V_112 )
{
V_113 = V_114 ;
if ( * V_112 ++ != '=' || ! * V_112 )
goto V_115;
if ( * V_112 == ',' )
goto V_116;
if ( tolower ( * V_112 ) == 'o' ) {
V_117 = 1 ;
goto V_115;
}
V_113 = 0 ;
if ( * V_112 == '-' )
goto V_115;
for (; * V_112 && * V_112 != ',' ; V_112 ++ ) {
switch ( tolower ( * V_112 ) ) {
case 'f' :
V_113 |= V_118 ;
break;
case 'z' :
V_113 |= V_19 ;
break;
case 'p' :
V_113 |= V_20 ;
break;
case 'u' :
V_113 |= V_23 ;
break;
case 't' :
V_113 |= V_100 ;
break;
case 'a' :
V_113 |= V_119 ;
break;
default:
F_37 ( V_49 L_45
L_46 , * V_112 ) ;
}
}
V_116:
if ( * V_112 == ',' )
V_120 = V_112 + 1 ;
V_115:
return 1 ;
}
static unsigned long F_102 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_103)( void * ) )
{
if ( V_113 && ( ! V_120 ||
! strncmp ( V_120 , V_45 , strlen ( V_120 ) ) ) )
V_3 |= V_113 ;
return V_3 ;
}
static inline void F_99 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 ) {}
static inline int F_100 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 , unsigned long V_18 ) { return 0 ; }
static inline struct V_9 * F_104 (
struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
unsigned long V_18 , unsigned long * V_3 ) { return NULL ; }
static inline int F_68 ( struct V_1 * V_2 , struct V_11 * V_11 )
{ return 1 ; }
static inline int F_70 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_77 ) { return 1 ; }
static inline void F_86 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_11 * V_11 ) {}
static inline void F_88 ( struct V_1 * V_2 , struct V_11 * V_11 ) {}
static inline unsigned long F_102 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_103)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_90 ( struct V_1 * V_2 , int V_10 )
{ return 0 ; }
static inline unsigned long F_92 ( struct V_9 * V_37 )
{ return 0 ; }
static inline void F_93 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_96 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline int F_74 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_78 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_12 ) {}
static inline void F_81 ( struct V_1 * V_2 , void * V_29 ) {}
static inline struct V_11 * F_105 ( T_5 V_3 , int V_10 ,
struct V_28 V_121 )
{
int V_25 = F_24 ( V_121 ) ;
V_3 |= V_122 ;
if ( V_10 == V_123 )
return F_106 ( V_3 , V_25 ) ;
else
return F_107 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_108 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_121 = V_2 -> V_121 ;
T_5 V_124 ;
V_3 &= V_101 ;
if ( V_3 & V_102 )
F_109 () ;
V_3 |= V_2 -> V_125 ;
V_124 = ( V_3 | V_126 | V_127 ) & ~ V_128 ;
V_11 = F_105 ( V_124 , V_10 , V_121 ) ;
if ( F_3 ( ! V_11 ) ) {
V_121 = V_2 -> V_129 ;
V_11 = F_105 ( V_3 , V_10 , V_121 ) ;
if ( V_11 )
F_7 ( V_2 , V_130 ) ;
}
if ( V_131 && V_11
&& ! ( V_2 -> V_3 & ( V_132 | V_114 ) ) ) {
int V_133 = 1 << F_24 ( V_121 ) ;
F_110 ( V_11 , F_24 ( V_121 ) , V_3 , V_10 ) ;
if ( V_2 -> F_103 )
F_111 ( V_11 , V_133 ) ;
else
F_112 ( V_11 , V_133 ) ;
}
if ( V_3 & V_102 )
F_113 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_25 ( V_121 ) ;
F_114 ( F_115 ( V_11 ) ,
( V_2 -> V_3 & V_134 ) ?
V_135 : V_136 ,
1 << F_24 ( V_121 ) ) ;
return V_11 ;
}
static void F_116 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_99 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_103 ) )
V_2 -> F_103 ( V_12 ) ;
}
static struct V_11 * F_117 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_86 ;
void * V_137 ;
void * V_5 ;
F_118 ( V_3 & V_138 ) ;
V_11 = F_108 ( V_2 ,
V_3 & ( V_139 | V_140 ) , V_10 ) ;
if ( ! V_11 )
goto V_115;
F_93 ( V_2 , F_119 ( V_11 ) , V_11 -> V_14 ) ;
V_11 -> V_141 = V_2 ;
F_120 ( V_11 ) ;
if ( V_11 -> V_142 )
F_121 ( V_11 ) ;
V_86 = F_12 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_86 , V_91 , V_27 << F_69 ( V_11 ) ) ;
V_137 = V_86 ;
F_122 (p, s, start, page->objects) {
F_116 ( V_2 , V_11 , V_137 ) ;
F_19 ( V_2 , V_137 , V_5 ) ;
V_137 = V_5 ;
}
F_116 ( V_2 , V_11 , V_137 ) ;
F_19 ( V_2 , V_137 , NULL ) ;
V_11 -> V_41 = V_86 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_143 = 1 ;
V_115:
return V_11 ;
}
static void F_123 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_69 ( V_11 ) ;
int V_133 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_68 ( V_2 , V_11 ) ;
F_122 (p, s, page_address(page),
page->objects)
F_70 ( V_2 , V_11 , V_5 , V_110 ) ;
}
F_124 ( V_11 , F_69 ( V_11 ) ) ;
F_114 ( F_115 ( V_11 ) ,
( V_2 -> V_3 & V_134 ) ?
V_135 : V_136 ,
- V_133 ) ;
F_125 ( V_11 ) ;
F_126 ( V_11 ) ;
F_127 ( V_11 ) ;
if ( V_66 -> V_144 )
V_66 -> V_144 -> V_145 += V_133 ;
F_128 ( V_11 , V_25 ) ;
}
static void F_129 ( struct V_146 * V_147 )
{
struct V_11 * V_11 ;
if ( V_148 )
V_11 = F_130 ( V_147 ) ;
else
V_11 = F_131 ( (struct V_149 * ) V_147 , struct V_11 , V_106 ) ;
F_123 ( V_11 -> V_141 , V_11 ) ;
}
static void F_132 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_146 * V_150 ;
if ( V_148 ) {
int V_25 = F_69 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_31 ( V_2 -> V_26 != sizeof( * V_150 ) ) ;
V_150 = F_12 ( V_11 ) + V_16 ;
} else {
V_150 = ( void * ) & V_11 -> V_106 ;
}
F_133 ( V_150 , F_129 ) ;
} else
F_123 ( V_2 , V_11 ) ;
}
static void F_134 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_96 ( V_2 , F_119 ( V_11 ) , V_11 -> V_14 ) ;
F_132 ( V_2 , V_11 ) ;
}
static inline void F_135 ( struct V_9 * V_37 ,
struct V_11 * V_11 , int V_151 )
{
V_37 -> V_152 ++ ;
if ( V_151 == V_153 )
F_136 ( & V_11 -> V_106 , & V_37 -> V_154 ) ;
else
F_87 ( & V_11 -> V_106 , & V_37 -> V_154 ) ;
}
static inline void F_137 ( struct V_9 * V_37 ,
struct V_11 * V_11 )
{
F_89 ( & V_11 -> V_106 ) ;
V_37 -> V_152 -- ;
}
static inline void * F_138 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 ,
int V_155 )
{
void * V_41 ;
unsigned long V_42 ;
struct V_11 V_156 ;
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_156 . V_42 = V_42 ;
if ( V_155 ) {
V_156 . V_24 = V_11 -> V_14 ;
V_156 . V_41 = NULL ;
} else {
V_156 . V_41 = V_41 ;
}
F_31 ( V_156 . V_143 ) ;
V_156 . V_143 = 1 ;
if ( ! F_30 ( V_2 , V_11 ,
V_41 , V_42 ,
V_156 . V_41 , V_156 . V_42 ,
L_47 ) )
return NULL ;
F_137 ( V_37 , V_11 ) ;
F_139 ( ! V_41 ) ;
return V_41 ;
}
static void * F_140 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_157 * V_158 , T_5 V_3 )
{
struct V_11 * V_11 , * V_159 ;
void * V_12 = NULL ;
if ( ! V_37 || ! V_37 -> V_152 )
return NULL ;
F_141 ( & V_37 -> V_160 ) ;
F_142 (page, page2, &n->partial, lru) {
void * V_71 ;
int V_161 ;
if ( ! F_143 ( V_11 , V_3 ) )
continue;
V_71 = F_138 ( V_2 , V_37 , V_11 , V_12 == NULL ) ;
if ( ! V_71 )
break;
if ( ! V_12 ) {
V_158 -> V_11 = V_11 ;
F_7 ( V_2 , V_162 ) ;
V_12 = V_71 ;
V_161 = V_11 -> V_14 - V_11 -> V_24 ;
} else {
V_161 = F_144 ( V_2 , V_11 , 0 ) ;
F_7 ( V_2 , V_163 ) ;
}
if ( F_1 ( V_2 ) || V_161 > V_2 -> V_164 / 2 )
break;
}
F_145 ( & V_37 -> V_160 ) ;
return V_12 ;
}
static void * F_146 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_157 * V_158 )
{
#ifdef F_147
struct V_165 * V_165 ;
struct V_166 * V_167 ;
struct V_168 * V_168 ;
enum V_169 V_170 = F_148 ( V_3 ) ;
void * V_12 ;
unsigned int V_171 ;
if ( ! V_2 -> V_172 ||
F_149 () % 1024 > V_2 -> V_172 )
return NULL ;
do {
V_171 = F_150 () ;
V_165 = F_151 ( F_152 () , V_3 ) ;
F_153 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_37 ;
V_37 = F_10 ( V_2 , F_154 ( V_168 ) ) ;
if ( V_37 && F_155 ( V_168 , V_3 ) &&
V_37 -> V_152 > V_2 -> V_173 ) {
V_12 = F_140 ( V_2 , V_37 , V_158 , V_3 ) ;
if ( V_12 ) {
F_156 ( V_171 ) ;
return V_12 ;
}
}
}
} while ( ! F_156 ( V_171 ) );
#endif
return NULL ;
}
static void * F_157 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_157 * V_158 )
{
void * V_12 ;
int V_174 = ( V_10 == V_123 ) ? F_158 () : V_10 ;
V_12 = F_140 ( V_2 , F_10 ( V_2 , V_174 ) , V_158 , V_3 ) ;
if ( V_12 || V_10 != V_123 )
return V_12 ;
return F_146 ( V_2 , V_3 , V_158 ) ;
}
static inline unsigned long F_159 ( unsigned long V_175 )
{
return V_175 + V_176 ;
}
static inline unsigned int F_160 ( unsigned long V_175 )
{
return V_175 % V_176 ;
}
static inline unsigned long F_161 ( unsigned long V_175 )
{
return V_175 / V_176 ;
}
static inline unsigned int F_162 ( int V_64 )
{
return V_64 ;
}
static inline void F_163 ( const char * V_37 ,
const struct V_1 * V_2 , unsigned long V_175 )
{
#ifdef F_36
unsigned long V_177 = F_164 ( V_2 -> V_8 -> V_175 ) ;
F_37 ( V_44 L_48 , V_37 , V_2 -> V_45 ) ;
#ifdef F_165
if ( F_160 ( V_175 ) != F_160 ( V_177 ) )
F_37 ( L_49 ,
F_160 ( V_175 ) , F_160 ( V_177 ) ) ;
else
#endif
if ( F_161 ( V_175 ) != F_161 ( V_177 ) )
F_37 ( L_50 ,
F_161 ( V_175 ) , F_161 ( V_177 ) ) ;
else
F_37 ( L_51 ,
V_177 , V_175 , F_159 ( V_175 ) ) ;
#endif
F_7 ( V_2 , V_178 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
int V_64 ;
F_167 (cpu)
F_168 ( V_2 -> V_8 , V_64 ) -> V_175 = F_162 ( V_64 ) ;
}
static void F_169 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_41 )
{
enum T_8 { V_179 , V_180 , V_181 , V_182 };
struct V_9 * V_37 = F_10 ( V_2 , F_119 ( V_11 ) ) ;
int V_183 = 0 ;
enum T_8 V_184 = V_179 , V_185 = V_179 ;
void * V_186 ;
int V_151 = V_187 ;
struct V_11 V_156 ;
struct V_11 V_188 ;
if ( V_11 -> V_41 ) {
F_7 ( V_2 , V_189 ) ;
V_151 = V_153 ;
}
while ( V_41 && ( V_186 = F_13 ( V_2 , V_41 ) ) ) {
void * V_190 ;
unsigned long V_42 ;
do {
V_190 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_19 ( V_2 , V_41 , V_190 ) ;
V_156 . V_42 = V_42 ;
V_156 . V_24 -- ;
F_31 ( ! V_156 . V_143 ) ;
} while ( ! F_30 ( V_2 , V_11 ,
V_190 , V_42 ,
V_41 , V_156 . V_42 ,
L_52 ) );
V_41 = V_186 ;
}
V_191:
V_188 . V_41 = V_11 -> V_41 ;
V_188 . V_42 = V_11 -> V_42 ;
F_31 ( ! V_188 . V_143 ) ;
V_156 . V_42 = V_188 . V_42 ;
if ( V_41 ) {
V_156 . V_24 -- ;
F_19 ( V_2 , V_41 , V_188 . V_41 ) ;
V_156 . V_41 = V_41 ;
} else
V_156 . V_41 = V_188 . V_41 ;
V_156 . V_143 = 0 ;
if ( ! V_156 . V_24 && V_37 -> V_152 > V_2 -> V_173 )
V_185 = V_182 ;
else if ( V_156 . V_41 ) {
V_185 = V_180 ;
if ( ! V_183 ) {
V_183 = 1 ;
F_141 ( & V_37 -> V_160 ) ;
}
} else {
V_185 = V_181 ;
if ( F_1 ( V_2 ) && ! V_183 ) {
V_183 = 1 ;
F_141 ( & V_37 -> V_160 ) ;
}
}
if ( V_184 != V_185 ) {
if ( V_184 == V_180 )
F_137 ( V_37 , V_11 ) ;
else if ( V_184 == V_181 )
F_88 ( V_2 , V_11 ) ;
if ( V_185 == V_180 ) {
F_135 ( V_37 , V_11 , V_151 ) ;
F_7 ( V_2 , V_151 ) ;
} else if ( V_185 == V_181 ) {
F_7 ( V_2 , V_192 ) ;
F_86 ( V_2 , V_37 , V_11 ) ;
}
}
V_184 = V_185 ;
if ( ! F_30 ( V_2 , V_11 ,
V_188 . V_41 , V_188 . V_42 ,
V_156 . V_41 , V_156 . V_42 ,
L_53 ) )
goto V_191;
if ( V_183 )
F_145 ( & V_37 -> V_160 ) ;
if ( V_185 == V_182 ) {
F_7 ( V_2 , V_193 ) ;
F_134 ( V_2 , V_11 ) ;
F_7 ( V_2 , V_194 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_9 * V_37 = NULL , * V_195 = NULL ;
struct V_157 * V_158 = F_171 ( V_2 -> V_8 ) ;
struct V_11 * V_11 , * V_196 = NULL ;
while ( ( V_11 = V_158 -> V_154 ) ) {
struct V_11 V_156 ;
struct V_11 V_188 ;
V_158 -> V_154 = V_11 -> V_197 ;
V_195 = F_10 ( V_2 , F_119 ( V_11 ) ) ;
if ( V_37 != V_195 ) {
if ( V_37 )
F_145 ( & V_37 -> V_160 ) ;
V_37 = V_195 ;
F_141 ( & V_37 -> V_160 ) ;
}
do {
V_188 . V_41 = V_11 -> V_41 ;
V_188 . V_42 = V_11 -> V_42 ;
F_31 ( ! V_188 . V_143 ) ;
V_156 . V_42 = V_188 . V_42 ;
V_156 . V_41 = V_188 . V_41 ;
V_156 . V_143 = 0 ;
} while ( ! F_30 ( V_2 , V_11 ,
V_188 . V_41 , V_188 . V_42 ,
V_156 . V_41 , V_156 . V_42 ,
L_53 ) );
if ( F_3 ( ! V_156 . V_24 && V_37 -> V_152 > V_2 -> V_173 ) ) {
V_11 -> V_197 = V_196 ;
V_196 = V_11 ;
} else {
F_135 ( V_37 , V_11 , V_153 ) ;
F_7 ( V_2 , V_198 ) ;
}
}
if ( V_37 )
F_145 ( & V_37 -> V_160 ) ;
while ( V_196 ) {
V_11 = V_196 ;
V_196 = V_196 -> V_197 ;
F_7 ( V_2 , V_193 ) ;
F_134 ( V_2 , V_11 ) ;
F_7 ( V_2 , V_194 ) ;
}
}
static int F_144 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_199 )
{
struct V_11 * V_200 ;
int V_133 ;
int V_201 ;
do {
V_133 = 0 ;
V_201 = 0 ;
V_200 = F_172 ( V_2 -> V_8 -> V_154 ) ;
if ( V_200 ) {
V_201 = V_200 -> V_201 ;
V_133 = V_200 -> V_133 ;
if ( V_199 && V_201 > V_2 -> V_164 ) {
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_170 ( V_2 ) ;
F_40 ( V_3 ) ;
V_200 = NULL ;
V_201 = 0 ;
V_133 = 0 ;
F_7 ( V_2 , V_202 ) ;
}
}
V_133 ++ ;
V_201 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_133 = V_133 ;
V_11 -> V_201 = V_201 ;
V_11 -> V_197 = V_200 ;
} while ( F_173 ( V_2 -> V_8 -> V_154 , V_200 , V_11 ) != V_200 );
return V_201 ;
}
static inline void F_174 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
F_7 ( V_2 , V_203 ) ;
F_169 ( V_2 , V_158 -> V_11 , V_158 -> V_41 ) ;
V_158 -> V_175 = F_159 ( V_158 -> V_175 ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
}
static inline void F_175 ( struct V_1 * V_2 , int V_64 )
{
struct V_157 * V_158 = F_168 ( V_2 -> V_8 , V_64 ) ;
if ( F_176 ( V_158 ) ) {
if ( V_158 -> V_11 )
F_174 ( V_2 , V_158 ) ;
F_170 ( V_2 ) ;
}
}
static void F_177 ( void * V_204 )
{
struct V_1 * V_2 = V_204 ;
F_175 ( V_2 , F_49 () ) ;
}
static bool F_178 ( int V_64 , void * V_205 )
{
struct V_1 * V_2 = V_205 ;
struct V_157 * V_158 = F_168 ( V_2 -> V_8 , V_64 ) ;
return V_158 -> V_11 || V_158 -> V_154 ;
}
static void F_179 ( struct V_1 * V_2 )
{
F_180 ( F_178 , F_177 , V_2 , 1 , V_206 ) ;
}
static inline int F_181 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_147
if ( V_10 != V_123 && F_119 ( V_11 ) != V_10 )
return 0 ;
#endif
return 1 ;
}
static int F_182 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static unsigned long F_183 ( struct V_9 * V_37 ,
int (* F_184)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_185 ( & V_37 -> V_160 , V_3 ) ;
F_186 (page, &n->partial, lru)
V_29 += F_184 ( V_11 ) ;
F_187 ( & V_37 -> V_160 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_188 ( struct V_9 * V_37 )
{
#ifdef F_2
return F_91 ( & V_37 -> V_109 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_189 ( struct V_1 * V_2 , T_5 V_207 , int V_208 )
{
int V_10 ;
F_37 ( V_209
L_54 ,
V_208 , V_207 ) ;
F_37 ( V_209 L_55
L_56 , V_2 -> V_45 , V_2 -> V_21 ,
V_2 -> V_15 , F_24 ( V_2 -> V_121 ) , F_24 ( V_2 -> V_129 ) ) ;
if ( F_24 ( V_2 -> V_129 ) > F_190 ( V_2 -> V_21 ) )
F_37 ( V_209 L_57
L_58 , V_2 -> V_45 ) ;
F_191 (node) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
unsigned long V_108 ;
unsigned long V_210 ;
unsigned long V_211 ;
if ( ! V_37 )
continue;
V_211 = F_183 ( V_37 , F_182 ) ;
V_108 = F_92 ( V_37 ) ;
V_210 = F_188 ( V_37 ) ;
F_37 ( V_209
L_59 ,
V_10 , V_108 , V_210 , V_211 ) ;
}
}
static inline void * F_192 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_157 * * V_212 )
{
void * V_41 ;
struct V_157 * V_158 = * V_212 ;
struct V_11 * V_11 ;
V_41 = F_157 ( V_2 , V_3 , V_10 , V_158 ) ;
if ( V_41 )
return V_41 ;
V_11 = F_117 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_158 = F_193 ( V_2 -> V_8 ) ;
if ( V_158 -> V_11 )
F_174 ( V_2 , V_158 ) ;
V_41 = V_11 -> V_41 ;
V_11 -> V_41 = NULL ;
F_7 ( V_2 , V_213 ) ;
V_158 -> V_11 = V_11 ;
* V_212 = V_158 ;
} else
V_41 = NULL ;
return V_41 ;
}
static inline bool F_143 ( struct V_11 * V_11 , T_5 V_207 )
{
if ( F_3 ( F_194 ( V_11 ) ) )
return F_195 ( V_207 ) ;
return true ;
}
static inline void * F_196 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_156 ;
unsigned long V_42 ;
void * V_41 ;
do {
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_156 . V_42 = V_42 ;
F_31 ( ! V_156 . V_143 ) ;
V_156 . V_24 = V_11 -> V_14 ;
V_156 . V_143 = V_41 != NULL ;
} while ( ! F_30 ( V_2 , V_11 ,
V_41 , V_42 ,
NULL , V_156 . V_42 ,
L_60 ) );
return V_41 ;
}
static void * F_197 ( struct V_1 * V_2 , T_5 V_207 , int V_10 ,
unsigned long V_18 , struct V_157 * V_158 )
{
void * V_41 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_39 ( V_3 ) ;
#ifdef F_165
V_158 = F_171 ( V_2 -> V_8 ) ;
#endif
V_11 = V_158 -> V_11 ;
if ( ! V_11 )
goto F_117;
V_191:
if ( F_3 ( ! F_181 ( V_11 , V_10 ) ) ) {
F_7 ( V_2 , V_214 ) ;
F_169 ( V_2 , V_11 , V_158 -> V_41 ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
goto F_117;
}
if ( F_3 ( ! F_143 ( V_11 , V_207 ) ) ) {
F_169 ( V_2 , V_11 , V_158 -> V_41 ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
goto F_117;
}
V_41 = V_158 -> V_41 ;
if ( V_41 )
goto V_215;
F_7 ( V_2 , V_216 ) ;
V_41 = F_196 ( V_2 , V_11 ) ;
if ( ! V_41 ) {
V_158 -> V_11 = NULL ;
F_7 ( V_2 , V_217 ) ;
goto F_117;
}
F_7 ( V_2 , V_218 ) ;
V_215:
F_31 ( ! V_158 -> V_11 -> V_143 ) ;
V_158 -> V_41 = F_13 ( V_2 , V_41 ) ;
V_158 -> V_175 = F_159 ( V_158 -> V_175 ) ;
F_40 ( V_3 ) ;
return V_41 ;
F_117:
if ( V_158 -> V_154 ) {
V_11 = V_158 -> V_11 = V_158 -> V_154 ;
V_158 -> V_154 = V_11 -> V_197 ;
F_7 ( V_2 , V_219 ) ;
V_158 -> V_41 = NULL ;
goto V_191;
}
V_41 = F_192 ( V_2 , V_207 , V_10 , & V_158 ) ;
if ( F_3 ( ! V_41 ) ) {
if ( ! ( V_207 & V_126 ) && F_198 () )
F_189 ( V_2 , V_207 , V_10 ) ;
F_40 ( V_3 ) ;
return NULL ;
}
V_11 = V_158 -> V_11 ;
if ( F_176 ( ! F_1 ( V_2 ) && F_143 ( V_11 , V_207 ) ) )
goto V_215;
if ( F_1 ( V_2 ) && ! F_100 ( V_2 , V_11 , V_41 , V_18 ) )
goto F_117;
F_169 ( V_2 , V_11 , F_13 ( V_2 , V_41 ) ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
F_40 ( V_3 ) ;
return V_41 ;
}
static T_2 void * F_199 ( struct V_1 * V_2 ,
T_5 V_207 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_157 * V_158 ;
struct V_11 * V_11 ;
unsigned long V_175 ;
if ( F_74 ( V_2 , V_207 ) )
return NULL ;
V_191:
V_158 = F_193 ( V_2 -> V_8 ) ;
V_175 = V_158 -> V_175 ;
F_200 () ;
V_12 = V_158 -> V_41 ;
V_11 = V_158 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_181 ( V_11 , V_10 ) ) )
V_12 = F_197 ( V_2 , V_207 , V_10 , V_18 , V_158 ) ;
else {
void * V_220 = F_16 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_201 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_175 ,
V_12 , V_175 ,
V_220 , F_159 ( V_175 ) ) ) ) {
F_163 ( L_61 , V_2 , V_175 ) ;
goto V_191;
}
F_14 ( V_2 , V_220 ) ;
F_7 ( V_2 , V_221 ) ;
}
if ( F_3 ( V_207 & V_222 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_78 ( V_2 , V_207 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_202 ( struct V_1 * V_2 ,
T_5 V_207 , unsigned long V_18 )
{
return F_199 ( V_2 , V_207 , V_123 , V_18 ) ;
}
void * F_203 ( struct V_1 * V_2 , T_5 V_207 )
{
void * V_223 = F_202 ( V_2 , V_207 , V_224 ) ;
F_204 ( V_224 , V_223 , V_2 -> V_21 , V_2 -> V_15 , V_207 ) ;
return V_223 ;
}
void * F_205 ( struct V_1 * V_2 , T_5 V_207 , T_1 V_15 )
{
void * V_223 = F_202 ( V_2 , V_207 , V_224 ) ;
F_206 ( V_224 , V_223 , V_15 , V_2 -> V_15 , V_207 ) ;
return V_223 ;
}
void * F_207 ( T_1 V_15 , T_5 V_3 , unsigned int V_25 )
{
void * V_223 = F_208 ( V_15 , V_3 , V_25 ) ;
F_206 ( V_224 , V_223 , V_15 , V_27 << V_25 , V_3 ) ;
return V_223 ;
}
void * F_209 ( struct V_1 * V_2 , T_5 V_207 , int V_10 )
{
void * V_223 = F_199 ( V_2 , V_207 , V_10 , V_224 ) ;
F_210 ( V_224 , V_223 ,
V_2 -> V_21 , V_2 -> V_15 , V_207 , V_10 ) ;
return V_223 ;
}
void * F_211 ( struct V_1 * V_2 ,
T_5 V_207 ,
int V_10 , T_1 V_15 )
{
void * V_223 = F_199 ( V_2 , V_207 , V_10 , V_224 ) ;
F_212 ( V_224 , V_223 ,
V_15 , V_2 -> V_15 , V_207 , V_10 ) ;
return V_223 ;
}
static void F_213 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_190 ;
void * * V_12 = ( void * ) V_29 ;
int V_225 ;
int V_24 ;
struct V_11 V_156 ;
unsigned long V_42 ;
struct V_9 * V_37 = NULL ;
unsigned long V_226 ( V_3 ) ;
F_7 ( V_2 , V_227 ) ;
if ( F_1 ( V_2 ) &&
! ( V_37 = F_104 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
V_190 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_19 ( V_2 , V_12 , V_190 ) ;
V_156 . V_42 = V_42 ;
V_225 = V_156 . V_143 ;
V_156 . V_24 -- ;
if ( ( ! V_156 . V_24 || ! V_190 ) && ! V_225 && ! V_37 ) {
if ( ! F_1 ( V_2 ) && ! V_190 )
V_156 . V_143 = 1 ;
else {
V_37 = F_10 ( V_2 , F_119 ( V_11 ) ) ;
F_185 ( & V_37 -> V_160 , V_3 ) ;
}
}
V_24 = V_156 . V_24 ;
} while ( ! F_38 ( V_2 , V_11 ,
V_190 , V_42 ,
V_12 , V_156 . V_42 ,
L_62 ) );
if ( F_176 ( ! V_37 ) ) {
if ( V_156 . V_143 && ! V_225 ) {
F_144 ( V_2 , V_11 , 1 ) ;
F_7 ( V_2 , V_228 ) ;
}
if ( V_225 )
F_7 ( V_2 , V_229 ) ;
return;
}
if ( V_225 )
F_7 ( V_2 , V_229 ) ;
else {
if ( F_3 ( ! V_24 && V_37 -> V_152 > V_2 -> V_173 ) )
goto V_230;
if ( F_3 ( ! V_190 ) ) {
F_88 ( V_2 , V_11 ) ;
F_135 ( V_37 , V_11 , V_153 ) ;
F_7 ( V_2 , V_198 ) ;
}
}
F_187 ( & V_37 -> V_160 , V_3 ) ;
return;
V_230:
if ( V_190 ) {
F_137 ( V_37 , V_11 ) ;
F_7 ( V_2 , V_231 ) ;
} else
F_88 ( V_2 , V_11 ) ;
F_187 ( & V_37 -> V_160 , V_3 ) ;
F_7 ( V_2 , V_194 ) ;
F_134 ( V_2 , V_11 ) ;
}
static T_2 void F_214 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_157 * V_158 ;
unsigned long V_175 ;
F_81 ( V_2 , V_29 ) ;
V_191:
V_158 = F_193 ( V_2 -> V_8 ) ;
V_175 = V_158 -> V_175 ;
F_200 () ;
if ( F_176 ( V_11 == V_158 -> V_11 ) ) {
F_19 ( V_2 , V_12 , V_158 -> V_41 ) ;
if ( F_3 ( ! F_201 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_175 ,
V_158 -> V_41 , V_175 ,
V_12 , F_159 ( V_175 ) ) ) ) {
F_163 ( L_63 , V_2 , V_175 ) ;
goto V_191;
}
F_7 ( V_2 , V_232 ) ;
} else
F_213 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_215 ( struct V_1 * V_2 , void * V_29 )
{
struct V_11 * V_11 ;
V_11 = F_130 ( V_29 ) ;
if ( F_1 ( V_2 ) && V_11 -> V_141 != V_2 ) {
F_216 ( L_64
L_65 , V_11 -> V_141 -> V_45 , V_2 -> V_45 ) ;
F_217 ( 1 ) ;
return;
}
F_214 ( V_2 , V_11 , V_29 , V_224 ) ;
F_218 ( V_224 , V_29 ) ;
}
static inline int F_219 ( int V_15 , int V_233 ,
int V_234 , int V_235 , int V_26 )
{
int V_25 ;
int V_236 ;
int V_237 = V_238 ;
if ( F_22 ( V_237 , V_15 , V_26 ) > V_99 )
return F_190 ( V_15 * V_99 ) - 1 ;
for ( V_25 = F_220 ( V_237 ,
F_221 ( V_233 * V_15 - 1 ) - V_239 ) ;
V_25 <= V_234 ; V_25 ++ ) {
unsigned long V_240 = V_27 << V_25 ;
if ( V_240 < V_233 * V_15 + V_26 )
continue;
V_236 = ( V_240 - V_26 ) % V_15 ;
if ( V_236 <= V_240 / V_235 )
break;
}
return V_25 ;
}
static inline int F_222 ( int V_15 , int V_26 )
{
int V_25 ;
int V_233 ;
int V_241 ;
int V_98 ;
V_233 = V_242 ;
if ( ! V_233 )
V_233 = 4 * ( F_221 ( V_243 ) + 1 ) ;
V_98 = F_22 ( V_244 , V_15 , V_26 ) ;
V_233 = V_129 ( V_233 , V_98 ) ;
while ( V_233 > 1 ) {
V_241 = 16 ;
while ( V_241 >= 4 ) {
V_25 = F_219 ( V_15 , V_233 ,
V_244 , V_241 , V_26 ) ;
if ( V_25 <= V_244 )
return V_25 ;
V_241 /= 2 ;
}
V_233 -- ;
}
V_25 = F_219 ( V_15 , 1 , V_244 , 1 , V_26 ) ;
if ( V_25 <= V_244 )
return V_25 ;
V_25 = F_219 ( V_15 , 1 , V_245 , 1 , V_26 ) ;
if ( V_25 < V_245 )
return V_25 ;
return - V_246 ;
}
static unsigned long F_223 ( unsigned long V_3 ,
unsigned long V_247 , unsigned long V_15 )
{
if ( V_3 & V_248 ) {
unsigned long V_249 = F_224 () ;
while ( V_15 <= V_249 / 2 )
V_249 /= 2 ;
V_247 = F_220 ( V_247 , V_249 ) ;
}
if ( V_247 < V_250 )
V_247 = V_250 ;
return F_225 ( V_247 , sizeof( void * ) ) ;
}
static void
F_226 ( struct V_9 * V_37 )
{
V_37 -> V_152 = 0 ;
F_227 ( & V_37 -> V_160 ) ;
F_228 ( & V_37 -> V_154 ) ;
#ifdef F_2
F_229 ( & V_37 -> V_108 , 0 ) ;
F_229 ( & V_37 -> V_109 , 0 ) ;
F_228 ( & V_37 -> V_107 ) ;
#endif
}
static inline int F_230 ( struct V_1 * V_2 )
{
F_231 ( V_251 <
V_252 * sizeof( struct V_157 ) ) ;
V_2 -> V_8 = F_232 ( sizeof( struct V_157 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_166 ( V_2 ) ;
return 1 ;
}
static void F_233 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_37 ;
F_118 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_117 ( V_9 , V_253 , V_10 ) ;
F_118 ( ! V_11 ) ;
if ( F_119 ( V_11 ) != V_10 ) {
F_37 ( V_49 L_66
L_67 , V_10 ) ;
F_37 ( V_49 L_68
L_69 ) ;
}
V_37 = V_11 -> V_41 ;
F_118 ( ! V_37 ) ;
V_11 -> V_41 = F_13 ( V_9 , V_37 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_143 = 0 ;
V_9 -> V_10 [ V_10 ] = V_37 ;
#ifdef F_2
F_63 ( V_9 , V_37 , V_94 ) ;
F_50 ( V_9 , V_37 ) ;
#endif
F_226 ( V_37 ) ;
F_93 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_135 ( V_37 , V_11 , V_187 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
int V_10 ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = V_2 -> V_10 [ V_10 ] ;
if ( V_37 )
F_215 ( V_9 , V_37 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_236 ( struct V_1 * V_2 )
{
int V_10 ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 ;
if ( V_254 == V_255 ) {
F_233 ( V_10 ) ;
continue;
}
V_37 = F_209 ( V_9 ,
V_256 , V_10 ) ;
if ( ! V_37 ) {
F_234 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_37 ;
F_226 ( V_37 ) ;
}
return 1 ;
}
static void F_237 ( struct V_1 * V_2 , unsigned long V_129 )
{
if ( V_129 < V_257 )
V_129 = V_257 ;
else if ( V_129 > V_258 )
V_129 = V_258 ;
V_2 -> V_173 = V_129 ;
}
static int F_238 ( struct V_1 * V_2 , int V_259 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
unsigned long V_247 = V_2 -> V_247 ;
int V_25 ;
V_15 = F_225 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_103 )
V_2 -> V_3 |= V_78 ;
else
V_2 -> V_3 &= ~ V_78 ;
if ( ( V_3 & V_19 ) && V_15 == V_2 -> V_21 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_24 = V_15 ;
if ( ( ( V_3 & ( V_22 | V_20 ) ) ||
V_2 -> F_103 ) ) {
V_2 -> V_16 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_23 )
V_15 += 2 * sizeof( struct V_51 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_247 = F_223 ( V_3 , V_247 , V_2 -> V_21 ) ;
V_2 -> V_247 = V_247 ;
V_15 = F_225 ( V_15 , V_247 ) ;
V_2 -> V_15 = V_15 ;
if ( V_259 >= 0 )
V_25 = V_259 ;
else
V_25 = F_222 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_125 = 0 ;
if ( V_25 )
V_2 -> V_125 |= V_260 ;
if ( V_2 -> V_3 & V_261 )
V_2 -> V_125 |= V_262 ;
if ( V_2 -> V_3 & V_134 )
V_2 -> V_125 |= V_263 ;
V_2 -> V_121 = F_23 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_129 = F_23 ( F_190 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_25 ( V_2 -> V_121 ) > F_25 ( V_2 -> F_220 ) )
V_2 -> F_220 = V_2 -> V_121 ;
return ! ! F_25 ( V_2 -> V_121 ) ;
}
static int F_239 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_102 ( V_2 -> V_15 , V_3 , V_2 -> V_45 , V_2 -> F_103 ) ;
V_2 -> V_26 = 0 ;
if ( V_148 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_146 ) ;
if ( ! F_238 ( V_2 , - 1 ) )
goto error;
if ( V_117 ) {
if ( F_190 ( V_2 -> V_15 ) > F_190 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_264 ;
V_2 -> V_16 = 0 ;
if ( ! F_238 ( V_2 , - 1 ) )
goto error;
}
}
#if F_33 ( V_38 ) && \
F_33 ( V_39 )
if ( F_240 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_40 ;
#endif
F_237 ( V_2 , F_241 ( V_2 -> V_15 ) / 2 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_164 = 0 ;
else if ( V_2 -> V_15 >= V_27 )
V_2 -> V_164 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_164 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_164 = 13 ;
else
V_2 -> V_164 = 30 ;
#ifdef F_147
V_2 -> V_172 = 1000 ;
#endif
if ( ! F_236 ( V_2 ) )
goto error;
if ( F_230 ( V_2 ) )
return 0 ;
F_234 ( V_2 ) ;
error:
if ( V_3 & V_265 )
F_242 ( L_70
L_71 ,
V_2 -> V_45 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 , F_24 ( V_2 -> V_121 ) ,
V_2 -> V_16 , V_3 ) ;
return - V_266 ;
}
unsigned int F_243 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ;
}
static void F_244 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_47 )
{
#ifdef F_2
void * V_18 = F_12 ( V_11 ) ;
void * V_5 ;
unsigned long * V_46 = F_245 ( F_246 ( V_11 -> V_14 ) *
sizeof( long ) , V_206 ) ;
if ( ! V_46 )
return;
F_62 ( V_2 , V_11 , V_47 , V_2 -> V_45 ) ;
F_26 ( V_11 ) ;
F_41 ( V_2 , V_11 , V_46 ) ;
F_122 (p, s, addr, page->objects) {
if ( ! F_247 ( F_20 ( V_5 , V_2 , V_18 ) , V_46 ) ) {
F_37 ( V_49 L_72 ,
V_5 , V_5 - V_18 ) ;
F_52 ( V_2 , V_5 ) ;
}
}
F_28 ( V_11 ) ;
F_248 ( V_46 ) ;
#endif
}
static void F_249 ( struct V_1 * V_2 , struct V_9 * V_37 )
{
struct V_11 * V_11 , * V_147 ;
F_142 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_137 ( V_37 , V_11 ) ;
F_134 ( V_2 , V_11 ) ;
} else {
F_244 ( V_2 , V_11 ,
L_73 ) ;
}
}
}
static inline int F_250 ( struct V_1 * V_2 )
{
int V_10 ;
F_179 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
F_249 ( V_2 , V_37 ) ;
if ( V_37 -> V_152 || F_90 ( V_2 , V_10 ) )
return 1 ;
}
F_251 ( V_2 -> V_8 ) ;
F_234 ( V_2 ) ;
return 0 ;
}
int F_252 ( struct V_1 * V_2 )
{
int V_267 = F_250 ( V_2 ) ;
if ( ! V_267 )
F_6 ( V_2 ) ;
return V_267 ;
}
static int T_7 F_253 ( char * V_112 )
{
F_254 ( & V_112 , & V_238 ) ;
return 1 ;
}
static int T_7 F_255 ( char * V_112 )
{
F_254 ( & V_112 , & V_244 ) ;
V_244 = V_129 ( V_244 , V_245 - 1 ) ;
return 1 ;
}
static int T_7 F_256 ( char * V_112 )
{
F_254 ( & V_112 , & V_242 ) ;
return 1 ;
}
static int T_7 F_257 ( char * V_112 )
{
V_268 = 1 ;
return 1 ;
}
static struct V_1 * T_7 F_258 ( const char * V_45 ,
int V_15 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_259 ( V_1 , V_253 ) ;
V_2 -> V_45 = V_45 ;
V_2 -> V_15 = V_2 -> V_21 = V_15 ;
V_2 -> V_247 = V_269 ;
if ( F_239 ( V_2 , V_3 ) )
goto F_242;
F_87 ( & V_2 -> V_270 , & V_271 ) ;
return V_2 ;
F_242:
F_242 ( L_74 , V_45 , V_15 ) ;
return NULL ;
}
static inline int F_260 ( T_1 V_88 )
{
return ( V_88 - 1 ) / 8 ;
}
static struct V_1 * F_261 ( T_1 V_15 , T_5 V_3 )
{
int V_272 ;
if ( V_15 <= 192 ) {
if ( ! V_15 )
return V_273 ;
V_272 = V_274 [ F_260 ( V_15 ) ] ;
} else
V_272 = F_221 ( V_15 - 1 ) ;
#ifdef F_262
if ( F_3 ( ( V_3 & V_262 ) ) )
return V_275 [ V_272 ] ;
#endif
return V_276 [ V_272 ] ;
}
void * F_263 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_277 ) )
return F_264 ( V_15 , V_3 ) ;
V_2 = F_261 ( V_15 , V_3 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_202 ( V_2 , V_3 , V_224 ) ;
F_206 ( V_224 , V_223 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_223 ;
}
static void * F_266 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_278 = NULL ;
V_3 |= V_260 | V_122 ;
V_11 = F_267 ( V_10 , V_3 , F_190 ( V_15 ) ) ;
if ( V_11 )
V_278 = F_12 ( V_11 ) ;
F_268 ( V_278 , V_15 , 1 , V_3 ) ;
return V_278 ;
}
void * F_269 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_277 ) ) {
V_223 = F_266 ( V_15 , V_3 , V_10 ) ;
F_212 ( V_224 , V_223 ,
V_15 , V_27 << F_190 ( V_15 ) ,
V_3 , V_10 ) ;
return V_223 ;
}
V_2 = F_261 ( V_15 , V_3 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_199 ( V_2 , V_3 , V_10 , V_224 ) ;
F_212 ( V_224 , V_223 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_223 ;
}
T_1 F_270 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_273 ) )
return 0 ;
V_11 = F_130 ( V_12 ) ;
if ( F_3 ( ! F_72 ( V_11 ) ) ) {
F_139 ( ! F_271 ( V_11 ) ) ;
return V_27 << F_69 ( V_11 ) ;
}
return F_21 ( V_11 -> V_141 ) ;
}
bool F_272 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
unsigned long V_3 ;
bool V_279 ;
if ( F_3 ( F_265 ( V_29 ) ) )
return false ;
F_39 ( V_3 ) ;
V_11 = F_130 ( V_29 ) ;
if ( F_3 ( ! F_72 ( V_11 ) ) ) {
V_279 = true ;
goto V_280;
}
F_26 ( V_11 ) ;
if ( F_73 ( V_11 -> V_141 , V_11 , V_12 ) ) {
F_61 ( V_11 -> V_141 , V_11 , V_12 , L_75 ) ;
V_279 = false ;
} else {
V_279 = true ;
}
F_28 ( V_11 ) ;
V_280:
F_40 ( V_3 ) ;
return V_279 ;
}
void F_248 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_273 ( V_224 , V_29 ) ;
if ( F_3 ( F_265 ( V_29 ) ) )
return;
V_11 = F_130 ( V_29 ) ;
if ( F_3 ( ! F_72 ( V_11 ) ) ) {
F_118 ( ! F_271 ( V_11 ) ) ;
F_274 ( V_29 ) ;
F_128 ( V_11 , F_69 ( V_11 ) ) ;
return;
}
F_214 ( V_11 -> V_141 , V_11 , V_12 , V_224 ) ;
}
int F_275 ( struct V_1 * V_2 )
{
int V_10 ;
int V_56 ;
struct V_9 * V_37 ;
struct V_11 * V_11 ;
struct V_11 * V_71 ;
int V_14 = F_25 ( V_2 -> F_220 ) ;
struct V_149 * V_281 =
F_276 ( sizeof( struct V_149 ) * V_14 , V_256 ) ;
unsigned long V_3 ;
if ( ! V_281 )
return - V_282 ;
F_179 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
V_37 = F_10 ( V_2 , V_10 ) ;
if ( ! V_37 -> V_152 )
continue;
for ( V_56 = 0 ; V_56 < V_14 ; V_56 ++ )
F_228 ( V_281 + V_56 ) ;
F_185 ( & V_37 -> V_160 , V_3 ) ;
F_142 (page, t, &n->partial, lru) {
F_277 ( & V_11 -> V_106 , V_281 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_37 -> V_152 -- ;
}
for ( V_56 = V_14 - 1 ; V_56 > 0 ; V_56 -- )
F_278 ( V_281 + V_56 , V_37 -> V_154 . V_283 ) ;
F_187 ( & V_37 -> V_160 , V_3 ) ;
F_142 (page, t, slabs_by_inuse, lru)
F_134 ( V_2 , V_11 ) ;
}
F_248 ( V_281 ) ;
return 0 ;
}
static int F_279 ( void * V_284 )
{
struct V_1 * V_2 ;
F_280 ( & V_285 ) ;
F_186 (s, &slab_caches, list)
F_275 ( V_2 ) ;
F_281 ( & V_285 ) ;
return 0 ;
}
static void F_282 ( void * V_284 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_286 * V_287 = V_284 ;
int V_288 ;
V_288 = V_287 -> V_289 ;
if ( V_288 < 0 )
return;
F_280 ( & V_285 ) ;
F_186 (s, &slab_caches, list) {
V_37 = F_10 ( V_2 , V_288 ) ;
if ( V_37 ) {
F_118 ( F_90 ( V_2 , V_288 ) ) ;
V_2 -> V_10 [ V_288 ] = NULL ;
F_215 ( V_9 , V_37 ) ;
}
}
F_281 ( & V_285 ) ;
}
static int F_283 ( void * V_284 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_286 * V_287 = V_284 ;
int V_208 = V_287 -> V_289 ;
int V_223 = 0 ;
if ( V_208 < 0 )
return 0 ;
F_280 ( & V_285 ) ;
F_186 (s, &slab_caches, list) {
V_37 = F_203 ( V_9 , V_256 ) ;
if ( ! V_37 ) {
V_223 = - V_282 ;
goto V_115;
}
F_226 ( V_37 ) ;
V_2 -> V_10 [ V_208 ] = V_37 ;
}
V_115:
F_281 ( & V_285 ) ;
return V_223 ;
}
static int F_284 ( struct V_290 * V_291 ,
unsigned long V_292 , void * V_284 )
{
int V_223 = 0 ;
switch ( V_292 ) {
case V_293 :
V_223 = F_283 ( V_284 ) ;
break;
case V_294 :
V_223 = F_279 ( V_284 ) ;
break;
case V_295 :
case V_296 :
F_282 ( V_284 ) ;
break;
case V_297 :
case V_298 :
break;
}
if ( V_223 )
V_223 = F_285 ( V_223 ) ;
else
V_223 = V_299 ;
return V_223 ;
}
static void T_7 F_286 ( struct V_1 * V_2 )
{
int V_10 ;
F_87 ( & V_2 -> V_270 , & V_271 ) ;
V_2 -> V_300 = - 1 ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_37 ) {
F_186 (p, &n->partial, lru)
V_5 -> V_141 = V_2 ;
#ifdef F_2
F_186 (p, &n->full, lru)
V_5 -> V_141 = V_2 ;
#endif
}
}
}
void T_7 F_287 ( void )
{
int V_56 ;
int V_301 = 0 ;
struct V_1 * V_302 ;
int V_25 ;
struct V_1 * V_303 ;
unsigned long V_304 ;
if ( F_288 () )
V_244 = 0 ;
V_305 = F_289 ( struct V_1 , V_10 ) +
V_306 * sizeof( struct V_9 * ) ;
V_304 = F_225 ( V_305 , F_224 () ) ;
V_25 = F_190 ( 2 * V_304 ) ;
V_1 = ( void * ) F_290 ( V_253 | V_222 , V_25 ) ;
V_9 = ( void * ) V_1 + V_304 ;
V_9 -> V_45 = L_76 ;
V_9 -> V_15 = V_9 -> V_21 =
sizeof( struct V_9 ) ;
F_239 ( V_9 , V_248 | V_265 ) ;
F_291 ( F_284 , V_307 ) ;
V_254 = V_308 ;
V_302 = V_1 ;
V_1 -> V_45 = L_77 ;
V_1 -> V_15 = V_1 -> V_21 = V_305 ;
F_239 ( V_1 , V_248 | V_265 ) ;
V_1 = F_203 ( V_1 , V_253 ) ;
memcpy ( V_1 , V_302 , V_305 ) ;
V_303 = V_9 ;
V_9 = F_203 ( V_1 , V_253 ) ;
memcpy ( V_9 , V_303 , V_305 ) ;
F_286 ( V_9 ) ;
V_301 ++ ;
F_286 ( V_1 ) ;
V_301 ++ ;
F_292 ( ( unsigned long ) V_302 , V_25 ) ;
F_231 ( V_309 > 256 ||
( V_309 & ( V_309 - 1 ) ) ) ;
for ( V_56 = 8 ; V_56 < V_309 ; V_56 += 8 ) {
int V_310 = F_260 ( V_56 ) ;
if ( V_310 >= F_293 ( V_274 ) )
break;
V_274 [ V_310 ] = V_311 ;
}
if ( V_309 == 64 ) {
for ( V_56 = 64 + 8 ; V_56 <= 96 ; V_56 += 8 )
V_274 [ F_260 ( V_56 ) ] = 7 ;
} else if ( V_309 == 128 ) {
for ( V_56 = 128 + 8 ; V_56 <= 192 ; V_56 += 8 )
V_274 [ F_260 ( V_56 ) ] = 8 ;
}
if ( V_309 <= 32 ) {
V_276 [ 1 ] = F_258 ( L_78 , 96 , 0 ) ;
V_301 ++ ;
}
if ( V_309 <= 64 ) {
V_276 [ 2 ] = F_258 ( L_79 , 192 , 0 ) ;
V_301 ++ ;
}
for ( V_56 = V_311 ; V_56 < V_252 ; V_56 ++ ) {
V_276 [ V_56 ] = F_258 ( L_80 , 1 << V_56 , 0 ) ;
V_301 ++ ;
}
V_254 = V_312 ;
if ( V_309 <= 32 ) {
V_276 [ 1 ] -> V_45 = F_294 ( V_276 [ 1 ] -> V_45 , V_253 ) ;
F_118 ( ! V_276 [ 1 ] -> V_45 ) ;
}
if ( V_309 <= 64 ) {
V_276 [ 2 ] -> V_45 = F_294 ( V_276 [ 2 ] -> V_45 , V_253 ) ;
F_118 ( ! V_276 [ 2 ] -> V_45 ) ;
}
for ( V_56 = V_311 ; V_56 < V_252 ; V_56 ++ ) {
char * V_2 = F_295 ( V_253 , L_81 , 1 << V_56 ) ;
F_118 ( ! V_2 ) ;
V_276 [ V_56 ] -> V_45 = V_2 ;
}
#ifdef F_296
F_297 ( & V_313 ) ;
#endif
#ifdef F_262
for ( V_56 = 0 ; V_56 < V_252 ; V_56 ++ ) {
struct V_1 * V_2 = V_276 [ V_56 ] ;
if ( V_2 && V_2 -> V_15 ) {
char * V_45 = F_295 ( V_253 ,
L_82 , V_2 -> V_21 ) ;
F_118 ( ! V_45 ) ;
V_275 [ V_56 ] = F_258 ( V_45 ,
V_2 -> V_21 , V_261 ) ;
}
}
#endif
F_37 ( V_44
L_83
L_84 ,
V_301 , F_224 () ,
V_238 , V_244 , V_242 ,
V_243 , V_306 ) ;
}
void T_7 F_298 ( void )
{
}
static int F_299 ( struct V_1 * V_2 )
{
if ( V_268 || ( V_2 -> V_3 & V_314 ) )
return 1 ;
if ( V_2 -> F_103 )
return 1 ;
if ( V_2 -> V_300 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_300 ( T_1 V_15 ,
T_1 V_247 , unsigned long V_3 , const char * V_45 ,
void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
if ( V_268 || ( V_3 & V_314 ) )
return NULL ;
if ( F_103 )
return NULL ;
V_15 = F_225 ( V_15 , sizeof( void * ) ) ;
V_247 = F_223 ( V_3 , V_247 , V_15 ) ;
V_15 = F_225 ( V_15 , V_247 ) ;
V_3 = F_102 ( V_15 , V_3 , V_45 , NULL ) ;
F_186 (s, &slab_caches, list) {
if ( F_299 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_315 ) != ( V_2 -> V_3 & V_315 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_247 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_301 ( const char * V_45 , T_1 V_15 ,
T_1 V_247 , unsigned long V_3 , void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_300 ( V_15 , V_247 , V_3 , V_45 , F_103 ) ;
if ( V_2 ) {
V_2 -> V_300 ++ ;
V_2 -> V_21 = F_220 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_302 ( int , V_2 -> V_24 , F_225 ( V_15 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_45 ) ) {
V_2 -> V_300 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_303 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_316 ;
V_316 = F_239 ( V_2 , V_3 ) ;
if ( V_316 )
return V_316 ;
F_281 ( & V_285 ) ;
V_316 = F_4 ( V_2 ) ;
F_280 ( & V_285 ) ;
if ( V_316 )
F_250 ( V_2 ) ;
return V_316 ;
}
static int T_9 F_304 ( struct V_290 * V_317 ,
unsigned long V_292 , void * V_318 )
{
long V_64 = ( long ) V_318 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_292 ) {
case V_319 :
case V_320 :
case V_321 :
case V_322 :
F_280 ( & V_285 ) ;
F_186 (s, &slab_caches, list) {
F_39 ( V_3 ) ;
F_175 ( V_2 , V_64 ) ;
F_40 ( V_3 ) ;
}
F_281 ( & V_285 ) ;
break;
default:
break;
}
return V_299 ;
}
void * F_305 ( T_1 V_15 , T_5 V_207 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_277 ) )
return F_264 ( V_15 , V_207 ) ;
V_2 = F_261 ( V_15 , V_207 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_202 ( V_2 , V_207 , V_323 ) ;
F_206 ( V_323 , V_223 , V_15 , V_2 -> V_15 , V_207 ) ;
return V_223 ;
}
void * F_306 ( T_1 V_15 , T_5 V_207 ,
int V_10 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_277 ) ) {
V_223 = F_266 ( V_15 , V_207 , V_10 ) ;
F_212 ( V_323 , V_223 ,
V_15 , V_27 << F_190 ( V_15 ) ,
V_207 , V_10 ) ;
return V_223 ;
}
V_2 = F_261 ( V_15 , V_207 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_199 ( V_2 , V_207 , V_10 , V_323 ) ;
F_212 ( V_323 , V_223 , V_15 , V_2 -> V_15 , V_207 , V_10 ) ;
return V_223 ;
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
void * V_18 = F_12 ( V_11 ) ;
if ( ! F_71 ( V_2 , V_11 ) ||
! F_73 ( V_2 , V_11 , NULL ) )
return 0 ;
F_310 ( V_46 , V_11 -> V_14 ) ;
F_41 ( V_2 , V_11 , V_46 ) ;
F_122 (p, s, addr, page->objects) {
if ( F_247 ( F_20 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_70 ( V_2 , V_11 , V_5 , V_110 ) )
return 0 ;
}
F_122 (p, s, addr, page->objects)
if ( ! F_247 ( F_20 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_70 ( V_2 , V_11 , V_5 , V_94 ) )
return 0 ;
return 1 ;
}
static void F_311 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
F_26 ( V_11 ) ;
F_309 ( V_2 , V_11 , V_46 ) ;
F_28 ( V_11 ) ;
}
static int F_312 ( struct V_1 * V_2 ,
struct V_9 * V_37 , unsigned long * V_46 )
{
unsigned long V_324 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_185 ( & V_37 -> V_160 , V_3 ) ;
F_186 (page, &n->partial, lru) {
F_311 ( V_2 , V_11 , V_46 ) ;
V_324 ++ ;
}
if ( V_324 != V_37 -> V_152 )
F_37 ( V_49 L_85
L_86 , V_2 -> V_45 , V_324 , V_37 -> V_152 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_115;
F_186 (page, &n->full, lru) {
F_311 ( V_2 , V_11 , V_46 ) ;
V_324 ++ ;
}
if ( V_324 != F_91 ( & V_37 -> V_108 ) )
F_37 ( V_49 L_87
L_86 , V_2 -> V_45 , V_324 ,
F_91 ( & V_37 -> V_108 ) ) ;
V_115:
F_187 ( & V_37 -> V_160 , V_3 ) ;
return V_324 ;
}
static long F_313 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_324 = 0 ;
unsigned long * V_46 = F_276 ( F_246 ( F_25 ( V_2 -> F_220 ) ) *
sizeof( unsigned long ) , V_256 ) ;
if ( ! V_46 )
return - V_282 ;
F_179 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
V_324 += F_312 ( V_2 , V_37 , V_46 ) ;
}
F_248 ( V_46 ) ;
return V_324 ;
}
static void F_314 ( struct V_325 * V_71 )
{
if ( V_71 -> F_220 )
F_292 ( ( unsigned long ) V_71 -> V_326 ,
F_190 ( sizeof( struct V_327 ) * V_71 -> F_220 ) ) ;
}
static int F_315 ( struct V_325 * V_71 , unsigned long F_220 , T_5 V_3 )
{
struct V_327 * V_184 ;
int V_25 ;
V_25 = F_190 ( sizeof( struct V_327 ) * F_220 ) ;
V_184 = ( void * ) F_290 ( V_3 , V_25 ) ;
if ( ! V_184 )
return 0 ;
if ( V_71 -> V_324 ) {
memcpy ( V_184 , V_71 -> V_326 , sizeof( struct V_327 ) * V_71 -> V_324 ) ;
F_314 ( V_71 ) ;
}
V_71 -> F_220 = F_220 ;
V_71 -> V_326 = V_184 ;
return 1 ;
}
static int F_316 ( struct V_325 * V_71 , struct V_1 * V_2 ,
const struct V_51 * V_51 )
{
long V_86 , V_90 , V_328 ;
struct V_327 * V_184 ;
unsigned long V_329 ;
unsigned long V_330 = V_68 - V_51 -> V_67 ;
V_86 = - 1 ;
V_90 = V_71 -> V_324 ;
for ( ; ; ) {
V_328 = V_86 + ( V_90 - V_86 + 1 ) / 2 ;
if ( V_328 == V_90 )
break;
V_329 = V_71 -> V_326 [ V_328 ] . V_18 ;
if ( V_51 -> V_18 == V_329 ) {
V_184 = & V_71 -> V_326 [ V_328 ] ;
V_184 -> V_324 ++ ;
if ( V_51 -> V_67 ) {
V_184 -> V_331 += V_330 ;
if ( V_330 < V_184 -> V_332 )
V_184 -> V_332 = V_330 ;
if ( V_330 > V_184 -> V_333 )
V_184 -> V_333 = V_330 ;
if ( V_51 -> V_65 < V_184 -> V_334 )
V_184 -> V_334 = V_51 -> V_65 ;
if ( V_51 -> V_65 > V_184 -> V_335 )
V_184 -> V_335 = V_51 -> V_65 ;
F_317 ( V_51 -> V_64 ,
F_318 ( V_184 -> V_336 ) ) ;
}
F_319 ( F_119 ( F_320 ( V_51 ) ) , V_184 -> V_337 ) ;
return 1 ;
}
if ( V_51 -> V_18 < V_329 )
V_90 = V_328 ;
else
V_86 = V_328 ;
}
if ( V_71 -> V_324 >= V_71 -> F_220 && ! F_315 ( V_71 , 2 * V_71 -> F_220 , V_206 ) )
return 0 ;
V_184 = V_71 -> V_326 + V_328 ;
if ( V_328 < V_71 -> V_324 )
memmove ( V_184 + 1 , V_184 ,
( V_71 -> V_324 - V_328 ) * sizeof( struct V_327 ) ) ;
V_71 -> V_324 ++ ;
V_184 -> V_324 = 1 ;
V_184 -> V_18 = V_51 -> V_18 ;
V_184 -> V_331 = V_330 ;
V_184 -> V_332 = V_330 ;
V_184 -> V_333 = V_330 ;
V_184 -> V_334 = V_51 -> V_65 ;
V_184 -> V_335 = V_51 -> V_65 ;
F_321 ( F_318 ( V_184 -> V_336 ) ) ;
F_317 ( V_51 -> V_64 , F_318 ( V_184 -> V_336 ) ) ;
F_322 ( V_184 -> V_337 ) ;
F_319 ( F_119 ( F_320 ( V_51 ) ) , V_184 -> V_337 ) ;
return 1 ;
}
static void F_323 ( struct V_325 * V_71 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_52 V_53 ,
unsigned long * V_46 )
{
void * V_18 = F_12 ( V_11 ) ;
void * V_5 ;
F_310 ( V_46 , V_11 -> V_14 ) ;
F_41 ( V_2 , V_11 , V_46 ) ;
F_122 (p, s, addr, page->objects)
if ( ! F_247 ( F_20 ( V_5 , V_2 , V_18 ) , V_46 ) )
F_316 ( V_71 , V_2 , F_45 ( V_2 , V_5 , V_53 ) ) ;
}
static int F_324 ( struct V_1 * V_2 , char * V_73 ,
enum V_52 V_53 )
{
int V_338 = 0 ;
unsigned long V_56 ;
struct V_325 V_71 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_46 = F_276 ( F_246 ( F_25 ( V_2 -> F_220 ) ) *
sizeof( unsigned long ) , V_256 ) ;
if ( ! V_46 || ! F_315 ( & V_71 , V_27 / sizeof( struct V_327 ) ,
V_339 ) ) {
F_248 ( V_46 ) ;
return sprintf ( V_73 , L_88 ) ;
}
F_179 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_91 ( & V_37 -> V_108 ) )
continue;
F_185 ( & V_37 -> V_160 , V_3 ) ;
F_186 (page, &n->partial, lru)
F_323 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_186 (page, &n->full, lru)
F_323 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_187 ( & V_37 -> V_160 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_324 ; V_56 ++ ) {
struct V_327 * V_184 = & V_71 . V_326 [ V_56 ] ;
if ( V_338 > V_27 - V_340 - 100 )
break;
V_338 += sprintf ( V_73 + V_338 , L_89 , V_184 -> V_324 ) ;
if ( V_184 -> V_18 )
V_338 += sprintf ( V_73 + V_338 , L_90 , ( void * ) V_184 -> V_18 ) ;
else
V_338 += sprintf ( V_73 + V_338 , L_91 ) ;
if ( V_184 -> V_331 != V_184 -> V_332 ) {
V_338 += sprintf ( V_73 + V_338 , L_92 ,
V_184 -> V_332 ,
( long ) F_325 ( V_184 -> V_331 , V_184 -> V_324 ) ,
V_184 -> V_333 ) ;
} else
V_338 += sprintf ( V_73 + V_338 , L_93 ,
V_184 -> V_332 ) ;
if ( V_184 -> V_334 != V_184 -> V_335 )
V_338 += sprintf ( V_73 + V_338 , L_94 ,
V_184 -> V_334 , V_184 -> V_335 ) ;
else
V_338 += sprintf ( V_73 + V_338 , L_95 ,
V_184 -> V_334 ) ;
if ( F_326 () > 1 &&
! F_327 ( F_318 ( V_184 -> V_336 ) ) &&
V_338 < V_27 - 60 ) {
V_338 += sprintf ( V_73 + V_338 , L_96 ) ;
V_338 += F_328 ( V_73 + V_338 , V_27 - V_338 - 50 ,
F_318 ( V_184 -> V_336 ) ) ;
}
if ( V_341 > 1 && ! F_329 ( V_184 -> V_337 ) &&
V_338 < V_27 - 60 ) {
V_338 += sprintf ( V_73 + V_338 , L_97 ) ;
V_338 += F_330 ( V_73 + V_338 , V_27 - V_338 - 50 ,
V_184 -> V_337 ) ;
}
V_338 += sprintf ( V_73 + V_338 , L_98 ) ;
}
F_314 ( & V_71 ) ;
F_248 ( V_46 ) ;
if ( ! V_71 . V_324 )
V_338 += sprintf ( V_73 , L_99 ) ;
return V_338 ;
}
static void F_331 ( void )
{
T_3 * V_5 ;
F_231 ( V_309 > 16 || V_252 < 10 ) ;
F_37 ( V_49 L_100 ) ;
F_37 ( V_49 L_101 ) ;
F_37 ( V_49 L_102 ) ;
V_5 = F_245 ( 16 , V_256 ) ;
V_5 [ 16 ] = 0x12 ;
F_37 ( V_49 L_103
L_104 , V_5 + 16 ) ;
F_313 ( V_276 [ 4 ] ) ;
V_5 = F_245 ( 32 , V_256 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_37 ( V_49 L_105
L_106 , V_5 ) ;
F_37 ( V_49
L_107 ) ;
F_313 ( V_276 [ 5 ] ) ;
V_5 = F_245 ( 64 , V_256 ) ;
V_5 += 64 + ( F_149 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_37 ( V_49 L_108 ,
V_5 ) ;
F_37 ( V_49
L_107 ) ;
F_313 ( V_276 [ 6 ] ) ;
F_37 ( V_49 L_109 ) ;
V_5 = F_245 ( 128 , V_256 ) ;
F_248 ( V_5 ) ;
* V_5 = 0x78 ;
F_37 ( V_49 L_110 , V_5 ) ;
F_313 ( V_276 [ 7 ] ) ;
V_5 = F_245 ( 256 , V_256 ) ;
F_248 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_37 ( V_49 L_111 ,
V_5 ) ;
F_313 ( V_276 [ 8 ] ) ;
V_5 = F_245 ( 512 , V_256 ) ;
F_248 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_37 ( V_49 L_112 , V_5 ) ;
F_313 ( V_276 [ 9 ] ) ;
}
static void F_331 ( void ) {}
static T_10 F_332 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_342 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_337 ;
unsigned long * V_343 ;
V_337 = F_245 ( 2 * sizeof( unsigned long ) * V_306 , V_256 ) ;
if ( ! V_337 )
return - V_282 ;
V_343 = V_337 + V_306 ;
if ( V_3 & V_344 ) {
int V_64 ;
F_167 (cpu) {
struct V_157 * V_158 = F_168 ( V_2 -> V_8 , V_64 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_333 ( V_158 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_119 ( V_11 ) ;
if ( V_3 & V_345 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_346 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
V_11 = F_333 ( V_158 -> V_154 ) ;
if ( V_11 ) {
V_29 = V_11 -> V_201 ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
}
V_343 [ V_10 ] ++ ;
}
}
F_334 () ;
#ifdef F_2
if ( V_3 & V_347 ) {
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
if ( V_3 & V_345 )
V_29 = F_91 ( & V_37 -> V_109 ) ;
else if ( V_3 & V_346 )
V_29 = F_91 ( & V_37 -> V_109 ) -
F_183 ( V_37 , F_182 ) ;
else
V_29 = F_91 ( & V_37 -> V_108 ) ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_348 ) {
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
if ( V_3 & V_345 )
V_29 = F_183 ( V_37 , F_308 ) ;
else if ( V_3 & V_346 )
V_29 = F_183 ( V_37 , F_307 ) ;
else
V_29 = V_37 -> V_152 ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_73 , L_113 , V_342 ) ;
#ifdef F_147
F_235 (node, N_NORMAL_MEMORY)
if ( V_337 [ V_10 ] )
V_29 += sprintf ( V_73 + V_29 , L_114 ,
V_10 , V_337 [ V_10 ] ) ;
#endif
F_335 () ;
F_248 ( V_337 ) ;
return V_29 + sprintf ( V_73 + V_29 , L_98 ) ;
}
static int F_336 ( struct V_1 * V_2 )
{
int V_10 ;
F_191 (node) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
if ( F_91 ( & V_37 -> V_109 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_337 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , V_2 -> V_15 ) ;
}
static T_10 F_338 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , V_2 -> V_247 ) ;
}
static T_10 F_339 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , V_2 -> V_21 ) ;
}
static T_10 F_340 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , F_25 ( V_2 -> V_121 ) ) ;
}
static T_10 F_341 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_25 ;
int V_316 ;
V_316 = F_342 ( V_73 , 10 , & V_25 ) ;
if ( V_316 )
return V_316 ;
if ( V_25 > V_244 || V_25 < V_238 )
return - V_266 ;
F_238 ( V_2 , V_25 ) ;
return V_48 ;
}
static T_10 F_343 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , F_24 ( V_2 -> V_121 ) ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_116 , V_2 -> V_173 ) ;
}
static T_10 F_345 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_129 ;
int V_316 ;
V_316 = F_342 ( V_73 , 10 , & V_129 ) ;
if ( V_316 )
return V_316 ;
F_237 ( V_2 , V_129 ) ;
return V_48 ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_117 , V_2 -> V_164 ) ;
}
static T_10 F_347 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_14 ;
int V_316 ;
V_316 = F_342 ( V_73 , 10 , & V_14 ) ;
if ( V_316 )
return V_316 ;
if ( V_14 && F_1 ( V_2 ) )
return - V_266 ;
V_2 -> V_164 = V_14 ;
F_179 ( V_2 ) ;
return V_48 ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! V_2 -> F_103 )
return 0 ;
return sprintf ( V_73 , L_118 , V_2 -> F_103 ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , V_2 -> V_300 - 1 ) ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_73 )
{
return F_332 ( V_2 , V_73 , V_348 ) ;
}
static T_10 F_351 ( struct V_1 * V_2 , char * V_73 )
{
return F_332 ( V_2 , V_73 , V_344 ) ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_73 )
{
return F_332 ( V_2 , V_73 , V_347 | V_346 ) ;
}
static T_10 F_353 ( struct V_1 * V_2 , char * V_73 )
{
return F_332 ( V_2 , V_73 , V_348 | V_346 ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_73 )
{
int V_14 = 0 ;
int V_133 = 0 ;
int V_64 ;
int V_338 ;
F_355 (cpu) {
struct V_11 * V_11 = F_168 ( V_2 -> V_8 , V_64 ) -> V_154 ;
if ( V_11 ) {
V_133 += V_11 -> V_133 ;
V_14 += V_11 -> V_201 ;
}
}
V_338 = sprintf ( V_73 , L_119 , V_14 , V_133 ) ;
#ifdef F_296
F_355 (cpu) {
struct V_11 * V_11 = F_168 ( V_2 -> V_8 , V_64 ) -> V_154 ;
if ( V_11 && V_338 < V_27 - 20 )
V_338 += sprintf ( V_73 + V_338 , L_120 , V_64 ,
V_11 -> V_201 , V_11 -> V_133 ) ;
}
#endif
return V_338 + sprintf ( V_73 + V_338 , L_98 ) ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_134 ) ) ;
}
static T_10 F_357 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_134 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_134 ;
return V_48 ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_248 ) ) ;
}
static T_10 F_359 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_261 ) ) ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , V_2 -> V_26 ) ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return F_332 ( V_2 , V_73 , V_347 ) ;
}
static T_10 F_363 ( struct V_1 * V_2 , char * V_73 )
{
return F_332 ( V_2 , V_73 , V_347 | V_345 ) ;
}
static T_10 F_364 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_118 ) ) ;
}
static T_10 F_365 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_118 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_118 ;
}
return V_48 ;
}
static T_10 F_366 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_100 ) ) ;
}
static T_10 F_367 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_100 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_100 ;
}
return V_48 ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_10 F_369 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_336 ( V_2 ) )
return - V_349 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_19 ;
}
F_238 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_10 F_371 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_336 ( V_2 ) )
return - V_349 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_20 ;
}
F_238 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_372 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_373 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_336 ( V_2 ) )
return - V_349 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_23 ;
}
F_238 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_374 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_375 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
int V_223 = - V_266 ;
if ( V_73 [ 0 ] == '1' ) {
V_223 = F_313 ( V_2 ) ;
if ( V_223 >= 0 )
V_223 = V_48 ;
}
return V_223 ;
}
static T_10 F_376 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_246 ;
return F_324 ( V_2 , V_73 , V_70 ) ;
}
static T_10 F_377 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_246 ;
return F_324 ( V_2 , V_73 , V_69 ) ;
}
static T_10 F_378 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_10 F_379 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_119 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_119 ;
return V_48 ;
}
static T_10 F_380 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_381 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( V_73 [ 0 ] == '1' ) {
int V_267 = F_275 ( V_2 ) ;
if ( V_267 )
return V_267 ;
} else
return - V_266 ;
return V_48 ;
}
static T_10 F_382 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_115 , V_2 -> V_172 / 10 ) ;
}
static T_10 F_383 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_350 ;
int V_316 ;
V_316 = F_342 ( V_73 , 10 , & V_350 ) ;
if ( V_316 )
return V_316 ;
if ( V_350 <= 100 )
V_2 -> V_172 = V_350 * 10 ;
return V_48 ;
}
static int F_384 ( struct V_1 * V_2 , char * V_73 , enum V_6 V_7 )
{
unsigned long V_351 = 0 ;
int V_64 ;
int V_338 ;
int * V_82 = F_276 ( V_243 * sizeof( int ) , V_256 ) ;
if ( ! V_82 )
return - V_282 ;
F_355 (cpu) {
unsigned V_29 = F_168 ( V_2 -> V_8 , V_64 ) -> F_7 [ V_7 ] ;
V_82 [ V_64 ] = V_29 ;
V_351 += V_29 ;
}
V_338 = sprintf ( V_73 , L_113 , V_351 ) ;
#ifdef F_296
F_355 (cpu) {
if ( V_82 [ V_64 ] && V_338 < V_27 - 20 )
V_338 += sprintf ( V_73 + V_338 , L_121 , V_64 , V_82 [ V_64 ] ) ;
}
#endif
F_248 ( V_82 ) ;
return V_338 + sprintf ( V_73 + V_338 , L_98 ) ;
}
static void F_385 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_64 ;
F_355 (cpu)
F_168 ( V_2 -> V_8 , V_64 ) -> F_7 [ V_7 ] = 0 ;
}
static T_10 F_386 ( struct V_352 * V_353 ,
struct V_354 * V_355 ,
char * V_73 )
{
struct V_356 * V_354 ;
struct V_1 * V_2 ;
int V_316 ;
V_354 = F_387 ( V_355 ) ;
V_2 = F_388 ( V_353 ) ;
if ( ! V_354 -> V_357 )
return - V_358 ;
V_316 = V_354 -> V_357 ( V_2 , V_73 ) ;
return V_316 ;
}
static T_10 F_389 ( struct V_352 * V_353 ,
struct V_354 * V_355 ,
const char * V_73 , T_1 V_338 )
{
struct V_356 * V_354 ;
struct V_1 * V_2 ;
int V_316 ;
V_354 = F_387 ( V_355 ) ;
V_2 = F_388 ( V_353 ) ;
if ( ! V_354 -> V_359 )
return - V_358 ;
V_316 = V_354 -> V_359 ( V_2 , V_73 , V_338 ) ;
return V_316 ;
}
static int F_390 ( struct V_360 * V_360 , struct V_352 * V_353 )
{
struct V_361 * V_362 = F_391 ( V_353 ) ;
if ( V_362 == & V_363 )
return 1 ;
return 0 ;
}
static char * F_392 ( struct V_1 * V_2 )
{
char * V_45 = F_276 ( V_364 , V_256 ) ;
char * V_5 = V_45 ;
F_118 ( ! V_45 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_261 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_134 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_118 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_132 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_45 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_122 , V_2 -> V_15 ) ;
F_118 ( V_5 > V_45 + V_364 - 1 ) ;
return V_45 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_316 ;
const char * V_45 ;
int V_365 ;
if ( V_254 < V_366 )
return 0 ;
V_365 = F_299 ( V_2 ) ;
if ( V_365 ) {
F_393 ( & V_367 -> V_353 , V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
} else {
V_45 = F_392 ( V_2 ) ;
}
V_2 -> V_353 . V_360 = V_367 ;
V_316 = F_394 ( & V_2 -> V_353 , & V_363 , NULL , V_45 ) ;
if ( V_316 ) {
F_395 ( & V_2 -> V_353 ) ;
return V_316 ;
}
V_316 = F_396 ( & V_2 -> V_353 , & V_368 ) ;
if ( V_316 ) {
F_397 ( & V_2 -> V_353 ) ;
F_395 ( & V_2 -> V_353 ) ;
return V_316 ;
}
F_398 ( & V_2 -> V_353 , V_369 ) ;
if ( ! V_365 ) {
F_5 ( V_2 , V_2 -> V_45 ) ;
F_248 ( V_45 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_254 < V_366 )
return;
F_398 ( & V_2 -> V_353 , V_370 ) ;
F_397 ( & V_2 -> V_353 ) ;
F_395 ( & V_2 -> V_353 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_45 )
{
struct V_371 * V_372 ;
if ( V_254 == V_366 ) {
F_393 ( & V_367 -> V_353 , V_45 ) ;
return F_399 ( & V_367 -> V_353 , & V_2 -> V_353 , V_45 ) ;
}
V_372 = F_276 ( sizeof( struct V_371 ) , V_256 ) ;
if ( ! V_372 )
return - V_282 ;
V_372 -> V_2 = V_2 ;
V_372 -> V_45 = V_45 ;
V_372 -> V_197 = V_373 ;
V_373 = V_372 ;
return 0 ;
}
static int T_7 F_400 ( void )
{
struct V_1 * V_2 ;
int V_316 ;
F_280 ( & V_285 ) ;
V_367 = F_401 ( L_123 , & V_374 , V_375 ) ;
if ( ! V_367 ) {
F_281 ( & V_285 ) ;
F_37 ( V_49 L_124 ) ;
return - V_246 ;
}
V_254 = V_366 ;
F_186 (s, &slab_caches, list) {
V_316 = F_4 ( V_2 ) ;
if ( V_316 )
F_37 ( V_49 L_125
L_126 , V_2 -> V_45 ) ;
}
while ( V_373 ) {
struct V_371 * V_372 = V_373 ;
V_373 = V_373 -> V_197 ;
V_316 = F_5 ( V_372 -> V_2 , V_372 -> V_45 ) ;
if ( V_316 )
F_37 ( V_49 L_127
L_128 , V_372 -> V_45 ) ;
F_248 ( V_372 ) ;
}
F_281 ( & V_285 ) ;
F_331 () ;
return 0 ;
}
static void F_402 ( struct V_376 * V_185 )
{
F_403 ( V_185 , L_129 ) ;
F_403 ( V_185 , L_130
L_131 ) ;
F_403 ( V_185 , L_132 ) ;
F_403 ( V_185 , L_133 ) ;
F_404 ( V_185 , '\n' ) ;
}
static void * F_405 ( struct V_376 * V_185 , T_11 * V_328 )
{
T_11 V_37 = * V_328 ;
F_280 ( & V_285 ) ;
if ( ! V_37 )
F_402 ( V_185 ) ;
return F_406 ( & V_271 , * V_328 ) ;
}
static void * F_407 ( struct V_376 * V_185 , void * V_5 , T_11 * V_328 )
{
return F_408 ( V_5 , & V_271 , V_328 ) ;
}
static void F_409 ( struct V_376 * V_185 , void * V_5 )
{
F_281 ( & V_285 ) ;
}
static int F_410 ( struct V_376 * V_185 , void * V_5 )
{
unsigned long V_377 = 0 ;
unsigned long V_108 = 0 ;
unsigned long V_378 = 0 ;
unsigned long V_210 = 0 ;
unsigned long V_211 = 0 ;
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_411 ( V_5 , struct V_1 , V_270 ) ;
F_191 (node) {
struct V_9 * V_37 = F_10 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
V_377 += V_37 -> V_152 ;
V_108 += F_91 ( & V_37 -> V_108 ) ;
V_210 += F_91 ( & V_37 -> V_109 ) ;
V_211 += F_183 ( V_37 , F_182 ) ;
}
V_378 = V_210 - V_211 ;
F_412 ( V_185 , L_134 , V_2 -> V_45 , V_378 ,
V_210 , V_2 -> V_15 , F_25 ( V_2 -> V_121 ) ,
( 1 << F_24 ( V_2 -> V_121 ) ) ) ;
F_412 ( V_185 , L_135 , 0 , 0 , 0 ) ;
F_412 ( V_185 , L_136 , V_108 , V_108 ,
0UL ) ;
F_404 ( V_185 , '\n' ) ;
return 0 ;
}
static int F_413 ( struct V_379 * V_379 , struct V_380 * V_380 )
{
return F_414 ( V_380 , & V_381 ) ;
}
static int T_7 F_415 ( void )
{
F_416 ( L_137 , V_382 , NULL , & V_383 ) ;
return 0 ;
}
