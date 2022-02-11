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
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case 0 :
switch ( V_12 -> V_20 ) {
case V_21 :
V_17 = V_16 -> V_22 . V_17 ;
V_18 =
V_23 ;
break;
default:
V_17 = - 1 ;
break;
}
if ( V_17 >= 0 ) {
F_4 ( & V_16 -> V_24 ,
true ) ;
* V_13 = F_5 (
V_16 -> V_24 . V_25 ,
V_26 , V_18 ,
V_17 ,
V_27 ) ;
F_4 ( & V_16 -> V_24 ,
false ) ;
} else {
* V_13 = 0 ;
return - V_28 ;
}
V_19 = V_29 ;
break;
case V_30 :
* V_13 = V_16 -> V_31 ;
* V_14 = V_16 -> V_32 ;
V_19 = V_16 -> V_33 ;
break;
case V_34 :
* V_13 = V_16 -> V_35 ;
V_19 = V_29 ;
break;
case V_36 :
V_19 = F_6 (
& V_16 -> V_24 , V_13 , V_14 ) ;
break;
case V_37 :
V_19 = F_7 (
& V_16 -> V_24 , V_13 , V_14 ) ;
break;
default:
V_19 = - V_28 ;
break;
}
return V_19 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 ,
int V_14 ,
long V_15 )
{
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_38 = 0 ;
switch ( V_15 ) {
case V_36 :
V_38 = F_9 (
& V_16 -> V_24 , V_13 , V_14 ) ;
break;
case V_37 :
V_38 = F_10 (
& V_16 -> V_24 , V_13 , V_14 ) ;
break;
default:
V_38 = - V_28 ;
}
return V_38 ;
}
static void F_11 ( struct V_10 * V_11 , const void * V_39 ,
int V_40 )
{
F_12 ( & V_11 -> V_41 , L_1 ) ;
F_13 ( V_11 , V_39 ) ;
}
static int F_14 ( struct V_42 * V_25 ,
unsigned V_43 ,
void * V_44 )
{
struct V_10 * V_11 = F_15 ( V_44 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_41 , L_2 ) ;
if ( F_16 ( & V_16 -> V_24 . V_45 ) )
F_11 ( V_11 ,
& V_16 -> V_46 ,
sizeof( V_16 -> V_46 ) ) ;
return 0 ;
}
static int F_17 ( struct V_42 * V_25 ,
unsigned V_43 ,
T_1 V_47 , char * V_48 ,
void * V_44 )
{
struct V_10 * V_11 = F_15 ( V_44 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_38 = - V_28 ;
switch ( V_43 ) {
case V_23 :
V_16 -> V_46 = * ( V_9 * ) V_48 ;
V_38 = 0 ;
break;
default:
break;
}
return V_38 ;
}
static int F_18 ( struct V_49 * V_50 ,
struct V_42 * V_25 ,
struct V_1 * V_2 ,
unsigned V_43 ,
struct V_16 * V_51 )
{
int V_38 ;
V_38 = F_19 ( V_25 , V_52 ,
V_43 ,
V_23 ,
& V_51 -> V_22 ) ;
if ( V_38 < 0 )
return V_38 ;
F_1 ( V_2 , V_21 ,
V_51 -> V_22 . V_4 ) ;
F_12 ( & V_50 -> V_41 , L_3 , V_51 -> V_22 . V_53 ,
V_51 -> V_22 . V_17 ) ;
V_51 -> V_33 = F_20 (
V_26 ,
& V_51 -> V_22 ,
& V_51 -> V_31 , & V_51 -> V_32 ) ;
if ( V_51 -> V_24 . V_54 . V_53 < 0 ) {
F_19 ( V_25 ,
V_55 , V_43 ,
V_56 |
V_57 ,
& V_51 -> V_24 . V_54 ) ;
F_12 ( & V_50 -> V_41 , L_4 ,
V_51 -> V_24 . V_54 . V_53 ,
V_51 -> V_24 . V_54 . V_17 ) ;
}
return V_38 ;
}
static int F_21 ( struct V_49 * V_50 )
{
int V_38 = 0 ;
static const char * V_58 = L_5 ;
struct V_10 * V_11 ;
struct V_16 * V_16 ;
struct V_42 * V_25 = V_50 -> V_41 . V_59 ;
struct V_1 * V_2 ;
V_11 = F_22 ( & V_50 -> V_41 , sizeof( struct V_16 ) ) ;
if ( ! V_11 )
return - V_60 ;
F_23 ( V_50 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_24 . V_25 = V_25 ;
V_16 -> V_24 . V_50 = V_50 ;
V_38 = F_24 ( V_25 , V_26 ,
& V_16 -> V_24 ) ;
if ( V_38 ) {
F_25 ( & V_50 -> V_41 , L_6 ) ;
return V_38 ;
}
V_2 = F_26 ( V_61 , sizeof( V_61 ) , V_62 ) ;
if ( ! V_2 ) {
F_25 ( & V_50 -> V_41 , L_7 ) ;
return - V_60 ;
}
V_38 = F_18 ( V_50 , V_25 , V_2 ,
V_26 , V_16 ) ;
if ( V_38 ) {
F_25 ( & V_50 -> V_41 , L_8 ) ;
goto V_63;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_64 =
F_27 ( V_61 ) ;
V_11 -> V_41 . V_65 = & V_50 -> V_41 ;
V_11 -> V_66 = & V_67 ;
V_11 -> V_58 = V_58 ;
V_11 -> V_68 = V_69 ;
V_38 = F_28 ( V_11 , & V_70 ,
NULL , NULL ) ;
if ( V_38 ) {
F_25 ( & V_50 -> V_41 , L_9 ) ;
goto V_63;
}
F_29 ( & V_16 -> V_24 . V_45 , 0 ) ;
V_38 = F_30 ( V_11 , V_58 ,
& V_16 -> V_24 ) ;
if ( V_38 < 0 ) {
F_25 ( & V_50 -> V_41 , L_10 ) ;
goto V_71;
}
V_38 = F_31 ( V_11 ) ;
if ( V_38 ) {
F_25 ( & V_50 -> V_41 , L_11 ) ;
goto V_72;
}
V_16 -> V_73 . V_74 = F_14 ;
V_16 -> V_73 . V_75 = F_17 ;
V_16 -> V_73 . V_50 = V_50 ;
V_38 = F_32 ( V_25 , V_26 ,
& V_16 -> V_73 ) ;
if ( V_38 < 0 ) {
F_25 ( & V_50 -> V_41 , L_12 ) ;
goto V_76;
}
return V_38 ;
V_76:
F_33 ( V_11 ) ;
V_72:
F_34 ( & V_16 -> V_24 ) ;
V_71:
F_35 ( V_11 ) ;
V_63:
F_36 ( V_11 -> V_2 ) ;
return V_38 ;
}
static int F_37 ( struct V_49 * V_50 )
{
struct V_42 * V_25 = V_50 -> V_41 . V_59 ;
struct V_10 * V_11 = F_15 ( V_50 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_38 ( V_25 , V_26 ) ;
F_33 ( V_11 ) ;
F_34 ( & V_16 -> V_24 ) ;
F_35 ( V_11 ) ;
F_36 ( V_11 -> V_2 ) ;
return 0 ;
}
