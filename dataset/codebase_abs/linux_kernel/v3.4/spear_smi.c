static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
int V_7 ;
T_1 V_8 ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_8 & ~ ( V_13 | V_14 ) , V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_6 << V_15 ) | V_16 | V_17 ,
V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
if ( V_7 > 0 )
V_7 = V_5 -> V_10 & 0xffff ;
else
V_7 = - V_22 ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_6 ( 0 , V_5 -> V_11 + V_18 ) ;
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static int F_9 ( struct V_4 * V_5 , T_1 V_6 ,
unsigned long V_23 )
{
unsigned long V_24 ;
int V_10 ;
V_24 = V_25 + V_23 ;
do {
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
continue;
else if ( ! ( V_10 & V_26 ) )
return 0 ;
F_10 () ;
} while ( ! F_11 ( V_25 , V_24 ) );
F_12 ( & V_5 -> V_27 -> V_5 , L_1 ) ;
return V_10 ;
}
static T_2 F_13 ( int V_28 , void * V_29 )
{
T_1 V_10 = 0 ;
struct V_4 * V_5 = V_29 ;
V_10 = F_5 ( V_5 -> V_11 + V_30 ) ;
if ( F_14 ( ! V_10 ) )
return V_31 ;
F_6 ( 0 , V_5 -> V_11 + V_30 ) ;
V_5 -> V_10 |= V_10 ;
F_15 ( & V_5 -> V_19 ) ;
return V_32 ;
}
static void F_16 ( struct V_4 * V_5 )
{
unsigned long V_33 = 0 ;
T_1 V_34 = 0 ;
T_1 V_35 ;
V_33 = F_17 ( V_5 -> V_36 ) ;
V_34 = F_18 ( V_33 , V_5 -> V_37 ) ;
V_35 = V_38 | V_39 | V_40 | ( V_34 << 8 ) ;
F_4 ( & V_5 -> V_9 ) ;
F_6 ( V_35 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
static int F_19 ( T_1 V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_20 ( V_43 ) ; V_42 ++ ) {
if ( V_43 [ V_42 ] . V_44 == V_41 )
return V_42 ;
}
return - V_45 ;
}
static int F_21 ( struct V_4 * V_5 , T_1 V_6 )
{
int V_7 ;
T_1 V_8 ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_8 & ~ V_13 , V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_6 << V_15 ) | V_46 | V_17 , V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_6 ( 0 , V_5 -> V_11 + V_18 ) ;
if ( V_7 <= 0 ) {
V_7 = - V_22 ;
F_12 ( & V_5 -> V_27 -> V_5 ,
L_2 ) ;
} else {
if ( V_5 -> V_10 & ( 1 << ( V_6 + V_47 ) ) )
V_7 = 0 ;
else {
F_12 ( & V_5 -> V_27 -> V_5 , L_3 ) ;
V_7 = - V_22 ;
}
}
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static inline T_1
F_22 ( struct V_1 * V_48 , T_1 V_49 )
{
T_1 V_50 ;
T_3 * V_51 = ( T_3 * ) & V_50 ;
V_51 [ 0 ] = V_48 -> V_52 ;
V_51 [ 1 ] = V_49 >> 16 ;
V_51 [ 2 ] = V_49 >> 8 ;
V_51 [ 3 ] = V_49 ;
return V_50 ;
}
static int F_23 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_53 , T_1 V_54 )
{
T_1 V_8 = 0 ;
int V_7 ;
V_7 = F_9 ( V_5 , V_6 , V_55 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_21 ( V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_8 | V_13 ) & ~ V_14 , V_5 -> V_11 + V_12 ) ;
F_6 ( V_53 , V_5 -> V_11 + V_56 ) ;
F_6 ( ( V_6 << V_15 ) | V_57 | V_17 | ( V_54 << V_58 ) ,
V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
if ( V_7 <= 0 ) {
V_7 = - V_22 ;
F_12 ( & V_5 -> V_27 -> V_5 , L_4 ) ;
} else
V_7 = 0 ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_6 ( 0 , V_5 -> V_11 + V_18 ) ;
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_59 * V_60 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_61 ;
T_1 V_62 , V_53 , V_6 ;
int V_63 , V_7 ;
if ( ! V_48 || ! V_5 )
return - V_45 ;
V_6 = V_48 -> V_6 ;
if ( V_6 > V_5 -> V_64 - 1 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_5 ) ;
return - V_65 ;
}
V_62 = V_60 -> V_62 ;
V_63 = V_60 -> V_63 ;
F_4 ( & V_48 -> V_9 ) ;
while ( V_63 ) {
V_53 = F_22 ( V_48 , V_62 ) ;
V_7 = F_23 ( V_5 , V_6 , V_53 , 4 ) ;
if ( V_7 ) {
V_60 -> V_66 = V_67 ;
F_8 ( & V_48 -> V_9 ) ;
return V_7 ;
}
V_62 += V_3 -> V_68 ;
V_63 -= V_3 -> V_68 ;
}
F_8 ( & V_48 -> V_9 ) ;
V_60 -> V_66 = V_69 ;
F_25 ( V_60 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , T_4 V_70 , T_5 V_63 ,
T_5 * V_71 , T_3 * V_72 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_61 ;
void * V_73 ;
T_1 V_8 , V_35 ;
int V_7 ;
if ( ! V_48 || ! V_5 )
return - V_45 ;
if ( V_48 -> V_6 > V_5 -> V_64 - 1 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_5 ) ;
return - V_65 ;
}
V_73 = V_48 -> V_74 + V_70 ;
F_4 ( & V_48 -> V_9 ) ;
V_7 = F_9 ( V_5 , V_48 -> V_6 , V_55 ) ;
if ( V_7 ) {
F_8 ( & V_48 -> V_9 ) ;
return V_7 ;
}
F_4 ( & V_5 -> V_9 ) ;
V_8 = V_35 = F_5 ( V_5 -> V_11 + V_12 ) ;
V_35 &= ~ ( V_13 | V_14 ) ;
if ( V_48 -> V_75 )
V_35 |= V_76 ;
F_6 ( V_35 , V_5 -> V_11 + V_12 ) ;
F_27 ( V_72 , ( T_3 * ) V_73 , V_63 ) ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
* V_71 = V_63 ;
F_8 ( & V_48 -> V_9 ) ;
return 0 ;
}
static inline int F_28 ( struct V_4 * V_5 , T_1 V_6 ,
void * V_77 , const void * V_73 , T_5 V_63 )
{
int V_7 ;
T_1 V_8 ;
V_7 = F_9 ( V_5 , V_6 , V_55 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_21 ( V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_8 | V_14 ) & ~ V_13 , V_5 -> V_11 + V_12 ) ;
F_29 ( V_77 , V_73 , V_63 ) ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , T_4 V_78 , T_5 V_63 ,
T_5 * V_71 , const T_3 * V_72 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_61 ;
void * V_77 ;
T_1 V_79 , V_80 ;
int V_7 ;
if ( ! V_48 || ! V_5 )
return - V_45 ;
if ( V_48 -> V_6 > V_5 -> V_64 - 1 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_5 ) ;
return - V_65 ;
}
V_77 = V_48 -> V_74 + V_78 ;
F_4 ( & V_48 -> V_9 ) ;
V_79 = ( T_1 ) V_78 % V_48 -> V_80 ;
if ( V_79 + V_63 <= V_48 -> V_80 ) {
V_7 = F_28 ( V_5 , V_48 -> V_6 , V_77 , V_72 , V_63 ) ;
if ( ! V_7 )
* V_71 += V_63 ;
} else {
T_1 V_81 ;
V_80 = V_48 -> V_80 - V_79 ;
V_7 = F_28 ( V_5 , V_48 -> V_6 , V_77 , V_72 ,
V_80 ) ;
if ( V_7 )
goto V_82;
else
* V_71 += V_80 ;
for ( V_81 = V_80 ; V_81 < V_63 ; V_81 += V_80 ) {
V_80 = V_63 - V_81 ;
if ( V_80 > V_48 -> V_80 )
V_80 = V_48 -> V_80 ;
V_7 = F_28 ( V_5 , V_48 -> V_6 , V_77 + V_81 ,
V_72 + V_81 , V_80 ) ;
if ( V_7 )
break;
else
* V_71 += V_80 ;
}
}
V_82:
F_8 ( & V_48 -> V_9 ) ;
return V_7 ;
}
static int F_31 ( struct V_4 * V_5 , T_1 V_6 )
{
int V_7 ;
T_1 V_35 = 0 ;
V_7 = F_9 ( V_5 , V_6 , V_83 ) ;
if ( V_7 )
return V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_35 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_35 | V_13 , V_5 -> V_11 + V_12 ) ;
F_6 ( V_84 , V_5 -> V_11 + V_56 ) ;
V_35 = ( V_6 << V_15 ) | V_57 | ( 1 << V_58 ) |
( 3 << V_85 ) | V_17 ;
F_6 ( V_35 , V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
if ( V_7 <= 0 ) {
V_7 = - V_45 ;
goto V_86;
}
V_35 = F_5 ( V_5 -> V_11 + V_87 ) ;
V_35 &= 0x00ffffff ;
V_7 = F_19 ( V_35 ) ;
V_86:
V_35 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_35 & ~ V_13 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static int T_6 F_32 ( struct V_88 * V_27 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = F_33 ( & V_27 -> V_5 ) ;
struct V_89 * V_93 = NULL ;
const T_7 * V_62 ;
T_1 V_35 ;
int V_63 ;
int V_81 = 0 ;
if ( ! V_90 )
return - V_45 ;
F_34 ( V_90 , L_6 , & V_35 ) ;
V_92 -> V_37 = V_35 ;
V_92 -> V_94 = F_35 ( & V_27 -> V_5 ,
sizeof( * V_92 -> V_94 ) ,
V_95 ) ;
while ( ( V_93 = F_36 ( V_90 , V_93 ) ) ) {
struct V_96 * V_97 ;
V_97 = & V_92 -> V_94 [ V_81 ] ;
V_92 -> V_90 [ V_81 ] = V_93 ;
V_62 = F_37 ( V_93 , L_7 , & V_63 ) ;
V_92 -> V_94 -> V_98 = F_38 ( & V_62 [ 0 ] ) ;
V_92 -> V_94 -> V_99 = F_38 ( & V_62 [ 1 ] ) ;
if ( F_37 ( V_93 , L_8 , NULL ) )
V_92 -> V_94 -> V_75 = 1 ;
V_81 ++ ;
}
V_92 -> V_64 = V_81 ;
return 0 ;
}
static int T_6 F_32 ( struct V_88 * V_27 ,
struct V_89 * V_90 )
{
return - V_100 ;
}
static int F_39 ( struct V_88 * V_27 ,
T_1 V_6 , struct V_89 * V_90 )
{
struct V_4 * V_5 = F_40 ( V_27 ) ;
struct V_101 V_102 = {} ;
struct V_96 * V_97 ;
struct V_91 * V_92 ;
struct V_1 * V_48 ;
struct V_103 * V_104 = NULL ;
int V_105 = 0 ;
int V_106 ;
int V_7 = 0 ;
V_92 = F_33 ( & V_27 -> V_5 ) ;
if ( V_6 > V_92 -> V_64 - 1 )
return - V_65 ;
V_97 = & V_92 -> V_94 [ V_6 ] ;
if ( ! V_97 )
return - V_45 ;
V_48 = F_41 ( sizeof( * V_48 ) , V_107 ) ;
if ( ! V_48 )
return - V_108 ;
V_48 -> V_6 = V_6 ;
V_48 -> V_75 = V_97 -> V_75 ? 1 : 0 ;
F_42 ( & V_48 -> V_9 ) ;
V_106 = F_31 ( V_5 , V_6 ) ;
if ( V_106 < 0 ) {
F_43 ( & V_5 -> V_27 -> V_5 , L_9 , V_6 ) ;
V_7 = V_106 ;
goto V_86;
}
V_48 -> V_74 = F_44 ( V_97 -> V_98 , V_97 -> V_99 ) ;
if ( ! V_48 -> V_74 ) {
V_7 = - V_22 ;
goto V_86;
}
V_5 -> V_48 [ V_6 ] = V_48 ;
V_48 -> V_3 . V_61 = V_5 ;
if ( V_97 -> V_109 )
V_48 -> V_3 . V_109 = V_97 -> V_109 ;
else
V_48 -> V_3 . V_109 = V_43 [ V_106 ] . V_109 ;
V_48 -> V_3 . type = V_110 ;
V_48 -> V_3 . V_111 = 1 ;
V_48 -> V_3 . V_112 = V_113 ;
V_48 -> V_3 . V_99 = V_97 -> V_99 ;
V_48 -> V_3 . V_68 = V_43 [ V_106 ] . V_114 ;
V_48 -> V_80 = V_43 [ V_106 ] . V_115 ;
V_48 -> V_3 . V_116 = V_48 -> V_80 ;
V_48 -> V_52 = V_43 [ V_106 ] . V_52 ;
V_48 -> V_3 . V_117 = F_24 ;
V_48 -> V_3 . V_118 = F_26 ;
V_48 -> V_3 . V_119 = F_30 ;
V_48 -> V_29 = V_43 [ V_106 ] . V_44 ;
F_43 ( & V_5 -> V_27 -> V_5 , L_10 ,
V_48 -> V_3 . V_109 , V_48 -> V_3 . V_99 ,
V_48 -> V_3 . V_99 / ( 1024 * 1024 ) ) ;
F_43 ( & V_5 -> V_27 -> V_5 , L_11 ,
V_48 -> V_3 . V_68 , V_48 -> V_3 . V_68 / 1024 ) ;
#ifndef F_45
if ( V_97 -> V_120 ) {
V_104 = V_97 -> V_120 ;
V_105 = V_97 -> V_121 ;
}
#endif
V_102 . V_122 = V_90 ;
V_7 = F_46 ( & V_48 -> V_3 , NULL , & V_102 , V_104 ,
V_105 ) ;
if ( V_7 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_12 , V_7 ) ;
goto V_123;
}
return 0 ;
V_123:
F_47 ( V_48 -> V_74 ) ;
V_86:
F_48 ( V_48 ) ;
return V_7 ;
}
static int T_6 F_49 ( struct V_88 * V_27 )
{
struct V_89 * V_90 = V_27 -> V_5 . V_122 ;
struct V_91 * V_92 = NULL ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
int V_28 , V_7 = 0 ;
int V_81 ;
if ( V_90 ) {
V_92 = F_35 ( & V_27 -> V_5 , sizeof( * V_92 ) , V_95 ) ;
if ( ! V_92 ) {
F_50 ( L_13 , V_126 ) ;
V_7 = - V_108 ;
goto V_127;
}
V_27 -> V_5 . V_128 = V_92 ;
V_7 = F_32 ( V_27 , V_90 ) ;
if ( V_7 ) {
V_7 = - V_45 ;
F_12 ( & V_27 -> V_5 , L_14 ) ;
goto V_127;
}
} else {
V_92 = F_33 ( & V_27 -> V_5 ) ;
if ( V_92 < 0 ) {
V_7 = - V_45 ;
F_12 ( & V_27 -> V_5 , L_14 ) ;
goto V_127;
}
}
V_125 = F_51 ( V_27 , V_129 , 0 ) ;
if ( ! V_125 ) {
V_7 = - V_45 ;
F_12 ( & V_27 -> V_5 , L_15 ) ;
goto V_127;
}
V_28 = F_52 ( V_27 , 0 ) ;
if ( V_28 < 0 ) {
V_7 = - V_45 ;
F_12 ( & V_27 -> V_5 , L_16 ) ;
goto V_127;
}
V_5 = F_41 ( sizeof( * V_5 ) , V_107 ) ;
if ( ! V_5 ) {
V_7 = - V_108 ;
F_12 ( & V_27 -> V_5 , L_17 ) ;
goto V_127;
}
V_125 = F_53 ( V_125 -> V_130 , F_54 ( V_125 ) ,
V_27 -> V_109 ) ;
if ( ! V_125 ) {
V_7 = - V_131 ;
F_12 ( & V_27 -> V_5 , L_18 ) ;
goto V_132;
}
V_5 -> V_11 = F_44 ( V_125 -> V_130 , F_54 ( V_125 ) ) ;
if ( ! V_5 -> V_11 ) {
V_7 = - V_22 ;
F_12 ( & V_27 -> V_5 , L_19 ) ;
goto V_133;
}
V_5 -> V_27 = V_27 ;
V_5 -> V_37 = V_92 -> V_37 ;
if ( V_5 -> V_37 < 0 || V_5 -> V_37 > V_134 )
V_5 -> V_37 = V_134 ;
V_5 -> V_64 = V_92 -> V_64 ;
if ( V_5 -> V_64 > V_135 ) {
F_12 ( & V_27 -> V_5 , L_20 ) ;
V_5 -> V_64 = V_135 ;
}
V_5 -> V_36 = F_55 ( & V_27 -> V_5 , NULL ) ;
if ( F_56 ( V_5 -> V_36 ) ) {
V_7 = F_57 ( V_5 -> V_36 ) ;
goto V_136;
}
V_7 = F_58 ( V_5 -> V_36 ) ;
if ( V_7 )
goto V_137;
V_7 = F_59 ( V_28 , F_13 , 0 , V_27 -> V_109 , V_5 ) ;
if ( V_7 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_21 ) ;
goto V_138;
}
F_42 ( & V_5 -> V_9 ) ;
F_60 ( & V_5 -> V_19 ) ;
F_16 ( V_5 ) ;
F_61 ( V_27 , V_5 ) ;
for ( V_81 = 0 ; V_81 < V_5 -> V_64 ; V_81 ++ ) {
V_7 = F_39 ( V_27 , V_81 , V_92 -> V_90 [ V_81 ] ) ;
if ( V_7 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_22 ) ;
goto V_139;
}
}
return 0 ;
V_139:
F_62 ( V_28 , V_5 ) ;
F_61 ( V_27 , NULL ) ;
V_138:
F_63 ( V_5 -> V_36 ) ;
V_137:
F_64 ( V_5 -> V_36 ) ;
V_136:
F_47 ( V_5 -> V_11 ) ;
V_133:
F_65 ( V_125 -> V_130 , F_54 ( V_125 ) ) ;
V_132:
F_48 ( V_5 ) ;
V_127:
return V_7 ;
}
static int T_8 F_66 ( struct V_88 * V_27 )
{
struct V_4 * V_5 ;
struct V_91 * V_92 ;
struct V_1 * V_48 ;
struct V_124 * V_125 ;
int V_7 ;
int V_81 , V_28 ;
V_5 = F_40 ( V_27 ) ;
if ( ! V_5 ) {
F_12 ( & V_27 -> V_5 , L_23 ) ;
return - V_45 ;
}
V_92 = F_33 ( & V_27 -> V_5 ) ;
for ( V_81 = 0 ; V_81 < V_5 -> V_64 ; V_81 ++ ) {
V_48 = V_5 -> V_48 [ V_81 ] ;
if ( ! V_48 )
continue;
V_7 = F_67 ( & V_48 -> V_3 ) ;
if ( V_7 )
F_12 ( & V_27 -> V_5 , L_24 ) ;
F_47 ( V_48 -> V_74 ) ;
F_48 ( V_48 ) ;
}
V_28 = F_52 ( V_27 , 0 ) ;
F_62 ( V_28 , V_5 ) ;
F_63 ( V_5 -> V_36 ) ;
F_64 ( V_5 -> V_36 ) ;
F_47 ( V_5 -> V_11 ) ;
F_48 ( V_5 ) ;
V_125 = F_51 ( V_27 , V_129 , 0 ) ;
F_65 ( V_125 -> V_130 , F_54 ( V_125 ) ) ;
F_61 ( V_27 , NULL ) ;
return 0 ;
}
int F_68 ( struct V_88 * V_27 , T_9 V_66 )
{
struct V_4 * V_5 = F_40 ( V_27 ) ;
if ( V_5 && V_5 -> V_36 )
F_63 ( V_5 -> V_36 ) ;
return 0 ;
}
int F_69 ( struct V_88 * V_27 )
{
struct V_4 * V_5 = F_40 ( V_27 ) ;
int V_7 = - V_140 ;
if ( V_5 && V_5 -> V_36 )
V_7 = F_58 ( V_5 -> V_36 ) ;
if ( ! V_7 )
F_16 ( V_5 ) ;
return V_7 ;
}
static int F_70 ( void )
{
return F_71 ( & V_141 ) ;
}
static void F_72 ( void )
{
F_73 ( & V_141 ) ;
}
