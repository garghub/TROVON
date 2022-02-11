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
static void F_27 ( void )
{
V_64 = 0 ;
}
static void F_28 ( const char * V_46 , unsigned int V_44 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_44 ; V_65 ++ ) {
if ( V_46 [ V_65 ] == ( 'O' ^ 0100 ) ) {
V_64 = ! V_64 ;
if ( V_64 )
continue;
} else if ( V_64 ) {
V_66 . V_67 = V_46 [ V_65 ] ;
F_29 ( & V_66 ) ;
V_64 = 0 ;
continue;
}
F_30 ( & V_16 , V_46 [ V_65 ] , 0 ) ;
}
}
static void F_27 ( void )
{
}
static void F_28 ( const char * V_46 , unsigned int V_44 )
{
F_31 ( & V_16 , V_46 , V_44 ) ;
}
static void
F_32 ( struct V_42 * V_40 )
{
char * V_46 ;
unsigned int V_44 ;
V_46 = ( char * ) ( ( V_36 ) V_40 + sizeof( struct V_42 ) ) ;
V_44 = V_40 -> V_33 - sizeof( struct V_42 ) ;
switch ( * V_46 ) {
case V_68 :
case V_69 :
F_27 () ;
break;
case V_70 :
V_46 ++ ;
V_44 -- ;
F_28 ( V_46 , V_44 ) ;
F_33 ( & V_16 ) ;
break;
}
}
static int
F_34 ( struct V_62 * V_63 , struct V_71 * V_72 )
{
if ( V_63 -> V_44 == 1 ) {
F_35 ( & V_16 , V_63 ) ;
V_16 . V_73 = 0 ;
if ( ! V_63 -> V_74 . V_75 && ! V_63 -> V_74 . V_76 ) {
V_63 -> V_74 . V_75 = 24 ;
V_63 -> V_74 . V_76 = 80 ;
}
}
return 0 ;
}
static void
F_36 ( struct V_62 * V_63 , struct V_71 * V_72 )
{
if ( V_63 -> V_44 == 1 )
F_35 ( & V_16 , NULL ) ;
}
static int
F_37 ( struct V_62 * V_63 , unsigned char V_77 )
{
return F_23 ( & V_77 , 1 , 0 , 0 , 1 ) ;
}
static void
F_38 ( struct V_62 * V_63 )
{
if ( ! V_14 )
F_9 () ;
else
V_15 = 1 ;
}
static int
F_39 ( struct V_62 * V_63 )
{
unsigned long V_3 ;
struct V_9 * V_78 ;
int V_44 ;
F_2 ( & V_7 , V_3 ) ;
V_44 = 0 ;
if ( V_32 != NULL )
V_44 = F_18 ( V_32 ) ;
F_40 (l, &sclp_vt220_empty)
V_44 += V_79 ;
F_7 ( & V_7 , V_3 ) ;
return V_44 ;
}
static int
F_41 ( struct V_62 * V_63 )
{
unsigned long V_3 ;
struct V_9 * V_78 ;
struct V_1 * V_80 ;
int V_44 ;
F_2 ( & V_7 , V_3 ) ;
V_44 = 0 ;
if ( V_32 != NULL )
V_44 = F_19 ( V_32 ) ;
F_40 (l, &sclp_vt220_outqueue) {
V_80 = F_6 ( V_78 , struct V_1 , V_8 ) ;
V_44 += F_19 ( V_80 ) ;
}
F_7 ( & V_7 , V_3 ) ;
return V_44 ;
}
static void
F_42 ( struct V_62 * V_63 )
{
F_9 () ;
}
static void T_1 F_43 ( void )
{
struct V_9 * V_4 , * V_81 ;
F_44 (page, p, &sclp_vt220_empty) {
F_3 ( V_4 ) ;
F_45 ( ( unsigned long ) V_4 ) ;
}
}
static void T_1 F_46 ( void )
{
V_82 -- ;
if ( V_82 != 0 )
return;
F_47 ( & V_83 ) ;
F_43 () ;
F_48 ( & V_16 ) ;
}
static int T_1 F_49 ( int V_84 )
{
void * V_4 ;
int V_65 ;
int V_85 ;
V_82 ++ ;
if ( V_82 != 1 )
return 0 ;
F_50 ( & V_7 ) ;
F_51 ( & V_10 ) ;
F_51 ( & V_11 ) ;
F_52 ( & V_34 ) ;
F_53 ( & V_16 ) ;
V_32 = NULL ;
V_86 = 0 ;
V_15 = 0 ;
V_85 = - V_87 ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
V_4 = ( void * ) F_54 ( V_88 | V_89 ) ;
if ( ! V_4 )
goto V_57;
F_4 ( V_4 , & V_10 ) ;
}
V_85 = F_55 ( & V_83 ) ;
V_57:
if ( V_85 ) {
F_43 () ;
V_82 -- ;
F_48 ( & V_16 ) ;
}
return V_85 ;
}
static int T_1 F_56 ( void )
{
struct V_90 * V_91 ;
int V_85 ;
V_91 = F_57 ( 1 ) ;
if ( ! V_91 )
return - V_87 ;
V_85 = F_49 ( V_92 ) ;
if ( V_85 )
goto V_93;
V_91 -> V_94 = V_95 ;
V_91 -> V_96 = V_97 ;
V_91 -> V_98 = V_99 ;
V_91 -> V_100 = V_101 ;
V_91 -> type = V_102 ;
V_91 -> V_103 = V_104 ;
V_91 -> V_105 = V_106 ;
V_91 -> V_3 = V_107 ;
F_58 ( V_91 , & V_108 ) ;
F_59 ( & V_16 , V_91 , 0 ) ;
V_85 = F_60 ( V_91 ) ;
if ( V_85 )
goto V_109;
V_85 = F_55 ( & V_110 ) ;
if ( V_85 )
goto V_111;
V_112 = V_91 ;
return 0 ;
V_111:
F_61 ( V_91 ) ;
V_109:
F_46 () ;
V_93:
F_62 ( V_91 ) ;
return V_85 ;
}
static void F_63 ( void )
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
static void F_64 ( void )
{
unsigned long V_3 ;
F_2 ( & V_7 , V_3 ) ;
V_13 = 0 ;
F_7 ( & V_7 , V_3 ) ;
F_9 () ;
}
static void F_65 ( void )
{
unsigned long V_3 ;
F_2 ( & V_7 , V_3 ) ;
V_13 = 1 ;
F_7 ( & V_7 , V_3 ) ;
F_63 () ;
}
static void F_66 ( struct F_55 * V_113 ,
enum V_114 V_114 )
{
switch ( V_114 ) {
case V_115 :
F_65 () ;
break;
case V_116 :
case V_117 :
F_64 () ;
break;
}
}
static void
F_67 ( struct V_118 * V_119 , const char * V_51 , unsigned int V_44 )
{
F_23 ( ( const unsigned char * ) V_51 , V_44 , 1 , 1 , 0 ) ;
}
static struct V_90 *
F_68 ( struct V_118 * V_47 , int * V_120 )
{
* V_120 = 0 ;
return V_112 ;
}
static int
F_69 ( struct V_121 * V_122 ,
unsigned long V_123 , void * V_17 )
{
F_63 () ;
return V_124 ;
}
static int T_1
F_70 ( void )
{
int V_85 ;
V_85 = F_49 ( V_125 ) ;
if ( V_85 )
return V_85 ;
F_71 ( & V_126 , & V_127 ) ;
F_72 ( & V_128 ) ;
F_73 ( & V_129 ) ;
return 0 ;
}
