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
if ( ! V_11 || V_11 -> V_15 < 1 ||
V_11 -> V_16 [ 0 ] -> V_17 < 1 )
return - V_18 ;
F_3 ( V_9 , V_11 , V_19 ) ;
F_4 ( V_9 ) ;
return ( int ) V_11 -> V_16 [ 0 ] -> V_20 [ 0 ] ;
}
static inline void F_5 ( struct V_8 * V_9 , const int V_21 )
{
struct V_10 * V_11 ;
T_1 V_22 [ 4 ] = { 0xe , 0xf , 0x1b , 0x10 } ;
if ( V_21 < 0 || V_21 > 3 )
return;
V_11 = V_9 -> V_12 [ V_13 ] .
V_14 [ V_22 [ V_21 ] ] ;
if ( ! V_11 )
return;
F_3 ( V_9 , V_11 , V_19 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
int V_23 ;
char V_2 [ 20 ] ;
struct V_24 * V_25 = F_7 ( V_9 ) ;
unsigned char * V_26 = F_8 ( 8 , V_27 ) ;
if ( ! V_26 )
goto V_28;
V_23 = F_9 ( V_25 , F_10 ( V_25 , 0 ) ,
V_29 ,
V_30 | V_31 |
V_32 ,
0x30c , 1 , V_26 , 8 ,
V_33 ) ;
if ( V_23 == 8 ) {
V_23 = F_1 ( & V_26 [ 2 ] , V_2 ) ;
F_11 ( V_9 , L_2 ,
V_2 , V_26 [ 2 ] , V_26 [ 3 ] , V_26 [ 4 ] , V_26 [ 5 ] ) ;
}
V_28:
F_12 ( V_26 ) ;
}
static T_2 F_13 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_40 ) ;
}
static T_2 F_16 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_41 ) ;
}
static T_2 F_17 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_42 ) ;
}
static T_2 F_18 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_43 ) ;
}
static T_2 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_44 *
V_39 -> V_40 /
V_39 -> V_42 ) ;
}
static T_2 F_20 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_2 , T_3 V_45 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
unsigned long V_46 ;
if ( F_21 ( V_2 , 0 , & V_46 ) )
return - V_18 ;
if ( V_46 > V_39 -> V_40 )
return - V_18 ;
V_39 -> V_44 = V_46 * V_39 -> V_42 /
V_39 -> V_40 ;
return V_45 ;
}
static T_2 F_22 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_47 *
V_39 -> V_41 /
V_39 -> V_43 ) ;
}
static T_2 F_23 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_2 , T_3 V_45 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
unsigned long V_46 ;
if ( F_21 ( V_2 , 0 , & V_46 ) )
return - V_18 ;
if ( V_46 > V_39 -> V_41 )
return - V_18 ;
V_39 -> V_47 = V_46 * V_39 -> V_43 /
V_39 -> V_41 ;
return V_45 ;
}
static T_2 F_24 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_48 ) ;
}
static T_2 F_25 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_2 , T_3 V_45 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
unsigned long V_46 ;
if ( F_21 ( V_2 , 0 , & V_46 ) )
return - V_18 ;
if ( V_46 > 0x7f )
return - V_18 ;
V_39 -> V_48 = V_46 ;
return V_45 ;
}
static T_2 F_26 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_49 *
V_39 -> V_40 /
V_39 -> V_42 ) ;
}
static T_2 F_27 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_2 , T_3 V_45 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
unsigned long V_46 ;
if ( F_21 ( V_2 , 0 , & V_46 ) )
return - V_18 ;
if ( V_46 > V_39 -> V_40 )
return - V_18 ;
V_39 -> V_49 = V_46 * V_39 -> V_42 /
V_39 -> V_40 ;
return V_45 ;
}
static T_2 F_28 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_39 -> V_50 *
V_39 -> V_41 /
V_39 -> V_43 ) ;
}
static T_2 F_29 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_2 , T_3 V_45 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
unsigned long V_46 ;
if ( F_21 ( V_2 , 0 , & V_46 ) )
return - V_18 ;
if ( V_46 > V_39 -> V_41 )
return - V_18 ;
V_39 -> V_50 = V_46 * V_39 -> V_43 /
V_39 -> V_41 ;
return V_45 ;
}
static T_2 F_30 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , - V_39 -> V_51 ) ;
}
static T_2 F_31 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_2 , T_3 V_45 )
{
struct V_8 * V_9 = F_14 ( V_35 , struct V_8 , V_35 ) ;
struct V_38 * V_39 = F_15 ( V_9 ) ;
unsigned long V_46 ;
if ( F_21 ( V_2 , 0 , & V_46 ) )
return - V_18 ;
if ( V_46 > 7 )
return - V_18 ;
V_39 -> V_51 = - V_46 ;
return V_45 ;
}
static int F_32 ( struct V_8 * V_9 , struct V_52 * V_53 ,
struct V_54 * V_16 , struct V_55 * V_56 ,
unsigned long * * V_57 , int * V_58 )
{
struct V_38 * V_39 = F_15 ( V_9 ) ;
if ( V_16 -> V_59 )
return 0 ;
switch ( V_56 -> V_60 & V_61 ) {
case V_62 :
switch ( V_56 -> V_60 ) {
case V_63 :
F_33 ( V_53 , V_56 , V_57 , V_58 ,
V_64 , V_65 ) ;
F_34 ( V_53 -> V_66 , V_67 ,
V_16 -> V_68 ,
V_16 -> V_69 , 0 , 0 ) ;
if ( ! V_39 -> V_42 ) {
V_39 -> V_42 =
V_16 -> V_69 -
V_16 -> V_68 ;
V_39 -> V_40 =
V_16 -> V_70 -
V_16 -> V_71 ;
V_39 -> V_49 = V_49 *
V_39 -> V_42 /
V_39 -> V_40 ;
V_39 -> V_44 = V_44 *
V_39 -> V_42 /
V_39 -> V_40 ;
}
return 1 ;
case V_72 :
F_33 ( V_53 , V_56 , V_57 , V_58 ,
V_64 , V_73 ) ;
F_34 ( V_53 -> V_66 , V_74 ,
V_16 -> V_68 ,
V_16 -> V_69 , 0 , 0 ) ;
if ( ! V_39 -> V_43 ) {
V_39 -> V_43 =
V_16 -> V_69 -
V_16 -> V_68 ;
V_39 -> V_41 =
V_16 -> V_70 -
V_16 -> V_71 ;
V_39 -> V_50 = V_50 *
V_39 -> V_43 /
V_39 -> V_41 ;
V_39 -> V_47 = V_47 *
V_39 -> V_43 /
V_39 -> V_41 ;
}
return 1 ;
}
return 0 ;
case V_75 :
switch ( V_56 -> V_60 ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return - 1 ;
case V_80 :
F_33 ( V_53 , V_56 , V_57 , V_58 ,
V_64 , V_81 ) ;
return 1 ;
case V_82 :
F_33 ( V_53 , V_56 , V_57 , V_58 ,
V_64 , V_83 ) ;
F_34 ( V_53 -> V_66 , V_84 ,
0 , 1 , 0 , 0 ) ;
return 1 ;
}
return 0 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_9 , struct V_52 * V_53 ,
struct V_54 * V_16 , struct V_55 * V_56 ,
unsigned long * * V_57 , int * V_58 )
{
if ( V_16 -> V_59 )
return 0 ;
if ( V_56 -> type == V_85 || V_56 -> type == V_86
|| V_56 -> type == V_64 )
F_36 ( V_56 -> V_87 , * V_57 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_60 , struct V_54 * V_16 ,
struct V_55 * V_56 , T_4 V_20 )
{
struct V_38 * V_39 = F_15 ( V_60 ) ;
struct V_88 * V_66 ;
if ( ! ( V_60 -> V_89 & V_90 ) )
goto V_91;
if( ! ( V_16 -> V_92 && V_16 -> V_92 -> V_66 ) )
return - V_18 ;
V_66 = V_16 -> V_92 -> V_66 ;
if ( V_16 -> V_93 == V_94 )
return 0 ;
switch ( V_56 -> V_60 ) {
case 0xff000001 :
V_39 -> V_95 = 1 ;
V_39 -> V_96 = 0 ;
break;
case V_97 :
V_39 -> V_98 = V_20 ;
return 1 ;
case V_99 :
V_39 -> V_100 = V_20 ;
break;
case V_63 :
V_39 -> V_101 = V_20 ;
V_39 -> V_102 = 0 ;
break;
case V_72 :
V_39 -> V_103 = V_20 ;
break;
case V_76 :
V_39 -> V_104 = V_20 ;
break;
case V_80 :
V_39 -> V_105 = V_20 ;
break;
case V_82 :
V_39 -> V_106 = V_20 ;
if ( ! V_39 -> V_95 ) {
F_38 ( V_66 , V_107 ,
V_39 -> V_98 ) ;
F_38 ( V_66 , V_108 ,
V_39 -> V_98 ) ;
F_39 ( V_66 , V_64 , V_67 , V_39 -> V_101 ) ;
F_39 ( V_66 , V_64 , V_74 , V_39 -> V_103 ) ;
}
break;
case 0xff000002 :
if ( V_39 -> V_102 >= 4 )
break;
V_39 -> V_109 [ V_39 -> V_102 ++ ] = V_20 ;
if ( V_39 -> V_102 != 4 )
break;
if ( V_39 -> V_109 [ 2 ] ) {
V_39 -> V_110 = V_51 - 1 ;
V_39 -> V_100 = 0 ;
break;
}
if ( V_39 -> V_109 [ 0 ] ) {
if ( V_39 -> V_105 < V_39 -> V_44 ||
V_39 -> V_106 < V_39 -> V_47 )
V_39 -> V_100 = 0 ;
} else
break;
if ( V_39 -> V_110 > 0 ) {
if ( V_39 -> V_105 >= V_39 -> V_49 &&
V_39 -> V_106 >= V_39 -> V_50 ) {
if ( V_39 -> V_104 )
V_39 -> V_110 = 0 ;
else {
V_39 -> V_110 = 1 ;
break;
}
} else
break;
}
if ( ! V_39 -> V_100 )
break;
if ( V_39 -> V_104 == 0 ) {
V_39 -> V_96 = V_39 -> V_100 ;
F_39 ( V_66 , V_64 , V_67 , V_39 -> V_101 ) ;
F_39 ( V_66 , V_64 , V_74 , V_39 -> V_103 ) ;
}
F_39 ( V_66 , V_64 , V_65 , V_39 -> V_101 ) ;
F_39 ( V_66 , V_64 , V_73 , V_39 -> V_103 ) ;
if ( V_39 -> V_105 > V_39 -> V_106 ) {
F_39 ( V_66 , V_64 ,
V_84 , 1 ) ;
F_39 ( V_66 , V_64 ,
V_81 , V_39 -> V_105 ) ;
F_39 ( V_66 , V_64 ,
V_83 , V_39 -> V_106 ) ;
} else {
F_39 ( V_66 , V_64 ,
V_84 , 0 ) ;
F_39 ( V_66 , V_64 ,
V_81 , V_39 -> V_106 ) ;
F_39 ( V_66 , V_64 ,
V_83 , V_39 -> V_105 ) ;
}
F_40 ( V_16 -> V_92 -> V_66 ) ;
break;
case V_111 :
if ( ! V_39 -> V_95 )
break;
V_39 -> V_95 = 0 ;
if ( V_39 -> V_110 > 0 ) {
if ( V_20 )
V_39 -> V_110 = ( V_39 -> V_110 > V_20 )
? V_39 -> V_110 - V_20
: 0 ;
else
V_39 -> V_110 = V_39 -> V_48 ;
break;
} else {
if ( V_20 && V_39 -> V_110 >=
V_39 -> V_51 )
V_39 -> V_110 = 0 ;
else if ( V_39 -> V_110 <= V_39 -> V_51 )
V_39 -> V_110 =
V_39 -> V_48 ;
else {
V_39 -> V_110 -- ;
break;
}
}
if ( V_39 -> V_96 && V_39 -> V_110 <= 0 ) {
F_38 ( V_66 , V_108 , 1 ) ;
F_38 ( V_66 , V_107 , 1 ) ;
} else {
F_38 ( V_66 , V_108 , 0 ) ;
F_38 ( V_66 , V_107 , 0 ) ;
}
break;
default:
return 0 ;
}
V_91:
if ( ( V_60 -> V_89 & V_112 ) && V_60 -> V_113 )
V_60 -> V_113 ( V_60 , V_16 , V_56 , V_20 ) ;
return 1 ;
}
static void F_41 ( struct V_8 * V_60 ,
struct V_52 * V_92 )
{
struct V_88 * V_66 = V_92 -> V_66 ;
if ( V_92 -> V_11 -> V_15 < 1 )
return;
switch ( V_92 -> V_11 -> V_16 [ 0 ] -> V_93 ) {
case V_94 :
V_66 -> V_114 = L_4 ;
break;
case V_115 :
F_42 ( V_116 , V_66 -> V_117 ) ;
F_42 ( V_118 , V_66 -> V_117 ) ;
F_42 ( V_119 , V_66 -> V_117 ) ;
F_43 ( V_108 , V_66 -> V_117 ) ;
V_66 -> V_114 = ( V_92 -> V_11 -> V_16 [ 0 ] -> V_59 ) ?
L_5 :
L_6 ;
break;
}
}
static int F_44 ( struct V_8 * V_9 , const struct V_120 * V_104 )
{
int V_23 ;
struct V_38 * V_39 ;
struct V_10 * V_11 ;
if ( V_104 -> V_121 )
V_9 -> V_122 |= V_123
| V_124 ;
V_39 = F_8 ( sizeof( struct V_38 ) , V_27 ) ;
if ( ! V_39 ) {
F_45 ( V_9 , L_7 ) ;
return - V_125 ;
}
V_39 -> V_95 = 0 ;
V_39 -> V_44 = 0 ;
V_39 -> V_47 = 0 ;
V_39 -> V_48 = V_48 ;
V_39 -> V_110 = V_48 ;
V_39 -> V_51 = - V_51 ;
V_39 -> V_42 = 1 ;
V_39 -> V_43 = 1 ;
V_39 -> V_40 = 1 ;
V_39 -> V_41 = 1 ;
F_46 ( V_9 , V_39 ) ;
V_23 = F_47 ( V_9 ) ;
if ( V_23 ) {
F_45 ( V_9 , L_8 ) ;
goto V_28;
}
V_23 = F_48 ( V_9 , V_126 & ~ V_127 ) ;
if ( V_23 ) {
F_45 ( V_9 , L_9 ) ;
goto V_28;
}
V_11 = V_9 -> V_12 [ V_13 ] . V_14 [ 0x0a ] ;
if ( V_11 ) {
F_4 ( V_9 ) ;
F_3 ( V_9 , V_11 , V_19 ) ;
if ( F_2 ( V_9 ) >= 4 )
F_5 ( V_9 , 3 ) ;
}
F_6 ( V_9 ) ;
V_23 = F_49 ( & V_9 -> V_35 . V_128 ,
& V_129 ) ;
return 0 ;
V_28:
F_12 ( V_39 ) ;
return V_23 ;
}
static void F_50 ( struct V_8 * V_9 )
{
F_51 ( & V_9 -> V_35 . V_128 ,
& V_129 ) ;
F_52 ( V_9 ) ;
F_12 ( F_15 ( V_9 ) ) ;
}
