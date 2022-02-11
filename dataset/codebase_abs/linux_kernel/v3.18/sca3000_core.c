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
struct V_9 V_10 [ 2 ] = {
{
. V_8 = 1 ,
. V_11 = V_2 -> V_5 ,
} , {
. V_8 = V_8 ,
. V_12 = V_2 -> V_13 ,
}
} ;
V_2 -> V_5 [ 0 ] = F_5 ( V_7 ) ;
return F_6 ( V_2 -> V_6 , V_10 , F_7 ( V_10 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_4 ( V_2 , V_15 , 1 ) ;
if ( V_14 < 0 )
return V_14 ;
return ! ( V_2 -> V_13 [ 0 ] & V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_9 V_10 [ 3 ] = {
{
. V_8 = 2 ,
. V_17 = 1 ,
. V_11 = V_2 -> V_5 ,
} , {
. V_8 = 2 ,
. V_17 = 1 ,
. V_11 = V_2 -> V_5 + 2 ,
} , {
. V_8 = 2 ,
. V_11 = V_2 -> V_5 + 4 ,
} ,
} ;
V_2 -> V_5 [ 0 ] = F_2 ( V_18 ) ;
V_2 -> V_5 [ 1 ] = 0x00 ;
V_2 -> V_5 [ 2 ] = F_2 ( V_18 ) ;
V_2 -> V_5 [ 3 ] = 0x50 ;
V_2 -> V_5 [ 4 ] = F_2 ( V_18 ) ;
V_2 -> V_5 [ 5 ] = 0xA0 ;
return F_6 ( V_2 -> V_6 , V_10 , F_7 ( V_10 ) ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_2 V_19 ,
T_2 V_4 )
{
int V_14 ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
goto V_20;
if ( V_14 ) {
V_14 = F_9 ( V_2 ) ;
if ( V_14 )
goto V_20;
}
V_14 = F_1 ( V_2 , V_21 , V_19 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_22 , V_4 ) ;
V_20:
return V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_23 )
{
int V_14 ;
V_14 = F_8 ( V_2 ) ;
if ( V_14 < 0 )
goto V_20;
if ( V_14 ) {
V_14 = F_9 ( V_2 ) ;
if ( V_14 )
goto V_20;
}
V_14 = F_1 ( V_2 , V_21 , V_23 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_22 , 1 ) ;
if ( V_14 )
goto V_20;
else
return V_2 -> V_13 [ 0 ] ;
V_20:
return V_14 ;
}
static int F_12 ( struct V_24 * V_25 )
{
int V_14 ;
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_15 , 1 ) ;
if ( V_14 < 0 )
goto V_20;
if ( V_2 -> V_13 [ 0 ] & V_29 )
F_16 ( V_25 , L_1 ) ;
if ( V_2 -> V_13 [ 0 ] & V_30 )
F_16 ( V_25 , L_2 ) ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static T_3 F_18 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
int V_8 = 0 , V_14 ;
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_34 , 1 ) ;
if ( V_14 < 0 )
goto V_20;
V_8 += sprintf ( V_33 + V_8 ,
L_3 ,
V_2 -> V_13 [ 0 ] & V_35 ,
V_2 -> V_13 [ 0 ] & V_36 ) ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ? V_14 : V_8 ;
}
static T_3
F_19 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_8 = 0 ;
V_8 += sprintf ( V_33 + V_8 , L_4 ) ;
switch ( V_2 -> V_37 -> V_38 ) {
case V_39 :
V_8 += sprintf ( V_33 + V_8 , L_5 ) ;
break;
case V_40 :
V_8 += sprintf ( V_33 + V_8 , L_6 ) ;
break;
}
switch ( V_2 -> V_37 -> V_41 ) {
case V_42 :
V_8 += sprintf ( V_33 + V_8 , L_7 ) ;
break;
}
V_8 += sprintf ( V_33 + V_8 , L_8 ) ;
return V_8 ;
}
static T_3
F_20 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_8 = 0 , V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
V_2 -> V_13 [ 0 ] &= 0x03 ;
switch ( V_2 -> V_13 [ 0 ] ) {
case V_44 :
V_8 += sprintf ( V_33 + V_8 , L_9 ) ;
break;
case V_45 :
V_8 += sprintf ( V_33 + V_8 , L_10 ) ;
break;
case V_46 :
switch ( V_2 -> V_37 -> V_38 ) {
case V_39 :
V_8 += sprintf ( V_33 + V_8 , L_11 ) ;
break;
case V_40 :
V_8 += sprintf ( V_33 + V_8 , L_12 ) ;
break;
}
break;
case V_47 :
switch ( V_2 -> V_37 -> V_41 ) {
case V_42 :
V_8 += sprintf ( V_33 + V_8 , L_13 ) ;
break;
}
break;
}
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ? V_14 : V_8 ;
}
static T_3
F_21 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_4 V_8 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 ;
T_1 V_48 = 0x03 ;
T_1 V_4 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_22 ( V_33 , 10 , & V_4 ) ;
if ( V_14 )
goto V_20;
if ( V_4 > 3 ) {
V_14 = - V_49 ;
goto V_20;
}
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
V_2 -> V_13 [ 0 ] &= ~ V_48 ;
V_2 -> V_13 [ 0 ] |= ( V_4 & V_48 ) ;
V_14 = F_1 ( V_2 , V_43 , V_2 -> V_13 [ 0 ] ) ;
if ( V_14 )
goto V_20;
F_17 ( & V_2 -> V_28 ) ;
return V_8 ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_23 ( struct V_26 * V_27 ,
struct V_50 const * V_51 ,
int * V_4 ,
int * V_52 ,
long V_48 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 ;
T_1 V_3 ;
switch ( V_48 ) {
case V_53 :
F_15 ( & V_2 -> V_28 ) ;
if ( V_51 -> type == V_54 ) {
if ( V_2 -> V_55 ) {
F_17 ( & V_2 -> V_28 ) ;
return - V_56 ;
}
V_3 = V_57 [ V_51 -> V_3 ] [ 0 ] ;
V_14 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_14 < 0 ) {
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
* V_4 = ( F_24 ( ( V_58 * ) V_2 -> V_13 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
} else {
V_14 = F_4 ( V_2 ,
V_59 , 2 ) ;
if ( V_14 < 0 ) {
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
* V_4 = ( ( V_2 -> V_13 [ 0 ] & 0x3F ) << 3 ) |
( ( V_2 -> V_13 [ 1 ] & 0xE0 ) >> 5 ) ;
}
F_17 ( & V_2 -> V_28 ) ;
return V_60 ;
case V_61 :
* V_4 = 0 ;
if ( V_51 -> type == V_54 )
* V_52 = V_2 -> V_37 -> V_62 ;
else
* V_52 = 555556 ;
return V_63 ;
case V_64 :
* V_4 = - 214 ;
* V_52 = 600000 ;
return V_63 ;
default:
return - V_49 ;
}
}
static T_3 F_25 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_8 = 0 , V_14 , V_4 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 )
goto V_20;
switch ( V_4 & 0x03 ) {
case V_44 :
V_8 += sprintf ( V_33 + V_8 , L_14 ,
V_2 -> V_37 -> V_65 ,
V_2 -> V_37 -> V_65 / 2 ,
V_2 -> V_37 -> V_65 / 4 ) ;
break;
case V_46 :
V_8 += sprintf ( V_33 + V_8 , L_14 ,
V_2 -> V_37 -> V_66 ,
V_2 -> V_37 -> V_66 / 2 ,
V_2 -> V_37 -> V_66 / 4 ) ;
break;
case V_47 :
V_8 += sprintf ( V_33 + V_8 , L_14 ,
V_2 -> V_37 -> V_67 ,
V_2 -> V_37 -> V_67 / 2 ,
V_2 -> V_37 -> V_67 / 4 ) ;
break;
}
return V_8 ;
V_20:
return V_14 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
const struct V_68 * V_37 ,
int * V_69 )
{
int V_14 ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
switch ( 0x03 & V_2 -> V_13 [ 0 ] ) {
case V_44 :
* V_69 = V_37 -> V_65 ;
break;
case V_46 :
* V_69 = V_37 -> V_66 ;
break;
case V_47 :
* V_69 = V_37 -> V_67 ;
break;
}
V_20:
return V_14 ;
}
static T_3 F_27 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 , V_8 = 0 , V_69 = 0 , V_4 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_26 ( V_2 , V_2 -> V_37 , & V_69 ) ;
if ( V_14 )
goto V_70;
V_14 = F_11 ( V_2 , V_71 ) ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 )
goto V_20;
V_4 = V_14 ;
if ( V_69 > 0 )
switch ( V_4 & 0x03 ) {
case 0x00 :
case 0x03 :
V_8 = sprintf ( V_33 , L_15 , V_69 ) ;
break;
case 0x01 :
V_8 = sprintf ( V_33 , L_15 , V_69 / 2 ) ;
break;
case 0x02 :
V_8 = sprintf ( V_33 , L_15 , V_69 / 4 ) ;
break;
}
return V_8 ;
V_70:
F_17 ( & V_2 -> V_28 ) ;
V_20:
return V_14 ;
}
static T_3 F_28 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_4 V_8 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 , V_69 = 0 ;
int V_72 ;
int V_4 ;
V_14 = F_29 ( V_33 , 10 , & V_4 ) ;
if ( V_14 )
return V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_26 ( V_2 , V_2 -> V_37 , & V_69 ) ;
if ( V_14 )
goto V_73;
V_14 = F_11 ( V_2 , V_71 ) ;
if ( V_14 < 0 )
goto V_73;
V_72 = V_14 ;
V_72 &= ~ 0x03 ;
if ( V_4 == V_69 / 2 ) {
V_72 |= V_74 ;
} else if ( V_4 == V_69 / 4 ) {
V_72 |= V_75 ;
} else if ( V_4 != V_69 ) {
V_14 = - V_49 ;
goto V_73;
}
V_14 = F_10 ( V_2 , V_71 ,
V_72 ) ;
V_73:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ? V_14 : V_8 ;
}
static int F_30 ( struct V_26 * V_27 ,
const struct V_50 * V_51 ,
enum V_76 type ,
enum V_77 V_78 ,
enum V_79 V_37 ,
int * V_4 , int * V_52 )
{
int V_14 , V_80 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_81 = V_51 -> V_82 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_11 ( V_2 , V_57 [ V_81 ] [ 1 ] ) ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_4 = 0 ;
if ( V_81 == 1 )
F_31 ( V_80 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_37 -> V_83 ) )
* V_4 += V_2 -> V_37 -> V_83 [ V_80 ] ;
else
F_31 ( V_80 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_37 -> V_84 ) )
* V_4 += V_2 -> V_37 -> V_84 [ V_80 ] ;
return V_60 ;
}
static int F_32 ( struct V_26 * V_27 ,
const struct V_50 * V_51 ,
enum V_76 type ,
enum V_77 V_78 ,
enum V_79 V_37 ,
int V_4 , int V_52 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_81 = V_51 -> V_82 ;
int V_14 ;
int V_80 ;
T_1 V_85 = 0 ;
if ( V_81 == 1 ) {
V_80 = F_7 ( V_2 -> V_37 -> V_83 ) ;
while ( V_80 > 0 )
if ( V_4 >= V_2 -> V_37 -> V_83 [ -- V_80 ] ) {
V_85 |= ( 1 << V_80 ) ;
V_4 -= V_2 -> V_37 -> V_83 [ V_80 ] ;
}
} else {
V_80 = F_7 ( V_2 -> V_37 -> V_84 ) ;
while ( V_80 > 0 )
if ( V_4 >= V_2 -> V_37 -> V_84 [ -- V_80 ] ) {
V_85 |= ( 1 << V_80 ) ;
V_4 -= V_2 -> V_37 -> V_84 [ V_80 ] ;
}
}
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_10 ( V_2 , V_57 [ V_81 ] [ 1 ] , V_85 ) ;
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static T_5 F_33 ( int V_86 , void * V_87 )
{
struct V_26 * V_27 = V_87 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 , V_4 ;
T_6 V_88 = F_34 () ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_89 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 )
goto V_90;
F_35 ( V_4 , V_27 -> V_91 ) ;
if ( V_4 & V_92 )
F_36 ( V_27 ,
F_37 ( V_54 ,
0 ,
V_93 ,
V_94 ,
V_95 ) ,
V_88 ) ;
if ( V_4 & V_96 )
F_36 ( V_27 ,
F_37 ( V_54 ,
0 ,
V_97 ,
V_94 ,
V_98 ) ,
V_88 ) ;
if ( V_4 & V_99 )
F_36 ( V_27 ,
F_37 ( V_54 ,
0 ,
V_100 ,
V_94 ,
V_98 ) ,
V_88 ) ;
if ( V_4 & V_101 )
F_36 ( V_27 ,
F_37 ( V_54 ,
0 ,
V_102 ,
V_94 ,
V_98 ) ,
V_88 ) ;
V_90:
return V_103 ;
}
static int F_38 ( struct V_26 * V_27 ,
const struct V_50 * V_51 ,
enum V_76 type ,
enum V_77 V_78 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 ;
T_1 V_104 = 0x03 ;
int V_81 = V_51 -> V_82 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
if ( ( V_2 -> V_13 [ 0 ] & V_104 ) != V_45 )
V_14 = 0 ;
else {
V_14 = F_11 ( V_2 , V_105 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = ! ! ( V_14 & V_57 [ V_81 ] [ 2 ] ) ;
}
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static T_3 F_39 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
int V_14 , V_8 ;
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_4 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 = sprintf ( V_33 , L_15 ,
! ! ( V_4 & V_106 ) ) ;
return V_8 ;
}
static T_3 F_40 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_4 V_8 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
T_1 V_4 ;
int V_14 ;
T_1 V_104 = V_106 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_22 ( V_33 , 10 , & V_4 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
if ( V_4 && ! ( V_2 -> V_13 [ 0 ] & V_104 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] | V_106 ) ) ;
else if ( ! V_4 && ( V_2 -> V_13 [ 0 ] & V_104 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_104 ) ) ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ? V_14 : V_8 ;
}
static int F_41 ( struct V_26 * V_27 ,
const struct V_50 * V_51 ,
enum V_76 type ,
enum V_77 V_78 ,
int V_107 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 , V_72 ;
T_1 V_104 = 0x03 ;
int V_81 = V_51 -> V_82 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_11 ( V_2 , V_105 ) ;
if ( V_14 < 0 )
goto V_108;
V_72 = V_14 ;
if ( V_107 && ! ( V_72 & V_57 [ V_81 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_105 ,
V_72 |
V_57 [ V_81 ] [ 2 ] ) ;
if ( V_14 )
goto V_108;
V_2 -> V_55 ++ ;
} else if ( ! V_107 && ( V_72 & V_57 [ V_81 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_105 ,
V_72 &
~ ( V_57 [ V_81 ] [ 2 ] ) ) ;
if ( V_14 )
goto V_108;
V_2 -> V_55 -- ;
}
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_108;
if ( ( V_2 -> V_55 )
&& ( ( V_2 -> V_13 [ 0 ] & V_104 ) != V_45 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_104 )
| V_45 ) ;
else if ( ! ( V_2 -> V_55 )
&& ( ( V_2 -> V_13 [ 0 ] & V_104 ) == V_45 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_104 ) ) ;
V_108:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_89 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_105 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = F_10 ( V_2 , V_105 ,
V_14 & V_109 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_71 ) ;
V_14 = F_10 ( V_2 , V_71 ,
( V_14 & V_110 )
| V_111
| V_112
| V_113
| V_75 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_114 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 ,
V_114 ,
( V_14 & V_115 )
| V_116 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & V_117 ) ) ;
V_2 -> V_118 = 11 ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_43 ( struct V_119 * V_120 )
{
int V_14 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
V_27 = F_44 ( & V_120 -> V_25 , sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_121 ;
V_2 = F_14 ( V_27 ) ;
F_45 ( V_120 , V_27 ) ;
V_2 -> V_6 = V_120 ;
F_46 ( & V_2 -> V_28 ) ;
V_2 -> V_37 = & V_122 [ F_47 ( V_120 )
-> V_123 ] ;
V_27 -> V_25 . V_124 = & V_120 -> V_25 ;
V_27 -> V_125 = F_47 ( V_120 ) -> V_125 ;
V_27 -> V_37 = & V_126 ;
if ( V_2 -> V_37 -> V_127 ) {
V_27 -> V_128 = V_129 ;
V_27 -> V_130 =
F_7 ( V_129 ) ;
} else {
V_27 -> V_128 = V_131 ;
V_27 -> V_130 = F_7 ( V_131 ) ;
}
V_27 -> V_132 = V_133 ;
F_48 ( V_27 ) ;
V_14 = F_49 ( V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_50 ( V_27 ,
V_131 ,
F_7 ( V_131 ) ) ;
if ( V_14 < 0 )
goto V_134;
if ( V_27 -> V_91 ) {
F_51 ( V_27 , V_27 -> V_91 , 0 ) ;
F_51 ( V_27 , V_27 -> V_91 , 1 ) ;
F_51 ( V_27 , V_27 -> V_91 , 2 ) ;
}
if ( V_120 -> V_86 ) {
V_14 = F_52 ( V_120 -> V_86 ,
NULL ,
& F_33 ,
V_135 | V_136 ,
L_16 ,
V_27 ) ;
if ( V_14 )
goto V_137;
}
F_53 ( V_27 ) ;
V_14 = F_42 ( V_2 ) ;
if ( V_14 )
goto V_138;
return 0 ;
V_138:
if ( V_120 -> V_86 )
F_54 ( V_120 -> V_86 , V_27 ) ;
V_137:
F_55 ( V_27 ) ;
V_134:
F_56 ( V_27 ) ;
return V_14 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_114 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_114 ,
( V_2 -> V_13 [ 0 ] &
~ ( V_139 |
V_140 |
V_141 ) ) ) ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_58 ( struct V_119 * V_120 )
{
struct V_26 * V_27 = F_59 ( V_120 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
F_57 ( V_2 ) ;
if ( V_120 -> V_86 )
F_54 ( V_120 -> V_86 , V_27 ) ;
F_56 ( V_27 ) ;
F_55 ( V_27 ) ;
F_60 ( V_27 ) ;
return 0 ;
}
