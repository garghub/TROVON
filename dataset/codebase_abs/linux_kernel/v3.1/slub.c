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
int V_49 , V_19 ;
int V_50 = 1 ;
char V_51 [ 17 ] ;
V_51 [ 16 ] = 0 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
if ( V_50 ) {
F_37 ( V_52 L_2 , V_47 , V_21 + V_49 ) ;
V_50 = 0 ;
}
F_37 ( V_53 L_3 , V_21 [ V_49 ] ) ;
V_19 = V_49 % 16 ;
V_51 [ V_19 ] = isgraph ( V_21 [ V_49 ] ) ? V_21 [ V_49 ] : '.' ;
if ( V_19 == 15 ) {
F_37 ( V_53 L_4 , V_51 ) ;
V_50 = 1 ;
}
}
if ( ! V_50 ) {
V_49 %= 16 ;
while ( V_49 < 16 ) {
F_37 ( V_53 L_5 ) ;
V_51 [ V_49 ] = ' ' ;
V_49 ++ ;
}
F_37 ( V_53 L_4 , V_51 ) ;
}
}
static struct V_54 * F_44 ( struct V_1 * V_2 , void * V_15 ,
enum V_55 V_56 )
{
struct V_54 * V_5 ;
if ( V_2 -> V_19 )
V_5 = V_15 + V_2 -> V_19 + sizeof( void * ) ;
else
V_5 = V_15 + V_2 -> V_27 ;
return V_5 + V_56 ;
}
static void F_45 ( struct V_1 * V_2 , void * V_15 ,
enum V_55 V_56 , unsigned long V_21 )
{
struct V_54 * V_5 = F_44 ( V_2 , V_15 , V_56 ) ;
if ( V_21 ) {
#ifdef F_46
struct V_57 V_58 ;
int V_49 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = V_61 ;
V_58 . V_62 = V_5 -> V_63 ;
V_58 . V_64 = 3 ;
F_47 ( & V_58 ) ;
if ( V_58 . V_59 != 0 &&
V_58 . V_62 [ V_58 . V_59 - 1 ] == V_65 )
V_58 . V_59 -- ;
for ( V_49 = V_58 . V_59 ; V_49 < V_61 ; V_49 ++ )
V_5 -> V_63 [ V_49 ] = 0 ;
#endif
V_5 -> V_21 = V_21 ;
V_5 -> V_66 = F_48 () ;
V_5 -> V_67 = V_68 -> V_67 ;
V_5 -> V_69 = V_70 ;
} else
memset ( V_5 , 0 , sizeof( struct V_54 ) ) ;
}
static void F_49 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_45 ( V_2 , V_15 , V_71 , 0UL ) ;
F_45 ( V_2 , V_15 , V_72 , 0UL ) ;
}
static void F_50 ( const char * V_2 , struct V_54 * V_73 )
{
if ( ! V_73 -> V_21 )
return;
F_37 ( V_52 L_6 ,
V_2 , ( void * ) V_73 -> V_21 , V_70 - V_73 -> V_69 , V_73 -> V_66 , V_73 -> V_67 ) ;
#ifdef F_46
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_61 ; V_49 ++ )
if ( V_73 -> V_63 [ V_49 ] )
F_37 ( V_52 L_7 , ( void * ) V_73 -> V_63 [ V_49 ] ) ;
else
break;
}
#endif
}
static void F_51 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_50 ( L_8 , F_44 ( V_2 , V_15 , V_72 ) ) ;
F_50 ( L_9 , F_44 ( V_2 , V_15 , V_71 ) ) ;
}
static void F_52 ( struct V_14 * V_14 )
{
F_37 ( V_52 L_10 ,
V_14 , V_14 -> V_17 , V_14 -> V_27 , V_14 -> V_42 , V_14 -> V_3 ) ;
}
static void F_53 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_37 ( V_52 L_11
L_12 ) ;
F_37 ( V_52 L_13 , V_2 -> V_6 , V_75 ) ;
F_37 ( V_52 L_14
L_15 ) ;
}
static void F_54 ( struct V_1 * V_2 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_37 ( V_52 L_16 , V_2 -> V_6 , V_75 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned int V_76 ;
T_3 * V_21 = F_14 ( V_14 ) ;
F_51 ( V_2 , V_5 ) ;
F_52 ( V_14 ) ;
F_37 ( V_52 L_17 ,
V_5 , V_5 - V_21 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_21 + 16 )
F_43 ( L_18 , V_5 - 16 , 16 ) ;
F_43 ( L_19 , V_5 , F_56 (unsigned long, s->objsize, PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_22 )
F_43 ( L_20 , V_5 + V_2 -> V_24 ,
V_2 -> V_27 - V_2 -> V_24 ) ;
if ( V_2 -> V_19 )
V_76 = V_2 -> V_19 + sizeof( void * ) ;
else
V_76 = V_2 -> V_27 ;
if ( V_2 -> V_3 & V_26 )
V_76 += 2 * sizeof( struct V_54 ) ;
if ( V_76 != V_2 -> V_18 )
F_43 ( L_21 , V_5 + V_76 , V_2 -> V_18 - V_76 ) ;
F_57 () ;
}
static void F_58 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_77 )
{
F_53 ( V_2 , L_22 , V_77 ) ;
F_55 ( V_2 , V_14 , V_15 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_14 * V_14 , char * V_74 , ... )
{
T_4 args ;
char V_75 [ 100 ] ;
va_start ( args , V_74 ) ;
vsnprintf ( V_75 , sizeof( V_75 ) , V_74 , args ) ;
va_end ( args ) ;
F_53 ( V_2 , L_22 , V_75 ) ;
F_52 ( V_14 ) ;
F_57 () ;
}
static void F_60 ( struct V_1 * V_2 , void * V_15 , T_3 V_78 )
{
T_3 * V_5 = V_15 ;
if ( V_2 -> V_3 & V_79 ) {
memset ( V_5 , V_80 , V_2 -> V_24 - 1 ) ;
V_5 [ V_2 -> V_24 - 1 ] = V_81 ;
}
if ( V_2 -> V_3 & V_22 )
memset ( V_5 + V_2 -> V_24 , V_78 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
static T_3 * F_61 ( T_3 * V_82 , T_3 V_83 , unsigned int V_84 )
{
while ( V_84 ) {
if ( * V_82 != V_83 )
return V_82 ;
V_82 ++ ;
V_84 -- ;
}
return NULL ;
}
static T_3 * F_62 ( T_3 * V_82 , T_3 V_83 , unsigned int V_84 )
{
T_5 V_85 ;
unsigned int V_86 , V_87 ;
if ( V_84 <= 16 )
return F_61 ( V_82 , V_83 , V_84 ) ;
V_85 = V_83 | V_83 << 8 | V_83 << 16 | V_83 << 24 ;
V_85 = ( V_85 & 0xffffffff ) | V_85 << 32 ;
V_87 = 8 - ( ( unsigned long ) V_82 ) % 8 ;
if ( V_87 ) {
T_3 * V_88 = F_61 ( V_82 , V_83 , V_87 ) ;
if ( V_88 )
return V_88 ;
V_82 += V_87 ;
V_84 -= V_87 ;
}
V_86 = V_84 / 8 ;
while ( V_86 ) {
if ( * ( T_5 * ) V_82 != V_85 )
return F_61 ( V_82 , V_83 , 8 ) ;
V_82 += 8 ;
V_86 -- ;
}
return F_61 ( V_82 , V_83 , V_84 % 8 ) ;
}
static void F_63 ( struct V_1 * V_2 , char * V_89 , T_3 V_90 ,
void * V_91 , void * V_92 )
{
F_54 ( V_2 , L_23 , V_91 , V_92 - 1 , V_90 ) ;
memset ( V_91 , V_90 , V_92 - V_91 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_3 * V_15 , char * V_93 ,
T_3 * V_82 , unsigned int V_83 , unsigned int V_84 )
{
T_3 * V_94 ;
T_3 * V_95 ;
V_94 = F_62 ( V_82 , V_83 , V_84 ) ;
if ( ! V_94 )
return 1 ;
V_95 = V_82 + V_84 ;
while ( V_95 > V_94 && V_95 [ - 1 ] == V_83 )
V_95 -- ;
F_53 ( V_2 , L_24 , V_93 ) ;
F_37 ( V_52 L_25 ,
V_94 , V_95 - 1 , V_94 [ 0 ] , V_83 ) ;
F_55 ( V_2 , V_14 , V_15 ) ;
F_63 ( V_2 , V_93 , V_83 , V_94 , V_95 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_14 * V_14 , T_3 * V_5 )
{
unsigned long V_76 = V_2 -> V_27 ;
if ( V_2 -> V_19 )
V_76 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_26 )
V_76 += 2 * sizeof( struct V_54 ) ;
if ( V_2 -> V_18 == V_76 )
return 1 ;
return F_64 ( V_2 , V_14 , V_5 , L_26 ,
V_5 + V_76 , V_96 , V_2 -> V_18 - V_76 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
T_3 * V_82 ;
T_3 * V_94 ;
T_3 * V_95 ;
int V_48 ;
int V_97 ;
if ( ! ( V_2 -> V_3 & V_23 ) )
return 1 ;
V_82 = F_14 ( V_14 ) ;
V_48 = ( V_30 << F_67 ( V_14 ) ) - V_2 -> V_29 ;
V_95 = V_82 + V_48 ;
V_97 = V_48 % V_2 -> V_18 ;
if ( ! V_97 )
return 1 ;
V_94 = F_62 ( V_95 - V_97 , V_96 , V_97 ) ;
if ( ! V_94 )
return 1 ;
while ( V_95 > V_94 && V_95 [ - 1 ] == V_96 )
V_95 -- ;
F_59 ( V_2 , V_14 , L_27 , V_94 , V_95 - 1 ) ;
F_43 ( L_21 , V_95 - V_97 , V_97 ) ;
F_63 ( V_2 , L_28 , V_96 , V_95 - V_97 , V_95 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_3 V_78 )
{
T_3 * V_5 = V_15 ;
T_3 * V_98 = V_15 + V_2 -> V_24 ;
if ( V_2 -> V_3 & V_22 ) {
if ( ! F_64 ( V_2 , V_14 , V_15 , L_20 ,
V_98 , V_78 , V_2 -> V_27 - V_2 -> V_24 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_23 ) && V_2 -> V_24 < V_2 -> V_27 ) {
F_64 ( V_2 , V_14 , V_5 , L_29 ,
V_98 , V_96 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
}
if ( V_2 -> V_3 & V_23 ) {
if ( V_78 != V_99 && ( V_2 -> V_3 & V_79 ) &&
( ! F_64 ( V_2 , V_14 , V_5 , L_30 , V_5 ,
V_80 , V_2 -> V_24 - 1 ) ||
! F_64 ( V_2 , V_14 , V_5 , L_30 ,
V_5 + V_2 -> V_24 - 1 , V_81 , 1 ) ) )
return 0 ;
F_65 ( V_2 , V_14 , V_5 ) ;
}
if ( ! V_2 -> V_19 && V_78 == V_99 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , F_15 ( V_2 , V_5 ) ) ) {
F_58 ( V_2 , V_14 , V_5 , L_31 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_100 ;
F_31 ( ! F_32 () ) ;
if ( ! F_70 ( V_14 ) ) {
F_59 ( V_2 , V_14 , L_32 ) ;
return 0 ;
}
V_100 = F_22 ( F_67 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_14 -> V_17 > V_100 ) {
F_59 ( V_2 , V_14 , L_33 ,
V_2 -> V_6 , V_14 -> V_17 , V_100 ) ;
return 0 ;
}
if ( V_14 -> V_27 > V_14 -> V_17 ) {
F_59 ( V_2 , V_14 , L_34 ,
V_2 -> V_6 , V_14 -> V_27 , V_14 -> V_17 ) ;
return 0 ;
}
F_66 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_101 )
{
int V_102 = 0 ;
void * V_20 ;
void * V_15 = NULL ;
unsigned long V_103 ;
V_20 = V_14 -> V_42 ;
while ( V_20 && V_102 <= V_14 -> V_17 ) {
if ( V_20 == V_101 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , V_20 ) ) {
if ( V_15 ) {
F_58 ( V_2 , V_14 , V_15 ,
L_35 ) ;
F_19 ( V_2 , V_15 , NULL ) ;
break;
} else {
F_59 ( V_2 , V_14 , L_31 ) ;
V_14 -> V_42 = NULL ;
V_14 -> V_27 = V_14 -> V_17 ;
F_54 ( V_2 , L_36 ) ;
return 0 ;
}
break;
}
V_15 = V_20 ;
V_20 = F_15 ( V_2 , V_15 ) ;
V_102 ++ ;
}
V_103 = F_22 ( F_67 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_103 > V_104 )
V_103 = V_104 ;
if ( V_14 -> V_17 != V_103 ) {
F_59 ( V_2 , V_14 , L_37
L_38 , V_14 -> V_17 , V_103 ) ;
V_14 -> V_17 = V_103 ;
F_54 ( V_2 , L_39 ) ;
}
if ( V_14 -> V_27 != V_14 -> V_17 - V_102 ) {
F_59 ( V_2 , V_14 , L_40
L_41 , V_14 -> V_27 , V_14 -> V_17 - V_102 ) ;
V_14 -> V_27 = V_14 -> V_17 - V_102 ;
F_54 ( V_2 , L_42 ) ;
}
return V_101 == NULL ;
}
static void V_58 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_15 ,
int V_56 )
{
if ( V_2 -> V_3 & V_105 ) {
F_37 ( V_45 L_43 ,
V_2 -> V_6 ,
V_56 ? L_44 : L_45 ,
V_15 , V_14 -> V_27 ,
V_14 -> V_42 ) ;
if ( ! V_56 )
F_43 ( L_19 , ( void * ) V_15 , V_2 -> V_24 ) ;
F_57 () ;
}
}
static inline int F_72 ( struct V_1 * V_2 , T_6 V_3 )
{
V_3 &= V_106 ;
F_73 ( V_3 ) ;
F_74 ( V_3 & V_107 ) ;
return F_75 ( V_2 -> V_24 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_76 ( struct V_1 * V_2 , T_6 V_3 , void * V_15 )
{
V_3 &= V_106 ;
F_77 ( V_2 , V_3 , V_15 , F_21 ( V_2 ) ) ;
F_78 ( V_15 , V_2 -> V_24 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_79 ( struct V_1 * V_2 , void * V_32 )
{
F_80 ( V_32 , V_2 -> V_3 ) ;
#if F_81 ( V_108 ) || F_81 ( V_109 )
{
unsigned long V_3 ;
F_39 ( V_3 ) ;
F_82 ( V_2 , V_32 , V_2 -> V_24 ) ;
F_83 ( V_32 , V_2 -> V_24 ) ;
F_40 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_110 ) )
F_84 ( V_32 , V_2 -> V_24 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_86 ( & V_14 -> V_111 , & V_40 -> V_112 ) ;
}
static void F_87 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_88 ( & V_14 -> V_111 ) ;
}
static inline unsigned long F_89 ( struct V_1 * V_2 , int V_13 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
return F_90 ( & V_40 -> V_113 ) ;
}
static inline unsigned long F_91 ( struct V_12 * V_40 )
{
return F_90 ( & V_40 -> V_113 ) ;
}
static inline void F_92 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_40 ) {
F_93 ( & V_40 -> V_113 ) ;
F_94 ( V_17 , & V_40 -> V_114 ) ;
}
}
static inline void F_95 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_96 ( & V_40 -> V_113 ) ;
F_97 ( V_17 , & V_40 -> V_114 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
if ( ! ( V_2 -> V_3 & ( V_26 | V_22 | V_79 ) ) )
return;
F_60 ( V_2 , V_15 , V_115 ) ;
F_49 ( V_2 , V_15 ) ;
}
static T_7 int F_99 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , unsigned long V_21 )
{
if ( ! F_69 ( V_2 , V_14 ) )
goto V_116;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_58 ( V_2 , V_14 , V_15 , L_46 ) ;
goto V_116;
}
if ( ! F_68 ( V_2 , V_14 , V_15 , V_115 ) )
goto V_116;
if ( V_2 -> V_3 & V_26 )
F_45 ( V_2 , V_15 , V_72 , V_21 ) ;
V_58 ( V_2 , V_14 , V_15 , 1 ) ;
F_60 ( V_2 , V_15 , V_99 ) ;
return 1 ;
V_116:
if ( F_70 ( V_14 ) ) {
F_54 ( V_2 , L_47 ) ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_42 = NULL ;
}
return 0 ;
}
static T_7 int F_100 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 )
{
unsigned long V_3 ;
int V_117 = 0 ;
F_39 ( V_3 ) ;
F_26 ( V_14 ) ;
if ( ! F_69 ( V_2 , V_14 ) )
goto V_118;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_59 ( V_2 , V_14 , L_48 , V_15 ) ;
goto V_118;
}
if ( F_71 ( V_2 , V_14 , V_15 ) ) {
F_58 ( V_2 , V_14 , V_15 , L_49 ) ;
goto V_118;
}
if ( ! F_68 ( V_2 , V_14 , V_15 , V_99 ) )
goto V_119;
if ( F_3 ( V_2 != V_14 -> V_120 ) ) {
if ( ! F_70 ( V_14 ) ) {
F_59 ( V_2 , V_14 , L_50
L_51 , V_15 ) ;
} else if ( ! V_14 -> V_120 ) {
F_37 ( V_52
L_52 ,
V_15 ) ;
F_57 () ;
} else
F_58 ( V_2 , V_14 , V_15 ,
L_53 ) ;
goto V_118;
}
if ( V_2 -> V_3 & V_26 )
F_45 ( V_2 , V_15 , V_71 , V_21 ) ;
V_58 ( V_2 , V_14 , V_15 , 0 ) ;
F_60 ( V_2 , V_15 , V_115 ) ;
V_117 = 1 ;
V_119:
F_28 ( V_14 ) ;
F_40 ( V_3 ) ;
return V_117 ;
V_118:
F_54 ( V_2 , L_54 , V_15 ) ;
goto V_119;
}
static int T_8 F_101 ( char * V_121 )
{
V_122 = V_123 ;
if ( * V_121 ++ != '=' || ! * V_121 )
goto V_119;
if ( * V_121 == ',' )
goto V_124;
if ( tolower ( * V_121 ) == 'o' ) {
V_125 = 1 ;
goto V_119;
}
V_122 = 0 ;
if ( * V_121 == '-' )
goto V_119;
for (; * V_121 && * V_121 != ',' ; V_121 ++ ) {
switch ( tolower ( * V_121 ) ) {
case 'f' :
V_122 |= V_126 ;
break;
case 'z' :
V_122 |= V_22 ;
break;
case 'p' :
V_122 |= V_23 ;
break;
case 'u' :
V_122 |= V_26 ;
break;
case 't' :
V_122 |= V_105 ;
break;
case 'a' :
V_122 |= V_127 ;
break;
default:
F_37 ( V_52 L_55
L_56 , * V_121 ) ;
}
}
V_124:
if ( * V_121 == ',' )
V_128 = V_121 + 1 ;
V_119:
return 1 ;
}
static unsigned long F_102 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
if ( V_122 && ( ! V_128 ||
! strncmp ( V_128 , V_6 , strlen ( V_128 ) ) ) )
V_3 |= V_122 ;
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
static inline int F_72 ( struct V_1 * V_2 , T_6 V_3 )
{ return 0 ; }
static inline void F_76 ( struct V_1 * V_2 , T_6 V_3 ,
void * V_15 ) {}
static inline void F_79 ( struct V_1 * V_2 , void * V_32 ) {}
static inline struct V_14 * F_104 ( T_6 V_3 , int V_13 ,
struct V_31 V_129 )
{
int V_28 = F_24 ( V_129 ) ;
V_3 |= V_130 ;
if ( V_13 == V_131 )
return F_105 ( V_3 , V_28 ) ;
else
return F_106 ( V_13 , V_3 , V_28 ) ;
}
static struct V_14 * F_107 ( struct V_1 * V_2 , T_6 V_3 , int V_13 )
{
struct V_14 * V_14 ;
struct V_31 V_129 = V_2 -> V_129 ;
T_6 V_132 ;
V_3 &= V_106 ;
if ( V_3 & V_107 )
F_108 () ;
V_3 |= V_2 -> V_133 ;
V_132 = ( V_3 | V_134 | V_135 ) & ~ V_136 ;
V_14 = F_104 ( V_132 , V_13 , V_129 ) ;
if ( F_3 ( ! V_14 ) ) {
V_129 = V_2 -> V_137 ;
V_14 = F_104 ( V_3 , V_13 , V_129 ) ;
if ( V_14 )
F_8 ( V_2 , V_138 ) ;
}
if ( V_3 & V_107 )
F_109 () ;
if ( ! V_14 )
return NULL ;
if ( V_139
&& ! ( V_2 -> V_3 & ( V_140 | V_123 ) ) ) {
int V_141 = 1 << F_24 ( V_129 ) ;
F_110 ( V_14 , F_24 ( V_129 ) , V_3 , V_13 ) ;
if ( V_2 -> F_103 )
F_111 ( V_14 , V_141 ) ;
else
F_112 ( V_14 , V_141 ) ;
}
V_14 -> V_17 = F_25 ( V_129 ) ;
F_113 ( F_114 ( V_14 ) ,
( V_2 -> V_3 & V_142 ) ?
V_143 : V_144 ,
1 << F_24 ( V_129 ) ) ;
return V_14 ;
}
static void F_115 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
F_98 ( V_2 , V_14 , V_15 ) ;
if ( F_3 ( V_2 -> F_103 ) )
V_2 -> F_103 ( V_15 ) ;
}
static struct V_14 * F_116 ( struct V_1 * V_2 , T_6 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_82 ;
void * V_145 ;
void * V_5 ;
F_117 ( V_3 & V_146 ) ;
V_14 = F_107 ( V_2 ,
V_3 & ( V_147 | V_148 ) , V_13 ) ;
if ( ! V_14 )
goto V_119;
F_92 ( V_2 , F_118 ( V_14 ) , V_14 -> V_17 ) ;
V_14 -> V_120 = V_2 ;
V_14 -> V_3 |= 1 << V_149 ;
V_82 = F_14 ( V_14 ) ;
if ( F_3 ( V_2 -> V_3 & V_23 ) )
memset ( V_82 , V_96 , V_30 << F_67 ( V_14 ) ) ;
V_145 = V_82 ;
F_119 (p, s, start, page->objects) {
F_115 ( V_2 , V_14 , V_145 ) ;
F_19 ( V_2 , V_145 , V_5 ) ;
V_145 = V_5 ;
}
F_115 ( V_2 , V_14 , V_145 ) ;
F_19 ( V_2 , V_145 , NULL ) ;
V_14 -> V_42 = V_82 ;
V_14 -> V_27 = 0 ;
V_14 -> V_150 = 1 ;
V_119:
return V_14 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_28 = F_67 ( V_14 ) ;
int V_141 = 1 << V_28 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_66 ( V_2 , V_14 ) ;
F_119 (p, s, page_address(page),
page->objects)
F_68 ( V_2 , V_14 , V_5 , V_115 ) ;
}
F_121 ( V_14 , F_67 ( V_14 ) ) ;
F_113 ( F_114 ( V_14 ) ,
( V_2 -> V_3 & V_142 ) ?
V_143 : V_144 ,
- V_141 ) ;
F_122 ( V_14 ) ;
F_123 ( V_14 ) ;
if ( V_68 -> V_151 )
V_68 -> V_151 -> V_152 += V_141 ;
F_124 ( V_14 , V_28 ) ;
}
static void F_125 ( struct V_153 * V_154 )
{
struct V_14 * V_14 ;
if ( V_155 )
V_14 = F_126 ( V_154 ) ;
else
V_14 = F_127 ( (struct V_156 * ) V_154 , struct V_14 , V_111 ) ;
F_120 ( V_14 -> V_120 , V_14 ) ;
}
static void F_128 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( F_3 ( V_2 -> V_3 & V_25 ) ) {
struct V_153 * V_157 ;
if ( V_155 ) {
int V_28 = F_67 ( V_14 ) ;
int V_19 = ( V_30 << V_28 ) - V_2 -> V_29 ;
F_31 ( V_2 -> V_29 != sizeof( * V_157 ) ) ;
V_157 = F_14 ( V_14 ) + V_19 ;
} else {
V_157 = ( void * ) & V_14 -> V_111 ;
}
F_129 ( V_157 , F_125 ) ;
} else
F_120 ( V_2 , V_14 ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
F_95 ( V_2 , F_118 ( V_14 ) , V_14 -> V_17 ) ;
F_128 ( V_2 , V_14 ) ;
}
static inline void F_131 ( struct V_12 * V_40 ,
struct V_14 * V_14 , int V_158 )
{
V_40 -> V_159 ++ ;
if ( V_158 )
F_132 ( & V_14 -> V_111 , & V_40 -> V_160 ) ;
else
F_86 ( & V_14 -> V_111 , & V_40 -> V_160 ) ;
}
static inline void F_133 ( struct V_12 * V_40 ,
struct V_14 * V_14 )
{
F_88 ( & V_14 -> V_111 ) ;
V_40 -> V_159 -- ;
}
static inline int F_134 ( struct V_1 * V_2 ,
struct V_12 * V_40 , struct V_14 * V_14 )
{
void * V_42 ;
unsigned long V_43 ;
struct V_14 V_161 ;
do {
V_42 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
V_161 . V_43 = V_43 ;
V_161 . V_27 = V_14 -> V_17 ;
F_31 ( V_161 . V_150 ) ;
V_161 . V_150 = 1 ;
} while ( ! F_30 ( V_2 , V_14 ,
V_42 , V_43 ,
NULL , V_161 . V_43 ,
L_57 ) );
F_133 ( V_40 , V_14 ) ;
if ( V_42 ) {
F_135 ( V_2 -> V_9 -> V_42 , V_42 ) ;
F_135 ( V_2 -> V_9 -> V_14 , V_14 ) ;
F_135 ( V_2 -> V_9 -> V_13 , F_118 ( V_14 ) ) ;
return 1 ;
} else {
F_37 ( V_52 L_58
L_59 , V_2 -> V_6 ) ;
return 0 ;
}
}
static struct V_14 * F_136 ( struct V_1 * V_2 ,
struct V_12 * V_40 )
{
struct V_14 * V_14 ;
if ( ! V_40 || ! V_40 -> V_159 )
return NULL ;
F_137 ( & V_40 -> V_162 ) ;
F_138 (page, &n->partial, lru)
if ( F_134 ( V_2 , V_40 , V_14 ) )
goto V_119;
V_14 = NULL ;
V_119:
F_139 ( & V_40 -> V_162 ) ;
return V_14 ;
}
static struct V_14 * F_140 ( struct V_1 * V_2 , T_6 V_3 )
{
#ifdef F_141
struct V_163 * V_163 ;
struct V_164 * V_165 ;
struct V_166 * V_166 ;
enum V_167 V_168 = F_142 ( V_3 ) ;
struct V_14 * V_14 ;
if ( ! V_2 -> V_169 ||
F_143 () % 1024 > V_2 -> V_169 )
return NULL ;
F_144 () ;
V_163 = F_145 ( F_146 ( V_68 -> V_170 ) , V_3 ) ;
F_147 (zone, z, zonelist, high_zoneidx) {
struct V_12 * V_40 ;
V_40 = F_12 ( V_2 , F_148 ( V_166 ) ) ;
if ( V_40 && F_149 ( V_166 , V_3 ) &&
V_40 -> V_159 > V_2 -> V_171 ) {
V_14 = F_136 ( V_2 , V_40 ) ;
if ( V_14 ) {
F_150 () ;
return V_14 ;
}
}
}
F_150 () ;
#endif
return NULL ;
}
static struct V_14 * F_151 ( struct V_1 * V_2 , T_6 V_3 , int V_13 )
{
struct V_14 * V_14 ;
int V_172 = ( V_13 == V_131 ) ? F_152 () : V_13 ;
V_14 = F_136 ( V_2 , F_12 ( V_2 , V_172 ) ) ;
if ( V_14 || V_13 != V_131 )
return V_14 ;
return F_140 ( V_2 , V_3 ) ;
}
static inline unsigned long F_153 ( unsigned long V_173 )
{
return V_173 + V_174 ;
}
static inline unsigned int F_154 ( unsigned long V_173 )
{
return V_173 % V_174 ;
}
static inline unsigned long F_155 ( unsigned long V_173 )
{
return V_173 / V_174 ;
}
static inline unsigned int F_156 ( int V_66 )
{
return V_66 ;
}
static inline void F_157 ( const char * V_40 ,
const struct V_1 * V_2 , unsigned long V_173 )
{
#ifdef F_36
unsigned long V_175 = F_158 ( V_2 -> V_9 -> V_173 ) ;
F_37 ( V_45 L_60 , V_40 , V_2 -> V_6 ) ;
#ifdef F_159
if ( F_154 ( V_173 ) != F_154 ( V_175 ) )
F_37 ( L_61 ,
F_154 ( V_173 ) , F_154 ( V_175 ) ) ;
else
#endif
if ( F_155 ( V_173 ) != F_155 ( V_175 ) )
F_37 ( L_62 ,
F_155 ( V_173 ) , F_155 ( V_175 ) ) ;
else
F_37 ( L_63 ,
V_175 , V_173 , F_153 ( V_173 ) ) ;
#endif
F_8 ( V_2 , V_176 ) ;
}
void F_160 ( struct V_1 * V_2 )
{
int V_66 ;
F_161 (cpu)
F_162 ( V_2 -> V_9 , V_66 ) -> V_173 = F_156 ( V_66 ) ;
}
static void F_163 ( struct V_1 * V_2 , struct V_177 * V_178 )
{
enum T_9 { V_179 , V_180 , V_181 , V_182 };
struct V_14 * V_14 = V_178 -> V_14 ;
struct V_12 * V_40 = F_12 ( V_2 , F_118 ( V_14 ) ) ;
int V_183 = 0 ;
enum T_9 V_184 = V_179 , V_185 = V_179 ;
void * V_42 ;
void * V_186 ;
int V_158 = 0 ;
struct V_14 V_161 ;
struct V_14 V_187 ;
if ( V_14 -> V_42 ) {
F_8 ( V_2 , V_188 ) ;
V_158 = 1 ;
}
V_178 -> V_173 = F_153 ( V_178 -> V_173 ) ;
V_178 -> V_14 = NULL ;
V_42 = V_178 -> V_42 ;
V_178 -> V_42 = NULL ;
while ( V_42 && ( V_186 = F_15 ( V_2 , V_42 ) ) ) {
void * V_189 ;
unsigned long V_43 ;
do {
V_189 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
F_19 ( V_2 , V_42 , V_189 ) ;
V_161 . V_43 = V_43 ;
V_161 . V_27 -- ;
F_31 ( ! V_161 . V_150 ) ;
} while ( ! F_30 ( V_2 , V_14 ,
V_189 , V_43 ,
V_42 , V_161 . V_43 ,
L_64 ) );
V_42 = V_186 ;
}
V_190:
V_187 . V_42 = V_14 -> V_42 ;
V_187 . V_43 = V_14 -> V_43 ;
F_31 ( ! V_187 . V_150 ) ;
V_161 . V_43 = V_187 . V_43 ;
if ( V_42 ) {
V_161 . V_27 -- ;
F_19 ( V_2 , V_42 , V_187 . V_42 ) ;
V_161 . V_42 = V_42 ;
} else
V_161 . V_42 = V_187 . V_42 ;
V_161 . V_150 = 0 ;
if ( ! V_161 . V_27 && V_40 -> V_159 > V_2 -> V_171 )
V_185 = V_182 ;
else if ( V_161 . V_42 ) {
V_185 = V_180 ;
if ( ! V_183 ) {
V_183 = 1 ;
F_137 ( & V_40 -> V_162 ) ;
}
} else {
V_185 = V_181 ;
if ( F_1 ( V_2 ) && ! V_183 ) {
V_183 = 1 ;
F_137 ( & V_40 -> V_162 ) ;
}
}
if ( V_184 != V_185 ) {
if ( V_184 == V_180 )
F_133 ( V_40 , V_14 ) ;
else if ( V_184 == V_181 )
F_87 ( V_2 , V_14 ) ;
if ( V_185 == V_180 ) {
F_131 ( V_40 , V_14 , V_158 ) ;
F_8 ( V_2 , V_158 ? V_191 : V_192 ) ;
} else if ( V_185 == V_181 ) {
F_8 ( V_2 , V_193 ) ;
F_85 ( V_2 , V_40 , V_14 ) ;
}
}
V_184 = V_185 ;
if ( ! F_30 ( V_2 , V_14 ,
V_187 . V_42 , V_187 . V_43 ,
V_161 . V_42 , V_161 . V_43 ,
L_65 ) )
goto V_190;
if ( V_183 )
F_139 ( & V_40 -> V_162 ) ;
if ( V_185 == V_182 ) {
F_8 ( V_2 , V_194 ) ;
F_130 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_195 ) ;
}
}
static inline void F_164 ( struct V_1 * V_2 , struct V_177 * V_178 )
{
F_8 ( V_2 , V_196 ) ;
F_163 ( V_2 , V_178 ) ;
}
static inline void F_165 ( struct V_1 * V_2 , int V_66 )
{
struct V_177 * V_178 = F_162 ( V_2 -> V_9 , V_66 ) ;
if ( F_166 ( V_178 && V_178 -> V_14 ) )
F_164 ( V_2 , V_178 ) ;
}
static void F_167 ( void * V_197 )
{
struct V_1 * V_2 = V_197 ;
F_165 ( V_2 , F_48 () ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
F_169 ( F_167 , V_2 , 1 ) ;
}
static inline int F_170 ( struct V_177 * V_178 , int V_13 )
{
#ifdef F_141
if ( V_13 != V_131 && V_178 -> V_13 != V_13 )
return 0 ;
#endif
return 1 ;
}
static int F_171 ( struct V_14 * V_14 )
{
return V_14 -> V_17 - V_14 -> V_27 ;
}
static unsigned long F_172 ( struct V_12 * V_40 ,
int (* F_173)( struct V_14 * ) )
{
unsigned long V_3 ;
unsigned long V_32 = 0 ;
struct V_14 * V_14 ;
F_174 ( & V_40 -> V_162 , V_3 ) ;
F_138 (page, &n->partial, lru)
V_32 += F_173 ( V_14 ) ;
F_175 ( & V_40 -> V_162 , V_3 ) ;
return V_32 ;
}
static inline unsigned long F_176 ( struct V_12 * V_40 )
{
#ifdef F_2
return F_90 ( & V_40 -> V_114 ) ;
#else
return 0 ;
#endif
}
static T_7 void
F_177 ( struct V_1 * V_2 , T_6 V_198 , int V_199 )
{
int V_13 ;
F_37 ( V_200
L_66 ,
V_199 , V_198 ) ;
F_37 ( V_200 L_67
L_68 , V_2 -> V_6 , V_2 -> V_24 ,
V_2 -> V_18 , F_24 ( V_2 -> V_129 ) , F_24 ( V_2 -> V_137 ) ) ;
if ( F_24 ( V_2 -> V_137 ) > F_178 ( V_2 -> V_24 ) )
F_37 ( V_200 L_69
L_70 , V_2 -> V_6 ) ;
F_179 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_113 ;
unsigned long V_201 ;
unsigned long V_202 ;
if ( ! V_40 )
continue;
V_202 = F_172 ( V_40 , F_171 ) ;
V_113 = F_91 ( V_40 ) ;
V_201 = F_176 ( V_40 ) ;
F_37 ( V_200
L_71 ,
V_13 , V_113 , V_201 , V_202 ) ;
}
}
static void * F_180 ( struct V_1 * V_2 , T_6 V_198 , int V_13 ,
unsigned long V_21 , struct V_177 * V_178 )
{
void * * V_15 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
struct V_14 V_161 ;
unsigned long V_43 ;
F_39 ( V_3 ) ;
#ifdef F_159
V_178 = F_181 ( V_2 -> V_9 ) ;
#endif
V_198 &= ~ V_203 ;
V_14 = V_178 -> V_14 ;
if ( ! V_14 )
goto F_116;
if ( F_3 ( ! F_170 ( V_178 , V_13 ) ) ) {
F_8 ( V_2 , V_204 ) ;
F_163 ( V_2 , V_178 ) ;
goto F_116;
}
F_8 ( V_2 , V_205 ) ;
do {
V_15 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
V_161 . V_43 = V_43 ;
F_31 ( ! V_161 . V_150 ) ;
V_161 . V_27 = V_14 -> V_17 ;
V_161 . V_150 = V_15 != NULL ;
} while ( ! F_30 ( V_2 , V_14 ,
V_15 , V_43 ,
NULL , V_161 . V_43 ,
L_72 ) );
if ( F_3 ( ! V_15 ) ) {
V_178 -> V_14 = NULL ;
F_8 ( V_2 , V_206 ) ;
goto F_116;
}
F_8 ( V_2 , V_207 ) ;
V_208:
F_31 ( ! V_14 -> V_150 ) ;
V_178 -> V_42 = F_15 ( V_2 , V_15 ) ;
V_178 -> V_173 = F_153 ( V_178 -> V_173 ) ;
F_40 ( V_3 ) ;
return V_15 ;
F_116:
V_14 = F_151 ( V_2 , V_198 , V_13 ) ;
if ( V_14 ) {
F_8 ( V_2 , V_209 ) ;
V_15 = V_178 -> V_42 ;
if ( F_1 ( V_2 ) )
goto V_210;
goto V_208;
}
V_14 = F_116 ( V_2 , V_198 , V_13 ) ;
if ( V_14 ) {
V_178 = F_182 ( V_2 -> V_9 ) ;
if ( V_178 -> V_14 )
F_164 ( V_2 , V_178 ) ;
V_15 = V_14 -> V_42 ;
V_14 -> V_42 = NULL ;
V_14 -> V_27 = V_14 -> V_17 ;
F_8 ( V_2 , V_211 ) ;
V_178 -> V_13 = F_118 ( V_14 ) ;
V_178 -> V_14 = V_14 ;
if ( F_1 ( V_2 ) )
goto V_210;
goto V_208;
}
if ( ! ( V_198 & V_134 ) && F_183 () )
F_177 ( V_2 , V_198 , V_13 ) ;
F_40 ( V_3 ) ;
return NULL ;
V_210:
if ( ! V_15 || ! F_99 ( V_2 , V_14 , V_15 , V_21 ) )
goto F_116;
V_178 -> V_42 = F_15 ( V_2 , V_15 ) ;
F_163 ( V_2 , V_178 ) ;
V_178 -> V_14 = NULL ;
V_178 -> V_13 = V_131 ;
F_40 ( V_3 ) ;
return V_15 ;
}
static T_2 void * F_184 ( struct V_1 * V_2 ,
T_6 V_198 , int V_13 , unsigned long V_21 )
{
void * * V_15 ;
struct V_177 * V_178 ;
unsigned long V_173 ;
if ( F_72 ( V_2 , V_198 ) )
return NULL ;
V_190:
V_178 = F_182 ( V_2 -> V_9 ) ;
V_173 = V_178 -> V_173 ;
F_185 () ;
V_15 = V_178 -> V_42 ;
if ( F_3 ( ! V_15 || ! F_170 ( V_178 , V_13 ) ) )
V_15 = F_180 ( V_2 , V_198 , V_13 , V_21 , V_178 ) ;
else {
if ( F_3 ( ! F_186 (
V_2 -> V_9 -> V_42 , V_2 -> V_9 -> V_173 ,
V_15 , V_173 ,
F_16 ( V_2 , V_15 ) , F_153 ( V_173 ) ) ) ) {
F_157 ( L_73 , V_2 , V_173 ) ;
goto V_190;
}
F_8 ( V_2 , V_212 ) ;
}
if ( F_3 ( V_198 & V_203 ) && V_15 )
memset ( V_15 , 0 , V_2 -> V_24 ) ;
F_76 ( V_2 , V_198 , V_15 ) ;
return V_15 ;
}
void * F_187 ( struct V_1 * V_2 , T_6 V_198 )
{
void * V_213 = F_184 ( V_2 , V_198 , V_131 , V_214 ) ;
F_188 ( V_214 , V_213 , V_2 -> V_24 , V_2 -> V_18 , V_198 ) ;
return V_213 ;
}
void * F_189 ( struct V_1 * V_2 , T_6 V_198 , T_1 V_18 )
{
void * V_213 = F_184 ( V_2 , V_198 , V_131 , V_214 ) ;
F_190 ( V_214 , V_213 , V_18 , V_2 -> V_18 , V_198 ) ;
return V_213 ;
}
void * F_191 ( T_1 V_18 , T_6 V_3 , unsigned int V_28 )
{
void * V_213 = F_192 ( V_18 , V_3 , V_28 ) ;
F_190 ( V_214 , V_213 , V_18 , V_30 << V_28 , V_3 ) ;
return V_213 ;
}
void * F_193 ( struct V_1 * V_2 , T_6 V_198 , int V_13 )
{
void * V_213 = F_184 ( V_2 , V_198 , V_13 , V_214 ) ;
F_194 ( V_214 , V_213 ,
V_2 -> V_24 , V_2 -> V_18 , V_198 , V_13 ) ;
return V_213 ;
}
void * F_195 ( struct V_1 * V_2 ,
T_6 V_198 ,
int V_13 , T_1 V_18 )
{
void * V_213 = F_184 ( V_2 , V_198 , V_13 , V_214 ) ;
F_196 ( V_214 , V_213 ,
V_18 , V_2 -> V_18 , V_198 , V_13 ) ;
return V_213 ;
}
static void F_197 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_32 , unsigned long V_21 )
{
void * V_189 ;
void * * V_15 = ( void * ) V_32 ;
int V_215 ;
int V_27 ;
struct V_14 V_161 ;
unsigned long V_43 ;
struct V_12 * V_40 = NULL ;
unsigned long V_216 ( V_3 ) ;
F_8 ( V_2 , V_217 ) ;
if ( F_1 ( V_2 ) && ! F_100 ( V_2 , V_14 , V_32 , V_21 ) )
return;
do {
V_189 = V_14 -> V_42 ;
V_43 = V_14 -> V_43 ;
F_19 ( V_2 , V_15 , V_189 ) ;
V_161 . V_43 = V_43 ;
V_215 = V_161 . V_150 ;
V_161 . V_27 -- ;
if ( ( ! V_161 . V_27 || ! V_189 ) && ! V_215 && ! V_40 ) {
V_40 = F_12 ( V_2 , F_118 ( V_14 ) ) ;
F_174 ( & V_40 -> V_162 , V_3 ) ;
}
V_27 = V_161 . V_27 ;
} while ( ! F_38 ( V_2 , V_14 ,
V_189 , V_43 ,
V_15 , V_161 . V_43 ,
L_74 ) );
if ( F_166 ( ! V_40 ) ) {
if ( V_215 )
F_8 ( V_2 , V_218 ) ;
return;
}
if ( V_215 )
F_8 ( V_2 , V_218 ) ;
else {
if ( F_3 ( ! V_27 && V_40 -> V_159 > V_2 -> V_171 ) )
goto V_219;
if ( F_3 ( ! V_189 ) ) {
F_87 ( V_2 , V_14 ) ;
F_131 ( V_40 , V_14 , 1 ) ;
F_8 ( V_2 , V_220 ) ;
}
}
F_175 ( & V_40 -> V_162 , V_3 ) ;
return;
V_219:
if ( V_189 ) {
F_133 ( V_40 , V_14 ) ;
F_8 ( V_2 , V_221 ) ;
} else
F_87 ( V_2 , V_14 ) ;
F_175 ( & V_40 -> V_162 , V_3 ) ;
F_8 ( V_2 , V_195 ) ;
F_130 ( V_2 , V_14 ) ;
}
static T_2 void F_198 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_32 , unsigned long V_21 )
{
void * * V_15 = ( void * ) V_32 ;
struct V_177 * V_178 ;
unsigned long V_173 ;
F_79 ( V_2 , V_32 ) ;
V_190:
V_178 = F_182 ( V_2 -> V_9 ) ;
V_173 = V_178 -> V_173 ;
F_185 () ;
if ( F_166 ( V_14 == V_178 -> V_14 ) ) {
F_19 ( V_2 , V_15 , V_178 -> V_42 ) ;
if ( F_3 ( ! F_186 (
V_2 -> V_9 -> V_42 , V_2 -> V_9 -> V_173 ,
V_178 -> V_42 , V_173 ,
V_15 , F_153 ( V_173 ) ) ) ) {
F_157 ( L_75 , V_2 , V_173 ) ;
goto V_190;
}
F_8 ( V_2 , V_222 ) ;
} else
F_197 ( V_2 , V_14 , V_32 , V_21 ) ;
}
void F_199 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_14 ;
V_14 = F_126 ( V_32 ) ;
F_198 ( V_2 , V_14 , V_32 , V_214 ) ;
F_200 ( V_214 , V_32 ) ;
}
static inline int F_201 ( int V_18 , int V_223 ,
int V_224 , int V_225 , int V_29 )
{
int V_28 ;
int V_226 ;
int V_227 = V_228 ;
if ( F_22 ( V_227 , V_18 , V_29 ) > V_104 )
return F_178 ( V_18 * V_104 ) - 1 ;
for ( V_28 = F_202 ( V_227 ,
F_203 ( V_223 * V_18 - 1 ) - V_229 ) ;
V_28 <= V_224 ; V_28 ++ ) {
unsigned long V_230 = V_30 << V_28 ;
if ( V_230 < V_223 * V_18 + V_29 )
continue;
V_226 = ( V_230 - V_29 ) % V_18 ;
if ( V_226 <= V_230 / V_225 )
break;
}
return V_28 ;
}
static inline int F_204 ( int V_18 , int V_29 )
{
int V_28 ;
int V_223 ;
int V_231 ;
int V_103 ;
V_223 = V_232 ;
if ( ! V_223 )
V_223 = 4 * ( F_203 ( V_233 ) + 1 ) ;
V_103 = F_22 ( V_234 , V_18 , V_29 ) ;
V_223 = V_137 ( V_223 , V_103 ) ;
while ( V_223 > 1 ) {
V_231 = 16 ;
while ( V_231 >= 4 ) {
V_28 = F_201 ( V_18 , V_223 ,
V_234 , V_231 , V_29 ) ;
if ( V_28 <= V_234 )
return V_28 ;
V_231 /= 2 ;
}
V_223 -- ;
}
V_28 = F_201 ( V_18 , 1 , V_234 , 1 , V_29 ) ;
if ( V_28 <= V_234 )
return V_28 ;
V_28 = F_201 ( V_18 , 1 , V_235 , 1 , V_29 ) ;
if ( V_28 < V_235 )
return V_28 ;
return - V_236 ;
}
static unsigned long F_205 ( unsigned long V_3 ,
unsigned long V_237 , unsigned long V_18 )
{
if ( V_3 & V_238 ) {
unsigned long V_239 = F_206 () ;
while ( V_18 <= V_239 / 2 )
V_239 /= 2 ;
V_237 = F_202 ( V_237 , V_239 ) ;
}
if ( V_237 < V_240 )
V_237 = V_240 ;
return F_207 ( V_237 , sizeof( void * ) ) ;
}
static void
F_208 ( struct V_12 * V_40 , struct V_1 * V_2 )
{
V_40 -> V_159 = 0 ;
F_209 ( & V_40 -> V_162 ) ;
F_210 ( & V_40 -> V_160 ) ;
#ifdef F_2
F_211 ( & V_40 -> V_113 , 0 ) ;
F_211 ( & V_40 -> V_114 , 0 ) ;
F_210 ( & V_40 -> V_112 ) ;
#endif
}
static inline int F_212 ( struct V_1 * V_2 )
{
F_213 ( V_241 <
V_242 * sizeof( struct V_177 ) ) ;
V_2 -> V_9 = F_214 ( sizeof( struct V_177 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_160 ( V_2 ) ;
return 1 ;
}
static void F_215 ( int V_13 )
{
struct V_14 * V_14 ;
struct V_12 * V_40 ;
F_117 ( V_12 -> V_18 < sizeof( struct V_12 ) ) ;
V_14 = F_116 ( V_12 , V_243 , V_13 ) ;
F_117 ( ! V_14 ) ;
if ( F_118 ( V_14 ) != V_13 ) {
F_37 ( V_52 L_76
L_77 , V_13 ) ;
F_37 ( V_52 L_78
L_79 ) ;
}
V_40 = V_14 -> V_42 ;
F_117 ( ! V_40 ) ;
V_14 -> V_42 = F_15 ( V_12 , V_40 ) ;
V_14 -> V_27 ++ ;
V_14 -> V_150 = 0 ;
V_12 -> V_13 [ V_13 ] = V_40 ;
#ifdef F_2
F_60 ( V_12 , V_40 , V_99 ) ;
F_49 ( V_12 , V_40 ) ;
#endif
F_208 ( V_40 , V_12 ) ;
F_92 ( V_12 , V_13 , V_14 -> V_17 ) ;
F_131 ( V_40 , V_14 , 0 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
int V_13 ;
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = V_2 -> V_13 [ V_13 ] ;
if ( V_40 )
F_199 ( V_12 , V_40 ) ;
V_2 -> V_13 [ V_13 ] = NULL ;
}
}
static int F_218 ( struct V_1 * V_2 )
{
int V_13 ;
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 ;
if ( V_10 == V_244 ) {
F_215 ( V_13 ) ;
continue;
}
V_40 = F_193 ( V_12 ,
V_245 , V_13 ) ;
if ( ! V_40 ) {
F_216 ( V_2 ) ;
return 0 ;
}
V_2 -> V_13 [ V_13 ] = V_40 ;
F_208 ( V_40 , V_2 ) ;
}
return 1 ;
}
static void F_219 ( struct V_1 * V_2 , unsigned long V_137 )
{
if ( V_137 < V_246 )
V_137 = V_246 ;
else if ( V_137 > V_247 )
V_137 = V_247 ;
V_2 -> V_171 = V_137 ;
}
static int F_220 ( struct V_1 * V_2 , int V_248 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_18 = V_2 -> V_24 ;
unsigned long V_237 = V_2 -> V_237 ;
int V_28 ;
V_18 = F_207 ( V_18 , sizeof( void * ) ) ;
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
V_18 += 2 * sizeof( struct V_54 ) ;
if ( V_3 & V_22 )
V_18 += sizeof( void * ) ;
#endif
V_237 = F_205 ( V_3 , V_237 , V_2 -> V_24 ) ;
V_2 -> V_237 = V_237 ;
V_18 = F_207 ( V_18 , V_237 ) ;
V_2 -> V_18 = V_18 ;
if ( V_248 >= 0 )
V_28 = V_248 ;
else
V_28 = F_204 ( V_18 , V_2 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
V_2 -> V_133 = 0 ;
if ( V_28 )
V_2 -> V_133 |= V_249 ;
if ( V_2 -> V_3 & V_250 )
V_2 -> V_133 |= V_251 ;
if ( V_2 -> V_3 & V_142 )
V_2 -> V_133 |= V_252 ;
V_2 -> V_129 = F_23 ( V_28 , V_18 , V_2 -> V_29 ) ;
V_2 -> V_137 = F_23 ( F_178 ( V_18 ) , V_18 , V_2 -> V_29 ) ;
if ( F_25 ( V_2 -> V_129 ) > F_25 ( V_2 -> F_202 ) )
V_2 -> F_202 = V_2 -> V_129 ;
return ! ! F_25 ( V_2 -> V_129 ) ;
}
static int F_221 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_18 ,
T_1 V_237 , unsigned long V_3 ,
void (* F_103)( void * ) )
{
memset ( V_2 , 0 , V_253 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_103 = F_103 ;
V_2 -> V_24 = V_18 ;
V_2 -> V_237 = V_237 ;
V_2 -> V_3 = F_102 ( V_18 , V_3 , V_6 , F_103 ) ;
V_2 -> V_29 = 0 ;
if ( V_155 && ( V_2 -> V_3 & V_25 ) )
V_2 -> V_29 = sizeof( struct V_153 ) ;
if ( ! F_220 ( V_2 , - 1 ) )
goto error;
if ( V_125 ) {
if ( F_178 ( V_2 -> V_18 ) > F_178 ( V_2 -> V_24 ) ) {
V_2 -> V_3 &= ~ V_254 ;
V_2 -> V_19 = 0 ;
if ( ! F_220 ( V_2 , - 1 ) )
goto error;
}
}
#ifdef F_33
if ( F_222 () && ( V_2 -> V_3 & V_4 ) == 0 )
V_2 -> V_3 |= V_41 ;
#endif
F_219 ( V_2 , F_223 ( V_2 -> V_18 ) ) ;
V_2 -> V_255 = 1 ;
#ifdef F_141
V_2 -> V_169 = 1000 ;
#endif
if ( ! F_218 ( V_2 ) )
goto error;
if ( F_212 ( V_2 ) )
return 1 ;
F_216 ( V_2 ) ;
error:
if ( V_3 & V_256 )
F_224 ( L_80
L_81 ,
V_2 -> V_6 , ( unsigned long ) V_18 , V_2 -> V_18 , F_24 ( V_2 -> V_129 ) ,
V_2 -> V_19 , V_3 ) ;
return 0 ;
}
unsigned int F_225 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
static void F_226 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const char * V_47 )
{
#ifdef F_2
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
unsigned long * V_46 = F_227 ( F_228 ( V_14 -> V_17 ) *
sizeof( long ) , V_257 ) ;
if ( ! V_46 )
return;
F_59 ( V_2 , V_14 , L_22 , V_47 ) ;
F_26 ( V_14 ) ;
F_41 ( V_2 , V_14 , V_46 ) ;
F_119 (p, s, addr, page->objects) {
if ( ! F_229 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) ) {
F_37 ( V_52 L_82 ,
V_5 , V_5 - V_21 ) ;
F_51 ( V_2 , V_5 ) ;
}
}
F_28 ( V_14 ) ;
F_7 ( V_46 ) ;
#endif
}
static void F_230 ( struct V_1 * V_2 , struct V_12 * V_40 )
{
unsigned long V_3 ;
struct V_14 * V_14 , * V_154 ;
F_174 ( & V_40 -> V_162 , V_3 ) ;
F_231 (page, h, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_133 ( V_40 , V_14 ) ;
F_130 ( V_2 , V_14 ) ;
} else {
F_226 ( V_2 , V_14 ,
L_83 ) ;
}
}
F_175 ( & V_40 -> V_162 , V_3 ) ;
}
static inline int F_232 ( struct V_1 * V_2 )
{
int V_13 ;
F_168 ( V_2 ) ;
F_233 ( V_2 -> V_9 ) ;
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
F_230 ( V_2 , V_40 ) ;
if ( V_40 -> V_159 || F_89 ( V_2 , V_13 ) )
return 1 ;
}
F_216 ( V_2 ) ;
return 0 ;
}
void F_234 ( struct V_1 * V_2 )
{
F_235 ( & V_258 ) ;
V_2 -> V_255 -- ;
if ( ! V_2 -> V_255 ) {
F_88 ( & V_2 -> V_259 ) ;
if ( F_232 ( V_2 ) ) {
F_37 ( V_52 L_84
L_85 , V_2 -> V_6 , V_260 ) ;
F_57 () ;
}
if ( V_2 -> V_3 & V_25 )
F_236 () ;
F_6 ( V_2 ) ;
}
F_237 ( & V_258 ) ;
}
static int T_8 F_238 ( char * V_121 )
{
F_239 ( & V_121 , & V_228 ) ;
return 1 ;
}
static int T_8 F_240 ( char * V_121 )
{
F_239 ( & V_121 , & V_234 ) ;
V_234 = V_137 ( V_234 , V_235 - 1 ) ;
return 1 ;
}
static int T_8 F_241 ( char * V_121 )
{
F_239 ( & V_121 , & V_232 ) ;
return 1 ;
}
static int T_8 F_242 ( char * V_121 )
{
V_261 = 1 ;
return 1 ;
}
static struct V_1 * T_8 F_243 ( const char * V_6 ,
int V_18 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_187 ( V_1 , V_243 ) ;
if ( ! F_221 ( V_2 , V_6 , V_18 , V_262 ,
V_3 , NULL ) )
goto F_224;
F_86 ( & V_2 -> V_259 , & V_263 ) ;
return V_2 ;
F_224:
F_224 ( L_86 , V_6 , V_18 ) ;
return NULL ;
}
static inline int F_244 ( T_1 V_84 )
{
return ( V_84 - 1 ) / 8 ;
}
static struct V_1 * F_245 ( T_1 V_18 , T_6 V_3 )
{
int V_264 ;
if ( V_18 <= 192 ) {
if ( ! V_18 )
return V_265 ;
V_264 = V_266 [ F_244 ( V_18 ) ] ;
} else
V_264 = F_203 ( V_18 - 1 ) ;
#ifdef F_246
if ( F_3 ( ( V_3 & V_251 ) ) )
return V_267 [ V_264 ] ;
#endif
return V_268 [ V_264 ] ;
}
void * F_247 ( T_1 V_18 , T_6 V_3 )
{
struct V_1 * V_2 ;
void * V_213 ;
if ( F_3 ( V_18 > V_269 ) )
return F_248 ( V_18 , V_3 ) ;
V_2 = F_245 ( V_18 , V_3 ) ;
if ( F_3 ( F_249 ( V_2 ) ) )
return V_2 ;
V_213 = F_184 ( V_2 , V_3 , V_131 , V_214 ) ;
F_190 ( V_214 , V_213 , V_18 , V_2 -> V_18 , V_3 ) ;
return V_213 ;
}
static void * F_250 ( T_1 V_18 , T_6 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_270 = NULL ;
V_3 |= V_249 | V_130 ;
V_14 = F_251 ( V_13 , V_3 , F_178 ( V_18 ) ) ;
if ( V_14 )
V_270 = F_14 ( V_14 ) ;
F_252 ( V_270 , V_18 , 1 , V_3 ) ;
return V_270 ;
}
void * F_253 ( T_1 V_18 , T_6 V_3 , int V_13 )
{
struct V_1 * V_2 ;
void * V_213 ;
if ( F_3 ( V_18 > V_269 ) ) {
V_213 = F_250 ( V_18 , V_3 , V_13 ) ;
F_196 ( V_214 , V_213 ,
V_18 , V_30 << F_178 ( V_18 ) ,
V_3 , V_13 ) ;
return V_213 ;
}
V_2 = F_245 ( V_18 , V_3 ) ;
if ( F_3 ( F_249 ( V_2 ) ) )
return V_2 ;
V_213 = F_184 ( V_2 , V_3 , V_13 , V_214 ) ;
F_196 ( V_214 , V_213 , V_18 , V_2 -> V_18 , V_3 , V_13 ) ;
return V_213 ;
}
T_1 F_254 ( const void * V_15 )
{
struct V_14 * V_14 ;
if ( F_3 ( V_15 == V_265 ) )
return 0 ;
V_14 = F_126 ( V_15 ) ;
if ( F_3 ( ! F_70 ( V_14 ) ) ) {
F_255 ( ! F_256 ( V_14 ) ) ;
return V_30 << F_67 ( V_14 ) ;
}
return F_21 ( V_14 -> V_120 ) ;
}
bool F_257 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
unsigned long V_3 ;
bool V_271 ;
if ( F_3 ( F_249 ( V_32 ) ) )
return false ;
F_39 ( V_3 ) ;
V_14 = F_126 ( V_32 ) ;
if ( F_3 ( ! F_70 ( V_14 ) ) ) {
V_271 = true ;
goto V_272;
}
F_26 ( V_14 ) ;
if ( F_71 ( V_14 -> V_120 , V_14 , V_15 ) ) {
F_58 ( V_14 -> V_120 , V_14 , V_15 , L_87 ) ;
V_271 = false ;
} else {
V_271 = true ;
}
F_28 ( V_14 ) ;
V_272:
F_40 ( V_3 ) ;
return V_271 ;
}
void F_7 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
F_258 ( V_214 , V_32 ) ;
if ( F_3 ( F_249 ( V_32 ) ) )
return;
V_14 = F_126 ( V_32 ) ;
if ( F_3 ( ! F_70 ( V_14 ) ) ) {
F_117 ( ! F_256 ( V_14 ) ) ;
F_259 ( V_32 ) ;
F_260 ( V_14 ) ;
return;
}
F_198 ( V_14 -> V_120 , V_14 , V_15 , V_214 ) ;
}
int F_261 ( struct V_1 * V_2 )
{
int V_13 ;
int V_49 ;
struct V_12 * V_40 ;
struct V_14 * V_14 ;
struct V_14 * V_73 ;
int V_17 = F_25 ( V_2 -> F_202 ) ;
struct V_156 * V_273 =
F_262 ( sizeof( struct V_156 ) * V_17 , V_245 ) ;
unsigned long V_3 ;
if ( ! V_273 )
return - V_274 ;
F_168 ( V_2 ) ;
F_217 (node, N_NORMAL_MEMORY) {
V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 -> V_159 )
continue;
for ( V_49 = 0 ; V_49 < V_17 ; V_49 ++ )
F_210 ( V_273 + V_49 ) ;
F_174 ( & V_40 -> V_162 , V_3 ) ;
F_231 (page, t, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_133 ( V_40 , V_14 ) ;
F_130 ( V_2 , V_14 ) ;
} else {
F_263 ( & V_14 -> V_111 ,
V_273 + V_14 -> V_27 ) ;
}
}
for ( V_49 = V_17 - 1 ; V_49 >= 0 ; V_49 -- )
F_264 ( V_273 + V_49 , V_40 -> V_160 . V_275 ) ;
F_175 ( & V_40 -> V_162 , V_3 ) ;
}
F_7 ( V_273 ) ;
return 0 ;
}
static int F_265 ( void * V_276 )
{
struct V_1 * V_2 ;
F_266 ( & V_258 ) ;
F_138 (s, &slab_caches, list)
F_261 ( V_2 ) ;
F_267 ( & V_258 ) ;
return 0 ;
}
static void F_268 ( void * V_276 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = V_276 ;
int V_279 ;
V_279 = V_278 -> V_280 ;
if ( V_279 < 0 )
return;
F_266 ( & V_258 ) ;
F_138 (s, &slab_caches, list) {
V_40 = F_12 ( V_2 , V_279 ) ;
if ( V_40 ) {
F_117 ( F_89 ( V_2 , V_279 ) ) ;
V_2 -> V_13 [ V_279 ] = NULL ;
F_199 ( V_12 , V_40 ) ;
}
}
F_267 ( & V_258 ) ;
}
static int F_269 ( void * V_276 )
{
struct V_12 * V_40 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = V_276 ;
int V_199 = V_278 -> V_280 ;
int V_213 = 0 ;
if ( V_199 < 0 )
return 0 ;
F_266 ( & V_258 ) ;
F_138 (s, &slab_caches, list) {
V_40 = F_187 ( V_12 , V_245 ) ;
if ( ! V_40 ) {
V_213 = - V_274 ;
goto V_119;
}
F_208 ( V_40 , V_2 ) ;
V_2 -> V_13 [ V_199 ] = V_40 ;
}
V_119:
F_267 ( & V_258 ) ;
return V_213 ;
}
static int F_270 ( struct V_281 * V_282 ,
unsigned long V_283 , void * V_276 )
{
int V_213 = 0 ;
switch ( V_283 ) {
case V_284 :
V_213 = F_269 ( V_276 ) ;
break;
case V_285 :
V_213 = F_265 ( V_276 ) ;
break;
case V_286 :
case V_287 :
F_268 ( V_276 ) ;
break;
case V_288 :
case V_289 :
break;
}
if ( V_213 )
V_213 = F_271 ( V_213 ) ;
else
V_213 = V_290 ;
return V_213 ;
}
static void T_8 F_272 ( struct V_1 * V_2 )
{
int V_13 ;
F_86 ( & V_2 -> V_259 , & V_263 ) ;
V_2 -> V_255 = - 1 ;
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
struct V_14 * V_5 ;
if ( V_40 ) {
F_138 (p, &n->partial, lru)
V_5 -> V_120 = V_2 ;
#ifdef F_2
F_138 (p, &n->full, lru)
V_5 -> V_120 = V_2 ;
#endif
}
}
}
void T_8 F_273 ( void )
{
int V_49 ;
int V_291 = 0 ;
struct V_1 * V_292 ;
int V_28 ;
struct V_1 * V_293 ;
unsigned long V_294 ;
V_253 = F_274 ( struct V_1 , V_13 ) +
V_295 * sizeof( struct V_12 * ) ;
V_294 = F_207 ( V_253 , F_206 () ) ;
V_28 = F_178 ( 2 * V_294 ) ;
V_1 = ( void * ) F_275 ( V_243 , V_28 ) ;
V_12 = ( void * ) V_1 + V_294 ;
F_221 ( V_12 , L_88 ,
sizeof( struct V_12 ) ,
0 , V_238 | V_256 , NULL ) ;
F_276 ( F_270 , V_296 ) ;
V_10 = V_297 ;
V_292 = V_1 ;
F_221 ( V_1 , L_89 , V_253 ,
0 , V_238 | V_256 , NULL ) ;
V_1 = F_187 ( V_1 , V_243 ) ;
memcpy ( V_1 , V_292 , V_253 ) ;
V_293 = V_12 ;
V_12 = F_187 ( V_1 , V_243 ) ;
memcpy ( V_12 , V_293 , V_253 ) ;
F_272 ( V_12 ) ;
V_291 ++ ;
F_272 ( V_1 ) ;
V_291 ++ ;
F_277 ( ( unsigned long ) V_292 , V_28 ) ;
F_213 ( V_298 > 256 ||
( V_298 & ( V_298 - 1 ) ) ) ;
for ( V_49 = 8 ; V_49 < V_298 ; V_49 += 8 ) {
int V_299 = F_244 ( V_49 ) ;
if ( V_299 >= F_278 ( V_266 ) )
break;
V_266 [ V_299 ] = V_300 ;
}
if ( V_298 == 64 ) {
for ( V_49 = 64 + 8 ; V_49 <= 96 ; V_49 += 8 )
V_266 [ F_244 ( V_49 ) ] = 7 ;
} else if ( V_298 == 128 ) {
for ( V_49 = 128 + 8 ; V_49 <= 192 ; V_49 += 8 )
V_266 [ F_244 ( V_49 ) ] = 8 ;
}
if ( V_298 <= 32 ) {
V_268 [ 1 ] = F_243 ( L_90 , 96 , 0 ) ;
V_291 ++ ;
}
if ( V_298 <= 64 ) {
V_268 [ 2 ] = F_243 ( L_91 , 192 , 0 ) ;
V_291 ++ ;
}
for ( V_49 = V_300 ; V_49 < V_242 ; V_49 ++ ) {
V_268 [ V_49 ] = F_243 ( L_92 , 1 << V_49 , 0 ) ;
V_291 ++ ;
}
V_10 = V_11 ;
if ( V_298 <= 32 ) {
V_268 [ 1 ] -> V_6 = F_279 ( V_268 [ 1 ] -> V_6 , V_243 ) ;
F_117 ( ! V_268 [ 1 ] -> V_6 ) ;
}
if ( V_298 <= 64 ) {
V_268 [ 2 ] -> V_6 = F_279 ( V_268 [ 2 ] -> V_6 , V_243 ) ;
F_117 ( ! V_268 [ 2 ] -> V_6 ) ;
}
for ( V_49 = V_300 ; V_49 < V_242 ; V_49 ++ ) {
char * V_2 = F_280 ( V_243 , L_93 , 1 << V_49 ) ;
F_117 ( ! V_2 ) ;
V_268 [ V_49 ] -> V_6 = V_2 ;
}
#ifdef F_281
F_282 ( & V_301 ) ;
#endif
#ifdef F_246
for ( V_49 = 0 ; V_49 < V_242 ; V_49 ++ ) {
struct V_1 * V_2 = V_268 [ V_49 ] ;
if ( V_2 && V_2 -> V_18 ) {
char * V_6 = F_280 ( V_243 ,
L_94 , V_2 -> V_24 ) ;
F_117 ( ! V_6 ) ;
V_267 [ V_49 ] = F_243 ( V_6 ,
V_2 -> V_24 , V_250 ) ;
}
}
#endif
F_37 ( V_45
L_95
L_96 ,
V_291 , F_206 () ,
V_228 , V_234 , V_232 ,
V_233 , V_295 ) ;
}
void T_8 F_283 ( void )
{
}
static int F_284 ( struct V_1 * V_2 )
{
if ( V_261 || ( V_2 -> V_3 & V_302 ) )
return 1 ;
if ( V_2 -> F_103 )
return 1 ;
if ( V_2 -> V_255 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_285 ( T_1 V_18 ,
T_1 V_237 , unsigned long V_3 , const char * V_6 ,
void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
if ( V_261 || ( V_3 & V_302 ) )
return NULL ;
if ( F_103 )
return NULL ;
V_18 = F_207 ( V_18 , sizeof( void * ) ) ;
V_237 = F_205 ( V_3 , V_237 , V_18 ) ;
V_18 = F_207 ( V_18 , V_237 ) ;
V_3 = F_102 ( V_18 , V_3 , V_6 , NULL ) ;
F_138 (s, &slab_caches, list) {
if ( F_284 ( V_2 ) )
continue;
if ( V_18 > V_2 -> V_18 )
continue;
if ( ( V_3 & V_303 ) != ( V_2 -> V_3 & V_303 ) )
continue;
if ( ( V_2 -> V_18 & ~ ( V_237 - 1 ) ) != V_2 -> V_18 )
continue;
if ( V_2 -> V_18 - V_18 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_286 ( const char * V_6 , T_1 V_18 ,
T_1 V_237 , unsigned long V_3 , void (* F_103)( void * ) )
{
struct V_1 * V_2 ;
char * V_40 ;
if ( F_255 ( ! V_6 ) )
return NULL ;
F_235 ( & V_258 ) ;
V_2 = F_285 ( V_18 , V_237 , V_3 , V_6 , F_103 ) ;
if ( V_2 ) {
V_2 -> V_255 ++ ;
V_2 -> V_24 = F_202 ( V_2 -> V_24 , ( int ) V_18 ) ;
V_2 -> V_27 = F_287 ( int , V_2 -> V_27 , F_207 ( V_18 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_255 -- ;
goto V_304;
}
F_237 ( & V_258 ) ;
return V_2 ;
}
V_40 = F_279 ( V_6 , V_245 ) ;
if ( ! V_40 )
goto V_304;
V_2 = F_262 ( V_253 , V_245 ) ;
if ( V_2 ) {
if ( F_221 ( V_2 , V_40 ,
V_18 , V_237 , V_3 , F_103 ) ) {
F_86 ( & V_2 -> V_259 , & V_263 ) ;
if ( F_4 ( V_2 ) ) {
F_88 ( & V_2 -> V_259 ) ;
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
goto V_304;
}
F_237 ( & V_258 ) ;
return V_2 ;
}
F_7 ( V_40 ) ;
F_7 ( V_2 ) ;
}
V_304:
F_237 ( & V_258 ) ;
if ( V_3 & V_256 )
F_224 ( L_97 , V_6 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int T_10 F_288 ( struct V_281 * V_305 ,
unsigned long V_283 , void * V_306 )
{
long V_66 = ( long ) V_306 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_283 ) {
case V_307 :
case V_308 :
case V_309 :
case V_310 :
F_266 ( & V_258 ) ;
F_138 (s, &slab_caches, list) {
F_39 ( V_3 ) ;
F_165 ( V_2 , V_66 ) ;
F_40 ( V_3 ) ;
}
F_267 ( & V_258 ) ;
break;
default:
break;
}
return V_290 ;
}
void * F_289 ( T_1 V_18 , T_6 V_198 , unsigned long V_311 )
{
struct V_1 * V_2 ;
void * V_213 ;
if ( F_3 ( V_18 > V_269 ) )
return F_248 ( V_18 , V_198 ) ;
V_2 = F_245 ( V_18 , V_198 ) ;
if ( F_3 ( F_249 ( V_2 ) ) )
return V_2 ;
V_213 = F_184 ( V_2 , V_198 , V_131 , V_311 ) ;
F_190 ( V_311 , V_213 , V_18 , V_2 -> V_18 , V_198 ) ;
return V_213 ;
}
void * F_290 ( T_1 V_18 , T_6 V_198 ,
int V_13 , unsigned long V_311 )
{
struct V_1 * V_2 ;
void * V_213 ;
if ( F_3 ( V_18 > V_269 ) ) {
V_213 = F_250 ( V_18 , V_198 , V_13 ) ;
F_196 ( V_311 , V_213 ,
V_18 , V_30 << F_178 ( V_18 ) ,
V_198 , V_13 ) ;
return V_213 ;
}
V_2 = F_245 ( V_18 , V_198 ) ;
if ( F_3 ( F_249 ( V_2 ) ) )
return V_2 ;
V_213 = F_184 ( V_2 , V_198 , V_13 , V_311 ) ;
F_196 ( V_311 , V_213 , V_18 , V_2 -> V_18 , V_198 , V_13 ) ;
return V_213 ;
}
static int F_291 ( struct V_14 * V_14 )
{
return V_14 -> V_27 ;
}
static int F_292 ( struct V_14 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_293 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_46 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
if ( ! F_69 ( V_2 , V_14 ) ||
! F_71 ( V_2 , V_14 , NULL ) )
return 0 ;
F_294 ( V_46 , V_14 -> V_17 ) ;
F_41 ( V_2 , V_14 , V_46 ) ;
F_119 (p, s, addr, page->objects) {
if ( F_229 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) )
if ( ! F_68 ( V_2 , V_14 , V_5 , V_115 ) )
return 0 ;
}
F_119 (p, s, addr, page->objects)
if ( ! F_229 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) )
if ( ! F_68 ( V_2 , V_14 , V_5 , V_99 ) )
return 0 ;
return 1 ;
}
static void F_295 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_46 )
{
F_26 ( V_14 ) ;
F_293 ( V_2 , V_14 , V_46 ) ;
F_28 ( V_14 ) ;
}
static int F_296 ( struct V_1 * V_2 ,
struct V_12 * V_40 , unsigned long * V_46 )
{
unsigned long V_312 = 0 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_174 ( & V_40 -> V_162 , V_3 ) ;
F_138 (page, &n->partial, lru) {
F_295 ( V_2 , V_14 , V_46 ) ;
V_312 ++ ;
}
if ( V_312 != V_40 -> V_159 )
F_37 ( V_52 L_98
L_99 , V_2 -> V_6 , V_312 , V_40 -> V_159 ) ;
if ( ! ( V_2 -> V_3 & V_26 ) )
goto V_119;
F_138 (page, &n->full, lru) {
F_295 ( V_2 , V_14 , V_46 ) ;
V_312 ++ ;
}
if ( V_312 != F_90 ( & V_40 -> V_113 ) )
F_37 ( V_52 L_100
L_99 , V_2 -> V_6 , V_312 ,
F_90 ( & V_40 -> V_113 ) ) ;
V_119:
F_175 ( & V_40 -> V_162 , V_3 ) ;
return V_312 ;
}
static long F_297 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_312 = 0 ;
unsigned long * V_46 = F_262 ( F_228 ( F_25 ( V_2 -> F_202 ) ) *
sizeof( unsigned long ) , V_245 ) ;
if ( ! V_46 )
return - V_274 ;
F_168 ( V_2 ) ;
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
V_312 += F_296 ( V_2 , V_40 , V_46 ) ;
}
F_7 ( V_46 ) ;
return V_312 ;
}
static void F_298 ( struct V_313 * V_73 )
{
if ( V_73 -> F_202 )
F_277 ( ( unsigned long ) V_73 -> V_314 ,
F_178 ( sizeof( struct V_315 ) * V_73 -> F_202 ) ) ;
}
static int F_299 ( struct V_313 * V_73 , unsigned long F_202 , T_6 V_3 )
{
struct V_315 * V_184 ;
int V_28 ;
V_28 = F_178 ( sizeof( struct V_315 ) * F_202 ) ;
V_184 = ( void * ) F_275 ( V_3 , V_28 ) ;
if ( ! V_184 )
return 0 ;
if ( V_73 -> V_312 ) {
memcpy ( V_184 , V_73 -> V_314 , sizeof( struct V_315 ) * V_73 -> V_312 ) ;
F_298 ( V_73 ) ;
}
V_73 -> F_202 = F_202 ;
V_73 -> V_314 = V_184 ;
return 1 ;
}
static int F_300 ( struct V_313 * V_73 , struct V_1 * V_2 ,
const struct V_54 * V_54 )
{
long V_82 , V_95 , V_316 ;
struct V_315 * V_184 ;
unsigned long V_317 ;
unsigned long V_318 = V_70 - V_54 -> V_69 ;
V_82 = - 1 ;
V_95 = V_73 -> V_312 ;
for ( ; ; ) {
V_316 = V_82 + ( V_95 - V_82 + 1 ) / 2 ;
if ( V_316 == V_95 )
break;
V_317 = V_73 -> V_314 [ V_316 ] . V_21 ;
if ( V_54 -> V_21 == V_317 ) {
V_184 = & V_73 -> V_314 [ V_316 ] ;
V_184 -> V_312 ++ ;
if ( V_54 -> V_69 ) {
V_184 -> V_319 += V_318 ;
if ( V_318 < V_184 -> V_320 )
V_184 -> V_320 = V_318 ;
if ( V_318 > V_184 -> V_321 )
V_184 -> V_321 = V_318 ;
if ( V_54 -> V_67 < V_184 -> V_322 )
V_184 -> V_322 = V_54 -> V_67 ;
if ( V_54 -> V_67 > V_184 -> V_323 )
V_184 -> V_323 = V_54 -> V_67 ;
F_301 ( V_54 -> V_66 ,
F_302 ( V_184 -> V_324 ) ) ;
}
F_303 ( F_118 ( F_304 ( V_54 ) ) , V_184 -> V_325 ) ;
return 1 ;
}
if ( V_54 -> V_21 < V_317 )
V_95 = V_316 ;
else
V_82 = V_316 ;
}
if ( V_73 -> V_312 >= V_73 -> F_202 && ! F_299 ( V_73 , 2 * V_73 -> F_202 , V_257 ) )
return 0 ;
V_184 = V_73 -> V_314 + V_316 ;
if ( V_316 < V_73 -> V_312 )
memmove ( V_184 + 1 , V_184 ,
( V_73 -> V_312 - V_316 ) * sizeof( struct V_315 ) ) ;
V_73 -> V_312 ++ ;
V_184 -> V_312 = 1 ;
V_184 -> V_21 = V_54 -> V_21 ;
V_184 -> V_319 = V_318 ;
V_184 -> V_320 = V_318 ;
V_184 -> V_321 = V_318 ;
V_184 -> V_322 = V_54 -> V_67 ;
V_184 -> V_323 = V_54 -> V_67 ;
F_305 ( F_302 ( V_184 -> V_324 ) ) ;
F_301 ( V_54 -> V_66 , F_302 ( V_184 -> V_324 ) ) ;
F_306 ( V_184 -> V_325 ) ;
F_303 ( F_118 ( F_304 ( V_54 ) ) , V_184 -> V_325 ) ;
return 1 ;
}
static void F_307 ( struct V_313 * V_73 , struct V_1 * V_2 ,
struct V_14 * V_14 , enum V_55 V_56 ,
unsigned long * V_46 )
{
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
F_294 ( V_46 , V_14 -> V_17 ) ;
F_41 ( V_2 , V_14 , V_46 ) ;
F_119 (p, s, addr, page->objects)
if ( ! F_229 ( F_20 ( V_5 , V_2 , V_21 ) , V_46 ) )
F_300 ( V_73 , V_2 , F_44 ( V_2 , V_5 , V_56 ) ) ;
}
static int F_308 ( struct V_1 * V_2 , char * V_75 ,
enum V_55 V_56 )
{
int V_326 = 0 ;
unsigned long V_49 ;
struct V_313 V_73 = { 0 , 0 , NULL } ;
int V_13 ;
unsigned long * V_46 = F_262 ( F_228 ( F_25 ( V_2 -> F_202 ) ) *
sizeof( unsigned long ) , V_245 ) ;
if ( ! V_46 || ! F_299 ( & V_73 , V_30 / sizeof( struct V_315 ) ,
V_327 ) ) {
F_7 ( V_46 ) ;
return sprintf ( V_75 , L_101 ) ;
}
F_168 ( V_2 ) ;
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
unsigned long V_3 ;
struct V_14 * V_14 ;
if ( ! F_90 ( & V_40 -> V_113 ) )
continue;
F_174 ( & V_40 -> V_162 , V_3 ) ;
F_138 (page, &n->partial, lru)
F_307 ( & V_73 , V_2 , V_14 , V_56 , V_46 ) ;
F_138 (page, &n->full, lru)
F_307 ( & V_73 , V_2 , V_14 , V_56 , V_46 ) ;
F_175 ( & V_40 -> V_162 , V_3 ) ;
}
for ( V_49 = 0 ; V_49 < V_73 . V_312 ; V_49 ++ ) {
struct V_315 * V_184 = & V_73 . V_314 [ V_49 ] ;
if ( V_326 > V_30 - V_328 - 100 )
break;
V_326 += sprintf ( V_75 + V_326 , L_102 , V_184 -> V_312 ) ;
if ( V_184 -> V_21 )
V_326 += sprintf ( V_75 + V_326 , L_103 , ( void * ) V_184 -> V_21 ) ;
else
V_326 += sprintf ( V_75 + V_326 , L_104 ) ;
if ( V_184 -> V_319 != V_184 -> V_320 ) {
V_326 += sprintf ( V_75 + V_326 , L_105 ,
V_184 -> V_320 ,
( long ) F_309 ( V_184 -> V_319 , V_184 -> V_312 ) ,
V_184 -> V_321 ) ;
} else
V_326 += sprintf ( V_75 + V_326 , L_106 ,
V_184 -> V_320 ) ;
if ( V_184 -> V_322 != V_184 -> V_323 )
V_326 += sprintf ( V_75 + V_326 , L_107 ,
V_184 -> V_322 , V_184 -> V_323 ) ;
else
V_326 += sprintf ( V_75 + V_326 , L_108 ,
V_184 -> V_322 ) ;
if ( F_310 () > 1 &&
! F_311 ( F_302 ( V_184 -> V_324 ) ) &&
V_326 < V_30 - 60 ) {
V_326 += sprintf ( V_75 + V_326 , L_109 ) ;
V_326 += F_312 ( V_75 + V_326 , V_30 - V_326 - 50 ,
F_302 ( V_184 -> V_324 ) ) ;
}
if ( V_329 > 1 && ! F_313 ( V_184 -> V_325 ) &&
V_326 < V_30 - 60 ) {
V_326 += sprintf ( V_75 + V_326 , L_110 ) ;
V_326 += F_314 ( V_75 + V_326 , V_30 - V_326 - 50 ,
V_184 -> V_325 ) ;
}
V_326 += sprintf ( V_75 + V_326 , L_111 ) ;
}
F_298 ( & V_73 ) ;
F_7 ( V_46 ) ;
if ( ! V_73 . V_312 )
V_326 += sprintf ( V_75 , L_112 ) ;
return V_326 ;
}
static void F_315 ( void )
{
T_3 * V_5 ;
F_213 ( V_298 > 16 || V_242 < 10 ) ;
F_37 ( V_52 L_113 ) ;
F_37 ( V_52 L_114 ) ;
F_37 ( V_52 L_115 ) ;
V_5 = F_227 ( 16 , V_245 ) ;
V_5 [ 16 ] = 0x12 ;
F_37 ( V_52 L_116
L_117 , V_5 + 16 ) ;
F_297 ( V_268 [ 4 ] ) ;
V_5 = F_227 ( 32 , V_245 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_37 ( V_52 L_118
L_119 , V_5 ) ;
F_37 ( V_52
L_120 ) ;
F_297 ( V_268 [ 5 ] ) ;
V_5 = F_227 ( 64 , V_245 ) ;
V_5 += 64 + ( F_143 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_37 ( V_52 L_121 ,
V_5 ) ;
F_37 ( V_52
L_120 ) ;
F_297 ( V_268 [ 6 ] ) ;
F_37 ( V_52 L_122 ) ;
V_5 = F_227 ( 128 , V_245 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_37 ( V_52 L_123 , V_5 ) ;
F_297 ( V_268 [ 7 ] ) ;
V_5 = F_227 ( 256 , V_245 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_37 ( V_52 L_124 ,
V_5 ) ;
F_297 ( V_268 [ 8 ] ) ;
V_5 = F_227 ( 512 , V_245 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_37 ( V_52 L_125 , V_5 ) ;
F_297 ( V_268 [ 9 ] ) ;
}
static void F_315 ( void ) {}
static T_11 F_316 ( struct V_1 * V_2 ,
char * V_75 , unsigned long V_3 )
{
unsigned long V_330 = 0 ;
int V_13 ;
int V_32 ;
unsigned long * V_325 ;
unsigned long * V_331 ;
V_325 = F_227 ( 2 * sizeof( unsigned long ) * V_295 , V_245 ) ;
if ( ! V_325 )
return - V_274 ;
V_331 = V_325 + V_295 ;
if ( V_3 & V_332 ) {
int V_66 ;
F_161 (cpu) {
struct V_177 * V_178 = F_162 ( V_2 -> V_9 , V_66 ) ;
if ( ! V_178 || V_178 -> V_13 < 0 )
continue;
if ( V_178 -> V_14 ) {
if ( V_3 & V_333 )
V_32 = V_178 -> V_14 -> V_17 ;
else if ( V_3 & V_334 )
V_32 = V_178 -> V_14 -> V_27 ;
else
V_32 = 1 ;
V_330 += V_32 ;
V_325 [ V_178 -> V_13 ] += V_32 ;
}
V_331 [ V_178 -> V_13 ] ++ ;
}
}
F_317 () ;
#ifdef F_2
if ( V_3 & V_335 ) {
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_333 )
V_32 = F_90 ( & V_40 -> V_114 ) ;
else if ( V_3 & V_334 )
V_32 = F_90 ( & V_40 -> V_114 ) -
F_172 ( V_40 , F_171 ) ;
else
V_32 = F_90 ( & V_40 -> V_113 ) ;
V_330 += V_32 ;
V_325 [ V_13 ] += V_32 ;
}
} else
#endif
if ( V_3 & V_336 ) {
F_217 (node, N_NORMAL_MEMORY) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_333 )
V_32 = F_172 ( V_40 , F_292 ) ;
else if ( V_3 & V_334 )
V_32 = F_172 ( V_40 , F_291 ) ;
else
V_32 = V_40 -> V_159 ;
V_330 += V_32 ;
V_325 [ V_13 ] += V_32 ;
}
}
V_32 = sprintf ( V_75 , L_126 , V_330 ) ;
#ifdef F_141
F_217 (node, N_NORMAL_MEMORY)
if ( V_325 [ V_13 ] )
V_32 += sprintf ( V_75 + V_32 , L_127 ,
V_13 , V_325 [ V_13 ] ) ;
#endif
F_318 () ;
F_7 ( V_325 ) ;
return V_32 + sprintf ( V_75 + V_32 , L_111 ) ;
}
static int F_319 ( struct V_1 * V_2 )
{
int V_13 ;
F_179 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
if ( F_90 ( & V_40 -> V_114 ) )
return 1 ;
}
return 0 ;
}
static T_11 F_320 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , V_2 -> V_18 ) ;
}
static T_11 F_321 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , V_2 -> V_237 ) ;
}
static T_11 F_322 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , V_2 -> V_24 ) ;
}
static T_11 F_323 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , F_25 ( V_2 -> V_129 ) ) ;
}
static T_11 F_324 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
unsigned long V_28 ;
int V_304 ;
V_304 = F_325 ( V_75 , 10 , & V_28 ) ;
if ( V_304 )
return V_304 ;
if ( V_28 > V_234 || V_28 < V_228 )
return - V_337 ;
F_220 ( V_2 , V_28 ) ;
return V_48 ;
}
static T_11 F_326 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , F_24 ( V_2 -> V_129 ) ) ;
}
static T_11 F_327 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_129 , V_2 -> V_171 ) ;
}
static T_11 F_328 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_48 )
{
unsigned long V_137 ;
int V_304 ;
V_304 = F_325 ( V_75 , 10 , & V_137 ) ;
if ( V_304 )
return V_304 ;
F_219 ( V_2 , V_137 ) ;
return V_48 ;
}
static T_11 F_329 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! V_2 -> F_103 )
return 0 ;
return sprintf ( V_75 , L_130 , V_2 -> F_103 ) ;
}
static T_11 F_330 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , V_2 -> V_255 - 1 ) ;
}
static T_11 F_331 ( struct V_1 * V_2 , char * V_75 )
{
return F_316 ( V_2 , V_75 , V_336 ) ;
}
static T_11 F_332 ( struct V_1 * V_2 , char * V_75 )
{
return F_316 ( V_2 , V_75 , V_332 ) ;
}
static T_11 F_333 ( struct V_1 * V_2 , char * V_75 )
{
return F_316 ( V_2 , V_75 , V_335 | V_334 ) ;
}
static T_11 F_334 ( struct V_1 * V_2 , char * V_75 )
{
return F_316 ( V_2 , V_75 , V_336 | V_334 ) ;
}
static T_11 F_335 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_142 ) ) ;
}
static T_11 F_336 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_142 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_142 ;
return V_48 ;
}
static T_11 F_337 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_238 ) ) ;
}
static T_11 F_338 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_250 ) ) ;
}
static T_11 F_339 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_25 ) ) ;
}
static T_11 F_340 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , V_2 -> V_29 ) ;
}
static T_11 F_341 ( struct V_1 * V_2 , char * V_75 )
{
return F_316 ( V_2 , V_75 , V_335 ) ;
}
static T_11 F_342 ( struct V_1 * V_2 , char * V_75 )
{
return F_316 ( V_2 , V_75 , V_335 | V_333 ) ;
}
static T_11 F_343 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_126 ) ) ;
}
static T_11 F_344 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
V_2 -> V_3 &= ~ V_126 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_126 ;
}
return V_48 ;
}
static T_11 F_345 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_105 ) ) ;
}
static T_11 F_346 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_105 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_105 ;
}
return V_48 ;
}
static T_11 F_347 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_11 F_348 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
if ( F_319 ( V_2 ) )
return - V_338 ;
V_2 -> V_3 &= ~ V_22 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_22 ;
}
F_220 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_11 F_349 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_11 F_350 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
if ( F_319 ( V_2 ) )
return - V_338 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_23 ;
}
F_220 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_11 F_351 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_26 ) ) ;
}
static T_11 F_352 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
if ( F_319 ( V_2 ) )
return - V_338 ;
V_2 -> V_3 &= ~ V_26 ;
if ( V_75 [ 0 ] == '1' ) {
V_2 -> V_3 &= ~ V_41 ;
V_2 -> V_3 |= V_26 ;
}
F_220 ( V_2 , - 1 ) ;
return V_48 ;
}
static T_11 F_353 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_11 F_354 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
int V_213 = - V_337 ;
if ( V_75 [ 0 ] == '1' ) {
V_213 = F_297 ( V_2 ) ;
if ( V_213 >= 0 )
V_213 = V_48 ;
}
return V_213 ;
}
static T_11 F_355 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_236 ;
return F_308 ( V_2 , V_75 , V_72 ) ;
}
static T_11 F_356 ( struct V_1 * V_2 , char * V_75 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_236 ;
return F_308 ( V_2 , V_75 , V_71 ) ;
}
static T_11 F_357 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , ! ! ( V_2 -> V_3 & V_127 ) ) ;
}
static T_11 F_358 ( struct V_1 * V_2 , const char * V_75 ,
T_1 V_48 )
{
V_2 -> V_3 &= ~ V_127 ;
if ( V_75 [ 0 ] == '1' )
V_2 -> V_3 |= V_127 ;
return V_48 ;
}
static T_11 F_359 ( struct V_1 * V_2 , char * V_75 )
{
return 0 ;
}
static T_11 F_360 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
if ( V_75 [ 0 ] == '1' ) {
int V_117 = F_261 ( V_2 ) ;
if ( V_117 )
return V_117 ;
} else
return - V_337 ;
return V_48 ;
}
static T_11 F_361 ( struct V_1 * V_2 , char * V_75 )
{
return sprintf ( V_75 , L_128 , V_2 -> V_169 / 10 ) ;
}
static T_11 F_362 ( struct V_1 * V_2 ,
const char * V_75 , T_1 V_48 )
{
unsigned long V_339 ;
int V_304 ;
V_304 = F_325 ( V_75 , 10 , & V_339 ) ;
if ( V_304 )
return V_304 ;
if ( V_339 <= 100 )
V_2 -> V_169 = V_339 * 10 ;
return V_48 ;
}
static int F_363 ( struct V_1 * V_2 , char * V_75 , enum V_7 V_8 )
{
unsigned long V_340 = 0 ;
int V_66 ;
int V_326 ;
int * V_90 = F_262 ( V_233 * sizeof( int ) , V_245 ) ;
if ( ! V_90 )
return - V_274 ;
F_364 (cpu) {
unsigned V_32 = F_162 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] ;
V_90 [ V_66 ] = V_32 ;
V_340 += V_32 ;
}
V_326 = sprintf ( V_75 , L_126 , V_340 ) ;
#ifdef F_281
F_364 (cpu) {
if ( V_90 [ V_66 ] && V_326 < V_30 - 20 )
V_326 += sprintf ( V_75 + V_326 , L_131 , V_66 , V_90 [ V_66 ] ) ;
}
#endif
F_7 ( V_90 ) ;
return V_326 + sprintf ( V_75 + V_326 , L_111 ) ;
}
static void F_365 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_66 ;
F_364 (cpu)
F_162 ( V_2 -> V_9 , V_66 ) -> F_8 [ V_8 ] = 0 ;
}
static T_11 F_366 ( struct V_341 * V_342 ,
struct V_343 * V_344 ,
char * V_75 )
{
struct V_345 * V_343 ;
struct V_1 * V_2 ;
int V_304 ;
V_343 = F_367 ( V_344 ) ;
V_2 = F_368 ( V_342 ) ;
if ( ! V_343 -> V_346 )
return - V_347 ;
V_304 = V_343 -> V_346 ( V_2 , V_75 ) ;
return V_304 ;
}
static T_11 F_369 ( struct V_341 * V_342 ,
struct V_343 * V_344 ,
const char * V_75 , T_1 V_326 )
{
struct V_345 * V_343 ;
struct V_1 * V_2 ;
int V_304 ;
V_343 = F_367 ( V_344 ) ;
V_2 = F_368 ( V_342 ) ;
if ( ! V_343 -> V_348 )
return - V_347 ;
V_304 = V_343 -> V_348 ( V_2 , V_75 , V_326 ) ;
return V_304 ;
}
static void F_370 ( struct V_341 * V_342 )
{
struct V_1 * V_2 = F_368 ( V_342 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_371 ( struct V_349 * V_349 , struct V_341 * V_342 )
{
struct V_350 * V_351 = F_372 ( V_342 ) ;
if ( V_351 == & V_352 )
return 1 ;
return 0 ;
}
static char * F_373 ( struct V_1 * V_2 )
{
char * V_6 = F_262 ( V_353 , V_245 ) ;
char * V_5 = V_6 ;
F_117 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_250 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_142 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_126 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_140 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_6 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_132 , V_2 -> V_18 ) ;
F_117 ( V_5 > V_6 + V_353 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_304 ;
const char * V_6 ;
int V_354 ;
if ( V_10 < V_355 )
return 0 ;
V_354 = F_284 ( V_2 ) ;
if ( V_354 ) {
F_374 ( & V_356 -> V_342 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_373 ( V_2 ) ;
}
V_2 -> V_342 . V_349 = V_356 ;
V_304 = F_375 ( & V_2 -> V_342 , & V_352 , NULL , V_6 ) ;
if ( V_304 ) {
F_376 ( & V_2 -> V_342 ) ;
return V_304 ;
}
V_304 = F_377 ( & V_2 -> V_342 , & V_357 ) ;
if ( V_304 ) {
F_378 ( & V_2 -> V_342 ) ;
F_376 ( & V_2 -> V_342 ) ;
return V_304 ;
}
F_379 ( & V_2 -> V_342 , V_358 ) ;
if ( ! V_354 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_10 < V_355 )
return;
F_379 ( & V_2 -> V_342 , V_359 ) ;
F_378 ( & V_2 -> V_342 ) ;
F_376 ( & V_2 -> V_342 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_360 * V_361 ;
if ( V_10 == V_355 ) {
F_374 ( & V_356 -> V_342 , V_6 ) ;
return F_380 ( & V_356 -> V_342 , & V_2 -> V_342 , V_6 ) ;
}
V_361 = F_262 ( sizeof( struct V_360 ) , V_245 ) ;
if ( ! V_361 )
return - V_274 ;
V_361 -> V_2 = V_2 ;
V_361 -> V_6 = V_6 ;
V_361 -> V_362 = V_363 ;
V_363 = V_361 ;
return 0 ;
}
static int T_8 F_381 ( void )
{
struct V_1 * V_2 ;
int V_304 ;
F_235 ( & V_258 ) ;
V_356 = F_382 ( L_133 , & V_364 , V_365 ) ;
if ( ! V_356 ) {
F_237 ( & V_258 ) ;
F_37 ( V_52 L_134 ) ;
return - V_236 ;
}
V_10 = V_355 ;
F_138 (s, &slab_caches, list) {
V_304 = F_4 ( V_2 ) ;
if ( V_304 )
F_37 ( V_52 L_135
L_136 , V_2 -> V_6 ) ;
}
while ( V_363 ) {
struct V_360 * V_361 = V_363 ;
V_363 = V_363 -> V_362 ;
V_304 = F_5 ( V_361 -> V_2 , V_361 -> V_6 ) ;
if ( V_304 )
F_37 ( V_52 L_137
L_138 , V_2 -> V_6 ) ;
F_7 ( V_361 ) ;
}
F_237 ( & V_258 ) ;
F_315 () ;
return 0 ;
}
static void F_383 ( struct V_366 * V_185 )
{
F_384 ( V_185 , L_139 ) ;
F_384 ( V_185 , L_140
L_141 ) ;
F_384 ( V_185 , L_142 ) ;
F_384 ( V_185 , L_143 ) ;
F_385 ( V_185 , '\n' ) ;
}
static void * F_386 ( struct V_366 * V_185 , T_12 * V_316 )
{
T_12 V_40 = * V_316 ;
F_266 ( & V_258 ) ;
if ( ! V_40 )
F_383 ( V_185 ) ;
return F_387 ( & V_263 , * V_316 ) ;
}
static void * F_388 ( struct V_366 * V_185 , void * V_5 , T_12 * V_316 )
{
return F_389 ( V_5 , & V_263 , V_316 ) ;
}
static void F_390 ( struct V_366 * V_185 , void * V_5 )
{
F_267 ( & V_258 ) ;
}
static int F_391 ( struct V_366 * V_185 , void * V_5 )
{
unsigned long V_367 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_368 = 0 ;
unsigned long V_201 = 0 ;
unsigned long V_202 = 0 ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_392 ( V_5 , struct V_1 , V_259 ) ;
F_179 (node) {
struct V_12 * V_40 = F_12 ( V_2 , V_13 ) ;
if ( ! V_40 )
continue;
V_367 += V_40 -> V_159 ;
V_113 += F_90 ( & V_40 -> V_113 ) ;
V_201 += F_90 ( & V_40 -> V_114 ) ;
V_202 += F_172 ( V_40 , F_171 ) ;
}
V_368 = V_201 - V_202 ;
F_393 ( V_185 , L_144 , V_2 -> V_6 , V_368 ,
V_201 , V_2 -> V_18 , F_25 ( V_2 -> V_129 ) ,
( 1 << F_24 ( V_2 -> V_129 ) ) ) ;
F_393 ( V_185 , L_145 , 0 , 0 , 0 ) ;
F_393 ( V_185 , L_146 , V_113 , V_113 ,
0UL ) ;
F_385 ( V_185 , '\n' ) ;
return 0 ;
}
static int F_394 ( struct V_369 * V_369 , struct V_370 * V_370 )
{
return F_395 ( V_370 , & V_371 ) ;
}
static int T_8 F_396 ( void )
{
F_397 ( L_147 , V_372 , NULL , & V_373 ) ;
return 0 ;
}
