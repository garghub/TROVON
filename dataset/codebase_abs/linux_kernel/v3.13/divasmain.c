static char * F_1 ( const char * V_1 )
{
char * V_2 ;
char * V_3 ;
if ( ( V_3 = strchr ( V_1 , ':' ) ) ) {
V_2 = V_3 + 2 ;
V_3 = strchr ( V_2 , '$' ) ;
* -- V_3 = 0 ;
} else
V_2 = L_1 ;
return V_2 ;
}
void F_2 ( unsigned char * V_4 , ... )
{
T_1 args ;
unsigned char line [ 160 ] ;
va_start ( args , V_4 ) ;
vsnprintf ( line , sizeof( line ) , V_4 , args ) ;
va_end ( args ) ;
F_3 ( V_5 L_2 , V_6 , line ) ;
}
void F_4 ( char * V_3 )
{
char V_7 [ 32 ] ;
strcpy ( V_7 , V_8 ) ;
sprintf ( V_3 , L_3 , V_6 , V_9 ,
F_1 ( V_7 ) , V_10 , V_11 , V_12 ) ;
}
T_2 F_5 ( void * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 ;
return ( ( T_2 ) V_15 -> V_16 -> V_17 ) ;
}
T_2 F_6 ( void * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 ;
return ( ( T_2 ) V_15 -> V_18 ) ;
}
unsigned long F_7 ( unsigned char V_16 , unsigned char V_19 ,
void * V_13 )
{
unsigned char V_20 = 0 ;
struct V_14 * V_21 = (struct V_14 * ) V_13 ;
V_20 = V_21 -> V_20 ;
return ( ( unsigned long ) V_20 ) ;
}
unsigned long F_8 ( unsigned char V_16 , unsigned char V_19 ,
int V_22 , void * V_13 )
{
unsigned long V_23 = 0 ;
struct V_14 * V_21 = (struct V_14 * ) V_13 ;
if ( V_22 < 6 ) {
V_23 = V_21 -> V_24 [ V_22 ] . V_25 ;
}
F_9 ( ( L_4 , V_22 , V_23 ) ) ;
{
unsigned long type = ( V_23 & 0x00000001 ) ;
if ( type & V_26 ) {
F_9 ( ( L_5 ) ) ;
V_23 &= V_27 ;
} else {
F_9 ( ( L_6 ) ) ;
V_23 &= V_28 ;
}
F_9 ( ( L_7 , V_23 ) ) ;
}
return ( V_23 ) ;
}
void F_10 ( T_2 V_16 , T_2 V_19 , int V_29 , void * V_30 , int V_31 ,
void * V_13 )
{
struct V_14 * V_21 = (struct V_14 * ) V_13 ;
switch ( V_31 ) {
case 1 :
F_11 ( V_21 , V_29 ,
* ( unsigned char * ) V_30 ) ;
break;
case 2 :
F_12 ( V_21 , V_29 ,
* ( unsigned short * ) V_30 ) ;
break;
case 4 :
F_13 ( V_21 , V_29 ,
* ( unsigned int * ) V_30 ) ;
break;
default:
if ( ! ( V_31 % 4 ) && ! ( V_31 & 0x03 ) ) {
T_3 * V_3 = ( T_3 * ) V_30 ;
V_31 /= 4 ;
while ( V_31 -- ) {
F_13 ( V_21 , V_29 ,
* ( unsigned int * )
V_3 ++ ) ;
}
} else {
T_2 * V_3 = ( T_2 * ) V_30 ;
while ( V_31 -- ) {
F_11 ( V_21 , V_29 ,
* ( unsigned char * )
V_3 ++ ) ;
}
}
}
}
void F_14 ( T_2 V_16 , T_2 V_19 , int V_29 , void * V_30 , int V_31 ,
void * V_13 )
{
struct V_14 * V_21 = (struct V_14 * ) V_13 ;
switch ( V_31 ) {
case 1 :
F_15 ( V_21 , V_29 , ( unsigned char * ) V_30 ) ;
break;
case 2 :
F_16 ( V_21 , V_29 , ( unsigned short * ) V_30 ) ;
break;
case 4 :
F_17 ( V_21 , V_29 , ( unsigned int * ) V_30 ) ;
break;
default:
if ( ! ( V_31 % 4 ) && ! ( V_31 & 0x03 ) ) {
T_3 * V_3 = ( T_3 * ) V_30 ;
V_31 /= 4 ;
while ( V_31 -- ) {
F_17 ( V_21 , V_29 ,
( unsigned int * )
V_3 ++ ) ;
}
} else {
T_2 * V_3 = ( T_2 * ) V_30 ;
while ( V_31 -- ) {
F_15 ( V_21 , V_29 ,
( unsigned char * )
V_3 ++ ) ;
}
}
}
}
static void * F_18 ( struct V_14 * V_32 ,
T_4 V_33 ,
T_5 * V_34 ,
void * * V_35 )
{
void * V_36 = F_19 ( V_32 , V_33 , V_34 ) ;
* V_35 = V_36 ;
return ( V_36 ) ;
}
void F_20 ( void * V_37 ,
struct V_38 * * V_39 , int V_40 )
{
struct V_14 * V_15 = (struct V_14 * ) V_37 ;
struct V_38 * V_41 =
F_21 ( V_37 , V_40 ) ;
if ( V_41 ) {
int V_42 ;
T_5 V_34 ;
void * V_43 ;
void * V_35 ;
for ( V_42 = 0 ; V_42 < V_40 ; V_42 ++ ) {
if ( ! ( V_43 = F_18 ( V_15 ,
V_44 ,
& V_34 ,
& V_35 ) ) )
{
break;
}
F_22 ( V_41 , V_42 , V_43 ,
( T_3 ) V_34 ,
V_35 ) ;
F_9 ((L_8,
i, (unsigned long) cpu_addr,
(dword) dma_handle,
(unsigned long) addr_handle)) }
}
* V_39 = V_41 ;
}
void F_23 ( void * V_37 , struct V_38 * V_41 )
{
struct V_14 * V_15 = (struct V_14 * ) V_37 ;
int V_42 ;
T_3 V_45 ;
void * V_43 ;
T_5 V_34 ;
void * V_35 ;
for ( V_42 = 0 ; ( V_41 != NULL ) ; V_42 ++ ) {
F_24 ( V_41 , V_42 , & V_43 , & V_45 ) ;
if ( ! V_43 ) {
break;
}
V_35 = F_25 ( V_41 , V_42 ) ;
V_34 = ( T_5 ) V_45 ;
F_26 ( V_15 , V_44 , V_35 ,
V_34 ) ;
F_9 ((L_9, i,
(unsigned long) cpu_addr, (dword) dma_handle,
(unsigned long) addr_handle))
}
F_27 ( V_41 ) ;
}
int
F_28 ( void * V_46 , int V_47 , unsigned long V_48 ,
unsigned long V_31 , const char * V_49 , int V_50 )
{
if ( V_47 ) {
if ( ! F_29 ( V_48 , V_31 , V_49 ) ) {
F_30 ((L_10, port))
return ( - 1 ) ;
}
} else {
F_31 ( V_48 , V_31 ) ;
}
return ( 0 ) ;
}
void T_6 * F_32 ( T_7 * V_51 , int V_50 , unsigned long V_22 , unsigned long V_52 )
{
void T_6 * V_23 = F_33 ( V_22 , V_52 ) ;
F_9 ( ( L_11 , V_22 , V_23 ) ) ;
return ( V_23 ) ;
}
void F_34 ( void T_6 * V_22 )
{
if ( V_22 ) {
F_35 ( V_22 ) ;
}
}
T_2 T_8 F_36 ( void T_6 * V_36 )
{
return ( F_37 ( ( unsigned long ) V_36 ) ) ;
}
T_9 T_8 F_38 ( void T_6 * V_36 )
{
return ( F_39 ( ( unsigned long ) V_36 ) ) ;
}
void T_8 F_40 ( void T_6 * V_36 , void * V_53 , int V_31 )
{
F_41 ( ( unsigned long ) V_36 , ( T_9 * ) V_53 , V_31 >> 1 ) ;
}
void T_8 F_42 ( void T_6 * V_36 , void * V_53 , int V_31 )
{
F_43 ( ( unsigned long ) V_36 , ( T_9 * ) V_53 , V_31 >> 1 ) ;
}
void T_8 F_44 ( void T_6 * V_36 , T_9 V_54 )
{
F_45 ( V_54 , ( unsigned long ) V_36 ) ;
}
void T_8 F_46 ( void T_6 * V_36 , T_9 V_3 )
{
F_47 ( V_3 , ( unsigned long ) V_36 ) ;
}
int F_48 ( void * V_55 , T_2 V_20 , const char * V_49 )
{
int V_56 = F_49 ( V_20 , V_57 ,
V_58 , V_49 , V_55 ) ;
return ( V_56 ) ;
}
void F_50 ( void * V_55 , T_2 V_20 )
{
F_51 ( V_20 , V_55 ) ;
}
static void F_52 ( unsigned long V_55 )
{
T_10 * V_59 = ( T_10 * ) V_55 ;
T_11 * V_60 = V_59 -> V_59 ;
( * ( V_60 -> V_61 ) ) ( V_60 , V_60 -> V_62 ) ;
}
int F_53 ( T_11 * V_59 ,
T_12 V_61 ,
void * V_62 )
{
T_10 * V_63 ;
V_63 = ( T_10 * ) F_54 ( 0 , sizeof( * V_63 ) ) ;
if ( ! ( V_59 -> V_64 = V_63 ) ) {
return ( - 1 ) ;
}
memset ( V_63 , 0x00 , sizeof( * V_63 ) ) ;
V_59 -> V_61 = V_61 ;
V_59 -> V_62 = V_62 ;
V_63 -> V_59 = V_59 ;
F_55 ( & V_63 -> V_65 , F_52 , ( unsigned long ) V_63 ) ;
return ( 0 ) ;
}
int F_56 ( T_11 * V_59 )
{
if ( V_59 && V_59 -> V_64 ) {
T_10 * V_63 =
( T_10 * ) V_59 -> V_64 ;
F_57 ( & V_63 -> V_65 ) ;
}
return ( 1 ) ;
}
int F_58 ( T_11 * V_59 )
{
return ( 0 ) ;
}
void F_59 ( T_11 * V_59 )
{
if ( V_59 && V_59 -> V_64 ) {
T_10 * V_63 =
( T_10 * ) V_59 -> V_64 ;
void * V_66 ;
F_60 ( & V_63 -> V_65 ) ;
V_66 = V_59 -> V_64 ;
V_59 -> V_64 = NULL ;
F_61 ( 0 , V_66 ) ;
}
}
static int
F_62 ( void * V_67 , void T_13 * V_68 , const void * V_69 , int V_31 )
{
if ( F_63 ( V_68 , V_69 , V_31 ) ) {
return ( - V_70 ) ;
}
return ( V_31 ) ;
}
static int
F_64 ( void * V_67 , void * V_68 , const void T_13 * V_69 , int V_31 )
{
if ( F_65 ( V_68 , V_69 , V_31 ) ) {
return ( - V_70 ) ;
}
return ( V_31 ) ;
}
static int F_66 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
return ( 0 ) ;
}
static int F_67 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
if ( V_72 -> V_73 ) {
F_68 ( V_72 -> V_73 , V_72 ) ;
}
return ( 0 ) ;
}
static T_14 F_69 ( struct V_72 * V_72 , const char T_13 * V_74 ,
T_4 V_75 , T_15 * V_76 )
{
int V_23 = - V_77 ;
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = F_70 ( V_72 , V_74 ,
V_75 ,
F_64 ) ;
}
if ( ! V_72 -> V_73 ) {
return ( - V_78 ) ;
}
V_23 = F_71 ( V_72 -> V_73 , V_72 ,
V_74 , V_75 , F_64 ) ;
switch ( V_23 ) {
case - 1 :
V_23 = - V_79 ;
break;
case - 2 :
V_23 = - V_80 ;
break;
case - 3 :
V_23 = - V_81 ;
break;
}
F_9 ( ( L_12 , V_23 ) ) ;
return ( V_23 ) ;
}
static T_14 F_72 ( struct V_72 * V_72 , char T_13 * V_74 ,
T_4 V_75 , T_15 * V_76 )
{
int V_23 = - V_77 ;
if ( ! V_72 -> V_73 ) {
V_72 -> V_73 = F_70 ( V_72 , V_74 ,
V_75 ,
F_64 ) ;
}
if ( ! V_72 -> V_73 ) {
return ( - V_78 ) ;
}
V_23 = F_73 ( V_72 -> V_73 , V_72 ,
V_74 , V_75 , F_62 ) ;
switch ( V_23 ) {
case - 1 :
V_23 = - V_82 ;
break;
case - 2 :
V_23 = - V_80 ;
break;
case - 3 :
V_23 = - V_70 ;
break;
}
F_9 ( ( L_13 , V_23 ) ) ;
return ( V_23 ) ;
}
static unsigned int F_74 ( struct V_72 * V_72 , T_16 * V_83 )
{
if ( ! V_72 -> V_73 ) {
return ( V_84 ) ;
}
return ( V_85 | V_86 ) ;
}
static void F_75 ( void )
{
F_76 ( V_12 , V_87 ) ;
}
static int T_17 F_77 ( void )
{
if ( ( V_12 = F_78 ( 0 , V_87 , & V_88 ) ) < 0 )
{
F_3 ( V_89 L_14 ,
V_6 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_79 ( struct V_14 * V_15 , const struct V_90 * V_91 )
{
void * V_92 = NULL ;
T_18 V_93 ;
T_18 V_94 = 32 ;
F_9 ((L_15,
CardProperties[ent->driver_data].Name,
pdev->bus->number, pdev->devfn))
F_3 ( V_5 L_16 ,
V_6 , V_95 [ V_91 -> V_96 ] . V_97 ,
V_15 -> V_16 -> V_17 , V_15 -> V_18 ) ;
if ( F_80 ( V_15 ) ) {
F_9 ((L_17,
DRIVERLNAME,
CardProperties[ent->driver_data].Name,
pdev->bus->number,
pdev->devfn))
F_3 ( V_89
L_17 ,
V_6 ,
V_95 [ V_91 -> V_96 ] .
V_97 , V_15 -> V_16 -> V_17 ,
V_15 -> V_18 ) ;
return ( - V_98 ) ;
}
F_81 ( V_15 ) ;
F_15 ( V_15 , V_99 , & V_93 ) ;
if ( ! V_93 ) {
F_9 ((L_18,
DRIVERLNAME, pdev->bus->number, pdev->devfn))
F_3 ( V_5
L_18 ,
V_6 , V_15 -> V_16 -> V_17 , V_15 -> V_18 ) ;
F_11 ( V_15 , V_99 , V_94 ) ;
}
if ( ! ( V_92 = F_82 ( V_15 , V_91 -> V_96 ) ) ) {
F_9 ((L_19,
DRIVERLNAME,
CardProperties[ent->driver_data].Name,
pdev->bus->number,
pdev->devfn))
F_3 ( V_89
L_19 ,
V_6 ,
V_95 [ V_91 -> V_96 ] .
V_97 , V_15 -> V_16 -> V_17 ,
V_15 -> V_18 ) ;
return ( - V_98 ) ;
}
F_83 ( V_15 , V_92 ) ;
return ( 0 ) ;
}
static void F_84 ( struct V_14 * V_15 )
{
void * V_92 = F_85 ( V_15 ) ;
F_9 ((L_20,
pdev->bus->number, pdev->devfn))
F_3 ( V_5 L_21 ,
V_6 , V_15 -> V_16 -> V_17 , V_15 -> V_18 ) ;
if ( V_92 ) {
F_86 ( V_92 ) ;
}
}
static int T_17 F_87 ( void )
{
char V_7 [ 50 ] ;
int V_23 = 0 ;
F_3 ( V_5 L_22 , V_100 ) ;
F_3 ( V_5 L_23 , V_6 , V_9 ) ;
strcpy ( V_7 , V_8 ) ;
F_3 ( L_24 , F_1 ( V_7 ) ,
V_10 , V_11 ) ;
F_3 ( V_5 L_25 , V_6 ) ;
#ifdef F_88
F_3 ( L_26 ) ;
#endif
#ifdef F_89
F_3 ( L_27 ) ;
#endif
F_3 ( L_28 ) ;
if ( ! F_90 ( V_101 ) ) {
F_3 ( V_89 L_29 ,
V_6 ) ;
V_23 = - V_98 ;
goto V_102;
}
if ( ! F_77 () ) {
#ifdef F_91
F_92 () ;
#endif
V_23 = - V_98 ;
goto V_102;
}
if ( ! F_93 () ) {
#ifdef F_91
F_75 () ;
F_92 () ;
#endif
F_3 ( V_89 L_30 ,
V_6 ) ;
V_23 = - V_98 ;
goto V_102;
}
if ( ( V_23 = F_94 ( & V_103 ) ) ) {
#ifdef F_91
F_95 () ;
F_75 () ;
F_92 () ;
#endif
F_3 ( V_89 L_31 ,
V_6 ) ;
goto V_102;
}
F_3 ( V_5 L_32 , V_6 , V_12 ) ;
V_102:
return ( V_23 ) ;
}
static void T_19 F_96 ( void )
{
F_97 ( & V_103 ) ;
F_95 () ;
F_75 () ;
F_92 () ;
F_3 ( V_5 L_33 , V_6 ) ;
}
