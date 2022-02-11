static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 -> V_7 . V_9 ;
const char * V_10 = V_5 -> V_8 -> V_10 ;
T_1 V_11 = ( T_1 ) V_3 ;
F_3 ( V_7 , L_1 , V_11 ) ;
switch ( V_11 ) {
case V_12 :
F_4 ( V_7 , L_2 , V_10 ) ;
break;
case V_13 :
F_5 ( V_7 , L_3 , V_10 ) ;
break;
default:
if ( F_6 ( V_5 -> V_8 , V_11 ) == V_14 )
F_3 ( V_7 , L_4 , V_11 ) ;
}
}
static void F_7 ( struct V_8 * V_8 , int V_15 )
{
struct V_4 * V_5 = V_8 -> V_16 ;
struct V_6 * V_7 = V_8 -> V_7 . V_9 ;
int V_17 ;
V_17 = F_8 ( V_5 -> V_18 , ( void * ) V_15 ) ;
if ( V_17 < 0 )
F_4 ( V_7 , L_5 ,
V_17 ) ;
}
static int F_9 ( struct V_8 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_16 ;
struct V_6 * V_7 = V_8 -> V_7 . V_9 ;
struct V_19 * V_20 = F_10 ( V_7 ) ;
struct V_21 * V_22 = V_20 -> V_7 . V_23 ;
int V_17 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
if ( V_22 -> V_24 )
V_22 -> V_24 ( V_8 -> V_25 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_26 = NULL ;
V_2 -> V_27 = F_1 ;
V_2 -> V_28 = false ;
V_2 -> V_29 = false ;
V_5 -> V_18 = F_11 ( V_2 , V_22 -> V_30 ) ;
if ( F_12 ( V_5 -> V_18 ) ) {
V_17 = - V_31 ;
F_4 ( V_7 , L_6 ,
F_13 ( V_5 -> V_18 ) ) ;
return V_17 ;
}
V_17 = F_8 ( V_5 -> V_18 , ( void * ) V_32 ) ;
if ( V_17 < 0 ) {
F_4 ( V_7 , L_7 , V_17 ) ;
goto V_33;
}
V_17 = V_22 -> V_34 ( V_20 ) ;
if ( V_17 ) {
F_4 ( V_7 , L_8 , V_17 ) ;
goto V_33;
}
return 0 ;
V_33:
F_14 ( V_5 -> V_18 ) ;
return V_17 ;
}
static int F_15 ( struct V_8 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 . V_9 ;
struct V_19 * V_20 = F_10 ( V_7 ) ;
struct V_21 * V_22 = V_20 -> V_7 . V_23 ;
struct V_4 * V_5 = V_8 -> V_16 ;
int V_17 ;
V_17 = V_22 -> V_35 ( V_20 ) ;
if ( V_17 )
return V_17 ;
F_14 ( V_5 -> V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_7 . V_23 ;
struct V_4 * V_5 ;
struct V_8 * V_8 ;
int V_17 ;
V_17 = F_17 ( & V_20 -> V_7 , F_18 ( 32 ) ) ;
if ( V_17 ) {
F_4 ( & V_20 -> V_7 , L_9 , V_17 ) ;
return V_17 ;
}
V_8 = F_19 ( & V_20 -> V_7 , V_22 -> V_10 , & V_36 ,
V_22 -> V_37 , sizeof( * V_5 ) ) ;
if ( ! V_8 )
return - V_38 ;
V_5 = V_8 -> V_16 ;
V_5 -> V_8 = V_8 ;
V_8 -> V_39 = true ;
F_20 ( V_20 , V_8 ) ;
V_17 = F_21 ( V_8 ) ;
if ( V_17 )
goto V_40;
return 0 ;
V_40:
F_22 ( V_8 ) ;
return V_17 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_8 * V_8 = F_24 ( V_20 ) ;
F_25 ( V_8 ) ;
F_22 ( V_8 ) ;
return 0 ;
}
