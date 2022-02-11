int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_2 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
V_3 , 0 , V_6 , V_5 , V_14 ) ;
memcpy ( V_4 , V_6 , V_5 ) ;
F_5 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
void const * V_4 , T_1 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_2 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
memcpy ( V_6 , V_4 , V_5 ) ;
V_7 = F_3 ( V_2 , F_7 ( V_2 , 0 ) ,
V_16 ,
V_11 | V_12 | V_17 ,
V_3 , 0 , V_6 , V_5 , V_14 ) ;
F_5 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
