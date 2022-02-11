static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( F_3 ( V_2 ) )
return - V_8 ;
V_7 = V_6 -> V_9 . V_10 -> V_11 ( V_6 , V_2 ) ;
if ( V_7 )
return V_7 ;
V_3 -> V_12 = V_2 ;
V_2 -> V_3 = V_3 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_5 ( ! F_3 ( V_2 ) ) ;
if ( ! F_3 ( V_2 ) )
return;
F_5 ( V_3 != V_2 -> V_3 ) ;
if ( V_3 != V_2 -> V_3 )
return;
V_3 -> V_12 = NULL ;
V_2 -> V_3 = NULL ;
V_6 -> V_9 . V_10 -> V_13 ( V_6 , & V_5 -> V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_7 ;
if ( ! F_3 ( V_2 ) )
return - V_14 ;
if ( F_7 ( V_2 ) )
return 0 ;
V_6 -> V_9 . V_10 -> V_15 ( V_6 , & V_5 -> V_16 ) ;
if ( V_5 -> V_17 )
V_6 -> V_9 . V_10 -> V_18 ( V_6 , V_5 -> V_17 ) ;
V_7 = V_6 -> V_9 . V_10 -> V_19 ( V_6 ) ;
if ( V_7 )
return V_7 ;
if ( F_8 ( V_5 -> V_20 ) )
F_9 ( V_5 -> V_20 , 1 ) ;
V_2 -> V_21 = V_22 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
if ( ! F_7 ( V_2 ) )
return;
if ( F_8 ( V_5 -> V_20 ) )
F_9 ( V_5 -> V_20 , 0 ) ;
V_6 -> V_9 . V_10 -> V_23 ( V_6 ) ;
V_2 -> V_21 = V_24 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_25 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
V_5 -> V_16 = * V_16 ;
V_2 -> V_26 . V_16 = * V_16 ;
V_6 -> V_9 . V_10 -> V_15 ( V_6 , V_16 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_25 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_16 = V_5 -> V_16 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_25 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_1 * V_6 = V_5 -> V_6 ;
return V_6 -> V_9 . V_10 -> V_27 ( V_6 , V_16 ) ;
}
static int F_14 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_15 ( V_29 ) ;
struct V_30 * V_31 ;
struct V_1 * V_2 , * V_6 ;
V_31 = F_16 ( & V_29 -> V_32 ) ;
V_5 -> V_20 = V_31 -> V_33 ;
V_5 -> V_17 = V_31 -> V_17 ;
V_6 = F_17 ( V_31 -> V_34 ) ;
if ( V_6 == NULL ) {
F_18 ( & V_29 -> V_32 , L_1 ) ;
return - V_14 ;
}
V_5 -> V_6 = V_6 ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_35 = V_31 -> V_35 ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_15 ( V_29 ) ;
struct V_36 * V_37 = V_29 -> V_32 . V_38 ;
struct V_1 * V_6 ;
int V_39 ;
V_39 = F_20 ( V_37 , L_2 , 0 ) ;
if ( F_8 ( V_39 ) || V_39 == - V_40 ) {
V_5 -> V_20 = V_39 ;
} else {
F_18 ( & V_29 -> V_32 , L_3 ) ;
return V_39 ;
}
V_6 = F_21 ( V_37 ) ;
if ( F_22 ( V_6 ) ) {
F_18 ( & V_29 -> V_32 , L_4 ) ;
return F_23 ( V_6 ) ;
}
V_5 -> V_6 = V_6 ;
return 0 ;
}
static int F_24 ( struct V_28 * V_29 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_7 ;
V_5 = F_25 ( & V_29 -> V_32 , sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
F_26 ( V_29 , V_5 ) ;
if ( F_16 ( & V_29 -> V_32 ) ) {
V_7 = F_14 ( V_29 ) ;
if ( V_7 )
return V_7 ;
} else if ( V_29 -> V_32 . V_38 ) {
V_7 = F_19 ( V_29 ) ;
if ( V_7 )
return V_7 ;
} else {
return - V_14 ;
}
if ( F_8 ( V_5 -> V_20 ) ) {
V_7 = F_27 ( & V_29 -> V_32 , V_5 -> V_20 ,
V_43 , L_5 ) ;
if ( V_7 ) {
F_18 ( & V_29 -> V_32 , L_6 ,
V_5 -> V_20 ) ;
goto V_44;
}
}
V_2 = & V_5 -> V_2 ;
V_2 -> V_9 . V_45 = & V_46 ;
V_2 -> V_32 = & V_29 -> V_32 ;
V_2 -> type = V_47 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = V_51 ;
V_2 -> V_52 . V_10 . V_17 = V_5 -> V_17 ;
V_2 -> V_53 = 1 ;
V_7 = F_28 ( V_2 ) ;
if ( V_7 ) {
F_18 ( & V_29 -> V_32 , L_7 ) ;
goto V_54;
}
return 0 ;
V_54:
V_44:
F_29 ( V_5 -> V_6 ) ;
return V_7 ;
}
static int T_1 F_30 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_15 ( V_29 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_1 * V_6 = V_5 -> V_6 ;
F_31 ( & V_5 -> V_2 ) ;
F_5 ( F_7 ( V_2 ) ) ;
if ( F_7 ( V_2 ) )
F_10 ( V_2 ) ;
F_5 ( F_3 ( V_2 ) ) ;
if ( F_3 ( V_2 ) )
F_4 ( V_2 , V_2 -> V_3 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
