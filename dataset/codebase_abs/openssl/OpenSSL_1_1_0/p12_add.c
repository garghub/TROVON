T_1 * F_1 ( void * V_1 , const T_2 * V_2 ,
int V_3 , int V_4 )
{
T_3 * V_5 ;
T_1 * V_6 ;
if ( ( V_5 = F_2 () ) == NULL ) {
F_3 ( V_7 , V_8 ) ;
return NULL ;
}
V_5 -> type = F_4 ( V_3 ) ;
if ( ! F_5 ( V_1 , V_2 , & V_5 -> V_9 . V_10 ) ) {
F_3 ( V_7 , V_8 ) ;
goto V_11;
}
if ( ( V_6 = F_6 () ) == NULL ) {
F_3 ( V_7 , V_8 ) ;
goto V_11;
}
V_6 -> V_9 . V_5 = V_5 ;
V_6 -> type = F_4 ( V_4 ) ;
return V_6 ;
V_11:
F_7 ( V_5 ) ;
return NULL ;
}
