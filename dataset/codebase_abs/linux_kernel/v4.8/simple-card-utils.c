int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 ,
char * V_6 ,
unsigned int * V_7 )
{
struct V_3 * V_8 = NULL ;
struct V_3 * V_9 = NULL ;
int V_10 = V_6 ? strlen ( V_6 ) : 0 ;
unsigned int V_11 ;
V_11 = F_2 ( V_4 , V_6 ,
& V_8 , & V_9 ) ;
V_11 &= ~ V_12 ;
if ( V_10 && ! V_8 && ! V_9 ) {
F_3 ( V_2 , L_1 ) ;
V_11 = F_2 ( V_5 , NULL , NULL , NULL ) |
( V_11 & ~ V_13 ) ;
} else {
if ( V_5 == V_8 )
V_11 |= ( V_5 == V_9 ) ?
V_14 : V_15 ;
else
V_11 |= ( V_5 == V_9 ) ?
V_16 : V_17 ;
}
F_4 ( V_8 ) ;
F_4 ( V_9 ) ;
* V_7 = V_11 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
const char * V_20 , ... )
{
T_1 V_21 ;
char * V_22 = NULL ;
int V_23 = - V_24 ;
va_start ( V_21 , V_20 ) ;
V_22 = F_6 ( V_2 , V_25 , V_20 , V_21 ) ;
va_end ( V_21 ) ;
if ( V_22 ) {
V_23 = 0 ;
V_19 -> V_22 = V_22 ;
V_19 -> V_26 = V_22 ;
}
return V_23 ;
}
int F_7 ( struct V_27 * V_28 ,
char * V_6 )
{
char V_29 [ 128 ] ;
int V_23 ;
snprintf ( V_29 , sizeof( V_29 ) , L_2 , V_6 ) ;
V_23 = F_8 ( V_28 , V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_28 -> V_22 && V_28 -> V_19 )
V_28 -> V_22 = V_28 -> V_19 -> V_22 ;
return 0 ;
}
