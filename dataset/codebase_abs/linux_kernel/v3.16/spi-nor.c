static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_6 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_1 , ( int ) V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_7 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_8 , L_2 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 ) {
case V_10 :
case V_11 :
case V_12 :
return 1 ;
case V_13 :
return 0 ;
}
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
V_2 -> V_14 [ 0 ] = V_4 ;
return V_2 -> V_15 ( V_2 , V_16 , V_2 -> V_14 , 1 , 0 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_15 ( V_2 , V_17 , NULL , 0 , 0 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_15 ( V_2 , V_18 , NULL , 0 , 0 ) ;
}
static inline struct V_1 * F_9 ( struct V_19 * V_20 )
{
return V_20 -> V_21 ;
}
static inline int F_10 ( struct V_1 * V_2 , T_2 V_22 , int V_23 )
{
int V_24 ;
bool V_25 = false ;
T_1 V_26 ;
switch ( F_11 ( V_22 ) ) {
case V_27 :
V_25 = true ;
case V_28 :
case 0xEF :
if ( V_25 )
F_7 ( V_2 ) ;
V_26 = V_23 ? V_29 : V_30 ;
V_24 = V_2 -> V_15 ( V_2 , V_26 , NULL , 0 , 0 ) ;
if ( V_25 )
F_8 ( V_2 ) ;
return V_24 ;
default:
V_2 -> V_14 [ 0 ] = V_23 << 7 ;
return V_2 -> V_15 ( V_2 , V_31 , V_2 -> V_14 , 1 , 0 ) ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned long V_32 ;
int V_33 ;
V_32 = V_34 + V_35 ;
do {
F_13 () ;
V_33 = F_1 ( V_2 ) ;
if ( V_33 < 0 )
break;
else if ( ! ( V_33 & V_36 ) )
return 0 ;
} while ( ! F_14 ( V_34 , V_32 ) );
return - V_37 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_2 -> F_15 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 ;
F_17 ( V_2 -> V_8 , L_3 , ( long long ) ( V_2 -> V_20 -> V_38 >> 10 ) ) ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_7 ( V_2 ) ;
return V_2 -> V_15 ( V_2 , V_39 , NULL , 0 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , enum V_40 V_41 )
{
int V_3 = 0 ;
F_19 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_43 ) {
V_3 = V_2 -> V_43 ( V_2 , V_41 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_8 , L_4 ) ;
F_20 ( & V_2 -> V_42 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_21 ( struct V_1 * V_2 , enum V_40 V_41 )
{
if ( V_2 -> V_44 )
V_2 -> V_44 ( V_2 , V_41 ) ;
F_20 ( & V_2 -> V_42 ) ;
}
static int F_22 ( struct V_19 * V_20 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_2 V_47 , V_48 ;
T_3 V_49 ;
int V_3 ;
F_17 ( V_2 -> V_8 , L_5 , ( long long ) V_46 -> V_47 ,
( long long ) V_46 -> V_48 ) ;
F_23 ( V_46 -> V_48 , V_20 -> V_50 , & V_49 ) ;
if ( V_49 )
return - V_51 ;
V_47 = V_46 -> V_47 ;
V_48 = V_46 -> V_48 ;
V_3 = F_18 ( V_2 , V_52 ) ;
if ( V_3 )
return V_3 ;
if ( V_48 == V_20 -> V_38 ) {
if ( F_16 ( V_2 ) ) {
V_3 = - V_53 ;
goto V_54;
}
} else {
while ( V_48 ) {
if ( V_2 -> V_55 ( V_2 , V_47 ) ) {
V_3 = - V_53 ;
goto V_54;
}
V_47 += V_20 -> V_50 ;
V_48 -= V_20 -> V_50 ;
}
}
F_21 ( V_2 , V_52 ) ;
V_46 -> V_56 = V_57 ;
F_24 ( V_46 ) ;
return V_3 ;
V_54:
F_21 ( V_2 , V_52 ) ;
V_46 -> V_56 = V_58 ;
return V_3 ;
}
static int F_25 ( struct V_19 * V_20 , T_4 V_59 , T_5 V_48 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_3 V_60 = V_59 ;
T_6 V_61 , V_62 ;
int V_3 = 0 ;
V_3 = F_18 ( V_2 , V_63 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_64;
V_61 = F_1 ( V_2 ) ;
if ( V_60 < V_20 -> V_38 - ( V_20 -> V_38 / 2 ) )
V_62 = V_61 | V_65 | V_66 | V_67 ;
else if ( V_60 < V_20 -> V_38 - ( V_20 -> V_38 / 4 ) )
V_62 = ( V_61 & ~ V_67 ) | V_65 | V_66 ;
else if ( V_60 < V_20 -> V_38 - ( V_20 -> V_38 / 8 ) )
V_62 = ( V_61 & ~ V_66 ) | V_65 | V_67 ;
else if ( V_60 < V_20 -> V_38 - ( V_20 -> V_38 / 16 ) )
V_62 = ( V_61 & ~ ( V_67 | V_66 ) ) | V_65 ;
else if ( V_60 < V_20 -> V_38 - ( V_20 -> V_38 / 32 ) )
V_62 = ( V_61 & ~ V_65 ) | V_66 | V_67 ;
else if ( V_60 < V_20 -> V_38 - ( V_20 -> V_38 / 64 ) )
V_62 = ( V_61 & ~ ( V_65 | V_67 ) ) | V_66 ;
else
V_62 = ( V_61 & ~ ( V_65 | V_66 ) ) | V_67 ;
if ( ( V_62 & ( V_65 | V_66 | V_67 ) ) >
( V_61 & ( V_65 | V_66 | V_67 ) ) ) {
F_7 ( V_2 ) ;
V_3 = F_6 ( V_2 , V_62 ) ;
if ( V_3 )
goto V_64;
}
V_64:
F_21 ( V_2 , V_63 ) ;
return V_3 ;
}
static int F_26 ( struct V_19 * V_20 , T_4 V_59 , T_5 V_48 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_3 V_60 = V_59 ;
T_6 V_61 , V_62 ;
int V_3 = 0 ;
V_3 = F_18 ( V_2 , V_68 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_64;
V_61 = F_1 ( V_2 ) ;
if ( V_60 + V_48 > V_20 -> V_38 - ( V_20 -> V_38 / 64 ) )
V_62 = V_61 & ~ ( V_65 | V_66 | V_67 ) ;
else if ( V_60 + V_48 > V_20 -> V_38 - ( V_20 -> V_38 / 32 ) )
V_62 = ( V_61 & ~ ( V_65 | V_66 ) ) | V_67 ;
else if ( V_60 + V_48 > V_20 -> V_38 - ( V_20 -> V_38 / 16 ) )
V_62 = ( V_61 & ~ ( V_65 | V_67 ) ) | V_66 ;
else if ( V_60 + V_48 > V_20 -> V_38 - ( V_20 -> V_38 / 8 ) )
V_62 = ( V_61 & ~ V_65 ) | V_66 | V_67 ;
else if ( V_60 + V_48 > V_20 -> V_38 - ( V_20 -> V_38 / 4 ) )
V_62 = ( V_61 & ~ ( V_67 | V_66 ) ) | V_65 ;
else if ( V_60 + V_48 > V_20 -> V_38 - ( V_20 -> V_38 / 2 ) )
V_62 = ( V_61 & ~ V_66 ) | V_65 | V_67 ;
else
V_62 = ( V_61 & ~ V_67 ) | V_65 | V_66 ;
if ( ( V_62 & ( V_65 | V_66 | V_67 ) ) <
( V_61 & ( V_65 | V_66 | V_67 ) ) ) {
F_7 ( V_2 ) ;
V_3 = F_6 ( V_2 , V_62 ) ;
if ( V_3 )
goto V_64;
}
V_64:
F_21 ( V_2 , V_68 ) ;
return V_3 ;
}
static const struct V_69 * F_27 ( struct V_1 * V_2 )
{
int V_70 ;
T_1 V_71 [ 5 ] ;
T_2 V_72 ;
T_7 V_73 ;
struct V_74 * V_75 ;
V_70 = V_2 -> V_5 ( V_2 , V_76 , V_71 , 5 ) ;
if ( V_70 < 0 ) {
F_17 ( V_2 -> V_8 , L_6 , V_70 ) ;
return F_28 ( V_70 ) ;
}
V_72 = V_71 [ 0 ] ;
V_72 = V_72 << 8 ;
V_72 |= V_71 [ 1 ] ;
V_72 = V_72 << 8 ;
V_72 |= V_71 [ 2 ] ;
V_73 = V_71 [ 3 ] << 8 | V_71 [ 4 ] ;
for ( V_70 = 0 ; V_70 < F_29 ( V_77 ) - 1 ; V_70 ++ ) {
V_75 = ( void * ) V_77 [ V_70 ] . V_78 ;
if ( V_75 -> V_22 == V_72 ) {
if ( V_75 -> V_79 == 0 || V_75 -> V_79 == V_73 )
return & V_77 [ V_70 ] ;
}
}
F_4 ( V_2 -> V_8 , L_7 , V_72 ) ;
return F_28 ( - V_80 ) ;
}
static const struct V_69 * F_30 ( struct V_1 * V_2 )
{
return V_2 -> V_81 ( V_2 ) ;
}
static int F_31 ( struct V_19 * V_20 , T_4 V_82 , T_8 V_48 ,
T_8 * V_83 , T_9 * V_84 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
int V_3 ;
F_17 ( V_2 -> V_8 , L_8 , ( T_2 ) V_82 , V_48 ) ;
V_3 = F_18 ( V_2 , V_85 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_86 ( V_2 , V_82 , V_48 , V_83 , V_84 ) ;
F_21 ( V_2 , V_85 ) ;
return V_3 ;
}
static int F_32 ( struct V_19 * V_20 , T_4 V_87 , T_8 V_48 ,
T_8 * V_83 , const T_9 * V_84 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_8 V_88 ;
int V_3 ;
F_17 ( V_2 -> V_8 , L_9 , ( T_2 ) V_87 , V_48 ) ;
V_3 = F_18 ( V_2 , V_89 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_90;
F_7 ( V_2 ) ;
V_2 -> V_91 = false ;
V_88 = V_87 % 2 ;
if ( V_88 ) {
V_2 -> V_92 = V_93 ;
V_2 -> V_94 ( V_2 , V_87 , 1 , V_83 , V_84 ) ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_90;
}
V_87 += V_88 ;
for (; V_88 < V_48 - 1 ; V_88 += 2 ) {
V_2 -> V_92 = V_95 ;
V_2 -> V_94 ( V_2 , V_87 , 2 , V_83 , V_84 + V_88 ) ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_90;
V_87 += 2 ;
V_2 -> V_91 = true ;
}
V_2 -> V_91 = false ;
F_8 ( V_2 ) ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_90;
if ( V_88 != V_48 ) {
F_7 ( V_2 ) ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 ( V_2 , V_87 , 1 , V_83 , V_84 + V_88 ) ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_90;
F_8 ( V_2 ) ;
}
V_90:
F_21 ( V_2 , V_89 ) ;
return V_3 ;
}
static int F_33 ( struct V_19 * V_20 , T_4 V_87 , T_8 V_48 ,
T_8 * V_83 , const T_9 * V_84 )
{
struct V_1 * V_2 = F_9 ( V_20 ) ;
T_2 V_96 , V_97 , V_98 ;
int V_3 ;
F_17 ( V_2 -> V_8 , L_9 , ( T_2 ) V_87 , V_48 ) ;
V_3 = F_18 ( V_2 , V_89 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_99;
F_7 ( V_2 ) ;
V_96 = V_87 & ( V_2 -> V_97 - 1 ) ;
if ( V_96 + V_48 <= V_2 -> V_97 ) {
V_2 -> V_94 ( V_2 , V_87 , V_48 , V_83 , V_84 ) ;
} else {
V_97 = V_2 -> V_97 - V_96 ;
V_2 -> V_94 ( V_2 , V_87 , V_97 , V_83 , V_84 ) ;
for ( V_98 = V_97 ; V_98 < V_48 ; V_98 += V_97 ) {
V_97 = V_48 - V_98 ;
if ( V_97 > V_2 -> V_97 )
V_97 = V_2 -> V_97 ;
F_15 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_94 ( V_2 , V_87 + V_98 , V_97 , V_83 , V_84 + V_98 ) ;
}
}
V_99:
F_21 ( V_2 , V_89 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
V_2 -> V_14 [ 0 ] = V_4 | V_100 ;
V_2 -> V_15 ( V_2 , V_16 , V_2 -> V_14 , 1 , 0 ) ;
if ( F_15 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_100 ) ) ) {
F_4 ( V_2 -> V_8 , L_10 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_7 V_4 )
{
V_2 -> V_14 [ 0 ] = V_4 & 0xff ;
V_2 -> V_14 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_15 ( V_2 , V_16 , V_2 -> V_14 , 2 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_3 ;
int V_101 = V_102 << 8 ;
F_7 ( V_2 ) ;
V_3 = F_35 ( V_2 , V_101 ) ;
if ( V_3 < 0 ) {
F_4 ( V_2 -> V_8 ,
L_11 ) ;
return - V_51 ;
}
V_3 = F_3 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_102 ) ) ) {
F_4 ( V_2 -> V_8 , L_12 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_22 )
{
int V_24 ;
switch ( F_11 ( V_22 ) ) {
case V_28 :
V_24 = F_34 ( V_2 ) ;
if ( V_24 ) {
F_4 ( V_2 -> V_8 , L_13 ) ;
return - V_51 ;
}
return V_24 ;
default:
V_24 = F_36 ( V_2 ) ;
if ( V_24 ) {
F_4 ( V_2 -> V_8 , L_14 ) ;
return - V_51 ;
}
return V_24 ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 || ! V_2 -> V_86 || ! V_2 -> V_94 ||
! V_2 -> V_5 || ! V_2 -> V_15 || ! V_2 -> V_55 ) {
F_2 ( L_15 ) ;
return - V_51 ;
}
if ( ! V_2 -> V_81 )
V_2 -> V_81 = F_27 ;
if ( ! V_2 -> F_15 )
V_2 -> F_15 = F_12 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , const struct V_69 * V_71 ,
enum V_103 V_104 )
{
struct V_74 * V_75 ;
struct V_105 * V_106 ;
struct V_107 * V_8 = V_2 -> V_8 ;
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_108 * V_109 = V_8 -> V_110 ;
int V_3 ;
int V_98 ;
V_3 = F_38 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_106 = F_40 ( V_8 ) ;
if ( V_106 && V_106 -> type ) {
const struct V_69 * V_111 ;
for ( V_98 = 0 ; V_98 < F_29 ( V_77 ) - 1 ; V_98 ++ ) {
V_111 = & V_77 [ V_98 ] ;
if ( strcmp ( V_106 -> type , V_111 -> V_112 ) )
continue;
break;
}
if ( V_98 < F_29 ( V_77 ) - 1 )
V_71 = V_111 ;
else
F_41 ( V_8 , L_16 , V_106 -> type ) ;
}
V_75 = ( void * ) V_71 -> V_78 ;
if ( V_75 -> V_22 ) {
const struct V_69 * V_113 ;
V_113 = F_30 ( V_2 ) ;
if ( F_42 ( V_113 ) ) {
return F_43 ( V_113 ) ;
} else if ( V_113 != V_71 ) {
F_41 ( V_8 , L_17 ,
V_113 -> V_112 , V_71 -> V_112 ) ;
V_71 = V_113 ;
V_75 = ( void * ) V_113 -> V_78 ;
}
}
F_44 ( & V_2 -> V_42 ) ;
if ( F_11 ( V_75 -> V_22 ) == V_114 ||
F_11 ( V_75 -> V_22 ) == V_115 ||
F_11 ( V_75 -> V_22 ) == V_116 ) {
F_7 ( V_2 ) ;
F_6 ( V_2 , 0 ) ;
}
if ( V_106 && V_106 -> V_112 )
V_20 -> V_112 = V_106 -> V_112 ;
else
V_20 -> V_112 = F_45 ( V_8 ) ;
V_20 -> type = V_117 ;
V_20 -> V_118 = 1 ;
V_20 -> V_119 = V_120 ;
V_20 -> V_38 = V_75 -> V_121 * V_75 -> V_122 ;
V_20 -> V_123 = F_22 ;
V_20 -> V_124 = F_31 ;
if ( F_11 ( V_75 -> V_22 ) == V_27 ) {
V_20 -> V_125 = F_25 ;
V_20 -> V_126 = F_26 ;
}
if ( V_75 -> V_119 & V_127 )
V_20 -> V_128 = F_32 ;
else
V_20 -> V_128 = F_33 ;
if ( V_75 -> V_119 & V_129 ) {
V_2 -> V_130 = V_131 ;
V_20 -> V_50 = 4096 ;
} else if ( V_75 -> V_119 & V_132 ) {
V_2 -> V_130 = V_133 ;
V_20 -> V_50 = 4096 ;
} else {
V_2 -> V_130 = V_134 ;
V_20 -> V_50 = V_75 -> V_121 ;
}
if ( V_75 -> V_119 & V_135 )
V_20 -> V_119 |= V_136 ;
V_20 -> V_8 . V_137 = V_8 ;
V_2 -> V_97 = V_75 -> V_97 ;
V_20 -> V_138 = V_2 -> V_97 ;
if ( V_109 ) {
if ( F_46 ( V_109 , L_18 ) )
V_2 -> V_9 = V_10 ;
else
V_2 -> V_9 = V_13 ;
} else {
V_2 -> V_9 = V_10 ;
}
if ( V_75 -> V_119 & V_139 )
V_2 -> V_9 = V_13 ;
if ( V_104 == V_12 && V_75 -> V_119 & V_140 ) {
V_3 = F_37 ( V_2 , V_75 -> V_22 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_19 ) ;
return V_3 ;
}
V_2 -> V_9 = V_12 ;
} else if ( V_104 == V_11 && V_75 -> V_119 & V_141 ) {
V_2 -> V_9 = V_11 ;
}
switch ( V_2 -> V_9 ) {
case V_12 :
V_2 -> V_142 = V_143 ;
break;
case V_11 :
V_2 -> V_142 = V_144 ;
break;
case V_10 :
V_2 -> V_142 = V_145 ;
break;
case V_13 :
V_2 -> V_142 = V_146 ;
break;
default:
F_4 ( V_8 , L_20 ) ;
return - V_51 ;
}
V_2 -> V_92 = V_147 ;
if ( V_75 -> V_148 )
V_2 -> V_148 = V_75 -> V_148 ;
else if ( V_20 -> V_38 > 0x1000000 ) {
V_2 -> V_148 = 4 ;
if ( F_11 ( V_75 -> V_22 ) == V_149 ) {
switch ( V_2 -> V_9 ) {
case V_12 :
V_2 -> V_142 = V_150 ;
break;
case V_11 :
V_2 -> V_142 = V_151 ;
break;
case V_10 :
V_2 -> V_142 = V_152 ;
break;
case V_13 :
V_2 -> V_142 = V_153 ;
break;
}
V_2 -> V_92 = V_154 ;
V_2 -> V_130 = V_155 ;
V_20 -> V_50 = V_75 -> V_121 ;
} else
F_10 ( V_2 , V_75 -> V_22 , 1 ) ;
} else {
V_2 -> V_148 = 3 ;
}
V_2 -> V_156 = F_5 ( V_2 ) ;
F_47 ( V_8 , L_21 , V_71 -> V_112 ,
( long long ) V_20 -> V_38 >> 10 ) ;
F_17 ( V_8 ,
L_22
L_23 ,
V_20 -> V_112 , ( long long ) V_20 -> V_38 , ( long long ) ( V_20 -> V_38 >> 20 ) ,
V_20 -> V_50 , V_20 -> V_50 / 1024 , V_20 -> V_157 ) ;
if ( V_20 -> V_157 )
for ( V_98 = 0 ; V_98 < V_20 -> V_157 ; V_98 ++ )
F_17 ( V_8 ,
L_24
L_25
L_26 ,
V_98 , ( long long ) V_20 -> V_158 [ V_98 ] . V_60 ,
V_20 -> V_158 [ V_98 ] . V_50 ,
V_20 -> V_158 [ V_98 ] . V_50 / 1024 ,
V_20 -> V_158 [ V_98 ] . V_159 ) ;
return 0 ;
}
const struct V_69 * F_48 ( char * V_112 )
{
const struct V_69 * V_71 = V_77 ;
while ( V_71 -> V_112 [ 0 ] ) {
if ( ! strcmp ( V_112 , V_71 -> V_112 ) )
return V_71 ;
V_71 ++ ;
}
return NULL ;
}
