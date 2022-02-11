static void T_1 F_1 ( void T_2 * V_1 )
{
int V_2 ;
if ( F_2 ( ! V_1 ) )
return;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ ) {
char V_4 [ 12 ] ;
const char * V_5 [] = {
L_1 ,
L_2
} ;
snprintf ( V_4 , F_3 ( V_4 ) , L_3 , V_2 ) ;
V_3 [ V_2 ] = F_4 ( NULL , V_4 ,
V_5 , 2 , 0 , V_1 + V_6 ,
F_5 ( V_2 ) , 1 ,
0 , & V_7 ) ;
if ( F_2 ( F_6 ( V_3 [ V_2 ] ) ) )
break;
}
}
void T_1 F_7 ( void T_2 * V_8 )
{
struct V_9 * V_9 ;
int V_2 ;
V_9 = F_8 ( NULL , L_4 , NULL ,
V_10 , 0 ) ;
F_2 ( F_9 ( V_9 , L_5 , NULL ) ) ;
V_9 = F_8 ( NULL , L_6 , NULL ,
V_10 , 24000000 ) ;
for ( V_2 = 0 ; V_2 < F_3 ( V_11 ) ; V_2 ++ )
F_2 ( F_9 ( V_9 , NULL ,
V_11 [ V_2 ] ) ) ;
V_9 = F_8 ( NULL , L_1 , NULL ,
V_10 , 32768 ) ;
F_2 ( F_9 ( V_9 , NULL , L_7 ) ) ;
V_9 = F_8 ( NULL , L_2 , NULL ,
V_10 , 1000000 ) ;
F_1 ( V_8 ) ;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ )
F_2 ( F_10 ( V_3 [ V_2 ] , V_9 ) ) ;
F_2 ( F_9 ( V_3 [ 0 ] ,
L_8 , L_9 ) ) ;
F_2 ( F_9 ( V_3 [ 1 ] ,
L_10 , L_9 ) ) ;
}
