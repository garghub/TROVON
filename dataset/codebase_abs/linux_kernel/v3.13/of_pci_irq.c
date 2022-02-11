int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
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
V_4 -> V_19 = V_7 ;
V_4 -> V_20 = 1 ;
V_4 -> args [ 0 ] = V_9 ;
V_10 = F_7 ( V_9 ) ;
V_11 [ 0 ] = F_7 ( ( V_2 -> V_16 -> V_21 << 16 ) | ( V_2 -> V_22 << 8 ) ) ;
V_11 [ 1 ] = V_11 [ 2 ] = F_7 ( 0 ) ;
return F_8 ( V_11 , V_4 ) ;
}
int F_9 ( const struct V_1 * V_23 , T_3 V_24 , T_3 V_12 )
{
struct V_3 V_25 ;
int V_26 ;
V_26 = F_1 ( V_23 , & V_25 ) ;
if ( V_26 ) {
F_10 ( & V_23 -> V_23 , L_1 , V_26 ) ;
return 0 ;
}
return F_11 ( & V_25 ) ;
}
