static void
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
void * V_4 ;
do {
V_4 = V_2 -> V_5 . V_6 ;
F_2 ( & V_7 , V_3 ) ;
F_3 ( & V_2 -> V_8 ) ;
F_4 ( (struct V_9 * ) V_4 , & V_10 ) ;
V_2 = NULL ;
if ( ! F_5 ( & V_11 ) )
V_2 = F_6 ( V_11 . V_12 ,
struct V_1 , V_8 ) ;
if ( ! V_2 || V_13 ) {
V_14 = 0 ;
F_7 ( & V_7 , V_3 ) ;
break;
}
F_7 ( & V_7 , V_3 ) ;
} while ( F_8 ( V_2 ) );
if ( V_2 == NULL && V_15 )
F_9 () ;
F_10 ( & V_16 ) ;
}
static void
F_11 ( struct V_5 * V_2 , void * V_17 )
{
struct V_1 * V_18 ;
struct V_19 * V_6 ;
V_18 = (struct V_1 * ) V_17 ;
if ( V_2 -> V_20 == V_21 ) {
F_1 ( V_18 ) ;
return;
}
V_6 = (struct V_19 * ) V_18 -> V_5 . V_6 ;
switch ( V_6 -> V_22 . V_23 ) {
case 0x0020 :
break;
case 0x05f0 :
break;
case 0x0340 :
if ( ++ V_18 -> V_24 > V_25 )
break;
if ( F_12 ( (struct V_26 * ) V_6 ) > 0 ) {
V_6 -> V_22 . V_23 = 0x0000 ;
V_18 -> V_5 . V_20 = V_27 ;
if ( F_13 ( V_2 ) == 0 )
return;
}
break;
case 0x0040 :
if ( ++ V_18 -> V_24 > V_25 )
break;
V_6 -> V_22 . V_23 = 0x0000 ;
V_18 -> V_5 . V_20 = V_27 ;
if ( F_13 ( V_2 ) == 0 )
return;
break;
default:
break;
}
F_1 ( V_18 ) ;
}
static int
F_8 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_28 = V_29 ;
V_2 -> V_5 . V_20 = V_27 ;
V_2 -> V_5 . V_30 = F_11 ;
V_2 -> V_5 . V_31 = ( void * ) V_2 ;
return F_13 ( & V_2 -> V_5 ) ;
}
static void
F_9 ( void )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_19 * V_6 ;
F_2 ( & V_7 , V_3 ) ;
if ( V_32 ) {
V_6 = (struct V_19 * )
V_32 -> V_5 . V_6 ;
if ( V_6 -> V_22 . V_33 != sizeof( struct V_19 ) ) {
F_4 ( & V_32 -> V_8 ,
& V_11 ) ;
V_32 = NULL ;
if ( F_14 ( & V_34 ) )
F_15 ( & V_34 ) ;
}
V_15 = 0 ;
}
if ( V_14 || V_13 )
goto V_35;
if ( F_5 ( & V_11 ) )
goto V_35;
V_2 = F_16 ( & V_11 ,
struct V_1 , V_8 ) ;
V_14 = 1 ;
F_7 ( & V_7 , V_3 ) ;
if ( F_8 ( V_2 ) )
F_1 ( V_2 ) ;
return;
V_35:
F_7 ( & V_7 , V_3 ) ;
}
static struct V_1 *
F_17 ( void * V_4 )
{
struct V_1 * V_2 ;
struct V_19 * V_6 ;
V_2 = ( (struct V_1 * )
( ( V_36 ) V_4 + V_37 ) ) - 1 ;
V_2 -> V_24 = 0 ;
V_2 -> V_5 . V_6 = V_4 ;
V_6 = (struct V_19 * ) V_4 ;
memset ( ( void * ) V_6 , 0 , sizeof( struct V_19 ) ) ;
V_6 -> V_22 . V_33 = sizeof( struct V_19 ) ;
V_6 -> V_22 . V_38 = V_39 ;
V_6 -> V_22 . V_23 = 0x0000 ;
V_6 -> V_40 . type = V_41 ;
V_6 -> V_40 . V_33 = sizeof( struct V_42 ) ;
return V_2 ;
}
static inline unsigned int
F_18 ( struct V_1 * V_2 )
{
struct V_19 * V_6 ;
V_6 = (struct V_19 * ) V_2 -> V_5 . V_6 ;
return V_37 - sizeof( struct V_1 ) -
V_6 -> V_22 . V_33 ;
}
static inline unsigned int
F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_6 ;
V_6 = (struct V_19 * ) V_2 -> V_5 . V_6 ;
return V_6 -> V_40 . V_33 - sizeof( struct V_42 ) ;
}
static int
F_20 ( struct V_1 * V_2 ,
const unsigned char * V_43 , int V_44 , int V_45 )
{
struct V_19 * V_6 ;
void * V_46 ;
unsigned char V_47 ;
int V_48 ;
int V_49 ;
if ( V_44 > F_18 ( V_2 ) )
V_44 = F_18 ( V_2 ) ;
if ( V_44 <= 0 )
return 0 ;
V_6 = (struct V_19 * ) V_2 -> V_5 . V_6 ;
V_46 = ( void * ) ( ( V_36 ) V_6 + V_6 -> V_22 . V_33 ) ;
if ( V_45 ) {
for ( V_48 = 0 , V_49 = 0 ;
( V_48 < V_44 ) && ( V_49 < F_18 ( V_2 ) ) ;
V_48 ++ ) {
V_47 = V_43 [ V_48 ] ;
if ( V_47 == 0x0a ) {
if ( V_49 + 1 < F_18 ( V_2 ) ) {
( ( unsigned char * ) V_46 ) [ V_49 ++ ] = V_47 ;
( ( unsigned char * ) V_46 ) [ V_49 ++ ] = 0x0d ;
} else
break;
} else
( ( unsigned char * ) V_46 ) [ V_49 ++ ] = V_47 ;
}
V_6 -> V_22 . V_33 += V_49 ;
V_6 -> V_40 . V_33 += V_49 ;
return V_48 ;
} else {
memcpy ( V_46 , ( const void * ) V_43 , V_44 ) ;
V_6 -> V_22 . V_33 += V_44 ;
V_6 -> V_40 . V_33 += V_44 ;
return V_44 ;
}
}
static void
F_21 ( unsigned long V_17 )
{
F_9 () ;
}
static int
F_22 ( void )
{
struct V_9 * V_8 ;
struct V_1 * V_2 ;
void * V_4 ;
if ( ! V_50 )
return 0 ;
V_8 = V_11 . V_12 ;
if ( V_14 )
V_8 = V_8 -> V_12 ;
if ( V_8 == & V_11 )
return 0 ;
F_3 ( V_8 ) ;
V_2 = F_6 ( V_8 , struct V_1 , V_8 ) ;
V_4 = V_2 -> V_5 . V_6 ;
F_4 ( (struct V_9 * ) V_4 , & V_10 ) ;
return 1 ;
}
static int
F_23 ( const unsigned char * V_51 , int V_44 , int V_52 ,
int V_45 , int V_53 )
{
unsigned long V_3 ;
void * V_4 ;
int V_54 ;
int V_55 ;
if ( V_44 <= 0 )
return 0 ;
V_55 = 0 ;
F_2 ( & V_7 , V_3 ) ;
do {
if ( V_32 == NULL ) {
if ( F_5 ( & V_10 ) )
V_56 ++ ;
while ( F_5 ( & V_10 ) ) {
if ( V_53 || V_13 )
goto V_57;
if ( F_22 () )
break;
F_7 ( & V_7 , V_3 ) ;
F_24 () ;
F_2 ( & V_7 , V_3 ) ;
}
V_4 = ( void * ) V_10 . V_12 ;
F_3 ( (struct V_9 * ) V_4 ) ;
V_32 =
F_17 ( V_4 ) ;
}
V_54 = F_20 ( V_32 ,
V_51 , V_44 , V_45 ) ;
V_55 += V_54 ;
if ( V_54 == V_44 )
break;
F_7 ( & V_7 , V_3 ) ;
F_9 () ;
F_2 ( & V_7 , V_3 ) ;
V_51 += V_54 ;
V_44 -= V_54 ;
} while ( V_44 > 0 );
if ( V_32 != NULL &&
! F_14 ( & V_34 ) && V_52 ) {
V_34 . V_58 = F_21 ;
V_34 . V_17 = 0UL ;
V_34 . V_59 = V_60 + V_61 ;
F_25 ( & V_34 ) ;
}
V_57:
F_7 ( & V_7 , V_3 ) ;
return V_55 ;
}
static int
F_26 ( struct V_62 * V_63 , const unsigned char * V_51 , int V_44 )
{
return F_23 ( V_51 , V_44 , 1 , 0 , 1 ) ;
}
static void
F_27 ( struct V_42 * V_40 )
{
char * V_46 ;
unsigned int V_44 ;
V_46 = ( char * ) ( ( V_36 ) V_40 + sizeof( struct V_42 ) ) ;
V_44 = V_40 -> V_33 - sizeof( struct V_42 ) ;
switch ( * V_46 ) {
case V_64 :
case V_65 :
break;
case V_66 :
V_46 ++ ;
V_44 -- ;
F_28 ( & V_16 , V_46 , V_44 ) ;
F_29 ( & V_16 ) ;
break;
}
}
static int
F_30 ( struct V_62 * V_63 , struct V_67 * V_68 )
{
if ( V_63 -> V_44 == 1 ) {
F_31 ( & V_16 , V_63 ) ;
V_16 . V_69 = 0 ;
if ( ! V_63 -> V_70 . V_71 && ! V_63 -> V_70 . V_72 ) {
V_63 -> V_70 . V_71 = 24 ;
V_63 -> V_70 . V_72 = 80 ;
}
}
return 0 ;
}
static void
F_32 ( struct V_62 * V_63 , struct V_67 * V_68 )
{
if ( V_63 -> V_44 == 1 )
F_31 ( & V_16 , NULL ) ;
}
static int
F_33 ( struct V_62 * V_63 , unsigned char V_73 )
{
return F_23 ( & V_73 , 1 , 0 , 0 , 1 ) ;
}
static void
F_34 ( struct V_62 * V_63 )
{
if ( ! V_14 )
F_9 () ;
else
V_15 = 1 ;
}
static int
F_35 ( struct V_62 * V_63 )
{
unsigned long V_3 ;
struct V_9 * V_74 ;
int V_44 ;
F_2 ( & V_7 , V_3 ) ;
V_44 = 0 ;
if ( V_32 != NULL )
V_44 = F_18 ( V_32 ) ;
F_36 (l, &sclp_vt220_empty)
V_44 += V_75 ;
F_7 ( & V_7 , V_3 ) ;
return V_44 ;
}
static int
F_37 ( struct V_62 * V_63 )
{
unsigned long V_3 ;
struct V_9 * V_74 ;
struct V_1 * V_76 ;
int V_44 ;
F_2 ( & V_7 , V_3 ) ;
V_44 = 0 ;
if ( V_32 != NULL )
V_44 = F_19 ( V_32 ) ;
F_36 (l, &sclp_vt220_outqueue) {
V_76 = F_6 ( V_74 , struct V_1 , V_8 ) ;
V_44 += F_19 ( V_76 ) ;
}
F_7 ( & V_7 , V_3 ) ;
return V_44 ;
}
static void
F_38 ( struct V_62 * V_63 )
{
F_9 () ;
}
static void T_1 F_39 ( void )
{
struct V_9 * V_4 , * V_77 ;
F_40 (page, p, &sclp_vt220_empty) {
F_3 ( V_4 ) ;
F_41 ( ( unsigned long ) V_4 ) ;
}
}
static void T_1 F_42 ( void )
{
V_78 -- ;
if ( V_78 != 0 )
return;
F_43 ( & V_79 ) ;
F_39 () ;
F_44 ( & V_16 ) ;
}
static int T_1 F_45 ( int V_80 )
{
void * V_4 ;
int V_81 ;
int V_82 ;
V_78 ++ ;
if ( V_78 != 1 )
return 0 ;
F_46 ( & V_7 ) ;
F_47 ( & V_10 ) ;
F_47 ( & V_11 ) ;
F_48 ( & V_34 ) ;
F_49 ( & V_16 ) ;
V_32 = NULL ;
V_83 = 0 ;
V_15 = 0 ;
V_82 = - V_84 ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
V_4 = ( void * ) F_50 ( V_85 | V_86 ) ;
if ( ! V_4 )
goto V_57;
F_4 ( V_4 , & V_10 ) ;
}
V_82 = F_51 ( & V_79 ) ;
V_57:
if ( V_82 ) {
F_39 () ;
V_78 -- ;
F_44 ( & V_16 ) ;
}
return V_82 ;
}
static int T_1 F_52 ( void )
{
struct V_87 * V_88 ;
int V_82 ;
V_88 = F_53 ( 1 ) ;
if ( ! V_88 )
return - V_84 ;
V_82 = F_45 ( V_89 ) ;
if ( V_82 )
goto V_90;
V_88 -> V_91 = V_92 ;
V_88 -> V_93 = V_94 ;
V_88 -> V_95 = V_96 ;
V_88 -> V_97 = V_98 ;
V_88 -> type = V_99 ;
V_88 -> V_100 = V_101 ;
V_88 -> V_102 = V_103 ;
V_88 -> V_3 = V_104 ;
F_54 ( V_88 , & V_105 ) ;
F_55 ( & V_16 , V_88 , 0 ) ;
V_82 = F_56 ( V_88 ) ;
if ( V_82 )
goto V_106;
V_82 = F_51 ( & V_107 ) ;
if ( V_82 )
goto V_108;
V_109 = V_88 ;
return 0 ;
V_108:
F_57 ( V_88 ) ;
V_106:
F_42 () ;
V_90:
F_58 ( V_88 ) ;
return V_82 ;
}
static void F_59 ( void )
{
unsigned long V_3 ;
F_9 () ;
F_2 ( & V_7 , V_3 ) ;
if ( F_14 ( & V_34 ) )
F_15 ( & V_34 ) ;
while ( V_14 ) {
F_7 ( & V_7 , V_3 ) ;
F_24 () ;
F_2 ( & V_7 , V_3 ) ;
}
F_7 ( & V_7 , V_3 ) ;
}
static void F_60 ( void )
{
unsigned long V_3 ;
F_2 ( & V_7 , V_3 ) ;
V_13 = 0 ;
F_7 ( & V_7 , V_3 ) ;
F_9 () ;
}
static void F_61 ( void )
{
unsigned long V_3 ;
F_2 ( & V_7 , V_3 ) ;
V_13 = 1 ;
F_7 ( & V_7 , V_3 ) ;
F_59 () ;
}
static void F_62 ( struct F_51 * V_110 ,
enum V_111 V_111 )
{
switch ( V_111 ) {
case V_112 :
F_61 () ;
break;
case V_113 :
case V_114 :
F_60 () ;
break;
}
}
static void
F_63 ( struct V_115 * V_116 , const char * V_51 , unsigned int V_44 )
{
F_23 ( ( const unsigned char * ) V_51 , V_44 , 1 , 1 , 0 ) ;
}
static struct V_87 *
F_64 ( struct V_115 * V_47 , int * V_117 )
{
* V_117 = 0 ;
return V_109 ;
}
static int
F_65 ( struct V_118 * V_119 ,
unsigned long V_120 , void * V_17 )
{
F_59 () ;
return V_121 ;
}
static int T_1
F_66 ( void )
{
int V_82 ;
V_82 = F_45 ( V_122 ) ;
if ( V_82 )
return V_82 ;
F_67 ( & V_123 , & V_124 ) ;
F_68 ( & V_125 ) ;
F_69 ( & V_126 ) ;
return 0 ;
}
