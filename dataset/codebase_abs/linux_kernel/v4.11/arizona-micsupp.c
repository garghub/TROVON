static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_8 * V_8 = V_4 -> V_8 ;
struct V_11 * V_11 = V_8 -> V_11 ;
unsigned int V_12 ;
int V_13 ;
V_13 = F_4 ( V_11 , V_14 , & V_12 ) ;
if ( V_13 != 0 ) {
F_5 ( V_8 -> V_15 , L_1 , V_13 ) ;
return;
}
if ( V_7 ) {
if ( ( V_12 & ( V_16 | V_17 ) ) ==
V_16 )
F_6 ( V_10 ,
L_2 ) ;
else
F_7 ( V_10 , L_2 ) ;
F_8 ( V_7 ) ;
}
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_10 ( V_19 ) ;
int V_13 ;
V_13 = F_11 ( V_19 ) ;
if ( V_13 == 0 )
F_12 ( & V_4 -> V_5 ) ;
return V_13 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_10 ( V_19 ) ;
int V_13 ;
V_13 = F_14 ( V_19 ) ;
if ( V_13 == 0 )
F_12 ( & V_4 -> V_5 ) ;
return V_13 ;
}
static int F_15 ( struct V_18 * V_19 , bool V_20 )
{
struct V_3 * V_4 = F_10 ( V_19 ) ;
int V_13 ;
V_13 = F_16 ( V_19 , V_20 ) ;
if ( V_13 == 0 )
F_12 ( & V_4 -> V_5 ) ;
return V_13 ;
}
static int F_17 ( struct V_8 * V_8 ,
struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_8 -> V_26 ;
struct V_3 * V_4 = V_22 -> V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
V_29 = F_18 ( V_8 -> V_15 -> V_32 , L_3 ) ;
if ( V_29 ) {
V_22 -> V_32 = V_29 ;
V_31 = F_19 ( V_8 -> V_15 , V_29 , V_24 ) ;
if ( V_31 ) {
V_31 -> V_33 = & V_4 -> V_34 ;
V_31 -> V_35 = 1 ;
V_26 -> V_36 = V_31 ;
}
}
return 0 ;
}
static int F_20 ( struct V_37 * V_38 )
{
struct V_8 * V_8 = F_21 ( V_38 -> V_15 . V_39 ) ;
const struct V_23 * V_24 ;
struct V_21 V_22 = { } ;
struct V_3 * V_4 ;
int V_13 ;
V_4 = F_22 ( & V_38 -> V_15 , sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_41 ;
V_4 -> V_8 = V_8 ;
F_23 ( & V_4 -> V_5 , F_1 ) ;
switch ( V_8 -> type ) {
case V_42 :
case V_43 :
V_24 = & V_44 ;
V_4 -> V_31 = V_45 ;
break;
default:
V_24 = & V_3 ;
V_4 -> V_31 = V_46 ;
break;
}
V_4 -> V_31 . V_33 = & V_4 -> V_34 ;
V_4 -> V_34 . V_34 = L_4 ;
V_4 -> V_34 . V_47 = V_47 ( V_8 -> V_15 ) ;
V_22 . V_15 = V_8 -> V_15 ;
V_22 . V_27 = V_4 ;
V_22 . V_11 = V_8 -> V_11 ;
if ( F_24 ( V_48 ) ) {
if ( ! F_25 ( V_8 -> V_15 ) ) {
V_13 = F_17 ( V_8 , & V_22 ,
V_24 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
if ( V_8 -> V_26 . V_36 )
V_22 . V_31 = V_8 -> V_26 . V_36 ;
else
V_22 . V_31 = & V_4 -> V_31 ;
F_26 ( V_8 -> V_11 , V_14 ,
V_17 , 0 ) ;
V_4 -> V_49 = F_27 ( & V_38 -> V_15 ,
V_24 ,
& V_22 ) ;
F_28 ( V_22 . V_32 ) ;
if ( F_29 ( V_4 -> V_49 ) ) {
V_13 = F_30 ( V_4 -> V_49 ) ;
F_5 ( V_8 -> V_15 , L_5 ,
V_13 ) ;
return V_13 ;
}
F_31 ( V_38 , V_4 ) ;
return 0 ;
}
