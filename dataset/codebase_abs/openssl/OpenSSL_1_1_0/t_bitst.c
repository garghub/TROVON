int F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 , int V_4 )
{
T_3 * V_5 ;
char V_6 = 1 ;
F_2 ( V_1 , L_1 , V_4 , L_2 ) ;
for ( V_5 = V_3 ; V_5 -> V_7 ; V_5 ++ ) {
if ( F_3 ( V_2 , V_5 -> V_8 ) ) {
if ( ! V_6 )
F_4 ( V_1 , L_3 ) ;
F_4 ( V_1 , V_5 -> V_7 ) ;
V_6 = 0 ;
}
}
F_4 ( V_1 , L_4 ) ;
return 1 ;
}
int F_5 ( T_2 * V_2 , const char * V_9 , int V_10 ,
T_3 * V_3 )
{
int V_8 ;
V_8 = F_6 ( V_9 , V_3 ) ;
if ( V_8 < 0 )
return 0 ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , V_8 , V_10 ) )
return 0 ;
}
return 1 ;
}
int F_6 ( const char * V_9 , T_3 * V_3 )
{
T_3 * V_5 ;
for ( V_5 = V_3 ; V_5 -> V_7 ; V_5 ++ ) {
if ( ( strcmp ( V_5 -> V_11 , V_9 ) == 0 )
|| ( strcmp ( V_5 -> V_7 , V_9 ) == 0 ) )
return V_5 -> V_8 ;
}
return - 1 ;
}
