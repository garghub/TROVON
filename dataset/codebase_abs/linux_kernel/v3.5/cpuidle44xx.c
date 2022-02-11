static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_8 [ V_5 ] ;
T_1 V_9 ;
int V_10 = F_2 () ;
F_3 () ;
V_9 = F_4 ( V_11 ) ;
if ( V_9 != V_12 ) {
V_5 = V_4 -> V_13 ;
V_7 = & V_8 [ V_5 ] ;
}
if ( V_5 > 0 )
F_5 ( V_14 , & V_10 ) ;
if ( V_7 -> V_15 == V_12 )
F_6 () ;
F_7 ( V_16 , V_7 -> V_17 ) ;
F_8 ( V_16 , V_7 -> V_18 ) ;
if ( ( V_7 -> V_18 == V_19 ) &&
( V_7 -> V_17 == V_12 ) )
F_9 () ;
F_10 ( V_2 -> V_20 , V_7 -> V_15 ) ;
if ( F_11 ( V_21 ) == V_12 )
F_12 () ;
if ( F_13 () )
F_14 () ;
if ( V_5 > 0 )
F_5 ( V_22 , & V_10 ) ;
F_15 () ;
return V_5 ;
}
int T_2 F_16 ( void )
{
struct V_1 * V_2 ;
unsigned int V_10 = 0 ;
V_16 = F_17 ( L_1 ) ;
V_21 = F_17 ( L_2 ) ;
V_11 = F_17 ( L_3 ) ;
if ( ( ! V_16 ) || ( ! V_21 ) || ( ! V_11 ) )
return - V_23 ;
V_2 = & F_18 ( V_24 , V_10 ) ;
V_2 -> V_20 = V_10 ;
F_19 ( & V_25 ) ;
if ( F_20 ( V_2 ) ) {
F_21 ( L_4 , V_26 ) ;
return - V_27 ;
}
return 0 ;
}
int T_2 F_16 ( void )
{
return 0 ;
}
