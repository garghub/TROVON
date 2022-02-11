static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
return F_3 ( V_2 -> V_5 , & V_4 , sizeof( V_4 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_4 [ 3 ] ;
V_4 [ 0 ] = ( V_3 >> 16 ) & 0xFF ;
V_4 [ 1 ] = ( V_3 >> 8 ) & 0xFF ;
V_4 [ 2 ] = V_3 & 0xFF ;
return F_3 ( V_2 -> V_5 , V_4 , sizeof( V_4 ) ) ;
}
static int F_5 ( struct V_6 * V_7 ,
const struct V_8 * V_9 , unsigned int V_10 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_11 = V_10 + 1 ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_11 - 1 ;
}
static T_3 F_8 ( struct V_6 * V_7 ,
T_4 V_12 ,
const struct V_8 * V_9 ,
char * V_13 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return sprintf ( V_13 , L_1 , V_2 -> V_14 ) ;
}
static T_3 F_9 ( struct V_6 * V_7 ,
T_4 V_12 ,
const struct V_8 * V_9 ,
const char * V_13 , T_5 V_15 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned int V_16 ;
unsigned int V_3 ;
bool V_17 ;
int V_18 ;
V_18 = F_10 ( V_13 , & V_17 ) ;
if ( V_18 )
return V_18 ;
F_11 ( & V_7 -> V_19 ) ;
V_2 -> V_14 = V_17 ;
if ( V_2 -> V_14 ) {
V_16 = V_9 -> V_20 . V_21 + V_9 -> V_20 . V_16 ;
V_3 = V_2 -> V_11 << V_16 ;
} else {
V_3 = V_2 -> V_22 ;
}
V_18 = V_2 -> V_23 -> V_24 ( V_2 , V_3 ) ;
F_12 ( & V_7 -> V_19 ) ;
return V_18 ? V_18 : V_15 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_8 const * V_9 ,
int * V_3 ,
int * V_25 ,
long V_26 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_27 ;
switch ( V_26 ) {
case V_28 :
* V_3 = V_2 -> V_22 ;
return V_29 ;
case V_30 :
V_27 = ( V_2 -> V_31 * 1000 ) >> V_9 -> V_20 . V_21 ;
* V_3 = V_27 / 1000 ;
* V_25 = ( V_27 % 1000 ) * 1000 ;
return V_32 ;
}
return - V_33 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_8 const * V_9 ,
int V_3 ,
int V_25 ,
long V_34 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_18 = 0 ;
switch ( V_34 ) {
case V_28 :
if ( V_3 >= ( 1 << V_9 -> V_20 . V_21 ) || V_3 < 0 )
return - V_33 ;
V_3 <<= V_9 -> V_20 . V_16 ;
F_11 ( & V_7 -> V_19 ) ;
V_2 -> V_22 = V_3 ;
if ( ! V_2 -> V_14 )
V_18 = V_2 -> V_23 -> V_24 ( V_2 , V_3 ) ;
F_12 ( & V_7 -> V_19 ) ;
break;
default:
V_18 = - V_33 ;
}
return V_18 ;
}
static int T_6 F_15 ( struct V_35 * V_5 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_36 * V_37 ;
int V_18 , V_38 = 0 ;
V_37 = F_16 ( & V_5 -> V_39 , L_2 ) ;
if ( ! F_17 ( V_37 ) ) {
V_18 = F_18 ( V_37 ) ;
if ( V_18 )
goto V_40;
V_38 = F_19 ( V_37 ) ;
}
V_7 = F_20 ( sizeof( * V_2 ) ) ;
if ( V_7 == NULL ) {
V_18 = - V_41 ;
goto V_42;
}
V_2 = F_6 ( V_7 ) ;
V_2 -> V_23 =
& V_43 [ F_21 ( V_5 ) -> V_44 ] ;
F_22 ( V_5 , V_7 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_5 = V_5 ;
V_7 -> V_39 . V_45 = & V_5 -> V_39 ;
V_7 -> V_46 = F_21 ( V_5 ) -> V_46 ;
V_7 -> V_47 = & V_48 ;
V_7 -> V_49 = V_50 ;
V_7 -> V_51 = & V_2 -> V_23 -> V_52 ;
V_7 -> V_53 = 1 ;
V_2 -> V_11 = V_54 ;
if ( V_2 -> V_23 -> V_55 )
V_2 -> V_31 = V_2 -> V_23 -> V_55 ;
else if ( V_38 )
V_2 -> V_31 = V_38 / 1000 ;
else
F_23 ( & V_5 -> V_39 , L_3 ) ;
V_18 = F_24 ( V_7 ) ;
if ( V_18 )
goto V_56;
return 0 ;
V_56:
F_25 ( V_7 ) ;
V_42:
if ( ! F_17 ( V_37 ) )
F_26 ( V_37 ) ;
V_40:
if ( ! F_17 ( V_37 ) )
F_27 ( V_37 ) ;
return V_18 ;
}
static int F_28 ( struct V_35 * V_5 )
{
struct V_6 * V_7 = F_29 ( V_5 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_30 ( V_7 ) ;
if ( ! F_17 ( V_2 -> V_37 ) ) {
F_26 ( V_2 -> V_37 ) ;
F_27 ( V_2 -> V_37 ) ;
}
F_25 ( V_7 ) ;
return 0 ;
}
