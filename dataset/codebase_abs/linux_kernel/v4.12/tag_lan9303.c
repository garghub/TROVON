static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( F_3 ( V_2 , V_8 ) < 0 ) {
F_4 ( & V_4 -> V_4 ,
L_1 ) ;
goto V_9;
}
F_5 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_10 , V_2 -> V_10 + V_8 , 2 * V_11 ) ;
V_7 = ( T_1 * ) ( V_2 -> V_10 + 2 * V_11 ) ;
V_7 [ 0 ] = F_6 ( V_12 ) ;
V_7 [ 1 ] = F_6 ( V_6 -> V_13 -> V_14 | F_7 ( 4 ) ) ;
return V_2 ;
V_9:
F_8 ( V_2 ) ;
return NULL ;
}
static struct V_1 * F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , struct V_3 * V_17 )
{
T_1 * V_7 ;
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 * V_22 ;
unsigned int V_23 ;
V_22 = V_19 -> V_22 [ 0 ] ;
if ( F_10 ( ! V_22 ) ) {
F_11 ( & V_4 -> V_4 , L_2 ) ;
return NULL ;
}
if ( F_10 ( ! F_12 ( V_2 , V_8 ) ) ) {
F_11 ( & V_4 -> V_4 ,
L_3 ) ;
return NULL ;
}
V_7 = ( T_1 * ) ( V_2 -> V_10 - 2 ) ;
if ( V_7 [ 0 ] != F_6 ( V_12 ) ) {
F_11 ( & V_4 -> V_4 , L_4 ) ;
return NULL ;
}
V_23 = F_13 ( V_7 [ 1 ] ) & 0x3 ;
if ( V_23 >= V_24 ) {
F_11 ( & V_4 -> V_4 , L_5 ) ;
return NULL ;
}
if ( ! V_22 -> V_25 [ V_23 ] . V_26 ) {
F_11 ( & V_4 -> V_4 , L_6 ) ;
return NULL ;
}
F_14 ( V_2 , 2 + 2 ) ;
memmove ( V_2 -> V_10 - V_27 , V_2 -> V_10 - ( V_27 + V_8 ) ,
2 * V_11 ) ;
V_2 -> V_4 = V_22 -> V_25 [ V_23 ] . V_26 ;
return V_2 ;
}
