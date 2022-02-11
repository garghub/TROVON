static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( V_2 -> V_6 . V_7 != V_8 ||
V_2 -> V_6 . V_9 != V_8 ||
V_2 -> V_6 . V_10 & ( V_11 | V_12 ) )
V_5 = 0 ;
F_3 ( V_4 -> V_13 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_16 == NULL || V_4 -> V_16 == V_15 -> V_17 ;
}
static int F_5 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_20 * V_17 = & V_19 -> V_17 ;
struct V_21 * V_22 = V_17 -> V_23 ;
enum V_24 V_25 ;
int V_26 ;
V_4 -> V_27 = F_6 ( V_22 , L_1 ) ;
V_25 = V_4 -> V_27 ? V_28 : V_29 ;
V_4 -> V_13 = F_7 ( V_17 , NULL , V_25 ) ;
if ( F_8 ( V_4 -> V_13 ) ) {
V_26 = F_9 ( V_4 -> V_13 ) ;
if ( V_26 != - V_30 ) {
F_10 ( V_17 ,
L_2 ) ;
}
return V_26 ;
}
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_31 * V_32 =
F_12 ( & V_19 -> V_17 ) ;
struct V_33 V_6 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_21 * V_22 = V_19 -> V_17 . V_23 ;
int V_26 ;
if ( ! V_32 && ! V_22 ) {
F_10 ( & V_19 -> V_17 ,
L_3 ) ;
return - V_34 ;
}
V_4 = F_13 ( & V_19 -> V_17 , sizeof( * V_4 ) , V_35 ) ;
if ( V_4 == NULL )
return - V_36 ;
V_4 -> V_17 = & V_19 -> V_17 ;
if ( V_22 ) {
V_26 = F_5 ( V_19 , V_4 ) ;
if ( V_26 )
return V_26 ;
} else {
unsigned long V_25 = V_37 ;
V_4 -> V_16 = V_32 -> V_16 ;
V_4 -> V_27 = V_32 -> V_27 ;
V_25 |= V_4 -> V_27 ? V_38 : V_39 ;
V_26 = F_14 ( V_4 -> V_17 , V_32 -> V_40 , V_25 ,
V_32 ? V_32 -> V_41 : L_4 ) ;
if ( V_26 < 0 ) {
F_10 ( & V_19 -> V_17 , L_5 ) ;
return V_26 ;
}
V_4 -> V_13 = F_15 ( V_32 -> V_40 ) ;
if ( ! V_4 -> V_13 )
return - V_42 ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . type = V_43 ;
V_6 . V_44 = 1 ;
V_2 = F_16 ( & V_19 -> V_17 , F_17 ( & V_19 -> V_17 ) ,
& V_19 -> V_17 , V_4 , & V_45 ,
& V_6 ) ;
if ( F_8 ( V_2 ) ) {
F_10 ( & V_19 -> V_17 , L_6 ) ;
return F_9 ( V_2 ) ;
}
V_2 -> V_6 . V_5 = V_4 -> V_27 ;
F_18 ( V_2 ) ;
F_19 ( V_19 , V_2 ) ;
return 0 ;
}
