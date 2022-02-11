static T_1 F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static int F_7 ( struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_12 * V_12 = ( void * ) V_11 -> V_13 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
void T_2 * V_16 ;
int V_17 ;
V_17 = F_8 ( V_9 ) ;
if ( V_17 ) {
F_9 ( & V_9 -> V_15 , L_1 ) ;
goto V_18;
}
V_17 = F_10 ( V_9 , V_19 ) ;
if ( V_17 ) {
F_9 ( & V_9 -> V_15 , L_2 ) ;
goto V_20;
}
F_11 ( V_9 ) ;
F_12 ( V_9 ) ;
V_16 = F_13 ( V_9 , 0 , F_14 ( V_9 , 0 ) ) ;
if ( ! V_16 ) {
F_9 ( & V_9 -> V_15 ,
L_3
L_4 ) ;
V_17 = - V_21 ;
goto V_22;
}
V_15 = F_15 () ;
if ( ! V_15 ) {
V_17 = - V_21 ;
goto V_23;
}
V_2 = F_16 ( V_15 ) ;
F_17 ( V_9 , V_15 ) ;
F_18 ( V_15 , & V_9 -> V_15 ) ;
V_15 -> V_24 = V_9 -> V_24 ;
V_2 -> V_5 = V_16 ;
if ( ! V_12 -> V_25 ) {
F_9 ( & V_9 -> V_15 , L_5 ) ;
V_17 = - V_26 ;
goto V_27;
} else {
V_2 -> V_28 . clock . V_25 = V_12 -> V_25 ;
}
switch ( V_12 -> type ) {
case V_29 :
V_2 -> V_6 = V_30 ;
break;
case V_31 :
V_2 -> V_6 = V_32 ;
V_2 -> V_28 . V_33 |= V_34 ;
break;
default:
V_17 = - V_35 ;
goto V_27;
}
switch ( V_12 -> V_36 ) {
case V_37 :
V_2 -> V_38 = F_5 ;
V_2 -> V_39 = F_6 ;
break;
case V_40 :
V_2 -> V_38 = F_1 ;
V_2 -> V_39 = F_3 ;
break;
default:
V_17 = - V_35 ;
goto V_27;
}
V_17 = F_19 ( V_15 ) ;
if ( V_17 ) {
F_9 ( & V_9 -> V_15 , L_6 ,
V_19 , V_17 ) ;
goto V_27;
}
F_20 ( & V_9 -> V_15 , L_7 ,
V_19 , V_2 -> V_6 , V_15 -> V_24 ) ;
return 0 ;
V_27:
F_17 ( V_9 , NULL ) ;
F_21 ( V_15 ) ;
V_23:
F_22 ( V_9 , V_16 ) ;
V_22:
F_23 ( V_9 ) ;
F_24 ( V_9 ) ;
F_25 ( V_9 ) ;
V_20:
F_26 ( V_9 ) ;
V_18:
return V_17 ;
}
static void F_27 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_28 ( V_9 ) ;
struct V_1 * V_2 = F_16 ( V_15 ) ;
F_29 ( V_15 ) ;
F_17 ( V_9 , NULL ) ;
F_21 ( V_15 ) ;
F_22 ( V_9 , V_2 -> V_5 ) ;
F_23 ( V_9 ) ;
F_24 ( V_9 ) ;
F_25 ( V_9 ) ;
F_26 ( V_9 ) ;
}
