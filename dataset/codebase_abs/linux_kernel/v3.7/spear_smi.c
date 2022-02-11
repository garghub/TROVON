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
else if ( V_7 == 0 )
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
if ( V_10 < 0 ) {
if ( V_10 == - V_22 )
continue;
return V_10 ;
} else if ( ! ( V_10 & V_26 ) ) {
return 0 ;
}
F_10 () ;
} while ( ! F_11 ( V_25 , V_24 ) );
F_12 ( & V_5 -> V_27 -> V_5 , L_1 ) ;
return - V_28 ;
}
static T_2 F_13 ( int V_29 , void * V_30 )
{
T_1 V_10 = 0 ;
struct V_4 * V_5 = V_30 ;
V_10 = F_5 ( V_5 -> V_11 + V_31 ) ;
if ( F_14 ( ! V_10 ) )
return V_32 ;
F_6 ( 0 , V_5 -> V_11 + V_31 ) ;
V_5 -> V_10 |= V_10 ;
F_15 ( & V_5 -> V_19 ) ;
return V_33 ;
}
static void F_16 ( struct V_4 * V_5 )
{
unsigned long V_34 = 0 ;
T_1 V_35 = 0 ;
T_1 V_36 ;
V_34 = F_17 ( V_5 -> V_37 ) ;
V_35 = F_18 ( V_34 , V_5 -> V_38 ) ;
V_36 = V_39 | V_40 | V_41 | ( V_35 << 8 ) ;
F_4 ( & V_5 -> V_9 ) ;
F_6 ( 0 , V_5 -> V_11 + V_31 ) ;
F_6 ( V_36 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
static int F_19 ( T_1 V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_20 ( V_44 ) ; V_43 ++ ) {
if ( V_44 [ V_43 ] . V_45 == V_42 )
return V_43 ;
}
return - V_46 ;
}
static int F_21 ( struct V_4 * V_5 , T_1 V_6 )
{
int V_7 ;
T_1 V_8 ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_8 & ~ V_13 , V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_6 << V_15 ) | V_47 | V_17 , V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_6 ( 0 , V_5 -> V_11 + V_18 ) ;
if ( V_7 == 0 ) {
V_7 = - V_48 ;
F_12 ( & V_5 -> V_27 -> V_5 ,
L_2 ) ;
} else if ( V_7 > 0 ) {
if ( V_5 -> V_10 & ( 1 << ( V_6 + V_49 ) ) )
V_7 = 0 ;
else {
F_12 ( & V_5 -> V_27 -> V_5 , L_3 ) ;
V_7 = - V_48 ;
}
}
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static inline T_1
F_22 ( struct V_1 * V_50 , T_1 V_51 )
{
T_1 V_52 ;
T_3 * V_53 = ( T_3 * ) & V_52 ;
V_53 [ 0 ] = V_50 -> V_54 ;
V_53 [ 1 ] = V_51 >> 16 ;
V_53 [ 2 ] = V_51 >> 8 ;
V_53 [ 3 ] = V_51 ;
return V_52 ;
}
static int F_23 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_55 , T_1 V_56 )
{
T_1 V_8 = 0 ;
int V_7 ;
V_7 = F_9 ( V_5 , V_6 , V_57 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_21 ( V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_8 | V_13 ) & ~ V_14 , V_5 -> V_11 + V_12 ) ;
F_6 ( V_55 , V_5 -> V_11 + V_58 ) ;
F_6 ( ( V_6 << V_15 ) | V_59 | V_17 | ( V_56 << V_60 ) ,
V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
if ( V_7 == 0 ) {
V_7 = - V_48 ;
F_12 ( & V_5 -> V_27 -> V_5 , L_4 ) ;
} else if ( V_7 > 0 )
V_7 = 0 ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_6 ( 0 , V_5 -> V_11 + V_18 ) ;
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_61 * V_62 )
{
struct V_1 * V_50 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_63 ;
T_1 V_64 , V_55 , V_6 ;
int V_65 , V_7 ;
if ( ! V_50 || ! V_5 )
return - V_46 ;
V_6 = V_50 -> V_6 ;
if ( V_6 > V_5 -> V_66 - 1 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_5 ) ;
return - V_67 ;
}
V_64 = V_62 -> V_64 ;
V_65 = V_62 -> V_65 ;
F_4 ( & V_50 -> V_9 ) ;
while ( V_65 ) {
V_55 = F_22 ( V_50 , V_64 ) ;
V_7 = F_23 ( V_5 , V_6 , V_55 , 4 ) ;
if ( V_7 ) {
V_62 -> V_68 = V_69 ;
F_8 ( & V_50 -> V_9 ) ;
return V_7 ;
}
V_64 += V_3 -> V_70 ;
V_65 -= V_3 -> V_70 ;
}
F_8 ( & V_50 -> V_9 ) ;
V_62 -> V_68 = V_71 ;
F_25 ( V_62 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , T_4 V_72 , T_5 V_65 ,
T_5 * V_73 , T_3 * V_74 )
{
struct V_1 * V_50 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_63 ;
void * V_75 ;
T_1 V_8 , V_36 ;
int V_7 ;
if ( ! V_50 || ! V_5 )
return - V_46 ;
if ( V_50 -> V_6 > V_5 -> V_66 - 1 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_5 ) ;
return - V_67 ;
}
V_75 = V_50 -> V_76 + V_72 ;
F_4 ( & V_50 -> V_9 ) ;
V_7 = F_9 ( V_5 , V_50 -> V_6 , V_57 ) ;
if ( V_7 ) {
F_8 ( & V_50 -> V_9 ) ;
return V_7 ;
}
F_4 ( & V_5 -> V_9 ) ;
V_8 = V_36 = F_5 ( V_5 -> V_11 + V_12 ) ;
V_36 &= ~ ( V_13 | V_14 ) ;
if ( V_50 -> V_77 )
V_36 |= V_78 ;
F_6 ( V_36 , V_5 -> V_11 + V_12 ) ;
F_27 ( V_74 , ( T_3 * ) V_75 , V_65 ) ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
* V_73 = V_65 ;
F_8 ( & V_50 -> V_9 ) ;
return 0 ;
}
static inline int F_28 ( struct V_4 * V_5 , T_1 V_6 ,
void * V_79 , const void * V_75 , T_5 V_65 )
{
int V_7 ;
T_1 V_8 ;
V_7 = F_9 ( V_5 , V_6 , V_57 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_21 ( V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_8 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( ( V_8 | V_14 ) & ~ V_13 , V_5 -> V_11 + V_12 ) ;
F_29 ( V_79 , V_75 , V_65 ) ;
F_6 ( V_8 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , T_4 V_80 , T_5 V_65 ,
T_5 * V_73 , const T_3 * V_74 )
{
struct V_1 * V_50 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_63 ;
void * V_79 ;
T_1 V_81 , V_82 ;
int V_7 ;
if ( ! V_50 || ! V_5 )
return - V_46 ;
if ( V_50 -> V_6 > V_5 -> V_66 - 1 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_5 ) ;
return - V_67 ;
}
V_79 = V_50 -> V_76 + V_80 ;
F_4 ( & V_50 -> V_9 ) ;
V_81 = ( T_1 ) V_80 % V_50 -> V_82 ;
if ( V_81 + V_65 <= V_50 -> V_82 ) {
V_7 = F_28 ( V_5 , V_50 -> V_6 , V_79 , V_74 , V_65 ) ;
if ( ! V_7 )
* V_73 += V_65 ;
} else {
T_1 V_83 ;
V_82 = V_50 -> V_82 - V_81 ;
V_7 = F_28 ( V_5 , V_50 -> V_6 , V_79 , V_74 ,
V_82 ) ;
if ( V_7 )
goto V_84;
else
* V_73 += V_82 ;
for ( V_83 = V_82 ; V_83 < V_65 ; V_83 += V_82 ) {
V_82 = V_65 - V_83 ;
if ( V_82 > V_50 -> V_82 )
V_82 = V_50 -> V_82 ;
V_7 = F_28 ( V_5 , V_50 -> V_6 , V_79 + V_83 ,
V_74 + V_83 , V_82 ) ;
if ( V_7 )
break;
else
* V_73 += V_82 ;
}
}
V_84:
F_8 ( & V_50 -> V_9 ) ;
return V_7 ;
}
static int F_31 ( struct V_4 * V_5 , T_1 V_6 )
{
int V_7 ;
T_1 V_36 = 0 ;
V_7 = F_9 ( V_5 , V_6 , V_85 ) ;
if ( V_7 )
return V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
V_36 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_36 | V_13 , V_5 -> V_11 + V_12 ) ;
F_6 ( V_86 , V_5 -> V_11 + V_58 ) ;
V_36 = ( V_6 << V_15 ) | V_59 | ( 1 << V_60 ) |
( 3 << V_87 ) | V_17 ;
F_6 ( V_36 , V_5 -> V_11 + V_18 ) ;
V_7 = F_7 ( V_5 -> V_19 ,
V_5 -> V_10 & V_20 , V_21 ) ;
if ( V_7 <= 0 ) {
V_7 = - V_46 ;
goto V_88;
}
V_36 = F_5 ( V_5 -> V_11 + V_89 ) ;
V_36 &= 0x00ffffff ;
V_7 = F_19 ( V_36 ) ;
V_88:
V_36 = F_5 ( V_5 -> V_11 + V_12 ) ;
F_6 ( V_36 & ~ V_13 , V_5 -> V_11 + V_12 ) ;
F_8 ( & V_5 -> V_9 ) ;
return V_7 ;
}
static int T_6 F_32 ( struct V_90 * V_27 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 = F_33 ( & V_27 -> V_5 ) ;
struct V_91 * V_95 = NULL ;
const T_7 * V_64 ;
T_1 V_36 ;
int V_65 ;
int V_83 = 0 ;
if ( ! V_92 )
return - V_46 ;
F_34 ( V_92 , L_6 , & V_36 ) ;
V_94 -> V_38 = V_36 ;
V_94 -> V_96 = F_35 ( & V_27 -> V_5 ,
sizeof( * V_94 -> V_96 ) ,
V_97 ) ;
while ( ( V_95 = F_36 ( V_92 , V_95 ) ) ) {
struct V_98 * V_99 ;
V_99 = & V_94 -> V_96 [ V_83 ] ;
V_94 -> V_92 [ V_83 ] = V_95 ;
V_64 = F_37 ( V_95 , L_7 , & V_65 ) ;
V_94 -> V_96 -> V_100 = F_38 ( & V_64 [ 0 ] ) ;
V_94 -> V_96 -> V_101 = F_38 ( & V_64 [ 1 ] ) ;
if ( F_37 ( V_95 , L_8 , NULL ) )
V_94 -> V_96 -> V_77 = 1 ;
V_83 ++ ;
}
V_94 -> V_66 = V_83 ;
return 0 ;
}
static int T_6 F_32 ( struct V_90 * V_27 ,
struct V_91 * V_92 )
{
return - V_102 ;
}
static int F_39 ( struct V_90 * V_27 ,
T_1 V_6 , struct V_91 * V_92 )
{
struct V_4 * V_5 = F_40 ( V_27 ) ;
struct V_103 V_104 = {} ;
struct V_98 * V_99 ;
struct V_93 * V_94 ;
struct V_1 * V_50 ;
struct V_105 * V_106 = NULL ;
int V_107 = 0 ;
int V_108 ;
int V_7 = 0 ;
V_94 = F_33 ( & V_27 -> V_5 ) ;
if ( V_6 > V_94 -> V_66 - 1 )
return - V_67 ;
V_99 = & V_94 -> V_96 [ V_6 ] ;
if ( ! V_99 )
return - V_46 ;
V_50 = F_35 ( & V_27 -> V_5 , sizeof( * V_50 ) , V_109 ) ;
if ( ! V_50 )
return - V_110 ;
V_50 -> V_6 = V_6 ;
V_50 -> V_77 = V_99 -> V_77 ? 1 : 0 ;
F_41 ( & V_50 -> V_9 ) ;
V_108 = F_31 ( V_5 , V_6 ) ;
if ( V_108 < 0 ) {
F_42 ( & V_5 -> V_27 -> V_5 , L_9 , V_6 ) ;
return V_108 ;
}
V_50 -> V_76 = F_43 ( & V_27 -> V_5 , V_99 -> V_100 ,
V_99 -> V_101 ) ;
if ( ! V_50 -> V_76 )
return - V_48 ;
V_5 -> V_50 [ V_6 ] = V_50 ;
V_50 -> V_3 . V_63 = V_5 ;
if ( V_99 -> V_111 )
V_50 -> V_3 . V_111 = V_99 -> V_111 ;
else
V_50 -> V_3 . V_111 = V_44 [ V_108 ] . V_111 ;
V_50 -> V_3 . type = V_112 ;
V_50 -> V_3 . V_113 = 1 ;
V_50 -> V_3 . V_114 = V_115 ;
V_50 -> V_3 . V_101 = V_99 -> V_101 ;
V_50 -> V_3 . V_70 = V_44 [ V_108 ] . V_116 ;
V_50 -> V_82 = V_44 [ V_108 ] . V_117 ;
V_50 -> V_3 . V_118 = V_50 -> V_82 ;
V_50 -> V_54 = V_44 [ V_108 ] . V_54 ;
V_50 -> V_3 . V_119 = F_24 ;
V_50 -> V_3 . V_120 = F_26 ;
V_50 -> V_3 . V_121 = F_30 ;
V_50 -> V_30 = V_44 [ V_108 ] . V_45 ;
F_42 ( & V_5 -> V_27 -> V_5 , L_10 ,
V_50 -> V_3 . V_111 , V_50 -> V_3 . V_101 ,
V_50 -> V_3 . V_101 / ( 1024 * 1024 ) ) ;
F_42 ( & V_5 -> V_27 -> V_5 , L_11 ,
V_50 -> V_3 . V_70 , V_50 -> V_3 . V_70 / 1024 ) ;
#ifndef F_44
if ( V_99 -> V_122 ) {
V_106 = V_99 -> V_122 ;
V_107 = V_99 -> V_123 ;
}
#endif
V_104 . V_124 = V_92 ;
V_7 = F_45 ( & V_50 -> V_3 , NULL , & V_104 , V_106 ,
V_107 ) ;
if ( V_7 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_12 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int T_6 F_46 ( struct V_90 * V_27 )
{
struct V_91 * V_92 = V_27 -> V_5 . V_124 ;
struct V_93 * V_94 = NULL ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
int V_29 , V_7 = 0 ;
int V_83 ;
if ( V_92 ) {
V_94 = F_35 ( & V_27 -> V_5 , sizeof( * V_94 ) , V_97 ) ;
if ( ! V_94 ) {
F_47 ( L_13 , V_127 ) ;
V_7 = - V_110 ;
goto V_128;
}
V_27 -> V_5 . V_129 = V_94 ;
V_7 = F_32 ( V_27 , V_92 ) ;
if ( V_7 ) {
V_7 = - V_46 ;
F_12 ( & V_27 -> V_5 , L_14 ) ;
goto V_128;
}
} else {
V_94 = F_33 ( & V_27 -> V_5 ) ;
if ( ! V_94 ) {
V_7 = - V_46 ;
F_12 ( & V_27 -> V_5 , L_14 ) ;
goto V_128;
}
}
V_29 = F_48 ( V_27 , 0 ) ;
if ( V_29 < 0 ) {
V_7 = - V_46 ;
F_12 ( & V_27 -> V_5 , L_15 ) ;
goto V_128;
}
V_5 = F_35 ( & V_27 -> V_5 , sizeof( * V_5 ) , V_109 ) ;
if ( ! V_5 ) {
V_7 = - V_110 ;
F_12 ( & V_27 -> V_5 , L_16 ) ;
goto V_128;
}
V_126 = F_49 ( V_27 , V_130 , 0 ) ;
V_5 -> V_11 = F_50 ( & V_27 -> V_5 , V_126 ) ;
if ( ! V_5 -> V_11 ) {
V_7 = - V_48 ;
F_12 ( & V_27 -> V_5 , L_17 ) ;
goto V_128;
}
V_5 -> V_27 = V_27 ;
V_5 -> V_38 = V_94 -> V_38 ;
if ( V_5 -> V_38 > V_131 )
V_5 -> V_38 = V_131 ;
V_5 -> V_66 = V_94 -> V_66 ;
if ( V_5 -> V_66 > V_132 ) {
F_12 ( & V_27 -> V_5 , L_18 ) ;
V_5 -> V_66 = V_132 ;
}
V_5 -> V_37 = F_51 ( & V_27 -> V_5 , NULL ) ;
if ( F_52 ( V_5 -> V_37 ) ) {
V_7 = F_53 ( V_5 -> V_37 ) ;
goto V_128;
}
V_7 = F_54 ( V_5 -> V_37 ) ;
if ( V_7 )
goto V_128;
V_7 = F_55 ( & V_27 -> V_5 , V_29 , F_13 , 0 ,
V_27 -> V_111 , V_5 ) ;
if ( V_7 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_19 ) ;
goto V_133;
}
F_41 ( & V_5 -> V_9 ) ;
F_56 ( & V_5 -> V_19 ) ;
F_16 ( V_5 ) ;
F_57 ( V_27 , V_5 ) ;
for ( V_83 = 0 ; V_83 < V_5 -> V_66 ; V_83 ++ ) {
V_7 = F_39 ( V_27 , V_83 , V_94 -> V_92 [ V_83 ] ) ;
if ( V_7 ) {
F_12 ( & V_5 -> V_27 -> V_5 , L_20 ) ;
goto V_134;
}
}
return 0 ;
V_134:
F_57 ( V_27 , NULL ) ;
V_133:
F_58 ( V_5 -> V_37 ) ;
V_128:
return V_7 ;
}
static int T_8 F_59 ( struct V_90 * V_27 )
{
struct V_4 * V_5 ;
struct V_1 * V_50 ;
int V_7 , V_83 ;
V_5 = F_40 ( V_27 ) ;
if ( ! V_5 ) {
F_12 ( & V_27 -> V_5 , L_21 ) ;
return - V_46 ;
}
for ( V_83 = 0 ; V_83 < V_5 -> V_66 ; V_83 ++ ) {
V_50 = V_5 -> V_50 [ V_83 ] ;
if ( ! V_50 )
continue;
V_7 = F_60 ( & V_50 -> V_3 ) ;
if ( V_7 )
F_12 ( & V_27 -> V_5 , L_22 ) ;
}
F_58 ( V_5 -> V_37 ) ;
F_57 ( V_27 , NULL ) ;
return 0 ;
}
static int F_61 ( struct V_135 * V_5 )
{
struct V_4 * V_136 = F_62 ( V_5 ) ;
if ( V_136 && V_136 -> V_37 )
F_58 ( V_136 -> V_37 ) ;
return 0 ;
}
static int F_63 ( struct V_135 * V_5 )
{
struct V_4 * V_136 = F_62 ( V_5 ) ;
int V_7 = - V_137 ;
if ( V_136 && V_136 -> V_37 )
V_7 = F_54 ( V_136 -> V_37 ) ;
if ( ! V_7 )
F_16 ( V_136 ) ;
return V_7 ;
}
static int F_64 ( void )
{
return F_65 ( & V_138 ) ;
}
static void F_66 ( void )
{
F_67 ( & V_138 ) ;
}
