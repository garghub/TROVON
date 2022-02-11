static void F_1 ( struct V_1 * V_2 )
{
asm volatile (
" sam31\n"
" diag %0,%0,0x0c\n"
" sam64\n"
:
: "a" (entry)
: "memory");
}
static void F_2 ( void * V_3 )
{
F_1 ( ( ( void * * ) V_3 ) [ F_3 () ] ) ;
}
static void * F_4 ( unsigned int * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 , V_8 , V_9 ;
void * * V_10 ;
F_5 () ;
V_7 = F_6 () ;
V_10 = F_7 ( sizeof( * V_10 ) * F_8 () , V_11 ) ;
if ( ! V_10 )
goto V_12;
V_6 = F_9 ( sizeof( struct V_13 ) +
V_7 * sizeof( struct V_1 ) ,
V_11 | V_14 ) ;
if ( ! V_6 )
goto V_15;
V_9 = 0 ;
F_10 (cpu) {
V_6 -> V_2 [ V_9 ] . V_8 = V_8 ;
V_10 [ V_8 ] = & V_6 -> V_2 [ V_9 ++ ] ;
}
F_11 ( F_2 , V_10 , 1 ) ;
* V_4 = V_7 ;
F_12 ( V_10 ) ;
F_13 () ;
return V_6 ;
V_15:
F_12 ( V_10 ) ;
V_12:
F_13 () ;
return F_14 ( - V_16 ) ;
}
static void F_15 ( const void * V_3 )
{
F_12 ( V_3 ) ;
}
static int F_16 ( void * * V_3 , void * * V_17 , T_1 * V_18 )
{
struct V_5 * V_6 ;
unsigned int V_4 ;
V_6 = F_4 ( & V_4 ) ;
if ( F_17 ( V_6 ) )
return F_18 ( V_6 ) ;
memset ( & V_6 -> V_19 , 0 , sizeof( V_6 -> V_19 ) ) ;
F_19 ( V_6 -> V_19 . V_20 ) ;
V_6 -> V_19 . V_21 = V_4 * sizeof( struct V_1 ) ;
V_6 -> V_19 . V_22 = V_23 ;
V_6 -> V_19 . V_4 = V_4 ;
* V_3 = V_6 ;
* V_17 = V_6 ;
* V_18 = V_6 -> V_19 . V_21 + sizeof( struct V_13 ) ;
return 0 ;
}
int T_2 F_20 ( void )
{
if ( ! V_24 )
return 0 ;
return F_21 ( & V_25 ) ;
}
void F_22 ( void )
{
if ( ! V_24 )
return;
F_23 ( & V_25 ) ;
}
