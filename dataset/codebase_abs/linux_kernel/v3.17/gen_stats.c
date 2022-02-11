static inline int
F_1 ( struct V_1 * V_2 , int type , void * V_3 , int V_4 )
{
if ( F_2 ( V_2 -> V_5 , type , V_4 , V_3 ) )
goto V_6;
return 0 ;
V_6:
F_3 ( V_2 -> V_7 ) ;
return - 1 ;
}
int
F_4 ( struct V_8 * V_5 , int type , int V_9 ,
int V_10 , T_1 * V_7 , struct V_1 * V_2 )
__acquires( V_7 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_5 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
if ( type )
V_2 -> V_11 = (struct V_12 * ) F_6 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = V_9 ;
V_2 -> V_14 = V_10 ;
if ( V_2 -> V_11 )
return F_1 ( V_2 , type , NULL , 0 ) ;
return 0 ;
}
int
F_7 ( struct V_8 * V_5 , int type , T_1 * V_7 ,
struct V_1 * V_2 )
{
return F_4 ( V_5 , type , 0 , 0 , V_7 , V_2 ) ;
}
int
F_8 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
if ( V_2 -> V_13 ) {
V_2 -> V_17 . V_18 = V_16 -> V_18 ;
V_2 -> V_17 . V_19 = V_16 -> V_19 ;
}
if ( V_2 -> V_11 ) {
struct V_20 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_18 = V_16 -> V_18 ;
V_21 . V_19 = V_16 -> V_19 ;
return F_1 ( V_2 , V_22 , & V_21 , sizeof( V_21 ) ) ;
}
return 0 ;
}
int
F_9 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
struct V_23 * V_24 )
{
struct V_25 V_26 ;
int V_27 ;
if ( V_16 && ! F_10 ( V_16 , V_24 ) )
return 0 ;
V_26 . V_28 = F_11 ( V_29 , V_30 , V_24 -> V_28 ) ;
V_26 . V_31 = V_24 -> V_31 ;
if ( V_2 -> V_13 ) {
V_2 -> V_17 . V_28 = V_26 . V_28 ;
V_2 -> V_17 . V_31 = V_26 . V_31 ;
}
if ( V_2 -> V_11 ) {
V_27 = F_1 ( V_2 , V_32 , & V_26 , sizeof( V_26 ) ) ;
if ( V_27 < 0 || V_26 . V_28 == V_24 -> V_28 )
return V_27 ;
return F_1 ( V_2 , V_33 , V_24 , sizeof( * V_24 ) ) ;
}
return 0 ;
}
int
F_12 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
if ( V_2 -> V_13 ) {
V_2 -> V_17 . V_36 = V_35 -> V_36 ;
V_2 -> V_17 . V_37 = V_35 -> V_37 ;
V_2 -> V_17 . V_38 = V_35 -> V_38 ;
V_2 -> V_17 . V_39 = V_35 -> V_39 ;
}
if ( V_2 -> V_11 )
return F_1 ( V_2 , V_40 , V_35 , sizeof( * V_35 ) ) ;
return 0 ;
}
int
F_13 ( struct V_1 * V_2 , void * V_41 , int V_42 )
{
if ( V_2 -> V_14 ) {
V_2 -> V_43 = V_41 ;
V_2 -> V_44 = V_42 ;
}
if ( V_2 -> V_11 )
return F_1 ( V_2 , V_45 , V_41 , V_42 ) ;
return 0 ;
}
int
F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_46 = F_6 ( V_2 -> V_5 ) - ( V_47 * ) V_2 -> V_11 ;
if ( V_2 -> V_13 )
if ( F_1 ( V_2 , V_2 -> V_13 , & V_2 -> V_17 ,
sizeof( V_2 -> V_17 ) ) < 0 )
return - 1 ;
if ( V_2 -> V_14 && V_2 -> V_43 ) {
if ( F_1 ( V_2 , V_2 -> V_14 , V_2 -> V_43 ,
V_2 -> V_44 ) < 0 )
return - 1 ;
}
F_3 ( V_2 -> V_7 ) ;
return 0 ;
}
