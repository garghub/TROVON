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
V_28 = F_14 ( V_8 -> V_30 ,
V_34 , V_41 ,
( V_42 | V_43 ) , 0 ) ;
if ( V_28 )
goto V_33;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_44 , 0 ) ;
if ( V_28 )
goto V_33;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 , 0 ) ;
if ( V_28 )
goto V_33;
V_8 -> V_39 . V_40 = false ;
}
F_15 ( V_8 -> V_30 , L_1 ,
V_27 , V_8 -> V_36 ) ;
F_16 ( & V_8 -> V_29 ) ;
return V_28 ;
V_33:
F_17 ( V_8 -> V_30 , L_2 , V_45 ) ;
F_16 ( & V_8 -> V_29 ) ;
return V_28 ;
}
int F_18 ( struct V_1 * V_8 )
{
T_1 V_46 ;
int V_28 ;
F_12 ( & V_8 -> V_29 ) ;
V_8 -> V_47 = 0 ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_32 , & V_46 ) ;
if ( V_28 < 0 )
goto V_48;
if ( ! ( V_46 & V_38 ) ) {
F_15 ( V_8 -> V_30 , L_3 , V_45 ) ;
V_8 -> V_49 = true ;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_35 ,
F_20 ( 10 ) ) ;
if ( V_28 )
goto V_48;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 ,
( V_37 | V_38 ) ) ;
if ( V_28 )
goto V_48;
} else {
V_8 -> V_49 = false ;
}
F_21 ( & V_8 -> V_50 ) ;
F_21 ( & V_8 -> V_51 ) ;
F_22 ( V_8 -> V_52 ) ;
return 0 ;
V_48:
F_16 ( & V_8 -> V_29 ) ;
return V_28 ;
}
int F_23 ( struct V_1 * V_8 )
{
return F_24 ( & V_8 -> V_50 ) ;
}
int F_25 ( struct V_1 * V_8 )
{
return F_24 ( & V_8 -> V_51 ) ;
}
int F_26 ( struct V_1 * V_8 , int * V_53 )
{
T_1 V_54 , V_55 ;
int V_56 ;
int V_28 ;
unsigned long V_57 ;
if ( ! F_24 ( & V_8 -> V_51 ) ) {
V_57 = F_27 (
& V_8 -> V_51 ,
V_58 ) ;
F_15 ( V_8 -> V_30 , L_4 ,
F_28 ( V_58 - V_57 ) ) ;
if ( ! V_57 ) {
V_28 = - V_59 ;
F_29 ( V_8 -> V_52 ) ;
V_8 -> V_47 = 0 ;
F_17 ( V_8 -> V_30 , L_5 ,
__LINE__ ) ;
goto V_48;
}
}
F_29 ( V_8 -> V_52 ) ;
V_8 -> V_47 = 0 ;
V_28 = F_14 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_43 , V_43 ) ;
F_30 ( 100 , 100 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_34 ,
V_60 , & V_54 ) ;
if ( V_28 < 0 )
goto V_48;
V_28 = F_19 ( V_8 -> V_30 , V_34 ,
V_61 , & V_55 ) ;
if ( V_28 < 0 )
goto V_48;
if ( V_55 & 0x10 )
V_56 = ( V_54 | ( V_55 << 8 ) | 0xFFFFE000 ) ;
else
V_56 = ( V_54 | ( V_55 << 8 ) ) ;
V_56 = ( V_56 * V_62 * 36 * 4 ) /
( 1000 * V_8 -> V_10 -> V_63 ) ;
if ( V_8 -> V_49 ) {
F_15 ( V_8 -> V_30 , L_6 , V_45 ) ;
V_28 = F_13 ( V_8 -> V_30 ,
V_34 , V_41 , 0 ) ;
if ( V_28 )
goto V_48;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_32 , 0 ) ;
if ( V_28 )
goto V_48;
}
F_16 ( & V_8 -> V_29 ) ;
( * V_53 ) = V_56 ;
return 0 ;
V_48:
F_16 ( & V_8 -> V_29 ) ;
return V_28 ;
}
int F_31 ( struct V_1 * V_8 )
{
int V_28 ;
unsigned long V_57 ;
int V_53 = 0 ;
V_28 = F_18 ( V_8 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_7 ) ;
return 0 ;
}
if ( ! F_24 ( & V_8 -> V_50 ) ) {
V_57 = F_27 (
& V_8 -> V_50 ,
V_58 ) ;
F_15 ( V_8 -> V_30 , L_8 ,
F_28 ( V_58 - V_57 ) ) ;
if ( ! V_57 ) {
V_28 = - V_59 ;
F_17 ( V_8 -> V_30 , L_5 ,
__LINE__ ) ;
goto V_48;
}
}
V_28 = F_26 ( V_8 , & V_53 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_9 ) ;
return 0 ;
}
F_15 ( V_8 -> V_30 , L_10 , V_45 , V_53 ) ;
return V_53 ;
V_48:
F_29 ( V_8 -> V_52 ) ;
F_16 ( & V_8 -> V_29 ) ;
return V_28 ;
}
static void F_32 ( struct V_64 * V_65 )
{
int V_56 ;
int V_28 ;
T_1 V_54 , V_66 , V_55 ;
struct V_1 * V_8 = F_33 ( V_65 ,
struct V_1 , V_67 ) ;
F_12 ( & V_8 -> V_29 ) ;
V_28 = F_13 ( V_8 -> V_30 , V_34 ,
V_44 , V_68 ) ;
if ( V_28 )
goto exit;
V_28 = F_19 ( V_8 -> V_30 , V_34 ,
V_69 , & V_54 ) ;
if ( V_28 < 0 )
goto exit;
V_28 = F_19 ( V_8 -> V_30 , V_34 ,
V_70 , & V_66 ) ;
if ( V_28 < 0 )
goto exit;
V_28 = F_19 ( V_8 -> V_30 , V_34 ,
V_71 , & V_55 ) ;
if ( V_28 < 0 )
goto exit;
if ( V_55 & 0x10 )
V_56 = ( V_54 | ( V_66 << 8 ) | ( V_55 << 16 ) | 0xFFE00000 ) ;
else
V_56 = ( V_54 | ( V_66 << 8 ) | ( V_55 << 16 ) ) ;
V_8 -> V_72 = ( V_56 * V_62 ) /
( 100 * V_8 -> V_10 -> V_63 ) ;
V_8 -> V_73 = ( V_56 * V_62 * 36 ) /
( 1000 * V_8 -> V_10 -> V_63 * ( V_8 -> V_36 / 4 ) ) ;
V_8 -> V_39 . V_74 = true ;
F_16 ( & V_8 -> V_29 ) ;
F_34 ( V_8 -> V_75 , & V_8 -> V_76 ) ;
F_15 ( V_8 -> V_30 , L_11 ,
V_8 -> V_10 -> V_63 , V_8 -> V_36 , V_56 , V_8 -> V_72 ) ;
return;
exit:
F_17 ( V_8 -> V_30 ,
L_12 ) ;
F_16 ( & V_8 -> V_29 ) ;
F_34 ( V_8 -> V_75 , & V_8 -> V_76 ) ;
}
static int F_35 ( struct V_1 * V_8 )
{
int V_77 ;
static int V_78 ;
V_77 = F_36 ( V_8 -> V_79 , V_80 ) ;
if ( V_77 < 0 ) {
F_17 ( V_8 -> V_30 ,
L_13 ,
V_45 ) ;
return V_78 ;
}
V_78 = V_77 ;
return V_77 ;
}
static int F_37 ( struct V_1 * V_8 , int V_5 )
{
int V_6 , V_81 ;
const struct V_82 * V_83 ;
int V_84 = 0 ;
V_83 = V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] . V_87 ,
V_81 = V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] . V_88 ;
for ( V_6 = 0 ; V_6 < V_81 ; ++ V_6 ) {
if ( V_5 > V_83 [ V_6 ] . V_5 )
break;
}
if ( ( V_6 > 0 ) && ( V_6 < V_81 ) ) {
V_84 = F_38 ( V_5 ,
V_83 [ V_6 ] . V_5 ,
V_83 [ V_6 ] . V_89 * 10 ,
V_83 [ V_6 - 1 ] . V_5 ,
V_83 [ V_6 - 1 ] . V_89 * 10 ) ;
} else if ( V_6 == 0 ) {
V_84 = 1000 ;
} else {
V_84 = 0 ;
}
F_15 ( V_8 -> V_30 , L_14 ,
V_45 , V_5 , V_84 ) ;
return V_84 ;
}
static int F_39 ( struct V_1 * V_8 )
{
V_8 -> V_77 = F_35 ( V_8 ) ;
return F_37 ( V_8 , V_8 -> V_77 ) ;
}
static int F_40 ( struct V_1 * V_8 )
{
int V_6 , V_81 ;
const struct V_90 * V_83 ;
int V_91 = 0 ;
V_83 = V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] . V_92 ;
V_81 = V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] . V_93 ;
for ( V_6 = 0 ; V_6 < V_81 ; ++ V_6 ) {
if ( V_8 -> V_94 / 10 > V_83 [ V_6 ] . V_95 )
break;
}
if ( ( V_6 > 0 ) && ( V_6 < V_81 ) ) {
V_91 = F_38 ( V_8 -> V_94 / 10 ,
V_83 [ V_6 ] . V_95 ,
V_83 [ V_6 ] . V_91 ,
V_83 [ V_6 - 1 ] . V_95 ,
V_83 [ V_6 - 1 ] . V_91 ) ;
} else if ( V_6 == 0 ) {
V_91 = V_83 [ 0 ] . V_91 ;
} else {
V_91 = V_83 [ V_81 - 1 ] . V_91 ;
}
F_15 ( V_8 -> V_30 , L_15
L_16 ,
V_45 , V_8 -> V_94 , V_91 , V_8 -> V_10 -> V_63 / 10 ,
( V_8 -> V_10 -> V_63 / 10 ) + V_91 ) ;
V_91 += V_8 -> V_10 -> V_63 / 10 ;
return V_91 ;
}
static int F_41 ( struct V_1 * V_8 )
{
int V_96 , V_53 ;
int V_6 = 0 ;
int V_77 = 0 ;
F_18 ( V_8 ) ;
do {
V_77 += F_35 ( V_8 ) ;
V_6 ++ ;
F_30 ( 5000 , 6000 ) ;
} while ( ! F_25 ( V_8 ) );
F_26 ( V_8 , & V_8 -> V_97 ) ;
V_8 -> V_77 = V_77 / V_6 ;
V_53 = F_40 ( V_8 ) ;
V_96 = V_8 -> V_77 - ( V_8 -> V_97 * V_53 ) / 1000 ;
F_15 ( V_8 -> V_30 , L_17
L_18 ,
V_45 , V_8 -> V_77 , V_96 , V_53 , V_8 -> V_97 , V_6 ) ;
return F_37 ( V_8 , V_96 ) ;
}
static int F_42 ( struct V_1 * V_8 , int V_98 )
{
return ( V_98 * 1000 ) / V_8 -> V_99 . V_100 ;
}
static int F_43 ( struct V_1 * V_8 , int V_101 )
{
return V_101 * V_8 -> V_99 . V_100 / 1000 ;
}
static int F_44 ( struct V_1 * V_8 , int V_98 )
{
T_2 V_102 ;
T_3 V_103 ;
V_102 = ( ( T_2 ) V_98 ) * ( ( T_2 ) V_8 -> V_104 ) ;
V_103 = F_45 ( V_102 , 1000 ) ;
if ( V_103 >= 1000 / 2 )
V_102 ++ ;
return ( int ) V_102 ;
}
static int F_46 ( struct V_1 * V_8 )
{
F_15 ( V_8 -> V_30 , L_19 ,
V_45 ,
V_8 -> V_99 . V_105 ,
V_8 -> V_72 ) ;
if ( V_8 -> V_99 . V_105 + V_8 -> V_72 > 0 )
V_8 -> V_99 . V_105 += V_8 -> V_72 ;
else
V_8 -> V_99 . V_105 = 0 ;
if ( V_8 -> V_99 . V_105 >= V_8 -> V_99 . V_100 ||
V_8 -> V_39 . V_106 ) {
V_8 -> V_99 . V_105 = V_8 -> V_99 . V_100 ;
}
F_10 ( V_8 , V_8 -> V_99 . V_105 ) ;
V_8 -> V_99 . V_107 =
F_42 ( V_8 , V_8 -> V_99 . V_105 ) ;
V_8 -> V_77 = F_35 ( V_8 ) ;
V_8 -> V_97 = F_31 ( V_8 ) ;
return V_8 -> V_99 . V_105 ;
}
static int F_47 ( struct V_1 * V_8 , bool V_108 )
{
int V_107 , V_105 ;
if ( V_108 )
V_107 = F_41 ( V_8 ) ;
else
V_107 = F_39 ( V_8 ) ;
V_105 = F_43 ( V_8 , V_107 ) ;
V_8 -> V_99 . V_105 = F_7 ( V_8 , V_105 ) ;
V_8 -> V_99 . V_107 =
F_42 ( V_8 , V_8 -> V_99 . V_105 ) ;
return V_8 -> V_99 . V_105 ;
}
static int F_48 ( struct V_1 * V_8 )
{
int V_109 , V_107 ;
F_15 ( V_8 -> V_30 , L_19 ,
V_45 ,
V_8 -> V_99 . V_105 ,
V_8 -> V_72 ) ;
if ( V_8 -> V_99 . V_105 + V_8 -> V_72 > 0 )
V_8 -> V_99 . V_105 += V_8 -> V_72 ;
else
V_8 -> V_99 . V_105 = 0 ;
if ( V_8 -> V_99 . V_105 >= V_8 -> V_99 . V_100 )
V_8 -> V_99 . V_105 = V_8 -> V_99 . V_100 ;
V_107 = F_42 ( V_8 , V_8 -> V_99 . V_105 ) ;
V_109 = F_39 ( V_8 ) ;
if ( V_107 < V_109 ) {
V_8 -> V_99 . V_107 = V_109 ;
V_8 -> V_99 . V_105 = F_43 ( V_8 ,
V_8 -> V_99 . V_107 ) ;
F_15 ( V_8 -> V_30 , L_20 ,
V_45 ,
V_107 ,
V_109 ) ;
F_10 ( V_8 , V_8 -> V_99 . V_105 ) ;
} else {
F_10 ( V_8 , V_8 -> V_99 . V_105 ) ;
V_8 -> V_99 . V_107 =
F_42 ( V_8 , V_8 -> V_99 . V_105 ) ;
}
return V_8 -> V_99 . V_105 ;
}
static int F_49 ( struct V_1 * V_8 )
{
int V_28 , V_110 ;
V_110 = F_50 ( V_8 -> V_99 . V_107 , 10 ) ;
if ( V_110 <= V_8 -> V_10 -> V_111 -> V_112 ||
V_8 -> V_39 . V_113 )
V_28 = V_114 ;
else if ( V_110 <= V_8 -> V_10 -> V_111 -> V_54 )
V_28 = V_115 ;
else if ( V_110 <= V_8 -> V_10 -> V_111 -> V_116 )
V_28 = V_117 ;
else if ( V_110 <= V_8 -> V_10 -> V_111 -> V_55 )
V_28 = V_118 ;
else
V_28 = V_119 ;
return V_28 ;
}
static int F_51 ( struct V_1 * V_8 )
{
struct V_120 * V_121 = & V_8 -> V_99 . V_122 ;
int V_89 = V_8 -> V_99 . V_123 ;
if ( ! V_121 -> V_27 )
return V_89 ;
if ( V_8 -> V_39 . V_124 ) {
V_121 -> V_125 [ 0 ] = 100 ;
V_121 -> V_125 [ 1 ] =
F_52 ( V_89 , V_8 -> V_10 -> V_11 -> V_126 ) ;
F_15 ( V_8 -> V_30 , L_21 ,
V_121 -> V_125 [ 0 ] , V_121 -> V_125 [ 1 ] ) ;
}
if ( ( V_121 -> V_125 [ 0 ] != V_121 -> V_125 [ 1 ] )
&& ( V_121 -> V_125 [ 1 ] > 0 ) )
V_89 = F_53 ( 100 ,
F_50 ( V_8 -> V_99 . V_123 *
V_121 -> V_125 [ 0 ] ,
V_121 -> V_125 [ 1 ] ) ) ;
if ( V_8 -> V_39 . V_127 ) {
if ( V_89 < V_121 -> V_128 ) {
V_121 -> V_128 = V_89 ;
F_15 ( V_8 -> V_30 , L_22 ,
V_121 -> V_128 ) ;
} else if ( ! V_8 -> V_39 . V_124 ) {
if ( V_8 -> V_99 . V_123 >=
V_121 -> V_128 ) {
F_15 ( V_8 -> V_30 , L_23 ) ;
V_121 -> V_27 = false ;
V_89 = V_8 -> V_99 . V_123 ;
} else {
F_15 ( V_8 -> V_30 ,
L_24 ,
V_121 -> V_128 ) ;
V_89 = V_121 -> V_128 ;
}
}
}
return V_89 ;
}
static void F_54 ( struct V_1 * V_8 )
{
struct V_120 * V_121 = & V_8 -> V_99 . V_122 ;
if ( ! V_121 -> V_27 )
return;
if ( V_8 -> V_39 . V_127 ) {
V_8 -> V_99 . V_122 . V_128 =
V_8 -> V_99 . V_122 . V_129 ;
F_15 ( V_8 -> V_30 , L_25 ,
V_8 -> V_99 . V_122 . V_128 ) ;
} else {
if ( V_121 -> V_129 != 100 ) {
V_121 -> V_125 [ 0 ] = V_121 -> V_129 ;
V_121 -> V_125 [ 1 ] = V_8 -> V_99 . V_123 ;
} else {
V_121 -> V_125 [ 0 ] = 100 ;
V_121 -> V_125 [ 1 ] =
F_52 ( V_8 -> V_99 . V_123 ,
V_8 -> V_10 -> V_11 -> V_126 ) ;
}
F_15 ( V_8 -> V_30 , L_26 ,
V_121 -> V_125 [ 0 ] , V_121 -> V_125 [ 1 ] ) ;
}
}
static void F_55 ( struct V_1 * V_8 , bool V_130 )
{
bool V_131 = false ;
int V_110 = F_50 ( V_8 -> V_99 . V_107 , 10 ) ;
V_8 -> V_99 . V_132 = F_49 ( V_8 ) ;
if ( V_8 -> V_99 . V_132 != V_8 -> V_99 . V_133 ) {
if ( ! ( ! V_8 -> V_39 . V_127 && V_8 -> V_99 . V_132 >
V_8 -> V_99 . V_133 ) || V_130 ) {
F_15 ( V_8 -> V_30 , L_27 ,
V_8 -> V_99 . V_133 ,
V_8 -> V_99 . V_132 ) ;
V_8 -> V_99 . V_133 = V_8 -> V_99 . V_132 ;
V_131 = true ;
} else {
F_15 ( V_8 -> V_30 , L_28
L_29 ,
V_8 -> V_99 . V_133 ,
V_8 -> V_99 . V_132 ) ;
}
}
if ( V_8 -> V_39 . V_113 ) {
F_15 ( V_8 -> V_30 , L_30 ) ;
V_8 -> V_99 . V_123 = 0 ;
V_8 -> V_99 . V_107 = 0 ;
V_110 = 0 ;
V_8 -> V_99 . V_134 = 0 ;
V_8 -> V_99 . V_105 = 0 ;
V_131 = true ;
} else if ( V_8 -> V_39 . V_124 ) {
if ( V_8 -> V_39 . V_106 ) {
V_8 -> V_99 . V_123 = V_110 ;
V_8 -> V_99 . V_134 = V_8 -> V_99 . V_105 ;
V_131 = true ;
if ( ! V_8 -> V_99 . V_122 . V_27 &&
V_8 -> V_10 -> V_135 ) {
V_8 -> V_99 . V_122 . V_27 = true ;
V_8 -> V_99 . V_122 . V_125 [ 0 ] = 100 ;
V_8 -> V_99 . V_122 . V_125 [ 1 ] =
V_8 -> V_99 . V_123 ;
V_8 -> V_99 . V_122 . V_128 = 100 ;
}
} else if ( V_8 -> V_99 . V_123 != V_110 ) {
F_15 ( V_8 -> V_30 ,
L_31
L_32 ,
V_110 ) ;
V_8 -> V_99 . V_123 = V_110 ;
V_8 -> V_99 . V_134 = V_8 -> V_99 . V_105 ;
V_131 = true ;
}
} else if ( V_8 -> V_99 . V_123 != V_110 ) {
if ( V_110 == 0 ) {
V_8 -> V_99 . V_123 = 1 ;
V_110 = 1 ;
V_131 = true ;
} else if ( ! ( ! V_8 -> V_39 . V_127 &&
V_110 > V_8 -> V_99 . V_123 ) || V_130 ) {
F_15 ( V_8 -> V_30 ,
L_33 ,
V_8 -> V_99 . V_123 ,
V_110 ,
V_8 -> V_99 . V_107 ) ;
V_8 -> V_99 . V_123 = V_110 ;
V_8 -> V_99 . V_134 = V_8 -> V_99 . V_105 ;
V_131 = true ;
} else {
F_15 ( V_8 -> V_30 , L_34
L_35 ,
V_8 -> V_99 . V_123 ,
V_110 ,
V_8 -> V_99 . V_107 ) ;
}
}
if ( V_131 ) {
if ( V_8 -> V_10 -> V_135 ) {
V_8 -> V_99 . V_122 . V_129 =
F_51 ( V_8 ) ;
F_56 ( V_8 -> V_30 , L_36 ,
V_8 -> V_99 . V_123 ,
V_8 -> V_99 . V_122 . V_129 ) ;
}
F_57 ( V_8 -> V_136 ) ;
if ( V_8 -> V_39 . V_124 && V_8 -> V_39 . V_106 ) {
F_15 ( V_8 -> V_30 , L_37 ) ;
V_8 -> V_39 . V_106 = false ;
F_58 ( & V_8 -> V_137 , NULL , L_38 ) ;
}
F_58 ( & V_8 -> V_137 , NULL , L_39 ) ;
}
}
static void F_59 ( struct V_1 * V_8 ,
enum V_138 V_139 )
{
F_15 ( V_8 -> V_30 , L_40 ,
V_8 -> V_140 ,
V_140 [ V_8 -> V_140 ] ,
V_139 ,
V_140 [ V_139 ] ) ;
V_8 -> V_140 = V_139 ;
}
static void F_60 ( struct V_1 * V_8 ,
enum V_141 V_139 )
{
F_15 ( V_8 -> V_30 , L_41 ,
V_8 -> V_142 ,
V_142 [ V_8 -> V_142 ] ,
V_139 ,
V_142 [ V_139 ] ) ;
V_8 -> V_142 = V_139 ;
}
static void F_61 ( struct V_1 * V_8 )
{
if ( V_8 -> V_142 != V_143 )
F_60 ( V_8 ,
V_143 ) ;
switch ( V_8 -> V_140 ) {
case V_144 :
V_8 -> V_36 = F_20 (
V_8 -> V_10 -> V_11 -> V_145 ) ;
F_11 ( V_8 , true ) ;
F_59 ( V_8 , V_146 ) ;
break;
case V_146 :
F_12 ( & V_8 -> V_29 ) ;
if ( ! V_8 -> V_39 . V_74 && ! V_8 -> V_39 . V_106 ) {
F_16 ( & V_8 -> V_29 ) ;
F_15 ( V_8 -> V_30 , L_42 ,
V_45 ) ;
break;
}
V_8 -> V_39 . V_74 = false ;
F_16 ( & V_8 -> V_29 ) ;
F_46 ( V_8 ) ;
break;
default:
break;
}
F_55 ( V_8 , false ) ;
}
static void F_62 ( struct V_1 * V_8 )
{
int V_84 ;
F_9 ( V_8 ) ;
V_84 = V_8 -> V_99 . V_147 ;
if ( V_84 > V_8 -> V_99 . V_100 ) {
F_15 ( V_8 -> V_30 , L_43
L_44 , V_84 , V_8 -> V_99 . V_100 ) ;
V_84 = V_8 -> V_99 . V_100 ;
}
F_10 ( V_8 , V_8 -> V_99 . V_147 ) ;
V_8 -> V_99 . V_107 = F_42 ( V_8 , V_84 ) ;
V_8 -> V_99 . V_105 = V_84 ;
F_55 ( V_8 , true ) ;
}
static bool F_63 ( struct V_1 * V_8 )
{
int V_84 , V_148 , V_149 ;
int V_150 ;
V_84 = V_8 -> V_99 . V_147 ;
V_150 = F_42 ( V_8 ,
V_8 -> V_99 . V_147 ) ;
V_148 = V_8 -> V_99 . V_107 - V_8 -> V_10 -> V_11 -> V_151 * 10 ;
V_149 = V_8 -> V_99 . V_107 + V_8 -> V_10 -> V_11 -> V_151 * 10 ;
if ( V_148 < 0 )
V_148 = 0 ;
if ( V_149 > 1000 )
V_149 = 1000 ;
F_15 ( V_8 -> V_30 , L_45
L_46 ,
V_148 , V_150 , V_149 , V_84 , V_8 -> V_99 . V_105 ) ;
if ( V_150 > V_148 && V_150 < V_149 ) {
F_15 ( V_8 -> V_30 , L_47 , V_84 ) ;
F_62 ( V_8 ) ;
return true ;
}
F_15 ( V_8 -> V_30 , L_48 ) ;
return false ;
}
static void F_64 ( struct V_1 * V_8 )
{
int V_152 ;
if ( V_8 -> V_140 != V_144 )
F_59 ( V_8 , V_144 ) ;
switch ( V_8 -> V_142 ) {
case V_153 :
V_8 -> V_154 = 0 ;
V_8 -> V_36 = F_20 ( V_8 -> V_10 -> V_11 -> V_155 ) ;
F_11 ( V_8 , true ) ;
F_60 ( V_8 ,
V_156 ) ;
case V_156 :
V_152 = V_8 -> V_10 -> V_11 -> V_155 ;
if ( V_8 -> V_154 > V_8 -> V_10 -> V_11 -> V_157 ) {
F_47 ( V_8 , true ) ;
F_55 ( V_8 , true ) ;
}
V_8 -> V_154 += V_152 ;
if ( V_8 -> V_154 > V_8 -> V_10 -> V_11 -> V_158 )
F_60 ( V_8 ,
V_159 ) ;
break;
case V_143 :
V_8 -> V_160 = 0 ;
V_8 -> V_161 = true ;
F_60 ( V_8 ,
V_162 ) ;
case V_162 :
V_152 = V_8 -> V_10 -> V_11 -> V_163 ;
V_8 -> V_97 = F_31 ( V_8 ) ;
if ( F_6 ( V_8 , V_8 -> V_97 ) ) {
if ( V_8 -> V_160 >
V_8 -> V_10 -> V_11 -> V_164 ) {
V_8 -> V_36 = F_20 (
V_8 -> V_10 -> V_11 -> V_165 ) ;
F_11 ( V_8 , true ) ;
F_60 ( V_8 ,
V_166 ) ;
V_8 -> V_161 = false ;
} else {
F_65 ( V_8 -> V_75 ,
& V_8 -> V_167 ,
V_152 * V_168 ) ;
}
V_8 -> V_160 += V_152 ;
} else {
V_8 -> V_36 = F_20 (
V_8 -> V_10 -> V_11 -> V_165 ) ;
F_11 ( V_8 , true ) ;
F_60 ( V_8 ,
V_166 ) ;
}
break;
case V_159 :
V_8 -> V_36 = F_20 (
V_8 -> V_10 -> V_11 -> V_165 ) ;
F_11 ( V_8 , true ) ;
F_60 ( V_8 ,
V_166 ) ;
break;
case V_166 :
V_8 -> V_97 = F_31 ( V_8 ) ;
if ( F_6 ( V_8 , V_8 -> V_97 ) ) {
if ( V_8 -> V_169 ) {
V_8 -> V_169 = false ;
V_8 -> V_170 = 0 ;
}
if ( V_8 -> V_161 ) {
F_60 ( V_8 ,
V_143 ) ;
F_65 ( V_8 -> V_75 ,
& V_8 -> V_167 , 0 ) ;
break;
}
F_47 ( V_8 , true ) ;
} else {
F_12 ( & V_8 -> V_29 ) ;
if ( ! V_8 -> V_39 . V_74 ) {
F_16 ( & V_8 -> V_29 ) ;
F_15 ( V_8 -> V_30 , L_42 ,
V_45 ) ;
break;
}
V_8 -> V_39 . V_74 = false ;
F_16 ( & V_8 -> V_29 ) ;
if ( ! V_8 -> V_169 ) {
V_8 -> V_169 = true ;
V_8 -> V_170 = 0 ;
}
V_8 -> V_170 +=
V_8 -> V_10 -> V_11 -> V_165 ;
if ( V_8 -> V_170 >
V_8 -> V_10 -> V_11 -> V_171 )
V_8 -> V_161 = true ;
F_48 ( V_8 ) ;
}
F_55 ( V_8 , false ) ;
break;
case V_172 :
F_47 ( V_8 , true ) ;
V_8 -> V_36 = F_20 (
V_8 -> V_10 -> V_11 -> V_165 ) ;
F_11 ( V_8 , true ) ;
F_60 ( V_8 ,
V_166 ) ;
F_55 ( V_8 , false ) ;
break;
default:
break;
}
}
static void F_66 ( struct V_1 * V_8 )
{
int V_28 ;
switch ( V_8 -> V_173 ) {
case V_174 :
F_15 ( V_8 -> V_30 , L_49 ) ;
V_28 = F_14 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_175 , V_176 ) ;
if ( V_28 < 0 )
goto V_177;
V_28 = F_14 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_178 , V_178 ) ;
if ( V_28 < 0 )
goto V_177;
V_8 -> V_173 = V_179 ;
break;
case V_180 :
V_28 = F_14 ( V_8 -> V_30 ,
V_34 , V_41 ,
V_181 , V_181 ) ;
if ( V_28 < 0 )
goto V_177;
V_8 -> V_39 . V_182 = false ;
F_15 ( V_8 -> V_30 , L_50 ) ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
break;
case V_179 :
F_15 ( V_8 -> V_30 , L_51 ) ;
default:
break;
}
return;
V_177:
F_17 ( V_8 -> V_30 , L_52 ) ;
V_8 -> V_39 . V_182 = false ;
V_8 -> V_173 = V_174 ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
}
static void F_67 ( struct V_1 * V_8 )
{
if ( V_8 -> V_39 . V_182 )
F_66 ( V_8 ) ;
else {
if ( V_8 -> V_39 . V_127 )
F_61 ( V_8 ) ;
else
F_64 ( V_8 ) ;
}
F_15 ( V_8 -> V_30 , L_53
L_54 ,
V_8 -> V_99 . V_100 ,
V_8 -> V_99 . V_183 ,
V_8 -> V_99 . V_105 ,
V_8 -> V_99 . V_107 ,
V_8 -> V_99 . V_132 ,
V_8 -> V_99 . V_134 ,
V_8 -> V_99 . V_123 ,
V_8 -> V_99 . V_133 ,
V_8 -> V_77 ,
V_8 -> V_97 ,
V_8 -> V_73 ,
V_8 -> V_72 ,
V_8 -> V_39 . V_127 ,
V_8 -> V_140 ,
V_8 -> V_142 ,
V_8 -> V_169 ,
V_8 -> V_161 ) ;
}
static void F_68 ( struct V_64 * V_65 )
{
struct V_1 * V_8 = F_33 ( V_65 , struct V_1 ,
V_167 . V_65 ) ;
if ( V_8 -> V_184 ) {
F_47 ( V_8 , true ) ;
F_55 ( V_8 , true ) ;
V_8 -> V_184 = false ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
} else if ( V_8 -> V_39 . V_185 ) {
if ( F_63 ( V_8 ) ) {
F_55 ( V_8 , true ) ;
if ( V_8 -> V_39 . V_127 )
F_59 ( V_8 ,
V_144 ) ;
else
F_60 ( V_8 ,
V_159 ) ;
}
V_8 -> V_39 . V_185 = false ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
} else
F_67 ( V_8 ) ;
}
static void F_69 ( struct V_64 * V_65 )
{
int V_28 ;
T_1 V_186 ;
struct V_1 * V_8 = F_33 ( V_65 , struct V_1 ,
V_187 . V_65 ) ;
V_28 = F_19 ( V_8 -> V_30 ,
V_188 , V_189 ,
& V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_8 -> V_30 , L_55 , V_45 ) ;
return;
}
if ( ( V_186 & V_190 ) == V_190 ) {
if ( ! V_8 -> V_39 . V_191 ) {
F_15 ( V_8 -> V_30 , L_56 ) ;
V_8 -> V_39 . V_191 = true ;
F_57 ( V_8 -> V_136 ) ;
}
F_65 ( V_8 -> V_75 , & V_8 -> V_187 ,
V_168 ) ;
} else {
F_15 ( V_8 -> V_30 , L_57 ) ;
V_8 -> V_39 . V_191 = false ;
F_57 ( V_8 -> V_136 ) ;
}
}
static void F_70 ( struct V_64 * V_65 )
{
int V_77 ;
struct V_1 * V_8 = F_33 ( V_65 , struct V_1 ,
V_192 . V_65 ) ;
V_77 = F_35 ( V_8 ) ;
if ( V_77 < V_8 -> V_10 -> V_11 -> V_193 ) {
if ( V_8 -> V_194 < 1 ) {
V_8 -> V_39 . V_113 = true ;
F_71 ( V_8 -> V_30 , L_58 ) ;
} else {
V_8 -> V_194 -- ;
F_71 ( V_8 -> V_30 , L_59 ) ;
F_65 ( V_8 -> V_75 , & V_8 -> V_192 ,
F_72 ( V_195 ) ) ;
}
} else {
V_8 -> V_39 . V_196 = false ;
V_8 -> V_194 = 10 ;
F_71 ( V_8 -> V_30 , L_60 ) ;
}
F_55 ( V_8 , false ) ;
}
static int F_73 ( struct V_1 * V_8 , int V_197 )
{
if ( V_197 > V_198 +
( V_199 * V_200 ) )
return V_200 ;
if ( V_197 < V_198 )
return 0 ;
return ( V_197 - V_198 ) / V_199 ;
}
static int F_74 ( struct V_1 * V_8 )
{
int V_201 ;
int V_202 ;
int V_203 ;
int V_204 ;
int V_205 ;
int V_28 ;
int V_206 ;
V_202 = V_8 -> V_10 -> V_11 -> V_207 ;
V_203 = V_8 -> V_10 -> V_11 -> V_208 ;
V_204 = F_73 ( V_8 , V_202 ) ;
V_205 = F_73 ( V_8 , V_203 ) ;
V_201 = V_198 + V_204 * V_199 ;
if ( V_201 != V_202 )
F_71 ( V_8 -> V_30 , L_61 ,
V_202 , V_201 , V_204 ) ;
V_201 = V_198 + V_205 * V_199 ;
if ( V_201 != V_203 )
F_71 ( V_8 -> V_30 , L_61 ,
V_203 , V_201 , V_205 ) ;
V_206 = V_204 | ( V_205 << 4 ) ;
F_15 ( V_8 -> V_30 , L_62 , V_206 , V_204 , V_205 ) ;
V_28 = F_13 ( V_8 -> V_30 , V_209 ,
V_210 , V_206 ) ;
return V_28 ;
}
static void F_75 ( struct V_64 * V_65 )
{
struct V_1 * V_8 = F_33 ( V_65 , struct V_1 , V_76 ) ;
F_67 ( V_8 ) ;
}
static T_4 F_76 ( int V_52 , void * V_211 )
{
struct V_1 * V_8 = V_211 ;
if ( ! V_8 -> V_47 ) {
V_8 -> V_47 ++ ;
F_77 ( & V_8 -> V_50 ) ;
} else {
V_8 -> V_47 = 0 ;
F_77 ( & V_8 -> V_51 ) ;
}
return V_212 ;
}
static T_4 F_78 ( int V_52 , void * V_211 )
{
struct V_1 * V_8 = V_211 ;
V_8 -> V_173 = V_180 ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
return V_212 ;
}
static T_4 F_79 ( int V_52 , void * V_211 )
{
struct V_1 * V_8 = V_211 ;
F_34 ( V_8 -> V_75 , & V_8 -> V_67 ) ;
return V_212 ;
}
static T_4 F_80 ( int V_52 , void * V_211 )
{
struct V_1 * V_8 = V_211 ;
F_15 ( V_8 -> V_30 , L_56 ) ;
F_65 ( V_8 -> V_75 , & V_8 -> V_187 , 0 ) ;
return V_212 ;
}
static T_4 F_81 ( int V_52 , void * V_211 )
{
struct V_1 * V_8 = V_211 ;
if ( ! V_8 -> V_39 . V_196 ) {
F_71 ( V_8 -> V_30 , L_63 ) ;
V_8 -> V_39 . V_196 = true ;
F_65 ( V_8 -> V_75 , & V_8 -> V_192 ,
F_72 ( V_195 ) ) ;
}
return V_212 ;
}
static int F_82 ( struct V_213 * V_214 ,
enum V_215 V_216 ,
union V_217 * V_56 )
{
struct V_1 * V_8 = F_83 ( V_214 ) ;
switch ( V_216 ) {
case V_218 :
if ( V_8 -> V_39 . V_191 )
V_56 -> V_219 = V_220 * 1000 ;
else
V_56 -> V_219 = V_8 -> V_77 * 1000 ;
break;
case V_221 :
V_56 -> V_219 = V_8 -> V_97 * 1000 ;
break;
case V_222 :
V_56 -> V_219 = V_8 -> V_73 * 1000 ;
break;
case V_223 :
V_56 -> V_219 = F_44 ( V_8 ,
V_8 -> V_99 . V_100 ) ;
break;
case V_224 :
V_56 -> V_219 = F_44 ( V_8 ,
V_8 -> V_99 . V_183 ) ;
break;
case V_225 :
if ( V_8 -> V_39 . V_226 && ! V_8 -> V_10 -> V_227 &&
V_8 -> V_39 . V_228 )
V_56 -> V_219 = F_44 ( V_8 ,
V_8 -> V_99 . V_183 ) ;
else
V_56 -> V_219 = F_44 ( V_8 ,
V_8 -> V_99 . V_134 ) ;
break;
case V_229 :
V_56 -> V_219 = V_8 -> V_99 . V_100 ;
break;
case V_230 :
V_56 -> V_219 = V_8 -> V_99 . V_183 ;
break;
case V_231 :
if ( V_8 -> V_39 . V_226 && ! V_8 -> V_10 -> V_227 &&
V_8 -> V_39 . V_228 )
V_56 -> V_219 = V_8 -> V_99 . V_183 ;
else
V_56 -> V_219 = V_8 -> V_99 . V_134 ;
break;
case V_232 :
if ( V_8 -> V_39 . V_226 && ! V_8 -> V_10 -> V_227 &&
V_8 -> V_39 . V_228 )
V_56 -> V_219 = 100 ;
else
V_56 -> V_219 = V_8 -> V_99 . V_123 ;
break;
case V_233 :
if ( V_8 -> V_39 . V_226 && ! V_8 -> V_10 -> V_227 &&
V_8 -> V_39 . V_228 )
V_56 -> V_219 = V_234 ;
else
V_56 -> V_219 = V_8 -> V_99 . V_133 ;
break;
default:
return - V_235 ;
}
return 0 ;
}
static int F_84 ( struct V_236 * V_30 , void * V_237 )
{
struct V_213 * V_214 ;
struct V_213 * V_238 = F_85 ( V_30 ) ;
const char * * V_239 = ( const char * * ) V_238 -> V_240 ;
struct V_1 * V_8 ;
union V_217 V_28 ;
int V_241 ;
V_214 = (struct V_213 * ) V_237 ;
V_8 = F_83 ( V_214 ) ;
V_241 = F_86 ( V_239 , V_238 -> V_242 , V_214 -> V_243 -> V_244 ) ;
if ( V_241 < 0 )
return 0 ;
for ( V_241 = 0 ; V_241 < V_238 -> V_243 -> V_245 ; V_241 ++ ) {
enum V_215 V_246 ;
V_246 = V_238 -> V_243 -> V_247 [ V_241 ] ;
if ( F_87 ( V_238 , V_246 , & V_28 ) )
continue;
switch ( V_246 ) {
case V_248 :
switch ( V_238 -> V_243 -> type ) {
case V_249 :
switch ( V_28 . V_219 ) {
case V_250 :
case V_251 :
case V_252 :
if ( ! V_8 -> V_39 . V_127 )
break;
V_8 -> V_39 . V_127 = false ;
V_8 -> V_39 . V_124 = false ;
if ( V_8 -> V_10 -> V_135 )
F_54 ( V_8 ) ;
F_34 ( V_8 -> V_75 , & V_8 -> V_76 ) ;
break;
case V_253 :
if ( V_8 -> V_39 . V_124 )
break;
V_8 -> V_39 . V_124 = true ;
V_8 -> V_39 . V_106 = true ;
V_8 -> V_99 . V_183 = V_8 -> V_99 . V_105 ;
F_34 ( V_8 -> V_75 , & V_8 -> V_76 ) ;
break;
case V_254 :
if ( V_8 -> V_39 . V_127 &&
! V_8 -> V_39 . V_124 )
break;
V_8 -> V_39 . V_127 = true ;
V_8 -> V_39 . V_124 = false ;
if ( V_8 -> V_10 -> V_135 )
F_54 ( V_8 ) ;
F_34 ( V_8 -> V_75 , & V_8 -> V_76 ) ;
break;
} ;
default:
break;
} ;
break;
case V_255 :
switch ( V_238 -> V_243 -> type ) {
case V_249 :
if ( ! V_8 -> V_39 . V_228 &&
V_8 -> V_10 -> V_86 != V_256 ) {
const struct V_257 * V_258 ;
V_258 = & ( V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] ) ;
V_8 -> V_39 . V_228 = true ;
V_8 -> V_99 . V_100 =
V_259 *
V_258 -> V_260 ;
V_8 -> V_99 . V_183 =
V_8 -> V_99 . V_100 ;
V_8 -> V_104 = V_258 -> V_261 ;
}
if ( V_28 . V_219 )
V_8 -> V_39 . V_226 = false ;
else
V_8 -> V_39 . V_226 = true ;
break;
default:
break;
}
break;
case V_262 :
switch ( V_238 -> V_243 -> type ) {
case V_249 :
if ( V_8 -> V_39 . V_228 )
V_8 -> V_94 = V_28 . V_219 ;
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
static int F_88 ( struct V_1 * V_8 )
{
int V_28 ;
V_28 = F_14 ( V_8 -> V_30 ,
V_188 ,
V_263 ,
V_264 ,
V_264 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_64 ) ;
goto V_265;
}
V_28 = F_14 ( V_8 -> V_30 ,
V_188 ,
V_263 ,
V_266 ,
V_266 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_65 ) ;
goto V_265;
}
V_28 = F_13 ( V_8 -> V_30 ,
V_209 ,
V_267 ,
F_4 (
V_8 -> V_10 -> V_11 -> V_193 ) << 1 |
V_268 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_66 , V_45 ) ;
goto V_265;
}
V_28 = F_74 ( V_8 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_67 ) ;
goto V_265;
}
if ( ( ( F_89 ( V_8 -> V_269 ) || F_90 ( V_8 -> V_269 ) ) &&
F_91 ( V_8 -> V_30 ) >= V_270 )
|| F_92 ( V_8 -> V_269 ) ) {
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_271 , V_8 -> V_10 -> V_11 -> V_272 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_68 , V_45 ) ;
goto V_265;
} ;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_273 , V_8 -> V_10 -> V_11 -> V_274 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_69 , V_45 ) ;
goto V_265;
} ;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_275 , V_8 -> V_10 -> V_11 -> V_276 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_70 , V_45 ) ;
goto V_265;
} ;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_277 , V_8 -> V_10 -> V_11 -> V_278 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_71 , V_45 ) ;
goto V_265;
} ;
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_279 , V_8 -> V_10 -> V_11 -> V_280 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_72 , V_45 ) ;
goto V_265;
} ;
}
V_265:
return V_28 ;
}
static void F_93 ( struct V_213 * V_214 )
{
struct V_1 * V_8 = F_83 ( V_214 ) ;
F_94 ( V_281 , NULL ,
V_8 -> V_136 , F_84 ) ;
}
static void F_95 ( struct V_64 * V_65 )
{
struct V_1 * V_8 = F_33 ( V_65 , struct V_1 ,
V_282 . V_65 ) ;
if ( V_8 -> V_39 . V_182 == false ) {
F_15 ( V_8 -> V_30 , L_73 ) ;
F_9 ( V_8 ) ;
F_47 ( V_8 , true ) ;
F_59 ( V_8 , V_144 ) ;
F_60 ( V_8 , V_153 ) ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
} else {
F_17 ( V_8 -> V_30 , L_74
L_75 ) ;
F_65 ( V_8 -> V_75 , & V_8 -> V_282 ,
F_72 ( 1 ) ) ;
}
}
static T_5 F_96 ( struct V_1 * V_8 , char * V_283 )
{
return sprintf ( V_283 , L_76 , V_8 -> V_99 . V_183 ) ;
}
static T_5 F_97 ( struct V_1 * V_8 , const char * V_283 ,
T_6 V_284 )
{
unsigned long V_285 ;
T_5 V_28 ;
V_28 = F_98 ( V_283 , 10 , & V_285 ) ;
F_15 ( V_8 -> V_30 , L_77 , V_28 , V_285 ) ;
if ( ! V_28 ) {
V_8 -> V_99 . V_183 = ( int ) V_285 ;
V_28 = V_284 ;
}
return V_28 ;
}
static T_5 F_99 ( struct V_1 * V_8 , char * V_283 )
{
return sprintf ( V_283 , L_76 , V_8 -> V_99 . V_134 ) ;
}
static T_5 F_100 ( struct V_1 * V_8 , const char * V_283 ,
T_6 V_284 )
{
unsigned long V_286 ;
T_5 V_28 ;
V_28 = F_98 ( V_283 , 10 , & V_286 ) ;
F_15 ( V_8 -> V_30 , L_78 ,
V_28 , V_286 , V_8 -> V_99 . V_134 ) ;
if ( ! V_28 ) {
V_8 -> V_99 . V_147 = ( int ) V_286 ;
V_8 -> V_39 . V_185 = true ;
V_28 = V_284 ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
}
return V_28 ;
}
static T_5
F_101 ( struct V_287 * V_288 , struct V_289 * V_290 , char * V_283 )
{
struct V_291 * V_292 ;
struct V_1 * V_8 ;
V_292 = F_33 ( V_290 , struct V_291 , V_290 ) ;
V_8 = F_33 ( V_288 , struct V_1 , V_137 ) ;
if ( ! V_292 -> V_293 )
return - V_294 ;
return V_292 -> V_293 ( V_8 , V_283 ) ;
}
static T_5
F_102 ( struct V_287 * V_288 , struct V_289 * V_290 , const char * V_283 ,
T_6 V_284 )
{
struct V_291 * V_292 ;
struct V_1 * V_8 ;
V_292 = F_33 ( V_290 , struct V_291 , V_290 ) ;
V_8 = F_33 ( V_288 , struct V_1 , V_137 ) ;
if ( ! V_292 -> V_295 )
return - V_294 ;
return V_292 -> V_295 ( V_8 , V_283 , V_284 ) ;
}
static void F_103 ( struct V_1 * V_8 )
{
F_104 ( & V_8 -> V_137 ) ;
}
static int F_105 ( struct V_1 * V_8 )
{
int V_28 = 0 ;
V_28 = F_106 ( & V_8 -> V_137 ,
& V_296 ,
NULL , L_79 ) ;
if ( V_28 < 0 )
F_17 ( V_8 -> V_30 , L_80 ) ;
return V_28 ;
}
static T_5 F_107 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_273 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_81 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0x7F ) ) ;
V_48:
return V_28 ;
}
static T_5 F_109 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
const char * V_283 , T_6 V_284 )
{
int V_28 ;
long unsigned V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_186 = F_110 ( V_283 , NULL , 10 ) ;
if ( V_186 > 0x7F ) {
F_17 ( V_30 , L_82 ) ;
goto V_48;
}
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_273 , ( T_1 ) V_186 ) ;
if ( V_28 < 0 )
F_17 ( V_30 , L_83 ) ;
V_48:
return V_284 ;
}
static T_5 F_111 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_271 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_84 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0x7F ) ) ;
V_48:
return V_28 ;
}
static T_5 F_112 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
const char * V_283 , T_6 V_284 )
{
int V_28 ;
int V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_186 = F_110 ( V_283 , NULL , 10 ) ;
if ( V_186 > 0x7F ) {
F_17 ( V_30 , L_85 ) ;
goto V_48;
}
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_271 , ( T_1 ) V_186 ) ;
if ( V_28 < 0 )
F_17 ( V_30 , L_86 ) ;
V_48:
return V_284 ;
}
static T_5 F_113 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_275 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_87 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0xF ) ) ;
V_48:
return V_28 ;
}
static T_5 F_114 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
const char * V_283 , T_6 V_284 )
{
int V_28 ;
int V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_186 = F_110 ( V_283 , NULL , 10 ) ;
if ( V_186 > 0xF ) {
F_17 ( V_30 , L_88 ) ;
goto V_48;
}
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_275 , ( T_1 ) V_186 ) ;
if ( V_28 < 0 )
F_17 ( V_30 , L_89 ) ;
V_48:
return V_284 ;
}
static T_5 F_115 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_299 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_90 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0x7F ) ) ;
V_48:
return V_28 ;
}
static T_5 F_116 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_275 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_87 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0xF0 ) >> 4 ) ;
V_48:
return V_28 ;
}
static T_5 F_117 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_279 , & V_186 ) ;
if ( V_28 < 0 )
goto V_48;
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0x1 ) ) ;
V_48:
return V_28 ;
}
static T_5 F_118 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
const char * V_283 , T_6 V_284 )
{
int V_28 ;
int V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_186 = F_110 ( V_283 , NULL , 10 ) ;
if ( V_186 > 0x1 ) {
F_17 ( V_30 , L_91 ) ;
goto V_48;
}
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_279 , ( T_1 ) V_186 ) ;
if ( V_28 < 0 )
F_17 ( V_30 , L_92 ) ;
V_48:
return V_284 ;
}
static T_5 F_119 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_279 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_93 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( ( V_186 & 0x10 ) >> 4 ) ) ;
V_48:
return V_28 ;
}
static T_5 F_120 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_277 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_94 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( V_186 & 0x7 ) ) ;
V_48:
return V_28 ;
}
static T_5 F_121 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
const char * V_283 , T_6 V_284 )
{
int V_28 ;
int V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_186 = F_110 ( V_283 , NULL , 10 ) ;
if ( V_186 > 0x7 ) {
F_17 ( V_30 , L_95 ) ;
goto V_48;
}
V_28 = F_13 ( V_8 -> V_30 , V_31 ,
V_277 , ( T_1 ) V_186 ) ;
if ( V_28 < 0 )
F_17 ( V_30 , L_96 ) ;
V_48:
return V_284 ;
}
static T_5 F_122 ( struct V_236 * V_30 ,
struct V_297 * V_290 ,
char * V_283 )
{
int V_28 ;
T_1 V_186 ;
struct V_213 * V_214 = F_85 ( V_30 ) ;
struct V_1 * V_8 = F_83 ( V_214 ) ;
V_28 = F_19 ( V_8 -> V_30 , V_31 ,
V_279 , & V_186 ) ;
if ( V_28 < 0 ) {
F_17 ( V_30 , L_93 ) ;
goto V_48;
}
return F_108 ( V_283 , V_298 , L_76 , ( ( V_186 & 0x20 ) >> 5 ) ) ;
V_48:
return V_28 ;
}
static int F_123 ( struct V_1 * V_8 )
{
unsigned int V_6 ;
if ( ( ( F_89 ( V_8 -> V_269 ) || F_90 ( V_8 -> V_269 ) ) &&
F_91 ( V_8 -> V_30 ) >= V_270 )
|| F_92 ( V_8 -> V_269 ) ) {
for ( V_6 = 0 ; V_6 < F_5 ( V_300 ) ; V_6 ++ )
if ( F_124 ( & V_8 -> V_136 -> V_30 ,
& V_300 [ V_6 ] ) )
goto V_301;
}
return 0 ;
V_301:
F_17 ( & V_8 -> V_136 -> V_30 , L_97 ) ;
while ( V_6 -- )
F_125 ( & V_8 -> V_136 -> V_30 ,
& V_300 [ V_6 ] ) ;
return - V_294 ;
}
static void F_126 ( struct V_1 * V_8 )
{
unsigned int V_6 ;
if ( ( ( F_89 ( V_8 -> V_269 ) || F_90 ( V_8 -> V_269 ) ) &&
F_91 ( V_8 -> V_30 ) >= V_270 )
|| F_92 ( V_8 -> V_269 ) ) {
for ( V_6 = 0 ; V_6 < F_5 ( V_300 ) ; V_6 ++ )
( void ) F_125 ( & V_8 -> V_136 -> V_30 ,
& V_300 [ V_6 ] ) ;
}
}
static int F_127 ( struct V_302 * V_303 )
{
struct V_1 * V_8 = F_128 ( V_303 ) ;
if ( ! V_8 -> V_39 . V_127 ) {
F_60 ( V_8 , V_172 ) ;
F_34 ( V_8 -> V_75 , & V_8 -> V_76 ) ;
}
return 0 ;
}
static int F_129 ( struct V_302 * V_303 ,
T_7 V_304 )
{
struct V_1 * V_8 = F_128 ( V_303 ) ;
F_130 ( & V_8 -> V_167 ) ;
F_131 ( & V_8 -> V_76 ) ;
F_131 ( & V_8 -> V_67 ) ;
F_130 ( & V_8 -> V_282 ) ;
F_130 ( & V_8 -> V_192 ) ;
F_130 ( & V_8 -> V_187 ) ;
if ( V_8 -> V_39 . V_40 && ! V_8 -> V_39 . V_127 )
F_11 ( V_8 , false ) ;
return 0 ;
}
static int F_132 ( struct V_302 * V_303 )
{
int V_28 = 0 ;
struct V_1 * V_8 = F_128 ( V_303 ) ;
F_133 ( & V_8 -> V_4 ) ;
V_28 = F_11 ( V_8 , false ) ;
if ( V_28 )
F_17 ( V_8 -> V_30 , L_98 ) ;
F_134 ( V_8 -> V_75 ) ;
F_103 ( V_8 ) ;
F_135 () ;
F_126 ( V_8 ) ;
F_136 ( V_8 -> V_136 ) ;
return V_28 ;
}
static int F_137 ( struct V_302 * V_303 )
{
struct V_305 * V_306 = V_303 -> V_30 . V_307 ;
struct V_308 * V_309 = V_303 -> V_30 . V_310 ;
struct V_311 V_312 = {} ;
struct V_1 * V_8 ;
int V_6 , V_52 ;
int V_28 = 0 ;
V_8 = F_138 ( & V_303 -> V_30 , sizeof( * V_8 ) , V_313 ) ;
if ( ! V_8 ) {
F_17 ( & V_303 -> V_30 , L_99 , V_45 ) ;
return - V_314 ;
}
if ( ! V_309 ) {
F_17 ( & V_303 -> V_30 , L_100 ) ;
return - V_235 ;
}
V_8 -> V_10 = V_309 ;
if ( V_306 ) {
V_28 = F_139 ( & V_303 -> V_30 , V_306 , V_8 -> V_10 ) ;
if ( V_28 ) {
F_17 ( & V_303 -> V_30 , L_101 ) ;
return V_28 ;
}
}
F_140 ( & V_8 -> V_29 ) ;
V_8 -> V_30 = & V_303 -> V_30 ;
V_8 -> V_269 = F_85 ( V_303 -> V_30 . V_269 ) ;
V_8 -> V_79 = F_141 ( L_102 ) ;
V_312 . V_240 = V_315 ;
V_312 . V_242 = F_5 ( V_315 ) ;
V_312 . V_316 = V_8 ;
V_8 -> V_99 . V_100 = V_259 *
V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] . V_260 ;
V_8 -> V_99 . V_183 = V_8 -> V_99 . V_100 ;
V_8 -> V_104 = V_8 -> V_10 -> V_85 [ V_8 -> V_10 -> V_86 ] . V_261 ;
V_8 -> V_184 = true ;
F_59 ( V_8 , V_144 ) ;
F_60 ( V_8 , V_153 ) ;
V_8 -> V_75 = F_142 ( L_103 ) ;
if ( V_8 -> V_75 == NULL ) {
F_17 ( V_8 -> V_30 , L_104 ) ;
return - V_314 ;
}
F_143 ( & V_8 -> V_76 , F_75 ) ;
F_143 ( & V_8 -> V_67 , F_32 ) ;
F_144 ( & V_8 -> V_282 ,
F_95 ) ;
F_144 ( & V_8 -> V_167 ,
F_68 ) ;
F_144 ( & V_8 -> V_192 ,
F_70 ) ;
F_144 ( & V_8 -> V_187 ,
F_69 ) ;
V_8 -> V_39 . V_113 = false ;
V_8 -> V_194 = 10 ;
V_28 = F_88 ( V_8 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_105 ) ;
goto V_317;
}
V_8 -> V_39 . V_226 = true ;
V_8 -> V_39 . V_228 = false ;
V_8 -> V_136 = F_145 ( V_8 -> V_30 , & V_318 , & V_312 ) ;
if ( F_146 ( V_8 -> V_136 ) ) {
F_17 ( V_8 -> V_30 , L_106 ) ;
V_28 = F_147 ( V_8 -> V_136 ) ;
goto V_317;
}
V_8 -> V_36 = F_20 ( V_8 -> V_10 -> V_11 -> V_155 ) ;
F_11 ( V_8 , true ) ;
F_148 ( & V_8 -> V_50 ) ;
F_148 ( & V_8 -> V_51 ) ;
for ( V_6 = 0 ; V_6 < F_5 ( V_319 ) ; V_6 ++ ) {
V_52 = F_149 ( V_303 , V_319 [ V_6 ] . V_244 ) ;
V_28 = F_150 ( V_52 , V_319 [ V_6 ] . V_320 ,
V_321 | V_322 ,
V_319 [ V_6 ] . V_244 , V_8 ) ;
if ( V_28 != 0 ) {
F_17 ( V_8 -> V_30 , L_107 ,
V_319 [ V_6 ] . V_244 , V_52 , V_28 ) ;
goto V_323;
}
F_15 ( V_8 -> V_30 , L_108 ,
V_319 [ V_6 ] . V_244 , V_52 , V_28 ) ;
}
V_52 = F_149 ( V_303 , V_324 [ 0 ] . V_244 ) ;
V_28 = F_151 ( V_52 , NULL , V_324 [ 0 ] . V_320 ,
V_321 | V_322 | V_325 ,
V_324 [ 0 ] . V_244 , V_8 ) ;
if ( V_28 != 0 ) {
F_17 ( V_8 -> V_30 , L_107 ,
V_324 [ 0 ] . V_244 , V_52 , V_28 ) ;
goto V_323;
}
F_15 ( V_8 -> V_30 , L_108 ,
V_324 [ 0 ] . V_244 , V_52 , V_28 ) ;
V_8 -> V_52 = F_149 ( V_303 , L_109 ) ;
F_29 ( V_8 -> V_52 ) ;
V_8 -> V_47 = 0 ;
F_152 ( V_303 , V_8 ) ;
V_28 = F_105 ( V_8 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_80 ) ;
goto V_323;
}
V_28 = F_123 ( V_8 ) ;
if ( V_28 ) {
F_17 ( V_8 -> V_30 , L_110 ) ;
F_103 ( V_8 ) ;
goto V_323;
}
V_8 -> V_39 . V_182 = true ;
V_8 -> V_173 = V_174 ;
V_8 -> V_94 = 210 ;
F_65 ( V_8 -> V_75 , & V_8 -> V_167 , 0 ) ;
F_153 ( & V_8 -> V_4 , & V_3 ) ;
return V_28 ;
V_323:
F_136 ( V_8 -> V_136 ) ;
for ( V_6 = 0 ; V_6 < F_5 ( V_319 ) ; V_6 ++ ) {
V_52 = F_149 ( V_303 , V_319 [ V_6 ] . V_244 ) ;
V_323 ( V_52 , V_8 ) ;
}
V_52 = F_149 ( V_303 , V_324 [ 0 ] . V_244 ) ;
V_323 ( V_52 , V_8 ) ;
V_317:
F_134 ( V_8 -> V_75 ) ;
return V_28 ;
}
static int T_8 F_154 ( void )
{
return F_155 ( & V_326 ) ;
}
static void T_9 F_156 ( void )
{
F_157 ( & V_326 ) ;
}
