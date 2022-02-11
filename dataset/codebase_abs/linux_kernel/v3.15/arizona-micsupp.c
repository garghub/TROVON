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
static int F_16 ( struct V_19 * V_20 )
{
struct V_8 * V_8 = F_17 ( V_20 -> V_13 . V_21 ) ;
const struct V_22 * V_23 ;
struct V_24 V_25 = { } ;
struct V_3 * V_4 ;
int V_11 ;
V_4 = F_18 ( & V_20 -> V_13 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_8 = V_8 ;
F_19 ( & V_4 -> V_5 , F_1 ) ;
switch ( V_8 -> type ) {
case V_28 :
V_23 = & V_29 ;
V_4 -> V_30 = V_31 ;
break;
default:
V_23 = & V_3 ;
V_4 -> V_30 = V_32 ;
break;
}
V_4 -> V_30 . V_33 = & V_4 -> V_34 ;
V_4 -> V_34 . V_34 = L_3 ;
V_4 -> V_34 . V_35 = V_35 ( V_8 -> V_13 ) ;
V_25 . V_13 = V_8 -> V_13 ;
V_25 . V_36 = V_4 ;
V_25 . V_9 = V_8 -> V_9 ;
if ( V_8 -> V_37 . V_38 )
V_25 . V_30 = V_8 -> V_37 . V_38 ;
else
V_25 . V_30 = & V_4 -> V_30 ;
F_20 ( V_8 -> V_9 , V_12 ,
V_15 , 0 ) ;
V_4 -> V_39 = F_21 ( & V_20 -> V_13 ,
V_23 ,
& V_25 ) ;
if ( F_22 ( V_4 -> V_39 ) ) {
V_11 = F_23 ( V_4 -> V_39 ) ;
F_4 ( V_8 -> V_13 , L_4 ,
V_11 ) ;
return V_11 ;
}
F_24 ( V_20 , V_4 ) ;
return 0 ;
}
