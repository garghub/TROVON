int F_1 ( const char * V_1 , char * * V_2 , const struct V_3 * V_4 ,
char * * V_5 , char * * V_6 , unsigned long * V_7 )
{
char * V_8 ;
char * V_9 ;
do {
if ( ( V_8 = F_2 ( V_2 , L_1 ) ) == NULL )
return 0 ;
} while ( * V_8 == '\0' );
if ( V_5 )
* V_5 = V_8 ;
if ( ( V_9 = strchr ( V_8 , '=' ) ) != NULL ) {
* V_9 ++ = 0 ;
}
* V_6 = V_9 ;
for (; V_4 -> V_10 ; V_4 ++ ) {
if ( ! strcmp ( V_4 -> V_10 , V_8 ) ) {
if ( ! V_9 ) {
if ( V_4 -> V_11 & V_12 ) {
return V_4 -> V_9 ;
}
F_3 ( V_13 L_2 ,
V_1 , V_8 ) ;
return - V_14 ;
}
if ( V_4 -> V_11 & V_15 ) {
char * V_16 ;
* V_7 = F_4 ( V_9 , & V_16 , 0 ) ;
if ( ! * V_16 ) {
return V_4 -> V_9 ;
}
F_3 ( V_13 L_3 ,
V_1 , V_8 , V_9 ) ;
return - V_17 ;
}
if ( V_4 -> V_11 & V_18 ) {
return V_4 -> V_9 ;
}
F_3 ( V_13 L_4 ,
V_1 , V_9 , V_8 ) ;
return - V_14 ;
}
}
F_3 ( V_13 L_5 , V_1 , V_8 ) ;
return - V_19 ;
}
