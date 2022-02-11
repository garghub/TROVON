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
F_11 ( V_17 , V_18 , V_16 ) ;
F_9 ( V_9 , V_17 ) ;
}
static void F_12 ( const struct V_8 * V_9 , int V_16 )
{
T_1 V_17 ;
V_17 = V_16 ? V_21 : 0 ;
F_6 ( V_9 , V_22 , V_17 ) ;
F_7 ( V_9 , V_22 ) ;
}
static void F_13 ( struct V_8 * V_9 , int V_23 )
{
T_1 V_17 ;
V_17 = F_8 ( V_9 ) ;
F_11 ( V_17 , V_24 , V_23 ) ;
F_9 ( V_9 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_17 ;
V_17 = F_4 ( V_2 , V_25 ) ;
F_11 ( V_17 , V_26 , 0 ) ;
F_11 ( V_17 , V_27 , 0 ) ;
F_11 ( V_17 , V_28 , 1 ) ;
F_1 ( V_2 , V_25 , V_17 ) ;
V_29 [ V_2 -> V_30 - 1 ] . V_31 = V_17 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_32 ;
struct V_10 * V_11 ;
V_32 = V_6 -> V_2 ;
F_1 ( V_32 , V_25 ,
V_29 [ V_32 -> V_30 - 1 ] . V_31 ) ;
F_1 ( V_32 , V_33 ,
V_29 [ V_32 -> V_30 - 1 ] . V_34 ) ;
F_16 (cs, &omap2_mcspi_ctx[spi_cntrl->bus_num - 1].cs,
node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 -> V_35 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
return F_20 ( V_6 -> V_35 ) ;
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
static unsigned
F_25 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_42 * V_43 ;
unsigned int V_44 , V_45 ;
unsigned long V_7 , V_46 , V_47 ;
int V_48 , V_49 , V_50 ;
int V_51 = 0 ;
T_1 V_17 ;
T_3 * V_52 ;
const T_3 * V_53 ;
void T_2 * V_54 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & V_6 -> V_55 [ V_9 -> V_56 ] ;
V_17 = F_8 ( V_9 ) ;
V_54 = V_11 -> V_7 + V_57 ;
V_44 = V_41 -> V_58 ;
V_45 = V_44 ;
V_48 = V_11 -> V_48 ;
V_7 = V_11 -> V_59 ;
V_46 = V_7 + V_60 ;
V_47 = V_7 + V_61 ;
V_52 = V_41 -> V_62 ;
V_53 = V_41 -> V_63 ;
if ( V_48 <= 8 ) {
V_49 = V_64 ;
V_50 = V_44 ;
} else if ( V_48 <= 16 ) {
V_49 = V_65 ;
V_50 = V_44 >> 1 ;
} else {
V_49 = V_66 ;
V_50 = V_44 >> 2 ;
}
if ( V_53 != NULL ) {
F_26 ( V_43 -> V_67 ,
V_49 , V_50 , 1 ,
V_68 ,
V_43 -> V_69 , 0 ) ;
F_27 ( V_43 -> V_67 , 0 ,
V_70 ,
V_46 , 0 , 0 ) ;
F_28 ( V_43 -> V_67 , 0 ,
V_71 ,
V_41 -> V_72 , 0 , 0 ) ;
}
if ( V_52 != NULL ) {
V_51 = V_50 - 1 ;
if ( V_17 & V_73 )
V_51 -- ;
F_26 ( V_43 -> V_74 ,
V_49 , V_51 , 1 ,
V_68 ,
V_43 -> V_75 , 1 ) ;
F_28 ( V_43 -> V_74 , 0 ,
V_70 ,
V_47 , 0 , 0 ) ;
F_27 ( V_43 -> V_74 , 0 ,
V_71 ,
V_41 -> V_76 , 0 , 0 ) ;
}
if ( V_53 != NULL ) {
F_29 ( V_43 -> V_67 ) ;
F_10 ( V_9 , 0 , 1 ) ;
}
if ( V_52 != NULL ) {
F_29 ( V_43 -> V_74 ) ;
F_10 ( V_9 , 1 , 1 ) ;
}
if ( V_53 != NULL ) {
F_30 ( & V_43 -> V_77 ) ;
F_31 ( & V_9 -> V_35 , V_41 -> V_72 , V_44 , V_78 ) ;
if ( V_52 == NULL ) {
if ( F_21 ( V_54 ,
V_79 ) < 0 )
F_32 ( & V_9 -> V_35 , L_1 ) ;
else if ( F_21 ( V_54 ,
V_80 ) < 0 )
F_32 ( & V_9 -> V_35 , L_2 ) ;
}
}
if ( V_52 != NULL ) {
F_30 ( & V_43 -> V_81 ) ;
F_31 ( & V_9 -> V_35 , V_41 -> V_76 , V_44 , V_82 ) ;
F_12 ( V_9 , 0 ) ;
if ( V_17 & V_73 ) {
if ( F_33 ( F_7 ( V_9 , V_57 )
& V_83 ) ) {
T_1 V_84 ;
V_84 = F_7 ( V_9 , V_61 ) ;
if ( V_48 <= 8 )
( ( T_3 * ) V_41 -> V_62 ) [ V_51 ++ ] = V_84 ;
else if ( V_48 <= 16 )
( ( V_85 * ) V_41 -> V_62 ) [ V_51 ++ ] = V_84 ;
else
( ( T_1 * ) V_41 -> V_62 ) [ V_51 ++ ] = V_84 ;
} else {
F_32 ( & V_9 -> V_35 ,
L_3 ) ;
V_44 -= ( V_48 <= 8 ) ? 2 :
( V_48 <= 16 ) ? 4 :
8 ;
F_12 ( V_9 , 1 ) ;
return V_44 ;
}
}
if ( F_33 ( F_7 ( V_9 , V_57 )
& V_83 ) ) {
T_1 V_84 ;
V_84 = F_7 ( V_9 , V_61 ) ;
if ( V_48 <= 8 )
( ( T_3 * ) V_41 -> V_62 ) [ V_51 ] = V_84 ;
else if ( V_48 <= 16 )
( ( V_85 * ) V_41 -> V_62 ) [ V_51 ] = V_84 ;
else
( ( T_1 * ) V_41 -> V_62 ) [ V_51 ] = V_84 ;
} else {
F_32 ( & V_9 -> V_35 , L_4 ) ;
V_44 -= ( V_48 <= 8 ) ? 1 :
( V_48 <= 16 ) ? 2 :
4 ;
}
F_12 ( V_9 , 1 ) ;
}
return V_44 ;
}
static unsigned
F_34 ( struct V_8 * V_9 , struct V_40 * V_41 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned int V_44 , V_45 ;
T_1 V_17 ;
void T_2 * V_7 = V_11 -> V_7 ;
void T_2 * V_46 ;
void T_2 * V_47 ;
void T_2 * V_54 ;
int V_48 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_44 = V_41 -> V_58 ;
V_45 = V_44 ;
V_48 = V_11 -> V_48 ;
V_17 = F_8 ( V_9 ) ;
V_46 = V_7 + V_60 ;
V_47 = V_7 + V_61 ;
V_54 = V_7 + V_57 ;
if ( V_45 < ( V_48 >> 3 ) )
return 0 ;
if ( V_48 <= 8 ) {
T_3 * V_52 ;
const T_3 * V_53 ;
V_52 = V_41 -> V_62 ;
V_53 = V_41 -> V_63 ;
do {
V_45 -= 1 ;
if ( V_53 != NULL ) {
if ( F_21 ( V_54 ,
V_79 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_1 ) ;
goto V_86;
}
F_35 ( & V_9 -> V_35 , L_5 ,
V_48 , * V_53 ) ;
F_3 ( * V_53 ++ , V_46 ) ;
}
if ( V_52 != NULL ) {
if ( F_21 ( V_54 ,
V_83 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_6 ) ;
goto V_86;
}
if ( V_45 == 1 && V_53 == NULL &&
( V_17 & V_73 ) ) {
F_12 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_47 ) ;
F_35 ( & V_9 -> V_35 , L_7 ,
V_48 , * ( V_52 - 1 ) ) ;
if ( F_21 ( V_54 ,
V_83 ) < 0 ) {
F_32 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_86;
}
V_45 = 0 ;
} else if ( V_45 == 0 && V_53 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_47 ) ;
F_35 ( & V_9 -> V_35 , L_7 ,
V_48 , * ( V_52 - 1 ) ) ;
}
} while ( V_45 );
} else if ( V_48 <= 16 ) {
V_85 * V_52 ;
const V_85 * V_53 ;
V_52 = V_41 -> V_62 ;
V_53 = V_41 -> V_63 ;
do {
V_45 -= 2 ;
if ( V_53 != NULL ) {
if ( F_21 ( V_54 ,
V_79 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_1 ) ;
goto V_86;
}
F_35 ( & V_9 -> V_35 , L_8 ,
V_48 , * V_53 ) ;
F_3 ( * V_53 ++ , V_46 ) ;
}
if ( V_52 != NULL ) {
if ( F_21 ( V_54 ,
V_83 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_6 ) ;
goto V_86;
}
if ( V_45 == 2 && V_53 == NULL &&
( V_17 & V_73 ) ) {
F_12 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_47 ) ;
F_35 ( & V_9 -> V_35 , L_9 ,
V_48 , * ( V_52 - 1 ) ) ;
if ( F_21 ( V_54 ,
V_83 ) < 0 ) {
F_32 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_86;
}
V_45 = 0 ;
} else if ( V_45 == 0 && V_53 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_47 ) ;
F_35 ( & V_9 -> V_35 , L_9 ,
V_48 , * ( V_52 - 1 ) ) ;
}
} while ( V_45 >= 2 );
} else if ( V_48 <= 32 ) {
T_1 * V_52 ;
const T_1 * V_53 ;
V_52 = V_41 -> V_62 ;
V_53 = V_41 -> V_63 ;
do {
V_45 -= 4 ;
if ( V_53 != NULL ) {
if ( F_21 ( V_54 ,
V_79 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_1 ) ;
goto V_86;
}
F_35 ( & V_9 -> V_35 , L_10 ,
V_48 , * V_53 ) ;
F_3 ( * V_53 ++ , V_46 ) ;
}
if ( V_52 != NULL ) {
if ( F_21 ( V_54 ,
V_83 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_6 ) ;
goto V_86;
}
if ( V_45 == 4 && V_53 == NULL &&
( V_17 & V_73 ) ) {
F_12 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_47 ) ;
F_35 ( & V_9 -> V_35 , L_11 ,
V_48 , * ( V_52 - 1 ) ) ;
if ( F_21 ( V_54 ,
V_83 ) < 0 ) {
F_32 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_86;
}
V_45 = 0 ;
} else if ( V_45 == 0 && V_53 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_47 ) ;
F_35 ( & V_9 -> V_35 , L_11 ,
V_48 , * ( V_52 - 1 ) ) ;
}
} while ( V_45 >= 4 );
}
if ( V_41 -> V_62 == NULL ) {
if ( F_21 ( V_54 ,
V_79 ) < 0 ) {
F_32 ( & V_9 -> V_35 , L_1 ) ;
} else if ( F_21 ( V_54 ,
V_80 ) < 0 )
F_32 ( & V_9 -> V_35 , L_2 ) ;
F_12 ( V_9 , 0 ) ;
}
V_86:
F_12 ( V_9 , 1 ) ;
return V_44 - V_45 ;
}
static T_1 F_36 ( T_1 V_87 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_87 >= ( V_88 >> div ) )
return div ;
return 15 ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_40 * V_89 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_5 * V_6 ;
struct V_1 * V_32 ;
T_1 V_17 = 0 , div = 0 ;
T_3 V_48 = V_9 -> V_90 ;
T_1 V_87 = V_9 -> V_91 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_32 = V_6 -> V_2 ;
if ( V_89 != NULL && V_89 -> V_90 )
V_48 = V_89 -> V_90 ;
V_11 -> V_48 = V_48 ;
if ( V_89 && V_89 -> V_87 )
V_87 = V_89 -> V_87 ;
V_87 = F_38 ( T_1 , V_87 , V_88 ) ;
div = F_36 ( V_87 ) ;
V_17 = F_8 ( V_9 ) ;
V_17 &= ~ ( V_92 | V_93 ) ;
V_17 |= V_94 ;
V_17 &= ~ V_95 ;
V_17 |= ( V_48 - 1 ) << 7 ;
if ( ! ( V_9 -> V_96 & V_97 ) )
V_17 |= V_98 ;
else
V_17 &= ~ V_98 ;
V_17 &= ~ V_99 ;
V_17 |= div << 2 ;
if ( V_9 -> V_96 & V_100 )
V_17 |= V_101 ;
else
V_17 &= ~ V_101 ;
if ( V_9 -> V_96 & V_102 )
V_17 |= V_103 ;
else
V_17 &= ~ V_103 ;
F_9 ( V_9 , V_17 ) ;
F_39 ( & V_9 -> V_35 , L_12 ,
V_88 >> div ,
( V_9 -> V_96 & V_102 ) ? L_13 : L_14 ,
( V_9 -> V_96 & V_100 ) ? L_15 : L_16 ) ;
return 0 ;
}
static void F_40 ( int V_104 , V_85 V_105 , void * V_106 )
{
struct V_8 * V_9 = V_106 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & ( V_6 -> V_55 [ V_9 -> V_56 ] ) ;
F_41 ( & V_43 -> V_81 ) ;
F_10 ( V_9 , 1 , 0 ) ;
}
static void F_42 ( int V_104 , V_85 V_105 , void * V_106 )
{
struct V_8 * V_9 = V_106 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & ( V_6 -> V_55 [ V_9 -> V_56 ] ) ;
F_41 ( & V_43 -> V_77 ) ;
F_10 ( V_9 , 0 , 0 ) ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_6 = F_2 ( V_2 ) ;
V_43 = V_6 -> V_55 + V_9 -> V_56 ;
if ( F_44 ( V_43 -> V_75 , L_17 ,
F_40 , V_9 ,
& V_43 -> V_74 ) ) {
F_32 ( & V_9 -> V_35 , L_18 ) ;
return - V_107 ;
}
if ( F_44 ( V_43 -> V_69 , L_19 ,
F_42 , V_9 ,
& V_43 -> V_67 ) ) {
F_45 ( V_43 -> V_74 ) ;
V_43 -> V_74 = - 1 ;
F_32 ( & V_9 -> V_35 , L_20 ) ;
return - V_107 ;
}
F_46 ( & V_43 -> V_81 ) ;
F_46 ( & V_43 -> V_77 ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 )
{
int V_108 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_90 < 4 || V_9 -> V_90 > 32 ) {
F_39 ( & V_9 -> V_35 , L_21 ,
V_9 -> V_90 ) ;
return - V_109 ;
}
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & V_6 -> V_55 [ V_9 -> V_56 ] ;
if ( ! V_11 ) {
V_11 = F_48 ( sizeof *V_11 , V_110 ) ;
if ( ! V_11 )
return - V_111 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_56 * 0x14 ;
V_11 -> V_59 = V_6 -> V_59 + V_9 -> V_56 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_49 ( & V_11 -> V_112 ,
& V_29 [ V_6 -> V_2 -> V_30 - 1 ] . V_11 ) ;
}
if ( V_43 -> V_74 == - 1
|| V_43 -> V_67 == - 1 ) {
V_108 = F_43 ( V_9 ) ;
if ( V_108 < 0 )
return V_108 ;
}
V_108 = F_19 ( V_6 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_37 ( V_9 , NULL ) ;
F_17 ( V_6 ) ;
return V_108 ;
}
static void F_50 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_51 ( & V_11 -> V_112 ) ;
F_52 ( V_9 -> V_12 ) ;
}
if ( V_9 -> V_56 < V_9 -> V_2 -> V_113 ) {
V_43 = & V_6 -> V_55 [ V_9 -> V_56 ] ;
if ( V_43 -> V_74 != - 1 ) {
F_45 ( V_43 -> V_74 ) ;
V_43 -> V_74 = - 1 ;
}
if ( V_43 -> V_67 != - 1 ) {
F_45 ( V_43 -> V_67 ) ;
V_43 -> V_67 = - 1 ;
}
}
}
static void F_53 ( struct V_114 * V_115 )
{
struct V_5 * V_6 ;
V_6 = F_54 ( V_115 , struct V_5 , V_115 ) ;
if ( F_19 ( V_6 ) < 0 )
return;
F_55 ( & V_6 -> V_116 ) ;
while ( ! F_56 ( & V_6 -> V_117 ) ) {
struct V_118 * V_119 ;
struct V_8 * V_9 ;
struct V_40 * V_89 = NULL ;
int V_23 = 0 ;
struct V_10 * V_11 ;
struct V_120 * V_121 ;
int V_122 = 0 ;
int V_123 = 0 ;
T_1 V_124 ;
V_119 = F_54 ( V_6 -> V_117 . V_125 , struct V_118 ,
V_126 ) ;
F_57 ( & V_119 -> V_126 ) ;
F_58 ( & V_6 -> V_116 ) ;
V_9 = V_119 -> V_9 ;
V_11 = V_9 -> V_12 ;
V_121 = V_9 -> V_127 ;
F_12 ( V_9 , 1 ) ;
F_16 (t, &m->transfers, transfer_list) {
if ( V_89 -> V_63 == NULL && V_89 -> V_62 == NULL && V_89 -> V_58 ) {
V_123 = - V_109 ;
break;
}
if ( V_122 || V_89 -> V_87 || V_89 -> V_90 ) {
V_122 = 1 ;
V_123 = F_37 ( V_9 , V_89 ) ;
if ( V_123 < 0 )
break;
if ( ! V_89 -> V_87 && ! V_89 -> V_90 )
V_122 = 0 ;
}
if ( ! V_23 ) {
F_13 ( V_9 , 1 ) ;
V_23 = 1 ;
}
V_124 = F_8 ( V_9 ) ;
V_124 &= ~ V_128 ;
V_124 &= ~ V_73 ;
if ( V_89 -> V_63 == NULL )
V_124 |= V_129 ;
else if ( V_89 -> V_62 == NULL )
V_124 |= V_130 ;
if ( V_121 && V_121 -> V_131 && V_89 -> V_63 == NULL ) {
if ( V_89 -> V_58 > ( ( V_11 -> V_48 + 7 ) >> 3 ) )
V_124 |= V_73 ;
}
F_9 ( V_9 , V_124 ) ;
if ( V_89 -> V_58 ) {
unsigned V_44 ;
if ( V_89 -> V_63 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_60 ) ;
if ( V_119 -> V_132 || V_89 -> V_58 >= V_133 )
V_44 = F_25 ( V_9 , V_89 ) ;
else
V_44 = F_34 ( V_9 , V_89 ) ;
V_119 -> V_134 += V_44 ;
if ( V_44 != V_89 -> V_58 ) {
V_123 = - V_135 ;
break;
}
}
if ( V_89 -> V_136 )
F_59 ( V_89 -> V_136 ) ;
if ( V_89 -> V_137 ) {
F_13 ( V_9 , 0 ) ;
V_23 = 0 ;
}
}
if ( V_122 ) {
V_122 = 0 ;
V_123 = F_37 ( V_9 , NULL ) ;
}
if ( V_23 )
F_13 ( V_9 , 0 ) ;
F_12 ( V_9 , 0 ) ;
V_119 -> V_123 = V_123 ;
V_119 -> F_41 ( V_119 -> V_138 ) ;
F_55 ( & V_6 -> V_116 ) ;
}
F_58 ( & V_6 -> V_116 ) ;
F_17 ( V_6 ) ;
}
static int F_60 ( struct V_8 * V_9 , struct V_118 * V_119 )
{
struct V_5 * V_6 ;
unsigned long V_139 ;
struct V_40 * V_89 ;
V_119 -> V_134 = 0 ;
V_119 -> V_123 = 0 ;
if ( F_56 ( & V_119 -> V_140 ) || ! V_119 -> F_41 )
return - V_109 ;
F_16 (t, &m->transfers, transfer_list) {
const void * V_63 = V_89 -> V_63 ;
void * V_62 = V_89 -> V_62 ;
unsigned V_58 = V_89 -> V_58 ;
if ( V_89 -> V_87 > V_88
|| ( V_58 && ! ( V_62 || V_63 ) )
|| ( V_89 -> V_90 &&
( V_89 -> V_90 < 4
|| V_89 -> V_90 > 32 ) ) ) {
F_39 ( & V_9 -> V_35 , L_22 ,
V_89 -> V_87 ,
V_58 ,
V_63 ? L_23 : L_24 ,
V_62 ? L_25 : L_24 ,
V_89 -> V_90 ) ;
return - V_109 ;
}
if ( V_89 -> V_87 && V_89 -> V_87 < ( V_88 >> 15 ) ) {
F_39 ( & V_9 -> V_35 , L_26 ,
V_89 -> V_87 ,
V_88 >> 15 ) ;
return - V_109 ;
}
if ( V_119 -> V_132 || V_58 < V_133 )
continue;
if ( V_63 != NULL ) {
V_89 -> V_72 = F_61 ( & V_9 -> V_35 , ( void * ) V_63 ,
V_58 , V_78 ) ;
if ( F_62 ( & V_9 -> V_35 , V_89 -> V_72 ) ) {
F_39 ( & V_9 -> V_35 , L_27 ,
'T' , V_58 ) ;
return - V_109 ;
}
}
if ( V_62 != NULL ) {
V_89 -> V_76 = F_61 ( & V_9 -> V_35 , V_62 , V_89 -> V_58 ,
V_82 ) ;
if ( F_62 ( & V_9 -> V_35 , V_89 -> V_76 ) ) {
F_39 ( & V_9 -> V_35 , L_27 ,
'R' , V_58 ) ;
if ( V_63 != NULL )
F_31 ( & V_9 -> V_35 , V_89 -> V_72 ,
V_58 , V_78 ) ;
return - V_109 ;
}
}
}
V_6 = F_2 ( V_9 -> V_2 ) ;
F_63 ( & V_6 -> V_116 , V_139 ) ;
F_49 ( & V_119 -> V_126 , & V_6 -> V_117 ) ;
F_64 ( V_6 -> V_141 , & V_6 -> V_115 ) ;
F_65 ( & V_6 -> V_116 , V_139 ) ;
return 0 ;
}
static int T_4 F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 V_142 ;
int V_108 = 0 ;
V_108 = F_19 ( V_6 ) ;
if ( V_108 < 0 )
return V_108 ;
V_142 = V_143 ;
F_1 ( V_2 , V_33 , V_142 ) ;
V_29 [ V_2 -> V_30 - 1 ] . V_34 = V_142 ;
F_14 ( V_2 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int F_67 ( struct V_144 * V_35 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_68 ( V_35 ) ;
V_6 = F_2 ( V_2 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
static int T_4 F_69 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
struct V_147 * V_148 ;
struct V_5 * V_6 ;
struct V_149 * V_150 ;
int V_123 = 0 , V_151 ;
char V_152 [ 20 ] ;
T_1 V_153 = 0 ;
static int V_30 = 1 ;
struct V_154 * V_112 = V_146 -> V_35 . V_155 ;
const struct V_156 * V_157 ;
V_2 = F_70 ( & V_146 -> V_35 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_39 ( & V_146 -> V_35 , L_28 ) ;
return - V_111 ;
}
V_2 -> V_158 = V_100 | V_102 | V_97 ;
V_2 -> V_159 = F_47 ;
V_2 -> V_160 = F_60 ;
V_2 -> V_161 = F_50 ;
V_2 -> V_35 . V_155 = V_112 ;
V_157 = F_71 ( V_162 , & V_146 -> V_35 ) ;
if ( V_157 ) {
T_1 V_163 = 1 ;
V_148 = V_157 -> V_106 ;
F_72 ( V_112 , L_29 , & V_163 ) ;
V_2 -> V_113 = V_163 ;
V_2 -> V_30 = V_30 ++ ;
} else {
V_148 = V_146 -> V_35 . V_164 ;
V_2 -> V_113 = V_148 -> V_163 ;
if ( V_146 -> V_165 != - 1 )
V_2 -> V_30 = V_146 -> V_165 ;
}
V_153 = V_148 -> V_153 ;
F_73 ( & V_146 -> V_35 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
sprintf ( V_152 , L_30 , V_2 -> V_30 ) ;
V_6 -> V_141 = F_74 ( V_152 , V_166 , 1 ) ;
if ( V_6 -> V_141 == NULL ) {
V_123 = - V_111 ;
goto V_167;
}
V_150 = F_75 ( V_146 , V_168 , 0 ) ;
if ( V_150 == NULL ) {
V_123 = - V_169 ;
goto V_167;
}
V_150 -> V_170 += V_153 ;
V_150 -> V_171 += V_153 ;
V_6 -> V_59 = V_150 -> V_170 ;
if ( ! F_76 ( V_150 -> V_170 , F_77 ( V_150 ) ,
F_78 ( & V_146 -> V_35 ) ) ) {
V_123 = - V_172 ;
goto V_167;
}
V_6 -> V_7 = F_79 ( V_150 -> V_170 , F_77 ( V_150 ) ) ;
if ( ! V_6 -> V_7 ) {
F_39 ( & V_146 -> V_35 , L_31 ) ;
V_123 = - V_111 ;
goto V_173;
}
V_6 -> V_35 = & V_146 -> V_35 ;
F_80 ( & V_6 -> V_115 , F_53 ) ;
F_81 ( & V_6 -> V_116 ) ;
F_82 ( & V_6 -> V_117 ) ;
F_82 ( & V_29 [ V_2 -> V_30 - 1 ] . V_11 ) ;
V_6 -> V_55 = F_83 ( V_2 -> V_113 ,
sizeof( struct V_42 ) ,
V_110 ) ;
if ( V_6 -> V_55 == NULL )
goto V_174;
for ( V_151 = 0 ; V_151 < V_2 -> V_113 ; V_151 ++ ) {
char V_175 [ 14 ] ;
struct V_149 * V_176 ;
sprintf ( V_175 , L_32 , V_151 ) ;
V_176 = F_84 ( V_146 , V_177 ,
V_175 ) ;
if ( ! V_176 ) {
F_39 ( & V_146 -> V_35 , L_33 ) ;
V_123 = - V_169 ;
break;
}
V_6 -> V_55 [ V_151 ] . V_74 = - 1 ;
V_6 -> V_55 [ V_151 ] . V_75 = V_176 -> V_170 ;
sprintf ( V_175 , L_34 , V_151 ) ;
V_176 = F_84 ( V_146 , V_177 ,
V_175 ) ;
if ( ! V_176 ) {
F_39 ( & V_146 -> V_35 , L_35 ) ;
V_123 = - V_169 ;
break;
}
V_6 -> V_55 [ V_151 ] . V_67 = - 1 ;
V_6 -> V_55 [ V_151 ] . V_69 = V_176 -> V_170 ;
}
if ( V_123 < 0 )
goto V_178;
F_85 ( & V_146 -> V_35 ) ;
if ( V_123 || F_66 ( V_6 ) < 0 )
goto V_179;
V_123 = F_86 ( V_2 ) ;
if ( V_123 < 0 )
goto V_180;
return V_123 ;
V_180:
F_87 ( V_2 ) ;
V_179:
F_88 ( & V_146 -> V_35 ) ;
V_178:
F_52 ( V_6 -> V_55 ) ;
V_174:
F_89 ( V_6 -> V_7 ) ;
V_173:
F_90 ( V_150 -> V_170 , F_77 ( V_150 ) ) ;
V_167:
F_52 ( V_2 ) ;
F_91 ( V_146 , NULL ) ;
return V_123 ;
}
static int T_5 F_92 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_42 * V_55 ;
struct V_149 * V_150 ;
void T_2 * V_7 ;
V_2 = F_68 ( & V_146 -> V_35 ) ;
V_6 = F_2 ( V_2 ) ;
V_55 = V_6 -> V_55 ;
F_17 ( V_6 ) ;
F_88 ( & V_146 -> V_35 ) ;
V_150 = F_75 ( V_146 , V_168 , 0 ) ;
F_90 ( V_150 -> V_170 , F_77 ( V_150 ) ) ;
V_7 = V_6 -> V_7 ;
F_93 ( V_2 ) ;
F_89 ( V_7 ) ;
F_52 ( V_55 ) ;
F_94 ( V_6 -> V_141 ) ;
F_91 ( V_146 , NULL ) ;
return 0 ;
}
static int F_95 ( struct V_144 * V_35 )
{
struct V_1 * V_2 = F_68 ( V_35 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
F_19 ( V_6 ) ;
F_16 (cs, &omap2_mcspi_ctx[master->bus_num - 1].cs,
node) {
if ( ( V_11 -> V_13 & V_24 ) == 0 ) {
F_11 ( V_11 -> V_13 , V_24 , 1 ) ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
F_11 ( V_11 -> V_13 , V_24 , 0 ) ;
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
}
F_17 ( V_6 ) ;
return 0 ;
}
static int T_4 F_96 ( void )
{
return F_97 ( & V_181 , F_69 ) ;
}
static void T_5 F_98 ( void )
{
F_99 ( & V_181 ) ;
}
