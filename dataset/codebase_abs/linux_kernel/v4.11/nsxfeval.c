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
V_8 = F_4 ( V_1 , V_2 ,
V_4 , V_6 ) ;
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
#ifdef F_15
switch ( F_16 ( V_21 -> V_35 ) ) {
case V_36 :
if ( V_21 -> V_37 -> V_38 . V_30 > V_21 -> V_30 ) {
F_6 ( ( V_15 ,
L_6 ,
V_21 -> V_30 ,
V_21 -> V_37 -> V_38 . V_30 ) ) ;
V_8 = V_39 ;
goto V_26;
}
else if ( V_21 -> V_37 -> V_38 . V_30 < V_21 -> V_30 ) {
F_17 ( ( V_15 ,
L_7 ,
V_21 -> V_30 ,
V_21 -> V_37 -> V_38 . V_30 ) ) ;
V_21 -> V_30 = V_21 -> V_37 -> V_38 . V_30 ;
}
if ( V_21 -> V_30 ) {
V_21 -> V_34 = F_9 ( ( ( T_6 )
V_21 ->
V_30 +
1 ) *
sizeof( void * ) ) ;
if ( ! V_21 -> V_34 ) {
V_8 = V_24 ;
goto V_26;
}
for ( V_23 = 0 ; V_23 < V_21 -> V_30 ; V_23 ++ ) {
V_8 =
F_14
( & V_4 -> V_18 [ V_23 ] ,
& V_21 -> V_34 [ V_23 ] ) ;
if ( F_5 ( V_8 ) ) {
goto V_26;
}
}
V_21 -> V_34 [ V_21 -> V_30 ] = NULL ;
}
break;
default:
if ( V_21 -> V_30 ) {
F_17 ( ( V_15 ,
L_8 ,
V_21 -> V_30 ) ) ;
}
break;
}
#endif
V_8 = F_18 ( V_21 ) ;
if ( ! V_6 ) {
goto V_40;
}
if ( ! V_21 -> V_41 ) {
V_6 -> V_11 = 0 ;
goto V_26;
}
if ( F_19 ( V_21 -> V_41 ) ==
V_42 ) {
V_8 = V_19 ;
V_21 -> V_41 = NULL ;
V_6 -> V_11 = 0 ;
}
if ( F_5 ( V_8 ) ) {
goto V_40;
}
F_20 ( V_21 ) ;
V_8 = F_21 ( V_21 -> V_41 ,
& V_22 ) ;
if ( F_22 ( V_8 ) ) {
V_8 = F_23 ( V_6 ,
V_22 ) ;
if ( F_5 ( V_8 ) ) {
F_12 ( ( V_27 ,
L_9 ,
( T_7 ) V_22 ,
F_24 ( V_8 ) ) ) ;
} else {
V_8 =
F_25 ( V_21 -> V_41 ,
V_6 ) ;
}
}
V_40:
if ( V_21 -> V_41 ) {
F_26 () ;
F_27 ( V_21 -> V_41 ) ;
F_28 () ;
}
V_26:
if ( V_21 -> V_34 ) {
F_29 ( V_21 -> V_34 ) ;
}
F_30 ( V_21 ) ;
F_3 ( V_8 ) ;
}
static void F_20 ( struct V_20 * V_21 )
{
union V_43 * V_37 = NULL ;
struct V_44 * V_35 ;
if ( ( V_21 -> V_41 ) -> V_45 . type != V_46 ) {
return;
}
switch ( V_21 -> V_41 -> V_47 . V_48 ) {
case V_49 :
V_37 = * ( V_21 -> V_41 -> V_47 . V_50 ) ;
break;
case V_51 :
V_35 = V_21 -> V_41 -> V_47 . V_52 ;
if ( V_35 ) {
V_37 = V_35 -> V_52 ;
}
break;
default:
return;
}
if ( V_37 ) {
F_31 ( V_37 ) ;
F_27 ( V_21 -> V_41 ) ;
V_21 -> V_41 = V_37 ;
}
return;
}
T_1
F_32 ( T_4 type ,
T_2 V_53 ,
T_7 V_54 ,
T_8 V_55 ,
T_8 V_56 ,
void * V_57 , void * * V_58 )
{
T_1 V_8 ;
F_2 ( F_32 ) ;
if ( ( type > V_59 ) ||
( ! V_54 ) || ( ! V_55 && ! V_56 ) ) {
F_3 ( V_10 ) ;
}
V_8 = F_33 ( & V_60 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_34 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
goto V_62;
}
if ( ! F_10 ( V_53 ) ) {
V_8 = V_10 ;
goto V_63;
}
V_8 = F_35 ( type , V_53 , V_54 ,
V_64 ,
V_55 , V_56 ,
V_57 , V_58 ) ;
V_63:
( void ) F_36 ( V_61 ) ;
V_62:
( void ) F_37 ( & V_60 ) ;
F_3 ( V_8 ) ;
}
static T_1
F_38 ( T_2 V_65 ,
T_7 V_66 ,
void * V_57 , void * * V_58 )
{
struct V_67 * V_21 = V_57 ;
T_1 V_8 ;
struct V_44 * V_35 ;
T_7 V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
T_7 V_23 ;
T_5 V_73 ;
int V_74 ;
V_8 = F_34 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_65 ) ;
V_8 = F_36 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
if ( ! V_35 ) {
return ( V_10 ) ;
}
if ( V_21 -> V_70 != NULL ) {
V_8 = F_39 ( V_35 , & V_70 ) ;
if ( V_8 == V_75 ) {
return ( V_14 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_76 ) ;
}
V_74 = strcmp ( V_70 -> string , V_21 -> V_70 ) ;
F_30 ( V_70 ) ;
if ( V_74 ) {
V_8 = F_40 ( V_35 , & V_72 ) ;
if ( V_8 == V_75 ) {
return ( V_14 ) ;
} else if ( F_5 ( V_8 ) ) {
return ( V_76 ) ;
}
V_73 = FALSE ;
for ( V_23 = 0 ; V_23 < V_72 -> V_29 ; V_23 ++ ) {
if ( strcmp ( V_72 -> V_77 [ V_23 ] . string , V_21 -> V_70 ) == 0 ) {
V_73 = TRUE ;
break;
}
}
F_30 ( V_72 ) ;
if ( ! V_73 ) {
return ( V_14 ) ;
}
}
}
V_8 = F_41 ( V_35 , & V_68 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_76 ) ;
}
if ( ! ( V_68 & V_78 ) &&
! ( V_68 & V_79 ) ) {
return ( V_76 ) ;
}
V_8 = V_21 -> V_80 ( V_65 , V_66 ,
V_21 -> V_57 , V_58 ) ;
return ( V_8 ) ;
}
T_1
F_42 ( const char * V_81 ,
T_8 V_80 ,
void * V_57 , void * * V_58 )
{
T_1 V_8 ;
struct V_67 V_21 ;
F_2 ( F_42 ) ;
if ( ! V_80 ) {
F_3 ( V_10 ) ;
}
V_21 . V_70 = V_81 ;
V_21 . V_57 = V_57 ;
V_21 . V_80 = V_80 ;
V_8 = F_34 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( V_8 ) ;
}
V_8 = F_35 ( V_82 , V_83 ,
V_84 , V_64 ,
F_38 , NULL ,
& V_21 , V_58 ) ;
( void ) F_36 ( V_61 ) ;
F_3 ( V_8 ) ;
}
T_1
F_43 ( T_2 V_65 ,
T_9 V_85 , void * V_86 )
{
struct V_44 * V_35 ;
T_1 V_8 ;
if ( ! V_65 || ! V_85 || ! V_86 ) {
return ( V_10 ) ;
}
V_8 = F_34 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_65 ) ;
if ( ! V_35 ) {
V_8 = V_10 ;
goto V_62;
}
V_8 = F_44 ( V_35 , V_85 , V_86 ) ;
V_62:
( void ) F_36 ( V_61 ) ;
return ( V_8 ) ;
}
T_1
F_45 ( T_2 V_65 , T_9 V_85 )
{
struct V_44 * V_35 ;
T_1 V_8 ;
if ( ! V_65 || ! V_85 ) {
return ( V_10 ) ;
}
V_8 = F_34 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_65 ) ;
if ( ! V_35 ) {
V_8 = V_10 ;
goto V_62;
}
V_8 = F_46 ( V_35 , V_85 ) ;
V_62:
( void ) F_36 ( V_61 ) ;
return ( V_8 ) ;
}
T_1
F_47 ( T_2 V_65 , T_9 V_85 ,
void * * V_86 , void (* F_48)( void * ) )
{
struct V_44 * V_35 ;
T_1 V_8 ;
if ( ! V_65 || ! V_85 || ! V_86 ) {
return ( V_10 ) ;
}
V_8 = F_34 ( V_61 ) ;
if ( F_5 ( V_8 ) ) {
return ( V_8 ) ;
}
V_35 = F_10 ( V_65 ) ;
if ( ! V_35 ) {
V_8 = V_10 ;
goto V_62;
}
V_8 = F_49 ( V_35 , V_85 , V_86 ) ;
if ( F_22 ( V_8 ) && F_48 ) {
F_48 ( * V_86 ) ;
}
V_62:
( void ) F_36 ( V_61 ) ;
return ( V_8 ) ;
}
T_1
F_50 ( T_2 V_65 , T_9 V_85 , void * * V_86 )
{
return F_47 ( V_65 , V_85 , V_86 , NULL ) ;
}
