static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
return F_2 ( V_2 -> V_6 ,
V_7 ,
V_2 -> type ,
V_2 -> V_8 ,
V_4 , V_5 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_3 V_4 ;
int V_11 ;
V_4 . V_12 = F_5 ( V_13 ) ;
V_4 . V_14 = F_5 ( sizeof( V_15 ) ) ;
V_4 . V_16 = F_5 ( 1 ) ;
V_11 = F_1 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( ! V_11 )
V_2 -> V_17 = 1 ;
return V_11 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
return V_2 -> V_17 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_3 V_4 ;
int V_11 ;
V_4 . V_12 = F_5 ( V_13 ) ;
V_4 . V_14 = F_5 ( sizeof( V_15 ) ) ;
V_4 . V_16 = 0 ;
V_11 = F_1 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( ! V_11 )
V_2 -> V_17 = 0 ;
return V_11 ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
return V_2 -> V_18 ;
}
static int F_9 ( struct V_9 * V_10 ,
int V_19 ,
int V_20 ,
unsigned * V_21 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_3 V_4 ;
int V_11 = 0 ;
V_4 . V_12 = F_5 ( V_22 ) ;
V_4 . V_14 = F_5 ( sizeof( V_15 ) ) ;
V_4 . V_16 = F_5 ( V_19 ) ;
V_11 = F_1 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( ! V_11 )
V_2 -> V_18 = V_19 ;
return V_11 ;
}
static int F_10 ( struct V_9 * V_10 , int V_23 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_3 V_4 ;
V_4 . V_12 = F_5 ( V_24 ) ;
V_4 . V_14 = F_5 ( sizeof( V_15 ) ) ;
V_4 . V_16 = F_5 ( V_23 / 1000 ) ;
return F_1 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
}
static int F_11 ( struct V_25 * V_26 )
{
const struct V_27 * V_28 ;
const struct V_29 * V_30 ;
struct V_31 V_32 = { } ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_33 * V_6 ;
V_6 = F_12 ( V_26 -> V_34 . V_35 ) ;
if ( ! V_6 ) {
F_13 ( & V_26 -> V_34 , L_1 ) ;
return - V_36 ;
}
V_30 = F_14 ( V_37 , & V_26 -> V_34 ) ;
for ( V_28 = V_30 -> V_38 ; V_28 -> V_39 ; V_28 ++ ) {
V_2 = F_15 ( & V_26 -> V_34 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_2 -> V_34 = & V_26 -> V_34 ;
V_2 -> type = V_28 -> type ;
V_2 -> V_8 = V_28 -> V_8 ;
V_2 -> V_6 = V_6 ;
memcpy ( & V_2 -> V_42 , V_28 -> V_42 , sizeof( V_2 -> V_42 ) ) ;
V_2 -> V_42 . V_8 = - 1 ;
V_2 -> V_42 . V_43 = V_44 ;
V_2 -> V_42 . type = V_45 ;
V_2 -> V_42 . V_39 = V_28 -> V_39 ;
V_2 -> V_42 . V_46 = V_28 -> V_47 ;
V_2 -> V_42 . V_48 = V_28 -> V_39 ;
V_32 . V_34 = & V_26 -> V_34 ;
V_32 . V_49 = V_2 ;
V_10 = F_16 ( & V_26 -> V_34 , & V_2 -> V_42 , & V_32 ) ;
if ( F_17 ( V_10 ) ) {
F_13 ( & V_26 -> V_34 , L_2 , V_28 -> V_39 ) ;
return F_18 ( V_10 ) ;
}
}
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_50 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_50 ) ;
}
