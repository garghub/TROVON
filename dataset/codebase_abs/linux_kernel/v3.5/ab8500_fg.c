struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
if ( F_2 ( & V_3 ) )
return NULL ;
V_2 = F_3 ( & V_3 , struct V_1 , V_4 ) ;
return V_2 ;
}
static T_1 F_4 ( int V_5 )
{
int V_6 ;
if ( V_5 < V_7 [ 0 ] )
return 0 ;
for ( V_6 = 0 ; V_6 < F_5 ( V_7 ) ; V_6 ++ ) {
if ( V_5 < V_7 [ V_6 ] )
return ( T_1 ) V_6 - 1 ;
}
return ( T_1 ) F_5 ( V_7 ) - 1 ;
}
static int F_6 ( struct V_1 * V_8 , int V_9 )
{
if ( V_9 > - V_8 -> V_10 -> V_11 -> V_12 )
return true ;
else
return false ;
}
static int F_7 ( struct V_1 * V_8 , int V_13 )
{
struct V_14 V_15 ;
struct V_16 * V_17 = & V_8 -> V_18 ;
F_8 ( & V_15 ) ;
do {
V_17 -> V_19 += V_13 - V_17 -> V_20 [ V_17 -> V_21 ] ;
V_17 -> V_20 [ V_17 -> V_21 ] = V_13 ;
V_17 -> V_22 [ V_17 -> V_21 ] = V_15 . V_23 ;
V_17 -> V_21 ++ ;
if ( V_17 -> V_21 == V_24 )
V_17 -> V_21 = 0 ;
if ( V_17 -> V_25 < V_24 )
V_17 -> V_25 ++ ;
} while ( V_15 . V_23 - V_26 > V_17 -> V_22 [ V_17 -> V_21 ] );
V_17 -> V_17 = V_17 -> V_19 / V_17 -> V_25 ;
return V_17 -> V_17 ;
}
static void F_9 ( struct V_1 * V_8 )
{
int V_6 ;
struct V_16 * V_17 = & V_8 -> V_18 ;
V_17 -> V_21 = 0 ;
V_17 -> V_25 = 0 ;
V_17 -> V_19 = 0 ;
V_17 -> V_17 = 0 ;
for ( V_6 = 0 ; V_6 < V_24 ; V_6 ++ ) {
V_17 -> V_20 [ V_6 ] = 0 ;
V_17 -> V_22 [ V_6 ] = 0 ;
}
}
static void F_10 ( struct V_1 * V_8 , int V_13 )
{
int V_6 ;
struct V_14 V_15 ;
struct V_16 * V_17 = & V_8 -> V_18 ;
F_8 ( & V_15 ) ;
for ( V_6 = 0 ; V_6 < V_24 ; V_6 ++ ) {
V_17 -> V_20 [ V_6 ] = V_13 ;
V_17 -> V_22 [ V_6 ] = V_15 . V_23 ;
}
V_17 -> V_21 = 0 ;
V_17 -> V_25 = V_24 ;
V_17 -> V_19 = V_13 * V_24 ;
V_17 -> V_17 = V_13 ;
}
static int F_11 ( struct V_1 * V_8 , bool V_27 )
{
int V_28 = 0 ;
F_12 ( & V_8 -> V_29 ) ;
if ( V_27 ) {
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 , 0x00 ) ;
if ( V_28 )
goto V_33;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_35 ,
V_8 -> V_36 ) ;
if ( V_28 )
goto V_33;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 ,
( V_37 | V_38 ) ) ;
if ( V_28 )
goto V_33;
V_8 -> V_39 . V_40 = true ;
} else {
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_41 , 0 ) ;
if ( V_28 )
goto V_33;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_42 , 0 ) ;
if ( V_28 )
goto V_33;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 , 0 ) ;
if ( V_28 )
goto V_33;
V_8 -> V_39 . V_40 = false ;
}
F_14 ( V_8 -> V_30 , L_1 ,
V_27 , V_8 -> V_36 ) ;
F_15 ( & V_8 -> V_29 ) ;
return V_28 ;
V_33:
F_16 ( V_8 -> V_30 , L_2 , V_43 ) ;
F_15 ( & V_8 -> V_29 ) ;
return V_28 ;
}
int F_17 ( struct V_1 * V_8 )
{
T_1 V_44 ;
int V_28 ;
F_12 ( & V_8 -> V_29 ) ;
V_28 = F_18 ( V_8 -> V_30 , V_31 ,
V_32 , & V_44 ) ;
if ( V_28 < 0 )
goto V_45;
if ( ! ( V_44 & V_38 ) ) {
F_14 ( V_8 -> V_30 , L_3 , V_43 ) ;
V_8 -> V_46 = true ;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_35 ,
F_19 ( 10 ) ) ;
if ( V_28 )
goto V_45;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 ,
( V_37 | V_38 ) ) ;
if ( V_28 )
goto V_45;
} else {
V_8 -> V_46 = false ;
}
F_20 ( V_8 -> V_47 ) ;
F_21 ( V_8 -> V_48 ) ;
return 0 ;
V_45:
F_15 ( & V_8 -> V_29 ) ;
return V_28 ;
}
int F_22 ( struct V_1 * V_8 )
{
return F_23 ( & V_8 -> V_47 ) ;
}
int F_24 ( struct V_1 * V_8 , int * V_49 )
{
T_1 V_50 , V_51 ;
int V_52 ;
int V_28 ;
int V_53 ;
if ( ! F_23 ( & V_8 -> V_47 ) ) {
V_53 = F_25 ( & V_8 -> V_47 ,
V_54 ) ;
F_14 ( V_8 -> V_30 , L_4 ,
( ( V_54 - V_53 ) * 1000 ) / V_55 ) ;
if ( ! V_53 ) {
V_28 = - V_56 ;
F_26 ( V_8 -> V_48 ) ;
F_16 ( V_8 -> V_30 , L_5 ,
__LINE__ ) ;
goto V_45;
}
}
F_26 ( V_8 -> V_48 ) ;
V_28 = F_27 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_57 , V_57 ) ;
F_28 ( 100 , 100 ) ;
V_28 = F_18 ( V_8 -> V_30 , V_34 ,
V_58 , & V_50 ) ;
if ( V_28 < 0 )
goto V_45;
V_28 = F_18 ( V_8 -> V_30 , V_34 ,
V_59 , & V_51 ) ;
if ( V_28 < 0 )
goto V_45;
if ( V_51 & 0x10 )
V_52 = ( V_50 | ( V_51 << 8 ) | 0xFFFFE000 ) ;
else
V_52 = ( V_50 | ( V_51 << 8 ) ) ;
V_52 = ( V_52 * V_60 * 36 * 4 ) /
( 1000 * V_8 -> V_10 -> V_61 ) ;
if ( V_8 -> V_46 ) {
F_14 ( V_8 -> V_30 , L_6 , V_43 ) ;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_41 , 0 ) ;
if ( V_28 )
goto V_45;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 , 0 ) ;
if ( V_28 )
goto V_45;
}
F_15 ( & V_8 -> V_29 ) ;
( * V_49 ) = V_52 ;
return 0 ;
V_45:
F_15 ( & V_8 -> V_29 ) ;
return V_28 ;
}
int F_29 ( struct V_1 * V_8 )
{
int V_28 ;
int V_49 = 0 ;
V_28 = F_17 ( V_8 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_7 ) ;
return 0 ;
}
V_28 = F_24 ( V_8 , & V_49 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_8 ) ;
return 0 ;
}
return V_49 ;
}
static void F_30 ( struct V_62 * V_63 )
{
int V_52 ;
int V_28 ;
T_1 V_50 , V_64 , V_51 ;
struct V_1 * V_8 = F_31 ( V_63 ,
struct V_1 , V_65 ) ;
F_12 ( & V_8 -> V_29 ) ;
V_28 = F_13 ( V_8 -> V_30 , V_34 ,
V_42 , V_66 ) ;
if ( V_28 )
goto exit;
V_28 = F_18 ( V_8 -> V_30 , V_34 ,
V_67 , & V_50 ) ;
if ( V_28 < 0 )
goto exit;
V_28 = F_18 ( V_8 -> V_30 , V_34 ,
V_68 , & V_64 ) ;
if ( V_28 < 0 )
goto exit;
V_28 = F_18 ( V_8 -> V_30 , V_34 ,
V_69 , & V_51 ) ;
if ( V_28 < 0 )
goto exit;
if ( V_51 & 0x10 )
V_52 = ( V_50 | ( V_64 << 8 ) | ( V_51 << 16 ) | 0xFFE00000 ) ;
else
V_52 = ( V_50 | ( V_64 << 8 ) | ( V_51 << 16 ) ) ;
V_8 -> V_70 = ( V_52 * V_60 ) /
( 100 * V_8 -> V_10 -> V_61 ) ;
V_8 -> V_71 = ( V_52 * V_60 * 36 ) /
( 1000 * V_8 -> V_10 -> V_61 * ( V_8 -> V_36 / 4 ) ) ;
V_8 -> V_39 . V_72 = true ;
F_15 ( & V_8 -> V_29 ) ;
F_32 ( V_8 -> V_73 , & V_8 -> V_74 ) ;
return;
exit:
F_16 ( V_8 -> V_30 ,
L_9 ) ;
F_15 ( & V_8 -> V_29 ) ;
F_32 ( V_8 -> V_73 , & V_8 -> V_74 ) ;
}
static int F_33 ( struct V_1 * V_8 )
{
int V_75 ;
static int V_76 ;
V_75 = F_34 ( V_8 -> V_77 , V_78 ) ;
if ( V_75 < 0 ) {
F_16 ( V_8 -> V_30 ,
L_10 ,
V_43 ) ;
return V_76 ;
}
V_76 = V_75 ;
return V_75 ;
}
static int F_35 ( struct V_1 * V_8 , int V_5 )
{
int V_6 , V_79 ;
struct V_80 * V_81 ;
int V_82 = 0 ;
V_81 = V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] . V_85 ,
V_79 = V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] . V_86 ;
for ( V_6 = 0 ; V_6 < V_79 ; ++ V_6 ) {
if ( V_5 > V_81 [ V_6 ] . V_5 )
break;
}
if ( ( V_6 > 0 ) && ( V_6 < V_79 ) ) {
V_82 = F_36 ( V_5 ,
V_81 [ V_6 ] . V_5 ,
V_81 [ V_6 ] . V_87 * 10 ,
V_81 [ V_6 - 1 ] . V_5 ,
V_81 [ V_6 - 1 ] . V_87 * 10 ) ;
} else if ( V_6 == 0 ) {
V_82 = 1000 ;
} else {
V_82 = 0 ;
}
F_14 ( V_8 -> V_30 , L_11 ,
V_43 , V_5 , V_82 ) ;
return V_82 ;
}
static int F_37 ( struct V_1 * V_8 )
{
V_8 -> V_75 = F_33 ( V_8 ) ;
return F_35 ( V_8 , V_8 -> V_75 ) ;
}
static int F_38 ( struct V_1 * V_8 )
{
int V_6 , V_79 ;
struct V_88 * V_81 ;
int V_89 = 0 ;
V_81 = V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] . V_90 ;
V_79 = V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] . V_91 ;
for ( V_6 = 0 ; V_6 < V_79 ; ++ V_6 ) {
if ( V_8 -> V_92 / 10 > V_81 [ V_6 ] . V_93 )
break;
}
if ( ( V_6 > 0 ) && ( V_6 < V_79 ) ) {
V_89 = F_36 ( V_8 -> V_92 / 10 ,
V_81 [ V_6 ] . V_93 ,
V_81 [ V_6 ] . V_89 ,
V_81 [ V_6 - 1 ] . V_93 ,
V_81 [ V_6 - 1 ] . V_89 ) ;
} else if ( V_6 == 0 ) {
V_89 = V_81 [ 0 ] . V_89 ;
} else {
V_89 = V_81 [ V_79 - 1 ] . V_89 ;
}
F_14 ( V_8 -> V_30 , L_12
L_13 ,
V_43 , V_8 -> V_92 , V_89 , V_8 -> V_10 -> V_61 / 10 ,
( V_8 -> V_10 -> V_61 / 10 ) + V_89 ) ;
V_89 += V_8 -> V_10 -> V_61 / 10 ;
return V_89 ;
}
static int F_39 ( struct V_1 * V_8 )
{
int V_94 , V_49 ;
int V_6 = 0 ;
int V_75 = 0 ;
F_17 ( V_8 ) ;
do {
V_75 += F_33 ( V_8 ) ;
V_6 ++ ;
F_40 ( 5 ) ;
} while ( ! F_22 ( V_8 ) );
F_24 ( V_8 , & V_8 -> V_95 ) ;
V_8 -> V_75 = V_75 / V_6 ;
V_49 = F_38 ( V_8 ) ;
V_94 = V_8 -> V_75 - ( V_8 -> V_95 * V_49 ) / 1000 ;
F_14 ( V_8 -> V_30 , L_14
L_15 ,
V_43 , V_8 -> V_75 , V_94 , V_49 , V_8 -> V_95 , V_6 ) ;
return F_35 ( V_8 , V_94 ) ;
}
static int F_41 ( struct V_1 * V_8 , int V_96 )
{
return ( V_96 * 1000 ) / V_8 -> V_97 . V_98 ;
}
static int F_42 ( struct V_1 * V_8 , int V_99 )
{
return V_99 * V_8 -> V_97 . V_98 / 1000 ;
}
static int F_43 ( struct V_1 * V_8 , int V_96 )
{
T_2 V_100 ;
T_3 V_101 ;
V_100 = ( ( T_2 ) V_96 ) * ( ( T_2 ) V_8 -> V_102 ) ;
V_101 = F_44 ( V_100 , 1000 ) ;
if ( V_101 >= 1000 / 2 )
V_100 ++ ;
return ( int ) V_100 ;
}
static int F_45 ( struct V_1 * V_8 )
{
F_14 ( V_8 -> V_30 , L_16 ,
V_43 ,
V_8 -> V_97 . V_103 ,
V_8 -> V_70 ) ;
if ( V_8 -> V_97 . V_103 + V_8 -> V_70 > 0 )
V_8 -> V_97 . V_103 += V_8 -> V_70 ;
else
V_8 -> V_97 . V_103 = 0 ;
if ( V_8 -> V_97 . V_103 >= V_8 -> V_97 . V_98 ||
V_8 -> V_39 . V_104 ) {
V_8 -> V_97 . V_103 = V_8 -> V_97 . V_98 ;
}
F_10 ( V_8 , V_8 -> V_97 . V_103 ) ;
V_8 -> V_97 . V_105 =
F_41 ( V_8 , V_8 -> V_97 . V_103 ) ;
V_8 -> V_75 = F_33 ( V_8 ) ;
V_8 -> V_95 = F_29 ( V_8 ) ;
return V_8 -> V_97 . V_103 ;
}
static int F_46 ( struct V_1 * V_8 , bool V_106 )
{
int V_105 , V_103 ;
if ( V_106 )
V_105 = F_39 ( V_8 ) ;
else
V_105 = F_37 ( V_8 ) ;
V_103 = F_42 ( V_8 , V_105 ) ;
V_8 -> V_97 . V_103 = F_7 ( V_8 , V_103 ) ;
V_8 -> V_97 . V_105 =
F_41 ( V_8 , V_8 -> V_97 . V_103 ) ;
return V_8 -> V_97 . V_103 ;
}
static int F_47 ( struct V_1 * V_8 )
{
int V_107 , V_105 ;
F_14 ( V_8 -> V_30 , L_16 ,
V_43 ,
V_8 -> V_97 . V_103 ,
V_8 -> V_70 ) ;
if ( V_8 -> V_97 . V_103 + V_8 -> V_70 > 0 )
V_8 -> V_97 . V_103 += V_8 -> V_70 ;
else
V_8 -> V_97 . V_103 = 0 ;
if ( V_8 -> V_97 . V_103 >= V_8 -> V_97 . V_98 )
V_8 -> V_97 . V_103 = V_8 -> V_97 . V_98 ;
V_105 = F_41 ( V_8 , V_8 -> V_97 . V_103 ) ;
V_107 = F_37 ( V_8 ) ;
if ( V_105 < V_107 ) {
V_8 -> V_97 . V_105 = V_107 ;
V_8 -> V_97 . V_103 = F_42 ( V_8 ,
V_8 -> V_97 . V_105 ) ;
F_14 ( V_8 -> V_30 , L_17 ,
V_43 ,
V_105 ,
V_107 ) ;
F_10 ( V_8 , V_8 -> V_97 . V_103 ) ;
} else {
F_10 ( V_8 , V_8 -> V_97 . V_103 ) ;
V_8 -> V_97 . V_105 =
F_41 ( V_8 , V_8 -> V_97 . V_103 ) ;
}
return V_8 -> V_97 . V_103 ;
}
static int F_48 ( struct V_1 * V_8 )
{
int V_28 , V_108 ;
V_108 = V_8 -> V_97 . V_105 / 10 ;
if ( V_108 <= V_8 -> V_10 -> V_109 -> V_110 ||
V_8 -> V_39 . V_111 )
V_28 = V_112 ;
else if ( V_108 <= V_8 -> V_10 -> V_109 -> V_50 )
V_28 = V_113 ;
else if ( V_108 <= V_8 -> V_10 -> V_109 -> V_114 )
V_28 = V_115 ;
else if ( V_108 <= V_8 -> V_10 -> V_109 -> V_51 )
V_28 = V_116 ;
else
V_28 = V_117 ;
return V_28 ;
}
static void F_49 ( struct V_1 * V_8 , bool V_118 )
{
bool V_119 = false ;
V_8 -> V_97 . V_120 = F_48 ( V_8 ) ;
if ( V_8 -> V_97 . V_120 != V_8 -> V_97 . V_121 ) {
if ( ! ( ! V_8 -> V_39 . V_122 && V_8 -> V_97 . V_120 >
V_8 -> V_97 . V_121 ) || V_118 ) {
F_14 ( V_8 -> V_30 , L_18 ,
V_8 -> V_97 . V_121 ,
V_8 -> V_97 . V_120 ) ;
V_8 -> V_97 . V_121 = V_8 -> V_97 . V_120 ;
V_119 = true ;
} else {
F_14 ( V_8 -> V_30 , L_19
L_20 ,
V_8 -> V_97 . V_121 ,
V_8 -> V_97 . V_120 ) ;
}
}
if ( V_8 -> V_39 . V_111 ) {
F_14 ( V_8 -> V_30 , L_21 ) ;
V_8 -> V_97 . V_123 = 0 ;
V_8 -> V_97 . V_105 = 0 ;
V_8 -> V_97 . V_124 = 0 ;
V_8 -> V_97 . V_103 = 0 ;
V_119 = true ;
} else if ( V_8 -> V_39 . V_125 ) {
if ( V_8 -> V_39 . V_104 ) {
V_8 -> V_97 . V_123 = V_8 -> V_97 . V_105 / 10 ;
V_8 -> V_97 . V_124 = V_8 -> V_97 . V_103 ;
} else if ( ! V_8 -> V_39 . V_104 &&
V_8 -> V_97 . V_123 !=
( V_8 -> V_97 . V_105 ) / 10 &&
( V_8 -> V_97 . V_105 / 10 ) <
V_8 -> V_10 -> V_11 -> V_126 ) {
F_14 ( V_8 -> V_30 ,
L_22
L_23 ,
V_8 -> V_97 . V_105 / 10 ) ;
V_8 -> V_97 . V_123 = V_8 -> V_97 . V_105 / 10 ;
V_8 -> V_97 . V_124 = V_8 -> V_97 . V_103 ;
V_119 = true ;
}
} else if ( V_8 -> V_97 . V_123 != V_8 -> V_97 . V_105 / 10 ) {
if ( V_8 -> V_97 . V_105 / 10 == 0 ) {
V_8 -> V_97 . V_123 = 1 ;
V_8 -> V_97 . V_105 = 1 ;
V_8 -> V_97 . V_124 = 1 ;
V_8 -> V_97 . V_103 = 1 ;
V_119 = true ;
} else if ( ! ( ! V_8 -> V_39 . V_122 &&
( V_8 -> V_97 . V_105 / 10 ) >
V_8 -> V_97 . V_123 ) || V_118 ) {
F_14 ( V_8 -> V_30 ,
L_24 ,
V_8 -> V_97 . V_123 ,
V_8 -> V_97 . V_105 / 10 ,
V_8 -> V_97 . V_105 ) ;
V_8 -> V_97 . V_123 = V_8 -> V_97 . V_105 / 10 ;
V_8 -> V_97 . V_124 = V_8 -> V_97 . V_103 ;
V_119 = true ;
} else {
F_14 ( V_8 -> V_30 , L_25
L_26 ,
V_8 -> V_97 . V_123 ,
V_8 -> V_97 . V_105 / 10 ,
V_8 -> V_97 . V_105 ) ;
}
}
if ( V_119 ) {
F_50 ( & V_8 -> V_127 ) ;
if ( V_8 -> V_39 . V_125 && V_8 -> V_39 . V_104 ) {
F_14 ( V_8 -> V_30 , L_27 ) ;
V_8 -> V_39 . V_104 = false ;
F_51 ( & V_8 -> V_128 , NULL , L_28 ) ;
}
F_51 ( & V_8 -> V_128 , NULL , L_29 ) ;
}
}
static void F_52 ( struct V_1 * V_8 ,
enum V_129 V_130 )
{
F_14 ( V_8 -> V_30 , L_30 ,
V_8 -> V_131 ,
V_131 [ V_8 -> V_131 ] ,
V_130 ,
V_131 [ V_130 ] ) ;
V_8 -> V_131 = V_130 ;
}
static void F_53 ( struct V_1 * V_8 ,
enum V_132 V_130 )
{
F_14 ( V_8 -> V_30 , L_31 ,
V_8 -> V_133 ,
V_133 [ V_8 -> V_133 ] ,
V_130 ,
V_133 [ V_130 ] ) ;
V_8 -> V_133 = V_130 ;
}
static void F_54 ( struct V_1 * V_8 )
{
if ( V_8 -> V_133 != V_134 )
F_53 ( V_8 ,
V_134 ) ;
switch ( V_8 -> V_131 ) {
case V_135 :
V_8 -> V_36 = F_19 (
V_8 -> V_10 -> V_11 -> V_136 ) ;
F_11 ( V_8 , true ) ;
F_52 ( V_8 , V_137 ) ;
break;
case V_137 :
F_12 ( & V_8 -> V_29 ) ;
if ( ! V_8 -> V_39 . V_72 ) {
F_15 ( & V_8 -> V_29 ) ;
F_14 ( V_8 -> V_30 , L_32 ,
V_43 ) ;
break;
}
V_8 -> V_39 . V_72 = false ;
F_15 ( & V_8 -> V_29 ) ;
F_45 ( V_8 ) ;
break;
default:
break;
}
F_49 ( V_8 , false ) ;
}
static void F_55 ( struct V_1 * V_8 )
{
int V_82 ;
F_9 ( V_8 ) ;
V_82 = V_8 -> V_97 . V_138 ;
if ( V_82 > V_8 -> V_97 . V_98 ) {
F_14 ( V_8 -> V_30 , L_33
L_34 , V_82 , V_8 -> V_97 . V_98 ) ;
V_82 = V_8 -> V_97 . V_98 ;
}
F_10 ( V_8 , V_8 -> V_97 . V_138 ) ;
V_8 -> V_97 . V_105 = F_41 ( V_8 , V_82 ) ;
V_8 -> V_97 . V_103 = V_82 ;
F_49 ( V_8 , true ) ;
}
static bool F_56 ( struct V_1 * V_8 )
{
int V_82 , V_139 , V_140 ;
int V_141 ;
V_82 = V_8 -> V_97 . V_138 ;
V_141 = F_41 ( V_8 ,
V_8 -> V_97 . V_138 ) ;
V_139 = V_8 -> V_97 . V_105 - V_8 -> V_10 -> V_11 -> V_142 * 10 ;
V_140 = V_8 -> V_97 . V_105 + V_8 -> V_10 -> V_11 -> V_142 * 10 ;
if ( V_139 < 0 )
V_139 = 0 ;
if ( V_140 > 1000 )
V_140 = 1000 ;
F_14 ( V_8 -> V_30 , L_35
L_36 ,
V_139 , V_141 , V_140 , V_82 , V_8 -> V_97 . V_103 ) ;
if ( V_141 > V_139 && V_141 < V_140 ) {
F_14 ( V_8 -> V_30 , L_37 , V_82 ) ;
F_55 ( V_8 ) ;
return true ;
}
F_14 ( V_8 -> V_30 , L_38 ) ;
return false ;
}
static void F_57 ( struct V_1 * V_8 )
{
int V_143 ;
if ( V_8 -> V_131 != V_135 )
F_52 ( V_8 , V_135 ) ;
switch ( V_8 -> V_133 ) {
case V_144 :
V_8 -> V_145 = 0 ;
V_8 -> V_36 = F_19 ( V_8 -> V_10 -> V_11 -> V_146 ) ;
F_11 ( V_8 , true ) ;
F_53 ( V_8 ,
V_147 ) ;
case V_147 :
V_143 = V_8 -> V_10 -> V_11 -> V_146 ;
if ( V_8 -> V_145 >
V_8 -> V_10 -> V_11 -> V_148 ) {
F_46 ( V_8 , true ) ;
F_49 ( V_8 , true ) ;
}
V_8 -> V_145 += V_143 ;
if ( V_8 -> V_145 > V_8 -> V_10 -> V_11 -> V_149 )
F_53 ( V_8 ,
V_150 ) ;
break;
case V_134 :
V_8 -> V_151 = 0 ;
V_8 -> V_152 = true ;
F_53 ( V_8 ,
V_153 ) ;
case V_153 :
V_143 = V_8 -> V_10 -> V_11 -> V_154 ;
V_8 -> V_95 = F_29 ( V_8 ) ;
if ( F_6 ( V_8 , V_8 -> V_95 ) ) {
if ( V_8 -> V_151 >
V_8 -> V_10 -> V_11 -> V_155 ) {
V_8 -> V_36 = F_19 (
V_8 -> V_10 -> V_11 -> V_156 ) ;
F_11 ( V_8 , true ) ;
F_53 ( V_8 ,
V_157 ) ;
V_8 -> V_152 = false ;
} else {
F_58 ( V_8 -> V_73 ,
& V_8 -> V_158 ,
V_143 * V_55 ) ;
}
V_8 -> V_151 += V_143 ;
} else {
V_8 -> V_36 = F_19 (
V_8 -> V_10 -> V_11 -> V_156 ) ;
F_11 ( V_8 , true ) ;
F_53 ( V_8 ,
V_157 ) ;
}
break;
case V_150 :
V_8 -> V_36 = F_19 (
V_8 -> V_10 -> V_11 -> V_156 ) ;
F_11 ( V_8 , true ) ;
F_53 ( V_8 ,
V_157 ) ;
break;
case V_157 :
V_8 -> V_95 = F_29 ( V_8 ) ;
if ( F_6 ( V_8 , V_8 -> V_95 ) ) {
if ( V_8 -> V_159 ) {
V_8 -> V_159 = false ;
V_8 -> V_160 = 0 ;
}
if ( V_8 -> V_152 ) {
F_53 ( V_8 ,
V_153 ) ;
F_58 ( V_8 -> V_73 ,
& V_8 -> V_158 , 0 ) ;
break;
}
F_46 ( V_8 , true ) ;
} else {
F_12 ( & V_8 -> V_29 ) ;
if ( ! V_8 -> V_39 . V_72 ) {
F_15 ( & V_8 -> V_29 ) ;
F_14 ( V_8 -> V_30 , L_32 ,
V_43 ) ;
break;
}
V_8 -> V_39 . V_72 = false ;
F_15 ( & V_8 -> V_29 ) ;
if ( ! V_8 -> V_159 ) {
V_8 -> V_159 = true ;
V_8 -> V_160 = 0 ;
}
V_8 -> V_160 +=
V_8 -> V_10 -> V_11 -> V_156 ;
if ( V_8 -> V_160 >
V_8 -> V_10 -> V_11 -> V_161 )
V_8 -> V_152 = true ;
F_47 ( V_8 ) ;
}
F_49 ( V_8 , false ) ;
break;
case V_162 :
F_11 ( V_8 , true ) ;
V_8 -> V_95 = F_29 ( V_8 ) ;
F_46 ( V_8 , true ) ;
V_8 -> V_36 = F_19 (
V_8 -> V_10 -> V_11 -> V_156 ) ;
F_11 ( V_8 , true ) ;
F_53 ( V_8 ,
V_157 ) ;
F_49 ( V_8 , false ) ;
break;
default:
break;
}
}
static void F_59 ( struct V_1 * V_8 )
{
int V_28 ;
switch ( V_8 -> V_163 ) {
case V_164 :
F_14 ( V_8 -> V_30 , L_39 ) ;
V_28 = F_27 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_165 , V_166 ) ;
if ( V_28 < 0 )
goto V_167;
V_28 = F_27 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_168 , V_168 ) ;
if ( V_28 < 0 )
goto V_167;
V_8 -> V_163 = V_169 ;
break;
case V_170 :
V_28 = F_27 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_171 , V_171 ) ;
if ( V_28 < 0 )
goto V_167;
V_8 -> V_39 . V_172 = false ;
F_14 ( V_8 -> V_30 , L_40 ) ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
break;
case V_169 :
F_14 ( V_8 -> V_30 , L_41 ) ;
default:
break;
}
return;
V_167:
F_16 ( V_8 -> V_30 , L_42 ) ;
V_8 -> V_39 . V_172 = false ;
V_8 -> V_163 = V_164 ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
}
static void F_60 ( struct V_1 * V_8 )
{
if ( V_8 -> V_39 . V_172 )
F_59 ( V_8 ) ;
else {
if ( V_8 -> V_39 . V_122 )
F_54 ( V_8 ) ;
else
F_57 ( V_8 ) ;
}
F_14 ( V_8 -> V_30 , L_43
L_44 ,
V_8 -> V_97 . V_98 ,
V_8 -> V_97 . V_103 ,
V_8 -> V_97 . V_105 ,
V_8 -> V_97 . V_120 ,
V_8 -> V_97 . V_124 ,
V_8 -> V_97 . V_123 ,
V_8 -> V_97 . V_121 ,
V_8 -> V_75 ,
V_8 -> V_95 ,
V_8 -> V_71 ,
V_8 -> V_70 ,
V_8 -> V_39 . V_122 ,
V_8 -> V_131 ,
V_8 -> V_133 ,
V_8 -> V_159 ,
V_8 -> V_152 ) ;
}
static void F_61 ( struct V_62 * V_63 )
{
struct V_1 * V_8 = F_31 ( V_63 , struct V_1 ,
V_158 . V_63 ) ;
if ( V_8 -> V_173 ) {
V_8 -> V_95 = F_29 ( V_8 ) ;
F_46 ( V_8 , true ) ;
F_49 ( V_8 , true ) ;
V_8 -> V_173 = false ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
} else if ( V_8 -> V_39 . V_174 ) {
if ( F_56 ( V_8 ) ) {
F_49 ( V_8 , true ) ;
if ( V_8 -> V_39 . V_122 )
F_52 ( V_8 ,
V_135 ) ;
else
F_53 ( V_8 ,
V_150 ) ;
}
V_8 -> V_39 . V_174 = false ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
} else
F_60 ( V_8 ) ;
}
static void F_62 ( struct V_62 * V_63 )
{
int V_28 ;
T_1 V_175 ;
struct V_1 * V_8 = F_31 ( V_63 , struct V_1 ,
V_176 . V_63 ) ;
if ( V_8 -> V_39 . V_177 ) {
V_28 = F_18 ( V_8 -> V_30 ,
V_178 , V_179 ,
& V_175 ) ;
if ( V_28 < 0 ) {
F_16 ( V_8 -> V_30 , L_45 , V_43 ) ;
return;
}
if ( ( V_175 & V_180 ) != V_180 ) {
F_14 ( V_8 -> V_30 , L_46 ) ;
V_8 -> V_39 . V_177 = false ;
F_50 ( & V_8 -> V_127 ) ;
return;
}
F_58 ( V_8 -> V_73 , & V_8 -> V_176 ,
F_63 ( V_55 ) ) ;
}
}
static void F_64 ( struct V_62 * V_63 )
{
int V_75 ;
struct V_1 * V_8 = F_31 ( V_63 , struct V_1 ,
V_181 . V_63 ) ;
V_75 = F_33 ( V_8 ) ;
if ( V_75 < V_8 -> V_10 -> V_11 -> V_182 ) {
V_8 -> V_39 . V_111 = true ;
F_65 ( V_8 -> V_30 , L_47 ) ;
F_58 ( V_8 -> V_73 , & V_8 -> V_181 ,
F_63 ( V_183 ) ) ;
} else {
V_8 -> V_39 . V_111 = false ;
F_65 ( V_8 -> V_30 , L_48 ) ;
}
F_49 ( V_8 , false ) ;
V_8 -> V_39 . V_184 = false ;
}
static int F_66 ( struct V_1 * V_8 , int V_185 )
{
if ( V_185 > V_186 +
( V_187 * V_188 ) )
return V_188 ;
if ( V_185 < V_186 )
return 0 ;
return ( V_185 - V_186 ) / V_187 ;
}
static int F_67 ( struct V_1 * V_8 )
{
int V_189 ;
int V_190 ;
int V_191 ;
int V_192 ;
int V_193 ;
int V_28 ;
int V_194 ;
V_190 = V_8 -> V_10 -> V_11 -> V_195 ;
V_191 = V_8 -> V_10 -> V_11 -> V_196 ;
V_192 = F_66 ( V_8 , V_190 ) ;
V_193 = F_66 ( V_8 , V_191 ) ;
V_189 = V_186 + V_192 * V_187 ;
if ( V_189 != V_190 )
F_65 ( V_8 -> V_30 , L_49 ,
V_190 , V_189 , V_192 ) ;
V_189 = V_186 + V_193 * V_187 ;
if ( V_189 != V_191 )
F_65 ( V_8 -> V_30 , L_49 ,
V_191 , V_189 , V_193 ) ;
V_194 = V_192 | ( V_193 << 4 ) ;
F_14 ( V_8 -> V_30 , L_50 , V_194 , V_192 , V_193 ) ;
V_28 = F_13 ( V_8 -> V_30 , V_197 ,
V_198 , V_194 ) ;
return V_28 ;
}
static void F_68 ( struct V_62 * V_63 )
{
struct V_1 * V_8 = F_31 ( V_63 , struct V_1 , V_74 ) ;
F_60 ( V_8 ) ;
}
static T_4 F_69 ( int V_48 , void * V_199 )
{
struct V_1 * V_8 = V_199 ;
F_70 ( & V_8 -> V_47 ) ;
return V_200 ;
}
static T_4 F_71 ( int V_48 , void * V_199 )
{
struct V_1 * V_8 = V_199 ;
V_8 -> V_163 = V_170 ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
return V_200 ;
}
static T_4 F_72 ( int V_48 , void * V_199 )
{
struct V_1 * V_8 = V_199 ;
F_32 ( V_8 -> V_73 , & V_8 -> V_65 ) ;
return V_200 ;
}
static T_4 F_73 ( int V_48 , void * V_199 )
{
struct V_1 * V_8 = V_199 ;
F_14 ( V_8 -> V_30 , L_51 ) ;
V_8 -> V_39 . V_177 = true ;
F_50 ( & V_8 -> V_127 ) ;
F_58 ( V_8 -> V_73 , & V_8 -> V_176 , 0 ) ;
return V_200 ;
}
static T_4 F_74 ( int V_48 , void * V_199 )
{
struct V_1 * V_8 = V_199 ;
if ( ! V_8 -> V_39 . V_184 ) {
F_65 ( V_8 -> V_30 , L_52 ) ;
V_8 -> V_39 . V_184 = true ;
F_58 ( V_8 -> V_73 , & V_8 -> V_181 ,
F_63 ( V_183 ) ) ;
}
return V_200 ;
}
static int F_75 ( struct V_201 * V_202 ,
enum V_203 V_204 ,
union V_205 * V_52 )
{
struct V_1 * V_8 ;
V_8 = F_76 ( V_202 ) ;
switch ( V_204 ) {
case V_206 :
if ( V_8 -> V_39 . V_177 )
V_52 -> V_207 = V_208 * 1000 ;
else
V_52 -> V_207 = V_8 -> V_75 * 1000 ;
break;
case V_209 :
V_52 -> V_207 = V_8 -> V_95 * 1000 ;
break;
case V_210 :
V_52 -> V_207 = V_8 -> V_71 * 1000 ;
break;
case V_211 :
V_52 -> V_207 = F_43 ( V_8 ,
V_8 -> V_97 . V_98 ) ;
break;
case V_212 :
V_52 -> V_207 = F_43 ( V_8 ,
V_8 -> V_97 . V_213 ) ;
break;
case V_214 :
if ( V_8 -> V_39 . V_215 && ! V_8 -> V_10 -> V_216 &&
V_8 -> V_39 . V_217 )
V_52 -> V_207 = F_43 ( V_8 ,
V_8 -> V_97 . V_213 ) ;
else
V_52 -> V_207 = F_43 ( V_8 ,
V_8 -> V_97 . V_124 ) ;
break;
case V_218 :
V_52 -> V_207 = V_8 -> V_97 . V_98 ;
break;
case V_219 :
V_52 -> V_207 = V_8 -> V_97 . V_213 ;
break;
case V_220 :
if ( V_8 -> V_39 . V_215 && ! V_8 -> V_10 -> V_216 &&
V_8 -> V_39 . V_217 )
V_52 -> V_207 = V_8 -> V_97 . V_213 ;
else
V_52 -> V_207 = V_8 -> V_97 . V_124 ;
break;
case V_221 :
if ( V_8 -> V_39 . V_215 && ! V_8 -> V_10 -> V_216 &&
V_8 -> V_39 . V_217 )
V_52 -> V_207 = 100 ;
else
V_52 -> V_207 = V_8 -> V_97 . V_123 ;
break;
case V_222 :
if ( V_8 -> V_39 . V_215 && ! V_8 -> V_10 -> V_216 &&
V_8 -> V_39 . V_217 )
V_52 -> V_207 = V_223 ;
else
V_52 -> V_207 = V_8 -> V_97 . V_121 ;
break;
default:
return - V_224 ;
}
return 0 ;
}
static int F_77 ( struct V_225 * V_30 , void * V_226 )
{
struct V_201 * V_202 ;
struct V_201 * V_227 ;
struct V_1 * V_8 ;
union V_205 V_28 ;
int V_6 , V_228 ;
bool V_229 = false ;
V_202 = (struct V_201 * ) V_226 ;
V_227 = F_78 ( V_30 ) ;
V_8 = F_76 ( V_202 ) ;
for ( V_6 = 0 ; V_6 < V_227 -> V_230 ; V_6 ++ ) {
if ( ! strcmp ( V_227 -> V_231 [ V_6 ] , V_202 -> V_232 ) )
V_229 = true ;
}
if ( ! V_229 )
return 0 ;
for ( V_228 = 0 ; V_228 < V_227 -> V_233 ; V_228 ++ ) {
enum V_203 V_234 ;
V_234 = V_227 -> V_235 [ V_228 ] ;
if ( V_227 -> V_236 ( V_227 , V_234 , & V_28 ) )
continue;
switch ( V_234 ) {
case V_237 :
switch ( V_227 -> type ) {
case V_238 :
switch ( V_28 . V_207 ) {
case V_239 :
case V_240 :
case V_241 :
if ( ! V_8 -> V_39 . V_122 )
break;
V_8 -> V_39 . V_122 = false ;
V_8 -> V_39 . V_125 = false ;
F_32 ( V_8 -> V_73 , & V_8 -> V_74 ) ;
break;
case V_242 :
if ( V_8 -> V_39 . V_125 )
break;
V_8 -> V_39 . V_125 = true ;
V_8 -> V_39 . V_104 = true ;
V_8 -> V_97 . V_213 = V_8 -> V_97 . V_103 ;
F_32 ( V_8 -> V_73 , & V_8 -> V_74 ) ;
break;
case V_243 :
if ( V_8 -> V_39 . V_122 )
break;
V_8 -> V_39 . V_122 = true ;
V_8 -> V_39 . V_125 = false ;
F_32 ( V_8 -> V_73 , & V_8 -> V_74 ) ;
break;
} ;
default:
break;
} ;
break;
case V_244 :
switch ( V_227 -> type ) {
case V_238 :
if ( ! V_8 -> V_39 . V_217 ) {
const struct V_245 * V_246 ;
V_246 = & ( V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] ) ;
V_8 -> V_39 . V_217 = true ;
V_8 -> V_97 . V_98 =
V_247 *
V_246 -> V_248 ;
V_8 -> V_97 . V_213 =
V_8 -> V_97 . V_98 ;
V_8 -> V_102 = V_246 -> V_249 ;
}
if ( V_28 . V_207 )
V_8 -> V_39 . V_215 = false ;
else
V_8 -> V_39 . V_215 = true ;
break;
default:
break;
}
break;
case V_250 :
switch ( V_227 -> type ) {
case V_238 :
if ( V_8 -> V_39 . V_217 )
V_8 -> V_92 = V_28 . V_207 ;
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
static int F_79 ( struct V_1 * V_8 )
{
int V_28 ;
V_28 = F_27 ( V_8 -> V_30 ,
V_178 ,
V_251 ,
V_252 ,
V_252 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_53 ) ;
goto V_253;
}
V_28 = F_27 ( V_8 -> V_30 ,
V_178 ,
V_251 ,
V_254 ,
V_254 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_54 ) ;
goto V_253;
}
V_28 = F_13 ( V_8 -> V_30 ,
V_197 ,
V_255 ,
F_4 (
V_8 -> V_10 -> V_11 -> V_182 ) << 1 |
V_256 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_55 , V_43 ) ;
goto V_253;
}
V_28 = F_67 ( V_8 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_56 ) ;
goto V_253;
}
V_253:
return V_28 ;
}
static void F_80 ( struct V_201 * V_202 )
{
struct V_1 * V_8 = F_76 ( V_202 ) ;
F_81 ( V_257 , NULL ,
& V_8 -> V_127 , F_77 ) ;
}
static void F_82 ( struct V_62 * V_63 )
{
struct V_1 * V_8 = F_31 ( V_63 , struct V_1 ,
V_258 . V_63 ) ;
if ( V_8 -> V_39 . V_172 == false ) {
F_14 ( V_8 -> V_30 , L_57 ) ;
F_9 ( V_8 ) ;
F_46 ( V_8 , true ) ;
F_52 ( V_8 , V_135 ) ;
F_53 ( V_8 , V_144 ) ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
} else {
F_16 ( V_8 -> V_30 , L_58
L_59 ) ;
F_58 ( V_8 -> V_73 , & V_8 -> V_258 ,
F_63 ( 1 ) ) ;
}
}
void F_83 ( void )
{
struct V_1 * V_8 = F_1 () ;
if ( V_8 != NULL )
F_58 ( V_8 -> V_73 , & V_8 -> V_258 , 0 ) ;
}
static T_5 F_84 ( struct V_1 * V_8 , char * V_259 )
{
return sprintf ( V_259 , L_60 , V_8 -> V_97 . V_213 ) ;
}
static T_5 F_85 ( struct V_1 * V_8 , const char * V_259 ,
T_6 V_260 )
{
unsigned long V_261 ;
T_5 V_28 = - V_224 ;
V_28 = F_86 ( V_259 , 10 , & V_261 ) ;
F_14 ( V_8 -> V_30 , L_61 , V_28 , V_261 ) ;
if ( ! V_28 ) {
V_8 -> V_97 . V_213 = ( int ) V_261 ;
V_28 = V_260 ;
}
return V_28 ;
}
static T_5 F_87 ( struct V_1 * V_8 , char * V_259 )
{
return sprintf ( V_259 , L_60 , V_8 -> V_97 . V_124 ) ;
}
static T_5 F_88 ( struct V_1 * V_8 , const char * V_259 ,
T_6 V_260 )
{
unsigned long V_262 ;
T_5 V_28 ;
V_28 = F_86 ( V_259 , 10 , & V_262 ) ;
F_14 ( V_8 -> V_30 , L_62 ,
V_28 , V_262 , V_8 -> V_97 . V_124 ) ;
if ( ! V_28 ) {
V_8 -> V_97 . V_138 = ( int ) V_262 ;
V_8 -> V_39 . V_174 = true ;
V_28 = V_260 ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
}
return V_28 ;
}
static T_5
F_89 ( struct V_263 * V_264 , struct V_265 * V_266 , char * V_259 )
{
struct V_267 * V_268 ;
struct V_1 * V_8 ;
V_268 = F_31 ( V_266 , struct V_267 , V_266 ) ;
V_8 = F_31 ( V_264 , struct V_1 , V_128 ) ;
if ( ! V_268 -> V_269 )
return - V_270 ;
return V_268 -> V_269 ( V_8 , V_259 ) ;
}
static T_5
F_90 ( struct V_263 * V_264 , struct V_265 * V_266 , const char * V_259 ,
T_6 V_260 )
{
struct V_267 * V_268 ;
struct V_1 * V_8 ;
V_268 = F_31 ( V_266 , struct V_267 , V_266 ) ;
V_8 = F_31 ( V_264 , struct V_1 , V_128 ) ;
if ( ! V_268 -> V_271 )
return - V_270 ;
return V_268 -> V_271 ( V_8 , V_259 , V_260 ) ;
}
static void F_91 ( struct V_1 * V_8 )
{
F_92 ( & V_8 -> V_128 ) ;
}
static int F_93 ( struct V_1 * V_8 )
{
int V_28 = 0 ;
V_28 = F_94 ( & V_8 -> V_128 ,
& V_272 ,
NULL , L_63 ) ;
if ( V_28 < 0 )
F_16 ( V_8 -> V_30 , L_64 ) ;
return V_28 ;
}
static int F_95 ( struct V_273 * V_274 )
{
struct V_1 * V_8 = F_96 ( V_274 ) ;
if ( ! V_8 -> V_39 . V_122 ) {
F_53 ( V_8 , V_162 ) ;
F_32 ( V_8 -> V_73 , & V_8 -> V_74 ) ;
}
return 0 ;
}
static int F_97 ( struct V_273 * V_274 ,
T_7 V_275 )
{
struct V_1 * V_8 = F_96 ( V_274 ) ;
F_98 ( & V_8 -> V_158 ) ;
if ( V_8 -> V_39 . V_40 && ! V_8 -> V_39 . V_122 )
F_11 ( V_8 , false ) ;
return 0 ;
}
static int T_8 F_99 ( struct V_273 * V_274 )
{
int V_28 = 0 ;
struct V_1 * V_8 = F_96 ( V_274 ) ;
F_100 ( & V_8 -> V_4 ) ;
V_28 = F_11 ( V_8 , false ) ;
if ( V_28 )
F_16 ( V_8 -> V_30 , L_65 ) ;
F_101 ( V_8 -> V_73 ) ;
F_91 ( V_8 ) ;
F_102 () ;
F_103 ( & V_8 -> V_127 ) ;
F_104 ( V_274 , NULL ) ;
F_105 ( V_8 ) ;
return V_28 ;
}
static int T_9 F_106 ( struct V_273 * V_274 )
{
int V_6 , V_48 ;
int V_28 = 0 ;
struct V_276 * V_277 = V_274 -> V_30 . V_278 ;
struct V_1 * V_8 ;
if ( ! V_277 ) {
F_16 ( & V_274 -> V_30 , L_66 ) ;
return - V_224 ;
}
V_8 = F_107 ( sizeof( * V_8 ) , V_279 ) ;
if ( ! V_8 )
return - V_280 ;
F_108 ( & V_8 -> V_29 ) ;
V_8 -> V_30 = & V_274 -> V_30 ;
V_8 -> V_281 = F_78 ( V_274 -> V_30 . V_281 ) ;
V_8 -> V_77 = F_109 ( L_67 ) ;
V_8 -> V_282 = V_277 -> V_2 ;
if ( ! V_8 -> V_282 ) {
F_16 ( V_8 -> V_30 , L_68 ) ;
V_28 = - V_224 ;
goto V_283;
}
V_8 -> V_10 = V_277 -> V_284 ;
if ( ! V_8 -> V_10 ) {
F_16 ( V_8 -> V_30 , L_69 ) ;
V_28 = - V_224 ;
goto V_283;
}
V_8 -> V_127 . V_232 = L_70 ;
V_8 -> V_127 . type = V_238 ;
V_8 -> V_127 . V_235 = V_285 ;
V_8 -> V_127 . V_233 = F_5 ( V_285 ) ;
V_8 -> V_127 . V_236 = F_75 ;
V_8 -> V_127 . V_231 = V_8 -> V_282 -> V_231 ;
V_8 -> V_127 . V_230 = V_8 -> V_282 -> V_230 ;
V_8 -> V_127 . V_286 = F_80 ;
V_8 -> V_97 . V_98 = V_247 *
V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] . V_248 ;
V_8 -> V_97 . V_213 = V_8 -> V_97 . V_98 ;
V_8 -> V_102 = V_8 -> V_10 -> V_83 [ V_8 -> V_10 -> V_84 ] . V_249 ;
V_8 -> V_173 = true ;
F_52 ( V_8 , V_135 ) ;
F_53 ( V_8 , V_144 ) ;
V_8 -> V_73 = F_110 ( L_71 ) ;
if ( V_8 -> V_73 == NULL ) {
F_16 ( V_8 -> V_30 , L_72 ) ;
goto V_283;
}
F_111 ( & V_8 -> V_74 , F_68 ) ;
F_111 ( & V_8 -> V_65 , F_30 ) ;
F_112 ( & V_8 -> V_258 ,
F_82 ) ;
F_112 ( & V_8 -> V_158 ,
F_61 ) ;
F_112 ( & V_8 -> V_181 ,
F_64 ) ;
F_112 ( & V_8 -> V_176 ,
F_62 ) ;
V_28 = F_79 ( V_8 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_73 ) ;
goto V_287;
}
V_8 -> V_39 . V_215 = true ;
V_8 -> V_39 . V_217 = false ;
V_28 = F_113 ( V_8 -> V_30 , & V_8 -> V_127 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_74 ) ;
goto V_287;
}
V_8 -> V_36 = F_19 ( V_8 -> V_10 -> V_11 -> V_146 ) ;
F_11 ( V_8 , true ) ;
F_114 ( & V_8 -> V_47 ) ;
for ( V_6 = 0 ; V_6 < F_5 ( V_288 ) ; V_6 ++ ) {
V_48 = F_115 ( V_274 , V_288 [ V_6 ] . V_232 ) ;
V_28 = F_116 ( V_48 , NULL , V_288 [ V_6 ] . V_289 ,
V_290 | V_291 ,
V_288 [ V_6 ] . V_232 , V_8 ) ;
if ( V_28 != 0 ) {
F_16 ( V_8 -> V_30 , L_75
, V_288 [ V_6 ] . V_232 , V_48 , V_28 ) ;
goto V_292;
}
F_14 ( V_8 -> V_30 , L_76 ,
V_288 [ V_6 ] . V_232 , V_48 , V_28 ) ;
}
V_8 -> V_48 = F_115 ( V_274 , L_77 ) ;
F_26 ( V_8 -> V_48 ) ;
F_104 ( V_274 , V_8 ) ;
V_28 = F_93 ( V_8 ) ;
if ( V_28 ) {
F_16 ( V_8 -> V_30 , L_64 ) ;
goto V_292;
}
V_8 -> V_39 . V_172 = true ;
V_8 -> V_163 = V_164 ;
V_8 -> V_92 = 210 ;
F_58 ( V_8 -> V_73 , & V_8 -> V_158 , 0 ) ;
F_117 ( & V_8 -> V_4 , & V_3 ) ;
return V_28 ;
V_292:
F_103 ( & V_8 -> V_127 ) ;
for ( V_6 = V_6 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_48 = F_115 ( V_274 , V_288 [ V_6 ] . V_232 ) ;
V_292 ( V_48 , V_8 ) ;
}
V_287:
F_101 ( V_8 -> V_73 ) ;
V_283:
F_105 ( V_8 ) ;
return V_28 ;
}
static int T_10 F_118 ( void )
{
return F_119 ( & V_293 ) ;
}
static void T_11 F_120 ( void )
{
F_121 ( & V_293 ) ;
}
