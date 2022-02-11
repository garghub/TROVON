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
static int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
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
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_4 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
struct V_14 V_15 [] = {
{
. V_16 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 1 ,
} , {
. V_19 = V_9 -> V_11 ,
. V_17 = 8 ,
. V_18 = 3 ,
}
} ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = F_11 ( V_3 ) ;
V_5 = F_16 ( V_9 -> V_12 , V_15 , F_17 ( V_15 ) ) ;
if ( V_5 ) {
F_12 ( & V_9 -> V_12 -> V_2 , L_3 ,
V_3 ) ;
goto V_20;
}
* V_4 = ( V_9 -> V_21 [ 0 ] << 16 ) | ( V_9 -> V_21 [ 1 ] << 8 ) | V_9 -> V_21 [ 2 ] ;
V_20:
F_7 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static T_3 F_18 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_5 ;
T_1 V_4 ;
struct V_25 * V_26 = F_19 ( V_23 ) ;
V_5 = F_9 ( V_2 , V_26 -> V_27 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_24 , L_4 , V_4 ) ;
}
static T_3 F_20 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_5 ;
T_2 V_4 ;
struct V_25 * V_26 = F_19 ( V_23 ) ;
V_5 = F_13 ( V_2 , V_26 -> V_27 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_24 , L_4 , V_4 ) ;
}
static T_3 F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_5 ;
T_4 V_4 ;
struct V_25 * V_26 = F_19 ( V_23 ) ;
V_5 = F_15 ( V_2 , V_26 -> V_27 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return sprintf ( V_24 , L_4 , V_4 ) ;
}
static T_3 F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_5 V_18 )
{
struct V_25 * V_26 = F_19 ( V_23 ) ;
int V_5 ;
T_1 V_4 ;
V_5 = F_23 ( V_24 , 10 , & V_4 ) ;
if ( V_5 )
goto V_20;
V_5 = F_1 ( V_2 , V_26 -> V_27 , V_4 ) ;
V_20:
return V_5 ? V_5 : V_18 ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_5 V_18 )
{
struct V_25 * V_26 = F_19 ( V_23 ) ;
int V_5 ;
T_2 V_4 ;
V_5 = F_25 ( V_24 , 10 , & V_4 ) ;
if ( V_5 )
goto V_20;
V_5 = F_8 ( V_2 , V_26 -> V_27 , V_4 ) ;
V_20:
return V_5 ? V_5 : V_18 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_13 ( V_2 , V_28 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 |= F_27 ( 6 ) ;
return F_8 ( V_2 , V_28 , V_4 ) ;
}
static int F_28 ( struct V_1 * V_2 , bool V_29 )
{
int V_5 ;
T_1 V_30 ;
V_5 = F_9 ( V_2 , V_31 , & V_30 ) ;
if ( V_5 )
goto V_20;
if ( V_29 )
V_30 |= F_27 ( 3 ) ;
else
V_30 &= ~ F_27 ( 3 ) ;
V_5 = F_1 ( V_2 , V_31 , V_30 ) ;
V_20:
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_13 ( V_2 , V_28 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 |= F_27 ( 4 ) ;
return F_8 ( V_2 , V_28 , V_4 ) ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_5 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
V_9 -> V_12 -> V_32 = V_33 ;
F_31 ( V_9 -> V_12 ) ;
V_5 = F_28 ( V_2 , false ) ;
if ( V_5 ) {
F_12 ( V_2 , L_5 ) ;
goto V_34;
}
F_26 ( V_2 ) ;
F_32 ( V_35 , V_35 + 100 ) ;
V_34:
return V_5 ;
}
static T_3 F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_24 )
{
int V_5 ;
T_2 V_36 ;
int V_37 ;
V_5 = F_13 ( V_2 , V_28 , & V_36 ) ;
if ( V_5 )
return V_5 ;
V_36 = ( V_36 >> 11 ) & 0x3 ;
V_37 = 27900 / ( 1 + V_36 ) ;
return sprintf ( V_24 , L_6 , V_37 ) ;
}
static T_3 F_34 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_5 V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_2 V_4 ;
int V_5 ;
T_2 V_38 , V_36 ;
V_5 = F_25 ( V_24 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_4 )
return - V_39 ;
F_4 ( & V_7 -> V_40 ) ;
V_36 = 27900 / V_4 ;
if ( V_36 > 0 )
V_36 -- ;
if ( V_36 > 1 )
V_9 -> V_12 -> V_41 = V_42 ;
else
V_9 -> V_12 -> V_41 = V_43 ;
V_5 = F_13 ( V_2 , V_28 , & V_38 ) ;
if ( V_5 )
goto V_44;
V_38 &= ~ ( 3 << 11 ) ;
V_38 |= V_36 << 11 ;
V_5 = F_8 ( V_2 , V_28 , V_38 ) ;
V_44:
F_7 ( & V_7 -> V_40 ) ;
return V_5 ? V_5 : V_18 ;
}
static int F_35 ( struct V_45 * V_46 )
{
int V_5 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_7 = F_36 ( & V_46 -> V_2 , sizeof( * V_9 ) ) ;
if ( ! V_7 )
return - V_47 ;
F_37 ( V_46 , V_7 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 -> V_12 = V_46 ;
F_38 ( & V_9 -> V_10 ) ;
V_7 -> V_48 = V_46 -> V_2 . V_49 -> V_48 ;
V_7 -> V_2 . V_50 = & V_46 -> V_2 ;
V_7 -> V_51 = & V_52 ;
V_7 -> V_53 = V_54 ;
V_5 = F_30 ( V_7 ) ;
if ( V_5 )
return V_5 ;
return F_39 ( V_7 ) ;
}
static int F_40 ( struct V_45 * V_46 )
{
struct V_6 * V_7 = F_41 ( V_46 ) ;
F_42 ( V_7 ) ;
F_29 ( & V_7 -> V_2 ) ;
return 0 ;
}
