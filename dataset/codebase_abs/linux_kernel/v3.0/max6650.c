static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = ( ( V_9 -> V_11 [ V_7 -> V_12 ] * 120 ) / F_4 ( V_9 -> V_13 ) ) ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_14 , V_15 , V_10 ;
V_14 = F_4 ( V_9 -> V_16 ) ;
V_15 = V_9 -> V_17 ;
V_10 = 60 * V_14 * clock / ( 256 * ( V_15 + 1 ) ) ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
int V_10 = F_9 ( V_5 , NULL , 10 ) ;
int V_14 , V_15 ;
V_10 = F_10 ( V_10 , V_20 , V_21 ) ;
F_11 ( & V_9 -> V_22 ) ;
V_14 = F_4 ( V_9 -> V_16 ) ;
V_15 = ( ( clock * V_14 ) / ( 256 * V_10 / 60 ) ) - 1 ;
if ( V_15 < 0 )
V_15 = 0 ;
if ( V_15 > 255 )
V_15 = 255 ;
V_9 -> V_17 = V_15 ;
F_12 ( V_19 , V_23 , V_9 -> V_17 ) ;
F_13 ( & V_9 -> V_22 ) ;
return V_13 ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_24 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( V_9 -> V_16 & V_25 )
V_24 = 255 - ( 255 * ( int ) V_9 -> V_26 ) / 180 ;
else
V_24 = 255 - ( 255 * ( int ) V_9 -> V_26 ) / 76 ;
if ( V_24 < 0 )
V_24 = 0 ;
return sprintf ( V_5 , L_1 , V_24 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
int V_24 = F_9 ( V_5 , NULL , 10 ) ;
V_24 = F_10 ( V_24 , 0 , 255 ) ;
F_11 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_16 & V_25 )
V_9 -> V_26 = 180 - ( 180 * V_24 ) / 255 ;
else
V_9 -> V_26 = 76 - ( 76 * V_24 ) / 255 ;
F_12 ( V_19 , V_27 , V_9 -> V_26 ) ;
F_13 ( & V_9 -> V_22 ) ;
return V_13 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_28 = ( V_9 -> V_16 & V_29 ) >> 4 ;
int V_30 [ 4 ] = { 0 , 1 , 2 , 1 } ;
return sprintf ( V_5 , L_1 , V_30 [ V_28 ] ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
int V_28 = F_9 ( V_5 , NULL , 10 ) ;
int V_31 [ 3 ] = { 0 , 3 , 2 } ;
if ( ( V_28 < 0 ) || ( V_28 > 2 ) ) {
F_18 ( & V_19 -> V_2 ,
L_2 , V_28 ) ;
return - V_32 ;
}
F_11 ( & V_9 -> V_22 ) ;
V_9 -> V_16 = F_19 ( V_19 , V_33 ) ;
V_9 -> V_16 = ( V_9 -> V_16 & ~ V_29 )
| ( V_31 [ V_28 ] << 4 ) ;
F_12 ( V_19 , V_33 , V_9 -> V_16 ) ;
F_13 ( & V_9 -> V_22 ) ;
return V_13 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_13 ) ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
int div = F_9 ( V_5 , NULL , 10 ) ;
F_11 ( & V_9 -> V_22 ) ;
switch ( div ) {
case 1 :
V_9 -> V_13 = 0 ;
break;
case 2 :
V_9 -> V_13 = 1 ;
break;
case 4 :
V_9 -> V_13 = 2 ;
break;
case 8 :
V_9 -> V_13 = 3 ;
break;
default:
F_13 ( & V_9 -> V_22 ) ;
F_18 ( & V_19 -> V_2 ,
L_3 , div ) ;
return - V_32 ;
}
F_12 ( V_19 , V_34 , V_9 -> V_13 ) ;
F_13 ( & V_9 -> V_22 ) ;
return V_13 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
int V_35 = 0 ;
if ( V_9 -> V_35 & V_7 -> V_12 ) {
F_11 ( & V_9 -> V_22 ) ;
V_35 = 1 ;
V_9 -> V_35 &= ~ V_7 -> V_12 ;
V_9 -> V_35 |= F_19 ( V_19 ,
V_36 ) ;
F_13 ( & V_9 -> V_22 ) ;
}
return sprintf ( V_5 , L_1 , V_35 ) ;
}
static T_3 F_23 ( struct V_37 * V_38 , struct V_39 * V_40 ,
int V_41 )
{
struct V_1 * V_2 = F_24 ( V_38 , struct V_1 , V_38 ) ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
T_4 V_42 = F_19 ( V_19 , V_43 ) ;
struct V_3 * V_4 ;
V_4 = F_24 ( V_40 , struct V_3 , V_7 ) ;
if ( V_4 == & V_44 . V_45
|| V_4 == & V_46 . V_45
|| V_4 == & V_47 . V_45
|| V_4 == & V_48 . V_45
|| V_4 == & V_49 . V_45 ) {
if ( ! ( V_42 & F_2 ( V_4 ) -> V_12 ) )
return 0 ;
}
return V_40 -> V_28 ;
}
static int F_25 ( struct V_18 * V_19 ,
const struct V_50 * V_51 )
{
struct V_8 * V_9 ;
int V_52 ;
if ( ! ( V_9 = F_26 ( sizeof( struct V_8 ) , V_53 ) ) ) {
F_18 ( & V_19 -> V_2 , L_4 ) ;
return - V_54 ;
}
F_27 ( V_19 , V_9 ) ;
F_28 ( & V_9 -> V_22 ) ;
V_9 -> V_55 = V_51 -> V_56 ;
V_52 = F_29 ( V_19 ) ;
if ( V_52 )
goto V_57;
V_52 = F_30 ( & V_19 -> V_2 . V_38 , & V_58 ) ;
if ( V_52 )
goto V_57;
if ( V_9 -> V_55 == 4 ) {
V_52 = F_30 ( & V_19 -> V_2 . V_38 , & V_59 ) ;
if ( V_52 )
goto V_60;
}
V_9 -> V_61 = F_31 ( & V_19 -> V_2 ) ;
if ( ! F_32 ( V_9 -> V_61 ) )
return 0 ;
V_52 = F_33 ( V_9 -> V_61 ) ;
F_18 ( & V_19 -> V_2 , L_5 ) ;
if ( V_9 -> V_55 == 4 )
F_34 ( & V_19 -> V_2 . V_38 , & V_59 ) ;
V_60:
F_34 ( & V_19 -> V_2 . V_38 , & V_58 ) ;
V_57:
F_35 ( V_9 ) ;
return V_52 ;
}
static int F_36 ( struct V_18 * V_19 )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
F_37 ( V_9 -> V_61 ) ;
if ( V_9 -> V_55 == 4 )
F_34 ( & V_19 -> V_2 . V_38 , & V_59 ) ;
F_34 ( & V_19 -> V_2 . V_38 , & V_58 ) ;
F_35 ( V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
int V_16 ;
int V_52 = - V_62 ;
V_16 = F_19 ( V_19 , V_33 ) ;
if ( V_16 < 0 ) {
F_18 ( & V_19 -> V_2 , L_6 ) ;
return V_52 ;
}
switch ( V_63 ) {
case 0 :
break;
case 5 :
V_16 &= ~ V_25 ;
break;
case 12 :
V_16 |= V_25 ;
break;
default:
F_18 ( & V_19 -> V_2 ,
L_7 ,
V_63 ) ;
}
F_38 ( & V_19 -> V_2 , L_8 ,
( V_16 & V_25 ) ? 12 : 5 ) ;
switch ( V_64 ) {
case 0 :
break;
case 1 :
V_16 &= ~ V_65 ;
break;
case 2 :
V_16 = ( V_16 & ~ V_65 )
| V_66 ;
break;
case 4 :
V_16 = ( V_16 & ~ V_65 )
| V_67 ;
break;
case 8 :
V_16 = ( V_16 & ~ V_65 )
| V_68 ;
break;
case 16 :
V_16 = ( V_16 & ~ V_65 )
| V_69 ;
break;
default:
F_18 ( & V_19 -> V_2 ,
L_9 ,
V_64 ) ;
}
F_38 ( & V_19 -> V_2 , L_10 ,
1 << ( V_16 & V_65 ) ) ;
if ( ( V_16 & V_29 ) == V_70 ) {
F_39 ( & V_19 -> V_2 , L_11 ) ;
V_16 = ( V_16 & ~ V_29 )
| V_71 ;
if ( F_12 ( V_19 , V_27 , 255 ) ) {
F_18 ( & V_19 -> V_2 , L_12 ) ;
return V_52 ;
}
}
if ( F_12 ( V_19 , V_33 , V_16 ) ) {
F_18 ( & V_19 -> V_2 , L_13 ) ;
return V_52 ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_13 = F_19 ( V_19 , V_34 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
int V_72 ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
F_11 ( & V_9 -> V_22 ) ;
if ( F_40 ( V_73 , V_9 -> V_74 + V_75 ) || ! V_9 -> V_76 ) {
V_9 -> V_17 = F_19 ( V_19 ,
V_23 ) ;
V_9 -> V_16 = F_19 ( V_19 ,
V_33 ) ;
for ( V_72 = 0 ; V_72 < V_9 -> V_55 ; V_72 ++ ) {
V_9 -> V_11 [ V_72 ] = F_19 ( V_19 ,
V_77 [ V_72 ] ) ;
}
V_9 -> V_13 = F_19 ( V_19 ,
V_34 ) ;
V_9 -> V_26 = F_19 ( V_19 , V_27 ) ;
V_9 -> V_35 |= F_19 ( V_19 ,
V_36 ) ;
V_9 -> V_74 = V_73 ;
V_9 -> V_76 = 1 ;
}
F_13 ( & V_9 -> V_22 ) ;
return V_9 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_78 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_78 ) ;
}
