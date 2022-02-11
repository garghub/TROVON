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
default:
return - V_28 ;
}
for ( V_20 = V_21 ; V_20 >= 0 ; V_20 -- ) {
if ( V_18 <= V_22 [ V_20 ] &&
V_19 >= V_22 [ V_20 ] ) {
return F_6 ( V_5 -> V_9 ,
V_29 ,
( 0x0F << V_3 * 4 ) , ( V_20 << V_3 * 4 ) ) ;
}
}
return - V_28 ;
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
default:
return - V_28 ;
}
V_7 = F_4 ( V_5 -> V_9 , V_29 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = ( V_6 >> V_3 * 4 ) & 0x0F ;
return V_22 [ V_6 ] ;
}
static struct V_30 * F_10 (
struct V_31 * V_32 )
{
struct V_30 * V_33 ;
struct V_34 * V_35 ;
int V_20 , V_36 , V_37 ;
V_35 = F_11 ( V_32 -> V_38 , L_1 ) ;
if ( ! V_35 ) {
F_12 ( V_32 , L_2 ) ;
return F_13 ( - V_39 ) ;
}
V_36 = F_14 ( V_32 , V_35 , V_40 ,
F_8 ( V_40 ) ) ;
F_15 ( V_35 ) ;
if ( V_36 < 0 ) {
F_12 ( V_32 , L_3 ) ;
return F_13 ( - V_28 ) ;
}
V_33 = F_16 ( V_32 , sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
return F_13 ( - V_42 ) ;
V_33 -> V_43 = V_36 ;
V_37 = 0 ;
for ( V_20 = 0 ; V_20 < F_8 ( V_40 ) ; V_20 ++ ) {
if ( ! V_40 [ V_20 ] . V_44 )
continue;
V_33 -> V_44 [ V_37 ] = V_40 [ V_20 ] . V_44 ;
V_37 ++ ;
}
return V_33 ;
}
static struct V_30 * F_10 (
struct V_31 * V_32 )
{
return F_13 ( - V_39 ) ;
}
static T_1 F_17 ( int V_45 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
int V_46 , V_47 , V_7 = V_48 ;
V_47 = F_4 ( V_5 -> V_9 , V_49 , & V_46 ) ;
if ( V_47 < 0 )
goto V_50;
if ( V_46 & V_51 ) {
F_18 ( V_5 -> V_2 [ 0 ] ,
V_52 ,
F_3 ( V_5 -> V_2 [ 0 ] ) ) ;
V_47 = F_19 ( V_5 -> V_9 , V_49 ,
V_51 ) ;
if ( V_47 < 0 )
goto V_50;
V_7 = V_53 ;
}
if ( V_46 & V_54 ) {
F_18 ( V_5 -> V_2 [ 1 ] ,
V_52 ,
F_3 ( V_5 -> V_2 [ 1 ] ) ) ;
V_47 = F_19 ( V_5 -> V_9 , V_49 ,
V_54 ) ;
if ( V_47 < 0 )
goto V_50;
V_7 = V_53 ;
}
return V_7 ;
V_50:
F_12 ( V_5 -> V_32 , L_4 , V_47 ) ;
return V_48 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_55 V_56 = { } ;
int V_20 , V_7 ;
unsigned int V_6 ;
V_7 = F_4 ( V_5 -> V_9 , V_57 , & V_6 ) ;
if ( V_7 < 0 ) {
F_12 ( V_5 -> V_32 , L_5 , V_7 ) ;
return V_7 ;
}
V_6 &= V_58 ;
if ( ( V_5 -> V_33 -> V_43 == 2 && V_6 == 0x40 )
|| ( V_5 -> V_33 -> V_43 == 1 && V_6 == 0x00 ) ) {
if ( V_6 == 0 )
V_5 -> V_59 = 1 ;
else
V_5 -> V_59 = 2 ;
} else {
F_12 ( V_5 -> V_32 , L_6 ) ;
return - V_28 ;
}
for ( V_20 = 0 ; V_20 < V_5 -> V_59 ; V_20 ++ ) {
V_56 . V_44 = V_5 -> V_33 -> V_44 [ V_20 ] ;
V_56 . V_32 = V_5 -> V_32 ;
V_56 . V_60 = V_5 ;
V_56 . V_9 = V_5 -> V_9 ;
V_56 . V_38 = V_5 -> V_32 -> V_38 ;
V_5 -> V_2 [ V_20 ] = F_21 ( V_5 -> V_32 ,
& V_61 [ V_20 ] , & V_56 ) ;
if ( F_22 ( V_5 -> V_2 [ V_20 ] ) ) {
F_12 ( V_5 -> V_32 ,
L_7 ) ;
return F_23 ( V_5 -> V_2 [ V_20 ] ) ;
}
if ( V_5 -> V_62 != 0 ) {
V_7 = F_6 ( V_5 -> V_9 ,
V_63 , V_64 << V_20 , 0 ) ;
if ( V_7 < 0 ) {
F_12 ( V_5 -> V_32 ,
L_8 , V_7 ) ;
return V_7 ;
}
}
}
return 0 ;
}
static int F_24 ( struct V_65 * V_66 ,
const struct V_67 * V_3 )
{
struct V_4 * V_5 ;
int error , V_7 ;
unsigned int V_6 ;
V_5 = F_16 ( & V_66 -> V_32 , sizeof( struct V_4 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
V_5 -> V_32 = & V_66 -> V_32 ;
V_5 -> V_9 = F_25 ( V_66 , & V_68 ) ;
if ( F_22 ( V_5 -> V_9 ) ) {
error = F_23 ( V_5 -> V_9 ) ;
F_12 ( V_5 -> V_32 , L_9 ,
error ) ;
return error ;
}
F_26 ( V_66 , V_5 ) ;
V_5 -> V_33 = V_66 -> V_32 . V_69 ;
V_7 = F_4 ( V_5 -> V_9 , V_70 , & V_6 ) ;
if ( V_7 < 0 ) {
F_12 ( V_5 -> V_32 , L_10 , V_7 ) ;
return V_7 ;
}
switch ( V_6 ) {
case V_71 :
V_5 -> V_23 = V_24 ;
break;
case V_72 :
V_5 -> V_23 = V_26 ;
break;
default:
F_12 ( V_5 -> V_32 , L_11 , V_6 ) ;
return - V_39 ;
}
if ( ! V_5 -> V_33 )
V_5 -> V_33 = F_10 ( V_5 -> V_32 ) ;
if ( F_22 ( V_5 -> V_33 ) ) {
F_12 ( V_5 -> V_32 , L_12 ) ;
return F_23 ( V_5 -> V_33 ) ;
}
V_5 -> V_62 = V_66 -> V_45 ;
if ( V_5 -> V_62 != 0 ) {
V_7 = F_27 ( V_5 -> V_32 , V_5 -> V_62 , NULL ,
F_17 ,
V_73 | V_74 ,
L_13 , V_5 ) ;
if ( V_7 != 0 ) {
F_12 ( V_5 -> V_32 , L_14 ,
V_5 -> V_62 ) ;
return V_7 ;
}
} else {
F_28 ( V_5 -> V_32 , L_15 ) ;
}
V_7 = F_20 ( V_5 ) ;
if ( V_7 < 0 )
F_12 ( V_5 -> V_32 , L_16 , V_7 ) ;
return V_7 ;
}
