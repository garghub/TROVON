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
F_8 ( & V_2 -> V_19 -> V_20 , L_1 ) ;
if ( V_6 )
F_8 ( & V_2 -> V_19 -> V_20 ,
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
unsigned int V_22 , V_23 ;
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
V_23 = 87.5 * V_26 ; break;
default:
V_23 = 76 * V_26 ; break;
case 2 :
V_23 = 76 * V_26 ; break;
} ;
V_3 = ( V_21 - V_23 ) / V_22 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_30 , unsigned int V_31 )
{
int V_4 = 0 ;
unsigned long V_5 ;
bool V_6 = 0 ;
V_2 -> V_7 [ V_32 ] |= V_33 ;
if ( V_30 == 1 )
V_2 -> V_7 [ V_32 ] &= ~ V_34 ;
else
V_2 -> V_7 [ V_32 ] |= V_34 ;
if ( V_31 == 1 )
V_2 -> V_7 [ V_32 ] |= V_35 ;
else
V_2 -> V_7 [ V_32 ] &= ~ V_35 ;
V_4 = F_2 ( V_2 , V_32 ) ;
if ( V_4 < 0 )
goto V_11;
if ( V_2 -> V_12 ) {
F_3 ( V_2 -> V_13 ) ;
V_4 = F_4 ( & V_2 -> V_13 ,
F_5 ( V_36 ) ) ;
if ( ! V_4 )
V_6 = true ;
} else {
V_5 = V_15 + F_5 ( V_36 ) ;
do {
V_4 = F_6 ( V_2 , V_16 ) ;
if ( V_4 < 0 )
goto V_17;
V_6 = F_7 ( V_15 , V_5 ) ;
} while ( ( ( V_2 -> V_7 [ V_16 ] & V_18 ) == 0 )
&& ( ! V_6 ) );
}
if ( ( V_2 -> V_7 [ V_16 ] & V_18 ) == 0 )
F_8 ( & V_2 -> V_19 -> V_20 , L_3 ) ;
if ( V_2 -> V_7 [ V_16 ] & V_37 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_4 ) ;
if ( V_6 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_5 , V_36 ) ;
V_17:
V_2 -> V_7 [ V_32 ] &= ~ V_33 ;
V_4 = F_2 ( V_2 , V_32 ) ;
V_11:
if ( ( V_4 == 0 ) && V_6 )
V_4 = - V_38 ;
return V_4 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_4 ;
V_2 -> V_7 [ V_32 ] =
V_39 | V_40 | V_41 ;
V_4 = F_2 ( V_2 , V_32 ) ;
if ( V_4 < 0 )
goto V_11;
V_2 -> V_7 [ V_42 ] =
( V_43 << 11 ) & V_44 ;
V_4 = F_2 ( V_2 , V_42 ) ;
if ( V_4 < 0 )
goto V_11;
V_2 -> V_7 [ V_24 ] =
( 0x3f << 8 ) |
( ( V_45 << 6 ) & V_27 ) |
( ( V_46 << 4 ) & V_25 ) |
15 ;
V_4 = F_2 ( V_2 , V_24 ) ;
if ( V_4 < 0 )
goto V_11;
V_4 = F_1 ( V_2 ,
V_2 -> V_7 [ V_8 ] & V_9 ) ;
V_11:
return V_4 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_4 ;
V_2 -> V_7 [ V_42 ] &= ~ V_47 ;
V_4 = F_2 ( V_2 , V_42 ) ;
if ( V_4 < 0 )
goto V_11;
V_2 -> V_7 [ V_32 ] &= ~ V_39 ;
V_2 -> V_7 [ V_32 ] |= V_40 | V_48 ;
V_4 = F_2 ( V_2 , V_32 ) ;
V_11:
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_4 ;
V_2 -> V_7 [ V_42 ] |= V_47 ;
V_4 = F_2 ( V_2 , V_42 ) ;
if ( V_4 < 0 )
V_2 -> V_7 [ V_42 ] &= ~ V_47 ;
return V_4 ;
}
static T_1 F_15 ( struct V_49 * V_49 , char T_2 * V_50 ,
T_3 V_51 , T_4 * V_52 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
unsigned int V_53 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
if ( ( V_2 -> V_7 [ V_42 ] & V_47 ) == 0 )
F_14 ( V_2 ) ;
while ( V_2 -> V_55 == V_2 -> V_56 ) {
if ( V_49 -> V_57 & V_58 ) {
V_4 = - V_59 ;
goto V_11;
}
if ( F_18 ( V_2 -> V_60 ,
V_2 -> V_55 != V_2 -> V_56 ) < 0 ) {
V_4 = - V_61 ;
goto V_11;
}
}
V_51 /= 3 ;
while ( V_53 < V_51 ) {
if ( V_2 -> V_56 == V_2 -> V_55 )
break;
if ( F_19 ( V_50 , & V_2 -> V_62 [ V_2 -> V_56 ] , 3 ) )
break;
V_2 -> V_56 += 3 ;
if ( V_2 -> V_56 >= V_2 -> V_63 )
V_2 -> V_56 = 0 ;
V_53 ++ ;
V_50 += 3 ;
V_4 += 3 ;
}
V_11:
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static unsigned int F_21 ( struct V_49 * V_49 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
if ( ( V_2 -> V_7 [ V_42 ] & V_47 ) == 0 )
F_14 ( V_2 ) ;
F_20 ( & V_2 -> V_54 ) ;
F_22 ( V_49 , & V_2 -> V_60 , V_65 ) ;
if ( V_2 -> V_56 != V_2 -> V_55 )
V_4 = V_66 | V_67 ;
return V_4 ;
}
static int F_23 ( struct V_49 * V_49 , void * V_68 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = - V_71 ;
if ( V_70 -> V_72 < V_73 )
goto V_11;
switch ( V_70 -> V_72 ) {
case V_74 :
return F_24 ( V_70 , 0 , 15 , 1 , 15 ) ;
case V_75 :
return F_24 ( V_70 , 0 , 1 , 1 , 1 ) ;
}
if ( ( V_4 == - V_71 ) && ( V_70 -> V_72 < V_76 ) ) {
V_70 -> V_77 = V_78 ;
V_4 = 0 ;
}
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_6 , V_4 ) ;
return V_4 ;
}
static int F_25 ( struct V_49 * V_49 , void * V_68 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
switch ( V_80 -> V_72 ) {
case V_74 :
V_80 -> V_81 = V_2 -> V_7 [ V_24 ] &
V_82 ;
break;
case V_75 :
V_80 -> V_81 = ( ( V_2 -> V_7 [ V_32 ] &
V_39 ) == 0 ) ? 1 : 0 ;
break;
default:
V_4 = - V_71 ;
}
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_7 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static int F_27 ( struct V_49 * V_49 , void * V_68 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
switch ( V_80 -> V_72 ) {
case V_74 :
V_2 -> V_7 [ V_24 ] &= ~ V_82 ;
V_2 -> V_7 [ V_24 ] |= V_80 -> V_81 ;
V_4 = F_2 ( V_2 , V_24 ) ;
break;
case V_75 :
if ( V_80 -> V_81 == 1 )
V_2 -> V_7 [ V_32 ] &= ~ V_39 ;
else
V_2 -> V_7 [ V_32 ] |= V_39 ;
V_4 = F_2 ( V_2 , V_32 ) ;
break;
default:
V_4 = - V_71 ;
}
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_8 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static int F_28 ( struct V_49 * V_49 , void * V_68 ,
struct V_83 * V_84 )
{
V_84 -> V_85 = 0 ;
strcpy ( V_84 -> V_86 , L_9 ) ;
V_84 -> V_87 = V_88 ;
V_84 -> V_89 = 0 ;
return 0 ;
}
static int F_29 ( struct V_49 * V_49 , void * V_68 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
if ( V_91 -> V_85 != 0 ) {
V_4 = - V_71 ;
goto V_11;
}
V_4 = F_6 ( V_2 , V_16 ) ;
if ( V_4 < 0 )
goto V_11;
strcpy ( V_91 -> V_86 , L_10 ) ;
V_91 -> type = V_92 ;
V_91 -> V_87 = V_93 | V_94 |
V_95 | V_96 ;
switch ( ( V_2 -> V_7 [ V_24 ] & V_27 ) >> 6 ) {
default:
V_91 -> V_97 = 87.5 * V_26 ;
V_91 -> V_98 = 108 * V_26 ;
break;
case 1 :
V_91 -> V_97 = 76 * V_26 ;
V_91 -> V_98 = 108 * V_26 ;
break;
case 2 :
V_91 -> V_97 = 76 * V_26 ;
V_91 -> V_98 = 90 * V_26 ;
break;
} ;
if ( ( V_2 -> V_7 [ V_16 ] & V_99 ) == 0 )
V_91 -> V_100 = V_101 ;
else
V_91 -> V_100 = V_101 | V_102 ;
V_91 -> V_100 |= V_103 ;
if ( ( V_2 -> V_7 [ V_32 ] & V_104 ) == 0 )
V_91 -> V_105 = V_106 ;
else
V_91 -> V_105 = V_107 ;
V_91 -> signal = ( V_2 -> V_7 [ V_16 ] & V_108 ) ;
V_91 -> signal = ( V_91 -> signal * 873 ) + ( 8 * V_91 -> signal / 10 ) ;
V_91 -> V_109 = ( V_2 -> V_7 [ V_16 ] & V_110 ) ? 1 : 0 ;
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_11 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static int F_30 ( struct V_49 * V_49 , void * V_68 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
if ( V_91 -> V_85 != 0 )
goto V_11;
switch ( V_91 -> V_105 ) {
case V_107 :
V_2 -> V_7 [ V_32 ] |= V_104 ;
break;
case V_106 :
V_2 -> V_7 [ V_32 ] &= ~ V_104 ;
break;
default:
goto V_11;
}
V_4 = F_2 ( V_2 , V_32 ) ;
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_12 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static int F_31 ( struct V_49 * V_49 , void * V_68 ,
struct V_111 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
if ( V_21 -> V_91 != 0 ) {
V_4 = - V_71 ;
goto V_11;
}
V_21 -> type = V_92 ;
V_4 = F_9 ( V_2 , & V_21 -> V_112 ) ;
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_13 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static int F_32 ( struct V_49 * V_49 , void * V_68 ,
struct V_111 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
if ( V_21 -> V_91 != 0 ) {
V_4 = - V_71 ;
goto V_11;
}
V_4 = F_10 ( V_2 , V_21 -> V_112 ) ;
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_14 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
static int F_33 ( struct V_49 * V_49 , void * V_68 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_4 = 0 ;
F_17 ( & V_2 -> V_54 ) ;
V_4 = F_26 ( V_2 ) ;
if ( V_4 )
goto V_11;
if ( V_114 -> V_91 != 0 ) {
V_4 = - V_71 ;
goto V_11;
}
V_4 = F_11 ( V_2 , V_114 -> V_30 , V_114 -> V_31 ) ;
V_11:
if ( V_4 < 0 )
F_8 ( & V_2 -> V_19 -> V_20 ,
L_15 , V_4 ) ;
F_20 ( & V_2 -> V_54 ) ;
return V_4 ;
}
