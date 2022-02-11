static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case 0 :
V_8 = F_3 ( V_10 -> V_11 ,
V_12 [ V_4 -> V_13 ] [ 0 ] ) ;
if ( V_8 < 0 )
return V_8 ;
* V_5 = F_4 ( V_8 ) ;
return V_14 ;
case ( 1 << V_15 ) :
V_8 = F_3 ( V_10 -> V_11 ,
V_12 [ V_4 -> V_13 ] [ 1 ] ) ;
if ( V_8 < 0 )
return V_8 ;
* V_5 = F_4 ( V_8 ) ;
return V_14 ;
default:
return - V_16 ;
}
}
static int F_5 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_8 ;
T_2 V_18 ;
bool V_19 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_20 = ! ! ( F_6 ( V_17 ) ==
V_21 ) ;
V_8 = F_7 ( V_10 -> V_11 , V_22 ) ;
if ( V_8 < 0 )
return V_8 ;
V_18 = ( V_8 >> 5 ) & 0x03 ;
V_19 = ! ! ( V_8 & 0x80 ) ;
switch ( F_8 ( V_17 ) ) {
case V_23 :
if ( V_20 )
return V_19 && ( V_18 == 0x1 ) ;
else
return V_19 && ( V_18 == 0x0 ) ;
case V_24 :
if ( V_20 )
return V_19 && ( V_18 == 0x3 ) ;
else
return V_19 && ( V_18 == 0x2 ) ;
case V_25 :
if ( V_20 )
return ! V_19 && ( V_18 == 0x1 ) ;
else
return ! V_19 && ( V_18 == 0x0 ) ;
} ;
return - V_16 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
int V_8 ;
T_3 V_26 ;
T_2 V_27 , V_28 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_4 = F_10 ( V_17 ) ;
int V_20 = ! ! ( F_6 ( V_17 ) ==
V_21 ) ;
if ( V_17 != V_10 -> V_29 )
return 0 ;
switch ( F_8 ( V_17 ) ) {
case V_25 :
V_26 = V_10 -> V_30 [ V_20 ] [ V_4 ] ;
V_8 = F_11 ( V_10 -> V_11 ,
V_12 [ V_4 ] [ 3 ] ,
F_4 ( V_26 ) ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
case V_23 :
V_27 = V_10 -> V_31 [ V_20 ] [ V_4 ] ;
V_28 = V_10 -> V_32 [ V_20 ] [ V_4 ] ;
break;
case V_24 :
V_27 = V_10 -> V_33 [ V_20 ] [ V_4 ] ;
V_28 = V_10 -> V_34 [ V_20 ] [ V_4 ] ;
break;
default:
return - V_16 ;
} ;
V_8 = F_12 ( V_10 -> V_11 ,
V_12 [ V_4 ] [ 4 ] ,
V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_10 -> V_11 ,
V_12 [ V_4 ] [ 5 ] ,
V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_17 , int V_35 )
{
T_2 V_36 , V_37 , V_19 ;
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_20 = ! ! ( F_6 ( V_17 ) ==
V_21 ) ;
if ( V_35 == 0 )
return - V_16 ;
if ( V_17 == V_10 -> V_29 )
return 0 ;
F_14 ( & V_10 -> V_38 ) ;
V_8 = F_7 ( V_10 -> V_11 , V_22 ) ;
if ( V_8 < 0 )
goto V_39;
V_37 = V_8 & ~ ( ( 0x03 << 5 ) | ( 0x1 << 7 ) ) ;
switch ( F_8 ( V_17 ) ) {
case V_23 :
V_19 = 1 ;
if ( V_20 )
V_36 = 0x1 ;
else
V_36 = 0x0 ;
break;
case V_24 :
V_19 = 1 ;
if ( V_20 )
V_36 = 0x3 ;
else
V_36 = 0x2 ;
break;
case V_25 :
V_19 = 0 ;
if ( V_20 )
V_36 = 0x1 ;
else
V_36 = 0x0 ;
break;
default:
V_8 = - V_16 ;
goto V_39;
} ;
V_37 |= ( ! V_19 << 7 ) | ( V_36 << 5 ) ;
V_8 = F_12 ( V_10 -> V_11 , V_22 , V_37 ) ;
if ( V_8 < 0 )
goto V_39;
V_10 -> V_29 = V_17 ;
V_8 = F_9 ( V_2 , V_17 ) ;
V_39:
F_15 ( & V_10 -> V_38 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_17 ,
int * V_5 )
{
int V_4 = F_10 ( V_17 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_20 = ! ! ( F_6 ( V_17 ) ==
V_21 ) ;
switch ( F_8 ( V_17 ) ) {
case V_23 :
* V_5 = V_10 -> V_31 [ V_20 ] [ V_4 ] ;
return 0 ;
case V_24 :
* V_5 = V_10 -> V_33 [ V_20 ] [ V_4 ] ;
return 0 ;
case V_25 :
* V_5 = V_10 -> V_30 [ V_20 ] [ V_4 ] ;
return 0 ;
default:
return - V_16 ;
} ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 V_17 ,
int V_5 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_4 = F_10 ( V_17 ) ;
int V_20 = ! ! ( F_6 ( V_17 ) ==
V_21 ) ;
F_14 ( & V_10 -> V_38 ) ;
switch ( F_8 ( V_17 ) ) {
case V_23 :
V_10 -> V_31 [ V_20 ] [ V_4 ] = V_5 ;
break;
case V_24 :
V_10 -> V_33 [ V_20 ] [ V_4 ] = V_5 ;
break;
case V_25 :
V_10 -> V_30 [ V_20 ] [ V_4 ] = V_5 ;
break;
default:
V_8 = - V_16 ;
goto V_39;
} ;
V_8 = F_9 ( V_2 , V_17 ) ;
V_39:
F_15 ( & V_10 -> V_38 ) ;
return V_8 ;
}
static T_4 F_18 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_45 * V_46 = F_20 ( V_43 ) ;
T_2 V_26 ;
int V_4 = F_10 ( V_46 -> V_47 ) ;
int V_20 = ! ! ( F_6 ( V_46 -> V_47 )
== V_21 ) ;
switch ( F_8 ( V_46 -> V_47 ) ) {
case V_23 :
V_26 = V_10 -> V_32 [ V_20 ] [ V_4 ] ;
break;
case V_24 :
V_26 = V_10 -> V_34 [ V_20 ] [ V_4 ] ;
break;
default:
return - V_16 ;
} ;
return sprintf ( V_44 , L_1 , V_26 ) ;
}
static T_4 F_21 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
const char * V_44 ,
T_5 V_48 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_45 * V_46 = F_20 ( V_43 ) ;
int V_4 = F_10 ( V_46 -> V_47 ) ;
int V_20 = ! ! ( F_6 ( V_46 -> V_47 ) ==
V_21 ) ;
T_2 V_49 ;
int V_8 ;
V_8 = F_22 ( V_44 , 10 , & V_49 ) ;
if ( V_8 < 0 )
return V_8 ;
F_14 ( & V_10 -> V_38 ) ;
switch ( F_8 ( V_46 -> V_47 ) ) {
case V_23 :
V_10 -> V_32 [ V_20 ] [ V_4 ] = V_49 ;
break;
case V_24 :
V_10 -> V_34 [ V_20 ] [ V_4 ] = V_49 ;
break;
default:
V_8 = - V_16 ;
goto V_39;
} ;
V_8 = F_9 ( V_2 , V_46 -> V_47 ) ;
V_39:
F_15 ( & V_10 -> V_38 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_48 ;
}
static T_6 F_23 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_2 V_52 ;
T_7 V_53 = F_24 () ;
int V_8 ;
V_8 = F_7 ( V_10 -> V_11 , V_54 ) ;
if ( V_8 < 0 )
return V_55 ;
V_52 = V_8 ;
if ( ( V_52 & V_56 ) &&
! ( V_10 -> V_57 & V_56 ) )
F_25 ( V_2 ,
F_26 ( V_58 ,
0 ,
V_25 ,
V_21 ) ,
V_53 ) ;
else if ( ( ! ( V_52 & V_56 ) ) &&
( V_10 -> V_57 & V_56 ) )
F_25 ( V_2 ,
F_26 ( V_58 ,
0 ,
V_25 ,
V_59 ) ,
V_53 ) ;
if ( ( V_52 & V_60 ) &&
! ( V_10 -> V_57 & V_60 ) )
F_25 ( V_2 ,
F_26 ( V_58 ,
1 ,
V_25 ,
V_21 ) ,
V_53 ) ;
else if ( ( ! ( V_52 & V_60 ) ) &&
( V_10 -> V_57 & V_60 ) )
F_25 ( V_2 ,
F_26 ( V_58 ,
1 ,
V_25 ,
V_59 ) ,
V_53 ) ;
V_10 -> V_57 = V_52 ;
return V_55 ;
}
static int T_8 F_27 ( struct V_61 * V_11 ,
const struct V_62 * V_63 )
{
int V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = F_28 ( sizeof( * V_10 ) ) ;
if ( V_2 == NULL ) {
V_8 = - V_64 ;
goto V_39;
}
V_10 = F_2 ( V_2 ) ;
F_29 ( & V_10 -> V_38 ) ;
F_30 ( V_11 , V_2 ) ;
V_10 -> V_11 = V_11 ;
V_2 -> V_65 = V_63 -> V_65 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = F_31 ( V_67 ) ;
V_2 -> V_41 . V_69 = & V_11 -> V_41 ;
V_2 -> V_70 = & V_71 ;
V_2 -> V_72 = V_73 ;
if ( V_11 -> V_50 ) {
V_8 = F_32 ( V_11 -> V_50 ,
NULL ,
& F_23 ,
V_74 |
V_75 ,
L_2 ,
V_2 ) ;
if ( V_8 )
goto V_76;
}
if ( V_11 -> V_41 . V_77 ) {
V_8 = F_32 ( * ( unsigned int * )
V_11 -> V_41 . V_77 ,
NULL ,
& F_23 ,
V_74 |
V_75 ,
L_3 ,
V_2 ) ;
if ( V_8 )
goto V_78;
}
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
goto V_79;
F_34 ( & V_11 -> V_41 , L_4 ,
V_63 -> V_65 , V_11 -> V_50 ) ;
return 0 ;
V_79:
if ( V_11 -> V_41 . V_77 )
F_35 ( * ( unsigned int * ) V_11 -> V_41 . V_77 ,
V_2 ) ;
V_78:
if ( V_11 -> V_50 )
F_35 ( V_11 -> V_50 , V_2 ) ;
V_76:
F_36 ( V_2 ) ;
V_39:
return V_8 ;
}
static int T_9 F_37 ( struct V_61 * V_11 )
{
struct V_1 * V_2 = F_38 ( V_11 ) ;
F_39 ( V_2 ) ;
if ( V_11 -> V_50 )
F_35 ( V_11 -> V_50 , V_2 ) ;
if ( V_11 -> V_41 . V_77 )
F_35 ( * ( unsigned int * ) V_11 -> V_41 . V_77 , V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static T_10 int F_40 ( void )
{
return F_41 ( & V_80 ) ;
}
static T_11 void F_42 ( void )
{
F_43 ( & V_80 ) ;
}
