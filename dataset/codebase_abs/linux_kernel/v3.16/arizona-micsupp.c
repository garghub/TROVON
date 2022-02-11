static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
struct V_8 * V_8 = V_4 -> V_8 ;
struct V_9 * V_9 = V_8 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_3 ( V_9 , V_12 , & V_10 ) ;
if ( V_11 != 0 ) {
F_4 ( V_8 -> V_13 , L_1 , V_11 ) ;
return;
}
if ( V_7 ) {
if ( ( V_10 & ( V_14 | V_15 ) ) ==
V_14 )
F_5 ( V_7 , L_2 ) ;
else
F_6 ( V_7 , L_2 ) ;
F_7 ( V_7 ) ;
}
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_9 ( V_17 ) ;
int V_11 ;
V_11 = F_10 ( V_17 ) ;
if ( V_11 == 0 )
F_11 ( & V_4 -> V_5 ) ;
return V_11 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_9 ( V_17 ) ;
int V_11 ;
V_11 = F_13 ( V_17 ) ;
if ( V_11 == 0 )
F_11 ( & V_4 -> V_5 ) ;
return V_11 ;
}
static int F_14 ( struct V_16 * V_17 , bool V_18 )
{
struct V_3 * V_4 = F_9 ( V_17 ) ;
int V_11 ;
V_11 = F_15 ( V_17 , V_18 ) ;
if ( V_11 == 0 )
F_11 ( & V_4 -> V_5 ) ;
return V_11 ;
}
static int F_16 ( struct V_8 * V_8 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_8 -> V_22 ;
struct V_3 * V_4 = V_20 -> V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
V_25 = F_17 ( V_8 -> V_13 -> V_28 , L_3 ) ;
if ( V_25 ) {
V_20 -> V_28 = V_25 ;
V_27 = F_18 ( V_8 -> V_13 , V_25 ) ;
if ( V_27 ) {
V_27 -> V_29 = & V_4 -> V_30 ;
V_27 -> V_31 = 1 ;
V_22 -> V_32 = V_27 ;
}
}
return 0 ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_8 * V_8 = F_20 ( V_34 -> V_13 . V_35 ) ;
const struct V_36 * V_37 ;
struct V_19 V_20 = { } ;
struct V_3 * V_4 ;
int V_11 ;
V_4 = F_21 ( & V_34 -> V_13 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_8 = V_8 ;
F_22 ( & V_4 -> V_5 , F_1 ) ;
switch ( V_8 -> type ) {
case V_40 :
V_37 = & V_41 ;
V_4 -> V_27 = V_42 ;
break;
default:
V_37 = & V_3 ;
V_4 -> V_27 = V_43 ;
break;
}
V_4 -> V_27 . V_29 = & V_4 -> V_30 ;
V_4 -> V_30 . V_30 = L_4 ;
V_4 -> V_30 . V_44 = V_44 ( V_8 -> V_13 ) ;
V_20 . V_13 = V_8 -> V_13 ;
V_20 . V_23 = V_4 ;
V_20 . V_9 = V_8 -> V_9 ;
if ( F_23 ( V_45 ) ) {
if ( ! F_24 ( V_8 -> V_13 ) ) {
V_11 = F_16 ( V_8 , & V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
}
}
if ( V_8 -> V_22 . V_32 )
V_20 . V_27 = V_8 -> V_22 . V_32 ;
else
V_20 . V_27 = & V_4 -> V_27 ;
F_25 ( V_8 -> V_9 , V_12 ,
V_15 , 0 ) ;
V_4 -> V_46 = F_26 ( & V_34 -> V_13 ,
V_37 ,
& V_20 ) ;
if ( F_27 ( V_4 -> V_46 ) ) {
V_11 = F_28 ( V_4 -> V_46 ) ;
F_4 ( V_8 -> V_13 , L_5 ,
V_11 ) ;
return V_11 ;
}
F_29 ( V_20 . V_28 ) ;
F_30 ( V_34 , V_4 ) ;
return 0 ;
}
