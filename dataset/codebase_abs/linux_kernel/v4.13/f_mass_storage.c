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
static void F_10 ( struct V_1 * V_2 , enum V_23 V_24 )
{
unsigned long V_25 ;
F_11 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> V_9 <= V_24 ) {
V_2 -> V_27 = V_2 -> V_28 ;
V_2 -> V_9 = V_24 ;
if ( V_2 -> V_29 )
F_12 ( V_30 , V_31 ,
V_2 -> V_29 ) ;
}
F_13 ( & V_2 -> V_26 , V_25 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_15 ( V_2 -> V_33 , V_2 -> V_34 , V_35 ) ;
V_2 -> V_33 -> V_36 = V_2 ;
if ( V_32 != 0 && V_32 != - V_37 ) {
F_16 ( V_2 , L_5 ,
V_2 -> V_33 -> V_20 , V_32 ) ;
}
return V_32 ;
}
static void F_17 ( struct V_18 * V_19 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_36 ;
struct V_11 * V_12 = V_39 -> V_40 ;
if ( V_39 -> V_41 || V_39 -> V_42 != V_39 -> V_13 )
F_8 ( V_2 , L_6 , V_43 ,
V_39 -> V_41 , V_39 -> V_42 , V_39 -> V_13 ) ;
if ( V_39 -> V_41 == - V_44 )
F_18 ( V_19 ) ;
F_19 ( & V_12 -> V_9 , V_45 ) ;
F_20 ( & V_2 -> V_46 ) ;
}
static void F_21 ( struct V_18 * V_19 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_36 ;
struct V_11 * V_12 = V_39 -> V_40 ;
F_22 ( V_2 , L_3 , V_39 -> V_47 , V_39 -> V_42 ) ;
if ( V_39 -> V_41 || V_39 -> V_42 != V_12 -> V_15 )
F_8 ( V_2 , L_6 , V_43 ,
V_39 -> V_41 , V_39 -> V_42 , V_12 -> V_15 ) ;
if ( V_39 -> V_41 == - V_44 )
F_18 ( V_19 ) ;
F_19 ( & V_12 -> V_9 , V_48 ) ;
F_20 ( & V_2 -> V_46 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_49 = F_24 ( V_2 -> V_50 ) - 1 ;
while ( V_49 >= 0 && ! V_2 -> V_50 [ V_49 ] )
-- V_49 ;
return V_49 ;
}
static int F_25 ( struct V_6 * V_7 ,
const struct V_51 * V_52 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_38 * V_39 = V_4 -> V_2 -> V_34 ;
T_1 V_53 = F_26 ( V_52 -> V_54 ) ;
T_1 V_55 = F_26 ( V_52 -> V_56 ) ;
T_1 V_57 = F_26 ( V_52 -> V_58 ) ;
if ( ! F_27 ( V_4 -> V_2 ) )
return - V_59 ;
++ V_4 -> V_2 -> V_28 ;
V_39 -> V_40 = NULL ;
V_39 -> V_13 = 0 ;
F_22 ( V_4 , L_7 , ( V_60 * ) V_52 , sizeof( * V_52 ) ) ;
switch ( V_52 -> V_61 ) {
case V_62 :
if ( V_52 -> V_63 !=
( V_64 | V_65 | V_66 ) )
break;
if ( V_53 != V_4 -> V_67 || V_55 != 0 ||
V_57 != 0 )
return - V_68 ;
F_8 ( V_4 , L_8 ) ;
F_10 ( V_4 -> V_2 , V_69 ) ;
return V_70 ;
case V_71 :
if ( V_52 -> V_63 !=
( V_72 | V_65 | V_66 ) )
break;
if ( V_53 != V_4 -> V_67 || V_55 != 0 ||
V_57 != 1 )
return - V_68 ;
F_28 ( V_4 , L_9 ) ;
* ( V_60 * ) V_39 -> V_47 = F_23 ( V_4 -> V_2 ) ;
V_39 -> V_13 = F_29 ( ( T_1 ) 1 , V_57 ) ;
return F_14 ( V_4 -> V_2 ) ;
}
F_28 ( V_4 ,
L_10 ,
V_52 -> V_63 , V_52 -> V_61 ,
F_26 ( V_52 -> V_56 ) , V_53 , V_57 ) ;
return - V_59 ;
}
static int F_30 ( struct V_5 * V_4 , struct V_18 * V_19 ,
struct V_38 * V_39 )
{
int V_32 ;
if ( V_19 == V_4 -> V_21 )
F_22 ( V_4 , L_2 , V_39 -> V_47 , V_39 -> V_13 ) ;
V_32 = F_15 ( V_19 , V_39 , V_73 ) ;
if ( V_32 ) {
V_39 -> V_41 = V_32 ;
if ( V_32 != - V_37 &&
! ( V_32 == - V_59 && V_39 -> V_13 == 0 ) )
F_16 ( V_4 , L_5 ,
V_19 -> V_20 , V_32 ) ;
}
return V_32 ;
}
static bool F_31 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_27 ( V_2 ) )
return false ;
V_12 -> V_9 = V_74 ;
if ( F_30 ( V_2 -> V_4 , V_2 -> V_4 -> V_21 , V_12 -> V_75 ) )
V_12 -> V_9 = V_45 ;
return true ;
}
static bool F_32 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( ! F_27 ( V_2 ) )
return false ;
V_12 -> V_9 = V_76 ;
if ( F_30 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 , V_12 -> V_17 ) )
V_12 -> V_9 = V_48 ;
return true ;
}
static int F_33 ( struct V_1 * V_2 , bool V_77 ,
struct V_11 * V_12 )
{
int V_32 ;
if ( V_77 )
V_32 = F_34 ( V_2 -> V_46 ,
V_12 && F_35 ( & V_12 -> V_9 ) >=
V_45 ) ;
else
V_32 = F_36 ( V_2 -> V_46 ,
V_12 && F_35 ( & V_12 -> V_9 ) >=
V_45 ) ;
return V_32 ? - V_78 : 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 ;
struct V_11 * V_12 ;
int V_32 ;
T_2 V_82 ;
T_3 V_83 , V_84 ;
unsigned int V_85 ;
T_4 V_86 ;
if ( V_2 -> V_87 [ 0 ] == V_88 )
V_81 = F_38 ( & V_2 -> V_87 [ 1 ] ) ;
else {
V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
if ( ( V_2 -> V_87 [ 1 ] & ~ 0x18 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
}
if ( V_81 >= V_80 -> V_92 ) {
V_80 -> V_89 = V_93 ;
return - V_91 ;
}
V_83 = ( ( T_3 ) V_81 ) << V_80 -> V_94 ;
V_82 = V_2 -> V_95 ;
if ( F_40 ( V_82 == 0 ) )
return - V_96 ;
for (; ; ) {
V_85 = F_29 ( V_82 , V_97 ) ;
V_85 = F_29 ( ( T_3 ) V_85 ,
V_80 -> V_98 - V_83 ) ;
V_12 = V_2 -> V_99 ;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
if ( V_85 == 0 ) {
V_80 -> V_89 =
V_93 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
V_12 -> V_75 -> V_13 = 0 ;
V_12 -> V_9 = V_48 ;
break;
}
V_84 = V_83 ;
V_86 = F_41 ( V_80 -> V_102 ,
( char V_103 * ) V_12 -> V_47 ,
V_85 , & V_84 ) ;
F_42 ( V_80 , L_11 , V_85 ,
( unsigned long long ) V_83 , ( int ) V_86 ) ;
if ( F_43 ( V_104 ) )
return - V_78 ;
if ( V_86 < 0 ) {
F_44 ( V_80 , L_12 , ( int ) V_86 ) ;
V_86 = 0 ;
} else if ( V_86 < V_85 ) {
F_44 ( V_80 , L_13 ,
( int ) V_86 , V_85 ) ;
V_86 = F_45 ( V_86 , V_80 -> V_105 ) ;
}
V_83 += V_86 ;
V_82 -= V_86 ;
V_2 -> V_106 -= V_86 ;
V_12 -> V_75 -> V_13 = V_86 ;
V_12 -> V_9 = V_48 ;
if ( V_86 < V_85 ) {
V_80 -> V_89 = V_107 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
if ( V_82 == 0 )
break;
V_12 -> V_75 -> V_108 = 0 ;
if ( ! F_31 ( V_2 , V_12 ) )
return - V_96 ;
V_2 -> V_99 = V_12 -> V_109 ;
}
return - V_96 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 ;
struct V_11 * V_12 ;
int V_110 ;
T_2 V_111 , V_112 ;
T_3 V_113 , V_83 , V_84 ;
unsigned int V_85 ;
T_4 V_114 ;
int V_32 ;
if ( V_80 -> V_115 ) {
V_80 -> V_89 = V_116 ;
return - V_91 ;
}
F_47 ( & V_80 -> V_102 -> V_117 ) ;
V_80 -> V_102 -> V_118 &= ~ V_119 ;
F_48 ( & V_80 -> V_102 -> V_117 ) ;
if ( V_2 -> V_87 [ 0 ] == V_120 )
V_81 = F_38 ( & V_2 -> V_87 [ 1 ] ) ;
else {
V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
if ( V_2 -> V_87 [ 1 ] & ~ 0x18 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( ! V_80 -> V_121 && ( V_2 -> V_87 [ 1 ] & 0x08 ) ) {
F_47 ( & V_80 -> V_102 -> V_117 ) ;
V_80 -> V_102 -> V_118 |= V_119 ;
F_48 ( & V_80 -> V_102 -> V_117 ) ;
}
}
if ( V_81 >= V_80 -> V_92 ) {
V_80 -> V_89 = V_93 ;
return - V_91 ;
}
V_110 = 1 ;
V_83 = V_113 = ( ( T_3 ) V_81 ) << V_80 -> V_94 ;
V_111 = V_2 -> V_95 ;
V_112 = V_2 -> V_95 ;
while ( V_112 > 0 ) {
V_12 = V_2 -> V_99 ;
if ( V_12 -> V_9 == V_45 && V_110 ) {
V_85 = F_29 ( V_111 , V_97 ) ;
if ( V_113 >= V_80 -> V_98 ) {
V_110 = 0 ;
V_80 -> V_89 =
V_93 ;
V_80 -> V_100 =
V_113 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
continue;
}
V_113 += V_85 ;
V_2 -> V_122 -= V_85 ;
V_111 -= V_85 ;
if ( V_111 == 0 )
V_110 = 0 ;
F_6 ( V_2 , V_12 , V_85 ) ;
if ( ! F_32 ( V_2 , V_12 ) )
return - V_96 ;
V_2 -> V_99 = V_12 -> V_109 ;
continue;
}
V_12 = V_2 -> V_123 ;
if ( V_12 -> V_9 == V_45 && ! V_110 )
break;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_123 = V_12 -> V_109 ;
V_12 -> V_9 = V_45 ;
if ( V_12 -> V_17 -> V_41 != 0 ) {
V_80 -> V_89 = V_124 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
V_85 = V_12 -> V_17 -> V_42 ;
if ( V_80 -> V_98 - V_83 < V_85 ) {
F_49 ( V_80 , L_14 ,
V_85 , ( unsigned long long ) V_83 ,
( unsigned long long ) V_80 -> V_98 ) ;
V_85 = V_80 -> V_98 - V_83 ;
}
V_85 = F_29 ( V_85 , V_12 -> V_15 ) ;
V_85 = F_45 ( V_85 , V_80 -> V_105 ) ;
if ( V_85 == 0 )
goto V_125;
V_84 = V_83 ;
V_114 = F_50 ( V_80 -> V_102 , ( char V_103 * ) V_12 -> V_47 ,
V_85 , & V_84 ) ;
F_42 ( V_80 , L_15 , V_85 ,
( unsigned long long ) V_83 , ( int ) V_114 ) ;
if ( F_43 ( V_104 ) )
return - V_78 ;
if ( V_114 < 0 ) {
F_44 ( V_80 , L_16 ,
( int ) V_114 ) ;
V_114 = 0 ;
} else if ( V_114 < V_85 ) {
F_44 ( V_80 , L_17 ,
( int ) V_114 , V_85 ) ;
V_114 = F_45 ( V_114 , V_80 -> V_105 ) ;
}
V_83 += V_114 ;
V_112 -= V_114 ;
V_2 -> V_106 -= V_114 ;
if ( V_114 < V_85 ) {
V_80 -> V_89 = V_126 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
V_125:
if ( V_12 -> V_17 -> V_42 < V_12 -> V_15 ) {
V_2 -> V_127 = 1 ;
break;
}
}
return - V_96 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_32 ;
V_32 = F_52 ( V_80 ) ;
if ( V_32 )
V_80 -> V_89 = V_126 ;
return 0 ;
}
static void F_53 ( struct V_79 * V_80 )
{
struct V_128 * V_102 = V_80 -> V_102 ;
struct V_129 * V_129 = F_54 ( V_102 ) ;
unsigned long V_32 ;
V_32 = F_55 ( V_129 -> V_130 , 0 , - 1 ) ;
F_42 ( V_80 , L_18 , V_32 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 ;
T_2 V_131 ;
struct V_11 * V_12 = V_2 -> V_99 ;
T_3 V_83 , V_84 ;
T_2 V_82 ;
unsigned int V_85 ;
T_4 V_86 ;
V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
if ( V_81 >= V_80 -> V_92 ) {
V_80 -> V_89 = V_93 ;
return - V_91 ;
}
if ( V_2 -> V_87 [ 1 ] & ~ 0x10 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
V_131 = F_57 ( & V_2 -> V_87 [ 7 ] ) ;
if ( F_40 ( V_131 == 0 ) )
return - V_96 ;
V_82 = V_131 << V_80 -> V_94 ;
V_83 = ( ( T_3 ) V_81 ) << V_80 -> V_94 ;
F_52 ( V_80 ) ;
if ( F_43 ( V_104 ) )
return - V_78 ;
F_53 ( V_80 ) ;
if ( F_43 ( V_104 ) )
return - V_78 ;
while ( V_82 > 0 ) {
V_85 = F_29 ( V_82 , V_97 ) ;
V_85 = F_29 ( ( T_3 ) V_85 ,
V_80 -> V_98 - V_83 ) ;
if ( V_85 == 0 ) {
V_80 -> V_89 =
V_93 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
V_84 = V_83 ;
V_86 = F_41 ( V_80 -> V_102 ,
( char V_103 * ) V_12 -> V_47 ,
V_85 , & V_84 ) ;
F_42 ( V_80 , L_11 , V_85 ,
( unsigned long long ) V_83 ,
( int ) V_86 ) ;
if ( F_43 ( V_104 ) )
return - V_78 ;
if ( V_86 < 0 ) {
F_44 ( V_80 , L_19 , ( int ) V_86 ) ;
V_86 = 0 ;
} else if ( V_86 < V_85 ) {
F_44 ( V_80 , L_20 ,
( int ) V_86 , V_85 ) ;
V_86 = F_45 ( V_86 , V_80 -> V_105 ) ;
}
if ( V_86 == 0 ) {
V_80 -> V_89 = V_107 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
V_83 += V_86 ;
V_82 -= V_86 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
if ( ! V_80 ) {
V_2 -> V_132 = 1 ;
memset ( V_47 , 0 , 36 ) ;
V_47 [ 0 ] = V_133 ;
V_47 [ 4 ] = 31 ;
return 36 ;
}
V_47 [ 0 ] = V_80 -> V_134 ? V_135 : V_136 ;
V_47 [ 1 ] = V_80 -> V_137 ? 0x80 : 0 ;
V_47 [ 2 ] = 2 ;
V_47 [ 3 ] = 2 ;
V_47 [ 4 ] = 31 ;
V_47 [ 5 ] = 0 ;
V_47 [ 6 ] = 0 ;
V_47 [ 7 ] = 0 ;
if ( V_80 -> V_138 [ 0 ] )
memcpy ( V_47 + 8 , V_80 -> V_138 ,
sizeof( V_80 -> V_138 ) ) ;
else
memcpy ( V_47 + 8 , V_2 -> V_138 ,
sizeof( V_2 -> V_138 ) ) ;
return 36 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
T_2 V_139 , V_140 ;
int V_141 ;
#if 0
if (curlun && curlun->unit_attention_data != SS_NO_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
}
#endif
if ( ! V_80 ) {
V_2 -> V_132 = 1 ;
V_139 = V_142 ;
V_140 = 0 ;
V_141 = 0 ;
} else {
V_139 = V_80 -> V_89 ;
V_140 = V_80 -> V_100 ;
V_141 = V_80 -> V_101 << 7 ;
V_80 -> V_89 = V_143 ;
V_80 -> V_100 = 0 ;
V_80 -> V_101 = 0 ;
}
memset ( V_47 , 0 , 18 ) ;
V_47 [ 0 ] = V_141 | 0x70 ;
V_47 [ 2 ] = F_60 ( V_139 ) ;
F_61 ( V_140 , & V_47 [ 3 ] ) ;
V_47 [ 7 ] = 18 - 8 ;
V_47 [ 12 ] = F_62 ( V_139 ) ;
V_47 [ 13 ] = F_63 ( V_139 ) ;
return 18 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
int V_144 = V_2 -> V_87 [ 8 ] ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
if ( V_144 > 1 || ( V_144 == 0 && V_81 != 0 ) ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
F_61 ( V_80 -> V_92 - 1 , & V_47 [ 0 ] ) ;
F_61 ( V_80 -> V_105 , & V_47 [ 4 ] ) ;
return 8 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_145 = V_2 -> V_87 [ 1 ] & 0x02 ;
T_2 V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
if ( V_2 -> V_87 [ 1 ] & ~ 0x02 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( V_81 >= V_80 -> V_92 ) {
V_80 -> V_89 = V_93 ;
return - V_91 ;
}
memset ( V_47 , 0 , 8 ) ;
V_47 [ 0 ] = 0x01 ;
F_66 ( & V_47 [ 4 ] , V_145 , V_81 ) ;
return 8 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_145 = V_2 -> V_87 [ 1 ] & 0x02 ;
int V_146 = V_2 -> V_87 [ 6 ] ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
if ( ( V_2 -> V_87 [ 1 ] & ~ 0x02 ) != 0 ||
V_146 > 1 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
memset ( V_47 , 0 , 20 ) ;
V_47 [ 1 ] = ( 20 - 2 ) ;
V_47 [ 2 ] = 1 ;
V_47 [ 3 ] = 1 ;
V_47 [ 5 ] = 0x16 ;
V_47 [ 6 ] = 0x01 ;
F_66 ( & V_47 [ 8 ] , V_145 , 0 ) ;
V_47 [ 13 ] = 0x16 ;
V_47 [ 14 ] = 0xAA ;
F_66 ( & V_47 [ 16 ] , V_145 , V_80 -> V_92 ) ;
return 20 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_147 = V_2 -> V_87 [ 0 ] ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
V_60 * V_148 = V_47 ;
int V_149 , V_150 ;
int V_151 , V_152 ;
int V_153 = 0 ;
int V_154 , V_155 ;
if ( ( V_2 -> V_87 [ 1 ] & ~ 0x08 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
V_149 = V_2 -> V_87 [ 2 ] >> 6 ;
V_150 = V_2 -> V_87 [ 2 ] & 0x3f ;
if ( V_149 == 3 ) {
V_80 -> V_89 = V_156 ;
return - V_91 ;
}
V_151 = ( V_149 == 1 ) ;
V_152 = ( V_150 == 0x3f ) ;
memset ( V_47 , 0 , 8 ) ;
if ( V_147 == V_157 ) {
V_47 [ 2 ] = ( V_80 -> V_115 ? 0x80 : 0x00 ) ;
V_47 += 4 ;
V_155 = 255 ;
} else {
V_47 [ 3 ] = ( V_80 -> V_115 ? 0x80 : 0x00 ) ;
V_47 += 8 ;
V_155 = 65535 ;
}
if ( V_150 == 0x08 || V_152 ) {
V_153 = 1 ;
V_47 [ 0 ] = 0x08 ;
V_47 [ 1 ] = 10 ;
memset ( V_47 + 2 , 0 , 10 ) ;
if ( ! V_151 ) {
V_47 [ 2 ] = 0x04 ;
F_69 ( 0xffff , & V_47 [ 4 ] ) ;
F_69 ( 0xffff , & V_47 [ 8 ] ) ;
F_69 ( 0xffff , & V_47 [ 10 ] ) ;
}
V_47 += 12 ;
}
V_154 = V_47 - V_148 ;
if ( ! V_153 || V_154 > V_155 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( V_147 == V_157 )
V_148 [ 0 ] = V_154 - 1 ;
else
F_69 ( V_154 - 2 , V_148 ) ;
return V_154 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_158 , V_159 ;
if ( ! V_80 ) {
return - V_91 ;
} else if ( ! V_80 -> V_137 ) {
V_80 -> V_89 = V_160 ;
return - V_91 ;
} else if ( ( V_2 -> V_87 [ 1 ] & ~ 0x01 ) != 0 ||
( V_2 -> V_87 [ 4 ] & ~ 0x03 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
V_158 = V_2 -> V_87 [ 4 ] & 0x02 ;
V_159 = V_2 -> V_87 [ 4 ] & 0x01 ;
if ( V_159 ) {
if ( ! F_71 ( V_80 ) ) {
V_80 -> V_89 = V_161 ;
return - V_91 ;
}
return 0 ;
}
if ( V_80 -> V_162 ) {
F_44 ( V_80 , L_21 ) ;
V_80 -> V_89 = V_163 ;
return - V_91 ;
}
if ( ! V_158 )
return 0 ;
F_72 ( & V_2 -> V_164 ) ;
F_73 ( & V_2 -> V_164 ) ;
F_74 ( V_80 ) ;
F_75 ( & V_2 -> V_164 ) ;
F_76 ( & V_2 -> V_164 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_165 ;
if ( ! V_2 -> V_80 ) {
return - V_91 ;
} else if ( ! V_2 -> V_80 -> V_137 ) {
V_2 -> V_80 -> V_89 = V_160 ;
return - V_91 ;
}
V_165 = V_2 -> V_87 [ 4 ] & 0x01 ;
if ( ( V_2 -> V_87 [ 4 ] & ~ 0x01 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( V_80 -> V_162 && ! V_165 )
F_52 ( V_80 ) ;
V_80 -> V_162 = V_165 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
V_47 [ 0 ] = V_47 [ 1 ] = V_47 [ 2 ] = 0 ;
V_47 [ 3 ] = 8 ;
V_47 += 4 ;
F_61 ( V_80 -> V_92 , & V_47 [ 0 ] ) ;
F_61 ( V_80 -> V_105 , & V_47 [ 4 ] ) ;
V_47 [ 4 ] = 0x02 ;
return 12 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
if ( V_80 )
V_80 -> V_89 = V_160 ;
return - V_91 ;
}
static int F_80 ( struct V_5 * V_4 )
{
int V_32 ;
V_32 = F_7 ( V_4 , V_4 -> V_21 ) ;
if ( V_32 == - V_166 )
F_28 ( V_4 , L_22 ) ;
while ( V_32 != 0 ) {
if ( V_32 != - V_166 ) {
F_16 ( V_4 , L_23 , V_32 ) ;
V_32 = 0 ;
break;
}
if ( F_81 ( 100 ) != 0 )
return - V_78 ;
V_32 = F_9 ( V_4 -> V_21 ) ;
}
return V_32 ;
}
static int F_82 ( struct V_5 * V_4 )
{
int V_32 ;
F_8 ( V_4 , L_24 ) ;
V_32 = F_83 ( V_4 -> V_21 ) ;
if ( V_32 == - V_166 )
F_28 ( V_4 , L_25 ) ;
while ( V_32 != 0 ) {
if ( V_32 != - V_166 ) {
F_16 ( V_4 , L_26 , V_32 ) ;
V_32 = 0 ;
break;
}
if ( F_81 ( 100 ) != 0 )
return - V_78 ;
V_32 = F_83 ( V_4 -> V_21 ) ;
}
return V_32 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_167 ;
T_2 V_85 ;
int V_32 ;
for ( V_12 = V_2 -> V_123 ;
V_12 -> V_9 != V_45 || V_2 -> V_122 > 0 ;
V_12 = V_2 -> V_123 ) {
V_167 = V_2 -> V_99 ;
if ( V_167 -> V_9 == V_45 &&
V_2 -> V_122 > 0 ) {
V_85 = F_29 ( V_2 -> V_122 , V_97 ) ;
F_6 ( V_2 , V_167 , V_85 ) ;
if ( ! F_32 ( V_2 , V_167 ) )
return - V_96 ;
V_2 -> V_99 = V_167 -> V_109 ;
V_2 -> V_122 -= V_85 ;
continue;
}
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
V_12 -> V_9 = V_45 ;
V_2 -> V_123 = V_12 -> V_109 ;
if ( V_12 -> V_17 -> V_42 < V_12 -> V_15 ||
V_12 -> V_17 -> V_41 != 0 ) {
F_10 ( V_2 , V_168 ) ;
return - V_78 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_99 ;
int V_32 = 0 ;
switch ( V_2 -> V_169 ) {
case V_170 :
break;
case V_171 :
if ( ! V_2 -> V_172 ) {
} else if ( F_27 ( V_2 ) ) {
F_7 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ) ;
V_32 = F_80 ( V_2 -> V_4 ) ;
} else {
V_32 = - V_96 ;
}
break;
case V_173 :
if ( V_2 -> V_174 == 0 ) {
} else if ( ! F_27 ( V_2 ) ) {
V_32 = - V_96 ;
} else if ( V_2 -> V_106 == 0 ) {
V_12 -> V_75 -> V_108 = 0 ;
if ( ! F_31 ( V_2 , V_12 ) )
return - V_96 ;
V_2 -> V_99 = V_12 -> V_109 ;
} else {
V_12 -> V_75 -> V_108 = 1 ;
if ( ! F_31 ( V_2 , V_12 ) )
V_32 = - V_96 ;
V_2 -> V_99 = V_12 -> V_109 ;
if ( V_2 -> V_172 )
V_32 = F_80 ( V_2 -> V_4 ) ;
}
break;
case V_175 :
if ( V_2 -> V_106 == 0 ) {
} else if ( V_2 -> V_127 ) {
F_10 ( V_2 , V_168 ) ;
V_32 = - V_78 ;
#if 0
} else if (common->can_stall) {
if (fsg_is_set(common))
fsg_set_halt(common->fsg,
common->fsg->bulk_out);
raise_exception(common, FSG_STATE_ABORT_BULK_OUT);
rc = -EINTR;
#endif
} else {
V_32 = F_84 ( V_2 ) ;
}
break;
}
return V_32 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
struct V_11 * V_12 ;
struct V_176 * V_177 ;
int V_32 ;
V_60 V_41 = V_178 ;
T_2 V_139 , V_140 = 0 ;
V_12 = V_2 -> V_99 ;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return;
if ( V_80 ) {
V_139 = V_80 -> V_89 ;
V_140 = V_80 -> V_100 ;
} else if ( V_2 -> V_132 )
V_139 = V_143 ;
else
V_139 = V_142 ;
if ( V_2 -> V_179 ) {
F_8 ( V_2 , L_27 ) ;
V_41 = V_180 ;
V_139 = V_160 ;
} else if ( V_139 != V_143 ) {
F_8 ( V_2 , L_28 ) ;
V_41 = V_181 ;
F_28 ( V_2 , L_29
L_30 ,
F_60 ( V_139 ) , F_62 ( V_139 ) , F_63 ( V_139 ) , V_140 ) ;
}
V_177 = ( void * ) V_12 -> V_47 ;
V_177 -> V_182 = F_87 ( V_183 ) ;
V_177 -> V_184 = V_2 -> V_185 ;
V_177 -> V_186 = F_87 ( V_2 -> V_106 ) ;
V_177 -> V_187 = V_41 ;
V_12 -> V_75 -> V_13 = V_188 ;
V_12 -> V_75 -> V_108 = 0 ;
if ( ! F_31 ( V_2 , V_12 ) )
return;
V_2 -> V_99 = V_12 -> V_109 ;
return;
}
static int F_88 ( struct V_1 * V_2 , int V_189 ,
enum V_190 V_169 , unsigned int V_191 ,
int V_192 , const char * V_20 )
{
int V_49 ;
unsigned int V_193 = V_2 -> V_87 [ 1 ] >> 5 ;
static const char V_194 [ 4 ] = { 'u' , 'o' , 'i' , 'n' } ;
char V_195 [ 20 ] ;
struct V_79 * V_80 ;
V_195 [ 0 ] = 0 ;
if ( V_2 -> V_169 != V_171 )
sprintf ( V_195 , L_31 , V_194 [ ( int ) V_2 -> V_169 ] ,
V_2 -> V_174 ) ;
F_28 ( V_2 , L_32 ,
V_20 , V_189 , V_194 [ ( int ) V_169 ] ,
V_2 -> V_95 , V_2 -> V_189 , V_195 ) ;
if ( V_2 -> V_95 == 0 )
V_169 = V_170 ;
if ( V_2 -> V_174 < V_2 -> V_95 ) {
V_2 -> V_95 = V_2 -> V_174 ;
V_2 -> V_179 = 1 ;
}
V_2 -> V_106 = V_2 -> V_174 ;
V_2 -> V_122 = V_2 -> V_174 ;
if ( V_2 -> V_169 != V_169 && V_2 -> V_95 > 0 ) {
V_2 -> V_179 = 1 ;
return - V_91 ;
}
if ( V_189 != V_2 -> V_189 ) {
if ( V_189 <= V_2 -> V_189 ) {
F_8 ( V_2 , L_33
L_34 , V_20 ,
V_189 , V_2 -> V_189 ) ;
V_189 = V_2 -> V_189 ;
} else {
V_2 -> V_179 = 1 ;
return - V_91 ;
}
}
if ( V_2 -> V_193 != V_193 )
F_8 ( V_2 , L_35 ,
V_2 -> V_193 , V_193 ) ;
V_80 = V_2 -> V_80 ;
if ( V_80 ) {
if ( V_2 -> V_87 [ 0 ] != V_196 ) {
V_80 -> V_89 = V_143 ;
V_80 -> V_100 = 0 ;
V_80 -> V_101 = 0 ;
}
} else {
V_2 -> V_132 = 0 ;
if ( V_2 -> V_87 [ 0 ] != V_197 &&
V_2 -> V_87 [ 0 ] != V_196 ) {
F_8 ( V_2 , L_36 , V_2 -> V_193 ) ;
return - V_91 ;
}
}
if ( V_80 && V_80 -> V_198 != V_143 &&
V_2 -> V_87 [ 0 ] != V_197 &&
V_2 -> V_87 [ 0 ] != V_196 ) {
V_80 -> V_89 = V_80 -> V_198 ;
V_80 -> V_198 = V_143 ;
return - V_91 ;
}
V_2 -> V_87 [ 1 ] &= 0x1f ;
for ( V_49 = 1 ; V_49 < V_189 ; ++ V_49 ) {
if ( V_2 -> V_87 [ V_49 ] && ! ( V_191 & ( 1 << V_49 ) ) ) {
if ( V_80 )
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
}
if ( V_80 && ! F_71 ( V_80 ) && V_192 ) {
V_80 -> V_89 = V_161 ;
return - V_91 ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
int V_189 , enum V_190 V_169 ,
unsigned int V_191 , int V_192 , const char * V_20 )
{
if ( V_2 -> V_80 )
V_2 -> V_95 <<= V_2 -> V_80 -> V_94 ;
return F_88 ( V_2 , V_189 , V_169 ,
V_191 , V_192 , V_20 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_32 ;
int V_199 = - V_91 ;
int V_49 ;
static char V_200 [ 16 ] ;
F_91 ( V_2 ) ;
V_12 = V_2 -> V_99 ;
V_2 -> V_123 = V_12 ;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_179 = 0 ;
V_2 -> V_127 = 0 ;
F_76 ( & V_2 -> V_164 ) ;
switch ( V_2 -> V_87 [ 0 ] ) {
case V_197 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_199 = F_88 ( V_2 , 6 , V_173 ,
( 1 << 4 ) , 0 ,
L_37 ) ;
if ( V_199 == 0 )
V_199 = F_58 ( V_2 , V_12 ) ;
break;
case V_201 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_199 = F_88 ( V_2 , 6 , V_175 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_38 ) ;
if ( V_199 == 0 )
V_199 = F_79 ( V_2 , V_12 ) ;
break;
case V_202 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_88 ( V_2 , 10 , V_175 ,
( 1 << 1 ) | ( 3 << 7 ) , 0 ,
L_39 ) ;
if ( V_199 == 0 )
V_199 = F_79 ( V_2 , V_12 ) ;
break;
case V_157 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_199 = F_88 ( V_2 , 6 , V_173 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) , 0 ,
L_40 ) ;
if ( V_199 == 0 )
V_199 = F_68 ( V_2 , V_12 ) ;
break;
case V_203 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_88 ( V_2 , 10 , V_173 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 3 << 7 ) , 0 ,
L_41 ) ;
if ( V_199 == 0 )
V_199 = F_68 ( V_2 , V_12 ) ;
break;
case V_204 :
V_2 -> V_95 = 0 ;
V_199 = F_88 ( V_2 , 6 , V_170 ,
( 1 << 4 ) , 0 ,
L_42 ) ;
if ( V_199 == 0 )
V_199 = F_77 ( V_2 ) ;
break;
case V_88 :
V_49 = V_2 -> V_87 [ 4 ] ;
V_2 -> V_95 = ( V_49 == 0 ) ? 256 : V_49 ;
V_199 = F_89 ( V_2 , 6 ,
V_173 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_43 ) ;
if ( V_199 == 0 )
V_199 = F_37 ( V_2 ) ;
break;
case V_205 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_89 ( V_2 , 10 ,
V_173 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_44 ) ;
if ( V_199 == 0 )
V_199 = F_37 ( V_2 ) ;
break;
case V_206 :
V_2 -> V_95 =
F_39 ( & V_2 -> V_87 [ 6 ] ) ;
V_199 = F_89 ( V_2 , 12 ,
V_173 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_45 ) ;
if ( V_199 == 0 )
V_199 = F_37 ( V_2 ) ;
break;
case V_207 :
V_2 -> V_95 = 8 ;
V_199 = F_88 ( V_2 , 10 , V_173 ,
( 0xf << 2 ) | ( 1 << 8 ) , 1 ,
L_46 ) ;
if ( V_199 == 0 )
V_199 = F_64 ( V_2 , V_12 ) ;
break;
case V_208 :
if ( ! V_2 -> V_80 || ! V_2 -> V_80 -> V_134 )
goto V_209;
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_88 ( V_2 , 10 , V_173 ,
( 3 << 7 ) | ( 0x1f << 1 ) , 1 ,
L_47 ) ;
if ( V_199 == 0 )
V_199 = F_65 ( V_2 , V_12 ) ;
break;
case V_210 :
if ( ! V_2 -> V_80 || ! V_2 -> V_80 -> V_134 )
goto V_209;
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_88 ( V_2 , 10 , V_173 ,
( 7 << 6 ) | ( 1 << 1 ) , 1 ,
L_48 ) ;
if ( V_199 == 0 )
V_199 = F_67 ( V_2 , V_12 ) ;
break;
case V_211 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_88 ( V_2 , 10 , V_173 ,
( 3 << 7 ) , 1 ,
L_49 ) ;
if ( V_199 == 0 )
V_199 = F_78 ( V_2 , V_12 ) ;
break;
case V_196 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_199 = F_88 ( V_2 , 6 , V_173 ,
( 1 << 4 ) , 0 ,
L_50 ) ;
if ( V_199 == 0 )
V_199 = F_59 ( V_2 , V_12 ) ;
break;
case V_212 :
V_2 -> V_95 = 0 ;
V_199 = F_88 ( V_2 , 6 , V_170 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_51 ) ;
if ( V_199 == 0 )
V_199 = F_70 ( V_2 ) ;
break;
case V_213 :
V_2 -> V_95 = 0 ;
V_199 = F_88 ( V_2 , 10 , V_170 ,
( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_52 ) ;
if ( V_199 == 0 )
V_199 = F_51 ( V_2 ) ;
break;
case V_214 :
V_2 -> V_95 = 0 ;
V_199 = F_88 ( V_2 , 6 , V_170 ,
0 , 1 ,
L_53 ) ;
break;
case V_215 :
V_2 -> V_95 = 0 ;
V_199 = F_88 ( V_2 , 10 , V_170 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_54 ) ;
if ( V_199 == 0 )
V_199 = F_56 ( V_2 ) ;
break;
case V_120 :
V_49 = V_2 -> V_87 [ 4 ] ;
V_2 -> V_95 = ( V_49 == 0 ) ? 256 : V_49 ;
V_199 = F_89 ( V_2 , 6 ,
V_175 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_55 ) ;
if ( V_199 == 0 )
V_199 = F_46 ( V_2 ) ;
break;
case V_216 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_199 = F_89 ( V_2 , 10 ,
V_175 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_56 ) ;
if ( V_199 == 0 )
V_199 = F_46 ( V_2 ) ;
break;
case V_217 :
V_2 -> V_95 =
F_39 ( & V_2 -> V_87 [ 6 ] ) ;
V_199 = F_89 ( V_2 , 12 ,
V_175 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_57 ) ;
if ( V_199 == 0 )
V_199 = F_46 ( V_2 ) ;
break;
case V_218 :
case V_219 :
case V_220 :
case V_221 :
default:
V_209:
V_2 -> V_95 = 0 ;
sprintf ( V_200 , L_58 , V_2 -> V_87 [ 0 ] ) ;
V_199 = F_88 ( V_2 , V_2 -> V_189 ,
V_171 , ~ 0 , 0 , V_200 ) ;
if ( V_199 == 0 ) {
V_2 -> V_80 -> V_89 = V_160 ;
V_199 = - V_91 ;
}
break;
}
F_72 ( & V_2 -> V_164 ) ;
if ( V_199 == - V_78 || F_43 ( V_104 ) )
return - V_78 ;
if ( V_199 == - V_91 )
V_199 = 0 ;
if ( V_199 >= 0 && V_2 -> V_169 == V_173 ) {
V_199 = F_29 ( ( T_2 ) V_199 , V_2 -> V_95 ) ;
V_12 -> V_75 -> V_13 = V_199 ;
V_12 -> V_9 = V_48 ;
V_2 -> V_106 -= V_199 ;
}
return 0 ;
}
static int F_92 ( struct V_5 * V_4 , struct V_11 * V_12 )
{
struct V_38 * V_39 = V_12 -> V_17 ;
struct V_222 * V_223 = V_39 -> V_47 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_39 -> V_41 || F_93 ( V_224 , & V_4 -> V_225 ) )
return - V_91 ;
if ( V_39 -> V_42 != V_226 ||
V_223 -> V_182 != F_87 (
V_227 ) ) {
F_8 ( V_4 , L_59 ,
V_39 -> V_42 ,
F_94 ( V_223 -> V_182 ) ) ;
F_82 ( V_4 ) ;
F_95 ( V_224 , & V_4 -> V_225 ) ;
return - V_91 ;
}
if ( V_223 -> V_228 >= F_24 ( V_2 -> V_50 ) ||
V_223 -> V_229 & ~ V_230 || V_223 -> V_231 <= 0 ||
V_223 -> V_231 > V_232 ) {
F_8 ( V_4 , L_60
L_61 ,
V_223 -> V_228 , V_223 -> V_229 , V_223 -> V_231 ) ;
if ( V_2 -> V_172 ) {
F_7 ( V_4 , V_4 -> V_22 ) ;
F_80 ( V_4 ) ;
}
return - V_91 ;
}
V_2 -> V_189 = V_223 -> V_231 ;
memcpy ( V_2 -> V_87 , V_223 -> V_233 , V_2 -> V_189 ) ;
if ( V_223 -> V_229 & V_230 )
V_2 -> V_169 = V_173 ;
else
V_2 -> V_169 = V_175 ;
V_2 -> V_174 = F_94 ( V_223 -> V_234 ) ;
if ( V_2 -> V_174 == 0 )
V_2 -> V_169 = V_170 ;
V_2 -> V_193 = V_223 -> V_228 ;
if ( V_2 -> V_193 < F_24 ( V_2 -> V_50 ) )
V_2 -> V_80 = V_2 -> V_50 [ V_2 -> V_193 ] ;
else
V_2 -> V_80 = NULL ;
V_2 -> V_185 = V_223 -> V_184 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_32 = 0 ;
V_12 = V_2 -> V_99 ;
V_32 = F_33 ( V_2 , true , V_12 ) ;
if ( V_32 )
return V_32 ;
F_6 ( V_2 , V_12 , V_226 ) ;
if ( ! F_32 ( V_2 , V_12 ) )
return - V_96 ;
V_32 = F_33 ( V_2 , true , V_12 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_27 ( V_2 ) ? F_92 ( V_2 -> V_4 , V_12 ) : - V_96 ;
V_12 -> V_9 = V_45 ;
return V_32 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_38 * * V_235 )
{
* V_235 = F_98 ( V_19 , V_35 ) ;
if ( * V_235 )
return 0 ;
ERROR ( V_2 , L_62 , V_19 -> V_20 ) ;
return - V_236 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_5 * V_237 )
{
struct V_5 * V_4 ;
int V_49 , V_32 = 0 ;
if ( V_2 -> V_238 )
F_8 ( V_2 , L_63 ) ;
V_239:
if ( V_2 -> V_4 ) {
V_4 = V_2 -> V_4 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_240 ; ++ V_49 ) {
struct V_11 * V_12 = & V_2 -> V_241 [ V_49 ] ;
if ( V_12 -> V_75 ) {
F_100 ( V_4 -> V_21 , V_12 -> V_75 ) ;
V_12 -> V_75 = NULL ;
}
if ( V_12 -> V_17 ) {
F_100 ( V_4 -> V_22 , V_12 -> V_17 ) ;
V_12 -> V_17 = NULL ;
}
}
if ( V_4 -> V_242 ) {
F_101 ( V_4 -> V_21 ) ;
V_4 -> V_242 = 0 ;
}
if ( V_4 -> V_243 ) {
F_101 ( V_4 -> V_22 ) ;
V_4 -> V_243 = 0 ;
}
V_2 -> V_4 = NULL ;
F_20 ( & V_2 -> V_244 ) ;
}
V_2 -> V_238 = 0 ;
if ( ! V_237 || V_32 )
return V_32 ;
V_2 -> V_4 = V_237 ;
V_4 = V_2 -> V_4 ;
V_32 = F_102 ( V_2 -> V_245 , & ( V_4 -> V_8 ) , V_4 -> V_21 ) ;
if ( V_32 )
goto V_239;
V_32 = F_103 ( V_4 -> V_21 ) ;
if ( V_32 )
goto V_239;
V_4 -> V_21 -> V_36 = V_2 ;
V_4 -> V_242 = 1 ;
V_32 = F_102 ( V_2 -> V_245 , & ( V_4 -> V_8 ) ,
V_4 -> V_22 ) ;
if ( V_32 )
goto V_239;
V_32 = F_103 ( V_4 -> V_22 ) ;
if ( V_32 )
goto V_239;
V_4 -> V_22 -> V_36 = V_2 ;
V_4 -> V_243 = 1 ;
V_2 -> V_16 = F_104 ( V_4 -> V_22 -> V_246 ) ;
F_105 ( V_224 , & V_4 -> V_225 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_240 ; ++ V_49 ) {
struct V_11 * V_12 = & V_2 -> V_241 [ V_49 ] ;
V_32 = F_97 ( V_2 , V_4 -> V_21 , & V_12 -> V_75 ) ;
if ( V_32 )
goto V_239;
V_32 = F_97 ( V_2 , V_4 -> V_22 , & V_12 -> V_17 ) ;
if ( V_32 )
goto V_239;
V_12 -> V_75 -> V_47 = V_12 -> V_17 -> V_47 = V_12 -> V_47 ;
V_12 -> V_75 -> V_40 = V_12 -> V_17 -> V_40 = V_12 ;
V_12 -> V_75 -> V_247 = F_17 ;
V_12 -> V_17 -> V_247 = F_21 ;
}
V_2 -> V_238 = 1 ;
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; ++ V_49 )
if ( V_2 -> V_50 [ V_49 ] )
V_2 -> V_50 [ V_49 ] -> V_198 =
V_248 ;
return V_32 ;
}
static int F_106 ( struct V_6 * V_7 , unsigned V_249 , unsigned V_250 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_237 = V_4 ;
F_10 ( V_4 -> V_2 , V_251 ) ;
return V_70 ;
}
static void F_107 ( struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_237 = NULL ;
F_10 ( V_4 -> V_2 , V_251 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_49 ;
struct V_11 * V_12 ;
enum V_23 V_252 ;
struct V_79 * V_80 ;
unsigned int V_27 ;
for (; ; ) {
int V_253 = F_109 ( NULL ) ;
if ( ! V_253 )
break;
if ( V_253 != V_30 ) {
F_110 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_9 < V_254 )
F_8 ( V_2 , L_64 ) ;
V_2 -> V_9 = V_254 ;
F_111 ( & V_2 -> V_26 ) ;
}
}
if ( F_112 ( V_2 -> V_4 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_240 ; ++ V_49 ) {
V_12 = & V_2 -> V_241 [ V_49 ] ;
if ( V_12 -> V_9 == V_74 )
F_113 ( V_2 -> V_4 -> V_21 , V_12 -> V_75 ) ;
if ( V_12 -> V_9 == V_76 )
F_113 ( V_2 -> V_4 -> V_22 ,
V_12 -> V_17 ) ;
if ( F_33 ( V_2 , false , V_12 ) )
return;
}
if ( V_2 -> V_4 -> V_242 )
F_18 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_4 -> V_243 )
F_18 ( V_2 -> V_4 -> V_22 ) ;
}
F_110 ( & V_2 -> V_26 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_240 ; ++ V_49 ) {
V_12 = & V_2 -> V_241 [ V_49 ] ;
V_12 -> V_9 = V_45 ;
}
V_2 -> V_99 = & V_2 -> V_241 [ 0 ] ;
V_2 -> V_123 = & V_2 -> V_241 [ 0 ] ;
V_27 = V_2 -> V_27 ;
V_252 = V_2 -> V_9 ;
V_2 -> V_9 = V_10 ;
if ( V_252 != V_168 ) {
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; ++ V_49 ) {
V_80 = V_2 -> V_50 [ V_49 ] ;
if ( ! V_80 )
continue;
V_80 -> V_162 = 0 ;
V_80 -> V_89 = V_143 ;
V_80 -> V_198 = V_143 ;
V_80 -> V_100 = 0 ;
V_80 -> V_101 = 0 ;
}
}
F_111 ( & V_2 -> V_26 ) ;
switch ( V_252 ) {
case V_10 :
break;
case V_168 :
F_86 ( V_2 ) ;
break;
case V_69 :
if ( ! F_27 ( V_2 ) )
break;
if ( F_114 ( V_224 ,
& V_2 -> V_4 -> V_225 ) )
F_115 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_28 == V_27 )
F_14 ( V_2 ) ;
break;
case V_251 :
F_99 ( V_2 , V_2 -> V_237 ) ;
if ( V_2 -> V_237 )
F_116 ( V_2 -> V_255 ) ;
break;
case V_254 :
F_99 ( V_2 , NULL ) ;
F_110 ( & V_2 -> V_26 ) ;
V_2 -> V_9 = V_256 ;
F_111 ( & V_2 -> V_26 ) ;
break;
case V_256 :
break;
}
}
static int F_117 ( void * V_257 )
{
struct V_1 * V_2 = V_257 ;
F_118 ( V_258 ) ;
F_118 ( V_259 ) ;
F_118 ( V_260 ) ;
F_118 ( V_30 ) ;
F_119 () ;
F_120 ( F_121 () ) ;
while ( V_2 -> V_9 != V_256 ) {
if ( F_5 ( V_2 ) || F_43 ( V_104 ) ) {
F_108 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_238 ) {
F_33 ( V_2 , true , NULL ) ;
continue;
}
if ( F_96 ( V_2 ) || F_5 ( V_2 ) )
continue;
if ( F_90 ( V_2 ) || F_5 ( V_2 ) )
continue;
if ( F_85 ( V_2 ) || F_5 ( V_2 ) )
continue;
F_86 ( V_2 ) ;
}
F_110 ( & V_2 -> V_26 ) ;
V_2 -> V_29 = NULL ;
F_111 ( & V_2 -> V_26 ) ;
if ( ! V_2 -> V_261 || ! V_2 -> V_261 -> V_262
|| V_2 -> V_261 -> V_262 ( V_2 ) < 0 ) {
int V_49 ;
F_73 ( & V_2 -> V_164 ) ;
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; V_49 ++ ) {
struct V_79 * V_80 = V_2 -> V_50 [ V_49 ] ;
if ( ! V_80 || ! F_71 ( V_80 ) )
continue;
F_74 ( V_80 ) ;
V_80 -> V_198 = V_161 ;
}
F_75 ( & V_2 -> V_164 ) ;
}
F_122 ( & V_2 -> V_263 , 0 ) ;
}
static T_4 F_123 ( struct V_264 * V_265 , struct V_266 * V_267 , char * V_47 )
{
struct V_79 * V_80 = F_124 ( V_265 ) ;
return F_125 ( V_80 , V_47 ) ;
}
static T_4 F_126 ( struct V_264 * V_265 , struct V_266 * V_267 ,
char * V_47 )
{
struct V_79 * V_80 = F_124 ( V_265 ) ;
return F_127 ( V_80 , V_47 ) ;
}
static T_4 F_128 ( struct V_264 * V_265 , struct V_266 * V_267 ,
char * V_47 )
{
struct V_79 * V_80 = F_124 ( V_265 ) ;
struct V_268 * V_164 = F_129 ( V_265 ) ;
return F_130 ( V_80 , V_164 , V_47 ) ;
}
static T_4 F_131 ( struct V_264 * V_265 , struct V_266 * V_267 ,
const char * V_47 , T_5 V_269 )
{
struct V_79 * V_80 = F_124 ( V_265 ) ;
struct V_268 * V_164 = F_129 ( V_265 ) ;
return F_132 ( V_80 , V_164 , V_47 , V_269 ) ;
}
static T_4 F_133 ( struct V_264 * V_265 , struct V_266 * V_267 ,
const char * V_47 , T_5 V_269 )
{
struct V_79 * V_80 = F_124 ( V_265 ) ;
return F_134 ( V_80 , V_47 , V_269 ) ;
}
static T_4 F_135 ( struct V_264 * V_265 , struct V_266 * V_267 ,
const char * V_47 , T_5 V_269 )
{
struct V_79 * V_80 = F_124 ( V_265 ) ;
struct V_268 * V_164 = F_129 ( V_265 ) ;
return F_136 ( V_80 , V_164 , V_47 , V_269 ) ;
}
static void F_137 ( struct V_264 * V_265 )
{
}
void F_138 ( struct V_1 * V_2 )
{
F_139 ( & V_2 -> V_270 ) ;
}
void F_140 ( struct V_1 * V_2 )
{
F_141 ( & V_2 -> V_270 , V_271 ) ;
}
static struct V_1 * F_142 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
V_2 = F_143 ( sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return F_144 ( - V_236 ) ;
V_2 -> V_272 = 1 ;
} else {
V_2 -> V_272 = 0 ;
}
F_145 ( & V_2 -> V_164 ) ;
F_146 ( & V_2 -> V_26 ) ;
F_147 ( & V_2 -> V_270 ) ;
F_148 ( & V_2 -> V_263 ) ;
F_149 ( & V_2 -> V_46 ) ;
F_149 ( & V_2 -> V_244 ) ;
V_2 -> V_9 = V_256 ;
memset ( V_2 -> V_50 , 0 , sizeof( V_2 -> V_50 ) ) ;
return V_2 ;
}
void F_150 ( struct V_1 * V_2 , bool V_273 )
{
V_2 -> V_273 = V_273 ;
}
static void F_151 ( struct V_11 * V_241 , unsigned V_274 )
{
if ( V_241 ) {
struct V_11 * V_12 = V_241 ;
while ( V_274 -- ) {
F_152 ( V_12 -> V_47 ) ;
++ V_12 ;
}
F_152 ( V_241 ) ;
}
}
int F_153 ( struct V_1 * V_2 , unsigned int V_274 )
{
struct V_11 * V_12 , * V_241 ;
int V_49 ;
V_241 = F_154 ( V_274 , sizeof( * V_241 ) , V_73 ) ;
if ( ! V_241 )
return - V_236 ;
V_12 = V_241 ;
V_49 = V_274 ;
goto V_275;
do {
V_12 -> V_109 = V_12 + 1 ;
++ V_12 ;
V_275:
V_12 -> V_47 = F_155 ( V_97 , V_73 ) ;
if ( F_40 ( ! V_12 -> V_47 ) )
goto V_276;
} while ( -- V_49 );
V_12 -> V_109 = V_241 ;
F_151 ( V_2 -> V_241 , V_2 -> V_240 ) ;
V_2 -> V_240 = V_274 ;
V_2 -> V_241 = V_241 ;
return 0 ;
V_276:
F_151 ( V_241 , V_274 ) ;
return - V_236 ;
}
void F_156 ( struct V_79 * V_193 )
{
if ( F_157 ( & V_193 -> V_265 ) )
F_158 ( & V_193 -> V_265 ) ;
F_74 ( V_193 ) ;
F_152 ( V_193 ) ;
}
static void F_159 ( struct V_1 * V_2 , int V_274 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_274 ; ++ V_49 )
if ( V_2 -> V_50 [ V_49 ] ) {
F_156 ( V_2 -> V_50 [ V_49 ] ) ;
V_2 -> V_50 [ V_49 ] = NULL ;
}
}
void F_160 ( struct V_1 * V_2 )
{
F_159 ( V_2 , F_24 ( V_2 -> V_50 ) ) ;
}
void F_161 ( struct V_1 * V_2 ,
const struct V_277 * V_261 )
{
V_2 -> V_261 = V_261 ;
}
void F_162 ( struct V_1 * V_2 )
{
F_151 ( V_2 -> V_241 , V_2 -> V_240 ) ;
V_2 -> V_241 = NULL ;
}
int F_163 ( struct V_1 * V_2 ,
struct V_278 * V_255 , bool V_172 )
{
struct V_279 * V_280 ;
V_2 -> V_245 = V_255 -> V_245 ;
V_2 -> V_33 = V_255 -> V_245 -> V_33 ;
V_2 -> V_34 = V_255 -> V_39 ;
V_2 -> V_255 = V_255 ;
V_280 = F_164 ( V_255 , V_281 ,
F_24 ( V_282 ) ) ;
if ( F_165 ( V_280 ) )
return F_166 ( V_280 ) ;
V_283 . V_284 = V_280 [ V_285 ] . V_286 ;
V_2 -> V_172 = V_172 &&
F_167 ( V_2 -> V_245 ) ;
return 0 ;
}
static T_6 F_168 ( struct V_287 * V_288 ,
struct V_289 * V_267 , int V_290 )
{
struct V_264 * V_265 = F_169 ( V_288 ) ;
struct V_79 * V_193 = F_124 ( V_265 ) ;
if ( V_267 == & V_291 . V_267 )
return V_193 -> V_134 ? V_292 : ( V_293 | V_292 ) ;
if ( V_267 == & V_294 . V_267 )
return V_193 -> V_137 ? ( V_293 | V_292 ) : V_292 ;
return V_267 -> V_295 ;
}
int F_170 ( struct V_1 * V_2 , struct V_296 * V_297 ,
unsigned int V_286 , const char * V_20 ,
const char * * V_298 )
{
struct V_79 * V_193 ;
char * V_299 , * V_300 ;
int V_32 = - V_236 ;
if ( V_286 >= F_24 ( V_2 -> V_50 ) )
return - V_301 ;
if ( V_2 -> V_50 [ V_286 ] )
return - V_302 ;
if ( ! V_297 -> V_303 && ! V_297 -> V_137 ) {
F_171 ( L_65 , V_286 ) ;
return - V_91 ;
}
V_193 = F_143 ( sizeof( * V_193 ) , V_73 ) ;
if ( ! V_193 )
return - V_236 ;
V_193 -> V_298 = V_298 ;
V_193 -> V_134 = ! ! V_297 -> V_134 ;
V_193 -> V_115 = V_297 -> V_134 || V_297 -> V_115 ;
V_193 -> V_304 = V_193 -> V_115 ;
V_193 -> V_137 = ! ! V_297 -> V_137 ;
if ( ! V_2 -> V_273 ) {
V_193 -> V_20 = V_20 ;
} else {
V_193 -> V_265 . V_305 = F_137 ;
V_193 -> V_265 . V_306 = & V_2 -> V_245 -> V_265 ;
V_193 -> V_265 . V_307 = V_308 ;
F_172 ( & V_193 -> V_265 , & V_2 -> V_164 ) ;
F_173 ( & V_193 -> V_265 , L_66 , V_20 ) ;
V_193 -> V_20 = F_174 ( & V_193 -> V_265 ) ;
V_32 = F_175 ( & V_193 -> V_265 ) ;
if ( V_32 ) {
F_176 ( L_67 , V_286 , V_32 ) ;
F_177 ( & V_193 -> V_265 ) ;
goto V_309;
}
}
V_2 -> V_50 [ V_286 ] = V_193 ;
if ( V_297 -> V_303 ) {
V_32 = F_178 ( V_193 , V_297 -> V_303 ) ;
if ( V_32 )
goto V_310;
}
V_299 = F_155 ( V_311 , V_73 ) ;
V_300 = L_68 ;
if ( F_71 ( V_193 ) ) {
V_300 = L_69 ;
if ( V_299 ) {
V_300 = F_179 ( V_193 -> V_102 , V_299 , V_311 ) ;
if ( F_165 ( V_300 ) )
V_300 = L_69 ;
}
}
F_176 ( L_70 ,
V_193 -> V_137 ? L_71 : L_72 ,
V_193 -> V_115 ? L_73 : L_72 ,
V_193 -> V_134 ? L_74 : L_72 ,
V_300 ) ;
F_152 ( V_299 ) ;
return 0 ;
V_310:
if ( F_157 ( & V_193 -> V_265 ) )
F_158 ( & V_193 -> V_265 ) ;
F_74 ( V_193 ) ;
V_2 -> V_50 [ V_286 ] = NULL ;
V_309:
F_152 ( V_193 ) ;
return V_32 ;
}
int F_180 ( struct V_1 * V_2 , struct V_312 * V_297 )
{
char V_47 [ 8 ] ;
int V_49 , V_32 ;
F_160 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_297 -> V_313 ; ++ V_49 ) {
snprintf ( V_47 , sizeof( V_47 ) , L_75 , V_49 ) ;
V_32 = F_170 ( V_2 , & V_297 -> V_50 [ V_49 ] , V_49 , V_47 , NULL ) ;
if ( V_32 )
goto V_314;
}
F_176 ( L_76 , V_297 -> V_313 ) ;
return 0 ;
V_314:
F_159 ( V_2 , V_49 ) ;
return V_32 ;
}
void F_181 ( struct V_1 * V_2 , const char * V_315 ,
const char * V_316 )
{
int V_49 ;
V_49 = F_182 () ;
snprintf ( V_2 -> V_138 , sizeof( V_2 -> V_138 ) ,
L_77 , V_315 ? : L_78 ,
V_316 ? : ( ( * V_2 -> V_50 ) -> V_134
? L_79
: L_80 ) ,
V_49 ) ;
}
static void V_271 ( struct V_317 * V_270 )
{
struct V_1 * V_2 = F_4 ( V_270 , struct V_1 , V_270 ) ;
int V_49 ;
if ( V_2 -> V_9 != V_256 ) {
F_10 ( V_2 , V_254 ) ;
F_183 ( & V_2 -> V_263 ) ;
}
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; ++ V_49 ) {
struct V_79 * V_193 = V_2 -> V_50 [ V_49 ] ;
if ( ! V_193 )
continue;
F_74 ( V_193 ) ;
if ( F_157 ( & V_193 -> V_265 ) )
F_158 ( & V_193 -> V_265 ) ;
F_152 ( V_193 ) ;
}
F_151 ( V_2 -> V_241 , V_2 -> V_240 ) ;
if ( V_2 -> V_272 )
F_152 ( V_2 ) ;
}
static int F_184 ( struct V_318 * V_319 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_320 * V_245 = V_319 -> V_255 -> V_245 ;
int V_49 ;
struct V_18 * V_19 ;
unsigned V_321 ;
int V_322 ;
struct V_323 * V_324 ;
V_322 = F_23 ( V_2 ) ;
if ( V_322 < 0 ) {
F_171 ( L_81 ) ;
return - V_91 ;
}
V_324 = F_185 ( V_7 -> V_325 ) ;
if ( ! V_324 -> V_326 ) {
V_322 = F_163 ( V_4 -> V_2 , V_319 -> V_255 ,
V_4 -> V_2 -> V_172 ) ;
if ( V_322 )
return V_322 ;
F_181 ( V_4 -> V_2 , NULL , NULL ) ;
}
if ( ! V_2 -> V_29 ) {
V_2 -> V_9 = V_10 ;
V_2 -> V_29 =
F_186 ( F_117 , V_2 , L_82 ) ;
if ( F_165 ( V_2 -> V_29 ) ) {
V_322 = F_166 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
V_2 -> V_9 = V_256 ;
return V_322 ;
}
F_8 ( V_2 , L_83 ,
F_187 ( V_2 -> V_29 ) ) ;
F_188 ( V_2 -> V_29 ) ;
}
V_4 -> V_245 = V_245 ;
V_49 = F_189 ( V_319 , V_7 ) ;
if ( V_49 < 0 )
goto V_314;
V_283 . V_327 = V_49 ;
V_4 -> V_67 = V_49 ;
V_19 = F_190 ( V_245 , & V_328 ) ;
if ( ! V_19 )
goto V_329;
V_4 -> V_21 = V_19 ;
V_19 = F_190 ( V_245 , & V_330 ) ;
if ( ! V_19 )
goto V_329;
V_4 -> V_22 = V_19 ;
V_331 . V_332 =
V_328 . V_332 ;
V_333 . V_332 =
V_330 . V_332 ;
V_321 = F_191 ( unsigned , V_97 / 1024 , 15 ) ;
V_334 . V_332 =
V_328 . V_332 ;
V_335 . V_336 = V_321 ;
V_337 . V_332 =
V_330 . V_332 ;
V_338 . V_336 = V_321 ;
V_322 = F_192 ( V_7 , V_339 , V_340 ,
V_341 , V_341 ) ;
if ( V_322 )
goto V_329;
return 0 ;
V_329:
ERROR ( V_4 , L_84 ) ;
V_49 = - V_342 ;
V_314:
if ( V_4 -> V_2 -> V_9 != V_256 ) {
F_10 ( V_4 -> V_2 , V_254 ) ;
F_183 ( & V_4 -> V_2 -> V_263 ) ;
}
return V_49 ;
}
static void F_193 ( struct V_318 * V_319 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_8 ( V_4 , L_85 ) ;
if ( V_4 -> V_2 -> V_4 == V_4 ) {
V_4 -> V_2 -> V_237 = NULL ;
F_10 ( V_4 -> V_2 , V_251 ) ;
F_194 ( V_2 -> V_244 , V_2 -> V_4 != V_4 ) ;
}
F_195 ( & V_4 -> V_8 ) ;
}
static inline struct V_343 * F_196 ( struct V_344 * V_345 )
{
return F_4 ( F_197 ( V_345 ) , struct V_343 , V_346 ) ;
}
static inline struct V_323 * F_198 ( struct V_344 * V_345 )
{
return F_4 ( F_197 ( V_345 ) , struct V_323 ,
V_347 . V_346 ) ;
}
static void F_199 ( struct V_344 * V_345 )
{
struct V_343 * V_348 ;
V_348 = F_196 ( V_345 ) ;
F_152 ( V_348 ) ;
}
static T_4 F_200 ( struct V_344 * V_345 , char * V_349 )
{
struct V_343 * V_324 = F_196 ( V_345 ) ;
struct V_323 * V_323 = F_198 ( V_324 -> V_346 . V_350 . V_351 ) ;
return F_130 ( V_324 -> V_193 , & V_323 -> V_2 -> V_164 , V_349 ) ;
}
static T_4 F_201 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
struct V_343 * V_324 = F_196 ( V_345 ) ;
struct V_323 * V_323 = F_198 ( V_324 -> V_346 . V_350 . V_351 ) ;
return F_136 ( V_324 -> V_193 , & V_323 -> V_2 -> V_164 , V_349 , V_154 ) ;
}
static T_4 F_202 ( struct V_344 * V_345 , char * V_349 )
{
return F_125 ( F_196 ( V_345 ) -> V_193 , V_349 ) ;
}
static T_4 F_203 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
struct V_343 * V_324 = F_196 ( V_345 ) ;
struct V_323 * V_323 = F_198 ( V_324 -> V_346 . V_350 . V_351 ) ;
return F_132 ( V_324 -> V_193 , & V_323 -> V_2 -> V_164 , V_349 , V_154 ) ;
}
static T_4 F_204 ( struct V_344 * V_345 ,
char * V_349 )
{
return F_205 ( F_196 ( V_345 ) -> V_193 , V_349 ) ;
}
static T_4 F_206 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
return F_207 ( F_196 ( V_345 ) -> V_193 , V_349 , V_154 ) ;
}
static T_4 F_208 ( struct V_344 * V_345 , char * V_349 )
{
return F_209 ( F_196 ( V_345 ) -> V_193 , V_349 ) ;
}
static T_4 F_210 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
struct V_343 * V_324 = F_196 ( V_345 ) ;
struct V_323 * V_323 = F_198 ( V_324 -> V_346 . V_350 . V_351 ) ;
return F_211 ( V_324 -> V_193 , & V_323 -> V_2 -> V_164 , V_349 ,
V_154 ) ;
}
static T_4 F_212 ( struct V_344 * V_345 , char * V_349 )
{
return F_127 ( F_196 ( V_345 ) -> V_193 , V_349 ) ;
}
static T_4 F_213 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
return F_134 ( F_196 ( V_345 ) -> V_193 , V_349 , V_154 ) ;
}
static T_4 F_214 ( struct V_344 * V_345 ,
char * V_349 )
{
return F_215 ( F_196 ( V_345 ) -> V_193 , V_349 ) ;
}
static T_4 F_216 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
return F_217 ( F_196 ( V_345 ) -> V_193 , V_349 , V_154 ) ;
}
static struct V_352 * F_218 ( struct V_352 * V_346 ,
const char * V_20 )
{
struct V_343 * V_324 ;
struct V_323 * V_323 ;
struct V_296 V_353 ;
char * V_354 ;
V_60 V_355 ;
int V_322 ;
V_354 = strchr ( V_20 , '.' ) ;
if ( ! V_354 ) {
F_171 ( L_86 ) ;
return F_144 ( - V_91 ) ;
}
V_354 ++ ;
V_322 = F_219 ( V_354 , 0 , & V_355 ) ;
if ( V_322 )
return F_144 ( V_322 ) ;
V_323 = F_198 ( & V_346 -> V_350 ) ;
if ( V_355 >= V_356 )
return F_144 ( - V_357 ) ;
F_220 ( & V_323 -> V_26 ) ;
if ( V_323 -> V_358 || V_323 -> V_2 -> V_50 [ V_355 ] ) {
V_322 = - V_302 ;
goto V_359;
}
V_324 = F_143 ( sizeof( * V_324 ) , V_73 ) ;
if ( ! V_324 ) {
V_322 = - V_236 ;
goto V_359;
}
memset ( & V_353 , 0 , sizeof( V_353 ) ) ;
V_353 . V_137 = true ;
V_322 = F_170 ( V_323 -> V_2 , & V_353 , V_355 , V_20 ,
( const char * * ) & V_346 -> V_350 . V_360 ) ;
if ( V_322 ) {
F_152 ( V_324 ) ;
goto V_359;
}
V_324 -> V_193 = V_323 -> V_2 -> V_50 [ V_355 ] ;
V_324 -> V_361 = V_355 ;
F_221 ( & V_323 -> V_26 ) ;
F_222 ( & V_324 -> V_346 , V_20 , & V_362 ) ;
return & V_324 -> V_346 ;
V_359:
F_221 ( & V_323 -> V_26 ) ;
return F_144 ( V_322 ) ;
}
static void F_223 ( struct V_352 * V_346 , struct V_344 * V_345 )
{
struct V_343 * V_348 ;
struct V_323 * V_323 ;
V_348 = F_196 ( V_345 ) ;
V_323 = F_198 ( & V_346 -> V_350 ) ;
F_220 ( & V_323 -> V_26 ) ;
if ( V_323 -> V_358 ) {
struct V_344 * V_245 ;
V_245 = V_346 -> V_350 . V_351 -> V_351 ;
F_224 ( V_245 ) ;
}
F_156 ( V_348 -> V_193 ) ;
V_323 -> V_2 -> V_50 [ V_348 -> V_361 ] = NULL ;
V_348 -> V_361 = 0 ;
F_221 ( & V_323 -> V_26 ) ;
F_225 ( V_345 ) ;
}
static void F_226 ( struct V_344 * V_345 )
{
struct V_323 * V_324 = F_198 ( V_345 ) ;
F_227 ( & V_324 -> V_347 ) ;
}
static T_4 F_228 ( struct V_344 * V_345 , char * V_349 )
{
struct V_323 * V_324 = F_198 ( V_345 ) ;
int V_363 ;
F_220 ( & V_324 -> V_26 ) ;
V_363 = sprintf ( V_349 , L_87 , V_324 -> V_2 -> V_172 ) ;
F_221 ( & V_324 -> V_26 ) ;
return V_363 ;
}
static T_4 F_229 ( struct V_344 * V_345 , const char * V_349 ,
T_5 V_154 )
{
struct V_323 * V_324 = F_198 ( V_345 ) ;
int V_322 ;
bool V_364 ;
F_220 ( & V_324 -> V_26 ) ;
if ( V_324 -> V_358 ) {
F_221 ( & V_324 -> V_26 ) ;
return - V_302 ;
}
V_322 = F_230 ( V_349 , & V_364 ) ;
if ( ! V_322 ) {
V_324 -> V_2 -> V_172 = V_364 ;
V_322 = V_154 ;
}
F_221 ( & V_324 -> V_26 ) ;
return V_322 ;
}
static T_4 F_231 ( struct V_344 * V_345 , char * V_349 )
{
struct V_323 * V_324 = F_198 ( V_345 ) ;
int V_363 ;
F_220 ( & V_324 -> V_26 ) ;
V_363 = sprintf ( V_349 , L_87 , V_324 -> V_2 -> V_240 ) ;
F_221 ( & V_324 -> V_26 ) ;
return V_363 ;
}
static T_4 F_232 ( struct V_344 * V_345 ,
const char * V_349 , T_5 V_154 )
{
struct V_323 * V_324 = F_198 ( V_345 ) ;
int V_322 ;
V_60 V_355 ;
F_220 ( & V_324 -> V_26 ) ;
if ( V_324 -> V_358 ) {
V_322 = - V_302 ;
goto V_365;
}
V_322 = F_219 ( V_349 , 0 , & V_355 ) ;
if ( V_322 )
goto V_365;
F_153 ( V_324 -> V_2 , V_355 ) ;
V_322 = V_154 ;
V_365:
F_221 ( & V_324 -> V_26 ) ;
return V_322 ;
}
static void F_233 ( struct V_366 * V_325 )
{
struct V_323 * V_324 ;
V_324 = F_185 ( V_325 ) ;
F_140 ( V_324 -> V_2 ) ;
F_152 ( V_324 ) ;
}
static struct V_366 * F_234 ( void )
{
struct V_323 * V_324 ;
struct V_296 V_353 ;
int V_32 ;
V_324 = F_143 ( sizeof( * V_324 ) , V_73 ) ;
if ( ! V_324 )
return F_144 ( - V_236 ) ;
F_235 ( & V_324 -> V_26 ) ;
V_324 -> V_347 . V_367 = F_233 ;
V_324 -> V_2 = F_142 ( V_324 -> V_2 ) ;
if ( F_165 ( V_324 -> V_2 ) ) {
V_32 = F_166 ( V_324 -> V_2 ) ;
goto V_368;
}
V_32 = F_153 ( V_324 -> V_2 ,
V_369 ) ;
if ( V_32 )
goto V_368;
F_176 ( V_370 L_88 V_371 L_89 ) ;
memset ( & V_353 , 0 , sizeof( V_353 ) ) ;
V_353 . V_137 = true ;
V_32 = F_170 ( V_324 -> V_2 , & V_353 , 0 , L_90 ,
( const char * * ) & V_324 -> V_347 . V_346 . V_350 . V_360 ) ;
if ( V_32 )
goto V_372;
V_324 -> V_373 . V_193 = V_324 -> V_2 -> V_50 [ 0 ] ;
V_324 -> V_373 . V_361 = 0 ;
F_222 ( & V_324 -> V_347 . V_346 , L_72 , & V_374 ) ;
F_222 ( & V_324 -> V_373 . V_346 , L_90 , & V_362 ) ;
F_236 ( & V_324 -> V_373 . V_346 , & V_324 -> V_347 . V_346 ) ;
return & V_324 -> V_347 ;
V_372:
F_162 ( V_324 -> V_2 ) ;
V_368:
F_152 ( V_324 ) ;
return F_144 ( V_32 ) ;
}
static void F_237 ( struct V_6 * V_7 )
{
struct V_5 * V_4 ;
struct V_323 * V_324 ;
V_4 = F_4 ( V_7 , struct V_5 , V_8 ) ;
V_324 = F_4 ( V_7 -> V_325 , struct V_323 , V_347 ) ;
F_220 ( & V_324 -> V_26 ) ;
V_324 -> V_358 -- ;
F_221 ( & V_324 -> V_26 ) ;
F_152 ( V_4 ) ;
}
static struct V_6 * F_238 ( struct V_366 * V_325 )
{
struct V_323 * V_324 = F_185 ( V_325 ) ;
struct V_1 * V_2 = V_324 -> V_2 ;
struct V_5 * V_4 ;
V_4 = F_143 ( sizeof( * V_4 ) , V_73 ) ;
if ( F_40 ( ! V_4 ) )
return F_144 ( - V_236 ) ;
F_220 ( & V_324 -> V_26 ) ;
V_324 -> V_358 ++ ;
F_221 ( & V_324 -> V_26 ) ;
V_4 -> V_8 . V_20 = V_370 ;
V_4 -> V_8 . V_375 = F_184 ;
V_4 -> V_8 . V_376 = F_193 ;
V_4 -> V_8 . V_377 = F_25 ;
V_4 -> V_8 . V_378 = F_106 ;
V_4 -> V_8 . V_379 = F_107 ;
V_4 -> V_8 . V_380 = F_237 ;
V_4 -> V_2 = V_2 ;
return & V_4 -> V_8 ;
}
void F_239 ( struct V_312 * V_297 ,
const struct V_381 * V_382 ,
unsigned int V_240 )
{
struct V_296 * V_193 ;
unsigned V_49 ;
V_297 -> V_313 =
F_29 ( V_382 -> V_50 ? : ( V_382 -> V_383 ? : 1u ) ,
( unsigned ) V_356 ) ;
for ( V_49 = 0 , V_193 = V_297 -> V_50 ; V_49 < V_297 -> V_313 ; ++ V_49 , ++ V_193 ) {
V_193 -> V_115 = ! ! V_382 -> V_115 [ V_49 ] ;
V_193 -> V_134 = ! ! V_382 -> V_134 [ V_49 ] ;
V_193 -> V_137 = ! ! V_382 -> V_137 [ V_49 ] ;
V_193 -> V_303 =
V_382 -> V_383 > V_49 && V_382 -> V_128 [ V_49 ] [ 0 ]
? V_382 -> V_128 [ V_49 ]
: NULL ;
}
V_297 -> V_384 = NULL ;
V_297 -> V_385 = NULL ;
V_297 -> V_261 = NULL ;
V_297 -> V_386 = NULL ;
V_297 -> V_172 = V_382 -> V_364 ;
V_297 -> V_240 = V_240 ;
}
