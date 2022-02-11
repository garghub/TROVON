int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 V_8 ;
int V_9 = 0 ;
int V_10 ;
int V_11 ;
int V_12 = 0 ;
int V_13 = 0 ;
T_1 V_14 = 0 ;
T_1 V_15 = 0 ;
if ( V_4 -> V_16 -> V_17 == V_4 ) {
goto V_18;
}
if ( V_4 -> V_19 == 0 && ! V_12 )
goto V_18;
if ( F_2 ( V_4 , V_20 ) )
goto V_18;
V_6 = F_3 () ;
if ( ! V_6 )
return - V_21 ;
V_11 = F_4 ( V_4 -> V_22 ) ;
if ( V_11 == 0 )
goto V_18;
if ( V_4 -> V_23 . V_24 == 0 ) {
struct V_25 * V_26 ;
T_2 V_27 ;
V_26 = F_5 ( V_4 ) ;
F_6 ( V_26 ) ;
V_27 = F_7 ( V_26 ) ;
V_4 -> V_28 . V_24 = 0 ;
F_8 ( V_26 , & V_4 -> V_28 ,
V_27 - 1 ) ;
F_9 ( V_26 ) ;
F_10 ( V_26 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
} else {
memcpy ( & V_8 , & V_4 -> V_23 , sizeof( V_8 ) ) ;
}
V_6 -> V_29 = 1 ;
V_9 = F_11 ( V_4 , & V_8 , NULL , V_6 , V_15 ) ;
if ( V_9 < 0 )
goto V_18;
if ( V_9 > 0 ) {
V_9 = 0 ;
goto V_18;
}
F_12 ( V_6 ) ;
V_10 = F_13 ( V_2 , V_4 , & V_8 , V_6 , 0 , 1 ) ;
if ( V_10 < 0 ) {
V_9 = V_10 ;
goto V_18;
}
if ( ! V_6 -> V_30 [ 1 ] ) {
V_9 = 0 ;
goto V_18;
}
V_6 -> V_31 [ 1 ] = F_7 ( V_6 -> V_30 [ 1 ] ) ;
V_13 = F_14 ( V_4 , V_6 , & V_8 , 1 ,
V_15 ) ;
V_9 = F_15 ( V_2 , V_4 ,
V_6 -> V_30 [ 1 ] , 0 ,
& V_14 ,
& V_4 -> V_23 ) ;
if ( V_9 ) {
F_16 ( V_9 == - V_32 ) ;
goto V_18;
}
if ( V_13 == 0 ) {
memcpy ( & V_4 -> V_23 , & V_8 , sizeof( V_8 ) ) ;
V_9 = - V_32 ;
}
V_18:
if ( V_6 )
F_17 ( V_6 ) ;
if ( V_9 == - V_32 ) {
if ( V_4 -> V_28 . V_24 > V_4 -> V_23 . V_24 )
goto V_33;
if ( V_4 -> V_28 . type > V_4 -> V_23 . type )
goto V_33;
if ( V_4 -> V_28 . V_34 > V_4 -> V_23 . V_34 )
goto V_33;
V_9 = 0 ;
}
V_33:
if ( V_9 != - V_32 ) {
memset ( & V_4 -> V_23 , 0 ,
sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_35 = V_2 -> V_36 ;
}
return V_9 ;
}
