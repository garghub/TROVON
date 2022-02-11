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
bool V_9 = 0 ;
V_2 -> V_4 [ V_10 ] &= ~ V_11 ;
V_2 -> V_4 [ V_10 ] |= V_12 | V_7 ;
V_8 = F_2 ( V_2 , V_10 ) ;
if ( V_8 < 0 )
goto V_13;
F_4 ( V_2 -> V_14 ) ;
V_8 = F_5 ( & V_2 -> V_14 ,
F_6 ( V_15 ) ) ;
if ( ! V_8 )
V_9 = true ;
if ( ( V_2 -> V_4 [ V_16 ] & V_17 ) == 0 )
F_7 ( & V_2 -> V_18 . V_19 , L_1 ) ;
if ( V_9 )
F_7 ( & V_2 -> V_18 . V_19 ,
L_2 , V_15 ) ;
V_2 -> V_4 [ V_10 ] &= ~ V_12 ;
V_8 = F_2 ( V_2 , V_10 ) ;
V_13:
return V_8 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
switch ( ( V_2 -> V_4 [ V_5 ] & V_20 ) >> 4 ) {
case 0 :
return 200 * 16 ;
case 1 :
return 100 * 16 ;
default:
return 50 * 16 ;
} ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int * V_21 )
{
int V_7 , V_8 ;
V_8 = F_10 ( V_2 , V_22 ) ;
V_7 = V_2 -> V_4 [ V_22 ] & V_23 ;
* V_21 = V_7 * F_8 ( V_2 ) + V_24 [ V_2 -> V_3 ] . V_25 ;
return V_8 ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_21 )
{
unsigned short V_7 ;
V_21 = F_12 ( V_21 , V_24 [ V_2 -> V_3 ] . V_25 ,
V_24 [ V_2 -> V_3 ] . V_26 ) ;
V_7 = ( V_21 - V_24 [ V_2 -> V_3 ] . V_25 ) / F_8 ( V_2 ) ;
return F_3 ( V_2 , V_7 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
int V_3 , V_8 ;
unsigned int V_21 ;
bool V_9 = 0 ;
if ( V_28 -> V_25 || V_28 -> V_26 ) {
for ( V_3 = 0 ; V_3 < F_14 ( V_24 ) ; V_3 ++ ) {
if ( V_24 [ V_3 ] . V_25 == V_28 -> V_25 &&
V_24 [ V_3 ] . V_26 == V_28 -> V_26 )
break;
}
if ( V_3 == F_14 ( V_24 ) )
return - V_29 ;
} else
V_3 = 1 ;
if ( V_2 -> V_3 != V_3 ) {
V_8 = F_9 ( V_2 , & V_21 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_11 ( V_2 , V_21 ) ;
if ( V_8 )
return V_8 ;
}
V_2 -> V_4 [ V_30 ] |= V_31 ;
if ( V_28 -> V_32 )
V_2 -> V_4 [ V_30 ] &= ~ V_33 ;
else
V_2 -> V_4 [ V_30 ] |= V_33 ;
if ( V_28 -> V_34 )
V_2 -> V_4 [ V_30 ] |= V_35 ;
else
V_2 -> V_4 [ V_30 ] &= ~ V_35 ;
V_8 = F_2 ( V_2 , V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
F_4 ( V_2 -> V_14 ) ;
V_8 = F_5 ( & V_2 -> V_14 ,
F_6 ( V_36 ) ) ;
if ( ! V_8 )
V_9 = true ;
if ( ( V_2 -> V_4 [ V_16 ] & V_17 ) == 0 )
F_7 ( & V_2 -> V_18 . V_19 , L_3 ) ;
if ( V_2 -> V_4 [ V_16 ] & V_37 )
F_7 ( & V_2 -> V_18 . V_19 ,
L_4 ) ;
V_2 -> V_4 [ V_30 ] &= ~ V_31 ;
V_8 = F_2 ( V_2 , V_30 ) ;
if ( V_8 == 0 && V_9 )
return - V_38 ;
return V_8 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_4 [ V_30 ] =
V_39 | V_40 | V_41 ;
V_8 = F_2 ( V_2 , V_30 ) ;
if ( V_8 < 0 )
goto V_13;
V_2 -> V_4 [ V_42 ] =
( V_43 << 11 ) & V_44 ;
V_8 = F_2 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
goto V_13;
V_2 -> V_4 [ V_5 ] =
( 0x1f << 8 ) |
( ( V_2 -> V_3 << 6 ) & V_6 ) |
( ( V_45 << 4 ) & V_20 ) |
15 ;
V_8 = F_2 ( V_2 , V_5 ) ;
if ( V_8 < 0 )
goto V_13;
V_8 = F_3 ( V_2 ,
V_2 -> V_4 [ V_10 ] & V_11 ) ;
V_13:
return V_8 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_4 [ V_42 ] &= ~ V_46 ;
V_8 = F_2 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
goto V_13;
V_2 -> V_4 [ V_30 ] &= ~ V_39 ;
V_2 -> V_4 [ V_30 ] |= V_40 | V_47 ;
V_8 = F_2 ( V_2 , V_30 ) ;
V_13:
return V_8 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_8 ;
V_2 -> V_4 [ V_42 ] |= V_46 ;
V_8 = F_2 ( V_2 , V_42 ) ;
if ( V_8 < 0 )
V_2 -> V_4 [ V_42 ] &= ~ V_46 ;
return V_8 ;
}
static T_1 F_18 ( struct V_48 * V_48 , char T_2 * V_49 ,
T_3 V_50 , T_4 * V_51 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
int V_8 = 0 ;
unsigned int V_52 = 0 ;
if ( ( V_2 -> V_4 [ V_42 ] & V_46 ) == 0 )
F_17 ( V_2 ) ;
while ( V_2 -> V_53 == V_2 -> V_54 ) {
if ( V_48 -> V_55 & V_56 ) {
V_8 = - V_57 ;
goto V_13;
}
if ( F_20 ( V_2 -> V_58 ,
V_2 -> V_53 != V_2 -> V_54 ) < 0 ) {
V_8 = - V_59 ;
goto V_13;
}
}
V_50 /= 3 ;
while ( V_52 < V_50 ) {
if ( V_2 -> V_54 == V_2 -> V_53 )
break;
if ( F_21 ( V_49 , & V_2 -> V_60 [ V_2 -> V_54 ] , 3 ) )
break;
V_2 -> V_54 += 3 ;
if ( V_2 -> V_54 >= V_2 -> V_61 )
V_2 -> V_54 = 0 ;
V_52 ++ ;
V_49 += 3 ;
V_8 += 3 ;
}
V_13:
return V_8 ;
}
static unsigned int F_22 ( struct V_48 * V_48 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
unsigned long V_64 = F_23 ( V_63 ) ;
int V_8 = F_24 ( V_48 , V_63 ) ;
if ( V_64 & ( V_65 | V_66 ) ) {
if ( ( V_2 -> V_4 [ V_42 ] & V_46 ) == 0 )
F_17 ( V_2 ) ;
F_25 ( V_48 , & V_2 -> V_58 , V_63 ) ;
if ( V_2 -> V_54 != V_2 -> V_53 )
V_8 |= V_65 | V_66 ;
}
return V_8 ;
}
static int F_26 ( struct V_67 * V_68 )
{
struct V_1 * V_2 =
F_27 ( V_68 -> V_69 , struct V_1 , V_70 ) ;
switch ( V_68 -> V_71 ) {
case V_72 :
V_2 -> V_4 [ V_5 ] &= ~ V_73 ;
V_2 -> V_4 [ V_5 ] |= V_68 -> V_74 ;
return F_2 ( V_2 , V_5 ) ;
case V_75 :
if ( V_68 -> V_74 )
V_2 -> V_4 [ V_30 ] &= ~ V_39 ;
else
V_2 -> V_4 [ V_30 ] |= V_39 ;
return F_2 ( V_2 , V_30 ) ;
default:
return - V_29 ;
}
}
static int F_28 ( struct V_48 * V_48 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
int V_8 = 0 ;
if ( V_78 -> V_79 != 0 )
return - V_29 ;
if ( ! V_2 -> V_80 ) {
V_8 = F_10 ( V_2 , V_16 ) ;
if ( V_8 < 0 )
return V_8 ;
}
strcpy ( V_78 -> V_81 , L_5 ) ;
V_78 -> type = V_82 ;
V_78 -> V_83 = V_84 | V_85 |
V_86 | V_87 |
V_88 |
V_89 ;
V_78 -> V_25 = 76 * V_90 ;
V_78 -> V_26 = 108 * V_90 ;
if ( ( V_2 -> V_4 [ V_16 ] & V_91 ) == 0 )
V_78 -> V_92 = V_93 ;
else
V_78 -> V_92 = V_94 ;
V_78 -> V_92 |= V_95 ;
if ( ( V_2 -> V_4 [ V_30 ] & V_96 ) == 0 )
V_78 -> V_97 = V_98 ;
else
V_78 -> V_97 = V_99 ;
V_78 -> signal = ( V_2 -> V_4 [ V_16 ] & V_100 ) ;
V_78 -> signal = ( V_78 -> signal * 873 ) + ( 8 * V_78 -> signal / 10 ) ;
if ( V_78 -> signal > 0xffff )
V_78 -> signal = 0xffff ;
V_78 -> V_101 = ( V_2 -> V_4 [ V_16 ] & V_102 ) ? 1 : 0 ;
return V_8 ;
}
static int F_29 ( struct V_48 * V_48 , void * V_76 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
if ( V_78 -> V_79 != 0 )
return - V_29 ;
switch ( V_78 -> V_97 ) {
case V_99 :
V_2 -> V_4 [ V_30 ] |= V_96 ;
break;
case V_98 :
default:
V_2 -> V_4 [ V_30 ] &= ~ V_96 ;
break;
}
return F_2 ( V_2 , V_30 ) ;
}
static int F_30 ( struct V_48 * V_48 , void * V_76 ,
struct V_103 * V_21 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
if ( V_21 -> V_78 != 0 )
return - V_29 ;
V_21 -> type = V_82 ;
return F_9 ( V_2 , & V_21 -> V_104 ) ;
}
static int F_31 ( struct V_48 * V_48 , void * V_76 ,
const struct V_103 * V_21 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
int V_8 ;
if ( V_21 -> V_78 != 0 )
return - V_29 ;
if ( V_21 -> V_104 < V_24 [ V_2 -> V_3 ] . V_25 ||
V_21 -> V_104 > V_24 [ V_2 -> V_3 ] . V_26 ) {
V_8 = F_1 ( V_2 , 1 ) ;
if ( V_8 )
return V_8 ;
}
return F_11 ( V_2 , V_21 -> V_104 ) ;
}
static int F_32 ( struct V_48 * V_48 , void * V_76 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 = F_19 ( V_48 ) ;
if ( V_28 -> V_78 != 0 )
return - V_29 ;
if ( V_48 -> V_55 & V_56 )
return - V_57 ;
return F_13 ( V_2 , V_28 ) ;
}
static int F_33 ( struct V_48 * V_48 , void * V_76 ,
struct V_105 * V_3 )
{
if ( V_3 -> V_78 != 0 )
return - V_29 ;
if ( V_3 -> V_79 >= F_14 ( V_24 ) )
return - V_29 ;
* V_3 = V_24 [ V_3 -> V_79 ] ;
return 0 ;
}
