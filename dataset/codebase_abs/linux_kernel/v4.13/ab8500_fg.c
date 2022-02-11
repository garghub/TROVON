struct V_1 * F_1 ( void )
{
return F_2 ( & V_2 , struct V_1 ,
V_3 ) ;
}
static T_1 F_3 ( int V_4 )
{
int V_5 ;
if ( V_4 < V_6 [ 0 ] )
return 0 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_6 ) ; V_5 ++ ) {
if ( V_4 < V_6 [ V_5 ] )
return ( T_1 ) V_5 - 1 ;
}
return ( T_1 ) F_4 ( V_6 ) - 1 ;
}
static int F_5 ( struct V_1 * V_7 , int V_8 )
{
if ( V_8 > - V_7 -> V_9 -> V_10 -> V_11 )
return true ;
else
return false ;
}
static int F_6 ( struct V_1 * V_7 , int V_12 )
{
struct V_13 V_14 ;
struct V_15 * V_16 = & V_7 -> V_17 ;
F_7 ( & V_14 ) ;
do {
V_16 -> V_18 += V_12 - V_16 -> V_19 [ V_16 -> V_20 ] ;
V_16 -> V_19 [ V_16 -> V_20 ] = V_12 ;
V_16 -> V_21 [ V_16 -> V_20 ] = V_14 . V_22 ;
V_16 -> V_20 ++ ;
if ( V_16 -> V_20 == V_23 )
V_16 -> V_20 = 0 ;
if ( V_16 -> V_24 < V_23 )
V_16 -> V_24 ++ ;
} while ( V_14 . V_22 - V_25 > V_16 -> V_21 [ V_16 -> V_20 ] );
V_16 -> V_16 = V_16 -> V_18 / V_16 -> V_24 ;
return V_16 -> V_16 ;
}
static void F_8 ( struct V_1 * V_7 )
{
int V_5 ;
struct V_15 * V_16 = & V_7 -> V_17 ;
V_16 -> V_20 = 0 ;
V_16 -> V_24 = 0 ;
V_16 -> V_18 = 0 ;
V_16 -> V_16 = 0 ;
for ( V_5 = 0 ; V_5 < V_23 ; V_5 ++ ) {
V_16 -> V_19 [ V_5 ] = 0 ;
V_16 -> V_21 [ V_5 ] = 0 ;
}
}
static void F_9 ( struct V_1 * V_7 , int V_12 )
{
int V_5 ;
struct V_13 V_14 ;
struct V_15 * V_16 = & V_7 -> V_17 ;
F_7 ( & V_14 ) ;
for ( V_5 = 0 ; V_5 < V_23 ; V_5 ++ ) {
V_16 -> V_19 [ V_5 ] = V_12 ;
V_16 -> V_21 [ V_5 ] = V_14 . V_22 ;
}
V_16 -> V_20 = 0 ;
V_16 -> V_24 = V_23 ;
V_16 -> V_18 = V_12 * V_23 ;
V_16 -> V_16 = V_12 ;
}
static int F_10 ( struct V_1 * V_7 , bool V_26 )
{
int V_27 = 0 ;
F_11 ( & V_7 -> V_28 ) ;
if ( V_26 ) {
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_31 , 0x00 ) ;
if ( V_27 )
goto V_32;
V_27 = F_12 ( V_7 -> V_29 ,
V_33 , V_34 ,
V_7 -> V_35 ) ;
if ( V_27 )
goto V_32;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_31 ,
( V_36 | V_37 ) ) ;
if ( V_27 )
goto V_32;
V_7 -> V_38 . V_39 = true ;
} else {
V_27 = F_13 ( V_7 -> V_29 ,
V_33 , V_40 ,
( V_41 | V_42 ) , 0 ) ;
if ( V_27 )
goto V_32;
V_27 = F_12 ( V_7 -> V_29 ,
V_33 , V_43 , 0 ) ;
if ( V_27 )
goto V_32;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_31 , 0 ) ;
if ( V_27 )
goto V_32;
V_7 -> V_38 . V_39 = false ;
}
F_14 ( V_7 -> V_29 , L_1 ,
V_26 , V_7 -> V_35 ) ;
F_15 ( & V_7 -> V_28 ) ;
return V_27 ;
V_32:
F_16 ( V_7 -> V_29 , L_2 , V_44 ) ;
F_15 ( & V_7 -> V_28 ) ;
return V_27 ;
}
int F_17 ( struct V_1 * V_7 )
{
T_1 V_45 ;
int V_27 ;
F_11 ( & V_7 -> V_28 ) ;
V_7 -> V_46 = 0 ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_31 , & V_45 ) ;
if ( V_27 < 0 )
goto V_47;
if ( ! ( V_45 & V_37 ) ) {
F_14 ( V_7 -> V_29 , L_3 , V_44 ) ;
V_7 -> V_48 = true ;
V_27 = F_12 ( V_7 -> V_29 ,
V_33 , V_34 ,
F_19 ( 10 ) ) ;
if ( V_27 )
goto V_47;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_31 ,
( V_36 | V_37 ) ) ;
if ( V_27 )
goto V_47;
} else {
V_7 -> V_48 = false ;
}
F_20 ( & V_7 -> V_49 ) ;
F_20 ( & V_7 -> V_50 ) ;
F_21 ( V_7 -> V_51 ) ;
return 0 ;
V_47:
F_15 ( & V_7 -> V_28 ) ;
return V_27 ;
}
int F_22 ( struct V_1 * V_7 )
{
return F_23 ( & V_7 -> V_49 ) ;
}
int F_24 ( struct V_1 * V_7 )
{
return F_23 ( & V_7 -> V_50 ) ;
}
int F_25 ( struct V_1 * V_7 , int * V_52 )
{
T_1 V_53 , V_54 ;
int V_55 ;
int V_27 ;
unsigned long V_56 ;
if ( ! F_23 ( & V_7 -> V_50 ) ) {
V_56 = F_26 (
& V_7 -> V_50 ,
V_57 ) ;
F_14 ( V_7 -> V_29 , L_4 ,
F_27 ( V_57 - V_56 ) ) ;
if ( ! V_56 ) {
V_27 = - V_58 ;
F_28 ( V_7 -> V_51 ) ;
V_7 -> V_46 = 0 ;
F_16 ( V_7 -> V_29 , L_5 ,
__LINE__ ) ;
goto V_47;
}
}
F_28 ( V_7 -> V_51 ) ;
V_7 -> V_46 = 0 ;
V_27 = F_13 ( V_7 -> V_29 ,
V_33 , V_40 ,
V_42 , V_42 ) ;
F_29 ( 100 , 100 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_33 ,
V_59 , & V_53 ) ;
if ( V_27 < 0 )
goto V_47;
V_27 = F_18 ( V_7 -> V_29 , V_33 ,
V_60 , & V_54 ) ;
if ( V_27 < 0 )
goto V_47;
if ( V_54 & 0x10 )
V_55 = ( V_53 | ( V_54 << 8 ) | 0xFFFFE000 ) ;
else
V_55 = ( V_53 | ( V_54 << 8 ) ) ;
V_55 = ( V_55 * V_61 * 36 * 4 ) /
( 1000 * V_7 -> V_9 -> V_62 ) ;
if ( V_7 -> V_48 ) {
F_14 ( V_7 -> V_29 , L_6 , V_44 ) ;
V_27 = F_12 ( V_7 -> V_29 ,
V_33 , V_40 , 0 ) ;
if ( V_27 )
goto V_47;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_31 , 0 ) ;
if ( V_27 )
goto V_47;
}
F_15 ( & V_7 -> V_28 ) ;
( * V_52 ) = V_55 ;
return 0 ;
V_47:
F_15 ( & V_7 -> V_28 ) ;
return V_27 ;
}
int F_30 ( struct V_1 * V_7 )
{
int V_27 ;
unsigned long V_56 ;
int V_52 = 0 ;
V_27 = F_17 ( V_7 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_7 ) ;
return 0 ;
}
if ( ! F_23 ( & V_7 -> V_49 ) ) {
V_56 = F_26 (
& V_7 -> V_49 ,
V_57 ) ;
F_14 ( V_7 -> V_29 , L_8 ,
F_27 ( V_57 - V_56 ) ) ;
if ( ! V_56 ) {
V_27 = - V_58 ;
F_16 ( V_7 -> V_29 , L_5 ,
__LINE__ ) ;
goto V_47;
}
}
V_27 = F_25 ( V_7 , & V_52 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_9 ) ;
return 0 ;
}
F_14 ( V_7 -> V_29 , L_10 , V_44 , V_52 ) ;
return V_52 ;
V_47:
F_28 ( V_7 -> V_51 ) ;
F_15 ( & V_7 -> V_28 ) ;
return V_27 ;
}
static void F_31 ( struct V_63 * V_64 )
{
int V_55 ;
int V_27 ;
T_1 V_53 , V_65 , V_54 ;
struct V_1 * V_7 = F_32 ( V_64 ,
struct V_1 , V_66 ) ;
F_11 ( & V_7 -> V_28 ) ;
V_27 = F_12 ( V_7 -> V_29 , V_33 ,
V_43 , V_67 ) ;
if ( V_27 )
goto exit;
V_27 = F_18 ( V_7 -> V_29 , V_33 ,
V_68 , & V_53 ) ;
if ( V_27 < 0 )
goto exit;
V_27 = F_18 ( V_7 -> V_29 , V_33 ,
V_69 , & V_65 ) ;
if ( V_27 < 0 )
goto exit;
V_27 = F_18 ( V_7 -> V_29 , V_33 ,
V_70 , & V_54 ) ;
if ( V_27 < 0 )
goto exit;
if ( V_54 & 0x10 )
V_55 = ( V_53 | ( V_65 << 8 ) | ( V_54 << 16 ) | 0xFFE00000 ) ;
else
V_55 = ( V_53 | ( V_65 << 8 ) | ( V_54 << 16 ) ) ;
V_7 -> V_71 = ( V_55 * V_61 ) /
( 100 * V_7 -> V_9 -> V_62 ) ;
V_7 -> V_72 = ( V_55 * V_61 * 36 ) /
( 1000 * V_7 -> V_9 -> V_62 * ( V_7 -> V_35 / 4 ) ) ;
V_7 -> V_38 . V_73 = true ;
F_15 ( & V_7 -> V_28 ) ;
F_33 ( V_7 -> V_74 , & V_7 -> V_75 ) ;
F_14 ( V_7 -> V_29 , L_11 ,
V_7 -> V_9 -> V_62 , V_7 -> V_35 , V_55 , V_7 -> V_71 ) ;
return;
exit:
F_16 ( V_7 -> V_29 ,
L_12 ) ;
F_15 ( & V_7 -> V_28 ) ;
F_33 ( V_7 -> V_74 , & V_7 -> V_75 ) ;
}
static int F_34 ( struct V_1 * V_7 )
{
int V_76 ;
static int V_77 ;
V_76 = F_35 ( V_7 -> V_78 , V_79 ) ;
if ( V_76 < 0 ) {
F_16 ( V_7 -> V_29 ,
L_13 ,
V_44 ) ;
return V_77 ;
}
V_77 = V_76 ;
return V_76 ;
}
static int F_36 ( struct V_1 * V_7 , int V_4 )
{
int V_5 , V_80 ;
const struct V_81 * V_82 ;
int V_83 = 0 ;
V_82 = V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] . V_86 ,
V_80 = V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] . V_87 ;
for ( V_5 = 0 ; V_5 < V_80 ; ++ V_5 ) {
if ( V_4 > V_82 [ V_5 ] . V_4 )
break;
}
if ( ( V_5 > 0 ) && ( V_5 < V_80 ) ) {
V_83 = F_37 ( V_4 ,
V_82 [ V_5 ] . V_4 ,
V_82 [ V_5 ] . V_88 * 10 ,
V_82 [ V_5 - 1 ] . V_4 ,
V_82 [ V_5 - 1 ] . V_88 * 10 ) ;
} else if ( V_5 == 0 ) {
V_83 = 1000 ;
} else {
V_83 = 0 ;
}
F_14 ( V_7 -> V_29 , L_14 ,
V_44 , V_4 , V_83 ) ;
return V_83 ;
}
static int F_38 ( struct V_1 * V_7 )
{
V_7 -> V_76 = F_34 ( V_7 ) ;
return F_36 ( V_7 , V_7 -> V_76 ) ;
}
static int F_39 ( struct V_1 * V_7 )
{
int V_5 , V_80 ;
const struct V_89 * V_82 ;
int V_90 = 0 ;
V_82 = V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] . V_91 ;
V_80 = V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] . V_92 ;
for ( V_5 = 0 ; V_5 < V_80 ; ++ V_5 ) {
if ( V_7 -> V_93 / 10 > V_82 [ V_5 ] . V_94 )
break;
}
if ( ( V_5 > 0 ) && ( V_5 < V_80 ) ) {
V_90 = F_37 ( V_7 -> V_93 / 10 ,
V_82 [ V_5 ] . V_94 ,
V_82 [ V_5 ] . V_90 ,
V_82 [ V_5 - 1 ] . V_94 ,
V_82 [ V_5 - 1 ] . V_90 ) ;
} else if ( V_5 == 0 ) {
V_90 = V_82 [ 0 ] . V_90 ;
} else {
V_90 = V_82 [ V_80 - 1 ] . V_90 ;
}
F_14 ( V_7 -> V_29 , L_15
L_16 ,
V_44 , V_7 -> V_93 , V_90 , V_7 -> V_9 -> V_62 / 10 ,
( V_7 -> V_9 -> V_62 / 10 ) + V_90 ) ;
V_90 += V_7 -> V_9 -> V_62 / 10 ;
return V_90 ;
}
static int F_40 ( struct V_1 * V_7 )
{
int V_95 , V_52 ;
int V_5 = 0 ;
int V_76 = 0 ;
F_17 ( V_7 ) ;
do {
V_76 += F_34 ( V_7 ) ;
V_5 ++ ;
F_29 ( 5000 , 6000 ) ;
} while ( ! F_24 ( V_7 ) );
F_25 ( V_7 , & V_7 -> V_96 ) ;
V_7 -> V_76 = V_76 / V_5 ;
V_52 = F_39 ( V_7 ) ;
V_95 = V_7 -> V_76 - ( V_7 -> V_96 * V_52 ) / 1000 ;
F_14 ( V_7 -> V_29 , L_17
L_18 ,
V_44 , V_7 -> V_76 , V_95 , V_52 , V_7 -> V_96 , V_5 ) ;
return F_36 ( V_7 , V_95 ) ;
}
static int F_41 ( struct V_1 * V_7 , int V_97 )
{
return ( V_97 * 1000 ) / V_7 -> V_98 . V_99 ;
}
static int F_42 ( struct V_1 * V_7 , int V_100 )
{
return V_100 * V_7 -> V_98 . V_99 / 1000 ;
}
static int F_43 ( struct V_1 * V_7 , int V_97 )
{
T_2 V_101 ;
T_3 V_102 ;
V_101 = ( ( T_2 ) V_97 ) * ( ( T_2 ) V_7 -> V_103 ) ;
V_102 = F_44 ( V_101 , 1000 ) ;
if ( V_102 >= 1000 / 2 )
V_101 ++ ;
return ( int ) V_101 ;
}
static int F_45 ( struct V_1 * V_7 )
{
F_14 ( V_7 -> V_29 , L_19 ,
V_44 ,
V_7 -> V_98 . V_104 ,
V_7 -> V_71 ) ;
if ( V_7 -> V_98 . V_104 + V_7 -> V_71 > 0 )
V_7 -> V_98 . V_104 += V_7 -> V_71 ;
else
V_7 -> V_98 . V_104 = 0 ;
if ( V_7 -> V_98 . V_104 >= V_7 -> V_98 . V_99 ||
V_7 -> V_38 . V_105 ) {
V_7 -> V_98 . V_104 = V_7 -> V_98 . V_99 ;
}
F_9 ( V_7 , V_7 -> V_98 . V_104 ) ;
V_7 -> V_98 . V_106 =
F_41 ( V_7 , V_7 -> V_98 . V_104 ) ;
V_7 -> V_76 = F_34 ( V_7 ) ;
V_7 -> V_96 = F_30 ( V_7 ) ;
return V_7 -> V_98 . V_104 ;
}
static int F_46 ( struct V_1 * V_7 , bool V_107 )
{
int V_106 , V_104 ;
if ( V_107 )
V_106 = F_40 ( V_7 ) ;
else
V_106 = F_38 ( V_7 ) ;
V_104 = F_42 ( V_7 , V_106 ) ;
V_7 -> V_98 . V_104 = F_6 ( V_7 , V_104 ) ;
V_7 -> V_98 . V_106 =
F_41 ( V_7 , V_7 -> V_98 . V_104 ) ;
return V_7 -> V_98 . V_104 ;
}
static int F_47 ( struct V_1 * V_7 )
{
int V_108 , V_106 ;
F_14 ( V_7 -> V_29 , L_19 ,
V_44 ,
V_7 -> V_98 . V_104 ,
V_7 -> V_71 ) ;
if ( V_7 -> V_98 . V_104 + V_7 -> V_71 > 0 )
V_7 -> V_98 . V_104 += V_7 -> V_71 ;
else
V_7 -> V_98 . V_104 = 0 ;
if ( V_7 -> V_98 . V_104 >= V_7 -> V_98 . V_99 )
V_7 -> V_98 . V_104 = V_7 -> V_98 . V_99 ;
V_106 = F_41 ( V_7 , V_7 -> V_98 . V_104 ) ;
V_108 = F_38 ( V_7 ) ;
if ( V_106 < V_108 ) {
V_7 -> V_98 . V_106 = V_108 ;
V_7 -> V_98 . V_104 = F_42 ( V_7 ,
V_7 -> V_98 . V_106 ) ;
F_14 ( V_7 -> V_29 , L_20 ,
V_44 ,
V_106 ,
V_108 ) ;
F_9 ( V_7 , V_7 -> V_98 . V_104 ) ;
} else {
F_9 ( V_7 , V_7 -> V_98 . V_104 ) ;
V_7 -> V_98 . V_106 =
F_41 ( V_7 , V_7 -> V_98 . V_104 ) ;
}
return V_7 -> V_98 . V_104 ;
}
static int F_48 ( struct V_1 * V_7 )
{
int V_27 , V_109 ;
V_109 = F_49 ( V_7 -> V_98 . V_106 , 10 ) ;
if ( V_109 <= V_7 -> V_9 -> V_110 -> V_111 ||
V_7 -> V_38 . V_112 )
V_27 = V_113 ;
else if ( V_109 <= V_7 -> V_9 -> V_110 -> V_53 )
V_27 = V_114 ;
else if ( V_109 <= V_7 -> V_9 -> V_110 -> V_115 )
V_27 = V_116 ;
else if ( V_109 <= V_7 -> V_9 -> V_110 -> V_54 )
V_27 = V_117 ;
else
V_27 = V_118 ;
return V_27 ;
}
static int F_50 ( struct V_1 * V_7 )
{
struct V_119 * V_120 = & V_7 -> V_98 . V_121 ;
int V_88 = V_7 -> V_98 . V_122 ;
if ( ! V_120 -> V_26 )
return V_88 ;
if ( V_7 -> V_38 . V_123 ) {
V_120 -> V_124 [ 0 ] = 100 ;
V_120 -> V_124 [ 1 ] =
F_51 ( V_88 , V_7 -> V_9 -> V_10 -> V_125 ) ;
F_14 ( V_7 -> V_29 , L_21 ,
V_120 -> V_124 [ 0 ] , V_120 -> V_124 [ 1 ] ) ;
}
if ( ( V_120 -> V_124 [ 0 ] != V_120 -> V_124 [ 1 ] )
&& ( V_120 -> V_124 [ 1 ] > 0 ) )
V_88 = F_52 ( 100 ,
F_49 ( V_7 -> V_98 . V_122 *
V_120 -> V_124 [ 0 ] ,
V_120 -> V_124 [ 1 ] ) ) ;
if ( V_7 -> V_38 . V_126 ) {
if ( V_88 < V_120 -> V_127 ) {
V_120 -> V_127 = V_88 ;
F_14 ( V_7 -> V_29 , L_22 ,
V_120 -> V_127 ) ;
} else if ( ! V_7 -> V_38 . V_123 ) {
if ( V_7 -> V_98 . V_122 >=
V_120 -> V_127 ) {
F_14 ( V_7 -> V_29 , L_23 ) ;
V_120 -> V_26 = false ;
V_88 = V_7 -> V_98 . V_122 ;
} else {
F_14 ( V_7 -> V_29 ,
L_24 ,
V_120 -> V_127 ) ;
V_88 = V_120 -> V_127 ;
}
}
}
return V_88 ;
}
static void F_53 ( struct V_1 * V_7 )
{
struct V_119 * V_120 = & V_7 -> V_98 . V_121 ;
if ( ! V_120 -> V_26 )
return;
if ( V_7 -> V_38 . V_126 ) {
V_7 -> V_98 . V_121 . V_127 =
V_7 -> V_98 . V_121 . V_128 ;
F_14 ( V_7 -> V_29 , L_25 ,
V_7 -> V_98 . V_121 . V_127 ) ;
} else {
if ( V_120 -> V_128 != 100 ) {
V_120 -> V_124 [ 0 ] = V_120 -> V_128 ;
V_120 -> V_124 [ 1 ] = V_7 -> V_98 . V_122 ;
} else {
V_120 -> V_124 [ 0 ] = 100 ;
V_120 -> V_124 [ 1 ] =
F_51 ( V_7 -> V_98 . V_122 ,
V_7 -> V_9 -> V_10 -> V_125 ) ;
}
F_14 ( V_7 -> V_29 , L_26 ,
V_120 -> V_124 [ 0 ] , V_120 -> V_124 [ 1 ] ) ;
}
}
static void F_54 ( struct V_1 * V_7 , bool V_129 )
{
bool V_130 = false ;
int V_109 = F_49 ( V_7 -> V_98 . V_106 , 10 ) ;
V_7 -> V_98 . V_131 = F_48 ( V_7 ) ;
if ( V_7 -> V_98 . V_131 != V_7 -> V_98 . V_132 ) {
if ( ! ( ! V_7 -> V_38 . V_126 && V_7 -> V_98 . V_131 >
V_7 -> V_98 . V_132 ) || V_129 ) {
F_14 ( V_7 -> V_29 , L_27 ,
V_7 -> V_98 . V_132 ,
V_7 -> V_98 . V_131 ) ;
V_7 -> V_98 . V_132 = V_7 -> V_98 . V_131 ;
V_130 = true ;
} else {
F_14 ( V_7 -> V_29 , L_28
L_29 ,
V_7 -> V_98 . V_132 ,
V_7 -> V_98 . V_131 ) ;
}
}
if ( V_7 -> V_38 . V_112 ) {
F_14 ( V_7 -> V_29 , L_30 ) ;
V_7 -> V_98 . V_122 = 0 ;
V_7 -> V_98 . V_106 = 0 ;
V_109 = 0 ;
V_7 -> V_98 . V_133 = 0 ;
V_7 -> V_98 . V_104 = 0 ;
V_130 = true ;
} else if ( V_7 -> V_38 . V_123 ) {
if ( V_7 -> V_38 . V_105 ) {
V_7 -> V_98 . V_122 = V_109 ;
V_7 -> V_98 . V_133 = V_7 -> V_98 . V_104 ;
V_130 = true ;
if ( ! V_7 -> V_98 . V_121 . V_26 &&
V_7 -> V_9 -> V_134 ) {
V_7 -> V_98 . V_121 . V_26 = true ;
V_7 -> V_98 . V_121 . V_124 [ 0 ] = 100 ;
V_7 -> V_98 . V_121 . V_124 [ 1 ] =
V_7 -> V_98 . V_122 ;
V_7 -> V_98 . V_121 . V_127 = 100 ;
}
} else if ( V_7 -> V_98 . V_122 != V_109 ) {
F_14 ( V_7 -> V_29 ,
L_31
L_32 ,
V_109 ) ;
V_7 -> V_98 . V_122 = V_109 ;
V_7 -> V_98 . V_133 = V_7 -> V_98 . V_104 ;
V_130 = true ;
}
} else if ( V_7 -> V_98 . V_122 != V_109 ) {
if ( V_109 == 0 ) {
V_7 -> V_98 . V_122 = 1 ;
V_109 = 1 ;
V_130 = true ;
} else if ( ! ( ! V_7 -> V_38 . V_126 &&
V_109 > V_7 -> V_98 . V_122 ) || V_129 ) {
F_14 ( V_7 -> V_29 ,
L_33 ,
V_7 -> V_98 . V_122 ,
V_109 ,
V_7 -> V_98 . V_106 ) ;
V_7 -> V_98 . V_122 = V_109 ;
V_7 -> V_98 . V_133 = V_7 -> V_98 . V_104 ;
V_130 = true ;
} else {
F_14 ( V_7 -> V_29 , L_34
L_35 ,
V_7 -> V_98 . V_122 ,
V_109 ,
V_7 -> V_98 . V_106 ) ;
}
}
if ( V_130 ) {
if ( V_7 -> V_9 -> V_134 ) {
V_7 -> V_98 . V_121 . V_128 =
F_50 ( V_7 ) ;
F_55 ( V_7 -> V_29 , L_36 ,
V_7 -> V_98 . V_122 ,
V_7 -> V_98 . V_121 . V_128 ) ;
}
F_56 ( V_7 -> V_135 ) ;
if ( V_7 -> V_38 . V_123 && V_7 -> V_38 . V_105 ) {
F_14 ( V_7 -> V_29 , L_37 ) ;
V_7 -> V_38 . V_105 = false ;
F_57 ( & V_7 -> V_136 , NULL , L_38 ) ;
}
F_57 ( & V_7 -> V_136 , NULL , L_39 ) ;
}
}
static void F_58 ( struct V_1 * V_7 ,
enum V_137 V_138 )
{
F_14 ( V_7 -> V_29 , L_40 ,
V_7 -> V_139 ,
V_139 [ V_7 -> V_139 ] ,
V_138 ,
V_139 [ V_138 ] ) ;
V_7 -> V_139 = V_138 ;
}
static void F_59 ( struct V_1 * V_7 ,
enum V_140 V_138 )
{
F_14 ( V_7 -> V_29 , L_41 ,
V_7 -> V_141 ,
V_141 [ V_7 -> V_141 ] ,
V_138 ,
V_141 [ V_138 ] ) ;
V_7 -> V_141 = V_138 ;
}
static void F_60 ( struct V_1 * V_7 )
{
if ( V_7 -> V_141 != V_142 )
F_59 ( V_7 ,
V_142 ) ;
switch ( V_7 -> V_139 ) {
case V_143 :
V_7 -> V_35 = F_19 (
V_7 -> V_9 -> V_10 -> V_144 ) ;
F_10 ( V_7 , true ) ;
F_58 ( V_7 , V_145 ) ;
break;
case V_145 :
F_11 ( & V_7 -> V_28 ) ;
if ( ! V_7 -> V_38 . V_73 && ! V_7 -> V_38 . V_105 ) {
F_15 ( & V_7 -> V_28 ) ;
F_14 ( V_7 -> V_29 , L_42 ,
V_44 ) ;
break;
}
V_7 -> V_38 . V_73 = false ;
F_15 ( & V_7 -> V_28 ) ;
F_45 ( V_7 ) ;
break;
default:
break;
}
F_54 ( V_7 , false ) ;
}
static void F_61 ( struct V_1 * V_7 )
{
int V_83 ;
F_8 ( V_7 ) ;
V_83 = V_7 -> V_98 . V_146 ;
if ( V_83 > V_7 -> V_98 . V_99 ) {
F_14 ( V_7 -> V_29 , L_43
L_44 , V_83 , V_7 -> V_98 . V_99 ) ;
V_83 = V_7 -> V_98 . V_99 ;
}
F_9 ( V_7 , V_7 -> V_98 . V_146 ) ;
V_7 -> V_98 . V_106 = F_41 ( V_7 , V_83 ) ;
V_7 -> V_98 . V_104 = V_83 ;
F_54 ( V_7 , true ) ;
}
static bool F_62 ( struct V_1 * V_7 )
{
int V_83 , V_147 , V_148 ;
int V_149 ;
V_83 = V_7 -> V_98 . V_146 ;
V_149 = F_41 ( V_7 ,
V_7 -> V_98 . V_146 ) ;
V_147 = V_7 -> V_98 . V_106 - V_7 -> V_9 -> V_10 -> V_150 * 10 ;
V_148 = V_7 -> V_98 . V_106 + V_7 -> V_9 -> V_10 -> V_150 * 10 ;
if ( V_147 < 0 )
V_147 = 0 ;
if ( V_148 > 1000 )
V_148 = 1000 ;
F_14 ( V_7 -> V_29 , L_45
L_46 ,
V_147 , V_149 , V_148 , V_83 , V_7 -> V_98 . V_104 ) ;
if ( V_149 > V_147 && V_149 < V_148 ) {
F_14 ( V_7 -> V_29 , L_47 , V_83 ) ;
F_61 ( V_7 ) ;
return true ;
}
F_14 ( V_7 -> V_29 , L_48 ) ;
return false ;
}
static void F_63 ( struct V_1 * V_7 )
{
int V_151 ;
if ( V_7 -> V_139 != V_143 )
F_58 ( V_7 , V_143 ) ;
switch ( V_7 -> V_141 ) {
case V_152 :
V_7 -> V_153 = 0 ;
V_7 -> V_35 = F_19 ( V_7 -> V_9 -> V_10 -> V_154 ) ;
F_10 ( V_7 , true ) ;
F_59 ( V_7 ,
V_155 ) ;
case V_155 :
V_151 = V_7 -> V_9 -> V_10 -> V_154 ;
if ( V_7 -> V_153 > V_7 -> V_9 -> V_10 -> V_156 ) {
F_46 ( V_7 , true ) ;
F_54 ( V_7 , true ) ;
}
V_7 -> V_153 += V_151 ;
if ( V_7 -> V_153 > V_7 -> V_9 -> V_10 -> V_157 )
F_59 ( V_7 ,
V_158 ) ;
break;
case V_142 :
V_7 -> V_159 = 0 ;
V_7 -> V_160 = true ;
F_59 ( V_7 ,
V_161 ) ;
case V_161 :
V_151 = V_7 -> V_9 -> V_10 -> V_162 ;
V_7 -> V_96 = F_30 ( V_7 ) ;
if ( F_5 ( V_7 , V_7 -> V_96 ) ) {
if ( V_7 -> V_159 >
V_7 -> V_9 -> V_10 -> V_163 ) {
V_7 -> V_35 = F_19 (
V_7 -> V_9 -> V_10 -> V_164 ) ;
F_10 ( V_7 , true ) ;
F_59 ( V_7 ,
V_165 ) ;
V_7 -> V_160 = false ;
} else {
F_64 ( V_7 -> V_74 ,
& V_7 -> V_166 ,
V_151 * V_167 ) ;
}
V_7 -> V_159 += V_151 ;
} else {
V_7 -> V_35 = F_19 (
V_7 -> V_9 -> V_10 -> V_164 ) ;
F_10 ( V_7 , true ) ;
F_59 ( V_7 ,
V_165 ) ;
}
break;
case V_158 :
V_7 -> V_35 = F_19 (
V_7 -> V_9 -> V_10 -> V_164 ) ;
F_10 ( V_7 , true ) ;
F_59 ( V_7 ,
V_165 ) ;
break;
case V_165 :
V_7 -> V_96 = F_30 ( V_7 ) ;
if ( F_5 ( V_7 , V_7 -> V_96 ) ) {
if ( V_7 -> V_168 ) {
V_7 -> V_168 = false ;
V_7 -> V_169 = 0 ;
}
if ( V_7 -> V_160 ) {
F_59 ( V_7 ,
V_142 ) ;
F_64 ( V_7 -> V_74 ,
& V_7 -> V_166 , 0 ) ;
break;
}
F_46 ( V_7 , true ) ;
} else {
F_11 ( & V_7 -> V_28 ) ;
if ( ! V_7 -> V_38 . V_73 ) {
F_15 ( & V_7 -> V_28 ) ;
F_14 ( V_7 -> V_29 , L_42 ,
V_44 ) ;
break;
}
V_7 -> V_38 . V_73 = false ;
F_15 ( & V_7 -> V_28 ) ;
if ( ! V_7 -> V_168 ) {
V_7 -> V_168 = true ;
V_7 -> V_169 = 0 ;
}
V_7 -> V_169 +=
V_7 -> V_9 -> V_10 -> V_164 ;
if ( V_7 -> V_169 >
V_7 -> V_9 -> V_10 -> V_170 )
V_7 -> V_160 = true ;
F_47 ( V_7 ) ;
}
F_54 ( V_7 , false ) ;
break;
case V_171 :
F_46 ( V_7 , true ) ;
V_7 -> V_35 = F_19 (
V_7 -> V_9 -> V_10 -> V_164 ) ;
F_10 ( V_7 , true ) ;
F_59 ( V_7 ,
V_165 ) ;
F_54 ( V_7 , false ) ;
break;
default:
break;
}
}
static void F_65 ( struct V_1 * V_7 )
{
int V_27 ;
switch ( V_7 -> V_172 ) {
case V_173 :
F_14 ( V_7 -> V_29 , L_49 ) ;
V_27 = F_13 ( V_7 -> V_29 ,
V_33 , V_40 ,
V_174 , V_175 ) ;
if ( V_27 < 0 )
goto V_176;
V_27 = F_13 ( V_7 -> V_29 ,
V_33 , V_40 ,
V_177 , V_177 ) ;
if ( V_27 < 0 )
goto V_176;
V_7 -> V_172 = V_178 ;
break;
case V_179 :
V_27 = F_13 ( V_7 -> V_29 ,
V_33 , V_40 ,
V_180 , V_180 ) ;
if ( V_27 < 0 )
goto V_176;
V_7 -> V_38 . V_181 = false ;
F_14 ( V_7 -> V_29 , L_50 ) ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
break;
case V_178 :
F_14 ( V_7 -> V_29 , L_51 ) ;
default:
break;
}
return;
V_176:
F_16 ( V_7 -> V_29 , L_52 ) ;
V_7 -> V_38 . V_181 = false ;
V_7 -> V_172 = V_173 ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
}
static void F_66 ( struct V_1 * V_7 )
{
if ( V_7 -> V_38 . V_181 )
F_65 ( V_7 ) ;
else {
if ( V_7 -> V_38 . V_126 )
F_60 ( V_7 ) ;
else
F_63 ( V_7 ) ;
}
F_14 ( V_7 -> V_29 , L_53
L_54 ,
V_7 -> V_98 . V_99 ,
V_7 -> V_98 . V_182 ,
V_7 -> V_98 . V_104 ,
V_7 -> V_98 . V_106 ,
V_7 -> V_98 . V_131 ,
V_7 -> V_98 . V_133 ,
V_7 -> V_98 . V_122 ,
V_7 -> V_98 . V_132 ,
V_7 -> V_76 ,
V_7 -> V_96 ,
V_7 -> V_72 ,
V_7 -> V_71 ,
V_7 -> V_38 . V_126 ,
V_7 -> V_139 ,
V_7 -> V_141 ,
V_7 -> V_168 ,
V_7 -> V_160 ) ;
}
static void F_67 ( struct V_63 * V_64 )
{
struct V_1 * V_7 = F_32 ( V_64 , struct V_1 ,
V_166 . V_64 ) ;
if ( V_7 -> V_183 ) {
F_46 ( V_7 , true ) ;
F_54 ( V_7 , true ) ;
V_7 -> V_183 = false ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
} else if ( V_7 -> V_38 . V_184 ) {
if ( F_62 ( V_7 ) ) {
F_54 ( V_7 , true ) ;
if ( V_7 -> V_38 . V_126 )
F_58 ( V_7 ,
V_143 ) ;
else
F_59 ( V_7 ,
V_158 ) ;
}
V_7 -> V_38 . V_184 = false ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
} else
F_66 ( V_7 ) ;
}
static void F_68 ( struct V_63 * V_64 )
{
int V_27 ;
T_1 V_185 ;
struct V_1 * V_7 = F_32 ( V_64 , struct V_1 ,
V_186 . V_64 ) ;
V_27 = F_18 ( V_7 -> V_29 ,
V_187 , V_188 ,
& V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_7 -> V_29 , L_55 , V_44 ) ;
return;
}
if ( ( V_185 & V_189 ) == V_189 ) {
if ( ! V_7 -> V_38 . V_190 ) {
F_14 ( V_7 -> V_29 , L_56 ) ;
V_7 -> V_38 . V_190 = true ;
F_56 ( V_7 -> V_135 ) ;
}
F_64 ( V_7 -> V_74 , & V_7 -> V_186 ,
V_167 ) ;
} else {
F_14 ( V_7 -> V_29 , L_57 ) ;
V_7 -> V_38 . V_190 = false ;
F_56 ( V_7 -> V_135 ) ;
}
}
static void F_69 ( struct V_63 * V_64 )
{
int V_76 ;
struct V_1 * V_7 = F_32 ( V_64 , struct V_1 ,
V_191 . V_64 ) ;
V_76 = F_34 ( V_7 ) ;
if ( V_76 < V_7 -> V_9 -> V_10 -> V_192 ) {
if ( V_7 -> V_193 < 1 ) {
V_7 -> V_38 . V_112 = true ;
F_70 ( V_7 -> V_29 , L_58 ) ;
} else {
V_7 -> V_193 -- ;
F_70 ( V_7 -> V_29 , L_59 ) ;
F_64 ( V_7 -> V_74 , & V_7 -> V_191 ,
F_71 ( V_194 ) ) ;
}
} else {
V_7 -> V_38 . V_195 = false ;
V_7 -> V_193 = 10 ;
F_70 ( V_7 -> V_29 , L_60 ) ;
}
F_54 ( V_7 , false ) ;
}
static int F_72 ( struct V_1 * V_7 , int V_196 )
{
if ( V_196 > V_197 +
( V_198 * V_199 ) )
return V_199 ;
if ( V_196 < V_197 )
return 0 ;
return ( V_196 - V_197 ) / V_198 ;
}
static int F_73 ( struct V_1 * V_7 )
{
int V_200 ;
int V_201 ;
int V_202 ;
int V_203 ;
int V_204 ;
int V_27 ;
int V_205 ;
V_201 = V_7 -> V_9 -> V_10 -> V_206 ;
V_202 = V_7 -> V_9 -> V_10 -> V_207 ;
V_203 = F_72 ( V_7 , V_201 ) ;
V_204 = F_72 ( V_7 , V_202 ) ;
V_200 = V_197 + V_203 * V_198 ;
if ( V_200 != V_201 )
F_70 ( V_7 -> V_29 , L_61 ,
V_201 , V_200 , V_203 ) ;
V_200 = V_197 + V_204 * V_198 ;
if ( V_200 != V_202 )
F_70 ( V_7 -> V_29 , L_61 ,
V_202 , V_200 , V_204 ) ;
V_205 = V_203 | ( V_204 << 4 ) ;
F_14 ( V_7 -> V_29 , L_62 , V_205 , V_203 , V_204 ) ;
V_27 = F_12 ( V_7 -> V_29 , V_208 ,
V_209 , V_205 ) ;
return V_27 ;
}
static void F_74 ( struct V_63 * V_64 )
{
struct V_1 * V_7 = F_32 ( V_64 , struct V_1 , V_75 ) ;
F_66 ( V_7 ) ;
}
static T_4 F_75 ( int V_51 , void * V_210 )
{
struct V_1 * V_7 = V_210 ;
if ( ! V_7 -> V_46 ) {
V_7 -> V_46 ++ ;
F_76 ( & V_7 -> V_49 ) ;
} else {
V_7 -> V_46 = 0 ;
F_76 ( & V_7 -> V_50 ) ;
}
return V_211 ;
}
static T_4 F_77 ( int V_51 , void * V_210 )
{
struct V_1 * V_7 = V_210 ;
V_7 -> V_172 = V_179 ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
return V_211 ;
}
static T_4 F_78 ( int V_51 , void * V_210 )
{
struct V_1 * V_7 = V_210 ;
F_33 ( V_7 -> V_74 , & V_7 -> V_66 ) ;
return V_211 ;
}
static T_4 F_79 ( int V_51 , void * V_210 )
{
struct V_1 * V_7 = V_210 ;
F_14 ( V_7 -> V_29 , L_56 ) ;
F_64 ( V_7 -> V_74 , & V_7 -> V_186 , 0 ) ;
return V_211 ;
}
static T_4 F_80 ( int V_51 , void * V_210 )
{
struct V_1 * V_7 = V_210 ;
if ( ! V_7 -> V_38 . V_195 ) {
F_70 ( V_7 -> V_29 , L_63 ) ;
V_7 -> V_38 . V_195 = true ;
F_64 ( V_7 -> V_74 , & V_7 -> V_191 ,
F_71 ( V_194 ) ) ;
}
return V_211 ;
}
static int F_81 ( struct V_212 * V_213 ,
enum V_214 V_215 ,
union V_216 * V_55 )
{
struct V_1 * V_7 = F_82 ( V_213 ) ;
switch ( V_215 ) {
case V_217 :
if ( V_7 -> V_38 . V_190 )
V_55 -> V_218 = V_219 * 1000 ;
else
V_55 -> V_218 = V_7 -> V_76 * 1000 ;
break;
case V_220 :
V_55 -> V_218 = V_7 -> V_96 * 1000 ;
break;
case V_221 :
V_55 -> V_218 = V_7 -> V_72 * 1000 ;
break;
case V_222 :
V_55 -> V_218 = F_43 ( V_7 ,
V_7 -> V_98 . V_99 ) ;
break;
case V_223 :
V_55 -> V_218 = F_43 ( V_7 ,
V_7 -> V_98 . V_182 ) ;
break;
case V_224 :
if ( V_7 -> V_38 . V_225 && ! V_7 -> V_9 -> V_226 &&
V_7 -> V_38 . V_227 )
V_55 -> V_218 = F_43 ( V_7 ,
V_7 -> V_98 . V_182 ) ;
else
V_55 -> V_218 = F_43 ( V_7 ,
V_7 -> V_98 . V_133 ) ;
break;
case V_228 :
V_55 -> V_218 = V_7 -> V_98 . V_99 ;
break;
case V_229 :
V_55 -> V_218 = V_7 -> V_98 . V_182 ;
break;
case V_230 :
if ( V_7 -> V_38 . V_225 && ! V_7 -> V_9 -> V_226 &&
V_7 -> V_38 . V_227 )
V_55 -> V_218 = V_7 -> V_98 . V_182 ;
else
V_55 -> V_218 = V_7 -> V_98 . V_133 ;
break;
case V_231 :
if ( V_7 -> V_38 . V_225 && ! V_7 -> V_9 -> V_226 &&
V_7 -> V_38 . V_227 )
V_55 -> V_218 = 100 ;
else
V_55 -> V_218 = V_7 -> V_98 . V_122 ;
break;
case V_232 :
if ( V_7 -> V_38 . V_225 && ! V_7 -> V_9 -> V_226 &&
V_7 -> V_38 . V_227 )
V_55 -> V_218 = V_233 ;
else
V_55 -> V_218 = V_7 -> V_98 . V_132 ;
break;
default:
return - V_234 ;
}
return 0 ;
}
static int F_83 ( struct V_235 * V_29 , void * V_236 )
{
struct V_212 * V_213 ;
struct V_212 * V_237 = F_84 ( V_29 ) ;
const char * * V_238 = ( const char * * ) V_237 -> V_239 ;
struct V_1 * V_7 ;
union V_216 V_27 ;
int V_240 ;
V_213 = (struct V_212 * ) V_236 ;
V_7 = F_82 ( V_213 ) ;
V_240 = F_85 ( V_238 , V_237 -> V_241 , V_213 -> V_242 -> V_243 ) ;
if ( V_240 < 0 )
return 0 ;
for ( V_240 = 0 ; V_240 < V_237 -> V_242 -> V_244 ; V_240 ++ ) {
enum V_214 V_245 ;
V_245 = V_237 -> V_242 -> V_246 [ V_240 ] ;
if ( F_86 ( V_237 , V_245 , & V_27 ) )
continue;
switch ( V_245 ) {
case V_247 :
switch ( V_237 -> V_242 -> type ) {
case V_248 :
switch ( V_27 . V_218 ) {
case V_249 :
case V_250 :
case V_251 :
if ( ! V_7 -> V_38 . V_126 )
break;
V_7 -> V_38 . V_126 = false ;
V_7 -> V_38 . V_123 = false ;
if ( V_7 -> V_9 -> V_134 )
F_53 ( V_7 ) ;
F_33 ( V_7 -> V_74 , & V_7 -> V_75 ) ;
break;
case V_252 :
if ( V_7 -> V_38 . V_123 )
break;
V_7 -> V_38 . V_123 = true ;
V_7 -> V_38 . V_105 = true ;
V_7 -> V_98 . V_182 = V_7 -> V_98 . V_104 ;
F_33 ( V_7 -> V_74 , & V_7 -> V_75 ) ;
break;
case V_253 :
if ( V_7 -> V_38 . V_126 &&
! V_7 -> V_38 . V_123 )
break;
V_7 -> V_38 . V_126 = true ;
V_7 -> V_38 . V_123 = false ;
if ( V_7 -> V_9 -> V_134 )
F_53 ( V_7 ) ;
F_33 ( V_7 -> V_74 , & V_7 -> V_75 ) ;
break;
} ;
default:
break;
} ;
break;
case V_254 :
switch ( V_237 -> V_242 -> type ) {
case V_248 :
if ( ! V_7 -> V_38 . V_227 &&
V_7 -> V_9 -> V_85 != V_255 ) {
const struct V_256 * V_257 ;
V_257 = & ( V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] ) ;
V_7 -> V_38 . V_227 = true ;
V_7 -> V_98 . V_99 =
V_258 *
V_257 -> V_259 ;
V_7 -> V_98 . V_182 =
V_7 -> V_98 . V_99 ;
V_7 -> V_103 = V_257 -> V_260 ;
}
if ( V_27 . V_218 )
V_7 -> V_38 . V_225 = false ;
else
V_7 -> V_38 . V_225 = true ;
break;
default:
break;
}
break;
case V_261 :
switch ( V_237 -> V_242 -> type ) {
case V_248 :
if ( V_7 -> V_38 . V_227 )
V_7 -> V_93 = V_27 . V_218 ;
break;
default:
break;
}
break;
default:
break;
}
}
return 0 ;
}
static int F_87 ( struct V_1 * V_7 )
{
int V_27 ;
V_27 = F_13 ( V_7 -> V_29 ,
V_187 ,
V_262 ,
V_263 ,
V_263 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_64 ) ;
goto V_264;
}
V_27 = F_13 ( V_7 -> V_29 ,
V_187 ,
V_262 ,
V_265 ,
V_265 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_65 ) ;
goto V_264;
}
V_27 = F_12 ( V_7 -> V_29 ,
V_208 ,
V_266 ,
F_3 (
V_7 -> V_9 -> V_10 -> V_192 ) << 1 |
V_267 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_66 , V_44 ) ;
goto V_264;
}
V_27 = F_73 ( V_7 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_67 ) ;
goto V_264;
}
if ( ( ( F_88 ( V_7 -> V_268 ) || F_89 ( V_7 -> V_268 ) ) &&
F_90 ( V_7 -> V_29 ) >= V_269 )
|| F_91 ( V_7 -> V_268 ) ) {
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_270 , V_7 -> V_9 -> V_10 -> V_271 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_68 , V_44 ) ;
goto V_264;
} ;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_272 , V_7 -> V_9 -> V_10 -> V_273 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_69 , V_44 ) ;
goto V_264;
} ;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_274 , V_7 -> V_9 -> V_10 -> V_275 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_70 , V_44 ) ;
goto V_264;
} ;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_276 , V_7 -> V_9 -> V_10 -> V_277 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_71 , V_44 ) ;
goto V_264;
} ;
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_278 , V_7 -> V_9 -> V_10 -> V_279 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_72 , V_44 ) ;
goto V_264;
} ;
}
V_264:
return V_27 ;
}
static void F_92 ( struct V_212 * V_213 )
{
struct V_1 * V_7 = F_82 ( V_213 ) ;
F_93 ( V_280 , NULL ,
V_7 -> V_135 , F_83 ) ;
}
static void F_94 ( struct V_63 * V_64 )
{
struct V_1 * V_7 = F_32 ( V_64 , struct V_1 ,
V_281 . V_64 ) ;
if ( V_7 -> V_38 . V_181 == false ) {
F_14 ( V_7 -> V_29 , L_73 ) ;
F_8 ( V_7 ) ;
F_46 ( V_7 , true ) ;
F_58 ( V_7 , V_143 ) ;
F_59 ( V_7 , V_152 ) ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
} else {
F_16 ( V_7 -> V_29 , L_74
L_75 ) ;
F_64 ( V_7 -> V_74 , & V_7 -> V_281 ,
F_71 ( 1 ) ) ;
}
}
static T_5 F_95 ( struct V_1 * V_7 , char * V_282 )
{
return sprintf ( V_282 , L_76 , V_7 -> V_98 . V_182 ) ;
}
static T_5 F_96 ( struct V_1 * V_7 , const char * V_282 ,
T_6 V_283 )
{
unsigned long V_284 ;
T_5 V_27 ;
V_27 = F_97 ( V_282 , 10 , & V_284 ) ;
F_14 ( V_7 -> V_29 , L_77 , V_27 , V_284 ) ;
if ( ! V_27 ) {
V_7 -> V_98 . V_182 = ( int ) V_284 ;
V_27 = V_283 ;
}
return V_27 ;
}
static T_5 F_98 ( struct V_1 * V_7 , char * V_282 )
{
return sprintf ( V_282 , L_76 , V_7 -> V_98 . V_133 ) ;
}
static T_5 F_99 ( struct V_1 * V_7 , const char * V_282 ,
T_6 V_283 )
{
unsigned long V_285 ;
T_5 V_27 ;
V_27 = F_97 ( V_282 , 10 , & V_285 ) ;
F_14 ( V_7 -> V_29 , L_78 ,
V_27 , V_285 , V_7 -> V_98 . V_133 ) ;
if ( ! V_27 ) {
V_7 -> V_98 . V_146 = ( int ) V_285 ;
V_7 -> V_38 . V_184 = true ;
V_27 = V_283 ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
}
return V_27 ;
}
static T_5
F_100 ( struct V_286 * V_287 , struct V_288 * V_289 , char * V_282 )
{
struct V_290 * V_291 ;
struct V_1 * V_7 ;
V_291 = F_32 ( V_289 , struct V_290 , V_289 ) ;
V_7 = F_32 ( V_287 , struct V_1 , V_136 ) ;
if ( ! V_291 -> V_292 )
return - V_293 ;
return V_291 -> V_292 ( V_7 , V_282 ) ;
}
static T_5
F_101 ( struct V_286 * V_287 , struct V_288 * V_289 , const char * V_282 ,
T_6 V_283 )
{
struct V_290 * V_291 ;
struct V_1 * V_7 ;
V_291 = F_32 ( V_289 , struct V_290 , V_289 ) ;
V_7 = F_32 ( V_287 , struct V_1 , V_136 ) ;
if ( ! V_291 -> V_294 )
return - V_293 ;
return V_291 -> V_294 ( V_7 , V_282 , V_283 ) ;
}
static void F_102 ( struct V_1 * V_7 )
{
F_103 ( & V_7 -> V_136 ) ;
}
static int F_104 ( struct V_1 * V_7 )
{
int V_27 = 0 ;
V_27 = F_105 ( & V_7 -> V_136 ,
& V_295 ,
NULL , L_79 ) ;
if ( V_27 < 0 )
F_16 ( V_7 -> V_29 , L_80 ) ;
return V_27 ;
}
static T_5 F_106 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_272 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_81 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0x7F ) ) ;
V_47:
return V_27 ;
}
static T_5 F_108 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
const char * V_282 , T_6 V_283 )
{
int V_27 ;
long unsigned V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_185 = F_109 ( V_282 , NULL , 10 ) ;
if ( V_185 > 0x7F ) {
F_16 ( V_29 , L_82 ) ;
goto V_47;
}
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_272 , ( T_1 ) V_185 ) ;
if ( V_27 < 0 )
F_16 ( V_29 , L_83 ) ;
V_47:
return V_283 ;
}
static T_5 F_110 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_270 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_84 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0x7F ) ) ;
V_47:
return V_27 ;
}
static T_5 F_111 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
const char * V_282 , T_6 V_283 )
{
int V_27 ;
int V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_185 = F_109 ( V_282 , NULL , 10 ) ;
if ( V_185 > 0x7F ) {
F_16 ( V_29 , L_85 ) ;
goto V_47;
}
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_270 , ( T_1 ) V_185 ) ;
if ( V_27 < 0 )
F_16 ( V_29 , L_86 ) ;
V_47:
return V_283 ;
}
static T_5 F_112 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_274 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_87 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0xF ) ) ;
V_47:
return V_27 ;
}
static T_5 F_113 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
const char * V_282 , T_6 V_283 )
{
int V_27 ;
int V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_185 = F_109 ( V_282 , NULL , 10 ) ;
if ( V_185 > 0xF ) {
F_16 ( V_29 , L_88 ) ;
goto V_47;
}
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_274 , ( T_1 ) V_185 ) ;
if ( V_27 < 0 )
F_16 ( V_29 , L_89 ) ;
V_47:
return V_283 ;
}
static T_5 F_114 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_298 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_90 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0x7F ) ) ;
V_47:
return V_27 ;
}
static T_5 F_115 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_274 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_87 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0xF0 ) >> 4 ) ;
V_47:
return V_27 ;
}
static T_5 F_116 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_278 , & V_185 ) ;
if ( V_27 < 0 )
goto V_47;
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0x1 ) ) ;
V_47:
return V_27 ;
}
static T_5 F_117 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
const char * V_282 , T_6 V_283 )
{
int V_27 ;
int V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_185 = F_109 ( V_282 , NULL , 10 ) ;
if ( V_185 > 0x1 ) {
F_16 ( V_29 , L_91 ) ;
goto V_47;
}
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_278 , ( T_1 ) V_185 ) ;
if ( V_27 < 0 )
F_16 ( V_29 , L_92 ) ;
V_47:
return V_283 ;
}
static T_5 F_118 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_278 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_93 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( ( V_185 & 0x10 ) >> 4 ) ) ;
V_47:
return V_27 ;
}
static T_5 F_119 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_276 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_94 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( V_185 & 0x7 ) ) ;
V_47:
return V_27 ;
}
static T_5 F_120 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
const char * V_282 , T_6 V_283 )
{
int V_27 ;
int V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_185 = F_109 ( V_282 , NULL , 10 ) ;
if ( V_185 > 0x7 ) {
F_16 ( V_29 , L_95 ) ;
goto V_47;
}
V_27 = F_12 ( V_7 -> V_29 , V_30 ,
V_276 , ( T_1 ) V_185 ) ;
if ( V_27 < 0 )
F_16 ( V_29 , L_96 ) ;
V_47:
return V_283 ;
}
static T_5 F_121 ( struct V_235 * V_29 ,
struct V_296 * V_289 ,
char * V_282 )
{
int V_27 ;
T_1 V_185 ;
struct V_212 * V_213 = F_84 ( V_29 ) ;
struct V_1 * V_7 = F_82 ( V_213 ) ;
V_27 = F_18 ( V_7 -> V_29 , V_30 ,
V_278 , & V_185 ) ;
if ( V_27 < 0 ) {
F_16 ( V_29 , L_93 ) ;
goto V_47;
}
return F_107 ( V_282 , V_297 , L_76 , ( ( V_185 & 0x20 ) >> 5 ) ) ;
V_47:
return V_27 ;
}
static int F_122 ( struct V_1 * V_7 )
{
unsigned int V_5 ;
if ( ( ( F_88 ( V_7 -> V_268 ) || F_89 ( V_7 -> V_268 ) ) &&
F_90 ( V_7 -> V_29 ) >= V_269 )
|| F_91 ( V_7 -> V_268 ) ) {
for ( V_5 = 0 ; V_5 < F_4 ( V_299 ) ; V_5 ++ )
if ( F_123 ( & V_7 -> V_135 -> V_29 ,
& V_299 [ V_5 ] ) )
goto V_300;
}
return 0 ;
V_300:
F_16 ( & V_7 -> V_135 -> V_29 , L_97 ) ;
while ( V_5 -- )
F_124 ( & V_7 -> V_135 -> V_29 ,
& V_299 [ V_5 ] ) ;
return - V_293 ;
}
static void F_125 ( struct V_1 * V_7 )
{
unsigned int V_5 ;
if ( ( ( F_88 ( V_7 -> V_268 ) || F_89 ( V_7 -> V_268 ) ) &&
F_90 ( V_7 -> V_29 ) >= V_269 )
|| F_91 ( V_7 -> V_268 ) ) {
for ( V_5 = 0 ; V_5 < F_4 ( V_299 ) ; V_5 ++ )
( void ) F_124 ( & V_7 -> V_135 -> V_29 ,
& V_299 [ V_5 ] ) ;
}
}
static int F_126 ( struct V_301 * V_302 )
{
struct V_1 * V_7 = F_127 ( V_302 ) ;
if ( ! V_7 -> V_38 . V_126 ) {
F_59 ( V_7 , V_171 ) ;
F_33 ( V_7 -> V_74 , & V_7 -> V_75 ) ;
}
return 0 ;
}
static int F_128 ( struct V_301 * V_302 ,
T_7 V_303 )
{
struct V_1 * V_7 = F_127 ( V_302 ) ;
F_129 ( & V_7 -> V_166 ) ;
F_130 ( & V_7 -> V_75 ) ;
F_130 ( & V_7 -> V_66 ) ;
F_129 ( & V_7 -> V_281 ) ;
F_129 ( & V_7 -> V_191 ) ;
F_129 ( & V_7 -> V_186 ) ;
if ( V_7 -> V_38 . V_39 && ! V_7 -> V_38 . V_126 )
F_10 ( V_7 , false ) ;
return 0 ;
}
static int F_131 ( struct V_301 * V_302 )
{
int V_27 = 0 ;
struct V_1 * V_7 = F_127 ( V_302 ) ;
F_132 ( & V_7 -> V_3 ) ;
V_27 = F_10 ( V_7 , false ) ;
if ( V_27 )
F_16 ( V_7 -> V_29 , L_98 ) ;
F_133 ( V_7 -> V_74 ) ;
F_102 ( V_7 ) ;
F_134 () ;
F_125 ( V_7 ) ;
F_135 ( V_7 -> V_135 ) ;
return V_27 ;
}
static int F_136 ( struct V_301 * V_302 )
{
struct V_304 * V_305 = V_302 -> V_29 . V_306 ;
struct V_307 * V_308 = V_302 -> V_29 . V_309 ;
struct V_310 V_311 = {} ;
struct V_1 * V_7 ;
int V_5 , V_51 ;
int V_27 = 0 ;
V_7 = F_137 ( & V_302 -> V_29 , sizeof( * V_7 ) , V_312 ) ;
if ( ! V_7 ) {
F_16 ( & V_302 -> V_29 , L_99 , V_44 ) ;
return - V_313 ;
}
if ( ! V_308 ) {
F_16 ( & V_302 -> V_29 , L_100 ) ;
return - V_234 ;
}
V_7 -> V_9 = V_308 ;
if ( V_305 ) {
V_27 = F_138 ( & V_302 -> V_29 , V_305 , V_7 -> V_9 ) ;
if ( V_27 ) {
F_16 ( & V_302 -> V_29 , L_101 ) ;
return V_27 ;
}
}
F_139 ( & V_7 -> V_28 ) ;
V_7 -> V_29 = & V_302 -> V_29 ;
V_7 -> V_268 = F_84 ( V_302 -> V_29 . V_268 ) ;
V_7 -> V_78 = F_140 ( L_102 ) ;
V_311 . V_239 = V_314 ;
V_311 . V_241 = F_4 ( V_314 ) ;
V_311 . V_315 = V_7 ;
V_7 -> V_98 . V_99 = V_258 *
V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] . V_259 ;
V_7 -> V_98 . V_182 = V_7 -> V_98 . V_99 ;
V_7 -> V_103 = V_7 -> V_9 -> V_84 [ V_7 -> V_9 -> V_85 ] . V_260 ;
V_7 -> V_183 = true ;
F_58 ( V_7 , V_143 ) ;
F_59 ( V_7 , V_152 ) ;
V_7 -> V_74 = F_141 ( L_103 , V_316 ) ;
if ( V_7 -> V_74 == NULL ) {
F_16 ( V_7 -> V_29 , L_104 ) ;
return - V_313 ;
}
F_142 ( & V_7 -> V_75 , F_74 ) ;
F_142 ( & V_7 -> V_66 , F_31 ) ;
F_143 ( & V_7 -> V_281 ,
F_94 ) ;
F_143 ( & V_7 -> V_166 ,
F_67 ) ;
F_143 ( & V_7 -> V_191 ,
F_69 ) ;
F_143 ( & V_7 -> V_186 ,
F_68 ) ;
V_7 -> V_38 . V_112 = false ;
V_7 -> V_193 = 10 ;
V_27 = F_87 ( V_7 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_105 ) ;
goto V_317;
}
V_7 -> V_38 . V_225 = true ;
V_7 -> V_38 . V_227 = false ;
V_7 -> V_135 = F_144 ( V_7 -> V_29 , & V_318 , & V_311 ) ;
if ( F_145 ( V_7 -> V_135 ) ) {
F_16 ( V_7 -> V_29 , L_106 ) ;
V_27 = F_146 ( V_7 -> V_135 ) ;
goto V_317;
}
V_7 -> V_35 = F_19 ( V_7 -> V_9 -> V_10 -> V_154 ) ;
F_10 ( V_7 , true ) ;
F_147 ( & V_7 -> V_49 ) ;
F_147 ( & V_7 -> V_50 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_319 ) ; V_5 ++ ) {
V_51 = F_148 ( V_302 , V_319 [ V_5 ] . V_243 ) ;
V_27 = F_149 ( V_51 , V_319 [ V_5 ] . V_320 ,
V_321 | V_322 ,
V_319 [ V_5 ] . V_243 , V_7 ) ;
if ( V_27 != 0 ) {
F_16 ( V_7 -> V_29 , L_107 ,
V_319 [ V_5 ] . V_243 , V_51 , V_27 ) ;
goto V_323;
}
F_14 ( V_7 -> V_29 , L_108 ,
V_319 [ V_5 ] . V_243 , V_51 , V_27 ) ;
}
V_51 = F_148 ( V_302 , V_324 [ 0 ] . V_243 ) ;
V_27 = F_150 ( V_51 , NULL , V_324 [ 0 ] . V_320 ,
V_321 | V_322 | V_325 ,
V_324 [ 0 ] . V_243 , V_7 ) ;
if ( V_27 != 0 ) {
F_16 ( V_7 -> V_29 , L_107 ,
V_324 [ 0 ] . V_243 , V_51 , V_27 ) ;
goto V_323;
}
F_14 ( V_7 -> V_29 , L_108 ,
V_324 [ 0 ] . V_243 , V_51 , V_27 ) ;
V_7 -> V_51 = F_148 ( V_302 , L_109 ) ;
F_28 ( V_7 -> V_51 ) ;
V_7 -> V_46 = 0 ;
F_151 ( V_302 , V_7 ) ;
V_27 = F_104 ( V_7 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_80 ) ;
goto V_323;
}
V_27 = F_122 ( V_7 ) ;
if ( V_27 ) {
F_16 ( V_7 -> V_29 , L_110 ) ;
F_102 ( V_7 ) ;
goto V_323;
}
V_7 -> V_38 . V_181 = true ;
V_7 -> V_172 = V_173 ;
V_7 -> V_93 = 210 ;
F_64 ( V_7 -> V_74 , & V_7 -> V_166 , 0 ) ;
F_152 ( & V_7 -> V_3 , & V_2 ) ;
return V_27 ;
V_323:
F_135 ( V_7 -> V_135 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_319 ) ; V_5 ++ ) {
V_51 = F_148 ( V_302 , V_319 [ V_5 ] . V_243 ) ;
V_323 ( V_51 , V_7 ) ;
}
V_51 = F_148 ( V_302 , V_324 [ 0 ] . V_243 ) ;
V_323 ( V_51 , V_7 ) ;
V_317:
F_133 ( V_7 -> V_74 ) ;
return V_27 ;
}
static int T_8 F_153 ( void )
{
return F_154 ( & V_326 ) ;
}
static void T_9 F_155 ( void )
{
F_156 ( & V_326 ) ;
}
