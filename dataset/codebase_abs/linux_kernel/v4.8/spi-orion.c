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
unsigned int V_16 , V_19 , V_20 , V_21 , V_22 ;
unsigned int V_23 , V_24 , V_25 ;
V_25 = V_9 ;
V_23 = 0 ;
V_24 = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
V_21 = 0x1 << V_20 ;
V_19 = V_10 / V_21 ;
V_19 = F_9 ( V_19 , V_9 ) ;
if ( ( V_19 == 0 ) || ( V_19 > 15 ) )
continue;
V_16 = V_10 / ( V_19 * V_21 ) ;
V_22 = V_9 - V_16 ;
if ( V_22 < V_25 ) {
V_23 = V_19 ;
V_24 = V_20 ;
V_25 = V_22 ;
}
}
if ( ( V_24 == 0 ) && ( V_23 == 0 ) )
return - V_26 ;
V_12 = ( ( V_24 & 0x6 ) << 5 ) |
( ( V_24 & 0x1 ) << 4 ) | V_23 ;
} else {
V_11 = F_9 ( V_10 , V_9 ) ;
V_11 = F_10 ( V_11 , 2 ) ;
if ( V_11 > 30 )
return - V_26 ;
if ( V_11 < 4 )
V_11 = 4 ;
V_12 = 0x10 + V_11 / 2 ;
}
V_2 = F_3 ( F_1 ( V_1 , V_27 ) ) ;
V_2 = ( ( V_2 & ~ V_14 -> V_28 ) | V_12 ) ;
F_4 ( V_2 , F_1 ( V_1 , V_27 ) ) ;
return 0 ;
}
static void
F_11 ( struct V_7 * V_8 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_27 ) ) ;
V_2 &= ~ V_29 ;
if ( V_8 -> V_30 & V_31 )
V_2 |= V_32 ;
if ( V_8 -> V_30 & V_33 )
V_2 |= V_34 ;
F_4 ( V_2 , F_1 ( V_1 , V_27 ) ) ;
}
static void
F_12 ( struct V_7 * V_8 , unsigned int V_9 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_35 ) ) ;
V_2 &= ~ V_36 ;
if ( F_8 ( V_1 -> V_16 ) == 250000000 &&
V_9 == 50000000 && V_8 -> V_30 & V_31 &&
V_8 -> V_30 & V_33 )
V_2 |= V_37 ;
else
V_2 |= V_38 ;
F_4 ( V_2 , F_1 ( V_1 , V_35 ) ) ;
}
static int
F_13 ( struct V_7 * V_8 , struct V_39 * V_40 )
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
F_11 ( V_8 ) ;
if ( V_1 -> V_14 -> V_45 )
F_12 ( V_8 , V_9 ) ;
V_43 = F_6 ( V_8 , V_9 ) ;
if ( V_43 )
return V_43 ;
if ( V_42 == 16 )
F_2 ( V_1 , V_27 ,
V_46 ) ;
else
F_5 ( V_1 , V_27 ,
V_46 ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_8 , bool V_47 )
{
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
F_5 ( V_1 , V_48 , V_49 ) ;
F_2 ( V_1 , V_48 ,
F_15 ( V_8 -> V_50 ) ) ;
if ( ! V_47 )
F_2 ( V_1 , V_48 , 0x1 ) ;
else
F_5 ( V_1 , V_48 , 0x1 ) ;
}
static inline int F_16 ( struct V_1 * V_1 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_53 ) ) )
return 1 ;
F_17 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_18 ( struct V_7 * V_8 ,
const T_3 * * V_54 , T_3 * * V_55 )
{
void T_1 * V_56 , * V_57 , * V_58 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_56 = F_1 ( V_1 , V_59 ) ;
V_57 = F_1 ( V_1 , V_60 ) ;
V_58 = F_1 ( V_1 , V_53 ) ;
F_4 ( 0x0 , V_58 ) ;
if ( V_54 && * V_54 )
F_4 ( * ( * V_54 ) ++ , V_56 ) ;
else
F_4 ( 0 , V_56 ) ;
if ( F_16 ( V_1 ) < 0 ) {
F_19 ( & V_8 -> V_61 , L_1 ) ;
return - 1 ;
}
if ( V_55 && * V_55 )
* ( * V_55 ) ++ = F_3 ( V_57 ) ;
return 1 ;
}
static inline int
F_20 ( struct V_7 * V_8 ,
const T_4 * * V_54 , T_4 * * V_55 )
{
void T_1 * V_56 , * V_57 , * V_58 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_56 = F_1 ( V_1 , V_59 ) ;
V_57 = F_1 ( V_1 , V_60 ) ;
V_58 = F_1 ( V_1 , V_53 ) ;
F_4 ( 0x0 , V_58 ) ;
if ( V_54 && * V_54 )
F_4 ( F_21 ( F_22 ( ( * V_54 ) ++ ) ) , V_56 ) ;
else
F_4 ( 0 , V_56 ) ;
if ( F_16 ( V_1 ) < 0 ) {
F_19 ( & V_8 -> V_61 , L_1 ) ;
return - 1 ;
}
if ( V_55 && * V_55 )
F_23 ( F_24 ( F_3 ( V_57 ) ) , ( * V_55 ) ++ ) ;
return 1 ;
}
static unsigned int
F_25 ( struct V_7 * V_8 , struct V_39 * V_62 )
{
unsigned int V_63 ;
int V_64 ;
struct V_1 * V_1 ;
int V_65 = V_8 -> V_50 ;
V_64 = V_8 -> V_42 ;
V_63 = V_62 -> V_66 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
if ( ( V_1 -> V_67 [ V_65 ] . V_68 ) && ( V_62 -> V_54 ) &&
( V_64 == 8 ) ) {
unsigned int V_69 = V_63 / 4 ;
unsigned int V_70 = V_63 % 4 ;
F_26 ( V_1 -> V_67 [ V_65 ] . V_68 ,
V_62 -> V_54 , V_69 ) ;
if ( V_70 ) {
T_2 * V_71 = ( T_2 * ) V_62 -> V_54 ;
F_27 ( V_1 -> V_67 [ V_65 ] . V_68 ,
& V_71 [ V_69 ] , V_70 ) ;
}
return V_63 ;
}
if ( V_64 == 8 ) {
const T_3 * V_72 = V_62 -> V_54 ;
T_3 * V_73 = V_62 -> V_55 ;
do {
if ( F_18 ( V_8 , & V_72 , & V_73 ) < 0 )
goto V_74;
V_63 -- ;
} while ( V_63 );
} else if ( V_64 == 16 ) {
const T_4 * V_72 = V_62 -> V_54 ;
T_4 * V_73 = V_62 -> V_55 ;
do {
if ( F_20 ( V_8 , & V_72 , & V_73 ) < 0 )
goto V_74;
V_63 -= 2 ;
} while ( V_63 );
}
V_74:
return V_62 -> V_66 - V_63 ;
}
static int F_28 ( struct V_75 * V_15 ,
struct V_7 * V_8 ,
struct V_39 * V_40 )
{
int V_76 = 0 ;
V_76 = F_13 ( V_8 , V_40 ) ;
if ( V_76 < 0 )
return V_76 ;
if ( V_40 -> V_66 )
F_25 ( V_8 , V_40 ) ;
return V_76 ;
}
static int F_29 ( struct V_7 * V_8 )
{
return F_13 ( V_8 , NULL ) ;
}
static int F_30 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_48 , 0x1 ) ;
F_4 ( 0 , F_1 ( V_1 , V_77 ) ) ;
return 0 ;
}
static int F_31 ( struct V_78 * V_79 )
{
const struct V_80 * V_81 ;
const struct V_13 * V_14 ;
struct V_75 * V_15 ;
struct V_1 * V_8 ;
struct V_82 * V_83 ;
unsigned long V_10 ;
int V_76 = 0 ;
struct V_84 * V_85 ;
V_15 = F_32 ( & V_79 -> V_61 , sizeof( * V_8 ) ) ;
if ( V_15 == NULL ) {
F_33 ( & V_79 -> V_61 , L_2 ) ;
return - V_86 ;
}
if ( V_79 -> V_87 != - 1 )
V_15 -> V_88 = V_79 -> V_87 ;
if ( V_79 -> V_61 . V_89 ) {
T_2 V_90 ;
if ( ! F_34 ( V_79 -> V_61 . V_89 , L_3 ,
& V_90 ) )
V_15 -> V_88 = V_90 ;
}
V_15 -> V_91 = V_33 | V_31 ;
V_15 -> V_92 = F_14 ;
V_15 -> V_93 = F_28 ;
V_15 -> V_94 = V_95 ;
V_15 -> V_96 = F_29 ;
V_15 -> V_97 = F_35 ( 8 ) | F_35 ( 16 ) ;
V_15 -> V_98 = true ;
F_36 ( V_79 , V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_8 -> V_15 = V_15 ;
V_81 = F_37 ( V_99 , & V_79 -> V_61 ) ;
V_14 = ( V_81 ) ? V_81 -> V_100 : & V_101 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_16 = F_38 ( & V_79 -> V_61 , NULL ) ;
if ( F_39 ( V_8 -> V_16 ) ) {
V_76 = F_40 ( V_8 -> V_16 ) ;
goto V_74;
}
V_76 = F_41 ( V_8 -> V_16 ) ;
if ( V_76 )
goto V_74;
V_10 = F_8 ( V_8 -> V_16 ) ;
if ( F_42 ( V_79 -> V_61 . V_89 ,
L_4 ) )
V_15 -> V_41 = F_43 ( V_14 -> V_102 ,
F_9 ( V_10 , V_14 -> V_103 ) ) ;
else if ( V_14 -> V_103 )
V_15 -> V_41 =
F_9 ( V_10 , V_14 -> V_103 ) ;
else
V_15 -> V_41 = V_14 -> V_102 ;
V_15 -> V_104 = F_9 ( V_10 , V_14 -> V_105 ) ;
V_83 = F_44 ( V_79 , V_106 , 0 ) ;
V_8 -> V_3 = F_45 ( & V_79 -> V_61 , V_83 ) ;
if ( F_39 ( V_8 -> V_3 ) ) {
V_76 = F_40 ( V_8 -> V_3 ) ;
goto V_107;
}
F_46 (pdev->dev.of_node, np) {
T_2 V_65 ;
V_76 = F_34 ( V_85 , L_5 , & V_65 ) ;
if ( V_76 ) {
F_19 ( & V_79 -> V_61 ,
L_6 ,
V_85 -> V_108 , V_76 ) ;
V_76 = 0 ;
continue;
}
V_76 = F_47 ( V_79 -> V_61 . V_89 , V_65 + 1 , V_83 ) ;
if ( V_76 )
continue;
V_8 -> V_67 [ V_65 ] . V_68 = F_48 ( & V_79 -> V_61 ,
V_83 -> V_109 ,
V_110 ) ;
if ( ! V_8 -> V_67 [ V_65 ] . V_68 ) {
V_76 = - V_86 ;
goto V_107;
}
V_8 -> V_67 [ V_65 ] . V_111 = V_110 ;
F_49 ( & V_79 -> V_61 , L_7 , V_65 ) ;
}
F_50 ( & V_79 -> V_61 ) ;
F_51 ( & V_79 -> V_61 ) ;
F_52 ( & V_79 -> V_61 , V_112 ) ;
F_53 ( & V_79 -> V_61 ) ;
V_76 = F_30 ( V_8 ) ;
if ( V_76 < 0 )
goto V_113;
F_54 ( & V_79 -> V_61 ) ;
F_55 ( & V_79 -> V_61 ) ;
V_15 -> V_61 . V_89 = V_79 -> V_61 . V_89 ;
V_76 = F_56 ( V_15 ) ;
if ( V_76 < 0 )
goto V_113;
return V_76 ;
V_113:
F_57 ( & V_79 -> V_61 ) ;
V_107:
F_58 ( V_8 -> V_16 ) ;
V_74:
F_59 ( V_15 ) ;
return V_76 ;
}
static int F_60 ( struct V_78 * V_79 )
{
struct V_75 * V_15 = F_61 ( V_79 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_62 ( & V_79 -> V_61 ) ;
F_58 ( V_8 -> V_16 ) ;
F_63 ( V_15 ) ;
F_57 ( & V_79 -> V_61 ) ;
return 0 ;
}
static int F_64 ( struct V_114 * V_61 )
{
struct V_75 * V_15 = F_65 ( V_61 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_58 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_66 ( struct V_114 * V_61 )
{
struct V_75 * V_15 = F_65 ( V_61 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
return F_41 ( V_8 -> V_16 ) ;
}
