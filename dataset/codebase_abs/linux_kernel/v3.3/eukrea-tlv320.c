static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 |
V_14 ) ;
if ( V_11 ) {
F_3 ( L_1 , V_15 ) ;
return V_11 ;
}
V_11 = F_2 ( V_9 , V_12 |
V_13 |
V_14 ) ;
if ( V_11 ) {
F_3 ( L_2 , V_15 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 ,
V_16 , V_17 ) ;
if ( V_11 ) {
F_3 ( L_3 , V_15 ) ;
return V_11 ;
}
F_5 ( V_10 , 0xffffffc , 0xffffffc , 2 , 0 ) ;
V_11 = F_4 ( V_10 , V_18 , 0 ,
V_19 ) ;
if ( V_11 ) {
F_3 ( L_4 ) ;
return V_11 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_11 ;
if ( ! F_7 () && ! F_8 ()
&& ! F_9 ()
&& ! F_10 () )
return 0 ;
V_20 = F_11 ( L_5 , - 1 ) ;
if ( ! V_20 )
return - V_21 ;
F_12 ( V_20 , & V_22 ) ;
V_11 = F_13 ( V_20 ) ;
if ( V_11 ) {
F_14 ( V_23 L_6 ) ;
F_15 ( V_20 ) ;
}
return V_11 ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_20 ) ;
}
