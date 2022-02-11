static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
if ( V_3 & V_5 )
F_3 ( V_3 & ~ V_5 , V_4 ) ;
}
static T_2 F_4 ( int V_6 , void * V_7 )
{
unsigned int V_8 , V_9 , V_10 ;
unsigned int V_11 ;
struct V_1 * V_2 = V_7 ;
int V_12 = 0 ;
T_2 V_13 = V_14 ;
V_8 = F_2 ( V_15 ) ;
F_3 ( V_8 , V_15 ) ;
if ( V_8 & ( V_16 | V_17 ) ) {
V_12 = 1 ;
V_13 = V_18 ;
}
V_10 = 0 ;
if ( V_2 -> V_19 > V_2 -> V_20 )
V_10 = 1 ;
if ( V_2 -> V_21 &&
( ( V_8 & V_22 ) ||
( V_8 & V_23 ) ) ) {
while ( F_2 ( V_24 ) &
V_25 ) {
if ( ( V_2 -> V_19 < V_26 ) &&
! V_2 -> V_27 )
F_1 ( V_2 ) ;
* ( V_2 -> V_21 ) ++ =
F_2 ( V_28 ) ;
V_2 -> V_19 -- ;
V_2 -> V_20 -- ;
if ( V_10 &&
( V_2 -> V_20 == V_26 + 1 ) )
break;
}
if ( V_10 &&
( V_2 -> V_20 == V_26 + 1 ) ) {
while ( F_2 ( V_29 ) !=
( V_2 -> V_20 - V_26 ) )
;
if ( ( ( int ) ( V_2 -> V_19 ) - V_26 ) >
V_30 ) {
F_3 ( V_30 ,
V_29 ) ;
V_2 -> V_20 = V_30 +
V_26 ;
} else {
F_3 ( V_2 -> V_19 -
V_26 ,
V_29 ) ;
V_2 -> V_20 = V_2 -> V_19 ;
}
}
if ( ( V_8 & V_22 ) && ! V_2 -> V_19 ) {
if ( ! V_2 -> V_27 )
F_1 ( V_2 ) ;
V_12 = 1 ;
}
V_13 = V_18 ;
}
if ( ( V_8 & V_22 ) && ! V_2 -> V_21 ) {
if ( V_2 -> V_31 ) {
V_9 = V_26 -
F_2 ( V_29 ) ;
if ( V_2 -> V_31 > V_9 )
V_11 = V_9 ;
else
V_11 = V_2 -> V_31 ;
while ( V_11 -- ) {
F_3 (
( * ( V_2 -> V_32 ) ++ ) ,
V_28 ) ;
V_2 -> V_31 -- ;
}
} else {
V_12 = 1 ;
}
if ( ! V_2 -> V_31 && ! V_2 -> V_27 )
F_1 ( V_2 ) ;
V_13 = V_18 ;
}
V_2 -> V_33 = V_8 & V_34 ;
if ( V_2 -> V_33 )
V_13 = V_18 ;
if ( V_12 )
F_5 ( & V_2 -> V_35 ) ;
return V_13 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_36 ;
unsigned int V_8 ;
V_2 -> V_21 = V_2 -> V_37 -> V_38 ;
V_2 -> V_19 = V_2 -> V_37 -> V_39 ;
V_36 = F_2 ( V_4 ) ;
V_36 |= V_40 | V_41 ;
if ( V_2 -> V_37 -> V_42 & V_43 )
V_2 -> V_19 = V_44 + 1 ;
V_2 -> V_20 = V_2 -> V_19 ;
if ( V_2 -> V_19 > V_26 )
V_36 |= V_5 ;
F_3 ( V_36 , V_4 ) ;
V_8 = F_2 ( V_15 ) ;
F_3 ( V_8 , V_15 ) ;
if ( V_2 -> V_19 > V_30 ) {
F_3 ( V_30 ,
V_29 ) ;
V_2 -> V_20 = V_30 ;
} else {
F_3 ( V_2 -> V_19 , V_29 ) ;
}
if ( ! V_2 -> V_27 &&
( ( V_2 -> V_37 -> V_42 & V_43 ) != V_43 ) &&
( V_2 -> V_19 <= V_26 ) )
F_1 ( V_2 ) ;
F_3 ( V_2 -> V_37 -> V_45 & V_46 ,
V_47 ) ;
F_3 ( V_48 , V_49 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
unsigned int V_11 ;
unsigned int V_36 ;
unsigned int V_8 ;
V_2 -> V_21 = NULL ;
V_2 -> V_32 = V_2 -> V_37 -> V_38 ;
V_2 -> V_31 = V_2 -> V_37 -> V_39 ;
V_36 = F_2 ( V_4 ) ;
V_36 &= ~ V_40 ;
V_36 |= V_41 ;
if ( V_2 -> V_31 > V_26 )
V_36 |= V_5 ;
F_3 ( V_36 , V_4 ) ;
V_8 = F_2 ( V_15 ) ;
F_3 ( V_8 , V_15 ) ;
V_9 = V_26 -
F_2 ( V_29 ) ;
if ( V_2 -> V_31 > V_9 )
V_11 = V_9 ;
else
V_11 = V_2 -> V_31 ;
while ( V_11 -- ) {
F_3 ( ( * ( V_2 -> V_32 ) ++ ) , V_28 ) ;
V_2 -> V_31 -- ;
}
if ( ! V_2 -> V_27 && ! V_2 -> V_31 )
F_1 ( V_2 ) ;
F_3 ( V_2 -> V_37 -> V_45 & V_46 ,
V_47 ) ;
F_3 ( V_48 , V_49 ) ;
}
static void F_8 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
T_1 V_53 ;
F_3 ( V_54 , V_55 ) ;
V_53 = F_2 ( V_4 ) ;
V_53 &= ~ V_5 ;
V_53 |= V_41 ;
F_3 ( V_53 , V_4 ) ;
F_3 ( 0 , V_29 ) ;
V_53 = F_2 ( V_15 ) ;
F_3 ( V_53 , V_15 ) ;
V_53 = F_2 ( V_24 ) ;
F_3 ( V_53 , V_24 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_56 * V_57 ,
struct V_50 * V_51 )
{
int V_58 ;
T_1 V_3 ;
V_2 -> V_37 = V_57 ;
V_2 -> V_33 = 0 ;
F_10 ( & V_2 -> V_35 ) ;
V_3 = F_2 ( V_4 ) ;
if ( V_57 -> V_42 & V_59 ) {
if ( V_3 & V_60 )
F_3 ( V_3 & ~ V_60 ,
V_4 ) ;
} else {
if ( ! ( V_3 & V_60 ) )
F_3 ( V_3 | V_60 ,
V_4 ) ;
}
if ( V_57 -> V_42 & V_61 )
F_6 ( V_2 ) ;
else
F_7 ( V_2 ) ;
V_58 = F_11 ( & V_2 -> V_35 , V_51 -> V_62 ) ;
if ( ! V_58 ) {
F_8 ( V_51 ) ;
F_12 ( V_2 -> V_51 . V_63 . V_64 ,
L_1 ) ;
return - V_65 ;
}
F_3 ( V_54 ,
V_55 ) ;
if ( V_2 -> V_33 & V_17 )
return - V_66 ;
return 0 ;
}
static int F_13 ( struct V_50 * V_51 , struct V_56 * V_67 ,
int V_68 )
{
int V_58 , V_69 ;
T_1 V_3 ;
struct V_1 * V_2 = V_51 -> V_52 ;
if ( F_2 ( V_24 ) & V_70 )
return - V_66 ;
if ( V_68 > 1 ) {
for ( V_69 = 0 ; V_69 < V_68 - 1 ; V_69 ++ ) {
if ( V_67 [ V_69 ] . V_42 & V_61 ) {
F_14 ( V_51 -> V_63 . V_64 ,
L_2 ) ;
return - V_71 ;
}
}
V_2 -> V_27 = 1 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_4 ) ;
} else {
V_2 -> V_27 = 0 ;
}
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ , V_67 ++ ) {
if ( V_69 == ( V_68 - 1 ) )
V_2 -> V_27 = 0 ;
V_58 = F_9 ( V_2 , V_67 , V_51 ) ;
if ( V_58 )
return V_58 ;
if ( V_2 -> V_33 ) {
F_8 ( V_51 ) ;
if ( V_2 -> V_33 & V_16 )
return - V_72 ;
return - V_73 ;
}
}
return V_68 ;
}
static T_1 F_15 ( struct V_50 * V_51 )
{
return V_74 | V_75 |
( V_76 & ~ V_77 ) |
V_78 ;
}
static int F_16 ( unsigned long * V_79 , unsigned long V_80 ,
unsigned int * V_81 , unsigned int * V_82 )
{
unsigned long V_83 = * V_79 , V_84 = * V_79 , V_85 , V_86 ;
unsigned int V_87 , V_88 , V_89 = 0 , V_90 = 0 ;
unsigned int V_91 , V_92 ;
V_86 = V_80 / ( 22 * V_83 ) ;
if ( ! V_86 || ( V_86 > ( V_93 * V_94 ) ) )
return - V_95 ;
V_91 = - 1 ;
for ( V_87 = 0 ; V_87 < V_93 ; V_87 ++ ) {
V_88 = F_17 ( V_80 , 22 * V_83 * ( V_87 + 1 ) ) ;
if ( ( V_88 < 1 ) || ( V_88 > V_94 ) )
continue;
V_88 -- ;
V_85 = V_80 / ( 22 * ( V_87 + 1 ) * ( V_88 + 1 ) ) ;
if ( V_85 > V_83 )
continue;
V_92 = ( ( V_85 > V_83 ) ? ( V_85 - V_83 ) :
( V_83 - V_85 ) ) ;
if ( V_91 > V_92 ) {
V_89 = V_87 ;
V_90 = V_88 ;
V_84 = V_85 ;
V_91 = V_92 ;
}
}
* V_81 = V_89 ;
* V_82 = V_90 ;
* V_79 = V_84 ;
return 0 ;
}
static int F_18 ( unsigned long V_96 , struct V_1 * V_2 )
{
unsigned int V_87 , V_88 ;
unsigned int V_36 ;
int V_58 = 0 ;
unsigned long V_83 = V_2 -> V_97 ;
V_58 = F_16 ( & V_83 , V_96 , & V_87 , & V_88 ) ;
if ( V_58 )
return V_58 ;
V_36 = F_2 ( V_4 ) ;
V_36 &= ~ ( V_98 | V_99 ) ;
V_36 |= ( ( V_87 << V_100 ) |
( V_88 << V_101 ) ) ;
F_3 ( V_36 , V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_102 * V_103 , unsigned long
V_104 , void * V_105 )
{
struct V_106 * V_107 = V_105 ;
struct V_1 * V_2 = F_20 ( V_103 ) ;
if ( V_2 -> V_108 )
return V_109 ;
switch ( V_104 ) {
case V_110 :
{
unsigned long V_80 = V_107 -> V_111 ;
unsigned long V_83 = V_2 -> V_97 ;
unsigned int V_87 , V_88 ;
int V_58 ;
V_58 = F_16 ( & V_83 , V_80 , & V_87 , & V_88 ) ;
if ( V_58 ) {
F_14 ( V_2 -> V_51 . V_63 . V_64 ,
L_3 ) ;
return V_112 ;
}
if ( V_107 -> V_111 > V_107 -> V_113 )
F_18 ( V_107 -> V_111 , V_2 ) ;
return V_109 ;
}
case V_114 :
V_2 -> V_80 = V_107 -> V_111 ;
if ( V_107 -> V_111 < V_107 -> V_113 )
F_18 ( V_107 -> V_111 , V_2 ) ;
return V_109 ;
case V_115 :
if ( V_107 -> V_111 > V_107 -> V_113 )
F_18 ( V_107 -> V_113 , V_2 ) ;
return V_109 ;
default:
return V_116 ;
}
}
static int T_3 F_21 ( struct V_117 * V_118 )
{
struct V_119 * V_120 = F_22 ( V_118 ,
struct V_119 , V_63 ) ;
struct V_1 * V_121 = F_23 ( V_120 ) ;
F_24 ( V_121 -> V_122 ) ;
V_121 -> V_108 = 1 ;
return 0 ;
}
static int T_3 F_25 ( struct V_117 * V_118 )
{
struct V_119 * V_120 = F_22 ( V_118 ,
struct V_119 , V_63 ) ;
struct V_1 * V_121 = F_23 ( V_120 ) ;
int V_58 ;
V_58 = F_26 ( V_121 -> V_122 ) ;
if ( V_58 ) {
F_12 ( V_118 , L_4 ) ;
return V_58 ;
}
V_121 -> V_108 = 0 ;
return 0 ;
}
static int F_27 ( struct V_119 * V_120 )
{
struct V_123 * V_124 ;
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_28 ( & V_120 -> V_63 , sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
F_29 ( V_120 , V_2 ) ;
V_124 = F_30 ( V_120 , V_127 , 0 ) ;
V_2 -> V_128 = F_31 ( & V_120 -> V_63 , V_124 ) ;
if ( F_32 ( V_2 -> V_128 ) )
return F_33 ( V_2 -> V_128 ) ;
V_2 -> V_6 = F_34 ( V_120 , 0 ) ;
V_2 -> V_51 . V_63 . V_129 = V_120 -> V_63 . V_129 ;
V_2 -> V_51 . V_130 = & V_131 ;
V_2 -> V_51 . V_62 = V_132 ;
V_2 -> V_51 . V_133 = 3 ;
V_2 -> V_51 . V_52 = V_2 ;
V_2 -> V_51 . V_63 . V_64 = & V_120 -> V_63 ;
F_35 ( & V_2 -> V_35 ) ;
snprintf ( V_2 -> V_51 . V_134 , sizeof( V_2 -> V_51 . V_134 ) ,
L_5 , ( unsigned long ) V_124 -> V_135 ) ;
V_2 -> V_122 = F_36 ( & V_120 -> V_63 , NULL ) ;
if ( F_32 ( V_2 -> V_122 ) ) {
F_12 ( & V_120 -> V_63 , L_6 ) ;
return F_33 ( V_2 -> V_122 ) ;
}
V_58 = F_37 ( V_2 -> V_122 ) ;
if ( V_58 ) {
F_12 ( & V_120 -> V_63 , L_7 ) ;
return V_58 ;
}
V_2 -> V_136 . V_137 = F_19 ;
if ( F_38 ( V_2 -> V_122 , & V_2 -> V_136 ) )
F_14 ( & V_120 -> V_63 , L_8 ) ;
V_2 -> V_80 = F_39 ( V_2 -> V_122 ) ;
V_58 = F_40 ( V_120 -> V_63 . V_129 , L_9 ,
& V_2 -> V_97 ) ;
if ( V_58 || ( V_2 -> V_97 > V_138 ) )
V_2 -> V_97 = V_139 ;
F_3 ( V_140 | V_60 | V_141 ,
V_4 ) ;
V_58 = F_18 ( V_2 -> V_80 , V_2 ) ;
if ( V_58 ) {
F_12 ( & V_120 -> V_63 , L_10 , V_2 -> V_97 ) ;
V_58 = - V_95 ;
goto V_142;
}
V_58 = F_41 ( & V_120 -> V_63 , V_2 -> V_6 , F_4 , 0 ,
V_143 , V_2 ) ;
if ( V_58 ) {
F_12 ( & V_120 -> V_63 , L_11 , V_2 -> V_6 ) ;
goto V_142;
}
V_58 = F_42 ( & V_2 -> V_51 ) ;
if ( V_58 < 0 ) {
F_12 ( & V_120 -> V_63 , L_12 , V_58 ) ;
goto V_142;
}
F_3 ( V_144 , V_145 ) ;
F_43 ( & V_120 -> V_63 , L_13 ,
V_2 -> V_97 / 1000 , ( unsigned long ) V_124 -> V_135 , V_2 -> V_6 ) ;
return 0 ;
V_142:
F_44 ( V_2 -> V_122 ) ;
return V_58 ;
}
static int F_45 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_23 ( V_120 ) ;
F_46 ( & V_2 -> V_51 ) ;
F_47 ( V_2 -> V_122 , & V_2 -> V_136 ) ;
F_44 ( V_2 -> V_122 ) ;
return 0 ;
}
