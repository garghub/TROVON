static int F_1 ( struct V_1 * V_2 ,
const void * V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
void * V_9 ;
int V_10 ;
if ( V_4 <= 0 || ! V_3 )
return - V_11 ;
V_9 = F_2 ( V_3 , V_4 , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = F_3 ( V_6 , F_4 ( V_6 , 0 ) , 0x00 ,
V_14 | V_15 | V_16 ,
0x0000 , 0x0000 , V_9 , V_4 , V_17 ) ;
F_5 ( V_9 ) ;
if ( V_10 != V_4 ) {
struct V_18 * V_8 = & V_2 -> V_8 ;
F_6 ( V_8 , L_1 ,
* ( V_19 * ) V_3 , V_10 ) ;
if ( V_10 >= 0 )
V_10 = - V_20 ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
V_22 = F_8 ( sizeof( * V_22 ) , V_12 ) ;
if ( ! V_22 )
return - V_13 ;
F_9 ( & V_22 -> V_23 ) ;
F_10 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
V_22 = F_12 ( V_2 ) ;
F_13 ( & V_22 -> V_23 ) ;
F_5 ( V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_18 * V_8 = V_25 -> V_8 ;
struct V_21 * V_22 ;
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
int V_10 ;
V_22 = F_12 ( V_2 ) ;
F_15 ( & V_22 -> V_23 ) ;
V_27 = V_22 -> V_28 ;
F_16 ( & V_22 -> V_23 ) ;
V_10 = ( ( V_27 & V_29 ) ? V_30 : 0 ) |
( ( V_27 & V_31 ) ? V_32 : 0 ) ;
F_17 ( V_8 , L_2 , V_33 , V_10 ) ;
return V_10 ;
}
static int F_18 ( struct V_24 * V_25 ,
unsigned int V_34 , unsigned int V_35 )
{
struct V_18 * V_8 = V_25 -> V_8 ;
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_21 * V_22 ;
struct V_36 V_37 ;
int V_10 ;
V_22 = F_12 ( V_2 ) ;
F_15 ( & V_22 -> V_23 ) ;
if ( V_34 & V_30 ) {
V_22 -> V_28 |= V_29 ;
F_17 ( V_8 , L_3 , V_33 ) ;
}
if ( V_34 & V_32 ) {
V_22 -> V_28 |= V_31 ;
F_17 ( V_8 , L_4 , V_33 ) ;
}
if ( V_35 & V_30 ) {
V_22 -> V_28 &= ~ V_29 ;
F_17 ( V_8 , L_5 , V_33 ) ;
}
if ( V_35 & V_32 ) {
V_22 -> V_28 &= ~ V_31 ;
F_17 ( V_8 , L_6 , V_33 ) ;
}
V_37 . V_38 = V_39 ;
V_37 . V_40 = V_22 -> V_28 ;
V_10 = F_1 ( V_2 , & V_37 , sizeof( V_37 ) ) ;
F_16 ( & V_22 -> V_23 ) ;
return V_10 ;
}
static void F_19 ( struct V_24 * V_25 , int V_41 )
{
struct V_18 * V_8 = V_25 -> V_8 ;
struct V_21 * V_22 ;
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_36 V_37 ;
V_22 = F_12 ( V_2 ) ;
F_15 ( & V_22 -> V_23 ) ;
if ( V_41 ) {
V_22 -> V_28 |= V_42 ;
F_17 ( V_8 , L_7 , V_33 ) ;
} else {
V_22 -> V_28 &= ~ V_42 ;
F_17 ( V_8 , L_8 , V_33 ) ;
}
V_37 . V_38 = V_39 ;
V_37 . V_40 = V_22 -> V_28 ;
F_1 ( V_2 , & V_37 , sizeof( V_37 ) ) ;
F_16 ( & V_22 -> V_23 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_43 )
{
struct V_24 * V_25 = V_2 -> V_2 . V_25 ;
unsigned int V_34 = 0 ;
unsigned int V_35 = 0 ;
if ( V_43 )
V_34 = V_30 | V_32 ;
else
V_35 = V_30 | V_32 ;
F_18 ( V_25 , V_34 , V_35 ) ;
}
static T_1 F_21 ( struct V_24 * V_25 )
{
const T_1 V_44 = F_22 ( V_25 ) ;
const T_1 V_45 [] = {
0 , 2400 , 4800 , 9600 , 19200 , 38400 , 57600 , 115200 , 153600
} ;
int V_46 ;
for ( V_46 = F_23 ( V_45 ) - 1 ; V_46 >= 0 ; V_46 -- ) {
if ( V_44 == V_45 [ V_46 ] )
return V_44 ;
}
F_24 ( V_25 , 9600 , 9600 ) ;
return F_22 ( V_25 ) ;
}
static void F_25 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_18 * V_8 = & V_2 -> V_8 ;
struct V_49 V_37 ;
T_1 V_44 ;
if ( V_48 && ! F_26 ( & V_25 -> V_50 , V_48 ) )
return;
if ( F_27 ( V_25 ) == V_51 )
F_20 ( V_2 , 0 ) ;
else if ( V_48 && ( V_48 -> V_52 & V_53 ) == V_51 )
F_20 ( V_2 , 1 ) ;
V_44 = F_21 ( V_25 ) ;
V_37 . V_38 = V_54 ;
V_37 . V_44 = F_28 ( V_44 ) ;
V_37 . V_40 = 0 ;
F_17 ( V_8 , L_9 , V_33 , V_44 ) ;
switch ( F_29 ( V_25 ) ) {
case V_55 :
V_37 . V_40 |= V_56 ;
F_17 ( V_8 , L_10 , V_33 ) ;
break;
default:
V_25 -> V_50 . V_52 &= ~ V_57 ;
V_25 -> V_50 . V_52 |= V_58 ;
F_30 ( V_8 , L_11 ) ;
case V_58 :
V_37 . V_40 |= V_59 ;
F_17 ( V_8 , L_12 , V_33 ) ;
break;
}
if ( F_31 ( V_25 ) ) {
if ( F_32 ( V_25 ) ) {
V_37 . V_40 |= V_60 ;
F_17 ( V_8 , L_13 , V_33 ) ;
} else {
V_37 . V_40 |= V_61 ;
F_17 ( V_8 , L_14 , V_33 ) ;
}
if ( F_33 ( V_25 ) ) {
V_25 -> V_50 . V_52 &= ~ V_62 ;
F_30 ( V_8 , L_15 ) ;
}
} else {
V_37 . V_40 |= V_63 ;
F_17 ( V_8 , L_16 , V_33 ) ;
}
if ( F_34 ( V_25 ) ) {
V_37 . V_40 |= V_64 ;
F_17 ( V_8 , L_17 , V_33 ) ;
} else {
V_37 . V_40 |= V_65 ;
F_17 ( V_8 , L_18 , V_33 ) ;
}
if ( F_35 ( V_25 ) ) {
V_25 -> V_50 . V_52 &= ~ V_66 ;
F_30 ( V_8 , L_19 ) ;
}
if ( F_36 ( V_25 ) || F_37 ( V_25 ) ) {
V_25 -> V_50 . V_67 &= ~ ( V_68 | V_69 ) ;
F_30 ( V_8 , L_20 ) ;
}
V_37 . V_40 |= V_70 ;
F_17 ( V_8 , L_21 , V_33 ) ;
F_1 ( V_2 , & V_37 , sizeof( V_37 ) ) ;
}
static int F_38 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_71 V_37 = {
. V_38 = V_72 ,
. V_73 = V_74
} ;
int V_10 ;
V_10 = F_1 ( V_2 , & V_37 , sizeof( V_37 ) ) ;
if ( V_10 )
return V_10 ;
if ( V_25 )
F_25 ( V_25 , V_2 , NULL ) ;
return F_39 ( V_25 , V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_71 V_37 = {
. V_38 = V_72 ,
. V_73 = V_75
} ;
F_41 ( V_2 ) ;
F_1 ( V_2 , & V_37 , sizeof( V_37 ) ) ;
}
