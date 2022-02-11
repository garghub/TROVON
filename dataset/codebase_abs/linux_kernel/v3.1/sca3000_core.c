int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
V_2 -> V_5 [ 0 ] = F_2 ( V_3 ) ;
V_2 -> V_5 [ 1 ] = V_4 ;
return F_3 ( V_2 -> V_6 , V_2 -> V_5 , 2 ) ;
}
int F_4 ( struct V_1 * V_2 ,
T_2 V_7 ,
int V_8 )
{
struct V_9 V_10 ;
struct V_11 V_12 [ 2 ] = {
{
. V_8 = 1 ,
. V_13 = V_2 -> V_5 ,
} , {
. V_8 = V_8 ,
. V_14 = V_2 -> V_15 ,
}
} ;
V_2 -> V_5 [ 0 ] = F_5 ( V_7 ) ;
F_6 ( & V_10 ) ;
F_7 ( & V_12 [ 0 ] , & V_10 ) ;
F_7 ( & V_12 [ 1 ] , & V_10 ) ;
return F_8 ( V_2 -> V_6 , & V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_4 ( V_2 , V_17 , 1 ) ;
if ( V_16 < 0 )
return V_16 ;
return ! ( V_2 -> V_15 [ 0 ] & V_18 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 V_10 ;
struct V_11 V_12 [ 3 ] = {
{
. V_8 = 2 ,
. V_19 = 1 ,
. V_13 = V_2 -> V_5 ,
} , {
. V_8 = 2 ,
. V_19 = 1 ,
. V_13 = V_2 -> V_5 + 2 ,
} , {
. V_8 = 2 ,
. V_13 = V_2 -> V_5 + 4 ,
} ,
} ;
V_2 -> V_5 [ 0 ] = F_2 ( V_20 ) ;
V_2 -> V_5 [ 1 ] = 0x00 ;
V_2 -> V_5 [ 2 ] = F_2 ( V_20 ) ;
V_2 -> V_5 [ 3 ] = 0x50 ;
V_2 -> V_5 [ 4 ] = F_2 ( V_20 ) ;
V_2 -> V_5 [ 5 ] = 0xA0 ;
F_6 ( & V_10 ) ;
F_7 ( & V_12 [ 0 ] , & V_10 ) ;
F_7 ( & V_12 [ 1 ] , & V_10 ) ;
F_7 ( & V_12 [ 2 ] , & V_10 ) ;
return F_8 ( V_2 -> V_6 , & V_10 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_21 ,
T_2 V_4 )
{
int V_16 ;
V_16 = F_9 ( V_2 ) ;
if ( V_16 < 0 )
goto V_22;
if ( V_16 ) {
V_16 = F_10 ( V_2 ) ;
if ( V_16 )
goto V_22;
}
V_16 = F_1 ( V_2 , V_23 , V_21 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_24 , V_4 ) ;
V_22:
return V_16 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_25 )
{
int V_16 ;
V_16 = F_9 ( V_2 ) ;
if ( V_16 < 0 )
goto V_22;
if ( V_16 ) {
V_16 = F_10 ( V_2 ) ;
if ( V_16 )
goto V_22;
}
V_16 = F_1 ( V_2 , V_23 , V_25 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_24 , 1 ) ;
if ( V_16 )
goto V_22;
else
return V_2 -> V_15 [ 0 ] ;
V_22:
return V_16 ;
}
static int F_13 ( struct V_26 * V_27 )
{
int V_16 ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_17 , 1 ) ;
if ( V_16 < 0 )
goto V_22;
if ( V_2 -> V_15 [ 0 ] & V_31 )
F_17 ( V_27 , L_1 ) ;
if ( V_2 -> V_15 [ 0 ] & V_32 )
F_17 ( V_27 , L_2 ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static T_3 F_19 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
int V_8 = 0 , V_16 ;
struct V_28 * V_36 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_37 , 1 ) ;
if ( V_16 < 0 )
goto V_22;
V_8 += sprintf ( V_35 + V_8 ,
L_3 ,
V_2 -> V_15 [ 0 ] & V_38 ,
V_2 -> V_15 [ 0 ] & V_39 ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3
F_20 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_28 * V_36 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
int V_8 = 0 ;
V_8 += sprintf ( V_35 + V_8 , L_4 ) ;
switch ( V_2 -> V_40 -> V_41 ) {
case V_42 :
V_8 += sprintf ( V_35 + V_8 , L_5 ) ;
break;
case V_43 :
V_8 += sprintf ( V_35 + V_8 , L_6 ) ;
break;
}
switch ( V_2 -> V_40 -> V_44 ) {
case V_45 :
V_8 += sprintf ( V_35 + V_8 , L_7 ) ;
break;
}
V_8 += sprintf ( V_35 + V_8 , L_8 ) ;
return V_8 ;
}
static T_3
F_21 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_28 * V_36 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
int V_8 = 0 , V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_22;
V_2 -> V_15 [ 0 ] &= 0x03 ;
switch ( V_2 -> V_15 [ 0 ] ) {
case V_47 :
V_8 += sprintf ( V_35 + V_8 , L_9 ) ;
break;
case V_48 :
V_8 += sprintf ( V_35 + V_8 , L_10 ) ;
break;
case V_49 :
switch ( V_2 -> V_40 -> V_41 ) {
case V_42 :
V_8 += sprintf ( V_35 + V_8 , L_11 ) ;
break;
case V_43 :
V_8 += sprintf ( V_35 + V_8 , L_12 ) ;
break;
}
break;
case V_50 :
switch ( V_2 -> V_40 -> V_44 ) {
case V_45 :
V_8 += sprintf ( V_35 + V_8 , L_13 ) ;
break;
}
break;
}
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3
F_22 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
const char * V_35 ,
T_4 V_8 )
{
struct V_28 * V_36 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
int V_16 ;
int V_51 = 0x03 ;
long V_4 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_23 ( V_35 , 10 , & V_4 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_22;
V_2 -> V_15 [ 0 ] &= ~ V_51 ;
V_2 -> V_15 [ 0 ] |= ( V_4 & V_51 ) ;
V_16 = F_1 ( V_2 , V_46 , V_2 -> V_15 [ 0 ] ) ;
if ( V_16 )
goto V_22;
F_18 ( & V_2 -> V_30 ) ;
return V_8 ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int F_24 ( struct V_28 * V_29 ,
struct V_52 const * V_53 ,
int * V_4 ,
int * V_54 ,
long V_51 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
T_1 V_3 ;
switch ( V_51 ) {
case 0 :
F_16 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_55 ) {
F_18 ( & V_2 -> V_30 ) ;
return - V_56 ;
}
V_3 = V_57 [ V_53 -> V_3 ] [ 0 ] ;
V_16 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_16 < 0 ) {
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
* V_4 = ( F_25 ( ( V_58 * ) V_2 -> V_15 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
F_18 ( & V_2 -> V_30 ) ;
return V_59 ;
case ( 1 << V_60 ) :
* V_4 = 0 ;
if ( V_53 -> type == V_61 )
* V_54 = V_2 -> V_40 -> V_62 ;
else
* V_54 = 555556 ;
return V_63 ;
default:
return - V_64 ;
}
}
static T_3 F_26 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_8 = 0 , V_16 , V_4 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_22;
switch ( V_4 & 0x03 ) {
case V_47 :
V_8 += sprintf ( V_35 + V_8 , L_14 ,
V_2 -> V_40 -> V_65 ,
V_2 -> V_40 -> V_65 / 2 ,
V_2 -> V_40 -> V_65 / 4 ) ;
break;
case V_49 :
V_8 += sprintf ( V_35 + V_8 , L_14 ,
V_2 -> V_40 -> V_66 ,
V_2 -> V_40 -> V_66 / 2 ,
V_2 -> V_40 -> V_66 / 4 ) ;
break;
case V_50 :
V_8 += sprintf ( V_35 + V_8 , L_14 ,
V_2 -> V_40 -> V_67 ,
V_2 -> V_40 -> V_67 / 2 ,
V_2 -> V_40 -> V_67 / 4 ) ;
break;
}
return V_8 ;
V_22:
return V_16 ;
}
static inline int F_27 ( struct V_1 * V_2 ,
const struct V_68 * V_40 ,
int * V_69 )
{
int V_16 ;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_22;
switch ( 0x03 & V_2 -> V_15 [ 0 ] ) {
case V_47 :
* V_69 = V_40 -> V_65 ;
break;
case V_49 :
* V_69 = V_40 -> V_66 ;
break;
case V_50 :
* V_69 = V_40 -> V_67 ;
break;
}
V_22:
return V_16 ;
}
static T_3 F_28 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 , V_8 = 0 , V_69 = 0 , V_4 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_27 ( V_2 , V_2 -> V_40 , & V_69 ) ;
if ( V_16 )
goto V_70;
V_16 = F_12 ( V_2 , V_71 ) ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_22;
V_4 = V_16 ;
if ( V_69 > 0 )
switch ( V_4 & 0x03 ) {
case 0x00 :
case 0x03 :
V_8 = sprintf ( V_35 , L_15 , V_69 ) ;
break;
case 0x01 :
V_8 = sprintf ( V_35 , L_15 , V_69 / 2 ) ;
break;
case 0x02 :
V_8 = sprintf ( V_35 , L_15 , V_69 / 4 ) ;
break;
}
return V_8 ;
V_70:
F_18 ( & V_2 -> V_30 ) ;
V_22:
return V_16 ;
}
static T_3 F_29 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
const char * V_35 ,
T_4 V_8 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 , V_69 = 0 ;
int V_72 ;
long V_4 ;
V_16 = F_23 ( V_35 , 10 , & V_4 ) ;
if ( V_16 )
return V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_27 ( V_2 , V_2 -> V_40 , & V_69 ) ;
if ( V_16 )
goto V_73;
V_16 = F_12 ( V_2 , V_71 ) ;
if ( V_16 < 0 )
goto V_73;
V_72 = V_16 ;
V_72 &= ~ 0x03 ;
if ( V_4 == V_69 / 2 ) {
V_72 |= V_74 ;
} else if ( V_4 == V_69 / 4 ) {
V_72 |= V_75 ;
} else if ( V_4 != V_69 ) {
V_16 = - V_64 ;
goto V_73;
}
V_16 = F_11 ( V_2 , V_71 ,
V_72 ) ;
V_73:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3 F_30 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
int V_4 ;
V_16 = F_4 ( V_2 , V_76 , 2 ) ;
if ( V_16 < 0 )
goto V_22;
V_4 = ( ( V_2 -> V_15 [ 0 ] & 0x3F ) << 3 ) | ( ( V_2 -> V_15 [ 1 ] & 0xE0 ) >> 5 ) ;
return sprintf ( V_35 , L_15 , V_4 ) ;
V_22:
return V_16 ;
}
static int F_31 ( struct V_28 * V_29 ,
int V_77 ,
int * V_4 )
{
int V_16 , V_78 ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_79 = F_32 ( V_77 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_12 ( V_2 , V_57 [ V_79 ] [ 1 ] ) ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_4 = 0 ;
if ( V_79 == 1 )
F_33 ( V_78 , ( unsigned long * ) & V_16 ,
F_34 ( V_2 -> V_40 -> V_80 ) )
* V_4 += V_2 -> V_40 -> V_80 [ V_78 ] ;
else
F_33 ( V_78 , ( unsigned long * ) & V_16 ,
F_34 ( V_2 -> V_40 -> V_81 ) )
* V_4 += V_2 -> V_40 -> V_81 [ V_78 ] ;
return 0 ;
}
static int F_35 ( struct V_28 * V_29 ,
int V_77 ,
int V_4 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_79 = F_32 ( V_77 ) ;
int V_16 ;
int V_78 ;
T_1 V_82 = 0 ;
if ( V_79 == 1 ) {
V_78 = F_34 ( V_2 -> V_40 -> V_80 ) ;
while ( V_78 > 0 )
if ( V_4 >= V_2 -> V_40 -> V_80 [ -- V_78 ] ) {
V_82 |= ( 1 << V_78 ) ;
V_4 -= V_2 -> V_40 -> V_80 [ V_78 ] ;
}
} else {
V_78 = F_34 ( V_2 -> V_40 -> V_81 ) ;
while ( V_78 > 0 )
if ( V_4 >= V_2 -> V_40 -> V_81 [ -- V_78 ] ) {
V_82 |= ( 1 << V_78 ) ;
V_4 -= V_2 -> V_40 -> V_81 [ V_78 ] ;
}
}
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_11 ( V_2 , V_57 [ V_79 ] [ 1 ] , V_82 ) ;
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static T_5 F_36 ( int V_83 , void * V_84 )
{
struct V_28 * V_29 = V_84 ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 , V_4 ;
T_6 V_85 = F_37 () ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_86 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_87;
F_38 ( V_4 , V_29 -> V_88 ) ;
if ( V_4 & V_89 )
F_39 ( V_29 , 0 ,
F_40 ( V_90 ,
0 ,
V_91 ,
V_92 ,
V_93 ) ,
V_85 ) ;
if ( V_4 & V_94 )
F_39 ( V_29 , 0 ,
F_40 ( V_90 ,
0 ,
V_95 ,
V_92 ,
V_96 ) ,
V_85 ) ;
if ( V_4 & V_97 )
F_39 ( V_29 , 0 ,
F_40 ( V_90 ,
0 ,
V_98 ,
V_92 ,
V_96 ) ,
V_85 ) ;
if ( V_4 & V_99 )
F_39 ( V_29 , 0 ,
F_40 ( V_90 ,
0 ,
V_100 ,
V_92 ,
V_96 ) ,
V_85 ) ;
V_87:
return V_101 ;
}
static int F_41 ( struct V_28 * V_29 ,
int V_77 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
T_1 V_102 = 0x03 ;
int V_79 = F_32 ( V_77 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_22;
if ( ( V_2 -> V_15 [ 0 ] & V_102 ) != V_48 )
V_16 = 0 ;
else {
V_16 = F_12 ( V_2 , V_103 ) ;
if ( V_16 < 0 )
goto V_22;
V_16 = ! ! ( V_16 & V_57 [ V_79 ] [ 2 ] ) ;
}
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static T_3 F_42 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
int V_16 , V_8 ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_4 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 < 0 )
return V_16 ;
V_8 = sprintf ( V_35 , L_15 ,
! ! ( V_4 & V_104 ) ) ;
return V_8 ;
}
static T_3 F_43 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
const char * V_35 ,
T_4 V_8 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
long V_4 ;
int V_16 ;
T_1 V_102 = V_104 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_23 ( V_35 , 10 , & V_4 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_22;
if ( V_4 && ! ( V_2 -> V_15 [ 0 ] & V_102 ) )
V_16 = F_1 ( V_2 , V_46 ,
( V_2 -> V_15 [ 0 ] | V_104 ) ) ;
else if ( ! V_4 && ( V_2 -> V_15 [ 0 ] & V_102 ) )
V_16 = F_1 ( V_2 , V_46 ,
( V_2 -> V_15 [ 0 ] & ~ V_102 ) ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ? V_16 : V_8 ;
}
static int F_44 ( struct V_28 * V_29 ,
int V_77 ,
int V_105 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 , V_72 ;
T_1 V_102 = 0x03 ;
int V_79 = F_32 ( V_77 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_12 ( V_2 , V_103 ) ;
if ( V_16 < 0 )
goto V_106;
V_72 = V_16 ;
if ( V_105 && ! ( V_72 & V_57 [ V_79 ] [ 2 ] ) ) {
V_16 = F_11 ( V_2 ,
V_103 ,
V_72 |
V_57 [ V_79 ] [ 2 ] ) ;
if ( V_16 )
goto V_106;
V_2 -> V_55 ++ ;
} else if ( ! V_105 && ( V_72 & V_57 [ V_79 ] [ 2 ] ) ) {
V_16 = F_11 ( V_2 ,
V_103 ,
V_72 &
~ ( V_57 [ V_79 ] [ 2 ] ) ) ;
if ( V_16 )
goto V_106;
V_2 -> V_55 -- ;
}
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_106;
if ( ( V_2 -> V_55 )
&& ( ( V_2 -> V_15 [ 0 ] & V_102 ) != V_48 ) )
V_16 = F_1 ( V_2 , V_46 ,
( V_2 -> V_15 [ 0 ] & ~ V_102 )
| V_48 ) ;
else if ( ! ( V_2 -> V_55 )
&& ( ( V_2 -> V_15 [ 0 ] & V_102 ) == V_48 ) )
V_16 = F_1 ( V_2 , V_46 ,
( V_2 -> V_15 [ 0 ] & ~ V_102 ) ) ;
V_106:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_86 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_12 ( V_2 , V_103 ) ;
if ( V_16 < 0 )
goto V_22;
V_16 = F_11 ( V_2 , V_103 ,
V_16 & V_107 ) ;
if ( V_16 )
goto V_22;
V_16 = F_12 ( V_2 , V_71 ) ;
V_16 = F_11 ( V_2 , V_71 ,
( V_16 & V_108 )
| V_109
| V_110
| V_111
| V_75 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_112 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 ,
V_112 ,
( V_16 & V_113 )
| V_114 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_46 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_46 ,
( V_2 -> V_15 [ 0 ] & V_115 ) ) ;
V_2 -> V_116 = 11 ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int T_7 F_46 ( struct V_117 * V_118 )
{
int V_16 , V_119 = 0 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_29 = F_47 ( sizeof( * V_2 ) ) ;
if ( V_29 == NULL ) {
V_16 = - V_120 ;
goto V_22;
}
V_2 = F_15 ( V_29 ) ;
F_48 ( V_118 , V_29 ) ;
V_2 -> V_6 = V_118 ;
F_49 ( & V_2 -> V_30 ) ;
V_2 -> V_40 = & V_121 [ F_50 ( V_118 )
-> V_122 ] ;
V_29 -> V_27 . V_123 = & V_118 -> V_27 ;
V_29 -> V_124 = F_50 ( V_118 ) -> V_124 ;
if ( V_2 -> V_40 -> V_125 )
V_29 -> V_40 = & V_126 ;
else {
V_29 -> V_40 = & V_127 ;
V_29 -> V_128 = V_129 ;
V_29 -> V_130 = F_34 ( V_129 ) ;
}
V_29 -> V_131 = V_132 ;
F_51 ( V_29 ) ;
V_16 = F_52 ( V_29 ) ;
if ( V_16 < 0 )
goto V_133;
V_119 = 1 ;
V_16 = F_53 ( V_29 -> V_88 , 0 ,
V_129 ,
F_34 ( V_129 ) ) ;
if ( V_16 < 0 )
goto V_134;
if ( V_118 -> V_83 && F_54 ( F_55 ( V_118 -> V_83 ) ) > 0 ) {
V_16 = F_56 ( V_118 -> V_83 ,
NULL ,
& F_36 ,
V_135 ,
L_16 ,
V_29 ) ;
if ( V_16 )
goto V_136;
}
F_57 ( V_29 ) ;
V_16 = F_45 ( V_2 ) ;
if ( V_16 )
goto V_137;
return 0 ;
V_137:
if ( V_118 -> V_83 && F_54 ( F_55 ( V_118 -> V_83 ) ) > 0 )
F_58 ( V_118 -> V_83 , V_29 ) ;
V_136:
F_59 ( V_29 -> V_88 ) ;
V_134:
V_133:
if ( V_119 )
F_60 ( V_29 ) ;
else
F_61 ( V_29 ) ;
V_22:
return V_16 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_112 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_112 ,
( V_2 -> V_15 [ 0 ] &
~ ( V_138 |
V_139 |
V_140 ) ) ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int F_63 ( struct V_117 * V_118 )
{
struct V_28 * V_29 = F_64 ( V_118 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
V_16 = F_62 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_118 -> V_83 && F_54 ( F_55 ( V_118 -> V_83 ) ) > 0 )
F_58 ( V_118 -> V_83 , V_29 ) ;
F_59 ( V_29 -> V_88 ) ;
F_65 ( V_29 ) ;
F_60 ( V_29 ) ;
return 0 ;
}
static T_8 int F_66 ( void )
{
return F_67 ( & V_141 ) ;
}
static T_9 void F_68 ( void )
{
F_69 ( & V_141 ) ;
}
