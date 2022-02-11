static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 , V_4 , V_3 ) ;
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 , unsigned V_8 )
{
int V_5 ;
V_5 = F_4 ( V_2 -> V_6 -> V_7 , V_4 , V_3 , V_8 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 )
{
int V_5 ;
V_5 = F_3 ( V_2 , V_3 , V_4 , 1 ) ;
return V_5 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
if ( V_9 == 0x00 )
return 1 << V_2 -> V_10 -> V_11 ;
else
return V_9 & ( ( 1 << V_2 -> V_10 -> V_11 ) - 1 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_12 ;
V_5 = F_5 ( V_2 , & V_12 , V_13 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 , L_1 , V_5 ) ;
return V_5 ;
}
V_12 |= 0x1 ;
V_5 = F_1 ( V_2 , V_12 , V_13 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 , L_2 , V_5 ) ;
return V_5 ;
}
F_9 ( ( 2 * F_10 ( V_14 , V_15 ) ) + 1 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 * V_16 ,
T_2 V_17 , int V_18 )
{
int V_5 , V_19 ;
T_1 V_20 [ V_21 ] ;
V_5 = F_3 ( V_2 , V_20 , V_17 , V_18 ) ;
if ( V_5 )
return V_5 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_10 -> V_22 ; V_19 ++ ) {
F_12 ( V_2 -> V_6 , L_3 , V_19 ,
V_20 [ V_19 ] ) ;
V_16 [ V_19 ] = F_6 ( V_2 , V_20 [ V_19 ] ) ;
}
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 * V_23 ,
T_2 * V_24 )
{
int V_5 , V_18 ;
T_1 V_12 ;
if ( V_2 -> V_10 -> V_22 < V_25 )
V_18 = V_25 ;
else
V_18 = V_2 -> V_10 -> V_22 ;
F_7 ( V_2 ) ;
if ( V_24 ) {
V_5 = F_11 ( V_2 , V_24 , V_26 ,
V_18 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 ,
L_4 , V_5 ) ;
return V_5 ;
}
}
V_5 = F_11 ( V_2 , V_23 , V_27 ,
V_18 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 ,
L_5 , V_5 ) ;
return V_5 ;
}
F_9 ( ( 4 * F_10 ( V_14 , V_15 ) ) + 1 ) ;
V_5 = F_5 ( V_2 , & V_12 , V_13 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 , L_1 , V_5 ) ;
return V_5 ;
}
V_12 &= 0xFE ;
V_5 = F_1 ( V_2 , V_12 , V_13 ) ;
if ( V_5 < 0 )
F_8 ( V_2 -> V_6 , L_2 , V_5 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , T_2 * V_23 ,
T_2 * V_24 )
{
int V_19 , V_9 , V_28 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_10 -> V_22 ; V_19 ++ ) {
int V_29 = V_23 [ V_19 ] ^ V_24 [ V_19 ] ;
if ( ! V_29 )
continue;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 -> V_11 ; V_9 ++ ) {
if ( ! ( V_29 & ( 1 << V_9 ) ) )
continue;
F_12 ( V_2 -> V_6 , L_6 , V_19 , V_9 ,
! ( V_23 [ V_19 ] & ( 1 << V_9 ) ) ?
L_7 : L_8 ) ;
V_28 = F_15 ( V_19 , V_9 , V_30 ) ;
F_16 ( V_2 -> V_31 , V_32 , V_33 , V_28 ) ;
F_17 ( V_2 -> V_31 ,
V_2 -> V_34 [ V_28 ] ,
! ( V_23 [ V_19 ] & ( 1 << V_9 ) ) ) ;
F_18 ( V_2 -> V_31 ) ;
}
}
}
static bool F_19 ( struct V_1 * V_2 , T_2 * V_23 )
{
int V_19 , V_35 = - 1 ;
T_2 V_36 , V_37 ;
V_36 = 0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_10 -> V_22 ; V_19 ++ ) {
V_37 = ( ~ V_23 [ V_19 ] ) &
( ( 1 << V_2 -> V_10 -> V_11 ) - 1 ) ;
if ( F_20 ( V_37 ) > 1 ) {
if ( V_35 == - 1 )
V_35 = V_19 ;
if ( V_36 & V_37 ) {
F_12 ( V_2 -> V_6 , L_9
L_10 , V_35 , V_19 ) ;
return true ;
}
}
V_36 |= V_37 ;
}
return false ;
}
static int F_21 ( struct V_1 * V_2 , unsigned int V_38 )
{
T_2 V_23 [ V_21 ] ;
T_2 V_24 [ V_21 ] ;
int V_5 ;
switch ( V_38 ) {
case 0x1 :
V_5 = F_13 ( V_2 , V_23 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_19 ( V_2 , V_23 ) )
return 0 ;
F_14 ( V_2 , V_23 , V_2 -> V_39 ) ;
memcpy ( V_2 -> V_39 , V_23 , sizeof( V_23 ) ) ;
break;
case 0x3 :
V_5 = F_13 ( V_2 , V_23 , V_24 ) ;
if ( V_5 < 0 )
return V_5 ;
F_14 ( V_2 , V_24 , V_2 -> V_39 ) ;
F_14 ( V_2 , V_23 , V_24 ) ;
memcpy ( V_2 -> V_39 , V_23 , sizeof( V_23 ) ) ;
break;
case 0x2 :
F_12 ( V_2 -> V_6 , L_11 ) ;
V_5 = F_13 ( V_2 , V_23 , V_24 ) ;
if ( V_5 < 0 )
return V_5 ;
F_14 ( V_2 , V_24 , V_2 -> V_39 ) ;
F_14 ( V_2 , V_23 , V_24 ) ;
memcpy ( V_2 -> V_39 , V_23 , sizeof( V_23 ) ) ;
break;
default:
V_5 = - V_40 ;
}
return V_5 ;
}
static T_3 F_22 ( int V_41 , void * V_3 )
{
T_2 V_23 [ V_21 ] ;
T_2 V_24 [ V_21 ] ;
int V_5 ;
struct V_1 * V_2 = V_3 ;
V_5 = F_13 ( V_2 , V_23 , V_24 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 , L_12 ) ;
return V_42 ;
}
F_14 ( V_2 , V_23 , V_2 -> V_43 ) ;
return V_42 ;
}
static T_3 F_23 ( int V_41 , void * V_3 )
{
struct V_1 * V_2 = V_3 ;
T_1 V_44 , V_38 ;
int V_5 ;
V_5 = F_3 ( V_2 , & V_44 , V_45 , 1 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 , L_13 ) ;
return V_42 ;
}
V_38 = V_44 & V_46 ;
V_5 = F_21 ( V_2 , V_38 ) ;
if ( V_5 < 0 )
F_8 ( V_2 -> V_6 , L_14 ) ;
return V_42 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_47 , V_5 , V_48 ;
T_1 V_12 = 0 , V_44 = 0 ;
static const T_1 V_49 [] = {
0 , 1 , 2 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 6 , 7 , 7 , 7 ,
} ;
if ( V_2 -> V_10 -> V_11 < V_50 )
V_47 = 0 ;
else
V_47 = V_2 -> V_10 -> V_11 - V_50 ;
V_44 = ( V_47 & V_51 ) <<
V_52 ;
if ( V_2 -> V_10 -> V_22 < V_53 )
V_47 = 0 ;
else
V_47 = V_49 [ V_2 -> V_10 -> V_22 - V_53 ] ;
V_44 |= ( V_47 << V_54 ) ;
V_5 = F_1 ( V_2 , V_44 , V_45 ) ;
if ( V_5 < 0 ) {
F_8 ( V_2 -> V_6 , L_15 , V_5 ) ;
return V_5 ;
}
V_47 = ( V_2 -> V_10 -> V_55 / 5 ) - 1 ;
V_12 |= ( V_47 << V_56 ) ;
V_47 = F_25 ( V_2 -> V_10 -> V_57 ) - 1 ;
V_12 |= ( V_47 << V_58 ) ;
V_48 = ( V_2 -> V_10 -> V_59 * V_15 ) / V_60 ;
V_12 |= ( V_48 << V_61 ) ;
V_5 = F_1 ( V_2 , V_12 , V_13 ) ;
if ( V_5 )
F_8 ( V_2 -> V_6 , L_2 , V_5 ) ;
return V_5 ;
}
static int F_26 ( int V_62 , int V_63 ,
struct V_1 * V_2 , struct V_64 * V_65 )
{
int V_5 , V_66 ;
if ( V_62 < 0 || V_63 < 0 )
return - V_40 ;
for ( V_66 = 0 ; V_66 < V_63 ; V_66 ++ ) {
V_5 = F_27 ( V_62 + V_66 , V_65 ) ;
if ( V_5 ) {
F_8 ( V_2 -> V_6 , L_16
L_17 ,
V_67 , V_62 + V_66 , V_5 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_68 |= V_69 ;
V_5 = F_1 ( V_2 , V_2 -> V_68 , V_45 ) ;
if ( V_5 < 0 )
F_8 ( V_2 -> V_6 , L_15 , V_5 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_68 &= ~ V_69 ;
V_5 = F_1 ( V_2 , V_2 -> V_68 , V_45 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 ;
}
static int F_30 ( struct V_70 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
return F_28 ( V_2 ) ;
}
static void F_32 ( struct V_70 * V_6 )
{
struct V_1 * V_2 = F_31 ( V_6 ) ;
F_29 ( V_2 ) ;
}
static int F_33 ( struct V_71 * V_72 )
{
const struct V_73 * V_10 =
F_34 ( & V_72 -> V_6 ) ;
const struct V_74 * V_75 ;
struct V_1 * V_2 ;
int V_5 ;
T_1 V_44 ;
struct V_64 V_76 = {
. V_77 = V_78 ,
. V_79 = V_80 ,
. V_81 = 0 ,
. V_82 = V_83 ,
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = 1 ,
} ;
struct V_64 V_91 = {
. V_77 = V_92 ,
. V_82 = V_93 ,
. V_84 = V_85 ,
. V_86 = V_94 ,
. V_88 = V_95 ,
. V_90 = 1 ,
} ;
if ( ! V_10 || ! V_10 -> V_11 || ! V_10 -> V_22 ||
V_10 -> V_11 > V_96 ||
V_10 -> V_22 > V_21 ||
V_10 -> V_11 < V_97 ) {
F_8 ( & V_72 -> V_6 , L_18 ) ;
return - V_40 ;
}
if ( ! V_10 -> V_57 ||
V_10 -> V_57 > V_98 ||
V_10 -> V_57 < V_99 ||
! F_35 ( V_10 -> V_57 ) ) {
F_8 ( & V_72 -> V_6 , L_19 ) ;
return - V_40 ;
}
if ( ! V_10 -> V_59 ||
V_10 -> V_59 > V_100 ||
V_10 -> V_59 < V_101 ||
( ( V_10 -> V_59 % V_101 ) != 0 ) ) {
F_8 ( & V_72 -> V_6 , L_20 ) ;
return - V_40 ;
}
if ( ! V_10 -> V_55 ||
( ( V_10 -> V_55 % 5 ) != 0 ) ||
V_10 -> V_55 > V_102 ||
V_10 -> V_55 < V_103 ) {
F_8 ( & V_72 -> V_6 , L_21 ) ;
return - V_40 ;
}
V_75 = V_10 -> V_75 ;
if ( ! V_75 ) {
F_8 ( & V_72 -> V_6 , L_22 ) ;
return - V_40 ;
}
V_2 = F_36 ( sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
F_37 ( V_72 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_6 = & V_72 -> V_6 ;
V_2 -> V_31 = F_38 () ;
if ( ! V_2 -> V_31 ) {
F_8 ( & V_72 -> V_6 , L_23 ) ;
V_5 = - V_105 ;
goto V_106;
}
V_2 -> V_107 = F_39 ( V_72 , 0 ) ;
if ( V_2 -> V_107 < 0 ) {
F_8 ( & V_72 -> V_6 , L_24 ) ;
V_5 = - V_108 ;
goto V_109;
}
V_2 -> V_110 = F_39 ( V_72 , 1 ) ;
if ( V_2 -> V_110 < 0 ) {
F_8 ( & V_72 -> V_6 , L_25 ) ;
V_5 = - V_108 ;
goto V_109;
}
V_2 -> V_31 -> V_111 = V_10 -> V_112 ? : L_26 ;
V_2 -> V_31 -> V_113 = V_10 -> V_114 ? : L_27 ;
V_2 -> V_31 -> V_6 . V_7 = & V_72 -> V_6 ;
V_2 -> V_31 -> V_115 . V_116 = V_117 ;
V_2 -> V_31 -> V_115 . V_118 = 0x0001 ;
V_2 -> V_31 -> V_115 . V_119 = 0x0001 ;
V_2 -> V_31 -> V_115 . V_120 = 0x0001 ;
V_2 -> V_31 -> V_121 = F_30 ;
V_2 -> V_31 -> V_122 = F_32 ;
V_5 = F_40 ( V_75 , NULL ,
V_21 , V_96 ,
V_2 -> V_34 , V_2 -> V_31 ) ;
if ( V_5 ) {
F_8 ( & V_72 -> V_6 , L_28 ) ;
goto V_109;
}
if ( V_10 -> V_123 )
F_41 ( V_124 , V_2 -> V_31 -> V_125 ) ;
F_42 ( V_2 -> V_31 , V_32 , V_33 ) ;
F_43 ( V_2 -> V_31 , V_2 ) ;
memset ( V_2 -> V_39 , 0xff , sizeof( V_2 -> V_39 ) ) ;
memset ( V_2 -> V_43 , 0xff , sizeof( V_2 -> V_43 ) ) ;
V_5 = F_24 ( V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_29 ) ;
goto V_109;
}
V_5 = F_26 ( V_10 -> V_126 ,
V_10 -> V_11 , V_2 , & V_91 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_30 ) ;
goto V_127;
}
V_5 = F_26 ( V_10 -> V_128 ,
V_10 -> V_22 , V_2 , & V_76 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_31 ) ;
goto V_127;
}
V_5 = F_44 ( V_2 -> V_107 , F_23 ,
V_129 , L_32 , V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_33 ) ;
goto V_109;
}
V_5 = F_44 ( V_2 -> V_110 , F_22 ,
V_129 , L_34 , V_2 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_35 ) ;
goto V_130;
}
V_5 = F_5 ( V_2 , & V_44 , V_45 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_36 ) ;
goto V_131;
}
V_2 -> V_68 = V_44 ;
V_5 = F_45 ( V_2 -> V_31 ) ;
if ( V_5 < 0 ) {
F_8 ( & V_72 -> V_6 , L_37 ) ;
goto V_131;
}
F_46 ( & V_72 -> V_6 , V_10 -> V_132 ) ;
return 0 ;
V_131:
F_47 ( V_2 -> V_110 , V_2 ) ;
V_130:
F_47 ( V_2 -> V_107 , V_2 ) ;
V_127:
V_109:
F_48 ( V_2 -> V_31 ) ;
V_106:
F_49 ( V_2 ) ;
return V_5 ;
}
static int F_50 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_51 ( V_72 ) ;
F_46 ( & V_72 -> V_6 , 0 ) ;
F_47 ( V_2 -> V_110 , V_2 ) ;
F_47 ( V_2 -> V_107 , V_2 ) ;
F_52 ( V_2 -> V_31 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_133 * V_6 )
{
struct V_71 * V_72 = F_54 ( V_6 ) ;
struct V_1 * V_2 = F_51 ( V_72 ) ;
struct V_70 * V_70 = V_2 -> V_31 ;
if ( F_55 ( V_6 ) ) {
F_56 ( V_2 -> V_107 ) ;
} else {
F_57 ( & V_70 -> V_134 ) ;
if ( V_70 -> V_135 )
F_29 ( V_2 ) ;
F_58 ( & V_70 -> V_134 ) ;
}
return 0 ;
}
static int F_59 ( struct V_133 * V_6 )
{
struct V_71 * V_72 = F_54 ( V_6 ) ;
struct V_1 * V_2 = F_51 ( V_72 ) ;
struct V_70 * V_70 = V_2 -> V_31 ;
if ( F_55 ( V_6 ) ) {
F_60 ( V_2 -> V_107 ) ;
} else {
F_57 ( & V_70 -> V_134 ) ;
if ( V_70 -> V_135 )
F_28 ( V_2 ) ;
F_58 ( & V_70 -> V_134 ) ;
}
return 0 ;
}
