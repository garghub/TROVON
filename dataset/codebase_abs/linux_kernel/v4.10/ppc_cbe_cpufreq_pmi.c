int F_1 ( int V_1 , unsigned int V_2 )
{
int V_3 ;
T_1 V_4 ;
#ifdef F_2
long time ;
#endif
V_4 . type = V_5 ;
V_4 . V_6 = F_3 ( V_1 ) ;
V_4 . V_7 = V_2 ;
#ifdef F_2
time = V_8 ;
#endif
F_4 ( V_4 ) ;
#ifdef F_2
time = V_8 - time ;
time = F_5 ( time ) ;
F_6 ( L_1 \
L_2 , time ) ;
#endif
V_3 = V_4 . V_7 ;
F_6 ( L_3 , V_3 ) ;
return V_3 ;
}
static void F_7 ( T_1 V_4 )
{
T_2 V_9 , V_10 ;
F_8 ( V_4 . type != V_5 ) ;
V_9 = V_4 . V_6 ;
V_10 = V_4 . V_7 ;
V_11 [ V_9 ] = V_10 ;
F_6 ( L_4 , V_9 , V_10 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = V_17 -> V_20 ;
T_2 V_9 ;
if ( V_14 == V_21 )
return 0 ;
V_9 = F_3 ( V_17 -> V_1 ) ;
F_6 ( L_5 , V_14 , V_9 ) ;
if ( V_11 [ V_9 ] != 0 ) {
F_6 ( L_6 ,
V_9 , V_11 [ V_9 ] ) ;
F_10 ( V_17 , 0 ,
V_19 [ V_11 [ V_9 ] ] . V_22 ) ;
}
return 0 ;
}
static int T_3 F_11 ( void )
{
V_23 = F_12 ( & V_24 ) == 0 ;
if ( ! V_23 )
return - V_25 ;
F_13 ( & V_26 , V_27 ) ;
return 0 ;
}
