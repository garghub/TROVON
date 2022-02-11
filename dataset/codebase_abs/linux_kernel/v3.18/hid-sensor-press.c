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
T_1 V_20 ;
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case V_21 :
switch ( V_12 -> V_22 ) {
case V_23 :
V_17 = V_16 -> V_24 . V_17 ;
V_18 =
V_25 ;
break;
default:
V_17 = - 1 ;
break;
}
if ( V_17 >= 0 ) {
V_20 = F_4 (
& V_16 -> V_26 ) ;
if ( V_20 < 0 )
return - V_27 ;
F_5 ( & V_16 -> V_26 ,
true ) ;
F_6 ( V_20 * 2 ) ;
* V_13 = F_7 (
V_16 -> V_26 . V_28 ,
V_29 , V_18 ,
V_17 ) ;
F_5 ( & V_16 -> V_26 ,
false ) ;
} else {
* V_13 = 0 ;
return - V_27 ;
}
V_19 = V_30 ;
break;
case V_31 :
* V_13 = V_16 -> V_32 ;
* V_14 = V_16 -> V_33 ;
V_19 = V_16 -> V_34 ;
break;
case V_35 :
* V_13 = V_16 -> V_36 ;
V_19 = V_30 ;
break;
case V_37 :
V_19 = F_8 (
& V_16 -> V_26 , V_13 , V_14 ) ;
break;
case V_38 :
V_19 = F_9 (
& V_16 -> V_26 , V_13 , V_14 ) ;
break;
default:
V_19 = - V_27 ;
break;
}
return V_19 ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 ,
int V_14 ,
long V_15 )
{
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_39 = 0 ;
switch ( V_15 ) {
case V_37 :
V_39 = F_11 (
& V_16 -> V_26 , V_13 , V_14 ) ;
break;
case V_38 :
V_39 = F_12 (
& V_16 -> V_26 , V_13 , V_14 ) ;
break;
default:
V_39 = - V_27 ;
}
return V_39 ;
}
static void F_13 ( struct V_10 * V_11 , const void * V_40 ,
int V_41 )
{
F_14 ( & V_11 -> V_42 , L_1 ) ;
F_15 ( V_11 , V_40 ) ;
}
static int F_16 ( struct V_43 * V_28 ,
unsigned V_44 ,
void * V_45 )
{
struct V_10 * V_11 = F_17 ( V_45 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_14 ( & V_11 -> V_42 , L_2 ) ;
if ( F_18 ( & V_16 -> V_26 . V_46 ) )
F_13 ( V_11 ,
& V_16 -> V_47 ,
sizeof( V_16 -> V_47 ) ) ;
return 0 ;
}
static int F_19 ( struct V_43 * V_28 ,
unsigned V_44 ,
T_2 V_48 , char * V_49 ,
void * V_45 )
{
struct V_10 * V_11 = F_17 ( V_45 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_39 = - V_27 ;
switch ( V_44 ) {
case V_25 :
V_16 -> V_47 = * ( V_9 * ) V_49 ;
V_39 = 0 ;
break;
default:
break;
}
return V_39 ;
}
static int F_20 ( struct V_50 * V_51 ,
struct V_43 * V_28 ,
struct V_1 * V_2 ,
unsigned V_44 ,
struct V_16 * V_52 )
{
int V_39 ;
V_39 = F_21 ( V_28 , V_53 ,
V_44 ,
V_25 ,
& V_52 -> V_24 ) ;
if ( V_39 < 0 )
return V_39 ;
F_1 ( V_2 , V_23 ,
V_52 -> V_24 . V_4 ) ;
F_14 ( & V_51 -> V_42 , L_3 , V_52 -> V_24 . V_54 ,
V_52 -> V_24 . V_17 ) ;
V_52 -> V_34 = F_22 (
V_29 ,
& V_52 -> V_24 ,
& V_52 -> V_32 , & V_52 -> V_33 ) ;
if ( V_52 -> V_26 . V_55 . V_54 < 0 ) {
F_21 ( V_28 ,
V_56 , V_44 ,
V_57 |
V_58 ,
& V_52 -> V_26 . V_55 ) ;
F_14 ( & V_51 -> V_42 , L_4 ,
V_52 -> V_26 . V_55 . V_54 ,
V_52 -> V_26 . V_55 . V_17 ) ;
}
return V_39 ;
}
static int F_23 ( struct V_50 * V_51 )
{
int V_39 = 0 ;
static const char * V_59 = L_5 ;
struct V_10 * V_11 ;
struct V_16 * V_16 ;
struct V_43 * V_28 = V_51 -> V_42 . V_60 ;
struct V_1 * V_2 ;
V_11 = F_24 ( & V_51 -> V_42 ,
sizeof( struct V_16 ) ) ;
if ( ! V_11 )
return - V_61 ;
F_25 ( V_51 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_26 . V_28 = V_28 ;
V_16 -> V_26 . V_51 = V_51 ;
V_39 = F_26 ( V_28 ,
V_29 ,
& V_16 -> V_26 ) ;
if ( V_39 ) {
F_27 ( & V_51 -> V_42 , L_6 ) ;
return V_39 ;
}
V_2 = F_28 ( V_62 , sizeof( V_62 ) , V_63 ) ;
if ( ! V_2 ) {
F_27 ( & V_51 -> V_42 , L_7 ) ;
return - V_61 ;
}
V_39 = F_20 ( V_51 , V_28 , V_2 ,
V_29 , V_16 ) ;
if ( V_39 ) {
F_27 ( & V_51 -> V_42 , L_8 ) ;
goto V_64;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_65 =
F_29 ( V_62 ) ;
V_11 -> V_42 . V_66 = & V_51 -> V_42 ;
V_11 -> V_67 = & V_68 ;
V_11 -> V_59 = V_59 ;
V_11 -> V_69 = V_70 ;
V_39 = F_30 ( V_11 , & V_71 ,
NULL , NULL ) ;
if ( V_39 ) {
F_27 ( & V_51 -> V_42 , L_9 ) ;
goto V_64;
}
F_31 ( & V_16 -> V_26 . V_46 , 0 ) ;
V_39 = F_32 ( V_11 , V_59 ,
& V_16 -> V_26 ) ;
if ( V_39 ) {
F_27 ( & V_51 -> V_42 , L_10 ) ;
goto V_72;
}
V_39 = F_33 ( V_11 ) ;
if ( V_39 ) {
F_27 ( & V_51 -> V_42 , L_11 ) ;
goto V_73;
}
V_16 -> V_74 . V_75 = F_16 ;
V_16 -> V_74 . V_76 = F_19 ;
V_16 -> V_74 . V_51 = V_51 ;
V_39 = F_34 ( V_28 , V_29 ,
& V_16 -> V_74 ) ;
if ( V_39 < 0 ) {
F_27 ( & V_51 -> V_42 , L_12 ) ;
goto V_77;
}
return V_39 ;
V_77:
F_35 ( V_11 ) ;
V_73:
F_36 ( & V_16 -> V_26 ) ;
V_72:
F_37 ( V_11 ) ;
V_64:
F_38 ( V_11 -> V_2 ) ;
return V_39 ;
}
static int F_39 ( struct V_50 * V_51 )
{
struct V_43 * V_28 = V_51 -> V_42 . V_60 ;
struct V_10 * V_11 = F_17 ( V_51 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_40 ( V_28 , V_29 ) ;
F_35 ( V_11 ) ;
F_36 ( & V_16 -> V_26 ) ;
F_37 ( V_11 ) ;
F_38 ( V_11 -> V_2 ) ;
return 0 ;
}
