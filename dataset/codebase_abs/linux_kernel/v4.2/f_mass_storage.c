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
if ( V_33 == 0 )
return;
* V_74 = 0 ;
* V_9 = V_47 ;
if ( V_33 != - V_38 && ! ( V_33 == - V_59 && V_40 -> V_13 == 0 ) )
F_19 ( V_4 , L_5 , V_19 -> V_20 , V_33 ) ;
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
V_48 [ 0 ] = V_137 ;
V_48 [ 4 ] = 31 ;
return 36 ;
}
V_48 [ 0 ] = V_85 -> V_138 ? V_139 : V_140 ;
V_48 [ 1 ] = V_85 -> V_141 ? 0x80 : 0 ;
V_48 [ 2 ] = 2 ;
V_48 [ 3 ] = 2 ;
V_48 [ 4 ] = 31 ;
V_48 [ 5 ] = 0 ;
V_48 [ 6 ] = 0 ;
V_48 [ 7 ] = 0 ;
memcpy ( V_48 + 8 , V_2 -> V_142 , sizeof V_2 -> V_142 ) ;
return 36 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
T_2 V_143 , V_144 ;
int V_145 ;
#if 0
if (curlun && curlun->unit_attention_data != SS_NO_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
}
#endif
if ( ! V_85 ) {
V_2 -> V_136 = 1 ;
V_143 = V_146 ;
V_144 = 0 ;
V_145 = 0 ;
} else {
V_143 = V_85 -> V_94 ;
V_144 = V_85 -> V_105 ;
V_145 = V_85 -> V_106 << 7 ;
V_85 -> V_94 = V_147 ;
V_85 -> V_105 = 0 ;
V_85 -> V_106 = 0 ;
}
memset ( V_48 , 0 , 18 ) ;
V_48 [ 0 ] = V_145 | 0x70 ;
V_48 [ 2 ] = F_63 ( V_143 ) ;
F_64 ( V_144 , & V_48 [ 3 ] ) ;
V_48 [ 7 ] = 18 - 8 ;
V_48 [ 12 ] = F_65 ( V_143 ) ;
V_48 [ 13 ] = F_66 ( V_143 ) ;
return 18 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
T_2 V_86 = F_45 ( & V_2 -> V_92 [ 2 ] ) ;
int V_148 = V_2 -> V_92 [ 8 ] ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
if ( V_148 > 1 || ( V_148 == 0 && V_86 != 0 ) ) {
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
int V_149 = V_2 -> V_92 [ 1 ] & 0x02 ;
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
F_69 ( & V_48 [ 4 ] , V_149 , V_86 ) ;
return 8 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_149 = V_2 -> V_92 [ 1 ] & 0x02 ;
int V_150 = V_2 -> V_92 [ 6 ] ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
if ( ( V_2 -> V_92 [ 1 ] & ~ 0x02 ) != 0 ||
V_150 > 1 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
memset ( V_48 , 0 , 20 ) ;
V_48 [ 1 ] = ( 20 - 2 ) ;
V_48 [ 2 ] = 1 ;
V_48 [ 3 ] = 1 ;
V_48 [ 5 ] = 0x16 ;
V_48 [ 6 ] = 0x01 ;
F_69 ( & V_48 [ 8 ] , V_149 , 0 ) ;
V_48 [ 13 ] = 0x16 ;
V_48 [ 14 ] = 0xAA ;
F_69 ( & V_48 [ 16 ] , V_149 , V_85 -> V_97 ) ;
return 20 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_151 = V_2 -> V_92 [ 0 ] ;
V_60 * V_48 = ( V_60 * ) V_12 -> V_48 ;
V_60 * V_152 = V_48 ;
int V_153 , V_154 ;
int V_155 , V_156 ;
int V_157 = 0 ;
int V_158 , V_159 ;
if ( ( V_2 -> V_92 [ 1 ] & ~ 0x08 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
V_153 = V_2 -> V_92 [ 2 ] >> 6 ;
V_154 = V_2 -> V_92 [ 2 ] & 0x3f ;
if ( V_153 == 3 ) {
V_85 -> V_94 = V_160 ;
return - V_96 ;
}
V_155 = ( V_153 == 1 ) ;
V_156 = ( V_154 == 0x3f ) ;
memset ( V_48 , 0 , 8 ) ;
if ( V_151 == V_161 ) {
V_48 [ 2 ] = ( V_85 -> V_119 ? 0x80 : 0x00 ) ;
V_48 += 4 ;
V_159 = 255 ;
} else {
V_48 [ 3 ] = ( V_85 -> V_119 ? 0x80 : 0x00 ) ;
V_48 += 8 ;
V_159 = 65535 ;
}
if ( V_154 == 0x08 || V_156 ) {
V_157 = 1 ;
V_48 [ 0 ] = 0x08 ;
V_48 [ 1 ] = 10 ;
memset ( V_48 + 2 , 0 , 10 ) ;
if ( ! V_155 ) {
V_48 [ 2 ] = 0x04 ;
F_72 ( 0xffff , & V_48 [ 4 ] ) ;
F_72 ( 0xffff , & V_48 [ 8 ] ) ;
F_72 ( 0xffff , & V_48 [ 10 ] ) ;
}
V_48 += 12 ;
}
V_158 = V_48 - V_152 ;
if ( ! V_157 || V_158 > V_159 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
if ( V_151 == V_161 )
V_152 [ 0 ] = V_158 - 1 ;
else
F_72 ( V_158 - 2 , V_152 ) ;
return V_158 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_162 , V_163 ;
if ( ! V_85 ) {
return - V_96 ;
} else if ( ! V_85 -> V_141 ) {
V_85 -> V_94 = V_164 ;
return - V_96 ;
} else if ( ( V_2 -> V_92 [ 1 ] & ~ 0x01 ) != 0 ||
( V_2 -> V_92 [ 4 ] & ~ 0x03 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
V_162 = V_2 -> V_92 [ 4 ] & 0x02 ;
V_163 = V_2 -> V_92 [ 4 ] & 0x01 ;
if ( V_163 ) {
if ( ! F_74 ( V_85 ) ) {
V_85 -> V_94 = V_165 ;
return - V_96 ;
}
return 0 ;
}
if ( V_85 -> V_166 ) {
F_49 ( V_85 , L_21 ) ;
V_85 -> V_94 = V_167 ;
return - V_96 ;
}
if ( ! V_162 )
return 0 ;
F_75 ( & V_2 -> V_168 ) ;
F_76 ( & V_2 -> V_168 ) ;
F_77 ( V_85 ) ;
F_78 ( & V_2 -> V_168 ) ;
F_79 ( & V_2 -> V_168 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
int V_169 ;
if ( ! V_2 -> V_85 ) {
return - V_96 ;
} else if ( ! V_2 -> V_85 -> V_141 ) {
V_2 -> V_85 -> V_94 = V_164 ;
return - V_96 ;
}
V_169 = V_2 -> V_92 [ 4 ] & 0x01 ;
if ( ( V_2 -> V_92 [ 4 ] & ~ 0x01 ) != 0 ) {
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
if ( V_85 -> V_166 && ! V_169 )
F_55 ( V_85 ) ;
V_85 -> V_166 = V_169 ;
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
V_85 -> V_94 = V_164 ;
return - V_96 ;
}
static int F_83 ( struct V_5 * V_4 )
{
int V_33 ;
V_33 = F_7 ( V_4 , V_4 -> V_21 ) ;
if ( V_33 == - V_170 )
F_29 ( V_4 , L_22 ) ;
while ( V_33 != 0 ) {
if ( V_33 != - V_170 ) {
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
if ( V_33 == - V_170 )
F_29 ( V_4 , L_25 ) ;
while ( V_33 != 0 ) {
if ( V_33 != - V_170 ) {
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
V_171 ) ;
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
switch ( V_2 -> V_172 ) {
case V_173 :
break;
case V_174 :
if ( ! V_2 -> V_175 ) {
} else if ( F_28 ( V_2 ) ) {
F_7 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ) ;
V_33 = F_83 ( V_2 -> V_4 ) ;
} else {
V_33 = - V_101 ;
}
break;
case V_176 :
if ( V_2 -> V_177 == 0 ) {
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
if ( V_2 -> V_175 )
V_33 = F_83 ( V_2 -> V_4 ) ;
}
break;
case V_178 :
if ( V_2 -> V_110 == 0 ) {
} else if ( V_2 -> V_131 ) {
F_13 ( V_2 , V_171 ) ;
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
struct V_179 * V_180 ;
int V_33 ;
V_60 V_42 = V_181 ;
T_2 V_143 , V_144 = 0 ;
V_12 = V_2 -> V_104 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
if ( V_85 ) {
V_143 = V_85 -> V_94 ;
V_144 = V_85 -> V_105 ;
} else if ( V_2 -> V_136 )
V_143 = V_147 ;
else
V_143 = V_146 ;
if ( V_2 -> V_182 ) {
F_8 ( V_2 , L_27 ) ;
V_42 = V_183 ;
V_143 = V_164 ;
} else if ( V_143 != V_147 ) {
F_8 ( V_2 , L_28 ) ;
V_42 = V_184 ;
F_29 ( V_2 , L_29
L_30 ,
F_63 ( V_143 ) , F_65 ( V_143 ) , F_66 ( V_143 ) , V_144 ) ;
}
V_180 = ( void * ) V_12 -> V_48 ;
V_180 -> V_185 = F_90 ( V_186 ) ;
V_180 -> V_187 = V_2 -> V_188 ;
V_180 -> V_189 = F_90 ( V_2 -> V_110 ) ;
V_180 -> V_190 = V_42 ;
V_12 -> V_78 -> V_13 = V_191 ;
V_12 -> V_78 -> V_112 = 0 ;
if ( ! F_34 ( V_2 , V_12 ) )
return - V_101 ;
V_2 -> V_104 = V_12 -> V_113 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , int V_192 ,
enum V_193 V_172 , unsigned int V_194 ,
int V_195 , const char * V_20 )
{
int V_196 ;
unsigned int V_197 = V_2 -> V_92 [ 1 ] >> 5 ;
static const char V_198 [ 4 ] = { 'u' , 'o' , 'i' , 'n' } ;
char V_199 [ 20 ] ;
struct V_84 * V_85 ;
V_199 [ 0 ] = 0 ;
if ( V_2 -> V_172 != V_174 )
sprintf ( V_199 , L_31 , V_198 [ ( int ) V_2 -> V_172 ] ,
V_2 -> V_177 ) ;
F_29 ( V_2 , L_32 ,
V_20 , V_192 , V_198 [ ( int ) V_172 ] ,
V_2 -> V_100 , V_2 -> V_192 , V_199 ) ;
if ( V_2 -> V_100 == 0 )
V_172 = V_173 ;
if ( V_2 -> V_177 < V_2 -> V_100 ) {
V_2 -> V_100 = V_2 -> V_177 ;
V_2 -> V_182 = 1 ;
}
V_2 -> V_110 = V_2 -> V_177 ;
V_2 -> V_126 = V_2 -> V_177 ;
if ( V_2 -> V_172 != V_172 && V_2 -> V_100 > 0 ) {
V_2 -> V_182 = 1 ;
return - V_96 ;
}
if ( V_192 != V_2 -> V_192 ) {
if ( V_192 <= V_2 -> V_192 ) {
F_8 ( V_2 , L_33
L_34 , V_20 ,
V_192 , V_2 -> V_192 ) ;
V_192 = V_2 -> V_192 ;
} else {
V_2 -> V_182 = 1 ;
return - V_96 ;
}
}
if ( V_2 -> V_197 != V_197 )
F_8 ( V_2 , L_35 ,
V_2 -> V_197 , V_197 ) ;
V_85 = V_2 -> V_85 ;
if ( V_85 ) {
if ( V_2 -> V_92 [ 0 ] != V_200 ) {
V_85 -> V_94 = V_147 ;
V_85 -> V_105 = 0 ;
V_85 -> V_106 = 0 ;
}
} else {
V_2 -> V_136 = 0 ;
if ( V_2 -> V_92 [ 0 ] != V_201 &&
V_2 -> V_92 [ 0 ] != V_200 ) {
F_8 ( V_2 , L_36 , V_2 -> V_197 ) ;
return - V_96 ;
}
}
if ( V_85 && V_85 -> V_202 != V_147 &&
V_2 -> V_92 [ 0 ] != V_201 &&
V_2 -> V_92 [ 0 ] != V_200 ) {
V_85 -> V_94 = V_85 -> V_202 ;
V_85 -> V_202 = V_147 ;
return - V_96 ;
}
V_2 -> V_92 [ 1 ] &= 0x1f ;
for ( V_196 = 1 ; V_196 < V_192 ; ++ V_196 ) {
if ( V_2 -> V_92 [ V_196 ] && ! ( V_194 & ( 1 << V_196 ) ) ) {
if ( V_85 )
V_85 -> V_94 = V_95 ;
return - V_96 ;
}
}
if ( V_85 && ! F_74 ( V_85 ) && V_195 ) {
V_85 -> V_94 = V_165 ;
return - V_96 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
int V_192 , enum V_193 V_172 ,
unsigned int V_194 , int V_195 , const char * V_20 )
{
if ( V_2 -> V_85 )
V_2 -> V_100 <<= V_2 -> V_85 -> V_99 ;
return F_91 ( V_2 , V_192 , V_172 ,
V_194 , V_195 , V_20 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_33 ;
int V_203 = - V_96 ;
int V_196 ;
static char V_204 [ 16 ] ;
F_94 ( V_2 ) ;
V_12 = V_2 -> V_104 ;
V_2 -> V_127 = V_12 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_36 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
V_2 -> V_182 = 0 ;
V_2 -> V_131 = 0 ;
F_79 ( & V_2 -> V_168 ) ;
switch ( V_2 -> V_92 [ 0 ] ) {
case V_201 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_203 = F_91 ( V_2 , 6 , V_176 ,
( 1 << 4 ) , 0 ,
L_37 ) ;
if ( V_203 == 0 )
V_203 = F_61 ( V_2 , V_12 ) ;
break;
case V_205 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_203 = F_91 ( V_2 , 6 , V_178 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_38 ) ;
if ( V_203 == 0 )
V_203 = F_82 ( V_2 , V_12 ) ;
break;
case V_206 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_91 ( V_2 , 10 , V_178 ,
( 1 << 1 ) | ( 3 << 7 ) , 0 ,
L_39 ) ;
if ( V_203 == 0 )
V_203 = F_82 ( V_2 , V_12 ) ;
break;
case V_161 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_203 = F_91 ( V_2 , 6 , V_176 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) , 0 ,
L_40 ) ;
if ( V_203 == 0 )
V_203 = F_71 ( V_2 , V_12 ) ;
break;
case V_207 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_91 ( V_2 , 10 , V_176 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 3 << 7 ) , 0 ,
L_41 ) ;
if ( V_203 == 0 )
V_203 = F_71 ( V_2 , V_12 ) ;
break;
case V_208 :
V_2 -> V_100 = 0 ;
V_203 = F_91 ( V_2 , 6 , V_173 ,
( 1 << 4 ) , 0 ,
L_42 ) ;
if ( V_203 == 0 )
V_203 = F_80 ( V_2 ) ;
break;
case V_93 :
V_196 = V_2 -> V_92 [ 4 ] ;
V_2 -> V_100 = ( V_196 == 0 ) ? 256 : V_196 ;
V_203 = F_92 ( V_2 , 6 ,
V_176 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_43 ) ;
if ( V_203 == 0 )
V_203 = F_43 ( V_2 ) ;
break;
case V_209 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_92 ( V_2 , 10 ,
V_176 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_44 ) ;
if ( V_203 == 0 )
V_203 = F_43 ( V_2 ) ;
break;
case V_210 :
V_2 -> V_100 =
F_45 ( & V_2 -> V_92 [ 6 ] ) ;
V_203 = F_92 ( V_2 , 12 ,
V_176 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_45 ) ;
if ( V_203 == 0 )
V_203 = F_43 ( V_2 ) ;
break;
case V_211 :
V_2 -> V_100 = 8 ;
V_203 = F_91 ( V_2 , 10 , V_176 ,
( 0xf << 2 ) | ( 1 << 8 ) , 1 ,
L_46 ) ;
if ( V_203 == 0 )
V_203 = F_67 ( V_2 , V_12 ) ;
break;
case V_212 :
if ( ! V_2 -> V_85 || ! V_2 -> V_85 -> V_138 )
goto V_213;
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_91 ( V_2 , 10 , V_176 ,
( 3 << 7 ) | ( 0x1f << 1 ) , 1 ,
L_47 ) ;
if ( V_203 == 0 )
V_203 = F_68 ( V_2 , V_12 ) ;
break;
case V_214 :
if ( ! V_2 -> V_85 || ! V_2 -> V_85 -> V_138 )
goto V_213;
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_91 ( V_2 , 10 , V_176 ,
( 7 << 6 ) | ( 1 << 1 ) , 1 ,
L_48 ) ;
if ( V_203 == 0 )
V_203 = F_70 ( V_2 , V_12 ) ;
break;
case V_215 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_91 ( V_2 , 10 , V_176 ,
( 3 << 7 ) , 1 ,
L_49 ) ;
if ( V_203 == 0 )
V_203 = F_81 ( V_2 , V_12 ) ;
break;
case V_200 :
V_2 -> V_100 = V_2 -> V_92 [ 4 ] ;
V_203 = F_91 ( V_2 , 6 , V_176 ,
( 1 << 4 ) , 0 ,
L_50 ) ;
if ( V_203 == 0 )
V_203 = F_62 ( V_2 , V_12 ) ;
break;
case V_216 :
V_2 -> V_100 = 0 ;
V_203 = F_91 ( V_2 , 6 , V_173 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_51 ) ;
if ( V_203 == 0 )
V_203 = F_73 ( V_2 ) ;
break;
case V_217 :
V_2 -> V_100 = 0 ;
V_203 = F_91 ( V_2 , 10 , V_173 ,
( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_52 ) ;
if ( V_203 == 0 )
V_203 = F_54 ( V_2 ) ;
break;
case V_218 :
V_2 -> V_100 = 0 ;
V_203 = F_91 ( V_2 , 6 , V_173 ,
0 , 1 ,
L_53 ) ;
break;
case V_219 :
V_2 -> V_100 = 0 ;
V_203 = F_91 ( V_2 , 10 , V_173 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_54 ) ;
if ( V_203 == 0 )
V_203 = F_59 ( V_2 ) ;
break;
case V_124 :
V_196 = V_2 -> V_92 [ 4 ] ;
V_2 -> V_100 = ( V_196 == 0 ) ? 256 : V_196 ;
V_203 = F_92 ( V_2 , 6 ,
V_178 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_55 ) ;
if ( V_203 == 0 )
V_203 = F_51 ( V_2 ) ;
break;
case V_220 :
V_2 -> V_100 =
F_60 ( & V_2 -> V_92 [ 7 ] ) ;
V_203 = F_92 ( V_2 , 10 ,
V_178 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_56 ) ;
if ( V_203 == 0 )
V_203 = F_51 ( V_2 ) ;
break;
case V_221 :
V_2 -> V_100 =
F_45 ( & V_2 -> V_92 [ 6 ] ) ;
V_203 = F_92 ( V_2 , 12 ,
V_178 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_57 ) ;
if ( V_203 == 0 )
V_203 = F_51 ( V_2 ) ;
break;
case V_222 :
case V_223 :
case V_224 :
case V_225 :
default:
V_213:
V_2 -> V_100 = 0 ;
sprintf ( V_204 , L_58 , V_2 -> V_92 [ 0 ] ) ;
V_203 = F_91 ( V_2 , V_2 -> V_192 ,
V_174 , ~ 0 , 0 , V_204 ) ;
if ( V_203 == 0 ) {
V_2 -> V_85 -> V_94 = V_164 ;
V_203 = - V_96 ;
}
break;
}
F_75 ( & V_2 -> V_168 ) ;
if ( V_203 == - V_82 || F_39 ( V_81 ) )
return - V_82 ;
if ( V_203 == - V_96 )
V_203 = 0 ;
if ( V_203 >= 0 && V_2 -> V_172 == V_176 ) {
V_203 = F_30 ( ( T_2 ) V_203 , V_2 -> V_100 ) ;
V_12 -> V_78 -> V_13 = V_203 ;
V_12 -> V_9 = V_50 ;
V_2 -> V_110 -= V_203 ;
}
return 0 ;
}
static int F_95 ( struct V_5 * V_4 , struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_17 ;
struct V_226 * V_227 = V_40 -> V_48 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_40 -> V_42 || F_96 ( V_228 , & V_4 -> V_229 ) )
return - V_96 ;
if ( V_40 -> V_43 != V_230 ||
V_227 -> V_185 != F_90 (
V_231 ) ) {
F_8 ( V_4 , L_59 ,
V_40 -> V_43 ,
F_97 ( V_227 -> V_185 ) ) ;
F_85 ( V_4 ) ;
F_98 ( V_228 , & V_4 -> V_229 ) ;
return - V_96 ;
}
if ( V_227 -> V_232 >= V_233 || V_227 -> V_234 & ~ V_235 ||
V_227 -> V_236 <= 0 || V_227 -> V_236 > V_237 ) {
F_8 ( V_4 , L_60
L_61 ,
V_227 -> V_232 , V_227 -> V_234 , V_227 -> V_236 ) ;
if ( V_2 -> V_175 ) {
F_7 ( V_4 , V_4 -> V_22 ) ;
F_83 ( V_4 ) ;
}
return - V_96 ;
}
V_2 -> V_192 = V_227 -> V_236 ;
memcpy ( V_2 -> V_92 , V_227 -> V_238 , V_2 -> V_192 ) ;
if ( V_227 -> V_234 & V_235 )
V_2 -> V_172 = V_176 ;
else
V_2 -> V_172 = V_178 ;
V_2 -> V_177 = F_97 ( V_227 -> V_239 ) ;
if ( V_2 -> V_177 == 0 )
V_2 -> V_172 = V_173 ;
V_2 -> V_197 = V_227 -> V_232 ;
if ( V_2 -> V_197 < V_2 -> V_73 )
V_2 -> V_85 = V_2 -> V_240 [ V_2 -> V_197 ] ;
else
V_2 -> V_85 = NULL ;
V_2 -> V_188 = V_227 -> V_187 ;
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
F_6 ( V_2 , V_12 , V_230 ) ;
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
struct V_39 * * V_241 )
{
* V_241 = F_101 ( V_19 , V_36 ) ;
if ( * V_241 )
return 0 ;
ERROR ( V_2 , L_62 , V_19 -> V_20 ) ;
return - V_242 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_5 * V_243 )
{
struct V_5 * V_4 ;
int V_196 , V_33 = 0 ;
if ( V_2 -> V_244 )
F_8 ( V_2 , L_63 ) ;
V_245:
if ( V_2 -> V_4 ) {
V_4 = V_2 -> V_4 ;
for ( V_196 = 0 ; V_196 < V_2 -> V_246 ; ++ V_196 ) {
struct V_11 * V_12 = & V_2 -> V_247 [ V_196 ] ;
if ( V_12 -> V_78 ) {
F_103 ( V_4 -> V_21 , V_12 -> V_78 ) ;
V_12 -> V_78 = NULL ;
}
if ( V_12 -> V_17 ) {
F_103 ( V_4 -> V_22 , V_12 -> V_17 ) ;
V_12 -> V_17 = NULL ;
}
}
if ( V_4 -> V_248 ) {
F_104 ( V_4 -> V_21 ) ;
V_4 -> V_21 -> V_37 = NULL ;
V_4 -> V_248 = 0 ;
}
if ( V_4 -> V_249 ) {
F_104 ( V_4 -> V_22 ) ;
V_4 -> V_22 -> V_37 = NULL ;
V_4 -> V_249 = 0 ;
}
V_2 -> V_4 = NULL ;
F_105 ( & V_2 -> V_250 ) ;
}
V_2 -> V_244 = 0 ;
if ( ! V_243 || V_33 )
return V_33 ;
V_2 -> V_4 = V_243 ;
V_4 = V_2 -> V_4 ;
V_33 = F_106 ( V_2 -> V_251 , & ( V_4 -> V_8 ) , V_4 -> V_21 ) ;
if ( V_33 )
goto V_245;
V_33 = F_107 ( V_4 -> V_21 ) ;
if ( V_33 )
goto V_245;
V_4 -> V_21 -> V_37 = V_2 ;
V_4 -> V_248 = 1 ;
V_33 = F_106 ( V_2 -> V_251 , & ( V_4 -> V_8 ) ,
V_4 -> V_22 ) ;
if ( V_33 )
goto V_245;
V_33 = F_107 ( V_4 -> V_22 ) ;
if ( V_33 )
goto V_245;
V_4 -> V_22 -> V_37 = V_2 ;
V_4 -> V_249 = 1 ;
V_2 -> V_16 = F_108 ( V_4 -> V_22 -> V_252 ) ;
F_109 ( V_228 , & V_4 -> V_229 ) ;
for ( V_196 = 0 ; V_196 < V_2 -> V_246 ; ++ V_196 ) {
struct V_11 * V_12 = & V_2 -> V_247 [ V_196 ] ;
V_33 = F_100 ( V_2 , V_4 -> V_21 , & V_12 -> V_78 ) ;
if ( V_33 )
goto V_245;
V_33 = F_100 ( V_2 , V_4 -> V_22 , & V_12 -> V_17 ) ;
if ( V_33 )
goto V_245;
V_12 -> V_78 -> V_48 = V_12 -> V_17 -> V_48 = V_12 -> V_48 ;
V_12 -> V_78 -> V_41 = V_12 -> V_17 -> V_41 = V_12 ;
V_12 -> V_78 -> V_253 = F_20 ;
V_12 -> V_17 -> V_253 = F_24 ;
}
V_2 -> V_244 = 1 ;
for ( V_196 = 0 ; V_196 < V_2 -> V_73 ; ++ V_196 )
if ( V_2 -> V_240 [ V_196 ] )
V_2 -> V_240 [ V_196 ] -> V_202 =
V_254 ;
return V_33 ;
}
static int F_110 ( struct V_6 * V_7 , unsigned V_255 , unsigned V_256 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_243 = V_4 ;
F_13 ( V_4 -> V_2 , V_257 ) ;
return V_70 ;
}
static void F_111 ( struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_243 = NULL ;
F_13 ( V_4 -> V_2 , V_257 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_5 V_258 ;
int V_196 ;
struct V_11 * V_12 ;
enum V_25 V_259 ;
struct V_84 * V_85 ;
unsigned int V_29 ;
for (; ; ) {
int V_260 =
F_113 ( V_81 , & V_81 -> V_261 , & V_258 ) ;
if ( ! V_260 )
break;
if ( V_260 != V_31 ) {
if ( V_2 -> V_9 < V_262 )
F_8 ( V_2 , L_64 ) ;
F_13 ( V_2 , V_262 ) ;
}
}
if ( F_114 ( V_2 -> V_4 ) ) {
for ( V_196 = 0 ; V_196 < V_2 -> V_246 ; ++ V_196 ) {
V_12 = & V_2 -> V_247 [ V_196 ] ;
if ( V_12 -> V_46 )
F_115 ( V_2 -> V_4 -> V_21 , V_12 -> V_78 ) ;
if ( V_12 -> V_49 )
F_115 ( V_2 -> V_4 -> V_22 ,
V_12 -> V_17 ) ;
}
for (; ; ) {
int V_263 = 0 ;
for ( V_196 = 0 ; V_196 < V_2 -> V_246 ; ++ V_196 ) {
V_12 = & V_2 -> V_247 [ V_196 ] ;
V_263 += V_12 -> V_46 + V_12 -> V_49 ;
}
if ( V_263 == 0 )
break;
if ( F_36 ( V_2 , true ) )
return;
}
if ( V_2 -> V_4 -> V_248 )
F_21 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_4 -> V_249 )
F_21 ( V_2 -> V_4 -> V_22 ) ;
}
F_32 ( & V_2 -> V_28 ) ;
for ( V_196 = 0 ; V_196 < V_2 -> V_246 ; ++ V_196 ) {
V_12 = & V_2 -> V_247 [ V_196 ] ;
V_12 -> V_9 = V_47 ;
}
V_2 -> V_104 = & V_2 -> V_247 [ 0 ] ;
V_2 -> V_127 = & V_2 -> V_247 [ 0 ] ;
V_29 = V_2 -> V_29 ;
V_259 = V_2 -> V_9 ;
if ( V_259 == V_171 )
V_2 -> V_9 = V_264 ;
else {
for ( V_196 = 0 ; V_196 < V_2 -> V_73 ; ++ V_196 ) {
V_85 = V_2 -> V_240 [ V_196 ] ;
if ( ! V_85 )
continue;
V_85 -> V_166 = 0 ;
V_85 -> V_94 = V_147 ;
V_85 -> V_202 = V_147 ;
V_85 -> V_105 = 0 ;
V_85 -> V_106 = 0 ;
}
V_2 -> V_9 = V_10 ;
}
F_33 ( & V_2 -> V_28 ) ;
switch ( V_259 ) {
case V_171 :
F_89 ( V_2 ) ;
F_32 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_9 == V_264 )
V_2 -> V_9 = V_10 ;
F_33 ( & V_2 -> V_28 ) ;
break;
case V_69 :
if ( ! F_28 ( V_2 ) )
break;
if ( F_116 ( V_228 ,
& V_2 -> V_4 -> V_229 ) )
F_117 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_30 == V_29 )
F_17 ( V_2 ) ;
break;
case V_257 :
F_102 ( V_2 , V_2 -> V_243 ) ;
if ( V_2 -> V_243 )
F_118 ( V_2 -> V_265 ) ;
break;
case V_262 :
case V_266 :
F_102 ( V_2 , NULL ) ;
F_32 ( & V_2 -> V_28 ) ;
V_2 -> V_9 = V_266 ;
F_33 ( & V_2 -> V_28 ) ;
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_264 :
case V_10 :
break;
}
}
static int F_119 ( void * V_271 )
{
struct V_1 * V_2 = V_271 ;
F_120 ( V_272 ) ;
F_120 ( V_273 ) ;
F_120 ( V_274 ) ;
F_120 ( V_31 ) ;
F_121 () ;
F_122 ( F_123 () ) ;
while ( V_2 -> V_9 != V_266 ) {
if ( F_5 ( V_2 ) || F_39 ( V_81 ) ) {
F_112 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_244 ) {
F_36 ( V_2 , true ) ;
continue;
}
if ( F_99 ( V_2 ) )
continue;
F_32 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_270 ;
F_33 ( & V_2 -> V_28 ) ;
if ( F_93 ( V_2 ) || F_88 ( V_2 ) )
continue;
F_32 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_264 ;
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
if ( ! V_2 -> V_275 || ! V_2 -> V_275 -> V_276
|| V_2 -> V_275 -> V_276 ( V_2 ) < 0 ) {
struct V_84 * * V_277 = V_2 -> V_240 ;
unsigned V_196 = V_2 -> V_73 ;
F_76 ( & V_2 -> V_168 ) ;
for (; V_196 -- ; ++ V_277 ) {
struct V_84 * V_85 = * V_277 ;
if ( ! V_85 || ! F_74 ( V_85 ) )
continue;
F_77 ( V_85 ) ;
V_85 -> V_202 = V_165 ;
}
F_78 ( & V_2 -> V_168 ) ;
}
F_124 ( & V_2 -> V_278 , 0 ) ;
}
static T_4 F_125 ( struct V_279 * V_280 , struct V_281 * V_282 , char * V_48 )
{
struct V_84 * V_85 = F_126 ( V_280 ) ;
return F_127 ( V_85 , V_48 ) ;
}
static T_4 F_128 ( struct V_279 * V_280 , struct V_281 * V_282 ,
char * V_48 )
{
struct V_84 * V_85 = F_126 ( V_280 ) ;
return F_129 ( V_85 , V_48 ) ;
}
static T_4 F_130 ( struct V_279 * V_280 , struct V_281 * V_282 ,
char * V_48 )
{
struct V_84 * V_85 = F_126 ( V_280 ) ;
struct V_283 * V_168 = F_131 ( V_280 ) ;
return F_132 ( V_85 , V_168 , V_48 ) ;
}
static T_4 F_133 ( struct V_279 * V_280 , struct V_281 * V_282 ,
const char * V_48 , T_6 V_284 )
{
struct V_84 * V_85 = F_126 ( V_280 ) ;
struct V_283 * V_168 = F_131 ( V_280 ) ;
return F_134 ( V_85 , V_168 , V_48 , V_284 ) ;
}
static T_4 F_135 ( struct V_279 * V_280 , struct V_281 * V_282 ,
const char * V_48 , T_6 V_284 )
{
struct V_84 * V_85 = F_126 ( V_280 ) ;
return F_136 ( V_85 , V_48 , V_284 ) ;
}
static T_4 F_137 ( struct V_279 * V_280 , struct V_281 * V_282 ,
const char * V_48 , T_6 V_284 )
{
struct V_84 * V_85 = F_126 ( V_280 ) ;
struct V_283 * V_168 = F_131 ( V_280 ) ;
return F_138 ( V_85 , V_168 , V_48 , V_284 ) ;
}
static void F_139 ( struct V_279 * V_280 )
{
}
void F_140 ( struct V_1 * V_2 )
{
F_141 ( & V_2 -> V_285 ) ;
}
void F_142 ( struct V_1 * V_2 )
{
F_143 ( & V_2 -> V_285 , V_286 ) ;
}
static inline int F_144 ( unsigned int V_246 )
{
if ( V_246 >= 2 && V_246 <= 4 )
return 0 ;
F_145 ( L_65 ,
V_246 , 2 , 4 ) ;
return - V_96 ;
}
static struct V_1 * F_146 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
V_2 = F_147 ( sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return F_148 ( - V_242 ) ;
V_2 -> V_287 = 1 ;
} else {
V_2 -> V_287 = 0 ;
}
F_149 ( & V_2 -> V_168 ) ;
F_150 ( & V_2 -> V_28 ) ;
F_151 ( & V_2 -> V_285 ) ;
F_152 ( & V_2 -> V_278 ) ;
F_153 ( & V_2 -> V_250 ) ;
V_2 -> V_9 = V_266 ;
return V_2 ;
}
void F_154 ( struct V_1 * V_2 , bool V_288 )
{
V_2 -> V_288 = V_288 ;
}
static void F_155 ( struct V_11 * V_247 , unsigned V_289 )
{
if ( V_247 ) {
struct V_11 * V_12 = V_247 ;
while ( V_289 -- ) {
F_156 ( V_12 -> V_48 ) ;
++ V_12 ;
}
F_156 ( V_247 ) ;
}
}
int F_157 ( struct V_1 * V_2 , unsigned int V_289 )
{
struct V_11 * V_12 , * V_247 ;
int V_196 , V_33 ;
V_33 = F_144 ( V_289 ) ;
if ( V_33 != 0 )
return V_33 ;
V_247 = F_158 ( V_289 , sizeof( * V_247 ) , V_77 ) ;
if ( ! V_247 )
return - V_242 ;
V_12 = V_247 ;
V_196 = V_289 ;
goto V_290;
do {
V_12 -> V_113 = V_12 + 1 ;
++ V_12 ;
V_290:
V_12 -> V_48 = F_159 ( V_102 , V_77 ) ;
if ( F_46 ( ! V_12 -> V_48 ) )
goto V_291;
} while ( -- V_196 );
V_12 -> V_113 = V_247 ;
F_155 ( V_2 -> V_247 , V_2 -> V_246 ) ;
V_2 -> V_246 = V_289 ;
V_2 -> V_247 = V_247 ;
return 0 ;
V_291:
F_155 ( V_247 , V_289 ) ;
return - V_242 ;
}
void F_160 ( struct V_84 * V_197 , bool V_288 )
{
if ( V_288 )
F_161 ( & V_197 -> V_280 ) ;
F_77 ( V_197 ) ;
F_156 ( V_197 ) ;
}
static void F_162 ( struct V_1 * V_2 , int V_289 )
{
int V_196 ;
for ( V_196 = 0 ; V_196 < V_289 ; ++ V_196 )
if ( V_2 -> V_240 [ V_196 ] ) {
F_160 ( V_2 -> V_240 [ V_196 ] , V_2 -> V_288 ) ;
V_2 -> V_240 [ V_196 ] = NULL ;
}
}
void F_163 ( struct V_1 * V_2 )
{
F_162 ( V_2 , V_2 -> V_73 ) ;
}
void F_164 ( struct V_1 * V_2 )
{
F_163 ( V_2 ) ;
F_156 ( V_2 -> V_240 ) ;
V_2 -> V_240 = NULL ;
}
int F_165 ( struct V_1 * V_2 , int V_73 )
{
struct V_84 * * V_85 ;
if ( V_73 < 1 || V_73 > V_233 ) {
F_145 ( L_66 , V_73 ) ;
return - V_96 ;
}
V_85 = F_158 ( V_233 , sizeof( * V_85 ) , V_77 ) ;
if ( F_46 ( ! V_85 ) )
return - V_242 ;
if ( V_2 -> V_240 )
F_164 ( V_2 ) ;
V_2 -> V_240 = V_85 ;
V_2 -> V_73 = V_73 ;
return 0 ;
}
void F_166 ( struct V_1 * V_2 ,
const struct V_292 * V_275 )
{
V_2 -> V_275 = V_275 ;
}
void F_167 ( struct V_1 * V_2 )
{
F_155 ( V_2 -> V_247 , V_2 -> V_246 ) ;
V_2 -> V_247 = NULL ;
}
int F_168 ( struct V_1 * V_2 ,
struct V_293 * V_265 , bool V_175 )
{
struct V_294 * V_295 ;
V_2 -> V_251 = V_265 -> V_251 ;
V_2 -> V_34 = V_265 -> V_251 -> V_34 ;
V_2 -> V_35 = V_265 -> V_40 ;
V_2 -> V_265 = V_265 ;
V_295 = F_169 ( V_265 , V_296 ,
F_170 ( V_297 ) ) ;
if ( F_171 ( V_295 ) )
return F_172 ( V_295 ) ;
V_298 . V_299 = V_295 [ V_300 ] . V_301 ;
V_2 -> V_175 = V_175 && ! ( F_173 ( V_2 -> V_251 ) ) ;
return 0 ;
}
static T_7 F_174 ( struct V_302 * V_303 ,
struct V_304 * V_282 , int V_305 )
{
struct V_279 * V_280 = F_175 ( V_303 ) ;
struct V_84 * V_197 = F_126 ( V_280 ) ;
if ( V_282 == & V_306 . V_282 )
return V_197 -> V_138 ? V_307 : ( V_308 | V_307 ) ;
if ( V_282 == & V_309 . V_282 )
return V_197 -> V_141 ? ( V_308 | V_307 ) : V_307 ;
return V_282 -> V_310 ;
}
int F_176 ( struct V_1 * V_2 , struct V_311 * V_312 ,
unsigned int V_301 , const char * V_20 ,
const char * * V_313 )
{
struct V_84 * V_197 ;
char * V_314 , * V_315 ;
int V_33 = - V_242 ;
if ( ! V_2 -> V_73 || ! V_2 -> V_240 )
return - V_316 ;
if ( V_2 -> V_240 [ V_301 ] )
return - V_317 ;
if ( ! V_312 -> V_318 && ! V_312 -> V_141 ) {
F_145 ( L_67 , V_301 ) ;
return - V_96 ;
}
V_197 = F_147 ( sizeof( * V_197 ) , V_77 ) ;
if ( ! V_197 )
return - V_242 ;
V_197 -> V_313 = V_313 ;
V_197 -> V_138 = ! ! V_312 -> V_138 ;
V_197 -> V_119 = V_312 -> V_138 || V_312 -> V_119 ;
V_197 -> V_319 = V_197 -> V_119 ;
V_197 -> V_141 = ! ! V_312 -> V_141 ;
if ( ! V_2 -> V_288 ) {
V_197 -> V_20 = V_20 ;
} else {
V_197 -> V_280 . V_320 = F_139 ;
V_197 -> V_280 . V_321 = & V_2 -> V_251 -> V_280 ;
V_197 -> V_280 . V_322 = V_323 ;
F_177 ( & V_197 -> V_280 , & V_2 -> V_168 ) ;
F_178 ( & V_197 -> V_280 , L_68 , V_20 ) ;
V_197 -> V_20 = F_179 ( & V_197 -> V_280 ) ;
V_33 = F_180 ( & V_197 -> V_280 ) ;
if ( V_33 ) {
F_181 ( L_69 , V_301 , V_33 ) ;
F_182 ( & V_197 -> V_280 ) ;
goto V_324;
}
}
V_2 -> V_240 [ V_301 ] = V_197 ;
if ( V_312 -> V_318 ) {
V_33 = F_183 ( V_197 , V_312 -> V_318 ) ;
if ( V_33 )
goto V_325;
}
V_314 = F_159 ( V_326 , V_77 ) ;
V_315 = L_70 ;
if ( F_74 ( V_197 ) ) {
V_315 = L_71 ;
if ( V_314 ) {
V_315 = F_184 ( V_197 -> V_107 , V_314 , V_326 ) ;
if ( F_171 ( V_315 ) )
V_315 = L_71 ;
}
}
F_181 ( L_72 ,
V_197 -> V_141 ? L_73 : L_74 ,
V_197 -> V_119 ? L_75 : L_74 ,
V_197 -> V_138 ? L_76 : L_74 ,
V_315 ) ;
F_156 ( V_314 ) ;
return 0 ;
V_325:
if ( V_2 -> V_288 )
F_161 ( & V_197 -> V_280 ) ;
F_77 ( V_197 ) ;
V_2 -> V_240 [ V_301 ] = NULL ;
V_324:
F_156 ( V_197 ) ;
return V_33 ;
}
int F_185 ( struct V_1 * V_2 , struct V_327 * V_312 )
{
char V_48 [ 8 ] ;
int V_196 , V_33 ;
for ( V_196 = 0 ; V_196 < V_2 -> V_73 ; ++ V_196 ) {
snprintf ( V_48 , sizeof( V_48 ) , L_77 , V_196 ) ;
V_33 = F_176 ( V_2 , & V_312 -> V_240 [ V_196 ] , V_196 , V_48 , NULL ) ;
if ( V_33 )
goto V_328;
}
F_181 ( L_78 , V_2 -> V_73 ) ;
return 0 ;
V_328:
F_162 ( V_2 , V_196 ) ;
return V_33 ;
}
void F_186 ( struct V_1 * V_2 , const char * V_329 ,
const char * V_330 )
{
int V_196 ;
V_196 = F_187 () ;
snprintf ( V_2 -> V_142 , sizeof( V_2 -> V_142 ) ,
L_79 , V_329 ? : L_80 ,
V_330 ? : ( ( * V_2 -> V_240 ) -> V_138
? L_81
: L_82 ) ,
V_196 ) ;
}
int F_188 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_10 ;
V_2 -> V_24 =
F_189 ( F_119 , V_2 , L_83 ) ;
if ( F_171 ( V_2 -> V_24 ) ) {
V_2 -> V_9 = V_266 ;
return F_172 ( V_2 -> V_24 ) ;
}
F_8 ( V_2 , L_84 , F_190 ( V_2 -> V_24 ) ) ;
F_12 ( V_2 -> V_24 ) ;
return 0 ;
}
static void V_286 ( struct V_331 * V_285 )
{
struct V_1 * V_2 = F_4 ( V_285 , struct V_1 , V_285 ) ;
if ( V_2 -> V_9 != V_266 ) {
F_13 ( V_2 , V_262 ) ;
F_191 ( & V_2 -> V_278 ) ;
}
if ( F_114 ( V_2 -> V_240 ) ) {
struct V_84 * * V_332 = V_2 -> V_240 ;
unsigned V_196 = V_2 -> V_73 ;
for (; V_196 ; -- V_196 , ++ V_332 ) {
struct V_84 * V_197 = * V_332 ;
if ( ! V_197 )
continue;
F_77 ( V_197 ) ;
if ( V_2 -> V_288 )
F_161 ( & V_197 -> V_280 ) ;
F_156 ( V_197 ) ;
}
F_156 ( V_2 -> V_240 ) ;
}
F_155 ( V_2 -> V_247 , V_2 -> V_246 ) ;
if ( V_2 -> V_287 )
F_156 ( V_2 ) ;
}
static int F_192 ( struct V_333 * V_334 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_335 * V_251 = V_334 -> V_265 -> V_251 ;
int V_196 ;
struct V_18 * V_19 ;
unsigned V_336 ;
int V_337 ;
struct V_338 * V_339 ;
V_339 = F_193 ( V_7 -> V_340 ) ;
if ( ! V_339 -> V_341 ) {
V_337 = F_168 ( V_4 -> V_2 , V_334 -> V_265 ,
V_4 -> V_2 -> V_175 ) ;
if ( V_337 )
return V_337 ;
F_186 ( V_4 -> V_2 , NULL , NULL ) ;
V_337 = F_188 ( V_4 -> V_2 ) ;
if ( V_337 )
return V_337 ;
}
V_4 -> V_251 = V_251 ;
V_196 = F_194 ( V_334 , V_7 ) ;
if ( V_196 < 0 )
return V_196 ;
V_298 . V_342 = V_196 ;
V_4 -> V_67 = V_196 ;
V_19 = F_195 ( V_251 , & V_343 ) ;
if ( ! V_19 )
goto V_344;
V_19 -> V_37 = V_4 -> V_2 ;
V_4 -> V_21 = V_19 ;
V_19 = F_195 ( V_251 , & V_345 ) ;
if ( ! V_19 )
goto V_344;
V_19 -> V_37 = V_4 -> V_2 ;
V_4 -> V_22 = V_19 ;
V_346 . V_347 =
V_343 . V_347 ;
V_348 . V_347 =
V_345 . V_347 ;
V_336 = F_196 ( unsigned , V_102 / 1024 , 15 ) ;
V_349 . V_347 =
V_343 . V_347 ;
V_350 . V_351 = V_336 ;
V_352 . V_347 =
V_345 . V_347 ;
V_353 . V_351 = V_336 ;
V_337 = F_197 ( V_7 , V_354 , V_355 ,
V_356 ) ;
if ( V_337 )
goto V_344;
return 0 ;
V_344:
ERROR ( V_4 , L_85 ) ;
return - V_357 ;
}
static void F_198 ( struct V_333 * V_334 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_8 ( V_4 , L_86 ) ;
if ( V_4 -> V_2 -> V_4 == V_4 ) {
V_4 -> V_2 -> V_243 = NULL ;
F_13 ( V_4 -> V_2 , V_257 ) ;
F_199 ( V_2 -> V_250 , V_2 -> V_4 != V_4 ) ;
}
F_200 ( & V_4 -> V_8 ) ;
}
static inline struct V_358 * F_201 ( struct V_359 * V_360 )
{
return F_4 ( F_202 ( V_360 ) , struct V_358 , V_361 ) ;
}
static inline struct V_338 * F_203 ( struct V_359 * V_360 )
{
return F_4 ( F_202 ( V_360 ) , struct V_338 ,
V_362 . V_361 ) ;
}
static void F_204 ( struct V_359 * V_360 )
{
struct V_358 * V_363 ;
V_363 = F_201 ( V_360 ) ;
F_156 ( V_363 ) ;
}
static T_4 F_205 ( struct V_358 * V_339 , char * V_364 )
{
struct V_338 * V_338 ;
V_338 = F_203 ( V_339 -> V_361 . V_365 . V_366 ) ;
return F_132 ( V_339 -> V_197 , & V_338 -> V_2 -> V_168 , V_364 ) ;
}
static T_4 F_206 ( struct V_358 * V_339 ,
const char * V_364 , T_6 V_158 )
{
struct V_338 * V_338 ;
V_338 = F_203 ( V_339 -> V_361 . V_365 . V_366 ) ;
return F_138 ( V_339 -> V_197 , & V_338 -> V_2 -> V_168 , V_364 , V_158 ) ;
}
static T_4 F_207 ( struct V_358 * V_339 , char * V_364 )
{
return F_127 ( V_339 -> V_197 , V_364 ) ;
}
static T_4 F_208 ( struct V_358 * V_339 ,
const char * V_364 , T_6 V_158 )
{
struct V_338 * V_338 ;
V_338 = F_203 ( V_339 -> V_361 . V_365 . V_366 ) ;
return F_134 ( V_339 -> V_197 , & V_338 -> V_2 -> V_168 , V_364 , V_158 ) ;
}
static T_4 F_209 ( struct V_358 * V_339 ,
char * V_364 )
{
return F_210 ( V_339 -> V_197 , V_364 ) ;
}
static T_4 F_211 ( struct V_358 * V_339 ,
const char * V_364 , T_6 V_158 )
{
return F_212 ( V_339 -> V_197 , V_364 , V_158 ) ;
}
static T_4 F_213 ( struct V_358 * V_339 , char * V_364 )
{
return F_214 ( V_339 -> V_197 , V_364 ) ;
}
static T_4 F_215 ( struct V_358 * V_339 ,
const char * V_364 , T_6 V_158 )
{
struct V_338 * V_338 ;
V_338 = F_203 ( V_339 -> V_361 . V_365 . V_366 ) ;
return F_216 ( V_339 -> V_197 , & V_338 -> V_2 -> V_168 , V_364 ,
V_158 ) ;
}
static T_4 F_217 ( struct V_358 * V_339 , char * V_364 )
{
return F_129 ( V_339 -> V_197 , V_364 ) ;
}
static T_4 F_218 ( struct V_358 * V_339 ,
const char * V_364 , T_6 V_158 )
{
return F_136 ( V_339 -> V_197 , V_364 , V_158 ) ;
}
static struct V_367 * F_219 ( struct V_367 * V_361 ,
const char * V_20 )
{
struct V_358 * V_339 ;
struct V_338 * V_338 ;
struct V_311 V_368 ;
char * V_369 ;
V_60 V_370 ;
int V_337 ;
V_369 = strchr ( V_20 , '.' ) ;
if ( ! V_369 ) {
F_145 ( L_87 ) ;
return F_148 ( - V_96 ) ;
}
V_369 ++ ;
V_337 = F_220 ( V_369 , 0 , & V_370 ) ;
if ( V_337 )
return F_148 ( V_337 ) ;
V_338 = F_203 ( & V_361 -> V_365 ) ;
if ( V_370 >= V_233 )
return F_148 ( - V_371 ) ;
F_221 ( & V_338 -> V_28 ) ;
if ( V_338 -> V_372 || V_338 -> V_2 -> V_240 [ V_370 ] ) {
V_337 = - V_317 ;
goto V_373;
}
V_339 = F_147 ( sizeof( * V_339 ) , V_77 ) ;
if ( ! V_339 ) {
V_337 = - V_242 ;
goto V_373;
}
memset ( & V_368 , 0 , sizeof( V_368 ) ) ;
V_368 . V_141 = true ;
V_337 = F_176 ( V_338 -> V_2 , & V_368 , V_370 , V_20 ,
( const char * * ) & V_361 -> V_365 . V_374 ) ;
if ( V_337 ) {
F_156 ( V_339 ) ;
goto V_373;
}
V_339 -> V_197 = V_338 -> V_2 -> V_240 [ V_370 ] ;
V_339 -> V_375 = V_370 ;
F_222 ( & V_338 -> V_28 ) ;
F_223 ( & V_339 -> V_361 , V_20 , & V_376 ) ;
return & V_339 -> V_361 ;
V_373:
F_222 ( & V_338 -> V_28 ) ;
return F_148 ( V_337 ) ;
}
static void F_224 ( struct V_367 * V_361 , struct V_359 * V_360 )
{
struct V_358 * V_363 ;
struct V_338 * V_338 ;
V_363 = F_201 ( V_360 ) ;
V_338 = F_203 ( & V_361 -> V_365 ) ;
F_221 ( & V_338 -> V_28 ) ;
if ( V_338 -> V_372 ) {
struct V_359 * V_251 ;
V_251 = V_361 -> V_365 . V_366 -> V_366 ;
F_225 ( V_251 ) ;
}
F_160 ( V_363 -> V_197 , V_338 -> V_2 -> V_288 ) ;
V_338 -> V_2 -> V_240 [ V_363 -> V_375 ] = NULL ;
V_363 -> V_375 = 0 ;
F_222 ( & V_338 -> V_28 ) ;
F_226 ( V_360 ) ;
}
static void F_227 ( struct V_359 * V_360 )
{
struct V_338 * V_339 = F_203 ( V_360 ) ;
F_228 ( & V_339 -> V_362 ) ;
}
static T_4 F_229 ( struct V_338 * V_339 , char * V_364 )
{
int V_377 ;
F_221 ( & V_339 -> V_28 ) ;
V_377 = sprintf ( V_364 , L_88 , V_339 -> V_2 -> V_175 ) ;
F_222 ( & V_339 -> V_28 ) ;
return V_377 ;
}
static T_4 F_230 ( struct V_338 * V_339 , const char * V_364 ,
T_6 V_158 )
{
int V_337 ;
bool V_378 ;
F_221 ( & V_339 -> V_28 ) ;
if ( V_339 -> V_372 ) {
F_222 ( & V_339 -> V_28 ) ;
return - V_317 ;
}
V_337 = F_231 ( V_364 , & V_378 ) ;
if ( ! V_337 ) {
V_339 -> V_2 -> V_175 = V_378 ;
V_337 = V_158 ;
}
F_222 ( & V_339 -> V_28 ) ;
return V_337 ;
}
static T_4 F_232 ( struct V_338 * V_339 , char * V_364 )
{
int V_377 ;
F_221 ( & V_339 -> V_28 ) ;
V_377 = sprintf ( V_364 , L_88 , V_339 -> V_2 -> V_246 ) ;
F_222 ( & V_339 -> V_28 ) ;
return V_377 ;
}
static T_4 F_233 ( struct V_338 * V_339 ,
const char * V_364 , T_6 V_158 )
{
int V_337 ;
V_60 V_370 ;
F_221 ( & V_339 -> V_28 ) ;
if ( V_339 -> V_372 ) {
V_337 = - V_317 ;
goto V_379;
}
V_337 = F_220 ( V_364 , 0 , & V_370 ) ;
if ( V_337 )
goto V_379;
V_337 = F_144 ( V_370 ) ;
if ( V_337 )
goto V_379;
F_157 ( V_339 -> V_2 , V_370 ) ;
V_337 = V_158 ;
V_379:
F_222 ( & V_339 -> V_28 ) ;
return V_337 ;
}
static void F_234 ( struct V_380 * V_340 )
{
struct V_338 * V_339 ;
V_339 = F_193 ( V_340 ) ;
F_142 ( V_339 -> V_2 ) ;
F_156 ( V_339 ) ;
}
static struct V_380 * F_235 ( void )
{
struct V_338 * V_339 ;
struct V_311 V_368 ;
int V_33 ;
V_339 = F_147 ( sizeof( * V_339 ) , V_77 ) ;
if ( ! V_339 )
return F_148 ( - V_242 ) ;
F_236 ( & V_339 -> V_28 ) ;
V_339 -> V_362 . V_381 = F_234 ;
V_339 -> V_2 = F_146 ( V_339 -> V_2 ) ;
if ( F_171 ( V_339 -> V_2 ) ) {
V_33 = F_172 ( V_339 -> V_2 ) ;
goto V_382;
}
V_33 = F_165 ( V_339 -> V_2 , V_233 ) ;
if ( V_33 )
goto V_382;
V_33 = F_157 ( V_339 -> V_2 ,
V_383 ) ;
if ( V_33 )
goto V_384;
F_181 ( V_385 L_89 V_386 L_90 ) ;
memset ( & V_368 , 0 , sizeof( V_368 ) ) ;
V_368 . V_141 = true ;
V_33 = F_176 ( V_339 -> V_2 , & V_368 , 0 , L_91 ,
( const char * * ) & V_339 -> V_362 . V_361 . V_365 . V_374 ) ;
V_339 -> V_387 . V_197 = V_339 -> V_2 -> V_240 [ 0 ] ;
V_339 -> V_387 . V_375 = 0 ;
F_223 ( & V_339 -> V_387 . V_361 , L_91 , & V_376 ) ;
V_339 -> V_388 [ 0 ] = & V_339 -> V_387 . V_361 ;
V_339 -> V_362 . V_361 . V_388 = V_339 -> V_388 ;
F_223 ( & V_339 -> V_362 . V_361 , L_74 , & V_389 ) ;
return & V_339 -> V_362 ;
V_384:
F_156 ( V_339 -> V_2 -> V_240 ) ;
V_382:
F_156 ( V_339 ) ;
return F_148 ( V_33 ) ;
}
static void F_237 ( struct V_6 * V_7 )
{
struct V_5 * V_4 ;
struct V_338 * V_339 ;
V_4 = F_4 ( V_7 , struct V_5 , V_8 ) ;
V_339 = F_4 ( V_7 -> V_340 , struct V_338 , V_362 ) ;
F_221 ( & V_339 -> V_28 ) ;
V_339 -> V_372 -- ;
F_222 ( & V_339 -> V_28 ) ;
F_156 ( V_4 ) ;
}
static struct V_6 * F_238 ( struct V_380 * V_340 )
{
struct V_338 * V_339 = F_193 ( V_340 ) ;
struct V_1 * V_2 = V_339 -> V_2 ;
struct V_5 * V_4 ;
unsigned V_73 , V_196 ;
V_4 = F_147 ( sizeof( * V_4 ) , V_77 ) ;
if ( F_46 ( ! V_4 ) )
return F_148 ( - V_242 ) ;
F_221 ( & V_339 -> V_28 ) ;
if ( ! V_339 -> V_372 ) {
for ( V_73 = V_196 = 0 ; V_196 < V_233 ; ++ V_196 )
if ( V_2 -> V_240 [ V_196 ] )
V_73 = V_196 + 1 ;
if ( ! V_73 )
F_239 ( L_92 ) ;
else
V_2 -> V_73 = V_73 ;
F_181 ( L_93 , V_2 -> V_73 ) ;
}
V_339 -> V_372 ++ ;
F_222 ( & V_339 -> V_28 ) ;
V_4 -> V_8 . V_20 = V_385 ;
V_4 -> V_8 . V_390 = F_192 ;
V_4 -> V_8 . V_391 = F_198 ;
V_4 -> V_8 . V_392 = F_26 ;
V_4 -> V_8 . V_393 = F_110 ;
V_4 -> V_8 . V_394 = F_111 ;
V_4 -> V_8 . V_395 = F_237 ;
V_4 -> V_2 = V_2 ;
return & V_4 -> V_8 ;
}
void F_240 ( struct V_327 * V_312 ,
const struct V_396 * V_397 ,
unsigned int V_246 )
{
struct V_311 * V_197 ;
unsigned V_196 ;
V_312 -> V_73 =
F_30 ( V_397 -> V_240 ? : ( V_397 -> V_398 ? : 1u ) ,
( unsigned ) V_233 ) ;
for ( V_196 = 0 , V_197 = V_312 -> V_240 ; V_196 < V_312 -> V_73 ; ++ V_196 , ++ V_197 ) {
V_197 -> V_119 = ! ! V_397 -> V_119 [ V_196 ] ;
V_197 -> V_138 = ! ! V_397 -> V_138 [ V_196 ] ;
V_197 -> V_141 = ! ! V_397 -> V_141 [ V_196 ] ;
V_197 -> V_318 =
V_397 -> V_398 > V_196 && V_397 -> V_132 [ V_196 ] [ 0 ]
? V_397 -> V_132 [ V_196 ]
: NULL ;
}
V_312 -> V_399 = NULL ;
V_312 -> V_400 = NULL ;
V_312 -> V_275 = NULL ;
V_312 -> V_401 = NULL ;
V_312 -> V_175 = V_397 -> V_378 ;
V_312 -> V_246 = V_246 ;
}
