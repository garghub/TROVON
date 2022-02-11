static int F_1 ( unsigned char * V_1 , char * V_2 )
{
T_1 V_3 = ( V_1 [ 1 ] & 0x0e ) >> 1 ;
T_1 V_4 = ( V_1 [ 0 ] & 0x3c ) >> 2 ;
T_1 V_5 = ( ( V_1 [ 0 ] & 0x03 ) << 3 ) | ( ( V_1 [ 3 ] & 0xe0 ) >> 5 ) ;
T_1 V_6 = ( ( V_1 [ 3 ] & 0x07 ) << 3 ) | ( ( V_1 [ 2 ] & 0xe0 ) >> 5 ) ;
T_1 V_7 = V_1 [ 2 ] & 0x07 ;
return sprintf ( V_2 , L_1 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
static inline int F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 [ V_13 ] .
V_14 [ 0x0d ] ;
if ( ! V_11 )
return - V_15 ;
F_3 ( V_9 , V_11 , V_16 ) ;
F_4 ( V_9 ) ;
return ( int ) V_11 -> V_17 [ 0 ] -> V_18 [ 0 ] ;
}
static inline void F_5 ( struct V_8 * V_9 , const int V_19 )
{
struct V_10 * V_11 ;
T_1 V_20 [ 4 ] = { 0xe , 0xf , 0x1b , 0x10 } ;
if ( V_19 < 0 || V_19 > 3 )
return;
V_11 = V_9 -> V_12 [ V_13 ] .
V_14 [ V_20 [ V_19 ] ] ;
if ( ! V_11 )
return;
F_3 ( V_9 , V_11 , V_16 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
int V_21 ;
char V_2 [ 20 ] ;
struct V_22 * V_23 = F_7 ( V_9 ) ;
unsigned char * V_24 = F_8 ( 8 , V_25 ) ;
if ( ! V_24 )
goto V_26;
V_21 = F_9 ( V_23 , F_10 ( V_23 , 0 ) ,
V_27 ,
V_28 | V_29 |
V_16 ,
0x30c , 1 , V_24 , 8 ,
V_30 ) ;
if ( V_21 == 8 ) {
V_21 = F_1 ( & V_24 [ 2 ] , V_2 ) ;
F_11 ( V_9 , L_2 ,
V_2 , V_24 [ 2 ] , V_24 [ 3 ] , V_24 [ 4 ] , V_24 [ 5 ] ) ;
}
V_26:
F_12 ( V_24 ) ;
}
static T_2 F_13 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_37 ) ;
}
static T_2 F_16 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_38 ) ;
}
static T_2 F_17 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_39 ) ;
}
static T_2 F_18 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_40 ) ;
}
static T_2 F_19 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_41 *
V_36 -> V_37 /
V_36 -> V_39 ) ;
}
static T_2 F_20 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 , T_3 V_42 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
unsigned long V_43 ;
if ( F_21 ( V_2 , 0 , & V_43 ) )
return - V_15 ;
if ( V_43 > V_36 -> V_37 )
return - V_15 ;
V_36 -> V_41 = V_43 * V_36 -> V_39 /
V_36 -> V_37 ;
return V_42 ;
}
static T_2 F_22 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_44 *
V_36 -> V_38 /
V_36 -> V_40 ) ;
}
static T_2 F_23 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 , T_3 V_42 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
unsigned long V_43 ;
if ( F_21 ( V_2 , 0 , & V_43 ) )
return - V_15 ;
if ( V_43 > V_36 -> V_38 )
return - V_15 ;
V_36 -> V_44 = V_43 * V_36 -> V_40 /
V_36 -> V_38 ;
return V_42 ;
}
static T_2 F_24 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_45 ) ;
}
static T_2 F_25 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 , T_3 V_42 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
unsigned long V_43 ;
if ( F_21 ( V_2 , 0 , & V_43 ) )
return - V_15 ;
if ( V_43 > 0x7f )
return - V_15 ;
V_36 -> V_45 = V_43 ;
return V_42 ;
}
static T_2 F_26 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_46 *
V_36 -> V_37 /
V_36 -> V_39 ) ;
}
static T_2 F_27 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 , T_3 V_42 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
unsigned long V_43 ;
if ( F_21 ( V_2 , 0 , & V_43 ) )
return - V_15 ;
if ( V_43 > V_36 -> V_37 )
return - V_15 ;
V_36 -> V_46 = V_43 * V_36 -> V_39 /
V_36 -> V_37 ;
return V_42 ;
}
static T_2 F_28 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_36 -> V_47 *
V_36 -> V_38 /
V_36 -> V_40 ) ;
}
static T_2 F_29 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 , T_3 V_42 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
unsigned long V_43 ;
if ( F_21 ( V_2 , 0 , & V_43 ) )
return - V_15 ;
if ( V_43 > V_36 -> V_38 )
return - V_15 ;
V_36 -> V_47 = V_43 * V_36 -> V_40 /
V_36 -> V_38 ;
return V_42 ;
}
static T_2 F_30 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , - V_36 -> V_48 ) ;
}
static T_2 F_31 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 , T_3 V_42 )
{
struct V_8 * V_9 = F_14 ( V_32 , struct V_8 , V_32 ) ;
struct V_35 * V_36 = F_15 ( V_9 ) ;
unsigned long V_43 ;
if ( F_21 ( V_2 , 0 , & V_43 ) )
return - V_15 ;
if ( V_43 > 7 )
return - V_15 ;
V_36 -> V_48 = - V_43 ;
return V_42 ;
}
static int F_32 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_51 * V_17 , struct V_52 * V_53 ,
unsigned long * * V_54 , int * V_55 )
{
struct V_35 * V_36 = F_15 ( V_9 ) ;
if ( V_17 -> V_56 )
return 0 ;
switch ( V_53 -> V_57 & V_58 ) {
case V_59 :
switch ( V_53 -> V_57 ) {
case V_60 :
F_33 ( V_50 , V_53 , V_54 , V_55 ,
V_61 , V_62 ) ;
F_34 ( V_50 -> V_63 , V_64 ,
V_17 -> V_65 ,
V_17 -> V_66 , 0 , 0 ) ;
if ( ! V_36 -> V_39 ) {
V_36 -> V_39 =
V_17 -> V_66 -
V_17 -> V_65 ;
V_36 -> V_37 =
V_17 -> V_67 -
V_17 -> V_68 ;
V_36 -> V_46 = V_46 *
V_36 -> V_39 /
V_36 -> V_37 ;
V_36 -> V_41 = V_41 *
V_36 -> V_39 /
V_36 -> V_37 ;
}
return 1 ;
case V_69 :
F_33 ( V_50 , V_53 , V_54 , V_55 ,
V_61 , V_70 ) ;
F_34 ( V_50 -> V_63 , V_71 ,
V_17 -> V_65 ,
V_17 -> V_66 , 0 , 0 ) ;
if ( ! V_36 -> V_40 ) {
V_36 -> V_40 =
V_17 -> V_66 -
V_17 -> V_65 ;
V_36 -> V_38 =
V_17 -> V_67 -
V_17 -> V_68 ;
V_36 -> V_47 = V_47 *
V_36 -> V_40 /
V_36 -> V_38 ;
V_36 -> V_44 = V_44 *
V_36 -> V_40 /
V_36 -> V_38 ;
}
return 1 ;
}
return 0 ;
case V_72 :
switch ( V_53 -> V_57 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
return - 1 ;
case V_77 :
F_33 ( V_50 , V_53 , V_54 , V_55 ,
V_61 , V_78 ) ;
return 1 ;
case V_79 :
F_33 ( V_50 , V_53 , V_54 , V_55 ,
V_61 , V_80 ) ;
F_34 ( V_50 -> V_63 , V_81 ,
0 , 1 , 0 , 0 ) ;
return 1 ;
}
return 0 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_51 * V_17 , struct V_52 * V_53 ,
unsigned long * * V_54 , int * V_55 )
{
if ( V_17 -> V_56 )
return 0 ;
if ( V_53 -> type == V_82 || V_53 -> type == V_83
|| V_53 -> type == V_61 )
F_36 ( V_53 -> V_84 , * V_54 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_57 , struct V_51 * V_17 ,
struct V_52 * V_53 , T_4 V_18 )
{
struct V_35 * V_36 = F_15 ( V_57 ) ;
struct V_85 * V_63 ;
if ( ! ( V_57 -> V_86 & V_87 ) )
goto V_88;
if( ! ( V_17 -> V_89 && V_17 -> V_89 -> V_63 ) )
return - V_15 ;
V_63 = V_17 -> V_89 -> V_63 ;
if ( V_17 -> V_90 == V_91 )
return 0 ;
switch ( V_53 -> V_57 ) {
case 0xff000001 :
V_36 -> V_92 = 1 ;
V_36 -> V_93 = 0 ;
break;
case V_94 :
V_36 -> V_95 = V_18 ;
return 1 ;
case V_96 :
V_36 -> V_97 = V_18 ;
break;
case V_60 :
V_36 -> V_98 = V_18 ;
V_36 -> V_99 = 0 ;
break;
case V_69 :
V_36 -> V_100 = V_18 ;
break;
case V_73 :
V_36 -> V_101 = V_18 ;
break;
case V_77 :
V_36 -> V_102 = V_18 ;
break;
case V_79 :
V_36 -> V_103 = V_18 ;
if ( ! V_36 -> V_92 ) {
F_38 ( V_63 , V_104 ,
V_36 -> V_95 ) ;
F_38 ( V_63 , V_105 ,
V_36 -> V_95 ) ;
F_39 ( V_63 , V_61 , V_64 , V_36 -> V_98 ) ;
F_39 ( V_63 , V_61 , V_71 , V_36 -> V_100 ) ;
}
break;
case 0xff000002 :
if ( V_36 -> V_99 >= 4 )
break;
V_36 -> V_106 [ V_36 -> V_99 ++ ] = V_18 ;
if ( V_36 -> V_99 != 4 )
break;
if ( V_36 -> V_106 [ 2 ] ) {
V_36 -> V_107 = V_48 - 1 ;
V_36 -> V_97 = 0 ;
break;
}
if ( V_36 -> V_106 [ 0 ] ) {
if ( V_36 -> V_102 < V_36 -> V_41 ||
V_36 -> V_103 < V_36 -> V_44 )
V_36 -> V_97 = 0 ;
} else
break;
if ( V_36 -> V_107 > 0 ) {
if ( V_36 -> V_102 >= V_36 -> V_46 &&
V_36 -> V_103 >= V_36 -> V_47 ) {
if ( V_36 -> V_101 )
V_36 -> V_107 = 0 ;
else {
V_36 -> V_107 = 1 ;
break;
}
} else
break;
}
if ( ! V_36 -> V_97 )
break;
if ( V_36 -> V_101 == 0 ) {
V_36 -> V_93 = V_36 -> V_97 ;
F_39 ( V_63 , V_61 , V_64 , V_36 -> V_98 ) ;
F_39 ( V_63 , V_61 , V_71 , V_36 -> V_100 ) ;
}
F_39 ( V_63 , V_61 , V_62 , V_36 -> V_98 ) ;
F_39 ( V_63 , V_61 , V_70 , V_36 -> V_100 ) ;
if ( V_36 -> V_102 > V_36 -> V_103 ) {
F_39 ( V_63 , V_61 ,
V_81 , 1 ) ;
F_39 ( V_63 , V_61 ,
V_78 , V_36 -> V_102 ) ;
F_39 ( V_63 , V_61 ,
V_80 , V_36 -> V_103 ) ;
} else {
F_39 ( V_63 , V_61 ,
V_81 , 0 ) ;
F_39 ( V_63 , V_61 ,
V_78 , V_36 -> V_103 ) ;
F_39 ( V_63 , V_61 ,
V_80 , V_36 -> V_102 ) ;
}
F_40 ( V_17 -> V_89 -> V_63 ) ;
break;
case V_108 :
if ( ! V_36 -> V_92 )
break;
V_36 -> V_92 = 0 ;
if ( V_36 -> V_107 > 0 ) {
if ( V_18 )
V_36 -> V_107 = ( V_36 -> V_107 > V_18 )
? V_36 -> V_107 - V_18
: 0 ;
else
V_36 -> V_107 = V_36 -> V_45 ;
break;
} else {
if ( V_18 && V_36 -> V_107 >=
V_36 -> V_48 )
V_36 -> V_107 = 0 ;
else if ( V_36 -> V_107 <= V_36 -> V_48 )
V_36 -> V_107 =
V_36 -> V_45 ;
else {
V_36 -> V_107 -- ;
break;
}
}
if ( V_36 -> V_93 && V_36 -> V_107 <= 0 ) {
F_38 ( V_63 , V_105 , 1 ) ;
F_38 ( V_63 , V_104 , 1 ) ;
} else {
F_38 ( V_63 , V_105 , 0 ) ;
F_38 ( V_63 , V_104 , 0 ) ;
}
break;
default:
return 0 ;
}
V_88:
if ( ( V_57 -> V_86 & V_109 ) && V_57 -> V_110 )
V_57 -> V_110 ( V_57 , V_17 , V_53 , V_18 ) ;
return 1 ;
}
static int F_41 ( struct V_8 * V_9 , const struct V_111 * V_101 )
{
int V_21 ;
struct V_35 * V_36 ;
struct V_49 * V_89 ;
struct V_85 * V_63 ;
struct V_10 * V_11 ;
if ( V_101 -> V_112 )
V_9 -> V_113 |= V_114
| V_115 ;
V_36 = F_8 ( sizeof( struct V_35 ) , V_25 ) ;
if ( ! V_36 ) {
F_42 ( V_9 , L_4 ) ;
return - V_116 ;
}
V_36 -> V_92 = 0 ;
V_36 -> V_41 = 0 ;
V_36 -> V_44 = 0 ;
V_36 -> V_45 = V_45 ;
V_36 -> V_107 = V_45 ;
V_36 -> V_48 = - V_48 ;
V_36 -> V_39 = 1 ;
V_36 -> V_40 = 1 ;
V_36 -> V_37 = 1 ;
V_36 -> V_38 = 1 ;
F_43 ( V_9 , V_36 ) ;
V_21 = F_44 ( V_9 ) ;
if ( V_21 ) {
F_42 ( V_9 , L_5 ) ;
goto V_26;
}
V_21 = F_45 ( V_9 , V_117 & ~ V_118 ) ;
if ( V_21 ) {
F_42 ( V_9 , L_6 ) ;
goto V_26;
}
F_46 (hidinput, &hdev->inputs, list) {
if ( V_89 -> V_11 -> V_119 < 1 )
continue;
V_63 = V_89 -> V_63 ;
switch ( V_89 -> V_11 -> V_17 [ 0 ] -> V_90 ) {
case V_91 :
V_63 -> V_120 = L_7 ;
break;
case V_121 :
F_47 ( V_122 , V_63 -> V_123 ) ;
F_47 ( V_124 , V_63 -> V_123 ) ;
F_47 ( V_125 , V_63 -> V_123 ) ;
F_48 ( V_105 , V_63 -> V_123 ) ;
V_63 -> V_120 =
( V_89 -> V_11 -> V_17 [ 0 ]
-> V_56 ) ?
L_8 :
L_9 ;
break;
}
}
V_11 = V_9 -> V_12 [ V_13 ] . V_14 [ 0x0a ] ;
if ( V_11 ) {
F_4 ( V_9 ) ;
F_3 ( V_9 , V_11 , V_16 ) ;
if ( F_2 ( V_9 ) >= 4 )
F_5 ( V_9 , 3 ) ;
}
F_6 ( V_9 ) ;
V_21 = F_49 ( & V_9 -> V_32 . V_126 ,
& V_127 ) ;
return 0 ;
V_26:
F_12 ( V_36 ) ;
return V_21 ;
}
static void F_50 ( struct V_8 * V_9 )
{
F_51 ( & V_9 -> V_32 . V_126 ,
& V_127 ) ;
F_52 ( V_9 ) ;
F_12 ( F_15 ( V_9 ) ) ;
}
static int T_5 F_53 ( void )
{
return F_54 ( & V_128 ) ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_128 ) ;
}
