static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
int V_4 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 , V_7 ) ;
if ( ! V_4 )
V_6 &= ~ V_8 ;
else
V_6 |= V_8 ;
F_1 ( V_2 , V_7 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_1 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
T_2 V_16 ;
T_2 V_17 = F_7 ( V_9 -> V_13 ) ;
V_12 = ( V_17 / 7000000 ) - 1 ;
if ( ( V_17 / ( V_12 + 1 ) ) > 12000000 )
V_12 ++ ;
V_14 = ( V_12 >= 2 ) ? 5 : 7 - V_12 ;
V_13 = ( ( V_17 / ( V_12 + 1 ) ) / ( V_11 -> V_18 * 1000 ) ) ;
if ( V_17 / ( V_12 + 1 ) / V_13 > V_11 -> V_18 * 1000 )
V_13 ++ ;
if ( V_11 -> V_18 > 100 )
V_16 = ( V_13 << 1 ) / 3 ;
else
V_16 = ( V_13 >> 1 ) ;
if ( V_13 >= V_16 + V_14 ) {
V_15 = V_13 - V_16 - V_14 ;
V_16 -= V_14 ;
} else {
V_15 = 0 ;
V_16 = V_13 - ( V_14 << 1 ) ;
}
F_1 ( V_9 , V_19 , V_12 ) ;
F_1 ( V_9 , V_20 , V_15 ) ;
F_1 ( V_9 , V_21 , V_16 ) ;
F_8 ( V_9 -> V_9 , L_1 , V_17 , V_13 ) ;
}
static int F_9 ( struct V_1 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_5 ( V_9 , 0 ) ;
F_6 ( V_9 ) ;
F_1 ( V_9 , V_22 , V_23 ) ;
F_8 ( V_9 -> V_9 , L_2 ,
F_3 ( V_9 , V_19 ) ) ;
F_8 ( V_9 -> V_9 , L_3 ,
F_3 ( V_9 , V_21 ) ) ;
F_8 ( V_9 -> V_9 , L_4 ,
F_3 ( V_9 , V_20 ) ) ;
F_8 ( V_9 -> V_9 , L_5 ,
V_11 -> V_18 , V_11 -> V_24 ) ;
F_5 ( V_9 , 1 ) ;
F_1 ( V_9 , V_25 , V_26 ) ;
return 0 ;
}
static void F_10 ( struct V_27 * V_28 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
F_1 ( V_9 , V_25 , 0 ) ;
F_5 ( V_9 , 0 ) ;
}
static void F_12 ( struct V_27 * V_28 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
F_9 ( V_9 ) ;
}
static void F_13 ( struct V_27 * V_28 , int V_4 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
if ( V_4 )
F_1 ( V_9 , V_29 ,
V_30 ) ;
else
F_1 ( V_9 , V_31 ,
V_32 ) ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
int V_4 ;
V_4 = F_3 ( V_9 , V_33 ) ;
return V_4 & V_34 ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
int V_4 ;
V_4 = F_3 ( V_9 , V_33 ) ;
return V_4 & V_35 ;
}
static void F_16 ( struct V_27 * V_28 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
F_10 ( V_28 ) ;
F_1 ( V_9 , V_36 , V_37 ) ;
F_1 ( V_9 , V_38 ,
V_39 ) ;
}
static void F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
F_1 ( V_9 , V_38 , 0 ) ;
F_12 ( V_28 ) ;
}
static int F_18 ( struct V_1 * V_9 )
{
unsigned long V_40 = V_41 + V_9 -> V_42 . V_40 ;
do {
if ( ! ( F_3 ( V_9 , V_43 ) & V_44 ) )
return 0 ;
F_19 ( 1 ) ;
} while ( F_20 ( V_41 , V_40 ) );
F_21 ( V_9 -> V_9 , L_6 ) ;
F_22 ( & V_9 -> V_42 ) ;
if ( F_3 ( V_9 , V_43 ) & V_44 )
return - V_45 ;
return 0 ;
}
static int
F_23 ( struct V_27 * V_28 , struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
T_2 V_49 ;
T_1 V_6 ;
unsigned long V_50 ;
if ( V_47 -> V_51 == V_23 ) {
F_21 ( V_9 -> V_9 , L_7 ) ;
return - V_52 ;
}
if ( V_11 -> V_24 )
F_24 ( V_11 -> V_24 ) ;
F_1 ( V_9 , V_53 , V_47 -> V_51 ) ;
V_9 -> V_54 = V_47 -> V_54 ;
V_9 -> V_55 = V_47 -> V_56 ;
V_9 -> V_48 = V_48 ;
F_1 ( V_9 , V_57 , V_9 -> V_55 ) ;
F_25 ( & V_9 -> V_58 ) ;
V_9 -> V_59 = 0 ;
V_49 = V_8 | V_60 ;
if ( V_47 -> V_61 & V_62 )
V_49 |= V_63 ;
if ( ! ( V_47 -> V_61 & V_64 ) )
V_49 |= V_65 ;
if ( V_47 -> V_56 == 0 )
V_49 |= V_66 ;
V_6 = F_3 ( V_9 , V_25 ) ;
if ( V_47 -> V_61 & V_64 )
V_6 |= V_67 ;
else
V_6 |= V_68 ;
F_1 ( V_9 , V_25 , V_6 ) ;
V_9 -> V_69 = 0 ;
F_1 ( V_9 , V_7 , V_49 ) ;
if ( ( ! ( V_47 -> V_61 & V_64 ) ) && V_9 -> V_55 ) {
F_1 ( V_9 , V_70 , * V_9 -> V_54 ++ ) ;
V_9 -> V_55 -- ;
}
V_49 |= V_71 ;
if ( V_48 && V_47 -> V_56 != 0 )
V_49 |= V_72 ;
F_1 ( V_9 , V_7 , V_49 ) ;
V_50 = F_26 ( & V_9 -> V_58 ,
V_9 -> V_42 . V_40 ) ;
if ( ! V_50 ) {
F_27 ( V_9 -> V_9 , L_8 ) ;
F_22 ( V_28 ) ;
V_9 -> V_55 = 0 ;
return - V_73 ;
}
if ( V_9 -> V_55 ) {
F_27 ( V_9 -> V_9 , L_9 ,
V_9 -> V_55 ) ;
V_9 -> V_69 = 1 ;
F_28 () ;
V_9 -> V_55 = 0 ;
return - V_74 ;
}
if ( F_29 ( ! V_9 -> V_59 ) )
return V_47 -> V_56 ;
if ( V_9 -> V_59 & V_75 ) {
F_9 ( V_9 ) ;
return - V_45 ;
}
if ( V_9 -> V_59 & V_76 ) {
if ( V_47 -> V_61 & V_77 )
return V_47 -> V_56 ;
V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_72 ;
F_1 ( V_9 , V_7 , V_6 ) ;
return - V_74 ;
}
return - V_45 ;
}
static int
F_30 ( struct V_27 * V_28 , struct V_46 V_78 [] , int V_79 )
{
struct V_1 * V_9 = F_11 ( V_28 ) ;
int V_80 ;
int V_81 ;
F_8 ( V_9 -> V_9 , L_10 , V_82 , V_79 ) ;
V_81 = F_18 ( V_9 ) ;
if ( V_81 < 0 ) {
F_21 ( V_9 -> V_9 , L_6 ) ;
return V_81 ;
}
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_81 = F_23 ( V_28 , & V_78 [ V_80 ] , ( V_80 == ( V_79 - 1 ) ) ) ;
F_8 ( V_9 -> V_9 , L_11 , V_82 , V_80 + 1 , V_79 ,
V_81 ) ;
if ( V_81 < 0 )
return V_81 ;
}
#ifdef F_31
F_32 ( & V_9 -> V_83 ) ;
#endif
return V_79 ;
}
static T_2 F_33 ( struct V_27 * V_28 )
{
return V_84 | V_85 ;
}
static void F_34 ( struct V_1 * V_9 )
{
T_1 V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_86 ;
F_1 ( V_9 , V_7 , V_6 ) ;
F_3 ( V_9 , V_87 ) ;
if ( ! V_9 -> V_69 )
F_27 ( V_9 -> V_9 , L_12 ) ;
}
static void F_35 ( struct V_1 * V_9 )
{
T_1 V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_66 | V_72 ;
F_1 ( V_9 , V_7 , V_6 ) ;
if ( ! V_9 -> V_69 )
F_8 ( V_9 -> V_9 , L_13 ) ;
}
static T_3 F_36 ( int V_88 , void * V_89 )
{
struct V_1 * V_9 = V_89 ;
T_2 V_90 ;
int V_91 = 0 ;
T_1 V_6 ;
while ( ( V_90 = F_3 ( V_9 , V_92 ) ) ) {
F_8 ( V_9 -> V_9 , L_14 , V_82 , V_90 ) ;
if ( V_91 ++ == 100 ) {
F_21 ( V_9 -> V_9 , L_15 ) ;
break;
}
switch ( V_90 ) {
case V_93 :
V_9 -> V_59 |= V_75 ;
V_9 -> V_55 = 0 ;
F_32 ( & V_9 -> V_58 ) ;
break;
case V_94 :
V_9 -> V_59 |= V_76 ;
V_9 -> V_55 = 0 ;
F_32 ( & V_9 -> V_58 ) ;
break;
case V_95 :
F_1 ( V_9 ,
V_43 , V_96 ) ;
if ( ( ( V_9 -> V_55 == 0 ) && ( V_9 -> V_48 != 0 ) ) ||
( V_9 -> V_59 & V_76 ) ) {
V_6 = F_3 ( V_9 ,
V_7 ) ;
V_6 |= V_72 ;
F_1 ( V_9 ,
V_7 , V_6 ) ;
}
F_32 ( & V_9 -> V_58 ) ;
break;
case V_97 :
if ( V_9 -> V_55 ) {
* V_9 -> V_54 ++ =
F_3 ( V_9 ,
V_87 ) ;
V_9 -> V_55 -- ;
if ( V_9 -> V_55 )
continue;
F_1 ( V_9 ,
V_43 ,
V_67 ) ;
} else {
F_34 ( V_9 ) ;
}
break;
case V_98 :
if ( V_9 -> V_55 ) {
F_1 ( V_9 , V_70 ,
* V_9 -> V_54 ++ ) ;
V_9 -> V_55 -- ;
if ( V_9 -> V_55 )
continue;
V_6 = F_3 ( V_9 ,
V_25 ) ;
V_6 &= ~ V_68 ;
F_1 ( V_9 ,
V_25 ,
V_6 ) ;
} else {
F_35 ( V_9 ) ;
}
break;
case V_99 :
F_1 ( V_9 ,
V_43 , V_100 ) ;
F_32 ( & V_9 -> V_58 ) ;
break;
case V_101 :
F_8 ( V_9 -> V_9 , L_16 ) ;
break;
default:
F_21 ( V_9 -> V_9 , L_17 , V_90 ) ;
break;
}
}
return V_91 ? V_102 : V_103 ;
}
static int F_37 ( struct V_104 * V_105 ,
unsigned long V_4 , void * V_106 )
{
struct V_1 * V_9 ;
V_9 = F_38 ( V_105 , struct V_1 , V_107 ) ;
if ( V_4 == V_108 ) {
F_39 ( & V_9 -> V_83 ) ;
F_5 ( V_9 , 0 ) ;
} else if ( V_4 == V_109 ) {
F_6 ( V_9 ) ;
F_5 ( V_9 , 1 ) ;
}
return 0 ;
}
static inline int F_40 ( struct V_1 * V_9 )
{
V_9 -> V_107 . V_110 = F_37 ;
return F_41 ( & V_9 -> V_107 ,
V_111 ) ;
}
static inline void F_42 ( struct V_1 * V_9 )
{
F_43 ( & V_9 -> V_107 ,
V_111 ) ;
}
static inline int F_40 ( struct V_1 * V_9 )
{
return 0 ;
}
static inline void F_42 ( struct V_1 * V_9 )
{
}
static int F_44 ( struct V_112 * V_113 )
{
struct V_1 * V_9 ;
struct V_27 * V_28 ;
struct V_114 * V_115 ;
int V_116 , V_117 ;
V_117 = F_45 ( V_113 , 0 ) ;
if ( V_117 <= 0 ) {
if ( ! V_117 )
V_117 = - V_118 ;
if ( V_117 != - V_119 )
F_27 ( & V_113 -> V_9 ,
L_18 , V_117 ) ;
return V_117 ;
}
V_9 = F_46 ( & V_113 -> V_9 , sizeof( struct V_1 ) ,
V_120 ) ;
if ( ! V_9 ) {
F_27 ( & V_113 -> V_9 , L_19 ) ;
return - V_121 ;
}
F_47 ( & V_9 -> V_58 ) ;
#ifdef F_31
F_47 ( & V_9 -> V_83 ) ;
#endif
V_9 -> V_9 = & V_113 -> V_9 ;
V_9 -> V_117 = V_117 ;
V_9 -> V_11 = F_48 ( & V_113 -> V_9 ) ;
F_49 ( V_113 , V_9 ) ;
if ( ! V_9 -> V_11 && V_113 -> V_9 . V_122 ) {
T_2 V_123 ;
V_9 -> V_11 = F_46 ( & V_113 -> V_9 ,
sizeof( struct V_10 ) , V_120 ) ;
if ( ! V_9 -> V_11 )
return - V_121 ;
memcpy ( V_9 -> V_11 , & V_124 ,
sizeof( struct V_10 ) ) ;
if ( ! F_50 ( V_113 -> V_9 . V_122 , L_20 ,
& V_123 ) )
V_9 -> V_11 -> V_18 = V_123 / 1000 ;
V_9 -> V_11 -> V_125 =
F_51 ( V_113 -> V_9 . V_122 ,
L_21 ) ;
} else if ( ! V_9 -> V_11 ) {
V_9 -> V_11 = & V_124 ;
}
V_9 -> V_13 = F_52 ( & V_113 -> V_9 , NULL ) ;
if ( F_53 ( V_9 -> V_13 ) )
return - V_126 ;
F_54 ( V_9 -> V_13 ) ;
V_115 = F_55 ( V_113 , V_127 , 0 ) ;
V_9 -> V_5 = F_56 ( & V_113 -> V_9 , V_115 ) ;
if ( F_53 ( V_9 -> V_5 ) ) {
V_116 = F_57 ( V_9 -> V_5 ) ;
goto V_128;
}
F_9 ( V_9 ) ;
V_116 = F_58 ( & V_113 -> V_9 , V_9 -> V_117 , F_36 , 0 ,
V_113 -> V_129 , V_9 ) ;
if ( V_116 ) {
F_27 ( & V_113 -> V_9 , L_22 , V_9 -> V_117 ) ;
goto V_128;
}
V_116 = F_40 ( V_9 ) ;
if ( V_116 ) {
F_27 ( & V_113 -> V_9 , L_23 ) ;
goto V_128;
}
V_28 = & V_9 -> V_42 ;
F_59 ( V_28 , V_9 ) ;
V_28 -> V_130 = V_131 ;
V_28 -> V_132 = V_133 ;
F_60 ( V_28 -> V_129 , L_24 , sizeof( V_28 -> V_129 ) ) ;
V_28 -> V_134 = & V_135 ;
V_28 -> V_9 . V_136 = & V_113 -> V_9 ;
V_28 -> V_40 = V_137 ;
V_28 -> V_9 . V_122 = V_113 -> V_9 . V_122 ;
if ( V_9 -> V_11 -> V_125 )
V_28 -> V_138 = & V_139 ;
else if ( V_9 -> V_11 -> V_140 ) {
V_28 -> V_138 = & V_141 ;
V_28 -> V_138 -> V_142 = V_9 -> V_11 -> V_140 ;
V_28 -> V_138 -> V_143 = V_9 -> V_11 -> V_144 ;
}
V_28 -> V_145 = V_113 -> V_146 ;
V_116 = F_61 ( V_28 ) ;
if ( V_116 ) {
F_27 ( & V_113 -> V_9 , L_25 ) ;
goto V_128;
}
return 0 ;
V_128:
F_62 ( V_9 -> V_13 ) ;
V_9 -> V_13 = NULL ;
return V_116 ;
}
static int F_63 ( struct V_112 * V_113 )
{
struct V_1 * V_9 = F_64 ( V_113 ) ;
F_42 ( V_9 ) ;
F_65 ( & V_9 -> V_42 ) ;
F_62 ( V_9 -> V_13 ) ;
V_9 -> V_13 = NULL ;
F_1 ( V_9 , V_7 , 0 ) ;
return 0 ;
}
static int F_66 ( struct V_147 * V_9 )
{
struct V_112 * V_113 = F_67 ( V_9 ) ;
struct V_1 * V_2 = F_64 ( V_113 ) ;
F_5 ( V_2 , 0 ) ;
F_62 ( V_2 -> V_13 ) ;
return 0 ;
}
static int F_68 ( struct V_147 * V_9 )
{
struct V_112 * V_113 = F_67 ( V_9 ) ;
struct V_1 * V_2 = F_64 ( V_113 ) ;
F_54 ( V_2 -> V_13 ) ;
F_5 ( V_2 , 1 ) ;
return 0 ;
}
static int T_4 F_69 ( void )
{
return F_70 ( & V_148 ) ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_148 ) ;
}
