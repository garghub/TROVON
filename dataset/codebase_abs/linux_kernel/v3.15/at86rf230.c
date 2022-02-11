static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == 7 ;
}
static int
F_2 ( struct V_4 * V_5 , T_1 * V_6 , T_2 * V_3 ,
T_2 * V_7 )
{
T_2 V_8 [ 4 ] ;
T_2 * V_9 = F_3 ( 2 , V_10 ) ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 = {
. V_16 = 2 ,
. V_17 = V_9 ,
. V_18 = V_9 ,
} ;
T_2 V_19 ;
if ( ! V_9 )
return - V_20 ;
for ( V_19 = V_21 ; V_19 <= V_22 ; V_19 ++ ) {
V_9 [ 0 ] = ( V_19 & V_23 ) | V_24 ;
V_9 [ 1 ] = 0xff ;
F_4 ( & V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_5 ( & V_13 ) ;
F_6 ( & V_15 , & V_13 ) ;
V_11 = F_7 ( V_5 , & V_13 ) ;
F_4 ( & V_5 -> V_25 , L_2 , V_11 ) ;
if ( V_13 . V_11 )
V_11 = V_13 . V_11 ;
F_4 ( & V_5 -> V_25 , L_2 , V_11 ) ;
F_4 ( & V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
if ( V_11 == 0 )
V_8 [ V_19 - V_21 ] = V_9 [ 1 ] ;
else
break;
}
if ( V_11 == 0 ) {
* V_3 = V_8 [ 0 ] ;
* V_7 = V_8 [ 1 ] ;
* V_6 = ( V_8 [ 3 ] << 8 ) | V_8 [ 2 ] ;
}
F_8 ( V_9 ) ;
return V_11 ;
}
static int
F_9 ( struct V_1 * V_26 , T_2 V_27 , T_2 V_8 )
{
T_2 * V_9 = V_26 -> V_9 ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 = {
. V_16 = 2 ,
. V_17 = V_9 ,
} ;
V_9 [ 0 ] = ( V_27 & V_23 ) | V_24 | V_28 ;
V_9 [ 1 ] = V_8 ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
F_5 ( & V_13 ) ;
F_6 ( & V_15 , & V_13 ) ;
V_11 = F_7 ( V_26 -> V_5 , & V_13 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
if ( V_13 . V_11 )
V_11 = V_13 . V_11 ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
return V_11 ;
}
static int
F_10 ( struct V_1 * V_26 ,
T_2 V_27 , T_2 V_29 , int V_30 , T_2 * V_8 )
{
T_2 * V_9 = V_26 -> V_9 ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 = {
. V_16 = 2 ,
. V_17 = V_9 ,
. V_18 = V_9 ,
} ;
V_9 [ 0 ] = ( V_27 & V_23 ) | V_24 ;
V_9 [ 1 ] = 0xff ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_5 ( & V_13 ) ;
F_6 ( & V_15 , & V_13 ) ;
V_11 = F_7 ( V_26 -> V_5 , & V_13 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
if ( V_13 . V_11 )
V_11 = V_13 . V_11 ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
if ( V_11 == 0 )
* V_8 = ( V_9 [ 1 ] & V_29 ) >> V_30 ;
return V_11 ;
}
static int
F_11 ( struct V_1 * V_26 ,
T_2 V_27 , T_2 V_29 , int V_30 , T_2 * V_8 )
{
int V_11 ;
F_12 ( & V_26 -> V_31 ) ;
V_11 = F_10 ( V_26 , V_27 , V_29 , V_30 , V_8 ) ;
F_13 ( & V_26 -> V_31 ) ;
return V_11 ;
}
static int
F_14 ( struct V_1 * V_26 ,
T_2 V_27 , T_2 V_29 , int V_30 , T_2 V_8 )
{
int V_11 ;
T_2 V_32 ;
F_12 ( & V_26 -> V_31 ) ;
V_11 = F_10 ( V_26 , V_27 , 0xff , 0 , & V_32 ) ;
if ( V_11 )
goto V_33;
V_32 &= ~ V_29 ;
V_32 |= ( V_8 << V_30 ) & V_29 ;
V_11 = F_9 ( V_26 , V_27 , V_32 ) ;
V_33:
F_13 ( & V_26 -> V_31 ) ;
return V_11 ;
}
static int
F_15 ( struct V_1 * V_26 , T_2 * V_8 , T_2 V_16 )
{
T_2 * V_9 = V_26 -> V_9 ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_34 = {
. V_16 = 2 ,
. V_17 = V_9 ,
} ;
struct V_14 V_35 = {
. V_16 = V_16 ,
. V_17 = V_8 ,
} ;
F_12 ( & V_26 -> V_31 ) ;
V_9 [ 0 ] = V_28 | V_36 ;
V_9 [ 1 ] = V_16 + 2 ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
F_5 ( & V_13 ) ;
F_6 ( & V_34 , & V_13 ) ;
F_6 ( & V_35 , & V_13 ) ;
V_11 = F_7 ( V_26 -> V_5 , & V_13 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
if ( V_13 . V_11 )
V_11 = V_13 . V_11 ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
F_13 ( & V_26 -> V_31 ) ;
return V_11 ;
}
static int
F_16 ( struct V_1 * V_26 , T_2 * V_8 , T_2 * V_16 , T_2 * V_37 )
{
T_2 * V_9 = V_26 -> V_9 ;
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_34 = {
. V_16 = 2 ,
. V_17 = V_9 ,
. V_18 = V_9 ,
} ;
struct V_14 V_38 = {
. V_16 = 2 ,
. V_17 = V_9 ,
. V_18 = V_9 ,
} ;
struct V_14 V_35 = {
. V_16 = 0 ,
. V_18 = V_8 ,
} ;
F_12 ( & V_26 -> V_31 ) ;
V_9 [ 0 ] = V_36 ;
V_9 [ 1 ] = 0x00 ;
F_5 ( & V_13 ) ;
F_6 ( & V_34 , & V_13 ) ;
V_11 = F_7 ( V_26 -> V_5 , & V_13 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
V_35 . V_16 = * ( V_9 + 1 ) + 1 ;
* V_16 = V_9 [ 1 ] ;
V_9 [ 0 ] = V_36 ;
V_9 [ 1 ] = 0x00 ;
F_5 ( & V_13 ) ;
F_6 ( & V_38 , & V_13 ) ;
F_6 ( & V_35 , & V_13 ) ;
V_11 = F_7 ( V_26 -> V_5 , & V_13 ) ;
if ( V_13 . V_11 )
V_11 = V_13 . V_11 ;
F_4 ( & V_26 -> V_5 -> V_25 , L_2 , V_11 ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_1 , V_9 [ 0 ] ) ;
F_4 ( & V_26 -> V_5 -> V_25 , L_3 , V_9 [ 1 ] ) ;
if ( V_11 ) {
if ( V_37 && ( * V_16 > V_26 -> V_9 [ 1 ] ) )
* V_37 = V_8 [ V_26 -> V_9 [ 1 ] ] ;
}
F_13 ( & V_26 -> V_31 ) ;
return V_11 ;
}
static int
F_17 ( struct V_39 * V_25 , T_2 * V_40 )
{
F_18 () ;
F_19 ( ! V_40 ) ;
* V_40 = 0xbe ;
return 0 ;
}
static int
F_20 ( struct V_39 * V_25 , int V_41 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
int V_43 ;
T_2 V_32 ;
T_2 V_44 ;
F_18 () ;
if ( V_41 == V_45 )
V_44 = V_46 ;
else if ( V_41 == V_47 )
V_44 = V_48 ;
else
V_44 = V_41 ;
do {
V_43 = F_11 ( V_26 , V_49 , & V_32 ) ;
if ( V_43 )
goto V_50;
} while ( V_32 == V_51 );
if ( V_32 == V_44 )
return 0 ;
V_43 = F_14 ( V_26 , V_52 , V_41 ) ;
if ( V_43 )
goto V_50;
do {
V_43 = F_11 ( V_26 , V_49 , & V_32 ) ;
if ( V_43 )
goto V_50;
} while ( V_32 == V_51 );
if ( V_32 == V_44 ||
( V_44 == V_53 && V_32 == V_54 ) ||
( V_44 == V_55 && V_32 == V_56 ) )
return 0 ;
F_21 ( L_4 , V_32 , V_41 ) ;
return - V_57 ;
V_50:
F_21 ( L_5 , V_43 ) ;
return V_43 ;
}
static int
F_22 ( struct V_39 * V_25 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
T_2 V_43 ;
V_43 = F_14 ( V_26 , V_58 , 1 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_20 ( V_25 , V_46 ) ;
if ( V_43 )
return V_43 ;
return F_20 ( V_25 , V_55 ) ;
}
static void
F_23 ( struct V_39 * V_25 )
{
F_20 ( V_25 , V_47 ) ;
}
static int
F_24 ( struct V_1 * V_26 , int V_59 , int V_60 )
{
V_26 -> V_61 = - 91 ;
return F_14 ( V_26 , V_62 , V_60 ) ;
}
static int
F_25 ( struct V_1 * V_26 , int V_59 , int V_60 )
{
int V_43 ;
if ( V_60 == 0 )
V_43 = F_14 ( V_26 , V_63 , 0 ) ;
else
V_43 = F_14 ( V_26 , V_63 , 1 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_59 == 0 ) {
V_43 = F_14 ( V_26 , V_64 , 0 ) ;
V_26 -> V_61 = - 100 ;
} else {
V_43 = F_14 ( V_26 , V_64 , 1 ) ;
V_26 -> V_61 = - 98 ;
}
if ( V_43 < 0 )
return V_43 ;
return F_14 ( V_26 , V_62 , V_60 ) ;
}
static int
F_26 ( struct V_39 * V_25 , int V_59 , int V_60 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
int V_43 ;
F_18 () ;
if ( V_59 < 0 || V_59 > 31 ||
! ( V_26 -> V_25 -> V_65 -> V_66 [ V_59 ] & F_27 ( V_60 ) ) ) {
F_28 ( 1 ) ;
return - V_67 ;
}
if ( F_1 ( V_26 ) )
V_43 = F_25 ( V_26 , V_59 , V_60 ) ;
else
V_43 = F_24 ( V_26 , V_59 , V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
F_29 ( 1 ) ;
V_25 -> V_65 -> V_68 = V_60 ;
V_25 -> V_65 -> V_69 = V_59 ;
return 0 ;
}
static int
F_30 ( struct V_39 * V_25 , struct V_70 * V_71 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
int V_43 ;
unsigned long V_72 ;
F_31 ( & V_26 -> V_73 , V_72 ) ;
if ( V_26 -> V_74 ) {
F_32 ( & V_26 -> V_73 , V_72 ) ;
return - V_57 ;
}
F_32 ( & V_26 -> V_73 , V_72 ) ;
F_18 () ;
V_43 = F_20 ( V_25 , V_45 ) ;
if ( V_43 )
goto V_50;
F_31 ( & V_26 -> V_73 , V_72 ) ;
V_26 -> V_75 = 1 ;
F_33 ( & V_26 -> V_76 ) ;
F_32 ( & V_26 -> V_73 , V_72 ) ;
V_43 = F_15 ( V_26 , V_71 -> V_8 , V_71 -> V_16 ) ;
if ( V_43 )
goto V_77;
if ( V_26 -> V_78 ) {
V_43 = F_14 ( V_26 , V_52 , V_79 ) ;
if ( V_43 )
goto V_77;
}
V_43 = F_14 ( V_26 , V_52 , V_80 ) ;
if ( V_43 )
goto V_77;
V_43 = F_34 ( & V_26 -> V_76 ) ;
if ( V_43 < 0 )
goto V_77;
V_43 = F_22 ( V_25 ) ;
return V_43 ;
V_77:
F_22 ( V_25 ) ;
V_50:
F_21 ( L_5 , V_43 ) ;
F_31 ( & V_26 -> V_73 , V_72 ) ;
V_26 -> V_75 = 0 ;
F_32 ( & V_26 -> V_73 , V_72 ) ;
return V_43 ;
}
static int F_35 ( struct V_1 * V_26 )
{
T_2 V_16 = 128 , V_37 = 0 ;
struct V_70 * V_71 ;
V_71 = F_36 ( V_16 , V_10 ) ;
if ( ! V_71 )
return - V_20 ;
if ( F_16 ( V_26 , F_37 ( V_71 , V_16 ) , & V_16 , & V_37 ) )
goto V_50;
if ( V_16 < 2 )
goto V_50;
F_38 ( V_71 , V_16 - 2 ) ;
F_39 ( V_26 -> V_25 , V_71 , V_37 ) ;
F_40 ( & V_26 -> V_5 -> V_25 , L_6 , V_16 , V_37 ) ;
return 0 ;
V_50:
F_41 ( L_7 ) ;
F_42 ( V_71 ) ;
return - V_67 ;
}
static int
F_43 ( struct V_39 * V_25 ,
struct V_81 * V_82 ,
unsigned long V_83 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
if ( V_83 & V_84 ) {
T_1 V_27 = F_44 ( V_82 -> V_85 ) ;
F_4 ( & V_26 -> V_5 -> V_25 ,
L_8 ) ;
F_9 ( V_26 , V_86 , V_27 ) ;
F_9 ( V_26 , V_87 , V_27 >> 8 ) ;
}
if ( V_83 & V_88 ) {
T_1 V_89 = F_44 ( V_82 -> V_90 ) ;
F_4 ( & V_26 -> V_5 -> V_25 ,
L_9 ) ;
F_9 ( V_26 , V_91 , V_89 ) ;
F_9 ( V_26 , V_92 , V_89 >> 8 ) ;
}
if ( V_83 & V_93 ) {
T_2 V_94 , V_27 [ 8 ] ;
memcpy ( V_27 , & V_82 -> V_95 , 8 ) ;
F_4 ( & V_26 -> V_5 -> V_25 ,
L_10 ) ;
for ( V_94 = 0 ; V_94 < 8 ; V_94 ++ )
F_9 ( V_26 , V_96 + V_94 , V_27 [ V_94 ] ) ;
}
if ( V_83 & V_97 ) {
F_4 ( & V_26 -> V_5 -> V_25 ,
L_11 ) ;
if ( V_82 -> V_98 )
F_14 ( V_26 , V_99 , 1 ) ;
else
F_14 ( V_26 , V_99 , 0 ) ;
}
return 0 ;
}
static int
F_45 ( struct V_39 * V_25 , int V_100 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
if ( V_100 > 5 || V_100 < - 26 )
return - V_67 ;
V_100 = - ( V_100 - 5 ) ;
return F_9 ( V_26 , V_101 , 0x60 | V_100 ) ;
}
static int
F_46 ( struct V_39 * V_25 , bool V_102 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
return F_14 ( V_26 , V_103 , V_102 ) ;
}
static int
F_47 ( struct V_39 * V_25 , T_2 V_104 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
return F_14 ( V_26 , V_105 , V_104 ) ;
}
static int
F_48 ( struct V_39 * V_25 , T_3 V_40 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
int V_106 ;
if ( V_40 < V_26 -> V_61 || V_40 > 30 )
return - V_67 ;
V_106 = ( V_40 - V_26 -> V_61 ) * 100 / 207 ;
return F_14 ( V_26 , V_107 , V_106 ) ;
}
static int
F_49 ( struct V_39 * V_25 , T_2 V_108 , T_2 V_109 ,
T_2 V_110 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
int V_43 ;
if ( V_108 > V_109 || V_109 > 8 || V_110 > 5 )
return - V_67 ;
V_43 = F_14 ( V_26 , V_111 , V_108 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_26 , V_112 , V_109 ) ;
if ( V_43 )
return V_43 ;
return F_14 ( V_26 , V_113 , V_110 ) ;
}
static int
F_50 ( struct V_39 * V_25 , T_4 V_110 )
{
struct V_1 * V_26 = V_25 -> V_42 ;
int V_43 = 0 ;
if ( V_110 < - 1 || V_110 > 15 )
return - V_67 ;
V_26 -> V_78 = V_110 >= 0 ;
if ( V_110 >= 0 )
V_43 = F_14 ( V_26 , V_114 , V_110 ) ;
return V_43 ;
}
static void F_51 ( struct V_115 * V_116 )
{
struct V_1 * V_26 =
F_52 ( V_116 , struct V_1 , V_117 ) ;
T_2 V_11 = 0 , V_32 ;
int V_43 ;
unsigned long V_72 ;
V_43 = F_11 ( V_26 , V_118 , 0xff , 0 , & V_32 ) ;
V_11 |= V_32 ;
V_11 &= ~ V_119 ;
V_11 &= ~ V_120 ;
V_11 &= ~ V_121 ;
V_11 &= ~ V_122 ;
if ( V_11 & V_123 ) {
V_11 &= ~ V_123 ;
F_31 ( & V_26 -> V_73 , V_72 ) ;
if ( V_26 -> V_75 ) {
V_26 -> V_75 = 0 ;
F_32 ( & V_26 -> V_73 , V_72 ) ;
F_53 ( & V_26 -> V_76 ) ;
} else {
F_32 ( & V_26 -> V_73 , V_72 ) ;
F_35 ( V_26 ) ;
}
}
F_31 ( & V_26 -> V_73 , V_72 ) ;
V_26 -> V_74 = 0 ;
F_32 ( & V_26 -> V_73 , V_72 ) ;
}
static void F_54 ( struct V_115 * V_116 )
{
struct V_1 * V_26 =
F_52 ( V_116 , struct V_1 , V_117 ) ;
F_51 ( V_116 ) ;
F_55 ( V_26 -> V_5 -> V_124 ) ;
}
static T_5 F_56 ( int V_124 , void * V_8 )
{
struct V_1 * V_26 = V_8 ;
unsigned long V_72 ;
F_31 ( & V_26 -> V_73 , V_72 ) ;
V_26 -> V_74 = 1 ;
F_32 ( & V_26 -> V_73 , V_72 ) ;
F_57 ( & V_26 -> V_117 ) ;
return V_125 ;
}
static T_5 F_58 ( int V_124 , void * V_8 )
{
F_59 ( V_124 ) ;
return F_56 ( V_124 , V_8 ) ;
}
static int F_60 ( struct V_1 * V_26 , int V_126 )
{
return F_14 ( V_26 , V_127 , V_126 ) ;
}
static int F_61 ( struct V_1 * V_26 )
{
struct V_128 * V_129 = V_26 -> V_5 -> V_25 . V_130 ;
int V_43 , V_131 ;
T_2 V_11 ;
T_2 V_132 [ 2 ] ;
V_43 = F_11 ( V_26 , V_49 , & V_11 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_26 , V_52 , V_47 ) ;
if ( V_43 )
return V_43 ;
if ( V_129 -> V_133 & ( V_134 | V_135 ) )
V_131 = V_136 ;
else
V_131 = V_137 ;
V_43 = F_60 ( V_26 , V_131 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_26 , V_138 , V_123 ) ;
if ( V_43 )
return V_43 ;
F_62 ( V_132 , F_63 ( V_132 ) ) ;
V_43 = F_14 ( V_26 , V_139 , V_132 [ 0 ] ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_26 , V_140 , V_132 [ 1 ] ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_26 , V_141 , 0x00 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( V_26 , V_142 , 0x00 ) ;
if ( V_43 )
return V_43 ;
F_29 ( 100 ) ;
V_43 = F_11 ( V_26 , V_143 , & V_11 ) ;
if ( V_43 )
return V_43 ;
if ( ! V_11 ) {
F_64 ( & V_26 -> V_5 -> V_25 , L_12 ) ;
return - V_67 ;
}
return 0 ;
}
static struct V_128 *
F_65 ( struct V_4 * V_5 )
{
struct V_128 * V_129 ;
const char * V_133 ;
if ( ! F_66 ( V_144 ) || ! V_5 -> V_25 . V_145 )
return V_5 -> V_25 . V_130 ;
V_129 = F_67 ( & V_5 -> V_25 , sizeof( * V_129 ) , V_10 ) ;
if ( ! V_129 )
goto V_146;
V_129 -> V_147 = F_68 ( V_5 -> V_25 . V_145 , L_13 , 0 ) ;
V_129 -> V_148 = F_68 ( V_5 -> V_25 . V_145 , L_14 , 0 ) ;
V_129 -> V_133 = V_149 ;
F_69 ( V_5 -> V_25 . V_145 , L_15 , & V_133 ) ;
if ( ! strcmp ( V_133 , L_16 ) )
V_129 -> V_133 = V_150 ;
else if ( ! strcmp ( V_133 , L_17 ) )
V_129 -> V_133 = V_135 ;
else if ( ! strcmp ( V_133 , L_18 ) )
V_129 -> V_133 = V_149 ;
else if ( ! strcmp ( V_133 , L_19 ) )
V_129 -> V_133 = V_134 ;
else
F_70 ( & V_5 -> V_25 , L_20 ) ;
V_5 -> V_25 . V_130 = V_129 ;
V_146:
return V_129 ;
}
static int F_71 ( struct V_4 * V_5 )
{
struct V_128 * V_129 ;
struct V_39 * V_25 ;
struct V_1 * V_26 ;
T_1 V_6 = 0 ;
T_2 V_3 = 0 , V_7 = 0 , V_11 ;
T_6 V_151 ;
T_7 V_152 ;
int V_43 ;
const char * V_153 ;
struct V_154 * V_155 = NULL ;
if ( ! V_5 -> V_124 ) {
F_64 ( & V_5 -> V_25 , L_21 ) ;
return - V_67 ;
}
V_129 = F_65 ( V_5 ) ;
if ( ! V_129 ) {
F_64 ( & V_5 -> V_25 , L_22 ) ;
return - V_67 ;
}
if ( F_72 ( V_129 -> V_147 ) ) {
V_43 = F_73 ( V_129 -> V_147 , L_23 ) ;
if ( V_43 )
return V_43 ;
}
if ( F_72 ( V_129 -> V_148 ) ) {
V_43 = F_73 ( V_129 -> V_148 , L_24 ) ;
if ( V_43 )
goto V_156;
}
if ( F_72 ( V_129 -> V_147 ) ) {
V_43 = F_74 ( V_129 -> V_147 , 1 ) ;
if ( V_43 )
goto V_157;
}
if ( F_72 ( V_129 -> V_148 ) ) {
V_43 = F_74 ( V_129 -> V_148 , 0 ) ;
if ( V_43 )
goto V_157;
}
if ( F_72 ( V_129 -> V_147 ) ) {
F_75 ( 1 ) ;
F_76 ( V_129 -> V_147 , 0 ) ;
F_75 ( 1 ) ;
F_76 ( V_129 -> V_147 , 1 ) ;
F_77 ( 120 , 240 ) ;
}
V_43 = F_2 ( V_5 , & V_6 , & V_3 , & V_7 ) ;
if ( V_43 < 0 )
goto V_157;
if ( V_6 != 0x001f ) {
F_64 ( & V_5 -> V_25 , L_25 ,
V_6 >> 8 , V_6 & 0xFF ) ;
V_43 = - V_67 ;
goto V_157;
}
switch ( V_3 ) {
case 2 :
V_153 = L_26 ;
break;
case 3 :
V_153 = L_27 ;
V_155 = & V_158 ;
break;
case 7 :
V_153 = L_28 ;
if ( V_7 == 1 )
V_155 = & V_159 ;
break;
case 11 :
V_153 = L_29 ;
V_155 = & V_158 ;
break;
default:
V_153 = L_30 ;
break;
}
F_78 ( & V_5 -> V_25 , L_31 , V_153 , V_7 ) ;
if ( ! V_155 ) {
V_43 = - V_160 ;
goto V_157;
}
V_25 = F_79 ( sizeof( * V_26 ) , V_155 ) ;
if ( ! V_25 ) {
V_43 = - V_20 ;
goto V_157;
}
V_26 = V_25 -> V_42 ;
V_26 -> V_25 = V_25 ;
V_26 -> V_3 = V_3 ;
V_26 -> V_161 = V_7 ;
V_26 -> V_5 = V_5 ;
V_25 -> V_162 = & V_5 -> V_25 ;
V_25 -> V_163 = 0 ;
V_25 -> V_72 = V_164 | V_165 ;
if ( V_129 -> V_133 & ( V_149 | V_134 ) ) {
V_152 = F_51 ;
V_151 = F_56 ;
} else {
V_152 = F_54 ;
V_151 = F_58 ;
}
F_80 ( & V_26 -> V_31 ) ;
F_81 ( & V_26 -> V_117 , V_152 ) ;
F_82 ( & V_26 -> V_73 ) ;
F_83 ( & V_26 -> V_76 ) ;
F_84 ( V_5 , V_26 ) ;
if ( F_1 ( V_26 ) ) {
V_25 -> V_65 -> V_66 [ 0 ] = 0x00007FF ;
V_25 -> V_65 -> V_66 [ 2 ] = 0x00007FF ;
} else {
V_25 -> V_65 -> V_66 [ 0 ] = 0x7FFF800 ;
}
V_43 = F_61 ( V_26 ) ;
if ( V_43 )
goto V_166;
V_43 = F_85 ( V_5 -> V_124 , V_151 ,
V_167 | V_129 -> V_133 ,
F_86 ( & V_5 -> V_25 ) , V_26 ) ;
if ( V_43 )
goto V_166;
V_43 = F_11 ( V_26 , V_118 , 0xff , 0 , & V_11 ) ;
if ( V_43 )
goto V_168;
V_43 = F_87 ( V_26 -> V_25 ) ;
if ( V_43 )
goto V_168;
return V_43 ;
V_168:
F_88 ( V_5 -> V_124 , V_26 ) ;
V_166:
F_89 ( & V_26 -> V_117 ) ;
F_84 ( V_5 , NULL ) ;
F_90 ( & V_26 -> V_31 ) ;
F_91 ( V_26 -> V_25 ) ;
V_157:
if ( F_72 ( V_129 -> V_148 ) )
F_92 ( V_129 -> V_148 ) ;
V_156:
if ( F_72 ( V_129 -> V_147 ) )
F_92 ( V_129 -> V_147 ) ;
return V_43 ;
}
static int F_93 ( struct V_4 * V_5 )
{
struct V_1 * V_26 = F_94 ( V_5 ) ;
struct V_128 * V_129 = V_5 -> V_25 . V_130 ;
F_14 ( V_26 , V_138 , 0 ) ;
F_95 ( V_26 -> V_25 ) ;
F_88 ( V_5 -> V_124 , V_26 ) ;
F_89 ( & V_26 -> V_117 ) ;
if ( F_72 ( V_129 -> V_148 ) )
F_92 ( V_129 -> V_148 ) ;
if ( F_72 ( V_129 -> V_147 ) )
F_92 ( V_129 -> V_147 ) ;
F_90 ( & V_26 -> V_31 ) ;
F_91 ( V_26 -> V_25 ) ;
F_40 ( & V_5 -> V_25 , L_32 ) ;
return 0 ;
}
