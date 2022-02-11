int F_1 ( struct V_1 * log )
{
struct V_2 * V_3 ;
const T_1 * V_4 ;
const T_2 * V_5 ;
if ( log -> V_6 != NULL ) {
F_2 ( L_1 , V_7 ) ;
return - V_8 ;
}
V_3 = F_3 ( NULL , L_2 ) ;
if ( ! V_3 ) {
F_2 ( L_3 , V_7 ) ;
return - V_9 ;
}
V_4 = F_4 ( V_3 , L_4 , NULL ) ;
if ( V_4 == NULL ) {
F_2 ( L_5 , V_7 ) ;
goto V_10;
}
if ( * V_4 == 0 ) {
F_2 ( L_6 , V_7 ) ;
goto V_10;
}
V_5 = F_4 ( V_3 , L_7 , NULL ) ;
if ( V_5 == NULL ) {
F_2 ( L_8 , V_7 ) ;
goto V_10;
}
F_5 ( V_3 ) ;
log -> V_6 = F_6 ( * V_4 , V_11 ) ;
if ( ! log -> V_6 ) {
F_2 ( L_9 ,
V_7 ) ;
return - V_12 ;
}
log -> V_13 = log -> V_6 + * V_4 ;
memcpy ( log -> V_6 , F_7 ( F_8 ( V_5 ) ) , * V_4 ) ;
return 0 ;
V_10:
F_5 ( V_3 ) ;
return - V_14 ;
}
