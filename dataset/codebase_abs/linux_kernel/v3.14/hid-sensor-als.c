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
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_17 = - 1 ;
V_9 V_18 ;
int V_19 ;
int V_20 ;
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case 0 :
switch ( V_12 -> V_21 ) {
case V_22 :
V_17 = V_16 -> V_23 . V_17 ;
V_18 =
V_24 ;
break;
default:
V_17 = - 1 ;
break;
}
if ( V_17 >= 0 )
* V_13 = F_4 (
V_16 -> V_25 . V_26 ,
V_27 , V_18 ,
V_17 ) ;
else {
* V_13 = 0 ;
return - V_28 ;
}
V_20 = V_29 ;
break;
case V_30 :
* V_13 = V_16 -> V_23 . V_31 ;
V_20 = V_29 ;
break;
case V_32 :
* V_13 = F_5 (
V_16 -> V_23 . V_33 ) ;
V_20 = V_29 ;
break;
case V_34 :
V_19 = F_6 (
& V_16 -> V_25 , V_13 , V_14 ) ;
V_20 = V_35 ;
break;
case V_36 :
V_19 = F_7 (
& V_16 -> V_25 , V_13 , V_14 ) ;
V_20 = V_35 ;
break;
default:
V_20 = - V_28 ;
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
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_19 = 0 ;
switch ( V_15 ) {
case V_34 :
V_19 = F_9 (
& V_16 -> V_25 , V_13 , V_14 ) ;
break;
case V_36 :
V_19 = F_10 (
& V_16 -> V_25 , V_13 , V_14 ) ;
break;
default:
V_19 = - V_28 ;
}
return V_19 ;
}
static void F_11 ( struct V_10 * V_11 , const void * V_37 ,
int V_38 )
{
F_12 ( & V_11 -> V_39 , L_1 ) ;
F_13 ( V_11 , V_37 ) ;
}
static int F_14 ( struct V_40 * V_26 ,
unsigned V_41 ,
void * V_42 )
{
struct V_10 * V_11 = F_15 ( V_42 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_39 , L_2 ,
V_16 -> V_25 . V_43 ) ;
if ( V_16 -> V_25 . V_43 )
F_11 ( V_11 ,
& V_16 -> V_44 ,
sizeof( V_16 -> V_44 ) ) ;
return 0 ;
}
static int F_16 ( struct V_40 * V_26 ,
unsigned V_41 ,
T_1 V_45 , char * V_46 ,
void * V_42 )
{
struct V_10 * V_11 = F_15 ( V_42 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_19 = - V_28 ;
switch ( V_41 ) {
case V_24 :
V_16 -> V_44 = * ( V_9 * ) V_46 ;
V_19 = 0 ;
break;
default:
break;
}
return V_19 ;
}
static int F_17 ( struct V_47 * V_48 ,
struct V_40 * V_26 ,
struct V_1 * V_2 ,
unsigned V_41 ,
struct V_16 * V_49 )
{
int V_19 ;
V_19 = F_18 ( V_26 , V_50 ,
V_41 ,
V_24 ,
& V_49 -> V_23 ) ;
if ( V_19 < 0 )
return V_19 ;
F_1 ( V_2 , V_22 ,
V_49 -> V_23 . V_4 ) ;
F_12 ( & V_48 -> V_39 , L_3 , V_49 -> V_23 . V_51 ,
V_49 -> V_23 . V_17 ) ;
if ( V_49 -> V_25 . V_52 . V_51 < 0 ) {
F_18 ( V_26 ,
V_53 , V_41 ,
V_54 |
V_55 ,
& V_49 -> V_25 . V_52 ) ;
F_12 ( & V_48 -> V_39 , L_4 ,
V_49 -> V_25 . V_52 . V_51 ,
V_49 -> V_25 . V_52 . V_17 ) ;
}
return V_19 ;
}
static int F_19 ( struct V_47 * V_48 )
{
int V_19 = 0 ;
static const char * V_56 = L_5 ;
struct V_10 * V_11 ;
struct V_16 * V_16 ;
struct V_40 * V_26 = V_48 -> V_39 . V_57 ;
struct V_1 * V_2 ;
V_11 = F_20 ( & V_48 -> V_39 , sizeof( struct V_16 ) ) ;
if ( ! V_11 )
return - V_58 ;
F_21 ( V_48 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_25 . V_26 = V_26 ;
V_16 -> V_25 . V_48 = V_48 ;
V_19 = F_22 ( V_26 , V_27 ,
& V_16 -> V_25 ) ;
if ( V_19 ) {
F_23 ( & V_48 -> V_39 , L_6 ) ;
return V_19 ;
}
V_2 = F_24 ( V_59 , sizeof( V_59 ) , V_60 ) ;
if ( ! V_2 ) {
F_23 ( & V_48 -> V_39 , L_7 ) ;
return - V_58 ;
}
V_19 = F_17 ( V_48 , V_26 , V_2 ,
V_27 , V_16 ) ;
if ( V_19 ) {
F_23 ( & V_48 -> V_39 , L_8 ) ;
goto V_61;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_62 =
F_25 ( V_59 ) ;
V_11 -> V_39 . V_63 = & V_48 -> V_39 ;
V_11 -> V_64 = & V_65 ;
V_11 -> V_56 = V_56 ;
V_11 -> V_66 = V_67 ;
V_19 = F_26 ( V_11 , & V_68 ,
NULL , NULL ) ;
if ( V_19 ) {
F_23 ( & V_48 -> V_39 , L_9 ) ;
goto V_61;
}
V_16 -> V_25 . V_43 = false ;
V_19 = F_27 ( V_11 , V_56 ,
& V_16 -> V_25 ) ;
if ( V_19 < 0 ) {
F_23 ( & V_48 -> V_39 , L_10 ) ;
goto V_69;
}
V_19 = F_28 ( V_11 ) ;
if ( V_19 ) {
F_23 ( & V_48 -> V_39 , L_11 ) ;
goto V_70;
}
V_16 -> V_71 . V_72 = F_14 ;
V_16 -> V_71 . V_73 = F_16 ;
V_16 -> V_71 . V_48 = V_48 ;
V_19 = F_29 ( V_26 , V_27 ,
& V_16 -> V_71 ) ;
if ( V_19 < 0 ) {
F_23 ( & V_48 -> V_39 , L_12 ) ;
goto V_74;
}
return V_19 ;
V_74:
F_30 ( V_11 ) ;
V_70:
F_31 ( & V_16 -> V_25 ) ;
V_69:
F_32 ( V_11 ) ;
V_61:
F_33 ( V_11 -> V_2 ) ;
return V_19 ;
}
static int F_34 ( struct V_47 * V_48 )
{
struct V_40 * V_26 = V_48 -> V_39 . V_57 ;
struct V_10 * V_11 = F_15 ( V_48 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_35 ( V_26 , V_27 ) ;
F_30 ( V_11 ) ;
F_31 ( & V_16 -> V_25 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 -> V_2 ) ;
return 0 ;
}
