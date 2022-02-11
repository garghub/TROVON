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
static int F_14 ( T_2 V_13 , bool V_21 )
{
bool V_22 = true ;
unsigned long long V_23 ;
T_1 V_24 ;
V_24 = F_15 ( V_13 , L_3 , NULL , & V_23 ) ;
if ( V_24 == V_25 )
V_22 = false ;
else if ( F_16 ( V_24 ) || ! ( V_23 & V_26 ) )
return - V_3 ;
if ( V_21 ) {
void * V_27 = NULL ;
F_17 ( V_28 , V_13 , 1 ,
F_12 , NULL , NULL , & V_27 ) ;
if ( ! V_27 )
return - V_3 ;
}
return V_22 ? V_29 : V_30 ;
}
static T_1 F_18 ( T_2 V_13 , T_3 V_14 ,
void * V_31 , void * * V_15 )
{
struct V_32 * V_33 = V_31 ;
unsigned long long V_34 ;
T_1 V_24 ;
int V_35 ;
V_24 = F_15 ( V_13 , V_36 , NULL , & V_34 ) ;
if ( F_16 ( V_24 ) || V_34 != V_33 -> V_34 )
return V_20 ;
if ( ! V_33 -> V_12 ) {
V_33 -> V_12 = V_13 ;
return V_20 ;
}
if ( ! V_33 -> V_37 ) {
V_35 = F_14 ( V_33 -> V_12 , V_33 -> V_21 ) ;
if ( V_35 == V_29 )
return V_19 ;
else
V_33 -> V_37 = V_35 ;
}
V_35 = F_14 ( V_13 , V_33 -> V_21 ) ;
if ( V_35 == V_29 ) {
V_33 -> V_12 = V_13 ;
return V_19 ;
} else if ( V_35 > V_33 -> V_37 ) {
V_33 -> V_12 = V_13 ;
V_33 -> V_37 = V_35 ;
}
return V_20 ;
}
T_2 F_19 ( T_2 V_38 , T_4 V_34 , bool V_21 )
{
if ( V_38 ) {
struct V_32 V_33 = {
. V_34 = V_34 ,
. V_21 = V_21 ,
} ;
F_17 ( V_28 , V_38 , 1 , F_18 ,
NULL , & V_33 , NULL ) ;
return V_33 . V_12 ;
}
return NULL ;
}
static void F_20 ( char * V_39 , unsigned int V_40 )
{
if ( V_40 > 0 )
snprintf ( V_39 , V_41 ,
V_42 L_4 , V_40 ) ;
else
strcpy ( V_39 , V_42 ) ;
}
int F_21 ( struct V_9 * V_10 , T_2 V_13 )
{
struct V_17 * V_43 = NULL ;
struct V_44 * V_45 , * V_46 ;
char V_47 [ V_41 ] ;
struct V_48 * V_49 ;
unsigned int V_40 ;
int V_50 = - V_51 ;
if ( F_22 ( V_10 ) ) {
if ( V_13 ) {
F_23 ( V_10 , L_5 ) ;
return - V_51 ;
} else {
V_43 = F_22 ( V_10 ) ;
}
} else {
F_13 ( V_13 , & V_43 ) ;
}
if ( ! V_43 )
return - V_51 ;
F_24 ( & V_43 -> V_10 ) ;
F_24 ( V_10 ) ;
V_45 = F_25 ( sizeof( * V_45 ) , V_52 ) ;
if ( ! V_45 ) {
V_50 = - V_53 ;
goto V_54;
}
F_26 ( & V_43 -> V_55 ) ;
V_49 = & V_43 -> V_56 ;
V_40 = 0 ;
F_10 (pn, &acpi_dev->physical_node_list, node) {
if ( V_46 -> V_10 == V_10 ) {
F_27 ( & V_43 -> V_55 ) ;
F_23 ( V_10 , L_6 ) ;
F_28 ( V_45 ) ;
if ( F_22 ( V_10 ) != V_43 )
goto V_54;
F_29 ( V_10 ) ;
F_29 ( & V_43 -> V_10 ) ;
return 0 ;
}
if ( V_46 -> V_40 == V_40 ) {
V_49 = & V_46 -> V_57 ;
V_40 ++ ;
}
}
V_45 -> V_40 = V_40 ;
V_45 -> V_10 = V_10 ;
F_30 ( & V_45 -> V_57 , V_49 ) ;
V_43 -> V_58 ++ ;
if ( ! F_22 ( V_10 ) )
F_31 ( V_10 , V_43 ) ;
F_20 ( V_47 , V_40 ) ;
V_50 = F_32 ( & V_43 -> V_10 . V_59 , & V_10 -> V_59 ,
V_47 ) ;
if ( V_50 )
F_33 ( & V_43 -> V_10 , L_7 ,
V_47 , V_50 ) ;
V_50 = F_32 ( & V_10 -> V_59 , & V_43 -> V_10 . V_59 ,
L_8 ) ;
if ( V_50 )
F_33 ( V_10 , L_9 ,
V_50 ) ;
F_27 ( & V_43 -> V_55 ) ;
if ( V_43 -> V_60 . V_61 . V_62 )
F_34 ( V_10 , true ) ;
return 0 ;
V_54:
F_31 ( V_10 , NULL ) ;
F_29 ( V_10 ) ;
F_29 ( & V_43 -> V_10 ) ;
return V_50 ;
}
int F_35 ( struct V_9 * V_10 )
{
struct V_17 * V_43 = F_22 ( V_10 ) ;
struct V_44 * V_63 ;
if ( ! V_43 )
return 0 ;
F_26 ( & V_43 -> V_55 ) ;
F_10 (entry, &acpi_dev->physical_node_list, node)
if ( V_63 -> V_10 == V_10 ) {
char V_64 [ V_41 ] ;
F_36 ( & V_63 -> V_57 ) ;
V_43 -> V_58 -- ;
F_20 ( V_64 , V_63 -> V_40 ) ;
F_37 ( & V_43 -> V_10 . V_59 , V_64 ) ;
F_37 ( & V_10 -> V_59 , L_8 ) ;
F_31 ( V_10 , NULL ) ;
F_29 ( V_10 ) ;
F_29 ( & V_43 -> V_10 ) ;
F_28 ( V_63 ) ;
break;
}
F_27 ( & V_43 -> V_55 ) ;
return 0 ;
}
void F_38 ( struct V_9 * V_10 , T_2 V_38 , T_4 V_34 )
{
struct V_17 * V_18 ;
if ( ! F_13 ( F_39 ( V_38 , V_34 ) , & V_18 ) )
F_31 ( V_10 , V_18 ) ;
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
F_41 ( L_10 , F_42 ( V_10 ) ) ;
goto V_65;
}
V_12 = F_21 ( V_10 , V_13 ) ;
if ( V_12 )
goto V_65;
}
if ( type && type -> V_66 )
type -> V_66 ( V_10 ) ;
V_65:
#if V_67
if ( ! V_12 ) {
struct V_68 V_69 = { V_70 , NULL } ;
F_43 ( F_44 ( V_10 ) , V_71 , & V_69 ) ;
F_41 ( L_11 , F_42 ( V_10 ) , ( char * ) V_69 . V_72 ) ;
F_28 ( V_69 . V_72 ) ;
} else
F_41 ( L_12 , F_42 ( V_10 ) ) ;
#endif
return V_12 ;
}
static int F_45 ( struct V_9 * V_10 )
{
struct V_1 * type ;
type = F_8 ( V_10 ) ;
if ( type && type -> V_73 )
type -> V_73 ( V_10 ) ;
F_35 ( V_10 ) ;
return 0 ;
}
int T_5 F_46 ( void )
{
if ( V_74 || V_75 ) {
F_5 (KERN_ERR PREFIX L_13 ) ;
return 0 ;
}
V_74 = F_40 ;
V_75 = F_45 ;
return 0 ;
}
