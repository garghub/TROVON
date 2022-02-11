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
switch ( ( T_2 ) V_49 -> V_51 ) {
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
switch ( ( T_2 ) V_49 -> V_51 ) {
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
case V_64 :
case V_65 :
if ( F_33 ( V_47 ) ) {
V_6 = - V_66 ;
goto V_67;
}
V_6 = F_6 ( V_9 , V_68 ) ;
if ( V_6 < 0 )
goto V_67;
V_6 = F_8 ( V_9 , V_69 ) ;
if ( V_6 < 0 )
goto V_67;
V_6 = F_4 ( V_9 -> V_2 ,
V_70 , 2 ,
( T_1 * ) & V_11 ) ;
if ( V_6 < 0 )
goto V_67;
F_22 ( & V_47 -> V_50 ) ;
V_6 = F_34 ( V_11 ) ;
if ( V_6 < 8192 )
* V_18 = V_6 * 1000 / 32 ;
else
* V_18 = ( V_6 - 16384 ) * 1000 / 32 ;
return V_71 ;
}
V_67:
F_22 ( & V_47 -> V_50 ) ;
return V_6 ;
}
static int F_35 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
int V_6 ;
if ( F_36 ( V_47 -> V_72 , V_47 -> V_73 ) )
return - V_33 ;
V_6 = F_37 ( V_47 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_9 , V_74 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_9 , V_75 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 -> V_76 = V_75 ;
return 0 ;
}
static int F_38 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_39 ( & V_9 -> V_77 ,
F_40 ( V_78 ) ) ;
return 0 ;
}
static int F_41 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_42 ( & V_9 -> V_77 ) ;
return F_6 ( V_9 , V_79 ) ;
}
static int F_43 ( struct V_46 * V_47 )
{
V_47 -> V_80 = F_44 ( V_47 ) ;
if ( ! V_47 -> V_80 )
return - V_81 ;
V_47 -> V_82 = & V_83 ;
V_47 -> V_84 |= V_85 ;
return 0 ;
}
static void F_45 ( struct V_86 * V_77 )
{
struct V_8 * V_9 = F_46 ( V_77 ,
struct V_8 , V_77 . V_77 ) ;
struct V_46 * V_47 = F_47 ( V_9 -> V_2 ) ;
struct V_87 * V_88 = V_47 -> V_80 ;
signed short V_45 [ 2 ] ;
unsigned char V_89 ;
F_21 ( & V_47 -> V_50 ) ;
if ( V_9 -> V_76 == V_75 ) {
F_6 ( V_9 , V_90 ) ;
V_9 -> V_76 = V_90 ;
F_39 ( & V_9 -> V_77 , V_9 -> V_91 ) ;
F_22 ( & V_47 -> V_50 ) ;
return;
}
F_4 ( V_9 -> V_2 , V_21 , 1 , & V_89 ) ;
if ( V_89 & V_92 ) {
int V_93 = F_48 ( V_47 -> V_72 ,
V_47 -> V_73 ) ;
F_4 ( V_9 -> V_2 ,
F_49 ( 1 , V_47 -> V_72 ) ?
V_94 : V_95 ,
V_93 * 2 , ( T_1 * ) V_45 ) ;
if ( V_93 == 2 ) {
V_45 [ 0 ] = F_34 ( V_45 [ 0 ] ) ;
V_45 [ 1 ] = F_34 ( V_45 [ 1 ] ) ;
} else {
V_45 [ 0 ] = F_34 ( V_45 [ 0 ] ) ;
}
V_88 -> V_96 -> V_97 ( V_88 , ( T_1 * ) V_45 , F_50 () ) ;
} else {
F_39 ( & V_9 -> V_77 , V_9 -> V_91 ) ;
F_22 ( & V_47 -> V_50 ) ;
return;
}
if ( V_89 & V_98 ) {
F_6 ( V_9 , V_79 ) ;
} else {
F_6 ( V_9 , V_99 ) ;
F_39 ( & V_9 -> V_77 , V_9 -> V_91 ) ;
}
F_22 ( & V_47 -> V_50 ) ;
}
static int T_5 F_51 ( struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
int V_6 , V_102 = 0 ;
struct V_103 * V_104 = V_2 -> V_7 . V_105 ;
struct V_8 * V_9 ;
struct V_46 * V_47 = F_52 ( sizeof( * V_9 ) ) ;
if ( V_47 == NULL )
return - V_81 ;
V_9 = F_19 ( V_47 ) ;
F_53 ( V_2 , V_47 ) ;
V_9 -> V_2 = V_2 ;
if ( ! V_104 )
V_9 -> V_104 = & V_106 ;
else
V_9 -> V_104 = V_104 ;
V_9 -> V_3 = F_54 ( & V_2 -> V_7 , L_9 ) ;
if ( ! F_55 ( V_9 -> V_3 ) ) {
V_6 = F_56 ( V_9 -> V_3 ) ;
if ( V_6 )
goto V_107;
V_102 = F_57 ( V_9 -> V_3 ) ;
}
if ( V_102 )
V_9 -> V_41 = V_102 / 1000 ;
else
V_9 -> V_41 = V_9 -> V_104 -> V_41 ;
if ( V_9 -> V_104 -> V_108 ) {
V_9 -> V_28 = V_9 -> V_104 -> V_108 ;
V_9 -> V_14 = V_109 ;
} else {
V_9 -> V_28 = V_110 ;
V_9 -> V_14 = V_111 ;
}
F_16 ( V_9 ) ;
F_58 ( & V_9 -> V_77 , F_45 ) ;
V_9 -> V_91 = F_40 ( V_112 ) ;
V_47 -> V_7 . V_113 = & V_2 -> V_7 ;
V_47 -> V_114 = & V_115 ;
V_47 -> V_116 = V_101 -> V_116 ;
V_47 -> V_84 = V_117 ;
V_47 -> V_118 = V_119 ;
V_47 -> V_120 = 1 ;
V_6 = F_43 ( V_47 ) ;
if ( V_6 )
goto V_121;
V_6 = F_59 ( V_47 , & V_119 [ 1 ] , 2 ) ;
if ( V_6 )
goto V_122;
F_60 ( V_47 , V_47 -> V_80 , 0 ) ;
F_60 ( V_47 , V_47 -> V_80 , 1 ) ;
V_6 = F_14 ( V_9 ) ;
if ( V_6 )
goto V_123;
V_6 = F_61 ( V_47 ) ;
if ( V_6 )
goto V_123;
return 0 ;
V_123:
F_62 ( V_47 ) ;
V_122:
F_63 ( V_47 -> V_80 ) ;
V_121:
if ( ! F_55 ( V_9 -> V_3 ) )
F_64 ( V_9 -> V_3 ) ;
V_107:
if ( ! F_55 ( V_9 -> V_3 ) )
F_65 ( V_9 -> V_3 ) ;
F_66 ( V_47 ) ;
return V_6 ;
}
static T_6 int F_67 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_47 ( V_2 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_68 ( V_47 ) ;
F_62 ( V_47 ) ;
F_63 ( V_47 -> V_80 ) ;
if ( ! F_55 ( V_9 -> V_3 ) ) {
F_64 ( V_9 -> V_3 ) ;
F_65 ( V_9 -> V_3 ) ;
}
F_66 ( V_47 ) ;
return 0 ;
}
