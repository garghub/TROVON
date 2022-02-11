static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_5 , T_1 V_7 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_6 ) ;
V_8 &= ~ V_7 ;
V_8 |= V_5 ;
F_3 ( V_2 , V_6 , V_8 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_10 = V_11 + V_12 ;
while ( ! ( F_1 ( V_2 , V_3 ) & V_9 ) ) {
if ( F_7 ( V_10 ) )
return - V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
T_1 * V_19 = ( T_1 * ) V_18 -> V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 / sizeof( T_1 ) ; V_21 ++ ) {
if ( V_16 )
V_19 [ V_21 ] = F_1 ( V_18 -> V_2 ,
F_10 ( V_21 ) ) ;
else
F_3 ( V_18 -> V_2 ,
F_10 ( V_21 ) , V_19 [ V_21 ] ) ;
}
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
T_1 * V_23 = ( T_1 * ) V_18 -> V_20 ;
T_1 * V_19 = ( T_1 * ) V_15 -> V_24 ;
int V_21 ;
if ( ! V_19 )
return;
if ( F_12 ( V_18 -> V_25 & V_26 ) ) {
for ( V_21 = 0 ; V_21 < V_22 / sizeof( T_1 ) ; V_21 ++ )
V_19 [ V_21 ] = F_13 ( V_23 [ V_21 ] ) ;
} else {
for ( V_21 = 0 ; V_21 < V_27 / sizeof( T_1 ) ; V_21 ++ )
V_19 [ V_21 ] = F_14 ( V_23 [ V_21 ] ) ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_28 ) ;
if ( ! ( V_2 -> V_25 & V_29 ) ) {
F_5 ( V_2 , V_30 ,
V_31 , V_31 ) ;
if ( F_6 ( V_2 , V_32 ,
V_33 ) )
return - V_13 ;
V_2 -> V_25 |= V_29 ;
V_2 -> V_34 = 0 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_35 ,
int V_36 , int V_37 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 = V_35 << 5 , V_7 ;
if ( F_12 ( V_18 -> V_38 ) )
F_3 ( V_2 , V_39 , V_18 -> V_38 ) ;
F_5 ( V_2 , V_30 ,
V_40 | ( V_37 ? V_41 : 0 ) ,
V_40 | V_41 ) ;
if ( V_18 -> V_25 & V_26 )
V_8 |= V_42 ;
if ( ! V_18 -> V_38 )
V_8 |= V_43 ;
if ( V_36 )
V_8 |= V_44 ;
V_7 = V_43 | V_44 |
V_42 | V_45 ;
F_5 ( V_2 , V_46 , V_8 , V_7 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_3 * V_47 ,
T_2 V_35 , int V_36 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_48 , V_49 ;
const T_1 * V_50 = ( const T_1 * ) V_47 ;
F_19 ( V_2 -> V_51 , L_1 ,
V_18 -> V_38 , V_35 , V_36 ) ;
F_17 ( V_2 , V_35 , V_36 , 0 ) ;
V_18 -> V_38 += V_35 ;
if ( F_6 ( V_2 , V_46 , V_52 ) )
return - V_13 ;
if ( V_36 )
V_18 -> V_25 |= V_53 ;
V_49 = F_20 ( V_35 , sizeof( T_1 ) ) ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
F_3 ( V_2 , F_21 ( V_48 ) , V_50 [ V_48 ] ) ;
return - V_54 ;
}
static int F_22 ( struct V_1 * V_2 , T_4 V_55 ,
T_2 V_35 , int V_36 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_49 ;
F_19 ( V_2 -> V_51 , L_2 ,
V_18 -> V_38 , V_35 , V_36 ) ;
V_49 = F_20 ( V_35 , sizeof( T_1 ) ) ;
F_23 ( V_2 -> V_56 , V_57 , V_49 ,
1 , V_58 , V_2 -> V_37 ,
V_59 ) ;
F_24 ( V_2 -> V_56 , 0 , V_60 ,
V_55 , 0 , 0 ) ;
F_17 ( V_2 , V_35 , V_36 , 1 ) ;
V_18 -> V_38 += V_35 ;
if ( V_36 )
V_18 -> V_25 |= V_53 ;
V_2 -> V_25 |= V_61 ;
F_25 ( V_2 -> V_56 ) ;
return - V_54 ;
}
static T_2 F_26 ( struct V_17 * V_18 ,
const T_3 * V_62 , T_2 V_35 )
{
T_2 V_48 = F_27 ( V_35 , V_18 -> V_63 - V_18 -> V_64 ) ;
V_48 = F_27 ( V_48 , V_18 -> V_65 ) ;
if ( V_48 <= 0 )
return 0 ;
memcpy ( V_18 -> V_50 + V_18 -> V_64 , V_62 , V_48 ) ;
V_18 -> V_64 += V_48 ;
return V_48 ;
}
static T_2 F_28 ( struct V_17 * V_18 )
{
T_2 V_48 ;
while ( V_18 -> V_66 ) {
V_48 = F_26 ( V_18 ,
F_29 ( V_18 -> V_66 ) + V_18 -> V_3 ,
V_18 -> V_66 -> V_35 - V_18 -> V_3 ) ;
if ( ! V_48 )
break;
V_18 -> V_3 += V_48 ;
V_18 -> V_65 -= V_48 ;
if ( V_18 -> V_3 == V_18 -> V_66 -> V_35 ) {
V_18 -> V_66 = F_30 ( V_18 -> V_66 ) ;
if ( V_18 -> V_66 )
V_18 -> V_3 = 0 ;
else
V_18 -> V_65 = 0 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_2 V_35 , int V_36 )
{
V_18 -> V_55 = F_32 ( V_2 -> V_51 , V_18 -> V_50 , V_18 -> V_63 ,
V_67 ) ;
if ( F_33 ( V_2 -> V_51 , V_18 -> V_55 ) ) {
F_34 ( V_2 -> V_51 , L_3 , V_18 -> V_63 ) ;
return - V_68 ;
}
V_18 -> V_25 &= ~ V_69 ;
return F_22 ( V_2 , V_18 -> V_55 , V_35 , V_36 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_36 ;
T_2 V_48 ;
F_28 ( V_18 ) ;
V_36 = ( V_18 -> V_25 & V_70 ) && ! V_18 -> V_65 ;
F_19 ( V_2 -> V_51 , L_4 ,
V_18 -> V_64 , V_18 -> V_38 , V_36 ) ;
if ( V_36 || ( V_18 -> V_64 == V_18 -> V_63 && V_18 -> V_65 ) ) {
V_48 = V_18 -> V_64 ;
V_18 -> V_64 = 0 ;
return F_31 ( V_2 , V_18 , V_48 , V_36 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_35 , V_36 , V_71 ;
struct V_72 * V_66 ;
if ( ! V_18 -> V_65 )
return 0 ;
if ( V_18 -> V_64 || V_18 -> V_3 )
return F_35 ( V_2 ) ;
F_19 ( V_2 -> V_51 , L_5 ,
V_18 -> V_38 , V_18 -> V_64 , V_18 -> V_65 ) ;
V_66 = V_18 -> V_66 ;
if ( ! F_37 ( V_66 ) )
return F_35 ( V_2 ) ;
if ( ! F_38 ( V_66 ) && ! F_39 ( V_66 ) )
return F_35 ( V_2 ) ;
V_35 = F_27 ( V_18 -> V_65 , V_66 -> V_35 ) ;
if ( F_38 ( V_66 ) ) {
if ( ! ( V_18 -> V_25 & V_70 ) ) {
V_71 = V_35 & ( V_73 - 1 ) ;
if ( ! V_71 )
V_71 = V_73 ;
V_35 -= V_71 ;
}
}
if ( ! F_40 ( V_2 -> V_51 , V_18 -> V_66 , 1 , V_67 ) ) {
F_34 ( V_2 -> V_51 , L_6 ) ;
return - V_68 ;
}
V_18 -> V_25 |= V_69 ;
V_18 -> V_65 -= V_35 ;
V_18 -> V_3 = V_35 ;
V_36 = ( V_18 -> V_25 & V_70 ) && ! V_18 -> V_65 ;
return F_22 ( V_2 , F_41 ( V_18 -> V_66 ) , V_35 , V_36 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_64 ;
F_28 ( V_18 ) ;
V_64 = V_18 -> V_64 ;
V_18 -> V_64 = 0 ;
return F_18 ( V_2 , V_18 -> V_50 , V_64 , 1 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
F_44 ( V_2 -> V_56 ) ;
if ( V_18 -> V_25 & V_69 ) {
F_45 ( V_2 -> V_51 , V_18 -> V_66 , 1 , V_67 ) ;
if ( V_18 -> V_66 -> V_35 == V_18 -> V_3 ) {
V_18 -> V_66 = F_30 ( V_18 -> V_66 ) ;
if ( V_18 -> V_66 )
V_18 -> V_3 = 0 ;
}
} else {
F_46 ( V_2 -> V_51 , V_18 -> V_55 , V_18 -> V_63 ,
V_67 ) ;
}
return 0 ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_74 * V_75 = F_48 ( V_15 ) ;
struct V_76 * V_77 = F_49 ( V_75 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = NULL , * V_78 ;
F_50 ( & V_79 . V_80 ) ;
if ( ! V_77 -> V_2 ) {
F_51 (tmp, &sham.dev_list, list) {
V_2 = V_78 ;
break;
}
V_77 -> V_2 = V_2 ;
} else {
V_2 = V_77 -> V_2 ;
}
F_52 ( & V_79 . V_80 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_25 = 0 ;
F_19 ( V_2 -> V_51 , L_7 ,
F_53 ( V_75 ) ) ;
if ( F_53 ( V_75 ) == V_22 )
V_18 -> V_25 |= V_26 ;
V_18 -> V_64 = 0 ;
V_18 -> V_38 = 0 ;
V_18 -> V_63 = V_81 ;
if ( V_77 -> V_25 & V_82 ) {
struct V_83 * V_84 = V_77 -> V_85 ;
memcpy ( V_18 -> V_50 , V_84 -> V_86 , V_73 ) ;
V_18 -> V_64 = V_73 ;
V_18 -> V_25 |= V_82 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_34 ;
F_19 ( V_2 -> V_51 , L_8 ,
V_18 -> V_65 , V_18 -> V_38 , ( V_18 -> V_25 & V_70 ) != 0 ) ;
if ( V_18 -> V_25 & V_87 )
V_34 = F_42 ( V_2 ) ;
else
V_34 = F_36 ( V_2 ) ;
F_19 ( V_2 -> V_51 , L_9 , V_34 , V_18 -> V_38 ) ;
return V_34 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_34 = 0 , V_88 = 1 ;
if ( V_18 -> V_64 <= 64 )
V_88 = 0 ;
if ( V_88 )
V_34 = F_31 ( V_2 , V_18 , V_18 -> V_64 , 1 ) ;
else
V_34 = F_18 ( V_2 , V_18 -> V_50 , V_18 -> V_64 , 1 ) ;
V_18 -> V_64 = 0 ;
F_19 ( V_2 -> V_51 , L_10 , V_34 ) ;
return V_34 ;
}
static int F_56 ( struct V_14 * V_15 )
{
struct V_76 * V_77 = F_57 ( V_15 -> V_85 . V_75 ) ;
struct V_83 * V_84 = V_77 -> V_85 ;
int V_89 = F_58 ( V_84 -> V_90 ) ;
int V_91 = F_59 ( V_84 -> V_90 ) ;
struct {
struct V_92 V_90 ;
char V_18 [ F_60 ( V_84 -> V_90 ) ] ;
} V_93 ;
V_93 . V_90 . V_75 = V_84 -> V_90 ;
V_93 . V_90 . V_25 = 0 ;
return F_61 ( & V_93 . V_90 ) ? :
F_62 ( & V_93 . V_90 , V_84 -> V_94 , V_89 ) ? :
F_63 ( & V_93 . V_90 , V_15 -> V_24 , V_91 , V_15 -> V_24 ) ;
}
static int F_64 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_34 = 0 ;
if ( V_18 -> V_38 ) {
F_11 ( V_15 ) ;
if ( V_18 -> V_25 & V_82 )
V_34 = F_56 ( V_15 ) ;
}
F_19 ( V_2 -> V_51 , L_11 , V_18 -> V_38 , V_18 -> V_64 ) ;
return V_34 ;
}
static void F_65 ( struct V_14 * V_15 , int V_34 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_34 ) {
F_8 ( V_18 -> V_2 -> V_15 , 1 ) ;
if ( V_18 -> V_25 & V_53 )
V_34 = F_64 ( V_15 ) ;
} else {
V_18 -> V_25 |= V_95 ;
}
F_66 ( V_2 -> V_28 ) ;
V_2 -> V_25 &= ~ V_96 ;
if ( V_15 -> V_85 . V_97 )
V_15 -> V_85 . V_97 ( & V_15 -> V_85 , V_34 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_98 * V_99 , * V_100 ;
struct V_17 * V_18 ;
struct V_14 * V_101 ;
unsigned long V_25 ;
int V_34 = 0 , V_102 = 0 ;
F_68 ( & V_2 -> V_80 , V_25 ) ;
if ( V_15 )
V_102 = F_69 ( & V_2 -> V_103 , V_15 ) ;
if ( V_2 -> V_25 & V_96 ) {
F_70 ( & V_2 -> V_80 , V_25 ) ;
return V_102 ;
}
V_100 = F_71 ( & V_2 -> V_103 ) ;
V_99 = F_72 ( & V_2 -> V_103 ) ;
if ( V_99 )
V_2 -> V_25 |= V_96 ;
F_70 ( & V_2 -> V_80 , V_25 ) ;
if ( ! V_99 )
return V_102 ;
if ( V_100 )
V_100 -> V_97 ( V_100 , - V_54 ) ;
V_15 = F_73 ( V_99 ) ;
V_101 = V_2 -> V_15 ;
V_2 -> V_15 = V_15 ;
V_18 = F_9 ( V_15 ) ;
F_19 ( V_2 -> V_51 , L_12 ,
V_18 -> V_104 , V_15 -> V_105 ) ;
V_34 = F_15 ( V_2 ) ;
if ( V_34 )
goto V_106;
F_74 ( V_2 -> V_56 , 0 ,
V_107 ,
V_2 -> V_108 + F_21 ( 0 ) , 0 , 16 ) ;
F_75 ( V_2 -> V_56 ,
V_109 ) ;
F_76 ( V_2 -> V_56 ,
V_110 ) ;
if ( V_18 -> V_38 )
F_8 ( V_15 , 0 ) ;
if ( V_18 -> V_104 == V_111 ) {
V_34 = F_54 ( V_2 ) ;
if ( V_34 != - V_54 && ( V_18 -> V_25 & V_70 ) )
V_34 = F_55 ( V_2 ) ;
} else if ( V_18 -> V_104 == V_112 ) {
V_34 = F_55 ( V_2 ) ;
}
V_106:
if ( V_34 != - V_54 ) {
F_65 ( V_15 , V_34 ) ;
F_77 ( & V_2 -> V_113 ) ;
}
F_19 ( V_2 -> V_51 , L_13 , V_34 ) ;
return V_102 ;
}
static int F_78 ( struct V_14 * V_15 , unsigned int V_104 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_76 * V_77 = F_57 ( V_15 -> V_85 . V_75 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
V_18 -> V_104 = V_104 ;
return F_67 ( V_2 , V_15 ) ;
}
static int F_79 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
if ( ! V_15 -> V_105 )
return 0 ;
V_18 -> V_65 = V_15 -> V_105 ;
V_18 -> V_66 = V_15 -> V_114 ;
V_18 -> V_3 = 0 ;
if ( V_18 -> V_25 & V_70 ) {
if ( ( V_18 -> V_38 + V_18 -> V_64 + V_18 -> V_65 ) < 9 ) {
F_28 ( V_18 ) ;
return 0 ;
} else if ( V_18 -> V_64 + V_18 -> V_65 <= V_73 ) {
V_18 -> V_25 |= V_87 ;
}
} else if ( V_18 -> V_64 + V_18 -> V_65 < V_18 -> V_63 ) {
F_28 ( V_18 ) ;
return 0 ;
}
return F_78 ( V_15 , V_111 ) ;
}
static int F_80 ( struct V_115 * V_90 , T_1 V_25 ,
const T_3 * V_62 , unsigned int V_116 , T_3 * V_16 )
{
struct {
struct V_92 V_90 ;
char V_18 [ F_60 ( V_90 ) ] ;
} V_93 ;
V_93 . V_90 . V_75 = V_90 ;
V_93 . V_90 . V_25 = V_25 & V_117 ;
return F_81 ( & V_93 . V_90 , V_62 , V_116 , V_16 ) ;
}
static int F_82 ( struct V_14 * V_15 )
{
struct V_76 * V_77 = F_57 ( V_15 -> V_85 . V_75 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
return F_80 ( V_77 -> V_118 , V_15 -> V_85 . V_25 ,
V_18 -> V_50 , V_18 -> V_64 , V_15 -> V_24 ) ;
}
static int F_83 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
V_18 -> V_25 |= V_70 ;
if ( V_18 -> V_25 & V_95 )
return 0 ;
if ( ( V_18 -> V_38 + V_18 -> V_64 ) < 9 )
return F_82 ( V_15 ) ;
else if ( V_18 -> V_64 )
return F_78 ( V_15 , V_112 ) ;
return F_64 ( V_15 ) ;
}
static int F_84 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_106 , V_119 ;
V_18 -> V_25 |= V_70 ;
V_106 = F_79 ( V_15 ) ;
if ( V_106 == - V_54 || V_106 == - V_120 )
return V_106 ;
V_119 = F_83 ( V_15 ) ;
return V_106 ? : V_119 ;
}
static int F_85 ( struct V_14 * V_15 )
{
return F_47 ( V_15 ) ? : F_84 ( V_15 ) ;
}
static int F_86 ( struct V_74 * V_75 , const T_3 * V_121 ,
unsigned int V_122 )
{
struct V_76 * V_77 = F_49 ( V_75 ) ;
struct V_83 * V_84 = V_77 -> V_85 ;
int V_89 = F_58 ( V_84 -> V_90 ) ;
int V_91 = F_59 ( V_84 -> V_90 ) ;
int V_34 , V_21 ;
V_34 = F_87 ( V_77 -> V_118 , V_121 , V_122 ) ;
if ( V_34 )
return V_34 ;
if ( V_122 > V_89 ) {
V_34 = F_80 ( V_84 -> V_90 ,
F_88 ( V_84 -> V_90 ) ,
V_121 , V_122 , V_84 -> V_86 ) ;
if ( V_34 )
return V_34 ;
V_122 = V_91 ;
} else {
memcpy ( V_84 -> V_86 , V_121 , V_122 ) ;
}
memset ( V_84 -> V_86 + V_122 , 0 , V_89 - V_122 ) ;
memcpy ( V_84 -> V_94 , V_84 -> V_86 , V_89 ) ;
for ( V_21 = 0 ; V_21 < V_89 ; V_21 ++ ) {
V_84 -> V_86 [ V_21 ] ^= 0x36 ;
V_84 -> V_94 [ V_21 ] ^= 0x5c ;
}
return V_34 ;
}
static int F_89 ( struct V_123 * V_75 , const char * V_124 )
{
struct V_76 * V_77 = F_57 ( V_75 ) ;
const char * V_125 = F_90 ( V_75 ) ;
V_77 -> V_118 = F_91 ( V_125 , 0 ,
V_126 ) ;
if ( F_92 ( V_77 -> V_118 ) ) {
F_93 ( L_14
L_15 , V_125 ) ;
return F_94 ( V_77 -> V_118 ) ;
}
F_95 ( F_96 ( V_75 ) ,
sizeof( struct V_17 ) + V_81 ) ;
if ( V_124 ) {
struct V_83 * V_84 = V_77 -> V_85 ;
V_77 -> V_25 |= V_82 ;
V_84 -> V_90 = F_91 ( V_124 , 0 ,
V_126 ) ;
if ( F_92 ( V_84 -> V_90 ) ) {
F_93 ( L_16
L_15 , V_124 ) ;
F_97 ( V_77 -> V_118 ) ;
return F_94 ( V_84 -> V_90 ) ;
}
}
return 0 ;
}
static int F_98 ( struct V_123 * V_75 )
{
return F_89 ( V_75 , NULL ) ;
}
static int F_99 ( struct V_123 * V_75 )
{
return F_89 ( V_75 , L_17 ) ;
}
static int F_100 ( struct V_123 * V_75 )
{
return F_89 ( V_75 , L_18 ) ;
}
static void F_101 ( struct V_123 * V_75 )
{
struct V_76 * V_77 = F_57 ( V_75 ) ;
F_97 ( V_77 -> V_118 ) ;
V_77 -> V_118 = NULL ;
if ( V_77 -> V_25 & V_82 ) {
struct V_83 * V_84 = V_77 -> V_85 ;
F_97 ( V_84 -> V_90 ) ;
}
}
static void F_102 ( unsigned long V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_127 = 0 , V_34 = 0 ;
if ( V_18 -> V_25 & V_128 ) {
V_18 -> V_25 &= ~ V_128 ;
V_127 = 1 ;
}
if ( V_2 -> V_25 & V_61 ) {
V_2 -> V_25 &= ~ V_61 ;
F_43 ( V_2 ) ;
if ( ! V_2 -> V_34 )
V_34 = F_36 ( V_2 ) ;
}
V_34 = V_2 -> V_34 ? : V_34 ;
if ( V_34 != - V_54 && ( V_127 || V_34 ) ) {
F_19 ( V_2 -> V_51 , L_19 , V_34 ) ;
F_65 ( V_15 , V_34 ) ;
F_67 ( V_2 , NULL ) ;
}
}
static void F_103 ( unsigned long V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
F_67 ( V_2 , NULL ) ;
}
static T_5 F_104 ( int V_129 , void * V_130 )
{
struct V_1 * V_2 = V_130 ;
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
if ( ! V_18 ) {
F_34 ( V_2 -> V_51 , L_20 ) ;
return V_131 ;
}
if ( F_105 ( V_18 -> V_25 & V_53 ) )
F_5 ( V_2 , V_46 , 0 , V_45 ) ;
F_5 ( V_2 , V_46 , V_132 ,
V_132 ) ;
F_1 ( V_2 , V_46 ) ;
V_18 -> V_25 |= V_128 ;
V_2 -> V_34 = 0 ;
F_77 ( & V_2 -> V_133 ) ;
return V_131 ;
}
static void F_106 ( int V_134 , T_6 V_135 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
if ( V_135 != V_136 ) {
F_93 ( L_21 , V_135 ) ;
V_2 -> V_34 = - V_137 ;
V_2 -> V_25 &= ~ V_29 ;
}
F_77 ( & V_2 -> V_133 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_34 ;
V_2 -> V_56 = - 1 ;
V_34 = F_108 ( V_2 -> V_37 , F_109 ( V_2 -> V_51 ) ,
F_106 , V_2 , & V_2 -> V_56 ) ;
if ( V_34 ) {
F_34 ( V_2 -> V_51 , L_22 ) ;
return V_34 ;
}
return 0 ;
}
static void F_110 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 >= 0 ) {
F_111 ( V_2 -> V_56 ) ;
V_2 -> V_56 = - 1 ;
}
}
static int T_7 F_112 ( struct V_138 * V_139 )
{
struct V_1 * V_2 ;
struct V_140 * V_51 = & V_139 -> V_51 ;
struct V_141 * V_142 ;
int V_34 , V_21 , V_143 ;
V_2 = F_113 ( sizeof( struct V_1 ) , V_144 ) ;
if ( V_2 == NULL ) {
F_34 ( V_51 , L_23 ) ;
V_34 = - V_145 ;
goto V_146;
}
V_2 -> V_51 = V_51 ;
F_114 ( V_139 , V_2 ) ;
F_115 ( & V_2 -> V_147 ) ;
F_116 ( & V_2 -> V_80 ) ;
F_117 ( & V_2 -> V_133 , F_102 , ( unsigned long ) V_2 ) ;
F_117 ( & V_2 -> V_113 , F_103 , ( unsigned long ) V_2 ) ;
F_118 ( & V_2 -> V_103 , V_148 ) ;
V_2 -> V_129 = - 1 ;
V_142 = F_119 ( V_139 , V_149 , 0 ) ;
if ( ! V_142 ) {
F_34 ( V_51 , L_24 ) ;
V_34 = - V_150 ;
goto V_151;
}
V_2 -> V_108 = V_142 -> V_152 ;
V_142 = F_119 ( V_139 , V_153 , 0 ) ;
if ( ! V_142 ) {
F_34 ( V_51 , L_25 ) ;
V_34 = - V_150 ;
goto V_151;
}
V_2 -> V_37 = V_142 -> V_152 ;
V_2 -> V_129 = F_120 ( V_139 , 0 ) ;
if ( V_2 -> V_129 < 0 ) {
F_34 ( V_51 , L_26 ) ;
V_34 = V_2 -> V_129 ;
goto V_151;
}
V_34 = F_121 ( V_2 -> V_129 , F_104 ,
V_154 , F_109 ( V_51 ) , V_2 ) ;
if ( V_34 ) {
F_34 ( V_51 , L_27 ) ;
goto V_151;
}
V_34 = F_107 ( V_2 ) ;
if ( V_34 )
goto V_155;
V_2 -> V_28 = F_122 ( V_51 , L_28 ) ;
if ( F_92 ( V_2 -> V_28 ) ) {
F_34 ( V_51 , L_29 ) ;
V_34 = F_94 ( V_2 -> V_28 ) ;
goto V_156;
}
V_2 -> V_4 = F_123 ( V_2 -> V_108 , V_157 ) ;
if ( ! V_2 -> V_4 ) {
F_34 ( V_51 , L_30 ) ;
V_34 = - V_145 ;
goto V_158;
}
F_16 ( V_2 -> V_28 ) ;
F_124 ( V_51 , L_31 ,
( F_1 ( V_2 , V_159 ) & V_160 ) >> 4 ,
F_1 ( V_2 , V_159 ) & V_161 ) ;
F_66 ( V_2 -> V_28 ) ;
F_125 ( & V_79 . V_80 ) ;
F_126 ( & V_2 -> V_147 , & V_79 . V_162 ) ;
F_127 ( & V_79 . V_80 ) ;
for ( V_21 = 0 ; V_21 < F_128 ( V_163 ) ; V_21 ++ ) {
V_34 = F_129 ( & V_163 [ V_21 ] ) ;
if ( V_34 )
goto V_164;
}
return 0 ;
V_164:
for ( V_143 = 0 ; V_143 < V_21 ; V_143 ++ )
F_130 ( & V_163 [ V_143 ] ) ;
F_131 ( V_2 -> V_4 ) ;
V_158:
F_132 ( V_2 -> V_28 ) ;
V_156:
F_110 ( V_2 ) ;
V_155:
if ( V_2 -> V_129 >= 0 )
F_133 ( V_2 -> V_129 , V_2 ) ;
V_151:
F_134 ( V_2 ) ;
V_2 = NULL ;
V_146:
F_34 ( V_51 , L_32 ) ;
return V_34 ;
}
static int T_8 F_135 ( struct V_138 * V_139 )
{
static struct V_1 * V_2 ;
int V_21 ;
V_2 = F_136 ( V_139 ) ;
if ( ! V_2 )
return - V_150 ;
F_125 ( & V_79 . V_80 ) ;
F_137 ( & V_2 -> V_147 ) ;
F_127 ( & V_79 . V_80 ) ;
for ( V_21 = 0 ; V_21 < F_128 ( V_163 ) ; V_21 ++ )
F_130 ( & V_163 [ V_21 ] ) ;
F_138 ( & V_2 -> V_133 ) ;
F_138 ( & V_2 -> V_113 ) ;
F_131 ( V_2 -> V_4 ) ;
F_132 ( V_2 -> V_28 ) ;
F_110 ( V_2 ) ;
if ( V_2 -> V_129 >= 0 )
F_133 ( V_2 -> V_129 , V_2 ) ;
F_134 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
static int T_9 F_139 ( void )
{
F_140 ( L_33 , L_34 ) ;
if ( ! F_141 () ||
( F_142 () != V_165 &&
F_142 () != V_166 ) ) {
F_93 ( L_35 ) ;
return - V_150 ;
}
return F_143 ( & V_167 ) ;
}
static void T_10 F_144 ( void )
{
F_145 ( & V_167 ) ;
}
