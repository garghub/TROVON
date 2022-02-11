static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_2 -> type == V_6 ) {
struct V_7 * V_8 ;
V_8 = & V_2 -> V_3 . V_9 ;
if ( V_8 -> type == V_10 ) {
V_5 -> V_11 = V_8 -> V_12 ;
if ( V_8 -> V_13 == V_14 )
V_5 -> V_15 |= V_16 ;
}
} else if ( V_5 -> V_17 < 0 ) {
struct V_18 V_19 ;
if ( F_2 ( V_2 , 0 , & V_19 ) )
V_5 -> V_17 = V_19 . V_20 ;
}
return 1 ;
}
static T_1 F_3 ( T_2 V_21 , T_3 V_22 ,
void * V_3 , void * * V_23 )
{
struct V_24 * V_25 = V_3 ;
struct V_26 V_27 ;
struct V_4 V_5 ;
struct V_28 * V_29 ;
int V_30 ;
if ( F_4 ( V_21 , & V_29 ) )
return V_31 ;
if ( F_5 ( V_29 ) || ! V_29 -> V_32 . V_33 )
return V_31 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_34 . V_21 = V_21 ;
V_5 . V_17 = - 1 ;
F_6 ( & V_27 ) ;
V_30 = F_7 ( V_29 , & V_27 ,
F_1 , & V_5 ) ;
F_8 ( & V_27 ) ;
if ( V_30 < 0 || ! V_5 . V_11 )
return V_31 ;
F_9 ( V_5 . type , F_10 ( & V_29 -> V_35 ) , sizeof( V_5 . type ) ) ;
if ( ! F_11 ( V_25 , & V_5 ) ) {
F_12 ( & V_25 -> V_35 ,
L_1 ,
F_10 ( & V_29 -> V_35 ) ) ;
}
return V_31 ;
}
void F_13 ( struct V_24 * V_25 )
{
T_2 V_21 ;
T_1 V_32 ;
V_21 = F_14 ( V_25 -> V_35 . V_36 ) ;
if ( ! V_21 )
return;
V_32 = F_15 ( V_37 , V_21 , 1 ,
F_3 , NULL ,
V_25 , NULL ) ;
if ( F_16 ( V_32 ) )
F_17 ( & V_25 -> V_35 , L_2 ) ;
}
