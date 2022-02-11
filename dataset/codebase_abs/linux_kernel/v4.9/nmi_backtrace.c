void F_1 ( const T_1 * V_1 ,
bool V_2 ,
void (* raise)( T_1 * V_1 ) )
{
int V_3 , V_4 = F_2 () ;
if ( F_3 ( 0 , & V_5 ) ) {
F_4 () ;
return;
}
F_5 ( F_6 ( V_6 ) , V_1 ) ;
if ( V_2 )
F_7 ( V_4 , F_6 ( V_6 ) ) ;
if ( F_8 ( V_4 , F_6 ( V_6 ) ) )
F_9 ( NULL ) ;
if ( ! F_10 ( F_6 ( V_6 ) ) ) {
F_11 ( L_1 ,
V_4 , V_7 , F_6 ( V_6 ) ) ;
raise ( F_6 ( V_6 ) ) ;
}
for ( V_3 = 0 ; V_3 < 10 * 1000 ; V_3 ++ ) {
if ( F_10 ( F_6 ( V_6 ) ) )
break;
F_12 ( 1 ) ;
F_13 () ;
}
F_14 () ;
F_15 ( 0 , & V_5 ) ;
F_4 () ;
}
bool F_9 ( struct V_8 * V_9 )
{
int V_10 = F_16 () ;
if ( F_8 ( V_10 , F_6 ( V_6 ) ) ) {
if ( V_9 && F_17 ( F_18 ( V_9 ) ) ) {
F_19 ( L_2 ,
V_10 , F_18 ( V_9 ) ) ;
} else {
F_19 ( L_3 , V_10 ) ;
if ( V_9 )
F_20 ( V_9 ) ;
else
F_21 () ;
}
F_7 ( V_10 , F_6 ( V_6 ) ) ;
return true ;
}
return false ;
}
