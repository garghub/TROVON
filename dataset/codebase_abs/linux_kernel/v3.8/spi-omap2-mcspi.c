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
if ( F_23 ( V_39 , V_38 ) )
return - 1 ;
F_24 () ;
}
return 0 ;
}
static void F_25 ( void * V_40 )
{
struct V_8 * V_9 = V_40 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_41 * V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
F_26 ( & V_42 -> V_45 ) ;
F_10 ( V_9 , 1 , 0 ) ;
}
static void F_27 ( void * V_40 )
{
struct V_8 * V_9 = V_40 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_41 * V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
F_26 ( & V_42 -> V_46 ) ;
F_10 ( V_9 , 0 , 0 ) ;
}
static void F_28 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_49 V_50 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
unsigned int V_51 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
V_51 = V_48 -> V_52 ;
if ( V_42 -> V_53 ) {
struct V_54 * V_55 ;
struct V_56 V_57 ;
F_29 ( V_42 -> V_53 , & V_50 ) ;
F_30 ( & V_57 , 1 ) ;
F_31 ( & V_57 ) = V_48 -> V_58 ;
F_32 ( & V_57 ) = V_48 -> V_52 ;
V_55 = F_33 ( V_42 -> V_53 , & V_57 , 1 ,
V_59 , V_60 | V_61 ) ;
if ( V_55 ) {
V_55 -> V_62 = F_27 ;
V_55 -> V_63 = V_9 ;
F_34 ( V_55 ) ;
} else {
}
}
F_35 ( V_42 -> V_53 ) ;
F_10 ( V_9 , 0 , 1 ) ;
}
static unsigned
F_36 ( struct V_8 * V_9 , struct V_47 * V_48 ,
struct V_49 V_50 ,
unsigned V_64 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
unsigned int V_51 ;
T_1 V_17 ;
int V_65 = 0 ;
int V_66 , V_67 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
V_51 = V_48 -> V_52 ;
V_66 = V_11 -> V_66 ;
V_17 = F_8 ( V_9 ) ;
if ( V_66 <= 8 )
V_67 = V_51 ;
else if ( V_66 <= 16 )
V_67 = V_51 >> 1 ;
else
V_67 = V_51 >> 2 ;
if ( V_42 -> V_68 ) {
struct V_54 * V_55 ;
struct V_56 V_57 ;
T_3 V_52 = V_48 -> V_52 - V_64 ;
F_29 ( V_42 -> V_68 , & V_50 ) ;
if ( V_17 & V_69 )
V_52 -= V_64 ;
F_30 ( & V_57 , 1 ) ;
F_31 ( & V_57 ) = V_48 -> V_70 ;
F_32 ( & V_57 ) = V_52 ;
V_55 = F_33 ( V_42 -> V_68 , & V_57 , 1 ,
V_71 , V_60 |
V_61 ) ;
if ( V_55 ) {
V_55 -> V_62 = F_25 ;
V_55 -> V_63 = V_9 ;
F_34 ( V_55 ) ;
} else {
}
}
F_35 ( V_42 -> V_68 ) ;
F_10 ( V_9 , 1 , 1 ) ;
F_37 ( & V_42 -> V_45 ) ;
F_38 ( V_6 -> V_35 , V_48 -> V_70 , V_51 ,
V_72 ) ;
F_11 ( V_9 , 0 ) ;
V_65 = V_67 - 1 ;
if ( V_17 & V_69 ) {
V_65 -- ;
if ( F_39 ( F_7 ( V_9 , V_73 )
& V_74 ) ) {
T_1 V_75 ;
V_75 = F_7 ( V_9 , V_76 ) ;
if ( V_66 <= 8 )
( ( V_77 * ) V_48 -> V_78 ) [ V_65 ++ ] = V_75 ;
else if ( V_66 <= 16 )
( ( V_79 * ) V_48 -> V_78 ) [ V_65 ++ ] = V_75 ;
else
( ( T_1 * ) V_48 -> V_78 ) [ V_65 ++ ] = V_75 ;
} else {
F_40 ( & V_9 -> V_35 , L_1 ) ;
V_51 -= ( V_66 <= 8 ) ? 2 :
( V_66 <= 16 ) ? 4 :
8 ;
F_11 ( V_9 , 1 ) ;
return V_51 ;
}
}
if ( F_39 ( F_7 ( V_9 , V_73 )
& V_74 ) ) {
T_1 V_75 ;
V_75 = F_7 ( V_9 , V_76 ) ;
if ( V_66 <= 8 )
( ( V_77 * ) V_48 -> V_78 ) [ V_65 ] = V_75 ;
else if ( V_66 <= 16 )
( ( V_79 * ) V_48 -> V_78 ) [ V_65 ] = V_75 ;
else
( ( T_1 * ) V_48 -> V_78 ) [ V_65 ] = V_75 ;
} else {
F_40 ( & V_9 -> V_35 , L_2 ) ;
V_51 -= ( V_66 <= 8 ) ? 1 :
( V_66 <= 16 ) ? 2 :
4 ;
}
F_11 ( V_9 , 1 ) ;
return V_51 ;
}
static unsigned
F_41 ( struct V_8 * V_9 , struct V_47 * V_48 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_41 * V_42 ;
unsigned int V_51 ;
T_1 V_17 ;
V_77 * V_80 ;
const V_77 * V_55 ;
struct V_49 V_50 ;
enum V_81 V_82 ;
unsigned V_64 ;
void T_2 * V_83 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
V_17 = F_8 ( V_9 ) ;
if ( V_11 -> V_66 <= 8 ) {
V_82 = V_84 ;
V_64 = 1 ;
} else if ( V_11 -> V_66 <= 16 ) {
V_82 = V_85 ;
V_64 = 2 ;
} else {
V_82 = V_86 ;
V_64 = 4 ;
}
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_87 = V_11 -> V_88 + V_76 ;
V_50 . V_89 = V_11 -> V_88 + V_90 ;
V_50 . V_91 = V_82 ;
V_50 . V_92 = V_82 ;
V_50 . V_93 = 1 ;
V_50 . V_94 = 1 ;
V_80 = V_48 -> V_78 ;
V_55 = V_48 -> V_95 ;
V_51 = V_48 -> V_52 ;
if ( V_55 != NULL )
F_28 ( V_9 , V_48 , V_50 ) ;
if ( V_80 != NULL )
V_51 = F_36 ( V_9 , V_48 , V_50 , V_64 ) ;
if ( V_55 != NULL ) {
V_83 = V_11 -> V_7 + V_73 ;
F_37 ( & V_42 -> V_46 ) ;
F_38 ( V_6 -> V_35 , V_48 -> V_58 , V_48 -> V_52 ,
V_96 ) ;
if ( V_80 == NULL ) {
if ( F_21 ( V_83 ,
V_97 ) < 0 )
F_40 ( & V_9 -> V_35 , L_3 ) ;
else if ( F_21 ( V_83 ,
V_98 ) < 0 )
F_40 ( & V_9 -> V_35 , L_4 ) ;
}
}
return V_51 ;
}
static unsigned
F_42 ( struct V_8 * V_9 , struct V_47 * V_48 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_51 , V_99 ;
T_1 V_17 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_100 ;
void T_2 * V_101 ;
void T_2 * V_83 ;
int V_66 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_51 = V_48 -> V_52 ;
V_99 = V_51 ;
V_66 = V_11 -> V_66 ;
V_17 = F_8 ( V_9 ) ;
V_100 = V_7 + V_90 ;
V_101 = V_7 + V_76 ;
V_83 = V_7 + V_73 ;
if ( V_99 < ( V_66 >> 3 ) )
return 0 ;
if ( V_66 <= 8 ) {
V_77 * V_80 ;
const V_77 * V_55 ;
V_80 = V_48 -> V_78 ;
V_55 = V_48 -> V_95 ;
do {
V_99 -= 1 ;
if ( V_55 != NULL ) {
if ( F_21 ( V_83 ,
V_97 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
goto V_102;
}
F_43 ( & V_9 -> V_35 , L_5 ,
V_66 , * V_55 ) ;
F_3 ( * V_55 ++ , V_100 ) ;
}
if ( V_80 != NULL ) {
if ( F_21 ( V_83 ,
V_74 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_6 ) ;
goto V_102;
}
if ( V_99 == 1 && V_55 == NULL &&
( V_17 & V_69 ) ) {
F_11 ( V_9 , 0 ) ;
* V_80 ++ = F_5 ( V_101 ) ;
F_43 ( & V_9 -> V_35 , L_7 ,
V_66 , * ( V_80 - 1 ) ) ;
if ( F_21 ( V_83 ,
V_74 ) < 0 ) {
F_40 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_102;
}
V_99 = 0 ;
} else if ( V_99 == 0 && V_55 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_80 ++ = F_5 ( V_101 ) ;
F_43 ( & V_9 -> V_35 , L_7 ,
V_66 , * ( V_80 - 1 ) ) ;
}
} while ( V_99 );
} else if ( V_66 <= 16 ) {
V_79 * V_80 ;
const V_79 * V_55 ;
V_80 = V_48 -> V_78 ;
V_55 = V_48 -> V_95 ;
do {
V_99 -= 2 ;
if ( V_55 != NULL ) {
if ( F_21 ( V_83 ,
V_97 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
goto V_102;
}
F_43 ( & V_9 -> V_35 , L_8 ,
V_66 , * V_55 ) ;
F_3 ( * V_55 ++ , V_100 ) ;
}
if ( V_80 != NULL ) {
if ( F_21 ( V_83 ,
V_74 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_6 ) ;
goto V_102;
}
if ( V_99 == 2 && V_55 == NULL &&
( V_17 & V_69 ) ) {
F_11 ( V_9 , 0 ) ;
* V_80 ++ = F_5 ( V_101 ) ;
F_43 ( & V_9 -> V_35 , L_9 ,
V_66 , * ( V_80 - 1 ) ) ;
if ( F_21 ( V_83 ,
V_74 ) < 0 ) {
F_40 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_102;
}
V_99 = 0 ;
} else if ( V_99 == 0 && V_55 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_80 ++ = F_5 ( V_101 ) ;
F_43 ( & V_9 -> V_35 , L_9 ,
V_66 , * ( V_80 - 1 ) ) ;
}
} while ( V_99 >= 2 );
} else if ( V_66 <= 32 ) {
T_1 * V_80 ;
const T_1 * V_55 ;
V_80 = V_48 -> V_78 ;
V_55 = V_48 -> V_95 ;
do {
V_99 -= 4 ;
if ( V_55 != NULL ) {
if ( F_21 ( V_83 ,
V_97 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
goto V_102;
}
F_43 ( & V_9 -> V_35 , L_10 ,
V_66 , * V_55 ) ;
F_3 ( * V_55 ++ , V_100 ) ;
}
if ( V_80 != NULL ) {
if ( F_21 ( V_83 ,
V_74 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_6 ) ;
goto V_102;
}
if ( V_99 == 4 && V_55 == NULL &&
( V_17 & V_69 ) ) {
F_11 ( V_9 , 0 ) ;
* V_80 ++ = F_5 ( V_101 ) ;
F_43 ( & V_9 -> V_35 , L_11 ,
V_66 , * ( V_80 - 1 ) ) ;
if ( F_21 ( V_83 ,
V_74 ) < 0 ) {
F_40 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_102;
}
V_99 = 0 ;
} else if ( V_99 == 0 && V_55 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_80 ++ = F_5 ( V_101 ) ;
F_43 ( & V_9 -> V_35 , L_11 ,
V_66 , * ( V_80 - 1 ) ) ;
}
} while ( V_99 >= 4 );
}
if ( V_48 -> V_78 == NULL ) {
if ( F_21 ( V_83 ,
V_97 ) < 0 ) {
F_40 ( & V_9 -> V_35 , L_3 ) ;
} else if ( F_21 ( V_83 ,
V_98 ) < 0 )
F_40 ( & V_9 -> V_35 , L_4 ) ;
F_11 ( V_9 , 0 ) ;
}
V_102:
F_11 ( V_9 , 1 ) ;
return V_51 - V_99 ;
}
static T_1 F_44 ( T_1 V_103 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_103 >= ( V_104 >> div ) )
return div ;
return 15 ;
}
static int F_45 ( struct V_8 * V_9 ,
struct V_47 * V_105 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_32 ;
T_1 V_17 = 0 , div = 0 ;
V_77 V_66 = V_9 -> V_106 ;
T_1 V_103 = V_9 -> V_107 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_32 = V_6 -> V_2 ;
if ( V_105 != NULL && V_105 -> V_106 )
V_66 = V_105 -> V_106 ;
V_11 -> V_66 = V_66 ;
if ( V_105 && V_105 -> V_103 )
V_103 = V_105 -> V_103 ;
V_103 = F_46 ( T_1 , V_103 , V_104 ) ;
div = F_44 ( V_103 ) ;
V_17 = F_8 ( V_9 ) ;
if ( V_6 -> V_108 == V_109 ) {
V_17 &= ~ V_110 ;
V_17 &= ~ V_111 ;
V_17 |= V_112 ;
} else {
V_17 |= V_110 ;
V_17 |= V_111 ;
V_17 &= ~ V_112 ;
}
V_17 &= ~ V_113 ;
V_17 |= ( V_66 - 1 ) << 7 ;
if ( ! ( V_9 -> V_114 & V_115 ) )
V_17 |= V_116 ;
else
V_17 &= ~ V_116 ;
V_17 &= ~ V_117 ;
V_17 |= div << 2 ;
if ( V_9 -> V_114 & V_118 )
V_17 |= V_119 ;
else
V_17 &= ~ V_119 ;
if ( V_9 -> V_114 & V_120 )
V_17 |= V_121 ;
else
V_17 &= ~ V_121 ;
F_9 ( V_9 , V_17 ) ;
F_47 ( & V_9 -> V_35 , L_12 ,
V_104 >> div ,
( V_9 -> V_114 & V_120 ) ? L_13 : L_14 ,
( V_9 -> V_114 & V_118 ) ? L_15 : L_16 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_41 * V_42 ;
T_4 V_122 ;
unsigned V_123 ;
V_6 = F_2 ( V_2 ) ;
V_42 = V_6 -> V_43 + V_9 -> V_44 ;
F_49 ( & V_42 -> V_45 ) ;
F_49 ( & V_42 -> V_46 ) ;
F_50 ( V_122 ) ;
F_51 ( V_124 , V_122 ) ;
V_123 = V_42 -> V_125 ;
V_42 -> V_68 = F_52 ( V_122 , V_126 , & V_123 ) ;
if ( ! V_42 -> V_68 ) {
F_40 ( & V_9 -> V_35 , L_17 ) ;
return - V_127 ;
}
V_123 = V_42 -> V_128 ;
V_42 -> V_53 = F_52 ( V_122 , V_126 , & V_123 ) ;
if ( ! V_42 -> V_53 ) {
F_40 ( & V_9 -> V_35 , L_18 ) ;
F_53 ( V_42 -> V_68 ) ;
V_42 -> V_68 = NULL ;
return - V_127 ;
}
return 0 ;
}
static int F_54 ( struct V_8 * V_9 )
{
int V_129 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_41 * V_42 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_106 < 4 || V_9 -> V_106 > 32 ) {
F_47 ( & V_9 -> V_35 , L_19 ,
V_9 -> V_106 ) ;
return - V_130 ;
}
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
if ( ! V_11 ) {
V_11 = F_55 ( sizeof *V_11 , V_131 ) ;
if ( ! V_11 )
return - V_132 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_44 * 0x14 ;
V_11 -> V_88 = V_6 -> V_88 + V_9 -> V_44 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_56 ( & V_11 -> V_133 , & V_26 -> V_11 ) ;
}
if ( ! V_42 -> V_68 || ! V_42 -> V_53 ) {
V_129 = F_48 ( V_9 ) ;
if ( V_129 < 0 )
return V_129 ;
}
V_129 = F_17 ( V_6 -> V_35 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_45 ( V_9 , NULL ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return V_129 ;
}
static void F_57 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_58 ( & V_11 -> V_133 ) ;
F_59 ( V_11 ) ;
}
if ( V_9 -> V_44 < V_9 -> V_2 -> V_134 ) {
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
if ( V_42 -> V_68 ) {
F_53 ( V_42 -> V_68 ) ;
V_42 -> V_68 = NULL ;
}
if ( V_42 -> V_53 ) {
F_53 ( V_42 -> V_53 ) ;
V_42 -> V_53 = NULL ;
}
}
}
static void F_60 ( struct V_5 * V_6 , struct V_135 * V_136 )
{
struct V_8 * V_9 ;
struct V_47 * V_105 = NULL ;
int V_23 = 0 ;
struct V_10 * V_11 ;
struct V_137 * V_138 ;
int V_139 = 0 ;
int V_140 = 0 ;
T_1 V_141 ;
V_9 = V_136 -> V_9 ;
V_11 = V_9 -> V_12 ;
V_138 = V_9 -> V_142 ;
F_11 ( V_9 , 1 ) ;
F_15 (t, &m->transfers, transfer_list) {
if ( V_105 -> V_95 == NULL && V_105 -> V_78 == NULL && V_105 -> V_52 ) {
V_140 = - V_130 ;
break;
}
if ( V_139 || V_105 -> V_103 || V_105 -> V_106 ) {
V_139 = 1 ;
V_140 = F_45 ( V_9 , V_105 ) ;
if ( V_140 < 0 )
break;
if ( ! V_105 -> V_103 && ! V_105 -> V_106 )
V_139 = 0 ;
}
if ( ! V_23 ) {
F_12 ( V_9 , 1 ) ;
V_23 = 1 ;
}
V_141 = F_8 ( V_9 ) ;
V_141 &= ~ V_143 ;
V_141 &= ~ V_69 ;
if ( V_105 -> V_95 == NULL )
V_141 |= V_144 ;
else if ( V_105 -> V_78 == NULL )
V_141 |= V_145 ;
if ( V_138 && V_138 -> V_146 && V_105 -> V_95 == NULL ) {
if ( V_105 -> V_52 > ( ( V_11 -> V_66 + 7 ) >> 3 ) )
V_141 |= V_69 ;
}
F_9 ( V_9 , V_141 ) ;
if ( V_105 -> V_52 ) {
unsigned V_51 ;
if ( V_105 -> V_95 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_90 ) ;
if ( V_136 -> V_147 || V_105 -> V_52 >= V_148 )
V_51 = F_41 ( V_9 , V_105 ) ;
else
V_51 = F_42 ( V_9 , V_105 ) ;
V_136 -> V_149 += V_51 ;
if ( V_51 != V_105 -> V_52 ) {
V_140 = - V_150 ;
break;
}
}
if ( V_105 -> V_151 )
F_61 ( V_105 -> V_151 ) ;
if ( V_105 -> V_152 ) {
F_12 ( V_9 , 0 ) ;
V_23 = 0 ;
}
}
if ( V_139 ) {
V_139 = 0 ;
V_140 = F_45 ( V_9 , NULL ) ;
}
if ( V_23 )
F_12 ( V_9 , 0 ) ;
F_11 ( V_9 , 0 ) ;
V_136 -> V_140 = V_140 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_5 * V_6 ;
struct V_47 * V_105 ;
V_6 = F_2 ( V_2 ) ;
V_136 -> V_149 = 0 ;
V_136 -> V_140 = 0 ;
if ( F_63 ( & V_136 -> V_153 ) )
return - V_130 ;
F_15 (t, &m->transfers, transfer_list) {
const void * V_95 = V_105 -> V_95 ;
void * V_78 = V_105 -> V_78 ;
unsigned V_52 = V_105 -> V_52 ;
if ( V_105 -> V_103 > V_104
|| ( V_52 && ! ( V_78 || V_95 ) )
|| ( V_105 -> V_106 &&
( V_105 -> V_106 < 4
|| V_105 -> V_106 > 32 ) ) ) {
F_47 ( V_6 -> V_35 , L_20 ,
V_105 -> V_103 ,
V_52 ,
V_95 ? L_21 : L_22 ,
V_78 ? L_23 : L_22 ,
V_105 -> V_106 ) ;
return - V_130 ;
}
if ( V_105 -> V_103 && V_105 -> V_103 < ( V_104 >> 15 ) ) {
F_47 ( V_6 -> V_35 , L_24 ,
V_105 -> V_103 ,
V_104 >> 15 ) ;
return - V_130 ;
}
if ( V_136 -> V_147 || V_52 < V_148 )
continue;
if ( V_95 != NULL ) {
V_105 -> V_58 = F_64 ( V_6 -> V_35 , ( void * ) V_95 ,
V_52 , V_96 ) ;
if ( F_65 ( V_6 -> V_35 , V_105 -> V_58 ) ) {
F_47 ( V_6 -> V_35 , L_25 ,
'T' , V_52 ) ;
return - V_130 ;
}
}
if ( V_78 != NULL ) {
V_105 -> V_70 = F_64 ( V_6 -> V_35 , V_78 , V_105 -> V_52 ,
V_72 ) ;
if ( F_65 ( V_6 -> V_35 , V_105 -> V_70 ) ) {
F_47 ( V_6 -> V_35 , L_25 ,
'R' , V_52 ) ;
if ( V_95 != NULL )
F_38 ( V_6 -> V_35 , V_105 -> V_58 ,
V_52 , V_96 ) ;
return - V_130 ;
}
}
}
F_60 ( V_6 , V_136 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_25 * V_26 = & V_6 -> V_26 ;
int V_129 = 0 ;
V_129 = F_17 ( V_6 -> V_35 ) ;
if ( V_129 < 0 )
return V_129 ;
F_1 ( V_2 , V_33 ,
V_154 ) ;
V_26 -> V_34 = V_154 ;
F_13 ( V_2 ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_68 ( struct V_155 * V_35 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_69 ( V_35 ) ;
V_6 = F_2 ( V_2 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
static int F_70 ( struct V_156 * V_157 )
{
struct V_1 * V_2 ;
const struct V_158 * V_159 ;
struct V_5 * V_6 ;
struct V_160 * V_161 ;
int V_140 = 0 , V_162 ;
T_1 V_163 = 0 ;
static int V_164 = 1 ;
struct V_165 * V_133 = V_157 -> V_35 . V_166 ;
const struct V_167 * V_168 ;
struct V_169 * V_169 ;
V_2 = F_71 ( & V_157 -> V_35 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_47 ( & V_157 -> V_35 , L_26 ) ;
return - V_132 ;
}
V_2 -> V_170 = V_118 | V_120 | V_115 ;
V_2 -> V_171 = F_54 ;
V_2 -> V_172 = F_16 ;
V_2 -> V_173 = F_18 ;
V_2 -> V_174 = F_62 ;
V_2 -> V_175 = F_57 ;
V_2 -> V_35 . V_166 = V_133 ;
F_72 ( & V_157 -> V_35 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_168 = F_73 ( V_176 , & V_157 -> V_35 ) ;
if ( V_168 ) {
T_1 V_177 = 1 ;
V_159 = V_168 -> V_40 ;
F_74 ( V_133 , L_27 , & V_177 ) ;
V_2 -> V_134 = V_177 ;
V_2 -> V_164 = V_164 ++ ;
if ( F_75 ( V_133 , L_28 , NULL ) )
V_6 -> V_108 = V_178 ;
} else {
V_159 = V_157 -> V_35 . V_179 ;
V_2 -> V_134 = V_159 -> V_177 ;
if ( V_157 -> V_180 != - 1 )
V_2 -> V_164 = V_157 -> V_180 ;
V_6 -> V_108 = V_159 -> V_108 ;
}
V_163 = V_159 -> V_163 ;
V_161 = F_76 ( V_157 , V_181 , 0 ) ;
if ( V_161 == NULL ) {
V_140 = - V_182 ;
goto V_183;
}
V_161 -> V_184 += V_163 ;
V_161 -> V_185 += V_163 ;
V_6 -> V_88 = V_161 -> V_184 ;
V_6 -> V_7 = F_77 ( & V_157 -> V_35 , V_161 ) ;
if ( ! V_6 -> V_7 ) {
F_47 ( & V_157 -> V_35 , L_29 ) ;
V_140 = - V_132 ;
goto V_183;
}
V_6 -> V_35 = & V_157 -> V_35 ;
F_78 ( & V_6 -> V_26 . V_11 ) ;
V_6 -> V_43 = F_79 ( V_2 -> V_134 ,
sizeof( struct V_41 ) ,
V_131 ) ;
if ( V_6 -> V_43 == NULL )
goto V_183;
for ( V_162 = 0 ; V_162 < V_2 -> V_134 ; V_162 ++ ) {
char V_186 [ 14 ] ;
struct V_160 * V_187 ;
sprintf ( V_186 , L_30 , V_162 ) ;
V_187 = F_80 ( V_157 , V_188 ,
V_186 ) ;
if ( ! V_187 ) {
F_47 ( & V_157 -> V_35 , L_31 ) ;
V_140 = - V_182 ;
break;
}
V_6 -> V_43 [ V_162 ] . V_125 = V_187 -> V_184 ;
sprintf ( V_186 , L_32 , V_162 ) ;
V_187 = F_80 ( V_157 , V_188 ,
V_186 ) ;
if ( ! V_187 ) {
F_47 ( & V_157 -> V_35 , L_33 ) ;
V_140 = - V_182 ;
break;
}
V_6 -> V_43 [ V_162 ] . V_128 = V_187 -> V_184 ;
}
if ( V_140 < 0 )
goto V_189;
V_169 = F_81 ( & V_157 -> V_35 ) ;
if ( F_82 ( V_169 ) )
F_83 ( & V_157 -> V_35 ,
L_34 ) ;
F_84 ( & V_157 -> V_35 ) ;
F_85 ( & V_157 -> V_35 , V_190 ) ;
F_86 ( & V_157 -> V_35 ) ;
if ( V_140 || F_67 ( V_6 ) < 0 )
goto V_191;
V_140 = F_87 ( V_2 ) ;
if ( V_140 < 0 )
goto V_191;
return V_140 ;
V_191:
F_88 ( & V_157 -> V_35 ) ;
V_189:
F_59 ( V_6 -> V_43 ) ;
V_183:
F_89 ( V_2 ) ;
return V_140 ;
}
static int F_90 ( struct V_156 * V_157 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_41 * V_43 ;
V_2 = F_69 ( & V_157 -> V_35 ) ;
V_6 = F_2 ( V_2 ) ;
V_43 = V_6 -> V_43 ;
F_91 ( V_6 -> V_35 ) ;
F_88 ( & V_157 -> V_35 ) ;
F_92 ( V_2 ) ;
F_59 ( V_43 ) ;
return 0 ;
}
static int F_93 ( struct V_155 * V_35 )
{
struct V_1 * V_2 = F_69 ( V_35 ) ;
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
