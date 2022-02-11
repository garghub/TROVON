T_1
F_1 ( T_2 V_1 ,
T_3 V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_4 V_7 )
{
T_1 V_8 ;
T_5 V_9 = FALSE ;
T_2 V_10 ;
char * V_11 ;
F_2 ( F_1 ) ;
if ( ! V_6 ) {
F_3 ( V_12 ) ;
}
if ( V_6 -> V_13 == V_14 ) {
V_9 = TRUE ;
}
if ( V_2 ) {
V_8 = F_4 ( V_1 , V_2 , & V_10 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
} else {
V_10 = V_1 ;
}
V_11 = F_6 ( V_10 ) ;
if ( ! V_11 ) {
F_3 ( V_15 ) ;
}
V_8 = F_7 ( V_10 , NULL , V_4 ,
V_6 ) ;
if ( F_5 ( V_8 ) ) {
goto exit;
}
if ( V_7 == V_16 ) {
goto exit;
}
if ( V_6 -> V_13 == 0 ) {
F_8 ( ( V_17 , L_1 ,
V_11 ) ) ;
V_8 = V_18 ;
goto exit;
}
if ( ( (union V_19 * ) V_6 -> V_20 ) -> type == V_7 ) {
goto exit;
}
F_8 ( ( V_17 ,
L_2 ,
V_11 ,
F_9 ( ( (union V_19 * ) V_6 ->
V_20 ) -> type ) ,
F_9 ( V_7 ) ) ) ;
if ( V_9 ) {
F_10 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
V_6 -> V_13 = 0 ;
V_8 = V_21 ;
exit:
F_11 ( V_11 ) ;
F_3 ( V_8 ) ;
}
T_1
F_7 ( T_2 V_1 ,
T_3 V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_8 ;
struct V_22 * V_23 ;
T_6 V_24 ;
T_7 V_25 ;
F_2 ( F_7 ) ;
V_23 = F_12 ( sizeof( struct V_22 ) ) ;
if ( ! V_23 ) {
F_3 ( V_15 ) ;
}
V_23 -> V_26 = F_13 ( V_1 ) ;
if ( ! V_23 -> V_26 ) {
V_8 = V_12 ;
goto V_27;
}
if ( ( V_2 ) && ( F_14 ( V_2 [ 0 ] ) ) ) {
V_23 -> V_26 = NULL ;
} else if ( ! V_1 ) {
if ( ! V_2 ) {
F_15 ( ( V_28 ,
L_3 ) ) ;
} else {
F_15 ( ( V_28 ,
L_4 ,
V_2 ) ) ;
}
V_8 = V_12 ;
goto V_27;
}
V_23 -> V_29 = V_2 ;
if ( V_4 && V_4 -> V_30 ) {
V_23 -> V_31 = ( V_32 ) V_4 -> V_30 ;
if ( V_23 -> V_31 > V_33 ) {
F_16 ( ( V_17 , V_2 ,
V_34 ,
L_5 ,
V_23 -> V_31 ,
V_33 ) ) ;
V_23 -> V_31 = V_33 ;
}
V_23 -> V_35 = F_12 ( ( ( T_6 ) V_23 ->
V_31 +
1 ) * sizeof( void * ) ) ;
if ( ! V_23 -> V_35 ) {
V_8 = V_15 ;
goto V_27;
}
for ( V_25 = 0 ; V_25 < V_23 -> V_31 ; V_25 ++ ) {
V_8 =
F_17 ( & V_4 ->
V_20 [ V_25 ] ,
& V_23 ->
V_35 [ V_25 ] ) ;
if ( F_5 ( V_8 ) ) {
goto V_27;
}
}
V_23 -> V_35 [ V_23 -> V_31 ] = NULL ;
}
#ifdef F_18
switch ( F_19 ( V_23 -> V_36 ) ) {
case V_37 :
if ( V_23 -> V_38 -> V_39 . V_31 > V_23 -> V_31 ) {
F_8 ( ( V_17 ,
L_6 ,
V_23 -> V_31 ,
V_23 -> V_38 -> V_39 . V_31 ) ) ;
V_8 = V_40 ;
goto V_27;
}
else if ( V_23 -> V_38 -> V_39 . V_31 < V_23 -> V_31 ) {
F_20 ( ( V_17 ,
L_7 ,
V_23 -> V_31 ,
V_23 -> V_38 -> V_39 . V_31 ) ) ;
V_23 -> V_31 = V_23 -> V_38 -> V_39 . V_31 ;
}
if ( V_23 -> V_31 ) {
V_23 -> V_35 = F_12 ( ( ( T_6 )
V_23 ->
V_31 +
1 ) *
sizeof( void * ) ) ;
if ( ! V_23 -> V_35 ) {
V_8 = V_15 ;
goto V_27;
}
for ( V_25 = 0 ; V_25 < V_23 -> V_31 ; V_25 ++ ) {
V_8 =
F_17
( & V_4 -> V_20 [ V_25 ] ,
& V_23 -> V_35 [ V_25 ] ) ;
if ( F_5 ( V_8 ) ) {
goto V_27;
}
}
V_23 -> V_35 [ V_23 -> V_31 ] = NULL ;
}
break;
default:
if ( V_23 -> V_31 ) {
F_20 ( ( V_17 ,
L_8 ,
V_23 -> V_31 ) ) ;
}
break;
}
#endif
V_8 = F_21 ( V_23 ) ;
if ( ! V_6 ) {
goto V_41;
}
if ( ! V_23 -> V_42 ) {
V_6 -> V_13 = 0 ;
goto V_27;
}
if ( F_22 ( V_23 -> V_42 ) ==
V_43 ) {
V_8 = V_21 ;
V_23 -> V_42 = NULL ;
V_6 -> V_13 = 0 ;
}
if ( F_5 ( V_8 ) ) {
goto V_41;
}
F_23 ( V_23 ) ;
V_8 = F_24 ( V_23 -> V_42 ,
& V_24 ) ;
if ( F_25 ( V_8 ) ) {
V_8 = F_26 ( V_6 ,
V_24 ) ;
if ( F_5 ( V_8 ) ) {
F_15 ( ( V_28 ,
L_9 ,
( T_7 ) V_24 ,
F_27 ( V_8 ) ) ) ;
} else {
V_8 =
F_28 ( V_23 -> V_42 ,
V_6 ) ;
}
}
V_41:
if ( V_23 -> V_42 ) {
F_29 () ;
F_30 ( V_23 -> V_42 ) ;
F_31 () ;
}
V_27:
if ( V_23 -> V_35 ) {
F_32 ( V_23 -> V_35 ) ;
}
F_11 ( V_23 ) ;
F_3 ( V_8 ) ;
}
static void F_23 ( struct V_22 * V_23 )
{
union V_44 * V_38 = NULL ;
struct V_45 * V_36 ;
if ( ( V_23 -> V_42 ) -> V_46 . type != V_47 ) {
return;
}
switch ( V_23 -> V_42 -> V_48 . V_49 ) {
case V_50 :
V_38 = * ( V_23 -> V_42 -> V_48 . V_51 ) ;
break;
case V_52 :
V_36 = V_23 -> V_42 -> V_48 . V_53 ;
if ( V_36 ) {
V_38 = V_36 -> V_53 ;
}
break;
default:
return;
}
if ( V_38 ) {
F_33 ( V_38 ) ;
F_30 ( V_23 -> V_42 ) ;
V_23 -> V_42 = V_38 ;
}
return;
}
T_1
F_34 ( T_4 type ,
T_2 V_54 ,
T_7 V_55 ,
T_8 V_56 ,
T_8 V_57 ,
void * V_58 , void * * V_59 )
{
T_1 V_8 ;
F_2 ( F_34 ) ;
if ( ( type > V_60 ) ||
( ! V_55 ) || ( ! V_56 && ! V_57 ) ) {
F_3 ( V_12 ) ;
}
V_8 = F_35 ( & V_61 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_36 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
goto V_63;
}
if ( ! F_13 ( V_54 ) ) {
V_8 = V_12 ;
goto V_64;
}
V_8 = F_37 ( type , V_54 , V_55 ,
V_65 ,
V_56 , V_57 ,
V_58 , V_59 ) ;
V_64:
( void ) F_38 ( V_62 ) ;
V_63:
( void ) F_39 ( & V_61 ) ;
F_3 ( V_8 ) ;
}
static T_1
F_40 ( T_2 V_66 ,
T_7 V_67 ,
void * V_58 , void * * V_59 )
{
struct V_68 * V_23 = V_58 ;
T_1 V_8 ;
struct V_45 * V_36 ;
T_7 V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
T_7 V_25 ;
T_5 V_74 ;
int V_75 ;
V_8 = F_36 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_36 = F_13 ( V_66 ) ;
V_8 = F_38 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
if ( ! V_36 ) {
return ( V_12 ) ;
}
if ( V_23 -> V_71 != NULL ) {
V_8 = F_41 ( V_36 , & V_71 ) ;
if ( V_8 == V_76 ) {
return ( V_77 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_78 ) ;
}
V_75 = strcmp ( V_71 -> string , V_23 -> V_71 ) ;
F_11 ( V_71 ) ;
if ( V_75 ) {
V_8 = F_42 ( V_36 , & V_73 ) ;
if ( V_8 == V_76 ) {
return ( V_77 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_78 ) ;
}
V_74 = FALSE ;
for ( V_25 = 0 ; V_25 < V_73 -> V_30 ; V_25 ++ ) {
if ( strcmp ( V_73 -> V_79 [ V_25 ] . string , V_23 -> V_71 ) == 0 ) {
V_74 = TRUE ;
break;
}
}
F_11 ( V_73 ) ;
if ( ! V_74 ) {
return ( V_77 ) ;
}
}
}
V_8 = F_43 ( V_36 , & V_69 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_78 ) ;
}
if ( ! ( V_69 & V_80 ) &&
! ( V_69 & V_81 ) ) {
return ( V_78 ) ;
}
V_8 = V_23 -> V_82 ( V_66 , V_67 ,
V_23 -> V_58 , V_59 ) ;
return ( V_8 ) ;
}
T_1
F_44 ( const char * V_83 ,
T_8 V_82 ,
void * V_58 , void * * V_59 )
{
T_1 V_8 ;
struct V_68 V_23 ;
F_2 ( F_44 ) ;
if ( ! V_82 ) {
F_3 ( V_12 ) ;
}
V_23 . V_71 = V_83 ;
V_23 . V_58 = V_58 ;
V_23 . V_82 = V_82 ;
V_8 = F_36 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_37 ( V_84 , V_85 ,
V_86 , V_65 ,
F_40 , NULL ,
& V_23 , V_59 ) ;
( void ) F_38 ( V_62 ) ;
F_3 ( V_8 ) ;
}
T_1
F_45 ( T_2 V_66 ,
T_9 V_87 , void * V_88 )
{
struct V_45 * V_36 ;
T_1 V_8 ;
if ( ! V_66 || ! V_87 || ! V_88 ) {
return ( V_12 ) ;
}
V_8 = F_36 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_36 = F_13 ( V_66 ) ;
if ( ! V_36 ) {
V_8 = V_12 ;
goto V_63;
}
V_8 = F_46 ( V_36 , V_87 , V_88 ) ;
V_63:
( void ) F_38 ( V_62 ) ;
return ( V_8 ) ;
}
T_1
F_47 ( T_2 V_66 , T_9 V_87 )
{
struct V_45 * V_36 ;
T_1 V_8 ;
if ( ! V_66 || ! V_87 ) {
return ( V_12 ) ;
}
V_8 = F_36 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_36 = F_13 ( V_66 ) ;
if ( ! V_36 ) {
V_8 = V_12 ;
goto V_63;
}
V_8 = F_48 ( V_36 , V_87 ) ;
V_63:
( void ) F_38 ( V_62 ) ;
return ( V_8 ) ;
}
T_1
F_49 ( T_2 V_66 , T_9 V_87 ,
void * * V_88 , void (* F_50)( void * ) )
{
struct V_45 * V_36 ;
T_1 V_8 ;
if ( ! V_66 || ! V_87 || ! V_88 ) {
return ( V_12 ) ;
}
V_8 = F_36 ( V_62 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_36 = F_13 ( V_66 ) ;
if ( ! V_36 ) {
V_8 = V_12 ;
goto V_63;
}
V_8 = F_51 ( V_36 , V_87 , V_88 ) ;
if ( F_25 ( V_8 ) && F_50 ) {
F_50 ( * V_88 ) ;
}
V_63:
( void ) F_38 ( V_62 ) ;
return ( V_8 ) ;
}
T_1
F_52 ( T_2 V_66 , T_9 V_87 , void * * V_88 )
{
return F_49 ( V_66 , V_87 , V_88 , NULL ) ;
}
