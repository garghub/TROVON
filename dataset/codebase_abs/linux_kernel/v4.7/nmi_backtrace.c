void F_1 ( bool V_1 ,
void (* raise)( T_1 * V_2 ) )
{
int V_3 , V_4 = F_2 () ;
if ( F_3 ( 0 , & V_5 ) ) {
F_4 () ;
return;
}
F_5 ( F_6 ( V_6 ) , V_7 ) ;
if ( ! V_1 )
F_7 ( V_4 , F_6 ( V_6 ) ) ;
if ( ! F_8 ( F_6 ( V_6 ) ) ) {
F_9 ( L_1 ,
( V_1 ? L_2 : L_3 ) ) ;
raise ( F_6 ( V_6 ) ) ;
}
for ( V_3 = 0 ; V_3 < 10 * 1000 ; V_3 ++ ) {
if ( F_8 ( F_6 ( V_6 ) ) )
break;
F_10 ( 1 ) ;
F_11 () ;
}
F_12 () ;
F_13 ( 0 , & V_5 ) ;
F_4 () ;
}
bool F_14 ( struct V_8 * V_9 )
{
int V_10 = F_15 () ;
if ( F_16 ( V_10 , F_6 ( V_6 ) ) ) {
F_17 ( L_4 , V_10 ) ;
if ( V_9 )
F_18 ( V_9 ) ;
else
F_19 () ;
F_7 ( V_10 , F_6 ( V_6 ) ) ;
return true ;
}
return false ;
}
