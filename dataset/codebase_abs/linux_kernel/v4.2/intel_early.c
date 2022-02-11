static enum V_1
F_1 ( struct V_2 * * V_3 ,
unsigned int V_4 , struct V_5 * V_6 )
{
struct V_2 * V_7 , * V_8 = NULL ;
struct V_9 * V_10 ;
int V_11 , V_12 , V_13 ;
V_11 = V_6 -> V_14 . V_15 ;
for ( V_13 = 0 ; V_13 < V_4 ; V_13 ++ ) {
V_7 = V_3 [ V_13 ] ;
V_10 = (struct V_9 * ) V_7 ;
V_12 = F_2 ( V_7 ,
V_6 -> V_14 . V_16 ,
V_6 -> V_14 . V_17 ,
V_11 ) ;
if ( ! V_12 )
continue;
V_11 = V_10 -> V_15 ;
V_8 = V_7 ;
}
if ( ! V_8 )
return V_18 ;
V_6 -> V_19 = (struct V_2 * ) V_8 ;
return V_20 ;
}
static inline void
F_3 ( struct V_2 * * V_21 , unsigned long * V_22 ,
unsigned long V_23 , int V_4 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_4 ; V_13 ++ )
V_21 [ V_13 ] = (struct V_2 * ) ( V_22 [ V_13 ] + V_23 ) ;
}
static void
F_4 ( struct V_2 * * V_24 ,
struct V_25 * V_25 )
{
int V_13 ;
struct V_2 * * * V_21 ;
V_21 = (struct V_2 * * * )
F_5 ( & V_25 -> V_21 ) ;
for ( V_13 = 0 ; V_13 < V_25 -> V_26 ; V_13 ++ ) {
struct V_2 * V_27 ;
V_27 = * (struct V_2 * * )
F_5 ( V_25 -> V_21 + V_13 ) ;
V_24 [ V_13 ] = (struct V_2 * ) F_5 ( V_27 ) ;
}
}
static enum V_1
F_6 ( struct V_25 * V_25 , unsigned long * V_22 ,
unsigned long V_28 , struct V_5 * V_6 )
{
struct V_2 * V_24 [ V_29 ] ;
unsigned int V_30 = V_25 -> V_26 ;
if ( ! V_25 -> V_21 ) {
F_3 ( V_24 , V_22 , V_28 , V_30 ) ;
return F_1 ( V_24 , V_30 , V_6 ) ;
} else {
#ifdef F_7
F_4 ( V_24 , V_25 ) ;
return F_1 ( V_24 , V_30 , V_6 ) ;
#else
return F_1 ( V_25 -> V_21 ,
V_30 , V_6 ) ;
#endif
}
}
static enum V_1
F_8 ( struct V_9 * V_31 ,
unsigned long V_16 )
{
unsigned int V_32 , V_33 ;
unsigned int V_34 , V_35 ;
struct V_36 * V_37 ;
unsigned long V_38 = F_9 ( V_31 ) ;
unsigned long V_39 = F_10 ( V_31 ) ;
int V_40 , V_13 ;
struct V_41 * V_42 ;
V_32 = F_11 ( V_16 ) ;
V_33 = F_12 ( V_16 ) ;
V_34 = F_11 ( V_31 -> V_16 ) ;
V_35 = F_12 ( V_31 -> V_16 ) ;
if ( V_32 == V_34 && V_33 == V_35 )
return V_20 ;
if ( V_38 <= V_39 + V_43 )
return V_18 ;
V_37 = ( void * ) V_31 + V_39 + V_43 ;
V_42 = ( void * ) V_37 + V_44 ;
V_40 = V_37 -> V_30 ;
for ( V_13 = 0 ; V_13 < V_40 ; V_13 ++ ) {
V_34 = F_11 ( V_42 -> V_16 ) ;
V_35 = F_12 ( V_42 -> V_16 ) ;
if ( V_32 == V_34 && V_33 == V_35 )
return V_20 ;
V_42 ++ ;
}
return V_18 ;
}
static int
F_13 ( struct V_25 * V_25 ,
struct V_2 * * V_45 ,
unsigned int V_26 )
{
int V_13 , V_46 ;
struct V_2 * * V_47 ;
int V_12 ;
if ( ! V_26 )
return - V_48 ;
V_47 = F_14 ( V_26 , sizeof( struct V_2 * ) , V_49 ) ;
if ( ! V_47 )
return - V_50 ;
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ ) {
struct V_9 * V_10 ;
struct V_2 * V_19 ;
unsigned long V_51 ;
if ( ! V_45 [ V_13 ] ) {
V_12 = - V_48 ;
goto V_52;
}
V_19 = V_45 [ V_13 ] ;
V_10 = & V_19 -> V_53 ;
V_51 = F_9 ( V_10 ) ;
V_47 [ V_13 ] = F_15 ( V_51 , V_49 ) ;
if ( ! V_47 [ V_13 ] ) {
V_12 = - V_50 ;
goto V_52;
}
memcpy ( V_47 [ V_13 ] , V_19 , V_51 ) ;
}
V_25 -> V_21 = V_47 ;
V_25 -> V_26 = V_26 ;
return 0 ;
V_52:
for ( V_46 = 0 ; V_46 <= V_13 ; V_46 ++ )
F_16 ( V_47 [ V_46 ] ) ;
F_16 ( V_47 ) ;
return V_12 ;
}
static unsigned int F_17 ( struct V_2 * * V_21 ,
T_1 * V_7 , unsigned int V_4 )
{
struct V_9 * V_10 , * V_54 ;
unsigned int V_16 , V_17 ;
int V_55 = 0 , V_13 ;
V_10 = (struct V_9 * ) V_7 ;
for ( V_13 = 0 ; V_13 < V_4 ; V_13 ++ ) {
V_54 = (struct V_9 * ) V_21 [ V_13 ] ;
V_16 = V_54 -> V_16 ;
V_17 = V_54 -> V_17 ;
if ( ! F_18 ( V_7 , V_16 , V_17 ) )
continue;
V_55 = 1 ;
if ( V_10 -> V_15 <= V_54 -> V_15 )
continue;
V_21 [ V_13 ] = (struct V_2 * ) V_7 ;
break;
}
if ( V_13 >= V_4 && ! V_55 )
V_21 [ V_4 ++ ] = (struct V_2 * ) V_7 ;
return V_4 ;
}
static enum V_1 T_2
F_19 ( int V_56 , unsigned long V_57 ,
void * V_58 , T_3 V_51 ,
struct V_25 * V_25 ,
unsigned long * V_59 ,
struct V_5 * V_6 )
{
T_1 * V_7 = V_58 ;
unsigned int V_60 = V_51 ;
enum V_1 V_61 = V_20 ;
unsigned int V_62 ;
struct V_9 * V_31 ;
struct V_2 * V_24 [ V_29 ] ;
unsigned int V_26 = V_25 -> V_26 ;
int V_13 ;
while ( V_60 && V_26 < F_20 ( V_24 ) ) {
if ( V_60 < sizeof( V_31 ) )
break;
V_31 = (struct V_9 * ) V_7 ;
V_62 = F_9 ( V_31 ) ;
if ( ! V_62 || V_62 > V_60 ||
F_21 ( V_7 , 0 ) < 0 )
break;
V_60 -= V_62 ;
if ( F_8 ( V_31 , V_6 -> V_14 . V_16 ) !=
V_20 ) {
V_7 += V_62 ;
continue;
}
V_26 = F_17 ( V_24 , V_7 , V_26 ) ;
V_7 += V_62 ;
}
if ( V_60 ) {
V_61 = V_63 ;
goto V_64;
}
if ( V_26 == 0 ) {
V_61 = V_18 ;
goto V_64;
}
for ( V_13 = 0 ; V_13 < V_26 ; V_13 ++ )
V_59 [ V_13 ] = ( unsigned long ) V_24 [ V_13 ] - V_57 ;
V_25 -> V_26 = V_26 ;
V_64:
return V_61 ;
}
static int F_22 ( struct V_5 * V_6 )
{
unsigned int V_65 [ 2 ] ;
unsigned int V_66 , V_33 ;
struct V_67 V_68 ;
unsigned int V_69 , V_70 , V_71 , V_72 ;
V_68 . V_16 = 0 ;
V_68 . V_17 = 0 ;
V_68 . V_15 = 0 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_69 = 0x00000001 ;
V_71 = 0 ;
F_23 ( & V_69 , & V_70 , & V_71 , & V_72 ) ;
V_68 . V_16 = V_69 ;
V_66 = F_11 ( V_68 . V_16 ) ;
V_33 = F_12 ( V_68 . V_16 ) ;
if ( ( V_33 >= 5 ) || ( V_66 > 6 ) ) {
F_24 ( V_73 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
V_68 . V_17 = 1 << ( ( V_65 [ 1 ] >> 18 ) & 7 ) ;
}
F_25 ( V_74 , 0 , 0 ) ;
F_26 () ;
F_24 ( V_74 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
V_68 . V_15 = V_65 [ 1 ] ;
V_6 -> V_14 = V_68 ;
V_6 -> V_75 = 1 ;
return 0 ;
}
static void T_4 F_27 ( void )
{
int V_13 , V_46 ;
unsigned int V_16 , V_17 , V_15 , V_38 , V_39 , V_76 ;
struct V_5 V_6 ;
if ( V_25 . V_26 == 0 ) {
F_28 ( L_1 ) ;
return;
}
F_28 ( L_2 , V_25 . V_26 ) ;
F_22 ( & V_6 ) ;
V_16 = V_6 . V_14 . V_16 ;
V_17 = V_6 . V_14 . V_17 ;
V_15 = V_6 . V_14 . V_15 ;
F_28 ( L_3 , V_16 , V_17 , V_15 ) ;
for ( V_13 = 0 ; V_13 < V_25 . V_26 ; V_13 ++ ) {
struct V_9 * V_77 ;
struct V_36 * V_37 ;
int V_40 ;
struct V_41 * V_42 ;
V_77 = (struct V_9 * )
V_25 . V_21 [ V_13 ] ;
V_16 = V_77 -> V_16 ;
V_17 = V_77 -> V_17 ;
V_15 = V_77 -> V_15 ;
V_38 = F_9 ( V_77 ) ;
V_39 = F_10 ( V_77 ) ;
V_76 = V_77 -> V_76 ;
F_28 ( L_4 ,
V_13 , V_16 , V_17 , V_15 , V_38 ,
V_76 & 0xffff ,
V_76 >> 24 ,
( V_76 >> 16 ) & 0xff ) ;
if ( V_38 <= V_39 + V_43 )
continue;
V_37 = ( void * ) V_77 + V_39 + V_43 ;
V_40 = V_37 -> V_30 ;
V_42 = ( void * ) V_37 + V_44 ;
for ( V_46 = 0 ; V_46 < V_40 ; V_46 ++ ) {
V_16 = V_42 -> V_16 ;
V_17 = V_42 -> V_17 ;
F_28 ( L_5 ,
V_46 , V_16 , V_17 ) ;
V_42 ++ ;
}
}
}
static inline void F_27 ( void )
{
}
int F_29 ( T_1 * V_19 )
{
struct V_2 * V_24 [ V_29 ] ;
unsigned int V_78 ;
unsigned int V_26 ;
struct V_2 * * V_21 ;
int V_12 = 0 ;
int V_13 ;
F_30 ( & V_79 ) ;
V_78 = V_25 . V_26 ;
V_26 = V_25 . V_26 ;
V_21 = V_25 . V_21 ;
if ( V_21 && V_26 )
memcpy ( V_24 , V_21 ,
V_26 * sizeof( struct V_2 * ) ) ;
V_26 = F_17 ( V_24 , V_19 , V_26 ) ;
V_12 = F_13 ( & V_25 , V_24 , V_26 ) ;
if ( V_12 ) {
F_31 ( L_6 ) ;
goto V_64;
}
F_27 () ;
if ( V_21 ) {
for ( V_13 = 0 ; V_13 < V_78 ; V_13 ++ )
F_16 ( V_21 [ V_13 ] ) ;
F_16 ( V_21 ) ;
}
V_64:
F_32 ( & V_79 ) ;
return V_12 ;
}
static bool T_2 F_33 ( struct V_80 * V_81 )
{
#ifdef F_34
unsigned int V_69 = 0x00000001 , V_70 , V_71 = 0 , V_72 ;
unsigned int V_66 , V_33 , V_82 ;
char V_83 [ 30 ] ;
F_23 ( & V_69 , & V_70 , & V_71 , & V_72 ) ;
V_66 = F_11 ( V_69 ) ;
V_33 = F_12 ( V_69 ) ;
V_82 = V_69 & 0xf ;
sprintf ( V_83 , L_7 , V_66 , V_33 , V_82 ) ;
return F_35 ( V_81 , V_83 ) ;
#else
return false ;
#endif
}
static T_2 enum V_1
F_36 ( struct V_25 * V_25 , unsigned long * V_22 ,
unsigned long V_57 , unsigned long V_51 ,
struct V_5 * V_6 )
{
struct V_80 V_84 ;
long V_85 = 0 ;
#ifdef F_7
char * V_27 = ( char * ) F_5 ( V_86 ) ;
#else
char * V_27 = V_86 ;
#endif
V_84 . V_58 = NULL ;
V_84 . V_51 = 0 ;
V_84 = F_37 ( V_27 , ( void * ) V_57 , V_51 , & V_85 ) ;
if ( ! V_84 . V_58 ) {
if ( ! F_33 ( & V_84 ) )
return V_63 ;
}
return F_19 ( 0 , V_57 , V_84 . V_58 , V_84 . V_51 ,
V_25 , V_22 , V_6 ) ;
}
static void
F_38 ( struct V_5 * V_6 , unsigned int V_76 )
{
int V_56 = F_39 () ;
F_40 ( L_8 ,
V_56 ,
V_6 -> V_14 . V_15 ,
V_76 & 0xffff ,
V_76 >> 24 ,
( V_76 >> 16 ) & 0xff ) ;
}
void F_41 ( void )
{
struct V_5 V_6 ;
if ( V_87 ) {
F_22 ( & V_6 ) ;
F_38 ( & V_6 , V_88 ) ;
V_87 = 0 ;
}
}
static void F_42 ( struct V_5 * V_6 )
{
struct V_2 * V_89 ;
int * V_90 ;
int * V_91 ;
V_89 = V_6 -> V_19 ;
if ( V_89 == NULL )
return;
V_90 = ( int * ) F_5 ( & V_87 ) ;
V_91 = ( int * ) F_5 ( & V_88 ) ;
* V_90 = 1 ;
* V_91 = V_89 -> V_53 . V_76 ;
}
static inline void F_43 ( void )
{
F_44 () ;
}
static inline void F_42 ( struct V_5 * V_6 )
{
struct V_2 * V_89 ;
V_89 = V_6 -> V_19 ;
if ( V_89 == NULL )
return;
F_38 ( V_6 , V_89 -> V_53 . V_76 ) ;
}
static int F_45 ( struct V_5 * V_6 , bool V_92 )
{
struct V_2 * V_89 ;
unsigned int V_65 [ 2 ] ;
V_89 = V_6 -> V_19 ;
if ( V_89 == NULL )
return 0 ;
F_25 ( V_93 ,
( unsigned long ) V_89 -> V_94 ,
( unsigned long ) V_89 -> V_94 >> 16 >> 16 ) ;
F_25 ( V_74 , 0 , 0 ) ;
F_26 () ;
F_24 ( V_74 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
if ( V_65 [ 1 ] != V_89 -> V_53 . V_15 )
return - 1 ;
#ifdef F_34
F_43 () ;
#endif
V_6 -> V_14 . V_15 = V_65 [ 1 ] ;
if ( V_92 )
F_42 ( V_6 ) ;
else
F_38 ( V_6 , V_89 -> V_53 . V_76 ) ;
return 0 ;
}
int T_2 F_46 ( void )
{
unsigned int V_30 = V_25 . V_26 ;
struct V_2 * V_21 [ V_29 ] ;
int V_12 = 0 ;
if ( V_30 == 0 )
return V_12 ;
F_3 ( V_21 , V_59 , V_28 , V_30 ) ;
V_12 = F_13 ( & V_25 , V_21 , V_30 ) ;
if ( V_12 )
F_31 ( L_9 ) ;
F_27 () ;
return V_12 ;
}
static void T_2
F_47 ( struct V_25 * V_25 ,
unsigned long * V_22 ,
unsigned long V_57 , unsigned long V_51 )
{
struct V_5 V_6 ;
enum V_1 V_12 ;
F_22 ( & V_6 ) ;
V_12 = F_36 ( V_25 , V_22 , V_57 , V_51 , & V_6 ) ;
if ( V_12 != V_20 )
return;
V_12 = F_6 ( V_25 , V_22 , V_57 , & V_6 ) ;
if ( V_12 != V_20 )
return;
F_45 ( & V_6 , true ) ;
}
void T_2 F_48 ( void )
{
T_5 V_57 , V_51 ;
#ifdef F_7
struct V_95 * V_27 ;
V_27 = (struct V_95 * ) F_5 ( & V_95 ) ;
V_57 = V_27 -> V_53 . V_96 ;
V_51 = V_27 -> V_53 . V_97 ;
F_47 (
(struct V_25 * ) F_5 ( & V_25 ) ,
( unsigned long * ) F_5 ( & V_59 ) ,
V_57 , V_51 ) ;
#else
V_57 = V_95 . V_53 . V_96 + V_98 ;
V_51 = V_95 . V_53 . V_97 ;
F_47 ( & V_25 , V_59 , V_57 , V_51 ) ;
#endif
}
void F_49 ( void )
{
struct V_25 * V_99 ;
struct V_5 V_6 ;
unsigned long * V_100 ;
unsigned long V_101 ;
enum V_1 V_12 ;
#ifdef F_7
unsigned long * V_102 ;
V_100 =
( unsigned long * ) F_5 ( V_59 ) ;
V_99 = (struct V_25 * ) F_5 ( & V_25 ) ;
V_102 = ( unsigned long * ) F_5 ( & V_28 ) ;
V_101 = ( unsigned long ) F_5 ( * V_102 ) ;
#else
V_99 = & V_25 ;
V_100 = V_59 ;
V_101 = V_28 ;
#endif
if ( V_99 -> V_26 == 0 )
return;
F_22 ( & V_6 ) ;
V_12 = F_6 ( V_99 , V_100 ,
V_101 , & V_6 ) ;
if ( V_12 != V_20 )
return;
F_45 ( & V_6 , true ) ;
}
void F_50 ( void )
{
struct V_5 V_6 ;
enum V_1 V_12 ;
if ( ! V_25 . V_26 )
return;
F_22 ( & V_6 ) ;
V_12 = F_1 ( V_25 . V_21 ,
V_25 . V_26 , & V_6 ) ;
if ( V_12 != V_20 )
return;
F_45 ( & V_6 , false ) ;
}
