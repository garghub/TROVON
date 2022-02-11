static int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 ,
T_2 V_5 )
{
T_3 V_6 = F_2 ( V_3 ) ;
struct V_7 V_8 [ 2 ] = {
{ . V_9 = V_2 -> V_9 , . V_5 = sizeof( V_6 ) , . V_10 = ( T_2 * ) & V_6 } ,
{ . V_9 = V_2 -> V_9 , . V_5 = V_5 , . V_10 = V_4 ,
. V_11 = V_12 } } ;
int V_13 ;
V_13 = F_3 ( V_2 -> V_14 , V_8 , F_4 ( V_8 ) ) ;
if ( V_13 < 0 )
F_5 ( & V_2 -> V_15 , L_1 , V_3 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_16 ;
int V_13 ;
V_13 = F_1 ( V_2 , V_3 , & V_16 , sizeof( V_16 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return V_16 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_3 V_16 ;
int V_13 ;
V_13 = F_1 ( V_2 , V_3 , & V_16 , sizeof( V_16 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_17 )
{
T_2 V_10 [ 3 ] ;
struct V_7 V_8 [ 1 ] = {
{ . V_9 = V_2 -> V_9 , . V_5 = sizeof( V_10 ) , . V_10 = ( T_2 * ) & V_10 } } ;
int V_13 ;
V_10 [ 0 ] = V_3 >> 8 ;
V_10 [ 1 ] = V_3 & 0xff ;
V_10 [ 2 ] = V_17 ;
V_13 = F_3 ( V_2 -> V_14 , V_8 , F_4 ( V_8 ) ) ;
if ( V_13 < 0 ) {
F_5 ( & V_2 -> V_15 , L_2 , V_3 ) ;
return V_13 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 )
{
T_3 V_10 [ 2 ] ;
struct V_7 V_8 [ 1 ] = {
{ . V_9 = V_2 -> V_9 , . V_5 = sizeof( V_10 ) , . V_10 = ( T_2 * ) & V_10 } } ;
int V_13 ;
V_10 [ 0 ] = F_2 ( V_3 ) ;
V_10 [ 1 ] = F_2 ( V_17 ) ;
V_13 = F_3 ( V_2 -> V_14 , V_8 , F_4 ( V_8 ) ) ;
if ( V_13 < 0 ) {
F_5 ( & V_2 -> V_15 , L_2 , V_3 ) ;
return V_13 ;
}
return 0 ;
}
static int F_11 ( struct V_18 * V_16 , int V_9 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
int V_19 = 20 , V_13 ;
T_1 V_20 ;
F_12 ( & V_16 -> V_21 ) ;
V_13 = F_9 ( V_2 ,
V_22 [ V_9 ] . V_23 , V_24 ) ;
if ( V_13 < 0 )
goto V_25;
while ( V_19 -- ) {
V_13 = F_6 ( V_2 , V_26 ) ;
if ( V_13 < 0 )
goto V_25;
if ( V_13 & V_22 [ V_9 ] . V_27 )
break;
F_13 ( 20 ) ;
}
if ( V_19 < 0 ) {
V_13 = - V_28 ;
goto V_25;
}
V_13 = V_22 [ V_9 ] . V_29 ?
F_7 ( V_2 , V_22 [ V_9 ] . V_30 ) :
F_6 ( V_2 , V_22 [ V_9 ] . V_30 ) ;
if ( V_13 < 0 )
goto V_25;
V_20 = V_13 ;
V_13 = F_9 ( V_2 , V_31 ,
V_32 | V_33 | V_34 ) ;
if ( V_13 < 0 )
goto V_25;
V_13 = V_20 ;
V_25:
F_14 ( & V_16 -> V_21 ) ;
return V_13 ;
}
static int F_15 ( struct V_35 * V_36 ,
struct V_37 const * V_38 ,
int * V_17 , int * V_39 , long V_40 )
{
struct V_18 * V_16 = F_16 ( V_36 ) ;
int V_13 , V_41 ;
switch ( V_40 ) {
case V_42 :
V_13 = F_11 ( V_16 , V_38 -> V_43 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_17 = V_13 ;
return V_44 ;
case V_45 :
V_13 = F_7 ( V_16 -> V_2 , V_46 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_17 = 0 ;
* V_39 = ( V_13 + 1 ) * 1000 ;
return V_47 ;
case V_48 :
switch ( V_38 -> type ) {
case V_49 :
* V_17 = 0 ;
* V_39 = 320000 ;
break;
case V_50 :
* V_17 = 0 ;
* V_39 = 1000 ;
break;
default:
return - V_51 ;
}
return V_47 ;
case V_52 :
V_13 = F_6 ( V_16 -> V_2 , V_53 ) ;
if ( V_13 < 0 )
return - V_51 ;
for ( V_41 = 0 ; V_41 < F_4 ( V_54 ) ; V_41 ++ ) {
if ( V_13 == V_54 [ V_41 ] [ 2 ] ) {
* V_17 = V_54 [ V_41 ] [ 0 ] ;
* V_39 = V_54 [ V_41 ] [ 1 ] ;
}
}
return V_47 ;
default:
return - V_51 ;
}
}
static int F_17 ( struct V_18 * V_16 , bool V_55 )
{
return F_9 ( V_16 -> V_2 , V_56 ,
V_55 ? V_57 : 0 ) ;
}
static int F_18 ( struct V_18 * V_16 , int V_17 , int V_39 )
{
int V_41 , V_13 ;
for ( V_41 = 0 ; V_41 < F_4 ( V_54 ) ; V_41 ++ ) {
if ( V_17 == V_54 [ V_41 ] [ 0 ] &&
V_39 == V_54 [ V_41 ] [ 1 ] ) {
F_12 ( & V_16 -> V_21 ) ;
V_13 = F_17 ( V_16 , true ) ;
if ( V_13 < 0 )
goto V_25;
V_13 = F_9 ( V_16 -> V_2 , V_53 ,
V_54 [ V_41 ] [ 3 ] ) ;
V_25:
F_17 ( V_16 , false ) ;
F_14 ( & V_16 -> V_21 ) ;
return V_13 ;
}
}
return - V_51 ;
}
static int F_19 ( struct V_18 * V_16 , int V_39 )
{
int V_13 ;
F_12 ( & V_16 -> V_21 ) ;
V_13 = F_17 ( V_16 , true ) ;
if ( V_13 < 0 )
goto V_25;
V_13 = F_10 ( V_16 -> V_2 , V_46 ,
( V_39 - 500 ) / 1000 ) ;
V_25:
F_17 ( V_16 , false ) ;
F_14 ( & V_16 -> V_21 ) ;
return V_13 ;
}
static int F_20 ( struct V_35 * V_36 ,
struct V_37 const * V_38 ,
int V_17 , int V_39 , long V_40 )
{
struct V_18 * V_16 = F_16 ( V_36 ) ;
switch ( V_40 ) {
case V_45 :
if ( V_17 != 0 || V_39 < 500 || V_39 >= 512500 )
return - V_51 ;
return F_19 ( V_16 , V_39 ) ;
case V_52 :
if ( V_38 -> type != V_49 )
return - V_51 ;
return F_18 ( V_16 , V_17 , V_39 ) ;
default:
return - V_51 ;
}
}
static int F_21 ( struct V_18 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
int V_13 ;
V_13 = F_6 ( V_2 , V_58 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 != V_59 ) {
F_5 ( & V_2 -> V_15 , L_3 , V_13 ) ;
return - V_60 ;
}
V_13 = F_17 ( V_16 , true ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_2 , V_61 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 != 0x01 )
F_22 ( & V_2 -> V_15 , L_4 ) ;
V_13 = F_9 ( V_2 , V_62 ,
V_63 | V_64 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_10 ( V_2 , V_46 , V_65 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_2 , V_53 , V_66 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_2 , V_61 , 0x00 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_17 ( V_16 , false ) ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_18 * V_16 ;
struct V_35 * V_36 ;
int V_13 ;
V_36 = F_24 ( & V_2 -> V_15 , sizeof( * V_16 ) ) ;
if ( ! V_36 )
return - V_69 ;
V_16 = F_16 ( V_36 ) ;
F_25 ( V_2 , V_36 ) ;
V_16 -> V_2 = V_2 ;
F_26 ( & V_16 -> V_21 ) ;
V_36 -> V_15 . V_70 = & V_2 -> V_15 ;
V_36 -> V_71 = & V_72 ;
V_36 -> V_73 = V_74 ;
V_36 -> V_75 = F_4 ( V_74 ) ;
V_36 -> V_76 = V_77 ;
V_36 -> V_78 = V_79 ;
V_13 = F_21 ( V_16 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_27 ( & V_2 -> V_15 , V_36 ) ;
}
