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
static inline void F_7 ( struct V_1 * V_2 ) { }
static inline void F_8 ( const struct V_1 * V_2 , enum V_6 V_7 )
{
#ifdef F_9
F_10 ( V_2 -> V_8 -> F_8 [ V_7 ] ) ;
#endif
}
static inline struct V_9 * F_11 ( struct V_1 * V_2 , int V_10 )
{
return V_2 -> V_10 [ V_10 ] ;
}
static inline int F_12 ( struct V_1 * V_2 ,
struct V_11 * V_11 , const void * V_12 )
{
void * V_13 ;
if ( ! V_12 )
return 1 ;
V_13 = F_13 ( V_11 ) ;
if ( V_12 < V_13 || V_12 >= V_13 + V_11 -> V_14 * V_2 -> V_15 ||
( V_12 - V_13 ) % V_2 -> V_15 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_14 ( struct V_1 * V_2 , void * V_12 )
{
return * ( void * * ) ( V_12 + V_2 -> V_16 ) ;
}
static void F_15 ( const struct V_1 * V_2 , void * V_12 )
{
F_16 ( V_12 + V_2 -> V_16 ) ;
}
static inline void * F_17 ( struct V_1 * V_2 , void * V_12 )
{
void * V_5 ;
#ifdef F_18
F_19 ( & V_5 , ( void * * ) ( V_12 + V_2 -> V_16 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_14 ( V_2 , V_12 ) ;
#endif
return V_5 ;
}
static inline void F_20 ( struct V_1 * V_2 , void * V_12 , void * V_17 )
{
* ( void * * ) ( V_12 + V_2 -> V_16 ) = V_17 ;
}
static inline int F_21 ( void * V_5 , struct V_1 * V_2 , void * V_18 )
{
return ( V_5 - V_18 ) / V_2 -> V_15 ;
}
static inline T_1 F_22 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_19 | V_20 ) )
return V_2 -> V_21 ;
#endif
if ( V_2 -> V_3 & ( V_22 | V_23 ) )
return V_2 -> V_24 ;
return V_2 -> V_15 ;
}
static inline int F_23 ( int V_25 , unsigned long V_15 , int V_26 )
{
return ( ( V_27 << V_25 ) - V_26 ) / V_15 ;
}
static inline struct V_28 F_24 ( int V_25 ,
unsigned long V_15 , int V_26 )
{
struct V_28 V_29 = {
( V_25 << V_30 ) + F_23 (order, size, reserved)
} ;
return V_29 ;
}
static inline int F_25 ( struct V_28 V_29 )
{
return V_29 . V_29 >> V_30 ;
}
static inline int F_26 ( struct V_28 V_29 )
{
return V_29 . V_29 & V_31 ;
}
static T_2 void F_27 ( struct V_11 * V_11 )
{
F_28 ( V_32 , & V_11 -> V_3 ) ;
}
static T_2 void F_29 ( struct V_11 * V_11 )
{
F_30 ( V_32 , & V_11 -> V_3 ) ;
}
static inline bool F_31 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_33 , unsigned long V_34 ,
void * V_35 , unsigned long V_36 ,
const char * V_37 )
{
F_32 ( ! F_33 () ) ;
#if F_34 ( V_38 ) && \
F_34 ( V_39 )
if ( V_2 -> V_3 & V_40 ) {
if ( F_35 ( & V_11 -> V_41 , & V_11 -> V_42 ,
V_33 , V_34 ,
V_35 , V_36 ) )
return 1 ;
} else
#endif
{
F_27 ( V_11 ) ;
if ( V_11 -> V_41 == V_33 && V_11 -> V_42 == V_34 ) {
V_11 -> V_41 = V_35 ;
V_11 -> V_42 = V_36 ;
F_29 ( V_11 ) ;
return 1 ;
}
F_29 ( V_11 ) ;
}
F_36 () ;
F_8 ( V_2 , V_43 ) ;
#ifdef F_37
F_38 ( V_44 L_1 , V_37 , V_2 -> V_45 ) ;
#endif
return 0 ;
}
static inline bool F_39 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_33 , unsigned long V_34 ,
void * V_35 , unsigned long V_36 ,
const char * V_37 )
{
#if F_34 ( V_38 ) && \
F_34 ( V_39 )
if ( V_2 -> V_3 & V_40 ) {
if ( F_35 ( & V_11 -> V_41 , & V_11 -> V_42 ,
V_33 , V_34 ,
V_35 , V_36 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_27 ( V_11 ) ;
if ( V_11 -> V_41 == V_33 && V_11 -> V_42 == V_34 ) {
V_11 -> V_41 = V_35 ;
V_11 -> V_42 = V_36 ;
F_29 ( V_11 ) ;
F_41 ( V_3 ) ;
return 1 ;
}
F_29 ( V_11 ) ;
F_41 ( V_3 ) ;
}
F_36 () ;
F_8 ( V_2 , V_43 ) ;
#ifdef F_37
F_38 ( V_44 L_1 , V_37 , V_2 -> V_45 ) ;
#endif
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_11 * V_11 , unsigned long * V_46 )
{
void * V_5 ;
void * V_18 = F_13 ( V_11 ) ;
for ( V_5 = V_11 -> V_41 ; V_5 ; V_5 = F_14 ( V_2 , V_5 ) )
F_43 ( F_21 ( V_5 , V_2 , V_18 ) , V_46 ) ;
}
static void F_44 ( char * V_47 , T_3 * V_18 , unsigned int V_48 )
{
F_45 ( V_49 , V_47 , V_50 , 16 , 1 , V_18 ,
V_48 , 1 ) ;
}
static struct V_51 * F_46 ( struct V_1 * V_2 , void * V_12 ,
enum V_52 V_53 )
{
struct V_51 * V_5 ;
if ( V_2 -> V_16 )
V_5 = V_12 + V_2 -> V_16 + sizeof( void * ) ;
else
V_5 = V_12 + V_2 -> V_24 ;
return V_5 + V_53 ;
}
static void F_47 ( struct V_1 * V_2 , void * V_12 ,
enum V_52 V_53 , unsigned long V_18 )
{
struct V_51 * V_5 = F_46 ( V_2 , V_12 , V_53 ) ;
if ( V_18 ) {
#ifdef F_48
struct V_54 V_55 ;
int V_56 ;
V_55 . V_57 = 0 ;
V_55 . V_58 = V_59 ;
V_55 . V_60 = V_5 -> V_61 ;
V_55 . V_62 = 3 ;
F_49 ( & V_55 ) ;
if ( V_55 . V_57 != 0 &&
V_55 . V_60 [ V_55 . V_57 - 1 ] == V_63 )
V_55 . V_57 -- ;
for ( V_56 = V_55 . V_57 ; V_56 < V_59 ; V_56 ++ )
V_5 -> V_61 [ V_56 ] = 0 ;
#endif
V_5 -> V_18 = V_18 ;
V_5 -> V_64 = F_50 () ;
V_5 -> V_65 = V_66 -> V_65 ;
V_5 -> V_67 = V_68 ;
} else
memset ( V_5 , 0 , sizeof( struct V_51 ) ) ;
}
static void F_51 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_47 ( V_2 , V_12 , V_69 , 0UL ) ;
F_47 ( V_2 , V_12 , V_70 , 0UL ) ;
}
static void F_52 ( const char * V_2 , struct V_51 * V_71 )
{
if ( ! V_71 -> V_18 )
return;
F_38 ( V_49 L_2 ,
V_2 , ( void * ) V_71 -> V_18 , V_68 - V_71 -> V_67 , V_71 -> V_64 , V_71 -> V_65 ) ;
#ifdef F_48
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_59 ; V_56 ++ )
if ( V_71 -> V_61 [ V_56 ] )
F_38 ( V_49 L_3 , ( void * ) V_71 -> V_61 [ V_56 ] ) ;
else
break;
}
#endif
}
static void F_53 ( struct V_1 * V_2 , void * V_12 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_52 ( L_4 , F_46 ( V_2 , V_12 , V_70 ) ) ;
F_52 ( L_5 , F_46 ( V_2 , V_12 , V_69 ) ) ;
}
static void F_54 ( struct V_11 * V_11 )
{
F_38 ( V_49 L_6 ,
V_11 , V_11 -> V_14 , V_11 -> V_24 , V_11 -> V_41 , V_11 -> V_3 ) ;
}
static void F_55 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_38 ( V_49 L_7
L_8 ) ;
F_38 ( V_49 L_9 , V_2 -> V_45 , F_56 () , V_73 ) ;
F_38 ( V_49 L_10
L_11 ) ;
F_57 ( V_74 ) ;
}
static void F_58 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_38 ( V_49 L_12 , V_2 -> V_45 , V_73 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned int V_75 ;
T_3 * V_18 = F_13 ( V_11 ) ;
F_53 ( V_2 , V_5 ) ;
F_54 ( V_11 ) ;
F_38 ( V_49 L_13 ,
V_5 , V_5 - V_18 , F_14 ( V_2 , V_5 ) ) ;
if ( V_5 > V_18 + 16 )
F_44 ( L_14 , V_5 - 16 , 16 ) ;
F_44 ( L_15 , V_5 , F_60 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_19 )
F_44 ( L_16 , V_5 + V_2 -> V_21 ,
V_2 -> V_24 - V_2 -> V_21 ) ;
if ( V_2 -> V_16 )
V_75 = V_2 -> V_16 + sizeof( void * ) ;
else
V_75 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_75 += 2 * sizeof( struct V_51 ) ;
if ( V_75 != V_2 -> V_15 )
F_44 ( L_17 , V_5 + V_75 , V_2 -> V_15 - V_75 ) ;
F_61 () ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_76 )
{
F_55 ( V_2 , L_18 , V_76 ) ;
F_59 ( V_2 , V_11 , V_12 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_11 * V_11 , const char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_55 ( V_2 , L_18 , V_73 ) ;
F_54 ( V_11 ) ;
F_61 () ;
}
static void F_64 ( struct V_1 * V_2 , void * V_12 , T_3 V_77 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_78 ) {
memset ( V_5 , V_79 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_80 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_77 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_65 ( struct V_1 * V_2 , char * V_81 , T_3 V_82 ,
void * V_83 , void * V_84 )
{
F_58 ( V_2 , L_19 , V_83 , V_84 - 1 , V_82 ) ;
memset ( V_83 , V_82 , V_84 - V_83 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_85 ,
T_3 * V_86 , unsigned int V_87 , unsigned int V_88 )
{
T_3 * V_89 ;
T_3 * V_90 ;
V_89 = F_67 ( V_86 , V_87 , V_88 ) ;
if ( ! V_89 )
return 1 ;
V_90 = V_86 + V_88 ;
while ( V_90 > V_89 && V_90 [ - 1 ] == V_87 )
V_90 -- ;
F_55 ( V_2 , L_20 , V_85 ) ;
F_38 ( V_49 L_21 ,
V_89 , V_90 - 1 , V_89 [ 0 ] , V_87 ) ;
F_59 ( V_2 , V_11 , V_12 ) ;
F_65 ( V_2 , V_85 , V_87 , V_89 , V_90 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_75 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_75 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_75 += 2 * sizeof( struct V_51 ) ;
if ( V_2 -> V_15 == V_75 )
return 1 ;
return F_66 ( V_2 , V_11 , V_5 , L_22 ,
V_5 + V_75 , V_91 , V_2 -> V_15 - V_75 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_86 ;
T_3 * V_89 ;
T_3 * V_90 ;
int V_48 ;
int V_92 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_86 = F_13 ( V_11 ) ;
V_48 = ( V_27 << F_70 ( V_11 ) ) - V_2 -> V_26 ;
V_90 = V_86 + V_48 ;
V_92 = V_48 % V_2 -> V_15 ;
if ( ! V_92 )
return 1 ;
V_89 = F_67 ( V_90 - V_92 , V_91 , V_92 ) ;
if ( ! V_89 )
return 1 ;
while ( V_90 > V_89 && V_90 [ - 1 ] == V_91 )
V_90 -- ;
F_63 ( V_2 , V_11 , L_23 , V_89 , V_90 - 1 ) ;
F_44 ( L_17 , V_90 - V_92 , V_92 ) ;
F_65 ( V_2 , L_24 , V_91 , V_90 - V_92 , V_90 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_77 )
{
T_3 * V_5 = V_12 ;
T_3 * V_93 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_66 ( V_2 , V_11 , V_12 , L_25 ,
V_93 , V_77 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_66 ( V_2 , V_11 , V_5 , L_26 ,
V_93 , V_91 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_77 != V_94 && ( V_2 -> V_3 & V_78 ) &&
( ! F_66 ( V_2 , V_11 , V_5 , L_27 , V_5 ,
V_79 , V_2 -> V_21 - 1 ) ||
! F_66 ( V_2 , V_11 , V_5 , L_27 ,
V_5 + V_2 -> V_21 - 1 , V_80 , 1 ) ) )
return 0 ;
F_68 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_77 == V_94 )
return 1 ;
if ( ! F_12 ( V_2 , V_11 , F_14 ( V_2 , V_5 ) ) ) {
F_62 ( V_2 , V_11 , V_5 , L_28 ) ;
F_20 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_95 ;
F_32 ( ! F_33 () ) ;
if ( ! F_73 ( V_11 ) ) {
F_63 ( V_2 , V_11 , L_29 ) ;
return 0 ;
}
V_95 = F_23 ( F_70 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_95 ) {
F_63 ( V_2 , V_11 , L_30 ,
V_2 -> V_45 , V_11 -> V_14 , V_95 ) ;
return 0 ;
}
if ( V_11 -> V_24 > V_11 -> V_14 ) {
F_63 ( V_2 , V_11 , L_31 ,
V_2 -> V_45 , V_11 -> V_24 , V_11 -> V_14 ) ;
return 0 ;
}
F_69 ( V_2 , V_11 ) ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_96 )
{
int V_97 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_98 ;
V_17 = V_11 -> V_41 ;
while ( V_17 && V_97 <= V_11 -> V_14 ) {
if ( V_17 == V_96 )
return 1 ;
if ( ! F_12 ( V_2 , V_11 , V_17 ) ) {
if ( V_12 ) {
F_62 ( V_2 , V_11 , V_12 ,
L_32 ) ;
F_20 ( V_2 , V_12 , NULL ) ;
break;
} else {
F_63 ( V_2 , V_11 , L_28 ) ;
V_11 -> V_41 = NULL ;
V_11 -> V_24 = V_11 -> V_14 ;
F_58 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_12 = V_17 ;
V_17 = F_14 ( V_2 , V_12 ) ;
V_97 ++ ;
}
V_98 = F_23 ( F_70 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_98 > V_99 )
V_98 = V_99 ;
if ( V_11 -> V_14 != V_98 ) {
F_63 ( V_2 , V_11 , L_34
L_35 , V_11 -> V_14 , V_98 ) ;
V_11 -> V_14 = V_98 ;
F_58 ( V_2 , L_36 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_97 ) {
F_63 ( V_2 , V_11 , L_37
L_38 , V_11 -> V_24 , V_11 -> V_14 - V_97 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_97 ;
F_58 ( V_2 , L_39 ) ;
}
return V_96 == NULL ;
}
static void V_55 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_53 )
{
if ( V_2 -> V_3 & V_100 ) {
F_38 ( V_44 L_40 ,
V_2 -> V_45 ,
V_53 ? L_41 : L_42 ,
V_12 , V_11 -> V_24 ,
V_11 -> V_41 ) ;
if ( ! V_53 )
F_44 ( L_15 , ( void * ) V_12 , V_2 -> V_21 ) ;
F_61 () ;
}
}
static inline int F_75 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_101 ;
F_76 ( V_3 ) ;
F_77 ( V_3 & V_102 ) ;
return F_78 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_79 ( struct V_1 * V_2 , T_5 V_3 , void * V_12 )
{
V_3 &= V_101 ;
F_80 ( V_2 , V_3 , V_12 , F_22 ( V_2 ) ) ;
F_81 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_82 ( struct V_1 * V_2 , void * V_29 )
{
F_83 ( V_29 , V_2 -> V_3 ) ;
#if F_34 ( V_103 ) || F_34 ( V_104 )
{
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_84 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_85 ( V_29 , V_2 -> V_21 ) ;
F_41 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_105 ) )
F_86 ( V_29 , V_2 -> V_21 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_88 ( & V_11 -> V_106 , & V_37 -> V_107 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_90 ( & V_11 -> V_106 ) ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
return F_92 ( & V_37 -> V_108 ) ;
}
static inline unsigned long F_93 ( struct V_9 * V_37 )
{
return F_92 ( & V_37 -> V_108 ) ;
}
static inline void F_94 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( V_37 ) {
F_95 ( & V_37 -> V_108 ) ;
F_96 ( V_14 , & V_37 -> V_109 ) ;
}
}
static inline void F_97 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
F_98 ( & V_37 -> V_108 ) ;
F_99 ( V_14 , & V_37 -> V_109 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_78 ) ) )
return;
F_64 ( V_2 , V_12 , V_110 ) ;
F_51 ( V_2 , V_12 ) ;
}
static T_6 int F_101 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_72 ( V_2 , V_11 ) )
goto V_111;
if ( ! F_12 ( V_2 , V_11 , V_12 ) ) {
F_62 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_111;
}
if ( ! F_71 ( V_2 , V_11 , V_12 , V_110 ) )
goto V_111;
if ( V_2 -> V_3 & V_23 )
F_47 ( V_2 , V_12 , V_70 , V_18 ) ;
V_55 ( V_2 , V_11 , V_12 , 1 ) ;
F_64 ( V_2 , V_12 , V_94 ) ;
return 1 ;
V_111:
if ( F_73 ( V_11 ) ) {
F_58 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_41 = NULL ;
}
return 0 ;
}
int T_7 F_102 ( char * V_112 )
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
F_38 ( V_49 L_45
L_46 , * V_112 ) ;
}
}
V_116:
if ( * V_112 == ',' )
V_120 = V_112 + 1 ;
V_115:
return 1 ;
}
static unsigned long F_103 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_104)( void * ) )
{
if ( V_113 && ( ! V_120 ||
! strncmp ( V_120 , V_45 , strlen ( V_120 ) ) ) )
V_3 |= V_113 ;
return V_3 ;
}
static inline void F_100 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 ) {}
static inline int F_101 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_12 , unsigned long V_18 ) { return 0 ; }
static inline struct V_9 * F_105 (
struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
unsigned long V_18 , unsigned long * V_3 ) { return NULL ; }
static inline int F_69 ( struct V_1 * V_2 , struct V_11 * V_11 )
{ return 1 ; }
static inline int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_77 ) { return 1 ; }
static inline void F_87 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_11 * V_11 ) {}
static inline void F_89 ( struct V_1 * V_2 , struct V_11 * V_11 ) {}
static inline unsigned long F_103 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_104)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_10 )
{ return 0 ; }
static inline unsigned long F_93 ( struct V_9 * V_37 )
{ return 0 ; }
static inline void F_94 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline void F_97 ( struct V_1 * V_2 , int V_10 ,
int V_14 ) {}
static inline int F_75 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_79 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_12 ) {}
static inline void F_82 ( struct V_1 * V_2 , void * V_29 ) {}
static inline struct V_11 * F_106 ( T_5 V_3 , int V_10 ,
struct V_28 V_121 )
{
int V_25 = F_25 ( V_121 ) ;
V_3 |= V_122 ;
if ( V_10 == V_123 )
return F_107 ( V_3 , V_25 ) ;
else
return F_108 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_109 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_121 = V_2 -> V_121 ;
T_5 V_124 ;
V_3 &= V_101 ;
if ( V_3 & V_102 )
F_110 () ;
V_3 |= V_2 -> V_125 ;
V_124 = ( V_3 | V_126 | V_127 ) & ~ V_128 ;
V_11 = F_106 ( V_124 , V_10 , V_121 ) ;
if ( F_3 ( ! V_11 ) ) {
V_121 = V_2 -> V_129 ;
V_11 = F_106 ( V_3 , V_10 , V_121 ) ;
if ( V_11 )
F_8 ( V_2 , V_130 ) ;
}
if ( V_131 && V_11
&& ! ( V_2 -> V_3 & ( V_132 | V_114 ) ) ) {
int V_133 = 1 << F_25 ( V_121 ) ;
F_111 ( V_11 , F_25 ( V_121 ) , V_3 , V_10 ) ;
if ( V_2 -> F_104 )
F_112 ( V_11 , V_133 ) ;
else
F_113 ( V_11 , V_133 ) ;
}
if ( V_3 & V_102 )
F_114 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_26 ( V_121 ) ;
F_115 ( F_116 ( V_11 ) ,
( V_2 -> V_3 & V_134 ) ?
V_135 : V_136 ,
1 << F_25 ( V_121 ) ) ;
return V_11 ;
}
static void F_117 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
F_100 ( V_2 , V_11 , V_12 ) ;
if ( F_3 ( V_2 -> F_104 ) )
V_2 -> F_104 ( V_12 ) ;
}
static struct V_11 * F_118 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_86 ;
void * V_137 ;
void * V_5 ;
int V_25 ;
F_119 ( V_3 & V_138 ) ;
V_11 = F_109 ( V_2 ,
V_3 & ( V_139 | V_140 ) , V_10 ) ;
if ( ! V_11 )
goto V_115;
V_25 = F_70 ( V_11 ) ;
F_94 ( V_2 , F_120 ( V_11 ) , V_11 -> V_14 ) ;
F_121 ( V_2 , V_25 ) ;
V_11 -> V_141 = V_2 ;
F_122 ( V_11 ) ;
if ( V_11 -> V_142 )
F_123 ( V_11 ) ;
V_86 = F_13 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_86 , V_91 , V_27 << V_25 ) ;
V_137 = V_86 ;
F_124 (p, s, start, page->objects) {
F_117 ( V_2 , V_11 , V_137 ) ;
F_20 ( V_2 , V_137 , V_5 ) ;
V_137 = V_5 ;
}
F_117 ( V_2 , V_11 , V_137 ) ;
F_20 ( V_2 , V_137 , NULL ) ;
V_11 -> V_41 = V_86 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_143 = 1 ;
V_115:
return V_11 ;
}
static void F_125 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_70 ( V_11 ) ;
int V_133 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_69 ( V_2 , V_11 ) ;
F_124 (p, s, page_address(page),
page->objects)
F_71 ( V_2 , V_11 , V_5 , V_110 ) ;
}
F_126 ( V_11 , F_70 ( V_11 ) ) ;
F_115 ( F_116 ( V_11 ) ,
( V_2 -> V_3 & V_134 ) ?
V_135 : V_136 ,
- V_133 ) ;
F_127 ( V_11 ) ;
F_128 ( V_11 ) ;
F_129 ( V_2 , V_25 ) ;
F_130 ( V_11 ) ;
if ( V_66 -> V_144 )
V_66 -> V_144 -> V_145 += V_133 ;
F_131 ( V_11 , V_25 ) ;
}
static void F_132 ( struct V_146 * V_147 )
{
struct V_11 * V_11 ;
if ( V_148 )
V_11 = F_133 ( V_147 ) ;
else
V_11 = F_134 ( (struct V_149 * ) V_147 , struct V_11 , V_106 ) ;
F_125 ( V_11 -> V_141 , V_11 ) ;
}
static void F_135 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_146 * V_150 ;
if ( V_148 ) {
int V_25 = F_70 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_32 ( V_2 -> V_26 != sizeof( * V_150 ) ) ;
V_150 = F_13 ( V_11 ) + V_16 ;
} else {
V_150 = ( void * ) & V_11 -> V_106 ;
}
F_136 ( V_150 , F_132 ) ;
} else
F_125 ( V_2 , V_11 ) ;
}
static void F_137 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_97 ( V_2 , F_120 ( V_11 ) , V_11 -> V_14 ) ;
F_135 ( V_2 , V_11 ) ;
}
static inline void F_138 ( struct V_9 * V_37 ,
struct V_11 * V_11 , int V_151 )
{
V_37 -> V_152 ++ ;
if ( V_151 == V_153 )
F_139 ( & V_11 -> V_106 , & V_37 -> V_154 ) ;
else
F_88 ( & V_11 -> V_106 , & V_37 -> V_154 ) ;
}
static inline void F_140 ( struct V_9 * V_37 ,
struct V_11 * V_11 )
{
F_90 ( & V_11 -> V_106 ) ;
V_37 -> V_152 -- ;
}
static inline void * F_141 ( struct V_1 * V_2 ,
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
F_32 ( V_156 . V_143 ) ;
V_156 . V_143 = 1 ;
if ( ! F_31 ( V_2 , V_11 ,
V_41 , V_42 ,
V_156 . V_41 , V_156 . V_42 ,
L_47 ) )
return NULL ;
F_140 ( V_37 , V_11 ) ;
F_142 ( ! V_41 ) ;
return V_41 ;
}
static void * F_143 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_157 * V_158 , T_5 V_3 )
{
struct V_11 * V_11 , * V_159 ;
void * V_12 = NULL ;
if ( ! V_37 || ! V_37 -> V_152 )
return NULL ;
F_144 ( & V_37 -> V_160 ) ;
F_145 (page, page2, &n->partial, lru) {
void * V_71 ;
int V_161 ;
if ( ! F_146 ( V_11 , V_3 ) )
continue;
V_71 = F_141 ( V_2 , V_37 , V_11 , V_12 == NULL ) ;
if ( ! V_71 )
break;
if ( ! V_12 ) {
V_158 -> V_11 = V_11 ;
F_8 ( V_2 , V_162 ) ;
V_12 = V_71 ;
V_161 = V_11 -> V_14 - V_11 -> V_24 ;
} else {
V_161 = F_147 ( V_2 , V_11 , 0 ) ;
F_8 ( V_2 , V_163 ) ;
}
if ( F_1 ( V_2 ) || V_161 > V_2 -> V_164 / 2 )
break;
}
F_148 ( & V_37 -> V_160 ) ;
return V_12 ;
}
static void * F_149 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_157 * V_158 )
{
#ifdef F_150
struct V_165 * V_165 ;
struct V_166 * V_167 ;
struct V_168 * V_168 ;
enum V_169 V_170 = F_151 ( V_3 ) ;
void * V_12 ;
unsigned int V_171 ;
if ( ! V_2 -> V_172 ||
F_152 () % 1024 > V_2 -> V_172 )
return NULL ;
do {
V_171 = F_153 () ;
V_165 = F_154 ( F_155 () , V_3 ) ;
F_156 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_37 ;
V_37 = F_11 ( V_2 , F_157 ( V_168 ) ) ;
if ( V_37 && F_158 ( V_168 , V_3 ) &&
V_37 -> V_152 > V_2 -> V_173 ) {
V_12 = F_143 ( V_2 , V_37 , V_158 , V_3 ) ;
if ( V_12 ) {
F_159 ( V_171 ) ;
return V_12 ;
}
}
}
} while ( ! F_159 ( V_171 ) );
#endif
return NULL ;
}
static void * F_160 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_157 * V_158 )
{
void * V_12 ;
int V_174 = ( V_10 == V_123 ) ? F_161 () : V_10 ;
V_12 = F_143 ( V_2 , F_11 ( V_2 , V_174 ) , V_158 , V_3 ) ;
if ( V_12 || V_10 != V_123 )
return V_12 ;
return F_149 ( V_2 , V_3 , V_158 ) ;
}
static inline unsigned long F_162 ( unsigned long V_175 )
{
return V_175 + V_176 ;
}
static inline unsigned int F_163 ( unsigned long V_175 )
{
return V_175 % V_176 ;
}
static inline unsigned long F_164 ( unsigned long V_175 )
{
return V_175 / V_176 ;
}
static inline unsigned int F_165 ( int V_64 )
{
return V_64 ;
}
static inline void F_166 ( const char * V_37 ,
const struct V_1 * V_2 , unsigned long V_175 )
{
#ifdef F_37
unsigned long V_177 = F_167 ( V_2 -> V_8 -> V_175 ) ;
F_38 ( V_44 L_48 , V_37 , V_2 -> V_45 ) ;
#ifdef F_168
if ( F_163 ( V_175 ) != F_163 ( V_177 ) )
F_38 ( L_49 ,
F_163 ( V_175 ) , F_163 ( V_177 ) ) ;
else
#endif
if ( F_164 ( V_175 ) != F_164 ( V_177 ) )
F_38 ( L_50 ,
F_164 ( V_175 ) , F_164 ( V_177 ) ) ;
else
F_38 ( L_51 ,
V_177 , V_175 , F_162 ( V_175 ) ) ;
#endif
F_8 ( V_2 , V_178 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
int V_64 ;
F_170 (cpu)
F_171 ( V_2 -> V_8 , V_64 ) -> V_175 = F_165 ( V_64 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_41 )
{
enum T_8 { V_179 , V_180 , V_181 , V_182 };
struct V_9 * V_37 = F_11 ( V_2 , F_120 ( V_11 ) ) ;
int V_183 = 0 ;
enum T_8 V_184 = V_179 , V_185 = V_179 ;
void * V_186 ;
int V_151 = V_187 ;
struct V_11 V_156 ;
struct V_11 V_188 ;
if ( V_11 -> V_41 ) {
F_8 ( V_2 , V_189 ) ;
V_151 = V_153 ;
}
while ( V_41 && ( V_186 = F_14 ( V_2 , V_41 ) ) ) {
void * V_190 ;
unsigned long V_42 ;
do {
V_190 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_20 ( V_2 , V_41 , V_190 ) ;
V_156 . V_42 = V_42 ;
V_156 . V_24 -- ;
F_32 ( ! V_156 . V_143 ) ;
} while ( ! F_31 ( V_2 , V_11 ,
V_190 , V_42 ,
V_41 , V_156 . V_42 ,
L_52 ) );
V_41 = V_186 ;
}
V_191:
V_188 . V_41 = V_11 -> V_41 ;
V_188 . V_42 = V_11 -> V_42 ;
F_32 ( ! V_188 . V_143 ) ;
V_156 . V_42 = V_188 . V_42 ;
if ( V_41 ) {
V_156 . V_24 -- ;
F_20 ( V_2 , V_41 , V_188 . V_41 ) ;
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
F_144 ( & V_37 -> V_160 ) ;
}
} else {
V_185 = V_181 ;
if ( F_1 ( V_2 ) && ! V_183 ) {
V_183 = 1 ;
F_144 ( & V_37 -> V_160 ) ;
}
}
if ( V_184 != V_185 ) {
if ( V_184 == V_180 )
F_140 ( V_37 , V_11 ) ;
else if ( V_184 == V_181 )
F_89 ( V_2 , V_11 ) ;
if ( V_185 == V_180 ) {
F_138 ( V_37 , V_11 , V_151 ) ;
F_8 ( V_2 , V_151 ) ;
} else if ( V_185 == V_181 ) {
F_8 ( V_2 , V_192 ) ;
F_87 ( V_2 , V_37 , V_11 ) ;
}
}
V_184 = V_185 ;
if ( ! F_31 ( V_2 , V_11 ,
V_188 . V_41 , V_188 . V_42 ,
V_156 . V_41 , V_156 . V_42 ,
L_53 ) )
goto V_191;
if ( V_183 )
F_148 ( & V_37 -> V_160 ) ;
if ( V_185 == V_182 ) {
F_8 ( V_2 , V_193 ) ;
F_137 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_194 ) ;
}
}
static void F_173 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_9 * V_37 = NULL , * V_195 = NULL ;
struct V_11 * V_11 , * V_196 = NULL ;
while ( ( V_11 = V_158 -> V_154 ) ) {
struct V_11 V_156 ;
struct V_11 V_188 ;
V_158 -> V_154 = V_11 -> V_197 ;
V_195 = F_11 ( V_2 , F_120 ( V_11 ) ) ;
if ( V_37 != V_195 ) {
if ( V_37 )
F_148 ( & V_37 -> V_160 ) ;
V_37 = V_195 ;
F_144 ( & V_37 -> V_160 ) ;
}
do {
V_188 . V_41 = V_11 -> V_41 ;
V_188 . V_42 = V_11 -> V_42 ;
F_32 ( ! V_188 . V_143 ) ;
V_156 . V_42 = V_188 . V_42 ;
V_156 . V_41 = V_188 . V_41 ;
V_156 . V_143 = 0 ;
} while ( ! F_31 ( V_2 , V_11 ,
V_188 . V_41 , V_188 . V_42 ,
V_156 . V_41 , V_156 . V_42 ,
L_53 ) );
if ( F_3 ( ! V_156 . V_24 && V_37 -> V_152 > V_2 -> V_173 ) ) {
V_11 -> V_197 = V_196 ;
V_196 = V_11 ;
} else {
F_138 ( V_37 , V_11 , V_153 ) ;
F_8 ( V_2 , V_198 ) ;
}
}
if ( V_37 )
F_148 ( & V_37 -> V_160 ) ;
while ( V_196 ) {
V_11 = V_196 ;
V_196 = V_196 -> V_197 ;
F_8 ( V_2 , V_193 ) ;
F_137 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_194 ) ;
}
}
static int F_147 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_199 )
{
struct V_11 * V_200 ;
int V_133 ;
int V_201 ;
do {
V_133 = 0 ;
V_201 = 0 ;
V_200 = F_174 ( V_2 -> V_8 -> V_154 ) ;
if ( V_200 ) {
V_201 = V_200 -> V_201 ;
V_133 = V_200 -> V_133 ;
if ( V_199 && V_201 > V_2 -> V_164 ) {
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_173 ( V_2 , F_175 ( V_2 -> V_8 ) ) ;
F_41 ( V_3 ) ;
V_200 = NULL ;
V_201 = 0 ;
V_133 = 0 ;
F_8 ( V_2 , V_202 ) ;
}
}
V_133 ++ ;
V_201 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_133 = V_133 ;
V_11 -> V_201 = V_201 ;
V_11 -> V_197 = V_200 ;
} while ( F_176 ( V_2 -> V_8 -> V_154 , V_200 , V_11 ) != V_200 );
return V_201 ;
}
static inline void F_177 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
F_8 ( V_2 , V_203 ) ;
F_172 ( V_2 , V_158 -> V_11 , V_158 -> V_41 ) ;
V_158 -> V_175 = F_162 ( V_158 -> V_175 ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
}
static inline void F_178 ( struct V_1 * V_2 , int V_64 )
{
struct V_157 * V_158 = F_171 ( V_2 -> V_8 , V_64 ) ;
if ( F_179 ( V_158 ) ) {
if ( V_158 -> V_11 )
F_177 ( V_2 , V_158 ) ;
F_173 ( V_2 , V_158 ) ;
}
}
static void F_180 ( void * V_204 )
{
struct V_1 * V_2 = V_204 ;
F_178 ( V_2 , F_50 () ) ;
}
static bool F_181 ( int V_64 , void * V_205 )
{
struct V_1 * V_2 = V_205 ;
struct V_157 * V_158 = F_171 ( V_2 -> V_8 , V_64 ) ;
return V_158 -> V_11 || V_158 -> V_154 ;
}
static void F_182 ( struct V_1 * V_2 )
{
F_183 ( F_181 , F_180 , V_2 , 1 , V_206 ) ;
}
static inline int F_184 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_150
if ( V_10 != V_123 && F_120 ( V_11 ) != V_10 )
return 0 ;
#endif
return 1 ;
}
static int F_185 ( struct V_11 * V_11 )
{
return V_11 -> V_14 - V_11 -> V_24 ;
}
static unsigned long F_186 ( struct V_9 * V_37 ,
int (* F_187)( struct V_11 * ) )
{
unsigned long V_3 ;
unsigned long V_29 = 0 ;
struct V_11 * V_11 ;
F_188 ( & V_37 -> V_160 , V_3 ) ;
F_189 (page, &n->partial, lru)
V_29 += F_187 ( V_11 ) ;
F_190 ( & V_37 -> V_160 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_191 ( struct V_9 * V_37 )
{
#ifdef F_2
return F_92 ( & V_37 -> V_109 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_192 ( struct V_1 * V_2 , T_5 V_207 , int V_208 )
{
int V_10 ;
F_38 ( V_209
L_54 ,
V_208 , V_207 ) ;
F_38 ( V_209 L_55
L_56 , V_2 -> V_45 , V_2 -> V_21 ,
V_2 -> V_15 , F_25 ( V_2 -> V_121 ) , F_25 ( V_2 -> V_129 ) ) ;
if ( F_25 ( V_2 -> V_129 ) > F_193 ( V_2 -> V_21 ) )
F_38 ( V_209 L_57
L_58 , V_2 -> V_45 ) ;
F_194 (node) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
unsigned long V_108 ;
unsigned long V_210 ;
unsigned long V_211 ;
if ( ! V_37 )
continue;
V_211 = F_186 ( V_37 , F_185 ) ;
V_108 = F_93 ( V_37 ) ;
V_210 = F_191 ( V_37 ) ;
F_38 ( V_209
L_59 ,
V_10 , V_108 , V_210 , V_211 ) ;
}
}
static inline void * F_195 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_157 * * V_212 )
{
void * V_41 ;
struct V_157 * V_158 = * V_212 ;
struct V_11 * V_11 ;
V_41 = F_160 ( V_2 , V_3 , V_10 , V_158 ) ;
if ( V_41 )
return V_41 ;
V_11 = F_118 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_158 = F_196 ( V_2 -> V_8 ) ;
if ( V_158 -> V_11 )
F_177 ( V_2 , V_158 ) ;
V_41 = V_11 -> V_41 ;
V_11 -> V_41 = NULL ;
F_8 ( V_2 , V_213 ) ;
V_158 -> V_11 = V_11 ;
* V_212 = V_158 ;
} else
V_41 = NULL ;
return V_41 ;
}
static inline bool F_146 ( struct V_11 * V_11 , T_5 V_207 )
{
if ( F_3 ( F_197 ( V_11 ) ) )
return F_198 ( V_207 ) ;
return true ;
}
static inline void * F_199 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_156 ;
unsigned long V_42 ;
void * V_41 ;
do {
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_156 . V_42 = V_42 ;
F_32 ( ! V_156 . V_143 ) ;
V_156 . V_24 = V_11 -> V_14 ;
V_156 . V_143 = V_41 != NULL ;
} while ( ! F_31 ( V_2 , V_11 ,
V_41 , V_42 ,
NULL , V_156 . V_42 ,
L_60 ) );
return V_41 ;
}
static void * F_200 ( struct V_1 * V_2 , T_5 V_207 , int V_10 ,
unsigned long V_18 , struct V_157 * V_158 )
{
void * V_41 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_40 ( V_3 ) ;
#ifdef F_168
V_158 = F_175 ( V_2 -> V_8 ) ;
#endif
V_11 = V_158 -> V_11 ;
if ( ! V_11 )
goto F_118;
V_191:
if ( F_3 ( ! F_184 ( V_11 , V_10 ) ) ) {
F_8 ( V_2 , V_214 ) ;
F_172 ( V_2 , V_11 , V_158 -> V_41 ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
goto F_118;
}
if ( F_3 ( ! F_146 ( V_11 , V_207 ) ) ) {
F_172 ( V_2 , V_11 , V_158 -> V_41 ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
goto F_118;
}
V_41 = V_158 -> V_41 ;
if ( V_41 )
goto V_215;
F_8 ( V_2 , V_216 ) ;
V_41 = F_199 ( V_2 , V_11 ) ;
if ( ! V_41 ) {
V_158 -> V_11 = NULL ;
F_8 ( V_2 , V_217 ) ;
goto F_118;
}
F_8 ( V_2 , V_218 ) ;
V_215:
F_32 ( ! V_158 -> V_11 -> V_143 ) ;
V_158 -> V_41 = F_14 ( V_2 , V_41 ) ;
V_158 -> V_175 = F_162 ( V_158 -> V_175 ) ;
F_41 ( V_3 ) ;
return V_41 ;
F_118:
if ( V_158 -> V_154 ) {
V_11 = V_158 -> V_11 = V_158 -> V_154 ;
V_158 -> V_154 = V_11 -> V_197 ;
F_8 ( V_2 , V_219 ) ;
V_158 -> V_41 = NULL ;
goto V_191;
}
V_41 = F_195 ( V_2 , V_207 , V_10 , & V_158 ) ;
if ( F_3 ( ! V_41 ) ) {
if ( ! ( V_207 & V_126 ) && F_201 () )
F_192 ( V_2 , V_207 , V_10 ) ;
F_41 ( V_3 ) ;
return NULL ;
}
V_11 = V_158 -> V_11 ;
if ( F_179 ( ! F_1 ( V_2 ) && F_146 ( V_11 , V_207 ) ) )
goto V_215;
if ( F_1 ( V_2 ) && ! F_101 ( V_2 , V_11 , V_41 , V_18 ) )
goto F_118;
F_172 ( V_2 , V_11 , F_14 ( V_2 , V_41 ) ) ;
V_158 -> V_11 = NULL ;
V_158 -> V_41 = NULL ;
F_41 ( V_3 ) ;
return V_41 ;
}
static T_2 void * F_202 ( struct V_1 * V_2 ,
T_5 V_207 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_157 * V_158 ;
struct V_11 * V_11 ;
unsigned long V_175 ;
if ( F_75 ( V_2 , V_207 ) )
return NULL ;
V_2 = F_203 ( V_2 , V_207 ) ;
V_191:
V_158 = F_196 ( V_2 -> V_8 ) ;
V_175 = V_158 -> V_175 ;
F_204 () ;
V_12 = V_158 -> V_41 ;
V_11 = V_158 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_184 ( V_11 , V_10 ) ) )
V_12 = F_200 ( V_2 , V_207 , V_10 , V_18 , V_158 ) ;
else {
void * V_220 = F_17 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_205 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_175 ,
V_12 , V_175 ,
V_220 , F_162 ( V_175 ) ) ) ) {
F_166 ( L_61 , V_2 , V_175 ) ;
goto V_191;
}
F_15 ( V_2 , V_220 ) ;
F_8 ( V_2 , V_221 ) ;
}
if ( F_3 ( V_207 & V_222 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_79 ( V_2 , V_207 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_206 ( struct V_1 * V_2 ,
T_5 V_207 , unsigned long V_18 )
{
return F_202 ( V_2 , V_207 , V_123 , V_18 ) ;
}
void * F_207 ( struct V_1 * V_2 , T_5 V_207 )
{
void * V_223 = F_206 ( V_2 , V_207 , V_224 ) ;
F_208 ( V_224 , V_223 , V_2 -> V_21 , V_2 -> V_15 , V_207 ) ;
return V_223 ;
}
void * F_209 ( struct V_1 * V_2 , T_5 V_207 , T_1 V_15 )
{
void * V_223 = F_206 ( V_2 , V_207 , V_224 ) ;
F_210 ( V_224 , V_223 , V_15 , V_2 -> V_15 , V_207 ) ;
return V_223 ;
}
void * F_211 ( T_1 V_15 , T_5 V_3 , unsigned int V_25 )
{
void * V_223 = F_212 ( V_15 , V_3 , V_25 ) ;
F_210 ( V_224 , V_223 , V_15 , V_27 << V_25 , V_3 ) ;
return V_223 ;
}
void * F_213 ( struct V_1 * V_2 , T_5 V_207 , int V_10 )
{
void * V_223 = F_202 ( V_2 , V_207 , V_10 , V_224 ) ;
F_214 ( V_224 , V_223 ,
V_2 -> V_21 , V_2 -> V_15 , V_207 , V_10 ) ;
return V_223 ;
}
void * F_215 ( struct V_1 * V_2 ,
T_5 V_207 ,
int V_10 , T_1 V_15 )
{
void * V_223 = F_202 ( V_2 , V_207 , V_10 , V_224 ) ;
F_216 ( V_224 , V_223 ,
V_15 , V_2 -> V_15 , V_207 , V_10 ) ;
return V_223 ;
}
static void F_217 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_190 ;
void * * V_12 = ( void * ) V_29 ;
int V_225 ;
struct V_11 V_156 ;
unsigned long V_42 ;
struct V_9 * V_37 = NULL ;
unsigned long V_226 ( V_3 ) ;
F_8 ( V_2 , V_227 ) ;
if ( F_1 ( V_2 ) &&
! ( V_37 = F_105 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_37 ) ) {
F_190 ( & V_37 -> V_160 , V_3 ) ;
V_37 = NULL ;
}
V_190 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_20 ( V_2 , V_12 , V_190 ) ;
V_156 . V_42 = V_42 ;
V_225 = V_156 . V_143 ;
V_156 . V_24 -- ;
if ( ( ! V_156 . V_24 || ! V_190 ) && ! V_225 ) {
if ( ! F_1 ( V_2 ) && ! V_190 )
V_156 . V_143 = 1 ;
else {
V_37 = F_11 ( V_2 , F_120 ( V_11 ) ) ;
F_188 ( & V_37 -> V_160 , V_3 ) ;
}
}
} while ( ! F_39 ( V_2 , V_11 ,
V_190 , V_42 ,
V_12 , V_156 . V_42 ,
L_62 ) );
if ( F_179 ( ! V_37 ) ) {
if ( V_156 . V_143 && ! V_225 ) {
F_147 ( V_2 , V_11 , 1 ) ;
F_8 ( V_2 , V_228 ) ;
}
if ( V_225 )
F_8 ( V_2 , V_229 ) ;
return;
}
if ( F_3 ( ! V_156 . V_24 && V_37 -> V_152 > V_2 -> V_173 ) )
goto V_230;
if ( F_1 ( V_2 ) && F_3 ( ! V_190 ) ) {
F_89 ( V_2 , V_11 ) ;
F_138 ( V_37 , V_11 , V_153 ) ;
F_8 ( V_2 , V_198 ) ;
}
F_190 ( & V_37 -> V_160 , V_3 ) ;
return;
V_230:
if ( V_190 ) {
F_140 ( V_37 , V_11 ) ;
F_8 ( V_2 , V_231 ) ;
} else
F_89 ( V_2 , V_11 ) ;
F_190 ( & V_37 -> V_160 , V_3 ) ;
F_8 ( V_2 , V_194 ) ;
F_137 ( V_2 , V_11 ) ;
}
static T_2 void F_218 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_157 * V_158 ;
unsigned long V_175 ;
F_82 ( V_2 , V_29 ) ;
V_191:
V_158 = F_196 ( V_2 -> V_8 ) ;
V_175 = V_158 -> V_175 ;
F_204 () ;
if ( F_179 ( V_11 == V_158 -> V_11 ) ) {
F_20 ( V_2 , V_12 , V_158 -> V_41 ) ;
if ( F_3 ( ! F_205 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_175 ,
V_158 -> V_41 , V_175 ,
V_12 , F_162 ( V_175 ) ) ) ) {
F_166 ( L_63 , V_2 , V_175 ) ;
goto V_191;
}
F_8 ( V_2 , V_232 ) ;
} else
F_217 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_219 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_220 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_218 ( V_2 , F_133 ( V_29 ) , V_29 , V_224 ) ;
F_221 ( V_224 , V_29 ) ;
}
static inline int F_222 ( int V_15 , int V_233 ,
int V_234 , int V_235 , int V_26 )
{
int V_25 ;
int V_236 ;
int V_237 = V_238 ;
if ( F_23 ( V_237 , V_15 , V_26 ) > V_99 )
return F_193 ( V_15 * V_99 ) - 1 ;
for ( V_25 = F_223 ( V_237 ,
F_224 ( V_233 * V_15 - 1 ) - V_239 ) ;
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
static inline int F_225 ( int V_15 , int V_26 )
{
int V_25 ;
int V_233 ;
int V_241 ;
int V_98 ;
V_233 = V_242 ;
if ( ! V_233 )
V_233 = 4 * ( F_224 ( V_243 ) + 1 ) ;
V_98 = F_23 ( V_244 , V_15 , V_26 ) ;
V_233 = V_129 ( V_233 , V_98 ) ;
while ( V_233 > 1 ) {
V_241 = 16 ;
while ( V_241 >= 4 ) {
V_25 = F_222 ( V_15 , V_233 ,
V_244 , V_241 , V_26 ) ;
if ( V_25 <= V_244 )
return V_25 ;
V_241 /= 2 ;
}
V_233 -- ;
}
V_25 = F_222 ( V_15 , 1 , V_244 , 1 , V_26 ) ;
if ( V_25 <= V_244 )
return V_25 ;
V_25 = F_222 ( V_15 , 1 , V_245 , 1 , V_26 ) ;
if ( V_25 < V_245 )
return V_25 ;
return - V_246 ;
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
F_231 ( V_247 <
V_248 * sizeof( struct V_157 ) ) ;
V_2 -> V_8 = F_232 ( sizeof( struct V_157 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_8 )
return 0 ;
F_169 ( V_2 ) ;
return 1 ;
}
static void F_233 ( int V_10 )
{
struct V_11 * V_11 ;
struct V_9 * V_37 ;
F_119 ( V_9 -> V_15 < sizeof( struct V_9 ) ) ;
V_11 = F_118 ( V_9 , V_249 , V_10 ) ;
F_119 ( ! V_11 ) ;
if ( F_120 ( V_11 ) != V_10 ) {
F_38 ( V_49 L_64
L_65 , V_10 ) ;
F_38 ( V_49 L_66
L_67 ) ;
}
V_37 = V_11 -> V_41 ;
F_119 ( ! V_37 ) ;
V_11 -> V_41 = F_14 ( V_9 , V_37 ) ;
V_11 -> V_24 = 1 ;
V_11 -> V_143 = 0 ;
V_9 -> V_10 [ V_10 ] = V_37 ;
#ifdef F_2
F_64 ( V_9 , V_37 , V_94 ) ;
F_51 ( V_9 , V_37 ) ;
#endif
F_226 ( V_37 ) ;
F_94 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_138 ( V_37 , V_11 , V_187 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
int V_10 ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = V_2 -> V_10 [ V_10 ] ;
if ( V_37 )
F_219 ( V_9 , V_37 ) ;
V_2 -> V_10 [ V_10 ] = NULL ;
}
}
static int F_236 ( struct V_1 * V_2 )
{
int V_10 ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 ;
if ( V_250 == V_251 ) {
F_233 ( V_10 ) ;
continue;
}
V_37 = F_213 ( V_9 ,
V_252 , V_10 ) ;
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
if ( V_129 < V_253 )
V_129 = V_253 ;
else if ( V_129 > V_254 )
V_129 = V_254 ;
V_2 -> V_173 = V_129 ;
}
static int F_238 ( struct V_1 * V_2 , int V_255 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_239 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_104 )
V_2 -> V_3 |= V_78 ;
else
V_2 -> V_3 &= ~ V_78 ;
if ( ( V_3 & V_19 ) && V_15 == V_2 -> V_21 )
V_15 += sizeof( void * ) ;
#endif
V_2 -> V_24 = V_15 ;
if ( ( ( V_3 & ( V_22 | V_20 ) ) ||
V_2 -> F_104 ) ) {
V_2 -> V_16 = V_15 ;
V_15 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_23 )
V_15 += 2 * sizeof( struct V_51 ) ;
if ( V_3 & V_19 )
V_15 += sizeof( void * ) ;
#endif
V_15 = F_239 ( V_15 , V_2 -> V_256 ) ;
V_2 -> V_15 = V_15 ;
if ( V_255 >= 0 )
V_25 = V_255 ;
else
V_25 = F_225 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_125 = 0 ;
if ( V_25 )
V_2 -> V_125 |= V_257 ;
if ( V_2 -> V_3 & V_258 )
V_2 -> V_125 |= V_259 ;
if ( V_2 -> V_3 & V_134 )
V_2 -> V_125 |= V_260 ;
V_2 -> V_121 = F_24 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_129 = F_24 ( F_193 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_26 ( V_2 -> V_121 ) > F_26 ( V_2 -> F_223 ) )
V_2 -> F_223 = V_2 -> V_121 ;
return ! ! F_26 ( V_2 -> V_121 ) ;
}
static int F_240 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_103 ( V_2 -> V_15 , V_3 , V_2 -> V_45 , V_2 -> F_104 ) ;
V_2 -> V_26 = 0 ;
if ( V_148 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_146 ) ;
if ( ! F_238 ( V_2 , - 1 ) )
goto error;
if ( V_117 ) {
if ( F_193 ( V_2 -> V_15 ) > F_193 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_261 ;
V_2 -> V_16 = 0 ;
if ( ! F_238 ( V_2 , - 1 ) )
goto error;
}
}
#if F_34 ( V_38 ) && \
F_34 ( V_39 )
if ( F_241 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_40 ;
#endif
F_237 ( V_2 , F_242 ( V_2 -> V_15 ) / 2 ) ;
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
#ifdef F_150
V_2 -> V_172 = 1000 ;
#endif
if ( ! F_236 ( V_2 ) )
goto error;
if ( F_230 ( V_2 ) )
return 0 ;
F_234 ( V_2 ) ;
error:
if ( V_3 & V_262 )
F_243 ( L_68
L_69 ,
V_2 -> V_45 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 , F_25 ( V_2 -> V_121 ) ,
V_2 -> V_16 , V_3 ) ;
return - V_263 ;
}
static void F_244 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_47 )
{
#ifdef F_2
void * V_18 = F_13 ( V_11 ) ;
void * V_5 ;
unsigned long * V_46 = F_245 ( F_246 ( V_11 -> V_14 ) *
sizeof( long ) , V_206 ) ;
if ( ! V_46 )
return;
F_63 ( V_2 , V_11 , V_47 , V_2 -> V_45 ) ;
F_27 ( V_11 ) ;
F_42 ( V_2 , V_11 , V_46 ) ;
F_124 (p, s, addr, page->objects) {
if ( ! F_247 ( F_21 ( V_5 , V_2 , V_18 ) , V_46 ) ) {
F_38 ( V_49 L_70 ,
V_5 , V_5 - V_18 ) ;
F_53 ( V_2 , V_5 ) ;
}
}
F_29 ( V_11 ) ;
F_248 ( V_46 ) ;
#endif
}
static void F_249 ( struct V_1 * V_2 , struct V_9 * V_37 )
{
struct V_11 * V_11 , * V_147 ;
F_145 (page, h, &n->partial, lru) {
if ( ! V_11 -> V_24 ) {
F_140 ( V_37 , V_11 ) ;
F_137 ( V_2 , V_11 ) ;
} else {
F_244 ( V_2 , V_11 ,
L_71 ) ;
}
}
}
static inline int F_250 ( struct V_1 * V_2 )
{
int V_10 ;
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
F_249 ( V_2 , V_37 ) ;
if ( V_37 -> V_152 || F_91 ( V_2 , V_10 ) )
return 1 ;
}
F_251 ( V_2 -> V_8 ) ;
F_234 ( V_2 ) ;
return 0 ;
}
int F_252 ( struct V_1 * V_2 )
{
int V_264 = F_250 ( V_2 ) ;
if ( ! V_264 ) {
F_253 ( & V_265 ) ;
F_6 ( V_2 ) ;
F_254 ( & V_265 ) ;
}
return V_264 ;
}
static int T_7 F_255 ( char * V_112 )
{
F_256 ( & V_112 , & V_238 ) ;
return 1 ;
}
static int T_7 F_257 ( char * V_112 )
{
F_256 ( & V_112 , & V_244 ) ;
V_244 = V_129 ( V_244 , V_245 - 1 ) ;
return 1 ;
}
static int T_7 F_258 ( char * V_112 )
{
F_256 ( & V_112 , & V_242 ) ;
return 1 ;
}
static int T_7 F_259 ( char * V_112 )
{
V_266 = 1 ;
return 1 ;
}
static inline int F_260 ( T_1 V_88 )
{
return ( V_88 - 1 ) / 8 ;
}
static struct V_1 * F_261 ( T_1 V_15 , T_5 V_3 )
{
int V_267 ;
if ( V_15 <= 192 ) {
if ( ! V_15 )
return V_268 ;
V_267 = V_269 [ F_260 ( V_15 ) ] ;
} else
V_267 = F_224 ( V_15 - 1 ) ;
#ifdef F_262
if ( F_3 ( ( V_3 & V_259 ) ) )
return V_270 [ V_267 ] ;
#endif
return V_271 [ V_267 ] ;
}
void * F_263 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_272 ) )
return F_264 ( V_15 , V_3 ) ;
V_2 = F_261 ( V_15 , V_3 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_206 ( V_2 , V_3 , V_224 ) ;
F_210 ( V_224 , V_223 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_223 ;
}
static void * F_266 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_273 = NULL ;
V_3 |= V_257 | V_122 | V_274 ;
V_11 = F_267 ( V_10 , V_3 , F_193 ( V_15 ) ) ;
if ( V_11 )
V_273 = F_13 ( V_11 ) ;
F_268 ( V_273 , V_15 , 1 , V_3 ) ;
return V_273 ;
}
void * F_269 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_272 ) ) {
V_223 = F_266 ( V_15 , V_3 , V_10 ) ;
F_216 ( V_224 , V_223 ,
V_15 , V_27 << F_193 ( V_15 ) ,
V_3 , V_10 ) ;
return V_223 ;
}
V_2 = F_261 ( V_15 , V_3 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_202 ( V_2 , V_3 , V_10 , V_224 ) ;
F_216 ( V_224 , V_223 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_223 ;
}
T_1 F_270 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_268 ) )
return 0 ;
V_11 = F_133 ( V_12 ) ;
if ( F_3 ( ! F_73 ( V_11 ) ) ) {
F_142 ( ! F_271 ( V_11 ) ) ;
return V_27 << F_70 ( V_11 ) ;
}
return F_22 ( V_11 -> V_141 ) ;
}
bool F_272 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
unsigned long V_3 ;
bool V_275 ;
if ( F_3 ( F_265 ( V_29 ) ) )
return false ;
F_40 ( V_3 ) ;
V_11 = F_133 ( V_29 ) ;
if ( F_3 ( ! F_73 ( V_11 ) ) ) {
V_275 = true ;
goto V_276;
}
F_27 ( V_11 ) ;
if ( F_74 ( V_11 -> V_141 , V_11 , V_12 ) ) {
F_62 ( V_11 -> V_141 , V_11 , V_12 , L_72 ) ;
V_275 = false ;
} else {
V_275 = true ;
}
F_29 ( V_11 ) ;
V_276:
F_41 ( V_3 ) ;
return V_275 ;
}
void F_248 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_273 ( V_224 , V_29 ) ;
if ( F_3 ( F_265 ( V_29 ) ) )
return;
V_11 = F_133 ( V_29 ) ;
if ( F_3 ( ! F_73 ( V_11 ) ) ) {
F_119 ( ! F_271 ( V_11 ) ) ;
F_274 ( V_29 ) ;
F_131 ( V_11 , F_70 ( V_11 ) ) ;
return;
}
F_218 ( V_11 -> V_141 , V_11 , V_12 , V_224 ) ;
}
int F_275 ( struct V_1 * V_2 )
{
int V_10 ;
int V_56 ;
struct V_9 * V_37 ;
struct V_11 * V_11 ;
struct V_11 * V_71 ;
int V_14 = F_26 ( V_2 -> F_223 ) ;
struct V_149 * V_277 =
F_276 ( sizeof( struct V_149 ) * V_14 , V_252 ) ;
unsigned long V_3 ;
if ( ! V_277 )
return - V_278 ;
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
V_37 = F_11 ( V_2 , V_10 ) ;
if ( ! V_37 -> V_152 )
continue;
for ( V_56 = 0 ; V_56 < V_14 ; V_56 ++ )
F_228 ( V_277 + V_56 ) ;
F_188 ( & V_37 -> V_160 , V_3 ) ;
F_145 (page, t, &n->partial, lru) {
F_277 ( & V_11 -> V_106 , V_277 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_37 -> V_152 -- ;
}
for ( V_56 = V_14 - 1 ; V_56 > 0 ; V_56 -- )
F_278 ( V_277 + V_56 , V_37 -> V_154 . V_279 ) ;
F_190 ( & V_37 -> V_160 , V_3 ) ;
F_145 (page, t, slabs_by_inuse, lru)
F_137 ( V_2 , V_11 ) ;
}
F_248 ( V_277 ) ;
return 0 ;
}
static int F_279 ( void * V_280 )
{
struct V_1 * V_2 ;
F_254 ( & V_265 ) ;
F_189 (s, &slab_caches, list)
F_275 ( V_2 ) ;
F_253 ( & V_265 ) ;
return 0 ;
}
static void F_280 ( void * V_280 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_281 * V_282 = V_280 ;
int V_283 ;
V_283 = V_282 -> V_284 ;
if ( V_283 < 0 )
return;
F_254 ( & V_265 ) ;
F_189 (s, &slab_caches, list) {
V_37 = F_11 ( V_2 , V_283 ) ;
if ( V_37 ) {
F_119 ( F_91 ( V_2 , V_283 ) ) ;
V_2 -> V_10 [ V_283 ] = NULL ;
F_219 ( V_9 , V_37 ) ;
}
}
F_253 ( & V_265 ) ;
}
static int F_281 ( void * V_280 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_281 * V_282 = V_280 ;
int V_208 = V_282 -> V_284 ;
int V_223 = 0 ;
if ( V_208 < 0 )
return 0 ;
F_254 ( & V_265 ) ;
F_189 (s, &slab_caches, list) {
V_37 = F_207 ( V_9 , V_252 ) ;
if ( ! V_37 ) {
V_223 = - V_278 ;
goto V_115;
}
F_226 ( V_37 ) ;
V_2 -> V_10 [ V_208 ] = V_37 ;
}
V_115:
F_253 ( & V_265 ) ;
return V_223 ;
}
static int F_282 ( struct V_285 * V_286 ,
unsigned long V_287 , void * V_280 )
{
int V_223 = 0 ;
switch ( V_287 ) {
case V_288 :
V_223 = F_281 ( V_280 ) ;
break;
case V_289 :
V_223 = F_279 ( V_280 ) ;
break;
case V_290 :
case V_291 :
F_280 ( V_280 ) ;
break;
case V_292 :
case V_293 :
break;
}
if ( V_223 )
V_223 = F_283 ( V_223 ) ;
else
V_223 = V_294 ;
return V_223 ;
}
static struct V_1 * T_7 F_284 ( struct V_1 * V_295 )
{
int V_10 ;
struct V_1 * V_2 = F_285 ( V_1 , V_249 ) ;
memcpy ( V_2 , V_295 , V_1 -> V_21 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_37 ) {
F_189 (p, &n->partial, lru)
V_5 -> V_141 = V_2 ;
#ifdef F_2
F_189 (p, &n->full, lru)
V_5 -> V_141 = V_2 ;
#endif
}
}
F_88 ( & V_2 -> V_296 , & V_297 ) ;
return V_2 ;
}
void T_7 F_286 ( void )
{
static V_298 struct V_1 V_299 ,
V_300 ;
int V_56 ;
int V_301 = 2 ;
if ( F_287 () )
V_244 = 0 ;
V_9 = & V_300 ;
V_1 = & V_299 ;
F_288 ( V_9 , L_73 ,
sizeof( struct V_9 ) , V_302 ) ;
F_289 ( F_282 , V_303 ) ;
V_250 = V_304 ;
F_288 ( V_1 , L_74 ,
F_290 ( struct V_1 , V_10 ) +
V_305 * sizeof( struct V_9 * ) ,
V_302 ) ;
V_1 = F_284 ( & V_299 ) ;
V_9 = F_284 ( & V_300 ) ;
F_231 ( V_306 > 256 ||
( V_306 & ( V_306 - 1 ) ) ) ;
for ( V_56 = 8 ; V_56 < V_306 ; V_56 += 8 ) {
int V_307 = F_260 ( V_56 ) ;
if ( V_307 >= F_291 ( V_269 ) )
break;
V_269 [ V_307 ] = V_308 ;
}
if ( V_306 == 64 ) {
for ( V_56 = 64 + 8 ; V_56 <= 96 ; V_56 += 8 )
V_269 [ F_260 ( V_56 ) ] = 7 ;
} else if ( V_306 == 128 ) {
for ( V_56 = 128 + 8 ; V_56 <= 192 ; V_56 += 8 )
V_269 [ F_260 ( V_56 ) ] = 8 ;
}
if ( V_306 <= 32 ) {
V_271 [ 1 ] = F_292 ( L_75 , 96 , 0 ) ;
V_301 ++ ;
}
if ( V_306 <= 64 ) {
V_271 [ 2 ] = F_292 ( L_76 , 192 , 0 ) ;
V_301 ++ ;
}
for ( V_56 = V_308 ; V_56 < V_248 ; V_56 ++ ) {
V_271 [ V_56 ] = F_292 ( L_77 , 1 << V_56 , 0 ) ;
V_301 ++ ;
}
V_250 = V_309 ;
if ( V_306 <= 32 ) {
V_271 [ 1 ] -> V_45 = F_293 ( V_271 [ 1 ] -> V_45 , V_249 ) ;
F_119 ( ! V_271 [ 1 ] -> V_45 ) ;
}
if ( V_306 <= 64 ) {
V_271 [ 2 ] -> V_45 = F_293 ( V_271 [ 2 ] -> V_45 , V_249 ) ;
F_119 ( ! V_271 [ 2 ] -> V_45 ) ;
}
for ( V_56 = V_308 ; V_56 < V_248 ; V_56 ++ ) {
char * V_2 = F_294 ( V_249 , L_78 , 1 << V_56 ) ;
F_119 ( ! V_2 ) ;
V_271 [ V_56 ] -> V_45 = V_2 ;
}
#ifdef F_295
F_296 ( & V_310 ) ;
#endif
#ifdef F_262
for ( V_56 = 0 ; V_56 < V_248 ; V_56 ++ ) {
struct V_1 * V_2 = V_271 [ V_56 ] ;
if ( V_2 && V_2 -> V_15 ) {
char * V_45 = F_294 ( V_249 ,
L_79 , V_2 -> V_21 ) ;
F_119 ( ! V_45 ) ;
V_270 [ V_56 ] = F_292 ( V_45 ,
V_2 -> V_21 , V_258 ) ;
}
}
#endif
F_38 ( V_44
L_80
L_81 ,
V_301 , F_297 () ,
V_238 , V_244 , V_242 ,
V_243 , V_305 ) ;
}
void T_7 F_298 ( void )
{
}
static int F_299 ( struct V_1 * V_2 )
{
if ( V_266 || ( V_2 -> V_3 & V_311 ) )
return 1 ;
if ( V_2 -> F_104 )
return 1 ;
if ( V_2 -> V_312 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_300 ( struct V_313 * V_314 , T_1 V_15 ,
T_1 V_256 , unsigned long V_3 , const char * V_45 ,
void (* F_104)( void * ) )
{
struct V_1 * V_2 ;
if ( V_266 || ( V_3 & V_311 ) )
return NULL ;
if ( F_104 )
return NULL ;
V_15 = F_239 ( V_15 , sizeof( void * ) ) ;
V_256 = F_301 ( V_3 , V_256 , V_15 ) ;
V_15 = F_239 ( V_15 , V_256 ) ;
V_3 = F_103 ( V_15 , V_3 , V_45 , NULL ) ;
F_189 (s, &slab_caches, list) {
if ( F_299 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_315 ) != ( V_2 -> V_3 & V_315 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_256 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
if ( ! F_302 ( V_2 , V_314 ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_303 ( struct V_313 * V_314 , const char * V_45 , T_1 V_15 ,
T_1 V_256 , unsigned long V_3 , void (* F_104)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_300 ( V_314 , V_15 , V_256 , V_3 , V_45 , F_104 ) ;
if ( V_2 ) {
V_2 -> V_312 ++ ;
V_2 -> V_21 = F_223 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_304 ( int , V_2 -> V_24 , F_239 ( V_15 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_45 ) ) {
V_2 -> V_312 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_305 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_316 ;
V_316 = F_240 ( V_2 , V_3 ) ;
if ( V_316 )
return V_316 ;
if ( V_250 <= V_309 )
return 0 ;
F_7 ( V_2 ) ;
F_253 ( & V_265 ) ;
V_316 = F_4 ( V_2 ) ;
F_254 ( & V_265 ) ;
if ( V_316 )
F_250 ( V_2 ) ;
return V_316 ;
}
static int T_9 F_306 ( struct V_285 * V_317 ,
unsigned long V_287 , void * V_318 )
{
long V_64 = ( long ) V_318 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_287 ) {
case V_319 :
case V_320 :
case V_321 :
case V_322 :
F_254 ( & V_265 ) ;
F_189 (s, &slab_caches, list) {
F_40 ( V_3 ) ;
F_178 ( V_2 , V_64 ) ;
F_41 ( V_3 ) ;
}
F_253 ( & V_265 ) ;
break;
default:
break;
}
return V_294 ;
}
void * F_307 ( T_1 V_15 , T_5 V_207 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_272 ) )
return F_264 ( V_15 , V_207 ) ;
V_2 = F_261 ( V_15 , V_207 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_206 ( V_2 , V_207 , V_323 ) ;
F_210 ( V_323 , V_223 , V_15 , V_2 -> V_15 , V_207 ) ;
return V_223 ;
}
void * F_308 ( T_1 V_15 , T_5 V_207 ,
int V_10 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_223 ;
if ( F_3 ( V_15 > V_272 ) ) {
V_223 = F_266 ( V_15 , V_207 , V_10 ) ;
F_216 ( V_323 , V_223 ,
V_15 , V_27 << F_193 ( V_15 ) ,
V_207 , V_10 ) ;
return V_223 ;
}
V_2 = F_261 ( V_15 , V_207 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_223 = F_202 ( V_2 , V_207 , V_10 , V_323 ) ;
F_216 ( V_323 , V_223 , V_15 , V_2 -> V_15 , V_207 , V_10 ) ;
return V_223 ;
}
static int F_309 ( struct V_11 * V_11 )
{
return V_11 -> V_24 ;
}
static int F_310 ( struct V_11 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_311 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_18 = F_13 ( V_11 ) ;
if ( ! F_72 ( V_2 , V_11 ) ||
! F_74 ( V_2 , V_11 , NULL ) )
return 0 ;
F_312 ( V_46 , V_11 -> V_14 ) ;
F_42 ( V_2 , V_11 , V_46 ) ;
F_124 (p, s, addr, page->objects) {
if ( F_247 ( F_21 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_71 ( V_2 , V_11 , V_5 , V_110 ) )
return 0 ;
}
F_124 (p, s, addr, page->objects)
if ( ! F_247 ( F_21 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_71 ( V_2 , V_11 , V_5 , V_94 ) )
return 0 ;
return 1 ;
}
static void F_313 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long * V_46 )
{
F_27 ( V_11 ) ;
F_311 ( V_2 , V_11 , V_46 ) ;
F_29 ( V_11 ) ;
}
static int F_314 ( struct V_1 * V_2 ,
struct V_9 * V_37 , unsigned long * V_46 )
{
unsigned long V_324 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_188 ( & V_37 -> V_160 , V_3 ) ;
F_189 (page, &n->partial, lru) {
F_313 ( V_2 , V_11 , V_46 ) ;
V_324 ++ ;
}
if ( V_324 != V_37 -> V_152 )
F_38 ( V_49 L_82
L_83 , V_2 -> V_45 , V_324 , V_37 -> V_152 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_115;
F_189 (page, &n->full, lru) {
F_313 ( V_2 , V_11 , V_46 ) ;
V_324 ++ ;
}
if ( V_324 != F_92 ( & V_37 -> V_108 ) )
F_38 ( V_49 L_84
L_83 , V_2 -> V_45 , V_324 ,
F_92 ( & V_37 -> V_108 ) ) ;
V_115:
F_190 ( & V_37 -> V_160 , V_3 ) ;
return V_324 ;
}
static long F_315 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_324 = 0 ;
unsigned long * V_46 = F_276 ( F_246 ( F_26 ( V_2 -> F_223 ) ) *
sizeof( unsigned long ) , V_252 ) ;
if ( ! V_46 )
return - V_278 ;
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
V_324 += F_314 ( V_2 , V_37 , V_46 ) ;
}
F_248 ( V_46 ) ;
return V_324 ;
}
static void F_316 ( struct V_325 * V_71 )
{
if ( V_71 -> F_223 )
F_317 ( ( unsigned long ) V_71 -> V_326 ,
F_193 ( sizeof( struct V_327 ) * V_71 -> F_223 ) ) ;
}
static int F_318 ( struct V_325 * V_71 , unsigned long F_223 , T_5 V_3 )
{
struct V_327 * V_184 ;
int V_25 ;
V_25 = F_193 ( sizeof( struct V_327 ) * F_223 ) ;
V_184 = ( void * ) F_319 ( V_3 , V_25 ) ;
if ( ! V_184 )
return 0 ;
if ( V_71 -> V_324 ) {
memcpy ( V_184 , V_71 -> V_326 , sizeof( struct V_327 ) * V_71 -> V_324 ) ;
F_316 ( V_71 ) ;
}
V_71 -> F_223 = F_223 ;
V_71 -> V_326 = V_184 ;
return 1 ;
}
static int F_320 ( struct V_325 * V_71 , struct V_1 * V_2 ,
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
F_321 ( V_51 -> V_64 ,
F_322 ( V_184 -> V_336 ) ) ;
}
F_323 ( F_120 ( F_324 ( V_51 ) ) , V_184 -> V_337 ) ;
return 1 ;
}
if ( V_51 -> V_18 < V_329 )
V_90 = V_328 ;
else
V_86 = V_328 ;
}
if ( V_71 -> V_324 >= V_71 -> F_223 && ! F_318 ( V_71 , 2 * V_71 -> F_223 , V_206 ) )
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
F_325 ( F_322 ( V_184 -> V_336 ) ) ;
F_321 ( V_51 -> V_64 , F_322 ( V_184 -> V_336 ) ) ;
F_326 ( V_184 -> V_337 ) ;
F_323 ( F_120 ( F_324 ( V_51 ) ) , V_184 -> V_337 ) ;
return 1 ;
}
static void F_327 ( struct V_325 * V_71 , struct V_1 * V_2 ,
struct V_11 * V_11 , enum V_52 V_53 ,
unsigned long * V_46 )
{
void * V_18 = F_13 ( V_11 ) ;
void * V_5 ;
F_312 ( V_46 , V_11 -> V_14 ) ;
F_42 ( V_2 , V_11 , V_46 ) ;
F_124 (p, s, addr, page->objects)
if ( ! F_247 ( F_21 ( V_5 , V_2 , V_18 ) , V_46 ) )
F_320 ( V_71 , V_2 , F_46 ( V_2 , V_5 , V_53 ) ) ;
}
static int F_328 ( struct V_1 * V_2 , char * V_73 ,
enum V_52 V_53 )
{
int V_338 = 0 ;
unsigned long V_56 ;
struct V_325 V_71 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_46 = F_276 ( F_246 ( F_26 ( V_2 -> F_223 ) ) *
sizeof( unsigned long ) , V_252 ) ;
if ( ! V_46 || ! F_318 ( & V_71 , V_27 / sizeof( struct V_327 ) ,
V_339 ) ) {
F_248 ( V_46 ) ;
return sprintf ( V_73 , L_85 ) ;
}
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_92 ( & V_37 -> V_108 ) )
continue;
F_188 ( & V_37 -> V_160 , V_3 ) ;
F_189 (page, &n->partial, lru)
F_327 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_189 (page, &n->full, lru)
F_327 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_190 ( & V_37 -> V_160 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_324 ; V_56 ++ ) {
struct V_327 * V_184 = & V_71 . V_326 [ V_56 ] ;
if ( V_338 > V_27 - V_340 - 100 )
break;
V_338 += sprintf ( V_73 + V_338 , L_86 , V_184 -> V_324 ) ;
if ( V_184 -> V_18 )
V_338 += sprintf ( V_73 + V_338 , L_87 , ( void * ) V_184 -> V_18 ) ;
else
V_338 += sprintf ( V_73 + V_338 , L_88 ) ;
if ( V_184 -> V_331 != V_184 -> V_332 ) {
V_338 += sprintf ( V_73 + V_338 , L_89 ,
V_184 -> V_332 ,
( long ) F_329 ( V_184 -> V_331 , V_184 -> V_324 ) ,
V_184 -> V_333 ) ;
} else
V_338 += sprintf ( V_73 + V_338 , L_90 ,
V_184 -> V_332 ) ;
if ( V_184 -> V_334 != V_184 -> V_335 )
V_338 += sprintf ( V_73 + V_338 , L_91 ,
V_184 -> V_334 , V_184 -> V_335 ) ;
else
V_338 += sprintf ( V_73 + V_338 , L_92 ,
V_184 -> V_334 ) ;
if ( F_330 () > 1 &&
! F_331 ( F_322 ( V_184 -> V_336 ) ) &&
V_338 < V_27 - 60 ) {
V_338 += sprintf ( V_73 + V_338 , L_93 ) ;
V_338 += F_332 ( V_73 + V_338 , V_27 - V_338 - 50 ,
F_322 ( V_184 -> V_336 ) ) ;
}
if ( V_341 > 1 && ! F_333 ( V_184 -> V_337 ) &&
V_338 < V_27 - 60 ) {
V_338 += sprintf ( V_73 + V_338 , L_94 ) ;
V_338 += F_334 ( V_73 + V_338 , V_27 - V_338 - 50 ,
V_184 -> V_337 ) ;
}
V_338 += sprintf ( V_73 + V_338 , L_95 ) ;
}
F_316 ( & V_71 ) ;
F_248 ( V_46 ) ;
if ( ! V_71 . V_324 )
V_338 += sprintf ( V_73 , L_96 ) ;
return V_338 ;
}
static void F_335 ( void )
{
T_3 * V_5 ;
F_231 ( V_306 > 16 || V_248 < 10 ) ;
F_38 ( V_49 L_97 ) ;
F_38 ( V_49 L_98 ) ;
F_38 ( V_49 L_99 ) ;
V_5 = F_245 ( 16 , V_252 ) ;
V_5 [ 16 ] = 0x12 ;
F_38 ( V_49 L_100
L_101 , V_5 + 16 ) ;
F_315 ( V_271 [ 4 ] ) ;
V_5 = F_245 ( 32 , V_252 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_38 ( V_49 L_102
L_103 , V_5 ) ;
F_38 ( V_49
L_104 ) ;
F_315 ( V_271 [ 5 ] ) ;
V_5 = F_245 ( 64 , V_252 ) ;
V_5 += 64 + ( F_152 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_38 ( V_49 L_105 ,
V_5 ) ;
F_38 ( V_49
L_104 ) ;
F_315 ( V_271 [ 6 ] ) ;
F_38 ( V_49 L_106 ) ;
V_5 = F_245 ( 128 , V_252 ) ;
F_248 ( V_5 ) ;
* V_5 = 0x78 ;
F_38 ( V_49 L_107 , V_5 ) ;
F_315 ( V_271 [ 7 ] ) ;
V_5 = F_245 ( 256 , V_252 ) ;
F_248 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_38 ( V_49 L_108 ,
V_5 ) ;
F_315 ( V_271 [ 8 ] ) ;
V_5 = F_245 ( 512 , V_252 ) ;
F_248 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_38 ( V_49 L_109 , V_5 ) ;
F_315 ( V_271 [ 9 ] ) ;
}
static void F_335 ( void ) {}
static T_10 F_336 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_342 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_337 ;
unsigned long * V_343 ;
V_337 = F_245 ( 2 * sizeof( unsigned long ) * V_305 , V_252 ) ;
if ( ! V_337 )
return - V_278 ;
V_343 = V_337 + V_305 ;
if ( V_3 & V_344 ) {
int V_64 ;
F_170 (cpu) {
struct V_157 * V_158 = F_171 ( V_2 -> V_8 , V_64 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_337 ( V_158 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_120 ( V_11 ) ;
if ( V_3 & V_345 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_346 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
V_11 = F_337 ( V_158 -> V_154 ) ;
if ( V_11 ) {
V_29 = V_11 -> V_201 ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
}
V_343 [ V_10 ] ++ ;
}
}
F_338 () ;
#ifdef F_2
if ( V_3 & V_347 ) {
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( V_3 & V_345 )
V_29 = F_92 ( & V_37 -> V_109 ) ;
else if ( V_3 & V_346 )
V_29 = F_92 ( & V_37 -> V_109 ) -
F_186 ( V_37 , F_185 ) ;
else
V_29 = F_92 ( & V_37 -> V_108 ) ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_348 ) {
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( V_3 & V_345 )
V_29 = F_186 ( V_37 , F_310 ) ;
else if ( V_3 & V_346 )
V_29 = F_186 ( V_37 , F_309 ) ;
else
V_29 = V_37 -> V_152 ;
V_342 += V_29 ;
V_337 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_73 , L_110 , V_342 ) ;
#ifdef F_150
F_235 (node, N_NORMAL_MEMORY)
if ( V_337 [ V_10 ] )
V_29 += sprintf ( V_73 + V_29 , L_111 ,
V_10 , V_337 [ V_10 ] ) ;
#endif
F_339 () ;
F_248 ( V_337 ) ;
return V_29 + sprintf ( V_73 + V_29 , L_95 ) ;
}
static int F_340 ( struct V_1 * V_2 )
{
int V_10 ;
F_194 (node) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
if ( F_92 ( & V_37 -> V_109 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_341 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_15 ) ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_256 ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_21 ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , F_26 ( V_2 -> V_121 ) ) ;
}
static T_10 F_345 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_25 ;
int V_316 ;
V_316 = F_346 ( V_73 , 10 , & V_25 ) ;
if ( V_316 )
return V_316 ;
if ( V_25 > V_244 || V_25 < V_238 )
return - V_263 ;
F_238 ( V_2 , V_25 ) ;
return V_48 ;
}
static T_10 F_347 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , F_25 ( V_2 -> V_121 ) ) ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_113 , V_2 -> V_173 ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_129 ;
int V_316 ;
V_316 = F_346 ( V_73 , 10 , & V_129 ) ;
if ( V_316 )
return V_316 ;
F_237 ( V_2 , V_129 ) ;
return V_48 ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_114 , V_2 -> V_164 ) ;
}
static T_10 F_351 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_14 ;
int V_316 ;
V_316 = F_346 ( V_73 , 10 , & V_14 ) ;
if ( V_316 )
return V_316 ;
if ( V_14 && F_1 ( V_2 ) )
return - V_263 ;
V_2 -> V_164 = V_14 ;
F_182 ( V_2 ) ;
return V_48 ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! V_2 -> F_104 )
return 0 ;
return sprintf ( V_73 , L_115 , V_2 -> F_104 ) ;
}
static T_10 F_353 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_312 - 1 ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_348 ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_344 ) ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_347 | V_346 ) ;
}
static T_10 F_357 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_348 | V_346 ) ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_73 )
{
int V_14 = 0 ;
int V_133 = 0 ;
int V_64 ;
int V_338 ;
F_359 (cpu) {
struct V_11 * V_11 = F_171 ( V_2 -> V_8 , V_64 ) -> V_154 ;
if ( V_11 ) {
V_133 += V_11 -> V_133 ;
V_14 += V_11 -> V_201 ;
}
}
V_338 = sprintf ( V_73 , L_116 , V_14 , V_133 ) ;
#ifdef F_295
F_359 (cpu) {
struct V_11 * V_11 = F_171 ( V_2 -> V_8 , V_64 ) -> V_154 ;
if ( V_11 && V_338 < V_27 - 20 )
V_338 += sprintf ( V_73 + V_338 , L_117 , V_64 ,
V_11 -> V_201 , V_11 -> V_133 ) ;
}
#endif
return V_338 + sprintf ( V_73 + V_338 , L_95 ) ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_134 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_134 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_134 ;
return V_48 ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_302 ) ) ;
}
static T_10 F_363 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_258 ) ) ;
}
static T_10 F_364 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_365 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_26 ) ;
}
static T_10 F_366 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_347 ) ;
}
static T_10 F_367 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_347 | V_345 ) ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_118 ) ) ;
}
static T_10 F_369 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_118 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_118 ;
}
return V_48 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_100 ) ) ;
}
static T_10 F_371 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_100 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_100 ;
}
return V_48 ;
}
static T_10 F_372 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_19 ) ) ;
}
static T_10 F_373 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_340 ( V_2 ) )
return - V_349 ;
V_2 -> V_3 &= ~ V_19 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_19 ;
}
F_238 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_374 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_10 F_375 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_340 ( V_2 ) )
return - V_349 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_20 ;
}
F_238 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_376 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_377 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_340 ( V_2 ) )
return - V_349 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_23 ;
}
F_238 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_378 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_379 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
int V_223 = - V_263 ;
if ( V_73 [ 0 ] == '1' ) {
V_223 = F_315 ( V_2 ) ;
if ( V_223 >= 0 )
V_223 = V_48 ;
}
return V_223 ;
}
static T_10 F_380 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_246 ;
return F_328 ( V_2 , V_73 , V_70 ) ;
}
static T_10 F_381 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_246 ;
return F_328 ( V_2 , V_73 , V_69 ) ;
}
static T_10 F_382 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_10 F_383 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_119 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_119 ;
return V_48 ;
}
static T_10 F_384 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_385 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( V_73 [ 0 ] == '1' ) {
int V_264 = F_275 ( V_2 ) ;
if ( V_264 )
return V_264 ;
} else
return - V_263 ;
return V_48 ;
}
static T_10 F_386 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_172 / 10 ) ;
}
static T_10 F_387 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_350 ;
int V_316 ;
V_316 = F_346 ( V_73 , 10 , & V_350 ) ;
if ( V_316 )
return V_316 ;
if ( V_350 <= 100 )
V_2 -> V_172 = V_350 * 10 ;
return V_48 ;
}
static int F_388 ( struct V_1 * V_2 , char * V_73 , enum V_6 V_7 )
{
unsigned long V_351 = 0 ;
int V_64 ;
int V_338 ;
int * V_82 = F_276 ( V_243 * sizeof( int ) , V_252 ) ;
if ( ! V_82 )
return - V_278 ;
F_359 (cpu) {
unsigned V_29 = F_171 ( V_2 -> V_8 , V_64 ) -> F_8 [ V_7 ] ;
V_82 [ V_64 ] = V_29 ;
V_351 += V_29 ;
}
V_338 = sprintf ( V_73 , L_110 , V_351 ) ;
#ifdef F_295
F_359 (cpu) {
if ( V_82 [ V_64 ] && V_338 < V_27 - 20 )
V_338 += sprintf ( V_73 + V_338 , L_118 , V_64 , V_82 [ V_64 ] ) ;
}
#endif
F_248 ( V_82 ) ;
return V_338 + sprintf ( V_73 + V_338 , L_95 ) ;
}
static void F_389 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_64 ;
F_359 (cpu)
F_171 ( V_2 -> V_8 , V_64 ) -> F_8 [ V_7 ] = 0 ;
}
static T_10 F_390 ( struct V_352 * V_353 ,
struct V_354 * V_355 ,
char * V_73 )
{
struct V_356 * V_354 ;
struct V_1 * V_2 ;
int V_316 ;
V_354 = F_391 ( V_355 ) ;
V_2 = F_392 ( V_353 ) ;
if ( ! V_354 -> V_357 )
return - V_358 ;
V_316 = V_354 -> V_357 ( V_2 , V_73 ) ;
return V_316 ;
}
static T_10 F_393 ( struct V_352 * V_353 ,
struct V_354 * V_355 ,
const char * V_73 , T_1 V_338 )
{
struct V_356 * V_354 ;
struct V_1 * V_2 ;
int V_316 ;
V_354 = F_391 ( V_355 ) ;
V_2 = F_392 ( V_353 ) ;
if ( ! V_354 -> V_359 )
return - V_358 ;
V_316 = V_354 -> V_359 ( V_2 , V_73 , V_338 ) ;
#ifdef F_394
if ( V_250 >= V_360 && V_316 >= 0 && F_395 ( V_2 ) ) {
int V_56 ;
F_254 ( & V_265 ) ;
if ( V_2 -> V_361 < V_338 )
V_2 -> V_361 = V_338 ;
F_396 (i) {
struct V_1 * V_158 = F_397 ( V_2 , V_56 ) ;
if ( V_158 )
V_354 -> V_359 ( V_158 , V_73 , V_338 ) ;
}
F_253 ( & V_265 ) ;
}
#endif
return V_316 ;
}
static void F_7 ( struct V_1 * V_2 )
{
#ifdef F_394
int V_56 ;
char * V_362 = NULL ;
if ( ! F_395 ( V_2 ) )
return;
if ( ! V_2 -> V_361 )
return;
for ( V_56 = 0 ; V_56 < F_291 ( V_363 ) ; V_56 ++ ) {
char V_364 [ 64 ] ;
char * V_73 ;
struct V_356 * V_355 = F_391 ( V_363 [ V_56 ] ) ;
if ( ! V_355 || ! V_355 -> V_359 || ! V_355 -> V_357 )
continue;
if ( V_362 )
V_73 = V_362 ;
else if ( V_2 -> V_361 < F_291 ( V_364 ) )
V_73 = V_364 ;
else {
V_362 = ( char * ) F_398 ( V_252 ) ;
if ( F_142 ( ! V_362 ) )
continue;
V_73 = V_362 ;
}
V_355 -> V_357 ( V_2 -> V_365 -> V_366 , V_73 ) ;
V_355 -> V_359 ( V_2 , V_73 , strlen ( V_73 ) ) ;
}
if ( V_362 )
F_399 ( ( unsigned long ) V_362 ) ;
#endif
}
static int F_400 ( struct V_367 * V_367 , struct V_352 * V_353 )
{
struct V_368 * V_369 = F_401 ( V_353 ) ;
if ( V_369 == & V_370 )
return 1 ;
return 0 ;
}
static char * F_402 ( struct V_1 * V_2 )
{
char * V_45 = F_276 ( V_371 , V_252 ) ;
char * V_5 = V_45 ;
F_119 ( ! V_45 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_258 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_134 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_118 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_132 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_45 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_119 , V_2 -> V_15 ) ;
#ifdef F_394
if ( ! F_395 ( V_2 ) )
V_5 += sprintf ( V_5 , L_120 , F_403 ( V_2 -> V_365 -> V_314 ) ) ;
#endif
F_119 ( V_5 > V_45 + V_371 - 1 ) ;
return V_45 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_316 ;
const char * V_45 ;
int V_372 = F_299 ( V_2 ) ;
if ( V_372 ) {
F_404 ( & V_373 -> V_353 , V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
} else {
V_45 = F_402 ( V_2 ) ;
}
V_2 -> V_353 . V_367 = V_373 ;
V_316 = F_405 ( & V_2 -> V_353 , & V_370 , NULL , V_45 ) ;
if ( V_316 ) {
F_406 ( & V_2 -> V_353 ) ;
return V_316 ;
}
V_316 = F_407 ( & V_2 -> V_353 , & V_374 ) ;
if ( V_316 ) {
F_408 ( & V_2 -> V_353 ) ;
F_406 ( & V_2 -> V_353 ) ;
return V_316 ;
}
F_409 ( & V_2 -> V_353 , V_375 ) ;
if ( ! V_372 ) {
F_5 ( V_2 , V_2 -> V_45 ) ;
F_248 ( V_45 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_250 < V_360 )
return;
F_409 ( & V_2 -> V_353 , V_376 ) ;
F_408 ( & V_2 -> V_353 ) ;
F_406 ( & V_2 -> V_353 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_45 )
{
struct V_377 * V_378 ;
if ( V_250 == V_360 ) {
F_404 ( & V_373 -> V_353 , V_45 ) ;
return F_410 ( & V_373 -> V_353 , & V_2 -> V_353 , V_45 ) ;
}
V_378 = F_276 ( sizeof( struct V_377 ) , V_252 ) ;
if ( ! V_378 )
return - V_278 ;
V_378 -> V_2 = V_2 ;
V_378 -> V_45 = V_45 ;
V_378 -> V_197 = V_379 ;
V_379 = V_378 ;
return 0 ;
}
static int T_7 F_411 ( void )
{
struct V_1 * V_2 ;
int V_316 ;
F_254 ( & V_265 ) ;
V_373 = F_412 ( L_121 , & V_380 , V_381 ) ;
if ( ! V_373 ) {
F_253 ( & V_265 ) ;
F_38 ( V_49 L_122 ) ;
return - V_246 ;
}
V_250 = V_360 ;
F_189 (s, &slab_caches, list) {
V_316 = F_4 ( V_2 ) ;
if ( V_316 )
F_38 ( V_49 L_123
L_124 , V_2 -> V_45 ) ;
}
while ( V_379 ) {
struct V_377 * V_378 = V_379 ;
V_379 = V_379 -> V_197 ;
V_316 = F_5 ( V_378 -> V_2 , V_378 -> V_45 ) ;
if ( V_316 )
F_38 ( V_49 L_125
L_126 , V_378 -> V_45 ) ;
F_248 ( V_378 ) ;
}
F_253 ( & V_265 ) ;
F_335 () ;
return 0 ;
}
void F_413 ( struct V_1 * V_2 , struct V_382 * V_383 )
{
unsigned long V_384 = 0 ;
unsigned long V_108 = 0 ;
unsigned long V_210 = 0 ;
unsigned long V_211 = 0 ;
int V_10 ;
F_194 (node) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
V_384 += V_37 -> V_152 ;
V_108 += F_92 ( & V_37 -> V_108 ) ;
V_210 += F_92 ( & V_37 -> V_109 ) ;
V_211 += F_186 ( V_37 , F_185 ) ;
}
V_383 -> V_385 = V_210 - V_211 ;
V_383 -> V_386 = V_210 ;
V_383 -> V_387 = V_108 ;
V_383 -> V_388 = V_108 ;
V_383 -> V_389 = F_26 ( V_2 -> V_121 ) ;
V_383 -> V_390 = F_25 ( V_2 -> V_121 ) ;
}
void F_414 ( struct V_391 * V_185 , struct V_1 * V_2 )
{
}
T_10 F_415 ( struct V_392 * V_392 , const char T_11 * V_362 ,
T_1 V_324 , T_12 * V_393 )
{
return - V_358 ;
}
