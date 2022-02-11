static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_4 = V_6 -> V_7 ;
if ( F_2 ( V_6 -> V_8 [ V_4 ] , 0 , 1 ) == V_9 ) {
if ( V_4 % 2 != 0 )
return - V_10 ;
if ( V_6 -> V_11 [ V_4 ] != V_12 ||
V_6 -> V_11 [ V_4 + 1 ] != V_12 )
return - V_10 ;
if ( V_3 == true ) {
V_6 -> V_13 |= F_3 ( V_4 / 2 + 16 ) ;
V_6 -> V_13 &= ~ F_3 ( V_4 / 2 ) ;
} else {
V_6 -> V_13 |= F_3 ( V_4 / 2 ) ;
V_6 -> V_13 &= ~ F_3 ( V_4 / 2 + 16 ) ;
}
}
return 0 ;
}
static T_2 F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_21 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_7 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_23 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_8 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_24 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_9 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_25 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_10 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_26 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_27 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_12 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_28 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_29 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_30 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
int V_32 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
if ( V_19 )
V_6 -> V_34 = 0x0 ;
V_6 -> V_34 &= ~ ( V_35 | V_36 ) ;
V_6 -> V_37 &= ~ ( F_3 ( 1 ) | F_3 ( 2 ) ) ;
V_6 -> V_34 &= ~ ( V_38 |
V_39 ) ;
V_6 -> V_37 &= ~ ( F_3 ( 16 ) | F_3 ( 17 ) ) ;
V_6 -> V_40 = 0x0 ;
V_6 -> V_41 = 0x0 ;
V_6 -> V_42 = 0x0 ;
V_6 -> V_43 = 0x0 ;
if ( V_2 -> V_44 == false )
V_6 -> V_45 = 0x8 ;
V_6 -> V_46 |= F_3 ( 0 ) ;
if ( V_2 -> V_23 == true ) {
V_6 -> V_34 |= V_47 ;
V_6 -> V_46 |= F_3 ( 9 ) ;
}
V_6 -> V_13 = 0x0 ;
V_6 -> V_48 = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_28 - 1 ; V_32 ++ )
V_6 -> V_49 [ V_32 ] = 0x0 ;
V_6 -> V_50 = 0x0 ;
V_6 -> V_51 = 0x0 ;
V_6 -> V_52 = 0x0 ;
V_6 -> V_53 = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_24 ; V_32 ++ ) {
V_6 -> V_54 [ V_32 ] = 0x0 ;
V_6 -> V_55 [ V_32 ] = 0x0 ;
V_6 -> V_56 [ V_32 ] = 0x0 ;
}
V_6 -> V_57 = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_29 ; V_32 ++ )
V_6 -> V_58 [ V_32 ] = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_30 ; V_32 ++ ) {
V_6 -> V_59 [ V_32 ] = 0x0 ;
V_6 -> V_60 [ V_32 ] = 0x0 ;
}
V_6 -> V_7 = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_23 * 2 ; V_32 ++ ) {
V_6 -> V_61 [ V_32 ] = 0x0 ;
V_6 -> V_8 [ V_32 ] = 0x0 ;
V_6 -> V_11 [ V_32 ] = V_62 ;
}
V_6 -> V_63 = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_26 ; V_32 ++ ) {
V_6 -> V_64 [ V_32 ] = 0x0 ;
V_6 -> V_65 [ V_32 ] = 0x0 ;
}
V_6 -> V_66 = 0x0 ;
V_6 -> V_67 = 0x0 ;
V_6 -> V_68 = 0x0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_27 ; V_32 ++ )
V_6 -> V_69 [ V_32 ] = 0x0 ;
V_6 -> V_70 = 0x0 ;
V_6 -> V_71 = 0x0 ;
V_2 -> V_72 = V_2 -> V_73 + 1 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_19 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_34 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_20 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 , V_34 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_34 = V_19 & V_74 ;
if ( V_6 -> V_34 & V_75 )
F_1 ( V_2 , true ) ;
else
F_1 ( V_2 , false ) ;
if ( V_2 -> V_76 == true ) {
V_6 -> V_37 &= ~ ( F_3 ( 1 ) | F_3 ( 2 ) ) ;
if ( V_6 -> V_34 & V_35 )
V_6 -> V_37 |= F_3 ( 1 ) ;
if ( V_6 -> V_34 & V_36 )
V_6 -> V_37 |= F_3 ( 2 ) ;
if ( V_6 -> V_34 & V_77 )
V_6 -> V_37 |= F_3 ( 1 ) | F_3 ( 2 ) ;
}
if ( ( V_6 -> V_34 & V_78 ) && ( V_2 -> V_79 == true ) )
V_6 -> V_37 |= F_3 ( 3 ) ;
else
V_6 -> V_37 &= ~ F_3 ( 3 ) ;
if ( ( V_6 -> V_34 & V_80 ) &&
( V_2 -> V_81 == true ) )
V_6 -> V_37 |= F_3 ( 4 ) ;
else
V_6 -> V_37 &= ~ F_3 ( 4 ) ;
if ( ( V_6 -> V_34 & V_82 ) && ( V_2 -> V_83 ) )
V_6 -> V_37 |= F_3 ( 6 ) ;
else
V_6 -> V_37 &= ~ F_3 ( 6 ) ;
if ( ( V_6 -> V_34 & V_84 ) && ( V_2 -> V_85 ) )
V_6 -> V_37 |= F_3 ( 7 ) ;
else
V_6 -> V_37 &= ~ F_3 ( 7 ) ;
V_34 = F_21 ( V_6 -> V_34 ) ;
if ( V_2 -> V_86 == true ) {
V_6 -> V_37 &= ~ ( F_3 ( 8 ) | F_3 ( 9 ) | F_3 ( 10 ) ) ;
V_6 -> V_37 |= V_34 << 8 ;
}
if ( ( V_6 -> V_34 & V_87 ) && ( V_2 -> V_88 ) )
V_6 -> V_37 |= F_3 ( 11 ) ;
else
V_6 -> V_37 &= ~ F_3 ( 11 ) ;
if ( ( V_6 -> V_34 & V_89 ) &&
( V_2 -> V_90 == true ) )
V_6 -> V_37 |= F_3 ( 12 ) ;
else
V_6 -> V_37 &= ~ F_3 ( 12 ) ;
V_34 = F_22 ( V_6 -> V_34 ) ;
V_6 -> V_37 &= ~ ( F_3 ( 13 ) | F_3 ( 14 ) ) ;
if ( ( V_34 & F_3 ( 0 ) ) && ( V_2 -> V_91 & F_3 ( 0 ) ) )
V_6 -> V_37 |= F_3 ( 13 ) ;
if ( ( V_34 & F_3 ( 1 ) ) && ( V_2 -> V_91 & F_3 ( 1 ) ) )
V_6 -> V_37 |= F_3 ( 14 ) ;
if ( ( V_6 -> V_34 & V_92 ) &&
( V_2 -> V_93 == true ) )
V_6 -> V_41 |= F_3 ( 11 ) ;
else
V_6 -> V_41 &= ~ F_3 ( 11 ) ;
if ( ( V_6 -> V_34 & V_94 ) &&
( V_2 -> V_95 == true ) )
V_6 -> V_41 |= F_3 ( 12 ) ;
else
V_6 -> V_41 &= ~ F_3 ( 12 ) ;
if ( V_6 -> V_34 & V_96 )
V_6 -> V_43 |= F_3 ( 8 ) ;
else
V_6 -> V_43 &= ~ F_3 ( 8 ) ;
if ( V_6 -> V_34 & V_97 )
V_6 -> V_43 |= F_3 ( 10 ) ;
else
V_6 -> V_43 &= ~ F_3 ( 10 ) ;
if ( ( V_6 -> V_34 & V_98 ) &&
( V_2 -> V_99 == true ) )
V_6 -> V_43 |= F_3 ( 13 ) ;
else
V_6 -> V_43 &= ~ F_3 ( 13 ) ;
if ( V_6 -> V_34 & V_47 )
V_6 -> V_46 |= F_3 ( 9 ) ;
else
V_6 -> V_46 &= ~ F_3 ( 9 ) ;
if ( V_6 -> V_34 & V_100 )
V_6 -> V_46 |= F_3 ( 10 ) ;
else
V_6 -> V_46 &= ~ F_3 ( 10 ) ;
if ( ( V_6 -> V_34 & V_101 ) &&
( V_2 -> V_102 == true ) )
V_6 -> V_46 |= F_3 ( 11 ) ;
else
V_6 -> V_46 &= ~ F_3 ( 11 ) ;
if ( V_6 -> V_34 & ( V_103 | V_104 ) )
F_23 ( V_6 ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_24 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_105 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_25 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
if ( V_19 > V_2 -> V_106 ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_10 ;
}
V_6 -> V_105 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_26 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_40 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_27 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
switch ( V_2 -> V_107 ) {
case 0x0 :
V_6 -> V_40 = V_19 & 0xFF ;
break;
case 0x1 :
V_6 -> V_40 = V_19 & 0xFFFF ;
break;
case 0x2 :
V_6 -> V_40 = V_19 & 0xFFFFFF ;
break;
case 0x3 :
V_6 -> V_40 = V_19 ;
break;
default:
break;
}
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_28 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = F_2 ( V_6 -> V_41 , 0 , 3 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_29 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_41 &= ~ ( F_3 ( 0 ) | F_3 ( 1 ) | F_3 ( 2 ) | F_3 ( 3 ) ) ;
switch ( V_2 -> V_107 ) {
case 0x0 :
V_6 -> V_41 |= V_19 & F_3 ( 1 ) ;
break;
case 0x1 :
V_6 -> V_41 |= V_19 & ( F_3 ( 0 ) | F_3 ( 1 ) ) ;
break;
case 0x2 :
V_6 -> V_41 |= V_19 & ( F_3 ( 0 ) | F_3 ( 1 ) | F_3 ( 2 ) ) ;
break;
case 0x3 :
V_6 -> V_41 |= V_19 & 0xF ;
break;
default:
break;
}
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_30 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_42 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_31 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( ! V_2 -> V_88 )
return - V_10 ;
V_6 -> V_42 = V_19 & V_108 ;
return V_31 ;
}
static T_2 F_32 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_45 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_33 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_2 -> V_44 == true )
return - V_10 ;
V_6 -> V_45 = V_19 & V_109 ;
return V_31 ;
}
static T_2 F_34 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_110 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_35 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 < V_2 -> V_111 )
return - V_10 ;
V_6 -> V_110 = V_19 & V_112 ;
return V_31 ;
}
static T_2 F_36 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_113 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_37 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_2 -> V_79 == false )
return - V_10 ;
if ( ! V_2 -> V_23 )
return - V_10 ;
if ( F_2 ( V_19 , 0 , 7 ) > V_2 -> V_23 )
return - V_10 ;
V_6 -> V_113 = V_19 ;
return V_31 ;
}
static T_2 F_38 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_46 & V_108 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_39 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_19 &= V_108 ;
V_6 -> V_46 &= ~ V_108 ;
V_6 -> V_46 |= V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_40 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = F_2 ( V_6 -> V_46 , 16 , 19 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_41 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_46 &= ~ ( F_3 ( 16 ) | F_3 ( 17 ) | F_3 ( 19 ) ) ;
V_19 &= V_2 -> V_114 ;
V_6 -> V_46 |= ( V_19 << 16 ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_42 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = F_2 ( V_6 -> V_46 , 20 , 23 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_43 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_46 &= ~ ( F_3 ( 20 ) | F_3 ( 21 ) | F_3 ( 22 ) ) ;
V_19 &= V_2 -> V_115 ;
V_6 -> V_46 |= ( V_19 << 20 ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_44 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_7 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_45 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 >= V_2 -> V_23 * 2 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_7 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_46 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_2 V_116 ;
T_1 V_19 , V_4 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
V_19 = F_2 ( V_6 -> V_8 [ V_4 ] , 0 , 1 ) ;
V_116 = F_6 ( V_18 , V_22 , L_2 ,
V_19 == V_9 ? L_3 :
( V_19 == V_117 ? L_4 :
( V_19 == V_118 ? L_5 :
L_6 ) ) ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_116 ;
}
static T_2 F_47 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
char V_119 [ 20 ] = L_7 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( strlen ( V_18 ) >= 20 )
return - V_10 ;
if ( sscanf ( V_18 , L_8 , V_119 ) != 1 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! strcmp ( V_119 , L_3 ) )
V_6 -> V_8 [ V_4 ] &= ~ ( F_3 ( 0 ) | F_3 ( 1 ) ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_48 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_4 = V_6 -> V_7 ;
F_17 ( & V_2 -> V_33 ) ;
if ( ! ( V_6 -> V_11 [ V_4 ] == V_62 ||
V_6 -> V_11 [ V_4 ] == V_120 ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_19 = ( unsigned long ) V_6 -> V_61 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_49 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! ( V_6 -> V_11 [ V_4 ] == V_62 ||
V_6 -> V_11 [ V_4 ] == V_120 ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_6 -> V_61 [ V_4 ] = ( V_122 ) V_19 ;
V_6 -> V_11 [ V_4 ] = V_120 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_50 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_123 , V_124 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( V_4 % 2 != 0 ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
if ( ! ( ( V_6 -> V_11 [ V_4 ] == V_62 &&
V_6 -> V_11 [ V_4 + 1 ] == V_62 ) ||
( V_6 -> V_11 [ V_4 ] == V_12 &&
V_6 -> V_11 [ V_4 + 1 ] == V_12 ) ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_123 = ( unsigned long ) V_6 -> V_61 [ V_4 ] ;
V_124 = ( unsigned long ) V_6 -> V_61 [ V_4 + 1 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_9 , V_123 , V_124 ) ;
}
static T_2 F_51 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_123 , V_124 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( sscanf ( V_18 , L_10 , & V_123 , & V_124 ) != 2 )
return - V_10 ;
if ( V_123 > V_124 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( V_4 % 2 != 0 ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
if ( ! ( ( V_6 -> V_11 [ V_4 ] == V_62 &&
V_6 -> V_11 [ V_4 + 1 ] == V_62 ) ||
( V_6 -> V_11 [ V_4 ] == V_12 &&
V_6 -> V_11 [ V_4 + 1 ] == V_12 ) ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_6 -> V_61 [ V_4 ] = ( V_122 ) V_123 ;
V_6 -> V_11 [ V_4 ] = V_12 ;
V_6 -> V_61 [ V_4 + 1 ] = ( V_122 ) V_124 ;
V_6 -> V_11 [ V_4 + 1 ] = V_12 ;
if ( V_6 -> V_34 & V_75 )
F_1 ( V_2 , true ) ;
else
F_1 ( V_2 , false ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_52 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! ( V_6 -> V_11 [ V_4 ] == V_62 ||
V_6 -> V_11 [ V_4 ] == V_125 ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_19 = ( unsigned long ) V_6 -> V_61 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_53 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! V_2 -> V_23 ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_10 ;
}
if ( ! ( V_6 -> V_11 [ V_4 ] == V_62 ||
V_6 -> V_11 [ V_4 ] == V_125 ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_6 -> V_61 [ V_4 ] = ( V_122 ) V_19 ;
V_6 -> V_11 [ V_4 ] = V_125 ;
V_6 -> V_48 |= F_3 ( V_4 ) ;
V_6 -> V_46 |= F_3 ( 9 ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_54 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! ( V_6 -> V_11 [ V_4 ] == V_62 ||
V_6 -> V_11 [ V_4 ] == V_126 ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_19 = ( unsigned long ) V_6 -> V_61 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_55 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! V_2 -> V_23 ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_10 ;
}
if ( ! ( V_6 -> V_11 [ V_4 ] == V_62 ||
V_6 -> V_11 [ V_4 ] == V_126 ) ) {
F_18 ( & V_2 -> V_33 ) ;
return - V_121 ;
}
V_6 -> V_61 [ V_4 ] = ( V_122 ) V_19 ;
V_6 -> V_11 [ V_4 ] = V_126 ;
V_6 -> V_48 |= F_3 ( V_4 + 16 ) ;
V_6 -> V_46 |= F_3 ( 9 ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_56 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_2 V_116 ;
T_1 V_4 , V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
V_19 = F_2 ( V_6 -> V_8 [ V_4 ] , 2 , 3 ) ;
V_116 = F_6 ( V_18 , V_22 , L_2 , V_19 == V_127 ? L_11 :
( V_19 == V_128 ? L_12 :
( V_19 == V_129 ? L_13 : L_14 ) ) ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_116 ;
}
static T_2 F_57 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
char V_119 [ 10 ] = L_7 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( strlen ( V_18 ) >= 10 )
return - V_10 ;
if ( sscanf ( V_18 , L_8 , V_119 ) != 1 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
if ( ! strcmp ( V_119 , L_11 ) )
V_6 -> V_8 [ V_4 ] &= ~ ( F_3 ( 2 ) | F_3 ( 3 ) ) ;
else if ( ! strcmp ( V_119 , L_12 ) ) {
if ( V_2 -> V_26 ) {
V_6 -> V_8 [ V_4 ] |= F_3 ( 2 ) ;
V_6 -> V_8 [ V_4 ] &= ~ F_3 ( 3 ) ;
}
} else if ( ! strcmp ( V_119 , L_13 ) ) {
if ( V_2 -> V_27 ) {
V_6 -> V_8 [ V_4 ] &= ~ F_3 ( 2 ) ;
V_6 -> V_8 [ V_4 ] |= F_3 ( 3 ) ;
}
} else if ( ! strcmp ( V_119 , L_14 ) ) {
if ( V_2 -> V_26 )
V_6 -> V_8 [ V_4 ] |= F_3 ( 2 ) ;
if ( V_2 -> V_27 )
V_6 -> V_8 [ V_4 ] |= F_3 ( 3 ) ;
}
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_58 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
V_19 = F_2 ( V_6 -> V_8 [ V_4 ] , 4 , 6 ) ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_59 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( ( V_2 -> V_26 <= 1 ) && ( V_2 -> V_27 <= 1 ) )
return - V_10 ;
if ( V_19 >= ( V_2 -> V_26 >= V_2 -> V_27 ?
V_2 -> V_26 : V_2 -> V_27 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_7 ;
V_6 -> V_8 [ V_4 ] &= ~ ( F_3 ( 4 ) | F_3 ( 5 ) | F_3 ( 6 ) ) ;
V_6 -> V_8 [ V_4 ] |= ( V_19 << 4 ) ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_60 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_130 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_61 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 >= V_2 -> V_28 - 1 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_130 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_62 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_51 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_63 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 >= V_2 -> V_28 )
return - V_10 ;
V_6 -> V_51 = V_19 ;
return V_31 ;
}
static T_2 F_64 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_130 ;
V_19 = V_6 -> V_49 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_65 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_130 ;
V_6 -> V_49 [ V_4 ] = V_19 & 0xFF ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_66 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_50 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_67 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( ! ( V_2 -> V_28 ) )
return - V_10 ;
V_6 -> V_50 = V_19 & V_108 ;
return V_31 ;
}
static T_2 F_68 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_53 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_69 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 >= V_2 -> V_24 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_53 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_70 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_53 ;
V_19 = V_6 -> V_54 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_71 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 > V_131 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_53 ;
V_6 -> V_54 [ V_4 ] = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_72 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_53 ;
V_19 = V_6 -> V_56 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_73 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 > V_131 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_53 ;
V_6 -> V_56 [ V_4 ] = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_74 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_53 ;
V_19 = V_6 -> V_55 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_75 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_53 ;
V_6 -> V_55 [ V_4 ] = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_76 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_57 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_77 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( ( V_19 == 0 ) || ( V_19 >= V_2 -> V_29 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_57 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_78 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_57 ;
V_19 = V_6 -> V_58 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_79 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_57 ;
if ( V_4 % 2 != 0 )
V_19 &= ~ F_3 ( 21 ) ;
V_6 -> V_58 [ V_4 ] = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_80 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_63 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_81 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 >= V_2 -> V_26 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_63 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_82 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
T_1 V_4 ;
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_63 ;
V_19 = ( unsigned long ) V_6 -> V_65 [ V_4 ] ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_83 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_4 ;
unsigned long V_132 , V_133 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_83 || ! V_2 -> V_26 )
return - V_10 ;
if ( F_16 ( V_18 , 16 , & V_132 ) )
return - V_10 ;
V_133 = F_84 ( V_132 ) ;
F_17 ( & V_2 -> V_33 ) ;
V_4 = V_6 -> V_63 ;
V_6 -> V_64 [ V_4 ] = ( V_122 ) V_133 ;
V_6 -> V_65 [ V_4 ] = ( V_122 ) V_132 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_85 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_123 , V_124 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_123 = V_6 -> V_66 ;
V_124 = V_6 -> V_67 ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_9 , V_123 , V_124 ) ;
}
static T_2 F_86 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_32 , V_134 , V_135 ;
unsigned long V_123 , V_124 , V_136 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_83 || ! V_2 -> V_26 )
return - V_10 ;
if ( sscanf ( V_18 , L_10 , & V_123 , & V_124 ) != 2 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
switch ( V_2 -> V_26 ) {
case 0x1 :
V_6 -> V_66 = V_123 & 0xFF ;
break;
case 0x2 :
V_6 -> V_66 = V_123 & 0xFFFF ;
break;
case 0x3 :
V_6 -> V_66 = V_123 & 0xFFFFFF ;
break;
case 0x4 :
V_6 -> V_66 = V_123 ;
break;
case 0x5 :
V_6 -> V_66 = V_123 ;
V_6 -> V_67 = V_124 & 0xFF ;
break;
case 0x6 :
V_6 -> V_66 = V_123 ;
V_6 -> V_67 = V_124 & 0xFFFF ;
break;
case 0x7 :
V_6 -> V_66 = V_123 ;
V_6 -> V_67 = V_124 & 0xFFFFFF ;
break;
case 0x8 :
V_6 -> V_66 = V_123 ;
V_6 -> V_67 = V_124 ;
break;
default:
break;
}
V_136 = V_6 -> V_66 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_26 ; V_32 ++ ) {
V_135 = V_136 & V_108 ;
for ( V_134 = 0 ; V_134 < 8 ; V_134 ++ ) {
if ( V_135 & 1 )
V_6 -> V_64 [ V_32 ] &= ~ ( 0xFF << ( V_134 * 8 ) ) ;
V_135 >>= 1 ;
}
if ( V_32 == 3 )
V_136 = V_6 -> V_67 ;
else
V_136 >>= 0x8 ;
}
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_87 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = V_6 -> V_68 ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_88 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
if ( V_19 >= V_2 -> V_27 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_68 = V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_89 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_19 = ( unsigned long ) V_6 -> V_69 [ V_6 -> V_68 ] ;
return F_6 ( V_18 , V_22 , L_1 , V_19 ) ;
}
static T_2 F_90 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
unsigned long V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_85 || ! V_2 -> V_27 )
return - V_10 ;
if ( F_16 ( V_18 , 16 , & V_19 ) )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
V_6 -> V_69 [ V_6 -> V_68 ] = ( V_122 ) V_19 ;
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_91 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
unsigned long V_123 , V_124 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_17 ( & V_2 -> V_33 ) ;
V_123 = V_6 -> V_70 ;
V_124 = V_6 -> V_71 ;
F_18 ( & V_2 -> V_33 ) ;
return F_6 ( V_18 , V_22 , L_9 , V_123 , V_124 ) ;
}
static T_2 F_92 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_31 )
{
T_1 V_32 , V_134 , V_135 ;
unsigned long V_123 , V_124 , V_136 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_2 -> V_85 || ! V_2 -> V_27 )
return - V_10 ;
if ( sscanf ( V_18 , L_10 , & V_123 , & V_124 ) != 2 )
return - V_10 ;
F_17 ( & V_2 -> V_33 ) ;
switch ( V_2 -> V_27 ) {
case 0x1 :
V_6 -> V_70 = V_123 & 0xFF ;
break;
case 0x2 :
V_6 -> V_70 = V_123 & 0xFFFF ;
break;
case 0x3 :
V_6 -> V_70 = V_123 & 0xFFFFFF ;
break;
case 0x4 :
V_6 -> V_70 = V_123 ;
break;
case 0x5 :
V_6 -> V_70 = V_123 ;
V_6 -> V_71 = V_124 & 0xFF ;
break;
case 0x6 :
V_6 -> V_70 = V_123 ;
V_6 -> V_71 = V_124 & 0xFFFF ;
break;
case 0x7 :
V_6 -> V_70 = V_123 ;
V_6 -> V_71 = V_124 & 0xFFFFFF ;
break;
case 0x8 :
V_6 -> V_70 = V_123 ;
V_6 -> V_71 = V_124 ;
break;
default:
break;
}
V_136 = V_6 -> V_70 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_27 ; V_32 ++ ) {
V_135 = V_136 & V_108 ;
for ( V_134 = 0 ; V_134 < 8 ; V_134 ++ ) {
if ( V_135 & 1 )
V_6 -> V_69 [ V_32 ] &= ~ ( 0xFF << ( V_134 * 8 ) ) ;
V_135 >>= 1 ;
}
if ( V_32 == 3 )
V_136 = V_6 -> V_71 ;
else
V_136 >>= 0x8 ;
}
F_18 ( & V_2 -> V_33 ) ;
return V_31 ;
}
static T_2 F_93 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
int V_19 ;
struct V_1 * V_2 = F_5 ( V_15 -> V_20 ) ;
V_19 = V_2 -> V_73 ;
return F_6 ( V_18 , V_22 , L_15 , V_19 ) ;
}
static void F_94 ( void * V_137 )
{
struct V_138 * V_139 = V_137 ;
V_139 -> V_137 = F_95 ( V_139 -> V_140 ) ;
}
static T_4 F_96 ( const struct V_14 * V_15 , T_4 V_141 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_138 V_139 ;
V_139 . V_140 = V_2 -> V_142 + V_141 ;
F_97 ( V_2 -> V_73 , F_94 , & V_139 , 1 ) ;
return V_139 . V_137 ;
}
