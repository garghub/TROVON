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
struct V_32 * V_33 ;
char V_34 [ sizeof( V_35 ) + 2 ] ;
int V_36 = - V_37 ;
if ( V_13 -> V_38 . T_1 ) {
F_20 ( V_13 , L_3 ) ;
return - V_37 ;
}
F_21 ( V_13 ) ;
V_19 = F_22 ( V_14 , & V_31 ) ;
if ( F_23 ( V_19 ) )
goto V_39;
V_33 = F_24 ( sizeof( struct V_32 ) ,
V_40 ) ;
if ( ! V_33 ) {
V_36 = - V_41 ;
goto V_39;
}
F_25 ( & V_31 -> V_42 ) ;
V_33 -> V_43 =
F_26 ( V_31 -> V_44 ,
V_45 ) ;
if ( V_33 -> V_43 >= V_45 ) {
V_36 = - V_46 ;
F_27 ( & V_31 -> V_42 ) ;
F_16 ( V_33 ) ;
goto V_39;
}
F_28 ( V_33 -> V_43 , V_31 -> V_44 ) ;
V_33 -> V_13 = V_13 ;
F_3 ( & V_33 -> V_47 , & V_31 -> V_48 ) ;
V_31 -> V_49 ++ ;
F_27 ( & V_31 -> V_42 ) ;
V_13 -> V_38 . T_1 = V_14 ;
if ( ! V_33 -> V_43 )
strcpy ( V_34 , V_35 ) ;
else
sprintf ( V_34 ,
L_4 , V_33 -> V_43 ) ;
V_36 = F_29 ( & V_31 -> V_13 . V_50 , & V_13 -> V_50 ,
V_34 ) ;
V_36 = F_29 ( & V_13 -> V_50 , & V_31 -> V_13 . V_50 ,
L_5 ) ;
if ( V_31 -> V_51 . V_52 . V_25 )
F_30 ( V_13 , true ) ;
return 0 ;
V_39:
F_31 ( V_13 ) ;
return V_36 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_32 * V_53 ;
struct V_30 * V_31 ;
T_2 V_19 ;
struct V_54 * V_47 , * V_55 ;
if ( ! V_13 -> V_38 . T_1 )
return 0 ;
V_19 = F_22 ( V_13 -> V_38 . T_1 ,
& V_31 ) ;
if ( F_23 ( V_19 ) )
goto V_39;
F_25 ( & V_31 -> V_42 ) ;
F_33 (node, next, &acpi_dev->physical_node_list) {
char V_34 [ sizeof( V_35 ) + 2 ] ;
V_53 = F_34 ( V_47 , struct V_32 ,
V_47 ) ;
if ( V_53 -> V_13 != V_13 )
continue;
F_35 ( V_47 ) ;
F_36 ( V_53 -> V_43 , V_31 -> V_44 ) ;
V_31 -> V_49 -- ;
if ( ! V_53 -> V_43 )
strcpy ( V_34 , V_35 ) ;
else
sprintf ( V_34 ,
L_4 , V_53 -> V_43 ) ;
F_37 ( & V_31 -> V_13 . V_50 , V_34 ) ;
F_37 ( & V_13 -> V_50 , L_5 ) ;
V_13 -> V_38 . T_1 = NULL ;
F_31 ( V_13 ) ;
F_16 ( V_53 ) ;
}
F_27 ( & V_31 -> V_42 ) ;
return 0 ;
V_39:
F_38 ( V_13 , L_6 ) ;
return - V_37 ;
}
static int F_39 ( struct V_12 * V_13 )
{
struct V_1 * type ;
T_1 V_14 ;
int V_11 = - V_37 ;
if ( ! V_13 -> V_4 || ! V_13 -> V_28 ) {
V_11 = F_12 ( V_13 , & V_14 ) ;
goto V_56;
}
type = F_8 ( V_13 -> V_4 ) ;
if ( ! type ) {
F_40 ( L_7 , F_41 ( V_13 ) ) ;
V_11 = - V_37 ;
goto V_56;
}
if ( ( V_11 = type -> V_5 ( V_13 , & V_14 ) ) != 0 )
F_40 ( L_8 , F_41 ( V_13 ) ) ;
V_56:
if ( ! V_11 )
F_19 ( V_13 , V_14 ) ;
#if V_57
if ( ! V_11 ) {
struct V_58 V_59 = { V_60 , NULL } ;
F_42 ( V_13 -> V_38 . T_1 ,
V_61 , & V_59 ) ;
F_40 ( L_9 , F_41 ( V_13 ) , ( char * ) V_59 . V_62 ) ;
F_16 ( V_59 . V_62 ) ;
} else
F_40 ( L_10 , F_41 ( V_13 ) ) ;
#endif
return V_11 ;
}
static int F_43 ( struct V_12 * V_13 )
{
F_32 ( V_13 ) ;
return 0 ;
}
int T_5 F_44 ( void )
{
if ( V_63 || V_64 ) {
F_5 (KERN_ERR PREFIX L_11 ) ;
return 0 ;
}
V_63 = F_39 ;
V_64 = F_43 ;
return 0 ;
}
