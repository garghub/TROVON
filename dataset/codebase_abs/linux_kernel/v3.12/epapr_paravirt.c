static int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 ,
int V_3 , void * V_4 )
{
const T_2 * V_5 ;
unsigned long V_6 ;
int V_7 ;
V_5 = F_2 ( V_1 , L_1 , & V_6 ) ;
if ( ! V_5 )
return 0 ;
if ( V_6 % 4 || V_6 > ( 4 * 4 ) )
return - 1 ;
for ( V_7 = 0 ; V_7 < ( V_6 / 4 ) ; V_7 ++ ) {
F_3 ( V_8 + V_7 , V_5 [ V_7 ] ) ;
#if ! F_4 ( V_9 ) || F_4 ( V_10 )
F_3 ( V_11 + V_7 , V_5 [ V_7 ] ) ;
#endif
}
#if ! F_4 ( V_9 ) || F_4 ( V_10 )
if ( F_2 ( V_1 , L_2 , NULL ) )
V_12 . V_13 = V_14 ;
#endif
V_15 = true ;
return 1 ;
}
int T_1 F_5 ( void )
{
F_6 ( F_1 , NULL ) ;
return 0 ;
}
