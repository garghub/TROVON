static void F_1 ( void )
{
if ( F_2 () & F_3 () & V_1 )
F_4 ( V_2 + V_3 ) ;
}
static T_1 F_5 ( int V_4 , void * V_5 )
{
unsigned int V_6 ;
unsigned long V_7 ;
int V_8 ;
F_6 ( V_7 ) ;
V_6 = F_7 () ;
F_8 ( 0x100 << V_3 ) ;
F_9 () ;
F_10 ( V_6 ) ;
F_11 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
F_12 ( & V_10 [ V_8 ] . V_11 ) ;
F_12 ( & V_10 [ V_8 ] . V_12 ) ;
}
return V_13 ;
}
void F_13 ( void )
{
unsigned long V_7 ;
F_6 ( V_7 ) ;
F_7 () ;
F_14 ( 1 ) ;
F_15 ( F_16 () | V_1 ) ;
F_10 ( V_14 ) ;
F_11 ( V_7 ) ;
}
int T_2 F_17 ( void )
{
struct V_15 * V_16 ;
int V_8 , V_17 ;
if ( ! V_18 ) {
F_18 ( L_1 ) ;
return - V_19 ;
}
if ( F_19 () == 0 ) {
F_18 ( L_2
L_3 ) ;
return - V_19 ;
}
V_20 = F_20 ( 0 , V_21 , & V_22 ) ;
if ( V_20 < 0 ) {
F_21 ( L_4 ) ;
return V_20 ;
}
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
F_22 ( & V_10 [ V_8 ] . V_12 ) ;
F_22 ( & V_10 [ V_8 ] . V_11 ) ;
F_23 ( & V_10 [ V_8 ] . V_23 , 0 ) ;
F_24 ( & V_10 [ V_8 ] . V_24 ) ;
V_16 = F_25 ( V_25 , NULL , F_26 ( V_20 , V_8 ) , NULL ,
L_5 , V_21 , V_8 ) ;
if ( F_27 ( V_16 ) ) {
V_17 = F_28 ( V_16 ) ;
goto V_26;
}
}
V_27 . V_28 = V_29 ;
V_27 . V_30 = V_31 ;
F_29 ( F_19 () , & V_27 ) ;
if ( V_32 ) {
V_33 = F_1 ;
} else {
F_21 ( L_6 ) ;
V_17 = - V_19 ;
goto V_34;
}
V_35 . V_5 = V_36 ;
V_17 = F_30 ( V_37 , & V_35 ) ;
if ( V_17 )
goto V_34;
return 0 ;
V_34:
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_31 ( V_25 , F_26 ( V_20 , V_8 ) ) ;
V_26:
F_32 ( V_20 , V_21 ) ;
return V_17 ;
}
void T_3 F_33 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_31 ( V_25 , F_26 ( V_20 , V_8 ) ) ;
F_32 ( V_20 , V_21 ) ;
V_33 = NULL ;
}
