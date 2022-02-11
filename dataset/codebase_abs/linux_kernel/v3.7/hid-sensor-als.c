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
static int F_11 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
long V_15 )
{
return V_35 ;
}
static void F_12 ( struct V_10 * V_11 , T_1 * V_37 , int V_38 )
{
struct V_39 * V_40 = V_11 -> V_40 ;
int V_41 ;
F_13 ( & V_11 -> V_42 , L_1 ) ;
if ( ! V_40 ) {
F_14 ( & V_11 -> V_42 , L_2 ) ;
return;
}
V_41 = V_40 -> V_43 -> V_44 ( V_40 ) ;
if ( V_38 > V_41 ) {
F_14 ( & V_11 -> V_42 , L_3 , V_38 ,
V_41 ) ;
return;
}
F_15 ( V_40 , ( T_1 * ) V_37 ) ;
}
static int F_16 ( struct V_45 * V_26 ,
unsigned V_46 ,
void * V_47 )
{
struct V_10 * V_11 = F_17 ( V_47 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_13 ( & V_11 -> V_42 , L_4 ,
V_16 -> V_25 . V_48 ) ;
if ( V_16 -> V_25 . V_48 )
F_12 ( V_11 ,
( T_1 * ) & V_16 -> V_49 ,
sizeof( V_16 -> V_49 ) ) ;
return 0 ;
}
static int F_18 ( struct V_45 * V_26 ,
unsigned V_46 ,
T_2 V_50 , char * V_51 ,
void * V_47 )
{
struct V_10 * V_11 = F_17 ( V_47 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_19 = - V_28 ;
switch ( V_46 ) {
case V_24 :
V_16 -> V_49 = * ( V_9 * ) V_51 ;
V_19 = 0 ;
break;
default:
break;
}
return V_19 ;
}
static int F_19 ( struct V_52 * V_53 ,
struct V_45 * V_26 ,
struct V_1 * V_2 ,
unsigned V_46 ,
struct V_16 * V_54 )
{
int V_19 ;
V_19 = F_20 ( V_26 , V_55 ,
V_46 ,
V_24 ,
& V_54 -> V_23 ) ;
if ( V_19 < 0 )
return V_19 ;
F_1 ( V_2 , V_22 ,
V_54 -> V_23 . V_4 ) ;
F_13 ( & V_53 -> V_42 , L_5 , V_54 -> V_23 . V_56 ,
V_54 -> V_23 . V_17 ) ;
return V_19 ;
}
static int T_3 F_21 ( struct V_52 * V_53 )
{
int V_19 = 0 ;
static const char * V_57 = L_6 ;
struct V_10 * V_11 ;
struct V_16 * V_16 ;
struct V_45 * V_26 = V_53 -> V_42 . V_58 ;
struct V_1 * V_2 ;
V_11 = F_22 ( sizeof( struct V_16 ) ) ;
if ( V_11 == NULL ) {
V_19 = - V_59 ;
goto V_60;
}
F_23 ( V_53 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_25 . V_26 = V_26 ;
V_16 -> V_25 . V_53 = V_53 ;
V_19 = F_24 ( V_26 , V_27 ,
& V_16 -> V_25 ) ;
if ( V_19 ) {
F_14 ( & V_53 -> V_42 , L_7 ) ;
goto V_61;
}
V_2 = F_25 ( V_62 ,
sizeof( V_62 ) ,
V_63 ) ;
if ( ! V_2 ) {
F_14 ( & V_53 -> V_42 , L_8 ) ;
goto V_61;
}
V_19 = F_19 ( V_53 , V_26 , V_2 ,
V_27 , V_16 ) ;
if ( V_19 ) {
F_14 ( & V_53 -> V_42 , L_9 ) ;
goto V_64;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_65 =
F_26 ( V_62 ) ;
V_11 -> V_42 . V_66 = & V_53 -> V_42 ;
V_11 -> V_67 = & V_68 ;
V_11 -> V_57 = V_57 ;
V_11 -> V_69 = V_70 ;
V_19 = F_27 ( V_11 , & V_71 ,
NULL , NULL ) ;
if ( V_19 ) {
F_14 ( & V_53 -> V_42 , L_10 ) ;
goto V_64;
}
V_16 -> V_25 . V_48 = false ;
V_19 = F_28 ( V_11 , V_57 ,
& V_16 -> V_25 ) ;
if ( V_19 < 0 ) {
F_14 ( & V_53 -> V_42 , L_11 ) ;
goto V_72;
}
V_19 = F_29 ( V_11 ) ;
if ( V_19 ) {
F_14 ( & V_53 -> V_42 , L_12 ) ;
goto V_73;
}
V_16 -> V_74 . V_75 = F_16 ;
V_16 -> V_74 . V_76 = F_18 ;
V_16 -> V_74 . V_53 = V_53 ;
V_19 = F_30 ( V_26 , V_27 ,
& V_16 -> V_74 ) ;
if ( V_19 < 0 ) {
F_14 ( & V_53 -> V_42 , L_13 ) ;
goto V_77;
}
return V_19 ;
V_77:
F_31 ( V_11 ) ;
V_73:
F_32 ( V_11 ) ;
V_72:
F_33 ( V_11 ) ;
V_64:
F_34 ( V_11 -> V_2 ) ;
V_61:
F_35 ( V_11 ) ;
V_60:
return V_19 ;
}
static int T_3 F_36 ( struct V_52 * V_53 )
{
struct V_45 * V_26 = V_53 -> V_42 . V_58 ;
struct V_10 * V_11 = F_17 ( V_53 ) ;
F_37 ( V_26 , V_27 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 -> V_2 ) ;
F_35 ( V_11 ) ;
return 0 ;
}
