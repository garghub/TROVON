static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
F_3 ( & V_4 -> V_8 ) ;
if ( F_4 ( V_9 , V_4 -> V_10 + V_11 ) || ! V_4 -> V_12 ) {
V_4 -> V_13 = F_5 ( V_6 ,
V_14 ) ;
V_4 -> V_15 = F_5 ( V_6 ,
V_16 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_17 ; V_7 ++ ) {
V_4 -> V_18 [ V_7 ] = F_5 ( V_6 ,
V_19 [ V_7 ] ) ;
}
V_4 -> V_20 = F_5 ( V_6 ,
V_21 ) ;
V_4 -> V_22 = F_5 ( V_6 , V_23 ) ;
V_4 -> V_24 |= F_5 ( V_6 ,
V_25 ) ;
V_4 -> V_10 = V_9 ;
V_4 -> V_12 = 1 ;
}
F_6 ( & V_4 -> V_8 ) ;
return V_4 ;
}
static T_1 F_7 ( struct V_2 * V_3 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_8 ( V_27 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_31 ;
V_31 = ( ( V_4 -> V_18 [ V_30 -> V_32 ] * 120 ) / F_9 ( V_4 -> V_20 ) ) ;
return sprintf ( V_28 , L_1 , V_31 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 , V_34 , V_31 ;
V_33 = F_9 ( V_4 -> V_15 ) ;
V_34 = V_4 -> V_13 ;
V_31 = 60 * V_33 * clock / ( 256 * ( V_34 + 1 ) ) ;
return sprintf ( V_28 , L_1 , V_31 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 , struct V_26 * V_27 ,
const char * V_28 , T_2 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_33 , V_34 ;
unsigned long V_31 ;
int V_35 ;
V_35 = F_12 ( V_28 , 10 , & V_31 ) ;
if ( V_35 )
return V_35 ;
V_31 = F_13 ( V_31 , V_36 , V_37 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_33 = F_9 ( V_4 -> V_15 ) ;
V_34 = ( ( clock * V_33 ) / ( 256 * V_31 / 60 ) ) - 1 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_34 > 255 )
V_34 = 255 ;
V_4 -> V_13 = V_34 ;
F_14 ( V_6 , V_14 , V_4 -> V_13 ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_20 ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_26 * V_27 ,
char * V_28 )
{
int V_38 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_15 & V_39 )
V_38 = 255 - ( 255 * ( int ) V_4 -> V_22 ) / 180 ;
else
V_38 = 255 - ( 255 * ( int ) V_4 -> V_22 ) / 76 ;
if ( V_38 < 0 )
V_38 = 0 ;
return sprintf ( V_28 , L_1 , V_38 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 , struct V_26 * V_27 ,
const char * V_28 , T_2 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_38 ;
int V_35 ;
V_35 = F_12 ( V_28 , 10 , & V_38 ) ;
if ( V_35 )
return V_35 ;
V_38 = F_13 ( V_38 , 0 , 255 ) ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_15 & V_39 )
V_4 -> V_22 = 180 - ( 180 * V_38 ) / 255 ;
else
V_4 -> V_22 = 76 - ( 76 * V_38 ) / 255 ;
F_14 ( V_6 , V_23 , V_4 -> V_22 ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_20 ;
}
static T_1 F_17 ( struct V_2 * V_3 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_40 = ( V_4 -> V_15 & V_41 ) >> 4 ;
int V_42 [ 4 ] = { 0 , 1 , 2 , 1 } ;
return sprintf ( V_28 , L_1 , V_42 [ V_40 ] ) ;
}
static T_1 F_18 ( struct V_2 * V_3 , struct V_26 * V_27 ,
const char * V_28 , T_2 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_43 [ 3 ] = { 0 , 3 , 2 } ;
unsigned long V_40 ;
int V_35 ;
V_35 = F_12 ( V_28 , 10 , & V_40 ) ;
if ( V_35 )
return V_35 ;
if ( V_40 > 2 )
return - V_44 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_15 = F_5 ( V_6 , V_16 ) ;
V_4 -> V_15 = ( V_4 -> V_15 & ~ V_41 )
| ( V_43 [ V_40 ] << 4 ) ;
F_14 ( V_6 , V_16 , V_4 -> V_15 ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_20 ;
}
static T_1 F_19 ( struct V_2 * V_3 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_28 , L_1 , F_9 ( V_4 -> V_20 ) ) ;
}
static T_1 F_20 ( struct V_2 * V_3 , struct V_26 * V_27 ,
const char * V_28 , T_2 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long div ;
int V_35 ;
V_35 = F_12 ( V_28 , 10 , & div ) ;
if ( V_35 )
return V_35 ;
F_3 ( & V_4 -> V_8 ) ;
switch ( div ) {
case 1 :
V_4 -> V_20 = 0 ;
break;
case 2 :
V_4 -> V_20 = 1 ;
break;
case 4 :
V_4 -> V_20 = 2 ;
break;
case 8 :
V_4 -> V_20 = 3 ;
break;
default:
F_6 ( & V_4 -> V_8 ) ;
return - V_44 ;
}
F_14 ( V_6 , V_21 , V_4 -> V_20 ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_20 ;
}
static T_1 F_21 ( struct V_2 * V_3 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_8 ( V_27 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_24 = 0 ;
if ( V_4 -> V_24 & V_30 -> V_32 ) {
F_3 ( & V_4 -> V_8 ) ;
V_24 = 1 ;
V_4 -> V_24 &= ~ V_30 -> V_32 ;
V_4 -> V_24 |= F_5 ( V_6 ,
V_25 ) ;
F_6 ( & V_4 -> V_8 ) ;
}
return sprintf ( V_28 , L_1 , V_24 ) ;
}
static T_3 F_22 ( struct V_45 * V_46 , struct V_47 * V_48 ,
int V_49 )
{
struct V_2 * V_3 = F_23 ( V_46 , struct V_2 , V_46 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_4 V_50 = F_5 ( V_6 , V_51 ) ;
struct V_26 * V_27 ;
V_27 = F_23 ( V_48 , struct V_26 , V_30 ) ;
if ( V_27 == & V_52 . V_53
|| V_27 == & V_54 . V_53
|| V_27 == & V_55 . V_53
|| V_27 == & V_56 . V_53
|| V_27 == & V_57 . V_53 ) {
if ( ! ( V_50 & F_8 ( V_27 ) -> V_32 ) )
return 0 ;
}
return V_48 -> V_40 ;
}
static int F_24 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
int V_15 ;
int V_35 = - V_58 ;
V_15 = F_5 ( V_6 , V_16 ) ;
if ( V_15 < 0 ) {
F_25 ( V_3 , L_2 ) ;
return V_35 ;
}
switch ( V_59 ) {
case 0 :
break;
case 5 :
V_15 &= ~ V_39 ;
break;
case 12 :
V_15 |= V_39 ;
break;
default:
F_25 ( V_3 , L_3 ,
V_59 ) ;
}
F_26 ( V_3 , L_4 ,
( V_15 & V_39 ) ? 12 : 5 ) ;
switch ( V_60 ) {
case 0 :
break;
case 1 :
V_15 &= ~ V_61 ;
break;
case 2 :
V_15 = ( V_15 & ~ V_61 )
| V_62 ;
break;
case 4 :
V_15 = ( V_15 & ~ V_61 )
| V_63 ;
break;
case 8 :
V_15 = ( V_15 & ~ V_61 )
| V_64 ;
break;
case 16 :
V_15 = ( V_15 & ~ V_61 )
| V_65 ;
break;
default:
F_25 ( V_3 , L_5 , V_60 ) ;
}
F_26 ( V_3 , L_6 ,
1 << ( V_15 & V_61 ) ) ;
if ( ( V_15 & V_41 ) == V_66 ) {
F_27 ( V_3 , L_7 ) ;
V_15 = ( V_15 & ~ V_41 )
| V_67 ;
if ( F_14 ( V_6 , V_23 , 255 ) ) {
F_25 ( V_3 , L_8 ) ;
return V_35 ;
}
}
if ( F_14 ( V_6 , V_16 , V_15 ) ) {
F_25 ( V_3 , L_9 ) ;
return V_35 ;
}
V_4 -> V_15 = V_15 ;
V_4 -> V_20 = F_5 ( V_6 , V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 ,
const struct V_68 * V_69 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_70 ;
int V_35 ;
V_4 = F_29 ( V_3 , sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_4 )
return - V_72 ;
V_4 -> V_6 = V_6 ;
F_30 ( & V_4 -> V_8 ) ;
V_4 -> V_17 = V_69 -> V_73 ;
V_35 = F_24 ( V_4 , V_6 ) ;
if ( V_35 )
return V_35 ;
V_4 -> V_74 [ 0 ] = & V_75 ;
if ( V_4 -> V_17 == 4 )
V_4 -> V_74 [ 1 ] = & V_76 ;
V_70 = F_31 ( V_3 ,
V_6 -> V_77 , V_4 ,
V_4 -> V_74 ) ;
return F_32 ( V_70 ) ;
}
