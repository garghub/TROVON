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
F_4 (
& V_17 -> V_21 ,
false ) ;
return - V_27 ;
}
F_4 ( & V_17 -> V_21 ,
false ) ;
V_20 = V_28 ;
break;
case V_29 :
switch ( V_12 -> type ) {
case V_30 :
* V_13 = V_17 -> V_31 . V_32 ;
* V_14 = V_17 -> V_31 . V_33 ;
V_20 = V_17 -> V_31 . V_34 ;
break;
case V_35 :
* V_13 = V_17 -> V_36 . V_32 ;
* V_14 = V_17 -> V_36 . V_33 ;
V_20 = V_17 -> V_36 . V_34 ;
break;
default:
V_20 = - V_27 ;
}
break;
case V_37 :
switch ( V_12 -> type ) {
case V_30 :
* V_13 = V_17 -> V_31 . V_38 ;
V_20 = V_28 ;
break;
case V_35 :
* V_13 = V_17 -> V_36 . V_38 ;
V_20 = V_28 ;
break;
default:
V_20 = - V_27 ;
}
break;
case V_39 :
V_20 = F_6 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_40 :
switch ( V_12 -> type ) {
case V_30 :
V_20 = F_7 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_35 :
V_20 = F_7 (
& V_17 -> V_41 , V_13 , V_14 ) ;
break;
default:
V_20 = - V_27 ;
}
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
int V_42 = 0 ;
switch ( V_15 ) {
case V_39 :
V_42 = F_9 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_40 :
switch ( V_12 -> type ) {
case V_30 :
V_42 = F_10 (
& V_17 -> V_21 , V_13 , V_14 ) ;
break;
case V_35 :
V_42 = F_10 (
& V_17 -> V_41 , V_13 , V_14 ) ;
break;
default:
V_42 = - V_27 ;
}
break;
default:
V_42 = - V_27 ;
}
return V_42 ;
}
static void F_11 ( struct V_10 * V_11 , const void * V_43 )
{
F_12 ( & V_11 -> V_44 , L_1 ) ;
F_13 ( V_11 , V_43 ) ;
}
static int F_14 ( struct V_45 * V_24 ,
unsigned V_46 ,
void * V_47 )
{
struct V_10 * V_11 = F_15 ( V_47 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_12 ( & V_11 -> V_44 , L_2 ) ;
if ( F_16 ( & V_17 -> V_21 . V_48 ) )
F_11 ( V_11 , V_17 -> V_49 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_24 ,
unsigned V_46 ,
T_1 V_50 , char * V_51 ,
void * V_47 )
{
struct V_10 * V_11 = F_15 ( V_47 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
int V_52 ;
int V_42 = 0 ;
V_9 * V_53 = NULL ;
switch ( V_46 ) {
case V_54 :
case V_55 :
case V_56 :
V_52 = ( V_46 - V_54 )
+ V_57 ;
break;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
V_52 = ( V_46 - V_58 )
+ V_62 ;
break;
default:
return - V_27 ;
}
V_53 = V_17 -> V_63 [ V_52 ] ;
if ( V_53 != NULL )
* V_53 = * ( ( V_9 * ) V_51 ) ;
else
V_42 = - V_27 ;
return V_42 ;
}
static int F_18 ( struct V_64 * V_65 ,
struct V_45 * V_24 ,
struct V_1 * * V_2 ,
int * V_66 ,
unsigned V_46 ,
struct V_16 * V_67 )
{
int V_68 ;
int V_69 = 0 ;
struct V_1 * V_70 ;
for ( V_68 = 0 ; V_68 < V_71 ; V_68 ++ ) {
int V_72 ;
V_9 V_19 = V_23 [ V_68 ] ;
V_72 = F_19 ( V_24 ,
V_73 ,
V_46 ,
V_19 ,
& ( V_67 -> V_22 [ V_68 ] ) ) ;
if ( ! V_72 )
V_69 ++ ;
}
if ( V_69 <= 0 ) {
F_20 ( & V_65 -> V_44 ,
L_3 ) ;
return - V_27 ;
}
F_12 ( & V_65 -> V_44 , L_4 ,
V_69 ) ;
F_12 ( & V_65 -> V_44 , L_5 ,
V_67 -> V_22 [ 0 ] . V_74 ,
V_67 -> V_22 [ 0 ] . V_18 ,
V_67 -> V_22 [ 1 ] . V_74 , V_67 -> V_22 [ 1 ] . V_18 ,
V_67 -> V_22 [ 2 ] . V_74 , V_67 -> V_22 [ 2 ] . V_18 ) ;
V_70 = F_21 ( & V_65 -> V_44 , V_69 ,
sizeof( struct V_1 ) ,
V_75 ) ;
if ( ! V_70 ) {
F_20 ( & V_65 -> V_44 ,
L_6 ) ;
return - V_76 ;
}
V_67 -> V_49 = F_21 ( & V_65 -> V_44 , V_69 ,
sizeof( V_9 ) ,
V_75 ) ;
if ( ! V_67 -> V_49 ) {
F_20 ( & V_65 -> V_44 ,
L_7 ) ;
return - V_76 ;
}
for ( V_68 = 0 , * V_66 = 0 ;
V_68 < V_71 && * V_66 < V_69 ;
V_68 ++ ) {
if ( V_67 -> V_22 [ V_68 ] . V_74 >= 0 ) {
( V_70 [ * V_66 ] ) = V_77 [ V_68 ] ;
( V_70 [ * V_66 ] ) . V_78 = * V_66 ;
( V_70 [ * V_66 ] ) . V_19 = V_68 ;
V_67 -> V_63 [ V_68 ] = & ( V_67 -> V_49 [ * V_66 ] ) ;
F_1 ( V_70 ,
* V_66 ,
V_67 -> V_22 [ V_68 ] . V_4 ) ;
( * V_66 ) ++ ;
}
}
if ( * V_66 <= 0 ) {
F_20 ( & V_65 -> V_44 ,
L_8 ) ;
return - V_27 ;
}
* V_2 = V_70 ;
F_12 ( & V_65 -> V_44 , L_9 ,
* V_66 ) ;
V_67 -> V_31 . V_34 = F_22 (
V_25 ,
& V_67 -> V_22 [ V_57 ] ,
& V_67 -> V_31 . V_32 ,
& V_67 -> V_31 . V_33 ) ;
V_67 -> V_36 . V_34
= F_22 (
V_58 ,
& V_67 -> V_22 [ V_62 ] ,
& V_67 -> V_36 . V_32 ,
& V_67 -> V_36 . V_33 ) ;
if ( V_67 -> V_21 . V_79 . V_74 < 0 ) {
F_19 ( V_24 ,
V_80 , V_46 ,
V_81 |
V_82 ,
& V_67 -> V_21 . V_79 ) ;
F_12 ( & V_65 -> V_44 , L_10 ,
V_67 -> V_21 . V_79 . V_74 ,
V_67 -> V_21 . V_79 . V_18 ) ;
}
if ( V_67 -> V_21 . V_79 . V_74 < 0 ) {
F_19 ( V_24 ,
V_80 , V_46 ,
V_81 |
V_83 ,
& V_67 -> V_21 . V_79 ) ;
F_12 ( & V_65 -> V_44 , L_10 ,
V_67 -> V_21 . V_79 . V_74 ,
V_67 -> V_21 . V_79 . V_18 ) ;
}
if ( V_67 -> V_41 . V_79 . V_74 < 0 ) {
F_19 ( V_24 ,
V_80 , V_46 ,
V_81 |
V_58 ,
& V_67 -> V_41 . V_79 ) ;
F_12 ( & V_65 -> V_44 , L_10 ,
V_67 -> V_41 . V_79 . V_74 ,
V_67 -> V_41 . V_79 . V_18 ) ;
}
return 0 ;
}
static int F_23 ( struct V_64 * V_65 )
{
int V_42 = 0 ;
static char * V_84 = L_11 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_45 * V_24 = V_65 -> V_44 . V_85 ;
struct V_1 * V_2 ;
int V_66 = 0 ;
V_11 = F_24 ( & V_65 -> V_44 ,
sizeof( struct V_16 ) ) ;
if ( V_11 == NULL )
return - V_76 ;
F_25 ( V_65 , V_11 ) ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_21 . V_24 = V_24 ;
V_17 -> V_21 . V_65 = V_65 ;
V_42 = F_26 ( V_24 ,
V_25 ,
& V_17 -> V_21 ) ;
if ( V_42 ) {
F_20 ( & V_65 -> V_44 , L_12 ) ;
return V_42 ;
}
V_17 -> V_41 = V_17 -> V_21 ;
V_42 = F_18 ( V_65 , V_24 ,
& V_2 , & V_66 ,
V_25 , V_17 ) ;
if ( V_42 ) {
F_20 ( & V_65 -> V_44 , L_13 ) ;
return V_42 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_86 = V_66 ;
V_11 -> V_44 . V_87 = & V_65 -> V_44 ;
V_11 -> V_88 = & V_89 ;
V_11 -> V_84 = V_84 ;
V_11 -> V_90 = V_91 ;
V_42 = F_27 ( V_11 , & V_92 ,
NULL , NULL ) ;
if ( V_42 ) {
F_20 ( & V_65 -> V_44 , L_14 ) ;
return V_42 ;
}
F_28 ( & V_17 -> V_21 . V_48 , 0 ) ;
V_42 = F_29 ( V_11 , V_84 ,
& V_17 -> V_21 ) ;
if ( V_42 < 0 ) {
F_20 ( & V_65 -> V_44 , L_15 ) ;
goto V_93;
}
V_42 = F_30 ( V_11 ) ;
if ( V_42 ) {
F_20 ( & V_65 -> V_44 , L_16 ) ;
goto V_94;
}
V_17 -> V_95 . V_96 = F_14 ;
V_17 -> V_95 . V_97 = F_17 ;
V_17 -> V_95 . V_65 = V_65 ;
V_42 = F_31 ( V_24 , V_25 ,
& V_17 -> V_95 ) ;
if ( V_42 < 0 ) {
F_20 ( & V_65 -> V_44 , L_17 ) ;
goto V_98;
}
return V_42 ;
V_98:
F_32 ( V_11 ) ;
V_94:
F_33 ( & V_17 -> V_21 ) ;
V_93:
F_34 ( V_11 ) ;
return V_42 ;
}
static int F_35 ( struct V_64 * V_65 )
{
struct V_45 * V_24 = V_65 -> V_44 . V_85 ;
struct V_10 * V_11 = F_15 ( V_65 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_36 ( V_24 , V_25 ) ;
F_32 ( V_11 ) ;
F_33 ( & V_17 -> V_21 ) ;
F_34 ( V_11 ) ;
return 0 ;
}
