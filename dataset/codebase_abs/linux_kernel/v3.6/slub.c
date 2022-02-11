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
static inline struct V_10 * F_11 ( struct V_1 * V_2 , int V_11 )
{
return V_2 -> V_11 [ V_11 ] ;
}
static inline int F_12 ( struct V_1 * V_2 ,
struct V_12 * V_12 , const void * V_13 )
{
void * V_14 ;
if ( ! V_13 )
return 1 ;
V_14 = F_13 ( V_12 ) ;
if ( V_13 < V_14 || V_13 >= V_14 + V_12 -> V_15 * V_2 -> V_16 ||
( V_13 - V_14 ) % V_2 -> V_16 ) {
return 0 ;
}
return 1 ;
}
static inline void * F_14 ( struct V_1 * V_2 , void * V_13 )
{
return * ( void * * ) ( V_13 + V_2 -> V_17 ) ;
}
static void F_15 ( const struct V_1 * V_2 , void * V_13 )
{
F_16 ( V_13 + V_2 -> V_17 ) ;
}
static inline void * F_17 ( struct V_1 * V_2 , void * V_13 )
{
void * V_5 ;
#ifdef F_18
F_19 ( & V_5 , ( void * * ) ( V_13 + V_2 -> V_17 ) , sizeof( V_5 ) ) ;
#else
V_5 = F_14 ( V_2 , V_13 ) ;
#endif
return V_5 ;
}
static inline void F_20 ( struct V_1 * V_2 , void * V_13 , void * V_18 )
{
* ( void * * ) ( V_13 + V_2 -> V_17 ) = V_18 ;
}
static inline int F_21 ( void * V_5 , struct V_1 * V_2 , void * V_19 )
{
return ( V_5 - V_19 ) / V_2 -> V_16 ;
}
static inline T_1 F_22 ( const struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 & ( V_20 | V_21 ) )
return V_2 -> V_22 ;
#endif
if ( V_2 -> V_3 & ( V_23 | V_24 ) )
return V_2 -> V_25 ;
return V_2 -> V_16 ;
}
static inline int F_23 ( int V_26 , unsigned long V_16 , int V_27 )
{
return ( ( V_28 << V_26 ) - V_27 ) / V_16 ;
}
static inline struct V_29 F_24 ( int V_26 ,
unsigned long V_16 , int V_27 )
{
struct V_29 V_30 = {
( V_26 << V_31 ) + F_23 (order, size, reserved)
} ;
return V_30 ;
}
static inline int F_25 ( struct V_29 V_30 )
{
return V_30 . V_30 >> V_31 ;
}
static inline int F_26 ( struct V_29 V_30 )
{
return V_30 . V_30 & V_32 ;
}
static T_2 void F_27 ( struct V_12 * V_12 )
{
F_28 ( V_33 , & V_12 -> V_3 ) ;
}
static T_2 void F_29 ( struct V_12 * V_12 )
{
F_30 ( V_33 , & V_12 -> V_3 ) ;
}
static inline bool F_31 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_34 , unsigned long V_35 ,
void * V_36 , unsigned long V_37 ,
const char * V_38 )
{
F_32 ( ! F_33 () ) ;
#if F_34 ( V_39 ) && \
F_34 ( V_40 )
if ( V_2 -> V_3 & V_41 ) {
if ( F_35 ( & V_12 -> V_42 , & V_12 -> V_43 ,
V_34 , V_35 ,
V_36 , V_37 ) )
return 1 ;
} else
#endif
{
F_27 ( V_12 ) ;
if ( V_12 -> V_42 == V_34 && V_12 -> V_43 == V_35 ) {
V_12 -> V_42 = V_36 ;
V_12 -> V_43 = V_37 ;
F_29 ( V_12 ) ;
return 1 ;
}
F_29 ( V_12 ) ;
}
F_36 () ;
F_8 ( V_2 , V_44 ) ;
#ifdef F_37
F_38 ( V_45 L_1 , V_38 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static inline bool F_39 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_34 , unsigned long V_35 ,
void * V_36 , unsigned long V_37 ,
const char * V_38 )
{
#if F_34 ( V_39 ) && \
F_34 ( V_40 )
if ( V_2 -> V_3 & V_41 ) {
if ( F_35 ( & V_12 -> V_42 , & V_12 -> V_43 ,
V_34 , V_35 ,
V_36 , V_37 ) )
return 1 ;
} else
#endif
{
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_27 ( V_12 ) ;
if ( V_12 -> V_42 == V_34 && V_12 -> V_43 == V_35 ) {
V_12 -> V_42 = V_36 ;
V_12 -> V_43 = V_37 ;
F_29 ( V_12 ) ;
F_41 ( V_3 ) ;
return 1 ;
}
F_29 ( V_12 ) ;
F_41 ( V_3 ) ;
}
F_36 () ;
F_8 ( V_2 , V_44 ) ;
#ifdef F_37
F_38 ( V_45 L_1 , V_38 , V_2 -> V_6 ) ;
#endif
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_12 * V_12 , unsigned long * V_46 )
{
void * V_5 ;
void * V_19 = F_13 ( V_12 ) ;
for ( V_5 = V_12 -> V_42 ; V_5 ; V_5 = F_14 ( V_2 , V_5 ) )
F_43 ( F_21 ( V_5 , V_2 , V_19 ) , V_46 ) ;
}
static void F_44 ( char * V_47 , T_3 * V_19 , unsigned int V_48 )
{
F_45 ( V_49 , V_47 , V_50 , 16 , 1 , V_19 ,
V_48 , 1 ) ;
}
static struct V_51 * F_46 ( struct V_1 * V_2 , void * V_13 ,
enum V_52 V_53 )
{
struct V_51 * V_5 ;
if ( V_2 -> V_17 )
V_5 = V_13 + V_2 -> V_17 + sizeof( void * ) ;
else
V_5 = V_13 + V_2 -> V_25 ;
return V_5 + V_53 ;
}
static void F_47 ( struct V_1 * V_2 , void * V_13 ,
enum V_52 V_53 , unsigned long V_19 )
{
struct V_51 * V_5 = F_46 ( V_2 , V_13 , V_53 ) ;
if ( V_19 ) {
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
V_5 -> V_19 = V_19 ;
V_5 -> V_64 = F_50 () ;
V_5 -> V_65 = V_66 -> V_65 ;
V_5 -> V_67 = V_68 ;
} else
memset ( V_5 , 0 , sizeof( struct V_51 ) ) ;
}
static void F_51 ( struct V_1 * V_2 , void * V_13 )
{
if ( ! ( V_2 -> V_3 & V_24 ) )
return;
F_47 ( V_2 , V_13 , V_69 , 0UL ) ;
F_47 ( V_2 , V_13 , V_70 , 0UL ) ;
}
static void F_52 ( const char * V_2 , struct V_51 * V_71 )
{
if ( ! V_71 -> V_19 )
return;
F_38 ( V_49 L_2 ,
V_2 , ( void * ) V_71 -> V_19 , V_68 - V_71 -> V_67 , V_71 -> V_64 , V_71 -> V_65 ) ;
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
static void F_53 ( struct V_1 * V_2 , void * V_13 )
{
if ( ! ( V_2 -> V_3 & V_24 ) )
return;
F_52 ( L_4 , F_46 ( V_2 , V_13 , V_70 ) ) ;
F_52 ( L_5 , F_46 ( V_2 , V_13 , V_69 ) ) ;
}
static void F_54 ( struct V_12 * V_12 )
{
F_38 ( V_49 L_6 ,
V_12 , V_12 -> V_15 , V_12 -> V_25 , V_12 -> V_42 , V_12 -> V_3 ) ;
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
F_38 ( V_49 L_9 , V_2 -> V_6 , F_56 () , V_73 ) ;
F_38 ( V_49 L_10
L_11 ) ;
}
static void F_57 ( struct V_1 * V_2 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_38 ( V_49 L_12 , V_2 -> V_6 , V_73 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_12 * V_12 , T_3 * V_5 )
{
unsigned int V_74 ;
T_3 * V_19 = F_13 ( V_12 ) ;
F_53 ( V_2 , V_5 ) ;
F_54 ( V_12 ) ;
F_38 ( V_49 L_13 ,
V_5 , V_5 - V_19 , F_14 ( V_2 , V_5 ) ) ;
if ( V_5 > V_19 + 16 )
F_44 ( L_14 , V_5 - 16 , 16 ) ;
F_44 ( L_15 , V_5 , F_59 (unsigned long, s->object_size,
PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_20 )
F_44 ( L_16 , V_5 + V_2 -> V_22 ,
V_2 -> V_25 - V_2 -> V_22 ) ;
if ( V_2 -> V_17 )
V_74 = V_2 -> V_17 + sizeof( void * ) ;
else
V_74 = V_2 -> V_25 ;
if ( V_2 -> V_3 & V_24 )
V_74 += 2 * sizeof( struct V_51 ) ;
if ( V_74 != V_2 -> V_16 )
F_44 ( L_17 , V_5 + V_74 , V_2 -> V_16 - V_74 ) ;
F_60 () ;
}
static void F_61 ( struct V_1 * V_2 , struct V_12 * V_12 ,
T_3 * V_13 , char * V_75 )
{
F_55 ( V_2 , L_18 , V_75 ) ;
F_58 ( V_2 , V_12 , V_13 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_12 * V_12 , char * V_72 , ... )
{
T_4 args ;
char V_73 [ 100 ] ;
va_start ( args , V_72 ) ;
vsnprintf ( V_73 , sizeof( V_73 ) , V_72 , args ) ;
va_end ( args ) ;
F_55 ( V_2 , L_18 , V_73 ) ;
F_54 ( V_12 ) ;
F_60 () ;
}
static void F_63 ( struct V_1 * V_2 , void * V_13 , T_3 V_76 )
{
T_3 * V_5 = V_13 ;
if ( V_2 -> V_3 & V_77 ) {
memset ( V_5 , V_78 , V_2 -> V_22 - 1 ) ;
V_5 [ V_2 -> V_22 - 1 ] = V_79 ;
}
if ( V_2 -> V_3 & V_20 )
memset ( V_5 + V_2 -> V_22 , V_76 , V_2 -> V_25 - V_2 -> V_22 ) ;
}
static void F_64 ( struct V_1 * V_2 , char * V_80 , T_3 V_81 ,
void * V_82 , void * V_83 )
{
F_57 ( V_2 , L_19 , V_82 , V_83 - 1 , V_81 ) ;
memset ( V_82 , V_81 , V_83 - V_82 ) ;
}
static int F_65 ( struct V_1 * V_2 , struct V_12 * V_12 ,
T_3 * V_13 , char * V_84 ,
T_3 * V_85 , unsigned int V_86 , unsigned int V_87 )
{
T_3 * V_88 ;
T_3 * V_89 ;
V_88 = F_66 ( V_85 , V_86 , V_87 ) ;
if ( ! V_88 )
return 1 ;
V_89 = V_85 + V_87 ;
while ( V_89 > V_88 && V_89 [ - 1 ] == V_86 )
V_89 -- ;
F_55 ( V_2 , L_20 , V_84 ) ;
F_38 ( V_49 L_21 ,
V_88 , V_89 - 1 , V_88 [ 0 ] , V_86 ) ;
F_58 ( V_2 , V_12 , V_13 ) ;
F_64 ( V_2 , V_84 , V_86 , V_88 , V_89 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_12 * V_12 , T_3 * V_5 )
{
unsigned long V_74 = V_2 -> V_25 ;
if ( V_2 -> V_17 )
V_74 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_24 )
V_74 += 2 * sizeof( struct V_51 ) ;
if ( V_2 -> V_16 == V_74 )
return 1 ;
return F_65 ( V_2 , V_12 , V_5 , L_22 ,
V_5 + V_74 , V_90 , V_2 -> V_16 - V_74 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
T_3 * V_85 ;
T_3 * V_88 ;
T_3 * V_89 ;
int V_48 ;
int V_91 ;
if ( ! ( V_2 -> V_3 & V_21 ) )
return 1 ;
V_85 = F_13 ( V_12 ) ;
V_48 = ( V_28 << F_69 ( V_12 ) ) - V_2 -> V_27 ;
V_89 = V_85 + V_48 ;
V_91 = V_48 % V_2 -> V_16 ;
if ( ! V_91 )
return 1 ;
V_88 = F_66 ( V_89 - V_91 , V_90 , V_91 ) ;
if ( ! V_88 )
return 1 ;
while ( V_89 > V_88 && V_89 [ - 1 ] == V_90 )
V_89 -- ;
F_62 ( V_2 , V_12 , L_23 , V_88 , V_89 - 1 ) ;
F_44 ( L_17 , V_89 - V_91 , V_91 ) ;
F_64 ( V_2 , L_24 , V_90 , V_89 - V_91 , V_89 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_13 , T_3 V_76 )
{
T_3 * V_5 = V_13 ;
T_3 * V_92 = V_13 + V_2 -> V_22 ;
if ( V_2 -> V_3 & V_20 ) {
if ( ! F_65 ( V_2 , V_12 , V_13 , L_25 ,
V_92 , V_76 , V_2 -> V_25 - V_2 -> V_22 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_21 ) && V_2 -> V_22 < V_2 -> V_25 ) {
F_65 ( V_2 , V_12 , V_5 , L_26 ,
V_92 , V_90 , V_2 -> V_25 - V_2 -> V_22 ) ;
}
}
if ( V_2 -> V_3 & V_21 ) {
if ( V_76 != V_93 && ( V_2 -> V_3 & V_77 ) &&
( ! F_65 ( V_2 , V_12 , V_5 , L_27 , V_5 ,
V_78 , V_2 -> V_22 - 1 ) ||
! F_65 ( V_2 , V_12 , V_5 , L_27 ,
V_5 + V_2 -> V_22 - 1 , V_79 , 1 ) ) )
return 0 ;
F_67 ( V_2 , V_12 , V_5 ) ;
}
if ( ! V_2 -> V_17 && V_76 == V_93 )
return 1 ;
if ( ! F_12 ( V_2 , V_12 , F_14 ( V_2 , V_5 ) ) ) {
F_61 ( V_2 , V_12 , V_5 , L_28 ) ;
F_20 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
int V_94 ;
F_32 ( ! F_33 () ) ;
if ( ! F_72 ( V_12 ) ) {
F_62 ( V_2 , V_12 , L_29 ) ;
return 0 ;
}
V_94 = F_23 ( F_69 ( V_12 ) , V_2 -> V_16 , V_2 -> V_27 ) ;
if ( V_12 -> V_15 > V_94 ) {
F_62 ( V_2 , V_12 , L_30 ,
V_2 -> V_6 , V_12 -> V_15 , V_94 ) ;
return 0 ;
}
if ( V_12 -> V_25 > V_12 -> V_15 ) {
F_62 ( V_2 , V_12 , L_31 ,
V_2 -> V_6 , V_12 -> V_25 , V_12 -> V_15 ) ;
return 0 ;
}
F_68 ( V_2 , V_12 ) ;
return 1 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_12 * V_12 , void * V_95 )
{
int V_96 = 0 ;
void * V_18 ;
void * V_13 = NULL ;
unsigned long V_97 ;
V_18 = V_12 -> V_42 ;
while ( V_18 && V_96 <= V_12 -> V_15 ) {
if ( V_18 == V_95 )
return 1 ;
if ( ! F_12 ( V_2 , V_12 , V_18 ) ) {
if ( V_13 ) {
F_61 ( V_2 , V_12 , V_13 ,
L_32 ) ;
F_20 ( V_2 , V_13 , NULL ) ;
break;
} else {
F_62 ( V_2 , V_12 , L_28 ) ;
V_12 -> V_42 = NULL ;
V_12 -> V_25 = V_12 -> V_15 ;
F_57 ( V_2 , L_33 ) ;
return 0 ;
}
break;
}
V_13 = V_18 ;
V_18 = F_14 ( V_2 , V_13 ) ;
V_96 ++ ;
}
V_97 = F_23 ( F_69 ( V_12 ) , V_2 -> V_16 , V_2 -> V_27 ) ;
if ( V_97 > V_98 )
V_97 = V_98 ;
if ( V_12 -> V_15 != V_97 ) {
F_62 ( V_2 , V_12 , L_34
L_35 , V_12 -> V_15 , V_97 ) ;
V_12 -> V_15 = V_97 ;
F_57 ( V_2 , L_36 ) ;
}
if ( V_12 -> V_25 != V_12 -> V_15 - V_96 ) {
F_62 ( V_2 , V_12 , L_37
L_38 , V_12 -> V_25 , V_12 -> V_15 - V_96 ) ;
V_12 -> V_25 = V_12 -> V_15 - V_96 ;
F_57 ( V_2 , L_39 ) ;
}
return V_95 == NULL ;
}
static void V_55 ( struct V_1 * V_2 , struct V_12 * V_12 , void * V_13 ,
int V_53 )
{
if ( V_2 -> V_3 & V_99 ) {
F_38 ( V_45 L_40 ,
V_2 -> V_6 ,
V_53 ? L_41 : L_42 ,
V_13 , V_12 -> V_25 ,
V_12 -> V_42 ) ;
if ( ! V_53 )
F_44 ( L_15 , ( void * ) V_13 , V_2 -> V_22 ) ;
F_60 () ;
}
}
static inline int F_74 ( struct V_1 * V_2 , T_5 V_3 )
{
V_3 &= V_100 ;
F_75 ( V_3 ) ;
F_76 ( V_3 & V_101 ) ;
return F_77 ( V_2 -> V_22 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_78 ( struct V_1 * V_2 , T_5 V_3 , void * V_13 )
{
V_3 &= V_100 ;
F_79 ( V_2 , V_3 , V_13 , F_22 ( V_2 ) ) ;
F_80 ( V_13 , V_2 -> V_22 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_81 ( struct V_1 * V_2 , void * V_30 )
{
F_82 ( V_30 , V_2 -> V_3 ) ;
#if F_34 ( V_102 ) || F_34 ( V_103 )
{
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_83 ( V_2 , V_30 , V_2 -> V_22 ) ;
F_84 ( V_30 , V_2 -> V_22 ) ;
F_41 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_104 ) )
F_85 ( V_30 , V_2 -> V_22 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_10 * V_38 , struct V_12 * V_12 )
{
if ( ! ( V_2 -> V_3 & V_24 ) )
return;
F_87 ( & V_12 -> V_105 , & V_38 -> V_106 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
if ( ! ( V_2 -> V_3 & V_24 ) )
return;
F_89 ( & V_12 -> V_105 ) ;
}
static inline unsigned long F_90 ( struct V_1 * V_2 , int V_11 )
{
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
return F_91 ( & V_38 -> V_107 ) ;
}
static inline unsigned long F_92 ( struct V_10 * V_38 )
{
return F_91 ( & V_38 -> V_107 ) ;
}
static inline void F_93 ( struct V_1 * V_2 , int V_11 , int V_15 )
{
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
if ( V_38 ) {
F_94 ( & V_38 -> V_107 ) ;
F_95 ( V_15 , & V_38 -> V_108 ) ;
}
}
static inline void F_96 ( struct V_1 * V_2 , int V_11 , int V_15 )
{
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
F_97 ( & V_38 -> V_107 ) ;
F_98 ( V_15 , & V_38 -> V_108 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_13 )
{
if ( ! ( V_2 -> V_3 & ( V_24 | V_20 | V_77 ) ) )
return;
F_63 ( V_2 , V_13 , V_109 ) ;
F_51 ( V_2 , V_13 ) ;
}
static T_6 int F_100 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_13 , unsigned long V_19 )
{
if ( ! F_71 ( V_2 , V_12 ) )
goto V_110;
if ( ! F_12 ( V_2 , V_12 , V_13 ) ) {
F_61 ( V_2 , V_12 , V_13 , L_43 ) ;
goto V_110;
}
if ( ! F_70 ( V_2 , V_12 , V_13 , V_109 ) )
goto V_110;
if ( V_2 -> V_3 & V_24 )
F_47 ( V_2 , V_13 , V_70 , V_19 ) ;
V_55 ( V_2 , V_12 , V_13 , 1 ) ;
F_63 ( V_2 , V_13 , V_93 ) ;
return 1 ;
V_110:
if ( F_72 ( V_12 ) ) {
F_57 ( V_2 , L_44 ) ;
V_12 -> V_25 = V_12 -> V_15 ;
V_12 -> V_42 = NULL ;
}
return 0 ;
}
static T_6 int F_101 ( struct V_1 * V_2 ,
struct V_12 * V_12 , void * V_13 , unsigned long V_19 )
{
unsigned long V_3 ;
int V_111 = 0 ;
F_40 ( V_3 ) ;
F_27 ( V_12 ) ;
if ( ! F_71 ( V_2 , V_12 ) )
goto V_112;
if ( ! F_12 ( V_2 , V_12 , V_13 ) ) {
F_62 ( V_2 , V_12 , L_45 , V_13 ) ;
goto V_112;
}
if ( F_73 ( V_2 , V_12 , V_13 ) ) {
F_61 ( V_2 , V_12 , V_13 , L_46 ) ;
goto V_112;
}
if ( ! F_70 ( V_2 , V_12 , V_13 , V_93 ) )
goto V_113;
if ( F_3 ( V_2 != V_12 -> V_114 ) ) {
if ( ! F_72 ( V_12 ) ) {
F_62 ( V_2 , V_12 , L_47
L_48 , V_13 ) ;
} else if ( ! V_12 -> V_114 ) {
F_38 ( V_49
L_49 ,
V_13 ) ;
F_60 () ;
} else
F_61 ( V_2 , V_12 , V_13 ,
L_50 ) ;
goto V_112;
}
if ( V_2 -> V_3 & V_24 )
F_47 ( V_2 , V_13 , V_69 , V_19 ) ;
V_55 ( V_2 , V_12 , V_13 , 0 ) ;
F_63 ( V_2 , V_13 , V_109 ) ;
V_111 = 1 ;
V_113:
F_29 ( V_12 ) ;
F_41 ( V_3 ) ;
return V_111 ;
V_112:
F_57 ( V_2 , L_51 , V_13 ) ;
goto V_113;
}
static int T_7 F_102 ( char * V_115 )
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
V_116 |= V_20 ;
break;
case 'p' :
V_116 |= V_21 ;
break;
case 'u' :
V_116 |= V_24 ;
break;
case 't' :
V_116 |= V_99 ;
break;
case 'a' :
V_116 |= V_121 ;
break;
default:
F_38 ( V_49 L_52
L_53 , * V_115 ) ;
}
}
V_118:
if ( * V_115 == ',' )
V_122 = V_115 + 1 ;
V_113:
return 1 ;
}
static unsigned long F_103 ( unsigned long V_22 ,
unsigned long V_3 , const char * V_6 ,
void (* F_104)( void * ) )
{
if ( V_116 && ( ! V_122 ||
! strncmp ( V_122 , V_6 , strlen ( V_122 ) ) ) )
V_3 |= V_116 ;
return V_3 ;
}
static inline void F_99 ( struct V_1 * V_2 ,
struct V_12 * V_12 , void * V_13 ) {}
static inline int F_100 ( struct V_1 * V_2 ,
struct V_12 * V_12 , void * V_13 , unsigned long V_19 ) { return 0 ; }
static inline int F_101 ( struct V_1 * V_2 ,
struct V_12 * V_12 , void * V_13 , unsigned long V_19 ) { return 0 ; }
static inline int F_68 ( struct V_1 * V_2 , struct V_12 * V_12 )
{ return 1 ; }
static inline int F_70 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_13 , T_3 V_76 ) { return 1 ; }
static inline void F_86 ( struct V_1 * V_2 , struct V_10 * V_38 ,
struct V_12 * V_12 ) {}
static inline void F_88 ( struct V_1 * V_2 , struct V_12 * V_12 ) {}
static inline unsigned long F_103 ( unsigned long V_22 ,
unsigned long V_3 , const char * V_6 ,
void (* F_104)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_90 ( struct V_1 * V_2 , int V_11 )
{ return 0 ; }
static inline unsigned long F_92 ( struct V_10 * V_38 )
{ return 0 ; }
static inline void F_93 ( struct V_1 * V_2 , int V_11 ,
int V_15 ) {}
static inline void F_96 ( struct V_1 * V_2 , int V_11 ,
int V_15 ) {}
static inline int F_74 ( struct V_1 * V_2 , T_5 V_3 )
{ return 0 ; }
static inline void F_78 ( struct V_1 * V_2 , T_5 V_3 ,
void * V_13 ) {}
static inline void F_81 ( struct V_1 * V_2 , void * V_30 ) {}
static inline struct V_12 * F_105 ( T_5 V_3 , int V_11 ,
struct V_29 V_123 )
{
int V_26 = F_25 ( V_123 ) ;
V_3 |= V_124 ;
if ( V_11 == V_125 )
return F_106 ( V_3 , V_26 ) ;
else
return F_107 ( V_11 , V_3 , V_26 ) ;
}
static struct V_12 * F_108 ( struct V_1 * V_2 , T_5 V_3 , int V_11 )
{
struct V_12 * V_12 ;
struct V_29 V_123 = V_2 -> V_123 ;
T_5 V_126 ;
V_3 &= V_100 ;
if ( V_3 & V_101 )
F_109 () ;
V_3 |= V_2 -> V_127 ;
V_126 = ( V_3 | V_128 | V_129 ) & ~ V_130 ;
V_12 = F_105 ( V_126 , V_11 , V_123 ) ;
if ( F_3 ( ! V_12 ) ) {
V_123 = V_2 -> V_131 ;
V_12 = F_105 ( V_3 , V_11 , V_123 ) ;
if ( V_12 )
F_8 ( V_2 , V_132 ) ;
}
if ( V_133 && V_12
&& ! ( V_2 -> V_3 & ( V_134 | V_117 ) ) ) {
int V_135 = 1 << F_25 ( V_123 ) ;
F_110 ( V_12 , F_25 ( V_123 ) , V_3 , V_11 ) ;
if ( V_2 -> F_104 )
F_111 ( V_12 , V_135 ) ;
else
F_112 ( V_12 , V_135 ) ;
}
if ( V_3 & V_101 )
F_113 () ;
if ( ! V_12 )
return NULL ;
V_12 -> V_15 = F_26 ( V_123 ) ;
F_114 ( F_115 ( V_12 ) ,
( V_2 -> V_3 & V_136 ) ?
V_137 : V_138 ,
1 << F_25 ( V_123 ) ) ;
return V_12 ;
}
static void F_116 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_13 )
{
F_99 ( V_2 , V_12 , V_13 ) ;
if ( F_3 ( V_2 -> F_104 ) )
V_2 -> F_104 ( V_13 ) ;
}
static struct V_12 * F_117 ( struct V_1 * V_2 , T_5 V_3 , int V_11 )
{
struct V_12 * V_12 ;
void * V_85 ;
void * V_139 ;
void * V_5 ;
F_118 ( V_3 & V_140 ) ;
V_12 = F_108 ( V_2 ,
V_3 & ( V_141 | V_142 ) , V_11 ) ;
if ( ! V_12 )
goto V_113;
F_93 ( V_2 , F_119 ( V_12 ) , V_12 -> V_15 ) ;
V_12 -> V_114 = V_2 ;
F_120 ( V_12 ) ;
if ( V_12 -> V_143 )
F_121 ( V_12 ) ;
V_85 = F_13 ( V_12 ) ;
if ( F_3 ( V_2 -> V_3 & V_21 ) )
memset ( V_85 , V_90 , V_28 << F_69 ( V_12 ) ) ;
V_139 = V_85 ;
F_122 (p, s, start, page->objects) {
F_116 ( V_2 , V_12 , V_139 ) ;
F_20 ( V_2 , V_139 , V_5 ) ;
V_139 = V_5 ;
}
F_116 ( V_2 , V_12 , V_139 ) ;
F_20 ( V_2 , V_139 , NULL ) ;
V_12 -> V_42 = V_85 ;
V_12 -> V_25 = V_12 -> V_15 ;
V_12 -> V_144 = 1 ;
V_113:
return V_12 ;
}
static void F_123 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
int V_26 = F_69 ( V_12 ) ;
int V_135 = 1 << V_26 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_68 ( V_2 , V_12 ) ;
F_122 (p, s, page_address(page),
page->objects)
F_70 ( V_2 , V_12 , V_5 , V_109 ) ;
}
F_124 ( V_12 , F_69 ( V_12 ) ) ;
F_114 ( F_115 ( V_12 ) ,
( V_2 -> V_3 & V_136 ) ?
V_137 : V_138 ,
- V_135 ) ;
F_125 ( V_12 ) ;
F_126 ( V_12 ) ;
F_127 ( V_12 ) ;
if ( V_66 -> V_145 )
V_66 -> V_145 -> V_146 += V_135 ;
F_128 ( V_12 , V_26 ) ;
}
static void F_129 ( struct V_147 * V_148 )
{
struct V_12 * V_12 ;
if ( V_149 )
V_12 = F_130 ( V_148 ) ;
else
V_12 = F_131 ( (struct V_150 * ) V_148 , struct V_12 , V_105 ) ;
F_123 ( V_12 -> V_114 , V_12 ) ;
}
static void F_132 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
if ( F_3 ( V_2 -> V_3 & V_23 ) ) {
struct V_147 * V_151 ;
if ( V_149 ) {
int V_26 = F_69 ( V_12 ) ;
int V_17 = ( V_28 << V_26 ) - V_2 -> V_27 ;
F_32 ( V_2 -> V_27 != sizeof( * V_151 ) ) ;
V_151 = F_13 ( V_12 ) + V_17 ;
} else {
V_151 = ( void * ) & V_12 -> V_105 ;
}
F_133 ( V_151 , F_129 ) ;
} else
F_123 ( V_2 , V_12 ) ;
}
static void F_134 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
F_96 ( V_2 , F_119 ( V_12 ) , V_12 -> V_15 ) ;
F_132 ( V_2 , V_12 ) ;
}
static inline void F_135 ( struct V_10 * V_38 ,
struct V_12 * V_12 , int V_152 )
{
V_38 -> V_153 ++ ;
if ( V_152 == V_154 )
F_136 ( & V_12 -> V_105 , & V_38 -> V_155 ) ;
else
F_87 ( & V_12 -> V_105 , & V_38 -> V_155 ) ;
}
static inline void F_137 ( struct V_10 * V_38 ,
struct V_12 * V_12 )
{
F_89 ( & V_12 -> V_105 ) ;
V_38 -> V_153 -- ;
}
static inline void * F_138 ( struct V_1 * V_2 ,
struct V_10 * V_38 , struct V_12 * V_12 ,
int V_156 )
{
void * V_42 ;
unsigned long V_43 ;
struct V_12 V_157 ;
V_42 = V_12 -> V_42 ;
V_43 = V_12 -> V_43 ;
V_157 . V_43 = V_43 ;
if ( V_156 ) {
V_157 . V_25 = V_12 -> V_15 ;
V_157 . V_42 = NULL ;
} else {
V_157 . V_42 = V_42 ;
}
F_32 ( V_157 . V_144 ) ;
V_157 . V_144 = 1 ;
if ( ! F_31 ( V_2 , V_12 ,
V_42 , V_43 ,
V_157 . V_42 , V_157 . V_43 ,
L_54 ) )
return NULL ;
F_137 ( V_38 , V_12 ) ;
F_139 ( ! V_42 ) ;
return V_42 ;
}
static void * F_140 ( struct V_1 * V_2 , struct V_10 * V_38 ,
struct V_158 * V_159 , T_5 V_3 )
{
struct V_12 * V_12 , * V_160 ;
void * V_13 = NULL ;
if ( ! V_38 || ! V_38 -> V_153 )
return NULL ;
F_141 ( & V_38 -> V_161 ) ;
F_142 (page, page2, &n->partial, lru) {
void * V_71 ;
int V_162 ;
if ( ! F_143 ( V_12 , V_3 ) )
continue;
V_71 = F_138 ( V_2 , V_38 , V_12 , V_13 == NULL ) ;
if ( ! V_71 )
break;
if ( ! V_13 ) {
V_159 -> V_12 = V_12 ;
F_8 ( V_2 , V_163 ) ;
V_13 = V_71 ;
V_162 = V_12 -> V_15 - V_12 -> V_25 ;
} else {
V_162 = F_144 ( V_2 , V_12 , 0 ) ;
F_8 ( V_2 , V_164 ) ;
}
if ( F_1 ( V_2 ) || V_162 > V_2 -> V_165 / 2 )
break;
}
F_145 ( & V_38 -> V_161 ) ;
return V_13 ;
}
static void * F_146 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_158 * V_159 )
{
#ifdef F_147
struct V_166 * V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_169 ;
enum V_170 V_171 = F_148 ( V_3 ) ;
void * V_13 ;
unsigned int V_172 ;
if ( ! V_2 -> V_173 ||
F_149 () % 1024 > V_2 -> V_173 )
return NULL ;
do {
V_172 = F_150 () ;
V_166 = F_151 ( F_152 () , V_3 ) ;
F_153 (zone, z, zonelist, high_zoneidx) {
struct V_10 * V_38 ;
V_38 = F_11 ( V_2 , F_154 ( V_169 ) ) ;
if ( V_38 && F_155 ( V_169 , V_3 ) &&
V_38 -> V_153 > V_2 -> V_174 ) {
V_13 = F_140 ( V_2 , V_38 , V_159 , V_3 ) ;
if ( V_13 ) {
F_156 ( V_172 ) ;
return V_13 ;
}
}
}
} while ( ! F_156 ( V_172 ) );
#endif
return NULL ;
}
static void * F_157 ( struct V_1 * V_2 , T_5 V_3 , int V_11 ,
struct V_158 * V_159 )
{
void * V_13 ;
int V_175 = ( V_11 == V_125 ) ? F_158 () : V_11 ;
V_13 = F_140 ( V_2 , F_11 ( V_2 , V_175 ) , V_159 , V_3 ) ;
if ( V_13 || V_11 != V_125 )
return V_13 ;
return F_146 ( V_2 , V_3 , V_159 ) ;
}
static inline unsigned long F_159 ( unsigned long V_176 )
{
return V_176 + V_177 ;
}
static inline unsigned int F_160 ( unsigned long V_176 )
{
return V_176 % V_177 ;
}
static inline unsigned long F_161 ( unsigned long V_176 )
{
return V_176 / V_177 ;
}
static inline unsigned int F_162 ( int V_64 )
{
return V_64 ;
}
static inline void F_163 ( const char * V_38 ,
const struct V_1 * V_2 , unsigned long V_176 )
{
#ifdef F_37
unsigned long V_178 = F_164 ( V_2 -> V_9 -> V_176 ) ;
F_38 ( V_45 L_55 , V_38 , V_2 -> V_6 ) ;
#ifdef F_165
if ( F_160 ( V_176 ) != F_160 ( V_178 ) )
F_38 ( L_56 ,
F_160 ( V_176 ) , F_160 ( V_178 ) ) ;
else
#endif
if ( F_161 ( V_176 ) != F_161 ( V_178 ) )
F_38 ( L_57 ,
F_161 ( V_176 ) , F_161 ( V_178 ) ) ;
else
F_38 ( L_58 ,
V_178 , V_176 , F_159 ( V_176 ) ) ;
#endif
F_8 ( V_2 , V_179 ) ;
}
void F_166 ( struct V_1 * V_2 )
{
int V_64 ;
F_167 (cpu)
F_168 ( V_2 -> V_9 , V_64 ) -> V_176 = F_162 ( V_64 ) ;
}
static void F_169 ( struct V_1 * V_2 , struct V_12 * V_12 , void * V_42 )
{
enum T_8 { V_180 , V_181 , V_182 , V_183 };
struct V_10 * V_38 = F_11 ( V_2 , F_119 ( V_12 ) ) ;
int V_184 = 0 ;
enum T_8 V_185 = V_180 , V_186 = V_180 ;
void * V_187 ;
int V_152 = V_188 ;
struct V_12 V_157 ;
struct V_12 V_189 ;
if ( V_12 -> V_42 ) {
F_8 ( V_2 , V_190 ) ;
V_152 = V_154 ;
}
while ( V_42 && ( V_187 = F_14 ( V_2 , V_42 ) ) ) {
void * V_191 ;
unsigned long V_43 ;
do {
V_191 = V_12 -> V_42 ;
V_43 = V_12 -> V_43 ;
F_20 ( V_2 , V_42 , V_191 ) ;
V_157 . V_43 = V_43 ;
V_157 . V_25 -- ;
F_32 ( ! V_157 . V_144 ) ;
} while ( ! F_31 ( V_2 , V_12 ,
V_191 , V_43 ,
V_42 , V_157 . V_43 ,
L_59 ) );
V_42 = V_187 ;
}
V_192:
V_189 . V_42 = V_12 -> V_42 ;
V_189 . V_43 = V_12 -> V_43 ;
F_32 ( ! V_189 . V_144 ) ;
V_157 . V_43 = V_189 . V_43 ;
if ( V_42 ) {
V_157 . V_25 -- ;
F_20 ( V_2 , V_42 , V_189 . V_42 ) ;
V_157 . V_42 = V_42 ;
} else
V_157 . V_42 = V_189 . V_42 ;
V_157 . V_144 = 0 ;
if ( ! V_157 . V_25 && V_38 -> V_153 > V_2 -> V_174 )
V_186 = V_183 ;
else if ( V_157 . V_42 ) {
V_186 = V_181 ;
if ( ! V_184 ) {
V_184 = 1 ;
F_141 ( & V_38 -> V_161 ) ;
}
} else {
V_186 = V_182 ;
if ( F_1 ( V_2 ) && ! V_184 ) {
V_184 = 1 ;
F_141 ( & V_38 -> V_161 ) ;
}
}
if ( V_185 != V_186 ) {
if ( V_185 == V_181 )
F_137 ( V_38 , V_12 ) ;
else if ( V_185 == V_182 )
F_88 ( V_2 , V_12 ) ;
if ( V_186 == V_181 ) {
F_135 ( V_38 , V_12 , V_152 ) ;
F_8 ( V_2 , V_152 ) ;
} else if ( V_186 == V_182 ) {
F_8 ( V_2 , V_193 ) ;
F_86 ( V_2 , V_38 , V_12 ) ;
}
}
V_185 = V_186 ;
if ( ! F_31 ( V_2 , V_12 ,
V_189 . V_42 , V_189 . V_43 ,
V_157 . V_42 , V_157 . V_43 ,
L_60 ) )
goto V_192;
if ( V_184 )
F_145 ( & V_38 -> V_161 ) ;
if ( V_186 == V_183 ) {
F_8 ( V_2 , V_194 ) ;
F_134 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_195 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_10 * V_38 = NULL , * V_196 = NULL ;
struct V_158 * V_159 = F_171 ( V_2 -> V_9 ) ;
struct V_12 * V_12 , * V_197 = NULL ;
while ( ( V_12 = V_159 -> V_155 ) ) {
struct V_12 V_157 ;
struct V_12 V_189 ;
V_159 -> V_155 = V_12 -> V_198 ;
V_196 = F_11 ( V_2 , F_119 ( V_12 ) ) ;
if ( V_38 != V_196 ) {
if ( V_38 )
F_145 ( & V_38 -> V_161 ) ;
V_38 = V_196 ;
F_141 ( & V_38 -> V_161 ) ;
}
do {
V_189 . V_42 = V_12 -> V_42 ;
V_189 . V_43 = V_12 -> V_43 ;
F_32 ( ! V_189 . V_144 ) ;
V_157 . V_43 = V_189 . V_43 ;
V_157 . V_42 = V_189 . V_42 ;
V_157 . V_144 = 0 ;
} while ( ! F_31 ( V_2 , V_12 ,
V_189 . V_42 , V_189 . V_43 ,
V_157 . V_42 , V_157 . V_43 ,
L_60 ) );
if ( F_3 ( ! V_157 . V_25 && V_38 -> V_153 > V_2 -> V_174 ) ) {
V_12 -> V_198 = V_197 ;
V_197 = V_12 ;
} else {
F_135 ( V_38 , V_12 , V_154 ) ;
F_8 ( V_2 , V_199 ) ;
}
}
if ( V_38 )
F_145 ( & V_38 -> V_161 ) ;
while ( V_197 ) {
V_12 = V_197 ;
V_197 = V_197 -> V_198 ;
F_8 ( V_2 , V_194 ) ;
F_134 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_195 ) ;
}
}
int F_144 ( struct V_1 * V_2 , struct V_12 * V_12 , int V_200 )
{
struct V_12 * V_201 ;
int V_135 ;
int V_202 ;
do {
V_135 = 0 ;
V_202 = 0 ;
V_201 = F_172 ( V_2 -> V_9 -> V_155 ) ;
if ( V_201 ) {
V_202 = V_201 -> V_202 ;
V_135 = V_201 -> V_135 ;
if ( V_200 && V_202 > V_2 -> V_165 ) {
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_170 ( V_2 ) ;
F_41 ( V_3 ) ;
V_202 = 0 ;
V_135 = 0 ;
F_8 ( V_2 , V_203 ) ;
}
}
V_135 ++ ;
V_202 += V_12 -> V_15 - V_12 -> V_25 ;
V_12 -> V_135 = V_135 ;
V_12 -> V_202 = V_202 ;
V_12 -> V_198 = V_201 ;
} while ( F_173 ( V_2 -> V_9 -> V_155 , V_201 , V_12 ) != V_201 );
return V_202 ;
}
static inline void F_174 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
F_8 ( V_2 , V_204 ) ;
F_169 ( V_2 , V_159 -> V_12 , V_159 -> V_42 ) ;
V_159 -> V_176 = F_159 ( V_159 -> V_176 ) ;
V_159 -> V_12 = NULL ;
V_159 -> V_42 = NULL ;
}
static inline void F_175 ( struct V_1 * V_2 , int V_64 )
{
struct V_158 * V_159 = F_168 ( V_2 -> V_9 , V_64 ) ;
if ( F_176 ( V_159 ) ) {
if ( V_159 -> V_12 )
F_174 ( V_2 , V_159 ) ;
F_170 ( V_2 ) ;
}
}
static void F_177 ( void * V_205 )
{
struct V_1 * V_2 = V_205 ;
F_175 ( V_2 , F_50 () ) ;
}
static bool F_178 ( int V_64 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
struct V_158 * V_159 = F_168 ( V_2 -> V_9 , V_64 ) ;
return V_159 -> V_12 || V_159 -> V_155 ;
}
static void F_179 ( struct V_1 * V_2 )
{
F_180 ( F_178 , F_177 , V_2 , 1 , V_207 ) ;
}
static inline int F_181 ( struct V_12 * V_12 , int V_11 )
{
#ifdef F_147
if ( V_11 != V_125 && F_119 ( V_12 ) != V_11 )
return 0 ;
#endif
return 1 ;
}
static int F_182 ( struct V_12 * V_12 )
{
return V_12 -> V_15 - V_12 -> V_25 ;
}
static unsigned long F_183 ( struct V_10 * V_38 ,
int (* F_184)( struct V_12 * ) )
{
unsigned long V_3 ;
unsigned long V_30 = 0 ;
struct V_12 * V_12 ;
F_185 ( & V_38 -> V_161 , V_3 ) ;
F_186 (page, &n->partial, lru)
V_30 += F_184 ( V_12 ) ;
F_187 ( & V_38 -> V_161 , V_3 ) ;
return V_30 ;
}
static inline unsigned long F_188 ( struct V_10 * V_38 )
{
#ifdef F_2
return F_91 ( & V_38 -> V_108 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_189 ( struct V_1 * V_2 , T_5 V_208 , int V_209 )
{
int V_11 ;
F_38 ( V_210
L_61 ,
V_209 , V_208 ) ;
F_38 ( V_210 L_62
L_63 , V_2 -> V_6 , V_2 -> V_22 ,
V_2 -> V_16 , F_25 ( V_2 -> V_123 ) , F_25 ( V_2 -> V_131 ) ) ;
if ( F_25 ( V_2 -> V_131 ) > F_190 ( V_2 -> V_22 ) )
F_38 ( V_210 L_64
L_65 , V_2 -> V_6 ) ;
F_191 (node) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
unsigned long V_107 ;
unsigned long V_211 ;
unsigned long V_212 ;
if ( ! V_38 )
continue;
V_212 = F_183 ( V_38 , F_182 ) ;
V_107 = F_92 ( V_38 ) ;
V_211 = F_188 ( V_38 ) ;
F_38 ( V_210
L_66 ,
V_11 , V_107 , V_211 , V_212 ) ;
}
}
static inline void * F_192 ( struct V_1 * V_2 , T_5 V_3 ,
int V_11 , struct V_158 * * V_213 )
{
void * V_42 ;
struct V_158 * V_159 = * V_213 ;
struct V_12 * V_12 ;
V_42 = F_157 ( V_2 , V_3 , V_11 , V_159 ) ;
if ( V_42 )
return V_42 ;
V_12 = F_117 ( V_2 , V_3 , V_11 ) ;
if ( V_12 ) {
V_159 = F_193 ( V_2 -> V_9 ) ;
if ( V_159 -> V_12 )
F_174 ( V_2 , V_159 ) ;
V_42 = V_12 -> V_42 ;
V_12 -> V_42 = NULL ;
F_8 ( V_2 , V_214 ) ;
V_159 -> V_12 = V_12 ;
* V_213 = V_159 ;
} else
V_42 = NULL ;
return V_42 ;
}
static inline bool F_143 ( struct V_12 * V_12 , T_5 V_208 )
{
if ( F_3 ( F_194 ( V_12 ) ) )
return F_195 ( V_208 ) ;
return true ;
}
static inline void * F_196 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
struct V_12 V_157 ;
unsigned long V_43 ;
void * V_42 ;
do {
V_42 = V_12 -> V_42 ;
V_43 = V_12 -> V_43 ;
V_157 . V_43 = V_43 ;
F_32 ( ! V_157 . V_144 ) ;
V_157 . V_25 = V_12 -> V_15 ;
V_157 . V_144 = V_42 != NULL ;
} while ( ! F_31 ( V_2 , V_12 ,
V_42 , V_43 ,
NULL , V_157 . V_43 ,
L_67 ) );
return V_42 ;
}
static void * F_197 ( struct V_1 * V_2 , T_5 V_208 , int V_11 ,
unsigned long V_19 , struct V_158 * V_159 )
{
void * V_42 ;
struct V_12 * V_12 ;
unsigned long V_3 ;
F_40 ( V_3 ) ;
#ifdef F_165
V_159 = F_171 ( V_2 -> V_9 ) ;
#endif
V_12 = V_159 -> V_12 ;
if ( ! V_12 )
goto F_117;
V_192:
if ( F_3 ( ! F_181 ( V_12 , V_11 ) ) ) {
F_8 ( V_2 , V_215 ) ;
F_169 ( V_2 , V_12 , V_159 -> V_42 ) ;
V_159 -> V_12 = NULL ;
V_159 -> V_42 = NULL ;
goto F_117;
}
if ( F_3 ( ! F_143 ( V_12 , V_208 ) ) ) {
F_169 ( V_2 , V_12 , V_159 -> V_42 ) ;
V_159 -> V_12 = NULL ;
V_159 -> V_42 = NULL ;
goto F_117;
}
V_42 = V_159 -> V_42 ;
if ( V_42 )
goto V_216;
F_8 ( V_2 , V_217 ) ;
V_42 = F_196 ( V_2 , V_12 ) ;
if ( ! V_42 ) {
V_159 -> V_12 = NULL ;
F_8 ( V_2 , V_218 ) ;
goto F_117;
}
F_8 ( V_2 , V_219 ) ;
V_216:
F_32 ( ! V_159 -> V_12 -> V_144 ) ;
V_159 -> V_42 = F_14 ( V_2 , V_42 ) ;
V_159 -> V_176 = F_159 ( V_159 -> V_176 ) ;
F_41 ( V_3 ) ;
return V_42 ;
F_117:
if ( V_159 -> V_155 ) {
V_12 = V_159 -> V_12 = V_159 -> V_155 ;
V_159 -> V_155 = V_12 -> V_198 ;
F_8 ( V_2 , V_220 ) ;
V_159 -> V_42 = NULL ;
goto V_192;
}
V_42 = F_192 ( V_2 , V_208 , V_11 , & V_159 ) ;
if ( F_3 ( ! V_42 ) ) {
if ( ! ( V_208 & V_128 ) && F_198 () )
F_189 ( V_2 , V_208 , V_11 ) ;
F_41 ( V_3 ) ;
return NULL ;
}
V_12 = V_159 -> V_12 ;
if ( F_176 ( ! F_1 ( V_2 ) && F_143 ( V_12 , V_208 ) ) )
goto V_216;
if ( F_1 ( V_2 ) && ! F_100 ( V_2 , V_12 , V_42 , V_19 ) )
goto F_117;
F_169 ( V_2 , V_12 , F_14 ( V_2 , V_42 ) ) ;
V_159 -> V_12 = NULL ;
V_159 -> V_42 = NULL ;
F_41 ( V_3 ) ;
return V_42 ;
}
static T_2 void * F_199 ( struct V_1 * V_2 ,
T_5 V_208 , int V_11 , unsigned long V_19 )
{
void * * V_13 ;
struct V_158 * V_159 ;
struct V_12 * V_12 ;
unsigned long V_176 ;
if ( F_74 ( V_2 , V_208 ) )
return NULL ;
V_192:
V_159 = F_193 ( V_2 -> V_9 ) ;
V_176 = V_159 -> V_176 ;
F_200 () ;
V_13 = V_159 -> V_42 ;
V_12 = V_159 -> V_12 ;
if ( F_3 ( ! V_13 || ! F_181 ( V_12 , V_11 ) ) )
V_13 = F_197 ( V_2 , V_208 , V_11 , V_19 , V_159 ) ;
else {
void * V_221 = F_17 ( V_2 , V_13 ) ;
if ( F_3 ( ! F_201 (
V_2 -> V_9 -> V_42 , V_2 -> V_9 -> V_176 ,
V_13 , V_176 ,
V_221 , F_159 ( V_176 ) ) ) ) {
F_163 ( L_68 , V_2 , V_176 ) ;
goto V_192;
}
F_15 ( V_2 , V_221 ) ;
F_8 ( V_2 , V_222 ) ;
}
if ( F_3 ( V_208 & V_223 ) && V_13 )
memset ( V_13 , 0 , V_2 -> V_22 ) ;
F_78 ( V_2 , V_208 , V_13 ) ;
return V_13 ;
}
void * F_202 ( struct V_1 * V_2 , T_5 V_208 )
{
void * V_224 = F_199 ( V_2 , V_208 , V_125 , V_225 ) ;
F_203 ( V_225 , V_224 , V_2 -> V_22 , V_2 -> V_16 , V_208 ) ;
return V_224 ;
}
void * F_204 ( struct V_1 * V_2 , T_5 V_208 , T_1 V_16 )
{
void * V_224 = F_199 ( V_2 , V_208 , V_125 , V_225 ) ;
F_205 ( V_225 , V_224 , V_16 , V_2 -> V_16 , V_208 ) ;
return V_224 ;
}
void * F_206 ( T_1 V_16 , T_5 V_3 , unsigned int V_26 )
{
void * V_224 = F_207 ( V_16 , V_3 , V_26 ) ;
F_205 ( V_225 , V_224 , V_16 , V_28 << V_26 , V_3 ) ;
return V_224 ;
}
void * F_208 ( struct V_1 * V_2 , T_5 V_208 , int V_11 )
{
void * V_224 = F_199 ( V_2 , V_208 , V_11 , V_225 ) ;
F_209 ( V_225 , V_224 ,
V_2 -> V_22 , V_2 -> V_16 , V_208 , V_11 ) ;
return V_224 ;
}
void * F_210 ( struct V_1 * V_2 ,
T_5 V_208 ,
int V_11 , T_1 V_16 )
{
void * V_224 = F_199 ( V_2 , V_208 , V_11 , V_225 ) ;
F_211 ( V_225 , V_224 ,
V_16 , V_2 -> V_16 , V_208 , V_11 ) ;
return V_224 ;
}
static void F_212 ( struct V_1 * V_2 , struct V_12 * V_12 ,
void * V_30 , unsigned long V_19 )
{
void * V_191 ;
void * * V_13 = ( void * ) V_30 ;
int V_226 ;
int V_25 ;
struct V_12 V_157 ;
unsigned long V_43 ;
struct V_10 * V_38 = NULL ;
unsigned long V_227 ( V_3 ) ;
F_8 ( V_2 , V_228 ) ;
if ( F_1 ( V_2 ) && ! F_101 ( V_2 , V_12 , V_30 , V_19 ) )
return;
do {
V_191 = V_12 -> V_42 ;
V_43 = V_12 -> V_43 ;
F_20 ( V_2 , V_13 , V_191 ) ;
V_157 . V_43 = V_43 ;
V_226 = V_157 . V_144 ;
V_157 . V_25 -- ;
if ( ( ! V_157 . V_25 || ! V_191 ) && ! V_226 && ! V_38 ) {
if ( ! F_1 ( V_2 ) && ! V_191 )
V_157 . V_144 = 1 ;
else {
V_38 = F_11 ( V_2 , F_119 ( V_12 ) ) ;
F_185 ( & V_38 -> V_161 , V_3 ) ;
}
}
V_25 = V_157 . V_25 ;
} while ( ! F_39 ( V_2 , V_12 ,
V_191 , V_43 ,
V_13 , V_157 . V_43 ,
L_69 ) );
if ( F_176 ( ! V_38 ) ) {
if ( V_157 . V_144 && ! V_226 ) {
F_144 ( V_2 , V_12 , 1 ) ;
F_8 ( V_2 , V_229 ) ;
}
if ( V_226 )
F_8 ( V_2 , V_230 ) ;
return;
}
if ( V_226 )
F_8 ( V_2 , V_230 ) ;
else {
if ( F_3 ( ! V_25 && V_38 -> V_153 > V_2 -> V_174 ) )
goto V_231;
if ( F_3 ( ! V_191 ) ) {
F_88 ( V_2 , V_12 ) ;
F_135 ( V_38 , V_12 , V_154 ) ;
F_8 ( V_2 , V_199 ) ;
}
}
F_187 ( & V_38 -> V_161 , V_3 ) ;
return;
V_231:
if ( V_191 ) {
F_137 ( V_38 , V_12 ) ;
F_8 ( V_2 , V_232 ) ;
} else
F_88 ( V_2 , V_12 ) ;
F_187 ( & V_38 -> V_161 , V_3 ) ;
F_8 ( V_2 , V_195 ) ;
F_134 ( V_2 , V_12 ) ;
}
static T_2 void F_213 ( struct V_1 * V_2 ,
struct V_12 * V_12 , void * V_30 , unsigned long V_19 )
{
void * * V_13 = ( void * ) V_30 ;
struct V_158 * V_159 ;
unsigned long V_176 ;
F_81 ( V_2 , V_30 ) ;
V_192:
V_159 = F_193 ( V_2 -> V_9 ) ;
V_176 = V_159 -> V_176 ;
F_200 () ;
if ( F_176 ( V_12 == V_159 -> V_12 ) ) {
F_20 ( V_2 , V_13 , V_159 -> V_42 ) ;
if ( F_3 ( ! F_201 (
V_2 -> V_9 -> V_42 , V_2 -> V_9 -> V_176 ,
V_159 -> V_42 , V_176 ,
V_13 , F_159 ( V_176 ) ) ) ) {
F_163 ( L_70 , V_2 , V_176 ) ;
goto V_192;
}
F_8 ( V_2 , V_233 ) ;
} else
F_212 ( V_2 , V_12 , V_30 , V_19 ) ;
}
void F_214 ( struct V_1 * V_2 , void * V_30 )
{
struct V_12 * V_12 ;
V_12 = F_130 ( V_30 ) ;
F_213 ( V_2 , V_12 , V_30 , V_225 ) ;
F_215 ( V_225 , V_30 ) ;
}
static inline int F_216 ( int V_16 , int V_234 ,
int V_235 , int V_236 , int V_27 )
{
int V_26 ;
int V_237 ;
int V_238 = V_239 ;
if ( F_23 ( V_238 , V_16 , V_27 ) > V_98 )
return F_190 ( V_16 * V_98 ) - 1 ;
for ( V_26 = F_217 ( V_238 ,
F_218 ( V_234 * V_16 - 1 ) - V_240 ) ;
V_26 <= V_235 ; V_26 ++ ) {
unsigned long V_241 = V_28 << V_26 ;
if ( V_241 < V_234 * V_16 + V_27 )
continue;
V_237 = ( V_241 - V_27 ) % V_16 ;
if ( V_237 <= V_241 / V_236 )
break;
}
return V_26 ;
}
static inline int F_219 ( int V_16 , int V_27 )
{
int V_26 ;
int V_234 ;
int V_242 ;
int V_97 ;
V_234 = V_243 ;
if ( ! V_234 )
V_234 = 4 * ( F_218 ( V_244 ) + 1 ) ;
V_97 = F_23 ( V_245 , V_16 , V_27 ) ;
V_234 = V_131 ( V_234 , V_97 ) ;
while ( V_234 > 1 ) {
V_242 = 16 ;
while ( V_242 >= 4 ) {
V_26 = F_216 ( V_16 , V_234 ,
V_245 , V_242 , V_27 ) ;
if ( V_26 <= V_245 )
return V_26 ;
V_242 /= 2 ;
}
V_234 -- ;
}
V_26 = F_216 ( V_16 , 1 , V_245 , 1 , V_27 ) ;
if ( V_26 <= V_245 )
return V_26 ;
V_26 = F_216 ( V_16 , 1 , V_246 , 1 , V_27 ) ;
if ( V_26 < V_246 )
return V_26 ;
return - V_247 ;
}
static unsigned long F_220 ( unsigned long V_3 ,
unsigned long V_248 , unsigned long V_16 )
{
if ( V_3 & V_249 ) {
unsigned long V_250 = F_221 () ;
while ( V_16 <= V_250 / 2 )
V_250 /= 2 ;
V_248 = F_217 ( V_248 , V_250 ) ;
}
if ( V_248 < V_251 )
V_248 = V_251 ;
return F_222 ( V_248 , sizeof( void * ) ) ;
}
static void
F_223 ( struct V_10 * V_38 )
{
V_38 -> V_153 = 0 ;
F_224 ( & V_38 -> V_161 ) ;
F_225 ( & V_38 -> V_155 ) ;
#ifdef F_2
F_226 ( & V_38 -> V_107 , 0 ) ;
F_226 ( & V_38 -> V_108 , 0 ) ;
F_225 ( & V_38 -> V_106 ) ;
#endif
}
static inline int F_227 ( struct V_1 * V_2 )
{
F_228 ( V_252 <
V_253 * sizeof( struct V_158 ) ) ;
V_2 -> V_9 = F_229 ( sizeof( struct V_158 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_166 ( V_2 ) ;
return 1 ;
}
static void F_230 ( int V_11 )
{
struct V_12 * V_12 ;
struct V_10 * V_38 ;
F_118 ( V_10 -> V_16 < sizeof( struct V_10 ) ) ;
V_12 = F_117 ( V_10 , V_254 , V_11 ) ;
F_118 ( ! V_12 ) ;
if ( F_119 ( V_12 ) != V_11 ) {
F_38 ( V_49 L_71
L_72 , V_11 ) ;
F_38 ( V_49 L_73
L_74 ) ;
}
V_38 = V_12 -> V_42 ;
F_118 ( ! V_38 ) ;
V_12 -> V_42 = F_14 ( V_10 , V_38 ) ;
V_12 -> V_25 = 1 ;
V_12 -> V_144 = 0 ;
V_10 -> V_11 [ V_11 ] = V_38 ;
#ifdef F_2
F_63 ( V_10 , V_38 , V_93 ) ;
F_51 ( V_10 , V_38 ) ;
#endif
F_223 ( V_38 ) ;
F_93 ( V_10 , V_11 , V_12 -> V_15 ) ;
F_135 ( V_38 , V_12 , V_188 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
int V_11 ;
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = V_2 -> V_11 [ V_11 ] ;
if ( V_38 )
F_214 ( V_10 , V_38 ) ;
V_2 -> V_11 [ V_11 ] = NULL ;
}
}
static int F_233 ( struct V_1 * V_2 )
{
int V_11 ;
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 ;
if ( V_255 == V_256 ) {
F_230 ( V_11 ) ;
continue;
}
V_38 = F_208 ( V_10 ,
V_257 , V_11 ) ;
if ( ! V_38 ) {
F_231 ( V_2 ) ;
return 0 ;
}
V_2 -> V_11 [ V_11 ] = V_38 ;
F_223 ( V_38 ) ;
}
return 1 ;
}
static void F_234 ( struct V_1 * V_2 , unsigned long V_131 )
{
if ( V_131 < V_258 )
V_131 = V_258 ;
else if ( V_131 > V_259 )
V_131 = V_259 ;
V_2 -> V_174 = V_131 ;
}
static int F_235 ( struct V_1 * V_2 , int V_260 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_16 = V_2 -> V_22 ;
unsigned long V_248 = V_2 -> V_248 ;
int V_26 ;
V_16 = F_222 ( V_16 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_21 ) && ! ( V_3 & V_23 ) &&
! V_2 -> F_104 )
V_2 -> V_3 |= V_77 ;
else
V_2 -> V_3 &= ~ V_77 ;
if ( ( V_3 & V_20 ) && V_16 == V_2 -> V_22 )
V_16 += sizeof( void * ) ;
#endif
V_2 -> V_25 = V_16 ;
if ( ( ( V_3 & ( V_23 | V_21 ) ) ||
V_2 -> F_104 ) ) {
V_2 -> V_17 = V_16 ;
V_16 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_24 )
V_16 += 2 * sizeof( struct V_51 ) ;
if ( V_3 & V_20 )
V_16 += sizeof( void * ) ;
#endif
V_248 = F_220 ( V_3 , V_248 , V_2 -> V_22 ) ;
V_2 -> V_248 = V_248 ;
V_16 = F_222 ( V_16 , V_248 ) ;
V_2 -> V_16 = V_16 ;
if ( V_260 >= 0 )
V_26 = V_260 ;
else
V_26 = F_219 ( V_16 , V_2 -> V_27 ) ;
if ( V_26 < 0 )
return 0 ;
V_2 -> V_127 = 0 ;
if ( V_26 )
V_2 -> V_127 |= V_261 ;
if ( V_2 -> V_3 & V_262 )
V_2 -> V_127 |= V_263 ;
if ( V_2 -> V_3 & V_136 )
V_2 -> V_127 |= V_264 ;
V_2 -> V_123 = F_24 ( V_26 , V_16 , V_2 -> V_27 ) ;
V_2 -> V_131 = F_24 ( F_190 ( V_16 ) , V_16 , V_2 -> V_27 ) ;
if ( F_26 ( V_2 -> V_123 ) > F_26 ( V_2 -> F_217 ) )
V_2 -> F_217 = V_2 -> V_123 ;
return ! ! F_26 ( V_2 -> V_123 ) ;
}
static int F_236 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_16 ,
T_1 V_248 , unsigned long V_3 ,
void (* F_104)( void * ) )
{
memset ( V_2 , 0 , V_265 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_104 = F_104 ;
V_2 -> V_22 = V_16 ;
V_2 -> V_248 = V_248 ;
V_2 -> V_3 = F_103 ( V_16 , V_3 , V_6 , F_104 ) ;
V_2 -> V_27 = 0 ;
if ( V_149 && ( V_2 -> V_3 & V_23 ) )
V_2 -> V_27 = sizeof( struct V_147 ) ;
if ( ! F_235 ( V_2 , - 1 ) )
goto error;
if ( V_119 ) {
if ( F_190 ( V_2 -> V_16 ) > F_190 ( V_2 -> V_22 ) ) {
V_2 -> V_3 &= ~ V_266 ;
V_2 -> V_17 = 0 ;
if ( ! F_235 ( V_2 , - 1 ) )
goto error;
}
}
#if F_34 ( V_39 ) && \
F_34 ( V_40 )
if ( F_237 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_41 ;
#endif
F_234 ( V_2 , F_238 ( V_2 -> V_16 ) / 2 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_165 = 0 ;
else if ( V_2 -> V_16 >= V_28 )
V_2 -> V_165 = 2 ;
else if ( V_2 -> V_16 >= 1024 )
V_2 -> V_165 = 6 ;
else if ( V_2 -> V_16 >= 256 )
V_2 -> V_165 = 13 ;
else
V_2 -> V_165 = 30 ;
V_2 -> V_267 = 1 ;
#ifdef F_147
V_2 -> V_173 = 1000 ;
#endif
if ( ! F_233 ( V_2 ) )
goto error;
if ( F_227 ( V_2 ) )
return 1 ;
F_231 ( V_2 ) ;
error:
if ( V_3 & V_268 )
F_239 ( L_75
L_76 ,
V_2 -> V_6 , ( unsigned long ) V_16 , V_2 -> V_16 , F_25 ( V_2 -> V_123 ) ,
V_2 -> V_17 , V_3 ) ;
return 0 ;
}
unsigned int F_240 ( struct V_1 * V_2 )
{
return V_2 -> V_22 ;
}
static void F_241 ( struct V_1 * V_2 , struct V_12 * V_12 ,
const char * V_47 )
{
#ifdef F_2
void * V_19 = F_13 ( V_12 ) ;
void * V_5 ;
unsigned long * V_46 = F_242 ( F_243 ( V_12 -> V_15 ) *
sizeof( long ) , V_207 ) ;
if ( ! V_46 )
return;
F_62 ( V_2 , V_12 , L_18 , V_47 ) ;
F_27 ( V_12 ) ;
F_42 ( V_2 , V_12 , V_46 ) ;
F_122 (p, s, addr, page->objects) {
if ( ! F_244 ( F_21 ( V_5 , V_2 , V_19 ) , V_46 ) ) {
F_38 ( V_49 L_77 ,
V_5 , V_5 - V_19 ) ;
F_53 ( V_2 , V_5 ) ;
}
}
F_29 ( V_12 ) ;
F_7 ( V_46 ) ;
#endif
}
static void F_245 ( struct V_1 * V_2 , struct V_10 * V_38 )
{
struct V_12 * V_12 , * V_148 ;
F_142 (page, h, &n->partial, lru) {
if ( ! V_12 -> V_25 ) {
F_137 ( V_38 , V_12 ) ;
F_134 ( V_2 , V_12 ) ;
} else {
F_241 ( V_2 , V_12 ,
L_78 ) ;
}
}
}
static inline int F_246 ( struct V_1 * V_2 )
{
int V_11 ;
F_179 ( V_2 ) ;
F_247 ( V_2 -> V_9 ) ;
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
F_245 ( V_2 , V_38 ) ;
if ( V_38 -> V_153 || F_90 ( V_2 , V_11 ) )
return 1 ;
}
F_231 ( V_2 ) ;
return 0 ;
}
void F_248 ( struct V_1 * V_2 )
{
F_249 ( & V_269 ) ;
V_2 -> V_267 -- ;
if ( ! V_2 -> V_267 ) {
F_89 ( & V_2 -> V_270 ) ;
F_250 ( & V_269 ) ;
if ( F_246 ( V_2 ) ) {
F_38 ( V_49 L_79
L_80 , V_2 -> V_6 , V_271 ) ;
F_60 () ;
}
if ( V_2 -> V_3 & V_23 )
F_251 () ;
F_6 ( V_2 ) ;
} else
F_250 ( & V_269 ) ;
}
static int T_7 F_252 ( char * V_115 )
{
F_253 ( & V_115 , & V_239 ) ;
return 1 ;
}
static int T_7 F_254 ( char * V_115 )
{
F_253 ( & V_115 , & V_245 ) ;
V_245 = V_131 ( V_245 , V_246 - 1 ) ;
return 1 ;
}
static int T_7 F_255 ( char * V_115 )
{
F_253 ( & V_115 , & V_243 ) ;
return 1 ;
}
static int T_7 F_256 ( char * V_115 )
{
V_272 = 1 ;
return 1 ;
}
static struct V_1 * T_7 F_257 ( const char * V_6 ,
int V_16 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_202 ( V_1 , V_254 ) ;
if ( ! F_236 ( V_2 , V_6 , V_16 , V_273 ,
V_3 , NULL ) )
goto F_239;
F_87 ( & V_2 -> V_270 , & V_274 ) ;
return V_2 ;
F_239:
F_239 ( L_81 , V_6 , V_16 ) ;
return NULL ;
}
static inline int F_258 ( T_1 V_87 )
{
return ( V_87 - 1 ) / 8 ;
}
static struct V_1 * F_259 ( T_1 V_16 , T_5 V_3 )
{
int V_275 ;
if ( V_16 <= 192 ) {
if ( ! V_16 )
return V_276 ;
V_275 = V_277 [ F_258 ( V_16 ) ] ;
} else
V_275 = F_218 ( V_16 - 1 ) ;
#ifdef F_260
if ( F_3 ( ( V_3 & V_263 ) ) )
return V_278 [ V_275 ] ;
#endif
return V_279 [ V_275 ] ;
}
void * F_261 ( T_1 V_16 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_16 > V_280 ) )
return F_262 ( V_16 , V_3 ) ;
V_2 = F_259 ( V_16 , V_3 ) ;
if ( F_3 ( F_263 ( V_2 ) ) )
return V_2 ;
V_224 = F_199 ( V_2 , V_3 , V_125 , V_225 ) ;
F_205 ( V_225 , V_224 , V_16 , V_2 -> V_16 , V_3 ) ;
return V_224 ;
}
static void * F_264 ( T_1 V_16 , T_5 V_3 , int V_11 )
{
struct V_12 * V_12 ;
void * V_281 = NULL ;
V_3 |= V_261 | V_124 ;
V_12 = F_265 ( V_11 , V_3 , F_190 ( V_16 ) ) ;
if ( V_12 )
V_281 = F_13 ( V_12 ) ;
F_266 ( V_281 , V_16 , 1 , V_3 ) ;
return V_281 ;
}
void * F_267 ( T_1 V_16 , T_5 V_3 , int V_11 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_16 > V_280 ) ) {
V_224 = F_264 ( V_16 , V_3 , V_11 ) ;
F_211 ( V_225 , V_224 ,
V_16 , V_28 << F_190 ( V_16 ) ,
V_3 , V_11 ) ;
return V_224 ;
}
V_2 = F_259 ( V_16 , V_3 ) ;
if ( F_3 ( F_263 ( V_2 ) ) )
return V_2 ;
V_224 = F_199 ( V_2 , V_3 , V_11 , V_225 ) ;
F_211 ( V_225 , V_224 , V_16 , V_2 -> V_16 , V_3 , V_11 ) ;
return V_224 ;
}
T_1 F_268 ( const void * V_13 )
{
struct V_12 * V_12 ;
if ( F_3 ( V_13 == V_276 ) )
return 0 ;
V_12 = F_130 ( V_13 ) ;
if ( F_3 ( ! F_72 ( V_12 ) ) ) {
F_139 ( ! F_269 ( V_12 ) ) ;
return V_28 << F_69 ( V_12 ) ;
}
return F_22 ( V_12 -> V_114 ) ;
}
bool F_270 ( const void * V_30 )
{
struct V_12 * V_12 ;
void * V_13 = ( void * ) V_30 ;
unsigned long V_3 ;
bool V_282 ;
if ( F_3 ( F_263 ( V_30 ) ) )
return false ;
F_40 ( V_3 ) ;
V_12 = F_130 ( V_30 ) ;
if ( F_3 ( ! F_72 ( V_12 ) ) ) {
V_282 = true ;
goto V_283;
}
F_27 ( V_12 ) ;
if ( F_73 ( V_12 -> V_114 , V_12 , V_13 ) ) {
F_61 ( V_12 -> V_114 , V_12 , V_13 , L_82 ) ;
V_282 = false ;
} else {
V_282 = true ;
}
F_29 ( V_12 ) ;
V_283:
F_41 ( V_3 ) ;
return V_282 ;
}
void F_7 ( const void * V_30 )
{
struct V_12 * V_12 ;
void * V_13 = ( void * ) V_30 ;
F_271 ( V_225 , V_30 ) ;
if ( F_3 ( F_263 ( V_30 ) ) )
return;
V_12 = F_130 ( V_30 ) ;
if ( F_3 ( ! F_72 ( V_12 ) ) ) {
F_118 ( ! F_269 ( V_12 ) ) ;
F_272 ( V_30 ) ;
F_273 ( V_12 ) ;
return;
}
F_213 ( V_12 -> V_114 , V_12 , V_13 , V_225 ) ;
}
int F_274 ( struct V_1 * V_2 )
{
int V_11 ;
int V_56 ;
struct V_10 * V_38 ;
struct V_12 * V_12 ;
struct V_12 * V_71 ;
int V_15 = F_26 ( V_2 -> F_217 ) ;
struct V_150 * V_284 =
F_275 ( sizeof( struct V_150 ) * V_15 , V_257 ) ;
unsigned long V_3 ;
if ( ! V_284 )
return - V_285 ;
F_179 ( V_2 ) ;
F_232 (node, N_NORMAL_MEMORY) {
V_38 = F_11 ( V_2 , V_11 ) ;
if ( ! V_38 -> V_153 )
continue;
for ( V_56 = 0 ; V_56 < V_15 ; V_56 ++ )
F_225 ( V_284 + V_56 ) ;
F_185 ( & V_38 -> V_161 , V_3 ) ;
F_142 (page, t, &n->partial, lru) {
F_276 ( & V_12 -> V_105 , V_284 + V_12 -> V_25 ) ;
if ( ! V_12 -> V_25 )
V_38 -> V_153 -- ;
}
for ( V_56 = V_15 - 1 ; V_56 > 0 ; V_56 -- )
F_277 ( V_284 + V_56 , V_38 -> V_155 . V_286 ) ;
F_187 ( & V_38 -> V_161 , V_3 ) ;
F_142 (page, t, slabs_by_inuse, lru)
F_134 ( V_2 , V_12 ) ;
}
F_7 ( V_284 ) ;
return 0 ;
}
static int F_278 ( void * V_287 )
{
struct V_1 * V_2 ;
F_249 ( & V_269 ) ;
F_186 (s, &slab_caches, list)
F_274 ( V_2 ) ;
F_250 ( & V_269 ) ;
return 0 ;
}
static void F_279 ( void * V_287 )
{
struct V_10 * V_38 ;
struct V_1 * V_2 ;
struct V_288 * V_289 = V_287 ;
int V_290 ;
V_290 = V_289 -> V_291 ;
if ( V_290 < 0 )
return;
F_249 ( & V_269 ) ;
F_186 (s, &slab_caches, list) {
V_38 = F_11 ( V_2 , V_290 ) ;
if ( V_38 ) {
F_118 ( F_90 ( V_2 , V_290 ) ) ;
V_2 -> V_11 [ V_290 ] = NULL ;
F_214 ( V_10 , V_38 ) ;
}
}
F_250 ( & V_269 ) ;
}
static int F_280 ( void * V_287 )
{
struct V_10 * V_38 ;
struct V_1 * V_2 ;
struct V_288 * V_289 = V_287 ;
int V_209 = V_289 -> V_291 ;
int V_224 = 0 ;
if ( V_209 < 0 )
return 0 ;
F_249 ( & V_269 ) ;
F_186 (s, &slab_caches, list) {
V_38 = F_202 ( V_10 , V_257 ) ;
if ( ! V_38 ) {
V_224 = - V_285 ;
goto V_113;
}
F_223 ( V_38 ) ;
V_2 -> V_11 [ V_209 ] = V_38 ;
}
V_113:
F_250 ( & V_269 ) ;
return V_224 ;
}
static int F_281 ( struct V_292 * V_293 ,
unsigned long V_294 , void * V_287 )
{
int V_224 = 0 ;
switch ( V_294 ) {
case V_295 :
V_224 = F_280 ( V_287 ) ;
break;
case V_296 :
V_224 = F_278 ( V_287 ) ;
break;
case V_297 :
case V_298 :
F_279 ( V_287 ) ;
break;
case V_299 :
case V_300 :
break;
}
if ( V_224 )
V_224 = F_282 ( V_224 ) ;
else
V_224 = V_301 ;
return V_224 ;
}
static void T_7 F_283 ( struct V_1 * V_2 )
{
int V_11 ;
F_87 ( & V_2 -> V_270 , & V_274 ) ;
V_2 -> V_267 = - 1 ;
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
struct V_12 * V_5 ;
if ( V_38 ) {
F_186 (p, &n->partial, lru)
V_5 -> V_114 = V_2 ;
#ifdef F_2
F_186 (p, &n->full, lru)
V_5 -> V_114 = V_2 ;
#endif
}
}
}
void T_7 F_284 ( void )
{
int V_56 ;
int V_302 = 0 ;
struct V_1 * V_303 ;
int V_26 ;
struct V_1 * V_304 ;
unsigned long V_305 ;
if ( F_285 () )
V_245 = 0 ;
V_265 = F_286 ( struct V_1 , V_11 ) +
V_306 * sizeof( struct V_10 * ) ;
V_305 = F_222 ( V_265 , F_221 () ) ;
V_26 = F_190 ( 2 * V_305 ) ;
V_1 = ( void * ) F_287 ( V_254 , V_26 ) ;
V_10 = ( void * ) V_1 + V_305 ;
F_236 ( V_10 , L_83 ,
sizeof( struct V_10 ) ,
0 , V_249 | V_268 , NULL ) ;
F_288 ( F_281 , V_307 ) ;
V_255 = V_308 ;
V_303 = V_1 ;
F_236 ( V_1 , L_84 , V_265 ,
0 , V_249 | V_268 , NULL ) ;
V_1 = F_202 ( V_1 , V_254 ) ;
memcpy ( V_1 , V_303 , V_265 ) ;
V_304 = V_10 ;
V_10 = F_202 ( V_1 , V_254 ) ;
memcpy ( V_10 , V_304 , V_265 ) ;
F_283 ( V_10 ) ;
V_302 ++ ;
F_283 ( V_1 ) ;
V_302 ++ ;
F_289 ( ( unsigned long ) V_303 , V_26 ) ;
F_228 ( V_309 > 256 ||
( V_309 & ( V_309 - 1 ) ) ) ;
for ( V_56 = 8 ; V_56 < V_309 ; V_56 += 8 ) {
int V_310 = F_258 ( V_56 ) ;
if ( V_310 >= F_290 ( V_277 ) )
break;
V_277 [ V_310 ] = V_311 ;
}
if ( V_309 == 64 ) {
for ( V_56 = 64 + 8 ; V_56 <= 96 ; V_56 += 8 )
V_277 [ F_258 ( V_56 ) ] = 7 ;
} else if ( V_309 == 128 ) {
for ( V_56 = 128 + 8 ; V_56 <= 192 ; V_56 += 8 )
V_277 [ F_258 ( V_56 ) ] = 8 ;
}
if ( V_309 <= 32 ) {
V_279 [ 1 ] = F_257 ( L_85 , 96 , 0 ) ;
V_302 ++ ;
}
if ( V_309 <= 64 ) {
V_279 [ 2 ] = F_257 ( L_86 , 192 , 0 ) ;
V_302 ++ ;
}
for ( V_56 = V_311 ; V_56 < V_253 ; V_56 ++ ) {
V_279 [ V_56 ] = F_257 ( L_87 , 1 << V_56 , 0 ) ;
V_302 ++ ;
}
V_255 = V_312 ;
if ( V_309 <= 32 ) {
V_279 [ 1 ] -> V_6 = F_291 ( V_279 [ 1 ] -> V_6 , V_254 ) ;
F_118 ( ! V_279 [ 1 ] -> V_6 ) ;
}
if ( V_309 <= 64 ) {
V_279 [ 2 ] -> V_6 = F_291 ( V_279 [ 2 ] -> V_6 , V_254 ) ;
F_118 ( ! V_279 [ 2 ] -> V_6 ) ;
}
for ( V_56 = V_311 ; V_56 < V_253 ; V_56 ++ ) {
char * V_2 = F_292 ( V_254 , L_88 , 1 << V_56 ) ;
F_118 ( ! V_2 ) ;
V_279 [ V_56 ] -> V_6 = V_2 ;
}
#ifdef F_293
F_294 ( & V_313 ) ;
#endif
#ifdef F_260
for ( V_56 = 0 ; V_56 < V_253 ; V_56 ++ ) {
struct V_1 * V_2 = V_279 [ V_56 ] ;
if ( V_2 && V_2 -> V_16 ) {
char * V_6 = F_292 ( V_254 ,
L_89 , V_2 -> V_22 ) ;
F_118 ( ! V_6 ) ;
V_278 [ V_56 ] = F_257 ( V_6 ,
V_2 -> V_22 , V_262 ) ;
}
}
#endif
F_38 ( V_45
L_90
L_91 ,
V_302 , F_221 () ,
V_239 , V_245 , V_243 ,
V_244 , V_306 ) ;
}
void T_7 F_295 ( void )
{
}
static int F_296 ( struct V_1 * V_2 )
{
if ( V_272 || ( V_2 -> V_3 & V_314 ) )
return 1 ;
if ( V_2 -> F_104 )
return 1 ;
if ( V_2 -> V_267 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_297 ( T_1 V_16 ,
T_1 V_248 , unsigned long V_3 , const char * V_6 ,
void (* F_104)( void * ) )
{
struct V_1 * V_2 ;
if ( V_272 || ( V_3 & V_314 ) )
return NULL ;
if ( F_104 )
return NULL ;
V_16 = F_222 ( V_16 , sizeof( void * ) ) ;
V_248 = F_220 ( V_3 , V_248 , V_16 ) ;
V_16 = F_222 ( V_16 , V_248 ) ;
V_3 = F_103 ( V_16 , V_3 , V_6 , NULL ) ;
F_186 (s, &slab_caches, list) {
if ( F_296 ( V_2 ) )
continue;
if ( V_16 > V_2 -> V_16 )
continue;
if ( ( V_3 & V_315 ) != ( V_2 -> V_3 & V_315 ) )
continue;
if ( ( V_2 -> V_16 & ~ ( V_248 - 1 ) ) != V_2 -> V_16 )
continue;
if ( V_2 -> V_16 - V_16 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_298 ( const char * V_6 , T_1 V_16 ,
T_1 V_248 , unsigned long V_3 , void (* F_104)( void * ) )
{
struct V_1 * V_2 ;
char * V_38 ;
V_2 = F_297 ( V_16 , V_248 , V_3 , V_6 , F_104 ) ;
if ( V_2 ) {
V_2 -> V_267 ++ ;
V_2 -> V_22 = F_217 ( V_2 -> V_22 , ( int ) V_16 ) ;
V_2 -> V_25 = F_299 ( int , V_2 -> V_25 , F_222 ( V_16 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_267 -- ;
return NULL ;
}
return V_2 ;
}
V_38 = F_291 ( V_6 , V_257 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_275 ( V_265 , V_257 ) ;
if ( V_2 ) {
if ( F_236 ( V_2 , V_38 ,
V_16 , V_248 , V_3 , F_104 ) ) {
int V_316 ;
F_87 ( & V_2 -> V_270 , & V_274 ) ;
F_250 ( & V_269 ) ;
V_316 = F_4 ( V_2 ) ;
F_249 ( & V_269 ) ;
if ( ! V_316 )
return V_2 ;
F_89 ( & V_2 -> V_270 ) ;
F_246 ( V_2 ) ;
}
F_7 ( V_2 ) ;
}
F_7 ( V_38 ) ;
return NULL ;
}
static int T_9 F_300 ( struct V_292 * V_317 ,
unsigned long V_294 , void * V_318 )
{
long V_64 = ( long ) V_318 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_294 ) {
case V_319 :
case V_320 :
case V_321 :
case V_322 :
F_249 ( & V_269 ) ;
F_186 (s, &slab_caches, list) {
F_40 ( V_3 ) ;
F_175 ( V_2 , V_64 ) ;
F_41 ( V_3 ) ;
}
F_250 ( & V_269 ) ;
break;
default:
break;
}
return V_301 ;
}
void * F_301 ( T_1 V_16 , T_5 V_208 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_16 > V_280 ) )
return F_262 ( V_16 , V_208 ) ;
V_2 = F_259 ( V_16 , V_208 ) ;
if ( F_3 ( F_263 ( V_2 ) ) )
return V_2 ;
V_224 = F_199 ( V_2 , V_208 , V_125 , V_323 ) ;
F_205 ( V_323 , V_224 , V_16 , V_2 -> V_16 , V_208 ) ;
return V_224 ;
}
void * F_302 ( T_1 V_16 , T_5 V_208 ,
int V_11 , unsigned long V_323 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_16 > V_280 ) ) {
V_224 = F_264 ( V_16 , V_208 , V_11 ) ;
F_211 ( V_323 , V_224 ,
V_16 , V_28 << F_190 ( V_16 ) ,
V_208 , V_11 ) ;
return V_224 ;
}
V_2 = F_259 ( V_16 , V_208 ) ;
if ( F_3 ( F_263 ( V_2 ) ) )
return V_2 ;
V_224 = F_199 ( V_2 , V_208 , V_11 , V_323 ) ;
F_211 ( V_323 , V_224 , V_16 , V_2 -> V_16 , V_208 , V_11 ) ;
return V_224 ;
}
static int F_303 ( struct V_12 * V_12 )
{
return V_12 -> V_25 ;
}
static int F_304 ( struct V_12 * V_12 )
{
return V_12 -> V_15 ;
}
static int F_305 ( struct V_1 * V_2 , struct V_12 * V_12 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_19 = F_13 ( V_12 ) ;
if ( ! F_71 ( V_2 , V_12 ) ||
! F_73 ( V_2 , V_12 , NULL ) )
return 0 ;
F_306 ( V_46 , V_12 -> V_15 ) ;
F_42 ( V_2 , V_12 , V_46 ) ;
F_122 (p, s, addr, page->objects) {
if ( F_244 ( F_21 ( V_5 , V_2 , V_19 ) , V_46 ) )
if ( ! F_70 ( V_2 , V_12 , V_5 , V_109 ) )
return 0 ;
}
F_122 (p, s, addr, page->objects)
if ( ! F_244 ( F_21 ( V_5 , V_2 , V_19 ) , V_46 ) )
if ( ! F_70 ( V_2 , V_12 , V_5 , V_93 ) )
return 0 ;
return 1 ;
}
static void F_307 ( struct V_1 * V_2 , struct V_12 * V_12 ,
unsigned long * V_46 )
{
F_27 ( V_12 ) ;
F_305 ( V_2 , V_12 , V_46 ) ;
F_29 ( V_12 ) ;
}
static int F_308 ( struct V_1 * V_2 ,
struct V_10 * V_38 , unsigned long * V_46 )
{
unsigned long V_324 = 0 ;
struct V_12 * V_12 ;
unsigned long V_3 ;
F_185 ( & V_38 -> V_161 , V_3 ) ;
F_186 (page, &n->partial, lru) {
F_307 ( V_2 , V_12 , V_46 ) ;
V_324 ++ ;
}
if ( V_324 != V_38 -> V_153 )
F_38 ( V_49 L_92
L_93 , V_2 -> V_6 , V_324 , V_38 -> V_153 ) ;
if ( ! ( V_2 -> V_3 & V_24 ) )
goto V_113;
F_186 (page, &n->full, lru) {
F_307 ( V_2 , V_12 , V_46 ) ;
V_324 ++ ;
}
if ( V_324 != F_91 ( & V_38 -> V_107 ) )
F_38 ( V_49 L_94
L_93 , V_2 -> V_6 , V_324 ,
F_91 ( & V_38 -> V_107 ) ) ;
V_113:
F_187 ( & V_38 -> V_161 , V_3 ) ;
return V_324 ;
}
static long F_309 ( struct V_1 * V_2 )
{
int V_11 ;
unsigned long V_324 = 0 ;
unsigned long * V_46 = F_275 ( F_243 ( F_26 ( V_2 -> F_217 ) ) *
sizeof( unsigned long ) , V_257 ) ;
if ( ! V_46 )
return - V_285 ;
F_179 ( V_2 ) ;
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
V_324 += F_308 ( V_2 , V_38 , V_46 ) ;
}
F_7 ( V_46 ) ;
return V_324 ;
}
static void F_310 ( struct V_325 * V_71 )
{
if ( V_71 -> F_217 )
F_289 ( ( unsigned long ) V_71 -> V_326 ,
F_190 ( sizeof( struct V_327 ) * V_71 -> F_217 ) ) ;
}
static int F_311 ( struct V_325 * V_71 , unsigned long F_217 , T_5 V_3 )
{
struct V_327 * V_185 ;
int V_26 ;
V_26 = F_190 ( sizeof( struct V_327 ) * F_217 ) ;
V_185 = ( void * ) F_287 ( V_3 , V_26 ) ;
if ( ! V_185 )
return 0 ;
if ( V_71 -> V_324 ) {
memcpy ( V_185 , V_71 -> V_326 , sizeof( struct V_327 ) * V_71 -> V_324 ) ;
F_310 ( V_71 ) ;
}
V_71 -> F_217 = F_217 ;
V_71 -> V_326 = V_185 ;
return 1 ;
}
static int F_312 ( struct V_325 * V_71 , struct V_1 * V_2 ,
const struct V_51 * V_51 )
{
long V_85 , V_89 , V_328 ;
struct V_327 * V_185 ;
unsigned long V_329 ;
unsigned long V_330 = V_68 - V_51 -> V_67 ;
V_85 = - 1 ;
V_89 = V_71 -> V_324 ;
for ( ; ; ) {
V_328 = V_85 + ( V_89 - V_85 + 1 ) / 2 ;
if ( V_328 == V_89 )
break;
V_329 = V_71 -> V_326 [ V_328 ] . V_19 ;
if ( V_51 -> V_19 == V_329 ) {
V_185 = & V_71 -> V_326 [ V_328 ] ;
V_185 -> V_324 ++ ;
if ( V_51 -> V_67 ) {
V_185 -> V_331 += V_330 ;
if ( V_330 < V_185 -> V_332 )
V_185 -> V_332 = V_330 ;
if ( V_330 > V_185 -> V_333 )
V_185 -> V_333 = V_330 ;
if ( V_51 -> V_65 < V_185 -> V_334 )
V_185 -> V_334 = V_51 -> V_65 ;
if ( V_51 -> V_65 > V_185 -> V_335 )
V_185 -> V_335 = V_51 -> V_65 ;
F_313 ( V_51 -> V_64 ,
F_314 ( V_185 -> V_336 ) ) ;
}
F_315 ( F_119 ( F_316 ( V_51 ) ) , V_185 -> V_337 ) ;
return 1 ;
}
if ( V_51 -> V_19 < V_329 )
V_89 = V_328 ;
else
V_85 = V_328 ;
}
if ( V_71 -> V_324 >= V_71 -> F_217 && ! F_311 ( V_71 , 2 * V_71 -> F_217 , V_207 ) )
return 0 ;
V_185 = V_71 -> V_326 + V_328 ;
if ( V_328 < V_71 -> V_324 )
memmove ( V_185 + 1 , V_185 ,
( V_71 -> V_324 - V_328 ) * sizeof( struct V_327 ) ) ;
V_71 -> V_324 ++ ;
V_185 -> V_324 = 1 ;
V_185 -> V_19 = V_51 -> V_19 ;
V_185 -> V_331 = V_330 ;
V_185 -> V_332 = V_330 ;
V_185 -> V_333 = V_330 ;
V_185 -> V_334 = V_51 -> V_65 ;
V_185 -> V_335 = V_51 -> V_65 ;
F_317 ( F_314 ( V_185 -> V_336 ) ) ;
F_313 ( V_51 -> V_64 , F_314 ( V_185 -> V_336 ) ) ;
F_318 ( V_185 -> V_337 ) ;
F_315 ( F_119 ( F_316 ( V_51 ) ) , V_185 -> V_337 ) ;
return 1 ;
}
static void F_319 ( struct V_325 * V_71 , struct V_1 * V_2 ,
struct V_12 * V_12 , enum V_52 V_53 ,
unsigned long * V_46 )
{
void * V_19 = F_13 ( V_12 ) ;
void * V_5 ;
F_306 ( V_46 , V_12 -> V_15 ) ;
F_42 ( V_2 , V_12 , V_46 ) ;
F_122 (p, s, addr, page->objects)
if ( ! F_244 ( F_21 ( V_5 , V_2 , V_19 ) , V_46 ) )
F_312 ( V_71 , V_2 , F_46 ( V_2 , V_5 , V_53 ) ) ;
}
static int F_320 ( struct V_1 * V_2 , char * V_73 ,
enum V_52 V_53 )
{
int V_338 = 0 ;
unsigned long V_56 ;
struct V_325 V_71 = { 0 , 0 , NULL } ;
int V_11 ;
unsigned long * V_46 = F_275 ( F_243 ( F_26 ( V_2 -> F_217 ) ) *
sizeof( unsigned long ) , V_257 ) ;
if ( ! V_46 || ! F_311 ( & V_71 , V_28 / sizeof( struct V_327 ) ,
V_339 ) ) {
F_7 ( V_46 ) ;
return sprintf ( V_73 , L_95 ) ;
}
F_179 ( V_2 ) ;
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
unsigned long V_3 ;
struct V_12 * V_12 ;
if ( ! F_91 ( & V_38 -> V_107 ) )
continue;
F_185 ( & V_38 -> V_161 , V_3 ) ;
F_186 (page, &n->partial, lru)
F_319 ( & V_71 , V_2 , V_12 , V_53 , V_46 ) ;
F_186 (page, &n->full, lru)
F_319 ( & V_71 , V_2 , V_12 , V_53 , V_46 ) ;
F_187 ( & V_38 -> V_161 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_324 ; V_56 ++ ) {
struct V_327 * V_185 = & V_71 . V_326 [ V_56 ] ;
if ( V_338 > V_28 - V_340 - 100 )
break;
V_338 += sprintf ( V_73 + V_338 , L_96 , V_185 -> V_324 ) ;
if ( V_185 -> V_19 )
V_338 += sprintf ( V_73 + V_338 , L_97 , ( void * ) V_185 -> V_19 ) ;
else
V_338 += sprintf ( V_73 + V_338 , L_98 ) ;
if ( V_185 -> V_331 != V_185 -> V_332 ) {
V_338 += sprintf ( V_73 + V_338 , L_99 ,
V_185 -> V_332 ,
( long ) F_321 ( V_185 -> V_331 , V_185 -> V_324 ) ,
V_185 -> V_333 ) ;
} else
V_338 += sprintf ( V_73 + V_338 , L_100 ,
V_185 -> V_332 ) ;
if ( V_185 -> V_334 != V_185 -> V_335 )
V_338 += sprintf ( V_73 + V_338 , L_101 ,
V_185 -> V_334 , V_185 -> V_335 ) ;
else
V_338 += sprintf ( V_73 + V_338 , L_102 ,
V_185 -> V_334 ) ;
if ( F_322 () > 1 &&
! F_323 ( F_314 ( V_185 -> V_336 ) ) &&
V_338 < V_28 - 60 ) {
V_338 += sprintf ( V_73 + V_338 , L_103 ) ;
V_338 += F_324 ( V_73 + V_338 , V_28 - V_338 - 50 ,
F_314 ( V_185 -> V_336 ) ) ;
}
if ( V_341 > 1 && ! F_325 ( V_185 -> V_337 ) &&
V_338 < V_28 - 60 ) {
V_338 += sprintf ( V_73 + V_338 , L_104 ) ;
V_338 += F_326 ( V_73 + V_338 , V_28 - V_338 - 50 ,
V_185 -> V_337 ) ;
}
V_338 += sprintf ( V_73 + V_338 , L_105 ) ;
}
F_310 ( & V_71 ) ;
F_7 ( V_46 ) ;
if ( ! V_71 . V_324 )
V_338 += sprintf ( V_73 , L_106 ) ;
return V_338 ;
}
static void F_327 ( void )
{
T_3 * V_5 ;
F_228 ( V_309 > 16 || V_253 < 10 ) ;
F_38 ( V_49 L_107 ) ;
F_38 ( V_49 L_108 ) ;
F_38 ( V_49 L_109 ) ;
V_5 = F_242 ( 16 , V_257 ) ;
V_5 [ 16 ] = 0x12 ;
F_38 ( V_49 L_110
L_111 , V_5 + 16 ) ;
F_309 ( V_279 [ 4 ] ) ;
V_5 = F_242 ( 32 , V_257 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_38 ( V_49 L_112
L_113 , V_5 ) ;
F_38 ( V_49
L_114 ) ;
F_309 ( V_279 [ 5 ] ) ;
V_5 = F_242 ( 64 , V_257 ) ;
V_5 += 64 + ( F_149 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_38 ( V_49 L_115 ,
V_5 ) ;
F_38 ( V_49
L_114 ) ;
F_309 ( V_279 [ 6 ] ) ;
F_38 ( V_49 L_116 ) ;
V_5 = F_242 ( 128 , V_257 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_38 ( V_49 L_117 , V_5 ) ;
F_309 ( V_279 [ 7 ] ) ;
V_5 = F_242 ( 256 , V_257 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_38 ( V_49 L_118 ,
V_5 ) ;
F_309 ( V_279 [ 8 ] ) ;
V_5 = F_242 ( 512 , V_257 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_38 ( V_49 L_119 , V_5 ) ;
F_309 ( V_279 [ 9 ] ) ;
}
static void F_327 ( void ) {}
static T_10 F_328 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_342 = 0 ;
int V_11 ;
int V_30 ;
unsigned long * V_337 ;
unsigned long * V_343 ;
V_337 = F_242 ( 2 * sizeof( unsigned long ) * V_306 , V_257 ) ;
if ( ! V_337 )
return - V_285 ;
V_343 = V_337 + V_306 ;
if ( V_3 & V_344 ) {
int V_64 ;
F_167 (cpu) {
struct V_158 * V_159 = F_168 ( V_2 -> V_9 , V_64 ) ;
int V_11 ;
struct V_12 * V_12 ;
V_12 = F_329 ( V_159 -> V_12 ) ;
if ( ! V_12 )
continue;
V_11 = F_119 ( V_12 ) ;
if ( V_3 & V_345 )
V_30 = V_12 -> V_15 ;
else if ( V_3 & V_346 )
V_30 = V_12 -> V_25 ;
else
V_30 = 1 ;
V_342 += V_30 ;
V_337 [ V_11 ] += V_30 ;
V_12 = F_329 ( V_159 -> V_155 ) ;
if ( V_12 ) {
V_30 = V_12 -> V_202 ;
V_342 += V_30 ;
V_337 [ V_11 ] += V_30 ;
}
V_343 [ V_11 ] ++ ;
}
}
F_330 () ;
#ifdef F_2
if ( V_3 & V_347 ) {
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
if ( V_3 & V_345 )
V_30 = F_91 ( & V_38 -> V_108 ) ;
else if ( V_3 & V_346 )
V_30 = F_91 ( & V_38 -> V_108 ) -
F_183 ( V_38 , F_182 ) ;
else
V_30 = F_91 ( & V_38 -> V_107 ) ;
V_342 += V_30 ;
V_337 [ V_11 ] += V_30 ;
}
} else
#endif
if ( V_3 & V_348 ) {
F_232 (node, N_NORMAL_MEMORY) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
if ( V_3 & V_345 )
V_30 = F_183 ( V_38 , F_304 ) ;
else if ( V_3 & V_346 )
V_30 = F_183 ( V_38 , F_303 ) ;
else
V_30 = V_38 -> V_153 ;
V_342 += V_30 ;
V_337 [ V_11 ] += V_30 ;
}
}
V_30 = sprintf ( V_73 , L_120 , V_342 ) ;
#ifdef F_147
F_232 (node, N_NORMAL_MEMORY)
if ( V_337 [ V_11 ] )
V_30 += sprintf ( V_73 + V_30 , L_121 ,
V_11 , V_337 [ V_11 ] ) ;
#endif
F_331 () ;
F_7 ( V_337 ) ;
return V_30 + sprintf ( V_73 + V_30 , L_105 ) ;
}
static int F_332 ( struct V_1 * V_2 )
{
int V_11 ;
F_191 (node) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
if ( ! V_38 )
continue;
if ( F_91 ( & V_38 -> V_108 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_333 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , V_2 -> V_16 ) ;
}
static T_10 F_334 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , V_2 -> V_248 ) ;
}
static T_10 F_335 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , V_2 -> V_22 ) ;
}
static T_10 F_336 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , F_26 ( V_2 -> V_123 ) ) ;
}
static T_10 F_337 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_26 ;
int V_349 ;
V_349 = F_338 ( V_73 , 10 , & V_26 ) ;
if ( V_349 )
return V_349 ;
if ( V_26 > V_245 || V_26 < V_239 )
return - V_350 ;
F_235 ( V_2 , V_26 ) ;
return V_48 ;
}
static T_10 F_339 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , F_25 ( V_2 -> V_123 ) ) ;
}
static T_10 F_340 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_123 , V_2 -> V_174 ) ;
}
static T_10 F_341 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_131 ;
int V_349 ;
V_349 = F_338 ( V_73 , 10 , & V_131 ) ;
if ( V_349 )
return V_349 ;
F_234 ( V_2 , V_131 ) ;
return V_48 ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_124 , V_2 -> V_165 ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_15 ;
int V_349 ;
V_349 = F_338 ( V_73 , 10 , & V_15 ) ;
if ( V_349 )
return V_349 ;
if ( V_15 && F_1 ( V_2 ) )
return - V_350 ;
V_2 -> V_165 = V_15 ;
F_179 ( V_2 ) ;
return V_48 ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! V_2 -> F_104 )
return 0 ;
return sprintf ( V_73 , L_125 , V_2 -> F_104 ) ;
}
static T_10 F_345 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , V_2 -> V_267 - 1 ) ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_73 )
{
return F_328 ( V_2 , V_73 , V_348 ) ;
}
static T_10 F_347 ( struct V_1 * V_2 , char * V_73 )
{
return F_328 ( V_2 , V_73 , V_344 ) ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_73 )
{
return F_328 ( V_2 , V_73 , V_347 | V_346 ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , char * V_73 )
{
return F_328 ( V_2 , V_73 , V_348 | V_346 ) ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_73 )
{
int V_15 = 0 ;
int V_135 = 0 ;
int V_64 ;
int V_338 ;
F_351 (cpu) {
struct V_12 * V_12 = F_168 ( V_2 -> V_9 , V_64 ) -> V_155 ;
if ( V_12 ) {
V_135 += V_12 -> V_135 ;
V_15 += V_12 -> V_202 ;
}
}
V_338 = sprintf ( V_73 , L_126 , V_15 , V_135 ) ;
#ifdef F_293
F_351 (cpu) {
struct V_12 * V_12 = F_168 ( V_2 -> V_9 , V_64 ) -> V_155 ;
if ( V_12 && V_338 < V_28 - 20 )
V_338 += sprintf ( V_73 + V_338 , L_127 , V_64 ,
V_12 -> V_202 , V_12 -> V_135 ) ;
}
#endif
return V_338 + sprintf ( V_73 + V_338 , L_105 ) ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_136 ) ) ;
}
static T_10 F_353 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_136 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_136 ;
return V_48 ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_249 ) ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_262 ) ) ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_357 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , V_2 -> V_27 ) ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_73 )
{
return F_328 ( V_2 , V_73 , V_347 ) ;
}
static T_10 F_359 ( struct V_1 * V_2 , char * V_73 )
{
return F_328 ( V_2 , V_73 , V_347 | V_345 ) ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_120 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_120 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_120 ;
}
return V_48 ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_99 ) ) ;
}
static T_10 F_363 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_99 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_99 ;
}
return V_48 ;
}
static T_10 F_364 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_20 ) ) ;
}
static T_10 F_365 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_332 ( V_2 ) )
return - V_351 ;
V_2 -> V_3 &= ~ V_20 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_20 ;
}
F_235 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_366 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_21 ) ) ;
}
static T_10 F_367 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_332 ( V_2 ) )
return - V_351 ;
V_2 -> V_3 &= ~ V_21 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_21 ;
}
F_235 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_24 ) ) ;
}
static T_10 F_369 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( F_332 ( V_2 ) )
return - V_351 ;
V_2 -> V_3 &= ~ V_24 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_24 ;
}
F_235 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_371 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
int V_224 = - V_350 ;
if ( V_73 [ 0 ] == '1' ) {
V_224 = F_309 ( V_2 ) ;
if ( V_224 >= 0 )
V_224 = V_48 ;
}
return V_224 ;
}
static T_10 F_372 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_24 ) )
return - V_247 ;
return F_320 ( V_2 , V_73 , V_70 ) ;
}
static T_10 F_373 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_24 ) )
return - V_247 ;
return F_320 ( V_2 , V_73 , V_69 ) ;
}
static T_10 F_374 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , ! ! ( V_2 -> V_3 & V_121 ) ) ;
}
static T_10 F_375 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_121 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_121 ;
return V_48 ;
}
static T_10 F_376 ( struct V_1 * V_2 , char * V_73 )
{
return 0 ;
}
static T_10 F_377 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
if ( V_73 [ 0 ] == '1' ) {
int V_111 = F_274 ( V_2 ) ;
if ( V_111 )
return V_111 ;
} else
return - V_350 ;
return V_48 ;
}
static T_10 F_378 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_122 , V_2 -> V_173 / 10 ) ;
}
static T_10 F_379 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_352 ;
int V_349 ;
V_349 = F_338 ( V_73 , 10 , & V_352 ) ;
if ( V_349 )
return V_349 ;
if ( V_352 <= 100 )
V_2 -> V_173 = V_352 * 10 ;
return V_48 ;
}
static int F_380 ( struct V_1 * V_2 , char * V_73 , enum V_7 V_8 )
{
unsigned long V_353 = 0 ;
int V_64 ;
int V_338 ;
int * V_81 = F_275 ( V_244 * sizeof( int ) , V_257 ) ;
if ( ! V_81 )
return - V_285 ;
F_351 (cpu) {
unsigned V_30 = F_168 ( V_2 -> V_9 , V_64 ) -> F_8 [ V_8 ] ;
V_81 [ V_64 ] = V_30 ;
V_353 += V_30 ;
}
V_338 = sprintf ( V_73 , L_120 , V_353 ) ;
#ifdef F_293
F_351 (cpu) {
if ( V_81 [ V_64 ] && V_338 < V_28 - 20 )
V_338 += sprintf ( V_73 + V_338 , L_128 , V_64 , V_81 [ V_64 ] ) ;
}
#endif
F_7 ( V_81 ) ;
return V_338 + sprintf ( V_73 + V_338 , L_105 ) ;
}
static void F_381 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_64 ;
F_351 (cpu)
F_168 ( V_2 -> V_9 , V_64 ) -> F_8 [ V_8 ] = 0 ;
}
static T_10 F_382 ( struct V_354 * V_355 ,
struct V_356 * V_357 ,
char * V_73 )
{
struct V_358 * V_356 ;
struct V_1 * V_2 ;
int V_349 ;
V_356 = F_383 ( V_357 ) ;
V_2 = F_384 ( V_355 ) ;
if ( ! V_356 -> V_359 )
return - V_360 ;
V_349 = V_356 -> V_359 ( V_2 , V_73 ) ;
return V_349 ;
}
static T_10 F_385 ( struct V_354 * V_355 ,
struct V_356 * V_357 ,
const char * V_73 , T_1 V_338 )
{
struct V_358 * V_356 ;
struct V_1 * V_2 ;
int V_349 ;
V_356 = F_383 ( V_357 ) ;
V_2 = F_384 ( V_355 ) ;
if ( ! V_356 -> V_361 )
return - V_360 ;
V_349 = V_356 -> V_361 ( V_2 , V_73 , V_338 ) ;
return V_349 ;
}
static void F_386 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_384 ( V_355 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_387 ( struct V_362 * V_362 , struct V_354 * V_355 )
{
struct V_363 * V_364 = F_388 ( V_355 ) ;
if ( V_364 == & V_365 )
return 1 ;
return 0 ;
}
static char * F_389 ( struct V_1 * V_2 )
{
char * V_6 = F_275 ( V_366 , V_257 ) ;
char * V_5 = V_6 ;
F_118 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_262 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_136 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_120 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_134 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_6 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_129 , V_2 -> V_16 ) ;
F_118 ( V_5 > V_6 + V_366 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_349 ;
const char * V_6 ;
int V_367 ;
if ( V_255 < V_368 )
return 0 ;
V_367 = F_296 ( V_2 ) ;
if ( V_367 ) {
F_390 ( & V_369 -> V_355 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_389 ( V_2 ) ;
}
V_2 -> V_355 . V_362 = V_369 ;
V_349 = F_391 ( & V_2 -> V_355 , & V_365 , NULL , V_6 ) ;
if ( V_349 ) {
F_392 ( & V_2 -> V_355 ) ;
return V_349 ;
}
V_349 = F_393 ( & V_2 -> V_355 , & V_370 ) ;
if ( V_349 ) {
F_394 ( & V_2 -> V_355 ) ;
F_392 ( & V_2 -> V_355 ) ;
return V_349 ;
}
F_395 ( & V_2 -> V_355 , V_371 ) ;
if ( ! V_367 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_255 < V_368 )
return;
F_395 ( & V_2 -> V_355 , V_372 ) ;
F_394 ( & V_2 -> V_355 ) ;
F_392 ( & V_2 -> V_355 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_373 * V_374 ;
if ( V_255 == V_368 ) {
F_390 ( & V_369 -> V_355 , V_6 ) ;
return F_396 ( & V_369 -> V_355 , & V_2 -> V_355 , V_6 ) ;
}
V_374 = F_275 ( sizeof( struct V_373 ) , V_257 ) ;
if ( ! V_374 )
return - V_285 ;
V_374 -> V_2 = V_2 ;
V_374 -> V_6 = V_6 ;
V_374 -> V_198 = V_375 ;
V_375 = V_374 ;
return 0 ;
}
static int T_7 F_397 ( void )
{
struct V_1 * V_2 ;
int V_349 ;
F_249 ( & V_269 ) ;
V_369 = F_398 ( L_130 , & V_376 , V_377 ) ;
if ( ! V_369 ) {
F_250 ( & V_269 ) ;
F_38 ( V_49 L_131 ) ;
return - V_247 ;
}
V_255 = V_368 ;
F_186 (s, &slab_caches, list) {
V_349 = F_4 ( V_2 ) ;
if ( V_349 )
F_38 ( V_49 L_132
L_133 , V_2 -> V_6 ) ;
}
while ( V_375 ) {
struct V_373 * V_374 = V_375 ;
V_375 = V_375 -> V_198 ;
V_349 = F_5 ( V_374 -> V_2 , V_374 -> V_6 ) ;
if ( V_349 )
F_38 ( V_49 L_134
L_135 , V_374 -> V_6 ) ;
F_7 ( V_374 ) ;
}
F_250 ( & V_269 ) ;
F_327 () ;
return 0 ;
}
static void F_399 ( struct V_378 * V_186 )
{
F_400 ( V_186 , L_136 ) ;
F_400 ( V_186 , L_137
L_138 ) ;
F_400 ( V_186 , L_139 ) ;
F_400 ( V_186 , L_140 ) ;
F_401 ( V_186 , '\n' ) ;
}
static void * F_402 ( struct V_378 * V_186 , T_11 * V_328 )
{
T_11 V_38 = * V_328 ;
F_249 ( & V_269 ) ;
if ( ! V_38 )
F_399 ( V_186 ) ;
return F_403 ( & V_274 , * V_328 ) ;
}
static void * F_404 ( struct V_378 * V_186 , void * V_5 , T_11 * V_328 )
{
return F_405 ( V_5 , & V_274 , V_328 ) ;
}
static void F_406 ( struct V_378 * V_186 , void * V_5 )
{
F_250 ( & V_269 ) ;
}
static int F_407 ( struct V_378 * V_186 , void * V_5 )
{
unsigned long V_379 = 0 ;
unsigned long V_107 = 0 ;
unsigned long V_380 = 0 ;
unsigned long V_211 = 0 ;
unsigned long V_212 = 0 ;
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_408 ( V_5 , struct V_1 , V_270 ) ;
F_191 (node) {
struct V_10 * V_38 = F_11 ( V_2 , V_11 ) ;
if ( ! V_38 )
continue;
V_379 += V_38 -> V_153 ;
V_107 += F_91 ( & V_38 -> V_107 ) ;
V_211 += F_91 ( & V_38 -> V_108 ) ;
V_212 += F_183 ( V_38 , F_182 ) ;
}
V_380 = V_211 - V_212 ;
F_409 ( V_186 , L_141 , V_2 -> V_6 , V_380 ,
V_211 , V_2 -> V_16 , F_26 ( V_2 -> V_123 ) ,
( 1 << F_25 ( V_2 -> V_123 ) ) ) ;
F_409 ( V_186 , L_142 , 0 , 0 , 0 ) ;
F_409 ( V_186 , L_143 , V_107 , V_107 ,
0UL ) ;
F_401 ( V_186 , '\n' ) ;
return 0 ;
}
static int F_410 ( struct V_381 * V_381 , struct V_382 * V_382 )
{
return F_411 ( V_382 , & V_383 ) ;
}
static int T_7 F_412 ( void )
{
F_413 ( L_144 , V_384 , NULL , & V_385 ) ;
return 0 ;
}
