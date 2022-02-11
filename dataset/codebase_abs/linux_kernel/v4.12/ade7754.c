static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_9 [ 0 ] = F_4 ( V_3 ) ;
V_8 -> V_9 [ 1 ] = V_4 ;
return F_5 ( V_8 -> V_10 , V_8 -> V_9 , 2 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_11 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_7 ( & V_8 -> V_12 ) ;
V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_8 -> V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_13 )
{
int V_11 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_7 ( & V_8 -> V_12 ) ;
V_8 -> V_9 [ 0 ] = F_4 ( V_3 ) ;
V_8 -> V_9 [ 1 ] = ( V_13 >> 8 ) & 0xFF ;
V_8 -> V_9 [ 2 ] = V_13 & 0xFF ;
V_11 = F_5 ( V_8 -> V_10 , V_8 -> V_9 , 3 ) ;
F_8 ( & V_8 -> V_12 ) ;
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_11 ;
V_11 = F_11 ( V_8 -> V_10 , F_12 ( V_3 ) ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_10 -> V_2 , L_1 ,
V_3 ) ;
return V_11 ;
}
* V_4 = V_11 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_11 ;
V_11 = F_15 ( V_8 -> V_10 , F_12 ( V_3 ) ) ;
if ( V_11 < 0 ) {
F_13 ( & V_8 -> V_10 -> V_2 , L_2 ,
V_3 ) ;
return V_11 ;
}
* V_4 = V_11 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_3 , T_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_11 ;
struct V_14 V_15 [] = {
{
. V_16 = V_8 -> V_9 ,
. V_17 = V_8 -> V_18 ,
. V_19 = 8 ,
. V_20 = 4 ,
} ,
} ;
F_7 ( & V_8 -> V_12 ) ;
V_8 -> V_9 [ 0 ] = F_12 ( V_3 ) ;
V_8 -> V_9 [ 1 ] = 0 ;
V_8 -> V_9 [ 2 ] = 0 ;
V_8 -> V_9 [ 3 ] = 0 ;
V_11 = F_17 ( V_8 -> V_10 , V_15 , F_18 ( V_15 ) ) ;
if ( V_11 ) {
F_13 ( & V_8 -> V_10 -> V_2 , L_3 ,
V_3 ) ;
goto V_21;
}
* V_4 = ( V_8 -> V_18 [ 1 ] << 16 ) | ( V_8 -> V_18 [ 2 ] << 8 ) | V_8 -> V_18 [ 3 ] ;
V_21:
F_8 ( & V_8 -> V_12 ) ;
return V_11 ;
}
static T_4 F_19 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_11 ;
T_1 V_4 = 0 ;
struct V_25 * V_26 = F_20 ( V_23 ) ;
V_11 = F_10 ( V_2 , V_26 -> V_27 , & V_4 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_24 , L_4 , V_4 ) ;
}
static T_4 F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_11 ;
T_2 V_4 = 0 ;
struct V_25 * V_26 = F_20 ( V_23 ) ;
V_11 = F_14 ( V_2 , V_26 -> V_27 , & V_4 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_24 , L_4 , V_4 ) ;
}
static T_4 F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_11 ;
T_3 V_4 = 0 ;
struct V_25 * V_26 = F_20 ( V_23 ) ;
V_11 = F_16 ( V_2 , V_26 -> V_27 , & V_4 ) ;
if ( V_11 )
return V_11 ;
return sprintf ( V_24 , L_4 , V_4 & 0xFFFFFF ) ;
}
static T_4 F_23 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_5 V_20 )
{
struct V_25 * V_26 = F_20 ( V_23 ) ;
int V_11 ;
T_1 V_4 ;
V_11 = F_24 ( V_24 , 10 , & V_4 ) ;
if ( V_11 )
goto V_21;
V_11 = F_6 ( V_2 , V_26 -> V_27 , V_4 ) ;
V_21:
return V_11 ? V_11 : V_20 ;
}
static T_4 F_25 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_5 V_20 )
{
struct V_25 * V_26 = F_20 ( V_23 ) ;
int V_11 ;
T_2 V_4 ;
V_11 = F_26 ( V_24 , 10 , & V_4 ) ;
if ( V_11 )
goto V_21;
V_11 = F_9 ( V_2 , V_26 -> V_27 , V_4 ) ;
V_21:
return V_11 ? V_11 : V_20 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_4 ;
V_11 = F_10 ( V_2 , V_28 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 |= F_28 ( 6 ) ;
return F_6 ( V_2 , V_28 , V_4 ) ;
}
static int F_29 ( struct V_1 * V_2 , bool V_29 )
{
int V_11 ;
T_2 V_30 ;
V_11 = F_14 ( V_2 , V_31 , & V_30 ) ;
if ( V_11 )
return V_11 ;
if ( V_29 )
V_30 |= F_28 ( 14 ) ;
else
V_30 &= ~ F_28 ( 14 ) ;
return F_9 ( V_2 , V_31 , V_30 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_4 ;
V_11 = F_10 ( V_2 , V_28 , & V_4 ) ;
if ( V_11 < 0 ) {
F_13 ( V_2 , L_5 ,
V_11 ) ;
return V_11 ;
}
V_4 |= 7 << 3 ;
return F_6 ( V_2 , V_28 , V_4 ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
int V_11 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_8 -> V_10 -> V_32 = V_33 ;
F_32 ( V_8 -> V_10 ) ;
V_11 = F_29 ( V_2 , false ) ;
if ( V_11 ) {
F_13 ( V_2 , L_6 ) ;
goto V_34;
}
F_27 ( V_2 ) ;
F_33 ( V_35 , V_35 + 100 ) ;
V_34:
return V_11 ;
}
static T_4 F_34 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_11 ;
T_1 V_36 ;
int V_37 ;
V_11 = F_10 ( V_2 , V_38 , & V_36 ) ;
if ( V_11 )
return V_11 ;
V_36 = ( V_36 >> 3 ) & 0x3 ;
V_37 = 26000 / ( 1 + V_36 ) ;
return sprintf ( V_24 , L_7 , V_37 ) ;
}
static T_4 F_35 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_5 V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_2 V_4 ;
int V_11 ;
T_1 V_39 , V_36 ;
V_11 = F_26 ( V_24 , 10 , & V_4 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_4 )
return - V_40 ;
F_7 ( & V_8 -> V_12 ) ;
V_36 = 26000 / V_4 ;
if ( V_36 > 0 )
V_36 -- ;
if ( V_36 > 1 )
V_8 -> V_10 -> V_41 = V_42 ;
else
V_8 -> V_10 -> V_41 = V_43 ;
V_11 = F_10 ( V_2 , V_38 , & V_39 ) ;
if ( V_11 )
goto V_44;
V_39 &= ~ ( 3 << 3 ) ;
V_39 |= V_36 << 3 ;
V_11 = F_1 ( V_2 , V_38 , V_39 ) ;
V_44:
F_8 ( & V_8 -> V_12 ) ;
return V_11 ? V_11 : V_20 ;
}
static int F_36 ( struct V_45 * V_46 )
{
int V_11 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
V_6 = F_37 ( & V_46 -> V_2 , sizeof( * V_8 ) ) ;
if ( ! V_6 )
return - V_47 ;
F_38 ( V_46 , V_6 ) ;
V_8 = F_3 ( V_6 ) ;
V_8 -> V_10 = V_46 ;
F_39 ( & V_8 -> V_12 ) ;
V_6 -> V_48 = V_46 -> V_2 . V_49 -> V_48 ;
V_6 -> V_2 . V_50 = & V_46 -> V_2 ;
V_6 -> V_51 = & V_52 ;
V_6 -> V_53 = V_54 ;
V_11 = F_31 ( V_6 ) ;
if ( V_11 )
goto V_55;
V_11 = F_40 ( V_6 ) ;
if ( V_11 )
goto V_55;
return V_11 ;
V_55:
F_30 ( & V_6 -> V_2 ) ;
return V_11 ;
}
static int F_41 ( struct V_45 * V_46 )
{
struct V_5 * V_6 = F_42 ( V_46 ) ;
F_43 ( V_6 ) ;
F_30 ( & V_6 -> V_2 ) ;
return 0 ;
}
