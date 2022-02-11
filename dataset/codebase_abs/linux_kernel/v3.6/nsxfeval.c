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
V_21 -> V_2 = V_2 ;
V_21 -> V_25 = F_10 ( V_1 ) ;
if ( ! V_21 -> V_25 ) {
V_8 = V_10 ;
goto V_26;
}
if ( V_4 && V_4 -> V_27 ) {
V_21 -> V_28 = F_9 ( ( ( T_6 )
V_4 ->
V_27 +
1 ) * sizeof( void * ) ) ;
if ( ! V_21 -> V_28 ) {
V_8 = V_24 ;
goto V_26;
}
for ( V_23 = 0 ; V_23 < V_4 -> V_27 ; V_23 ++ ) {
V_8 =
F_11 ( & V_4 ->
V_18 [ V_23 ] ,
& V_21 ->
V_28 [ V_23 ] ) ;
if ( F_5 ( V_8 ) ) {
goto V_26;
}
}
V_21 -> V_28 [ V_4 -> V_27 ] = NULL ;
}
if ( ( V_2 ) && ( F_12 ( V_2 [ 0 ] ) ) ) {
V_21 -> V_25 = NULL ;
V_8 = F_13 ( V_21 ) ;
} else if ( ! V_1 ) {
if ( ! V_2 ) {
F_14 ( ( V_29 ,
L_3 ) ) ;
} else {
F_14 ( ( V_29 ,
L_4 ,
V_2 ) ) ;
}
V_8 = V_10 ;
} else {
V_8 = F_13 ( V_21 ) ;
}
if ( V_6 ) {
if ( ! V_21 -> V_30 ) {
V_6 -> V_11 = 0 ;
} else {
if ( F_15 ( V_21 -> V_30 ) ==
V_31 ) {
V_8 = V_19 ;
V_21 -> V_30 = NULL ;
V_6 -> V_11 = 0 ;
}
if ( F_16 ( V_8 ) ) {
F_17 ( V_21 ) ;
V_8 =
F_18 ( V_21 -> V_30 ,
& V_22 ) ;
if ( F_16 ( V_8 ) ) {
V_8 =
F_19
( V_6 ,
V_22 ) ;
if ( F_5 ( V_8 ) ) {
F_14 ( ( V_29 ,
L_5 ,
( T_7 )
V_22 ,
F_20
( V_8 ) ) ) ;
} else {
V_8 =
F_21
( V_21 -> V_30 ,
V_6 ) ;
}
}
}
}
}
if ( V_21 -> V_30 ) {
F_22 () ;
F_23 ( V_21 -> V_30 ) ;
F_24 () ;
}
V_26:
if ( V_21 -> V_28 ) {
F_25 ( V_21 -> V_28 ) ;
}
F_8 ( V_21 ) ;
F_3 ( V_8 ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
union V_32 * V_33 = NULL ;
struct V_34 * V_35 ;
if ( ( V_21 -> V_30 ) -> V_36 . type != V_37 ) {
return;
}
switch ( V_21 -> V_30 -> V_38 . V_39 ) {
case V_40 :
V_33 = * ( V_21 -> V_30 -> V_38 . V_41 ) ;
break;
case V_42 :
V_35 = V_21 -> V_30 -> V_38 . V_43 ;
if ( V_35 ) {
V_33 = V_35 -> V_43 ;
}
break;
default:
return;
}
if ( V_33 ) {
F_26 ( V_33 ) ;
F_23 ( V_21 -> V_30 ) ;
V_21 -> V_30 = V_33 ;
}
return;
}
T_1
F_27 ( T_4 type ,
T_2 V_44 ,
T_7 V_45 ,
T_8 V_46 ,
T_8 V_47 ,
void * V_48 , void * * V_49 )
{
T_1 V_8 ;
F_2 ( F_27 ) ;
if ( ( type > V_50 ) ||
( ! V_45 ) || ( ! V_46 && ! V_47 ) ) {
F_3 ( V_10 ) ;
}
V_8 = F_28 ( & V_51 ) ;
if ( F_5 ( V_8 ) ) {
return V_8 ;
}
V_8 = F_29 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
goto V_53;
}
V_8 = F_30 ( type , V_44 , V_45 ,
V_54 , V_46 ,
V_47 , V_48 ,
V_49 ) ;
( void ) F_31 ( V_52 ) ;
V_53:
( void ) F_32 ( & V_51 ) ;
F_3 ( V_8 ) ;
}
static T_1
F_33 ( T_2 V_55 ,
T_7 V_56 ,
void * V_48 , void * * V_49 )
{
struct V_57 * V_21 = V_48 ;
T_1 V_8 ;
struct V_34 * V_35 ;
T_7 V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
T_7 V_23 ;
T_5 V_63 ;
int V_64 ;
V_8 = F_29 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_55 ) ;
V_8 = F_31 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
if ( ! V_35 ) {
return ( V_10 ) ;
}
if ( V_21 -> V_60 != NULL ) {
V_8 = F_34 ( V_35 , & V_60 ) ;
if ( V_8 == V_65 ) {
return ( V_14 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_66 ) ;
}
V_64 = F_35 ( V_60 -> string , V_21 -> V_60 ) ;
F_8 ( V_60 ) ;
if ( V_64 ) {
V_8 = F_36 ( V_35 , & V_62 ) ;
if ( V_8 == V_65 ) {
return ( V_14 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_66 ) ;
}
V_63 = 0 ;
for ( V_23 = 0 ; V_23 < V_62 -> V_27 ; V_23 ++ ) {
if ( F_35 ( V_62 -> V_67 [ V_23 ] . string , V_21 -> V_60 )
== 0 ) {
V_63 = 1 ;
break;
}
}
F_8 ( V_62 ) ;
if ( ! V_63 )
return ( V_14 ) ;
}
}
V_8 = F_37 ( V_35 , & V_58 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_66 ) ;
}
if ( ! ( V_58 & V_68 ) &&
! ( V_58 & V_69 ) ) {
return ( V_66 ) ;
}
V_8 = V_21 -> V_70 ( V_55 , V_56 , V_21 -> V_48 ,
V_49 ) ;
return ( V_8 ) ;
}
T_1
F_38 ( const char * V_71 ,
T_8 V_70 ,
void * V_48 , void * * V_49 )
{
T_1 V_8 ;
struct V_57 V_21 ;
F_2 ( F_38 ) ;
if ( ! V_70 ) {
F_3 ( V_10 ) ;
}
V_21 . V_60 = V_71 ;
V_21 . V_48 = V_48 ;
V_21 . V_70 = V_70 ;
V_8 = F_29 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_30 ( V_72 , V_73 ,
V_74 , V_54 ,
F_33 , NULL ,
& V_21 , V_49 ) ;
( void ) F_31 ( V_52 ) ;
F_3 ( V_8 ) ;
}
T_1
F_39 ( T_2 V_55 ,
T_9 V_75 , void * V_76 )
{
struct V_34 * V_35 ;
T_1 V_8 ;
if ( ! V_55 || ! V_75 || ! V_76 ) {
return ( V_10 ) ;
}
V_8 = F_29 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_55 ) ;
if ( ! V_35 ) {
V_8 = V_10 ;
goto V_53;
}
V_8 = F_40 ( V_35 , V_75 , V_76 ) ;
V_53:
( void ) F_31 ( V_52 ) ;
return ( V_8 ) ;
}
T_1
F_41 ( T_2 V_55 , T_9 V_75 )
{
struct V_34 * V_35 ;
T_1 V_8 ;
if ( ! V_55 || ! V_75 ) {
return ( V_10 ) ;
}
V_8 = F_29 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_55 ) ;
if ( ! V_35 ) {
V_8 = V_10 ;
goto V_53;
}
V_8 = F_42 ( V_35 , V_75 ) ;
V_53:
( void ) F_31 ( V_52 ) ;
return ( V_8 ) ;
}
T_1
F_43 ( T_2 V_55 , T_9 V_75 , void * * V_76 )
{
struct V_34 * V_35 ;
T_1 V_8 ;
if ( ! V_55 || ! V_75 || ! V_76 ) {
return ( V_10 ) ;
}
V_8 = F_29 ( V_52 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_55 ) ;
if ( ! V_35 ) {
V_8 = V_10 ;
goto V_53;
}
V_8 = F_44 ( V_35 , V_75 , V_76 ) ;
V_53:
( void ) F_31 ( V_52 ) ;
return ( V_8 ) ;
}
