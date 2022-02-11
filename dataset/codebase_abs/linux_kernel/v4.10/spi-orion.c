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
F_4 ( V_2 , F_1 ( V_1 , V_24 ) ) ;
}
static void
F_13 ( struct V_7 * V_8 , unsigned int V_9 )
{
T_2 V_2 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_2 = F_3 ( F_1 ( V_1 , V_32 ) ) ;
V_2 &= ~ V_33 ;
if ( F_8 ( V_1 -> V_16 ) == 250000000 &&
V_9 == 50000000 && V_8 -> V_27 & V_28 &&
V_8 -> V_27 & V_30 )
V_2 |= V_34 ;
else
V_2 |= V_35 ;
F_4 ( V_2 , F_1 ( V_1 , V_32 ) ) ;
}
static int
F_14 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_1 * V_1 ;
unsigned int V_9 = V_8 -> V_38 ;
unsigned int V_39 = V_8 -> V_39 ;
int V_40 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
if ( ( V_37 != NULL ) && V_37 -> V_41 )
V_9 = V_37 -> V_41 ;
if ( ( V_37 != NULL ) && V_37 -> V_39 )
V_39 = V_37 -> V_39 ;
F_12 ( V_8 ) ;
if ( V_1 -> V_14 -> V_42 )
F_13 ( V_8 , V_9 ) ;
V_40 = F_6 ( V_8 , V_9 ) ;
if ( V_40 )
return V_40 ;
if ( V_39 == 16 )
F_2 ( V_1 , V_24 ,
V_43 ) ;
else
F_5 ( V_1 , V_24 ,
V_43 ) ;
return 0 ;
}
static void F_15 ( struct V_7 * V_8 , bool V_44 )
{
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
F_5 ( V_1 , V_45 , V_46 ) ;
F_2 ( V_1 , V_45 ,
F_16 ( V_8 -> V_47 ) ) ;
if ( ! V_44 )
F_2 ( V_1 , V_45 , 0x1 ) ;
else
F_5 ( V_1 , V_45 , 0x1 ) ;
}
static inline int F_17 ( struct V_1 * V_1 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
if ( F_3 ( F_1 ( V_1 , V_50 ) ) )
return 1 ;
F_18 ( 1 ) ;
}
return - 1 ;
}
static inline int
F_19 ( struct V_7 * V_8 ,
const T_3 * * V_51 , T_3 * * V_52 )
{
void T_1 * V_53 , * V_54 , * V_55 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_53 = F_1 ( V_1 , V_56 ) ;
V_54 = F_1 ( V_1 , V_57 ) ;
V_55 = F_1 ( V_1 , V_50 ) ;
F_4 ( 0x0 , V_55 ) ;
if ( V_51 && * V_51 )
F_4 ( * ( * V_51 ) ++ , V_53 ) ;
else
F_4 ( 0 , V_53 ) ;
if ( F_17 ( V_1 ) < 0 ) {
F_20 ( & V_8 -> V_58 , L_1 ) ;
return - 1 ;
}
if ( V_52 && * V_52 )
* ( * V_52 ) ++ = F_3 ( V_54 ) ;
return 1 ;
}
static inline int
F_21 ( struct V_7 * V_8 ,
const T_4 * * V_51 , T_4 * * V_52 )
{
void T_1 * V_53 , * V_54 , * V_55 ;
struct V_1 * V_1 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
V_53 = F_1 ( V_1 , V_56 ) ;
V_54 = F_1 ( V_1 , V_57 ) ;
V_55 = F_1 ( V_1 , V_50 ) ;
F_4 ( 0x0 , V_55 ) ;
if ( V_51 && * V_51 )
F_4 ( F_22 ( F_23 ( ( * V_51 ) ++ ) ) , V_53 ) ;
else
F_4 ( 0 , V_53 ) ;
if ( F_17 ( V_1 ) < 0 ) {
F_20 ( & V_8 -> V_58 , L_1 ) ;
return - 1 ;
}
if ( V_52 && * V_52 )
F_24 ( F_25 ( F_3 ( V_54 ) ) , ( * V_52 ) ++ ) ;
return 1 ;
}
static unsigned int
F_26 ( struct V_7 * V_8 , struct V_36 * V_59 )
{
unsigned int V_60 ;
int V_61 ;
struct V_1 * V_1 ;
int V_62 = V_8 -> V_47 ;
V_61 = V_8 -> V_39 ;
V_60 = V_59 -> V_63 ;
V_1 = F_7 ( V_8 -> V_15 ) ;
if ( ( V_1 -> V_64 [ V_62 ] . V_65 ) && ( V_59 -> V_51 ) &&
( V_61 == 8 ) ) {
unsigned int V_66 = V_60 / 4 ;
unsigned int V_67 = V_60 % 4 ;
F_27 ( V_1 -> V_64 [ V_62 ] . V_65 ,
V_59 -> V_51 , V_66 ) ;
if ( V_67 ) {
T_2 * V_68 = ( T_2 * ) V_59 -> V_51 ;
F_28 ( V_1 -> V_64 [ V_62 ] . V_65 ,
& V_68 [ V_66 ] , V_67 ) ;
}
return V_60 ;
}
if ( V_61 == 8 ) {
const T_3 * V_69 = V_59 -> V_51 ;
T_3 * V_70 = V_59 -> V_52 ;
do {
if ( F_19 ( V_8 , & V_69 , & V_70 ) < 0 )
goto V_71;
V_60 -- ;
} while ( V_60 );
} else if ( V_61 == 16 ) {
const T_4 * V_69 = V_59 -> V_51 ;
T_4 * V_70 = V_59 -> V_52 ;
do {
if ( F_21 ( V_8 , & V_69 , & V_70 ) < 0 )
goto V_71;
V_60 -= 2 ;
} while ( V_60 );
}
V_71:
return V_59 -> V_63 - V_60 ;
}
static int F_29 ( struct V_72 * V_15 ,
struct V_7 * V_8 ,
struct V_36 * V_37 )
{
int V_73 = 0 ;
V_73 = F_14 ( V_8 , V_37 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_37 -> V_63 )
F_26 ( V_8 , V_37 ) ;
return V_73 ;
}
static int F_30 ( struct V_7 * V_8 )
{
return F_14 ( V_8 , NULL ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_45 , 0x1 ) ;
F_4 ( 0 , F_1 ( V_1 , V_74 ) ) ;
return 0 ;
}
static int F_32 ( struct V_75 * V_76 )
{
const struct V_77 * V_78 ;
const struct V_13 * V_14 ;
struct V_72 * V_15 ;
struct V_1 * V_8 ;
struct V_79 * V_80 ;
unsigned long V_10 ;
int V_73 = 0 ;
struct V_81 * V_82 ;
V_15 = F_33 ( & V_76 -> V_58 , sizeof( * V_8 ) ) ;
if ( V_15 == NULL ) {
F_34 ( & V_76 -> V_58 , L_2 ) ;
return - V_83 ;
}
if ( V_76 -> V_84 != - 1 )
V_15 -> V_85 = V_76 -> V_84 ;
if ( V_76 -> V_58 . V_86 ) {
T_2 V_87 ;
if ( ! F_35 ( V_76 -> V_58 . V_86 , L_3 ,
& V_87 ) )
V_15 -> V_85 = V_87 ;
}
V_15 -> V_88 = V_30 | V_28 ;
V_15 -> V_89 = F_15 ;
V_15 -> V_90 = F_29 ;
V_15 -> V_91 = V_92 ;
V_15 -> V_93 = F_30 ;
V_15 -> V_94 = F_36 ( 8 ) | F_36 ( 16 ) ;
V_15 -> V_95 = true ;
F_37 ( V_76 , V_15 ) ;
V_8 = F_7 ( V_15 ) ;
V_8 -> V_15 = V_15 ;
V_78 = F_38 ( V_96 , & V_76 -> V_58 ) ;
V_14 = ( V_78 ) ? V_78 -> V_97 : & V_98 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_16 = F_39 ( & V_76 -> V_58 , NULL ) ;
if ( F_40 ( V_8 -> V_16 ) ) {
V_73 = F_41 ( V_8 -> V_16 ) ;
goto V_71;
}
V_73 = F_42 ( V_8 -> V_16 ) ;
if ( V_73 )
goto V_71;
V_10 = F_8 ( V_8 -> V_16 ) ;
if ( F_43 ( V_76 -> V_58 . V_86 ,
L_4 ) )
V_15 -> V_38 = F_44 ( V_14 -> V_99 ,
F_9 ( V_10 , V_14 -> V_100 ) ) ;
else if ( V_14 -> V_100 )
V_15 -> V_38 =
F_9 ( V_10 , V_14 -> V_100 ) ;
else
V_15 -> V_38 = V_14 -> V_99 ;
V_15 -> V_101 = F_9 ( V_10 , V_14 -> V_102 ) ;
V_80 = F_45 ( V_76 , V_103 , 0 ) ;
V_8 -> V_3 = F_46 ( & V_76 -> V_58 , V_80 ) ;
if ( F_40 ( V_8 -> V_3 ) ) {
V_73 = F_41 ( V_8 -> V_3 ) ;
goto V_104;
}
F_47 (pdev->dev.of_node, np) {
T_2 V_62 ;
V_73 = F_35 ( V_82 , L_5 , & V_62 ) ;
if ( V_73 ) {
F_20 ( & V_76 -> V_58 ,
L_6 ,
V_82 -> V_105 , V_73 ) ;
V_73 = 0 ;
continue;
}
V_73 = F_48 ( V_76 -> V_58 . V_86 , V_62 + 1 , V_80 ) ;
if ( V_73 )
continue;
V_8 -> V_64 [ V_62 ] . V_65 = F_49 ( & V_76 -> V_58 ,
V_80 -> V_106 ,
V_107 ) ;
if ( ! V_8 -> V_64 [ V_62 ] . V_65 ) {
V_73 = - V_83 ;
goto V_104;
}
V_8 -> V_64 [ V_62 ] . V_108 = V_107 ;
F_50 ( & V_76 -> V_58 , L_7 , V_62 ) ;
}
F_51 ( & V_76 -> V_58 ) ;
F_52 ( & V_76 -> V_58 ) ;
F_53 ( & V_76 -> V_58 , V_109 ) ;
F_54 ( & V_76 -> V_58 ) ;
V_73 = F_31 ( V_8 ) ;
if ( V_73 < 0 )
goto V_110;
F_55 ( & V_76 -> V_58 ) ;
F_56 ( & V_76 -> V_58 ) ;
V_15 -> V_58 . V_86 = V_76 -> V_58 . V_86 ;
V_73 = F_57 ( V_15 ) ;
if ( V_73 < 0 )
goto V_110;
return V_73 ;
V_110:
F_58 ( & V_76 -> V_58 ) ;
V_104:
F_59 ( V_8 -> V_16 ) ;
V_71:
F_60 ( V_15 ) ;
return V_73 ;
}
static int F_61 ( struct V_75 * V_76 )
{
struct V_72 * V_15 = F_62 ( V_76 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_63 ( & V_76 -> V_58 ) ;
F_59 ( V_8 -> V_16 ) ;
F_64 ( V_15 ) ;
F_58 ( & V_76 -> V_58 ) ;
return 0 ;
}
static int F_65 ( struct V_111 * V_58 )
{
struct V_72 * V_15 = F_66 ( V_58 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
F_59 ( V_8 -> V_16 ) ;
return 0 ;
}
static int F_67 ( struct V_111 * V_58 )
{
struct V_72 * V_15 = F_66 ( V_58 ) ;
struct V_1 * V_8 = F_7 ( V_15 ) ;
return F_42 ( V_8 -> V_16 ) ;
}
