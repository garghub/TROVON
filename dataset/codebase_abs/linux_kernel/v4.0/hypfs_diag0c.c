static void F_1 ( struct V_1 * V_2 )
{
asm volatile (
#ifdef F_2
" sam31\n"
" diag %0,%0,0x0c\n"
" sam64\n"
#else
" diag %0,%0,0x0c\n"
#endif
:
: "a" (entry)
: "memory");
}
static void F_3 ( void * V_3 )
{
F_1 ( ( ( void * * ) V_3 ) [ F_4 () ] ) ;
}
static void * F_5 ( unsigned int * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 ;
void * * V_10 ;
F_6 () ;
V_7 = F_7 () ;
V_10 = F_8 ( sizeof( * V_10 ) * F_9 () , V_11 ) ;
if ( ! V_10 )
goto V_12;
V_6 = F_10 ( sizeof( struct V_13 ) +
V_7 * sizeof( struct V_1 ) ,
V_11 | V_14 ) ;
if ( ! V_6 )
goto V_15;
V_9 = 0 ;
F_11 (cpu) {
V_6 -> V_2 [ V_9 ] . V_8 = V_8 ;
V_10 [ V_8 ] = & V_6 -> V_2 [ V_9 ++ ] ;
}
F_12 ( F_3 , V_10 , 1 ) ;
* V_4 = V_7 ;
F_13 ( V_10 ) ;
F_14 () ;
return V_6 ;
V_15:
F_13 ( V_10 ) ;
V_12:
F_14 () ;
return F_15 ( - V_16 ) ;
}
static void F_16 ( const void * V_3 )
{
F_13 ( V_3 ) ;
}
static int F_17 ( void * * V_3 , void * * V_17 , T_1 * V_18 )
{
struct V_5 * V_6 ;
unsigned int V_4 ;
V_6 = F_5 ( & V_4 ) ;
if ( F_18 ( V_6 ) )
return F_19 ( V_6 ) ;
memset ( & V_6 -> V_19 , 0 , sizeof( V_6 -> V_19 ) ) ;
F_20 ( V_6 -> V_19 . V_20 ) ;
V_6 -> V_19 . V_21 = V_4 * sizeof( struct V_1 ) ;
V_6 -> V_19 . V_22 = V_23 ;
V_6 -> V_19 . V_4 = V_4 ;
* V_3 = V_6 ;
* V_17 = V_6 ;
* V_18 = V_6 -> V_19 . V_21 + sizeof( struct V_13 ) ;
return 0 ;
}
int T_2 F_21 ( void )
{
if ( ! V_24 )
return 0 ;
return F_22 ( & V_25 ) ;
}
void F_23 ( void )
{
if ( ! V_24 )
return;
F_24 ( & V_25 ) ;
}
