static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , L_1 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_6 , L_2 ,
sizeof( V_4 -> V_6 ) ) ;
F_2 ( V_4 -> V_7 , L_3 ,
sizeof( V_4 -> V_7 ) ) ;
V_4 -> V_8 = V_9 | V_10 ;
V_4 -> V_11 = V_4 -> V_8 | V_12 ;
return 0 ;
}
static inline struct V_13 * F_3 ( struct V_1 * V_1 )
{
return & ( (struct V_14 * ) F_4 ( V_1 ) ) -> V_15 ;
}
static int F_5 ( struct V_1 * V_1 , void * V_16 ,
struct V_17 * V_18 )
{
return F_6 ( F_3 ( V_1 ) , 0 , V_19 ,
V_20 , V_18 ) ;
}
static int F_7 ( struct V_1 * V_1 , void * V_16 ,
const struct V_17 * V_18 )
{
return F_6 ( F_3 ( V_1 ) , 0 , V_19 ,
V_21 , V_18 ) ;
}
static int F_8 ( struct V_1 * V_1 , void * V_16 ,
struct V_22 * V_23 )
{
return F_6 ( F_3 ( V_1 ) , 0 , V_19 ,
V_24 , V_23 ) ;
}
static int F_9 ( struct V_1 * V_1 , void * V_16 ,
const struct V_22 * V_23 )
{
return F_6 ( F_3 ( V_1 ) , 0 , V_19 ,
V_25 , V_23 ) ;
}
static long F_10 ( struct V_1 * V_1 , void * V_16 ,
bool V_26 , unsigned int V_27 , void * V_28 )
{
return F_6 ( F_3 ( V_1 ) , 0 , V_29 ,
V_30 , V_27 , V_28 ) ;
}
static int F_11 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 . V_36 ;
struct V_14 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
int V_42 = 0 ;
if ( ! V_34 ) {
F_12 ( & V_32 -> V_35 , L_4 ) ;
V_42 = - V_43 ;
goto exit;
}
V_37 = F_13 ( & V_32 -> V_35 , sizeof( * V_37 ) , V_44 ) ;
if ( ! V_37 ) {
F_12 ( & V_32 -> V_35 , L_5 ) ;
V_42 = - V_45 ;
goto exit;
}
F_14 ( & V_37 -> V_46 ) ;
V_42 = F_15 ( & V_32 -> V_35 , & V_37 -> V_15 ) ;
if ( V_42 ) {
F_12 ( & V_32 -> V_35 , L_6 ) ;
goto exit;
}
V_39 = F_16 ( V_34 -> V_47 ) ;
if ( ! V_39 ) {
F_12 ( & V_32 -> V_35 , L_7 ,
V_34 -> V_47 ) ;
V_42 = - V_48 ;
goto V_49;
}
V_41 = F_17 ( & V_37 -> V_15 , V_39 ,
V_34 -> V_50 , NULL ) ;
if ( ! V_41 ) {
F_12 ( & V_32 -> V_35 , L_8 ) ;
V_42 = - V_48 ;
goto V_51;
}
V_37 -> V_52 = V_53 ;
V_37 -> V_52 . V_15 = & V_37 -> V_15 ;
V_37 -> V_52 . V_54 = V_41 -> V_54 ;
V_37 -> V_52 . V_46 = & V_37 -> V_46 ;
F_18 ( & V_37 -> V_52 , V_37 ) ;
if ( F_19 ( & V_37 -> V_52 , V_55 , V_56 ) ) {
F_12 ( & V_32 -> V_35 , L_9 ) ;
V_42 = - V_57 ;
goto V_51;
}
F_20 ( & V_32 -> V_35 , L_10 ) ;
goto exit;
V_51:
F_21 ( V_39 ) ;
V_49:
F_22 ( & V_37 -> V_15 ) ;
exit:
return V_42 ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_13 * V_15 = F_24 ( V_32 ) ;
struct V_40 * V_41 = F_25 ( V_15 -> V_58 . V_59 ,
struct V_40 , V_60 ) ;
struct V_61 * V_62 = F_26 ( V_41 ) ;
struct V_14 * V_37 ;
V_37 = F_27 ( V_15 , struct V_14 , V_15 ) ;
F_28 ( & V_37 -> V_52 ) ;
F_21 ( V_62 -> V_39 ) ;
F_22 ( & V_37 -> V_15 ) ;
return 0 ;
}
