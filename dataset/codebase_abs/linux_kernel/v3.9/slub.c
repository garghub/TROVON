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
F_57 ( V_74 , V_75 ) ;
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
unsigned int V_76 ;
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
V_76 = V_2 -> V_16 + sizeof( void * ) ;
else
V_76 = V_2 -> V_24 ;
if ( V_2 -> V_3 & V_23 )
V_76 += 2 * sizeof( struct V_51 ) ;
if ( V_76 != V_2 -> V_15 )
F_44 ( L_17 , V_5 + V_76 , V_2 -> V_15 - V_76 ) ;
F_61 () ;
}
static void F_62 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_77 )
{
F_55 ( V_2 , L_18 , V_77 ) ;
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
static void F_64 ( struct V_1 * V_2 , void * V_12 , T_3 V_78 )
{
T_3 * V_5 = V_12 ;
if ( V_2 -> V_3 & V_79 ) {
memset ( V_5 , V_80 , V_2 -> V_21 - 1 ) ;
V_5 [ V_2 -> V_21 - 1 ] = V_81 ;
}
if ( V_2 -> V_3 & V_19 )
memset ( V_5 + V_2 -> V_21 , V_78 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
static void F_65 ( struct V_1 * V_2 , char * V_82 , T_3 V_83 ,
void * V_84 , void * V_85 )
{
F_58 ( V_2 , L_19 , V_84 , V_85 - 1 , V_83 ) ;
memset ( V_84 , V_83 , V_85 - V_84 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_11 * V_11 ,
T_3 * V_12 , char * V_86 ,
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
F_55 ( V_2 , L_20 , V_86 ) ;
F_38 ( V_49 L_21 ,
V_90 , V_91 - 1 , V_90 [ 0 ] , V_88 ) ;
F_59 ( V_2 , V_11 , V_12 ) ;
F_65 ( V_2 , V_86 , V_88 , V_90 , V_91 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_11 , T_3 * V_5 )
{
unsigned long V_76 = V_2 -> V_24 ;
if ( V_2 -> V_16 )
V_76 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_23 )
V_76 += 2 * sizeof( struct V_51 ) ;
if ( V_2 -> V_15 == V_76 )
return 1 ;
return F_66 ( V_2 , V_11 , V_5 , L_22 ,
V_5 + V_76 , V_92 , V_2 -> V_15 - V_76 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
T_3 * V_87 ;
T_3 * V_90 ;
T_3 * V_91 ;
int V_48 ;
int V_93 ;
if ( ! ( V_2 -> V_3 & V_20 ) )
return 1 ;
V_87 = F_13 ( V_11 ) ;
V_48 = ( V_27 << F_70 ( V_11 ) ) - V_2 -> V_26 ;
V_91 = V_87 + V_48 ;
V_93 = V_48 % V_2 -> V_15 ;
if ( ! V_93 )
return 1 ;
V_90 = F_67 ( V_91 - V_93 , V_92 , V_93 ) ;
if ( ! V_90 )
return 1 ;
while ( V_91 > V_90 && V_91 [ - 1 ] == V_92 )
V_91 -- ;
F_63 ( V_2 , V_11 , L_23 , V_90 , V_91 - 1 ) ;
F_44 ( L_17 , V_91 - V_93 , V_93 ) ;
F_65 ( V_2 , L_24 , V_92 , V_91 - V_93 , V_91 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , T_3 V_78 )
{
T_3 * V_5 = V_12 ;
T_3 * V_94 = V_12 + V_2 -> V_21 ;
if ( V_2 -> V_3 & V_19 ) {
if ( ! F_66 ( V_2 , V_11 , V_12 , L_25 ,
V_94 , V_78 , V_2 -> V_24 - V_2 -> V_21 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_20 ) && V_2 -> V_21 < V_2 -> V_24 ) {
F_66 ( V_2 , V_11 , V_5 , L_26 ,
V_94 , V_92 , V_2 -> V_24 - V_2 -> V_21 ) ;
}
}
if ( V_2 -> V_3 & V_20 ) {
if ( V_78 != V_95 && ( V_2 -> V_3 & V_79 ) &&
( ! F_66 ( V_2 , V_11 , V_5 , L_27 , V_5 ,
V_80 , V_2 -> V_21 - 1 ) ||
! F_66 ( V_2 , V_11 , V_5 , L_27 ,
V_5 + V_2 -> V_21 - 1 , V_81 , 1 ) ) )
return 0 ;
F_68 ( V_2 , V_11 , V_5 ) ;
}
if ( ! V_2 -> V_16 && V_78 == V_95 )
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
int V_96 ;
F_32 ( ! F_33 () ) ;
if ( ! F_73 ( V_11 ) ) {
F_63 ( V_2 , V_11 , L_29 ) ;
return 0 ;
}
V_96 = F_23 ( F_70 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_11 -> V_14 > V_96 ) {
F_63 ( V_2 , V_11 , L_30 ,
V_2 -> V_45 , V_11 -> V_14 , V_96 ) ;
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
static int F_74 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_97 )
{
int V_98 = 0 ;
void * V_17 ;
void * V_12 = NULL ;
unsigned long V_99 ;
V_17 = V_11 -> V_41 ;
while ( V_17 && V_98 <= V_11 -> V_14 ) {
if ( V_17 == V_97 )
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
V_98 ++ ;
}
V_99 = F_23 ( F_70 ( V_11 ) , V_2 -> V_15 , V_2 -> V_26 ) ;
if ( V_99 > V_100 )
V_99 = V_100 ;
if ( V_11 -> V_14 != V_99 ) {
F_63 ( V_2 , V_11 , L_34
L_35 , V_11 -> V_14 , V_99 ) ;
V_11 -> V_14 = V_99 ;
F_58 ( V_2 , L_36 ) ;
}
if ( V_11 -> V_24 != V_11 -> V_14 - V_98 ) {
F_63 ( V_2 , V_11 , L_37
L_38 , V_11 -> V_24 , V_11 -> V_14 - V_98 ) ;
V_11 -> V_24 = V_11 -> V_14 - V_98 ;
F_58 ( V_2 , L_39 ) ;
}
return V_97 == NULL ;
}
static void V_55 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_12 ,
int V_53 )
{
if ( V_2 -> V_3 & V_101 ) {
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
V_3 &= V_102 ;
F_76 ( V_3 ) ;
F_77 ( V_3 & V_103 ) ;
return F_78 ( V_2 -> V_21 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_79 ( struct V_1 * V_2 , T_5 V_3 , void * V_12 )
{
V_3 &= V_102 ;
F_80 ( V_2 , V_3 , V_12 , F_22 ( V_2 ) ) ;
F_81 ( V_12 , V_2 -> V_21 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_82 ( struct V_1 * V_2 , void * V_29 )
{
F_83 ( V_29 , V_2 -> V_3 ) ;
#if F_34 ( V_104 ) || F_34 ( V_105 )
{
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_84 ( V_2 , V_29 , V_2 -> V_21 ) ;
F_85 ( V_29 , V_2 -> V_21 ) ;
F_41 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_106 ) )
F_86 ( V_29 , V_2 -> V_21 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_88 ( & V_11 -> V_107 , & V_37 -> V_108 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return;
F_90 ( & V_11 -> V_107 ) ;
}
static inline unsigned long F_91 ( struct V_1 * V_2 , int V_10 )
{
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
return F_92 ( & V_37 -> V_109 ) ;
}
static inline unsigned long F_93 ( struct V_9 * V_37 )
{
return F_92 ( & V_37 -> V_109 ) ;
}
static inline void F_94 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( V_37 ) {
F_95 ( & V_37 -> V_109 ) ;
F_96 ( V_14 , & V_37 -> V_110 ) ;
}
}
static inline void F_97 ( struct V_1 * V_2 , int V_10 , int V_14 )
{
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
F_98 ( & V_37 -> V_109 ) ;
F_99 ( V_14 , & V_37 -> V_110 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 )
{
if ( ! ( V_2 -> V_3 & ( V_23 | V_19 | V_79 ) ) )
return;
F_64 ( V_2 , V_12 , V_111 ) ;
F_51 ( V_2 , V_12 ) ;
}
static T_6 int F_101 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_12 , unsigned long V_18 )
{
if ( ! F_72 ( V_2 , V_11 ) )
goto V_112;
if ( ! F_12 ( V_2 , V_11 , V_12 ) ) {
F_62 ( V_2 , V_11 , V_12 , L_43 ) ;
goto V_112;
}
if ( ! F_71 ( V_2 , V_11 , V_12 , V_111 ) )
goto V_112;
if ( V_2 -> V_3 & V_23 )
F_47 ( V_2 , V_12 , V_70 , V_18 ) ;
V_55 ( V_2 , V_11 , V_12 , 1 ) ;
F_64 ( V_2 , V_12 , V_95 ) ;
return 1 ;
V_112:
if ( F_73 ( V_11 ) ) {
F_58 ( V_2 , L_44 ) ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_41 = NULL ;
}
return 0 ;
}
int T_7 F_102 ( char * V_113 )
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
F_38 ( V_49 L_45
L_46 , * V_113 ) ;
}
}
V_117:
if ( * V_113 == ',' )
V_121 = V_113 + 1 ;
V_116:
return 1 ;
}
static unsigned long F_103 ( unsigned long V_21 ,
unsigned long V_3 , const char * V_45 ,
void (* F_104)( void * ) )
{
if ( V_114 && ( ! V_121 ||
! strncmp ( V_121 , V_45 , strlen ( V_121 ) ) ) )
V_3 |= V_114 ;
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
void * V_12 , T_3 V_78 ) { return 1 ; }
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
struct V_28 V_122 )
{
int V_25 = F_25 ( V_122 ) ;
V_3 |= V_123 ;
if ( V_10 == V_124 )
return F_107 ( V_3 , V_25 ) ;
else
return F_108 ( V_10 , V_3 , V_25 ) ;
}
static struct V_11 * F_109 ( struct V_1 * V_2 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
struct V_28 V_122 = V_2 -> V_122 ;
T_5 V_125 ;
V_3 &= V_102 ;
if ( V_3 & V_103 )
F_110 () ;
V_3 |= V_2 -> V_126 ;
V_125 = ( V_3 | V_127 | V_128 ) & ~ V_129 ;
V_11 = F_106 ( V_125 , V_10 , V_122 ) ;
if ( F_3 ( ! V_11 ) ) {
V_122 = V_2 -> V_130 ;
V_11 = F_106 ( V_3 , V_10 , V_122 ) ;
if ( V_11 )
F_8 ( V_2 , V_131 ) ;
}
if ( V_132 && V_11
&& ! ( V_2 -> V_3 & ( V_133 | V_115 ) ) ) {
int V_134 = 1 << F_25 ( V_122 ) ;
F_111 ( V_11 , F_25 ( V_122 ) , V_3 , V_10 ) ;
if ( V_2 -> F_104 )
F_112 ( V_11 , V_134 ) ;
else
F_113 ( V_11 , V_134 ) ;
}
if ( V_3 & V_103 )
F_114 () ;
if ( ! V_11 )
return NULL ;
V_11 -> V_14 = F_26 ( V_122 ) ;
F_115 ( F_116 ( V_11 ) ,
( V_2 -> V_3 & V_135 ) ?
V_136 : V_137 ,
1 << F_25 ( V_122 ) ) ;
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
void * V_87 ;
void * V_138 ;
void * V_5 ;
int V_25 ;
F_119 ( V_3 & V_139 ) ;
V_11 = F_109 ( V_2 ,
V_3 & ( V_140 | V_141 ) , V_10 ) ;
if ( ! V_11 )
goto V_116;
V_25 = F_70 ( V_11 ) ;
F_94 ( V_2 , F_120 ( V_11 ) , V_11 -> V_14 ) ;
F_121 ( V_2 , V_25 ) ;
V_11 -> V_142 = V_2 ;
F_122 ( V_11 ) ;
if ( V_11 -> V_143 )
F_123 ( V_11 ) ;
V_87 = F_13 ( V_11 ) ;
if ( F_3 ( V_2 -> V_3 & V_20 ) )
memset ( V_87 , V_92 , V_27 << V_25 ) ;
V_138 = V_87 ;
F_124 (p, s, start, page->objects) {
F_117 ( V_2 , V_11 , V_138 ) ;
F_20 ( V_2 , V_138 , V_5 ) ;
V_138 = V_5 ;
}
F_117 ( V_2 , V_11 , V_138 ) ;
F_20 ( V_2 , V_138 , NULL ) ;
V_11 -> V_41 = V_87 ;
V_11 -> V_24 = V_11 -> V_14 ;
V_11 -> V_144 = 1 ;
V_116:
return V_11 ;
}
static void F_125 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
int V_25 = F_70 ( V_11 ) ;
int V_134 = 1 << V_25 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_69 ( V_2 , V_11 ) ;
F_124 (p, s, page_address(page),
page->objects)
F_71 ( V_2 , V_11 , V_5 , V_111 ) ;
}
F_126 ( V_11 , F_70 ( V_11 ) ) ;
F_115 ( F_116 ( V_11 ) ,
( V_2 -> V_3 & V_135 ) ?
V_136 : V_137 ,
- V_134 ) ;
F_127 ( V_11 ) ;
F_128 ( V_11 ) ;
F_129 ( V_2 , V_25 ) ;
F_130 ( V_11 ) ;
if ( V_66 -> V_145 )
V_66 -> V_145 -> V_146 += V_134 ;
F_131 ( V_11 , V_25 ) ;
}
static void F_132 ( struct V_147 * V_148 )
{
struct V_11 * V_11 ;
if ( V_149 )
V_11 = F_133 ( V_148 ) ;
else
V_11 = F_134 ( (struct V_150 * ) V_148 , struct V_11 , V_107 ) ;
F_125 ( V_11 -> V_142 , V_11 ) ;
}
static void F_135 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
if ( F_3 ( V_2 -> V_3 & V_22 ) ) {
struct V_147 * V_151 ;
if ( V_149 ) {
int V_25 = F_70 ( V_11 ) ;
int V_16 = ( V_27 << V_25 ) - V_2 -> V_26 ;
F_32 ( V_2 -> V_26 != sizeof( * V_151 ) ) ;
V_151 = F_13 ( V_11 ) + V_16 ;
} else {
V_151 = ( void * ) & V_11 -> V_107 ;
}
F_136 ( V_151 , F_132 ) ;
} else
F_125 ( V_2 , V_11 ) ;
}
static void F_137 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
F_97 ( V_2 , F_120 ( V_11 ) , V_11 -> V_14 ) ;
F_135 ( V_2 , V_11 ) ;
}
static inline void F_138 ( struct V_9 * V_37 ,
struct V_11 * V_11 , int V_152 )
{
V_37 -> V_153 ++ ;
if ( V_152 == V_154 )
F_139 ( & V_11 -> V_107 , & V_37 -> V_155 ) ;
else
F_88 ( & V_11 -> V_107 , & V_37 -> V_155 ) ;
}
static inline void F_140 ( struct V_9 * V_37 ,
struct V_11 * V_11 )
{
F_90 ( & V_11 -> V_107 ) ;
V_37 -> V_153 -- ;
}
static inline void * F_141 ( struct V_1 * V_2 ,
struct V_9 * V_37 , struct V_11 * V_11 ,
int V_156 )
{
void * V_41 ;
unsigned long V_42 ;
struct V_11 V_157 ;
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_157 . V_42 = V_42 ;
if ( V_156 ) {
V_157 . V_24 = V_11 -> V_14 ;
V_157 . V_41 = NULL ;
} else {
V_157 . V_41 = V_41 ;
}
F_32 ( V_157 . V_144 ) ;
V_157 . V_144 = 1 ;
if ( ! F_31 ( V_2 , V_11 ,
V_41 , V_42 ,
V_157 . V_41 , V_157 . V_42 ,
L_47 ) )
return NULL ;
F_140 ( V_37 , V_11 ) ;
F_142 ( ! V_41 ) ;
return V_41 ;
}
static void * F_143 ( struct V_1 * V_2 , struct V_9 * V_37 ,
struct V_158 * V_159 , T_5 V_3 )
{
struct V_11 * V_11 , * V_160 ;
void * V_12 = NULL ;
if ( ! V_37 || ! V_37 -> V_153 )
return NULL ;
F_144 ( & V_37 -> V_161 ) ;
F_145 (page, page2, &n->partial, lru) {
void * V_71 ;
int V_162 ;
if ( ! F_146 ( V_11 , V_3 ) )
continue;
V_71 = F_141 ( V_2 , V_37 , V_11 , V_12 == NULL ) ;
if ( ! V_71 )
break;
if ( ! V_12 ) {
V_159 -> V_11 = V_11 ;
F_8 ( V_2 , V_163 ) ;
V_12 = V_71 ;
V_162 = V_11 -> V_14 - V_11 -> V_24 ;
} else {
V_162 = F_147 ( V_2 , V_11 , 0 ) ;
F_8 ( V_2 , V_164 ) ;
}
if ( F_1 ( V_2 ) || V_162 > V_2 -> V_165 / 2 )
break;
}
F_148 ( & V_37 -> V_161 ) ;
return V_12 ;
}
static void * F_149 ( struct V_1 * V_2 , T_5 V_3 ,
struct V_158 * V_159 )
{
#ifdef F_150
struct V_166 * V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_169 ;
enum V_170 V_171 = F_151 ( V_3 ) ;
void * V_12 ;
unsigned int V_172 ;
if ( ! V_2 -> V_173 ||
F_152 () % 1024 > V_2 -> V_173 )
return NULL ;
do {
V_172 = F_153 () ;
V_166 = F_154 ( F_155 () , V_3 ) ;
F_156 (zone, z, zonelist, high_zoneidx) {
struct V_9 * V_37 ;
V_37 = F_11 ( V_2 , F_157 ( V_169 ) ) ;
if ( V_37 && F_158 ( V_169 , V_3 ) &&
V_37 -> V_153 > V_2 -> V_174 ) {
V_12 = F_143 ( V_2 , V_37 , V_159 , V_3 ) ;
if ( V_12 ) {
F_159 ( V_172 ) ;
return V_12 ;
}
}
}
} while ( ! F_159 ( V_172 ) );
#endif
return NULL ;
}
static void * F_160 ( struct V_1 * V_2 , T_5 V_3 , int V_10 ,
struct V_158 * V_159 )
{
void * V_12 ;
int V_175 = ( V_10 == V_124 ) ? F_161 () : V_10 ;
V_12 = F_143 ( V_2 , F_11 ( V_2 , V_175 ) , V_159 , V_3 ) ;
if ( V_12 || V_10 != V_124 )
return V_12 ;
return F_149 ( V_2 , V_3 , V_159 ) ;
}
static inline unsigned long F_162 ( unsigned long V_176 )
{
return V_176 + V_177 ;
}
static inline unsigned int F_163 ( unsigned long V_176 )
{
return V_176 % V_177 ;
}
static inline unsigned long F_164 ( unsigned long V_176 )
{
return V_176 / V_177 ;
}
static inline unsigned int F_165 ( int V_64 )
{
return V_64 ;
}
static inline void F_166 ( const char * V_37 ,
const struct V_1 * V_2 , unsigned long V_176 )
{
#ifdef F_37
unsigned long V_178 = F_167 ( V_2 -> V_8 -> V_176 ) ;
F_38 ( V_44 L_48 , V_37 , V_2 -> V_45 ) ;
#ifdef F_168
if ( F_163 ( V_176 ) != F_163 ( V_178 ) )
F_38 ( L_49 ,
F_163 ( V_176 ) , F_163 ( V_178 ) ) ;
else
#endif
if ( F_164 ( V_176 ) != F_164 ( V_178 ) )
F_38 ( L_50 ,
F_164 ( V_176 ) , F_164 ( V_178 ) ) ;
else
F_38 ( L_51 ,
V_178 , V_176 , F_162 ( V_176 ) ) ;
#endif
F_8 ( V_2 , V_179 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
int V_64 ;
F_170 (cpu)
F_171 ( V_2 -> V_8 , V_64 ) -> V_176 = F_165 ( V_64 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_11 * V_11 , void * V_41 )
{
enum T_8 { V_180 , V_181 , V_182 , V_183 };
struct V_9 * V_37 = F_11 ( V_2 , F_120 ( V_11 ) ) ;
int V_184 = 0 ;
enum T_8 V_185 = V_180 , V_186 = V_180 ;
void * V_187 ;
int V_152 = V_188 ;
struct V_11 V_157 ;
struct V_11 V_189 ;
if ( V_11 -> V_41 ) {
F_8 ( V_2 , V_190 ) ;
V_152 = V_154 ;
}
while ( V_41 && ( V_187 = F_14 ( V_2 , V_41 ) ) ) {
void * V_191 ;
unsigned long V_42 ;
do {
V_191 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_20 ( V_2 , V_41 , V_191 ) ;
V_157 . V_42 = V_42 ;
V_157 . V_24 -- ;
F_32 ( ! V_157 . V_144 ) ;
} while ( ! F_31 ( V_2 , V_11 ,
V_191 , V_42 ,
V_41 , V_157 . V_42 ,
L_52 ) );
V_41 = V_187 ;
}
V_192:
V_189 . V_41 = V_11 -> V_41 ;
V_189 . V_42 = V_11 -> V_42 ;
F_32 ( ! V_189 . V_144 ) ;
V_157 . V_42 = V_189 . V_42 ;
if ( V_41 ) {
V_157 . V_24 -- ;
F_20 ( V_2 , V_41 , V_189 . V_41 ) ;
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
F_144 ( & V_37 -> V_161 ) ;
}
} else {
V_186 = V_182 ;
if ( F_1 ( V_2 ) && ! V_184 ) {
V_184 = 1 ;
F_144 ( & V_37 -> V_161 ) ;
}
}
if ( V_185 != V_186 ) {
if ( V_185 == V_181 )
F_140 ( V_37 , V_11 ) ;
else if ( V_185 == V_182 )
F_89 ( V_2 , V_11 ) ;
if ( V_186 == V_181 ) {
F_138 ( V_37 , V_11 , V_152 ) ;
F_8 ( V_2 , V_152 ) ;
} else if ( V_186 == V_182 ) {
F_8 ( V_2 , V_193 ) ;
F_87 ( V_2 , V_37 , V_11 ) ;
}
}
V_185 = V_186 ;
if ( ! F_31 ( V_2 , V_11 ,
V_189 . V_41 , V_189 . V_42 ,
V_157 . V_41 , V_157 . V_42 ,
L_53 ) )
goto V_192;
if ( V_184 )
F_148 ( & V_37 -> V_161 ) ;
if ( V_186 == V_183 ) {
F_8 ( V_2 , V_194 ) ;
F_137 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_195 ) ;
}
}
static void F_173 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
struct V_9 * V_37 = NULL , * V_196 = NULL ;
struct V_11 * V_11 , * V_197 = NULL ;
while ( ( V_11 = V_159 -> V_155 ) ) {
struct V_11 V_157 ;
struct V_11 V_189 ;
V_159 -> V_155 = V_11 -> V_198 ;
V_196 = F_11 ( V_2 , F_120 ( V_11 ) ) ;
if ( V_37 != V_196 ) {
if ( V_37 )
F_148 ( & V_37 -> V_161 ) ;
V_37 = V_196 ;
F_144 ( & V_37 -> V_161 ) ;
}
do {
V_189 . V_41 = V_11 -> V_41 ;
V_189 . V_42 = V_11 -> V_42 ;
F_32 ( ! V_189 . V_144 ) ;
V_157 . V_42 = V_189 . V_42 ;
V_157 . V_41 = V_189 . V_41 ;
V_157 . V_144 = 0 ;
} while ( ! F_31 ( V_2 , V_11 ,
V_189 . V_41 , V_189 . V_42 ,
V_157 . V_41 , V_157 . V_42 ,
L_53 ) );
if ( F_3 ( ! V_157 . V_24 && V_37 -> V_153 > V_2 -> V_174 ) ) {
V_11 -> V_198 = V_197 ;
V_197 = V_11 ;
} else {
F_138 ( V_37 , V_11 , V_154 ) ;
F_8 ( V_2 , V_199 ) ;
}
}
if ( V_37 )
F_148 ( & V_37 -> V_161 ) ;
while ( V_197 ) {
V_11 = V_197 ;
V_197 = V_197 -> V_198 ;
F_8 ( V_2 , V_194 ) ;
F_137 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_195 ) ;
}
}
static int F_147 ( struct V_1 * V_2 , struct V_11 * V_11 , int V_200 )
{
struct V_11 * V_201 ;
int V_134 ;
int V_202 ;
do {
V_134 = 0 ;
V_202 = 0 ;
V_201 = F_174 ( V_2 -> V_8 -> V_155 ) ;
if ( V_201 ) {
V_202 = V_201 -> V_202 ;
V_134 = V_201 -> V_134 ;
if ( V_200 && V_202 > V_2 -> V_165 ) {
unsigned long V_3 ;
F_40 ( V_3 ) ;
F_173 ( V_2 , F_175 ( V_2 -> V_8 ) ) ;
F_41 ( V_3 ) ;
V_201 = NULL ;
V_202 = 0 ;
V_134 = 0 ;
F_8 ( V_2 , V_203 ) ;
}
}
V_134 ++ ;
V_202 += V_11 -> V_14 - V_11 -> V_24 ;
V_11 -> V_134 = V_134 ;
V_11 -> V_202 = V_202 ;
V_11 -> V_198 = V_201 ;
} while ( F_176 ( V_2 -> V_8 -> V_155 , V_201 , V_11 ) != V_201 );
return V_202 ;
}
static inline void F_177 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
F_8 ( V_2 , V_204 ) ;
F_172 ( V_2 , V_159 -> V_11 , V_159 -> V_41 ) ;
V_159 -> V_176 = F_162 ( V_159 -> V_176 ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
}
static inline void F_178 ( struct V_1 * V_2 , int V_64 )
{
struct V_158 * V_159 = F_171 ( V_2 -> V_8 , V_64 ) ;
if ( F_179 ( V_159 ) ) {
if ( V_159 -> V_11 )
F_177 ( V_2 , V_159 ) ;
F_173 ( V_2 , V_159 ) ;
}
}
static void F_180 ( void * V_205 )
{
struct V_1 * V_2 = V_205 ;
F_178 ( V_2 , F_50 () ) ;
}
static bool F_181 ( int V_64 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
struct V_158 * V_159 = F_171 ( V_2 -> V_8 , V_64 ) ;
return V_159 -> V_11 || V_159 -> V_155 ;
}
static void F_182 ( struct V_1 * V_2 )
{
F_183 ( F_181 , F_180 , V_2 , 1 , V_207 ) ;
}
static inline int F_184 ( struct V_11 * V_11 , int V_10 )
{
#ifdef F_150
if ( V_10 != V_124 && F_120 ( V_11 ) != V_10 )
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
F_188 ( & V_37 -> V_161 , V_3 ) ;
F_189 (page, &n->partial, lru)
V_29 += F_187 ( V_11 ) ;
F_190 ( & V_37 -> V_161 , V_3 ) ;
return V_29 ;
}
static inline unsigned long F_191 ( struct V_9 * V_37 )
{
#ifdef F_2
return F_92 ( & V_37 -> V_110 ) ;
#else
return 0 ;
#endif
}
static T_6 void
F_192 ( struct V_1 * V_2 , T_5 V_208 , int V_209 )
{
int V_10 ;
F_38 ( V_210
L_54 ,
V_209 , V_208 ) ;
F_38 ( V_210 L_55
L_56 , V_2 -> V_45 , V_2 -> V_21 ,
V_2 -> V_15 , F_25 ( V_2 -> V_122 ) , F_25 ( V_2 -> V_130 ) ) ;
if ( F_25 ( V_2 -> V_130 ) > F_193 ( V_2 -> V_21 ) )
F_38 ( V_210 L_57
L_58 , V_2 -> V_45 ) ;
F_194 (node) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
unsigned long V_109 ;
unsigned long V_211 ;
unsigned long V_212 ;
if ( ! V_37 )
continue;
V_212 = F_186 ( V_37 , F_185 ) ;
V_109 = F_93 ( V_37 ) ;
V_211 = F_191 ( V_37 ) ;
F_38 ( V_210
L_59 ,
V_10 , V_109 , V_211 , V_212 ) ;
}
}
static inline void * F_195 ( struct V_1 * V_2 , T_5 V_3 ,
int V_10 , struct V_158 * * V_213 )
{
void * V_41 ;
struct V_158 * V_159 = * V_213 ;
struct V_11 * V_11 ;
V_41 = F_160 ( V_2 , V_3 , V_10 , V_159 ) ;
if ( V_41 )
return V_41 ;
V_11 = F_118 ( V_2 , V_3 , V_10 ) ;
if ( V_11 ) {
V_159 = F_196 ( V_2 -> V_8 ) ;
if ( V_159 -> V_11 )
F_177 ( V_2 , V_159 ) ;
V_41 = V_11 -> V_41 ;
V_11 -> V_41 = NULL ;
F_8 ( V_2 , V_214 ) ;
V_159 -> V_11 = V_11 ;
* V_213 = V_159 ;
} else
V_41 = NULL ;
return V_41 ;
}
static inline bool F_146 ( struct V_11 * V_11 , T_5 V_208 )
{
if ( F_3 ( F_197 ( V_11 ) ) )
return F_198 ( V_208 ) ;
return true ;
}
static inline void * F_199 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
struct V_11 V_157 ;
unsigned long V_42 ;
void * V_41 ;
do {
V_41 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
V_157 . V_42 = V_42 ;
F_32 ( ! V_157 . V_144 ) ;
V_157 . V_24 = V_11 -> V_14 ;
V_157 . V_144 = V_41 != NULL ;
} while ( ! F_31 ( V_2 , V_11 ,
V_41 , V_42 ,
NULL , V_157 . V_42 ,
L_60 ) );
return V_41 ;
}
static void * F_200 ( struct V_1 * V_2 , T_5 V_208 , int V_10 ,
unsigned long V_18 , struct V_158 * V_159 )
{
void * V_41 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_40 ( V_3 ) ;
#ifdef F_168
V_159 = F_175 ( V_2 -> V_8 ) ;
#endif
V_11 = V_159 -> V_11 ;
if ( ! V_11 )
goto F_118;
V_192:
if ( F_3 ( ! F_184 ( V_11 , V_10 ) ) ) {
F_8 ( V_2 , V_215 ) ;
F_172 ( V_2 , V_11 , V_159 -> V_41 ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
goto F_118;
}
if ( F_3 ( ! F_146 ( V_11 , V_208 ) ) ) {
F_172 ( V_2 , V_11 , V_159 -> V_41 ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
goto F_118;
}
V_41 = V_159 -> V_41 ;
if ( V_41 )
goto V_216;
F_8 ( V_2 , V_217 ) ;
V_41 = F_199 ( V_2 , V_11 ) ;
if ( ! V_41 ) {
V_159 -> V_11 = NULL ;
F_8 ( V_2 , V_218 ) ;
goto F_118;
}
F_8 ( V_2 , V_219 ) ;
V_216:
F_32 ( ! V_159 -> V_11 -> V_144 ) ;
V_159 -> V_41 = F_14 ( V_2 , V_41 ) ;
V_159 -> V_176 = F_162 ( V_159 -> V_176 ) ;
F_41 ( V_3 ) ;
return V_41 ;
F_118:
if ( V_159 -> V_155 ) {
V_11 = V_159 -> V_11 = V_159 -> V_155 ;
V_159 -> V_155 = V_11 -> V_198 ;
F_8 ( V_2 , V_220 ) ;
V_159 -> V_41 = NULL ;
goto V_192;
}
V_41 = F_195 ( V_2 , V_208 , V_10 , & V_159 ) ;
if ( F_3 ( ! V_41 ) ) {
if ( ! ( V_208 & V_127 ) && F_201 () )
F_192 ( V_2 , V_208 , V_10 ) ;
F_41 ( V_3 ) ;
return NULL ;
}
V_11 = V_159 -> V_11 ;
if ( F_179 ( ! F_1 ( V_2 ) && F_146 ( V_11 , V_208 ) ) )
goto V_216;
if ( F_1 ( V_2 ) && ! F_101 ( V_2 , V_11 , V_41 , V_18 ) )
goto F_118;
F_172 ( V_2 , V_11 , F_14 ( V_2 , V_41 ) ) ;
V_159 -> V_11 = NULL ;
V_159 -> V_41 = NULL ;
F_41 ( V_3 ) ;
return V_41 ;
}
static T_2 void * F_202 ( struct V_1 * V_2 ,
T_5 V_208 , int V_10 , unsigned long V_18 )
{
void * * V_12 ;
struct V_158 * V_159 ;
struct V_11 * V_11 ;
unsigned long V_176 ;
if ( F_75 ( V_2 , V_208 ) )
return NULL ;
V_2 = F_203 ( V_2 , V_208 ) ;
V_192:
V_159 = F_196 ( V_2 -> V_8 ) ;
V_176 = V_159 -> V_176 ;
F_204 () ;
V_12 = V_159 -> V_41 ;
V_11 = V_159 -> V_11 ;
if ( F_3 ( ! V_12 || ! F_184 ( V_11 , V_10 ) ) )
V_12 = F_200 ( V_2 , V_208 , V_10 , V_18 , V_159 ) ;
else {
void * V_221 = F_17 ( V_2 , V_12 ) ;
if ( F_3 ( ! F_205 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_176 ,
V_12 , V_176 ,
V_221 , F_162 ( V_176 ) ) ) ) {
F_166 ( L_61 , V_2 , V_176 ) ;
goto V_192;
}
F_15 ( V_2 , V_221 ) ;
F_8 ( V_2 , V_222 ) ;
}
if ( F_3 ( V_208 & V_223 ) && V_12 )
memset ( V_12 , 0 , V_2 -> V_21 ) ;
F_79 ( V_2 , V_208 , V_12 ) ;
return V_12 ;
}
static T_2 void * F_206 ( struct V_1 * V_2 ,
T_5 V_208 , unsigned long V_18 )
{
return F_202 ( V_2 , V_208 , V_124 , V_18 ) ;
}
void * F_207 ( struct V_1 * V_2 , T_5 V_208 )
{
void * V_224 = F_206 ( V_2 , V_208 , V_225 ) ;
F_208 ( V_225 , V_224 , V_2 -> V_21 , V_2 -> V_15 , V_208 ) ;
return V_224 ;
}
void * F_209 ( struct V_1 * V_2 , T_5 V_208 , T_1 V_15 )
{
void * V_224 = F_206 ( V_2 , V_208 , V_225 ) ;
F_210 ( V_225 , V_224 , V_15 , V_2 -> V_15 , V_208 ) ;
return V_224 ;
}
void * F_211 ( T_1 V_15 , T_5 V_3 , unsigned int V_25 )
{
void * V_224 = F_212 ( V_15 , V_3 , V_25 ) ;
F_210 ( V_225 , V_224 , V_15 , V_27 << V_25 , V_3 ) ;
return V_224 ;
}
void * F_213 ( struct V_1 * V_2 , T_5 V_208 , int V_10 )
{
void * V_224 = F_202 ( V_2 , V_208 , V_10 , V_225 ) ;
F_214 ( V_225 , V_224 ,
V_2 -> V_21 , V_2 -> V_15 , V_208 , V_10 ) ;
return V_224 ;
}
void * F_215 ( struct V_1 * V_2 ,
T_5 V_208 ,
int V_10 , T_1 V_15 )
{
void * V_224 = F_202 ( V_2 , V_208 , V_10 , V_225 ) ;
F_216 ( V_225 , V_224 ,
V_15 , V_2 -> V_15 , V_208 , V_10 ) ;
return V_224 ;
}
static void F_217 ( struct V_1 * V_2 , struct V_11 * V_11 ,
void * V_29 , unsigned long V_18 )
{
void * V_191 ;
void * * V_12 = ( void * ) V_29 ;
int V_226 ;
struct V_11 V_157 ;
unsigned long V_42 ;
struct V_9 * V_37 = NULL ;
unsigned long V_227 ( V_3 ) ;
F_8 ( V_2 , V_228 ) ;
if ( F_1 ( V_2 ) &&
! ( V_37 = F_105 ( V_2 , V_11 , V_29 , V_18 , & V_3 ) ) )
return;
do {
if ( F_3 ( V_37 ) ) {
F_190 ( & V_37 -> V_161 , V_3 ) ;
V_37 = NULL ;
}
V_191 = V_11 -> V_41 ;
V_42 = V_11 -> V_42 ;
F_20 ( V_2 , V_12 , V_191 ) ;
V_157 . V_42 = V_42 ;
V_226 = V_157 . V_144 ;
V_157 . V_24 -- ;
if ( ( ! V_157 . V_24 || ! V_191 ) && ! V_226 ) {
if ( ! F_1 ( V_2 ) && ! V_191 )
V_157 . V_144 = 1 ;
else {
V_37 = F_11 ( V_2 , F_120 ( V_11 ) ) ;
F_188 ( & V_37 -> V_161 , V_3 ) ;
}
}
} while ( ! F_39 ( V_2 , V_11 ,
V_191 , V_42 ,
V_12 , V_157 . V_42 ,
L_62 ) );
if ( F_179 ( ! V_37 ) ) {
if ( V_157 . V_144 && ! V_226 ) {
F_147 ( V_2 , V_11 , 1 ) ;
F_8 ( V_2 , V_229 ) ;
}
if ( V_226 )
F_8 ( V_2 , V_230 ) ;
return;
}
if ( F_3 ( ! V_157 . V_24 && V_37 -> V_153 > V_2 -> V_174 ) )
goto V_231;
if ( F_1 ( V_2 ) && F_3 ( ! V_191 ) ) {
F_89 ( V_2 , V_11 ) ;
F_138 ( V_37 , V_11 , V_154 ) ;
F_8 ( V_2 , V_199 ) ;
}
F_190 ( & V_37 -> V_161 , V_3 ) ;
return;
V_231:
if ( V_191 ) {
F_140 ( V_37 , V_11 ) ;
F_8 ( V_2 , V_232 ) ;
} else
F_89 ( V_2 , V_11 ) ;
F_190 ( & V_37 -> V_161 , V_3 ) ;
F_8 ( V_2 , V_195 ) ;
F_137 ( V_2 , V_11 ) ;
}
static T_2 void F_218 ( struct V_1 * V_2 ,
struct V_11 * V_11 , void * V_29 , unsigned long V_18 )
{
void * * V_12 = ( void * ) V_29 ;
struct V_158 * V_159 ;
unsigned long V_176 ;
F_82 ( V_2 , V_29 ) ;
V_192:
V_159 = F_196 ( V_2 -> V_8 ) ;
V_176 = V_159 -> V_176 ;
F_204 () ;
if ( F_179 ( V_11 == V_159 -> V_11 ) ) {
F_20 ( V_2 , V_12 , V_159 -> V_41 ) ;
if ( F_3 ( ! F_205 (
V_2 -> V_8 -> V_41 , V_2 -> V_8 -> V_176 ,
V_159 -> V_41 , V_176 ,
V_12 , F_162 ( V_176 ) ) ) ) {
F_166 ( L_63 , V_2 , V_176 ) ;
goto V_192;
}
F_8 ( V_2 , V_233 ) ;
} else
F_217 ( V_2 , V_11 , V_29 , V_18 ) ;
}
void F_219 ( struct V_1 * V_2 , void * V_29 )
{
V_2 = F_220 ( V_2 , V_29 ) ;
if ( ! V_2 )
return;
F_218 ( V_2 , F_133 ( V_29 ) , V_29 , V_225 ) ;
F_221 ( V_225 , V_29 ) ;
}
static inline int F_222 ( int V_15 , int V_234 ,
int V_235 , int V_236 , int V_26 )
{
int V_25 ;
int V_237 ;
int V_238 = V_239 ;
if ( F_23 ( V_238 , V_15 , V_26 ) > V_100 )
return F_193 ( V_15 * V_100 ) - 1 ;
for ( V_25 = F_223 ( V_238 ,
F_224 ( V_234 * V_15 - 1 ) - V_240 ) ;
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
static inline int F_225 ( int V_15 , int V_26 )
{
int V_25 ;
int V_234 ;
int V_242 ;
int V_99 ;
V_234 = V_243 ;
if ( ! V_234 )
V_234 = 4 * ( F_224 ( V_244 ) + 1 ) ;
V_99 = F_23 ( V_245 , V_15 , V_26 ) ;
V_234 = V_130 ( V_234 , V_99 ) ;
while ( V_234 > 1 ) {
V_242 = 16 ;
while ( V_242 >= 4 ) {
V_25 = F_222 ( V_15 , V_234 ,
V_245 , V_242 , V_26 ) ;
if ( V_25 <= V_245 )
return V_25 ;
V_242 /= 2 ;
}
V_234 -- ;
}
V_25 = F_222 ( V_15 , 1 , V_245 , 1 , V_26 ) ;
if ( V_25 <= V_245 )
return V_25 ;
V_25 = F_222 ( V_15 , 1 , V_246 , 1 , V_26 ) ;
if ( V_25 < V_246 )
return V_25 ;
return - V_247 ;
}
static void
F_226 ( struct V_9 * V_37 )
{
V_37 -> V_153 = 0 ;
F_227 ( & V_37 -> V_161 ) ;
F_228 ( & V_37 -> V_155 ) ;
#ifdef F_2
F_229 ( & V_37 -> V_109 , 0 ) ;
F_229 ( & V_37 -> V_110 , 0 ) ;
F_228 ( & V_37 -> V_108 ) ;
#endif
}
static inline int F_230 ( struct V_1 * V_2 )
{
F_231 ( V_248 <
V_249 * sizeof( struct V_158 ) ) ;
V_2 -> V_8 = F_232 ( sizeof( struct V_158 ) ,
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
V_11 = F_118 ( V_9 , V_250 , V_10 ) ;
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
V_11 -> V_144 = 0 ;
V_9 -> V_10 [ V_10 ] = V_37 ;
#ifdef F_2
F_64 ( V_9 , V_37 , V_95 ) ;
F_51 ( V_9 , V_37 ) ;
#endif
F_226 ( V_37 ) ;
F_94 ( V_9 , V_10 , V_11 -> V_14 ) ;
F_138 ( V_37 , V_11 , V_188 ) ;
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
if ( V_251 == V_252 ) {
F_233 ( V_10 ) ;
continue;
}
V_37 = F_213 ( V_9 ,
V_253 , V_10 ) ;
if ( ! V_37 ) {
F_234 ( V_2 ) ;
return 0 ;
}
V_2 -> V_10 [ V_10 ] = V_37 ;
F_226 ( V_37 ) ;
}
return 1 ;
}
static void F_237 ( struct V_1 * V_2 , unsigned long V_130 )
{
if ( V_130 < V_254 )
V_130 = V_254 ;
else if ( V_130 > V_255 )
V_130 = V_255 ;
V_2 -> V_174 = V_130 ;
}
static int F_238 ( struct V_1 * V_2 , int V_256 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_15 = V_2 -> V_21 ;
int V_25 ;
V_15 = F_239 ( V_15 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_20 ) && ! ( V_3 & V_22 ) &&
! V_2 -> F_104 )
V_2 -> V_3 |= V_79 ;
else
V_2 -> V_3 &= ~ V_79 ;
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
V_15 = F_239 ( V_15 , V_2 -> V_257 ) ;
V_2 -> V_15 = V_15 ;
if ( V_256 >= 0 )
V_25 = V_256 ;
else
V_25 = F_225 ( V_15 , V_2 -> V_26 ) ;
if ( V_25 < 0 )
return 0 ;
V_2 -> V_126 = 0 ;
if ( V_25 )
V_2 -> V_126 |= V_258 ;
if ( V_2 -> V_3 & V_259 )
V_2 -> V_126 |= V_260 ;
if ( V_2 -> V_3 & V_135 )
V_2 -> V_126 |= V_261 ;
V_2 -> V_122 = F_24 ( V_25 , V_15 , V_2 -> V_26 ) ;
V_2 -> V_130 = F_24 ( F_193 ( V_15 ) , V_15 , V_2 -> V_26 ) ;
if ( F_26 ( V_2 -> V_122 ) > F_26 ( V_2 -> F_223 ) )
V_2 -> F_223 = V_2 -> V_122 ;
return ! ! F_26 ( V_2 -> V_122 ) ;
}
static int F_240 ( struct V_1 * V_2 , unsigned long V_3 )
{
V_2 -> V_3 = F_103 ( V_2 -> V_15 , V_3 , V_2 -> V_45 , V_2 -> F_104 ) ;
V_2 -> V_26 = 0 ;
if ( V_149 && ( V_2 -> V_3 & V_22 ) )
V_2 -> V_26 = sizeof( struct V_147 ) ;
if ( ! F_238 ( V_2 , - 1 ) )
goto error;
if ( V_118 ) {
if ( F_193 ( V_2 -> V_15 ) > F_193 ( V_2 -> V_21 ) ) {
V_2 -> V_3 &= ~ V_262 ;
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
V_2 -> V_165 = 0 ;
else if ( V_2 -> V_15 >= V_27 )
V_2 -> V_165 = 2 ;
else if ( V_2 -> V_15 >= 1024 )
V_2 -> V_165 = 6 ;
else if ( V_2 -> V_15 >= 256 )
V_2 -> V_165 = 13 ;
else
V_2 -> V_165 = 30 ;
#ifdef F_150
V_2 -> V_173 = 1000 ;
#endif
if ( ! F_236 ( V_2 ) )
goto error;
if ( F_230 ( V_2 ) )
return 0 ;
F_234 ( V_2 ) ;
error:
if ( V_3 & V_263 )
F_243 ( L_68
L_69 ,
V_2 -> V_45 , ( unsigned long ) V_2 -> V_15 , V_2 -> V_15 , F_25 ( V_2 -> V_122 ) ,
V_2 -> V_16 , V_3 ) ;
return - V_264 ;
}
static void F_244 ( struct V_1 * V_2 , struct V_11 * V_11 ,
const char * V_47 )
{
#ifdef F_2
void * V_18 = F_13 ( V_11 ) ;
void * V_5 ;
unsigned long * V_46 = F_245 ( F_246 ( V_11 -> V_14 ) *
sizeof( long ) , V_207 ) ;
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
struct V_11 * V_11 , * V_148 ;
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
if ( V_37 -> V_153 || F_91 ( V_2 , V_10 ) )
return 1 ;
}
F_251 ( V_2 -> V_8 ) ;
F_234 ( V_2 ) ;
return 0 ;
}
int F_252 ( struct V_1 * V_2 )
{
int V_265 = F_250 ( V_2 ) ;
if ( ! V_265 ) {
F_253 ( & V_266 ) ;
F_6 ( V_2 ) ;
F_254 ( & V_266 ) ;
}
return V_265 ;
}
static int T_7 F_255 ( char * V_113 )
{
F_256 ( & V_113 , & V_239 ) ;
return 1 ;
}
static int T_7 F_257 ( char * V_113 )
{
F_256 ( & V_113 , & V_245 ) ;
V_245 = V_130 ( V_245 , V_246 - 1 ) ;
return 1 ;
}
static int T_7 F_258 ( char * V_113 )
{
F_256 ( & V_113 , & V_243 ) ;
return 1 ;
}
static int T_7 F_259 ( char * V_113 )
{
V_267 = 1 ;
return 1 ;
}
static inline int F_260 ( T_1 V_89 )
{
return ( V_89 - 1 ) / 8 ;
}
static struct V_1 * F_261 ( T_1 V_15 , T_5 V_3 )
{
int V_268 ;
if ( V_15 <= 192 ) {
if ( ! V_15 )
return V_269 ;
V_268 = V_270 [ F_260 ( V_15 ) ] ;
} else
V_268 = F_224 ( V_15 - 1 ) ;
#ifdef F_262
if ( F_3 ( ( V_3 & V_260 ) ) )
return V_271 [ V_268 ] ;
#endif
return V_272 [ V_268 ] ;
}
void * F_263 ( T_1 V_15 , T_5 V_3 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_273 ) )
return F_264 ( V_15 , V_3 ) ;
V_2 = F_261 ( V_15 , V_3 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_224 = F_206 ( V_2 , V_3 , V_225 ) ;
F_210 ( V_225 , V_224 , V_15 , V_2 -> V_15 , V_3 ) ;
return V_224 ;
}
static void * F_266 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_11 * V_11 ;
void * V_274 = NULL ;
V_3 |= V_258 | V_123 | V_275 ;
V_11 = F_267 ( V_10 , V_3 , F_193 ( V_15 ) ) ;
if ( V_11 )
V_274 = F_13 ( V_11 ) ;
F_268 ( V_274 , V_15 , 1 , V_3 ) ;
return V_274 ;
}
void * F_269 ( T_1 V_15 , T_5 V_3 , int V_10 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_273 ) ) {
V_224 = F_266 ( V_15 , V_3 , V_10 ) ;
F_216 ( V_225 , V_224 ,
V_15 , V_27 << F_193 ( V_15 ) ,
V_3 , V_10 ) ;
return V_224 ;
}
V_2 = F_261 ( V_15 , V_3 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_224 = F_202 ( V_2 , V_3 , V_10 , V_225 ) ;
F_216 ( V_225 , V_224 , V_15 , V_2 -> V_15 , V_3 , V_10 ) ;
return V_224 ;
}
T_1 F_270 ( const void * V_12 )
{
struct V_11 * V_11 ;
if ( F_3 ( V_12 == V_269 ) )
return 0 ;
V_11 = F_133 ( V_12 ) ;
if ( F_3 ( ! F_73 ( V_11 ) ) ) {
F_142 ( ! F_271 ( V_11 ) ) ;
return V_27 << F_70 ( V_11 ) ;
}
return F_22 ( V_11 -> V_142 ) ;
}
bool F_272 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
unsigned long V_3 ;
bool V_276 ;
if ( F_3 ( F_265 ( V_29 ) ) )
return false ;
F_40 ( V_3 ) ;
V_11 = F_133 ( V_29 ) ;
if ( F_3 ( ! F_73 ( V_11 ) ) ) {
V_276 = true ;
goto V_277;
}
F_27 ( V_11 ) ;
if ( F_74 ( V_11 -> V_142 , V_11 , V_12 ) ) {
F_62 ( V_11 -> V_142 , V_11 , V_12 , L_72 ) ;
V_276 = false ;
} else {
V_276 = true ;
}
F_29 ( V_11 ) ;
V_277:
F_41 ( V_3 ) ;
return V_276 ;
}
void F_248 ( const void * V_29 )
{
struct V_11 * V_11 ;
void * V_12 = ( void * ) V_29 ;
F_273 ( V_225 , V_29 ) ;
if ( F_3 ( F_265 ( V_29 ) ) )
return;
V_11 = F_133 ( V_29 ) ;
if ( F_3 ( ! F_73 ( V_11 ) ) ) {
F_119 ( ! F_271 ( V_11 ) ) ;
F_274 ( V_29 ) ;
F_131 ( V_11 , F_70 ( V_11 ) ) ;
return;
}
F_218 ( V_11 -> V_142 , V_11 , V_12 , V_225 ) ;
}
int F_275 ( struct V_1 * V_2 )
{
int V_10 ;
int V_56 ;
struct V_9 * V_37 ;
struct V_11 * V_11 ;
struct V_11 * V_71 ;
int V_14 = F_26 ( V_2 -> F_223 ) ;
struct V_150 * V_278 =
F_276 ( sizeof( struct V_150 ) * V_14 , V_253 ) ;
unsigned long V_3 ;
if ( ! V_278 )
return - V_279 ;
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
V_37 = F_11 ( V_2 , V_10 ) ;
if ( ! V_37 -> V_153 )
continue;
for ( V_56 = 0 ; V_56 < V_14 ; V_56 ++ )
F_228 ( V_278 + V_56 ) ;
F_188 ( & V_37 -> V_161 , V_3 ) ;
F_145 (page, t, &n->partial, lru) {
F_277 ( & V_11 -> V_107 , V_278 + V_11 -> V_24 ) ;
if ( ! V_11 -> V_24 )
V_37 -> V_153 -- ;
}
for ( V_56 = V_14 - 1 ; V_56 > 0 ; V_56 -- )
F_278 ( V_278 + V_56 , V_37 -> V_155 . V_280 ) ;
F_190 ( & V_37 -> V_161 , V_3 ) ;
F_145 (page, t, slabs_by_inuse, lru)
F_137 ( V_2 , V_11 ) ;
}
F_248 ( V_278 ) ;
return 0 ;
}
static int F_279 ( void * V_281 )
{
struct V_1 * V_2 ;
F_254 ( & V_266 ) ;
F_189 (s, &slab_caches, list)
F_275 ( V_2 ) ;
F_253 ( & V_266 ) ;
return 0 ;
}
static void F_280 ( void * V_281 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_282 * V_283 = V_281 ;
int V_284 ;
V_284 = V_283 -> V_285 ;
if ( V_284 < 0 )
return;
F_254 ( & V_266 ) ;
F_189 (s, &slab_caches, list) {
V_37 = F_11 ( V_2 , V_284 ) ;
if ( V_37 ) {
F_119 ( F_91 ( V_2 , V_284 ) ) ;
V_2 -> V_10 [ V_284 ] = NULL ;
F_219 ( V_9 , V_37 ) ;
}
}
F_253 ( & V_266 ) ;
}
static int F_281 ( void * V_281 )
{
struct V_9 * V_37 ;
struct V_1 * V_2 ;
struct V_282 * V_283 = V_281 ;
int V_209 = V_283 -> V_285 ;
int V_224 = 0 ;
if ( V_209 < 0 )
return 0 ;
F_254 ( & V_266 ) ;
F_189 (s, &slab_caches, list) {
V_37 = F_207 ( V_9 , V_253 ) ;
if ( ! V_37 ) {
V_224 = - V_279 ;
goto V_116;
}
F_226 ( V_37 ) ;
V_2 -> V_10 [ V_209 ] = V_37 ;
}
V_116:
F_253 ( & V_266 ) ;
return V_224 ;
}
static int F_282 ( struct V_286 * V_287 ,
unsigned long V_288 , void * V_281 )
{
int V_224 = 0 ;
switch ( V_288 ) {
case V_289 :
V_224 = F_281 ( V_281 ) ;
break;
case V_290 :
V_224 = F_279 ( V_281 ) ;
break;
case V_291 :
case V_292 :
F_280 ( V_281 ) ;
break;
case V_293 :
case V_294 :
break;
}
if ( V_224 )
V_224 = F_283 ( V_224 ) ;
else
V_224 = V_295 ;
return V_224 ;
}
static struct V_1 * T_7 F_284 ( struct V_1 * V_296 )
{
int V_10 ;
struct V_1 * V_2 = F_285 ( V_1 , V_250 ) ;
memcpy ( V_2 , V_296 , V_1 -> V_21 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
struct V_11 * V_5 ;
if ( V_37 ) {
F_189 (p, &n->partial, lru)
V_5 -> V_142 = V_2 ;
#ifdef F_2
F_189 (p, &n->full, lru)
V_5 -> V_142 = V_2 ;
#endif
}
}
F_88 ( & V_2 -> V_297 , & V_298 ) ;
return V_2 ;
}
void T_7 F_286 ( void )
{
static V_299 struct V_1 V_300 ,
V_301 ;
int V_56 ;
int V_302 = 2 ;
if ( F_287 () )
V_245 = 0 ;
V_9 = & V_301 ;
V_1 = & V_300 ;
F_288 ( V_9 , L_73 ,
sizeof( struct V_9 ) , V_303 ) ;
F_289 ( F_282 , V_304 ) ;
V_251 = V_305 ;
F_288 ( V_1 , L_74 ,
F_290 ( struct V_1 , V_10 ) +
V_306 * sizeof( struct V_9 * ) ,
V_303 ) ;
V_1 = F_284 ( & V_300 ) ;
V_9 = F_284 ( & V_301 ) ;
F_231 ( V_307 > 256 ||
( V_307 & ( V_307 - 1 ) ) ) ;
for ( V_56 = 8 ; V_56 < V_307 ; V_56 += 8 ) {
int V_308 = F_260 ( V_56 ) ;
if ( V_308 >= F_291 ( V_270 ) )
break;
V_270 [ V_308 ] = V_309 ;
}
if ( V_307 == 64 ) {
for ( V_56 = 64 + 8 ; V_56 <= 96 ; V_56 += 8 )
V_270 [ F_260 ( V_56 ) ] = 7 ;
} else if ( V_307 == 128 ) {
for ( V_56 = 128 + 8 ; V_56 <= 192 ; V_56 += 8 )
V_270 [ F_260 ( V_56 ) ] = 8 ;
}
if ( V_307 <= 32 ) {
V_272 [ 1 ] = F_292 ( L_75 , 96 , 0 ) ;
V_302 ++ ;
}
if ( V_307 <= 64 ) {
V_272 [ 2 ] = F_292 ( L_76 , 192 , 0 ) ;
V_302 ++ ;
}
for ( V_56 = V_309 ; V_56 < V_249 ; V_56 ++ ) {
V_272 [ V_56 ] = F_292 ( L_77 , 1 << V_56 , 0 ) ;
V_302 ++ ;
}
V_251 = V_310 ;
if ( V_307 <= 32 ) {
V_272 [ 1 ] -> V_45 = F_293 ( V_272 [ 1 ] -> V_45 , V_250 ) ;
F_119 ( ! V_272 [ 1 ] -> V_45 ) ;
}
if ( V_307 <= 64 ) {
V_272 [ 2 ] -> V_45 = F_293 ( V_272 [ 2 ] -> V_45 , V_250 ) ;
F_119 ( ! V_272 [ 2 ] -> V_45 ) ;
}
for ( V_56 = V_309 ; V_56 < V_249 ; V_56 ++ ) {
char * V_2 = F_294 ( V_250 , L_78 , 1 << V_56 ) ;
F_119 ( ! V_2 ) ;
V_272 [ V_56 ] -> V_45 = V_2 ;
}
#ifdef F_295
F_296 ( & V_311 ) ;
#endif
#ifdef F_262
for ( V_56 = 0 ; V_56 < V_249 ; V_56 ++ ) {
struct V_1 * V_2 = V_272 [ V_56 ] ;
if ( V_2 && V_2 -> V_15 ) {
char * V_45 = F_294 ( V_250 ,
L_79 , V_2 -> V_21 ) ;
F_119 ( ! V_45 ) ;
V_271 [ V_56 ] = F_292 ( V_45 ,
V_2 -> V_21 , V_259 ) ;
}
}
#endif
F_38 ( V_44
L_80
L_81 ,
V_302 , F_297 () ,
V_239 , V_245 , V_243 ,
V_244 , V_306 ) ;
}
void T_7 F_298 ( void )
{
}
static int F_299 ( struct V_1 * V_2 )
{
if ( V_267 || ( V_2 -> V_3 & V_312 ) )
return 1 ;
if ( V_2 -> F_104 )
return 1 ;
if ( V_2 -> V_313 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_300 ( struct V_314 * V_315 , T_1 V_15 ,
T_1 V_257 , unsigned long V_3 , const char * V_45 ,
void (* F_104)( void * ) )
{
struct V_1 * V_2 ;
if ( V_267 || ( V_3 & V_312 ) )
return NULL ;
if ( F_104 )
return NULL ;
V_15 = F_239 ( V_15 , sizeof( void * ) ) ;
V_257 = F_301 ( V_3 , V_257 , V_15 ) ;
V_15 = F_239 ( V_15 , V_257 ) ;
V_3 = F_103 ( V_15 , V_3 , V_45 , NULL ) ;
F_189 (s, &slab_caches, list) {
if ( F_299 ( V_2 ) )
continue;
if ( V_15 > V_2 -> V_15 )
continue;
if ( ( V_3 & V_316 ) != ( V_2 -> V_3 & V_316 ) )
continue;
if ( ( V_2 -> V_15 & ~ ( V_257 - 1 ) ) != V_2 -> V_15 )
continue;
if ( V_2 -> V_15 - V_15 >= sizeof( void * ) )
continue;
if ( ! F_302 ( V_2 , V_315 ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 *
F_303 ( struct V_314 * V_315 , const char * V_45 , T_1 V_15 ,
T_1 V_257 , unsigned long V_3 , void (* F_104)( void * ) )
{
struct V_1 * V_2 ;
V_2 = F_300 ( V_315 , V_15 , V_257 , V_3 , V_45 , F_104 ) ;
if ( V_2 ) {
V_2 -> V_313 ++ ;
V_2 -> V_21 = F_223 ( V_2 -> V_21 , ( int ) V_15 ) ;
V_2 -> V_24 = F_304 ( int , V_2 -> V_24 , F_239 ( V_15 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_45 ) ) {
V_2 -> V_313 -- ;
V_2 = NULL ;
}
}
return V_2 ;
}
int F_305 ( struct V_1 * V_2 , unsigned long V_3 )
{
int V_317 ;
V_317 = F_240 ( V_2 , V_3 ) ;
if ( V_317 )
return V_317 ;
if ( V_251 <= V_310 )
return 0 ;
F_7 ( V_2 ) ;
F_253 ( & V_266 ) ;
V_317 = F_4 ( V_2 ) ;
F_254 ( & V_266 ) ;
if ( V_317 )
F_250 ( V_2 ) ;
return V_317 ;
}
static int T_9 F_306 ( struct V_286 * V_318 ,
unsigned long V_288 , void * V_319 )
{
long V_64 = ( long ) V_319 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_288 ) {
case V_320 :
case V_321 :
case V_322 :
case V_323 :
F_254 ( & V_266 ) ;
F_189 (s, &slab_caches, list) {
F_40 ( V_3 ) ;
F_178 ( V_2 , V_64 ) ;
F_41 ( V_3 ) ;
}
F_253 ( & V_266 ) ;
break;
default:
break;
}
return V_295 ;
}
void * F_307 ( T_1 V_15 , T_5 V_208 , unsigned long V_324 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_273 ) )
return F_264 ( V_15 , V_208 ) ;
V_2 = F_261 ( V_15 , V_208 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_224 = F_206 ( V_2 , V_208 , V_324 ) ;
F_210 ( V_324 , V_224 , V_15 , V_2 -> V_15 , V_208 ) ;
return V_224 ;
}
void * F_308 ( T_1 V_15 , T_5 V_208 ,
int V_10 , unsigned long V_324 )
{
struct V_1 * V_2 ;
void * V_224 ;
if ( F_3 ( V_15 > V_273 ) ) {
V_224 = F_266 ( V_15 , V_208 , V_10 ) ;
F_216 ( V_324 , V_224 ,
V_15 , V_27 << F_193 ( V_15 ) ,
V_208 , V_10 ) ;
return V_224 ;
}
V_2 = F_261 ( V_15 , V_208 ) ;
if ( F_3 ( F_265 ( V_2 ) ) )
return V_2 ;
V_224 = F_202 ( V_2 , V_208 , V_10 , V_324 ) ;
F_216 ( V_324 , V_224 , V_15 , V_2 -> V_15 , V_208 , V_10 ) ;
return V_224 ;
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
if ( ! F_71 ( V_2 , V_11 , V_5 , V_111 ) )
return 0 ;
}
F_124 (p, s, addr, page->objects)
if ( ! F_247 ( F_21 ( V_5 , V_2 , V_18 ) , V_46 ) )
if ( ! F_71 ( V_2 , V_11 , V_5 , V_95 ) )
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
unsigned long V_325 = 0 ;
struct V_11 * V_11 ;
unsigned long V_3 ;
F_188 ( & V_37 -> V_161 , V_3 ) ;
F_189 (page, &n->partial, lru) {
F_313 ( V_2 , V_11 , V_46 ) ;
V_325 ++ ;
}
if ( V_325 != V_37 -> V_153 )
F_38 ( V_49 L_82
L_83 , V_2 -> V_45 , V_325 , V_37 -> V_153 ) ;
if ( ! ( V_2 -> V_3 & V_23 ) )
goto V_116;
F_189 (page, &n->full, lru) {
F_313 ( V_2 , V_11 , V_46 ) ;
V_325 ++ ;
}
if ( V_325 != F_92 ( & V_37 -> V_109 ) )
F_38 ( V_49 L_84
L_83 , V_2 -> V_45 , V_325 ,
F_92 ( & V_37 -> V_109 ) ) ;
V_116:
F_190 ( & V_37 -> V_161 , V_3 ) ;
return V_325 ;
}
static long F_315 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_325 = 0 ;
unsigned long * V_46 = F_276 ( F_246 ( F_26 ( V_2 -> F_223 ) ) *
sizeof( unsigned long ) , V_253 ) ;
if ( ! V_46 )
return - V_279 ;
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
V_325 += F_314 ( V_2 , V_37 , V_46 ) ;
}
F_248 ( V_46 ) ;
return V_325 ;
}
static void F_316 ( struct V_326 * V_71 )
{
if ( V_71 -> F_223 )
F_317 ( ( unsigned long ) V_71 -> V_327 ,
F_193 ( sizeof( struct V_328 ) * V_71 -> F_223 ) ) ;
}
static int F_318 ( struct V_326 * V_71 , unsigned long F_223 , T_5 V_3 )
{
struct V_328 * V_185 ;
int V_25 ;
V_25 = F_193 ( sizeof( struct V_328 ) * F_223 ) ;
V_185 = ( void * ) F_319 ( V_3 , V_25 ) ;
if ( ! V_185 )
return 0 ;
if ( V_71 -> V_325 ) {
memcpy ( V_185 , V_71 -> V_327 , sizeof( struct V_328 ) * V_71 -> V_325 ) ;
F_316 ( V_71 ) ;
}
V_71 -> F_223 = F_223 ;
V_71 -> V_327 = V_185 ;
return 1 ;
}
static int F_320 ( struct V_326 * V_71 , struct V_1 * V_2 ,
const struct V_51 * V_51 )
{
long V_87 , V_91 , V_329 ;
struct V_328 * V_185 ;
unsigned long V_330 ;
unsigned long V_331 = V_68 - V_51 -> V_67 ;
V_87 = - 1 ;
V_91 = V_71 -> V_325 ;
for ( ; ; ) {
V_329 = V_87 + ( V_91 - V_87 + 1 ) / 2 ;
if ( V_329 == V_91 )
break;
V_330 = V_71 -> V_327 [ V_329 ] . V_18 ;
if ( V_51 -> V_18 == V_330 ) {
V_185 = & V_71 -> V_327 [ V_329 ] ;
V_185 -> V_325 ++ ;
if ( V_51 -> V_67 ) {
V_185 -> V_332 += V_331 ;
if ( V_331 < V_185 -> V_333 )
V_185 -> V_333 = V_331 ;
if ( V_331 > V_185 -> V_334 )
V_185 -> V_334 = V_331 ;
if ( V_51 -> V_65 < V_185 -> V_335 )
V_185 -> V_335 = V_51 -> V_65 ;
if ( V_51 -> V_65 > V_185 -> V_336 )
V_185 -> V_336 = V_51 -> V_65 ;
F_321 ( V_51 -> V_64 ,
F_322 ( V_185 -> V_337 ) ) ;
}
F_323 ( F_120 ( F_324 ( V_51 ) ) , V_185 -> V_338 ) ;
return 1 ;
}
if ( V_51 -> V_18 < V_330 )
V_91 = V_329 ;
else
V_87 = V_329 ;
}
if ( V_71 -> V_325 >= V_71 -> F_223 && ! F_318 ( V_71 , 2 * V_71 -> F_223 , V_207 ) )
return 0 ;
V_185 = V_71 -> V_327 + V_329 ;
if ( V_329 < V_71 -> V_325 )
memmove ( V_185 + 1 , V_185 ,
( V_71 -> V_325 - V_329 ) * sizeof( struct V_328 ) ) ;
V_71 -> V_325 ++ ;
V_185 -> V_325 = 1 ;
V_185 -> V_18 = V_51 -> V_18 ;
V_185 -> V_332 = V_331 ;
V_185 -> V_333 = V_331 ;
V_185 -> V_334 = V_331 ;
V_185 -> V_335 = V_51 -> V_65 ;
V_185 -> V_336 = V_51 -> V_65 ;
F_325 ( F_322 ( V_185 -> V_337 ) ) ;
F_321 ( V_51 -> V_64 , F_322 ( V_185 -> V_337 ) ) ;
F_326 ( V_185 -> V_338 ) ;
F_323 ( F_120 ( F_324 ( V_51 ) ) , V_185 -> V_338 ) ;
return 1 ;
}
static void F_327 ( struct V_326 * V_71 , struct V_1 * V_2 ,
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
int V_339 = 0 ;
unsigned long V_56 ;
struct V_326 V_71 = { 0 , 0 , NULL } ;
int V_10 ;
unsigned long * V_46 = F_276 ( F_246 ( F_26 ( V_2 -> F_223 ) ) *
sizeof( unsigned long ) , V_253 ) ;
if ( ! V_46 || ! F_318 ( & V_71 , V_27 / sizeof( struct V_328 ) ,
V_340 ) ) {
F_248 ( V_46 ) ;
return sprintf ( V_73 , L_85 ) ;
}
F_182 ( V_2 ) ;
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
unsigned long V_3 ;
struct V_11 * V_11 ;
if ( ! F_92 ( & V_37 -> V_109 ) )
continue;
F_188 ( & V_37 -> V_161 , V_3 ) ;
F_189 (page, &n->partial, lru)
F_327 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_189 (page, &n->full, lru)
F_327 ( & V_71 , V_2 , V_11 , V_53 , V_46 ) ;
F_190 ( & V_37 -> V_161 , V_3 ) ;
}
for ( V_56 = 0 ; V_56 < V_71 . V_325 ; V_56 ++ ) {
struct V_328 * V_185 = & V_71 . V_327 [ V_56 ] ;
if ( V_339 > V_27 - V_341 - 100 )
break;
V_339 += sprintf ( V_73 + V_339 , L_86 , V_185 -> V_325 ) ;
if ( V_185 -> V_18 )
V_339 += sprintf ( V_73 + V_339 , L_87 , ( void * ) V_185 -> V_18 ) ;
else
V_339 += sprintf ( V_73 + V_339 , L_88 ) ;
if ( V_185 -> V_332 != V_185 -> V_333 ) {
V_339 += sprintf ( V_73 + V_339 , L_89 ,
V_185 -> V_333 ,
( long ) F_329 ( V_185 -> V_332 , V_185 -> V_325 ) ,
V_185 -> V_334 ) ;
} else
V_339 += sprintf ( V_73 + V_339 , L_90 ,
V_185 -> V_333 ) ;
if ( V_185 -> V_335 != V_185 -> V_336 )
V_339 += sprintf ( V_73 + V_339 , L_91 ,
V_185 -> V_335 , V_185 -> V_336 ) ;
else
V_339 += sprintf ( V_73 + V_339 , L_92 ,
V_185 -> V_335 ) ;
if ( F_330 () > 1 &&
! F_331 ( F_322 ( V_185 -> V_337 ) ) &&
V_339 < V_27 - 60 ) {
V_339 += sprintf ( V_73 + V_339 , L_93 ) ;
V_339 += F_332 ( V_73 + V_339 , V_27 - V_339 - 50 ,
F_322 ( V_185 -> V_337 ) ) ;
}
if ( V_342 > 1 && ! F_333 ( V_185 -> V_338 ) &&
V_339 < V_27 - 60 ) {
V_339 += sprintf ( V_73 + V_339 , L_94 ) ;
V_339 += F_334 ( V_73 + V_339 , V_27 - V_339 - 50 ,
V_185 -> V_338 ) ;
}
V_339 += sprintf ( V_73 + V_339 , L_95 ) ;
}
F_316 ( & V_71 ) ;
F_248 ( V_46 ) ;
if ( ! V_71 . V_325 )
V_339 += sprintf ( V_73 , L_96 ) ;
return V_339 ;
}
static void F_335 ( void )
{
T_3 * V_5 ;
F_231 ( V_307 > 16 || V_249 < 10 ) ;
F_38 ( V_49 L_97 ) ;
F_38 ( V_49 L_98 ) ;
F_38 ( V_49 L_99 ) ;
V_5 = F_245 ( 16 , V_253 ) ;
V_5 [ 16 ] = 0x12 ;
F_38 ( V_49 L_100
L_101 , V_5 + 16 ) ;
F_315 ( V_272 [ 4 ] ) ;
V_5 = F_245 ( 32 , V_253 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_38 ( V_49 L_102
L_103 , V_5 ) ;
F_38 ( V_49
L_104 ) ;
F_315 ( V_272 [ 5 ] ) ;
V_5 = F_245 ( 64 , V_253 ) ;
V_5 += 64 + ( F_152 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_38 ( V_49 L_105 ,
V_5 ) ;
F_38 ( V_49
L_104 ) ;
F_315 ( V_272 [ 6 ] ) ;
F_38 ( V_49 L_106 ) ;
V_5 = F_245 ( 128 , V_253 ) ;
F_248 ( V_5 ) ;
* V_5 = 0x78 ;
F_38 ( V_49 L_107 , V_5 ) ;
F_315 ( V_272 [ 7 ] ) ;
V_5 = F_245 ( 256 , V_253 ) ;
F_248 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_38 ( V_49 L_108 ,
V_5 ) ;
F_315 ( V_272 [ 8 ] ) ;
V_5 = F_245 ( 512 , V_253 ) ;
F_248 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_38 ( V_49 L_109 , V_5 ) ;
F_315 ( V_272 [ 9 ] ) ;
}
static void F_335 ( void ) {}
static T_10 F_336 ( struct V_1 * V_2 ,
char * V_73 , unsigned long V_3 )
{
unsigned long V_343 = 0 ;
int V_10 ;
int V_29 ;
unsigned long * V_338 ;
unsigned long * V_344 ;
V_338 = F_245 ( 2 * sizeof( unsigned long ) * V_306 , V_253 ) ;
if ( ! V_338 )
return - V_279 ;
V_344 = V_338 + V_306 ;
if ( V_3 & V_345 ) {
int V_64 ;
F_170 (cpu) {
struct V_158 * V_159 = F_171 ( V_2 -> V_8 , V_64 ) ;
int V_10 ;
struct V_11 * V_11 ;
V_11 = F_337 ( V_159 -> V_11 ) ;
if ( ! V_11 )
continue;
V_10 = F_120 ( V_11 ) ;
if ( V_3 & V_346 )
V_29 = V_11 -> V_14 ;
else if ( V_3 & V_347 )
V_29 = V_11 -> V_24 ;
else
V_29 = 1 ;
V_343 += V_29 ;
V_338 [ V_10 ] += V_29 ;
V_11 = F_337 ( V_159 -> V_155 ) ;
if ( V_11 ) {
V_29 = V_11 -> V_202 ;
V_343 += V_29 ;
V_338 [ V_10 ] += V_29 ;
}
V_344 [ V_10 ] ++ ;
}
}
F_338 () ;
#ifdef F_2
if ( V_3 & V_348 ) {
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( V_3 & V_346 )
V_29 = F_92 ( & V_37 -> V_110 ) ;
else if ( V_3 & V_347 )
V_29 = F_92 ( & V_37 -> V_110 ) -
F_186 ( V_37 , F_185 ) ;
else
V_29 = F_92 ( & V_37 -> V_109 ) ;
V_343 += V_29 ;
V_338 [ V_10 ] += V_29 ;
}
} else
#endif
if ( V_3 & V_349 ) {
F_235 (node, N_NORMAL_MEMORY) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( V_3 & V_346 )
V_29 = F_186 ( V_37 , F_310 ) ;
else if ( V_3 & V_347 )
V_29 = F_186 ( V_37 , F_309 ) ;
else
V_29 = V_37 -> V_153 ;
V_343 += V_29 ;
V_338 [ V_10 ] += V_29 ;
}
}
V_29 = sprintf ( V_73 , L_110 , V_343 ) ;
#ifdef F_150
F_235 (node, N_NORMAL_MEMORY)
if ( V_338 [ V_10 ] )
V_29 += sprintf ( V_73 + V_29 , L_111 ,
V_10 , V_338 [ V_10 ] ) ;
#endif
F_339 () ;
F_248 ( V_338 ) ;
return V_29 + sprintf ( V_73 + V_29 , L_95 ) ;
}
static int F_340 ( struct V_1 * V_2 )
{
int V_10 ;
F_194 (node) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
if ( F_92 ( & V_37 -> V_110 ) )
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
return sprintf ( V_73 , L_112 , V_2 -> V_257 ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_21 ) ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , F_26 ( V_2 -> V_122 ) ) ;
}
static T_10 F_345 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_25 ;
int V_317 ;
V_317 = F_346 ( V_73 , 10 , & V_25 ) ;
if ( V_317 )
return V_317 ;
if ( V_25 > V_245 || V_25 < V_239 )
return - V_264 ;
F_238 ( V_2 , V_25 ) ;
return V_48 ;
}
static T_10 F_347 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , F_25 ( V_2 -> V_122 ) ) ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_113 , V_2 -> V_174 ) ;
}
static T_10 F_349 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_130 ;
int V_317 ;
V_317 = F_346 ( V_73 , 10 , & V_130 ) ;
if ( V_317 )
return V_317 ;
F_237 ( V_2 , V_130 ) ;
return V_48 ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_114 , V_2 -> V_165 ) ;
}
static T_10 F_351 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
unsigned long V_14 ;
int V_317 ;
V_317 = F_346 ( V_73 , 10 , & V_14 ) ;
if ( V_317 )
return V_317 ;
if ( V_14 && F_1 ( V_2 ) )
return - V_264 ;
V_2 -> V_165 = V_14 ;
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
return sprintf ( V_73 , L_112 , V_2 -> V_313 - 1 ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_349 ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_345 ) ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_348 | V_347 ) ;
}
static T_10 F_357 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_349 | V_347 ) ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_73 )
{
int V_14 = 0 ;
int V_134 = 0 ;
int V_64 ;
int V_339 ;
F_359 (cpu) {
struct V_11 * V_11 = F_171 ( V_2 -> V_8 , V_64 ) -> V_155 ;
if ( V_11 ) {
V_134 += V_11 -> V_134 ;
V_14 += V_11 -> V_202 ;
}
}
V_339 = sprintf ( V_73 , L_116 , V_14 , V_134 ) ;
#ifdef F_295
F_359 (cpu) {
struct V_11 * V_11 = F_171 ( V_2 -> V_8 , V_64 ) -> V_155 ;
if ( V_11 && V_339 < V_27 - 20 )
V_339 += sprintf ( V_73 + V_339 , L_117 , V_64 ,
V_11 -> V_202 , V_11 -> V_134 ) ;
}
#endif
return V_339 + sprintf ( V_73 + V_339 , L_95 ) ;
}
static T_10 F_360 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_135 ) ) ;
}
static T_10 F_361 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_135 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_135 ;
return V_48 ;
}
static T_10 F_362 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_303 ) ) ;
}
static T_10 F_363 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_259 ) ) ;
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
return F_336 ( V_2 , V_73 , V_348 ) ;
}
static T_10 F_367 ( struct V_1 * V_2 , char * V_73 )
{
return F_336 ( V_2 , V_73 , V_348 | V_346 ) ;
}
static T_10 F_368 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_119 ) ) ;
}
static T_10 F_369 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_119 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_119 ;
}
return V_48 ;
}
static T_10 F_370 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_101 ) ) ;
}
static T_10 F_371 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_101 ;
if ( V_73 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_40 ;
V_2 -> V_3 |= V_101 ;
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
return - V_350 ;
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
return - V_350 ;
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
return - V_350 ;
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
int V_224 = - V_264 ;
if ( V_73 [ 0 ] == '1' ) {
V_224 = F_315 ( V_2 ) ;
if ( V_224 >= 0 )
V_224 = V_48 ;
}
return V_224 ;
}
static T_10 F_380 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_247 ;
return F_328 ( V_2 , V_73 , V_70 ) ;
}
static T_10 F_381 ( struct V_1 * V_2 , char * V_73 )
{
if ( ! ( V_2 -> V_3 & V_23 ) )
return - V_247 ;
return F_328 ( V_2 , V_73 , V_69 ) ;
}
static T_10 F_382 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , ! ! ( V_2 -> V_3 & V_120 ) ) ;
}
static T_10 F_383 ( struct V_1 * V_2 , const char * V_73 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_120 ;
if ( V_73 [ 0 ] == '1' )
V_2 -> V_3 |= V_120 ;
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
int V_265 = F_275 ( V_2 ) ;
if ( V_265 )
return V_265 ;
} else
return - V_264 ;
return V_48 ;
}
static T_10 F_386 ( struct V_1 * V_2 , char * V_73 )
{
return sprintf ( V_73 , L_112 , V_2 -> V_173 / 10 ) ;
}
static T_10 F_387 ( struct V_1 * V_2 ,
const char * V_73 , T_1 V_48 )
{
unsigned long V_351 ;
int V_317 ;
V_317 = F_346 ( V_73 , 10 , & V_351 ) ;
if ( V_317 )
return V_317 ;
if ( V_351 <= 100 )
V_2 -> V_173 = V_351 * 10 ;
return V_48 ;
}
static int F_388 ( struct V_1 * V_2 , char * V_73 , enum V_6 V_7 )
{
unsigned long V_352 = 0 ;
int V_64 ;
int V_339 ;
int * V_83 = F_276 ( V_244 * sizeof( int ) , V_253 ) ;
if ( ! V_83 )
return - V_279 ;
F_359 (cpu) {
unsigned V_29 = F_171 ( V_2 -> V_8 , V_64 ) -> F_8 [ V_7 ] ;
V_83 [ V_64 ] = V_29 ;
V_352 += V_29 ;
}
V_339 = sprintf ( V_73 , L_110 , V_352 ) ;
#ifdef F_295
F_359 (cpu) {
if ( V_83 [ V_64 ] && V_339 < V_27 - 20 )
V_339 += sprintf ( V_73 + V_339 , L_118 , V_64 , V_83 [ V_64 ] ) ;
}
#endif
F_248 ( V_83 ) ;
return V_339 + sprintf ( V_73 + V_339 , L_95 ) ;
}
static void F_389 ( struct V_1 * V_2 , enum V_6 V_7 )
{
int V_64 ;
F_359 (cpu)
F_171 ( V_2 -> V_8 , V_64 ) -> F_8 [ V_7 ] = 0 ;
}
static T_10 F_390 ( struct V_353 * V_354 ,
struct V_355 * V_356 ,
char * V_73 )
{
struct V_357 * V_355 ;
struct V_1 * V_2 ;
int V_317 ;
V_355 = F_391 ( V_356 ) ;
V_2 = F_392 ( V_354 ) ;
if ( ! V_355 -> V_358 )
return - V_359 ;
V_317 = V_355 -> V_358 ( V_2 , V_73 ) ;
return V_317 ;
}
static T_10 F_393 ( struct V_353 * V_354 ,
struct V_355 * V_356 ,
const char * V_73 , T_1 V_339 )
{
struct V_357 * V_355 ;
struct V_1 * V_2 ;
int V_317 ;
V_355 = F_391 ( V_356 ) ;
V_2 = F_392 ( V_354 ) ;
if ( ! V_355 -> V_360 )
return - V_359 ;
V_317 = V_355 -> V_360 ( V_2 , V_73 , V_339 ) ;
#ifdef F_394
if ( V_251 >= V_361 && V_317 >= 0 && F_395 ( V_2 ) ) {
int V_56 ;
F_254 ( & V_266 ) ;
if ( V_2 -> V_362 < V_339 )
V_2 -> V_362 = V_339 ;
F_396 (i) {
struct V_1 * V_159 = F_397 ( V_2 , V_56 ) ;
if ( V_159 )
V_355 -> V_360 ( V_159 , V_73 , V_339 ) ;
}
F_253 ( & V_266 ) ;
}
#endif
return V_317 ;
}
static void F_7 ( struct V_1 * V_2 )
{
#ifdef F_394
int V_56 ;
char * V_363 = NULL ;
if ( ! F_395 ( V_2 ) )
return;
if ( ! V_2 -> V_362 )
return;
for ( V_56 = 0 ; V_56 < F_291 ( V_364 ) ; V_56 ++ ) {
char V_365 [ 64 ] ;
char * V_73 ;
struct V_357 * V_356 = F_391 ( V_364 [ V_56 ] ) ;
if ( ! V_356 || ! V_356 -> V_360 || ! V_356 -> V_358 )
continue;
if ( V_363 )
V_73 = V_363 ;
else if ( V_2 -> V_362 < F_291 ( V_365 ) )
V_73 = V_365 ;
else {
V_363 = ( char * ) F_398 ( V_253 ) ;
if ( F_142 ( ! V_363 ) )
continue;
V_73 = V_363 ;
}
V_356 -> V_358 ( V_2 -> V_366 -> V_367 , V_73 ) ;
V_356 -> V_360 ( V_2 , V_73 , strlen ( V_73 ) ) ;
}
if ( V_363 )
F_399 ( ( unsigned long ) V_363 ) ;
#endif
}
static int F_400 ( struct V_368 * V_368 , struct V_353 * V_354 )
{
struct V_369 * V_370 = F_401 ( V_354 ) ;
if ( V_370 == & V_371 )
return 1 ;
return 0 ;
}
static char * F_402 ( struct V_1 * V_2 )
{
char * V_45 = F_276 ( V_372 , V_253 ) ;
char * V_5 = V_45 ;
F_119 ( ! V_45 ) ;
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
V_5 += sprintf ( V_5 , L_119 , V_2 -> V_15 ) ;
#ifdef F_394
if ( ! F_395 ( V_2 ) )
V_5 += sprintf ( V_5 , L_120 , F_403 ( V_2 -> V_366 -> V_315 ) ) ;
#endif
F_119 ( V_5 > V_45 + V_372 - 1 ) ;
return V_45 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_317 ;
const char * V_45 ;
int V_373 = F_299 ( V_2 ) ;
if ( V_373 ) {
F_404 ( & V_374 -> V_354 , V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
} else {
V_45 = F_402 ( V_2 ) ;
}
V_2 -> V_354 . V_368 = V_374 ;
V_317 = F_405 ( & V_2 -> V_354 , & V_371 , NULL , V_45 ) ;
if ( V_317 ) {
F_406 ( & V_2 -> V_354 ) ;
return V_317 ;
}
V_317 = F_407 ( & V_2 -> V_354 , & V_375 ) ;
if ( V_317 ) {
F_408 ( & V_2 -> V_354 ) ;
F_406 ( & V_2 -> V_354 ) ;
return V_317 ;
}
F_409 ( & V_2 -> V_354 , V_376 ) ;
if ( ! V_373 ) {
F_5 ( V_2 , V_2 -> V_45 ) ;
F_248 ( V_45 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_251 < V_361 )
return;
F_409 ( & V_2 -> V_354 , V_377 ) ;
F_408 ( & V_2 -> V_354 ) ;
F_406 ( & V_2 -> V_354 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_45 )
{
struct V_378 * V_379 ;
if ( V_251 == V_361 ) {
F_404 ( & V_374 -> V_354 , V_45 ) ;
return F_410 ( & V_374 -> V_354 , & V_2 -> V_354 , V_45 ) ;
}
V_379 = F_276 ( sizeof( struct V_378 ) , V_253 ) ;
if ( ! V_379 )
return - V_279 ;
V_379 -> V_2 = V_2 ;
V_379 -> V_45 = V_45 ;
V_379 -> V_198 = V_380 ;
V_380 = V_379 ;
return 0 ;
}
static int T_7 F_411 ( void )
{
struct V_1 * V_2 ;
int V_317 ;
F_254 ( & V_266 ) ;
V_374 = F_412 ( L_121 , & V_381 , V_382 ) ;
if ( ! V_374 ) {
F_253 ( & V_266 ) ;
F_38 ( V_49 L_122 ) ;
return - V_247 ;
}
V_251 = V_361 ;
F_189 (s, &slab_caches, list) {
V_317 = F_4 ( V_2 ) ;
if ( V_317 )
F_38 ( V_49 L_123
L_124 , V_2 -> V_45 ) ;
}
while ( V_380 ) {
struct V_378 * V_379 = V_380 ;
V_380 = V_380 -> V_198 ;
V_317 = F_5 ( V_379 -> V_2 , V_379 -> V_45 ) ;
if ( V_317 )
F_38 ( V_49 L_125
L_126 , V_379 -> V_45 ) ;
F_248 ( V_379 ) ;
}
F_253 ( & V_266 ) ;
F_335 () ;
return 0 ;
}
void F_413 ( struct V_1 * V_2 , struct V_383 * V_384 )
{
unsigned long V_385 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_211 = 0 ;
unsigned long V_212 = 0 ;
int V_10 ;
F_194 (node) {
struct V_9 * V_37 = F_11 ( V_2 , V_10 ) ;
if ( ! V_37 )
continue;
V_385 += V_37 -> V_153 ;
V_109 += F_92 ( & V_37 -> V_109 ) ;
V_211 += F_92 ( & V_37 -> V_110 ) ;
V_212 += F_186 ( V_37 , F_185 ) ;
}
V_384 -> V_386 = V_211 - V_212 ;
V_384 -> V_387 = V_211 ;
V_384 -> V_388 = V_109 ;
V_384 -> V_389 = V_109 ;
V_384 -> V_390 = F_26 ( V_2 -> V_122 ) ;
V_384 -> V_391 = F_25 ( V_2 -> V_122 ) ;
}
void F_414 ( struct V_392 * V_186 , struct V_1 * V_2 )
{
}
T_10 F_415 ( struct V_393 * V_393 , const char T_11 * V_363 ,
T_1 V_325 , T_12 * V_394 )
{
return - V_359 ;
}
