static inline void T_1 * F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
return V_1 -> V_3 + V_2 ;
}
static inline void
F_2 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_4 )
{
void T_1 * V_5 = F_1 ( V_1 , V_2 ) ;
T_2 V_6 ;
V_6 = F_3 ( V_5 ) ;
V_6 |= V_4 ;
F_4 ( V_6 , V_5 ) ;
}
static inline void
F_5 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_4 )
{
void T_1 * V_5 = F_1 ( V_1 , V_2 ) ;
T_2 V_6 ;
V_6 = F_3 ( V_5 ) ;
V_6 &= ~ V_4 ;
F_4 ( V_6 , V_5 ) ;
}
static int F_6 ( struct V_7 * V_8 , unsigned int V_9 )
{
T_2 V_10 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_2 ;
struct V_1 * V_1 ;
const struct V_13 * V_14 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_14 = V_1 -> V_14 ;
V_10 = F_8 ( V_1 -> V_16 ) ;
if ( V_14 -> V_17 == V_18 ) {
unsigned V_19 = F_9 ( V_10 , V_9 ) ;
unsigned V_20 , V_21 ;
if ( V_19 < 16 ) {
V_20 = V_19 ;
V_21 = 0 ;
} else {
unsigned V_22 ;
V_21 = F_10 ( V_19 ) - 4 ;
V_22 = 1 << V_21 ;
V_19 = ( V_19 + V_22 - 1 ) & - V_22 ;
V_21 = F_10 ( V_19 ) - 4 ;
V_20 = V_19 >> V_21 ;
if ( V_21 > 7 )
return - V_23 ;
}
V_12 = ( ( V_21 & 0x6 ) << 5 ) | ( ( V_21 & 0x1 ) << 4 ) | V_20 ;
} else {
V_11 = F_9 ( V_10 , V_9 ) ;
V_11 = F_11 ( V_11 , 2 ) ;
if ( V_11 > 30 )
return - V_23 ;
if ( V_11 < 4 )
V_11 = 4 ;
V_12 = 0x10 + V_11 / 2 ;
}
V_2 = F_3 ( F_1 ( V_1 , V_24 ) ) ;
V_2 = ( ( V_2 & ~ V_14 -> V_25 ) | V_12 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_24 ) ) ;
return 0 ;
}
static void
F_12 ( struct V_7 * V_8 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_24 ) ) ;
V_2 &= ~ V_26 ;
if ( V_8 -> V_27 & V_28 )
V_2 |= V_29 ;
if ( V_8 -> V_27 & V_30 )
V_2 |= V_31 ;
if ( V_8 -> V_27 & V_32 )
V_2 |= V_33 | V_34 ;
else
V_2 &= ~ ( V_33 | V_34 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_24 ) ) ;
}
static void
F_13 ( struct V_7 * V_8 , unsigned int V_9 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_35 ) ) ;
V_2 &= ~ V_36 ;
if ( F_8 ( V_1 -> V_16 ) == 250000000 &&
V_9 == 50000000 && V_8 -> V_27 & V_28 &&
V_8 -> V_27 & V_30 )
V_2 |= V_37 ;
else
V_2 |= V_38 ;
F_4 ( V_2 , F_1 ( V_1 , V_35 ) ) ;
}
static int
F_14 ( struct V_7 * V_8 , struct V_39 * V_40 )
{
struct V_1 * V_1 ;
unsigned int V_9 = V_8 -> V_41 ;
unsigned int V_42 = V_8 -> V_42 ;
int V_43 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
if ( ( V_40 != NULL ) && V_40 -> V_44 )
V_9 = V_40 -> V_44 ;
if ( ( V_40 != NULL ) && V_40 -> V_42 )
V_42 = V_40 -> V_42 ;
F_12 ( V_8 ) ;
if ( V_1 -> V_14 -> V_45 )
F_13 ( V_8 , V_9 ) ;
V_43 = F_6 ( V_8 , V_9 ) ;
if ( V_43 )
return V_43 ;
if ( V_42 == 16 )
F_2 ( V_1 , V_24 ,
V_46 ) ;
else
F_5 ( V_1 , V_24 ,
V_46 ) ;
return 0 ;
}
static void F_15 ( struct V_7 * V_8 , bool V_47 )
{
struct V_1 * V_1 ;
int V_48 ;
if ( F_16 ( V_8 -> V_49 ) )
V_48 = 0 ;
else
V_48 = V_8 -> V_50 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
F_5 ( V_1 , V_51 , V_52 ) ;
F_2 ( V_1 , V_51 ,
F_17 ( V_48 ) ) ;
if ( ! V_47 )
F_2 ( V_1 , V_51 , 0x1 ) ;
else
F_5 ( V_1 , V_51 , 0x1 ) ;
}
static inline int F_18 ( struct V_1 * V_1 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_55 ) ) )
return 1 ;
F_19 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_20 ( struct V_7 * V_8 ,
const T_3 * * V_56 , T_3 * * V_57 )
{
void T_1 * V_58 , * V_59 , * V_60 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_58 = F_1 ( V_1 , V_61 ) ;
V_59 = F_1 ( V_1 , V_62 ) ;
V_60 = F_1 ( V_1 , V_55 ) ;
F_4 ( 0x0 , V_60 ) ;
if ( V_56 && * V_56 )
F_4 ( * ( * V_56 ) ++ , V_58 ) ;
else
F_4 ( 0 , V_58 ) ;
if ( F_18 ( V_1 ) < 0 ) {
F_21 ( & V_8 -> V_63 , L_1 ) ;
return - 1 ;
}
if ( V_57 && * V_57 )
* ( * V_57 ) ++ = F_3 ( V_59 ) ;
return 1 ;
}
static inline int
F_22 ( struct V_7 * V_8 ,
const T_4 * * V_56 , T_4 * * V_57 )
{
void T_1 * V_58 , * V_59 , * V_60 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_58 = F_1 ( V_1 , V_61 ) ;
V_59 = F_1 ( V_1 , V_62 ) ;
V_60 = F_1 ( V_1 , V_55 ) ;
F_4 ( 0x0 , V_60 ) ;
if ( V_56 && * V_56 )
F_4 ( F_23 ( F_24 ( ( * V_56 ) ++ ) ) , V_58 ) ;
else
F_4 ( 0 , V_58 ) ;
if ( F_18 ( V_1 ) < 0 ) {
F_21 ( & V_8 -> V_63 , L_1 ) ;
return - 1 ;
}
if ( V_57 && * V_57 )
F_25 ( F_26 ( F_3 ( V_59 ) ) , ( * V_57 ) ++ ) ;
return 1 ;
}
static unsigned int
F_27 ( struct V_7 * V_8 , struct V_39 * V_64 )
{
unsigned int V_65 ;
int V_66 ;
struct V_1 * V_1 ;
int V_48 = V_8 -> V_50 ;
V_66 = V_8 -> V_42 ;
V_65 = V_64 -> V_67 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
if ( ( V_1 -> V_68 [ V_48 ] . V_69 ) && ( V_64 -> V_56 ) &&
( V_66 == 8 ) ) {
unsigned int V_70 = V_65 / 4 ;
unsigned int V_71 = V_65 % 4 ;
F_28 ( V_1 -> V_68 [ V_48 ] . V_69 ,
V_64 -> V_56 , V_70 ) ;
if ( V_71 ) {
T_2 * V_72 = ( T_2 * ) V_64 -> V_56 ;
F_29 ( V_1 -> V_68 [ V_48 ] . V_69 ,
& V_72 [ V_70 ] , V_71 ) ;
}
return V_65 ;
}
if ( V_66 == 8 ) {
const T_3 * V_73 = V_64 -> V_56 ;
T_3 * V_74 = V_64 -> V_57 ;
do {
if ( F_20 ( V_8 , & V_73 , & V_74 ) < 0 )
goto V_75;
V_65 -- ;
} while ( V_65 );
} else if ( V_66 == 16 ) {
const T_4 * V_73 = V_64 -> V_56 ;
T_4 * V_74 = V_64 -> V_57 ;
do {
if ( F_22 ( V_8 , & V_73 , & V_74 ) < 0 )
goto V_75;
V_65 -= 2 ;
} while ( V_65 );
}
V_75:
return V_64 -> V_67 - V_65 ;
}
static int F_30 ( struct V_76 * V_15 ,
struct V_7 * V_8 ,
struct V_39 * V_40 )
{
int V_77 = 0 ;
V_77 = F_14 ( V_8 , V_40 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( V_40 -> V_67 )
F_27 ( V_8 , V_40 ) ;
return V_77 ;
}
static int F_31 ( struct V_7 * V_8 )
{
return F_14 ( V_8 , NULL ) ;
}
static int F_32 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_51 , 0x1 ) ;
F_4 ( 0 , F_1 ( V_1 , V_78 ) ) ;
return 0 ;
}
static int F_33 ( struct V_79 * V_80 )
{
const struct V_81 * V_82 ;
const struct V_13 * V_14 ;
struct V_76 * V_15 ;
struct V_1 * V_8 ;
struct V_83 * V_84 ;
unsigned long V_10 ;
int V_77 = 0 ;
struct V_85 * V_86 ;
V_15 = F_34 ( & V_80 -> V_63 , sizeof( * V_8 ) ) ;
if ( V_15 == NULL ) {
F_35 ( & V_80 -> V_63 , L_2 ) ;
return - V_87 ;
}
if ( V_80 -> V_88 != - 1 )
V_15 -> V_89 = V_80 -> V_88 ;
if ( V_80 -> V_63 . V_90 ) {
T_2 V_91 ;
if ( ! F_36 ( V_80 -> V_63 . V_90 , L_3 ,
& V_91 ) )
V_15 -> V_89 = V_91 ;
}
V_15 -> V_92 = V_30 | V_28 | V_32 ;
V_15 -> V_93 = F_15 ;
V_15 -> V_94 = F_30 ;
V_15 -> V_95 = V_96 ;
V_15 -> V_97 = F_31 ;
V_15 -> V_98 = F_37 ( 8 ) | F_37 ( 16 ) ;
V_15 -> V_99 = true ;
V_15 -> V_100 = V_101 ;
F_38 ( V_80 , V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_8 -> V_15 = V_15 ;
V_82 = F_39 ( V_102 , & V_80 -> V_63 ) ;
V_14 = ( V_82 ) ? V_82 -> V_103 : & V_104 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_16 = F_40 ( & V_80 -> V_63 , NULL ) ;
if ( F_41 ( V_8 -> V_16 ) ) {
V_77 = F_42 ( V_8 -> V_16 ) ;
goto V_75;
}
V_77 = F_43 ( V_8 -> V_16 ) ;
if ( V_77 )
goto V_75;
V_10 = F_8 ( V_8 -> V_16 ) ;
if ( F_44 ( V_80 -> V_63 . V_90 ,
L_4 ) )
V_15 -> V_41 = F_45 ( V_14 -> V_105 ,
F_9 ( V_10 , V_14 -> V_106 ) ) ;
else if ( V_14 -> V_106 )
V_15 -> V_41 =
F_9 ( V_10 , V_14 -> V_106 ) ;
else
V_15 -> V_41 = V_14 -> V_105 ;
V_15 -> V_107 = F_9 ( V_10 , V_14 -> V_108 ) ;
V_84 = F_46 ( V_80 , V_109 , 0 ) ;
V_8 -> V_3 = F_47 ( & V_80 -> V_63 , V_84 ) ;
if ( F_41 ( V_8 -> V_3 ) ) {
V_77 = F_42 ( V_8 -> V_3 ) ;
goto V_110;
}
F_48 (pdev->dev.of_node, np) {
T_2 V_48 ;
V_77 = F_36 ( V_86 , L_5 , & V_48 ) ;
if ( V_77 ) {
F_21 ( & V_80 -> V_63 ,
L_6 ,
V_86 -> V_111 , V_77 ) ;
V_77 = 0 ;
continue;
}
V_77 = F_49 ( V_80 -> V_63 . V_90 , V_48 + 1 , V_84 ) ;
if ( V_77 )
continue;
V_8 -> V_68 [ V_48 ] . V_69 = F_50 ( & V_80 -> V_63 ,
V_84 -> V_112 ,
V_113 ) ;
if ( ! V_8 -> V_68 [ V_48 ] . V_69 ) {
V_77 = - V_87 ;
goto V_110;
}
V_8 -> V_68 [ V_48 ] . V_114 = V_113 ;
F_51 ( & V_80 -> V_63 , L_7 , V_48 ) ;
}
F_52 ( & V_80 -> V_63 ) ;
F_53 ( & V_80 -> V_63 ) ;
F_54 ( & V_80 -> V_63 , V_115 ) ;
F_55 ( & V_80 -> V_63 ) ;
V_77 = F_32 ( V_8 ) ;
if ( V_77 < 0 )
goto V_116;
F_56 ( & V_80 -> V_63 ) ;
F_57 ( & V_80 -> V_63 ) ;
V_15 -> V_63 . V_90 = V_80 -> V_63 . V_90 ;
V_77 = F_58 ( V_15 ) ;
if ( V_77 < 0 )
goto V_116;
return V_77 ;
V_116:
F_59 ( & V_80 -> V_63 ) ;
V_110:
F_60 ( V_8 -> V_16 ) ;
V_75:
F_61 ( V_15 ) ;
return V_77 ;
}
static int F_62 ( struct V_79 * V_80 )
{
struct V_76 * V_15 = F_63 ( V_80 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_64 ( & V_80 -> V_63 ) ;
F_60 ( V_8 -> V_16 ) ;
F_65 ( V_15 ) ;
F_59 ( & V_80 -> V_63 ) ;
return 0 ;
}
static int F_66 ( struct V_117 * V_63 )
{
struct V_76 * V_15 = F_67 ( V_63 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_60 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_68 ( struct V_117 * V_63 )
{
struct V_76 * V_15 = F_67 ( V_63 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
return F_43 ( V_8 -> V_16 ) ;
}
