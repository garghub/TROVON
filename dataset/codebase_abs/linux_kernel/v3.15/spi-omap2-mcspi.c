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
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_18 ;
V_18 = V_11 -> V_22 ;
if ( V_17 )
V_18 |= V_23 ;
else
V_18 &= ~ V_23 ;
V_11 -> V_22 = V_18 ;
F_6 ( V_9 , V_24 , V_11 -> V_22 ) ;
F_7 ( V_9 , V_24 ) ;
}
static void F_13 ( struct V_8 * V_9 , int V_25 )
{
T_1 V_18 ;
V_18 = F_8 ( V_9 ) ;
if ( V_25 )
V_18 |= V_26 ;
else
V_18 &= ~ V_26 ;
F_9 ( V_9 , V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_6 -> V_28 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 , V_29 ) ;
V_18 &= ~ ( V_30 | V_31 ) ;
V_18 |= V_32 ;
F_1 ( V_2 , V_29 , V_18 ) ;
V_28 -> V_33 = V_18 ;
}
static void F_15 ( const struct V_8 * V_9 ,
struct V_34 * V_35 , int V_17 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
unsigned int V_36 ;
int V_37 , V_38 , V_39 ;
T_1 V_40 , V_41 ;
V_6 = F_2 ( V_2 ) ;
V_40 = F_8 ( V_9 ) ;
if ( V_17 ) {
V_39 = F_10 ( V_11 -> V_15 ) ;
if ( V_35 -> V_42 % V_39 != 0 )
goto V_43;
if ( V_35 -> V_44 != NULL && V_35 -> V_45 != NULL )
V_37 = V_46 / 2 ;
else
V_37 = V_46 ;
V_38 = F_16 ( V_35 -> V_42 , V_37 ) ;
if ( V_38 < 2 || V_38 % V_39 != 0 )
goto V_43;
V_36 = V_35 -> V_42 / V_39 ;
if ( V_36 > V_47 )
goto V_43;
V_41 = V_36 << 16 ;
if ( V_35 -> V_44 != NULL ) {
V_40 |= V_48 ;
V_41 |= ( V_38 - 1 ) << 8 ;
}
if ( V_35 -> V_45 != NULL ) {
V_40 |= V_49 ;
V_41 |= V_38 - 1 ;
}
F_1 ( V_2 , V_50 , V_41 ) ;
F_9 ( V_9 , V_40 ) ;
V_6 -> V_38 = V_38 ;
return;
}
V_43:
if ( V_35 -> V_44 != NULL )
V_40 &= ~ V_48 ;
else
V_40 &= ~ V_49 ;
F_9 ( V_9 , V_40 ) ;
V_6 -> V_38 = 0 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_51 = V_6 -> V_2 ;
struct V_27 * V_28 = & V_6 -> V_28 ;
struct V_10 * V_11 ;
F_1 ( V_51 , V_29 , V_28 -> V_33 ) ;
F_1 ( V_51 , V_52 , V_28 -> V_53 ) ;
F_18 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static int F_19 ( void T_2 * V_54 , unsigned long V_55 )
{
unsigned long V_56 ;
V_56 = V_57 + F_20 ( 1000 ) ;
while ( ! ( F_5 ( V_54 ) & V_55 ) ) {
if ( F_21 ( V_57 , V_56 ) ) {
if ( ! ( F_5 ( V_54 ) & V_55 ) )
return - V_58 ;
else
return 0 ;
}
F_22 () ;
}
return 0 ;
}
static void F_23 ( void * V_59 )
{
struct V_8 * V_9 = V_59 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_60 * V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
F_11 ( V_9 , 1 , 0 ) ;
F_24 ( & V_61 -> V_64 ) ;
}
static void F_25 ( void * V_59 )
{
struct V_8 * V_9 = V_59 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_60 * V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
F_11 ( V_9 , 0 , 0 ) ;
F_24 ( & V_61 -> V_65 ) ;
}
static void F_26 ( struct V_8 * V_9 ,
struct V_34 * V_66 ,
struct V_67 V_68 )
{
struct V_5 * V_6 ;
struct V_60 * V_61 ;
unsigned int V_69 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
V_69 = V_66 -> V_42 ;
if ( V_61 -> V_70 ) {
struct V_71 * V_72 ;
struct V_73 V_74 ;
F_27 ( V_61 -> V_70 , & V_68 ) ;
F_28 ( & V_74 , 1 ) ;
F_29 ( & V_74 ) = V_66 -> V_75 ;
F_30 ( & V_74 ) = V_66 -> V_42 ;
V_72 = F_31 ( V_61 -> V_70 , & V_74 , 1 ,
V_76 , V_77 | V_78 ) ;
if ( V_72 ) {
V_72 -> V_79 = F_25 ;
V_72 -> V_80 = V_9 ;
F_32 ( V_72 ) ;
} else {
}
}
F_33 ( V_61 -> V_70 ) ;
F_11 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_34 ( struct V_8 * V_9 , struct V_34 * V_66 ,
struct V_67 V_68 ,
unsigned V_81 )
{
struct V_5 * V_6 ;
struct V_60 * V_61 ;
unsigned int V_69 , V_82 ;
T_1 V_18 ;
int V_83 = 0 ;
int V_15 , V_84 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
V_69 = V_66 -> V_42 ;
V_82 = V_66 -> V_42 ;
if ( V_6 -> V_38 == 0 )
V_82 -= V_81 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
if ( V_15 <= 8 )
V_84 = V_69 ;
else if ( V_15 <= 16 )
V_84 = V_69 >> 1 ;
else
V_84 = V_69 >> 2 ;
if ( V_61 -> V_85 ) {
struct V_71 * V_72 ;
struct V_73 V_74 ;
F_27 ( V_61 -> V_85 , & V_68 ) ;
if ( ( V_18 & V_86 ) && V_6 -> V_38 == 0 )
V_82 -= V_81 ;
F_28 ( & V_74 , 1 ) ;
F_29 ( & V_74 ) = V_66 -> V_87 ;
F_30 ( & V_74 ) = V_82 ;
V_72 = F_31 ( V_61 -> V_85 , & V_74 , 1 ,
V_88 , V_77 |
V_78 ) ;
if ( V_72 ) {
V_72 -> V_79 = F_23 ;
V_72 -> V_80 = V_9 ;
F_32 ( V_72 ) ;
} else {
}
}
F_33 ( V_61 -> V_85 ) ;
F_11 ( V_9 , 1 , 1 ) ;
F_35 ( & V_61 -> V_64 ) ;
F_36 ( V_6 -> V_89 , V_66 -> V_87 , V_69 ,
V_90 ) ;
if ( V_6 -> V_38 > 0 )
return V_69 ;
F_12 ( V_9 , 0 ) ;
V_83 = V_84 - 1 ;
if ( V_18 & V_86 ) {
V_83 -- ;
if ( F_37 ( F_7 ( V_9 , V_91 )
& V_92 ) ) {
T_1 V_93 ;
V_93 = F_7 ( V_9 , V_94 ) ;
if ( V_15 <= 8 )
( ( V_95 * ) V_66 -> V_44 ) [ V_83 ++ ] = V_93 ;
else if ( V_15 <= 16 )
( ( V_96 * ) V_66 -> V_44 ) [ V_83 ++ ] = V_93 ;
else
( ( T_1 * ) V_66 -> V_44 ) [ V_83 ++ ] = V_93 ;
} else {
int V_39 = F_10 ( V_15 ) ;
F_38 ( & V_9 -> V_89 , L_1 ) ;
V_69 -= ( V_39 << 1 ) ;
F_12 ( V_9 , 1 ) ;
return V_69 ;
}
}
if ( F_37 ( F_7 ( V_9 , V_91 )
& V_92 ) ) {
T_1 V_93 ;
V_93 = F_7 ( V_9 , V_94 ) ;
if ( V_15 <= 8 )
( ( V_95 * ) V_66 -> V_44 ) [ V_83 ] = V_93 ;
else if ( V_15 <= 16 )
( ( V_96 * ) V_66 -> V_44 ) [ V_83 ] = V_93 ;
else
( ( T_1 * ) V_66 -> V_44 ) [ V_83 ] = V_93 ;
} else {
F_38 ( & V_9 -> V_89 , L_2 ) ;
V_69 -= F_10 ( V_15 ) ;
}
F_12 ( V_9 , 1 ) ;
return V_69 ;
}
static unsigned
F_39 ( struct V_8 * V_9 , struct V_34 * V_66 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_60 * V_61 ;
unsigned int V_69 ;
T_1 V_18 ;
V_95 * V_97 ;
const V_95 * V_72 ;
struct V_67 V_68 ;
enum V_98 V_99 ;
unsigned V_81 ;
T_1 V_100 ;
void T_2 * V_101 ;
void T_2 * V_102 ;
int V_103 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
V_18 = F_8 ( V_9 ) ;
if ( V_11 -> V_15 <= 8 ) {
V_99 = V_104 ;
V_81 = 1 ;
} else if ( V_11 -> V_15 <= 16 ) {
V_99 = V_105 ;
V_81 = 2 ;
} else {
V_99 = V_106 ;
V_81 = 4 ;
}
V_69 = V_66 -> V_42 ;
V_100 = 1 ;
if ( V_6 -> V_38 > 0 ) {
if ( V_69 > V_6 -> V_38 )
V_100 = V_6 -> V_38 / V_81 ;
else
V_100 = V_69 / V_81 ;
}
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_107 = V_11 -> V_108 + V_94 ;
V_68 . V_109 = V_11 -> V_108 + V_110 ;
V_68 . V_111 = V_99 ;
V_68 . V_112 = V_99 ;
V_68 . V_113 = V_100 ;
V_68 . V_114 = V_100 ;
V_97 = V_66 -> V_44 ;
V_72 = V_66 -> V_45 ;
if ( V_72 != NULL )
F_26 ( V_9 , V_66 , V_68 ) ;
if ( V_97 != NULL )
V_69 = F_34 ( V_9 , V_66 , V_68 , V_81 ) ;
if ( V_72 != NULL ) {
F_35 ( & V_61 -> V_65 ) ;
F_36 ( V_6 -> V_89 , V_66 -> V_75 , V_66 -> V_42 ,
V_115 ) ;
if ( V_6 -> V_38 > 0 ) {
V_102 = V_6 -> V_7 + V_116 ;
if ( F_19 ( V_102 ,
V_117 ) < 0 )
F_38 ( & V_9 -> V_89 , L_3 ) ;
F_1 ( V_6 -> V_2 , V_116 ,
V_117 ) ;
}
if ( V_97 == NULL ) {
V_101 = V_11 -> V_7 + V_91 ;
if ( V_6 -> V_38 > 0 ) {
V_103 = F_19 ( V_101 ,
V_118 ) ;
if ( V_103 < 0 )
F_38 ( & V_9 -> V_89 , L_4 ) ;
} else {
V_103 = F_19 ( V_101 ,
V_119 ) ;
if ( V_103 < 0 )
F_38 ( & V_9 -> V_89 , L_5 ) ;
}
if ( V_103 >= 0 &&
( F_19 ( V_101 ,
V_120 ) < 0 ) )
F_38 ( & V_9 -> V_89 , L_6 ) ;
}
}
return V_69 ;
}
static unsigned
F_40 ( struct V_8 * V_9 , struct V_34 * V_66 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_69 , V_121 ;
T_1 V_18 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_122 ;
void T_2 * V_123 ;
void T_2 * V_101 ;
int V_15 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_69 = V_66 -> V_42 ;
V_121 = V_69 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
V_122 = V_7 + V_110 ;
V_123 = V_7 + V_94 ;
V_101 = V_7 + V_91 ;
if ( V_121 < ( V_15 >> 3 ) )
return 0 ;
if ( V_15 <= 8 ) {
V_95 * V_97 ;
const V_95 * V_72 ;
V_97 = V_66 -> V_44 ;
V_72 = V_66 -> V_45 ;
do {
V_121 -= 1 ;
if ( V_72 != NULL ) {
if ( F_19 ( V_101 ,
V_119 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_5 ) ;
goto V_124;
}
F_41 ( & V_9 -> V_89 , L_7 ,
V_15 , * V_72 ) ;
F_3 ( * V_72 ++ , V_122 ) ;
}
if ( V_97 != NULL ) {
if ( F_19 ( V_101 ,
V_92 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_8 ) ;
goto V_124;
}
if ( V_121 == 1 && V_72 == NULL &&
( V_18 & V_86 ) ) {
F_12 ( V_9 , 0 ) ;
* V_97 ++ = F_5 ( V_123 ) ;
F_41 ( & V_9 -> V_89 , L_9 ,
V_15 , * ( V_97 - 1 ) ) ;
if ( F_19 ( V_101 ,
V_92 ) < 0 ) {
F_38 ( & V_9 -> V_89 ,
L_8 ) ;
goto V_124;
}
V_121 = 0 ;
} else if ( V_121 == 0 && V_72 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_97 ++ = F_5 ( V_123 ) ;
F_41 ( & V_9 -> V_89 , L_9 ,
V_15 , * ( V_97 - 1 ) ) ;
}
} while ( V_121 );
} else if ( V_15 <= 16 ) {
V_96 * V_97 ;
const V_96 * V_72 ;
V_97 = V_66 -> V_44 ;
V_72 = V_66 -> V_45 ;
do {
V_121 -= 2 ;
if ( V_72 != NULL ) {
if ( F_19 ( V_101 ,
V_119 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_5 ) ;
goto V_124;
}
F_41 ( & V_9 -> V_89 , L_10 ,
V_15 , * V_72 ) ;
F_3 ( * V_72 ++ , V_122 ) ;
}
if ( V_97 != NULL ) {
if ( F_19 ( V_101 ,
V_92 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_8 ) ;
goto V_124;
}
if ( V_121 == 2 && V_72 == NULL &&
( V_18 & V_86 ) ) {
F_12 ( V_9 , 0 ) ;
* V_97 ++ = F_5 ( V_123 ) ;
F_41 ( & V_9 -> V_89 , L_11 ,
V_15 , * ( V_97 - 1 ) ) ;
if ( F_19 ( V_101 ,
V_92 ) < 0 ) {
F_38 ( & V_9 -> V_89 ,
L_8 ) ;
goto V_124;
}
V_121 = 0 ;
} else if ( V_121 == 0 && V_72 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_97 ++ = F_5 ( V_123 ) ;
F_41 ( & V_9 -> V_89 , L_11 ,
V_15 , * ( V_97 - 1 ) ) ;
}
} while ( V_121 >= 2 );
} else if ( V_15 <= 32 ) {
T_1 * V_97 ;
const T_1 * V_72 ;
V_97 = V_66 -> V_44 ;
V_72 = V_66 -> V_45 ;
do {
V_121 -= 4 ;
if ( V_72 != NULL ) {
if ( F_19 ( V_101 ,
V_119 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_5 ) ;
goto V_124;
}
F_41 ( & V_9 -> V_89 , L_12 ,
V_15 , * V_72 ) ;
F_3 ( * V_72 ++ , V_122 ) ;
}
if ( V_97 != NULL ) {
if ( F_19 ( V_101 ,
V_92 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_8 ) ;
goto V_124;
}
if ( V_121 == 4 && V_72 == NULL &&
( V_18 & V_86 ) ) {
F_12 ( V_9 , 0 ) ;
* V_97 ++ = F_5 ( V_123 ) ;
F_41 ( & V_9 -> V_89 , L_13 ,
V_15 , * ( V_97 - 1 ) ) ;
if ( F_19 ( V_101 ,
V_92 ) < 0 ) {
F_38 ( & V_9 -> V_89 ,
L_8 ) ;
goto V_124;
}
V_121 = 0 ;
} else if ( V_121 == 0 && V_72 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_97 ++ = F_5 ( V_123 ) ;
F_41 ( & V_9 -> V_89 , L_13 ,
V_15 , * ( V_97 - 1 ) ) ;
}
} while ( V_121 >= 4 );
}
if ( V_66 -> V_44 == NULL ) {
if ( F_19 ( V_101 ,
V_119 ) < 0 ) {
F_38 ( & V_9 -> V_89 , L_5 ) ;
} else if ( F_19 ( V_101 ,
V_120 ) < 0 )
F_38 ( & V_9 -> V_89 , L_6 ) ;
F_12 ( V_9 , 0 ) ;
}
V_124:
F_12 ( V_9 , 1 ) ;
return V_69 - V_121 ;
}
static T_1 F_42 ( T_1 V_125 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_125 >= ( V_126 >> div ) )
return div ;
return 15 ;
}
static int F_43 ( struct V_8 * V_9 ,
struct V_34 * V_35 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_51 ;
T_1 V_18 = 0 , V_127 = 0 , div , V_128 = 0 , V_129 = 0 ;
V_95 V_15 = V_9 -> V_130 ;
T_1 V_125 = V_9 -> V_131 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_51 = V_6 -> V_2 ;
if ( V_35 != NULL && V_35 -> V_130 )
V_15 = V_35 -> V_130 ;
V_11 -> V_15 = V_15 ;
if ( V_35 && V_35 -> V_125 )
V_125 = V_35 -> V_125 ;
V_125 = F_44 ( T_1 , V_125 , V_126 ) ;
if ( V_125 < ( V_126 / V_132 ) ) {
V_127 = F_42 ( V_125 ) ;
V_125 = V_126 >> V_127 ;
V_129 = 0 ;
} else {
div = ( V_126 + V_125 - 1 ) / V_125 ;
V_125 = V_126 / div ;
V_127 = ( div - 1 ) & 0xf ;
V_128 = ( div - 1 ) >> 4 ;
V_129 = V_133 ;
}
V_18 = F_8 ( V_9 ) ;
if ( V_6 -> V_134 == V_135 ) {
V_18 &= ~ V_136 ;
V_18 &= ~ V_137 ;
V_18 |= V_138 ;
} else {
V_18 |= V_136 ;
V_18 |= V_137 ;
V_18 &= ~ V_138 ;
}
V_18 &= ~ V_139 ;
V_18 |= ( V_15 - 1 ) << 7 ;
if ( ! ( V_9 -> V_140 & V_141 ) )
V_18 |= V_142 ;
else
V_18 &= ~ V_142 ;
V_18 &= ~ V_143 ;
V_18 |= V_127 << 2 ;
V_18 &= ~ V_133 ;
V_18 |= V_129 ;
if ( V_129 ) {
V_11 -> V_22 &= ~ V_144 ;
V_11 -> V_22 |= V_128 << 8 ;
F_6 ( V_9 , V_24 , V_11 -> V_22 ) ;
}
if ( V_9 -> V_140 & V_145 )
V_18 |= V_146 ;
else
V_18 &= ~ V_146 ;
if ( V_9 -> V_140 & V_147 )
V_18 |= V_148 ;
else
V_18 &= ~ V_148 ;
F_9 ( V_9 , V_18 ) ;
F_45 ( & V_9 -> V_89 , L_14 ,
V_125 ,
( V_9 -> V_140 & V_147 ) ? L_15 : L_16 ,
( V_9 -> V_140 & V_145 ) ? L_17 : L_18 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_60 * V_61 ;
T_3 V_149 ;
unsigned V_150 ;
V_6 = F_2 ( V_2 ) ;
V_61 = V_6 -> V_62 + V_9 -> V_63 ;
F_47 ( & V_61 -> V_64 ) ;
F_47 ( & V_61 -> V_65 ) ;
F_48 ( V_149 ) ;
F_49 ( V_151 , V_149 ) ;
V_150 = V_61 -> V_152 ;
V_61 -> V_85 =
F_50 ( V_149 , V_153 ,
& V_150 , & V_2 -> V_89 ,
V_61 -> V_154 ) ;
if ( ! V_61 -> V_85 )
goto V_155;
V_150 = V_61 -> V_156 ;
V_61 -> V_70 =
F_50 ( V_149 , V_153 ,
& V_150 , & V_2 -> V_89 ,
V_61 -> V_157 ) ;
if ( ! V_61 -> V_70 ) {
F_51 ( V_61 -> V_85 ) ;
V_61 -> V_85 = NULL ;
goto V_155;
}
return 0 ;
V_155:
F_52 ( & V_9 -> V_89 , L_19 ) ;
return - V_158 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_159 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_27 * V_28 = & V_6 -> V_28 ;
struct V_60 * V_61 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
if ( ! V_11 ) {
V_11 = F_54 ( sizeof *V_11 , V_160 ) ;
if ( ! V_11 )
return - V_161 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_63 * 0x14 ;
V_11 -> V_108 = V_6 -> V_108 + V_9 -> V_63 * 0x14 ;
V_11 -> V_13 = 0 ;
V_11 -> V_22 = 0 ;
V_9 -> V_12 = V_11 ;
F_55 ( & V_11 -> V_162 , & V_28 -> V_11 ) ;
}
if ( ! V_61 -> V_85 || ! V_61 -> V_70 ) {
V_159 = F_46 ( V_9 ) ;
if ( V_159 < 0 && V_159 != - V_158 )
return V_159 ;
}
V_159 = F_56 ( V_6 -> V_89 ) ;
if ( V_159 < 0 )
return V_159 ;
V_159 = F_43 ( V_9 , NULL ) ;
F_57 ( V_6 -> V_89 ) ;
F_58 ( V_6 -> V_89 ) ;
return V_159 ;
}
static void F_59 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_60 * V_61 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_60 ( & V_11 -> V_162 ) ;
F_61 ( V_11 ) ;
}
if ( V_9 -> V_63 < V_9 -> V_2 -> V_163 ) {
V_61 = & V_6 -> V_62 [ V_9 -> V_63 ] ;
if ( V_61 -> V_85 ) {
F_51 ( V_61 -> V_85 ) ;
V_61 -> V_85 = NULL ;
}
if ( V_61 -> V_70 ) {
F_51 ( V_61 -> V_70 ) ;
V_61 -> V_70 = NULL ;
}
}
}
static void F_62 ( struct V_5 * V_6 , struct V_164 * V_165 )
{
struct V_8 * V_9 ;
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
int V_25 = 0 ;
struct V_10 * V_11 ;
struct V_166 * V_167 ;
int V_168 = 0 ;
int V_169 = 0 ;
T_1 V_40 ;
V_9 = V_165 -> V_9 ;
V_2 = V_9 -> V_2 ;
V_61 = V_6 -> V_62 + V_9 -> V_63 ;
V_11 = V_9 -> V_12 ;
V_167 = V_9 -> V_170 ;
F_12 ( V_9 , 0 ) ;
F_18 (t, &m->transfers, transfer_list) {
if ( V_35 -> V_45 == NULL && V_35 -> V_44 == NULL && V_35 -> V_42 ) {
V_169 = - V_171 ;
break;
}
if ( V_168 ||
( V_35 -> V_125 != V_9 -> V_131 ) ||
( V_35 -> V_130 != V_9 -> V_130 ) ) {
V_168 = 1 ;
V_169 = F_43 ( V_9 , V_35 ) ;
if ( V_169 < 0 )
break;
if ( V_35 -> V_125 == V_9 -> V_131 &&
V_35 -> V_130 == V_9 -> V_130 )
V_168 = 0 ;
}
if ( V_167 && V_167 -> V_172 ) {
V_40 = V_6 -> V_28 . V_33 ;
V_40 &= ~ V_32 ;
F_1 ( V_2 , V_29 , V_40 ) ;
V_6 -> V_28 . V_33 =
F_7 ( V_9 , V_29 ) ;
}
if ( ! V_25 ) {
F_13 ( V_9 , 1 ) ;
V_25 = 1 ;
}
V_40 = F_8 ( V_9 ) ;
V_40 &= ~ V_173 ;
V_40 &= ~ V_86 ;
if ( V_35 -> V_45 == NULL )
V_40 |= V_174 ;
else if ( V_35 -> V_44 == NULL )
V_40 |= V_175 ;
if ( V_167 && V_167 -> V_176 && V_35 -> V_45 == NULL ) {
if ( V_35 -> V_42 > ( ( V_11 -> V_15 + 7 ) >> 3 ) )
V_40 |= V_86 ;
}
F_9 ( V_9 , V_40 ) ;
if ( V_35 -> V_42 ) {
unsigned V_69 ;
if ( ( V_61 -> V_85 && V_61 -> V_70 ) &&
( V_165 -> V_177 || V_35 -> V_42 >= V_178 ) )
F_15 ( V_9 , V_35 , 1 ) ;
F_12 ( V_9 , 1 ) ;
if ( V_35 -> V_45 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_110 ) ;
if ( ( V_61 -> V_85 && V_61 -> V_70 ) &&
( V_165 -> V_177 || V_35 -> V_42 >= V_178 ) )
V_69 = F_39 ( V_9 , V_35 ) ;
else
V_69 = F_40 ( V_9 , V_35 ) ;
V_165 -> V_179 += V_69 ;
if ( V_69 != V_35 -> V_42 ) {
V_169 = - V_180 ;
break;
}
}
if ( V_35 -> V_181 )
F_63 ( V_35 -> V_181 ) ;
if ( V_35 -> V_182 ) {
F_13 ( V_9 , 0 ) ;
V_25 = 0 ;
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_38 > 0 )
F_15 ( V_9 , V_35 , 0 ) ;
}
if ( V_168 ) {
V_168 = 0 ;
V_169 = F_43 ( V_9 , NULL ) ;
}
if ( V_25 )
F_13 ( V_9 , 0 ) ;
if ( V_167 && V_167 -> V_172 ) {
V_40 = V_6 -> V_28 . V_33 ;
V_40 |= V_32 ;
F_1 ( V_2 , V_29 , V_40 ) ;
V_6 -> V_28 . V_33 =
F_7 ( V_9 , V_29 ) ;
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_38 > 0 && V_35 )
F_15 ( V_9 , V_35 , 0 ) ;
V_165 -> V_169 = V_169 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_8 * V_9 ;
struct V_5 * V_6 ;
struct V_60 * V_61 ;
struct V_34 * V_35 ;
V_9 = V_165 -> V_9 ;
V_6 = F_2 ( V_2 ) ;
V_61 = V_6 -> V_62 + V_9 -> V_63 ;
V_165 -> V_179 = 0 ;
V_165 -> V_169 = 0 ;
F_18 (t, &m->transfers, transfer_list) {
const void * V_45 = V_35 -> V_45 ;
void * V_44 = V_35 -> V_44 ;
unsigned V_42 = V_35 -> V_42 ;
if ( ( V_42 && ! ( V_44 || V_45 ) ) ) {
F_45 ( V_6 -> V_89 , L_20 ,
V_35 -> V_125 ,
V_42 ,
V_45 ? L_21 : L_22 ,
V_44 ? L_23 : L_22 ,
V_35 -> V_130 ) ;
return - V_171 ;
}
if ( V_165 -> V_177 || V_42 < V_178 )
continue;
if ( V_61 -> V_70 && V_45 != NULL ) {
V_35 -> V_75 = F_65 ( V_6 -> V_89 , ( void * ) V_45 ,
V_42 , V_115 ) ;
if ( F_66 ( V_6 -> V_89 , V_35 -> V_75 ) ) {
F_45 ( V_6 -> V_89 , L_24 ,
'T' , V_42 ) ;
return - V_171 ;
}
}
if ( V_61 -> V_85 && V_44 != NULL ) {
V_35 -> V_87 = F_65 ( V_6 -> V_89 , V_44 , V_35 -> V_42 ,
V_90 ) ;
if ( F_66 ( V_6 -> V_89 , V_35 -> V_87 ) ) {
F_45 ( V_6 -> V_89 , L_24 ,
'R' , V_42 ) ;
if ( V_45 != NULL )
F_36 ( V_6 -> V_89 , V_35 -> V_75 ,
V_42 , V_115 ) ;
return - V_171 ;
}
}
}
F_62 ( V_6 , V_165 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_27 * V_28 = & V_6 -> V_28 ;
int V_159 = 0 ;
V_159 = F_56 ( V_6 -> V_89 ) ;
if ( V_159 < 0 )
return V_159 ;
F_1 ( V_2 , V_52 ,
V_183 ) ;
V_28 -> V_53 = V_183 ;
F_14 ( V_2 ) ;
F_57 ( V_6 -> V_89 ) ;
F_58 ( V_6 -> V_89 ) ;
return 0 ;
}
static int F_69 ( struct V_184 * V_89 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_70 ( V_89 ) ;
V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
const struct V_187 * V_188 ;
struct V_5 * V_6 ;
struct V_189 * V_190 ;
int V_169 = 0 , V_191 ;
T_1 V_192 = 0 ;
static int V_193 = 1 ;
struct V_194 * V_162 = V_186 -> V_89 . V_195 ;
const struct V_196 * V_197 ;
V_2 = F_72 ( & V_186 -> V_89 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_45 ( & V_186 -> V_89 , L_25 ) ;
return - V_161 ;
}
V_2 -> V_198 = V_145 | V_147 | V_141 ;
V_2 -> V_199 = F_73 ( 4 , 32 ) ;
V_2 -> V_200 = F_53 ;
V_2 -> V_201 = true ;
V_2 -> V_202 = F_64 ;
V_2 -> V_203 = F_59 ;
V_2 -> V_89 . V_195 = V_162 ;
V_2 -> V_131 = V_126 ;
V_2 -> V_204 = V_126 >> 15 ;
F_74 ( V_186 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_197 = F_75 ( V_205 , & V_186 -> V_89 ) ;
if ( V_197 ) {
T_1 V_206 = 1 ;
V_188 = V_197 -> V_59 ;
F_76 ( V_162 , L_26 , & V_206 ) ;
V_2 -> V_163 = V_206 ;
V_2 -> V_193 = V_193 ++ ;
if ( F_77 ( V_162 , L_27 , NULL ) )
V_6 -> V_134 = V_207 ;
} else {
V_188 = F_78 ( & V_186 -> V_89 ) ;
V_2 -> V_163 = V_188 -> V_206 ;
if ( V_186 -> V_208 != - 1 )
V_2 -> V_193 = V_186 -> V_208 ;
V_6 -> V_134 = V_188 -> V_134 ;
}
V_192 = V_188 -> V_192 ;
V_190 = F_79 ( V_186 , V_209 , 0 ) ;
if ( V_190 == NULL ) {
V_169 = - V_210 ;
goto V_211;
}
V_190 -> V_212 += V_192 ;
V_190 -> V_213 += V_192 ;
V_6 -> V_108 = V_190 -> V_212 ;
V_6 -> V_7 = F_80 ( & V_186 -> V_89 , V_190 ) ;
if ( F_81 ( V_6 -> V_7 ) ) {
V_169 = F_82 ( V_6 -> V_7 ) ;
goto V_211;
}
V_6 -> V_89 = & V_186 -> V_89 ;
F_83 ( & V_6 -> V_28 . V_11 ) ;
V_6 -> V_62 = F_84 ( & V_186 -> V_89 , V_2 -> V_163 ,
sizeof( struct V_60 ) ,
V_160 ) ;
if ( V_6 -> V_62 == NULL ) {
V_169 = - V_161 ;
goto V_211;
}
for ( V_191 = 0 ; V_191 < V_2 -> V_163 ; V_191 ++ ) {
char * V_154 = V_6 -> V_62 [ V_191 ] . V_154 ;
char * V_157 = V_6 -> V_62 [ V_191 ] . V_157 ;
struct V_189 * V_214 ;
sprintf ( V_154 , L_28 , V_191 ) ;
if ( ! V_186 -> V_89 . V_195 ) {
V_214 =
F_85 ( V_186 ,
V_215 ,
V_154 ) ;
if ( ! V_214 ) {
F_45 ( & V_186 -> V_89 ,
L_29 ) ;
V_169 = - V_210 ;
break;
}
V_6 -> V_62 [ V_191 ] . V_152 =
V_214 -> V_212 ;
}
sprintf ( V_157 , L_30 , V_191 ) ;
if ( ! V_186 -> V_89 . V_195 ) {
V_214 =
F_85 ( V_186 ,
V_215 ,
V_157 ) ;
if ( ! V_214 ) {
F_45 ( & V_186 -> V_89 ,
L_31 ) ;
V_169 = - V_210 ;
break;
}
V_6 -> V_62 [ V_191 ] . V_156 =
V_214 -> V_212 ;
}
}
if ( V_169 < 0 )
goto V_211;
F_86 ( & V_186 -> V_89 ) ;
F_87 ( & V_186 -> V_89 , V_216 ) ;
F_88 ( & V_186 -> V_89 ) ;
V_169 = F_68 ( V_6 ) ;
if ( V_169 < 0 )
goto V_217;
V_169 = F_89 ( & V_186 -> V_89 , V_2 ) ;
if ( V_169 < 0 )
goto V_217;
return V_169 ;
V_217:
F_90 ( & V_186 -> V_89 ) ;
V_211:
F_91 ( V_2 ) ;
return V_169 ;
}
static int F_92 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_93 ( V_186 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_94 ( V_6 -> V_89 ) ;
F_90 ( & V_186 -> V_89 ) ;
return 0 ;
}
static int F_95 ( struct V_184 * V_89 )
{
struct V_1 * V_2 = F_70 ( V_89 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_6 -> V_28 ;
struct V_10 * V_11 ;
F_56 ( V_6 -> V_89 ) ;
F_18 (cs, &ctx->cs, node) {
if ( ( V_11 -> V_13 & V_26 ) == 0 ) {
V_11 -> V_13 |= V_26 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
V_11 -> V_13 &= ~ V_26 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_57 ( V_6 -> V_89 ) ;
F_58 ( V_6 -> V_89 ) ;
return 0 ;
}
