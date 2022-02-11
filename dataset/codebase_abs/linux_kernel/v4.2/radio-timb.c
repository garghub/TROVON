static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , L_1 , sizeof( V_4 -> V_7 ) ) ;
snprintf ( V_4 -> V_8 , sizeof( V_4 -> V_8 ) , L_2 V_6 ) ;
V_4 -> V_9 = V_10 | V_11 ;
V_4 -> V_12 = V_4 -> V_9 | V_13 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , void * V_2 ,
struct V_14 * V_4 )
{
struct V_15 * V_16 = F_4 ( V_1 ) ;
return F_5 ( V_16 -> V_17 , V_18 , V_19 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_1 , void * V_2 ,
const struct V_14 * V_4 )
{
struct V_15 * V_16 = F_4 ( V_1 ) ;
return F_5 ( V_16 -> V_17 , V_18 , V_20 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_1 , void * V_2 ,
const struct V_21 * V_22 )
{
struct V_15 * V_16 = F_4 ( V_1 ) ;
return F_5 ( V_16 -> V_17 , V_18 , V_23 , V_22 ) ;
}
static int F_8 ( struct V_1 * V_1 , void * V_2 ,
struct V_21 * V_22 )
{
struct V_15 * V_16 = F_4 ( V_1 ) ;
return F_5 ( V_16 -> V_17 , V_18 , V_24 , V_22 ) ;
}
static int F_9 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = V_26 -> V_29 . V_30 ;
struct V_15 * V_16 ;
int V_31 ;
if ( ! V_28 ) {
F_10 ( & V_26 -> V_29 , L_3 ) ;
V_31 = - V_32 ;
goto V_31;
}
V_16 = F_11 ( & V_26 -> V_29 , sizeof( * V_16 ) , V_33 ) ;
if ( ! V_16 ) {
V_31 = - V_34 ;
goto V_31;
}
V_16 -> V_28 = * V_28 ;
F_12 ( & V_16 -> V_35 ) ;
F_2 ( V_16 -> V_36 . V_37 , L_1 ,
sizeof( V_16 -> V_36 . V_37 ) ) ;
V_16 -> V_36 . V_38 = & V_39 ;
V_16 -> V_36 . V_40 = & V_41 ;
V_16 -> V_36 . V_42 = V_43 ;
V_16 -> V_36 . V_44 = - 1 ;
V_16 -> V_36 . V_35 = & V_16 -> V_35 ;
F_2 ( V_16 -> V_45 . V_37 , V_6 , sizeof( V_16 -> V_45 . V_37 ) ) ;
V_31 = F_13 ( NULL , & V_16 -> V_45 ) ;
if ( V_31 )
goto V_31;
V_16 -> V_36 . V_45 = & V_16 -> V_45 ;
V_16 -> V_17 = F_14 ( & V_16 -> V_45 ,
F_15 ( V_28 -> V_46 ) , V_28 -> V_18 , NULL ) ;
V_16 -> V_47 = F_14 ( & V_16 -> V_45 ,
F_15 ( V_28 -> V_46 ) , V_28 -> V_48 , NULL ) ;
if ( V_16 -> V_17 == NULL || V_16 -> V_47 == NULL ) {
V_31 = - V_49 ;
goto V_50;
}
V_16 -> V_45 . V_51 = V_16 -> V_47 -> V_51 ;
V_31 = F_16 ( & V_16 -> V_36 , V_52 , - 1 ) ;
if ( V_31 ) {
F_10 ( & V_26 -> V_29 , L_4 ) ;
goto V_50;
}
F_17 ( & V_16 -> V_36 , V_16 ) ;
F_18 ( V_26 , V_16 ) ;
return 0 ;
V_50:
F_19 ( & V_16 -> V_45 ) ;
V_31:
F_10 ( & V_26 -> V_29 , L_5 , V_31 ) ;
return V_31 ;
}
static int F_20 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = F_21 ( V_26 ) ;
F_22 ( & V_16 -> V_36 ) ;
F_19 ( & V_16 -> V_45 ) ;
return 0 ;
}
