static inline int F_1 ( struct V_1 * V_2 ,
const char * V_3 , unsigned line )
{
if ( V_2 -> V_4 )
return 1 ;
ERROR ( V_2 , L_1 , V_3 , line ) ;
F_2 ( 1 ) ;
return 0 ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_4 ( V_7 , struct V_5 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_9 > V_10 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 , unsigned int V_13 )
{
unsigned int V_14 ;
V_12 -> V_15 = V_13 ;
V_14 = V_13 % V_2 -> V_16 ;
if ( V_14 > 0 )
V_13 += V_2 -> V_16 - V_14 ;
V_12 -> V_17 -> V_13 = V_13 ;
}
static int F_7 ( struct V_5 * V_4 , struct V_18 * V_19 )
{
const char * V_20 ;
if ( V_19 == V_4 -> V_21 )
V_20 = L_2 ;
else if ( V_19 == V_4 -> V_22 )
V_20 = L_3 ;
else
V_20 = V_19 -> V_20 ;
F_8 ( V_4 , L_4 , V_20 ) ;
return F_9 ( V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 () ;
V_2 -> V_23 = 1 ;
if ( V_2 -> V_24 )
F_12 ( V_2 -> V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 , enum V_25 V_26 )
{
unsigned long V_27 ;
F_14 ( & V_2 -> V_28 , V_27 ) ;
if ( V_2 -> V_9 <= V_26 ) {
V_2 -> V_29 = V_2 -> V_30 ;
V_2 -> V_9 = V_26 ;
if ( V_2 -> V_24 )
F_15 ( V_31 , V_32 ,
V_2 -> V_24 ) ;
}
F_16 ( & V_2 -> V_28 , V_27 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_18 ( V_2 -> V_34 , V_2 -> V_35 , V_36 ) ;
V_2 -> V_34 -> V_37 = V_2 ;
if ( V_33 != 0 && V_33 != - V_38 ) {
F_19 ( V_2 , L_5 ,
V_2 -> V_34 -> V_20 , V_33 ) ;
}
return V_33 ;
}
static void F_20 ( struct V_18 * V_19 , struct V_39 * V_40 )
{
struct V_1 * V_2 = V_19 -> V_37 ;
struct V_11 * V_12 = V_40 -> V_41 ;
if ( V_40 -> V_42 || V_40 -> V_43 != V_40 -> V_13 )
F_8 ( V_2 , L_6 , V_44 ,
V_40 -> V_42 , V_40 -> V_43 , V_40 -> V_13 ) ;
if ( V_40 -> V_42 == - V_45 )
F_21 ( V_19 ) ;
F_11 () ;
F_22 ( & V_2 -> V_28 ) ;
V_12 -> V_46 = 0 ;
V_12 -> V_9 = V_47 ;
F_10 ( V_2 ) ;
F_23 ( & V_2 -> V_28 ) ;
}
static void F_24 ( struct V_18 * V_19 , struct V_39 * V_40 )
{
struct V_1 * V_2 = V_19 -> V_37 ;
struct V_11 * V_12 = V_40 -> V_41 ;
F_25 ( V_2 , L_3 , V_40 -> V_48 , V_40 -> V_43 ) ;
if ( V_40 -> V_42 || V_40 -> V_43 != V_12 -> V_15 )
F_8 ( V_2 , L_6 , V_44 ,
V_40 -> V_42 , V_40 -> V_43 , V_12 -> V_15 ) ;
if ( V_40 -> V_42 == - V_45 )
F_21 ( V_19 ) ;
F_11 () ;
F_22 ( & V_2 -> V_28 ) ;
V_12 -> V_49 = 0 ;
V_12 -> V_9 = V_50 ;
F_10 ( V_2 ) ;
F_23 ( & V_2 -> V_28 ) ;
}
static int F_26 ( struct V_6 * V_7 ,
const struct V_51 * V_52 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_39 * V_40 = V_4 -> V_2 -> V_35 ;
T_1 V_53 = F_27 ( V_52 -> V_54 ) ;
T_1 V_55 = F_27 ( V_52 -> V_56 ) ;
T_1 V_57 = F_27 ( V_52 -> V_58 ) ;
if ( ! F_28 ( V_4 -> V_2 ) )
return - V_59 ;
++ V_4 -> V_2 -> V_30 ;
V_40 -> V_41 = NULL ;
V_40 -> V_13 = 0 ;
F_25 ( V_4 , L_7 , ( V_60 * ) V_52 , sizeof( * V_52 ) ) ;
switch ( V_52 -> V_61 ) {
case V_62 :
if ( V_52 -> V_63 !=
( V_64 | V_65 | V_66 ) )
break;
if ( V_53 != V_4 -> V_67 || V_55 != 0 ||
V_57 != 0 )
return - V_68 ;
F_8 ( V_4 , L_8 ) ;
F_13 ( V_4 -> V_2 , V_69 ) ;
return V_70 ;
case V_71 :
if ( V_52 -> V_63 !=
( V_72 | V_65 | V_66 ) )
break;
if ( V_53 != V_4 -> V_67 || V_55 != 0 ||
V_57 != 1 )
return - V_68 ;
F_29 ( V_4 , L_9 ) ;
* ( V_60 * ) V_40 -> V_48 = V_4 -> V_2 -> V_73 - 1 ;
V_40 -> V_13 = F_30 ( ( T_1 ) 1 , V_57 ) ;
return F_17 ( V_4 -> V_2 ) ;
}
F_29 ( V_4 ,
L_10 ,
V_52 -> V_63 , V_52 -> V_61 ,
F_27 ( V_52 -> V_56 ) , V_53 , V_57 ) ;
return - V_59 ;
}
static void F_31 ( struct V_5 * V_4 , struct V_18 * V_19 ,
struct V_39 * V_40 , int * V_74 ,
enum V_75 * V_9 )
{
int V_33 ;
if ( V_19 == V_4 -> V_21 )
F_25 ( V_4 , L_2 , V_40 -> V_48 , V_40 -> V_13 ) ;
F_32 ( & V_4 -> V_2 -> V_28 ) ;
* V_74 = 1 ;
* V_9 = V_76 ;
F_33 ( & V_4 -> V_2 -> V_28 ) ;
V_33 = F_18 ( V_19 , V_40 , V_77 ) ;
if ( V_33 != 0 ) {
* V_74 = 0 ;
* V_9 = V_47 ;
if ( V_33 != - V_38 &&
! ( V_33 == - V_59 && V_40 -> V_13 == 0 ) )
F_19 ( V_4 , L_5 ,
V_19 -> V_20 , V_33 ) ;
}
}
static bool F_34 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_28 ( V_2 ) )
return false ;
F_31 ( V_2 -> V_4 , V_2 -> V_4 -> V_21 ,
V_12 -> V_78 , & V_12 -> V_46 , & V_12 -> V_9 ) ;
return true ;
}
static bool F_35 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_28 ( V_2 ) )
return false ;
F_31 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ,
V_12 -> V_17 , & V_12 -> V_49 , & V_12 -> V_9 ) ;
return true ;
}
static int F_36 ( struct V_1 * V_2 , bool V_79 )
{
int V_33 = 0 ;
for (; ; ) {
if ( V_79 )
F_37 () ;
F_38 ( V_80 ) ;
if ( F_39 ( V_81 ) ) {
V_33 = - V_82 ;
break;
}
if ( V_2 -> V_23 )
break;
F_40 () ;
}
F_41 ( V_83 ) ;
V_2 -> V_23 = 0 ;
F_42 () ;
return V_33 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
T_2 V_86 ;
struct V_11 * V_12 ;
int V_33 ;
T_2 V_87 ;
T_3 V_88 , V_89 ;
unsigned int V_90 ;
T_4 V_91 ;
if ( V_2 -> V_92 [ 0 ] == V_93 )
V_86 = F_44 ( & V_2 -> V_92 [ 1 ] ) ;
else {
V_86 = F_45 ( & V_2 -> V_92 [ 2 ] ) ;
if ( ( V_2 -> V_92 [ 1 ] & ~ 0x18 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
}
if ( V_86 >= V_85 -> V_97 ) {
V_85 -> V_94 = V_98 ;
return - V_96 ;
}
V_88 = ( ( T_3 ) V_86 ) << V_85 -> V_99 ;
V_87 = V_2 -> V_100 ;
if ( F_46 ( V_87 == 0 ) )
return - V_101 ;
for (; ; ) {
V_90 = F_30 ( V_87 , V_102 ) ;
V_90 = F_30 ( ( T_3 ) V_90 ,
V_85 -> V_103 - V_88 ) ;
V_12 = V_2 -> V_104 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_36 ( V_2 , false ) ;
if ( V_33 )
return V_33 ;
}
if ( V_90 == 0 ) {
V_85 -> V_94 =
V_98 ;
V_85 -> V_105 =
V_88 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
V_12 -> V_78 -> V_13 = 0 ;
V_12 -> V_9 = V_50 ;
break;
}
V_89 = V_88 ;
V_91 = F_47 ( V_85 -> V_107 ,
( char V_108 * ) V_12 -> V_48 ,
V_90 , & V_89 ) ;
F_48 ( V_85 , L_11 , V_90 ,
( unsigned long long ) V_88 , ( int ) V_91 ) ;
if ( F_39 ( V_81 ) )
return - V_82 ;
if ( V_91 < 0 ) {
F_49 ( V_85 , L_12 , ( int ) V_91 ) ;
V_91 = 0 ;
} else if ( V_91 < V_90 ) {
F_49 ( V_85 , L_13 ,
( int ) V_91 , V_90 ) ;
V_91 = F_50 ( V_91 , V_85 -> V_109 ) ;
}
V_88 += V_91 ;
V_87 -= V_91 ;
V_2 -> V_110 -= V_91 ;
V_12 -> V_78 -> V_13 = V_91 ;
V_12 -> V_9 = V_50 ;
if ( V_91 < V_90 ) {
V_85 -> V_94 = V_111 ;
V_85 -> V_105 =
V_88 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
break;
}
if ( V_87 == 0 )
break;
V_12 -> V_78 -> V_112 = 0 ;
if ( ! F_34 ( V_2 , V_12 ) )
return - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
}
return - V_101 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
T_2 V_86 ;
struct V_11 * V_12 ;
int V_114 ;
T_2 V_115 , V_116 ;
T_3 V_117 , V_88 , V_89 ;
unsigned int V_90 ;
T_4 V_118 ;
int V_33 ;
if ( V_85 -> V_119 ) {
V_85 -> V_94 = V_120 ;
return - V_96 ;
}
F_22 ( & V_85 -> V_107 -> V_121 ) ;
V_85 -> V_107 -> V_122 &= ~ V_123 ;
F_23 ( & V_85 -> V_107 -> V_121 ) ;
if ( V_2 -> V_92 [ 0 ] == V_124 )
V_86 = F_44 ( & V_2 -> V_92 [ 1 ] ) ;
else {
V_86 = F_45 ( & V_2 -> V_92 [ 2 ] ) ;
if ( V_2 -> V_92 [ 1 ] & ~ 0x18 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
if ( ! V_85 -> V_125 && ( V_2 -> V_92 [ 1 ] & 0x08 ) ) {
F_22 ( & V_85 -> V_107 -> V_121 ) ;
V_85 -> V_107 -> V_122 |= V_123 ;
F_23 ( & V_85 -> V_107 -> V_121 ) ;
}
}
if ( V_86 >= V_85 -> V_97 ) {
V_85 -> V_94 = V_98 ;
return - V_96 ;
}
V_114 = 1 ;
V_88 = V_117 = ( ( T_3 ) V_86 ) << V_85 -> V_99 ;
V_115 = V_2 -> V_100 ;
V_116 = V_2 -> V_100 ;
while ( V_116 > 0 ) {
V_12 = V_2 -> V_104 ;
if ( V_12 -> V_9 == V_47 && V_114 ) {
V_90 = F_30 ( V_115 , V_102 ) ;
if ( V_117 >= V_85 -> V_103 ) {
V_114 = 0 ;
V_85 -> V_94 =
V_98 ;
V_85 -> V_105 =
V_117 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
continue;
}
V_117 += V_90 ;
V_2 -> V_126 -= V_90 ;
V_115 -= V_90 ;
if ( V_115 == 0 )
V_114 = 0 ;
F_6 ( V_2 , V_12 , V_90 ) ;
if ( ! F_35 ( V_2 , V_12 ) )
return - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
continue;
}
V_12 = V_2 -> V_127 ;
if ( V_12 -> V_9 == V_47 && ! V_114 )
break;
if ( V_12 -> V_9 == V_50 ) {
F_42 () ;
V_2 -> V_127 = V_12 -> V_113 ;
V_12 -> V_9 = V_47 ;
if ( V_12 -> V_17 -> V_42 != 0 ) {
V_85 -> V_94 = V_128 ;
V_85 -> V_105 =
V_88 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
break;
}
V_90 = V_12 -> V_17 -> V_43 ;
if ( V_85 -> V_103 - V_88 < V_90 ) {
F_52 ( V_85 ,
L_14 ,
V_90 , ( unsigned long long ) V_88 ,
( unsigned long long ) V_85 -> V_103 ) ;
V_90 = V_85 -> V_103 - V_88 ;
}
V_90 = F_30 ( V_90 , V_12 -> V_15 ) ;
V_90 = F_50 ( V_90 , V_85 -> V_109 ) ;
if ( V_90 == 0 )
goto V_129;
V_89 = V_88 ;
V_118 = F_53 ( V_85 -> V_107 ,
( char V_108 * ) V_12 -> V_48 ,
V_90 , & V_89 ) ;
F_48 ( V_85 , L_15 , V_90 ,
( unsigned long long ) V_88 , ( int ) V_118 ) ;
if ( F_39 ( V_81 ) )
return - V_82 ;
if ( V_118 < 0 ) {
F_49 ( V_85 , L_16 ,
( int ) V_118 ) ;
V_118 = 0 ;
} else if ( V_118 < V_90 ) {
F_49 ( V_85 , L_17 ,
( int ) V_118 , V_90 ) ;
V_118 = F_50 ( V_118 , V_85 -> V_109 ) ;
}
V_88 += V_118 ;
V_116 -= V_118 ;
V_2 -> V_110 -= V_118 ;
if ( V_118 < V_90 ) {
V_85 -> V_94 = V_130 ;
V_85 -> V_105 =
V_88 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
break;
}
V_129:
if ( V_12 -> V_17 -> V_43 < V_12 -> V_15 ) {
V_2 -> V_131 = 1 ;
break;
}
continue;
}
V_33 = F_36 ( V_2 , false ) ;
if ( V_33 )
return V_33 ;
}
return - V_101 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_33 ;
V_33 = F_55 ( V_85 ) ;
if ( V_33 )
V_85 -> V_94 = V_130 ;
return 0 ;
}
static void F_56 ( struct V_84 * V_85 )
{
struct V_132 * V_107 = V_85 -> V_107 ;
struct V_133 * V_133 = F_57 ( V_107 ) ;
unsigned long V_33 ;
V_33 = F_58 ( V_133 -> V_134 , 0 , - 1 ) ;
F_48 ( V_85 , L_18 , V_33 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
T_2 V_86 ;
T_2 V_135 ;
struct V_11 * V_12 = V_2 -> V_104 ;
T_3 V_88 , V_89 ;
T_2 V_87 ;
unsigned int V_90 ;
T_4 V_91 ;
V_86 = F_45 ( & V_2 -> V_92 [ 2 ] ) ;
if ( V_86 >= V_85 -> V_97 ) {
V_85 -> V_94 = V_98 ;
return - V_96 ;
}
if ( V_2 -> V_92 [ 1 ] & ~ 0x10 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
V_135 = F_60 ( & V_2 -> V_92 [ 7 ] ) ;
if ( F_46 ( V_135 == 0 ) )
return - V_101 ;
V_87 = V_135 << V_85 -> V_99 ;
V_88 = ( ( T_3 ) V_86 ) << V_85 -> V_99 ;
F_55 ( V_85 ) ;
if ( F_39 ( V_81 ) )
return - V_82 ;
F_56 ( V_85 ) ;
if ( F_39 ( V_81 ) )
return - V_82 ;
while ( V_87 > 0 ) {
V_90 = F_30 ( V_87 , V_102 ) ;
V_90 = F_30 ( ( T_3 ) V_90 ,
V_85 -> V_103 - V_88 ) ;
if ( V_90 == 0 ) {
V_85 -> V_94 =
V_98 ;
V_85 -> V_105 =
V_88 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
break;
}
V_89 = V_88 ;
V_91 = F_47 ( V_85 -> V_107 ,
( char V_108 * ) V_12 -> V_48 ,
V_90 , & V_89 ) ;
F_48 ( V_85 , L_11 , V_90 ,
( unsigned long long ) V_88 ,
( int ) V_91 ) ;
if ( F_39 ( V_81 ) )
return - V_82 ;
if ( V_91 < 0 ) {
F_49 ( V_85 , L_19 , ( int ) V_91 ) ;
V_91 = 0 ;
} else if ( V_91 < V_90 ) {
F_49 ( V_85 , L_20 ,
( int ) V_91 , V_90 ) ;
V_91 = F_50 ( V_91 , V_85 -> V_109 ) ;
}
if ( V_91 == 0 ) {
V_85 -> V_94 = V_111 ;
V_85 -> V_105 =
V_88 >> V_85 -> V_99 ;
V_85 -> V_106 = 1 ;
break;
}
V_88 += V_91 ;
V_87 -= V_91 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
if ( ! V_85 ) {
V_2 -> V_136 = 1 ;
memset ( V_48 , 0 , 36 ) ;
V_48 [ 0 ] = 0x7f ;
V_48 [ 4 ] = 31 ;
return 36 ;
}
V_48 [ 0 ] = V_85 -> V_137 ? V_138 : V_139 ;
V_48 [ 1 ] = V_85 -> V_140 ? 0x80 : 0 ;
V_48 [ 2 ] = 2 ;
V_48 [ 3 ] = 2 ;
V_48 [ 4 ] = 31 ;
V_48 [ 5 ] = 0 ;
V_48 [ 6 ] = 0 ;
V_48 [ 7 ] = 0 ;
memcpy ( V_48 + 8 , V_2 -> V_141 , sizeof V_2 -> V_141 ) ;
return 36 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
T_2 V_142 , V_143 ;
int V_144 ;
#if 0
if (curlun && curlun->unit_attention_data != SS_NO_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
}
#endif
if ( ! V_85 ) {
V_2 -> V_136 = 1 ;
V_142 = V_145 ;
V_143 = 0 ;
V_144 = 0 ;
} else {
V_142 = V_85 -> V_94 ;
V_143 = V_85 -> V_105 ;
V_144 = V_85 -> V_106 << 7 ;
V_85 -> V_94 = V_146 ;
V_85 -> V_105 = 0 ;
V_85 -> V_106 = 0 ;
}
memset ( V_48 , 0 , 18 ) ;
V_48 [ 0 ] = V_144 | 0x70 ;
V_48 [ 2 ] = F_63 ( V_142 ) ;
F_64 ( V_143 , & V_48 [ 3 ] ) ;
V_48 [ 7 ] = 18 - 8 ;
V_48 [ 12 ] = F_65 ( V_142 ) ;
V_48 [ 13 ] = F_66 ( V_142 ) ;
return 18 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
T_2 V_86 = F_45 ( & V_2 -> V_92 [ 2 ] ) ;
int V_147 = V_2 -> V_92 [ 8 ] ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
if ( V_147 > 1 || ( V_147 == 0 && V_86 != 0 ) ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
F_64 ( V_85 -> V_97 - 1 , & V_48 [ 0 ] ) ;
F_64 ( V_85 -> V_109 , & V_48 [ 4 ] ) ;
return 8 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_148 = V_2 -> V_92 [ 1 ] & 0x02 ;
T_2 V_86 = F_45 ( & V_2 -> V_92 [ 2 ] ) ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
if ( V_2 -> V_92 [ 1 ] & ~ 0x02 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
if ( V_86 >= V_85 -> V_97 ) {
V_85 -> V_94 = V_98 ;
return - V_96 ;
}
memset ( V_48 , 0 , 8 ) ;
V_48 [ 0 ] = 0x01 ;
F_69 ( & V_48 [ 4 ] , V_148 , V_86 ) ;
return 8 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_148 = V_2 -> V_92 [ 1 ] & 0x02 ;
int V_149 = V_2 -> V_92 [ 6 ] ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
if ( ( V_2 -> V_92 [ 1 ] & ~ 0x02 ) != 0 ||
V_149 > 1 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
memset ( V_48 , 0 , 20 ) ;
V_48 [ 1 ] = ( 20 - 2 ) ;
V_48 [ 2 ] = 1 ;
V_48 [ 3 ] = 1 ;
V_48 [ 5 ] = 0x16 ;
V_48 [ 6 ] = 0x01 ;
F_69 ( & V_48 [ 8 ] , V_148 , 0 ) ;
V_48 [ 13 ] = 0x16 ;
V_48 [ 14 ] = 0xAA ;
F_69 ( & V_48 [ 16 ] , V_148 , V_85 -> V_97 ) ;
return 20 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_150 = V_2 -> V_92 [ 0 ] ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
V_60 * V_151 = V_48 ;
int V_152 , V_153 ;
int V_154 , V_155 ;
int V_156 = 0 ;
int V_157 , V_158 ;
if ( ( V_2 -> V_92 [ 1 ] & ~ 0x08 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
V_152 = V_2 -> V_92 [ 2 ] >> 6 ;
V_153 = V_2 -> V_92 [ 2 ] & 0x3f ;
if ( V_152 == 3 ) {
V_85 -> V_94 = V_159 ;
return - V_96 ;
}
V_154 = ( V_152 == 1 ) ;
V_155 = ( V_153 == 0x3f ) ;
memset ( V_48 , 0 , 8 ) ;
if ( V_150 == V_160 ) {
V_48 [ 2 ] = ( V_85 -> V_119 ? 0x80 : 0x00 ) ;
V_48 += 4 ;
V_158 = 255 ;
} else {
V_48 [ 3 ] = ( V_85 -> V_119 ? 0x80 : 0x00 ) ;
V_48 += 8 ;
V_158 = 65535 ;
}
if ( V_153 == 0x08 || V_155 ) {
V_156 = 1 ;
V_48 [ 0 ] = 0x08 ;
V_48 [ 1 ] = 10 ;
memset ( V_48 + 2 , 0 , 10 ) ;
if ( ! V_154 ) {
V_48 [ 2 ] = 0x04 ;
F_72 ( 0xffff , & V_48 [ 4 ] ) ;
F_72 ( 0xffff , & V_48 [ 8 ] ) ;
F_72 ( 0xffff , & V_48 [ 10 ] ) ;
}
V_48 += 12 ;
}
V_157 = V_48 - V_151 ;
if ( ! V_156 || V_157 > V_158 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
if ( V_150 == V_160 )
V_151 [ 0 ] = V_157 - 1 ;
else
F_72 ( V_157 - 2 , V_151 ) ;
return V_157 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_161 , V_162 ;
if ( ! V_85 ) {
return - V_96 ;
} else if ( ! V_85 -> V_140 ) {
V_85 -> V_94 = V_163 ;
return - V_96 ;
} else if ( ( V_2 -> V_92 [ 1 ] & ~ 0x01 ) != 0 ||
( V_2 -> V_92 [ 4 ] & ~ 0x03 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
V_161 = V_2 -> V_92 [ 4 ] & 0x02 ;
V_162 = V_2 -> V_92 [ 4 ] & 0x01 ;
if ( V_162 ) {
if ( ! F_74 ( V_85 ) ) {
V_85 -> V_94 = V_164 ;
return - V_96 ;
}
return 0 ;
}
if ( V_85 -> V_165 ) {
F_49 ( V_85 , L_21 ) ;
V_85 -> V_94 = V_166 ;
return - V_96 ;
}
if ( ! V_161 )
return 0 ;
F_75 ( & V_2 -> V_167 ) ;
F_76 ( & V_2 -> V_167 ) ;
F_77 ( V_85 ) ;
F_78 ( & V_2 -> V_167 ) ;
F_79 ( & V_2 -> V_167 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_168 ;
if ( ! V_2 -> V_85 ) {
return - V_96 ;
} else if ( ! V_2 -> V_85 -> V_140 ) {
V_2 -> V_85 -> V_94 = V_163 ;
return - V_96 ;
}
V_168 = V_2 -> V_92 [ 4 ] & 0x01 ;
if ( ( V_2 -> V_92 [ 4 ] & ~ 0x01 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
if ( V_85 -> V_165 && ! V_168 )
F_55 ( V_85 ) ;
V_85 -> V_165 = V_168 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
V_48 [ 0 ] = V_48 [ 1 ] = V_48 [ 2 ] = 0 ;
V_48 [ 3 ] = 8 ;
V_48 += 4 ;
F_64 ( V_85 -> V_97 , & V_48 [ 0 ] ) ;
F_64 ( V_85 -> V_109 , & V_48 [ 4 ] ) ;
V_48 [ 4 ] = 0x02 ;
return 12 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
if ( V_85 )
V_85 -> V_94 = V_163 ;
return - V_96 ;
}
static int F_83 ( struct V_5 * V_4 )
{
int V_33 ;
V_33 = F_7 ( V_4 , V_4 -> V_21 ) ;
if ( V_33 == - V_169 )
F_29 ( V_4 , L_22 ) ;
while ( V_33 != 0 ) {
if ( V_33 != - V_169 ) {
F_19 ( V_4 , L_23 , V_33 ) ;
V_33 = 0 ;
break;
}
if ( F_84 ( 100 ) != 0 )
return - V_82 ;
V_33 = F_9 ( V_4 -> V_21 ) ;
}
return V_33 ;
}
static int F_85 ( struct V_5 * V_4 )
{
int V_33 ;
F_8 ( V_4 , L_24 ) ;
V_33 = F_86 ( V_4 -> V_21 ) ;
if ( V_33 == - V_169 )
F_29 ( V_4 , L_25 ) ;
while ( V_33 != 0 ) {
if ( V_33 != - V_169 ) {
F_19 ( V_4 , L_26 , V_33 ) ;
V_33 = 0 ;
break;
}
if ( F_84 ( 100 ) != 0 )
return - V_82 ;
V_33 = F_86 ( V_4 -> V_21 ) ;
}
return V_33 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
T_2 V_90 ;
int V_33 ;
for ( V_12 = V_2 -> V_127 ;
V_12 -> V_9 != V_47 || V_2 -> V_126 > 0 ;
V_12 = V_2 -> V_127 ) {
if ( V_12 -> V_9 == V_50 ) {
F_42 () ;
V_12 -> V_9 = V_47 ;
V_2 -> V_127 = V_12 -> V_113 ;
if ( V_12 -> V_17 -> V_43 < V_12 -> V_15 ||
V_12 -> V_17 -> V_42 != 0 ) {
F_13 ( V_2 ,
V_170 ) ;
return - V_82 ;
}
continue;
}
V_12 = V_2 -> V_104 ;
if ( V_12 -> V_9 == V_47
&& V_2 -> V_126 > 0 ) {
V_90 = F_30 ( V_2 -> V_126 , V_102 ) ;
F_6 ( V_2 , V_12 , V_90 ) ;
if ( ! F_35 ( V_2 , V_12 ) )
return - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
V_2 -> V_126 -= V_90 ;
continue;
}
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_104 ;
int V_33 = 0 ;
switch ( V_2 -> V_171 ) {
case V_172 :
break;
case V_173 :
if ( ! V_2 -> V_174 ) {
} else if ( F_28 ( V_2 ) ) {
F_7 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ) ;
V_33 = F_83 ( V_2 -> V_4 ) ;
} else {
V_33 = - V_101 ;
}
break;
case V_175 :
if ( V_2 -> V_176 == 0 ) {
} else if ( ! F_28 ( V_2 ) ) {
V_33 = - V_101 ;
} else if ( V_2 -> V_110 == 0 ) {
V_12 -> V_78 -> V_112 = 0 ;
if ( ! F_34 ( V_2 , V_12 ) )
return - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
} else {
V_12 -> V_78 -> V_112 = 1 ;
if ( ! F_34 ( V_2 , V_12 ) )
V_33 = - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
if ( V_2 -> V_174 )
V_33 = F_83 ( V_2 -> V_4 ) ;
}
break;
case V_177 :
if ( V_2 -> V_110 == 0 ) {
} else if ( V_2 -> V_131 ) {
F_13 ( V_2 , V_170 ) ;
V_33 = - V_82 ;
#if 0
} else if (common->can_stall) {
if (fsg_is_set(common))
fsg_set_halt(common->fsg,
common->fsg->bulk_out);
raise_exception(common, FSG_STATE_ABORT_BULK_OUT);
rc = -EINTR;
#endif
} else {
V_33 = F_87 ( V_2 ) ;
}
break;
}
return V_33 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
struct V_11 * V_12 ;
struct V_178 * V_179 ;
int V_33 ;
V_60 V_42 = V_180 ;
T_2 V_142 , V_143 = 0 ;
V_12 = V_2 -> V_104 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
if ( V_85 ) {
V_142 = V_85 -> V_94 ;
V_143 = V_85 -> V_105 ;
} else if ( V_2 -> V_136 )
V_142 = V_146 ;
else
V_142 = V_145 ;
if ( V_2 -> V_181 ) {
F_8 ( V_2 , L_27 ) ;
V_42 = V_182 ;
V_142 = V_163 ;
} else if ( V_142 != V_146 ) {
F_8 ( V_2 , L_28 ) ;
V_42 = V_183 ;
F_29 ( V_2 , L_29
L_30 ,
F_63 ( V_142 ) , F_65 ( V_142 ) , F_66 ( V_142 ) , V_143 ) ;
}
V_179 = ( void * ) V_12 -> V_48 ;
V_179 -> V_184 = F_90 ( V_185 ) ;
V_179 -> V_186 = V_2 -> V_187 ;
V_179 -> V_188 = F_90 ( V_2 -> V_110 ) ;
V_179 -> V_189 = V_42 ;
V_12 -> V_78 -> V_13 = V_190 ;
V_12 -> V_78 -> V_112 = 0 ;
if ( ! F_34 ( V_2 , V_12 ) )
return - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , int V_191 ,
enum V_192 V_171 , unsigned int V_193 ,
int V_194 , const char * V_20 )
{
int V_195 ;
unsigned int V_196 = V_2 -> V_92 [ 1 ] >> 5 ;
static const char V_197 [ 4 ] = { 'u' , 'o' , 'i' , 'n' } ;
char V_198 [ 20 ] ;
struct V_84 * V_85 ;
V_198 [ 0 ] = 0 ;
if ( V_2 -> V_171 != V_173 )
sprintf ( V_198 , L_31 , V_197 [ ( int ) V_2 -> V_171 ] ,
V_2 -> V_176 ) ;
F_29 ( V_2 , L_32 ,
V_20 , V_191 , V_197 [ ( int ) V_171 ] ,
V_2 -> V_100 , V_2 -> V_191 , V_198 ) ;
if ( V_2 -> V_100 == 0 )
V_171 = V_172 ;
if ( V_2 -> V_176 < V_2 -> V_100 ) {
V_2 -> V_100 = V_2 -> V_176 ;
V_2 -> V_181 = 1 ;
}
V_2 -> V_110 = V_2 -> V_176 ;
V_2 -> V_126 = V_2 -> V_176 ;
if ( V_2 -> V_171 != V_171 && V_2 -> V_100 > 0 ) {
V_2 -> V_181 = 1 ;
return - V_96 ;
}
if ( V_191 != V_2 -> V_191 ) {
if ( V_191 <= V_2 -> V_191 ) {
F_8 ( V_2 , L_33
L_34 , V_20 ,
V_191 , V_2 -> V_191 ) ;
V_191 = V_2 -> V_191 ;
} else {
V_2 -> V_181 = 1 ;
return - V_96 ;
}
}
if ( V_2 -> V_196 != V_196 )
F_8 ( V_2 , L_35 ,
V_2 -> V_196 , V_196 ) ;
V_85 = V_2 -> V_85 ;
if ( V_85 ) {
if ( V_2 -> V_92 [ 0 ] != V_199 ) {
V_85 -> V_94 = V_146 ;
V_85 -> V_105 = 0 ;
V_85 -> V_106 = 0 ;
}
} else {
V_2 -> V_136 = 0 ;
if ( V_2 -> V_92 [ 0 ] != V_200 &&
V_2 -> V_92 [ 0 ] != V_199 ) {
F_8 ( V_2 , L_36 , V_2 -> V_196 ) ;
return - V_96 ;
}
}
if ( V_85 && V_85 -> V_201 != V_146 &&
V_2 -> V_92 [ 0 ] != V_200 &&
V_2 -> V_92 [ 0 ] != V_199 ) {
V_85 -> V_94 = V_85 -> V_201 ;
V_85 -> V_201 = V_146 ;
return - V_96 ;
}
V_2 -> V_92 [ 1 ] &= 0x1f ;
for ( V_195 = 1 ; V_195 < V_191 ; ++ V_195 ) {
if ( V_2 -> V_92 [ V_195 ] && ! ( V_193 & ( 1 << V_195 ) ) ) {
if ( V_85 )
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
}
if ( V_85 && ! F_74 ( V_85 ) && V_194 ) {
V_85 -> V_94 = V_164 ;
return - V_96 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
int V_191 , enum V_192 V_171 ,
unsigned int V_193 , int V_194 , const char * V_20 )
{
if ( V_2 -> V_85 )
V_2 -> V_100 <<= V_2 -> V_85 -> V_99 ;
return F_91 ( V_2 , V_191 , V_171 ,
V_193 , V_194 , V_20 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_33 ;
int V_202 = - V_96 ;
int V_195 ;
static char V_203 [ 16 ] ;
F_94 ( V_2 ) ;
V_12 = V_2 -> V_104 ;
V_2 -> V_127 = V_12 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
V_2 -> V_181 = 0 ;
V_2 -> V_131 = 0 ;
F_79 ( & V_2 -> V_167 ) ;
switch ( V_2 -> V_92 [ 0 ] ) {
case V_200 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_202 = F_91 ( V_2 , 6 , V_175 ,
( 1 << 4 ) , 0 ,
L_37 ) ;
if ( V_202 == 0 )
V_202 = F_61 ( V_2 , V_12 ) ;
break;
case V_204 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_202 = F_91 ( V_2 , 6 , V_177 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_38 ) ;
if ( V_202 == 0 )
V_202 = F_82 ( V_2 , V_12 ) ;
break;
case V_205 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_91 ( V_2 , 10 , V_177 ,
( 1 << 1 ) | ( 3 << 7 ) , 0 ,
L_39 ) ;
if ( V_202 == 0 )
V_202 = F_82 ( V_2 , V_12 ) ;
break;
case V_160 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_202 = F_91 ( V_2 , 6 , V_175 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) , 0 ,
L_40 ) ;
if ( V_202 == 0 )
V_202 = F_71 ( V_2 , V_12 ) ;
break;
case V_206 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_91 ( V_2 , 10 , V_175 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 3 << 7 ) , 0 ,
L_41 ) ;
if ( V_202 == 0 )
V_202 = F_71 ( V_2 , V_12 ) ;
break;
case V_207 :
V_2 -> V_100 = 0 ;
V_202 = F_91 ( V_2 , 6 , V_172 ,
( 1 << 4 ) , 0 ,
L_42 ) ;
if ( V_202 == 0 )
V_202 = F_80 ( V_2 ) ;
break;
case V_93 :
V_195 = V_2 -> V_92 [ 4 ] ;
V_2 -> V_100 = ( V_195 == 0 ) ? 256 : V_195 ;
V_202 = F_92 ( V_2 , 6 ,
V_175 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_43 ) ;
if ( V_202 == 0 )
V_202 = F_43 ( V_2 ) ;
break;
case V_208 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_92 ( V_2 , 10 ,
V_175 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_44 ) ;
if ( V_202 == 0 )
V_202 = F_43 ( V_2 ) ;
break;
case V_209 :
V_2 -> V_100 =
F_45 ( & V_2 -> V_92 [ 6 ] ) ;
V_202 = F_92 ( V_2 , 12 ,
V_175 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_45 ) ;
if ( V_202 == 0 )
V_202 = F_43 ( V_2 ) ;
break;
case V_210 :
V_2 -> V_100 = 8 ;
V_202 = F_91 ( V_2 , 10 , V_175 ,
( 0xf << 2 ) | ( 1 << 8 ) , 1 ,
L_46 ) ;
if ( V_202 == 0 )
V_202 = F_67 ( V_2 , V_12 ) ;
break;
case V_211 :
if ( ! V_2 -> V_85 || ! V_2 -> V_85 -> V_137 )
goto V_212;
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_91 ( V_2 , 10 , V_175 ,
( 3 << 7 ) | ( 0x1f << 1 ) , 1 ,
L_47 ) ;
if ( V_202 == 0 )
V_202 = F_68 ( V_2 , V_12 ) ;
break;
case V_213 :
if ( ! V_2 -> V_85 || ! V_2 -> V_85 -> V_137 )
goto V_212;
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_91 ( V_2 , 10 , V_175 ,
( 7 << 6 ) | ( 1 << 1 ) , 1 ,
L_48 ) ;
if ( V_202 == 0 )
V_202 = F_70 ( V_2 , V_12 ) ;
break;
case V_214 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_91 ( V_2 , 10 , V_175 ,
( 3 << 7 ) , 1 ,
L_49 ) ;
if ( V_202 == 0 )
V_202 = F_81 ( V_2 , V_12 ) ;
break;
case V_199 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_202 = F_91 ( V_2 , 6 , V_175 ,
( 1 << 4 ) , 0 ,
L_50 ) ;
if ( V_202 == 0 )
V_202 = F_62 ( V_2 , V_12 ) ;
break;
case V_215 :
V_2 -> V_100 = 0 ;
V_202 = F_91 ( V_2 , 6 , V_172 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_51 ) ;
if ( V_202 == 0 )
V_202 = F_73 ( V_2 ) ;
break;
case V_216 :
V_2 -> V_100 = 0 ;
V_202 = F_91 ( V_2 , 10 , V_172 ,
( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_52 ) ;
if ( V_202 == 0 )
V_202 = F_54 ( V_2 ) ;
break;
case V_217 :
V_2 -> V_100 = 0 ;
V_202 = F_91 ( V_2 , 6 , V_172 ,
0 , 1 ,
L_53 ) ;
break;
case V_218 :
V_2 -> V_100 = 0 ;
V_202 = F_91 ( V_2 , 10 , V_172 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_54 ) ;
if ( V_202 == 0 )
V_202 = F_59 ( V_2 ) ;
break;
case V_124 :
V_195 = V_2 -> V_92 [ 4 ] ;
V_2 -> V_100 = ( V_195 == 0 ) ? 256 : V_195 ;
V_202 = F_92 ( V_2 , 6 ,
V_177 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_55 ) ;
if ( V_202 == 0 )
V_202 = F_51 ( V_2 ) ;
break;
case V_219 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_202 = F_92 ( V_2 , 10 ,
V_177 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_56 ) ;
if ( V_202 == 0 )
V_202 = F_51 ( V_2 ) ;
break;
case V_220 :
V_2 -> V_100 =
F_45 ( & V_2 -> V_92 [ 6 ] ) ;
V_202 = F_92 ( V_2 , 12 ,
V_177 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_57 ) ;
if ( V_202 == 0 )
V_202 = F_51 ( V_2 ) ;
break;
case V_221 :
case V_222 :
case V_223 :
case V_224 :
default:
V_212:
V_2 -> V_100 = 0 ;
sprintf ( V_203 , L_58 , V_2 -> V_92 [ 0 ] ) ;
V_202 = F_91 ( V_2 , V_2 -> V_191 ,
V_173 , ~ 0 , 0 , V_203 ) ;
if ( V_202 == 0 ) {
V_2 -> V_85 -> V_94 = V_163 ;
V_202 = - V_96 ;
}
break;
}
F_75 ( & V_2 -> V_167 ) ;
if ( V_202 == - V_82 || F_39 ( V_81 ) )
return - V_82 ;
if ( V_202 == - V_96 )
V_202 = 0 ;
if ( V_202 >= 0 && V_2 -> V_171 == V_175 ) {
V_202 = F_30 ( ( T_2 ) V_202 , V_2 -> V_100 ) ;
V_12 -> V_78 -> V_13 = V_202 ;
V_12 -> V_9 = V_50 ;
V_2 -> V_110 -= V_202 ;
}
return 0 ;
}
static int F_95 ( struct V_5 * V_4 , struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_17 ;
struct V_225 * V_226 = V_40 -> V_48 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_40 -> V_42 || F_96 ( V_227 , & V_4 -> V_228 ) )
return - V_96 ;
if ( V_40 -> V_43 != V_229 ||
V_226 -> V_184 != F_90 (
V_230 ) ) {
F_8 ( V_4 , L_59 ,
V_40 -> V_43 ,
F_97 ( V_226 -> V_184 ) ) ;
F_85 ( V_4 ) ;
F_98 ( V_227 , & V_4 -> V_228 ) ;
return - V_96 ;
}
if ( V_226 -> V_231 >= V_232 || V_226 -> V_233 & ~ V_234 ||
V_226 -> V_235 <= 0 || V_226 -> V_235 > V_236 ) {
F_8 ( V_4 , L_60
L_61 ,
V_226 -> V_231 , V_226 -> V_233 , V_226 -> V_235 ) ;
if ( V_2 -> V_174 ) {
F_7 ( V_4 , V_4 -> V_22 ) ;
F_83 ( V_4 ) ;
}
return - V_96 ;
}
V_2 -> V_191 = V_226 -> V_235 ;
memcpy ( V_2 -> V_92 , V_226 -> V_237 , V_2 -> V_191 ) ;
if ( V_226 -> V_233 & V_234 )
V_2 -> V_171 = V_175 ;
else
V_2 -> V_171 = V_177 ;
V_2 -> V_176 = F_97 ( V_226 -> V_238 ) ;
if ( V_2 -> V_176 == 0 )
V_2 -> V_171 = V_172 ;
V_2 -> V_196 = V_226 -> V_231 ;
if ( V_2 -> V_196 < V_2 -> V_73 )
V_2 -> V_85 = V_2 -> V_239 [ V_2 -> V_196 ] ;
else
V_2 -> V_85 = NULL ;
V_2 -> V_187 = V_226 -> V_186 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_33 = 0 ;
V_12 = V_2 -> V_104 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
F_6 ( V_2 , V_12 , V_229 ) ;
if ( ! F_35 ( V_2 , V_12 ) )
return - V_101 ;
while ( V_12 -> V_9 != V_50 ) {
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
F_42 () ;
V_33 = F_28 ( V_2 ) ? F_95 ( V_2 -> V_4 , V_12 ) : - V_101 ;
V_12 -> V_9 = V_47 ;
return V_33 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_39 * * V_240 )
{
* V_240 = F_101 ( V_19 , V_36 ) ;
if ( * V_240 )
return 0 ;
ERROR ( V_2 , L_62 , V_19 -> V_20 ) ;
return - V_241 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_5 * V_242 )
{
struct V_5 * V_4 ;
int V_195 , V_33 = 0 ;
if ( V_2 -> V_243 )
F_8 ( V_2 , L_63 ) ;
V_244:
if ( V_2 -> V_4 ) {
V_4 = V_2 -> V_4 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_245 ; ++ V_195 ) {
struct V_11 * V_12 = & V_2 -> V_246 [ V_195 ] ;
if ( V_12 -> V_78 ) {
F_103 ( V_4 -> V_21 , V_12 -> V_78 ) ;
V_12 -> V_78 = NULL ;
}
if ( V_12 -> V_17 ) {
F_103 ( V_4 -> V_22 , V_12 -> V_17 ) ;
V_12 -> V_17 = NULL ;
}
}
if ( V_4 -> V_247 ) {
F_104 ( V_4 -> V_21 ) ;
V_4 -> V_21 -> V_37 = NULL ;
V_4 -> V_247 = 0 ;
}
if ( V_4 -> V_248 ) {
F_104 ( V_4 -> V_22 ) ;
V_4 -> V_22 -> V_37 = NULL ;
V_4 -> V_248 = 0 ;
}
V_2 -> V_4 = NULL ;
F_105 ( & V_2 -> V_249 ) ;
}
V_2 -> V_243 = 0 ;
if ( ! V_242 || V_33 )
return V_33 ;
V_2 -> V_4 = V_242 ;
V_4 = V_2 -> V_4 ;
V_33 = F_106 ( V_2 -> V_250 , & ( V_4 -> V_8 ) , V_4 -> V_21 ) ;
if ( V_33 )
goto V_244;
V_33 = F_107 ( V_4 -> V_21 ) ;
if ( V_33 )
goto V_244;
V_4 -> V_21 -> V_37 = V_2 ;
V_4 -> V_247 = 1 ;
V_33 = F_106 ( V_2 -> V_250 , & ( V_4 -> V_8 ) ,
V_4 -> V_22 ) ;
if ( V_33 )
goto V_244;
V_33 = F_107 ( V_4 -> V_22 ) ;
if ( V_33 )
goto V_244;
V_4 -> V_22 -> V_37 = V_2 ;
V_4 -> V_248 = 1 ;
V_2 -> V_16 = F_108 ( V_4 -> V_22 -> V_251 ) ;
F_109 ( V_227 , & V_4 -> V_228 ) ;
for ( V_195 = 0 ; V_195 < V_2 -> V_245 ; ++ V_195 ) {
struct V_11 * V_12 = & V_2 -> V_246 [ V_195 ] ;
V_33 = F_100 ( V_2 , V_4 -> V_21 , & V_12 -> V_78 ) ;
if ( V_33 )
goto V_244;
V_33 = F_100 ( V_2 , V_4 -> V_22 , & V_12 -> V_17 ) ;
if ( V_33 )
goto V_244;
V_12 -> V_78 -> V_48 = V_12 -> V_17 -> V_48 = V_12 -> V_48 ;
V_12 -> V_78 -> V_41 = V_12 -> V_17 -> V_41 = V_12 ;
V_12 -> V_78 -> V_252 = F_20 ;
V_12 -> V_17 -> V_252 = F_24 ;
}
V_2 -> V_243 = 1 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_73 ; ++ V_195 )
if ( V_2 -> V_239 [ V_195 ] )
V_2 -> V_239 [ V_195 ] -> V_201 =
V_253 ;
return V_33 ;
}
static int F_110 ( struct V_6 * V_7 , unsigned V_254 , unsigned V_255 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_242 = V_4 ;
F_13 ( V_4 -> V_2 , V_256 ) ;
return V_70 ;
}
static void F_111 ( struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_242 = NULL ;
F_13 ( V_4 -> V_2 , V_256 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_5 V_257 ;
int V_195 ;
struct V_11 * V_12 ;
enum V_25 V_258 ;
struct V_84 * V_85 ;
unsigned int V_29 ;
for (; ; ) {
int V_259 =
F_113 ( V_81 , & V_81 -> V_260 , & V_257 ) ;
if ( ! V_259 )
break;
if ( V_259 != V_31 ) {
if ( V_2 -> V_9 < V_261 )
F_8 ( V_2 , L_64 ) ;
F_13 ( V_2 , V_261 ) ;
}
}
if ( F_114 ( V_2 -> V_4 ) ) {
for ( V_195 = 0 ; V_195 < V_2 -> V_245 ; ++ V_195 ) {
V_12 = & V_2 -> V_246 [ V_195 ] ;
if ( V_12 -> V_46 )
F_115 ( V_2 -> V_4 -> V_21 , V_12 -> V_78 ) ;
if ( V_12 -> V_49 )
F_115 ( V_2 -> V_4 -> V_22 ,
V_12 -> V_17 ) ;
}
for (; ; ) {
int V_262 = 0 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_245 ; ++ V_195 ) {
V_12 = & V_2 -> V_246 [ V_195 ] ;
V_262 += V_12 -> V_46 + V_12 -> V_49 ;
}
if ( V_262 == 0 )
break;
if ( F_36 ( V_2 , true ) )
return;
}
if ( V_2 -> V_4 -> V_247 )
F_21 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_4 -> V_248 )
F_21 ( V_2 -> V_4 -> V_22 ) ;
}
F_32 ( & V_2 -> V_28 ) ;
for ( V_195 = 0 ; V_195 < V_2 -> V_245 ; ++ V_195 ) {
V_12 = & V_2 -> V_246 [ V_195 ] ;
V_12 -> V_9 = V_47 ;
}
V_2 -> V_104 = & V_2 -> V_246 [ 0 ] ;
V_2 -> V_127 = & V_2 -> V_246 [ 0 ] ;
V_29 = V_2 -> V_29 ;
V_258 = V_2 -> V_9 ;
if ( V_258 == V_170 )
V_2 -> V_9 = V_263 ;
else {
for ( V_195 = 0 ; V_195 < V_2 -> V_73 ; ++ V_195 ) {
V_85 = V_2 -> V_239 [ V_195 ] ;
if ( ! V_85 )
continue;
V_85 -> V_165 = 0 ;
V_85 -> V_94 = V_146 ;
V_85 -> V_201 = V_146 ;
V_85 -> V_105 = 0 ;
V_85 -> V_106 = 0 ;
}
V_2 -> V_9 = V_10 ;
}
F_33 ( & V_2 -> V_28 ) ;
switch ( V_258 ) {
case V_170 :
F_89 ( V_2 ) ;
F_32 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_9 == V_263 )
V_2 -> V_9 = V_10 ;
F_33 ( & V_2 -> V_28 ) ;
break;
case V_69 :
if ( ! F_28 ( V_2 ) )
break;
if ( F_116 ( V_227 ,
& V_2 -> V_4 -> V_228 ) )
F_117 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_30 == V_29 )
F_17 ( V_2 ) ;
break;
case V_256 :
F_102 ( V_2 , V_2 -> V_242 ) ;
if ( V_2 -> V_242 )
F_118 ( V_2 -> V_264 ) ;
break;
case V_261 :
case V_265 :
F_102 ( V_2 , NULL ) ;
F_32 ( & V_2 -> V_28 ) ;
V_2 -> V_9 = V_265 ;
F_33 ( & V_2 -> V_28 ) ;
break;
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_263 :
case V_10 :
break;
}
}
static int F_119 ( void * V_270 )
{
struct V_1 * V_2 = V_270 ;
F_120 ( V_271 ) ;
F_120 ( V_272 ) ;
F_120 ( V_273 ) ;
F_120 ( V_31 ) ;
F_121 () ;
F_122 ( F_123 () ) ;
while ( V_2 -> V_9 != V_265 ) {
if ( F_5 ( V_2 ) || F_39 ( V_81 ) ) {
F_112 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_243 ) {
F_36 ( V_2 , true ) ;
continue;
}
if ( F_99 ( V_2 ) )
continue;
F_32 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_269 ;
F_33 ( & V_2 -> V_28 ) ;
if ( F_93 ( V_2 ) || F_88 ( V_2 ) )
continue;
F_32 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_263 ;
F_33 ( & V_2 -> V_28 ) ;
if ( F_89 ( V_2 ) )
continue;
F_32 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_10 ;
F_33 ( & V_2 -> V_28 ) ;
}
F_32 ( & V_2 -> V_28 ) ;
V_2 -> V_24 = NULL ;
F_33 ( & V_2 -> V_28 ) ;
if ( ! V_2 -> V_274 || ! V_2 -> V_274 -> V_275
|| V_2 -> V_274 -> V_275 ( V_2 ) < 0 ) {
struct V_84 * * V_276 = V_2 -> V_239 ;
unsigned V_195 = V_2 -> V_73 ;
F_76 ( & V_2 -> V_167 ) ;
for (; V_195 -- ; ++ V_276 ) {
struct V_84 * V_85 = * V_276 ;
if ( ! V_85 || ! F_74 ( V_85 ) )
continue;
F_77 ( V_85 ) ;
V_85 -> V_201 = V_164 ;
}
F_78 ( & V_2 -> V_167 ) ;
}
F_124 ( & V_2 -> V_277 , 0 ) ;
}
static T_4 F_125 ( struct V_278 * V_279 , struct V_280 * V_281 , char * V_48 )
{
struct V_84 * V_85 = F_126 ( V_279 ) ;
return F_127 ( V_85 , V_48 ) ;
}
static T_4 F_128 ( struct V_278 * V_279 , struct V_280 * V_281 ,
char * V_48 )
{
struct V_84 * V_85 = F_126 ( V_279 ) ;
return F_129 ( V_85 , V_48 ) ;
}
static T_4 F_130 ( struct V_278 * V_279 , struct V_280 * V_281 ,
char * V_48 )
{
struct V_84 * V_85 = F_126 ( V_279 ) ;
struct V_282 * V_167 = F_131 ( V_279 ) ;
return F_132 ( V_85 , V_167 , V_48 ) ;
}
static T_4 F_133 ( struct V_278 * V_279 , struct V_280 * V_281 ,
const char * V_48 , T_6 V_283 )
{
struct V_84 * V_85 = F_126 ( V_279 ) ;
struct V_282 * V_167 = F_131 ( V_279 ) ;
return F_134 ( V_85 , V_167 , V_48 , V_283 ) ;
}
static T_4 F_135 ( struct V_278 * V_279 , struct V_280 * V_281 ,
const char * V_48 , T_6 V_283 )
{
struct V_84 * V_85 = F_126 ( V_279 ) ;
return F_136 ( V_85 , V_48 , V_283 ) ;
}
static T_4 F_137 ( struct V_278 * V_279 , struct V_280 * V_281 ,
const char * V_48 , T_6 V_283 )
{
struct V_84 * V_85 = F_126 ( V_279 ) ;
struct V_282 * V_167 = F_131 ( V_279 ) ;
return F_138 ( V_85 , V_167 , V_48 , V_283 ) ;
}
static void F_139 ( struct V_278 * V_279 )
{
}
void F_140 ( struct V_1 * V_2 )
{
F_141 ( & V_2 -> V_284 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
F_143 ( & V_2 -> V_284 , V_285 ) ;
}
static inline int F_144 ( unsigned int V_245 )
{
if ( V_245 >= 2 && V_245 <= 4 )
return 0 ;
F_145 ( L_65 ,
V_245 , 2 , 4 ) ;
return - V_96 ;
}
static struct V_1 * F_146 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
V_2 = F_147 ( sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return F_148 ( - V_241 ) ;
V_2 -> V_286 = 1 ;
} else {
V_2 -> V_286 = 0 ;
}
F_149 ( & V_2 -> V_167 ) ;
F_150 ( & V_2 -> V_28 ) ;
F_151 ( & V_2 -> V_284 ) ;
F_152 ( & V_2 -> V_277 ) ;
F_153 ( & V_2 -> V_249 ) ;
V_2 -> V_9 = V_265 ;
return V_2 ;
}
void F_154 ( struct V_1 * V_2 , bool V_287 )
{
V_2 -> V_287 = V_287 ;
}
static void F_155 ( struct V_11 * V_246 , unsigned V_288 )
{
if ( V_246 ) {
struct V_11 * V_12 = V_246 ;
while ( V_288 -- ) {
F_156 ( V_12 -> V_48 ) ;
++ V_12 ;
}
F_156 ( V_246 ) ;
}
}
int F_157 ( struct V_1 * V_2 , unsigned int V_288 )
{
struct V_11 * V_12 , * V_246 ;
int V_195 , V_33 ;
V_33 = F_144 ( V_288 ) ;
if ( V_33 != 0 )
return V_33 ;
V_246 = F_158 ( V_288 , sizeof( * V_246 ) , V_77 ) ;
if ( ! V_246 )
return - V_241 ;
V_12 = V_246 ;
V_195 = V_288 ;
goto V_289;
do {
V_12 -> V_113 = V_12 + 1 ;
++ V_12 ;
V_289:
V_12 -> V_48 = F_159 ( V_102 , V_77 ) ;
if ( F_46 ( ! V_12 -> V_48 ) )
goto V_290;
} while ( -- V_195 );
V_12 -> V_113 = V_246 ;
F_155 ( V_2 -> V_246 , V_2 -> V_245 ) ;
V_2 -> V_245 = V_288 ;
V_2 -> V_246 = V_246 ;
return 0 ;
V_290:
F_155 ( V_246 , V_288 ) ;
return - V_241 ;
}
static inline void F_160 ( struct V_84 * V_196 )
{
F_161 ( & V_196 -> V_279 , & V_291 ) ;
F_161 ( & V_196 -> V_279 , & V_292 ) ;
F_161 ( & V_196 -> V_279 , & V_293 ) ;
}
void F_162 ( struct V_84 * V_196 , bool V_287 )
{
if ( V_287 ) {
F_160 ( V_196 ) ;
F_163 ( & V_196 -> V_279 ) ;
}
F_77 ( V_196 ) ;
F_156 ( V_196 ) ;
}
static void F_164 ( struct V_1 * V_2 , int V_288 )
{
int V_195 ;
for ( V_195 = 0 ; V_195 < V_288 ; ++ V_195 )
if ( V_2 -> V_239 [ V_195 ] ) {
F_162 ( V_2 -> V_239 [ V_195 ] , V_2 -> V_287 ) ;
V_2 -> V_239 [ V_195 ] = NULL ;
}
}
void F_165 ( struct V_1 * V_2 )
{
F_164 ( V_2 , V_2 -> V_73 ) ;
}
void F_166 ( struct V_1 * V_2 )
{
F_165 ( V_2 ) ;
F_156 ( V_2 -> V_239 ) ;
V_2 -> V_239 = NULL ;
}
int F_167 ( struct V_1 * V_2 , int V_73 )
{
struct V_84 * * V_85 ;
if ( V_73 < 1 || V_73 > V_232 ) {
F_145 ( L_66 , V_73 ) ;
return - V_96 ;
}
V_85 = F_158 ( V_73 , sizeof( * V_85 ) , V_77 ) ;
if ( F_46 ( ! V_85 ) )
return - V_241 ;
if ( V_2 -> V_239 )
F_166 ( V_2 ) ;
V_2 -> V_239 = V_85 ;
V_2 -> V_73 = V_73 ;
F_168 ( L_67 , V_2 -> V_73 ) ;
return 0 ;
}
void F_169 ( struct V_1 * V_2 ,
const struct V_294 * V_274 )
{
V_2 -> V_274 = V_274 ;
}
void F_170 ( struct V_1 * V_2 )
{
F_155 ( V_2 -> V_246 , V_2 -> V_245 ) ;
V_2 -> V_246 = NULL ;
}
int F_171 ( struct V_1 * V_2 ,
struct V_295 * V_264 , bool V_174 )
{
struct V_296 * V_297 ;
V_2 -> V_250 = V_264 -> V_250 ;
V_2 -> V_34 = V_264 -> V_250 -> V_34 ;
V_2 -> V_35 = V_264 -> V_40 ;
V_2 -> V_264 = V_264 ;
V_297 = F_172 ( V_264 , V_298 ,
F_173 ( V_299 ) ) ;
if ( F_174 ( V_297 ) )
return F_175 ( V_297 ) ;
V_300 . V_301 = V_297 [ V_302 ] . V_303 ;
V_2 -> V_174 = V_174 && ! ( F_176 ( V_2 -> V_250 ) ) ;
return 0 ;
}
static inline int F_177 ( struct V_1 * V_2 ,
struct V_84 * V_196 )
{
int V_33 ;
V_33 = F_178 ( & V_196 -> V_279 ) ;
if ( V_33 ) {
F_179 ( & V_196 -> V_279 ) ;
return V_33 ;
}
V_33 = F_180 ( & V_196 -> V_279 ,
V_196 -> V_137
? & V_304
: & V_292 ) ;
if ( V_33 )
goto error;
V_33 = F_180 ( & V_196 -> V_279 ,
V_196 -> V_140
? & V_293
: & V_305 ) ;
if ( V_33 )
goto error;
V_33 = F_180 ( & V_196 -> V_279 , & V_291 ) ;
if ( V_33 )
goto error;
return 0 ;
error:
F_160 ( V_196 ) ;
F_163 ( & V_196 -> V_279 ) ;
return V_33 ;
}
int F_181 ( struct V_1 * V_2 , struct V_306 * V_307 ,
unsigned int V_303 , const char * V_20 ,
const char * * V_308 )
{
struct V_84 * V_196 ;
char * V_309 , * V_310 ;
int V_33 = - V_241 ;
if ( ! V_2 -> V_73 || ! V_2 -> V_239 )
return - V_311 ;
if ( V_2 -> V_239 [ V_303 ] )
return - V_312 ;
if ( ! V_307 -> V_313 && ! V_307 -> V_140 ) {
F_145 ( L_68 , V_303 ) ;
return - V_96 ;
}
V_196 = F_147 ( sizeof( * V_196 ) , V_77 ) ;
if ( ! V_196 )
return - V_241 ;
V_196 -> V_308 = V_308 ;
V_196 -> V_137 = ! ! V_307 -> V_137 ;
V_196 -> V_119 = V_307 -> V_137 || V_307 -> V_119 ;
V_196 -> V_314 = V_196 -> V_119 ;
V_196 -> V_140 = ! ! V_307 -> V_140 ;
if ( ! V_2 -> V_287 ) {
V_196 -> V_20 = V_20 ;
} else {
V_196 -> V_279 . V_315 = F_139 ;
V_196 -> V_279 . V_316 = & V_2 -> V_250 -> V_279 ;
F_182 ( & V_196 -> V_279 , & V_2 -> V_167 ) ;
F_183 ( & V_196 -> V_279 , L_69 , V_20 ) ;
V_196 -> V_20 = F_184 ( & V_196 -> V_279 ) ;
V_33 = F_177 ( V_2 , V_196 ) ;
if ( V_33 ) {
F_168 ( L_70 , V_303 , V_33 ) ;
goto V_317;
}
}
V_2 -> V_239 [ V_303 ] = V_196 ;
if ( V_307 -> V_313 ) {
V_33 = F_185 ( V_196 , V_307 -> V_313 ) ;
if ( V_33 )
goto V_318;
}
V_309 = F_159 ( V_319 , V_77 ) ;
V_310 = L_71 ;
if ( F_74 ( V_196 ) ) {
V_310 = L_72 ;
if ( V_309 ) {
V_310 = F_186 ( & V_196 -> V_107 -> V_320 , V_309 , V_319 ) ;
if ( F_174 ( V_310 ) )
V_310 = L_72 ;
}
}
F_168 ( L_73 ,
V_196 -> V_140 ? L_74 : L_75 ,
V_196 -> V_119 ? L_76 : L_75 ,
V_196 -> V_137 ? L_77 : L_75 ,
V_310 ) ;
F_156 ( V_309 ) ;
return 0 ;
V_318:
if ( V_2 -> V_287 ) {
F_160 ( V_196 ) ;
F_163 ( & V_196 -> V_279 ) ;
}
F_77 ( V_196 ) ;
V_2 -> V_239 [ V_303 ] = NULL ;
V_317:
F_156 ( V_196 ) ;
return V_33 ;
}
int F_187 ( struct V_1 * V_2 , struct V_321 * V_307 )
{
char V_48 [ 8 ] ;
int V_195 , V_33 ;
for ( V_195 = 0 ; V_195 < V_2 -> V_73 ; ++ V_195 ) {
snprintf ( V_48 , sizeof( V_48 ) , L_78 , V_195 ) ;
V_33 = F_181 ( V_2 , & V_307 -> V_239 [ V_195 ] , V_195 , V_48 , NULL ) ;
if ( V_33 )
goto V_322;
}
F_168 ( L_67 , V_2 -> V_73 ) ;
return 0 ;
V_322:
F_164 ( V_2 , V_195 ) ;
return V_33 ;
}
void F_188 ( struct V_1 * V_2 , const char * V_323 ,
const char * V_324 )
{
int V_195 ;
V_195 = F_189 () ;
snprintf ( V_2 -> V_141 , sizeof( V_2 -> V_141 ) ,
L_79 , V_323 ? : L_80 ,
V_324 ? : ( ( * V_2 -> V_239 ) -> V_137
? L_81
: L_82 ) ,
V_195 ) ;
}
int F_190 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_10 ;
V_2 -> V_24 =
F_191 ( F_119 , V_2 , L_83 ) ;
if ( F_174 ( V_2 -> V_24 ) ) {
V_2 -> V_9 = V_265 ;
return F_175 ( V_2 -> V_24 ) ;
}
F_8 ( V_2 , L_84 , F_192 ( V_2 -> V_24 ) ) ;
F_12 ( V_2 -> V_24 ) ;
return 0 ;
}
static void V_285 ( struct V_325 * V_284 )
{
struct V_1 * V_2 = F_4 ( V_284 , struct V_1 , V_284 ) ;
if ( V_2 -> V_9 != V_265 ) {
F_13 ( V_2 , V_261 ) ;
F_193 ( & V_2 -> V_277 ) ;
}
if ( F_114 ( V_2 -> V_239 ) ) {
struct V_84 * * V_326 = V_2 -> V_239 ;
unsigned V_195 = V_2 -> V_73 ;
for (; V_195 ; -- V_195 , ++ V_326 ) {
struct V_84 * V_196 = * V_326 ;
if ( ! V_196 )
continue;
if ( V_2 -> V_287 )
F_160 ( V_196 ) ;
F_77 ( V_196 ) ;
if ( V_2 -> V_287 )
F_163 ( & V_196 -> V_279 ) ;
F_156 ( V_196 ) ;
}
F_156 ( V_2 -> V_239 ) ;
}
F_155 ( V_2 -> V_246 , V_2 -> V_245 ) ;
if ( V_2 -> V_286 )
F_156 ( V_2 ) ;
}
static int F_194 ( struct V_327 * V_328 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_329 * V_250 = V_328 -> V_264 -> V_250 ;
int V_195 ;
struct V_18 * V_19 ;
unsigned V_330 ;
int V_331 ;
struct V_332 * V_333 ;
V_333 = F_195 ( V_7 -> V_334 ) ;
if ( ! V_333 -> V_335 ) {
V_331 = F_171 ( V_4 -> V_2 , V_328 -> V_264 ,
V_4 -> V_2 -> V_174 ) ;
if ( V_331 )
return V_331 ;
F_188 ( V_4 -> V_2 , NULL , NULL ) ;
V_331 = F_190 ( V_4 -> V_2 ) ;
if ( V_331 )
return V_331 ;
}
V_4 -> V_250 = V_250 ;
V_195 = F_196 ( V_328 , V_7 ) ;
if ( V_195 < 0 )
return V_195 ;
V_300 . V_336 = V_195 ;
V_4 -> V_67 = V_195 ;
V_19 = F_197 ( V_250 , & V_337 ) ;
if ( ! V_19 )
goto V_338;
V_19 -> V_37 = V_4 -> V_2 ;
V_4 -> V_21 = V_19 ;
V_19 = F_197 ( V_250 , & V_339 ) ;
if ( ! V_19 )
goto V_338;
V_19 -> V_37 = V_4 -> V_2 ;
V_4 -> V_22 = V_19 ;
V_340 . V_341 =
V_337 . V_341 ;
V_342 . V_341 =
V_339 . V_341 ;
V_330 = F_198 ( unsigned , V_102 / 1024 , 15 ) ;
V_343 . V_341 =
V_337 . V_341 ;
V_344 . V_345 = V_330 ;
V_346 . V_341 =
V_339 . V_341 ;
V_347 . V_345 = V_330 ;
V_331 = F_199 ( V_7 , V_348 , V_349 ,
V_350 ) ;
if ( V_331 )
goto V_338;
return 0 ;
V_338:
ERROR ( V_4 , L_85 ) ;
return - V_351 ;
}
static void F_200 ( struct V_327 * V_328 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_8 ( V_4 , L_86 ) ;
if ( V_4 -> V_2 -> V_4 == V_4 ) {
V_4 -> V_2 -> V_242 = NULL ;
F_13 ( V_4 -> V_2 , V_256 ) ;
F_201 ( V_2 -> V_249 , V_2 -> V_4 != V_4 ) ;
}
F_202 ( & V_4 -> V_8 ) ;
}
static inline struct V_352 * F_203 ( struct V_353 * V_354 )
{
return F_4 ( F_204 ( V_354 ) , struct V_352 , V_355 ) ;
}
static inline struct V_332 * F_205 ( struct V_353 * V_354 )
{
return F_4 ( F_204 ( V_354 ) , struct V_332 ,
V_356 . V_355 ) ;
}
static void F_206 ( struct V_353 * V_354 )
{
struct V_352 * V_357 ;
V_357 = F_203 ( V_354 ) ;
F_156 ( V_357 ) ;
}
static T_4 F_207 ( struct V_352 * V_333 , char * V_358 )
{
struct V_332 * V_332 ;
V_332 = F_205 ( V_333 -> V_355 . V_359 . V_360 ) ;
return F_132 ( V_333 -> V_196 , & V_332 -> V_2 -> V_167 , V_358 ) ;
}
static T_4 F_208 ( struct V_352 * V_333 ,
const char * V_358 , T_6 V_157 )
{
struct V_332 * V_332 ;
V_332 = F_205 ( V_333 -> V_355 . V_359 . V_360 ) ;
return F_138 ( V_333 -> V_196 , & V_332 -> V_2 -> V_167 , V_358 , V_157 ) ;
}
static T_4 F_209 ( struct V_352 * V_333 , char * V_358 )
{
return F_127 ( V_333 -> V_196 , V_358 ) ;
}
static T_4 F_210 ( struct V_352 * V_333 ,
const char * V_358 , T_6 V_157 )
{
struct V_332 * V_332 ;
V_332 = F_205 ( V_333 -> V_355 . V_359 . V_360 ) ;
return F_134 ( V_333 -> V_196 , & V_332 -> V_2 -> V_167 , V_358 , V_157 ) ;
}
static T_4 F_211 ( struct V_352 * V_333 ,
char * V_358 )
{
return F_212 ( V_333 -> V_196 , V_358 ) ;
}
static T_4 F_213 ( struct V_352 * V_333 ,
const char * V_358 , T_6 V_157 )
{
return F_214 ( V_333 -> V_196 , V_358 , V_157 ) ;
}
static T_4 F_215 ( struct V_352 * V_333 , char * V_358 )
{
return F_216 ( V_333 -> V_196 , V_358 ) ;
}
static T_4 F_217 ( struct V_352 * V_333 ,
const char * V_358 , T_6 V_157 )
{
struct V_332 * V_332 ;
V_332 = F_205 ( V_333 -> V_355 . V_359 . V_360 ) ;
return F_218 ( V_333 -> V_196 , & V_332 -> V_2 -> V_167 , V_358 ,
V_157 ) ;
}
static T_4 F_219 ( struct V_352 * V_333 , char * V_358 )
{
return F_129 ( V_333 -> V_196 , V_358 ) ;
}
static T_4 F_220 ( struct V_352 * V_333 ,
const char * V_358 , T_6 V_157 )
{
return F_136 ( V_333 -> V_196 , V_358 , V_157 ) ;
}
static struct V_361 * F_221 ( struct V_361 * V_355 ,
const char * V_20 )
{
struct V_352 * V_333 ;
struct V_332 * V_332 ;
struct V_306 V_362 ;
char * V_363 ;
V_60 V_364 ;
int V_331 ;
V_363 = strchr ( V_20 , '.' ) ;
if ( ! V_363 ) {
F_145 ( L_87 ) ;
return F_148 ( - V_96 ) ;
}
V_363 ++ ;
V_331 = F_222 ( V_363 , 0 , & V_364 ) ;
if ( V_331 )
return F_148 ( V_331 ) ;
V_332 = F_205 ( & V_355 -> V_359 ) ;
if ( V_364 >= V_232 )
return F_148 ( - V_365 ) ;
F_223 ( & V_332 -> V_28 ) ;
if ( V_332 -> V_366 || V_332 -> V_2 -> V_239 [ V_364 ] ) {
V_331 = - V_312 ;
goto V_367;
}
V_333 = F_147 ( sizeof( * V_333 ) , V_77 ) ;
if ( ! V_333 ) {
V_331 = - V_241 ;
goto V_367;
}
memset ( & V_362 , 0 , sizeof( V_362 ) ) ;
V_362 . V_140 = true ;
V_331 = F_181 ( V_332 -> V_2 , & V_362 , V_364 , V_20 ,
( const char * * ) & V_355 -> V_359 . V_368 ) ;
if ( V_331 ) {
F_156 ( V_333 ) ;
goto V_367;
}
V_333 -> V_196 = V_332 -> V_2 -> V_239 [ V_364 ] ;
V_333 -> V_369 = V_364 ;
F_224 ( & V_332 -> V_28 ) ;
F_225 ( & V_333 -> V_355 , V_20 , & V_370 ) ;
return & V_333 -> V_355 ;
V_367:
F_224 ( & V_332 -> V_28 ) ;
return F_148 ( V_331 ) ;
}
static void F_226 ( struct V_361 * V_355 , struct V_353 * V_354 )
{
struct V_352 * V_357 ;
struct V_332 * V_332 ;
V_357 = F_203 ( V_354 ) ;
V_332 = F_205 ( & V_355 -> V_359 ) ;
F_223 ( & V_332 -> V_28 ) ;
if ( V_332 -> V_366 ) {
struct V_353 * V_250 ;
V_250 = V_355 -> V_359 . V_360 -> V_360 ;
F_227 ( V_250 ) ;
}
F_162 ( V_357 -> V_196 , V_332 -> V_2 -> V_287 ) ;
V_332 -> V_2 -> V_239 [ V_357 -> V_369 ] = NULL ;
V_357 -> V_369 = 0 ;
F_224 ( & V_332 -> V_28 ) ;
F_228 ( V_354 ) ;
}
static void F_229 ( struct V_353 * V_354 )
{
struct V_332 * V_333 = F_205 ( V_354 ) ;
F_230 ( & V_333 -> V_356 ) ;
}
static T_4 F_231 ( struct V_332 * V_333 , char * V_358 )
{
int V_371 ;
F_223 ( & V_333 -> V_28 ) ;
V_371 = sprintf ( V_358 , L_88 , V_333 -> V_2 -> V_174 ) ;
F_224 ( & V_333 -> V_28 ) ;
return V_371 ;
}
static T_4 F_232 ( struct V_332 * V_333 , const char * V_358 ,
T_6 V_157 )
{
int V_331 ;
bool V_372 ;
F_223 ( & V_333 -> V_28 ) ;
if ( V_333 -> V_366 ) {
F_224 ( & V_333 -> V_28 ) ;
return - V_312 ;
}
V_331 = F_233 ( V_358 , & V_372 ) ;
if ( ! V_331 ) {
V_333 -> V_2 -> V_174 = V_372 ;
V_331 = V_157 ;
}
F_224 ( & V_333 -> V_28 ) ;
return V_331 ;
}
static T_4 F_234 ( struct V_332 * V_333 , char * V_358 )
{
int V_371 ;
F_223 ( & V_333 -> V_28 ) ;
V_371 = sprintf ( V_358 , L_88 , V_333 -> V_2 -> V_245 ) ;
F_224 ( & V_333 -> V_28 ) ;
return V_371 ;
}
static T_4 F_235 ( struct V_332 * V_333 ,
const char * V_358 , T_6 V_157 )
{
int V_331 ;
V_60 V_364 ;
F_223 ( & V_333 -> V_28 ) ;
if ( V_333 -> V_366 ) {
V_331 = - V_312 ;
goto V_373;
}
V_331 = F_222 ( V_358 , 0 , & V_364 ) ;
if ( V_331 )
goto V_373;
V_331 = F_144 ( V_364 ) ;
if ( V_331 )
goto V_373;
F_157 ( V_333 -> V_2 , V_364 ) ;
V_331 = V_157 ;
V_373:
F_224 ( & V_333 -> V_28 ) ;
return V_331 ;
}
static void F_236 ( struct V_374 * V_334 )
{
struct V_332 * V_333 ;
V_333 = F_195 ( V_334 ) ;
F_142 ( V_333 -> V_2 ) ;
F_156 ( V_333 ) ;
}
static struct V_374 * F_237 ( void )
{
struct V_332 * V_333 ;
struct V_306 V_362 ;
int V_33 ;
V_333 = F_147 ( sizeof( * V_333 ) , V_77 ) ;
if ( ! V_333 )
return F_148 ( - V_241 ) ;
F_238 ( & V_333 -> V_28 ) ;
V_333 -> V_356 . V_375 = F_236 ;
V_333 -> V_2 = F_146 ( V_333 -> V_2 ) ;
if ( F_174 ( V_333 -> V_2 ) ) {
V_33 = F_175 ( V_333 -> V_2 ) ;
goto V_376;
}
V_33 = F_167 ( V_333 -> V_2 , V_232 ) ;
if ( V_33 )
goto V_376;
V_33 = F_157 ( V_333 -> V_2 ,
V_377 ) ;
if ( V_33 )
goto V_378;
F_168 ( V_379 L_89 V_380 L_90 ) ;
memset ( & V_362 , 0 , sizeof( V_362 ) ) ;
V_362 . V_140 = true ;
V_33 = F_181 ( V_333 -> V_2 , & V_362 , 0 , L_91 ,
( const char * * ) & V_333 -> V_356 . V_355 . V_359 . V_368 ) ;
V_333 -> V_381 . V_196 = V_333 -> V_2 -> V_239 [ 0 ] ;
V_333 -> V_381 . V_369 = 0 ;
F_225 ( & V_333 -> V_381 . V_355 , L_91 , & V_370 ) ;
V_333 -> V_382 [ 0 ] = & V_333 -> V_381 . V_355 ;
V_333 -> V_356 . V_355 . V_382 = V_333 -> V_382 ;
F_225 ( & V_333 -> V_356 . V_355 , L_75 , & V_383 ) ;
return & V_333 -> V_356 ;
V_378:
F_156 ( V_333 -> V_2 -> V_239 ) ;
V_376:
F_156 ( V_333 ) ;
return F_148 ( V_33 ) ;
}
static void F_239 ( struct V_6 * V_7 )
{
struct V_5 * V_4 ;
struct V_332 * V_333 ;
V_4 = F_4 ( V_7 , struct V_5 , V_8 ) ;
V_333 = F_4 ( V_7 -> V_334 , struct V_332 , V_356 ) ;
F_223 ( & V_333 -> V_28 ) ;
V_333 -> V_366 -- ;
F_224 ( & V_333 -> V_28 ) ;
F_156 ( V_4 ) ;
}
static struct V_6 * F_240 ( struct V_374 * V_334 )
{
struct V_332 * V_333 = F_195 ( V_334 ) ;
struct V_1 * V_2 = V_333 -> V_2 ;
struct V_5 * V_4 ;
V_4 = F_147 ( sizeof( * V_4 ) , V_77 ) ;
if ( F_46 ( ! V_4 ) )
return F_148 ( - V_241 ) ;
F_223 ( & V_333 -> V_28 ) ;
V_333 -> V_366 ++ ;
F_224 ( & V_333 -> V_28 ) ;
V_4 -> V_8 . V_20 = V_379 ;
V_4 -> V_8 . V_384 = F_194 ;
V_4 -> V_8 . V_385 = F_200 ;
V_4 -> V_8 . V_386 = F_26 ;
V_4 -> V_8 . V_387 = F_110 ;
V_4 -> V_8 . V_388 = F_111 ;
V_4 -> V_8 . V_389 = F_239 ;
V_4 -> V_2 = V_2 ;
return & V_4 -> V_8 ;
}
void F_241 ( struct V_321 * V_307 ,
const struct V_390 * V_391 ,
unsigned int V_245 )
{
struct V_306 * V_196 ;
unsigned V_195 ;
V_307 -> V_73 =
F_30 ( V_391 -> V_239 ? : ( V_391 -> V_392 ? : 1u ) ,
( unsigned ) V_232 ) ;
for ( V_195 = 0 , V_196 = V_307 -> V_239 ; V_195 < V_307 -> V_73 ; ++ V_195 , ++ V_196 ) {
V_196 -> V_119 = ! ! V_391 -> V_119 [ V_195 ] ;
V_196 -> V_137 = ! ! V_391 -> V_137 [ V_195 ] ;
V_196 -> V_140 = ! ! V_391 -> V_140 [ V_195 ] ;
V_196 -> V_313 =
V_391 -> V_392 > V_195 && V_391 -> V_132 [ V_195 ] [ 0 ]
? V_391 -> V_132 [ V_195 ]
: NULL ;
}
V_307 -> V_393 = NULL ;
V_307 -> V_394 = NULL ;
V_307 -> V_274 = NULL ;
V_307 -> V_395 = NULL ;
V_307 -> V_174 = V_391 -> V_372 ;
V_307 -> V_245 = V_245 ;
}
