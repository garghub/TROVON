static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
V_2 -> V_5 [ 0 ] = F_2 ( V_3 ) ;
V_2 -> V_5 [ 1 ] = V_4 ;
return F_3 ( V_2 -> V_6 , V_2 -> V_5 , 2 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_7 ,
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
T_1 V_19 ,
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
return V_2 -> V_13 [ 0 ] ;
V_20:
return V_14 ;
}
static int F_12 ( struct V_24 * V_25 )
{
int V_14 ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_27 , 1 ) ;
if ( V_14 < 0 )
goto V_20;
F_15 ( & V_25 -> V_28 ,
L_1 ,
V_2 -> V_13 [ 0 ] & V_29 ,
V_2 -> V_13 [ 0 ] & V_30 ) ;
V_20:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static T_3
F_17 ( struct V_31 * V_28 ,
struct V_32 * V_33 ,
char * V_34 )
{
struct V_24 * V_25 = F_18 ( V_28 ) ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_8 ;
V_8 = sprintf ( V_34 , L_2 , V_2 -> V_35 -> V_36 ) ;
if ( V_2 -> V_35 -> V_37 )
V_8 += sprintf ( V_34 + V_8 , L_3 ,
V_2 -> V_35 -> V_38 ) ;
if ( V_2 -> V_35 -> V_39 )
V_8 += sprintf ( V_34 + V_8 , L_3 ,
V_2 -> V_35 -> V_40 ) ;
V_8 += sprintf ( V_34 + V_8 , L_4 ) ;
return V_8 ;
}
static inline int F_19 ( struct V_1 * V_2 ,
const struct V_41 * V_35 ,
int * V_42 )
{
int V_14 ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
switch ( V_44 & V_2 -> V_13 [ 0 ] ) {
case V_45 :
* V_42 = V_35 -> V_46 ;
break;
case V_47 :
* V_42 = V_35 -> V_48 ;
break;
case V_49 :
* V_42 = V_35 -> V_50 ;
break;
default:
V_14 = - V_51 ;
}
V_20:
return V_14 ;
}
static int F_20 ( struct V_1 * V_2 , int * V_4 )
{
int V_14 ;
V_14 = F_19 ( V_2 , V_2 -> V_35 , V_4 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_11 ( V_2 , V_52 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( * V_4 > 0 ) {
V_14 &= V_53 ;
switch ( V_14 ) {
case V_54 :
* V_4 /= 2 ;
break;
case V_55 :
* V_4 /= 4 ;
break;
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_4 )
{
int V_14 , V_42 , V_56 ;
V_14 = F_19 ( V_2 , V_2 -> V_35 , & V_42 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_11 ( V_2 , V_52 ) ;
if ( V_14 < 0 )
return V_14 ;
V_56 = V_14 & ~ V_53 ;
if ( V_4 == V_42 / 2 )
V_56 |= V_54 ;
if ( V_4 == V_42 / 4 )
V_56 |= V_55 ;
else if ( V_4 != V_42 )
return - V_51 ;
return F_10 ( V_2 , V_52 ,
V_56 ) ;
}
static int F_22 ( struct V_1 * V_2 , int * V_4 )
{
int V_14 ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_13 [ 0 ] &= V_44 ;
switch ( V_2 -> V_13 [ 0 ] ) {
case V_45 :
* V_4 = V_2 -> V_35 -> V_36 ;
return V_57 ;
case V_58 :
return - V_59 ;
case V_47 :
* V_4 = V_2 -> V_35 -> V_38 ;
return V_57 ;
case V_49 :
* V_4 = V_2 -> V_35 -> V_40 ;
return V_57 ;
default:
return - V_51 ;
}
}
static int F_23 ( struct V_1 * V_2 , int V_4 )
{
int V_14 ;
int V_60 ;
if ( V_4 == V_2 -> V_35 -> V_36 )
V_60 = V_45 ;
else if ( V_2 -> V_35 -> V_37 &&
( V_4 == V_2 -> V_35 -> V_38 ) )
V_60 = V_47 ;
else if ( V_2 -> V_35 -> V_39 &&
( V_4 == V_2 -> V_35 -> V_40 ) )
V_60 = V_49 ;
else
return - V_51 ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_13 [ 0 ] &= ~ V_44 ;
V_2 -> V_13 [ 0 ] |= ( V_60 & V_44 ) ;
return F_1 ( V_2 , V_43 , V_2 -> V_13 [ 0 ] ) ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_61 const * V_62 ,
int * V_4 ,
int * V_63 ,
long V_64 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
T_1 V_3 ;
switch ( V_64 ) {
case V_65 :
F_14 ( & V_2 -> V_26 ) ;
if ( V_62 -> type == V_66 ) {
if ( V_2 -> V_67 ) {
F_16 ( & V_2 -> V_26 ) ;
return - V_59 ;
}
V_3 = V_68 [ V_62 -> V_3 ] [ 0 ] ;
V_14 = F_4 ( V_2 , V_3 , 2 ) ;
if ( V_14 < 0 ) {
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
* V_4 = ( F_25 ( ( V_69 * ) V_2 -> V_13 ) >> 3 ) & 0x1FFF ;
* V_4 = ( ( * V_4 ) << ( sizeof( * V_4 ) * 8 - 13 ) ) >>
( sizeof( * V_4 ) * 8 - 13 ) ;
} else {
V_14 = F_4 ( V_2 ,
V_70 ,
2 ) ;
if ( V_14 < 0 ) {
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
* V_4 = ( ( V_2 -> V_13 [ 0 ] & 0x3F ) << 3 ) |
( ( V_2 -> V_13 [ 1 ] & 0xE0 ) >> 5 ) ;
}
F_16 ( & V_2 -> V_26 ) ;
return V_57 ;
case V_71 :
* V_4 = 0 ;
if ( V_62 -> type == V_66 )
* V_63 = V_2 -> V_35 -> V_72 ;
else
* V_63 = 555556 ;
return V_73 ;
case V_74 :
* V_4 = - 214 ;
* V_63 = 600000 ;
return V_73 ;
case V_75 :
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_20 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_26 ) ;
return V_14 ? V_14 : V_57 ;
case V_76 :
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_22 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
default:
return - V_51 ;
}
}
static int F_26 ( struct V_24 * V_25 ,
struct V_61 const * V_62 ,
int V_4 , int V_63 , long V_64 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
switch ( V_64 ) {
case V_75 :
if ( V_63 )
return - V_51 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_21 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
case V_76 :
if ( V_63 )
return - V_51 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_23 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_26 ) ;
default:
return - V_51 ;
}
return V_14 ;
}
static T_3 F_27 ( struct V_31 * V_28 ,
struct V_32 * V_33 ,
char * V_34 )
{
struct V_24 * V_25 = F_18 ( V_28 ) ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_8 = 0 , V_14 , V_4 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_14 )
goto V_20;
switch ( V_4 & V_44 ) {
case V_45 :
V_8 += sprintf ( V_34 + V_8 , L_5 ,
V_2 -> V_35 -> V_46 ,
V_2 -> V_35 -> V_46 / 2 ,
V_2 -> V_35 -> V_46 / 4 ) ;
break;
case V_47 :
V_8 += sprintf ( V_34 + V_8 , L_5 ,
V_2 -> V_35 -> V_48 ,
V_2 -> V_35 -> V_48 / 2 ,
V_2 -> V_35 -> V_48 / 4 ) ;
break;
case V_49 :
V_8 += sprintf ( V_34 + V_8 , L_5 ,
V_2 -> V_35 -> V_50 ,
V_2 -> V_35 -> V_50 / 2 ,
V_2 -> V_35 -> V_50 / 4 ) ;
break;
}
return V_8 ;
V_20:
return V_14 ;
}
static int F_28 ( struct V_24 * V_25 ,
const struct V_61 * V_62 ,
enum V_77 type ,
enum V_78 V_79 ,
enum V_80 V_35 ,
int * V_4 , int * V_63 )
{
int V_14 , V_81 ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
switch ( V_35 ) {
case V_82 :
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_11 ( V_2 ,
V_68 [ V_62 -> V_3 ] [ 1 ] ) ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_4 = 0 ;
if ( V_62 -> V_83 == V_84 )
F_29 ( V_81 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_35 -> V_85 ) )
* V_4 += V_2 -> V_35 -> V_85 [ V_81 ] ;
else
F_29 ( V_81 , ( unsigned long * ) & V_14 ,
F_7 ( V_2 -> V_35 -> V_86 ) )
* V_4 += V_2 -> V_35 -> V_86 [ V_81 ] ;
return V_57 ;
case V_87 :
* V_4 = 0 ;
* V_63 = 226000 ;
return V_73 ;
default:
return - V_51 ;
}
}
static int F_30 ( struct V_24 * V_25 ,
const struct V_61 * V_62 ,
enum V_77 type ,
enum V_78 V_79 ,
enum V_80 V_35 ,
int V_4 , int V_63 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
int V_81 ;
T_1 V_88 = 0 ;
if ( V_62 -> V_83 == V_84 ) {
V_81 = F_7 ( V_2 -> V_35 -> V_85 ) ;
while ( V_81 > 0 )
if ( V_4 >= V_2 -> V_35 -> V_85 [ -- V_81 ] ) {
V_88 |= ( 1 << V_81 ) ;
V_4 -= V_2 -> V_35 -> V_85 [ V_81 ] ;
}
} else {
V_81 = F_7 ( V_2 -> V_35 -> V_86 ) ;
while ( V_81 > 0 )
if ( V_4 >= V_2 -> V_35 -> V_86 [ -- V_81 ] ) {
V_88 |= ( 1 << V_81 ) ;
V_4 -= V_2 -> V_35 -> V_86 [ V_81 ] ;
}
}
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_10 ( V_2 ,
V_68 [ V_62 -> V_3 ] [ 1 ] ,
V_88 ) ;
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_1 V_7 ,
T_1 * V_13 ,
int V_8 )
{
int V_14 ;
struct V_9 V_10 [ 2 ] = {
{
. V_8 = 1 ,
. V_11 = V_2 -> V_5 ,
} , {
. V_8 = V_8 ,
. V_12 = V_13 ,
}
} ;
V_2 -> V_5 [ 0 ] = F_5 ( V_7 ) ;
V_14 = F_6 ( V_2 -> V_6 , V_10 , F_7 ( V_10 ) ) ;
if ( V_14 ) {
F_32 ( F_33 ( & V_2 -> V_6 -> V_28 ) , L_6 ) ;
return V_14 ;
}
return 0 ;
}
static void F_34 ( T_1 V_4 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 , V_81 , V_89 ;
F_14 ( & V_2 -> V_26 ) ;
if ( V_4 & V_90 ) {
V_14 = F_4 ( V_2 , V_91 ,
1 ) ;
if ( V_14 )
goto V_20;
V_89 = V_2 -> V_13 [ 0 ] ;
V_14 = F_31 ( V_2 , V_92 , V_2 -> V_13 ,
V_89 * 2 ) ;
if ( V_14 )
goto V_20;
for ( V_81 = 0 ; V_81 < V_89 / 3 ; V_81 ++ ) {
F_35 ( V_25 , V_2 -> V_13 + V_81 * 3 * 2 ) ;
}
}
V_20:
F_16 ( & V_2 -> V_26 ) ;
}
static T_4 F_36 ( int V_93 , void * V_94 )
{
struct V_24 * V_25 = V_94 ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 , V_4 ;
T_5 V_95 = F_37 ( V_25 ) ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_96 , 1 ) ;
V_4 = V_2 -> V_13 [ 0 ] ;
F_16 ( & V_2 -> V_26 ) ;
if ( V_14 )
goto V_97;
F_34 ( V_4 , V_25 ) ;
if ( V_4 & V_98 )
F_38 ( V_25 ,
F_39 ( V_66 ,
0 ,
V_99 ,
V_100 ,
V_101 ) ,
V_95 ) ;
if ( V_4 & V_102 )
F_38 ( V_25 ,
F_39 ( V_66 ,
0 ,
V_84 ,
V_100 ,
V_103 ) ,
V_95 ) ;
if ( V_4 & V_104 )
F_38 ( V_25 ,
F_39 ( V_66 ,
0 ,
V_105 ,
V_100 ,
V_103 ) ,
V_95 ) ;
if ( V_4 & V_106 )
F_38 ( V_25 ,
F_39 ( V_66 ,
0 ,
V_107 ,
V_100 ,
V_103 ) ,
V_95 ) ;
V_97:
return V_108 ;
}
static int F_40 ( struct V_24 * V_25 ,
const struct V_61 * V_62 ,
enum V_77 type ,
enum V_78 V_79 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
switch ( V_62 -> V_83 ) {
case V_99 :
V_14 = ! ! ( V_2 -> V_13 [ 0 ] & V_109 ) ;
break;
case V_105 :
case V_84 :
case V_107 :
if ( ( V_2 -> V_13 [ 0 ] & V_44 )
!= V_58 ) {
V_14 = 0 ;
} else {
V_14 = F_11 ( V_2 ,
V_110 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = ! ! ( V_14 & V_68 [ V_62 -> V_3 ] [ 2 ] ) ;
}
break;
default:
V_14 = - V_51 ;
}
V_20:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_41 ( struct V_24 * V_25 , int V_111 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
return V_14 ;
if ( V_111 && ! ( V_2 -> V_13 [ 0 ] & V_109 ) )
return F_1 ( V_2 , V_43 ,
V_2 -> V_13 [ 0 ] | V_109 ) ;
else if ( ! V_111 && ( V_2 -> V_13 [ 0 ] & V_109 ) )
return F_1 ( V_2 , V_43 ,
V_2 -> V_13 [ 0 ] & ~ V_109 ) ;
else
return 0 ;
}
static int F_42 ( struct V_24 * V_25 , int V_112 ,
int V_111 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 , V_56 ;
V_14 = F_11 ( V_2 , V_110 ) ;
if ( V_14 < 0 )
return V_14 ;
V_56 = V_14 ;
if ( V_111 && ! ( V_56 & V_68 [ V_112 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_110 ,
V_56 |
V_68 [ V_112 ] [ 2 ] ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_67 ++ ;
} else if ( ! V_111 && ( V_56 & V_68 [ V_112 ] [ 2 ] ) ) {
V_14 = F_10 ( V_2 ,
V_110 ,
V_56 &
~ ( V_68 [ V_112 ] [ 2 ] ) ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_67 -- ;
}
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_2 -> V_67 ) &&
( ( V_2 -> V_13 [ 0 ] & V_44 )
!= V_58 ) )
return F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_44 )
| V_58 ) ;
else if ( ! ( V_2 -> V_67 ) &&
( ( V_2 -> V_13 [ 0 ] & V_44 )
== V_58 ) )
return F_1 ( V_2 , V_43 ,
V_2 -> V_13 [ 0 ] & V_44 ) ;
else
return 0 ;
}
static int F_43 ( struct V_24 * V_25 ,
const struct V_61 * V_62 ,
enum V_77 type ,
enum V_78 V_79 ,
int V_111 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
F_14 ( & V_2 -> V_26 ) ;
switch ( V_62 -> V_83 ) {
case V_99 :
V_14 = F_41 ( V_25 , V_111 ) ;
break;
case V_105 :
case V_84 :
case V_107 :
V_14 = F_42 ( V_25 ,
V_62 -> V_3 ,
V_111 ) ;
break;
default:
V_14 = - V_51 ;
break;
}
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_44 ( struct V_24 * V_25 )
{
struct V_113 * V_114 ;
V_114 = F_45 () ;
if ( ! V_114 )
return - V_115 ;
F_46 ( V_25 , V_114 ) ;
V_25 -> V_116 |= V_117 ;
return 0 ;
}
static void F_47 ( struct V_24 * V_25 )
{
F_48 ( V_25 -> V_114 ) ;
}
static inline
int F_49 ( struct V_24 * V_25 , bool V_111 )
{
struct V_1 * V_2 = F_13 ( V_25 ) ;
int V_14 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
if ( V_111 ) {
F_15 ( & V_25 -> V_28 , L_7 ) ;
V_14 = F_1 ( V_2 ,
V_43 ,
( V_2 -> V_13 [ 0 ] | V_118 ) ) ;
} else
V_14 = F_1 ( V_2 ,
V_43 ,
( V_2 -> V_13 [ 0 ] & ~ V_118 ) ) ;
V_20:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_50 ( struct V_24 * V_25 )
{
int V_14 ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_119 , 1 ) ;
if ( V_14 )
goto V_120;
V_14 = F_1 ( V_2 ,
V_119 ,
V_2 -> V_13 [ 0 ] | V_121 ) ;
if ( V_14 )
goto V_120;
F_16 ( & V_2 -> V_26 ) ;
return F_49 ( V_25 , 1 ) ;
V_120:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_51 ( struct V_24 * V_25 )
{
int V_14 ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
V_14 = F_49 ( V_25 , 0 ) ;
if ( V_14 )
return V_14 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_119 , 1 ) ;
if ( V_14 )
goto V_122;
V_14 = F_1 ( V_2 ,
V_119 ,
V_2 -> V_13 [ 0 ] & ~ V_121 ) ;
V_122:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_14 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_96 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_110 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = F_10 ( V_2 , V_110 ,
V_14 & V_123 ) ;
if ( V_14 )
goto V_20;
V_14 = F_11 ( V_2 , V_52 ) ;
if ( V_14 < 0 )
goto V_20;
V_14 = F_10 ( V_2 , V_52 ,
( V_14 & V_124 )
| V_125
| V_126
| V_127
| V_55 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_119 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 ,
V_119 ,
( V_14 & V_128 )
| V_129 ) ;
if ( V_14 )
goto V_20;
V_14 = F_4 ( V_2 , V_43 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_43 ,
( V_2 -> V_13 [ 0 ] & V_130 ) ) ;
V_20:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_53 ( struct V_131 * V_132 )
{
int V_14 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
V_25 = F_54 ( & V_132 -> V_28 , sizeof( * V_2 ) ) ;
if ( ! V_25 )
return - V_115 ;
V_2 = F_13 ( V_25 ) ;
F_55 ( V_132 , V_25 ) ;
V_2 -> V_6 = V_132 ;
F_56 ( & V_2 -> V_26 ) ;
V_2 -> V_35 = & V_133 [ F_57 ( V_132 )
-> V_134 ] ;
V_25 -> V_28 . V_135 = & V_132 -> V_28 ;
V_25 -> V_136 = F_57 ( V_132 ) -> V_136 ;
V_25 -> V_35 = & V_137 ;
if ( V_2 -> V_35 -> V_138 ) {
V_25 -> V_139 = V_140 ;
V_25 -> V_141 =
F_7 ( V_140 ) ;
} else {
V_25 -> V_139 = V_142 ;
V_25 -> V_141 = F_7 ( V_142 ) ;
}
V_25 -> V_116 = V_143 ;
F_44 ( V_25 ) ;
if ( V_132 -> V_93 ) {
V_14 = F_58 ( V_132 -> V_93 ,
NULL ,
& F_36 ,
V_144 | V_145 ,
L_8 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
V_25 -> V_146 = & V_147 ;
V_14 = F_52 ( V_2 ) ;
if ( V_14 )
goto V_148;
V_14 = F_12 ( V_25 ) ;
if ( V_14 )
goto V_148;
return F_59 ( V_25 ) ;
V_148:
if ( V_132 -> V_93 )
F_60 ( V_132 -> V_93 , V_25 ) ;
return V_14 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_14 ;
F_14 ( & V_2 -> V_26 ) ;
V_14 = F_4 ( V_2 , V_119 , 1 ) ;
if ( V_14 )
goto V_20;
V_14 = F_1 ( V_2 , V_119 ,
( V_2 -> V_13 [ 0 ] &
~ ( V_149 |
V_121 |
V_150 ) ) ) ;
V_20:
F_16 ( & V_2 -> V_26 ) ;
return V_14 ;
}
static int F_62 ( struct V_131 * V_132 )
{
struct V_24 * V_25 = F_63 ( V_132 ) ;
struct V_1 * V_2 = F_13 ( V_25 ) ;
F_64 ( V_25 ) ;
F_61 ( V_2 ) ;
if ( V_132 -> V_93 )
F_60 ( V_132 -> V_93 , V_25 ) ;
F_47 ( V_25 ) ;
return 0 ;
}
