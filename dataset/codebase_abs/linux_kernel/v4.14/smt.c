int F_1 ( void )
{
static bool V_1 ;
static int V_2 ;
int V_3 ;
int V_4 ;
if ( V_1 )
return V_2 ;
V_4 = F_2 ( V_5 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
unsigned long long V_6 ;
char * V_7 ;
T_1 strlen ;
char V_8 [ 256 ] ;
snprintf ( V_8 , sizeof V_8 ,
L_1 ,
V_3 ) ;
if ( F_3 ( V_8 , & V_7 , & strlen ) < 0 )
continue;
V_6 = F_4 ( V_7 , NULL , 16 ) ;
free ( V_7 ) ;
if ( F_5 ( V_6 ) > 1 ) {
V_2 = 1 ;
V_1 = true ;
break;
}
}
if ( ! V_1 ) {
V_2 = 0 ;
V_1 = true ;
}
return V_2 ;
}
