static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 , V_4 , V_5 ) ;
F_2 ( V_3 , V_6 , 0xA5 ) ;
F_2 ( V_3 , V_6 , 0x5A ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
int V_7 = F_4 ( V_3 ) ;
F_5 ( L_1 ) ;
V_7 |= V_8 ;
V_7 &= ~ ( V_9 | V_10 ) ;
F_6 ( V_3 , V_7 ) ;
return F_7 ( V_3 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
int V_7 = F_4 ( V_3 ) ;
F_5 ( L_2 ) ;
V_7 |= V_8 ;
V_7 &= ~ ( V_9 | V_10 ) ;
F_6 ( V_3 , V_7 ) ;
return F_7 ( V_3 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
int V_7 = F_4 ( V_3 ) ;
F_5 ( L_3 ) ;
V_7 |= V_9 ;
V_7 &= ~ ( V_8 | V_10 ) ;
F_6 ( V_3 , V_7 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
int V_7 = F_4 ( V_3 ) ;
int V_13 ;
V_13 = ( ( 0x7f & V_12 -> V_13 ) << 1 ) ;
if ( V_12 -> V_14 & V_15 )
V_13 |= 1 ;
F_5 ( L_4 ,
V_12 -> V_13 , V_12 -> V_14 & V_15 ? 'R' : 'W' , V_13 ) ;
F_2 ( V_3 , V_16 , V_13 ) ;
V_7 &= ~ ( V_9 | V_8 | V_10 ) ;
F_6 ( V_3 , V_7 ) ;
return F_7 ( V_3 ) ;
}
static int F_11 ( struct V_2 * V_3 ,
T_1 V_17 )
{
int V_7 = F_4 ( V_3 ) ;
F_5 ( L_5 , V_17 ) ;
F_2 ( V_3 , V_16 , V_17 ) ;
V_7 &= ~ ( V_9 | V_8 | V_10 ) ;
F_6 ( V_3 , V_7 ) ;
return F_7 ( V_3 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
T_1 * V_17 , int V_18 )
{
* V_17 = F_13 ( V_3 , V_16 ) ;
F_5 ( L_6 , * V_17 , V_18 ? L_7 : L_8 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
int V_18 )
{
int V_7 = F_4 ( V_3 ) ;
V_7 &= ~ ( V_9 | V_8 | V_10 | V_19 ) ;
if ( V_18 )
V_7 |= V_19 ;
F_6 ( V_3 , V_7 ) ;
return F_7 ( V_3 ) ;
}
static int F_15 ( struct V_20 * V_21 ,
struct V_11 * V_22 ,
int V_23 )
{
struct V_2 * V_3 = V_21 -> V_24 ;
struct V_11 * V_12 = NULL ;
int V_25 ;
int V_26 = 0 ;
int V_27 ;
int V_28 ;
int V_29 = 1 ;
unsigned long V_30 = V_31 + V_21 -> V_30 ;
while ( ( V_27 = F_16 ( V_3 ) ) != 0xf8 ) {
if ( F_17 ( V_31 , V_30 ) ) {
F_18 ( 10 ) ;
} else {
F_19 ( & V_21 -> V_32 , L_9
L_10 , V_27 ) ;
return - V_33 ;
}
}
F_20 ( L_11 , V_23 ) ;
if ( V_34 >= 2 ) {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
int V_13 , V_35 ;
V_12 = & V_22 [ V_25 ] ;
V_13 = ( 0x7f & V_12 -> V_13 ) ;
if ( V_12 -> V_14 & V_15 )
F_21 ( V_36 L_12 ,
V_25 , V_12 -> V_37 , V_13 , ( V_13 << 1 ) | 1 ) ;
else {
F_21 ( V_36 L_13 ,
V_25 , V_12 -> V_37 , V_13 , V_13 << 1 ,
V_12 -> V_37 == 0 ? L_14 : L_15 ) ;
for ( V_35 = 0 ; V_35 < V_12 -> V_37 ; V_35 ++ )
F_21 ( L_16 , V_12 -> V_38 [ V_35 ] , V_35 == V_12 -> V_37 - 1 ? L_14 : L_15 ) ;
F_21 ( L_17 ) ;
}
}
}
V_25 = 0 ;
V_28 = - V_39 ;
while ( V_25 < V_23 ) {
V_27 = F_16 ( V_3 ) ;
F_22 ( L_18 , V_27 ) ;
V_12 = & V_22 [ V_25 ] ;
switch ( V_27 ) {
case 0xf8 :
V_29 = F_3 ( V_3 ) ;
break;
case 0x08 :
case 0x10 :
V_29 = F_10 ( V_3 , V_12 ) ;
break;
case 0x18 :
case 0x28 :
if ( V_26 < V_12 -> V_37 ) {
V_29 = F_11 ( V_3 ,
V_12 -> V_38 [ V_26 ] ) ;
V_26 ++ ;
break;
}
V_25 ++ ; V_26 = 0 ;
if ( V_25 == V_23 )
F_9 ( V_3 ) ;
else
V_29 = F_8 ( V_3 ) ;
break;
case 0x20 :
F_5 ( L_19 ) ;
F_9 ( V_3 ) ;
goto V_40;
case 0x40 :
V_29 = F_14 ( V_3 , V_12 -> V_37 > 1 ) ;
break;
case 0x50 :
if ( V_26 < V_12 -> V_37 ) {
F_12 ( V_3 , & V_12 -> V_38 [ V_26 ] , 1 ) ;
V_26 ++ ;
V_29 = F_14 ( V_3 ,
V_26 < V_12 -> V_37 - 1 ) ;
break;
}
V_25 ++ ; V_26 = 0 ;
if ( V_25 == V_23 )
F_9 ( V_3 ) ;
else
V_29 = F_8 ( V_3 ) ;
break;
case 0x48 :
F_5 ( L_20 ) ;
F_9 ( V_3 ) ;
goto V_40;
case 0x30 :
F_5 ( L_21 ) ;
F_9 ( V_3 ) ;
goto V_40;
case 0x38 :
F_5 ( L_22 ) ;
F_3 ( V_3 ) ;
goto V_40;
case 0x58 :
if ( V_26 == V_12 -> V_37 - 1 ) {
F_12 ( V_3 , & V_12 -> V_38 [ V_26 ] , 0 ) ;
V_25 ++ ; V_26 = 0 ;
if ( V_25 == V_23 )
F_9 ( V_3 ) ;
else
V_29 = F_8 ( V_3 ) ;
} else {
F_5 ( L_23
L_24 ,
V_26 , V_12 -> V_37 ) ;
F_9 ( V_3 ) ;
goto V_40;
}
break;
case 0x70 :
F_5 ( L_25 ) ;
F_23 ( V_3 ) ;
goto V_40;
case 0x90 :
F_5 ( L_26 ) ;
F_23 ( V_3 ) ;
goto V_40;
case 0x00 :
F_5 ( L_27 ) ;
F_23 ( V_3 ) ;
goto V_40;
default:
F_24 ( & V_21 -> V_32 , L_28 , V_27 ) ;
break;
}
if ( ! V_29 )
goto V_40;
}
V_28 = V_25 ;
V_40:
F_20 ( L_29
L_30 ,
V_25 , V_23 , F_16 ( V_3 ) ,
F_4 ( V_3 ) ) ;
return V_28 ;
}
static T_2 F_25 ( struct V_20 * V_3 )
{
return V_41 | V_42 ;
}
static unsigned int F_26 ( struct V_20 * V_3 )
{
struct V_2 * V_43 = V_3 -> V_24 ;
F_2 ( V_43 , V_4 , V_44 ) ;
F_2 ( V_43 , V_6 , 0xAA ) ;
F_2 ( V_43 , V_4 , V_45 ) ;
F_2 ( V_43 , V_6 , 0x00 ) ;
F_2 ( V_43 , V_4 , V_44 ) ;
if ( F_13 ( V_43 , V_6 ) == 0xAA ) {
F_21 ( V_36 L_31 , V_3 -> V_46 ) ;
return V_47 ;
} else {
F_21 ( V_36 L_32 , V_3 -> V_46 ) ;
return V_48 ;
}
}
static int F_27 ( struct V_20 * V_3 )
{
struct V_2 * V_43 = V_3 -> V_24 ;
V_3 -> V_49 = & V_50 ;
if ( F_26 ( V_3 ) == V_48 ) {
static int V_51 [] = { 330 , 288 , 217 , 146 , 88 , 59 , 44 , 36 } ;
int clock ;
if ( V_43 -> V_52 > 7 ) {
switch ( V_43 -> V_52 ) {
case 330000 :
V_43 -> V_52 = V_53 ;
break;
case 288000 :
V_43 -> V_52 = V_54 ;
break;
case 217000 :
V_43 -> V_52 = V_55 ;
break;
case 146000 :
V_43 -> V_52 = V_56 ;
break;
case 88000 :
V_43 -> V_52 = V_57 ;
break;
case 59000 :
V_43 -> V_52 = V_58 ;
break;
case 44000 :
V_43 -> V_52 = V_59 ;
break;
case 36000 :
V_43 -> V_52 = V_60 ;
break;
default:
F_21 ( V_61
L_33
L_34 , V_3 -> V_46 ) ;
V_43 -> V_52 = V_58 ;
}
} else {
F_21 ( V_61 L_35
L_36
L_37
L_38 , V_3 -> V_46 ) ;
}
F_23 ( V_43 ) ;
clock = F_28 ( V_43 ) ;
F_21 ( V_36 L_39 ,
V_3 -> V_46 , V_51 [ clock ] ) ;
F_6 ( V_43 , V_62 | clock ) ;
} else {
int clock ;
int V_63 ;
int V_64 , V_65 ;
int V_66 , V_67 ;
int V_68 ;
V_43 -> V_69 = F_1 ;
if ( V_43 -> V_52 > 1265800 ) {
F_21 ( V_61 L_40
L_41 , V_3 -> V_46 ) ;
V_43 -> V_52 = 1265800 ;
}
if ( V_43 -> V_52 < 60300 ) {
F_21 ( V_61 L_42
L_43 , V_3 -> V_46 ) ;
V_43 -> V_52 = 60300 ;
}
clock = F_28 ( V_43 ) / 100 ;
if ( V_43 -> V_52 > 10000 ) {
V_63 = V_70 ;
V_66 = 14 ;
V_67 = 5 ;
V_68 = 22 ;
} else if ( V_43 -> V_52 > 4000 ) {
V_63 = V_71 ;
V_66 = 17 ;
V_67 = 9 ;
V_68 = 22 ;
} else if ( V_43 -> V_52 > 1000 ) {
V_63 = V_72 ;
V_66 = 44 ;
V_67 = 20 ;
V_68 = 58 ;
} else {
V_63 = V_73 ;
V_66 = 157 ;
V_67 = 134 ;
V_68 = 127 ;
}
if ( clock < 648 ) {
V_64 = 255 ;
V_65 = 1000000 - clock * V_68 ;
V_65 /= ( V_74 * clock ) - V_64 ;
} else {
V_64 = ( 1000000 - clock * V_68 ) * V_66 ;
V_64 /= V_74 * clock * ( V_67 + V_66 ) ;
V_65 = V_64 * V_67 / V_66 ;
}
F_23 ( V_43 ) ;
F_21 ( V_36
L_44 , V_3 -> V_46 , clock * 100 ) ;
F_2 ( V_43 , V_4 , V_75 ) ;
F_2 ( V_43 , V_6 , V_63 ) ;
F_2 ( V_43 , V_4 , V_76 ) ;
F_2 ( V_43 , V_6 , V_64 ) ;
F_2 ( V_43 , V_4 , V_77 ) ;
F_2 ( V_43 , V_6 , V_65 ) ;
F_6 ( V_43 , V_62 ) ;
}
F_29 ( 500 ) ;
return 0 ;
}
int F_30 ( struct V_20 * V_3 )
{
int V_78 ;
V_78 = F_27 ( V_3 ) ;
if ( V_78 )
return V_78 ;
return F_31 ( V_3 ) ;
}
int F_32 ( struct V_20 * V_3 )
{
int V_78 ;
V_78 = F_27 ( V_3 ) ;
if ( V_78 )
return V_78 ;
return F_33 ( V_3 ) ;
}
