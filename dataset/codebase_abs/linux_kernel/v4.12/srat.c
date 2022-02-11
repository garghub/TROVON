void T_1
F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
if ( F_2 () )
return;
if ( V_2 -> V_6 . V_7 < sizeof( struct V_1 ) ) {
F_3 () ;
return;
}
if ( ( V_2 -> V_8 & V_9 ) == 0 )
return;
V_3 = V_2 -> V_10 ;
V_5 = V_2 -> V_5 ;
if ( ! V_11 -> V_12 ( V_5 ) ) {
F_4 ( V_13 L_1 ,
V_3 , V_5 ) ;
return;
}
V_4 = F_5 ( V_3 ) ;
if ( V_4 < 0 ) {
F_4 ( V_14 L_2 , V_3 ) ;
F_3 () ;
return;
}
if ( V_5 >= V_15 ) {
F_4 ( V_13 L_3 , V_3 , V_5 , V_4 ) ;
return;
}
F_6 ( V_5 , V_4 ) ;
F_7 ( V_4 , V_16 ) ;
F_4 ( V_13 L_4 ,
V_3 , V_5 , V_4 ) ;
}
void T_1
F_8 ( struct V_17 * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
if ( F_2 () )
return;
if ( V_2 -> V_6 . V_7 != sizeof( struct V_17 ) ) {
F_3 () ;
return;
}
if ( ( V_2 -> V_8 & V_9 ) == 0 )
return;
V_3 = V_2 -> V_18 ;
if ( V_19 >= 2 )
V_3 |= * ( ( unsigned int * ) V_2 -> V_20 ) << 8 ;
V_4 = F_5 ( V_3 ) ;
if ( V_4 < 0 ) {
F_4 ( V_14 L_2 , V_3 ) ;
F_3 () ;
return;
}
if ( F_9 () >= V_21 )
V_5 = ( V_2 -> V_5 << 8 ) | V_2 -> V_22 ;
else
V_5 = V_2 -> V_5 ;
if ( V_5 >= V_15 ) {
F_4 ( V_13 L_5 , V_3 , V_5 , V_4 ) ;
return;
}
F_6 ( V_5 , V_4 ) ;
F_7 ( V_4 , V_16 ) ;
F_4 ( V_13 L_6 ,
V_3 , V_5 , V_4 ) ;
}
int T_1 F_10 ( void )
{
int V_23 ;
V_23 = F_11 () ;
if ( V_23 < 0 )
return V_23 ;
return F_2 () ? - V_24 : 0 ;
}
