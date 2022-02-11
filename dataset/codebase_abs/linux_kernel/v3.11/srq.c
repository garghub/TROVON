void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_10 ;
F_2 ( & V_6 -> V_11 ) ;
V_10 = F_3 ( & V_6 -> V_12 , V_3 ) ;
if ( V_10 )
F_4 ( & V_10 -> V_13 ) ;
F_5 ( & V_6 -> V_11 ) ;
if ( ! V_10 ) {
F_6 ( V_2 , L_1 , V_3 ) ;
return;
}
V_10 -> V_14 ( V_10 , V_4 ) ;
if ( F_7 ( & V_10 -> V_13 ) )
F_8 ( & V_10 -> free ) ;
}
struct V_9 * F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_10 ;
F_2 ( & V_6 -> V_11 ) ;
V_10 = F_3 ( & V_6 -> V_12 , V_3 ) ;
if ( V_10 )
F_4 ( & V_10 -> V_13 ) ;
F_5 ( & V_6 -> V_11 ) ;
return V_10 ;
}
int F_10 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_16 , int V_17 )
{
struct V_18 V_19 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_20 V_21 ;
struct V_22 V_23 ;
int V_24 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_16 -> V_25 . V_26 = F_11 ( V_27 ) ;
V_24 = F_12 ( V_2 , V_16 , V_17 , & V_19 , sizeof( V_19 ) ) ;
if ( V_24 )
return V_24 ;
if ( V_19 . V_25 . V_28 )
return F_13 ( & V_19 . V_25 ) ;
V_10 -> V_3 = F_14 ( V_19 . V_3 ) & 0xffffff ;
F_15 ( & V_10 -> V_13 , 1 ) ;
F_16 ( & V_10 -> free ) ;
F_17 ( & V_6 -> V_11 ) ;
V_24 = F_18 ( & V_6 -> V_12 , V_10 -> V_3 , V_10 ) ;
F_19 ( & V_6 -> V_11 ) ;
if ( V_24 ) {
F_6 ( V_2 , L_2 , V_24 , V_10 -> V_3 ) ;
goto V_29;
}
return 0 ;
V_29:
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_21 . V_3 = F_20 ( V_10 -> V_3 ) ;
V_21 . V_25 . V_26 = F_11 ( V_30 ) ;
F_12 ( V_2 , & V_21 , sizeof( V_21 ) , & V_23 , sizeof( V_23 ) ) ;
return V_24 ;
}
int F_21 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_20 V_16 ;
struct V_22 V_19 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_31 ;
int V_24 ;
F_17 ( & V_6 -> V_11 ) ;
V_31 = F_22 ( & V_6 -> V_12 , V_10 -> V_3 ) ;
F_19 ( & V_6 -> V_11 ) ;
if ( ! V_31 ) {
F_6 ( V_2 , L_3 , V_10 -> V_3 ) ;
return - V_32 ;
}
if ( V_31 != V_10 ) {
F_6 ( V_2 , L_4 , V_10 -> V_3 ) ;
return - V_32 ;
}
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_16 . V_25 . V_26 = F_11 ( V_30 ) ;
V_16 . V_3 = F_20 ( V_10 -> V_3 ) ;
V_24 = F_12 ( V_2 , & V_16 , sizeof( V_16 ) , & V_19 , sizeof( V_19 ) ) ;
if ( V_24 )
return V_24 ;
if ( V_19 . V_25 . V_28 )
return F_13 ( & V_19 . V_25 ) ;
if ( F_7 ( & V_10 -> V_13 ) )
F_8 ( & V_10 -> free ) ;
F_23 ( & V_10 -> free ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_33 * V_19 )
{
struct V_34 V_16 ;
int V_24 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_16 . V_25 . V_26 = F_11 ( V_35 ) ;
V_16 . V_3 = F_20 ( V_10 -> V_3 ) ;
V_24 = F_12 ( V_2 , & V_16 , sizeof( V_16 ) , V_19 , sizeof( * V_19 ) ) ;
if ( V_24 )
return V_24 ;
if ( V_19 -> V_25 . V_28 )
return F_13 ( & V_19 -> V_25 ) ;
return V_24 ;
}
int F_25 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_36 , int V_37 )
{
struct V_38 V_16 ;
struct V_39 V_19 ;
int V_24 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_16 . V_25 . V_26 = F_11 ( V_40 ) ;
V_16 . V_25 . V_41 = F_11 ( ! ! V_37 ) ;
V_16 . V_3 = F_20 ( V_10 -> V_3 ) ;
V_16 . V_36 = F_11 ( V_36 ) ;
V_24 = F_12 ( V_2 , & V_16 , sizeof( V_16 ) , & V_19 , sizeof( V_19 ) ) ;
if ( V_24 )
return V_24 ;
if ( V_19 . V_25 . V_28 )
return F_13 ( & V_19 . V_25 ) ;
return V_24 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
F_27 ( & V_6 -> V_11 ) ;
F_28 ( & V_6 -> V_12 , V_42 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
}
