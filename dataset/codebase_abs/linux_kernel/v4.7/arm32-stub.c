T_1 F_1 ( T_2 * V_1 )
{
int V_2 ;
if ( ! F_2 ( V_3 ) )
return V_4 ;
V_2 = F_3 ( V_5 , 0 ) ;
if ( V_2 < 5 ) {
F_4 ( V_1 , L_1 ) ;
return V_6 ;
}
return V_4 ;
}
struct V_7 * F_5 ( T_2 * V_1 )
{
struct V_7 * V_8 ;
T_1 V_9 ;
V_9 = F_6 ( V_10 , V_11 ,
sizeof( * V_8 ) , ( void * * ) & V_8 ) ;
if ( V_9 != V_4 )
return NULL ;
V_9 = F_6 ( V_12 ,
& V_13 , V_8 ) ;
if ( V_9 == V_4 )
return V_8 ;
F_6 ( V_14 , V_8 ) ;
return NULL ;
}
void F_7 ( T_2 * V_1 , struct V_7 * V_8 )
{
if ( ! V_8 )
return;
F_6 ( V_12 , & V_13 , NULL ) ;
F_6 ( V_14 , V_8 ) ;
}
T_1 F_8 ( T_2 * V_15 ,
unsigned long * V_16 ,
unsigned long * V_17 ,
unsigned long * V_18 ,
unsigned long * V_19 ,
unsigned long V_20 ,
T_3 * V_21 )
{
unsigned long V_22 ;
T_1 V_9 ;
T_4 V_23 ;
V_20 = F_9 ( V_20 , V_24 ) ;
V_23 = V_20 ;
* V_19 = V_25 ;
V_22 = F_9 ( * V_19 , V_26 ) / V_26 ;
V_9 = V_15 -> V_27 -> V_28 ( V_29 ,
V_30 ,
V_22 , & V_23 ) ;
if ( V_9 != V_4 ) {
* V_19 = 0 ;
F_4 ( V_15 , L_2 ) ;
return V_9 ;
}
* V_18 = V_23 ;
* V_17 = V_21 -> V_17 ;
V_9 = F_10 ( V_15 , V_16 , * V_17 ,
* V_17 ,
V_20 + V_25 , 0 ) ;
if ( V_9 != V_4 ) {
F_4 ( V_15 , L_3 ) ;
F_11 ( V_15 , * V_19 , * V_18 ) ;
* V_19 = 0 ;
return V_9 ;
}
if ( * V_16 + * V_17 > V_20 + V_31 ) {
F_4 ( V_15 , L_4 ) ;
F_11 ( V_15 , * V_19 , * V_18 ) ;
* V_19 = 0 ;
F_11 ( V_15 , * V_17 , * V_16 ) ;
* V_17 = 0 ;
return V_32 ;
}
return V_4 ;
}
