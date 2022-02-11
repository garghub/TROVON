static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_6 -> V_7 + V_3 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 -> V_7 + V_3 ) ;
}
static inline void F_6 ( const struct V_8 * V_9 ,
int V_3 , T_1 V_4 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
F_3 ( V_4 , V_11 -> V_7 + V_3 ) ;
}
static inline T_1 F_7 ( const struct V_8 * V_9 , int V_3 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
return F_5 ( V_11 -> V_7 + V_3 ) ;
}
static inline T_1 F_8 ( const struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
return V_11 -> V_13 ;
}
static inline void F_9 ( const struct V_8 * V_9 , T_1 V_4 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_13 = V_4 ;
F_6 ( V_9 , V_14 , V_4 ) ;
F_7 ( V_9 , V_14 ) ;
}
static inline int F_10 ( int V_15 )
{
if ( V_15 <= 8 )
return 1 ;
else if ( V_15 <= 16 )
return 2 ;
else
return 4 ;
}
static void F_11 ( const struct V_8 * V_9 ,
int V_16 , int V_17 )
{
T_1 V_18 , V_19 ;
V_18 = F_8 ( V_9 ) ;
if ( V_16 )
V_19 = V_20 ;
else
V_19 = V_21 ;
if ( V_17 )
V_18 |= V_19 ;
else
V_18 &= ~ V_19 ;
F_9 ( V_9 , V_18 ) ;
}
static void F_12 ( const struct V_8 * V_9 , int V_17 )
{
T_1 V_18 ;
V_18 = V_17 ? V_22 : 0 ;
F_6 ( V_9 , V_23 , V_18 ) ;
F_7 ( V_9 , V_23 ) ;
}
static void F_13 ( struct V_8 * V_9 , int V_24 )
{
T_1 V_18 ;
V_18 = F_8 ( V_9 ) ;
if ( V_24 )
V_18 |= V_25 ;
else
V_18 &= ~ V_25 ;
F_9 ( V_9 , V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_27 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 , V_28 ) ;
V_18 &= ~ ( V_29 | V_30 ) ;
V_18 |= V_31 ;
F_1 ( V_2 , V_28 , V_18 ) ;
V_27 -> V_32 = V_18 ;
}
static void F_15 ( const struct V_8 * V_9 ,
struct V_33 * V_34 , int V_17 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
unsigned int V_35 ;
int V_36 , V_37 , V_38 ;
T_1 V_39 , V_40 ;
V_6 = F_2 ( V_2 ) ;
V_39 = F_8 ( V_9 ) ;
if ( V_17 ) {
V_38 = F_10 ( V_11 -> V_15 ) ;
if ( V_34 -> V_41 % V_38 != 0 )
goto V_42;
if ( V_34 -> V_43 != NULL && V_34 -> V_44 != NULL )
V_36 = V_45 / 2 ;
else
V_36 = V_45 ;
V_37 = F_16 ( V_34 -> V_41 , V_36 ) ;
if ( V_37 < 2 || V_37 % V_38 != 0 )
goto V_42;
V_35 = V_34 -> V_41 / V_38 ;
if ( V_35 > V_46 )
goto V_42;
V_40 = V_35 << 16 ;
if ( V_34 -> V_43 != NULL ) {
V_39 |= V_47 ;
V_40 |= ( V_37 - 1 ) << 8 ;
}
if ( V_34 -> V_44 != NULL ) {
V_39 |= V_48 ;
V_40 |= V_37 - 1 ;
}
F_1 ( V_2 , V_49 , V_40 ) ;
F_9 ( V_9 , V_39 ) ;
V_6 -> V_37 = V_37 ;
return;
}
V_42:
if ( V_34 -> V_43 != NULL )
V_39 &= ~ V_47 ;
else
V_39 &= ~ V_48 ;
F_9 ( V_9 , V_39 ) ;
V_6 -> V_37 = 0 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_50 = V_6 -> V_2 ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_10 * V_11 ;
F_1 ( V_50 , V_28 , V_27 -> V_32 ) ;
F_1 ( V_50 , V_51 , V_27 -> V_52 ) ;
F_18 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static int F_19 ( void T_2 * V_53 , unsigned long V_54 )
{
unsigned long V_55 ;
V_55 = V_56 + F_20 ( 1000 ) ;
while ( ! ( F_5 ( V_53 ) & V_54 ) ) {
if ( F_21 ( V_56 , V_55 ) ) {
if ( ! ( F_5 ( V_53 ) & V_54 ) )
return - V_57 ;
else
return 0 ;
}
F_22 () ;
}
return 0 ;
}
static void F_23 ( void * V_58 )
{
struct V_8 * V_9 = V_58 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_59 * V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
F_11 ( V_9 , 1 , 0 ) ;
F_24 ( & V_60 -> V_63 ) ;
}
static void F_25 ( void * V_58 )
{
struct V_8 * V_9 = V_58 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_59 * V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
F_11 ( V_9 , 0 , 0 ) ;
F_24 ( & V_60 -> V_64 ) ;
}
static void F_26 ( struct V_8 * V_9 ,
struct V_33 * V_65 ,
struct V_66 V_67 )
{
struct V_5 * V_6 ;
struct V_59 * V_60 ;
unsigned int V_68 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
V_68 = V_65 -> V_41 ;
if ( V_60 -> V_69 ) {
struct V_70 * V_71 ;
struct V_72 V_73 ;
F_27 ( V_60 -> V_69 , & V_67 ) ;
F_28 ( & V_73 , 1 ) ;
F_29 ( & V_73 ) = V_65 -> V_74 ;
F_30 ( & V_73 ) = V_65 -> V_41 ;
V_71 = F_31 ( V_60 -> V_69 , & V_73 , 1 ,
V_75 , V_76 | V_77 ) ;
if ( V_71 ) {
V_71 -> V_78 = F_25 ;
V_71 -> V_79 = V_9 ;
F_32 ( V_71 ) ;
} else {
}
}
F_33 ( V_60 -> V_69 ) ;
F_11 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_34 ( struct V_8 * V_9 , struct V_33 * V_65 ,
struct V_66 V_67 ,
unsigned V_80 )
{
struct V_5 * V_6 ;
struct V_59 * V_60 ;
unsigned int V_68 , V_81 ;
T_1 V_18 ;
int V_82 = 0 ;
int V_15 , V_83 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
V_68 = V_65 -> V_41 ;
V_81 = V_65 -> V_41 ;
if ( V_6 -> V_37 == 0 )
V_81 -= V_80 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
if ( V_15 <= 8 )
V_83 = V_68 ;
else if ( V_15 <= 16 )
V_83 = V_68 >> 1 ;
else
V_83 = V_68 >> 2 ;
if ( V_60 -> V_84 ) {
struct V_70 * V_71 ;
struct V_72 V_73 ;
F_27 ( V_60 -> V_84 , & V_67 ) ;
if ( ( V_18 & V_85 ) && V_6 -> V_37 == 0 )
V_81 -= V_80 ;
F_28 ( & V_73 , 1 ) ;
F_29 ( & V_73 ) = V_65 -> V_86 ;
F_30 ( & V_73 ) = V_81 ;
V_71 = F_31 ( V_60 -> V_84 , & V_73 , 1 ,
V_87 , V_76 |
V_77 ) ;
if ( V_71 ) {
V_71 -> V_78 = F_23 ;
V_71 -> V_79 = V_9 ;
F_32 ( V_71 ) ;
} else {
}
}
F_33 ( V_60 -> V_84 ) ;
F_11 ( V_9 , 1 , 1 ) ;
F_35 ( & V_60 -> V_63 ) ;
F_36 ( V_6 -> V_88 , V_65 -> V_86 , V_68 ,
V_89 ) ;
if ( V_6 -> V_37 > 0 )
return V_68 ;
F_12 ( V_9 , 0 ) ;
V_82 = V_83 - 1 ;
if ( V_18 & V_85 ) {
V_82 -- ;
if ( F_37 ( F_7 ( V_9 , V_90 )
& V_91 ) ) {
T_1 V_92 ;
V_92 = F_7 ( V_9 , V_93 ) ;
if ( V_15 <= 8 )
( ( V_94 * ) V_65 -> V_43 ) [ V_82 ++ ] = V_92 ;
else if ( V_15 <= 16 )
( ( V_95 * ) V_65 -> V_43 ) [ V_82 ++ ] = V_92 ;
else
( ( T_1 * ) V_65 -> V_43 ) [ V_82 ++ ] = V_92 ;
} else {
int V_38 = F_10 ( V_15 ) ;
F_38 ( & V_9 -> V_88 , L_1 ) ;
V_68 -= ( V_38 << 1 ) ;
F_12 ( V_9 , 1 ) ;
return V_68 ;
}
}
if ( F_37 ( F_7 ( V_9 , V_90 )
& V_91 ) ) {
T_1 V_92 ;
V_92 = F_7 ( V_9 , V_93 ) ;
if ( V_15 <= 8 )
( ( V_94 * ) V_65 -> V_43 ) [ V_82 ] = V_92 ;
else if ( V_15 <= 16 )
( ( V_95 * ) V_65 -> V_43 ) [ V_82 ] = V_92 ;
else
( ( T_1 * ) V_65 -> V_43 ) [ V_82 ] = V_92 ;
} else {
F_38 ( & V_9 -> V_88 , L_2 ) ;
V_68 -= F_10 ( V_15 ) ;
}
F_12 ( V_9 , 1 ) ;
return V_68 ;
}
static unsigned
F_39 ( struct V_8 * V_9 , struct V_33 * V_65 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_59 * V_60 ;
unsigned int V_68 ;
T_1 V_18 ;
V_94 * V_96 ;
const V_94 * V_71 ;
struct V_66 V_67 ;
enum V_97 V_98 ;
unsigned V_80 ;
T_1 V_99 ;
void T_2 * V_100 ;
void T_2 * V_101 ;
int V_102 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
V_18 = F_8 ( V_9 ) ;
if ( V_11 -> V_15 <= 8 ) {
V_98 = V_103 ;
V_80 = 1 ;
} else if ( V_11 -> V_15 <= 16 ) {
V_98 = V_104 ;
V_80 = 2 ;
} else {
V_98 = V_105 ;
V_80 = 4 ;
}
V_68 = V_65 -> V_41 ;
V_99 = 1 ;
if ( V_6 -> V_37 > 0 ) {
if ( V_68 > V_6 -> V_37 )
V_99 = V_6 -> V_37 / V_80 ;
else
V_99 = V_68 / V_80 ;
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_106 = V_11 -> V_107 + V_93 ;
V_67 . V_108 = V_11 -> V_107 + V_109 ;
V_67 . V_110 = V_98 ;
V_67 . V_111 = V_98 ;
V_67 . V_112 = V_99 ;
V_67 . V_113 = V_99 ;
V_96 = V_65 -> V_43 ;
V_71 = V_65 -> V_44 ;
if ( V_71 != NULL )
F_26 ( V_9 , V_65 , V_67 ) ;
if ( V_96 != NULL )
V_68 = F_34 ( V_9 , V_65 , V_67 , V_80 ) ;
if ( V_71 != NULL ) {
F_35 ( & V_60 -> V_64 ) ;
F_36 ( V_6 -> V_88 , V_65 -> V_74 , V_65 -> V_41 ,
V_114 ) ;
if ( V_6 -> V_37 > 0 ) {
V_101 = V_6 -> V_7 + V_115 ;
if ( F_19 ( V_101 ,
V_116 ) < 0 )
F_38 ( & V_9 -> V_88 , L_3 ) ;
F_1 ( V_6 -> V_2 , V_115 ,
V_116 ) ;
}
if ( V_96 == NULL ) {
V_100 = V_11 -> V_7 + V_90 ;
if ( V_6 -> V_37 > 0 ) {
V_102 = F_19 ( V_100 ,
V_117 ) ;
if ( V_102 < 0 )
F_38 ( & V_9 -> V_88 , L_4 ) ;
} else {
V_102 = F_19 ( V_100 ,
V_118 ) ;
if ( V_102 < 0 )
F_38 ( & V_9 -> V_88 , L_5 ) ;
}
if ( V_102 >= 0 &&
( F_19 ( V_100 ,
V_119 ) < 0 ) )
F_38 ( & V_9 -> V_88 , L_6 ) ;
}
}
return V_68 ;
}
static unsigned
F_40 ( struct V_8 * V_9 , struct V_33 * V_65 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_68 , V_120 ;
T_1 V_18 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_121 ;
void T_2 * V_122 ;
void T_2 * V_100 ;
int V_15 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_68 = V_65 -> V_41 ;
V_120 = V_68 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
V_121 = V_7 + V_109 ;
V_122 = V_7 + V_93 ;
V_100 = V_7 + V_90 ;
if ( V_120 < ( V_15 >> 3 ) )
return 0 ;
if ( V_15 <= 8 ) {
V_94 * V_96 ;
const V_94 * V_71 ;
V_96 = V_65 -> V_43 ;
V_71 = V_65 -> V_44 ;
do {
V_120 -= 1 ;
if ( V_71 != NULL ) {
if ( F_19 ( V_100 ,
V_118 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_5 ) ;
goto V_123;
}
F_41 ( & V_9 -> V_88 , L_7 ,
V_15 , * V_71 ) ;
F_3 ( * V_71 ++ , V_121 ) ;
}
if ( V_96 != NULL ) {
if ( F_19 ( V_100 ,
V_91 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_8 ) ;
goto V_123;
}
if ( V_120 == 1 && V_71 == NULL &&
( V_18 & V_85 ) ) {
F_12 ( V_9 , 0 ) ;
* V_96 ++ = F_5 ( V_122 ) ;
F_41 ( & V_9 -> V_88 , L_9 ,
V_15 , * ( V_96 - 1 ) ) ;
if ( F_19 ( V_100 ,
V_91 ) < 0 ) {
F_38 ( & V_9 -> V_88 ,
L_8 ) ;
goto V_123;
}
V_120 = 0 ;
} else if ( V_120 == 0 && V_71 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_96 ++ = F_5 ( V_122 ) ;
F_41 ( & V_9 -> V_88 , L_9 ,
V_15 , * ( V_96 - 1 ) ) ;
}
} while ( V_120 );
} else if ( V_15 <= 16 ) {
V_95 * V_96 ;
const V_95 * V_71 ;
V_96 = V_65 -> V_43 ;
V_71 = V_65 -> V_44 ;
do {
V_120 -= 2 ;
if ( V_71 != NULL ) {
if ( F_19 ( V_100 ,
V_118 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_5 ) ;
goto V_123;
}
F_41 ( & V_9 -> V_88 , L_10 ,
V_15 , * V_71 ) ;
F_3 ( * V_71 ++ , V_121 ) ;
}
if ( V_96 != NULL ) {
if ( F_19 ( V_100 ,
V_91 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_8 ) ;
goto V_123;
}
if ( V_120 == 2 && V_71 == NULL &&
( V_18 & V_85 ) ) {
F_12 ( V_9 , 0 ) ;
* V_96 ++ = F_5 ( V_122 ) ;
F_41 ( & V_9 -> V_88 , L_11 ,
V_15 , * ( V_96 - 1 ) ) ;
if ( F_19 ( V_100 ,
V_91 ) < 0 ) {
F_38 ( & V_9 -> V_88 ,
L_8 ) ;
goto V_123;
}
V_120 = 0 ;
} else if ( V_120 == 0 && V_71 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_96 ++ = F_5 ( V_122 ) ;
F_41 ( & V_9 -> V_88 , L_11 ,
V_15 , * ( V_96 - 1 ) ) ;
}
} while ( V_120 >= 2 );
} else if ( V_15 <= 32 ) {
T_1 * V_96 ;
const T_1 * V_71 ;
V_96 = V_65 -> V_43 ;
V_71 = V_65 -> V_44 ;
do {
V_120 -= 4 ;
if ( V_71 != NULL ) {
if ( F_19 ( V_100 ,
V_118 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_5 ) ;
goto V_123;
}
F_41 ( & V_9 -> V_88 , L_12 ,
V_15 , * V_71 ) ;
F_3 ( * V_71 ++ , V_121 ) ;
}
if ( V_96 != NULL ) {
if ( F_19 ( V_100 ,
V_91 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_8 ) ;
goto V_123;
}
if ( V_120 == 4 && V_71 == NULL &&
( V_18 & V_85 ) ) {
F_12 ( V_9 , 0 ) ;
* V_96 ++ = F_5 ( V_122 ) ;
F_41 ( & V_9 -> V_88 , L_13 ,
V_15 , * ( V_96 - 1 ) ) ;
if ( F_19 ( V_100 ,
V_91 ) < 0 ) {
F_38 ( & V_9 -> V_88 ,
L_8 ) ;
goto V_123;
}
V_120 = 0 ;
} else if ( V_120 == 0 && V_71 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_96 ++ = F_5 ( V_122 ) ;
F_41 ( & V_9 -> V_88 , L_13 ,
V_15 , * ( V_96 - 1 ) ) ;
}
} while ( V_120 >= 4 );
}
if ( V_65 -> V_43 == NULL ) {
if ( F_19 ( V_100 ,
V_118 ) < 0 ) {
F_38 ( & V_9 -> V_88 , L_5 ) ;
} else if ( F_19 ( V_100 ,
V_119 ) < 0 )
F_38 ( & V_9 -> V_88 , L_6 ) ;
F_12 ( V_9 , 0 ) ;
}
V_123:
F_12 ( V_9 , 1 ) ;
return V_68 - V_120 ;
}
static T_1 F_42 ( T_1 V_124 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_124 >= ( V_125 >> div ) )
return div ;
return 15 ;
}
static int F_43 ( struct V_8 * V_9 ,
struct V_33 * V_34 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_50 ;
T_1 V_18 = 0 , div = 0 ;
V_94 V_15 = V_9 -> V_126 ;
T_1 V_124 = V_9 -> V_127 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_50 = V_6 -> V_2 ;
if ( V_34 != NULL && V_34 -> V_126 )
V_15 = V_34 -> V_126 ;
V_11 -> V_15 = V_15 ;
if ( V_34 && V_34 -> V_124 )
V_124 = V_34 -> V_124 ;
V_124 = F_44 ( T_1 , V_124 , V_125 ) ;
div = F_42 ( V_124 ) ;
V_18 = F_8 ( V_9 ) ;
if ( V_6 -> V_128 == V_129 ) {
V_18 &= ~ V_130 ;
V_18 &= ~ V_131 ;
V_18 |= V_132 ;
} else {
V_18 |= V_130 ;
V_18 |= V_131 ;
V_18 &= ~ V_132 ;
}
V_18 &= ~ V_133 ;
V_18 |= ( V_15 - 1 ) << 7 ;
if ( ! ( V_9 -> V_134 & V_135 ) )
V_18 |= V_136 ;
else
V_18 &= ~ V_136 ;
V_18 &= ~ V_137 ;
V_18 |= div << 2 ;
if ( V_9 -> V_134 & V_138 )
V_18 |= V_139 ;
else
V_18 &= ~ V_139 ;
if ( V_9 -> V_134 & V_140 )
V_18 |= V_141 ;
else
V_18 &= ~ V_141 ;
F_9 ( V_9 , V_18 ) ;
F_45 ( & V_9 -> V_88 , L_14 ,
V_125 >> div ,
( V_9 -> V_134 & V_140 ) ? L_15 : L_16 ,
( V_9 -> V_134 & V_138 ) ? L_17 : L_18 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_59 * V_60 ;
T_3 V_142 ;
unsigned V_143 ;
V_6 = F_2 ( V_2 ) ;
V_60 = V_6 -> V_61 + V_9 -> V_62 ;
F_47 ( & V_60 -> V_63 ) ;
F_47 ( & V_60 -> V_64 ) ;
F_48 ( V_142 ) ;
F_49 ( V_144 , V_142 ) ;
V_143 = V_60 -> V_145 ;
V_60 -> V_84 =
F_50 ( V_142 , V_146 ,
& V_143 , & V_2 -> V_88 ,
V_60 -> V_147 ) ;
if ( ! V_60 -> V_84 )
goto V_148;
V_143 = V_60 -> V_149 ;
V_60 -> V_69 =
F_50 ( V_142 , V_146 ,
& V_143 , & V_2 -> V_88 ,
V_60 -> V_150 ) ;
if ( ! V_60 -> V_69 ) {
F_51 ( V_60 -> V_84 ) ;
V_60 -> V_84 = NULL ;
goto V_148;
}
return 0 ;
V_148:
F_52 ( & V_9 -> V_88 , L_19 ) ;
return - V_151 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_152 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_59 * V_60 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
if ( ! V_11 ) {
V_11 = F_54 ( sizeof *V_11 , V_153 ) ;
if ( ! V_11 )
return - V_154 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_62 * 0x14 ;
V_11 -> V_107 = V_6 -> V_107 + V_9 -> V_62 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_55 ( & V_11 -> V_155 , & V_27 -> V_11 ) ;
}
if ( ! V_60 -> V_84 || ! V_60 -> V_69 ) {
V_152 = F_46 ( V_9 ) ;
if ( V_152 < 0 && V_152 != - V_151 )
return V_152 ;
}
V_152 = F_56 ( V_6 -> V_88 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_43 ( V_9 , NULL ) ;
F_57 ( V_6 -> V_88 ) ;
F_58 ( V_6 -> V_88 ) ;
return V_152 ;
}
static void F_59 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_59 * V_60 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_60 ( & V_11 -> V_155 ) ;
F_61 ( V_11 ) ;
}
if ( V_9 -> V_62 < V_9 -> V_2 -> V_156 ) {
V_60 = & V_6 -> V_61 [ V_9 -> V_62 ] ;
if ( V_60 -> V_84 ) {
F_51 ( V_60 -> V_84 ) ;
V_60 -> V_84 = NULL ;
}
if ( V_60 -> V_69 ) {
F_51 ( V_60 -> V_69 ) ;
V_60 -> V_69 = NULL ;
}
}
}
static void F_62 ( struct V_5 * V_6 , struct V_157 * V_158 )
{
struct V_8 * V_9 ;
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_159 * V_160 ;
int V_161 = 0 ;
int V_162 = 0 ;
T_1 V_39 ;
V_9 = V_158 -> V_9 ;
V_2 = V_9 -> V_2 ;
V_60 = V_6 -> V_61 + V_9 -> V_62 ;
V_11 = V_9 -> V_12 ;
V_160 = V_9 -> V_163 ;
F_12 ( V_9 , 0 ) ;
F_18 (t, &m->transfers, transfer_list) {
if ( V_34 -> V_44 == NULL && V_34 -> V_43 == NULL && V_34 -> V_41 ) {
V_162 = - V_164 ;
break;
}
if ( V_161 || V_34 -> V_124 || V_34 -> V_126 ) {
V_161 = 1 ;
V_162 = F_43 ( V_9 , V_34 ) ;
if ( V_162 < 0 )
break;
if ( ! V_34 -> V_124 && ! V_34 -> V_126 )
V_161 = 0 ;
}
if ( V_160 && V_160 -> V_165 ) {
V_39 = V_6 -> V_27 . V_32 ;
V_39 &= ~ V_31 ;
F_1 ( V_2 , V_28 , V_39 ) ;
V_6 -> V_27 . V_32 =
F_7 ( V_9 , V_28 ) ;
}
if ( ! V_24 ) {
F_13 ( V_9 , 1 ) ;
V_24 = 1 ;
}
V_39 = F_8 ( V_9 ) ;
V_39 &= ~ V_166 ;
V_39 &= ~ V_85 ;
if ( V_34 -> V_44 == NULL )
V_39 |= V_167 ;
else if ( V_34 -> V_43 == NULL )
V_39 |= V_168 ;
if ( V_160 && V_160 -> V_169 && V_34 -> V_44 == NULL ) {
if ( V_34 -> V_41 > ( ( V_11 -> V_15 + 7 ) >> 3 ) )
V_39 |= V_85 ;
}
F_9 ( V_9 , V_39 ) ;
if ( V_34 -> V_41 ) {
unsigned V_68 ;
if ( ( V_60 -> V_84 && V_60 -> V_69 ) &&
( V_158 -> V_170 || V_34 -> V_41 >= V_171 ) )
F_15 ( V_9 , V_34 , 1 ) ;
F_12 ( V_9 , 1 ) ;
if ( V_34 -> V_44 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_109 ) ;
if ( ( V_60 -> V_84 && V_60 -> V_69 ) &&
( V_158 -> V_170 || V_34 -> V_41 >= V_171 ) )
V_68 = F_39 ( V_9 , V_34 ) ;
else
V_68 = F_40 ( V_9 , V_34 ) ;
V_158 -> V_172 += V_68 ;
if ( V_68 != V_34 -> V_41 ) {
V_162 = - V_173 ;
break;
}
}
if ( V_34 -> V_174 )
F_63 ( V_34 -> V_174 ) ;
if ( V_34 -> V_175 ) {
F_13 ( V_9 , 0 ) ;
V_24 = 0 ;
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_37 > 0 )
F_15 ( V_9 , V_34 , 0 ) ;
}
if ( V_161 ) {
V_161 = 0 ;
V_162 = F_43 ( V_9 , NULL ) ;
}
if ( V_24 )
F_13 ( V_9 , 0 ) ;
if ( V_160 && V_160 -> V_165 ) {
V_39 = V_6 -> V_27 . V_32 ;
V_39 |= V_31 ;
F_1 ( V_2 , V_28 , V_39 ) ;
V_6 -> V_27 . V_32 =
F_7 ( V_9 , V_28 ) ;
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_37 > 0 && V_34 )
F_15 ( V_9 , V_34 , 0 ) ;
V_158 -> V_162 = V_162 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_157 * V_158 )
{
struct V_8 * V_9 ;
struct V_5 * V_6 ;
struct V_59 * V_60 ;
struct V_33 * V_34 ;
V_9 = V_158 -> V_9 ;
V_6 = F_2 ( V_2 ) ;
V_60 = V_6 -> V_61 + V_9 -> V_62 ;
V_158 -> V_172 = 0 ;
V_158 -> V_162 = 0 ;
if ( F_65 ( & V_158 -> V_176 ) )
return - V_164 ;
F_18 (t, &m->transfers, transfer_list) {
const void * V_44 = V_34 -> V_44 ;
void * V_43 = V_34 -> V_43 ;
unsigned V_41 = V_34 -> V_41 ;
if ( V_34 -> V_124 > V_125
|| ( V_41 && ! ( V_43 || V_44 ) ) ) {
F_45 ( V_6 -> V_88 , L_20 ,
V_34 -> V_124 ,
V_41 ,
V_44 ? L_21 : L_22 ,
V_43 ? L_23 : L_22 ,
V_34 -> V_126 ) ;
return - V_164 ;
}
if ( V_34 -> V_124 && V_34 -> V_124 < ( V_125 >> 15 ) ) {
F_45 ( V_6 -> V_88 , L_24 ,
V_34 -> V_124 ,
V_125 >> 15 ) ;
return - V_164 ;
}
if ( V_158 -> V_170 || V_41 < V_171 )
continue;
if ( V_60 -> V_69 && V_44 != NULL ) {
V_34 -> V_74 = F_66 ( V_6 -> V_88 , ( void * ) V_44 ,
V_41 , V_114 ) ;
if ( F_67 ( V_6 -> V_88 , V_34 -> V_74 ) ) {
F_45 ( V_6 -> V_88 , L_25 ,
'T' , V_41 ) ;
return - V_164 ;
}
}
if ( V_60 -> V_84 && V_43 != NULL ) {
V_34 -> V_86 = F_66 ( V_6 -> V_88 , V_43 , V_34 -> V_41 ,
V_89 ) ;
if ( F_67 ( V_6 -> V_88 , V_34 -> V_86 ) ) {
F_45 ( V_6 -> V_88 , L_25 ,
'R' , V_41 ) ;
if ( V_44 != NULL )
F_36 ( V_6 -> V_88 , V_34 -> V_74 ,
V_41 , V_114 ) ;
return - V_164 ;
}
}
}
F_62 ( V_6 , V_158 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_26 * V_27 = & V_6 -> V_27 ;
int V_152 = 0 ;
V_152 = F_56 ( V_6 -> V_88 ) ;
if ( V_152 < 0 )
return V_152 ;
F_1 ( V_2 , V_51 ,
V_177 ) ;
V_27 -> V_52 = V_177 ;
F_14 ( V_2 ) ;
F_57 ( V_6 -> V_88 ) ;
F_58 ( V_6 -> V_88 ) ;
return 0 ;
}
static int F_70 ( struct V_178 * V_88 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_71 ( V_88 ) ;
V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int F_72 ( struct V_179 * V_180 )
{
struct V_1 * V_2 ;
const struct V_181 * V_182 ;
struct V_5 * V_6 ;
struct V_183 * V_184 ;
int V_162 = 0 , V_185 ;
T_1 V_186 = 0 ;
static int V_187 = 1 ;
struct V_188 * V_155 = V_180 -> V_88 . V_189 ;
const struct V_190 * V_191 ;
V_2 = F_73 ( & V_180 -> V_88 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_45 ( & V_180 -> V_88 , L_26 ) ;
return - V_154 ;
}
V_2 -> V_192 = V_138 | V_140 | V_135 ;
V_2 -> V_193 = F_74 ( 4 , 32 ) ;
V_2 -> V_194 = F_53 ;
V_2 -> V_195 = true ;
V_2 -> V_196 = F_64 ;
V_2 -> V_197 = F_59 ;
V_2 -> V_88 . V_189 = V_155 ;
F_75 ( V_180 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_191 = F_76 ( V_198 , & V_180 -> V_88 ) ;
if ( V_191 ) {
T_1 V_199 = 1 ;
V_182 = V_191 -> V_58 ;
F_77 ( V_155 , L_27 , & V_199 ) ;
V_2 -> V_156 = V_199 ;
V_2 -> V_187 = V_187 ++ ;
if ( F_78 ( V_155 , L_28 , NULL ) )
V_6 -> V_128 = V_200 ;
} else {
V_182 = F_79 ( & V_180 -> V_88 ) ;
V_2 -> V_156 = V_182 -> V_199 ;
if ( V_180 -> V_201 != - 1 )
V_2 -> V_187 = V_180 -> V_201 ;
V_6 -> V_128 = V_182 -> V_128 ;
}
V_186 = V_182 -> V_186 ;
V_184 = F_80 ( V_180 , V_202 , 0 ) ;
if ( V_184 == NULL ) {
V_162 = - V_203 ;
goto V_204;
}
V_184 -> V_205 += V_186 ;
V_184 -> V_206 += V_186 ;
V_6 -> V_107 = V_184 -> V_205 ;
V_6 -> V_7 = F_81 ( & V_180 -> V_88 , V_184 ) ;
if ( F_82 ( V_6 -> V_7 ) ) {
V_162 = F_83 ( V_6 -> V_7 ) ;
goto V_204;
}
V_6 -> V_88 = & V_180 -> V_88 ;
F_84 ( & V_6 -> V_27 . V_11 ) ;
V_6 -> V_61 = F_85 ( V_2 -> V_156 ,
sizeof( struct V_59 ) ,
V_153 ) ;
if ( V_6 -> V_61 == NULL )
goto V_204;
for ( V_185 = 0 ; V_185 < V_2 -> V_156 ; V_185 ++ ) {
char * V_147 = V_6 -> V_61 [ V_185 ] . V_147 ;
char * V_150 = V_6 -> V_61 [ V_185 ] . V_150 ;
struct V_183 * V_207 ;
sprintf ( V_147 , L_29 , V_185 ) ;
if ( ! V_180 -> V_88 . V_189 ) {
V_207 =
F_86 ( V_180 ,
V_208 ,
V_147 ) ;
if ( ! V_207 ) {
F_45 ( & V_180 -> V_88 ,
L_30 ) ;
V_162 = - V_203 ;
break;
}
V_6 -> V_61 [ V_185 ] . V_145 =
V_207 -> V_205 ;
}
sprintf ( V_150 , L_31 , V_185 ) ;
if ( ! V_180 -> V_88 . V_189 ) {
V_207 =
F_86 ( V_180 ,
V_208 ,
V_150 ) ;
if ( ! V_207 ) {
F_45 ( & V_180 -> V_88 ,
L_32 ) ;
V_162 = - V_203 ;
break;
}
V_6 -> V_61 [ V_185 ] . V_149 =
V_207 -> V_205 ;
}
}
if ( V_162 < 0 )
goto V_209;
F_87 ( & V_180 -> V_88 ) ;
F_88 ( & V_180 -> V_88 , V_210 ) ;
F_89 ( & V_180 -> V_88 ) ;
V_162 = F_69 ( V_6 ) ;
if ( V_162 < 0 )
goto V_211;
V_162 = F_90 ( & V_180 -> V_88 , V_2 ) ;
if ( V_162 < 0 )
goto V_211;
return V_162 ;
V_211:
F_91 ( & V_180 -> V_88 ) ;
V_209:
F_61 ( V_6 -> V_61 ) ;
V_204:
F_92 ( V_2 ) ;
return V_162 ;
}
static int F_93 ( struct V_179 * V_180 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_59 * V_61 ;
V_2 = F_94 ( V_180 ) ;
V_6 = F_2 ( V_2 ) ;
V_61 = V_6 -> V_61 ;
F_95 ( V_6 -> V_88 ) ;
F_91 ( & V_180 -> V_88 ) ;
F_61 ( V_61 ) ;
return 0 ;
}
static int F_96 ( struct V_178 * V_88 )
{
struct V_1 * V_2 = F_71 ( V_88 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_10 * V_11 ;
F_56 ( V_6 -> V_88 ) ;
F_18 (cs, &ctx->cs, node) {
if ( ( V_11 -> V_13 & V_25 ) == 0 ) {
V_11 -> V_13 |= V_25 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
V_11 -> V_13 &= ~ V_25 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_57 ( V_6 -> V_88 ) ;
F_58 ( V_6 -> V_88 ) ;
return 0 ;
}
