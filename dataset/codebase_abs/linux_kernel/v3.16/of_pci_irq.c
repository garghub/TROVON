int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_7 ;
struct V_1 * V_8 ;
T_1 V_9 [ 3 ] ;
T_2 V_10 ;
int V_11 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 ) {
V_11 = F_3 ( V_6 , 0 , V_4 ) ;
if ( ! V_11 )
return V_11 ;
}
V_11 = F_4 ( V_2 , V_12 , & V_10 ) ;
if ( V_11 != 0 )
return V_11 ;
if ( V_10 == 0 )
return - V_13 ;
for (; ; ) {
V_8 = V_2 -> V_14 -> V_15 ;
if ( V_8 == NULL ) {
V_7 = F_5 ( V_2 -> V_14 ) ;
if ( V_7 == NULL )
return - V_16 ;
} else {
V_7 = F_2 ( V_8 ) ;
}
if ( V_7 )
break;
V_10 = F_6 ( V_2 , V_10 ) ;
V_2 = V_8 ;
}
V_4 -> V_17 = V_7 ;
V_4 -> V_18 = 1 ;
V_4 -> args [ 0 ] = V_10 ;
V_9 [ 0 ] = F_7 ( ( V_2 -> V_14 -> V_19 << 16 ) | ( V_2 -> V_20 << 8 ) ) ;
V_9 [ 1 ] = V_9 [ 2 ] = F_7 ( 0 ) ;
return F_8 ( V_9 , V_4 ) ;
}
int F_9 ( const struct V_1 * V_21 , T_2 V_22 , T_2 V_10 )
{
struct V_3 V_23 ;
int V_24 ;
V_24 = F_1 ( V_21 , & V_23 ) ;
if ( V_24 ) {
F_10 ( & V_21 -> V_21 , L_1 , V_24 ) ;
return 0 ;
}
return F_11 ( & V_23 ) ;
}
