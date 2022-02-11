static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
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
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
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
unsigned int V_3 , unsigned long V_23 )
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
T_3 V_11 ;
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
V_35 ,
2 , ( T_1 * ) & V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 -> V_36 = 100 ;
V_11 = F_15 ( V_9 -> V_36 ) ;
return F_1 ( V_9 -> V_2 , V_37 , 2 , ( T_1 * ) & V_11 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
int V_38 ;
unsigned int V_39 [ 4 ] = { 1980 , 198 , 383 , 970 } ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ )
V_9 -> V_40 [ V_38 ] = V_39 [ V_38 ] * V_9 -> V_41 / 3300 ;
}
static T_4 F_17 ( struct V_42 * V_7 ,
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
V_6 = F_21 ( V_47 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_4 ( V_9 -> V_2 , V_49 -> V_50 , 3 , & V_11 . V_26 [ 1 ] ) ;
F_22 ( V_47 ) ;
if ( V_6 < 0 )
return V_6 ;
V_24 = F_23 ( V_11 . V_25 ) & 0xFFFFFF ;
V_24 = ( V_27 ) V_24 * ( V_27 ) ( V_9 -> V_28 / 4 ) ;
F_12 ( V_24 , 1 << 27 ) ;
return sprintf ( V_45 , L_3 , ( int ) V_24 ) ;
}
static T_4 F_24 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_5 V_4 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
unsigned long V_18 ;
int V_6 ;
V_6 = F_25 ( V_45 , 10 , & V_18 ) ;
if ( V_6 )
return V_6 ;
if ( V_18 > V_51 )
return - V_33 ;
V_6 = F_21 ( V_47 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_9 , V_49 -> V_50 , V_18 ) ;
F_22 ( V_47 ) ;
return V_6 ? V_6 : V_4 ;
}
static T_4 F_26 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
char * V_45 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
int V_6 = 0 , V_4 = 0 ;
F_27 ( & V_9 -> V_52 ) ;
switch ( ( V_53 ) V_49 -> V_50 ) {
case V_54 :
V_4 = sprintf ( V_45 , L_4 ,
V_9 -> V_40 [ ( V_9 -> V_12 >> 1 ) & 0x3 ] ) ;
break;
case V_55 :
V_4 = sprintf ( V_45 , L_5 , V_9 -> V_40 [ 0 ] ,
V_9 -> V_40 [ 3 ] , V_9 -> V_40 [ 2 ] ,
V_9 -> V_40 [ 1 ] ) ;
break;
case V_56 :
V_4 = sprintf ( V_45 , L_3 , V_9 -> V_34 ) ;
break;
case V_57 :
V_4 = sprintf ( V_45 , L_6 ,
( V_9 -> V_12 & V_58 ) ?
L_7 : L_8 ) ;
break;
case V_59 :
V_4 = sprintf ( V_45 , L_9 ) ;
break;
case V_60 :
V_4 = sprintf ( V_45 , L_3 , V_9 -> V_36 ) ;
break;
default:
V_6 = - V_33 ;
}
F_28 ( & V_9 -> V_52 ) ;
return V_6 ? V_6 : V_4 ;
}
static T_4 F_29 ( struct V_42 * V_7 ,
struct V_43 * V_44 ,
const char * V_45 ,
T_5 V_4 )
{
struct V_46 * V_47 = F_18 ( V_7 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
struct V_48 * V_49 = F_20 ( V_44 ) ;
T_6 V_18 ;
int V_38 , V_6 = 0 ;
T_3 V_11 ;
if ( V_49 -> V_50 != V_57 ) {
V_6 = F_30 ( V_45 , 10 , & V_18 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_21 ( V_47 ) ;
if ( V_6 )
return V_6 ;
F_27 ( & V_9 -> V_52 ) ;
switch ( ( V_53 ) V_49 -> V_50 ) {
case V_54 :
V_6 = - V_33 ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ )
if ( V_18 == V_9 -> V_40 [ V_38 ] ) {
V_9 -> V_12 &= ~ F_31 ( 0x3 ) ;
V_9 -> V_12 |= F_31 ( V_38 ) ;
V_6 = F_6 ( V_9 , 0 ) ;
break;
}
break;
case V_57 :
if ( F_32 ( V_45 , L_7 ) ) {
V_9 -> V_12 |= V_58 ;
} else if ( F_32 ( V_45 , L_8 ) ) {
V_9 -> V_12 &= ~ V_58 ;
} else {
V_6 = - V_33 ;
break;
}
V_6 = F_6 ( V_9 , 0 ) ;
break;
case V_56 :
V_18 = F_33 ( V_18 , ( T_6 ) 0 , ( T_6 ) 0x7FF ) ;
V_9 -> V_34 = V_18 ;
if ( V_18 > 1022 )
V_18 = ( V_18 >> 2 ) | ( 3 << 9 ) ;
else if ( V_18 > 511 )
V_18 = ( V_18 >> 1 ) | ( 1 << 9 ) ;
V_11 = F_15 ( V_18 ) ;
V_6 = F_1 ( V_9 -> V_2 ,
V_35 ,
2 , ( T_1 * ) & V_11 ) ;
break;
case V_60 :
V_18 = F_33 ( V_18 , ( T_6 ) 0 , ( T_6 ) 511 ) ;
V_9 -> V_36 = V_18 ;
V_11 = F_15 ( V_18 ) ;
V_6 = F_1 ( V_9 -> V_2 , V_37 , 2 ,
( T_1 * ) & V_11 ) ;
break;
default:
V_6 = - V_33 ;
}
F_28 ( & V_9 -> V_52 ) ;
F_22 ( V_47 ) ;
return V_6 ? V_6 : V_4 ;
}
static int F_34 ( struct V_46 * V_47 ,
struct V_61 const * V_62 ,
int * V_18 ,
int * V_63 ,
long V_64 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
T_3 V_11 ;
int V_6 ;
switch ( V_64 ) {
case V_65 :
V_6 = F_21 ( V_47 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_9 , V_66 ) ;
if ( V_6 < 0 )
goto V_67;
V_6 = F_8 ( V_9 , V_68 ) ;
if ( V_6 < 0 )
goto V_67;
V_6 = F_4 ( V_9 -> V_2 ,
V_69 ,
2 , ( T_1 * ) & V_11 ) ;
if ( V_6 < 0 )
goto V_67;
F_22 ( V_47 ) ;
* V_18 = F_35 ( F_36 ( V_11 ) , 13 ) ;
return V_70 ;
case V_71 :
* V_18 = 1000 ;
* V_63 = 5 ;
return V_72 ;
}
return - V_33 ;
V_67:
F_22 ( V_47 ) ;
return V_6 ;
}
static int F_37 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
int V_6 ;
if ( F_38 ( V_47 -> V_73 , V_47 -> V_74 ) )
return - V_33 ;
V_6 = F_7 ( V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_9 , V_75 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_9 , V_76 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 -> V_77 = V_76 ;
return 0 ;
}
static int F_39 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_40 ( & V_9 -> V_78 ,
F_41 ( V_79 ) ) ;
return 0 ;
}
static int F_42 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_43 ( & V_9 -> V_78 ) ;
return F_6 ( V_9 , V_80 ) ;
}
static int F_44 ( struct V_46 * V_47 )
{
struct V_81 * V_82 ;
V_82 = F_45 () ;
if ( ! V_82 )
return - V_83 ;
F_46 ( V_47 , V_82 ) ;
V_47 -> V_84 = & V_85 ;
V_47 -> V_86 |= V_87 ;
return 0 ;
}
static void F_47 ( struct V_88 * V_78 )
{
struct V_8 * V_9 = F_48 ( V_78 ,
struct V_8 , V_78 . V_78 ) ;
struct V_46 * V_47 = F_49 ( V_9 -> V_2 ) ;
T_3 V_45 [ 2 ] ;
int V_18 [ 2 ] ;
unsigned char V_89 ;
int V_6 ;
if ( V_9 -> V_77 == V_76 ) {
F_6 ( V_9 , V_90 ) ;
V_9 -> V_77 = V_90 ;
F_40 ( & V_9 -> V_78 , V_9 -> V_91 ) ;
return;
}
V_6 = F_4 ( V_9 -> V_2 , V_21 , 1 , & V_89 ) ;
if ( V_6 )
return;
if ( V_89 & V_92 ) {
int V_93 = F_50 ( V_47 -> V_73 ,
V_47 -> V_74 ) ;
V_6 = F_4 ( V_9 -> V_2 ,
F_51 ( 1 , V_47 -> V_73 ) ?
V_94 : V_95 ,
V_93 * 2 , ( T_1 * ) V_45 ) ;
if ( V_6 )
return;
if ( V_93 == 2 ) {
V_18 [ 0 ] = F_36 ( V_45 [ 0 ] ) ;
V_18 [ 1 ] = F_36 ( V_45 [ 1 ] ) ;
} else {
V_18 [ 0 ] = F_36 ( V_45 [ 0 ] ) ;
}
F_52 ( V_47 , V_18 ) ;
} else {
F_40 ( & V_9 -> V_78 , V_9 -> V_91 ) ;
return;
}
if ( V_89 & V_96 ) {
F_6 ( V_9 , V_80 ) ;
} else {
F_6 ( V_9 , V_97 ) ;
F_40 ( & V_9 -> V_78 , V_9 -> V_91 ) ;
}
}
static int F_53 ( struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
int V_6 , V_100 = 0 ;
struct V_101 * V_102 = F_54 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 ;
struct V_46 * V_47 ;
V_47 = F_55 ( & V_2 -> V_7 , sizeof( * V_9 ) ) ;
if ( ! V_47 )
return - V_83 ;
V_9 = F_19 ( V_47 ) ;
F_56 ( V_2 , V_47 ) ;
V_9 -> V_2 = V_2 ;
F_57 ( & V_9 -> V_52 ) ;
if ( ! V_102 )
V_102 = & V_103 ;
V_9 -> V_3 = F_58 ( & V_2 -> V_7 , L_10 ) ;
if ( F_59 ( V_9 -> V_3 ) )
return F_60 ( V_9 -> V_3 ) ;
V_6 = F_61 ( V_9 -> V_3 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_7 , L_11 ) ;
return V_6 ;
}
V_100 = F_62 ( V_9 -> V_3 ) ;
if ( V_100 )
V_9 -> V_41 = V_100 / 1000 ;
else
V_9 -> V_41 = V_102 -> V_41 ;
if ( V_102 -> V_104 ) {
V_9 -> V_28 = V_102 -> V_104 ;
V_9 -> V_14 = V_105 ;
} else {
V_9 -> V_28 = V_106 ;
V_9 -> V_14 = V_107 ;
}
F_16 ( V_9 ) ;
F_63 ( & V_9 -> V_78 , F_47 ) ;
V_9 -> V_91 = F_41 ( V_108 ) ;
V_47 -> V_7 . V_109 = & V_2 -> V_7 ;
V_47 -> V_110 = & V_111 ;
V_47 -> V_112 = V_99 -> V_112 ;
V_47 -> V_86 = V_113 ;
V_47 -> V_114 = V_115 ;
V_47 -> V_116 = F_64 ( V_115 ) ;
V_6 = F_44 ( V_47 ) ;
if ( V_6 )
goto V_117;
V_6 = F_14 ( V_9 ) ;
if ( V_6 )
goto V_118;
V_6 = F_65 ( V_47 ) ;
if ( V_6 )
goto V_118;
return 0 ;
V_118:
F_66 ( V_47 -> V_82 ) ;
V_117:
F_67 ( V_9 -> V_3 ) ;
return V_6 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_49 ( V_2 ) ;
struct V_8 * V_9 = F_19 ( V_47 ) ;
F_69 ( V_47 ) ;
F_66 ( V_47 -> V_82 ) ;
F_67 ( V_9 -> V_3 ) ;
return 0 ;
}
