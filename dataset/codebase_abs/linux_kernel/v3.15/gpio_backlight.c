static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( V_2 -> V_6 . V_7 != V_8 ||
V_2 -> V_6 . V_9 != V_8 ||
V_2 -> V_6 . V_10 & ( V_11 | V_12 ) )
V_5 = 0 ;
F_3 ( V_4 -> V_13 , V_5 ? V_4 -> V_14 : ! V_4 -> V_14 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_6 . V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_17 == NULL || V_4 -> V_17 == V_16 -> V_18 ;
}
static int F_6 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_20 -> V_18 . V_23 ;
enum V_24 V_25 ;
V_4 -> V_13 = F_7 ( V_22 , 0 , & V_25 ) ;
if ( ! F_8 ( V_4 -> V_13 ) ) {
if ( V_4 -> V_13 != - V_26 ) {
F_9 ( & V_20 -> V_18 ,
L_1 ) ;
}
return V_4 -> V_13 ;
}
V_4 -> V_14 = ( V_25 & V_27 ) ? 0 : 1 ;
V_4 -> V_28 = F_10 ( V_22 , L_2 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_29 * V_30 =
F_12 ( & V_20 -> V_18 ) ;
struct V_31 V_6 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_21 * V_22 = V_20 -> V_18 . V_23 ;
int V_32 ;
if ( ! V_30 && ! V_22 ) {
F_9 ( & V_20 -> V_18 ,
L_3 ) ;
return - V_33 ;
}
V_4 = F_13 ( & V_20 -> V_18 , sizeof( * V_4 ) , V_34 ) ;
if ( V_4 == NULL )
return - V_35 ;
V_4 -> V_18 = & V_20 -> V_18 ;
if ( V_22 ) {
V_32 = F_6 ( V_20 , V_4 ) ;
if ( V_32 )
return V_32 ;
} else {
V_4 -> V_17 = V_30 -> V_17 ;
V_4 -> V_13 = V_30 -> V_13 ;
V_4 -> V_14 = V_30 -> V_36 ? 0 : 1 ;
V_4 -> V_28 = V_30 -> V_28 ;
}
V_32 = F_14 ( V_4 -> V_18 , V_4 -> V_13 , V_37 |
( V_4 -> V_14 ? V_38
: V_39 ) ,
V_30 ? V_30 -> V_40 : L_4 ) ;
if ( V_32 < 0 ) {
F_9 ( & V_20 -> V_18 , L_5 ) ;
return V_32 ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_41 ;
V_6 . V_42 = 1 ;
V_2 = F_15 ( & V_20 -> V_18 , F_16 ( & V_20 -> V_18 ) ,
& V_20 -> V_18 , V_4 , & V_43 ,
& V_6 ) ;
if ( F_17 ( V_2 ) ) {
F_9 ( & V_20 -> V_18 , L_6 ) ;
return F_18 ( V_2 ) ;
}
V_2 -> V_6 . V_5 = V_4 -> V_28 ;
F_19 ( V_2 ) ;
F_20 ( V_20 , V_2 ) ;
return 0 ;
}
