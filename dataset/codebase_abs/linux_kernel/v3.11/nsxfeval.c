T_1
F_1 ( T_2 V_1 ,
T_3 V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_4 V_7 )
{
T_1 V_8 ;
T_5 V_9 = FALSE ;
F_2 ( F_1 ) ;
if ( ! V_6 ) {
F_3 ( V_10 ) ;
}
if ( V_6 -> V_11 == V_12 ) {
V_9 = TRUE ;
}
V_8 =
F_4 ( V_1 , V_2 , V_4 ,
V_6 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
if ( V_7 == V_13 ) {
F_3 ( V_14 ) ;
}
if ( V_6 -> V_11 == 0 ) {
F_6 ( ( V_15 , L_1 ) ) ;
F_3 ( V_16 ) ;
}
if ( ( (union V_17 * ) V_6 -> V_18 ) -> type == V_7 ) {
F_3 ( V_14 ) ;
}
F_6 ( ( V_15 ,
L_2 ,
F_7 ( ( (union V_17 * ) V_6 ->
V_18 ) -> type ) ,
F_7 ( V_7 ) ) ) ;
if ( V_9 ) {
F_8 ( V_6 -> V_18 ) ;
V_6 -> V_18 = NULL ;
}
V_6 -> V_11 = 0 ;
F_3 ( V_19 ) ;
}
T_1
F_4 ( T_2 V_1 ,
T_3 V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_8 ;
struct V_20 * V_21 ;
T_6 V_22 ;
T_7 V_23 ;
F_2 ( F_4 ) ;
V_21 = F_9 ( sizeof( struct V_20 ) ) ;
if ( ! V_21 ) {
F_3 ( V_24 ) ;
}
V_21 -> V_25 = F_10 ( V_1 ) ;
if ( ! V_21 -> V_25 ) {
V_8 = V_10 ;
goto V_26;
}
if ( ( V_2 ) && ( F_11 ( V_2 [ 0 ] ) ) ) {
V_21 -> V_25 = NULL ;
} else if ( ! V_1 ) {
if ( ! V_2 ) {
F_12 ( ( V_27 ,
L_3 ) ) ;
} else {
F_12 ( ( V_27 ,
L_4 ,
V_2 ) ) ;
}
V_8 = V_10 ;
goto V_26;
}
V_21 -> V_28 = V_2 ;
if ( V_4 && V_4 -> V_29 ) {
V_21 -> V_30 = ( V_31 ) V_4 -> V_29 ;
if ( V_21 -> V_30 > V_32 ) {
F_13 ( ( V_15 , V_2 ,
V_33 ,
L_5 ,
V_21 -> V_30 ,
V_32 ) ) ;
V_21 -> V_30 = V_32 ;
}
V_21 -> V_34 = F_9 ( ( ( T_6 ) V_21 ->
V_30 +
1 ) * sizeof( void * ) ) ;
if ( ! V_21 -> V_34 ) {
V_8 = V_24 ;
goto V_26;
}
for ( V_23 = 0 ; V_23 < V_21 -> V_30 ; V_23 ++ ) {
V_8 =
F_14 ( & V_4 ->
V_18 [ V_23 ] ,
& V_21 ->
V_34 [ V_23 ] ) ;
if ( F_5 ( V_8 ) ) {
goto V_26;
}
}
V_21 -> V_34 [ V_21 -> V_30 ] = NULL ;
}
#if 0
switch (acpi_ns_get_type(info->node)) {
case ACPI_TYPE_METHOD:
if (info->obj_desc->method.param_count > info->param_count) {
ACPI_ERROR((AE_INFO,
"Insufficient arguments (%u) - %u are required",
info->param_count,
info->obj_desc->method.param_count));
status = AE_MISSING_ARGUMENTS;
goto cleanup;
}
else if (info->obj_desc->method.param_count < info->param_count) {
ACPI_WARNING((AE_INFO,
"Excess arguments (%u) - only %u are required",
info->param_count,
info->obj_desc->method.param_count));
info->param_count = info->obj_desc->method.param_count;
}
if (info->param_count) {
info->parameters = ACPI_ALLOCATE_ZEROED(((acpi_size)
info->
param_count +
1) *
sizeof(void *));
if (!info->parameters) {
status = AE_NO_MEMORY;
goto cleanup;
}
for (i = 0; i < info->param_count; i++) {
status =
acpi_ut_copy_eobject_to_iobject
(&external_params->pointer[i],
&info->parameters[i]);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
}
info->parameters[info->param_count] = NULL;
}
break;
default:
if (info->param_count) {
ACPI_WARNING((AE_INFO,
"%u arguments were passed to a non-method ACPI object",
info->param_count));
}
break;
}
#endif
V_8 = F_15 ( V_21 ) ;
if ( V_6 ) {
if ( ! V_21 -> V_35 ) {
V_6 -> V_11 = 0 ;
} else {
if ( F_16 ( V_21 -> V_35 ) ==
V_36 ) {
V_8 = V_19 ;
V_21 -> V_35 = NULL ;
V_6 -> V_11 = 0 ;
}
if ( F_17 ( V_8 ) ) {
F_18 ( V_21 ) ;
V_8 =
F_19 ( V_21 -> V_35 ,
& V_22 ) ;
if ( F_17 ( V_8 ) ) {
V_8 =
F_20
( V_6 ,
V_22 ) ;
if ( F_5 ( V_8 ) ) {
F_12 ( ( V_27 ,
L_6 ,
( T_7 )
V_22 ,
F_21
( V_8 ) ) ) ;
} else {
V_8 =
F_22
( V_21 -> V_35 ,
V_6 ) ;
}
}
}
}
}
if ( V_21 -> V_35 ) {
F_23 () ;
F_24 ( V_21 -> V_35 ) ;
F_25 () ;
}
V_26:
if ( V_21 -> V_34 ) {
F_26 ( V_21 -> V_34 ) ;
}
F_8 ( V_21 ) ;
F_3 ( V_8 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
union V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
if ( ( V_21 -> V_35 ) -> V_41 . type != V_42 ) {
return;
}
switch ( V_21 -> V_35 -> V_43 . V_44 ) {
case V_45 :
V_38 = * ( V_21 -> V_35 -> V_43 . V_46 ) ;
break;
case V_47 :
V_40 = V_21 -> V_35 -> V_43 . V_48 ;
if ( V_40 ) {
V_38 = V_40 -> V_48 ;
}
break;
default:
return;
}
if ( V_38 ) {
F_27 ( V_38 ) ;
F_24 ( V_21 -> V_35 ) ;
V_21 -> V_35 = V_38 ;
}
return;
}
T_1
F_28 ( T_4 type ,
T_2 V_49 ,
T_7 V_50 ,
T_8 V_51 ,
T_8 V_52 ,
void * V_53 , void * * V_54 )
{
T_1 V_8 ;
F_2 ( F_28 ) ;
if ( ( type > V_55 ) ||
( ! V_50 ) || ( ! V_51 && ! V_52 ) ) {
F_3 ( V_10 ) ;
}
V_8 = F_29 ( & V_56 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_30 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
goto V_58;
}
V_8 = F_31 ( type , V_49 , V_50 ,
V_59 , V_51 ,
V_52 , V_53 ,
V_54 ) ;
( void ) F_32 ( V_57 ) ;
V_58:
( void ) F_33 ( & V_56 ) ;
F_3 ( V_8 ) ;
}
static T_1
F_34 ( T_2 V_60 ,
T_7 V_61 ,
void * V_53 , void * * V_54 )
{
struct V_62 * V_21 = V_53 ;
T_1 V_8 ;
struct V_39 * V_40 ;
T_7 V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
T_7 V_23 ;
T_5 V_68 ;
int V_69 ;
V_8 = F_30 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_40 = F_10 ( V_60 ) ;
V_8 = F_32 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
if ( ! V_40 ) {
return ( V_10 ) ;
}
if ( V_21 -> V_65 != NULL ) {
V_8 = F_35 ( V_40 , & V_65 ) ;
if ( V_8 == V_70 ) {
return ( V_14 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_71 ) ;
}
V_69 = F_36 ( V_65 -> string , V_21 -> V_65 ) ;
F_8 ( V_65 ) ;
if ( V_69 ) {
V_8 = F_37 ( V_40 , & V_67 ) ;
if ( V_8 == V_70 ) {
return ( V_14 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_71 ) ;
}
V_68 = FALSE ;
for ( V_23 = 0 ; V_23 < V_67 -> V_29 ; V_23 ++ ) {
if ( F_36 ( V_67 -> V_72 [ V_23 ] . string , V_21 -> V_65 )
== 0 ) {
V_68 = TRUE ;
break;
}
}
F_8 ( V_67 ) ;
if ( ! V_68 ) {
return ( V_14 ) ;
}
}
}
V_8 = F_38 ( V_40 , & V_63 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_71 ) ;
}
if ( ! ( V_63 & V_73 ) &&
! ( V_63 & V_74 ) ) {
return ( V_71 ) ;
}
V_8 = V_21 -> V_75 ( V_60 , V_61 , V_21 -> V_53 ,
V_54 ) ;
return ( V_8 ) ;
}
T_1
F_39 ( const char * V_76 ,
T_8 V_75 ,
void * V_53 , void * * V_54 )
{
T_1 V_8 ;
struct V_62 V_21 ;
F_2 ( F_39 ) ;
if ( ! V_75 ) {
F_3 ( V_10 ) ;
}
V_21 . V_65 = V_76 ;
V_21 . V_53 = V_53 ;
V_21 . V_75 = V_75 ;
V_8 = F_30 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_31 ( V_77 , V_78 ,
V_79 , V_59 ,
F_34 , NULL ,
& V_21 , V_54 ) ;
( void ) F_32 ( V_57 ) ;
F_3 ( V_8 ) ;
}
T_1
F_40 ( T_2 V_60 ,
T_9 V_80 , void * V_81 )
{
struct V_39 * V_40 ;
T_1 V_8 ;
if ( ! V_60 || ! V_80 || ! V_81 ) {
return ( V_10 ) ;
}
V_8 = F_30 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_40 = F_10 ( V_60 ) ;
if ( ! V_40 ) {
V_8 = V_10 ;
goto V_58;
}
V_8 = F_41 ( V_40 , V_80 , V_81 ) ;
V_58:
( void ) F_32 ( V_57 ) ;
return ( V_8 ) ;
}
T_1
F_42 ( T_2 V_60 , T_9 V_80 )
{
struct V_39 * V_40 ;
T_1 V_8 ;
if ( ! V_60 || ! V_80 ) {
return ( V_10 ) ;
}
V_8 = F_30 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_40 = F_10 ( V_60 ) ;
if ( ! V_40 ) {
V_8 = V_10 ;
goto V_58;
}
V_8 = F_43 ( V_40 , V_80 ) ;
V_58:
( void ) F_32 ( V_57 ) ;
return ( V_8 ) ;
}
T_1
F_44 ( T_2 V_60 , T_9 V_80 , void * * V_81 )
{
struct V_39 * V_40 ;
T_1 V_8 ;
if ( ! V_60 || ! V_80 || ! V_81 ) {
return ( V_10 ) ;
}
V_8 = F_30 ( V_57 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_40 = F_10 ( V_60 ) ;
if ( ! V_40 ) {
V_8 = V_10 ;
goto V_58;
}
V_8 = F_45 ( V_40 , V_80 , V_81 ) ;
V_58:
( void ) F_32 ( V_57 ) ;
return ( V_8 ) ;
}
