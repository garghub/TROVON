int F_1 ( struct V_1 * type )
{
if ( V_2 )
return - V_3 ;
if ( type && type -> V_4 && type -> V_5 ) {
F_2 ( & V_6 ) ;
F_3 ( & type -> V_7 , & V_8 ) ;
F_4 ( & V_6 ) ;
F_5 (KERN_INFO PREFIX L_1 ,
type->bus->name) ;
return 0 ;
}
return - V_3 ;
}
int F_6 ( struct V_1 * type )
{
if ( V_2 )
return 0 ;
if ( type ) {
F_2 ( & V_6 ) ;
F_7 ( & type -> V_7 ) ;
F_4 ( & V_6 ) ;
F_5 (KERN_INFO PREFIX L_2 ,
type->bus->name) ;
return 0 ;
}
return - V_3 ;
}
static struct V_1 * F_8 ( struct V_9 * type )
{
struct V_1 * V_10 , * V_11 = NULL ;
F_9 ( & V_6 ) ;
F_10 (tmp, &bus_type_list, list) {
if ( V_10 -> V_4 == type ) {
V_11 = V_10 ;
break;
}
}
F_11 ( & V_6 ) ;
return V_11 ;
}
static int F_12 ( struct V_12 * V_13 , T_1 * V_14 )
{
struct V_1 * V_10 ;
int V_11 = - V_3 ;
F_9 ( & V_6 ) ;
F_10 (tmp, &bus_type_list, list) {
if ( V_10 -> V_15 && ! V_10 -> V_15 ( V_13 , V_14 ) ) {
V_11 = 0 ;
break;
}
}
F_11 ( & V_6 ) ;
return V_11 ;
}
static T_2
F_13 ( T_1 V_14 , T_3 V_16 , void * V_17 , void * * V_18 )
{
T_2 V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 = V_17 ;
V_19 = F_14 ( V_14 , & V_21 ) ;
if ( F_15 ( V_19 ) ) {
if ( ( V_21 -> V_24 == V_23 -> V_24 )
&& ( V_21 -> V_25 & V_26 ) )
V_23 -> V_14 = V_14 ;
F_16 ( V_21 ) ;
}
return V_27 ;
}
T_1 F_17 ( T_1 V_28 , T_4 V_24 )
{
struct V_22 V_23 = { NULL , V_24 } ;
if ( ! V_28 )
return NULL ;
F_18 ( V_29 , V_28 ,
1 , F_13 , NULL , & V_23 , NULL ) ;
return V_23 . V_14 ;
}
static int F_19 ( struct V_12 * V_13 , T_1 V_14 )
{
struct V_30 * V_31 ;
T_2 V_19 ;
struct V_32 * V_33 , * V_34 ;
char V_35 [ sizeof( V_36 ) + 2 ] ;
int V_37 = - V_38 ;
if ( F_20 ( V_13 ) ) {
if ( V_14 ) {
F_21 ( V_13 , L_3 ) ;
return - V_38 ;
} else {
V_14 = F_20 ( V_13 ) ;
}
}
if ( ! V_14 )
return - V_38 ;
F_22 ( V_13 ) ;
V_19 = F_23 ( V_14 , & V_31 ) ;
if ( F_24 ( V_19 ) )
goto V_39;
V_33 = F_25 ( sizeof( * V_33 ) , V_40 ) ;
if ( ! V_33 ) {
V_37 = - V_41 ;
goto V_39;
}
F_26 ( & V_31 -> V_42 ) ;
F_10 (pn, &acpi_dev->physical_node_list, node)
if ( V_34 -> V_13 == V_13 ) {
F_21 ( V_13 , L_4 ) ;
goto V_43;
}
V_33 -> V_44 =
F_27 ( V_31 -> V_45 ,
V_46 ) ;
if ( V_33 -> V_44 >= V_46 ) {
V_37 = - V_47 ;
goto V_43;
}
F_28 ( V_33 -> V_44 , V_31 -> V_45 ) ;
V_33 -> V_13 = V_13 ;
F_3 ( & V_33 -> V_48 , & V_31 -> V_49 ) ;
V_31 -> V_50 ++ ;
F_29 ( & V_31 -> V_42 ) ;
if ( ! F_20 ( V_13 ) )
F_30 ( V_13 , V_31 -> V_14 ) ;
if ( ! V_33 -> V_44 )
strcpy ( V_35 , V_36 ) ;
else
sprintf ( V_35 ,
L_5 , V_33 -> V_44 ) ;
V_37 = F_31 ( & V_31 -> V_13 . V_51 , & V_13 -> V_51 ,
V_35 ) ;
V_37 = F_31 ( & V_13 -> V_51 , & V_31 -> V_13 . V_51 ,
L_6 ) ;
if ( V_31 -> V_52 . V_53 . V_25 )
F_32 ( V_13 , true ) ;
return 0 ;
V_39:
F_30 ( V_13 , NULL ) ;
F_33 ( V_13 ) ;
return V_37 ;
V_43:
F_29 ( & V_31 -> V_42 ) ;
F_16 ( V_33 ) ;
goto V_39;
}
static int F_34 ( struct V_12 * V_13 )
{
struct V_32 * V_54 ;
struct V_30 * V_31 ;
T_2 V_19 ;
struct V_55 * V_48 , * V_56 ;
if ( ! F_20 ( V_13 ) )
return 0 ;
V_19 = F_23 ( F_20 ( V_13 ) , & V_31 ) ;
if ( F_24 ( V_19 ) )
goto V_39;
F_26 ( & V_31 -> V_42 ) ;
F_35 (node, next, &acpi_dev->physical_node_list) {
char V_35 [ sizeof( V_36 ) + 2 ] ;
V_54 = F_36 ( V_48 , struct V_32 ,
V_48 ) ;
if ( V_54 -> V_13 != V_13 )
continue;
F_37 ( V_48 ) ;
F_38 ( V_54 -> V_44 , V_31 -> V_45 ) ;
V_31 -> V_50 -- ;
if ( ! V_54 -> V_44 )
strcpy ( V_35 , V_36 ) ;
else
sprintf ( V_35 ,
L_5 , V_54 -> V_44 ) ;
F_39 ( & V_31 -> V_13 . V_51 , V_35 ) ;
F_39 ( & V_13 -> V_51 , L_6 ) ;
F_30 ( V_13 , NULL ) ;
F_33 ( V_13 ) ;
F_16 ( V_54 ) ;
}
F_29 ( & V_31 -> V_42 ) ;
return 0 ;
V_39:
F_40 ( V_13 , L_7 ) ;
return - V_38 ;
}
static int F_41 ( struct V_12 * V_13 )
{
struct V_1 * type ;
T_1 V_14 ;
int V_11 = - V_38 ;
V_11 = F_19 ( V_13 , NULL ) ;
if ( ! V_11 )
goto V_57;
if ( ! V_13 -> V_4 || ! V_13 -> V_28 ) {
V_11 = F_12 ( V_13 , & V_14 ) ;
goto V_58;
}
type = F_8 ( V_13 -> V_4 ) ;
if ( ! type ) {
F_42 ( L_8 , F_43 ( V_13 ) ) ;
V_11 = - V_38 ;
goto V_58;
}
if ( ( V_11 = type -> V_5 ( V_13 , & V_14 ) ) != 0 )
F_42 ( L_9 , F_43 ( V_13 ) ) ;
V_58:
if ( ! V_11 )
F_19 ( V_13 , V_14 ) ;
V_57:
#if V_59
if ( ! V_11 ) {
struct V_60 V_61 = { V_62 , NULL } ;
F_44 ( F_20 ( V_13 ) , V_63 , & V_61 ) ;
F_42 ( L_10 , F_43 ( V_13 ) , ( char * ) V_61 . V_64 ) ;
F_16 ( V_61 . V_64 ) ;
} else
F_42 ( L_11 , F_43 ( V_13 ) ) ;
#endif
return V_11 ;
}
static int F_45 ( struct V_12 * V_13 )
{
F_34 ( V_13 ) ;
return 0 ;
}
int T_5 F_46 ( void )
{
if ( V_65 || V_66 ) {
F_5 (KERN_ERR PREFIX L_12 ) ;
return 0 ;
}
V_65 = F_41 ;
V_66 = F_45 ;
return 0 ;
}
