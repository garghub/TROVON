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
static inline void F_33 ( struct V_11 * V_11 , unsigned long V_33 )
{
struct V_11 V_34 ;
V_34 . V_35 = V_33 ;
V_11 -> V_36 = V_34 . V_36 ;
V_11 -> V_24 = V_34 . V_24 ;
V_11 -> V_14 = V_34 . V_14 ;
}
static inline bool F_34 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_37 , unsigned long V_38 ,
void * V_39 , unsigned long V_33 ,
const char * V_40 )
{
F_35 ( ! F_36 () ) ;
#if F_37 ( V_41 ) && \
F_37 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_38 ( & V_11 -> V_44 , & V_11 -> V_35 ,
V_37 , V_38 ,
V_39 , V_33 ) )
return 1 ;
} else
#endif
{
F_29 ( V_11 ) ;
if ( V_11 -> V_44 == V_37 &&
V_11 -> V_35 == V_38 ) {
V_11 -> V_44 = V_39 ;
F_33 ( V_11 , V_33 ) ;
F_31 ( V_11 ) ;
return 1 ;
}
F_31 ( V_11 ) ;
}
F_39 () ;
F_10 ( V_2 , V_45 ) ;
#ifdef F_40
F_41 ( V_46 L_1 , V_40 , V_2 -> V_47 ) ;
#endif
return 0 ;
}
static inline bool F_42 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_37 , unsigned long V_38 ,
void * V_39 , unsigned long V_33 ,
const char * V_40 )
{
#if F_37 ( V_41 ) && \
F_37 ( V_42 )
if ( V_2 -> V_3 & V_43 ) {
if ( F_38 ( & V_11 -> V_44 , & V_11 -> V_35 ,
V_37 , V_38 ,
V_39 , V_33 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_43 ( V_3 ) ;
F_29 ( V_11 ) ;
if ( V_11 -> V_44 == V_37 &&
V_11 -> V_35 == V_38 ) {
V_11 -> V_44 = V_39 ;
F_33 ( V_11 , V_33 ) ;
F_31 ( V_11 ) ;
F_44 ( V_3 ) ;
return 1 ;
}
F_31 ( V_11 ) ;
F_44 ( V_3 ) ;
}
F_39 () ;
F_10 ( V_2 , V_45 ) ;
#ifdef F_40
F_41 ( V_46 L_1 , V_40 , V_2 -> V_47 ) ;
#endif
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long * V_48 )
{
void * V_5 ;
void * V_18 = F_15 ( V_11 ) ;
for ( V_5 = V_11 -> V_44 ; V_5 ; V_5 = F_16 ( V_2 , V_5 ) )
F_46 ( F_23 ( V_5 , V_2 , V_18 ) , V_48 ) ;
}
static void F_47 ( char * V_49 , T_3 * V_18 , unsigned int V_50 )
{
F_48 ( V_51 , V_49 , V_52 , 16 , 1 , V_18 ,
V_50 , 1 ) ;
}
static struct V_53 * F_49 ( struct V_1 * V_2 , void * V_12 ,
enum V_54 V_55 )
{
struct V_53 * V_5 ;
if ( V_2 -> V_16 )
V_5 = V_12 + V_2 -> V_16 + sizeof( void * ) ;
else
V_5 = V_12 + V_2 -> V_24 ;
return V_5 + V_55 ;
}
static void F_50 ( struct V_1 * V_2 , void * V_12 ,
enum V_54 V_55 , unsigned long V_18 )
{
struct V_53 * V_5 = F_49 ( V_2 , V_12 , V_55 ) ;
if ( V_18 ) {
#ifdef F_51
struct V_56 V_57 ;
int V_58 ;
V_57 . V_59 = 0 ;
V_57 . V_60 = V_61 ;
V_57 . V_62 = V_5 -> V_63 ;
V_57 . V_64 = 3 ;
F_52 ( & V_57 ) ;
if ( V_57 . V_59 != 0 &&
V_57 . V_62 [ V_57 . V_59 - 1 ] == V_65 )
V_57 . V_59 -- ;
for ( V_58 = V_57 . V_59 ; V_58 < V_61 ; V_58 ++ )
V_5 -> V_63 [ V_58 ] = 0 ;
#endif
V_5 -> V_18 = V_18 ;
V_5 -> V_66 = F_53 () ;
V_5 -> V_67 = V_68 -> V_67 ;
V_5 -> V_69 = V_70 ;
} else
memset ( V_5 , 0 , sizeof( struct V_53 ) ) ;
}
static void F_54 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_50 ( V_2 , V_12 , V_71 , 0UL ) ;
F_50 ( V_2 , V_12 , V_72 , 0UL ) ;
}
static void F_55 ( const char * V_2 , struct V_53 * V_73 )
{
if ( ! V_73 -> V_18 )
return;
F_41 ( V_51 L_2 ,
V_2 , ( void * ) V_73 -> V_18 , V_70 - V_73 -> V_69 , V_73 -> V_66 , V_73 -> V_67 ) ;
#ifdef F_51
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 ; V_58 ++ )
if ( V_73 -> V_63 [ V_58 ] )
F_41 ( V_51 L_3 , ( void * ) V_73 -> V_63 [ V_58 ] ) ;
else
break;
}
#endif
}
static void F_56 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_55 ( L_4 , F_49 ( V_2 , V_12 , V_72 ) ) ;
F_55 ( L_5 , F_49 ( V_2 , V_12 , V_71 ) ) ;
}
static void F_57 ( struct V_11 * V_11 )
{
F_41 ( V_51
L_6 ,
V_11 , V_11 -> V_14 , V_11 -> V_24 , V_11 -> V_44 , V_11 -> V_3 ) ;
}
static void F_58 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_41 ( V_51 L_7
L_8 ) ;
F_41 ( V_51 L_9 , V_2 -> V_47 , F_59 () , V_75 ) ;
F_41 ( V_51 L_10
L_11 ) ;
F_60 ( V_76 , V_77 ) ;
}
static void F_61 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_41 ( V_51 L_12 , V_2 -> V_47 , V_75 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned int V_78 ;
T_3 * V_18 = F_15 ( V_11 ) ;
F_56 ( V_2 , V_5 ) ;
F_57 ( V_11 ) ;
F_41 ( V_51 L_13 ,
V_5 , V_5 - V_18 , F_16 ( V_2 , V_5 ) ) ;
if ( V_5 > V_18 + 16 )
F_47 ( L_14 , V_5 - 16 , 16 ) ;
F_47 ( L_15 , V_5 , F_63 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_19 )
F_47 ( L_16 , V_5 + V_2 -> V_21 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
if ( V_2 -> V_16 )
V_78 = V_2 -> V_16 + sizeof( void * ) ;
else
V_78 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_78 += 2 * sizeof( struct V_53 ) ;
if ( V_78 != V_2 -> V_15 )
F_47 ( L_17 , V_5 + V_78 , V_2 -> V_15 - V_78 ) ;
F_64 () ;
}
static void F_65 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_79 )
{
F_58 ( V_2 , L_18 , V_79 ) ;
F_62 ( V_2 , V_11 , V_12 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_58 ( V_2 , L_18 , V_75 ) ;
F_57 ( V_11 ) ;
F_64 () ;
}
static void F_67 ( struct V_1 * V_2 , void * V_12 , T_3 V_80 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_81 ) {
memset ( V_5 , V_82 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_83 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_80 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_68 ( struct V_1 * V_2 , char * V_84 , T_3 V_85 ,
void * V_86 , void * V_87 )
{
F_61 ( V_2 , L_19 , V_86 , V_87 - 1 , V_85 ) ;
memset ( V_86 , V_85 , V_87 - V_86 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_88 ,
T_3 * V_89 , unsigned int V_90 , unsigned int V_91 )
{
T_3 * V_92 ;
T_3 * V_93 ;
V_92 = F_70 ( V_89 , V_90 , V_91 ) ;
if ( ! V_92 )
return 1 ;
V_93 = V_89 + V_91 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_90 )
V_93 -- ;
F_58 ( V_2 , L_20 , V_88 ) ;
F_41 ( V_51 L_21 ,
V_92 , V_93 - 1 , V_92 [ 0 ] , V_90 ) ;
F_62 ( V_2 , V_11 , V_12 ) ;
F_68 ( V_2 , V_88 , V_90 , V_92 , V_93 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_78 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_78 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_78 += 2 * sizeof( struct V_53 ) ;
if ( V_2 -> V_15 == V_78 )
return 1 ;
return F_69 ( V_2 , V_11 , V_5 , L_22 ,
V_5 + V_78 , V_94 , V_2 -> V_15 - V_78 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_89 ;
T_3 * V_92 ;
T_3 * V_93 ;
int V_50 ;
int V_95 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_89 = F_15 ( V_11 ) ;
V_50 = ( V_27 << F_73 ( V_11 ) ) - V_2 -> V_26 ;
V_93 = V_89 + V_50 ;
V_95 = V_50 % V_2 -> V_15 ;
if ( ! V_95 )
return 1 ;
V_92 = F_70 ( V_93 - V_95 , V_94 , V_95 ) ;
if ( ! V_92 )
return 1 ;
while ( V_93 > V_92 && V_93 [ - 1 ] == V_94 )
V_93 -- ;
F_66 ( V_2 , V_11 , L_23 , V_92 , V_93 - 1 ) ;
F_47 ( L_17 , V_93 - V_95 , V_95 ) ;
F_68 ( V_2 , L_24 , V_94 , V_93 - V_95 , V_93 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_80 )
{
T_3 * V_5 = V_12 ;
T_3 * V_96 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_69 ( V_2 , V_11 , V_12 , L_25 ,
V_96 , V_80 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_69 ( V_2 , V_11 , V_5 , L_26 ,
V_96 , V_94 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_80 != V_97 && ( V_2 -> V_3 & V_81 ) &&
( ! F_69 ( V_2 , V_11 , V_5 , L_27 , V_5 ,
V_82 , V_2 -> V_21 - 1 ) ||
! F_69 ( V_2 , V_11 , V_5 , L_27 ,
V_5 + V_2 -> V_21 - 1 , V_83 , 1 ) ) )
return 0 ;
F_71 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_80 == V_97 )
return 1 ;
if ( ! F_14 ( V_2 , V_11 , F_16 ( V_2 , V_5 ) ) ) {
F_65 ( V_2 , V_11 , V_5 , L_28 ) ;
F_22 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_98 ;
F_35 ( ! F_36 () ) ;
if ( ! F_76 ( V_11 ) ) {
F_66 ( V_2 , V_11 , L_29 ) ;
return 0 ;
}
V_98 = F_25 ( F_73 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_98 ) {
F_66 ( V_2 , V_11 , L_30 ,
V_2 -> V_47 , V_11 -> V_14 , V_98 ) ;
return 0 ;
}
if ( V_11 -> V_24 > V_11 -> V_14 ) {
F_66 ( V_2 , V_11 , L_31 ,
V_2 -> V_47 , V_11 -> V_24 , V_11 -> V_14 ) ;
return 0 ;
}
F_72 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_99 )
{
int V_100 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_101 ;
V_17 = V_11 -> V_44 ;
while ( V_17 && V_100 <= V_11 -> V_14 ) {
if ( V_17 == V_99 )
return 1 ;
if ( ! F_14 ( V_2 , V_11 , V_17 ) ) {
if ( V_12 ) {
F_65 ( V_2 , V_11 , V_12 ,
L_32 ) ;
F_22 ( V_2 , V_12 , NULL ) ;
} else {
F_66 ( V_2 , V_11 , L_28 ) ;
V_11 -> V_44 = NULL ;
V_11 -> V_24 = V_11 -> V_14 ;
F_61 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_12 = V_17 ;
V_17 = F_16 ( V_2 , V_12 ) ;
V_100 ++ ;
}
V_101 = F_25 ( F_73 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_101 > V_102 )
V_101 = V_102 ;
if ( V_11 -> V_14 != V_101 ) {
F_66 ( V_2 , V_11 , L_34
L_35 , V_11 -> V_14 , V_101 ) ;
V_11 -> V_14 = V_101 ;
F_61 ( V_2 , L_36 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_100 ) {
F_66 ( V_2 , V_11 , L_37
L_38 , V_11 -> V_24 , V_11 -> V_14 - V_100 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_100 ;
F_61 ( V_2 , L_39 ) ;
}
return V_99 == NULL ;
}
static void V_57 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_55 )
{
if ( V_2 -> V_3 & V_103 ) {
F_41 ( V_46 L_40 ,
V_2 -> V_47 ,
V_55 ? L_41 : L_42 ,
V_12 , V_11 -> V_24 ,
V_11 -> V_44 ) ;
if ( ! V_55 )
F_47 ( L_15 , ( void * ) V_12 ,
V_2 -> V_21 ) ;
F_64 () ;
}
}
static inline void F_78 ( void * V_104 , T_1 V_15 , T_5 V_3 )
{
F_79 ( V_104 , V_15 , 1 , V_3 ) ;
}
static inline void F_80 ( const void * V_29 )
{
F_81 ( V_29 ) ;
}
static inline int F_82 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_105 ;
F_83 ( V_3 ) ;
F_84 ( V_3 & V_106 ) ;
return F_85 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_86 ( struct V_1 * V_2 ,
T_5 V_3 , void * V_12 )
{
V_3 &= V_105 ;
F_87 ( V_2 , V_3 , V_12 , F_24 ( V_2 ) ) ;
F_88 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_89 ( struct V_1 * V_2 , void * V_29 )
{
F_90 ( V_29 , V_2 -> V_3 ) ;
#if F_37 ( V_107 ) || F_37 ( V_108 )
{
unsigned long V_3 ;
F_43 ( V_3 ) ;
F_91 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_92 ( V_29 , V_2 -> V_21 ) ;
F_44 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_109 ) )
F_93 ( V_29 , V_2 -> V_21 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_9 * V_40 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_95 ( & V_40 -> V_110 ) ;
F_96 ( & V_11 -> V_111 , & V_40 -> V_112 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_9 * V_40 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_95 ( & V_40 -> V_110 ) ;
F_98 ( & V_11 -> V_111 ) ;
}
static inline unsigned long F_99 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
return F_100 ( & V_40 -> V_113 ) ;
}
static inline unsigned long F_101 ( struct V_9 * V_40 )
{
return F_100 ( & V_40 -> V_113 ) ;
}
static inline void F_102 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
if ( F_103 ( V_40 ) ) {
F_104 ( & V_40 -> V_113 ) ;
F_105 ( V_14 , & V_40 -> V_114 ) ;
}
}
static inline void F_106 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
F_107 ( & V_40 -> V_113 ) ;
F_108 ( V_14 , & V_40 -> V_114 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_81 ) ) )
return;
F_67 ( V_2 , V_12 , V_115 ) ;
F_54 ( V_2 , V_12 ) ;
}
static T_6 int F_110 ( struct V_1 * V_2 ,
struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_75 ( V_2 , V_11 ) )
goto V_116;
if ( ! F_14 ( V_2 , V_11 , V_12 ) ) {
F_65 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_116;
}
if ( ! F_74 ( V_2 , V_11 , V_12 , V_115 ) )
goto V_116;
if ( V_2 -> V_3 & V_23 )
F_50 ( V_2 , V_12 , V_72 , V_18 ) ;
V_57 ( V_2 , V_11 , V_12 , 1 ) ;
F_67 ( V_2 , V_12 , V_97 ) ;
return 1 ;
V_116:
if ( F_76 ( V_11 ) ) {
F_61 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_44 = NULL ;
}
return 0 ;
}
int T_7 F_111 ( char * V_117 )
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
F_41 ( V_51 L_45
L_46 , * V_117 ) ;
}
}
V_121:
if ( * V_117 == ',' )
V_125 = V_117 + 1 ;
V_120:
return 1 ;
}
static unsigned long F_112 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_47 ,
void (* F_113)( void * ) )
{
if ( V_118 && ( ! V_125 || ( V_47 &&
! strncmp ( V_125 , V_47 , strlen ( V_125 ) ) ) ) )
V_3 |= V_118 ;
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
void * V_12 , T_3 V_80 ) { return 1 ; }
static inline void F_94 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_11 * V_11 ) {}
static inline void F_97 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_11 * V_11 ) {}
static inline unsigned long F_112 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_47 ,
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
static inline void F_78 ( void * V_104 , T_1 V_15 , T_5 V_3 )
{
F_79 ( V_104 , V_15 , 1 , V_3 ) ;
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
V_3 & V_105 ) ;
}
static inline void F_89 ( struct V_1 * V_2 , void * V_29 )
{
F_90 ( V_29 , V_2 -> V_3 ) ;
}
static inline struct V_11 * F_115 ( T_5 V_3 , int V_10 ,
struct V_28 V_126 )
{
int V_25 = F_27 ( V_126 ) ;
V_3 |= V_127 ;
if ( V_10 == V_128 )
return F_116 ( V_3 , V_25 ) ;
else
return F_117 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_118 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_126 = V_2 -> V_126 ;
T_5 V_129 ;
V_3 &= V_105 ;
if ( V_3 & V_106 )
F_119 () ;
V_3 |= V_2 -> V_130 ;
V_129 = ( V_3 | V_131 | V_132 ) & ~ V_133 ;
V_11 = F_115 ( V_129 , V_10 , V_126 ) ;
if ( F_3 ( ! V_11 ) ) {
V_126 = V_2 -> V_134 ;
V_11 = F_115 ( V_3 , V_10 , V_126 ) ;
if ( V_11 )
F_10 ( V_2 , V_135 ) ;
}
if ( V_136 && V_11
&& ! ( V_2 -> V_3 & ( V_137 | V_119 ) ) ) {
int V_138 = 1 << F_27 ( V_126 ) ;
F_120 ( V_11 , F_27 ( V_126 ) , V_3 , V_10 ) ;
if ( V_2 -> F_113 )
F_121 ( V_11 , V_138 ) ;
else
F_122 ( V_11 , V_138 ) ;
}
if ( V_3 & V_106 )
F_123 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_28 ( V_126 ) ;
F_124 ( F_125 ( V_11 ) ,
( V_2 -> V_3 & V_139 ) ?
V_140 : V_141 ,
1 << F_27 ( V_126 ) ) ;
return V_11 ;
}
static void F_126 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_109 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_113 ) )
V_2 -> F_113 ( V_12 ) ;
}
static struct V_11 * F_127 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_89 ;
void * V_142 ;
void * V_5 ;
int V_25 ;
F_128 ( V_3 & V_143 ) ;
V_11 = F_118 ( V_2 ,
V_3 & ( V_144 | V_145 ) , V_10 ) ;
if ( ! V_11 )
goto V_120;
V_25 = F_73 ( V_11 ) ;
F_102 ( V_2 , F_129 ( V_11 ) , V_11 -> V_14 ) ;
F_130 ( V_2 , V_25 ) ;
V_11 -> V_146 = V_2 ;
F_131 ( V_11 ) ;
if ( V_11 -> V_147 )
F_132 ( V_11 ) ;
V_89 = F_15 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_89 , V_94 , V_27 << V_25 ) ;
V_142 = V_89 ;
F_133 (p, s, start, page->objects) {
F_126 ( V_2 , V_11 , V_142 ) ;
F_22 ( V_2 , V_142 , V_5 ) ;
V_142 = V_5 ;
}
F_126 ( V_2 , V_11 , V_142 ) ;
F_22 ( V_2 , V_142 , NULL ) ;
V_11 -> V_44 = V_89 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_36 = 1 ;
V_120:
return V_11 ;
}
static void F_134 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_73 ( V_11 ) ;
int V_138 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_72 ( V_2 , V_11 ) ;
F_133 (p, s, page_address(page),
page->objects)
F_74 ( V_2 , V_11 , V_5 , V_115 ) ;
}
F_135 ( V_11 , F_73 ( V_11 ) ) ;
F_124 ( F_125 ( V_11 ) ,
( V_2 -> V_3 & V_139 ) ?
V_140 : V_141 ,
- V_138 ) ;
F_136 ( V_11 ) ;
F_137 ( V_11 ) ;
F_138 ( V_2 , V_25 ) ;
F_139 ( V_11 ) ;
if ( V_68 -> V_148 )
V_68 -> V_148 -> V_149 += V_138 ;
F_140 ( V_11 , V_25 ) ;
}
static void F_141 ( struct V_150 * V_151 )
{
struct V_11 * V_11 ;
if ( V_152 )
V_11 = F_142 ( V_151 ) ;
else
V_11 = F_143 ( (struct V_153 * ) V_151 , struct V_11 , V_111 ) ;
F_134 ( V_11 -> V_146 , V_11 ) ;
}
static void F_144 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_150 * V_154 ;
if ( V_152 ) {
int V_25 = F_73 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_35 ( V_2 -> V_26 != sizeof( * V_154 ) ) ;
V_154 = F_15 ( V_11 ) + V_16 ;
} else {
V_154 = ( void * ) & V_11 -> V_111 ;
}
F_145 ( V_154 , F_141 ) ;
} else
F_134 ( V_2 , V_11 ) ;
}
static void F_146 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_106 ( V_2 , F_129 ( V_11 ) , V_11 -> V_14 ) ;
F_144 ( V_2 , V_11 ) ;
}
static inline void
F_147 ( struct V_9 * V_40 , struct V_11 * V_11 , int V_155 )
{
V_40 -> V_156 ++ ;
if ( V_155 == V_157 )
F_148 ( & V_11 -> V_111 , & V_40 -> V_158 ) ;
else
F_96 ( & V_11 -> V_111 , & V_40 -> V_158 ) ;
}
static inline void F_149 ( struct V_9 * V_40 ,
struct V_11 * V_11 , int V_155 )
{
F_95 ( & V_40 -> V_110 ) ;
F_147 ( V_40 , V_11 , V_155 ) ;
}
static inline void
F_150 ( struct V_9 * V_40 , struct V_11 * V_11 )
{
F_98 ( & V_11 -> V_111 ) ;
V_40 -> V_156 -- ;
}
static inline void F_151 ( struct V_9 * V_40 ,
struct V_11 * V_11 )
{
F_95 ( & V_40 -> V_110 ) ;
F_150 ( V_40 , V_11 ) ;
}
static inline void * F_152 ( struct V_1 * V_2 ,
struct V_9 * V_40 , struct V_11 * V_11 ,
int V_159 , int * V_14 )
{
void * V_44 ;
unsigned long V_35 ;
struct V_11 V_160 ;
F_95 ( & V_40 -> V_110 ) ;
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
F_35 ( V_160 . V_36 ) ;
V_160 . V_36 = 1 ;
if ( ! F_34 ( V_2 , V_11 ,
V_44 , V_35 ,
V_160 . V_44 , V_160 . V_35 ,
L_47 ) )
return NULL ;
F_151 ( V_40 , V_11 ) ;
F_153 ( ! V_44 ) ;
return V_44 ;
}
static void * F_154 ( struct V_1 * V_2 , struct V_9 * V_40 ,
struct V_161 * V_162 , T_5 V_3 )
{
struct V_11 * V_11 , * V_163 ;
void * V_12 = NULL ;
int V_164 = 0 ;
int V_14 ;
if ( ! V_40 || ! V_40 -> V_156 )
return NULL ;
F_155 ( & V_40 -> V_110 ) ;
F_156 (page, page2, &n->partial, lru) {
void * V_73 ;
if ( ! F_157 ( V_11 , V_3 ) )
continue;
V_73 = F_152 ( V_2 , V_40 , V_11 , V_12 == NULL , & V_14 ) ;
if ( ! V_73 )
break;
V_164 += V_14 ;
if ( ! V_12 ) {
V_162 -> V_11 = V_11 ;
F_10 ( V_2 , V_165 ) ;
V_12 = V_73 ;
} else {
F_158 ( V_2 , V_11 , 0 ) ;
F_10 ( V_2 , V_166 ) ;
}
if ( ! F_4 ( V_2 )
|| V_164 > V_2 -> V_167 / 2 )
break;
}
F_159 ( & V_40 -> V_110 ) ;
return V_12 ;
}
static void * F_160 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_161 * V_162 )
{
#ifdef F_161
struct V_168 * V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_171 ;
enum V_172 V_173 = F_162 ( V_3 ) ;
void * V_12 ;
unsigned int V_174 ;
if ( ! V_2 -> V_175 ||
F_163 () % 1024 > V_2 -> V_175 )
return NULL ;
do {
V_174 = F_164 () ;
V_168 = F_165 ( F_166 () , V_3 ) ;
F_167 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_40 ;
V_40 = F_13 ( V_2 , F_168 ( V_171 ) ) ;
if ( V_40 && F_169 ( V_171 , V_3 ) &&
V_40 -> V_156 > V_2 -> V_176 ) {
V_12 = F_154 ( V_2 , V_40 , V_162 , V_3 ) ;
if ( V_12 ) {
F_170 ( V_174 ) ;
return V_12 ;
}
}
}
} while ( ! F_170 ( V_174 ) );
#endif
return NULL ;
}
static void * F_171 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_161 * V_162 )
{
void * V_12 ;
int V_177 = ( V_10 == V_128 ) ? F_172 () : V_10 ;
V_12 = F_154 ( V_2 , F_13 ( V_2 , V_177 ) , V_162 , V_3 ) ;
if ( V_12 || V_10 != V_128 )
return V_12 ;
return F_160 ( V_2 , V_3 , V_162 ) ;
}
static inline unsigned long F_173 ( unsigned long V_178 )
{
return V_178 + V_179 ;
}
static inline unsigned int F_174 ( unsigned long V_178 )
{
return V_178 % V_179 ;
}
static inline unsigned long F_175 ( unsigned long V_178 )
{
return V_178 / V_179 ;
}
static inline unsigned int F_176 ( int V_66 )
{
return V_66 ;
}
static inline void F_177 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_178 )
{
#ifdef F_40
unsigned long V_180 = F_178 ( V_2 -> V_8 -> V_178 ) ;
F_41 ( V_46 L_48 , V_40 , V_2 -> V_47 ) ;
#ifdef F_179
if ( F_174 ( V_178 ) != F_174 ( V_180 ) )
F_41 ( L_49 ,
F_174 ( V_178 ) , F_174 ( V_180 ) ) ;
else
#endif
if ( F_175 ( V_178 ) != F_175 ( V_180 ) )
F_41 ( L_50 ,
F_175 ( V_178 ) , F_175 ( V_180 ) ) ;
else
F_41 ( L_51 ,
V_180 , V_178 , F_173 ( V_178 ) ) ;
#endif
F_10 ( V_2 , V_181 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
int V_66 ;
F_181 (cpu)
F_182 ( V_2 -> V_8 , V_66 ) -> V_178 = F_176 ( V_66 ) ;
}
static void F_183 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_44 )
{
enum T_8 { V_182 , V_183 , V_184 , V_185 };
struct V_9 * V_40 = F_13 ( V_2 , F_129 ( V_11 ) ) ;
int V_186 = 0 ;
enum T_8 V_187 = V_182 , V_188 = V_182 ;
void * V_189 ;
int V_155 = V_190 ;
struct V_11 V_160 ;
struct V_11 V_191 ;
if ( V_11 -> V_44 ) {
F_10 ( V_2 , V_192 ) ;
V_155 = V_157 ;
}
while ( V_44 && ( V_189 = F_16 ( V_2 , V_44 ) ) ) {
void * V_193 ;
unsigned long V_35 ;
do {
V_193 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
F_22 ( V_2 , V_44 , V_193 ) ;
V_160 . V_35 = V_35 ;
V_160 . V_24 -- ;
F_35 ( ! V_160 . V_36 ) ;
} while ( ! F_34 ( V_2 , V_11 ,
V_193 , V_35 ,
V_44 , V_160 . V_35 ,
L_52 ) );
V_44 = V_189 ;
}
V_194:
V_191 . V_44 = V_11 -> V_44 ;
V_191 . V_35 = V_11 -> V_35 ;
F_35 ( ! V_191 . V_36 ) ;
V_160 . V_35 = V_191 . V_35 ;
if ( V_44 ) {
V_160 . V_24 -- ;
F_22 ( V_2 , V_44 , V_191 . V_44 ) ;
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
F_155 ( & V_40 -> V_110 ) ;
}
} else {
V_188 = V_184 ;
if ( F_1 ( V_2 ) && ! V_186 ) {
V_186 = 1 ;
F_155 ( & V_40 -> V_110 ) ;
}
}
if ( V_187 != V_188 ) {
if ( V_187 == V_183 )
F_151 ( V_40 , V_11 ) ;
else if ( V_187 == V_184 )
F_97 ( V_2 , V_40 , V_11 ) ;
if ( V_188 == V_183 ) {
F_149 ( V_40 , V_11 , V_155 ) ;
F_10 ( V_2 , V_155 ) ;
} else if ( V_188 == V_184 ) {
F_10 ( V_2 , V_195 ) ;
F_94 ( V_2 , V_40 , V_11 ) ;
}
}
V_187 = V_188 ;
if ( ! F_34 ( V_2 , V_11 ,
V_191 . V_44 , V_191 . V_35 ,
V_160 . V_44 , V_160 . V_35 ,
L_53 ) )
goto V_194;
if ( V_186 )
F_159 ( & V_40 -> V_110 ) ;
if ( V_188 == V_185 ) {
F_10 ( V_2 , V_196 ) ;
F_146 ( V_2 , V_11 ) ;
F_10 ( V_2 , V_197 ) ;
}
}
static void F_184 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
#ifdef F_5
struct V_9 * V_40 = NULL , * V_198 = NULL ;
struct V_11 * V_11 , * V_199 = NULL ;
while ( ( V_11 = V_162 -> V_158 ) ) {
struct V_11 V_160 ;
struct V_11 V_191 ;
V_162 -> V_158 = V_11 -> V_200 ;
V_198 = F_13 ( V_2 , F_129 ( V_11 ) ) ;
if ( V_40 != V_198 ) {
if ( V_40 )
F_159 ( & V_40 -> V_110 ) ;
V_40 = V_198 ;
F_155 ( & V_40 -> V_110 ) ;
}
do {
V_191 . V_44 = V_11 -> V_44 ;
V_191 . V_35 = V_11 -> V_35 ;
F_35 ( ! V_191 . V_36 ) ;
V_160 . V_35 = V_191 . V_35 ;
V_160 . V_44 = V_191 . V_44 ;
V_160 . V_36 = 0 ;
} while ( ! F_34 ( V_2 , V_11 ,
V_191 . V_44 , V_191 . V_35 ,
V_160 . V_44 , V_160 . V_35 ,
L_53 ) );
if ( F_3 ( ! V_160 . V_24 && V_40 -> V_156 > V_2 -> V_176 ) ) {
V_11 -> V_200 = V_199 ;
V_199 = V_11 ;
} else {
F_149 ( V_40 , V_11 , V_157 ) ;
F_10 ( V_2 , V_201 ) ;
}
}
if ( V_40 )
F_159 ( & V_40 -> V_110 ) ;
while ( V_199 ) {
V_11 = V_199 ;
V_199 = V_199 -> V_200 ;
F_10 ( V_2 , V_196 ) ;
F_146 ( V_2 , V_11 ) ;
F_10 ( V_2 , V_197 ) ;
}
#endif
}
static void F_158 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_202 )
{
#ifdef F_5
struct V_11 * V_203 ;
int V_138 ;
int V_204 ;
do {
V_138 = 0 ;
V_204 = 0 ;
V_203 = F_185 ( V_2 -> V_8 -> V_158 ) ;
if ( V_203 ) {
V_204 = V_203 -> V_204 ;
V_138 = V_203 -> V_138 ;
if ( V_202 && V_204 > V_2 -> V_167 ) {
unsigned long V_3 ;
F_43 ( V_3 ) ;
F_184 ( V_2 , F_186 ( V_2 -> V_8 ) ) ;
F_44 ( V_3 ) ;
V_203 = NULL ;
V_204 = 0 ;
V_138 = 0 ;
F_10 ( V_2 , V_205 ) ;
}
}
V_138 ++ ;
V_204 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_138 = V_138 ;
V_11 -> V_204 = V_204 ;
V_11 -> V_200 = V_203 ;
} while ( F_187 ( V_2 -> V_8 -> V_158 , V_203 , V_11 )
!= V_203 );
#endif
}
static inline void F_188 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
F_10 ( V_2 , V_206 ) ;
F_183 ( V_2 , V_162 -> V_11 , V_162 -> V_44 ) ;
V_162 -> V_178 = F_173 ( V_162 -> V_178 ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
}
static inline void F_189 ( struct V_1 * V_2 , int V_66 )
{
struct V_161 * V_162 = F_182 ( V_2 -> V_8 , V_66 ) ;
if ( F_103 ( V_162 ) ) {
if ( V_162 -> V_11 )
F_188 ( V_2 , V_162 ) ;
F_184 ( V_2 , V_162 ) ;
}
}
static void F_190 ( void * V_207 )
{
struct V_1 * V_2 = V_207 ;
F_189 ( V_2 , F_53 () ) ;
}
static bool F_191 ( int V_66 , void * V_208 )
{
struct V_1 * V_2 = V_208 ;
struct V_161 * V_162 = F_182 ( V_2 -> V_8 , V_66 ) ;
return V_162 -> V_11 || V_162 -> V_158 ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_193 ( F_191 , F_190 , V_2 , 1 , V_209 ) ;
}
static inline int F_194 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_161
if ( ! V_11 || ( V_10 != V_128 && F_129 ( V_11 ) != V_10 ) )
return 0 ;
#endif
return 1 ;
}
static int F_195 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static unsigned long F_196 ( struct V_9 * V_40 ,
int (* F_197)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_198 ( & V_40 -> V_110 , V_3 ) ;
F_199 (page, &n->partial, lru)
V_29 += F_197 ( V_11 ) ;
F_200 ( & V_40 -> V_110 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_201 ( struct V_9 * V_40 )
{
#ifdef F_2
return F_100 ( & V_40 -> V_114 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_202 ( struct V_1 * V_2 , T_5 V_210 , int V_211 )
{
int V_10 ;
F_41 ( V_212
L_54 ,
V_211 , V_210 ) ;
F_41 ( V_212 L_55
L_56 , V_2 -> V_47 , V_2 -> V_21 ,
V_2 -> V_15 , F_27 ( V_2 -> V_126 ) , F_27 ( V_2 -> V_134 ) ) ;
if ( F_27 ( V_2 -> V_134 ) > F_203 ( V_2 -> V_21 ) )
F_41 ( V_212 L_57
L_58 , V_2 -> V_47 ) ;
F_204 (node) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
unsigned long V_113 ;
unsigned long V_213 ;
unsigned long V_214 ;
if ( ! V_40 )
continue;
V_214 = F_196 ( V_40 , F_195 ) ;
V_113 = F_101 ( V_40 ) ;
V_213 = F_201 ( V_40 ) ;
F_41 ( V_212
L_59 ,
V_10 , V_113 , V_213 , V_214 ) ;
}
}
static inline void * F_205 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_161 * * V_215 )
{
void * V_44 ;
struct V_161 * V_162 = * V_215 ;
struct V_11 * V_11 ;
V_44 = F_171 ( V_2 , V_3 , V_10 , V_162 ) ;
if ( V_44 )
return V_44 ;
V_11 = F_127 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_162 = F_206 ( V_2 -> V_8 ) ;
if ( V_162 -> V_11 )
F_188 ( V_2 , V_162 ) ;
V_44 = V_11 -> V_44 ;
V_11 -> V_44 = NULL ;
F_10 ( V_2 , V_216 ) ;
V_162 -> V_11 = V_11 ;
* V_215 = V_162 ;
} else
V_44 = NULL ;
return V_44 ;
}
static inline bool F_157 ( struct V_11 * V_11 , T_5 V_210 )
{
if ( F_3 ( F_207 ( V_11 ) ) )
return F_208 ( V_210 ) ;
return true ;
}
static inline void * F_209 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_160 ;
unsigned long V_35 ;
void * V_44 ;
do {
V_44 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
V_160 . V_35 = V_35 ;
F_35 ( ! V_160 . V_36 ) ;
V_160 . V_24 = V_11 -> V_14 ;
V_160 . V_36 = V_44 != NULL ;
} while ( ! F_34 ( V_2 , V_11 ,
V_44 , V_35 ,
NULL , V_160 . V_35 ,
L_60 ) );
return V_44 ;
}
static void * F_210 ( struct V_1 * V_2 , T_5 V_210 , int V_10 ,
unsigned long V_18 , struct V_161 * V_162 )
{
void * V_44 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_43 ( V_3 ) ;
#ifdef F_179
V_162 = F_186 ( V_2 -> V_8 ) ;
#endif
V_11 = V_162 -> V_11 ;
if ( ! V_11 )
goto F_127;
V_194:
if ( F_3 ( ! F_194 ( V_11 , V_10 ) ) ) {
F_10 ( V_2 , V_217 ) ;
F_183 ( V_2 , V_11 , V_162 -> V_44 ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
goto F_127;
}
if ( F_3 ( ! F_157 ( V_11 , V_210 ) ) ) {
F_183 ( V_2 , V_11 , V_162 -> V_44 ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
goto F_127;
}
V_44 = V_162 -> V_44 ;
if ( V_44 )
goto V_218;
F_10 ( V_2 , V_219 ) ;
V_44 = F_209 ( V_2 , V_11 ) ;
if ( ! V_44 ) {
V_162 -> V_11 = NULL ;
F_10 ( V_2 , V_220 ) ;
goto F_127;
}
F_10 ( V_2 , V_221 ) ;
V_218:
F_35 ( ! V_162 -> V_11 -> V_36 ) ;
V_162 -> V_44 = F_16 ( V_2 , V_44 ) ;
V_162 -> V_178 = F_173 ( V_162 -> V_178 ) ;
F_44 ( V_3 ) ;
return V_44 ;
F_127:
if ( V_162 -> V_158 ) {
V_11 = V_162 -> V_11 = V_162 -> V_158 ;
V_162 -> V_158 = V_11 -> V_200 ;
F_10 ( V_2 , V_222 ) ;
V_162 -> V_44 = NULL ;
goto V_194;
}
V_44 = F_205 ( V_2 , V_210 , V_10 , & V_162 ) ;
if ( F_3 ( ! V_44 ) ) {
if ( ! ( V_210 & V_131 ) && F_211 () )
F_202 ( V_2 , V_210 , V_10 ) ;
F_44 ( V_3 ) ;
return NULL ;
}
V_11 = V_162 -> V_11 ;
if ( F_103 ( ! F_1 ( V_2 ) && F_157 ( V_11 , V_210 ) ) )
goto V_218;
if ( F_1 ( V_2 ) &&
! F_110 ( V_2 , V_11 , V_44 , V_18 ) )
goto F_127;
F_183 ( V_2 , V_11 , F_16 ( V_2 , V_44 ) ) ;
V_162 -> V_11 = NULL ;
V_162 -> V_44 = NULL ;
F_44 ( V_3 ) ;
return V_44 ;
}
static T_2 void * F_212 ( struct V_1 * V_2 ,
T_5 V_210 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_161 * V_162 ;
struct V_11 * V_11 ;
unsigned long V_178 ;
if ( F_82 ( V_2 , V_210 ) )
return NULL ;
V_2 = F_213 ( V_2 , V_210 ) ;
V_194:
F_214 () ;
V_162 = F_206 ( V_2 -> V_8 ) ;
V_178 = V_162 -> V_178 ;
F_215 () ;
V_12 = V_162 -> V_44 ;
V_11 = V_162 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_194 ( V_11 , V_10 ) ) )
V_12 = F_210 ( V_2 , V_210 , V_10 , V_18 , V_162 ) ;
else {
void * V_223 = F_19 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_216 (
V_2 -> V_8 -> V_44 , V_2 -> V_8 -> V_178 ,
V_12 , V_178 ,
V_223 , F_173 ( V_178 ) ) ) ) {
F_177 ( L_61 , V_2 , V_178 ) ;
goto V_194;
}
F_17 ( V_2 , V_223 ) ;
F_10 ( V_2 , V_224 ) ;
}
if ( F_3 ( V_210 & V_225 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_86 ( V_2 , V_210 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_217 ( struct V_1 * V_2 ,
T_5 V_210 , unsigned long V_18 )
{
return F_212 ( V_2 , V_210 , V_128 , V_18 ) ;
}
void * F_218 ( struct V_1 * V_2 , T_5 V_210 )
{
void * V_226 = F_217 ( V_2 , V_210 , V_227 ) ;
F_219 ( V_227 , V_226 , V_2 -> V_21 ,
V_2 -> V_15 , V_210 ) ;
return V_226 ;
}
void * F_220 ( struct V_1 * V_2 , T_5 V_210 , T_1 V_15 )
{
void * V_226 = F_217 ( V_2 , V_210 , V_227 ) ;
F_221 ( V_227 , V_226 , V_15 , V_2 -> V_15 , V_210 ) ;
return V_226 ;
}
void * F_222 ( struct V_1 * V_2 , T_5 V_210 , int V_10 )
{
void * V_226 = F_212 ( V_2 , V_210 , V_10 , V_227 ) ;
F_223 ( V_227 , V_226 ,
V_2 -> V_21 , V_2 -> V_15 , V_210 , V_10 ) ;
return V_226 ;
}
void * F_224 ( struct V_1 * V_2 ,
T_5 V_210 ,
int V_10 , T_1 V_15 )
{
void * V_226 = F_212 ( V_2 , V_210 , V_10 , V_227 ) ;
F_225 ( V_227 , V_226 ,
V_15 , V_2 -> V_15 , V_210 , V_10 ) ;
return V_226 ;
}
static void F_226 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_193 ;
void * * V_12 = ( void * ) V_29 ;
int V_228 ;
struct V_11 V_160 ;
unsigned long V_35 ;
struct V_9 * V_40 = NULL ;
unsigned long V_229 ( V_3 ) ;
F_10 ( V_2 , V_230 ) ;
if ( F_1 ( V_2 ) &&
! ( V_40 = F_114 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_40 ) ) {
F_200 ( & V_40 -> V_110 , V_3 ) ;
V_40 = NULL ;
}
V_193 = V_11 -> V_44 ;
V_35 = V_11 -> V_35 ;
F_22 ( V_2 , V_12 , V_193 ) ;
V_160 . V_35 = V_35 ;
V_228 = V_160 . V_36 ;
V_160 . V_24 -- ;
if ( ( ! V_160 . V_24 || ! V_193 ) && ! V_228 ) {
if ( F_4 ( V_2 ) && ! V_193 ) {
V_160 . V_36 = 1 ;
} else {
V_40 = F_13 ( V_2 , F_129 ( V_11 ) ) ;
F_198 ( & V_40 -> V_110 , V_3 ) ;
}
}
} while ( ! F_42 ( V_2 , V_11 ,
V_193 , V_35 ,
V_12 , V_160 . V_35 ,
L_62 ) );
if ( F_103 ( ! V_40 ) ) {
if ( V_160 . V_36 && ! V_228 ) {
F_158 ( V_2 , V_11 , 1 ) ;
F_10 ( V_2 , V_231 ) ;
}
if ( V_228 )
F_10 ( V_2 , V_232 ) ;
return;
}
if ( F_3 ( ! V_160 . V_24 && V_40 -> V_156 > V_2 -> V_176 ) )
goto V_233;
if ( ! F_4 ( V_2 ) && F_3 ( ! V_193 ) ) {
if ( F_1 ( V_2 ) )
F_97 ( V_2 , V_40 , V_11 ) ;
F_149 ( V_40 , V_11 , V_157 ) ;
F_10 ( V_2 , V_201 ) ;
}
F_200 ( & V_40 -> V_110 , V_3 ) ;
return;
V_233:
if ( V_193 ) {
F_151 ( V_40 , V_11 ) ;
F_10 ( V_2 , V_234 ) ;
} else {
F_97 ( V_2 , V_40 , V_11 ) ;
}
F_200 ( & V_40 -> V_110 , V_3 ) ;
F_10 ( V_2 , V_197 ) ;
F_146 ( V_2 , V_11 ) ;
}
static T_2 void F_227 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_161 * V_162 ;
unsigned long V_178 ;
F_89 ( V_2 , V_29 ) ;
V_194:
F_214 () ;
V_162 = F_206 ( V_2 -> V_8 ) ;
V_178 = V_162 -> V_178 ;
F_215 () ;
if ( F_103 ( V_11 == V_162 -> V_11 ) ) {
F_22 ( V_2 , V_12 , V_162 -> V_44 ) ;
if ( F_3 ( ! F_216 (
V_2 -> V_8 -> V_44 , V_2 -> V_8 -> V_178 ,
V_162 -> V_44 , V_178 ,
V_12 , F_173 ( V_178 ) ) ) ) {
F_177 ( L_63 , V_2 , V_178 ) ;
goto V_194;
}
F_10 ( V_2 , V_235 ) ;
} else
F_226 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_228 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_229 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_227 ( V_2 , F_142 ( V_29 ) , V_29 , V_227 ) ;
F_230 ( V_227 , V_29 ) ;
}
static inline int F_231 ( int V_15 , int V_236 ,
int V_237 , int V_238 , int V_26 )
{
int V_25 ;
int V_239 ;
int V_240 = V_241 ;
if ( F_25 ( V_240 , V_15 , V_26 ) > V_102 )
return F_203 ( V_15 * V_102 ) - 1 ;
for ( V_25 = F_232 ( V_240 ,
F_233 ( V_236 * V_15 - 1 ) - V_242 ) ;
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
static inline int F_234 ( int V_15 , int V_26 )
{
int V_25 ;
int V_236 ;
int V_244 ;
int V_101 ;
V_236 = V_245 ;
if ( ! V_236 )
V_236 = 4 * ( F_233 ( V_246 ) + 1 ) ;
V_101 = F_25 ( V_247 , V_15 , V_26 ) ;
V_236 = V_134 ( V_236 , V_101 ) ;
while ( V_236 > 1 ) {
V_244 = 16 ;
while ( V_244 >= 4 ) {
V_25 = F_231 ( V_15 , V_236 ,
V_247 , V_244 , V_26 ) ;
if ( V_25 <= V_247 )
return V_25 ;
V_244 /= 2 ;
}
V_236 -- ;
}
V_25 = F_231 ( V_15 , 1 , V_247 , 1 , V_26 ) ;
if ( V_25 <= V_247 )
return V_25 ;
V_25 = F_231 ( V_15 , 1 , V_248 , 1 , V_26 ) ;
if ( V_25 < V_248 )
return V_25 ;
return - V_249 ;
}
static void
F_235 ( struct V_9 * V_40 )
{
V_40 -> V_156 = 0 ;
F_236 ( & V_40 -> V_110 ) ;
F_237 ( & V_40 -> V_158 ) ;
#ifdef F_2
F_238 ( & V_40 -> V_113 , 0 ) ;
F_238 ( & V_40 -> V_114 , 0 ) ;
F_237 ( & V_40 -> V_112 ) ;
#endif
}
static inline int F_239 ( struct V_1 * V_2 )
{
F_240 ( V_250 <
V_251 * sizeof( struct V_161 ) ) ;
V_2 -> V_8 = F_241 ( sizeof( struct V_161 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_180 ( V_2 ) ;
return 1 ;
}
static void F_242 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_40 ;
F_128 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_127 ( V_9 , V_252 , V_10 ) ;
F_128 ( ! V_11 ) ;
if ( F_129 ( V_11 ) != V_10 ) {
F_41 ( V_51 L_64
L_65 , V_10 ) ;
F_41 ( V_51 L_66
L_67 ) ;
}
V_40 = V_11 -> V_44 ;
F_128 ( ! V_40 ) ;
V_11 -> V_44 = F_16 ( V_9 , V_40 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_36 = 0 ;
V_9 -> V_10 [ V_10 ] = V_40 ;
#ifdef F_2
F_67 ( V_9 , V_40 , V_97 ) ;
F_54 ( V_9 , V_40 ) ;
#endif
F_235 ( V_40 ) ;
F_102 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_147 ( V_40 , V_11 , V_190 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
int V_10 ;
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = V_2 -> V_10 [ V_10 ] ;
if ( V_40 )
F_228 ( V_9 , V_40 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_245 ( struct V_1 * V_2 )
{
int V_10 ;
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 ;
if ( V_253 == V_254 ) {
F_242 ( V_10 ) ;
continue;
}
V_40 = F_222 ( V_9 ,
V_255 , V_10 ) ;
if ( ! V_40 ) {
F_243 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_40 ;
F_235 ( V_40 ) ;
}
return 1 ;
}
static void F_246 ( struct V_1 * V_2 , unsigned long V_134 )
{
if ( V_134 < V_256 )
V_134 = V_256 ;
else if ( V_134 > V_257 )
V_134 = V_257 ;
V_2 -> V_176 = V_134 ;
}
static int F_247 ( struct V_1 * V_2 , int V_258 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_248 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_113 )
V_2 -> V_3 |= V_81 ;
else
V_2 -> V_3 &= ~ V_81 ;
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
V_15 += 2 * sizeof( struct V_53 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_15 = F_248 ( V_15 , V_2 -> V_259 ) ;
V_2 -> V_15 = V_15 ;
if ( V_258 >= 0 )
V_25 = V_258 ;
else
V_25 = F_234 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_130 = 0 ;
if ( V_25 )
V_2 -> V_130 |= V_260 ;
if ( V_2 -> V_3 & V_261 )
V_2 -> V_130 |= V_262 ;
if ( V_2 -> V_3 & V_139 )
V_2 -> V_130 |= V_263 ;
V_2 -> V_126 = F_26 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_134 = F_26 ( F_203 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_28 ( V_2 -> V_126 ) > F_28 ( V_2 -> F_232 ) )
V_2 -> F_232 = V_2 -> V_126 ;
return ! ! F_28 ( V_2 -> V_126 ) ;
}
static int F_249 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_112 ( V_2 -> V_15 , V_3 , V_2 -> V_47 , V_2 -> F_113 ) ;
V_2 -> V_26 = 0 ;
if ( V_152 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_150 ) ;
if ( ! F_247 ( V_2 , - 1 ) )
goto error;
if ( V_122 ) {
if ( F_203 ( V_2 -> V_15 ) > F_203 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_264 ;
V_2 -> V_16 = 0 ;
if ( ! F_247 ( V_2 , - 1 ) )
goto error;
}
}
#if F_37 ( V_41 ) && \
F_37 ( V_42 )
if ( F_250 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_43 ;
#endif
F_246 ( V_2 , F_251 ( V_2 -> V_15 ) / 2 ) ;
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
#ifdef F_161
V_2 -> V_175 = 1000 ;
#endif
if ( ! F_245 ( V_2 ) )
goto error;
if ( F_239 ( V_2 ) )
return 0 ;
F_243 ( V_2 ) ;
error:
if ( V_3 & V_265 )
F_252 ( L_68
L_69 ,
V_2 -> V_47 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 ,
F_27 ( V_2 -> V_126 ) , V_2 -> V_16 , V_3 ) ;
return - V_266 ;
}
static void F_253 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_49 )
{
#ifdef F_2
void * V_18 = F_15 ( V_11 ) ;
void * V_5 ;
unsigned long * V_48 = F_254 ( F_255 ( V_11 -> V_14 ) *
sizeof( long ) , V_209 ) ;
if ( ! V_48 )
return;
F_66 ( V_2 , V_11 , V_49 , V_2 -> V_47 ) ;
F_29 ( V_11 ) ;
F_45 ( V_2 , V_11 , V_48 ) ;
F_133 (p, s, addr, page->objects) {
if ( ! F_256 ( F_23 ( V_5 , V_2 , V_18 ) , V_48 ) ) {
F_41 ( V_51 L_70 ,
V_5 , V_5 - V_18 ) ;
F_56 ( V_2 , V_5 ) ;
}
}
F_31 ( V_11 ) ;
F_257 ( V_48 ) ;
#endif
}
static void F_258 ( struct V_1 * V_2 , struct V_9 * V_40 )
{
struct V_11 * V_11 , * V_151 ;
F_156 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_150 ( V_40 , V_11 ) ;
F_146 ( V_2 , V_11 ) ;
} else {
F_253 ( V_2 , V_11 ,
L_71 ) ;
}
}
}
static inline int F_259 ( struct V_1 * V_2 )
{
int V_10 ;
F_192 ( V_2 ) ;
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
F_258 ( V_2 , V_40 ) ;
if ( V_40 -> V_156 || F_99 ( V_2 , V_10 ) )
return 1 ;
}
F_260 ( V_2 -> V_8 ) ;
F_243 ( V_2 ) ;
return 0 ;
}
int F_261 ( struct V_1 * V_2 )
{
int V_267 = F_259 ( V_2 ) ;
if ( ! V_267 ) {
F_262 ( & V_268 ) ;
F_8 ( V_2 ) ;
F_263 ( & V_268 ) ;
}
return V_267 ;
}
static int T_7 F_264 ( char * V_117 )
{
F_265 ( & V_117 , & V_241 ) ;
return 1 ;
}
static int T_7 F_266 ( char * V_117 )
{
F_265 ( & V_117 , & V_247 ) ;
V_247 = V_134 ( V_247 , V_248 - 1 ) ;
return 1 ;
}
static int T_7 F_267 ( char * V_117 )
{
F_265 ( & V_117 , & V_245 ) ;
return 1 ;
}
static int T_7 F_268 ( char * V_117 )
{
V_269 = 1 ;
return 1 ;
}
void * F_269 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_270 ) )
return F_270 ( V_15 , V_3 ) ;
V_2 = F_271 ( V_15 , V_3 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_226 = F_217 ( V_2 , V_3 , V_227 ) ;
F_221 ( V_227 , V_226 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_226 ;
}
static void * F_273 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_104 = NULL ;
V_3 |= V_260 | V_127 | V_271 ;
V_11 = F_274 ( V_10 , V_3 , F_203 ( V_15 ) ) ;
if ( V_11 )
V_104 = F_15 ( V_11 ) ;
F_78 ( V_104 , V_15 , V_3 ) ;
return V_104 ;
}
void * F_275 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_270 ) ) {
V_226 = F_273 ( V_15 , V_3 , V_10 ) ;
F_225 ( V_227 , V_226 ,
V_15 , V_27 << F_203 ( V_15 ) ,
V_3 , V_10 ) ;
return V_226 ;
}
V_2 = F_271 ( V_15 , V_3 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_226 = F_212 ( V_2 , V_3 , V_10 , V_227 ) ;
F_225 ( V_227 , V_226 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_226 ;
}
T_1 F_276 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_272 ) )
return 0 ;
V_11 = F_142 ( V_12 ) ;
if ( F_3 ( ! F_76 ( V_11 ) ) ) {
F_153 ( ! F_277 ( V_11 ) ) ;
return V_27 << F_73 ( V_11 ) ;
}
return F_24 ( V_11 -> V_146 ) ;
}
void F_257 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_278 ( V_227 , V_29 ) ;
if ( F_3 ( F_272 ( V_29 ) ) )
return;
V_11 = F_142 ( V_29 ) ;
if ( F_3 ( ! F_76 ( V_11 ) ) ) {
F_128 ( ! F_277 ( V_11 ) ) ;
F_80 ( V_29 ) ;
F_140 ( V_11 , F_73 ( V_11 ) ) ;
return;
}
F_227 ( V_11 -> V_146 , V_11 , V_12 , V_227 ) ;
}
int F_279 ( struct V_1 * V_2 )
{
int V_10 ;
int V_58 ;
struct V_9 * V_40 ;
struct V_11 * V_11 ;
struct V_11 * V_73 ;
int V_14 = F_28 ( V_2 -> F_232 ) ;
struct V_153 * V_273 =
F_280 ( sizeof( struct V_153 ) * V_14 , V_255 ) ;
unsigned long V_3 ;
if ( ! V_273 )
return - V_274 ;
F_192 ( V_2 ) ;
F_244 (node, N_NORMAL_MEMORY) {
V_40 = F_13 ( V_2 , V_10 ) ;
if ( ! V_40 -> V_156 )
continue;
for ( V_58 = 0 ; V_58 < V_14 ; V_58 ++ )
F_237 ( V_273 + V_58 ) ;
F_198 ( & V_40 -> V_110 , V_3 ) ;
F_156 (page, t, &n->partial, lru) {
F_281 ( & V_11 -> V_111 , V_273 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_40 -> V_156 -- ;
}
for ( V_58 = V_14 - 1 ; V_58 > 0 ; V_58 -- )
F_282 ( V_273 + V_58 , V_40 -> V_158 . V_275 ) ;
F_200 ( & V_40 -> V_110 , V_3 ) ;
F_156 (page, t, slabs_by_inuse, lru)
F_146 ( V_2 , V_11 ) ;
}
F_257 ( V_273 ) ;
return 0 ;
}
static int F_283 ( void * V_276 )
{
struct V_1 * V_2 ;
F_263 ( & V_268 ) ;
F_199 (s, &slab_caches, list)
F_279 ( V_2 ) ;
F_262 ( & V_268 ) ;
return 0 ;
}
static void F_284 ( void * V_276 )
{
struct V_9 * V_40 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = V_276 ;
int V_279 ;
V_279 = V_278 -> V_280 ;
if ( V_279 < 0 )
return;
F_263 ( & V_268 ) ;
F_199 (s, &slab_caches, list) {
V_40 = F_13 ( V_2 , V_279 ) ;
if ( V_40 ) {
F_128 ( F_99 ( V_2 , V_279 ) ) ;
V_2 -> V_10 [ V_279 ] = NULL ;
F_228 ( V_9 , V_40 ) ;
}
}
F_262 ( & V_268 ) ;
}
static int F_285 ( void * V_276 )
{
struct V_9 * V_40 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = V_276 ;
int V_211 = V_278 -> V_280 ;
int V_226 = 0 ;
if ( V_211 < 0 )
return 0 ;
F_263 ( & V_268 ) ;
F_199 (s, &slab_caches, list) {
V_40 = F_218 ( V_9 , V_255 ) ;
if ( ! V_40 ) {
V_226 = - V_274 ;
goto V_120;
}
F_235 ( V_40 ) ;
V_2 -> V_10 [ V_211 ] = V_40 ;
}
V_120:
F_262 ( & V_268 ) ;
return V_226 ;
}
static int F_286 ( struct V_281 * V_282 ,
unsigned long V_283 , void * V_276 )
{
int V_226 = 0 ;
switch ( V_283 ) {
case V_284 :
V_226 = F_285 ( V_276 ) ;
break;
case V_285 :
V_226 = F_283 ( V_276 ) ;
break;
case V_286 :
case V_287 :
F_284 ( V_276 ) ;
break;
case V_288 :
case V_289 :
break;
}
if ( V_226 )
V_226 = F_287 ( V_226 ) ;
else
V_226 = V_290 ;
return V_226 ;
}
static struct V_1 * T_7 F_288 ( struct V_1 * V_291 )
{
int V_10 ;
struct V_1 * V_2 = F_289 ( V_1 , V_252 ) ;
memcpy ( V_2 , V_291 , V_1 -> V_21 ) ;
F_189 ( V_2 , F_53 () ) ;
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_40 ) {
F_199 (p, &n->partial, lru)
V_5 -> V_146 = V_2 ;
#ifdef F_2
F_199 (p, &n->full, lru)
V_5 -> V_146 = V_2 ;
#endif
}
}
F_96 ( & V_2 -> V_292 , & V_293 ) ;
return V_2 ;
}
void T_7 F_290 ( void )
{
static V_294 struct V_1 V_295 ,
V_296 ;
if ( F_291 () )
V_247 = 0 ;
V_9 = & V_296 ;
V_1 = & V_295 ;
F_292 ( V_9 , L_72 ,
sizeof( struct V_9 ) , V_297 ) ;
F_293 ( & V_298 ) ;
V_253 = V_299 ;
F_292 ( V_1 , L_73 ,
F_294 ( struct V_1 , V_10 ) +
V_300 * sizeof( struct V_9 * ) ,
V_297 ) ;
V_1 = F_288 ( & V_295 ) ;
V_9 = F_288 ( & V_296 ) ;
F_295 ( 0 ) ;
#ifdef F_296
F_297 ( & V_301 ) ;
#endif
F_41 ( V_46
L_74
L_75 ,
F_298 () ,
V_241 , V_247 , V_245 ,
V_246 , V_300 ) ;
}
void T_7 F_299 ( void )
{
}
static int F_300 ( struct V_1 * V_2 )
{
if ( V_269 || ( V_2 -> V_3 & V_302 ) )
return 1 ;
if ( V_2 -> F_113 )
return 1 ;
if ( V_2 -> V_303 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_301 ( struct V_304 * V_305 , T_1 V_15 ,
T_1 V_259 , unsigned long V_3 , const char * V_47 ,
void (* F_113)( void * ) )
{
struct V_1 * V_2 ;
if ( V_269 || ( V_3 & V_302 ) )
return NULL ;
if ( F_113 )
return NULL ;
V_15 = F_248 ( V_15 , sizeof( void * ) ) ;
V_259 = F_302 ( V_3 , V_259 , V_15 ) ;
V_15 = F_248 ( V_15 , V_259 ) ;
V_3 = F_112 ( V_15 , V_3 , V_47 , NULL ) ;
F_199 (s, &slab_caches, list) {
if ( F_300 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_306 ) != ( V_2 -> V_3 & V_306 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_259 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
if ( ! F_303 ( V_2 , V_305 ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_304 ( struct V_304 * V_305 , const char * V_47 , T_1 V_15 ,
T_1 V_259 , unsigned long V_3 , void (* F_113)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_301 ( V_305 , V_15 , V_259 , V_3 , V_47 , F_113 ) ;
if ( V_2 ) {
V_2 -> V_303 ++ ;
V_2 -> V_21 = F_232 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_305 ( int , V_2 -> V_24 , F_248 ( V_15 , sizeof( void * ) ) ) ;
if ( F_7 ( V_2 , V_47 ) ) {
V_2 -> V_303 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_306 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_307 ;
V_307 = F_249 ( V_2 , V_3 ) ;
if ( V_307 )
return V_307 ;
if ( V_253 <= V_308 )
return 0 ;
F_9 ( V_2 ) ;
F_262 ( & V_268 ) ;
V_307 = F_6 ( V_2 ) ;
F_263 ( & V_268 ) ;
if ( V_307 )
F_259 ( V_2 ) ;
return V_307 ;
}
static int F_307 ( struct V_281 * V_309 ,
unsigned long V_283 , void * V_310 )
{
long V_66 = ( long ) V_310 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_283 ) {
case V_311 :
case V_312 :
case V_313 :
case V_314 :
F_263 ( & V_268 ) ;
F_199 (s, &slab_caches, list) {
F_43 ( V_3 ) ;
F_189 ( V_2 , V_66 ) ;
F_44 ( V_3 ) ;
}
F_262 ( & V_268 ) ;
break;
default:
break;
}
return V_290 ;
}
void * F_308 ( T_1 V_15 , T_5 V_210 , unsigned long V_315 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_270 ) )
return F_270 ( V_15 , V_210 ) ;
V_2 = F_271 ( V_15 , V_210 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_226 = F_217 ( V_2 , V_210 , V_315 ) ;
F_221 ( V_315 , V_226 , V_15 , V_2 -> V_15 , V_210 ) ;
return V_226 ;
}
void * F_309 ( T_1 V_15 , T_5 V_210 ,
int V_10 , unsigned long V_315 )
{
struct V_1 * V_2 ;
void * V_226 ;
if ( F_3 ( V_15 > V_270 ) ) {
V_226 = F_273 ( V_15 , V_210 , V_10 ) ;
F_225 ( V_315 , V_226 ,
V_15 , V_27 << F_203 ( V_15 ) ,
V_210 , V_10 ) ;
return V_226 ;
}
V_2 = F_271 ( V_15 , V_210 ) ;
if ( F_3 ( F_272 ( V_2 ) ) )
return V_2 ;
V_226 = F_212 ( V_2 , V_210 , V_10 , V_315 ) ;
F_225 ( V_315 , V_226 , V_15 , V_2 -> V_15 , V_210 , V_10 ) ;
return V_226 ;
}
static int F_310 ( struct V_11 * V_11 )
{
return V_11 -> V_24 ;
}
static int F_311 ( struct V_11 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_312 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_48 )
{
void * V_5 ;
void * V_18 = F_15 ( V_11 ) ;
if ( ! F_75 ( V_2 , V_11 ) ||
! F_77 ( V_2 , V_11 , NULL ) )
return 0 ;
F_313 ( V_48 , V_11 -> V_14 ) ;
F_45 ( V_2 , V_11 , V_48 ) ;
F_133 (p, s, addr, page->objects) {
if ( F_256 ( F_23 ( V_5 , V_2 , V_18 ) , V_48 ) )
if ( ! F_74 ( V_2 , V_11 , V_5 , V_115 ) )
return 0 ;
}
F_133 (p, s, addr, page->objects)
if ( ! F_256 ( F_23 ( V_5 , V_2 , V_18 ) , V_48 ) )
if ( ! F_74 ( V_2 , V_11 , V_5 , V_97 ) )
return 0 ;
return 1 ;
}
static void F_314 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_48 )
{
F_29 ( V_11 ) ;
F_312 ( V_2 , V_11 , V_48 ) ;
F_31 ( V_11 ) ;
}
static int F_315 ( struct V_1 * V_2 ,
struct V_9 * V_40 , unsigned long * V_48 )
{
unsigned long V_316 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_198 ( & V_40 -> V_110 , V_3 ) ;
F_199 (page, &n->partial, lru) {
F_314 ( V_2 , V_11 , V_48 ) ;
V_316 ++ ;
}
if ( V_316 != V_40 -> V_156 )
F_41 ( V_51 L_76
L_77 , V_2 -> V_47 , V_316 , V_40 -> V_156 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_120;
F_199 (page, &n->full, lru) {
F_314 ( V_2 , V_11 , V_48 ) ;
V_316 ++ ;
}
if ( V_316 != F_100 ( & V_40 -> V_113 ) )
F_41 ( V_51 L_78
L_77 , V_2 -> V_47 , V_316 ,
F_100 ( & V_40 -> V_113 ) ) ;
V_120:
F_200 ( & V_40 -> V_110 , V_3 ) ;
return V_316 ;
}
static long F_316 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_316 = 0 ;
unsigned long * V_48 = F_280 ( F_255 ( F_28 ( V_2 -> F_232 ) ) *
sizeof( unsigned long ) , V_255 ) ;
if ( ! V_48 )
return - V_274 ;
F_192 ( V_2 ) ;
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
V_316 += F_315 ( V_2 , V_40 , V_48 ) ;
}
F_257 ( V_48 ) ;
return V_316 ;
}
static void F_317 ( struct V_317 * V_73 )
{
if ( V_73 -> F_232 )
F_318 ( ( unsigned long ) V_73 -> V_318 ,
F_203 ( sizeof( struct V_319 ) * V_73 -> F_232 ) ) ;
}
static int F_319 ( struct V_317 * V_73 , unsigned long F_232 , T_5 V_3 )
{
struct V_319 * V_187 ;
int V_25 ;
V_25 = F_203 ( sizeof( struct V_319 ) * F_232 ) ;
V_187 = ( void * ) F_320 ( V_3 , V_25 ) ;
if ( ! V_187 )
return 0 ;
if ( V_73 -> V_316 ) {
memcpy ( V_187 , V_73 -> V_318 , sizeof( struct V_319 ) * V_73 -> V_316 ) ;
F_317 ( V_73 ) ;
}
V_73 -> F_232 = F_232 ;
V_73 -> V_318 = V_187 ;
return 1 ;
}
static int F_321 ( struct V_317 * V_73 , struct V_1 * V_2 ,
const struct V_53 * V_53 )
{
long V_89 , V_93 , V_320 ;
struct V_319 * V_187 ;
unsigned long V_321 ;
unsigned long V_322 = V_70 - V_53 -> V_69 ;
V_89 = - 1 ;
V_93 = V_73 -> V_316 ;
for ( ; ; ) {
V_320 = V_89 + ( V_93 - V_89 + 1 ) / 2 ;
if ( V_320 == V_93 )
break;
V_321 = V_73 -> V_318 [ V_320 ] . V_18 ;
if ( V_53 -> V_18 == V_321 ) {
V_187 = & V_73 -> V_318 [ V_320 ] ;
V_187 -> V_316 ++ ;
if ( V_53 -> V_69 ) {
V_187 -> V_323 += V_322 ;
if ( V_322 < V_187 -> V_324 )
V_187 -> V_324 = V_322 ;
if ( V_322 > V_187 -> V_325 )
V_187 -> V_325 = V_322 ;
if ( V_53 -> V_67 < V_187 -> V_326 )
V_187 -> V_326 = V_53 -> V_67 ;
if ( V_53 -> V_67 > V_187 -> V_327 )
V_187 -> V_327 = V_53 -> V_67 ;
F_322 ( V_53 -> V_66 ,
F_323 ( V_187 -> V_328 ) ) ;
}
F_324 ( F_129 ( F_325 ( V_53 ) ) , V_187 -> V_329 ) ;
return 1 ;
}
if ( V_53 -> V_18 < V_321 )
V_93 = V_320 ;
else
V_89 = V_320 ;
}
if ( V_73 -> V_316 >= V_73 -> F_232 && ! F_319 ( V_73 , 2 * V_73 -> F_232 , V_209 ) )
return 0 ;
V_187 = V_73 -> V_318 + V_320 ;
if ( V_320 < V_73 -> V_316 )
memmove ( V_187 + 1 , V_187 ,
( V_73 -> V_316 - V_320 ) * sizeof( struct V_319 ) ) ;
V_73 -> V_316 ++ ;
V_187 -> V_316 = 1 ;
V_187 -> V_18 = V_53 -> V_18 ;
V_187 -> V_323 = V_322 ;
V_187 -> V_324 = V_322 ;
V_187 -> V_325 = V_322 ;
V_187 -> V_326 = V_53 -> V_67 ;
V_187 -> V_327 = V_53 -> V_67 ;
F_326 ( F_323 ( V_187 -> V_328 ) ) ;
F_322 ( V_53 -> V_66 , F_323 ( V_187 -> V_328 ) ) ;
F_327 ( V_187 -> V_329 ) ;
F_324 ( F_129 ( F_325 ( V_53 ) ) , V_187 -> V_329 ) ;
return 1 ;
}
static void F_328 ( struct V_317 * V_73 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_54 V_55 ,
unsigned long * V_48 )
{
void * V_18 = F_15 ( V_11 ) ;
void * V_5 ;
F_313 ( V_48 , V_11 -> V_14 ) ;
F_45 ( V_2 , V_11 , V_48 ) ;
F_133 (p, s, addr, page->objects)
if ( ! F_256 ( F_23 ( V_5 , V_2 , V_18 ) , V_48 ) )
F_321 ( V_73 , V_2 , F_49 ( V_2 , V_5 , V_55 ) ) ;
}
static int F_329 ( struct V_1 * V_2 , char * V_75 ,
enum V_54 V_55 )
{
int V_330 = 0 ;
unsigned long V_58 ;
struct V_317 V_73 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_48 = F_280 ( F_255 ( F_28 ( V_2 -> F_232 ) ) *
sizeof( unsigned long ) , V_255 ) ;
if ( ! V_48 || ! F_319 ( & V_73 , V_27 / sizeof( struct V_319 ) ,
V_331 ) ) {
F_257 ( V_48 ) ;
return sprintf ( V_75 , L_79 ) ;
}
F_192 ( V_2 ) ;
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_100 ( & V_40 -> V_113 ) )
continue;
F_198 ( & V_40 -> V_110 , V_3 ) ;
F_199 (page, &n->partial, lru)
F_328 ( & V_73 , V_2 , V_11 , V_55 , V_48 ) ;
F_199 (page, &n->full, lru)
F_328 ( & V_73 , V_2 , V_11 , V_55 , V_48 ) ;
F_200 ( & V_40 -> V_110 , V_3 ) ;
}
for ( V_58 = 0 ; V_58 < V_73 . V_316 ; V_58 ++ ) {
struct V_319 * V_187 = & V_73 . V_318 [ V_58 ] ;
if ( V_330 > V_27 - V_332 - 100 )
break;
V_330 += sprintf ( V_75 + V_330 , L_80 , V_187 -> V_316 ) ;
if ( V_187 -> V_18 )
V_330 += sprintf ( V_75 + V_330 , L_81 , ( void * ) V_187 -> V_18 ) ;
else
V_330 += sprintf ( V_75 + V_330 , L_82 ) ;
if ( V_187 -> V_323 != V_187 -> V_324 ) {
V_330 += sprintf ( V_75 + V_330 , L_83 ,
V_187 -> V_324 ,
( long ) F_330 ( V_187 -> V_323 , V_187 -> V_316 ) ,
V_187 -> V_325 ) ;
} else
V_330 += sprintf ( V_75 + V_330 , L_84 ,
V_187 -> V_324 ) ;
if ( V_187 -> V_326 != V_187 -> V_327 )
V_330 += sprintf ( V_75 + V_330 , L_85 ,
V_187 -> V_326 , V_187 -> V_327 ) ;
else
V_330 += sprintf ( V_75 + V_330 , L_86 ,
V_187 -> V_326 ) ;
if ( F_331 () > 1 &&
! F_332 ( F_323 ( V_187 -> V_328 ) ) &&
V_330 < V_27 - 60 ) {
V_330 += sprintf ( V_75 + V_330 , L_87 ) ;
V_330 += F_333 ( V_75 + V_330 ,
V_27 - V_330 - 50 ,
F_323 ( V_187 -> V_328 ) ) ;
}
if ( V_333 > 1 && ! F_334 ( V_187 -> V_329 ) &&
V_330 < V_27 - 60 ) {
V_330 += sprintf ( V_75 + V_330 , L_88 ) ;
V_330 += F_335 ( V_75 + V_330 ,
V_27 - V_330 - 50 ,
V_187 -> V_329 ) ;
}
V_330 += sprintf ( V_75 + V_330 , L_89 ) ;
}
F_317 ( & V_73 ) ;
F_257 ( V_48 ) ;
if ( ! V_73 . V_316 )
V_330 += sprintf ( V_75 , L_90 ) ;
return V_330 ;
}
static void F_336 ( void )
{
T_3 * V_5 ;
F_240 ( V_334 > 16 || V_251 < 10 ) ;
F_41 ( V_51 L_91 ) ;
F_41 ( V_51 L_92 ) ;
F_41 ( V_51 L_93 ) ;
V_5 = F_254 ( 16 , V_255 ) ;
V_5 [ 16 ] = 0x12 ;
F_41 ( V_51 L_94
L_95 , V_5 + 16 ) ;
F_316 ( V_335 [ 4 ] ) ;
V_5 = F_254 ( 32 , V_255 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_41 ( V_51 L_96
L_97 , V_5 ) ;
F_41 ( V_51
L_98 ) ;
F_316 ( V_335 [ 5 ] ) ;
V_5 = F_254 ( 64 , V_255 ) ;
V_5 += 64 + ( F_163 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_41 ( V_51 L_99 ,
V_5 ) ;
F_41 ( V_51
L_98 ) ;
F_316 ( V_335 [ 6 ] ) ;
F_41 ( V_51 L_100 ) ;
V_5 = F_254 ( 128 , V_255 ) ;
F_257 ( V_5 ) ;
* V_5 = 0x78 ;
F_41 ( V_51 L_101 , V_5 ) ;
F_316 ( V_335 [ 7 ] ) ;
V_5 = F_254 ( 256 , V_255 ) ;
F_257 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_41 ( V_51 L_102 ,
V_5 ) ;
F_316 ( V_335 [ 8 ] ) ;
V_5 = F_254 ( 512 , V_255 ) ;
F_257 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_41 ( V_51 L_103 , V_5 ) ;
F_316 ( V_335 [ 9 ] ) ;
}
static void F_336 ( void ) {}
static T_9 F_337 ( struct V_1 * V_2 ,
char * V_75 , unsigned long V_3 )
{
unsigned long V_336 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_329 ;
V_329 = F_254 ( sizeof( unsigned long ) * V_300 , V_255 ) ;
if ( ! V_329 )
return - V_274 ;
if ( V_3 & V_337 ) {
int V_66 ;
F_181 (cpu) {
struct V_161 * V_162 = F_182 ( V_2 -> V_8 ,
V_66 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_338 ( V_162 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_129 ( V_11 ) ;
if ( V_3 & V_338 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_339 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
V_11 = F_338 ( V_162 -> V_158 ) ;
if ( V_11 ) {
V_10 = F_129 ( V_11 ) ;
if ( V_3 & V_338 )
F_339 ( 1 ) ;
else if ( V_3 & V_339 )
F_339 ( 1 ) ;
else
V_29 = V_11 -> V_138 ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
}
}
}
F_340 () ;
#ifdef F_2
if ( V_3 & V_340 ) {
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
if ( V_3 & V_338 )
V_29 = F_100 ( & V_40 -> V_114 ) ;
else if ( V_3 & V_339 )
V_29 = F_100 ( & V_40 -> V_114 ) -
F_196 ( V_40 , F_195 ) ;
else
V_29 = F_100 ( & V_40 -> V_113 ) ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_341 ) {
F_244 (node, N_NORMAL_MEMORY) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
if ( V_3 & V_338 )
V_29 = F_196 ( V_40 , F_311 ) ;
else if ( V_3 & V_339 )
V_29 = F_196 ( V_40 , F_310 ) ;
else
V_29 = V_40 -> V_156 ;
V_336 += V_29 ;
V_329 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_75 , L_104 , V_336 ) ;
#ifdef F_161
F_244 (node, N_NORMAL_MEMORY)
if ( V_329 [ V_10 ] )
V_29 += sprintf ( V_75 + V_29 , L_105 ,
V_10 , V_329 [ V_10 ] ) ;
#endif
F_341 () ;
F_257 ( V_329 ) ;
return V_29 + sprintf ( V_75 + V_29 , L_89 ) ;
}
static int F_342 ( struct V_1 * V_2 )
{
int V_10 ;
F_204 (node) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
if ( ! V_40 )
continue;
if ( F_100 ( & V_40 -> V_114 ) )
return 1 ;
}
return 0 ;
}
static T_9 F_343 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_15 ) ;
}
static T_9 F_344 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_259 ) ;
}
static T_9 F_345 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_21 ) ;
}
static T_9 F_346 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , F_28 ( V_2 -> V_126 ) ) ;
}
static T_9 F_347 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_25 ;
int V_307 ;
V_307 = F_348 ( V_75 , 10 , & V_25 ) ;
if ( V_307 )
return V_307 ;
if ( V_25 > V_247 || V_25 < V_241 )
return - V_266 ;
F_247 ( V_2 , V_25 ) ;
return V_50 ;
}
static T_9 F_349 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , F_27 ( V_2 -> V_126 ) ) ;
}
static T_9 F_350 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_107 , V_2 -> V_176 ) ;
}
static T_9 F_351 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_134 ;
int V_307 ;
V_307 = F_348 ( V_75 , 10 , & V_134 ) ;
if ( V_307 )
return V_307 ;
F_246 ( V_2 , V_134 ) ;
return V_50 ;
}
static T_9 F_352 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_108 , V_2 -> V_167 ) ;
}
static T_9 F_353 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
unsigned long V_14 ;
int V_307 ;
V_307 = F_348 ( V_75 , 10 , & V_14 ) ;
if ( V_307 )
return V_307 ;
if ( V_14 && ! F_4 ( V_2 ) )
return - V_266 ;
V_2 -> V_167 = V_14 ;
F_192 ( V_2 ) ;
return V_50 ;
}
static T_9 F_354 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! V_2 -> F_113 )
return 0 ;
return sprintf ( V_75 , L_109 , V_2 -> F_113 ) ;
}
static T_9 F_355 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_303 - 1 ) ;
}
static T_9 F_356 ( struct V_1 * V_2 , char * V_75 )
{
return F_337 ( V_2 , V_75 , V_341 ) ;
}
static T_9 F_357 ( struct V_1 * V_2 , char * V_75 )
{
return F_337 ( V_2 , V_75 , V_337 ) ;
}
static T_9 F_358 ( struct V_1 * V_2 , char * V_75 )
{
return F_337 ( V_2 , V_75 , V_340 | V_339 ) ;
}
static T_9 F_359 ( struct V_1 * V_2 , char * V_75 )
{
return F_337 ( V_2 , V_75 , V_341 | V_339 ) ;
}
static T_9 F_360 ( struct V_1 * V_2 , char * V_75 )
{
int V_14 = 0 ;
int V_138 = 0 ;
int V_66 ;
int V_330 ;
F_361 (cpu) {
struct V_11 * V_11 = F_182 ( V_2 -> V_8 , V_66 ) -> V_158 ;
if ( V_11 ) {
V_138 += V_11 -> V_138 ;
V_14 += V_11 -> V_204 ;
}
}
V_330 = sprintf ( V_75 , L_110 , V_14 , V_138 ) ;
#ifdef F_296
F_361 (cpu) {
struct V_11 * V_11 = F_182 ( V_2 -> V_8 , V_66 ) -> V_158 ;
if ( V_11 && V_330 < V_27 - 20 )
V_330 += sprintf ( V_75 + V_330 , L_111 , V_66 ,
V_11 -> V_204 , V_11 -> V_138 ) ;
}
#endif
return V_330 + sprintf ( V_75 + V_330 , L_89 ) ;
}
static T_9 F_362 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_139 ) ) ;
}
static T_9 F_363 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_139 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_139 ;
return V_50 ;
}
static T_9 F_364 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_297 ) ) ;
}
static T_9 F_365 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_261 ) ) ;
}
static T_9 F_366 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_9 F_367 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_26 ) ;
}
static T_9 F_368 ( struct V_1 * V_2 , char * V_75 )
{
return F_337 ( V_2 , V_75 , V_340 ) ;
}
static T_9 F_369 ( struct V_1 * V_2 , char * V_75 )
{
return F_337 ( V_2 , V_75 , V_340 | V_338 ) ;
}
static T_9 F_370 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_123 ) ) ;
}
static T_9 F_371 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
V_2 -> V_3 &= ~ V_123 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_123 ;
}
return V_50 ;
}
static T_9 F_372 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_103 ) ) ;
}
static T_9 F_373 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_103 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_103 ;
}
return V_50 ;
}
static T_9 F_374 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_9 F_375 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_342 ( V_2 ) )
return - V_342 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_19 ;
}
F_247 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_376 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_9 F_377 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_342 ( V_2 ) )
return - V_342 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_20 ;
}
F_247 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_378 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_9 F_379 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( F_342 ( V_2 ) )
return - V_342 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_43 ;
V_2 -> V_3 |= V_23 ;
}
F_247 ( V_2 , - 1 ) ;
return V_50 ;
}
static T_9 F_380 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_9 F_381 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
int V_226 = - V_266 ;
if ( V_75 [ 0 ] == '1' ) {
V_226 = F_316 ( V_2 ) ;
if ( V_226 >= 0 )
V_226 = V_50 ;
}
return V_226 ;
}
static T_9 F_382 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_249 ;
return F_329 ( V_2 , V_75 , V_72 ) ;
}
static T_9 F_383 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_249 ;
return F_329 ( V_2 , V_75 , V_71 ) ;
}
static T_9 F_384 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , ! ! ( V_2 -> V_3 & V_124 ) ) ;
}
static T_9 F_385 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_50 )
{
V_2 -> V_3 &= ~ V_124 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_124 ;
return V_50 ;
}
static T_9 F_386 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_9 F_387 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
if ( V_75 [ 0 ] == '1' ) {
int V_267 = F_279 ( V_2 ) ;
if ( V_267 )
return V_267 ;
} else
return - V_266 ;
return V_50 ;
}
static T_9 F_388 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_106 , V_2 -> V_175 / 10 ) ;
}
static T_9 F_389 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_50 )
{
unsigned long V_343 ;
int V_307 ;
V_307 = F_348 ( V_75 , 10 , & V_343 ) ;
if ( V_307 )
return V_307 ;
if ( V_343 <= 100 )
V_2 -> V_175 = V_343 * 10 ;
return V_50 ;
}
static int F_390 ( struct V_1 * V_2 , char * V_75 , enum V_6 V_7 )
{
unsigned long V_344 = 0 ;
int V_66 ;
int V_330 ;
int * V_85 = F_280 ( V_246 * sizeof( int ) , V_255 ) ;
if ( ! V_85 )
return - V_274 ;
F_361 (cpu) {
unsigned V_29 = F_182 ( V_2 -> V_8 , V_66 ) -> F_10 [ V_7 ] ;
V_85 [ V_66 ] = V_29 ;
V_344 += V_29 ;
}
V_330 = sprintf ( V_75 , L_104 , V_344 ) ;
#ifdef F_296
F_361 (cpu) {
if ( V_85 [ V_66 ] && V_330 < V_27 - 20 )
V_330 += sprintf ( V_75 + V_330 , L_112 , V_66 , V_85 [ V_66 ] ) ;
}
#endif
F_257 ( V_85 ) ;
return V_330 + sprintf ( V_75 + V_330 , L_89 ) ;
}
static void F_391 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_66 ;
F_361 (cpu)
F_182 ( V_2 -> V_8 , V_66 ) -> F_10 [ V_7 ] = 0 ;
}
static T_9 F_392 ( struct V_345 * V_346 ,
struct V_347 * V_348 ,
char * V_75 )
{
struct V_349 * V_347 ;
struct V_1 * V_2 ;
int V_307 ;
V_347 = F_393 ( V_348 ) ;
V_2 = F_394 ( V_346 ) ;
if ( ! V_347 -> V_350 )
return - V_351 ;
V_307 = V_347 -> V_350 ( V_2 , V_75 ) ;
return V_307 ;
}
static T_9 F_395 ( struct V_345 * V_346 ,
struct V_347 * V_348 ,
const char * V_75 , T_1 V_330 )
{
struct V_349 * V_347 ;
struct V_1 * V_2 ;
int V_307 ;
V_347 = F_393 ( V_348 ) ;
V_2 = F_394 ( V_346 ) ;
if ( ! V_347 -> V_352 )
return - V_351 ;
V_307 = V_347 -> V_352 ( V_2 , V_75 , V_330 ) ;
#ifdef F_396
if ( V_253 >= V_353 && V_307 >= 0 && F_397 ( V_2 ) ) {
int V_58 ;
F_263 ( & V_268 ) ;
if ( V_2 -> V_354 < V_330 )
V_2 -> V_354 = V_330 ;
F_398 (i) {
struct V_1 * V_162 = F_399 ( V_2 , V_58 ) ;
if ( V_162 )
V_347 -> V_352 ( V_162 , V_75 , V_330 ) ;
}
F_262 ( & V_268 ) ;
}
#endif
return V_307 ;
}
static void F_9 ( struct V_1 * V_2 )
{
#ifdef F_396
int V_58 ;
char * V_355 = NULL ;
if ( ! F_397 ( V_2 ) )
return;
if ( ! V_2 -> V_354 )
return;
for ( V_58 = 0 ; V_58 < F_400 ( V_356 ) ; V_58 ++ ) {
char V_357 [ 64 ] ;
char * V_75 ;
struct V_349 * V_348 = F_393 ( V_356 [ V_58 ] ) ;
if ( ! V_348 || ! V_348 -> V_352 || ! V_348 -> V_350 )
continue;
if ( V_355 )
V_75 = V_355 ;
else if ( V_2 -> V_354 < F_400 ( V_357 ) )
V_75 = V_357 ;
else {
V_355 = ( char * ) F_401 ( V_255 ) ;
if ( F_153 ( ! V_355 ) )
continue;
V_75 = V_355 ;
}
V_348 -> V_350 ( V_2 -> V_358 -> V_359 , V_75 ) ;
V_348 -> V_352 ( V_2 , V_75 , strlen ( V_75 ) ) ;
}
if ( V_355 )
F_402 ( ( unsigned long ) V_355 ) ;
#endif
}
static int F_403 ( struct V_360 * V_360 , struct V_345 * V_346 )
{
struct V_361 * V_362 = F_404 ( V_346 ) ;
if ( V_362 == & V_363 )
return 1 ;
return 0 ;
}
static char * F_405 ( struct V_1 * V_2 )
{
char * V_47 = F_280 ( V_364 , V_255 ) ;
char * V_5 = V_47 ;
F_128 ( ! V_47 ) ;
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
#ifdef F_396
if ( ! F_397 ( V_2 ) )
V_5 += sprintf ( V_5 , L_114 ,
F_406 ( V_2 -> V_358 -> V_305 ) ) ;
#endif
F_128 ( V_5 > V_47 + V_364 - 1 ) ;
return V_47 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_307 ;
const char * V_47 ;
int V_365 = F_300 ( V_2 ) ;
if ( V_365 ) {
F_407 ( & V_366 -> V_346 , V_2 -> V_47 ) ;
V_47 = V_2 -> V_47 ;
} else {
V_47 = F_405 ( V_2 ) ;
}
V_2 -> V_346 . V_360 = V_366 ;
V_307 = F_408 ( & V_2 -> V_346 , & V_363 , NULL , L_18 , V_47 ) ;
if ( V_307 ) {
F_409 ( & V_2 -> V_346 ) ;
return V_307 ;
}
V_307 = F_410 ( & V_2 -> V_346 , & V_367 ) ;
if ( V_307 ) {
F_411 ( & V_2 -> V_346 ) ;
F_409 ( & V_2 -> V_346 ) ;
return V_307 ;
}
F_412 ( & V_2 -> V_346 , V_368 ) ;
if ( ! V_365 ) {
F_7 ( V_2 , V_2 -> V_47 ) ;
F_257 ( V_47 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_253 < V_353 )
return;
F_412 ( & V_2 -> V_346 , V_369 ) ;
F_411 ( & V_2 -> V_346 ) ;
F_409 ( & V_2 -> V_346 ) ;
}
static int F_7 ( struct V_1 * V_2 , const char * V_47 )
{
struct V_370 * V_371 ;
if ( V_253 == V_353 ) {
F_407 ( & V_366 -> V_346 , V_47 ) ;
return F_413 ( & V_366 -> V_346 , & V_2 -> V_346 , V_47 ) ;
}
V_371 = F_280 ( sizeof( struct V_370 ) , V_255 ) ;
if ( ! V_371 )
return - V_274 ;
V_371 -> V_2 = V_2 ;
V_371 -> V_47 = V_47 ;
V_371 -> V_200 = V_372 ;
V_372 = V_371 ;
return 0 ;
}
static int T_7 F_414 ( void )
{
struct V_1 * V_2 ;
int V_307 ;
F_263 ( & V_268 ) ;
V_366 = F_415 ( L_115 , & V_373 , V_374 ) ;
if ( ! V_366 ) {
F_262 ( & V_268 ) ;
F_41 ( V_51 L_116 ) ;
return - V_249 ;
}
V_253 = V_353 ;
F_199 (s, &slab_caches, list) {
V_307 = F_6 ( V_2 ) ;
if ( V_307 )
F_41 ( V_51 L_117
L_118 , V_2 -> V_47 ) ;
}
while ( V_372 ) {
struct V_370 * V_371 = V_372 ;
V_372 = V_372 -> V_200 ;
V_307 = F_7 ( V_371 -> V_2 , V_371 -> V_47 ) ;
if ( V_307 )
F_41 ( V_51 L_119
L_120 , V_371 -> V_47 ) ;
F_257 ( V_371 ) ;
}
F_262 ( & V_268 ) ;
F_336 () ;
return 0 ;
}
void F_416 ( struct V_1 * V_2 , struct V_375 * V_376 )
{
unsigned long V_113 = 0 ;
unsigned long V_213 = 0 ;
unsigned long V_214 = 0 ;
int V_10 ;
F_204 (node) {
struct V_9 * V_40 = F_13 ( V_2 , V_10 ) ;
if ( ! V_40 )
continue;
V_113 += F_101 ( V_40 ) ;
V_213 += F_201 ( V_40 ) ;
V_214 += F_196 ( V_40 , F_195 ) ;
}
V_376 -> V_377 = V_213 - V_214 ;
V_376 -> V_378 = V_213 ;
V_376 -> V_379 = V_113 ;
V_376 -> V_380 = V_113 ;
V_376 -> V_381 = F_28 ( V_2 -> V_126 ) ;
V_376 -> V_382 = F_27 ( V_2 -> V_126 ) ;
}
void F_417 ( struct V_383 * V_188 , struct V_1 * V_2 )
{
}
T_9 F_418 ( struct V_384 * V_384 , const char T_10 * V_355 ,
T_1 V_316 , T_11 * V_385 )
{
return - V_351 ;
}
