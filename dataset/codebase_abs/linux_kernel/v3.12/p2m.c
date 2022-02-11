static inline unsigned F_1 ( unsigned long V_1 )
{
F_2 ( V_1 >= V_2 ) ;
return V_1 / ( V_3 * V_4 ) ;
}
static inline unsigned F_3 ( unsigned long V_1 )
{
return ( V_1 / V_4 ) % V_3 ;
}
static inline unsigned F_4 ( unsigned long V_1 )
{
return V_1 % V_4 ;
}
static void F_5 ( unsigned long * * * V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 [ V_6 ] = V_8 ;
}
static void F_6 ( unsigned long * V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 [ V_6 ] = F_7 ( V_9 ) ;
}
static void F_8 ( unsigned long * * V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 [ V_6 ] = V_9 ;
}
static void F_9 ( unsigned long * * V_10 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
V_10 [ V_6 ] = V_11 ;
}
static void F_10 ( unsigned long * V_10 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
V_10 [ V_6 ] = F_7 ( V_11 ) ;
}
static void F_11 ( unsigned long * V_12 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
V_12 [ V_6 ] = V_13 ;
}
void T_1 F_12 ( void )
{
unsigned long V_1 ;
if ( V_14 == NULL ) {
V_9 = F_13 ( V_15 , V_15 ) ;
F_10 ( V_9 ) ;
V_16 = F_13 ( V_15 , V_15 ) ;
F_8 ( V_16 ) ;
V_14 = F_13 ( V_15 , V_15 ) ;
F_6 ( V_14 ) ;
} else {
F_10 ( V_9 ) ;
}
for ( V_1 = 0 ; V_1 < V_17 ; V_1 += V_4 ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 = F_3 ( V_1 ) ;
unsigned long * * V_10 ;
unsigned long * V_20 ;
V_10 = V_21 [ V_18 ] ;
V_20 = V_16 [ V_18 ] ;
if ( V_10 == V_8 ) {
F_2 ( V_19 ) ;
F_2 ( V_20 != V_9 ) ;
V_14 [ V_18 ] = F_7 ( V_9 ) ;
V_1 += ( V_3 - 1 ) * V_4 ;
continue;
}
if ( V_20 == V_9 ) {
V_20 = F_13 ( V_15 , V_15 ) ;
F_10 ( V_20 ) ;
V_16 [ V_18 ] = V_20 ;
}
V_14 [ V_18 ] = F_7 ( V_20 ) ;
V_20 [ V_19 ] = F_7 ( V_10 [ V_19 ] ) ;
}
}
void F_14 ( void )
{
F_2 ( V_22 == & V_23 ) ;
V_22 -> V_24 . V_25 =
F_7 ( V_14 ) ;
V_22 -> V_24 . V_26 = V_17 ;
}
void T_2 F_15 ( void )
{
unsigned long * V_27 = ( unsigned long * ) V_28 -> V_27 ;
unsigned long V_26 = F_16 ( V_29 , V_28 -> V_30 ) ;
unsigned long V_1 ;
V_17 = V_26 ;
V_11 = F_13 ( V_15 , V_15 ) ;
F_11 ( V_11 ) ;
V_8 = F_13 ( V_15 , V_15 ) ;
F_9 ( V_8 ) ;
V_21 = F_13 ( V_15 , V_15 ) ;
F_5 ( V_21 ) ;
V_31 = F_13 ( V_15 , V_15 ) ;
F_11 ( V_31 ) ;
for ( V_1 = 0 ; V_1 < V_26 ; V_1 += V_4 ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 = F_3 ( V_1 ) ;
if ( V_21 [ V_18 ] == V_8 ) {
unsigned long * * V_10 = F_13 ( V_15 , V_15 ) ;
F_9 ( V_10 ) ;
V_21 [ V_18 ] = V_10 ;
}
if ( F_17 ( V_1 + V_4 > V_26 ) ) {
unsigned long V_32 ;
V_32 = V_26 % V_4 ;
for ( ; V_32 < V_4 ; V_32 ++ )
V_27 [ V_1 + V_32 ] = V_13 ;
}
V_21 [ V_18 ] [ V_19 ] = & V_27 [ V_1 ] ;
}
F_18 () ;
}
unsigned long T_2 F_19 ( void )
{
unsigned long va_start ;
unsigned long va_end ;
unsigned long V_1 ;
unsigned long V_33 = 0 ;
unsigned long * V_27 = NULL ;
unsigned long V_34 ;
va_start = V_28 -> V_27 ;
V_34 = F_20 ( V_28 -> V_30 * sizeof( unsigned long ) ) ;
va_end = va_start + V_34 ;
if ( va_start <= V_35 && va_start >= V_36 )
return 0 ;
V_27 = F_21 ( V_34 , V_15 ) ;
if ( ! V_27 ) {
F_22 ( L_1 ) ;
return V_28 -> V_27 ;
}
memset ( V_27 , 0xFF , V_34 ) ;
for ( V_1 = 0 ; V_1 < F_23 ( V_29 , V_4 ) ; V_1 += V_4 ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 ;
unsigned long * V_37 ;
if ( ! V_21 [ V_18 ] )
continue;
if ( V_21 [ V_18 ] == V_8 )
continue;
V_19 = F_3 ( V_1 ) ;
V_37 = V_21 [ V_18 ] [ V_19 ] ;
if ( ! V_37 )
continue;
if ( ( V_37 == V_11 ) || ( V_37 == V_31 ) )
continue;
if ( ( unsigned long ) V_37 == V_13 )
continue;
if ( V_37 >= ( unsigned long * ) va_start && V_37 <= ( unsigned long * ) va_end ) {
unsigned long * V_38 ;
if ( V_33 > ( V_34 / sizeof( unsigned long ) ) ) {
F_24 ( 1 , L_2 ,
V_34 / sizeof( unsigned long ) , V_33 ) ;
return 0 ;
}
V_38 = & V_27 [ V_33 ] ;
F_25 ( V_38 , V_37 ) ;
V_21 [ V_18 ] [ V_19 ] = & V_27 [ V_33 ] ;
V_16 [ V_18 ] [ V_19 ] = F_7 ( & V_27 [ V_33 ] ) ;
V_33 += V_4 ;
}
}
return ( unsigned long ) V_27 ;
}
unsigned long T_2 F_19 ( void )
{
return 0 ;
}
unsigned long F_26 ( unsigned long V_1 )
{
unsigned V_18 , V_19 , V_39 ;
if ( F_17 ( V_1 >= V_2 ) )
return V_13 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_39 = F_4 ( V_1 ) ;
if ( V_21 [ V_18 ] [ V_19 ] == V_31 )
return F_27 ( V_1 ) ;
return V_21 [ V_18 ] [ V_19 ] [ V_39 ] ;
}
static void * F_28 ( void )
{
return ( void * ) F_29 ( V_40 | V_41 ) ;
}
static void F_30 ( void * V_42 )
{
F_31 ( ( unsigned long ) V_42 ) ;
}
static bool F_32 ( unsigned long V_1 )
{
unsigned V_18 , V_19 ;
unsigned long * * * V_43 , * * V_10 ;
unsigned long * V_44 , * V_45 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_43 = & V_21 [ V_18 ] ;
V_10 = * V_43 ;
if ( V_10 == V_8 ) {
V_10 = F_28 () ;
if ( ! V_10 )
return false ;
F_9 ( V_10 ) ;
if ( F_33 ( V_43 , V_8 , V_10 ) != V_8 )
F_30 ( V_10 ) ;
}
V_44 = & V_14 [ V_18 ] ;
V_45 = V_16 [ V_18 ] ;
F_2 ( F_7 ( V_45 ) != * V_44 ) ;
if ( V_45 == V_9 ) {
unsigned long V_46 ;
unsigned long V_47 ;
V_45 = F_28 () ;
if ( ! V_45 )
return false ;
F_10 ( V_45 ) ;
V_46 = F_7 ( V_9 ) ;
V_47 = F_7 ( V_45 ) ;
if ( F_33 ( V_44 , V_46 , V_47 ) != V_46 )
F_30 ( V_45 ) ;
else
V_16 [ V_18 ] = V_45 ;
}
if ( V_21 [ V_18 ] [ V_19 ] == V_31 ||
V_21 [ V_18 ] [ V_19 ] == V_11 ) {
unsigned long * V_12 ;
unsigned long * V_48 = V_21 [ V_18 ] [ V_19 ] ;
V_12 = F_28 () ;
if ( ! V_12 )
return false ;
F_11 ( V_12 ) ;
if ( F_33 ( & V_10 [ V_19 ] , V_48 , V_12 ) != V_48 )
F_30 ( V_12 ) ;
else
V_45 [ V_19 ] = F_7 ( V_12 ) ;
}
return true ;
}
static bool T_2 F_34 ( unsigned long V_1 , bool V_49 )
{
unsigned V_18 , V_19 , V_39 ;
unsigned long * V_12 ;
unsigned long * V_20 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_39 = F_4 ( V_1 ) ;
if ( ! V_39 && V_49 )
return false ;
F_24 ( V_21 [ V_18 ] [ V_19 ] == V_31 ,
L_3 ,
V_18 , V_19 ) ;
if ( V_21 [ V_18 ] [ V_19 ] != V_11 )
return false ;
V_12 = F_13 ( V_15 , V_15 ) ;
F_11 ( V_12 ) ;
V_21 [ V_18 ] [ V_19 ] = V_12 ;
V_20 = V_16 [ V_18 ] ;
F_24 ( V_20 [ V_19 ] != F_7 ( V_11 ) ,
L_4 ,
V_18 , V_19 ) ;
V_20 [ V_19 ] = F_7 ( V_12 ) ;
return true ;
}
static bool T_2 F_35 ( unsigned long V_1 )
{
unsigned V_18 = F_1 ( V_1 ) ;
unsigned long * V_20 ;
unsigned long * * V_10 ;
V_10 = V_21 [ V_18 ] ;
V_20 = V_16 [ V_18 ] ;
if ( V_10 == V_8 ) {
V_10 = F_13 ( V_15 , V_15 ) ;
F_9 ( V_10 ) ;
V_21 [ V_18 ] = V_10 ;
F_2 ( V_20 != V_9 ) ;
}
if ( V_20 == V_9 ) {
V_20 = F_13 ( V_15 , V_15 ) ;
F_10 ( V_20 ) ;
V_16 [ V_18 ] = V_20 ;
V_14 [ V_18 ] = F_7 ( V_20 ) ;
}
return true ;
}
bool T_2 F_36 ( unsigned long V_50 , unsigned long V_51 )
{
unsigned V_18 ;
unsigned V_19 ;
unsigned V_52 ;
unsigned V_53 ;
unsigned long * V_12 ;
unsigned long * V_20 ;
unsigned V_39 ;
unsigned long V_1 ;
if ( F_4 ( V_50 ) )
return false ;
for ( V_1 = 0 ; V_1 < V_29 ; V_1 += V_4 ) {
V_18 = F_1 ( V_1 ) ;
if ( ! V_21 [ V_18 ] )
continue;
if ( V_21 [ V_18 ] == V_8 )
continue;
V_19 = F_3 ( V_1 ) ;
V_12 = V_21 [ V_18 ] [ V_19 ] ;
if ( ! V_12 )
continue;
if ( ( V_12 == V_11 ) || ( V_12 == V_31 ) )
continue;
if ( ( unsigned long ) V_12 == V_13 )
continue;
V_52 = 0 ;
V_53 = 0 ;
for ( V_39 = 0 ; V_39 < V_4 ; V_39 ++ ) {
if ( V_12 [ V_39 ] == F_27 ( V_1 + V_39 ) )
V_52 ++ ;
else if ( V_12 [ V_39 ] == V_13 )
V_53 ++ ;
else
break;
}
if ( ( V_52 == V_4 ) || ( V_53 == V_4 ) )
goto V_54;
}
return false ;
V_54:
V_21 [ V_18 ] [ V_19 ] = ( V_52 ? V_31 : V_11 ) ;
V_20 = V_16 [ V_18 ] ;
V_20 [ V_19 ] = F_7 ( V_11 ) ;
V_18 = F_1 ( V_50 ) ;
V_19 = F_3 ( V_50 ) ;
if ( F_37 ( V_21 [ V_18 ] == V_8 ) )
F_35 ( V_50 ) ;
if ( F_37 ( V_21 [ V_18 ] [ V_19 ] != V_11 ) )
return false ;
F_11 ( V_12 ) ;
V_21 [ V_18 ] [ V_19 ] = V_12 ;
V_20 = V_16 [ V_18 ] ;
V_20 [ V_19 ] = F_7 ( V_12 ) ;
return true ;
}
bool T_2 F_38 ( unsigned long V_1 , unsigned long V_55 )
{
if ( F_17 ( ! F_39 ( V_1 , V_55 ) ) ) {
if ( ! F_35 ( V_1 ) )
return false ;
if ( F_36 ( V_1 , V_55 ) )
return F_39 ( V_1 , V_55 ) ;
if ( ! F_34 ( V_1 , false ) )
return false ;
if ( ! F_39 ( V_1 , V_55 ) )
return false ;
}
return true ;
}
unsigned long T_2 F_40 ( unsigned long V_56 ,
unsigned long V_57 )
{
unsigned long V_1 ;
if ( F_17 ( V_56 >= V_2 || V_57 >= V_2 ) )
return 0 ;
if ( F_17 ( F_41 ( V_58 ) ) )
return V_57 - V_56 ;
if ( V_56 > V_57 )
return 0 ;
for ( V_1 = ( V_56 & ~ ( V_3 * V_4 - 1 ) ) ;
V_1 < F_23 ( V_57 , ( V_3 * V_4 ) ) ;
V_1 += V_3 * V_4 )
{
F_37 ( ! F_35 ( V_1 ) ) ;
}
F_34 ( V_56 , true ) ;
F_34 ( V_57 , true ) ;
for ( V_1 = V_56 ; V_1 < V_57 ; V_1 ++ )
if ( ! F_39 ( V_1 , F_27 ( V_1 ) ) )
break;
if ( ! F_24 ( ( V_1 - V_56 ) != ( V_57 - V_56 ) ,
L_5 ,
( V_57 - V_56 ) - ( V_1 - V_56 ) ) )
F_42 ( V_59 L_6 , V_56 , V_1 ) ;
return V_1 - V_56 ;
}
bool F_39 ( unsigned long V_1 , unsigned long V_55 )
{
unsigned V_18 , V_19 , V_39 ;
if ( F_17 ( F_41 ( V_58 ) ) ) {
F_2 ( V_1 != V_55 && V_55 != V_13 ) ;
return true ;
}
if ( F_17 ( V_1 >= V_2 ) ) {
F_2 ( V_55 != V_13 ) ;
return true ;
}
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_39 = F_4 ( V_1 ) ;
if ( V_55 != V_13 && ( V_55 & V_60 ) ) {
if ( V_21 [ V_18 ] [ V_19 ] == V_31 )
return true ;
if ( V_21 [ V_18 ] [ V_19 ] == V_11 ) {
F_37 ( F_33 ( & V_21 [ V_18 ] [ V_19 ] , V_11 ,
V_31 ) != V_11 ) ;
return true ;
}
}
if ( V_21 [ V_18 ] [ V_19 ] == V_11 )
return V_55 == V_13 ;
V_21 [ V_18 ] [ V_19 ] [ V_39 ] = V_55 ;
return true ;
}
bool F_43 ( unsigned long V_1 , unsigned long V_55 )
{
if ( F_17 ( ! F_39 ( V_1 , V_55 ) ) ) {
if ( ! F_32 ( V_1 ) )
return false ;
if ( ! F_39 ( V_1 , V_55 ) )
return false ;
}
return true ;
}
static void T_2 F_18 ( void )
{
unsigned V_6 ;
V_61 = F_13 ( sizeof( * V_61 ) * V_62 ,
sizeof( unsigned long ) ) ;
for ( V_6 = 0 ; V_6 < V_62 ; V_6 ++ )
F_44 ( & V_61 [ V_6 ] ) ;
}
static unsigned long F_45 ( unsigned long V_55 )
{
return F_46 ( V_55 , V_63 ) ;
}
int F_47 ( unsigned long V_55 , struct V_64 * V_64 ,
struct V_65 * V_66 )
{
unsigned long V_67 ;
unsigned long V_1 ;
unsigned long V_68 ( V_69 ) ;
unsigned V_70 ;
T_3 * V_71 = NULL ;
V_1 = F_48 ( V_64 ) ;
if ( ! F_49 ( V_64 ) ) {
V_69 = ( unsigned long ) F_50 ( V_1 << V_72 ) ;
V_71 = F_51 ( V_69 , & V_70 ) ;
if ( F_24 ( V_71 == NULL || V_70 != V_73 ,
L_7 , V_1 ) )
return - V_74 ;
}
F_37 ( F_52 ( V_64 ) ) ;
F_53 ( V_64 ) ;
F_54 ( V_64 , V_55 ) ;
V_64 -> V_75 = F_55 ( V_1 ) ;
if ( F_17 ( ! F_43 ( V_1 , F_56 ( V_55 ) ) ) )
return - V_76 ;
if ( V_66 != NULL ) {
if ( ! F_49 ( V_64 ) ) {
struct V_77 V_78 =
F_57 ( sizeof( * V_66 ) ) ;
F_58 ( V_78 . V_79 ,
V_80 , V_66 , 1 ) ;
F_59 ( V_81 ) ;
}
}
F_60 ( & V_82 , V_67 ) ;
F_61 ( & V_64 -> V_83 , & V_61 [ F_45 ( V_55 ) ] ) ;
F_62 ( & V_82 , V_67 ) ;
V_1 = F_63 ( V_55 ) ;
if ( F_26 ( V_1 ) == V_55 )
F_43 ( V_1 , F_56 ( V_55 ) ) ;
return 0 ;
}
int F_64 ( struct V_64 * V_64 ,
struct V_65 * V_66 )
{
unsigned long V_67 ;
unsigned long V_55 ;
unsigned long V_1 ;
unsigned long V_68 ( V_69 ) ;
unsigned V_70 ;
T_3 * V_71 = NULL ;
V_1 = F_48 ( V_64 ) ;
V_55 = F_26 ( V_1 ) ;
if ( V_55 == V_13 || ! ( V_55 & V_84 ) )
return - V_74 ;
if ( ! F_49 ( V_64 ) ) {
V_69 = ( unsigned long ) F_50 ( V_1 << V_72 ) ;
V_71 = F_51 ( V_69 , & V_70 ) ;
if ( F_24 ( V_71 == NULL || V_70 != V_73 ,
L_8 , V_1 ) )
return - V_74 ;
}
F_60 ( & V_82 , V_67 ) ;
F_65 ( & V_64 -> V_83 ) ;
F_62 ( & V_82 , V_67 ) ;
F_37 ( ! F_52 ( V_64 ) ) ;
F_66 ( V_64 ) ;
F_43 ( V_1 , V_64 -> V_75 ) ;
if ( V_66 != NULL ) {
if ( ! F_49 ( V_64 ) ) {
struct V_77 V_78 ;
struct V_85 * V_86 ;
struct V_64 * V_87 = F_67 () ;
unsigned long V_88 = ( unsigned long )
F_50 ( F_48 ( V_87 ) << V_72 ) ;
if ( V_66 -> V_89 == - 1 )
F_68 () ;
if ( V_66 -> V_89 == V_90 ) {
F_42 ( V_91 L_9
L_10 ,
V_1 , V_55 ) ;
F_69 () ;
return - 1 ;
}
F_70 () ;
V_78 = F_71 (
sizeof( struct V_85 ) ) ;
V_86 = V_78 . args ;
V_86 -> V_92 = V_66 -> V_92 ;
V_86 -> V_93 = V_88 ;
V_86 -> V_89 = V_66 -> V_89 ;
F_58 ( V_78 . V_79 ,
V_94 , V_86 , 1 ) ;
V_78 = F_71 ( 0 ) ;
F_72 ( V_78 . V_79 , V_88 ,
F_73 ( F_48 ( V_87 ) ,
V_95 ) , 0 ) ;
F_59 ( V_81 ) ;
V_66 -> V_92 = 0 ;
F_69 () ;
}
}
V_55 &= ~ V_84 ;
V_1 = F_63 ( V_55 ) ;
if ( F_26 ( V_1 ) == F_56 ( V_55 ) &&
F_74 ( V_55 ) == NULL )
F_43 ( V_1 , V_55 ) ;
return 0 ;
}
struct V_64 * F_74 ( unsigned long V_55 )
{
unsigned long V_67 ;
struct V_96 * V_97 = & V_61 [ F_45 ( V_55 ) ] ;
struct V_64 * V_42 , * V_98 ;
V_98 = NULL ;
F_60 ( & V_82 , V_67 ) ;
F_75 (p, bucket, lru) {
if ( F_76 ( V_42 ) == V_55 ) {
V_98 = V_42 ;
break;
}
}
F_62 ( & V_82 , V_67 ) ;
return V_98 ;
}
unsigned long F_77 ( unsigned long V_55 , unsigned long V_1 )
{
struct V_64 * V_42 = F_74 ( V_55 ) ;
unsigned long V_98 = V_1 ;
if ( V_42 )
V_98 = F_48 ( V_42 ) ;
return V_98 ;
}
static int F_78 ( struct V_99 * V_100 , void * V_101 )
{
static const char * const V_102 [] = { L_11 , L_12 ,
L_13 , L_14 , L_15 } ;
#define F_79 0
#define F_80 1
#define F_81 2
#define F_82 3
static const char * const V_103 [] = {
[ F_79 ] = L_16 ,
[ F_80 ] = L_17 ,
[ F_81 ] = L_18 ,
[ F_82 ] = L_14 } ;
unsigned long V_1 , V_104 = 0 , V_105 = 0 ;
unsigned int V_68 ( V_106 ) ;
unsigned int V_68 ( V_107 ) ;
if ( ! V_21 )
return 0 ;
for ( V_1 = 0 ; V_1 < V_29 ; V_1 ++ ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 = F_3 ( V_1 ) ;
unsigned V_39 = F_4 ( V_1 ) ;
unsigned V_108 , type ;
V_108 = 4 ;
type = F_82 ;
if ( V_21 [ V_18 ] == V_8 ) {
V_108 = 0 ; type = F_80 ;
} else if ( V_21 [ V_18 ] == NULL ) {
V_108 = 0 ; type = F_82 ;
} else if ( V_21 [ V_18 ] [ V_19 ] == NULL ) {
V_108 = 1 ; type = F_82 ;
} else if ( V_21 [ V_18 ] [ V_19 ] == V_31 ) {
V_108 = 1 ; type = F_79 ;
} else if ( V_21 [ V_18 ] [ V_19 ] == V_11 ) {
V_108 = 1 ; type = F_80 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_39 ] == 0 ) {
V_108 = 2 ; type = F_82 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_39 ] == F_27 ( V_1 ) ) {
V_108 = 2 ; type = F_79 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_39 ] == V_13 ) {
V_108 = 2 ; type = F_80 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_39 ] == V_1 ) {
V_108 = 2 ; type = F_81 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_39 ] != V_1 ) {
V_108 = 2 ; type = F_81 ;
}
if ( V_1 == 0 ) {
V_106 = V_108 ;
V_107 = type ;
}
if ( V_1 == V_29 - 1 ) {
V_108 = 3 ;
type = F_82 ;
}
if ( V_107 != type ) {
F_83 ( V_100 , L_19 ,
V_104 , V_1 , V_103 [ V_107 ] ) ;
V_104 = V_1 ;
V_107 = type ;
}
if ( V_106 != V_108 ) {
F_83 ( V_100 , L_20 ,
V_105 , V_1 , V_102 [ V_106 ] ) ;
V_105 = V_1 ;
V_106 = V_108 ;
}
}
return 0 ;
#undef F_79
#undef F_80
#undef F_81
#undef F_82
}
static int F_84 ( struct V_109 * V_109 , struct V_110 * V_111 )
{
return F_85 ( V_111 , F_78 , NULL ) ;
}
static int T_2 F_86 ( void )
{
struct V_112 * V_113 = F_87 () ;
if ( V_113 == NULL )
return - V_76 ;
V_114 = F_88 ( L_21 , V_113 ) ;
F_89 ( L_22 , 0600 , V_114 , NULL , & V_115 ) ;
return 0 ;
}
