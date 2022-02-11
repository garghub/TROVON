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
V_16 =
V_15 -> V_20 [ V_2 -> V_21 ] . V_16 ;
V_17 = V_22 [ V_2 -> V_21 ] ;
if ( V_16 >= 0 )
* V_11 = F_4 (
V_15 -> V_23 . V_24 ,
V_25 , V_17 ,
V_16 ) ;
else {
return - V_26 ;
}
V_18 = V_27 ;
break;
case V_28 :
* V_11 = V_15 -> V_20 [ V_29 ] . V_30 ;
V_18 = V_27 ;
break;
case V_31 :
* V_11 = F_5 (
V_15 -> V_20 [ V_29 ] . V_32 ) ;
V_18 = V_27 ;
break;
case V_33 :
V_18 = F_6 (
& V_15 -> V_23 , V_11 , V_12 ) ;
break;
case V_34 :
V_18 = F_7 (
& V_15 -> V_23 , V_11 , V_12 ) ;
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
int V_35 ;
switch ( V_13 ) {
case V_33 :
V_35 = F_9 (
& V_15 -> V_23 , V_11 , V_12 ) ;
break;
case V_34 :
V_35 = F_10 (
& V_15 -> V_23 , V_11 , V_12 ) ;
break;
default:
V_35 = - V_26 ;
}
return V_35 ;
}
static void F_11 ( struct V_9 * V_10 , T_1 * V_36 , int V_37 )
{
F_12 ( & V_10 -> V_38 , L_1 ) ;
F_13 ( V_10 , ( T_1 * ) V_36 ) ;
}
static int F_14 ( struct V_39 * V_24 ,
unsigned V_40 ,
void * V_41 )
{
struct V_9 * V_10 = F_15 ( V_41 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
F_12 ( & V_10 -> V_38 , L_2 ,
V_15 -> V_23 . V_42 ) ;
if ( V_15 -> V_23 . V_42 )
F_11 ( V_10 ,
( T_1 * ) V_15 -> V_43 ,
sizeof( V_15 -> V_43 ) ) ;
return 0 ;
}
static int F_16 ( struct V_39 * V_24 ,
unsigned V_40 ,
T_2 V_44 , char * V_45 ,
void * V_41 )
{
struct V_9 * V_10 = F_15 ( V_41 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
int V_35 = 0 ;
switch ( V_40 ) {
case V_46 :
V_15 -> V_43 [ V_29 ] = * ( V_8 * ) V_45 ;
break;
case V_47 :
V_15 -> V_43 [ V_48 ] = * ( V_8 * ) V_45 ;
break;
case V_49 :
V_15 -> V_43 [ V_50 ] = * ( V_8 * ) V_45 ;
break;
default:
V_35 = - V_26 ;
break;
}
return V_35 ;
}
static int F_17 ( struct V_51 * V_52 ,
struct V_39 * V_24 ,
struct V_1 * V_53 ,
unsigned V_40 ,
struct V_14 * V_54 )
{
int V_35 ;
V_35 = F_18 ( V_24 ,
V_55 ,
V_40 ,
V_46 ,
& V_54 -> V_20 [ V_29 ] ) ;
if ( V_35 )
return V_35 ;
F_1 ( & V_53 [ V_29 ] ,
V_54 -> V_20 [ V_29 ] . V_3 ) ;
V_35 = F_18 ( V_24 ,
V_55 ,
V_40 ,
V_47 ,
& V_54 -> V_20 [ V_48 ] ) ;
if ( V_35 )
return V_35 ;
F_1 ( & V_53 [ V_48 ] ,
V_54 -> V_20 [ V_48 ] . V_3 ) ;
V_35 = F_18 ( V_24 ,
V_55 ,
V_40 ,
V_49 ,
& V_54 -> V_20 [ V_50 ] ) ;
if ( V_35 )
return V_35 ;
F_1 ( & V_53 [ V_50 ] ,
V_54 -> V_20 [ V_50 ] . V_3 ) ;
F_12 ( & V_52 -> V_38 , L_3 ,
V_54 -> V_20 [ 0 ] . V_56 ,
V_54 -> V_20 [ 0 ] . V_16 ,
V_54 -> V_20 [ 1 ] . V_56 , V_54 -> V_20 [ 1 ] . V_16 ,
V_54 -> V_20 [ 2 ] . V_56 , V_54 -> V_20 [ 2 ] . V_16 ) ;
if ( V_54 -> V_23 . V_57 . V_56 < 0 ) {
F_18 ( V_24 ,
V_58 , V_40 ,
V_59 |
V_60 ,
& V_54 -> V_23 . V_57 ) ;
F_12 ( & V_52 -> V_38 , L_4 ,
V_54 -> V_23 . V_57 . V_56 ,
V_54 -> V_23 . V_57 . V_16 ) ;
}
return V_35 ;
}
static int F_19 ( struct V_51 * V_52 )
{
int V_35 ;
static char * V_61 = L_5 ;
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_39 * V_24 = V_52 -> V_38 . V_62 ;
struct V_1 * V_53 ;
V_10 = F_20 ( & V_52 -> V_38 ,
sizeof( struct V_14 ) ) ;
if ( V_10 == NULL )
return - V_63 ;
F_21 ( V_52 , V_10 ) ;
V_15 = F_3 ( V_10 ) ;
V_15 -> V_23 . V_24 = V_24 ;
V_15 -> V_23 . V_52 = V_52 ;
V_35 = F_22 ( V_24 ,
V_25 ,
& V_15 -> V_23 ) ;
if ( V_35 ) {
F_23 ( & V_52 -> V_38 , L_6 ) ;
return V_35 ;
}
V_53 = F_24 ( V_64 , sizeof( V_64 ) ,
V_65 ) ;
if ( ! V_53 ) {
F_23 ( & V_52 -> V_38 , L_7 ) ;
return - V_63 ;
}
V_35 = F_17 ( V_52 , V_24 , V_53 ,
V_25 , V_15 ) ;
if ( V_35 ) {
F_23 ( & V_52 -> V_38 , L_8 ) ;
goto V_66;
}
V_10 -> V_53 = V_53 ;
V_10 -> V_67 = F_25 ( V_64 ) ;
V_10 -> V_38 . V_68 = & V_52 -> V_38 ;
V_10 -> V_69 = & V_70 ;
V_10 -> V_61 = V_61 ;
V_10 -> V_71 = V_72 ;
V_35 = F_26 ( V_10 , & V_73 ,
NULL , NULL ) ;
if ( V_35 ) {
F_23 ( & V_52 -> V_38 , L_9 ) ;
goto V_66;
}
V_15 -> V_23 . V_42 = false ;
V_35 = F_27 ( V_10 , V_61 ,
& V_15 -> V_23 ) ;
if ( V_35 ) {
F_23 ( & V_52 -> V_38 , L_10 ) ;
goto V_74;
}
V_35 = F_28 ( V_10 ) ;
if ( V_35 ) {
F_23 ( & V_52 -> V_38 , L_11 ) ;
goto V_75;
}
V_15 -> V_76 . V_77 = F_14 ;
V_15 -> V_76 . V_78 = F_16 ;
V_15 -> V_76 . V_52 = V_52 ;
V_35 = F_29 ( V_24 ,
V_25 ,
& V_15 -> V_76 ) ;
if ( V_35 ) {
F_23 ( & V_52 -> V_38 , L_12 ) ;
goto V_79;
}
return 0 ;
V_79:
F_30 ( V_10 ) ;
V_75:
F_31 ( & V_15 -> V_23 ) ;
V_74:
F_32 ( V_10 ) ;
V_66:
F_33 ( V_10 -> V_53 ) ;
return V_35 ;
}
static int F_34 ( struct V_51 * V_52 )
{
struct V_39 * V_24 = V_52 -> V_38 . V_62 ;
struct V_9 * V_10 = F_15 ( V_52 ) ;
struct V_14 * V_15 = F_3 ( V_10 ) ;
F_35 ( V_24 , V_25 ) ;
F_30 ( V_10 ) ;
F_31 ( & V_15 -> V_23 ) ;
F_32 ( V_10 ) ;
F_33 ( V_10 -> V_53 ) ;
return 0 ;
}
