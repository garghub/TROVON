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
static int F_26 ( struct V_1 * V_2 )
{
int V_51 = F_27 ( V_2 -> V_52 ) - 1 ;
while ( V_51 >= 0 && ! V_2 -> V_52 [ V_51 ] )
-- V_51 ;
return V_51 ;
}
static int F_28 ( struct V_6 * V_7 ,
const struct V_53 * V_54 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_39 * V_40 = V_4 -> V_2 -> V_35 ;
T_1 V_55 = F_29 ( V_54 -> V_56 ) ;
T_1 V_57 = F_29 ( V_54 -> V_58 ) ;
T_1 V_59 = F_29 ( V_54 -> V_60 ) ;
if ( ! F_30 ( V_4 -> V_2 ) )
return - V_61 ;
++ V_4 -> V_2 -> V_30 ;
V_40 -> V_41 = NULL ;
V_40 -> V_13 = 0 ;
F_25 ( V_4 , L_7 , ( V_62 * ) V_54 , sizeof( * V_54 ) ) ;
switch ( V_54 -> V_63 ) {
case V_64 :
if ( V_54 -> V_65 !=
( V_66 | V_67 | V_68 ) )
break;
if ( V_55 != V_4 -> V_69 || V_57 != 0 ||
V_59 != 0 )
return - V_70 ;
F_8 ( V_4 , L_8 ) ;
F_13 ( V_4 -> V_2 , V_71 ) ;
return V_72 ;
case V_73 :
if ( V_54 -> V_65 !=
( V_74 | V_67 | V_68 ) )
break;
if ( V_55 != V_4 -> V_69 || V_57 != 0 ||
V_59 != 1 )
return - V_70 ;
F_31 ( V_4 , L_9 ) ;
* ( V_62 * ) V_40 -> V_48 = F_26 ( V_4 -> V_2 ) ;
V_40 -> V_13 = F_32 ( ( T_1 ) 1 , V_59 ) ;
return F_17 ( V_4 -> V_2 ) ;
}
F_31 ( V_4 ,
L_10 ,
V_54 -> V_65 , V_54 -> V_63 ,
F_29 ( V_54 -> V_58 ) , V_55 , V_59 ) ;
return - V_61 ;
}
static void F_33 ( struct V_5 * V_4 , struct V_18 * V_19 ,
struct V_39 * V_40 , int * V_75 ,
enum V_76 * V_9 )
{
int V_33 ;
if ( V_19 == V_4 -> V_21 )
F_25 ( V_4 , L_2 , V_40 -> V_48 , V_40 -> V_13 ) ;
F_34 ( & V_4 -> V_2 -> V_28 ) ;
* V_75 = 1 ;
* V_9 = V_77 ;
F_35 ( & V_4 -> V_2 -> V_28 ) ;
V_33 = F_18 ( V_19 , V_40 , V_78 ) ;
if ( V_33 == 0 )
return;
* V_75 = 0 ;
* V_9 = V_47 ;
if ( V_33 != - V_38 && ! ( V_33 == - V_61 && V_40 -> V_13 == 0 ) )
F_19 ( V_4 , L_5 , V_19 -> V_20 , V_33 ) ;
}
static bool F_36 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_30 ( V_2 ) )
return false ;
F_33 ( V_2 -> V_4 , V_2 -> V_4 -> V_21 ,
V_12 -> V_79 , & V_12 -> V_46 , & V_12 -> V_9 ) ;
return true ;
}
static bool F_37 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_30 ( V_2 ) )
return false ;
F_33 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ,
V_12 -> V_17 , & V_12 -> V_49 , & V_12 -> V_9 ) ;
return true ;
}
static int F_38 ( struct V_1 * V_2 , bool V_80 )
{
int V_33 = 0 ;
for (; ; ) {
if ( V_80 )
F_39 () ;
F_40 ( V_81 ) ;
if ( F_41 ( V_82 ) ) {
V_33 = - V_83 ;
break;
}
if ( V_2 -> V_23 )
break;
F_42 () ;
}
F_43 ( V_84 ) ;
V_2 -> V_23 = 0 ;
F_44 () ;
return V_33 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
T_2 V_87 ;
struct V_11 * V_12 ;
int V_33 ;
T_2 V_88 ;
T_3 V_89 , V_90 ;
unsigned int V_91 ;
T_4 V_92 ;
if ( V_2 -> V_93 [ 0 ] == V_94 )
V_87 = F_46 ( & V_2 -> V_93 [ 1 ] ) ;
else {
V_87 = F_47 ( & V_2 -> V_93 [ 2 ] ) ;
if ( ( V_2 -> V_93 [ 1 ] & ~ 0x18 ) != 0 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
}
if ( V_87 >= V_86 -> V_98 ) {
V_86 -> V_95 = V_99 ;
return - V_97 ;
}
V_89 = ( ( T_3 ) V_87 ) << V_86 -> V_100 ;
V_88 = V_2 -> V_101 ;
if ( F_48 ( V_88 == 0 ) )
return - V_102 ;
for (; ; ) {
V_91 = F_32 ( V_88 , V_103 ) ;
V_91 = F_32 ( ( T_3 ) V_91 ,
V_86 -> V_104 - V_89 ) ;
V_12 = V_2 -> V_105 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_38 ( V_2 , false ) ;
if ( V_33 )
return V_33 ;
}
if ( V_91 == 0 ) {
V_86 -> V_95 =
V_99 ;
V_86 -> V_106 =
V_89 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
V_12 -> V_79 -> V_13 = 0 ;
V_12 -> V_9 = V_50 ;
break;
}
V_90 = V_89 ;
V_92 = F_49 ( V_86 -> V_108 ,
( char V_109 * ) V_12 -> V_48 ,
V_91 , & V_90 ) ;
F_50 ( V_86 , L_11 , V_91 ,
( unsigned long long ) V_89 , ( int ) V_92 ) ;
if ( F_41 ( V_82 ) )
return - V_83 ;
if ( V_92 < 0 ) {
F_51 ( V_86 , L_12 , ( int ) V_92 ) ;
V_92 = 0 ;
} else if ( V_92 < V_91 ) {
F_51 ( V_86 , L_13 ,
( int ) V_92 , V_91 ) ;
V_92 = F_52 ( V_92 , V_86 -> V_110 ) ;
}
V_89 += V_92 ;
V_88 -= V_92 ;
V_2 -> V_111 -= V_92 ;
V_12 -> V_79 -> V_13 = V_92 ;
V_12 -> V_9 = V_50 ;
if ( V_92 < V_91 ) {
V_86 -> V_95 = V_112 ;
V_86 -> V_106 =
V_89 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
break;
}
if ( V_88 == 0 )
break;
V_12 -> V_79 -> V_113 = 0 ;
if ( ! F_36 ( V_2 , V_12 ) )
return - V_102 ;
V_2 -> V_105 = V_12 -> V_114 ;
}
return - V_102 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
T_2 V_87 ;
struct V_11 * V_12 ;
int V_115 ;
T_2 V_116 , V_117 ;
T_3 V_118 , V_89 , V_90 ;
unsigned int V_91 ;
T_4 V_119 ;
int V_33 ;
if ( V_86 -> V_120 ) {
V_86 -> V_95 = V_121 ;
return - V_97 ;
}
F_22 ( & V_86 -> V_108 -> V_122 ) ;
V_86 -> V_108 -> V_123 &= ~ V_124 ;
F_23 ( & V_86 -> V_108 -> V_122 ) ;
if ( V_2 -> V_93 [ 0 ] == V_125 )
V_87 = F_46 ( & V_2 -> V_93 [ 1 ] ) ;
else {
V_87 = F_47 ( & V_2 -> V_93 [ 2 ] ) ;
if ( V_2 -> V_93 [ 1 ] & ~ 0x18 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
if ( ! V_86 -> V_126 && ( V_2 -> V_93 [ 1 ] & 0x08 ) ) {
F_22 ( & V_86 -> V_108 -> V_122 ) ;
V_86 -> V_108 -> V_123 |= V_124 ;
F_23 ( & V_86 -> V_108 -> V_122 ) ;
}
}
if ( V_87 >= V_86 -> V_98 ) {
V_86 -> V_95 = V_99 ;
return - V_97 ;
}
V_115 = 1 ;
V_89 = V_118 = ( ( T_3 ) V_87 ) << V_86 -> V_100 ;
V_116 = V_2 -> V_101 ;
V_117 = V_2 -> V_101 ;
while ( V_117 > 0 ) {
V_12 = V_2 -> V_105 ;
if ( V_12 -> V_9 == V_47 && V_115 ) {
V_91 = F_32 ( V_116 , V_103 ) ;
if ( V_118 >= V_86 -> V_104 ) {
V_115 = 0 ;
V_86 -> V_95 =
V_99 ;
V_86 -> V_106 =
V_118 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
continue;
}
V_118 += V_91 ;
V_2 -> V_127 -= V_91 ;
V_116 -= V_91 ;
if ( V_116 == 0 )
V_115 = 0 ;
F_6 ( V_2 , V_12 , V_91 ) ;
if ( ! F_37 ( V_2 , V_12 ) )
return - V_102 ;
V_2 -> V_105 = V_12 -> V_114 ;
continue;
}
V_12 = V_2 -> V_128 ;
if ( V_12 -> V_9 == V_47 && ! V_115 )
break;
if ( V_12 -> V_9 == V_50 ) {
F_44 () ;
V_2 -> V_128 = V_12 -> V_114 ;
V_12 -> V_9 = V_47 ;
if ( V_12 -> V_17 -> V_42 != 0 ) {
V_86 -> V_95 = V_129 ;
V_86 -> V_106 =
V_89 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
break;
}
V_91 = V_12 -> V_17 -> V_43 ;
if ( V_86 -> V_104 - V_89 < V_91 ) {
F_54 ( V_86 ,
L_14 ,
V_91 , ( unsigned long long ) V_89 ,
( unsigned long long ) V_86 -> V_104 ) ;
V_91 = V_86 -> V_104 - V_89 ;
}
V_91 = F_32 ( V_91 , V_12 -> V_15 ) ;
V_91 = F_52 ( V_91 , V_86 -> V_110 ) ;
if ( V_91 == 0 )
goto V_130;
V_90 = V_89 ;
V_119 = F_55 ( V_86 -> V_108 ,
( char V_109 * ) V_12 -> V_48 ,
V_91 , & V_90 ) ;
F_50 ( V_86 , L_15 , V_91 ,
( unsigned long long ) V_89 , ( int ) V_119 ) ;
if ( F_41 ( V_82 ) )
return - V_83 ;
if ( V_119 < 0 ) {
F_51 ( V_86 , L_16 ,
( int ) V_119 ) ;
V_119 = 0 ;
} else if ( V_119 < V_91 ) {
F_51 ( V_86 , L_17 ,
( int ) V_119 , V_91 ) ;
V_119 = F_52 ( V_119 , V_86 -> V_110 ) ;
}
V_89 += V_119 ;
V_117 -= V_119 ;
V_2 -> V_111 -= V_119 ;
if ( V_119 < V_91 ) {
V_86 -> V_95 = V_131 ;
V_86 -> V_106 =
V_89 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
break;
}
V_130:
if ( V_12 -> V_17 -> V_43 < V_12 -> V_15 ) {
V_2 -> V_132 = 1 ;
break;
}
continue;
}
V_33 = F_38 ( V_2 , false ) ;
if ( V_33 )
return V_33 ;
}
return - V_102 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
int V_33 ;
V_33 = F_57 ( V_86 ) ;
if ( V_33 )
V_86 -> V_95 = V_131 ;
return 0 ;
}
static void F_58 ( struct V_85 * V_86 )
{
struct V_133 * V_108 = V_86 -> V_108 ;
struct V_134 * V_134 = F_59 ( V_108 ) ;
unsigned long V_33 ;
V_33 = F_60 ( V_134 -> V_135 , 0 , - 1 ) ;
F_50 ( V_86 , L_18 , V_33 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
T_2 V_87 ;
T_2 V_136 ;
struct V_11 * V_12 = V_2 -> V_105 ;
T_3 V_89 , V_90 ;
T_2 V_88 ;
unsigned int V_91 ;
T_4 V_92 ;
V_87 = F_47 ( & V_2 -> V_93 [ 2 ] ) ;
if ( V_87 >= V_86 -> V_98 ) {
V_86 -> V_95 = V_99 ;
return - V_97 ;
}
if ( V_2 -> V_93 [ 1 ] & ~ 0x10 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
V_136 = F_62 ( & V_2 -> V_93 [ 7 ] ) ;
if ( F_48 ( V_136 == 0 ) )
return - V_102 ;
V_88 = V_136 << V_86 -> V_100 ;
V_89 = ( ( T_3 ) V_87 ) << V_86 -> V_100 ;
F_57 ( V_86 ) ;
if ( F_41 ( V_82 ) )
return - V_83 ;
F_58 ( V_86 ) ;
if ( F_41 ( V_82 ) )
return - V_83 ;
while ( V_88 > 0 ) {
V_91 = F_32 ( V_88 , V_103 ) ;
V_91 = F_32 ( ( T_3 ) V_91 ,
V_86 -> V_104 - V_89 ) ;
if ( V_91 == 0 ) {
V_86 -> V_95 =
V_99 ;
V_86 -> V_106 =
V_89 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
break;
}
V_90 = V_89 ;
V_92 = F_49 ( V_86 -> V_108 ,
( char V_109 * ) V_12 -> V_48 ,
V_91 , & V_90 ) ;
F_50 ( V_86 , L_11 , V_91 ,
( unsigned long long ) V_89 ,
( int ) V_92 ) ;
if ( F_41 ( V_82 ) )
return - V_83 ;
if ( V_92 < 0 ) {
F_51 ( V_86 , L_19 , ( int ) V_92 ) ;
V_92 = 0 ;
} else if ( V_92 < V_91 ) {
F_51 ( V_86 , L_20 ,
( int ) V_92 , V_91 ) ;
V_92 = F_52 ( V_92 , V_86 -> V_110 ) ;
}
if ( V_92 == 0 ) {
V_86 -> V_95 = V_112 ;
V_86 -> V_106 =
V_89 >> V_86 -> V_100 ;
V_86 -> V_107 = 1 ;
break;
}
V_89 += V_92 ;
V_88 -= V_92 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
if ( ! V_86 ) {
V_2 -> V_137 = 1 ;
memset ( V_48 , 0 , 36 ) ;
V_48 [ 0 ] = V_138 ;
V_48 [ 4 ] = 31 ;
return 36 ;
}
V_48 [ 0 ] = V_86 -> V_139 ? V_140 : V_141 ;
V_48 [ 1 ] = V_86 -> V_142 ? 0x80 : 0 ;
V_48 [ 2 ] = 2 ;
V_48 [ 3 ] = 2 ;
V_48 [ 4 ] = 31 ;
V_48 [ 5 ] = 0 ;
V_48 [ 6 ] = 0 ;
V_48 [ 7 ] = 0 ;
memcpy ( V_48 + 8 , V_2 -> V_143 , sizeof V_2 -> V_143 ) ;
return 36 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
T_2 V_144 , V_145 ;
int V_146 ;
#if 0
if (curlun && curlun->unit_attention_data != SS_NO_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
}
#endif
if ( ! V_86 ) {
V_2 -> V_137 = 1 ;
V_144 = V_147 ;
V_145 = 0 ;
V_146 = 0 ;
} else {
V_144 = V_86 -> V_95 ;
V_145 = V_86 -> V_106 ;
V_146 = V_86 -> V_107 << 7 ;
V_86 -> V_95 = V_148 ;
V_86 -> V_106 = 0 ;
V_86 -> V_107 = 0 ;
}
memset ( V_48 , 0 , 18 ) ;
V_48 [ 0 ] = V_146 | 0x70 ;
V_48 [ 2 ] = F_65 ( V_144 ) ;
F_66 ( V_145 , & V_48 [ 3 ] ) ;
V_48 [ 7 ] = 18 - 8 ;
V_48 [ 12 ] = F_67 ( V_144 ) ;
V_48 [ 13 ] = F_68 ( V_144 ) ;
return 18 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
T_2 V_87 = F_47 ( & V_2 -> V_93 [ 2 ] ) ;
int V_149 = V_2 -> V_93 [ 8 ] ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
if ( V_149 > 1 || ( V_149 == 0 && V_87 != 0 ) ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
F_66 ( V_86 -> V_98 - 1 , & V_48 [ 0 ] ) ;
F_66 ( V_86 -> V_110 , & V_48 [ 4 ] ) ;
return 8 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
int V_150 = V_2 -> V_93 [ 1 ] & 0x02 ;
T_2 V_87 = F_47 ( & V_2 -> V_93 [ 2 ] ) ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
if ( V_2 -> V_93 [ 1 ] & ~ 0x02 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
if ( V_87 >= V_86 -> V_98 ) {
V_86 -> V_95 = V_99 ;
return - V_97 ;
}
memset ( V_48 , 0 , 8 ) ;
V_48 [ 0 ] = 0x01 ;
F_71 ( & V_48 [ 4 ] , V_150 , V_87 ) ;
return 8 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
int V_150 = V_2 -> V_93 [ 1 ] & 0x02 ;
int V_151 = V_2 -> V_93 [ 6 ] ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
if ( ( V_2 -> V_93 [ 1 ] & ~ 0x02 ) != 0 ||
V_151 > 1 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
memset ( V_48 , 0 , 20 ) ;
V_48 [ 1 ] = ( 20 - 2 ) ;
V_48 [ 2 ] = 1 ;
V_48 [ 3 ] = 1 ;
V_48 [ 5 ] = 0x16 ;
V_48 [ 6 ] = 0x01 ;
F_71 ( & V_48 [ 8 ] , V_150 , 0 ) ;
V_48 [ 13 ] = 0x16 ;
V_48 [ 14 ] = 0xAA ;
F_71 ( & V_48 [ 16 ] , V_150 , V_86 -> V_98 ) ;
return 20 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
int V_152 = V_2 -> V_93 [ 0 ] ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
V_62 * V_153 = V_48 ;
int V_154 , V_155 ;
int V_156 , V_157 ;
int V_158 = 0 ;
int V_159 , V_160 ;
if ( ( V_2 -> V_93 [ 1 ] & ~ 0x08 ) != 0 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
V_154 = V_2 -> V_93 [ 2 ] >> 6 ;
V_155 = V_2 -> V_93 [ 2 ] & 0x3f ;
if ( V_154 == 3 ) {
V_86 -> V_95 = V_161 ;
return - V_97 ;
}
V_156 = ( V_154 == 1 ) ;
V_157 = ( V_155 == 0x3f ) ;
memset ( V_48 , 0 , 8 ) ;
if ( V_152 == V_162 ) {
V_48 [ 2 ] = ( V_86 -> V_120 ? 0x80 : 0x00 ) ;
V_48 += 4 ;
V_160 = 255 ;
} else {
V_48 [ 3 ] = ( V_86 -> V_120 ? 0x80 : 0x00 ) ;
V_48 += 8 ;
V_160 = 65535 ;
}
if ( V_155 == 0x08 || V_157 ) {
V_158 = 1 ;
V_48 [ 0 ] = 0x08 ;
V_48 [ 1 ] = 10 ;
memset ( V_48 + 2 , 0 , 10 ) ;
if ( ! V_156 ) {
V_48 [ 2 ] = 0x04 ;
F_74 ( 0xffff , & V_48 [ 4 ] ) ;
F_74 ( 0xffff , & V_48 [ 8 ] ) ;
F_74 ( 0xffff , & V_48 [ 10 ] ) ;
}
V_48 += 12 ;
}
V_159 = V_48 - V_153 ;
if ( ! V_158 || V_159 > V_160 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
if ( V_152 == V_162 )
V_153 [ 0 ] = V_159 - 1 ;
else
F_74 ( V_159 - 2 , V_153 ) ;
return V_159 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
int V_163 , V_164 ;
if ( ! V_86 ) {
return - V_97 ;
} else if ( ! V_86 -> V_142 ) {
V_86 -> V_95 = V_165 ;
return - V_97 ;
} else if ( ( V_2 -> V_93 [ 1 ] & ~ 0x01 ) != 0 ||
( V_2 -> V_93 [ 4 ] & ~ 0x03 ) != 0 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
V_163 = V_2 -> V_93 [ 4 ] & 0x02 ;
V_164 = V_2 -> V_93 [ 4 ] & 0x01 ;
if ( V_164 ) {
if ( ! F_76 ( V_86 ) ) {
V_86 -> V_95 = V_166 ;
return - V_97 ;
}
return 0 ;
}
if ( V_86 -> V_167 ) {
F_51 ( V_86 , L_21 ) ;
V_86 -> V_95 = V_168 ;
return - V_97 ;
}
if ( ! V_163 )
return 0 ;
F_77 ( & V_2 -> V_169 ) ;
F_78 ( & V_2 -> V_169 ) ;
F_79 ( V_86 ) ;
F_80 ( & V_2 -> V_169 ) ;
F_81 ( & V_2 -> V_169 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
int V_170 ;
if ( ! V_2 -> V_86 ) {
return - V_97 ;
} else if ( ! V_2 -> V_86 -> V_142 ) {
V_2 -> V_86 -> V_95 = V_165 ;
return - V_97 ;
}
V_170 = V_2 -> V_93 [ 4 ] & 0x01 ;
if ( ( V_2 -> V_93 [ 4 ] & ~ 0x01 ) != 0 ) {
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
if ( V_86 -> V_167 && ! V_170 )
F_57 ( V_86 ) ;
V_86 -> V_167 = V_170 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
V_62 * V_48 = ( V_62 * ) V_12 -> V_48 ;
V_48 [ 0 ] = V_48 [ 1 ] = V_48 [ 2 ] = 0 ;
V_48 [ 3 ] = 8 ;
V_48 += 4 ;
F_66 ( V_86 -> V_98 , & V_48 [ 0 ] ) ;
F_66 ( V_86 -> V_110 , & V_48 [ 4 ] ) ;
V_48 [ 4 ] = 0x02 ;
return 12 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
if ( V_86 )
V_86 -> V_95 = V_165 ;
return - V_97 ;
}
static int F_85 ( struct V_5 * V_4 )
{
int V_33 ;
V_33 = F_7 ( V_4 , V_4 -> V_21 ) ;
if ( V_33 == - V_171 )
F_31 ( V_4 , L_22 ) ;
while ( V_33 != 0 ) {
if ( V_33 != - V_171 ) {
F_19 ( V_4 , L_23 , V_33 ) ;
V_33 = 0 ;
break;
}
if ( F_86 ( 100 ) != 0 )
return - V_83 ;
V_33 = F_9 ( V_4 -> V_21 ) ;
}
return V_33 ;
}
static int F_87 ( struct V_5 * V_4 )
{
int V_33 ;
F_8 ( V_4 , L_24 ) ;
V_33 = F_88 ( V_4 -> V_21 ) ;
if ( V_33 == - V_171 )
F_31 ( V_4 , L_25 ) ;
while ( V_33 != 0 ) {
if ( V_33 != - V_171 ) {
F_19 ( V_4 , L_26 , V_33 ) ;
V_33 = 0 ;
break;
}
if ( F_86 ( 100 ) != 0 )
return - V_83 ;
V_33 = F_88 ( V_4 -> V_21 ) ;
}
return V_33 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
T_2 V_91 ;
int V_33 ;
for ( V_12 = V_2 -> V_128 ;
V_12 -> V_9 != V_47 || V_2 -> V_127 > 0 ;
V_12 = V_2 -> V_128 ) {
if ( V_12 -> V_9 == V_50 ) {
F_44 () ;
V_12 -> V_9 = V_47 ;
V_2 -> V_128 = V_12 -> V_114 ;
if ( V_12 -> V_17 -> V_43 < V_12 -> V_15 ||
V_12 -> V_17 -> V_42 != 0 ) {
F_13 ( V_2 ,
V_172 ) ;
return - V_83 ;
}
continue;
}
V_12 = V_2 -> V_105 ;
if ( V_12 -> V_9 == V_47
&& V_2 -> V_127 > 0 ) {
V_91 = F_32 ( V_2 -> V_127 , V_103 ) ;
F_6 ( V_2 , V_12 , V_91 ) ;
if ( ! F_37 ( V_2 , V_12 ) )
return - V_102 ;
V_2 -> V_105 = V_12 -> V_114 ;
V_2 -> V_127 -= V_91 ;
continue;
}
V_33 = F_38 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_105 ;
int V_33 = 0 ;
switch ( V_2 -> V_173 ) {
case V_174 :
break;
case V_175 :
if ( ! V_2 -> V_176 ) {
} else if ( F_30 ( V_2 ) ) {
F_7 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ) ;
V_33 = F_85 ( V_2 -> V_4 ) ;
} else {
V_33 = - V_102 ;
}
break;
case V_177 :
if ( V_2 -> V_178 == 0 ) {
} else if ( ! F_30 ( V_2 ) ) {
V_33 = - V_102 ;
} else if ( V_2 -> V_111 == 0 ) {
V_12 -> V_79 -> V_113 = 0 ;
if ( ! F_36 ( V_2 , V_12 ) )
return - V_102 ;
V_2 -> V_105 = V_12 -> V_114 ;
} else {
V_12 -> V_79 -> V_113 = 1 ;
if ( ! F_36 ( V_2 , V_12 ) )
V_33 = - V_102 ;
V_2 -> V_105 = V_12 -> V_114 ;
if ( V_2 -> V_176 )
V_33 = F_85 ( V_2 -> V_4 ) ;
}
break;
case V_179 :
if ( V_2 -> V_111 == 0 ) {
} else if ( V_2 -> V_132 ) {
F_13 ( V_2 , V_172 ) ;
V_33 = - V_83 ;
#if 0
} else if (common->can_stall) {
if (fsg_is_set(common))
fsg_set_halt(common->fsg,
common->fsg->bulk_out);
raise_exception(common, FSG_STATE_ABORT_BULK_OUT);
rc = -EINTR;
#endif
} else {
V_33 = F_89 ( V_2 ) ;
}
break;
}
return V_33 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_85 * V_86 = V_2 -> V_86 ;
struct V_11 * V_12 ;
struct V_180 * V_181 ;
int V_33 ;
V_62 V_42 = V_182 ;
T_2 V_144 , V_145 = 0 ;
V_12 = V_2 -> V_105 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_38 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
if ( V_86 ) {
V_144 = V_86 -> V_95 ;
V_145 = V_86 -> V_106 ;
} else if ( V_2 -> V_137 )
V_144 = V_148 ;
else
V_144 = V_147 ;
if ( V_2 -> V_183 ) {
F_8 ( V_2 , L_27 ) ;
V_42 = V_184 ;
V_144 = V_165 ;
} else if ( V_144 != V_148 ) {
F_8 ( V_2 , L_28 ) ;
V_42 = V_185 ;
F_31 ( V_2 , L_29
L_30 ,
F_65 ( V_144 ) , F_67 ( V_144 ) , F_68 ( V_144 ) , V_145 ) ;
}
V_181 = ( void * ) V_12 -> V_48 ;
V_181 -> V_186 = F_92 ( V_187 ) ;
V_181 -> V_188 = V_2 -> V_189 ;
V_181 -> V_190 = F_92 ( V_2 -> V_111 ) ;
V_181 -> V_191 = V_42 ;
V_12 -> V_79 -> V_13 = V_192 ;
V_12 -> V_79 -> V_113 = 0 ;
if ( ! F_36 ( V_2 , V_12 ) )
return - V_102 ;
V_2 -> V_105 = V_12 -> V_114 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , int V_193 ,
enum V_194 V_173 , unsigned int V_195 ,
int V_196 , const char * V_20 )
{
int V_51 ;
unsigned int V_197 = V_2 -> V_93 [ 1 ] >> 5 ;
static const char V_198 [ 4 ] = { 'u' , 'o' , 'i' , 'n' } ;
char V_199 [ 20 ] ;
struct V_85 * V_86 ;
V_199 [ 0 ] = 0 ;
if ( V_2 -> V_173 != V_175 )
sprintf ( V_199 , L_31 , V_198 [ ( int ) V_2 -> V_173 ] ,
V_2 -> V_178 ) ;
F_31 ( V_2 , L_32 ,
V_20 , V_193 , V_198 [ ( int ) V_173 ] ,
V_2 -> V_101 , V_2 -> V_193 , V_199 ) ;
if ( V_2 -> V_101 == 0 )
V_173 = V_174 ;
if ( V_2 -> V_178 < V_2 -> V_101 ) {
V_2 -> V_101 = V_2 -> V_178 ;
V_2 -> V_183 = 1 ;
}
V_2 -> V_111 = V_2 -> V_178 ;
V_2 -> V_127 = V_2 -> V_178 ;
if ( V_2 -> V_173 != V_173 && V_2 -> V_101 > 0 ) {
V_2 -> V_183 = 1 ;
return - V_97 ;
}
if ( V_193 != V_2 -> V_193 ) {
if ( V_193 <= V_2 -> V_193 ) {
F_8 ( V_2 , L_33
L_34 , V_20 ,
V_193 , V_2 -> V_193 ) ;
V_193 = V_2 -> V_193 ;
} else {
V_2 -> V_183 = 1 ;
return - V_97 ;
}
}
if ( V_2 -> V_197 != V_197 )
F_8 ( V_2 , L_35 ,
V_2 -> V_197 , V_197 ) ;
V_86 = V_2 -> V_86 ;
if ( V_86 ) {
if ( V_2 -> V_93 [ 0 ] != V_200 ) {
V_86 -> V_95 = V_148 ;
V_86 -> V_106 = 0 ;
V_86 -> V_107 = 0 ;
}
} else {
V_2 -> V_137 = 0 ;
if ( V_2 -> V_93 [ 0 ] != V_201 &&
V_2 -> V_93 [ 0 ] != V_200 ) {
F_8 ( V_2 , L_36 , V_2 -> V_197 ) ;
return - V_97 ;
}
}
if ( V_86 && V_86 -> V_202 != V_148 &&
V_2 -> V_93 [ 0 ] != V_201 &&
V_2 -> V_93 [ 0 ] != V_200 ) {
V_86 -> V_95 = V_86 -> V_202 ;
V_86 -> V_202 = V_148 ;
return - V_97 ;
}
V_2 -> V_93 [ 1 ] &= 0x1f ;
for ( V_51 = 1 ; V_51 < V_193 ; ++ V_51 ) {
if ( V_2 -> V_93 [ V_51 ] && ! ( V_195 & ( 1 << V_51 ) ) ) {
if ( V_86 )
V_86 -> V_95 = V_96 ;
return - V_97 ;
}
}
if ( V_86 && ! F_76 ( V_86 ) && V_196 ) {
V_86 -> V_95 = V_166 ;
return - V_97 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
int V_193 , enum V_194 V_173 ,
unsigned int V_195 , int V_196 , const char * V_20 )
{
if ( V_2 -> V_86 )
V_2 -> V_101 <<= V_2 -> V_86 -> V_100 ;
return F_93 ( V_2 , V_193 , V_173 ,
V_195 , V_196 , V_20 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_33 ;
int V_203 = - V_97 ;
int V_51 ;
static char V_204 [ 16 ] ;
F_96 ( V_2 ) ;
V_12 = V_2 -> V_105 ;
V_2 -> V_128 = V_12 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_38 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
V_2 -> V_183 = 0 ;
V_2 -> V_132 = 0 ;
F_81 ( & V_2 -> V_169 ) ;
switch ( V_2 -> V_93 [ 0 ] ) {
case V_201 :
V_2 -> V_101 = V_2 -> V_93 [ 4 ] ;
V_203 = F_93 ( V_2 , 6 , V_177 ,
( 1 << 4 ) , 0 ,
L_37 ) ;
if ( V_203 == 0 )
V_203 = F_63 ( V_2 , V_12 ) ;
break;
case V_205 :
V_2 -> V_101 = V_2 -> V_93 [ 4 ] ;
V_203 = F_93 ( V_2 , 6 , V_179 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_38 ) ;
if ( V_203 == 0 )
V_203 = F_84 ( V_2 , V_12 ) ;
break;
case V_206 :
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_93 ( V_2 , 10 , V_179 ,
( 1 << 1 ) | ( 3 << 7 ) , 0 ,
L_39 ) ;
if ( V_203 == 0 )
V_203 = F_84 ( V_2 , V_12 ) ;
break;
case V_162 :
V_2 -> V_101 = V_2 -> V_93 [ 4 ] ;
V_203 = F_93 ( V_2 , 6 , V_177 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) , 0 ,
L_40 ) ;
if ( V_203 == 0 )
V_203 = F_73 ( V_2 , V_12 ) ;
break;
case V_207 :
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_93 ( V_2 , 10 , V_177 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 3 << 7 ) , 0 ,
L_41 ) ;
if ( V_203 == 0 )
V_203 = F_73 ( V_2 , V_12 ) ;
break;
case V_208 :
V_2 -> V_101 = 0 ;
V_203 = F_93 ( V_2 , 6 , V_174 ,
( 1 << 4 ) , 0 ,
L_42 ) ;
if ( V_203 == 0 )
V_203 = F_82 ( V_2 ) ;
break;
case V_94 :
V_51 = V_2 -> V_93 [ 4 ] ;
V_2 -> V_101 = ( V_51 == 0 ) ? 256 : V_51 ;
V_203 = F_94 ( V_2 , 6 ,
V_177 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_43 ) ;
if ( V_203 == 0 )
V_203 = F_45 ( V_2 ) ;
break;
case V_209 :
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_94 ( V_2 , 10 ,
V_177 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_44 ) ;
if ( V_203 == 0 )
V_203 = F_45 ( V_2 ) ;
break;
case V_210 :
V_2 -> V_101 =
F_47 ( & V_2 -> V_93 [ 6 ] ) ;
V_203 = F_94 ( V_2 , 12 ,
V_177 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_45 ) ;
if ( V_203 == 0 )
V_203 = F_45 ( V_2 ) ;
break;
case V_211 :
V_2 -> V_101 = 8 ;
V_203 = F_93 ( V_2 , 10 , V_177 ,
( 0xf << 2 ) | ( 1 << 8 ) , 1 ,
L_46 ) ;
if ( V_203 == 0 )
V_203 = F_69 ( V_2 , V_12 ) ;
break;
case V_212 :
if ( ! V_2 -> V_86 || ! V_2 -> V_86 -> V_139 )
goto V_213;
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_93 ( V_2 , 10 , V_177 ,
( 3 << 7 ) | ( 0x1f << 1 ) , 1 ,
L_47 ) ;
if ( V_203 == 0 )
V_203 = F_70 ( V_2 , V_12 ) ;
break;
case V_214 :
if ( ! V_2 -> V_86 || ! V_2 -> V_86 -> V_139 )
goto V_213;
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_93 ( V_2 , 10 , V_177 ,
( 7 << 6 ) | ( 1 << 1 ) , 1 ,
L_48 ) ;
if ( V_203 == 0 )
V_203 = F_72 ( V_2 , V_12 ) ;
break;
case V_215 :
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_93 ( V_2 , 10 , V_177 ,
( 3 << 7 ) , 1 ,
L_49 ) ;
if ( V_203 == 0 )
V_203 = F_83 ( V_2 , V_12 ) ;
break;
case V_200 :
V_2 -> V_101 = V_2 -> V_93 [ 4 ] ;
V_203 = F_93 ( V_2 , 6 , V_177 ,
( 1 << 4 ) , 0 ,
L_50 ) ;
if ( V_203 == 0 )
V_203 = F_64 ( V_2 , V_12 ) ;
break;
case V_216 :
V_2 -> V_101 = 0 ;
V_203 = F_93 ( V_2 , 6 , V_174 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_51 ) ;
if ( V_203 == 0 )
V_203 = F_75 ( V_2 ) ;
break;
case V_217 :
V_2 -> V_101 = 0 ;
V_203 = F_93 ( V_2 , 10 , V_174 ,
( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_52 ) ;
if ( V_203 == 0 )
V_203 = F_56 ( V_2 ) ;
break;
case V_218 :
V_2 -> V_101 = 0 ;
V_203 = F_93 ( V_2 , 6 , V_174 ,
0 , 1 ,
L_53 ) ;
break;
case V_219 :
V_2 -> V_101 = 0 ;
V_203 = F_93 ( V_2 , 10 , V_174 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_54 ) ;
if ( V_203 == 0 )
V_203 = F_61 ( V_2 ) ;
break;
case V_125 :
V_51 = V_2 -> V_93 [ 4 ] ;
V_2 -> V_101 = ( V_51 == 0 ) ? 256 : V_51 ;
V_203 = F_94 ( V_2 , 6 ,
V_179 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_55 ) ;
if ( V_203 == 0 )
V_203 = F_53 ( V_2 ) ;
break;
case V_220 :
V_2 -> V_101 =
F_62 ( & V_2 -> V_93 [ 7 ] ) ;
V_203 = F_94 ( V_2 , 10 ,
V_179 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_56 ) ;
if ( V_203 == 0 )
V_203 = F_53 ( V_2 ) ;
break;
case V_221 :
V_2 -> V_101 =
F_47 ( & V_2 -> V_93 [ 6 ] ) ;
V_203 = F_94 ( V_2 , 12 ,
V_179 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_57 ) ;
if ( V_203 == 0 )
V_203 = F_53 ( V_2 ) ;
break;
case V_222 :
case V_223 :
case V_224 :
case V_225 :
default:
V_213:
V_2 -> V_101 = 0 ;
sprintf ( V_204 , L_58 , V_2 -> V_93 [ 0 ] ) ;
V_203 = F_93 ( V_2 , V_2 -> V_193 ,
V_175 , ~ 0 , 0 , V_204 ) ;
if ( V_203 == 0 ) {
V_2 -> V_86 -> V_95 = V_165 ;
V_203 = - V_97 ;
}
break;
}
F_77 ( & V_2 -> V_169 ) ;
if ( V_203 == - V_83 || F_41 ( V_82 ) )
return - V_83 ;
if ( V_203 == - V_97 )
V_203 = 0 ;
if ( V_203 >= 0 && V_2 -> V_173 == V_177 ) {
V_203 = F_32 ( ( T_2 ) V_203 , V_2 -> V_101 ) ;
V_12 -> V_79 -> V_13 = V_203 ;
V_12 -> V_9 = V_50 ;
V_2 -> V_111 -= V_203 ;
}
return 0 ;
}
static int F_97 ( struct V_5 * V_4 , struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_17 ;
struct V_226 * V_227 = V_40 -> V_48 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_40 -> V_42 || F_98 ( V_228 , & V_4 -> V_229 ) )
return - V_97 ;
if ( V_40 -> V_43 != V_230 ||
V_227 -> V_186 != F_92 (
V_231 ) ) {
F_8 ( V_4 , L_59 ,
V_40 -> V_43 ,
F_99 ( V_227 -> V_186 ) ) ;
F_87 ( V_4 ) ;
F_100 ( V_228 , & V_4 -> V_229 ) ;
return - V_97 ;
}
if ( V_227 -> V_232 >= F_27 ( V_2 -> V_52 ) ||
V_227 -> V_233 & ~ V_234 || V_227 -> V_235 <= 0 ||
V_227 -> V_235 > V_236 ) {
F_8 ( V_4 , L_60
L_61 ,
V_227 -> V_232 , V_227 -> V_233 , V_227 -> V_235 ) ;
if ( V_2 -> V_176 ) {
F_7 ( V_4 , V_4 -> V_22 ) ;
F_85 ( V_4 ) ;
}
return - V_97 ;
}
V_2 -> V_193 = V_227 -> V_235 ;
memcpy ( V_2 -> V_93 , V_227 -> V_237 , V_2 -> V_193 ) ;
if ( V_227 -> V_233 & V_234 )
V_2 -> V_173 = V_177 ;
else
V_2 -> V_173 = V_179 ;
V_2 -> V_178 = F_99 ( V_227 -> V_238 ) ;
if ( V_2 -> V_178 == 0 )
V_2 -> V_173 = V_174 ;
V_2 -> V_197 = V_227 -> V_232 ;
if ( V_2 -> V_197 < F_27 ( V_2 -> V_52 ) )
V_2 -> V_86 = V_2 -> V_52 [ V_2 -> V_197 ] ;
else
V_2 -> V_86 = NULL ;
V_2 -> V_189 = V_227 -> V_188 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_33 = 0 ;
V_12 = V_2 -> V_105 ;
while ( V_12 -> V_9 != V_47 ) {
V_33 = F_38 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
F_6 ( V_2 , V_12 , V_230 ) ;
if ( ! F_37 ( V_2 , V_12 ) )
return - V_102 ;
while ( V_12 -> V_9 != V_50 ) {
V_33 = F_38 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
}
F_44 () ;
V_33 = F_30 ( V_2 ) ? F_97 ( V_2 -> V_4 , V_12 ) : - V_102 ;
V_12 -> V_9 = V_47 ;
return V_33 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_39 * * V_239 )
{
* V_239 = F_103 ( V_19 , V_36 ) ;
if ( * V_239 )
return 0 ;
ERROR ( V_2 , L_62 , V_19 -> V_20 ) ;
return - V_240 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_5 * V_241 )
{
struct V_5 * V_4 ;
int V_51 , V_33 = 0 ;
if ( V_2 -> V_242 )
F_8 ( V_2 , L_63 ) ;
V_243:
if ( V_2 -> V_4 ) {
V_4 = V_2 -> V_4 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_244 ; ++ V_51 ) {
struct V_11 * V_12 = & V_2 -> V_245 [ V_51 ] ;
if ( V_12 -> V_79 ) {
F_105 ( V_4 -> V_21 , V_12 -> V_79 ) ;
V_12 -> V_79 = NULL ;
}
if ( V_12 -> V_17 ) {
F_105 ( V_4 -> V_22 , V_12 -> V_17 ) ;
V_12 -> V_17 = NULL ;
}
}
if ( V_4 -> V_246 ) {
F_106 ( V_4 -> V_21 ) ;
V_4 -> V_21 -> V_37 = NULL ;
V_4 -> V_246 = 0 ;
}
if ( V_4 -> V_247 ) {
F_106 ( V_4 -> V_22 ) ;
V_4 -> V_22 -> V_37 = NULL ;
V_4 -> V_247 = 0 ;
}
V_2 -> V_4 = NULL ;
F_107 ( & V_2 -> V_248 ) ;
}
V_2 -> V_242 = 0 ;
if ( ! V_241 || V_33 )
return V_33 ;
V_2 -> V_4 = V_241 ;
V_4 = V_2 -> V_4 ;
V_33 = F_108 ( V_2 -> V_249 , & ( V_4 -> V_8 ) , V_4 -> V_21 ) ;
if ( V_33 )
goto V_243;
V_33 = F_109 ( V_4 -> V_21 ) ;
if ( V_33 )
goto V_243;
V_4 -> V_21 -> V_37 = V_2 ;
V_4 -> V_246 = 1 ;
V_33 = F_108 ( V_2 -> V_249 , & ( V_4 -> V_8 ) ,
V_4 -> V_22 ) ;
if ( V_33 )
goto V_243;
V_33 = F_109 ( V_4 -> V_22 ) ;
if ( V_33 )
goto V_243;
V_4 -> V_22 -> V_37 = V_2 ;
V_4 -> V_247 = 1 ;
V_2 -> V_16 = F_110 ( V_4 -> V_22 -> V_250 ) ;
F_111 ( V_228 , & V_4 -> V_229 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_244 ; ++ V_51 ) {
struct V_11 * V_12 = & V_2 -> V_245 [ V_51 ] ;
V_33 = F_102 ( V_2 , V_4 -> V_21 , & V_12 -> V_79 ) ;
if ( V_33 )
goto V_243;
V_33 = F_102 ( V_2 , V_4 -> V_22 , & V_12 -> V_17 ) ;
if ( V_33 )
goto V_243;
V_12 -> V_79 -> V_48 = V_12 -> V_17 -> V_48 = V_12 -> V_48 ;
V_12 -> V_79 -> V_41 = V_12 -> V_17 -> V_41 = V_12 ;
V_12 -> V_79 -> V_251 = F_20 ;
V_12 -> V_17 -> V_251 = F_24 ;
}
V_2 -> V_242 = 1 ;
for ( V_51 = 0 ; V_51 < F_27 ( V_2 -> V_52 ) ; ++ V_51 )
if ( V_2 -> V_52 [ V_51 ] )
V_2 -> V_52 [ V_51 ] -> V_202 =
V_252 ;
return V_33 ;
}
static int F_112 ( struct V_6 * V_7 , unsigned V_253 , unsigned V_254 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_241 = V_4 ;
F_13 ( V_4 -> V_2 , V_255 ) ;
return V_72 ;
}
static void F_113 ( struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_241 = NULL ;
F_13 ( V_4 -> V_2 , V_255 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
T_5 V_256 ;
int V_51 ;
struct V_11 * V_12 ;
enum V_25 V_257 ;
struct V_85 * V_86 ;
unsigned int V_29 ;
for (; ; ) {
int V_258 =
F_115 ( V_82 , & V_82 -> V_259 , & V_256 ) ;
if ( ! V_258 )
break;
if ( V_258 != V_31 ) {
if ( V_2 -> V_9 < V_260 )
F_8 ( V_2 , L_64 ) ;
F_13 ( V_2 , V_260 ) ;
}
}
if ( F_116 ( V_2 -> V_4 ) ) {
for ( V_51 = 0 ; V_51 < V_2 -> V_244 ; ++ V_51 ) {
V_12 = & V_2 -> V_245 [ V_51 ] ;
if ( V_12 -> V_46 )
F_117 ( V_2 -> V_4 -> V_21 , V_12 -> V_79 ) ;
if ( V_12 -> V_49 )
F_117 ( V_2 -> V_4 -> V_22 ,
V_12 -> V_17 ) ;
}
for (; ; ) {
int V_261 = 0 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_244 ; ++ V_51 ) {
V_12 = & V_2 -> V_245 [ V_51 ] ;
V_261 += V_12 -> V_46 + V_12 -> V_49 ;
}
if ( V_261 == 0 )
break;
if ( F_38 ( V_2 , true ) )
return;
}
if ( V_2 -> V_4 -> V_246 )
F_21 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_4 -> V_247 )
F_21 ( V_2 -> V_4 -> V_22 ) ;
}
F_34 ( & V_2 -> V_28 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_244 ; ++ V_51 ) {
V_12 = & V_2 -> V_245 [ V_51 ] ;
V_12 -> V_9 = V_47 ;
}
V_2 -> V_105 = & V_2 -> V_245 [ 0 ] ;
V_2 -> V_128 = & V_2 -> V_245 [ 0 ] ;
V_29 = V_2 -> V_29 ;
V_257 = V_2 -> V_9 ;
if ( V_257 == V_172 )
V_2 -> V_9 = V_262 ;
else {
for ( V_51 = 0 ; V_51 < F_27 ( V_2 -> V_52 ) ; ++ V_51 ) {
V_86 = V_2 -> V_52 [ V_51 ] ;
if ( ! V_86 )
continue;
V_86 -> V_167 = 0 ;
V_86 -> V_95 = V_148 ;
V_86 -> V_202 = V_148 ;
V_86 -> V_106 = 0 ;
V_86 -> V_107 = 0 ;
}
V_2 -> V_9 = V_10 ;
}
F_35 ( & V_2 -> V_28 ) ;
switch ( V_257 ) {
case V_172 :
F_91 ( V_2 ) ;
F_34 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_9 == V_262 )
V_2 -> V_9 = V_10 ;
F_35 ( & V_2 -> V_28 ) ;
break;
case V_71 :
if ( ! F_30 ( V_2 ) )
break;
if ( F_118 ( V_228 ,
& V_2 -> V_4 -> V_229 ) )
F_119 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_30 == V_29 )
F_17 ( V_2 ) ;
break;
case V_255 :
F_104 ( V_2 , V_2 -> V_241 ) ;
if ( V_2 -> V_241 )
F_120 ( V_2 -> V_263 ) ;
break;
case V_260 :
case V_264 :
F_104 ( V_2 , NULL ) ;
F_34 ( & V_2 -> V_28 ) ;
V_2 -> V_9 = V_264 ;
F_35 ( & V_2 -> V_28 ) ;
break;
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_262 :
case V_10 :
break;
}
}
static int F_121 ( void * V_269 )
{
struct V_1 * V_2 = V_269 ;
F_122 ( V_270 ) ;
F_122 ( V_271 ) ;
F_122 ( V_272 ) ;
F_122 ( V_31 ) ;
F_123 () ;
F_124 ( F_125 () ) ;
while ( V_2 -> V_9 != V_264 ) {
if ( F_5 ( V_2 ) || F_41 ( V_82 ) ) {
F_114 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_242 ) {
F_38 ( V_2 , true ) ;
continue;
}
if ( F_101 ( V_2 ) )
continue;
F_34 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_268 ;
F_35 ( & V_2 -> V_28 ) ;
if ( F_95 ( V_2 ) || F_90 ( V_2 ) )
continue;
F_34 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_262 ;
F_35 ( & V_2 -> V_28 ) ;
if ( F_91 ( V_2 ) )
continue;
F_34 ( & V_2 -> V_28 ) ;
if ( ! F_5 ( V_2 ) )
V_2 -> V_9 = V_10 ;
F_35 ( & V_2 -> V_28 ) ;
}
F_34 ( & V_2 -> V_28 ) ;
V_2 -> V_24 = NULL ;
F_35 ( & V_2 -> V_28 ) ;
if ( ! V_2 -> V_273 || ! V_2 -> V_273 -> V_274
|| V_2 -> V_273 -> V_274 ( V_2 ) < 0 ) {
int V_51 ;
F_78 ( & V_2 -> V_169 ) ;
for ( V_51 = 0 ; V_51 < F_27 ( V_2 -> V_52 ) ; -- V_51 ) {
struct V_85 * V_86 = V_2 -> V_52 [ V_51 ] ;
if ( ! V_86 || ! F_76 ( V_86 ) )
continue;
F_79 ( V_86 ) ;
V_86 -> V_202 = V_166 ;
}
F_80 ( & V_2 -> V_169 ) ;
}
F_126 ( & V_2 -> V_275 , 0 ) ;
}
static T_4 F_127 ( struct V_276 * V_277 , struct V_278 * V_279 , char * V_48 )
{
struct V_85 * V_86 = F_128 ( V_277 ) ;
return F_129 ( V_86 , V_48 ) ;
}
static T_4 F_130 ( struct V_276 * V_277 , struct V_278 * V_279 ,
char * V_48 )
{
struct V_85 * V_86 = F_128 ( V_277 ) ;
return F_131 ( V_86 , V_48 ) ;
}
static T_4 F_132 ( struct V_276 * V_277 , struct V_278 * V_279 ,
char * V_48 )
{
struct V_85 * V_86 = F_128 ( V_277 ) ;
struct V_280 * V_169 = F_133 ( V_277 ) ;
return F_134 ( V_86 , V_169 , V_48 ) ;
}
static T_4 F_135 ( struct V_276 * V_277 , struct V_278 * V_279 ,
const char * V_48 , T_6 V_281 )
{
struct V_85 * V_86 = F_128 ( V_277 ) ;
struct V_280 * V_169 = F_133 ( V_277 ) ;
return F_136 ( V_86 , V_169 , V_48 , V_281 ) ;
}
static T_4 F_137 ( struct V_276 * V_277 , struct V_278 * V_279 ,
const char * V_48 , T_6 V_281 )
{
struct V_85 * V_86 = F_128 ( V_277 ) ;
return F_138 ( V_86 , V_48 , V_281 ) ;
}
static T_4 F_139 ( struct V_276 * V_277 , struct V_278 * V_279 ,
const char * V_48 , T_6 V_281 )
{
struct V_85 * V_86 = F_128 ( V_277 ) ;
struct V_280 * V_169 = F_133 ( V_277 ) ;
return F_140 ( V_86 , V_169 , V_48 , V_281 ) ;
}
static void F_141 ( struct V_276 * V_277 )
{
}
void F_142 ( struct V_1 * V_2 )
{
F_143 ( & V_2 -> V_282 ) ;
}
void F_144 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_282 , V_283 ) ;
}
static inline int F_146 ( unsigned int V_244 )
{
if ( V_244 >= 2 && V_244 <= 4 )
return 0 ;
F_147 ( L_65 ,
V_244 , 2 , 4 ) ;
return - V_97 ;
}
static struct V_1 * F_148 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
V_2 = F_149 ( sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return F_150 ( - V_240 ) ;
V_2 -> V_284 = 1 ;
} else {
V_2 -> V_284 = 0 ;
}
F_151 ( & V_2 -> V_169 ) ;
F_152 ( & V_2 -> V_28 ) ;
F_153 ( & V_2 -> V_282 ) ;
F_154 ( & V_2 -> V_275 ) ;
F_155 ( & V_2 -> V_248 ) ;
V_2 -> V_9 = V_264 ;
memset ( V_2 -> V_52 , 0 , sizeof( V_2 -> V_52 ) ) ;
return V_2 ;
}
void F_156 ( struct V_1 * V_2 , bool V_285 )
{
V_2 -> V_285 = V_285 ;
}
static void F_157 ( struct V_11 * V_245 , unsigned V_286 )
{
if ( V_245 ) {
struct V_11 * V_12 = V_245 ;
while ( V_286 -- ) {
F_158 ( V_12 -> V_48 ) ;
++ V_12 ;
}
F_158 ( V_245 ) ;
}
}
int F_159 ( struct V_1 * V_2 , unsigned int V_286 )
{
struct V_11 * V_12 , * V_245 ;
int V_51 , V_33 ;
V_33 = F_146 ( V_286 ) ;
if ( V_33 != 0 )
return V_33 ;
V_245 = F_160 ( V_286 , sizeof( * V_245 ) , V_78 ) ;
if ( ! V_245 )
return - V_240 ;
V_12 = V_245 ;
V_51 = V_286 ;
goto V_287;
do {
V_12 -> V_114 = V_12 + 1 ;
++ V_12 ;
V_287:
V_12 -> V_48 = F_161 ( V_103 , V_78 ) ;
if ( F_48 ( ! V_12 -> V_48 ) )
goto V_288;
} while ( -- V_51 );
V_12 -> V_114 = V_245 ;
F_157 ( V_2 -> V_245 , V_2 -> V_244 ) ;
V_2 -> V_244 = V_286 ;
V_2 -> V_245 = V_245 ;
return 0 ;
V_288:
F_157 ( V_245 , V_286 ) ;
return - V_240 ;
}
void F_162 ( struct V_85 * V_197 )
{
if ( F_163 ( & V_197 -> V_277 ) )
F_164 ( & V_197 -> V_277 ) ;
F_79 ( V_197 ) ;
F_158 ( V_197 ) ;
}
static void F_165 ( struct V_1 * V_2 , int V_286 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_286 ; ++ V_51 )
if ( V_2 -> V_52 [ V_51 ] ) {
F_162 ( V_2 -> V_52 [ V_51 ] ) ;
V_2 -> V_52 [ V_51 ] = NULL ;
}
}
void F_166 ( struct V_1 * V_2 )
{
F_165 ( V_2 , F_27 ( V_2 -> V_52 ) ) ;
}
void F_167 ( struct V_1 * V_2 ,
const struct V_289 * V_273 )
{
V_2 -> V_273 = V_273 ;
}
void F_168 ( struct V_1 * V_2 )
{
F_157 ( V_2 -> V_245 , V_2 -> V_244 ) ;
V_2 -> V_245 = NULL ;
}
int F_169 ( struct V_1 * V_2 ,
struct V_290 * V_263 , bool V_176 )
{
struct V_291 * V_292 ;
V_2 -> V_249 = V_263 -> V_249 ;
V_2 -> V_34 = V_263 -> V_249 -> V_34 ;
V_2 -> V_35 = V_263 -> V_40 ;
V_2 -> V_263 = V_263 ;
V_292 = F_170 ( V_263 , V_293 ,
F_27 ( V_294 ) ) ;
if ( F_171 ( V_292 ) )
return F_172 ( V_292 ) ;
V_295 . V_296 = V_292 [ V_297 ] . V_298 ;
V_2 -> V_176 = V_176 &&
F_173 ( V_2 -> V_249 ) ;
return 0 ;
}
static T_7 F_174 ( struct V_299 * V_300 ,
struct V_301 * V_279 , int V_302 )
{
struct V_276 * V_277 = F_175 ( V_300 ) ;
struct V_85 * V_197 = F_128 ( V_277 ) ;
if ( V_279 == & V_303 . V_279 )
return V_197 -> V_139 ? V_304 : ( V_305 | V_304 ) ;
if ( V_279 == & V_306 . V_279 )
return V_197 -> V_142 ? ( V_305 | V_304 ) : V_304 ;
return V_279 -> V_307 ;
}
int F_176 ( struct V_1 * V_2 , struct V_308 * V_309 ,
unsigned int V_298 , const char * V_20 ,
const char * * V_310 )
{
struct V_85 * V_197 ;
char * V_311 , * V_312 ;
int V_33 = - V_240 ;
if ( V_298 >= F_27 ( V_2 -> V_52 ) )
return - V_313 ;
if ( V_2 -> V_52 [ V_298 ] )
return - V_314 ;
if ( ! V_309 -> V_315 && ! V_309 -> V_142 ) {
F_147 ( L_66 , V_298 ) ;
return - V_97 ;
}
V_197 = F_149 ( sizeof( * V_197 ) , V_78 ) ;
if ( ! V_197 )
return - V_240 ;
V_197 -> V_310 = V_310 ;
V_197 -> V_139 = ! ! V_309 -> V_139 ;
V_197 -> V_120 = V_309 -> V_139 || V_309 -> V_120 ;
V_197 -> V_316 = V_197 -> V_120 ;
V_197 -> V_142 = ! ! V_309 -> V_142 ;
if ( ! V_2 -> V_285 ) {
V_197 -> V_20 = V_20 ;
} else {
V_197 -> V_277 . V_317 = F_141 ;
V_197 -> V_277 . V_318 = & V_2 -> V_249 -> V_277 ;
V_197 -> V_277 . V_319 = V_320 ;
F_177 ( & V_197 -> V_277 , & V_2 -> V_169 ) ;
F_178 ( & V_197 -> V_277 , L_67 , V_20 ) ;
V_197 -> V_20 = F_179 ( & V_197 -> V_277 ) ;
V_33 = F_180 ( & V_197 -> V_277 ) ;
if ( V_33 ) {
F_181 ( L_68 , V_298 , V_33 ) ;
F_182 ( & V_197 -> V_277 ) ;
goto V_321;
}
}
V_2 -> V_52 [ V_298 ] = V_197 ;
if ( V_309 -> V_315 ) {
V_33 = F_183 ( V_197 , V_309 -> V_315 ) ;
if ( V_33 )
goto V_322;
}
V_311 = F_161 ( V_323 , V_78 ) ;
V_312 = L_69 ;
if ( F_76 ( V_197 ) ) {
V_312 = L_70 ;
if ( V_311 ) {
V_312 = F_184 ( V_197 -> V_108 , V_311 , V_323 ) ;
if ( F_171 ( V_312 ) )
V_312 = L_70 ;
}
}
F_181 ( L_71 ,
V_197 -> V_142 ? L_72 : L_73 ,
V_197 -> V_120 ? L_74 : L_73 ,
V_197 -> V_139 ? L_75 : L_73 ,
V_312 ) ;
F_158 ( V_311 ) ;
return 0 ;
V_322:
if ( F_163 ( & V_197 -> V_277 ) )
F_164 ( & V_197 -> V_277 ) ;
F_79 ( V_197 ) ;
V_2 -> V_52 [ V_298 ] = NULL ;
V_321:
F_158 ( V_197 ) ;
return V_33 ;
}
int F_185 ( struct V_1 * V_2 , struct V_324 * V_309 )
{
char V_48 [ 8 ] ;
int V_51 , V_33 ;
F_166 ( V_2 ) ;
for ( V_51 = 0 ; V_51 < V_309 -> V_325 ; ++ V_51 ) {
snprintf ( V_48 , sizeof( V_48 ) , L_76 , V_51 ) ;
V_33 = F_176 ( V_2 , & V_309 -> V_52 [ V_51 ] , V_51 , V_48 , NULL ) ;
if ( V_33 )
goto V_326;
}
F_181 ( L_77 , V_309 -> V_325 ) ;
return 0 ;
V_326:
F_165 ( V_2 , V_51 ) ;
return V_33 ;
}
void F_186 ( struct V_1 * V_2 , const char * V_327 ,
const char * V_328 )
{
int V_51 ;
V_51 = F_187 () ;
snprintf ( V_2 -> V_143 , sizeof( V_2 -> V_143 ) ,
L_78 , V_327 ? : L_79 ,
V_328 ? : ( ( * V_2 -> V_52 ) -> V_139
? L_80
: L_81 ) ,
V_51 ) ;
}
int F_188 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_10 ;
V_2 -> V_24 =
F_189 ( F_121 , V_2 , L_82 ) ;
if ( F_171 ( V_2 -> V_24 ) ) {
V_2 -> V_9 = V_264 ;
return F_172 ( V_2 -> V_24 ) ;
}
F_8 ( V_2 , L_83 , F_190 ( V_2 -> V_24 ) ) ;
F_12 ( V_2 -> V_24 ) ;
return 0 ;
}
static void V_283 ( struct V_329 * V_282 )
{
struct V_1 * V_2 = F_4 ( V_282 , struct V_1 , V_282 ) ;
int V_51 ;
if ( V_2 -> V_9 != V_264 ) {
F_13 ( V_2 , V_260 ) ;
F_191 ( & V_2 -> V_275 ) ;
}
for ( V_51 = 0 ; V_51 < F_27 ( V_2 -> V_52 ) ; ++ V_51 ) {
struct V_85 * V_197 = V_2 -> V_52 [ V_51 ] ;
if ( ! V_197 )
continue;
F_79 ( V_197 ) ;
if ( F_163 ( & V_197 -> V_277 ) )
F_164 ( & V_197 -> V_277 ) ;
F_158 ( V_197 ) ;
}
F_157 ( V_2 -> V_245 , V_2 -> V_244 ) ;
if ( V_2 -> V_284 )
F_158 ( V_2 ) ;
}
static int F_192 ( struct V_330 * V_331 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_332 * V_249 = V_331 -> V_263 -> V_249 ;
int V_51 ;
struct V_18 * V_19 ;
unsigned V_333 ;
int V_334 ;
struct V_335 * V_336 ;
V_334 = F_26 ( V_2 ) ;
if ( V_334 < 0 ) {
F_147 ( L_84 ) ;
return - V_97 ;
}
V_336 = F_193 ( V_7 -> V_337 ) ;
if ( ! V_336 -> V_338 ) {
V_334 = F_169 ( V_4 -> V_2 , V_331 -> V_263 ,
V_4 -> V_2 -> V_176 ) ;
if ( V_334 )
return V_334 ;
F_186 ( V_4 -> V_2 , NULL , NULL ) ;
V_334 = F_188 ( V_4 -> V_2 ) ;
if ( V_334 )
return V_334 ;
}
V_4 -> V_249 = V_249 ;
V_51 = F_194 ( V_331 , V_7 ) ;
if ( V_51 < 0 )
goto V_326;
V_295 . V_339 = V_51 ;
V_4 -> V_69 = V_51 ;
V_19 = F_195 ( V_249 , & V_340 ) ;
if ( ! V_19 )
goto V_341;
V_19 -> V_37 = V_4 -> V_2 ;
V_4 -> V_21 = V_19 ;
V_19 = F_195 ( V_249 , & V_342 ) ;
if ( ! V_19 )
goto V_341;
V_19 -> V_37 = V_4 -> V_2 ;
V_4 -> V_22 = V_19 ;
V_343 . V_344 =
V_340 . V_344 ;
V_345 . V_344 =
V_342 . V_344 ;
V_333 = F_196 ( unsigned , V_103 / 1024 , 15 ) ;
V_346 . V_344 =
V_340 . V_344 ;
V_347 . V_348 = V_333 ;
V_349 . V_344 =
V_342 . V_344 ;
V_350 . V_348 = V_333 ;
V_334 = F_197 ( V_7 , V_351 , V_352 ,
V_353 ) ;
if ( V_334 )
goto V_341;
return 0 ;
V_341:
ERROR ( V_4 , L_85 ) ;
V_51 = - V_354 ;
V_326:
if ( V_4 -> V_2 -> V_9 != V_264 ) {
F_13 ( V_4 -> V_2 , V_260 ) ;
F_191 ( & V_4 -> V_2 -> V_275 ) ;
}
return V_51 ;
}
static void F_198 ( struct V_330 * V_331 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_8 ( V_4 , L_86 ) ;
if ( V_4 -> V_2 -> V_4 == V_4 ) {
V_4 -> V_2 -> V_241 = NULL ;
F_13 ( V_4 -> V_2 , V_255 ) ;
F_199 ( V_2 -> V_248 , V_2 -> V_4 != V_4 ) ;
}
F_200 ( & V_4 -> V_8 ) ;
}
static inline struct V_355 * F_201 ( struct V_356 * V_357 )
{
return F_4 ( F_202 ( V_357 ) , struct V_355 , V_358 ) ;
}
static inline struct V_335 * F_203 ( struct V_356 * V_357 )
{
return F_4 ( F_202 ( V_357 ) , struct V_335 ,
V_359 . V_358 ) ;
}
static void F_204 ( struct V_356 * V_357 )
{
struct V_355 * V_360 ;
V_360 = F_201 ( V_357 ) ;
F_158 ( V_360 ) ;
}
static T_4 F_205 ( struct V_355 * V_336 , char * V_361 )
{
struct V_335 * V_335 ;
V_335 = F_203 ( V_336 -> V_358 . V_362 . V_363 ) ;
return F_134 ( V_336 -> V_197 , & V_335 -> V_2 -> V_169 , V_361 ) ;
}
static T_4 F_206 ( struct V_355 * V_336 ,
const char * V_361 , T_6 V_159 )
{
struct V_335 * V_335 ;
V_335 = F_203 ( V_336 -> V_358 . V_362 . V_363 ) ;
return F_140 ( V_336 -> V_197 , & V_335 -> V_2 -> V_169 , V_361 , V_159 ) ;
}
static T_4 F_207 ( struct V_355 * V_336 , char * V_361 )
{
return F_129 ( V_336 -> V_197 , V_361 ) ;
}
static T_4 F_208 ( struct V_355 * V_336 ,
const char * V_361 , T_6 V_159 )
{
struct V_335 * V_335 ;
V_335 = F_203 ( V_336 -> V_358 . V_362 . V_363 ) ;
return F_136 ( V_336 -> V_197 , & V_335 -> V_2 -> V_169 , V_361 , V_159 ) ;
}
static T_4 F_209 ( struct V_355 * V_336 ,
char * V_361 )
{
return F_210 ( V_336 -> V_197 , V_361 ) ;
}
static T_4 F_211 ( struct V_355 * V_336 ,
const char * V_361 , T_6 V_159 )
{
return F_212 ( V_336 -> V_197 , V_361 , V_159 ) ;
}
static T_4 F_213 ( struct V_355 * V_336 , char * V_361 )
{
return F_214 ( V_336 -> V_197 , V_361 ) ;
}
static T_4 F_215 ( struct V_355 * V_336 ,
const char * V_361 , T_6 V_159 )
{
struct V_335 * V_335 ;
V_335 = F_203 ( V_336 -> V_358 . V_362 . V_363 ) ;
return F_216 ( V_336 -> V_197 , & V_335 -> V_2 -> V_169 , V_361 ,
V_159 ) ;
}
static T_4 F_217 ( struct V_355 * V_336 , char * V_361 )
{
return F_131 ( V_336 -> V_197 , V_361 ) ;
}
static T_4 F_218 ( struct V_355 * V_336 ,
const char * V_361 , T_6 V_159 )
{
return F_138 ( V_336 -> V_197 , V_361 , V_159 ) ;
}
static struct V_364 * F_219 ( struct V_364 * V_358 ,
const char * V_20 )
{
struct V_355 * V_336 ;
struct V_335 * V_335 ;
struct V_308 V_365 ;
char * V_366 ;
V_62 V_367 ;
int V_334 ;
V_366 = strchr ( V_20 , '.' ) ;
if ( ! V_366 ) {
F_147 ( L_87 ) ;
return F_150 ( - V_97 ) ;
}
V_366 ++ ;
V_334 = F_220 ( V_366 , 0 , & V_367 ) ;
if ( V_334 )
return F_150 ( V_334 ) ;
V_335 = F_203 ( & V_358 -> V_362 ) ;
if ( V_367 >= V_368 )
return F_150 ( - V_369 ) ;
F_221 ( & V_335 -> V_28 ) ;
if ( V_335 -> V_370 || V_335 -> V_2 -> V_52 [ V_367 ] ) {
V_334 = - V_314 ;
goto V_371;
}
V_336 = F_149 ( sizeof( * V_336 ) , V_78 ) ;
if ( ! V_336 ) {
V_334 = - V_240 ;
goto V_371;
}
memset ( & V_365 , 0 , sizeof( V_365 ) ) ;
V_365 . V_142 = true ;
V_334 = F_176 ( V_335 -> V_2 , & V_365 , V_367 , V_20 ,
( const char * * ) & V_358 -> V_362 . V_372 ) ;
if ( V_334 ) {
F_158 ( V_336 ) ;
goto V_371;
}
V_336 -> V_197 = V_335 -> V_2 -> V_52 [ V_367 ] ;
V_336 -> V_373 = V_367 ;
F_222 ( & V_335 -> V_28 ) ;
F_223 ( & V_336 -> V_358 , V_20 , & V_374 ) ;
return & V_336 -> V_358 ;
V_371:
F_222 ( & V_335 -> V_28 ) ;
return F_150 ( V_334 ) ;
}
static void F_224 ( struct V_364 * V_358 , struct V_356 * V_357 )
{
struct V_355 * V_360 ;
struct V_335 * V_335 ;
V_360 = F_201 ( V_357 ) ;
V_335 = F_203 ( & V_358 -> V_362 ) ;
F_221 ( & V_335 -> V_28 ) ;
if ( V_335 -> V_370 ) {
struct V_356 * V_249 ;
V_249 = V_358 -> V_362 . V_363 -> V_363 ;
F_225 ( V_249 ) ;
}
F_162 ( V_360 -> V_197 ) ;
V_335 -> V_2 -> V_52 [ V_360 -> V_373 ] = NULL ;
V_360 -> V_373 = 0 ;
F_222 ( & V_335 -> V_28 ) ;
F_226 ( V_357 ) ;
}
static void F_227 ( struct V_356 * V_357 )
{
struct V_335 * V_336 = F_203 ( V_357 ) ;
F_228 ( & V_336 -> V_359 ) ;
}
static T_4 F_229 ( struct V_335 * V_336 , char * V_361 )
{
int V_375 ;
F_221 ( & V_336 -> V_28 ) ;
V_375 = sprintf ( V_361 , L_88 , V_336 -> V_2 -> V_176 ) ;
F_222 ( & V_336 -> V_28 ) ;
return V_375 ;
}
static T_4 F_230 ( struct V_335 * V_336 , const char * V_361 ,
T_6 V_159 )
{
int V_334 ;
bool V_376 ;
F_221 ( & V_336 -> V_28 ) ;
if ( V_336 -> V_370 ) {
F_222 ( & V_336 -> V_28 ) ;
return - V_314 ;
}
V_334 = F_231 ( V_361 , & V_376 ) ;
if ( ! V_334 ) {
V_336 -> V_2 -> V_176 = V_376 ;
V_334 = V_159 ;
}
F_222 ( & V_336 -> V_28 ) ;
return V_334 ;
}
static T_4 F_232 ( struct V_335 * V_336 , char * V_361 )
{
int V_375 ;
F_221 ( & V_336 -> V_28 ) ;
V_375 = sprintf ( V_361 , L_88 , V_336 -> V_2 -> V_244 ) ;
F_222 ( & V_336 -> V_28 ) ;
return V_375 ;
}
static T_4 F_233 ( struct V_335 * V_336 ,
const char * V_361 , T_6 V_159 )
{
int V_334 ;
V_62 V_367 ;
F_221 ( & V_336 -> V_28 ) ;
if ( V_336 -> V_370 ) {
V_334 = - V_314 ;
goto V_377;
}
V_334 = F_220 ( V_361 , 0 , & V_367 ) ;
if ( V_334 )
goto V_377;
V_334 = F_146 ( V_367 ) ;
if ( V_334 )
goto V_377;
F_159 ( V_336 -> V_2 , V_367 ) ;
V_334 = V_159 ;
V_377:
F_222 ( & V_336 -> V_28 ) ;
return V_334 ;
}
static void F_234 ( struct V_378 * V_337 )
{
struct V_335 * V_336 ;
V_336 = F_193 ( V_337 ) ;
F_144 ( V_336 -> V_2 ) ;
F_158 ( V_336 ) ;
}
static struct V_378 * F_235 ( void )
{
struct V_335 * V_336 ;
struct V_308 V_365 ;
int V_33 ;
V_336 = F_149 ( sizeof( * V_336 ) , V_78 ) ;
if ( ! V_336 )
return F_150 ( - V_240 ) ;
F_236 ( & V_336 -> V_28 ) ;
V_336 -> V_359 . V_379 = F_234 ;
V_336 -> V_2 = F_148 ( V_336 -> V_2 ) ;
if ( F_171 ( V_336 -> V_2 ) ) {
V_33 = F_172 ( V_336 -> V_2 ) ;
goto V_380;
}
V_33 = F_159 ( V_336 -> V_2 ,
V_381 ) ;
if ( V_33 )
goto V_380;
F_181 ( V_382 L_89 V_383 L_90 ) ;
memset ( & V_365 , 0 , sizeof( V_365 ) ) ;
V_365 . V_142 = true ;
V_33 = F_176 ( V_336 -> V_2 , & V_365 , 0 , L_91 ,
( const char * * ) & V_336 -> V_359 . V_358 . V_362 . V_372 ) ;
if ( V_33 )
goto V_384;
V_336 -> V_385 . V_197 = V_336 -> V_2 -> V_52 [ 0 ] ;
V_336 -> V_385 . V_373 = 0 ;
F_223 ( & V_336 -> V_385 . V_358 , L_91 , & V_374 ) ;
V_336 -> V_386 [ 0 ] = & V_336 -> V_385 . V_358 ;
V_336 -> V_359 . V_358 . V_386 = V_336 -> V_386 ;
F_223 ( & V_336 -> V_359 . V_358 , L_73 , & V_387 ) ;
return & V_336 -> V_359 ;
V_384:
F_168 ( V_336 -> V_2 ) ;
V_380:
F_158 ( V_336 ) ;
return F_150 ( V_33 ) ;
}
static void F_237 ( struct V_6 * V_7 )
{
struct V_5 * V_4 ;
struct V_335 * V_336 ;
V_4 = F_4 ( V_7 , struct V_5 , V_8 ) ;
V_336 = F_4 ( V_7 -> V_337 , struct V_335 , V_359 ) ;
F_221 ( & V_336 -> V_28 ) ;
V_336 -> V_370 -- ;
F_222 ( & V_336 -> V_28 ) ;
F_158 ( V_4 ) ;
}
static struct V_6 * F_238 ( struct V_378 * V_337 )
{
struct V_335 * V_336 = F_193 ( V_337 ) ;
struct V_1 * V_2 = V_336 -> V_2 ;
struct V_5 * V_4 ;
V_4 = F_149 ( sizeof( * V_4 ) , V_78 ) ;
if ( F_48 ( ! V_4 ) )
return F_150 ( - V_240 ) ;
F_221 ( & V_336 -> V_28 ) ;
V_336 -> V_370 ++ ;
F_222 ( & V_336 -> V_28 ) ;
V_4 -> V_8 . V_20 = V_382 ;
V_4 -> V_8 . V_388 = F_192 ;
V_4 -> V_8 . V_389 = F_198 ;
V_4 -> V_8 . V_390 = F_28 ;
V_4 -> V_8 . V_391 = F_112 ;
V_4 -> V_8 . V_392 = F_113 ;
V_4 -> V_8 . V_393 = F_237 ;
V_4 -> V_2 = V_2 ;
return & V_4 -> V_8 ;
}
void F_239 ( struct V_324 * V_309 ,
const struct V_394 * V_395 ,
unsigned int V_244 )
{
struct V_308 * V_197 ;
unsigned V_51 ;
V_309 -> V_325 =
F_32 ( V_395 -> V_52 ? : ( V_395 -> V_396 ? : 1u ) ,
( unsigned ) V_368 ) ;
for ( V_51 = 0 , V_197 = V_309 -> V_52 ; V_51 < V_309 -> V_325 ; ++ V_51 , ++ V_197 ) {
V_197 -> V_120 = ! ! V_395 -> V_120 [ V_51 ] ;
V_197 -> V_139 = ! ! V_395 -> V_139 [ V_51 ] ;
V_197 -> V_142 = ! ! V_395 -> V_142 [ V_51 ] ;
V_197 -> V_315 =
V_395 -> V_396 > V_51 && V_395 -> V_133 [ V_51 ] [ 0 ]
? V_395 -> V_133 [ V_51 ]
: NULL ;
}
V_309 -> V_397 = NULL ;
V_309 -> V_398 = NULL ;
V_309 -> V_273 = NULL ;
V_309 -> V_399 = NULL ;
V_309 -> V_176 = V_395 -> V_376 ;
V_309 -> V_244 = V_244 ;
}
