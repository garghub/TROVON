static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = * V_4 -> V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_3 ( V_4 -> V_12 , V_4 -> V_13 , & V_10 ) ;
if ( V_11 != 0 ) {
F_4 ( V_4 -> V_14 ,
L_1 , V_11 ) ;
return;
}
if ( V_7 ) {
V_9 = F_5 ( V_7 ) ;
if ( ( V_10 & ( V_15 | V_16 ) ) ==
V_15 )
F_6 ( V_9 ,
L_2 ) ;
else
F_7 ( V_9 , L_2 ) ;
F_8 ( V_7 ) ;
}
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_11 ;
V_11 = F_11 ( V_18 ) ;
if ( V_11 == 0 )
F_12 ( & V_4 -> V_5 ) ;
return V_11 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_11 ;
V_11 = F_14 ( V_18 ) ;
if ( V_11 == 0 )
F_12 ( & V_4 -> V_5 ) ;
return V_11 ;
}
static int F_15 ( struct V_17 * V_18 , bool V_19 )
{
struct V_3 * V_4 = F_10 ( V_18 ) ;
int V_11 ;
V_11 = F_16 ( V_18 , V_19 ) ;
if ( V_11 == 0 )
F_12 ( & V_4 -> V_5 ) ;
return V_11 ;
}
static int F_17 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_3 * V_4 = V_23 -> V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_28 = F_18 ( V_23 -> V_14 -> V_31 , L_3 ) ;
if ( V_28 ) {
V_23 -> V_31 = V_28 ;
V_30 = F_19 ( V_23 -> V_14 , V_28 , V_25 ) ;
if ( V_30 ) {
V_30 -> V_32 = & V_4 -> V_33 ;
V_30 -> V_34 = 1 ;
V_21 -> V_30 = V_30 ;
}
}
return 0 ;
}
static int F_20 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
const struct V_24 * V_25 ,
struct V_20 * V_21 )
{
struct V_22 V_23 = { } ;
int V_11 ;
F_21 ( & V_4 -> V_5 , F_1 ) ;
V_4 -> V_30 . V_32 = & V_4 -> V_33 ;
V_4 -> V_33 . V_33 = L_4 ;
V_4 -> V_33 . V_37 = V_37 ( V_4 -> V_14 ) ;
V_4 -> V_13 = V_25 -> V_13 ;
V_23 . V_14 = V_4 -> V_14 ;
V_23 . V_26 = V_4 ;
V_23 . V_12 = V_4 -> V_12 ;
if ( F_22 ( V_38 ) ) {
if ( ! F_23 ( V_4 -> V_14 ) ) {
V_11 = F_17 ( V_21 , & V_23 ,
V_25 ) ;
if ( V_11 < 0 )
return V_11 ;
}
}
if ( V_21 -> V_30 )
V_23 . V_30 = V_21 -> V_30 ;
else
V_23 . V_30 = & V_4 -> V_30 ;
F_24 ( V_4 -> V_12 , V_4 -> V_13 ,
V_16 , 0 ) ;
V_4 -> V_39 = F_25 ( & V_36 -> V_14 ,
V_25 ,
& V_23 ) ;
F_26 ( V_23 . V_31 ) ;
if ( F_27 ( V_4 -> V_39 ) ) {
V_11 = F_28 ( V_4 -> V_39 ) ;
F_4 ( V_4 -> V_14 , L_5 ,
V_11 ) ;
return V_11 ;
}
F_29 ( V_36 , V_4 ) ;
return 0 ;
}
static int F_30 ( struct V_35 * V_36 )
{
struct V_40 * V_40 = F_31 ( V_36 -> V_14 . V_41 ) ;
const struct V_24 * V_25 ;
struct V_3 * V_4 ;
V_4 = F_32 ( & V_36 -> V_14 , sizeof( * V_4 ) , V_42 ) ;
if ( ! V_4 )
return - V_43 ;
V_4 -> V_12 = V_40 -> V_12 ;
V_4 -> V_7 = & V_40 -> V_7 ;
V_4 -> V_14 = V_40 -> V_14 ;
switch ( V_40 -> type ) {
case V_44 :
case V_45 :
V_25 = & V_46 ;
V_4 -> V_30 = V_47 ;
break;
default:
V_25 = & V_3 ;
V_4 -> V_30 = V_48 ;
break;
}
return F_20 ( V_36 , V_4 , V_25 ,
& V_40 -> V_21 . V_49 ) ;
}
