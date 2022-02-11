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
case V_20 :
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
if ( V_17 >= 0 ) {
F_4 ( & V_16 -> V_25 ,
true ) ;
* V_13 = F_5 (
V_16 -> V_25 . V_26 ,
V_27 , V_18 ,
V_17 ,
V_28 ) ;
F_4 ( & V_16 -> V_25 ,
false ) ;
} else {
* V_13 = 0 ;
return - V_29 ;
}
V_19 = V_30 ;
break;
case V_31 :
* V_13 = V_16 -> V_23 . V_32 ;
V_19 = V_30 ;
break;
case V_33 :
* V_13 = F_6 (
V_16 -> V_23 . V_34 ) ;
V_19 = V_30 ;
break;
case V_35 :
V_19 = F_7 (
& V_16 -> V_25 , V_13 , V_14 ) ;
break;
case V_36 :
V_19 = F_8 (
& V_16 -> V_25 , V_13 , V_14 ) ;
break;
default:
V_19 = - V_29 ;
break;
}
return V_19 ;
}
static int F_9 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 ,
int V_14 ,
long V_15 )
{
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_37 = 0 ;
switch ( V_15 ) {
case V_35 :
V_37 = F_10 (
& V_16 -> V_25 , V_13 , V_14 ) ;
break;
case V_36 :
V_37 = F_11 (
& V_16 -> V_25 , V_13 , V_14 ) ;
break;
default:
V_37 = - V_29 ;
}
return V_37 ;
}
static void F_12 ( struct V_10 * V_11 , const void * V_38 ,
int V_39 )
{
F_13 ( & V_11 -> V_40 , L_1 ) ;
F_14 ( V_11 , V_38 ) ;
}
static int F_15 ( struct V_41 * V_26 ,
unsigned V_42 ,
void * V_43 )
{
struct V_10 * V_11 = F_16 ( V_43 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_13 ( & V_11 -> V_40 , L_2 ) ;
if ( F_17 ( & V_16 -> V_25 . V_44 ) )
F_12 ( V_11 ,
& V_16 -> V_45 ,
sizeof( V_16 -> V_45 ) ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_26 ,
unsigned V_42 ,
T_1 V_46 , char * V_47 ,
void * V_43 )
{
struct V_10 * V_11 = F_16 ( V_43 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
int V_37 = - V_29 ;
switch ( V_42 ) {
case V_24 :
V_16 -> V_45 = * ( V_9 * ) V_47 ;
V_37 = 0 ;
break;
default:
break;
}
return V_37 ;
}
static int F_19 ( struct V_48 * V_49 ,
struct V_41 * V_26 ,
struct V_1 * V_2 ,
unsigned V_42 ,
struct V_16 * V_50 )
{
int V_37 ;
V_37 = F_20 ( V_26 , V_51 ,
V_42 ,
V_24 ,
& V_50 -> V_23 ) ;
if ( V_37 < 0 )
return V_37 ;
F_1 ( V_2 , V_22 ,
V_50 -> V_23 . V_4 ) ;
F_13 ( & V_49 -> V_40 , L_3 , V_50 -> V_23 . V_52 ,
V_50 -> V_23 . V_17 ) ;
if ( V_50 -> V_25 . V_53 . V_52 < 0 ) {
F_20 ( V_26 ,
V_54 , V_42 ,
V_55 |
V_56 ,
& V_50 -> V_25 . V_53 ) ;
F_13 ( & V_49 -> V_40 , L_4 ,
V_50 -> V_25 . V_53 . V_52 ,
V_50 -> V_25 . V_53 . V_17 ) ;
}
if ( V_50 -> V_25 . V_53 . V_52 < 0 )
F_20 ( V_26 ,
V_54 , V_42 ,
V_55 |
V_24 ,
& V_50 -> V_25 . V_53 ) ;
return V_37 ;
}
static int F_21 ( struct V_48 * V_49 )
{
int V_37 = 0 ;
static const char * V_57 = L_5 ;
struct V_10 * V_11 ;
struct V_16 * V_16 ;
struct V_41 * V_26 = V_49 -> V_40 . V_58 ;
V_11 = F_22 ( & V_49 -> V_40 ,
sizeof( struct V_16 ) ) ;
if ( ! V_11 )
return - V_59 ;
F_23 ( V_49 , V_11 ) ;
V_16 = F_3 ( V_11 ) ;
V_16 -> V_25 . V_26 = V_26 ;
V_16 -> V_25 . V_49 = V_49 ;
V_37 = F_24 ( V_26 , V_27 ,
& V_16 -> V_25 ) ;
if ( V_37 ) {
F_25 ( & V_49 -> V_40 , L_6 ) ;
return V_37 ;
}
V_11 -> V_2 = F_26 ( V_60 , sizeof( V_60 ) ,
V_61 ) ;
if ( ! V_11 -> V_2 ) {
F_25 ( & V_49 -> V_40 , L_7 ) ;
return - V_59 ;
}
V_37 = F_19 ( V_49 , V_26 ,
(struct V_1 * ) V_11 -> V_2 ,
V_27 , V_16 ) ;
if ( V_37 ) {
F_25 ( & V_49 -> V_40 , L_8 ) ;
goto V_62;
}
V_11 -> V_63 = F_27 ( V_60 ) ;
V_11 -> V_40 . V_64 = & V_49 -> V_40 ;
V_11 -> V_65 = & V_66 ;
V_11 -> V_57 = V_57 ;
V_11 -> V_67 = V_68 ;
V_37 = F_28 ( V_11 , & V_69 ,
NULL , NULL ) ;
if ( V_37 ) {
F_25 ( & V_49 -> V_40 , L_9 ) ;
goto V_62;
}
F_29 ( & V_16 -> V_25 . V_44 , 0 ) ;
V_37 = F_30 ( V_11 , V_57 ,
& V_16 -> V_25 ) ;
if ( V_37 ) {
F_25 ( & V_49 -> V_40 , L_10 ) ;
goto V_70;
}
V_37 = F_31 ( V_11 ) ;
if ( V_37 ) {
F_25 ( & V_49 -> V_40 , L_11 ) ;
goto V_71;
}
V_16 -> V_72 . V_73 = F_15 ;
V_16 -> V_72 . V_74 = F_18 ;
V_16 -> V_72 . V_49 = V_49 ;
V_37 = F_32 ( V_26 , V_27 ,
& V_16 -> V_72 ) ;
if ( V_37 < 0 ) {
F_25 ( & V_49 -> V_40 , L_12 ) ;
goto V_75;
}
return V_37 ;
V_75:
F_33 ( V_11 ) ;
V_71:
F_34 ( & V_16 -> V_25 ) ;
V_70:
F_35 ( V_11 ) ;
V_62:
F_36 ( V_11 -> V_2 ) ;
return V_37 ;
}
static int F_37 ( struct V_48 * V_49 )
{
struct V_41 * V_26 = V_49 -> V_40 . V_58 ;
struct V_10 * V_11 = F_16 ( V_49 ) ;
struct V_16 * V_16 = F_3 ( V_11 ) ;
F_38 ( V_26 , V_27 ) ;
F_33 ( V_11 ) ;
F_34 ( & V_16 -> V_25 ) ;
F_35 ( V_11 ) ;
F_36 ( V_11 -> V_2 ) ;
return 0 ;
}
