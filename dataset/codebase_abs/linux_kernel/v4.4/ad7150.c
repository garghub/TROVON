static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_11 :
V_8 = F_3 ( V_10 -> V_12 ,
V_13 [ V_4 -> V_14 ] [ 0 ] ) ;
if ( V_8 < 0 )
return V_8 ;
* V_5 = F_4 ( V_8 ) ;
return V_15 ;
case V_16 :
V_8 = F_3 ( V_10 -> V_12 ,
V_13 [ V_4 -> V_14 ] [ 1 ] ) ;
if ( V_8 < 0 )
return V_8 ;
* V_5 = F_4 ( V_8 ) ;
return V_15 ;
default:
return - V_17 ;
}
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , enum V_18 type ,
enum V_19 V_20 )
{
int V_8 ;
T_1 V_21 ;
bool V_22 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_8 = F_6 ( V_10 -> V_12 , V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
V_21 = ( V_8 >> 5 ) & 0x03 ;
V_22 = ! ! ( V_8 & 0x80 ) ;
switch ( type ) {
case V_24 :
if ( V_20 == V_25 )
return V_22 && ( V_21 == 0x1 ) ;
return V_22 && ( V_21 == 0x0 ) ;
case V_26 :
if ( V_20 == V_25 )
return V_22 && ( V_21 == 0x3 ) ;
return V_22 && ( V_21 == 0x2 ) ;
case V_27 :
if ( V_20 == V_25 )
return ! V_22 && ( V_21 == 0x1 ) ;
return ! V_22 && ( V_21 == 0x0 ) ;
default:
break;
}
return - V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_4 , enum V_18 type ,
enum V_19 V_20 )
{
int V_8 ;
T_2 V_28 ;
T_1 V_29 , V_30 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_31 = ( V_20 == V_25 ) ;
T_3 V_32 ;
V_32 = F_8 ( V_33 , V_4 , type , V_20 ) ;
if ( V_32 != V_10 -> V_34 )
return 0 ;
switch ( type ) {
case V_27 :
V_28 = V_10 -> V_35 [ V_31 ] [ V_4 ] ;
return F_9 ( V_10 -> V_12 ,
V_13 [ V_4 ] [ 3 ] ,
F_4 ( V_28 ) ) ;
case V_24 :
V_29 = V_10 -> V_36 [ V_31 ] [ V_4 ] ;
V_30 = V_10 -> V_37 [ V_31 ] [ V_4 ] ;
break;
case V_26 :
V_29 = V_10 -> V_38 [ V_31 ] [ V_4 ] ;
V_30 = V_10 -> V_39 [ V_31 ] [ V_4 ] ;
break;
default:
return - V_17 ;
}
V_8 = F_10 ( V_10 -> V_12 ,
V_13 [ V_4 ] [ 4 ] ,
V_29 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_10 ( V_10 -> V_12 ,
V_13 [ V_4 ] [ 5 ] ,
V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , enum V_18 type ,
enum V_19 V_20 , int V_40 )
{
T_1 V_41 , V_42 , V_22 ;
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_31 = ( V_20 == V_25 ) ;
T_3 V_32 ;
if ( ! V_40 )
return - V_17 ;
V_32 = F_8 ( V_4 -> type , V_4 -> V_14 , type , V_20 ) ;
if ( V_32 == V_10 -> V_34 )
return 0 ;
F_12 ( & V_10 -> V_43 ) ;
V_8 = F_6 ( V_10 -> V_12 , V_23 ) ;
if ( V_8 < 0 )
goto V_44;
V_42 = V_8 & ~ ( ( 0x03 << 5 ) | ( 0x1 << 7 ) ) ;
switch ( type ) {
case V_24 :
V_22 = 1 ;
if ( V_31 )
V_41 = 0x1 ;
else
V_41 = 0x0 ;
break;
case V_26 :
V_22 = 1 ;
if ( V_31 )
V_41 = 0x3 ;
else
V_41 = 0x2 ;
break;
case V_27 :
V_22 = 0 ;
if ( V_31 )
V_41 = 0x1 ;
else
V_41 = 0x0 ;
break;
default:
V_8 = - V_17 ;
goto V_44;
}
V_42 |= ( ! V_22 << 7 ) | ( V_41 << 5 ) ;
V_8 = F_10 ( V_10 -> V_12 , V_23 , V_42 ) ;
if ( V_8 < 0 )
goto V_44;
V_10 -> V_34 = V_32 ;
V_8 = F_7 ( V_2 , V_4 -> V_14 , type , V_20 ) ;
V_44:
F_13 ( & V_10 -> V_43 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_18 type ,
enum V_19 V_20 ,
enum V_45 V_46 ,
int * V_5 , int * V_6 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_31 = ( V_20 == V_25 ) ;
switch ( type ) {
case V_24 :
* V_5 = V_10 -> V_36 [ V_31 ] [ V_4 -> V_14 ] ;
return V_15 ;
case V_26 :
* V_5 = V_10 -> V_38 [ V_31 ] [ V_4 -> V_14 ] ;
return V_15 ;
case V_27 :
* V_5 = V_10 -> V_35 [ V_31 ] [ V_4 -> V_14 ] ;
return V_15 ;
default:
return - V_17 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_18 type ,
enum V_19 V_20 ,
enum V_45 V_46 ,
int V_5 , int V_6 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_31 = ( V_20 == V_25 ) ;
F_12 ( & V_10 -> V_43 ) ;
switch ( type ) {
case V_24 :
V_10 -> V_36 [ V_31 ] [ V_4 -> V_14 ] = V_5 ;
break;
case V_26 :
V_10 -> V_38 [ V_31 ] [ V_4 -> V_14 ] = V_5 ;
break;
case V_27 :
V_10 -> V_35 [ V_31 ] [ V_4 -> V_14 ] = V_5 ;
break;
default:
V_8 = - V_17 ;
goto V_44;
}
V_8 = F_7 ( V_2 , V_4 -> V_14 , type , V_20 ) ;
V_44:
F_13 ( & V_10 -> V_43 ) ;
return V_8 ;
}
static T_4 F_16 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
char * V_51 )
{
struct V_1 * V_2 = F_17 ( V_48 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_52 * V_53 = F_18 ( V_50 ) ;
T_1 V_28 ;
int V_4 = F_19 ( V_53 -> V_54 ) ;
int V_31 = ! ! ( F_20 ( V_53 -> V_54 )
== V_25 ) ;
switch ( F_21 ( V_53 -> V_54 ) ) {
case V_24 :
V_28 = V_10 -> V_37 [ V_31 ] [ V_4 ] ;
break;
case V_26 :
V_28 = V_10 -> V_39 [ V_31 ] [ V_4 ] ;
break;
default:
return - V_17 ;
}
return sprintf ( V_51 , L_1 , V_28 ) ;
}
static T_4 F_22 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
const char * V_51 ,
T_5 V_55 )
{
struct V_1 * V_2 = F_17 ( V_48 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_52 * V_53 = F_18 ( V_50 ) ;
int V_4 = F_19 ( V_53 -> V_54 ) ;
enum V_19 V_20 ;
enum V_18 type ;
int V_31 ;
T_1 V_56 ;
int V_8 ;
type = F_21 ( V_53 -> V_54 ) ;
V_20 = F_20 ( V_53 -> V_54 ) ;
V_31 = ( V_20 == V_25 ) ;
V_8 = F_23 ( V_51 , 10 , & V_56 ) ;
if ( V_8 < 0 )
return V_8 ;
F_12 ( & V_10 -> V_43 ) ;
switch ( type ) {
case V_24 :
V_10 -> V_37 [ V_31 ] [ V_4 ] = V_56 ;
break;
case V_26 :
V_10 -> V_39 [ V_31 ] [ V_4 ] = V_56 ;
break;
default:
V_8 = - V_17 ;
goto V_44;
}
V_8 = F_7 ( V_2 , V_4 , type , V_20 ) ;
V_44:
F_13 ( & V_10 -> V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_55 ;
}
static T_6 F_24 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_59 ;
T_7 V_60 = F_25 () ;
int V_8 ;
V_8 = F_6 ( V_10 -> V_12 , V_61 ) ;
if ( V_8 < 0 )
return V_62 ;
V_59 = V_8 ;
if ( ( V_59 & V_63 ) &&
! ( V_10 -> V_64 & V_63 ) )
F_26 ( V_2 ,
F_8 ( V_33 ,
0 ,
V_27 ,
V_25 ) ,
V_60 ) ;
else if ( ( ! ( V_59 & V_63 ) ) &&
( V_10 -> V_64 & V_63 ) )
F_26 ( V_2 ,
F_8 ( V_33 ,
0 ,
V_27 ,
V_65 ) ,
V_60 ) ;
if ( ( V_59 & V_66 ) &&
! ( V_10 -> V_64 & V_66 ) )
F_26 ( V_2 ,
F_8 ( V_33 ,
1 ,
V_27 ,
V_25 ) ,
V_60 ) ;
else if ( ( ! ( V_59 & V_66 ) ) &&
( V_10 -> V_64 & V_66 ) )
F_26 ( V_2 ,
F_8 ( V_33 ,
1 ,
V_27 ,
V_65 ) ,
V_60 ) ;
V_10 -> V_64 = V_59 ;
return V_62 ;
}
static int F_27 ( struct V_67 * V_12 ,
const struct V_68 * V_69 )
{
int V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_28 ( & V_12 -> V_48 , sizeof( * V_10 ) ) ;
if ( ! V_2 )
return - V_70 ;
V_10 = F_2 ( V_2 ) ;
F_29 ( & V_10 -> V_43 ) ;
F_30 ( V_12 , V_2 ) ;
V_10 -> V_12 = V_12 ;
V_2 -> V_71 = V_69 -> V_71 ;
V_2 -> V_72 = V_73 ;
V_2 -> V_74 = F_31 ( V_73 ) ;
V_2 -> V_48 . V_75 = & V_12 -> V_48 ;
V_2 -> V_46 = & V_76 ;
V_2 -> V_77 = V_78 ;
if ( V_12 -> V_57 ) {
V_8 = F_32 ( & V_12 -> V_48 , V_12 -> V_57 ,
NULL ,
& F_24 ,
V_79 |
V_80 |
V_81 ,
L_2 ,
V_2 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_12 -> V_48 . V_82 ) {
V_8 = F_32 ( & V_12 -> V_48 , * ( unsigned int * )
V_12 -> V_48 . V_82 ,
NULL ,
& F_24 ,
V_79 |
V_80 |
V_81 ,
L_3 ,
V_2 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_33 ( V_2 -> V_48 . V_75 , V_2 ) ;
if ( V_8 )
return V_8 ;
F_34 ( & V_12 -> V_48 , L_4 ,
V_69 -> V_71 , V_12 -> V_57 ) ;
return 0 ;
}
