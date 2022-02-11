static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_4 ) ;
if ( V_3 & V_5 )
F_3 ( V_3 & ~ V_5 , V_4 ) ;
}
static T_2 F_4 ( int V_6 , void * V_7 )
{
unsigned int V_8 , V_9 ;
unsigned int V_10 , V_11 ;
struct V_1 * V_2 = V_7 ;
int V_12 = 0 ;
T_2 V_13 = V_14 ;
V_8 = F_2 ( V_15 ) ;
if ( V_8 & ( V_16 | V_17 ) ) {
V_12 = 1 ;
V_13 = V_18 ;
}
if ( ( V_8 & V_19 ) &&
( V_2 -> V_20 >= V_21 ) ) {
V_10 = V_21 ;
V_2 -> V_20 -= V_21 ;
V_9 = F_2 ( V_22 ) ;
if ( ! V_9 ) {
if ( V_2 -> V_20 > V_23 )
F_3 ( V_23 ,
V_22 ) ;
else
F_3 ( V_2 -> V_20 ,
V_22 ) ;
}
while ( V_10 -- )
* ( V_2 -> V_24 ) ++ =
F_2 ( V_25 ) ;
if ( ! V_2 -> V_26 &&
( V_2 -> V_20 <= V_27 ) )
F_1 ( V_2 ) ;
V_13 = V_18 ;
}
if ( V_8 & V_28 ) {
if ( ! V_2 -> V_24 ) {
if ( V_2 -> V_29 ) {
V_9 = V_27 -
F_2 ( V_22 ) ;
if ( V_2 -> V_29 > V_9 )
V_11 = V_9 ;
else
V_11 = V_2 -> V_29 ;
while ( V_11 -- ) {
F_3 (
( * ( V_2 -> V_30 ) ++ ) ,
V_25 ) ;
V_2 -> V_29 -- ;
}
} else {
V_12 = 1 ;
}
if ( ! V_2 -> V_29 && ! V_2 -> V_26 )
F_1 ( V_2 ) ;
} else {
if ( ! V_2 -> V_26 )
F_1 ( V_2 ) ;
while ( F_2 ( V_31 ) &
V_32 ) {
* ( V_2 -> V_24 ) ++ =
F_2 ( V_25 ) ;
V_2 -> V_20 -- ;
}
V_12 = 1 ;
}
V_13 = V_18 ;
}
V_2 -> V_33 = V_8 & V_34 ;
if ( V_2 -> V_33 )
V_13 = V_18 ;
F_3 ( V_8 , V_15 ) ;
if ( V_12 )
F_5 ( & V_2 -> V_35 ) ;
return V_13 ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_36 ;
unsigned int V_8 ;
V_2 -> V_24 = V_2 -> V_37 -> V_38 ;
V_2 -> V_20 = V_2 -> V_37 -> V_39 ;
V_36 = F_2 ( V_4 ) ;
V_36 |= V_40 | V_41 ;
if ( V_2 -> V_37 -> V_42 & V_43 )
V_2 -> V_20 = V_44 + 1 ;
if ( V_2 -> V_20 > V_27 )
V_36 |= V_5 ;
F_3 ( V_36 , V_4 ) ;
V_8 = F_2 ( V_15 ) ;
F_3 ( V_8 , V_15 ) ;
if ( V_2 -> V_20 > V_23 )
F_3 ( V_23 ,
V_22 ) ;
else
F_3 ( V_2 -> V_20 , V_22 ) ;
if ( ! V_2 -> V_26 &&
( ( V_2 -> V_37 -> V_42 & V_43 ) != V_43 ) &&
( V_2 -> V_20 <= V_27 ) )
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
V_2 -> V_24 = NULL ;
V_2 -> V_30 = V_2 -> V_37 -> V_38 ;
V_2 -> V_29 = V_2 -> V_37 -> V_39 ;
V_36 = F_2 ( V_4 ) ;
V_36 &= ~ V_40 ;
V_36 |= V_41 ;
if ( V_2 -> V_29 > V_27 )
V_36 |= V_5 ;
F_3 ( V_36 , V_4 ) ;
V_8 = F_2 ( V_15 ) ;
F_3 ( V_8 , V_15 ) ;
V_9 = V_27 -
F_2 ( V_22 ) ;
if ( V_2 -> V_29 > V_9 )
V_11 = V_9 ;
else
V_11 = V_2 -> V_29 ;
while ( V_11 -- ) {
F_3 ( ( * ( V_2 -> V_30 ) ++ ) , V_25 ) ;
V_2 -> V_29 -- ;
}
if ( ! V_2 -> V_26 && ! V_2 -> V_29 )
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
F_3 ( 0 , V_22 ) ;
V_53 = F_2 ( V_15 ) ;
F_3 ( V_53 , V_15 ) ;
V_53 = F_2 ( V_31 ) ;
F_3 ( V_53 , V_31 ) ;
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
if ( F_2 ( V_31 ) & V_70 )
return - V_66 ;
if ( V_68 > 1 ) {
V_2 -> V_26 = 1 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_4 ) ;
} else {
V_2 -> V_26 = 0 ;
}
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ , V_67 ++ ) {
if ( V_69 == ( V_68 - 1 ) )
V_2 -> V_26 = 0 ;
V_58 = F_9 ( V_2 , V_67 , V_51 ) ;
if ( V_58 )
return V_58 ;
if ( V_2 -> V_33 ) {
F_8 ( V_51 ) ;
if ( V_2 -> V_33 & V_16 )
return - V_71 ;
return - V_72 ;
}
}
return V_68 ;
}
static T_1 F_14 ( struct V_50 * V_51 )
{
return V_73 | V_74 |
( V_75 & ~ V_76 ) |
V_77 ;
}
static int F_15 ( unsigned long * V_78 , unsigned long V_79 ,
unsigned int * V_80 , unsigned int * V_81 )
{
unsigned long V_82 = * V_78 , V_83 = * V_78 , V_84 , V_85 ;
unsigned int V_86 , V_87 , V_88 = 0 , V_89 = 0 ;
unsigned int V_90 , V_91 ;
V_85 = V_79 / ( 22 * V_82 ) ;
if ( ! V_85 || ( V_85 > ( V_92 * V_93 ) ) )
return - V_94 ;
V_90 = - 1 ;
for ( V_86 = 0 ; V_86 < V_92 ; V_86 ++ ) {
V_87 = F_16 ( V_79 , 22 * V_82 * ( V_86 + 1 ) ) ;
if ( ( V_87 < 1 ) || ( V_87 > V_93 ) )
continue;
V_87 -- ;
V_84 = V_79 / ( 22 * ( V_86 + 1 ) * ( V_87 + 1 ) ) ;
if ( V_84 > V_82 )
continue;
V_91 = ( ( V_84 > V_82 ) ? ( V_84 - V_82 ) :
( V_82 - V_84 ) ) ;
if ( V_90 > V_91 ) {
V_88 = V_86 ;
V_89 = V_87 ;
V_83 = V_84 ;
V_90 = V_91 ;
}
}
* V_80 = V_88 ;
* V_81 = V_89 ;
* V_78 = V_83 ;
return 0 ;
}
static int F_17 ( unsigned long V_95 , struct V_1 * V_2 )
{
unsigned int V_86 , V_87 ;
unsigned int V_36 ;
int V_58 = 0 ;
unsigned long V_82 = V_2 -> V_96 ;
V_58 = F_15 ( & V_82 , V_95 , & V_86 , & V_87 ) ;
if ( V_58 )
return V_58 ;
V_36 = F_2 ( V_4 ) ;
V_36 &= ~ ( V_97 | V_98 ) ;
V_36 |= ( ( V_86 << V_99 ) |
( V_87 << V_100 ) ) ;
F_3 ( V_36 , V_4 ) ;
return 0 ;
}
static int F_18 ( struct V_101 * V_102 , unsigned long
V_103 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
struct V_1 * V_2 = F_19 ( V_102 ) ;
if ( V_2 -> V_107 )
return V_108 ;
switch ( V_103 ) {
case V_109 :
{
unsigned long V_79 = V_106 -> V_110 ;
unsigned long V_82 = V_2 -> V_96 ;
unsigned int V_86 , V_87 ;
int V_58 ;
V_58 = F_15 ( & V_82 , V_79 , & V_86 , & V_87 ) ;
if ( V_58 ) {
F_20 ( V_2 -> V_51 . V_63 . V_64 ,
L_2 ) ;
return V_111 ;
}
if ( V_106 -> V_110 > V_106 -> V_112 )
F_17 ( V_106 -> V_110 , V_2 ) ;
return V_108 ;
}
case V_113 :
V_2 -> V_79 = V_106 -> V_110 ;
if ( V_106 -> V_110 < V_106 -> V_112 )
F_17 ( V_106 -> V_110 , V_2 ) ;
return V_108 ;
case V_114 :
if ( V_106 -> V_110 > V_106 -> V_112 )
F_17 ( V_106 -> V_112 , V_2 ) ;
return V_108 ;
default:
return V_115 ;
}
}
static int T_3 F_21 ( struct V_116 * V_117 )
{
struct V_118 * V_119 = F_22 ( V_117 ,
struct V_118 , V_63 ) ;
struct V_1 * V_120 = F_23 ( V_119 ) ;
F_24 ( V_120 -> V_121 ) ;
V_120 -> V_107 = 1 ;
return 0 ;
}
static int T_3 F_25 ( struct V_116 * V_117 )
{
struct V_118 * V_119 = F_22 ( V_117 ,
struct V_118 , V_63 ) ;
struct V_1 * V_120 = F_23 ( V_119 ) ;
int V_58 ;
V_58 = F_26 ( V_120 -> V_121 ) ;
if ( V_58 ) {
F_12 ( V_117 , L_3 ) ;
return V_58 ;
}
V_120 -> V_107 = 0 ;
return 0 ;
}
static int F_27 ( struct V_118 * V_119 )
{
struct V_122 * V_123 ;
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_28 ( & V_119 -> V_63 , sizeof( * V_2 ) , V_124 ) ;
if ( ! V_2 )
return - V_125 ;
F_29 ( V_119 , V_2 ) ;
V_123 = F_30 ( V_119 , V_126 , 0 ) ;
V_2 -> V_127 = F_31 ( & V_119 -> V_63 , V_123 ) ;
if ( F_32 ( V_2 -> V_127 ) )
return F_33 ( V_2 -> V_127 ) ;
V_2 -> V_6 = F_34 ( V_119 , 0 ) ;
V_2 -> V_51 . V_63 . V_128 = V_119 -> V_63 . V_128 ;
V_2 -> V_51 . V_129 = & V_130 ;
V_2 -> V_51 . V_62 = V_131 ;
V_2 -> V_51 . V_132 = 3 ;
V_2 -> V_51 . V_52 = V_2 ;
V_2 -> V_51 . V_63 . V_64 = & V_119 -> V_63 ;
F_35 ( & V_2 -> V_35 ) ;
snprintf ( V_2 -> V_51 . V_133 , sizeof( V_2 -> V_51 . V_133 ) ,
L_4 , ( unsigned long ) V_123 -> V_134 ) ;
V_2 -> V_121 = F_36 ( & V_119 -> V_63 , NULL ) ;
if ( F_32 ( V_2 -> V_121 ) ) {
F_12 ( & V_119 -> V_63 , L_5 ) ;
return F_33 ( V_2 -> V_121 ) ;
}
V_58 = F_37 ( V_2 -> V_121 ) ;
if ( V_58 ) {
F_12 ( & V_119 -> V_63 , L_6 ) ;
return V_58 ;
}
V_2 -> V_135 . V_136 = F_18 ;
if ( F_38 ( V_2 -> V_121 , & V_2 -> V_135 ) )
F_20 ( & V_119 -> V_63 , L_7 ) ;
V_2 -> V_79 = F_39 ( V_2 -> V_121 ) ;
V_58 = F_40 ( V_119 -> V_63 . V_128 , L_8 ,
& V_2 -> V_96 ) ;
if ( V_58 || ( V_2 -> V_96 > V_137 ) )
V_2 -> V_96 = V_138 ;
F_3 ( V_139 | V_60 | V_140 ,
V_4 ) ;
V_58 = F_17 ( V_2 -> V_79 , V_2 ) ;
if ( V_58 ) {
F_12 ( & V_119 -> V_63 , L_9 , V_2 -> V_96 ) ;
V_58 = - V_94 ;
goto V_141;
}
V_58 = F_41 ( & V_119 -> V_63 , V_2 -> V_6 , F_4 , 0 ,
V_142 , V_2 ) ;
if ( V_58 ) {
F_12 ( & V_119 -> V_63 , L_10 , V_2 -> V_6 ) ;
goto V_141;
}
V_58 = F_42 ( & V_2 -> V_51 ) ;
if ( V_58 < 0 ) {
F_12 ( & V_119 -> V_63 , L_11 , V_58 ) ;
goto V_141;
}
F_3 ( V_143 , V_144 ) ;
F_43 ( & V_119 -> V_63 , L_12 ,
V_2 -> V_96 / 1000 , ( unsigned long ) V_123 -> V_134 , V_2 -> V_6 ) ;
return 0 ;
V_141:
F_44 ( V_2 -> V_121 ) ;
return V_58 ;
}
static int F_45 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_23 ( V_119 ) ;
F_46 ( & V_2 -> V_51 ) ;
F_47 ( V_2 -> V_121 , & V_2 -> V_135 ) ;
F_44 ( V_2 -> V_121 ) ;
return 0 ;
}
