int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = V_4 ;
V_5 = F_6 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_13 )
{
int V_5 ;
struct V_14 V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_16 V_17 [] = {
{
. V_18 = V_9 -> V_11 ,
. V_19 = 8 ,
. V_20 = 3 ,
}
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = ( V_13 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 2 ] = V_13 & 0xFF ;
F_9 ( & V_15 ) ;
F_10 ( V_17 , & V_15 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_15 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 V_13 )
{
int V_5 ;
struct V_14 V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_16 V_17 [] = {
{
. V_18 = V_9 -> V_11 ,
. V_19 = 8 ,
. V_20 = 4 ,
}
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = ( V_13 >> 16 ) & 0xFF ;
V_9 -> V_11 [ 2 ] = ( V_13 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 3 ] = V_13 & 0xFF ;
F_9 ( & V_15 ) ;
F_10 ( V_17 , & V_15 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_15 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 )
{
struct V_14 V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_16 V_17 [] = {
{
. V_18 = V_9 -> V_11 ,
. V_19 = 8 ,
. V_20 = 1 ,
. V_21 = 4 ,
} ,
{
. V_18 = & V_9 -> V_11 [ 1 ] ,
. V_22 = V_9 -> V_23 ,
. V_19 = 8 ,
. V_20 = 1 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_14 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
F_9 ( & V_15 ) ;
F_10 ( & V_17 [ 0 ] , & V_15 ) ;
F_10 ( & V_17 [ 1 ] , & V_15 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_15 ) ;
if ( V_5 ) {
F_15 ( & V_9 -> V_12 -> V_2 , L_1 ,
V_3 ) ;
goto V_24;
}
* V_4 = V_9 -> V_23 [ 0 ] ;
V_24:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_14 V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_16 V_17 [] = {
{
. V_18 = V_9 -> V_11 ,
. V_19 = 8 ,
. V_20 = 1 ,
. V_21 = 4 ,
} ,
{
. V_18 = & V_9 -> V_11 [ 1 ] ,
. V_22 = V_9 -> V_23 ,
. V_19 = 8 ,
. V_20 = 2 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_14 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
V_9 -> V_11 [ 2 ] = 0 ;
F_9 ( & V_15 ) ;
F_10 ( & V_17 [ 0 ] , & V_15 ) ;
F_10 ( & V_17 [ 1 ] , & V_15 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_15 ) ;
if ( V_5 ) {
F_15 ( & V_9 -> V_12 -> V_2 , L_2 ,
V_3 ) ;
goto V_24;
}
* V_4 = ( V_9 -> V_23 [ 0 ] << 8 ) | V_9 -> V_23 [ 1 ] ;
V_24:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 * V_4 )
{
struct V_14 V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_16 V_17 [] = {
{
. V_18 = V_9 -> V_11 ,
. V_19 = 8 ,
. V_20 = 1 ,
. V_21 = 4 ,
} ,
{
. V_18 = & V_9 -> V_11 [ 1 ] ,
. V_22 = V_9 -> V_23 ,
. V_19 = 8 ,
. V_20 = 3 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_14 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = 0 ;
V_9 -> V_11 [ 2 ] = 0 ;
V_9 -> V_11 [ 3 ] = 0 ;
F_9 ( & V_15 ) ;
F_10 ( & V_17 [ 0 ] , & V_15 ) ;
F_10 ( & V_17 [ 1 ] , & V_15 ) ;
V_5 = F_11 ( V_9 -> V_12 , & V_15 ) ;
if ( V_5 ) {
F_15 ( & V_9 -> V_12 -> V_2 , L_3 ,
V_3 ) ;
goto V_24;
}
* V_4 = ( V_9 -> V_23 [ 0 ] << 16 ) | ( V_9 -> V_23 [ 1 ] << 8 ) | V_9 -> V_23 [ 2 ] ;
V_24:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_4 F_18 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
char * V_27 )
{
int V_5 ;
T_1 V_4 = 0 ;
struct V_28 * V_29 = F_19 ( V_26 ) ;
V_5 = F_13 ( V_2 , V_29 -> V_30 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_27 , L_4 , V_4 ) ;
}
static T_4 F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
char * V_27 )
{
int V_5 ;
T_2 V_4 = 0 ;
struct V_28 * V_29 = F_19 ( V_26 ) ;
V_5 = F_16 ( V_2 , V_29 -> V_30 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_27 , L_4 , V_4 ) ;
}
static T_4 F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
char * V_27 )
{
int V_5 ;
T_3 V_4 = 0 ;
struct V_28 * V_29 = F_19 ( V_26 ) ;
V_5 = F_17 ( V_2 , V_29 -> V_30 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_27 , L_4 , V_4 & 0xFFFFFF ) ;
}
static T_4 F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_20 )
{
struct V_28 * V_29 = F_19 ( V_26 ) ;
int V_5 ;
long V_4 ;
V_5 = F_23 ( V_27 , 10 , & V_4 ) ;
if ( V_5 )
goto V_24;
V_5 = F_1 ( V_2 , V_29 -> V_30 , V_4 ) ;
V_24:
return V_5 ? V_5 : V_20 ;
}
static T_4 F_24 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_20 )
{
struct V_28 * V_29 = F_19 ( V_26 ) ;
int V_5 ;
long V_4 ;
V_5 = F_23 ( V_27 , 10 , & V_4 ) ;
if ( V_5 )
goto V_24;
V_5 = F_8 ( V_2 , V_29 -> V_30 , V_4 ) ;
V_24:
return V_5 ? V_5 : V_20 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_4 ;
F_13 ( V_2 ,
V_31 ,
& V_4 ) ;
V_4 |= 1 << 6 ;
V_5 = F_1 ( V_2 ,
V_31 ,
V_4 ) ;
return V_5 ;
}
static T_4 F_26 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
const char * V_27 , T_5 V_20 )
{
if ( V_20 < 1 )
return - 1 ;
switch ( V_27 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_25 ( V_2 ) ;
}
return V_20 ;
}
int F_27 ( struct V_1 * V_2 , bool V_32 )
{
int V_5 ;
T_3 V_33 ;
V_5 = F_17 ( V_2 , V_34 , & V_33 ) ;
if ( V_5 )
goto V_24;
if ( V_32 )
V_33 |= 1 << 16 ;
else
V_33 &= ~ ( 1 << 16 ) ;
V_5 = F_12 ( V_2 , V_34 , V_33 ) ;
if ( V_5 )
goto V_24;
V_24:
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_4 ;
F_13 ( V_2 ,
V_31 ,
& V_4 ) ;
V_4 |= 7 << 3 ;
V_5 = F_1 ( V_2 ,
V_31 ,
V_4 ) ;
return V_5 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_5 ;
V_9 -> V_12 -> V_35 = V_36 ;
F_30 ( V_9 -> V_12 ) ;
V_5 = F_27 ( V_2 , false ) ;
if ( V_5 ) {
F_15 ( V_2 , L_5 ) ;
goto V_37;
}
F_25 ( V_2 ) ;
F_31 ( V_38 ) ;
V_37:
return V_5 ;
}
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
char * V_27 )
{
int V_5 , V_20 = 0 ;
T_1 V_39 ;
int V_40 ;
V_5 = F_13 ( V_2 ,
V_41 ,
& V_39 ) ;
if ( V_5 )
return V_5 ;
V_39 = ( V_39 >> 5 ) & 0x3 ;
V_40 = 26040 / ( 1 << V_39 ) ;
V_20 = sprintf ( V_27 , L_6 , V_40 ) ;
return V_20 ;
}
static T_4 F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
const char * V_27 ,
T_5 V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_4 ;
int V_5 ;
T_1 V_42 , V_39 ;
V_5 = F_23 ( V_27 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_4 ( & V_7 -> V_43 ) ;
switch ( V_4 ) {
case 26040 :
V_39 = 0 ;
break;
case 13020 :
V_39 = 1 ;
break;
case 6510 :
V_39 = 2 ;
break;
case 3255 :
V_39 = 3 ;
break;
default:
V_5 = - V_44 ;
goto V_45;
}
V_5 = F_13 ( V_2 ,
V_41 ,
& V_42 ) ;
if ( V_5 )
goto V_45;
V_42 &= ~ ( 5 << 3 ) ;
V_42 |= V_39 << 5 ;
V_5 = F_1 ( V_2 ,
V_41 ,
V_42 ) ;
V_45:
F_7 ( & V_7 -> V_43 ) ;
return V_5 ? V_5 : V_20 ;
}
static int T_6 F_34 ( struct V_46 * V_47 )
{
int V_48 , V_5 ;
struct V_8 * V_9 ;
struct V_6 * V_7 = F_35 ( sizeof( * V_9 ) ) ;
if ( V_7 == NULL ) {
V_5 = - V_49 ;
goto V_24;
}
V_9 = F_3 ( V_7 ) ;
F_36 ( V_47 , V_7 ) ;
V_9 -> V_23 = F_37 ( V_50 , sizeof( * V_9 -> V_23 ) , V_51 ) ;
if ( V_9 -> V_23 == NULL ) {
V_5 = - V_49 ;
goto V_52;
}
V_9 -> V_11 = F_37 ( V_53 , sizeof( * V_9 -> V_11 ) , V_51 ) ;
if ( V_9 -> V_11 == NULL ) {
V_5 = - V_49 ;
goto V_54;
}
V_9 -> V_12 = V_47 ;
V_9 -> V_55 = & V_56 [ 0 ] ;
F_38 ( & V_9 -> V_10 ) ;
V_7 -> V_57 = V_47 -> V_2 . V_58 -> V_57 ;
V_7 -> V_2 . V_59 = & V_47 -> V_2 ;
V_7 -> V_60 = & V_61 ;
V_7 -> V_62 = V_63 ;
for ( V_48 = 0 ; V_48 < V_64 ; V_48 ++ )
F_39 ( V_48 , & V_9 -> V_65 [ V_48 ] ) ;
V_7 -> V_65 = V_9 -> V_65 ;
V_5 = F_40 ( V_7 ) ;
if ( V_5 )
goto V_66;
V_5 = F_41 ( V_7 ,
& V_56 [ 0 ] ,
F_42 ( V_56 ) ) ;
if ( V_5 ) {
F_15 ( & V_47 -> V_2 , L_7 ) ;
goto V_67;
}
V_5 = F_29 ( V_7 ) ;
if ( V_5 )
goto V_68;
if ( V_47 -> V_69 ) {
V_5 = F_43 ( V_7 ) ;
if ( V_5 )
goto V_68;
}
V_5 = F_44 ( V_7 ) ;
if ( V_5 )
goto V_70;
return 0 ;
V_70:
if ( V_47 -> V_69 )
F_45 ( V_7 ) ;
V_68:
F_46 ( V_7 ) ;
V_67:
F_47 ( V_7 ) ;
V_66:
F_48 ( V_9 -> V_11 ) ;
V_54:
F_48 ( V_9 -> V_23 ) ;
V_52:
F_49 ( V_7 ) ;
V_24:
return V_5 ;
}
static int F_50 ( struct V_46 * V_47 )
{
struct V_6 * V_7 = F_51 ( V_47 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
F_52 ( V_7 ) ;
V_5 = F_28 ( & V_7 -> V_2 ) ;
if ( V_5 )
goto V_37;
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_7 ) ;
F_48 ( V_9 -> V_11 ) ;
F_48 ( V_9 -> V_23 ) ;
F_49 ( V_7 ) ;
V_37:
return V_5 ;
}
