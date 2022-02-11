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
struct V_18 * V_19 = V_9 -> V_9 -> V_19 ;
V_12 = ( V_17 / 12000000 ) - 1 ;
if ( ( V_17 / ( V_12 + 1 ) ) > 12000000 )
V_12 ++ ;
V_14 = ( V_12 >= 2 ) ? 5 : 7 - V_12 ;
if ( V_19 && F_8 ( V_19 , L_1 ) )
V_14 = 6 ;
V_13 = ( ( V_17 / ( V_12 + 1 ) ) / ( V_11 -> V_20 * 1000 ) ) ;
if ( V_17 / ( V_12 + 1 ) / V_13 > V_11 -> V_20 * 1000 )
V_13 ++ ;
if ( V_11 -> V_20 > 100 )
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
F_1 ( V_9 , V_21 , V_12 ) ;
F_1 ( V_9 , V_22 , V_15 ) ;
F_1 ( V_9 , V_23 , V_16 ) ;
F_9 ( V_9 -> V_9 , L_2 , V_17 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_5 ( V_9 , 0 ) ;
F_6 ( V_9 ) ;
F_1 ( V_9 , V_24 , V_25 ) ;
F_9 ( V_9 -> V_9 , L_3 ,
F_3 ( V_9 , V_21 ) ) ;
F_9 ( V_9 -> V_9 , L_4 ,
F_3 ( V_9 , V_23 ) ) ;
F_9 ( V_9 -> V_9 , L_5 ,
F_3 ( V_9 , V_22 ) ) ;
F_9 ( V_9 -> V_9 , L_6 ,
V_11 -> V_20 , V_11 -> V_26 ) ;
F_5 ( V_9 , 1 ) ;
F_1 ( V_9 , V_27 , V_28 ) ;
return 0 ;
}
static void F_11 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
F_1 ( V_9 , V_27 , 0 ) ;
F_5 ( V_9 , 0 ) ;
}
static void F_13 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
F_10 ( V_9 ) ;
}
static void F_14 ( struct V_29 * V_30 , int V_4 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
if ( V_4 )
F_1 ( V_9 , V_31 ,
V_32 ) ;
else
F_1 ( V_9 , V_33 ,
V_34 ) ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
int V_4 ;
V_4 = F_3 ( V_9 , V_35 ) ;
return V_4 & V_36 ;
}
static int F_16 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
int V_4 ;
V_4 = F_3 ( V_9 , V_35 ) ;
return V_4 & V_37 ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
F_11 ( V_30 ) ;
F_1 ( V_9 , V_38 , V_39 ) ;
F_1 ( V_9 , V_40 ,
V_41 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
F_1 ( V_9 , V_40 , 0 ) ;
F_13 ( V_30 ) ;
}
static int F_19 ( struct V_1 * V_9 )
{
unsigned long V_42 = V_43 + V_9 -> V_44 . V_42 ;
do {
if ( ! ( F_3 ( V_9 , V_45 ) & V_46 ) )
return 0 ;
F_20 ( 1 ) ;
} while ( F_21 ( V_43 , V_42 ) );
F_22 ( V_9 -> V_9 , L_7 ) ;
F_23 ( & V_9 -> V_44 ) ;
if ( F_3 ( V_9 , V_45 ) & V_46 )
return - V_47 ;
return 0 ;
}
static int
F_24 ( struct V_29 * V_30 , struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
T_2 V_51 ;
T_1 V_6 ;
unsigned long V_52 ;
if ( V_49 -> V_53 == V_25 ) {
F_22 ( V_9 -> V_9 , L_8 ) ;
return - V_54 ;
}
if ( V_11 -> V_26 )
F_25 ( V_11 -> V_26 ) ;
F_1 ( V_9 , V_55 , V_49 -> V_53 ) ;
V_9 -> V_56 = V_49 -> V_56 ;
V_9 -> V_57 = V_49 -> V_58 ;
V_9 -> V_50 = V_50 ;
F_1 ( V_9 , V_59 , V_9 -> V_57 ) ;
F_26 ( & V_9 -> V_60 ) ;
V_9 -> V_61 = 0 ;
V_51 = V_8 | V_62 ;
if ( V_49 -> V_63 & V_64 )
V_51 |= V_65 ;
if ( ! ( V_49 -> V_63 & V_66 ) )
V_51 |= V_67 ;
if ( V_49 -> V_58 == 0 )
V_51 |= V_68 ;
V_6 = F_3 ( V_9 , V_27 ) ;
if ( V_49 -> V_63 & V_66 )
V_6 |= V_69 ;
else
V_6 |= V_70 ;
F_1 ( V_9 , V_27 , V_6 ) ;
V_9 -> V_71 = 0 ;
F_1 ( V_9 , V_7 , V_51 ) ;
if ( ( ! ( V_49 -> V_63 & V_66 ) ) && V_9 -> V_57 ) {
F_1 ( V_9 , V_72 , * V_9 -> V_56 ++ ) ;
V_9 -> V_57 -- ;
}
V_51 |= V_73 ;
if ( V_50 && V_49 -> V_58 != 0 )
V_51 |= V_74 ;
F_1 ( V_9 , V_7 , V_51 ) ;
V_52 = F_27 ( & V_9 -> V_60 ,
V_9 -> V_44 . V_42 ) ;
if ( ! V_52 ) {
F_28 ( V_9 -> V_9 , L_9 ) ;
F_23 ( V_30 ) ;
V_9 -> V_57 = 0 ;
return - V_75 ;
}
if ( V_9 -> V_57 ) {
F_28 ( V_9 -> V_9 , L_10 ,
V_9 -> V_57 ) ;
V_9 -> V_71 = 1 ;
F_29 () ;
V_9 -> V_57 = 0 ;
return - V_76 ;
}
if ( F_30 ( ! V_9 -> V_61 ) )
return V_49 -> V_58 ;
if ( V_9 -> V_61 & V_77 ) {
F_10 ( V_9 ) ;
return - V_47 ;
}
if ( V_9 -> V_61 & V_78 ) {
if ( V_49 -> V_63 & V_79 )
return V_49 -> V_58 ;
V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_74 ;
F_1 ( V_9 , V_7 , V_6 ) ;
return - V_76 ;
}
return - V_47 ;
}
static int
F_31 ( struct V_29 * V_30 , struct V_48 V_80 [] , int V_81 )
{
struct V_1 * V_9 = F_12 ( V_30 ) ;
int V_82 ;
int V_83 ;
F_9 ( V_9 -> V_9 , L_11 , V_84 , V_81 ) ;
V_83 = F_19 ( V_9 ) ;
if ( V_83 < 0 ) {
F_22 ( V_9 -> V_9 , L_7 ) ;
return V_83 ;
}
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
V_83 = F_24 ( V_30 , & V_80 [ V_82 ] , ( V_82 == ( V_81 - 1 ) ) ) ;
F_9 ( V_9 -> V_9 , L_12 , V_84 , V_82 + 1 , V_81 ,
V_83 ) ;
if ( V_83 < 0 )
return V_83 ;
}
#ifdef F_32
F_33 ( & V_9 -> V_85 ) ;
#endif
return V_81 ;
}
static T_2 F_34 ( struct V_29 * V_30 )
{
return V_86 | V_87 ;
}
static void F_35 ( struct V_1 * V_9 )
{
T_1 V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_88 ;
F_1 ( V_9 , V_7 , V_6 ) ;
F_3 ( V_9 , V_89 ) ;
if ( ! V_9 -> V_71 )
F_28 ( V_9 -> V_9 , L_13 ) ;
}
static void F_36 ( struct V_1 * V_9 )
{
T_1 V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_68 | V_74 ;
F_1 ( V_9 , V_7 , V_6 ) ;
if ( ! V_9 -> V_71 )
F_9 ( V_9 -> V_9 , L_14 ) ;
}
static T_3 F_37 ( int V_90 , void * V_91 )
{
struct V_1 * V_9 = V_91 ;
T_2 V_92 ;
int V_93 = 0 ;
T_1 V_6 ;
while ( ( V_92 = F_3 ( V_9 , V_94 ) ) ) {
F_9 ( V_9 -> V_9 , L_15 , V_84 , V_92 ) ;
if ( V_93 ++ == 100 ) {
F_22 ( V_9 -> V_9 , L_16 ) ;
break;
}
switch ( V_92 ) {
case V_95 :
V_9 -> V_61 |= V_77 ;
V_9 -> V_57 = 0 ;
F_33 ( & V_9 -> V_60 ) ;
break;
case V_96 :
V_9 -> V_61 |= V_78 ;
V_9 -> V_57 = 0 ;
F_33 ( & V_9 -> V_60 ) ;
break;
case V_97 :
F_1 ( V_9 ,
V_45 , V_98 ) ;
if ( ( ( V_9 -> V_57 == 0 ) && ( V_9 -> V_50 != 0 ) ) ||
( V_9 -> V_61 & V_78 ) ) {
V_6 = F_3 ( V_9 ,
V_7 ) ;
V_6 |= V_74 ;
F_1 ( V_9 ,
V_7 , V_6 ) ;
}
F_33 ( & V_9 -> V_60 ) ;
break;
case V_99 :
if ( V_9 -> V_57 ) {
* V_9 -> V_56 ++ =
F_3 ( V_9 ,
V_89 ) ;
V_9 -> V_57 -- ;
if ( V_9 -> V_57 )
continue;
F_1 ( V_9 ,
V_45 ,
V_69 ) ;
} else {
F_35 ( V_9 ) ;
}
break;
case V_100 :
if ( V_9 -> V_57 ) {
F_1 ( V_9 , V_72 ,
* V_9 -> V_56 ++ ) ;
V_9 -> V_57 -- ;
if ( V_9 -> V_57 )
continue;
V_6 = F_3 ( V_9 ,
V_27 ) ;
V_6 &= ~ V_70 ;
F_1 ( V_9 ,
V_27 ,
V_6 ) ;
} else {
F_36 ( V_9 ) ;
}
break;
case V_101 :
F_1 ( V_9 ,
V_45 , V_102 ) ;
F_33 ( & V_9 -> V_60 ) ;
break;
case V_103 :
F_9 ( V_9 -> V_9 , L_17 ) ;
break;
default:
F_22 ( V_9 -> V_9 , L_18 , V_92 ) ;
break;
}
}
return V_93 ? V_104 : V_105 ;
}
static int F_38 ( struct V_106 * V_107 ,
unsigned long V_4 , void * V_108 )
{
struct V_1 * V_9 ;
V_9 = F_39 ( V_107 , struct V_1 , V_109 ) ;
if ( V_4 == V_110 ) {
F_40 ( & V_9 -> V_85 ) ;
F_5 ( V_9 , 0 ) ;
} else if ( V_4 == V_111 ) {
F_6 ( V_9 ) ;
F_5 ( V_9 , 1 ) ;
}
return 0 ;
}
static inline int F_41 ( struct V_1 * V_9 )
{
V_9 -> V_109 . V_112 = F_38 ;
return F_42 ( & V_9 -> V_109 ,
V_113 ) ;
}
static inline void F_43 ( struct V_1 * V_9 )
{
F_44 ( & V_9 -> V_109 ,
V_113 ) ;
}
static inline int F_41 ( struct V_1 * V_9 )
{
return 0 ;
}
static inline void F_43 ( struct V_1 * V_9 )
{
}
static int F_45 ( struct V_114 * V_115 )
{
struct V_1 * V_9 ;
struct V_29 * V_30 ;
struct V_116 * V_117 ;
int V_118 , V_119 ;
V_119 = F_46 ( V_115 , 0 ) ;
if ( V_119 <= 0 ) {
if ( ! V_119 )
V_119 = - V_120 ;
if ( V_119 != - V_121 )
F_28 ( & V_115 -> V_9 ,
L_19 , V_119 ) ;
return V_119 ;
}
V_9 = F_47 ( & V_115 -> V_9 , sizeof( struct V_1 ) ,
V_122 ) ;
if ( ! V_9 ) {
F_28 ( & V_115 -> V_9 , L_20 ) ;
return - V_123 ;
}
F_48 ( & V_9 -> V_60 ) ;
#ifdef F_32
F_48 ( & V_9 -> V_85 ) ;
#endif
V_9 -> V_9 = & V_115 -> V_9 ;
V_9 -> V_119 = V_119 ;
V_9 -> V_11 = F_49 ( & V_115 -> V_9 ) ;
F_50 ( V_115 , V_9 ) ;
if ( ! V_9 -> V_11 && V_115 -> V_9 . V_19 ) {
T_2 V_124 ;
V_9 -> V_11 = F_47 ( & V_115 -> V_9 ,
sizeof( struct V_10 ) , V_122 ) ;
if ( ! V_9 -> V_11 )
return - V_123 ;
memcpy ( V_9 -> V_11 , & V_125 ,
sizeof( struct V_10 ) ) ;
if ( ! F_51 ( V_115 -> V_9 . V_19 , L_21 ,
& V_124 ) )
V_9 -> V_11 -> V_20 = V_124 / 1000 ;
V_9 -> V_11 -> V_126 =
F_52 ( V_115 -> V_9 . V_19 ,
L_22 ) ;
} else if ( ! V_9 -> V_11 ) {
V_9 -> V_11 = & V_125 ;
}
V_9 -> V_13 = F_53 ( & V_115 -> V_9 , NULL ) ;
if ( F_54 ( V_9 -> V_13 ) )
return F_55 ( V_9 -> V_13 ) ;
F_56 ( V_9 -> V_13 ) ;
V_117 = F_57 ( V_115 , V_127 , 0 ) ;
V_9 -> V_5 = F_58 ( & V_115 -> V_9 , V_117 ) ;
if ( F_54 ( V_9 -> V_5 ) ) {
V_118 = F_55 ( V_9 -> V_5 ) ;
goto V_128;
}
F_10 ( V_9 ) ;
V_118 = F_59 ( & V_115 -> V_9 , V_9 -> V_119 , F_37 , 0 ,
V_115 -> V_129 , V_9 ) ;
if ( V_118 ) {
F_28 ( & V_115 -> V_9 , L_23 , V_9 -> V_119 ) ;
goto V_128;
}
V_118 = F_41 ( V_9 ) ;
if ( V_118 ) {
F_28 ( & V_115 -> V_9 , L_24 ) ;
goto V_128;
}
V_30 = & V_9 -> V_44 ;
F_60 ( V_30 , V_9 ) ;
V_30 -> V_130 = V_131 ;
V_30 -> V_132 = V_133 ;
F_61 ( V_30 -> V_129 , L_25 , sizeof( V_30 -> V_129 ) ) ;
V_30 -> V_134 = & V_135 ;
V_30 -> V_9 . V_136 = & V_115 -> V_9 ;
V_30 -> V_42 = V_137 ;
V_30 -> V_9 . V_19 = V_115 -> V_9 . V_19 ;
if ( V_9 -> V_11 -> V_126 )
V_30 -> V_138 = & V_139 ;
else if ( V_9 -> V_11 -> V_140 ) {
V_30 -> V_138 = & V_141 ;
V_30 -> V_138 -> V_142 = V_9 -> V_11 -> V_140 ;
V_30 -> V_138 -> V_143 = V_9 -> V_11 -> V_144 ;
}
V_30 -> V_145 = V_115 -> V_146 ;
V_118 = F_62 ( V_30 ) ;
if ( V_118 )
goto V_128;
return 0 ;
V_128:
F_63 ( V_9 -> V_13 ) ;
V_9 -> V_13 = NULL ;
return V_118 ;
}
static int F_64 ( struct V_114 * V_115 )
{
struct V_1 * V_9 = F_65 ( V_115 ) ;
F_43 ( V_9 ) ;
F_66 ( & V_9 -> V_44 ) ;
F_63 ( V_9 -> V_13 ) ;
V_9 -> V_13 = NULL ;
F_1 ( V_9 , V_7 , 0 ) ;
return 0 ;
}
static int F_67 ( struct V_147 * V_9 )
{
struct V_1 * V_2 = F_68 ( V_9 ) ;
F_5 ( V_2 , 0 ) ;
F_63 ( V_2 -> V_13 ) ;
return 0 ;
}
static int F_69 ( struct V_147 * V_9 )
{
struct V_1 * V_2 = F_68 ( V_9 ) ;
F_56 ( V_2 -> V_13 ) ;
F_5 ( V_2 , 1 ) ;
return 0 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_148 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_148 ) ;
}
