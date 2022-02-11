static void F_1 ( struct V_1 * V_2 , const char * V_3 ,
unsigned int V_4 )
{
int V_5 , V_6 , V_7 ;
for ( V_5 = 0 , V_6 = 0 ; V_5 < V_4 ; V_5 ++ ) {
if ( ! V_3 [ V_5 ] )
return;
if ( V_3 [ V_5 ] == '\n' ) {
do {
V_7 = F_2 ( V_8 , & V_3 [ V_6 ] , V_5 - V_6 ) ;
if ( V_7 < 0 )
;
V_6 += V_7 ;
} while ( V_6 < V_5 );
while ( F_2 ( V_8 , L_1 , 1 ) <= 0 )
;
}
}
if ( V_6 != V_4 ) {
do {
V_7 = F_2 ( V_8 , & V_3 [ V_6 ] , V_4 - V_6 ) ;
if ( V_7 < 0 )
;
V_6 += V_7 ;
} while ( V_6 < V_4 );
}
}
static int F_3 ( struct V_1 * V_2 , char * V_3 )
{
char V_9 [ 32 ] ;
if ( F_4 ( L_2 , V_9 , 32 ) >= 0 ) {
#ifdef F_5
if ( ! strcmp ( V_9 , L_3 ) ) {
F_6 ( L_4 ) ;
} else if ( ! strcmp ( V_9 , L_5 ) ) {
F_6 ( L_6 ) ;
} else
#endif
#ifdef F_7
if ( ! strcmp ( V_9 , L_7 ) ) {
F_6 ( L_8 ) ;
} else
#endif
return - V_10 ;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
F_9 ( & V_11 ) ;
return 0 ;
}
