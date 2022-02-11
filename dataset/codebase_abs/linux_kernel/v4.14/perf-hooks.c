void F_1 ( const struct V_1 * V_2 )
{
if ( ! ( V_2 && V_2 -> V_3 && * V_2 -> V_3 ) )
return;
if ( F_2 ( V_4 , 1 ) ) {
F_3 ( L_1 ,
V_2 -> V_5 ) ;
* ( V_6 -> V_3 ) = NULL ;
} else {
V_6 = V_2 ;
(* * V_2 -> V_3 )( V_2 -> V_7 ) ;
}
V_6 = NULL ;
}
void F_4 ( void )
{
if ( V_6 )
F_5 ( V_4 , 1 ) ;
}
int F_6 ( const char * V_5 ,
T_1 V_8 ,
void * V_7 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_7 ( V_10 ) ; V_9 ++ ) {
if ( strcmp ( V_5 , V_10 [ V_9 ] -> V_5 ) != 0 )
continue;
if ( * ( V_10 [ V_9 ] -> V_3 ) )
F_3 ( L_2 , V_5 ) ;
* ( V_10 [ V_9 ] -> V_3 ) = V_8 ;
V_10 [ V_9 ] -> V_7 = V_7 ;
return 0 ;
}
return - V_11 ;
}
T_1 F_8 ( const char * V_5 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_7 ( V_10 ) ; V_9 ++ ) {
if ( strcmp ( V_5 , V_10 [ V_9 ] -> V_5 ) != 0 )
continue;
return * ( V_10 [ V_9 ] -> V_3 ) ;
}
return F_9 ( - V_11 ) ;
}
