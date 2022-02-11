int F_1 ( struct V_1 * V_2 ,
const char * V_3 ,
struct V_4 * V_5 ,
unsigned int * V_6 ,
unsigned int * V_7 )
{
struct V_8 V_9 ;
struct V_1 * V_10 , * V_11 ;
const T_1 * V_12 ;
int V_13 ;
V_10 = F_2 ( V_2 , V_3 , 0 ) ;
if ( ! V_10 )
return - V_14 ;
if ( ! F_3 ( V_10 , L_1 ) ) {
F_4 ( V_10 ) ;
return - V_14 ;
}
V_13 = F_5 ( V_10 , 0 , & V_9 ) ;
if ( V_13 ) {
F_4 ( V_10 ) ;
return V_13 ;
}
snprintf ( ( char * ) V_5 -> V_15 , V_16 , L_2 ,
( unsigned long long ) V_9 . V_17 , V_10 -> V_3 ) ;
V_12 = F_6 ( V_10 , L_3 , NULL ) ;
if ( ! V_12 ) {
F_4 ( V_10 ) ;
return - V_14 ;
}
* V_6 = F_7 ( V_12 ) ;
V_11 = F_8 ( V_10 ) ;
V_12 = F_6 ( V_11 , L_3 , NULL ) ;
if ( ! V_12 ) {
F_4 ( V_11 ) ;
return - V_14 ;
}
* V_7 = F_7 ( V_12 ) ;
F_4 ( V_11 ) ;
F_4 ( V_10 ) ;
return 0 ;
}
