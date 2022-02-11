static int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
if ( V_4 . V_5 )
return V_4 . V_5 ( F_2 ( V_1 ) ,
F_3 ( V_6 ) ) ;
return - V_7 ;
}
void T_1 F_4 ( unsigned int V_1 )
{
const struct V_8 V_9 = {
. type = V_10 ,
} ;
if ( V_4 . V_11 )
V_4 . V_11 ( V_9 ) ;
F_5 ( L_1 , V_1 ) ;
}
int T_1 F_6 ( unsigned int V_1 )
{
int V_12 , V_13 ;
if ( ! V_4 . V_14 )
return 1 ;
for ( V_13 = 0 ; V_13 < 10 ; V_13 ++ ) {
V_12 = V_4 . V_14 ( F_2 ( V_1 ) , 0 ) ;
if ( V_12 == V_15 ) {
F_7 ( L_2 , V_1 ) ;
return 1 ;
}
F_8 ( 10 ) ;
F_7 ( L_3 ) ;
}
F_9 ( L_4 ,
V_1 , V_12 ) ;
return 0 ;
}
bool T_2 F_10 ( void )
{
return ( V_4 . V_5 != NULL ) ;
}
