void
F_1 ( union V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
union V_1 * V_7 ;
T_1 V_8 ;
F_2 ( V_9 , V_2 ) ;
if ( ! V_10 &&
! ( V_11 & V_12 ) ) {
V_13 ;
}
V_6 = ( ( T_1 ) F_3 () / 10 ) ;
V_6 &= 0x03FFFFFF ;
if ( ! ( ( V_3 > 0 ) && V_4 == 0 ) ) {
F_4 ( L_1 , V_6 , V_3 , L_2 ) ;
}
if ( V_4 > 0 ) {
F_4 ( L_3 , V_4 - 1 ) ;
}
if ( ! V_2 ) {
F_4 ( L_4 ) ;
V_13 ;
}
if ( F_5 ( V_2 ) == V_14 ) {
F_4 ( L_5 ,
F_6 ( V_2 ) ) ;
if ( ! F_7 ( V_2 ) ) {
F_4 ( L_6 ,
V_2 ) ;
V_13 ;
}
} else if ( F_5 ( V_2 ) ==
V_15 ) {
F_4 ( L_7 ,
F_8 ( ( (struct
V_16 * )
V_2 ) -> type ) ,
V_2 ) ;
V_13 ;
} else {
V_13 ;
}
switch ( V_2 -> V_17 . type ) {
case V_18 :
if ( V_19 == 4 ) {
F_4 ( L_8 ,
( T_1 ) V_2 -> integer . V_8 ) ;
} else {
F_4 ( L_9 ,
F_9 ( V_2 -> integer .
V_8 ) ) ;
}
break;
case V_20 :
F_4 ( L_10 , ( T_1 ) V_2 -> V_21 . V_22 ) ;
F_10 ( V_2 -> V_21 . V_23 ,
( V_2 -> V_21 . V_22 < 256 ) ?
V_2 -> V_21 . V_22 : 256 ,
V_24 , 0 ) ;
break;
case V_25 :
F_4 ( L_11 ,
V_2 -> string . V_22 ,
V_2 -> string . V_23 ) ;
break;
case V_26 :
F_4 ( L_12 ,
V_2 -> V_27 . V_28 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_27 . V_28 ; V_5 ++ ) {
F_1 ( V_2 -> V_27 .
V_29 [ V_5 ] , V_3 + 4 , V_5 + 1 ) ;
}
break;
case V_30 :
F_4 ( L_13 ,
F_11 ( V_2 ) ) ;
switch ( V_2 -> V_31 . V_32 ) {
case V_33 :
F_4 ( L_14 , V_2 -> V_31 . V_8 ) ;
break;
case V_34 :
F_4 ( L_15 ,
V_2 -> V_31 . V_8 ) ;
V_13 ;
default:
break;
}
F_4 ( L_2 ) ;
if ( V_2 -> V_31 . V_35 ) {
if ( F_5
( V_2 -> V_31 . V_35 ) !=
V_15 ) {
F_4
( L_16 ,
V_2 -> V_31 . V_35 ) ;
} else {
F_4 ( L_17 ,
V_2 -> V_31 . V_35 ,
( V_2 -> V_31 . V_35 ) ->
V_36 . V_37 ) ;
switch ( ( V_2 -> V_31 . V_35 ) -> type ) {
case V_38 :
F_4 ( L_18 ) ;
break;
case V_39 :
F_4 ( L_19 ) ;
break;
default:
F_1 ( ( V_2 ->
V_31 .
V_35 ) -> V_40 ,
V_3 + 4 , 0 ) ;
break;
}
}
} else if ( V_2 -> V_31 . V_40 ) {
if ( F_5
( V_2 -> V_31 . V_40 ) ==
V_15 ) {
F_1 ( ( (struct
V_16 * )
V_2 -> V_31 .
V_40 ) -> V_40 ,
V_3 + 4 , 0 ) ;
} else {
V_7 = V_2 -> V_31 . V_40 ;
V_8 = V_2 -> V_31 . V_8 ;
switch ( V_7 -> V_17 . type ) {
case V_20 :
F_4 ( L_20 ,
V_8 ,
* V_2 -> V_31 .
V_41 ) ;
break;
case V_25 :
F_4
( L_21 ,
V_8 ,
* V_2 -> V_31 .
V_41 ,
* V_2 -> V_31 .
V_41 ) ;
break;
case V_26 :
F_4 ( L_22 , V_8 ) ;
F_1 ( * V_2 ->
V_31 . V_42 ,
V_3 + 4 , 0 ) ;
break;
default:
F_4
( L_23 ,
V_7 -> V_17 . type ) ;
break;
}
}
}
break;
default:
F_4 ( L_24 , V_2 ) ;
break;
}
F_12 ( ( V_43 , L_25 ) ) ;
V_13 ;
}
static T_2 F_13 ( char * V_36 )
{
if ( ! ( V_44 & V_45 ) ) {
return ( FALSE ) ;
}
if ( V_46 ) {
return ( TRUE ) ;
}
if ( V_36 &&
( V_47 &&
strcmp ( V_47 , V_36 ) ) ) {
return ( FALSE ) ;
}
if ( ( V_44 & V_48 ) &&
! V_47 ) {
return ( FALSE ) ;
}
return ( TRUE ) ;
}
static const char * F_14 ( T_3 type )
{
switch ( type ) {
case V_49 :
return L_26 ;
case V_50 :
return L_27 ;
case V_51 :
return L_28 ;
default:
return L_29 ;
}
}
void
F_15 ( T_3 type ,
T_2 V_52 , T_2 * V_53 , char * V_54 )
{
F_16 ( V_55 ) ;
if ( V_54 ) {
F_17 ( ( V_56 ,
L_30 ,
F_14 ( type ) ,
V_52 ? L_31 : L_32 , V_53 , V_54 ) ) ;
} else {
F_17 ( ( V_56 ,
L_33 ,
F_14 ( type ) ,
V_52 ? L_31 : L_32 , V_53 ) ) ;
}
}
void
F_18 ( struct V_16 * V_57 ,
union V_1 * V_58 ,
struct V_59 * V_60 )
{
T_4 V_61 ;
char * V_54 = NULL ;
T_2 V_62 = FALSE ;
F_16 ( V_63 ) ;
if ( V_57 ) {
V_54 = F_19 ( V_57 , TRUE ) ;
}
V_61 = F_20 ( V_64 ) ;
if ( F_21 ( V_61 ) ) {
goto exit;
}
V_62 = F_13 ( V_54 ) ;
if ( V_62 && ! V_46 ) {
V_46 = V_58 ;
V_65 = V_11 ;
V_66 = V_67 ;
V_11 = V_68 ;
V_67 = V_69 ;
if ( V_70 ) {
V_11 = V_70 ;
}
if ( V_71 ) {
V_67 = V_71 ;
}
}
( void ) F_22 ( V_64 ) ;
exit:
if ( V_62 ) {
F_23 ( V_49 , TRUE ,
V_58 ? V_58 -> V_72 . V_73 : NULL ,
V_54 ) ;
}
if ( V_54 ) {
F_24 ( V_54 ) ;
}
}
void
F_25 ( struct V_16 * V_57 ,
union V_1 * V_58 ,
struct V_59 * V_60 )
{
T_4 V_61 ;
char * V_54 = NULL ;
T_2 V_62 ;
F_16 ( V_74 ) ;
if ( V_57 ) {
V_54 = F_19 ( V_57 , TRUE ) ;
}
V_61 = F_20 ( V_64 ) ;
if ( F_21 ( V_61 ) ) {
goto V_75;
}
V_62 = F_13 ( NULL ) ;
( void ) F_22 ( V_64 ) ;
if ( V_62 ) {
F_23 ( V_49 , FALSE ,
V_58 ? V_58 -> V_72 . V_73 : NULL ,
V_54 ) ;
}
V_61 = F_20 ( V_64 ) ;
if ( F_21 ( V_61 ) ) {
goto V_75;
}
if ( V_46 == V_58 ) {
if ( V_44 & V_48 ) {
V_47 = NULL ;
}
V_11 = V_65 ;
V_67 = V_66 ;
V_46 = NULL ;
}
( void ) F_22 ( V_64 ) ;
V_75:
if ( V_54 ) {
F_24 ( V_54 ) ;
}
}
void
F_26 ( union V_76 * V_77 ,
struct V_59 * V_60 )
{
F_16 ( V_78 ) ;
if ( F_13 ( NULL ) &&
( V_44 & V_79 ) ) {
F_23 ( V_50 , TRUE ,
V_77 -> V_17 . V_53 , V_77 -> V_17 . V_80 ) ;
}
}
void
F_27 ( union V_76 * V_77 ,
struct V_59 * V_60 )
{
F_16 ( V_81 ) ;
if ( F_13 ( NULL ) &&
( V_44 & V_79 ) ) {
F_23 ( V_50 , FALSE ,
V_77 -> V_17 . V_53 , V_77 -> V_17 . V_80 ) ;
}
}
