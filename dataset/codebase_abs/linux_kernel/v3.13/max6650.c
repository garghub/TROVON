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
int V_14 , V_15 ;
unsigned long V_10 ;
int V_20 ;
V_20 = F_9 ( V_5 , 10 , & V_10 ) ;
if ( V_20 )
return V_20 ;
V_10 = F_10 ( V_10 , V_21 , V_22 ) ;
F_11 ( & V_9 -> V_23 ) ;
V_14 = F_4 ( V_9 -> V_16 ) ;
V_15 = ( ( clock * V_14 ) / ( 256 * V_10 / 60 ) ) - 1 ;
if ( V_15 < 0 )
V_15 = 0 ;
if ( V_15 > 255 )
V_15 = 255 ;
V_9 -> V_17 = V_15 ;
F_12 ( V_19 , V_24 , V_9 -> V_17 ) ;
F_13 ( & V_9 -> V_23 ) ;
return V_13 ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_25 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( V_9 -> V_16 & V_26 )
V_25 = 255 - ( 255 * ( int ) V_9 -> V_27 ) / 180 ;
else
V_25 = 255 - ( 255 * ( int ) V_9 -> V_27 ) / 76 ;
if ( V_25 < 0 )
V_25 = 0 ;
return sprintf ( V_5 , L_1 , V_25 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
unsigned long V_25 ;
int V_20 ;
V_20 = F_9 ( V_5 , 10 , & V_25 ) ;
if ( V_20 )
return V_20 ;
V_25 = F_10 ( V_25 , 0 , 255 ) ;
F_11 ( & V_9 -> V_23 ) ;
if ( V_9 -> V_16 & V_26 )
V_9 -> V_27 = 180 - ( 180 * V_25 ) / 255 ;
else
V_9 -> V_27 = 76 - ( 76 * V_25 ) / 255 ;
F_12 ( V_19 , V_28 , V_9 -> V_27 ) ;
F_13 ( & V_9 -> V_23 ) ;
return V_13 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_29 = ( V_9 -> V_16 & V_30 ) >> 4 ;
int V_31 [ 4 ] = { 0 , 1 , 2 , 1 } ;
return sprintf ( V_5 , L_1 , V_31 [ V_29 ] ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
int V_32 [ 3 ] = { 0 , 3 , 2 } ;
unsigned long V_29 ;
int V_20 ;
V_20 = F_9 ( V_5 , 10 , & V_29 ) ;
if ( V_20 )
return V_20 ;
if ( V_29 > 2 )
return - V_33 ;
F_11 ( & V_9 -> V_23 ) ;
V_9 -> V_16 = F_18 ( V_19 , V_34 ) ;
V_9 -> V_16 = ( V_9 -> V_16 & ~ V_30 )
| ( V_32 [ V_29 ] << 4 ) ;
F_12 ( V_19 , V_34 , V_9 -> V_16 ) ;
F_13 ( & V_9 -> V_23 ) ;
return V_13 ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_13 ) ) ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
unsigned long div ;
int V_20 ;
V_20 = F_9 ( V_5 , 10 , & div ) ;
if ( V_20 )
return V_20 ;
F_11 ( & V_9 -> V_23 ) ;
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
F_13 ( & V_9 -> V_23 ) ;
return - V_33 ;
}
F_12 ( V_19 , V_35 , V_9 -> V_13 ) ;
F_13 ( & V_9 -> V_23 ) ;
return V_13 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
int V_36 = 0 ;
if ( V_9 -> V_36 & V_7 -> V_12 ) {
F_11 ( & V_9 -> V_23 ) ;
V_36 = 1 ;
V_9 -> V_36 &= ~ V_7 -> V_12 ;
V_9 -> V_36 |= F_18 ( V_19 ,
V_37 ) ;
F_13 ( & V_9 -> V_23 ) ;
}
return sprintf ( V_5 , L_1 , V_36 ) ;
}
static T_3 F_22 ( struct V_38 * V_39 , struct V_40 * V_41 ,
int V_42 )
{
struct V_1 * V_2 = F_23 ( V_39 , struct V_1 , V_39 ) ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
T_4 V_43 = F_18 ( V_19 , V_44 ) ;
struct V_3 * V_4 ;
V_4 = F_23 ( V_41 , struct V_3 , V_7 ) ;
if ( V_4 == & V_45 . V_46
|| V_4 == & V_47 . V_46
|| V_4 == & V_48 . V_46
|| V_4 == & V_49 . V_46
|| V_4 == & V_50 . V_46 ) {
if ( ! ( V_43 & F_2 ( V_4 ) -> V_12 ) )
return 0 ;
}
return V_41 -> V_29 ;
}
static int F_24 ( struct V_18 * V_19 ,
const struct V_51 * V_52 )
{
struct V_8 * V_9 ;
int V_20 ;
V_9 = F_25 ( & V_19 -> V_2 , sizeof( struct V_8 ) ,
V_53 ) ;
if ( ! V_9 ) {
F_26 ( & V_19 -> V_2 , L_2 ) ;
return - V_54 ;
}
F_27 ( V_19 , V_9 ) ;
F_28 ( & V_9 -> V_23 ) ;
V_9 -> V_55 = V_52 -> V_56 ;
V_20 = F_29 ( V_19 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_30 ( & V_19 -> V_2 . V_39 , & V_57 ) ;
if ( V_20 )
return V_20 ;
if ( V_9 -> V_55 == 4 ) {
V_20 = F_30 ( & V_19 -> V_2 . V_39 , & V_58 ) ;
if ( V_20 )
goto V_59;
}
V_9 -> V_60 = F_31 ( & V_19 -> V_2 ) ;
if ( ! F_32 ( V_9 -> V_60 ) )
return 0 ;
V_20 = F_33 ( V_9 -> V_60 ) ;
F_26 ( & V_19 -> V_2 , L_3 ) ;
if ( V_9 -> V_55 == 4 )
F_34 ( & V_19 -> V_2 . V_39 , & V_58 ) ;
V_59:
F_34 ( & V_19 -> V_2 . V_39 , & V_57 ) ;
return V_20 ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
F_36 ( V_9 -> V_60 ) ;
if ( V_9 -> V_55 == 4 )
F_34 ( & V_19 -> V_2 . V_39 , & V_58 ) ;
F_34 ( & V_19 -> V_2 . V_39 , & V_57 ) ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
int V_16 ;
int V_20 = - V_61 ;
V_16 = F_18 ( V_19 , V_34 ) ;
if ( V_16 < 0 ) {
F_26 ( & V_19 -> V_2 , L_4 ) ;
return V_20 ;
}
switch ( V_62 ) {
case 0 :
break;
case 5 :
V_16 &= ~ V_26 ;
break;
case 12 :
V_16 |= V_26 ;
break;
default:
F_26 ( & V_19 -> V_2 , L_5 ,
V_62 ) ;
}
F_37 ( & V_19 -> V_2 , L_6 ,
( V_16 & V_26 ) ? 12 : 5 ) ;
switch ( V_63 ) {
case 0 :
break;
case 1 :
V_16 &= ~ V_64 ;
break;
case 2 :
V_16 = ( V_16 & ~ V_64 )
| V_65 ;
break;
case 4 :
V_16 = ( V_16 & ~ V_64 )
| V_66 ;
break;
case 8 :
V_16 = ( V_16 & ~ V_64 )
| V_67 ;
break;
case 16 :
V_16 = ( V_16 & ~ V_64 )
| V_68 ;
break;
default:
F_26 ( & V_19 -> V_2 , L_7 ,
V_63 ) ;
}
F_37 ( & V_19 -> V_2 , L_8 ,
1 << ( V_16 & V_64 ) ) ;
if ( ( V_16 & V_30 ) == V_69 ) {
F_38 ( & V_19 -> V_2 , L_9 ) ;
V_16 = ( V_16 & ~ V_30 )
| V_70 ;
if ( F_12 ( V_19 , V_28 , 255 ) ) {
F_26 ( & V_19 -> V_2 , L_10 ) ;
return V_20 ;
}
}
if ( F_12 ( V_19 , V_34 , V_16 ) ) {
F_26 ( & V_19 -> V_2 , L_11 ) ;
return V_20 ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_13 = F_18 ( V_19 , V_35 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
int V_71 ;
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_8 * V_9 = F_8 ( V_19 ) ;
F_11 ( & V_9 -> V_23 ) ;
if ( F_39 ( V_72 , V_9 -> V_73 + V_74 ) || ! V_9 -> V_75 ) {
V_9 -> V_17 = F_18 ( V_19 ,
V_24 ) ;
V_9 -> V_16 = F_18 ( V_19 ,
V_34 ) ;
for ( V_71 = 0 ; V_71 < V_9 -> V_55 ; V_71 ++ ) {
V_9 -> V_11 [ V_71 ] = F_18 ( V_19 ,
V_76 [ V_71 ] ) ;
}
V_9 -> V_13 = F_18 ( V_19 ,
V_35 ) ;
V_9 -> V_27 = F_18 ( V_19 , V_28 ) ;
V_9 -> V_36 |= F_18 ( V_19 ,
V_37 ) ;
V_9 -> V_73 = V_72 ;
V_9 -> V_75 = 1 ;
}
F_13 ( & V_9 -> V_23 ) ;
return V_9 ;
}
