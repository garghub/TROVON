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
if ( V_2 -> V_54 ) {
F_17 ( & V_2 -> V_28 ) ;
return - V_55 ;
}
V_3 = V_56 [ V_51 -> V_3 ] [ 0 ] ;
V_14 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_14 < 0 ) {
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
* V_4 = ( F_24 ( ( V_57 * ) V_2 -> V_13 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
F_17 ( & V_2 -> V_28 ) ;
return V_58 ;
case V_59 :
* V_4 = 0 ;
if ( V_51 -> type == V_60 )
* V_52 = V_2 -> V_37 -> V_61 ;
else
* V_52 = 555556 ;
return V_62 ;
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
V_2 -> V_37 -> V_63 ,
V_2 -> V_37 -> V_63 / 2 ,
V_2 -> V_37 -> V_63 / 4 ) ;
break;
case V_46 :
V_8 += sprintf ( V_33 + V_8 , L_14 ,
V_2 -> V_37 -> V_64 ,
V_2 -> V_37 -> V_64 / 2 ,
V_2 -> V_37 -> V_64 / 4 ) ;
break;
case V_47 :
V_8 += sprintf ( V_33 + V_8 , L_14 ,
V_2 -> V_37 -> V_65 ,
V_2 -> V_37 -> V_65 / 2 ,
V_2 -> V_37 -> V_65 / 4 ) ;
break;
}
return V_8 ;
V_20:
return V_14 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
const struct V_66 * V_37 ,
int * V_67 )
{
int V_14 ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
switch ( 0x03 & V_2 -> V_13 [ 0 ] ) {
case V_44 :
* V_67 = V_37 -> V_63 ;
break;
case V_46 :
* V_67 = V_37 -> V_64 ;
break;
case V_47 :
* V_67 = V_37 -> V_65 ;
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
int V_14 , V_8 = 0 , V_67 = 0 , V_4 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_26 ( V_2 , V_2 -> V_37 , & V_67 ) ;
if ( V_14 )
goto V_68;
V_14 = F_11 ( V_2 , V_69 ) ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 )
goto V_20;
V_4 = V_14 ;
if ( V_67 > 0 )
switch ( V_4 & 0x03 ) {
case 0x00 :
case 0x03 :
V_8 = sprintf ( V_33 , L_15 , V_67 ) ;
break;
case 0x01 :
V_8 = sprintf ( V_33 , L_15 , V_67 / 2 ) ;
break;
case 0x02 :
V_8 = sprintf ( V_33 , L_15 , V_67 / 4 ) ;
break;
}
return V_8 ;
V_68:
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
int V_14 , V_67 = 0 ;
int V_70 ;
long V_4 ;
V_14 = F_29 ( V_33 , 10 , & V_4 ) ;
if ( V_14 )
return V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_26 ( V_2 , V_2 -> V_37 , & V_67 ) ;
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
V_14 = - V_49 ;
goto V_71;
}
V_14 = F_10 ( V_2 , V_69 ,
V_70 ) ;
V_71:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ? V_14 : V_8 ;
}
static T_3 F_30 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 ;
int V_4 ;
V_14 = F_4 ( V_2 , V_74 , 2 ) ;
if ( V_14 < 0 )
goto V_20;
V_4 = ( ( V_2 -> V_13 [ 0 ] & 0x3F ) << 3 ) | ( ( V_2 -> V_13 [ 1 ] & 0xE0 ) >> 5 ) ;
return sprintf ( V_33 , L_15 , V_4 ) ;
V_20:
return V_14 ;
}
static int F_31 ( struct V_26 * V_27 ,
T_5 V_75 ,
int * V_4 )
{
int V_14 , V_76 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_77 = F_32 ( V_75 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_11 ( V_2 , V_56 [ V_77 ] [ 1 ] ) ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_4 = 0 ;
if ( V_77 == 1 )
F_33 ( V_76 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_37 -> V_78 ) )
* V_4 += V_2 -> V_37 -> V_78 [ V_76 ] ;
else
F_33 ( V_76 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_37 -> V_79 ) )
* V_4 += V_2 -> V_37 -> V_79 [ V_76 ] ;
return 0 ;
}
static int F_34 ( struct V_26 * V_27 ,
T_5 V_75 ,
int V_4 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_77 = F_32 ( V_75 ) ;
int V_14 ;
int V_76 ;
T_1 V_80 = 0 ;
if ( V_77 == 1 ) {
V_76 = F_7 ( V_2 -> V_37 -> V_78 ) ;
while ( V_76 > 0 )
if ( V_4 >= V_2 -> V_37 -> V_78 [ -- V_76 ] ) {
V_80 |= ( 1 << V_76 ) ;
V_4 -= V_2 -> V_37 -> V_78 [ V_76 ] ;
}
} else {
V_76 = F_7 ( V_2 -> V_37 -> V_79 ) ;
while ( V_76 > 0 )
if ( V_4 >= V_2 -> V_37 -> V_79 [ -- V_76 ] ) {
V_80 |= ( 1 << V_76 ) ;
V_4 -= V_2 -> V_37 -> V_79 [ V_76 ] ;
}
}
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_10 ( V_2 , V_56 [ V_77 ] [ 1 ] , V_80 ) ;
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static T_6 F_35 ( int V_81 , void * V_82 )
{
struct V_26 * V_27 = V_82 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 , V_4 ;
T_7 V_83 = F_36 () ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_84 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_17 ( & V_2 -> V_28 ) ;
if ( V_14 )
goto V_85;
F_37 ( V_4 , V_27 -> V_86 ) ;
if ( V_4 & V_87 )
F_38 ( V_27 ,
F_39 ( V_60 ,
0 ,
V_88 ,
V_89 ,
V_90 ) ,
V_83 ) ;
if ( V_4 & V_91 )
F_38 ( V_27 ,
F_39 ( V_60 ,
0 ,
V_92 ,
V_89 ,
V_93 ) ,
V_83 ) ;
if ( V_4 & V_94 )
F_38 ( V_27 ,
F_39 ( V_60 ,
0 ,
V_95 ,
V_89 ,
V_93 ) ,
V_83 ) ;
if ( V_4 & V_96 )
F_38 ( V_27 ,
F_39 ( V_60 ,
0 ,
V_97 ,
V_89 ,
V_93 ) ,
V_83 ) ;
V_85:
return V_98 ;
}
static int F_40 ( struct V_26 * V_27 ,
T_5 V_75 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 ;
T_1 V_99 = 0x03 ;
int V_77 = F_32 ( V_75 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
if ( ( V_2 -> V_13 [ 0 ] & V_99 ) != V_45 )
V_14 = 0 ;
else {
V_14 = F_11 ( V_2 , V_100 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = ! ! ( V_14 & V_56 [ V_77 ] [ 2 ] ) ;
}
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static T_3 F_41 ( struct V_24 * V_25 ,
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
! ! ( V_4 & V_101 ) ) ;
return V_8 ;
}
static T_3 F_42 ( struct V_24 * V_25 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_4 V_8 )
{
struct V_26 * V_27 = F_13 ( V_25 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
long V_4 ;
int V_14 ;
T_1 V_99 = V_101 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_29 ( V_33 , 10 , & V_4 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
if ( V_4 && ! ( V_2 -> V_13 [ 0 ] & V_99 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] | V_101 ) ) ;
else if ( ! V_4 && ( V_2 -> V_13 [ 0 ] & V_99 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_99 ) ) ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ? V_14 : V_8 ;
}
static int F_43 ( struct V_26 * V_27 ,
T_5 V_75 ,
int V_102 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
int V_14 , V_70 ;
T_1 V_99 = 0x03 ;
int V_77 = F_32 ( V_75 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_11 ( V_2 , V_100 ) ;
if ( V_14 < 0 )
goto V_103;
V_70 = V_14 ;
if ( V_102 && ! ( V_70 & V_56 [ V_77 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_100 ,
V_70 |
V_56 [ V_77 ] [ 2 ] ) ;
if ( V_14 )
goto V_103;
V_2 -> V_54 ++ ;
} else if ( ! V_102 && ( V_70 & V_56 [ V_77 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_100 ,
V_70 &
~ ( V_56 [ V_77 ] [ 2 ] ) ) ;
if ( V_14 )
goto V_103;
V_2 -> V_54 -- ;
}
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_103;
if ( ( V_2 -> V_54 )
&& ( ( V_2 -> V_13 [ 0 ] & V_99 ) != V_45 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_99 )
| V_45 ) ;
else if ( ! ( V_2 -> V_54 )
&& ( ( V_2 -> V_13 [ 0 ] & V_99 ) == V_45 ) )
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_99 ) ) ;
V_103:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_84 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_100 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = F_10 ( V_2 , V_100 ,
V_14 & V_104 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_69 ) ;
V_14 = F_10 ( V_2 , V_69 ,
( V_14 & V_105 )
| V_106
| V_107
| V_108
| V_73 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_109 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 ,
V_109 ,
( V_14 & V_110 )
| V_111 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & V_112 ) ) ;
V_2 -> V_113 = 11 ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_45 ( struct V_114 * V_115 )
{
int V_14 ;
struct V_1 * V_2 ;
struct V_26 * V_27 ;
V_27 = F_46 ( sizeof( * V_2 ) ) ;
if ( V_27 == NULL ) {
V_14 = - V_116 ;
goto V_20;
}
V_2 = F_14 ( V_27 ) ;
F_47 ( V_115 , V_27 ) ;
V_2 -> V_6 = V_115 ;
F_48 ( & V_2 -> V_28 ) ;
V_2 -> V_37 = & V_117 [ F_49 ( V_115 )
-> V_118 ] ;
V_27 -> V_25 . V_119 = & V_115 -> V_25 ;
V_27 -> V_120 = F_49 ( V_115 ) -> V_120 ;
if ( V_2 -> V_37 -> V_121 )
V_27 -> V_37 = & V_122 ;
else {
V_27 -> V_37 = & V_123 ;
V_27 -> V_124 = V_125 ;
V_27 -> V_126 = F_7 ( V_125 ) ;
}
V_27 -> V_127 = V_128 ;
F_50 ( V_27 ) ;
V_14 = F_51 ( V_27 ) ;
if ( V_14 < 0 )
goto V_129;
V_14 = F_52 ( V_27 ,
V_125 ,
F_7 ( V_125 ) ) ;
if ( V_14 < 0 )
goto V_130;
if ( V_27 -> V_86 ) {
F_53 ( V_27 , V_27 -> V_86 , 0 ) ;
F_53 ( V_27 , V_27 -> V_86 , 1 ) ;
F_53 ( V_27 , V_27 -> V_86 , 2 ) ;
}
if ( V_115 -> V_81 ) {
V_14 = F_54 ( V_115 -> V_81 ,
NULL ,
& F_35 ,
V_131 | V_132 ,
L_16 ,
V_27 ) ;
if ( V_14 )
goto V_133;
}
F_55 ( V_27 ) ;
V_14 = F_44 ( V_2 ) ;
if ( V_14 )
goto V_134;
return 0 ;
V_134:
if ( V_115 -> V_81 )
F_56 ( V_115 -> V_81 , V_27 ) ;
V_133:
F_57 ( V_27 ) ;
V_130:
F_58 ( V_27 ) ;
V_129:
F_59 ( V_27 ) ;
V_20:
return V_14 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_14 ;
F_15 ( & V_2 -> V_28 ) ;
V_14 = F_4 ( V_2 , V_109 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_109 ,
( V_2 -> V_13 [ 0 ] &
~ ( V_135 |
V_136 |
V_137 ) ) ) ;
V_20:
F_17 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_61 ( struct V_114 * V_115 )
{
struct V_26 * V_27 = F_62 ( V_115 ) ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
F_60 ( V_2 ) ;
if ( V_115 -> V_81 )
F_56 ( V_115 -> V_81 , V_27 ) ;
F_58 ( V_27 ) ;
F_57 ( V_27 ) ;
F_63 ( V_27 ) ;
F_59 ( V_27 ) ;
return 0 ;
}
