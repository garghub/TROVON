int F_1 ( struct V_1 * type )
{
if ( V_2 )
return - V_3 ;
if ( type && type -> V_4 && type -> V_5 ) {
F_2 ( & V_6 ) ;
F_3 ( & type -> V_7 , & V_8 ) ;
F_4 ( & V_6 ) ;
F_5 (KERN_INFO PREFIX L_1 , type->name) ;
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
type->name) ;
return 0 ;
}
return - V_3 ;
}
static struct V_1 * F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_11 , * V_12 = NULL ;
F_9 ( & V_6 ) ;
F_10 (tmp, &bus_type_list, list) {
if ( V_11 -> V_4 ( V_10 ) ) {
V_12 = V_11 ;
break;
}
}
F_11 ( & V_6 ) ;
return V_12 ;
}
static T_1 F_12 ( T_2 V_13 , T_3 V_14 ,
void * V_15 , void * * V_16 )
{
unsigned long long V_17 ;
T_1 V_18 ;
V_18 = F_13 ( V_13 , V_19 , NULL , & V_17 ) ;
if ( F_14 ( V_18 ) && V_17 == * ( ( V_20 * ) V_15 ) ) {
* V_16 = V_13 ;
return V_21 ;
}
return V_22 ;
}
T_2 F_15 ( T_2 V_23 , V_20 V_24 )
{
void * V_12 = NULL ;
if ( ! V_23 )
return NULL ;
F_16 ( V_25 , V_23 , 1 , NULL ,
F_12 , & V_24 , & V_12 ) ;
return ( T_2 ) V_12 ;
}
static int F_17 ( struct V_9 * V_10 , T_2 V_13 )
{
struct V_26 * V_27 ;
T_1 V_18 ;
struct V_28 * V_29 , * V_30 ;
char V_31 [ sizeof( V_32 ) + 2 ] ;
int V_33 = - V_34 ;
if ( F_18 ( V_10 ) ) {
if ( V_13 ) {
F_19 ( V_10 , L_3 ) ;
return - V_34 ;
} else {
V_13 = F_18 ( V_10 ) ;
}
}
if ( ! V_13 )
return - V_34 ;
F_20 ( V_10 ) ;
V_18 = F_21 ( V_13 , & V_27 ) ;
if ( F_22 ( V_18 ) )
goto V_35;
V_29 = F_23 ( sizeof( * V_29 ) , V_36 ) ;
if ( ! V_29 ) {
V_33 = - V_37 ;
goto V_35;
}
F_24 ( & V_27 -> V_38 ) ;
F_10 (pn, &acpi_dev->physical_node_list, node)
if ( V_30 -> V_10 == V_10 ) {
F_19 ( V_10 , L_4 ) ;
goto V_39;
}
V_29 -> V_40 =
F_25 ( V_27 -> V_41 ,
V_42 ) ;
if ( V_29 -> V_40 >= V_42 ) {
V_33 = - V_43 ;
goto V_39;
}
F_26 ( V_29 -> V_40 , V_27 -> V_41 ) ;
V_29 -> V_10 = V_10 ;
F_3 ( & V_29 -> V_44 , & V_27 -> V_45 ) ;
V_27 -> V_46 ++ ;
F_27 ( & V_27 -> V_38 ) ;
if ( ! F_18 ( V_10 ) )
F_28 ( V_10 , V_27 -> V_13 ) ;
if ( ! V_29 -> V_40 )
strcpy ( V_31 , V_32 ) ;
else
sprintf ( V_31 ,
L_5 , V_29 -> V_40 ) ;
V_33 = F_29 ( & V_27 -> V_10 . V_47 , & V_10 -> V_47 ,
V_31 ) ;
V_33 = F_29 ( & V_10 -> V_47 , & V_27 -> V_10 . V_47 ,
L_6 ) ;
if ( V_27 -> V_48 . V_49 . V_50 )
F_30 ( V_10 , true ) ;
return 0 ;
V_35:
F_28 ( V_10 , NULL ) ;
F_31 ( V_10 ) ;
return V_33 ;
V_39:
F_27 ( & V_27 -> V_38 ) ;
F_32 ( V_29 ) ;
goto V_35;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_28 * V_51 ;
struct V_26 * V_27 ;
T_1 V_18 ;
struct V_52 * V_44 , * V_53 ;
if ( ! F_18 ( V_10 ) )
return 0 ;
V_18 = F_21 ( F_18 ( V_10 ) , & V_27 ) ;
if ( F_22 ( V_18 ) )
goto V_35;
F_24 ( & V_27 -> V_38 ) ;
F_34 (node, next, &acpi_dev->physical_node_list) {
char V_31 [ sizeof( V_32 ) + 2 ] ;
V_51 = F_35 ( V_44 , struct V_28 ,
V_44 ) ;
if ( V_51 -> V_10 != V_10 )
continue;
F_36 ( V_44 ) ;
F_37 ( V_51 -> V_40 , V_27 -> V_41 ) ;
V_27 -> V_46 -- ;
if ( ! V_51 -> V_40 )
strcpy ( V_31 , V_32 ) ;
else
sprintf ( V_31 ,
L_5 , V_51 -> V_40 ) ;
F_38 ( & V_27 -> V_10 . V_47 , V_31 ) ;
F_38 ( & V_10 -> V_47 , L_6 ) ;
F_28 ( V_10 , NULL ) ;
F_31 ( V_10 ) ;
F_32 ( V_51 ) ;
}
F_27 ( & V_27 -> V_38 ) ;
return 0 ;
V_35:
F_39 ( V_10 , L_7 ) ;
return - V_34 ;
}
static int F_40 ( struct V_9 * V_10 )
{
struct V_1 * type = F_8 ( V_10 ) ;
T_2 V_13 ;
int V_12 ;
V_12 = F_17 ( V_10 , NULL ) ;
if ( V_12 && type ) {
V_12 = type -> V_5 ( V_10 , & V_13 ) ;
if ( V_12 ) {
F_41 ( L_8 , F_42 ( V_10 ) ) ;
goto V_54;
}
V_12 = F_17 ( V_10 , V_13 ) ;
if ( V_12 )
goto V_54;
}
if ( type && type -> V_55 )
type -> V_55 ( V_10 ) ;
V_54:
#if V_56
if ( ! V_12 ) {
struct V_57 V_58 = { V_59 , NULL } ;
F_43 ( F_18 ( V_10 ) , V_60 , & V_58 ) ;
F_41 ( L_9 , F_42 ( V_10 ) , ( char * ) V_58 . V_61 ) ;
F_32 ( V_58 . V_61 ) ;
} else
F_41 ( L_10 , F_42 ( V_10 ) ) ;
#endif
return V_12 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_1 * type ;
type = F_8 ( V_10 ) ;
if ( type && type -> V_62 )
type -> V_62 ( V_10 ) ;
F_33 ( V_10 ) ;
return 0 ;
}
int T_4 F_45 ( void )
{
if ( V_63 || V_64 ) {
F_5 (KERN_ERR PREFIX L_11 ) ;
return 0 ;
}
V_63 = F_40 ;
V_64 = F_44 ;
return 0 ;
}
