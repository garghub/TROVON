static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 , T_3 V_3 ,
T_2 * V_4 )
{
return F_2 ( V_1 -> V_5 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_2 V_2 ,
T_3 V_3 , const T_2 * V_4 )
{
return F_4 ( V_1 -> V_5 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_2 V_6 , T_3 V_3 ,
T_2 * V_4 )
{
T_1 V_7 ;
T_2 V_8 ;
T_2 V_9 ;
T_2 * V_10 ;
struct V_11 * V_5 = V_1 -> V_5 ;
if ( ! ( V_12 & V_6 ) )
return - V_13 ;
if ( V_14 & V_6 ) {
V_9 = F_6 ( V_6 , V_15 ) ;
V_7 = F_7 ( V_5 , V_9 , V_4 ) ;
goto V_16;
}
V_7 = 0 ;
for ( V_8 = 0 ; V_8 * V_17 < V_3 ; V_8 ++ ) {
V_9 = F_8 ( V_6 , V_8 ) ;
V_9 = F_6 ( V_9 , V_15 ) ;
V_10 = V_4 + V_17 * V_8 ;
V_7 = F_7 ( V_5 , V_9 , V_10 ) ;
if ( V_7 < 0 )
goto V_16;
}
V_16:
return V_7 > 0 ? V_3 : V_7 ;
}
static T_4 F_9 ( struct V_1 * V_1 , T_2 V_18 )
{
T_2 V_6 ;
if ( V_1 -> V_19 ) {
V_6 = V_20 [ V_18 ] . V_6 ;
V_6 = F_6 ( V_6 , V_15 ) ;
} else {
V_6 = V_21 [ V_18 ] . V_6 ;
}
return F_10 ( V_1 -> V_5 , V_6 ) ;
}
static T_4 F_11 ( struct V_1 * V_1 , T_2 V_18 , T_2 V_22 )
{
T_2 V_6 ;
if ( V_1 -> V_19 ) {
V_6 = V_20 [ V_18 ] . V_6 ;
V_6 = F_6 ( V_6 , V_23 ) ;
} else {
V_6 = V_21 [ V_18 ] . V_6 ;
}
return F_12 ( V_1 -> V_5 , V_6 , V_22 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , T_2 V_18 , T_2 * V_4 )
{
T_2 V_6 ;
T_3 V_3 ;
if ( V_1 -> V_19 ) {
V_6 = V_20 [ V_18 ] . V_6 ;
V_3 = V_20 [ V_18 ] . V_3 ;
return F_5 ( V_1 , V_6 , V_3 , V_4 ) ;
} else {
V_6 = V_21 [ V_18 ] . V_6 ;
V_3 = V_21 [ V_18 ] . V_3 ;
return F_1 ( V_1 , V_6 , V_3 , V_4 ) ;
}
}
static int F_14 ( struct V_1 * V_1 )
{
int V_7 ;
T_2 V_24 [ V_25 ] ;
V_1 -> V_26 = V_27 ;
V_7 = F_1 ( V_1 , V_28 , V_25 ,
V_24 ) ;
if ( V_1 -> V_19 && ( V_7 == - V_29 || V_7 == - V_30 ) )
V_7 = F_13 ( V_1 , V_31 , V_24 ) ;
if ( V_7 != V_25 )
goto error;
if ( ( V_24 [ V_32 ] & V_33 ) == V_33 ) {
switch ( V_24 [ V_32 ] & V_34 ) {
case V_35 :
case V_36 :
V_1 -> V_26 = V_37 ;
break;
default:
V_7 = - V_38 ;
goto error;
}
} else {
if ( V_24 [ V_39 ] & V_40 )
V_1 -> V_26 = V_41 ;
else if ( V_24 [ V_42 ] & V_43 )
V_1 -> V_26 = V_44 ;
else
V_1 -> V_26 = V_45 ;
}
return 0 ;
error:
return ( V_7 < 0 ) ? V_7 : - V_38 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned int V_46 )
{
int V_7 ;
int V_47 = V_46 / 100 ;
V_7 = F_14 ( V_1 ) ;
while ( ( V_7 || V_1 -> V_26 >= V_41 ) && V_47 -- ) {
F_16 ( 100 ) ;
V_7 = F_14 ( V_1 ) ;
}
return ( V_7 == - V_38 || V_7 == - V_29 ) ? - V_29 : V_7 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_3 ( V_1 , 0 , sizeof( V_48 ) ,
V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
F_16 ( 100 ) ;
V_7 = F_15 ( V_1 , 500 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_1 -> V_26 != V_45 )
return - V_38 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_3 ( V_1 , 0 , sizeof( V_49 ) , V_49 ) ;
if ( V_7 < 0 )
return V_7 ;
F_19 ( 50000 , 100000 ) ;
V_7 = F_15 ( V_1 , 2000 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_1 -> V_26 != V_37 )
return - V_38 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , T_2 V_50 )
{
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
int V_7 ;
T_2 V_53 ;
if ( V_1 -> V_26 != V_37 )
return 0 ;
V_7 = F_9 ( V_1 , V_54 ) ;
if ( V_7 < 0 )
return V_7 ;
V_53 = V_7 & ~ V_55 ;
V_53 |= V_50 & V_55 ;
V_7 = F_11 ( V_1 , V_54 , V_53 ) ;
if ( V_7 < 0 )
F_21 ( V_52 , L_1 ,
V_50 , V_7 ) ;
return V_7 ;
}
static int F_22 ( struct V_1 * V_1 )
{
T_2 V_56 [ V_57 ] ;
int V_7 ;
if ( V_1 -> V_26 != V_37 )
return - V_58 ;
V_7 = F_13 ( V_1 , V_59 , V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != V_57 )
return - V_60 ;
memcpy ( & V_1 -> V_61 [ 0 ] , & V_56 [ 0 ] , 5 ) ;
V_1 -> V_61 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_61 [ 6 ] , & V_56 [ 5 ] , 6 ) ;
V_1 -> V_61 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_61 [ 13 ] , & V_56 [ 11 ] , 2 ) ;
V_1 -> V_61 [ 15 ] = '\0' ;
V_1 -> V_62 = V_56 [ 19 ] & V_63 ;
V_1 -> V_64 = V_56 [ 20 ] & 0x0f ;
V_1 -> V_65 = ( ( V_56 [ 21 ] & 0xf0 ) << 4 ) | V_56 [ 22 ] ;
V_1 -> V_66 = ( ( V_56 [ 21 ] & 0x0f ) << 8 ) | V_56 [ 23 ] ;
V_1 -> V_67 =
( ( V_56 [ 24 ] & 0xf0 ) << 4 ) | V_56 [ 25 ] ;
V_1 -> V_68 =
( ( V_56 [ 24 ] & 0x0f ) << 8 ) | V_56 [ 26 ] ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
static const char V_69 [] = L_2 ;
int V_7 ;
V_7 = F_15 ( V_1 , 2000 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_1 -> V_26 ) {
case V_44 :
V_7 = F_17 ( V_1 ) ;
if ( V_7 )
return V_7 ;
case V_45 :
V_7 = F_18 ( V_1 ) ;
if ( V_7 )
return V_7 ;
case V_37 :
V_7 = F_22 ( V_1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_1 -> V_64 != V_70 ) {
F_21 ( V_52 , L_3 ,
V_1 -> V_64 ) ;
return - V_13 ;
}
if ( memcmp ( V_1 -> V_61 , V_69 ,
sizeof( V_69 ) - 1 ) != 0 ) {
F_21 ( V_52 , L_4 ,
V_1 -> V_61 ) ;
return - V_13 ;
}
return 0 ;
default:
return - V_60 ;
}
return 0 ;
}
static T_5 F_24 ( int V_71 , void * V_72 )
{
struct V_1 * V_1 = V_72 ;
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
struct V_73 * V_74 = V_1 -> V_74 ;
struct V_75 V_76 ;
int V_77 ;
int V_7 ;
int V_78 ;
if ( F_25 ( V_52 ) )
F_26 ( V_52 , 0 ) ;
V_7 = F_13 ( V_1 , V_79 , ( T_2 * ) & V_76 ) ;
if ( V_7 != sizeof( V_76 ) )
goto V_16;
if ( ( V_76 . V_80 & V_33 ) != V_33 ||
( V_76 . V_80 & V_34 ) != V_35 ||
( V_76 . V_81 & V_82 ) != V_82 ) {
goto V_16;
}
V_78 = ( V_76 . V_81 >> 4 ) & 0x0f ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
const struct V_83 * V_84 = & V_76 . V_85 [ V_77 ] ;
int V_86 = V_84 -> V_87 - 1 ;
F_27 ( V_74 , V_86 ) ;
F_28 ( V_74 , V_88 , true ) ;
F_29 ( V_74 , V_89 ,
( ( V_84 -> V_90 & 0xf0 ) << 4 ) | V_84 -> V_91 ) ;
F_29 ( V_74 , V_92 ,
( ( V_84 -> V_90 & 0x0f ) << 8 ) | V_84 -> V_93 ) ;
F_29 ( V_74 , V_94 , V_84 -> V_95 ) ;
}
F_30 ( V_74 ) ;
if ( V_1 -> V_62 & V_96 )
F_31 ( V_74 , V_97 ,
V_76 . V_81 & V_98 ) ;
if ( V_1 -> V_62 & V_99 )
F_31 ( V_74 , V_100 ,
V_76 . V_81 & V_101 ) ;
if ( V_1 -> V_62 & V_102 )
F_31 ( V_74 , V_103 ,
V_76 . V_81 & V_104 ) ;
F_32 ( V_74 ) ;
V_16:
return V_105 ;
}
static T_2 F_33 ( struct V_11 * V_5 )
{
T_2 V_7 = V_106 ;
if ( F_34 ( V_5 -> V_107 , V_108 ) )
V_7 |= V_109 ;
if ( F_34 ( V_5 -> V_107 , V_110 |
V_111 |
V_112 ) )
V_7 |= V_113 ;
return V_7 ;
}
static int F_35 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
int V_7 ;
struct V_73 * V_74 ;
if ( ! V_1 -> V_67 || ! V_1 -> V_68 )
return - V_13 ;
V_74 = V_1 -> V_74 = F_36 () ;
if ( ! V_74 ) {
F_21 ( V_52 , L_5 ) ;
return - V_114 ;
}
V_74 -> V_115 = V_116 ;
V_74 -> V_117 = V_1 -> V_117 ;
V_74 -> V_87 . V_118 = V_119 ;
V_74 -> V_87 . V_120 = 1 ;
V_74 -> V_87 . V_121 = 0 ;
V_74 -> V_52 . V_122 = & V_1 -> V_5 -> V_52 ;
F_37 ( V_74 , V_1 ) ;
F_38 ( V_123 , V_74 -> V_124 ) ;
F_39 ( V_74 , V_89 , 0 , V_1 -> V_65 , 0 ,
0 ) ;
F_39 ( V_74 , V_92 , 0 , V_1 -> V_66 , 0 ,
0 ) ;
F_39 ( V_74 , V_94 , 0 , 255 , 0 , 0 ) ;
F_40 ( V_74 , V_89 ,
V_1 -> V_65 / V_1 -> V_67 ) ;
F_40 ( V_74 , V_92 ,
V_1 -> V_66 / V_1 -> V_68 ) ;
if ( V_1 -> V_62 & V_96 )
F_38 ( V_97 , V_74 -> V_125 ) ;
if ( V_1 -> V_62 & V_99 )
F_38 ( V_100 , V_74 -> V_125 ) ;
if ( V_1 -> V_62 & V_102 )
F_38 ( V_103 , V_74 -> V_125 ) ;
if ( V_1 -> V_62 == V_96 )
F_38 ( V_126 , V_74 -> V_127 ) ;
V_7 = F_41 ( V_74 , V_128 ,
V_129 | V_130 ) ;
if ( V_7 ) {
F_21 ( V_52 , L_6 , V_7 ) ;
goto V_131;
}
V_7 = F_42 ( V_74 ) ;
if ( V_7 ) {
F_21 ( V_52 , L_7 , V_7 ) ;
goto V_131;
}
return 0 ;
V_131:
F_43 ( V_74 ) ;
V_1 -> V_74 = NULL ;
return V_7 ;
}
static int F_44 ( struct V_11 * V_5 ,
const struct V_132 * V_72 )
{
int V_7 ;
T_2 V_133 ;
struct V_1 * V_1 ;
struct V_51 * V_52 = & V_5 -> V_52 ;
V_133 = F_33 ( V_5 ) ;
if ( V_133 == V_106 ) {
F_21 ( V_52 , L_8 ) ;
return - V_60 ;
}
V_1 = F_45 ( sizeof( struct V_1 ) , V_134 ) ;
if ( ! V_1 ) {
F_21 ( V_52 , L_9 ) ;
return - V_114 ;
}
V_1 -> V_64 = V_70 ;
V_1 -> V_5 = V_5 ;
F_46 ( V_5 , V_1 ) ;
sprintf ( V_1 -> V_117 , L_10 , V_5 -> V_107 -> V_135 ,
V_5 -> V_136 ) ;
if ( V_133 == V_113 )
V_1 -> V_19 = true ;
V_1 -> V_26 = V_27 ;
V_7 = F_23 ( V_1 ) ;
if ( V_7 ) {
F_21 ( V_52 , L_11 , V_7 ) ;
goto V_137;
}
V_7 = F_35 ( V_1 ) ;
if ( V_7 ) {
F_21 ( V_52 , L_12 , V_7 ) ;
goto V_137;
}
V_7 = F_20 ( V_1 , V_138 ) ;
if ( V_7 ) {
F_21 ( V_52 , L_13 , V_7 ) ;
goto V_139;
}
V_1 -> V_71 = V_5 -> V_71 ;
V_7 = F_47 ( V_1 -> V_71 ,
NULL ,
F_24 ,
V_140 | V_141 ,
L_14 ,
V_1 ) ;
if ( V_7 ) {
F_21 ( V_52 , L_15 , V_7 ) ;
goto V_139;
}
return 0 ;
V_139:
F_48 ( V_1 -> V_74 ) ;
V_137:
F_49 ( V_1 ) ;
return V_7 ;
}
static int F_50 ( struct V_11 * V_5 )
{
struct V_1 * V_1 = F_51 ( V_5 ) ;
F_52 ( V_1 -> V_71 , V_1 ) ;
F_48 ( V_1 -> V_74 ) ;
F_20 ( V_1 , V_142 ) ;
F_49 ( V_1 ) ;
return 0 ;
}
static int F_53 ( struct V_51 * V_52 )
{
int V_7 ;
T_2 V_50 ;
struct V_1 * V_1 = F_54 ( V_52 ) ;
F_55 ( V_1 -> V_71 ) ;
V_50 = F_25 ( V_52 ) ? V_143
: V_142 ;
V_7 = F_20 ( V_1 , V_50 ) ;
if ( V_7 < 0 )
F_21 ( V_52 , L_16 , V_7 ) ;
if ( F_25 ( V_52 ) )
V_1 -> V_144 = ( F_56 ( V_1 -> V_71 ) == 0 ) ;
return 0 ;
}
static int F_57 ( struct V_51 * V_52 )
{
int V_7 ;
struct V_1 * V_1 = F_54 ( V_52 ) ;
if ( F_25 ( V_52 ) && V_1 -> V_144 )
F_58 ( V_1 -> V_71 ) ;
V_7 = F_20 ( V_1 , V_138 ) ;
if ( V_7 )
F_59 ( V_52 , L_17 , V_7 ) ;
F_60 ( V_1 -> V_71 ) ;
return 0 ;
}
