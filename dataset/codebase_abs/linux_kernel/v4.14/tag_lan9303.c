static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 * V_7 ;
if ( F_3 ( V_2 , V_8 ) < 0 ) {
F_4 ( & V_4 -> V_4 ,
L_1 ) ;
return NULL ;
}
F_5 ( V_2 , V_8 ) ;
memmove ( V_2 -> V_9 , V_2 -> V_9 + V_8 , 2 * V_10 ) ;
V_7 = ( T_1 * ) ( V_2 -> V_9 + 2 * V_10 ) ;
V_7 [ 0 ] = F_6 ( V_11 ) ;
V_7 [ 1 ] = F_6 ( V_6 -> V_12 -> V_13 | F_7 ( 4 ) ) ;
return V_2 ;
}
static struct V_1 * F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 )
{
T_1 * V_7 ;
struct V_16 * V_17 = V_4 -> V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
V_20 = V_17 -> V_20 [ 0 ] ;
if ( F_9 ( ! V_20 ) ) {
F_10 ( & V_4 -> V_4 , L_2 ) ;
return NULL ;
}
if ( F_9 ( ! F_11 ( V_2 , V_8 ) ) ) {
F_10 ( & V_4 -> V_4 ,
L_3 ) ;
return NULL ;
}
V_7 = ( T_1 * ) ( V_2 -> V_9 - 2 ) ;
if ( V_7 [ 0 ] != F_6 ( V_11 ) ) {
F_10 ( & V_4 -> V_4 , L_4 ) ;
return NULL ;
}
V_21 = F_12 ( V_7 [ 1 ] ) & 0x3 ;
if ( V_21 >= V_20 -> V_22 ) {
F_10 ( & V_4 -> V_4 , L_5 ) ;
return NULL ;
}
if ( ! V_20 -> V_23 [ V_21 ] . V_24 ) {
F_10 ( & V_4 -> V_4 , L_6 ) ;
return NULL ;
}
F_13 ( V_2 , 2 + 2 ) ;
memmove ( V_2 -> V_9 - V_25 , V_2 -> V_9 - ( V_25 + V_8 ) ,
2 * V_10 ) ;
V_2 -> V_4 = V_20 -> V_23 [ V_21 ] . V_24 ;
return V_2 ;
}
