static inline bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
return ( V_4 & V_3 ) != 0 ;
}
static inline bool F_3 ( int V_7 )
{
if ( V_7 == V_8 || V_7 == V_9 )
return true ;
return false ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_10 * V_2 -> V_11 ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
T_1 V_12 = F_2 ( V_2 -> V_5 + V_13 ) ;
return V_12 & V_14 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_15 )
{
unsigned long V_16 ;
T_1 V_17 ;
V_16 = 0 ;
while ( ! F_5 ( V_2 ) ) {
F_7 ( V_18 , V_18 * 2 ) ;
if ( ++ V_16 > V_19 )
return - V_20 ;
}
if ( V_16 )
F_8 ( V_2 -> V_21 , L_1 ,
V_16 , V_15 ) ;
V_17 = F_2 ( V_2 -> V_5 + V_13 ) ;
if ( ( ( V_17 & V_22 ) == V_23 ) &&
( V_15 == V_24 ) ) {
F_9 ( V_25 , V_2 -> V_5 + V_13 ) ;
F_9 ( V_25 , V_2 -> V_5 + V_13 ) ;
} else {
V_17 &= ~ V_22 ;
V_17 |= V_15 ;
F_9 ( V_17 , V_2 -> V_5 + V_13 ) ;
}
V_16 = 0 ;
while ( ! F_5 ( V_2 ) ) {
F_7 ( V_18 , V_18 * 2 ) ;
if ( ++ V_16 > V_19 )
return - V_20 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_26 )
{
T_2 * V_27 = V_2 -> V_27 ;
int V_28 , V_29 , V_30 ;
T_1 V_31 ;
for (; V_26 ; V_26 -- ) {
V_31 = F_2 ( V_2 -> V_5 + V_32 ) ;
V_30 = F_11 ( int , F_4 ( V_2 ) -
V_2 -> V_33 ,
V_2 -> V_11 ) ;
if ( ! V_27 ) {
V_2 -> V_33 += V_30 ;
continue;
}
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ , V_2 -> V_33 ++ ) {
V_29 = V_34 ;
V_29 *= ( V_2 -> V_11 - V_28 - 1 ) ;
V_27 [ V_2 -> V_33 ] = V_31 >> V_29 ;
}
}
}
static void F_12 ( struct V_1 * V_2 , T_1 * V_35 )
{
T_1 V_36 , V_37 , V_26 ;
bool V_38 = V_2 -> V_7 == V_39 ;
V_36 = F_13 ( F_4 ( V_2 ) - V_2 -> V_33 ,
V_2 -> V_11 ) ;
V_37 = V_2 -> V_40 >> 2 ;
do {
F_9 ( V_41 ,
V_2 -> V_5 + V_6 ) ;
if ( V_38 ) {
V_26 = ( V_36 > V_37 ) ?
V_37 : V_36 ;
} else {
if ( ! F_1 ( V_2 ,
V_42 ) )
break;
V_26 = 1 ;
}
F_10 ( V_2 , V_26 ) ;
V_36 -= V_26 ;
if ( V_38 && ! F_1 ( V_2 ,
V_43 ) )
break;
} while ( V_36 );
* V_35 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( V_38 && * V_35 & V_44 )
F_9 ( V_41 ,
V_2 -> V_5 + V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_26 )
{
const T_2 * V_45 = V_2 -> V_45 ;
int V_28 , V_30 ;
T_1 V_31 , V_46 ;
for (; V_26 ; V_26 -- ) {
V_31 = 0 ;
V_30 = F_11 ( int , F_4 ( V_2 ) -
V_2 -> V_47 ,
V_2 -> V_11 ) ;
if ( V_45 )
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
V_46 = V_45 [ V_2 -> V_47 + V_28 ] ;
V_31 |= V_46 << ( V_34 * ( 3 - V_28 ) ) ;
}
V_2 -> V_47 += V_30 ;
F_9 ( V_31 , V_2 -> V_5 + V_48 ) ;
}
}
static void F_15 ( void * V_46 )
{
struct V_1 * V_49 = V_46 ;
F_16 ( & V_49 -> V_50 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
bool V_38 = V_2 -> V_7 == V_39 ;
T_1 V_36 , V_37 , V_26 ;
V_36 = F_13 ( F_4 ( V_2 ) - V_2 -> V_47 ,
V_2 -> V_11 ) ;
V_37 = V_2 -> V_51 >> 2 ;
do {
F_9 ( V_52 ,
V_2 -> V_5 + V_6 ) ;
if ( V_38 ) {
V_26 = ( V_36 > V_37 ) ?
V_37 : V_36 ;
} else {
if ( F_1 ( V_2 ,
V_53 ) )
break;
V_26 = 1 ;
}
F_14 ( V_2 , V_26 ) ;
V_36 -= V_26 ;
if ( V_38 && ! F_1 ( V_2 ,
V_54 ) )
break;
} while ( V_36 );
}
static int F_18 ( struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int V_59 , enum V_60 V_61 ,
T_3 V_62 )
{
struct V_1 * V_49 = F_19 ( V_56 ) ;
unsigned long V_63 = V_64 | V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
T_4 V_70 ;
if ( V_61 == V_71 )
V_69 = V_56 -> V_72 ;
else
V_69 = V_56 -> V_73 ;
V_67 = F_20 ( V_69 , V_58 , V_59 , V_61 , V_63 ) ;
if ( F_21 ( V_67 ) )
return V_67 ? F_22 ( V_67 ) : - V_74 ;
V_67 -> V_62 = V_62 ;
V_67 -> V_75 = V_49 ;
V_70 = F_23 ( V_67 ) ;
return F_24 ( V_70 ) ;
}
static void F_25 ( struct V_55 * V_56 ,
struct V_76 * V_77 )
{
if ( V_77 -> V_45 )
F_26 ( V_56 -> V_72 ) ;
if ( V_77 -> V_27 )
F_26 ( V_56 -> V_73 ) ;
}
static T_1 F_27 ( struct V_57 * V_58 , T_1 V_78 ,
T_1 * V_59 )
{
struct V_57 * V_79 ;
T_1 V_80 = 0 ;
for ( V_79 = V_58 ; V_79 ; V_79 = F_28 ( V_79 ) ) {
unsigned int V_81 = F_29 ( V_79 ) ;
if ( ( ( V_80 + V_81 ) < V_80 ) || ( ( V_80 + V_81 ) > V_78 ) )
break;
V_80 += V_81 ;
( * V_59 ) ++ ;
}
return V_80 ;
}
static int F_30 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_84 )
{
T_3 V_85 = NULL , V_86 = NULL ;
struct V_55 * V_56 = V_83 -> V_56 ;
struct V_1 * V_49 = F_19 ( V_56 ) ;
struct V_57 * V_87 , * V_88 ;
int V_89 ;
if ( V_77 -> V_27 )
V_85 = F_15 ;
else if ( V_77 -> V_45 )
V_86 = F_15 ;
V_88 = V_77 -> V_90 . V_58 ;
V_87 = V_77 -> V_91 . V_58 ;
do {
T_1 V_92 = 0 , V_93 = 0 ;
if ( V_88 )
V_49 -> V_10 = F_27 ( V_88 ,
V_94 , & V_92 ) / V_49 -> V_11 ;
if ( V_87 )
V_49 -> V_10 = F_27 ( V_87 ,
V_94 , & V_93 ) / V_49 -> V_11 ;
if ( ! V_49 -> V_10 )
return - V_20 ;
V_89 = F_31 ( V_83 , V_77 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_6 ( V_49 , V_95 ) ;
if ( V_89 ) {
F_32 ( V_49 -> V_21 , L_2 ) ;
return V_89 ;
}
if ( V_88 ) {
V_89 = F_18 ( V_56 , V_88 , V_92 ,
V_96 , V_85 ) ;
if ( V_89 )
return V_89 ;
F_33 ( V_56 -> V_73 ) ;
}
if ( V_87 ) {
V_89 = F_18 ( V_56 , V_87 , V_93 ,
V_71 , V_86 ) ;
if ( V_89 )
return V_89 ;
F_33 ( V_56 -> V_72 ) ;
}
if ( ! F_34 ( & V_49 -> V_50 , V_84 ) )
return - V_97 ;
for (; V_88 && V_92 -- ; V_88 = F_28 ( V_88 ) )
;
for (; V_87 && V_93 -- ; V_87 = F_28 ( V_87 ) )
;
} while ( V_88 || V_87 );
return 0 ;
}
static int F_35 ( struct V_82 * V_83 , struct V_76 * V_77 ,
unsigned long V_84 )
{
struct V_55 * V_56 = V_83 -> V_56 ;
struct V_1 * V_49 = F_19 ( V_56 ) ;
int V_89 , V_10 , V_98 , V_99 = 0 ;
V_10 = V_49 -> V_10 ;
V_98 = V_10 / V_94 ;
V_49 -> V_27 = V_77 -> V_27 ;
V_49 -> V_45 = V_77 -> V_45 ;
do {
if ( V_98 )
V_49 -> V_10 = V_94 ;
else
V_49 -> V_10 = V_10 % V_94 ;
if ( V_49 -> V_45 && V_99 )
V_49 -> V_45 = V_77 -> V_45 + V_99 * V_94 ;
if ( V_49 -> V_27 && V_99 )
V_49 -> V_27 = V_77 -> V_27 + V_99 * V_94 ;
if ( V_49 -> V_10 <= ( V_49 -> V_100 / sizeof( T_1 ) ) )
V_49 -> V_7 = V_101 ;
V_89 = F_31 ( V_83 , V_77 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_6 ( V_49 , V_95 ) ;
if ( V_89 ) {
F_32 ( V_49 -> V_21 , L_2 ) ;
return V_89 ;
}
V_89 = F_6 ( V_49 , V_23 ) ;
if ( V_89 ) {
F_32 ( V_49 -> V_21 , L_3 ) ;
return V_89 ;
}
if ( V_49 -> V_7 == V_101 )
F_17 ( V_49 ) ;
V_89 = F_6 ( V_49 , V_95 ) ;
if ( V_89 ) {
F_32 ( V_49 -> V_21 , L_2 ) ;
return V_89 ;
}
if ( ! F_34 ( & V_49 -> V_50 , V_84 ) )
return - V_97 ;
V_99 ++ ;
} while ( V_98 -- );
return 0 ;
}
static T_5 F_36 ( int V_102 , void * V_103 )
{
struct V_1 * V_2 = V_103 ;
T_1 V_35 , V_104 , V_105 ;
int error = 0 ;
V_104 = F_2 ( V_2 -> V_5 + V_106 ) ;
V_105 = F_2 ( V_2 -> V_5 + V_107 ) ;
V_35 = F_2 ( V_2 -> V_5 + V_6 ) ;
F_9 ( V_104 , V_2 -> V_5 + V_106 ) ;
F_9 ( V_105 , V_2 -> V_5 + V_107 ) ;
if ( V_104 ) {
if ( V_104 & V_108 )
F_32 ( V_2 -> V_21 , L_4 ) ;
if ( V_104 & V_109 )
F_32 ( V_2 -> V_21 , L_5 ) ;
if ( V_104 & V_110 )
F_32 ( V_2 -> V_21 , L_6 ) ;
if ( V_104 & V_111 )
F_32 ( V_2 -> V_21 , L_7 ) ;
error = - V_20 ;
}
if ( V_105 ) {
if ( V_105 & V_112 )
F_32 ( V_2 -> V_21 , L_8 ) ;
if ( V_105 & V_113 )
F_32 ( V_2 -> V_21 , L_9 ) ;
error = - V_20 ;
}
if ( F_3 ( V_2 -> V_7 ) ) {
F_9 ( V_35 , V_2 -> V_5 + V_6 ) ;
} else {
if ( V_35 & V_41 )
F_12 ( V_2 , & V_35 ) ;
if ( V_35 & V_52 )
F_17 ( V_2 ) ;
}
if ( ( V_35 & V_44 ) || error )
F_16 ( & V_2 -> V_50 ) ;
return V_114 ;
}
static int F_37 ( struct V_82 * V_83 , struct V_76 * V_77 )
{
struct V_1 * V_2 = F_19 ( V_83 -> V_56 ) ;
int V_89 ;
if ( V_83 -> V_7 & V_115 && V_77 -> V_81 > V_2 -> V_100 ) {
F_38 ( V_2 -> V_21 , L_10 ,
V_77 -> V_81 , V_2 -> V_100 ) ;
return - V_20 ;
}
V_89 = F_39 ( V_2 -> V_116 , V_77 -> V_117 ) ;
if ( V_89 ) {
F_38 ( V_2 -> V_21 , L_11 ,
V_77 -> V_117 ) ;
return - V_20 ;
}
V_2 -> V_11 = F_13 ( V_77 -> V_118 , 8 ) ;
V_2 -> V_10 = V_77 -> V_81 / V_2 -> V_11 ;
if ( V_2 -> V_10 <= ( V_2 -> V_100 / sizeof( T_1 ) ) )
V_2 -> V_7 = V_101 ;
else if ( V_83 -> V_56 -> V_119 &&
V_83 -> V_56 -> V_119 ( V_83 -> V_56 , V_83 , V_77 ) &&
V_83 -> V_56 -> V_120 )
V_2 -> V_7 = V_9 ;
else
V_2 -> V_7 = V_39 ;
return 0 ;
}
static int F_31 ( struct V_82 * V_83 , struct V_76 * V_77 )
{
struct V_1 * V_2 = F_19 ( V_83 -> V_56 ) ;
T_1 V_121 , V_122 , V_123 ;
unsigned long V_63 ;
F_40 ( & V_2 -> V_124 , V_63 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> error = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_47 = 0 ;
F_41 ( & V_2 -> V_124 , V_63 ) ;
if ( F_6 ( V_2 , V_24 ) ) {
F_38 ( V_2 -> V_21 , L_12 ) ;
return - V_20 ;
}
switch ( V_2 -> V_7 ) {
case V_101 :
F_9 ( V_2 -> V_10 ,
V_2 -> V_5 + V_125 ) ;
F_9 ( V_2 -> V_10 ,
V_2 -> V_5 + V_126 ) ;
F_9 ( 0 , V_2 -> V_5 + V_127 ) ;
F_9 ( 0 , V_2 -> V_5 + V_128 ) ;
break;
case V_9 :
F_9 ( V_2 -> V_10 ,
V_2 -> V_5 + V_127 ) ;
F_9 ( V_2 -> V_10 ,
V_2 -> V_5 + V_128 ) ;
F_9 ( 0 , V_2 -> V_5 + V_125 ) ;
F_9 ( 0 , V_2 -> V_5 + V_126 ) ;
if ( ! V_2 -> V_129 ) {
void T_6 * V_130 ;
V_130 = V_2 -> V_5 + V_127 ;
if ( V_77 -> V_45 )
F_9 ( 0 , V_130 ) ;
else
F_9 ( V_2 -> V_10 , V_130 ) ;
F_9 ( 0 , V_2 -> V_5 + V_128 ) ;
}
break;
case V_39 :
F_42 ( & V_2 -> V_50 ) ;
F_9 ( V_2 -> V_10 ,
V_2 -> V_5 + V_127 ) ;
F_9 ( V_2 -> V_10 ,
V_2 -> V_5 + V_128 ) ;
F_9 ( 0 , V_2 -> V_5 + V_125 ) ;
F_9 ( 0 , V_2 -> V_5 + V_126 ) ;
break;
default:
F_38 ( V_2 -> V_21 , L_13 ,
V_2 -> V_7 ) ;
return - V_20 ;
}
V_122 = F_2 ( V_2 -> V_5 + V_131 ) ;
V_122 &= ~ ( V_132 | V_133 ) ;
if ( ! F_3 ( V_2 -> V_7 ) )
V_122 &= ~ ( V_134 | V_135 ) ;
else
V_122 |= V_134 | V_135 ;
V_122 |= ( V_2 -> V_7 << V_136 ) ;
V_122 |= ( V_2 -> V_7 << V_137 ) ;
F_9 ( V_122 , V_2 -> V_5 + V_131 ) ;
V_123 = F_2 ( V_2 -> V_5 + V_138 ) ;
if ( V_83 -> V_7 & V_139 )
V_123 |= V_140 ;
else
V_123 &= ~ V_140 ;
F_9 ( V_123 , V_2 -> V_5 + V_138 ) ;
V_121 = F_2 ( V_2 -> V_5 + V_141 ) ;
if ( V_83 -> V_7 & V_115 )
V_121 |= V_142 ;
else
V_121 &= ~ V_142 ;
if ( V_83 -> V_7 & V_143 )
V_121 &= ~ V_144 ;
else
V_121 |= V_144 ;
if ( ( V_77 -> V_117 >= V_145 ) && ! ( V_83 -> V_7 & V_115 ) )
V_121 |= V_146 ;
else
V_121 &= ~ V_146 ;
F_9 ( V_121 , V_2 -> V_5 + V_141 ) ;
V_121 = F_2 ( V_2 -> V_5 + V_147 ) ;
V_121 &= ~ ( V_148 | V_149 | V_150 ) ;
V_121 |= V_77 -> V_118 - 1 ;
V_121 |= V_151 ;
if ( F_3 ( V_2 -> V_7 ) ) {
if ( ! V_77 -> V_45 )
V_121 |= V_149 ;
if ( ! V_77 -> V_27 )
V_121 |= V_148 ;
}
F_9 ( V_121 , V_2 -> V_5 + V_147 ) ;
if ( ! V_2 -> V_129 ) {
T_1 V_152 = 0 ;
if ( F_3 ( V_2 -> V_7 ) )
V_152 = V_41 | V_52 ;
F_9 ( V_152 , V_2 -> V_5 + V_153 ) ;
}
return 0 ;
}
static int F_43 ( struct V_55 * V_56 ,
struct V_82 * V_83 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_19 ( V_56 ) ;
unsigned long V_84 , V_63 ;
int V_89 = - V_20 ;
V_89 = F_37 ( V_83 , V_77 ) ;
if ( V_89 )
return V_89 ;
V_84 = F_13 ( V_77 -> V_117 , V_154 ) ;
V_84 = F_13 ( F_11 (unsigned long, SPI_MAX_XFER,
xfer->len) * 8 , V_84 ) ;
V_84 = 100 * F_44 ( V_84 ) ;
F_42 ( & V_2 -> V_50 ) ;
F_40 ( & V_2 -> V_124 , V_63 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> error = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_47 = 0 ;
F_41 ( & V_2 -> V_124 , V_63 ) ;
if ( F_3 ( V_2 -> V_7 ) )
V_89 = F_30 ( V_83 , V_77 , V_84 ) ;
else
V_89 = F_35 ( V_83 , V_77 , V_84 ) ;
if ( V_89 )
goto exit;
exit:
F_6 ( V_2 , V_24 ) ;
F_40 ( & V_2 -> V_124 , V_63 ) ;
if ( ! V_89 )
V_89 = V_2 -> error ;
F_41 ( & V_2 -> V_124 , V_63 ) ;
if ( V_89 && F_3 ( V_2 -> V_7 ) )
F_25 ( V_56 , V_77 ) ;
return V_89 ;
}
static bool F_45 ( struct V_55 * V_56 , struct V_82 * V_83 ,
struct V_76 * V_77 )
{
struct V_1 * V_49 = F_19 ( V_56 ) ;
T_7 V_155 = F_46 () ;
int V_10 ;
if ( V_77 -> V_27 ) {
if ( ! F_47 ( ( T_7 ) V_77 -> V_27 , V_155 ) ||
F_21 ( V_56 -> V_73 ) )
return false ;
if ( V_49 -> V_129 && ( V_77 -> V_81 % V_49 -> V_40 ) )
return false ;
}
if ( V_77 -> V_45 ) {
if ( ! F_47 ( ( T_7 ) V_77 -> V_45 , V_155 ) ||
F_21 ( V_56 -> V_72 ) )
return false ;
if ( V_49 -> V_129 && ( V_77 -> V_81 % V_49 -> V_51 ) )
return false ;
}
V_10 = V_77 -> V_81 / F_13 ( V_77 -> V_118 , 8 ) ;
if ( V_10 <= ( V_49 -> V_100 / sizeof( T_1 ) ) )
return false ;
return true ;
}
static void F_48 ( struct V_55 * V_56 )
{
if ( ! F_21 ( V_56 -> V_73 ) )
F_49 ( V_56 -> V_73 ) ;
if ( ! F_21 ( V_56 -> V_72 ) )
F_49 ( V_56 -> V_72 ) ;
}
static int F_50 ( struct V_55 * V_56 , T_8 V_5 )
{
struct V_1 * V_83 = F_19 ( V_56 ) ;
struct V_156 * V_157 = & V_83 -> V_157 ,
* V_158 = & V_83 -> V_158 ;
struct V_159 * V_21 = V_83 -> V_21 ;
int V_89 ;
V_56 -> V_73 = F_51 ( V_21 , L_14 ) ;
if ( F_52 ( V_56 -> V_73 ) )
return F_22 ( V_56 -> V_73 ) ;
V_56 -> V_72 = F_51 ( V_21 , L_15 ) ;
if ( F_52 ( V_56 -> V_72 ) ) {
V_89 = F_22 ( V_56 -> V_72 ) ;
goto V_160;
}
V_157 -> V_161 = V_96 ;
V_157 -> V_162 = 1 ;
V_157 -> V_163 = V_5 + V_32 ;
V_157 -> V_164 = V_83 -> V_40 ;
V_158 -> V_161 = V_71 ;
V_158 -> V_162 = 1 ;
V_158 -> V_165 = V_5 + V_48 ;
V_158 -> V_166 = V_83 -> V_51 ;
V_89 = F_53 ( V_56 -> V_73 , V_157 ) ;
if ( V_89 ) {
F_38 ( V_21 , L_16 ) ;
goto V_167;
}
V_89 = F_53 ( V_56 -> V_72 , V_158 ) ;
if ( V_89 ) {
F_38 ( V_21 , L_17 ) ;
goto V_167;
}
return 0 ;
V_167:
F_49 ( V_56 -> V_72 ) ;
V_160:
F_49 ( V_56 -> V_73 ) ;
return V_89 ;
}
static void F_54 ( struct V_82 * V_83 , bool V_168 )
{
struct V_1 * V_2 ;
T_1 V_169 ;
T_1 V_170 ;
V_2 = F_19 ( V_83 -> V_56 ) ;
V_169 = F_2 ( V_2 -> V_5 + V_138 ) ;
V_170 = V_169 ;
if ( ! V_168 )
V_169 |= V_171 ;
else
V_169 &= ~ V_171 ;
if ( V_169 != V_170 )
F_9 ( V_169 , V_2 -> V_5 + V_138 ) ;
}
static int F_55 ( struct V_172 * V_173 )
{
struct V_55 * V_56 ;
struct V_174 * V_175 , * V_116 ;
struct V_1 * V_2 ;
struct V_176 * V_177 ;
struct V_159 * V_21 ;
void T_6 * V_5 ;
T_1 V_178 , V_122 , V_179 ;
int V_89 , V_102 , V_180 ;
V_21 = & V_173 -> V_21 ;
V_177 = F_56 ( V_173 , V_181 , 0 ) ;
V_5 = F_57 ( V_21 , V_177 ) ;
if ( F_52 ( V_5 ) )
return F_22 ( V_5 ) ;
V_102 = F_58 ( V_173 , 0 ) ;
if ( V_102 < 0 )
return V_102 ;
V_116 = F_59 ( V_21 , L_18 ) ;
if ( F_52 ( V_116 ) )
return F_22 ( V_116 ) ;
V_175 = F_59 ( V_21 , L_19 ) ;
if ( F_52 ( V_175 ) )
return F_22 ( V_175 ) ;
if ( F_60 ( V_21 -> V_182 , L_20 , & V_178 ) )
V_178 = V_183 ;
if ( ! V_178 || V_178 > V_183 ) {
F_38 ( V_21 , L_21 , V_178 ) ;
return - V_184 ;
}
V_89 = F_61 ( V_116 ) ;
if ( V_89 ) {
F_38 ( V_21 , L_22 ) ;
return V_89 ;
}
V_89 = F_61 ( V_175 ) ;
if ( V_89 ) {
F_62 ( V_116 ) ;
F_38 ( V_21 , L_23 ) ;
return V_89 ;
}
V_56 = F_63 ( V_21 , sizeof( struct V_1 ) ) ;
if ( ! V_56 ) {
F_62 ( V_116 ) ;
F_62 ( V_175 ) ;
F_38 ( V_21 , L_24 ) ;
return - V_185 ;
}
if ( F_60 ( V_21 -> V_182 , L_25 , & V_179 ) ||
V_179 > V_186 )
V_56 -> V_187 = V_186 ;
else
V_56 -> V_187 = V_179 ;
V_56 -> V_188 = V_173 -> V_189 ;
V_56 -> V_190 = V_139 | V_143 | V_191 | V_115 ;
V_56 -> V_192 = F_64 ( 4 , 32 ) ;
V_56 -> V_193 = V_178 ;
V_56 -> V_194 = F_43 ;
V_56 -> V_21 . V_182 = V_173 -> V_21 . V_182 ;
V_56 -> V_195 = true ;
V_56 -> V_196 = F_46 () ;
V_56 -> V_197 = V_94 ;
F_65 ( V_173 , V_56 ) ;
V_2 = F_19 ( V_56 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_175 = V_175 ;
V_2 -> V_116 = V_116 ;
V_2 -> V_102 = V_102 ;
V_89 = F_50 ( V_56 , V_177 -> V_198 ) ;
if ( V_89 == - V_199 )
goto error;
else if ( ! V_89 )
V_56 -> V_119 = F_45 ;
V_2 -> V_129 = ( V_200 ) F_66 ( V_21 ) ;
if ( ! V_2 -> V_129 )
V_56 -> V_201 = F_54 ;
F_67 ( & V_2 -> V_124 ) ;
F_68 ( & V_2 -> V_50 ) ;
V_122 = F_2 ( V_5 + V_131 ) ;
V_180 = F_69 ( V_122 ) ;
if ( V_180 )
V_2 -> V_51 = V_180 * 16 ;
else
V_2 -> V_51 = 4 ;
V_180 = F_70 ( V_122 ) ;
if ( V_180 )
V_2 -> V_40 = V_180 * 16 ;
else
V_2 -> V_40 = 4 ;
V_180 = F_71 ( V_122 ) ;
V_2 -> V_202 = V_2 -> V_51 * ( 2 << V_180 ) ;
V_180 = F_72 ( V_122 ) ;
V_2 -> V_100 = V_2 -> V_40 * ( 2 << V_180 ) ;
F_73 ( V_21 , L_26 ,
V_2 -> V_40 , V_2 -> V_100 ,
V_2 -> V_51 , V_2 -> V_202 ) ;
F_9 ( 1 , V_5 + V_203 ) ;
V_89 = F_6 ( V_2 , V_24 ) ;
if ( V_89 ) {
F_38 ( V_21 , L_12 ) ;
goto V_204;
}
F_9 ( 0 , V_5 + V_6 ) ;
F_9 ( 0 , V_5 + V_131 ) ;
if ( ! V_2 -> V_129 )
F_9 ( 0 , V_5 + V_153 ) ;
F_9 ( V_113 | V_112 ,
V_5 + V_205 ) ;
if ( V_2 -> V_129 )
F_9 ( V_108 |
V_109 | V_110 ,
V_5 + V_206 ) ;
F_9 ( 0 , V_5 + V_141 ) ;
F_9 ( V_207 , V_5 + V_138 ) ;
V_89 = F_74 ( V_21 , V_102 , F_36 ,
V_208 , V_173 -> V_209 , V_2 ) ;
if ( V_89 )
goto V_204;
F_75 ( V_21 , V_154 ) ;
F_76 ( V_21 ) ;
F_77 ( V_21 ) ;
F_78 ( V_21 ) ;
V_89 = F_79 ( V_21 , V_56 ) ;
if ( V_89 )
goto V_210;
return 0 ;
V_210:
F_80 ( & V_173 -> V_21 ) ;
V_204:
F_48 ( V_56 ) ;
error:
F_62 ( V_116 ) ;
F_62 ( V_175 ) ;
F_81 ( V_56 ) ;
return V_89 ;
}
static int F_82 ( struct V_159 * V_159 )
{
struct V_55 * V_56 = F_83 ( V_159 ) ;
struct V_1 * V_2 = F_19 ( V_56 ) ;
T_1 V_121 ;
V_121 = F_84 ( V_2 -> V_5 + V_147 ) ;
V_121 |= V_211 ;
F_9 ( V_121 , V_2 -> V_5 + V_147 ) ;
F_62 ( V_2 -> V_116 ) ;
F_62 ( V_2 -> V_175 ) ;
return 0 ;
}
static int F_85 ( struct V_159 * V_159 )
{
struct V_55 * V_56 = F_83 ( V_159 ) ;
struct V_1 * V_2 = F_19 ( V_56 ) ;
T_1 V_121 ;
int V_89 ;
V_89 = F_61 ( V_2 -> V_175 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_61 ( V_2 -> V_116 ) ;
if ( V_89 )
return V_89 ;
V_121 = F_2 ( V_2 -> V_5 + V_147 ) ;
V_121 &= ~ V_211 ;
F_9 ( V_121 , V_2 -> V_5 + V_147 ) ;
return 0 ;
}
static int F_86 ( struct V_159 * V_159 )
{
struct V_55 * V_56 = F_83 ( V_159 ) ;
struct V_1 * V_2 = F_19 ( V_56 ) ;
int V_89 ;
V_89 = F_87 ( V_56 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_6 ( V_2 , V_24 ) ;
if ( V_89 )
return V_89 ;
if ( ! F_88 ( V_159 ) ) {
F_62 ( V_2 -> V_116 ) ;
F_62 ( V_2 -> V_175 ) ;
}
return 0 ;
}
static int F_89 ( struct V_159 * V_159 )
{
struct V_55 * V_56 = F_83 ( V_159 ) ;
struct V_1 * V_2 = F_19 ( V_56 ) ;
int V_89 ;
V_89 = F_61 ( V_2 -> V_175 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_61 ( V_2 -> V_116 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_6 ( V_2 , V_24 ) ;
if ( V_89 )
return V_89 ;
return F_90 ( V_56 ) ;
}
static int F_91 ( struct V_172 * V_173 )
{
struct V_55 * V_56 = F_83 ( & V_173 -> V_21 ) ;
struct V_1 * V_2 = F_19 ( V_56 ) ;
int V_89 ;
V_89 = F_92 ( & V_173 -> V_21 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_6 ( V_2 , V_24 ) ;
if ( V_89 )
return V_89 ;
F_48 ( V_56 ) ;
F_62 ( V_2 -> V_116 ) ;
F_62 ( V_2 -> V_175 ) ;
F_93 ( & V_173 -> V_21 ) ;
F_80 ( & V_173 -> V_21 ) ;
return 0 ;
}
