static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
if ( V_3 & V_5 )
F_3 ( V_3 & ~ V_5 , V_4 ) ;
}
static inline bool F_4 ( struct V_1 * V_2 , bool V_6 )
{
return ( V_6 &&
( V_2 -> V_7 == V_8 + 1 ) ) ;
}
static T_2 F_5 ( int V_9 , void * V_10 )
{
unsigned int V_11 , V_12 , V_13 ;
unsigned int V_14 ;
bool V_15 ;
struct V_1 * V_2 = V_10 ;
int V_16 = 0 ;
T_2 V_17 = V_18 ;
V_11 = F_2 ( V_19 ) ;
F_3 ( V_11 , V_19 ) ;
if ( V_11 & ( V_20 | V_21 ) ) {
V_16 = 1 ;
V_17 = V_22 ;
}
V_13 = 0 ;
if ( V_2 -> V_23 > V_2 -> V_7 )
V_13 = 1 ;
V_15 = ( V_2 -> V_24 & V_25 ) && V_13 ;
if ( V_2 -> V_26 &&
( ( V_11 & V_27 ) ||
( V_11 & V_28 ) ) ) {
while ( F_2 ( V_29 ) &
V_30 ) {
if ( ( V_2 -> V_23 < V_8 ) &&
! V_2 -> V_31 )
F_1 ( V_2 ) ;
* ( V_2 -> V_26 ) ++ =
F_2 ( V_32 ) ;
V_2 -> V_23 -- ;
V_2 -> V_7 -- ;
if ( F_4 ( V_2 , V_15 ) )
break;
}
if ( F_4 ( V_2 , V_15 ) ) {
while ( F_2 ( V_33 ) !=
( V_2 -> V_7 - V_8 ) )
;
if ( ( ( int ) ( V_2 -> V_23 ) - V_8 ) >
V_34 ) {
F_3 ( V_34 ,
V_33 ) ;
V_2 -> V_7 = V_34 +
V_8 ;
} else {
F_3 ( V_2 -> V_23 -
V_8 ,
V_33 ) ;
V_2 -> V_7 = V_2 -> V_23 ;
}
} else if ( V_2 -> V_23 && ! V_15 &&
! V_2 -> V_7 ) {
F_3 ( V_2 -> V_35 -> V_36 & V_37 ,
V_38 ) ;
if ( V_2 -> V_23 > V_34 ) {
F_3 ( V_34 ,
V_33 ) ;
V_2 -> V_7 = V_34 ;
} else {
F_3 ( V_2 -> V_23 ,
V_33 ) ;
V_2 -> V_7 = V_2 -> V_23 ;
}
}
if ( ( V_11 & V_27 ) && ! V_2 -> V_23 ) {
if ( ! V_2 -> V_31 )
F_1 ( V_2 ) ;
V_16 = 1 ;
}
V_17 = V_22 ;
}
if ( ( V_11 & V_27 ) && ! V_2 -> V_26 ) {
if ( V_2 -> V_39 ) {
V_12 = V_8 -
F_2 ( V_33 ) ;
if ( V_2 -> V_39 > V_12 )
V_14 = V_12 ;
else
V_14 = V_2 -> V_39 ;
while ( V_14 -- ) {
F_3 (
( * ( V_2 -> V_40 ) ++ ) ,
V_32 ) ;
V_2 -> V_39 -- ;
}
} else {
V_16 = 1 ;
}
if ( ! V_2 -> V_39 && ! V_2 -> V_31 )
F_1 ( V_2 ) ;
V_17 = V_22 ;
}
V_2 -> V_41 = V_11 & V_42 ;
if ( V_2 -> V_41 )
V_17 = V_22 ;
if ( V_16 )
F_6 ( & V_2 -> V_43 ) ;
return V_17 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_44 ;
unsigned int V_11 ;
V_2 -> V_26 = V_2 -> V_35 -> V_45 ;
V_2 -> V_23 = V_2 -> V_35 -> V_46 ;
V_44 = F_2 ( V_4 ) ;
V_44 |= V_47 | V_48 ;
if ( V_2 -> V_35 -> V_49 & V_50 )
V_2 -> V_23 = V_51 + 1 ;
V_2 -> V_7 = V_2 -> V_23 ;
if ( V_2 -> V_23 > V_8 )
V_44 |= V_5 ;
F_3 ( V_44 , V_4 ) ;
V_11 = F_2 ( V_19 ) ;
F_3 ( V_11 , V_19 ) ;
if ( V_2 -> V_23 > V_34 ) {
F_3 ( V_34 ,
V_33 ) ;
V_2 -> V_7 = V_34 ;
} else {
F_3 ( V_2 -> V_23 , V_33 ) ;
}
if ( ! V_2 -> V_31 &&
( ( V_2 -> V_35 -> V_49 & V_50 ) != V_50 ) &&
( V_2 -> V_23 <= V_8 ) )
F_1 ( V_2 ) ;
F_3 ( V_2 -> V_35 -> V_36 & V_37 ,
V_38 ) ;
F_3 ( V_52 , V_53 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
unsigned int V_14 ;
unsigned int V_44 ;
unsigned int V_11 ;
V_2 -> V_26 = NULL ;
V_2 -> V_40 = V_2 -> V_35 -> V_45 ;
V_2 -> V_39 = V_2 -> V_35 -> V_46 ;
V_44 = F_2 ( V_4 ) ;
V_44 &= ~ V_47 ;
V_44 |= V_48 ;
if ( V_2 -> V_39 > V_8 )
V_44 |= V_5 ;
F_3 ( V_44 , V_4 ) ;
V_11 = F_2 ( V_19 ) ;
F_3 ( V_11 , V_19 ) ;
V_12 = V_8 -
F_2 ( V_33 ) ;
if ( V_2 -> V_39 > V_12 )
V_14 = V_12 ;
else
V_14 = V_2 -> V_39 ;
while ( V_14 -- ) {
F_3 ( ( * ( V_2 -> V_40 ) ++ ) , V_32 ) ;
V_2 -> V_39 -- ;
}
if ( ! V_2 -> V_31 && ! V_2 -> V_39 )
F_1 ( V_2 ) ;
F_3 ( V_2 -> V_35 -> V_36 & V_37 ,
V_38 ) ;
F_3 ( V_52 , V_53 ) ;
}
static void F_9 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
T_1 V_57 ;
F_3 ( V_58 , V_59 ) ;
V_57 = F_2 ( V_4 ) ;
V_57 &= ~ V_5 ;
V_57 |= V_48 ;
F_3 ( V_57 , V_4 ) ;
F_3 ( 0 , V_33 ) ;
V_57 = F_2 ( V_19 ) ;
F_3 ( V_57 , V_19 ) ;
V_57 = F_2 ( V_29 ) ;
F_3 ( V_57 , V_29 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_60 * V_61 ,
struct V_54 * V_55 )
{
unsigned long V_62 ;
T_1 V_3 ;
V_2 -> V_35 = V_61 ;
V_2 -> V_41 = 0 ;
F_11 ( & V_2 -> V_43 ) ;
V_3 = F_2 ( V_4 ) ;
if ( V_61 -> V_49 & V_63 ) {
if ( V_3 & V_64 )
F_3 ( V_3 & ~ V_64 ,
V_4 ) ;
} else {
if ( ! ( V_3 & V_64 ) )
F_3 ( V_3 | V_64 ,
V_4 ) ;
}
if ( V_61 -> V_49 & V_65 )
F_7 ( V_2 ) ;
else
F_8 ( V_2 ) ;
V_62 = F_12 ( & V_2 -> V_43 , V_55 -> V_66 ) ;
if ( V_62 == 0 ) {
F_9 ( V_55 ) ;
F_13 ( V_2 -> V_55 . V_67 . V_68 ,
L_1 ) ;
return - V_69 ;
}
F_3 ( V_58 ,
V_59 ) ;
if ( V_2 -> V_41 & V_21 )
return - V_70 ;
return 0 ;
}
static int F_14 ( struct V_54 * V_55 , struct V_60 * V_71 ,
int V_72 )
{
int V_73 , V_74 ;
T_1 V_3 ;
struct V_1 * V_2 = V_55 -> V_56 ;
bool V_15 ;
if ( F_2 ( V_29 ) & V_75 )
return - V_70 ;
V_15 = ! ! ( V_2 -> V_24 & V_25 ) ;
if ( V_72 > 1 ) {
for ( V_74 = 0 ; ( V_74 < V_72 - 1 && V_15 ) ; V_74 ++ ) {
if ( V_71 [ V_74 ] . V_49 & V_65 ) {
F_15 ( V_55 -> V_67 . V_68 ,
L_2 ) ;
return - V_76 ;
}
}
V_2 -> V_31 = 1 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_4 ) ;
} else {
V_2 -> V_31 = 0 ;
}
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ , V_71 ++ ) {
if ( V_74 == ( V_72 - 1 ) )
V_2 -> V_31 = 0 ;
V_73 = F_10 ( V_2 , V_71 , V_55 ) ;
if ( V_73 )
return V_73 ;
if ( V_2 -> V_41 ) {
F_9 ( V_55 ) ;
if ( V_2 -> V_41 & V_20 )
return - V_77 ;
return - V_78 ;
}
}
return V_72 ;
}
static T_1 F_16 ( struct V_54 * V_55 )
{
return V_79 | V_80 |
( V_81 & ~ V_82 ) |
V_83 ;
}
static int F_17 ( unsigned long * V_84 , unsigned long V_85 ,
unsigned int * V_86 , unsigned int * V_87 )
{
unsigned long V_88 = * V_84 , V_89 = * V_84 , V_90 , V_91 ;
unsigned int V_92 , V_93 , V_94 = 0 , V_95 = 0 ;
unsigned int V_96 , V_97 ;
V_91 = V_85 / ( 22 * V_88 ) ;
if ( ! V_91 || ( V_91 > ( V_98 * V_99 ) ) )
return - V_100 ;
V_96 = - 1 ;
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
V_93 = F_18 ( V_85 , 22 * V_88 * ( V_92 + 1 ) ) ;
if ( ( V_93 < 1 ) || ( V_93 > V_99 ) )
continue;
V_93 -- ;
V_90 = V_85 / ( 22 * ( V_92 + 1 ) * ( V_93 + 1 ) ) ;
if ( V_90 > V_88 )
continue;
V_97 = ( ( V_90 > V_88 ) ? ( V_90 - V_88 ) :
( V_88 - V_90 ) ) ;
if ( V_96 > V_97 ) {
V_94 = V_92 ;
V_95 = V_93 ;
V_89 = V_90 ;
V_96 = V_97 ;
}
}
* V_86 = V_94 ;
* V_87 = V_95 ;
* V_84 = V_89 ;
return 0 ;
}
static int F_19 ( unsigned long V_101 , struct V_1 * V_2 )
{
unsigned int V_92 , V_93 ;
unsigned int V_44 ;
int V_73 = 0 ;
unsigned long V_88 = V_2 -> V_102 ;
V_73 = F_17 ( & V_88 , V_101 , & V_92 , & V_93 ) ;
if ( V_73 )
return V_73 ;
V_44 = F_2 ( V_4 ) ;
V_44 &= ~ ( V_103 | V_104 ) ;
V_44 |= ( ( V_92 << V_105 ) |
( V_93 << V_106 ) ) ;
F_3 ( V_44 , V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_107 * V_108 , unsigned long
V_109 , void * V_110 )
{
struct V_111 * V_112 = V_110 ;
struct V_1 * V_2 = F_21 ( V_108 ) ;
if ( V_2 -> V_113 )
return V_114 ;
switch ( V_109 ) {
case V_115 :
{
unsigned long V_85 = V_112 -> V_116 ;
unsigned long V_88 = V_2 -> V_102 ;
unsigned int V_92 , V_93 ;
int V_73 ;
V_73 = F_17 ( & V_88 , V_85 , & V_92 , & V_93 ) ;
if ( V_73 ) {
F_15 ( V_2 -> V_55 . V_67 . V_68 ,
L_3 ) ;
return V_117 ;
}
if ( V_112 -> V_116 > V_112 -> V_118 )
F_19 ( V_112 -> V_116 , V_2 ) ;
return V_114 ;
}
case V_119 :
V_2 -> V_85 = V_112 -> V_116 ;
if ( V_112 -> V_116 < V_112 -> V_118 )
F_19 ( V_112 -> V_116 , V_2 ) ;
return V_114 ;
case V_120 :
if ( V_112 -> V_116 > V_112 -> V_118 )
F_19 ( V_112 -> V_118 , V_2 ) ;
return V_114 ;
default:
return V_121 ;
}
}
static int T_3 F_22 ( struct V_122 * V_123 )
{
struct V_124 * V_125 = F_23 ( V_123 ,
struct V_124 , V_67 ) ;
struct V_1 * V_126 = F_24 ( V_125 ) ;
F_25 ( V_126 -> V_127 ) ;
V_126 -> V_113 = 1 ;
return 0 ;
}
static int T_3 F_26 ( struct V_122 * V_123 )
{
struct V_124 * V_125 = F_23 ( V_123 ,
struct V_124 , V_67 ) ;
struct V_1 * V_126 = F_24 ( V_125 ) ;
int V_73 ;
V_73 = F_27 ( V_126 -> V_127 ) ;
if ( V_73 ) {
F_13 ( V_123 , L_4 ) ;
return V_73 ;
}
V_126 -> V_113 = 0 ;
return 0 ;
}
static int F_28 ( struct V_124 * V_125 )
{
struct V_128 * V_129 ;
struct V_1 * V_2 ;
int V_73 ;
const struct V_130 * V_131 ;
V_2 = F_29 ( & V_125 -> V_67 , sizeof( * V_2 ) , V_132 ) ;
if ( ! V_2 )
return - V_133 ;
F_30 ( V_125 , V_2 ) ;
V_131 = F_31 ( V_134 , V_125 -> V_67 . V_135 ) ;
if ( V_131 && V_131 -> V_110 ) {
const struct V_136 * V_110 = V_131 -> V_110 ;
V_2 -> V_24 = V_110 -> V_24 ;
}
V_129 = F_32 ( V_125 , V_137 , 0 ) ;
V_2 -> V_138 = F_33 ( & V_125 -> V_67 , V_129 ) ;
if ( F_34 ( V_2 -> V_138 ) )
return F_35 ( V_2 -> V_138 ) ;
V_2 -> V_9 = F_36 ( V_125 , 0 ) ;
V_2 -> V_55 . V_139 = V_140 ;
V_2 -> V_55 . V_67 . V_135 = V_125 -> V_67 . V_135 ;
V_2 -> V_55 . V_141 = & V_142 ;
V_2 -> V_55 . V_66 = V_143 ;
V_2 -> V_55 . V_144 = 3 ;
V_2 -> V_55 . V_56 = V_2 ;
V_2 -> V_55 . V_67 . V_68 = & V_125 -> V_67 ;
F_37 ( & V_2 -> V_43 ) ;
snprintf ( V_2 -> V_55 . V_145 , sizeof( V_2 -> V_55 . V_145 ) ,
L_5 , ( unsigned long ) V_129 -> V_146 ) ;
V_2 -> V_127 = F_38 ( & V_125 -> V_67 , NULL ) ;
if ( F_34 ( V_2 -> V_127 ) ) {
F_13 ( & V_125 -> V_67 , L_6 ) ;
return F_35 ( V_2 -> V_127 ) ;
}
V_73 = F_39 ( V_2 -> V_127 ) ;
if ( V_73 ) {
F_13 ( & V_125 -> V_67 , L_7 ) ;
return V_73 ;
}
V_2 -> V_147 . V_148 = F_20 ;
if ( F_40 ( V_2 -> V_127 , & V_2 -> V_147 ) )
F_15 ( & V_125 -> V_67 , L_8 ) ;
V_2 -> V_85 = F_41 ( V_2 -> V_127 ) ;
V_73 = F_42 ( V_125 -> V_67 . V_135 , L_9 ,
& V_2 -> V_102 ) ;
if ( V_73 || ( V_2 -> V_102 > V_149 ) )
V_2 -> V_102 = V_150 ;
F_3 ( V_151 | V_64 | V_152 ,
V_4 ) ;
V_73 = F_19 ( V_2 -> V_85 , V_2 ) ;
if ( V_73 ) {
F_13 ( & V_125 -> V_67 , L_10 , V_2 -> V_102 ) ;
V_73 = - V_100 ;
goto V_153;
}
V_73 = F_43 ( & V_125 -> V_67 , V_2 -> V_9 , F_5 , 0 ,
V_154 , V_2 ) ;
if ( V_73 ) {
F_13 ( & V_125 -> V_67 , L_11 , V_2 -> V_9 ) ;
goto V_153;
}
V_73 = F_44 ( & V_2 -> V_55 ) ;
if ( V_73 < 0 ) {
F_13 ( & V_125 -> V_67 , L_12 , V_73 ) ;
goto V_153;
}
F_3 ( V_155 , V_156 ) ;
F_45 ( & V_125 -> V_67 , L_13 ,
V_2 -> V_102 / 1000 , ( unsigned long ) V_129 -> V_146 , V_2 -> V_9 ) ;
return 0 ;
V_153:
F_46 ( V_2 -> V_127 ) ;
return V_73 ;
}
static int F_47 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_24 ( V_125 ) ;
F_48 ( & V_2 -> V_55 ) ;
F_49 ( V_2 -> V_127 , & V_2 -> V_147 ) ;
F_46 ( V_2 -> V_127 ) ;
return 0 ;
}
