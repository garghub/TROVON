T_1 * F_1 ( int V_1 )
{
T_1 * V_2 ;
T_2 * V_3 ;
if ( V_1 != V_4 ) {
F_2 ( V_5 ,
V_6 ) ;
return NULL ;
}
V_2 = F_3 () ;
if ( V_2 == NULL )
return NULL ;
V_3 = F_4 ( T_2 ) ;
if ( V_3 == NULL )
goto V_7;
V_2 -> V_8 = F_5 ( V_9 ) ;
V_2 -> V_10 . V_11 = V_3 ;
V_3 -> V_12 = 0 ;
F_6 ( V_3 -> V_13 ,
F_5 ( V_4 ) , V_14 , NULL ) ;
V_3 -> V_15 -> V_16 = F_5 ( V_17 ) ;
return V_2 ;
V_7:
F_7 ( V_2 ) ;
return NULL ;
}
T_3 * F_8 ( T_1 * V_2 )
{
T_2 * V_3 ;
const T_4 * V_18 ;
if ( F_9 ( V_2 -> V_8 ) != V_9 ) {
F_2 ( V_19 ,
V_20 ) ;
return NULL ;
}
V_3 = V_2 -> V_10 . V_11 ;
F_10 ( & V_18 , NULL , NULL , V_3 -> V_13 ) ;
if ( F_9 ( V_18 ) != V_4 ) {
F_2 ( V_19 ,
V_6 ) ;
return NULL ;
}
return F_11 ( F_12 () ) ;
}
