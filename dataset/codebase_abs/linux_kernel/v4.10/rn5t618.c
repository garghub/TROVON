static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static void F_2 ( bool V_14 )
{
F_3 ( V_15 -> V_16 , V_17 ,
V_18 ,
V_14 ? V_18 : 0 ) ;
F_3 ( V_15 -> V_16 , V_19 ,
V_20 , V_20 ) ;
}
static void F_4 ( void )
{
F_2 ( false ) ;
}
static int F_5 ( struct V_21 * V_22 ,
unsigned long V_23 , void * V_24 )
{
F_2 ( true ) ;
F_6 ( 1 ) ;
return V_25 ;
}
static int F_7 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
const struct V_30 * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
V_31 = F_8 ( V_35 , & V_27 -> V_2 ) ;
if ( ! V_31 ) {
F_9 ( & V_27 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_33 = F_10 ( & V_27 -> V_2 , sizeof( * V_33 ) , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
F_11 ( V_27 , V_33 ) ;
V_33 -> V_39 = ( long ) V_31 -> V_40 ;
V_33 -> V_16 = F_12 ( V_27 , & V_41 ) ;
if ( F_13 ( V_33 -> V_16 ) ) {
V_34 = F_14 ( V_33 -> V_16 ) ;
F_9 ( & V_27 -> V_2 , L_2 , V_34 ) ;
return V_34 ;
}
V_34 = F_15 ( & V_27 -> V_2 , - 1 , V_42 ,
F_16 ( V_42 ) , NULL , 0 , NULL ) ;
if ( V_34 ) {
F_9 ( & V_27 -> V_2 , L_3 , V_34 ) ;
return V_34 ;
}
V_15 = V_33 ;
if ( F_17 ( V_27 -> V_2 . V_43 ) ) {
if ( ! V_44 )
V_44 = F_4 ;
else
F_18 ( & V_27 -> V_2 , L_4 ) ;
}
V_45 . V_46 = F_5 ;
V_45 . V_47 = 192 ;
V_34 = F_19 ( & V_45 ) ;
if ( V_34 ) {
F_9 ( & V_27 -> V_2 , L_5 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_32 * V_33 = F_21 ( V_27 ) ;
if ( V_33 == V_15 ) {
V_15 = NULL ;
V_44 = NULL ;
}
return 0 ;
}
