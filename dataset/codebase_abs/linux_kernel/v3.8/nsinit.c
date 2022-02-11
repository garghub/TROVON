T_1 F_1 ( void )
{
T_1 V_1 ;
struct V_2 V_3 ;
F_2 ( V_4 ) ;
F_3 ( ( V_5 ,
L_1 ) ) ;
F_4 ( ( V_6 ,
L_2 ) ) ;
F_5 ( & V_3 , 0 , sizeof( struct V_2 ) ) ;
V_1 = F_6 ( V_7 , V_8 ,
V_9 , V_10 ,
NULL , & V_3 , NULL ) ;
if ( F_7 ( V_1 ) ) {
F_8 ( ( V_11 , V_1 , L_3 ) ) ;
}
F_4 ( ( V_6 ,
L_4
L_5 ,
V_3 . V_12 , V_3 . V_13 ,
V_3 . V_14 , V_3 . V_15 ,
V_3 . V_16 , V_3 . V_17 ,
V_3 . V_18 , V_3 . V_19 ,
V_3 . V_20 ) ) ;
F_3 ( ( V_5 ,
L_6 , V_3 . V_21 ) ) ;
F_3 ( ( V_5 ,
L_7 , V_3 . V_13 ) ) ;
F_9 ( V_22 ) ;
}
T_1 F_10 ( void )
{
T_1 V_1 ;
struct V_23 V_3 ;
F_2 ( V_24 ) ;
V_3 . V_25 = 0 ;
V_3 . V_26 = 0 ;
V_3 . V_27 = 0 ;
F_4 ( ( V_6 ,
L_8
L_9 ) ) ;
V_1 = F_11 ( V_7 , V_8 ,
V_9 , FALSE ,
V_28 , NULL , & V_3 ,
NULL ) ;
if ( F_7 ( V_1 ) ) {
goto V_29;
}
V_3 . V_30 =
F_12 ( sizeof( struct V_31 ) ) ;
if ( ! V_3 . V_30 ) {
V_1 = V_32 ;
goto V_29;
}
V_3 . V_30 -> V_33 = V_34 ;
V_3 . V_30 -> V_35 = V_36 ;
V_3 . V_30 -> V_37 = NULL ;
V_3 . V_30 -> V_38 = V_39 ;
V_1 = F_13 ( V_3 . V_30 ) ;
if ( F_14 ( V_1 ) ) {
V_3 . V_27 ++ ;
}
V_1 = F_11 ( V_7 , V_8 ,
V_9 , FALSE ,
V_40 , NULL , & V_3 ,
NULL ) ;
if ( V_41 >= V_42 ) {
V_43 = TRUE ;
}
F_15 ( V_3 . V_30 ) ;
if ( F_7 ( V_1 ) ) {
goto V_29;
}
F_4 ( ( V_6 ,
L_10
L_11 ,
V_3 . V_27 , V_3 . V_26 , V_3 . V_25 ) ) ;
F_9 ( V_1 ) ;
V_29:
F_8 ( ( V_11 , V_1 , L_12 ) ) ;
F_9 ( V_1 ) ;
}
static T_1
V_10 ( T_2 V_44 ,
T_3 V_45 , void * V_46 , void * * V_47 )
{
T_4 type ;
T_1 V_1 = V_22 ;
struct V_2 * V_3 =
(struct V_2 * ) V_46 ;
struct V_48 * V_49 =
(struct V_48 * ) V_44 ;
union V_50 * V_51 ;
F_16 ( V_52 ) ;
V_3 -> V_20 ++ ;
type = F_17 ( V_44 ) ;
V_51 = F_18 ( V_49 ) ;
if ( ! V_51 ) {
return ( V_22 ) ;
}
switch ( type ) {
case V_53 :
V_3 -> V_13 ++ ;
break;
case V_54 :
V_3 -> V_15 ++ ;
break;
case V_55 :
V_3 -> V_15 ++ ;
break;
case V_56 :
V_3 -> V_17 ++ ;
break;
case V_57 :
V_3 -> V_19 ++ ;
break;
default:
return ( V_22 ) ;
}
if ( V_51 -> V_58 . V_38 & V_59 ) {
return ( V_22 ) ;
}
F_19 () ;
switch ( type ) {
case V_53 :
V_3 -> V_12 ++ ;
V_1 = F_20 ( V_51 ) ;
break;
case V_54 :
V_3 -> V_14 ++ ;
V_1 = F_21 ( V_51 ) ;
break;
case V_55 :
V_3 -> V_14 ++ ;
V_1 = F_22 ( V_51 ) ;
break;
case V_56 :
V_3 -> V_16 ++ ;
V_1 = F_23 ( V_51 ) ;
break;
case V_57 :
V_3 -> V_18 ++ ;
V_1 = F_24 ( V_51 ) ;
break;
default:
break;
}
if ( F_7 ( V_1 ) ) {
F_8 ( ( V_11 , V_1 ,
L_13 ,
F_25 ( V_49 ) ,
F_26 ( type ) ) ) ;
}
if ( ! ( V_60 & V_61 ) ) {
F_4 ( ( V_6 , L_14 ) ) ;
}
F_27 () ;
return ( V_22 ) ;
}
static T_1
V_28 ( T_2 V_44 ,
T_3 V_62 , void * V_46 , void * * V_47 )
{
struct V_23 * V_3 =
F_28 ( struct V_23 , V_46 ) ;
struct V_48 * V_49 ;
struct V_48 * V_63 ;
V_49 = F_28 ( struct V_48 , V_44 ) ;
if ( ( V_49 -> type == V_64 ) ||
( V_49 -> type == V_65 ) ||
( V_49 -> type == V_66 ) ) {
V_3 -> V_25 ++ ;
return ( V_22 ) ;
}
if ( ! F_29 ( V_49 -> V_67 . V_68 , V_36 ) ) {
return ( V_22 ) ;
}
V_63 = V_49 -> V_69 ;
switch ( V_63 -> type ) {
case V_64 :
case V_65 :
case V_66 :
while ( V_63 ) {
V_63 -> V_38 |= V_70 ;
V_63 = V_63 -> V_69 ;
}
break;
default:
break;
}
return ( V_22 ) ;
}
static T_1
V_40 ( T_2 V_44 ,
T_3 V_62 , void * V_46 , void * * V_47 )
{
struct V_23 * V_71 =
F_28 ( struct V_23 , V_46 ) ;
struct V_31 * V_3 = V_71 -> V_30 ;
T_3 V_38 ;
T_1 V_1 ;
struct V_48 * V_72 ;
F_2 ( V_73 ) ;
V_72 = F_28 ( struct V_48 , V_44 ) ;
if ( ( V_72 -> type != V_64 ) &&
( V_72 -> type != V_65 ) &&
( V_72 -> type != V_66 ) ) {
F_9 ( V_22 ) ;
}
if ( ! ( V_72 -> V_38 & V_70 ) ) {
F_9 ( V_74 ) ;
}
F_30 ( F_31
( V_75 , V_72 , V_76 ) ) ;
V_1 = F_32 ( V_72 , & V_38 ) ;
if ( F_7 ( V_1 ) ) {
F_9 ( V_22 ) ;
}
if ( V_38 != V_9 ) {
V_71 -> V_26 ++ ;
}
if ( ! ( V_38 & V_77 ) ) {
if ( V_38 & V_78 ) {
F_9 ( V_22 ) ;
} else {
F_9 ( V_74 ) ;
}
}
F_30 ( F_31
( V_75 , V_72 , V_36 ) ) ;
V_3 -> V_33 = V_72 ;
V_3 -> V_35 = V_36 ;
V_3 -> V_37 = NULL ;
V_3 -> V_38 = V_39 ;
V_1 = F_13 ( V_3 ) ;
if ( F_14 ( V_1 ) ) {
V_71 -> V_27 ++ ;
if ( ( V_60 <= V_79 ) &&
( ! ( V_60 & V_80 ) ) ) {
F_4 ( ( V_6 , L_14 ) ) ;
}
}
#ifdef F_33
else if ( V_1 != V_81 ) {
char * V_82 =
F_34 ( V_3 -> V_83 ) ;
F_8 ( ( V_11 , V_1 , L_15 ,
V_82 ) ) ;
F_15 ( V_82 ) ;
}
#endif
V_1 = V_22 ;
if ( V_84 ) {
V_1 =
V_84 ( V_72 , V_85 ) ;
}
F_9 ( V_1 ) ;
}
