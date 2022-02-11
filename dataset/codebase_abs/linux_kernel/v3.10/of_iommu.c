int F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 ,
unsigned long * V_5 , T_1 * V_6 , T_2 * V_7 )
{
const T_3 * V_8 , * V_9 ;
int V_10 , V_11 = 0 ;
char V_12 [ V_13 ] , V_14 [ V_13 ] , V_15 [ V_13 ] ;
if ( ! V_2 || ! V_6 || ! V_7 )
return - V_16 ;
if ( ! V_3 )
V_3 = L_1 ;
snprintf ( V_12 , sizeof( V_12 ) , L_2 , V_3 ) ;
snprintf ( V_14 , sizeof( V_14 ) , L_3 , V_3 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_4 , V_3 ) ;
V_8 = F_2 ( V_2 , V_12 , & V_10 ) ;
if ( ! V_8 )
return - V_17 ;
V_9 = V_8 + V_10 / sizeof( * V_8 ) ;
while ( V_8 < V_9 ) {
T_4 V_18 ;
const void * V_19 ;
if ( V_5 )
* V_5 = F_3 ( V_8 ++ ) ;
V_19 = F_2 ( V_2 , V_14 , NULL ) ;
if ( ! V_19 )
V_19 = F_2 ( V_2 , L_5 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_4 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_6 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
V_19 = F_2 ( V_2 , V_15 , NULL ) ;
V_18 = V_19 ? F_3 ( V_19 ) : F_6 ( V_2 ) ;
if ( ! V_18 )
return - V_16 ;
* V_7 = F_5 ( V_8 , V_18 ) ;
V_8 += V_18 ;
if ( V_11 ++ == V_4 )
break;
}
return 0 ;
}
