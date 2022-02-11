static enum V_1
F_1 ( struct V_2 * * V_3 ,
unsigned int V_4 ,
struct V_5 * V_6 )
{
struct V_2 * V_7 , * V_8 = NULL ;
int V_9 = V_6 -> V_10 . V_11 ;
enum V_1 V_12 = V_13 ;
unsigned int V_14 ;
struct V_15 * V_16 ;
unsigned int V_17 = V_6 -> V_10 . V_18 ;
unsigned int V_19 = V_6 -> V_10 . V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_4 ; V_21 ++ ) {
V_7 = V_3 [ V_21 ] ;
V_16 = (struct V_15 * ) V_7 ;
V_14 = F_2 ( V_16 ) ;
if ( F_3 ( V_17 , V_19 , V_7 , V_9 ) ) {
V_9 = V_16 -> V_11 ;
V_8 = V_7 ;
}
}
if ( ! V_8 ) {
V_12 = V_22 ;
goto V_23;
}
V_6 -> V_24 = (struct V_2 * ) V_8 ;
V_23:
return V_12 ;
}
static void
F_4 ( struct V_2 * * V_25 ,
unsigned long * V_26 ,
unsigned long V_27 , int V_4 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_4 ; V_21 ++ )
V_25 [ V_21 ] = (struct V_2 * )
( V_26 [ V_21 ] + V_27 ) ;
}
static void
F_5 ( struct V_2 * * V_28 ,
struct V_29 * V_29 )
{
int V_21 ;
struct V_2 * * * V_25 ;
V_25 = (struct V_2 * * * )
F_6 ( & V_29 -> V_25 ) ;
for ( V_21 = 0 ; V_21 < V_29 -> V_4 ; V_21 ++ ) {
struct V_2 * V_30 ;
V_30 = * (struct V_2 * * )
F_6 ( V_29 -> V_25 + V_21 ) ;
V_28 [ V_21 ] = (struct V_2 * ) F_6 ( V_30 ) ;
}
}
static enum V_1
F_7 ( struct V_29 * V_29 ,
unsigned long * V_26 ,
unsigned long V_27 ,
struct V_5 * V_6 )
{
struct V_2 * V_28 [ V_31 ] ;
unsigned int V_32 = V_29 -> V_4 ;
if ( ! V_29 -> V_25 ) {
F_4 ( V_28 , V_26 ,
V_27 , V_32 ) ;
return F_1 ( V_28 , V_32 , V_6 ) ;
} else {
#ifdef F_8
F_5 ( V_28 , V_29 ) ;
return F_1 ( V_28 , V_32 , V_6 ) ;
#else
return F_1 ( V_29 -> V_25 ,
V_32 , V_6 ) ;
#endif
}
}
static T_1 F_9 ( unsigned long V_18 )
{
T_1 V_33 ;
V_33 = ( V_18 >> 8 ) & 0xf ;
if ( V_33 == 0xf )
V_33 += ( V_18 >> 20 ) & 0xff ;
return V_33 ;
}
static T_1 F_10 ( unsigned long V_18 )
{
T_1 V_33 , V_34 ;
V_33 = F_9 ( V_18 ) ;
V_34 = ( V_18 >> 4 ) & 0xf ;
if ( V_33 == 0x6 || V_33 == 0xf )
V_34 += ( ( V_18 >> 16 ) & 0xf ) << 4 ;
return V_34 ;
}
static enum V_1
F_11 ( struct V_15 * V_16 ,
unsigned long V_18 )
{
T_1 V_33 , V_34 ;
T_1 V_35 , V_36 ;
struct V_37 * V_38 ;
unsigned long V_39 = F_2 ( V_16 ) ;
unsigned long V_40 = F_12 ( V_16 ) ;
int V_41 , V_21 ;
struct V_42 * V_43 ;
V_33 = F_9 ( V_18 ) ;
V_34 = F_10 ( V_18 ) ;
V_35 = F_9 ( V_16 -> V_18 ) ;
V_36 = F_10 ( V_16 -> V_18 ) ;
if ( V_33 == V_35 && V_34 == V_36 )
return V_13 ;
if ( V_39 <= V_40 + V_44 )
return V_22 ;
V_38 = (struct V_37 * )
V_16 + V_40 + V_44 ;
V_41 = V_38 -> V_32 ;
V_43 = ( void * ) V_38 + V_45 ;
for ( V_21 = 0 ; V_21 < V_41 ; V_21 ++ ) {
V_35 = F_9 ( V_43 -> V_18 ) ;
V_36 = F_10 ( V_43 -> V_18 ) ;
if ( V_33 == V_35 && V_34 == V_36 )
return V_13 ;
V_43 ++ ;
}
return V_22 ;
}
static int
F_13 ( struct V_29 * V_29 ,
struct V_2 * * V_46 ,
unsigned int V_4 )
{
int V_21 , V_47 ;
struct V_2 * * V_3 ;
int V_48 ;
if ( ! V_4 )
return - V_49 ;
V_3 = F_14 ( V_4 * sizeof( struct V_2 * ) ,
V_50 ) ;
if ( ! V_3 )
return - V_51 ;
for ( V_21 = 0 ; V_21 < V_4 ; V_21 ++ ) {
struct V_2 * V_24 = V_46 [ V_21 ] ;
struct V_15 * V_16 = & V_24 -> V_52 ;
unsigned long V_14 = F_2 ( V_16 ) ;
V_3 [ V_21 ] = F_14 ( V_14 , V_50 ) ;
if ( ! V_3 [ V_21 ] ) {
V_48 = - V_51 ;
goto V_53;
}
if ( ! V_46 [ V_21 ] ) {
V_48 = - V_49 ;
goto V_53;
}
memcpy ( V_3 [ V_21 ] , V_24 , V_14 ) ;
}
V_29 -> V_25 = V_3 ;
V_29 -> V_4 = V_4 ;
return 0 ;
V_53:
for ( V_47 = 0 ; V_47 <= V_21 ; V_47 ++ )
F_15 ( V_3 [ V_47 ] ) ;
F_15 ( V_3 ) ;
return V_48 ;
}
static void F_16 ( struct V_2 * * V_25 , T_1 * V_7 ,
unsigned int * V_54 )
{
int V_21 ;
int V_55 = 0 ;
unsigned int V_4 = * V_54 ;
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) V_7 ;
for ( V_21 = 0 ; V_21 < V_4 ; V_21 ++ ) {
unsigned int V_18 , V_20 ;
unsigned int V_9 ;
struct V_15 * V_56 =
(struct V_15 * ) V_25 [ V_21 ] ;
V_18 = V_56 -> V_18 ;
V_20 = V_56 -> V_20 ;
V_9 = V_16 -> V_11 ;
if ( F_17 ( V_18 , V_20 , V_7 , V_9 ) ) {
V_55 = 1 ;
if ( F_18 ( V_16 , V_9 ) ) {
V_25 [ V_21 ] =
(struct V_2 * ) V_7 ;
break;
}
}
}
if ( V_21 >= V_4 && ! V_55 )
V_25 [ V_4 ++ ] =
(struct V_2 * ) V_7 ;
* V_54 = V_4 ;
}
static enum V_1 T_2
F_19 ( int V_57 , unsigned long V_58 ,
void * V_59 , T_3 V_60 ,
struct V_29 * V_29 ,
unsigned long * V_26 ,
struct V_5 * V_6 )
{
T_1 * V_7 = V_59 ;
unsigned int V_61 = V_60 ;
enum V_1 V_12 = V_13 ;
unsigned int V_14 ;
struct V_15 * V_16 ;
struct V_2 * V_28 [ V_31 ] ;
unsigned int V_4 = V_29 -> V_4 ;
int V_21 ;
while ( V_61 ) {
V_16 = (struct V_15 * ) V_7 ;
V_14 = F_2 ( V_16 ) ;
if ( ! V_14 || V_14 > V_61 ||
F_20 ( V_7 , 0 ) < 0 )
break;
V_61 -= V_14 ;
if ( F_11 ( V_16 , V_6 -> V_10 . V_18 ) !=
V_13 ) {
V_7 += V_14 ;
continue;
}
F_16 ( V_28 , V_7 , & V_4 ) ;
V_7 += V_14 ;
}
if ( V_61 ) {
V_12 = V_62 ;
goto V_23;
}
if ( V_4 == 0 ) {
V_12 = V_22 ;
goto V_23;
}
for ( V_21 = 0 ; V_21 < V_4 ; V_21 ++ )
V_26 [ V_21 ] = ( unsigned long ) V_28 [ V_21 ] - V_58 ;
V_29 -> V_4 = V_4 ;
V_23:
return V_12 ;
}
static int F_21 ( struct V_5 * V_6 )
{
unsigned int V_63 [ 2 ] ;
T_1 V_33 , V_34 ;
struct V_64 V_17 ;
unsigned int V_65 , V_66 , V_67 , V_68 ;
V_17 . V_18 = 0 ;
V_17 . V_20 = 0 ;
V_17 . V_11 = 0 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_65 = 0x00000001 ;
V_67 = 0 ;
F_22 ( & V_65 , & V_66 , & V_67 , & V_68 ) ;
V_17 . V_18 = V_65 ;
V_33 = F_9 ( V_17 . V_18 ) ;
V_34 = F_10 ( V_17 . V_18 ) ;
if ( ( V_34 >= 5 ) || ( V_33 > 6 ) ) {
F_23 ( V_69 , V_63 [ 0 ] , V_63 [ 1 ] ) ;
V_17 . V_20 = 1 << ( ( V_63 [ 1 ] >> 18 ) & 7 ) ;
}
F_24 ( V_70 , 0 , 0 ) ;
F_25 () ;
F_23 ( V_70 , V_63 [ 0 ] , V_63 [ 1 ] ) ;
V_17 . V_11 = V_63 [ 1 ] ;
V_6 -> V_10 = V_17 ;
V_6 -> V_71 = 1 ;
return 0 ;
}
static void T_4 F_26 ( void )
{
int V_21 , V_47 ;
unsigned int V_18 , V_20 , V_11 , V_39 , V_40 , V_72 ;
struct V_5 V_6 ;
if ( V_29 . V_4 == 0 ) {
F_27 ( L_1 ) ;
return;
}
F_27 ( L_2 , V_29 . V_4 ) ;
F_21 ( & V_6 ) ;
V_18 = V_6 . V_10 . V_18 ;
V_20 = V_6 . V_10 . V_20 ;
V_11 = V_6 . V_10 . V_11 ;
F_27 ( L_3 ,
F_28 () , V_18 , V_20 , V_11 ) ;
for ( V_21 = 0 ; V_21 < V_29 . V_4 ; V_21 ++ ) {
struct V_15 * V_56 ;
struct V_37 * V_38 ;
int V_41 ;
struct V_42 * V_43 ;
V_56 = (struct V_15 * )
V_29 . V_25 [ V_21 ] ;
V_18 = V_56 -> V_18 ;
V_20 = V_56 -> V_20 ;
V_11 = V_56 -> V_11 ;
V_39 = F_2 ( V_56 ) ;
V_40 = F_12 ( V_56 ) ;
V_72 = V_56 -> V_72 ;
F_27 ( L_4 ,
V_21 , V_18 , V_20 , V_11 , V_39 ,
V_72 & 0xffff ,
V_72 >> 24 ,
( V_72 >> 16 ) & 0xff ) ;
if ( V_39 <= V_40 + V_44 )
continue;
V_38 = (struct V_37 * )
V_56 + V_40 + V_44 ;
V_41 = V_38 -> V_32 ;
V_43 = ( void * ) V_38 + V_45 ;
for ( V_47 = 0 ; V_47 < V_41 ; V_47 ++ ) {
V_18 = V_43 -> V_18 ;
V_20 = V_43 -> V_20 ;
F_27 ( L_5 ,
V_47 , V_18 , V_20 ) ;
V_43 ++ ;
}
}
}
static inline void F_26 ( void )
{
}
int F_29 ( T_1 * V_24 )
{
struct V_2 * V_28 [ V_31 ] ;
unsigned int V_73 ;
unsigned int V_4 ;
struct V_2 * * V_25 ;
int V_48 = 0 ;
int V_21 ;
F_30 ( & V_74 ) ;
V_73 = V_29 . V_4 ;
V_4 = V_29 . V_4 ;
V_25 = V_29 . V_25 ;
if ( V_25 && V_4 )
memcpy ( V_28 , V_25 ,
V_4 * sizeof( struct V_2 * ) ) ;
F_16 ( V_28 , V_24 , & V_4 ) ;
V_48 = F_13 ( & V_29 , V_28 , V_4 ) ;
if ( V_48 ) {
F_31 ( L_6 ) ;
goto V_23;
}
F_26 () ;
if ( V_25 ) {
for ( V_21 = 0 ; V_21 < V_73 ; V_21 ++ )
F_15 ( V_25 [ V_21 ] ) ;
F_15 ( V_25 ) ;
}
V_23:
F_32 ( & V_74 ) ;
return V_48 ;
}
static T_2 enum V_1
F_33 ( unsigned long V_58 , unsigned long V_75 ,
struct V_29 * V_29 ,
unsigned long * V_26 ,
struct V_5 * V_6 )
{
unsigned int V_60 = V_75 - V_58 + 1 ;
struct V_76 V_77 ;
long V_78 = 0 ;
#ifdef F_8
char * V_30 = ( char * ) F_6 ( V_79 ) ;
#else
char * V_30 = V_79 ;
#endif
V_77 . V_59 = NULL ;
V_77 . V_60 = 0 ;
V_77 = F_34 ( V_30 , ( void * ) V_58 , V_60 , & V_78 ) ;
if ( ! V_77 . V_59 )
return V_62 ;
return F_19 ( 0 , V_58 , V_77 . V_59 , V_77 . V_60 ,
V_29 , V_26 ,
V_6 ) ;
}
static void
F_35 ( struct V_5 * V_6 , unsigned int V_72 )
{
int V_57 = F_28 () ;
F_36 ( L_7 ,
V_57 ,
V_6 -> V_10 . V_11 ,
V_72 & 0xffff ,
V_72 >> 24 ,
( V_72 >> 16 ) & 0xff ) ;
}
void F_37 ( void )
{
struct V_5 V_6 ;
if ( V_80 ) {
F_21 ( & V_6 ) ;
F_35 ( & V_6 , V_81 ) ;
V_80 = 0 ;
}
}
static void F_38 ( struct V_5 * V_6 )
{
struct V_2 * V_82 ;
int * V_83 ;
int * V_84 ;
V_82 = V_6 -> V_24 ;
if ( V_82 == NULL )
return;
V_83 = ( int * ) F_6 ( & V_80 ) ;
V_84 = ( int * ) F_6 ( & V_81 ) ;
* V_83 = 1 ;
* V_84 = V_82 -> V_52 . V_72 ;
}
static inline void F_39 ( void )
{
F_40 () ;
}
static inline void F_38 ( struct V_5 * V_6 )
{
struct V_2 * V_82 ;
V_82 = V_6 -> V_24 ;
if ( V_82 == NULL )
return;
F_35 ( V_6 , V_82 -> V_52 . V_72 ) ;
}
static int F_41 ( struct V_5 * V_6 , bool V_85 )
{
struct V_2 * V_82 ;
unsigned int V_63 [ 2 ] ;
V_82 = V_6 -> V_24 ;
if ( V_82 == NULL )
return 0 ;
F_24 ( V_86 ,
( unsigned long ) V_82 -> V_87 ,
( unsigned long ) V_82 -> V_87 >> 16 >> 16 ) ;
F_24 ( V_70 , 0 , 0 ) ;
F_25 () ;
F_23 ( V_70 , V_63 [ 0 ] , V_63 [ 1 ] ) ;
if ( V_63 [ 1 ] != V_82 -> V_52 . V_11 )
return - 1 ;
#ifdef F_42
F_39 () ;
#endif
V_6 -> V_10 . V_11 = V_63 [ 1 ] ;
if ( V_85 )
F_38 ( V_6 ) ;
else
F_35 ( V_6 , V_82 -> V_52 . V_72 ) ;
return 0 ;
}
int T_2 F_43 ( void )
{
unsigned int V_32 = V_29 . V_4 ;
struct V_2 * V_25 [ V_31 ] ;
int V_48 = 0 ;
if ( V_32 == 0 )
return V_48 ;
F_4 ( V_25 , V_26 , V_27 , V_32 ) ;
V_48 = F_13 ( & V_29 , V_25 , V_32 ) ;
if ( V_48 )
F_31 ( L_8 ) ;
F_26 () ;
return V_48 ;
}
static void T_2
F_44 ( struct V_29 * V_29 ,
unsigned long * V_26 ,
unsigned long V_88 ,
unsigned long V_89 ,
struct V_5 * V_6 )
{
enum V_1 V_48 ;
F_21 ( V_6 ) ;
F_33 ( V_88 , V_89 , V_29 ,
V_26 , V_6 ) ;
V_48 = F_7 ( V_29 , V_26 ,
V_88 , V_6 ) ;
if ( V_48 == V_13 )
F_41 ( V_6 , true ) ;
}
void T_2
F_45 ( void )
{
T_5 V_90 , V_91 ;
unsigned long V_88 , V_89 ;
struct V_5 V_6 ;
#ifdef F_8
struct V_92 * V_93 ;
V_93 = (struct V_92 * ) F_6 ( & V_92 ) ;
V_90 = V_93 -> V_52 . V_90 ;
V_91 = V_93 -> V_52 . V_91 ;
V_88 = V_90 ;
V_89 = V_88 + V_91 ;
F_44 (
(struct V_29 * ) F_6 ( & V_29 ) ,
( unsigned long * ) F_6 ( & V_26 ) ,
V_88 , V_89 , & V_6 ) ;
#else
V_90 = V_92 . V_52 . V_90 ;
V_91 = V_92 . V_52 . V_91 ;
V_88 = V_90 + V_94 ;
V_89 = V_88 + V_91 ;
F_44 ( & V_29 , V_26 ,
V_88 , V_89 ,
& V_6 ) ;
#endif
}
void F_46 ( void )
{
struct V_29 * V_95 ;
struct V_5 V_6 ;
unsigned long * V_96 ;
unsigned long V_97 ;
#ifdef F_8
unsigned long * V_98 ;
V_96 =
( unsigned long * ) F_6 ( V_26 ) ;
V_95 = (struct V_29 * ) F_6 ( & V_29 ) ;
V_98 = ( unsigned long * ) F_6 ( & V_27 ) ;
V_97 = ( unsigned long ) F_6 ( * V_98 ) ;
#else
V_95 = & V_29 ;
V_96 = V_26 ;
V_97 = V_27 ;
#endif
if ( V_95 -> V_4 == 0 )
return;
F_21 ( & V_6 ) ;
F_7 ( V_95 , V_96 ,
V_97 , & V_6 ) ;
F_41 ( & V_6 , true ) ;
}
void F_47 ( void )
{
struct V_5 V_6 ;
enum V_1 V_48 ;
if ( ! V_29 . V_4 )
return;
F_21 ( & V_6 ) ;
V_48 = F_1 ( V_29 . V_25 ,
V_29 . V_4 , & V_6 ) ;
if ( V_48 != V_13 )
return;
F_41 ( & V_6 , false ) ;
}
