static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
asm volatile (
" sam31\n"
" diag %0,%0,0x0c\n"
" sam64\n"
:
: "a" (entry)
: "memory");
}
static void F_3 ( void * V_4 )
{
F_1 ( ( ( void * * ) V_4 ) [ F_4 () ] ) ;
}
static void * F_5 ( unsigned int * V_5 )
{
struct V_6 * V_7 ;
unsigned int V_8 , V_9 , V_10 ;
void * * V_11 ;
F_6 () ;
V_8 = F_7 () ;
V_11 = F_8 ( sizeof( * V_11 ) * F_9 () , V_12 ) ;
if ( ! V_11 )
goto V_13;
V_7 = F_10 ( sizeof( struct V_14 ) +
V_8 * sizeof( struct V_1 ) ,
V_12 | V_15 ) ;
if ( ! V_7 )
goto V_16;
V_10 = 0 ;
F_11 (cpu) {
V_7 -> V_2 [ V_10 ] . V_9 = V_9 ;
V_11 [ V_9 ] = & V_7 -> V_2 [ V_10 ++ ] ;
}
F_12 ( F_3 , V_11 , 1 ) ;
* V_5 = V_8 ;
F_13 ( V_11 ) ;
F_14 () ;
return V_7 ;
V_16:
F_13 ( V_11 ) ;
V_13:
F_14 () ;
return F_15 ( - V_17 ) ;
}
static void F_16 ( const void * V_4 )
{
F_13 ( V_4 ) ;
}
static int F_17 ( void * * V_4 , void * * V_18 , T_1 * V_19 )
{
struct V_6 * V_7 ;
unsigned int V_5 ;
V_7 = F_5 ( & V_5 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
memset ( & V_7 -> V_20 , 0 , sizeof( V_7 -> V_20 ) ) ;
F_20 ( V_7 -> V_20 . V_21 ) ;
V_7 -> V_20 . V_22 = V_5 * sizeof( struct V_1 ) ;
V_7 -> V_20 . V_23 = V_24 ;
V_7 -> V_20 . V_5 = V_5 ;
* V_4 = V_7 ;
* V_18 = V_7 ;
* V_19 = V_7 -> V_20 . V_22 + sizeof( struct V_14 ) ;
return 0 ;
}
int T_2 F_21 ( void )
{
if ( ! V_25 )
return 0 ;
return F_22 ( & V_26 ) ;
}
void F_23 ( void )
{
if ( ! V_25 )
return;
F_24 ( & V_26 ) ;
}
