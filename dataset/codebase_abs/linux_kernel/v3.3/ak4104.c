static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_8 -> V_9 ; V_3 ++ ) {
int V_10 = F_2 ( V_6 , V_3 | V_11 ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_1 ) ;
return V_10 ;
}
V_4 [ V_3 ] = V_10 ;
}
return 0 ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
T_1 * V_4 = V_2 -> V_4 ;
if ( V_13 >= V_2 -> V_8 -> V_9 )
return - V_14 ;
return V_4 [ V_13 ] ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_13 ,
unsigned int V_15 )
{
T_1 * V_16 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_13 >= V_2 -> V_8 -> V_9 )
return - V_14 ;
if ( V_16 [ V_13 ] != V_15 ) {
T_1 V_17 [ 2 ] = { ( V_13 & V_18 ) | V_19 , V_15 } ;
if ( F_6 ( V_6 , V_17 , sizeof( V_17 ) ) ) {
F_3 ( & V_6 -> V_12 , L_2 ) ;
return - V_20 ;
}
V_16 [ V_13 ] = V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_21 * V_22 ,
unsigned int V_23 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
int V_24 = 0 ;
V_24 = F_4 ( V_2 , V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 &= ~ ( V_26 | V_27 ) ;
switch ( V_23 & V_28 ) {
case V_29 :
break;
case V_30 :
V_24 |= V_26 ;
break;
case V_31 :
V_24 |= V_26 | V_27 ;
break;
default:
F_3 ( V_2 -> V_12 , L_3 ) ;
return - V_14 ;
}
if ( ( V_23 & V_32 ) != V_33 )
return - V_14 ;
return F_5 ( V_2 , V_25 , V_24 ) ;
}
static int F_8 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_21 * V_38 )
{
struct V_39 * V_40 = V_35 -> V_41 ;
struct V_1 * V_2 = V_40 -> V_2 ;
int V_24 = 0 ;
V_24 |= V_42 ;
F_5 ( V_2 , F_9 ( 0 ) , V_24 ) ;
V_24 = 0 ;
switch ( F_10 ( V_37 ) ) {
case 44100 :
V_24 |= V_43 ;
break;
case 48000 :
V_24 |= V_44 ;
break;
case 32000 :
V_24 |= V_45 ;
break;
default:
F_3 ( V_2 -> V_12 , L_4 ) ;
return - V_14 ;
}
return F_5 ( V_2 , F_9 ( 3 ) , V_24 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_12 ( V_2 ) ;
int V_10 , V_24 ;
V_2 -> V_7 = V_47 -> V_7 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 ) {
F_3 ( V_2 -> V_12 , L_5 ) ;
return V_10 ;
}
if ( F_4 ( V_2 , V_48 ) !=
V_49 )
return - V_50 ;
V_24 = F_4 ( V_2 , V_25 ) ;
V_24 |= V_51 | V_52 ;
V_10 = F_5 ( V_2 , V_25 , V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
V_24 = F_4 ( V_2 , V_53 ) ;
V_24 |= V_54 ;
V_10 = F_5 ( V_2 , V_53 , V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
F_13 ( V_2 -> V_12 , L_6 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_24 , V_10 ;
V_24 = F_4 ( V_2 , V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 &= ~ ( V_51 | V_52 ) ;
V_10 = F_5 ( V_2 , V_25 , V_24 ) ;
return V_10 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_46 * V_47 ;
int V_10 ;
V_6 -> V_55 = 8 ;
V_6 -> V_56 = V_57 ;
V_10 = F_16 ( V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
V_47 = F_17 ( & V_6 -> V_12 , sizeof( struct V_46 ) ,
V_58 ) ;
if ( V_47 == NULL )
return - V_59 ;
V_47 -> V_7 = V_6 ;
V_47 -> V_60 = V_61 ;
F_18 ( V_6 , V_47 ) ;
V_10 = F_19 ( & V_6 -> V_12 ,
& V_62 , & V_63 , 1 ) ;
return V_10 ;
}
static int T_2 F_20 ( struct V_5 * V_6 )
{
F_21 ( & V_6 -> V_12 ) ;
return 0 ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_64 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_64 ) ;
}
