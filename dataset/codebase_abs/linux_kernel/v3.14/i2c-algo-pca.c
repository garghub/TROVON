static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 ) {
F_2 ( V_2 , V_5 , V_6 ) ;
F_2 ( V_2 , V_7 , 0xA5 ) ;
F_2 ( V_2 , V_7 , 0x5A ) ;
} else {
V_2 -> V_8 ( V_2 -> V_9 ) ;
}
}
static int F_3 ( struct V_1 * V_2 )
{
int V_10 = F_4 ( V_2 ) ;
F_5 ( L_1 ) ;
V_10 |= V_11 ;
V_10 &= ~ ( V_12 | V_13 ) ;
F_6 ( V_2 , V_10 ) ;
return F_7 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_10 = F_4 ( V_2 ) ;
F_5 ( L_2 ) ;
V_10 |= V_11 ;
V_10 &= ~ ( V_12 | V_13 ) ;
F_6 ( V_2 , V_10 ) ;
return F_7 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_10 = F_4 ( V_2 ) ;
F_5 ( L_3 ) ;
V_10 |= V_12 ;
V_10 &= ~ ( V_11 | V_13 ) ;
F_6 ( V_2 , V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_10 = F_4 ( V_2 ) ;
int V_16 ;
V_16 = ( ( 0x7f & V_15 -> V_16 ) << 1 ) ;
if ( V_15 -> V_17 & V_18 )
V_16 |= 1 ;
F_5 ( L_4 ,
V_15 -> V_16 , V_15 -> V_17 & V_18 ? 'R' : 'W' , V_16 ) ;
F_2 ( V_2 , V_19 , V_16 ) ;
V_10 &= ~ ( V_12 | V_11 | V_13 ) ;
F_6 ( V_2 , V_10 ) ;
return F_7 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_20 )
{
int V_10 = F_4 ( V_2 ) ;
F_5 ( L_5 , V_20 ) ;
F_2 ( V_2 , V_19 , V_20 ) ;
V_10 &= ~ ( V_12 | V_11 | V_13 ) ;
F_6 ( V_2 , V_10 ) ;
return F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 * V_20 , int V_21 )
{
* V_20 = F_13 ( V_2 , V_19 ) ;
F_5 ( L_6 , * V_20 , V_21 ? L_7 : L_8 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_21 )
{
int V_10 = F_4 ( V_2 ) ;
V_10 &= ~ ( V_12 | V_11 | V_13 | V_22 ) ;
if ( V_21 )
V_10 |= V_22 ;
F_6 ( V_2 , V_10 ) ;
return F_7 ( V_2 ) ;
}
static int F_15 ( struct V_23 * V_24 ,
struct V_14 * V_25 ,
int V_26 )
{
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_14 * V_15 = NULL ;
int V_28 ;
int V_29 = 0 ;
int V_30 ;
int V_31 ;
int V_32 = 1 ;
unsigned long V_33 = V_34 + V_24 -> V_33 ;
while ( ( V_30 = F_16 ( V_2 ) ) != 0xf8 ) {
if ( F_17 ( V_34 , V_33 ) ) {
F_18 ( 10 ) ;
} else {
F_19 ( & V_24 -> V_35 , L_9
L_10 , V_30 ) ;
return - V_36 ;
}
}
F_20 ( L_11 , V_26 ) ;
if ( V_37 >= 2 ) {
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
int V_16 , V_38 ;
V_15 = & V_25 [ V_28 ] ;
V_16 = ( 0x7f & V_15 -> V_16 ) ;
if ( V_15 -> V_17 & V_18 )
F_21 ( V_39 L_12 ,
V_28 , V_15 -> V_40 , V_16 , ( V_16 << 1 ) | 1 ) ;
else {
F_21 ( V_39 L_13 ,
V_28 , V_15 -> V_40 , V_16 , V_16 << 1 ,
V_15 -> V_40 == 0 ? L_14 : L_15 ) ;
for ( V_38 = 0 ; V_38 < V_15 -> V_40 ; V_38 ++ )
F_21 ( L_16 , V_15 -> V_41 [ V_38 ] , V_38 == V_15 -> V_40 - 1 ? L_14 : L_15 ) ;
F_21 ( L_17 ) ;
}
}
}
V_28 = 0 ;
V_31 = - V_42 ;
while ( V_28 < V_26 ) {
V_30 = F_16 ( V_2 ) ;
F_22 ( L_18 , V_30 ) ;
V_15 = & V_25 [ V_28 ] ;
switch ( V_30 ) {
case 0xf8 :
V_32 = F_3 ( V_2 ) ;
break;
case 0x08 :
case 0x10 :
V_32 = F_10 ( V_2 , V_15 ) ;
break;
case 0x18 :
case 0x28 :
if ( V_29 < V_15 -> V_40 ) {
V_32 = F_11 ( V_2 ,
V_15 -> V_41 [ V_29 ] ) ;
V_29 ++ ;
break;
}
V_28 ++ ; V_29 = 0 ;
if ( V_28 == V_26 )
F_9 ( V_2 ) ;
else
V_32 = F_8 ( V_2 ) ;
break;
case 0x20 :
F_5 ( L_19 ) ;
F_9 ( V_2 ) ;
V_31 = - V_43 ;
goto V_44;
case 0x40 :
V_32 = F_14 ( V_2 , V_15 -> V_40 > 1 ) ;
break;
case 0x50 :
if ( V_29 < V_15 -> V_40 ) {
F_12 ( V_2 , & V_15 -> V_41 [ V_29 ] , 1 ) ;
V_29 ++ ;
V_32 = F_14 ( V_2 ,
V_29 < V_15 -> V_40 - 1 ) ;
break;
}
V_28 ++ ; V_29 = 0 ;
if ( V_28 == V_26 )
F_9 ( V_2 ) ;
else
V_32 = F_8 ( V_2 ) ;
break;
case 0x48 :
F_5 ( L_20 ) ;
F_9 ( V_2 ) ;
V_31 = - V_43 ;
goto V_44;
case 0x30 :
F_5 ( L_21 ) ;
F_9 ( V_2 ) ;
goto V_44;
case 0x38 :
F_5 ( L_22 ) ;
F_3 ( V_2 ) ;
goto V_44;
case 0x58 :
if ( V_29 == V_15 -> V_40 - 1 ) {
F_12 ( V_2 , & V_15 -> V_41 [ V_29 ] , 0 ) ;
V_28 ++ ; V_29 = 0 ;
if ( V_28 == V_26 )
F_9 ( V_2 ) ;
else
V_32 = F_8 ( V_2 ) ;
} else {
F_5 ( L_23
L_24 ,
V_29 , V_15 -> V_40 ) ;
F_9 ( V_2 ) ;
goto V_44;
}
break;
case 0x70 :
F_5 ( L_25 ) ;
F_1 ( V_2 ) ;
goto V_44;
case 0x90 :
F_5 ( L_26 ) ;
F_1 ( V_2 ) ;
goto V_44;
case 0x00 :
F_5 ( L_27 ) ;
F_1 ( V_2 ) ;
goto V_44;
default:
F_23 ( & V_24 -> V_35 , L_28 , V_30 ) ;
break;
}
if ( ! V_32 )
goto V_44;
}
V_31 = V_28 ;
V_44:
F_20 ( L_29
L_30 ,
V_28 , V_26 , F_16 ( V_2 ) ,
F_4 ( V_2 ) ) ;
return V_31 ;
}
static T_2 F_24 ( struct V_23 * V_2 )
{
return V_45 | V_46 ;
}
static unsigned int F_25 ( struct V_23 * V_2 )
{
struct V_1 * V_47 = V_2 -> V_27 ;
F_2 ( V_47 , V_5 , V_48 ) ;
F_2 ( V_47 , V_7 , 0xAA ) ;
F_2 ( V_47 , V_5 , V_49 ) ;
F_2 ( V_47 , V_7 , 0x00 ) ;
F_2 ( V_47 , V_5 , V_48 ) ;
if ( F_13 ( V_47 , V_7 ) == 0xAA ) {
F_21 ( V_39 L_31 , V_2 -> V_50 ) ;
V_47 -> V_3 = V_4 ;
} else {
F_21 ( V_39 L_32 , V_2 -> V_50 ) ;
V_47 -> V_3 = V_51 ;
}
return V_47 -> V_3 ;
}
static int F_26 ( struct V_23 * V_2 )
{
struct V_1 * V_47 = V_2 -> V_27 ;
V_2 -> V_52 = & V_53 ;
if ( F_25 ( V_2 ) == V_51 ) {
static int V_54 [] = { 330 , 288 , 217 , 146 , 88 , 59 , 44 , 36 } ;
int clock ;
if ( V_47 -> V_55 > 7 ) {
switch ( V_47 -> V_55 ) {
case 330000 :
V_47 -> V_55 = V_56 ;
break;
case 288000 :
V_47 -> V_55 = V_57 ;
break;
case 217000 :
V_47 -> V_55 = V_58 ;
break;
case 146000 :
V_47 -> V_55 = V_59 ;
break;
case 88000 :
V_47 -> V_55 = V_60 ;
break;
case 59000 :
V_47 -> V_55 = V_61 ;
break;
case 44000 :
V_47 -> V_55 = V_62 ;
break;
case 36000 :
V_47 -> V_55 = V_63 ;
break;
default:
F_21 ( V_64
L_33
L_34 , V_2 -> V_50 ) ;
V_47 -> V_55 = V_61 ;
}
} else {
F_21 ( V_64 L_35
L_36
L_37
L_38 , V_2 -> V_50 ) ;
}
F_1 ( V_47 ) ;
clock = F_27 ( V_47 ) ;
F_21 ( V_39 L_39 ,
V_2 -> V_50 , V_54 [ clock ] ) ;
F_6 ( V_47 , V_65 | clock ) ;
} else {
int clock ;
int V_66 ;
int V_67 , V_68 ;
int V_69 , V_70 ;
int V_71 ;
if ( V_47 -> V_55 > 1265800 ) {
F_21 ( V_64 L_40
L_41 , V_2 -> V_50 ) ;
V_47 -> V_55 = 1265800 ;
}
if ( V_47 -> V_55 < 60300 ) {
F_21 ( V_64 L_42
L_43 , V_2 -> V_50 ) ;
V_47 -> V_55 = 60300 ;
}
clock = F_27 ( V_47 ) / 100 ;
if ( V_47 -> V_55 > 1000000 ) {
V_66 = V_72 ;
V_69 = 14 ;
V_70 = 5 ;
V_71 = 22 ;
} else if ( V_47 -> V_55 > 400000 ) {
V_66 = V_73 ;
V_69 = 17 ;
V_70 = 9 ;
V_71 = 22 ;
} else if ( V_47 -> V_55 > 100000 ) {
V_66 = V_74 ;
V_69 = 44 ;
V_70 = 20 ;
V_71 = 58 ;
} else {
V_66 = V_75 ;
V_69 = 157 ;
V_70 = 134 ;
V_71 = 127 ;
}
if ( clock < 648 ) {
V_67 = 255 ;
V_68 = 1000000 - clock * V_71 ;
V_68 /= ( V_76 * clock ) - V_67 ;
} else {
V_67 = ( 1000000 - clock * V_71 ) * V_69 ;
V_67 /= V_76 * clock * ( V_70 + V_69 ) ;
V_68 = V_67 * V_70 / V_69 ;
}
F_1 ( V_47 ) ;
F_21 ( V_39
L_44 , V_2 -> V_50 , clock * 100 ) ;
F_2 ( V_47 , V_5 , V_77 ) ;
F_2 ( V_47 , V_7 , V_66 ) ;
F_2 ( V_47 , V_5 , V_78 ) ;
F_2 ( V_47 , V_7 , V_67 ) ;
F_2 ( V_47 , V_5 , V_79 ) ;
F_2 ( V_47 , V_7 , V_68 ) ;
F_6 ( V_47 , V_65 ) ;
}
F_28 ( 500 ) ;
return 0 ;
}
int F_29 ( struct V_23 * V_2 )
{
int V_80 ;
V_80 = F_26 ( V_2 ) ;
if ( V_80 )
return V_80 ;
return F_30 ( V_2 ) ;
}
int F_31 ( struct V_23 * V_2 )
{
int V_80 ;
V_80 = F_26 ( V_2 ) ;
if ( V_80 )
return V_80 ;
return F_32 ( V_2 ) ;
}
