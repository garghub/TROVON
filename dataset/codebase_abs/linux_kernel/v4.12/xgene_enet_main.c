static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( ! V_2 )
return;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_5 ] ;
V_4 -> V_8 = F_2 ( V_5 |
F_3 ( V_9 , V_2 -> V_10 ) |
F_3 ( V_11 , 3 ) ) ;
}
}
static T_1 F_4 ( T_2 V_12 )
{
T_1 V_13 , V_14 ;
V_13 = F_5 ( V_15 , V_12 ) ;
if ( F_6 ( V_13 == 0x7800 ) ) {
return 0 ;
} else if ( ! ( V_13 & F_7 ( 14 ) ) ) {
V_14 = F_8 ( 13 , 0 ) ;
return ( V_13 & V_14 ) ? ( V_13 & V_14 ) : V_16 ;
} else if ( ! ( V_13 & F_8 ( 13 , 12 ) ) ) {
V_14 = F_8 ( 11 , 0 ) ;
return ( V_13 & V_14 ) ? ( V_13 & V_14 ) : V_17 ;
} else {
V_14 = F_8 ( 11 , 0 ) ;
return ( V_13 & V_14 ) ? ( V_13 & V_14 ) : V_18 ;
}
}
static T_1 F_9 ( T_3 V_19 )
{
T_1 V_13 ;
V_13 = ( V_19 == V_17 ) ? F_7 ( 14 ) : 0 ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_3 V_20 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
T_4 V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
T_3 V_6 , V_29 ;
T_1 V_13 ;
int V_5 ;
if ( F_6 ( ! V_2 ) )
return 0 ;
V_24 = V_2 -> V_24 ;
V_22 = F_11 ( V_24 ) ;
V_27 = F_12 ( V_24 ) ;
V_6 = V_2 -> V_6 - 1 ;
V_29 = V_2 -> V_29 ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_29 ] ;
V_28 = F_13 () ;
if ( F_6 ( ! V_28 ) )
return - V_30 ;
V_25 = F_14 ( V_27 , V_28 , 0 ,
V_31 , V_32 ) ;
if ( F_6 ( F_15 ( V_27 , V_25 ) ) ) {
F_16 ( V_28 ) ;
return - V_30 ;
}
V_13 = F_9 ( V_31 ) ;
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_25 ) |
F_3 ( V_15 , V_13 ) |
F_17 ( V_35 ) ) ;
V_2 -> V_36 [ V_29 ] = V_28 ;
V_29 = ( V_29 + 1 ) & V_6 ;
}
V_22 -> V_37 -> V_38 ( V_2 , V_20 ) ;
V_2 -> V_29 = V_29 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_3 V_20 )
{
struct V_39 * V_40 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_26 * V_27 ;
T_4 V_25 ;
T_3 V_29 = V_2 -> V_29 ;
T_3 V_6 = V_2 -> V_6 - 1 ;
T_1 V_12 , V_41 ;
int V_5 ;
V_24 = V_2 -> V_24 ;
V_27 = F_12 ( V_2 -> V_24 ) ;
V_22 = F_11 ( V_24 ) ;
V_12 = V_42 | ( V_43 & F_8 ( 11 , 0 ) ) ;
V_41 = V_44 ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_29 ] ;
V_40 = F_19 ( V_24 , V_41 ) ;
if ( F_6 ( ! V_40 ) )
return - V_30 ;
V_25 = F_20 ( V_27 , V_40 -> V_45 , V_41 , V_32 ) ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_24 , L_1 ) ;
F_22 ( V_40 ) ;
return - V_46 ;
}
V_2 -> V_47 [ V_29 ] = V_40 ;
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_25 ) |
F_3 ( V_15 , V_12 ) |
F_17 ( V_35 ) ) ;
V_29 = ( V_29 + 1 ) & V_6 ;
}
V_22 -> V_37 -> V_38 ( V_2 , V_20 ) ;
V_2 -> V_29 = V_29 ;
return 0 ;
}
static T_5 F_23 ( const void * V_45 )
{
const struct V_48 * V_49 = V_45 ;
return ( V_49 -> V_50 == F_24 ( V_51 ) ) ? V_52 : V_53 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_12 ( V_2 -> V_24 ) ;
struct V_3 * V_4 ;
T_4 V_25 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_47 [ V_5 ] ) {
F_22 ( V_2 -> V_47 [ V_5 ] ) ;
V_4 = & V_2 -> V_7 [ V_5 ] ;
V_25 = F_5 ( V_34 , F_26 ( V_4 -> V_33 ) ) ;
F_27 ( V_27 , V_25 , V_54 ,
V_32 ) ;
}
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_12 ( V_2 -> V_24 ) ;
T_4 V_25 ;
struct V_28 * V_28 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_28 = V_2 -> V_36 [ V_5 ] ;
if ( V_28 ) {
V_25 = V_2 -> V_55 [ V_5 ] ;
F_29 ( V_27 , V_25 , V_31 ,
V_32 ) ;
F_16 ( V_28 ) ;
}
}
}
static T_6 F_30 ( const int V_56 , void * V_45 )
{
struct V_1 * V_57 = V_45 ;
if ( F_31 ( & V_57 -> V_58 ) ) {
F_32 ( V_56 ) ;
F_33 ( & V_57 -> V_58 ) ;
}
return V_59 ;
}
static int F_34 ( struct V_1 * V_60 ,
struct V_61 * V_4 )
{
struct V_21 * V_22 = F_11 ( V_60 -> V_24 ) ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
T_7 * V_62 ;
T_4 * V_55 ;
T_1 V_63 ;
T_5 V_64 ;
int V_5 , V_65 = 0 ;
T_5 V_66 ;
V_63 = F_5 ( V_67 , F_26 ( V_4 -> V_8 ) ) ;
V_40 = V_60 -> V_68 [ V_63 ] ;
V_55 = & V_60 -> V_55 [ V_63 * V_69 ] ;
V_27 = F_12 ( V_60 -> V_24 ) ;
F_27 ( V_27 , F_5 ( V_34 , F_26 ( V_4 -> V_33 ) ) ,
F_35 ( V_40 ) ,
V_70 ) ;
for ( V_5 = 0 ; V_5 < F_36 ( V_40 ) -> V_71 ; V_5 ++ ) {
V_62 = & F_36 ( V_40 ) -> V_72 [ V_5 ] ;
F_29 ( V_27 , V_55 [ V_5 ] , F_37 ( V_62 ) ,
V_70 ) ;
}
if ( F_38 ( V_73 , F_26 ( V_4 -> V_74 ) ) ) {
V_66 = F_5 ( V_75 , F_26 ( V_4 -> V_74 ) ) ;
F_39 ( & V_22 -> V_76 ) ;
V_22 -> V_77 [ V_66 ] -- ;
F_40 ( & V_22 -> V_76 ) ;
}
V_64 = F_5 ( V_78 , F_26 ( V_4 -> V_8 ) ) ;
if ( F_6 ( V_64 > 2 ) ) {
F_41 ( V_60 , F_11 ( V_60 -> V_24 ) ,
V_64 ) ;
V_65 = - V_79 ;
}
if ( F_42 ( V_40 ) ) {
F_22 ( V_40 ) ;
} else {
F_21 ( V_60 -> V_24 , L_2 ) ;
V_65 = - V_79 ;
}
return V_65 ;
}
static int F_43 ( struct V_23 * V_24 , T_3 V_80 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
int V_66 = - V_81 ;
int V_5 ;
F_39 ( & V_22 -> V_76 ) ;
for ( V_5 = 0 ; V_66 < 0 && V_5 < V_82 ; V_5 ++ ) {
if ( V_22 -> V_80 [ V_5 ] == V_80 ) {
V_22 -> V_77 [ V_5 ] ++ ;
V_66 = V_5 ;
}
}
for ( V_5 = 0 ; V_66 < 0 && V_5 < V_82 ; V_5 ++ ) {
if ( ! V_22 -> V_77 [ V_5 ] ) {
V_22 -> V_77 [ V_5 ] ++ ;
V_22 -> V_83 -> V_84 ( V_22 , V_80 , V_5 ) ;
V_22 -> V_80 [ V_5 ] = V_80 ;
V_66 = V_5 ;
}
}
F_40 ( & V_22 -> V_76 ) ;
return V_66 ;
}
static int F_44 ( struct V_39 * V_40 , T_2 * V_85 )
{
struct V_23 * V_24 = V_40 -> V_27 ;
struct V_86 * V_87 ;
T_5 V_88 = 0 , V_89 = 0 ;
T_5 V_48 , V_90 = 0 , V_91 = 0 ;
T_3 V_92 , V_80 = 0 ;
T_3 V_5 , V_41 , V_71 ;
int V_66 ;
V_48 = F_23 ( V_40 -> V_45 ) ;
if ( F_6 ( V_40 -> V_93 != F_24 ( V_94 ) ) &&
F_6 ( V_40 -> V_93 != F_24 ( V_51 ) ) )
goto V_95;
if ( F_6 ( ! ( V_40 -> V_27 -> V_96 & V_97 ) ) )
goto V_95;
V_87 = F_45 ( V_40 ) ;
if ( F_6 ( F_46 ( V_87 ) ) )
goto V_95;
if ( F_42 ( V_87 -> V_93 == V_98 ) ) {
V_89 = F_47 ( V_40 ) >> 2 ;
V_91 = 1 ;
V_90 = V_99 ;
if ( V_24 -> V_96 & V_100 ) {
V_92 = V_48 + F_48 ( V_40 ) + F_47 ( V_40 ) ;
V_80 = F_36 ( V_40 ) -> V_101 ;
if ( F_49 ( V_40 ) ) {
V_41 = F_35 ( V_40 ) ;
V_71 = F_36 ( V_40 ) -> V_71 ;
for ( V_5 = 0 ; V_5 < 2 && V_5 < V_71 ; V_5 ++ )
V_41 += F_36 ( V_40 ) -> V_72 [ V_5 ] . V_19 ;
if ( F_6 ( V_92 > V_41 ) ) {
if ( F_50 ( V_40 ) )
return 0 ;
}
}
if ( ! V_80 || ( ( V_40 -> V_41 - V_92 ) <= V_80 ) )
goto V_95;
V_66 = F_43 ( V_24 , V_80 ) ;
if ( F_6 ( V_66 < 0 ) )
return - V_81 ;
* V_85 |= F_17 ( V_73 ) | F_3 ( V_75 , V_66 ) ;
}
} else if ( V_87 -> V_93 == V_102 ) {
V_89 = V_103 ;
V_91 = 1 ;
}
V_95:
V_88 = F_48 ( V_40 ) >> 2 ;
* V_85 |= F_3 ( V_104 , V_89 ) |
F_3 ( V_105 , V_88 ) |
F_3 ( V_106 , V_48 ) |
F_3 ( V_107 , V_91 ) |
F_3 ( V_108 , V_90 ) |
F_17 ( V_109 ) |
F_17 ( V_110 ) ;
return 0 ;
}
static T_1 F_51 ( T_1 V_41 )
{
return ( V_41 == V_111 ) ? 0 : V_41 ;
}
static void F_52 ( T_8 * V_112 , T_3 V_113 , T_4 V_114 , T_3 V_41 )
{
V_112 [ V_113 ^ 1 ] = F_2 ( F_3 ( V_34 , V_114 ) |
F_3 ( V_15 , V_41 ) ) ;
}
static T_8 * F_53 ( struct V_1 * V_115 )
{
T_8 * V_116 ;
V_116 = & V_115 -> V_116 [ V_115 -> V_117 * V_118 ] ;
memset ( V_116 , 0 , sizeof( T_8 ) * V_118 ) ;
V_115 -> V_117 = ( V_115 -> V_117 + 1 ) & ( ( V_115 -> V_6 / 2 ) - 1 ) ;
return V_116 ;
}
static T_4 * F_54 ( struct V_1 * V_115 )
{
return & V_115 -> V_60 -> V_55 [ V_115 -> V_29 * V_69 ] ;
}
static int F_55 ( struct V_1 * V_119 ,
struct V_39 * V_40 )
{
struct V_26 * V_27 = F_12 ( V_119 -> V_24 ) ;
struct V_21 * V_22 = F_11 ( V_119 -> V_24 ) ;
struct V_61 * V_4 ;
T_8 * V_120 = NULL , * V_116 = NULL ;
T_4 V_25 , V_121 , * V_55 ;
T_7 * V_62 ;
T_1 V_29 = V_119 -> V_29 ;
T_2 V_85 = 0 ;
T_3 V_41 , V_13 ;
T_5 V_122 = 0 , V_123 = 0 , V_113 = 0 ;
bool V_124 = false ;
T_3 V_19 , V_125 , V_126 = 0 ;
T_3 V_5 , V_127 , V_71 , V_128 = 1 ;
int V_65 ;
V_4 = & V_119 -> V_4 [ V_29 ] ;
V_29 = ( V_29 + 1 ) & ( V_119 -> V_6 - 1 ) ;
memset ( V_4 , 0 , sizeof( struct V_61 ) ) ;
V_65 = F_44 ( V_40 , & V_85 ) ;
if ( V_65 )
return V_65 ;
V_4 -> V_74 = F_2 ( F_3 ( V_129 , V_119 -> V_10 ) |
V_85 ) ;
V_41 = F_35 ( V_40 ) ;
V_13 = F_51 ( V_41 ) ;
V_25 = F_20 ( V_27 , V_40 -> V_45 , V_41 , V_70 ) ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_119 -> V_24 , L_1 ) ;
return - V_46 ;
}
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_25 ) |
F_3 ( V_15 , V_13 ) |
F_17 ( V_35 ) ) ;
if ( ! F_49 ( V_40 ) )
goto V_95;
V_123 = 1 ;
V_120 = ( void * ) & V_119 -> V_4 [ V_29 ] ;
V_29 = ( V_29 + 1 ) & ( V_119 -> V_6 - 1 ) ;
memset ( V_120 , 0 , sizeof( struct V_61 ) ) ;
V_71 = F_36 ( V_40 ) -> V_71 ;
for ( V_5 = V_71 ; V_5 < 4 ; V_5 ++ )
V_120 [ V_5 ^ 1 ] = F_2 ( V_130 ) ;
V_55 = F_54 ( V_119 ) ;
for ( V_5 = 0 , V_127 = 0 ; V_124 || ( V_127 < V_71 ) ; V_5 ++ ) {
if ( ! V_124 ) {
V_62 = & F_36 ( V_40 ) -> V_72 [ V_127 ] ;
V_19 = F_37 ( V_62 ) ;
V_125 = 0 ;
V_121 = F_56 ( V_27 , V_62 , 0 , V_19 ,
V_70 ) ;
if ( F_15 ( V_27 , V_121 ) )
return - V_46 ;
V_55 [ V_127 ] = V_121 ;
V_127 ++ ;
if ( V_19 > V_111 )
V_124 = true ;
}
if ( V_19 > V_111 ) {
V_41 = V_111 ;
V_19 -= V_111 ;
} else {
V_41 = V_19 ;
V_124 = false ;
}
V_25 = V_121 + V_125 ;
V_13 = F_51 ( V_41 ) ;
switch ( V_5 ) {
case 0 :
case 1 :
case 2 :
F_52 ( V_120 , V_5 , V_25 , V_13 ) ;
break;
case 3 :
if ( V_124 || ( V_127 != V_71 ) ) {
V_116 = F_53 ( V_119 ) ;
F_52 ( V_116 , V_113 , V_25 ,
V_13 ) ;
V_113 ++ ;
V_126 += V_41 ;
} else {
F_52 ( V_120 , V_5 , V_25 ,
V_13 ) ;
}
break;
default:
F_52 ( V_116 , V_113 , V_25 , V_13 ) ;
V_113 ++ ;
V_126 += V_41 ;
break;
}
if ( V_124 )
V_125 += V_111 ;
}
V_128 ++ ;
if ( V_113 ) {
V_122 = 1 ;
V_25 = F_20 ( V_27 , V_116 ,
sizeof( T_2 ) * V_118 ,
V_70 ) ;
if ( F_15 ( V_27 , V_25 ) ) {
F_22 ( V_40 ) ;
return - V_46 ;
}
V_5 = V_126 >> V_131 ;
V_120 [ 2 ] = F_2 ( F_3 ( V_34 , V_25 ) |
F_3 ( V_132 , V_5 ) |
F_3 ( V_133 , V_113 ) ) ;
V_4 -> V_134 = F_2 ( F_3 ( V_135 , V_126 ) ) ;
}
V_95:
V_4 -> V_8 = F_2 ( F_3 ( V_136 , V_122 ) | F_3 ( V_137 , V_123 ) |
F_3 ( V_67 , V_119 -> V_29 ) ) ;
V_119 -> V_60 -> V_68 [ V_119 -> V_29 ] = V_40 ;
V_22 -> V_138 [ V_119 -> V_60 -> V_139 ] += V_128 ;
V_119 -> V_29 = V_29 ;
return V_128 ;
}
static T_9 F_57 ( struct V_39 * V_40 ,
struct V_23 * V_24 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_1 * V_119 ;
int V_139 = V_40 -> V_140 ;
T_3 V_138 = V_22 -> V_138 [ V_139 ] ;
int V_128 ;
V_119 = V_22 -> V_119 [ V_139 ] ;
if ( V_138 < V_22 -> V_141 [ V_139 ] )
V_138 += ( ( F_58 ( V_22 -> V_138 [ V_139 ] ) ) ~ 0U ) ;
if ( ( V_138 - V_22 -> V_141 [ V_139 ] ) > V_22 -> V_142 ) {
F_59 ( V_24 , V_139 ) ;
return V_143 ;
}
if ( F_60 ( V_40 , V_144 ) )
return V_145 ;
V_128 = F_55 ( V_119 , V_40 ) ;
if ( V_128 == - V_81 )
return V_143 ;
if ( V_128 <= 0 ) {
F_22 ( V_40 ) ;
return V_145 ;
}
F_61 ( V_40 ) ;
V_119 -> V_146 ++ ;
V_119 -> V_147 += V_40 -> V_41 ;
V_22 -> V_37 -> V_38 ( V_119 , V_128 ) ;
return V_145 ;
}
static void F_62 ( struct V_39 * V_40 )
{
struct V_23 * V_24 = V_40 -> V_27 ;
struct V_86 * V_87 = F_45 ( V_40 ) ;
if ( ! ( V_24 -> V_96 & V_148 ) )
return;
if ( V_40 -> V_93 != F_24 ( V_94 ) )
return;
if ( F_46 ( V_87 ) )
return;
if ( V_87 -> V_93 != V_98 && V_87 -> V_93 != V_102 )
return;
V_40 -> V_149 = V_150 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_61 * V_4 ,
struct V_61 * V_120 )
{
T_8 * V_112 = ( void * ) V_120 ;
T_4 V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
T_1 V_6 , V_151 ;
T_3 V_152 ;
int V_5 ;
if ( ! V_2 || ! V_4 || ! V_120 ||
( ! F_5 ( V_137 , F_26 ( V_4 -> V_8 ) ) ) )
return;
V_27 = F_12 ( V_2 -> V_24 ) ;
V_6 = V_2 -> V_6 - 1 ;
V_151 = V_2 -> V_151 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_152 = F_4 ( F_26 ( V_112 [ V_5 ^ 1 ] ) ) ;
if ( ! V_152 )
break;
V_25 = F_5 ( V_34 , F_26 ( V_112 [ V_5 ^ 1 ] ) ) ;
F_29 ( V_27 , V_25 , V_31 , V_32 ) ;
V_28 = V_2 -> V_36 [ V_151 ] ;
F_16 ( V_28 ) ;
V_2 -> V_36 [ V_151 ] = NULL ;
V_151 = ( V_151 + 1 ) & V_6 ;
}
V_2 -> V_151 = V_151 ;
}
static bool F_64 ( struct V_39 * V_40 , T_3 V_41 , T_5 V_64 )
{
if ( V_64 == V_153 && V_41 == V_154 ) {
if ( F_65 ( F_66 ( V_40 ) -> V_50 ) < 46 )
return true ;
}
return false ;
}
static int F_67 ( struct V_1 * V_57 ,
struct V_61 * V_4 ,
struct V_61 * V_120 )
{
struct V_1 * V_2 , * V_155 ;
T_3 V_156 , V_152 , V_63 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
T_4 V_25 ;
struct V_39 * V_40 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
T_1 V_6 , V_151 ;
int V_5 , V_65 = 0 ;
T_8 * V_112 ;
T_5 V_64 ;
bool V_123 ;
V_24 = V_57 -> V_24 ;
V_22 = F_11 ( V_24 ) ;
V_27 = F_12 ( V_57 -> V_24 ) ;
V_2 = V_57 -> V_2 ;
V_155 = V_57 -> V_155 ;
F_27 ( V_27 , F_5 ( V_34 , F_26 ( V_4 -> V_33 ) ) ,
V_44 , V_32 ) ;
V_63 = F_5 ( V_67 , F_26 ( V_4 -> V_8 ) ) ;
V_40 = V_2 -> V_47 [ V_63 ] ;
V_2 -> V_47 [ V_63 ] = NULL ;
V_156 = F_4 ( F_26 ( V_4 -> V_33 ) ) ;
F_68 ( V_40 , V_156 ) ;
F_69 ( V_40 -> V_45 - V_157 ) ;
V_40 -> V_93 = F_70 ( V_40 , V_24 ) ;
V_64 = ( F_5 ( V_158 , F_26 ( V_4 -> V_8 ) ) << V_159 ) |
F_5 ( V_78 , F_26 ( V_4 -> V_8 ) ) ;
if ( F_6 ( V_64 ) ) {
if ( ! F_64 ( V_40 , V_156 , V_64 ) ) {
F_22 ( V_40 ) ;
F_63 ( V_155 , V_4 , V_120 ) ;
F_41 ( V_57 , V_22 , V_64 ) ;
goto V_95;
}
}
V_123 = F_5 ( V_137 , F_26 ( V_4 -> V_8 ) ) ;
if ( ! V_123 ) {
V_156 -= 4 ;
goto V_160;
}
V_6 = V_155 -> V_6 - 1 ;
V_151 = V_155 -> V_151 ;
V_112 = ( void * ) V_120 ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_152 = F_4 ( F_26 ( V_112 [ V_5 ^ 1 ] ) ) ;
if ( ! V_152 )
break;
V_25 = F_5 ( V_34 , F_26 ( V_112 [ V_5 ^ 1 ] ) ) ;
F_29 ( V_27 , V_25 , V_31 , V_32 ) ;
V_28 = V_155 -> V_36 [ V_151 ] ;
F_71 ( V_40 , F_36 ( V_40 ) -> V_71 , V_28 , 0 ,
V_152 , V_31 ) ;
V_156 += V_152 ;
V_155 -> V_36 [ V_151 ] = NULL ;
V_151 = ( V_151 + 1 ) & V_6 ;
}
V_155 -> V_151 = V_151 ;
V_57 -> V_161 -= F_36 ( V_40 ) -> V_71 ;
V_160:
F_72 ( V_40 ) ;
F_62 ( V_40 ) ;
V_57 -> V_162 ++ ;
V_57 -> V_163 += V_156 ;
F_73 ( & V_57 -> V_58 , V_40 ) ;
V_95:
if ( V_57 -> V_161 <= 0 ) {
V_65 = F_10 ( V_155 , V_164 ) ;
V_57 -> V_161 = V_164 ;
if ( V_65 )
return V_65 ;
}
if ( -- V_57 -> V_165 == 0 ) {
V_65 = F_18 ( V_2 , V_166 ) ;
V_57 -> V_165 = V_166 ;
}
return V_65 ;
}
static bool F_74 ( struct V_61 * V_4 )
{
return F_5 ( V_9 , F_26 ( V_4 -> V_8 ) ) ? true : false ;
}
static int F_75 ( struct V_1 * V_115 ,
int V_167 )
{
struct V_23 * V_24 = V_115 -> V_24 ;
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_61 * V_4 , * V_120 ;
T_1 V_151 = V_115 -> V_151 ;
T_1 V_6 = V_115 -> V_6 - 1 ;
int V_65 , V_168 , V_128 = 0 , V_169 = 0 ;
bool V_170 ;
do {
V_4 = & V_115 -> V_4 [ V_151 ] ;
V_168 = 0 ;
V_170 = false ;
V_120 = NULL ;
if ( F_6 ( F_76 ( V_4 ) ) )
break;
F_77 () ;
if ( F_38 ( V_137 , F_26 ( V_4 -> V_8 ) ) ) {
V_151 = ( V_151 + 1 ) & V_6 ;
V_120 = & V_115 -> V_4 [ V_151 ] ;
if ( F_6 ( F_76 ( V_120 ) ) ) {
V_151 = ( V_151 - 1 ) & V_6 ;
break;
}
F_77 () ;
V_128 ++ ;
V_168 ++ ;
}
if ( F_74 ( V_4 ) ) {
V_65 = F_67 ( V_115 , V_4 , V_120 ) ;
} else {
V_65 = F_34 ( V_115 , V_4 ) ;
V_170 = true ;
}
F_78 ( V_4 ) ;
if ( V_120 )
F_78 ( V_120 ) ;
V_151 = ( V_151 + 1 ) & V_6 ;
V_128 ++ ;
V_168 ++ ;
V_169 ++ ;
if ( V_170 )
V_22 -> V_141 [ V_115 -> V_139 ] += V_168 ;
if ( V_65 )
break;
} while ( -- V_167 );
if ( F_42 ( V_128 ) ) {
V_22 -> V_37 -> V_38 ( V_115 , - V_128 ) ;
V_115 -> V_151 = V_151 ;
if ( F_79 ( V_24 , V_115 -> V_139 ) )
F_80 ( V_24 , V_115 -> V_139 ) ;
}
return V_169 ;
}
static int F_81 ( struct V_171 * V_58 , const int V_167 )
{
struct V_1 * V_115 ;
int V_169 ;
V_115 = F_82 ( V_58 , struct V_1 , V_58 ) ;
V_169 = F_75 ( V_115 , V_167 ) ;
if ( V_169 != V_167 ) {
F_83 ( V_58 , V_169 ) ;
F_84 ( V_115 -> V_56 ) ;
}
return V_169 ;
}
static void F_85 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_172 * V_173 ;
int V_5 ;
V_22 -> V_83 -> V_174 ( V_22 ) ;
for ( V_5 = 0 ; V_5 < V_22 -> V_175 ; V_5 ++ ) {
V_173 = F_86 ( V_24 , V_5 ) ;
V_173 -> V_176 = V_177 ;
F_87 ( V_173 ) ;
}
}
static void F_88 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_1 * V_115 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_115 = V_22 -> V_57 [ V_5 ] ;
if ( ! V_22 -> V_179 ) {
snprintf ( V_115 -> V_180 , V_181 , L_3 ,
V_24 -> V_182 ) ;
} else {
snprintf ( V_115 -> V_180 , V_181 , L_4 ,
V_24 -> V_182 , V_5 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_22 -> V_179 ; V_5 ++ ) {
V_115 = V_22 -> V_119 [ V_5 ] -> V_60 ;
snprintf ( V_115 -> V_180 , V_181 , L_5 ,
V_24 -> V_182 , V_5 ) ;
}
}
static int F_89 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_26 * V_27 = F_12 ( V_24 ) ;
struct V_1 * V_115 ;
int V_65 = 0 , V_5 ;
F_88 ( V_24 ) ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_115 = V_22 -> V_57 [ V_5 ] ;
F_90 ( V_115 -> V_56 , V_183 ) ;
V_65 = F_91 ( V_27 , V_115 -> V_56 , F_30 ,
0 , V_115 -> V_180 , V_115 ) ;
if ( V_65 ) {
F_21 ( V_24 , L_6 ,
V_115 -> V_180 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_22 -> V_179 ; V_5 ++ ) {
V_115 = V_22 -> V_119 [ V_5 ] -> V_60 ;
F_90 ( V_115 -> V_56 , V_183 ) ;
V_65 = F_91 ( V_27 , V_115 -> V_56 , F_30 ,
0 , V_115 -> V_180 , V_115 ) ;
if ( V_65 ) {
F_21 ( V_24 , L_6 ,
V_115 -> V_180 ) ;
}
}
return V_65 ;
}
static void F_92 ( struct V_23 * V_24 )
{
struct V_21 * V_22 ;
struct V_1 * V_115 ;
struct V_26 * V_27 ;
int V_5 ;
V_22 = F_11 ( V_24 ) ;
V_27 = F_12 ( V_24 ) ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_115 = V_22 -> V_57 [ V_5 ] ;
F_93 ( V_115 -> V_56 , V_183 ) ;
F_94 ( V_27 , V_115 -> V_56 , V_115 ) ;
}
for ( V_5 = 0 ; V_5 < V_22 -> V_179 ; V_5 ++ ) {
V_115 = V_22 -> V_119 [ V_5 ] -> V_60 ;
F_93 ( V_115 -> V_56 , V_183 ) ;
F_94 ( V_27 , V_115 -> V_56 , V_115 ) ;
}
}
static void F_95 ( struct V_21 * V_22 )
{
struct V_171 * V_58 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_58 = & V_22 -> V_57 [ V_5 ] -> V_58 ;
F_96 ( V_58 ) ;
}
for ( V_5 = 0 ; V_5 < V_22 -> V_179 ; V_5 ++ ) {
V_58 = & V_22 -> V_119 [ V_5 ] -> V_60 -> V_58 ;
F_96 ( V_58 ) ;
}
}
static void F_97 ( struct V_21 * V_22 )
{
struct V_171 * V_58 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_58 = & V_22 -> V_57 [ V_5 ] -> V_58 ;
F_98 ( V_58 ) ;
}
for ( V_5 = 0 ; V_5 < V_22 -> V_179 ; V_5 ++ ) {
V_58 = & V_22 -> V_119 [ V_5 ] -> V_60 -> V_58 ;
F_98 ( V_58 ) ;
}
}
static int F_99 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
const struct V_184 * V_83 = V_22 -> V_83 ;
int V_65 ;
V_65 = F_100 ( V_24 , V_22 -> V_175 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_101 ( V_24 , V_22 -> V_178 ) ;
if ( V_65 )
return V_65 ;
F_95 ( V_22 ) ;
V_65 = F_89 ( V_24 ) ;
if ( V_65 )
return V_65 ;
if ( V_24 -> V_185 ) {
F_102 ( V_24 -> V_185 ) ;
} else {
F_103 ( & V_22 -> V_186 , V_187 ) ;
F_104 ( V_24 ) ;
}
V_83 -> V_188 ( V_22 ) ;
V_83 -> V_189 ( V_22 ) ;
F_105 ( V_24 ) ;
return V_65 ;
}
static int F_106 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
const struct V_184 * V_83 = V_22 -> V_83 ;
int V_5 ;
F_107 ( V_24 ) ;
V_83 -> V_190 ( V_22 ) ;
V_83 -> V_191 ( V_22 ) ;
if ( V_24 -> V_185 )
F_108 ( V_24 -> V_185 ) ;
else
F_109 ( & V_22 -> V_186 ) ;
F_92 ( V_24 ) ;
F_97 ( V_22 ) ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ )
F_75 ( V_22 -> V_57 [ V_5 ] , - 1 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_115 )
{
struct V_21 * V_22 ;
struct V_26 * V_27 ;
V_22 = F_11 ( V_115 -> V_24 ) ;
V_27 = F_12 ( V_115 -> V_24 ) ;
V_22 -> V_37 -> V_192 ( V_115 ) ;
F_111 ( V_27 , V_115 -> V_19 , V_115 -> V_193 , V_115 -> V_194 ) ;
}
static void F_112 ( struct V_21 * V_22 )
{
struct V_1 * V_2 , * V_155 ;
struct V_1 * V_115 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_175 ; V_5 ++ ) {
V_115 = V_22 -> V_119 [ V_5 ] ;
if ( V_115 ) {
F_110 ( V_115 ) ;
V_22 -> V_195 -> V_192 ( V_22 , V_115 ) ;
if ( V_22 -> V_179 )
F_110 ( V_115 -> V_60 ) ;
V_22 -> V_119 [ V_5 ] = NULL ;
}
}
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_115 = V_22 -> V_57 [ V_5 ] ;
if ( V_115 ) {
V_155 = V_115 -> V_155 ;
if ( V_155 ) {
F_28 ( V_155 ) ;
F_110 ( V_155 ) ;
V_22 -> V_195 -> V_192 ( V_22 , V_155 ) ;
}
V_2 = V_115 -> V_2 ;
F_25 ( V_2 ) ;
F_110 ( V_2 ) ;
V_22 -> V_195 -> V_192 ( V_22 , V_2 ) ;
F_110 ( V_115 ) ;
V_22 -> V_57 [ V_5 ] = NULL ;
}
}
}
static int F_113 ( struct V_26 * V_27 ,
enum V_196 V_197 )
{
int V_19 = - V_46 ;
switch ( V_197 ) {
case V_198 :
V_19 = 0x200 ;
break;
case V_199 :
V_19 = 0x800 ;
break;
case V_200 :
V_19 = 0x4000 ;
break;
case V_201 :
V_19 = 0x10000 ;
break;
case V_202 :
V_19 = 0x80000 ;
break;
default:
F_114 ( V_27 , L_7 , V_197 ) ;
break;
}
return V_19 ;
}
static void F_115 ( struct V_1 * V_115 )
{
struct V_21 * V_22 ;
struct V_26 * V_27 ;
if ( ! V_115 )
return;
V_27 = F_12 ( V_115 -> V_24 ) ;
V_22 = F_11 ( V_115 -> V_24 ) ;
if ( V_115 -> V_193 ) {
V_22 -> V_37 -> V_192 ( V_115 ) ;
F_111 ( V_27 , V_115 -> V_19 , V_115 -> V_193 , V_115 -> V_194 ) ;
}
F_116 ( V_27 , V_115 ) ;
}
static void F_117 ( struct V_21 * V_22 )
{
struct V_1 * V_155 ;
struct V_26 * V_27 = & V_22 -> V_203 -> V_27 ;
struct V_1 * V_115 ;
void * V_204 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_175 ; V_5 ++ ) {
V_115 = V_22 -> V_119 [ V_5 ] ;
if ( V_115 ) {
if ( V_115 -> V_60 && V_115 -> V_60 -> V_68 )
F_116 ( V_27 , V_115 -> V_60 -> V_68 ) ;
if ( V_115 -> V_60 && V_22 -> V_179 )
F_115 ( V_115 -> V_60 ) ;
F_115 ( V_115 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_115 = V_22 -> V_57 [ V_5 ] ;
if ( V_115 ) {
if ( V_115 -> V_2 ) {
if ( V_115 -> V_2 -> V_47 )
F_116 ( V_27 , V_115 -> V_2 -> V_47 ) ;
F_115 ( V_115 -> V_2 ) ;
}
V_155 = V_115 -> V_155 ;
if ( V_155 ) {
V_204 = V_155 -> V_36 ;
if ( V_204 )
F_116 ( V_27 , V_204 ) ;
V_204 = V_155 -> V_55 ;
if ( V_204 )
F_116 ( V_27 , V_204 ) ;
}
F_115 ( V_115 ) ;
}
}
}
static bool F_118 ( struct V_21 * V_22 ,
struct V_1 * V_115 )
{
if ( ( V_22 -> V_205 == V_206 ) &&
( F_119 ( V_115 -> V_207 ) == V_208 ) ) {
return true ;
}
return false ;
}
static void T_10 * F_120 ( struct V_21 * V_22 ,
struct V_1 * V_115 )
{
T_5 V_209 = V_22 -> V_37 -> V_209 ;
return V_22 -> V_210 + ( V_115 -> V_211 << V_209 ) ;
}
static struct V_1 * F_121 (
struct V_23 * V_24 , T_3 V_212 ,
enum V_196 V_197 , T_3 V_213 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_26 * V_27 = F_12 ( V_24 ) ;
struct V_1 * V_115 ;
void * V_214 ;
int V_19 ;
V_19 = F_113 ( V_27 , V_197 ) ;
if ( V_19 < 0 )
return NULL ;
V_115 = F_122 ( V_27 , sizeof( struct V_1 ) ,
V_215 ) ;
if ( ! V_115 )
return NULL ;
V_115 -> V_24 = V_24 ;
V_115 -> V_211 = V_212 ;
V_115 -> V_197 = V_197 ;
V_115 -> V_207 = V_213 ;
V_115 -> V_193 = F_123 ( V_27 , V_19 , & V_115 -> V_194 ,
V_215 | V_216 ) ;
if ( ! V_115 -> V_193 ) {
F_116 ( V_27 , V_115 ) ;
return NULL ;
}
V_115 -> V_19 = V_19 ;
if ( F_118 ( V_22 , V_115 ) ) {
V_214 = F_123 ( V_27 , V_217 ,
& V_115 -> V_218 ,
V_215 | V_216 ) ;
if ( ! V_214 ) {
F_111 ( V_27 , V_19 , V_115 -> V_193 ,
V_115 -> V_194 ) ;
F_116 ( V_27 , V_115 ) ;
return NULL ;
}
V_115 -> V_214 = V_214 ;
}
V_115 -> V_219 = F_120 ( V_22 , V_115 ) ;
V_115 -> V_220 = V_115 -> V_219 + V_221 ;
V_115 = V_22 -> V_37 -> V_222 ( V_115 ) ;
F_124 ( V_24 , L_8 ,
V_115 -> V_211 , V_115 -> V_19 , V_115 -> V_207 , V_115 -> V_6 ) ;
return V_115 ;
}
static T_1 F_125 ( enum V_223 V_224 , T_5 V_225 )
{
return ( V_224 << 6 ) | ( V_225 & F_8 ( 5 , 0 ) ) ;
}
static enum V_223 F_126 ( struct V_21 * V_204 )
{
enum V_223 V_224 ;
if ( V_204 -> V_205 == V_226 ) {
switch ( V_204 -> V_227 ) {
case V_228 :
V_224 = V_229 ;
break;
default:
V_224 = ( ! V_204 -> V_230 ) ? V_229 :
V_231 ;
break;
}
} else {
V_224 = ( ! V_204 -> V_230 ) ? V_229 : V_231 ;
}
return V_224 ;
}
static T_5 F_127 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = & V_22 -> V_203 -> V_27 ;
T_3 V_232 ;
int V_65 ;
V_65 = F_128 ( V_27 , L_9 , & V_232 ) ;
return ( ! V_65 ) ? V_232 : V_22 -> V_232 ;
}
static int F_129 ( struct V_23 * V_24 )
{
struct V_1 * V_57 , * V_119 , * V_60 ;
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_1 * V_155 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_26 * V_27 = F_12 ( V_24 ) ;
T_5 V_233 = V_22 -> V_233 ;
T_5 V_234 = V_22 -> V_234 ;
T_1 V_212 = V_22 -> V_212 ;
enum V_223 V_224 ;
T_4 V_235 ;
T_1 V_213 , V_6 ;
T_8 * V_116 ;
int V_5 , V_65 , V_19 ;
T_5 V_232 ;
V_232 = F_127 ( V_22 ) ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_224 = F_126 ( V_22 ) ;
V_213 = F_125 ( V_208 , V_232 ++ ) ;
V_57 = F_121 ( V_24 , V_212 ++ ,
V_200 ,
V_213 ) ;
if ( ! V_57 ) {
V_65 = - V_30 ;
goto V_236;
}
V_224 = F_126 ( V_22 ) ;
V_213 = F_125 ( V_224 , V_234 ++ ) ;
V_2 = F_121 ( V_24 , V_212 ++ ,
V_200 ,
V_213 ) ;
if ( ! V_2 ) {
V_65 = - V_30 ;
goto V_236;
}
V_57 -> V_165 = V_166 ;
V_57 -> V_161 = V_164 ;
V_57 -> V_56 = V_22 -> V_237 [ V_5 ] ;
V_2 -> V_47 = F_130 ( V_27 , V_2 -> V_6 ,
sizeof( struct V_39 * ) ,
V_215 ) ;
if ( ! V_2 -> V_47 ) {
V_65 = - V_30 ;
goto V_236;
}
V_2 -> V_10 = F_131 ( V_2 ) ;
V_57 -> V_2 = V_2 ;
V_22 -> V_57 [ V_5 ] = V_57 ;
if ( ( V_22 -> V_205 == V_226 && V_22 -> V_178 > 4 ) ||
( V_22 -> V_205 == V_206 && V_22 -> V_178 > 16 ) ) {
break;
}
V_224 = F_126 ( V_22 ) ;
V_213 = F_125 ( V_224 , V_234 ++ ) ;
V_155 = F_121 ( V_24 , V_212 ++ ,
V_200 ,
V_213 ) ;
if ( ! V_155 ) {
V_65 = - V_30 ;
goto V_236;
}
V_6 = V_155 -> V_6 ;
V_155 -> V_36 = F_130 ( V_27 , V_6 ,
sizeof( struct V_28 * ) ,
V_215 ) ;
if ( ! V_155 -> V_36 ) {
V_65 = - V_30 ;
goto V_236;
}
V_155 -> V_55 = F_130 ( V_27 , V_6 ,
sizeof( T_4 ) ,
V_215 ) ;
if ( ! V_155 -> V_55 ) {
V_65 = - V_30 ;
goto V_236;
}
V_155 -> V_10 = F_131 ( V_155 ) ;
V_57 -> V_155 = V_155 ;
}
for ( V_5 = 0 ; V_5 < V_22 -> V_175 ; V_5 ++ ) {
V_224 = F_126 ( V_22 ) ;
V_213 = F_125 ( V_224 , V_233 ++ ) ;
V_119 = F_121 ( V_24 , V_212 ++ ,
V_200 ,
V_213 ) ;
if ( ! V_119 ) {
V_65 = - V_30 ;
goto V_236;
}
V_19 = ( V_119 -> V_6 / 2 ) * sizeof( T_8 ) * V_118 ;
V_116 = F_123 ( V_27 , V_19 , & V_235 ,
V_215 | V_216 ) ;
if ( ! V_116 ) {
V_65 = - V_30 ;
goto V_236;
}
V_119 -> V_116 = V_116 ;
V_22 -> V_119 [ V_5 ] = V_119 ;
if ( ! V_22 -> V_179 ) {
V_60 = V_22 -> V_57 [ V_5 ] ;
} else {
V_213 = F_125 ( V_208 ,
V_232 ++ ) ;
V_60 = F_121 ( V_24 , V_212 ++ ,
V_200 ,
V_213 ) ;
if ( ! V_60 ) {
V_65 = - V_30 ;
goto V_236;
}
V_60 -> V_56 = V_22 -> V_237 [ V_22 -> V_178 + V_5 ] ;
V_60 -> V_139 = V_5 ;
}
V_60 -> V_68 = F_130 ( V_27 , V_119 -> V_6 ,
sizeof( struct V_39 * ) ,
V_215 ) ;
if ( ! V_60 -> V_68 ) {
V_65 = - V_30 ;
goto V_236;
}
V_19 = sizeof( T_4 ) * V_69 ;
V_60 -> V_55 = F_130 ( V_27 , V_119 -> V_6 ,
V_19 , V_215 ) ;
if ( ! V_60 -> V_55 ) {
F_116 ( V_27 , V_60 -> V_68 ) ;
V_65 = - V_30 ;
goto V_236;
}
V_119 -> V_60 = V_60 ;
V_119 -> V_10 = F_131 ( V_60 ) ;
}
if ( V_22 -> V_37 -> V_238 )
V_22 -> V_37 -> V_238 ( V_22 -> V_119 [ 0 ] ) ;
V_22 -> V_142 = V_22 -> V_119 [ 0 ] -> V_6 - 128 ;
return 0 ;
V_236:
F_117 ( V_22 ) ;
return V_65 ;
}
static void F_132 (
struct V_23 * V_24 ,
struct V_239 * V_240 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
struct V_239 * V_241 = & V_22 -> V_241 ;
struct V_1 * V_115 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_175 ; V_5 ++ ) {
V_115 = V_22 -> V_119 [ V_5 ] ;
if ( V_115 ) {
V_241 -> V_146 += V_115 -> V_146 ;
V_241 -> V_147 += V_115 -> V_147 ;
}
}
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_115 = V_22 -> V_57 [ V_5 ] ;
if ( V_115 ) {
V_241 -> V_162 += V_115 -> V_162 ;
V_241 -> V_163 += V_115 -> V_163 ;
V_241 -> V_242 += V_115 -> V_243 +
V_115 -> V_244 +
V_115 -> V_245 +
V_115 -> V_246 ;
V_241 -> V_247 += V_115 -> V_247 ;
}
}
memcpy ( V_240 , V_241 , sizeof( struct V_239 ) ) ;
}
static int F_133 ( struct V_23 * V_24 , void * V_114 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
int V_65 ;
V_65 = F_134 ( V_24 , V_114 ) ;
if ( V_65 )
return V_65 ;
V_22 -> V_83 -> V_248 ( V_22 ) ;
return V_65 ;
}
static int F_135 ( struct V_23 * V_24 , int V_249 )
{
struct V_21 * V_22 = F_11 ( V_24 ) ;
int V_250 ;
if ( ! F_136 ( V_24 ) )
return 0 ;
V_250 = ( V_249 > V_251 ) ? ( V_249 + 18 ) : 0x600 ;
F_106 ( V_24 ) ;
V_24 -> V_252 = V_249 ;
V_22 -> V_83 -> V_253 ( V_22 , V_250 ) ;
F_99 ( V_24 ) ;
return 0 ;
}
static void F_137 ( struct V_26 * V_27 ,
struct V_21 * V_22 )
{
T_11 V_64 ;
T_2 V_254 ;
V_64 = F_138 ( F_139 ( V_27 ) , L_10 , NULL , & V_254 ) ;
if ( F_140 ( V_64 ) ) {
V_22 -> V_230 = 0 ;
} else {
V_22 -> V_230 = V_254 ;
}
return;
}
static void F_141 ( struct V_26 * V_27 , struct V_21 * V_22 )
{
T_3 V_207 = 0 ;
F_142 ( V_27 -> V_255 , L_11 , & V_207 ) ;
V_22 -> V_230 = V_207 & F_7 ( 0 ) ;
return;
}
static int F_143 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = & V_22 -> V_203 -> V_27 ;
int V_256 , V_65 ;
V_65 = F_142 ( V_27 -> V_255 , L_12 , & V_256 ) ;
if ( V_65 ) {
V_22 -> V_257 = 4 ;
return 0 ;
}
if ( V_256 < 0 || V_256 > 7 ) {
F_114 ( V_27 , L_13 ) ;
return - V_46 ;
}
V_22 -> V_257 = V_256 ;
return 0 ;
}
static int F_144 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = & V_22 -> V_203 -> V_27 ;
int V_256 , V_65 ;
V_65 = F_142 ( V_27 -> V_255 , L_14 , & V_256 ) ;
if ( V_65 ) {
V_22 -> V_258 = 2 ;
return 0 ;
}
if ( V_256 < 0 || V_256 > 7 ) {
F_114 ( V_27 , L_15 ) ;
return - V_46 ;
}
V_22 -> V_258 = V_256 ;
return 0 ;
}
static int F_145 ( struct V_21 * V_22 )
{
struct V_259 * V_203 = V_22 -> V_203 ;
struct V_26 * V_27 = & V_203 -> V_27 ;
int V_5 , V_65 , V_260 ;
if ( V_22 -> V_227 == V_261 )
V_260 = 1 ;
else if ( V_22 -> V_227 == V_228 )
V_260 = 2 ;
else
V_260 = V_262 ;
for ( V_5 = 0 ; V_5 < V_260 ; V_5 ++ ) {
V_65 = F_146 ( V_203 , V_5 ) ;
if ( V_65 <= 0 ) {
if ( V_22 -> V_227 == V_263 ) {
V_260 = V_5 ;
V_22 -> V_178 = V_260 / 2 ;
V_22 -> V_175 = V_260 / 2 ;
V_22 -> V_179 = V_260 / 2 ;
break;
}
F_114 ( V_27 , L_16 ) ;
V_65 = V_65 ? : - V_264 ;
return V_65 ;
}
V_22 -> V_237 [ V_5 ] = V_65 ;
}
return 0 ;
}
static int F_147 ( struct V_21 * V_22 )
{
int V_65 ;
if ( V_22 -> V_227 == V_263 )
return 0 ;
if ( ! F_148 ( V_265 ) )
return 0 ;
V_65 = F_149 ( V_22 -> V_24 ) ;
if ( ! V_65 )
V_22 -> V_266 = true ;
return 0 ;
}
static void F_150 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = & V_22 -> V_203 -> V_27 ;
V_22 -> V_267 = false ;
if ( V_22 -> V_227 != V_263 ||
( ! F_151 ( V_27 , L_17 ) &&
! F_151 ( V_27 , L_18 ) ) )
return;
V_22 -> V_267 = true ;
V_22 -> V_268 = F_152 ( V_27 , L_19 , V_269 ) ;
if ( F_153 ( V_22 -> V_268 ) )
V_22 -> V_268 = F_152 ( V_27 , L_20 , V_269 ) ;
}
static int F_154 ( struct V_21 * V_22 )
{
struct V_259 * V_203 ;
struct V_23 * V_24 ;
struct V_26 * V_27 ;
struct V_270 * V_271 ;
void T_10 * V_272 ;
T_3 V_125 ;
int V_65 = 0 ;
V_203 = V_22 -> V_203 ;
V_27 = & V_203 -> V_27 ;
V_24 = V_22 -> V_24 ;
V_271 = F_155 ( V_203 , V_273 , V_274 ) ;
if ( ! V_271 ) {
F_114 ( V_27 , L_21 ) ;
return - V_275 ;
}
V_22 -> V_272 = F_156 ( V_27 , V_271 -> V_276 , F_157 ( V_271 ) ) ;
if ( ! V_22 -> V_272 ) {
F_114 ( V_27 , L_22 ) ;
return - V_30 ;
}
V_271 = F_155 ( V_203 , V_273 , V_277 ) ;
if ( ! V_271 ) {
F_114 ( V_27 , L_23 ) ;
return - V_275 ;
}
V_22 -> V_278 = F_156 ( V_27 , V_271 -> V_276 ,
F_157 ( V_271 ) ) ;
if ( ! V_22 -> V_278 ) {
F_114 ( V_27 , L_24 ) ;
return - V_30 ;
}
V_271 = F_155 ( V_203 , V_273 , V_279 ) ;
if ( ! V_271 ) {
F_114 ( V_27 , L_25 ) ;
return - V_275 ;
}
V_22 -> V_210 = F_156 ( V_27 , V_271 -> V_276 ,
F_157 ( V_271 ) ) ;
if ( ! V_22 -> V_210 ) {
F_114 ( V_27 , L_26 ) ;
return - V_30 ;
}
if ( V_27 -> V_255 )
F_141 ( V_27 , V_22 ) ;
#ifdef F_158
else
F_137 ( V_27 , V_22 ) ;
#endif
if ( ! F_159 ( V_27 , V_24 -> V_280 , V_281 ) )
F_160 ( V_24 ) ;
memcpy ( V_24 -> V_282 , V_24 -> V_280 , V_24 -> V_283 ) ;
V_22 -> V_227 = F_161 ( V_27 ) ;
if ( V_22 -> V_227 < 0 ) {
F_114 ( V_27 , L_27 ) ;
return V_22 -> V_227 ;
}
if ( V_22 -> V_227 != V_261 &&
V_22 -> V_227 != V_228 &&
V_22 -> V_227 != V_263 ) {
F_114 ( V_27 , L_28 ) ;
return - V_275 ;
}
V_65 = F_143 ( V_22 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_144 ( V_22 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_145 ( V_22 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_147 ( V_22 ) ;
if ( V_65 )
return V_65 ;
F_150 ( V_22 ) ;
V_22 -> V_284 = F_162 ( & V_203 -> V_27 , NULL ) ;
if ( F_153 ( V_22 -> V_284 ) ) {
if ( F_163 ( V_22 -> V_284 ) != - V_285 || V_27 -> V_255 )
return F_163 ( V_22 -> V_284 ) ;
F_164 ( V_27 , L_29 ) ;
}
if ( V_22 -> V_227 != V_263 )
V_272 = V_22 -> V_272 - ( V_22 -> V_230 * V_286 ) ;
else
V_272 = V_22 -> V_272 ;
V_22 -> V_287 = V_272 + V_288 ;
V_22 -> V_289 . V_290 = V_272 + V_291 ;
V_22 -> V_292 = V_272 + V_293 ;
V_22 -> V_294 = V_272 + V_295 ;
if ( V_22 -> V_227 == V_261 ||
V_22 -> V_227 == V_228 ) {
V_22 -> V_296 = V_22 -> V_272 + V_297 ;
V_125 = ( V_22 -> V_205 == V_226 ) ?
V_298 :
V_299 ;
V_22 -> V_300 = V_272 + V_125 ;
} else {
V_22 -> V_296 = V_272 + V_301 ;
V_22 -> V_300 = V_272 + V_302 ;
V_22 -> V_303 = V_272 + V_304 ;
}
V_22 -> V_305 = V_306 ;
return 0 ;
}
static int F_165 ( struct V_21 * V_22 )
{
struct V_307 * V_308 = & V_22 -> V_289 ;
struct V_1 * V_155 ;
struct V_23 * V_24 = V_22 -> V_24 ;
struct V_1 * V_2 ;
T_1 V_10 , V_213 ;
int V_5 , V_65 ;
T_3 V_128 ;
V_65 = V_22 -> V_195 -> V_174 ( V_22 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_129 ( V_24 ) ;
if ( V_65 ) {
F_21 ( V_24 , L_30 ) ;
return V_65 ;
}
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_2 = V_22 -> V_57 [ V_5 ] -> V_2 ;
F_1 ( V_2 ) ;
V_155 = V_22 -> V_57 [ V_5 ] -> V_155 ;
F_1 ( V_155 ) ;
V_128 = V_22 -> V_305 ;
V_65 = F_18 ( V_2 , V_128 ) ;
if ( V_65 )
goto V_236;
V_65 = F_10 ( V_155 , V_128 ) ;
if ( V_65 )
goto V_236;
}
V_10 = F_131 ( V_22 -> V_57 [ 0 ] ) ;
V_2 = V_22 -> V_57 [ 0 ] -> V_2 ;
if ( V_22 -> V_227 == V_263 ) {
V_308 -> V_309 = 512 ;
V_308 -> V_310 = 1024 ;
V_308 -> V_311 = 3 ;
V_308 -> V_312 = V_313 ;
V_308 -> V_314 . V_315 = 0 ;
V_308 -> V_314 . V_316 = 0 ;
V_308 -> V_317 = 8 ;
V_65 = V_22 -> V_318 -> V_319 ( V_22 ) ;
if ( V_65 ) {
F_21 ( V_24 , L_31 ) ;
goto V_236;
}
} else {
V_10 = F_131 ( V_22 -> V_57 [ 0 ] ) ;
V_2 = V_22 -> V_57 [ 0 ] -> V_2 ;
V_155 = V_22 -> V_57 [ 0 ] -> V_155 ;
V_213 = ( V_155 ) ? V_155 -> V_207 : 0 ;
V_22 -> V_195 -> V_320 ( V_22 , V_10 ,
V_2 -> V_207 , V_213 ) ;
}
V_24 -> V_321 = V_54 ;
V_22 -> V_322 = V_323 ;
V_22 -> V_83 -> V_324 ( V_22 ) ;
return V_65 ;
V_236:
F_112 ( V_22 ) ;
return V_65 ;
}
static void F_166 ( struct V_21 * V_22 )
{
switch ( V_22 -> V_227 ) {
case V_261 :
V_22 -> V_83 = & V_325 ;
V_22 -> V_195 = & V_326 ;
V_22 -> V_327 = V_328 ;
V_22 -> V_178 = 1 ;
V_22 -> V_175 = 1 ;
V_22 -> V_179 = 0 ;
break;
case V_228 :
V_22 -> V_83 = & V_329 ;
V_22 -> V_195 = & V_330 ;
V_22 -> V_327 = V_331 ;
V_22 -> V_178 = 1 ;
V_22 -> V_175 = 1 ;
V_22 -> V_179 = 1 ;
break;
default:
V_22 -> V_83 = & V_332 ;
V_22 -> V_195 = & V_333 ;
V_22 -> V_318 = & V_334 ;
V_22 -> V_327 = V_335 ;
if ( ! V_22 -> V_178 ) {
V_22 -> V_178 = V_336 ;
V_22 -> V_175 = V_337 ;
V_22 -> V_179 = V_338 ;
}
break;
}
if ( V_22 -> V_205 == V_226 ) {
switch ( V_22 -> V_230 ) {
case 0 :
if ( V_22 -> V_227 == V_263 ) {
V_22 -> V_232 = V_339 ;
V_22 -> V_233 = V_340 ;
V_22 -> V_234 = V_341 ;
V_22 -> V_212 = V_342 ;
} else {
V_22 -> V_232 = V_343 ;
V_22 -> V_233 = V_344 ;
V_22 -> V_234 = V_345 ;
V_22 -> V_212 = V_342 ;
}
break;
case 1 :
if ( V_22 -> V_227 == V_263 ) {
V_22 -> V_232 = V_346 ;
V_22 -> V_233 = V_347 ;
V_22 -> V_234 = V_348 ;
V_22 -> V_212 = V_349 ;
} else {
V_22 -> V_232 = V_350 ;
V_22 -> V_233 = V_351 ;
V_22 -> V_234 = V_352 ;
V_22 -> V_212 = V_353 ;
}
break;
default:
break;
}
V_22 -> V_37 = & V_354 ;
} else {
switch ( V_22 -> V_230 ) {
case 0 :
V_22 -> V_232 = V_339 ;
V_22 -> V_233 = V_340 ;
V_22 -> V_234 = V_341 ;
V_22 -> V_212 = V_355 ;
break;
case 1 :
V_22 -> V_232 = V_356 ;
V_22 -> V_233 = V_357 ;
V_22 -> V_234 = V_358 ;
V_22 -> V_212 = V_359 ;
break;
default:
break;
}
V_22 -> V_327 = V_335 ;
V_22 -> V_37 = & V_360 ;
}
}
static void F_167 ( struct V_21 * V_22 )
{
struct V_171 * V_58 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_178 ; V_5 ++ ) {
V_58 = & V_22 -> V_57 [ V_5 ] -> V_58 ;
F_168 ( V_22 -> V_24 , V_58 , F_81 ,
V_361 ) ;
}
for ( V_5 = 0 ; V_5 < V_22 -> V_179 ; V_5 ++ ) {
V_58 = & V_22 -> V_119 [ V_5 ] -> V_60 -> V_58 ;
F_168 ( V_22 -> V_24 , V_58 , F_81 ,
V_361 ) ;
}
}
static int F_169 ( struct V_259 * V_203 )
{
struct V_23 * V_24 ;
struct V_21 * V_22 ;
struct V_26 * V_27 = & V_203 -> V_27 ;
void (* F_170)( struct V_362 * );
const struct V_363 * V_364 ;
int V_65 ;
V_24 = F_171 ( sizeof( struct V_21 ) ,
V_336 , V_337 ) ;
if ( ! V_24 )
return - V_30 ;
V_22 = F_11 ( V_24 ) ;
V_22 -> V_203 = V_203 ;
V_22 -> V_24 = V_24 ;
F_172 ( V_24 , V_27 ) ;
F_173 ( V_203 , V_22 ) ;
V_24 -> V_365 = & V_366 ;
F_174 ( V_24 ) ;
V_24 -> V_96 |= V_97 |
V_367 |
V_368 |
V_369 ;
V_364 = F_175 ( V_370 , & V_203 -> V_27 ) ;
if ( V_364 ) {
V_22 -> V_205 = (enum V_371 ) V_364 -> V_45 ;
}
#ifdef F_158
else {
const struct V_372 * V_373 ;
V_373 = F_176 ( V_374 , & V_203 -> V_27 ) ;
if ( V_373 )
V_22 -> V_205 = (enum V_371 ) V_373 -> V_375 ;
}
#endif
if ( ! V_22 -> V_205 ) {
V_65 = - V_275 ;
goto V_236;
}
V_65 = F_154 ( V_22 ) ;
if ( V_65 )
goto V_236;
F_166 ( V_22 ) ;
if ( V_22 -> V_227 == V_263 ) {
V_24 -> V_96 |= V_100 | V_148 ;
F_177 ( & V_22 -> V_76 ) ;
}
V_24 -> V_376 = V_24 -> V_96 ;
V_65 = F_178 ( V_27 , F_179 ( 64 ) ) ;
if ( V_65 ) {
F_21 ( V_24 , L_32 ) ;
goto V_236;
}
V_65 = F_165 ( V_22 ) ;
if ( V_65 )
goto V_236;
F_170 = V_22 -> V_83 -> F_170 ;
if ( V_22 -> V_227 == V_263 ) {
F_180 ( & V_22 -> V_186 , F_170 ) ;
} else if ( ! V_22 -> V_266 ) {
if ( V_22 -> V_227 == V_261 )
V_65 = F_181 ( V_22 ) ;
else
F_180 ( & V_22 -> V_186 , F_170 ) ;
if ( V_65 )
goto V_377;
}
F_167 ( V_22 ) ;
V_65 = F_182 ( V_24 ) ;
if ( V_65 ) {
F_21 ( V_24 , L_33 ) ;
goto V_378;
}
return 0 ;
V_378:
if ( V_22 -> V_266 )
F_183 ( V_22 ) ;
else if ( V_22 -> V_227 == V_261 )
F_184 ( V_22 ) ;
V_377:
F_112 ( V_22 ) ;
V_236:
F_185 ( V_24 ) ;
return V_65 ;
}
static int F_186 ( struct V_259 * V_203 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
V_22 = F_187 ( V_203 ) ;
V_24 = V_22 -> V_24 ;
F_188 () ;
if ( F_136 ( V_24 ) )
F_189 ( V_24 ) ;
F_190 () ;
if ( V_22 -> V_266 )
F_183 ( V_22 ) ;
else if ( V_22 -> V_227 == V_261 )
F_184 ( V_22 ) ;
F_191 ( V_24 ) ;
V_22 -> V_195 -> V_379 ( V_22 ) ;
F_112 ( V_22 ) ;
F_185 ( V_24 ) ;
return 0 ;
}
static void F_192 ( struct V_259 * V_203 )
{
struct V_21 * V_22 ;
V_22 = F_187 ( V_203 ) ;
if ( ! V_22 )
return;
if ( ! V_22 -> V_24 )
return;
F_186 ( V_203 ) ;
}
