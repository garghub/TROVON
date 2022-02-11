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
if ( V_1 -> V_8 != - 1 )
F_3 ( V_1 -> V_8 , 1 ) ;
}
static int F_4 ( char * * V_9 , int V_10 )
{
struct V_6 V_11 ;
int V_12 ;
V_11 . V_7 = V_10 ;
V_11 . V_8 = V_10 ;
V_12 = F_5 ( F_2 , & V_11 , V_9 ) ;
return V_12 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
int V_13 [ 2 ] , V_12 , V_14 ;
V_14 = F_7 ( V_13 , 1 , 1 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_4 -> V_15 . V_9 , V_13 [ 1 ] ) ;
if ( V_14 < 0 ) {
F_8 ( V_16 L_1 , - V_14 ) ;
goto V_17;
}
V_12 = V_14 ;
V_4 -> V_18 = V_13 [ 1 ] ;
V_4 -> V_19 . V_20 = 0 ;
V_4 -> V_19 . V_21 = 0 ;
V_4 -> V_12 = V_14 ;
return V_13 [ 0 ] ;
V_17:
F_9 ( V_13 [ 0 ] ) ;
F_9 ( V_13 [ 1 ] ) ;
return V_14 ;
}
static void F_10 ( int V_10 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
int V_14 ;
F_9 ( V_10 ) ;
F_9 ( V_4 -> V_18 ) ;
V_4 -> V_18 = - 1 ;
if ( V_4 -> V_12 < 1 ) {
F_8 ( V_16 L_2
L_3 ) ;
return;
}
#if 0
if (kill(pri->pid, SIGHUP)<0) {
printk(UM_KERN_ERR "slirp_close: sending hangup to %d failed "
"(%d)\n", pri->pid, errno);
}
#endif
V_14 = F_11 ( V_4 -> V_12 ) ;
if ( V_14 < 0 )
return;
V_4 -> V_12 = - 1 ;
}
int F_12 ( int V_10 , void * V_22 , int V_23 , struct V_3 * V_4 )
{
return F_13 ( V_10 , V_22 , V_23 , & V_4 -> V_19 ) ;
}
int F_14 ( int V_10 , void * V_22 , int V_23 , struct V_3 * V_4 )
{
return F_15 ( V_10 , V_22 , V_23 , & V_4 -> V_19 ) ;
}
