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
int V_36 , V_37 ;
T_1 V_38 , V_39 ;
V_6 = F_2 ( V_2 ) ;
V_38 = F_8 ( V_9 ) ;
if ( V_17 ) {
V_37 = F_10 ( V_11 -> V_15 ) ;
if ( V_34 -> V_40 % V_37 != 0 )
goto V_41;
V_36 = F_16 ( V_34 -> V_40 , V_42 ) ;
if ( V_36 < 2 || V_36 % V_37 != 0 )
goto V_41;
V_35 = V_34 -> V_40 / V_37 ;
if ( V_35 > V_43 )
goto V_41;
V_39 = V_35 << 16 ;
if ( V_34 -> V_44 != NULL ) {
V_38 |= V_45 ;
V_39 |= ( V_36 - 1 ) << 8 ;
} else {
V_38 |= V_46 ;
V_39 |= V_36 - 1 ;
}
F_1 ( V_2 , V_47 , V_39 ) ;
F_9 ( V_9 , V_38 ) ;
V_6 -> V_36 = V_36 ;
return;
}
V_41:
if ( V_34 -> V_44 != NULL )
V_38 &= ~ V_45 ;
else
V_38 &= ~ V_46 ;
F_9 ( V_9 , V_38 ) ;
V_6 -> V_36 = 0 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_48 = V_6 -> V_2 ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_10 * V_11 ;
F_1 ( V_48 , V_28 , V_27 -> V_32 ) ;
F_1 ( V_48 , V_49 , V_27 -> V_50 ) ;
F_18 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_20 ( V_6 -> V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_22 ( V_6 -> V_51 ) ;
F_23 ( V_6 -> V_51 ) ;
return 0 ;
}
static int F_24 ( void T_2 * V_52 , unsigned long V_53 )
{
unsigned long V_54 ;
V_54 = V_55 + F_25 ( 1000 ) ;
while ( ! ( F_5 ( V_52 ) & V_53 ) ) {
if ( F_26 ( V_55 , V_54 ) ) {
if ( ! ( F_5 ( V_52 ) & V_53 ) )
return - V_56 ;
else
return 0 ;
}
F_27 () ;
}
return 0 ;
}
static void F_28 ( void * V_57 )
{
struct V_8 * V_9 = V_57 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_58 * V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
F_11 ( V_9 , 1 , 0 ) ;
F_29 ( & V_59 -> V_62 ) ;
}
static void F_30 ( void * V_57 )
{
struct V_8 * V_9 = V_57 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_58 * V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
F_11 ( V_9 , 0 , 0 ) ;
F_29 ( & V_59 -> V_63 ) ;
}
static void F_31 ( struct V_8 * V_9 ,
struct V_33 * V_64 ,
struct V_65 V_66 )
{
struct V_5 * V_6 ;
struct V_58 * V_59 ;
unsigned int V_67 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
V_67 = V_64 -> V_40 ;
if ( V_59 -> V_68 ) {
struct V_69 * V_70 ;
struct V_71 V_72 ;
F_32 ( V_59 -> V_68 , & V_66 ) ;
F_33 ( & V_72 , 1 ) ;
F_34 ( & V_72 ) = V_64 -> V_73 ;
F_35 ( & V_72 ) = V_64 -> V_40 ;
V_70 = F_36 ( V_59 -> V_68 , & V_72 , 1 ,
V_74 , V_75 | V_76 ) ;
if ( V_70 ) {
V_70 -> V_77 = F_30 ;
V_70 -> V_78 = V_9 ;
F_37 ( V_70 ) ;
} else {
}
}
F_38 ( V_59 -> V_68 ) ;
F_11 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_39 ( struct V_8 * V_9 , struct V_33 * V_64 ,
struct V_65 V_66 ,
unsigned V_79 )
{
struct V_5 * V_6 ;
struct V_58 * V_59 ;
unsigned int V_67 , V_80 ;
T_1 V_18 ;
int V_81 = 0 ;
int V_15 , V_82 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
V_67 = V_64 -> V_40 ;
V_80 = V_64 -> V_40 ;
if ( V_6 -> V_36 == 0 )
V_80 -= V_79 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
if ( V_15 <= 8 )
V_82 = V_67 ;
else if ( V_15 <= 16 )
V_82 = V_67 >> 1 ;
else
V_82 = V_67 >> 2 ;
if ( V_59 -> V_83 ) {
struct V_69 * V_70 ;
struct V_71 V_72 ;
F_32 ( V_59 -> V_83 , & V_66 ) ;
if ( ( V_18 & V_84 ) && V_6 -> V_36 == 0 )
V_80 -= V_79 ;
F_33 ( & V_72 , 1 ) ;
F_34 ( & V_72 ) = V_64 -> V_85 ;
F_35 ( & V_72 ) = V_80 ;
V_70 = F_36 ( V_59 -> V_83 , & V_72 , 1 ,
V_86 , V_75 |
V_76 ) ;
if ( V_70 ) {
V_70 -> V_77 = F_28 ;
V_70 -> V_78 = V_9 ;
F_37 ( V_70 ) ;
} else {
}
}
F_38 ( V_59 -> V_83 ) ;
F_11 ( V_9 , 1 , 1 ) ;
F_40 ( & V_59 -> V_62 ) ;
F_41 ( V_6 -> V_51 , V_64 -> V_85 , V_67 ,
V_87 ) ;
if ( V_6 -> V_36 > 0 )
return V_67 ;
F_12 ( V_9 , 0 ) ;
V_81 = V_82 - 1 ;
if ( V_18 & V_84 ) {
V_81 -- ;
if ( F_42 ( F_7 ( V_9 , V_88 )
& V_89 ) ) {
T_1 V_90 ;
V_90 = F_7 ( V_9 , V_91 ) ;
if ( V_15 <= 8 )
( ( V_92 * ) V_64 -> V_44 ) [ V_81 ++ ] = V_90 ;
else if ( V_15 <= 16 )
( ( V_93 * ) V_64 -> V_44 ) [ V_81 ++ ] = V_90 ;
else
( ( T_1 * ) V_64 -> V_44 ) [ V_81 ++ ] = V_90 ;
} else {
int V_37 = F_10 ( V_15 ) ;
F_43 ( & V_9 -> V_51 , L_1 ) ;
V_67 -= ( V_37 << 1 ) ;
F_12 ( V_9 , 1 ) ;
return V_67 ;
}
}
if ( F_42 ( F_7 ( V_9 , V_88 )
& V_89 ) ) {
T_1 V_90 ;
V_90 = F_7 ( V_9 , V_91 ) ;
if ( V_15 <= 8 )
( ( V_92 * ) V_64 -> V_44 ) [ V_81 ] = V_90 ;
else if ( V_15 <= 16 )
( ( V_93 * ) V_64 -> V_44 ) [ V_81 ] = V_90 ;
else
( ( T_1 * ) V_64 -> V_44 ) [ V_81 ] = V_90 ;
} else {
F_43 ( & V_9 -> V_51 , L_2 ) ;
V_67 -= F_10 ( V_15 ) ;
}
F_12 ( V_9 , 1 ) ;
return V_67 ;
}
static unsigned
F_44 ( struct V_8 * V_9 , struct V_33 * V_64 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_58 * V_59 ;
unsigned int V_67 ;
T_1 V_18 ;
V_92 * V_94 ;
const V_92 * V_70 ;
struct V_65 V_66 ;
enum V_95 V_96 ;
unsigned V_79 ;
T_1 V_97 ;
void T_2 * V_98 ;
void T_2 * V_99 ;
int V_100 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
V_18 = F_8 ( V_9 ) ;
if ( V_11 -> V_15 <= 8 ) {
V_96 = V_101 ;
V_79 = 1 ;
} else if ( V_11 -> V_15 <= 16 ) {
V_96 = V_102 ;
V_79 = 2 ;
} else {
V_96 = V_103 ;
V_79 = 4 ;
}
V_67 = V_64 -> V_40 ;
V_97 = 1 ;
if ( V_6 -> V_36 > 0 ) {
if ( V_67 > V_6 -> V_36 )
V_97 = V_6 -> V_36 / V_79 ;
else
V_97 = V_67 / V_79 ;
}
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_104 = V_11 -> V_105 + V_91 ;
V_66 . V_106 = V_11 -> V_105 + V_107 ;
V_66 . V_108 = V_96 ;
V_66 . V_109 = V_96 ;
V_66 . V_110 = V_97 ;
V_66 . V_111 = V_97 ;
V_94 = V_64 -> V_44 ;
V_70 = V_64 -> V_112 ;
if ( V_70 != NULL )
F_31 ( V_9 , V_64 , V_66 ) ;
if ( V_94 != NULL )
V_67 = F_39 ( V_9 , V_64 , V_66 , V_79 ) ;
if ( V_70 != NULL ) {
F_40 ( & V_59 -> V_63 ) ;
F_41 ( V_6 -> V_51 , V_64 -> V_73 , V_64 -> V_40 ,
V_113 ) ;
if ( V_6 -> V_36 > 0 ) {
V_99 = V_6 -> V_7 + V_114 ;
if ( F_24 ( V_99 ,
V_115 ) < 0 )
F_43 ( & V_9 -> V_51 , L_3 ) ;
F_1 ( V_6 -> V_2 , V_114 ,
V_115 ) ;
}
if ( V_94 == NULL ) {
V_98 = V_11 -> V_7 + V_88 ;
if ( V_6 -> V_36 > 0 ) {
V_100 = F_24 ( V_98 ,
V_116 ) ;
if ( V_100 < 0 )
F_43 ( & V_9 -> V_51 , L_4 ) ;
} else {
V_100 = F_24 ( V_98 ,
V_117 ) ;
if ( V_100 < 0 )
F_43 ( & V_9 -> V_51 , L_5 ) ;
}
if ( V_100 >= 0 &&
( F_24 ( V_98 ,
V_118 ) < 0 ) )
F_43 ( & V_9 -> V_51 , L_6 ) ;
}
}
return V_67 ;
}
static unsigned
F_45 ( struct V_8 * V_9 , struct V_33 * V_64 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_67 , V_119 ;
T_1 V_18 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_120 ;
void T_2 * V_121 ;
void T_2 * V_98 ;
int V_15 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_67 = V_64 -> V_40 ;
V_119 = V_67 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
V_120 = V_7 + V_107 ;
V_121 = V_7 + V_91 ;
V_98 = V_7 + V_88 ;
if ( V_119 < ( V_15 >> 3 ) )
return 0 ;
if ( V_15 <= 8 ) {
V_92 * V_94 ;
const V_92 * V_70 ;
V_94 = V_64 -> V_44 ;
V_70 = V_64 -> V_112 ;
do {
V_119 -= 1 ;
if ( V_70 != NULL ) {
if ( F_24 ( V_98 ,
V_117 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_5 ) ;
goto V_122;
}
F_46 ( & V_9 -> V_51 , L_7 ,
V_15 , * V_70 ) ;
F_3 ( * V_70 ++ , V_120 ) ;
}
if ( V_94 != NULL ) {
if ( F_24 ( V_98 ,
V_89 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_8 ) ;
goto V_122;
}
if ( V_119 == 1 && V_70 == NULL &&
( V_18 & V_84 ) ) {
F_12 ( V_9 , 0 ) ;
* V_94 ++ = F_5 ( V_121 ) ;
F_46 ( & V_9 -> V_51 , L_9 ,
V_15 , * ( V_94 - 1 ) ) ;
if ( F_24 ( V_98 ,
V_89 ) < 0 ) {
F_43 ( & V_9 -> V_51 ,
L_8 ) ;
goto V_122;
}
V_119 = 0 ;
} else if ( V_119 == 0 && V_70 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_94 ++ = F_5 ( V_121 ) ;
F_46 ( & V_9 -> V_51 , L_9 ,
V_15 , * ( V_94 - 1 ) ) ;
}
} while ( V_119 );
} else if ( V_15 <= 16 ) {
V_93 * V_94 ;
const V_93 * V_70 ;
V_94 = V_64 -> V_44 ;
V_70 = V_64 -> V_112 ;
do {
V_119 -= 2 ;
if ( V_70 != NULL ) {
if ( F_24 ( V_98 ,
V_117 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_5 ) ;
goto V_122;
}
F_46 ( & V_9 -> V_51 , L_10 ,
V_15 , * V_70 ) ;
F_3 ( * V_70 ++ , V_120 ) ;
}
if ( V_94 != NULL ) {
if ( F_24 ( V_98 ,
V_89 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_8 ) ;
goto V_122;
}
if ( V_119 == 2 && V_70 == NULL &&
( V_18 & V_84 ) ) {
F_12 ( V_9 , 0 ) ;
* V_94 ++ = F_5 ( V_121 ) ;
F_46 ( & V_9 -> V_51 , L_11 ,
V_15 , * ( V_94 - 1 ) ) ;
if ( F_24 ( V_98 ,
V_89 ) < 0 ) {
F_43 ( & V_9 -> V_51 ,
L_8 ) ;
goto V_122;
}
V_119 = 0 ;
} else if ( V_119 == 0 && V_70 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_94 ++ = F_5 ( V_121 ) ;
F_46 ( & V_9 -> V_51 , L_11 ,
V_15 , * ( V_94 - 1 ) ) ;
}
} while ( V_119 >= 2 );
} else if ( V_15 <= 32 ) {
T_1 * V_94 ;
const T_1 * V_70 ;
V_94 = V_64 -> V_44 ;
V_70 = V_64 -> V_112 ;
do {
V_119 -= 4 ;
if ( V_70 != NULL ) {
if ( F_24 ( V_98 ,
V_117 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_5 ) ;
goto V_122;
}
F_46 ( & V_9 -> V_51 , L_12 ,
V_15 , * V_70 ) ;
F_3 ( * V_70 ++ , V_120 ) ;
}
if ( V_94 != NULL ) {
if ( F_24 ( V_98 ,
V_89 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_8 ) ;
goto V_122;
}
if ( V_119 == 4 && V_70 == NULL &&
( V_18 & V_84 ) ) {
F_12 ( V_9 , 0 ) ;
* V_94 ++ = F_5 ( V_121 ) ;
F_46 ( & V_9 -> V_51 , L_13 ,
V_15 , * ( V_94 - 1 ) ) ;
if ( F_24 ( V_98 ,
V_89 ) < 0 ) {
F_43 ( & V_9 -> V_51 ,
L_8 ) ;
goto V_122;
}
V_119 = 0 ;
} else if ( V_119 == 0 && V_70 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_94 ++ = F_5 ( V_121 ) ;
F_46 ( & V_9 -> V_51 , L_13 ,
V_15 , * ( V_94 - 1 ) ) ;
}
} while ( V_119 >= 4 );
}
if ( V_64 -> V_44 == NULL ) {
if ( F_24 ( V_98 ,
V_117 ) < 0 ) {
F_43 ( & V_9 -> V_51 , L_5 ) ;
} else if ( F_24 ( V_98 ,
V_118 ) < 0 )
F_43 ( & V_9 -> V_51 , L_6 ) ;
F_12 ( V_9 , 0 ) ;
}
V_122:
F_12 ( V_9 , 1 ) ;
return V_67 - V_119 ;
}
static T_1 F_47 ( T_1 V_123 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_123 >= ( V_124 >> div ) )
return div ;
return 15 ;
}
static int F_48 ( struct V_8 * V_9 ,
struct V_33 * V_34 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_48 ;
T_1 V_18 = 0 , div = 0 ;
V_92 V_15 = V_9 -> V_125 ;
T_1 V_123 = V_9 -> V_126 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_48 = V_6 -> V_2 ;
if ( V_34 != NULL && V_34 -> V_125 )
V_15 = V_34 -> V_125 ;
V_11 -> V_15 = V_15 ;
if ( V_34 && V_34 -> V_123 )
V_123 = V_34 -> V_123 ;
V_123 = F_49 ( T_1 , V_123 , V_124 ) ;
div = F_47 ( V_123 ) ;
V_18 = F_8 ( V_9 ) ;
if ( V_6 -> V_127 == V_128 ) {
V_18 &= ~ V_129 ;
V_18 &= ~ V_130 ;
V_18 |= V_131 ;
} else {
V_18 |= V_129 ;
V_18 |= V_130 ;
V_18 &= ~ V_131 ;
}
V_18 &= ~ V_132 ;
V_18 |= ( V_15 - 1 ) << 7 ;
if ( ! ( V_9 -> V_133 & V_134 ) )
V_18 |= V_135 ;
else
V_18 &= ~ V_135 ;
V_18 &= ~ V_136 ;
V_18 |= div << 2 ;
if ( V_9 -> V_133 & V_137 )
V_18 |= V_138 ;
else
V_18 &= ~ V_138 ;
if ( V_9 -> V_133 & V_139 )
V_18 |= V_140 ;
else
V_18 &= ~ V_140 ;
F_9 ( V_9 , V_18 ) ;
F_50 ( & V_9 -> V_51 , L_14 ,
V_124 >> div ,
( V_9 -> V_133 & V_139 ) ? L_15 : L_16 ,
( V_9 -> V_133 & V_137 ) ? L_17 : L_18 ) ;
return 0 ;
}
static int F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_58 * V_59 ;
T_3 V_141 ;
unsigned V_142 ;
V_6 = F_2 ( V_2 ) ;
V_59 = V_6 -> V_60 + V_9 -> V_61 ;
F_52 ( & V_59 -> V_62 ) ;
F_52 ( & V_59 -> V_63 ) ;
F_53 ( V_141 ) ;
F_54 ( V_143 , V_141 ) ;
V_142 = V_59 -> V_144 ;
V_59 -> V_83 =
F_55 ( V_141 , V_145 ,
& V_142 , & V_2 -> V_51 ,
V_59 -> V_146 ) ;
if ( ! V_59 -> V_83 )
goto V_147;
V_142 = V_59 -> V_148 ;
V_59 -> V_68 =
F_55 ( V_141 , V_145 ,
& V_142 , & V_2 -> V_51 ,
V_59 -> V_149 ) ;
if ( ! V_59 -> V_68 ) {
F_56 ( V_59 -> V_83 ) ;
V_59 -> V_83 = NULL ;
goto V_147;
}
return 0 ;
V_147:
F_57 ( & V_9 -> V_51 , L_19 ) ;
return - V_150 ;
}
static int F_58 ( struct V_8 * V_9 )
{
int V_151 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_58 * V_59 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
if ( ! V_11 ) {
V_11 = F_59 ( sizeof *V_11 , V_152 ) ;
if ( ! V_11 )
return - V_153 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_61 * 0x14 ;
V_11 -> V_105 = V_6 -> V_105 + V_9 -> V_61 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_60 ( & V_11 -> V_154 , & V_27 -> V_11 ) ;
}
if ( ! V_59 -> V_83 || ! V_59 -> V_68 ) {
V_151 = F_51 ( V_9 ) ;
if ( V_151 < 0 && V_151 != - V_150 )
return V_151 ;
}
V_151 = F_20 ( V_6 -> V_51 ) ;
if ( V_151 < 0 )
return V_151 ;
V_151 = F_48 ( V_9 , NULL ) ;
F_22 ( V_6 -> V_51 ) ;
F_23 ( V_6 -> V_51 ) ;
return V_151 ;
}
static void F_61 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_58 * V_59 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_62 ( & V_11 -> V_154 ) ;
F_63 ( V_11 ) ;
}
if ( V_9 -> V_61 < V_9 -> V_2 -> V_155 ) {
V_59 = & V_6 -> V_60 [ V_9 -> V_61 ] ;
if ( V_59 -> V_83 ) {
F_56 ( V_59 -> V_83 ) ;
V_59 -> V_83 = NULL ;
}
if ( V_59 -> V_68 ) {
F_56 ( V_59 -> V_68 ) ;
V_59 -> V_68 = NULL ;
}
}
}
static void F_64 ( struct V_5 * V_6 , struct V_156 * V_157 )
{
struct V_8 * V_9 ;
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
int V_24 = 0 ;
struct V_10 * V_11 ;
struct V_158 * V_159 ;
int V_160 = 0 ;
int V_161 = 0 ;
T_1 V_38 ;
V_9 = V_157 -> V_9 ;
V_2 = V_9 -> V_2 ;
V_59 = V_6 -> V_60 + V_9 -> V_61 ;
V_11 = V_9 -> V_12 ;
V_159 = V_9 -> V_162 ;
F_12 ( V_9 , 0 ) ;
F_18 (t, &m->transfers, transfer_list) {
if ( V_34 -> V_112 == NULL && V_34 -> V_44 == NULL && V_34 -> V_40 ) {
V_161 = - V_163 ;
break;
}
if ( V_160 || V_34 -> V_123 || V_34 -> V_125 ) {
V_160 = 1 ;
V_161 = F_48 ( V_9 , V_34 ) ;
if ( V_161 < 0 )
break;
if ( ! V_34 -> V_123 && ! V_34 -> V_125 )
V_160 = 0 ;
}
if ( V_159 && V_159 -> V_164 ) {
V_38 = V_6 -> V_27 . V_32 ;
V_38 &= ~ V_31 ;
F_1 ( V_2 , V_28 , V_38 ) ;
V_6 -> V_27 . V_32 =
F_7 ( V_9 , V_28 ) ;
}
if ( ! V_24 ) {
F_13 ( V_9 , 1 ) ;
V_24 = 1 ;
}
V_38 = F_8 ( V_9 ) ;
V_38 &= ~ V_165 ;
V_38 &= ~ V_84 ;
if ( V_34 -> V_112 == NULL )
V_38 |= V_166 ;
else if ( V_34 -> V_44 == NULL )
V_38 |= V_167 ;
if ( V_159 && V_159 -> V_168 && V_34 -> V_112 == NULL ) {
if ( V_34 -> V_40 > ( ( V_11 -> V_15 + 7 ) >> 3 ) )
V_38 |= V_84 ;
}
F_9 ( V_9 , V_38 ) ;
if ( V_34 -> V_40 ) {
unsigned V_67 ;
if ( ( V_59 -> V_83 && V_59 -> V_68 ) &&
( V_157 -> V_169 || V_34 -> V_40 >= V_170 ) )
F_15 ( V_9 , V_34 , 1 ) ;
F_12 ( V_9 , 1 ) ;
if ( V_34 -> V_112 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_107 ) ;
if ( ( V_59 -> V_83 && V_59 -> V_68 ) &&
( V_157 -> V_169 || V_34 -> V_40 >= V_170 ) )
V_67 = F_44 ( V_9 , V_34 ) ;
else
V_67 = F_45 ( V_9 , V_34 ) ;
V_157 -> V_171 += V_67 ;
if ( V_67 != V_34 -> V_40 ) {
V_161 = - V_172 ;
break;
}
}
if ( V_34 -> V_173 )
F_65 ( V_34 -> V_173 ) ;
if ( V_34 -> V_174 ) {
F_13 ( V_9 , 0 ) ;
V_24 = 0 ;
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_36 > 0 )
F_15 ( V_9 , V_34 , 0 ) ;
}
if ( V_160 ) {
V_160 = 0 ;
V_161 = F_48 ( V_9 , NULL ) ;
}
if ( V_24 )
F_13 ( V_9 , 0 ) ;
if ( V_159 && V_159 -> V_164 ) {
V_38 = V_6 -> V_27 . V_32 ;
V_38 |= V_31 ;
F_1 ( V_2 , V_28 , V_38 ) ;
V_6 -> V_27 . V_32 =
F_7 ( V_9 , V_28 ) ;
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_36 > 0 && V_34 )
F_15 ( V_9 , V_34 , 0 ) ;
V_157 -> V_161 = V_161 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
struct V_8 * V_9 ;
struct V_5 * V_6 ;
struct V_58 * V_59 ;
struct V_33 * V_34 ;
V_9 = V_157 -> V_9 ;
V_6 = F_2 ( V_2 ) ;
V_59 = V_6 -> V_60 + V_9 -> V_61 ;
V_157 -> V_171 = 0 ;
V_157 -> V_161 = 0 ;
if ( F_67 ( & V_157 -> V_175 ) )
return - V_163 ;
F_18 (t, &m->transfers, transfer_list) {
const void * V_112 = V_34 -> V_112 ;
void * V_44 = V_34 -> V_44 ;
unsigned V_40 = V_34 -> V_40 ;
if ( V_34 -> V_123 > V_124
|| ( V_40 && ! ( V_44 || V_112 ) ) ) {
F_50 ( V_6 -> V_51 , L_20 ,
V_34 -> V_123 ,
V_40 ,
V_112 ? L_21 : L_22 ,
V_44 ? L_23 : L_22 ,
V_34 -> V_125 ) ;
return - V_163 ;
}
if ( V_34 -> V_123 && V_34 -> V_123 < ( V_124 >> 15 ) ) {
F_50 ( V_6 -> V_51 , L_24 ,
V_34 -> V_123 ,
V_124 >> 15 ) ;
return - V_163 ;
}
if ( V_157 -> V_169 || V_40 < V_170 )
continue;
if ( V_59 -> V_68 && V_112 != NULL ) {
V_34 -> V_73 = F_68 ( V_6 -> V_51 , ( void * ) V_112 ,
V_40 , V_113 ) ;
if ( F_69 ( V_6 -> V_51 , V_34 -> V_73 ) ) {
F_50 ( V_6 -> V_51 , L_25 ,
'T' , V_40 ) ;
return - V_163 ;
}
}
if ( V_59 -> V_83 && V_44 != NULL ) {
V_34 -> V_85 = F_68 ( V_6 -> V_51 , V_44 , V_34 -> V_40 ,
V_87 ) ;
if ( F_69 ( V_6 -> V_51 , V_34 -> V_85 ) ) {
F_50 ( V_6 -> V_51 , L_25 ,
'R' , V_40 ) ;
if ( V_112 != NULL )
F_41 ( V_6 -> V_51 , V_34 -> V_73 ,
V_40 , V_113 ) ;
return - V_163 ;
}
}
}
F_64 ( V_6 , V_157 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_26 * V_27 = & V_6 -> V_27 ;
int V_151 = 0 ;
V_151 = F_20 ( V_6 -> V_51 ) ;
if ( V_151 < 0 )
return V_151 ;
F_1 ( V_2 , V_49 ,
V_176 ) ;
V_27 -> V_50 = V_176 ;
F_14 ( V_2 ) ;
F_22 ( V_6 -> V_51 ) ;
F_23 ( V_6 -> V_51 ) ;
return 0 ;
}
static int F_72 ( struct V_177 * V_51 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_73 ( V_51 ) ;
V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_178 * V_179 )
{
struct V_1 * V_2 ;
const struct V_180 * V_181 ;
struct V_5 * V_6 ;
struct V_182 * V_183 ;
int V_161 = 0 , V_184 ;
T_1 V_185 = 0 ;
static int V_186 = 1 ;
struct V_187 * V_154 = V_179 -> V_51 . V_188 ;
const struct V_189 * V_190 ;
V_2 = F_75 ( & V_179 -> V_51 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_50 ( & V_179 -> V_51 , L_26 ) ;
return - V_153 ;
}
V_2 -> V_191 = V_137 | V_139 | V_134 ;
V_2 -> V_192 = F_76 ( 4 , 32 ) ;
V_2 -> V_193 = F_58 ;
V_2 -> V_194 = F_19 ;
V_2 -> V_195 = F_21 ;
V_2 -> V_196 = F_66 ;
V_2 -> V_197 = F_61 ;
V_2 -> V_51 . V_188 = V_154 ;
F_77 ( V_179 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_190 = F_78 ( V_198 , & V_179 -> V_51 ) ;
if ( V_190 ) {
T_1 V_199 = 1 ;
V_181 = V_190 -> V_57 ;
F_79 ( V_154 , L_27 , & V_199 ) ;
V_2 -> V_155 = V_199 ;
V_2 -> V_186 = V_186 ++ ;
if ( F_80 ( V_154 , L_28 , NULL ) )
V_6 -> V_127 = V_200 ;
} else {
V_181 = V_179 -> V_51 . V_201 ;
V_2 -> V_155 = V_181 -> V_199 ;
if ( V_179 -> V_202 != - 1 )
V_2 -> V_186 = V_179 -> V_202 ;
V_6 -> V_127 = V_181 -> V_127 ;
}
V_185 = V_181 -> V_185 ;
V_183 = F_81 ( V_179 , V_203 , 0 ) ;
if ( V_183 == NULL ) {
V_161 = - V_204 ;
goto V_205;
}
V_183 -> V_206 += V_185 ;
V_183 -> V_207 += V_185 ;
V_6 -> V_105 = V_183 -> V_206 ;
V_6 -> V_7 = F_82 ( & V_179 -> V_51 , V_183 ) ;
if ( F_83 ( V_6 -> V_7 ) ) {
V_161 = F_84 ( V_6 -> V_7 ) ;
goto V_205;
}
V_6 -> V_51 = & V_179 -> V_51 ;
F_85 ( & V_6 -> V_27 . V_11 ) ;
V_6 -> V_60 = F_86 ( V_2 -> V_155 ,
sizeof( struct V_58 ) ,
V_152 ) ;
if ( V_6 -> V_60 == NULL )
goto V_205;
for ( V_184 = 0 ; V_184 < V_2 -> V_155 ; V_184 ++ ) {
char * V_146 = V_6 -> V_60 [ V_184 ] . V_146 ;
char * V_149 = V_6 -> V_60 [ V_184 ] . V_149 ;
struct V_182 * V_208 ;
sprintf ( V_146 , L_29 , V_184 ) ;
if ( ! V_179 -> V_51 . V_188 ) {
V_208 =
F_87 ( V_179 ,
V_209 ,
V_146 ) ;
if ( ! V_208 ) {
F_50 ( & V_179 -> V_51 ,
L_30 ) ;
V_161 = - V_204 ;
break;
}
V_6 -> V_60 [ V_184 ] . V_144 =
V_208 -> V_206 ;
}
sprintf ( V_149 , L_31 , V_184 ) ;
if ( ! V_179 -> V_51 . V_188 ) {
V_208 =
F_87 ( V_179 ,
V_209 ,
V_149 ) ;
if ( ! V_208 ) {
F_50 ( & V_179 -> V_51 ,
L_32 ) ;
V_161 = - V_204 ;
break;
}
V_6 -> V_60 [ V_184 ] . V_148 =
V_208 -> V_206 ;
}
}
if ( V_161 < 0 )
goto V_210;
F_88 ( & V_179 -> V_51 ) ;
F_89 ( & V_179 -> V_51 , V_211 ) ;
F_90 ( & V_179 -> V_51 ) ;
V_161 = F_71 ( V_6 ) ;
if ( V_161 < 0 )
goto V_212;
V_161 = F_91 ( V_2 ) ;
if ( V_161 < 0 )
goto V_212;
return V_161 ;
V_212:
F_92 ( & V_179 -> V_51 ) ;
V_210:
F_63 ( V_6 -> V_60 ) ;
V_205:
F_93 ( V_2 ) ;
return V_161 ;
}
static int F_94 ( struct V_178 * V_179 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_58 * V_60 ;
V_2 = F_95 ( V_179 ) ;
V_6 = F_2 ( V_2 ) ;
V_60 = V_6 -> V_60 ;
F_96 ( V_6 -> V_51 ) ;
F_92 ( & V_179 -> V_51 ) ;
F_97 ( V_2 ) ;
F_63 ( V_60 ) ;
return 0 ;
}
static int F_98 ( struct V_177 * V_51 )
{
struct V_1 * V_2 = F_73 ( V_51 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_27 ;
struct V_10 * V_11 ;
F_20 ( V_6 -> V_51 ) ;
F_18 (cs, &ctx->cs, node) {
if ( ( V_11 -> V_13 & V_25 ) == 0 ) {
V_11 -> V_13 |= V_25 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
V_11 -> V_13 &= ~ V_25 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_22 ( V_6 -> V_51 ) ;
F_23 ( V_6 -> V_51 ) ;
return 0 ;
}
