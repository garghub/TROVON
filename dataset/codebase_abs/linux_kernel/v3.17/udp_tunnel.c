int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
int V_6 = - V_7 ;
struct V_4 * V_8 = NULL ;
#if F_2 ( V_9 )
if ( V_3 -> V_10 == V_11 ) {
struct V_12 V_13 ;
V_6 = F_3 ( V_11 , V_14 , 0 , & V_8 ) ;
if ( V_6 < 0 )
goto error;
F_4 ( V_8 -> V_15 , V_1 ) ;
V_13 . V_16 = V_11 ;
memcpy ( & V_13 . V_17 , & V_3 -> V_18 ,
sizeof( V_13 . V_17 ) ) ;
V_13 . V_19 = V_3 -> V_20 ;
V_6 = F_5 ( V_8 , (struct V_21 * ) & V_13 ,
sizeof( V_13 ) ) ;
if ( V_6 < 0 )
goto error;
if ( V_3 -> V_22 ) {
V_13 . V_16 = V_11 ;
memcpy ( & V_13 . V_17 , & V_3 -> V_23 ,
sizeof( V_13 . V_17 ) ) ;
V_13 . V_19 = V_3 -> V_22 ;
V_6 = F_6 ( V_8 ,
(struct V_21 * ) & V_13 ,
sizeof( V_13 ) , 0 ) ;
}
if ( V_6 < 0 )
goto error;
F_7 ( V_8 -> V_15 , ! V_3 -> V_24 ) ;
F_8 ( V_8 -> V_15 , ! V_3 -> V_25 ) ;
} else
#endif
if ( V_3 -> V_10 == V_26 ) {
struct V_27 V_28 ;
V_6 = F_3 ( V_26 , V_14 , 0 , & V_8 ) ;
if ( V_6 < 0 )
goto error;
F_4 ( V_8 -> V_15 , V_1 ) ;
V_28 . V_29 = V_26 ;
V_28 . V_30 = V_3 -> V_31 ;
V_28 . V_32 = V_3 -> V_20 ;
V_6 = F_5 ( V_8 , (struct V_21 * ) & V_28 ,
sizeof( V_28 ) ) ;
if ( V_6 < 0 )
goto error;
if ( V_3 -> V_22 ) {
V_28 . V_29 = V_26 ;
V_28 . V_30 = V_3 -> V_33 ;
V_28 . V_32 = V_3 -> V_22 ;
V_6 = F_6 ( V_8 ,
(struct V_21 * ) & V_28 ,
sizeof( V_28 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
}
V_8 -> V_15 -> V_34 = ! V_3 -> V_35 ;
} else {
return - V_36 ;
}
* V_5 = V_8 ;
return 0 ;
error:
if ( V_8 ) {
F_9 ( V_8 , V_37 ) ;
F_10 ( V_8 -> V_15 ) ;
}
* V_5 = NULL ;
return V_6 ;
}
