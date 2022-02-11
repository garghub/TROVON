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
static void F_26 ( struct V_1 * V_2 , struct V_14 * V_14 , unsigned long * V_35 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
for ( V_5 = V_14 -> V_36 ; V_5 ; V_5 = F_15 ( V_2 , V_5 ) )
F_27 ( F_20 ( V_5 , V_2 , V_21 ) , V_35 ) ;
}
static void F_28 ( char * V_37 , T_2 * V_21 , unsigned int V_38 )
{
int V_39 , V_19 ;
int V_40 = 1 ;
char V_41 [ 17 ] ;
V_41 [ 16 ] = 0 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
if ( V_40 ) {
F_29 ( V_42 L_1 , V_37 , V_21 + V_39 ) ;
V_40 = 0 ;
}
F_29 ( V_43 L_2 , V_21 [ V_39 ] ) ;
V_19 = V_39 % 16 ;
V_41 [ V_19 ] = isgraph ( V_21 [ V_39 ] ) ? V_21 [ V_39 ] : '.' ;
if ( V_19 == 15 ) {
F_29 ( V_43 L_3 , V_41 ) ;
V_40 = 1 ;
}
}
if ( ! V_40 ) {
V_39 %= 16 ;
while ( V_39 < 16 ) {
F_29 ( V_43 L_4 ) ;
V_41 [ V_39 ] = ' ' ;
V_39 ++ ;
}
F_29 ( V_43 L_3 , V_41 ) ;
}
}
static struct V_44 * F_30 ( struct V_1 * V_2 , void * V_15 ,
enum V_45 V_46 )
{
struct V_44 * V_5 ;
if ( V_2 -> V_19 )
V_5 = V_15 + V_2 -> V_19 + sizeof( void * ) ;
else
V_5 = V_15 + V_2 -> V_27 ;
return V_5 + V_46 ;
}
static void F_31 ( struct V_1 * V_2 , void * V_15 ,
enum V_45 V_46 , unsigned long V_21 )
{
struct V_44 * V_5 = F_30 ( V_2 , V_15 , V_46 ) ;
if ( V_21 ) {
V_5 -> V_21 = V_21 ;
V_5 -> V_47 = F_32 () ;
V_5 -> V_48 = V_49 -> V_48 ;
V_5 -> V_50 = V_51 ;
} else
memset ( V_5 , 0 , sizeof( struct V_44 ) ) ;
}
static void F_33 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_31 ( V_2 , V_15 , V_52 , 0UL ) ;
F_31 ( V_2 , V_15 , V_53 , 0UL ) ;
}
static void F_34 ( const char * V_2 , struct V_44 * V_54 )
{
if ( ! V_54 -> V_21 )
return;
F_29 ( V_42 L_5 ,
V_2 , ( void * ) V_54 -> V_21 , V_51 - V_54 -> V_50 , V_54 -> V_47 , V_54 -> V_48 ) ;
}
static void F_35 ( struct V_1 * V_2 , void * V_15 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
F_34 ( L_6 , F_30 ( V_2 , V_15 , V_53 ) ) ;
F_34 ( L_7 , F_30 ( V_2 , V_15 , V_52 ) ) ;
}
static void F_36 ( struct V_14 * V_14 )
{
F_29 ( V_42 L_8 ,
V_14 , V_14 -> V_17 , V_14 -> V_27 , V_14 -> V_36 , V_14 -> V_3 ) ;
}
static void F_37 ( struct V_1 * V_2 , char * V_55 , ... )
{
T_3 args ;
char V_56 [ 100 ] ;
va_start ( args , V_55 ) ;
vsnprintf ( V_56 , sizeof( V_56 ) , V_55 , args ) ;
va_end ( args ) ;
F_29 ( V_42 L_9
L_10 ) ;
F_29 ( V_42 L_11 , V_2 -> V_6 , V_56 ) ;
F_29 ( V_42 L_12
L_13 ) ;
}
static void F_38 ( struct V_1 * V_2 , char * V_55 , ... )
{
T_3 args ;
char V_56 [ 100 ] ;
va_start ( args , V_55 ) ;
vsnprintf ( V_56 , sizeof( V_56 ) , V_55 , args ) ;
va_end ( args ) ;
F_29 ( V_42 L_14 , V_2 -> V_6 , V_56 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_14 * V_14 , T_2 * V_5 )
{
unsigned int V_57 ;
T_2 * V_21 = F_14 ( V_14 ) ;
F_35 ( V_2 , V_5 ) ;
F_36 ( V_14 ) ;
F_29 ( V_42 L_15 ,
V_5 , V_5 - V_21 , F_15 ( V_2 , V_5 ) ) ;
if ( V_5 > V_21 + 16 )
F_28 ( L_16 , V_5 - 16 , 16 ) ;
F_28 ( L_17 , V_5 , F_40 (unsigned long, s->objsize, PAGE_SIZE) ) ;
if ( V_2 -> V_3 & V_22 )
F_28 ( L_18 , V_5 + V_2 -> V_24 ,
V_2 -> V_27 - V_2 -> V_24 ) ;
if ( V_2 -> V_19 )
V_57 = V_2 -> V_19 + sizeof( void * ) ;
else
V_57 = V_2 -> V_27 ;
if ( V_2 -> V_3 & V_26 )
V_57 += 2 * sizeof( struct V_44 ) ;
if ( V_57 != V_2 -> V_18 )
F_28 ( L_19 , V_5 + V_57 , V_2 -> V_18 - V_57 ) ;
F_41 () ;
}
static void F_42 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_2 * V_15 , char * V_58 )
{
F_37 ( V_2 , L_20 , V_58 ) ;
F_39 ( V_2 , V_14 , V_15 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_14 * V_14 , char * V_55 , ... )
{
T_3 args ;
char V_56 [ 100 ] ;
va_start ( args , V_55 ) ;
vsnprintf ( V_56 , sizeof( V_56 ) , V_55 , args ) ;
va_end ( args ) ;
F_37 ( V_2 , L_20 , V_56 ) ;
F_36 ( V_14 ) ;
F_41 () ;
}
static void F_44 ( struct V_1 * V_2 , void * V_15 , T_2 V_59 )
{
T_2 * V_5 = V_15 ;
if ( V_2 -> V_3 & V_60 ) {
memset ( V_5 , V_61 , V_2 -> V_24 - 1 ) ;
V_5 [ V_2 -> V_24 - 1 ] = V_62 ;
}
if ( V_2 -> V_3 & V_22 )
memset ( V_5 + V_2 -> V_24 , V_59 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
static T_2 * F_45 ( T_2 * V_63 , unsigned int V_64 , unsigned int V_65 )
{
while ( V_65 ) {
if ( * V_63 != ( T_2 ) V_64 )
return V_63 ;
V_63 ++ ;
V_65 -- ;
}
return NULL ;
}
static void F_46 ( struct V_1 * V_2 , char * V_66 , T_2 V_67 ,
void * V_68 , void * V_69 )
{
F_38 ( V_2 , L_21 , V_68 , V_69 - 1 , V_67 ) ;
memset ( V_68 , V_67 , V_69 - V_68 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_14 * V_14 ,
T_2 * V_15 , char * V_70 ,
T_2 * V_63 , unsigned int V_64 , unsigned int V_65 )
{
T_2 * V_71 ;
T_2 * V_72 ;
V_71 = F_45 ( V_63 , V_64 , V_65 ) ;
if ( ! V_71 )
return 1 ;
V_72 = V_63 + V_65 ;
while ( V_72 > V_71 && V_72 [ - 1 ] == V_64 )
V_72 -- ;
F_37 ( V_2 , L_22 , V_70 ) ;
F_29 ( V_42 L_23 ,
V_71 , V_72 - 1 , V_71 [ 0 ] , V_64 ) ;
F_39 ( V_2 , V_14 , V_15 ) ;
F_46 ( V_2 , V_70 , V_64 , V_71 , V_72 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_14 * V_14 , T_2 * V_5 )
{
unsigned long V_57 = V_2 -> V_27 ;
if ( V_2 -> V_19 )
V_57 += sizeof( void * ) ;
if ( V_2 -> V_3 & V_26 )
V_57 += 2 * sizeof( struct V_44 ) ;
if ( V_2 -> V_18 == V_57 )
return 1 ;
return F_47 ( V_2 , V_14 , V_5 , L_24 ,
V_5 + V_57 , V_73 , V_2 -> V_18 - V_57 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
T_2 * V_63 ;
T_2 * V_71 ;
T_2 * V_72 ;
int V_38 ;
int V_74 ;
if ( ! ( V_2 -> V_3 & V_23 ) )
return 1 ;
V_63 = F_14 ( V_14 ) ;
V_38 = ( V_30 << F_50 ( V_14 ) ) - V_2 -> V_29 ;
V_72 = V_63 + V_38 ;
V_74 = V_38 % V_2 -> V_18 ;
if ( ! V_74 )
return 1 ;
V_71 = F_45 ( V_72 - V_74 , V_73 , V_74 ) ;
if ( ! V_71 )
return 1 ;
while ( V_72 > V_71 && V_72 [ - 1 ] == V_73 )
V_72 -- ;
F_43 ( V_2 , V_14 , L_25 , V_71 , V_72 - 1 ) ;
F_28 ( L_19 , V_72 - V_74 , V_74 ) ;
F_46 ( V_2 , L_26 , V_73 , V_72 - V_74 , V_72 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_2 V_59 )
{
T_2 * V_5 = V_15 ;
T_2 * V_75 = V_15 + V_2 -> V_24 ;
if ( V_2 -> V_3 & V_22 ) {
if ( ! F_47 ( V_2 , V_14 , V_15 , L_18 ,
V_75 , V_59 , V_2 -> V_27 - V_2 -> V_24 ) )
return 0 ;
} else {
if ( ( V_2 -> V_3 & V_23 ) && V_2 -> V_24 < V_2 -> V_27 ) {
F_47 ( V_2 , V_14 , V_5 , L_27 ,
V_75 , V_73 , V_2 -> V_27 - V_2 -> V_24 ) ;
}
}
if ( V_2 -> V_3 & V_23 ) {
if ( V_59 != V_76 && ( V_2 -> V_3 & V_60 ) &&
( ! F_47 ( V_2 , V_14 , V_5 , L_28 , V_5 ,
V_61 , V_2 -> V_24 - 1 ) ||
! F_47 ( V_2 , V_14 , V_5 , L_28 ,
V_5 + V_2 -> V_24 - 1 , V_62 , 1 ) ) )
return 0 ;
F_48 ( V_2 , V_14 , V_5 ) ;
}
if ( ! V_2 -> V_19 && V_59 == V_76 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , F_15 ( V_2 , V_5 ) ) ) {
F_42 ( V_2 , V_14 , V_5 , L_29 ) ;
F_19 ( V_2 , V_5 , NULL ) ;
return 0 ;
}
return 1 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_77 ;
F_53 ( ! F_54 () ) ;
if ( ! F_55 ( V_14 ) ) {
F_43 ( V_2 , V_14 , L_30 ) ;
return 0 ;
}
V_77 = F_22 ( F_50 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_14 -> V_17 > V_77 ) {
F_43 ( V_2 , V_14 , L_31 ,
V_2 -> V_6 , V_14 -> V_17 , V_77 ) ;
return 0 ;
}
if ( V_14 -> V_27 > V_14 -> V_17 ) {
F_43 ( V_2 , V_14 , L_32 ,
V_2 -> V_6 , V_14 -> V_27 , V_14 -> V_17 ) ;
return 0 ;
}
F_49 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_78 )
{
int V_79 = 0 ;
void * V_20 = V_14 -> V_36 ;
void * V_15 = NULL ;
unsigned long V_80 ;
while ( V_20 && V_79 <= V_14 -> V_17 ) {
if ( V_20 == V_78 )
return 1 ;
if ( ! F_13 ( V_2 , V_14 , V_20 ) ) {
if ( V_15 ) {
F_42 ( V_2 , V_14 , V_15 ,
L_33 ) ;
F_19 ( V_2 , V_15 , NULL ) ;
break;
} else {
F_43 ( V_2 , V_14 , L_29 ) ;
V_14 -> V_36 = NULL ;
V_14 -> V_27 = V_14 -> V_17 ;
F_38 ( V_2 , L_34 ) ;
return 0 ;
}
break;
}
V_15 = V_20 ;
V_20 = F_15 ( V_2 , V_15 ) ;
V_79 ++ ;
}
V_80 = F_22 ( F_50 ( V_14 ) , V_2 -> V_18 , V_2 -> V_29 ) ;
if ( V_80 > V_81 )
V_80 = V_81 ;
if ( V_14 -> V_17 != V_80 ) {
F_43 ( V_2 , V_14 , L_35
L_36 , V_14 -> V_17 , V_80 ) ;
V_14 -> V_17 = V_80 ;
F_38 ( V_2 , L_37 ) ;
}
if ( V_14 -> V_27 != V_14 -> V_17 - V_79 ) {
F_43 ( V_2 , V_14 , L_38
L_39 , V_14 -> V_27 , V_14 -> V_17 - V_79 ) ;
V_14 -> V_27 = V_14 -> V_17 - V_79 ;
F_38 ( V_2 , L_40 ) ;
}
return V_78 == NULL ;
}
static void F_57 ( struct V_1 * V_2 , struct V_14 * V_14 , void * V_15 ,
int V_46 )
{
if ( V_2 -> V_3 & V_82 ) {
F_29 ( V_83 L_41 ,
V_2 -> V_6 ,
V_46 ? L_42 : L_43 ,
V_15 , V_14 -> V_27 ,
V_14 -> V_36 ) ;
if ( ! V_46 )
F_28 ( L_17 , ( void * ) V_15 , V_2 -> V_24 ) ;
F_41 () ;
}
}
static inline int F_58 ( struct V_1 * V_2 , T_4 V_3 )
{
V_3 &= V_84 ;
F_59 ( V_3 ) ;
F_60 ( V_3 & V_85 ) ;
return F_61 ( V_2 -> V_24 , V_3 , V_2 -> V_3 ) ;
}
static inline void F_62 ( struct V_1 * V_2 , T_4 V_3 , void * V_15 )
{
V_3 &= V_84 ;
F_63 ( V_2 , V_3 , V_15 , F_21 ( V_2 ) ) ;
F_64 ( V_15 , V_2 -> V_24 , 1 , V_2 -> V_3 , V_3 ) ;
}
static inline void F_65 ( struct V_1 * V_2 , void * V_32 )
{
F_66 ( V_32 , V_2 -> V_3 ) ;
#if F_67 ( V_86 ) || F_67 ( V_87 )
{
unsigned long V_3 ;
F_68 ( V_3 ) ;
F_69 ( V_2 , V_32 , V_2 -> V_24 ) ;
F_70 ( V_32 , V_2 -> V_24 ) ;
F_71 ( V_3 ) ;
}
#endif
if ( ! ( V_2 -> V_3 & V_88 ) )
F_72 ( V_32 , V_2 -> V_24 ) ;
}
static void F_73 ( struct V_12 * V_89 , struct V_14 * V_14 )
{
F_74 ( & V_89 -> V_90 ) ;
F_75 ( & V_14 -> V_91 , & V_89 -> V_92 ) ;
F_76 ( & V_89 -> V_90 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_12 * V_89 ;
if ( ! ( V_2 -> V_3 & V_26 ) )
return;
V_89 = F_12 ( V_2 , F_78 ( V_14 ) ) ;
F_74 ( & V_89 -> V_90 ) ;
F_79 ( & V_14 -> V_91 ) ;
F_76 ( & V_89 -> V_90 ) ;
}
static inline unsigned long F_80 ( struct V_1 * V_2 , int V_13 )
{
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
return F_81 ( & V_89 -> V_93 ) ;
}
static inline unsigned long F_82 ( struct V_12 * V_89 )
{
return F_81 ( & V_89 -> V_93 ) ;
}
static inline void F_83 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
if ( V_89 ) {
F_84 ( & V_89 -> V_93 ) ;
F_85 ( V_17 , & V_89 -> V_94 ) ;
}
}
static inline void F_86 ( struct V_1 * V_2 , int V_13 , int V_17 )
{
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
F_87 ( & V_89 -> V_93 ) ;
F_88 ( V_17 , & V_89 -> V_94 ) ;
}
static void F_89 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
if ( ! ( V_2 -> V_3 & ( V_26 | V_22 | V_60 ) ) )
return;
F_44 ( V_2 , V_15 , V_95 ) ;
F_33 ( V_2 , V_15 ) ;
}
static T_5 int F_90 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , unsigned long V_21 )
{
if ( ! F_52 ( V_2 , V_14 ) )
goto V_96;
if ( ! F_56 ( V_2 , V_14 , V_15 ) ) {
F_42 ( V_2 , V_14 , V_15 , L_44 ) ;
goto V_96;
}
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_42 ( V_2 , V_14 , V_15 , L_45 ) ;
goto V_96;
}
if ( ! F_51 ( V_2 , V_14 , V_15 , V_95 ) )
goto V_96;
if ( V_2 -> V_3 & V_26 )
F_31 ( V_2 , V_15 , V_53 , V_21 ) ;
F_57 ( V_2 , V_14 , V_15 , 1 ) ;
F_44 ( V_2 , V_15 , V_76 ) ;
return 1 ;
V_96:
if ( F_55 ( V_14 ) ) {
F_38 ( V_2 , L_46 ) ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_36 = NULL ;
}
return 0 ;
}
static T_5 int F_91 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 )
{
if ( ! F_52 ( V_2 , V_14 ) )
goto V_97;
if ( ! F_13 ( V_2 , V_14 , V_15 ) ) {
F_43 ( V_2 , V_14 , L_47 , V_15 ) ;
goto V_97;
}
if ( F_56 ( V_2 , V_14 , V_15 ) ) {
F_42 ( V_2 , V_14 , V_15 , L_48 ) ;
goto V_97;
}
if ( ! F_51 ( V_2 , V_14 , V_15 , V_76 ) )
return 0 ;
if ( F_3 ( V_2 != V_14 -> V_98 ) ) {
if ( ! F_55 ( V_14 ) ) {
F_43 ( V_2 , V_14 , L_49
L_50 , V_15 ) ;
} else if ( ! V_14 -> V_98 ) {
F_29 ( V_42
L_51 ,
V_15 ) ;
F_41 () ;
} else
F_42 ( V_2 , V_14 , V_15 ,
L_52 ) ;
goto V_97;
}
if ( ! F_92 ( V_14 ) && ! V_14 -> V_36 )
F_77 ( V_2 , V_14 ) ;
if ( V_2 -> V_3 & V_26 )
F_31 ( V_2 , V_15 , V_52 , V_21 ) ;
F_57 ( V_2 , V_14 , V_15 , 0 ) ;
F_44 ( V_2 , V_15 , V_95 ) ;
return 1 ;
V_97:
F_38 ( V_2 , L_53 , V_15 ) ;
return 0 ;
}
static int T_6 F_93 ( char * V_99 )
{
V_100 = V_101 ;
if ( * V_99 ++ != '=' || ! * V_99 )
goto V_102;
if ( * V_99 == ',' )
goto V_103;
if ( tolower ( * V_99 ) == 'o' ) {
V_104 = 1 ;
goto V_102;
}
V_100 = 0 ;
if ( * V_99 == '-' )
goto V_102;
for (; * V_99 && * V_99 != ',' ; V_99 ++ ) {
switch ( tolower ( * V_99 ) ) {
case 'f' :
V_100 |= V_105 ;
break;
case 'z' :
V_100 |= V_22 ;
break;
case 'p' :
V_100 |= V_23 ;
break;
case 'u' :
V_100 |= V_26 ;
break;
case 't' :
V_100 |= V_82 ;
break;
case 'a' :
V_100 |= V_106 ;
break;
default:
F_29 ( V_42 L_54
L_55 , * V_99 ) ;
}
}
V_103:
if ( * V_99 == ',' )
V_107 = V_99 + 1 ;
V_102:
return 1 ;
}
static unsigned long F_94 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_95)( void * ) )
{
if ( V_100 && ( ! V_107 ||
! strncmp ( V_107 , V_6 , strlen ( V_107 ) ) ) )
V_3 |= V_100 ;
return V_3 ;
}
static inline void F_89 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 ) {}
static inline int F_90 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_91 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_15 , unsigned long V_21 ) { return 0 ; }
static inline int F_49 ( struct V_1 * V_2 , struct V_14 * V_14 )
{ return 1 ; }
static inline int F_51 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 , T_2 V_59 ) { return 1 ; }
static inline void F_73 ( struct V_12 * V_89 , struct V_14 * V_14 ) {}
static inline unsigned long F_94 ( unsigned long V_24 ,
unsigned long V_3 , const char * V_6 ,
void (* F_95)( void * ) )
{
return V_3 ;
}
static inline unsigned long F_80 ( struct V_1 * V_2 , int V_13 )
{ return 0 ; }
static inline unsigned long F_82 ( struct V_12 * V_89 )
{ return 0 ; }
static inline void F_83 ( struct V_1 * V_2 , int V_13 ,
int V_17 ) {}
static inline void F_86 ( struct V_1 * V_2 , int V_13 ,
int V_17 ) {}
static inline int F_58 ( struct V_1 * V_2 , T_4 V_3 )
{ return 0 ; }
static inline void F_62 ( struct V_1 * V_2 , T_4 V_3 ,
void * V_15 ) {}
static inline void F_65 ( struct V_1 * V_2 , void * V_32 ) {}
static inline struct V_14 * F_96 ( T_4 V_3 , int V_13 ,
struct V_31 V_108 )
{
int V_28 = F_24 ( V_108 ) ;
V_3 |= V_109 ;
if ( V_13 == V_110 )
return F_97 ( V_3 , V_28 ) ;
else
return F_98 ( V_13 , V_3 , V_28 ) ;
}
static struct V_14 * F_99 ( struct V_1 * V_2 , T_4 V_3 , int V_13 )
{
struct V_14 * V_14 ;
struct V_31 V_108 = V_2 -> V_108 ;
T_4 V_111 ;
V_3 |= V_2 -> V_112 ;
V_111 = ( V_3 | V_113 | V_114 ) & ~ V_115 ;
V_14 = F_96 ( V_111 , V_13 , V_108 ) ;
if ( F_3 ( ! V_14 ) ) {
V_108 = V_2 -> V_116 ;
V_14 = F_96 ( V_3 , V_13 , V_108 ) ;
if ( ! V_14 )
return NULL ;
F_8 ( V_2 , V_117 ) ;
}
if ( V_118
&& ! ( V_2 -> V_3 & ( V_119 | V_101 ) ) ) {
int V_120 = 1 << F_24 ( V_108 ) ;
F_100 ( V_14 , F_24 ( V_108 ) , V_3 , V_13 ) ;
if ( V_2 -> F_95 )
F_101 ( V_14 , V_120 ) ;
else
F_102 ( V_14 , V_120 ) ;
}
V_14 -> V_17 = F_25 ( V_108 ) ;
F_103 ( F_104 ( V_14 ) ,
( V_2 -> V_3 & V_121 ) ?
V_122 : V_123 ,
1 << F_24 ( V_108 ) ) ;
return V_14 ;
}
static void F_105 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_15 )
{
F_89 ( V_2 , V_14 , V_15 ) ;
if ( F_3 ( V_2 -> F_95 ) )
V_2 -> F_95 ( V_15 ) ;
}
static struct V_14 * F_106 ( struct V_1 * V_2 , T_4 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_63 ;
void * V_124 ;
void * V_5 ;
F_107 ( V_3 & V_125 ) ;
V_14 = F_99 ( V_2 ,
V_3 & ( V_126 | V_127 ) , V_13 ) ;
if ( ! V_14 )
goto V_102;
F_83 ( V_2 , F_78 ( V_14 ) , V_14 -> V_17 ) ;
V_14 -> V_98 = V_2 ;
V_14 -> V_3 |= 1 << V_128 ;
V_63 = F_14 ( V_14 ) ;
if ( F_3 ( V_2 -> V_3 & V_23 ) )
memset ( V_63 , V_73 , V_30 << F_50 ( V_14 ) ) ;
V_124 = V_63 ;
F_108 (p, s, start, page->objects) {
F_105 ( V_2 , V_14 , V_124 ) ;
F_19 ( V_2 , V_124 , V_5 ) ;
V_124 = V_5 ;
}
F_105 ( V_2 , V_14 , V_124 ) ;
F_19 ( V_2 , V_124 , NULL ) ;
V_14 -> V_36 = V_63 ;
V_14 -> V_27 = 0 ;
V_102:
return V_14 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_28 = F_50 ( V_14 ) ;
int V_120 = 1 << V_28 ;
if ( F_1 ( V_2 ) ) {
void * V_5 ;
F_49 ( V_2 , V_14 ) ;
F_108 (p, s, page_address(page),
page->objects)
F_51 ( V_2 , V_14 , V_5 , V_95 ) ;
}
F_110 ( V_14 , F_50 ( V_14 ) ) ;
F_103 ( F_104 ( V_14 ) ,
( V_2 -> V_3 & V_121 ) ?
V_122 : V_123 ,
- V_120 ) ;
F_111 ( V_14 ) ;
F_112 ( V_14 ) ;
if ( V_49 -> V_129 )
V_49 -> V_129 -> V_130 += V_120 ;
F_113 ( V_14 , V_28 ) ;
}
static void F_114 ( struct V_131 * V_132 )
{
struct V_14 * V_14 ;
if ( V_133 )
V_14 = F_115 ( V_132 ) ;
else
V_14 = F_116 ( (struct V_134 * ) V_132 , struct V_14 , V_91 ) ;
F_109 ( V_14 -> V_98 , V_14 ) ;
}
static void F_117 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( F_3 ( V_2 -> V_3 & V_25 ) ) {
struct V_131 * V_135 ;
if ( V_133 ) {
int V_28 = F_50 ( V_14 ) ;
int V_19 = ( V_30 << V_28 ) - V_2 -> V_29 ;
F_53 ( V_2 -> V_29 != sizeof( * V_135 ) ) ;
V_135 = F_14 ( V_14 ) + V_19 ;
} else {
V_135 = ( void * ) & V_14 -> V_91 ;
}
F_118 ( V_135 , F_114 ) ;
} else
F_109 ( V_2 , V_14 ) ;
}
static void F_119 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
F_86 ( V_2 , F_78 ( V_14 ) , V_14 -> V_17 ) ;
F_117 ( V_2 , V_14 ) ;
}
static T_7 void F_120 ( struct V_14 * V_14 )
{
F_121 ( V_136 , & V_14 -> V_3 ) ;
}
static T_7 void F_122 ( struct V_14 * V_14 )
{
F_123 ( V_136 , & V_14 -> V_3 ) ;
}
static T_7 int F_124 ( struct V_14 * V_14 )
{
int V_137 = 1 ;
V_137 = F_125 ( V_136 , & V_14 -> V_3 ) ;
return V_137 ;
}
static void F_126 ( struct V_12 * V_89 ,
struct V_14 * V_14 , int V_138 )
{
F_74 ( & V_89 -> V_90 ) ;
V_89 -> V_139 ++ ;
if ( V_138 )
F_127 ( & V_14 -> V_91 , & V_89 -> V_140 ) ;
else
F_75 ( & V_14 -> V_91 , & V_89 -> V_140 ) ;
F_76 ( & V_89 -> V_90 ) ;
}
static inline void F_128 ( struct V_12 * V_89 ,
struct V_14 * V_14 )
{
F_79 ( & V_14 -> V_91 ) ;
V_89 -> V_139 -- ;
}
static void F_129 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_12 * V_89 = F_12 ( V_2 , F_78 ( V_14 ) ) ;
F_74 ( & V_89 -> V_90 ) ;
F_128 ( V_89 , V_14 ) ;
F_76 ( & V_89 -> V_90 ) ;
}
static inline int F_130 ( struct V_12 * V_89 ,
struct V_14 * V_14 )
{
if ( F_124 ( V_14 ) ) {
F_128 ( V_89 , V_14 ) ;
F_131 ( V_14 ) ;
return 1 ;
}
return 0 ;
}
static struct V_14 * F_132 ( struct V_12 * V_89 )
{
struct V_14 * V_14 ;
if ( ! V_89 || ! V_89 -> V_139 )
return NULL ;
F_74 ( & V_89 -> V_90 ) ;
F_133 (page, &n->partial, lru)
if ( F_130 ( V_89 , V_14 ) )
goto V_102;
V_14 = NULL ;
V_102:
F_76 ( & V_89 -> V_90 ) ;
return V_14 ;
}
static struct V_14 * F_134 ( struct V_1 * V_2 , T_4 V_3 )
{
#ifdef F_135
struct V_141 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_144 ;
enum V_145 V_146 = F_136 ( V_3 ) ;
struct V_14 * V_14 ;
if ( ! V_2 -> V_147 ||
F_137 () % 1024 > V_2 -> V_147 )
return NULL ;
F_138 () ;
V_141 = F_139 ( F_140 ( V_49 -> V_148 ) , V_3 ) ;
F_141 (zone, z, zonelist, high_zoneidx) {
struct V_12 * V_89 ;
V_89 = F_12 ( V_2 , F_142 ( V_144 ) ) ;
if ( V_89 && F_143 ( V_144 , V_3 ) &&
V_89 -> V_139 > V_2 -> V_149 ) {
V_14 = F_132 ( V_89 ) ;
if ( V_14 ) {
F_144 () ;
return V_14 ;
}
}
}
F_144 () ;
#endif
return NULL ;
}
static struct V_14 * F_145 ( struct V_1 * V_2 , T_4 V_3 , int V_13 )
{
struct V_14 * V_14 ;
int V_150 = ( V_13 == V_110 ) ? F_146 () : V_13 ;
V_14 = F_132 ( F_12 ( V_2 , V_150 ) ) ;
if ( V_14 || V_13 != V_110 )
return V_14 ;
return F_134 ( V_2 , V_3 ) ;
}
static void F_147 ( struct V_1 * V_2 , struct V_14 * V_14 , int V_138 )
__releases( T_8 )
{
struct V_12 * V_89 = F_12 ( V_2 , F_78 ( V_14 ) ) ;
F_148 ( V_14 ) ;
if ( V_14 -> V_27 ) {
if ( V_14 -> V_36 ) {
F_126 ( V_89 , V_14 , V_138 ) ;
F_8 ( V_2 , V_138 ? V_151 : V_152 ) ;
} else {
F_8 ( V_2 , V_153 ) ;
if ( F_1 ( V_2 ) && ( V_2 -> V_3 & V_26 ) )
F_73 ( V_89 , V_14 ) ;
}
F_122 ( V_14 ) ;
} else {
F_8 ( V_2 , V_154 ) ;
if ( V_89 -> V_139 < V_2 -> V_149 ) {
F_126 ( V_89 , V_14 , 1 ) ;
F_122 ( V_14 ) ;
} else {
F_122 ( V_14 ) ;
F_8 ( V_2 , V_155 ) ;
F_119 ( V_2 , V_14 ) ;
}
}
}
static inline unsigned long F_149 ( unsigned long V_156 )
{
return V_156 + V_157 ;
}
static inline unsigned int F_150 ( unsigned long V_156 )
{
return V_156 % V_157 ;
}
static inline unsigned long F_151 ( unsigned long V_156 )
{
return V_156 / V_157 ;
}
static inline unsigned int F_152 ( int V_47 )
{
return V_47 ;
}
static inline void F_153 ( const char * V_89 ,
const struct V_1 * V_2 , unsigned long V_156 )
{
#ifdef F_154
unsigned long V_158 = F_155 ( V_2 -> V_9 -> V_156 ) ;
F_29 ( V_83 L_56 , V_89 , V_2 -> V_6 ) ;
#ifdef F_156
if ( F_150 ( V_156 ) != F_150 ( V_158 ) )
F_29 ( L_57 ,
F_150 ( V_156 ) , F_150 ( V_158 ) ) ;
else
#endif
if ( F_151 ( V_156 ) != F_151 ( V_158 ) )
F_29 ( L_58 ,
F_151 ( V_156 ) , F_151 ( V_158 ) ) ;
else
F_29 ( L_59 ,
V_158 , V_156 , F_149 ( V_156 ) ) ;
#endif
F_8 ( V_2 , V_159 ) ;
}
void F_157 ( struct V_1 * V_2 )
{
int V_47 ;
F_158 (cpu)
F_159 ( V_2 -> V_9 , V_47 ) -> V_156 = F_152 ( V_47 ) ;
}
static void F_160 ( struct V_1 * V_2 , struct V_160 * V_161 )
__releases( T_8 )
{
struct V_14 * V_14 = V_161 -> V_14 ;
int V_138 = 1 ;
if ( V_14 -> V_36 )
F_8 ( V_2 , V_162 ) ;
while ( F_3 ( V_161 -> V_36 ) ) {
void * * V_15 ;
V_138 = 0 ;
V_15 = V_161 -> V_36 ;
V_161 -> V_36 = F_15 ( V_2 , V_161 -> V_36 ) ;
F_19 ( V_2 , V_15 , V_14 -> V_36 ) ;
V_14 -> V_36 = V_15 ;
V_14 -> V_27 -- ;
}
V_161 -> V_14 = NULL ;
V_161 -> V_156 = F_149 ( V_161 -> V_156 ) ;
F_147 ( V_2 , V_14 , V_138 ) ;
}
static inline void F_161 ( struct V_1 * V_2 , struct V_160 * V_161 )
{
F_8 ( V_2 , V_163 ) ;
F_120 ( V_161 -> V_14 ) ;
F_160 ( V_2 , V_161 ) ;
}
static inline void F_162 ( struct V_1 * V_2 , int V_47 )
{
struct V_160 * V_161 = F_159 ( V_2 -> V_9 , V_47 ) ;
if ( F_163 ( V_161 && V_161 -> V_14 ) )
F_161 ( V_2 , V_161 ) ;
}
static void F_164 ( void * V_164 )
{
struct V_1 * V_2 = V_164 ;
F_162 ( V_2 , F_32 () ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_166 ( F_164 , V_2 , 1 ) ;
}
static inline int F_167 ( struct V_160 * V_161 , int V_13 )
{
#ifdef F_135
if ( V_13 != V_110 && V_161 -> V_13 != V_13 )
return 0 ;
#endif
return 1 ;
}
static int F_168 ( struct V_14 * V_14 )
{
return V_14 -> V_17 - V_14 -> V_27 ;
}
static unsigned long F_169 ( struct V_12 * V_89 ,
int (* F_170)( struct V_14 * ) )
{
unsigned long V_3 ;
unsigned long V_32 = 0 ;
struct V_14 * V_14 ;
F_171 ( & V_89 -> V_90 , V_3 ) ;
F_133 (page, &n->partial, lru)
V_32 += F_170 ( V_14 ) ;
F_172 ( & V_89 -> V_90 , V_3 ) ;
return V_32 ;
}
static inline unsigned long F_173 ( struct V_12 * V_89 )
{
#ifdef F_2
return F_81 ( & V_89 -> V_94 ) ;
#else
return 0 ;
#endif
}
static T_5 void
F_174 ( struct V_1 * V_2 , T_4 V_165 , int V_166 )
{
int V_13 ;
F_29 ( V_167
L_60 ,
V_166 , V_165 ) ;
F_29 ( V_167 L_61
L_62 , V_2 -> V_6 , V_2 -> V_24 ,
V_2 -> V_18 , F_24 ( V_2 -> V_108 ) , F_24 ( V_2 -> V_116 ) ) ;
if ( F_24 ( V_2 -> V_116 ) > F_175 ( V_2 -> V_24 ) )
F_29 ( V_167 L_63
L_64 , V_2 -> V_6 ) ;
F_176 (node) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
unsigned long V_93 ;
unsigned long V_168 ;
unsigned long V_169 ;
if ( ! V_89 )
continue;
V_169 = F_169 ( V_89 , F_168 ) ;
V_93 = F_82 ( V_89 ) ;
V_168 = F_173 ( V_89 ) ;
F_29 ( V_167
L_65 ,
V_13 , V_93 , V_168 , V_169 ) ;
}
}
static void * F_177 ( struct V_1 * V_2 , T_4 V_165 , int V_13 ,
unsigned long V_21 , struct V_160 * V_161 )
{
void * * V_15 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_68 ( V_3 ) ;
#ifdef F_156
V_161 = F_178 ( V_2 -> V_9 ) ;
#endif
V_165 &= ~ V_170 ;
V_14 = V_161 -> V_14 ;
if ( ! V_14 )
goto F_106;
F_120 ( V_14 ) ;
if ( F_3 ( ! F_167 ( V_161 , V_13 ) ) )
goto V_171;
F_8 ( V_2 , V_172 ) ;
V_173:
V_15 = V_14 -> V_36 ;
if ( F_3 ( ! V_15 ) )
goto V_171;
if ( F_1 ( V_2 ) )
goto V_174;
V_161 -> V_36 = F_15 ( V_2 , V_15 ) ;
V_14 -> V_27 = V_14 -> V_17 ;
V_14 -> V_36 = NULL ;
F_122 ( V_14 ) ;
V_161 -> V_156 = F_149 ( V_161 -> V_156 ) ;
F_71 ( V_3 ) ;
F_8 ( V_2 , V_175 ) ;
return V_15 ;
V_171:
F_160 ( V_2 , V_161 ) ;
F_106:
V_14 = F_145 ( V_2 , V_165 , V_13 ) ;
if ( V_14 ) {
F_8 ( V_2 , V_176 ) ;
V_161 -> V_13 = F_78 ( V_14 ) ;
V_161 -> V_14 = V_14 ;
goto V_173;
}
V_165 &= V_84 ;
if ( V_165 & V_85 )
F_179 () ;
V_14 = F_106 ( V_2 , V_165 , V_13 ) ;
if ( V_165 & V_85 )
F_180 () ;
if ( V_14 ) {
V_161 = F_181 ( V_2 -> V_9 ) ;
F_8 ( V_2 , V_177 ) ;
if ( V_161 -> V_14 )
F_161 ( V_2 , V_161 ) ;
F_120 ( V_14 ) ;
F_131 ( V_14 ) ;
V_161 -> V_13 = F_78 ( V_14 ) ;
V_161 -> V_14 = V_14 ;
goto V_173;
}
if ( ! ( V_165 & V_113 ) && F_182 () )
F_174 ( V_2 , V_165 , V_13 ) ;
F_71 ( V_3 ) ;
return NULL ;
V_174:
if ( ! F_90 ( V_2 , V_14 , V_15 , V_21 ) )
goto V_171;
V_14 -> V_27 ++ ;
V_14 -> V_36 = F_15 ( V_2 , V_15 ) ;
F_160 ( V_2 , V_161 ) ;
V_161 -> V_14 = NULL ;
V_161 -> V_13 = V_110 ;
F_71 ( V_3 ) ;
return V_15 ;
}
static T_7 void * F_183 ( struct V_1 * V_2 ,
T_4 V_165 , int V_13 , unsigned long V_21 )
{
void * * V_15 ;
struct V_160 * V_161 ;
unsigned long V_156 ;
if ( F_58 ( V_2 , V_165 ) )
return NULL ;
V_178:
V_161 = F_181 ( V_2 -> V_9 ) ;
V_156 = V_161 -> V_156 ;
F_184 () ;
V_15 = V_161 -> V_36 ;
if ( F_3 ( ! V_15 || ! F_167 ( V_161 , V_13 ) ) )
V_15 = F_177 ( V_2 , V_165 , V_13 , V_21 , V_161 ) ;
else {
if ( F_3 ( ! F_185 (
V_2 -> V_9 -> V_36 , V_2 -> V_9 -> V_156 ,
V_15 , V_156 ,
F_16 ( V_2 , V_15 ) , F_149 ( V_156 ) ) ) ) {
F_153 ( L_66 , V_2 , V_156 ) ;
goto V_178;
}
F_8 ( V_2 , V_179 ) ;
}
if ( F_3 ( V_165 & V_170 ) && V_15 )
memset ( V_15 , 0 , V_2 -> V_24 ) ;
F_62 ( V_2 , V_165 , V_15 ) ;
return V_15 ;
}
void * F_186 ( struct V_1 * V_2 , T_4 V_165 )
{
void * V_180 = F_183 ( V_2 , V_165 , V_110 , V_181 ) ;
F_187 ( V_181 , V_180 , V_2 -> V_24 , V_2 -> V_18 , V_165 ) ;
return V_180 ;
}
void * F_188 ( struct V_1 * V_2 , T_4 V_165 , T_1 V_18 )
{
void * V_180 = F_183 ( V_2 , V_165 , V_110 , V_181 ) ;
F_189 ( V_181 , V_180 , V_18 , V_2 -> V_18 , V_165 ) ;
return V_180 ;
}
void * F_190 ( T_1 V_18 , T_4 V_3 , unsigned int V_28 )
{
void * V_180 = F_191 ( V_18 , V_3 , V_28 ) ;
F_189 ( V_181 , V_180 , V_18 , V_30 << V_28 , V_3 ) ;
return V_180 ;
}
void * F_192 ( struct V_1 * V_2 , T_4 V_165 , int V_13 )
{
void * V_180 = F_183 ( V_2 , V_165 , V_13 , V_181 ) ;
F_193 ( V_181 , V_180 ,
V_2 -> V_24 , V_2 -> V_18 , V_165 , V_13 ) ;
return V_180 ;
}
void * F_194 ( struct V_1 * V_2 ,
T_4 V_165 ,
int V_13 , T_1 V_18 )
{
void * V_180 = F_183 ( V_2 , V_165 , V_13 , V_181 ) ;
F_195 ( V_181 , V_180 ,
V_18 , V_2 -> V_18 , V_165 , V_13 ) ;
return V_180 ;
}
static void F_196 ( struct V_1 * V_2 , struct V_14 * V_14 ,
void * V_32 , unsigned long V_21 )
{
void * V_182 ;
void * * V_15 = ( void * ) V_32 ;
unsigned long V_3 ;
F_68 ( V_3 ) ;
F_120 ( V_14 ) ;
F_8 ( V_2 , V_183 ) ;
if ( F_1 ( V_2 ) && ! F_91 ( V_2 , V_14 , V_32 , V_21 ) )
goto V_184;
V_182 = V_14 -> V_36 ;
F_19 ( V_2 , V_15 , V_182 ) ;
V_14 -> V_36 = V_15 ;
V_14 -> V_27 -- ;
if ( F_3 ( F_92 ( V_14 ) ) ) {
F_8 ( V_2 , V_185 ) ;
goto V_184;
}
if ( F_3 ( ! V_14 -> V_27 ) )
goto V_186;
if ( F_3 ( ! V_182 ) ) {
F_126 ( F_12 ( V_2 , F_78 ( V_14 ) ) , V_14 , 1 ) ;
F_8 ( V_2 , V_187 ) ;
}
V_184:
F_122 ( V_14 ) ;
F_71 ( V_3 ) ;
return;
V_186:
if ( V_182 ) {
F_129 ( V_2 , V_14 ) ;
F_8 ( V_2 , V_188 ) ;
}
F_122 ( V_14 ) ;
F_71 ( V_3 ) ;
F_8 ( V_2 , V_155 ) ;
F_119 ( V_2 , V_14 ) ;
}
static T_7 void F_197 ( struct V_1 * V_2 ,
struct V_14 * V_14 , void * V_32 , unsigned long V_21 )
{
void * * V_15 = ( void * ) V_32 ;
struct V_160 * V_161 ;
unsigned long V_156 ;
F_65 ( V_2 , V_32 ) ;
V_178:
V_161 = F_181 ( V_2 -> V_9 ) ;
V_156 = V_161 -> V_156 ;
F_184 () ;
if ( F_163 ( V_14 == V_161 -> V_14 ) ) {
F_19 ( V_2 , V_15 , V_161 -> V_36 ) ;
if ( F_3 ( ! F_185 (
V_2 -> V_9 -> V_36 , V_2 -> V_9 -> V_156 ,
V_161 -> V_36 , V_156 ,
V_15 , F_149 ( V_156 ) ) ) ) {
F_153 ( L_67 , V_2 , V_156 ) ;
goto V_178;
}
F_8 ( V_2 , V_189 ) ;
} else
F_196 ( V_2 , V_14 , V_32 , V_21 ) ;
}
void F_198 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_14 ;
V_14 = F_115 ( V_32 ) ;
F_197 ( V_2 , V_14 , V_32 , V_181 ) ;
F_199 ( V_181 , V_32 ) ;
}
static inline int F_200 ( int V_18 , int V_190 ,
int V_191 , int V_192 , int V_29 )
{
int V_28 ;
int V_193 ;
int V_194 = V_195 ;
if ( F_22 ( V_194 , V_18 , V_29 ) > V_81 )
return F_175 ( V_18 * V_81 ) - 1 ;
for ( V_28 = F_201 ( V_194 ,
F_202 ( V_190 * V_18 - 1 ) - V_196 ) ;
V_28 <= V_191 ; V_28 ++ ) {
unsigned long V_197 = V_30 << V_28 ;
if ( V_197 < V_190 * V_18 + V_29 )
continue;
V_193 = ( V_197 - V_29 ) % V_18 ;
if ( V_193 <= V_197 / V_192 )
break;
}
return V_28 ;
}
static inline int F_203 ( int V_18 , int V_29 )
{
int V_28 ;
int V_190 ;
int V_198 ;
int V_80 ;
V_190 = V_199 ;
if ( ! V_190 )
V_190 = 4 * ( F_202 ( V_200 ) + 1 ) ;
V_80 = F_22 ( V_201 , V_18 , V_29 ) ;
V_190 = V_116 ( V_190 , V_80 ) ;
while ( V_190 > 1 ) {
V_198 = 16 ;
while ( V_198 >= 4 ) {
V_28 = F_200 ( V_18 , V_190 ,
V_201 , V_198 , V_29 ) ;
if ( V_28 <= V_201 )
return V_28 ;
V_198 /= 2 ;
}
V_190 -- ;
}
V_28 = F_200 ( V_18 , 1 , V_201 , 1 , V_29 ) ;
if ( V_28 <= V_201 )
return V_28 ;
V_28 = F_200 ( V_18 , 1 , V_202 , 1 , V_29 ) ;
if ( V_28 < V_202 )
return V_28 ;
return - V_203 ;
}
static unsigned long F_204 ( unsigned long V_3 ,
unsigned long V_204 , unsigned long V_18 )
{
if ( V_3 & V_205 ) {
unsigned long V_206 = F_205 () ;
while ( V_18 <= V_206 / 2 )
V_206 /= 2 ;
V_204 = F_201 ( V_204 , V_206 ) ;
}
if ( V_204 < V_207 )
V_204 = V_207 ;
return F_206 ( V_204 , sizeof( void * ) ) ;
}
static void
F_207 ( struct V_12 * V_89 , struct V_1 * V_2 )
{
V_89 -> V_139 = 0 ;
F_208 ( & V_89 -> V_90 ) ;
F_209 ( & V_89 -> V_140 ) ;
#ifdef F_2
F_210 ( & V_89 -> V_93 , 0 ) ;
F_210 ( & V_89 -> V_94 , 0 ) ;
F_209 ( & V_89 -> V_92 ) ;
#endif
}
static inline int F_211 ( struct V_1 * V_2 )
{
F_212 ( V_208 <
V_209 * sizeof( struct V_160 ) ) ;
V_2 -> V_9 = F_213 ( sizeof( struct V_160 ) ,
2 * sizeof( void * ) ) ;
if ( ! V_2 -> V_9 )
return 0 ;
F_157 ( V_2 ) ;
return 1 ;
}
static void F_214 ( int V_13 )
{
struct V_14 * V_14 ;
struct V_12 * V_89 ;
unsigned long V_3 ;
F_107 ( V_12 -> V_18 < sizeof( struct V_12 ) ) ;
V_14 = F_106 ( V_12 , V_210 , V_13 ) ;
F_107 ( ! V_14 ) ;
if ( F_78 ( V_14 ) != V_13 ) {
F_29 ( V_42 L_68
L_69 , V_13 ) ;
F_29 ( V_42 L_70
L_71 ) ;
}
V_89 = V_14 -> V_36 ;
F_107 ( ! V_89 ) ;
V_14 -> V_36 = F_15 ( V_12 , V_89 ) ;
V_14 -> V_27 ++ ;
V_12 -> V_13 [ V_13 ] = V_89 ;
#ifdef F_2
F_44 ( V_12 , V_89 , V_76 ) ;
F_33 ( V_12 , V_89 ) ;
#endif
F_207 ( V_89 , V_12 ) ;
F_83 ( V_12 , V_13 , V_14 -> V_17 ) ;
F_68 ( V_3 ) ;
F_126 ( V_89 , V_14 , 0 ) ;
F_71 ( V_3 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
int V_13 ;
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = V_2 -> V_13 [ V_13 ] ;
if ( V_89 )
F_198 ( V_12 , V_89 ) ;
V_2 -> V_13 [ V_13 ] = NULL ;
}
}
static int F_217 ( struct V_1 * V_2 )
{
int V_13 ;
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 ;
if ( V_10 == V_211 ) {
F_214 ( V_13 ) ;
continue;
}
V_89 = F_192 ( V_12 ,
V_212 , V_13 ) ;
if ( ! V_89 ) {
F_215 ( V_2 ) ;
return 0 ;
}
V_2 -> V_13 [ V_13 ] = V_89 ;
F_207 ( V_89 , V_2 ) ;
}
return 1 ;
}
static void F_218 ( struct V_1 * V_2 , unsigned long V_116 )
{
if ( V_116 < V_213 )
V_116 = V_213 ;
else if ( V_116 > V_214 )
V_116 = V_214 ;
V_2 -> V_149 = V_116 ;
}
static int F_219 ( struct V_1 * V_2 , int V_215 )
{
unsigned long V_3 = V_2 -> V_3 ;
unsigned long V_18 = V_2 -> V_24 ;
unsigned long V_204 = V_2 -> V_204 ;
int V_28 ;
V_18 = F_206 ( V_18 , sizeof( void * ) ) ;
#ifdef F_2
if ( ( V_3 & V_23 ) && ! ( V_3 & V_25 ) &&
! V_2 -> F_95 )
V_2 -> V_3 |= V_60 ;
else
V_2 -> V_3 &= ~ V_60 ;
if ( ( V_3 & V_22 ) && V_18 == V_2 -> V_24 )
V_18 += sizeof( void * ) ;
#endif
V_2 -> V_27 = V_18 ;
if ( ( ( V_3 & ( V_25 | V_23 ) ) ||
V_2 -> F_95 ) ) {
V_2 -> V_19 = V_18 ;
V_18 += sizeof( void * ) ;
}
#ifdef F_2
if ( V_3 & V_26 )
V_18 += 2 * sizeof( struct V_44 ) ;
if ( V_3 & V_22 )
V_18 += sizeof( void * ) ;
#endif
V_204 = F_204 ( V_3 , V_204 , V_2 -> V_24 ) ;
V_2 -> V_204 = V_204 ;
V_18 = F_206 ( V_18 , V_204 ) ;
V_2 -> V_18 = V_18 ;
if ( V_215 >= 0 )
V_28 = V_215 ;
else
V_28 = F_203 ( V_18 , V_2 -> V_29 ) ;
if ( V_28 < 0 )
return 0 ;
V_2 -> V_112 = 0 ;
if ( V_28 )
V_2 -> V_112 |= V_216 ;
if ( V_2 -> V_3 & V_217 )
V_2 -> V_112 |= V_218 ;
if ( V_2 -> V_3 & V_121 )
V_2 -> V_112 |= V_219 ;
V_2 -> V_108 = F_23 ( V_28 , V_18 , V_2 -> V_29 ) ;
V_2 -> V_116 = F_23 ( F_175 ( V_18 ) , V_18 , V_2 -> V_29 ) ;
if ( F_25 ( V_2 -> V_108 ) > F_25 ( V_2 -> F_201 ) )
V_2 -> F_201 = V_2 -> V_108 ;
return ! ! F_25 ( V_2 -> V_108 ) ;
}
static int F_220 ( struct V_1 * V_2 ,
const char * V_6 , T_1 V_18 ,
T_1 V_204 , unsigned long V_3 ,
void (* F_95)( void * ) )
{
memset ( V_2 , 0 , V_220 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> F_95 = F_95 ;
V_2 -> V_24 = V_18 ;
V_2 -> V_204 = V_204 ;
V_2 -> V_3 = F_94 ( V_18 , V_3 , V_6 , F_95 ) ;
V_2 -> V_29 = 0 ;
if ( V_133 && ( V_2 -> V_3 & V_25 ) )
V_2 -> V_29 = sizeof( struct V_131 ) ;
if ( ! F_219 ( V_2 , - 1 ) )
goto error;
if ( V_104 ) {
if ( F_175 ( V_2 -> V_18 ) > F_175 ( V_2 -> V_24 ) ) {
V_2 -> V_3 &= ~ V_221 ;
V_2 -> V_19 = 0 ;
if ( ! F_219 ( V_2 , - 1 ) )
goto error;
}
}
F_218 ( V_2 , F_221 ( V_2 -> V_18 ) ) ;
V_2 -> V_222 = 1 ;
#ifdef F_135
V_2 -> V_147 = 1000 ;
#endif
if ( ! F_217 ( V_2 ) )
goto error;
if ( F_211 ( V_2 ) )
return 1 ;
F_215 ( V_2 ) ;
error:
if ( V_3 & V_223 )
F_222 ( L_72
L_73 ,
V_2 -> V_6 , ( unsigned long ) V_18 , V_2 -> V_18 , F_24 ( V_2 -> V_108 ) ,
V_2 -> V_19 , V_3 ) ;
return 0 ;
}
unsigned int F_223 ( struct V_1 * V_2 )
{
return V_2 -> V_24 ;
}
static void F_224 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const char * V_37 )
{
#ifdef F_2
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
unsigned long * V_35 = F_225 ( F_226 ( V_14 -> V_17 ) *
sizeof( long ) , V_224 ) ;
if ( ! V_35 )
return;
F_43 ( V_2 , V_14 , L_20 , V_37 ) ;
F_120 ( V_14 ) ;
F_26 ( V_2 , V_14 , V_35 ) ;
F_108 (p, s, addr, page->objects) {
if ( ! F_227 ( F_20 ( V_5 , V_2 , V_21 ) , V_35 ) ) {
F_29 ( V_42 L_74 ,
V_5 , V_5 - V_21 ) ;
F_35 ( V_2 , V_5 ) ;
}
}
F_122 ( V_14 ) ;
F_7 ( V_35 ) ;
#endif
}
static void F_228 ( struct V_1 * V_2 , struct V_12 * V_89 )
{
unsigned long V_3 ;
struct V_14 * V_14 , * V_132 ;
F_171 ( & V_89 -> V_90 , V_3 ) ;
F_229 (page, h, &n->partial, lru) {
if ( ! V_14 -> V_27 ) {
F_128 ( V_89 , V_14 ) ;
F_119 ( V_2 , V_14 ) ;
} else {
F_224 ( V_2 , V_14 ,
L_75 ) ;
}
}
F_172 ( & V_89 -> V_90 , V_3 ) ;
}
static inline int F_230 ( struct V_1 * V_2 )
{
int V_13 ;
F_165 ( V_2 ) ;
F_231 ( V_2 -> V_9 ) ;
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
F_228 ( V_2 , V_89 ) ;
if ( V_89 -> V_139 || F_80 ( V_2 , V_13 ) )
return 1 ;
}
F_215 ( V_2 ) ;
return 0 ;
}
void F_232 ( struct V_1 * V_2 )
{
F_233 ( & V_225 ) ;
V_2 -> V_222 -- ;
if ( ! V_2 -> V_222 ) {
F_79 ( & V_2 -> V_226 ) ;
if ( F_230 ( V_2 ) ) {
F_29 ( V_42 L_76
L_77 , V_2 -> V_6 , V_227 ) ;
F_41 () ;
}
if ( V_2 -> V_3 & V_25 )
F_234 () ;
F_6 ( V_2 ) ;
}
F_235 ( & V_225 ) ;
}
static int T_6 F_236 ( char * V_99 )
{
F_237 ( & V_99 , & V_195 ) ;
return 1 ;
}
static int T_6 F_238 ( char * V_99 )
{
F_237 ( & V_99 , & V_201 ) ;
V_201 = V_116 ( V_201 , V_202 - 1 ) ;
return 1 ;
}
static int T_6 F_239 ( char * V_99 )
{
F_237 ( & V_99 , & V_199 ) ;
return 1 ;
}
static int T_6 F_240 ( char * V_99 )
{
V_228 = 1 ;
return 1 ;
}
static struct V_1 * T_6 F_241 ( const char * V_6 ,
int V_18 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_186 ( V_1 , V_210 ) ;
if ( ! F_220 ( V_2 , V_6 , V_18 , V_229 ,
V_3 , NULL ) )
goto F_222;
F_75 ( & V_2 -> V_226 , & V_230 ) ;
return V_2 ;
F_222:
F_222 ( L_78 , V_6 , V_18 ) ;
return NULL ;
}
static inline int F_242 ( T_1 V_65 )
{
return ( V_65 - 1 ) / 8 ;
}
static struct V_1 * F_243 ( T_1 V_18 , T_4 V_3 )
{
int V_231 ;
if ( V_18 <= 192 ) {
if ( ! V_18 )
return V_232 ;
V_231 = V_233 [ F_242 ( V_18 ) ] ;
} else
V_231 = F_202 ( V_18 - 1 ) ;
#ifdef F_244
if ( F_3 ( ( V_3 & V_218 ) ) )
return V_234 [ V_231 ] ;
#endif
return V_235 [ V_231 ] ;
}
void * F_245 ( T_1 V_18 , T_4 V_3 )
{
struct V_1 * V_2 ;
void * V_180 ;
if ( F_3 ( V_18 > V_236 ) )
return F_246 ( V_18 , V_3 ) ;
V_2 = F_243 ( V_18 , V_3 ) ;
if ( F_3 ( F_247 ( V_2 ) ) )
return V_2 ;
V_180 = F_183 ( V_2 , V_3 , V_110 , V_181 ) ;
F_189 ( V_181 , V_180 , V_18 , V_2 -> V_18 , V_3 ) ;
return V_180 ;
}
static void * F_248 ( T_1 V_18 , T_4 V_3 , int V_13 )
{
struct V_14 * V_14 ;
void * V_237 = NULL ;
V_3 |= V_216 | V_109 ;
V_14 = F_249 ( V_13 , V_3 , F_175 ( V_18 ) ) ;
if ( V_14 )
V_237 = F_14 ( V_14 ) ;
F_250 ( V_237 , V_18 , 1 , V_3 ) ;
return V_237 ;
}
void * F_251 ( T_1 V_18 , T_4 V_3 , int V_13 )
{
struct V_1 * V_2 ;
void * V_180 ;
if ( F_3 ( V_18 > V_236 ) ) {
V_180 = F_248 ( V_18 , V_3 , V_13 ) ;
F_195 ( V_181 , V_180 ,
V_18 , V_30 << F_175 ( V_18 ) ,
V_3 , V_13 ) ;
return V_180 ;
}
V_2 = F_243 ( V_18 , V_3 ) ;
if ( F_3 ( F_247 ( V_2 ) ) )
return V_2 ;
V_180 = F_183 ( V_2 , V_3 , V_13 , V_181 ) ;
F_195 ( V_181 , V_180 , V_18 , V_2 -> V_18 , V_3 , V_13 ) ;
return V_180 ;
}
T_1 F_252 ( const void * V_15 )
{
struct V_14 * V_14 ;
if ( F_3 ( V_15 == V_232 ) )
return 0 ;
V_14 = F_115 ( V_15 ) ;
if ( F_3 ( ! F_55 ( V_14 ) ) ) {
F_253 ( ! F_254 ( V_14 ) ) ;
return V_30 << F_50 ( V_14 ) ;
}
return F_21 ( V_14 -> V_98 ) ;
}
void F_7 ( const void * V_32 )
{
struct V_14 * V_14 ;
void * V_15 = ( void * ) V_32 ;
F_255 ( V_181 , V_32 ) ;
if ( F_3 ( F_247 ( V_32 ) ) )
return;
V_14 = F_115 ( V_32 ) ;
if ( F_3 ( ! F_55 ( V_14 ) ) ) {
F_107 ( ! F_254 ( V_14 ) ) ;
F_256 ( V_32 ) ;
F_257 ( V_14 ) ;
return;
}
F_197 ( V_14 -> V_98 , V_14 , V_15 , V_181 ) ;
}
int F_258 ( struct V_1 * V_2 )
{
int V_13 ;
int V_39 ;
struct V_12 * V_89 ;
struct V_14 * V_14 ;
struct V_14 * V_54 ;
int V_17 = F_25 ( V_2 -> F_201 ) ;
struct V_134 * V_238 =
F_259 ( sizeof( struct V_134 ) * V_17 , V_212 ) ;
unsigned long V_3 ;
if ( ! V_238 )
return - V_239 ;
F_165 ( V_2 ) ;
F_216 (node, N_NORMAL_MEMORY) {
V_89 = F_12 ( V_2 , V_13 ) ;
if ( ! V_89 -> V_139 )
continue;
for ( V_39 = 0 ; V_39 < V_17 ; V_39 ++ )
F_209 ( V_238 + V_39 ) ;
F_171 ( & V_89 -> V_90 , V_3 ) ;
F_229 (page, t, &n->partial, lru) {
if ( ! V_14 -> V_27 && F_124 ( V_14 ) ) {
F_128 ( V_89 , V_14 ) ;
F_122 ( V_14 ) ;
F_119 ( V_2 , V_14 ) ;
} else {
F_260 ( & V_14 -> V_91 ,
V_238 + V_14 -> V_27 ) ;
}
}
for ( V_39 = V_17 - 1 ; V_39 >= 0 ; V_39 -- )
F_261 ( V_238 + V_39 , V_89 -> V_140 . V_240 ) ;
F_172 ( & V_89 -> V_90 , V_3 ) ;
}
F_7 ( V_238 ) ;
return 0 ;
}
static int F_262 ( void * V_241 )
{
struct V_1 * V_2 ;
F_263 ( & V_225 ) ;
F_133 (s, &slab_caches, list)
F_258 ( V_2 ) ;
F_264 ( & V_225 ) ;
return 0 ;
}
static void F_265 ( void * V_241 )
{
struct V_12 * V_89 ;
struct V_1 * V_2 ;
struct V_242 * V_243 = V_241 ;
int V_244 ;
V_244 = V_243 -> V_245 ;
if ( V_244 < 0 )
return;
F_263 ( & V_225 ) ;
F_133 (s, &slab_caches, list) {
V_89 = F_12 ( V_2 , V_244 ) ;
if ( V_89 ) {
F_107 ( F_80 ( V_2 , V_244 ) ) ;
V_2 -> V_13 [ V_244 ] = NULL ;
F_198 ( V_12 , V_89 ) ;
}
}
F_264 ( & V_225 ) ;
}
static int F_266 ( void * V_241 )
{
struct V_12 * V_89 ;
struct V_1 * V_2 ;
struct V_242 * V_243 = V_241 ;
int V_166 = V_243 -> V_245 ;
int V_180 = 0 ;
if ( V_166 < 0 )
return 0 ;
F_263 ( & V_225 ) ;
F_133 (s, &slab_caches, list) {
V_89 = F_186 ( V_12 , V_212 ) ;
if ( ! V_89 ) {
V_180 = - V_239 ;
goto V_102;
}
F_207 ( V_89 , V_2 ) ;
V_2 -> V_13 [ V_166 ] = V_89 ;
}
V_102:
F_264 ( & V_225 ) ;
return V_180 ;
}
static int F_267 ( struct V_246 * V_247 ,
unsigned long V_248 , void * V_241 )
{
int V_180 = 0 ;
switch ( V_248 ) {
case V_249 :
V_180 = F_266 ( V_241 ) ;
break;
case V_250 :
V_180 = F_262 ( V_241 ) ;
break;
case V_251 :
case V_252 :
F_265 ( V_241 ) ;
break;
case V_253 :
case V_254 :
break;
}
if ( V_180 )
V_180 = F_268 ( V_180 ) ;
else
V_180 = V_255 ;
return V_180 ;
}
static void T_6 F_269 ( struct V_1 * V_2 )
{
int V_13 ;
F_75 ( & V_2 -> V_226 , & V_230 ) ;
V_2 -> V_222 = - 1 ;
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
struct V_14 * V_5 ;
if ( V_89 ) {
F_133 (p, &n->partial, lru)
V_5 -> V_98 = V_2 ;
#ifdef F_2
F_133 (p, &n->full, lru)
V_5 -> V_98 = V_2 ;
#endif
}
}
}
void T_6 F_270 ( void )
{
int V_39 ;
int V_256 = 0 ;
struct V_1 * V_257 ;
int V_28 ;
struct V_1 * V_258 ;
unsigned long V_259 ;
V_220 = F_271 ( struct V_1 , V_13 ) +
V_260 * sizeof( struct V_12 * ) ;
V_259 = F_206 ( V_220 , F_205 () ) ;
V_28 = F_175 ( 2 * V_259 ) ;
V_1 = ( void * ) F_272 ( V_210 , V_28 ) ;
V_12 = ( void * ) V_1 + V_259 ;
F_220 ( V_12 , L_79 ,
sizeof( struct V_12 ) ,
0 , V_205 | V_223 , NULL ) ;
F_273 ( F_267 , V_261 ) ;
V_10 = V_262 ;
V_257 = V_1 ;
F_220 ( V_1 , L_80 , V_220 ,
0 , V_205 | V_223 , NULL ) ;
V_1 = F_186 ( V_1 , V_210 ) ;
memcpy ( V_1 , V_257 , V_220 ) ;
V_258 = V_12 ;
V_12 = F_186 ( V_1 , V_210 ) ;
memcpy ( V_12 , V_258 , V_220 ) ;
F_269 ( V_12 ) ;
V_256 ++ ;
F_269 ( V_1 ) ;
V_256 ++ ;
F_274 ( ( unsigned long ) V_257 , V_28 ) ;
F_212 ( V_263 > 256 ||
( V_263 & ( V_263 - 1 ) ) ) ;
for ( V_39 = 8 ; V_39 < V_263 ; V_39 += 8 ) {
int V_264 = F_242 ( V_39 ) ;
if ( V_264 >= F_275 ( V_233 ) )
break;
V_233 [ V_264 ] = V_265 ;
}
if ( V_263 == 64 ) {
for ( V_39 = 64 + 8 ; V_39 <= 96 ; V_39 += 8 )
V_233 [ F_242 ( V_39 ) ] = 7 ;
} else if ( V_263 == 128 ) {
for ( V_39 = 128 + 8 ; V_39 <= 192 ; V_39 += 8 )
V_233 [ F_242 ( V_39 ) ] = 8 ;
}
if ( V_263 <= 32 ) {
V_235 [ 1 ] = F_241 ( L_81 , 96 , 0 ) ;
V_256 ++ ;
}
if ( V_263 <= 64 ) {
V_235 [ 2 ] = F_241 ( L_82 , 192 , 0 ) ;
V_256 ++ ;
}
for ( V_39 = V_265 ; V_39 < V_209 ; V_39 ++ ) {
V_235 [ V_39 ] = F_241 ( L_83 , 1 << V_39 , 0 ) ;
V_256 ++ ;
}
V_10 = V_11 ;
if ( V_263 <= 32 ) {
V_235 [ 1 ] -> V_6 = F_276 ( V_235 [ 1 ] -> V_6 , V_210 ) ;
F_107 ( ! V_235 [ 1 ] -> V_6 ) ;
}
if ( V_263 <= 64 ) {
V_235 [ 2 ] -> V_6 = F_276 ( V_235 [ 2 ] -> V_6 , V_210 ) ;
F_107 ( ! V_235 [ 2 ] -> V_6 ) ;
}
for ( V_39 = V_265 ; V_39 < V_209 ; V_39 ++ ) {
char * V_2 = F_277 ( V_210 , L_84 , 1 << V_39 ) ;
F_107 ( ! V_2 ) ;
V_235 [ V_39 ] -> V_6 = V_2 ;
}
#ifdef F_278
F_279 ( & V_266 ) ;
#endif
#ifdef F_244
for ( V_39 = 0 ; V_39 < V_209 ; V_39 ++ ) {
struct V_1 * V_2 = V_235 [ V_39 ] ;
if ( V_2 && V_2 -> V_18 ) {
char * V_6 = F_277 ( V_210 ,
L_85 , V_2 -> V_24 ) ;
F_107 ( ! V_6 ) ;
V_234 [ V_39 ] = F_241 ( V_6 ,
V_2 -> V_24 , V_217 ) ;
}
}
#endif
F_29 ( V_83
L_86
L_87 ,
V_256 , F_205 () ,
V_195 , V_201 , V_199 ,
V_200 , V_260 ) ;
}
void T_6 F_280 ( void )
{
}
static int F_281 ( struct V_1 * V_2 )
{
if ( V_228 || ( V_2 -> V_3 & V_267 ) )
return 1 ;
if ( V_2 -> F_95 )
return 1 ;
if ( V_2 -> V_222 < 0 )
return 1 ;
return 0 ;
}
static struct V_1 * F_282 ( T_1 V_18 ,
T_1 V_204 , unsigned long V_3 , const char * V_6 ,
void (* F_95)( void * ) )
{
struct V_1 * V_2 ;
if ( V_228 || ( V_3 & V_267 ) )
return NULL ;
if ( F_95 )
return NULL ;
V_18 = F_206 ( V_18 , sizeof( void * ) ) ;
V_204 = F_204 ( V_3 , V_204 , V_18 ) ;
V_18 = F_206 ( V_18 , V_204 ) ;
V_3 = F_94 ( V_18 , V_3 , V_6 , NULL ) ;
F_133 (s, &slab_caches, list) {
if ( F_281 ( V_2 ) )
continue;
if ( V_18 > V_2 -> V_18 )
continue;
if ( ( V_3 & V_268 ) != ( V_2 -> V_3 & V_268 ) )
continue;
if ( ( V_2 -> V_18 & ~ ( V_204 - 1 ) ) != V_2 -> V_18 )
continue;
if ( V_2 -> V_18 - V_18 >= sizeof( void * ) )
continue;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_283 ( const char * V_6 , T_1 V_18 ,
T_1 V_204 , unsigned long V_3 , void (* F_95)( void * ) )
{
struct V_1 * V_2 ;
char * V_89 ;
if ( F_253 ( ! V_6 ) )
return NULL ;
F_233 ( & V_225 ) ;
V_2 = F_282 ( V_18 , V_204 , V_3 , V_6 , F_95 ) ;
if ( V_2 ) {
V_2 -> V_222 ++ ;
V_2 -> V_24 = F_201 ( V_2 -> V_24 , ( int ) V_18 ) ;
V_2 -> V_27 = F_284 ( int , V_2 -> V_27 , F_206 ( V_18 , sizeof( void * ) ) ) ;
if ( F_5 ( V_2 , V_6 ) ) {
V_2 -> V_222 -- ;
goto V_269;
}
F_235 ( & V_225 ) ;
return V_2 ;
}
V_89 = F_276 ( V_6 , V_212 ) ;
if ( ! V_89 )
goto V_269;
V_2 = F_259 ( V_220 , V_212 ) ;
if ( V_2 ) {
if ( F_220 ( V_2 , V_89 ,
V_18 , V_204 , V_3 , F_95 ) ) {
F_75 ( & V_2 -> V_226 , & V_230 ) ;
if ( F_4 ( V_2 ) ) {
F_79 ( & V_2 -> V_226 ) ;
F_7 ( V_89 ) ;
F_7 ( V_2 ) ;
goto V_269;
}
F_235 ( & V_225 ) ;
return V_2 ;
}
F_7 ( V_89 ) ;
F_7 ( V_2 ) ;
}
V_269:
F_235 ( & V_225 ) ;
if ( V_3 & V_223 )
F_222 ( L_88 , V_6 ) ;
else
V_2 = NULL ;
return V_2 ;
}
static int T_9 F_285 ( struct V_246 * V_270 ,
unsigned long V_248 , void * V_271 )
{
long V_47 = ( long ) V_271 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
switch ( V_248 ) {
case V_272 :
case V_273 :
case V_274 :
case V_275 :
F_263 ( & V_225 ) ;
F_133 (s, &slab_caches, list) {
F_68 ( V_3 ) ;
F_162 ( V_2 , V_47 ) ;
F_71 ( V_3 ) ;
}
F_264 ( & V_225 ) ;
break;
default:
break;
}
return V_255 ;
}
void * F_286 ( T_1 V_18 , T_4 V_165 , unsigned long V_276 )
{
struct V_1 * V_2 ;
void * V_180 ;
if ( F_3 ( V_18 > V_236 ) )
return F_246 ( V_18 , V_165 ) ;
V_2 = F_243 ( V_18 , V_165 ) ;
if ( F_3 ( F_247 ( V_2 ) ) )
return V_2 ;
V_180 = F_183 ( V_2 , V_165 , V_110 , V_276 ) ;
F_189 ( V_276 , V_180 , V_18 , V_2 -> V_18 , V_165 ) ;
return V_180 ;
}
void * F_287 ( T_1 V_18 , T_4 V_165 ,
int V_13 , unsigned long V_276 )
{
struct V_1 * V_2 ;
void * V_180 ;
if ( F_3 ( V_18 > V_236 ) ) {
V_180 = F_248 ( V_18 , V_165 , V_13 ) ;
F_195 ( V_276 , V_180 ,
V_18 , V_30 << F_175 ( V_18 ) ,
V_165 , V_13 ) ;
return V_180 ;
}
V_2 = F_243 ( V_18 , V_165 ) ;
if ( F_3 ( F_247 ( V_2 ) ) )
return V_2 ;
V_180 = F_183 ( V_2 , V_165 , V_13 , V_276 ) ;
F_195 ( V_276 , V_180 , V_18 , V_2 -> V_18 , V_165 , V_13 ) ;
return V_180 ;
}
static int F_288 ( struct V_14 * V_14 )
{
return V_14 -> V_27 ;
}
static int F_289 ( struct V_14 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_290 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_35 )
{
void * V_5 ;
void * V_21 = F_14 ( V_14 ) ;
if ( ! F_52 ( V_2 , V_14 ) ||
! F_56 ( V_2 , V_14 , NULL ) )
return 0 ;
F_291 ( V_35 , V_14 -> V_17 ) ;
F_26 ( V_2 , V_14 , V_35 ) ;
F_108 (p, s, addr, page->objects) {
if ( F_227 ( F_20 ( V_5 , V_2 , V_21 ) , V_35 ) )
if ( ! F_51 ( V_2 , V_14 , V_5 , V_95 ) )
return 0 ;
}
F_108 (p, s, addr, page->objects)
if ( ! F_227 ( F_20 ( V_5 , V_2 , V_21 ) , V_35 ) )
if ( ! F_51 ( V_2 , V_14 , V_5 , V_76 ) )
return 0 ;
return 1 ;
}
static void F_292 ( struct V_1 * V_2 , struct V_14 * V_14 ,
unsigned long * V_35 )
{
if ( F_124 ( V_14 ) ) {
F_290 ( V_2 , V_14 , V_35 ) ;
F_122 ( V_14 ) ;
} else
F_29 ( V_83 L_89 ,
V_2 -> V_6 , V_14 ) ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_12 * V_89 , unsigned long * V_35 )
{
unsigned long V_277 = 0 ;
struct V_14 * V_14 ;
unsigned long V_3 ;
F_171 ( & V_89 -> V_90 , V_3 ) ;
F_133 (page, &n->partial, lru) {
F_292 ( V_2 , V_14 , V_35 ) ;
V_277 ++ ;
}
if ( V_277 != V_89 -> V_139 )
F_29 ( V_42 L_90
L_91 , V_2 -> V_6 , V_277 , V_89 -> V_139 ) ;
if ( ! ( V_2 -> V_3 & V_26 ) )
goto V_102;
F_133 (page, &n->full, lru) {
F_292 ( V_2 , V_14 , V_35 ) ;
V_277 ++ ;
}
if ( V_277 != F_81 ( & V_89 -> V_93 ) )
F_29 ( V_42 L_92
L_91 , V_2 -> V_6 , V_277 ,
F_81 ( & V_89 -> V_93 ) ) ;
V_102:
F_172 ( & V_89 -> V_90 , V_3 ) ;
return V_277 ;
}
static long F_294 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_277 = 0 ;
unsigned long * V_35 = F_259 ( F_226 ( F_25 ( V_2 -> F_201 ) ) *
sizeof( unsigned long ) , V_212 ) ;
if ( ! V_35 )
return - V_239 ;
F_165 ( V_2 ) ;
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
V_277 += F_293 ( V_2 , V_89 , V_35 ) ;
}
F_7 ( V_35 ) ;
return V_277 ;
}
static void F_295 ( struct V_278 * V_54 )
{
if ( V_54 -> F_201 )
F_274 ( ( unsigned long ) V_54 -> V_279 ,
F_175 ( sizeof( struct V_280 ) * V_54 -> F_201 ) ) ;
}
static int F_296 ( struct V_278 * V_54 , unsigned long F_201 , T_4 V_3 )
{
struct V_280 * V_281 ;
int V_28 ;
V_28 = F_175 ( sizeof( struct V_280 ) * F_201 ) ;
V_281 = ( void * ) F_272 ( V_3 , V_28 ) ;
if ( ! V_281 )
return 0 ;
if ( V_54 -> V_277 ) {
memcpy ( V_281 , V_54 -> V_279 , sizeof( struct V_280 ) * V_54 -> V_277 ) ;
F_295 ( V_54 ) ;
}
V_54 -> F_201 = F_201 ;
V_54 -> V_279 = V_281 ;
return 1 ;
}
static int F_297 ( struct V_278 * V_54 , struct V_1 * V_2 ,
const struct V_44 * V_44 )
{
long V_63 , V_72 , V_282 ;
struct V_280 * V_281 ;
unsigned long V_283 ;
unsigned long V_284 = V_51 - V_44 -> V_50 ;
V_63 = - 1 ;
V_72 = V_54 -> V_277 ;
for ( ; ; ) {
V_282 = V_63 + ( V_72 - V_63 + 1 ) / 2 ;
if ( V_282 == V_72 )
break;
V_283 = V_54 -> V_279 [ V_282 ] . V_21 ;
if ( V_44 -> V_21 == V_283 ) {
V_281 = & V_54 -> V_279 [ V_282 ] ;
V_281 -> V_277 ++ ;
if ( V_44 -> V_50 ) {
V_281 -> V_285 += V_284 ;
if ( V_284 < V_281 -> V_286 )
V_281 -> V_286 = V_284 ;
if ( V_284 > V_281 -> V_287 )
V_281 -> V_287 = V_284 ;
if ( V_44 -> V_48 < V_281 -> V_288 )
V_281 -> V_288 = V_44 -> V_48 ;
if ( V_44 -> V_48 > V_281 -> V_289 )
V_281 -> V_289 = V_44 -> V_48 ;
F_298 ( V_44 -> V_47 ,
F_299 ( V_281 -> V_290 ) ) ;
}
F_300 ( F_78 ( F_301 ( V_44 ) ) , V_281 -> V_291 ) ;
return 1 ;
}
if ( V_44 -> V_21 < V_283 )
V_72 = V_282 ;
else
V_63 = V_282 ;
}
if ( V_54 -> V_277 >= V_54 -> F_201 && ! F_296 ( V_54 , 2 * V_54 -> F_201 , V_224 ) )
return 0 ;
V_281 = V_54 -> V_279 + V_282 ;
if ( V_282 < V_54 -> V_277 )
memmove ( V_281 + 1 , V_281 ,
( V_54 -> V_277 - V_282 ) * sizeof( struct V_280 ) ) ;
V_54 -> V_277 ++ ;
V_281 -> V_277 = 1 ;
V_281 -> V_21 = V_44 -> V_21 ;
V_281 -> V_285 = V_284 ;
V_281 -> V_286 = V_284 ;
V_281 -> V_287 = V_284 ;
V_281 -> V_288 = V_44 -> V_48 ;
V_281 -> V_289 = V_44 -> V_48 ;
F_302 ( F_299 ( V_281 -> V_290 ) ) ;
F_298 ( V_44 -> V_47 , F_299 ( V_281 -> V_290 ) ) ;
F_303 ( V_281 -> V_291 ) ;
F_300 ( F_78 ( F_301 ( V_44 ) ) , V_281 -> V_291 ) ;
return 1 ;
}
static void F_304 ( struct V_278 * V_54 , struct V_1 * V_2 ,
struct V_14 * V_14 , enum V_45 V_46 ,
unsigned long * V_35 )
{
void * V_21 = F_14 ( V_14 ) ;
void * V_5 ;
F_291 ( V_35 , V_14 -> V_17 ) ;
F_26 ( V_2 , V_14 , V_35 ) ;
F_108 (p, s, addr, page->objects)
if ( ! F_227 ( F_20 ( V_5 , V_2 , V_21 ) , V_35 ) )
F_297 ( V_54 , V_2 , F_30 ( V_2 , V_5 , V_46 ) ) ;
}
static int F_305 ( struct V_1 * V_2 , char * V_56 ,
enum V_45 V_46 )
{
int V_292 = 0 ;
unsigned long V_39 ;
struct V_278 V_54 = { 0 , 0 , NULL } ;
int V_13 ;
unsigned long * V_35 = F_259 ( F_226 ( F_25 ( V_2 -> F_201 ) ) *
sizeof( unsigned long ) , V_212 ) ;
if ( ! V_35 || ! F_296 ( & V_54 , V_30 / sizeof( struct V_280 ) ,
V_293 ) ) {
F_7 ( V_35 ) ;
return sprintf ( V_56 , L_93 ) ;
}
F_165 ( V_2 ) ;
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
unsigned long V_3 ;
struct V_14 * V_14 ;
if ( ! F_81 ( & V_89 -> V_93 ) )
continue;
F_171 ( & V_89 -> V_90 , V_3 ) ;
F_133 (page, &n->partial, lru)
F_304 ( & V_54 , V_2 , V_14 , V_46 , V_35 ) ;
F_133 (page, &n->full, lru)
F_304 ( & V_54 , V_2 , V_14 , V_46 , V_35 ) ;
F_172 ( & V_89 -> V_90 , V_3 ) ;
}
for ( V_39 = 0 ; V_39 < V_54 . V_277 ; V_39 ++ ) {
struct V_280 * V_281 = & V_54 . V_279 [ V_39 ] ;
if ( V_292 > V_30 - V_294 - 100 )
break;
V_292 += sprintf ( V_56 + V_292 , L_94 , V_281 -> V_277 ) ;
if ( V_281 -> V_21 )
V_292 += sprintf ( V_56 + V_292 , L_95 , ( void * ) V_281 -> V_21 ) ;
else
V_292 += sprintf ( V_56 + V_292 , L_96 ) ;
if ( V_281 -> V_285 != V_281 -> V_286 ) {
V_292 += sprintf ( V_56 + V_292 , L_97 ,
V_281 -> V_286 ,
( long ) F_306 ( V_281 -> V_285 , V_281 -> V_277 ) ,
V_281 -> V_287 ) ;
} else
V_292 += sprintf ( V_56 + V_292 , L_98 ,
V_281 -> V_286 ) ;
if ( V_281 -> V_288 != V_281 -> V_289 )
V_292 += sprintf ( V_56 + V_292 , L_99 ,
V_281 -> V_288 , V_281 -> V_289 ) ;
else
V_292 += sprintf ( V_56 + V_292 , L_100 ,
V_281 -> V_288 ) ;
if ( F_307 () > 1 &&
! F_308 ( F_299 ( V_281 -> V_290 ) ) &&
V_292 < V_30 - 60 ) {
V_292 += sprintf ( V_56 + V_292 , L_101 ) ;
V_292 += F_309 ( V_56 + V_292 , V_30 - V_292 - 50 ,
F_299 ( V_281 -> V_290 ) ) ;
}
if ( V_295 > 1 && ! F_310 ( V_281 -> V_291 ) &&
V_292 < V_30 - 60 ) {
V_292 += sprintf ( V_56 + V_292 , L_102 ) ;
V_292 += F_311 ( V_56 + V_292 , V_30 - V_292 - 50 ,
V_281 -> V_291 ) ;
}
V_292 += sprintf ( V_56 + V_292 , L_103 ) ;
}
F_295 ( & V_54 ) ;
F_7 ( V_35 ) ;
if ( ! V_54 . V_277 )
V_292 += sprintf ( V_56 , L_104 ) ;
return V_292 ;
}
static void F_312 ( void )
{
T_2 * V_5 ;
F_212 ( V_263 > 16 || V_209 < 10 ) ;
F_29 ( V_42 L_105 ) ;
F_29 ( V_42 L_106 ) ;
F_29 ( V_42 L_107 ) ;
V_5 = F_225 ( 16 , V_212 ) ;
V_5 [ 16 ] = 0x12 ;
F_29 ( V_42 L_108
L_109 , V_5 + 16 ) ;
F_294 ( V_235 [ 4 ] ) ;
V_5 = F_225 ( 32 , V_212 ) ;
V_5 [ 32 + sizeof( void * ) ] = 0x34 ;
F_29 ( V_42 L_110
L_111 , V_5 ) ;
F_29 ( V_42
L_112 ) ;
F_294 ( V_235 [ 5 ] ) ;
V_5 = F_225 ( 64 , V_212 ) ;
V_5 += 64 + ( F_137 () & 0xff ) * sizeof( void * ) ;
* V_5 = 0x56 ;
F_29 ( V_42 L_113 ,
V_5 ) ;
F_29 ( V_42
L_112 ) ;
F_294 ( V_235 [ 6 ] ) ;
F_29 ( V_42 L_114 ) ;
V_5 = F_225 ( 128 , V_212 ) ;
F_7 ( V_5 ) ;
* V_5 = 0x78 ;
F_29 ( V_42 L_115 , V_5 ) ;
F_294 ( V_235 [ 7 ] ) ;
V_5 = F_225 ( 256 , V_212 ) ;
F_7 ( V_5 ) ;
V_5 [ 50 ] = 0x9a ;
F_29 ( V_42 L_116 ,
V_5 ) ;
F_294 ( V_235 [ 8 ] ) ;
V_5 = F_225 ( 512 , V_212 ) ;
F_7 ( V_5 ) ;
V_5 [ 512 ] = 0xab ;
F_29 ( V_42 L_117 , V_5 ) ;
F_294 ( V_235 [ 9 ] ) ;
}
static void F_312 ( void ) {}
static T_10 F_313 ( struct V_1 * V_2 ,
char * V_56 , unsigned long V_3 )
{
unsigned long V_296 = 0 ;
int V_13 ;
int V_32 ;
unsigned long * V_291 ;
unsigned long * V_297 ;
V_291 = F_225 ( 2 * sizeof( unsigned long ) * V_260 , V_212 ) ;
if ( ! V_291 )
return - V_239 ;
V_297 = V_291 + V_260 ;
if ( V_3 & V_298 ) {
int V_47 ;
F_158 (cpu) {
struct V_160 * V_161 = F_159 ( V_2 -> V_9 , V_47 ) ;
if ( ! V_161 || V_161 -> V_13 < 0 )
continue;
if ( V_161 -> V_14 ) {
if ( V_3 & V_299 )
V_32 = V_161 -> V_14 -> V_17 ;
else if ( V_3 & V_300 )
V_32 = V_161 -> V_14 -> V_27 ;
else
V_32 = 1 ;
V_296 += V_32 ;
V_291 [ V_161 -> V_13 ] += V_32 ;
}
V_297 [ V_161 -> V_13 ] ++ ;
}
}
F_314 () ;
#ifdef F_2
if ( V_3 & V_301 ) {
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_299 )
V_32 = F_81 ( & V_89 -> V_94 ) ;
else if ( V_3 & V_300 )
V_32 = F_81 ( & V_89 -> V_94 ) -
F_169 ( V_89 , F_168 ) ;
else
V_32 = F_81 ( & V_89 -> V_93 ) ;
V_296 += V_32 ;
V_291 [ V_13 ] += V_32 ;
}
} else
#endif
if ( V_3 & V_302 ) {
F_216 (node, N_NORMAL_MEMORY) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
if ( V_3 & V_299 )
V_32 = F_169 ( V_89 , F_289 ) ;
else if ( V_3 & V_300 )
V_32 = F_169 ( V_89 , F_288 ) ;
else
V_32 = V_89 -> V_139 ;
V_296 += V_32 ;
V_291 [ V_13 ] += V_32 ;
}
}
V_32 = sprintf ( V_56 , L_118 , V_296 ) ;
#ifdef F_135
F_216 (node, N_NORMAL_MEMORY)
if ( V_291 [ V_13 ] )
V_32 += sprintf ( V_56 + V_32 , L_119 ,
V_13 , V_291 [ V_13 ] ) ;
#endif
F_315 () ;
F_7 ( V_291 ) ;
return V_32 + sprintf ( V_56 + V_32 , L_103 ) ;
}
static int F_316 ( struct V_1 * V_2 )
{
int V_13 ;
F_176 (node) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
if ( ! V_89 )
continue;
if ( F_81 ( & V_89 -> V_94 ) )
return 1 ;
}
return 0 ;
}
static T_10 F_317 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , V_2 -> V_18 ) ;
}
static T_10 F_318 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , V_2 -> V_204 ) ;
}
static T_10 F_319 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , V_2 -> V_24 ) ;
}
static T_10 F_320 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , F_25 ( V_2 -> V_108 ) ) ;
}
static T_10 F_321 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
unsigned long V_28 ;
int V_269 ;
V_269 = F_322 ( V_56 , 10 , & V_28 ) ;
if ( V_269 )
return V_269 ;
if ( V_28 > V_201 || V_28 < V_195 )
return - V_303 ;
F_219 ( V_2 , V_28 ) ;
return V_38 ;
}
static T_10 F_323 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , F_24 ( V_2 -> V_108 ) ) ;
}
static T_10 F_324 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_121 , V_2 -> V_149 ) ;
}
static T_10 F_325 ( struct V_1 * V_2 , const char * V_56 ,
T_1 V_38 )
{
unsigned long V_116 ;
int V_269 ;
V_269 = F_322 ( V_56 , 10 , & V_116 ) ;
if ( V_269 )
return V_269 ;
F_218 ( V_2 , V_116 ) ;
return V_38 ;
}
static T_10 F_326 ( struct V_1 * V_2 , char * V_56 )
{
if ( ! V_2 -> F_95 )
return 0 ;
return sprintf ( V_56 , L_122 , V_2 -> F_95 ) ;
}
static T_10 F_327 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , V_2 -> V_222 - 1 ) ;
}
static T_10 F_328 ( struct V_1 * V_2 , char * V_56 )
{
return F_313 ( V_2 , V_56 , V_302 ) ;
}
static T_10 F_329 ( struct V_1 * V_2 , char * V_56 )
{
return F_313 ( V_2 , V_56 , V_298 ) ;
}
static T_10 F_330 ( struct V_1 * V_2 , char * V_56 )
{
return F_313 ( V_2 , V_56 , V_301 | V_300 ) ;
}
static T_10 F_331 ( struct V_1 * V_2 , char * V_56 )
{
return F_313 ( V_2 , V_56 , V_302 | V_300 ) ;
}
static T_10 F_332 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_121 ) ) ;
}
static T_10 F_333 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
V_2 -> V_3 &= ~ V_121 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_121 ;
return V_38 ;
}
static T_10 F_334 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_205 ) ) ;
}
static T_10 F_335 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_217 ) ) ;
}
static T_10 F_336 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_25 ) ) ;
}
static T_10 F_337 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , V_2 -> V_29 ) ;
}
static T_10 F_338 ( struct V_1 * V_2 , char * V_56 )
{
return F_313 ( V_2 , V_56 , V_301 ) ;
}
static T_10 F_339 ( struct V_1 * V_2 , char * V_56 )
{
return F_313 ( V_2 , V_56 , V_301 | V_299 ) ;
}
static T_10 F_340 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_105 ) ) ;
}
static T_10 F_341 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
V_2 -> V_3 &= ~ V_105 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_105 ;
return V_38 ;
}
static T_10 F_342 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_82 ) ) ;
}
static T_10 F_343 ( struct V_1 * V_2 , const char * V_56 ,
T_1 V_38 )
{
V_2 -> V_3 &= ~ V_82 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_82 ;
return V_38 ;
}
static T_10 F_344 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_22 ) ) ;
}
static T_10 F_345 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
if ( F_316 ( V_2 ) )
return - V_304 ;
V_2 -> V_3 &= ~ V_22 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_22 ;
F_219 ( V_2 , - 1 ) ;
return V_38 ;
}
static T_10 F_346 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_23 ) ) ;
}
static T_10 F_347 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
if ( F_316 ( V_2 ) )
return - V_304 ;
V_2 -> V_3 &= ~ V_23 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_23 ;
F_219 ( V_2 , - 1 ) ;
return V_38 ;
}
static T_10 F_348 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_26 ) ) ;
}
static T_10 F_349 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
if ( F_316 ( V_2 ) )
return - V_304 ;
V_2 -> V_3 &= ~ V_26 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_26 ;
F_219 ( V_2 , - 1 ) ;
return V_38 ;
}
static T_10 F_350 ( struct V_1 * V_2 , char * V_56 )
{
return 0 ;
}
static T_10 F_351 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
int V_180 = - V_303 ;
if ( V_56 [ 0 ] == '1' ) {
V_180 = F_294 ( V_2 ) ;
if ( V_180 >= 0 )
V_180 = V_38 ;
}
return V_180 ;
}
static T_10 F_352 ( struct V_1 * V_2 , char * V_56 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_203 ;
return F_305 ( V_2 , V_56 , V_53 ) ;
}
static T_10 F_353 ( struct V_1 * V_2 , char * V_56 )
{
if ( ! ( V_2 -> V_3 & V_26 ) )
return - V_203 ;
return F_305 ( V_2 , V_56 , V_52 ) ;
}
static T_10 F_354 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , ! ! ( V_2 -> V_3 & V_106 ) ) ;
}
static T_10 F_355 ( struct V_1 * V_2 , const char * V_56 ,
T_1 V_38 )
{
V_2 -> V_3 &= ~ V_106 ;
if ( V_56 [ 0 ] == '1' )
V_2 -> V_3 |= V_106 ;
return V_38 ;
}
static T_10 F_356 ( struct V_1 * V_2 , char * V_56 )
{
return 0 ;
}
static T_10 F_357 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
if ( V_56 [ 0 ] == '1' ) {
int V_137 = F_258 ( V_2 ) ;
if ( V_137 )
return V_137 ;
} else
return - V_303 ;
return V_38 ;
}
static T_10 F_358 ( struct V_1 * V_2 , char * V_56 )
{
return sprintf ( V_56 , L_120 , V_2 -> V_147 / 10 ) ;
}
static T_10 F_359 ( struct V_1 * V_2 ,
const char * V_56 , T_1 V_38 )
{
unsigned long V_305 ;
int V_269 ;
V_269 = F_322 ( V_56 , 10 , & V_305 ) ;
if ( V_269 )
return V_269 ;
if ( V_305 <= 100 )
V_2 -> V_147 = V_305 * 10 ;
return V_38 ;
}
static int F_360 ( struct V_1 * V_2 , char * V_56 , enum V_7 V_8 )
{
unsigned long V_306 = 0 ;
int V_47 ;
int V_292 ;
int * V_67 = F_259 ( V_200 * sizeof( int ) , V_212 ) ;
if ( ! V_67 )
return - V_239 ;
F_361 (cpu) {
unsigned V_32 = F_159 ( V_2 -> V_9 , V_47 ) -> F_8 [ V_8 ] ;
V_67 [ V_47 ] = V_32 ;
V_306 += V_32 ;
}
V_292 = sprintf ( V_56 , L_118 , V_306 ) ;
#ifdef F_278
F_361 (cpu) {
if ( V_67 [ V_47 ] && V_292 < V_30 - 20 )
V_292 += sprintf ( V_56 + V_292 , L_123 , V_47 , V_67 [ V_47 ] ) ;
}
#endif
F_7 ( V_67 ) ;
return V_292 + sprintf ( V_56 + V_292 , L_103 ) ;
}
static void F_362 ( struct V_1 * V_2 , enum V_7 V_8 )
{
int V_47 ;
F_361 (cpu)
F_159 ( V_2 -> V_9 , V_47 ) -> F_8 [ V_8 ] = 0 ;
}
static T_10 F_363 ( struct V_307 * V_308 ,
struct V_309 * V_310 ,
char * V_56 )
{
struct V_311 * V_309 ;
struct V_1 * V_2 ;
int V_269 ;
V_309 = F_364 ( V_310 ) ;
V_2 = F_365 ( V_308 ) ;
if ( ! V_309 -> V_312 )
return - V_313 ;
V_269 = V_309 -> V_312 ( V_2 , V_56 ) ;
return V_269 ;
}
static T_10 F_366 ( struct V_307 * V_308 ,
struct V_309 * V_310 ,
const char * V_56 , T_1 V_292 )
{
struct V_311 * V_309 ;
struct V_1 * V_2 ;
int V_269 ;
V_309 = F_364 ( V_310 ) ;
V_2 = F_365 ( V_308 ) ;
if ( ! V_309 -> V_314 )
return - V_313 ;
V_269 = V_309 -> V_314 ( V_2 , V_56 , V_292 ) ;
return V_269 ;
}
static void F_367 ( struct V_307 * V_308 )
{
struct V_1 * V_2 = F_365 ( V_308 ) ;
F_7 ( V_2 -> V_6 ) ;
F_7 ( V_2 ) ;
}
static int F_368 ( struct V_315 * V_315 , struct V_307 * V_308 )
{
struct V_316 * V_317 = F_369 ( V_308 ) ;
if ( V_317 == & V_318 )
return 1 ;
return 0 ;
}
static char * F_370 ( struct V_1 * V_2 )
{
char * V_6 = F_259 ( V_319 , V_212 ) ;
char * V_5 = V_6 ;
F_107 ( ! V_6 ) ;
* V_5 ++ = ':' ;
if ( V_2 -> V_3 & V_217 )
* V_5 ++ = 'd' ;
if ( V_2 -> V_3 & V_121 )
* V_5 ++ = 'a' ;
if ( V_2 -> V_3 & V_105 )
* V_5 ++ = 'F' ;
if ( ! ( V_2 -> V_3 & V_119 ) )
* V_5 ++ = 't' ;
if ( V_5 != V_6 + 1 )
* V_5 ++ = '-' ;
V_5 += sprintf ( V_5 , L_124 , V_2 -> V_18 ) ;
F_107 ( V_5 > V_6 + V_319 - 1 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_269 ;
const char * V_6 ;
int V_320 ;
if ( V_10 < V_321 )
return 0 ;
V_320 = F_281 ( V_2 ) ;
if ( V_320 ) {
F_371 ( & V_322 -> V_308 , V_2 -> V_6 ) ;
V_6 = V_2 -> V_6 ;
} else {
V_6 = F_370 ( V_2 ) ;
}
V_2 -> V_308 . V_315 = V_322 ;
V_269 = F_372 ( & V_2 -> V_308 , & V_318 , NULL , V_6 ) ;
if ( V_269 ) {
F_373 ( & V_2 -> V_308 ) ;
return V_269 ;
}
V_269 = F_374 ( & V_2 -> V_308 , & V_323 ) ;
if ( V_269 ) {
F_375 ( & V_2 -> V_308 ) ;
F_373 ( & V_2 -> V_308 ) ;
return V_269 ;
}
F_376 ( & V_2 -> V_308 , V_324 ) ;
if ( ! V_320 ) {
F_5 ( V_2 , V_2 -> V_6 ) ;
F_7 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_10 < V_321 )
return;
F_376 ( & V_2 -> V_308 , V_325 ) ;
F_375 ( & V_2 -> V_308 ) ;
F_373 ( & V_2 -> V_308 ) ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_326 * V_327 ;
if ( V_10 == V_321 ) {
F_371 ( & V_322 -> V_308 , V_6 ) ;
return F_377 ( & V_322 -> V_308 , & V_2 -> V_308 , V_6 ) ;
}
V_327 = F_259 ( sizeof( struct V_326 ) , V_212 ) ;
if ( ! V_327 )
return - V_239 ;
V_327 -> V_2 = V_2 ;
V_327 -> V_6 = V_6 ;
V_327 -> V_328 = V_329 ;
V_329 = V_327 ;
return 0 ;
}
static int T_6 F_378 ( void )
{
struct V_1 * V_2 ;
int V_269 ;
F_233 ( & V_225 ) ;
V_322 = F_379 ( L_125 , & V_330 , V_331 ) ;
if ( ! V_322 ) {
F_235 ( & V_225 ) ;
F_29 ( V_42 L_126 ) ;
return - V_203 ;
}
V_10 = V_321 ;
F_133 (s, &slab_caches, list) {
V_269 = F_4 ( V_2 ) ;
if ( V_269 )
F_29 ( V_42 L_127
L_128 , V_2 -> V_6 ) ;
}
while ( V_329 ) {
struct V_326 * V_327 = V_329 ;
V_329 = V_329 -> V_328 ;
V_269 = F_5 ( V_327 -> V_2 , V_327 -> V_6 ) ;
if ( V_269 )
F_29 ( V_42 L_129
L_130 , V_2 -> V_6 ) ;
F_7 ( V_327 ) ;
}
F_235 ( & V_225 ) ;
F_312 () ;
return 0 ;
}
static void F_380 ( struct V_332 * V_333 )
{
F_381 ( V_333 , L_131 ) ;
F_381 ( V_333 , L_132
L_133 ) ;
F_381 ( V_333 , L_134 ) ;
F_381 ( V_333 , L_135 ) ;
F_382 ( V_333 , '\n' ) ;
}
static void * F_383 ( struct V_332 * V_333 , T_11 * V_282 )
{
T_11 V_89 = * V_282 ;
F_263 ( & V_225 ) ;
if ( ! V_89 )
F_380 ( V_333 ) ;
return F_384 ( & V_230 , * V_282 ) ;
}
static void * F_385 ( struct V_332 * V_333 , void * V_5 , T_11 * V_282 )
{
return F_386 ( V_5 , & V_230 , V_282 ) ;
}
static void F_387 ( struct V_332 * V_333 , void * V_5 )
{
F_264 ( & V_225 ) ;
}
static int F_388 ( struct V_332 * V_333 , void * V_5 )
{
unsigned long V_334 = 0 ;
unsigned long V_93 = 0 ;
unsigned long V_335 = 0 ;
unsigned long V_168 = 0 ;
unsigned long V_169 = 0 ;
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_389 ( V_5 , struct V_1 , V_226 ) ;
F_176 (node) {
struct V_12 * V_89 = F_12 ( V_2 , V_13 ) ;
if ( ! V_89 )
continue;
V_334 += V_89 -> V_139 ;
V_93 += F_81 ( & V_89 -> V_93 ) ;
V_168 += F_81 ( & V_89 -> V_94 ) ;
V_169 += F_169 ( V_89 , F_168 ) ;
}
V_335 = V_168 - V_169 ;
F_390 ( V_333 , L_136 , V_2 -> V_6 , V_335 ,
V_168 , V_2 -> V_18 , F_25 ( V_2 -> V_108 ) ,
( 1 << F_24 ( V_2 -> V_108 ) ) ) ;
F_390 ( V_333 , L_137 , 0 , 0 , 0 ) ;
F_390 ( V_333 , L_138 , V_93 , V_93 ,
0UL ) ;
F_382 ( V_333 , '\n' ) ;
return 0 ;
}
static int F_391 ( struct V_336 * V_336 , struct V_337 * V_337 )
{
return F_392 ( V_337 , & V_338 ) ;
}
static int T_6 F_393 ( void )
{
F_394 ( L_139 , V_339 , NULL , & V_340 ) ;
return 0 ;
}
