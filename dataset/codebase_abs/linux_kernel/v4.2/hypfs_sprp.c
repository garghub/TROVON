static unsigned long F_1 ( void * V_1 , unsigned long V_2 )
{
register unsigned long T_1 V_3 ( L_1 ) = ( unsigned long ) V_1 ;
register unsigned long T_2 V_3 ( L_2 ) ;
register unsigned long T_3 V_3 ( L_3 ) = V_2 ;
asm volatile("diag %1,%2,0x304\n"
: "=d" (_rc) : "d" (_data), "d" (_cmd) : "memory");
return T_2 ;
}
static void F_2 ( const void * V_1 )
{
F_3 ( ( unsigned long ) V_1 ) ;
}
static int F_4 ( void * * V_4 , void * * V_5 , T_4 * V_6 )
{
unsigned long V_7 ;
void * V_1 ;
V_1 = ( void * ) F_5 ( V_8 ) ;
if ( ! V_1 )
return - V_9 ;
V_7 = F_1 ( V_1 , V_10 ) ;
if ( V_7 != 1 ) {
* V_4 = * V_5 = NULL ;
* V_6 = 0 ;
F_3 ( ( unsigned long ) V_1 ) ;
return - V_11 ;
}
* V_4 = * V_5 = V_1 ;
* V_6 = V_12 ;
return 0 ;
}
static int F_6 ( void T_5 * V_13 )
{
struct V_14 V_15 ;
unsigned long V_2 ;
void T_5 * V_16 ;
void * V_1 ;
int V_7 ;
if ( F_7 ( & V_15 , V_13 , sizeof( V_15 ) ) )
return - V_17 ;
if ( ( V_15 . args [ 0 ] >> 8 ) != 0 || V_15 . args [ 1 ] > V_18 )
return - V_19 ;
V_1 = ( void * ) F_5 ( V_8 | V_20 ) ;
if ( ! V_1 )
return - V_9 ;
V_16 = ( void T_5 * ) ( unsigned long ) V_15 . V_1 ;
if ( V_15 . args [ 1 ] == V_21 ||
V_15 . args [ 1 ] == V_22 )
if ( F_7 ( V_1 , V_16 , V_12 ) ) {
V_7 = - V_17 ;
goto V_23;
}
V_2 = * ( unsigned long * ) & V_15 . args [ 0 ] ;
V_15 . V_7 = F_1 ( V_1 , V_2 ) ;
if ( V_15 . args [ 1 ] == V_10 )
if ( F_8 ( V_16 , V_1 , V_12 ) ) {
V_7 = - V_17 ;
goto V_23;
}
V_7 = F_8 ( V_13 , & V_15 , sizeof( V_15 ) ) ? - V_17 : 0 ;
V_23:
F_3 ( ( unsigned long ) V_1 ) ;
return V_7 ;
}
static long F_9 ( struct V_24 * V_24 , unsigned int V_2 ,
unsigned long V_25 )
{
void T_5 * V_26 ;
if ( ! F_10 ( V_27 ) )
return - V_28 ;
if ( F_11 () )
V_26 = F_12 ( V_25 ) ;
else
V_26 = ( void T_5 * ) V_25 ;
switch ( V_2 ) {
case V_29 :
return F_6 ( V_26 ) ;
default:
return - V_30 ;
}
return 0 ;
}
int F_13 ( void )
{
if ( ! V_31 . V_32 )
return 0 ;
return F_14 ( & V_33 ) ;
}
void F_15 ( void )
{
if ( ! V_31 . V_32 )
return;
F_16 ( & V_33 ) ;
}
