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
V_12 = F_2 ( V_6 -> V_14 . V_16 ,
V_6 -> V_14 . V_17 ,
V_11 ,
V_7 ) ;
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
unsigned int V_16 , V_17 , V_11 ;
int V_55 = 0 , V_13 ;
V_10 = (struct V_9 * ) V_7 ;
for ( V_13 = 0 ; V_13 < V_4 ; V_13 ++ ) {
V_54 = (struct V_9 * ) V_21 [ V_13 ] ;
V_16 = V_54 -> V_16 ;
V_17 = V_54 -> V_17 ;
V_11 = V_10 -> V_15 ;
if ( ! F_18 ( V_16 , V_17 , V_11 , V_7 ) )
continue;
V_55 = 1 ;
if ( ! F_19 ( V_10 , V_11 ) )
continue;
V_21 [ V_13 ] = (struct V_2 * ) V_7 ;
break;
}
if ( V_13 >= V_4 && ! V_55 )
V_21 [ V_4 ++ ] = (struct V_2 * ) V_7 ;
return V_4 ;
}
static enum V_1 T_2
F_20 ( int V_56 , unsigned long V_57 ,
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
while ( V_60 && V_26 < F_21 ( V_24 ) ) {
if ( V_60 < sizeof( V_31 ) )
break;
V_31 = (struct V_9 * ) V_7 ;
V_62 = F_9 ( V_31 ) ;
if ( ! V_62 || V_62 > V_60 ||
F_22 ( V_7 , 0 ) < 0 )
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
static int F_23 ( struct V_5 * V_6 )
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
F_24 ( & V_69 , & V_70 , & V_71 , & V_72 ) ;
V_68 . V_16 = V_69 ;
V_66 = F_11 ( V_68 . V_16 ) ;
V_33 = F_12 ( V_68 . V_16 ) ;
if ( ( V_33 >= 5 ) || ( V_66 > 6 ) ) {
F_25 ( V_73 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
V_68 . V_17 = 1 << ( ( V_65 [ 1 ] >> 18 ) & 7 ) ;
}
F_26 ( V_74 , 0 , 0 ) ;
F_27 () ;
F_25 ( V_74 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
V_68 . V_15 = V_65 [ 1 ] ;
V_6 -> V_14 = V_68 ;
V_6 -> V_75 = 1 ;
return 0 ;
}
static void T_4 F_28 ( void )
{
int V_13 , V_46 ;
unsigned int V_16 , V_17 , V_15 , V_38 , V_39 , V_76 ;
struct V_5 V_6 ;
if ( V_25 . V_26 == 0 ) {
F_29 ( L_1 ) ;
return;
}
F_29 ( L_2 , V_25 . V_26 ) ;
F_23 ( & V_6 ) ;
V_16 = V_6 . V_14 . V_16 ;
V_17 = V_6 . V_14 . V_17 ;
V_15 = V_6 . V_14 . V_15 ;
F_29 ( L_3 , V_16 , V_17 , V_15 ) ;
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
F_29 ( L_4 ,
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
F_29 ( L_5 ,
V_46 , V_16 , V_17 ) ;
V_42 ++ ;
}
}
}
static inline void F_28 ( void )
{
}
int F_30 ( T_1 * V_19 )
{
struct V_2 * V_24 [ V_29 ] ;
unsigned int V_78 ;
unsigned int V_26 ;
struct V_2 * * V_21 ;
int V_12 = 0 ;
int V_13 ;
F_31 ( & V_79 ) ;
V_78 = V_25 . V_26 ;
V_26 = V_25 . V_26 ;
V_21 = V_25 . V_21 ;
if ( V_21 && V_26 )
memcpy ( V_24 , V_21 ,
V_26 * sizeof( struct V_2 * ) ) ;
V_26 = F_17 ( V_24 , V_19 , V_26 ) ;
V_12 = F_13 ( & V_25 , V_24 , V_26 ) ;
if ( V_12 ) {
F_32 ( L_6 ) ;
goto V_64;
}
F_28 () ;
if ( V_21 ) {
for ( V_13 = 0 ; V_13 < V_78 ; V_13 ++ )
F_16 ( V_21 [ V_13 ] ) ;
F_16 ( V_21 ) ;
}
V_64:
F_33 ( & V_79 ) ;
return V_12 ;
}
static T_2 enum V_1
F_34 ( struct V_25 * V_25 , unsigned long * V_22 ,
unsigned long V_57 , unsigned long V_51 ,
struct V_5 * V_6 )
{
struct V_80 V_81 ;
long V_82 = 0 ;
#ifdef F_7
char * V_27 = ( char * ) F_5 ( V_83 ) ;
#else
char * V_27 = V_83 ;
#endif
V_81 . V_58 = NULL ;
V_81 . V_51 = 0 ;
V_81 = F_35 ( V_27 , ( void * ) V_57 , V_51 , & V_82 ) ;
if ( ! V_81 . V_58 )
return V_63 ;
return F_20 ( 0 , V_57 , V_81 . V_58 , V_81 . V_51 ,
V_25 , V_22 , V_6 ) ;
}
static void
F_36 ( struct V_5 * V_6 , unsigned int V_76 )
{
int V_56 = F_37 () ;
F_38 ( L_7 ,
V_56 ,
V_6 -> V_14 . V_15 ,
V_76 & 0xffff ,
V_76 >> 24 ,
( V_76 >> 16 ) & 0xff ) ;
}
void F_39 ( void )
{
struct V_5 V_6 ;
if ( V_84 ) {
F_23 ( & V_6 ) ;
F_36 ( & V_6 , V_85 ) ;
V_84 = 0 ;
}
}
static void F_40 ( struct V_5 * V_6 )
{
struct V_2 * V_86 ;
int * V_87 ;
int * V_88 ;
V_86 = V_6 -> V_19 ;
if ( V_86 == NULL )
return;
V_87 = ( int * ) F_5 ( & V_84 ) ;
V_88 = ( int * ) F_5 ( & V_85 ) ;
* V_87 = 1 ;
* V_88 = V_86 -> V_53 . V_76 ;
}
static inline void F_41 ( void )
{
F_42 () ;
}
static inline void F_40 ( struct V_5 * V_6 )
{
struct V_2 * V_86 ;
V_86 = V_6 -> V_19 ;
if ( V_86 == NULL )
return;
F_36 ( V_6 , V_86 -> V_53 . V_76 ) ;
}
static int F_43 ( struct V_5 * V_6 , bool V_89 )
{
struct V_2 * V_86 ;
unsigned int V_65 [ 2 ] ;
V_86 = V_6 -> V_19 ;
if ( V_86 == NULL )
return 0 ;
F_26 ( V_90 ,
( unsigned long ) V_86 -> V_91 ,
( unsigned long ) V_86 -> V_91 >> 16 >> 16 ) ;
F_26 ( V_74 , 0 , 0 ) ;
F_27 () ;
F_25 ( V_74 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
if ( V_65 [ 1 ] != V_86 -> V_53 . V_15 )
return - 1 ;
#ifdef F_44
F_41 () ;
#endif
V_6 -> V_14 . V_15 = V_65 [ 1 ] ;
if ( V_89 )
F_40 ( V_6 ) ;
else
F_36 ( V_6 , V_86 -> V_53 . V_76 ) ;
return 0 ;
}
int T_2 F_45 ( void )
{
unsigned int V_30 = V_25 . V_26 ;
struct V_2 * V_21 [ V_29 ] ;
int V_12 = 0 ;
if ( V_30 == 0 )
return V_12 ;
F_3 ( V_21 , V_59 , V_28 , V_30 ) ;
V_12 = F_13 ( & V_25 , V_21 , V_30 ) ;
if ( V_12 )
F_32 ( L_8 ) ;
F_28 () ;
return V_12 ;
}
static void T_2
F_46 ( struct V_25 * V_25 ,
unsigned long * V_22 ,
unsigned long V_57 , unsigned long V_51 )
{
struct V_5 V_6 ;
enum V_1 V_12 ;
F_23 ( & V_6 ) ;
V_12 = F_34 ( V_25 , V_22 , V_57 , V_51 , & V_6 ) ;
if ( V_12 != V_20 )
return;
V_12 = F_6 ( V_25 , V_22 , V_57 , & V_6 ) ;
if ( V_12 != V_20 )
return;
F_43 ( & V_6 , true ) ;
}
void T_2 F_47 ( void )
{
T_5 V_57 , V_51 ;
#ifdef F_7
struct V_92 * V_27 ;
V_27 = (struct V_92 * ) F_5 ( & V_92 ) ;
V_57 = V_27 -> V_53 . V_93 ;
V_51 = V_27 -> V_53 . V_94 ;
F_46 (
(struct V_25 * ) F_5 ( & V_25 ) ,
( unsigned long * ) F_5 ( & V_59 ) ,
V_57 , V_51 ) ;
#else
V_57 = V_92 . V_53 . V_93 + V_95 ;
V_51 = V_92 . V_53 . V_94 ;
F_46 ( & V_25 , V_59 , V_57 , V_51 ) ;
#endif
}
void F_48 ( void )
{
struct V_25 * V_96 ;
struct V_5 V_6 ;
unsigned long * V_97 ;
unsigned long V_98 ;
enum V_1 V_12 ;
#ifdef F_7
unsigned long * V_99 ;
V_97 =
( unsigned long * ) F_5 ( V_59 ) ;
V_96 = (struct V_25 * ) F_5 ( & V_25 ) ;
V_99 = ( unsigned long * ) F_5 ( & V_28 ) ;
V_98 = ( unsigned long ) F_5 ( * V_99 ) ;
#else
V_96 = & V_25 ;
V_97 = V_59 ;
V_98 = V_28 ;
#endif
if ( V_96 -> V_26 == 0 )
return;
F_23 ( & V_6 ) ;
V_12 = F_6 ( V_96 , V_97 ,
V_98 , & V_6 ) ;
if ( V_12 != V_20 )
return;
F_43 ( & V_6 , true ) ;
}
void F_49 ( void )
{
struct V_5 V_6 ;
enum V_1 V_12 ;
if ( ! V_25 . V_26 )
return;
F_23 ( & V_6 ) ;
V_12 = F_1 ( V_25 . V_21 ,
V_25 . V_26 , & V_6 ) ;
if ( V_12 != V_20 )
return;
F_43 ( & V_6 , false ) ;
}
