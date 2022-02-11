static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 ;
struct V_8 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_11 ) ;
if ( V_10 ) {
F_3 ( V_4 , L_1 , V_10 ) ;
return V_10 ;
}
F_4 ( V_2 -> V_12 , & V_9 ) ;
F_5 ( & V_9 , V_2 -> V_13 , 0xffff ) ;
V_9 . V_14 = true ;
V_10 = F_6 ( V_2 -> V_12 , & V_9 ) ;
if ( V_10 ) {
F_3 ( V_4 , L_2 , V_10 ) ;
return V_10 ;
}
if ( V_2 -> V_15 ) {
F_4 ( V_2 -> V_15 , & V_9 ) ;
V_9 . V_16 = V_2 -> V_17 ;
V_9 . V_14 = true ;
V_10 = F_6 ( V_2 -> V_15 , & V_9 ) ;
if ( V_10 ) {
F_3 ( V_4 , L_3 , V_10 ) ;
F_7 ( V_2 -> V_12 ) ;
return V_10 ;
}
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_11 ) ;
if ( V_2 -> V_15 )
F_7 ( V_2 -> V_15 ) ;
F_7 ( V_2 -> V_12 ) ;
}
static void F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ,
struct V_1 , V_20 ) ;
if ( V_2 -> V_13 )
F_1 ( V_2 ) ;
else
F_8 ( V_2 ) ;
}
static int F_12 ( struct V_21 * V_6 , void * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_6 ) ;
V_2 -> V_13 = V_24 -> V_25 . V_26 . V_27 ;
if ( ! V_2 -> V_13 )
V_2 -> V_13 = V_24 -> V_25 . V_26 . V_28 ;
F_14 ( & V_2 -> V_20 ) ;
return 0 ;
}
static void F_15 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_13 ( V_5 ) ;
F_16 ( & V_2 -> V_20 ) ;
F_8 ( V_2 ) ;
}
static int F_17 ( struct V_29 * V_4 )
{
struct V_1 * V_2 ;
struct V_8 V_9 ;
int V_10 ;
V_2 = F_18 ( & V_4 -> V_6 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_5 = F_19 ( & V_4 -> V_6 ) ;
if ( ! V_2 -> V_5 )
return - V_31 ;
V_2 -> V_11 = F_20 ( & V_4 -> V_6 , L_4 ) ;
V_10 = F_21 ( V_2 -> V_11 ) ;
if ( V_10 ) {
if ( V_10 != - V_32 )
F_3 ( & V_4 -> V_6 , L_5 ,
V_10 ) ;
return V_10 ;
}
V_2 -> V_12 = F_22 ( & V_4 -> V_6 , L_6 ) ;
V_10 = F_21 ( V_2 -> V_12 ) ;
if ( V_10 ) {
if ( V_10 != - V_32 )
F_3 ( & V_4 -> V_6 , L_7 ,
V_10 ) ;
return V_10 ;
}
F_23 ( & V_2 -> V_20 , F_10 ) ;
F_24 ( V_2 -> V_12 , & V_9 ) ;
V_9 . V_14 = false ;
V_10 = F_6 ( V_2 -> V_12 , & V_9 ) ;
if ( V_10 ) {
F_3 ( & V_4 -> V_6 , L_8 ,
V_10 ) ;
return V_10 ;
}
V_2 -> V_15 = F_22 ( & V_4 -> V_6 , L_9 ) ;
V_10 = F_21 ( V_2 -> V_15 ) ;
switch ( V_10 ) {
case 0 :
F_24 ( V_2 -> V_15 , & V_9 ) ;
V_9 . V_14 = false ;
V_10 = F_6 ( V_2 -> V_15 , & V_9 ) ;
if ( V_10 ) {
F_3 ( & V_4 -> V_6 , L_8 ,
V_10 ) ;
return V_10 ;
}
V_2 -> V_17 =
F_25 ( V_2 -> V_15 ) / 2 ;
F_26 ( & V_4 -> V_6 , L_10 ,
& V_2 -> V_17 ) ;
break;
case - V_33 :
V_2 -> V_15 = NULL ;
break;
default:
F_3 ( & V_4 -> V_6 , L_11 , V_10 ) ;
case - V_32 :
return V_10 ;
}
V_2 -> V_5 -> V_34 = L_12 ;
V_2 -> V_5 -> V_35 . V_36 = V_37 ;
V_2 -> V_5 -> V_6 . V_7 = & V_4 -> V_6 ;
V_2 -> V_5 -> V_38 = F_15 ;
F_27 ( V_2 -> V_5 , V_2 ) ;
F_28 ( V_2 -> V_5 , V_39 , V_40 ) ;
V_10 = F_29 ( V_2 -> V_5 , NULL ,
F_12 ) ;
if ( V_10 ) {
F_3 ( & V_4 -> V_6 , L_13 , V_10 ) ;
return V_10 ;
}
V_10 = F_30 ( V_2 -> V_5 ) ;
if ( V_10 ) {
F_3 ( & V_4 -> V_6 , L_14 , V_10 ) ;
return V_10 ;
}
F_31 ( V_4 , V_2 ) ;
return 0 ;
}
static int T_1 F_32 ( struct V_3 * V_6 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
F_16 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_13 )
F_8 ( V_2 ) ;
return 0 ;
}
static int T_1 F_34 ( struct V_3 * V_6 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
if ( V_2 -> V_13 )
F_1 ( V_2 ) ;
return 0 ;
}
