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
T_5 V_12 ;
unsigned int V_13 ;
if( strcmp ( V_6 , L_1 ) ) return F_3 ( V_1 , V_5 , V_6 ) ;
if( ! ( V_2 = F_4 () ) ) {
F_5 ( V_14 , V_8 ) ;
return NULL ;
}
if( V_5 && ( V_5 -> V_15 == V_16 ) ) return V_2 ;
if( ! V_5 || ( ! V_5 -> V_17 && ! V_5 -> V_18 ) ) {
F_5 ( V_19 , V_20 ) ;
goto V_21;
}
if( V_5 -> V_17 )
V_9 = V_5 -> V_17 -> V_22 -> V_23 -> V_24 ;
else V_9 = V_5 -> V_18 -> V_25 -> V_26 -> V_24 ;
if( ! V_9 ) {
F_5 ( V_19 , V_20 ) ;
goto V_21;
}
F_9 ( & V_12 , F_10 () ) ;
F_11 ( & V_12 , V_9 -> V_3 , V_9 -> V_4 ) ;
F_12 ( & V_12 , V_10 , & V_13 ) ;
if( ! F_13 ( V_2 , V_10 , V_13 ) ) {
F_5 ( V_14 , V_8 ) ;
goto V_21;
}
return V_2 ;
V_21:
F_7 ( V_2 ) ;
return NULL ;
}
