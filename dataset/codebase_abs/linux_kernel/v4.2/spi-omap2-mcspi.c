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
T_1 V_18 ;
if ( V_9 -> V_25 & V_26 )
V_17 = ! V_17 ;
if ( V_9 -> V_12 ) {
V_18 = F_8 ( V_9 ) ;
if ( V_17 )
V_18 &= ~ V_27 ;
else
V_18 |= V_27 ;
F_9 ( V_9 , V_18 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_28 * V_29 = & V_6 -> V_29 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 , V_30 ) ;
V_18 &= ~ ( V_31 | V_32 ) ;
V_18 |= V_33 ;
F_1 ( V_2 , V_30 , V_18 ) ;
V_29 -> V_34 = V_18 ;
}
static void F_15 ( const struct V_8 * V_9 ,
struct V_35 * V_36 , int V_17 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
unsigned int V_37 ;
int V_38 , V_39 , V_40 ;
T_1 V_41 , V_42 ;
V_6 = F_2 ( V_2 ) ;
V_41 = F_8 ( V_9 ) ;
if ( V_17 ) {
V_40 = F_10 ( V_11 -> V_15 ) ;
if ( V_36 -> V_43 % V_40 != 0 )
goto V_44;
if ( V_36 -> V_45 != NULL && V_36 -> V_46 != NULL )
V_38 = V_47 / 2 ;
else
V_38 = V_47 ;
V_39 = F_16 ( V_36 -> V_43 , V_38 ) ;
if ( V_39 < 2 || V_39 % V_40 != 0 )
goto V_44;
V_37 = V_36 -> V_43 / V_40 ;
if ( V_37 > V_48 )
goto V_44;
V_42 = V_37 << 16 ;
if ( V_36 -> V_45 != NULL ) {
V_41 |= V_49 ;
V_42 |= ( V_39 - 1 ) << 8 ;
}
if ( V_36 -> V_46 != NULL ) {
V_41 |= V_50 ;
V_42 |= V_39 - 1 ;
}
F_1 ( V_2 , V_51 , V_42 ) ;
F_9 ( V_9 , V_41 ) ;
V_6 -> V_39 = V_39 ;
return;
}
V_44:
if ( V_36 -> V_45 != NULL )
V_41 &= ~ V_49 ;
if ( V_36 -> V_46 != NULL )
V_41 &= ~ V_50 ;
F_9 ( V_9 , V_41 ) ;
V_6 -> V_39 = 0 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_52 = V_6 -> V_2 ;
struct V_28 * V_29 = & V_6 -> V_29 ;
struct V_10 * V_11 ;
F_1 ( V_52 , V_30 , V_29 -> V_34 ) ;
F_1 ( V_52 , V_53 , V_29 -> V_54 ) ;
F_18 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static int F_19 ( void T_2 * V_55 , unsigned long V_56 )
{
unsigned long V_57 ;
V_57 = V_58 + F_20 ( 1000 ) ;
while ( ! ( F_5 ( V_55 ) & V_56 ) ) {
if ( F_21 ( V_58 , V_57 ) ) {
if ( ! ( F_5 ( V_55 ) & V_56 ) )
return - V_59 ;
else
return 0 ;
}
F_22 () ;
}
return 0 ;
}
static void F_23 ( void * V_60 )
{
struct V_8 * V_9 = V_60 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_61 * V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
F_11 ( V_9 , 1 , 0 ) ;
F_24 ( & V_62 -> V_65 ) ;
}
static void F_25 ( void * V_60 )
{
struct V_8 * V_9 = V_60 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_61 * V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
F_11 ( V_9 , 0 , 0 ) ;
F_24 ( & V_62 -> V_66 ) ;
}
static void F_26 ( struct V_8 * V_9 ,
struct V_35 * V_67 ,
struct V_68 V_69 )
{
struct V_5 * V_6 ;
struct V_61 * V_62 ;
unsigned int V_70 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
V_70 = V_67 -> V_43 ;
if ( V_62 -> V_71 ) {
struct V_72 * V_73 ;
struct V_74 V_75 ;
F_27 ( V_62 -> V_71 , & V_69 ) ;
F_28 ( & V_75 , 1 ) ;
F_29 ( & V_75 ) = V_67 -> V_76 ;
F_30 ( & V_75 ) = V_67 -> V_43 ;
V_73 = F_31 ( V_62 -> V_71 , & V_75 , 1 ,
V_77 , V_78 | V_79 ) ;
if ( V_73 ) {
V_73 -> V_80 = F_25 ;
V_73 -> V_81 = V_9 ;
F_32 ( V_73 ) ;
} else {
}
}
F_33 ( V_62 -> V_71 ) ;
F_11 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_34 ( struct V_8 * V_9 , struct V_35 * V_67 ,
struct V_68 V_69 ,
unsigned V_82 )
{
struct V_5 * V_6 ;
struct V_61 * V_62 ;
unsigned int V_70 , V_83 ;
T_1 V_18 ;
int V_84 = 0 ;
int V_15 , V_85 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
V_70 = V_67 -> V_43 ;
V_83 = V_67 -> V_43 ;
if ( V_6 -> V_39 == 0 )
V_83 -= V_82 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
if ( V_15 <= 8 )
V_85 = V_70 ;
else if ( V_15 <= 16 )
V_85 = V_70 >> 1 ;
else
V_85 = V_70 >> 2 ;
if ( V_62 -> V_86 ) {
struct V_72 * V_73 ;
struct V_74 V_75 ;
F_27 ( V_62 -> V_86 , & V_69 ) ;
if ( ( V_18 & V_87 ) && V_6 -> V_39 == 0 )
V_83 -= V_82 ;
F_28 ( & V_75 , 1 ) ;
F_29 ( & V_75 ) = V_67 -> V_88 ;
F_30 ( & V_75 ) = V_83 ;
V_73 = F_31 ( V_62 -> V_86 , & V_75 , 1 ,
V_89 , V_78 |
V_79 ) ;
if ( V_73 ) {
V_73 -> V_80 = F_23 ;
V_73 -> V_81 = V_9 ;
F_32 ( V_73 ) ;
} else {
}
}
F_33 ( V_62 -> V_86 ) ;
F_11 ( V_9 , 1 , 1 ) ;
F_35 ( & V_62 -> V_65 ) ;
F_36 ( V_6 -> V_90 , V_67 -> V_88 , V_70 ,
V_91 ) ;
if ( V_6 -> V_39 > 0 )
return V_70 ;
F_12 ( V_9 , 0 ) ;
V_84 = V_85 - 1 ;
if ( V_18 & V_87 ) {
V_84 -- ;
if ( F_37 ( F_7 ( V_9 , V_92 )
& V_93 ) ) {
T_1 V_94 ;
V_94 = F_7 ( V_9 , V_95 ) ;
if ( V_15 <= 8 )
( ( V_96 * ) V_67 -> V_45 ) [ V_84 ++ ] = V_94 ;
else if ( V_15 <= 16 )
( ( V_97 * ) V_67 -> V_45 ) [ V_84 ++ ] = V_94 ;
else
( ( T_1 * ) V_67 -> V_45 ) [ V_84 ++ ] = V_94 ;
} else {
int V_40 = F_10 ( V_15 ) ;
F_38 ( & V_9 -> V_90 , L_1 ) ;
V_70 -= ( V_40 << 1 ) ;
F_12 ( V_9 , 1 ) ;
return V_70 ;
}
}
if ( F_37 ( F_7 ( V_9 , V_92 )
& V_93 ) ) {
T_1 V_94 ;
V_94 = F_7 ( V_9 , V_95 ) ;
if ( V_15 <= 8 )
( ( V_96 * ) V_67 -> V_45 ) [ V_84 ] = V_94 ;
else if ( V_15 <= 16 )
( ( V_97 * ) V_67 -> V_45 ) [ V_84 ] = V_94 ;
else
( ( T_1 * ) V_67 -> V_45 ) [ V_84 ] = V_94 ;
} else {
F_38 ( & V_9 -> V_90 , L_2 ) ;
V_70 -= F_10 ( V_15 ) ;
}
F_12 ( V_9 , 1 ) ;
return V_70 ;
}
static unsigned
F_39 ( struct V_8 * V_9 , struct V_35 * V_67 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_61 * V_62 ;
unsigned int V_70 ;
T_1 V_18 ;
V_96 * V_98 ;
const V_96 * V_73 ;
struct V_68 V_69 ;
enum V_99 V_100 ;
unsigned V_82 ;
T_1 V_101 ;
void T_2 * V_102 ;
void T_2 * V_103 ;
int V_104 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
V_18 = F_8 ( V_9 ) ;
if ( V_11 -> V_15 <= 8 ) {
V_100 = V_105 ;
V_82 = 1 ;
} else if ( V_11 -> V_15 <= 16 ) {
V_100 = V_106 ;
V_82 = 2 ;
} else {
V_100 = V_107 ;
V_82 = 4 ;
}
V_70 = V_67 -> V_43 ;
V_101 = 1 ;
if ( V_6 -> V_39 > 0 ) {
if ( V_70 > V_6 -> V_39 )
V_101 = V_6 -> V_39 / V_82 ;
else
V_101 = V_70 / V_82 ;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_108 = V_11 -> V_109 + V_95 ;
V_69 . V_110 = V_11 -> V_109 + V_111 ;
V_69 . V_112 = V_100 ;
V_69 . V_113 = V_100 ;
V_69 . V_114 = V_101 ;
V_69 . V_115 = V_101 ;
V_98 = V_67 -> V_45 ;
V_73 = V_67 -> V_46 ;
if ( V_73 != NULL )
F_26 ( V_9 , V_67 , V_69 ) ;
if ( V_98 != NULL )
V_70 = F_34 ( V_9 , V_67 , V_69 , V_82 ) ;
if ( V_73 != NULL ) {
F_35 ( & V_62 -> V_66 ) ;
F_36 ( V_6 -> V_90 , V_67 -> V_76 , V_67 -> V_43 ,
V_116 ) ;
if ( V_6 -> V_39 > 0 ) {
V_103 = V_6 -> V_7 + V_117 ;
if ( F_19 ( V_103 ,
V_118 ) < 0 )
F_38 ( & V_9 -> V_90 , L_3 ) ;
F_1 ( V_6 -> V_2 , V_117 ,
V_118 ) ;
}
if ( V_98 == NULL ) {
V_102 = V_11 -> V_7 + V_92 ;
if ( V_6 -> V_39 > 0 ) {
V_104 = F_19 ( V_102 ,
V_119 ) ;
if ( V_104 < 0 )
F_38 ( & V_9 -> V_90 , L_4 ) ;
} else {
V_104 = F_19 ( V_102 ,
V_120 ) ;
if ( V_104 < 0 )
F_38 ( & V_9 -> V_90 , L_5 ) ;
}
if ( V_104 >= 0 &&
( F_19 ( V_102 ,
V_121 ) < 0 ) )
F_38 ( & V_9 -> V_90 , L_6 ) ;
}
}
return V_70 ;
}
static unsigned
F_40 ( struct V_8 * V_9 , struct V_35 * V_67 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_70 , V_122 ;
T_1 V_18 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_123 ;
void T_2 * V_124 ;
void T_2 * V_102 ;
int V_15 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_70 = V_67 -> V_43 ;
V_122 = V_70 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
V_123 = V_7 + V_111 ;
V_124 = V_7 + V_95 ;
V_102 = V_7 + V_92 ;
if ( V_122 < ( V_15 >> 3 ) )
return 0 ;
if ( V_15 <= 8 ) {
V_96 * V_98 ;
const V_96 * V_73 ;
V_98 = V_67 -> V_45 ;
V_73 = V_67 -> V_46 ;
do {
V_122 -= 1 ;
if ( V_73 != NULL ) {
if ( F_19 ( V_102 ,
V_120 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_5 ) ;
goto V_125;
}
F_41 ( & V_9 -> V_90 , L_7 ,
V_15 , * V_73 ) ;
F_3 ( * V_73 ++ , V_123 ) ;
}
if ( V_98 != NULL ) {
if ( F_19 ( V_102 ,
V_93 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_8 ) ;
goto V_125;
}
if ( V_122 == 1 && V_73 == NULL &&
( V_18 & V_87 ) ) {
F_12 ( V_9 , 0 ) ;
* V_98 ++ = F_5 ( V_124 ) ;
F_41 ( & V_9 -> V_90 , L_9 ,
V_15 , * ( V_98 - 1 ) ) ;
if ( F_19 ( V_102 ,
V_93 ) < 0 ) {
F_38 ( & V_9 -> V_90 ,
L_8 ) ;
goto V_125;
}
V_122 = 0 ;
} else if ( V_122 == 0 && V_73 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_98 ++ = F_5 ( V_124 ) ;
F_41 ( & V_9 -> V_90 , L_9 ,
V_15 , * ( V_98 - 1 ) ) ;
}
} while ( V_122 );
} else if ( V_15 <= 16 ) {
V_97 * V_98 ;
const V_97 * V_73 ;
V_98 = V_67 -> V_45 ;
V_73 = V_67 -> V_46 ;
do {
V_122 -= 2 ;
if ( V_73 != NULL ) {
if ( F_19 ( V_102 ,
V_120 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_5 ) ;
goto V_125;
}
F_41 ( & V_9 -> V_90 , L_10 ,
V_15 , * V_73 ) ;
F_3 ( * V_73 ++ , V_123 ) ;
}
if ( V_98 != NULL ) {
if ( F_19 ( V_102 ,
V_93 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_8 ) ;
goto V_125;
}
if ( V_122 == 2 && V_73 == NULL &&
( V_18 & V_87 ) ) {
F_12 ( V_9 , 0 ) ;
* V_98 ++ = F_5 ( V_124 ) ;
F_41 ( & V_9 -> V_90 , L_11 ,
V_15 , * ( V_98 - 1 ) ) ;
if ( F_19 ( V_102 ,
V_93 ) < 0 ) {
F_38 ( & V_9 -> V_90 ,
L_8 ) ;
goto V_125;
}
V_122 = 0 ;
} else if ( V_122 == 0 && V_73 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_98 ++ = F_5 ( V_124 ) ;
F_41 ( & V_9 -> V_90 , L_11 ,
V_15 , * ( V_98 - 1 ) ) ;
}
} while ( V_122 >= 2 );
} else if ( V_15 <= 32 ) {
T_1 * V_98 ;
const T_1 * V_73 ;
V_98 = V_67 -> V_45 ;
V_73 = V_67 -> V_46 ;
do {
V_122 -= 4 ;
if ( V_73 != NULL ) {
if ( F_19 ( V_102 ,
V_120 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_5 ) ;
goto V_125;
}
F_41 ( & V_9 -> V_90 , L_12 ,
V_15 , * V_73 ) ;
F_3 ( * V_73 ++ , V_123 ) ;
}
if ( V_98 != NULL ) {
if ( F_19 ( V_102 ,
V_93 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_8 ) ;
goto V_125;
}
if ( V_122 == 4 && V_73 == NULL &&
( V_18 & V_87 ) ) {
F_12 ( V_9 , 0 ) ;
* V_98 ++ = F_5 ( V_124 ) ;
F_41 ( & V_9 -> V_90 , L_13 ,
V_15 , * ( V_98 - 1 ) ) ;
if ( F_19 ( V_102 ,
V_93 ) < 0 ) {
F_38 ( & V_9 -> V_90 ,
L_8 ) ;
goto V_125;
}
V_122 = 0 ;
} else if ( V_122 == 0 && V_73 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_98 ++ = F_5 ( V_124 ) ;
F_41 ( & V_9 -> V_90 , L_13 ,
V_15 , * ( V_98 - 1 ) ) ;
}
} while ( V_122 >= 4 );
}
if ( V_67 -> V_45 == NULL ) {
if ( F_19 ( V_102 ,
V_120 ) < 0 ) {
F_38 ( & V_9 -> V_90 , L_5 ) ;
} else if ( F_19 ( V_102 ,
V_121 ) < 0 )
F_38 ( & V_9 -> V_90 , L_6 ) ;
F_12 ( V_9 , 0 ) ;
}
V_125:
F_12 ( V_9 , 1 ) ;
return V_70 - V_122 ;
}
static T_1 F_42 ( T_1 V_126 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_126 >= ( V_127 >> div ) )
return div ;
return 15 ;
}
static int F_43 ( struct V_8 * V_9 ,
struct V_35 * V_36 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_52 ;
T_1 V_18 = 0 , V_128 = 0 , div , V_129 = 0 , V_130 = 0 ;
V_96 V_15 = V_9 -> V_131 ;
T_1 V_126 = V_9 -> V_132 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_52 = V_6 -> V_2 ;
if ( V_36 != NULL && V_36 -> V_131 )
V_15 = V_36 -> V_131 ;
V_11 -> V_15 = V_15 ;
if ( V_36 && V_36 -> V_126 )
V_126 = V_36 -> V_126 ;
V_126 = F_44 ( T_1 , V_126 , V_127 ) ;
if ( V_126 < ( V_127 / V_133 ) ) {
V_128 = F_42 ( V_126 ) ;
V_126 = V_127 >> V_128 ;
V_130 = 0 ;
} else {
div = ( V_127 + V_126 - 1 ) / V_126 ;
V_126 = V_127 / div ;
V_128 = ( div - 1 ) & 0xf ;
V_129 = ( div - 1 ) >> 4 ;
V_130 = V_134 ;
}
V_18 = F_8 ( V_9 ) ;
if ( V_6 -> V_135 == V_136 ) {
V_18 &= ~ V_137 ;
V_18 &= ~ V_138 ;
V_18 |= V_139 ;
} else {
V_18 |= V_137 ;
V_18 |= V_138 ;
V_18 &= ~ V_139 ;
}
V_18 &= ~ V_140 ;
V_18 |= ( V_15 - 1 ) << 7 ;
if ( ! ( V_9 -> V_25 & V_26 ) )
V_18 |= V_141 ;
else
V_18 &= ~ V_141 ;
V_18 &= ~ V_142 ;
V_18 |= V_128 << 2 ;
V_18 &= ~ V_134 ;
V_18 |= V_130 ;
if ( V_130 ) {
V_11 -> V_22 &= ~ V_143 ;
V_11 -> V_22 |= V_129 << 8 ;
F_6 ( V_9 , V_24 , V_11 -> V_22 ) ;
}
if ( V_9 -> V_25 & V_144 )
V_18 |= V_145 ;
else
V_18 &= ~ V_145 ;
if ( V_9 -> V_25 & V_146 )
V_18 |= V_147 ;
else
V_18 &= ~ V_147 ;
F_9 ( V_9 , V_18 ) ;
V_11 -> V_25 = V_9 -> V_25 ;
F_45 ( & V_9 -> V_90 , L_14 ,
V_126 ,
( V_9 -> V_25 & V_146 ) ? L_15 : L_16 ,
( V_9 -> V_25 & V_144 ) ? L_17 : L_18 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_61 * V_62 ;
T_3 V_148 ;
unsigned V_149 ;
V_6 = F_2 ( V_2 ) ;
V_62 = V_6 -> V_63 + V_9 -> V_64 ;
F_47 ( & V_62 -> V_65 ) ;
F_47 ( & V_62 -> V_66 ) ;
F_48 ( V_148 ) ;
F_49 ( V_150 , V_148 ) ;
V_149 = V_62 -> V_151 ;
V_62 -> V_86 =
F_50 ( V_148 , V_152 ,
& V_149 , & V_2 -> V_90 ,
V_62 -> V_153 ) ;
if ( ! V_62 -> V_86 )
goto V_154;
V_149 = V_62 -> V_155 ;
V_62 -> V_71 =
F_50 ( V_148 , V_152 ,
& V_149 , & V_2 -> V_90 ,
V_62 -> V_156 ) ;
if ( ! V_62 -> V_71 ) {
F_51 ( V_62 -> V_86 ) ;
V_62 -> V_86 = NULL ;
goto V_154;
}
return 0 ;
V_154:
F_52 ( & V_9 -> V_90 , L_19 ) ;
return - V_157 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_158 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_28 * V_29 = & V_6 -> V_29 ;
struct V_61 * V_62 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
if ( ! V_11 ) {
V_11 = F_54 ( sizeof *V_11 , V_159 ) ;
if ( ! V_11 )
return - V_160 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_64 * 0x14 ;
V_11 -> V_109 = V_6 -> V_109 + V_9 -> V_64 * 0x14 ;
V_11 -> V_25 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_22 = 0 ;
V_9 -> V_12 = V_11 ;
F_55 ( & V_11 -> V_161 , & V_29 -> V_11 ) ;
}
if ( ! V_62 -> V_86 || ! V_62 -> V_71 ) {
V_158 = F_46 ( V_9 ) ;
if ( V_158 < 0 && V_158 != - V_157 )
return V_158 ;
}
if ( F_56 ( V_9 -> V_162 ) ) {
V_158 = F_57 ( V_9 -> V_162 , F_58 ( & V_9 -> V_90 ) ) ;
if ( V_158 ) {
F_38 ( & V_9 -> V_90 , L_20 ) ;
return V_158 ;
}
F_59 ( V_9 -> V_162 , ! ( V_9 -> V_25 & V_26 ) ) ;
}
V_158 = F_60 ( V_6 -> V_90 ) ;
if ( V_158 < 0 )
return V_158 ;
V_158 = F_43 ( V_9 , NULL ) ;
F_61 ( V_6 -> V_90 ) ;
F_62 ( V_6 -> V_90 ) ;
return V_158 ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_61 * V_62 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_64 ( & V_11 -> V_161 ) ;
F_65 ( V_11 ) ;
}
if ( V_9 -> V_64 < V_9 -> V_2 -> V_163 ) {
V_62 = & V_6 -> V_63 [ V_9 -> V_64 ] ;
if ( V_62 -> V_86 ) {
F_51 ( V_62 -> V_86 ) ;
V_62 -> V_86 = NULL ;
}
if ( V_62 -> V_71 ) {
F_51 ( V_62 -> V_71 ) ;
V_62 -> V_71 = NULL ;
}
}
if ( F_56 ( V_9 -> V_162 ) )
F_66 ( V_9 -> V_162 ) ;
}
static int F_67 ( struct V_5 * V_6 ,
struct V_8 * V_9 , struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_61 * V_62 ;
struct V_10 * V_11 ;
struct V_164 * V_165 ;
int V_166 = 0 ;
int V_167 = 0 ;
T_1 V_41 ;
V_2 = V_9 -> V_2 ;
V_62 = V_6 -> V_63 + V_9 -> V_64 ;
V_11 = V_9 -> V_12 ;
V_165 = V_9 -> V_168 ;
if ( V_9 -> V_25 != V_11 -> V_25 )
V_166 = 1 ;
F_12 ( V_9 , 0 ) ;
if ( F_56 ( V_9 -> V_162 ) )
F_13 ( V_9 , V_9 -> V_25 & V_26 ) ;
if ( V_166 ||
( V_36 -> V_126 != V_9 -> V_132 ) ||
( V_36 -> V_131 != V_9 -> V_131 ) ) {
V_166 = 1 ;
V_167 = F_43 ( V_9 , V_36 ) ;
if ( V_167 < 0 )
goto V_125;
if ( V_36 -> V_126 == V_9 -> V_132 &&
V_36 -> V_131 == V_9 -> V_131 )
V_166 = 0 ;
}
if ( V_165 && V_165 -> V_169 ) {
V_41 = V_6 -> V_29 . V_34 ;
V_41 &= ~ V_33 ;
F_1 ( V_2 , V_30 , V_41 ) ;
V_6 -> V_29 . V_34 =
F_7 ( V_9 , V_30 ) ;
}
V_41 = F_8 ( V_9 ) ;
V_41 &= ~ V_170 ;
V_41 &= ~ V_87 ;
if ( V_36 -> V_46 == NULL )
V_41 |= V_171 ;
else if ( V_36 -> V_45 == NULL )
V_41 |= V_172 ;
if ( V_165 && V_165 -> V_173 && V_36 -> V_46 == NULL ) {
if ( V_36 -> V_43 > ( ( V_11 -> V_15 + 7 ) >> 3 ) )
V_41 |= V_87 ;
}
F_9 ( V_9 , V_41 ) ;
if ( V_36 -> V_43 ) {
unsigned V_70 ;
if ( ( V_62 -> V_86 && V_62 -> V_71 ) &&
( V_36 -> V_43 >= V_174 ) )
F_15 ( V_9 , V_36 , 1 ) ;
F_12 ( V_9 , 1 ) ;
if ( V_36 -> V_46 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_111 ) ;
if ( ( V_62 -> V_86 && V_62 -> V_71 ) &&
( V_36 -> V_43 >= V_174 ) )
V_70 = F_39 ( V_9 , V_36 ) ;
else
V_70 = F_40 ( V_9 , V_36 ) ;
if ( V_70 != V_36 -> V_43 ) {
V_167 = - V_175 ;
goto V_125;
}
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_39 > 0 )
F_15 ( V_9 , V_36 , 0 ) ;
V_125:
if ( V_166 ) {
V_166 = 0 ;
V_167 = F_43 ( V_9 , NULL ) ;
}
if ( V_165 && V_165 -> V_169 ) {
V_41 = V_6 -> V_29 . V_34 ;
V_41 |= V_33 ;
F_1 ( V_2 , V_30 , V_41 ) ;
V_6 -> V_29 . V_34 =
F_7 ( V_9 , V_30 ) ;
}
F_12 ( V_9 , 0 ) ;
if ( F_56 ( V_9 -> V_162 ) )
F_13 ( V_9 , ! ( V_9 -> V_25 & V_26 ) ) ;
if ( V_6 -> V_39 > 0 && V_36 )
F_15 ( V_9 , V_36 , 0 ) ;
return V_167 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 , struct V_35 * V_36 )
{
struct V_5 * V_6 ;
struct V_61 * V_62 ;
const void * V_46 = V_36 -> V_46 ;
void * V_45 = V_36 -> V_45 ;
unsigned V_43 = V_36 -> V_43 ;
V_6 = F_2 ( V_2 ) ;
V_62 = V_6 -> V_63 + V_9 -> V_64 ;
if ( ( V_43 && ! ( V_45 || V_46 ) ) ) {
F_45 ( V_6 -> V_90 , L_21 ,
V_36 -> V_126 ,
V_43 ,
V_46 ? L_22 : L_23 ,
V_45 ? L_24 : L_23 ,
V_36 -> V_131 ) ;
return - V_176 ;
}
if ( V_43 < V_174 )
goto V_177;
if ( V_62 -> V_71 && V_46 != NULL ) {
V_36 -> V_76 = F_69 ( V_6 -> V_90 , ( void * ) V_46 ,
V_43 , V_116 ) ;
if ( F_70 ( V_6 -> V_90 , V_36 -> V_76 ) ) {
F_45 ( V_6 -> V_90 , L_25 ,
'T' , V_43 ) ;
return - V_176 ;
}
}
if ( V_62 -> V_86 && V_45 != NULL ) {
V_36 -> V_88 = F_69 ( V_6 -> V_90 , V_45 , V_36 -> V_43 ,
V_91 ) ;
if ( F_70 ( V_6 -> V_90 , V_36 -> V_88 ) ) {
F_45 ( V_6 -> V_90 , L_25 ,
'R' , V_43 ) ;
if ( V_46 != NULL )
F_36 ( V_6 -> V_90 , V_36 -> V_76 ,
V_43 , V_116 ) ;
return - V_176 ;
}
}
V_177:
return F_67 ( V_6 , V_9 , V_36 ) ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_28 * V_29 = & V_6 -> V_29 ;
int V_158 = 0 ;
V_158 = F_60 ( V_6 -> V_90 ) ;
if ( V_158 < 0 )
return V_158 ;
F_1 ( V_2 , V_53 ,
V_178 ) ;
V_29 -> V_54 = V_178 ;
F_14 ( V_2 ) ;
F_61 ( V_6 -> V_90 ) ;
F_62 ( V_6 -> V_90 ) ;
return 0 ;
}
static int F_72 ( struct V_179 * V_90 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_73 ( V_90 ) ;
V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_180 * V_181 )
{
struct V_1 * V_2 ;
const struct V_182 * V_183 ;
struct V_5 * V_6 ;
struct V_184 * V_185 ;
int V_167 = 0 , V_186 ;
T_1 V_187 = 0 ;
static int V_188 = 1 ;
struct V_189 * V_161 = V_181 -> V_90 . V_190 ;
const struct V_191 * V_192 ;
V_2 = F_75 ( & V_181 -> V_90 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_45 ( & V_181 -> V_90 , L_26 ) ;
return - V_160 ;
}
V_2 -> V_193 = V_144 | V_146 | V_26 ;
V_2 -> V_194 = F_76 ( 4 , 32 ) ;
V_2 -> V_195 = F_53 ;
V_2 -> V_196 = true ;
V_2 -> V_197 = F_68 ;
V_2 -> V_198 = F_13 ;
V_2 -> V_199 = F_63 ;
V_2 -> V_90 . V_190 = V_161 ;
V_2 -> V_132 = V_127 ;
V_2 -> V_200 = V_127 >> 15 ;
F_77 ( V_181 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_192 = F_78 ( V_201 , & V_181 -> V_90 ) ;
if ( V_192 ) {
T_1 V_202 = 1 ;
V_183 = V_192 -> V_60 ;
F_79 ( V_161 , L_27 , & V_202 ) ;
V_2 -> V_163 = V_202 ;
V_2 -> V_188 = V_188 ++ ;
if ( F_80 ( V_161 , L_28 , NULL ) )
V_6 -> V_135 = V_203 ;
} else {
V_183 = F_81 ( & V_181 -> V_90 ) ;
V_2 -> V_163 = V_183 -> V_202 ;
if ( V_181 -> V_204 != - 1 )
V_2 -> V_188 = V_181 -> V_204 ;
V_6 -> V_135 = V_183 -> V_135 ;
}
V_187 = V_183 -> V_187 ;
V_185 = F_82 ( V_181 , V_205 , 0 ) ;
if ( V_185 == NULL ) {
V_167 = - V_206 ;
goto V_207;
}
V_185 -> V_208 += V_187 ;
V_185 -> V_209 += V_187 ;
V_6 -> V_109 = V_185 -> V_208 ;
V_6 -> V_7 = F_83 ( & V_181 -> V_90 , V_185 ) ;
if ( F_84 ( V_6 -> V_7 ) ) {
V_167 = F_85 ( V_6 -> V_7 ) ;
goto V_207;
}
V_6 -> V_90 = & V_181 -> V_90 ;
F_86 ( & V_6 -> V_29 . V_11 ) ;
V_6 -> V_63 = F_87 ( & V_181 -> V_90 , V_2 -> V_163 ,
sizeof( struct V_61 ) ,
V_159 ) ;
if ( V_6 -> V_63 == NULL ) {
V_167 = - V_160 ;
goto V_207;
}
for ( V_186 = 0 ; V_186 < V_2 -> V_163 ; V_186 ++ ) {
char * V_153 = V_6 -> V_63 [ V_186 ] . V_153 ;
char * V_156 = V_6 -> V_63 [ V_186 ] . V_156 ;
struct V_184 * V_210 ;
sprintf ( V_153 , L_29 , V_186 ) ;
if ( ! V_181 -> V_90 . V_190 ) {
V_210 =
F_88 ( V_181 ,
V_211 ,
V_153 ) ;
if ( ! V_210 ) {
F_45 ( & V_181 -> V_90 ,
L_30 ) ;
V_167 = - V_206 ;
break;
}
V_6 -> V_63 [ V_186 ] . V_151 =
V_210 -> V_208 ;
}
sprintf ( V_156 , L_31 , V_186 ) ;
if ( ! V_181 -> V_90 . V_190 ) {
V_210 =
F_88 ( V_181 ,
V_211 ,
V_156 ) ;
if ( ! V_210 ) {
F_45 ( & V_181 -> V_90 ,
L_32 ) ;
V_167 = - V_206 ;
break;
}
V_6 -> V_63 [ V_186 ] . V_155 =
V_210 -> V_208 ;
}
}
if ( V_167 < 0 )
goto V_207;
F_89 ( & V_181 -> V_90 ) ;
F_90 ( & V_181 -> V_90 , V_212 ) ;
F_91 ( & V_181 -> V_90 ) ;
V_167 = F_71 ( V_6 ) ;
if ( V_167 < 0 )
goto V_213;
V_167 = F_92 ( & V_181 -> V_90 , V_2 ) ;
if ( V_167 < 0 )
goto V_213;
return V_167 ;
V_213:
F_93 ( & V_181 -> V_90 ) ;
V_207:
F_94 ( V_2 ) ;
return V_167 ;
}
static int F_95 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = F_96 ( V_181 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_97 ( V_6 -> V_90 ) ;
F_93 ( & V_181 -> V_90 ) ;
return 0 ;
}
static int F_98 ( struct V_179 * V_90 )
{
struct V_1 * V_2 = F_73 ( V_90 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_28 * V_29 = & V_6 -> V_29 ;
struct V_10 * V_11 ;
F_60 ( V_6 -> V_90 ) ;
F_18 (cs, &ctx->cs, node) {
if ( ( V_11 -> V_13 & V_27 ) == 0 ) {
V_11 -> V_13 |= V_27 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
V_11 -> V_13 &= ~ V_27 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_61 ( V_6 -> V_90 ) ;
F_62 ( V_6 -> V_90 ) ;
return 0 ;
}
