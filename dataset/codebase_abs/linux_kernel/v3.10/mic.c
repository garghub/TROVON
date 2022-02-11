int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( L_1 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_3 ) ) {
F_4 ( V_4 L_2
L_3 ) ;
V_2 -> V_3 = NULL ;
return - V_5 ;
}
V_2 -> V_6 = F_2 ( L_1 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_6 ) ) {
F_4 ( V_4 L_2
L_3 ) ;
V_2 -> V_6 = NULL ;
return - V_5 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_6 ( V_2 -> V_3 ) ;
if ( V_2 -> V_6 )
F_6 ( V_2 -> V_6 ) ;
}
int F_7 ( struct V_7 * V_8 , T_1 * V_9 ,
T_1 * V_10 , T_1 * V_11 , T_1 V_12 ,
T_1 * V_13 , T_2 V_14 , T_1 * V_15 )
{
struct V_16 V_17 ;
struct V_18 V_19 [ 2 ] ;
T_1 V_20 [ V_21 + 2 ] ;
if ( V_8 == NULL ) {
F_4 ( V_22 L_4 ) ;
return - 1 ;
}
memcpy ( & V_20 [ 0 ] , V_10 , V_23 ) ;
memcpy ( & V_20 [ V_23 ] , V_11 , V_23 ) ;
V_20 [ V_23 * 2 ] = V_12 ;
V_20 [ V_23 * 2 + 1 ] = 0 ;
V_20 [ V_23 * 2 + 2 ] = 0 ;
V_20 [ V_23 * 2 + 3 ] = 0 ;
F_8 ( V_19 , 2 ) ;
F_9 ( & V_19 [ 0 ] , V_20 , sizeof( V_20 ) ) ;
F_9 ( & V_19 [ 1 ] , V_13 , V_14 ) ;
if ( F_10 ( V_8 , V_9 , V_24 ) )
return - 1 ;
V_17 . V_25 = V_8 ;
V_17 . V_26 = 0 ;
return F_11 ( & V_17 , V_19 , V_14 + sizeof( V_20 ) ,
V_15 ) ;
}
