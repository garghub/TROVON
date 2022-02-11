static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
int V_6 ;
while ( V_4 -- ) {
V_6 = F_2 ( V_2 , V_3 ++ , * V_5 ++ ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_7 , L_1 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
int V_6 ;
while ( V_4 -- ) {
V_6 = F_5 ( V_2 , V_3 ++ ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_7 , L_2 ) ;
return V_6 ;
}
* V_5 ++ = V_6 ;
}
return 0 ;
}
static int F_6 ( struct V_8 * V_9 , unsigned char V_10 )
{
unsigned char V_11 = V_9 -> V_12 | V_10 ;
return F_1 ( V_9 -> V_2 ,
V_13 , 1 , & V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
unsigned char V_11 = V_9 -> V_14 | V_15 ;
return F_1 ( V_9 -> V_2 ,
V_16 , 1 , & V_11 ) ;
}
static int F_8 ( struct V_8 * V_9 , unsigned char V_17 )
{
unsigned char V_18 , V_19 = V_20 ;
int V_6 ;
while ( V_19 -- ) {
V_6 = F_4 ( V_9 -> V_2 , V_21 , 1 , & V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_18 & V_17 )
return V_18 ;
F_9 () ;
F_10 ( 1 ) ;
}
return - V_22 ;
}
static int F_11 ( struct V_8 * V_9 ,
unsigned V_3 , unsigned long V_23 )
{
unsigned long long V_24 ;
union {
T_2 V_25 ;
T_1 V_26 [ 4 ] ;
} V_11 ;
V_24 = ( V_27 ) V_23 * ( V_27 ) ( 1 << 27 ) ;
F_12 ( V_24 , V_9 -> V_28 / 4 ) ;
switch ( V_3 ) {
case V_29 :
V_9 -> V_30 = V_23 ;
break;
case V_31 :
V_9 -> V_32 = V_23 ;
break;
default:
return - V_33 ;
}
V_11 . V_25 = F_13 ( V_24 ) ;
return F_1 ( V_9 -> V_2 , V_3 , 3 , & V_11 . V_26 [ 1 ] ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
unsigned short V_11 ;
int V_6 ;
V_6 = F_7 ( V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_9 , V_29 , 10000 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_9 , V_31 , 200 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 -> V_34 = 10 ;
V_11 = F_15 ( V_9 -> V_34 ) ;
V_6 = F_1 ( V_9 -> V_2 ,
V_35 , 2 , ( T_1 * ) & V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 -> V_36 = 100 ;
V_11 = F_15 ( V_9 -> V_36 ) ;
return F_1 ( V_9 -> V_2 , V_37 , 2 , ( T_1 * ) & V_11 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
int V_38 ;
unsigned V_39 [ 4 ] = { 1980 , 198 , 383 , 970 } ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ )
V_9 -> V_40 [ V_38 ] = V_39 [ V_38 ] * V_9 -> V_41 / 3300 ;
}
static T_3 F_17 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
int V_6 ;
unsigned long long V_24 ;
union {
T_2 V_25 ;
T_1 V_26 [ 4 ] ;
} V_11 ;
F_21 ( & V_47 -> V_50 ) ;
V_6 = F_4 ( V_9 -> V_2 , V_49 -> V_51 , 3 , & V_11 . V_26 [ 1 ] ) ;
F_22 ( & V_47 -> V_50 ) ;
if ( V_6 < 0 )
return V_6 ;
V_24 = F_23 ( V_11 . V_25 ) & 0xFFFFFF ;
V_24 = ( V_27 ) V_24 * ( V_27 ) ( V_9 -> V_28 / 4 ) ;
F_12 ( V_24 , 1 << 27 ) ;
return sprintf ( V_45 , L_3 , ( int ) V_24 ) ;
}
static T_3 F_24 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_4 V_4 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
long V_18 ;
int V_6 ;
V_6 = F_25 ( V_45 , 10 , & V_18 ) ;
if ( V_6 )
return V_6 ;
if ( V_18 > V_52 )
return - V_33 ;
F_21 ( & V_47 -> V_50 ) ;
V_6 = F_11 ( V_9 , V_49 -> V_51 , V_18 ) ;
F_22 ( & V_47 -> V_50 ) ;
return V_6 ? V_6 : V_4 ;
}
static T_3 F_26 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
int V_6 = 0 , V_4 = 0 ;
F_21 ( & V_47 -> V_50 ) ;
switch ( V_49 -> V_51 ) {
case V_53 :
V_4 = sprintf ( V_45 , L_3 ,
V_9 -> V_40 [ ( V_9 -> V_12 >> 1 ) & 0x3 ] ) ;
break;
case V_54 :
V_4 = sprintf ( V_45 , L_4 , V_9 -> V_40 [ 0 ] ,
V_9 -> V_40 [ 3 ] , V_9 -> V_40 [ 2 ] ,
V_9 -> V_40 [ 1 ] ) ;
break;
case V_55 :
V_4 = sprintf ( V_45 , L_3 , V_9 -> V_34 ) ;
break;
case V_56 :
V_4 = sprintf ( V_45 , L_5 ,
( V_9 -> V_12 & V_57 ) ?
L_6 : L_7 ) ;
break;
case V_58 :
V_4 = sprintf ( V_45 , L_8 ) ;
break;
case V_59 :
V_4 = sprintf ( V_45 , L_3 , V_9 -> V_36 ) ;
break;
default:
V_6 = - V_33 ;
}
F_22 ( & V_47 -> V_50 ) ;
return V_6 ? V_6 : V_4 ;
}
static T_3 F_27 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_4 V_4 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
long V_18 ;
int V_38 , V_6 = 0 ;
unsigned short V_11 ;
if ( V_49 -> V_51 != V_56 ) {
V_6 = F_28 ( V_45 , 10 , & V_18 ) ;
if ( V_6 )
return V_6 ;
}
F_21 ( & V_47 -> V_50 ) ;
switch ( V_49 -> V_51 ) {
case V_53 :
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ )
if ( V_18 == V_9 -> V_40 [ V_38 ] ) {
V_9 -> V_12 &= ~ F_29 ( 0x3 ) ;
V_9 -> V_12 |= F_29 ( V_38 ) ;
V_6 = F_6 ( V_9 , 0 ) ;
break;
}
V_6 = - V_33 ;
break;
case V_56 :
if ( F_30 ( V_45 , L_6 ) ) {
V_9 -> V_12 |= V_57 ;
} else if ( F_30 ( V_45 , L_7 ) ) {
V_9 -> V_12 &= ~ V_57 ;
} else {
V_6 = - V_33 ;
break;
}
V_6 = F_6 ( V_9 , 0 ) ;
break;
case V_55 :
V_18 = F_31 ( V_18 , 0L , 0x7FFL ) ;
V_9 -> V_34 = V_18 ;
if ( V_18 > 511 )
V_18 = ( V_18 >> 1 ) | ( 1 << 9 ) ;
else if ( V_18 > 1022 )
V_18 = ( V_18 >> 2 ) | ( 3 << 9 ) ;
V_11 = F_15 ( V_18 ) ;
V_6 = F_1 ( V_9 -> V_2 ,
V_35 , 2 , ( T_1 * ) & V_11 ) ;
break;
case V_59 :
V_18 = F_31 ( V_18 , 0L , 511L ) ;
V_9 -> V_36 = V_18 ;
V_11 = F_15 ( V_18 ) ;
V_6 = F_1 ( V_9 -> V_2 , V_37 , 2 ,
( T_1 * ) & V_11 ) ;
break;
default:
V_6 = - V_33 ;
}
F_22 ( & V_47 -> V_50 ) ;
return V_6 ? V_6 : V_4 ;
}
static int F_32 ( struct V_46 * V_47 ,
struct V_60 const * V_61 ,
int * V_18 ,
int * V_62 ,
long V_63 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
unsigned short V_11 ;
int V_6 = - V_33 ;
F_21 ( & V_47 -> V_50 ) ;
switch ( V_63 ) {
case 0 :
if ( F_33 ( V_47 ) ) {
V_6 = - V_64 ;
goto V_65;
}
V_6 = F_6 ( V_9 , V_66 ) ;
if ( V_6 < 0 )
goto V_65;
V_6 = F_8 ( V_9 , V_67 ) ;
if ( V_6 < 0 )
goto V_65;
V_6 = F_4 ( V_9 -> V_2 ,
V_68 , 2 ,
( T_1 * ) & V_11 ) ;
if ( V_6 < 0 )
goto V_65;
F_22 ( & V_47 -> V_50 ) ;
V_6 = F_34 ( V_11 ) ;
if ( V_6 < 8192 )
* V_18 = V_6 * 1000 / 32 ;
else
* V_18 = ( V_6 - 16384 ) * 1000 / 32 ;
return V_69 ;
}
V_65:
F_22 ( & V_47 -> V_50 ) ;
return V_6 ;
}
static int F_35 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_70 * V_71 = V_47 -> V_72 ;
T_4 V_73 ;
int V_6 ;
if ( ! V_71 -> V_74 )
return - V_33 ;
V_73 = V_71 -> V_74 *
V_75 [ 1 ] . V_76 . V_77 / 8 ;
if ( V_47 -> V_72 -> V_78 -> V_79 )
V_47 -> V_72 -> V_78 ->
V_79 ( V_47 -> V_72 , V_73 ) ;
V_6 = F_7 ( V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_9 , V_80 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_9 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 -> V_82 = V_81 ;
return 0 ;
}
static int F_36 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_37 ( & V_9 -> V_83 ,
F_38 ( V_84 ) ) ;
return 0 ;
}
static int F_39 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_40 ( & V_9 -> V_83 ) ;
return F_6 ( V_9 , V_85 ) ;
}
static int F_41 ( struct V_46 * V_47 )
{
V_47 -> V_72 = F_42 ( V_47 ) ;
if ( ! V_47 -> V_72 )
return - V_86 ;
V_47 -> V_72 -> V_78 = & V_87 ;
V_47 -> V_72 -> V_88 = & V_89 ;
V_47 -> V_90 |= V_91 ;
return 0 ;
}
static void F_43 ( struct V_92 * V_83 )
{
struct V_8 * V_9 = F_44 ( V_83 ,
struct V_8 , V_83 . V_83 ) ;
struct V_46 * V_47 = F_45 ( V_9 -> V_2 ) ;
struct V_70 * V_71 = V_47 -> V_72 ;
signed short V_45 [ 2 ] ;
unsigned char V_93 ;
F_21 ( & V_47 -> V_50 ) ;
if ( V_9 -> V_82 == V_81 ) {
F_6 ( V_9 , V_94 ) ;
V_9 -> V_82 = V_94 ;
F_37 ( & V_9 -> V_83 , V_9 -> V_95 ) ;
F_22 ( & V_47 -> V_50 ) ;
return;
}
F_4 ( V_9 -> V_2 , V_21 , 1 , & V_93 ) ;
if ( V_93 & V_96 ) {
F_4 ( V_9 -> V_2 ,
F_46 ( 1 , V_71 -> V_97 ) ?
V_98 : V_99 ,
V_71 -> V_74 * 2 , ( T_1 * ) V_45 ) ;
if ( V_71 -> V_74 == 2 ) {
V_45 [ 0 ] = F_34 ( V_45 [ 0 ] ) ;
V_45 [ 1 ] = F_34 ( V_45 [ 1 ] ) ;
} else {
V_45 [ 0 ] = F_34 ( V_45 [ 0 ] ) ;
}
V_71 -> V_78 -> V_100 ( V_71 , ( T_1 * ) V_45 , F_47 () ) ;
} else {
F_37 ( & V_9 -> V_83 , V_9 -> V_95 ) ;
F_22 ( & V_47 -> V_50 ) ;
return;
}
if ( V_93 & V_101 ) {
F_6 ( V_9 , V_85 ) ;
} else {
F_6 ( V_9 , V_102 ) ;
F_37 ( & V_9 -> V_83 , V_9 -> V_95 ) ;
}
F_22 ( & V_47 -> V_50 ) ;
}
static int T_5 F_48 ( struct V_1 * V_2 ,
const struct V_103 * V_104 )
{
int V_6 , V_105 = 0 ;
struct V_106 * V_107 = V_2 -> V_7 . V_108 ;
struct V_8 * V_9 ;
struct V_46 * V_47 = F_49 ( sizeof( * V_9 ) ) ;
if ( V_47 == NULL )
return - V_86 ;
V_9 = F_19 ( V_47 ) ;
F_50 ( V_2 , V_47 ) ;
V_9 -> V_2 = V_2 ;
if ( ! V_107 )
V_9 -> V_107 = & V_109 ;
else
V_9 -> V_107 = V_107 ;
V_9 -> V_3 = F_51 ( & V_2 -> V_7 , L_9 ) ;
if ( ! F_52 ( V_9 -> V_3 ) ) {
V_6 = F_53 ( V_9 -> V_3 ) ;
if ( V_6 )
goto V_110;
V_105 = F_54 ( V_9 -> V_3 ) ;
}
if ( V_105 )
V_9 -> V_41 = V_105 / 1000 ;
else
V_9 -> V_41 = V_9 -> V_107 -> V_41 ;
if ( V_9 -> V_107 -> V_111 ) {
V_9 -> V_28 = V_9 -> V_107 -> V_111 ;
V_9 -> V_14 = V_112 ;
} else {
V_9 -> V_28 = V_113 ;
V_9 -> V_14 = V_114 ;
}
F_16 ( V_9 ) ;
F_55 ( & V_9 -> V_83 , F_43 ) ;
V_9 -> V_95 = F_38 ( V_115 ) ;
V_47 -> V_7 . V_116 = & V_2 -> V_7 ;
V_47 -> V_117 = & V_118 ;
V_47 -> V_119 = V_104 -> V_119 ;
V_47 -> V_90 = V_120 ;
V_47 -> V_121 = V_75 ;
V_47 -> V_122 = 1 ;
V_6 = F_41 ( V_47 ) ;
if ( V_6 )
goto V_123;
V_6 = F_56 ( V_47 , & V_75 [ 1 ] , 2 ) ;
if ( V_6 )
goto V_124;
F_57 ( V_47 -> V_72 , 0 ) ;
F_57 ( V_47 -> V_72 , 1 ) ;
V_6 = F_14 ( V_9 ) ;
if ( V_6 )
goto V_125;
V_6 = F_58 ( V_47 ) ;
if ( V_6 )
goto V_125;
return 0 ;
V_125:
F_59 ( V_47 ) ;
V_124:
F_60 ( V_47 -> V_72 ) ;
V_123:
if ( ! F_52 ( V_9 -> V_3 ) )
F_61 ( V_9 -> V_3 ) ;
V_110:
if ( ! F_52 ( V_9 -> V_3 ) )
F_62 ( V_9 -> V_3 ) ;
F_63 ( V_47 ) ;
return V_6 ;
}
static T_6 int F_64 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_45 ( V_2 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_65 ( V_47 ) ;
F_59 ( V_47 ) ;
F_60 ( V_47 -> V_72 ) ;
if ( ! F_52 ( V_9 -> V_3 ) ) {
F_61 ( V_9 -> V_3 ) ;
F_62 ( V_9 -> V_3 ) ;
}
F_63 ( V_47 ) ;
return 0 ;
}
static T_7 int F_66 ( void )
{
return F_67 ( & V_126 ) ;
}
static T_8 void F_68 ( void )
{
F_69 ( & V_126 ) ;
}
