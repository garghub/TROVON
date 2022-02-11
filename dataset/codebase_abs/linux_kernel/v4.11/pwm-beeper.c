static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 V_5 ;
int error ;
F_2 ( V_2 -> V_6 , & V_5 ) ;
V_5 . V_7 = true ;
V_5 . V_3 = V_3 ;
F_3 ( & V_5 , 50 , 100 ) ;
error = F_4 ( V_2 -> V_6 , & V_5 ) ;
if ( error )
return error ;
if ( ! V_2 -> V_8 ) {
error = F_5 ( V_2 -> V_9 ) ;
if ( error ) {
F_6 ( V_2 -> V_6 ) ;
return error ;
}
V_2 -> V_8 = true ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_8 ( V_2 -> V_9 ) ;
V_2 -> V_8 = false ;
}
F_6 ( V_2 -> V_6 ) ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 , struct V_1 , V_11 ) ;
unsigned long V_3 = F_11 ( V_2 -> V_3 ) ;
if ( V_3 )
F_1 ( V_2 , V_3 ) ;
else
F_7 ( V_2 ) ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned int type , unsigned int V_14 , int V_15 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
if ( type != V_16 || V_15 < 0 )
return - V_17 ;
switch ( V_14 ) {
case V_18 :
V_15 = V_15 ? 1000 : 0 ;
break;
case V_19 :
break;
default:
return - V_17 ;
}
if ( V_15 == 0 )
V_2 -> V_3 = 0 ;
else
V_2 -> V_3 = F_14 ( V_15 ) ;
if ( ! V_2 -> V_20 )
F_15 ( & V_2 -> V_11 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_11 ) ;
F_7 ( V_2 ) ;
}
static void F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
F_16 ( V_2 ) ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
struct V_1 * V_2 ;
struct V_4 V_5 ;
int error ;
V_2 = F_20 ( V_24 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
V_2 -> V_6 = F_21 ( V_24 , NULL ) ;
if ( F_22 ( V_2 -> V_6 ) ) {
error = F_23 ( V_2 -> V_6 ) ;
if ( error != - V_27 )
F_24 ( V_24 , L_1 ,
error ) ;
return error ;
}
F_25 ( V_2 -> V_6 , & V_5 ) ;
V_5 . V_7 = false ;
error = F_4 ( V_2 -> V_6 , & V_5 ) ;
if ( error ) {
F_24 ( V_24 , L_2 ,
error ) ;
return error ;
}
V_2 -> V_9 = F_26 ( V_24 , L_3 ) ;
if ( F_22 ( V_2 -> V_9 ) ) {
error = F_23 ( V_2 -> V_9 ) ;
if ( error != - V_27 )
F_24 ( V_24 , L_4 ,
error ) ;
return error ;
}
F_27 ( & V_2 -> V_11 , F_9 ) ;
V_2 -> V_13 = F_28 ( V_24 ) ;
if ( ! V_2 -> V_13 ) {
F_24 ( V_24 , L_5 ) ;
return - V_26 ;
}
V_2 -> V_13 -> V_28 = L_6 ;
V_2 -> V_13 -> V_29 = L_7 ;
V_2 -> V_13 -> V_30 . V_31 = V_32 ;
V_2 -> V_13 -> V_30 . V_33 = 0x001f ;
V_2 -> V_13 -> V_30 . V_34 = 0x0001 ;
V_2 -> V_13 -> V_30 . V_35 = 0x0100 ;
F_29 ( V_2 -> V_13 , V_16 , V_19 ) ;
F_29 ( V_2 -> V_13 , V_16 , V_18 ) ;
V_2 -> V_13 -> V_36 = F_12 ;
V_2 -> V_13 -> V_37 = F_18 ;
F_30 ( V_2 -> V_13 , V_2 ) ;
error = F_31 ( V_2 -> V_13 ) ;
if ( error ) {
F_24 ( V_24 , L_8 , error ) ;
return error ;
}
F_32 ( V_22 , V_2 ) ;
return 0 ;
}
static int T_1 F_33 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_34 ( V_24 ) ;
F_35 ( & V_2 -> V_13 -> V_38 ) ;
V_2 -> V_20 = true ;
F_36 ( & V_2 -> V_13 -> V_38 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int T_1 F_37 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_34 ( V_24 ) ;
F_35 ( & V_2 -> V_13 -> V_38 ) ;
V_2 -> V_20 = false ;
F_36 ( & V_2 -> V_13 -> V_38 ) ;
F_15 ( & V_2 -> V_11 ) ;
return 0 ;
}
