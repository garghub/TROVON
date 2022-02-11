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
struct V_1 * V_2 = V_29 -> V_30 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_17 , 1 ) ;
if ( V_16 < 0 )
goto V_22;
if ( V_2 -> V_15 [ 0 ] & V_32 )
F_16 ( V_27 , L_1 ) ;
if ( V_2 -> V_15 [ 0 ] & V_33 )
F_16 ( V_27 , L_2 ) ;
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static T_3 F_18 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
int V_8 = 0 , V_16 ;
struct V_28 * V_37 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_37 -> V_30 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_38 , 1 ) ;
if ( V_16 < 0 )
goto V_22;
V_8 += sprintf ( V_36 + V_8 ,
L_3 ,
V_2 -> V_15 [ 0 ] & V_39 ,
V_2 -> V_15 [ 0 ] & V_40 ) ;
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3
F_19 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_28 * V_37 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_37 -> V_30 ;
int V_8 = 0 ;
V_8 += sprintf ( V_36 + V_8 , L_4 ) ;
switch ( V_2 -> V_41 -> V_42 ) {
case V_43 :
V_8 += sprintf ( V_36 + V_8 , L_5 ) ;
break;
case V_44 :
V_8 += sprintf ( V_36 + V_8 , L_6 ) ;
break;
}
switch ( V_2 -> V_41 -> V_45 ) {
case V_46 :
V_8 += sprintf ( V_36 + V_8 , L_7 ) ;
break;
}
V_8 += sprintf ( V_36 + V_8 , L_8 ) ;
return V_8 ;
}
static T_3
F_20 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_28 * V_37 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_37 -> V_30 ;
int V_8 = 0 , V_16 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_22;
V_2 -> V_15 [ 0 ] &= 0x03 ;
switch ( V_2 -> V_15 [ 0 ] ) {
case V_48 :
V_8 += sprintf ( V_36 + V_8 , L_9 ) ;
break;
case V_49 :
V_8 += sprintf ( V_36 + V_8 , L_10 ) ;
break;
case V_50 :
switch ( V_2 -> V_41 -> V_42 ) {
case V_43 :
V_8 += sprintf ( V_36 + V_8 , L_11 ) ;
break;
case V_44 :
V_8 += sprintf ( V_36 + V_8 , L_12 ) ;
break;
}
break;
case V_51 :
switch ( V_2 -> V_41 -> V_45 ) {
case V_46 :
V_8 += sprintf ( V_36 + V_8 , L_13 ) ;
break;
}
break;
}
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3
F_21 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
const char * V_36 ,
T_4 V_8 )
{
struct V_28 * V_37 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_37 -> V_30 ;
int V_16 ;
int V_52 = 0x03 ;
long V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_22 ( V_36 , 10 , & V_4 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_22;
V_2 -> V_15 [ 0 ] &= ~ V_52 ;
V_2 -> V_15 [ 0 ] |= ( V_4 & V_52 ) ;
V_16 = F_1 ( V_2 , V_47 , V_2 -> V_15 [ 0 ] ) ;
if ( V_16 )
goto V_22;
F_17 ( & V_2 -> V_31 ) ;
return V_8 ;
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static int F_23 ( struct V_28 * V_29 ,
struct V_53 const * V_54 ,
int * V_4 ,
int * V_55 ,
long V_52 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_16 ;
T_1 V_3 ;
switch ( V_52 ) {
case 0 :
F_15 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_56 ) {
F_17 ( & V_2 -> V_31 ) ;
return - V_57 ;
}
V_3 = V_58 [ V_54 -> V_3 ] [ 0 ] ;
V_16 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_16 < 0 ) {
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
* V_4 = ( F_24 ( ( V_59 * ) V_2 -> V_15 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
F_17 ( & V_2 -> V_31 ) ;
return V_60 ;
case ( 1 << V_61 ) :
* V_4 = 0 ;
if ( V_54 -> type == V_62 )
* V_55 = V_2 -> V_41 -> V_63 ;
else
* V_55 = 555556 ;
return V_64 ;
default:
return - V_65 ;
}
}
static T_3 F_25 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_8 = 0 , V_16 , V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_17 ( & V_2 -> V_31 ) ;
if ( V_16 )
goto V_22;
switch ( V_4 & 0x03 ) {
case V_48 :
V_8 += sprintf ( V_36 + V_8 , L_14 ,
V_2 -> V_41 -> V_66 ,
V_2 -> V_41 -> V_66 / 2 ,
V_2 -> V_41 -> V_66 / 4 ) ;
break;
case V_50 :
V_8 += sprintf ( V_36 + V_8 , L_14 ,
V_2 -> V_41 -> V_67 ,
V_2 -> V_41 -> V_67 / 2 ,
V_2 -> V_41 -> V_67 / 4 ) ;
break;
case V_51 :
V_8 += sprintf ( V_36 + V_8 , L_14 ,
V_2 -> V_41 -> V_68 ,
V_2 -> V_41 -> V_68 / 2 ,
V_2 -> V_41 -> V_68 / 4 ) ;
break;
}
return V_8 ;
V_22:
return V_16 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
const struct V_69 * V_41 ,
int * V_70 )
{
int V_16 ;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_22;
switch ( 0x03 & V_2 -> V_15 [ 0 ] ) {
case V_48 :
* V_70 = V_41 -> V_66 ;
break;
case V_50 :
* V_70 = V_41 -> V_67 ;
break;
case V_51 :
* V_70 = V_41 -> V_68 ;
break;
}
V_22:
return V_16 ;
}
static T_3 F_27 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_16 , V_8 = 0 , V_70 = 0 , V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_26 ( V_2 , V_2 -> V_41 , & V_70 ) ;
if ( V_16 )
goto V_71;
V_16 = F_12 ( V_2 , V_72 ) ;
F_17 ( & V_2 -> V_31 ) ;
if ( V_16 )
goto V_22;
V_4 = V_16 ;
if ( V_70 > 0 )
switch ( V_4 & 0x03 ) {
case 0x00 :
case 0x03 :
V_8 = sprintf ( V_36 , L_15 , V_70 ) ;
break;
case 0x01 :
V_8 = sprintf ( V_36 , L_15 , V_70 / 2 ) ;
break;
case 0x02 :
V_8 = sprintf ( V_36 , L_15 , V_70 / 4 ) ;
break;
}
return V_8 ;
V_71:
F_17 ( & V_2 -> V_31 ) ;
V_22:
return V_16 ;
}
static T_3 F_28 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
const char * V_36 ,
T_4 V_8 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_16 , V_70 = 0 ;
int V_73 ;
long V_4 ;
V_16 = F_22 ( V_36 , 10 , & V_4 ) ;
if ( V_16 )
return V_16 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_26 ( V_2 , V_2 -> V_41 , & V_70 ) ;
if ( V_16 )
goto V_74;
V_16 = F_12 ( V_2 , V_72 ) ;
if ( V_16 < 0 )
goto V_74;
V_73 = V_16 ;
V_73 &= ~ 0x03 ;
if ( V_4 == V_70 / 2 ) {
V_73 |= V_75 ;
} else if ( V_4 == V_70 / 4 ) {
V_73 |= V_76 ;
} else if ( V_4 != V_70 ) {
V_16 = - V_65 ;
goto V_74;
}
V_16 = F_11 ( V_2 , V_72 ,
V_73 ) ;
V_74:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ? V_16 : V_8 ;
}
static T_3 F_29 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_16 ;
int V_4 ;
V_16 = F_4 ( V_2 , V_77 , 2 ) ;
if ( V_16 < 0 )
goto V_22;
V_4 = ( ( V_2 -> V_15 [ 0 ] & 0x3F ) << 3 ) | ( ( V_2 -> V_15 [ 1 ] & 0xE0 ) >> 5 ) ;
return sprintf ( V_36 , L_15 , V_4 ) ;
V_22:
return V_16 ;
}
static int F_30 ( struct V_28 * V_29 ,
int V_78 ,
int * V_4 )
{
int V_16 , V_79 ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_80 = F_31 ( V_78 ) ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_12 ( V_2 , V_58 [ V_80 ] [ 1 ] ) ;
F_17 ( & V_2 -> V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
* V_4 = 0 ;
if ( V_80 == 1 )
F_32 ( V_79 , ( unsigned long * ) & V_16 ,
F_33 ( V_2 -> V_41 -> V_81 ) )
* V_4 += V_2 -> V_41 -> V_81 [ V_79 ] ;
else
F_32 ( V_79 , ( unsigned long * ) & V_16 ,
F_33 ( V_2 -> V_41 -> V_82 ) )
* V_4 += V_2 -> V_41 -> V_82 [ V_79 ] ;
return 0 ;
}
static int F_34 ( struct V_28 * V_29 ,
int V_78 ,
int V_4 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_80 = F_31 ( V_78 ) ;
int V_16 ;
int V_79 ;
T_1 V_83 = 0 ;
if ( V_80 == 1 ) {
V_79 = F_33 ( V_2 -> V_41 -> V_81 ) ;
while ( V_79 > 0 )
if ( V_4 >= V_2 -> V_41 -> V_81 [ -- V_79 ] ) {
V_83 |= ( 1 << V_79 ) ;
V_4 -= V_2 -> V_41 -> V_81 [ V_79 ] ;
}
} else {
V_79 = F_33 ( V_2 -> V_41 -> V_82 ) ;
while ( V_79 > 0 )
if ( V_4 >= V_2 -> V_41 -> V_82 [ -- V_79 ] ) {
V_83 |= ( 1 << V_79 ) ;
V_4 -= V_2 -> V_41 -> V_82 [ V_79 ] ;
}
}
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_11 ( V_2 , V_58 [ V_80 ] [ 1 ] , V_83 ) ;
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static T_5 F_35 ( int V_84 , void * V_85 )
{
struct V_28 * V_29 = V_85 ;
struct V_1 * V_2 ;
int V_16 , V_4 ;
T_6 V_86 = F_36 () ;
V_2 = V_29 -> V_30 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_87 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_17 ( & V_2 -> V_31 ) ;
if ( V_16 )
goto V_88;
F_37 ( V_4 , V_2 -> V_29 -> V_89 ) ;
if ( V_4 & V_90 )
F_38 ( V_2 -> V_29 , 0 ,
F_39 ( V_91 ,
0 ,
V_92 ,
V_93 ,
V_94 ) ,
V_86 ) ;
if ( V_4 & V_95 )
F_38 ( V_2 -> V_29 , 0 ,
F_39 ( V_91 ,
0 ,
V_96 ,
V_93 ,
V_97 ) ,
V_86 ) ;
if ( V_4 & V_98 )
F_38 ( V_2 -> V_29 , 0 ,
F_39 ( V_91 ,
0 ,
V_99 ,
V_93 ,
V_97 ) ,
V_86 ) ;
if ( V_4 & V_100 )
F_38 ( V_2 -> V_29 , 0 ,
F_39 ( V_91 ,
0 ,
V_101 ,
V_93 ,
V_97 ) ,
V_86 ) ;
V_88:
return V_102 ;
}
static int F_40 ( struct V_28 * V_29 ,
int V_78 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_16 ;
T_1 V_103 = 0x03 ;
int V_80 = F_31 ( V_78 ) ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_22;
if ( ( V_2 -> V_15 [ 0 ] & V_103 ) != V_49 )
V_16 = 0 ;
else {
V_16 = F_12 ( V_2 , V_104 ) ;
if ( V_16 < 0 )
goto V_22;
V_16 = ! ! ( V_16 & V_58 [ V_80 ] [ 2 ] ) ;
}
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static T_3 F_41 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
char * V_36 )
{
int V_16 , V_8 ;
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
int V_4 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
V_4 = V_2 -> V_15 [ 0 ] ;
F_17 ( & V_2 -> V_31 ) ;
if ( V_16 < 0 )
return V_16 ;
V_8 = sprintf ( V_36 , L_15 ,
! ! ( V_4 & V_105 ) ) ;
return V_8 ;
}
static T_3 F_42 ( struct V_26 * V_27 ,
struct V_34 * V_35 ,
const char * V_36 ,
T_4 V_8 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_1 * V_2 = V_29 -> V_30 ;
long V_4 ;
int V_16 ;
T_1 V_103 = V_105 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_22 ( V_36 , 10 , & V_4 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_22;
if ( V_4 && ! ( V_2 -> V_15 [ 0 ] & V_103 ) )
V_16 = F_1 ( V_2 , V_47 ,
( V_2 -> V_15 [ 0 ] | V_105 ) ) ;
else if ( ! V_4 && ( V_2 -> V_15 [ 0 ] & V_103 ) )
V_16 = F_1 ( V_2 , V_47 ,
( V_2 -> V_15 [ 0 ] & ~ V_103 ) ) ;
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ? V_16 : V_8 ;
}
static int F_43 ( struct V_28 * V_29 ,
int V_78 ,
int V_106 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
int V_16 , V_73 ;
T_1 V_103 = 0x03 ;
int V_80 = F_31 ( V_78 ) ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_12 ( V_2 , V_104 ) ;
if ( V_16 < 0 )
goto V_107;
V_73 = V_16 ;
if ( V_106 && ! ( V_73 & V_58 [ V_80 ] [ 2 ] ) ) {
V_16 = F_11 ( V_2 ,
V_104 ,
V_73 |
V_58 [ V_80 ] [ 2 ] ) ;
if ( V_16 )
goto V_107;
V_2 -> V_56 ++ ;
} else if ( ! V_106 && ( V_73 & V_58 [ V_80 ] [ 2 ] ) ) {
V_16 = F_11 ( V_2 ,
V_104 ,
V_73 &
~ ( V_58 [ V_80 ] [ 2 ] ) ) ;
if ( V_16 )
goto V_107;
V_2 -> V_56 -- ;
}
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_107;
if ( ( V_2 -> V_56 )
&& ( ( V_2 -> V_15 [ 0 ] & V_103 ) != V_49 ) )
V_16 = F_1 ( V_2 , V_47 ,
( V_2 -> V_15 [ 0 ] & ~ V_103 )
| V_49 ) ;
else if ( ! ( V_2 -> V_56 )
&& ( ( V_2 -> V_15 [ 0 ] & V_103 ) == V_49 ) )
V_16 = F_1 ( V_2 , V_47 ,
( V_2 -> V_15 [ 0 ] & ~ V_103 ) ) ;
V_107:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_16 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_87 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_12 ( V_2 , V_104 ) ;
if ( V_16 < 0 )
goto V_22;
V_16 = F_11 ( V_2 , V_104 ,
V_16 & V_108 ) ;
if ( V_16 )
goto V_22;
V_16 = F_12 ( V_2 , V_72 ) ;
V_16 = F_11 ( V_2 , V_72 ,
( V_16 & V_109 )
| V_110
| V_111
| V_112
| V_76 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_113 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 ,
V_113 ,
( V_16 & V_114 )
| V_115 ) ;
if ( V_16 )
goto V_22;
V_16 = F_4 ( V_2 , V_47 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_47 ,
( V_2 -> V_15 [ 0 ] & V_116 ) ) ;
V_2 -> V_117 = 11 ;
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static int T_7 F_45 ( struct V_118 * V_119 )
{
int V_16 , V_120 = 0 ;
struct V_1 * V_2 ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_121 ) ;
if ( V_2 == NULL ) {
V_16 = - V_122 ;
goto V_22;
}
F_47 ( V_119 , V_2 ) ;
V_2 -> V_6 = V_119 ;
F_48 ( & V_2 -> V_31 ) ;
V_2 -> V_41 = & V_123 [ F_49 ( V_119 )
-> V_124 ] ;
V_2 -> V_29 = F_50 ( 0 ) ;
if ( V_2 -> V_29 == NULL ) {
V_16 = - V_122 ;
goto V_125;
}
V_2 -> V_29 -> V_27 . V_126 = & V_119 -> V_27 ;
V_2 -> V_29 -> V_127 = F_49 ( V_119 ) -> V_127 ;
if ( V_2 -> V_41 -> V_128 )
V_2 -> V_29 -> V_41 = & V_129 ;
else {
V_2 -> V_29 -> V_41 = & V_130 ;
V_2 -> V_29 -> V_131 = V_132 ;
V_2 -> V_29 -> V_133 = F_33 ( V_132 ) ;
}
V_2 -> V_29 -> V_30 = ( void * ) ( V_2 ) ;
V_2 -> V_29 -> V_134 = V_135 ;
F_51 ( V_2 -> V_29 ) ;
V_16 = F_52 ( V_2 -> V_29 ) ;
if ( V_16 < 0 )
goto V_136;
V_120 = 1 ;
V_16 = F_53 ( V_2 -> V_29 -> V_89 , 0 ,
V_132 ,
F_33 ( V_132 ) ) ;
if ( V_16 < 0 )
goto V_137;
if ( V_119 -> V_84 && F_54 ( F_55 ( V_119 -> V_84 ) ) > 0 ) {
V_16 = F_56 ( V_119 -> V_84 ,
NULL ,
& F_35 ,
V_138 ,
L_16 ,
V_2 -> V_29 ) ;
if ( V_16 )
goto V_139;
}
F_57 ( V_2 -> V_29 ) ;
V_16 = F_44 ( V_2 ) ;
if ( V_16 )
goto V_140;
return 0 ;
V_140:
if ( V_119 -> V_84 && F_54 ( F_55 ( V_119 -> V_84 ) ) > 0 )
F_58 ( V_119 -> V_84 , V_2 -> V_29 ) ;
V_139:
F_59 ( V_2 -> V_29 -> V_89 ) ;
V_137:
V_136:
if ( V_120 )
F_60 ( V_2 -> V_29 ) ;
else
F_61 ( V_2 -> V_29 ) ;
V_125:
F_62 ( V_2 ) ;
V_22:
return V_16 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_16 ;
F_15 ( & V_2 -> V_31 ) ;
V_16 = F_4 ( V_2 , V_113 , 1 ) ;
if ( V_16 )
goto V_22;
V_16 = F_1 ( V_2 , V_113 ,
( V_2 -> V_15 [ 0 ] &
~ ( V_141 |
V_142 |
V_143 ) ) ) ;
V_22:
F_17 ( & V_2 -> V_31 ) ;
return V_16 ;
}
static int F_64 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_65 ( V_119 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
int V_16 ;
V_16 = F_63 ( V_2 ) ;
if ( V_16 )
return V_16 ;
if ( V_119 -> V_84 && F_54 ( F_55 ( V_119 -> V_84 ) ) > 0 )
F_58 ( V_119 -> V_84 , V_29 ) ;
F_59 ( V_29 -> V_89 ) ;
F_66 ( V_29 ) ;
F_60 ( V_29 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static T_8 int F_67 ( void )
{
return F_68 ( & V_144 ) ;
}
static T_9 void F_69 ( void )
{
F_70 ( & V_144 ) ;
}
