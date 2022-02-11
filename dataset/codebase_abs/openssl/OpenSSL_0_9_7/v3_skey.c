char * F_1 ( T_1 * V_1 ,
T_2 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
}
T_2 * F_3 ( T_1 * V_1 ,
T_3 * V_5 , char * V_6 )
{
T_2 * V_2 ;
long V_4 ;
if( ! ( V_2 = F_4 () ) ) {
F_5 ( V_7 , V_8 ) ;
return NULL ;
}
if( ! ( V_2 -> V_3 = F_6 ( V_6 , & V_4 ) ) ) {
F_7 ( V_2 ) ;
return NULL ;
}
V_2 -> V_4 = V_4 ;
return V_2 ;
}
static T_2 * F_8 ( T_1 * V_1 ,
T_3 * V_5 , char * V_6 )
{
T_2 * V_2 ;
T_4 * V_9 ;
unsigned char V_10 [ V_11 ] ;
unsigned int V_12 ;
if( strcmp ( V_6 , L_1 ) ) return F_3 ( V_1 , V_5 , V_6 ) ;
if( ! ( V_2 = F_4 () ) ) {
F_5 ( V_13 , V_8 ) ;
return NULL ;
}
if( V_5 && ( V_5 -> V_14 == V_15 ) ) return V_2 ;
if( ! V_5 || ( ! V_5 -> V_16 && ! V_5 -> V_17 ) ) {
F_5 ( V_18 , V_19 ) ;
goto V_20;
}
if( V_5 -> V_16 )
V_9 = V_5 -> V_16 -> V_21 -> V_22 -> V_23 ;
else V_9 = V_5 -> V_17 -> V_24 -> V_25 -> V_23 ;
if( ! V_9 ) {
F_5 ( V_18 , V_19 ) ;
goto V_20;
}
F_9 ( V_9 -> V_3 , V_9 -> V_4 , V_10 , & V_12 , F_10 () , NULL ) ;
if( ! F_11 ( V_2 , V_10 , V_12 ) ) {
F_5 ( V_13 , V_8 ) ;
goto V_20;
}
return V_2 ;
V_20:
F_7 ( V_2 ) ;
return NULL ;
}
