static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 * V_4 = V_2 -> V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_4 ) {
* V_4 ++ = ( T_2 ) V_3 ;
V_2 -> V_4 = V_4 ;
}
V_2 -> V_7 -- ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
const T_2 * V_8 = V_2 -> V_8 ;
if ( V_8 ) {
V_3 = * V_8 ++ ;
V_2 -> V_8 = V_8 ;
}
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
V_2 -> V_10 -- ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_3 * V_4 = V_2 -> V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_4 ) {
* V_4 ++ = ( T_3 ) V_3 ;
V_2 -> V_4 = V_4 ;
}
V_2 -> V_7 -- ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
const T_3 * V_8 = V_2 -> V_8 ;
if ( V_8 ) {
V_3 = * V_8 ++ ;
V_2 -> V_8 = V_8 ;
}
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
V_2 -> V_10 -- ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 * V_4 = V_2 -> V_4 ;
V_3 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_4 ) {
* V_4 ++ = ( T_1 ) V_3 ;
V_2 -> V_4 = V_4 ;
}
V_2 -> V_7 -- ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
const T_1 * V_8 = V_2 -> V_8 ;
if ( V_8 ) {
V_3 = * V_8 ++ ;
V_2 -> V_8 = V_8 ;
}
F_4 ( V_3 , V_2 -> V_5 + V_9 ) ;
V_2 -> V_10 -- ;
}
static T_4 F_9 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
T_1 V_13 = F_2 ( V_2 -> V_5 + V_14 ) ;
if ( V_2 -> V_15 && ( V_13 & V_16 ) ) {
F_10 ( & V_2 -> V_17 ) ;
F_4 ( 0x0 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_19 ,
V_2 -> V_5 + V_14 ) ;
return V_20 ;
}
if ( V_13 & V_21 ||
V_13 & V_22 ) {
F_10 ( & V_2 -> V_17 ) ;
F_10 ( & V_2 -> V_23 ) ;
F_4 ( 0x0 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_19 ,
V_2 -> V_5 + V_14 ) ;
return V_20 ;
}
if ( V_13 & V_24 )
F_10 ( & V_2 -> V_17 ) ;
while ( ! ( F_2 ( V_2 -> V_5 + V_14 ) &
V_25 ) )
F_11 () ;
F_10 ( & V_2 -> V_23 ) ;
F_4 ( 0x0 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_19 ,
V_2 -> V_5 + V_14 ) ;
return V_20 ;
}
static void F_12 ( void * V_3 )
{
struct V_26 * V_27 = V_3 ;
F_10 ( V_27 ) ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 ;
int V_32 = V_31 -> V_33 * 10 ;
T_1 V_34 ;
V_2 = F_14 ( V_29 -> V_35 ) ;
memcpy ( & V_34 , V_2 -> V_8 , V_31 -> V_33 ) ;
if ( V_2 -> V_36 == 1 && ! ( V_29 -> V_37 & V_38 ) )
V_34 = F_15 ( V_34 ) >>
( ( V_39 - V_31 -> V_33 ) * 8 ) ;
if ( V_2 -> V_36 == 2 && V_31 -> V_33 == 4 &&
( ! ( V_29 -> V_37 & V_38 ) ) )
V_34 = ( ( V_34 & 0xffff ) << 16 ) | ( V_34 >> 16 ) ;
F_4 ( V_34 , V_2 -> V_5 + V_40 ) ;
F_4 ( V_41 ,
V_2 -> V_5 + V_18 ) ;
F_4 ( V_42 ,
V_2 -> V_5 + V_43 ) ;
if ( F_16 ( & V_2 -> V_17 , V_32 ) == 0 ) {
F_17 ( & V_29 -> V_44 , L_1 ) ;
return 0 ;
}
return V_31 -> V_33 ;
}
static void F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 , * V_47 ;
int V_32 = V_31 -> V_33 * 10 ;
V_2 = F_14 ( V_29 -> V_35 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_49 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_50 ) ;
F_4 ( V_51 , V_2 -> V_5 + V_49 ) ;
F_4 ( V_51 , V_2 -> V_5 + V_50 ) ;
F_4 ( 0 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_19 , V_2 -> V_5 + V_14 ) ;
if ( V_2 -> V_10 < V_52 ) {
F_4 ( F_2 ( V_2 -> V_5 + V_53 ) |
V_54 | V_55 ,
V_2 -> V_5 + V_53 ) ;
F_4 ( V_2 -> V_10 - 1 ,
V_2 -> V_5 + V_56 ) ;
F_4 ( V_2 -> V_10 - 1 ,
V_2 -> V_5 + V_57 ) ;
} else {
F_4 ( F_2 ( V_2 -> V_5 + V_53 ) ,
V_2 -> V_5 + V_53 ) ;
F_4 ( 0 , V_2 -> V_5 + V_56 ) ;
F_4 ( 0 , V_2 -> V_5 + V_57 ) ;
}
V_2 -> V_58 = F_19 ( & V_29 -> V_44 , V_2 -> V_4 , V_31 -> V_33 ,
( V_31 -> V_59 != V_31 -> V_60 ) ?
V_61 : V_62 ) ;
V_46 = F_20 ( V_2 -> V_63 ,
V_2 -> V_58 , V_31 -> V_33 , V_64 ,
V_65 | V_66 ) ;
V_46 -> V_67 = F_12 ;
V_46 -> V_68 = & V_2 -> V_23 ;
V_2 -> V_69 = F_19 ( & V_29 -> V_44 , ( void * ) V_2 -> V_8 , V_31 -> V_33 ,
( V_31 -> V_59 != V_31 -> V_60 ) ?
V_70 : V_62 ) ;
V_47 = F_20 ( V_2 -> V_71 ,
V_2 -> V_69 , V_31 -> V_33 , V_72 ,
V_65 | V_66 ) ;
V_47 -> V_67 = F_12 ;
V_47 -> V_68 = & V_2 -> V_17 ;
F_21 ( V_47 ) ;
F_21 ( V_46 ) ;
F_22 ( V_2 -> V_71 ) ;
F_22 ( V_2 -> V_63 ) ;
F_4 ( V_73 | V_74 ,
V_2 -> V_5 + V_43 ) ;
if ( F_16 ( & V_2 -> V_23 , V_32 ) == 0 ) {
F_17 ( & V_29 -> V_44 , L_2 ) ;
F_23 ( V_2 -> V_63 ) ;
} else
V_2 -> V_7 = 0 ;
if ( F_16 ( & V_2 -> V_17 , V_32 ) == 0 ) {
F_17 ( & V_29 -> V_44 , L_2 ) ;
F_23 ( V_2 -> V_71 ) ;
}
F_24 ( & V_29 -> V_44 , V_2 -> V_69 , V_31 -> V_33 , V_70 ) ;
F_24 ( & V_29 -> V_44 , V_2 -> V_58 , V_31 -> V_33 , V_61 ) ;
F_4 ( 0 , V_2 -> V_5 + V_49 ) ;
F_4 ( 0 , V_2 -> V_5 + V_50 ) ;
if ( V_2 -> V_10 >= V_52 )
F_4 ( 0 , V_2 -> V_5 + V_43 ) ;
}
static void F_25 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 ;
int V_32 = V_31 -> V_33 * 10 ;
V_2 = F_14 ( V_29 -> V_35 ) ;
do {
F_4 ( V_48 ,
V_2 -> V_5 + V_49 ) ;
F_4 ( V_48 ,
V_2 -> V_5 + V_50 ) ;
F_4 ( V_51 ,
V_2 -> V_5 + V_49 ) ;
F_4 ( V_51 ,
V_2 -> V_5 + V_50 ) ;
F_4 ( 0 , V_2 -> V_5 + V_18 ) ;
F_4 ( V_19 ,
V_2 -> V_5 + V_14 ) ;
F_4 ( F_2 ( V_2 -> V_5 + V_53 ) |
V_55 | V_54 ,
V_2 -> V_5 + V_53 ) ;
F_4 ( F_26 ( V_2 -> V_10 , ( T_1 ) ( 256 / V_2 -> V_36 ) )
- 1 , V_2 -> V_5 + V_56 ) ;
F_4 ( F_26 ( V_2 -> V_7 , ( T_1 ) ( 256 / V_2 -> V_36 ) )
- 1 , V_2 -> V_5 + V_57 ) ;
while ( ! ( ( F_2 ( V_2 -> V_5 + V_75 )
& V_76 ) ) && V_2 -> V_10 )
V_2 -> V_77 ( V_2 ) ;
F_4 ( V_78 |
V_79 |
V_80 ,
V_2 -> V_5 + V_18 ) ;
F_4 ( V_73 | V_74 ,
V_2 -> V_5 + V_43 ) ;
if ( ! F_16 ( & V_2 -> V_17 , V_32 ) ||
! F_16 ( & V_2 -> V_23 , V_32 ) ) {
F_17 ( & V_29 -> V_44 , L_2 ) ;
break;
}
while ( ! ( ( F_2 ( V_2 -> V_5 + V_81 )
& V_82 ) ) && V_2 -> V_7 )
V_2 -> V_83 ( V_2 ) ;
F_4 ( 0 , V_2 -> V_5 + V_49 ) ;
F_4 ( 0 , V_2 -> V_5 + V_50 ) ;
} while ( V_2 -> V_10 != 0 || V_2 -> V_7 != 0 );
}
static int F_27 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_29 -> V_35 ) ;
V_2 -> V_8 = V_31 -> V_59 ? V_31 -> V_59 : V_2 -> V_84 ;
V_2 -> V_4 = V_31 -> V_60 ? V_31 -> V_60 : V_2 -> V_84 ;
V_2 -> V_10 = V_2 -> V_7 = V_31 -> V_33 / V_2 -> V_36 ;
F_28 ( & V_2 -> V_23 ) ;
F_28 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_15 )
F_13 ( V_29 , V_31 ) ;
else if ( F_29 ( V_31 ) )
F_18 ( V_29 , V_31 ) ;
else
F_25 ( V_29 , V_31 ) ;
return V_31 -> V_33 - V_2 -> V_7 * V_2 -> V_36 ;
}
static void F_30 ( struct V_28 * V_29 , int V_85 )
{
struct V_1 * V_2 = F_14 ( V_29 -> V_35 ) ;
if ( V_2 -> V_86 [ V_29 -> V_87 ] == 0 ) {
T_1 V_88 = F_2 ( V_2 -> V_5 + V_53 ) ;
switch ( V_85 ) {
case V_89 :
if ( V_29 -> V_37 & V_90 )
V_88 |= V_91 ;
else
V_88 &= ~ V_91 ;
break;
case V_92 :
if ( V_29 -> V_37 & V_90 )
V_88 &= ~ V_91 ;
else
V_88 |= V_91 ;
break;
}
F_4 ( V_88 , V_2 -> V_5 + V_53 ) ;
} else {
int V_93 = V_2 -> V_86 [ V_29 -> V_87 ] ;
switch ( V_85 ) {
case V_89 :
F_31 ( V_93 ,
V_29 -> V_37 & V_90 ? 1 : 0 ) ;
break;
case V_92 :
F_31 ( V_93 ,
V_29 -> V_37 & V_90 ? 0 : 1 ) ;
break;
}
}
}
static int
F_32 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
struct V_1 * V_2 ;
T_2 V_94 = 0 ;
int V_95 = 0 ;
T_1 V_88 ;
T_1 V_96 , V_97 ;
T_1 V_98 = V_99 / 4 ;
V_2 = F_14 ( V_29 -> V_35 ) ;
V_94 = ( V_31 ) ? V_31 -> V_94 : V_29 -> V_94 ;
V_95 = V_31 && V_31 -> V_100 ? V_31 -> V_100 : V_29 -> V_101 ;
V_88 = ( V_2 -> V_102 / ( 2 * V_95 ) ) - 1 ;
if ( V_88 > 0xFFFF || V_88 < 0 ) {
F_17 ( & V_29 -> V_44 , L_3 , V_95 ) ;
return - V_103 ;
}
switch ( V_94 ) {
case 8 :
V_88 |= V_104 ;
V_2 -> V_83 = F_1 ;
V_2 -> V_77 = F_3 ;
break;
case 12 :
case 16 :
V_88 |= ( V_94 == 12 ) ?
V_105 :
V_106 ;
V_2 -> V_83 = F_5 ;
V_2 -> V_77 = F_6 ;
break;
case 32 :
V_88 |= V_107 ;
V_2 -> V_83 = F_7 ;
V_2 -> V_77 = F_8 ;
break;
default:
F_33 () ;
}
V_2 -> V_36 = F_34 ( V_94 , 8 ) ;
V_96 = F_35 ( V_99 / 2 ) |
V_2 -> V_36 ;
V_97 = F_35 ( V_99 / 2 ) |
V_2 -> V_36 ;
if ( ! ( V_29 -> V_37 & V_90 ) )
V_88 |= V_108 ;
if ( ! ( V_29 -> V_37 & V_38 ) )
V_88 |= V_109 ;
if ( V_29 -> V_37 & V_110 )
V_88 |= V_111 ;
if ( ( ( V_29 -> V_37 & V_110 ) && ( V_29 -> V_37 & V_112 ) ) ||
( ! ( V_29 -> V_37 & V_110 ) && ! ( V_29 -> V_37 & V_112 ) ) )
V_88 &= ~ V_113 ;
else
V_88 |= V_113 ;
F_4 ( F_36 ( V_98 - 2 ) |
F_37 ( V_98 / 2 ) |
F_38 ( 2 ) ,
V_2 -> V_5 + V_114 ) ;
F_4 ( F_36 ( 2 ) |
F_37 ( V_98 / 2 ) |
F_38 ( V_98 - 2 ) ,
V_2 -> V_5 + V_115 ) ;
F_4 ( V_96 , V_2 -> V_5 + V_116 ) ;
F_4 ( V_97 , V_2 -> V_5 + V_117 ) ;
if ( V_31 && V_31 -> V_59 && ! V_31 -> V_60 && ( V_31 -> V_33 <= V_39 ) ) {
V_88 |= ( F_39 ( ( V_31 -> V_33 - 1 ) ) |
V_118 ) ;
V_2 -> V_15 = true ;
} else {
V_88 &= ~ V_118 ;
V_2 -> V_15 = false ;
}
V_88 |= V_119 ;
F_4 ( V_88 , V_2 -> V_5 + V_53 ) ;
if ( F_29 ( V_31 ) ) {
F_4 ( 0 , V_2 -> V_5 + V_120 ) ;
F_4 ( V_121 ,
V_2 -> V_5 + V_122 ) ;
} else {
F_4 ( V_123 ,
V_2 -> V_5 + V_120 ) ;
F_4 ( V_123 ,
V_2 -> V_5 + V_122 ) ;
}
return 0 ;
}
static int F_40 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_101 )
return - V_103 ;
return F_32 ( V_29 , NULL ) ;
}
static int F_41 ( struct V_124 * V_125 )
{
struct V_1 * V_2 ;
struct V_126 * V_35 ;
struct V_127 * V_128 ;
int V_129 , V_130 , V_11 ;
int V_131 ;
int V_132 ;
V_132 = F_42 ( V_125 -> V_44 . V_133 ,
L_4 , & V_129 ) ;
if ( V_132 < 0 ) {
F_17 ( & V_125 -> V_44 , L_5 ) ;
goto V_134;
}
V_35 = F_43 ( & V_125 -> V_44 ,
sizeof( * V_2 ) + sizeof( int ) * V_129 ) ;
if ( ! V_35 ) {
F_17 ( & V_125 -> V_44 , L_6 ) ;
return - V_135 ;
}
F_44 ( V_125 , V_35 ) ;
V_2 = F_14 ( V_35 ) ;
V_35 -> V_136 = V_129 ;
for ( V_131 = 0 ; V_131 < V_35 -> V_136 ; V_131 ++ ) {
V_130 = F_45 ( V_125 -> V_44 . V_133 , L_7 , V_131 ) ;
if ( V_130 < 0 ) {
F_17 ( & V_125 -> V_44 , L_8 ) ;
V_132 = - V_137 ;
goto V_138;
}
V_2 -> V_86 [ V_131 ] = V_130 ;
if ( V_130 == 0 )
continue;
V_132 = F_46 ( V_130 , V_139 ) ;
if ( V_132 ) {
while ( V_131 > 0 ) {
V_131 -- ;
if ( V_2 -> V_86 [ V_131 ] > 0 )
F_47 ( V_2 -> V_86 [ V_131 ] ) ;
}
F_17 ( & V_125 -> V_44 , L_9 ) ;
goto V_138;
}
}
V_128 = F_48 ( V_125 , V_140 , 0 ) ;
V_2 -> V_5 = F_49 ( & V_125 -> V_44 , V_128 ) ;
if ( F_50 ( V_2 -> V_5 ) ) {
V_132 = F_51 ( V_2 -> V_5 ) ;
goto V_138;
}
V_11 = F_52 ( V_125 , 0 ) ;
if ( V_11 < 0 ) {
V_132 = - V_141 ;
goto V_138;
}
V_132 = F_53 ( & V_125 -> V_44 , V_11 , F_9 , 0 ,
V_139 , V_2 ) ;
if ( V_132 )
goto V_138;
V_2 -> V_142 . V_35 = V_35 ;
V_2 -> V_142 . V_86 = F_30 ;
V_2 -> V_142 . V_143 = F_32 ;
V_2 -> V_142 . V_144 = F_27 ;
V_2 -> V_142 . V_35 -> V_145 = F_40 ;
V_35 -> V_146 = V_125 -> V_147 ;
V_35 -> V_148 = V_110 | V_112 | V_38 | V_90 ;
V_35 -> V_149 = F_54 ( 8 ) | F_54 ( 12 ) |
F_54 ( 16 ) | F_54 ( 32 ) ;
V_2 -> V_142 . V_35 -> V_44 . V_133 = V_125 -> V_44 . V_133 ;
V_2 -> V_63 = F_55 ( & V_125 -> V_44 , L_10 ) ;
if ( ! V_2 -> V_63 ) {
F_17 ( & V_125 -> V_44 , L_11 ) ;
V_132 = - V_137 ;
goto V_138;
}
V_2 -> V_71 = F_55 ( & V_125 -> V_44 , L_12 ) ;
if ( ! V_2 -> V_71 ) {
F_17 ( & V_125 -> V_44 , L_13 ) ;
V_132 = - V_137 ;
goto V_150;
}
V_2 -> V_151 = F_56 ( & V_125 -> V_44 , NULL ) ;
if ( F_50 ( V_2 -> V_151 ) ) {
V_132 = F_51 ( V_2 -> V_151 ) ;
goto V_152;
}
F_57 ( V_2 -> V_151 ) ;
V_2 -> V_102 = F_58 ( V_2 -> V_151 ) ;
F_59 ( & V_2 -> V_23 ) ;
F_59 ( & V_2 -> V_17 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_49 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_50 ) ;
F_4 ( V_51 , V_2 -> V_5 + V_49 ) ;
F_4 ( V_51 , V_2 -> V_5 + V_50 ) ;
F_4 ( 0 , V_2 -> V_5 + V_153 ) ;
V_2 -> V_84 = F_60 ( 2 * V_154 , V_155 ) ;
if ( ! V_2 -> V_84 ) {
V_132 = - V_135 ;
goto V_156;
}
V_132 = F_61 ( & V_2 -> V_142 ) ;
if ( V_132 )
goto V_157;
F_62 ( & V_125 -> V_44 , L_14 , V_35 -> V_146 ) ;
return 0 ;
V_157:
F_63 ( V_2 -> V_84 ) ;
V_156:
F_64 ( V_2 -> V_151 ) ;
F_65 ( V_2 -> V_151 ) ;
V_152:
F_66 ( V_2 -> V_71 ) ;
V_150:
F_66 ( V_2 -> V_63 ) ;
V_138:
F_67 ( V_35 ) ;
V_134:
return V_132 ;
}
static int F_68 ( struct V_124 * V_125 )
{
struct V_126 * V_35 ;
struct V_1 * V_2 ;
int V_131 ;
V_35 = F_69 ( V_125 ) ;
V_2 = F_14 ( V_35 ) ;
F_70 ( & V_2 -> V_142 ) ;
for ( V_131 = 0 ; V_131 < V_35 -> V_136 ; V_131 ++ ) {
if ( V_2 -> V_86 [ V_131 ] > 0 )
F_47 ( V_2 -> V_86 [ V_131 ] ) ;
}
F_63 ( V_2 -> V_84 ) ;
F_64 ( V_2 -> V_151 ) ;
F_65 ( V_2 -> V_151 ) ;
F_66 ( V_2 -> V_63 ) ;
F_66 ( V_2 -> V_71 ) ;
F_67 ( V_35 ) ;
return 0 ;
}
static int F_71 ( struct V_158 * V_44 )
{
struct V_126 * V_35 = F_72 ( V_44 ) ;
struct V_1 * V_2 = F_14 ( V_35 ) ;
int V_132 ;
V_132 = F_73 ( V_35 ) ;
if ( V_132 )
return V_132 ;
F_74 ( V_2 -> V_151 ) ;
return 0 ;
}
static int F_75 ( struct V_158 * V_44 )
{
struct V_126 * V_35 = F_72 ( V_44 ) ;
struct V_1 * V_2 = F_14 ( V_35 ) ;
F_76 ( V_2 -> V_151 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_49 ) ;
F_4 ( V_48 , V_2 -> V_5 + V_50 ) ;
F_4 ( V_51 , V_2 -> V_5 + V_49 ) ;
F_4 ( V_51 , V_2 -> V_5 + V_50 ) ;
return F_77 ( V_35 ) ;
}
