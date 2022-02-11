static int T_1 F_1 ( int V_1 , unsigned long V_2 )
{
unsigned long V_3 = 0 , V_4 = 0 ;
if ( V_5 == NULL )
return - 1 ;
V_3 = ( ( unsigned long ) F_2 ( V_2 ) / 0x1000 ) << 16 ;
V_4 = ( 0x1000000 | V_3 | V_1 ) ;
while ( * V_5 & 0x1000000 )
;
* V_5 = V_4 ;
return 0 ;
}
static int F_3 ( void )
{
if ( V_6 . V_7 == 6 &&
( V_6 . V_8 >= 7 && V_6 . V_8 <= 11 ) )
return 1 ;
return 0 ;
}
static void F_4 ( void )
{
if ( ! ( V_6 . V_7 <= 15 && V_6 . V_8 <= 2 ) )
V_9 = V_10 ;
else
V_9 = V_11 ;
}
static int F_5 ( char * V_12 )
{
int V_13 ;
int V_14 = 0 ;
unsigned char type , V_15 ;
unsigned long V_16 ;
char * V_17 = NULL ;
struct V_5 * V_18 = NULL ;
struct V_19 * V_20 ;
struct V_21 * V_22 , * V_23 ;
V_17 = V_12 ;
V_17 += 8 ;
for ( V_13 = 0 ; V_13 <= 6 ; V_13 ++ ) {
type = * V_17 ++ ;
V_15 = * V_17 ++ ;
V_17 -= 2 ;
switch ( type ) {
case V_24 :
V_20 = (struct V_19 * ) V_17 ;
V_16 = F_6 ( V_20 -> V_25 ) ;
V_26 = V_16 ;
V_22 = (struct V_21 * ) V_16 ;
V_25 = F_7 ( V_22 ) ;
V_16 = F_6 ( V_20 -> V_21 ) ;
V_27 = F_8 ( V_20 -> V_28 ) ;
V_29 = V_16 ;
V_23 = (struct V_21 * ) V_16 ;
V_21 = F_7 ( V_23 ) ;
F_9 ( L_1 ,
( unsigned long ) V_25 ) ;
F_9 ( L_2 ,
( unsigned long ) V_21 ) ;
V_14 ++ ;
break;
case V_30 :
V_18 = (struct V_5 * ) V_17 ;
if ( V_17 != NULL ) {
if ( V_18 -> V_31 )
V_5 = F_7 ( V_18 -> V_31 ) ;
else
V_5 = NULL ;
V_14 ++ ;
}
break;
default:
break;
}
V_17 += V_15 ;
}
if ( V_14 < 2 )
V_9 = V_32 ;
else
F_4 () ;
return V_9 ;
}
static int T_2 F_10 ( unsigned long * V_33 )
{
struct V_34 * V_35 = NULL ;
struct V_36 * V_37 ;
T_3 V_38 ;
T_4 V_39 ;
int V_13 = 0 ;
for (; ; ) {
V_39 = F_11 ( L_3 , V_13 ++ , & V_35 , & V_38 ) ;
if ( ! F_12 ( V_39 ) )
return - 1 ;
if ( ! memcmp ( ( char * ) & V_35 -> V_40 , L_4 , 6 ) )
break;
F_13 ( V_35 , V_38 ) ;
}
V_37 = ( void * ) V_35 ;
V_41 = V_37 -> V_42 ;
V_43 = V_37 -> V_44 ;
F_13 ( V_35 , V_38 ) ;
* V_33 = ( unsigned long ) F_14 ( V_41 , V_43 ) ;
return 0 ;
}
static void T_2 F_15 ( unsigned long V_33 )
{
if ( ! V_33 )
return;
F_16 ( ( char * ) V_33 , V_43 ) ;
}
static int F_17 ( void )
{
struct V_34 V_35 ;
if ( F_12 ( F_18 ( V_45 , 0 , & V_35 ) ) &&
! strncmp ( V_35 . V_40 , L_4 , 6 ) )
return 1 ;
return 0 ;
}
static int T_2 F_19 ( char * V_40 , char * V_46 )
{
unsigned long V_33 = 0 ;
int V_47 ;
int V_39 = 0 ;
V_47 = F_17 () ;
if ( ! F_10 ( & V_33 ) ) {
if ( V_47 ) {
V_39 = F_5 ( ( char * ) V_33 ) ;
} else {
F_4 () ;
V_39 = 1 ;
}
F_15 ( V_33 ) ;
}
V_48 = V_39 ;
return V_39 && ! F_3 () ;
}
static int F_20 ( char * V_40 , char * V_46 )
{
int V_39 = V_48 ;
return V_39 && F_3 () ;
}
static int F_19 ( char * V_40 , char * V_46 )
{
return 0 ;
}
static int F_20 ( char * V_40 , char * V_46 )
{
return 0 ;
}
static void F_21 ( int V_49 )
{
int V_13 = 0 ;
while ( V_13 ++ < V_49 )
F_22 () ;
}
static int F_23 ( struct V_21 * V_21 )
{
int V_50 = 0 ;
int V_51 ;
V_51 = V_52 ;
while ( ( V_25 -> V_53 & V_54 ) != 0 ) {
if ( -- V_51 <= 0 ) {
F_24 ( 1 , L_5 ) ;
return - 1 ;
}
F_21 ( V_52 ) ;
}
memcpy ( V_25 , V_21 , sizeof( struct V_21 ) ) ;
F_25 ( 1 , V_27 ) ;
V_51 = V_52 ;
while ( ( V_21 -> V_53 & V_54 ) == 0 ) {
if ( -- V_51 <= 0 ) {
F_24 ( 1 , L_6 ) ;
return - 1 ;
}
F_21 ( V_52 ) ;
}
V_50 = ( V_21 -> V_55 & 0xffff0000000000ULL ) >> 48 ;
V_21 -> V_53 &= ~ V_54 ;
return V_50 ;
}
static void F_26 ( void )
{
struct V_21 V_56 ;
int V_57 ;
if ( ! V_9 )
return;
F_27 ( L_7 ) ;
memset ( & V_56 , 0 , sizeof( struct V_21 ) ) ;
V_56 . V_55 = V_58 ;
V_56 . V_53 = V_54 ;
while ( ( V_57 = F_23 ( & V_56 ) ) != 0 )
F_24 ( 1 , L_8 , V_57 ) ;
}
static void F_28 ( T_5 * V_59 )
{
while ( ! F_29 ( V_59 ) )
F_30 () ;
}
static unsigned int F_31 ( unsigned long V_60 )
{
return ( V_60 >> 24 ) & 0xFF ;
}
static void F_32 ( const struct V_61 * V_62 , int V_63 )
{
F_33 ( V_62 , V_63 ) ;
}
static void F_34 ( int V_63 )
{
F_35 ( V_64 , V_63 ) ;
}
static void F_36 ( int V_63 )
{
F_32 ( V_64 , V_63 ) ;
}
static int F_37 ( void )
{
return 1 ;
}
static const struct V_61 * F_38 ( void )
{
return V_65 ;
}
static const struct V_61 * F_39 ( void )
{
return F_40 ( F_41 () ) ;
}
static unsigned long F_42 ( T_6 * V_66 , int V_67 )
{
return 0 ;
}
static unsigned long F_43 ( int V_68 )
{
return F_44 ( V_68 , V_69 ) ;
}
static int F_45 ( int V_1 )
{
return F_46 ( V_70 , V_1 ) ;
}
static unsigned long F_47 ( int V_1 )
{
unsigned long V_71 = F_48 ( V_70 , V_1 ) ;
return F_49 ( V_71 ) ;
}
static void F_50 ( void )
{
unsigned long V_16 ;
int V_1 = F_41 () ;
F_51 ( V_72 , V_73 ) ;
V_16 = F_47 ( V_1 ) ;
F_51 ( V_74 , V_16 ) ;
}
static void F_52 ( void )
{
unsigned long V_16 ;
int V_1 = F_41 () ;
F_51 ( V_72 , V_75 ) ;
V_16 = F_47 ( V_1 ) ;
F_51 ( V_74 , V_16 ) ;
}
static void F_53 ( void )
{
int V_76 = F_48 ( V_70 , F_41 () ) ;
F_27 ( L_9 ,
( V_77 [ V_76 ] == 0x14 ) ?
L_10 : L_11 ,
V_78 , F_54 ( F_39 () ) [ 0 ] ) ;
}
static int F_55 ( int V_79 )
{
if ( ! V_79 )
return V_80 ;
else if ( V_79 < V_81 )
return F_48 ( V_70 , V_79 ) ;
else
return V_82 ;
}
static void F_56 ( int V_83 , T_6 * V_84 )
{
F_57 ( V_85 , V_84 ) ;
++ V_85 ;
}
static void F_58 ( T_6 * V_86 , T_6 * V_84 )
{
F_59 ( 0xFFL , V_84 ) ;
}
static int F_60 ( int V_87 )
{
V_80 = F_61 () ;
return 1 ;
}
static inline int
F_62 ( const struct V_61 * V_61 , unsigned int * V_88 )
{
unsigned int V_89 = 0 ;
unsigned int V_1 , V_90 ( V_67 ) ;
F_63 (cpu, cpumask, cpu_online_mask) {
int V_91 = F_46 ( V_92 , V_1 ) ;
if ( V_89 && F_64 ( V_67 ) != F_64 ( V_91 ) ) {
F_24 ( 1 , L_12 ) ;
return - V_93 ;
}
V_67 |= V_91 ;
V_89 ++ ;
}
if ( ! V_89 )
return - V_93 ;
* V_88 = V_67 ;
return 0 ;
}
static int
F_65 ( const struct V_61 * V_94 ,
const struct V_61 * V_95 ,
unsigned int * V_67 )
{
T_7 V_61 ;
* V_67 = F_46 ( V_92 , 0 ) ;
if ( ! F_66 ( & V_61 , V_96 ) )
return 0 ;
F_67 ( V_61 , V_94 , V_95 ) ;
F_62 ( V_61 , V_67 ) ;
F_68 ( V_61 ) ;
return 0 ;
}
static int F_69 ( int V_97 , int V_98 )
{
return V_97 >> V_98 ;
}
static int F_70 ( void )
{
return 0 ;
}
static int F_71 ( struct V_99 * V_100 , char * V_101 ,
char * V_102 )
{
int V_39 = 0 ;
if ( V_100 -> V_12 ) {
struct V_103 * V_104 =
(struct V_103 * ) V_100 -> V_12 ;
if ( ! strncmp ( V_101 , L_4 , 6 ) )
V_39 = F_5 ( ( char * ) V_104 ) ;
}
V_105 = V_39 ;
return V_39 && ! F_3 () ;
}
static int F_72 ( struct V_99 * V_100 , char * V_101 ,
char * V_102 )
{
int V_39 = V_105 ;
return V_39 && F_3 () ;
}
