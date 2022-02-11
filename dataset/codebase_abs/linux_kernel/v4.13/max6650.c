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
static int F_7 ( struct V_1 * V_4 , T_1 V_26 )
{
int V_27 ;
T_1 V_15 = V_4 -> V_15 ;
if ( V_26 == ( V_15 & V_28 ) )
return 0 ;
V_15 = ( V_15 & ~ V_28 ) | V_26 ;
V_27 = F_8 ( V_4 -> V_6 , V_16 ,
V_15 ) ;
if ( V_27 < 0 )
return V_27 ;
V_4 -> V_15 = V_15 ;
return 0 ;
}
static T_2 F_9 ( struct V_2 * V_3 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_32 * V_33 = F_10 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_34 ;
V_34 = ( ( V_4 -> V_18 [ V_33 -> V_35 ] * 120 ) / F_11 ( V_4 -> V_20 ) ) ;
return sprintf ( V_31 , L_1 , V_34 ) ;
}
static T_2 F_12 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_36 , V_37 , V_34 ;
V_36 = F_11 ( V_4 -> V_15 ) ;
V_37 = V_4 -> V_13 ;
V_34 = 60 * V_36 * clock / ( 256 * ( V_37 + 1 ) ) ;
return sprintf ( V_31 , L_1 , V_34 ) ;
}
static int F_13 ( struct V_1 * V_4 , unsigned long V_34 )
{
int V_36 , V_37 ;
if ( V_34 == 0 )
return F_7 ( V_4 , V_38 ) ;
V_34 = F_14 ( V_34 , V_39 , V_40 ) ;
V_36 = F_11 ( V_4 -> V_15 ) ;
V_37 = ( ( clock * V_36 ) / ( 256 * V_34 / 60 ) ) - 1 ;
if ( V_37 < 0 )
V_37 = 0 ;
if ( V_37 > 255 )
V_37 = 255 ;
V_4 -> V_13 = V_37 ;
return F_8 ( V_4 -> V_6 , V_14 ,
V_4 -> V_13 ) ;
}
static T_2 F_15 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_34 ;
int V_41 ;
V_41 = F_16 ( V_31 , 10 , & V_34 ) ;
if ( V_41 )
return V_41 ;
F_3 ( & V_4 -> V_8 ) ;
V_41 = F_13 ( V_4 , V_34 ) ;
F_6 ( & V_4 -> V_8 ) ;
if ( V_41 < 0 )
return V_41 ;
return V_20 ;
}
static T_2 F_17 ( struct V_2 * V_3 , struct V_29 * V_30 ,
char * V_31 )
{
int V_42 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_15 & V_43 )
V_42 = 255 - ( 255 * ( int ) V_4 -> V_22 ) / 180 ;
else
V_42 = 255 - ( 255 * ( int ) V_4 -> V_22 ) / 76 ;
if ( V_42 < 0 )
V_42 = 0 ;
return sprintf ( V_31 , L_1 , V_42 ) ;
}
static T_2 F_18 ( struct V_2 * V_3 ,
struct V_29 * V_30 , const char * V_31 ,
T_3 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_42 ;
int V_41 ;
V_41 = F_16 ( V_31 , 10 , & V_42 ) ;
if ( V_41 )
return V_41 ;
V_42 = F_14 ( V_42 , 0 , 255 ) ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_15 & V_43 )
V_4 -> V_22 = 180 - ( 180 * V_42 ) / 255 ;
else
V_4 -> V_22 = 76 - ( 76 * V_42 ) / 255 ;
V_41 = F_8 ( V_6 , V_23 , V_4 -> V_22 ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_41 < 0 ? V_41 : V_20 ;
}
static T_2 F_19 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_26 = ( V_4 -> V_15 & V_28 ) >> 4 ;
int V_44 [ 4 ] = { 0 , 3 , 2 , 1 } ;
return sprintf ( V_31 , L_1 , V_44 [ V_26 ] ) ;
}
static T_2 F_20 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_26 ;
int V_41 ;
const T_1 V_45 [] = {
V_46 ,
V_47 ,
V_48 ,
V_38 ,
} ;
V_41 = F_16 ( V_31 , 10 , & V_26 ) ;
if ( V_41 )
return V_41 ;
if ( V_26 >= F_21 ( V_45 ) )
return - V_49 ;
F_3 ( & V_4 -> V_8 ) ;
F_7 ( V_4 , V_45 [ V_26 ] ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_20 ;
}
static T_2 F_22 ( struct V_2 * V_3 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return sprintf ( V_31 , L_1 , F_11 ( V_4 -> V_20 ) ) ;
}
static T_2 F_23 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
const char * V_31 , T_3 V_20 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long div ;
int V_41 ;
V_41 = F_16 ( V_31 , 10 , & div ) ;
if ( V_41 )
return V_41 ;
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
return - V_49 ;
}
F_8 ( V_6 , V_21 , V_4 -> V_20 ) ;
F_6 ( & V_4 -> V_8 ) ;
return V_20 ;
}
static T_2 F_24 ( struct V_2 * V_3 , struct V_29 * V_30 ,
char * V_31 )
{
struct V_32 * V_33 = F_10 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_24 = 0 ;
if ( V_4 -> V_24 & V_33 -> V_35 ) {
F_3 ( & V_4 -> V_8 ) ;
V_24 = 1 ;
V_4 -> V_24 &= ~ V_33 -> V_35 ;
V_4 -> V_24 |= F_5 ( V_6 ,
V_25 ) ;
F_6 ( & V_4 -> V_8 ) ;
}
return sprintf ( V_31 , L_1 , V_24 ) ;
}
static T_4 F_25 ( struct V_50 * V_51 , struct V_52 * V_53 ,
int V_54 )
{
struct V_2 * V_3 = F_26 ( V_51 , struct V_2 , V_51 ) ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_55 = F_5 ( V_6 , V_56 ) ;
struct V_29 * V_30 ;
V_30 = F_26 ( V_53 , struct V_29 , V_33 ) ;
if ( V_30 == & V_57 . V_58
|| V_30 == & V_59 . V_58
|| V_30 == & V_60 . V_58
|| V_30 == & V_61 . V_58
|| V_30 == & V_62 . V_58 ) {
if ( ! ( V_55 & F_10 ( V_30 ) -> V_35 ) )
return 0 ;
}
return V_53 -> V_26 ;
}
static int F_27 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
int V_15 ;
int V_41 = - V_63 ;
T_5 V_64 ;
T_5 V_65 ;
T_5 V_66 ;
if ( F_28 ( V_3 -> V_67 , L_2 ,
& V_64 ) )
V_64 = V_68 ;
else
V_64 /= 1000000 ;
if ( F_28 ( V_3 -> V_67 , L_3 ,
& V_65 ) )
V_65 = V_69 ;
V_15 = F_5 ( V_6 , V_16 ) ;
if ( V_15 < 0 ) {
F_29 ( V_3 , L_4 ) ;
return V_41 ;
}
switch ( V_64 ) {
case 0 :
break;
case 5 :
V_15 &= ~ V_43 ;
break;
case 12 :
V_15 |= V_43 ;
break;
default:
F_29 ( V_3 , L_5 , V_64 ) ;
}
switch ( V_65 ) {
case 0 :
break;
case 1 :
V_15 &= ~ V_70 ;
break;
case 2 :
V_15 = ( V_15 & ~ V_70 )
| V_71 ;
break;
case 4 :
V_15 = ( V_15 & ~ V_70 )
| V_72 ;
break;
case 8 :
V_15 = ( V_15 & ~ V_70 )
| V_73 ;
break;
case 16 :
V_15 = ( V_15 & ~ V_70 )
| V_74 ;
break;
default:
F_29 ( V_3 , L_6 , V_65 ) ;
}
F_30 ( V_3 , L_7 ,
( V_15 & V_43 ) ? 12 : 5 ,
1 << ( V_15 & V_70 ) ) ;
if ( F_8 ( V_6 , V_16 , V_15 ) ) {
F_29 ( V_3 , L_8 ) ;
return V_41 ;
}
V_4 -> V_15 = V_15 ;
V_4 -> V_20 = F_5 ( V_6 , V_21 ) ;
if ( ! F_28 ( V_6 -> V_3 . V_67 , L_9 ,
& V_66 ) ) {
F_13 ( V_4 , V_66 ) ;
F_7 ( V_4 , V_48 ) ;
}
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_75 * V_76 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
const struct V_77 * V_78 =
F_32 ( F_33 ( V_79 ) , V_3 ) ;
struct V_1 * V_4 ;
struct V_2 * V_80 ;
int V_41 ;
V_4 = F_34 ( V_3 , sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_4 )
return - V_82 ;
V_4 -> V_6 = V_6 ;
F_35 ( & V_4 -> V_8 ) ;
V_4 -> V_17 = V_78 ? ( int ) ( V_83 ) V_78 -> V_4 : V_76 -> V_84 ;
V_41 = F_27 ( V_4 , V_6 ) ;
if ( V_41 )
return V_41 ;
V_4 -> V_85 [ 0 ] = & V_86 ;
if ( V_4 -> V_17 == 4 )
V_4 -> V_85 [ 1 ] = & V_87 ;
V_80 = F_36 ( V_3 ,
V_6 -> V_88 , V_4 ,
V_4 -> V_85 ) ;
return F_37 ( V_80 ) ;
}
