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
F_3 ( V_2 -> V_35 -> V_36 & V_37 ,
V_38 ) ;
if ( ! V_2 -> V_31 &&
( ( V_2 -> V_35 -> V_49 & V_50 ) != V_50 ) &&
( V_2 -> V_23 <= V_8 ) )
F_1 ( V_2 ) ;
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
V_73 = F_15 ( V_2 -> V_67 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( F_2 ( V_29 ) & V_75 ) {
V_73 = - V_70 ;
goto V_76;
}
V_15 = ! ! ( V_2 -> V_24 & V_25 ) ;
if ( V_72 > 1 ) {
for ( V_74 = 0 ; ( V_74 < V_72 - 1 && V_15 ) ; V_74 ++ ) {
if ( V_71 [ V_74 ] . V_49 & V_65 ) {
F_16 ( V_55 -> V_67 . V_68 ,
L_2 ) ;
V_73 = - V_77 ;
goto V_76;
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
goto V_76;
if ( V_2 -> V_41 ) {
F_9 ( V_55 ) ;
if ( V_2 -> V_41 & V_20 ) {
V_73 = - V_78 ;
goto V_76;
}
V_73 = - V_79 ;
goto V_76;
}
}
V_73 = V_72 ;
V_76:
F_17 ( V_2 -> V_67 ) ;
F_18 ( V_2 -> V_67 ) ;
return V_73 ;
}
static T_1 F_19 ( struct V_54 * V_55 )
{
return V_80 | V_81 |
( V_82 & ~ V_83 ) |
V_84 ;
}
static int F_20 ( unsigned long * V_85 , unsigned long V_86 ,
unsigned int * V_87 , unsigned int * V_88 )
{
unsigned long V_89 = * V_85 , V_90 = * V_85 , V_91 , V_92 ;
unsigned int V_93 , V_94 , V_95 = 0 , V_96 = 0 ;
unsigned int V_97 , V_98 ;
V_92 = V_86 / ( 22 * V_89 ) ;
if ( ! V_92 || ( V_92 > ( V_99 * V_100 ) ) )
return - V_101 ;
V_97 = - 1 ;
for ( V_93 = 0 ; V_93 < V_99 ; V_93 ++ ) {
V_94 = F_21 ( V_86 , 22 * V_89 * ( V_93 + 1 ) ) ;
if ( ( V_94 < 1 ) || ( V_94 > V_100 ) )
continue;
V_94 -- ;
V_91 = V_86 / ( 22 * ( V_93 + 1 ) * ( V_94 + 1 ) ) ;
if ( V_91 > V_89 )
continue;
V_98 = ( ( V_91 > V_89 ) ? ( V_91 - V_89 ) :
( V_89 - V_91 ) ) ;
if ( V_97 > V_98 ) {
V_95 = V_93 ;
V_96 = V_94 ;
V_90 = V_91 ;
V_97 = V_98 ;
}
}
* V_87 = V_95 ;
* V_88 = V_96 ;
* V_85 = V_90 ;
return 0 ;
}
static int F_22 ( unsigned long V_102 , struct V_1 * V_2 )
{
unsigned int V_93 , V_94 ;
unsigned int V_44 ;
int V_73 = 0 ;
unsigned long V_89 = V_2 -> V_103 ;
V_73 = F_20 ( & V_89 , V_102 , & V_93 , & V_94 ) ;
if ( V_73 )
return V_73 ;
V_44 = F_2 ( V_4 ) ;
V_44 &= ~ ( V_104 | V_105 ) ;
V_44 |= ( ( V_93 << V_106 ) |
( V_94 << V_107 ) ) ;
F_3 ( V_44 , V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_108 * V_109 , unsigned long
V_110 , void * V_111 )
{
struct V_112 * V_113 = V_111 ;
struct V_1 * V_2 = F_24 ( V_109 ) ;
if ( F_25 ( V_2 -> V_67 ) )
return V_114 ;
switch ( V_110 ) {
case V_115 :
{
unsigned long V_86 = V_113 -> V_116 ;
unsigned long V_89 = V_2 -> V_103 ;
unsigned int V_93 , V_94 ;
int V_73 ;
V_73 = F_20 ( & V_89 , V_86 , & V_93 , & V_94 ) ;
if ( V_73 ) {
F_16 ( V_2 -> V_55 . V_67 . V_68 ,
L_3 ) ;
return V_117 ;
}
if ( V_113 -> V_116 > V_113 -> V_118 )
F_22 ( V_113 -> V_116 , V_2 ) ;
return V_114 ;
}
case V_119 :
V_2 -> V_86 = V_113 -> V_116 ;
if ( V_113 -> V_116 < V_113 -> V_118 )
F_22 ( V_113 -> V_116 , V_2 ) ;
return V_114 ;
case V_120 :
if ( V_113 -> V_116 > V_113 -> V_118 )
F_22 ( V_113 -> V_118 , V_2 ) ;
return V_114 ;
default:
return V_121 ;
}
}
static int T_3 F_26 ( struct V_122 * V_67 )
{
struct V_123 * V_124 = F_27 ( V_67 ) ;
struct V_1 * V_125 = F_28 ( V_124 ) ;
F_29 ( V_125 -> V_126 ) ;
return 0 ;
}
static int T_3 F_30 ( struct V_122 * V_67 )
{
struct V_123 * V_124 = F_27 ( V_67 ) ;
struct V_1 * V_125 = F_28 ( V_124 ) ;
int V_73 ;
V_73 = F_31 ( V_125 -> V_126 ) ;
if ( V_73 ) {
F_13 ( V_67 , L_4 ) ;
return V_73 ;
}
return 0 ;
}
static int F_32 ( struct V_123 * V_124 )
{
struct V_127 * V_128 ;
struct V_1 * V_2 ;
int V_73 ;
const struct V_129 * V_130 ;
V_2 = F_33 ( & V_124 -> V_67 , sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 )
return - V_132 ;
V_2 -> V_67 = & V_124 -> V_67 ;
F_34 ( V_124 , V_2 ) ;
V_130 = F_35 ( V_133 , V_124 -> V_67 . V_134 ) ;
if ( V_130 && V_130 -> V_111 ) {
const struct V_135 * V_111 = V_130 -> V_111 ;
V_2 -> V_24 = V_111 -> V_24 ;
}
V_128 = F_36 ( V_124 , V_136 , 0 ) ;
V_2 -> V_137 = F_37 ( & V_124 -> V_67 , V_128 ) ;
if ( F_38 ( V_2 -> V_137 ) )
return F_39 ( V_2 -> V_137 ) ;
V_2 -> V_9 = F_40 ( V_124 , 0 ) ;
V_2 -> V_55 . V_138 = V_139 ;
V_2 -> V_55 . V_67 . V_134 = V_124 -> V_67 . V_134 ;
V_2 -> V_55 . V_140 = & V_141 ;
V_2 -> V_55 . V_66 = V_142 ;
V_2 -> V_55 . V_143 = 3 ;
V_2 -> V_55 . V_56 = V_2 ;
V_2 -> V_55 . V_67 . V_68 = & V_124 -> V_67 ;
F_41 ( & V_2 -> V_43 ) ;
snprintf ( V_2 -> V_55 . V_144 , sizeof( V_2 -> V_55 . V_144 ) ,
L_5 , ( unsigned long ) V_128 -> V_145 ) ;
V_2 -> V_126 = F_42 ( & V_124 -> V_67 , NULL ) ;
if ( F_38 ( V_2 -> V_126 ) ) {
F_13 ( & V_124 -> V_67 , L_6 ) ;
return F_39 ( V_2 -> V_126 ) ;
}
V_73 = F_43 ( V_2 -> V_126 ) ;
if ( V_73 )
F_13 ( & V_124 -> V_67 , L_7 ) ;
F_44 ( V_2 -> V_67 ) ;
F_45 ( V_2 -> V_67 , V_146 ) ;
F_46 ( V_2 -> V_67 ) ;
F_47 ( V_2 -> V_67 ) ;
V_2 -> V_147 . V_148 = F_23 ;
if ( F_48 ( V_2 -> V_126 , & V_2 -> V_147 ) )
F_16 ( & V_124 -> V_67 , L_8 ) ;
V_2 -> V_86 = F_49 ( V_2 -> V_126 ) ;
V_73 = F_50 ( V_124 -> V_67 . V_134 , L_9 ,
& V_2 -> V_103 ) ;
if ( V_73 || ( V_2 -> V_103 > V_149 ) )
V_2 -> V_103 = V_150 ;
F_3 ( V_151 | V_64 | V_152 ,
V_4 ) ;
V_73 = F_22 ( V_2 -> V_86 , V_2 ) ;
if ( V_73 ) {
F_13 ( & V_124 -> V_67 , L_10 , V_2 -> V_103 ) ;
V_73 = - V_101 ;
goto V_153;
}
V_73 = F_51 ( & V_124 -> V_67 , V_2 -> V_9 , F_5 , 0 ,
V_154 , V_2 ) ;
if ( V_73 ) {
F_13 ( & V_124 -> V_67 , L_11 , V_2 -> V_9 ) ;
goto V_153;
}
F_3 ( V_155 , V_156 ) ;
V_73 = F_52 ( & V_2 -> V_55 ) ;
if ( V_73 < 0 )
goto V_153;
F_53 ( & V_124 -> V_67 , L_12 ,
V_2 -> V_103 / 1000 , ( unsigned long ) V_128 -> V_145 , V_2 -> V_9 ) ;
return 0 ;
V_153:
F_54 ( V_2 -> V_126 ) ;
F_55 ( & V_124 -> V_67 ) ;
F_56 ( & V_124 -> V_67 ) ;
return V_73 ;
}
static int F_57 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_28 ( V_124 ) ;
F_58 ( & V_2 -> V_55 ) ;
F_59 ( V_2 -> V_126 , & V_2 -> V_147 ) ;
F_54 ( V_2 -> V_126 ) ;
F_56 ( & V_124 -> V_67 ) ;
return 0 ;
}
