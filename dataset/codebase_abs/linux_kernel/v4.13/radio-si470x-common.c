static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_3 == V_3 )
return 0 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 [ V_5 ] &= ~ V_6 ;
V_2 -> V_4 [ V_5 ] |= V_2 -> V_3 << 6 ;
return F_2 ( V_2 , V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned short V_7 )
{
int V_8 ;
unsigned long V_9 ;
bool V_10 = false ;
V_2 -> V_4 [ V_11 ] &= ~ V_12 ;
V_2 -> V_4 [ V_11 ] |= V_13 | V_7 ;
V_8 = F_2 ( V_2 , V_11 ) ;
if ( V_8 < 0 )
goto V_14;
F_4 ( & V_2 -> V_15 ) ;
V_9 = F_5 ( & V_2 -> V_15 ,
F_6 ( V_16 ) ) ;
if ( V_9 == 0 )
V_10 = true ;
if ( ( V_2 -> V_4 [ V_17 ] & V_18 ) == 0 )
F_7 ( & V_2 -> V_19 . V_20 , L_1 ) ;
if ( V_10 )
F_7 ( & V_2 -> V_19 . V_20 ,
L_2 , V_16 ) ;
V_2 -> V_4 [ V_11 ] &= ~ V_13 ;
V_8 = F_2 ( V_2 , V_11 ) ;
V_14:
return V_8 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
switch ( ( V_2 -> V_4 [ V_5 ] & V_21 ) >> 4 ) {
case 0 :
return 200 * 16 ;
case 1 :
return 100 * 16 ;
default:
return 50 * 16 ;
}
}
static int F_9 ( struct V_1 * V_2 , unsigned int * V_22 )
{
int V_7 , V_8 ;
V_8 = F_10 ( V_2 , V_23 ) ;
V_7 = V_2 -> V_4 [ V_23 ] & V_24 ;
* V_22 = V_7 * F_8 ( V_2 ) + V_25 [ V_2 -> V_3 ] . V_26 ;
return V_8 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_22 )
{
unsigned short V_7 ;
V_22 = F_12 ( V_22 , V_25 [ V_2 -> V_3 ] . V_26 ,
V_25 [ V_2 -> V_3 ] . V_27 ) ;
V_7 = ( V_22 - V_25 [ V_2 -> V_3 ] . V_26 ) / F_8 ( V_2 ) ;
return F_3 ( V_2 , V_7 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
int V_3 , V_8 ;
unsigned int V_22 ;
bool V_10 = false ;
unsigned long V_9 ;
if ( V_29 -> V_26 || V_29 -> V_27 ) {
for ( V_3 = 0 ; V_3 < F_14 ( V_25 ) ; V_3 ++ ) {
if ( V_25 [ V_3 ] . V_26 == V_29 -> V_26 &&
V_25 [ V_3 ] . V_27 == V_29 -> V_27 )
break;
}
if ( V_3 == F_14 ( V_25 ) )
return - V_30 ;
} else
V_3 = 1 ;
if ( V_2 -> V_3 != V_3 ) {
V_8 = F_9 ( V_2 , & V_22 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_2 , V_22 ) ;
if ( V_8 )
return V_8 ;
}
V_2 -> V_4 [ V_31 ] |= V_32 ;
if ( V_29 -> V_33 )
V_2 -> V_4 [ V_31 ] &= ~ V_34 ;
else
V_2 -> V_4 [ V_31 ] |= V_34 ;
if ( V_29 -> V_35 )
V_2 -> V_4 [ V_31 ] |= V_36 ;
else
V_2 -> V_4 [ V_31 ] &= ~ V_36 ;
V_8 = F_2 ( V_2 , V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
F_4 ( & V_2 -> V_15 ) ;
V_9 = F_5 ( & V_2 -> V_15 ,
F_6 ( V_37 ) ) ;
if ( V_9 == 0 )
V_10 = true ;
if ( ( V_2 -> V_4 [ V_17 ] & V_18 ) == 0 )
F_7 ( & V_2 -> V_19 . V_20 , L_3 ) ;
if ( V_2 -> V_4 [ V_17 ] & V_38 )
F_7 ( & V_2 -> V_19 . V_20 ,
L_4 ) ;
V_2 -> V_4 [ V_31 ] &= ~ V_32 ;
V_8 = F_2 ( V_2 , V_31 ) ;
if ( V_8 == 0 && V_10 )
return - V_39 ;
return V_8 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_4 [ V_31 ] =
V_40 | V_41 | V_42 ;
V_8 = F_2 ( V_2 , V_31 ) ;
if ( V_8 < 0 )
goto V_14;
V_2 -> V_4 [ V_43 ] =
( V_44 << 11 ) & V_45 ;
V_8 = F_2 ( V_2 , V_43 ) ;
if ( V_8 < 0 )
goto V_14;
V_2 -> V_4 [ V_5 ] =
( 0x1f << 8 ) |
( ( V_2 -> V_3 << 6 ) & V_6 ) |
( ( V_46 << 4 ) & V_21 ) |
15 ;
V_8 = F_2 ( V_2 , V_5 ) ;
if ( V_8 < 0 )
goto V_14;
V_8 = F_3 ( V_2 ,
V_2 -> V_4 [ V_11 ] & V_12 ) ;
V_14:
return V_8 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_4 [ V_43 ] &= ~ V_47 ;
V_8 = F_2 ( V_2 , V_43 ) ;
if ( V_8 < 0 )
goto V_14;
V_2 -> V_4 [ V_31 ] &= ~ V_40 ;
V_2 -> V_4 [ V_31 ] |= V_41 | V_48 ;
V_8 = F_2 ( V_2 , V_31 ) ;
V_14:
return V_8 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_4 [ V_43 ] |= V_47 ;
V_8 = F_2 ( V_2 , V_43 ) ;
if ( V_8 < 0 )
V_2 -> V_4 [ V_43 ] &= ~ V_47 ;
return V_8 ;
}
static T_1 F_18 ( struct V_49 * V_49 , char T_2 * V_50 ,
T_3 V_51 , T_4 * V_52 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
int V_8 = 0 ;
unsigned int V_53 = 0 ;
if ( ( V_2 -> V_4 [ V_43 ] & V_47 ) == 0 )
F_17 ( V_2 ) ;
while ( V_2 -> V_54 == V_2 -> V_55 ) {
if ( V_49 -> V_56 & V_57 ) {
V_8 = - V_58 ;
goto V_14;
}
if ( F_20 ( V_2 -> V_59 ,
V_2 -> V_54 != V_2 -> V_55 ) < 0 ) {
V_8 = - V_60 ;
goto V_14;
}
}
V_51 /= 3 ;
while ( V_53 < V_51 ) {
if ( V_2 -> V_55 == V_2 -> V_54 )
break;
if ( F_21 ( V_50 , & V_2 -> V_61 [ V_2 -> V_55 ] , 3 ) )
break;
V_2 -> V_55 += 3 ;
if ( V_2 -> V_55 >= V_2 -> V_62 )
V_2 -> V_55 = 0 ;
V_53 ++ ;
V_50 += 3 ;
V_8 += 3 ;
}
V_14:
return V_8 ;
}
static unsigned int F_22 ( struct V_49 * V_49 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
unsigned long V_65 = F_23 ( V_64 ) ;
int V_8 = F_24 ( V_49 , V_64 ) ;
if ( V_65 & ( V_66 | V_67 ) ) {
if ( ( V_2 -> V_4 [ V_43 ] & V_47 ) == 0 )
F_17 ( V_2 ) ;
F_25 ( V_49 , & V_2 -> V_59 , V_64 ) ;
if ( V_2 -> V_55 != V_2 -> V_54 )
V_8 |= V_66 | V_67 ;
}
return V_8 ;
}
static int F_26 ( struct V_68 * V_69 )
{
struct V_1 * V_2 =
F_27 ( V_69 -> V_70 , struct V_1 , V_71 ) ;
switch ( V_69 -> V_72 ) {
case V_73 :
V_2 -> V_4 [ V_5 ] &= ~ V_74 ;
V_2 -> V_4 [ V_5 ] |= V_69 -> V_75 ;
return F_2 ( V_2 , V_5 ) ;
case V_76 :
if ( V_69 -> V_75 )
V_2 -> V_4 [ V_31 ] &= ~ V_40 ;
else
V_2 -> V_4 [ V_31 ] |= V_40 ;
return F_2 ( V_2 , V_31 ) ;
default:
return - V_30 ;
}
}
static int F_28 ( struct V_49 * V_49 , void * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
int V_8 = 0 ;
if ( V_79 -> V_80 != 0 )
return - V_30 ;
if ( ! V_2 -> V_81 ) {
V_8 = F_10 ( V_2 , V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
}
strcpy ( V_79 -> V_82 , L_5 ) ;
V_79 -> type = V_83 ;
V_79 -> V_84 = V_85 | V_86 |
V_87 | V_88 |
V_89 |
V_90 ;
V_79 -> V_26 = 76 * V_91 ;
V_79 -> V_27 = 108 * V_91 ;
if ( ( V_2 -> V_4 [ V_17 ] & V_92 ) == 0 )
V_79 -> V_93 = V_94 ;
else
V_79 -> V_93 = V_95 ;
V_79 -> V_93 |= V_96 ;
if ( ( V_2 -> V_4 [ V_31 ] & V_97 ) == 0 )
V_79 -> V_98 = V_99 ;
else
V_79 -> V_98 = V_100 ;
V_79 -> signal = ( V_2 -> V_4 [ V_17 ] & V_101 ) ;
V_79 -> signal = ( V_79 -> signal * 873 ) + ( 8 * V_79 -> signal / 10 ) ;
if ( V_79 -> signal > 0xffff )
V_79 -> signal = 0xffff ;
V_79 -> V_102 = ( V_2 -> V_4 [ V_17 ] & V_103 ) ? 1 : 0 ;
return V_8 ;
}
static int F_29 ( struct V_49 * V_49 , void * V_77 ,
const struct V_78 * V_79 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
if ( V_79 -> V_80 != 0 )
return - V_30 ;
switch ( V_79 -> V_98 ) {
case V_100 :
V_2 -> V_4 [ V_31 ] |= V_97 ;
break;
case V_99 :
default:
V_2 -> V_4 [ V_31 ] &= ~ V_97 ;
break;
}
return F_2 ( V_2 , V_31 ) ;
}
static int F_30 ( struct V_49 * V_49 , void * V_77 ,
struct V_104 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
if ( V_22 -> V_79 != 0 )
return - V_30 ;
V_22 -> type = V_83 ;
return F_9 ( V_2 , & V_22 -> V_105 ) ;
}
static int F_31 ( struct V_49 * V_49 , void * V_77 ,
const struct V_104 * V_22 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
int V_8 ;
if ( V_22 -> V_79 != 0 )
return - V_30 ;
if ( V_22 -> V_105 < V_25 [ V_2 -> V_3 ] . V_26 ||
V_22 -> V_105 > V_25 [ V_2 -> V_3 ] . V_27 ) {
V_8 = F_1 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
}
return F_11 ( V_2 , V_22 -> V_105 ) ;
}
static int F_32 ( struct V_49 * V_49 , void * V_77 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_49 ) ;
if ( V_29 -> V_79 != 0 )
return - V_30 ;
if ( V_49 -> V_56 & V_57 )
return - V_58 ;
return F_13 ( V_2 , V_29 ) ;
}
static int F_33 ( struct V_49 * V_49 , void * V_77 ,
struct V_106 * V_3 )
{
if ( V_3 -> V_79 != 0 )
return - V_30 ;
if ( V_3 -> V_80 >= F_14 ( V_25 ) )
return - V_30 ;
* V_3 = V_25 [ V_3 -> V_80 ] ;
return 0 ;
}
