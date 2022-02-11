T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
T_2 V_5 ,
union V_6 * * V_7 )
{
union V_3 * V_8 ;
union V_3 * V_9 ;
union V_6 * V_10 = NULL ;
T_1 V_11 = V_12 ;
T_3 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
F_2 ( V_16 ) ;
V_9 = V_4 -> V_17 . V_9 ;
while ( ( V_9 -> V_17 . V_18 == V_19 ) ||
( V_9 -> V_17 . V_18 == V_20 ) ) {
V_9 = V_9 -> V_17 . V_9 ;
}
V_10 = * V_7 ;
if ( ! V_10 ) {
V_10 = F_3 ( V_21 ) ;
* V_7 = V_10 ;
if ( ! V_10 ) {
F_4 ( V_22 ) ;
}
V_10 -> V_23 . V_24 = V_9 -> V_17 . V_24 ;
}
if ( V_10 -> V_23 . V_25 & V_26 ) {
F_4 ( V_12 ) ;
}
V_10 -> V_23 . V_27 = F_5 ( ( ( V_28 )
V_5 +
1 ) * sizeof( void * ) ) ;
if ( ! V_10 -> V_23 . V_27 ) {
F_6 ( V_10 ) ;
F_4 ( V_22 ) ;
}
V_10 -> V_23 . V_29 = V_5 ;
V_8 = V_4 -> V_17 . V_30 . V_8 ;
V_8 = V_8 -> V_17 . V_31 ;
if ( V_8 ) {
V_10 -> V_23 . V_25 |= V_26 ;
}
for ( V_15 = 0 ; V_8 && ( V_15 < V_5 ) ; V_15 ++ ) {
if ( V_8 -> V_17 . V_18 == V_32 ) {
if ( V_8 -> V_17 . V_24 -> type == V_33 ) {
V_8 -> V_17 . V_18 = V_34 ;
V_11 =
F_7 ( V_2 ,
V_8 ,
& V_10 ->
V_23 .
V_27 [ V_15 ] ) ;
} else {
V_10 -> V_23 . V_27 [ V_15 ] =
F_8 ( union V_6 ,
V_8 -> V_17 . V_24 ) ;
}
} else {
V_11 =
F_7 ( V_2 , V_8 ,
& V_10 -> V_23 .
V_27 [ V_15 ] ) ;
if ( V_11 == V_35 ) {
F_9 ( ( V_36 , L_1 ,
L_2 ) ) ;
}
F_10 ( 0 ,
V_10 -> V_23 .
V_27 [ V_15 ] , NULL ,
& V_10 -> V_23 .
V_27 [ V_15 ] ) ;
}
if ( * V_7 ) {
V_13 =
( * V_7 ) -> V_17 . V_13 ;
if ( V_13 > 1 ) {
for ( V_14 = 0 ;
V_14 < ( ( T_2 ) V_13 - 1 ) ;
V_14 ++ ) {
F_11 ( ( V_10 ->
V_23 .
V_27 [ V_15 ] ) ) ;
}
}
}
V_8 = V_8 -> V_17 . V_31 ;
}
if ( V_8 ) {
while ( V_8 ) {
if ( V_8 -> V_17 . V_24 ) {
F_12 ( F_8
( union
V_6 ,
V_8 -> V_17 . V_24 ) ) ;
V_8 -> V_17 . V_24 = NULL ;
}
V_15 ++ ;
V_8 = V_8 -> V_17 . V_31 ;
}
F_13 ( ( L_3
L_4 ,
V_15 , V_5 ) ) ;
} else if ( V_15 < V_5 ) {
F_14 ( ( V_37 ,
L_5
L_6 ,
V_15 , V_5 ) ) ;
}
V_10 -> V_23 . V_25 |= V_26 ;
V_4 -> V_17 . V_24 = F_8 ( struct V_38 , V_10 ) ;
F_4 ( V_11 ) ;
}
T_1
F_10 ( T_4 V_39 ,
union V_6 * V_40 ,
union V_41 * V_42 , void * V_43 )
{
union V_6 * * V_44 ;
if ( ! V_40 ) {
return ( V_12 ) ;
}
if ( V_43 ) {
V_44 = (union V_6 * * ) V_43 ;
} else {
V_44 = V_42 -> V_45 . V_46 ;
}
if ( V_40 -> V_17 . type == V_47 ) {
F_15 ( V_44 ) ;
} else if ( V_40 -> V_17 . type == V_21 ) {
V_40 -> V_23 . V_25 |= V_26 ;
}
return ( V_12 ) ;
}
static void
F_15 ( union V_6 * * V_44 )
{
T_1 V_11 ;
union V_41 V_48 ;
union V_6 * V_49 = * V_44 ;
struct V_38 * V_50 ;
char * V_51 = NULL ;
T_5 type ;
F_2 ( V_52 ) ;
if ( V_49 -> V_53 . V_54 ) {
V_55 ;
}
V_48 . V_56 . V_24 = V_49 -> V_53 . V_24 ;
V_11 = F_16 ( & V_48 , ( char * ) V_49 -> V_53 . V_57 ,
V_58 , V_59 ,
V_60 | V_61 ,
NULL , & V_50 ) ;
if ( F_17 ( V_11 ) ) {
V_11 = F_18 ( V_62 ,
( char * ) V_49 -> V_53 .
V_57 , NULL , & V_51 ) ;
F_19 ( ( V_36 , V_11 ,
L_7 ,
V_51 ) ) ;
F_20 ( V_51 ) ;
* V_44 = NULL ;
V_55 ;
} else if ( V_50 -> type == V_58 ) {
F_9 ( ( V_36 ,
L_8 ,
V_50 -> V_63 . V_64 ,
V_48 . V_56 . V_24 -> V_63 . V_64 ) ) ;
* V_44 = NULL ;
V_55 ;
}
#if 0
else if (resolved_node->flags & ANOBJ_TEMPORARY) {
ACPI_ERROR((AE_INFO,
"Package element refers to a temporary name [%4.4s], "
"inserting a NULL element",
resolved_node->name.ascii));
*element_ptr = NULL;
return_VOID;
}
#endif
if ( V_50 -> type == V_65 ) {
V_50 = F_8 ( struct V_38 ,
V_50 -> V_66 ) ;
}
V_49 -> V_53 . V_54 = TRUE ;
V_49 -> V_53 . V_24 = V_50 ;
type = V_49 -> V_53 . V_24 -> type ;
V_11 = F_21 ( & V_50 , NULL ) ;
if ( F_17 ( V_11 ) ) {
V_55 ;
}
#if 0
type = op->common.node->type;
if (type == ACPI_TYPE_LOCAL_ALIAS) {
type = obj_desc->common.type;
op->common.node = ACPI_CAST_PTR(struct acpi_namespace_node,
op->common.node->object);
}
#endif
switch ( type ) {
case V_67 :
case V_68 :
F_11 ( V_50 -> V_66 ) ;
break;
case V_69 :
case V_33 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
break;
default:
* V_44 = (union V_6 * ) V_50 ;
break;
}
V_55 ;
}
