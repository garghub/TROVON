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
static void F_13 ( struct V_8 * V_9 , bool V_17 )
{
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
T_1 V_18 ;
if ( V_9 -> V_25 & V_26 )
V_17 = ! V_17 ;
if ( V_9 -> V_12 ) {
int V_27 = F_14 ( V_6 -> V_28 ) ;
if ( V_27 < 0 ) {
F_15 ( V_6 -> V_28 , L_1 , V_27 ) ;
return;
}
V_18 = F_8 ( V_9 ) ;
if ( V_17 )
V_18 &= ~ V_29 ;
else
V_18 |= V_29 ;
F_9 ( V_9 , V_18 ) ;
F_16 ( V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_30 * V_31 = & V_6 -> V_31 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 , V_32 ) ;
V_18 &= ~ ( V_33 | V_34 ) ;
V_18 |= V_35 ;
F_1 ( V_2 , V_32 , V_18 ) ;
V_31 -> V_36 = V_18 ;
}
static void F_19 ( const struct V_8 * V_9 ,
struct V_37 * V_38 , int V_17 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
unsigned int V_39 ;
int V_40 , V_41 , V_42 ;
T_1 V_43 , V_44 ;
V_6 = F_2 ( V_2 ) ;
V_43 = F_8 ( V_9 ) ;
if ( V_17 ) {
V_42 = F_10 ( V_11 -> V_15 ) ;
if ( V_38 -> V_45 % V_42 != 0 )
goto V_46;
if ( V_38 -> V_47 != NULL && V_38 -> V_48 != NULL )
V_40 = V_49 / 2 ;
else
V_40 = V_49 ;
V_41 = F_20 ( V_38 -> V_45 , V_40 ) ;
if ( V_41 < 2 || V_41 % V_42 != 0 )
goto V_46;
V_39 = V_38 -> V_45 / V_42 ;
if ( V_39 > V_50 )
goto V_46;
V_44 = V_39 << 16 ;
if ( V_38 -> V_47 != NULL ) {
V_43 |= V_51 ;
V_44 |= ( V_41 - 1 ) << 8 ;
}
if ( V_38 -> V_48 != NULL ) {
V_43 |= V_52 ;
V_44 |= V_41 - 1 ;
}
F_1 ( V_2 , V_53 , V_44 ) ;
F_9 ( V_9 , V_43 ) ;
V_6 -> V_41 = V_41 ;
return;
}
V_46:
if ( V_38 -> V_47 != NULL )
V_43 &= ~ V_51 ;
if ( V_38 -> V_48 != NULL )
V_43 &= ~ V_52 ;
F_9 ( V_9 , V_43 ) ;
V_6 -> V_41 = 0 ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_54 = V_6 -> V_2 ;
struct V_30 * V_31 = & V_6 -> V_31 ;
struct V_10 * V_11 ;
F_1 ( V_54 , V_32 , V_31 -> V_36 ) ;
F_1 ( V_54 , V_55 , V_31 -> V_56 ) ;
F_22 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static int F_23 ( void T_2 * V_57 , unsigned long V_58 )
{
unsigned long V_59 ;
V_59 = V_60 + F_24 ( 1000 ) ;
while ( ! ( F_5 ( V_57 ) & V_58 ) ) {
if ( F_25 ( V_60 , V_59 ) ) {
if ( ! ( F_5 ( V_57 ) & V_58 ) )
return - V_61 ;
else
return 0 ;
}
F_26 () ;
}
return 0 ;
}
static void F_27 ( void * V_62 )
{
struct V_8 * V_9 = V_62 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_63 * V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
F_11 ( V_9 , 1 , 0 ) ;
F_28 ( & V_64 -> V_67 ) ;
}
static void F_29 ( void * V_62 )
{
struct V_8 * V_9 = V_62 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_63 * V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
F_11 ( V_9 , 0 , 0 ) ;
F_28 ( & V_64 -> V_68 ) ;
}
static void F_30 ( struct V_8 * V_9 ,
struct V_37 * V_69 ,
struct V_70 V_71 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
unsigned int V_72 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
V_72 = V_69 -> V_45 ;
if ( V_64 -> V_73 ) {
struct V_74 * V_75 ;
struct V_76 V_77 ;
F_31 ( V_64 -> V_73 , & V_71 ) ;
F_32 ( & V_77 , 1 ) ;
F_33 ( & V_77 ) = V_69 -> V_78 ;
F_34 ( & V_77 ) = V_69 -> V_45 ;
V_75 = F_35 ( V_64 -> V_73 , & V_77 , 1 ,
V_79 , V_80 | V_81 ) ;
if ( V_75 ) {
V_75 -> V_82 = F_29 ;
V_75 -> V_83 = V_9 ;
F_36 ( V_75 ) ;
} else {
}
}
F_37 ( V_64 -> V_73 ) ;
F_11 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_38 ( struct V_8 * V_9 , struct V_37 * V_69 ,
struct V_70 V_71 ,
unsigned V_84 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
unsigned int V_72 , V_85 ;
T_1 V_18 ;
int V_86 = 0 ;
int V_15 , V_87 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
V_72 = V_69 -> V_45 ;
V_85 = V_69 -> V_45 ;
if ( V_6 -> V_41 == 0 )
V_85 -= V_84 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
if ( V_15 <= 8 )
V_87 = V_72 ;
else if ( V_15 <= 16 )
V_87 = V_72 >> 1 ;
else
V_87 = V_72 >> 2 ;
if ( V_64 -> V_88 ) {
struct V_74 * V_75 ;
struct V_76 V_77 ;
F_31 ( V_64 -> V_88 , & V_71 ) ;
if ( ( V_18 & V_89 ) && V_6 -> V_41 == 0 )
V_85 -= V_84 ;
F_32 ( & V_77 , 1 ) ;
F_33 ( & V_77 ) = V_69 -> V_90 ;
F_34 ( & V_77 ) = V_85 ;
V_75 = F_35 ( V_64 -> V_88 , & V_77 , 1 ,
V_91 , V_80 |
V_81 ) ;
if ( V_75 ) {
V_75 -> V_82 = F_27 ;
V_75 -> V_83 = V_9 ;
F_36 ( V_75 ) ;
} else {
}
}
F_37 ( V_64 -> V_88 ) ;
F_11 ( V_9 , 1 , 1 ) ;
F_39 ( & V_64 -> V_67 ) ;
F_40 ( V_6 -> V_28 , V_69 -> V_90 , V_72 ,
V_92 ) ;
if ( V_6 -> V_41 > 0 )
return V_72 ;
F_12 ( V_9 , 0 ) ;
V_86 = V_87 - 1 ;
if ( V_18 & V_89 ) {
V_86 -- ;
if ( F_41 ( F_7 ( V_9 , V_93 )
& V_94 ) ) {
T_1 V_95 ;
V_95 = F_7 ( V_9 , V_96 ) ;
if ( V_15 <= 8 )
( ( V_97 * ) V_69 -> V_47 ) [ V_86 ++ ] = V_95 ;
else if ( V_15 <= 16 )
( ( V_98 * ) V_69 -> V_47 ) [ V_86 ++ ] = V_95 ;
else
( ( T_1 * ) V_69 -> V_47 ) [ V_86 ++ ] = V_95 ;
} else {
int V_42 = F_10 ( V_15 ) ;
F_15 ( & V_9 -> V_28 , L_2 ) ;
V_72 -= ( V_42 << 1 ) ;
F_12 ( V_9 , 1 ) ;
return V_72 ;
}
}
if ( F_41 ( F_7 ( V_9 , V_93 )
& V_94 ) ) {
T_1 V_95 ;
V_95 = F_7 ( V_9 , V_96 ) ;
if ( V_15 <= 8 )
( ( V_97 * ) V_69 -> V_47 ) [ V_86 ] = V_95 ;
else if ( V_15 <= 16 )
( ( V_98 * ) V_69 -> V_47 ) [ V_86 ] = V_95 ;
else
( ( T_1 * ) V_69 -> V_47 ) [ V_86 ] = V_95 ;
} else {
F_15 ( & V_9 -> V_28 , L_3 ) ;
V_72 -= F_10 ( V_15 ) ;
}
F_12 ( V_9 , 1 ) ;
return V_72 ;
}
static unsigned
F_42 ( struct V_8 * V_9 , struct V_37 * V_69 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_63 * V_64 ;
unsigned int V_72 ;
T_1 V_18 ;
V_97 * V_99 ;
const V_97 * V_75 ;
struct V_70 V_71 ;
enum V_100 V_101 ;
unsigned V_84 ;
T_1 V_102 ;
void T_2 * V_103 ;
void T_2 * V_104 ;
int V_105 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
V_18 = F_8 ( V_9 ) ;
if ( V_11 -> V_15 <= 8 ) {
V_101 = V_106 ;
V_84 = 1 ;
} else if ( V_11 -> V_15 <= 16 ) {
V_101 = V_107 ;
V_84 = 2 ;
} else {
V_101 = V_108 ;
V_84 = 4 ;
}
V_72 = V_69 -> V_45 ;
V_102 = 1 ;
if ( V_6 -> V_41 > 0 ) {
if ( V_72 > V_6 -> V_41 )
V_102 = V_6 -> V_41 / V_84 ;
else
V_102 = V_72 / V_84 ;
}
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_109 = V_11 -> V_110 + V_96 ;
V_71 . V_111 = V_11 -> V_110 + V_112 ;
V_71 . V_113 = V_101 ;
V_71 . V_114 = V_101 ;
V_71 . V_115 = V_102 ;
V_71 . V_116 = V_102 ;
V_99 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
if ( V_75 != NULL )
F_30 ( V_9 , V_69 , V_71 ) ;
if ( V_99 != NULL )
V_72 = F_38 ( V_9 , V_69 , V_71 , V_84 ) ;
if ( V_75 != NULL ) {
F_39 ( & V_64 -> V_68 ) ;
F_40 ( V_6 -> V_28 , V_69 -> V_78 , V_69 -> V_45 ,
V_117 ) ;
if ( V_6 -> V_41 > 0 ) {
V_104 = V_6 -> V_7 + V_118 ;
if ( F_23 ( V_104 ,
V_119 ) < 0 )
F_15 ( & V_9 -> V_28 , L_4 ) ;
F_1 ( V_6 -> V_2 , V_118 ,
V_119 ) ;
}
if ( V_99 == NULL ) {
V_103 = V_11 -> V_7 + V_93 ;
if ( V_6 -> V_41 > 0 ) {
V_105 = F_23 ( V_103 ,
V_120 ) ;
if ( V_105 < 0 )
F_15 ( & V_9 -> V_28 , L_5 ) ;
} else {
V_105 = F_23 ( V_103 ,
V_121 ) ;
if ( V_105 < 0 )
F_15 ( & V_9 -> V_28 , L_6 ) ;
}
if ( V_105 >= 0 &&
( F_23 ( V_103 ,
V_122 ) < 0 ) )
F_15 ( & V_9 -> V_28 , L_7 ) ;
}
}
return V_72 ;
}
static unsigned
F_43 ( struct V_8 * V_9 , struct V_37 * V_69 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_72 , V_123 ;
T_1 V_18 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_124 ;
void T_2 * V_125 ;
void T_2 * V_103 ;
int V_15 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_72 = V_69 -> V_45 ;
V_123 = V_72 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
V_124 = V_7 + V_112 ;
V_125 = V_7 + V_96 ;
V_103 = V_7 + V_93 ;
if ( V_123 < ( V_15 >> 3 ) )
return 0 ;
if ( V_15 <= 8 ) {
V_97 * V_99 ;
const V_97 * V_75 ;
V_99 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
do {
V_123 -= 1 ;
if ( V_75 != NULL ) {
if ( F_23 ( V_103 ,
V_121 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_6 ) ;
goto V_126;
}
F_44 ( & V_9 -> V_28 , L_8 ,
V_15 , * V_75 ) ;
F_3 ( * V_75 ++ , V_124 ) ;
}
if ( V_99 != NULL ) {
if ( F_23 ( V_103 ,
V_94 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_9 ) ;
goto V_126;
}
if ( V_123 == 1 && V_75 == NULL &&
( V_18 & V_89 ) ) {
F_12 ( V_9 , 0 ) ;
* V_99 ++ = F_5 ( V_125 ) ;
F_44 ( & V_9 -> V_28 , L_10 ,
V_15 , * ( V_99 - 1 ) ) ;
if ( F_23 ( V_103 ,
V_94 ) < 0 ) {
F_15 ( & V_9 -> V_28 ,
L_9 ) ;
goto V_126;
}
V_123 = 0 ;
} else if ( V_123 == 0 && V_75 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_99 ++ = F_5 ( V_125 ) ;
F_44 ( & V_9 -> V_28 , L_10 ,
V_15 , * ( V_99 - 1 ) ) ;
}
} while ( V_123 );
} else if ( V_15 <= 16 ) {
V_98 * V_99 ;
const V_98 * V_75 ;
V_99 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
do {
V_123 -= 2 ;
if ( V_75 != NULL ) {
if ( F_23 ( V_103 ,
V_121 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_6 ) ;
goto V_126;
}
F_44 ( & V_9 -> V_28 , L_11 ,
V_15 , * V_75 ) ;
F_3 ( * V_75 ++ , V_124 ) ;
}
if ( V_99 != NULL ) {
if ( F_23 ( V_103 ,
V_94 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_9 ) ;
goto V_126;
}
if ( V_123 == 2 && V_75 == NULL &&
( V_18 & V_89 ) ) {
F_12 ( V_9 , 0 ) ;
* V_99 ++ = F_5 ( V_125 ) ;
F_44 ( & V_9 -> V_28 , L_12 ,
V_15 , * ( V_99 - 1 ) ) ;
if ( F_23 ( V_103 ,
V_94 ) < 0 ) {
F_15 ( & V_9 -> V_28 ,
L_9 ) ;
goto V_126;
}
V_123 = 0 ;
} else if ( V_123 == 0 && V_75 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_99 ++ = F_5 ( V_125 ) ;
F_44 ( & V_9 -> V_28 , L_12 ,
V_15 , * ( V_99 - 1 ) ) ;
}
} while ( V_123 >= 2 );
} else if ( V_15 <= 32 ) {
T_1 * V_99 ;
const T_1 * V_75 ;
V_99 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
do {
V_123 -= 4 ;
if ( V_75 != NULL ) {
if ( F_23 ( V_103 ,
V_121 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_6 ) ;
goto V_126;
}
F_44 ( & V_9 -> V_28 , L_13 ,
V_15 , * V_75 ) ;
F_3 ( * V_75 ++ , V_124 ) ;
}
if ( V_99 != NULL ) {
if ( F_23 ( V_103 ,
V_94 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_9 ) ;
goto V_126;
}
if ( V_123 == 4 && V_75 == NULL &&
( V_18 & V_89 ) ) {
F_12 ( V_9 , 0 ) ;
* V_99 ++ = F_5 ( V_125 ) ;
F_44 ( & V_9 -> V_28 , L_14 ,
V_15 , * ( V_99 - 1 ) ) ;
if ( F_23 ( V_103 ,
V_94 ) < 0 ) {
F_15 ( & V_9 -> V_28 ,
L_9 ) ;
goto V_126;
}
V_123 = 0 ;
} else if ( V_123 == 0 && V_75 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_99 ++ = F_5 ( V_125 ) ;
F_44 ( & V_9 -> V_28 , L_14 ,
V_15 , * ( V_99 - 1 ) ) ;
}
} while ( V_123 >= 4 );
}
if ( V_69 -> V_47 == NULL ) {
if ( F_23 ( V_103 ,
V_121 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_6 ) ;
} else if ( F_23 ( V_103 ,
V_122 ) < 0 )
F_15 ( & V_9 -> V_28 , L_7 ) ;
F_12 ( V_9 , 0 ) ;
}
V_126:
F_12 ( V_9 , 1 ) ;
return V_72 - V_123 ;
}
static T_1 F_45 ( T_1 V_127 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_127 >= ( V_128 >> div ) )
return div ;
return 15 ;
}
static int F_46 ( struct V_8 * V_9 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_54 ;
T_1 V_18 = 0 , V_129 = 0 , div , V_130 = 0 , V_131 = 0 ;
V_97 V_15 = V_9 -> V_132 ;
T_1 V_127 = V_9 -> V_133 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_54 = V_6 -> V_2 ;
if ( V_38 != NULL && V_38 -> V_132 )
V_15 = V_38 -> V_132 ;
V_11 -> V_15 = V_15 ;
if ( V_38 && V_38 -> V_127 )
V_127 = V_38 -> V_127 ;
V_127 = F_47 ( T_1 , V_127 , V_128 ) ;
if ( V_127 < ( V_128 / V_134 ) ) {
V_129 = F_45 ( V_127 ) ;
V_127 = V_128 >> V_129 ;
V_131 = 0 ;
} else {
div = ( V_128 + V_127 - 1 ) / V_127 ;
V_127 = V_128 / div ;
V_129 = ( div - 1 ) & 0xf ;
V_130 = ( div - 1 ) >> 4 ;
V_131 = V_135 ;
}
V_18 = F_8 ( V_9 ) ;
if ( V_6 -> V_136 == V_137 ) {
V_18 &= ~ V_138 ;
V_18 &= ~ V_139 ;
V_18 |= V_140 ;
} else {
V_18 |= V_138 ;
V_18 |= V_139 ;
V_18 &= ~ V_140 ;
}
V_18 &= ~ V_141 ;
V_18 |= ( V_15 - 1 ) << 7 ;
if ( ! ( V_9 -> V_25 & V_26 ) )
V_18 |= V_142 ;
else
V_18 &= ~ V_142 ;
V_18 &= ~ V_143 ;
V_18 |= V_129 << 2 ;
V_18 &= ~ V_135 ;
V_18 |= V_131 ;
if ( V_131 ) {
V_11 -> V_22 &= ~ V_144 ;
V_11 -> V_22 |= V_130 << 8 ;
F_6 ( V_9 , V_24 , V_11 -> V_22 ) ;
}
if ( V_9 -> V_25 & V_145 )
V_18 |= V_146 ;
else
V_18 &= ~ V_146 ;
if ( V_9 -> V_25 & V_147 )
V_18 |= V_148 ;
else
V_18 &= ~ V_148 ;
F_9 ( V_9 , V_18 ) ;
V_11 -> V_25 = V_9 -> V_25 ;
F_48 ( & V_9 -> V_28 , L_15 ,
V_127 ,
( V_9 -> V_25 & V_147 ) ? L_16 : L_17 ,
( V_9 -> V_25 & V_145 ) ? L_18 : L_19 ) ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_63 * V_64 ;
T_3 V_149 ;
unsigned V_150 ;
V_6 = F_2 ( V_2 ) ;
V_64 = V_6 -> V_65 + V_9 -> V_66 ;
F_50 ( & V_64 -> V_67 ) ;
F_50 ( & V_64 -> V_68 ) ;
F_51 ( V_149 ) ;
F_52 ( V_151 , V_149 ) ;
V_150 = V_64 -> V_152 ;
V_64 -> V_88 =
F_53 ( V_149 , V_153 ,
& V_150 , & V_2 -> V_28 ,
V_64 -> V_154 ) ;
if ( ! V_64 -> V_88 )
goto V_155;
V_150 = V_64 -> V_156 ;
V_64 -> V_73 =
F_53 ( V_149 , V_153 ,
& V_150 , & V_2 -> V_28 ,
V_64 -> V_157 ) ;
if ( ! V_64 -> V_73 ) {
F_54 ( V_64 -> V_88 ) ;
V_64 -> V_88 = NULL ;
goto V_155;
}
return 0 ;
V_155:
F_55 ( & V_9 -> V_28 , L_20 ) ;
return - V_158 ;
}
static int F_56 ( struct V_8 * V_9 )
{
int V_159 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_30 * V_31 = & V_6 -> V_31 ;
struct V_63 * V_64 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
if ( ! V_11 ) {
V_11 = F_57 ( sizeof *V_11 , V_160 ) ;
if ( ! V_11 )
return - V_161 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_66 * 0x14 ;
V_11 -> V_110 = V_6 -> V_110 + V_9 -> V_66 * 0x14 ;
V_11 -> V_25 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_22 = 0 ;
V_9 -> V_12 = V_11 ;
F_58 ( & V_11 -> V_162 , & V_31 -> V_11 ) ;
}
if ( ! V_64 -> V_88 || ! V_64 -> V_73 ) {
V_159 = F_49 ( V_9 ) ;
if ( V_159 < 0 && V_159 != - V_158 )
return V_159 ;
}
if ( F_59 ( V_9 -> V_163 ) ) {
V_159 = F_60 ( V_9 -> V_163 , F_61 ( & V_9 -> V_28 ) ) ;
if ( V_159 ) {
F_15 ( & V_9 -> V_28 , L_21 ) ;
return V_159 ;
}
F_62 ( V_9 -> V_163 , ! ( V_9 -> V_25 & V_26 ) ) ;
}
V_159 = F_14 ( V_6 -> V_28 ) ;
if ( V_159 < 0 )
return V_159 ;
V_159 = F_46 ( V_9 , NULL ) ;
F_16 ( V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
return V_159 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_64 ( & V_11 -> V_162 ) ;
F_65 ( V_11 ) ;
}
if ( V_9 -> V_66 < V_9 -> V_2 -> V_164 ) {
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
if ( V_64 -> V_88 ) {
F_54 ( V_64 -> V_88 ) ;
V_64 -> V_88 = NULL ;
}
if ( V_64 -> V_73 ) {
F_54 ( V_64 -> V_73 ) ;
V_64 -> V_73 = NULL ;
}
}
if ( F_59 ( V_9 -> V_163 ) )
F_66 ( V_9 -> V_163 ) ;
}
static int F_67 ( struct V_5 * V_6 ,
struct V_8 * V_9 , struct V_37 * V_38 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_10 * V_11 ;
struct V_165 * V_166 ;
int V_167 = 0 ;
int V_168 = 0 ;
T_1 V_43 ;
V_2 = V_9 -> V_2 ;
V_64 = V_6 -> V_65 + V_9 -> V_66 ;
V_11 = V_9 -> V_12 ;
V_166 = V_9 -> V_169 ;
if ( V_9 -> V_25 != V_11 -> V_25 )
V_167 = 1 ;
F_12 ( V_9 , 0 ) ;
if ( F_59 ( V_9 -> V_163 ) )
F_13 ( V_9 , V_9 -> V_25 & V_26 ) ;
if ( V_167 ||
( V_38 -> V_127 != V_9 -> V_133 ) ||
( V_38 -> V_132 != V_9 -> V_132 ) ) {
V_167 = 1 ;
V_168 = F_46 ( V_9 , V_38 ) ;
if ( V_168 < 0 )
goto V_126;
if ( V_38 -> V_127 == V_9 -> V_133 &&
V_38 -> V_132 == V_9 -> V_132 )
V_167 = 0 ;
}
if ( V_166 && V_166 -> V_170 ) {
V_43 = V_6 -> V_31 . V_36 ;
V_43 &= ~ V_35 ;
F_1 ( V_2 , V_32 , V_43 ) ;
V_6 -> V_31 . V_36 =
F_7 ( V_9 , V_32 ) ;
}
V_43 = F_8 ( V_9 ) ;
V_43 &= ~ V_171 ;
V_43 &= ~ V_89 ;
if ( V_38 -> V_48 == NULL )
V_43 |= V_172 ;
else if ( V_38 -> V_47 == NULL )
V_43 |= V_173 ;
if ( V_166 && V_166 -> V_174 && V_38 -> V_48 == NULL ) {
if ( V_38 -> V_45 > ( ( V_11 -> V_15 + 7 ) >> 3 ) )
V_43 |= V_89 ;
}
F_9 ( V_9 , V_43 ) ;
if ( V_38 -> V_45 ) {
unsigned V_72 ;
if ( ( V_64 -> V_88 && V_64 -> V_73 ) &&
( V_38 -> V_45 >= V_175 ) )
F_19 ( V_9 , V_38 , 1 ) ;
F_12 ( V_9 , 1 ) ;
if ( V_38 -> V_48 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_112 ) ;
if ( ( V_64 -> V_88 && V_64 -> V_73 ) &&
( V_38 -> V_45 >= V_175 ) )
V_72 = F_42 ( V_9 , V_38 ) ;
else
V_72 = F_43 ( V_9 , V_38 ) ;
if ( V_72 != V_38 -> V_45 ) {
V_168 = - V_176 ;
goto V_126;
}
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_41 > 0 )
F_19 ( V_9 , V_38 , 0 ) ;
V_126:
if ( V_167 ) {
V_167 = 0 ;
V_168 = F_46 ( V_9 , NULL ) ;
}
if ( V_166 && V_166 -> V_170 ) {
V_43 = V_6 -> V_31 . V_36 ;
V_43 |= V_35 ;
F_1 ( V_2 , V_32 , V_43 ) ;
V_6 -> V_31 . V_36 =
F_7 ( V_9 , V_32 ) ;
}
F_12 ( V_9 , 0 ) ;
if ( F_59 ( V_9 -> V_163 ) )
F_13 ( V_9 , ! ( V_9 -> V_25 & V_26 ) ) ;
if ( V_6 -> V_41 > 0 && V_38 )
F_19 ( V_9 , V_38 , 0 ) ;
return V_168 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 , struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
const void * V_48 = V_38 -> V_48 ;
void * V_47 = V_38 -> V_47 ;
unsigned V_45 = V_38 -> V_45 ;
V_6 = F_2 ( V_2 ) ;
V_64 = V_6 -> V_65 + V_9 -> V_66 ;
if ( ( V_45 && ! ( V_47 || V_48 ) ) ) {
F_48 ( V_6 -> V_28 , L_22 ,
V_38 -> V_127 ,
V_45 ,
V_48 ? L_23 : L_24 ,
V_47 ? L_25 : L_24 ,
V_38 -> V_132 ) ;
return - V_177 ;
}
if ( V_45 < V_175 )
goto V_178;
if ( V_64 -> V_73 && V_48 != NULL ) {
V_38 -> V_78 = F_69 ( V_6 -> V_28 , ( void * ) V_48 ,
V_45 , V_117 ) ;
if ( F_70 ( V_6 -> V_28 , V_38 -> V_78 ) ) {
F_48 ( V_6 -> V_28 , L_26 ,
'T' , V_45 ) ;
return - V_177 ;
}
}
if ( V_64 -> V_88 && V_47 != NULL ) {
V_38 -> V_90 = F_69 ( V_6 -> V_28 , V_47 , V_38 -> V_45 ,
V_92 ) ;
if ( F_70 ( V_6 -> V_28 , V_38 -> V_90 ) ) {
F_48 ( V_6 -> V_28 , L_26 ,
'R' , V_45 ) ;
if ( V_48 != NULL )
F_40 ( V_6 -> V_28 , V_38 -> V_78 ,
V_45 , V_117 ) ;
return - V_177 ;
}
}
V_178:
return F_67 ( V_6 , V_9 , V_38 ) ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_30 * V_31 = & V_6 -> V_31 ;
int V_159 = 0 ;
V_159 = F_14 ( V_6 -> V_28 ) ;
if ( V_159 < 0 )
return V_159 ;
F_1 ( V_2 , V_55 ,
V_179 ) ;
V_31 -> V_56 = V_179 ;
F_18 ( V_2 ) ;
F_16 ( V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
return 0 ;
}
static int F_72 ( struct V_180 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_73 ( V_28 ) ;
V_6 = F_2 ( V_2 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_181 * V_182 )
{
struct V_1 * V_2 ;
const struct V_183 * V_184 ;
struct V_5 * V_6 ;
struct V_185 * V_186 ;
int V_168 = 0 , V_187 ;
T_1 V_188 = 0 ;
static int V_189 = 1 ;
struct V_190 * V_162 = V_182 -> V_28 . V_191 ;
const struct V_192 * V_193 ;
V_2 = F_75 ( & V_182 -> V_28 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_48 ( & V_182 -> V_28 , L_27 ) ;
return - V_161 ;
}
V_2 -> V_194 = V_145 | V_147 | V_26 ;
V_2 -> V_195 = F_76 ( 4 , 32 ) ;
V_2 -> V_196 = F_56 ;
V_2 -> V_197 = true ;
V_2 -> V_198 = F_68 ;
V_2 -> V_199 = F_13 ;
V_2 -> V_200 = F_63 ;
V_2 -> V_28 . V_191 = V_162 ;
V_2 -> V_133 = V_128 ;
V_2 -> V_201 = V_128 >> 15 ;
F_77 ( V_182 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_193 = F_78 ( V_202 , & V_182 -> V_28 ) ;
if ( V_193 ) {
T_1 V_203 = 1 ;
V_184 = V_193 -> V_62 ;
F_79 ( V_162 , L_28 , & V_203 ) ;
V_2 -> V_164 = V_203 ;
V_2 -> V_189 = V_189 ++ ;
if ( F_80 ( V_162 , L_29 , NULL ) )
V_6 -> V_136 = V_204 ;
} else {
V_184 = F_81 ( & V_182 -> V_28 ) ;
V_2 -> V_164 = V_184 -> V_203 ;
if ( V_182 -> V_205 != - 1 )
V_2 -> V_189 = V_182 -> V_205 ;
V_6 -> V_136 = V_184 -> V_136 ;
}
V_188 = V_184 -> V_188 ;
V_186 = F_82 ( V_182 , V_206 , 0 ) ;
if ( V_186 == NULL ) {
V_168 = - V_207 ;
goto V_208;
}
V_186 -> V_209 += V_188 ;
V_186 -> V_210 += V_188 ;
V_6 -> V_110 = V_186 -> V_209 ;
V_6 -> V_7 = F_83 ( & V_182 -> V_28 , V_186 ) ;
if ( F_84 ( V_6 -> V_7 ) ) {
V_168 = F_85 ( V_6 -> V_7 ) ;
goto V_208;
}
V_6 -> V_28 = & V_182 -> V_28 ;
F_86 ( & V_6 -> V_31 . V_11 ) ;
V_6 -> V_65 = F_87 ( & V_182 -> V_28 , V_2 -> V_164 ,
sizeof( struct V_63 ) ,
V_160 ) ;
if ( V_6 -> V_65 == NULL ) {
V_168 = - V_161 ;
goto V_208;
}
for ( V_187 = 0 ; V_187 < V_2 -> V_164 ; V_187 ++ ) {
char * V_154 = V_6 -> V_65 [ V_187 ] . V_154 ;
char * V_157 = V_6 -> V_65 [ V_187 ] . V_157 ;
struct V_185 * V_211 ;
sprintf ( V_154 , L_30 , V_187 ) ;
if ( ! V_182 -> V_28 . V_191 ) {
V_211 =
F_88 ( V_182 ,
V_212 ,
V_154 ) ;
if ( ! V_211 ) {
F_48 ( & V_182 -> V_28 ,
L_31 ) ;
V_168 = - V_207 ;
break;
}
V_6 -> V_65 [ V_187 ] . V_152 =
V_211 -> V_209 ;
}
sprintf ( V_157 , L_32 , V_187 ) ;
if ( ! V_182 -> V_28 . V_191 ) {
V_211 =
F_88 ( V_182 ,
V_212 ,
V_157 ) ;
if ( ! V_211 ) {
F_48 ( & V_182 -> V_28 ,
L_33 ) ;
V_168 = - V_207 ;
break;
}
V_6 -> V_65 [ V_187 ] . V_156 =
V_211 -> V_209 ;
}
}
if ( V_168 < 0 )
goto V_208;
F_89 ( & V_182 -> V_28 ) ;
F_90 ( & V_182 -> V_28 , V_213 ) ;
F_91 ( & V_182 -> V_28 ) ;
V_168 = F_71 ( V_6 ) ;
if ( V_168 < 0 )
goto V_214;
V_168 = F_92 ( & V_182 -> V_28 , V_2 ) ;
if ( V_168 < 0 )
goto V_214;
return V_168 ;
V_214:
F_93 ( & V_182 -> V_28 ) ;
V_208:
F_94 ( V_2 ) ;
return V_168 ;
}
static int F_95 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = F_96 ( V_182 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_97 ( V_6 -> V_28 ) ;
F_93 ( & V_182 -> V_28 ) ;
return 0 ;
}
static int F_98 ( struct V_180 * V_28 )
{
struct V_1 * V_2 = F_73 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_30 * V_31 = & V_6 -> V_31 ;
struct V_10 * V_11 ;
F_14 ( V_6 -> V_28 ) ;
F_22 (cs, &ctx->cs, node) {
if ( ( V_11 -> V_13 & V_29 ) == 0 ) {
V_11 -> V_13 |= V_29 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
V_11 -> V_13 &= ~ V_29 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_16 ( V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
return 0 ;
}
