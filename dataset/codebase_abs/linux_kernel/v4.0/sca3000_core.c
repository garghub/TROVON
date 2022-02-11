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
static T_3 F_12 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
int V_8 = 0 , V_14 ;
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_32 , 1 ) ;
if ( V_14 < 0 )
goto V_20;
V_8 += sprintf ( V_28 + V_8 ,
L_1 ,
V_2 -> V_13 [ 0 ] & V_33 ,
V_2 -> V_13 [ 0 ] & V_34 ) ;
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ? V_14 : V_8 ;
}
static T_3
F_17 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_8 = 0 ;
V_8 += sprintf ( V_28 + V_8 , L_2 ) ;
switch ( V_2 -> V_35 -> V_36 ) {
case V_37 :
V_8 += sprintf ( V_28 + V_8 , L_3 ) ;
break;
case V_38 :
V_8 += sprintf ( V_28 + V_8 , L_4 ) ;
break;
}
switch ( V_2 -> V_35 -> V_39 ) {
case V_40 :
V_8 += sprintf ( V_28 + V_8 , L_5 ) ;
break;
}
V_8 += sprintf ( V_28 + V_8 , L_6 ) ;
return V_8 ;
}
static T_3
F_18 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_8 = 0 , V_14 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_20;
V_2 -> V_13 [ 0 ] &= 0x03 ;
switch ( V_2 -> V_13 [ 0 ] ) {
case V_42 :
V_8 += sprintf ( V_28 + V_8 , L_7 ) ;
break;
case V_43 :
V_8 += sprintf ( V_28 + V_8 , L_8 ) ;
break;
case V_44 :
switch ( V_2 -> V_35 -> V_36 ) {
case V_37 :
V_8 += sprintf ( V_28 + V_8 , L_9 ) ;
break;
case V_38 :
V_8 += sprintf ( V_28 + V_8 , L_10 ) ;
break;
}
break;
case V_45 :
switch ( V_2 -> V_35 -> V_39 ) {
case V_40 :
V_8 += sprintf ( V_28 + V_8 , L_11 ) ;
break;
}
break;
}
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ? V_14 : V_8 ;
}
static T_3
F_19 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 ,
T_4 V_8 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 ;
T_1 V_46 = 0x03 ;
T_1 V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_20 ( V_28 , 10 , & V_4 ) ;
if ( V_14 )
goto V_20;
if ( V_4 > 3 ) {
V_14 = - V_47 ;
goto V_20;
}
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_20;
V_2 -> V_13 [ 0 ] &= ~ V_46 ;
V_2 -> V_13 [ 0 ] |= ( V_4 & V_46 ) ;
V_14 = F_1 ( V_2 , V_41 , V_2 -> V_13 [ 0 ] ) ;
if ( V_14 )
goto V_20;
F_16 ( & V_2 -> V_31 ) ;
return V_8 ;
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
static int F_21 ( struct V_29 * V_30 ,
struct V_48 const * V_49 ,
int * V_4 ,
int * V_50 ,
long V_46 )
{
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 ;
T_1 V_3 ;
switch ( V_46 ) {
case V_51 :
F_15 ( & V_2 -> V_31 ) ;
if ( V_49 -> type == V_52 ) {
if ( V_2 -> V_53 ) {
F_16 ( & V_2 -> V_31 ) ;
return - V_54 ;
}
V_3 = V_55 [ V_49 -> V_3 ] [ 0 ] ;
V_14 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_14 < 0 ) {
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
* V_4 = ( F_22 ( ( V_56 * ) V_2 -> V_13 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
} else {
V_14 = F_4 ( V_2 ,
V_57 , 2 ) ;
if ( V_14 < 0 ) {
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
* V_4 = ( ( V_2 -> V_13 [ 0 ] & 0x3F ) << 3 ) |
( ( V_2 -> V_13 [ 1 ] & 0xE0 ) >> 5 ) ;
}
F_16 ( & V_2 -> V_31 ) ;
return V_58 ;
case V_59 :
* V_4 = 0 ;
if ( V_49 -> type == V_52 )
* V_50 = V_2 -> V_35 -> V_60 ;
else
* V_50 = 555556 ;
return V_61 ;
case V_62 :
* V_4 = - 214 ;
* V_50 = 600000 ;
return V_61 ;
default:
return - V_47 ;
}
}
static T_3 F_23 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_8 = 0 , V_14 , V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_16 ( & V_2 -> V_31 ) ;
if ( V_14 )
goto V_20;
switch ( V_4 & 0x03 ) {
case V_42 :
V_8 += sprintf ( V_28 + V_8 , L_12 ,
V_2 -> V_35 -> V_63 ,
V_2 -> V_35 -> V_63 / 2 ,
V_2 -> V_35 -> V_63 / 4 ) ;
break;
case V_44 :
V_8 += sprintf ( V_28 + V_8 , L_12 ,
V_2 -> V_35 -> V_64 ,
V_2 -> V_35 -> V_64 / 2 ,
V_2 -> V_35 -> V_64 / 4 ) ;
break;
case V_45 :
V_8 += sprintf ( V_28 + V_8 , L_12 ,
V_2 -> V_35 -> V_65 ,
V_2 -> V_35 -> V_65 / 2 ,
V_2 -> V_35 -> V_65 / 4 ) ;
break;
}
return V_8 ;
V_20:
return V_14 ;
}
static inline int F_24 ( struct V_1 * V_2 ,
const struct V_66 * V_35 ,
int * V_67 )
{
int V_14 ;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_20;
switch ( 0x03 & V_2 -> V_13 [ 0 ] ) {
case V_42 :
* V_67 = V_35 -> V_63 ;
break;
case V_44 :
* V_67 = V_35 -> V_64 ;
break;
case V_45 :
* V_67 = V_35 -> V_65 ;
break;
}
V_20:
return V_14 ;
}
static T_3 F_25 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 , V_8 = 0 , V_67 = 0 , V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_24 ( V_2 , V_2 -> V_35 , & V_67 ) ;
if ( V_14 )
goto V_68;
V_14 = F_11 ( V_2 , V_69 ) ;
F_16 ( & V_2 -> V_31 ) ;
if ( V_14 )
goto V_20;
V_4 = V_14 ;
if ( V_67 > 0 )
switch ( V_4 & 0x03 ) {
case 0x00 :
case 0x03 :
V_8 = sprintf ( V_28 , L_13 , V_67 ) ;
break;
case 0x01 :
V_8 = sprintf ( V_28 , L_13 , V_67 / 2 ) ;
break;
case 0x02 :
V_8 = sprintf ( V_28 , L_13 , V_67 / 4 ) ;
break;
}
return V_8 ;
V_68:
F_16 ( & V_2 -> V_31 ) ;
V_20:
return V_14 ;
}
static T_3 F_26 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 ,
T_4 V_8 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 , V_67 = 0 ;
int V_70 ;
int V_4 ;
V_14 = F_27 ( V_28 , 10 , & V_4 ) ;
if ( V_14 )
return V_14 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_24 ( V_2 , V_2 -> V_35 , & V_67 ) ;
if ( V_14 )
goto V_71;
V_14 = F_11 ( V_2 , V_69 ) ;
if ( V_14 < 0 )
goto V_71;
V_70 = V_14 ;
V_70 &= ~ 0x03 ;
if ( V_4 == V_67 / 2 ) {
V_70 |= V_72 ;
} else if ( V_4 == V_67 / 4 ) {
V_70 |= V_73 ;
} else if ( V_4 != V_67 ) {
V_14 = - V_47 ;
goto V_71;
}
V_14 = F_10 ( V_2 , V_69 ,
V_70 ) ;
V_71:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ? V_14 : V_8 ;
}
static int F_28 ( struct V_29 * V_30 ,
const struct V_48 * V_49 ,
enum V_74 type ,
enum V_75 V_76 ,
enum V_77 V_35 ,
int * V_4 , int * V_50 )
{
int V_14 , V_78 ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_79 = V_49 -> V_80 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_11 ( V_2 , V_55 [ V_79 ] [ 1 ] ) ;
F_16 ( & V_2 -> V_31 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_4 = 0 ;
if ( V_79 == 1 )
F_29 ( V_78 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_35 -> V_81 ) )
* V_4 += V_2 -> V_35 -> V_81 [ V_78 ] ;
else
F_29 ( V_78 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_35 -> V_82 ) )
* V_4 += V_2 -> V_35 -> V_82 [ V_78 ] ;
return V_58 ;
}
static int F_30 ( struct V_29 * V_30 ,
const struct V_48 * V_49 ,
enum V_74 type ,
enum V_75 V_76 ,
enum V_77 V_35 ,
int V_4 , int V_50 )
{
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_79 = V_49 -> V_80 ;
int V_14 ;
int V_78 ;
T_1 V_83 = 0 ;
if ( V_79 == 1 ) {
V_78 = F_7 ( V_2 -> V_35 -> V_81 ) ;
while ( V_78 > 0 )
if ( V_4 >= V_2 -> V_35 -> V_81 [ -- V_78 ] ) {
V_83 |= ( 1 << V_78 ) ;
V_4 -= V_2 -> V_35 -> V_81 [ V_78 ] ;
}
} else {
V_78 = F_7 ( V_2 -> V_35 -> V_82 ) ;
while ( V_78 > 0 )
if ( V_4 >= V_2 -> V_35 -> V_82 [ -- V_78 ] ) {
V_83 |= ( 1 << V_78 ) ;
V_4 -= V_2 -> V_35 -> V_82 [ V_78 ] ;
}
}
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_10 ( V_2 , V_55 [ V_79 ] [ 1 ] , V_83 ) ;
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
static T_5 F_31 ( int V_84 , void * V_85 )
{
struct V_29 * V_30 = V_85 ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 , V_4 ;
T_6 V_86 = F_32 () ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_87 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_16 ( & V_2 -> V_31 ) ;
if ( V_14 )
goto V_88;
F_33 ( V_4 , V_30 -> V_89 ) ;
if ( V_4 & V_90 )
F_34 ( V_30 ,
F_35 ( V_52 ,
0 ,
V_91 ,
V_92 ,
V_93 ) ,
V_86 ) ;
if ( V_4 & V_94 )
F_34 ( V_30 ,
F_35 ( V_52 ,
0 ,
V_95 ,
V_92 ,
V_96 ) ,
V_86 ) ;
if ( V_4 & V_97 )
F_34 ( V_30 ,
F_35 ( V_52 ,
0 ,
V_98 ,
V_92 ,
V_96 ) ,
V_86 ) ;
if ( V_4 & V_99 )
F_34 ( V_30 ,
F_35 ( V_52 ,
0 ,
V_100 ,
V_92 ,
V_96 ) ,
V_86 ) ;
V_88:
return V_101 ;
}
static int F_36 ( struct V_29 * V_30 ,
const struct V_48 * V_49 ,
enum V_74 type ,
enum V_75 V_76 )
{
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 ;
T_1 V_102 = 0x03 ;
int V_79 = V_49 -> V_80 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_20;
if ( ( V_2 -> V_13 [ 0 ] & V_102 ) != V_43 )
V_14 = 0 ;
else {
V_14 = F_11 ( V_2 , V_103 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = ! ! ( V_14 & V_55 [ V_79 ] [ 2 ] ) ;
}
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
static T_3 F_37 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
int V_14 , V_8 ;
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_16 ( & V_2 -> V_31 ) ;
if ( V_14 < 0 )
return V_14 ;
V_8 = sprintf ( V_28 , L_13 ,
! ! ( V_4 & V_104 ) ) ;
return V_8 ;
}
static T_3 F_38 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 ,
T_4 V_8 )
{
struct V_29 * V_30 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
T_1 V_4 ;
int V_14 ;
T_1 V_102 = V_104 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_20 ( V_28 , 10 , & V_4 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_20;
if ( V_4 && ! ( V_2 -> V_13 [ 0 ] & V_102 ) )
V_14 = F_1 ( V_2 , V_41 ,
( V_2 -> V_13 [ 0 ] | V_104 ) ) ;
else if ( ! V_4 && ( V_2 -> V_13 [ 0 ] & V_102 ) )
V_14 = F_1 ( V_2 , V_41 ,
( V_2 -> V_13 [ 0 ] & ~ V_102 ) ) ;
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ? V_14 : V_8 ;
}
static int F_39 ( struct V_29 * V_30 ,
const struct V_48 * V_49 ,
enum V_74 type ,
enum V_75 V_76 ,
int V_105 )
{
struct V_1 * V_2 = F_14 ( V_30 ) ;
int V_14 , V_70 ;
T_1 V_102 = 0x03 ;
int V_79 = V_49 -> V_80 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_11 ( V_2 , V_103 ) ;
if ( V_14 < 0 )
goto V_106;
V_70 = V_14 ;
if ( V_105 && ! ( V_70 & V_55 [ V_79 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_103 ,
V_70 |
V_55 [ V_79 ] [ 2 ] ) ;
if ( V_14 )
goto V_106;
V_2 -> V_53 ++ ;
} else if ( ! V_105 && ( V_70 & V_55 [ V_79 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_103 ,
V_70 &
~ ( V_55 [ V_79 ] [ 2 ] ) ) ;
if ( V_14 )
goto V_106;
V_2 -> V_53 -- ;
}
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_106;
if ( ( V_2 -> V_53 )
&& ( ( V_2 -> V_13 [ 0 ] & V_102 ) != V_43 ) )
V_14 = F_1 ( V_2 , V_41 ,
( V_2 -> V_13 [ 0 ] & ~ V_102 )
| V_43 ) ;
else if ( ! ( V_2 -> V_53 )
&& ( ( V_2 -> V_13 [ 0 ] & V_102 ) == V_43 ) )
V_14 = F_1 ( V_2 , V_41 ,
( V_2 -> V_13 [ 0 ] & ~ V_102 ) ) ;
V_106:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_14 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_87 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_103 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = F_10 ( V_2 , V_103 ,
V_14 & V_107 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_69 ) ;
V_14 = F_10 ( V_2 , V_69 ,
( V_14 & V_108 )
| V_109
| V_110
| V_111
| V_73 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_112 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 ,
V_112 ,
( V_14 & V_113 )
| V_114 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_41 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_41 ,
( V_2 -> V_13 [ 0 ] & V_115 ) ) ;
V_2 -> V_116 = 11 ;
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
static int F_41 ( struct V_117 * V_118 )
{
int V_14 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
V_30 = F_42 ( & V_118 -> V_25 , sizeof( * V_2 ) ) ;
if ( ! V_30 )
return - V_119 ;
V_2 = F_14 ( V_30 ) ;
F_43 ( V_118 , V_30 ) ;
V_2 -> V_6 = V_118 ;
F_44 ( & V_2 -> V_31 ) ;
V_2 -> V_35 = & V_120 [ F_45 ( V_118 )
-> V_121 ] ;
V_30 -> V_25 . V_122 = & V_118 -> V_25 ;
V_30 -> V_123 = F_45 ( V_118 ) -> V_123 ;
V_30 -> V_35 = & V_124 ;
if ( V_2 -> V_35 -> V_125 ) {
V_30 -> V_126 = V_127 ;
V_30 -> V_128 =
F_7 ( V_127 ) ;
} else {
V_30 -> V_126 = V_129 ;
V_30 -> V_128 = F_7 ( V_129 ) ;
}
V_30 -> V_130 = V_131 ;
F_46 ( V_30 ) ;
V_14 = F_47 ( V_30 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_118 -> V_84 ) {
V_14 = F_48 ( V_118 -> V_84 ,
NULL ,
& F_31 ,
V_132 | V_133 ,
L_14 ,
V_30 ) ;
if ( V_14 )
goto V_134;
}
F_49 ( V_30 ) ;
V_14 = F_40 ( V_2 ) ;
if ( V_14 )
goto V_135;
return 0 ;
V_135:
if ( V_118 -> V_84 )
F_50 ( V_118 -> V_84 , V_30 ) ;
V_134:
F_51 ( V_30 ) ;
return V_14 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_14 ;
F_15 ( & V_2 -> V_31 ) ;
V_14 = F_4 ( V_2 , V_112 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_112 ,
( V_2 -> V_13 [ 0 ] &
~ ( V_136 |
V_137 |
V_138 ) ) ) ;
V_20:
F_16 ( & V_2 -> V_31 ) ;
return V_14 ;
}
static int F_53 ( struct V_117 * V_118 )
{
struct V_29 * V_30 = F_54 ( V_118 ) ;
struct V_1 * V_2 = F_14 ( V_30 ) ;
F_52 ( V_2 ) ;
if ( V_118 -> V_84 )
F_50 ( V_118 -> V_84 , V_30 ) ;
F_51 ( V_30 ) ;
F_55 ( V_30 ) ;
return 0 ;
}
