void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_3 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_4 ( L_1 ) ;
F_5 ( V_5 -> V_6 , true ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_4 ( L_1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_3 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_4 ( L_1 ) ;
F_5 ( V_5 -> V_6 , false ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_7 * V_9 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_12 * V_13 ;
struct V_3 * V_3 = F_3 ( V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_4 ( L_2 ,
V_8 -> V_14 . V_15 , V_8 -> V_16 ,
V_8 -> V_17 , V_8 -> clock ,
V_8 -> V_18 , V_8 -> V_19 ,
V_8 -> V_20 , V_8 -> V_21 ,
V_8 -> V_22 , V_8 -> V_23 ,
V_8 -> V_24 , V_8 -> V_25 ,
V_8 -> type , V_8 -> V_26 ) ;
F_10 (connector, &dev->mode_config.connector_list, head) {
if ( ( V_13 -> V_27 != NULL ) &&
( V_13 -> V_27 -> V_2 == V_2 ) ) {
F_11 ( V_5 -> V_6 ,
V_9 , & V_13 -> V_28 ) ;
break;
}
}
}
struct V_1 * F_12 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
int V_29 ;
V_3 = F_13 ( V_5 -> V_11 -> V_11 ,
sizeof( * V_3 ) , V_30 ) ;
if ( ! V_3 ) {
V_29 = - V_31 ;
goto V_32;
}
V_3 -> V_5 = V_5 ;
V_2 = & V_3 -> V_14 ;
V_2 -> V_33 = & V_34 ;
V_29 = F_14 ( V_5 -> V_11 , V_2 ) ;
if ( V_29 )
goto V_32;
return V_2 ;
V_32:
if ( V_2 )
F_1 ( V_2 ) ;
return F_15 ( V_29 ) ;
}
