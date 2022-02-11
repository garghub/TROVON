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
static void F_10 ( const struct V_8 * V_9 ,
int V_15 , int V_16 )
{
T_1 V_17 , V_18 ;
V_17 = F_8 ( V_9 ) ;
if ( V_15 )
V_18 = V_19 ;
else
V_18 = V_20 ;
if ( V_16 )
V_17 |= V_18 ;
else
V_17 &= ~ V_18 ;
F_9 ( V_9 , V_17 ) ;
}
static void F_11 ( const struct V_8 * V_9 , int V_16 )
{
T_1 V_17 ;
V_17 = V_16 ? V_21 : 0 ;
F_6 ( V_9 , V_22 , V_17 ) ;
F_7 ( V_9 , V_22 ) ;
}
static void F_12 ( struct V_8 * V_9 , int V_23 )
{
T_1 V_17 ;
V_17 = F_8 ( V_9 ) ;
if ( V_23 )
V_17 |= V_24 ;
else
V_17 &= ~ V_24 ;
F_9 ( V_9 , V_17 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
T_1 V_17 ;
V_17 = F_4 ( V_2 , V_27 ) ;
V_17 &= ~ ( V_28 | V_29 ) ;
V_17 |= V_30 ;
F_1 ( V_2 , V_27 , V_17 ) ;
V_26 -> V_31 = V_17 ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_32 = V_6 -> V_2 ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_10 * V_11 ;
F_1 ( V_32 , V_27 , V_26 -> V_31 ) ;
F_1 ( V_32 , V_33 , V_26 -> V_34 ) ;
F_15 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_21 ( void T_2 * V_36 , unsigned long V_37 )
{
unsigned long V_38 ;
V_38 = V_39 + F_22 ( 1000 ) ;
while ( ! ( F_5 ( V_36 ) & V_37 ) ) {
if ( F_23 ( V_39 , V_38 ) ) {
if ( ! ( F_5 ( V_36 ) & V_37 ) )
return - V_40 ;
else
return 0 ;
}
F_24 () ;
}
return 0 ;
}
static void F_25 ( void * V_41 )
{
struct V_8 * V_9 = V_41 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_42 * V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
F_10 ( V_9 , 1 , 0 ) ;
F_26 ( & V_43 -> V_46 ) ;
}
static void F_27 ( void * V_41 )
{
struct V_8 * V_9 = V_41 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_42 * V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
F_10 ( V_9 , 0 , 0 ) ;
F_26 ( & V_43 -> V_47 ) ;
}
static void F_28 ( struct V_8 * V_9 ,
struct V_48 * V_49 ,
struct V_50 V_51 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
unsigned int V_52 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
V_52 = V_49 -> V_53 ;
if ( V_43 -> V_54 ) {
struct V_55 * V_56 ;
struct V_57 V_58 ;
F_29 ( V_43 -> V_54 , & V_51 ) ;
F_30 ( & V_58 , 1 ) ;
F_31 ( & V_58 ) = V_49 -> V_59 ;
F_32 ( & V_58 ) = V_49 -> V_53 ;
V_56 = F_33 ( V_43 -> V_54 , & V_58 , 1 ,
V_60 , V_61 | V_62 ) ;
if ( V_56 ) {
V_56 -> V_63 = F_27 ;
V_56 -> V_64 = V_9 ;
F_34 ( V_56 ) ;
} else {
}
}
F_35 ( V_43 -> V_54 ) ;
F_10 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_36 ( struct V_8 * V_9 , struct V_48 * V_49 ,
struct V_50 V_51 ,
unsigned V_65 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
unsigned int V_52 ;
T_1 V_17 ;
int V_66 = 0 ;
int V_67 , V_68 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
V_52 = V_49 -> V_53 ;
V_67 = V_11 -> V_67 ;
V_17 = F_8 ( V_9 ) ;
if ( V_67 <= 8 )
V_68 = V_52 ;
else if ( V_67 <= 16 )
V_68 = V_52 >> 1 ;
else
V_68 = V_52 >> 2 ;
if ( V_43 -> V_69 ) {
struct V_55 * V_56 ;
struct V_57 V_58 ;
T_3 V_53 = V_49 -> V_53 - V_65 ;
F_29 ( V_43 -> V_69 , & V_51 ) ;
if ( V_17 & V_70 )
V_53 -= V_65 ;
F_30 ( & V_58 , 1 ) ;
F_31 ( & V_58 ) = V_49 -> V_71 ;
F_32 ( & V_58 ) = V_53 ;
V_56 = F_33 ( V_43 -> V_69 , & V_58 , 1 ,
V_72 , V_61 |
V_62 ) ;
if ( V_56 ) {
V_56 -> V_63 = F_25 ;
V_56 -> V_64 = V_9 ;
F_34 ( V_56 ) ;
} else {
}
}
F_35 ( V_43 -> V_69 ) ;
F_10 ( V_9 , 1 , 1 ) ;
F_37 ( & V_43 -> V_46 ) ;
F_38 ( V_6 -> V_35 , V_49 -> V_71 , V_52 ,
V_73 ) ;
F_11 ( V_9 , 0 ) ;
V_66 = V_68 - 1 ;
if ( V_17 & V_70 ) {
V_66 -- ;
if ( F_39 ( F_7 ( V_9 , V_74 )
& V_75 ) ) {
T_1 V_76 ;
V_76 = F_7 ( V_9 , V_77 ) ;
if ( V_67 <= 8 )
( ( V_78 * ) V_49 -> V_79 ) [ V_66 ++ ] = V_76 ;
else if ( V_67 <= 16 )
( ( V_80 * ) V_49 -> V_79 ) [ V_66 ++ ] = V_76 ;
else
( ( T_1 * ) V_49 -> V_79 ) [ V_66 ++ ] = V_76 ;
} else {
F_40 ( & V_9 -> V_35 , L_1 ) ;
V_52 -= ( V_67 <= 8 ) ? 2 :
( V_67 <= 16 ) ? 4 :
8 ;
F_11 ( V_9 , 1 ) ;
return V_52 ;
}
}
if ( F_39 ( F_7 ( V_9 , V_74 )
& V_75 ) ) {
T_1 V_76 ;
V_76 = F_7 ( V_9 , V_77 ) ;
if ( V_67 <= 8 )
( ( V_78 * ) V_49 -> V_79 ) [ V_66 ] = V_76 ;
else if ( V_67 <= 16 )
( ( V_80 * ) V_49 -> V_79 ) [ V_66 ] = V_76 ;
else
( ( T_1 * ) V_49 -> V_79 ) [ V_66 ] = V_76 ;
} else {
F_40 ( & V_9 -> V_35 , L_2 ) ;
V_52 -= ( V_67 <= 8 ) ? 1 :
( V_67 <= 16 ) ? 2 :
4 ;
}
F_11 ( V_9 , 1 ) ;
return V_52 ;
}
static unsigned
F_41 ( struct V_8 * V_9 , struct V_48 * V_49 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_42 * V_43 ;
unsigned int V_52 ;
T_1 V_17 ;
V_78 * V_81 ;
const V_78 * V_56 ;
struct V_50 V_51 ;
enum V_82 V_83 ;
unsigned V_65 ;
void T_2 * V_84 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
V_17 = F_8 ( V_9 ) ;
if ( V_11 -> V_67 <= 8 ) {
V_83 = V_85 ;
V_65 = 1 ;
} else if ( V_11 -> V_67 <= 16 ) {
V_83 = V_86 ;
V_65 = 2 ;
} else {
V_83 = V_87 ;
V_65 = 4 ;
}
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_88 = V_11 -> V_89 + V_77 ;
V_51 . V_90 = V_11 -> V_89 + V_91 ;
V_51 . V_92 = V_83 ;
V_51 . V_93 = V_83 ;
V_51 . V_94 = 1 ;
V_51 . V_95 = 1 ;
V_81 = V_49 -> V_79 ;
V_56 = V_49 -> V_96 ;
V_52 = V_49 -> V_53 ;
if ( V_56 != NULL )
F_28 ( V_9 , V_49 , V_51 ) ;
if ( V_81 != NULL )
V_52 = F_36 ( V_9 , V_49 , V_51 , V_65 ) ;
if ( V_56 != NULL ) {
V_84 = V_11 -> V_7 + V_74 ;
F_37 ( & V_43 -> V_47 ) ;
F_38 ( V_6 -> V_35 , V_49 -> V_59 , V_49 -> V_53 ,
V_97 ) ;
if ( V_81 == NULL ) {
if ( F_21 ( V_84 ,
V_98 ) < 0 )
F_40 ( & V_9 -> V_35 , L_3 ) ;
else if ( F_21 ( V_84 ,
V_99 ) < 0 )
F_40 ( & V_9 -> V_35 , L_4 ) ;
}
}
return V_52 ;
}
static unsigned
F_42 ( struct V_8 * V_9 , struct V_48 * V_49 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_52 , V_100 ;
T_1 V_17 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_101 ;
void T_2 * V_102 ;
void T_2 * V_84 ;
int V_67 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_52 = V_49 -> V_53 ;
V_100 = V_52 ;
V_67 = V_11 -> V_67 ;
V_17 = F_8 ( V_9 ) ;
V_101 = V_7 + V_91 ;
V_102 = V_7 + V_77 ;
V_84 = V_7 + V_74 ;
if ( V_100 < ( V_67 >> 3 ) )
return 0 ;
if ( V_67 <= 8 ) {
V_78 * V_81 ;
const V_78 * V_56 ;
V_81 = V_49 -> V_79 ;
V_56 = V_49 -> V_96 ;
do {
V_100 -= 1 ;
if ( V_56 != NULL ) {
if ( F_21 ( V_84 ,
V_98 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
goto V_103;
}
F_43 ( & V_9 -> V_35 , L_5 ,
V_67 , * V_56 ) ;
F_3 ( * V_56 ++ , V_101 ) ;
}
if ( V_81 != NULL ) {
if ( F_21 ( V_84 ,
V_75 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_6 ) ;
goto V_103;
}
if ( V_100 == 1 && V_56 == NULL &&
( V_17 & V_70 ) ) {
F_11 ( V_9 , 0 ) ;
* V_81 ++ = F_5 ( V_102 ) ;
F_43 ( & V_9 -> V_35 , L_7 ,
V_67 , * ( V_81 - 1 ) ) ;
if ( F_21 ( V_84 ,
V_75 ) < 0 ) {
F_40 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_103;
}
V_100 = 0 ;
} else if ( V_100 == 0 && V_56 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_81 ++ = F_5 ( V_102 ) ;
F_43 ( & V_9 -> V_35 , L_7 ,
V_67 , * ( V_81 - 1 ) ) ;
}
} while ( V_100 );
} else if ( V_67 <= 16 ) {
V_80 * V_81 ;
const V_80 * V_56 ;
V_81 = V_49 -> V_79 ;
V_56 = V_49 -> V_96 ;
do {
V_100 -= 2 ;
if ( V_56 != NULL ) {
if ( F_21 ( V_84 ,
V_98 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
goto V_103;
}
F_43 ( & V_9 -> V_35 , L_8 ,
V_67 , * V_56 ) ;
F_3 ( * V_56 ++ , V_101 ) ;
}
if ( V_81 != NULL ) {
if ( F_21 ( V_84 ,
V_75 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_6 ) ;
goto V_103;
}
if ( V_100 == 2 && V_56 == NULL &&
( V_17 & V_70 ) ) {
F_11 ( V_9 , 0 ) ;
* V_81 ++ = F_5 ( V_102 ) ;
F_43 ( & V_9 -> V_35 , L_9 ,
V_67 , * ( V_81 - 1 ) ) ;
if ( F_21 ( V_84 ,
V_75 ) < 0 ) {
F_40 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_103;
}
V_100 = 0 ;
} else if ( V_100 == 0 && V_56 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_81 ++ = F_5 ( V_102 ) ;
F_43 ( & V_9 -> V_35 , L_9 ,
V_67 , * ( V_81 - 1 ) ) ;
}
} while ( V_100 >= 2 );
} else if ( V_67 <= 32 ) {
T_1 * V_81 ;
const T_1 * V_56 ;
V_81 = V_49 -> V_79 ;
V_56 = V_49 -> V_96 ;
do {
V_100 -= 4 ;
if ( V_56 != NULL ) {
if ( F_21 ( V_84 ,
V_98 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
goto V_103;
}
F_43 ( & V_9 -> V_35 , L_10 ,
V_67 , * V_56 ) ;
F_3 ( * V_56 ++ , V_101 ) ;
}
if ( V_81 != NULL ) {
if ( F_21 ( V_84 ,
V_75 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_6 ) ;
goto V_103;
}
if ( V_100 == 4 && V_56 == NULL &&
( V_17 & V_70 ) ) {
F_11 ( V_9 , 0 ) ;
* V_81 ++ = F_5 ( V_102 ) ;
F_43 ( & V_9 -> V_35 , L_11 ,
V_67 , * ( V_81 - 1 ) ) ;
if ( F_21 ( V_84 ,
V_75 ) < 0 ) {
F_40 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_103;
}
V_100 = 0 ;
} else if ( V_100 == 0 && V_56 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_81 ++ = F_5 ( V_102 ) ;
F_43 ( & V_9 -> V_35 , L_11 ,
V_67 , * ( V_81 - 1 ) ) ;
}
} while ( V_100 >= 4 );
}
if ( V_49 -> V_79 == NULL ) {
if ( F_21 ( V_84 ,
V_98 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
} else if ( F_21 ( V_84 ,
V_99 ) < 0 )
F_40 ( & V_9 -> V_35 , L_4 ) ;
F_11 ( V_9 , 0 ) ;
}
V_103:
F_11 ( V_9 , 1 ) ;
return V_52 - V_100 ;
}
static T_1 F_44 ( T_1 V_104 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_104 >= ( V_105 >> div ) )
return div ;
return 15 ;
}
static int F_45 ( struct V_8 * V_9 ,
struct V_48 * V_106 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_32 ;
T_1 V_17 = 0 , div = 0 ;
V_78 V_67 = V_9 -> V_107 ;
T_1 V_104 = V_9 -> V_108 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_32 = V_6 -> V_2 ;
if ( V_106 != NULL && V_106 -> V_107 )
V_67 = V_106 -> V_107 ;
V_11 -> V_67 = V_67 ;
if ( V_106 && V_106 -> V_104 )
V_104 = V_106 -> V_104 ;
V_104 = F_46 ( T_1 , V_104 , V_105 ) ;
div = F_44 ( V_104 ) ;
V_17 = F_8 ( V_9 ) ;
if ( V_6 -> V_109 == V_110 ) {
V_17 &= ~ V_111 ;
V_17 &= ~ V_112 ;
V_17 |= V_113 ;
} else {
V_17 |= V_111 ;
V_17 |= V_112 ;
V_17 &= ~ V_113 ;
}
V_17 &= ~ V_114 ;
V_17 |= ( V_67 - 1 ) << 7 ;
if ( ! ( V_9 -> V_115 & V_116 ) )
V_17 |= V_117 ;
else
V_17 &= ~ V_117 ;
V_17 &= ~ V_118 ;
V_17 |= div << 2 ;
if ( V_9 -> V_115 & V_119 )
V_17 |= V_120 ;
else
V_17 &= ~ V_120 ;
if ( V_9 -> V_115 & V_121 )
V_17 |= V_122 ;
else
V_17 &= ~ V_122 ;
F_9 ( V_9 , V_17 ) ;
F_47 ( & V_9 -> V_35 , L_12 ,
V_105 >> div ,
( V_9 -> V_115 & V_121 ) ? L_13 : L_14 ,
( V_9 -> V_115 & V_119 ) ? L_15 : L_16 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
T_4 V_123 ;
unsigned V_124 ;
V_6 = F_2 ( V_2 ) ;
V_43 = V_6 -> V_44 + V_9 -> V_45 ;
F_49 ( & V_43 -> V_46 ) ;
F_49 ( & V_43 -> V_47 ) ;
F_50 ( V_123 ) ;
F_51 ( V_125 , V_123 ) ;
V_124 = V_43 -> V_126 ;
V_43 -> V_69 = F_52 ( V_123 , V_127 , & V_124 ) ;
if ( ! V_43 -> V_69 )
goto V_128;
V_124 = V_43 -> V_129 ;
V_43 -> V_54 = F_52 ( V_123 , V_127 , & V_124 ) ;
if ( ! V_43 -> V_54 ) {
F_53 ( V_43 -> V_69 ) ;
V_43 -> V_69 = NULL ;
goto V_128;
}
return 0 ;
V_128:
F_54 ( & V_9 -> V_35 , L_17 ) ;
return - V_130 ;
}
static int F_55 ( struct V_8 * V_9 )
{
int V_131 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_42 * V_43 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_107 < 4 || V_9 -> V_107 > 32 ) {
F_47 ( & V_9 -> V_35 , L_18 ,
V_9 -> V_107 ) ;
return - V_132 ;
}
V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
if ( ! V_11 ) {
V_11 = F_56 ( sizeof *V_11 , V_133 ) ;
if ( ! V_11 )
return - V_134 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_45 * 0x14 ;
V_11 -> V_89 = V_6 -> V_89 + V_9 -> V_45 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_57 ( & V_11 -> V_135 , & V_26 -> V_11 ) ;
}
if ( ! V_43 -> V_69 || ! V_43 -> V_54 ) {
V_131 = F_48 ( V_9 ) ;
if ( V_131 < 0 && V_131 != - V_130 )
return V_131 ;
}
V_131 = F_17 ( V_6 -> V_35 ) ;
if ( V_131 < 0 )
return V_131 ;
V_131 = F_45 ( V_9 , NULL ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return V_131 ;
}
static void F_58 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_59 ( & V_11 -> V_135 ) ;
F_60 ( V_11 ) ;
}
if ( V_9 -> V_45 < V_9 -> V_2 -> V_136 ) {
V_43 = & V_6 -> V_44 [ V_9 -> V_45 ] ;
if ( V_43 -> V_69 ) {
F_53 ( V_43 -> V_69 ) ;
V_43 -> V_69 = NULL ;
}
if ( V_43 -> V_54 ) {
F_53 ( V_43 -> V_54 ) ;
V_43 -> V_54 = NULL ;
}
}
}
static void F_61 ( struct V_5 * V_6 , struct V_137 * V_138 )
{
struct V_8 * V_9 ;
struct V_48 * V_106 = NULL ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_23 = 0 ;
struct V_10 * V_11 ;
struct V_139 * V_140 ;
int V_141 = 0 ;
int V_142 = 0 ;
T_1 V_143 ;
V_9 = V_138 -> V_9 ;
V_2 = V_9 -> V_2 ;
V_43 = V_6 -> V_44 + V_9 -> V_45 ;
V_11 = V_9 -> V_12 ;
V_140 = V_9 -> V_144 ;
F_11 ( V_9 , 1 ) ;
F_15 (t, &m->transfers, transfer_list) {
if ( V_106 -> V_96 == NULL && V_106 -> V_79 == NULL && V_106 -> V_53 ) {
V_142 = - V_132 ;
break;
}
if ( V_141 || V_106 -> V_104 || V_106 -> V_107 ) {
V_141 = 1 ;
V_142 = F_45 ( V_9 , V_106 ) ;
if ( V_142 < 0 )
break;
if ( ! V_106 -> V_104 && ! V_106 -> V_107 )
V_141 = 0 ;
}
if ( V_140 && V_140 -> V_145 ) {
V_143 = V_6 -> V_26 . V_31 ;
V_143 &= ~ V_30 ;
F_1 ( V_2 , V_27 , V_143 ) ;
V_6 -> V_26 . V_31 =
F_7 ( V_9 , V_27 ) ;
}
if ( ! V_23 ) {
F_12 ( V_9 , 1 ) ;
V_23 = 1 ;
}
V_143 = F_8 ( V_9 ) ;
V_143 &= ~ V_146 ;
V_143 &= ~ V_70 ;
if ( V_106 -> V_96 == NULL )
V_143 |= V_147 ;
else if ( V_106 -> V_79 == NULL )
V_143 |= V_148 ;
if ( V_140 && V_140 -> V_149 && V_106 -> V_96 == NULL ) {
if ( V_106 -> V_53 > ( ( V_11 -> V_67 + 7 ) >> 3 ) )
V_143 |= V_70 ;
}
F_9 ( V_9 , V_143 ) ;
if ( V_106 -> V_53 ) {
unsigned V_52 ;
if ( V_106 -> V_96 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_91 ) ;
if ( ( V_43 -> V_69 && V_43 -> V_54 ) &&
( V_138 -> V_150 || V_106 -> V_53 >= V_151 ) )
V_52 = F_41 ( V_9 , V_106 ) ;
else
V_52 = F_42 ( V_9 , V_106 ) ;
V_138 -> V_152 += V_52 ;
if ( V_52 != V_106 -> V_53 ) {
V_142 = - V_153 ;
break;
}
}
if ( V_106 -> V_154 )
F_62 ( V_106 -> V_154 ) ;
if ( V_106 -> V_155 ) {
F_12 ( V_9 , 0 ) ;
V_23 = 0 ;
}
}
if ( V_141 ) {
V_141 = 0 ;
V_142 = F_45 ( V_9 , NULL ) ;
}
if ( V_23 )
F_12 ( V_9 , 0 ) ;
if ( V_140 && V_140 -> V_145 ) {
V_143 = V_6 -> V_26 . V_31 ;
V_143 |= V_30 ;
F_1 ( V_2 , V_27 , V_143 ) ;
V_6 -> V_26 . V_31 =
F_7 ( V_9 , V_27 ) ;
}
F_11 ( V_9 , 0 ) ;
V_138 -> V_142 = V_142 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
struct V_8 * V_9 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_48 * V_106 ;
V_9 = V_138 -> V_9 ;
V_6 = F_2 ( V_2 ) ;
V_43 = V_6 -> V_44 + V_9 -> V_45 ;
V_138 -> V_152 = 0 ;
V_138 -> V_142 = 0 ;
if ( F_64 ( & V_138 -> V_156 ) )
return - V_132 ;
F_15 (t, &m->transfers, transfer_list) {
const void * V_96 = V_106 -> V_96 ;
void * V_79 = V_106 -> V_79 ;
unsigned V_53 = V_106 -> V_53 ;
if ( V_106 -> V_104 > V_105
|| ( V_53 && ! ( V_79 || V_96 ) )
|| ( V_106 -> V_107 &&
( V_106 -> V_107 < 4
|| V_106 -> V_107 > 32 ) ) ) {
F_47 ( V_6 -> V_35 , L_19 ,
V_106 -> V_104 ,
V_53 ,
V_96 ? L_20 : L_21 ,
V_79 ? L_22 : L_21 ,
V_106 -> V_107 ) ;
return - V_132 ;
}
if ( V_106 -> V_104 && V_106 -> V_104 < ( V_105 >> 15 ) ) {
F_47 ( V_6 -> V_35 , L_23 ,
V_106 -> V_104 ,
V_105 >> 15 ) ;
return - V_132 ;
}
if ( V_138 -> V_150 || V_53 < V_151 )
continue;
if ( V_43 -> V_54 && V_96 != NULL ) {
V_106 -> V_59 = F_65 ( V_6 -> V_35 , ( void * ) V_96 ,
V_53 , V_97 ) ;
if ( F_66 ( V_6 -> V_35 , V_106 -> V_59 ) ) {
F_47 ( V_6 -> V_35 , L_24 ,
'T' , V_53 ) ;
return - V_132 ;
}
}
if ( V_43 -> V_69 && V_79 != NULL ) {
V_106 -> V_71 = F_65 ( V_6 -> V_35 , V_79 , V_106 -> V_53 ,
V_73 ) ;
if ( F_66 ( V_6 -> V_35 , V_106 -> V_71 ) ) {
F_47 ( V_6 -> V_35 , L_24 ,
'R' , V_53 ) ;
if ( V_96 != NULL )
F_38 ( V_6 -> V_35 , V_106 -> V_59 ,
V_53 , V_97 ) ;
return - V_132 ;
}
}
}
F_61 ( V_6 , V_138 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_25 * V_26 = & V_6 -> V_26 ;
int V_131 = 0 ;
V_131 = F_17 ( V_6 -> V_35 ) ;
if ( V_131 < 0 )
return V_131 ;
F_1 ( V_2 , V_33 ,
V_157 ) ;
V_26 -> V_34 = V_157 ;
F_13 ( V_2 ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_69 ( struct V_158 * V_35 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_70 ( V_35 ) ;
V_6 = F_2 ( V_2 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_159 * V_160 )
{
struct V_1 * V_2 ;
const struct V_161 * V_162 ;
struct V_5 * V_6 ;
struct V_163 * V_164 ;
int V_142 = 0 , V_165 ;
T_1 V_166 = 0 ;
static int V_167 = 1 ;
struct V_168 * V_135 = V_160 -> V_35 . V_169 ;
const struct V_170 * V_171 ;
struct V_172 * V_172 ;
V_2 = F_72 ( & V_160 -> V_35 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_47 ( & V_160 -> V_35 , L_25 ) ;
return - V_134 ;
}
V_2 -> V_173 = V_119 | V_121 | V_116 ;
V_2 -> V_174 = F_55 ;
V_2 -> V_175 = F_16 ;
V_2 -> V_176 = F_18 ;
V_2 -> V_177 = F_63 ;
V_2 -> V_178 = F_58 ;
V_2 -> V_35 . V_169 = V_135 ;
F_73 ( & V_160 -> V_35 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_171 = F_74 ( V_179 , & V_160 -> V_35 ) ;
if ( V_171 ) {
T_1 V_180 = 1 ;
V_162 = V_171 -> V_41 ;
F_75 ( V_135 , L_26 , & V_180 ) ;
V_2 -> V_136 = V_180 ;
V_2 -> V_167 = V_167 ++ ;
if ( F_76 ( V_135 , L_27 , NULL ) )
V_6 -> V_109 = V_181 ;
} else {
V_162 = V_160 -> V_35 . V_182 ;
V_2 -> V_136 = V_162 -> V_180 ;
if ( V_160 -> V_183 != - 1 )
V_2 -> V_167 = V_160 -> V_183 ;
V_6 -> V_109 = V_162 -> V_109 ;
}
V_166 = V_162 -> V_166 ;
V_164 = F_77 ( V_160 , V_184 , 0 ) ;
if ( V_164 == NULL ) {
V_142 = - V_185 ;
goto V_186;
}
V_164 -> V_187 += V_166 ;
V_164 -> V_188 += V_166 ;
V_6 -> V_89 = V_164 -> V_187 ;
V_6 -> V_7 = F_78 ( & V_160 -> V_35 , V_164 ) ;
if ( F_79 ( V_6 -> V_7 ) ) {
V_142 = F_80 ( V_6 -> V_7 ) ;
goto V_186;
}
V_6 -> V_35 = & V_160 -> V_35 ;
F_81 ( & V_6 -> V_26 . V_11 ) ;
V_6 -> V_44 = F_82 ( V_2 -> V_136 ,
sizeof( struct V_42 ) ,
V_133 ) ;
if ( V_6 -> V_44 == NULL )
goto V_186;
for ( V_165 = 0 ; V_165 < V_2 -> V_136 ; V_165 ++ ) {
char V_189 [ 14 ] ;
struct V_163 * V_190 ;
sprintf ( V_189 , L_28 , V_165 ) ;
V_190 = F_83 ( V_160 , V_191 ,
V_189 ) ;
if ( ! V_190 ) {
F_47 ( & V_160 -> V_35 , L_29 ) ;
V_142 = - V_185 ;
break;
}
V_6 -> V_44 [ V_165 ] . V_126 = V_190 -> V_187 ;
sprintf ( V_189 , L_30 , V_165 ) ;
V_190 = F_83 ( V_160 , V_191 ,
V_189 ) ;
if ( ! V_190 ) {
F_47 ( & V_160 -> V_35 , L_31 ) ;
V_142 = - V_185 ;
break;
}
V_6 -> V_44 [ V_165 ] . V_129 = V_190 -> V_187 ;
}
if ( V_142 < 0 )
goto V_192;
V_172 = F_84 ( & V_160 -> V_35 ) ;
if ( F_79 ( V_172 ) )
F_54 ( & V_160 -> V_35 ,
L_32 ) ;
F_85 ( & V_160 -> V_35 ) ;
F_86 ( & V_160 -> V_35 , V_193 ) ;
F_87 ( & V_160 -> V_35 ) ;
V_142 = F_68 ( V_6 ) ;
if ( V_142 < 0 )
goto V_194;
V_142 = F_88 ( V_2 ) ;
if ( V_142 < 0 )
goto V_194;
return V_142 ;
V_194:
F_89 ( & V_160 -> V_35 ) ;
V_192:
F_60 ( V_6 -> V_44 ) ;
V_186:
F_90 ( V_2 ) ;
return V_142 ;
}
static int F_91 ( struct V_159 * V_160 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_42 * V_44 ;
V_2 = F_70 ( & V_160 -> V_35 ) ;
V_6 = F_2 ( V_2 ) ;
V_44 = V_6 -> V_44 ;
F_92 ( V_6 -> V_35 ) ;
F_89 ( & V_160 -> V_35 ) ;
F_93 ( V_2 ) ;
F_60 ( V_44 ) ;
return 0 ;
}
static int F_94 ( struct V_158 * V_35 )
{
struct V_1 * V_2 = F_70 ( V_35 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_10 * V_11 ;
F_17 ( V_6 -> V_35 ) ;
F_15 (cs, &ctx->cs, node) {
if ( ( V_11 -> V_13 & V_24 ) == 0 ) {
V_11 -> V_13 |= V_24 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
V_11 -> V_13 &= ~ V_24 ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return 0 ;
}
