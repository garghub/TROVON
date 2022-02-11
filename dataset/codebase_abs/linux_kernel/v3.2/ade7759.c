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
int V_5 ;
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
int V_5 ;
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
T_3 * V_4 )
{
struct V_14 V_15 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_16 V_17 [] = {
{
. V_18 = V_9 -> V_11 ,
. V_19 = V_9 -> V_20 ,
. V_21 = 8 ,
. V_22 = 6 ,
} ,
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_11 ( V_3 ) ;
memset ( & V_9 -> V_11 [ 1 ] , 0 , 5 ) ;
F_17 ( & V_15 ) ;
F_18 ( V_17 , & V_15 ) ;
V_5 = F_19 ( V_9 -> V_12 , & V_15 ) ;
if ( V_5 ) {
F_12 ( & V_9 -> V_12 -> V_2 , L_3 ,
V_3 ) ;
goto V_23;
}
* V_4 = ( ( T_3 ) V_9 -> V_20 [ 1 ] << 32 ) | ( V_9 -> V_20 [ 2 ] << 24 ) |
( V_9 -> V_20 [ 3 ] << 16 ) | ( V_9 -> V_20 [ 4 ] << 8 ) | V_9 -> V_20 [ 5 ] ;
V_23:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_4 F_20 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_1 V_4 = 0 ;
struct V_27 * V_28 = F_21 ( V_25 ) ;
V_5 = F_9 ( V_2 , V_28 -> V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_26 , L_4 , V_4 ) ;
}
static T_4 F_22 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_2 V_4 = 0 ;
struct V_27 * V_28 = F_21 ( V_25 ) ;
V_5 = F_13 ( V_2 , V_28 -> V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_26 , L_4 , V_4 ) ;
}
static T_4 F_23 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_3 V_4 = 0 ;
struct V_27 * V_28 = F_21 ( V_25 ) ;
V_5 = F_16 ( V_2 , V_28 -> V_29 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_26 , L_5 , V_4 ) ;
}
static T_4 F_24 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_5 V_22 )
{
struct V_27 * V_28 = F_21 ( V_25 ) ;
int V_5 ;
long V_4 ;
V_5 = F_25 ( V_26 , 10 , & V_4 ) ;
if ( V_5 )
goto V_23;
V_5 = F_1 ( V_2 , V_28 -> V_29 , V_4 ) ;
V_23:
return V_5 ? V_5 : V_22 ;
}
static T_4 F_26 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_5 V_22 )
{
struct V_27 * V_28 = F_21 ( V_25 ) ;
int V_5 ;
long V_4 ;
V_5 = F_25 ( V_26 , 10 , & V_4 ) ;
if ( V_5 )
goto V_23;
V_5 = F_8 ( V_2 , V_28 -> V_29 , V_4 ) ;
V_23:
return V_5 ? V_5 : V_22 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_4 ;
F_13 ( V_2 ,
V_30 ,
& V_4 ) ;
V_4 |= 1 << 6 ;
V_5 = F_8 ( V_2 ,
V_30 ,
V_4 ) ;
return V_5 ;
}
static T_4 F_28 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 , T_5 V_22 )
{
if ( V_22 < 1 )
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
goto V_23;
if ( V_31 )
V_32 |= 1 << 3 ;
else
V_32 &= ~ ( 1 << 3 ) ;
V_5 = F_1 ( V_2 , V_33 , V_32 ) ;
V_23:
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_2 V_4 ;
F_13 ( V_2 ,
V_30 ,
& V_4 ) ;
V_4 |= 1 << 4 ;
return F_8 ( V_2 , V_30 , V_4 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
int V_5 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_1 * V_2 = & V_7 -> V_2 ;
V_9 -> V_12 -> V_34 = V_35 ;
F_32 ( V_9 -> V_12 ) ;
V_5 = F_29 ( V_2 , false ) ;
if ( V_5 ) {
F_12 ( V_2 , L_6 ) ;
goto V_36;
}
F_27 ( V_2 ) ;
F_33 ( V_37 ) ;
V_36:
return V_5 ;
}
static T_4 F_34 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
char * V_26 )
{
int V_5 ;
T_2 V_38 ;
int V_39 ;
V_5 = F_13 ( V_2 ,
V_30 ,
& V_38 ) ;
if ( V_5 )
return V_5 ;
V_38 = ( V_38 >> 3 ) & 0x3 ;
V_39 = 27900 / ( 1 + V_38 ) ;
return sprintf ( V_26 , L_7 , V_39 ) ;
}
static T_4 F_35 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_5 V_22 )
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
V_40 &= ~ ( 3 << 13 ) ;
V_40 |= V_38 << 13 ;
V_5 = F_8 ( V_2 , V_30 , V_40 ) ;
V_45:
F_7 ( & V_7 -> V_41 ) ;
return V_5 ? V_5 : V_22 ;
}
static int T_6 F_36 ( struct V_46 * V_47 )
{
int V_5 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_7 = F_37 ( sizeof( * V_9 ) ) ;
if ( V_7 == NULL ) {
V_5 = - V_48 ;
goto V_23;
}
F_38 ( V_47 , V_7 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_12 = V_47 ;
F_39 ( & V_9 -> V_10 ) ;
V_7 -> V_49 = V_47 -> V_2 . V_50 -> V_49 ;
V_7 -> V_2 . V_51 = & V_47 -> V_2 ;
V_7 -> V_52 = & V_53 ;
V_7 -> V_54 = V_55 ;
V_5 = F_31 ( V_7 ) ;
if ( V_5 )
goto V_56;
V_5 = F_40 ( V_7 ) ;
if ( V_5 )
goto V_56;
return 0 ;
V_56:
F_41 ( V_7 ) ;
V_23:
return V_5 ;
}
static int F_42 ( struct V_46 * V_47 )
{
int V_5 ;
struct V_6 * V_7 = F_43 ( V_47 ) ;
F_44 ( V_7 ) ;
V_5 = F_30 ( & ( V_7 -> V_2 ) ) ;
if ( V_5 )
goto V_36;
F_41 ( V_7 ) ;
V_36:
return V_5 ;
}
static T_7 int F_45 ( void )
{
return F_46 ( & V_57 ) ;
}
static T_8 void F_47 ( void )
{
F_48 ( & V_57 ) ;
}
