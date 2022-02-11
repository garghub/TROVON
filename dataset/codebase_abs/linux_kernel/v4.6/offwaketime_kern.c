int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) F_2 ( V_2 ) ;
struct V_5 V_6 = {} ;
T_1 V_7 ;
V_7 = _ ( V_4 -> V_7 ) ;
F_3 ( & V_6 . V_8 , sizeof( V_6 . V_8 ) ) ;
V_6 . V_9 = F_4 ( V_2 , & V_10 , V_11 ) ;
F_5 ( & V_12 , & V_7 , & V_6 , V_13 ) ;
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_14 )
{
struct V_15 V_16 = {} ;
struct V_5 * V_6 ;
T_2 V_17 = 0 , * V_18 ;
F_3 ( & V_16 . V_19 , sizeof( V_16 . V_19 ) ) ;
V_16 . V_20 = F_4 ( V_2 , & V_10 , V_11 ) ;
V_6 = F_7 ( & V_12 , & V_7 ) ;
if ( V_6 ) {
V_16 . V_21 = V_6 -> V_9 ;
F_8 ( & V_16 . F_1 , V_6 -> V_8 , V_22 ) ;
F_9 ( & V_12 , & V_7 ) ;
}
V_18 = F_7 ( & V_23 , & V_16 ) ;
if ( ! V_18 ) {
F_5 ( & V_23 , & V_16 , & V_17 , V_24 ) ;
V_18 = F_7 ( & V_23 , & V_16 ) ;
if ( ! V_18 )
return 0 ;
}
( * V_18 ) += V_14 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) F_2 ( V_2 ) ;
T_2 V_14 , V_25 , * V_26 ;
T_1 V_7 ;
V_7 = _ ( V_4 -> V_7 ) ;
V_25 = F_11 () ;
F_5 ( & V_27 , & V_7 , & V_25 , V_13 ) ;
V_7 = F_12 () ;
V_26 = F_7 ( & V_27 , & V_7 ) ;
if ( ! V_26 )
return 0 ;
V_14 = F_11 () - * V_26 ;
F_9 ( & V_27 , & V_7 ) ;
V_14 = V_14 / 1000 ;
if ( V_14 < V_28 )
return 0 ;
return F_6 ( V_2 , V_7 , V_14 ) ;
}
