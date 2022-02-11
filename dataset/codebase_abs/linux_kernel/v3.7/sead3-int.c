T_1 void F_1 ( void )
{
unsigned int V_1 = F_2 () & F_3 () & V_2 ;
int V_3 ;
V_3 = ( F_4 ( V_1 ) - V_4 - 1 ) ;
if ( V_3 >= 0 )
F_5 ( V_5 + V_3 ) ;
else
F_6 () ;
}
void T_2 F_7 ( void )
{
int V_6 ;
if ( ! V_7 ) {
F_8 () ;
if ( V_8 ) {
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
F_9 ( V_6 , F_1 ) ;
}
}
V_9 = ( unsigned long ) F_10 ( V_10 ,
V_11 ) ;
V_12 = ( F_11 ( V_9 ) & V_13 ) >>
V_14 ;
F_12 ( L_1 , ( V_12 ) ? L_2 : L_3 ) ;
F_12 ( L_4 ,
( V_15 . V_16 & V_17 ) ? L_5 : L_6 ) ;
if ( V_12 )
F_13 ( V_18 , V_19 , V_20 ,
F_14 ( V_20 ) , V_21 ) ;
}
void F_15 ( int V_22 )
{
unsigned int V_6 , V_23 ;
for ( V_6 = 0 ; V_6 < V_24 [ V_22 ] . V_25 ; V_6 ++ ) {
V_23 = V_24 [ V_22 ] . V_26 [ V_6 ] ;
F_16 ( V_23 ) ;
}
if ( V_24 [ V_22 ] . V_27 ) {
F_17 ( F_18 ( V_28 , V_29 ) , 0 ) ;
F_17 ( F_18 ( V_30 , V_31 ) ,
V_24 [ V_22 ] . V_27 ) ;
}
}
void F_19 ( int V_22 )
{
unsigned int V_6 , V_23 ;
for ( V_6 = 0 ; V_6 < V_24 [ V_22 ] . V_25 ; V_6 ++ ) {
V_23 = V_24 [ V_22 ] . V_26 [ V_6 ] ;
F_20 ( V_23 ) ;
}
if ( V_24 [ V_22 ] . V_27 ) {
F_17 ( F_18 ( V_28 , V_29 ) , 0 ) ;
F_17 ( F_18 ( V_30 , V_32 ) ,
V_24 [ V_22 ] . V_27 ) ;
}
}
void F_21 ( struct V_33 * V_34 )
{
F_20 ( V_34 -> V_3 - V_35 ) ;
}
void F_22 ( struct V_33 * V_34 )
{
unsigned int V_3 = ( V_34 -> V_3 - V_35 ) ;
unsigned int V_6 , V_23 ;
for ( V_6 = 0 ; V_6 < V_24 [ V_3 ] . V_25 ; V_6 ++ ) {
V_23 = V_24 [ V_3 ] . V_26 [ V_6 ] ;
if ( V_36 [ V_23 ] & V_37 )
F_17 ( F_18 ( V_38 , V_39 ) , V_23 ) ;
}
F_16 ( V_3 ) ;
}
void T_2 F_23 ( int V_40 , struct V_41 * V_42 )
{
int V_6 ;
if ( ! V_7 )
return;
for ( V_6 = V_35 ; V_6 < ( V_35 + V_40 ) ; V_6 ++ )
F_24 ( V_6 , V_42 , V_43 ) ;
}
