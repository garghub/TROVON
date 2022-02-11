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
V_18 ) ;
else {
* V_13 = 0 ;
F_4 ( & V_17 -> V_21 ,
false ) ;
return - V_26 ;
}
F_4 ( & V_17 -> V_21 , false ) ;
V_20 = V_27 ;
break;
case V_28 :
* V_13 = V_17 -> V_29 ;
* V_14 = V_17 -> V_30 ;
V_20 = V_17 -> V_31 ;
break;
case V_32 :
* V_13 = V_17 -> V_33 ;
V_20 = V_27 ;
break;
case V_34 :
V_20 = F_6 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_35 :
V_20 = F_7 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
default:
V_20 = - V_26 ;
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
int V_36 = 0 ;
switch ( V_15 ) {
case V_34 :
V_36 = F_9 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_35 :
V_36 = F_10 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
default:
V_36 = - V_26 ;
}
return V_36 ;
}
static void F_11 ( struct V_10 * V_11 , const void * V_37 )
{
F_12 ( & V_11 -> V_38 , L_1 ) ;
F_13 ( V_11 , V_37 ) ;
}
static int F_14 ( struct V_39 * V_24 ,
unsigned V_40 ,
void * V_41 )
{
struct V_10 * V_11 = F_15 ( V_41 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_38 , L_2 ) ;
if ( F_16 ( & V_17 -> V_21 . V_42 ) )
F_11 ( V_11 , V_17 -> V_43 ) ;
return 0 ;
}
static int F_17 ( struct V_39 * V_24 ,
unsigned V_40 ,
T_1 V_44 , char * V_45 ,
void * V_41 )
{
struct V_10 * V_11 = F_15 ( V_41 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_46 ;
int V_36 = 0 ;
V_9 * V_47 = NULL ;
switch ( V_40 ) {
case V_48 :
case V_49 :
case V_50 :
V_46 = ( V_40 - V_48 )
+ V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
V_46 = ( V_40 - V_52 )
+ V_56 ;
break;
default:
return - V_26 ;
}
V_47 = V_17 -> V_57 [ V_46 ] ;
if ( V_47 != NULL )
* V_47 = * ( ( V_9 * ) V_45 ) ;
else
V_36 = - V_26 ;
return V_36 ;
}
static int F_18 ( struct V_58 * V_59 ,
struct V_39 * V_24 ,
struct V_1 * * V_2 ,
int * V_60 ,
unsigned V_40 ,
struct V_16 * V_61 )
{
int V_62 ;
int V_63 = 0 ;
struct V_1 * V_64 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
int V_66 ;
V_9 V_19 = V_23 [ V_62 ] ;
V_66 = F_19 ( V_24 ,
V_67 ,
V_40 ,
V_19 ,
& ( V_61 -> V_22 [ V_62 ] ) ) ;
if ( ! V_66 )
V_63 ++ ;
}
if ( V_63 <= 0 ) {
F_20 ( & V_59 -> V_38 ,
L_3 ) ;
return - V_26 ;
}
F_12 ( & V_59 -> V_38 , L_4 ,
V_63 ) ;
F_12 ( & V_59 -> V_38 , L_5 ,
V_61 -> V_22 [ 0 ] . V_68 ,
V_61 -> V_22 [ 0 ] . V_18 ,
V_61 -> V_22 [ 1 ] . V_68 , V_61 -> V_22 [ 1 ] . V_18 ,
V_61 -> V_22 [ 2 ] . V_68 , V_61 -> V_22 [ 2 ] . V_18 ) ;
V_64 = F_21 ( & V_59 -> V_38 , V_63 ,
sizeof( struct V_1 ) ,
V_69 ) ;
if ( ! V_64 ) {
F_20 ( & V_59 -> V_38 ,
L_6 ) ;
return - V_70 ;
}
V_61 -> V_43 = F_21 ( & V_59 -> V_38 , V_63 ,
sizeof( V_9 ) ,
V_69 ) ;
if ( ! V_61 -> V_43 ) {
F_20 ( & V_59 -> V_38 ,
L_7 ) ;
return - V_70 ;
}
for ( V_62 = 0 , * V_60 = 0 ;
V_62 < V_65 && * V_60 < V_63 ;
V_62 ++ ) {
if ( V_61 -> V_22 [ V_62 ] . V_68 >= 0 ) {
( V_64 [ * V_60 ] ) = V_71 [ V_62 ] ;
( V_64 [ * V_60 ] ) . V_72 = * V_60 ;
( V_64 [ * V_60 ] ) . V_19 = V_62 ;
V_61 -> V_57 [ V_62 ] = & ( V_61 -> V_43 [ * V_60 ] ) ;
F_1 ( V_64 ,
* V_60 ,
V_61 -> V_22 [ V_62 ] . V_4 ) ;
( * V_60 ) ++ ;
}
}
if ( * V_60 <= 0 ) {
F_20 ( & V_59 -> V_38 ,
L_8 ) ;
return - V_26 ;
}
* V_2 = V_64 ;
F_12 ( & V_59 -> V_38 , L_9 ,
* V_60 ) ;
V_61 -> V_31 = F_22 (
V_25 ,
& V_61 -> V_22 [ V_51 ] ,
& V_61 -> V_29 , & V_61 -> V_30 ) ;
if ( V_61 -> V_21 . V_73 . V_68 < 0 ) {
F_19 ( V_24 ,
V_74 , V_40 ,
V_75 |
V_76 ,
& V_61 -> V_21 . V_73 ) ;
F_12 ( & V_59 -> V_38 , L_10 ,
V_61 -> V_21 . V_73 . V_68 ,
V_61 -> V_21 . V_73 . V_18 ) ;
}
return 0 ;
}
static int F_23 ( struct V_58 * V_59 )
{
int V_36 = 0 ;
static char * V_77 = L_11 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_39 * V_24 = V_59 -> V_38 . V_78 ;
struct V_1 * V_2 ;
int V_60 = 0 ;
V_11 = F_24 ( & V_59 -> V_38 ,
sizeof( struct V_16 ) ) ;
if ( V_11 == NULL )
return - V_70 ;
F_25 ( V_59 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_21 . V_24 = V_24 ;
V_17 -> V_21 . V_59 = V_59 ;
V_36 = F_26 ( V_24 ,
V_25 ,
& V_17 -> V_21 ) ;
if ( V_36 ) {
F_20 ( & V_59 -> V_38 , L_12 ) ;
return V_36 ;
}
V_36 = F_18 ( V_59 , V_24 ,
& V_2 , & V_60 ,
V_25 , V_17 ) ;
if ( V_36 ) {
F_20 ( & V_59 -> V_38 , L_13 ) ;
return V_36 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_79 = V_60 ;
V_11 -> V_38 . V_80 = & V_59 -> V_38 ;
V_11 -> V_81 = & V_82 ;
V_11 -> V_77 = V_77 ;
V_11 -> V_83 = V_84 ;
V_36 = F_27 ( V_11 , & V_85 ,
NULL , NULL ) ;
if ( V_36 ) {
F_20 ( & V_59 -> V_38 , L_14 ) ;
return V_36 ;
}
F_28 ( & V_17 -> V_21 . V_42 , 0 ) ;
V_36 = F_29 ( V_11 , V_77 ,
& V_17 -> V_21 ) ;
if ( V_36 < 0 ) {
F_20 ( & V_59 -> V_38 , L_15 ) ;
goto V_86;
}
V_36 = F_30 ( V_11 ) ;
if ( V_36 ) {
F_20 ( & V_59 -> V_38 , L_16 ) ;
goto V_87;
}
V_17 -> V_88 . V_89 = F_14 ;
V_17 -> V_88 . V_90 = F_17 ;
V_17 -> V_88 . V_59 = V_59 ;
V_36 = F_31 ( V_24 , V_25 ,
& V_17 -> V_88 ) ;
if ( V_36 < 0 ) {
F_20 ( & V_59 -> V_38 , L_17 ) ;
goto V_91;
}
return V_36 ;
V_91:
F_32 ( V_11 ) ;
V_87:
F_33 ( & V_17 -> V_21 ) ;
V_86:
F_34 ( V_11 ) ;
return V_36 ;
}
static int F_35 ( struct V_58 * V_59 )
{
struct V_39 * V_24 = V_59 -> V_38 . V_78 ;
struct V_10 * V_11 = F_15 ( V_59 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_36 ( V_24 , V_25 ) ;
F_32 ( V_11 ) ;
F_33 ( & V_17 -> V_21 ) ;
F_34 ( V_11 ) ;
return 0 ;
}
