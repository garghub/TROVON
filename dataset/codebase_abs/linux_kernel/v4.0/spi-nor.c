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
return 8 ;
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
static inline int F_11 ( struct V_1 * V_2 , struct V_23 * V_24 ,
int V_25 )
{
int V_26 ;
bool V_27 = false ;
T_1 V_28 ;
switch ( F_12 ( V_24 ) ) {
case V_29 :
V_27 = true ;
case V_30 :
case 0xEF :
if ( V_27 )
F_8 ( V_2 ) ;
V_28 = V_25 ? V_31 : V_32 ;
V_26 = V_2 -> V_16 ( V_2 , V_28 , NULL , 0 , 0 ) ;
if ( V_27 )
F_9 ( V_2 ) ;
return V_26 ;
default:
V_2 -> V_15 [ 0 ] = V_25 << 7 ;
return V_2 -> V_16 ( V_2 , V_33 , V_2 -> V_15 , 1 , 0 ) ;
}
}
static inline int F_13 ( struct V_1 * V_2 )
{
int V_34 = F_1 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
else
return ! ( V_34 & V_35 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
int V_36 = F_3 ( V_2 ) ;
if ( V_36 < 0 )
return V_36 ;
else
return V_36 & V_37 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_34 , V_36 ;
V_34 = F_13 ( V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
V_36 = V_2 -> V_38 & V_39 ? F_14 ( V_2 ) : 1 ;
if ( V_36 < 0 )
return V_36 ;
return V_34 && V_36 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
int V_41 = 0 , V_3 ;
V_40 = V_42 + V_43 ;
while ( ! V_41 ) {
if ( F_17 ( V_42 , V_40 ) )
V_41 = 1 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
return 0 ;
F_18 () ;
}
F_5 ( V_2 -> V_9 , L_4 ) ;
return - V_44 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_9 , L_5 , ( long long ) ( V_2 -> V_21 -> V_45 >> 10 ) ) ;
return V_2 -> V_16 ( V_2 , V_46 , NULL , 0 , 0 ) ;
}
static int F_21 ( struct V_1 * V_2 , enum V_47 V_48 )
{
int V_3 = 0 ;
F_22 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_50 ) {
V_3 = V_2 -> V_50 ( V_2 , V_48 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_6 ) ;
F_23 ( & V_2 -> V_49 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_24 ( struct V_1 * V_2 , enum V_47 V_48 )
{
if ( V_2 -> V_51 )
V_2 -> V_51 ( V_2 , V_48 ) ;
F_23 ( & V_2 -> V_49 ) ;
}
static int F_25 ( struct V_20 * V_21 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_54 , V_55 ;
T_3 V_56 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_7 , ( long long ) V_53 -> V_54 ,
( long long ) V_53 -> V_55 ) ;
F_26 ( V_53 -> V_55 , V_21 -> V_57 , & V_56 ) ;
if ( V_56 )
return - V_58 ;
V_54 = V_53 -> V_54 ;
V_55 = V_53 -> V_55 ;
V_3 = F_21 ( V_2 , V_59 ) ;
if ( V_3 )
return V_3 ;
if ( V_55 == V_21 -> V_45 ) {
F_8 ( V_2 ) ;
if ( F_19 ( V_2 ) ) {
V_3 = - V_60 ;
goto V_61;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_61;
} else {
while ( V_55 ) {
F_8 ( V_2 ) ;
if ( V_2 -> V_62 ( V_2 , V_54 ) ) {
V_3 = - V_60 ;
goto V_61;
}
V_54 += V_21 -> V_57 ;
V_55 -= V_21 -> V_57 ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_61;
}
}
F_9 ( V_2 ) ;
F_24 ( V_2 , V_59 ) ;
V_53 -> V_63 = V_64 ;
F_27 ( V_53 ) ;
return V_3 ;
V_61:
F_24 ( V_2 , V_59 ) ;
V_53 -> V_63 = V_65 ;
return V_3 ;
}
static int F_28 ( struct V_20 * V_21 , T_4 V_66 , T_5 V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_3 V_67 = V_66 ;
T_6 V_68 , V_69 ;
int V_3 = 0 ;
V_3 = F_21 ( V_2 , V_70 ) ;
if ( V_3 )
return V_3 ;
V_68 = F_1 ( V_2 ) ;
if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 2 ) )
V_69 = V_68 | V_71 | V_72 | V_73 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 4 ) )
V_69 = ( V_68 & ~ V_73 ) | V_71 | V_72 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 8 ) )
V_69 = ( V_68 & ~ V_72 ) | V_71 | V_73 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 16 ) )
V_69 = ( V_68 & ~ ( V_73 | V_72 ) ) | V_71 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 32 ) )
V_69 = ( V_68 & ~ V_71 ) | V_72 | V_73 ;
else if ( V_67 < V_21 -> V_45 - ( V_21 -> V_45 / 64 ) )
V_69 = ( V_68 & ~ ( V_71 | V_73 ) ) | V_72 ;
else
V_69 = ( V_68 & ~ ( V_71 | V_72 ) ) | V_73 ;
if ( ( V_69 & ( V_71 | V_72 | V_73 ) ) >
( V_68 & ( V_71 | V_72 | V_73 ) ) ) {
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_69 ) ;
if ( V_3 )
goto V_74;
}
V_74:
F_24 ( V_2 , V_70 ) ;
return V_3 ;
}
static int F_29 ( struct V_20 * V_21 , T_4 V_66 , T_5 V_55 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_3 V_67 = V_66 ;
T_6 V_68 , V_69 ;
int V_3 = 0 ;
V_3 = F_21 ( V_2 , V_75 ) ;
if ( V_3 )
return V_3 ;
V_68 = F_1 ( V_2 ) ;
if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 64 ) )
V_69 = V_68 & ~ ( V_71 | V_72 | V_73 ) ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 32 ) )
V_69 = ( V_68 & ~ ( V_71 | V_72 ) ) | V_73 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 16 ) )
V_69 = ( V_68 & ~ ( V_71 | V_73 ) ) | V_72 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 8 ) )
V_69 = ( V_68 & ~ V_71 ) | V_72 | V_73 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 4 ) )
V_69 = ( V_68 & ~ ( V_73 | V_72 ) ) | V_71 ;
else if ( V_67 + V_55 > V_21 -> V_45 - ( V_21 -> V_45 / 2 ) )
V_69 = ( V_68 & ~ V_72 ) | V_71 | V_73 ;
else
V_69 = ( V_68 & ~ V_73 ) | V_71 | V_72 ;
if ( ( V_69 & ( V_71 | V_72 | V_73 ) ) <
( V_68 & ( V_71 | V_72 | V_73 ) ) ) {
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_69 ) ;
if ( V_3 )
goto V_74;
}
V_74:
F_24 ( V_2 , V_75 ) ;
return V_3 ;
}
static const struct V_76 * F_30 ( struct V_1 * V_2 )
{
int V_77 ;
T_1 V_78 [ V_79 ] ;
struct V_23 * V_24 ;
V_77 = V_2 -> V_5 ( V_2 , V_80 , V_78 , V_79 ) ;
if ( V_77 < 0 ) {
F_20 ( V_2 -> V_9 , L_8 , V_77 ) ;
return F_31 ( V_77 ) ;
}
for ( V_77 = 0 ; V_77 < F_32 ( V_81 ) - 1 ; V_77 ++ ) {
V_24 = ( void * ) V_81 [ V_77 ] . V_82 ;
if ( V_24 -> V_83 ) {
if ( ! memcmp ( V_24 -> V_78 , V_78 , V_24 -> V_83 ) )
return & V_81 [ V_77 ] ;
}
}
F_5 ( V_2 -> V_9 , L_9 ,
V_78 [ 0 ] , V_78 [ 1 ] , V_78 [ 2 ] ) ;
return F_31 ( - V_84 ) ;
}
static int F_33 ( struct V_20 * V_21 , T_4 V_85 , T_7 V_55 ,
T_7 * V_86 , T_8 * V_87 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_10 , ( T_2 ) V_85 , V_55 ) ;
V_3 = F_21 ( V_2 , V_88 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_89 ( V_2 , V_85 , V_55 , V_86 , V_87 ) ;
F_24 ( V_2 , V_88 ) ;
return V_3 ;
}
static int F_34 ( struct V_20 * V_21 , T_4 V_90 , T_7 V_55 ,
T_7 * V_86 , const T_8 * V_87 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_7 V_91 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_11 , ( T_2 ) V_90 , V_55 ) ;
V_3 = F_21 ( V_2 , V_92 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_93 = false ;
V_91 = V_90 % 2 ;
if ( V_91 ) {
V_2 -> V_94 = V_95 ;
V_2 -> V_96 ( V_2 , V_90 , 1 , V_86 , V_87 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_97;
}
V_90 += V_91 ;
for (; V_91 < V_55 - 1 ; V_91 += 2 ) {
V_2 -> V_94 = V_98 ;
V_2 -> V_96 ( V_2 , V_90 , 2 , V_86 , V_87 + V_91 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_97;
V_90 += 2 ;
V_2 -> V_93 = true ;
}
V_2 -> V_93 = false ;
F_9 ( V_2 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_97;
if ( V_91 != V_55 ) {
F_8 ( V_2 ) ;
V_2 -> V_94 = V_95 ;
V_2 -> V_96 ( V_2 , V_90 , 1 , V_86 , V_87 + V_91 ) ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_97;
F_9 ( V_2 ) ;
}
V_97:
F_24 ( V_2 , V_92 ) ;
return V_3 ;
}
static int F_35 ( struct V_20 * V_21 , T_4 V_90 , T_7 V_55 ,
T_7 * V_86 , const T_8 * V_87 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_99 , V_100 , V_101 ;
int V_3 ;
F_20 ( V_2 -> V_9 , L_11 , ( T_2 ) V_90 , V_55 ) ;
V_3 = F_21 ( V_2 , V_92 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_99 = V_90 & ( V_2 -> V_100 - 1 ) ;
if ( V_99 + V_55 <= V_2 -> V_100 ) {
V_2 -> V_96 ( V_2 , V_90 , V_55 , V_86 , V_87 ) ;
} else {
V_100 = V_2 -> V_100 - V_99 ;
V_2 -> V_96 ( V_2 , V_90 , V_100 , V_86 , V_87 ) ;
for ( V_101 = V_100 ; V_101 < V_55 ; V_101 += V_100 ) {
V_100 = V_55 - V_101 ;
if ( V_100 > V_2 -> V_100 )
V_100 = V_2 -> V_100 ;
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
goto V_102;
F_8 ( V_2 ) ;
V_2 -> V_96 ( V_2 , V_90 + V_101 , V_100 , V_86 , V_87 + V_101 ) ;
}
}
V_3 = F_16 ( V_2 ) ;
V_102:
F_24 ( V_2 , V_92 ) ;
return V_3 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 | V_103 ;
V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 , 0 ) ;
if ( F_16 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_103 ) ) ) {
F_5 ( V_2 -> V_9 , L_12 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_9 V_4 )
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
L_13 ) ;
return - V_58 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_105 ) ) ) {
F_5 ( V_2 -> V_9 , L_14 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_106 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
F_8 ( V_2 ) ;
V_2 -> V_15 [ 0 ] = V_4 & ~ V_107 ;
V_3 = V_2 -> V_16 ( V_2 , V_108 , V_2 -> V_15 , 1 , 0 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_5 ( V_2 , V_106 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_15 , V_3 ) ;
return V_3 ;
}
if ( V_4 & V_107 ) {
F_5 ( V_2 -> V_9 , L_17 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_26 ;
switch ( F_12 ( V_24 ) ) {
case V_30 :
V_26 = F_36 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_18 ) ;
return - V_58 ;
}
return V_26 ;
case V_29 :
V_26 = F_39 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_19 ) ;
return - V_58 ;
}
return V_26 ;
default:
V_26 = F_38 ( V_2 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_9 , L_20 ) ;
return - V_58 ;
}
return V_26 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_89 || ! V_2 -> V_96 ||
! V_2 -> V_5 || ! V_2 -> V_16 || ! V_2 -> V_62 ) {
F_2 ( L_21 ) ;
return - V_58 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 , const char * V_109 , enum V_110 V_111 )
{
const struct V_76 * V_78 = NULL ;
struct V_23 * V_24 ;
struct V_112 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_113 * V_114 = V_9 -> V_115 ;
int V_3 ;
int V_101 ;
V_3 = F_41 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( ! V_109 )
V_78 = F_30 ( V_2 ) ;
else
V_78 = F_43 ( V_109 ) ;
if ( F_44 ( V_78 ) )
return - V_116 ;
V_24 = ( void * ) V_78 -> V_82 ;
if ( V_109 && V_24 -> V_83 ) {
const struct V_76 * V_117 ;
V_117 = F_30 ( V_2 ) ;
if ( F_45 ( V_117 ) ) {
return F_46 ( V_117 ) ;
} else if ( V_117 != V_78 ) {
F_47 ( V_9 , L_22 ,
V_117 -> V_109 , V_78 -> V_109 ) ;
V_78 = V_117 ;
V_24 = ( void * ) V_117 -> V_82 ;
}
}
F_48 ( & V_2 -> V_49 ) ;
if ( F_12 ( V_24 ) == V_118 ||
F_12 ( V_24 ) == V_119 ||
F_12 ( V_24 ) == V_120 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
}
if ( ! V_21 -> V_109 )
V_21 -> V_109 = F_49 ( V_9 ) ;
V_21 -> type = V_121 ;
V_21 -> V_122 = 1 ;
V_21 -> V_38 = V_123 ;
V_21 -> V_45 = V_24 -> V_124 * V_24 -> V_125 ;
V_21 -> V_126 = F_25 ;
V_21 -> V_127 = F_33 ;
if ( F_12 ( V_24 ) == V_29 ) {
V_21 -> V_128 = F_28 ;
V_21 -> V_129 = F_29 ;
}
if ( V_24 -> V_38 & V_130 )
V_21 -> V_131 = F_34 ;
else
V_21 -> V_131 = F_35 ;
if ( V_24 -> V_38 & V_132 )
V_2 -> V_38 |= V_39 ;
#ifdef F_50
if ( V_24 -> V_38 & V_133 ) {
V_2 -> V_134 = V_135 ;
V_21 -> V_57 = 4096 ;
} else if ( V_24 -> V_38 & V_136 ) {
V_2 -> V_134 = V_137 ;
V_21 -> V_57 = 4096 ;
} else
#endif
{
V_2 -> V_134 = V_138 ;
V_21 -> V_57 = V_24 -> V_124 ;
}
if ( V_24 -> V_38 & V_139 )
V_21 -> V_38 |= V_140 ;
V_21 -> V_9 . V_141 = V_9 ;
V_2 -> V_100 = V_24 -> V_100 ;
V_21 -> V_142 = V_2 -> V_100 ;
if ( V_114 ) {
if ( F_51 ( V_114 , L_23 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_24 -> V_38 & V_143 )
V_2 -> V_10 = V_14 ;
if ( V_111 == V_13 && V_24 -> V_38 & V_144 ) {
V_3 = F_40 ( V_2 , V_24 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_24 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_111 == V_12 && V_24 -> V_38 & V_145 ) {
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
F_5 ( V_9 , L_25 ) ;
return - V_58 ;
}
V_2 -> V_94 = V_151 ;
if ( V_24 -> V_152 )
V_2 -> V_152 = V_24 -> V_152 ;
else if ( V_21 -> V_45 > 0x1000000 ) {
V_2 -> V_152 = 4 ;
if ( F_12 ( V_24 ) == V_153 ) {
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
V_2 -> V_94 = V_158 ;
V_2 -> V_134 = V_159 ;
V_21 -> V_57 = V_24 -> V_124 ;
} else
F_11 ( V_2 , V_24 , 1 ) ;
} else {
V_2 -> V_152 = 3 ;
}
V_2 -> V_160 = F_6 ( V_2 ) ;
F_52 ( V_9 , L_26 , V_78 -> V_109 ,
( long long ) V_21 -> V_45 >> 10 ) ;
F_20 ( V_9 ,
L_27
L_28 ,
V_21 -> V_109 , ( long long ) V_21 -> V_45 , ( long long ) ( V_21 -> V_45 >> 20 ) ,
V_21 -> V_57 , V_21 -> V_57 / 1024 , V_21 -> V_161 ) ;
if ( V_21 -> V_161 )
for ( V_101 = 0 ; V_101 < V_21 -> V_161 ; V_101 ++ )
F_20 ( V_9 ,
L_29
L_30
L_31 ,
V_101 , ( long long ) V_21 -> V_162 [ V_101 ] . V_67 ,
V_21 -> V_162 [ V_101 ] . V_57 ,
V_21 -> V_162 [ V_101 ] . V_57 / 1024 ,
V_21 -> V_162 [ V_101 ] . V_163 ) ;
return 0 ;
}
static const struct V_76 * F_43 ( const char * V_109 )
{
const struct V_76 * V_78 = V_81 ;
while ( V_78 -> V_109 [ 0 ] ) {
if ( ! strcmp ( V_109 , V_78 -> V_109 ) )
return V_78 ;
V_78 ++ ;
}
return NULL ;
}
