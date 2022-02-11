struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_4 ( V_3 ) ;
F_5 ( V_4 ) ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_6 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_11 * V_12 ;
bool V_13 ;
int V_14 ;
V_13 = false ;
F_7 (connector, &dev->mode_config.connector_list, head) {
if ( V_12 -> V_3 == V_3 ) {
V_13 = F_8 ( V_12 ) ;
break;
}
}
if ( V_5 -> V_15 -> V_16 )
V_5 -> V_15 -> V_16 ( V_5 , V_13 ) ;
if ( V_13 && V_5 -> V_15 -> V_17 ) {
struct V_18 V_19 ;
V_14 = F_9 ( & V_19 , V_8 ) ;
if ( V_14 == 0 )
V_5 -> V_15 -> V_17 ( V_5 , & V_19 ) ;
}
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_20 * V_21 = V_5 -> V_15 ;
V_21 -> V_22 ( V_5 ) ;
}
static int F_11 ( struct V_2 * V_3 ,
enum V_23 V_24 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_20 * V_21 = V_5 -> V_15 ;
int V_27 ;
if ( V_21 -> V_28 ) {
V_27 = V_21 -> V_28 ( V_5 , V_26 ) ;
} else {
struct V_25 V_29 = { 0 } ;
V_21 -> V_30 ( V_5 , & V_29 ) ;
if ( memcmp ( V_26 , & V_29 , sizeof( struct V_25 ) ) )
V_27 = - V_31 ;
else
V_27 = 0 ;
}
if ( V_27 ) {
F_12 ( V_10 -> V_10 , L_1 , V_27 ) ;
return V_27 ;
}
if ( V_21 -> V_32 )
V_21 -> V_32 ( V_5 , V_26 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_20 * V_21 = V_5 -> V_15 ;
int V_14 ;
F_11 ( V_3 , F_14 ( V_3 -> V_33 ) ,
F_15 ( V_3 -> V_33 ) ) ;
V_14 = V_21 -> V_34 ( V_5 ) ;
if ( V_14 )
F_12 ( V_3 -> V_10 -> V_10 ,
L_2 ,
V_5 -> V_35 , V_14 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
return 0 ;
}
struct V_2 * F_17 ( struct V_9 * V_10 ,
struct V_1 * V_5 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
goto V_41;
V_4 -> V_5 = V_5 ;
V_3 = & V_4 -> V_42 ;
F_19 ( V_10 , V_3 , & V_43 ,
V_44 , NULL ) ;
F_20 ( V_3 , & V_45 ) ;
return V_3 ;
V_41:
if ( V_3 )
F_3 ( V_3 ) ;
return NULL ;
}
