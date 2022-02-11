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
F_31 ( V_64 -> V_73 , & V_71 ) ;
V_75 = F_32 ( V_64 -> V_73 , V_69 -> V_76 . V_77 ,
V_69 -> V_76 . V_78 ,
V_79 ,
V_80 | V_81 ) ;
if ( V_75 ) {
V_75 -> V_82 = F_29 ;
V_75 -> V_83 = V_9 ;
F_33 ( V_75 ) ;
} else {
}
}
F_34 ( V_64 -> V_73 ) ;
F_11 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_35 ( struct V_8 * V_9 , struct V_37 * V_69 ,
struct V_70 V_71 ,
unsigned V_84 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
unsigned int V_72 , V_85 = 0 ;
struct V_86 * V_87 [ 2 ] ;
int V_88 = 0 , V_89 [ 2 ] , V_90 , V_91 ;
T_3 V_92 [ 2 ] ;
T_1 V_18 ;
int V_93 = 0 ;
int V_15 , V_94 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
V_72 = V_69 -> V_45 ;
if ( V_6 -> V_41 == 0 )
V_85 = V_84 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
if ( V_15 <= 8 )
V_94 = V_72 ;
else if ( V_15 <= 16 )
V_94 = V_72 >> 1 ;
else
V_94 = V_72 >> 2 ;
if ( V_64 -> V_95 ) {
struct V_74 * V_75 ;
F_31 ( V_64 -> V_95 , & V_71 ) ;
if ( ( V_18 & V_96 ) && V_6 -> V_41 == 0 )
V_85 += V_84 ;
if ( V_85 ) {
V_92 [ 0 ] = V_72 - V_85 ;
V_92 [ 1 ] = V_85 ;
V_88 = 2 ;
} else {
V_92 [ 0 ] = V_72 ;
V_88 = 1 ;
}
V_90 = F_36 ( V_69 -> V_97 . V_77 , V_69 -> V_97 . V_78 ,
0 , V_88 ,
V_92 ,
V_87 , V_89 ,
V_98 ) ;
if ( V_90 < 0 ) {
F_15 ( & V_9 -> V_28 , L_2 ) ;
return 0 ;
}
V_75 = F_32 ( V_64 -> V_95 ,
V_87 [ 0 ] ,
V_89 [ 0 ] ,
V_99 ,
V_80 | V_81 ) ;
if ( V_75 ) {
V_75 -> V_82 = F_27 ;
V_75 -> V_83 = V_9 ;
F_33 ( V_75 ) ;
} else {
}
}
F_34 ( V_64 -> V_95 ) ;
F_11 ( V_9 , 1 , 1 ) ;
F_37 ( & V_64 -> V_67 ) ;
for ( V_91 = 0 ; V_91 < V_88 ; V_91 ++ )
F_38 ( V_87 [ V_91 ] ) ;
if ( V_6 -> V_41 > 0 )
return V_72 ;
F_12 ( V_9 , 0 ) ;
V_93 = V_94 - 1 ;
if ( V_18 & V_96 ) {
V_93 -- ;
if ( F_39 ( F_7 ( V_9 , V_100 )
& V_101 ) ) {
T_1 V_102 ;
V_102 = F_7 ( V_9 , V_103 ) ;
if ( V_15 <= 8 )
( ( V_104 * ) V_69 -> V_47 ) [ V_93 ++ ] = V_102 ;
else if ( V_15 <= 16 )
( ( V_105 * ) V_69 -> V_47 ) [ V_93 ++ ] = V_102 ;
else
( ( T_1 * ) V_69 -> V_47 ) [ V_93 ++ ] = V_102 ;
} else {
int V_42 = F_10 ( V_15 ) ;
F_15 ( & V_9 -> V_28 , L_3 ) ;
V_72 -= ( V_42 << 1 ) ;
F_12 ( V_9 , 1 ) ;
return V_72 ;
}
}
if ( F_39 ( F_7 ( V_9 , V_100 )
& V_101 ) ) {
T_1 V_102 ;
V_102 = F_7 ( V_9 , V_103 ) ;
if ( V_15 <= 8 )
( ( V_104 * ) V_69 -> V_47 ) [ V_93 ] = V_102 ;
else if ( V_15 <= 16 )
( ( V_105 * ) V_69 -> V_47 ) [ V_93 ] = V_102 ;
else
( ( T_1 * ) V_69 -> V_47 ) [ V_93 ] = V_102 ;
} else {
F_15 ( & V_9 -> V_28 , L_4 ) ;
V_72 -= F_10 ( V_15 ) ;
}
F_12 ( V_9 , 1 ) ;
return V_72 ;
}
static unsigned
F_40 ( struct V_8 * V_9 , struct V_37 * V_69 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_63 * V_64 ;
unsigned int V_72 ;
T_1 V_18 ;
V_104 * V_106 ;
const V_104 * V_75 ;
struct V_70 V_71 ;
enum V_107 V_108 ;
unsigned V_84 ;
T_1 V_109 ;
void T_2 * V_110 ;
void T_2 * V_111 ;
int V_112 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
V_18 = F_8 ( V_9 ) ;
if ( V_11 -> V_15 <= 8 ) {
V_108 = V_113 ;
V_84 = 1 ;
} else if ( V_11 -> V_15 <= 16 ) {
V_108 = V_114 ;
V_84 = 2 ;
} else {
V_108 = V_115 ;
V_84 = 4 ;
}
V_72 = V_69 -> V_45 ;
V_109 = 1 ;
if ( V_6 -> V_41 > 0 ) {
if ( V_72 > V_6 -> V_41 )
V_109 = V_6 -> V_41 / V_84 ;
else
V_109 = V_72 / V_84 ;
}
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_116 = V_11 -> V_117 + V_103 ;
V_71 . V_118 = V_11 -> V_117 + V_119 ;
V_71 . V_120 = V_108 ;
V_71 . V_121 = V_108 ;
V_71 . V_122 = V_109 ;
V_71 . V_123 = V_109 ;
V_106 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
if ( V_75 != NULL )
F_30 ( V_9 , V_69 , V_71 ) ;
if ( V_106 != NULL )
V_72 = F_35 ( V_9 , V_69 , V_71 , V_84 ) ;
if ( V_75 != NULL ) {
F_37 ( & V_64 -> V_68 ) ;
if ( V_6 -> V_41 > 0 ) {
V_111 = V_6 -> V_7 + V_124 ;
if ( F_23 ( V_111 ,
V_125 ) < 0 )
F_15 ( & V_9 -> V_28 , L_5 ) ;
F_1 ( V_6 -> V_2 , V_124 ,
V_125 ) ;
}
if ( V_106 == NULL ) {
V_110 = V_11 -> V_7 + V_100 ;
if ( V_6 -> V_41 > 0 ) {
V_112 = F_23 ( V_110 ,
V_126 ) ;
if ( V_112 < 0 )
F_15 ( & V_9 -> V_28 , L_6 ) ;
} else {
V_112 = F_23 ( V_110 ,
V_127 ) ;
if ( V_112 < 0 )
F_15 ( & V_9 -> V_28 , L_7 ) ;
}
if ( V_112 >= 0 &&
( F_23 ( V_110 ,
V_128 ) < 0 ) )
F_15 ( & V_9 -> V_28 , L_8 ) ;
}
}
return V_72 ;
}
static unsigned
F_41 ( struct V_8 * V_9 , struct V_37 * V_69 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_72 , V_129 ;
T_1 V_18 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_130 ;
void T_2 * V_131 ;
void T_2 * V_110 ;
int V_15 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_72 = V_69 -> V_45 ;
V_129 = V_72 ;
V_15 = V_11 -> V_15 ;
V_18 = F_8 ( V_9 ) ;
V_130 = V_7 + V_119 ;
V_131 = V_7 + V_103 ;
V_110 = V_7 + V_100 ;
if ( V_129 < ( V_15 >> 3 ) )
return 0 ;
if ( V_15 <= 8 ) {
V_104 * V_106 ;
const V_104 * V_75 ;
V_106 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
do {
V_129 -= 1 ;
if ( V_75 != NULL ) {
if ( F_23 ( V_110 ,
V_127 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_7 ) ;
goto V_132;
}
F_42 ( & V_9 -> V_28 , L_9 ,
V_15 , * V_75 ) ;
F_3 ( * V_75 ++ , V_130 ) ;
}
if ( V_106 != NULL ) {
if ( F_23 ( V_110 ,
V_101 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_10 ) ;
goto V_132;
}
if ( V_129 == 1 && V_75 == NULL &&
( V_18 & V_96 ) ) {
F_12 ( V_9 , 0 ) ;
* V_106 ++ = F_5 ( V_131 ) ;
F_42 ( & V_9 -> V_28 , L_11 ,
V_15 , * ( V_106 - 1 ) ) ;
if ( F_23 ( V_110 ,
V_101 ) < 0 ) {
F_15 ( & V_9 -> V_28 ,
L_10 ) ;
goto V_132;
}
V_129 = 0 ;
} else if ( V_129 == 0 && V_75 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_106 ++ = F_5 ( V_131 ) ;
F_42 ( & V_9 -> V_28 , L_11 ,
V_15 , * ( V_106 - 1 ) ) ;
}
} while ( V_129 );
} else if ( V_15 <= 16 ) {
V_105 * V_106 ;
const V_105 * V_75 ;
V_106 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
do {
V_129 -= 2 ;
if ( V_75 != NULL ) {
if ( F_23 ( V_110 ,
V_127 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_7 ) ;
goto V_132;
}
F_42 ( & V_9 -> V_28 , L_12 ,
V_15 , * V_75 ) ;
F_3 ( * V_75 ++ , V_130 ) ;
}
if ( V_106 != NULL ) {
if ( F_23 ( V_110 ,
V_101 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_10 ) ;
goto V_132;
}
if ( V_129 == 2 && V_75 == NULL &&
( V_18 & V_96 ) ) {
F_12 ( V_9 , 0 ) ;
* V_106 ++ = F_5 ( V_131 ) ;
F_42 ( & V_9 -> V_28 , L_13 ,
V_15 , * ( V_106 - 1 ) ) ;
if ( F_23 ( V_110 ,
V_101 ) < 0 ) {
F_15 ( & V_9 -> V_28 ,
L_10 ) ;
goto V_132;
}
V_129 = 0 ;
} else if ( V_129 == 0 && V_75 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_106 ++ = F_5 ( V_131 ) ;
F_42 ( & V_9 -> V_28 , L_13 ,
V_15 , * ( V_106 - 1 ) ) ;
}
} while ( V_129 >= 2 );
} else if ( V_15 <= 32 ) {
T_1 * V_106 ;
const T_1 * V_75 ;
V_106 = V_69 -> V_47 ;
V_75 = V_69 -> V_48 ;
do {
V_129 -= 4 ;
if ( V_75 != NULL ) {
if ( F_23 ( V_110 ,
V_127 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_7 ) ;
goto V_132;
}
F_42 ( & V_9 -> V_28 , L_14 ,
V_15 , * V_75 ) ;
F_3 ( * V_75 ++ , V_130 ) ;
}
if ( V_106 != NULL ) {
if ( F_23 ( V_110 ,
V_101 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_10 ) ;
goto V_132;
}
if ( V_129 == 4 && V_75 == NULL &&
( V_18 & V_96 ) ) {
F_12 ( V_9 , 0 ) ;
* V_106 ++ = F_5 ( V_131 ) ;
F_42 ( & V_9 -> V_28 , L_15 ,
V_15 , * ( V_106 - 1 ) ) ;
if ( F_23 ( V_110 ,
V_101 ) < 0 ) {
F_15 ( & V_9 -> V_28 ,
L_10 ) ;
goto V_132;
}
V_129 = 0 ;
} else if ( V_129 == 0 && V_75 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_106 ++ = F_5 ( V_131 ) ;
F_42 ( & V_9 -> V_28 , L_15 ,
V_15 , * ( V_106 - 1 ) ) ;
}
} while ( V_129 >= 4 );
}
if ( V_69 -> V_47 == NULL ) {
if ( F_23 ( V_110 ,
V_127 ) < 0 ) {
F_15 ( & V_9 -> V_28 , L_7 ) ;
} else if ( F_23 ( V_110 ,
V_128 ) < 0 )
F_15 ( & V_9 -> V_28 , L_8 ) ;
F_12 ( V_9 , 0 ) ;
}
V_132:
F_12 ( V_9 , 1 ) ;
return V_72 - V_129 ;
}
static T_1 F_43 ( T_1 V_133 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_133 >= ( V_134 >> div ) )
return div ;
return 15 ;
}
static int F_44 ( struct V_8 * V_9 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_54 ;
T_1 V_18 = 0 , V_135 = 0 , div , V_136 = 0 , V_137 = 0 ;
V_104 V_15 = V_9 -> V_138 ;
T_1 V_133 = V_9 -> V_139 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_54 = V_6 -> V_2 ;
if ( V_38 != NULL && V_38 -> V_138 )
V_15 = V_38 -> V_138 ;
V_11 -> V_15 = V_15 ;
if ( V_38 && V_38 -> V_133 )
V_133 = V_38 -> V_133 ;
V_133 = F_45 ( T_1 , V_133 , V_134 ) ;
if ( V_133 < ( V_134 / V_140 ) ) {
V_135 = F_43 ( V_133 ) ;
V_133 = V_134 >> V_135 ;
V_137 = 0 ;
} else {
div = ( V_134 + V_133 - 1 ) / V_133 ;
V_133 = V_134 / div ;
V_135 = ( div - 1 ) & 0xf ;
V_136 = ( div - 1 ) >> 4 ;
V_137 = V_141 ;
}
V_18 = F_8 ( V_9 ) ;
if ( V_6 -> V_142 == V_143 ) {
V_18 &= ~ V_144 ;
V_18 &= ~ V_145 ;
V_18 |= V_146 ;
} else {
V_18 |= V_144 ;
V_18 |= V_145 ;
V_18 &= ~ V_146 ;
}
V_18 &= ~ V_147 ;
V_18 |= ( V_15 - 1 ) << 7 ;
if ( ! ( V_9 -> V_25 & V_26 ) )
V_18 |= V_148 ;
else
V_18 &= ~ V_148 ;
V_18 &= ~ V_149 ;
V_18 |= V_135 << 2 ;
V_18 &= ~ V_141 ;
V_18 |= V_137 ;
if ( V_137 ) {
V_11 -> V_22 &= ~ V_150 ;
V_11 -> V_22 |= V_136 << 8 ;
F_6 ( V_9 , V_24 , V_11 -> V_22 ) ;
}
if ( V_9 -> V_25 & V_151 )
V_18 |= V_152 ;
else
V_18 &= ~ V_152 ;
if ( V_9 -> V_25 & V_153 )
V_18 |= V_154 ;
else
V_18 &= ~ V_154 ;
F_9 ( V_9 , V_18 ) ;
V_11 -> V_25 = V_9 -> V_25 ;
F_46 ( & V_9 -> V_28 , L_16 ,
V_133 ,
( V_9 -> V_25 & V_153 ) ? L_17 : L_18 ,
( V_9 -> V_25 & V_151 ) ? L_19 : L_20 ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_63 * V_64 ;
int V_90 = 0 ;
V_6 = F_2 ( V_2 ) ;
V_64 = V_6 -> V_65 + V_9 -> V_66 ;
F_48 ( & V_64 -> V_67 ) ;
F_48 ( & V_64 -> V_68 ) ;
V_64 -> V_95 = F_49 ( & V_2 -> V_28 ,
V_64 -> V_155 ) ;
if ( F_50 ( V_64 -> V_95 ) ) {
V_90 = F_51 ( V_64 -> V_95 ) ;
V_64 -> V_95 = NULL ;
goto V_156;
}
V_64 -> V_73 = F_49 ( & V_2 -> V_28 ,
V_64 -> V_157 ) ;
if ( F_50 ( V_64 -> V_73 ) ) {
V_90 = F_51 ( V_64 -> V_73 ) ;
V_64 -> V_73 = NULL ;
F_52 ( V_64 -> V_95 ) ;
V_64 -> V_95 = NULL ;
}
V_156:
return V_90 ;
}
static int F_53 ( struct V_8 * V_9 )
{
int V_90 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_30 * V_31 = & V_6 -> V_31 ;
struct V_63 * V_64 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
if ( ! V_11 ) {
V_11 = F_54 ( sizeof *V_11 , V_98 ) ;
if ( ! V_11 )
return - V_158 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_66 * 0x14 ;
V_11 -> V_117 = V_6 -> V_117 + V_9 -> V_66 * 0x14 ;
V_11 -> V_25 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_22 = 0 ;
V_9 -> V_12 = V_11 ;
F_55 ( & V_11 -> V_159 , & V_31 -> V_11 ) ;
if ( F_56 ( V_9 -> V_160 ) ) {
V_90 = F_57 ( V_9 -> V_160 , F_58 ( & V_9 -> V_28 ) ) ;
if ( V_90 ) {
F_15 ( & V_9 -> V_28 , L_21 ) ;
return V_90 ;
}
F_59 ( V_9 -> V_160 ,
! ( V_9 -> V_25 & V_26 ) ) ;
}
}
if ( ! V_64 -> V_95 || ! V_64 -> V_73 ) {
V_90 = F_47 ( V_9 ) ;
if ( V_90 )
F_60 ( & V_9 -> V_28 , L_22 ,
V_90 ) ;
}
V_90 = F_14 ( V_6 -> V_28 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_44 ( V_9 , NULL ) ;
F_16 ( V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
return V_90 ;
}
static void F_61 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_62 ( & V_11 -> V_159 ) ;
F_38 ( V_11 ) ;
}
if ( V_9 -> V_66 < V_9 -> V_2 -> V_161 ) {
V_64 = & V_6 -> V_65 [ V_9 -> V_66 ] ;
if ( V_64 -> V_95 ) {
F_52 ( V_64 -> V_95 ) ;
V_64 -> V_95 = NULL ;
}
if ( V_64 -> V_73 ) {
F_52 ( V_64 -> V_73 ) ;
V_64 -> V_73 = NULL ;
}
}
if ( F_56 ( V_9 -> V_160 ) )
F_63 ( V_9 -> V_160 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
struct V_10 * V_11 ;
struct V_162 * V_163 ;
int V_164 = 0 ;
int V_165 = 0 ;
T_1 V_43 ;
V_6 = F_2 ( V_2 ) ;
V_64 = V_6 -> V_65 + V_9 -> V_66 ;
V_11 = V_9 -> V_12 ;
V_163 = V_9 -> V_166 ;
if ( V_9 -> V_25 != V_11 -> V_25 )
V_164 = 1 ;
F_12 ( V_9 , 0 ) ;
if ( F_56 ( V_9 -> V_160 ) )
F_13 ( V_9 , V_9 -> V_25 & V_26 ) ;
if ( V_164 ||
( V_38 -> V_133 != V_9 -> V_139 ) ||
( V_38 -> V_138 != V_9 -> V_138 ) ) {
V_164 = 1 ;
V_165 = F_44 ( V_9 , V_38 ) ;
if ( V_165 < 0 )
goto V_132;
if ( V_38 -> V_133 == V_9 -> V_139 &&
V_38 -> V_138 == V_9 -> V_138 )
V_164 = 0 ;
}
if ( V_163 && V_163 -> V_167 ) {
V_43 = V_6 -> V_31 . V_36 ;
V_43 &= ~ V_35 ;
F_1 ( V_2 , V_32 , V_43 ) ;
V_6 -> V_31 . V_36 =
F_7 ( V_9 , V_32 ) ;
}
V_43 = F_8 ( V_9 ) ;
V_43 &= ~ V_168 ;
V_43 &= ~ V_96 ;
if ( V_38 -> V_48 == NULL )
V_43 |= V_169 ;
else if ( V_38 -> V_47 == NULL )
V_43 |= V_170 ;
if ( V_163 && V_163 -> V_171 && V_38 -> V_48 == NULL ) {
if ( V_38 -> V_45 > ( ( V_11 -> V_15 + 7 ) >> 3 ) )
V_43 |= V_96 ;
}
F_9 ( V_9 , V_43 ) ;
if ( V_38 -> V_45 ) {
unsigned V_72 ;
if ( ( V_64 -> V_95 && V_64 -> V_73 ) &&
V_2 -> V_172 &&
V_2 -> V_173 ( V_2 , V_9 , V_38 ) )
F_19 ( V_9 , V_38 , 1 ) ;
F_12 ( V_9 , 1 ) ;
if ( V_38 -> V_48 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_119 ) ;
if ( ( V_64 -> V_95 && V_64 -> V_73 ) &&
V_2 -> V_172 &&
V_2 -> V_173 ( V_2 , V_9 , V_38 ) )
V_72 = F_40 ( V_9 , V_38 ) ;
else
V_72 = F_41 ( V_9 , V_38 ) ;
if ( V_72 != V_38 -> V_45 ) {
V_165 = - V_174 ;
goto V_132;
}
}
F_12 ( V_9 , 0 ) ;
if ( V_6 -> V_41 > 0 )
F_19 ( V_9 , V_38 , 0 ) ;
V_132:
if ( V_164 ) {
V_164 = 0 ;
V_165 = F_44 ( V_9 , NULL ) ;
}
if ( V_163 && V_163 -> V_167 ) {
V_43 = V_6 -> V_31 . V_36 ;
V_43 |= V_35 ;
F_1 ( V_2 , V_32 , V_43 ) ;
V_6 -> V_31 . V_36 =
F_7 ( V_9 , V_32 ) ;
}
F_12 ( V_9 , 0 ) ;
if ( F_56 ( V_9 -> V_160 ) )
F_13 ( V_9 , ! ( V_9 -> V_25 & V_26 ) ) ;
if ( V_6 -> V_41 > 0 && V_38 )
F_19 ( V_9 , V_38 , 0 ) ;
return V_165 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_30 * V_31 = & V_6 -> V_31 ;
struct V_10 * V_11 ;
F_22 (cs, &ctx->cs, node) {
if ( V_176 -> V_9 -> V_12 == V_11 )
continue;
if ( ( V_11 -> V_13 & V_29 ) ) {
V_11 -> V_13 &= ~ V_29 ;
F_3 ( V_11 -> V_13 ,
V_11 -> V_7 + V_14 ) ;
F_5 ( V_11 -> V_7 + V_14 ) ;
}
}
return 0 ;
}
static bool F_66 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_37 * V_69 )
{
return ( V_69 -> V_45 >= V_177 ) ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_30 * V_31 = & V_6 -> V_31 ;
int V_90 = 0 ;
V_90 = F_14 ( V_6 -> V_28 ) ;
if ( V_90 < 0 )
return V_90 ;
F_1 ( V_2 , V_55 ,
V_178 ) ;
V_31 -> V_56 = V_178 ;
F_18 ( V_2 ) ;
F_16 ( V_6 -> V_28 ) ;
F_17 ( V_6 -> V_28 ) ;
return 0 ;
}
static int F_68 ( struct V_179 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_69 ( V_28 ) ;
V_6 = F_2 ( V_2 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
static int F_70 ( struct V_180 * V_181 )
{
struct V_1 * V_2 ;
const struct V_182 * V_183 ;
struct V_5 * V_6 ;
struct V_184 * V_185 ;
int V_165 = 0 , V_186 ;
T_1 V_187 = 0 ;
static int V_188 = 1 ;
struct V_189 * V_159 = V_181 -> V_28 . V_190 ;
const struct V_191 * V_192 ;
V_2 = F_71 ( & V_181 -> V_28 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_46 ( & V_181 -> V_28 , L_23 ) ;
return - V_158 ;
}
V_2 -> V_193 = V_151 | V_153 | V_26 ;
V_2 -> V_194 = F_72 ( 4 , 32 ) ;
V_2 -> V_195 = F_53 ;
V_2 -> V_196 = true ;
V_2 -> V_197 = F_65 ;
V_2 -> V_173 = F_66 ;
V_2 -> V_198 = F_64 ;
V_2 -> V_199 = F_13 ;
V_2 -> V_200 = F_61 ;
V_2 -> V_28 . V_190 = V_159 ;
V_2 -> V_139 = V_134 ;
V_2 -> V_201 = V_134 >> 15 ;
F_73 ( V_181 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_192 = F_74 ( V_202 , & V_181 -> V_28 ) ;
if ( V_192 ) {
T_1 V_203 = 1 ;
V_183 = V_192 -> V_62 ;
F_75 ( V_159 , L_24 , & V_203 ) ;
V_2 -> V_161 = V_203 ;
V_2 -> V_188 = V_188 ++ ;
if ( F_76 ( V_159 , L_25 , NULL ) )
V_6 -> V_142 = V_204 ;
} else {
V_183 = F_77 ( & V_181 -> V_28 ) ;
V_2 -> V_161 = V_183 -> V_203 ;
if ( V_181 -> V_205 != - 1 )
V_2 -> V_188 = V_181 -> V_205 ;
V_6 -> V_142 = V_183 -> V_142 ;
}
V_187 = V_183 -> V_187 ;
V_185 = F_78 ( V_181 , V_206 , 0 ) ;
V_6 -> V_7 = F_79 ( & V_181 -> V_28 , V_185 ) ;
if ( F_50 ( V_6 -> V_7 ) ) {
V_165 = F_51 ( V_6 -> V_7 ) ;
goto V_207;
}
V_6 -> V_117 = V_185 -> V_208 + V_187 ;
V_6 -> V_7 += V_187 ;
V_6 -> V_28 = & V_181 -> V_28 ;
F_80 ( & V_6 -> V_31 . V_11 ) ;
V_6 -> V_65 = F_81 ( & V_181 -> V_28 , V_2 -> V_161 ,
sizeof( struct V_63 ) ,
V_98 ) ;
if ( V_6 -> V_65 == NULL ) {
V_165 = - V_158 ;
goto V_207;
}
for ( V_186 = 0 ; V_186 < V_2 -> V_161 ; V_186 ++ ) {
sprintf ( V_6 -> V_65 [ V_186 ] . V_155 , L_26 , V_186 ) ;
sprintf ( V_6 -> V_65 [ V_186 ] . V_157 , L_27 , V_186 ) ;
}
if ( V_165 < 0 )
goto V_207;
F_82 ( & V_181 -> V_28 ) ;
F_83 ( & V_181 -> V_28 , V_209 ) ;
F_84 ( & V_181 -> V_28 ) ;
V_165 = F_67 ( V_6 ) ;
if ( V_165 < 0 )
goto V_210;
V_165 = F_85 ( & V_181 -> V_28 , V_2 ) ;
if ( V_165 < 0 )
goto V_210;
return V_165 ;
V_210:
F_86 ( & V_181 -> V_28 ) ;
F_87 ( & V_181 -> V_28 ) ;
F_88 ( & V_181 -> V_28 ) ;
V_207:
F_89 ( V_2 ) ;
return V_165 ;
}
static int F_90 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = F_91 ( V_181 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_86 ( V_6 -> V_28 ) ;
F_87 ( V_6 -> V_28 ) ;
F_88 ( & V_181 -> V_28 ) ;
return 0 ;
}
static int F_92 ( struct V_179 * V_28 )
{
struct V_1 * V_2 = F_69 ( V_28 ) ;
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
return F_93 ( V_28 ) ;
}
static int F_94 ( struct V_179 * V_28 )
{
return F_95 ( V_28 ) ;
}
