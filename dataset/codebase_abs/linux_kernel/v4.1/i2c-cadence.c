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
unsigned long V_58 ;
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
if ( V_58 == 0 ) {
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
int V_69 , V_70 ;
T_1 V_3 ;
struct V_1 * V_2 = V_51 -> V_52 ;
if ( F_2 ( V_24 ) & V_71 )
return - V_66 ;
if ( V_68 > 1 ) {
for ( V_70 = 0 ; V_70 < V_68 - 1 ; V_70 ++ ) {
if ( V_67 [ V_70 ] . V_42 & V_61 ) {
F_14 ( V_51 -> V_63 . V_64 ,
L_2 ) ;
return - V_72 ;
}
}
V_2 -> V_27 = 1 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_4 ) ;
} else {
V_2 -> V_27 = 0 ;
}
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ , V_67 ++ ) {
if ( V_70 == ( V_68 - 1 ) )
V_2 -> V_27 = 0 ;
V_69 = F_9 ( V_2 , V_67 , V_51 ) ;
if ( V_69 )
return V_69 ;
if ( V_2 -> V_33 ) {
F_8 ( V_51 ) ;
if ( V_2 -> V_33 & V_16 )
return - V_73 ;
return - V_74 ;
}
}
return V_68 ;
}
static T_1 F_15 ( struct V_50 * V_51 )
{
return V_75 | V_76 |
( V_77 & ~ V_78 ) |
V_79 ;
}
static int F_16 ( unsigned long * V_80 , unsigned long V_81 ,
unsigned int * V_82 , unsigned int * V_83 )
{
unsigned long V_84 = * V_80 , V_85 = * V_80 , V_86 , V_87 ;
unsigned int V_88 , V_89 , V_90 = 0 , V_91 = 0 ;
unsigned int V_92 , V_93 ;
V_87 = V_81 / ( 22 * V_84 ) ;
if ( ! V_87 || ( V_87 > ( V_94 * V_95 ) ) )
return - V_96 ;
V_92 = - 1 ;
for ( V_88 = 0 ; V_88 < V_94 ; V_88 ++ ) {
V_89 = F_17 ( V_81 , 22 * V_84 * ( V_88 + 1 ) ) ;
if ( ( V_89 < 1 ) || ( V_89 > V_95 ) )
continue;
V_89 -- ;
V_86 = V_81 / ( 22 * ( V_88 + 1 ) * ( V_89 + 1 ) ) ;
if ( V_86 > V_84 )
continue;
V_93 = ( ( V_86 > V_84 ) ? ( V_86 - V_84 ) :
( V_84 - V_86 ) ) ;
if ( V_92 > V_93 ) {
V_90 = V_88 ;
V_91 = V_89 ;
V_85 = V_86 ;
V_92 = V_93 ;
}
}
* V_82 = V_90 ;
* V_83 = V_91 ;
* V_80 = V_85 ;
return 0 ;
}
static int F_18 ( unsigned long V_97 , struct V_1 * V_2 )
{
unsigned int V_88 , V_89 ;
unsigned int V_36 ;
int V_69 = 0 ;
unsigned long V_84 = V_2 -> V_98 ;
V_69 = F_16 ( & V_84 , V_97 , & V_88 , & V_89 ) ;
if ( V_69 )
return V_69 ;
V_36 = F_2 ( V_4 ) ;
V_36 &= ~ ( V_99 | V_100 ) ;
V_36 |= ( ( V_88 << V_101 ) |
( V_89 << V_102 ) ) ;
F_3 ( V_36 , V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_103 * V_104 , unsigned long
V_105 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
struct V_1 * V_2 = F_20 ( V_104 ) ;
if ( V_2 -> V_109 )
return V_110 ;
switch ( V_105 ) {
case V_111 :
{
unsigned long V_81 = V_108 -> V_112 ;
unsigned long V_84 = V_2 -> V_98 ;
unsigned int V_88 , V_89 ;
int V_69 ;
V_69 = F_16 ( & V_84 , V_81 , & V_88 , & V_89 ) ;
if ( V_69 ) {
F_14 ( V_2 -> V_51 . V_63 . V_64 ,
L_3 ) ;
return V_113 ;
}
if ( V_108 -> V_112 > V_108 -> V_114 )
F_18 ( V_108 -> V_112 , V_2 ) ;
return V_110 ;
}
case V_115 :
V_2 -> V_81 = V_108 -> V_112 ;
if ( V_108 -> V_112 < V_108 -> V_114 )
F_18 ( V_108 -> V_112 , V_2 ) ;
return V_110 ;
case V_116 :
if ( V_108 -> V_112 > V_108 -> V_114 )
F_18 ( V_108 -> V_114 , V_2 ) ;
return V_110 ;
default:
return V_117 ;
}
}
static int T_3 F_21 ( struct V_118 * V_119 )
{
struct V_120 * V_121 = F_22 ( V_119 ,
struct V_120 , V_63 ) ;
struct V_1 * V_122 = F_23 ( V_121 ) ;
F_24 ( V_122 -> V_123 ) ;
V_122 -> V_109 = 1 ;
return 0 ;
}
static int T_3 F_25 ( struct V_118 * V_119 )
{
struct V_120 * V_121 = F_22 ( V_119 ,
struct V_120 , V_63 ) ;
struct V_1 * V_122 = F_23 ( V_121 ) ;
int V_69 ;
V_69 = F_26 ( V_122 -> V_123 ) ;
if ( V_69 ) {
F_12 ( V_119 , L_4 ) ;
return V_69 ;
}
V_122 -> V_109 = 0 ;
return 0 ;
}
static int F_27 ( struct V_120 * V_121 )
{
struct V_124 * V_125 ;
struct V_1 * V_2 ;
int V_69 ;
V_2 = F_28 ( & V_121 -> V_63 , sizeof( * V_2 ) , V_126 ) ;
if ( ! V_2 )
return - V_127 ;
F_29 ( V_121 , V_2 ) ;
V_125 = F_30 ( V_121 , V_128 , 0 ) ;
V_2 -> V_129 = F_31 ( & V_121 -> V_63 , V_125 ) ;
if ( F_32 ( V_2 -> V_129 ) )
return F_33 ( V_2 -> V_129 ) ;
V_2 -> V_6 = F_34 ( V_121 , 0 ) ;
V_2 -> V_51 . V_63 . V_130 = V_121 -> V_63 . V_130 ;
V_2 -> V_51 . V_131 = & V_132 ;
V_2 -> V_51 . V_62 = V_133 ;
V_2 -> V_51 . V_134 = 3 ;
V_2 -> V_51 . V_52 = V_2 ;
V_2 -> V_51 . V_63 . V_64 = & V_121 -> V_63 ;
F_35 ( & V_2 -> V_35 ) ;
snprintf ( V_2 -> V_51 . V_135 , sizeof( V_2 -> V_51 . V_135 ) ,
L_5 , ( unsigned long ) V_125 -> V_136 ) ;
V_2 -> V_123 = F_36 ( & V_121 -> V_63 , NULL ) ;
if ( F_32 ( V_2 -> V_123 ) ) {
F_12 ( & V_121 -> V_63 , L_6 ) ;
return F_33 ( V_2 -> V_123 ) ;
}
V_69 = F_37 ( V_2 -> V_123 ) ;
if ( V_69 ) {
F_12 ( & V_121 -> V_63 , L_7 ) ;
return V_69 ;
}
V_2 -> V_137 . V_138 = F_19 ;
if ( F_38 ( V_2 -> V_123 , & V_2 -> V_137 ) )
F_14 ( & V_121 -> V_63 , L_8 ) ;
V_2 -> V_81 = F_39 ( V_2 -> V_123 ) ;
V_69 = F_40 ( V_121 -> V_63 . V_130 , L_9 ,
& V_2 -> V_98 ) ;
if ( V_69 || ( V_2 -> V_98 > V_139 ) )
V_2 -> V_98 = V_140 ;
F_3 ( V_141 | V_60 | V_142 ,
V_4 ) ;
V_69 = F_18 ( V_2 -> V_81 , V_2 ) ;
if ( V_69 ) {
F_12 ( & V_121 -> V_63 , L_10 , V_2 -> V_98 ) ;
V_69 = - V_96 ;
goto V_143;
}
V_69 = F_41 ( & V_121 -> V_63 , V_2 -> V_6 , F_4 , 0 ,
V_144 , V_2 ) ;
if ( V_69 ) {
F_12 ( & V_121 -> V_63 , L_11 , V_2 -> V_6 ) ;
goto V_143;
}
V_69 = F_42 ( & V_2 -> V_51 ) ;
if ( V_69 < 0 ) {
F_12 ( & V_121 -> V_63 , L_12 , V_69 ) ;
goto V_143;
}
F_3 ( V_145 , V_146 ) ;
F_43 ( & V_121 -> V_63 , L_13 ,
V_2 -> V_98 / 1000 , ( unsigned long ) V_125 -> V_136 , V_2 -> V_6 ) ;
return 0 ;
V_143:
F_44 ( V_2 -> V_123 ) ;
return V_69 ;
}
static int F_45 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_23 ( V_121 ) ;
F_46 ( & V_2 -> V_51 ) ;
F_47 ( V_2 -> V_123 , & V_2 -> V_137 ) ;
F_44 ( V_2 -> V_123 ) ;
return 0 ;
}
