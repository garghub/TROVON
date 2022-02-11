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
struct V_21 * V_22 =
V_17 -> V_23 . V_22 ;
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case 0 :
F_4 ( & V_17 -> V_23 , true ) ;
V_18 = V_17 -> V_24 [ V_12 -> V_25 ] . V_18 ;
V_19 = V_26 [ V_12 -> V_25 ] ;
if ( V_18 >= 0 )
* V_13 = F_5 (
V_17 -> V_23 . V_22 ,
V_22 -> V_27 , V_19 , V_18 ,
V_28 ) ;
else {
* V_13 = 0 ;
F_4 ( & V_17 -> V_23 ,
false ) ;
return - V_29 ;
}
F_4 ( & V_17 -> V_23 , false ) ;
V_20 = V_30 ;
break;
case V_31 :
* V_13 = V_17 -> V_32 ;
* V_14 = V_17 -> V_33 ;
V_20 = V_17 -> V_34 ;
break;
case V_35 :
* V_13 = V_17 -> V_36 ;
V_20 = V_30 ;
break;
case V_37 :
V_20 = F_6 (
& V_17 -> V_23 , V_13 , V_14 ) ;
break;
case V_38 :
V_20 = F_7 (
& V_17 -> V_23 , V_13 , V_14 ) ;
break;
default:
V_20 = - V_29 ;
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
int V_39 = 0 ;
switch ( V_15 ) {
case V_37 :
V_39 = F_9 (
& V_17 -> V_23 , V_13 , V_14 ) ;
break;
case V_38 :
V_39 = F_10 (
& V_17 -> V_23 , V_13 , V_14 ) ;
break;
default:
V_39 = - V_29 ;
}
return V_39 ;
}
static void F_11 ( struct V_10 * V_11 , void * V_40 ,
int V_41 , T_1 V_42 )
{
F_12 ( & V_11 -> V_43 , L_1 ) ;
F_13 ( V_11 , V_40 , V_42 ) ;
}
static int F_14 ( struct V_21 * V_22 ,
unsigned V_44 ,
void * V_45 )
{
struct V_10 * V_11 = F_15 ( V_45 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_43 , L_2 ) ;
if ( F_16 ( & V_17 -> V_23 . V_46 ) ) {
if ( ! V_17 -> V_42 )
V_17 -> V_42 = F_17 ( V_11 ) ;
F_11 ( V_11 ,
V_17 -> V_47 ,
sizeof( V_17 -> V_47 ) ,
V_17 -> V_42 ) ;
V_17 -> V_42 = 0 ;
}
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
unsigned V_44 ,
T_2 V_48 , char * V_49 ,
void * V_45 )
{
struct V_10 * V_11 = F_15 ( V_45 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_50 ;
int V_39 = - V_29 ;
switch ( V_44 ) {
case V_51 :
case V_52 :
case V_53 :
V_50 = V_44 - V_51 ;
V_17 -> V_47 [ V_54 + V_50 ] =
* ( V_9 * ) V_49 ;
V_39 = 0 ;
break;
case V_55 :
V_17 -> V_42 =
F_19 (
& V_17 -> V_23 ,
* ( T_1 * ) V_49 ) ;
break;
default:
break;
}
return V_39 ;
}
static int F_20 ( struct V_56 * V_57 ,
struct V_21 * V_22 ,
struct V_1 * V_2 ,
unsigned V_44 ,
struct V_16 * V_58 )
{
int V_39 ;
int V_59 ;
for ( V_59 = 0 ; V_59 <= V_60 ; ++ V_59 ) {
V_39 = F_21 ( V_22 ,
V_61 ,
V_44 ,
V_51 + V_59 ,
& V_58 -> V_24 [ V_54 + V_59 ] ) ;
if ( V_39 < 0 )
break;
F_1 ( V_2 ,
V_54 + V_59 ,
V_58 -> V_24 [ V_54 + V_59 ] . V_4 ) ;
}
F_12 ( & V_57 -> V_43 , L_3 ,
V_58 -> V_24 [ 0 ] . V_62 ,
V_58 -> V_24 [ 0 ] . V_18 ,
V_58 -> V_24 [ 1 ] . V_62 , V_58 -> V_24 [ 1 ] . V_18 ,
V_58 -> V_24 [ 2 ] . V_62 , V_58 -> V_24 [ 2 ] . V_18 ) ;
V_58 -> V_34 = F_22 (
V_22 -> V_27 ,
& V_58 -> V_24 [ V_54 ] ,
& V_58 -> V_32 , & V_58 -> V_33 ) ;
if ( V_58 -> V_23 . V_63 . V_62 < 0 ) {
F_21 ( V_22 ,
V_64 , V_44 ,
V_65 |
V_66 ,
& V_58 -> V_23 . V_63 ) ;
F_12 ( & V_57 -> V_43 , L_4 ,
V_58 -> V_23 . V_63 . V_62 ,
V_58 -> V_23 . V_63 . V_18 ) ;
}
return V_39 ;
}
static int F_23 ( struct V_56 * V_57 )
{
int V_39 = 0 ;
const char * V_67 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
const struct V_1 * V_68 ;
int V_69 ;
struct V_21 * V_22 = V_57 -> V_43 . V_70 ;
V_11 = F_24 ( & V_57 -> V_43 ,
sizeof( struct V_16 ) ) ;
if ( V_11 == NULL )
return - V_71 ;
F_25 ( V_57 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_23 . V_22 = V_22 ;
V_17 -> V_23 . V_57 = V_57 ;
if ( V_22 -> V_27 == V_72 ) {
V_67 = L_5 ;
V_68 = V_73 ;
V_69 = sizeof( V_73 ) ;
V_11 -> V_74 = F_26 ( V_73 ) ;
} else {
V_67 = L_6 ;
V_68 = V_75 ;
V_69 = sizeof( V_75 ) ;
V_11 -> V_74 = F_26 ( V_75 ) ;
}
V_39 = F_27 ( V_22 , V_22 -> V_27 ,
& V_17 -> V_23 ) ;
if ( V_39 ) {
F_28 ( & V_57 -> V_43 , L_7 ) ;
return V_39 ;
}
V_11 -> V_2 = F_29 ( V_68 , V_69 , V_76 ) ;
if ( ! V_11 -> V_2 ) {
F_28 ( & V_57 -> V_43 , L_8 ) ;
return - V_71 ;
}
V_39 = F_20 ( V_57 , V_22 ,
(struct V_1 * ) V_11 -> V_2 ,
V_22 -> V_27 , V_17 ) ;
if ( V_39 ) {
F_28 ( & V_57 -> V_43 , L_9 ) ;
goto V_77;
}
V_11 -> V_43 . V_78 = & V_57 -> V_43 ;
V_11 -> V_79 = & V_80 ;
V_11 -> V_67 = V_67 ;
V_11 -> V_81 = V_82 ;
V_39 = F_30 ( V_11 , & V_83 ,
NULL , NULL ) ;
if ( V_39 ) {
F_28 ( & V_57 -> V_43 , L_10 ) ;
goto V_77;
}
F_31 ( & V_17 -> V_23 . V_46 , 0 ) ;
V_39 = F_32 ( V_11 , V_67 ,
& V_17 -> V_23 ) ;
if ( V_39 < 0 ) {
F_28 ( & V_57 -> V_43 , L_11 ) ;
goto V_84;
}
V_39 = F_33 ( V_11 ) ;
if ( V_39 ) {
F_28 ( & V_57 -> V_43 , L_12 ) ;
goto V_85;
}
V_17 -> V_86 . V_87 = F_14 ;
V_17 -> V_86 . V_88 = F_18 ;
V_17 -> V_86 . V_57 = V_57 ;
V_39 = F_34 ( V_22 , V_22 -> V_27 ,
& V_17 -> V_86 ) ;
if ( V_39 < 0 ) {
F_28 ( & V_57 -> V_43 , L_13 ) ;
goto V_89;
}
return V_39 ;
V_89:
F_35 ( V_11 ) ;
V_85:
F_36 ( & V_17 -> V_23 ) ;
V_84:
F_37 ( V_11 ) ;
V_77:
F_38 ( V_11 -> V_2 ) ;
return V_39 ;
}
static int F_39 ( struct V_56 * V_57 )
{
struct V_21 * V_22 = V_57 -> V_43 . V_70 ;
struct V_10 * V_11 = F_15 ( V_57 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_40 ( V_22 , V_22 -> V_27 ) ;
F_35 ( V_11 ) ;
F_36 ( & V_17 -> V_23 ) ;
F_37 ( V_11 ) ;
F_38 ( V_11 -> V_2 ) ;
return 0 ;
}
