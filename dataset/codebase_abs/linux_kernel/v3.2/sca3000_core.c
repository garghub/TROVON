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
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_36 , 1 ) ;
if ( V_16 < 0 )
goto V_22;
V_8 += sprintf ( V_35 + V_8 ,
L_3 ,
V_2 -> V_15 [ 0 ] & V_37 ,
V_2 -> V_15 [ 0 ] & V_38 ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3
F_20 ( struct V_26 * V_27 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_8 = 0 ;
V_8 += sprintf ( V_35 + V_8 , L_4 ) ;
switch ( V_2 -> V_39 -> V_40 ) {
case V_41 :
V_8 += sprintf ( V_35 + V_8 , L_5 ) ;
break;
case V_42 :
V_8 += sprintf ( V_35 + V_8 , L_6 ) ;
break;
}
switch ( V_2 -> V_39 -> V_43 ) {
case V_44 :
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
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_8 = 0 , V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_22;
V_2 -> V_15 [ 0 ] &= 0x03 ;
switch ( V_2 -> V_15 [ 0 ] ) {
case V_46 :
V_8 += sprintf ( V_35 + V_8 , L_9 ) ;
break;
case V_47 :
V_8 += sprintf ( V_35 + V_8 , L_10 ) ;
break;
case V_48 :
switch ( V_2 -> V_39 -> V_40 ) {
case V_41 :
V_8 += sprintf ( V_35 + V_8 , L_11 ) ;
break;
case V_42 :
V_8 += sprintf ( V_35 + V_8 , L_12 ) ;
break;
}
break;
case V_49 :
switch ( V_2 -> V_39 -> V_43 ) {
case V_44 :
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
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
int V_50 = 0x03 ;
long V_4 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_23 ( V_35 , 10 , & V_4 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_22;
V_2 -> V_15 [ 0 ] &= ~ V_50 ;
V_2 -> V_15 [ 0 ] |= ( V_4 & V_50 ) ;
V_16 = F_1 ( V_2 , V_45 , V_2 -> V_15 [ 0 ] ) ;
if ( V_16 )
goto V_22;
F_18 ( & V_2 -> V_30 ) ;
return V_8 ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int F_24 ( struct V_28 * V_29 ,
struct V_51 const * V_52 ,
int * V_4 ,
int * V_53 ,
long V_50 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
T_1 V_3 ;
switch ( V_50 ) {
case 0 :
F_16 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_54 ) {
F_18 ( & V_2 -> V_30 ) ;
return - V_55 ;
}
V_3 = V_56 [ V_52 -> V_3 ] [ 0 ] ;
V_16 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_16 < 0 ) {
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
* V_4 = ( F_25 ( ( V_57 * ) V_2 -> V_15 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
F_18 ( & V_2 -> V_30 ) ;
return V_58 ;
case ( 1 << V_59 ) :
* V_4 = 0 ;
if ( V_52 -> type == V_60 )
* V_53 = V_2 -> V_39 -> V_61 ;
else
* V_53 = 555556 ;
return V_62 ;
default:
return - V_63 ;
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
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_22;
switch ( V_4 & 0x03 ) {
case V_46 :
V_8 += sprintf ( V_35 + V_8 , L_14 ,
V_2 -> V_39 -> V_64 ,
V_2 -> V_39 -> V_64 / 2 ,
V_2 -> V_39 -> V_64 / 4 ) ;
break;
case V_48 :
V_8 += sprintf ( V_35 + V_8 , L_14 ,
V_2 -> V_39 -> V_65 ,
V_2 -> V_39 -> V_65 / 2 ,
V_2 -> V_39 -> V_65 / 4 ) ;
break;
case V_49 :
V_8 += sprintf ( V_35 + V_8 , L_14 ,
V_2 -> V_39 -> V_66 ,
V_2 -> V_39 -> V_66 / 2 ,
V_2 -> V_39 -> V_66 / 4 ) ;
break;
}
return V_8 ;
V_22:
return V_16 ;
}
static inline int F_27 ( struct V_1 * V_2 ,
const struct V_67 * V_39 ,
int * V_68 )
{
int V_16 ;
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_22;
switch ( 0x03 & V_2 -> V_15 [ 0 ] ) {
case V_46 :
* V_68 = V_39 -> V_64 ;
break;
case V_48 :
* V_68 = V_39 -> V_65 ;
break;
case V_49 :
* V_68 = V_39 -> V_66 ;
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
int V_16 , V_8 = 0 , V_68 = 0 , V_4 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_27 ( V_2 , V_2 -> V_39 , & V_68 ) ;
if ( V_16 )
goto V_69;
V_16 = F_12 ( V_2 , V_70 ) ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_22;
V_4 = V_16 ;
if ( V_68 > 0 )
switch ( V_4 & 0x03 ) {
case 0x00 :
case 0x03 :
V_8 = sprintf ( V_35 , L_15 , V_68 ) ;
break;
case 0x01 :
V_8 = sprintf ( V_35 , L_15 , V_68 / 2 ) ;
break;
case 0x02 :
V_8 = sprintf ( V_35 , L_15 , V_68 / 4 ) ;
break;
}
return V_8 ;
V_69:
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
int V_16 , V_68 = 0 ;
int V_71 ;
long V_4 ;
V_16 = F_23 ( V_35 , 10 , & V_4 ) ;
if ( V_16 )
return V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_27 ( V_2 , V_2 -> V_39 , & V_68 ) ;
if ( V_16 )
goto V_72;
V_16 = F_12 ( V_2 , V_70 ) ;
if ( V_16 < 0 )
goto V_72;
V_71 = V_16 ;
V_71 &= ~ 0x03 ;
if ( V_4 == V_68 / 2 ) {
V_71 |= V_73 ;
} else if ( V_4 == V_68 / 4 ) {
V_71 |= V_74 ;
} else if ( V_4 != V_68 ) {
V_16 = - V_63 ;
goto V_72;
}
V_16 = F_11 ( V_2 , V_70 ,
V_71 ) ;
V_72:
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
V_16 = F_4 ( V_2 , V_75 , 2 ) ;
if ( V_16 < 0 )
goto V_22;
V_4 = ( ( V_2 -> V_15 [ 0 ] & 0x3F ) << 3 ) | ( ( V_2 -> V_15 [ 1 ] & 0xE0 ) >> 5 ) ;
return sprintf ( V_35 , L_15 , V_4 ) ;
V_22:
return V_16 ;
}
static int F_31 ( struct V_28 * V_29 ,
T_5 V_76 ,
int * V_4 )
{
int V_16 , V_77 ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_78 = F_32 ( V_76 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_12 ( V_2 , V_56 [ V_78 ] [ 1 ] ) ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_4 = 0 ;
if ( V_78 == 1 )
F_33 ( V_77 , ( unsigned long * ) & V_16 ,
F_34 ( V_2 -> V_39 -> V_79 ) )
* V_4 += V_2 -> V_39 -> V_79 [ V_77 ] ;
else
F_33 ( V_77 , ( unsigned long * ) & V_16 ,
F_34 ( V_2 -> V_39 -> V_80 ) )
* V_4 += V_2 -> V_39 -> V_80 [ V_77 ] ;
return 0 ;
}
static int F_35 ( struct V_28 * V_29 ,
T_5 V_76 ,
int V_4 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_78 = F_32 ( V_76 ) ;
int V_16 ;
int V_77 ;
T_1 V_81 = 0 ;
if ( V_78 == 1 ) {
V_77 = F_34 ( V_2 -> V_39 -> V_79 ) ;
while ( V_77 > 0 )
if ( V_4 >= V_2 -> V_39 -> V_79 [ -- V_77 ] ) {
V_81 |= ( 1 << V_77 ) ;
V_4 -= V_2 -> V_39 -> V_79 [ V_77 ] ;
}
} else {
V_77 = F_34 ( V_2 -> V_39 -> V_80 ) ;
while ( V_77 > 0 )
if ( V_4 >= V_2 -> V_39 -> V_80 [ -- V_77 ] ) {
V_81 |= ( 1 << V_77 ) ;
V_4 -= V_2 -> V_39 -> V_80 [ V_77 ] ;
}
}
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_11 ( V_2 , V_56 [ V_78 ] [ 1 ] , V_81 ) ;
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static T_6 F_36 ( int V_82 , void * V_83 )
{
struct V_28 * V_29 = V_83 ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 , V_4 ;
T_7 V_84 = F_37 () ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_85 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 )
goto V_86;
F_38 ( V_4 , V_29 -> V_87 ) ;
if ( V_4 & V_88 )
F_39 ( V_29 ,
F_40 ( V_60 ,
0 ,
V_89 ,
V_90 ,
V_91 ) ,
V_84 ) ;
if ( V_4 & V_92 )
F_39 ( V_29 ,
F_40 ( V_60 ,
0 ,
V_93 ,
V_90 ,
V_94 ) ,
V_84 ) ;
if ( V_4 & V_95 )
F_39 ( V_29 ,
F_40 ( V_60 ,
0 ,
V_96 ,
V_90 ,
V_94 ) ,
V_84 ) ;
if ( V_4 & V_97 )
F_39 ( V_29 ,
F_40 ( V_60 ,
0 ,
V_98 ,
V_90 ,
V_94 ) ,
V_84 ) ;
V_86:
return V_99 ;
}
static int F_41 ( struct V_28 * V_29 ,
T_5 V_76 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
T_1 V_100 = 0x03 ;
int V_78 = F_32 ( V_76 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_22;
if ( ( V_2 -> V_15 [ 0 ] & V_100 ) != V_47 )
V_16 = 0 ;
else {
V_16 = F_12 ( V_2 , V_101 ) ;
if ( V_16 < 0 )
goto V_22;
V_16 = ! ! ( V_16 & V_56 [ V_78 ] [ 2 ] ) ;
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
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_18 ( & V_2 -> V_30 ) ;
if ( V_16 < 0 )
return V_16 ;
V_8 = sprintf ( V_35 , L_15 ,
! ! ( V_4 & V_102 ) ) ;
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
T_1 V_100 = V_102 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_23 ( V_35 , 10 , & V_4 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_22;
if ( V_4 && ! ( V_2 -> V_15 [ 0 ] & V_100 ) )
V_16 = F_1 ( V_2 , V_45 ,
( V_2 -> V_15 [ 0 ] | V_102 ) ) ;
else if ( ! V_4 && ( V_2 -> V_15 [ 0 ] & V_100 ) )
V_16 = F_1 ( V_2 , V_45 ,
( V_2 -> V_15 [ 0 ] & ~ V_100 ) ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ? V_16 : V_8 ;
}
static int F_44 ( struct V_28 * V_29 ,
T_5 V_76 ,
int V_103 )
{
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 , V_71 ;
T_1 V_100 = 0x03 ;
int V_78 = F_32 ( V_76 ) ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_12 ( V_2 , V_101 ) ;
if ( V_16 < 0 )
goto V_104;
V_71 = V_16 ;
if ( V_103 && ! ( V_71 & V_56 [ V_78 ] [ 2 ] ) ) {
V_16 = F_11 ( V_2 ,
V_101 ,
V_71 |
V_56 [ V_78 ] [ 2 ] ) ;
if ( V_16 )
goto V_104;
V_2 -> V_54 ++ ;
} else if ( ! V_103 && ( V_71 & V_56 [ V_78 ] [ 2 ] ) ) {
V_16 = F_11 ( V_2 ,
V_101 ,
V_71 &
~ ( V_56 [ V_78 ] [ 2 ] ) ) ;
if ( V_16 )
goto V_104;
V_2 -> V_54 -- ;
}
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_104;
if ( ( V_2 -> V_54 )
&& ( ( V_2 -> V_15 [ 0 ] & V_100 ) != V_47 ) )
V_16 = F_1 ( V_2 , V_45 ,
( V_2 -> V_15 [ 0 ] & ~ V_100 )
| V_47 ) ;
else if ( ! ( V_2 -> V_54 )
&& ( ( V_2 -> V_15 [ 0 ] & V_100 ) == V_47 ) )
V_16 = F_1 ( V_2 , V_45 ,
( V_2 -> V_15 [ 0 ] & ~ V_100 ) ) ;
V_104:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_85 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_12 ( V_2 , V_101 ) ;
if ( V_16 < 0 )
goto V_22;
V_16 = F_11 ( V_2 , V_101 ,
V_16 & V_105 ) ;
if ( V_16 )
goto V_22;
V_16 = F_12 ( V_2 , V_70 ) ;
V_16 = F_11 ( V_2 , V_70 ,
( V_16 & V_106 )
| V_107
| V_108
| V_109
| V_74 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_110 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 ,
V_110 ,
( V_16 & V_111 )
| V_112 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_45 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_45 ,
( V_2 -> V_15 [ 0 ] & V_113 ) ) ;
V_2 -> V_114 = 11 ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int T_8 F_46 ( struct V_115 * V_116 )
{
int V_16 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_29 = F_47 ( sizeof( * V_2 ) ) ;
if ( V_29 == NULL ) {
V_16 = - V_117 ;
goto V_22;
}
V_2 = F_15 ( V_29 ) ;
F_48 ( V_116 , V_29 ) ;
V_2 -> V_6 = V_116 ;
F_49 ( & V_2 -> V_30 ) ;
V_2 -> V_39 = & V_118 [ F_50 ( V_116 )
-> V_119 ] ;
V_29 -> V_27 . V_120 = & V_116 -> V_27 ;
V_29 -> V_121 = F_50 ( V_116 ) -> V_121 ;
if ( V_2 -> V_39 -> V_122 )
V_29 -> V_39 = & V_123 ;
else {
V_29 -> V_39 = & V_124 ;
V_29 -> V_125 = V_126 ;
V_29 -> V_127 = F_34 ( V_126 ) ;
}
V_29 -> V_128 = V_129 ;
F_51 ( V_29 ) ;
V_16 = F_52 ( V_29 ) ;
if ( V_16 < 0 )
goto V_130;
V_16 = F_53 ( V_29 ,
V_126 ,
F_34 ( V_126 ) ) ;
if ( V_16 < 0 )
goto V_131;
if ( V_29 -> V_87 ) {
F_54 ( V_29 -> V_87 , 0 ) ;
F_54 ( V_29 -> V_87 , 1 ) ;
F_54 ( V_29 -> V_87 , 2 ) ;
}
if ( V_116 -> V_82 ) {
V_16 = F_55 ( V_116 -> V_82 ,
NULL ,
& F_36 ,
V_132 ,
L_16 ,
V_29 ) ;
if ( V_16 )
goto V_133;
}
F_56 ( V_29 ) ;
V_16 = F_45 ( V_2 ) ;
if ( V_16 )
goto V_134;
return 0 ;
V_134:
if ( V_116 -> V_82 )
F_57 ( V_116 -> V_82 , V_29 ) ;
V_133:
F_58 ( V_29 ) ;
V_131:
F_59 ( V_29 ) ;
V_130:
F_60 ( V_29 ) ;
V_22:
return V_16 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_16 ;
F_16 ( & V_2 -> V_30 ) ;
V_16 = F_4 ( V_2 , V_110 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_110 ,
( V_2 -> V_15 [ 0 ] &
~ ( V_135 |
V_136 |
V_137 ) ) ) ;
V_22:
F_18 ( & V_2 -> V_30 ) ;
return V_16 ;
}
static int F_62 ( struct V_115 * V_116 )
{
struct V_28 * V_29 = F_63 ( V_116 ) ;
struct V_1 * V_2 = F_15 ( V_29 ) ;
int V_16 ;
V_16 = F_61 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_116 -> V_82 )
F_57 ( V_116 -> V_82 , V_29 ) ;
F_59 ( V_29 ) ;
F_58 ( V_29 ) ;
F_64 ( V_29 ) ;
F_60 ( V_29 ) ;
return 0 ;
}
static T_9 int F_65 ( void )
{
return F_66 ( & V_138 ) ;
}
static T_10 void F_67 ( void )
{
F_68 ( & V_138 ) ;
}
