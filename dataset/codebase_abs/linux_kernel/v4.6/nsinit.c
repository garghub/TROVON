T_1 F_1 ( void )
{
T_1 V_1 ;
struct V_2 V_3 ;
F_2 ( V_4 ) ;
F_3 ( ( V_5 ,
L_1 ) ) ;
F_3 ( ( V_6 ,
L_2 ) ) ;
F_4 ( ( V_7 ,
L_3 ) ) ;
memset ( & V_3 , 0 , sizeof( struct V_2 ) ) ;
V_1 = F_5 ( V_8 , V_9 ,
V_10 , V_11 ,
NULL , & V_3 , NULL ) ;
if ( F_6 ( V_1 ) ) {
F_7 ( ( V_12 , V_1 , L_4 ) ) ;
}
F_4 ( ( V_7 ,
L_5
L_6 ,
V_3 . V_13 , V_3 . V_14 ,
V_3 . V_15 , V_3 . V_16 ,
V_3 . V_17 , V_3 . V_18 ,
V_3 . V_19 , V_3 . V_20 ,
V_3 . V_21 ) ) ;
F_3 ( ( V_6 ,
L_7 ,
V_3 . V_22 , V_3 . V_14 ) ) ;
F_8 ( V_23 ) ;
}
T_1 F_9 ( T_2 V_24 )
{
T_1 V_1 = V_23 ;
struct V_25 V_3 ;
F_2 ( V_26 ) ;
if ( ! ( V_24 & V_27 ) ) {
F_3 ( ( V_5 ,
L_8 ) ) ;
V_3 . V_28 = 0 ;
V_3 . V_29 = 0 ;
V_3 . V_30 = 0 ;
F_4 ( ( V_7 ,
L_9
L_10 ) ) ;
V_1 = F_10 ( V_8 , V_9 ,
V_10 , FALSE ,
V_31 , NULL ,
& V_3 , NULL ) ;
if ( F_6 ( V_1 ) ) {
goto V_32;
}
V_3 . V_33 =
F_11 ( sizeof( struct V_34 ) ) ;
if ( ! V_3 . V_33 ) {
V_1 = V_35 ;
goto V_32;
}
V_3 . V_33 -> V_36 = V_37 ;
V_3 . V_33 -> V_38 = V_39 ;
V_3 . V_33 -> V_40 = NULL ;
V_3 . V_33 -> V_24 = V_41 ;
V_1 = F_12 ( V_3 . V_33 ) ;
if ( F_13 ( V_1 ) ) {
V_3 . V_30 ++ ;
}
}
if ( ! ( V_24 & V_42 ) ) {
F_3 ( ( V_5 ,
L_11 ) ) ;
V_1 = F_14 () ;
if ( F_6 ( V_1 ) ) {
goto V_32;
}
}
if ( ! ( V_24 & V_27 ) ) {
V_1 = F_10 ( V_8 , V_9 ,
V_10 , FALSE ,
V_43 , NULL ,
& V_3 , NULL ) ;
if ( V_44 >= V_45 ) {
V_46 = TRUE ;
}
F_15 ( V_3 . V_33 ) ;
if ( F_6 ( V_1 ) ) {
goto V_32;
}
F_4 ( ( V_7 ,
L_12
L_13 ,
V_3 . V_30 , V_3 . V_29 ,
V_3 . V_28 ) ) ;
}
F_8 ( V_1 ) ;
V_32:
F_7 ( ( V_12 , V_1 , L_14 ) ) ;
F_8 ( V_1 ) ;
}
static T_1
V_11 ( T_3 V_47 ,
T_2 V_48 , void * V_49 , void * * V_50 )
{
T_4 type ;
T_1 V_1 = V_23 ;
struct V_2 * V_3 =
(struct V_2 * ) V_49 ;
struct V_51 * V_52 =
(struct V_51 * ) V_47 ;
union V_53 * V_54 ;
F_16 ( V_55 ) ;
V_3 -> V_21 ++ ;
type = F_17 ( V_47 ) ;
V_54 = F_18 ( V_52 ) ;
if ( ! V_54 ) {
return ( V_23 ) ;
}
switch ( type ) {
case V_56 :
V_3 -> V_14 ++ ;
break;
case V_57 :
V_3 -> V_16 ++ ;
break;
case V_58 :
V_3 -> V_16 ++ ;
break;
case V_59 :
V_3 -> V_18 ++ ;
break;
case V_60 :
V_3 -> V_20 ++ ;
break;
default:
return ( V_23 ) ;
}
if ( V_54 -> V_61 . V_24 & V_62 ) {
return ( V_23 ) ;
}
F_19 () ;
switch ( type ) {
case V_56 :
V_3 -> V_13 ++ ;
V_1 = F_20 ( V_54 ) ;
break;
case V_57 :
V_3 -> V_15 ++ ;
V_1 = F_21 ( V_54 ) ;
break;
case V_58 :
V_3 -> V_15 ++ ;
V_1 = F_22 ( V_54 ) ;
break;
case V_59 :
V_3 -> V_17 ++ ;
V_1 = F_23 ( V_54 ) ;
break;
case V_60 :
V_3 -> V_19 ++ ;
V_1 = F_24 ( V_54 ) ;
break;
default:
break;
}
if ( F_6 ( V_1 ) ) {
F_7 ( ( V_12 , V_1 ,
L_15 ,
F_25 ( V_52 ) ,
F_26 ( type ) ) ) ;
}
F_27 () ;
return ( V_23 ) ;
}
static T_1
V_31 ( T_3 V_47 ,
T_2 V_63 , void * V_49 , void * * V_50 )
{
struct V_25 * V_3 =
F_28 ( struct V_25 , V_49 ) ;
struct V_51 * V_52 ;
struct V_51 * V_64 ;
V_52 = F_28 ( struct V_51 , V_47 ) ;
if ( ( V_52 -> type == V_65 ) ||
( V_52 -> type == V_66 ) ||
( V_52 -> type == V_67 ) ) {
V_3 -> V_28 ++ ;
return ( V_23 ) ;
}
if ( ! F_29 ( V_52 -> V_68 . V_69 , V_39 ) ) {
return ( V_23 ) ;
}
V_64 = V_52 -> V_70 ;
switch ( V_64 -> type ) {
case V_65 :
case V_66 :
case V_67 :
while ( V_64 ) {
V_64 -> V_24 |= V_71 ;
V_64 = V_64 -> V_70 ;
}
break;
default:
break;
}
return ( V_23 ) ;
}
static T_1
V_43 ( T_3 V_47 ,
T_2 V_63 , void * V_49 , void * * V_50 )
{
struct V_25 * V_72 =
F_28 ( struct V_25 , V_49 ) ;
struct V_34 * V_3 = V_72 -> V_33 ;
T_2 V_24 ;
T_1 V_1 ;
struct V_51 * V_73 ;
F_2 ( V_74 ) ;
V_73 = F_28 ( struct V_51 , V_47 ) ;
if ( ( V_73 -> type != V_65 ) &&
( V_73 -> type != V_66 ) &&
( V_73 -> type != V_67 ) ) {
F_8 ( V_23 ) ;
}
if ( ! ( V_73 -> V_24 & V_71 ) ) {
F_8 ( V_75 ) ;
}
F_30 ( F_31
( V_76 , V_73 , V_77 ) ) ;
V_1 = F_32 ( V_73 , & V_24 ) ;
if ( F_6 ( V_1 ) ) {
F_8 ( V_23 ) ;
}
if ( V_24 != V_10 ) {
V_72 -> V_29 ++ ;
}
if ( ! ( V_24 & V_78 ) ) {
if ( V_24 & V_79 ) {
F_8 ( V_23 ) ;
} else {
F_8 ( V_75 ) ;
}
}
F_30 ( F_31
( V_76 , V_73 , V_39 ) ) ;
memset ( V_3 , 0 , sizeof( struct V_34 ) ) ;
V_3 -> V_36 = V_73 ;
V_3 -> V_38 = V_39 ;
V_3 -> V_40 = NULL ;
V_3 -> V_24 = V_41 ;
V_1 = F_12 ( V_3 ) ;
if ( F_13 ( V_1 ) ) {
V_72 -> V_30 ++ ;
}
#ifdef F_33
else if ( V_1 != V_80 ) {
char * V_81 =
F_34 ( V_73 , TRUE ) ;
F_7 ( ( V_12 , V_1 , L_16 ,
V_81 ) ) ;
F_15 ( V_81 ) ;
}
#endif
V_1 = V_23 ;
if ( V_82 ) {
V_1 =
V_82 ( V_73 , V_83 ) ;
}
F_8 ( V_1 ) ;
}
