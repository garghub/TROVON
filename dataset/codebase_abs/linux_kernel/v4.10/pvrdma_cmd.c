static inline int F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
unsigned V_5 )
{
int V_6 ;
F_2 ( & V_2 -> V_7 -> V_2 , L_1 ) ;
V_6 = F_3 ( & V_2 -> V_8 ,
F_4 ( V_9 ) ) ;
if ( V_6 == 0 || V_6 == - V_10 ) {
F_5 ( & V_2 -> V_7 -> V_2 ,
L_2 ) ;
return - V_11 ;
}
F_6 ( & V_2 -> V_12 ) ;
memcpy ( V_4 , V_2 -> V_13 , sizeof( * V_4 ) ) ;
F_7 ( & V_2 -> V_12 ) ;
if ( V_4 -> V_14 . V_15 != V_5 ) {
F_5 ( & V_2 -> V_7 -> V_2 ,
L_3 ,
V_4 -> V_14 . V_15 , V_5 ) ;
return - V_16 ;
}
return 0 ;
}
int
F_8 ( struct V_1 * V_2 , union V_17 * V_18 ,
union V_3 * V_4 , unsigned V_5 )
{
int V_6 ;
F_2 ( & V_2 -> V_7 -> V_2 , L_4 ) ;
F_9 ( & V_2 -> V_19 ) ;
F_10 ( sizeof( union V_17 ) !=
sizeof( struct V_20 ) ) ;
F_6 ( & V_2 -> V_12 ) ;
memcpy ( V_2 -> V_21 , V_18 , sizeof( * V_18 ) ) ;
F_7 ( & V_2 -> V_12 ) ;
F_11 ( & V_2 -> V_8 ) ;
F_12 ( V_2 , V_22 , 0 ) ;
F_13 () ;
V_6 = F_14 ( V_2 , V_23 ) ;
if ( V_6 == 0 ) {
if ( V_4 != NULL )
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
} else {
F_5 ( & V_2 -> V_7 -> V_2 ,
L_5 , V_6 ) ;
V_6 = - V_16 ;
}
F_15 ( & V_2 -> V_19 ) ;
return V_6 ;
}
