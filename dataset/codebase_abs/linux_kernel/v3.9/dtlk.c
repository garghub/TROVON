static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned int V_5 = F_2 ( F_3 ( V_1 ) ) ;
char V_6 ;
int V_7 = 0 , V_8 ;
F_4 ( L_1 ) ;
if ( V_5 != V_9 || ! V_10 )
return - V_11 ;
for ( V_8 = 0 ; V_8 < V_12 ; V_8 ++ ) {
while ( V_7 < V_3 && F_5 () ) {
V_6 = F_6 () ;
if ( F_7 ( V_6 , V_2 ++ ) )
return - V_13 ;
V_7 ++ ;
}
if ( V_7 )
return V_7 ;
if ( V_1 -> V_14 & V_15 )
break;
F_8 ( 100 ) ;
}
if ( V_8 == V_12 )
F_9 ( V_16 L_2 ) ;
V_17 ;
return - V_18 ;
}
static T_1 F_10 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
int V_7 = 0 , V_8 = 0 , V_6 ;
F_4 ( L_3 ) ;
#ifdef F_11
F_9 ( L_4 ) ;
{
int V_7 , V_6 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
if ( F_12 ( V_6 , V_2 + V_7 ) )
return - V_13 ;
if ( ' ' <= V_6 && V_6 <= '~' )
F_9 ( L_5 , V_6 ) ;
else
F_9 ( L_6 , V_6 ) ;
}
F_9 ( L_7 ) ;
}
#endif
if ( F_2 ( F_3 ( V_1 ) ) != V_9 )
return - V_11 ;
while ( 1 ) {
while ( V_7 < V_3 && ! F_12 ( V_6 , V_2 ) &&
( V_6 == V_19 || F_13 () ) ) {
F_14 ( V_6 ) ;
V_2 ++ ;
V_7 ++ ;
if ( V_7 % 5 == 0 )
F_8 ( 1 ) ;
else {
for ( V_8 = 0 ;
V_8 < V_12 / ( 4000 / V_20 ) ;
V_8 ++ )
if ( F_15 ( V_21 ) &
V_22 )
break;
}
V_8 = 0 ;
}
if ( V_7 == V_3 )
return V_7 ;
if ( V_1 -> V_14 & V_15 )
break;
F_8 ( 1 ) ;
if ( ++ V_8 > 10 * V_20 ) {
F_9 ( L_8
L_9 ,
F_15 ( V_21 ) ) ;
V_17 ;
return - V_23 ;
}
}
V_17 ;
return - V_18 ;
}
static unsigned int F_16 ( struct V_1 * V_1 , T_5 * V_24 )
{
int V_25 = 0 ;
unsigned long V_26 ;
F_4 ( L_10 ) ;
F_17 ( V_1 , & V_27 , V_24 ) ;
if ( V_10 && F_5 () ) {
F_18 ( & V_28 ) ;
V_25 = V_29 | V_30 ;
}
if ( F_13 () ) {
F_18 ( & V_28 ) ;
V_25 |= V_31 | V_32 ;
}
V_26 = V_33 + 3 * V_20 / 100 ;
F_19 ( & V_28 , V_26 ) ;
return V_25 ;
}
static void F_20 ( unsigned long V_34 )
{
F_4 ( L_11 ) ;
F_21 ( & V_27 ) ;
}
static long F_22 ( struct V_1 * V_1 ,
unsigned int V_35 ,
unsigned long V_36 )
{
char T_2 * V_37 = ( char T_2 * ) V_36 ;
struct V_38 * V_39 ;
char V_40 ;
F_4 ( L_12 ) ;
switch ( V_35 ) {
case V_41 :
F_23 ( & V_42 ) ;
V_39 = F_24 () ;
F_25 ( & V_42 ) ;
if ( F_26 ( V_37 , V_39 , sizeof( struct V_38 ) ) )
return - V_11 ;
return 0 ;
case V_43 :
V_40 = F_15 ( V_21 ) ;
return F_7 ( V_40 , V_37 ) ;
default:
return - V_11 ;
}
}
static int F_27 ( struct V_44 * V_44 , struct V_1 * V_1 )
{
F_4 ( L_13 ) ;
F_28 ( V_44 , V_1 ) ;
switch ( F_2 ( V_44 ) ) {
case V_9 :
if ( V_45 )
return - V_23 ;
return F_28 ( V_44 , V_1 ) ;
default:
return - V_46 ;
}
}
static int F_29 ( struct V_44 * V_44 , struct V_1 * V_1 )
{
F_4 ( L_14 ) ;
switch ( F_2 ( V_44 ) ) {
case V_9 :
break;
default:
break;
}
V_17 ;
F_30 ( & V_28 ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
int V_47 ;
V_48 = 0 ;
V_21 = 0 ;
V_45 = 0 ;
V_49 = F_32 ( 0 , L_15 , & V_50 ) ;
if ( V_49 < 0 ) {
F_9 ( V_16 L_16 ) ;
return V_49 ;
}
V_47 = F_33 () ;
if ( V_47 ) {
F_34 ( V_49 , L_15 ) ;
return V_47 ;
}
F_9 ( L_17 , V_49 ) ;
F_35 ( & V_27 ) ;
return 0 ;
}
static void T_7 F_36 ( void )
{
F_37 ( L_18 , 8 ) ;
F_8 ( 500 ) ;
F_14 ( V_19 ) ;
F_34 ( V_49 , L_15 ) ;
F_38 ( V_48 , V_51 ) ;
}
static int F_5 ( void )
{
#ifdef F_11
F_9 ( L_19 , F_15 ( V_48 ) != 0x7f , V_33 ) ;
#endif
return F_15 ( V_48 ) != 0x7f ;
}
static int F_13 ( void )
{
#ifdef F_39
F_9 ( L_20 , ( F_15 ( V_21 ) & V_22 ) != 0 ) ;
#endif
return F_15 ( V_21 ) & V_22 ;
}
static int T_6 F_33 ( void )
{
unsigned int V_52 = 0 ;
int V_7 = 0 ;
struct V_38 * V_39 ;
if ( V_48 | V_21 )
return - V_23 ;
for ( V_7 = 0 ; V_53 [ V_7 ] ; V_7 ++ ) {
#if 0
printk("DoubleTalk PC - Port %03x = %04x\n",
dtlk_portlist[i], (testval = inw_p(dtlk_portlist[i])));
#endif
if ( ! F_40 ( V_53 [ V_7 ] , V_51 ,
L_15 ) )
continue;
V_52 = F_41 ( V_53 [ V_7 ] ) ;
if ( ( V_52 &= 0xfbff ) == 0x107f ) {
V_48 = V_53 [ V_7 ] ;
V_21 = V_48 + 1 ;
V_39 = F_24 () ;
F_9 ( L_21
L_22 ,
V_53 [ V_7 ] , V_53 [ V_7 ] +
V_51 - 1 ,
V_39 -> V_54 , V_39 -> V_55 ) ;
F_42 ( 0xff , V_48 ) ;
F_37 ( L_23 , 8 ) ;
F_8 ( 100 ) ;
V_10 = F_5 () ;
#ifdef F_11
F_9 ( L_24 , V_10 ) ;
#endif
#ifdef F_43
{
#define F_44 \
for (i = 0; i < 10; i++) \
{ \
buffer[b++] = inb_p(dtlk_port_lpc); \
__delay(loops_per_jiffy/(1000000/HZ)); \
}
char V_56 [ 1000 ] ;
int V_57 = 0 , V_7 , V_58 ;
F_44
F_42 ( 0xff , V_48 ) ;
V_56 [ V_57 ++ ] = 0 ;
F_44
F_37 ( L_25 , 4 ) ;
V_56 [ V_57 ++ ] = 0 ;
F_45 ( 50 * V_12 / ( 1000 / V_20 ) ) ;
F_42 ( 0xff , V_48 ) ;
V_56 [ V_57 ++ ] = 0 ;
F_44
F_9 ( L_26 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ )
F_9 ( L_27 , V_56 [ V_58 ] ) ;
F_9 ( L_26 ) ;
}
#endif
#ifdef F_46
{
#define F_44 \
for (i = 0; i < 10; i++) \
{ \
buffer[b++] = inb_p(dtlk_port_tts); \
__delay(loops_per_jiffy/(1000000/HZ)); \
}
char V_56 [ 1000 ] ;
int V_57 = 0 , V_7 , V_58 ;
F_47 ( 10 ) ;
F_44
F_42 ( 0x03 , V_21 ) ;
V_56 [ V_57 ++ ] = 0 ;
F_44
F_44
F_9 ( L_26 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ )
F_9 ( L_27 , V_56 [ V_58 ] ) ;
F_9 ( L_26 ) ;
}
#endif
F_37 ( L_28 , 18 ) ;
return 0 ;
}
F_38 ( V_53 [ V_7 ] , V_51 ) ;
}
F_9 ( V_59 L_29 ) ;
return - V_60 ;
}
static struct V_38 * F_24 ( void )
{
unsigned char * V_61 ;
static char V_2 [ sizeof( struct V_38 ) + 1 ] ;
int V_62 , V_7 ;
static struct V_38 V_63 ;
F_4 ( L_30 ) ;
F_37 ( L_31 , 3 ) ;
for ( V_62 = 0 , V_7 = 0 ; V_7 < 50 ; V_7 ++ ) {
V_2 [ V_62 ] = F_48 () ;
if ( V_62 > 2 && V_2 [ V_62 ] == 0x7f )
break;
if ( V_62 < sizeof( struct V_38 ) )
V_62 ++ ;
}
V_61 = V_2 ;
V_63 . V_55 = V_61 [ 0 ] + V_61 [ 1 ] * 256 ;
V_61 += 2 ;
V_7 = 0 ;
while ( * V_61 != '\r' ) {
V_63 . V_54 [ V_7 ] = * V_61 ;
if ( V_7 < sizeof( V_63 . V_54 ) - 1 )
V_7 ++ ;
V_61 ++ ;
}
V_63 . V_54 [ V_7 ] = 0 ;
V_61 ++ ;
V_63 . V_64 = * V_61 ++ ;
V_63 . V_65 = * V_61 ++ ;
V_63 . V_66 = * V_61 ++ ;
V_63 . V_67 = * V_61 ++ ;
V_63 . V_68 = * V_61 ++ ;
V_63 . V_69 = * V_61 ++ ;
V_63 . V_70 = * V_61 ++ ;
V_63 . V_71 = * V_61 ++ ;
V_63 . V_72 = * V_61 ++ ;
V_63 . V_73 = * V_61 ++ ;
V_63 . V_74 = * V_61 ++ ;
V_63 . V_75 = * V_61 ++ ;
V_63 . V_76 = * V_61 ++ ;
V_63 . V_77 = * V_61 ++ ;
V_63 . V_78 = V_10 ;
V_17 ;
return & V_63 ;
}
static char F_48 ( void )
{
int V_40 , V_8 = 0 ;
char V_6 ;
F_4 ( L_32 ) ;
do {
V_40 = F_15 ( V_21 ) ;
} while ( ( V_40 & V_79 ) == 0 &&
V_8 ++ < V_80 );
if ( V_8 > V_80 )
F_9 ( V_16 L_33 ) ;
V_6 = F_15 ( V_21 ) ;
V_6 &= 0x7f ;
F_42 ( V_6 , V_21 ) ;
V_8 = 0 ;
do {
V_40 = F_15 ( V_21 ) ;
} while ( ( V_40 & V_79 ) != 0 &&
V_8 ++ < V_80 );
if ( V_8 > V_80 )
F_9 ( V_16 L_33 ) ;
V_17 ;
return V_6 ;
}
static char F_6 ( void )
{
int V_8 = 0 ;
char V_6 ;
F_4 ( L_34 ) ;
V_6 = F_15 ( V_48 ) ;
F_42 ( 0xff , V_48 ) ;
V_8 = ( V_12 * 20 ) / ( 1000000 / V_20 ) ;
while ( F_15 ( V_48 ) != 0x7f && -- V_8 > 0 ) ;
if ( V_8 == 0 )
F_9 ( V_16 L_35 ) ;
V_17 ;
return V_6 ;
}
static char F_37 ( const char * V_2 , int V_81 )
{
char V_82 = 0 ;
F_4 ( L_36 ) ;
while ( V_81 -- > 0 )
V_82 = F_14 ( * V_2 ++ ) ;
V_17 ;
return V_82 ;
}
static char F_14 ( char V_6 )
{
int V_8 = 0 ;
#ifdef F_39
F_9 ( L_37 ) ;
if ( ' ' <= V_6 && V_6 <= '~' )
F_9 ( L_38 , V_6 ) ;
else
F_9 ( L_39 , V_6 ) ;
#endif
if ( V_6 != V_19 )
while ( ( F_15 ( V_21 ) & V_22 ) == 0 &&
V_8 ++ < V_80 )
;
if ( V_8 > V_80 )
F_9 ( V_16 L_40 ) ;
F_42 ( V_6 , V_21 ) ;
for ( V_8 = 0 ; V_8 < V_12 / ( 100000 / V_20 ) ; V_8 ++ )
if ( ( F_15 ( V_21 ) & V_22 ) == 0 )
break;
#ifdef F_39
F_9 ( L_41 ) ;
#endif
return 0 ;
}
