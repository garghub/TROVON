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
F_2 ( L_2 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_8 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_3 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
return 1 ;
case V_14 :
return 0 ;
}
return 0 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 , 0 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_18 , NULL , 0 , 0 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_19 , NULL , 0 , 0 ) ;
}
static inline struct V_1 * F_10 ( struct V_20 * V_21 )
{
return V_21 -> V_22 ;
}
static inline int F_11 ( struct V_1 * V_2 , T_2 V_23 , int V_24 )
{
int V_25 ;
bool V_26 = false ;
T_1 V_27 ;
switch ( F_12 ( V_23 ) ) {
case V_28 :
V_26 = true ;
case V_29 :
case 0xEF :
if ( V_26 )
F_8 ( V_2 ) ;
V_27 = V_24 ? V_30 : V_31 ;
V_25 = V_2 -> V_16 ( V_2 , V_27 , NULL , 0 , 0 ) ;
if ( V_26 )
F_9 ( V_2 ) ;
return V_25 ;
default:
V_2 -> V_15 [ 0 ] = V_24 << 7 ;
return V_2 -> V_16 ( V_2 , V_32 , V_2 -> V_15 , 1 , 0 ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
int V_34 ;
V_33 = V_35 + V_36 ;
do {
F_14 () ;
V_34 = F_1 ( V_2 ) ;
if ( V_34 < 0 )
break;
else if ( ! ( V_34 & V_37 ) )
return 0 ;
} while ( ! F_15 ( V_35 , V_33 ) );
return - V_38 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
int V_34 ;
int V_39 ;
V_33 = V_35 + V_36 ;
do {
F_14 () ;
V_34 = F_1 ( V_2 ) ;
if ( V_34 < 0 ) {
break;
} else if ( ! ( V_34 & V_37 ) ) {
V_39 = F_3 ( V_2 ) ;
if ( V_39 < 0 )
break;
if ( V_39 & V_40 )
return 0 ;
}
} while ( ! F_15 ( V_35 , V_33 ) );
return - V_38 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return V_2 -> F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 ;
F_19 ( V_2 -> V_9 , L_4 , ( long long ) ( V_2 -> V_21 -> V_41 >> 10 ) ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
return V_2 -> V_16 ( V_2 , V_42 , NULL , 0 , 0 ) ;
}
static int F_20 ( struct V_1 * V_2 , enum V_43 V_44 )
{
int V_3 = 0 ;
F_21 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_46 ) {
V_3 = V_2 -> V_46 ( V_2 , V_44 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_5 ) ;
F_22 ( & V_2 -> V_45 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_23 ( struct V_1 * V_2 , enum V_43 V_44 )
{
if ( V_2 -> V_47 )
V_2 -> V_47 ( V_2 , V_44 ) ;
F_22 ( & V_2 -> V_45 ) ;
}
static int F_24 ( struct V_20 * V_21 , struct V_48 * V_49 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_50 , V_51 ;
T_3 V_52 ;
int V_3 ;
F_19 ( V_2 -> V_9 , L_6 , ( long long ) V_49 -> V_50 ,
( long long ) V_49 -> V_51 ) ;
F_25 ( V_49 -> V_51 , V_21 -> V_53 , & V_52 ) ;
if ( V_52 )
return - V_54 ;
V_50 = V_49 -> V_50 ;
V_51 = V_49 -> V_51 ;
V_3 = F_20 ( V_2 , V_55 ) ;
if ( V_3 )
return V_3 ;
if ( V_51 == V_21 -> V_41 ) {
if ( F_18 ( V_2 ) ) {
V_3 = - V_56 ;
goto V_57;
}
} else {
while ( V_51 ) {
if ( V_2 -> V_58 ( V_2 , V_50 ) ) {
V_3 = - V_56 ;
goto V_57;
}
V_50 += V_21 -> V_53 ;
V_51 -= V_21 -> V_53 ;
}
}
F_23 ( V_2 , V_55 ) ;
V_49 -> V_59 = V_60 ;
F_26 ( V_49 ) ;
return V_3 ;
V_57:
F_23 ( V_2 , V_55 ) ;
V_49 -> V_59 = V_61 ;
return V_3 ;
}
static int F_27 ( struct V_20 * V_21 , T_4 V_62 , T_5 V_51 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_3 V_63 = V_62 ;
T_6 V_64 , V_65 ;
int V_3 = 0 ;
V_3 = F_20 ( V_2 , V_66 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_67;
V_64 = F_1 ( V_2 ) ;
if ( V_63 < V_21 -> V_41 - ( V_21 -> V_41 / 2 ) )
V_65 = V_64 | V_68 | V_69 | V_70 ;
else if ( V_63 < V_21 -> V_41 - ( V_21 -> V_41 / 4 ) )
V_65 = ( V_64 & ~ V_70 ) | V_68 | V_69 ;
else if ( V_63 < V_21 -> V_41 - ( V_21 -> V_41 / 8 ) )
V_65 = ( V_64 & ~ V_69 ) | V_68 | V_70 ;
else if ( V_63 < V_21 -> V_41 - ( V_21 -> V_41 / 16 ) )
V_65 = ( V_64 & ~ ( V_70 | V_69 ) ) | V_68 ;
else if ( V_63 < V_21 -> V_41 - ( V_21 -> V_41 / 32 ) )
V_65 = ( V_64 & ~ V_68 ) | V_69 | V_70 ;
else if ( V_63 < V_21 -> V_41 - ( V_21 -> V_41 / 64 ) )
V_65 = ( V_64 & ~ ( V_68 | V_70 ) ) | V_69 ;
else
V_65 = ( V_64 & ~ ( V_68 | V_69 ) ) | V_70 ;
if ( ( V_65 & ( V_68 | V_69 | V_70 ) ) >
( V_64 & ( V_68 | V_69 | V_70 ) ) ) {
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_65 ) ;
if ( V_3 )
goto V_67;
}
V_67:
F_23 ( V_2 , V_66 ) ;
return V_3 ;
}
static int F_28 ( struct V_20 * V_21 , T_4 V_62 , T_5 V_51 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_3 V_63 = V_62 ;
T_6 V_64 , V_65 ;
int V_3 = 0 ;
V_3 = F_20 ( V_2 , V_71 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_67;
V_64 = F_1 ( V_2 ) ;
if ( V_63 + V_51 > V_21 -> V_41 - ( V_21 -> V_41 / 64 ) )
V_65 = V_64 & ~ ( V_68 | V_69 | V_70 ) ;
else if ( V_63 + V_51 > V_21 -> V_41 - ( V_21 -> V_41 / 32 ) )
V_65 = ( V_64 & ~ ( V_68 | V_69 ) ) | V_70 ;
else if ( V_63 + V_51 > V_21 -> V_41 - ( V_21 -> V_41 / 16 ) )
V_65 = ( V_64 & ~ ( V_68 | V_70 ) ) | V_69 ;
else if ( V_63 + V_51 > V_21 -> V_41 - ( V_21 -> V_41 / 8 ) )
V_65 = ( V_64 & ~ V_68 ) | V_69 | V_70 ;
else if ( V_63 + V_51 > V_21 -> V_41 - ( V_21 -> V_41 / 4 ) )
V_65 = ( V_64 & ~ ( V_70 | V_69 ) ) | V_68 ;
else if ( V_63 + V_51 > V_21 -> V_41 - ( V_21 -> V_41 / 2 ) )
V_65 = ( V_64 & ~ V_69 ) | V_68 | V_70 ;
else
V_65 = ( V_64 & ~ V_70 ) | V_68 | V_69 ;
if ( ( V_65 & ( V_68 | V_69 | V_70 ) ) <
( V_64 & ( V_68 | V_69 | V_70 ) ) ) {
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_65 ) ;
if ( V_3 )
goto V_67;
}
V_67:
F_23 ( V_2 , V_71 ) ;
return V_3 ;
}
static const struct V_72 * F_29 ( struct V_1 * V_2 )
{
int V_73 ;
T_1 V_74 [ 5 ] ;
T_2 V_75 ;
T_7 V_76 ;
struct V_77 * V_78 ;
V_73 = V_2 -> V_5 ( V_2 , V_79 , V_74 , 5 ) ;
if ( V_73 < 0 ) {
F_19 ( V_2 -> V_9 , L_7 , V_73 ) ;
return F_30 ( V_73 ) ;
}
V_75 = V_74 [ 0 ] ;
V_75 = V_75 << 8 ;
V_75 |= V_74 [ 1 ] ;
V_75 = V_75 << 8 ;
V_75 |= V_74 [ 2 ] ;
V_76 = V_74 [ 3 ] << 8 | V_74 [ 4 ] ;
for ( V_73 = 0 ; V_73 < F_31 ( V_80 ) - 1 ; V_73 ++ ) {
V_78 = ( void * ) V_80 [ V_73 ] . V_81 ;
if ( V_78 -> V_23 == V_75 ) {
if ( V_78 -> V_82 == 0 || V_78 -> V_82 == V_76 )
return & V_80 [ V_73 ] ;
}
}
F_5 ( V_2 -> V_9 , L_8 , V_75 ) ;
return F_30 ( - V_83 ) ;
}
static const struct V_72 * F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_84 ( V_2 ) ;
}
static int F_33 ( struct V_20 * V_21 , T_4 V_85 , T_8 V_51 ,
T_8 * V_86 , T_9 * V_87 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_19 ( V_2 -> V_9 , L_9 , ( T_2 ) V_85 , V_51 ) ;
V_3 = F_20 ( V_2 , V_88 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_89 ( V_2 , V_85 , V_51 , V_86 , V_87 ) ;
F_23 ( V_2 , V_88 ) ;
return V_3 ;
}
static int F_34 ( struct V_20 * V_21 , T_4 V_90 , T_8 V_51 ,
T_8 * V_86 , const T_9 * V_87 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_8 V_91 ;
int V_3 ;
F_19 ( V_2 -> V_9 , L_10 , ( T_2 ) V_90 , V_51 ) ;
V_3 = F_20 ( V_2 , V_92 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_93;
F_8 ( V_2 ) ;
V_2 -> V_94 = false ;
V_91 = V_90 % 2 ;
if ( V_91 ) {
V_2 -> V_95 = V_96 ;
V_2 -> V_97 ( V_2 , V_90 , 1 , V_86 , V_87 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_93;
}
V_90 += V_91 ;
for (; V_91 < V_51 - 1 ; V_91 += 2 ) {
V_2 -> V_95 = V_98 ;
V_2 -> V_97 ( V_2 , V_90 , 2 , V_86 , V_87 + V_91 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_93;
V_90 += 2 ;
V_2 -> V_94 = true ;
}
V_2 -> V_94 = false ;
F_9 ( V_2 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_93;
if ( V_91 != V_51 ) {
F_8 ( V_2 ) ;
V_2 -> V_95 = V_96 ;
V_2 -> V_97 ( V_2 , V_90 , 1 , V_86 , V_87 + V_91 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_93;
F_9 ( V_2 ) ;
}
V_93:
F_23 ( V_2 , V_92 ) ;
return V_3 ;
}
static int F_35 ( struct V_20 * V_21 , T_4 V_90 , T_8 V_51 ,
T_8 * V_86 , const T_9 * V_87 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_99 , V_100 , V_101 ;
int V_3 ;
F_19 ( V_2 -> V_9 , L_10 , ( T_2 ) V_90 , V_51 ) ;
V_3 = F_20 ( V_2 , V_92 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 )
goto V_102;
F_8 ( V_2 ) ;
V_99 = V_90 & ( V_2 -> V_100 - 1 ) ;
if ( V_99 + V_51 <= V_2 -> V_100 ) {
V_2 -> V_97 ( V_2 , V_90 , V_51 , V_86 , V_87 ) ;
} else {
V_100 = V_2 -> V_100 - V_99 ;
V_2 -> V_97 ( V_2 , V_90 , V_100 , V_86 , V_87 ) ;
for ( V_101 = V_100 ; V_101 < V_51 ; V_101 += V_100 ) {
V_100 = V_51 - V_101 ;
if ( V_100 > V_2 -> V_100 )
V_100 = V_2 -> V_100 ;
F_17 ( V_2 ) ;
F_8 ( V_2 ) ;
V_2 -> V_97 ( V_2 , V_90 + V_101 , V_100 , V_86 , V_87 + V_101 ) ;
}
}
V_102:
F_23 ( V_2 , V_92 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 | V_103 ;
V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 , 0 ) ;
if ( F_17 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_103 ) ) ) {
F_5 ( V_2 -> V_9 , L_11 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_7 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 & 0xff ;
V_2 -> V_15 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 2 , 0 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_3 ;
int V_104 = V_105 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_37 ( V_2 , V_104 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_12 ) ;
return - V_54 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_105 ) ) ) {
F_5 ( V_2 -> V_9 , L_13 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 V_23 )
{
int V_25 ;
switch ( F_12 ( V_23 ) ) {
case V_29 :
V_25 = F_36 ( V_2 ) ;
if ( V_25 ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_54 ;
}
return V_25 ;
default:
V_25 = F_38 ( V_2 ) ;
if ( V_25 ) {
F_5 ( V_2 -> V_9 , L_15 ) ;
return - V_54 ;
}
return V_25 ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_89 || ! V_2 -> V_97 ||
! V_2 -> V_5 || ! V_2 -> V_16 || ! V_2 -> V_58 ) {
F_2 ( L_16 ) ;
return - V_54 ;
}
if ( ! V_2 -> V_84 )
V_2 -> V_84 = F_29 ;
if ( ! V_2 -> F_17 )
V_2 -> F_17 = F_13 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , const struct V_72 * V_74 ,
enum V_106 V_107 )
{
struct V_77 * V_78 ;
struct V_108 * V_109 ;
struct V_110 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_111 * V_112 = V_9 -> V_113 ;
int V_3 ;
int V_101 ;
V_3 = F_40 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_109 = F_42 ( V_9 ) ;
if ( V_109 && V_109 -> type ) {
const struct V_72 * V_114 ;
for ( V_101 = 0 ; V_101 < F_31 ( V_80 ) - 1 ; V_101 ++ ) {
V_114 = & V_80 [ V_101 ] ;
if ( strcmp ( V_109 -> type , V_114 -> V_115 ) )
continue;
break;
}
if ( V_101 < F_31 ( V_80 ) - 1 )
V_74 = V_114 ;
else
F_43 ( V_9 , L_17 , V_109 -> type ) ;
}
V_78 = ( void * ) V_74 -> V_81 ;
if ( V_78 -> V_23 ) {
const struct V_72 * V_116 ;
V_116 = F_32 ( V_2 ) ;
if ( F_44 ( V_116 ) ) {
return F_45 ( V_116 ) ;
} else if ( V_116 != V_74 ) {
F_43 ( V_9 , L_18 ,
V_116 -> V_115 , V_74 -> V_115 ) ;
V_74 = V_116 ;
V_78 = ( void * ) V_116 -> V_81 ;
}
}
F_46 ( & V_2 -> V_45 ) ;
if ( F_12 ( V_78 -> V_23 ) == V_117 ||
F_12 ( V_78 -> V_23 ) == V_118 ||
F_12 ( V_78 -> V_23 ) == V_119 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
}
if ( V_109 && V_109 -> V_115 )
V_21 -> V_115 = V_109 -> V_115 ;
else
V_21 -> V_115 = F_47 ( V_9 ) ;
V_21 -> type = V_120 ;
V_21 -> V_121 = 1 ;
V_21 -> V_122 = V_123 ;
V_21 -> V_41 = V_78 -> V_124 * V_78 -> V_125 ;
V_21 -> V_126 = F_24 ;
V_21 -> V_127 = F_33 ;
if ( F_12 ( V_78 -> V_23 ) == V_28 ) {
V_21 -> V_128 = F_27 ;
V_21 -> V_129 = F_28 ;
}
if ( V_78 -> V_122 & V_130 )
V_21 -> V_131 = F_34 ;
else
V_21 -> V_131 = F_35 ;
if ( ( V_78 -> V_122 & V_132 ) &&
V_2 -> F_17 == F_13 )
V_2 -> F_17 = F_16 ;
if ( V_78 -> V_122 & V_133 ) {
V_2 -> V_134 = V_135 ;
V_21 -> V_53 = 4096 ;
} else if ( V_78 -> V_122 & V_136 ) {
V_2 -> V_134 = V_137 ;
V_21 -> V_53 = 4096 ;
} else {
V_2 -> V_134 = V_138 ;
V_21 -> V_53 = V_78 -> V_124 ;
}
if ( V_78 -> V_122 & V_139 )
V_21 -> V_122 |= V_140 ;
V_21 -> V_9 . V_141 = V_9 ;
V_2 -> V_100 = V_78 -> V_100 ;
V_21 -> V_142 = V_2 -> V_100 ;
if ( V_112 ) {
if ( F_48 ( V_112 , L_19 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_78 -> V_122 & V_143 )
V_2 -> V_10 = V_14 ;
if ( V_107 == V_13 && V_78 -> V_122 & V_144 ) {
V_3 = F_39 ( V_2 , V_78 -> V_23 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_20 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_107 == V_12 && V_78 -> V_122 & V_145 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_146 = V_147 ;
break;
case V_12 :
V_2 -> V_146 = V_148 ;
break;
case V_11 :
V_2 -> V_146 = V_149 ;
break;
case V_14 :
V_2 -> V_146 = V_150 ;
break;
default:
F_5 ( V_9 , L_21 ) ;
return - V_54 ;
}
V_2 -> V_95 = V_151 ;
if ( V_78 -> V_152 )
V_2 -> V_152 = V_78 -> V_152 ;
else if ( V_21 -> V_41 > 0x1000000 ) {
V_2 -> V_152 = 4 ;
if ( F_12 ( V_78 -> V_23 ) == V_153 ) {
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_146 = V_154 ;
break;
case V_12 :
V_2 -> V_146 = V_155 ;
break;
case V_11 :
V_2 -> V_146 = V_156 ;
break;
case V_14 :
V_2 -> V_146 = V_157 ;
break;
}
V_2 -> V_95 = V_158 ;
V_2 -> V_134 = V_159 ;
V_21 -> V_53 = V_78 -> V_124 ;
} else
F_11 ( V_2 , V_78 -> V_23 , 1 ) ;
} else {
V_2 -> V_152 = 3 ;
}
V_2 -> V_160 = F_6 ( V_2 ) ;
F_49 ( V_9 , L_22 , V_74 -> V_115 ,
( long long ) V_21 -> V_41 >> 10 ) ;
F_19 ( V_9 ,
L_23
L_24 ,
V_21 -> V_115 , ( long long ) V_21 -> V_41 , ( long long ) ( V_21 -> V_41 >> 20 ) ,
V_21 -> V_53 , V_21 -> V_53 / 1024 , V_21 -> V_161 ) ;
if ( V_21 -> V_161 )
for ( V_101 = 0 ; V_101 < V_21 -> V_161 ; V_101 ++ )
F_19 ( V_9 ,
L_25
L_26
L_27 ,
V_101 , ( long long ) V_21 -> V_162 [ V_101 ] . V_63 ,
V_21 -> V_162 [ V_101 ] . V_53 ,
V_21 -> V_162 [ V_101 ] . V_53 / 1024 ,
V_21 -> V_162 [ V_101 ] . V_163 ) ;
return 0 ;
}
const struct V_72 * F_50 ( char * V_115 )
{
const struct V_72 * V_74 = V_80 ;
while ( V_74 -> V_115 [ 0 ] ) {
if ( ! strcmp ( V_115 , V_74 -> V_115 ) )
return V_74 ;
V_74 ++ ;
}
return NULL ;
}
