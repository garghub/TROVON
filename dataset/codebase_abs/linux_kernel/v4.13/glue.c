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
return V_16 && ! V_14 -> V_23 . type . V_24 ?
V_25 : V_26 ;
}
struct V_13 * F_16 ( struct V_13 * V_27 ,
T_2 V_28 , bool V_15 )
{
struct V_13 * V_14 , * V_12 = NULL ;
int V_29 = 0 ;
if ( ! V_27 )
return NULL ;
F_10 (adev, &parent->children, node) {
unsigned long long V_30 ;
T_1 V_18 ;
int V_31 ;
V_18 = F_13 ( V_14 -> V_19 , V_32 ,
NULL , & V_30 ) ;
if ( F_14 ( V_18 ) || V_30 != V_28 )
continue;
if ( ! V_12 ) {
V_12 = V_14 ;
continue;
}
if ( ! V_29 ) {
V_29 = F_12 ( V_12 , V_15 ) ;
if ( V_29 == V_25 )
return V_12 ;
}
V_31 = F_12 ( V_14 , V_15 ) ;
if ( V_31 == V_25 ) {
return V_14 ;
} else if ( V_31 > V_29 ) {
V_12 = V_14 ;
V_29 = V_31 ;
}
}
return V_12 ;
}
static void F_17 ( char * V_33 , unsigned int V_34 )
{
if ( V_34 > 0 )
snprintf ( V_33 , V_35 ,
V_36 L_4 , V_34 ) ;
else
strcpy ( V_33 , V_36 ) ;
}
int F_18 ( struct V_9 * V_10 , struct V_13 * V_37 )
{
struct V_38 * V_39 , * V_40 ;
char V_41 [ V_35 ] ;
struct V_42 * V_43 ;
unsigned int V_34 ;
int V_44 = - V_45 ;
if ( F_19 ( V_10 ) ) {
if ( V_37 ) {
F_20 ( V_10 , L_5 ) ;
return - V_45 ;
} else {
V_37 = F_21 ( V_10 ) ;
}
}
if ( ! V_37 )
return - V_45 ;
F_22 ( & V_37 -> V_10 ) ;
F_22 ( V_10 ) ;
V_39 = F_23 ( sizeof( * V_39 ) , V_46 ) ;
if ( ! V_39 ) {
V_44 = - V_47 ;
goto V_48;
}
F_24 ( & V_37 -> V_49 ) ;
V_43 = & V_37 -> V_50 ;
V_34 = 0 ;
F_10 (pn, &acpi_dev->physical_node_list, node) {
if ( V_40 -> V_10 == V_10 ) {
F_25 ( & V_37 -> V_49 ) ;
F_20 ( V_10 , L_6 ) ;
F_26 ( V_39 ) ;
if ( F_21 ( V_10 ) != V_37 )
goto V_48;
F_27 ( V_10 ) ;
F_27 ( & V_37 -> V_10 ) ;
return 0 ;
}
if ( V_40 -> V_34 == V_34 ) {
V_43 = & V_40 -> V_51 ;
V_34 ++ ;
}
}
V_39 -> V_34 = V_34 ;
V_39 -> V_10 = V_10 ;
F_28 ( & V_39 -> V_51 , V_43 ) ;
V_37 -> V_52 ++ ;
if ( ! F_19 ( V_10 ) )
F_29 ( V_10 , V_37 ) ;
F_17 ( V_41 , V_34 ) ;
V_44 = F_30 ( & V_37 -> V_10 . V_53 , & V_10 -> V_53 ,
V_41 ) ;
if ( V_44 )
F_31 ( & V_37 -> V_10 , L_7 ,
V_41 , V_44 ) ;
V_44 = F_30 ( & V_10 -> V_53 , & V_37 -> V_10 . V_53 ,
L_8 ) ;
if ( V_44 )
F_31 ( V_10 , L_9 ,
V_44 ) ;
F_25 ( & V_37 -> V_49 ) ;
if ( V_37 -> V_54 . V_55 . V_56 )
F_32 ( V_10 , true ) ;
return 0 ;
V_48:
F_29 ( V_10 , NULL ) ;
F_27 ( V_10 ) ;
F_27 ( & V_37 -> V_10 ) ;
return V_44 ;
}
int F_33 ( struct V_9 * V_10 )
{
struct V_13 * V_37 = F_21 ( V_10 ) ;
struct V_38 * V_57 ;
if ( ! V_37 )
return 0 ;
F_24 ( & V_37 -> V_49 ) ;
F_10 (entry, &acpi_dev->physical_node_list, node)
if ( V_57 -> V_10 == V_10 ) {
char V_58 [ V_35 ] ;
F_34 ( & V_57 -> V_51 ) ;
V_37 -> V_52 -- ;
F_17 ( V_58 , V_57 -> V_34 ) ;
F_35 ( & V_37 -> V_10 . V_53 , V_58 ) ;
F_35 ( & V_10 -> V_53 , L_8 ) ;
F_29 ( V_10 , NULL ) ;
F_27 ( V_10 ) ;
F_27 ( & V_37 -> V_10 ) ;
F_26 ( V_57 ) ;
break;
}
F_25 ( & V_37 -> V_49 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_1 * type = F_8 ( V_10 ) ;
struct V_13 * V_14 ;
int V_12 ;
V_12 = F_18 ( V_10 , NULL ) ;
if ( V_12 && type ) {
struct V_13 * V_14 ;
V_14 = type -> V_5 ( V_10 ) ;
if ( ! V_14 ) {
F_37 ( L_10 , F_38 ( V_10 ) ) ;
V_12 = - V_3 ;
goto V_59;
}
V_12 = F_18 ( V_10 , V_14 ) ;
if ( V_12 )
goto V_59;
}
V_14 = F_21 ( V_10 ) ;
if ( ! V_14 )
goto V_59;
if ( V_10 -> V_60 == & V_61 )
F_39 ( V_10 ) ;
if ( type && type -> V_62 )
type -> V_62 ( V_10 ) ;
else if ( V_14 -> V_63 && V_14 -> V_63 -> V_64 )
V_14 -> V_63 -> V_64 ( V_10 ) ;
V_59:
#if V_65
if ( ! V_12 ) {
struct V_66 V_67 = { V_68 , NULL } ;
F_40 ( F_41 ( V_10 ) , V_69 , & V_67 ) ;
F_37 ( L_11 , F_38 ( V_10 ) , ( char * ) V_67 . V_70 ) ;
F_26 ( V_67 . V_70 ) ;
} else
F_37 ( L_12 , F_38 ( V_10 ) ) ;
#endif
return V_12 ;
}
static int F_42 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_21 ( V_10 ) ;
struct V_1 * type ;
if ( ! V_14 )
return 0 ;
type = F_8 ( V_10 ) ;
if ( type && type -> V_71 )
type -> V_71 ( V_10 ) ;
else if ( V_14 -> V_63 && V_14 -> V_63 -> V_72 )
V_14 -> V_63 -> V_72 ( V_10 ) ;
F_33 ( V_10 ) ;
return 0 ;
}
void T_3 F_43 ( void )
{
if ( V_73 || V_74 ) {
F_5 (KERN_ERR PREFIX L_13 ) ;
return;
}
V_73 = F_36 ;
V_74 = F_42 ;
}
