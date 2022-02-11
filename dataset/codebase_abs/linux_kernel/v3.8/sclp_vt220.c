static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
void * V_6 ;
do {
V_6 = V_2 -> V_7 . V_8 ;
F_2 ( & V_9 , V_5 ) ;
F_3 ( & V_2 -> V_10 ) ;
F_4 ( (struct V_11 * ) V_6 , & V_12 ) ;
V_2 = NULL ;
if ( ! F_5 ( & V_13 ) )
V_2 = F_6 ( V_13 . V_14 ,
struct V_1 , V_10 ) ;
if ( ! V_2 || V_15 ) {
V_16 = 0 ;
F_7 ( & V_9 , V_5 ) ;
break;
}
F_7 ( & V_9 , V_5 ) ;
} while ( F_8 ( V_2 ) );
if ( V_2 == NULL && V_17 )
F_9 () ;
V_4 = F_10 ( & V_18 ) ;
if ( V_4 ) {
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
}
}
static void
F_13 ( struct V_7 * V_2 , void * V_19 )
{
struct V_1 * V_20 ;
struct V_21 * V_8 ;
V_20 = (struct V_1 * ) V_19 ;
if ( V_2 -> V_22 == V_23 ) {
F_1 ( V_20 ) ;
return;
}
V_8 = (struct V_21 * ) V_20 -> V_7 . V_8 ;
switch ( V_8 -> V_24 . V_25 ) {
case 0x0020 :
break;
case 0x05f0 :
break;
case 0x0340 :
if ( ++ V_20 -> V_26 > V_27 )
break;
if ( F_14 ( (struct V_28 * ) V_8 ) > 0 ) {
V_8 -> V_24 . V_25 = 0x0000 ;
V_20 -> V_7 . V_22 = V_29 ;
if ( F_15 ( V_2 ) == 0 )
return;
}
break;
case 0x0040 :
if ( ++ V_20 -> V_26 > V_27 )
break;
V_8 -> V_24 . V_25 = 0x0000 ;
V_20 -> V_7 . V_22 = V_29 ;
if ( F_15 ( V_2 ) == 0 )
return;
break;
default:
break;
}
F_1 ( V_20 ) ;
}
static int
F_8 ( struct V_1 * V_2 )
{
if ( ! ( V_30 . V_31 & V_32 ) ) {
V_2 -> V_7 . V_22 = V_23 ;
return - V_33 ;
}
V_2 -> V_7 . V_34 = V_35 ;
V_2 -> V_7 . V_22 = V_29 ;
V_2 -> V_7 . V_36 = F_13 ;
V_2 -> V_7 . V_37 = ( void * ) V_2 ;
return F_15 ( & V_2 -> V_7 ) ;
}
static void
F_9 ( void )
{
unsigned long V_5 ;
struct V_1 * V_2 ;
struct V_21 * V_8 ;
F_2 ( & V_9 , V_5 ) ;
if ( V_38 ) {
V_8 = (struct V_21 * )
V_38 -> V_7 . V_8 ;
if ( V_8 -> V_24 . V_39 != sizeof( struct V_21 ) ) {
F_4 ( & V_38 -> V_10 ,
& V_13 ) ;
V_38 = NULL ;
if ( F_16 ( & V_40 ) )
F_17 ( & V_40 ) ;
}
V_17 = 0 ;
}
if ( V_16 || V_15 )
goto V_41;
if ( F_5 ( & V_13 ) )
goto V_41;
V_2 = F_18 ( & V_13 ,
struct V_1 , V_10 ) ;
V_16 = 1 ;
F_7 ( & V_9 , V_5 ) ;
if ( F_8 ( V_2 ) )
F_1 ( V_2 ) ;
return;
V_41:
F_7 ( & V_9 , V_5 ) ;
}
static struct V_1 *
F_19 ( void * V_6 )
{
struct V_1 * V_2 ;
struct V_21 * V_8 ;
V_2 = ( (struct V_1 * )
( ( V_42 ) V_6 + V_43 ) ) - 1 ;
V_2 -> V_26 = 0 ;
V_2 -> V_7 . V_8 = V_6 ;
V_8 = (struct V_21 * ) V_6 ;
memset ( ( void * ) V_8 , 0 , sizeof( struct V_21 ) ) ;
V_8 -> V_24 . V_39 = sizeof( struct V_21 ) ;
V_8 -> V_24 . V_44 = V_45 ;
V_8 -> V_24 . V_25 = 0x0000 ;
V_8 -> V_46 . type = V_47 ;
V_8 -> V_46 . V_39 = sizeof( struct V_48 ) ;
return V_2 ;
}
static inline unsigned int
F_20 ( struct V_1 * V_2 )
{
struct V_21 * V_8 ;
V_8 = (struct V_21 * ) V_2 -> V_7 . V_8 ;
return V_43 - sizeof( struct V_1 ) -
V_8 -> V_24 . V_39 ;
}
static inline unsigned int
F_21 ( struct V_1 * V_2 )
{
struct V_21 * V_8 ;
V_8 = (struct V_21 * ) V_2 -> V_7 . V_8 ;
return V_8 -> V_46 . V_39 - sizeof( struct V_48 ) ;
}
static int
F_22 ( struct V_1 * V_2 ,
const unsigned char * V_49 , int V_50 , int V_51 )
{
struct V_21 * V_8 ;
void * V_52 ;
unsigned char V_53 ;
int V_54 ;
int V_55 ;
if ( V_50 > F_20 ( V_2 ) )
V_50 = F_20 ( V_2 ) ;
if ( V_50 <= 0 )
return 0 ;
V_8 = (struct V_21 * ) V_2 -> V_7 . V_8 ;
V_52 = ( void * ) ( ( V_42 ) V_8 + V_8 -> V_24 . V_39 ) ;
if ( V_51 ) {
for ( V_54 = 0 , V_55 = 0 ;
( V_54 < V_50 ) && ( V_55 < F_20 ( V_2 ) ) ;
V_54 ++ ) {
V_53 = V_49 [ V_54 ] ;
if ( V_53 == 0x0a ) {
if ( V_55 + 1 < F_20 ( V_2 ) ) {
( ( unsigned char * ) V_52 ) [ V_55 ++ ] = V_53 ;
( ( unsigned char * ) V_52 ) [ V_55 ++ ] = 0x0d ;
} else
break;
} else
( ( unsigned char * ) V_52 ) [ V_55 ++ ] = V_53 ;
}
V_8 -> V_24 . V_39 += V_55 ;
V_8 -> V_46 . V_39 += V_55 ;
return V_54 ;
} else {
memcpy ( V_52 , ( const void * ) V_49 , V_50 ) ;
V_8 -> V_24 . V_39 += V_50 ;
V_8 -> V_46 . V_39 += V_50 ;
return V_50 ;
}
}
static void
F_23 ( unsigned long V_19 )
{
F_9 () ;
}
static int
F_24 ( const unsigned char * V_56 , int V_50 , int V_57 ,
int V_51 , int V_58 )
{
unsigned long V_5 ;
void * V_6 ;
int V_59 ;
int V_60 ;
if ( V_50 <= 0 )
return 0 ;
V_60 = 0 ;
F_2 ( & V_9 , V_5 ) ;
do {
if ( V_38 == NULL ) {
while ( F_5 ( & V_12 ) ) {
F_7 ( & V_9 , V_5 ) ;
if ( V_58 || V_15 )
goto V_61;
else
F_25 () ;
F_2 ( & V_9 , V_5 ) ;
}
V_6 = ( void * ) V_12 . V_14 ;
F_3 ( (struct V_11 * ) V_6 ) ;
V_38 =
F_19 ( V_6 ) ;
}
V_59 = F_22 ( V_38 ,
V_56 , V_50 , V_51 ) ;
V_60 += V_59 ;
if ( V_59 == V_50 )
break;
F_7 ( & V_9 , V_5 ) ;
F_9 () ;
F_2 ( & V_9 , V_5 ) ;
V_56 += V_59 ;
V_50 -= V_59 ;
} while ( V_50 > 0 );
if ( V_38 != NULL &&
! F_16 ( & V_40 ) && V_57 ) {
V_40 . V_62 = F_23 ;
V_40 . V_19 = 0UL ;
V_40 . V_63 = V_64 + V_65 ;
F_26 ( & V_40 ) ;
}
F_7 ( & V_9 , V_5 ) ;
V_61:
return V_60 ;
}
static int
F_27 ( struct V_3 * V_4 , const unsigned char * V_56 , int V_50 )
{
return F_24 ( V_56 , V_50 , 1 , 0 , 1 ) ;
}
static void
F_28 ( struct V_48 * V_46 )
{
struct V_3 * V_4 = F_10 ( & V_18 ) ;
char * V_52 ;
unsigned int V_50 ;
if ( V_4 == NULL )
return;
V_52 = ( char * ) ( ( V_42 ) V_46 + sizeof( struct V_48 ) ) ;
V_50 = V_46 -> V_39 - sizeof( struct V_48 ) ;
switch ( * V_52 ) {
case V_66 :
case V_67 :
break;
case V_68 :
V_52 ++ ;
V_50 -- ;
F_29 ( V_4 , V_52 , V_50 ) ;
F_30 ( V_4 ) ;
break;
}
F_12 ( V_4 ) ;
}
static int
F_31 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
if ( V_4 -> V_50 == 1 ) {
F_32 ( & V_18 , V_4 ) ;
V_4 -> V_71 = 0 ;
if ( ! V_4 -> V_72 . V_73 && ! V_4 -> V_72 . V_74 ) {
V_4 -> V_72 . V_73 = 24 ;
V_4 -> V_72 . V_74 = 80 ;
}
}
return 0 ;
}
static void
F_33 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
if ( V_4 -> V_50 == 1 )
F_32 ( & V_18 , NULL ) ;
}
static int
F_34 ( struct V_3 * V_4 , unsigned char V_75 )
{
return F_24 ( & V_75 , 1 , 0 , 0 , 1 ) ;
}
static void
F_35 ( struct V_3 * V_4 )
{
if ( ! V_16 )
F_9 () ;
else
V_17 = 1 ;
}
static int
F_36 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
struct V_11 * V_76 ;
int V_50 ;
F_2 ( & V_9 , V_5 ) ;
V_50 = 0 ;
if ( V_38 != NULL )
V_50 = F_20 ( V_38 ) ;
F_37 (l, &sclp_vt220_empty)
V_50 += V_77 ;
F_7 ( & V_9 , V_5 ) ;
return V_50 ;
}
static int
F_38 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
struct V_11 * V_76 ;
struct V_1 * V_78 ;
int V_50 ;
F_2 ( & V_9 , V_5 ) ;
V_50 = 0 ;
if ( V_38 != NULL )
V_50 = F_21 ( V_38 ) ;
F_37 (l, &sclp_vt220_outqueue) {
V_78 = F_6 ( V_76 , struct V_1 , V_10 ) ;
V_50 += F_21 ( V_78 ) ;
}
F_7 ( & V_9 , V_5 ) ;
return V_50 ;
}
static void
F_39 ( struct V_3 * V_4 )
{
F_9 () ;
}
static void T_1 F_40 ( void )
{
struct V_11 * V_6 , * V_79 ;
F_41 (page, p, &sclp_vt220_empty) {
F_3 ( V_6 ) ;
F_42 ( ( unsigned long ) V_6 ) ;
}
}
static void T_1 F_43 ( void )
{
V_80 -- ;
if ( V_80 != 0 )
return;
F_44 ( & V_30 ) ;
F_40 () ;
F_45 ( & V_18 ) ;
}
static int T_1 F_46 ( int V_81 )
{
void * V_6 ;
int V_82 ;
int V_83 ;
V_80 ++ ;
if ( V_80 != 1 )
return 0 ;
F_47 ( & V_9 ) ;
F_48 ( & V_12 ) ;
F_48 ( & V_13 ) ;
F_49 ( & V_40 ) ;
F_50 ( & V_18 ) ;
V_38 = NULL ;
V_84 = 0 ;
V_17 = 0 ;
V_83 = - V_85 ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
V_6 = ( void * ) F_51 ( V_86 | V_87 ) ;
if ( ! V_6 )
goto V_61;
F_4 ( V_6 , & V_12 ) ;
}
V_83 = F_52 ( & V_30 ) ;
V_61:
if ( V_83 ) {
F_40 () ;
V_80 -- ;
F_45 ( & V_18 ) ;
}
return V_83 ;
}
static int T_1 F_53 ( void )
{
struct V_88 * V_89 ;
int V_83 ;
V_89 = F_54 ( 1 ) ;
if ( ! V_89 )
return - V_85 ;
V_83 = F_46 ( V_90 ) ;
if ( V_83 )
goto V_91;
V_89 -> V_92 = V_93 ;
V_89 -> V_94 = V_95 ;
V_89 -> V_96 = V_97 ;
V_89 -> V_98 = V_99 ;
V_89 -> type = V_100 ;
V_89 -> V_101 = V_102 ;
V_89 -> V_103 = V_104 ;
V_89 -> V_5 = V_105 ;
F_55 ( V_89 , & V_106 ) ;
F_56 ( & V_18 , V_89 , 0 ) ;
V_83 = F_57 ( V_89 ) ;
if ( V_83 )
goto V_107;
V_108 = V_89 ;
return 0 ;
V_107:
F_43 () ;
V_91:
F_58 ( V_89 ) ;
return V_83 ;
}
static void F_59 ( void )
{
unsigned long V_5 ;
F_9 () ;
F_2 ( & V_9 , V_5 ) ;
if ( F_16 ( & V_40 ) )
F_17 ( & V_40 ) ;
while ( V_16 ) {
F_7 ( & V_9 , V_5 ) ;
F_25 () ;
F_2 ( & V_9 , V_5 ) ;
}
F_7 ( & V_9 , V_5 ) ;
}
static void F_60 ( void )
{
unsigned long V_5 ;
F_2 ( & V_9 , V_5 ) ;
V_15 = 0 ;
F_7 ( & V_9 , V_5 ) ;
F_9 () ;
}
static void F_61 ( void )
{
unsigned long V_5 ;
F_2 ( & V_9 , V_5 ) ;
V_15 = 1 ;
F_7 ( & V_9 , V_5 ) ;
F_59 () ;
}
static void F_62 ( struct F_52 * V_109 ,
enum V_110 V_110 )
{
switch ( V_110 ) {
case V_111 :
F_61 () ;
break;
case V_112 :
case V_113 :
F_60 () ;
break;
}
}
static void
F_63 ( struct V_114 * V_115 , const char * V_56 , unsigned int V_50 )
{
F_24 ( ( const unsigned char * ) V_56 , V_50 , 1 , 1 , 0 ) ;
}
static struct V_88 *
F_64 ( struct V_114 * V_53 , int * V_116 )
{
* V_116 = 0 ;
return V_108 ;
}
static int
F_65 ( struct V_117 * V_118 ,
unsigned long V_119 , void * V_19 )
{
F_59 () ;
return V_120 ;
}
static int T_1
F_66 ( void )
{
int V_83 ;
if ( ! V_121 )
return 0 ;
V_83 = F_46 ( V_122 ) ;
if ( V_83 )
return V_83 ;
F_67 ( & V_123 , & V_124 ) ;
F_68 ( & V_125 ) ;
F_69 ( & V_126 ) ;
return 0 ;
}
