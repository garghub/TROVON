static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_7 [ V_4 -> V_8 ] ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 [ V_4 -> V_8 ] = V_9 ;
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
T_2 V_10 ,
const struct V_3 * V_4 ,
char * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_11 , L_1 , V_6 -> V_12 [ V_4 -> V_8 ] ) ;
}
static int F_5 ( struct V_5 * V_13 ,
const struct V_3 * V_4 )
{
T_3 V_14 [ 2 ] ;
V_14 [ 0 ] = V_15 ;
if ( V_4 -> V_8 == 0 )
V_14 [ 1 ] = V_16 ;
else
V_14 [ 1 ] = V_17 ;
if ( V_13 -> V_12 [ V_4 -> V_8 ] )
V_14 [ 1 ] |= V_13 -> V_7 [ V_4 -> V_8 ] + 1 ;
else
V_14 [ 1 ] |= V_18 ;
return F_6 ( V_13 -> V_19 , V_14 , 2 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
T_2 V_10 ,
const struct V_3 * V_4 ,
const char * V_11 , T_4 V_20 )
{
struct V_5 * V_13 = F_2 ( V_2 ) ;
bool V_12 ;
int V_21 ;
V_21 = F_8 ( V_11 , & V_12 ) ;
if ( V_21 )
return V_21 ;
V_13 -> V_12 [ V_4 -> V_8 ] = V_12 ;
V_21 = F_5 ( V_13 , V_4 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 ,
int * V_22 , int V_8 )
{
struct V_5 * V_13 = F_2 ( V_2 ) ;
struct V_23 * V_19 = V_13 -> V_19 ;
T_3 V_14 [ 1 ] ;
T_3 V_24 [ 2 ] ;
int V_21 ;
if ( ( V_8 != 0 ) && ( V_8 != 1 ) )
return - V_25 ;
V_14 [ 0 ] = V_26 [ V_8 ] ;
F_10 ( & V_13 -> V_27 ) ;
V_21 = F_6 ( V_19 , V_14 , 1 ) ;
if ( V_21 < 0 ) {
F_11 ( & V_13 -> V_27 ) ;
return V_21 ;
} else if ( V_21 != 1 ) {
F_11 ( & V_13 -> V_27 ) ;
return - V_28 ;
}
V_21 = F_12 ( V_19 , V_24 , 2 ) ;
if ( V_21 < 0 ) {
F_11 ( & V_13 -> V_27 ) ;
return V_21 ;
} else if ( V_21 != 2 ) {
F_11 ( & V_13 -> V_27 ) ;
return - V_28 ;
}
F_11 ( & V_13 -> V_27 ) ;
* V_22 = ( ( V_24 [ 0 ] & 0x0f ) << 6 ) | ( V_24 [ 1 ] >> 2 ) ;
return V_29 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_22 , int V_8 )
{
struct V_5 * V_13 = F_2 ( V_2 ) ;
struct V_23 * V_19 = V_13 -> V_19 ;
T_3 V_14 [ 2 ] ;
int V_21 ;
if ( ( V_22 < 0 ) || ( V_22 > 1023 ) )
return - V_25 ;
if ( ( V_8 != 0 ) && ( V_8 != 1 ) )
return - V_25 ;
V_14 [ 0 ] = V_30 [ V_8 ] ;
V_14 [ 0 ] |= V_22 >> 6 ;
V_14 [ 1 ] = ( V_22 & 0x3f ) << 2 ;
V_21 = F_6 ( V_19 , V_14 , 2 ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 != 2 )
return - V_28 ;
else
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_22 , int * V_31 , long V_32 )
{
struct V_5 * V_13 = F_2 ( V_2 ) ;
switch ( V_32 ) {
case V_33 :
return F_9 ( V_2 , V_22 , V_4 -> V_8 ) ;
case V_34 :
* V_22 = V_13 -> V_35 ;
* V_31 = 10 ;
return V_36 ;
default:
return - V_25 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_22 , int V_31 , long V_32 )
{
if ( V_31 != 0 )
return - V_25 ;
switch ( V_32 ) {
case V_33 :
return F_13 ( V_2 , V_22 , V_4 -> V_8 ) ;
default:
return - V_25 ;
}
}
static int F_16 ( struct V_37 * V_38 )
{
T_3 V_14 [ 2 ] = { V_15 ,
V_16 |
V_17 |
V_39 } ;
return F_6 ( F_17 ( V_38 ) , V_14 , 2 ) ;
}
static int F_18 ( struct V_37 * V_38 )
{
T_3 V_14 [ 2 ] = { V_15 ,
V_16 |
V_17 |
V_18 } ;
return F_6 ( F_17 ( V_38 ) , V_14 , 2 ) ;
}
static int F_19 ( struct V_23 * V_19 ,
const struct V_40 * V_41 )
{
struct V_5 * V_13 ;
struct V_1 * V_2 ;
T_5 V_42 ;
int V_21 ;
V_2 = F_20 ( & V_19 -> V_38 , sizeof( * V_13 ) ) ;
if ( ! V_2 )
return - V_43 ;
V_13 = F_2 ( V_2 ) ;
F_21 ( V_19 , V_2 ) ;
V_13 -> V_19 = V_19 ;
F_22 ( & V_13 -> V_27 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
V_13 -> V_12 [ V_42 ] = true ;
V_13 -> V_7 [ V_42 ] = V_45 ;
}
V_13 -> V_46 = F_23 ( & V_19 -> V_38 , L_2 ) ;
if ( F_24 ( V_13 -> V_46 ) ) {
V_21 = F_25 ( V_13 -> V_46 ) ;
F_26 ( & V_19 -> V_38 ,
L_3 , V_21 ) ;
goto V_47;
}
V_21 = F_27 ( V_13 -> V_46 ) ;
if ( V_21 ) {
F_26 ( & V_19 -> V_38 ,
L_4 , V_21 ) ;
goto V_47;
}
V_21 = F_28 ( V_13 -> V_46 ) ;
if ( V_21 < 0 ) {
F_26 ( & V_19 -> V_38 ,
L_5 , V_21 ) ;
goto V_48;
}
V_13 -> V_35 = V_21 / 1000 ;
V_2 -> V_49 = V_41 -> V_49 ;
V_2 -> V_38 . V_50 = & V_19 -> V_38 ;
V_2 -> V_51 = F_29 ( V_52 ) ;
V_2 -> V_53 = V_52 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = & V_57 ;
return F_30 ( V_2 ) ;
V_48:
F_31 ( V_13 -> V_46 ) ;
V_47:
return V_21 ;
}
static int F_32 ( struct V_23 * V_19 )
{
struct V_1 * V_2 = F_33 ( V_19 ) ;
struct V_5 * V_13 = F_2 ( V_2 ) ;
F_34 ( V_2 ) ;
F_31 ( V_13 -> V_46 ) ;
return 0 ;
}
