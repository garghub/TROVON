static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
V_2 -> V_4 . V_5 = 's' ;
V_2 -> V_4 . V_6 = V_3 * 8 ;
V_2 -> V_4 . V_7 = sizeof( V_8 ) * 8 ;
}
static int F_2 ( struct V_9 * V_10 ,
struct V_1 const * V_2 ,
int * V_11 , int * V_12 ,
long V_13 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
int V_16 = - 1 ;
V_8 V_17 ;
int V_18 ;
T_1 V_19 ;
* V_11 = 0 ;
* V_12 = 0 ;
switch ( V_13 ) {
case V_20 :
V_19 = F_4 (
& V_15 -> V_21 ) ;
if ( V_19 < 0 )
return - V_22 ;
F_5 ( & V_15 -> V_21 , true ) ;
F_6 ( V_19 * 2 ) ;
V_16 =
V_15 -> V_23 [ V_2 -> V_24 ] . V_16 ;
V_17 = V_25 [ V_2 -> V_24 ] ;
if ( V_16 >= 0 )
* V_11 = F_7 (
V_15 -> V_21 . V_26 ,
V_27 , V_17 ,
V_16 ) ;
else {
F_5 ( & V_15 -> V_21 ,
false ) ;
return - V_22 ;
}
F_5 ( & V_15 -> V_21 , false ) ;
V_18 = V_28 ;
break;
case V_29 :
* V_11 = V_15 -> V_30 ;
* V_12 = V_15 -> V_31 ;
V_18 = V_15 -> V_32 ;
break;
case V_33 :
* V_11 = V_15 -> V_34 ;
V_18 = V_28 ;
break;
case V_35 :
V_18 = F_8 (
& V_15 -> V_21 , V_11 , V_12 ) ;
break;
case V_36 :
V_18 = F_9 (
& V_15 -> V_21 , V_11 , V_12 ) ;
break;
default:
V_18 = - V_22 ;
break;
}
return V_18 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_1 const * V_2 ,
int V_11 ,
int V_12 ,
long V_13 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
int V_37 ;
switch ( V_13 ) {
case V_35 :
V_37 = F_11 (
& V_15 -> V_21 , V_11 , V_12 ) ;
break;
case V_36 :
V_37 = F_12 (
& V_15 -> V_21 , V_11 , V_12 ) ;
break;
default:
V_37 = - V_22 ;
}
return V_37 ;
}
static void F_13 ( struct V_9 * V_10 , T_2 * V_38 , int V_39 )
{
F_14 ( & V_10 -> V_40 , L_1 ) ;
F_15 ( V_10 , ( T_2 * ) V_38 ) ;
}
static int F_16 ( struct V_41 * V_26 ,
unsigned V_42 ,
void * V_43 )
{
struct V_9 * V_10 = F_17 ( V_43 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
F_14 ( & V_10 -> V_40 , L_2 ) ;
if ( F_18 ( & V_15 -> V_21 . V_44 ) )
F_13 ( V_10 ,
( T_2 * ) V_15 -> V_45 ,
sizeof( V_15 -> V_45 ) ) ;
return 0 ;
}
static int F_19 ( struct V_41 * V_26 ,
unsigned V_42 ,
T_3 V_46 , char * V_47 ,
void * V_43 )
{
struct V_9 * V_10 = F_17 ( V_43 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
int V_37 = 0 ;
switch ( V_42 ) {
case V_48 :
V_15 -> V_45 [ V_49 ] = * ( V_8 * ) V_47 ;
break;
case V_50 :
V_15 -> V_45 [ V_51 ] = * ( V_8 * ) V_47 ;
break;
case V_52 :
V_15 -> V_45 [ V_53 ] = * ( V_8 * ) V_47 ;
break;
default:
V_37 = - V_22 ;
break;
}
return V_37 ;
}
static int F_20 ( struct V_54 * V_55 ,
struct V_41 * V_26 ,
struct V_1 * V_56 ,
unsigned V_42 ,
struct V_14 * V_57 )
{
int V_37 ;
V_37 = F_21 ( V_26 ,
V_58 ,
V_42 ,
V_48 ,
& V_57 -> V_23 [ V_49 ] ) ;
if ( V_37 )
return V_37 ;
F_1 ( & V_56 [ V_49 ] ,
V_57 -> V_23 [ V_49 ] . V_3 ) ;
V_37 = F_21 ( V_26 ,
V_58 ,
V_42 ,
V_50 ,
& V_57 -> V_23 [ V_51 ] ) ;
if ( V_37 )
return V_37 ;
F_1 ( & V_56 [ V_51 ] ,
V_57 -> V_23 [ V_51 ] . V_3 ) ;
V_37 = F_21 ( V_26 ,
V_58 ,
V_42 ,
V_52 ,
& V_57 -> V_23 [ V_53 ] ) ;
if ( V_37 )
return V_37 ;
F_1 ( & V_56 [ V_53 ] ,
V_57 -> V_23 [ V_53 ] . V_3 ) ;
F_14 ( & V_55 -> V_40 , L_3 ,
V_57 -> V_23 [ 0 ] . V_59 ,
V_57 -> V_23 [ 0 ] . V_16 ,
V_57 -> V_23 [ 1 ] . V_59 , V_57 -> V_23 [ 1 ] . V_16 ,
V_57 -> V_23 [ 2 ] . V_59 , V_57 -> V_23 [ 2 ] . V_16 ) ;
V_57 -> V_32 = F_22 (
V_27 ,
& V_57 -> V_23 [ V_49 ] ,
& V_57 -> V_30 , & V_57 -> V_31 ) ;
if ( V_57 -> V_21 . V_60 . V_59 < 0 ) {
F_21 ( V_26 ,
V_61 , V_42 ,
V_62 |
V_63 ,
& V_57 -> V_21 . V_60 ) ;
F_14 ( & V_55 -> V_40 , L_4 ,
V_57 -> V_21 . V_60 . V_59 ,
V_57 -> V_21 . V_60 . V_16 ) ;
}
return V_37 ;
}
static int F_23 ( struct V_54 * V_55 )
{
int V_37 ;
static char * V_64 = L_5 ;
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_41 * V_26 = V_55 -> V_40 . V_65 ;
struct V_1 * V_56 ;
V_10 = F_24 ( & V_55 -> V_40 ,
sizeof( struct V_14 ) ) ;
if ( V_10 == NULL )
return - V_66 ;
F_25 ( V_55 , V_10 ) ;
V_15 = F_3 ( V_10 ) ;
V_15 -> V_21 . V_26 = V_26 ;
V_15 -> V_21 . V_55 = V_55 ;
V_37 = F_26 ( V_26 ,
V_27 ,
& V_15 -> V_21 ) ;
if ( V_37 ) {
F_27 ( & V_55 -> V_40 , L_6 ) ;
return V_37 ;
}
V_56 = F_28 ( V_67 , sizeof( V_67 ) ,
V_68 ) ;
if ( ! V_56 ) {
F_27 ( & V_55 -> V_40 , L_7 ) ;
return - V_66 ;
}
V_37 = F_20 ( V_55 , V_26 , V_56 ,
V_27 , V_15 ) ;
if ( V_37 ) {
F_27 ( & V_55 -> V_40 , L_8 ) ;
goto V_69;
}
V_10 -> V_56 = V_56 ;
V_10 -> V_70 = F_29 ( V_67 ) ;
V_10 -> V_40 . V_71 = & V_55 -> V_40 ;
V_10 -> V_72 = & V_73 ;
V_10 -> V_64 = V_64 ;
V_10 -> V_74 = V_75 ;
V_37 = F_30 ( V_10 , & V_76 ,
NULL , NULL ) ;
if ( V_37 ) {
F_27 ( & V_55 -> V_40 , L_9 ) ;
goto V_69;
}
F_31 ( & V_15 -> V_21 . V_44 , 0 ) ;
V_37 = F_32 ( V_10 , V_64 ,
& V_15 -> V_21 ) ;
if ( V_37 ) {
F_27 ( & V_55 -> V_40 , L_10 ) ;
goto V_77;
}
V_37 = F_33 ( V_10 ) ;
if ( V_37 ) {
F_27 ( & V_55 -> V_40 , L_11 ) ;
goto V_78;
}
V_15 -> V_79 . V_80 = F_16 ;
V_15 -> V_79 . V_81 = F_19 ;
V_15 -> V_79 . V_55 = V_55 ;
V_37 = F_34 ( V_26 ,
V_27 ,
& V_15 -> V_79 ) ;
if ( V_37 ) {
F_27 ( & V_55 -> V_40 , L_12 ) ;
goto V_82;
}
return 0 ;
V_82:
F_35 ( V_10 ) ;
V_78:
F_36 ( & V_15 -> V_21 ) ;
V_77:
F_37 ( V_10 ) ;
V_69:
F_38 ( V_10 -> V_56 ) ;
return V_37 ;
}
static int F_39 ( struct V_54 * V_55 )
{
struct V_41 * V_26 = V_55 -> V_40 . V_65 ;
struct V_9 * V_10 = F_17 ( V_55 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
F_40 ( V_26 , V_27 ) ;
F_35 ( V_10 ) ;
F_36 ( & V_15 -> V_21 ) ;
F_37 ( V_10 ) ;
F_38 ( V_10 -> V_56 ) ;
return 0 ;
}
