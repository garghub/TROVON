static int F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static void F_2 ( void * V_5 )
{
struct V_6 * V_1 = V_5 ;
if ( V_1 -> V_7 != - 1 )
F_3 ( V_1 -> V_7 , 0 ) ;
if ( V_1 -> stdout != - 1 )
F_3 ( V_1 -> stdout , 1 ) ;
}
static int F_4 ( char * * V_8 , int V_9 )
{
struct V_6 V_10 ;
int V_11 ;
V_10 . V_7 = V_9 ;
V_10 . stdout = V_9 ;
V_11 = F_5 ( F_2 , & V_10 , V_8 ) ;
return V_11 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
int V_12 [ 2 ] , V_11 , V_13 ;
V_13 = F_7 ( V_12 , 1 , 1 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_4 -> V_14 . V_8 , V_12 [ 1 ] ) ;
if ( V_13 < 0 ) {
F_8 ( V_15 L_1 , - V_13 ) ;
goto V_16;
}
V_11 = V_13 ;
V_4 -> V_17 = V_12 [ 1 ] ;
V_4 -> V_18 . V_19 = 0 ;
V_4 -> V_18 . V_20 = 0 ;
V_4 -> V_11 = V_13 ;
return V_12 [ 0 ] ;
V_16:
F_9 ( V_12 [ 0 ] ) ;
F_9 ( V_12 [ 1 ] ) ;
return V_13 ;
}
static void F_10 ( int V_9 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
int V_13 ;
F_9 ( V_9 ) ;
F_9 ( V_4 -> V_17 ) ;
V_4 -> V_17 = - 1 ;
if ( V_4 -> V_11 < 1 ) {
F_8 ( V_15 L_2
L_3 ) ;
return;
}
#if 0
if (kill(pri->pid, SIGHUP)<0) {
printk(UM_KERN_ERR "slirp_close: sending hangup to %d failed "
"(%d)\n", pri->pid, errno);
}
#endif
V_13 = F_11 ( V_4 -> V_11 ) ;
if ( V_13 < 0 )
return;
V_4 -> V_11 = - 1 ;
}
int F_12 ( int V_9 , void * V_21 , int V_22 , struct V_3 * V_4 )
{
return F_13 ( V_9 , V_21 , V_22 , & V_4 -> V_18 ) ;
}
int F_14 ( int V_9 , void * V_21 , int V_22 , struct V_3 * V_4 )
{
return F_15 ( V_9 , V_21 , V_22 , & V_4 -> V_18 ) ;
}
