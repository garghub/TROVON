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
T_3 * V_52 ;
const T_3 * V_53 ;
void T_2 * V_54 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
V_51 = V_48 -> V_55 ;
V_52 = V_48 -> V_56 ;
V_53 = V_48 -> V_57 ;
V_54 = V_11 -> V_7 + V_58 ;
if ( V_42 -> V_59 ) {
struct V_60 * V_53 ;
struct V_61 V_62 ;
F_29 ( V_42 -> V_59 , & V_50 ) ;
F_30 ( & V_62 , 1 ) ;
F_31 ( & V_62 ) = V_48 -> V_63 ;
F_32 ( & V_62 ) = V_48 -> V_55 ;
V_53 = F_33 ( V_42 -> V_59 , & V_62 , 1 ,
V_64 , V_65 | V_66 ) ;
if ( V_53 ) {
V_53 -> V_67 = F_27 ;
V_53 -> V_68 = V_9 ;
F_34 ( V_53 ) ;
} else {
}
}
F_35 ( V_42 -> V_59 ) ;
F_10 ( V_9 , 0 , 1 ) ;
F_36 ( & V_42 -> V_46 ) ;
F_37 ( V_6 -> V_35 , V_48 -> V_63 , V_51 ,
V_69 ) ;
if ( V_52 == NULL ) {
if ( F_21 ( V_54 ,
V_70 ) < 0 )
F_38 ( & V_9 -> V_35 , L_1 ) ;
else if ( F_21 ( V_54 ,
V_71 ) < 0 )
F_38 ( & V_9 -> V_35 , L_2 ) ;
}
}
static unsigned
F_39 ( struct V_8 * V_9 , struct V_47 * V_48 ,
struct V_49 V_50 ,
unsigned V_72 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
unsigned int V_51 ;
T_1 V_17 ;
int V_73 = 0 ;
int V_74 , V_75 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
V_51 = V_48 -> V_55 ;
V_74 = V_11 -> V_74 ;
V_17 = F_8 ( V_9 ) ;
if ( V_74 <= 8 )
V_75 = V_51 ;
else if ( V_74 <= 16 )
V_75 = V_51 >> 1 ;
else
V_75 = V_51 >> 2 ;
if ( V_42 -> V_76 ) {
struct V_60 * V_53 ;
struct V_61 V_62 ;
T_4 V_55 = V_48 -> V_55 - V_72 ;
F_29 ( V_42 -> V_76 , & V_50 ) ;
if ( V_17 & V_77 )
V_55 -= V_72 ;
F_30 ( & V_62 , 1 ) ;
F_31 ( & V_62 ) = V_48 -> V_78 ;
F_32 ( & V_62 ) = V_55 ;
V_53 = F_33 ( V_42 -> V_76 , & V_62 , 1 ,
V_79 , V_65 |
V_66 ) ;
if ( V_53 ) {
V_53 -> V_67 = F_25 ;
V_53 -> V_68 = V_9 ;
F_34 ( V_53 ) ;
} else {
}
}
F_35 ( V_42 -> V_76 ) ;
F_10 ( V_9 , 1 , 1 ) ;
F_36 ( & V_42 -> V_45 ) ;
F_37 ( V_6 -> V_35 , V_48 -> V_78 , V_51 ,
V_80 ) ;
F_11 ( V_9 , 0 ) ;
V_73 = V_75 - 1 ;
if ( V_17 & V_77 ) {
V_73 -- ;
if ( F_40 ( F_7 ( V_9 , V_58 )
& V_81 ) ) {
T_1 V_82 ;
V_82 = F_7 ( V_9 , V_83 ) ;
if ( V_74 <= 8 )
( ( T_3 * ) V_48 -> V_56 ) [ V_73 ++ ] = V_82 ;
else if ( V_74 <= 16 )
( ( V_84 * ) V_48 -> V_56 ) [ V_73 ++ ] = V_82 ;
else
( ( T_1 * ) V_48 -> V_56 ) [ V_73 ++ ] = V_82 ;
} else {
F_38 ( & V_9 -> V_35 , L_3 ) ;
V_51 -= ( V_74 <= 8 ) ? 2 :
( V_74 <= 16 ) ? 4 :
8 ;
F_11 ( V_9 , 1 ) ;
return V_51 ;
}
}
if ( F_40 ( F_7 ( V_9 , V_58 )
& V_81 ) ) {
T_1 V_82 ;
V_82 = F_7 ( V_9 , V_83 ) ;
if ( V_74 <= 8 )
( ( T_3 * ) V_48 -> V_56 ) [ V_73 ] = V_82 ;
else if ( V_74 <= 16 )
( ( V_84 * ) V_48 -> V_56 ) [ V_73 ] = V_82 ;
else
( ( T_1 * ) V_48 -> V_56 ) [ V_73 ] = V_82 ;
} else {
F_38 ( & V_9 -> V_35 , L_4 ) ;
V_51 -= ( V_74 <= 8 ) ? 1 :
( V_74 <= 16 ) ? 2 :
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
T_3 * V_52 ;
const T_3 * V_53 ;
struct V_49 V_50 ;
enum V_85 V_86 ;
unsigned V_72 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
V_17 = F_8 ( V_9 ) ;
if ( V_11 -> V_74 <= 8 ) {
V_86 = V_87 ;
V_72 = 1 ;
} else if ( V_11 -> V_74 <= 16 ) {
V_86 = V_88 ;
V_72 = 2 ;
} else {
V_86 = V_89 ;
V_72 = 4 ;
}
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_90 = V_11 -> V_91 + V_83 ;
V_50 . V_92 = V_11 -> V_91 + V_93 ;
V_50 . V_94 = V_86 ;
V_50 . V_95 = V_86 ;
V_50 . V_96 = 1 ;
V_50 . V_97 = 1 ;
V_52 = V_48 -> V_56 ;
V_53 = V_48 -> V_57 ;
V_51 = V_48 -> V_55 ;
if ( V_53 != NULL )
F_28 ( V_9 , V_48 , V_50 ) ;
if ( V_52 != NULL )
return F_39 ( V_9 , V_48 , V_50 , V_72 ) ;
return V_51 ;
}
static unsigned
F_42 ( struct V_8 * V_9 , struct V_47 * V_48 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_51 , V_98 ;
T_1 V_17 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_99 ;
void T_2 * V_100 ;
void T_2 * V_54 ;
int V_74 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_51 = V_48 -> V_55 ;
V_98 = V_51 ;
V_74 = V_11 -> V_74 ;
V_17 = F_8 ( V_9 ) ;
V_99 = V_7 + V_93 ;
V_100 = V_7 + V_83 ;
V_54 = V_7 + V_58 ;
if ( V_98 < ( V_74 >> 3 ) )
return 0 ;
if ( V_74 <= 8 ) {
T_3 * V_52 ;
const T_3 * V_53 ;
V_52 = V_48 -> V_56 ;
V_53 = V_48 -> V_57 ;
do {
V_98 -= 1 ;
if ( V_53 != NULL ) {
if ( F_21 ( V_54 ,
V_70 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_1 ) ;
goto V_101;
}
F_43 ( & V_9 -> V_35 , L_5 ,
V_74 , * V_53 ) ;
F_3 ( * V_53 ++ , V_99 ) ;
}
if ( V_52 != NULL ) {
if ( F_21 ( V_54 ,
V_81 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_6 ) ;
goto V_101;
}
if ( V_98 == 1 && V_53 == NULL &&
( V_17 & V_77 ) ) {
F_11 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_100 ) ;
F_43 ( & V_9 -> V_35 , L_7 ,
V_74 , * ( V_52 - 1 ) ) ;
if ( F_21 ( V_54 ,
V_81 ) < 0 ) {
F_38 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_101;
}
V_98 = 0 ;
} else if ( V_98 == 0 && V_53 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_100 ) ;
F_43 ( & V_9 -> V_35 , L_7 ,
V_74 , * ( V_52 - 1 ) ) ;
}
} while ( V_98 );
} else if ( V_74 <= 16 ) {
V_84 * V_52 ;
const V_84 * V_53 ;
V_52 = V_48 -> V_56 ;
V_53 = V_48 -> V_57 ;
do {
V_98 -= 2 ;
if ( V_53 != NULL ) {
if ( F_21 ( V_54 ,
V_70 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_1 ) ;
goto V_101;
}
F_43 ( & V_9 -> V_35 , L_8 ,
V_74 , * V_53 ) ;
F_3 ( * V_53 ++ , V_99 ) ;
}
if ( V_52 != NULL ) {
if ( F_21 ( V_54 ,
V_81 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_6 ) ;
goto V_101;
}
if ( V_98 == 2 && V_53 == NULL &&
( V_17 & V_77 ) ) {
F_11 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_100 ) ;
F_43 ( & V_9 -> V_35 , L_9 ,
V_74 , * ( V_52 - 1 ) ) ;
if ( F_21 ( V_54 ,
V_81 ) < 0 ) {
F_38 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_101;
}
V_98 = 0 ;
} else if ( V_98 == 0 && V_53 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_100 ) ;
F_43 ( & V_9 -> V_35 , L_9 ,
V_74 , * ( V_52 - 1 ) ) ;
}
} while ( V_98 >= 2 );
} else if ( V_74 <= 32 ) {
T_1 * V_52 ;
const T_1 * V_53 ;
V_52 = V_48 -> V_56 ;
V_53 = V_48 -> V_57 ;
do {
V_98 -= 4 ;
if ( V_53 != NULL ) {
if ( F_21 ( V_54 ,
V_70 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_1 ) ;
goto V_101;
}
F_43 ( & V_9 -> V_35 , L_10 ,
V_74 , * V_53 ) ;
F_3 ( * V_53 ++ , V_99 ) ;
}
if ( V_52 != NULL ) {
if ( F_21 ( V_54 ,
V_81 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_6 ) ;
goto V_101;
}
if ( V_98 == 4 && V_53 == NULL &&
( V_17 & V_77 ) ) {
F_11 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_100 ) ;
F_43 ( & V_9 -> V_35 , L_11 ,
V_74 , * ( V_52 - 1 ) ) ;
if ( F_21 ( V_54 ,
V_81 ) < 0 ) {
F_38 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_101;
}
V_98 = 0 ;
} else if ( V_98 == 0 && V_53 == NULL ) {
F_11 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_100 ) ;
F_43 ( & V_9 -> V_35 , L_11 ,
V_74 , * ( V_52 - 1 ) ) ;
}
} while ( V_98 >= 4 );
}
if ( V_48 -> V_56 == NULL ) {
if ( F_21 ( V_54 ,
V_70 ) < 0 ) {
F_38 ( & V_9 -> V_35 , L_1 ) ;
} else if ( F_21 ( V_54 ,
V_71 ) < 0 )
F_38 ( & V_9 -> V_35 , L_2 ) ;
F_11 ( V_9 , 0 ) ;
}
V_101:
F_11 ( V_9 , 1 ) ;
return V_51 - V_98 ;
}
static T_1 F_44 ( T_1 V_102 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_102 >= ( V_103 >> div ) )
return div ;
return 15 ;
}
static int F_45 ( struct V_8 * V_9 ,
struct V_47 * V_104 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_32 ;
T_1 V_17 = 0 , div = 0 ;
T_3 V_74 = V_9 -> V_105 ;
T_1 V_102 = V_9 -> V_106 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_32 = V_6 -> V_2 ;
if ( V_104 != NULL && V_104 -> V_105 )
V_74 = V_104 -> V_105 ;
V_11 -> V_74 = V_74 ;
if ( V_104 && V_104 -> V_102 )
V_102 = V_104 -> V_102 ;
V_102 = F_46 ( T_1 , V_102 , V_103 ) ;
div = F_44 ( V_102 ) ;
V_17 = F_8 ( V_9 ) ;
V_17 &= ~ ( V_107 | V_108 ) ;
V_17 |= V_109 ;
V_17 &= ~ V_110 ;
V_17 |= ( V_74 - 1 ) << 7 ;
if ( ! ( V_9 -> V_111 & V_112 ) )
V_17 |= V_113 ;
else
V_17 &= ~ V_113 ;
V_17 &= ~ V_114 ;
V_17 |= div << 2 ;
if ( V_9 -> V_111 & V_115 )
V_17 |= V_116 ;
else
V_17 &= ~ V_116 ;
if ( V_9 -> V_111 & V_117 )
V_17 |= V_118 ;
else
V_17 &= ~ V_118 ;
F_9 ( V_9 , V_17 ) ;
F_47 ( & V_9 -> V_35 , L_12 ,
V_103 >> div ,
( V_9 -> V_111 & V_117 ) ? L_13 : L_14 ,
( V_9 -> V_111 & V_115 ) ? L_15 : L_16 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_41 * V_42 ;
T_5 V_119 ;
unsigned V_120 ;
V_6 = F_2 ( V_2 ) ;
V_42 = V_6 -> V_43 + V_9 -> V_44 ;
F_49 ( & V_42 -> V_45 ) ;
F_49 ( & V_42 -> V_46 ) ;
F_50 ( V_119 ) ;
F_51 ( V_121 , V_119 ) ;
V_120 = V_42 -> V_122 ;
V_42 -> V_76 = F_52 ( V_119 , V_123 , & V_120 ) ;
if ( ! V_42 -> V_76 ) {
F_38 ( & V_9 -> V_35 , L_17 ) ;
return - V_124 ;
}
V_120 = V_42 -> V_125 ;
V_42 -> V_59 = F_52 ( V_119 , V_123 , & V_120 ) ;
if ( ! V_42 -> V_59 ) {
F_38 ( & V_9 -> V_35 , L_18 ) ;
F_53 ( V_42 -> V_76 ) ;
V_42 -> V_76 = NULL ;
return - V_124 ;
}
return 0 ;
}
static int F_54 ( struct V_8 * V_9 )
{
int V_126 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_41 * V_42 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_105 < 4 || V_9 -> V_105 > 32 ) {
F_47 ( & V_9 -> V_35 , L_19 ,
V_9 -> V_105 ) ;
return - V_127 ;
}
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
if ( ! V_11 ) {
V_11 = F_55 ( sizeof *V_11 , V_128 ) ;
if ( ! V_11 )
return - V_129 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_44 * 0x14 ;
V_11 -> V_91 = V_6 -> V_91 + V_9 -> V_44 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_56 ( & V_11 -> V_130 , & V_26 -> V_11 ) ;
}
if ( ! V_42 -> V_76 || ! V_42 -> V_59 ) {
V_126 = F_48 ( V_9 ) ;
if ( V_126 < 0 )
return V_126 ;
}
V_126 = F_17 ( V_6 -> V_35 ) ;
if ( V_126 < 0 )
return V_126 ;
V_126 = F_45 ( V_9 , NULL ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return V_126 ;
}
static void F_57 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_58 ( & V_11 -> V_130 ) ;
F_59 ( V_11 ) ;
}
if ( V_9 -> V_44 < V_9 -> V_2 -> V_131 ) {
V_42 = & V_6 -> V_43 [ V_9 -> V_44 ] ;
if ( V_42 -> V_76 ) {
F_53 ( V_42 -> V_76 ) ;
V_42 -> V_76 = NULL ;
}
if ( V_42 -> V_59 ) {
F_53 ( V_42 -> V_59 ) ;
V_42 -> V_59 = NULL ;
}
}
}
static void F_60 ( struct V_5 * V_6 , struct V_132 * V_133 )
{
struct V_8 * V_9 ;
struct V_47 * V_104 = NULL ;
int V_23 = 0 ;
struct V_10 * V_11 ;
struct V_134 * V_135 ;
int V_136 = 0 ;
int V_137 = 0 ;
T_1 V_138 ;
V_9 = V_133 -> V_9 ;
V_11 = V_9 -> V_12 ;
V_135 = V_9 -> V_139 ;
F_11 ( V_9 , 1 ) ;
F_15 (t, &m->transfers, transfer_list) {
if ( V_104 -> V_57 == NULL && V_104 -> V_56 == NULL && V_104 -> V_55 ) {
V_137 = - V_127 ;
break;
}
if ( V_136 || V_104 -> V_102 || V_104 -> V_105 ) {
V_136 = 1 ;
V_137 = F_45 ( V_9 , V_104 ) ;
if ( V_137 < 0 )
break;
if ( ! V_104 -> V_102 && ! V_104 -> V_105 )
V_136 = 0 ;
}
if ( ! V_23 ) {
F_12 ( V_9 , 1 ) ;
V_23 = 1 ;
}
V_138 = F_8 ( V_9 ) ;
V_138 &= ~ V_140 ;
V_138 &= ~ V_77 ;
if ( V_104 -> V_57 == NULL )
V_138 |= V_141 ;
else if ( V_104 -> V_56 == NULL )
V_138 |= V_142 ;
if ( V_135 && V_135 -> V_143 && V_104 -> V_57 == NULL ) {
if ( V_104 -> V_55 > ( ( V_11 -> V_74 + 7 ) >> 3 ) )
V_138 |= V_77 ;
}
F_9 ( V_9 , V_138 ) ;
if ( V_104 -> V_55 ) {
unsigned V_51 ;
if ( V_104 -> V_57 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_93 ) ;
if ( V_133 -> V_144 || V_104 -> V_55 >= V_145 )
V_51 = F_41 ( V_9 , V_104 ) ;
else
V_51 = F_42 ( V_9 , V_104 ) ;
V_133 -> V_146 += V_51 ;
if ( V_51 != V_104 -> V_55 ) {
V_137 = - V_147 ;
break;
}
}
if ( V_104 -> V_148 )
F_61 ( V_104 -> V_148 ) ;
if ( V_104 -> V_149 ) {
F_12 ( V_9 , 0 ) ;
V_23 = 0 ;
}
}
if ( V_136 ) {
V_136 = 0 ;
V_137 = F_45 ( V_9 , NULL ) ;
}
if ( V_23 )
F_12 ( V_9 , 0 ) ;
F_11 ( V_9 , 0 ) ;
V_133 -> V_137 = V_137 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_5 * V_6 ;
struct V_47 * V_104 ;
V_6 = F_2 ( V_2 ) ;
V_133 -> V_146 = 0 ;
V_133 -> V_137 = 0 ;
if ( F_63 ( & V_133 -> V_150 ) )
return - V_127 ;
F_15 (t, &m->transfers, transfer_list) {
const void * V_57 = V_104 -> V_57 ;
void * V_56 = V_104 -> V_56 ;
unsigned V_55 = V_104 -> V_55 ;
if ( V_104 -> V_102 > V_103
|| ( V_55 && ! ( V_56 || V_57 ) )
|| ( V_104 -> V_105 &&
( V_104 -> V_105 < 4
|| V_104 -> V_105 > 32 ) ) ) {
F_47 ( V_6 -> V_35 , L_20 ,
V_104 -> V_102 ,
V_55 ,
V_57 ? L_21 : L_22 ,
V_56 ? L_23 : L_22 ,
V_104 -> V_105 ) ;
return - V_127 ;
}
if ( V_104 -> V_102 && V_104 -> V_102 < ( V_103 >> 15 ) ) {
F_47 ( V_6 -> V_35 , L_24 ,
V_104 -> V_102 ,
V_103 >> 15 ) ;
return - V_127 ;
}
if ( V_133 -> V_144 || V_55 < V_145 )
continue;
if ( V_57 != NULL ) {
V_104 -> V_63 = F_64 ( V_6 -> V_35 , ( void * ) V_57 ,
V_55 , V_69 ) ;
if ( F_65 ( V_6 -> V_35 , V_104 -> V_63 ) ) {
F_47 ( V_6 -> V_35 , L_25 ,
'T' , V_55 ) ;
return - V_127 ;
}
}
if ( V_56 != NULL ) {
V_104 -> V_78 = F_64 ( V_6 -> V_35 , V_56 , V_104 -> V_55 ,
V_80 ) ;
if ( F_65 ( V_6 -> V_35 , V_104 -> V_78 ) ) {
F_47 ( V_6 -> V_35 , L_25 ,
'R' , V_55 ) ;
if ( V_57 != NULL )
F_37 ( V_6 -> V_35 , V_104 -> V_63 ,
V_55 , V_69 ) ;
return - V_127 ;
}
}
}
F_60 ( V_6 , V_133 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int T_6 F_67 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_25 * V_26 = & V_6 -> V_26 ;
int V_126 = 0 ;
V_126 = F_17 ( V_6 -> V_35 ) ;
if ( V_126 < 0 )
return V_126 ;
F_1 ( V_2 , V_33 ,
V_151 ) ;
V_26 -> V_34 = V_151 ;
F_13 ( V_2 ) ;
F_19 ( V_6 -> V_35 ) ;
F_20 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_68 ( struct V_152 * V_35 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_69 ( V_35 ) ;
V_6 = F_2 ( V_2 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
static int T_6 F_70 ( struct V_153 * V_154 )
{
struct V_1 * V_2 ;
const struct V_155 * V_156 ;
struct V_5 * V_6 ;
struct V_157 * V_158 ;
int V_137 = 0 , V_159 ;
T_1 V_160 = 0 ;
static int V_161 = 1 ;
struct V_162 * V_130 = V_154 -> V_35 . V_163 ;
const struct V_164 * V_165 ;
struct V_166 * V_166 ;
V_2 = F_71 ( & V_154 -> V_35 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_47 ( & V_154 -> V_35 , L_26 ) ;
return - V_129 ;
}
V_2 -> V_167 = V_115 | V_117 | V_112 ;
V_2 -> V_168 = F_54 ;
V_2 -> V_169 = F_16 ;
V_2 -> V_170 = F_18 ;
V_2 -> V_171 = F_62 ;
V_2 -> V_172 = F_57 ;
V_2 -> V_35 . V_163 = V_130 ;
V_165 = F_72 ( V_173 , & V_154 -> V_35 ) ;
if ( V_165 ) {
T_1 V_174 = 1 ;
V_156 = V_165 -> V_40 ;
F_73 ( V_130 , L_27 , & V_174 ) ;
V_2 -> V_131 = V_174 ;
V_2 -> V_161 = V_161 ++ ;
} else {
V_156 = V_154 -> V_35 . V_175 ;
V_2 -> V_131 = V_156 -> V_174 ;
if ( V_154 -> V_176 != - 1 )
V_2 -> V_161 = V_154 -> V_176 ;
}
V_160 = V_156 -> V_160 ;
F_74 ( & V_154 -> V_35 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_158 = F_75 ( V_154 , V_177 , 0 ) ;
if ( V_158 == NULL ) {
V_137 = - V_178 ;
goto V_179;
}
V_158 -> V_180 += V_160 ;
V_158 -> V_181 += V_160 ;
V_6 -> V_91 = V_158 -> V_180 ;
V_6 -> V_7 = F_76 ( & V_154 -> V_35 , V_158 ) ;
if ( ! V_6 -> V_7 ) {
F_47 ( & V_154 -> V_35 , L_28 ) ;
V_137 = - V_129 ;
goto V_179;
}
V_6 -> V_35 = & V_154 -> V_35 ;
F_77 ( & V_6 -> V_26 . V_11 ) ;
V_6 -> V_43 = F_78 ( V_2 -> V_131 ,
sizeof( struct V_41 ) ,
V_128 ) ;
if ( V_6 -> V_43 == NULL )
goto V_179;
for ( V_159 = 0 ; V_159 < V_2 -> V_131 ; V_159 ++ ) {
char V_182 [ 14 ] ;
struct V_157 * V_183 ;
sprintf ( V_182 , L_29 , V_159 ) ;
V_183 = F_79 ( V_154 , V_184 ,
V_182 ) ;
if ( ! V_183 ) {
F_47 ( & V_154 -> V_35 , L_30 ) ;
V_137 = - V_178 ;
break;
}
V_6 -> V_43 [ V_159 ] . V_122 = V_183 -> V_180 ;
sprintf ( V_182 , L_31 , V_159 ) ;
V_183 = F_79 ( V_154 , V_184 ,
V_182 ) ;
if ( ! V_183 ) {
F_47 ( & V_154 -> V_35 , L_32 ) ;
V_137 = - V_178 ;
break;
}
V_6 -> V_43 [ V_159 ] . V_125 = V_183 -> V_180 ;
}
if ( V_137 < 0 )
goto V_185;
V_166 = F_80 ( & V_154 -> V_35 ) ;
if ( F_81 ( V_166 ) )
F_82 ( & V_154 -> V_35 ,
L_33 ) ;
F_83 ( & V_154 -> V_35 ) ;
F_84 ( & V_154 -> V_35 , V_186 ) ;
F_85 ( & V_154 -> V_35 ) ;
if ( V_137 || F_67 ( V_6 ) < 0 )
goto V_187;
V_137 = F_86 ( V_2 ) ;
if ( V_137 < 0 )
goto V_187;
return V_137 ;
V_187:
F_87 ( & V_154 -> V_35 ) ;
V_185:
F_59 ( V_6 -> V_43 ) ;
V_179:
F_88 ( V_2 ) ;
return V_137 ;
}
static int T_7 F_89 ( struct V_153 * V_154 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_41 * V_43 ;
V_2 = F_69 ( & V_154 -> V_35 ) ;
V_6 = F_2 ( V_2 ) ;
V_43 = V_6 -> V_43 ;
F_90 ( V_6 -> V_35 ) ;
F_87 ( & V_154 -> V_35 ) ;
F_91 ( V_2 ) ;
F_59 ( V_43 ) ;
return 0 ;
}
static int F_92 ( struct V_152 * V_35 )
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
