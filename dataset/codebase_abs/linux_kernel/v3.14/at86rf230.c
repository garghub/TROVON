static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 = {
. V_11 = 2 ,
. V_12 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 & V_13 ) | V_14 | V_15 ;
V_5 [ 1 ] = V_4 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
F_3 ( & V_8 ) ;
F_4 ( & V_10 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 , int V_19 , T_1 * V_4 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 = {
. V_11 = 2 ,
. V_12 = V_5 ,
. V_20 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 & V_13 ) | V_14 ;
V_5 [ 1 ] = 0xff ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_3 ( & V_8 ) ;
F_4 ( & V_10 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
if ( V_6 == 0 )
* V_4 = V_5 [ 1 ] ;
return V_6 ;
}
static int
F_7 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 , int V_19 , T_1 * V_4 )
{
int V_6 ;
F_8 ( & V_2 -> V_21 ) ;
V_6 = F_6 ( V_2 , V_3 , V_18 , V_19 , V_4 ) ;
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_18 , int V_19 , T_1 V_4 )
{
int V_6 ;
T_1 V_22 ;
F_8 ( & V_2 -> V_21 ) ;
V_6 = F_6 ( V_2 , V_3 , 0xff , 0 , & V_22 ) ;
if ( V_6 )
goto V_23;
V_22 &= ~ V_18 ;
V_22 |= ( V_4 << V_19 ) & V_18 ;
V_6 = F_1 ( V_2 , V_3 , V_22 ) ;
V_23:
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_11 ( struct V_1 * V_2 , T_1 * V_4 , T_1 V_11 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_24 = {
. V_11 = 2 ,
. V_12 = V_5 ,
} ;
struct V_9 V_25 = {
. V_11 = V_11 ,
. V_12 = V_4 ,
} ;
F_8 ( & V_2 -> V_21 ) ;
V_5 [ 0 ] = V_15 | V_26 ;
V_5 [ 1 ] = V_11 + 2 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
F_3 ( & V_8 ) ;
F_4 ( & V_24 , & V_8 ) ;
F_4 ( & V_25 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 * V_4 , T_1 * V_11 , T_1 * V_27 )
{
T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
struct V_7 V_8 ;
struct V_9 V_24 = {
. V_11 = 2 ,
. V_12 = V_5 ,
. V_20 = V_5 ,
} ;
struct V_9 V_28 = {
. V_11 = 2 ,
. V_12 = V_5 ,
. V_20 = V_5 ,
} ;
struct V_9 V_25 = {
. V_11 = 0 ,
. V_20 = V_4 ,
} ;
F_8 ( & V_2 -> V_21 ) ;
V_5 [ 0 ] = V_26 ;
V_5 [ 1 ] = 0x00 ;
F_3 ( & V_8 ) ;
F_4 ( & V_24 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
V_25 . V_11 = * ( V_5 + 1 ) + 1 ;
* V_11 = V_5 [ 1 ] ;
V_5 [ 0 ] = V_26 ;
V_5 [ 1 ] = 0x00 ;
F_3 ( & V_8 ) ;
F_4 ( & V_28 , & V_8 ) ;
F_4 ( & V_25 , & V_8 ) ;
V_6 = F_5 ( V_2 -> V_16 , & V_8 ) ;
if ( V_8 . V_6 )
V_6 = V_8 . V_6 ;
F_2 ( & V_2 -> V_16 -> V_17 , L_3 , V_6 ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_1 , V_5 [ 0 ] ) ;
F_2 ( & V_2 -> V_16 -> V_17 , L_2 , V_5 [ 1 ] ) ;
if ( V_6 ) {
if ( V_27 && ( * V_11 > V_2 -> V_5 [ 1 ] ) )
* V_27 = V_4 [ V_2 -> V_5 [ 1 ] ] ;
}
F_9 ( & V_2 -> V_21 ) ;
return V_6 ;
}
static int
F_13 ( struct V_29 * V_17 , T_1 * V_30 )
{
F_14 () ;
F_15 ( ! V_30 ) ;
* V_30 = 0xbe ;
return 0 ;
}
static int
F_16 ( struct V_29 * V_17 , int V_31 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
int V_33 ;
T_1 V_22 ;
T_1 V_34 ;
F_14 () ;
if ( V_31 == V_35 )
V_34 = V_36 ;
else if ( V_31 == V_37 )
V_34 = V_38 ;
else
V_34 = V_31 ;
do {
V_33 = F_7 ( V_2 , V_39 , & V_22 ) ;
if ( V_33 )
goto V_40;
} while ( V_22 == V_41 );
if ( V_22 == V_34 )
return 0 ;
V_33 = F_10 ( V_2 , V_42 , V_31 ) ;
if ( V_33 )
goto V_40;
do {
V_33 = F_7 ( V_2 , V_39 , & V_22 ) ;
if ( V_33 )
goto V_40;
} while ( V_22 == V_41 );
if ( V_22 == V_34 )
return 0 ;
F_17 ( L_4 , V_22 , V_31 ) ;
return - V_43 ;
V_40:
F_17 ( L_5 , V_33 ) ;
return V_33 ;
}
static int
F_18 ( struct V_29 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
T_1 V_33 ;
V_33 = F_10 ( V_2 , V_44 , 1 ) ;
if ( V_33 )
return V_33 ;
return F_16 ( V_17 , V_45 ) ;
}
static void
F_19 ( struct V_29 * V_17 )
{
F_16 ( V_17 , V_37 ) ;
}
static int
F_20 ( struct V_29 * V_17 , int V_46 , int V_47 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
int V_33 ;
F_14 () ;
if ( V_46 != 0 || V_47 < 11 || V_47 > 26 ) {
F_21 ( 1 ) ;
return - V_48 ;
}
V_33 = F_10 ( V_2 , V_49 , V_47 ) ;
F_22 ( 1 ) ;
V_17 -> V_50 -> V_51 = V_47 ;
return 0 ;
}
static int
F_23 ( struct V_29 * V_17 , struct V_52 * V_53 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
int V_33 ;
unsigned long V_54 ;
F_24 ( & V_2 -> V_55 , V_54 ) ;
if ( V_2 -> V_56 ) {
F_25 ( & V_2 -> V_55 , V_54 ) ;
return - V_43 ;
}
F_25 ( & V_2 -> V_55 , V_54 ) ;
F_14 () ;
V_33 = F_16 ( V_17 , V_35 ) ;
if ( V_33 )
goto V_40;
F_24 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_57 = 1 ;
F_26 ( & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
V_33 = F_11 ( V_2 , V_53 -> V_4 , V_53 -> V_11 ) ;
if ( V_33 )
goto V_59;
V_33 = F_10 ( V_2 , V_42 , V_60 ) ;
if ( V_33 )
goto V_59;
V_33 = F_27 ( & V_2 -> V_58 ) ;
if ( V_33 < 0 )
goto V_59;
V_33 = F_18 ( V_17 ) ;
return V_33 ;
V_59:
F_18 ( V_17 ) ;
V_40:
F_17 ( L_5 , V_33 ) ;
F_24 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_57 = 0 ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
return V_33 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_11 = 128 , V_27 = 0 ;
struct V_52 * V_53 ;
V_53 = F_29 ( V_11 , V_61 ) ;
if ( ! V_53 )
return - V_62 ;
if ( F_12 ( V_2 , F_30 ( V_53 , V_11 ) , & V_11 , & V_27 ) )
goto V_40;
if ( V_11 < 2 )
goto V_40;
F_31 ( V_53 , V_11 - 2 ) ;
F_32 ( V_2 -> V_17 , V_53 , V_27 ) ;
F_33 ( & V_2 -> V_16 -> V_17 , L_6 , V_11 , V_27 ) ;
return 0 ;
V_40:
F_34 ( L_7 ) ;
F_35 ( V_53 ) ;
return - V_48 ;
}
static int
F_36 ( struct V_29 * V_17 ,
struct V_63 * V_64 ,
unsigned long V_65 )
{
struct V_1 * V_2 = V_17 -> V_32 ;
if ( V_65 & V_66 ) {
F_2 ( & V_2 -> V_16 -> V_17 ,
L_8 ) ;
F_1 ( V_2 , V_67 , V_64 -> V_68 ) ;
F_1 ( V_2 , V_69 , V_64 -> V_68 >> 8 ) ;
}
if ( V_65 & V_70 ) {
F_2 ( & V_2 -> V_16 -> V_17 ,
L_9 ) ;
F_1 ( V_2 , V_71 , V_64 -> V_72 ) ;
F_1 ( V_2 , V_73 , V_64 -> V_72 >> 8 ) ;
}
if ( V_65 & V_74 ) {
F_2 ( & V_2 -> V_16 -> V_17 ,
L_10 ) ;
F_10 ( V_2 , V_75 , V_64 -> V_76 [ 7 ] ) ;
F_10 ( V_2 , V_77 , V_64 -> V_76 [ 6 ] ) ;
F_10 ( V_2 , V_78 , V_64 -> V_76 [ 5 ] ) ;
F_10 ( V_2 , V_79 , V_64 -> V_76 [ 4 ] ) ;
F_10 ( V_2 , V_80 , V_64 -> V_76 [ 3 ] ) ;
F_10 ( V_2 , V_81 , V_64 -> V_76 [ 2 ] ) ;
F_10 ( V_2 , V_82 , V_64 -> V_76 [ 1 ] ) ;
F_10 ( V_2 , V_83 , V_64 -> V_76 [ 0 ] ) ;
}
if ( V_65 & V_84 ) {
F_2 ( & V_2 -> V_16 -> V_17 ,
L_11 ) ;
if ( V_64 -> V_85 )
F_10 ( V_2 , V_86 , 1 ) ;
else
F_10 ( V_2 , V_86 , 0 ) ;
}
return 0 ;
}
static void F_37 ( struct V_87 * V_88 )
{
struct V_1 * V_2 =
F_38 ( V_88 , struct V_1 , V_89 ) ;
T_1 V_6 = 0 , V_22 ;
int V_33 ;
unsigned long V_54 ;
V_33 = F_7 ( V_2 , V_90 , 0xff , 0 , & V_22 ) ;
V_6 |= V_22 ;
V_6 &= ~ V_91 ;
V_6 &= ~ V_92 ;
V_6 &= ~ V_93 ;
V_6 &= ~ V_94 ;
if ( V_6 & V_95 ) {
F_24 ( & V_2 -> V_55 , V_54 ) ;
V_6 &= ~ V_95 ;
if ( V_2 -> V_57 ) {
V_2 -> V_57 = 0 ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
F_39 ( & V_2 -> V_58 ) ;
} else {
F_25 ( & V_2 -> V_55 , V_54 ) ;
F_28 ( V_2 ) ;
}
}
F_24 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_56 = 0 ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
}
static void F_40 ( struct V_87 * V_88 )
{
struct V_1 * V_2 =
F_38 ( V_88 , struct V_1 , V_89 ) ;
F_37 ( V_88 ) ;
F_41 ( V_2 -> V_16 -> V_96 ) ;
}
static T_2 F_42 ( int V_96 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
unsigned long V_54 ;
F_24 ( & V_2 -> V_55 , V_54 ) ;
V_2 -> V_56 = 1 ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
F_43 ( & V_2 -> V_89 ) ;
return V_97 ;
}
static T_2 F_44 ( int V_96 , void * V_4 )
{
F_45 ( V_96 ) ;
return F_42 ( V_96 , V_4 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_98 )
{
return F_10 ( V_2 , V_99 , V_98 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_100 * V_101 = V_2 -> V_16 -> V_17 . V_102 ;
int V_33 , V_103 ;
T_1 V_6 ;
V_33 = F_7 ( V_2 , V_39 , & V_6 ) ;
if ( V_33 )
return V_33 ;
F_48 ( & V_2 -> V_16 -> V_17 , L_12 , V_6 ) ;
if ( V_6 == V_104 ) {
V_33 = F_10 ( V_2 , V_42 , V_38 ) ;
if ( V_33 )
return V_33 ;
F_22 ( 1 ) ;
V_33 = F_7 ( V_2 , V_39 , & V_6 ) ;
if ( V_33 )
return V_33 ;
F_48 ( & V_2 -> V_16 -> V_17 , L_12 , V_6 ) ;
}
if ( V_101 -> V_105 & ( V_106 | V_107 ) )
V_103 = V_108 ;
else
V_103 = V_109 ;
V_33 = F_46 ( V_2 , V_103 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_10 ( V_2 , V_110 , V_95 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_10 ( V_2 , V_111 , 0x00 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_10 ( V_2 , V_112 , 0x00 ) ;
if ( V_33 )
return V_33 ;
F_22 ( 100 ) ;
V_33 = F_10 ( V_2 , V_42 , V_36 ) ;
if ( V_33 )
return V_33 ;
F_22 ( 1 ) ;
V_33 = F_7 ( V_2 , V_39 , & V_6 ) ;
if ( V_33 )
return V_33 ;
F_48 ( & V_2 -> V_16 -> V_17 , L_12 , V_6 ) ;
V_33 = F_7 ( V_2 , V_113 , & V_6 ) ;
if ( V_33 )
return V_33 ;
if ( ! V_6 ) {
F_49 ( & V_2 -> V_16 -> V_17 , L_13 ) ;
return - V_48 ;
}
V_33 = F_7 ( V_2 , V_114 , & V_6 ) ;
if ( V_33 )
return V_33 ;
if ( ! V_6 ) {
F_49 ( & V_2 -> V_16 -> V_17 , L_14 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_50 ( struct V_115 * V_16 )
{
struct V_1 * V_2 = F_51 ( V_16 ) ;
struct V_100 * V_101 = V_16 -> V_17 . V_102 ;
V_2 -> V_116 = V_101 -> V_116 ;
V_2 -> V_117 = V_101 -> V_117 ;
V_2 -> V_118 = V_101 -> V_118 ;
}
static int F_52 ( struct V_115 * V_16 )
{
struct V_100 * V_101 ;
struct V_29 * V_17 ;
struct V_1 * V_2 ;
T_1 V_119 , V_120 , V_6 ;
T_3 V_121 ;
T_4 V_122 ;
int V_33 , V_123 = 0 ;
const char * V_124 ;
if ( ! V_16 -> V_96 ) {
F_49 ( & V_16 -> V_17 , L_15 ) ;
return - V_48 ;
}
V_101 = V_16 -> V_17 . V_102 ;
if ( ! V_101 ) {
F_49 ( & V_16 -> V_17 , L_16 ) ;
return - V_48 ;
}
V_17 = F_53 ( sizeof( * V_2 ) , & V_125 ) ;
if ( ! V_17 )
return - V_62 ;
V_2 = V_17 -> V_32 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_16 = V_16 ;
V_17 -> V_126 = & V_16 -> V_17 ;
V_17 -> V_127 = 0 ;
V_17 -> V_50 -> V_128 [ 0 ] = 0x7FFF800 ;
V_17 -> V_54 = V_129 ;
if ( V_101 -> V_105 & ( V_130 | V_106 ) ) {
V_122 = F_37 ;
V_121 = F_42 ;
} else {
V_122 = F_40 ;
V_121 = F_44 ;
}
F_54 ( & V_2 -> V_21 ) ;
F_55 ( & V_2 -> V_89 , V_122 ) ;
F_56 ( & V_2 -> V_55 ) ;
F_57 ( & V_2 -> V_58 ) ;
F_58 ( V_16 , V_2 ) ;
F_50 ( V_16 ) ;
V_33 = F_59 ( V_2 -> V_116 , L_17 ) ;
if ( V_33 )
goto V_131;
if ( F_60 ( V_2 -> V_117 ) ) {
V_33 = F_59 ( V_2 -> V_117 , L_18 ) ;
if ( V_33 )
goto V_132;
}
V_33 = F_61 ( V_2 -> V_116 , 1 ) ;
if ( V_33 )
goto V_133;
if ( F_60 ( V_2 -> V_117 ) ) {
V_33 = F_61 ( V_2 -> V_117 , 0 ) ;
if ( V_33 )
goto V_133;
}
F_22 ( 1 ) ;
F_62 ( V_2 -> V_116 , 0 ) ;
F_22 ( 1 ) ;
F_62 ( V_2 -> V_116 , 1 ) ;
F_22 ( 1 ) ;
V_33 = F_7 ( V_2 , V_134 , & V_119 ) ;
if ( V_33 )
goto V_133;
V_33 = F_7 ( V_2 , V_135 , & V_120 ) ;
if ( V_33 )
goto V_133;
if ( V_120 != 0x00 || V_119 != 0x1f ) {
F_49 ( & V_16 -> V_17 , L_19 ,
V_120 , V_119 ) ;
V_33 = - V_48 ;
goto V_133;
}
V_33 = F_7 ( V_2 , V_136 , & V_2 -> V_137 ) ;
if ( V_33 )
goto V_133;
V_33 = F_7 ( V_2 , V_138 , & V_2 -> V_139 ) ;
if ( V_33 )
goto V_133;
switch ( V_2 -> V_137 ) {
case 2 :
V_124 = L_20 ;
break;
case 3 :
V_124 = L_21 ;
V_123 = 1 ;
break;
default:
V_124 = L_22 ;
break;
}
F_48 ( & V_16 -> V_17 , L_23 , V_124 , V_2 -> V_139 ) ;
if ( ! V_123 ) {
V_33 = - V_140 ;
goto V_133;
}
V_33 = F_47 ( V_2 ) ;
if ( V_33 )
goto V_133;
V_33 = F_63 ( V_16 -> V_96 , V_121 ,
V_141 | V_101 -> V_105 ,
F_64 ( & V_16 -> V_17 ) , V_2 ) ;
if ( V_33 )
goto V_133;
V_33 = F_7 ( V_2 , V_90 , 0xff , 0 , & V_6 ) ;
if ( V_33 )
goto V_142;
V_33 = F_65 ( V_2 -> V_17 ) ;
if ( V_33 )
goto V_142;
return V_33 ;
V_142:
F_66 ( V_16 -> V_96 , V_2 ) ;
F_67 ( & V_2 -> V_89 ) ;
V_133:
if ( F_60 ( V_2 -> V_117 ) )
F_68 ( V_2 -> V_117 ) ;
V_132:
F_68 ( V_2 -> V_116 ) ;
V_131:
F_69 ( & V_2 -> V_21 ) ;
F_70 ( V_2 -> V_17 ) ;
return V_33 ;
}
static int F_71 ( struct V_115 * V_16 )
{
struct V_1 * V_2 = F_51 ( V_16 ) ;
F_72 ( V_2 -> V_17 ) ;
F_66 ( V_16 -> V_96 , V_2 ) ;
F_67 ( & V_2 -> V_89 ) ;
if ( F_60 ( V_2 -> V_117 ) )
F_68 ( V_2 -> V_117 ) ;
F_68 ( V_2 -> V_116 ) ;
F_69 ( & V_2 -> V_21 ) ;
F_70 ( V_2 -> V_17 ) ;
F_33 ( & V_16 -> V_17 , L_24 ) ;
return 0 ;
}
