static inline unsigned long F_1 ( void * V_1 , unsigned long V_2 )
{
register unsigned long T_1 V_3 ( L_1 ) = ( unsigned long ) V_1 ;
register unsigned long T_2 V_3 ( L_2 ) ;
register unsigned long T_3 V_3 ( L_3 ) = V_2 ;
asm volatile("diag %1,%2,0x304\n"
: "=d" (_rc) : "d" (_data), "d" (_cmd) : "memory");
return T_2 ;
}
static unsigned long F_2 ( void * V_1 , unsigned long V_2 )
{
F_3 ( V_4 ) ;
return F_1 ( V_1 , V_2 ) ;
}
static void F_4 ( const void * V_1 )
{
F_5 ( ( unsigned long ) V_1 ) ;
}
static int F_6 ( void * * V_5 , void * * V_6 , T_4 * V_7 )
{
unsigned long V_8 ;
void * V_1 ;
V_1 = ( void * ) F_7 ( V_9 ) ;
if ( ! V_1 )
return - V_10 ;
V_8 = F_2 ( V_1 , V_11 ) ;
if ( V_8 != 1 ) {
* V_5 = * V_6 = NULL ;
* V_7 = 0 ;
F_5 ( ( unsigned long ) V_1 ) ;
return - V_12 ;
}
* V_5 = * V_6 = V_1 ;
* V_7 = V_13 ;
return 0 ;
}
static int F_8 ( void T_5 * V_14 )
{
struct V_15 V_16 ;
unsigned long V_2 ;
void T_5 * V_17 ;
void * V_1 ;
int V_8 ;
if ( F_9 ( & V_16 , V_14 , sizeof( V_16 ) ) )
return - V_18 ;
if ( ( V_16 . args [ 0 ] >> 8 ) != 0 || V_16 . args [ 1 ] > V_19 )
return - V_20 ;
V_1 = ( void * ) F_7 ( V_9 | V_21 ) ;
if ( ! V_1 )
return - V_10 ;
V_17 = ( void T_5 * ) ( unsigned long ) V_16 . V_1 ;
if ( V_16 . args [ 1 ] == V_22 ||
V_16 . args [ 1 ] == V_23 )
if ( F_9 ( V_1 , V_17 , V_13 ) ) {
V_8 = - V_18 ;
goto V_24;
}
V_2 = * ( unsigned long * ) & V_16 . args [ 0 ] ;
V_16 . V_8 = F_2 ( V_1 , V_2 ) ;
if ( V_16 . args [ 1 ] == V_11 )
if ( F_10 ( V_17 , V_1 , V_13 ) ) {
V_8 = - V_18 ;
goto V_24;
}
V_8 = F_10 ( V_14 , & V_16 , sizeof( V_16 ) ) ? - V_18 : 0 ;
V_24:
F_5 ( ( unsigned long ) V_1 ) ;
return V_8 ;
}
static long F_11 ( struct V_25 * V_25 , unsigned int V_2 ,
unsigned long V_26 )
{
void T_5 * V_27 ;
if ( ! F_12 ( V_28 ) )
return - V_29 ;
if ( F_13 () )
V_27 = F_14 ( V_26 ) ;
else
V_27 = ( void T_5 * ) V_26 ;
switch ( V_2 ) {
case V_30 :
return F_8 ( V_27 ) ;
default:
return - V_31 ;
}
return 0 ;
}
int F_15 ( void )
{
if ( ! V_32 . V_33 )
return 0 ;
return F_16 ( & V_34 ) ;
}
void F_17 ( void )
{
if ( ! V_32 . V_33 )
return;
F_18 ( & V_34 ) ;
}
