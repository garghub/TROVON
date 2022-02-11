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
if ( V_16 != NULL ) {
F_10 ( V_16 ) ;
}
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
if ( ! ( V_28 . V_29 & V_30 ) ) {
V_2 -> V_5 . V_20 = V_21 ;
return - V_31 ;
}
V_2 -> V_5 . V_32 = V_33 ;
V_2 -> V_5 . V_20 = V_27 ;
V_2 -> V_5 . V_34 = F_11 ;
V_2 -> V_5 . V_35 = ( void * ) V_2 ;
return F_13 ( & V_2 -> V_5 ) ;
}
static void
F_9 ( void )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_19 * V_6 ;
F_2 ( & V_7 , V_3 ) ;
if ( V_36 ) {
V_6 = (struct V_19 * )
V_36 -> V_5 . V_6 ;
if ( V_6 -> V_22 . V_37 != sizeof( struct V_19 ) ) {
F_4 ( & V_36 -> V_8 ,
& V_11 ) ;
V_36 = NULL ;
if ( F_14 ( & V_38 ) )
F_15 ( & V_38 ) ;
}
V_15 = 0 ;
}
if ( V_14 || V_13 )
goto V_39;
if ( F_5 ( & V_11 ) )
goto V_39;
V_2 = F_16 ( & V_11 ,
struct V_1 , V_8 ) ;
V_14 = 1 ;
F_7 ( & V_7 , V_3 ) ;
if ( F_8 ( V_2 ) )
F_1 ( V_2 ) ;
return;
V_39:
F_7 ( & V_7 , V_3 ) ;
}
static struct V_1 *
F_17 ( void * V_4 )
{
struct V_1 * V_2 ;
struct V_19 * V_6 ;
V_2 = ( (struct V_1 * )
( ( V_40 ) V_4 + V_41 ) ) - 1 ;
V_2 -> V_24 = 0 ;
V_2 -> V_5 . V_6 = V_4 ;
V_6 = (struct V_19 * ) V_4 ;
memset ( ( void * ) V_6 , 0 , sizeof( struct V_19 ) ) ;
V_6 -> V_22 . V_37 = sizeof( struct V_19 ) ;
V_6 -> V_22 . V_42 = V_43 ;
V_6 -> V_22 . V_23 = 0x0000 ;
V_6 -> V_44 . type = V_45 ;
V_6 -> V_44 . V_37 = sizeof( struct V_46 ) ;
return V_2 ;
}
static inline unsigned int
F_18 ( struct V_1 * V_2 )
{
struct V_19 * V_6 ;
V_6 = (struct V_19 * ) V_2 -> V_5 . V_6 ;
return V_41 - sizeof( struct V_1 ) -
V_6 -> V_22 . V_37 ;
}
static inline unsigned int
F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_6 ;
V_6 = (struct V_19 * ) V_2 -> V_5 . V_6 ;
return V_6 -> V_44 . V_37 - sizeof( struct V_46 ) ;
}
static int
F_20 ( struct V_1 * V_2 ,
const unsigned char * V_47 , int V_48 , int V_49 )
{
struct V_19 * V_6 ;
void * V_50 ;
unsigned char V_51 ;
int V_52 ;
int V_53 ;
if ( V_48 > F_18 ( V_2 ) )
V_48 = F_18 ( V_2 ) ;
if ( V_48 <= 0 )
return 0 ;
V_6 = (struct V_19 * ) V_2 -> V_5 . V_6 ;
V_50 = ( void * ) ( ( V_40 ) V_6 + V_6 -> V_22 . V_37 ) ;
if ( V_49 ) {
for ( V_52 = 0 , V_53 = 0 ;
( V_52 < V_48 ) && ( V_53 < F_18 ( V_2 ) ) ;
V_52 ++ ) {
V_51 = V_47 [ V_52 ] ;
if ( V_51 == 0x0a ) {
if ( V_53 + 1 < F_18 ( V_2 ) ) {
( ( unsigned char * ) V_50 ) [ V_53 ++ ] = V_51 ;
( ( unsigned char * ) V_50 ) [ V_53 ++ ] = 0x0d ;
} else
break;
} else
( ( unsigned char * ) V_50 ) [ V_53 ++ ] = V_51 ;
}
V_6 -> V_22 . V_37 += V_53 ;
V_6 -> V_44 . V_37 += V_53 ;
return V_52 ;
} else {
memcpy ( V_50 , ( const void * ) V_47 , V_48 ) ;
V_6 -> V_22 . V_37 += V_48 ;
V_6 -> V_44 . V_37 += V_48 ;
return V_48 ;
}
}
static void
F_21 ( unsigned long V_17 )
{
F_9 () ;
}
static int
F_22 ( const unsigned char * V_54 , int V_48 , int V_55 ,
int V_49 , int V_56 )
{
unsigned long V_3 ;
void * V_4 ;
int V_57 ;
int V_58 ;
if ( V_48 <= 0 )
return 0 ;
V_58 = 0 ;
F_2 ( & V_7 , V_3 ) ;
do {
if ( V_36 == NULL ) {
while ( F_5 ( & V_10 ) ) {
F_7 ( & V_7 , V_3 ) ;
if ( V_56 || V_13 )
goto V_59;
else
F_23 () ;
F_2 ( & V_7 , V_3 ) ;
}
V_4 = ( void * ) V_10 . V_12 ;
F_3 ( (struct V_9 * ) V_4 ) ;
V_36 =
F_17 ( V_4 ) ;
}
V_57 = F_20 ( V_36 ,
V_54 , V_48 , V_49 ) ;
V_58 += V_57 ;
if ( V_57 == V_48 )
break;
F_7 ( & V_7 , V_3 ) ;
F_9 () ;
F_2 ( & V_7 , V_3 ) ;
V_54 += V_57 ;
V_48 -= V_57 ;
} while ( V_48 > 0 );
if ( V_36 != NULL &&
! F_14 ( & V_38 ) && V_55 ) {
V_38 . V_60 = F_21 ;
V_38 . V_17 = 0UL ;
V_38 . V_61 = V_62 + V_63 ;
F_24 ( & V_38 ) ;
}
F_7 ( & V_7 , V_3 ) ;
V_59:
return V_58 ;
}
static int
F_25 ( struct V_64 * V_65 , const unsigned char * V_54 , int V_48 )
{
return F_22 ( V_54 , V_48 , 1 , 0 , 1 ) ;
}
static void
F_26 ( struct V_46 * V_44 )
{
char * V_50 ;
unsigned int V_48 ;
if ( V_16 == NULL )
return;
V_50 = ( char * ) ( ( V_40 ) V_44 + sizeof( struct V_46 ) ) ;
V_48 = V_44 -> V_37 - sizeof( struct V_46 ) ;
switch ( * V_50 ) {
case V_66 :
case V_67 :
break;
case V_68 :
V_50 ++ ;
V_48 -- ;
F_27 ( V_16 , V_50 , V_48 ) ;
F_28 ( V_16 ) ;
break;
}
}
static int
F_29 ( struct V_64 * V_65 , struct V_69 * V_70 )
{
if ( V_65 -> V_48 == 1 ) {
V_16 = V_65 ;
V_65 -> V_71 = F_30 ( V_72 , V_73 ) ;
if ( V_65 -> V_71 == NULL )
return - V_74 ;
V_65 -> V_75 = 0 ;
if ( ! V_65 -> V_76 . V_77 && ! V_65 -> V_76 . V_78 ) {
V_65 -> V_76 . V_77 = 24 ;
V_65 -> V_76 . V_78 = 80 ;
}
}
return 0 ;
}
static void
F_31 ( struct V_64 * V_65 , struct V_69 * V_70 )
{
if ( V_65 -> V_48 == 1 ) {
V_16 = NULL ;
F_32 ( V_65 -> V_71 ) ;
V_65 -> V_71 = NULL ;
}
}
static int
F_33 ( struct V_64 * V_65 , unsigned char V_79 )
{
return F_22 ( & V_79 , 1 , 0 , 0 , 1 ) ;
}
static void
F_34 ( struct V_64 * V_65 )
{
if ( ! V_14 )
F_9 () ;
else
V_15 = 1 ;
}
static int
F_35 ( struct V_64 * V_65 )
{
unsigned long V_3 ;
struct V_9 * V_80 ;
int V_48 ;
F_2 ( & V_7 , V_3 ) ;
V_48 = 0 ;
if ( V_36 != NULL )
V_48 = F_18 ( V_36 ) ;
F_36 (l, &sclp_vt220_empty)
V_48 += V_81 ;
F_7 ( & V_7 , V_3 ) ;
return V_48 ;
}
static int
F_37 ( struct V_64 * V_65 )
{
unsigned long V_3 ;
struct V_9 * V_80 ;
struct V_1 * V_82 ;
int V_48 ;
F_2 ( & V_7 , V_3 ) ;
V_48 = 0 ;
if ( V_36 != NULL )
V_48 = F_19 ( V_36 ) ;
F_36 (l, &sclp_vt220_outqueue) {
V_82 = F_6 ( V_80 , struct V_1 , V_8 ) ;
V_48 += F_19 ( V_82 ) ;
}
F_7 ( & V_7 , V_3 ) ;
return V_48 ;
}
static void
F_38 ( struct V_64 * V_65 )
{
F_9 () ;
}
static void T_1 F_39 ( void )
{
struct V_9 * V_4 , * V_83 ;
F_40 (page, p, &sclp_vt220_empty) {
F_3 ( V_4 ) ;
F_41 ( ( unsigned long ) V_4 ) ;
}
}
static void T_1 F_42 ( void )
{
V_84 -- ;
if ( V_84 != 0 )
return;
F_43 ( & V_28 ) ;
F_39 () ;
}
static int T_1 F_44 ( int V_85 )
{
void * V_4 ;
int V_86 ;
int V_87 ;
V_84 ++ ;
if ( V_84 != 1 )
return 0 ;
F_45 ( & V_7 ) ;
F_46 ( & V_10 ) ;
F_46 ( & V_11 ) ;
F_47 ( & V_38 ) ;
V_36 = NULL ;
V_88 = 0 ;
V_16 = NULL ;
V_15 = 0 ;
V_87 = - V_74 ;
for ( V_86 = 0 ; V_86 < V_85 ; V_86 ++ ) {
V_4 = ( void * ) F_48 ( V_73 | V_89 ) ;
if ( ! V_4 )
goto V_59;
F_4 ( V_4 , & V_10 ) ;
}
V_87 = F_49 ( & V_28 ) ;
V_59:
if ( V_87 ) {
F_39 () ;
V_84 -- ;
}
return V_87 ;
}
static int T_1 F_50 ( void )
{
struct V_90 * V_91 ;
int V_87 ;
V_91 = F_51 ( 1 ) ;
if ( ! V_91 )
return - V_74 ;
V_87 = F_44 ( V_92 ) ;
if ( V_87 )
goto V_93;
V_91 -> V_94 = V_95 ;
V_91 -> V_96 = V_97 ;
V_91 -> V_98 = V_99 ;
V_91 -> V_100 = V_101 ;
V_91 -> V_102 = V_103 ;
V_91 -> type = V_104 ;
V_91 -> V_105 = V_106 ;
V_91 -> V_107 = V_108 ;
V_91 -> V_3 = V_109 ;
F_52 ( V_91 , & V_110 ) ;
V_87 = F_53 ( V_91 ) ;
if ( V_87 )
goto V_111;
V_112 = V_91 ;
return 0 ;
V_111:
F_42 () ;
V_93:
F_54 ( V_91 ) ;
return V_87 ;
}
static void F_55 ( void )
{
unsigned long V_3 ;
F_9 () ;
F_2 ( & V_7 , V_3 ) ;
if ( F_14 ( & V_38 ) )
F_15 ( & V_38 ) ;
while ( V_14 ) {
F_7 ( & V_7 , V_3 ) ;
F_23 () ;
F_2 ( & V_7 , V_3 ) ;
}
F_7 ( & V_7 , V_3 ) ;
}
static void F_56 ( void )
{
unsigned long V_3 ;
F_2 ( & V_7 , V_3 ) ;
V_13 = 0 ;
F_7 ( & V_7 , V_3 ) ;
F_9 () ;
}
static void F_57 ( void )
{
unsigned long V_3 ;
F_2 ( & V_7 , V_3 ) ;
V_13 = 1 ;
F_7 ( & V_7 , V_3 ) ;
F_55 () ;
}
static void F_58 ( struct F_49 * V_113 ,
enum V_114 V_114 )
{
switch ( V_114 ) {
case V_115 :
F_57 () ;
break;
case V_116 :
case V_117 :
F_56 () ;
break;
}
}
static void
F_59 ( struct V_118 * V_119 , const char * V_54 , unsigned int V_48 )
{
F_22 ( ( const unsigned char * ) V_54 , V_48 , 1 , 1 , 0 ) ;
}
static struct V_90 *
F_60 ( struct V_118 * V_51 , int * V_120 )
{
* V_120 = 0 ;
return V_112 ;
}
static int
F_61 ( struct V_121 * V_122 ,
unsigned long V_123 , void * V_17 )
{
F_55 () ;
return V_124 ;
}
static int T_1
F_62 ( void )
{
int V_87 ;
if ( ! V_125 )
return 0 ;
V_87 = F_44 ( V_126 ) ;
if ( V_87 )
return V_87 ;
F_63 ( & V_127 , & V_128 ) ;
F_64 ( & V_129 ) ;
F_65 ( & V_130 ) ;
return 0 ;
}
