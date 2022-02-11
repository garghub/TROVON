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
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
T_1 V_17 ;
V_17 = F_4 ( V_2 , V_27 ) ;
F_11 ( V_17 , V_28 , 0 ) ;
F_11 ( V_17 , V_29 , 0 ) ;
F_11 ( V_17 , V_30 , 1 ) ;
F_1 ( V_2 , V_27 , V_17 ) ;
V_26 -> V_31 = V_17 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_32 = V_6 -> V_2 ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_10 * V_11 ;
F_1 ( V_32 , V_27 , V_26 -> V_31 ) ;
F_1 ( V_32 , V_33 , V_26 -> V_34 ) ;
F_16 (cs, &ctx->cs, node)
F_3 ( V_11 -> V_13 , V_11 -> V_7 + V_14 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 -> V_35 ) ;
F_19 ( V_6 -> V_35 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
return F_21 ( V_6 -> V_35 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_21 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_18 ( V_6 -> V_35 ) ;
F_19 ( V_6 -> V_35 ) ;
return 0 ;
}
static int F_24 ( void T_2 * V_36 , unsigned long V_37 )
{
unsigned long V_38 ;
V_38 = V_39 + F_25 ( 1000 ) ;
while ( ! ( F_5 ( V_36 ) & V_37 ) ) {
if ( F_26 ( V_39 , V_38 ) )
return - 1 ;
F_27 () ;
}
return 0 ;
}
static unsigned
F_28 ( struct V_8 * V_9 , struct V_40 * V_41 )
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
F_29 ( V_43 -> V_67 ,
V_49 , V_50 , 1 ,
V_68 ,
V_43 -> V_69 , 0 ) ;
F_30 ( V_43 -> V_67 , 0 ,
V_70 ,
V_46 , 0 , 0 ) ;
F_31 ( V_43 -> V_67 , 0 ,
V_71 ,
V_41 -> V_72 , 0 , 0 ) ;
}
if ( V_52 != NULL ) {
V_51 = V_50 - 1 ;
if ( V_17 & V_73 )
V_51 -- ;
F_29 ( V_43 -> V_74 ,
V_49 , V_51 , 1 ,
V_68 ,
V_43 -> V_75 , 1 ) ;
F_31 ( V_43 -> V_74 , 0 ,
V_70 ,
V_47 , 0 , 0 ) ;
F_30 ( V_43 -> V_74 , 0 ,
V_71 ,
V_41 -> V_76 , 0 , 0 ) ;
}
if ( V_53 != NULL ) {
F_32 ( V_43 -> V_67 ) ;
F_10 ( V_9 , 0 , 1 ) ;
}
if ( V_52 != NULL ) {
F_32 ( V_43 -> V_74 ) ;
F_10 ( V_9 , 1 , 1 ) ;
}
if ( V_53 != NULL ) {
F_33 ( & V_43 -> V_77 ) ;
F_34 ( & V_9 -> V_35 , V_41 -> V_72 , V_44 , V_78 ) ;
if ( V_52 == NULL ) {
if ( F_24 ( V_54 ,
V_79 ) < 0 )
F_35 ( & V_9 -> V_35 , L_1 ) ;
else if ( F_24 ( V_54 ,
V_80 ) < 0 )
F_35 ( & V_9 -> V_35 , L_2 ) ;
}
}
if ( V_52 != NULL ) {
F_33 ( & V_43 -> V_81 ) ;
F_34 ( & V_9 -> V_35 , V_41 -> V_76 , V_44 , V_82 ) ;
F_12 ( V_9 , 0 ) ;
if ( V_17 & V_73 ) {
if ( F_36 ( F_7 ( V_9 , V_57 )
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
F_35 ( & V_9 -> V_35 ,
L_3 ) ;
V_44 -= ( V_48 <= 8 ) ? 2 :
( V_48 <= 16 ) ? 4 :
8 ;
F_12 ( V_9 , 1 ) ;
return V_44 ;
}
}
if ( F_36 ( F_7 ( V_9 , V_57 )
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
F_35 ( & V_9 -> V_35 , L_4 ) ;
V_44 -= ( V_48 <= 8 ) ? 1 :
( V_48 <= 16 ) ? 2 :
4 ;
}
F_12 ( V_9 , 1 ) ;
}
return V_44 ;
}
static unsigned
F_37 ( struct V_8 * V_9 , struct V_40 * V_41 )
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
if ( F_24 ( V_54 ,
V_79 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_1 ) ;
goto V_86;
}
F_38 ( & V_9 -> V_35 , L_5 ,
V_48 , * V_53 ) ;
F_3 ( * V_53 ++ , V_46 ) ;
}
if ( V_52 != NULL ) {
if ( F_24 ( V_54 ,
V_83 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_6 ) ;
goto V_86;
}
if ( V_45 == 1 && V_53 == NULL &&
( V_17 & V_73 ) ) {
F_12 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_47 ) ;
F_38 ( & V_9 -> V_35 , L_7 ,
V_48 , * ( V_52 - 1 ) ) ;
if ( F_24 ( V_54 ,
V_83 ) < 0 ) {
F_35 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_86;
}
V_45 = 0 ;
} else if ( V_45 == 0 && V_53 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_47 ) ;
F_38 ( & V_9 -> V_35 , L_7 ,
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
if ( F_24 ( V_54 ,
V_79 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_1 ) ;
goto V_86;
}
F_38 ( & V_9 -> V_35 , L_8 ,
V_48 , * V_53 ) ;
F_3 ( * V_53 ++ , V_46 ) ;
}
if ( V_52 != NULL ) {
if ( F_24 ( V_54 ,
V_83 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_6 ) ;
goto V_86;
}
if ( V_45 == 2 && V_53 == NULL &&
( V_17 & V_73 ) ) {
F_12 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_47 ) ;
F_38 ( & V_9 -> V_35 , L_9 ,
V_48 , * ( V_52 - 1 ) ) ;
if ( F_24 ( V_54 ,
V_83 ) < 0 ) {
F_35 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_86;
}
V_45 = 0 ;
} else if ( V_45 == 0 && V_53 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_47 ) ;
F_38 ( & V_9 -> V_35 , L_9 ,
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
if ( F_24 ( V_54 ,
V_79 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_1 ) ;
goto V_86;
}
F_38 ( & V_9 -> V_35 , L_10 ,
V_48 , * V_53 ) ;
F_3 ( * V_53 ++ , V_46 ) ;
}
if ( V_52 != NULL ) {
if ( F_24 ( V_54 ,
V_83 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_6 ) ;
goto V_86;
}
if ( V_45 == 4 && V_53 == NULL &&
( V_17 & V_73 ) ) {
F_12 ( V_9 , 0 ) ;
* V_52 ++ = F_5 ( V_47 ) ;
F_38 ( & V_9 -> V_35 , L_11 ,
V_48 , * ( V_52 - 1 ) ) ;
if ( F_24 ( V_54 ,
V_83 ) < 0 ) {
F_35 ( & V_9 -> V_35 ,
L_6 ) ;
goto V_86;
}
V_45 = 0 ;
} else if ( V_45 == 0 && V_53 == NULL ) {
F_12 ( V_9 , 0 ) ;
}
* V_52 ++ = F_5 ( V_47 ) ;
F_38 ( & V_9 -> V_35 , L_11 ,
V_48 , * ( V_52 - 1 ) ) ;
}
} while ( V_45 >= 4 );
}
if ( V_41 -> V_62 == NULL ) {
if ( F_24 ( V_54 ,
V_79 ) < 0 ) {
F_35 ( & V_9 -> V_35 , L_1 ) ;
} else if ( F_24 ( V_54 ,
V_80 ) < 0 )
F_35 ( & V_9 -> V_35 , L_2 ) ;
F_12 ( V_9 , 0 ) ;
}
V_86:
F_12 ( V_9 , 1 ) ;
return V_44 - V_45 ;
}
static T_1 F_39 ( T_1 V_87 )
{
T_1 div ;
for ( div = 0 ; div < 15 ; div ++ )
if ( V_87 >= ( V_88 >> div ) )
return div ;
return 15 ;
}
static int F_40 ( struct V_8 * V_9 ,
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
V_87 = F_41 ( T_1 , V_87 , V_88 ) ;
div = F_39 ( V_87 ) ;
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
F_42 ( & V_9 -> V_35 , L_12 ,
V_88 >> div ,
( V_9 -> V_96 & V_102 ) ? L_13 : L_14 ,
( V_9 -> V_96 & V_100 ) ? L_15 : L_16 ) ;
return 0 ;
}
static void F_43 ( int V_104 , V_85 V_105 , void * V_106 )
{
struct V_8 * V_9 = V_106 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & ( V_6 -> V_55 [ V_9 -> V_56 ] ) ;
F_44 ( & V_43 -> V_81 ) ;
F_10 ( V_9 , 1 , 0 ) ;
}
static void F_45 ( int V_104 , V_85 V_105 , void * V_106 )
{
struct V_8 * V_9 = V_106 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
V_43 = & ( V_6 -> V_55 [ V_9 -> V_56 ] ) ;
F_44 ( & V_43 -> V_77 ) ;
F_10 ( V_9 , 0 , 0 ) ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_6 = F_2 ( V_2 ) ;
V_43 = V_6 -> V_55 + V_9 -> V_56 ;
if ( F_47 ( V_43 -> V_75 , L_17 ,
F_43 , V_9 ,
& V_43 -> V_74 ) ) {
F_35 ( & V_9 -> V_35 , L_18 ) ;
return - V_107 ;
}
if ( F_47 ( V_43 -> V_69 , L_19 ,
F_45 , V_9 ,
& V_43 -> V_67 ) ) {
F_48 ( V_43 -> V_74 ) ;
V_43 -> V_74 = - 1 ;
F_35 ( & V_9 -> V_35 , L_20 ) ;
return - V_107 ;
}
F_49 ( & V_43 -> V_81 ) ;
F_49 ( & V_43 -> V_77 ) ;
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
int V_108 ;
struct V_5 * V_6 = F_2 ( V_9 -> V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_42 * V_43 ;
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_90 < 4 || V_9 -> V_90 > 32 ) {
F_42 ( & V_9 -> V_35 , L_21 ,
V_9 -> V_90 ) ;
return - V_109 ;
}
V_43 = & V_6 -> V_55 [ V_9 -> V_56 ] ;
if ( ! V_11 ) {
V_11 = F_51 ( sizeof *V_11 , V_110 ) ;
if ( ! V_11 )
return - V_111 ;
V_11 -> V_7 = V_6 -> V_7 + V_9 -> V_56 * 0x14 ;
V_11 -> V_59 = V_6 -> V_59 + V_9 -> V_56 * 0x14 ;
V_11 -> V_13 = 0 ;
V_9 -> V_12 = V_11 ;
F_52 ( & V_11 -> V_112 , & V_26 -> V_11 ) ;
}
if ( V_43 -> V_74 == - 1
|| V_43 -> V_67 == - 1 ) {
V_108 = F_46 ( V_9 ) ;
if ( V_108 < 0 )
return V_108 ;
}
V_108 = F_20 ( V_6 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_40 ( V_9 , NULL ) ;
F_17 ( V_6 ) ;
return V_108 ;
}
static void F_53 ( struct V_8 * V_9 )
{
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_9 -> V_2 ) ;
if ( V_9 -> V_12 ) {
V_11 = V_9 -> V_12 ;
F_54 ( & V_11 -> V_112 ) ;
F_55 ( V_11 ) ;
}
if ( V_9 -> V_56 < V_9 -> V_2 -> V_113 ) {
V_43 = & V_6 -> V_55 [ V_9 -> V_56 ] ;
if ( V_43 -> V_74 != - 1 ) {
F_48 ( V_43 -> V_74 ) ;
V_43 -> V_74 = - 1 ;
}
if ( V_43 -> V_67 != - 1 ) {
F_48 ( V_43 -> V_67 ) ;
V_43 -> V_67 = - 1 ;
}
}
}
static void F_56 ( struct V_5 * V_6 , struct V_114 * V_115 )
{
struct V_8 * V_9 ;
struct V_40 * V_89 = NULL ;
int V_23 = 0 ;
struct V_10 * V_11 ;
struct V_116 * V_117 ;
int V_118 = 0 ;
int V_119 = 0 ;
T_1 V_120 ;
V_9 = V_115 -> V_9 ;
V_11 = V_9 -> V_12 ;
V_117 = V_9 -> V_121 ;
F_12 ( V_9 , 1 ) ;
F_16 (t, &m->transfers, transfer_list) {
if ( V_89 -> V_63 == NULL && V_89 -> V_62 == NULL && V_89 -> V_58 ) {
V_119 = - V_109 ;
break;
}
if ( V_118 || V_89 -> V_87 || V_89 -> V_90 ) {
V_118 = 1 ;
V_119 = F_40 ( V_9 , V_89 ) ;
if ( V_119 < 0 )
break;
if ( ! V_89 -> V_87 && ! V_89 -> V_90 )
V_118 = 0 ;
}
if ( ! V_23 ) {
F_13 ( V_9 , 1 ) ;
V_23 = 1 ;
}
V_120 = F_8 ( V_9 ) ;
V_120 &= ~ V_122 ;
V_120 &= ~ V_73 ;
if ( V_89 -> V_63 == NULL )
V_120 |= V_123 ;
else if ( V_89 -> V_62 == NULL )
V_120 |= V_124 ;
if ( V_117 && V_117 -> V_125 && V_89 -> V_63 == NULL ) {
if ( V_89 -> V_58 > ( ( V_11 -> V_48 + 7 ) >> 3 ) )
V_120 |= V_73 ;
}
F_9 ( V_9 , V_120 ) ;
if ( V_89 -> V_58 ) {
unsigned V_44 ;
if ( V_89 -> V_63 == NULL )
F_3 ( 0 , V_11 -> V_7
+ V_60 ) ;
if ( V_115 -> V_126 || V_89 -> V_58 >= V_127 )
V_44 = F_28 ( V_9 , V_89 ) ;
else
V_44 = F_37 ( V_9 , V_89 ) ;
V_115 -> V_128 += V_44 ;
if ( V_44 != V_89 -> V_58 ) {
V_119 = - V_129 ;
break;
}
}
if ( V_89 -> V_130 )
F_57 ( V_89 -> V_130 ) ;
if ( V_89 -> V_131 ) {
F_13 ( V_9 , 0 ) ;
V_23 = 0 ;
}
}
if ( V_118 ) {
V_118 = 0 ;
V_119 = F_40 ( V_9 , NULL ) ;
}
if ( V_23 )
F_13 ( V_9 , 0 ) ;
F_12 ( V_9 , 0 ) ;
V_115 -> V_119 = V_119 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 ;
struct V_40 * V_89 ;
V_6 = F_2 ( V_2 ) ;
V_115 -> V_128 = 0 ;
V_115 -> V_119 = 0 ;
if ( F_59 ( & V_115 -> V_132 ) )
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
F_42 ( V_6 -> V_35 , L_22 ,
V_89 -> V_87 ,
V_58 ,
V_63 ? L_23 : L_24 ,
V_62 ? L_25 : L_24 ,
V_89 -> V_90 ) ;
return - V_109 ;
}
if ( V_89 -> V_87 && V_89 -> V_87 < ( V_88 >> 15 ) ) {
F_42 ( V_6 -> V_35 , L_26 ,
V_89 -> V_87 ,
V_88 >> 15 ) ;
return - V_109 ;
}
if ( V_115 -> V_126 || V_58 < V_127 )
continue;
if ( V_63 != NULL ) {
V_89 -> V_72 = F_60 ( V_6 -> V_35 , ( void * ) V_63 ,
V_58 , V_78 ) ;
if ( F_61 ( V_6 -> V_35 , V_89 -> V_72 ) ) {
F_42 ( V_6 -> V_35 , L_27 ,
'T' , V_58 ) ;
return - V_109 ;
}
}
if ( V_62 != NULL ) {
V_89 -> V_76 = F_60 ( V_6 -> V_35 , V_62 , V_89 -> V_58 ,
V_82 ) ;
if ( F_61 ( V_6 -> V_35 , V_89 -> V_76 ) ) {
F_42 ( V_6 -> V_35 , L_27 ,
'R' , V_58 ) ;
if ( V_63 != NULL )
F_34 ( V_6 -> V_35 , V_89 -> V_72 ,
V_58 , V_78 ) ;
return - V_109 ;
}
}
}
F_56 ( V_6 , V_115 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int T_4 F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_25 * V_26 = & V_6 -> V_26 ;
int V_108 = 0 ;
V_108 = F_20 ( V_6 ) ;
if ( V_108 < 0 )
return V_108 ;
F_1 ( V_2 , V_33 ,
V_133 ) ;
V_26 -> V_34 = V_133 ;
F_14 ( V_2 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int F_64 ( struct V_134 * V_35 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_2 = F_65 ( V_35 ) ;
V_6 = F_2 ( V_2 ) ;
F_15 ( V_6 ) ;
return 0 ;
}
static int T_5 F_66 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_5 * V_6 ;
struct V_139 * V_140 ;
int V_119 = 0 , V_141 ;
T_1 V_142 = 0 ;
static int V_143 = 1 ;
struct V_144 * V_112 = V_136 -> V_35 . V_145 ;
const struct V_146 * V_147 ;
V_2 = F_67 ( & V_136 -> V_35 , sizeof *V_6 ) ;
if ( V_2 == NULL ) {
F_42 ( & V_136 -> V_35 , L_28 ) ;
return - V_111 ;
}
V_2 -> V_148 = V_100 | V_102 | V_97 ;
V_2 -> V_149 = F_50 ;
V_2 -> V_150 = F_22 ;
V_2 -> V_151 = F_23 ;
V_2 -> V_152 = F_58 ;
V_2 -> V_153 = F_53 ;
V_2 -> V_35 . V_145 = V_112 ;
V_147 = F_68 ( V_154 , & V_136 -> V_35 ) ;
if ( V_147 ) {
T_1 V_155 = 1 ;
V_138 = V_147 -> V_106 ;
F_69 ( V_112 , L_29 , & V_155 ) ;
V_2 -> V_113 = V_155 ;
V_2 -> V_143 = V_143 ++ ;
} else {
V_138 = V_136 -> V_35 . V_156 ;
V_2 -> V_113 = V_138 -> V_155 ;
if ( V_136 -> V_157 != - 1 )
V_2 -> V_143 = V_136 -> V_157 ;
}
V_142 = V_138 -> V_142 ;
F_70 ( & V_136 -> V_35 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_140 = F_71 ( V_136 , V_158 , 0 ) ;
if ( V_140 == NULL ) {
V_119 = - V_159 ;
goto V_160;
}
V_140 -> V_161 += V_142 ;
V_140 -> V_162 += V_142 ;
V_6 -> V_59 = V_140 -> V_161 ;
V_6 -> V_7 = F_72 ( & V_136 -> V_35 , V_140 ) ;
if ( ! V_6 -> V_7 ) {
F_42 ( & V_136 -> V_35 , L_30 ) ;
V_119 = - V_111 ;
goto V_160;
}
V_6 -> V_35 = & V_136 -> V_35 ;
F_73 ( & V_6 -> V_26 . V_11 ) ;
V_6 -> V_55 = F_74 ( V_2 -> V_113 ,
sizeof( struct V_42 ) ,
V_110 ) ;
if ( V_6 -> V_55 == NULL )
goto V_160;
for ( V_141 = 0 ; V_141 < V_2 -> V_113 ; V_141 ++ ) {
char V_163 [ 14 ] ;
struct V_139 * V_164 ;
sprintf ( V_163 , L_31 , V_141 ) ;
V_164 = F_75 ( V_136 , V_165 ,
V_163 ) ;
if ( ! V_164 ) {
F_42 ( & V_136 -> V_35 , L_32 ) ;
V_119 = - V_159 ;
break;
}
V_6 -> V_55 [ V_141 ] . V_74 = - 1 ;
V_6 -> V_55 [ V_141 ] . V_75 = V_164 -> V_161 ;
sprintf ( V_163 , L_33 , V_141 ) ;
V_164 = F_75 ( V_136 , V_165 ,
V_163 ) ;
if ( ! V_164 ) {
F_42 ( & V_136 -> V_35 , L_34 ) ;
V_119 = - V_159 ;
break;
}
V_6 -> V_55 [ V_141 ] . V_67 = - 1 ;
V_6 -> V_55 [ V_141 ] . V_69 = V_164 -> V_161 ;
}
if ( V_119 < 0 )
goto V_166;
F_76 ( & V_136 -> V_35 ) ;
F_77 ( & V_136 -> V_35 , V_167 ) ;
F_78 ( & V_136 -> V_35 ) ;
if ( V_119 || F_63 ( V_6 ) < 0 )
goto V_168;
V_119 = F_79 ( V_2 ) ;
if ( V_119 < 0 )
goto V_169;
return V_119 ;
V_169:
F_80 ( V_2 ) ;
V_168:
F_81 ( & V_136 -> V_35 ) ;
V_166:
F_55 ( V_6 -> V_55 ) ;
V_160:
F_55 ( V_2 ) ;
F_82 ( V_136 , NULL ) ;
return V_119 ;
}
static int T_6 F_83 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_42 * V_55 ;
V_2 = F_65 ( & V_136 -> V_35 ) ;
V_6 = F_2 ( V_2 ) ;
V_55 = V_6 -> V_55 ;
F_17 ( V_6 ) ;
F_81 ( & V_136 -> V_35 ) ;
F_84 ( V_2 ) ;
F_55 ( V_55 ) ;
F_82 ( V_136 , NULL ) ;
return 0 ;
}
static int F_85 ( struct V_134 * V_35 )
{
struct V_1 * V_2 = F_65 ( V_35 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_25 * V_26 = & V_6 -> V_26 ;
struct V_10 * V_11 ;
F_20 ( V_6 ) ;
F_16 (cs, &ctx->cs, node) {
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
