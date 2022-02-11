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
static int F_12 ( struct V_13 * V_14 , bool V_15 )
{
bool V_16 = true ;
unsigned long long V_17 ;
T_1 V_18 ;
V_18 = F_13 ( V_14 -> V_19 , L_3 , NULL , & V_17 ) ;
if ( V_18 == V_20 )
V_16 = false ;
else if ( F_14 ( V_18 ) || ! ( V_17 & V_21 ) )
return - V_3 ;
if ( V_15 && F_15 ( & V_14 -> V_22 ) )
return - V_3 ;
return V_16 ? V_23 : V_24 ;
}
struct V_13 * F_16 ( struct V_13 * V_25 ,
T_2 V_26 , bool V_15 )
{
struct V_13 * V_14 , * V_12 = NULL ;
int V_27 = 0 ;
if ( ! V_25 )
return NULL ;
F_10 (adev, &parent->children, node) {
unsigned long long V_28 ;
T_1 V_18 ;
int V_29 ;
V_18 = F_13 ( V_14 -> V_19 , V_30 ,
NULL , & V_28 ) ;
if ( F_14 ( V_18 ) || V_28 != V_26 )
continue;
if ( ! V_12 ) {
V_12 = V_14 ;
continue;
}
if ( ! V_27 ) {
V_27 = F_12 ( V_12 , V_15 ) ;
if ( V_27 == V_23 )
return V_12 ;
}
V_29 = F_12 ( V_14 , V_15 ) ;
if ( V_29 == V_23 ) {
return V_14 ;
} else if ( V_29 > V_27 ) {
V_12 = V_14 ;
V_27 = V_29 ;
}
}
return V_12 ;
}
static void F_17 ( char * V_31 , unsigned int V_32 )
{
if ( V_32 > 0 )
snprintf ( V_31 , V_33 ,
V_34 L_4 , V_32 ) ;
else
strcpy ( V_31 , V_34 ) ;
}
int F_18 ( struct V_9 * V_10 , struct V_13 * V_35 )
{
struct V_36 * V_37 , * V_38 ;
char V_39 [ V_33 ] ;
struct V_40 * V_41 ;
unsigned int V_32 ;
int V_42 = - V_43 ;
if ( F_19 ( V_10 ) ) {
if ( V_35 ) {
F_20 ( V_10 , L_5 ) ;
return - V_43 ;
} else {
V_35 = F_19 ( V_10 ) ;
}
}
if ( ! V_35 )
return - V_43 ;
F_21 ( & V_35 -> V_10 ) ;
F_21 ( V_10 ) ;
V_37 = F_22 ( sizeof( * V_37 ) , V_44 ) ;
if ( ! V_37 ) {
V_42 = - V_45 ;
goto V_46;
}
F_23 ( & V_35 -> V_47 ) ;
V_41 = & V_35 -> V_48 ;
V_32 = 0 ;
F_10 (pn, &acpi_dev->physical_node_list, node) {
if ( V_38 -> V_10 == V_10 ) {
F_24 ( & V_35 -> V_47 ) ;
F_20 ( V_10 , L_6 ) ;
F_25 ( V_37 ) ;
if ( F_19 ( V_10 ) != V_35 )
goto V_46;
F_26 ( V_10 ) ;
F_26 ( & V_35 -> V_10 ) ;
return 0 ;
}
if ( V_38 -> V_32 == V_32 ) {
V_41 = & V_38 -> V_49 ;
V_32 ++ ;
}
}
V_37 -> V_32 = V_32 ;
V_37 -> V_10 = V_10 ;
F_27 ( & V_37 -> V_49 , V_41 ) ;
V_35 -> V_50 ++ ;
if ( ! F_19 ( V_10 ) )
F_28 ( V_10 , V_35 ) ;
F_17 ( V_39 , V_32 ) ;
V_42 = F_29 ( & V_35 -> V_10 . V_51 , & V_10 -> V_51 ,
V_39 ) ;
if ( V_42 )
F_30 ( & V_35 -> V_10 , L_7 ,
V_39 , V_42 ) ;
V_42 = F_29 ( & V_10 -> V_51 , & V_35 -> V_10 . V_51 ,
L_8 ) ;
if ( V_42 )
F_30 ( V_10 , L_9 ,
V_42 ) ;
F_24 ( & V_35 -> V_47 ) ;
if ( V_35 -> V_52 . V_53 . V_54 )
F_31 ( V_10 , true ) ;
return 0 ;
V_46:
F_28 ( V_10 , NULL ) ;
F_26 ( V_10 ) ;
F_26 ( & V_35 -> V_10 ) ;
return V_42 ;
}
int F_32 ( struct V_9 * V_10 )
{
struct V_13 * V_35 = F_19 ( V_10 ) ;
struct V_36 * V_55 ;
if ( ! V_35 )
return 0 ;
F_23 ( & V_35 -> V_47 ) ;
F_10 (entry, &acpi_dev->physical_node_list, node)
if ( V_55 -> V_10 == V_10 ) {
char V_56 [ V_33 ] ;
F_33 ( & V_55 -> V_49 ) ;
V_35 -> V_50 -- ;
F_17 ( V_56 , V_55 -> V_32 ) ;
F_34 ( & V_35 -> V_10 . V_51 , V_56 ) ;
F_34 ( & V_10 -> V_51 , L_8 ) ;
F_28 ( V_10 , NULL ) ;
F_26 ( V_10 ) ;
F_26 ( & V_35 -> V_10 ) ;
F_25 ( V_55 ) ;
break;
}
F_24 ( & V_35 -> V_47 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 )
{
struct V_1 * type = F_8 ( V_10 ) ;
int V_12 ;
V_12 = F_18 ( V_10 , NULL ) ;
if ( V_12 && type ) {
struct V_13 * V_14 ;
V_14 = type -> V_5 ( V_10 ) ;
if ( ! V_14 ) {
F_36 ( L_10 , F_37 ( V_10 ) ) ;
V_12 = - V_3 ;
goto V_57;
}
V_12 = F_18 ( V_10 , V_14 ) ;
if ( V_12 )
goto V_57;
}
if ( type && type -> V_58 )
type -> V_58 ( V_10 ) ;
V_57:
#if V_59
if ( ! V_12 ) {
struct V_60 V_61 = { V_62 , NULL } ;
F_38 ( F_39 ( V_10 ) , V_63 , & V_61 ) ;
F_36 ( L_11 , F_37 ( V_10 ) , ( char * ) V_61 . V_64 ) ;
F_25 ( V_61 . V_64 ) ;
} else
F_36 ( L_12 , F_37 ( V_10 ) ) ;
#endif
return V_12 ;
}
static int F_40 ( struct V_9 * V_10 )
{
struct V_1 * type ;
type = F_8 ( V_10 ) ;
if ( type && type -> V_65 )
type -> V_65 ( V_10 ) ;
F_32 ( V_10 ) ;
return 0 ;
}
int T_3 F_41 ( void )
{
if ( V_66 || V_67 ) {
F_5 (KERN_ERR PREFIX L_13 ) ;
return 0 ;
}
V_66 = F_35 ;
V_67 = F_40 ;
return 0 ;
}
