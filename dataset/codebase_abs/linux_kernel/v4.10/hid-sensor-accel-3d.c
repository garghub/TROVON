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
V_18 ,
V_27 ) ;
else {
* V_13 = 0 ;
F_4 ( & V_17 -> V_21 ,
false ) ;
return - V_28 ;
}
F_4 ( & V_17 -> V_21 , false ) ;
V_20 = V_29 ;
break;
case V_30 :
* V_13 = V_17 -> V_31 ;
* V_14 = V_17 -> V_32 ;
V_20 = V_17 -> V_33 ;
break;
case V_34 :
* V_13 = V_17 -> V_35 ;
V_20 = V_29 ;
break;
case V_36 :
V_20 = F_6 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_37 :
V_20 = F_7 (
& V_17 -> V_21 , V_13 , V_14 ) ;
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
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_38 = 0 ;
switch ( V_15 ) {
case V_36 :
V_38 = F_9 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_37 :
V_38 = F_10 (
& V_17 -> V_21 , V_13 , V_14 ) ;
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
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_41 , L_2 ) ;
if ( F_16 ( & V_17 -> V_21 . V_45 ) )
F_11 ( V_11 ,
V_17 -> V_46 ,
sizeof( V_17 -> V_46 ) ) ;
return 0 ;
}
static int F_17 ( struct V_42 * V_25 ,
unsigned V_43 ,
T_1 V_47 , char * V_48 ,
void * V_44 )
{
struct V_10 * V_11 = F_15 ( V_44 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_49 ;
int V_38 = - V_28 ;
switch ( V_43 ) {
case V_50 :
case V_51 :
case V_52 :
V_49 = V_43 - V_50 ;
V_17 -> V_46 [ V_53 + V_49 ] =
* ( V_9 * ) V_48 ;
V_38 = 0 ;
break;
default:
break;
}
return V_38 ;
}
static int F_18 ( struct V_54 * V_55 ,
struct V_42 * V_25 ,
struct V_1 * V_2 ,
unsigned V_43 ,
struct V_16 * V_56 )
{
int V_38 ;
int V_57 ;
for ( V_57 = 0 ; V_57 <= V_58 ; ++ V_57 ) {
V_38 = F_19 ( V_25 ,
V_59 ,
V_43 ,
V_50 + V_57 ,
& V_56 -> V_22 [ V_53 + V_57 ] ) ;
if ( V_38 < 0 )
break;
F_1 ( V_2 ,
V_53 + V_57 ,
V_56 -> V_22 [ V_53 + V_57 ] . V_4 ) ;
}
F_12 ( & V_55 -> V_41 , L_3 ,
V_56 -> V_22 [ 0 ] . V_60 ,
V_56 -> V_22 [ 0 ] . V_18 ,
V_56 -> V_22 [ 1 ] . V_60 , V_56 -> V_22 [ 1 ] . V_18 ,
V_56 -> V_22 [ 2 ] . V_60 , V_56 -> V_22 [ 2 ] . V_18 ) ;
V_56 -> V_33 = F_20 (
V_26 ,
& V_56 -> V_22 [ V_53 ] ,
& V_56 -> V_31 , & V_56 -> V_32 ) ;
if ( V_56 -> V_21 . V_61 . V_60 < 0 ) {
F_19 ( V_25 ,
V_62 , V_43 ,
V_63 |
V_64 ,
& V_56 -> V_21 . V_61 ) ;
F_12 ( & V_55 -> V_41 , L_4 ,
V_56 -> V_21 . V_61 . V_60 ,
V_56 -> V_21 . V_61 . V_18 ) ;
}
return V_38 ;
}
static int F_21 ( struct V_54 * V_55 )
{
int V_38 = 0 ;
static const char * V_65 = L_5 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_42 * V_25 = V_55 -> V_41 . V_66 ;
V_11 = F_22 ( & V_55 -> V_41 ,
sizeof( struct V_16 ) ) ;
if ( V_11 == NULL )
return - V_67 ;
F_23 ( V_55 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_21 . V_25 = V_25 ;
V_17 -> V_21 . V_55 = V_55 ;
V_38 = F_24 ( V_25 ,
V_26 ,
& V_17 -> V_21 ) ;
if ( V_38 ) {
F_25 ( & V_55 -> V_41 , L_6 ) ;
return V_38 ;
}
V_11 -> V_2 = F_26 ( V_68 ,
sizeof( V_68 ) , V_69 ) ;
if ( ! V_11 -> V_2 ) {
F_25 ( & V_55 -> V_41 , L_7 ) ;
return - V_67 ;
}
V_38 = F_18 ( V_55 , V_25 ,
(struct V_1 * ) V_11 -> V_2 ,
V_26 , V_17 ) ;
if ( V_38 ) {
F_25 ( & V_55 -> V_41 , L_8 ) ;
goto V_70;
}
V_11 -> V_71 = F_27 ( V_68 ) ;
V_11 -> V_41 . V_72 = & V_55 -> V_41 ;
V_11 -> V_73 = & V_74 ;
V_11 -> V_65 = V_65 ;
V_11 -> V_75 = V_76 ;
V_38 = F_28 ( V_11 , & V_77 ,
NULL , NULL ) ;
if ( V_38 ) {
F_25 ( & V_55 -> V_41 , L_9 ) ;
goto V_70;
}
F_29 ( & V_17 -> V_21 . V_45 , 0 ) ;
V_38 = F_30 ( V_11 , V_65 ,
& V_17 -> V_21 ) ;
if ( V_38 < 0 ) {
F_25 ( & V_55 -> V_41 , L_10 ) ;
goto V_78;
}
V_38 = F_31 ( V_11 ) ;
if ( V_38 ) {
F_25 ( & V_55 -> V_41 , L_11 ) ;
goto V_79;
}
V_17 -> V_80 . V_81 = F_14 ;
V_17 -> V_80 . V_82 = F_17 ;
V_17 -> V_80 . V_55 = V_55 ;
V_38 = F_32 ( V_25 , V_26 ,
& V_17 -> V_80 ) ;
if ( V_38 < 0 ) {
F_25 ( & V_55 -> V_41 , L_12 ) ;
goto V_83;
}
return V_38 ;
V_83:
F_33 ( V_11 ) ;
V_79:
F_34 ( & V_17 -> V_21 ) ;
V_78:
F_35 ( V_11 ) ;
V_70:
F_36 ( V_11 -> V_2 ) ;
return V_38 ;
}
static int F_37 ( struct V_54 * V_55 )
{
struct V_42 * V_25 = V_55 -> V_41 . V_66 ;
struct V_10 * V_11 = F_15 ( V_55 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_38 ( V_25 , V_26 ) ;
F_33 ( V_11 ) ;
F_34 ( & V_17 -> V_21 ) ;
F_35 ( V_11 ) ;
F_36 ( V_11 -> V_2 ) ;
return 0 ;
}
