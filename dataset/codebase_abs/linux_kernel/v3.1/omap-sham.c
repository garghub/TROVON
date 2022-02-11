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
if ( F_12 ( V_18 -> V_25 & F_13 ( V_26 ) ) ) {
for ( V_21 = 0 ; V_21 < V_22 / sizeof( T_1 ) ; V_21 ++ )
V_19 [ V_21 ] = F_14 ( V_23 [ V_21 ] ) ;
} else {
for ( V_21 = 0 ; V_21 < V_27 / sizeof( T_1 ) ; V_21 ++ )
V_19 [ V_21 ] = F_15 ( V_23 [ V_21 ] ) ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_28 ) ;
if ( ! F_18 ( V_29 , & V_2 -> V_25 ) ) {
F_5 ( V_2 , V_30 ,
V_31 , V_31 ) ;
if ( F_6 ( V_2 , V_32 ,
V_33 ) )
return - V_13 ;
F_19 ( V_29 , & V_2 -> V_25 ) ;
V_2 -> V_34 = 0 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_2 V_35 ,
int V_36 , int V_37 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
T_1 V_8 = V_35 << 5 , V_7 ;
if ( F_12 ( V_18 -> V_38 ) )
F_3 ( V_2 , V_39 , V_18 -> V_38 ) ;
F_5 ( V_2 , V_30 ,
V_40 | ( V_37 ? V_41 : 0 ) ,
V_40 | V_41 ) ;
if ( V_18 -> V_25 & F_13 ( V_26 ) )
V_8 |= V_42 ;
if ( ! V_18 -> V_38 )
V_8 |= V_43 ;
if ( V_36 )
V_8 |= V_44 ;
V_7 = V_43 | V_44 |
V_42 | V_45 ;
F_5 ( V_2 , V_46 , V_8 , V_7 ) ;
}
static int F_21 ( struct V_1 * V_2 , const T_3 * V_47 ,
T_2 V_35 , int V_36 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_48 , V_49 ;
const T_1 * V_50 = ( const T_1 * ) V_47 ;
F_22 ( V_2 -> V_51 , L_1 ,
V_18 -> V_38 , V_35 , V_36 ) ;
F_20 ( V_2 , V_35 , V_36 , 0 ) ;
V_18 -> V_38 += V_35 ;
if ( F_6 ( V_2 , V_46 , V_52 ) )
return - V_13 ;
if ( V_36 )
F_19 ( V_53 , & V_2 -> V_25 ) ;
F_19 ( V_54 , & V_2 -> V_25 ) ;
V_49 = F_23 ( V_35 , sizeof( T_1 ) ) ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
F_3 ( V_2 , F_24 ( V_48 ) , V_50 [ V_48 ] ) ;
return - V_55 ;
}
static int F_25 ( struct V_1 * V_2 , T_4 V_56 ,
T_2 V_35 , int V_36 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_49 ;
F_22 ( V_2 -> V_51 , L_2 ,
V_18 -> V_38 , V_35 , V_36 ) ;
V_49 = F_23 ( V_35 , sizeof( T_1 ) ) ;
F_26 ( V_2 -> V_57 , V_58 , V_49 ,
1 , V_59 , V_2 -> V_37 ,
V_60 ) ;
F_27 ( V_2 -> V_57 , 0 , V_61 ,
V_56 , 0 , 0 ) ;
F_20 ( V_2 , V_35 , V_36 , 1 ) ;
V_18 -> V_38 += V_35 ;
if ( V_36 )
F_19 ( V_53 , & V_2 -> V_25 ) ;
F_19 ( V_62 , & V_2 -> V_25 ) ;
F_28 ( V_2 -> V_57 ) ;
return - V_55 ;
}
static T_2 F_29 ( struct V_17 * V_18 ,
const T_3 * V_63 , T_2 V_35 )
{
T_2 V_48 = F_30 ( V_35 , V_18 -> V_64 - V_18 -> V_65 ) ;
V_48 = F_30 ( V_48 , V_18 -> V_66 ) ;
if ( V_48 <= 0 )
return 0 ;
memcpy ( V_18 -> V_50 + V_18 -> V_65 , V_63 , V_48 ) ;
V_18 -> V_65 += V_48 ;
return V_48 ;
}
static T_2 F_31 ( struct V_17 * V_18 )
{
T_2 V_48 ;
while ( V_18 -> V_67 ) {
V_48 = F_29 ( V_18 ,
F_32 ( V_18 -> V_67 ) + V_18 -> V_3 ,
V_18 -> V_67 -> V_35 - V_18 -> V_3 ) ;
if ( ! V_48 )
break;
V_18 -> V_3 += V_48 ;
V_18 -> V_66 -= V_48 ;
if ( V_18 -> V_3 == V_18 -> V_67 -> V_35 ) {
V_18 -> V_67 = F_33 ( V_18 -> V_67 ) ;
if ( V_18 -> V_67 )
V_18 -> V_3 = 0 ;
else
V_18 -> V_66 = 0 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
T_2 V_35 , int V_36 )
{
V_18 -> V_56 = F_35 ( V_2 -> V_51 , V_18 -> V_50 , V_18 -> V_64 ,
V_68 ) ;
if ( F_36 ( V_2 -> V_51 , V_18 -> V_56 ) ) {
F_37 ( V_2 -> V_51 , L_3 , V_18 -> V_64 ) ;
return - V_69 ;
}
V_18 -> V_25 &= ~ F_13 ( V_70 ) ;
return F_25 ( V_2 , V_18 -> V_56 , V_35 , V_36 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_36 ;
T_2 V_48 ;
F_31 ( V_18 ) ;
V_36 = ( V_18 -> V_25 & F_13 ( V_71 ) ) && ! V_18 -> V_66 ;
F_22 ( V_2 -> V_51 , L_4 ,
V_18 -> V_65 , V_18 -> V_38 , V_36 ) ;
if ( V_36 || ( V_18 -> V_65 == V_18 -> V_64 && V_18 -> V_66 ) ) {
V_48 = V_18 -> V_65 ;
V_18 -> V_65 = 0 ;
return F_34 ( V_2 , V_18 , V_48 , V_36 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
unsigned int V_35 , V_36 , V_72 ;
struct V_73 * V_67 ;
if ( ! V_18 -> V_66 )
return 0 ;
if ( V_18 -> V_65 || V_18 -> V_3 )
return F_38 ( V_2 ) ;
F_22 ( V_2 -> V_51 , L_5 ,
V_18 -> V_38 , V_18 -> V_65 , V_18 -> V_66 ) ;
V_67 = V_18 -> V_67 ;
if ( ! F_40 ( V_67 ) )
return F_38 ( V_2 ) ;
if ( ! F_41 ( V_67 ) && ! F_42 ( V_67 ) )
return F_38 ( V_2 ) ;
V_35 = F_30 ( V_18 -> V_66 , V_67 -> V_35 ) ;
if ( F_41 ( V_67 ) ) {
if ( ! ( V_18 -> V_25 & F_13 ( V_71 ) ) ) {
V_72 = V_35 & ( V_74 - 1 ) ;
if ( ! V_72 )
V_72 = V_74 ;
V_35 -= V_72 ;
}
}
if ( ! F_43 ( V_2 -> V_51 , V_18 -> V_67 , 1 , V_68 ) ) {
F_37 ( V_2 -> V_51 , L_6 ) ;
return - V_69 ;
}
V_18 -> V_25 |= F_13 ( V_70 ) ;
V_18 -> V_66 -= V_35 ;
V_18 -> V_3 = V_35 ;
V_36 = ( V_18 -> V_25 & F_13 ( V_71 ) ) && ! V_18 -> V_66 ;
return F_25 ( V_2 , F_44 ( V_18 -> V_67 ) , V_35 , V_36 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
int V_65 ;
F_31 ( V_18 ) ;
V_65 = V_18 -> V_65 ;
V_18 -> V_65 = 0 ;
return F_21 ( V_2 , V_18 -> V_50 , V_65 , 1 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_9 ( V_2 -> V_15 ) ;
F_47 ( V_2 -> V_57 ) ;
if ( V_18 -> V_25 & F_13 ( V_70 ) ) {
F_48 ( V_2 -> V_51 , V_18 -> V_67 , 1 , V_68 ) ;
if ( V_18 -> V_67 -> V_35 == V_18 -> V_3 ) {
V_18 -> V_67 = F_33 ( V_18 -> V_67 ) ;
if ( V_18 -> V_67 )
V_18 -> V_3 = 0 ;
}
} else {
F_49 ( V_2 -> V_51 , V_18 -> V_56 , V_18 -> V_64 ,
V_68 ) ;
}
return 0 ;
}
static int F_50 ( struct V_14 * V_15 )
{
struct V_75 * V_76 = F_51 ( V_15 ) ;
struct V_77 * V_78 = F_52 ( V_76 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = NULL , * V_79 ;
F_53 ( & V_80 . V_81 ) ;
if ( ! V_78 -> V_2 ) {
F_54 (tmp, &sham.dev_list, list) {
V_2 = V_79 ;
break;
}
V_78 -> V_2 = V_2 ;
} else {
V_2 = V_78 -> V_2 ;
}
F_55 ( & V_80 . V_81 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_25 = 0 ;
F_22 ( V_2 -> V_51 , L_7 ,
F_56 ( V_76 ) ) ;
if ( F_56 ( V_76 ) == V_22 )
V_18 -> V_25 |= F_13 ( V_26 ) ;
V_18 -> V_65 = 0 ;
V_18 -> V_38 = 0 ;
V_18 -> V_64 = V_82 ;
if ( V_78 -> V_25 & F_13 ( V_83 ) ) {
struct V_84 * V_85 = V_78 -> V_86 ;
memcpy ( V_18 -> V_50 , V_85 -> V_87 , V_74 ) ;
V_18 -> V_65 = V_74 ;
V_18 -> V_25 |= F_13 ( V_83 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_34 ;
F_22 ( V_2 -> V_51 , L_8 ,
V_18 -> V_66 , V_18 -> V_38 , ( V_18 -> V_25 & F_13 ( V_71 ) ) != 0 ) ;
if ( V_18 -> V_25 & F_13 ( V_54 ) )
V_34 = F_45 ( V_2 ) ;
else
V_34 = F_39 ( V_2 ) ;
F_22 ( V_2 -> V_51 , L_9 , V_34 , V_18 -> V_38 ) ;
return V_34 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_34 = 0 , V_88 = 1 ;
if ( V_18 -> V_65 <= 64 )
V_88 = 0 ;
if ( V_88 )
V_34 = F_34 ( V_2 , V_18 , V_18 -> V_65 , 1 ) ;
else
V_34 = F_21 ( V_2 , V_18 -> V_50 , V_18 -> V_65 , 1 ) ;
V_18 -> V_65 = 0 ;
F_22 ( V_2 -> V_51 , L_10 , V_34 ) ;
return V_34 ;
}
static int F_59 ( struct V_14 * V_15 )
{
struct V_77 * V_78 = F_60 ( V_15 -> V_86 . V_76 ) ;
struct V_84 * V_85 = V_78 -> V_86 ;
int V_89 = F_61 ( V_85 -> V_90 ) ;
int V_91 = F_62 ( V_85 -> V_90 ) ;
struct {
struct V_92 V_90 ;
char V_18 [ F_63 ( V_85 -> V_90 ) ] ;
} V_93 ;
V_93 . V_90 . V_76 = V_85 -> V_90 ;
V_93 . V_90 . V_25 = 0 ;
return F_64 ( & V_93 . V_90 ) ? :
F_65 ( & V_93 . V_90 , V_85 -> V_94 , V_89 ) ? :
F_66 ( & V_93 . V_90 , V_15 -> V_24 , V_91 , V_15 -> V_24 ) ;
}
static int F_67 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_34 = 0 ;
if ( V_18 -> V_38 ) {
F_11 ( V_15 ) ;
if ( V_18 -> V_25 & F_13 ( V_83 ) )
V_34 = F_59 ( V_15 ) ;
}
F_22 ( V_2 -> V_51 , L_11 , V_18 -> V_38 , V_18 -> V_65 ) ;
return V_34 ;
}
static void F_68 ( struct V_14 * V_15 , int V_34 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_34 ) {
F_8 ( V_15 , 1 ) ;
if ( F_18 ( V_53 , & V_2 -> V_25 ) )
V_34 = F_67 ( V_15 ) ;
} else {
V_18 -> V_25 |= F_13 ( V_95 ) ;
}
V_2 -> V_25 &= ~ ( F_13 ( V_96 ) | F_13 ( V_53 ) | F_13 ( V_54 ) |
F_13 ( V_97 ) | F_13 ( V_98 ) ) ;
F_69 ( V_2 -> V_28 ) ;
if ( V_15 -> V_86 . V_99 )
V_15 -> V_86 . V_99 ( & V_15 -> V_86 , V_34 ) ;
F_70 ( & V_2 -> V_100 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_101 * V_102 , * V_103 ;
struct V_17 * V_18 ;
unsigned long V_25 ;
int V_34 = 0 , V_104 = 0 ;
F_72 ( & V_2 -> V_81 , V_25 ) ;
if ( V_15 )
V_104 = F_73 ( & V_2 -> V_105 , V_15 ) ;
if ( F_18 ( V_96 , & V_2 -> V_25 ) ) {
F_74 ( & V_2 -> V_81 , V_25 ) ;
return V_104 ;
}
V_103 = F_75 ( & V_2 -> V_105 ) ;
V_102 = F_76 ( & V_2 -> V_105 ) ;
if ( V_102 )
F_19 ( V_96 , & V_2 -> V_25 ) ;
F_74 ( & V_2 -> V_81 , V_25 ) ;
if ( ! V_102 )
return V_104 ;
if ( V_103 )
V_103 -> V_99 ( V_103 , - V_55 ) ;
V_15 = F_77 ( V_102 ) ;
V_2 -> V_15 = V_15 ;
V_18 = F_9 ( V_15 ) ;
F_22 ( V_2 -> V_51 , L_12 ,
V_18 -> V_106 , V_15 -> V_107 ) ;
V_34 = F_16 ( V_2 ) ;
if ( V_34 )
goto V_108;
F_78 ( V_2 -> V_57 , 0 ,
V_109 ,
V_2 -> V_110 + F_24 ( 0 ) , 0 , 16 ) ;
F_79 ( V_2 -> V_57 ,
V_111 ) ;
F_80 ( V_2 -> V_57 ,
V_112 ) ;
if ( V_18 -> V_38 )
F_8 ( V_15 , 0 ) ;
if ( V_18 -> V_106 == V_113 ) {
V_34 = F_57 ( V_2 ) ;
if ( V_34 != - V_55 && ( V_18 -> V_25 & F_13 ( V_71 ) ) )
V_34 = F_58 ( V_2 ) ;
} else if ( V_18 -> V_106 == V_114 ) {
V_34 = F_58 ( V_2 ) ;
}
V_108:
if ( V_34 != - V_55 )
F_68 ( V_15 , V_34 ) ;
F_22 ( V_2 -> V_51 , L_13 , V_34 ) ;
return V_104 ;
}
static int F_81 ( struct V_14 * V_15 , unsigned int V_106 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_77 * V_78 = F_60 ( V_15 -> V_86 . V_76 ) ;
struct V_1 * V_2 = V_78 -> V_2 ;
V_18 -> V_106 = V_106 ;
return F_71 ( V_2 , V_15 ) ;
}
static int F_82 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
if ( ! V_15 -> V_107 )
return 0 ;
V_18 -> V_66 = V_15 -> V_107 ;
V_18 -> V_67 = V_15 -> V_115 ;
V_18 -> V_3 = 0 ;
if ( V_18 -> V_25 & F_13 ( V_71 ) ) {
if ( ( V_18 -> V_38 + V_18 -> V_65 + V_18 -> V_66 ) < 9 ) {
F_31 ( V_18 ) ;
return 0 ;
} else if ( V_18 -> V_65 + V_18 -> V_66 <= V_74 ) {
V_18 -> V_25 |= F_13 ( V_54 ) ;
}
} else if ( V_18 -> V_65 + V_18 -> V_66 < V_18 -> V_64 ) {
F_31 ( V_18 ) ;
return 0 ;
}
return F_81 ( V_15 , V_113 ) ;
}
static int F_83 ( struct V_116 * V_90 , T_1 V_25 ,
const T_3 * V_63 , unsigned int V_117 , T_3 * V_16 )
{
struct {
struct V_92 V_90 ;
char V_18 [ F_63 ( V_90 ) ] ;
} V_93 ;
V_93 . V_90 . V_76 = V_90 ;
V_93 . V_90 . V_25 = V_25 & V_118 ;
return F_84 ( & V_93 . V_90 , V_63 , V_117 , V_16 ) ;
}
static int F_85 ( struct V_14 * V_15 )
{
struct V_77 * V_78 = F_60 ( V_15 -> V_86 . V_76 ) ;
struct V_17 * V_18 = F_9 ( V_15 ) ;
return F_83 ( V_78 -> V_119 , V_15 -> V_86 . V_25 ,
V_18 -> V_50 , V_18 -> V_65 , V_15 -> V_24 ) ;
}
static int F_86 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
V_18 -> V_25 |= F_13 ( V_71 ) ;
if ( V_18 -> V_25 & F_13 ( V_95 ) )
return 0 ;
if ( ( V_18 -> V_38 + V_18 -> V_65 ) < 9 )
return F_85 ( V_15 ) ;
else if ( V_18 -> V_65 )
return F_81 ( V_15 , V_114 ) ;
return F_67 ( V_15 ) ;
}
static int F_87 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
int V_108 , V_120 ;
V_18 -> V_25 |= F_13 ( V_71 ) ;
V_108 = F_82 ( V_15 ) ;
if ( V_108 == - V_55 || V_108 == - V_121 )
return V_108 ;
V_120 = F_86 ( V_15 ) ;
return V_108 ? : V_120 ;
}
static int F_88 ( struct V_14 * V_15 )
{
return F_50 ( V_15 ) ? : F_87 ( V_15 ) ;
}
static int F_89 ( struct V_75 * V_76 , const T_3 * V_122 ,
unsigned int V_123 )
{
struct V_77 * V_78 = F_52 ( V_76 ) ;
struct V_84 * V_85 = V_78 -> V_86 ;
int V_89 = F_61 ( V_85 -> V_90 ) ;
int V_91 = F_62 ( V_85 -> V_90 ) ;
int V_34 , V_21 ;
V_34 = F_90 ( V_78 -> V_119 , V_122 , V_123 ) ;
if ( V_34 )
return V_34 ;
if ( V_123 > V_89 ) {
V_34 = F_83 ( V_85 -> V_90 ,
F_91 ( V_85 -> V_90 ) ,
V_122 , V_123 , V_85 -> V_87 ) ;
if ( V_34 )
return V_34 ;
V_123 = V_91 ;
} else {
memcpy ( V_85 -> V_87 , V_122 , V_123 ) ;
}
memset ( V_85 -> V_87 + V_123 , 0 , V_89 - V_123 ) ;
memcpy ( V_85 -> V_94 , V_85 -> V_87 , V_89 ) ;
for ( V_21 = 0 ; V_21 < V_89 ; V_21 ++ ) {
V_85 -> V_87 [ V_21 ] ^= 0x36 ;
V_85 -> V_94 [ V_21 ] ^= 0x5c ;
}
return V_34 ;
}
static int F_92 ( struct V_124 * V_76 , const char * V_125 )
{
struct V_77 * V_78 = F_60 ( V_76 ) ;
const char * V_126 = F_93 ( V_76 ) ;
V_78 -> V_119 = F_94 ( V_126 , 0 ,
V_127 ) ;
if ( F_95 ( V_78 -> V_119 ) ) {
F_96 ( L_14
L_15 , V_126 ) ;
return F_97 ( V_78 -> V_119 ) ;
}
F_98 ( F_99 ( V_76 ) ,
sizeof( struct V_17 ) + V_82 ) ;
if ( V_125 ) {
struct V_84 * V_85 = V_78 -> V_86 ;
V_78 -> V_25 |= F_13 ( V_83 ) ;
V_85 -> V_90 = F_94 ( V_125 , 0 ,
V_127 ) ;
if ( F_95 ( V_85 -> V_90 ) ) {
F_96 ( L_16
L_15 , V_125 ) ;
F_100 ( V_78 -> V_119 ) ;
return F_97 ( V_85 -> V_90 ) ;
}
}
return 0 ;
}
static int F_101 ( struct V_124 * V_76 )
{
return F_92 ( V_76 , NULL ) ;
}
static int F_102 ( struct V_124 * V_76 )
{
return F_92 ( V_76 , L_17 ) ;
}
static int F_103 ( struct V_124 * V_76 )
{
return F_92 ( V_76 , L_18 ) ;
}
static void F_104 ( struct V_124 * V_76 )
{
struct V_77 * V_78 = F_60 ( V_76 ) ;
F_100 ( V_78 -> V_119 ) ;
V_78 -> V_119 = NULL ;
if ( V_78 -> V_25 & F_13 ( V_83 ) ) {
struct V_84 * V_85 = V_78 -> V_86 ;
F_100 ( V_85 -> V_90 ) ;
}
}
static void F_105 ( unsigned long V_63 )
{
struct V_1 * V_2 = (struct V_1 * ) V_63 ;
int V_34 = 0 ;
if ( ! F_18 ( V_96 , & V_2 -> V_25 ) ) {
F_71 ( V_2 , NULL ) ;
return;
}
if ( F_18 ( V_54 , & V_2 -> V_25 ) ) {
if ( F_106 ( V_98 , & V_2 -> V_25 ) )
goto V_128;
} else if ( F_18 ( V_97 , & V_2 -> V_25 ) ) {
if ( F_106 ( V_62 , & V_2 -> V_25 ) ) {
F_46 ( V_2 ) ;
if ( V_2 -> V_34 ) {
V_34 = V_2 -> V_34 ;
goto V_128;
}
}
if ( F_106 ( V_98 , & V_2 -> V_25 ) ) {
F_107 ( V_97 , & V_2 -> V_25 ) ;
V_34 = F_39 ( V_2 ) ;
if ( V_34 != - V_55 )
goto V_128;
}
}
return;
V_128:
F_22 ( V_2 -> V_51 , L_19 , V_34 ) ;
F_68 ( V_2 -> V_15 , V_34 ) ;
}
static T_5 F_108 ( int V_129 , void * V_130 )
{
struct V_1 * V_2 = V_130 ;
if ( F_109 ( F_18 ( V_53 , & V_2 -> V_25 ) ) )
F_5 ( V_2 , V_46 , 0 , V_45 ) ;
F_5 ( V_2 , V_46 , V_131 ,
V_131 ) ;
F_1 ( V_2 , V_46 ) ;
if ( ! F_18 ( V_96 , & V_2 -> V_25 ) ) {
F_110 ( V_2 -> V_51 , L_20 ) ;
return V_132 ;
}
F_19 ( V_98 , & V_2 -> V_25 ) ;
F_70 ( & V_2 -> V_100 ) ;
return V_132 ;
}
static void F_111 ( int V_133 , T_6 V_134 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
if ( V_134 != V_135 ) {
F_96 ( L_21 , V_134 ) ;
V_2 -> V_34 = - V_136 ;
F_107 ( V_29 , & V_2 -> V_25 ) ;
}
F_19 ( V_97 , & V_2 -> V_25 ) ;
F_70 ( & V_2 -> V_100 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_34 ;
V_2 -> V_57 = - 1 ;
V_34 = F_113 ( V_2 -> V_37 , F_114 ( V_2 -> V_51 ) ,
F_111 , V_2 , & V_2 -> V_57 ) ;
if ( V_34 ) {
F_37 ( V_2 -> V_51 , L_22 ) ;
return V_34 ;
}
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 >= 0 ) {
F_116 ( V_2 -> V_57 ) ;
V_2 -> V_57 = - 1 ;
}
}
static int T_7 F_117 ( struct V_137 * V_138 )
{
struct V_1 * V_2 ;
struct V_139 * V_51 = & V_138 -> V_51 ;
struct V_140 * V_141 ;
int V_34 , V_21 , V_142 ;
V_2 = F_118 ( sizeof( struct V_1 ) , V_143 ) ;
if ( V_2 == NULL ) {
F_37 ( V_51 , L_23 ) ;
V_34 = - V_144 ;
goto V_145;
}
V_2 -> V_51 = V_51 ;
F_119 ( V_138 , V_2 ) ;
F_120 ( & V_2 -> V_146 ) ;
F_121 ( & V_2 -> V_81 ) ;
F_122 ( & V_2 -> V_100 , F_105 , ( unsigned long ) V_2 ) ;
F_123 ( & V_2 -> V_105 , V_147 ) ;
V_2 -> V_129 = - 1 ;
V_141 = F_124 ( V_138 , V_148 , 0 ) ;
if ( ! V_141 ) {
F_37 ( V_51 , L_24 ) ;
V_34 = - V_149 ;
goto V_150;
}
V_2 -> V_110 = V_141 -> V_151 ;
V_141 = F_124 ( V_138 , V_152 , 0 ) ;
if ( ! V_141 ) {
F_37 ( V_51 , L_25 ) ;
V_34 = - V_149 ;
goto V_150;
}
V_2 -> V_37 = V_141 -> V_151 ;
V_2 -> V_129 = F_125 ( V_138 , 0 ) ;
if ( V_2 -> V_129 < 0 ) {
F_37 ( V_51 , L_26 ) ;
V_34 = V_2 -> V_129 ;
goto V_150;
}
V_34 = F_126 ( V_2 -> V_129 , F_108 ,
V_153 , F_114 ( V_51 ) , V_2 ) ;
if ( V_34 ) {
F_37 ( V_51 , L_27 ) ;
goto V_150;
}
V_34 = F_112 ( V_2 ) ;
if ( V_34 )
goto V_154;
V_2 -> V_28 = F_127 ( V_51 , L_28 ) ;
if ( F_95 ( V_2 -> V_28 ) ) {
F_37 ( V_51 , L_29 ) ;
V_34 = F_97 ( V_2 -> V_28 ) ;
goto V_155;
}
V_2 -> V_4 = F_128 ( V_2 -> V_110 , V_156 ) ;
if ( ! V_2 -> V_4 ) {
F_37 ( V_51 , L_30 ) ;
V_34 = - V_144 ;
goto V_157;
}
F_17 ( V_2 -> V_28 ) ;
F_129 ( V_51 , L_31 ,
( F_1 ( V_2 , V_158 ) & V_159 ) >> 4 ,
F_1 ( V_2 , V_158 ) & V_160 ) ;
F_69 ( V_2 -> V_28 ) ;
F_130 ( & V_80 . V_81 ) ;
F_131 ( & V_2 -> V_146 , & V_80 . V_161 ) ;
F_132 ( & V_80 . V_81 ) ;
for ( V_21 = 0 ; V_21 < F_133 ( V_162 ) ; V_21 ++ ) {
V_34 = F_134 ( & V_162 [ V_21 ] ) ;
if ( V_34 )
goto V_163;
}
return 0 ;
V_163:
for ( V_142 = 0 ; V_142 < V_21 ; V_142 ++ )
F_135 ( & V_162 [ V_142 ] ) ;
F_136 ( V_2 -> V_4 ) ;
V_157:
F_137 ( V_2 -> V_28 ) ;
V_155:
F_115 ( V_2 ) ;
V_154:
if ( V_2 -> V_129 >= 0 )
F_138 ( V_2 -> V_129 , V_2 ) ;
V_150:
F_139 ( V_2 ) ;
V_2 = NULL ;
V_145:
F_37 ( V_51 , L_32 ) ;
return V_34 ;
}
static int T_8 F_140 ( struct V_137 * V_138 )
{
static struct V_1 * V_2 ;
int V_21 ;
V_2 = F_141 ( V_138 ) ;
if ( ! V_2 )
return - V_149 ;
F_130 ( & V_80 . V_81 ) ;
F_142 ( & V_2 -> V_146 ) ;
F_132 ( & V_80 . V_81 ) ;
for ( V_21 = 0 ; V_21 < F_133 ( V_162 ) ; V_21 ++ )
F_135 ( & V_162 [ V_21 ] ) ;
F_143 ( & V_2 -> V_100 ) ;
F_136 ( V_2 -> V_4 ) ;
F_137 ( V_2 -> V_28 ) ;
F_115 ( V_2 ) ;
if ( V_2 -> V_129 >= 0 )
F_138 ( V_2 -> V_129 , V_2 ) ;
F_139 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
static int T_9 F_144 ( void )
{
F_145 ( L_33 , L_34 ) ;
if ( ! F_146 () ||
( F_147 () != V_164 &&
F_147 () != V_165 ) ) {
F_96 ( L_35 ) ;
return - V_149 ;
}
return F_148 ( & V_166 ) ;
}
static void T_10 F_149 ( void )
{
F_150 ( & V_166 ) ;
}
