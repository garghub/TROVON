static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( F_4 ( V_9 -> V_10 . V_11 ) -> V_12 )
return sprintf ( V_5 , L_1 , L_2 ) ;
else
return sprintf ( V_5 , L_1 , L_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 , V_14 = 0 ;
T_2 V_15 ;
int V_16 ;
V_13 = F_6 ( & V_9 -> V_10 , V_17 , & V_15 ) ;
if ( V_13 )
return V_13 ;
if ( F_4 ( V_9 -> V_10 . V_11 ) -> V_12 )
V_16 = ( V_15 & V_18 ) ? 8 : 256 ;
else
V_16 = ( V_15 & V_18 ) ? 66 : 2048 ;
V_16 /= ( V_15 & V_19 ) + 1 ;
V_14 = sprintf ( V_5 , L_4 , V_16 ) ;
return V_14 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_3 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
long V_20 ;
int V_13 ;
T_4 V_15 ;
V_13 = F_8 ( V_5 , 10 , & V_20 ) ;
if ( V_13 )
return V_13 ;
if ( V_20 == 0 )
return - V_21 ;
F_9 ( & V_7 -> V_22 ) ;
if ( F_4 ( V_9 -> V_10 . V_11 ) -> V_12 ) {
V_15 = ( 256 / V_20 ) ;
if ( V_15 > 0 )
V_15 -- ;
V_15 &= V_19 ;
} else {
V_15 = ( 2048 / V_20 ) ;
if ( V_15 > 0 )
V_15 -- ;
V_15 &= V_19 ;
}
if ( ( V_15 & V_19 ) >= 0x0A )
V_9 -> V_10 . V_11 -> V_23 = V_24 ;
else
V_9 -> V_10 . V_11 -> V_23 = V_25 ;
V_13 = F_10 ( & V_9 -> V_10 ,
V_17 ,
V_15 ) ;
F_11 ( & V_7 -> V_22 ) ;
return V_13 ? V_13 : V_14 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
T_2 V_20 = V_26 ;
V_13 = F_13 ( & V_9 -> V_10 , V_27 , V_20 ) ;
if ( V_13 )
F_14 ( & V_7 -> V_2 , L_5 ) ;
return V_13 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_28 const * V_29 ,
int * V_20 , int * V_30 ,
long V_31 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_13 ;
int V_32 ;
T_4 V_33 ;
T_5 V_34 ;
switch ( V_31 ) {
case V_35 :
return F_16 ( V_7 , V_29 ,
V_36 , V_20 ) ;
case V_37 :
switch ( V_29 -> type ) {
case V_38 :
* V_20 = 0 ;
if ( F_4 ( V_9 -> V_10 . V_11 ) -> V_12 ) {
* V_30 = F_17 ( 18320 ) ;
} else {
* V_30 = F_17 ( 73260 ) ;
}
return V_39 ;
case V_40 :
if ( V_29 -> V_41 == 0 ) {
* V_20 = 1 ;
* V_30 = 831500 ;
} else {
* V_20 = 0 ;
* V_30 = 610500 ;
}
return V_39 ;
case V_42 :
* V_20 = 145 ;
* V_30 = 300000 ;
return V_39 ;
default:
return - V_21 ;
}
break;
case V_43 :
* V_20 = 250000 / 1453 ;
return V_44 ;
case V_45 :
switch ( V_29 -> type ) {
case V_38 :
V_32 = 12 ;
break;
default:
return - V_21 ;
}
F_9 ( & V_7 -> V_22 ) ;
V_33 = V_46 [ V_29 -> V_47 ] [ 0 ] ;
V_13 = F_6 ( & V_9 -> V_10 , V_33 , & V_34 ) ;
if ( V_13 ) {
F_11 ( & V_7 -> V_22 ) ;
return V_13 ;
}
V_34 &= ( 1 << V_32 ) - 1 ;
V_34 = ( T_5 ) ( V_34 << ( 16 - V_32 ) ) >> ( 16 - V_32 ) ;
* V_20 = V_34 ;
F_11 ( & V_7 -> V_22 ) ;
return V_44 ;
case V_48 :
switch ( V_29 -> type ) {
case V_38 :
V_32 = 12 ;
break;
default:
return - V_21 ;
}
F_9 ( & V_7 -> V_22 ) ;
V_33 = V_46 [ V_29 -> V_47 ] [ 1 ] ;
V_13 = F_6 ( & V_9 -> V_10 , V_33 , & V_34 ) ;
if ( V_13 ) {
F_11 ( & V_7 -> V_22 ) ;
return V_13 ;
}
* V_20 = ( 1 << V_32 ) - 1 ;
F_11 ( & V_7 -> V_22 ) ;
return V_44 ;
}
return - V_21 ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_28 const * V_29 ,
int V_20 ,
int V_30 ,
long V_31 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_32 = 12 ;
T_5 V_34 ;
T_4 V_33 ;
switch ( V_31 ) {
case V_45 :
V_34 = V_20 & ( ( 1 << V_32 ) - 1 ) ;
V_33 = V_46 [ V_29 -> V_47 ] [ 0 ] ;
return F_13 ( & V_9 -> V_10 , V_33 , V_34 ) ;
case V_48 :
V_34 = V_20 & ( ( 1 << V_32 ) - 1 ) ;
V_33 = V_46 [ V_29 -> V_47 ] [ 1 ] ;
return F_13 ( & V_9 -> V_10 , V_33 , V_34 ) ;
}
return - V_21 ;
}
static int F_19 ( struct V_49 * V_11 )
{
int V_13 ;
struct V_50 * V_51 = V_11 -> V_2 . V_52 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_7 = F_20 ( sizeof( * V_9 ) ) ;
if ( V_7 == NULL ) {
V_13 = - V_53 ;
goto V_54;
}
V_9 = F_3 ( V_7 ) ;
if ( V_51 )
V_9 -> V_55 = V_51 -> V_55 ;
F_21 ( V_11 , V_7 ) ;
V_7 -> V_56 = F_4 ( V_11 ) -> V_56 ;
V_7 -> V_2 . V_57 = & V_11 -> V_2 ;
V_7 -> V_58 = & V_59 ;
V_7 -> V_60
= F_22 ( V_61 ) ;
if ( V_51 && V_51 -> V_62 )
switch ( V_51 -> V_62 ) {
case 'x' :
V_7 -> V_63 = V_61 ;
break;
case 'y' :
V_7 -> V_63 = V_64 ;
break;
case 'z' :
V_7 -> V_63 = V_65 ;
break;
default:
return - V_21 ;
}
else
V_7 -> V_63 = V_61 ;
V_7 -> V_60 = F_22 ( V_61 ) ;
V_7 -> V_66 = V_67 ;
V_13 = F_23 ( & V_9 -> V_10 , V_7 , V_11 , & V_68 ) ;
if ( V_13 )
goto V_69;
V_13 = F_24 ( & V_9 -> V_10 , V_7 , NULL ) ;
if ( V_13 )
goto V_69;
if ( V_7 -> V_70 ) {
F_25 ( V_7 , V_7 -> V_70 ,
V_71 ) ;
F_25 ( V_7 , V_7 -> V_70 ,
V_72 ) ;
F_25 ( V_7 , V_7 -> V_70 ,
V_73 ) ;
F_25 ( V_7 , V_7 -> V_70 ,
V_74 ) ;
F_25 ( V_7 , V_7 -> V_70 ,
V_75 ) ;
}
V_13 = F_26 ( & V_9 -> V_10 ) ;
if ( V_13 )
goto V_76;
V_13 = F_27 ( V_7 ) ;
if ( V_13 )
goto V_76;
return 0 ;
V_76:
F_28 ( & V_9 -> V_10 , V_7 ) ;
V_69:
F_29 ( V_7 ) ;
V_54:
return V_13 ;
}
static int F_30 ( struct V_49 * V_11 )
{
struct V_6 * V_7 = F_31 ( V_11 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_32 ( V_7 ) ;
F_12 ( V_7 ) ;
F_28 ( & V_9 -> V_10 , V_7 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
