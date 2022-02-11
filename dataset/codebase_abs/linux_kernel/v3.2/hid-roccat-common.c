static inline T_1 F_1 ( T_2 V_1 )
{
return 0x300 | V_1 ;
}
int F_2 ( struct V_2 * V_3 , T_3 V_1 ,
void * V_4 , T_3 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_3 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_4 ( V_3 , F_5 ( V_3 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
F_1 ( V_1 ) ,
0 , V_6 , V_5 , V_14 ) ;
memcpy ( V_4 , V_6 , V_5 ) ;
F_6 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
int F_7 ( struct V_2 * V_3 , T_3 V_1 ,
void const * V_4 , T_3 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_3 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
memcpy ( V_6 , V_4 , V_5 ) ;
V_7 = F_4 ( V_3 , F_8 ( V_3 , 0 ) ,
V_16 ,
V_11 | V_12 | V_17 ,
F_1 ( V_1 ) ,
0 , V_6 , V_5 , V_14 ) ;
F_6 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
