static inline struct V_1 * F_1
( struct V_2 * V_3 )
{
if ( F_2 ( V_4 ) && ( V_3 -> V_5 . V_6 ) ) {
const struct V_7 * V_8 ;
V_8 = F_3 ( V_9 ,
V_3 -> V_5 . V_6 ) ;
return (struct V_1 * ) V_8 -> V_10 ;
}
return (struct V_1 * )
F_4 ( V_3 ) -> V_11 ;
}
static void F_5 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
F_6 ( V_5 , V_15 , F_7 ( V_14 ) ) ;
F_6 ( V_5 , V_16 , F_8 ( V_14 ) ) ;
}
static void F_9 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
F_6 ( V_5 , V_17 , F_7 ( V_14 ) ) ;
F_6 ( V_5 , V_18 , F_8 ( V_14 ) ) ;
}
static void F_10 ( struct V_12 * V_5 , int V_19 )
{
V_5 -> V_20 -> V_21 . V_22 ( & V_5 -> V_20 -> V_21 , V_19 ) ;
V_5 -> V_23 = false ;
}
static void F_11 ( struct V_12 * V_5 )
{
F_12 ( V_5 -> V_5 , V_5 -> V_24 , 1 , V_25 ) ;
}
static void F_13 ( struct V_12 * V_5 )
{
F_12 ( V_5 -> V_5 , V_5 -> V_26 , 1 , V_27 ) ;
}
static int F_14 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
int V_19 ;
if ( ! F_15 ( F_8 ( V_14 ) , V_28 ) ) {
V_19 = - V_29 ;
goto exit;
}
if ( ! F_8 ( V_14 ) ) {
V_19 = - V_29 ;
goto exit;
}
V_19 = F_16 ( V_5 -> V_5 , V_14 , 1 , V_25 ) ;
if ( ! V_19 ) {
V_19 = - V_30 ;
goto exit;
}
V_5 -> V_24 = V_14 ;
V_19 = 0 ;
exit:
return V_19 ;
}
static int F_17 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
int V_19 ;
if ( ! F_15 ( F_8 ( V_14 ) , V_28 ) ) {
V_19 = - V_29 ;
goto exit;
}
if ( ! F_8 ( V_14 ) ) {
V_19 = - V_29 ;
goto exit;
}
V_19 = F_16 ( V_5 -> V_5 , V_14 , 1 , V_27 ) ;
if ( ! V_19 ) {
V_19 = - V_30 ;
goto exit;
}
V_5 -> V_26 = V_14 ;
V_19 = 0 ;
exit:
return V_19 ;
}
static void F_18 ( struct V_12 * V_5 )
{
int V_19 = 0 ;
F_11 ( V_5 ) ;
if ( ! F_19 ( V_5 -> V_24 ) ) {
V_19 = F_14 ( V_5 , F_20 ( V_5 -> V_24 ) ) ;
if ( V_19 ) {
F_10 ( V_5 , V_19 ) ;
return;
}
F_9 ( V_5 , V_5 -> V_24 ) ;
} else {
F_10 ( V_5 , V_19 ) ;
V_5 -> V_23 = true ;
F_21 ( & V_5 -> V_31 ) ;
}
}
static void F_22 ( struct V_12 * V_5 )
{
int V_19 ;
F_13 ( V_5 ) ;
if ( ! F_19 ( V_5 -> V_26 ) ) {
V_19 = F_17 ( V_5 , F_20 ( V_5 -> V_26 ) ) ;
if ( V_19 ) {
F_10 ( V_5 , V_19 ) ;
return;
}
F_5 ( V_5 , V_5 -> V_26 ) ;
}
}
static T_1 F_23 ( int V_32 , void * V_33 )
{
struct V_2 * V_3 = V_33 ;
struct V_12 * V_5 = F_24 ( V_3 ) ;
T_2 V_34 ;
unsigned long V_35 ;
F_25 ( & V_5 -> V_36 , V_35 ) ;
if ( V_32 == V_5 -> V_37 ) {
V_34 = F_26 ( V_5 , V_38 ) ;
if ( V_34 & V_39 )
F_22 ( V_5 ) ;
if ( V_34 & V_40 )
F_18 ( V_5 ) ;
F_6 ( V_5 , V_41 , V_34 ) ;
}
F_27 ( & V_5 -> V_36 , V_35 ) ;
return V_42 ;
}
static void F_28 ( struct V_12 * V_5 ,
T_3 * V_43 , T_3 * V_44 , unsigned int V_45 )
{
void T_4 * V_46 ;
if ( V_44 )
F_29 ( V_5 -> V_47 + F_30 ( 0 ) , V_44 , 0x10 ) ;
if ( V_45 == V_48 )
V_46 = V_5 -> V_47 + F_31 ( 0 ) ;
else if ( V_45 == V_49 )
V_46 = V_5 -> V_47 + F_31 ( 2 ) ;
else
V_46 = V_5 -> V_47 + F_31 ( 4 ) ;
F_29 ( V_46 , V_43 , V_45 ) ;
}
static void F_32 ( struct V_12 * V_5 , unsigned long V_50 )
{
struct V_51 * V_20 = V_5 -> V_20 ;
T_2 V_52 ;
int V_19 ;
unsigned long V_35 ;
V_52 = V_53 ;
if ( V_50 & V_54 )
V_52 |= V_55 ;
if ( ( V_50 & V_56 ) == V_57 )
V_52 |= V_58 ;
else if ( ( V_50 & V_56 ) == V_59 )
V_52 |= V_60 ;
if ( V_5 -> V_61 -> V_45 == V_49 )
V_52 |= V_62 ;
else if ( V_5 -> V_61 -> V_45 == V_48 )
V_52 |= V_63 ;
V_52 |= V_64 ;
V_52 |= V_65
| V_66
| V_67
| V_68
| V_69 ;
F_25 ( & V_5 -> V_36 , V_35 ) ;
F_6 ( V_5 , V_70 ,
V_71 | V_72 ) ;
F_6 ( V_5 , V_73 , 0x00 ) ;
V_19 = F_17 ( V_5 , V_20 -> V_74 ) ;
if ( V_19 )
goto V_75;
V_19 = F_14 ( V_5 , V_20 -> V_76 ) ;
if ( V_19 )
goto V_77;
F_33 ( V_5 , V_78 , V_52 ) ;
F_28 ( V_5 , V_5 -> V_61 -> V_79 , V_20 -> V_80 , V_5 -> V_61 -> V_45 ) ;
F_5 ( V_5 , V_20 -> V_74 ) ;
F_9 ( V_5 , V_20 -> V_76 ) ;
F_6 ( V_5 , V_81 ,
V_82 | V_83 ) ;
F_27 ( & V_5 -> V_36 , V_35 ) ;
return;
V_77:
F_13 ( V_5 ) ;
V_75:
F_10 ( V_5 , V_19 ) ;
F_27 ( & V_5 -> V_36 , V_35 ) ;
}
static void F_34 ( unsigned long V_10 )
{
struct V_12 * V_5 = (struct V_12 * ) V_10 ;
struct V_84 * V_85 , * V_86 ;
struct V_87 * V_88 ;
unsigned long V_35 ;
F_25 ( & V_5 -> V_36 , V_35 ) ;
V_86 = F_35 ( & V_5 -> V_89 ) ;
V_85 = F_36 ( & V_5 -> V_89 ) ;
if ( ! V_85 ) {
V_5 -> V_23 = false ;
F_27 ( & V_5 -> V_36 , V_35 ) ;
return;
}
F_27 ( & V_5 -> V_36 , V_35 ) ;
if ( V_86 )
V_86 -> V_22 ( V_86 , - V_90 ) ;
V_5 -> V_20 = F_37 ( V_85 ) ;
V_5 -> V_61 = F_38 ( V_5 -> V_20 -> V_21 . V_91 ) ;
V_88 = F_39 ( V_5 -> V_20 ) ;
F_32 ( V_5 , V_88 -> V_50 ) ;
}
static int F_40 ( struct V_12 * V_5 ,
struct V_51 * V_20 )
{
unsigned long V_35 ;
int V_19 ;
F_25 ( & V_5 -> V_36 , V_35 ) ;
V_19 = F_41 ( & V_5 -> V_89 , V_20 ) ;
if ( V_5 -> V_23 ) {
F_27 ( & V_5 -> V_36 , V_35 ) ;
goto exit;
}
V_5 -> V_23 = true ;
F_27 ( & V_5 -> V_36 , V_35 ) ;
F_21 ( & V_5 -> V_31 ) ;
exit:
return V_19 ;
}
static int F_42 ( struct V_51 * V_20 , unsigned long V_50 )
{
struct V_92 * V_91 = F_43 ( V_20 ) ;
struct V_93 * V_61 = F_44 ( V_91 ) ;
struct V_87 * V_88 = F_39 ( V_20 ) ;
struct V_12 * V_5 = V_61 -> V_5 ;
if ( ! F_15 ( V_20 -> V_94 , V_28 ) ) {
F_45 ( V_5 -> V_5 , L_1 ) ;
return - V_29 ;
}
V_88 -> V_50 = V_50 ;
return F_40 ( V_5 , V_20 ) ;
}
static int F_46 ( struct V_92 * V_95 ,
const T_3 * V_43 , unsigned int V_45 )
{
struct V_96 * V_91 = F_47 ( V_95 ) ;
struct V_93 * V_61 = F_38 ( V_91 ) ;
if ( V_45 != V_97 &&
V_45 != V_49 &&
V_45 != V_48 )
return - V_29 ;
memcpy ( V_61 -> V_79 , V_43 , V_45 ) ;
V_61 -> V_45 = V_45 ;
return 0 ;
}
static int F_48 ( struct V_51 * V_20 )
{
return F_42 ( V_20 , 0 ) ;
}
static int F_49 ( struct V_51 * V_20 )
{
return F_42 ( V_20 , V_54 ) ;
}
static int F_50 ( struct V_51 * V_20 )
{
return F_42 ( V_20 , V_57 ) ;
}
static int F_51 ( struct V_51 * V_20 )
{
return F_42 ( V_20 , V_54 | V_57 ) ;
}
static int F_52 ( struct V_96 * V_91 )
{
struct V_93 * V_61 = F_38 ( V_91 ) ;
V_61 -> V_5 = V_98 ;
V_91 -> V_99 . V_100 = sizeof( struct V_87 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 )
{
int V_101 , V_102 , V_19 = - V_103 ;
struct V_12 * V_104 ;
struct V_105 * V_5 = & V_3 -> V_5 ;
struct V_106 * V_107 ;
struct V_1 * V_108 ;
if ( V_98 )
return - V_109 ;
V_104 = F_54 ( V_5 , sizeof( * V_104 ) , V_110 ) ;
if ( ! V_104 )
return - V_30 ;
V_107 = F_55 ( V_3 , V_111 , 0 ) ;
V_104 -> V_112 = F_56 ( & V_3 -> V_5 , V_107 ) ;
if ( F_57 ( V_104 -> V_112 ) )
return F_58 ( V_104 -> V_112 ) ;
V_108 = F_1 ( V_3 ) ;
V_104 -> V_113 = F_59 ( V_5 , L_2 ) ;
if ( F_57 ( V_104 -> V_113 ) ) {
F_45 ( V_5 , L_3 ) ;
return - V_114 ;
}
V_19 = F_60 ( V_104 -> V_113 ) ;
if ( V_19 < 0 ) {
F_45 ( V_5 , L_4 , V_19 ) ;
return V_19 ;
}
F_61 ( & V_104 -> V_36 ) ;
V_104 -> V_47 = V_104 -> V_112 + V_108 -> V_115 ;
V_104 -> V_37 = F_62 ( V_3 , 0 ) ;
if ( V_104 -> V_37 < 0 ) {
V_19 = V_104 -> V_37 ;
F_63 ( V_5 , L_5 ) ;
goto V_116;
}
V_19 = F_64 ( V_5 , V_104 -> V_37 , F_23 ,
V_117 , V_3 -> V_118 , V_3 ) ;
if ( V_19 < 0 ) {
F_63 ( V_5 , L_5 ) ;
goto V_116;
}
if ( V_108 -> V_119 ) {
V_104 -> V_120 = F_62 ( V_3 , 1 ) ;
if ( V_104 -> V_120 < 0 ) {
V_19 = V_104 -> V_120 ;
F_63 ( V_5 , L_6 ) ;
goto V_116;
}
V_19 = F_64 ( V_5 , V_104 -> V_120 , F_23 ,
V_117 , V_3 -> V_118 , V_3 ) ;
if ( V_19 < 0 ) {
F_63 ( V_5 , L_6 ) ;
goto V_116;
}
}
V_104 -> V_23 = false ;
V_104 -> V_108 = V_108 ;
V_104 -> V_5 = V_5 ;
F_65 ( V_3 , V_104 ) ;
V_98 = V_104 ;
F_66 ( & V_104 -> V_31 , F_34 , ( unsigned long ) V_104 ) ;
F_67 ( & V_104 -> V_89 , V_121 ) ;
for ( V_101 = 0 ; V_101 < F_68 ( V_122 ) ; V_101 ++ ) {
V_19 = F_69 ( & V_122 [ V_101 ] ) ;
if ( V_19 )
goto V_123;
}
F_70 ( V_5 , L_7 ) ;
return 0 ;
V_123:
F_45 ( V_5 , L_8 , V_122 [ V_101 ] . V_124 , V_19 ) ;
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ )
F_71 ( & V_122 [ V_102 ] ) ;
F_72 ( & V_104 -> V_31 ) ;
V_116:
F_73 ( V_104 -> V_113 ) ;
V_98 = NULL ;
return V_19 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_12 * V_104 = F_24 ( V_3 ) ;
int V_101 ;
if ( ! V_104 )
return - V_103 ;
for ( V_101 = 0 ; V_101 < F_68 ( V_122 ) ; V_101 ++ )
F_71 ( & V_122 [ V_101 ] ) ;
F_72 ( & V_104 -> V_31 ) ;
F_73 ( V_104 -> V_113 ) ;
V_98 = NULL ;
return 0 ;
}
