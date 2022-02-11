static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( V_2 -> V_6 . V_7 != V_8 ||
V_2 -> V_6 . V_9 != V_8 ||
V_2 -> V_6 . V_10 & ( V_11 | V_12 ) )
V_5 = 0 ;
F_3 ( V_4 -> V_13 ,
V_5 ? V_4 -> V_14 : ! V_4 -> V_14 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_17 == NULL || V_4 -> V_17 == V_16 -> V_18 ;
}
static int F_5 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = V_20 -> V_18 . V_23 ;
enum V_24 V_25 ;
V_4 -> V_13 = F_6 ( V_22 , 0 , & V_25 ) ;
if ( ! F_7 ( V_4 -> V_13 ) ) {
if ( V_4 -> V_13 != - V_26 ) {
F_8 ( & V_20 -> V_18 ,
L_1 ) ;
}
return V_4 -> V_13 ;
}
V_4 -> V_14 = ( V_25 & V_27 ) ? 0 : 1 ;
V_4 -> V_28 = F_9 ( V_22 , L_2 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_29 * V_30 =
F_11 ( & V_20 -> V_18 ) ;
struct V_31 V_6 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_21 * V_22 = V_20 -> V_18 . V_23 ;
unsigned long V_32 = V_33 ;
int V_34 ;
if ( ! V_30 && ! V_22 ) {
F_8 ( & V_20 -> V_18 ,
L_3 ) ;
return - V_35 ;
}
V_4 = F_12 ( & V_20 -> V_18 , sizeof( * V_4 ) , V_36 ) ;
if ( V_4 == NULL )
return - V_37 ;
V_4 -> V_18 = & V_20 -> V_18 ;
if ( V_22 ) {
V_34 = F_5 ( V_20 , V_4 ) ;
if ( V_34 )
return V_34 ;
} else {
V_4 -> V_17 = V_30 -> V_17 ;
V_4 -> V_13 = V_30 -> V_13 ;
V_4 -> V_14 = V_30 -> V_38 ? 0 : 1 ;
V_4 -> V_28 = V_30 -> V_28 ;
}
if ( V_4 -> V_14 )
V_32 |= V_4 -> V_28 ? V_39 : V_40 ;
else
V_32 |= V_4 -> V_28 ? V_40 : V_39 ;
V_34 = F_13 ( V_4 -> V_18 , V_4 -> V_13 , V_32 ,
V_30 ? V_30 -> V_41 : L_4 ) ;
if ( V_34 < 0 ) {
F_8 ( & V_20 -> V_18 , L_5 ) ;
return V_34 ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_42 ;
V_6 . V_43 = 1 ;
V_2 = F_14 ( & V_20 -> V_18 , F_15 ( & V_20 -> V_18 ) ,
& V_20 -> V_18 , V_4 , & V_44 ,
& V_6 ) ;
if ( F_16 ( V_2 ) ) {
F_8 ( & V_20 -> V_18 , L_6 ) ;
return F_17 ( V_2 ) ;
}
V_2 -> V_6 . V_5 = V_4 -> V_28 ;
F_18 ( V_2 ) ;
F_19 ( V_20 , V_2 ) ;
return 0 ;
}
