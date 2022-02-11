int F_1 ( unsigned int V_1 , T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_2 == V_5 [ V_3 ] . V_6 )
return V_5 [ V_3 ] . V_7 ;
}
return V_8 ;
}
void T_2 F_2 ( struct V_9 * V_10 )
{
int V_11 , V_12 ;
T_3 V_13 ;
if ( F_3 () )
return;
if ( V_10 -> V_14 . V_15 < sizeof( struct V_9 ) ) {
F_4 ( L_1 ,
V_10 -> V_14 . V_15 ) ;
F_5 () ;
return;
}
if ( ! ( V_10 -> V_16 & V_17 ) )
return;
if ( V_4 >= V_18 ) {
F_6 ( L_2 ,
V_18 ) ;
return;
}
V_11 = V_10 -> V_19 ;
V_12 = F_7 ( V_11 ) ;
if ( V_12 == V_8 || V_12 >= V_20 ) {
F_4 ( L_3 , V_11 ) ;
F_5 () ;
return;
}
V_13 = F_8 ( V_10 -> V_21 ) ;
if ( V_13 == V_22 ) {
F_4 ( L_4 ,
V_11 , V_10 -> V_21 ) ;
F_5 () ;
return;
}
V_5 [ V_4 ] . V_7 = V_12 ;
V_5 [ V_4 ] . V_6 = V_13 ;
F_9 ( V_12 , V_23 ) ;
V_4 ++ ;
F_10 ( L_5 ,
V_11 , V_13 , V_12 ) ;
}
int T_2 F_11 ( void )
{
int V_24 ;
V_24 = F_12 () ;
if ( V_24 ) {
F_10 ( L_6 ) ;
return V_24 ;
}
return F_3 () ? - V_25 : 0 ;
}
