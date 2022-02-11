static int F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
int V_4 ;
unsigned long V_5 ;
bool V_6 = 0 ;
V_2 -> V_7 [ V_8 ] &= ~ V_9 ;
V_2 -> V_7 [ V_8 ] |= V_10 | V_3 ;
V_4 = F_2 ( V_2 , V_8 ) ;
if ( V_4 < 0 )
goto V_11;
if ( V_2 -> V_12 ) {
F_3 ( V_2 -> V_13 ) ;
V_4 = F_4 ( & V_2 -> V_13 ,
F_5 ( V_14 ) ) ;
if ( ! V_4 )
V_6 = true ;
} else {
V_5 = V_15 + F_5 ( V_14 ) ;
do {
V_4 = F_6 ( V_2 , V_16 ) ;
if ( V_4 < 0 )
goto V_17;
V_6 = F_7 ( V_15 , V_5 ) ;
} while ( ( ( V_2 -> V_7 [ V_16 ] & V_18 ) == 0 )
&& ( ! V_6 ) );
}
if ( ( V_2 -> V_7 [ V_16 ] & V_18 ) == 0 )
F_8 ( & V_2 -> V_19 . V_20 , L_1 ) ;
if ( V_6 )
F_8 ( & V_2 -> V_19 . V_20 ,
L_2 , V_14 ) ;
V_17:
V_2 -> V_7 [ V_8 ] &= ~ V_10 ;
V_4 = F_2 ( V_2 , V_8 ) ;
V_11:
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int * V_21 )
{
unsigned int V_22 , V_23 ;
unsigned short V_3 ;
int V_4 ;
switch ( ( V_2 -> V_7 [ V_24 ] & V_25 ) >> 4 ) {
case 0 :
V_22 = 0.200 * V_26 ; break;
case 1 :
V_22 = 0.100 * V_26 ; break;
default:
V_22 = 0.050 * V_26 ; break;
} ;
switch ( ( V_2 -> V_7 [ V_24 ] & V_27 ) >> 6 ) {
case 0 :
V_23 = 87.5 * V_26 ; break;
default:
V_23 = 76 * V_26 ; break;
case 2 :
V_23 = 76 * V_26 ; break;
} ;
V_4 = F_6 ( V_2 , V_28 ) ;
V_3 = V_2 -> V_7 [ V_28 ] & V_29 ;
* V_21 = V_3 * V_22 + V_23 ;
return V_4 ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_21 )
{
unsigned int V_22 , V_23 , V_30 ;
unsigned short V_3 ;
switch ( ( V_2 -> V_7 [ V_24 ] & V_25 ) >> 4 ) {
case 0 :
V_22 = 0.200 * V_26 ; break;
case 1 :
V_22 = 0.100 * V_26 ; break;
default:
V_22 = 0.050 * V_26 ; break;
} ;
switch ( ( V_2 -> V_7 [ V_24 ] & V_27 ) >> 6 ) {
case 0 :
V_23 = 87.5 * V_26 ;
V_30 = 108 * V_26 ;
break;
default:
V_23 = 76 * V_26 ;
V_30 = 108 * V_26 ;
break;
case 2 :
V_23 = 76 * V_26 ;
V_30 = 90 * V_26 ;
break;
} ;
V_21 = F_11 ( V_21 , V_23 , V_30 ) ;
V_3 = ( V_21 - V_23 ) / V_22 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_31 , unsigned int V_32 )
{
int V_4 = 0 ;
unsigned long V_5 ;
bool V_6 = 0 ;
V_2 -> V_7 [ V_33 ] |= V_34 ;
if ( V_31 == 1 )
V_2 -> V_7 [ V_33 ] &= ~ V_35 ;
else
V_2 -> V_7 [ V_33 ] |= V_35 ;
if ( V_32 == 1 )
V_2 -> V_7 [ V_33 ] |= V_36 ;
else
V_2 -> V_7 [ V_33 ] &= ~ V_36 ;
V_4 = F_2 ( V_2 , V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_2 -> V_12 ) {
F_3 ( V_2 -> V_13 ) ;
V_4 = F_4 ( & V_2 -> V_13 ,
F_5 ( V_37 ) ) ;
if ( ! V_4 )
V_6 = true ;
} else {
V_5 = V_15 + F_5 ( V_37 ) ;
do {
V_4 = F_6 ( V_2 , V_16 ) ;
if ( V_4 < 0 )
goto V_17;
V_6 = F_7 ( V_15 , V_5 ) ;
} while ( ( ( V_2 -> V_7 [ V_16 ] & V_18 ) == 0 )
&& ( ! V_6 ) );
}
if ( ( V_2 -> V_7 [ V_16 ] & V_18 ) == 0 )
F_8 ( & V_2 -> V_19 . V_20 , L_3 ) ;
if ( V_2 -> V_7 [ V_16 ] & V_38 )
F_8 ( & V_2 -> V_19 . V_20 ,
L_4 ) ;
V_17:
V_2 -> V_7 [ V_33 ] &= ~ V_34 ;
V_4 = F_2 ( V_2 , V_33 ) ;
if ( V_4 == 0 && V_6 )
return - V_39 ;
return V_4 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_4 ;
V_2 -> V_7 [ V_33 ] =
V_40 | V_41 | V_42 ;
V_4 = F_2 ( V_2 , V_33 ) ;
if ( V_4 < 0 )
goto V_11;
V_2 -> V_7 [ V_43 ] =
( V_44 << 11 ) & V_45 ;
V_4 = F_2 ( V_2 , V_43 ) ;
if ( V_4 < 0 )
goto V_11;
V_2 -> V_7 [ V_24 ] =
( 0x3f << 8 ) |
( ( V_46 << 6 ) & V_27 ) |
( ( V_47 << 4 ) & V_25 ) |
15 ;
V_4 = F_2 ( V_2 , V_24 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_1 ( V_2 ,
V_2 -> V_7 [ V_8 ] & V_9 ) ;
V_11:
return V_4 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_4 ;
V_2 -> V_7 [ V_43 ] &= ~ V_48 ;
V_4 = F_2 ( V_2 , V_43 ) ;
if ( V_4 < 0 )
goto V_11;
V_2 -> V_7 [ V_33 ] &= ~ V_40 ;
V_2 -> V_7 [ V_33 ] |= V_41 | V_49 ;
V_4 = F_2 ( V_2 , V_33 ) ;
V_11:
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_4 ;
V_2 -> V_7 [ V_43 ] |= V_48 ;
V_4 = F_2 ( V_2 , V_43 ) ;
if ( V_4 < 0 )
V_2 -> V_7 [ V_43 ] &= ~ V_48 ;
return V_4 ;
}
static T_1 F_16 ( struct V_50 * V_50 , char T_2 * V_51 ,
T_3 V_52 , T_4 * V_53 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
int V_4 = 0 ;
unsigned int V_54 = 0 ;
if ( ( V_2 -> V_7 [ V_43 ] & V_48 ) == 0 )
F_15 ( V_2 ) ;
while ( V_2 -> V_55 == V_2 -> V_56 ) {
if ( V_50 -> V_57 & V_58 ) {
V_4 = - V_59 ;
goto V_11;
}
if ( F_18 ( V_2 -> V_60 ,
V_2 -> V_55 != V_2 -> V_56 ) < 0 ) {
V_4 = - V_61 ;
goto V_11;
}
}
V_52 /= 3 ;
while ( V_54 < V_52 ) {
if ( V_2 -> V_56 == V_2 -> V_55 )
break;
if ( F_19 ( V_51 , & V_2 -> V_62 [ V_2 -> V_56 ] , 3 ) )
break;
V_2 -> V_56 += 3 ;
if ( V_2 -> V_56 >= V_2 -> V_63 )
V_2 -> V_56 = 0 ;
V_54 ++ ;
V_51 += 3 ;
V_4 += 3 ;
}
V_11:
return V_4 ;
}
static unsigned int F_20 ( struct V_50 * V_50 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
unsigned long V_66 = F_21 ( V_65 ) ;
int V_4 = F_22 ( V_50 , V_65 ) ;
if ( V_66 & ( V_67 | V_68 ) ) {
if ( ( V_2 -> V_7 [ V_43 ] & V_48 ) == 0 )
F_15 ( V_2 ) ;
F_23 ( V_50 , & V_2 -> V_60 , V_65 ) ;
if ( V_2 -> V_56 != V_2 -> V_55 )
V_4 |= V_67 | V_68 ;
}
return V_4 ;
}
static int F_24 ( struct V_69 * V_70 )
{
struct V_1 * V_2 =
F_25 ( V_70 -> V_71 , struct V_1 , V_72 ) ;
switch ( V_70 -> V_73 ) {
case V_74 :
V_2 -> V_7 [ V_24 ] &= ~ V_75 ;
V_2 -> V_7 [ V_24 ] |= V_70 -> V_76 ;
return F_2 ( V_2 , V_24 ) ;
case V_77 :
if ( V_70 -> V_76 )
V_2 -> V_7 [ V_33 ] &= ~ V_40 ;
else
V_2 -> V_7 [ V_33 ] |= V_40 ;
return F_2 ( V_2 , V_33 ) ;
default:
return - V_78 ;
}
}
static int F_26 ( struct V_50 * V_50 , void * V_79 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
int V_4 ;
if ( V_81 -> V_82 != 0 )
return - V_78 ;
V_4 = F_6 ( V_2 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
strcpy ( V_81 -> V_83 , L_5 ) ;
V_81 -> type = V_84 ;
V_81 -> V_85 = V_86 | V_87 |
V_88 | V_89 ;
switch ( ( V_2 -> V_7 [ V_24 ] & V_27 ) >> 6 ) {
default:
V_81 -> V_90 = 87.5 * V_26 ;
V_81 -> V_91 = 108 * V_26 ;
break;
case 1 :
V_81 -> V_90 = 76 * V_26 ;
V_81 -> V_91 = 108 * V_26 ;
break;
case 2 :
V_81 -> V_90 = 76 * V_26 ;
V_81 -> V_91 = 90 * V_26 ;
break;
} ;
if ( ( V_2 -> V_7 [ V_16 ] & V_92 ) == 0 )
V_81 -> V_93 = V_94 ;
else
V_81 -> V_93 = V_95 ;
V_81 -> V_93 |= V_96 ;
if ( ( V_2 -> V_7 [ V_33 ] & V_97 ) == 0 )
V_81 -> V_98 = V_99 ;
else
V_81 -> V_98 = V_100 ;
V_81 -> signal = ( V_2 -> V_7 [ V_16 ] & V_101 ) ;
V_81 -> signal = ( V_81 -> signal * 873 ) + ( 8 * V_81 -> signal / 10 ) ;
if ( V_81 -> signal > 0xffff )
V_81 -> signal = 0xffff ;
V_81 -> V_102 = ( V_2 -> V_7 [ V_16 ] & V_103 ) ? 1 : 0 ;
return V_4 ;
}
static int F_27 ( struct V_50 * V_50 , void * V_79 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
if ( V_81 -> V_82 != 0 )
return - V_78 ;
switch ( V_81 -> V_98 ) {
case V_100 :
V_2 -> V_7 [ V_33 ] |= V_97 ;
break;
case V_99 :
default:
V_2 -> V_7 [ V_33 ] &= ~ V_97 ;
break;
}
return F_2 ( V_2 , V_33 ) ;
}
static int F_28 ( struct V_50 * V_50 , void * V_79 ,
struct V_104 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
if ( V_21 -> V_81 != 0 )
return - V_78 ;
V_21 -> type = V_84 ;
return F_9 ( V_2 , & V_21 -> V_105 ) ;
}
static int F_29 ( struct V_50 * V_50 , void * V_79 ,
struct V_104 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
if ( V_21 -> V_81 != 0 )
return - V_78 ;
return F_10 ( V_2 , V_21 -> V_105 ) ;
}
static int F_30 ( struct V_50 * V_50 , void * V_79 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_17 ( V_50 ) ;
if ( V_107 -> V_81 != 0 )
return - V_78 ;
return F_12 ( V_2 , V_107 -> V_31 , V_107 -> V_32 ) ;
}
