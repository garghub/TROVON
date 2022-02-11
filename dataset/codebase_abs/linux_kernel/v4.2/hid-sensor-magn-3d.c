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
V_18 =
V_17 -> V_22 [ V_12 -> V_19 ] . V_18 ;
V_19 = V_23 [ V_12 -> V_19 ] ;
if ( V_18 >= 0 )
* V_13 = F_5 (
V_17 -> V_21 . V_24 ,
V_25 , V_19 ,
V_18 ,
V_26 ) ;
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
static void F_11 ( struct V_10 * V_11 , const void * V_38 )
{
F_12 ( & V_11 -> V_39 , L_1 ) ;
F_13 ( V_11 , V_38 ) ;
}
static int F_14 ( struct V_40 * V_24 ,
unsigned V_41 ,
void * V_42 )
{
struct V_10 * V_11 = F_15 ( V_42 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_39 , L_2 ) ;
if ( F_16 ( & V_17 -> V_21 . V_43 ) )
F_11 ( V_11 , V_17 -> V_44 ) ;
return 0 ;
}
static int F_17 ( struct V_40 * V_24 ,
unsigned V_41 ,
T_1 V_45 , char * V_46 ,
void * V_42 )
{
struct V_10 * V_11 = F_15 ( V_42 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_47 ;
int V_37 = 0 ;
V_9 * V_48 = NULL ;
switch ( V_41 ) {
case V_49 :
case V_50 :
case V_51 :
V_47 = ( V_41 - V_49 )
+ V_52 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_47 = ( V_41 - V_53 )
+ V_57 ;
break;
default:
return - V_27 ;
}
V_48 = V_17 -> V_58 [ V_47 ] ;
if ( V_48 != NULL )
* V_48 = * ( ( V_9 * ) V_46 ) ;
else
V_37 = - V_27 ;
return V_37 ;
}
static int F_18 ( struct V_59 * V_60 ,
struct V_40 * V_24 ,
struct V_1 * * V_2 ,
int * V_61 ,
unsigned V_41 ,
struct V_16 * V_62 )
{
int V_63 ;
int V_64 = 0 ;
struct V_1 * V_65 ;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ ) {
int V_67 ;
V_9 V_19 = V_23 [ V_63 ] ;
V_67 = F_19 ( V_24 ,
V_68 ,
V_41 ,
V_19 ,
& ( V_62 -> V_22 [ V_63 ] ) ) ;
if ( ! V_67 )
V_64 ++ ;
}
if ( V_64 <= 0 ) {
F_20 ( & V_60 -> V_39 ,
L_3 ) ;
return - V_27 ;
}
F_12 ( & V_60 -> V_39 , L_4 ,
V_64 ) ;
F_12 ( & V_60 -> V_39 , L_5 ,
V_62 -> V_22 [ 0 ] . V_69 ,
V_62 -> V_22 [ 0 ] . V_18 ,
V_62 -> V_22 [ 1 ] . V_69 , V_62 -> V_22 [ 1 ] . V_18 ,
V_62 -> V_22 [ 2 ] . V_69 , V_62 -> V_22 [ 2 ] . V_18 ) ;
V_65 = F_21 ( & V_60 -> V_39 , V_64 ,
sizeof( struct V_1 ) ,
V_70 ) ;
if ( ! V_65 ) {
F_20 ( & V_60 -> V_39 ,
L_6 ) ;
return - V_71 ;
}
V_62 -> V_44 = F_21 ( & V_60 -> V_39 , V_64 ,
sizeof( V_9 ) ,
V_70 ) ;
if ( ! V_62 -> V_44 ) {
F_20 ( & V_60 -> V_39 ,
L_7 ) ;
return - V_71 ;
}
for ( V_63 = 0 , * V_61 = 0 ;
V_63 < V_66 && * V_61 < V_64 ;
V_63 ++ ) {
if ( V_62 -> V_22 [ V_63 ] . V_69 >= 0 ) {
( V_65 [ * V_61 ] ) = V_72 [ V_63 ] ;
( V_65 [ * V_61 ] ) . V_73 = * V_61 ;
( V_65 [ * V_61 ] ) . V_19 = V_63 ;
V_62 -> V_58 [ V_63 ] = & ( V_62 -> V_44 [ * V_61 ] ) ;
F_1 ( V_65 ,
* V_61 ,
V_62 -> V_22 [ V_63 ] . V_4 ) ;
( * V_61 ) ++ ;
}
}
if ( * V_61 <= 0 ) {
F_20 ( & V_60 -> V_39 ,
L_8 ) ;
return - V_27 ;
}
* V_2 = V_65 ;
F_12 ( & V_60 -> V_39 , L_9 ,
* V_61 ) ;
V_62 -> V_32 = F_22 (
V_25 ,
& V_62 -> V_22 [ V_52 ] ,
& V_62 -> V_30 , & V_62 -> V_31 ) ;
if ( V_62 -> V_21 . V_74 . V_69 < 0 ) {
F_19 ( V_24 ,
V_75 , V_41 ,
V_76 |
V_77 ,
& V_62 -> V_21 . V_74 ) ;
F_12 ( & V_60 -> V_39 , L_10 ,
V_62 -> V_21 . V_74 . V_69 ,
V_62 -> V_21 . V_74 . V_18 ) ;
}
return 0 ;
}
static int F_23 ( struct V_59 * V_60 )
{
int V_37 = 0 ;
static char * V_78 = L_11 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_40 * V_24 = V_60 -> V_39 . V_79 ;
struct V_1 * V_2 ;
int V_61 = 0 ;
V_11 = F_24 ( & V_60 -> V_39 ,
sizeof( struct V_16 ) ) ;
if ( V_11 == NULL )
return - V_71 ;
F_25 ( V_60 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_21 . V_24 = V_24 ;
V_17 -> V_21 . V_60 = V_60 ;
V_37 = F_26 ( V_24 ,
V_25 ,
& V_17 -> V_21 ) ;
if ( V_37 ) {
F_20 ( & V_60 -> V_39 , L_12 ) ;
return V_37 ;
}
V_37 = F_18 ( V_60 , V_24 ,
& V_2 , & V_61 ,
V_25 , V_17 ) ;
if ( V_37 ) {
F_20 ( & V_60 -> V_39 , L_13 ) ;
return V_37 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_80 = V_61 ;
V_11 -> V_39 . V_81 = & V_60 -> V_39 ;
V_11 -> V_82 = & V_83 ;
V_11 -> V_78 = V_78 ;
V_11 -> V_84 = V_85 ;
V_37 = F_27 ( V_11 , & V_86 ,
NULL , NULL ) ;
if ( V_37 ) {
F_20 ( & V_60 -> V_39 , L_14 ) ;
return V_37 ;
}
F_28 ( & V_17 -> V_21 . V_43 , 0 ) ;
V_37 = F_29 ( V_11 , V_78 ,
& V_17 -> V_21 ) ;
if ( V_37 < 0 ) {
F_20 ( & V_60 -> V_39 , L_15 ) ;
goto V_87;
}
V_37 = F_30 ( V_11 ) ;
if ( V_37 ) {
F_20 ( & V_60 -> V_39 , L_16 ) ;
goto V_88;
}
V_17 -> V_89 . V_90 = F_14 ;
V_17 -> V_89 . V_91 = F_17 ;
V_17 -> V_89 . V_60 = V_60 ;
V_37 = F_31 ( V_24 , V_25 ,
& V_17 -> V_89 ) ;
if ( V_37 < 0 ) {
F_20 ( & V_60 -> V_39 , L_17 ) ;
goto V_92;
}
return V_37 ;
V_92:
F_32 ( V_11 ) ;
V_88:
F_33 ( & V_17 -> V_21 ) ;
V_87:
F_34 ( V_11 ) ;
return V_37 ;
}
static int F_35 ( struct V_59 * V_60 )
{
struct V_40 * V_24 = V_60 -> V_39 . V_79 ;
struct V_10 * V_11 = F_15 ( V_60 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_36 ( V_24 , V_25 ) ;
F_32 ( V_11 ) ;
F_33 ( & V_17 -> V_21 ) ;
F_34 ( V_11 ) ;
return 0 ;
}
