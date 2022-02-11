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
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case 0 :
F_4 ( & V_17 -> V_21 , true ) ;
V_18 = V_17 -> V_22 [ V_12 -> V_23 ] . V_18 ;
V_19 = V_24 [ V_12 -> V_23 ] ;
if ( V_18 >= 0 )
* V_13 = F_5 (
V_17 -> V_21 . V_25 ,
V_26 , V_19 ,
V_18 ) ;
else {
* V_13 = 0 ;
F_4 ( & V_17 -> V_21 ,
false ) ;
return - V_27 ;
}
F_4 ( & V_17 -> V_21 , false ) ;
V_20 = V_28 ;
break;
case V_29 :
* V_13 = V_17 -> V_30 ;
* V_14 = V_17 -> V_31 ;
V_20 = V_17 -> V_32 ;
break;
case V_33 :
* V_13 = V_17 -> V_34 ;
V_20 = V_28 ;
break;
case V_35 :
V_20 = F_6 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_36 :
V_20 = F_7 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
default:
V_20 = - V_27 ;
break;
}
return V_20 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 ,
int V_14 ,
long V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_37 = 0 ;
switch ( V_15 ) {
case V_35 :
V_37 = F_9 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_36 :
V_37 = F_10 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
default:
V_37 = - V_27 ;
}
return V_37 ;
}
static void F_11 ( struct V_10 * V_11 , const void * V_38 ,
int V_39 )
{
F_12 ( & V_11 -> V_40 , L_1 ) ;
F_13 ( V_11 , V_38 ) ;
}
static int F_14 ( struct V_41 * V_25 ,
unsigned V_42 ,
void * V_43 )
{
struct V_10 * V_11 = F_15 ( V_43 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_40 , L_2 ) ;
if ( F_16 ( & V_17 -> V_21 . V_44 ) )
F_11 ( V_11 ,
V_17 -> V_45 ,
sizeof( V_17 -> V_45 ) ) ;
return 0 ;
}
static int F_17 ( struct V_41 * V_25 ,
unsigned V_42 ,
T_1 V_46 , char * V_47 ,
void * V_43 )
{
struct V_10 * V_11 = F_15 ( V_43 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_48 ;
int V_37 = - V_27 ;
switch ( V_42 ) {
case V_49 :
case V_50 :
case V_51 :
V_48 = V_42 - V_49 ;
V_17 -> V_45 [ V_52 + V_48 ] =
* ( V_9 * ) V_47 ;
V_37 = 0 ;
break;
default:
break;
}
return V_37 ;
}
static int F_18 ( struct V_53 * V_54 ,
struct V_41 * V_25 ,
struct V_1 * V_2 ,
unsigned V_42 ,
struct V_16 * V_55 )
{
int V_37 ;
int V_56 ;
for ( V_56 = 0 ; V_56 <= V_57 ; ++ V_56 ) {
V_37 = F_19 ( V_25 ,
V_58 ,
V_42 ,
V_49 + V_56 ,
& V_55 -> V_22 [ V_52 + V_56 ] ) ;
if ( V_37 < 0 )
break;
F_1 ( V_2 ,
V_52 + V_56 ,
V_55 -> V_22 [ V_52 + V_56 ] . V_4 ) ;
}
F_12 ( & V_54 -> V_40 , L_3 ,
V_55 -> V_22 [ 0 ] . V_59 ,
V_55 -> V_22 [ 0 ] . V_18 ,
V_55 -> V_22 [ 1 ] . V_59 , V_55 -> V_22 [ 1 ] . V_18 ,
V_55 -> V_22 [ 2 ] . V_59 , V_55 -> V_22 [ 2 ] . V_18 ) ;
V_55 -> V_32 = F_20 (
V_26 ,
& V_55 -> V_22 [ V_52 ] ,
& V_55 -> V_30 , & V_55 -> V_31 ) ;
if ( V_55 -> V_21 . V_60 . V_59 < 0 ) {
F_19 ( V_25 ,
V_61 , V_42 ,
V_62 |
V_63 ,
& V_55 -> V_21 . V_60 ) ;
F_12 ( & V_54 -> V_40 , L_4 ,
V_55 -> V_21 . V_60 . V_59 ,
V_55 -> V_21 . V_60 . V_18 ) ;
}
return V_37 ;
}
static int F_21 ( struct V_53 * V_54 )
{
int V_37 = 0 ;
static const char * V_64 = L_5 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_41 * V_25 = V_54 -> V_40 . V_65 ;
struct V_1 * V_2 ;
V_11 = F_22 ( & V_54 -> V_40 , sizeof( * V_17 ) ) ;
if ( ! V_11 )
return - V_66 ;
F_23 ( V_54 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_21 . V_25 = V_25 ;
V_17 -> V_21 . V_54 = V_54 ;
V_37 = F_24 ( V_25 ,
V_26 ,
& V_17 -> V_21 ) ;
if ( V_37 ) {
F_25 ( & V_54 -> V_40 , L_6 ) ;
return V_37 ;
}
V_2 = F_26 ( V_67 , sizeof( V_67 ) ,
V_68 ) ;
if ( ! V_2 ) {
F_25 ( & V_54 -> V_40 , L_7 ) ;
return - V_66 ;
}
V_37 = F_18 ( V_54 , V_25 , V_2 ,
V_26 , V_17 ) ;
if ( V_37 ) {
F_25 ( & V_54 -> V_40 , L_8 ) ;
goto V_69;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_70 = F_27 ( V_67 ) ;
V_11 -> V_40 . V_71 = & V_54 -> V_40 ;
V_11 -> V_72 = & V_73 ;
V_11 -> V_64 = V_64 ;
V_11 -> V_74 = V_75 ;
V_37 = F_28 ( V_11 , & V_76 ,
NULL , NULL ) ;
if ( V_37 ) {
F_25 ( & V_54 -> V_40 , L_9 ) ;
goto V_69;
}
F_29 ( & V_17 -> V_21 . V_44 , 0 ) ;
V_37 = F_30 ( V_11 , V_64 ,
& V_17 -> V_21 ) ;
if ( V_37 < 0 ) {
F_25 ( & V_54 -> V_40 , L_10 ) ;
goto V_77;
}
V_37 = F_31 ( V_11 ) ;
if ( V_37 ) {
F_25 ( & V_54 -> V_40 , L_11 ) ;
goto V_78;
}
V_17 -> V_79 . V_80 = F_14 ;
V_17 -> V_79 . V_81 = F_17 ;
V_17 -> V_79 . V_54 = V_54 ;
V_37 = F_32 ( V_25 , V_26 ,
& V_17 -> V_79 ) ;
if ( V_37 < 0 ) {
F_25 ( & V_54 -> V_40 , L_12 ) ;
goto V_82;
}
return V_37 ;
V_82:
F_33 ( V_11 ) ;
V_78:
F_34 ( & V_17 -> V_21 ) ;
V_77:
F_35 ( V_11 ) ;
V_69:
F_36 ( V_11 -> V_2 ) ;
return V_37 ;
}
static int F_37 ( struct V_53 * V_54 )
{
struct V_41 * V_25 = V_54 -> V_40 . V_65 ;
struct V_10 * V_11 = F_15 ( V_54 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_38 ( V_25 , V_26 ) ;
F_33 ( V_11 ) ;
F_34 ( & V_17 -> V_21 ) ;
F_35 ( V_11 ) ;
F_36 ( V_11 -> V_2 ) ;
return 0 ;
}
