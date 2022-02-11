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
V_30 ,
0x30c , 1 , V_24 , 8 ,
V_31 ) ;
if ( V_21 == 8 ) {
V_21 = F_1 ( & V_24 [ 2 ] , V_2 ) ;
F_11 ( V_9 , L_2 ,
V_2 , V_24 [ 2 ] , V_24 [ 3 ] , V_24 [ 4 ] , V_24 [ 5 ] ) ;
}
V_26:
F_12 ( V_24 ) ;
}
static T_2 F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_38 ) ;
}
static T_2 F_16 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_39 ) ;
}
static T_2 F_17 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_40 ) ;
}
static T_2 F_18 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_41 ) ;
}
static T_2 F_19 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_42 *
V_37 -> V_38 /
V_37 -> V_40 ) ;
}
static T_2 F_20 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_2 , T_3 V_43 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
unsigned long V_44 ;
if ( F_21 ( V_2 , 0 , & V_44 ) )
return - V_15 ;
if ( V_44 > V_37 -> V_38 )
return - V_15 ;
V_37 -> V_42 = V_44 * V_37 -> V_40 /
V_37 -> V_38 ;
return V_43 ;
}
static T_2 F_22 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_45 *
V_37 -> V_39 /
V_37 -> V_41 ) ;
}
static T_2 F_23 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_2 , T_3 V_43 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
unsigned long V_44 ;
if ( F_21 ( V_2 , 0 , & V_44 ) )
return - V_15 ;
if ( V_44 > V_37 -> V_39 )
return - V_15 ;
V_37 -> V_45 = V_44 * V_37 -> V_41 /
V_37 -> V_39 ;
return V_43 ;
}
static T_2 F_24 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_46 ) ;
}
static T_2 F_25 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_2 , T_3 V_43 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
unsigned long V_44 ;
if ( F_21 ( V_2 , 0 , & V_44 ) )
return - V_15 ;
if ( V_44 > 0x7f )
return - V_15 ;
V_37 -> V_46 = V_44 ;
return V_43 ;
}
static T_2 F_26 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_47 *
V_37 -> V_38 /
V_37 -> V_40 ) ;
}
static T_2 F_27 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_2 , T_3 V_43 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
unsigned long V_44 ;
if ( F_21 ( V_2 , 0 , & V_44 ) )
return - V_15 ;
if ( V_44 > V_37 -> V_38 )
return - V_15 ;
V_37 -> V_47 = V_44 * V_37 -> V_40 /
V_37 -> V_38 ;
return V_43 ;
}
static T_2 F_28 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , V_37 -> V_48 *
V_37 -> V_39 /
V_37 -> V_41 ) ;
}
static T_2 F_29 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_2 , T_3 V_43 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
unsigned long V_44 ;
if ( F_21 ( V_2 , 0 , & V_44 ) )
return - V_15 ;
if ( V_44 > V_37 -> V_39 )
return - V_15 ;
V_37 -> V_48 = V_44 * V_37 -> V_41 /
V_37 -> V_39 ;
return V_43 ;
}
static T_2 F_30 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_2 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
return sprintf ( V_2 , L_3 , - V_37 -> V_49 ) ;
}
static T_2 F_31 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_2 , T_3 V_43 )
{
struct V_8 * V_9 = F_14 ( V_33 , struct V_8 , V_33 ) ;
struct V_36 * V_37 = F_15 ( V_9 ) ;
unsigned long V_44 ;
if ( F_21 ( V_2 , 0 , & V_44 ) )
return - V_15 ;
if ( V_44 > 7 )
return - V_15 ;
V_37 -> V_49 = - V_44 ;
return V_43 ;
}
static int F_32 ( struct V_8 * V_9 , struct V_50 * V_51 ,
struct V_52 * V_17 , struct V_53 * V_54 ,
unsigned long * * V_55 , int * V_56 )
{
struct V_36 * V_37 = F_15 ( V_9 ) ;
if ( V_17 -> V_57 )
return 0 ;
switch ( V_54 -> V_58 & V_59 ) {
case V_60 :
switch ( V_54 -> V_58 ) {
case V_61 :
F_33 ( V_51 , V_54 , V_55 , V_56 ,
V_62 , V_63 ) ;
F_34 ( V_51 -> V_64 , V_65 ,
V_17 -> V_66 ,
V_17 -> V_67 , 0 , 0 ) ;
if ( ! V_37 -> V_40 ) {
V_37 -> V_40 =
V_17 -> V_67 -
V_17 -> V_66 ;
V_37 -> V_38 =
V_17 -> V_68 -
V_17 -> V_69 ;
V_37 -> V_47 = V_47 *
V_37 -> V_40 /
V_37 -> V_38 ;
V_37 -> V_42 = V_42 *
V_37 -> V_40 /
V_37 -> V_38 ;
}
return 1 ;
case V_70 :
F_33 ( V_51 , V_54 , V_55 , V_56 ,
V_62 , V_71 ) ;
F_34 ( V_51 -> V_64 , V_72 ,
V_17 -> V_66 ,
V_17 -> V_67 , 0 , 0 ) ;
if ( ! V_37 -> V_41 ) {
V_37 -> V_41 =
V_17 -> V_67 -
V_17 -> V_66 ;
V_37 -> V_39 =
V_17 -> V_68 -
V_17 -> V_69 ;
V_37 -> V_48 = V_48 *
V_37 -> V_41 /
V_37 -> V_39 ;
V_37 -> V_45 = V_45 *
V_37 -> V_41 /
V_37 -> V_39 ;
}
return 1 ;
}
return 0 ;
case V_73 :
switch ( V_54 -> V_58 ) {
case V_74 :
case V_75 :
case V_76 :
case V_77 :
return - 1 ;
case V_78 :
F_33 ( V_51 , V_54 , V_55 , V_56 ,
V_62 , V_79 ) ;
return 1 ;
case V_80 :
F_33 ( V_51 , V_54 , V_55 , V_56 ,
V_62 , V_81 ) ;
F_34 ( V_51 -> V_64 , V_82 ,
0 , 1 , 0 , 0 ) ;
return 1 ;
}
return 0 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_9 , struct V_50 * V_51 ,
struct V_52 * V_17 , struct V_53 * V_54 ,
unsigned long * * V_55 , int * V_56 )
{
if ( V_17 -> V_57 )
return 0 ;
if ( V_54 -> type == V_83 || V_54 -> type == V_84
|| V_54 -> type == V_62 )
F_36 ( V_54 -> V_85 , * V_55 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_58 , struct V_52 * V_17 ,
struct V_53 * V_54 , T_4 V_18 )
{
struct V_36 * V_37 = F_15 ( V_58 ) ;
struct V_86 * V_64 ;
if ( ! ( V_58 -> V_87 & V_88 ) )
goto V_89;
if( ! ( V_17 -> V_90 && V_17 -> V_90 -> V_64 ) )
return - V_15 ;
V_64 = V_17 -> V_90 -> V_64 ;
if ( V_17 -> V_91 == V_92 )
return 0 ;
switch ( V_54 -> V_58 ) {
case 0xff000001 :
V_37 -> V_93 = 1 ;
V_37 -> V_94 = 0 ;
break;
case V_95 :
V_37 -> V_96 = V_18 ;
return 1 ;
case V_97 :
V_37 -> V_98 = V_18 ;
break;
case V_61 :
V_37 -> V_99 = V_18 ;
V_37 -> V_100 = 0 ;
break;
case V_70 :
V_37 -> V_101 = V_18 ;
break;
case V_74 :
V_37 -> V_102 = V_18 ;
break;
case V_78 :
V_37 -> V_103 = V_18 ;
break;
case V_80 :
V_37 -> V_104 = V_18 ;
if ( ! V_37 -> V_93 ) {
F_38 ( V_64 , V_105 ,
V_37 -> V_96 ) ;
F_38 ( V_64 , V_106 ,
V_37 -> V_96 ) ;
F_39 ( V_64 , V_62 , V_65 , V_37 -> V_99 ) ;
F_39 ( V_64 , V_62 , V_72 , V_37 -> V_101 ) ;
}
break;
case 0xff000002 :
if ( V_37 -> V_100 >= 4 )
break;
V_37 -> V_107 [ V_37 -> V_100 ++ ] = V_18 ;
if ( V_37 -> V_100 != 4 )
break;
if ( V_37 -> V_107 [ 2 ] ) {
V_37 -> V_108 = V_49 - 1 ;
V_37 -> V_98 = 0 ;
break;
}
if ( V_37 -> V_107 [ 0 ] ) {
if ( V_37 -> V_103 < V_37 -> V_42 ||
V_37 -> V_104 < V_37 -> V_45 )
V_37 -> V_98 = 0 ;
} else
break;
if ( V_37 -> V_108 > 0 ) {
if ( V_37 -> V_103 >= V_37 -> V_47 &&
V_37 -> V_104 >= V_37 -> V_48 ) {
if ( V_37 -> V_102 )
V_37 -> V_108 = 0 ;
else {
V_37 -> V_108 = 1 ;
break;
}
} else
break;
}
if ( ! V_37 -> V_98 )
break;
if ( V_37 -> V_102 == 0 ) {
V_37 -> V_94 = V_37 -> V_98 ;
F_39 ( V_64 , V_62 , V_65 , V_37 -> V_99 ) ;
F_39 ( V_64 , V_62 , V_72 , V_37 -> V_101 ) ;
}
F_39 ( V_64 , V_62 , V_63 , V_37 -> V_99 ) ;
F_39 ( V_64 , V_62 , V_71 , V_37 -> V_101 ) ;
if ( V_37 -> V_103 > V_37 -> V_104 ) {
F_39 ( V_64 , V_62 ,
V_82 , 1 ) ;
F_39 ( V_64 , V_62 ,
V_79 , V_37 -> V_103 ) ;
F_39 ( V_64 , V_62 ,
V_81 , V_37 -> V_104 ) ;
} else {
F_39 ( V_64 , V_62 ,
V_82 , 0 ) ;
F_39 ( V_64 , V_62 ,
V_79 , V_37 -> V_104 ) ;
F_39 ( V_64 , V_62 ,
V_81 , V_37 -> V_103 ) ;
}
F_40 ( V_17 -> V_90 -> V_64 ) ;
break;
case V_109 :
if ( ! V_37 -> V_93 )
break;
V_37 -> V_93 = 0 ;
if ( V_37 -> V_108 > 0 ) {
if ( V_18 )
V_37 -> V_108 = ( V_37 -> V_108 > V_18 )
? V_37 -> V_108 - V_18
: 0 ;
else
V_37 -> V_108 = V_37 -> V_46 ;
break;
} else {
if ( V_18 && V_37 -> V_108 >=
V_37 -> V_49 )
V_37 -> V_108 = 0 ;
else if ( V_37 -> V_108 <= V_37 -> V_49 )
V_37 -> V_108 =
V_37 -> V_46 ;
else {
V_37 -> V_108 -- ;
break;
}
}
if ( V_37 -> V_94 && V_37 -> V_108 <= 0 ) {
F_38 ( V_64 , V_106 , 1 ) ;
F_38 ( V_64 , V_105 , 1 ) ;
} else {
F_38 ( V_64 , V_106 , 0 ) ;
F_38 ( V_64 , V_105 , 0 ) ;
}
break;
default:
return 0 ;
}
V_89:
if ( ( V_58 -> V_87 & V_110 ) && V_58 -> V_111 )
V_58 -> V_111 ( V_58 , V_17 , V_54 , V_18 ) ;
return 1 ;
}
static void F_41 ( struct V_8 * V_58 ,
struct V_50 * V_90 )
{
struct V_86 * V_64 = V_90 -> V_64 ;
if ( V_90 -> V_11 -> V_112 < 1 )
return;
switch ( V_90 -> V_11 -> V_17 [ 0 ] -> V_91 ) {
case V_92 :
V_64 -> V_113 = L_4 ;
break;
case V_114 :
F_42 ( V_115 , V_64 -> V_116 ) ;
F_42 ( V_117 , V_64 -> V_116 ) ;
F_42 ( V_118 , V_64 -> V_116 ) ;
F_43 ( V_106 , V_64 -> V_116 ) ;
V_64 -> V_113 = ( V_90 -> V_11 -> V_17 [ 0 ] -> V_57 ) ?
L_5 :
L_6 ;
break;
}
}
static int F_44 ( struct V_8 * V_9 , const struct V_119 * V_102 )
{
int V_21 ;
struct V_36 * V_37 ;
struct V_10 * V_11 ;
if ( V_102 -> V_120 )
V_9 -> V_121 |= V_122
| V_123 ;
V_37 = F_8 ( sizeof( struct V_36 ) , V_25 ) ;
if ( ! V_37 ) {
F_45 ( V_9 , L_7 ) ;
return - V_124 ;
}
V_37 -> V_93 = 0 ;
V_37 -> V_42 = 0 ;
V_37 -> V_45 = 0 ;
V_37 -> V_46 = V_46 ;
V_37 -> V_108 = V_46 ;
V_37 -> V_49 = - V_49 ;
V_37 -> V_40 = 1 ;
V_37 -> V_41 = 1 ;
V_37 -> V_38 = 1 ;
V_37 -> V_39 = 1 ;
F_46 ( V_9 , V_37 ) ;
V_21 = F_47 ( V_9 ) ;
if ( V_21 ) {
F_45 ( V_9 , L_8 ) ;
goto V_26;
}
V_21 = F_48 ( V_9 , V_125 & ~ V_126 ) ;
if ( V_21 ) {
F_45 ( V_9 , L_9 ) ;
goto V_26;
}
V_11 = V_9 -> V_12 [ V_13 ] . V_14 [ 0x0a ] ;
if ( V_11 ) {
F_4 ( V_9 ) ;
F_3 ( V_9 , V_11 , V_16 ) ;
if ( F_2 ( V_9 ) >= 4 )
F_5 ( V_9 , 3 ) ;
}
F_6 ( V_9 ) ;
V_21 = F_49 ( & V_9 -> V_33 . V_127 ,
& V_128 ) ;
return 0 ;
V_26:
F_12 ( V_37 ) ;
return V_21 ;
}
static void F_50 ( struct V_8 * V_9 )
{
F_51 ( & V_9 -> V_33 . V_127 ,
& V_128 ) ;
F_52 ( V_9 ) ;
F_12 ( F_15 ( V_9 ) ) ;
}
