static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static inline struct V_6 * F_3 ( struct V_3 * V_7 )
{
return F_4 ( V_7 , struct V_6 , V_4 ) ;
}
static int F_5 ( struct V_3 * V_7 ,
enum V_8 V_9 , union V_10 * V_11 )
{
struct V_6 * V_6 = F_3 ( V_7 ) ;
const struct V_12 * V_13 = V_6 -> V_13 ;
switch ( V_9 ) {
case V_14 :
V_11 -> V_15 = F_6 ( V_13 -> V_16 ) ;
V_11 -> V_15 ^= V_13 -> V_17 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int T_2 F_7 ( struct V_19 * V_20 )
{
const struct V_12 * V_13 = V_20 -> V_21 . V_22 ;
struct V_6 * V_6 ;
struct V_3 * V_4 ;
int V_23 ;
int V_1 ;
if ( ! V_13 ) {
F_8 ( & V_20 -> V_21 , L_1 ) ;
return - V_18 ;
}
if ( ! F_9 ( V_13 -> V_16 ) ) {
F_8 ( & V_20 -> V_21 , L_2 ) ;
return - V_18 ;
}
V_6 = F_10 ( sizeof( * V_6 ) , V_24 ) ;
if ( ! V_6 ) {
F_8 ( & V_20 -> V_21 , L_3 ) ;
return - V_25 ;
}
V_4 = & V_6 -> V_4 ;
V_4 -> V_26 = V_13 -> V_26 ? V_13 -> V_26 : L_4 ;
V_4 -> type = V_13 -> type ;
V_4 -> V_27 = V_28 ;
V_4 -> V_29 = F_11 ( V_28 ) ;
V_4 -> V_30 = F_5 ;
V_4 -> V_31 = V_13 -> V_31 ;
V_4 -> V_32 = V_13 -> V_32 ;
V_23 = F_12 ( V_13 -> V_16 , F_13 ( & V_20 -> V_21 ) ) ;
if ( V_23 ) {
F_8 ( & V_20 -> V_21 , L_5 , V_23 ) ;
goto V_33;
}
V_23 = F_14 ( V_13 -> V_16 ) ;
if ( V_23 ) {
F_8 ( & V_20 -> V_21 , L_6 , V_23 ) ;
goto V_34;
}
V_6 -> V_13 = V_13 ;
V_23 = F_15 ( & V_20 -> V_21 , V_4 ) ;
if ( V_23 < 0 ) {
F_8 ( & V_20 -> V_21 , L_7 ,
V_23 ) ;
goto V_34;
}
V_1 = F_16 ( V_13 -> V_16 ) ;
if ( V_1 > 0 ) {
V_23 = F_17 ( V_1 , F_1 ,
V_35 | V_36 ,
F_13 ( & V_20 -> V_21 ) , V_4 ) ;
if ( V_23 < 0 )
F_18 ( & V_20 -> V_21 , L_8 , V_23 ) ;
else
V_6 -> V_1 = V_1 ;
}
F_19 ( V_20 , V_6 ) ;
return 0 ;
V_34:
F_20 ( V_13 -> V_16 ) ;
V_33:
F_21 ( V_6 ) ;
return V_23 ;
}
static int T_3 F_22 ( struct V_19 * V_20 )
{
struct V_6 * V_6 = F_23 ( V_20 ) ;
if ( V_6 -> V_1 )
F_24 ( V_6 -> V_1 , & V_6 -> V_4 ) ;
F_25 ( & V_6 -> V_4 ) ;
F_20 ( V_6 -> V_13 -> V_16 ) ;
F_19 ( V_20 , NULL ) ;
F_21 ( V_6 ) ;
return 0 ;
}
static int F_26 ( struct V_37 * V_21 )
{
struct V_19 * V_20 = F_27 ( V_21 ) ;
struct V_6 * V_6 = F_23 ( V_20 ) ;
F_2 ( & V_6 -> V_4 ) ;
return 0 ;
}
