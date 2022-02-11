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
* V_11 = 0 ;
* V_12 = 0 ;
switch ( V_13 ) {
case V_19 :
F_4 ( & V_15 -> V_20 , true ) ;
V_16 =
V_15 -> V_21 [ V_2 -> V_22 ] . V_16 ;
V_17 = V_23 [ V_2 -> V_22 ] ;
if ( V_16 >= 0 )
* V_11 = F_5 (
V_15 -> V_20 . V_24 ,
V_25 , V_17 ,
V_16 ) ;
else {
F_4 ( & V_15 -> V_20 ,
false ) ;
return - V_26 ;
}
F_4 ( & V_15 -> V_20 , false ) ;
V_18 = V_27 ;
break;
case V_28 :
* V_11 = V_15 -> V_29 ;
* V_12 = V_15 -> V_30 ;
V_18 = V_15 -> V_31 ;
break;
case V_32 :
* V_11 = V_15 -> V_33 ;
V_18 = V_27 ;
break;
case V_34 :
V_18 = F_6 (
& V_15 -> V_20 , V_11 , V_12 ) ;
break;
case V_35 :
V_18 = F_7 (
& V_15 -> V_20 , V_11 , V_12 ) ;
break;
default:
V_18 = - V_26 ;
break;
}
return V_18 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_1 const * V_2 ,
int V_11 ,
int V_12 ,
long V_13 )
{
struct V_14 * V_15 = F_3 ( V_10 ) ;
int V_36 ;
switch ( V_13 ) {
case V_34 :
V_36 = F_9 (
& V_15 -> V_20 , V_11 , V_12 ) ;
break;
case V_35 :
V_36 = F_10 (
& V_15 -> V_20 , V_11 , V_12 ) ;
break;
default:
V_36 = - V_26 ;
}
return V_36 ;
}
static void F_11 ( struct V_9 * V_10 , T_1 * V_37 , int V_38 )
{
F_12 ( & V_10 -> V_39 , L_1 ) ;
F_13 ( V_10 , ( T_1 * ) V_37 ) ;
}
static int F_14 ( struct V_40 * V_24 ,
unsigned V_41 ,
void * V_42 )
{
struct V_9 * V_10 = F_15 ( V_42 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
F_12 ( & V_10 -> V_39 , L_2 ) ;
if ( F_16 ( & V_15 -> V_20 . V_43 ) )
F_11 ( V_10 ,
( T_1 * ) V_15 -> V_44 ,
sizeof( V_15 -> V_44 ) ) ;
return 0 ;
}
static int F_17 ( struct V_40 * V_24 ,
unsigned V_41 ,
T_2 V_45 , char * V_46 ,
void * V_42 )
{
struct V_9 * V_10 = F_15 ( V_42 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
int V_36 = 0 ;
switch ( V_41 ) {
case V_47 :
V_15 -> V_44 [ V_48 ] = * ( V_8 * ) V_46 ;
break;
case V_49 :
V_15 -> V_44 [ V_50 ] = * ( V_8 * ) V_46 ;
break;
case V_51 :
V_15 -> V_44 [ V_52 ] = * ( V_8 * ) V_46 ;
break;
default:
V_36 = - V_26 ;
break;
}
return V_36 ;
}
static int F_18 ( struct V_53 * V_54 ,
struct V_40 * V_24 ,
struct V_1 * V_55 ,
unsigned V_41 ,
struct V_14 * V_56 )
{
int V_36 ;
V_36 = F_19 ( V_24 ,
V_57 ,
V_41 ,
V_47 ,
& V_56 -> V_21 [ V_48 ] ) ;
if ( V_36 )
return V_36 ;
F_1 ( & V_55 [ V_48 ] ,
V_56 -> V_21 [ V_48 ] . V_3 ) ;
V_36 = F_19 ( V_24 ,
V_57 ,
V_41 ,
V_49 ,
& V_56 -> V_21 [ V_50 ] ) ;
if ( V_36 )
return V_36 ;
F_1 ( & V_55 [ V_50 ] ,
V_56 -> V_21 [ V_50 ] . V_3 ) ;
V_36 = F_19 ( V_24 ,
V_57 ,
V_41 ,
V_51 ,
& V_56 -> V_21 [ V_52 ] ) ;
if ( V_36 )
return V_36 ;
F_1 ( & V_55 [ V_52 ] ,
V_56 -> V_21 [ V_52 ] . V_3 ) ;
F_12 ( & V_54 -> V_39 , L_3 ,
V_56 -> V_21 [ 0 ] . V_58 ,
V_56 -> V_21 [ 0 ] . V_16 ,
V_56 -> V_21 [ 1 ] . V_58 , V_56 -> V_21 [ 1 ] . V_16 ,
V_56 -> V_21 [ 2 ] . V_58 , V_56 -> V_21 [ 2 ] . V_16 ) ;
V_56 -> V_31 = F_20 (
V_25 ,
& V_56 -> V_21 [ V_48 ] ,
& V_56 -> V_29 , & V_56 -> V_30 ) ;
if ( V_56 -> V_20 . V_59 . V_58 < 0 ) {
F_19 ( V_24 ,
V_60 , V_41 ,
V_61 |
V_62 ,
& V_56 -> V_20 . V_59 ) ;
F_12 ( & V_54 -> V_39 , L_4 ,
V_56 -> V_20 . V_59 . V_58 ,
V_56 -> V_20 . V_59 . V_16 ) ;
}
return V_36 ;
}
static int F_21 ( struct V_53 * V_54 )
{
int V_36 ;
static char * V_63 = L_5 ;
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_40 * V_24 = V_54 -> V_39 . V_64 ;
struct V_1 * V_55 ;
V_10 = F_22 ( & V_54 -> V_39 ,
sizeof( struct V_14 ) ) ;
if ( V_10 == NULL )
return - V_65 ;
F_23 ( V_54 , V_10 ) ;
V_15 = F_3 ( V_10 ) ;
V_15 -> V_20 . V_24 = V_24 ;
V_15 -> V_20 . V_54 = V_54 ;
V_36 = F_24 ( V_24 ,
V_25 ,
& V_15 -> V_20 ) ;
if ( V_36 ) {
F_25 ( & V_54 -> V_39 , L_6 ) ;
return V_36 ;
}
V_55 = F_26 ( V_66 , sizeof( V_66 ) ,
V_67 ) ;
if ( ! V_55 ) {
F_25 ( & V_54 -> V_39 , L_7 ) ;
return - V_65 ;
}
V_36 = F_18 ( V_54 , V_24 , V_55 ,
V_25 , V_15 ) ;
if ( V_36 ) {
F_25 ( & V_54 -> V_39 , L_8 ) ;
goto V_68;
}
V_10 -> V_55 = V_55 ;
V_10 -> V_69 = F_27 ( V_66 ) ;
V_10 -> V_39 . V_70 = & V_54 -> V_39 ;
V_10 -> V_71 = & V_72 ;
V_10 -> V_63 = V_63 ;
V_10 -> V_73 = V_74 ;
V_36 = F_28 ( V_10 , & V_75 ,
NULL , NULL ) ;
if ( V_36 ) {
F_25 ( & V_54 -> V_39 , L_9 ) ;
goto V_68;
}
F_29 ( & V_15 -> V_20 . V_43 , 0 ) ;
V_36 = F_30 ( V_10 , V_63 ,
& V_15 -> V_20 ) ;
if ( V_36 ) {
F_25 ( & V_54 -> V_39 , L_10 ) ;
goto V_76;
}
V_36 = F_31 ( V_10 ) ;
if ( V_36 ) {
F_25 ( & V_54 -> V_39 , L_11 ) ;
goto V_77;
}
V_15 -> V_78 . V_79 = F_14 ;
V_15 -> V_78 . V_80 = F_17 ;
V_15 -> V_78 . V_54 = V_54 ;
V_36 = F_32 ( V_24 ,
V_25 ,
& V_15 -> V_78 ) ;
if ( V_36 ) {
F_25 ( & V_54 -> V_39 , L_12 ) ;
goto V_81;
}
return 0 ;
V_81:
F_33 ( V_10 ) ;
V_77:
F_34 ( & V_15 -> V_20 ) ;
V_76:
F_35 ( V_10 ) ;
V_68:
F_36 ( V_10 -> V_55 ) ;
return V_36 ;
}
static int F_37 ( struct V_53 * V_54 )
{
struct V_40 * V_24 = V_54 -> V_39 . V_64 ;
struct V_9 * V_10 = F_15 ( V_54 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
F_38 ( V_24 , V_25 ) ;
F_33 ( V_10 ) ;
F_34 ( & V_15 -> V_20 ) ;
F_35 ( V_10 ) ;
F_36 ( V_10 -> V_55 ) ;
return 0 ;
}
