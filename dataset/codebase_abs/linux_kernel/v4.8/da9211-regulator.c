static unsigned int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
unsigned int V_6 ;
int V_7 , V_8 = 0 ;
V_7 = F_4 ( V_5 -> V_9 , V_10 + V_3 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_6 & 0x03 ) {
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
V_8 = V_14 ;
break;
case V_15 :
V_8 = V_16 ;
break;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
int V_17 = 0 ;
switch ( V_8 ) {
case V_12 :
V_17 = V_11 ;
break;
case V_14 :
V_17 = V_13 ;
break;
case V_16 :
V_17 = V_15 ;
break;
}
return F_6 ( V_5 -> V_9 , V_10 + V_3 ,
0x03 , V_17 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_18 ,
int V_19 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
int V_20 , V_21 ;
const int * V_22 ;
switch ( V_5 -> V_23 ) {
case V_24 :
V_22 = V_25 ;
V_21 = F_8 ( V_25 ) - 1 ;
break;
case V_26 :
V_22 = V_27 ;
V_21 = F_8 ( V_27 ) - 1 ;
break;
case V_28 :
V_22 = V_29 ;
V_21 = F_8 ( V_29 ) - 1 ;
break;
default:
return - V_30 ;
}
for ( V_20 = V_21 ; V_20 >= 0 ; V_20 -- ) {
if ( V_18 <= V_22 [ V_20 ] &&
V_19 >= V_22 [ V_20 ] ) {
return F_6 ( V_5 -> V_9 ,
V_31 ,
( 0x0F << V_3 * 4 ) , ( V_20 << V_3 * 4 ) ) ;
}
}
return - V_30 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
unsigned int V_6 ;
int V_7 ;
const int * V_22 ;
switch ( V_5 -> V_23 ) {
case V_24 :
V_22 = V_25 ;
break;
case V_26 :
V_22 = V_27 ;
break;
case V_28 :
V_22 = V_29 ;
break;
default:
return - V_30 ;
}
V_7 = F_4 ( V_5 -> V_9 , V_31 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = ( V_6 >> V_3 * 4 ) & 0x0F ;
return V_22 [ V_6 ] ;
}
static struct V_32 * F_10 (
struct V_33 * V_34 )
{
struct V_32 * V_35 ;
struct V_36 * V_37 ;
int V_20 , V_38 , V_39 ;
V_37 = F_11 ( V_34 -> V_40 , L_1 ) ;
if ( ! V_37 ) {
F_12 ( V_34 , L_2 ) ;
return F_13 ( - V_41 ) ;
}
V_38 = F_14 ( V_34 , V_37 , V_42 ,
F_8 ( V_42 ) ) ;
F_15 ( V_37 ) ;
if ( V_38 < 0 ) {
F_12 ( V_34 , L_3 ) ;
return F_13 ( - V_30 ) ;
}
V_35 = F_16 ( V_34 , sizeof( * V_35 ) , V_43 ) ;
if ( ! V_35 )
return F_13 ( - V_44 ) ;
V_35 -> V_45 = V_38 ;
V_39 = 0 ;
for ( V_20 = 0 ; V_20 < F_8 ( V_42 ) ; V_20 ++ ) {
if ( ! V_42 [ V_20 ] . V_46 )
continue;
V_35 -> V_46 [ V_39 ] = V_42 [ V_20 ] . V_46 ;
V_35 -> V_47 [ V_39 ] = V_42 [ V_20 ] . V_40 ;
V_35 -> V_48 [ V_39 ] =
F_17 ( V_42 [ V_20 ] . V_40 ,
L_4 , 0 ) ;
V_39 ++ ;
}
return V_35 ;
}
static struct V_32 * F_10 (
struct V_33 * V_34 )
{
return F_13 ( - V_41 ) ;
}
static T_1 F_18 ( int V_49 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
int V_50 , V_51 , V_7 = V_52 ;
V_51 = F_4 ( V_5 -> V_9 , V_53 , & V_50 ) ;
if ( V_51 < 0 )
goto V_54;
if ( V_50 & V_55 ) {
F_19 ( V_5 -> V_2 [ 0 ] ,
V_56 , NULL ) ;
V_51 = F_20 ( V_5 -> V_9 , V_53 ,
V_55 ) ;
if ( V_51 < 0 )
goto V_54;
V_7 = V_57 ;
}
if ( V_50 & V_58 ) {
F_19 ( V_5 -> V_2 [ 1 ] ,
V_56 , NULL ) ;
V_51 = F_20 ( V_5 -> V_9 , V_53 ,
V_58 ) ;
if ( V_51 < 0 )
goto V_54;
V_7 = V_57 ;
}
return V_7 ;
V_54:
F_12 ( V_5 -> V_34 , L_5 , V_51 ) ;
return V_52 ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_59 V_60 = { } ;
int V_20 , V_7 ;
unsigned int V_6 ;
V_7 = F_4 ( V_5 -> V_9 , V_61 , & V_6 ) ;
if ( V_7 < 0 ) {
F_12 ( V_5 -> V_34 , L_6 , V_7 ) ;
return V_7 ;
}
V_6 &= V_62 ;
if ( V_5 -> V_35 -> V_45 == 1 && V_6 == 0x00 )
V_5 -> V_63 = 1 ;
else if ( V_5 -> V_35 -> V_45 == 2 && V_6 != 0x00 )
V_5 -> V_63 = 2 ;
else {
F_12 ( V_5 -> V_34 , L_7 ) ;
return - V_30 ;
}
for ( V_20 = 0 ; V_20 < V_5 -> V_63 ; V_20 ++ ) {
V_60 . V_46 = V_5 -> V_35 -> V_46 [ V_20 ] ;
V_60 . V_34 = V_5 -> V_34 ;
V_60 . V_64 = V_5 ;
V_60 . V_9 = V_5 -> V_9 ;
V_60 . V_40 = V_5 -> V_35 -> V_47 [ V_20 ] ;
if ( F_22 ( V_5 -> V_35 -> V_48 [ V_20 ] ) ) {
V_60 . V_65 = V_5 -> V_35 -> V_48 [ V_20 ] ;
V_60 . V_66 = true ;
} else {
V_60 . V_65 = - V_30 ;
V_60 . V_66 = false ;
}
V_5 -> V_2 [ V_20 ] = F_23 ( V_5 -> V_34 ,
& V_67 [ V_20 ] , & V_60 ) ;
if ( F_24 ( V_5 -> V_2 [ V_20 ] ) ) {
F_12 ( V_5 -> V_34 ,
L_8 ) ;
return F_25 ( V_5 -> V_2 [ V_20 ] ) ;
}
if ( V_5 -> V_68 != 0 ) {
V_7 = F_6 ( V_5 -> V_9 ,
V_69 , V_70 << V_20 , 0 ) ;
if ( V_7 < 0 ) {
F_12 ( V_5 -> V_34 ,
L_9 , V_7 ) ;
return V_7 ;
}
}
}
return 0 ;
}
static int F_26 ( struct V_71 * V_72 ,
const struct V_73 * V_3 )
{
struct V_4 * V_5 ;
int error , V_7 ;
unsigned int V_6 ;
V_5 = F_16 ( & V_72 -> V_34 , sizeof( struct V_4 ) , V_43 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_34 = & V_72 -> V_34 ;
V_5 -> V_9 = F_27 ( V_72 , & V_74 ) ;
if ( F_24 ( V_5 -> V_9 ) ) {
error = F_25 ( V_5 -> V_9 ) ;
F_12 ( V_5 -> V_34 , L_10 ,
error ) ;
return error ;
}
F_28 ( V_72 , V_5 ) ;
V_5 -> V_35 = V_72 -> V_34 . V_75 ;
V_7 = F_4 ( V_5 -> V_9 , V_76 , & V_6 ) ;
if ( V_7 < 0 ) {
F_12 ( V_5 -> V_34 , L_11 , V_7 ) ;
return V_7 ;
}
switch ( V_6 ) {
case V_77 :
V_5 -> V_23 = V_24 ;
break;
case V_78 :
V_5 -> V_23 = V_26 ;
break;
case V_79 :
V_5 -> V_23 = V_28 ;
break;
default:
F_12 ( V_5 -> V_34 , L_12 , V_6 ) ;
return - V_41 ;
}
if ( ! V_5 -> V_35 )
V_5 -> V_35 = F_10 ( V_5 -> V_34 ) ;
if ( F_24 ( V_5 -> V_35 ) ) {
F_12 ( V_5 -> V_34 , L_13 ) ;
return F_25 ( V_5 -> V_35 ) ;
}
V_5 -> V_68 = V_72 -> V_49 ;
if ( V_5 -> V_68 != 0 ) {
V_7 = F_29 ( V_5 -> V_34 , V_5 -> V_68 , NULL ,
F_18 ,
V_80 | V_81 ,
L_14 , V_5 ) ;
if ( V_7 != 0 ) {
F_12 ( V_5 -> V_34 , L_15 ,
V_5 -> V_68 ) ;
return V_7 ;
}
} else {
F_30 ( V_5 -> V_34 , L_16 ) ;
}
V_7 = F_21 ( V_5 ) ;
if ( V_7 < 0 )
F_12 ( V_5 -> V_34 , L_17 , V_7 ) ;
return V_7 ;
}
