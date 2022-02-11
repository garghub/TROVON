static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( F_3 ( V_2 ) )
return 0 ;
V_6 = V_5 -> V_7 . V_8 -> V_9 ( V_5 , V_2 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_3 ( V_2 ) )
return;
V_5 -> V_7 . V_8 -> V_10 ( V_5 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! F_3 ( V_2 ) )
return - V_11 ;
if ( F_6 ( V_2 ) )
return 0 ;
if ( V_4 -> V_12 )
V_5 -> V_7 . V_8 -> V_13 ( V_5 , V_4 -> V_12 ) ;
V_5 -> V_7 . V_8 -> V_14 ( V_5 , & V_4 -> V_15 ) ;
V_6 = V_5 -> V_7 . V_8 -> V_16 ( V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_17 )
F_7 ( V_4 -> V_17 , 1 ) ;
if ( F_8 ( V_4 -> V_18 ) )
F_9 ( V_4 -> V_18 , 1 ) ;
V_2 -> V_19 = V_20 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
if ( ! F_6 ( V_2 ) )
return;
if ( V_4 -> V_17 )
F_7 ( V_4 -> V_17 , 0 ) ;
if ( F_8 ( V_4 -> V_18 ) )
F_9 ( V_4 -> V_18 , 0 ) ;
V_5 -> V_7 . V_8 -> V_21 ( V_5 ) ;
V_2 -> V_19 = V_22 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
V_4 -> V_15 = * V_24 ;
V_2 -> V_25 . V_24 = * V_24 ;
V_5 -> V_7 . V_8 -> V_14 ( V_5 , V_24 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_24 = V_4 -> V_15 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
return V_5 -> V_7 . V_8 -> V_26 ( V_5 , V_24 ) ;
}
static int F_14 ( struct V_27 * V_28 )
{
const struct V_29 * V_30 ;
struct V_3 * V_4 = F_15 ( V_28 ) ;
struct V_1 * V_2 , * V_5 ;
struct V_15 V_31 ;
int V_6 ;
V_30 = F_16 ( & V_28 -> V_32 ) ;
V_5 = F_17 ( V_30 -> V_33 ) ;
if ( V_5 == NULL ) {
F_18 ( & V_28 -> V_32 , L_1 ,
V_30 -> V_33 ) ;
return - V_34 ;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_12 = V_30 -> V_12 ;
F_19 ( V_30 -> V_35 , & V_31 ) ;
F_20 ( & V_31 , & V_4 -> V_15 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_36 = V_30 -> V_36 ;
V_6 = F_21 ( & V_28 -> V_32 , V_30 -> V_17 ,
V_37 , L_2 ) ;
if ( V_6 )
goto V_38;
V_4 -> V_17 = F_22 ( V_30 -> V_17 ) ;
V_4 -> V_18 = V_30 -> V_18 ;
return 0 ;
V_38:
F_23 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int F_24 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_15 ( V_28 ) ;
struct V_39 * V_40 = V_28 -> V_32 . V_41 ;
struct V_1 * V_5 ;
int V_6 ;
struct V_35 V_42 ;
struct V_15 V_31 ;
struct V_43 * V_44 ;
V_44 = F_25 ( & V_28 -> V_32 , L_3 ) ;
if ( F_26 ( V_44 ) ) {
if ( F_27 ( V_44 ) != - V_45 )
return F_27 ( V_44 ) ;
else
V_44 = NULL ;
} else {
F_28 ( V_44 , 0 ) ;
}
V_4 -> V_17 = V_44 ;
V_4 -> V_18 = - V_45 ;
V_6 = F_29 ( V_40 , L_4 , & V_42 ) ;
if ( V_6 ) {
F_18 ( & V_28 -> V_32 , L_5 ) ;
return V_6 ;
}
F_19 ( & V_42 , & V_31 ) ;
F_20 ( & V_31 , & V_4 -> V_15 ) ;
V_5 = F_30 ( V_40 ) ;
if ( F_26 ( V_5 ) ) {
F_18 ( & V_28 -> V_32 , L_6 ) ;
return F_27 ( V_5 ) ;
}
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_31 ( struct V_27 * V_28 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_6 ;
V_4 = F_32 ( & V_28 -> V_32 , sizeof( * V_4 ) , V_46 ) ;
if ( V_4 == NULL )
return - V_47 ;
F_33 ( V_28 , V_4 ) ;
if ( F_16 ( & V_28 -> V_32 ) ) {
V_6 = F_14 ( V_28 ) ;
if ( V_6 )
return V_6 ;
} else if ( V_28 -> V_32 . V_41 ) {
V_6 = F_24 ( V_28 ) ;
if ( V_6 )
return V_6 ;
} else {
return - V_11 ;
}
if ( F_8 ( V_4 -> V_18 ) ) {
V_6 = F_21 ( & V_28 -> V_32 , V_4 -> V_18 ,
V_37 , L_7 ) ;
if ( V_6 )
goto V_38;
}
V_2 = & V_4 -> V_2 ;
V_2 -> V_32 = & V_28 -> V_32 ;
V_2 -> V_48 = & V_49 ;
V_2 -> type = V_50 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_25 . V_24 = V_4 -> V_15 ;
V_2 -> V_53 . V_8 . V_12 = V_4 -> V_12 ;
V_6 = F_34 ( V_2 ) ;
if ( V_6 ) {
F_18 ( & V_28 -> V_32 , L_8 ) ;
goto V_54;
}
return 0 ;
V_54:
V_38:
F_23 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int T_1 F_35 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_15 ( V_28 ) ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_5 = V_4 -> V_5 ;
F_36 ( V_2 ) ;
F_10 ( V_2 ) ;
F_4 ( V_2 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
