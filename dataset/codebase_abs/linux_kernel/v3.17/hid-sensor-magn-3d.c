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
T_1 V_21 ;
* V_13 = 0 ;
* V_14 = 0 ;
switch ( V_15 ) {
case 0 :
V_21 = F_4 (
& V_17 -> V_22 ) ;
if ( V_21 < 0 )
return - V_23 ;
F_5 ( & V_17 -> V_22 , true ) ;
F_6 ( V_21 * 2 ) ;
V_18 =
V_17 -> V_24 [ V_12 -> V_19 ] . V_18 ;
V_19 = V_25 [ V_12 -> V_19 ] ;
if ( V_18 >= 0 )
* V_13 = F_7 (
V_17 -> V_22 . V_26 ,
V_27 , V_19 ,
V_18 ) ;
else {
* V_13 = 0 ;
F_5 ( & V_17 -> V_22 ,
false ) ;
return - V_23 ;
}
F_5 ( & V_17 -> V_22 , false ) ;
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
V_20 = F_8 (
& V_17 -> V_22 , V_13 , V_14 ) ;
break;
case V_36 :
V_20 = F_9 (
& V_17 -> V_22 , V_13 , V_14 ) ;
break;
default:
V_20 = - V_23 ;
break;
}
return V_20 ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 ,
int V_14 ,
long V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_37 = 0 ;
switch ( V_15 ) {
case V_35 :
V_37 = F_11 (
& V_17 -> V_22 , V_13 , V_14 ) ;
break;
case V_36 :
V_37 = F_12 (
& V_17 -> V_22 , V_13 , V_14 ) ;
break;
default:
V_37 = - V_23 ;
}
return V_37 ;
}
static void F_13 ( struct V_10 * V_11 , const void * V_38 ,
int V_39 )
{
F_14 ( & V_11 -> V_40 , L_1 ) ;
F_15 ( V_11 , V_38 ) ;
}
static int F_16 ( struct V_41 * V_26 ,
unsigned V_42 ,
void * V_43 )
{
struct V_10 * V_11 = F_17 ( V_43 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_14 ( & V_11 -> V_40 , L_2 ) ;
if ( F_18 ( & V_17 -> V_22 . V_44 ) )
F_13 ( V_11 ,
V_17 -> V_45 ,
sizeof( V_17 -> V_45 ) ) ;
return 0 ;
}
static int F_19 ( struct V_41 * V_26 ,
unsigned V_42 ,
T_2 V_46 , char * V_47 ,
void * V_43 )
{
struct V_10 * V_11 = F_17 ( V_43 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_48 ;
int V_37 = 0 ;
V_9 * V_49 = NULL ;
switch ( V_42 ) {
case V_50 :
case V_51 :
case V_52 :
V_48 = ( V_42 - V_50 )
+ V_53 ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_48 = ( V_42 - V_54 )
+ V_58 ;
break;
default:
return - V_23 ;
}
V_49 = V_17 -> V_59 [ V_48 ] ;
if ( V_49 != NULL )
* V_49 = * ( ( V_9 * ) V_47 ) ;
else
V_37 = - V_23 ;
return V_37 ;
}
static int F_20 ( struct V_60 * V_61 ,
struct V_41 * V_26 ,
struct V_1 * * V_2 ,
int * V_62 ,
unsigned V_42 ,
struct V_16 * V_63 )
{
int V_64 ;
int V_65 = 0 ;
struct V_1 * V_66 ;
for ( V_64 = 0 ; V_64 < V_67 ; V_64 ++ ) {
int V_68 ;
V_9 V_19 = V_25 [ V_64 ] ;
V_68 = F_21 ( V_26 ,
V_69 ,
V_42 ,
V_19 ,
& ( V_63 -> V_24 [ V_64 ] ) ) ;
if ( ! V_68 )
V_65 ++ ;
}
if ( V_65 <= 0 ) {
F_22 ( & V_61 -> V_40 ,
L_3 ) ;
return - V_23 ;
}
F_14 ( & V_61 -> V_40 , L_4 ,
V_65 ) ;
F_14 ( & V_61 -> V_40 , L_5 ,
V_63 -> V_24 [ 0 ] . V_70 ,
V_63 -> V_24 [ 0 ] . V_18 ,
V_63 -> V_24 [ 1 ] . V_70 , V_63 -> V_24 [ 1 ] . V_18 ,
V_63 -> V_24 [ 2 ] . V_70 , V_63 -> V_24 [ 2 ] . V_18 ) ;
V_66 = F_23 ( & V_61 -> V_40 , V_65 ,
sizeof( struct V_1 ) ,
V_71 ) ;
if ( ! V_66 ) {
F_22 ( & V_61 -> V_40 ,
L_6 ) ;
return - V_72 ;
}
V_63 -> V_45 = F_23 ( & V_61 -> V_40 , V_65 ,
sizeof( V_9 ) ,
V_71 ) ;
if ( ! V_63 -> V_45 ) {
F_22 ( & V_61 -> V_40 ,
L_7 ) ;
return - V_72 ;
}
for ( V_64 = 0 , * V_62 = 0 ;
V_64 < V_67 && * V_62 < V_65 ;
V_64 ++ ) {
if ( V_63 -> V_24 [ V_64 ] . V_70 >= 0 ) {
( V_66 [ * V_62 ] ) = V_73 [ V_64 ] ;
( V_66 [ * V_62 ] ) . V_74 = * V_62 ;
( V_66 [ * V_62 ] ) . V_19 = V_64 ;
V_63 -> V_59 [ V_64 ] = & ( V_63 -> V_45 [ * V_62 ] ) ;
F_1 ( V_66 ,
* V_62 ,
V_63 -> V_24 [ V_64 ] . V_4 ) ;
( * V_62 ) ++ ;
}
}
if ( * V_62 <= 0 ) {
F_22 ( & V_61 -> V_40 ,
L_8 ) ;
return - V_23 ;
}
* V_2 = V_66 ;
F_14 ( & V_61 -> V_40 , L_9 ,
* V_62 ) ;
V_63 -> V_32 = F_24 (
V_27 ,
& V_63 -> V_24 [ V_53 ] ,
& V_63 -> V_30 , & V_63 -> V_31 ) ;
if ( V_63 -> V_22 . V_75 . V_70 < 0 ) {
F_21 ( V_26 ,
V_76 , V_42 ,
V_77 |
V_78 ,
& V_63 -> V_22 . V_75 ) ;
F_14 ( & V_61 -> V_40 , L_10 ,
V_63 -> V_22 . V_75 . V_70 ,
V_63 -> V_22 . V_75 . V_18 ) ;
}
return 0 ;
}
static int F_25 ( struct V_60 * V_61 )
{
int V_37 = 0 ;
static char * V_79 = L_11 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_41 * V_26 = V_61 -> V_40 . V_80 ;
struct V_1 * V_2 ;
int V_62 = 0 ;
V_11 = F_26 ( & V_61 -> V_40 ,
sizeof( struct V_16 ) ) ;
if ( V_11 == NULL )
return - V_72 ;
F_27 ( V_61 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_22 . V_26 = V_26 ;
V_17 -> V_22 . V_61 = V_61 ;
V_37 = F_28 ( V_26 ,
V_27 ,
& V_17 -> V_22 ) ;
if ( V_37 ) {
F_22 ( & V_61 -> V_40 , L_12 ) ;
return V_37 ;
}
V_37 = F_20 ( V_61 , V_26 ,
& V_2 , & V_62 ,
V_27 , V_17 ) ;
if ( V_37 ) {
F_22 ( & V_61 -> V_40 , L_13 ) ;
return V_37 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_81 = V_62 ;
V_11 -> V_40 . V_82 = & V_61 -> V_40 ;
V_11 -> V_83 = & V_84 ;
V_11 -> V_79 = V_79 ;
V_11 -> V_85 = V_86 ;
V_37 = F_29 ( V_11 , & V_87 ,
NULL , NULL ) ;
if ( V_37 ) {
F_22 ( & V_61 -> V_40 , L_14 ) ;
return V_37 ;
}
F_30 ( & V_17 -> V_22 . V_44 , 0 ) ;
V_37 = F_31 ( V_11 , V_79 ,
& V_17 -> V_22 ) ;
if ( V_37 < 0 ) {
F_22 ( & V_61 -> V_40 , L_15 ) ;
goto V_88;
}
V_37 = F_32 ( V_11 ) ;
if ( V_37 ) {
F_22 ( & V_61 -> V_40 , L_16 ) ;
goto V_89;
}
V_17 -> V_90 . V_91 = F_16 ;
V_17 -> V_90 . V_92 = F_19 ;
V_17 -> V_90 . V_61 = V_61 ;
V_37 = F_33 ( V_26 , V_27 ,
& V_17 -> V_90 ) ;
if ( V_37 < 0 ) {
F_22 ( & V_61 -> V_40 , L_17 ) ;
goto V_93;
}
return V_37 ;
V_93:
F_34 ( V_11 ) ;
V_89:
F_35 ( & V_17 -> V_22 ) ;
V_88:
F_36 ( V_11 ) ;
return V_37 ;
}
static int F_37 ( struct V_60 * V_61 )
{
struct V_41 * V_26 = V_61 -> V_40 . V_80 ;
struct V_10 * V_11 = F_17 ( V_61 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_38 ( V_26 , V_27 ) ;
F_34 ( V_11 ) ;
F_35 ( & V_17 -> V_22 ) ;
F_36 ( V_11 ) ;
return 0 ;
}
