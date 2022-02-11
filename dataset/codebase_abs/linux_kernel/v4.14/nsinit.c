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
T_3 V_26 ;
F_2 ( V_27 ) ;
if ( ! ( V_24 & V_28 ) ) {
F_3 ( ( V_5 ,
L_8 ) ) ;
V_3 . V_29 = 0 ;
V_3 . V_30 = 0 ;
V_3 . V_31 = 0 ;
F_4 ( ( V_7 ,
L_9
L_10 ) ) ;
V_1 = F_10 ( V_8 , V_9 ,
V_10 , FALSE ,
V_32 , NULL ,
& V_3 , NULL ) ;
if ( F_6 ( V_1 ) ) {
goto V_33;
}
V_3 . V_34 =
F_11 ( sizeof( struct V_35 ) ) ;
if ( ! V_3 . V_34 ) {
V_1 = V_36 ;
goto V_33;
}
V_3 . V_34 -> V_37 = V_38 ;
V_3 . V_34 -> V_39 = V_40 ;
V_3 . V_34 -> V_41 = NULL ;
V_3 . V_34 -> V_24 = V_42 ;
V_1 = F_12 ( V_3 . V_34 ) ;
if ( F_13 ( V_1 ) ) {
V_3 . V_31 ++ ;
}
V_1 = F_14 ( NULL , L_11 , & V_26 ) ;
if ( F_13 ( V_1 ) ) {
memset ( V_3 . V_34 , 0 ,
sizeof( struct V_35 ) ) ;
V_3 . V_34 -> V_37 = V_26 ;
V_3 . V_34 -> V_39 =
V_40 ;
V_3 . V_34 -> V_41 = NULL ;
V_3 . V_34 -> V_24 = V_42 ;
V_1 = F_12 ( V_3 . V_34 ) ;
if ( F_13 ( V_1 ) ) {
V_3 . V_31 ++ ;
}
}
}
if ( ! ( V_24 & V_43 ) ) {
F_3 ( ( V_5 ,
L_12 ) ) ;
V_1 = F_15 () ;
if ( F_6 ( V_1 ) ) {
goto V_33;
}
}
if ( ! ( V_24 & V_28 ) ) {
V_1 = F_10 ( V_8 , V_9 ,
V_10 , FALSE ,
V_44 , NULL ,
& V_3 , NULL ) ;
if ( V_45 >= V_46 ) {
V_47 = TRUE ;
}
F_16 ( V_3 . V_34 ) ;
if ( F_6 ( V_1 ) ) {
goto V_33;
}
F_4 ( ( V_7 ,
L_13
L_14 ,
V_3 . V_31 , V_3 . V_30 ,
V_3 . V_29 ) ) ;
}
F_8 ( V_1 ) ;
V_33:
F_7 ( ( V_12 , V_1 , L_15 ) ) ;
F_8 ( V_1 ) ;
}
static T_1
V_11 ( T_3 V_48 ,
T_2 V_49 , void * V_50 , void * * V_51 )
{
T_4 type ;
T_1 V_1 = V_23 ;
struct V_2 * V_3 =
(struct V_2 * ) V_50 ;
struct V_52 * V_53 =
(struct V_52 * ) V_48 ;
union V_54 * V_55 ;
F_17 ( V_56 ) ;
V_3 -> V_21 ++ ;
type = F_18 ( V_48 ) ;
V_55 = F_19 ( V_53 ) ;
if ( ! V_55 ) {
return ( V_23 ) ;
}
switch ( type ) {
case V_57 :
V_3 -> V_14 ++ ;
break;
case V_58 :
V_3 -> V_16 ++ ;
break;
case V_59 :
V_3 -> V_16 ++ ;
break;
case V_60 :
V_3 -> V_18 ++ ;
break;
case V_61 :
V_3 -> V_20 ++ ;
break;
default:
return ( V_23 ) ;
}
if ( V_55 -> V_62 . V_24 & V_63 ) {
return ( V_23 ) ;
}
F_20 () ;
switch ( type ) {
case V_57 :
V_3 -> V_13 ++ ;
V_1 = F_21 ( V_55 ) ;
break;
case V_58 :
V_3 -> V_15 ++ ;
V_1 = F_22 ( V_55 ) ;
break;
case V_59 :
V_3 -> V_15 ++ ;
V_1 = F_23 ( V_55 ) ;
break;
case V_60 :
V_3 -> V_17 ++ ;
V_1 = F_24 ( V_55 ) ;
break;
case V_61 :
V_3 -> V_19 ++ ;
V_1 = F_25 ( V_55 ) ;
if ( F_6 ( V_1 ) ) {
break;
}
V_1 = F_26 ( V_55 , NULL ,
V_64 ,
NULL ) ;
V_55 -> V_65 . V_24 |= V_63 ;
break;
default:
break;
}
if ( F_6 ( V_1 ) ) {
F_7 ( ( V_12 , V_1 ,
L_16 ,
F_27 ( V_53 ) ,
F_28 ( type ) ) ) ;
}
F_29 () ;
return ( V_23 ) ;
}
static T_1
V_32 ( T_3 V_48 ,
T_2 V_66 , void * V_50 , void * * V_51 )
{
struct V_25 * V_3 =
F_30 ( struct V_25 , V_50 ) ;
struct V_52 * V_53 ;
struct V_52 * V_67 ;
V_53 = F_30 ( struct V_52 , V_48 ) ;
if ( ( V_53 -> type == V_68 ) ||
( V_53 -> type == V_69 ) ||
( V_53 -> type == V_70 ) ) {
V_3 -> V_29 ++ ;
return ( V_23 ) ;
}
if ( ! F_31 ( V_53 -> V_71 . V_72 , V_40 ) ) {
return ( V_23 ) ;
}
V_67 = V_53 -> V_73 ;
switch ( V_67 -> type ) {
case V_68 :
case V_69 :
case V_70 :
while ( V_67 ) {
V_67 -> V_24 |= V_74 ;
V_67 = V_67 -> V_73 ;
}
break;
default:
break;
}
return ( V_23 ) ;
}
static T_1
V_44 ( T_3 V_48 ,
T_2 V_66 , void * V_50 , void * * V_51 )
{
struct V_25 * V_75 =
F_30 ( struct V_25 , V_50 ) ;
struct V_35 * V_3 = V_75 -> V_34 ;
T_2 V_24 ;
T_1 V_1 ;
struct V_52 * V_76 ;
F_2 ( V_77 ) ;
V_76 = F_30 ( struct V_52 , V_48 ) ;
if ( ( V_76 -> type != V_68 ) &&
( V_76 -> type != V_69 ) &&
( V_76 -> type != V_70 ) ) {
F_8 ( V_23 ) ;
}
if ( ! ( V_76 -> V_24 & V_74 ) ) {
F_8 ( V_78 ) ;
}
F_32 ( F_33
( V_79 , V_76 , V_80 ) ) ;
V_1 = F_34 ( V_76 , & V_24 ) ;
if ( F_6 ( V_1 ) ) {
F_8 ( V_23 ) ;
}
if ( V_24 != V_10 ) {
V_75 -> V_30 ++ ;
}
if ( ! ( V_24 & V_81 ) ) {
if ( V_24 & V_82 ) {
F_8 ( V_23 ) ;
} else {
F_8 ( V_78 ) ;
}
}
if ( ! F_31 ( V_76 -> V_71 . V_72 , L_17 ) ||
V_76 -> V_73 != V_38 ) {
F_32 ( F_33
( V_79 , V_76 ,
V_40 ) ) ;
memset ( V_3 , 0 , sizeof( struct V_35 ) ) ;
V_3 -> V_37 = V_76 ;
V_3 -> V_39 = V_40 ;
V_3 -> V_41 = NULL ;
V_3 -> V_24 = V_42 ;
V_1 = F_12 ( V_3 ) ;
if ( F_13 ( V_1 ) ) {
V_75 -> V_31 ++ ;
}
#ifdef F_35
else if ( V_1 != V_83 ) {
char * V_84 =
F_36 ( V_76 , TRUE ) ;
F_7 ( ( V_12 , V_1 ,
L_18 ,
V_84 ) ) ;
F_16 ( V_84 ) ;
}
#endif
}
V_1 = V_23 ;
if ( V_85 ) {
V_1 =
V_85 ( V_76 , V_86 ) ;
}
F_8 ( V_1 ) ;
}
