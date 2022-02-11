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
struct V_17 * V_18 = NULL ;
F_13 ( V_13 , & V_18 ) ;
if ( V_18 ) {
* V_16 = V_13 ;
return V_19 ;
}
return V_20 ;
}
static bool F_14 ( T_2 V_13 , bool V_21 )
{
unsigned long long V_22 ;
T_1 V_23 ;
V_23 = F_15 ( V_13 , & V_22 ) ;
if ( F_16 ( V_23 ) || ! ( V_22 & V_24 ) )
return false ;
if ( V_21 ) {
void * V_25 = NULL ;
F_17 ( V_26 , V_13 , 1 ,
F_12 , NULL , NULL , & V_25 ) ;
return ! ! V_25 ;
}
return true ;
}
static T_1 F_18 ( T_2 V_13 , T_3 V_14 ,
void * V_27 , void * * V_15 )
{
struct V_28 * V_29 = V_27 ;
unsigned long long V_30 ;
T_1 V_23 ;
V_23 = F_19 ( V_13 , V_31 , NULL , & V_30 ) ;
if ( F_16 ( V_23 ) || V_30 != V_29 -> V_30 )
return V_20 ;
if ( ! V_29 -> V_12 ) {
V_29 -> V_12 = V_13 ;
return V_20 ;
}
if ( ! V_29 -> V_32 ) {
if ( F_14 ( V_29 -> V_12 , V_29 -> V_21 ) )
return V_19 ;
else
V_29 -> V_32 = true ;
}
if ( F_14 ( V_13 , V_29 -> V_21 ) ) {
V_29 -> V_12 = V_13 ;
return V_19 ;
}
return V_20 ;
}
T_2 F_20 ( T_2 V_33 , T_4 V_30 , bool V_21 )
{
if ( V_33 ) {
struct V_28 V_29 = {
. V_30 = V_30 ,
. V_21 = V_21 ,
} ;
F_17 ( V_26 , V_33 , 1 , F_18 ,
NULL , & V_29 , NULL ) ;
return V_29 . V_12 ;
}
return NULL ;
}
int F_21 ( struct V_9 * V_10 , T_2 V_13 )
{
struct V_17 * V_34 ;
T_1 V_23 ;
struct V_35 * V_36 , * V_37 ;
char V_38 [ V_39 ] ;
struct V_40 * V_41 ;
unsigned int V_42 ;
int V_43 = - V_44 ;
if ( F_22 ( V_10 ) ) {
if ( V_13 ) {
F_23 ( V_10 , L_3 ) ;
return - V_44 ;
} else {
V_13 = F_22 ( V_10 ) ;
}
}
if ( ! V_13 )
return - V_44 ;
F_24 ( V_10 ) ;
V_23 = F_13 ( V_13 , & V_34 ) ;
if ( F_16 ( V_23 ) )
goto V_45;
V_36 = F_25 ( sizeof( * V_36 ) , V_46 ) ;
if ( ! V_36 ) {
V_43 = - V_47 ;
goto V_45;
}
F_26 ( & V_34 -> V_48 ) ;
V_41 = & V_34 -> V_49 ;
V_42 = 0 ;
F_10 (pn, &acpi_dev->physical_node_list, node) {
if ( V_37 -> V_10 == V_10 ) {
F_23 ( V_10 , L_4 ) ;
goto V_50;
}
if ( V_37 -> V_42 == V_42 ) {
V_41 = & V_37 -> V_51 ;
V_42 ++ ;
}
}
V_36 -> V_42 = V_42 ;
V_36 -> V_10 = V_10 ;
F_27 ( & V_36 -> V_51 , V_41 ) ;
V_34 -> V_52 ++ ;
F_28 ( & V_34 -> V_48 ) ;
if ( ! F_22 ( V_10 ) )
F_29 ( V_10 , V_34 -> V_13 ) ;
if ( ! V_36 -> V_42 )
strcpy ( V_38 , V_53 ) ;
else
sprintf ( V_38 ,
L_5 , V_36 -> V_42 ) ;
V_43 = F_30 ( & V_34 -> V_10 . V_54 , & V_10 -> V_54 ,
V_38 ) ;
V_43 = F_30 ( & V_10 -> V_54 , & V_34 -> V_10 . V_54 ,
L_6 ) ;
if ( V_34 -> V_55 . V_56 . V_57 )
F_31 ( V_10 , true ) ;
return 0 ;
V_45:
F_29 ( V_10 , NULL ) ;
F_32 ( V_10 ) ;
return V_43 ;
V_50:
F_28 ( & V_34 -> V_48 ) ;
F_33 ( V_36 ) ;
goto V_45;
}
int F_34 ( struct V_9 * V_10 )
{
struct V_35 * V_58 ;
struct V_17 * V_34 ;
T_1 V_23 ;
struct V_40 * V_51 , * V_59 ;
if ( ! F_22 ( V_10 ) )
return 0 ;
V_23 = F_13 ( F_22 ( V_10 ) , & V_34 ) ;
if ( F_16 ( V_23 ) )
goto V_45;
F_26 ( & V_34 -> V_48 ) ;
F_35 (node, next, &acpi_dev->physical_node_list) {
char V_38 [ V_39 ] ;
V_58 = F_36 ( V_51 , struct V_35 ,
V_51 ) ;
if ( V_58 -> V_10 != V_10 )
continue;
F_37 ( V_51 ) ;
V_34 -> V_52 -- ;
if ( ! V_58 -> V_42 )
strcpy ( V_38 , V_53 ) ;
else
sprintf ( V_38 ,
L_5 , V_58 -> V_42 ) ;
F_38 ( & V_34 -> V_10 . V_54 , V_38 ) ;
F_38 ( & V_10 -> V_54 , L_6 ) ;
F_29 ( V_10 , NULL ) ;
F_32 ( V_10 ) ;
F_33 ( V_58 ) ;
}
F_28 ( & V_34 -> V_48 ) ;
return 0 ;
V_45:
F_39 ( V_10 , L_7 ) ;
return - V_44 ;
}
static int F_40 ( struct V_9 * V_10 )
{
struct V_1 * type = F_8 ( V_10 ) ;
T_2 V_13 ;
int V_12 ;
V_12 = F_21 ( V_10 , NULL ) ;
if ( V_12 && type ) {
V_12 = type -> V_5 ( V_10 , & V_13 ) ;
if ( V_12 ) {
F_41 ( L_8 , F_42 ( V_10 ) ) ;
goto V_60;
}
V_12 = F_21 ( V_10 , V_13 ) ;
if ( V_12 )
goto V_60;
}
if ( type && type -> V_61 )
type -> V_61 ( V_10 ) ;
V_60:
#if V_62
if ( ! V_12 ) {
struct V_63 V_64 = { V_65 , NULL } ;
F_43 ( F_22 ( V_10 ) , V_66 , & V_64 ) ;
F_41 ( L_9 , F_42 ( V_10 ) , ( char * ) V_64 . V_67 ) ;
F_33 ( V_64 . V_67 ) ;
} else
F_41 ( L_10 , F_42 ( V_10 ) ) ;
#endif
return V_12 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_1 * type ;
type = F_8 ( V_10 ) ;
if ( type && type -> V_68 )
type -> V_68 ( V_10 ) ;
F_34 ( V_10 ) ;
return 0 ;
}
int T_5 F_45 ( void )
{
if ( V_69 || V_70 ) {
F_5 (KERN_ERR PREFIX L_11 ) ;
return 0 ;
}
V_69 = F_40 ;
V_70 = F_44 ;
return 0 ;
}
