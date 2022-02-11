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
F_22 ( void )
{
struct V_9 * V_8 ;
struct V_1 * V_2 ;
void * V_4 ;
if ( ! V_54 )
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
F_23 ( const unsigned char * V_55 , int V_48 , int V_56 ,
int V_49 , int V_57 )
{
unsigned long V_3 ;
void * V_4 ;
int V_58 ;
int V_59 ;
if ( V_48 <= 0 )
return 0 ;
V_59 = 0 ;
F_2 ( & V_7 , V_3 ) ;
do {
if ( V_36 == NULL ) {
if ( F_5 ( & V_10 ) )
V_60 ++ ;
while ( F_5 ( & V_10 ) ) {
if ( V_57 || V_13 )
goto V_61;
if ( F_22 () )
break;
F_7 ( & V_7 , V_3 ) ;
F_24 () ;
F_2 ( & V_7 , V_3 ) ;
}
V_4 = ( void * ) V_10 . V_12 ;
F_3 ( (struct V_9 * ) V_4 ) ;
V_36 =
F_17 ( V_4 ) ;
}
V_58 = F_20 ( V_36 ,
V_55 , V_48 , V_49 ) ;
V_59 += V_58 ;
if ( V_58 == V_48 )
break;
F_7 ( & V_7 , V_3 ) ;
F_9 () ;
F_2 ( & V_7 , V_3 ) ;
V_55 += V_58 ;
V_48 -= V_58 ;
} while ( V_48 > 0 );
if ( V_36 != NULL &&
! F_14 ( & V_38 ) && V_56 ) {
V_38 . V_62 = F_21 ;
V_38 . V_17 = 0UL ;
V_38 . V_63 = V_64 + V_65 ;
F_25 ( & V_38 ) ;
}
V_61:
F_7 ( & V_7 , V_3 ) ;
return V_59 ;
}
static int
F_26 ( struct V_66 * V_67 , const unsigned char * V_55 , int V_48 )
{
return F_23 ( V_55 , V_48 , 1 , 0 , 1 ) ;
}
static void
F_27 ( struct V_46 * V_44 )
{
char * V_50 ;
unsigned int V_48 ;
V_50 = ( char * ) ( ( V_40 ) V_44 + sizeof( struct V_46 ) ) ;
V_48 = V_44 -> V_37 - sizeof( struct V_46 ) ;
switch ( * V_50 ) {
case V_68 :
case V_69 :
break;
case V_70 :
V_50 ++ ;
V_48 -- ;
F_28 ( & V_16 , V_50 , V_48 ) ;
F_29 ( & V_16 ) ;
break;
}
}
static int
F_30 ( struct V_66 * V_67 , struct V_71 * V_72 )
{
if ( V_67 -> V_48 == 1 ) {
F_31 ( & V_16 , V_67 ) ;
V_16 . V_73 = 0 ;
if ( ! V_67 -> V_74 . V_75 && ! V_67 -> V_74 . V_76 ) {
V_67 -> V_74 . V_75 = 24 ;
V_67 -> V_74 . V_76 = 80 ;
}
}
return 0 ;
}
static void
F_32 ( struct V_66 * V_67 , struct V_71 * V_72 )
{
if ( V_67 -> V_48 == 1 )
F_31 ( & V_16 , NULL ) ;
}
static int
F_33 ( struct V_66 * V_67 , unsigned char V_77 )
{
return F_23 ( & V_77 , 1 , 0 , 0 , 1 ) ;
}
static void
F_34 ( struct V_66 * V_67 )
{
if ( ! V_14 )
F_9 () ;
else
V_15 = 1 ;
}
static int
F_35 ( struct V_66 * V_67 )
{
unsigned long V_3 ;
struct V_9 * V_78 ;
int V_48 ;
F_2 ( & V_7 , V_3 ) ;
V_48 = 0 ;
if ( V_36 != NULL )
V_48 = F_18 ( V_36 ) ;
F_36 (l, &sclp_vt220_empty)
V_48 += V_79 ;
F_7 ( & V_7 , V_3 ) ;
return V_48 ;
}
static int
F_37 ( struct V_66 * V_67 )
{
unsigned long V_3 ;
struct V_9 * V_78 ;
struct V_1 * V_80 ;
int V_48 ;
F_2 ( & V_7 , V_3 ) ;
V_48 = 0 ;
if ( V_36 != NULL )
V_48 = F_19 ( V_36 ) ;
F_36 (l, &sclp_vt220_outqueue) {
V_80 = F_6 ( V_78 , struct V_1 , V_8 ) ;
V_48 += F_19 ( V_80 ) ;
}
F_7 ( & V_7 , V_3 ) ;
return V_48 ;
}
static void
F_38 ( struct V_66 * V_67 )
{
F_9 () ;
}
static void T_1 F_39 ( void )
{
struct V_9 * V_4 , * V_81 ;
F_40 (page, p, &sclp_vt220_empty) {
F_3 ( V_4 ) ;
F_41 ( ( unsigned long ) V_4 ) ;
}
}
static void T_1 F_42 ( void )
{
V_82 -- ;
if ( V_82 != 0 )
return;
F_43 ( & V_28 ) ;
F_39 () ;
F_44 ( & V_16 ) ;
}
static int T_1 F_45 ( int V_83 )
{
void * V_4 ;
int V_84 ;
int V_85 ;
V_82 ++ ;
if ( V_82 != 1 )
return 0 ;
F_46 ( & V_7 ) ;
F_47 ( & V_10 ) ;
F_47 ( & V_11 ) ;
F_48 ( & V_38 ) ;
F_49 ( & V_16 ) ;
V_36 = NULL ;
V_86 = 0 ;
V_15 = 0 ;
V_85 = - V_87 ;
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
V_4 = ( void * ) F_50 ( V_88 | V_89 ) ;
if ( ! V_4 )
goto V_61;
F_4 ( V_4 , & V_10 ) ;
}
V_85 = F_51 ( & V_28 ) ;
V_61:
if ( V_85 ) {
F_39 () ;
V_82 -- ;
F_44 ( & V_16 ) ;
}
return V_85 ;
}
static int T_1 F_52 ( void )
{
struct V_90 * V_91 ;
int V_85 ;
V_91 = F_53 ( 1 ) ;
if ( ! V_91 )
return - V_87 ;
V_85 = F_45 ( V_92 ) ;
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
F_54 ( V_91 , & V_108 ) ;
F_55 ( & V_16 , V_91 , 0 ) ;
V_85 = F_56 ( V_91 ) ;
if ( V_85 )
goto V_109;
V_85 = F_51 ( & V_110 ) ;
if ( V_85 )
goto V_111;
V_112 = V_91 ;
return 0 ;
V_111:
F_57 ( V_91 ) ;
V_109:
F_42 () ;
V_93:
F_58 ( V_91 ) ;
return V_85 ;
}
static void F_59 ( void )
{
unsigned long V_3 ;
F_9 () ;
F_2 ( & V_7 , V_3 ) ;
if ( F_14 ( & V_38 ) )
F_15 ( & V_38 ) ;
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
static void F_62 ( struct F_51 * V_113 ,
enum V_114 V_114 )
{
switch ( V_114 ) {
case V_115 :
F_61 () ;
break;
case V_116 :
case V_117 :
F_60 () ;
break;
}
}
static void
F_63 ( struct V_118 * V_119 , const char * V_55 , unsigned int V_48 )
{
F_23 ( ( const unsigned char * ) V_55 , V_48 , 1 , 1 , 0 ) ;
}
static struct V_90 *
F_64 ( struct V_118 * V_51 , int * V_120 )
{
* V_120 = 0 ;
return V_112 ;
}
static int
F_65 ( struct V_121 * V_122 ,
unsigned long V_123 , void * V_17 )
{
F_59 () ;
return V_124 ;
}
static int T_1
F_66 ( void )
{
int V_85 ;
if ( ! V_125 )
return 0 ;
V_85 = F_45 ( V_126 ) ;
if ( V_85 )
return V_85 ;
F_67 ( & V_127 , & V_128 ) ;
F_68 ( & V_129 ) ;
F_69 ( & V_130 ) ;
return 0 ;
}
