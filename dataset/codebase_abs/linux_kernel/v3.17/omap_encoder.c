struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_4 ( V_3 , false ) ;
F_5 ( V_3 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_2 * V_3 , int V_6 )
{
}
static bool F_8 ( struct V_2 * V_3 ,
const struct V_7 * V_6 ,
struct V_7 * V_8 )
{
return true ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_7 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_11 * V_12 ;
bool V_13 ;
int V_14 ;
V_13 = false ;
F_10 (connector, &dev->mode_config.connector_list, head) {
if ( V_12 -> V_3 == V_3 ) {
V_13 = F_11 ( V_12 ) ;
break;
}
}
if ( V_5 -> V_15 -> V_16 )
V_5 -> V_15 -> V_16 ( V_5 , V_13 ) ;
if ( V_13 && V_5 -> V_15 -> V_17 ) {
struct V_18 V_19 ;
V_14 = F_12 ( & V_19 , V_8 ) ;
if ( V_14 == 0 )
V_5 -> V_15 -> V_17 ( V_5 , & V_19 ) ;
}
}
static void F_13 ( struct V_2 * V_3 )
{
}
static void F_14 ( struct V_2 * V_3 )
{
}
int F_4 ( struct V_2 * V_3 , bool V_20 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_21 * V_22 = V_5 -> V_15 ;
if ( V_20 ) {
return V_22 -> V_23 ( V_5 ) ;
} else {
V_22 -> V_24 ( V_5 ) ;
return 0 ;
}
}
int F_15 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_21 * V_22 = V_5 -> V_15 ;
int V_29 ;
V_5 -> V_30 -> V_31 = V_26 ;
if ( V_22 -> V_32 ) {
V_29 = V_22 -> V_32 ( V_5 , V_28 ) ;
} else {
struct V_27 V_33 = { 0 } ;
V_22 -> V_34 ( V_5 , & V_33 ) ;
if ( memcmp ( V_28 , & V_33 , sizeof( struct V_27 ) ) )
V_29 = - V_35 ;
else
V_29 = 0 ;
}
if ( V_29 ) {
F_16 ( V_10 -> V_10 , L_1 , V_29 ) ;
return V_29 ;
}
if ( V_22 -> V_36 )
V_22 -> V_36 ( V_5 , V_28 ) ;
return 0 ;
}
struct V_2 * F_17 ( struct V_9 * V_10 ,
struct V_1 * V_5 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
goto V_38;
V_4 -> V_5 = V_5 ;
V_3 = & V_4 -> V_39 ;
F_19 ( V_10 , V_3 , & V_40 ,
V_41 ) ;
F_20 ( V_3 , & V_42 ) ;
return V_3 ;
V_38:
if ( V_3 )
F_3 ( V_3 ) ;
return NULL ;
}
