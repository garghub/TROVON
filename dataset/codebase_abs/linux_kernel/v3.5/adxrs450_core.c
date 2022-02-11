static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = V_10 | ( V_3 >> 7 ) ;
V_6 -> V_9 [ 1 ] = V_3 << 1 ;
V_6 -> V_9 [ 2 ] = 0 ;
V_6 -> V_9 [ 3 ] = 0 ;
if ( ! ( F_4 ( F_5 ( * ( V_11 * ) V_6 -> V_9 ) ) & 1 ) )
V_6 -> V_9 [ 3 ] |= V_12 ;
V_7 = F_6 ( V_6 -> V_13 , V_6 -> V_9 , 4 ) ;
if ( V_7 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_1 ,
V_3 ) ;
goto V_15;
}
V_7 = F_8 ( V_6 -> V_13 , V_6 -> V_16 , 4 ) ;
if ( V_7 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_1 ,
V_3 ) ;
goto V_15;
}
* V_4 = ( F_5 ( * ( V_11 * ) V_6 -> V_16 ) >> 5 ) & 0xFFFF ;
V_15:
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = V_17 | V_3 >> 7 ;
V_6 -> V_9 [ 1 ] = V_3 << 1 | V_4 >> 15 ;
V_6 -> V_9 [ 2 ] = V_4 >> 7 ;
V_6 -> V_9 [ 3 ] = V_4 << 1 ;
if ( ! ( F_4 ( F_5 ( * ( V_11 * ) V_6 -> V_9 ) ) & 1 ) )
V_6 -> V_9 [ 3 ] |= V_12 ;
V_7 = F_6 ( V_6 -> V_13 , V_6 -> V_9 , 4 ) ;
if ( V_7 )
F_7 ( & V_6 -> V_13 -> V_14 , L_2 ,
V_3 ) ;
F_11 ( 1 ) ;
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = V_18 ;
V_6 -> V_9 [ 1 ] = 0 ;
V_6 -> V_9 [ 2 ] = 0 ;
V_6 -> V_9 [ 3 ] = 0 ;
V_7 = F_6 ( V_6 -> V_13 , V_6 -> V_9 , 4 ) ;
if ( V_7 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_3 ) ;
goto V_15;
}
V_7 = F_8 ( V_6 -> V_13 , V_6 -> V_16 , 4 ) ;
if ( V_7 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_3 ) ;
goto V_15;
}
* V_4 = ( F_5 ( * ( V_11 * ) V_6 -> V_16 ) >> 10 ) & 0xFFFF ;
V_15:
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_13 ( struct V_5 * V_6 ,
V_11 * V_4 , char V_19 )
{
struct V_20 V_21 ;
int V_7 ;
struct V_22 V_23 = {
. V_24 = V_6 -> V_9 ,
. V_25 = V_6 -> V_16 ,
. V_26 = 8 ,
. V_27 = 4 ,
} ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 [ 0 ] = V_18 ;
V_6 -> V_9 [ 1 ] = 0 ;
V_6 -> V_9 [ 2 ] = 0 ;
V_6 -> V_9 [ 3 ] = 0 ;
if ( V_19 )
V_6 -> V_9 [ 3 ] |= ( V_28 | V_12 ) ;
F_14 ( & V_21 ) ;
F_15 ( & V_23 , & V_21 ) ;
V_7 = F_16 ( V_6 -> V_13 , & V_21 ) ;
if ( V_7 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_4 ) ;
goto V_15;
}
* V_4 = F_5 ( * ( V_11 * ) V_6 -> V_16 ) ;
V_15:
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 )
{
V_11 V_29 ;
T_2 V_30 ;
int V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_11 ( V_31 * 2 ) ;
V_7 = F_13 ( V_6 , & V_29 , 1 ) ;
if ( V_7 )
return V_7 ;
if ( V_29 != 0x01 )
F_18 ( & V_6 -> V_13 -> V_14 , L_5
L_6 ) ;
F_11 ( V_31 ) ;
V_7 = F_13 ( V_6 , & V_29 , 0 ) ;
if ( V_7 )
return V_7 ;
F_11 ( V_31 ) ;
V_7 = F_13 ( V_6 , & V_29 , 0 ) ;
if ( V_7 )
return V_7 ;
if ( ( ( V_29 & 0xff ) | 0x01 ) != 0xff || F_19 ( V_29 ) != 2 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_7 ) ;
return - V_32 ;
}
V_7 = F_13 ( V_6 , & V_29 , 0 ) ;
if ( V_7 )
return V_7 ;
if ( ( ( V_29 & 0xff ) | 0x01 ) != 0xff || F_19 ( V_29 ) != 2 ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_8 ) ;
return - V_32 ;
}
V_7 = F_1 ( V_2 , V_33 , & V_30 ) ;
if ( V_7 )
return V_7 ;
if ( V_30 & 0x0fff ) {
F_7 ( & V_6 -> V_13 -> V_14 , L_9 ) ;
return - V_34 ;
}
V_7 = F_1 ( V_2 , V_35 , & V_30 ) ;
if ( V_7 )
return V_7 ;
F_20 ( & V_6 -> V_13 -> V_14 , L_10 , V_30 ) ;
V_7 = F_1 ( V_2 , V_36 , & V_30 ) ;
if ( V_7 )
return V_7 ;
V_29 = V_30 ;
V_7 = F_1 ( V_2 , V_37 , & V_30 ) ;
if ( V_7 )
return V_7 ;
V_29 |= V_30 << 16 ;
F_20 ( & V_6 -> V_13 -> V_14 , L_11 , V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_38 const * V_39 ,
int V_4 ,
int V_40 ,
long V_41 )
{
int V_7 ;
switch ( V_41 ) {
case V_42 :
V_7 = F_10 ( V_2 ,
V_43 ,
V_4 & 0x3FF ) ;
break;
default:
V_7 = - V_34 ;
break;
}
return V_7 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_38 const * V_39 ,
int * V_4 ,
int * V_40 ,
long V_41 )
{
int V_7 ;
T_3 V_29 ;
switch ( V_41 ) {
case V_44 :
switch ( V_39 -> type ) {
case V_45 :
V_7 = F_12 ( V_2 , & V_29 ) ;
if ( V_7 )
break;
* V_4 = V_29 ;
V_7 = V_46 ;
break;
case V_47 :
V_7 = F_1 ( V_2 ,
V_48 , & V_29 ) ;
if ( V_7 )
break;
* V_4 = ( V_29 >> 6 ) + 225 ;
V_7 = V_46 ;
break;
default:
V_7 = - V_34 ;
break;
}
break;
case V_49 :
switch ( V_39 -> type ) {
case V_45 :
* V_4 = 0 ;
* V_40 = 218166 ;
return V_50 ;
case V_47 :
* V_4 = 200 ;
* V_40 = 0 ;
return V_46 ;
default:
return - V_34 ;
}
break;
case V_51 :
V_7 = F_1 ( V_2 , V_52 , & V_29 ) ;
if ( V_7 )
break;
* V_4 = V_29 ;
V_7 = V_46 ;
break;
case V_42 :
V_7 = F_1 ( V_2 , V_43 , & V_29 ) ;
if ( V_7 )
break;
* V_4 = V_29 ;
V_7 = V_46 ;
break;
default:
V_7 = - V_34 ;
break;
}
return V_7 ;
}
static int T_4 F_23 ( struct V_53 * V_54 )
{
int V_7 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
V_7 = - V_55 ;
goto V_15;
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_13 = V_54 ;
F_25 ( & V_6 -> V_8 ) ;
F_26 ( V_54 , V_2 ) ;
V_2 -> V_14 . V_56 = & V_54 -> V_14 ;
V_2 -> V_57 = & V_58 ;
V_2 -> V_59 = V_60 ;
V_2 -> V_61 =
V_62 [ F_27 ( V_54 ) -> V_63 ] ;
V_2 -> V_64 = F_28 ( V_62 ) ;
V_2 -> V_65 = V_54 -> V_14 . V_66 -> V_65 ;
V_7 = F_29 ( V_2 ) ;
if ( V_7 )
goto V_67;
V_7 = F_17 ( V_2 ) ;
if ( V_7 )
goto V_68;
return 0 ;
V_68:
F_30 ( V_2 ) ;
V_67:
F_31 ( V_2 ) ;
V_15:
return V_7 ;
}
static int F_32 ( struct V_53 * V_54 )
{
F_30 ( F_33 ( V_54 ) ) ;
F_31 ( F_33 ( V_54 ) ) ;
return 0 ;
}
