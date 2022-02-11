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
static int F_5 ( struct V_1 * V_2 , T_1 V_18 )
{
int V_8 ;
T_2 V_19 ;
bool V_20 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_21 = ! ! ( F_6 ( V_18 ) ==
V_22 ) ;
V_8 = F_7 ( V_10 -> V_12 , V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
V_19 = ( V_8 >> 5 ) & 0x03 ;
V_20 = ! ! ( V_8 & 0x80 ) ;
switch ( F_8 ( V_18 ) ) {
case V_24 :
if ( V_21 )
return V_20 && ( V_19 == 0x1 ) ;
else
return V_20 && ( V_19 == 0x0 ) ;
case V_25 :
if ( V_21 )
return V_20 && ( V_19 == 0x3 ) ;
else
return V_20 && ( V_19 == 0x2 ) ;
case V_26 :
if ( V_21 )
return ! V_20 && ( V_19 == 0x1 ) ;
else
return ! V_20 && ( V_19 == 0x0 ) ;
} ;
return - V_17 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_18 )
{
int V_8 ;
T_3 V_27 ;
T_2 V_28 , V_29 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_4 = F_10 ( V_18 ) ;
int V_21 = ! ! ( F_6 ( V_18 ) ==
V_22 ) ;
if ( V_18 != V_10 -> V_30 )
return 0 ;
switch ( F_8 ( V_18 ) ) {
case V_26 :
V_27 = V_10 -> V_31 [ V_21 ] [ V_4 ] ;
V_8 = F_11 ( V_10 -> V_12 ,
V_13 [ V_4 ] [ 3 ] ,
F_4 ( V_27 ) ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
case V_24 :
V_28 = V_10 -> V_32 [ V_21 ] [ V_4 ] ;
V_29 = V_10 -> V_33 [ V_21 ] [ V_4 ] ;
break;
case V_25 :
V_28 = V_10 -> V_34 [ V_21 ] [ V_4 ] ;
V_29 = V_10 -> V_35 [ V_21 ] [ V_4 ] ;
break;
default:
return - V_17 ;
} ;
V_8 = F_12 ( V_10 -> V_12 ,
V_13 [ V_4 ] [ 4 ] ,
V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_10 -> V_12 ,
V_13 [ V_4 ] [ 5 ] ,
V_29 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_18 , int V_36 )
{
T_2 V_37 , V_38 , V_20 ;
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_21 = ! ! ( F_6 ( V_18 ) ==
V_22 ) ;
if ( V_36 == 0 )
return - V_17 ;
if ( V_18 == V_10 -> V_30 )
return 0 ;
F_14 ( & V_10 -> V_39 ) ;
V_8 = F_7 ( V_10 -> V_12 , V_23 ) ;
if ( V_8 < 0 )
goto V_40;
V_38 = V_8 & ~ ( ( 0x03 << 5 ) | ( 0x1 << 7 ) ) ;
switch ( F_8 ( V_18 ) ) {
case V_24 :
V_20 = 1 ;
if ( V_21 )
V_37 = 0x1 ;
else
V_37 = 0x0 ;
break;
case V_25 :
V_20 = 1 ;
if ( V_21 )
V_37 = 0x3 ;
else
V_37 = 0x2 ;
break;
case V_26 :
V_20 = 0 ;
if ( V_21 )
V_37 = 0x1 ;
else
V_37 = 0x0 ;
break;
default:
V_8 = - V_17 ;
goto V_40;
} ;
V_38 |= ( ! V_20 << 7 ) | ( V_37 << 5 ) ;
V_8 = F_12 ( V_10 -> V_12 , V_23 , V_38 ) ;
if ( V_8 < 0 )
goto V_40;
V_10 -> V_30 = V_18 ;
V_8 = F_9 ( V_2 , V_18 ) ;
V_40:
F_15 ( & V_10 -> V_39 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_18 ,
int * V_5 )
{
int V_4 = F_10 ( V_18 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_21 = ! ! ( F_6 ( V_18 ) ==
V_22 ) ;
switch ( F_8 ( V_18 ) ) {
case V_24 :
* V_5 = V_10 -> V_32 [ V_21 ] [ V_4 ] ;
return 0 ;
case V_25 :
* V_5 = V_10 -> V_34 [ V_21 ] [ V_4 ] ;
return 0 ;
case V_26 :
* V_5 = V_10 -> V_31 [ V_21 ] [ V_4 ] ;
return 0 ;
default:
return - V_17 ;
} ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 V_18 ,
int V_5 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_4 = F_10 ( V_18 ) ;
int V_21 = ! ! ( F_6 ( V_18 ) ==
V_22 ) ;
F_14 ( & V_10 -> V_39 ) ;
switch ( F_8 ( V_18 ) ) {
case V_24 :
V_10 -> V_32 [ V_21 ] [ V_4 ] = V_5 ;
break;
case V_25 :
V_10 -> V_34 [ V_21 ] [ V_4 ] = V_5 ;
break;
case V_26 :
V_10 -> V_31 [ V_21 ] [ V_4 ] = V_5 ;
break;
default:
V_8 = - V_17 ;
goto V_40;
} ;
V_8 = F_9 ( V_2 , V_18 ) ;
V_40:
F_15 ( & V_10 -> V_39 ) ;
return V_8 ;
}
static T_4 F_18 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_46 * V_47 = F_20 ( V_44 ) ;
T_2 V_27 ;
int V_4 = F_10 ( V_47 -> V_48 ) ;
int V_21 = ! ! ( F_6 ( V_47 -> V_48 )
== V_22 ) ;
switch ( F_8 ( V_47 -> V_48 ) ) {
case V_24 :
V_27 = V_10 -> V_33 [ V_21 ] [ V_4 ] ;
break;
case V_25 :
V_27 = V_10 -> V_35 [ V_21 ] [ V_4 ] ;
break;
default:
return - V_17 ;
} ;
return sprintf ( V_45 , L_1 , V_27 ) ;
}
static T_4 F_21 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_5 V_49 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_46 * V_47 = F_20 ( V_44 ) ;
int V_4 = F_10 ( V_47 -> V_48 ) ;
int V_21 = ! ! ( F_6 ( V_47 -> V_48 ) ==
V_22 ) ;
T_2 V_50 ;
int V_8 ;
V_8 = F_22 ( V_45 , 10 , & V_50 ) ;
if ( V_8 < 0 )
return V_8 ;
F_14 ( & V_10 -> V_39 ) ;
switch ( F_8 ( V_47 -> V_48 ) ) {
case V_24 :
V_10 -> V_33 [ V_21 ] [ V_4 ] = V_50 ;
break;
case V_25 :
V_10 -> V_35 [ V_21 ] [ V_4 ] = V_50 ;
break;
default:
V_8 = - V_17 ;
goto V_40;
} ;
V_8 = F_9 ( V_2 , V_47 -> V_48 ) ;
V_40:
F_15 ( & V_10 -> V_39 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_49 ;
}
static T_6 F_23 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_2 V_53 ;
T_7 V_54 = F_24 () ;
int V_8 ;
V_8 = F_7 ( V_10 -> V_12 , V_55 ) ;
if ( V_8 < 0 )
return V_56 ;
V_53 = V_8 ;
if ( ( V_53 & V_57 ) &&
! ( V_10 -> V_58 & V_57 ) )
F_25 ( V_2 ,
F_26 ( V_59 ,
0 ,
V_26 ,
V_22 ) ,
V_54 ) ;
else if ( ( ! ( V_53 & V_57 ) ) &&
( V_10 -> V_58 & V_57 ) )
F_25 ( V_2 ,
F_26 ( V_59 ,
0 ,
V_26 ,
V_60 ) ,
V_54 ) ;
if ( ( V_53 & V_61 ) &&
! ( V_10 -> V_58 & V_61 ) )
F_25 ( V_2 ,
F_26 ( V_59 ,
1 ,
V_26 ,
V_22 ) ,
V_54 ) ;
else if ( ( ! ( V_53 & V_61 ) ) &&
( V_10 -> V_58 & V_61 ) )
F_25 ( V_2 ,
F_26 ( V_59 ,
1 ,
V_26 ,
V_60 ) ,
V_54 ) ;
V_10 -> V_58 = V_53 ;
return V_56 ;
}
static int T_8 F_27 ( struct V_62 * V_12 ,
const struct V_63 * V_64 )
{
int V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_28 ( sizeof( * V_10 ) ) ;
if ( V_2 == NULL ) {
V_8 = - V_65 ;
goto V_40;
}
V_10 = F_2 ( V_2 ) ;
F_29 ( & V_10 -> V_39 ) ;
F_30 ( V_12 , V_2 ) ;
V_10 -> V_12 = V_12 ;
V_2 -> V_66 = V_64 -> V_66 ;
V_2 -> V_67 = V_68 ;
V_2 -> V_69 = F_31 ( V_68 ) ;
V_2 -> V_42 . V_70 = & V_12 -> V_42 ;
V_2 -> V_71 = & V_72 ;
V_2 -> V_73 = V_74 ;
if ( V_12 -> V_51 ) {
V_8 = F_32 ( V_12 -> V_51 ,
NULL ,
& F_23 ,
V_75 |
V_76 ,
L_2 ,
V_2 ) ;
if ( V_8 )
goto V_77;
}
if ( V_12 -> V_42 . V_78 ) {
V_8 = F_32 ( * ( unsigned int * )
V_12 -> V_42 . V_78 ,
NULL ,
& F_23 ,
V_75 |
V_76 ,
L_3 ,
V_2 ) ;
if ( V_8 )
goto V_79;
}
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
goto V_80;
F_34 ( & V_12 -> V_42 , L_4 ,
V_64 -> V_66 , V_12 -> V_51 ) ;
return 0 ;
V_80:
if ( V_12 -> V_42 . V_78 )
F_35 ( * ( unsigned int * ) V_12 -> V_42 . V_78 ,
V_2 ) ;
V_79:
if ( V_12 -> V_51 )
F_35 ( V_12 -> V_51 , V_2 ) ;
V_77:
F_36 ( V_2 ) ;
V_40:
return V_8 ;
}
static int T_9 F_37 ( struct V_62 * V_12 )
{
struct V_1 * V_2 = F_38 ( V_12 ) ;
F_39 ( V_2 ) ;
if ( V_12 -> V_51 )
F_35 ( V_12 -> V_51 , V_2 ) ;
if ( V_12 -> V_42 . V_78 )
F_35 ( * ( unsigned int * ) V_12 -> V_42 . V_78 , V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
