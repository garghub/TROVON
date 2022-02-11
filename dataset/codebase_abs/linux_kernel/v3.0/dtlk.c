static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned int V_5 = F_2 ( V_1 -> V_6 . V_7 -> V_8 ) ;
char V_9 ;
int V_10 = 0 , V_11 ;
F_3 ( L_1 ) ;
if ( V_5 != V_12 || ! V_13 )
return - V_14 ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
while ( V_10 < V_3 && F_4 () ) {
V_9 = F_5 () ;
if ( F_6 ( V_9 , V_2 ++ ) )
return - V_16 ;
V_10 ++ ;
}
if ( V_10 )
return V_10 ;
if ( V_1 -> V_17 & V_18 )
break;
F_7 ( 100 ) ;
}
if ( V_11 == V_15 )
F_8 ( V_19 L_2 ) ;
V_20 ;
return - V_21 ;
}
static T_1 F_9 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
int V_10 = 0 , V_11 = 0 , V_9 ;
F_3 ( L_3 ) ;
#ifdef F_10
F_8 ( L_4 ) ;
{
int V_10 , V_9 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
if ( F_11 ( V_9 , V_2 + V_10 ) )
return - V_16 ;
if ( ' ' <= V_9 && V_9 <= '~' )
F_8 ( L_5 , V_9 ) ;
else
F_8 ( L_6 , V_9 ) ;
}
F_8 ( L_7 ) ;
}
#endif
if ( F_2 ( V_1 -> V_6 . V_7 -> V_8 ) != V_12 )
return - V_14 ;
while ( 1 ) {
while ( V_10 < V_3 && ! F_11 ( V_9 , V_2 ) &&
( V_9 == V_22 || F_12 () ) ) {
F_13 ( V_9 ) ;
V_2 ++ ;
V_10 ++ ;
if ( V_10 % 5 == 0 )
F_7 ( 1 ) ;
else {
for ( V_11 = 0 ;
V_11 < V_15 / ( 4000 / V_23 ) ;
V_11 ++ )
if ( F_14 ( V_24 ) &
V_25 )
break;
}
V_11 = 0 ;
}
if ( V_10 == V_3 )
return V_10 ;
if ( V_1 -> V_17 & V_18 )
break;
F_7 ( 1 ) ;
if ( ++ V_11 > 10 * V_23 ) {
F_8 ( L_8
L_9 ,
F_14 ( V_24 ) ) ;
V_20 ;
return - V_26 ;
}
}
V_20 ;
return - V_21 ;
}
static unsigned int F_15 ( struct V_1 * V_1 , T_5 * V_27 )
{
int V_28 = 0 ;
unsigned long V_29 ;
F_3 ( L_10 ) ;
F_16 ( V_1 , & V_30 , V_27 ) ;
if ( V_13 && F_4 () ) {
F_17 ( & V_31 ) ;
V_28 = V_32 | V_33 ;
}
if ( F_12 () ) {
F_17 ( & V_31 ) ;
V_28 |= V_34 | V_35 ;
}
V_29 = V_36 + 3 * V_23 / 100 ;
F_18 ( & V_31 , V_29 ) ;
return V_28 ;
}
static void F_19 ( unsigned long V_37 )
{
F_3 ( L_11 ) ;
F_20 ( & V_30 ) ;
}
static long F_21 ( struct V_1 * V_1 ,
unsigned int V_38 ,
unsigned long V_39 )
{
char T_2 * V_40 = ( char T_2 * ) V_39 ;
struct V_41 * V_42 ;
char V_43 ;
F_3 ( L_12 ) ;
switch ( V_38 ) {
case V_44 :
F_22 ( & V_45 ) ;
V_42 = F_23 () ;
F_24 ( & V_45 ) ;
if ( F_25 ( V_40 , V_42 , sizeof( struct V_41 ) ) )
return - V_14 ;
return 0 ;
case V_46 :
V_43 = F_14 ( V_24 ) ;
return F_6 ( V_43 , V_40 ) ;
default:
return - V_14 ;
}
}
static int F_26 ( struct V_47 * V_47 , struct V_1 * V_1 )
{
F_3 ( L_13 ) ;
F_27 ( V_47 , V_1 ) ;
switch ( F_2 ( V_47 ) ) {
case V_12 :
if ( V_48 )
return - V_26 ;
return F_27 ( V_47 , V_1 ) ;
default:
return - V_49 ;
}
}
static int F_28 ( struct V_47 * V_47 , struct V_1 * V_1 )
{
F_3 ( L_14 ) ;
switch ( F_2 ( V_47 ) ) {
case V_12 :
break;
default:
break;
}
V_20 ;
F_29 ( & V_31 ) ;
return 0 ;
}
static int T_6 F_30 ( void )
{
int V_50 ;
V_51 = 0 ;
V_24 = 0 ;
V_48 = 0 ;
V_52 = F_31 ( 0 , L_15 , & V_53 ) ;
if ( V_52 < 0 ) {
F_8 ( V_19 L_16 ) ;
return V_52 ;
}
V_50 = F_32 () ;
if ( V_50 ) {
F_33 ( V_52 , L_15 ) ;
return V_50 ;
}
F_8 ( L_17 , V_52 ) ;
F_34 ( & V_30 ) ;
return 0 ;
}
static void T_7 F_35 ( void )
{
F_36 ( L_18 , 8 ) ;
F_7 ( 500 ) ;
F_13 ( V_22 ) ;
F_33 ( V_52 , L_15 ) ;
F_37 ( V_51 , V_54 ) ;
}
static int F_4 ( void )
{
#ifdef F_10
F_8 ( L_19 , F_14 ( V_51 ) != 0x7f , V_36 ) ;
#endif
return F_14 ( V_51 ) != 0x7f ;
}
static int F_12 ( void )
{
#ifdef F_38
F_8 ( L_20 , ( F_14 ( V_24 ) & V_25 ) != 0 ) ;
#endif
return F_14 ( V_24 ) & V_25 ;
}
static int T_6 F_32 ( void )
{
unsigned int V_55 = 0 ;
int V_10 = 0 ;
struct V_41 * V_42 ;
if ( V_51 | V_24 )
return - V_26 ;
for ( V_10 = 0 ; V_56 [ V_10 ] ; V_10 ++ ) {
#if 0
printk("DoubleTalk PC - Port %03x = %04x\n",
dtlk_portlist[i], (testval = inw_p(dtlk_portlist[i])));
#endif
if ( ! F_39 ( V_56 [ V_10 ] , V_54 ,
L_15 ) )
continue;
V_55 = F_40 ( V_56 [ V_10 ] ) ;
if ( ( V_55 &= 0xfbff ) == 0x107f ) {
V_51 = V_56 [ V_10 ] ;
V_24 = V_51 + 1 ;
V_42 = F_23 () ;
F_8 ( L_21
L_22 ,
V_56 [ V_10 ] , V_56 [ V_10 ] +
V_54 - 1 ,
V_42 -> V_57 , V_42 -> V_58 ) ;
F_41 ( 0xff , V_51 ) ;
F_36 ( L_23 , 8 ) ;
F_7 ( 100 ) ;
V_13 = F_4 () ;
#ifdef F_10
F_8 ( L_24 , V_13 ) ;
#endif
#ifdef F_42
{
#define F_43 \
for (i = 0; i < 10; i++) \
{ \
buffer[b++] = inb_p(dtlk_port_lpc); \
__delay(loops_per_jiffy/(1000000/HZ)); \
}
char V_59 [ 1000 ] ;
int V_60 = 0 , V_10 , V_61 ;
F_43
F_41 ( 0xff , V_51 ) ;
V_59 [ V_60 ++ ] = 0 ;
F_43
F_36 ( L_25 , 4 ) ;
V_59 [ V_60 ++ ] = 0 ;
F_44 ( 50 * V_15 / ( 1000 / V_23 ) ) ;
F_41 ( 0xff , V_51 ) ;
V_59 [ V_60 ++ ] = 0 ;
F_43
F_8 ( L_26 ) ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ )
F_8 ( L_27 , V_59 [ V_61 ] ) ;
F_8 ( L_26 ) ;
}
#endif
#ifdef F_45
{
#define F_43 \
for (i = 0; i < 10; i++) \
{ \
buffer[b++] = inb_p(dtlk_port_tts); \
__delay(loops_per_jiffy/(1000000/HZ)); \
}
char V_59 [ 1000 ] ;
int V_60 = 0 , V_10 , V_61 ;
F_46 ( 10 ) ;
F_43
F_41 ( 0x03 , V_24 ) ;
V_59 [ V_60 ++ ] = 0 ;
F_43
F_43
F_8 ( L_26 ) ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ )
F_8 ( L_27 , V_59 [ V_61 ] ) ;
F_8 ( L_26 ) ;
}
#endif
F_36 ( L_28 , 18 ) ;
return 0 ;
}
F_37 ( V_56 [ V_10 ] , V_54 ) ;
}
F_8 ( V_62 L_29 ) ;
return - V_63 ;
}
static struct V_41 * F_23 ( void )
{
unsigned char * V_64 ;
static char V_2 [ sizeof( struct V_41 ) + 1 ] ;
int V_65 , V_10 ;
static struct V_41 V_66 ;
F_3 ( L_30 ) ;
F_36 ( L_31 , 3 ) ;
for ( V_65 = 0 , V_10 = 0 ; V_10 < 50 ; V_10 ++ ) {
V_2 [ V_65 ] = F_47 () ;
if ( V_65 > 2 && V_2 [ V_65 ] == 0x7f )
break;
if ( V_65 < sizeof( struct V_41 ) )
V_65 ++ ;
}
V_64 = V_2 ;
V_66 . V_58 = V_64 [ 0 ] + V_64 [ 1 ] * 256 ;
V_64 += 2 ;
V_10 = 0 ;
while ( * V_64 != '\r' ) {
V_66 . V_57 [ V_10 ] = * V_64 ;
if ( V_10 < sizeof( V_66 . V_57 ) - 1 )
V_10 ++ ;
V_64 ++ ;
}
V_66 . V_57 [ V_10 ] = 0 ;
V_64 ++ ;
V_66 . V_67 = * V_64 ++ ;
V_66 . V_68 = * V_64 ++ ;
V_66 . V_69 = * V_64 ++ ;
V_66 . V_70 = * V_64 ++ ;
V_66 . V_71 = * V_64 ++ ;
V_66 . V_72 = * V_64 ++ ;
V_66 . V_73 = * V_64 ++ ;
V_66 . V_74 = * V_64 ++ ;
V_66 . V_75 = * V_64 ++ ;
V_66 . V_76 = * V_64 ++ ;
V_66 . V_77 = * V_64 ++ ;
V_66 . V_78 = * V_64 ++ ;
V_66 . V_79 = * V_64 ++ ;
V_66 . V_80 = * V_64 ++ ;
V_66 . V_81 = V_13 ;
V_20 ;
return & V_66 ;
}
static char F_47 ( void )
{
int V_43 , V_11 = 0 ;
char V_9 ;
F_3 ( L_32 ) ;
do {
V_43 = F_14 ( V_24 ) ;
} while ( ( V_43 & V_82 ) == 0 &&
V_11 ++ < V_83 );
if ( V_11 > V_83 )
F_8 ( V_19 L_33 ) ;
V_9 = F_14 ( V_24 ) ;
V_9 &= 0x7f ;
F_41 ( V_9 , V_24 ) ;
V_11 = 0 ;
do {
V_43 = F_14 ( V_24 ) ;
} while ( ( V_43 & V_82 ) != 0 &&
V_11 ++ < V_83 );
if ( V_11 > V_83 )
F_8 ( V_19 L_33 ) ;
V_20 ;
return V_9 ;
}
static char F_5 ( void )
{
int V_11 = 0 ;
char V_9 ;
F_3 ( L_34 ) ;
V_9 = F_14 ( V_51 ) ;
F_41 ( 0xff , V_51 ) ;
V_11 = ( V_15 * 20 ) / ( 1000000 / V_23 ) ;
while ( F_14 ( V_51 ) != 0x7f && -- V_11 > 0 ) ;
if ( V_11 == 0 )
F_8 ( V_19 L_35 ) ;
V_20 ;
return V_9 ;
}
static char F_36 ( const char * V_2 , int V_84 )
{
char V_85 = 0 ;
F_3 ( L_36 ) ;
while ( V_84 -- > 0 )
V_85 = F_13 ( * V_2 ++ ) ;
V_20 ;
return V_85 ;
}
static char F_13 ( char V_9 )
{
int V_11 = 0 ;
#ifdef F_38
F_8 ( L_37 ) ;
if ( ' ' <= V_9 && V_9 <= '~' )
F_8 ( L_38 , V_9 ) ;
else
F_8 ( L_39 , V_9 ) ;
#endif
if ( V_9 != V_22 )
while ( ( F_14 ( V_24 ) & V_25 ) == 0 &&
V_11 ++ < V_83 )
;
if ( V_11 > V_83 )
F_8 ( V_19 L_40 ) ;
F_41 ( V_9 , V_24 ) ;
for ( V_11 = 0 ; V_11 < V_15 / ( 100000 / V_23 ) ; V_11 ++ )
if ( ( F_14 ( V_24 ) & V_25 ) == 0 )
break;
#ifdef F_38
F_8 ( L_41 ) ;
#endif
return 0 ;
}
