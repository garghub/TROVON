int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_7 ;
struct V_1 * V_8 ;
T_1 V_9 ;
T_2 V_10 ;
T_2 V_11 [ 3 ] ;
T_3 V_12 ;
int V_13 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 ) {
V_13 = F_3 ( V_6 , 0 , V_4 ) ;
if ( ! V_13 )
return V_13 ;
}
V_13 = F_4 ( V_2 , V_14 , & V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
if ( V_12 == 0 )
return - V_15 ;
V_9 = V_12 ;
for (; ; ) {
V_8 = V_2 -> V_16 -> V_17 ;
if ( V_8 == NULL ) {
V_7 = F_5 ( V_2 -> V_16 ) ;
if ( V_7 == NULL )
return - V_18 ;
} else {
V_7 = F_2 ( V_8 ) ;
}
if ( V_7 )
break;
V_9 = F_6 ( V_2 , V_9 ) ;
V_2 = V_8 ;
}
V_10 = F_7 ( V_9 ) ;
V_11 [ 0 ] = F_7 ( ( V_2 -> V_16 -> V_19 << 16 ) | ( V_2 -> V_20 << 8 ) ) ;
V_11 [ 1 ] = V_11 [ 2 ] = F_7 ( 0 ) ;
return F_8 ( V_7 , & V_10 , 1 , V_11 , V_4 ) ;
}
