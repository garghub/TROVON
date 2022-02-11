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
static void F_19 ( T_1 V_14 ,
void * V_17 )
{
}
struct V_12 * F_20 ( T_1 V_14 )
{
T_2 V_19 ;
struct V_12 * V_13 ;
V_19 = F_21 ( V_14 , F_19 , ( void * * ) & V_13 ) ;
if ( F_15 ( V_19 ) )
return F_22 ( V_13 ) ;
return NULL ;
}
static int F_23 ( struct V_12 * V_13 , T_1 V_14 )
{
struct V_30 * V_31 ;
T_2 V_19 ;
if ( V_13 -> V_32 . T_1 ) {
F_24 ( V_13 , L_3 ) ;
return - V_33 ;
}
F_22 ( V_13 ) ;
V_19 = F_25 ( V_14 , F_19 , V_13 ) ;
if ( F_26 ( V_19 ) ) {
F_27 ( V_13 ) ;
return - V_33 ;
}
V_13 -> V_32 . T_1 = V_14 ;
V_19 = F_28 ( V_14 , & V_31 ) ;
if ( ! F_26 ( V_19 ) ) {
int V_11 ;
V_11 = F_29 ( & V_13 -> V_34 , & V_31 -> V_13 . V_34 ,
L_4 ) ;
V_11 = F_29 ( & V_31 -> V_13 . V_34 , & V_13 -> V_34 ,
L_5 ) ;
if ( V_31 -> V_35 . V_36 . V_25 )
F_30 ( V_13 , true ) ;
}
return 0 ;
}
static int F_31 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_32 . T_1 )
return 0 ;
if ( V_13 == F_20 ( V_13 -> V_32 . T_1 ) ) {
struct V_30 * V_31 ;
F_27 ( V_13 ) ;
if ( ! F_28 ( V_13 -> V_32 . T_1 ,
& V_31 ) ) {
F_32 ( & V_13 -> V_34 , L_4 ) ;
F_32 ( & V_31 -> V_13 . V_34 , L_5 ) ;
}
F_33 ( V_13 -> V_32 . T_1 ,
F_19 ) ;
V_13 -> V_32 . T_1 = NULL ;
F_27 ( V_13 ) ;
} else {
F_34 ( V_13 , L_6 ) ;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_1 * type ;
T_1 V_14 ;
int V_11 = - V_33 ;
if ( ! V_13 -> V_4 || ! V_13 -> V_28 ) {
V_11 = F_12 ( V_13 , & V_14 ) ;
goto V_37;
}
type = F_8 ( V_13 -> V_4 ) ;
if ( ! type ) {
F_36 ( L_7 , F_37 ( V_13 ) ) ;
V_11 = - V_33 ;
goto V_37;
}
if ( ( V_11 = type -> V_5 ( V_13 , & V_14 ) ) != 0 )
F_36 ( L_8 , F_37 ( V_13 ) ) ;
V_37:
if ( ! V_11 )
F_23 ( V_13 , V_14 ) ;
#if V_38
if ( ! V_11 ) {
struct V_39 V_40 = { V_41 , NULL } ;
F_38 ( V_13 -> V_32 . T_1 ,
V_42 , & V_40 ) ;
F_36 ( L_9 , F_37 ( V_13 ) , ( char * ) V_40 . V_43 ) ;
F_16 ( V_40 . V_43 ) ;
} else
F_36 ( L_10 , F_37 ( V_13 ) ) ;
#endif
return V_11 ;
}
static int F_39 ( struct V_12 * V_13 )
{
F_31 ( V_13 ) ;
return 0 ;
}
int T_5 F_40 ( void )
{
if ( V_44 || V_45 ) {
F_5 (KERN_ERR PREFIX L_11 ) ;
return 0 ;
}
V_44 = F_35 ;
V_45 = F_39 ;
return 0 ;
}
