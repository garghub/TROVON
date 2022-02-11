static int F_1 ( struct V_1 * V_2 ,
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
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_5 ( V_3 ) ;
V_9 -> V_11 [ 1 ] = ( V_13 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 2 ] = V_13 & 0xFF ;
V_5 = F_6 ( V_9 -> V_12 , V_9 -> V_11 , 3 ) ;
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_3 V_5 ;
V_5 = F_10 ( V_9 -> V_12 , F_11 ( V_3 ) ) ;
if ( V_5 < 0 ) {
F_12 ( & V_9 -> V_12 -> V_2 , L_1 ,
V_3 ) ;
return V_5 ;
}
* V_4 = V_5 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_3 V_5 ;
V_5 = F_14 ( V_9 -> V_12 , F_11 ( V_3 ) ) ;
if ( V_5 < 0 ) {
F_12 ( & V_9 -> V_12 -> V_2 , L_2 ,
V_3 ) ;
return V_5 ;
}
* V_4 = V_5 ;
* V_4 = F_15 ( V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_4 * V_4 )
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
} , {
. V_21 = V_9 -> V_11 ,
. V_19 = 8 ,
. V_20 = 3 ,
}
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_11 ( V_3 ) ;
F_17 ( & V_15 ) ;
F_18 ( & V_17 [ 0 ] , & V_15 ) ;
F_18 ( & V_17 [ 1 ] , & V_15 ) ;
V_5 = F_19 ( V_9 -> V_12 , & V_15 ) ;
if ( V_5 ) {
F_12 ( & V_9 -> V_12 -> V_2 , L_3 ,
V_3 ) ;
goto V_22;
}
* V_4 = ( V_9 -> V_23 [ 0 ] << 16 ) | ( V_9 -> V_23 [ 1 ] << 8 ) | V_9 -> V_23 [ 2 ] ;
V_22:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_3 F_20 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_1 V_4 ;
struct V_27 * V_28 = F_21 ( V_25 ) ;
V_5 = F_9 ( V_2 , V_28 -> V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_26 , L_4 , V_4 ) ;
}
static T_3 F_22 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_2 V_4 ;
struct V_27 * V_28 = F_21 ( V_25 ) ;
V_5 = F_13 ( V_2 , V_28 -> V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_26 , L_4 , V_4 ) ;
}
static T_3 F_23 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_4 V_4 ;
struct V_27 * V_28 = F_21 ( V_25 ) ;
V_5 = F_16 ( V_2 , V_28 -> V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_26 , L_4 , V_4 ) ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_25 ) ;
int V_5 ;
long V_4 ;
V_5 = F_25 ( V_26 , 10 , & V_4 ) ;
if ( V_5 )
goto V_22;
V_5 = F_1 ( V_2 , V_28 -> V_29 , V_4 ) ;
V_22:
return V_5 ? V_5 : V_20 ;
}
static T_3 F_26 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_25 ) ;
int V_5 ;
long V_4 ;
V_5 = F_25 ( V_26 , 10 , & V_4 ) ;
if ( V_5 )
goto V_22;
V_5 = F_8 ( V_2 , V_28 -> V_29 , V_4 ) ;
V_22:
return V_5 ? V_5 : V_20 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_2 V_4 ;
F_13 ( V_2 , V_30 , & V_4 ) ;
V_4 |= 1 << 6 ;
return F_8 ( V_2 , V_30 , V_4 ) ;
}
static T_3 F_28 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 , T_5 V_20 )
{
if ( V_20 < 1 )
return - 1 ;
switch ( V_26 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_27 ( V_2 ) ;
}
return - 1 ;
}
static int F_29 ( struct V_1 * V_2 , bool V_31 )
{
int V_5 ;
T_1 V_32 ;
V_5 = F_9 ( V_2 , V_33 , & V_32 ) ;
if ( V_5 )
goto V_22;
if ( V_31 )
V_32 |= 1 << 3 ;
else
V_32 &= ~ ( 1 << 3 ) ;
V_5 = F_1 ( V_2 , V_33 , V_32 ) ;
V_22:
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_2 V_4 ;
F_13 ( V_2 , V_30 , & V_4 ) ;
V_4 |= 1 << 4 ;
return F_8 ( V_2 , V_30 , V_4 ) ;
}
static int F_31 ( struct V_8 * V_9 )
{
int V_5 ;
struct V_1 * V_2 = & V_9 -> V_7 -> V_2 ;
V_9 -> V_12 -> V_34 = V_35 ;
F_32 ( V_9 -> V_12 ) ;
V_5 = F_29 ( V_2 , false ) ;
if ( V_5 ) {
F_12 ( V_2 , L_5 ) ;
goto V_36;
}
F_27 ( V_2 ) ;
F_33 ( V_37 ) ;
V_36:
return V_5 ;
}
static T_3 F_34 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 , V_20 = 0 ;
T_1 V_38 ;
int V_39 ;
V_5 = F_9 ( V_2 , V_30 , & V_38 ) ;
if ( V_5 )
return V_5 ;
V_38 = ( V_38 >> 11 ) & 0x3 ;
V_39 = 27900 / ( 1 + V_38 ) ;
V_20 = sprintf ( V_26 , L_6 , V_39 ) ;
return V_20 ;
}
static T_3 F_35 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_5 V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_4 ;
int V_5 ;
T_2 V_40 , V_38 ;
V_5 = F_25 ( V_26 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_4 ( & V_7 -> V_41 ) ;
V_38 = ( 27900 / V_4 ) ;
if ( V_38 > 0 )
V_38 -- ;
if ( V_38 > 1 )
V_9 -> V_12 -> V_42 = V_43 ;
else
V_9 -> V_12 -> V_42 = V_44 ;
V_5 = F_13 ( V_2 , V_30 , & V_40 ) ;
if ( V_5 )
goto V_45;
V_40 &= ~ ( 3 << 11 ) ;
V_40 |= V_38 << 11 ;
V_5 = F_8 ( V_2 , V_30 , V_40 ) ;
V_45:
F_7 ( & V_7 -> V_41 ) ;
return V_5 ? V_5 : V_20 ;
}
static int T_6 F_36 ( struct V_46 * V_47 )
{
int V_5 , V_48 = 0 ;
struct V_8 * V_9 = F_37 ( sizeof *V_9 , V_49 ) ;
if ( ! V_9 ) {
V_5 = - V_50 ;
goto V_22;
}
F_38 ( V_47 , V_9 ) ;
V_9 -> V_23 = F_37 ( sizeof( * V_9 -> V_23 ) * V_51 , V_49 ) ;
if ( V_9 -> V_23 == NULL ) {
V_5 = - V_50 ;
goto V_52;
}
V_9 -> V_11 = F_37 ( sizeof( * V_9 -> V_11 ) * V_53 , V_49 ) ;
if ( V_9 -> V_11 == NULL ) {
V_5 = - V_50 ;
goto V_54;
}
V_9 -> V_12 = V_47 ;
F_39 ( & V_9 -> V_10 ) ;
V_9 -> V_7 = F_40 ( 0 ) ;
if ( V_9 -> V_7 == NULL ) {
V_5 = - V_50 ;
goto V_55;
}
V_9 -> V_7 -> V_56 = V_47 -> V_2 . V_57 -> V_56 ;
V_9 -> V_7 -> V_2 . V_58 = & V_47 -> V_2 ;
V_9 -> V_7 -> V_59 = & V_60 ;
V_9 -> V_7 -> V_61 = ( void * ) ( V_9 ) ;
V_9 -> V_7 -> V_62 = V_63 ;
V_5 = F_41 ( V_9 -> V_7 ) ;
if ( V_5 )
goto V_64;
V_48 = 1 ;
V_5 = F_31 ( V_9 ) ;
if ( V_5 )
goto V_64;
return 0 ;
V_64:
if ( V_48 )
F_42 ( V_9 -> V_7 ) ;
else
F_43 ( V_9 -> V_7 ) ;
V_55:
F_44 ( V_9 -> V_11 ) ;
V_54:
F_44 ( V_9 -> V_23 ) ;
V_52:
F_44 ( V_9 ) ;
V_22:
return V_5 ;
}
static int F_45 ( struct V_46 * V_47 )
{
int V_5 ;
struct V_8 * V_9 = F_46 ( V_47 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
V_5 = F_30 ( & ( V_7 -> V_2 ) ) ;
if ( V_5 )
goto V_36;
F_42 ( V_7 ) ;
F_44 ( V_9 -> V_11 ) ;
F_44 ( V_9 -> V_23 ) ;
F_44 ( V_9 ) ;
return 0 ;
V_36:
return V_5 ;
}
static T_7 int F_47 ( void )
{
return F_48 ( & V_65 ) ;
}
static T_8 void F_49 ( void )
{
F_50 ( & V_65 ) ;
}
