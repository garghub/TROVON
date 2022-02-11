static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_5 = V_2 -> V_6 ( V_2 -> V_7 , V_4 -> V_8 ) ;
return V_5 >> V_4 -> V_9 & ( ( 1 << V_4 -> V_10 ) - 1 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_11 )
{
int V_5 , V_12 , V_13 , V_14 ;
V_5 = V_2 -> V_6 ( V_2 -> V_7 , V_4 -> V_8 ) ;
V_12 = ( ( 1 << V_4 -> V_10 ) - 1 ) << V_4 -> V_9 ;
V_13 = ( V_5 & V_12 ) >> V_4 -> V_9 ;
V_14 = ( V_11 << V_4 -> V_9 ) & V_12 ;
V_5 = ( V_5 & ~ V_12 ) | V_14 ;
V_2 -> V_15 ( V_2 -> V_7 , V_4 -> V_8 , V_5 ) ;
return V_13 ;
}
static void F_3 ( struct V_1 * V_2 , int V_16 , ... )
{
T_1 V_17 ;
const struct V_3 * V_18 ;
int V_5 = 0 , V_12 , * V_19 , V_8 = - 1 ;
va_start ( V_17 , V_16 ) ;
while ( -- V_16 >= 0 ) {
V_18 = va_arg ( V_17 , const struct V_3 * ) ;
V_19 = va_arg ( V_17 , int * ) ;
if ( V_8 == - 1 ) {
V_8 = V_18 -> V_8 ;
V_5 = V_2 -> V_6 ( V_2 -> V_7 , V_8 ) ;
}
V_12 = ( 1 << V_18 -> V_10 ) - 1 ;
* V_19 = V_5 >> V_18 -> V_9 & V_12 ;
}
va_end ( V_17 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_16 , ... )
{
T_1 V_17 ;
int V_8 ;
const struct V_3 * V_18 ;
int V_19 ;
int V_5 , V_20 , V_12 , V_21 ;
V_12 = 0 ;
V_21 = 0 ;
V_8 = - 1 ;
va_start ( V_17 , V_16 ) ;
while ( -- V_16 >= 0 ) {
V_18 = va_arg ( V_17 , const struct V_3 * ) ;
V_19 = va_arg ( V_17 , int ) ;
if ( V_8 == - 1 )
V_8 = V_18 -> V_8 ;
else
F_5 ( V_8 != V_18 -> V_8 ) ;
V_20 = ( ( 1 << V_18 -> V_10 ) - 1 ) << V_18 -> V_9 ;
V_12 |= V_20 ;
V_21 |= ( V_19 << V_18 -> V_9 ) & V_20 ;
}
va_end ( V_17 ) ;
if ( ~ V_12 & 0xFFFF )
V_5 = V_2 -> V_6 ( V_2 -> V_7 , V_8 ) ;
else
V_5 = 0 ;
V_5 = ( V_5 & ~ V_12 ) | V_21 ;
V_2 -> V_15 ( V_2 -> V_7 , V_8 , V_5 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_22 )
{
const struct V_23 * V_24 = V_23 [ V_22 ] ;
int V_25 ;
V_25 = ( 1 << V_24 -> V_26 -> V_10 ) ;
if ( ! V_24 -> V_27 )
V_25 -= 1 ;
return V_25 ;
}
int F_7 ( struct V_1 * V_2 , int V_22 )
{
int V_28 , V_29 , V_30 , V_31 ;
const struct V_23 * V_24 = V_23 [ V_22 ] ;
unsigned short V_12 = ( 1 << V_24 -> V_26 -> V_10 ) - 1 ;
F_3 ( V_2 , 2 , V_24 -> V_26 , & V_28 , V_24 -> V_32 , & V_29 ) ;
if ( V_24 -> V_33 ) {
V_28 = V_12 - V_28 ;
V_29 = V_12 - V_29 ;
}
if ( V_24 -> V_27 ) {
F_3 ( V_2 , 2 , V_24 -> V_27 , & V_30 , V_24 -> V_34 , & V_31 ) ;
if ( V_30 )
V_28 = 0 ;
if ( V_31 )
V_29 = 0 ;
}
return V_28 << 0 | V_29 << 8 ;
}
int F_8 ( struct V_1 * V_2 , int V_22 , int V_11 )
{
const struct V_23 * V_24 = V_23 [ V_22 ] ;
unsigned short V_12 = ( 1 << V_24 -> V_26 -> V_10 ) - 1 ;
int V_28 = ( V_11 >> 0 ) & V_12 ;
int V_29 = ( V_11 >> 8 ) & V_12 ;
int V_30 = ( V_28 == 0 ) ? 1 : 0 ;
int V_31 = ( V_29 == 0 ) ? 1 : 0 ;
if ( V_24 -> V_33 ) {
V_28 = V_12 - V_28 ;
V_29 = V_12 - V_29 ;
}
if ( V_24 -> V_27 )
F_4 ( V_2 , 2 , V_24 -> V_27 , V_30 , V_24 -> V_34 , V_31 ) ;
F_4 ( V_2 , 2 , V_24 -> V_26 , V_28 , V_24 -> V_32 , V_29 ) ;
return F_7 ( V_2 , V_22 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_35 = F_1 ( V_2 , & V_36 ) ;
if ( V_35 < 0 || V_35 > 2 ) {
V_35 = 2 ;
F_4 ( V_2 , 2 ,
& V_36 , V_35 , & V_37 , V_35 ) ;
}
return V_35 ;
}
int F_10 ( struct V_1 * V_2 , int V_38 )
{
if ( V_38 < 0 || V_38 > 2 )
return - V_39 ;
F_4 ( V_2 , 2 , & V_36 , V_38 , & V_37 , V_38 ) ;
return V_38 ;
}
void F_11 ( struct V_1 * V_2 ,
unsigned int V_22 ,
unsigned int V_40 ,
T_2 V_41 ,
unsigned int V_42 )
{
int V_43 = 0 , V_44 = 0 ;
switch ( V_41 ) {
case V_45 :
V_43 = 0 ;
break;
case V_46 :
V_43 = 0 ;
break;
case V_47 :
V_43 = 1 ;
break;
case V_48 :
V_43 = 2 ;
break;
case V_49 :
V_43 = 3 ;
break;
default:
break;
}
switch ( V_42 ) {
case 2 :
V_44 = 0 ;
break;
case 1 :
V_44 = 1 ;
break;
default:
break;
}
if ( V_22 ) {
F_2 ( V_2 , & V_50 , V_40 ) ;
F_4 ( V_2 , 2 ,
& V_51 , V_44 ,
& V_52 , V_43 ) ;
} else {
F_2 ( V_2 , & V_53 , V_40 ) ;
F_4 ( V_2 , 2 ,
& V_54 , V_44 ,
& V_55 , V_43 ) ;
}
}
void F_12 ( struct V_1 * V_2 , unsigned int V_22 )
{
if ( V_22 )
F_2 ( V_2 , & V_52 , 1 ) ;
else
F_2 ( V_2 , & V_55 , 1 ) ;
}
void F_13 ( struct V_1 * V_2 ,
unsigned int V_40 ,
T_2 V_41 ,
unsigned int V_42 )
{
int V_56 = 0 ;
switch ( V_41 ) {
case V_45 : V_56 = 0 ; break;
case V_46 : V_56 = 0 ; break;
case V_47 : V_56 = 1 ; break;
case V_48 : V_56 = 2 ; break;
case V_49 : V_56 = 3 ; break;
default: break;
}
F_2 ( V_2 , & V_57 , V_40 ) ;
F_4 ( V_2 , 2 ,
& V_58 , V_56 , & V_59 , V_56 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
}
int F_15 ( struct V_1 * V_2 )
{
unsigned long V_60 ;
if ( F_1 ( V_2 , & V_61 ) != 0 ) {
F_16 ( V_62 L_1 ) ;
return - V_63 ;
}
F_2 ( V_2 , & V_64 , 1 ) ;
F_2 ( V_2 , & V_65 , 0 ) ;
V_60 = V_66 + F_17 ( 500 ) ;
while ( F_1 ( V_2 , & V_67 ) ) {
if ( F_18 ( V_66 , V_60 ) ) {
F_16 ( V_62
L_2 ) ;
return - V_63 ;
}
F_19 ( 5 ) ;
}
F_4 ( V_2 , 3 ,
& V_68 , 1 ,
& V_69 , 1 ,
& V_70 , 1 ) ;
F_4 ( V_2 , 4 ,
& V_71 , 1 ,
& V_72 , 2 ,
& V_73 , 3 ,
& V_74 , 3 ) ;
F_2 ( V_2 , & V_75 , 1 ) ;
F_4 ( V_2 , 7 ,
& V_76 , 1 ,
& V_77 , 1 ,
& V_78 , 1 ,
& V_79 , 1 ,
& V_80 , 1 ,
& V_81 , 1 ,
& V_82 , 1 ) ;
F_8 ( V_2 , V_83 , 0 ) ;
F_8 ( V_2 , V_84 , 0 ) ;
F_8 ( V_2 , V_85 , 0 ) ;
F_8 ( V_2 , V_86 , 0 ) ;
F_8 ( V_2 , V_87 , 0 ) ;
F_8 ( V_2 , V_88 , 0 ) ;
F_4 ( V_2 , 2 , & V_89 , 0 , & V_90 , 0 ) ;
F_4 ( V_2 , 2 , & V_91 , 0 , & V_92 , 0 ) ;
F_10 ( V_2 , 2 ) ;
F_4 ( V_2 , 2 , & V_93 , 1 , & V_94 , 1 ) ;
F_4 ( V_2 , 3 ,
& V_95 , 1 ,
& V_96 , 0 ,
& V_97 , 0 ) ;
return 0 ;
}
