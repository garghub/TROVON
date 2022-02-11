static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_1 * V_1 ;
struct V_3 * V_4 ;
V_1 = F_2 ( sizeof( * V_1 ) , V_5 ) ;
if ( ! V_1 )
return NULL ;
V_4 = F_3 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_8 ) ;
if ( ! V_4 ) {
F_4 ( V_1 ) ;
return NULL ;
}
V_2 -> V_8 ++ ;
V_1 -> V_4 = V_4 ;
V_1 -> V_9 = V_2 ;
return V_1 ;
}
static void F_5 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_6 ( V_1 -> V_9 -> V_10 , V_4 ) ;
F_7 ( V_4 ) ;
if ( V_1 -> V_11 )
F_8 ( & V_1 -> V_12 ) ;
F_4 ( V_1 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_13 ;
struct V_2 * V_2 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
V_2 = V_1 -> V_9 ;
V_4 = V_1 -> V_4 ;
V_15 = & V_4 -> V_15 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_16 = V_2 -> V_16 ;
V_15 -> V_17 = V_18 ;
V_15 -> V_19 = V_20 ;
V_15 -> V_21 = V_20 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = V_23 ;
V_4 -> V_25 = V_23 ;
V_4 -> V_26 = V_23 ;
V_4 -> V_27 = V_23 ;
V_13 = F_10 ( V_1 -> V_4 ) ;
if ( V_13 )
return V_13 ;
F_11 ( V_2 -> V_10 , V_1 -> V_4 ) ;
F_12 ( & V_1 -> V_12 ,
& V_2 -> V_28 ) ;
V_1 -> V_11 = true ;
return 0 ;
}
static int F_13 ( struct V_2 * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_15 ;
V_15 = & V_30 -> V_15 ;
V_15 -> V_16 = V_2 -> V_16 ;
V_15 -> V_19 = V_20 ;
V_15 -> V_21 = V_20 ;
return F_14 ( V_30 ) ;
}
static struct V_2 * F_15 (
struct V_31 * V_31 , T_1 V_16 )
{
int V_13 ;
struct V_2 * V_2 ;
struct V_32 * V_10 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
return NULL ;
F_16 ( & V_2 -> V_28 ) ;
V_2 -> V_6 = V_31 ;
V_10 = F_17 ( V_31 -> V_7 ) ;
if ( ! V_10 )
goto V_33;
V_13 = F_18 ( V_10 ) ;
if ( V_13 )
goto V_34;
V_2 -> V_10 = V_10 ;
V_2 -> V_16 = V_16 ;
F_12 ( & V_2 -> V_35 ,
& V_31 -> V_36 ) ;
return V_2 ;
V_34:
F_19 ( V_10 ) ;
V_33:
F_4 ( V_2 ) ;
return NULL ;
}
static void F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_1 ;
struct V_1 * V_37 ;
F_21 (pqi_sas_phy, next,
&pqi_sas_port->phy_list_head, phy_list_entry)
F_5 ( V_1 ) ;
F_22 ( V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_35 ) ;
F_4 ( V_2 ) ;
}
static struct V_31 * F_23 ( struct V_38 * V_7 )
{
struct V_31 * V_31 ;
V_31 = F_2 ( sizeof( * V_31 ) , V_5 ) ;
if ( V_31 ) {
V_31 -> V_7 = V_7 ;
F_16 ( & V_31 -> V_36 ) ;
}
return V_31 ;
}
static void F_24 ( struct V_31 * V_31 )
{
struct V_2 * V_2 ;
struct V_2 * V_37 ;
if ( ! V_31 )
return;
F_21 (pqi_sas_port, next,
&pqi_sas_node->port_list_head, port_list_entry)
F_20 ( V_2 ) ;
F_4 ( V_31 ) ;
}
struct V_39 * F_25 (
struct V_40 * V_41 , struct V_29 * V_30 )
{
struct V_39 * V_38 ;
F_26 (device, &ctrl_info->scsi_device_list,
scsi_device_list_entry) {
if ( ! V_38 -> V_32 )
continue;
if ( V_38 -> V_32 -> V_30 == V_30 )
return V_38 ;
}
return NULL ;
}
int F_27 ( struct V_42 * V_43 , struct V_40 * V_41 )
{
int V_13 ;
struct V_38 * V_7 ;
struct V_31 * V_31 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
V_7 = & V_43 -> V_44 ;
V_31 = F_23 ( V_7 ) ;
if ( ! V_31 )
return - V_45 ;
V_2 = F_15 ( V_31 , V_41 -> V_16 ) ;
if ( ! V_2 ) {
V_13 = - V_46 ;
goto V_47;
}
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 ) {
V_13 = - V_46 ;
goto V_34;
}
V_13 = F_9 ( V_1 ) ;
if ( V_13 )
goto V_48;
V_41 -> V_49 = V_31 ;
return 0 ;
V_48:
F_5 ( V_1 ) ;
V_34:
F_20 ( V_2 ) ;
V_47:
F_24 ( V_31 ) ;
return V_13 ;
}
void F_28 ( struct V_40 * V_41 )
{
F_24 ( V_41 -> V_49 ) ;
}
int F_29 ( struct V_31 * V_31 ,
struct V_39 * V_38 )
{
int V_13 ;
struct V_2 * V_2 ;
struct V_29 * V_30 ;
V_2 = F_15 ( V_31 , V_38 -> V_16 ) ;
if ( ! V_2 )
return - V_45 ;
V_30 = F_30 ( V_2 -> V_10 ) ;
if ( ! V_30 ) {
V_13 = - V_46 ;
goto V_34;
}
V_2 -> V_30 = V_30 ;
V_38 -> V_32 = V_2 ;
V_13 = F_13 ( V_2 , V_30 ) ;
if ( V_13 )
goto V_34;
return 0 ;
V_34:
F_20 ( V_2 ) ;
V_38 -> V_32 = NULL ;
return V_13 ;
}
void F_31 ( struct V_39 * V_38 )
{
if ( V_38 -> V_32 ) {
F_20 ( V_38 -> V_32 ) ;
V_38 -> V_32 = NULL ;
}
}
static int F_32 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_33 ( struct V_29 * V_30 ,
T_1 * V_50 )
{
return 0 ;
}
static int F_34 ( struct V_29 * V_30 )
{
return - V_51 ;
}
static int F_35 ( struct V_3 * V_4 , int V_52 )
{
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , int V_53 )
{
return 0 ;
}
static int F_37 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_38 ( struct V_3 * V_4 )
{
}
static int F_39 ( struct V_3 * V_4 ,
struct V_54 * V_55 )
{
return - V_56 ;
}
static int F_40 ( struct V_42 * V_43 , struct V_29 * V_30 ,
struct V_57 * V_58 )
{
return - V_56 ;
}
