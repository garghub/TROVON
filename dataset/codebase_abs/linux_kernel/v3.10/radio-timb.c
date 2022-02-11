static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , L_1 , sizeof( V_4 -> V_7 ) ) ;
snprintf ( V_4 -> V_8 , sizeof( V_4 -> V_8 ) , L_2 V_6 ) ;
V_4 -> V_9 = V_10 | V_11 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , void * V_2 ,
struct V_12 * V_4 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_15 , V_16 , V_17 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_1 , void * V_2 ,
const struct V_12 * V_4 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_15 , V_16 , V_18 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_19 , void * V_2 ,
unsigned int * V_20 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_19 , void * V_2 ,
unsigned int V_20 )
{
return V_20 ? - V_21 : 0 ;
}
static int F_9 ( struct V_1 * V_1 , void * V_2 ,
struct V_22 * V_23 )
{
V_23 -> V_24 = 0 ;
F_2 ( V_23 -> V_25 , L_3 , sizeof( V_23 -> V_25 ) ) ;
V_23 -> V_26 = V_27 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , void * V_2 ,
const struct V_22 * V_23 )
{
return V_23 -> V_24 ? - V_21 : 0 ;
}
static int F_11 ( struct V_1 * V_1 , void * V_2 ,
const struct V_28 * V_29 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_15 , V_16 , V_30 , V_29 ) ;
}
static int F_12 ( struct V_1 * V_1 , void * V_2 ,
struct V_28 * V_29 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_15 , V_16 , V_31 , V_29 ) ;
}
static int F_13 ( struct V_1 * V_1 , void * V_2 ,
struct V_32 * V_33 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_34 , V_35 , V_36 , V_33 ) ;
}
static int F_14 ( struct V_1 * V_1 , void * V_2 ,
struct V_37 * V_38 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_34 , V_35 , V_39 , V_38 ) ;
}
static int F_15 ( struct V_1 * V_1 , void * V_2 ,
struct V_37 * V_38 )
{
struct V_13 * V_14 = F_4 ( V_1 ) ;
return F_5 ( V_14 -> V_34 , V_35 , V_40 , V_38 ) ;
}
static int F_16 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 . V_46 ;
struct V_13 * V_14 ;
int V_47 ;
if ( ! V_44 ) {
F_17 ( & V_42 -> V_45 , L_4 ) ;
V_47 = - V_21 ;
goto V_47;
}
V_14 = F_18 ( & V_42 -> V_45 , sizeof( * V_14 ) , V_48 ) ;
if ( ! V_14 ) {
V_47 = - V_49 ;
goto V_47;
}
V_14 -> V_44 = * V_44 ;
F_19 ( & V_14 -> V_50 ) ;
F_2 ( V_14 -> V_51 . V_25 , L_1 ,
sizeof( V_14 -> V_51 . V_25 ) ) ;
V_14 -> V_51 . V_52 = & V_53 ;
V_14 -> V_51 . V_54 = & V_55 ;
V_14 -> V_51 . V_56 = V_57 ;
V_14 -> V_51 . V_58 = - 1 ;
V_14 -> V_51 . V_50 = & V_14 -> V_50 ;
F_2 ( V_14 -> V_59 . V_25 , V_6 , sizeof( V_14 -> V_59 . V_25 ) ) ;
V_47 = F_20 ( NULL , & V_14 -> V_59 ) ;
if ( V_47 )
goto V_47;
V_14 -> V_51 . V_59 = & V_14 -> V_59 ;
V_47 = F_21 ( & V_14 -> V_51 , V_60 , - 1 ) ;
if ( V_47 ) {
F_17 ( & V_42 -> V_45 , L_5 ) ;
goto V_61;
}
F_22 ( & V_14 -> V_51 , V_14 ) ;
F_23 ( V_42 , V_14 ) ;
return 0 ;
V_61:
V_57 ( & V_14 -> V_51 ) ;
F_24 ( & V_14 -> V_59 ) ;
V_47:
F_17 ( & V_42 -> V_45 , L_6 , V_47 ) ;
return V_47 ;
}
static int F_25 ( struct V_41 * V_42 )
{
struct V_13 * V_14 = F_26 ( V_42 ) ;
F_27 ( & V_14 -> V_51 ) ;
V_57 ( & V_14 -> V_51 ) ;
F_24 ( & V_14 -> V_59 ) ;
return 0 ;
}
