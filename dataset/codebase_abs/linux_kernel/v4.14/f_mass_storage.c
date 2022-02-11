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
V_86 = F_41 ( V_80 -> V_102 , V_12 -> V_47 , V_85 ,
& V_84 ) ;
F_42 ( V_80 , L_11 , V_85 ,
( unsigned long long ) V_83 , ( int ) V_86 ) ;
if ( F_43 ( V_103 ) )
return - V_78 ;
if ( V_86 < 0 ) {
F_44 ( V_80 , L_12 , ( int ) V_86 ) ;
V_86 = 0 ;
} else if ( V_86 < V_85 ) {
F_44 ( V_80 , L_13 ,
( int ) V_86 , V_85 ) ;
V_86 = F_45 ( V_86 , V_80 -> V_104 ) ;
}
V_83 += V_86 ;
V_82 -= V_86 ;
V_2 -> V_105 -= V_86 ;
V_12 -> V_75 -> V_13 = V_86 ;
V_12 -> V_9 = V_48 ;
if ( V_86 < V_85 ) {
V_80 -> V_89 = V_106 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
if ( V_82 == 0 )
break;
V_12 -> V_75 -> V_107 = 0 ;
if ( ! F_31 ( V_2 , V_12 ) )
return - V_96 ;
V_2 -> V_99 = V_12 -> V_108 ;
}
return - V_96 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 ;
struct V_11 * V_12 ;
int V_109 ;
T_2 V_110 , V_111 ;
T_3 V_112 , V_83 , V_84 ;
unsigned int V_85 ;
T_4 V_113 ;
int V_32 ;
if ( V_80 -> V_114 ) {
V_80 -> V_89 = V_115 ;
return - V_91 ;
}
F_47 ( & V_80 -> V_102 -> V_116 ) ;
V_80 -> V_102 -> V_117 &= ~ V_118 ;
F_48 ( & V_80 -> V_102 -> V_116 ) ;
if ( V_2 -> V_87 [ 0 ] == V_119 )
V_81 = F_38 ( & V_2 -> V_87 [ 1 ] ) ;
else {
V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
if ( V_2 -> V_87 [ 1 ] & ~ 0x18 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( ! V_80 -> V_120 && ( V_2 -> V_87 [ 1 ] & 0x08 ) ) {
F_47 ( & V_80 -> V_102 -> V_116 ) ;
V_80 -> V_102 -> V_117 |= V_118 ;
F_48 ( & V_80 -> V_102 -> V_116 ) ;
}
}
if ( V_81 >= V_80 -> V_92 ) {
V_80 -> V_89 = V_93 ;
return - V_91 ;
}
V_109 = 1 ;
V_83 = V_112 = ( ( T_3 ) V_81 ) << V_80 -> V_94 ;
V_110 = V_2 -> V_95 ;
V_111 = V_2 -> V_95 ;
while ( V_111 > 0 ) {
V_12 = V_2 -> V_99 ;
if ( V_12 -> V_9 == V_45 && V_109 ) {
V_85 = F_29 ( V_110 , V_97 ) ;
if ( V_112 >= V_80 -> V_98 ) {
V_109 = 0 ;
V_80 -> V_89 =
V_93 ;
V_80 -> V_100 =
V_112 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
continue;
}
V_112 += V_85 ;
V_2 -> V_121 -= V_85 ;
V_110 -= V_85 ;
if ( V_110 == 0 )
V_109 = 0 ;
F_6 ( V_2 , V_12 , V_85 ) ;
if ( ! F_32 ( V_2 , V_12 ) )
return - V_96 ;
V_2 -> V_99 = V_12 -> V_108 ;
continue;
}
V_12 = V_2 -> V_122 ;
if ( V_12 -> V_9 == V_45 && ! V_109 )
break;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_122 = V_12 -> V_108 ;
V_12 -> V_9 = V_45 ;
if ( V_12 -> V_17 -> V_41 != 0 ) {
V_80 -> V_89 = V_123 ;
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
V_85 = F_45 ( V_85 , V_80 -> V_104 ) ;
if ( V_85 == 0 )
goto V_124;
V_84 = V_83 ;
V_113 = F_50 ( V_80 -> V_102 , V_12 -> V_47 , V_85 ,
& V_84 ) ;
F_42 ( V_80 , L_15 , V_85 ,
( unsigned long long ) V_83 , ( int ) V_113 ) ;
if ( F_43 ( V_103 ) )
return - V_78 ;
if ( V_113 < 0 ) {
F_44 ( V_80 , L_16 ,
( int ) V_113 ) ;
V_113 = 0 ;
} else if ( V_113 < V_85 ) {
F_44 ( V_80 , L_17 ,
( int ) V_113 , V_85 ) ;
V_113 = F_45 ( V_113 , V_80 -> V_104 ) ;
}
V_83 += V_113 ;
V_111 -= V_113 ;
V_2 -> V_105 -= V_113 ;
if ( V_113 < V_85 ) {
V_80 -> V_89 = V_125 ;
V_80 -> V_100 =
V_83 >> V_80 -> V_94 ;
V_80 -> V_101 = 1 ;
break;
}
V_124:
if ( V_12 -> V_17 -> V_42 < V_12 -> V_15 ) {
V_2 -> V_126 = 1 ;
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
V_80 -> V_89 = V_125 ;
return 0 ;
}
static void F_53 ( struct V_79 * V_80 )
{
struct V_127 * V_102 = V_80 -> V_102 ;
struct V_128 * V_128 = F_54 ( V_102 ) ;
unsigned long V_32 ;
V_32 = F_55 ( V_128 -> V_129 , 0 , - 1 ) ;
F_42 ( V_80 , L_18 , V_32 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 ;
T_2 V_130 ;
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
V_130 = F_57 ( & V_2 -> V_87 [ 7 ] ) ;
if ( F_40 ( V_130 == 0 ) )
return - V_96 ;
V_82 = V_130 << V_80 -> V_94 ;
V_83 = ( ( T_3 ) V_81 ) << V_80 -> V_94 ;
F_52 ( V_80 ) ;
if ( F_43 ( V_103 ) )
return - V_78 ;
F_53 ( V_80 ) ;
if ( F_43 ( V_103 ) )
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
V_86 = F_41 ( V_80 -> V_102 , V_12 -> V_47 , V_85 ,
& V_84 ) ;
F_42 ( V_80 , L_11 , V_85 ,
( unsigned long long ) V_83 ,
( int ) V_86 ) ;
if ( F_43 ( V_103 ) )
return - V_78 ;
if ( V_86 < 0 ) {
F_44 ( V_80 , L_19 , ( int ) V_86 ) ;
V_86 = 0 ;
} else if ( V_86 < V_85 ) {
F_44 ( V_80 , L_20 ,
( int ) V_86 , V_85 ) ;
V_86 = F_45 ( V_86 , V_80 -> V_104 ) ;
}
if ( V_86 == 0 ) {
V_80 -> V_89 = V_106 ;
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
V_2 -> V_131 = 1 ;
memset ( V_47 , 0 , 36 ) ;
V_47 [ 0 ] = V_132 ;
V_47 [ 4 ] = 31 ;
return 36 ;
}
V_47 [ 0 ] = V_80 -> V_133 ? V_134 : V_135 ;
V_47 [ 1 ] = V_80 -> V_136 ? 0x80 : 0 ;
V_47 [ 2 ] = 2 ;
V_47 [ 3 ] = 2 ;
V_47 [ 4 ] = 31 ;
V_47 [ 5 ] = 0 ;
V_47 [ 6 ] = 0 ;
V_47 [ 7 ] = 0 ;
if ( V_80 -> V_137 [ 0 ] )
memcpy ( V_47 + 8 , V_80 -> V_137 ,
sizeof( V_80 -> V_137 ) ) ;
else
memcpy ( V_47 + 8 , V_2 -> V_137 ,
sizeof( V_2 -> V_137 ) ) ;
return 36 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
T_2 V_138 , V_139 ;
int V_140 ;
#if 0
if (curlun && curlun->unit_attention_data != SS_NO_SENSE) {
curlun->sense_data = curlun->unit_attention_data;
curlun->unit_attention_data = SS_NO_SENSE;
}
#endif
if ( ! V_80 ) {
V_2 -> V_131 = 1 ;
V_138 = V_141 ;
V_139 = 0 ;
V_140 = 0 ;
} else {
V_138 = V_80 -> V_89 ;
V_139 = V_80 -> V_100 ;
V_140 = V_80 -> V_101 << 7 ;
V_80 -> V_89 = V_142 ;
V_80 -> V_100 = 0 ;
V_80 -> V_101 = 0 ;
}
memset ( V_47 , 0 , 18 ) ;
V_47 [ 0 ] = V_140 | 0x70 ;
V_47 [ 2 ] = F_60 ( V_138 ) ;
F_61 ( V_139 , & V_47 [ 3 ] ) ;
V_47 [ 7 ] = 18 - 8 ;
V_47 [ 12 ] = F_62 ( V_138 ) ;
V_47 [ 13 ] = F_63 ( V_138 ) ;
return 18 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_2 V_81 = F_39 ( & V_2 -> V_87 [ 2 ] ) ;
int V_143 = V_2 -> V_87 [ 8 ] ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
if ( V_143 > 1 || ( V_143 == 0 && V_81 != 0 ) ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
F_61 ( V_80 -> V_92 - 1 , & V_47 [ 0 ] ) ;
F_61 ( V_80 -> V_104 , & V_47 [ 4 ] ) ;
return 8 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_144 = V_2 -> V_87 [ 1 ] & 0x02 ;
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
F_66 ( & V_47 [ 4 ] , V_144 , V_81 ) ;
return 8 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_144 = V_2 -> V_87 [ 1 ] & 0x02 ;
int V_145 = V_2 -> V_87 [ 6 ] ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
if ( ( V_2 -> V_87 [ 1 ] & ~ 0x02 ) != 0 ||
V_145 > 1 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
memset ( V_47 , 0 , 20 ) ;
V_47 [ 1 ] = ( 20 - 2 ) ;
V_47 [ 2 ] = 1 ;
V_47 [ 3 ] = 1 ;
V_47 [ 5 ] = 0x16 ;
V_47 [ 6 ] = 0x01 ;
F_66 ( & V_47 [ 8 ] , V_144 , 0 ) ;
V_47 [ 13 ] = 0x16 ;
V_47 [ 14 ] = 0xAA ;
F_66 ( & V_47 [ 16 ] , V_144 , V_80 -> V_92 ) ;
return 20 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_146 = V_2 -> V_87 [ 0 ] ;
V_60 * V_47 = ( V_60 * ) V_12 -> V_47 ;
V_60 * V_147 = V_47 ;
int V_148 , V_149 ;
int V_150 , V_151 ;
int V_152 = 0 ;
int V_153 , V_154 ;
if ( ( V_2 -> V_87 [ 1 ] & ~ 0x08 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
V_148 = V_2 -> V_87 [ 2 ] >> 6 ;
V_149 = V_2 -> V_87 [ 2 ] & 0x3f ;
if ( V_148 == 3 ) {
V_80 -> V_89 = V_155 ;
return - V_91 ;
}
V_150 = ( V_148 == 1 ) ;
V_151 = ( V_149 == 0x3f ) ;
memset ( V_47 , 0 , 8 ) ;
if ( V_146 == V_156 ) {
V_47 [ 2 ] = ( V_80 -> V_114 ? 0x80 : 0x00 ) ;
V_47 += 4 ;
V_154 = 255 ;
} else {
V_47 [ 3 ] = ( V_80 -> V_114 ? 0x80 : 0x00 ) ;
V_47 += 8 ;
V_154 = 65535 ;
}
if ( V_149 == 0x08 || V_151 ) {
V_152 = 1 ;
V_47 [ 0 ] = 0x08 ;
V_47 [ 1 ] = 10 ;
memset ( V_47 + 2 , 0 , 10 ) ;
if ( ! V_150 ) {
V_47 [ 2 ] = 0x04 ;
F_69 ( 0xffff , & V_47 [ 4 ] ) ;
F_69 ( 0xffff , & V_47 [ 8 ] ) ;
F_69 ( 0xffff , & V_47 [ 10 ] ) ;
}
V_47 += 12 ;
}
V_153 = V_47 - V_147 ;
if ( ! V_152 || V_153 > V_154 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( V_146 == V_156 )
V_147 [ 0 ] = V_153 - 1 ;
else
F_69 ( V_153 - 2 , V_147 ) ;
return V_153 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_157 , V_158 ;
if ( ! V_80 ) {
return - V_91 ;
} else if ( ! V_80 -> V_136 ) {
V_80 -> V_89 = V_159 ;
return - V_91 ;
} else if ( ( V_2 -> V_87 [ 1 ] & ~ 0x01 ) != 0 ||
( V_2 -> V_87 [ 4 ] & ~ 0x03 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
V_157 = V_2 -> V_87 [ 4 ] & 0x02 ;
V_158 = V_2 -> V_87 [ 4 ] & 0x01 ;
if ( V_158 ) {
if ( ! F_71 ( V_80 ) ) {
V_80 -> V_89 = V_160 ;
return - V_91 ;
}
return 0 ;
}
if ( V_80 -> V_161 ) {
F_44 ( V_80 , L_21 ) ;
V_80 -> V_89 = V_162 ;
return - V_91 ;
}
if ( ! V_157 )
return 0 ;
F_72 ( & V_2 -> V_163 ) ;
F_73 ( & V_2 -> V_163 ) ;
F_74 ( V_80 ) ;
F_75 ( & V_2 -> V_163 ) ;
F_76 ( & V_2 -> V_163 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
int V_164 ;
if ( ! V_2 -> V_80 ) {
return - V_91 ;
} else if ( ! V_2 -> V_80 -> V_136 ) {
V_2 -> V_80 -> V_89 = V_159 ;
return - V_91 ;
}
V_164 = V_2 -> V_87 [ 4 ] & 0x01 ;
if ( ( V_2 -> V_87 [ 4 ] & ~ 0x01 ) != 0 ) {
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
if ( V_80 -> V_161 && ! V_164 )
F_52 ( V_80 ) ;
V_80 -> V_161 = V_164 ;
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
F_61 ( V_80 -> V_104 , & V_47 [ 4 ] ) ;
V_47 [ 4 ] = 0x02 ;
return 12 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
if ( V_80 )
V_80 -> V_89 = V_159 ;
return - V_91 ;
}
static int F_80 ( struct V_5 * V_4 )
{
int V_32 ;
V_32 = F_7 ( V_4 , V_4 -> V_21 ) ;
if ( V_32 == - V_165 )
F_28 ( V_4 , L_22 ) ;
while ( V_32 != 0 ) {
if ( V_32 != - V_165 ) {
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
if ( V_32 == - V_165 )
F_28 ( V_4 , L_25 ) ;
while ( V_32 != 0 ) {
if ( V_32 != - V_165 ) {
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
struct V_11 * V_12 , * V_166 ;
T_2 V_85 ;
int V_32 ;
for ( V_12 = V_2 -> V_122 ;
V_12 -> V_9 != V_45 || V_2 -> V_121 > 0 ;
V_12 = V_2 -> V_122 ) {
V_166 = V_2 -> V_99 ;
if ( V_166 -> V_9 == V_45 &&
V_2 -> V_121 > 0 ) {
V_85 = F_29 ( V_2 -> V_121 , V_97 ) ;
F_6 ( V_2 , V_166 , V_85 ) ;
if ( ! F_32 ( V_2 , V_166 ) )
return - V_96 ;
V_2 -> V_99 = V_166 -> V_108 ;
V_2 -> V_121 -= V_85 ;
continue;
}
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
V_12 -> V_9 = V_45 ;
V_2 -> V_122 = V_12 -> V_108 ;
if ( V_12 -> V_17 -> V_42 < V_12 -> V_15 ||
V_12 -> V_17 -> V_41 != 0 ) {
F_10 ( V_2 , V_167 ) ;
return - V_78 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_99 ;
int V_32 = 0 ;
switch ( V_2 -> V_168 ) {
case V_169 :
break;
case V_170 :
if ( ! V_2 -> V_171 ) {
} else if ( F_27 ( V_2 ) ) {
F_7 ( V_2 -> V_4 , V_2 -> V_4 -> V_22 ) ;
V_32 = F_80 ( V_2 -> V_4 ) ;
} else {
V_32 = - V_96 ;
}
break;
case V_172 :
if ( V_2 -> V_173 == 0 ) {
} else if ( ! F_27 ( V_2 ) ) {
V_32 = - V_96 ;
} else if ( V_2 -> V_105 == 0 ) {
V_12 -> V_75 -> V_107 = 0 ;
if ( ! F_31 ( V_2 , V_12 ) )
return - V_96 ;
V_2 -> V_99 = V_12 -> V_108 ;
} else {
V_12 -> V_75 -> V_107 = 1 ;
if ( ! F_31 ( V_2 , V_12 ) )
V_32 = - V_96 ;
V_2 -> V_99 = V_12 -> V_108 ;
if ( V_2 -> V_171 )
V_32 = F_80 ( V_2 -> V_4 ) ;
}
break;
case V_174 :
if ( V_2 -> V_105 == 0 ) {
} else if ( V_2 -> V_126 ) {
F_10 ( V_2 , V_167 ) ;
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
struct V_175 * V_176 ;
int V_32 ;
V_60 V_41 = V_177 ;
T_2 V_138 , V_139 = 0 ;
V_12 = V_2 -> V_99 ;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return;
if ( V_80 ) {
V_138 = V_80 -> V_89 ;
V_139 = V_80 -> V_100 ;
} else if ( V_2 -> V_131 )
V_138 = V_142 ;
else
V_138 = V_141 ;
if ( V_2 -> V_178 ) {
F_8 ( V_2 , L_27 ) ;
V_41 = V_179 ;
V_138 = V_159 ;
} else if ( V_138 != V_142 ) {
F_8 ( V_2 , L_28 ) ;
V_41 = V_180 ;
F_28 ( V_2 , L_29
L_30 ,
F_60 ( V_138 ) , F_62 ( V_138 ) , F_63 ( V_138 ) , V_139 ) ;
}
V_176 = ( void * ) V_12 -> V_47 ;
V_176 -> V_181 = F_87 ( V_182 ) ;
V_176 -> V_183 = V_2 -> V_184 ;
V_176 -> V_185 = F_87 ( V_2 -> V_105 ) ;
V_176 -> V_186 = V_41 ;
V_12 -> V_75 -> V_13 = V_187 ;
V_12 -> V_75 -> V_107 = 0 ;
if ( ! F_31 ( V_2 , V_12 ) )
return;
V_2 -> V_99 = V_12 -> V_108 ;
return;
}
static int F_88 ( struct V_1 * V_2 , int V_188 ,
enum V_189 V_168 , unsigned int V_190 ,
int V_191 , const char * V_20 )
{
int V_49 ;
unsigned int V_192 = V_2 -> V_87 [ 1 ] >> 5 ;
static const char V_193 [ 4 ] = { 'u' , 'o' , 'i' , 'n' } ;
char V_194 [ 20 ] ;
struct V_79 * V_80 ;
V_194 [ 0 ] = 0 ;
if ( V_2 -> V_168 != V_170 )
sprintf ( V_194 , L_31 , V_193 [ ( int ) V_2 -> V_168 ] ,
V_2 -> V_173 ) ;
F_28 ( V_2 , L_32 ,
V_20 , V_188 , V_193 [ ( int ) V_168 ] ,
V_2 -> V_95 , V_2 -> V_188 , V_194 ) ;
if ( V_2 -> V_95 == 0 )
V_168 = V_169 ;
if ( V_2 -> V_173 < V_2 -> V_95 ) {
V_2 -> V_95 = V_2 -> V_173 ;
V_2 -> V_178 = 1 ;
}
V_2 -> V_105 = V_2 -> V_173 ;
V_2 -> V_121 = V_2 -> V_173 ;
if ( V_2 -> V_168 != V_168 && V_2 -> V_95 > 0 ) {
V_2 -> V_178 = 1 ;
return - V_91 ;
}
if ( V_188 != V_2 -> V_188 ) {
if ( V_188 <= V_2 -> V_188 ) {
F_8 ( V_2 , L_33
L_34 , V_20 ,
V_188 , V_2 -> V_188 ) ;
V_188 = V_2 -> V_188 ;
} else {
V_2 -> V_178 = 1 ;
return - V_91 ;
}
}
if ( V_2 -> V_192 != V_192 )
F_8 ( V_2 , L_35 ,
V_2 -> V_192 , V_192 ) ;
V_80 = V_2 -> V_80 ;
if ( V_80 ) {
if ( V_2 -> V_87 [ 0 ] != V_195 ) {
V_80 -> V_89 = V_142 ;
V_80 -> V_100 = 0 ;
V_80 -> V_101 = 0 ;
}
} else {
V_2 -> V_131 = 0 ;
if ( V_2 -> V_87 [ 0 ] != V_196 &&
V_2 -> V_87 [ 0 ] != V_195 ) {
F_8 ( V_2 , L_36 , V_2 -> V_192 ) ;
return - V_91 ;
}
}
if ( V_80 && V_80 -> V_197 != V_142 &&
V_2 -> V_87 [ 0 ] != V_196 &&
V_2 -> V_87 [ 0 ] != V_195 ) {
V_80 -> V_89 = V_80 -> V_197 ;
V_80 -> V_197 = V_142 ;
return - V_91 ;
}
V_2 -> V_87 [ 1 ] &= 0x1f ;
for ( V_49 = 1 ; V_49 < V_188 ; ++ V_49 ) {
if ( V_2 -> V_87 [ V_49 ] && ! ( V_190 & ( 1 << V_49 ) ) ) {
if ( V_80 )
V_80 -> V_89 = V_90 ;
return - V_91 ;
}
}
if ( V_80 && ! F_71 ( V_80 ) && V_191 ) {
V_80 -> V_89 = V_160 ;
return - V_91 ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
int V_188 , enum V_189 V_168 ,
unsigned int V_190 , int V_191 , const char * V_20 )
{
if ( V_2 -> V_80 )
V_2 -> V_95 <<= V_2 -> V_80 -> V_94 ;
return F_88 ( V_2 , V_188 , V_168 ,
V_190 , V_191 , V_20 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_32 ;
int V_198 = - V_91 ;
int V_49 ;
static char V_199 [ 16 ] ;
F_91 ( V_2 ) ;
V_12 = V_2 -> V_99 ;
V_2 -> V_122 = V_12 ;
V_32 = F_33 ( V_2 , false , V_12 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_178 = 0 ;
V_2 -> V_126 = 0 ;
F_76 ( & V_2 -> V_163 ) ;
switch ( V_2 -> V_87 [ 0 ] ) {
case V_196 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_198 = F_88 ( V_2 , 6 , V_172 ,
( 1 << 4 ) , 0 ,
L_37 ) ;
if ( V_198 == 0 )
V_198 = F_58 ( V_2 , V_12 ) ;
break;
case V_200 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_198 = F_88 ( V_2 , 6 , V_174 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_38 ) ;
if ( V_198 == 0 )
V_198 = F_79 ( V_2 , V_12 ) ;
break;
case V_201 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_88 ( V_2 , 10 , V_174 ,
( 1 << 1 ) | ( 3 << 7 ) , 0 ,
L_39 ) ;
if ( V_198 == 0 )
V_198 = F_79 ( V_2 , V_12 ) ;
break;
case V_156 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_198 = F_88 ( V_2 , 6 , V_172 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 1 << 4 ) , 0 ,
L_40 ) ;
if ( V_198 == 0 )
V_198 = F_68 ( V_2 , V_12 ) ;
break;
case V_202 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_88 ( V_2 , 10 , V_172 ,
( 1 << 1 ) | ( 1 << 2 ) | ( 3 << 7 ) , 0 ,
L_41 ) ;
if ( V_198 == 0 )
V_198 = F_68 ( V_2 , V_12 ) ;
break;
case V_203 :
V_2 -> V_95 = 0 ;
V_198 = F_88 ( V_2 , 6 , V_169 ,
( 1 << 4 ) , 0 ,
L_42 ) ;
if ( V_198 == 0 )
V_198 = F_77 ( V_2 ) ;
break;
case V_88 :
V_49 = V_2 -> V_87 [ 4 ] ;
V_2 -> V_95 = ( V_49 == 0 ) ? 256 : V_49 ;
V_198 = F_89 ( V_2 , 6 ,
V_172 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_43 ) ;
if ( V_198 == 0 )
V_198 = F_37 ( V_2 ) ;
break;
case V_204 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_89 ( V_2 , 10 ,
V_172 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_44 ) ;
if ( V_198 == 0 )
V_198 = F_37 ( V_2 ) ;
break;
case V_205 :
V_2 -> V_95 =
F_39 ( & V_2 -> V_87 [ 6 ] ) ;
V_198 = F_89 ( V_2 , 12 ,
V_172 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_45 ) ;
if ( V_198 == 0 )
V_198 = F_37 ( V_2 ) ;
break;
case V_206 :
V_2 -> V_95 = 8 ;
V_198 = F_88 ( V_2 , 10 , V_172 ,
( 0xf << 2 ) | ( 1 << 8 ) , 1 ,
L_46 ) ;
if ( V_198 == 0 )
V_198 = F_64 ( V_2 , V_12 ) ;
break;
case V_207 :
if ( ! V_2 -> V_80 || ! V_2 -> V_80 -> V_133 )
goto V_208;
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_88 ( V_2 , 10 , V_172 ,
( 3 << 7 ) | ( 0x1f << 1 ) , 1 ,
L_47 ) ;
if ( V_198 == 0 )
V_198 = F_65 ( V_2 , V_12 ) ;
break;
case V_209 :
if ( ! V_2 -> V_80 || ! V_2 -> V_80 -> V_133 )
goto V_208;
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_88 ( V_2 , 10 , V_172 ,
( 7 << 6 ) | ( 1 << 1 ) , 1 ,
L_48 ) ;
if ( V_198 == 0 )
V_198 = F_67 ( V_2 , V_12 ) ;
break;
case V_210 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_88 ( V_2 , 10 , V_172 ,
( 3 << 7 ) , 1 ,
L_49 ) ;
if ( V_198 == 0 )
V_198 = F_78 ( V_2 , V_12 ) ;
break;
case V_195 :
V_2 -> V_95 = V_2 -> V_87 [ 4 ] ;
V_198 = F_88 ( V_2 , 6 , V_172 ,
( 1 << 4 ) , 0 ,
L_50 ) ;
if ( V_198 == 0 )
V_198 = F_59 ( V_2 , V_12 ) ;
break;
case V_211 :
V_2 -> V_95 = 0 ;
V_198 = F_88 ( V_2 , 6 , V_169 ,
( 1 << 1 ) | ( 1 << 4 ) , 0 ,
L_51 ) ;
if ( V_198 == 0 )
V_198 = F_70 ( V_2 ) ;
break;
case V_212 :
V_2 -> V_95 = 0 ;
V_198 = F_88 ( V_2 , 10 , V_169 ,
( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_52 ) ;
if ( V_198 == 0 )
V_198 = F_51 ( V_2 ) ;
break;
case V_213 :
V_2 -> V_95 = 0 ;
V_198 = F_88 ( V_2 , 6 , V_169 ,
0 , 1 ,
L_53 ) ;
break;
case V_214 :
V_2 -> V_95 = 0 ;
V_198 = F_88 ( V_2 , 10 , V_169 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_54 ) ;
if ( V_198 == 0 )
V_198 = F_56 ( V_2 ) ;
break;
case V_119 :
V_49 = V_2 -> V_87 [ 4 ] ;
V_2 -> V_95 = ( V_49 == 0 ) ? 256 : V_49 ;
V_198 = F_89 ( V_2 , 6 ,
V_174 ,
( 7 << 1 ) | ( 1 << 4 ) , 1 ,
L_55 ) ;
if ( V_198 == 0 )
V_198 = F_46 ( V_2 ) ;
break;
case V_215 :
V_2 -> V_95 =
F_57 ( & V_2 -> V_87 [ 7 ] ) ;
V_198 = F_89 ( V_2 , 10 ,
V_174 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 3 << 7 ) , 1 ,
L_56 ) ;
if ( V_198 == 0 )
V_198 = F_46 ( V_2 ) ;
break;
case V_216 :
V_2 -> V_95 =
F_39 ( & V_2 -> V_87 [ 6 ] ) ;
V_198 = F_89 ( V_2 , 12 ,
V_174 ,
( 1 << 1 ) | ( 0xf << 2 ) | ( 0xf << 6 ) , 1 ,
L_57 ) ;
if ( V_198 == 0 )
V_198 = F_46 ( V_2 ) ;
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
default:
V_208:
V_2 -> V_95 = 0 ;
sprintf ( V_199 , L_58 , V_2 -> V_87 [ 0 ] ) ;
V_198 = F_88 ( V_2 , V_2 -> V_188 ,
V_170 , ~ 0 , 0 , V_199 ) ;
if ( V_198 == 0 ) {
V_2 -> V_80 -> V_89 = V_159 ;
V_198 = - V_91 ;
}
break;
}
F_72 ( & V_2 -> V_163 ) ;
if ( V_198 == - V_78 || F_43 ( V_103 ) )
return - V_78 ;
if ( V_198 == - V_91 )
V_198 = 0 ;
if ( V_198 >= 0 && V_2 -> V_168 == V_172 ) {
V_198 = F_29 ( ( T_2 ) V_198 , V_2 -> V_95 ) ;
V_12 -> V_75 -> V_13 = V_198 ;
V_12 -> V_9 = V_48 ;
V_2 -> V_105 -= V_198 ;
}
return 0 ;
}
static int F_92 ( struct V_5 * V_4 , struct V_11 * V_12 )
{
struct V_38 * V_39 = V_12 -> V_17 ;
struct V_221 * V_222 = V_39 -> V_47 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_39 -> V_41 || F_93 ( V_223 , & V_4 -> V_224 ) )
return - V_91 ;
if ( V_39 -> V_42 != V_225 ||
V_222 -> V_181 != F_87 (
V_226 ) ) {
F_8 ( V_4 , L_59 ,
V_39 -> V_42 ,
F_94 ( V_222 -> V_181 ) ) ;
F_82 ( V_4 ) ;
F_95 ( V_223 , & V_4 -> V_224 ) ;
return - V_91 ;
}
if ( V_222 -> V_227 >= F_24 ( V_2 -> V_50 ) ||
V_222 -> V_228 & ~ V_229 || V_222 -> V_230 <= 0 ||
V_222 -> V_230 > V_231 ) {
F_8 ( V_4 , L_60
L_61 ,
V_222 -> V_227 , V_222 -> V_228 , V_222 -> V_230 ) ;
if ( V_2 -> V_171 ) {
F_7 ( V_4 , V_4 -> V_22 ) ;
F_80 ( V_4 ) ;
}
return - V_91 ;
}
V_2 -> V_188 = V_222 -> V_230 ;
memcpy ( V_2 -> V_87 , V_222 -> V_232 , V_2 -> V_188 ) ;
if ( V_222 -> V_228 & V_229 )
V_2 -> V_168 = V_172 ;
else
V_2 -> V_168 = V_174 ;
V_2 -> V_173 = F_94 ( V_222 -> V_233 ) ;
if ( V_2 -> V_173 == 0 )
V_2 -> V_168 = V_169 ;
V_2 -> V_192 = V_222 -> V_227 ;
if ( V_2 -> V_192 < F_24 ( V_2 -> V_50 ) )
V_2 -> V_80 = V_2 -> V_50 [ V_2 -> V_192 ] ;
else
V_2 -> V_80 = NULL ;
V_2 -> V_184 = V_222 -> V_183 ;
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
F_6 ( V_2 , V_12 , V_225 ) ;
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
struct V_38 * * V_234 )
{
* V_234 = F_98 ( V_19 , V_35 ) ;
if ( * V_234 )
return 0 ;
ERROR ( V_2 , L_62 , V_19 -> V_20 ) ;
return - V_235 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_5 * V_236 )
{
struct V_5 * V_4 ;
int V_49 , V_32 = 0 ;
if ( V_2 -> V_237 )
F_8 ( V_2 , L_63 ) ;
V_238:
if ( V_2 -> V_4 ) {
V_4 = V_2 -> V_4 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_239 ; ++ V_49 ) {
struct V_11 * V_12 = & V_2 -> V_240 [ V_49 ] ;
if ( V_12 -> V_75 ) {
F_100 ( V_4 -> V_21 , V_12 -> V_75 ) ;
V_12 -> V_75 = NULL ;
}
if ( V_12 -> V_17 ) {
F_100 ( V_4 -> V_22 , V_12 -> V_17 ) ;
V_12 -> V_17 = NULL ;
}
}
if ( V_4 -> V_241 ) {
F_101 ( V_4 -> V_21 ) ;
V_4 -> V_241 = 0 ;
}
if ( V_4 -> V_242 ) {
F_101 ( V_4 -> V_22 ) ;
V_4 -> V_242 = 0 ;
}
V_2 -> V_4 = NULL ;
F_20 ( & V_2 -> V_243 ) ;
}
V_2 -> V_237 = 0 ;
if ( ! V_236 || V_32 )
return V_32 ;
V_2 -> V_4 = V_236 ;
V_4 = V_2 -> V_4 ;
V_32 = F_102 ( V_2 -> V_244 , & ( V_4 -> V_8 ) , V_4 -> V_21 ) ;
if ( V_32 )
goto V_238;
V_32 = F_103 ( V_4 -> V_21 ) ;
if ( V_32 )
goto V_238;
V_4 -> V_21 -> V_36 = V_2 ;
V_4 -> V_241 = 1 ;
V_32 = F_102 ( V_2 -> V_244 , & ( V_4 -> V_8 ) ,
V_4 -> V_22 ) ;
if ( V_32 )
goto V_238;
V_32 = F_103 ( V_4 -> V_22 ) ;
if ( V_32 )
goto V_238;
V_4 -> V_22 -> V_36 = V_2 ;
V_4 -> V_242 = 1 ;
V_2 -> V_16 = F_104 ( V_4 -> V_22 -> V_245 ) ;
F_105 ( V_223 , & V_4 -> V_224 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_239 ; ++ V_49 ) {
struct V_11 * V_12 = & V_2 -> V_240 [ V_49 ] ;
V_32 = F_97 ( V_2 , V_4 -> V_21 , & V_12 -> V_75 ) ;
if ( V_32 )
goto V_238;
V_32 = F_97 ( V_2 , V_4 -> V_22 , & V_12 -> V_17 ) ;
if ( V_32 )
goto V_238;
V_12 -> V_75 -> V_47 = V_12 -> V_17 -> V_47 = V_12 -> V_47 ;
V_12 -> V_75 -> V_40 = V_12 -> V_17 -> V_40 = V_12 ;
V_12 -> V_75 -> V_246 = F_17 ;
V_12 -> V_17 -> V_246 = F_21 ;
}
V_2 -> V_237 = 1 ;
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; ++ V_49 )
if ( V_2 -> V_50 [ V_49 ] )
V_2 -> V_50 [ V_49 ] -> V_197 =
V_247 ;
return V_32 ;
}
static int F_106 ( struct V_6 * V_7 , unsigned V_248 , unsigned V_249 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_236 = V_4 ;
F_10 ( V_4 -> V_2 , V_250 ) ;
return V_70 ;
}
static void F_107 ( struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
V_4 -> V_2 -> V_236 = NULL ;
F_10 ( V_4 -> V_2 , V_250 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_49 ;
struct V_11 * V_12 ;
enum V_23 V_251 ;
struct V_79 * V_80 ;
unsigned int V_27 ;
for (; ; ) {
int V_252 = F_109 ( NULL ) ;
if ( ! V_252 )
break;
if ( V_252 != V_30 ) {
F_110 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_9 < V_253 )
F_8 ( V_2 , L_64 ) ;
V_2 -> V_9 = V_253 ;
F_111 ( & V_2 -> V_26 ) ;
}
}
if ( F_112 ( V_2 -> V_4 ) ) {
for ( V_49 = 0 ; V_49 < V_2 -> V_239 ; ++ V_49 ) {
V_12 = & V_2 -> V_240 [ V_49 ] ;
if ( V_12 -> V_9 == V_74 )
F_113 ( V_2 -> V_4 -> V_21 , V_12 -> V_75 ) ;
if ( V_12 -> V_9 == V_76 )
F_113 ( V_2 -> V_4 -> V_22 ,
V_12 -> V_17 ) ;
if ( F_33 ( V_2 , false , V_12 ) )
return;
}
if ( V_2 -> V_4 -> V_241 )
F_18 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_4 -> V_242 )
F_18 ( V_2 -> V_4 -> V_22 ) ;
}
F_110 ( & V_2 -> V_26 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_239 ; ++ V_49 ) {
V_12 = & V_2 -> V_240 [ V_49 ] ;
V_12 -> V_9 = V_45 ;
}
V_2 -> V_99 = & V_2 -> V_240 [ 0 ] ;
V_2 -> V_122 = & V_2 -> V_240 [ 0 ] ;
V_27 = V_2 -> V_27 ;
V_251 = V_2 -> V_9 ;
V_2 -> V_9 = V_10 ;
if ( V_251 != V_167 ) {
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; ++ V_49 ) {
V_80 = V_2 -> V_50 [ V_49 ] ;
if ( ! V_80 )
continue;
V_80 -> V_161 = 0 ;
V_80 -> V_89 = V_142 ;
V_80 -> V_197 = V_142 ;
V_80 -> V_100 = 0 ;
V_80 -> V_101 = 0 ;
}
}
F_111 ( & V_2 -> V_26 ) ;
switch ( V_251 ) {
case V_10 :
break;
case V_167 :
F_86 ( V_2 ) ;
break;
case V_69 :
if ( ! F_27 ( V_2 ) )
break;
if ( F_114 ( V_223 ,
& V_2 -> V_4 -> V_224 ) )
F_115 ( V_2 -> V_4 -> V_21 ) ;
if ( V_2 -> V_28 == V_27 )
F_14 ( V_2 ) ;
break;
case V_250 :
F_99 ( V_2 , V_2 -> V_236 ) ;
if ( V_2 -> V_236 )
F_116 ( V_2 -> V_254 ) ;
break;
case V_253 :
F_99 ( V_2 , NULL ) ;
F_110 ( & V_2 -> V_26 ) ;
V_2 -> V_9 = V_255 ;
F_111 ( & V_2 -> V_26 ) ;
break;
case V_255 :
break;
}
}
static int F_117 ( void * V_256 )
{
struct V_1 * V_2 = V_256 ;
int V_49 ;
F_118 ( V_257 ) ;
F_118 ( V_258 ) ;
F_118 ( V_259 ) ;
F_118 ( V_30 ) ;
F_119 () ;
while ( V_2 -> V_9 != V_255 ) {
if ( F_5 ( V_2 ) || F_43 ( V_103 ) ) {
F_108 ( V_2 ) ;
continue;
}
if ( ! V_2 -> V_237 ) {
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
F_73 ( & V_2 -> V_163 ) ;
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; V_49 ++ ) {
struct V_79 * V_80 = V_2 -> V_50 [ V_49 ] ;
if ( V_80 && F_71 ( V_80 ) )
F_74 ( V_80 ) ;
}
F_75 ( & V_2 -> V_163 ) ;
F_120 ( & V_2 -> V_260 , 0 ) ;
}
static T_4 F_121 ( struct V_261 * V_262 , struct V_263 * V_264 , char * V_47 )
{
struct V_79 * V_80 = F_122 ( V_262 ) ;
return F_123 ( V_80 , V_47 ) ;
}
static T_4 F_124 ( struct V_261 * V_262 , struct V_263 * V_264 ,
char * V_47 )
{
struct V_79 * V_80 = F_122 ( V_262 ) ;
return F_125 ( V_80 , V_47 ) ;
}
static T_4 F_126 ( struct V_261 * V_262 , struct V_263 * V_264 ,
char * V_47 )
{
struct V_79 * V_80 = F_122 ( V_262 ) ;
struct V_265 * V_163 = F_127 ( V_262 ) ;
return F_128 ( V_80 , V_163 , V_47 ) ;
}
static T_4 F_129 ( struct V_261 * V_262 , struct V_263 * V_264 ,
const char * V_47 , T_5 V_266 )
{
struct V_79 * V_80 = F_122 ( V_262 ) ;
struct V_265 * V_163 = F_127 ( V_262 ) ;
return F_130 ( V_80 , V_163 , V_47 , V_266 ) ;
}
static T_4 F_131 ( struct V_261 * V_262 , struct V_263 * V_264 ,
const char * V_47 , T_5 V_266 )
{
struct V_79 * V_80 = F_122 ( V_262 ) ;
return F_132 ( V_80 , V_47 , V_266 ) ;
}
static T_4 F_133 ( struct V_261 * V_262 , struct V_263 * V_264 ,
const char * V_47 , T_5 V_266 )
{
struct V_79 * V_80 = F_122 ( V_262 ) ;
struct V_265 * V_163 = F_127 ( V_262 ) ;
return F_134 ( V_80 , V_163 , V_47 , V_266 ) ;
}
static void F_135 ( struct V_261 * V_262 )
{
}
void F_136 ( struct V_1 * V_2 )
{
F_137 ( & V_2 -> V_267 ) ;
}
void F_138 ( struct V_1 * V_2 )
{
F_139 ( & V_2 -> V_267 , V_268 ) ;
}
static struct V_1 * F_140 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
V_2 = F_141 ( sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return F_142 ( - V_235 ) ;
V_2 -> V_269 = 1 ;
} else {
V_2 -> V_269 = 0 ;
}
F_143 ( & V_2 -> V_163 ) ;
F_144 ( & V_2 -> V_26 ) ;
F_145 ( & V_2 -> V_267 ) ;
F_146 ( & V_2 -> V_260 ) ;
F_147 ( & V_2 -> V_46 ) ;
F_147 ( & V_2 -> V_243 ) ;
V_2 -> V_9 = V_255 ;
memset ( V_2 -> V_50 , 0 , sizeof( V_2 -> V_50 ) ) ;
return V_2 ;
}
void F_148 ( struct V_1 * V_2 , bool V_270 )
{
V_2 -> V_270 = V_270 ;
}
static void F_149 ( struct V_11 * V_240 , unsigned V_271 )
{
if ( V_240 ) {
struct V_11 * V_12 = V_240 ;
while ( V_271 -- ) {
F_150 ( V_12 -> V_47 ) ;
++ V_12 ;
}
F_150 ( V_240 ) ;
}
}
int F_151 ( struct V_1 * V_2 , unsigned int V_271 )
{
struct V_11 * V_12 , * V_240 ;
int V_49 ;
V_240 = F_152 ( V_271 , sizeof( * V_240 ) , V_73 ) ;
if ( ! V_240 )
return - V_235 ;
V_12 = V_240 ;
V_49 = V_271 ;
goto V_272;
do {
V_12 -> V_108 = V_12 + 1 ;
++ V_12 ;
V_272:
V_12 -> V_47 = F_153 ( V_97 , V_73 ) ;
if ( F_40 ( ! V_12 -> V_47 ) )
goto V_273;
} while ( -- V_49 );
V_12 -> V_108 = V_240 ;
F_149 ( V_2 -> V_240 , V_2 -> V_239 ) ;
V_2 -> V_239 = V_271 ;
V_2 -> V_240 = V_240 ;
return 0 ;
V_273:
F_149 ( V_240 , V_271 ) ;
return - V_235 ;
}
void F_154 ( struct V_79 * V_192 )
{
if ( F_155 ( & V_192 -> V_262 ) )
F_156 ( & V_192 -> V_262 ) ;
F_74 ( V_192 ) ;
F_150 ( V_192 ) ;
}
static void F_157 ( struct V_1 * V_2 , int V_271 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_271 ; ++ V_49 )
if ( V_2 -> V_50 [ V_49 ] ) {
F_154 ( V_2 -> V_50 [ V_49 ] ) ;
V_2 -> V_50 [ V_49 ] = NULL ;
}
}
void F_158 ( struct V_1 * V_2 )
{
F_157 ( V_2 , F_24 ( V_2 -> V_50 ) ) ;
}
void F_159 ( struct V_1 * V_2 )
{
F_149 ( V_2 -> V_240 , V_2 -> V_239 ) ;
V_2 -> V_240 = NULL ;
}
int F_160 ( struct V_1 * V_2 ,
struct V_274 * V_254 , bool V_171 )
{
struct V_275 * V_276 ;
V_2 -> V_244 = V_254 -> V_244 ;
V_2 -> V_33 = V_254 -> V_244 -> V_33 ;
V_2 -> V_34 = V_254 -> V_39 ;
V_2 -> V_254 = V_254 ;
V_276 = F_161 ( V_254 , V_277 ,
F_24 ( V_278 ) ) ;
if ( F_162 ( V_276 ) )
return F_163 ( V_276 ) ;
V_279 . V_280 = V_276 [ V_281 ] . V_282 ;
V_2 -> V_171 = V_171 &&
F_164 ( V_2 -> V_244 ) ;
return 0 ;
}
static T_6 F_165 ( struct V_283 * V_284 ,
struct V_285 * V_264 , int V_286 )
{
struct V_261 * V_262 = F_166 ( V_284 ) ;
struct V_79 * V_192 = F_122 ( V_262 ) ;
if ( V_264 == & V_287 . V_264 )
return V_192 -> V_133 ? V_288 : ( V_289 | V_288 ) ;
if ( V_264 == & V_290 . V_264 )
return V_192 -> V_136 ? ( V_289 | V_288 ) : V_288 ;
return V_264 -> V_291 ;
}
int F_167 ( struct V_1 * V_2 , struct V_292 * V_293 ,
unsigned int V_282 , const char * V_20 ,
const char * * V_294 )
{
struct V_79 * V_192 ;
char * V_295 , * V_296 ;
int V_32 = - V_235 ;
if ( V_282 >= F_24 ( V_2 -> V_50 ) )
return - V_297 ;
if ( V_2 -> V_50 [ V_282 ] )
return - V_298 ;
if ( ! V_293 -> V_299 && ! V_293 -> V_136 ) {
F_168 ( L_65 , V_282 ) ;
return - V_91 ;
}
V_192 = F_141 ( sizeof( * V_192 ) , V_73 ) ;
if ( ! V_192 )
return - V_235 ;
V_192 -> V_294 = V_294 ;
V_192 -> V_133 = ! ! V_293 -> V_133 ;
V_192 -> V_114 = V_293 -> V_133 || V_293 -> V_114 ;
V_192 -> V_300 = V_192 -> V_114 ;
V_192 -> V_136 = ! ! V_293 -> V_136 ;
if ( ! V_2 -> V_270 ) {
V_192 -> V_20 = V_20 ;
} else {
V_192 -> V_262 . V_301 = F_135 ;
V_192 -> V_262 . V_302 = & V_2 -> V_244 -> V_262 ;
V_192 -> V_262 . V_303 = V_304 ;
F_169 ( & V_192 -> V_262 , & V_2 -> V_163 ) ;
F_170 ( & V_192 -> V_262 , L_66 , V_20 ) ;
V_192 -> V_20 = F_171 ( & V_192 -> V_262 ) ;
V_32 = F_172 ( & V_192 -> V_262 ) ;
if ( V_32 ) {
F_173 ( L_67 , V_282 , V_32 ) ;
F_174 ( & V_192 -> V_262 ) ;
goto V_305;
}
}
V_2 -> V_50 [ V_282 ] = V_192 ;
if ( V_293 -> V_299 ) {
V_32 = F_175 ( V_192 , V_293 -> V_299 ) ;
if ( V_32 )
goto V_306;
}
V_295 = F_153 ( V_307 , V_73 ) ;
V_296 = L_68 ;
if ( F_71 ( V_192 ) ) {
V_296 = L_69 ;
if ( V_295 ) {
V_296 = F_176 ( V_192 -> V_102 , V_295 , V_307 ) ;
if ( F_162 ( V_296 ) )
V_296 = L_69 ;
}
}
F_173 ( L_70 ,
V_192 -> V_136 ? L_71 : L_72 ,
V_192 -> V_114 ? L_73 : L_72 ,
V_192 -> V_133 ? L_74 : L_72 ,
V_296 ) ;
F_150 ( V_295 ) ;
return 0 ;
V_306:
if ( F_155 ( & V_192 -> V_262 ) )
F_156 ( & V_192 -> V_262 ) ;
F_74 ( V_192 ) ;
V_2 -> V_50 [ V_282 ] = NULL ;
V_305:
F_150 ( V_192 ) ;
return V_32 ;
}
int F_177 ( struct V_1 * V_2 , struct V_308 * V_293 )
{
char V_47 [ 8 ] ;
int V_49 , V_32 ;
F_158 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < V_293 -> V_309 ; ++ V_49 ) {
snprintf ( V_47 , sizeof( V_47 ) , L_75 , V_49 ) ;
V_32 = F_167 ( V_2 , & V_293 -> V_50 [ V_49 ] , V_49 , V_47 , NULL ) ;
if ( V_32 )
goto V_310;
}
F_173 ( L_76 , V_293 -> V_309 ) ;
return 0 ;
V_310:
F_157 ( V_2 , V_49 ) ;
return V_32 ;
}
void F_178 ( struct V_1 * V_2 , const char * V_311 ,
const char * V_312 )
{
int V_49 ;
V_49 = F_179 () ;
snprintf ( V_2 -> V_137 , sizeof( V_2 -> V_137 ) ,
L_77 , V_311 ? : L_78 ,
V_312 ? : ( ( * V_2 -> V_50 ) -> V_133
? L_79
: L_80 ) ,
V_49 ) ;
}
static void V_268 ( struct V_313 * V_267 )
{
struct V_1 * V_2 = F_4 ( V_267 , struct V_1 , V_267 ) ;
int V_49 ;
if ( V_2 -> V_9 != V_255 ) {
F_10 ( V_2 , V_253 ) ;
F_180 ( & V_2 -> V_260 ) ;
}
for ( V_49 = 0 ; V_49 < F_24 ( V_2 -> V_50 ) ; ++ V_49 ) {
struct V_79 * V_192 = V_2 -> V_50 [ V_49 ] ;
if ( ! V_192 )
continue;
F_74 ( V_192 ) ;
if ( F_155 ( & V_192 -> V_262 ) )
F_156 ( & V_192 -> V_262 ) ;
F_150 ( V_192 ) ;
}
F_149 ( V_2 -> V_240 , V_2 -> V_239 ) ;
if ( V_2 -> V_269 )
F_150 ( V_2 ) ;
}
static int F_181 ( struct V_314 * V_315 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_316 * V_244 = V_315 -> V_254 -> V_244 ;
int V_49 ;
struct V_18 * V_19 ;
unsigned V_317 ;
int V_318 ;
struct V_319 * V_320 ;
V_318 = F_23 ( V_2 ) ;
if ( V_318 < 0 ) {
F_168 ( L_81 ) ;
return - V_91 ;
}
V_320 = F_182 ( V_7 -> V_321 ) ;
if ( ! V_320 -> V_322 ) {
V_318 = F_160 ( V_4 -> V_2 , V_315 -> V_254 ,
V_4 -> V_2 -> V_171 ) ;
if ( V_318 )
return V_318 ;
F_178 ( V_4 -> V_2 , NULL , NULL ) ;
}
if ( ! V_2 -> V_29 ) {
V_2 -> V_9 = V_10 ;
V_2 -> V_29 =
F_183 ( F_117 , V_2 , L_82 ) ;
if ( F_162 ( V_2 -> V_29 ) ) {
V_318 = F_163 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
V_2 -> V_9 = V_255 ;
return V_318 ;
}
F_8 ( V_2 , L_83 ,
F_184 ( V_2 -> V_29 ) ) ;
F_185 ( V_2 -> V_29 ) ;
}
V_4 -> V_244 = V_244 ;
V_49 = F_186 ( V_315 , V_7 ) ;
if ( V_49 < 0 )
goto V_310;
V_279 . V_323 = V_49 ;
V_4 -> V_67 = V_49 ;
V_19 = F_187 ( V_244 , & V_324 ) ;
if ( ! V_19 )
goto V_325;
V_4 -> V_21 = V_19 ;
V_19 = F_187 ( V_244 , & V_326 ) ;
if ( ! V_19 )
goto V_325;
V_4 -> V_22 = V_19 ;
V_327 . V_328 =
V_324 . V_328 ;
V_329 . V_328 =
V_326 . V_328 ;
V_317 = F_188 ( unsigned , V_97 / 1024 , 15 ) ;
V_330 . V_328 =
V_324 . V_328 ;
V_331 . V_332 = V_317 ;
V_333 . V_328 =
V_326 . V_328 ;
V_334 . V_332 = V_317 ;
V_318 = F_189 ( V_7 , V_335 , V_336 ,
V_337 , V_337 ) ;
if ( V_318 )
goto V_325;
return 0 ;
V_325:
ERROR ( V_4 , L_84 ) ;
V_49 = - V_338 ;
V_310:
if ( V_4 -> V_2 -> V_9 != V_255 ) {
F_10 ( V_4 -> V_2 , V_253 ) ;
F_180 ( & V_4 -> V_2 -> V_260 ) ;
}
return V_49 ;
}
static void F_190 ( struct V_314 * V_315 , struct V_6 * V_7 )
{
struct V_5 * V_4 = F_3 ( V_7 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_8 ( V_4 , L_85 ) ;
if ( V_4 -> V_2 -> V_4 == V_4 ) {
V_4 -> V_2 -> V_236 = NULL ;
F_10 ( V_4 -> V_2 , V_250 ) ;
F_191 ( V_2 -> V_243 , V_2 -> V_4 != V_4 ) ;
}
F_192 ( & V_4 -> V_8 ) ;
}
static inline struct V_339 * F_193 ( struct V_340 * V_341 )
{
return F_4 ( F_194 ( V_341 ) , struct V_339 , V_342 ) ;
}
static inline struct V_319 * F_195 ( struct V_340 * V_341 )
{
return F_4 ( F_194 ( V_341 ) , struct V_319 ,
V_343 . V_342 ) ;
}
static void F_196 ( struct V_340 * V_341 )
{
struct V_339 * V_344 ;
V_344 = F_193 ( V_341 ) ;
F_150 ( V_344 ) ;
}
static T_4 F_197 ( struct V_340 * V_341 , char * V_345 )
{
struct V_339 * V_320 = F_193 ( V_341 ) ;
struct V_319 * V_319 = F_195 ( V_320 -> V_342 . V_346 . V_347 ) ;
return F_128 ( V_320 -> V_192 , & V_319 -> V_2 -> V_163 , V_345 ) ;
}
static T_4 F_198 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
struct V_339 * V_320 = F_193 ( V_341 ) ;
struct V_319 * V_319 = F_195 ( V_320 -> V_342 . V_346 . V_347 ) ;
return F_134 ( V_320 -> V_192 , & V_319 -> V_2 -> V_163 , V_345 , V_153 ) ;
}
static T_4 F_199 ( struct V_340 * V_341 , char * V_345 )
{
return F_123 ( F_193 ( V_341 ) -> V_192 , V_345 ) ;
}
static T_4 F_200 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
struct V_339 * V_320 = F_193 ( V_341 ) ;
struct V_319 * V_319 = F_195 ( V_320 -> V_342 . V_346 . V_347 ) ;
return F_130 ( V_320 -> V_192 , & V_319 -> V_2 -> V_163 , V_345 , V_153 ) ;
}
static T_4 F_201 ( struct V_340 * V_341 ,
char * V_345 )
{
return F_202 ( F_193 ( V_341 ) -> V_192 , V_345 ) ;
}
static T_4 F_203 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
return F_204 ( F_193 ( V_341 ) -> V_192 , V_345 , V_153 ) ;
}
static T_4 F_205 ( struct V_340 * V_341 , char * V_345 )
{
return F_206 ( F_193 ( V_341 ) -> V_192 , V_345 ) ;
}
static T_4 F_207 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
struct V_339 * V_320 = F_193 ( V_341 ) ;
struct V_319 * V_319 = F_195 ( V_320 -> V_342 . V_346 . V_347 ) ;
return F_208 ( V_320 -> V_192 , & V_319 -> V_2 -> V_163 , V_345 ,
V_153 ) ;
}
static T_4 F_209 ( struct V_340 * V_341 , char * V_345 )
{
return F_125 ( F_193 ( V_341 ) -> V_192 , V_345 ) ;
}
static T_4 F_210 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
return F_132 ( F_193 ( V_341 ) -> V_192 , V_345 , V_153 ) ;
}
static T_4 F_211 ( struct V_340 * V_341 ,
char * V_345 )
{
return F_212 ( F_193 ( V_341 ) -> V_192 , V_345 ) ;
}
static T_4 F_213 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
return F_214 ( F_193 ( V_341 ) -> V_192 , V_345 , V_153 ) ;
}
static struct V_348 * F_215 ( struct V_348 * V_342 ,
const char * V_20 )
{
struct V_339 * V_320 ;
struct V_319 * V_319 ;
struct V_292 V_349 ;
char * V_350 ;
V_60 V_351 ;
int V_318 ;
V_350 = strchr ( V_20 , '.' ) ;
if ( ! V_350 ) {
F_168 ( L_86 ) ;
return F_142 ( - V_91 ) ;
}
V_350 ++ ;
V_318 = F_216 ( V_350 , 0 , & V_351 ) ;
if ( V_318 )
return F_142 ( V_318 ) ;
V_319 = F_195 ( & V_342 -> V_346 ) ;
if ( V_351 >= V_352 )
return F_142 ( - V_353 ) ;
F_217 ( & V_319 -> V_26 ) ;
if ( V_319 -> V_354 || V_319 -> V_2 -> V_50 [ V_351 ] ) {
V_318 = - V_298 ;
goto V_355;
}
V_320 = F_141 ( sizeof( * V_320 ) , V_73 ) ;
if ( ! V_320 ) {
V_318 = - V_235 ;
goto V_355;
}
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
V_349 . V_136 = true ;
V_318 = F_167 ( V_319 -> V_2 , & V_349 , V_351 , V_20 ,
( const char * * ) & V_342 -> V_346 . V_356 ) ;
if ( V_318 ) {
F_150 ( V_320 ) ;
goto V_355;
}
V_320 -> V_192 = V_319 -> V_2 -> V_50 [ V_351 ] ;
V_320 -> V_357 = V_351 ;
F_218 ( & V_319 -> V_26 ) ;
F_219 ( & V_320 -> V_342 , V_20 , & V_358 ) ;
return & V_320 -> V_342 ;
V_355:
F_218 ( & V_319 -> V_26 ) ;
return F_142 ( V_318 ) ;
}
static void F_220 ( struct V_348 * V_342 , struct V_340 * V_341 )
{
struct V_339 * V_344 ;
struct V_319 * V_319 ;
V_344 = F_193 ( V_341 ) ;
V_319 = F_195 ( & V_342 -> V_346 ) ;
F_217 ( & V_319 -> V_26 ) ;
if ( V_319 -> V_354 ) {
struct V_340 * V_244 ;
V_244 = V_342 -> V_346 . V_347 -> V_347 ;
F_221 ( V_244 ) ;
}
F_154 ( V_344 -> V_192 ) ;
V_319 -> V_2 -> V_50 [ V_344 -> V_357 ] = NULL ;
V_344 -> V_357 = 0 ;
F_218 ( & V_319 -> V_26 ) ;
F_222 ( V_341 ) ;
}
static void F_223 ( struct V_340 * V_341 )
{
struct V_319 * V_320 = F_195 ( V_341 ) ;
F_224 ( & V_320 -> V_343 ) ;
}
static T_4 F_225 ( struct V_340 * V_341 , char * V_345 )
{
struct V_319 * V_320 = F_195 ( V_341 ) ;
int V_359 ;
F_217 ( & V_320 -> V_26 ) ;
V_359 = sprintf ( V_345 , L_87 , V_320 -> V_2 -> V_171 ) ;
F_218 ( & V_320 -> V_26 ) ;
return V_359 ;
}
static T_4 F_226 ( struct V_340 * V_341 , const char * V_345 ,
T_5 V_153 )
{
struct V_319 * V_320 = F_195 ( V_341 ) ;
int V_318 ;
bool V_360 ;
F_217 ( & V_320 -> V_26 ) ;
if ( V_320 -> V_354 ) {
F_218 ( & V_320 -> V_26 ) ;
return - V_298 ;
}
V_318 = F_227 ( V_345 , & V_360 ) ;
if ( ! V_318 ) {
V_320 -> V_2 -> V_171 = V_360 ;
V_318 = V_153 ;
}
F_218 ( & V_320 -> V_26 ) ;
return V_318 ;
}
static T_4 F_228 ( struct V_340 * V_341 , char * V_345 )
{
struct V_319 * V_320 = F_195 ( V_341 ) ;
int V_359 ;
F_217 ( & V_320 -> V_26 ) ;
V_359 = sprintf ( V_345 , L_87 , V_320 -> V_2 -> V_239 ) ;
F_218 ( & V_320 -> V_26 ) ;
return V_359 ;
}
static T_4 F_229 ( struct V_340 * V_341 ,
const char * V_345 , T_5 V_153 )
{
struct V_319 * V_320 = F_195 ( V_341 ) ;
int V_318 ;
V_60 V_351 ;
F_217 ( & V_320 -> V_26 ) ;
if ( V_320 -> V_354 ) {
V_318 = - V_298 ;
goto V_361;
}
V_318 = F_216 ( V_345 , 0 , & V_351 ) ;
if ( V_318 )
goto V_361;
F_151 ( V_320 -> V_2 , V_351 ) ;
V_318 = V_153 ;
V_361:
F_218 ( & V_320 -> V_26 ) ;
return V_318 ;
}
static void F_230 ( struct V_362 * V_321 )
{
struct V_319 * V_320 ;
V_320 = F_182 ( V_321 ) ;
F_138 ( V_320 -> V_2 ) ;
F_150 ( V_320 ) ;
}
static struct V_362 * F_231 ( void )
{
struct V_319 * V_320 ;
struct V_292 V_349 ;
int V_32 ;
V_320 = F_141 ( sizeof( * V_320 ) , V_73 ) ;
if ( ! V_320 )
return F_142 ( - V_235 ) ;
F_232 ( & V_320 -> V_26 ) ;
V_320 -> V_343 . V_363 = F_230 ;
V_320 -> V_2 = F_140 ( V_320 -> V_2 ) ;
if ( F_162 ( V_320 -> V_2 ) ) {
V_32 = F_163 ( V_320 -> V_2 ) ;
goto V_364;
}
V_32 = F_151 ( V_320 -> V_2 ,
V_365 ) ;
if ( V_32 )
goto V_364;
F_173 ( V_366 L_88 V_367 L_89 ) ;
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
V_349 . V_136 = true ;
V_32 = F_167 ( V_320 -> V_2 , & V_349 , 0 , L_90 ,
( const char * * ) & V_320 -> V_343 . V_342 . V_346 . V_356 ) ;
if ( V_32 )
goto V_368;
V_320 -> V_369 . V_192 = V_320 -> V_2 -> V_50 [ 0 ] ;
V_320 -> V_369 . V_357 = 0 ;
F_219 ( & V_320 -> V_343 . V_342 , L_72 , & V_370 ) ;
F_219 ( & V_320 -> V_369 . V_342 , L_90 , & V_358 ) ;
F_233 ( & V_320 -> V_369 . V_342 , & V_320 -> V_343 . V_342 ) ;
return & V_320 -> V_343 ;
V_368:
F_159 ( V_320 -> V_2 ) ;
V_364:
F_150 ( V_320 ) ;
return F_142 ( V_32 ) ;
}
static void F_234 ( struct V_6 * V_7 )
{
struct V_5 * V_4 ;
struct V_319 * V_320 ;
V_4 = F_4 ( V_7 , struct V_5 , V_8 ) ;
V_320 = F_4 ( V_7 -> V_321 , struct V_319 , V_343 ) ;
F_217 ( & V_320 -> V_26 ) ;
V_320 -> V_354 -- ;
F_218 ( & V_320 -> V_26 ) ;
F_150 ( V_4 ) ;
}
static struct V_6 * F_235 ( struct V_362 * V_321 )
{
struct V_319 * V_320 = F_182 ( V_321 ) ;
struct V_1 * V_2 = V_320 -> V_2 ;
struct V_5 * V_4 ;
V_4 = F_141 ( sizeof( * V_4 ) , V_73 ) ;
if ( F_40 ( ! V_4 ) )
return F_142 ( - V_235 ) ;
F_217 ( & V_320 -> V_26 ) ;
V_320 -> V_354 ++ ;
F_218 ( & V_320 -> V_26 ) ;
V_4 -> V_8 . V_20 = V_366 ;
V_4 -> V_8 . V_371 = F_181 ;
V_4 -> V_8 . V_372 = F_190 ;
V_4 -> V_8 . V_373 = F_25 ;
V_4 -> V_8 . V_374 = F_106 ;
V_4 -> V_8 . V_375 = F_107 ;
V_4 -> V_8 . V_376 = F_234 ;
V_4 -> V_2 = V_2 ;
return & V_4 -> V_8 ;
}
void F_236 ( struct V_308 * V_293 ,
const struct V_377 * V_378 ,
unsigned int V_239 )
{
struct V_292 * V_192 ;
unsigned V_49 ;
V_293 -> V_309 =
F_29 ( V_378 -> V_50 ? : ( V_378 -> V_379 ? : 1u ) ,
( unsigned ) V_352 ) ;
for ( V_49 = 0 , V_192 = V_293 -> V_50 ; V_49 < V_293 -> V_309 ; ++ V_49 , ++ V_192 ) {
V_192 -> V_114 = ! ! V_378 -> V_114 [ V_49 ] ;
V_192 -> V_133 = ! ! V_378 -> V_133 [ V_49 ] ;
V_192 -> V_136 = ! ! V_378 -> V_136 [ V_49 ] ;
V_192 -> V_299 =
V_378 -> V_379 > V_49 && V_378 -> V_127 [ V_49 ] [ 0 ]
? V_378 -> V_127 [ V_49 ]
: NULL ;
}
V_293 -> V_380 = NULL ;
V_293 -> V_381 = NULL ;
V_293 -> V_382 = NULL ;
V_293 -> V_383 = NULL ;
V_293 -> V_171 = V_378 -> V_360 ;
V_293 -> V_239 = V_239 ;
}
