static int F_1 ( unsigned char V_1 )
{
if ( V_1 >= 'a' && V_1 <= 'f' )
return V_1 - 'a' + 10 ;
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' ;
if ( V_1 >= 'A' && V_1 <= 'F' )
return V_1 - 'A' + 10 ;
return - 1 ;
}
void F_2 ( const char * V_2 , ... )
{
static char V_3 [ 1024 ] ;
T_1 args ;
int V_4 ;
va_start ( args , V_2 ) ;
V_4 = vsnprintf ( V_3 , sizeof( V_3 ) , V_2 , args ) ;
va_end ( args ) ;
F_3 ( V_3 , V_4 ) ;
}
static inline char * F_4 ( char * V_5 , const char * V_6 )
{
int V_7 = 0 ;
while ( ( V_5 [ V_7 ] = V_6 [ V_7 ] ) )
V_7 ++ ;
return V_5 ;
}
static void F_5 ( void )
{
asm volatile(" dcef @(gr0,gr0),#1 \n"
" icei @(gr0,gr0),#1 \n"
" membar \n"
" bar \n"
);
}
static void F_6 ( char * V_8 )
{
unsigned char V_9 ;
unsigned char V_10 ;
unsigned char V_1 ;
int V_11 , V_12 , V_13 , error ;
for (; ; ) {
do {
F_7 ( & V_1 , 0 ) ;
} while ( V_1 != '$' );
V_9 = 0 ;
V_10 = - 1 ;
V_11 = 0 ;
error = 0 ;
while ( V_11 < V_14 ) {
V_13 = F_7 ( & V_1 , 0 ) ;
if ( V_13 < 0 )
error = V_13 ;
if ( V_1 == '#' )
break;
V_9 += V_1 ;
V_8 [ V_11 ] = V_1 ;
V_11 ++ ;
}
if ( error == - V_15 ) {
F_8 ( L_1 ) ;
F_8 ( L_2 ) ;
F_9 ( '-' ) ;
continue;
}
if ( V_11 >= V_14 || error )
continue;
V_8 [ V_11 ] = 0 ;
V_13 = F_7 ( & V_1 , 0 ) ;
if ( V_13 < 0 )
error = V_13 ;
V_10 = F_1 ( V_1 ) << 4 ;
V_13 = F_7 ( & V_1 , 0 ) ;
if ( V_13 < 0 )
error = V_13 ;
V_10 |= F_1 ( V_1 ) ;
if ( error ) {
if ( error == - V_15 )
F_8 ( L_3 ) ;
F_8 ( L_2 ) ;
F_9 ( '-' ) ;
continue;
}
if ( V_9 != V_10 ) {
F_8 ( L_2 ) ;
F_9 ( '-' ) ;
continue;
}
F_8 ( L_4 , V_8 , V_9 ) ;
F_8 ( L_5 ) ;
F_9 ( '+' ) ;
if ( V_8 [ 2 ] == ':' ) {
F_9 ( V_8 [ 0 ] ) ;
F_9 ( V_8 [ 1 ] ) ;
V_11 = 0 ;
while ( V_8 [ V_11 ] ) V_11 ++ ;
for ( V_12 = 3 ; V_12 <= V_11 ; V_12 ++ )
V_8 [ V_12 - 3 ] = V_8 [ V_12 ] ;
}
break;
}
}
static int F_10 ( char * V_8 )
{
unsigned char V_9 ;
int V_11 ;
unsigned char V_1 ;
F_8 ( L_6 , V_8 ) ;
do {
F_9 ( '$' ) ;
V_9 = 0 ;
V_11 = 0 ;
while ( ( V_1 = V_8 [ V_11 ] ) != 0 ) {
F_9 ( V_1 ) ;
V_9 += V_1 ;
V_11 += 1 ;
}
F_9 ( '#' ) ;
F_9 ( F_11 ( V_9 ) ) ;
F_9 ( F_12 ( V_9 ) ) ;
} while ( F_7 ( & V_1 , 0 ) ,
#ifdef F_13
V_1 == '-' && ( F_8 ( L_7 ) , 0 ) ,
V_1 != '-' && V_1 != '+' && ( F_8 ( L_8 , V_1 ) , 0 ) ,
#endif
V_1 != '+' && V_1 != '$' );
if ( V_1 == '+' ) {
F_8 ( L_9 ) ;
return 0 ;
}
F_8 ( L_10 ) ;
V_16 = V_1 ;
return 1 ;
}
static int F_14 ( char * * V_17 , unsigned long * V_18 )
{
int V_11 = 0 , V_1 ;
* V_18 = 0 ;
while ( * * V_17 ) {
V_1 = F_1 ( * * V_17 ) ;
if ( V_1 < 0 )
break;
* V_18 = ( * V_18 << 4 ) | ( ( V_19 ) V_1 & 0xf ) ;
V_11 ++ ;
( * V_17 ) ++ ;
}
return V_11 ;
}
static inline int F_15 ( const void * V_20 )
{
#ifdef F_16
unsigned long V_21 ;
asm("lrad %1,%0,#1,#0,#0" : "=r"(paddr) : "r"(vaddr));
if ( ! ( V_21 & V_22 ) )
return 0 ;
#endif
return 1 ;
}
static inline unsigned long F_17 ( unsigned long V_20 )
{
T_2 * V_23 ;
T_3 * V_24 ;
T_4 * V_25 ;
T_5 * V_26 ;
unsigned long V_27 , V_28 ;
V_23 = ( T_2 * ) F_18 ( 3 ) + F_19 ( V_20 ) ;
V_24 = F_20 ( V_23 , V_20 ) ;
V_25 = F_21 ( V_24 , V_20 ) ;
if ( F_22 ( * V_25 ) || ! F_23 ( * V_25 ) )
return 0 ;
V_28 = F_24 ( 5 ) ;
V_27 = F_25 ( * V_25 ) ;
F_26 ( 5 , V_27 | V_29 | V_30 | V_31 | V_32 | V_22 ) ;
V_26 = ( T_5 * ) F_18 ( 5 ) + F_27 ( V_20 ) ;
if ( F_28 ( * V_26 ) )
V_27 = F_29 ( * V_26 ) ;
else
V_27 = 0 ;
F_26 ( 5 , V_28 ) ;
return V_27 ;
}
static inline int F_30 ( const void * V_20 )
{
#ifdef F_16
unsigned long V_26 ;
V_33 = F_24 ( 2 ) ;
V_34 = F_18 ( 2 ) ;
#endif
if ( F_15 ( V_20 ) )
return 1 ;
#ifdef F_16
V_26 = F_17 ( ( unsigned long ) V_20 ) ;
if ( V_26 ) {
F_26 ( 2 , V_26 ) ;
F_31 ( 2 , ( unsigned long ) V_20 & V_35 ) ;
return 1 ;
}
#endif
return 0 ;
}
static inline void F_32 ( void )
{
#ifdef F_16
F_26 ( 2 , V_33 ) ;
F_31 ( 2 , V_34 ) ;
#endif
}
static inline int F_33 ( const void * V_36 , T_6 * V_37 )
{
unsigned long V_38 ;
T_6 V_39 ;
if ( ! F_30 ( V_36 ) )
return 0 ;
asm volatile(" movgs gr0,brr \n"
" ld%I2 %M2,%0 \n"
" movsg brr,%1 \n"
: "=r"(res), "=r"(brr)
: "m"(*(uint32_t *) addr));
* V_37 = V_39 ;
F_32 () ;
return F_34 ( ! V_38 ) ;
}
static inline int F_35 ( void * V_36 , T_6 V_27 )
{
unsigned long V_38 ;
if ( ! F_30 ( V_36 ) )
return 0 ;
asm volatile(" movgs gr0,brr \n"
" st%I2 %1,%M2 \n"
" movsg brr,%0 \n"
: "=r"(brr)
: "r"(val), "m"(*(uint32_t *) addr));
F_32 () ;
return F_34 ( ! V_38 ) ;
}
static inline int F_36 ( const void * V_36 , T_7 * V_37 )
{
unsigned long V_38 ;
T_7 V_39 ;
if ( ! F_30 ( V_36 ) )
return 0 ;
asm volatile(" movgs gr0,brr \n"
" lduh%I2 %M2,%0 \n"
" movsg brr,%1 \n"
: "=r"(res), "=r"(brr)
: "m"(*(uint16_t *) addr));
* V_37 = V_39 ;
F_32 () ;
return F_34 ( ! V_38 ) ;
}
static inline int F_37 ( void * V_36 , T_7 V_27 )
{
unsigned long V_38 ;
if ( ! F_30 ( V_36 ) )
return 0 ;
asm volatile(" movgs gr0,brr \n"
" sth%I2 %1,%M2 \n"
" movsg brr,%0 \n"
: "=r"(brr)
: "r"(val), "m"(*(uint16_t *) addr));
F_32 () ;
return F_34 ( ! V_38 ) ;
}
static inline int F_38 ( const void * V_36 , V_19 * V_37 )
{
unsigned long V_38 ;
V_19 V_39 ;
if ( ! F_30 ( V_36 ) )
return 0 ;
asm volatile(" movgs gr0,brr \n"
" ldub%I2 %M2,%0 \n"
" movsg brr,%1 \n"
: "=r"(res), "=r"(brr)
: "m"(*(uint8_t *) addr));
* V_37 = V_39 ;
F_32 () ;
return F_34 ( ! V_38 ) ;
}
static inline int F_39 ( void * V_36 , V_19 V_27 )
{
unsigned long V_38 ;
if ( ! F_30 ( V_36 ) )
return 0 ;
asm volatile(" movgs gr0,brr \n"
" stb%I2 %1,%M2 \n"
" movsg brr,%0 \n"
: "=r"(brr)
: "r"(val), "m"(*(uint8_t *) addr));
F_32 () ;
return F_34 ( ! V_38 ) ;
}
static void F_40 ( struct V_40 * V_41 , const char * V_42 , unsigned V_43 )
{
char V_44 [ 26 ] ;
int V_45 ;
V_44 [ 0 ] = 'O' ;
while ( V_43 > 0 ) {
V_45 = 1 ;
while ( V_43 > 0 && V_45 < 20 ) {
F_41 ( V_42 , V_44 + V_45 , 2 , 0 ) ;
V_45 += 2 ;
if ( * V_42 == 0x0a ) {
V_44 [ V_45 ++ ] = '0' ;
V_44 [ V_45 ++ ] = 'd' ;
}
V_42 ++ ;
V_43 -- ;
}
V_44 [ V_45 ] = 0 ;
F_10 ( V_44 ) ;
}
}
static unsigned char * F_41 ( const void * V_46 , char * V_3 , int V_11 , int V_47 )
{
const V_19 * V_48 = V_46 ;
V_19 V_1 [ 4 ] V_49 ( ( F_42 ( 4 ) ) ) ;
if ( ( T_6 ) V_48 & 1 && V_11 >= 1 ) {
if ( ! F_38 ( V_48 , V_1 ) )
return NULL ;
V_3 = F_43 ( V_3 , V_1 [ 0 ] ) ;
V_48 ++ ;
V_11 -- ;
}
if ( ( T_6 ) V_48 & 3 && V_11 >= 2 ) {
if ( ! F_36 ( V_48 , ( T_7 * ) V_1 ) )
return NULL ;
V_3 = F_43 ( V_3 , V_1 [ 0 ] ) ;
V_3 = F_43 ( V_3 , V_1 [ 1 ] ) ;
V_48 += 2 ;
V_11 -= 2 ;
}
while ( V_11 >= 4 ) {
if ( ! F_33 ( V_48 , ( T_6 * ) V_1 ) )
return NULL ;
V_3 = F_43 ( V_3 , V_1 [ 0 ] ) ;
V_3 = F_43 ( V_3 , V_1 [ 1 ] ) ;
V_3 = F_43 ( V_3 , V_1 [ 2 ] ) ;
V_3 = F_43 ( V_3 , V_1 [ 3 ] ) ;
V_48 += 4 ;
V_11 -= 4 ;
}
if ( V_11 >= 2 ) {
if ( ! F_36 ( V_48 , ( T_7 * ) V_1 ) )
return NULL ;
V_3 = F_43 ( V_3 , V_1 [ 0 ] ) ;
V_3 = F_43 ( V_3 , V_1 [ 1 ] ) ;
V_48 += 2 ;
V_11 -= 2 ;
}
if ( V_11 >= 1 ) {
if ( ! F_38 ( V_48 , V_1 ) )
return NULL ;
V_3 = F_43 ( V_3 , V_1 [ 0 ] ) ;
}
* V_3 = 0 ;
return V_3 ;
}
static char * F_44 ( const char * V_3 , void * V_46 , int V_11 )
{
V_19 * V_48 = V_46 ;
union {
T_6 V_50 ;
T_7 V_51 ;
V_19 V_52 [ 4 ] ;
} V_1 ;
if ( ( V_53 ) V_48 & 1 && V_11 >= 1 ) {
V_1 . V_52 [ 0 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 0 ] |= F_1 ( * V_3 ++ ) ;
if ( ! F_39 ( V_48 , V_1 . V_52 [ 0 ] ) )
return NULL ;
V_48 ++ ;
V_11 -- ;
}
if ( ( V_53 ) V_48 & 3 && V_11 >= 2 ) {
V_1 . V_52 [ 0 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 0 ] |= F_1 ( * V_3 ++ ) ;
V_1 . V_52 [ 1 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 1 ] |= F_1 ( * V_3 ++ ) ;
if ( ! F_37 ( V_48 , V_1 . V_51 ) )
return NULL ;
V_48 += 2 ;
V_11 -= 2 ;
}
while ( V_11 >= 4 ) {
V_1 . V_52 [ 0 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 0 ] |= F_1 ( * V_3 ++ ) ;
V_1 . V_52 [ 1 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 1 ] |= F_1 ( * V_3 ++ ) ;
V_1 . V_52 [ 2 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 2 ] |= F_1 ( * V_3 ++ ) ;
V_1 . V_52 [ 3 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 3 ] |= F_1 ( * V_3 ++ ) ;
if ( ! F_35 ( V_48 , V_1 . V_50 ) )
return NULL ;
V_48 += 4 ;
V_11 -= 4 ;
}
if ( V_11 >= 2 ) {
V_1 . V_52 [ 0 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 0 ] |= F_1 ( * V_3 ++ ) ;
V_1 . V_52 [ 1 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 1 ] |= F_1 ( * V_3 ++ ) ;
if ( ! F_37 ( V_48 , V_1 . V_51 ) )
return NULL ;
V_48 += 2 ;
V_11 -= 2 ;
}
if ( V_11 >= 1 ) {
V_1 . V_52 [ 0 ] = F_1 ( * V_3 ++ ) << 4 ;
V_1 . V_52 [ 0 ] |= F_1 ( * V_3 ++ ) ;
if ( ! F_39 ( V_48 , V_1 . V_52 [ 0 ] ) )
return NULL ;
}
return ( char * ) V_3 ;
}
static inline int F_45 ( unsigned long V_38 )
{
const struct V_54 * V_55 ;
unsigned long V_56 = ( V_38 & V_57 ) >> 12 ;
for ( V_55 = V_54 ; V_55 -> V_58 ; V_55 ++ )
if ( V_55 -> V_58 & V_38 )
if ( ! V_55 -> V_59 || V_55 -> V_59 == V_56 )
break;
return V_55 -> V_60 ;
}
static int F_46 ( unsigned long type , unsigned long V_36 , unsigned long V_4 )
{
unsigned long V_61 ;
int V_62 , V_7 , V_63 ;
union {
struct {
unsigned long V_64 , V_65 ;
};
V_19 V_66 [ 8 ] ;
} V_67 ;
switch ( type ) {
case 0 :
if ( V_36 & 3 || V_4 > 7 * 4 )
return - V_68 ;
for ( V_62 = 255 ; V_62 >= 0 ; V_62 -- )
if ( ! V_69 [ V_62 ] . V_36 )
break;
if ( V_62 < 0 )
return - V_70 ;
for ( V_7 = 0 ; V_7 < V_4 / 4 ; V_7 ++ )
if ( ! F_33 ( & ( ( T_6 * ) V_36 ) [ V_7 ] ,
& V_69 [ V_62 ] . V_71 [ V_7 ] ) )
return - V_72 ;
for ( V_7 = 0 ; V_7 < V_4 / 4 ; V_7 ++ )
if ( ! F_35 ( & ( ( T_6 * ) V_36 ) [ V_7 ] ,
V_73 )
) {
for ( V_63 = 0 ; V_63 < V_7 ; V_63 ++ )
F_35 ( & ( ( T_6 * ) V_36 ) [ V_63 ] ,
V_69 [ V_62 ] . V_71 [ V_63 ] ) ;
return - V_72 ;
}
V_69 [ V_62 ] . V_36 = V_36 ;
V_69 [ V_62 ] . V_4 = V_4 ;
#if 0
gdbstub_printk("Set BKPT[%02x]: %08lx #%d {%04x, %04x} -> { %04x, %04x }\n",
bkpt,
gdbstub_bkpts[bkpt].addr,
gdbstub_bkpts[bkpt].len,
gdbstub_bkpts[bkpt].originsns[0],
gdbstub_bkpts[bkpt].originsns[1],
((uint32_t *) addr)[0],
((uint32_t *) addr)[1]
);
#endif
return 0 ;
case 1 :
if ( V_36 & 3 || V_4 != 4 )
return - V_68 ;
if ( ! ( V_74 -> V_75 & V_76 ) ) {
V_74 -> V_75 |= V_76 ;
V_74 -> V_77 [ 0 ] = V_36 ;
asm volatile("movgs %0,ibar0" : : "r"(addr));
return 0 ;
}
if ( ! ( V_74 -> V_75 & V_78 ) ) {
V_74 -> V_75 |= V_78 ;
V_74 -> V_77 [ 1 ] = V_36 ;
asm volatile("movgs %0,ibar1" : : "r"(addr));
return 0 ;
}
if ( ! ( V_74 -> V_75 & V_79 ) ) {
V_74 -> V_75 |= V_79 ;
V_74 -> V_77 [ 2 ] = V_36 ;
asm volatile("movgs %0,ibar2" : : "r"(addr));
return 0 ;
}
if ( ! ( V_74 -> V_75 & V_80 ) ) {
V_74 -> V_75 |= V_80 ;
V_74 -> V_77 [ 3 ] = V_36 ;
asm volatile("movgs %0,ibar3" : : "r"(addr));
return 0 ;
}
return - V_70 ;
case 2 :
case 3 :
case 4 :
if ( ( V_36 & ~ 7 ) != ( ( V_36 + V_4 - 1 ) & ~ 7 ) )
return - V_68 ;
V_61 = V_36 & 7 ;
memset ( V_67 . V_66 , 0xff , sizeof( V_67 . V_66 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ )
V_67 . V_66 [ V_61 + V_7 ] = 0 ;
V_36 &= ~ 7 ;
if ( ! ( V_74 -> V_75 & ( V_81 | V_82 ) ) ) {
V_61 = type == 2 ? V_82 : type == 3 ? V_81 : V_81 | V_82 ;
V_74 -> V_75 |= V_61 ;
V_74 -> V_83 [ 0 ] = V_36 ;
V_74 -> V_67 [ 0 ] [ 0 ] = V_67 . V_64 ;
V_74 -> V_67 [ 0 ] [ 1 ] = V_67 . V_65 ;
V_74 -> V_84 [ 0 ] [ 0 ] = 0 ;
V_74 -> V_84 [ 0 ] [ 1 ] = 0 ;
asm volatile(" movgs %0,dbar0 \n"
" movgs %1,dbmr00 \n"
" movgs %2,dbmr01 \n"
" movgs gr0,dbdr00 \n"
" movgs gr0,dbdr01 \n"
: : "r"(addr), "r"(dbmr.mask0), "r"(dbmr.mask1));
return 0 ;
}
if ( ! ( V_74 -> V_75 & ( V_85 | V_86 ) ) ) {
V_61 = type == 2 ? V_86 : type == 3 ? V_85 : V_85 | V_86 ;
V_74 -> V_75 |= V_61 ;
V_74 -> V_83 [ 1 ] = V_36 ;
V_74 -> V_67 [ 1 ] [ 0 ] = V_67 . V_64 ;
V_74 -> V_67 [ 1 ] [ 1 ] = V_67 . V_65 ;
V_74 -> V_84 [ 1 ] [ 0 ] = 0 ;
V_74 -> V_84 [ 1 ] [ 1 ] = 0 ;
asm volatile(" movgs %0,dbar1 \n"
" movgs %1,dbmr10 \n"
" movgs %2,dbmr11 \n"
" movgs gr0,dbdr10 \n"
" movgs gr0,dbdr11 \n"
: : "r"(addr), "r"(dbmr.mask0), "r"(dbmr.mask1));
return 0 ;
}
return - V_70 ;
default:
return - V_68 ;
}
}
int F_47 ( unsigned long type , unsigned long V_36 , unsigned long V_4 )
{
unsigned long V_61 ;
int V_62 , V_7 ;
union {
struct {
unsigned long V_64 , V_65 ;
};
V_19 V_66 [ 8 ] ;
} V_67 ;
switch ( type ) {
case 0 :
for ( V_62 = 255 ; V_62 >= 0 ; V_62 -- )
if ( V_69 [ V_62 ] . V_36 == V_36 && V_69 [ V_62 ] . V_4 == V_4 )
break;
if ( V_62 < 0 )
return - V_87 ;
V_69 [ V_62 ] . V_36 = 0 ;
for ( V_7 = 0 ; V_7 < V_4 / 4 ; V_7 ++ )
if ( ! F_35 ( & ( ( T_6 * ) V_36 ) [ V_7 ] ,
V_69 [ V_62 ] . V_71 [ V_7 ] ) )
return - V_72 ;
return 0 ;
case 1 :
if ( V_36 & 3 || V_4 != 4 )
return - V_68 ;
#define F_48 ( T_8 ) ({ unsigned long x; asm volatile("movsg ibar"#X",%0" : "=r"(x)); x; })
if ( V_74 -> V_75 & V_76 && F_48 ( 0 ) == V_36 ) {
V_74 -> V_75 &= ~ V_76 ;
V_74 -> V_77 [ 0 ] = 0 ;
asm volatile("movgs gr0,ibar0");
return 0 ;
}
if ( V_74 -> V_75 & V_78 && F_48 ( 1 ) == V_36 ) {
V_74 -> V_75 &= ~ V_78 ;
V_74 -> V_77 [ 1 ] = 0 ;
asm volatile("movgs gr0,ibar1");
return 0 ;
}
if ( V_74 -> V_75 & V_79 && F_48 ( 2 ) == V_36 ) {
V_74 -> V_75 &= ~ V_79 ;
V_74 -> V_77 [ 2 ] = 0 ;
asm volatile("movgs gr0,ibar2");
return 0 ;
}
if ( V_74 -> V_75 & V_80 && F_48 ( 3 ) == V_36 ) {
V_74 -> V_75 &= ~ V_80 ;
V_74 -> V_77 [ 3 ] = 0 ;
asm volatile("movgs gr0,ibar3");
return 0 ;
}
return - V_68 ;
case 2 :
case 3 :
case 4 :
if ( ( V_36 & ~ 7 ) != ( ( V_36 + V_4 - 1 ) & ~ 7 ) )
return - V_68 ;
V_61 = V_36 & 7 ;
memset ( V_67 . V_66 , 0xff , sizeof( V_67 . V_66 ) ) ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ )
V_67 . V_66 [ V_61 + V_7 ] = 0 ;
V_36 &= ~ 7 ;
#define F_49 ( T_8 ) ({ unsigned long x; asm volatile("movsg dbar"#X",%0" : "=r"(x)); x; })
#define F_50 ( T_8 ) ({ unsigned long x; asm volatile("movsg dbmr"#X"0,%0" : "=r"(x)); x; })
#define F_51 ( T_8 ) ({ unsigned long x; asm volatile("movsg dbmr"#X"1,%0" : "=r"(x)); x; })
V_61 = type == 2 ? V_82 : type == 3 ? V_81 : V_81 | V_82 ;
if ( ( V_74 -> V_75 & ( V_81 | V_82 ) ) != V_61 ||
F_49 ( 0 ) != V_36 ||
F_50 ( 0 ) != V_67 . V_64 ||
F_51 ( 0 ) != V_67 . V_65 )
goto V_88;
V_74 -> V_75 &= ~ ( V_81 | V_82 ) ;
V_74 -> V_83 [ 0 ] = 0 ;
V_74 -> V_67 [ 0 ] [ 0 ] = 0 ;
V_74 -> V_67 [ 0 ] [ 1 ] = 0 ;
V_74 -> V_84 [ 0 ] [ 0 ] = 0 ;
V_74 -> V_84 [ 0 ] [ 1 ] = 0 ;
asm volatile(" movgs gr0,dbar0 \n"
" movgs gr0,dbmr00 \n"
" movgs gr0,dbmr01 \n"
" movgs gr0,dbdr00 \n"
" movgs gr0,dbdr01 \n");
return 0 ;
V_88:
V_61 = type == 2 ? V_86 : type == 3 ? V_85 : V_85 | V_86 ;
if ( ( V_74 -> V_75 & ( V_85 | V_86 ) ) != V_61 ||
F_49 ( 1 ) != V_36 ||
F_50 ( 1 ) != V_67 . V_64 ||
F_51 ( 1 ) != V_67 . V_65 )
goto V_89;
V_74 -> V_75 &= ~ ( V_85 | V_86 ) ;
V_74 -> V_83 [ 1 ] = 0 ;
V_74 -> V_67 [ 1 ] [ 0 ] = 0 ;
V_74 -> V_67 [ 1 ] [ 1 ] = 0 ;
V_74 -> V_84 [ 1 ] [ 0 ] = 0 ;
V_74 -> V_84 [ 1 ] [ 1 ] = 0 ;
asm volatile(" movgs gr0,dbar1 \n"
" movgs gr0,dbmr10 \n"
" movgs gr0,dbmr11 \n"
" movgs gr0,dbdr10 \n"
" movgs gr0,dbdr11 \n");
return 0 ;
V_89:
return - V_70 ;
default:
return - V_68 ;
}
}
static void F_52 ( void )
{
unsigned long V_36 = V_90 -> V_91 - 4 ;
int V_62 ;
for ( V_62 = 255 ; V_62 >= 0 ; V_62 -- )
if ( V_69 [ V_62 ] . V_36 == V_36 )
break;
if ( V_62 >= 0 )
V_90 -> V_91 = V_36 ;
}
static void T_9 F_53 ( void )
{
unsigned long * V_92 ;
int V_7 ;
F_2 ( L_11 ) ;
F_2 ( L_12 ,
V_90 ,
V_90 -> V_93 & V_94 ? L_13 : L_14 ) ;
V_92 = ( unsigned long * ) V_90 ;
for ( V_7 = 0 ; V_7 < V_95 ; V_7 ++ ) {
F_54 ( L_15 , V_96 [ V_7 + 0 ] , V_92 [ V_7 + 0 ] ) ;
if ( V_7 == V_95 - 1 || V_7 % 5 == 4 )
F_54 ( L_11 ) ;
else
F_54 ( L_16 ) ;
}
F_2 ( L_17 , V_97 -> V_98 , V_97 -> V_99 ) ;
}
static void T_9 F_55 ( void )
{
F_2 ( L_18 , V_100 . V_75 ) ;
F_2 ( L_19 , V_100 . V_38 ) ;
F_2 ( L_20 , F_48 ( 0 ) ) ;
F_2 ( L_21 , F_48 ( 1 ) ) ;
F_2 ( L_22 , F_48 ( 2 ) ) ;
F_2 ( L_23 , F_48 ( 3 ) ) ;
F_2 ( L_24 , F_49 ( 0 ) ) ;
F_2 ( L_25 , F_50 ( 0 ) ) ;
F_2 ( L_26 , F_51 ( 0 ) ) ;
F_2 ( L_27 , F_49 ( 1 ) ) ;
F_2 ( L_28 , F_50 ( 1 ) ) ;
F_2 ( L_29 , F_51 ( 1 ) ) ;
F_2 ( L_11 ) ;
}
void F_56 ( void )
{
asm volatile("movsg hsr0,%0" : "=r"(__debug_mmu.regs.hsr0));
asm volatile("movsg pcsr,%0" : "=r"(__debug_mmu.regs.pcsr));
asm volatile("movsg esr0,%0" : "=r"(__debug_mmu.regs.esr0));
asm volatile("movsg ear0,%0" : "=r"(__debug_mmu.regs.ear0));
asm volatile("movsg epcr0,%0" : "=r"(__debug_mmu.regs.epcr0));
V_101 . V_102 [ 0 ] . V_103 = F_57 ( 0 ) ;
V_101 . V_102 [ 0 ] . V_104 = F_58 ( 0 ) ;
V_101 . V_102 [ 1 ] . V_103 = F_57 ( 1 ) ;
V_101 . V_102 [ 1 ] . V_104 = F_58 ( 1 ) ;
V_101 . V_102 [ 2 ] . V_103 = F_57 ( 2 ) ;
V_101 . V_102 [ 2 ] . V_104 = F_58 ( 2 ) ;
V_101 . V_102 [ 3 ] . V_103 = F_57 ( 3 ) ;
V_101 . V_102 [ 3 ] . V_104 = F_58 ( 3 ) ;
V_101 . V_102 [ 4 ] . V_103 = F_57 ( 4 ) ;
V_101 . V_102 [ 4 ] . V_104 = F_58 ( 4 ) ;
V_101 . V_102 [ 5 ] . V_103 = F_57 ( 5 ) ;
V_101 . V_102 [ 5 ] . V_104 = F_58 ( 5 ) ;
V_101 . V_102 [ 6 ] . V_103 = F_57 ( 6 ) ;
V_101 . V_102 [ 6 ] . V_104 = F_58 ( 6 ) ;
V_101 . V_102 [ 7 ] . V_103 = F_57 ( 7 ) ;
V_101 . V_102 [ 7 ] . V_104 = F_58 ( 7 ) ;
V_101 . V_102 [ 8 ] . V_103 = F_57 ( 8 ) ;
V_101 . V_102 [ 8 ] . V_104 = F_58 ( 8 ) ;
V_101 . V_102 [ 9 ] . V_103 = F_57 ( 9 ) ;
V_101 . V_102 [ 9 ] . V_104 = F_58 ( 9 ) ;
V_101 . V_102 [ 10 ] . V_103 = F_57 ( 10 ) ;
V_101 . V_102 [ 10 ] . V_104 = F_58 ( 10 ) ;
V_101 . V_102 [ 11 ] . V_103 = F_57 ( 11 ) ;
V_101 . V_102 [ 11 ] . V_104 = F_58 ( 11 ) ;
V_101 . V_102 [ 12 ] . V_103 = F_57 ( 12 ) ;
V_101 . V_102 [ 12 ] . V_104 = F_58 ( 12 ) ;
V_101 . V_102 [ 13 ] . V_103 = F_57 ( 13 ) ;
V_101 . V_102 [ 13 ] . V_104 = F_58 ( 13 ) ;
V_101 . V_102 [ 14 ] . V_103 = F_57 ( 14 ) ;
V_101 . V_102 [ 14 ] . V_104 = F_58 ( 14 ) ;
V_101 . V_102 [ 15 ] . V_103 = F_57 ( 15 ) ;
V_101 . V_102 [ 15 ] . V_104 = F_58 ( 15 ) ;
V_101 . V_105 [ 0 ] . V_103 = F_18 ( 0 ) ;
V_101 . V_105 [ 0 ] . V_104 = F_24 ( 0 ) ;
V_101 . V_105 [ 1 ] . V_103 = F_18 ( 1 ) ;
V_101 . V_105 [ 1 ] . V_104 = F_24 ( 1 ) ;
V_101 . V_105 [ 2 ] . V_103 = F_18 ( 2 ) ;
V_101 . V_105 [ 2 ] . V_104 = F_24 ( 2 ) ;
V_101 . V_105 [ 3 ] . V_103 = F_18 ( 3 ) ;
V_101 . V_105 [ 3 ] . V_104 = F_24 ( 3 ) ;
V_101 . V_105 [ 4 ] . V_103 = F_18 ( 4 ) ;
V_101 . V_105 [ 4 ] . V_104 = F_24 ( 4 ) ;
V_101 . V_105 [ 5 ] . V_103 = F_18 ( 5 ) ;
V_101 . V_105 [ 5 ] . V_104 = F_24 ( 5 ) ;
V_101 . V_105 [ 6 ] . V_103 = F_18 ( 6 ) ;
V_101 . V_105 [ 6 ] . V_104 = F_24 ( 6 ) ;
V_101 . V_105 [ 7 ] . V_103 = F_18 ( 7 ) ;
V_101 . V_105 [ 7 ] . V_104 = F_24 ( 7 ) ;
V_101 . V_105 [ 8 ] . V_103 = F_18 ( 8 ) ;
V_101 . V_105 [ 8 ] . V_104 = F_24 ( 8 ) ;
V_101 . V_105 [ 9 ] . V_103 = F_18 ( 9 ) ;
V_101 . V_105 [ 9 ] . V_104 = F_24 ( 9 ) ;
V_101 . V_105 [ 10 ] . V_103 = F_18 ( 10 ) ;
V_101 . V_105 [ 10 ] . V_104 = F_24 ( 10 ) ;
V_101 . V_105 [ 11 ] . V_103 = F_18 ( 11 ) ;
V_101 . V_105 [ 11 ] . V_104 = F_24 ( 11 ) ;
V_101 . V_105 [ 12 ] . V_103 = F_18 ( 12 ) ;
V_101 . V_105 [ 12 ] . V_104 = F_24 ( 12 ) ;
V_101 . V_105 [ 13 ] . V_103 = F_18 ( 13 ) ;
V_101 . V_105 [ 13 ] . V_104 = F_24 ( 13 ) ;
V_101 . V_105 [ 14 ] . V_103 = F_18 ( 14 ) ;
V_101 . V_105 [ 14 ] . V_104 = F_24 ( 14 ) ;
V_101 . V_105 [ 15 ] . V_103 = F_18 ( 15 ) ;
V_101 . V_105 [ 15 ] . V_104 = F_24 ( 15 ) ;
#ifdef F_16
do {
struct V_106 * V_42 ;
int V_7 ;
asm volatile("movsg tplr,%0" : "=r"(__debug_mmu.regs.tplr));
asm volatile("movsg tppr,%0" : "=r"(__debug_mmu.regs.tppr));
asm volatile("movsg tpxr,%0" : "=r"(__debug_mmu.regs.tpxr));
asm volatile("movsg cxnr,%0" : "=r"(__debug_mmu.regs.cxnr));
V_42 = V_101 . V_107 ;
asm volatile("movgs %0,tpxr" :: "r"(0 << TPXR_WAY_SHIFT));
for ( V_7 = 0 ; V_7 < 64 ; V_7 ++ ) {
asm volatile("tlbpr %0,gr0,#1,#0" :: "r"(loop << PAGE_SHIFT));
asm volatile("movsg tplr,%0" : "=r"(p->L));
asm volatile("movsg tppr,%0" : "=r"(p->P));
V_42 ++ ;
}
asm volatile("movgs %0,tpxr" :: "r"(1 << TPXR_WAY_SHIFT));
for ( V_7 = 0 ; V_7 < 64 ; V_7 ++ ) {
asm volatile("tlbpr %0,gr0,#1,#0" :: "r"(loop << PAGE_SHIFT));
asm volatile("movsg tplr,%0" : "=r"(p->L));
asm volatile("movsg tppr,%0" : "=r"(p->P));
V_42 ++ ;
}
asm volatile("movgs %0,tplr" :: "r"(__debug_mmu.regs.tplr));
asm volatile("movgs %0,tppr" :: "r"(__debug_mmu.regs.tppr));
asm volatile("movgs %0,tpxr" :: "r"(__debug_mmu.regs.tpxr));
} while( 0 );
#endif
}
static void F_59 ( void )
{
if ( strcmp ( V_108 , L_30 ) == 0 ) {
sprintf ( V_109 , L_31 ) ;
return;
}
if ( strcmp ( V_108 , L_32 ) == 0 ) {
sprintf ( V_109 , L_33 ) ;
return;
}
if ( strcmp ( V_108 , L_34 ) == 0 ) {
sprintf ( V_109 , L_35 ) ;
return;
}
if ( strcmp ( V_108 , L_36 ) == 0 ) {
sprintf ( V_109 , L_37 ) ;
return;
}
if ( strcmp ( V_108 , L_38 ) == 0 ) {
sprintf ( V_109 , L_39 ,
sizeof( V_108 ) ) ;
return;
}
F_4 ( V_109 , L_40 ) ;
}
void F_60 ( int V_110 )
{
unsigned long V_36 , V_111 , V_7 , V_83 , V_112 , V_113 , V_114 ;
T_6 V_115 ;
char * V_17 ;
int V_116 = 0 ;
F_61 ( 0x5000 ) ;
if ( V_110 < 0 ) {
#ifndef F_62
return;
#else
V_110 = V_117 ;
#endif
}
F_63 ( & V_118 -> V_119 ) ;
#if 0
gdbstub_printk("--> gdbstub() %08x %p %08x %08x\n",
__debug_frame->pc,
__debug_frame,
__debug_regs->brr,
__debug_regs->bpsr);
#endif
F_61 ( 0x5001 ) ;
V_112 = ( unsigned long ) V_120 ;
V_113 = ( unsigned long ) V_121 ;
V_114 = V_90 -> V_91 & ~ 15 ;
if ( V_114 == V_112 + V_122 ||
V_114 == V_113 + V_122
) {
asm volatile("movsg pcsr,%0" : "=r"(__debug_frame->pc));
V_90 -> V_93 |= V_123 ;
V_90 -> V_93 &= ~ V_94 ;
if ( V_90 -> V_93 & V_124 )
V_90 -> V_93 |= V_94 ;
V_100 . V_38 = ( V_90 -> V_56 & V_125 ) << 12 ;
V_100 . V_38 |= V_126 ;
V_110 = V_117 ;
}
if ( V_114 == V_112 + V_127 ||
V_114 == V_113 + V_127
) {
asm volatile("movgs %0,timerd" :: "r"(10000000));
asm volatile("movsg pcsr,%0" : "=r"(__debug_frame->pc));
V_90 -> V_93 |= V_123 ;
V_90 -> V_93 &= ~ V_94 ;
if ( V_90 -> V_93 & V_124 )
V_90 -> V_93 |= V_94 ;
V_100 . V_38 = ( V_90 -> V_56 & V_125 ) << 12 ;
V_100 . V_38 |= V_126 ;
V_110 = V_128 ;
}
F_61 ( 0x5002 ) ;
if ( V_100 . V_38 & V_129 )
F_52 () ;
F_61 ( 0x5003 ) ;
if ( V_90 -> V_91 == ( unsigned long ) V_130 + 4 ) {
F_40 ( (struct V_40 * ) V_90 -> V_131 ,
( const char * ) V_90 -> V_132 ,
( unsigned ) V_90 -> V_133 ) ;
goto V_134;
}
if ( V_16 ) {
V_110 = V_117 ;
goto V_135;
}
if ( ! V_110 )
V_110 = F_45 ( V_100 . V_38 ) ;
F_61 ( 0x5004 ) ;
if ( V_110 != V_117 && V_110 != V_136 && V_110 != V_137 ) {
static const char V_138 [] = L_41 ;
static const char V_139 [] = L_42 ;
unsigned long V_38 = V_100 . V_38 ;
char V_140 ;
V_17 = V_109 ;
* V_17 ++ = 'O' ;
V_17 = F_41 ( V_138 , V_17 , sizeof( V_138 ) - 1 , 0 ) ;
V_140 = F_11 ( V_38 >> 24 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_12 ( V_38 >> 24 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_11 ( V_38 >> 16 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_12 ( V_38 >> 16 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_11 ( V_38 >> 8 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_12 ( V_38 >> 8 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_11 ( V_38 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_140 = F_12 ( V_38 ) ;
V_17 = F_43 ( V_17 , V_140 ) ;
V_17 = F_41 ( V_139 , V_17 , sizeof( V_139 ) - 1 , 0 ) ;
* V_17 = 0 ;
F_10 ( V_109 ) ;
}
F_61 ( 0x5005 ) ;
V_17 = V_109 ;
* V_17 ++ = 'T' ;
V_17 = F_43 ( V_17 , V_110 ) ;
V_17 = F_43 ( V_17 , V_141 ) ;
* V_17 ++ = ':' ;
V_17 = F_41 ( & V_90 -> V_91 , V_17 , 4 , 0 ) ;
* V_17 ++ = ';' ;
V_17 = F_43 ( V_17 , V_142 ) ;
* V_17 ++ = ':' ;
V_17 = F_41 ( & V_90 -> V_143 , V_17 , 4 , 0 ) ;
* V_17 ++ = ';' ;
V_17 = F_43 ( V_17 , V_144 ) ;
* V_17 ++ = ':' ;
V_17 = F_41 ( & V_90 -> V_145 , V_17 , 4 , 0 ) ;
* V_17 ++ = ';' ;
* V_17 ++ = 0 ;
F_10 ( V_109 ) ;
F_61 ( 0x5006 ) ;
V_135:
F_56 () ;
while ( 1 ) {
V_109 [ 0 ] = 0 ;
F_61 ( 0x5007 ) ;
F_6 ( V_108 ) ;
F_61 ( 0x5600 | V_108 [ 0 ] ) ;
switch ( V_108 [ 0 ] ) {
case '?' :
V_109 [ 0 ] = 'S' ;
V_109 [ 1 ] = F_11 ( V_110 ) ;
V_109 [ 2 ] = F_12 ( V_110 ) ;
V_109 [ 3 ] = 0 ;
break;
case 'd' :
break;
case 'g' :
V_115 = 0 ;
V_17 = V_109 ;
V_17 = F_41 ( & V_115 , V_17 , 4 , 0 ) ;
for ( V_7 = 1 ; V_7 <= 27 ; V_7 ++ )
V_17 = F_41 ( & V_146 -> V_12 . V_147 [ V_7 ] , V_17 , 4 , 0 ) ;
V_112 = ( unsigned long ) V_148 ;
V_17 = F_41 ( & V_112 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_146 -> V_12 . V_147 [ 29 ] , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_146 -> V_12 . V_147 [ 30 ] , V_17 , 4 , 0 ) ;
#ifdef F_16
V_17 = F_41 ( & V_146 -> V_12 . V_147 [ 31 ] , V_17 , 4 , 0 ) ;
#else
V_112 = ( unsigned long ) V_90 ;
V_17 = F_41 ( & V_112 , V_17 , 4 , 0 ) ;
#endif
for ( V_7 = 32 ; V_7 <= 63 ; V_7 ++ )
V_17 = F_41 ( & V_146 -> V_12 . V_147 [ V_7 ] , V_17 , 4 , 0 ) ;
for ( V_7 = 0 ; V_7 <= 63 ; V_7 ++ )
V_17 = F_41 ( & V_146 -> V_149 . V_150 [ V_7 ] , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_91 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_93 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_151 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_152 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_115 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_115 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_115 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_56 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_100 . V_38 , V_17 , 4 , 0 ) ;
asm volatile("movsg dbar0,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg dbar1,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg dbar2,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg dbar3,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg scr0,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg scr1,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg scr2,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
asm volatile("movsg scr3,%0" : "=r"(dbar));
V_17 = F_41 ( & V_83 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_153 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_154 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_155 , V_17 , 8 , 0 ) ;
V_17 = F_41 ( & V_146 -> V_149 . V_156 [ 0 ] , V_17 , 4 , 0 ) ;
for ( V_7 = 0 ; V_7 <= 7 ; V_7 ++ )
V_17 = F_41 ( & V_146 -> V_149 . V_157 [ V_7 ] , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_146 -> V_149 . V_158 , V_17 , 8 , 0 ) ;
for ( V_7 = 0 ; V_7 <= 1 ; V_7 ++ )
V_17 = F_41 ( & V_146 -> V_149 . V_159 [ V_7 ] , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_160 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_90 -> V_161 , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_146 -> V_149 . V_162 [ 0 ] , V_17 , 4 , 0 ) ;
V_17 = F_41 ( & V_146 -> V_149 . V_162 [ 1 ] , V_17 , 4 , 0 ) ;
break;
case 'G' :
V_17 = & V_108 [ 1 ] ;
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
for ( V_7 = 1 ; V_7 <= 27 ; V_7 ++ )
V_17 = F_44 ( V_17 , & V_146 -> V_12 . V_147 [ V_7 ] , 4 ) ;
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
V_148 = (struct V_163 * ) V_112 ;
V_17 = F_44 ( V_17 , & V_90 -> V_164 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_165 , 4 ) ;
#ifdef F_16
V_17 = F_44 ( V_17 , & V_90 -> V_166 , 4 ) ;
#else
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
#endif
for ( V_7 = 32 ; V_7 <= 63 ; V_7 ++ )
V_17 = F_44 ( V_17 , & V_146 -> V_12 . V_147 [ V_7 ] , 4 ) ;
for ( V_7 = 0 ; V_7 <= 63 ; V_7 ++ )
V_17 = F_41 ( & V_146 -> V_149 . V_150 [ V_7 ] , V_17 , 4 , 0 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_91 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_93 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_151 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_152 , 4 ) ;
for ( V_7 = 132 ; V_7 <= 140 ; V_7 ++ )
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
asm volatile("movgs %0,scr0" :: "r"(temp));
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
asm volatile("movgs %0,scr1" :: "r"(temp));
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
asm volatile("movgs %0,scr2" :: "r"(temp));
V_17 = F_44 ( V_17 , & V_112 , 4 ) ;
asm volatile("movgs %0,scr3" :: "r"(temp));
V_17 = F_44 ( V_17 , & V_90 -> V_153 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_154 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_155 , 8 ) ;
V_17 = F_44 ( V_17 , & V_146 -> V_149 . V_156 [ 0 ] , 4 ) ;
for ( V_7 = 0 ; V_7 <= 7 ; V_7 ++ )
V_17 = F_44 ( V_17 , & V_146 -> V_149 . V_157 [ V_7 ] , 4 ) ;
V_17 = F_44 ( V_17 , & V_146 -> V_149 . V_158 , 8 ) ;
for ( V_7 = 0 ; V_7 <= 1 ; V_7 ++ )
V_17 = F_44 ( V_17 , & V_146 -> V_149 . V_159 [ V_7 ] , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_160 , 4 ) ;
V_17 = F_44 ( V_17 , & V_90 -> V_161 , 4 ) ;
V_17 = F_44 ( V_17 , & V_146 -> V_149 . V_162 [ 0 ] , 4 ) ;
V_17 = F_44 ( V_17 , & V_146 -> V_149 . V_162 [ 1 ] , 4 ) ;
F_4 ( V_109 , L_37 ) ;
break;
case 'm' :
V_17 = & V_108 [ 1 ] ;
if ( F_14 ( & V_17 , & V_36 ) &&
* V_17 ++ == ',' &&
F_14 ( & V_17 , & V_111 )
) {
if ( F_41 ( ( char * ) V_36 , V_109 , V_111 , 1 ) )
break;
F_4 ( V_109 , L_43 ) ;
}
else {
F_4 ( V_109 , L_40 ) ;
}
break;
case 'M' :
V_17 = & V_108 [ 1 ] ;
if ( F_14 ( & V_17 , & V_36 ) &&
* V_17 ++ == ',' &&
F_14 ( & V_17 , & V_111 ) &&
* V_17 ++ == ':'
) {
if ( F_44 ( V_17 , ( char * ) V_36 , V_111 ) ) {
F_4 ( V_109 , L_37 ) ;
}
else {
F_4 ( V_109 , L_43 ) ;
}
}
else
F_4 ( V_109 , L_44 ) ;
V_116 = 1 ;
break;
case 'p' :
break;
case 'P' :
V_17 = & V_108 [ 1 ] ;
if ( ! F_14 ( & V_17 , & V_36 ) ||
* V_17 ++ != '=' ||
! F_14 ( & V_17 , & V_112 )
) {
F_4 ( V_109 , L_40 ) ;
break;
}
V_113 = 1 ;
switch ( V_36 ) {
case F_64 ( 0 ) :
break;
case F_64 ( 1 ) ... F_64 ( 63 ) :
V_146 -> V_12 . V_147 [ V_36 - F_64 ( 0 ) ] = V_112 ;
break;
case F_65 ( 0 ) ... F_65 ( 63 ) :
V_146 -> V_149 . V_150 [ V_36 - F_65 ( 0 ) ] = V_112 ;
break;
case V_141 :
V_146 -> V_12 . V_91 = V_112 ;
break;
case V_167 :
V_146 -> V_12 . V_93 = V_112 ;
break;
case V_168 :
V_146 -> V_12 . V_151 = V_112 ;
break;
case V_169 :
V_146 -> V_12 . V_152 = V_112 ;
break;
case V_170 :
V_100 . V_38 = V_112 ;
break;
case V_171 :
V_146 -> V_12 . V_153 = V_112 ;
break;
case V_172 :
V_146 -> V_12 . V_154 = V_112 ;
break;
case V_173 :
V_146 -> V_149 . V_156 [ 0 ] = V_112 ;
break;
case F_66 ( 0 ) ... F_66 ( 7 ) :
V_146 -> V_149 . V_157 [ V_36 - F_66 ( 0 ) ] = V_112 ;
break;
case F_67 ( 0 ) :
* ( T_6 * ) & V_146 -> V_149 . V_158 [ 0 ] = V_112 ;
break;
case F_67 ( 4 ) :
* ( T_6 * ) & V_146 -> V_149 . V_158 [ 4 ] = V_112 ;
break;
case F_68 ( 0 ) ... F_68 ( 1 ) :
V_146 -> V_149 . V_159 [ V_36 - F_68 ( 0 ) ] = V_112 ;
break;
case F_69 ( 0 ) ... F_69 ( 1 ) :
V_146 -> V_12 . V_174 [ V_36 - F_69 ( 0 ) ] = V_112 ;
break;
case F_70 ( 0 ) ... F_70 ( 1 ) :
V_146 -> V_149 . V_162 [ V_36 - F_70 ( 0 ) ] = V_112 ;
break;
default:
V_113 = 0 ;
break;
}
if ( V_113 ) {
F_4 ( V_109 , L_37 ) ;
}
else {
F_4 ( V_109 , L_44 ) ;
}
break;
case 'c' :
V_17 = & V_108 [ 1 ] ;
if ( F_14 ( & V_17 , & V_36 ) )
V_90 -> V_91 = V_36 ;
goto V_134;
case 'k' :
goto V_134;
case 'D' :
F_4 ( V_109 , L_37 ) ;
break;
case 'r' :
break;
case 's' :
V_74 -> V_75 |= V_175 ;
V_100 . V_75 |= V_175 ;
goto V_134;
case 'v' :
if ( strcmp ( V_108 , L_45 ) == 0 ) {
V_109 [ 0 ] = 0 ;
break;
}
goto V_176;
case 'b' :
V_17 = & V_108 [ 1 ] ;
if ( ! F_14 ( & V_17 , & V_112 ) ) {
F_4 ( V_109 , L_46 ) ;
break;
}
if ( V_112 ) {
F_10 ( L_37 ) ;
F_71 ( V_112 ) ;
}
break;
case 'Z' :
V_17 = & V_108 [ 1 ] ;
if ( ! F_14 ( & V_17 , & V_112 ) || * V_17 ++ != ',' ||
! F_14 ( & V_17 , & V_36 ) || * V_17 ++ != ',' ||
! F_14 ( & V_17 , & V_111 )
) {
F_4 ( V_109 , L_40 ) ;
break;
}
if ( V_112 >= 5 ) {
F_4 ( V_109 , L_43 ) ;
break;
}
if ( F_46 ( V_112 , V_36 , V_111 ) < 0 ) {
F_4 ( V_109 , L_43 ) ;
break;
}
if ( V_112 == 0 )
V_116 = 1 ;
F_4 ( V_109 , L_37 ) ;
break;
case 'z' :
V_17 = & V_108 [ 1 ] ;
if ( ! F_14 ( & V_17 , & V_112 ) || * V_17 ++ != ',' ||
! F_14 ( & V_17 , & V_36 ) || * V_17 ++ != ',' ||
! F_14 ( & V_17 , & V_111 )
) {
F_4 ( V_109 , L_40 ) ;
break;
}
if ( V_112 >= 5 ) {
F_4 ( V_109 , L_43 ) ;
break;
}
if ( F_47 ( V_112 , V_36 , V_111 ) < 0 ) {
F_4 ( V_109 , L_43 ) ;
break;
}
if ( V_112 == 0 )
V_116 = 1 ;
F_4 ( V_109 , L_37 ) ;
break;
case 'H' :
F_4 ( V_109 , L_37 ) ;
break;
case 'q' :
F_59 () ;
break;
default:
V_176:
F_8 ( L_47 , V_108 ) ;
F_4 ( V_109 , L_40 ) ;
break;
}
F_61 ( 0x5009 ) ;
F_10 ( V_109 ) ;
}
V_134:
F_72 ( & V_118 -> V_119 ) ;
if ( V_116 )
F_5 () ;
F_61 ( 0x5666 ) ;
}
void T_10 F_73 ( void )
{
#ifdef F_62
unsigned char V_1 ;
int V_13 ;
#endif
F_2 ( L_48 , V_177 ) ;
F_74 () ;
F_8 ( L_5 ) ;
F_9 ( '+' ) ;
#ifdef F_62
F_2 ( L_49 ) ;
do { F_7 ( & V_1 , 0 ) ; } while ( V_1 != '$' );
do { F_7 ( & V_1 , 0 ) ; } while ( V_1 != '#' );
do { V_13 = F_7 ( & V_1 , 0 ) ; } while ( V_13 != 0 );
do { V_13 = F_7 ( & V_1 , 0 ) ; } while ( V_13 != 0 );
F_8 ( L_2 ) ;
F_9 ( '-' ) ;
#else
F_2 ( L_50 ) ;
#endif
#if 0
ptr = output_buffer;
*ptr++ = 'O';
ptr = mem2hex(gdbstub_banner, ptr, sizeof(gdbstub_banner) - 1, 0);
gdbstub_send_packet(output_buffer);
#endif
#if F_75 ( V_178 ) && F_75 ( F_62 )
F_76 ( & V_179 ) ;
#endif
}
static int T_10 F_77 ( void )
{
F_54 ( L_51 ) ;
F_76 ( & V_179 ) ;
return 0 ;
}
void F_78 ( int V_180 )
{
unsigned char V_9 ;
int V_11 ;
unsigned char V_1 ;
sprintf ( V_109 , L_52 , V_180 & 0xff ) ;
F_9 ( '$' ) ;
V_9 = 0 ;
V_11 = 0 ;
while ( ( V_1 = V_109 [ V_11 ] ) != 0 ) {
F_9 ( V_1 ) ;
V_9 += V_1 ;
V_11 += 1 ;
}
F_9 ( '#' ) ;
F_9 ( F_11 ( V_9 ) ) ;
F_9 ( F_12 ( V_9 ) ) ;
F_9 ( '-' ) ;
F_79 () ;
}
static void * malloc ( T_11 V_181 )
{
return F_80 ( V_181 , V_182 ) ;
}
static void free ( void * V_42 )
{
F_81 ( V_42 ) ;
}
static T_6 F_82 ( void )
{
return F_83 ( 0 ) ;
}
static T_6 F_84 ( T_6 V_183 )
{
F_85 ( 0 , V_183 ) ;
return F_83 ( 0 ) ;
}
