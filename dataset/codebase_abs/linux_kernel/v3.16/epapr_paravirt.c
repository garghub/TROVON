static int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 ,
int V_3 , void * V_4 )
{
const T_2 * V_5 ;
int V_6 ;
int V_7 ;
V_5 = F_2 ( V_1 , L_1 , & V_6 ) ;
if ( ! V_5 )
return 0 ;
if ( V_6 % 4 || V_6 > ( 4 * 4 ) )
return - 1 ;
for ( V_7 = 0 ; V_7 < ( V_6 / 4 ) ; V_7 ++ ) {
T_2 V_8 = F_3 ( V_5 [ V_7 ] ) ;
F_4 ( V_9 + V_7 , V_8 ) ;
#if ! F_5 ( V_10 ) || F_5 ( V_11 )
F_4 ( V_12 + V_7 , V_8 ) ;
#endif
}
#if ! F_5 ( V_10 ) || F_5 ( V_11 )
if ( F_2 ( V_1 , L_2 , NULL ) )
V_13 = true ;
#endif
V_14 = true ;
return 1 ;
}
int T_1 F_6 ( void )
{
F_7 ( F_1 , NULL ) ;
return 0 ;
}
static int T_1 F_8 ( void )
{
#if ! F_5 ( V_10 ) || F_5 ( V_11 )
if ( V_13 )
V_15 . V_16 = V_17 ;
#endif
return 0 ;
}
