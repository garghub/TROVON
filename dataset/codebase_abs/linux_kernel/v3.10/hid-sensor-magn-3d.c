static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
V_2 [ V_3 ] . V_5 . V_6 = 's' ;
V_2 [ V_3 ] . V_5 . V_7 = V_4 * 8 ;
V_2 [ V_3 ] . V_5 . V_8 = sizeof( V_9 ) * 8 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int * V_13 , int * V_14 ,
long V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_18 = - 1 ;
V_9 V_19 ;
int V_20 ;
int V_21 ;
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case 0 :
V_18 =
V_17 -> V_22 [ V_12 -> V_23 ] . V_18 ;
V_19 = V_24 [ V_12 -> V_23 ] ;
if ( V_18 >= 0 )
* V_13 = F_4 (
V_17 -> V_25 . V_26 ,
V_27 , V_19 ,
V_18 ) ;
else {
* V_13 = 0 ;
return - V_28 ;
}
V_21 = V_29 ;
break;
case V_30 :
* V_13 = V_17 -> V_22 [ V_31 ] . V_32 ;
V_21 = V_29 ;
break;
case V_33 :
* V_13 = F_5 (
V_17 -> V_22 [ V_31 ] . V_34 ) ;
V_21 = V_29 ;
break;
case V_35 :
V_20 = F_6 (
& V_17 -> V_25 , V_13 , V_14 ) ;
V_21 = V_36 ;
break;
case V_37 :
V_20 = F_7 (
& V_17 -> V_25 , V_13 , V_14 ) ;
V_21 = V_36 ;
break;
default:
V_21 = - V_28 ;
break;
}
return V_21 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 ,
int V_14 ,
long V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_20 = 0 ;
switch ( V_15 ) {
case V_35 :
V_20 = F_9 (
& V_17 -> V_25 , V_13 , V_14 ) ;
break;
case V_37 :
V_20 = F_10 (
& V_17 -> V_25 , V_13 , V_14 ) ;
break;
default:
V_20 = - V_28 ;
}
return V_20 ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
long V_15 )
{
return V_36 ;
}
static void F_12 ( struct V_10 * V_11 , T_1 * V_38 , int V_39 )
{
F_13 ( & V_11 -> V_40 , L_1 ) ;
F_14 ( V_11 , ( T_1 * ) V_38 ) ;
}
static int F_15 ( struct V_41 * V_26 ,
unsigned V_42 ,
void * V_43 )
{
struct V_10 * V_11 = F_16 ( V_43 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_13 ( & V_11 -> V_40 , L_2 ,
V_17 -> V_25 . V_44 ) ;
if ( V_17 -> V_25 . V_44 )
F_12 ( V_11 ,
( T_1 * ) V_17 -> V_45 ,
sizeof( V_17 -> V_45 ) ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_26 ,
unsigned V_42 ,
T_2 V_46 , char * V_47 ,
void * V_43 )
{
struct V_10 * V_11 = F_16 ( V_43 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_48 ;
int V_20 = - V_28 ;
switch ( V_42 ) {
case V_49 :
case V_50 :
case V_51 :
V_48 = V_42 - V_49 ;
V_17 -> V_45 [ V_31 + V_48 ] =
* ( V_9 * ) V_47 ;
V_20 = 0 ;
break;
default:
break;
}
return V_20 ;
}
static int F_18 ( struct V_52 * V_53 ,
struct V_41 * V_26 ,
struct V_1 * V_2 ,
unsigned V_42 ,
struct V_16 * V_54 )
{
int V_20 ;
int V_55 ;
for ( V_55 = 0 ; V_55 <= V_56 ; ++ V_55 ) {
V_20 = F_19 ( V_26 ,
V_57 ,
V_42 ,
V_49 + V_55 ,
& V_54 -> V_22 [ V_31 + V_55 ] ) ;
if ( V_20 < 0 )
break;
F_1 ( V_2 ,
V_31 + V_55 ,
V_54 -> V_22 [ V_31 + V_55 ] . V_4 ) ;
}
F_13 ( & V_53 -> V_40 , L_3 ,
V_54 -> V_22 [ 0 ] . V_58 ,
V_54 -> V_22 [ 0 ] . V_18 ,
V_54 -> V_22 [ 1 ] . V_58 , V_54 -> V_22 [ 1 ] . V_18 ,
V_54 -> V_22 [ 2 ] . V_58 , V_54 -> V_22 [ 2 ] . V_18 ) ;
return V_20 ;
}
static int F_20 ( struct V_52 * V_53 )
{
int V_20 = 0 ;
static char * V_59 = L_4 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_41 * V_26 = V_53 -> V_40 . V_60 ;
struct V_1 * V_2 ;
V_11 = F_21 ( sizeof( struct V_16 ) ) ;
if ( V_11 == NULL ) {
V_20 = - V_61 ;
goto V_62;
}
F_22 ( V_53 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_25 . V_26 = V_26 ;
V_17 -> V_25 . V_53 = V_53 ;
V_20 = F_23 ( V_26 ,
V_27 ,
& V_17 -> V_25 ) ;
if ( V_20 ) {
F_24 ( & V_53 -> V_40 , L_5 ) ;
goto V_63;
}
V_2 = F_25 ( V_64 , sizeof( V_64 ) ,
V_65 ) ;
if ( ! V_2 ) {
V_20 = - V_61 ;
F_24 ( & V_53 -> V_40 , L_6 ) ;
goto V_63;
}
V_20 = F_18 ( V_53 , V_26 , V_2 ,
V_27 , V_17 ) ;
if ( V_20 ) {
F_24 ( & V_53 -> V_40 , L_7 ) ;
goto V_66;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_67 = F_26 ( V_64 ) ;
V_11 -> V_40 . V_68 = & V_53 -> V_40 ;
V_11 -> V_69 = & V_70 ;
V_11 -> V_59 = V_59 ;
V_11 -> V_71 = V_72 ;
V_20 = F_27 ( V_11 , & V_73 ,
NULL , NULL ) ;
if ( V_20 ) {
F_24 ( & V_53 -> V_40 , L_8 ) ;
goto V_66;
}
V_17 -> V_25 . V_44 = false ;
V_20 = F_28 ( V_11 , V_59 ,
& V_17 -> V_25 ) ;
if ( V_20 < 0 ) {
F_24 ( & V_53 -> V_40 , L_9 ) ;
goto V_74;
}
V_20 = F_29 ( V_11 ) ;
if ( V_20 ) {
F_24 ( & V_53 -> V_40 , L_10 ) ;
goto V_75;
}
V_17 -> V_76 . V_77 = F_15 ;
V_17 -> V_76 . V_78 = F_17 ;
V_17 -> V_76 . V_53 = V_53 ;
V_20 = F_30 ( V_26 , V_27 ,
& V_17 -> V_76 ) ;
if ( V_20 < 0 ) {
F_24 ( & V_53 -> V_40 , L_11 ) ;
goto V_79;
}
return V_20 ;
V_79:
F_31 ( V_11 ) ;
V_75:
F_32 ( V_11 ) ;
V_74:
F_33 ( V_11 ) ;
V_66:
F_34 ( V_11 -> V_2 ) ;
V_63:
F_35 ( V_11 ) ;
V_62:
return V_20 ;
}
static int F_36 ( struct V_52 * V_53 )
{
struct V_41 * V_26 = V_53 -> V_40 . V_60 ;
struct V_10 * V_11 = F_16 ( V_53 ) ;
F_37 ( V_26 , V_27 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 -> V_2 ) ;
F_35 ( V_11 ) ;
return 0 ;
}
