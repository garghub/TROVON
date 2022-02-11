int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_8 V_9 ;
int V_10 = 0 ;
int V_11 ;
int V_12 ;
int V_13 = 0 ;
int V_14 = 0 ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
if ( V_5 )
goto V_17;
if ( V_4 -> V_18 -> V_19 == V_4 ) {
goto V_17;
}
if ( V_4 -> V_20 == 0 && ! V_13 )
goto V_17;
if ( F_2 ( V_4 , V_21 ) )
goto V_17;
V_7 = F_3 () ;
if ( ! V_7 )
return - V_22 ;
V_12 = F_4 ( V_4 -> V_23 ) ;
if ( V_12 == 0 )
goto V_17;
if ( V_4 -> V_24 . V_25 == 0 ) {
struct V_26 * V_27 ;
T_2 V_28 ;
V_27 = F_5 ( V_4 ) ;
F_6 ( V_27 ) ;
V_28 = F_7 ( V_27 ) ;
V_4 -> V_29 . V_25 = 0 ;
F_8 ( V_27 , & V_4 -> V_29 ,
V_28 - 1 ) ;
F_9 ( V_27 ) ;
F_10 ( V_27 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
} else {
memcpy ( & V_9 , & V_4 -> V_24 , sizeof( V_9 ) ) ;
}
V_7 -> V_30 = 1 ;
if ( V_5 )
V_16 = V_4 -> V_31 ;
V_10 = F_11 ( V_4 , & V_9 , NULL , V_7 ,
V_5 , V_16 ) ;
if ( V_10 < 0 )
goto V_17;
if ( V_10 > 0 ) {
V_10 = 0 ;
goto V_17;
}
F_12 ( V_7 ) ;
V_11 = F_13 ( V_2 , V_4 , & V_9 , V_7 , 0 , 1 ) ;
if ( V_11 < 0 ) {
V_10 = V_11 ;
goto V_17;
}
if ( ! V_7 -> V_32 [ 1 ] ) {
V_10 = 0 ;
goto V_17;
}
V_7 -> V_33 [ 1 ] = F_7 ( V_7 -> V_32 [ 1 ] ) ;
V_14 = F_14 ( V_4 , V_7 , & V_9 , 1 , V_5 ,
V_16 ) ;
V_10 = F_15 ( V_2 , V_4 ,
V_7 -> V_32 [ 1 ] , 0 ,
V_5 , & V_15 ,
& V_4 -> V_24 ) ;
if ( V_10 ) {
F_16 ( V_10 == - V_34 ) ;
goto V_17;
}
if ( V_14 == 0 ) {
memcpy ( & V_4 -> V_24 , & V_9 , sizeof( V_9 ) ) ;
V_10 = - V_34 ;
}
V_17:
if ( V_7 )
F_17 ( V_7 ) ;
if ( V_10 == - V_34 ) {
if ( V_4 -> V_29 . V_25 > V_4 -> V_24 . V_25 )
goto V_35;
if ( V_4 -> V_29 . type > V_4 -> V_24 . type )
goto V_35;
if ( V_4 -> V_29 . V_36 > V_4 -> V_24 . V_36 )
goto V_35;
V_10 = 0 ;
}
V_35:
if ( V_10 != - V_34 ) {
memset ( & V_4 -> V_24 , 0 ,
sizeof( V_4 -> V_24 ) ) ;
V_4 -> V_31 = V_2 -> V_37 ;
}
return V_10 ;
}
