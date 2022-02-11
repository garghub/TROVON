static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
T_2 V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 * V_13 = F_4 ( V_4 ) ;
V_6 = V_11 -> V_14 ( V_2 , V_13 -> V_15 , & V_7 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_5 , L_1 , V_7 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
T_3 V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 * V_13 = F_4 ( V_4 ) ;
V_6 = V_11 -> V_16 ( V_2 , V_13 -> V_15 , & V_7 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_5 , L_1 , V_7 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
T_4 V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_12 * V_13 = F_4 ( V_4 ) ;
V_6 = V_11 -> V_17 ( V_2 , V_13 -> V_15 , & V_7 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_5 , L_1 , V_7 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
T_4 V_7 = 0 ;
struct V_12 * V_13 = F_4 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
V_6 = V_11 -> V_18 ( V_2 , V_13 -> V_15 , & V_7 ) ;
if ( V_6 )
return V_6 ;
return sprintf ( V_5 , L_1 , V_7 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_5 V_19 )
{
struct V_12 * V_13 = F_4 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_6 ;
long V_7 ;
V_6 = F_9 ( V_5 , 10 , & V_7 ) ;
if ( V_6 )
goto V_20;
V_6 = V_11 -> V_21 ( V_2 , V_13 -> V_15 , V_7 ) ;
V_20:
return V_6 ? V_6 : V_19 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_5 V_19 )
{
struct V_12 * V_13 = F_4 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_6 ;
long V_7 ;
V_6 = F_9 ( V_5 , 10 , & V_7 ) ;
if ( V_6 )
goto V_20;
V_6 = V_11 -> V_22 ( V_2 , V_13 -> V_15 , V_7 ) ;
V_20:
return V_6 ? V_6 : V_19 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_5 V_19 )
{
struct V_12 * V_13 = F_4 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_6 ;
long V_7 ;
V_6 = F_9 ( V_5 , 10 , & V_7 ) ;
if ( V_6 )
goto V_20;
V_6 = V_11 -> V_23 ( V_2 , V_13 -> V_15 , V_7 ) ;
V_20:
return V_6 ? V_6 : V_19 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_5 V_19 )
{
struct V_12 * V_13 = F_4 ( V_4 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_6 ;
long V_7 ;
V_6 = F_9 ( V_5 , 10 , & V_7 ) ;
if ( V_6 )
goto V_20;
V_6 = V_11 -> V_24 ( V_2 , V_13 -> V_15 , V_7 ) ;
V_20:
return V_6 ? V_6 : V_19 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
T_3 V_7 ;
V_11 -> V_16 ( V_2 , V_25 , & V_7 ) ;
V_7 |= 1 << 7 ;
return V_11 -> V_22 ( V_2 , V_25 , V_7 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_5 V_19 )
{
if ( V_19 < 1 )
return - 1 ;
switch ( V_5 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_13 ( V_2 ) ;
}
return - 1 ;
}
static int F_15 ( struct V_1 * V_2 , bool V_26 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
int V_6 ;
T_4 V_27 ;
V_6 = V_11 -> V_18 ( V_2 , V_28 , & V_27 ) ;
if ( V_6 )
goto V_20;
if ( V_26 )
V_27 |= 1 << 17 ;
else
V_27 &= ~ ( 1 << 17 ) ;
V_6 = V_11 -> V_24 ( V_2 , V_28 , V_27 ) ;
if ( V_6 )
goto V_20;
V_20:
return V_6 ;
}
static int F_16 ( struct V_8 * V_9 )
{
int V_6 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
V_6 = F_15 ( V_2 , false ) ;
if ( V_6 ) {
F_17 ( V_2 , L_2 ) ;
goto V_29;
}
F_13 ( V_2 ) ;
F_18 ( V_30 ) ;
V_29:
return V_6 ;
}
int F_19 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_6 ;
struct V_10 * V_11 = F_3 ( V_9 ) ;
F_20 ( & V_11 -> V_31 ) ;
V_9 -> V_2 . V_32 = V_2 ;
V_9 -> V_33 = & V_34 ;
V_9 -> V_35 = V_36 ;
V_6 = F_21 ( V_9 ) ;
if ( V_6 )
goto V_37;
V_6 = F_16 ( V_9 ) ;
if ( V_6 )
goto V_38;
return 0 ;
V_38:
F_22 ( V_9 ) ;
V_37:
F_23 ( V_9 ) ;
V_20:
return V_6 ;
}
int F_24 ( struct V_8 * V_9 )
{
F_22 ( V_9 ) ;
return 0 ;
}
