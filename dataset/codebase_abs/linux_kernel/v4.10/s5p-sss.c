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
static void F_10 ( struct V_12 * V_5 , struct V_13 * * V_14 )
{
int V_19 ;
if ( ! * V_14 )
return;
V_19 = F_11 ( V_5 -> V_20 -> V_21 , V_22 ) ;
F_12 ( ( unsigned long ) F_13 ( * V_14 ) , F_14 ( V_19 ) ) ;
F_15 ( * V_14 ) ;
* V_14 = NULL ;
}
static void F_16 ( void * V_23 , struct V_13 * V_14 ,
unsigned int V_21 , int V_24 )
{
struct V_25 V_26 ;
if ( ! V_21 )
return;
F_17 ( & V_26 , V_14 ) ;
F_18 ( V_23 , & V_26 , V_21 , V_24 ) ;
F_19 ( & V_26 , V_24 , 0 ) ;
}
static void F_20 ( struct V_12 * V_5 , int V_27 )
{
if ( V_5 -> V_28 ) {
F_21 ( V_5 -> V_5 ,
L_1 ,
V_5 -> V_20 -> V_21 ) ;
F_16 ( F_13 ( V_5 -> V_28 ) , V_5 -> V_20 -> V_29 ,
V_5 -> V_20 -> V_21 , 1 ) ;
}
F_10 ( V_5 , & V_5 -> V_30 ) ;
F_10 ( V_5 , & V_5 -> V_28 ) ;
V_5 -> V_20 -> V_31 . V_32 ( & V_5 -> V_20 -> V_31 , V_27 ) ;
V_5 -> V_33 = false ;
}
static void F_22 ( struct V_12 * V_5 )
{
F_23 ( V_5 -> V_5 , V_5 -> V_34 , 1 , V_35 ) ;
}
static void F_24 ( struct V_12 * V_5 )
{
F_23 ( V_5 -> V_5 , V_5 -> V_36 , 1 , V_37 ) ;
}
static int F_25 ( struct V_12 * V_5 , struct V_13 * V_38 ,
struct V_13 * * V_29 )
{
void * V_39 ;
int V_19 ;
* V_29 = F_26 ( sizeof( * * V_29 ) , V_40 ) ;
if ( ! * V_29 )
return - V_41 ;
V_19 = F_11 ( V_5 -> V_20 -> V_21 , V_22 ) ;
V_39 = ( void * ) F_27 ( V_40 , F_14 ( V_19 ) ) ;
if ( ! V_39 ) {
F_15 ( * V_29 ) ;
* V_29 = NULL ;
return - V_41 ;
}
F_16 ( V_39 , V_38 , V_5 -> V_20 -> V_21 , 0 ) ;
F_28 ( * V_29 , 1 ) ;
F_29 ( * V_29 , V_39 , V_19 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
int V_27 ;
if ( ! V_14 -> V_42 ) {
V_27 = - V_43 ;
goto exit;
}
V_27 = F_31 ( V_5 -> V_5 , V_14 , 1 , V_35 ) ;
if ( ! V_27 ) {
V_27 = - V_41 ;
goto exit;
}
V_5 -> V_34 = V_14 ;
V_27 = 0 ;
exit:
return V_27 ;
}
static int F_32 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
int V_27 ;
if ( ! V_14 -> V_42 ) {
V_27 = - V_43 ;
goto exit;
}
V_27 = F_31 ( V_5 -> V_5 , V_14 , 1 , V_37 ) ;
if ( ! V_27 ) {
V_27 = - V_41 ;
goto exit;
}
V_5 -> V_36 = V_14 ;
V_27 = 0 ;
exit:
return V_27 ;
}
static bool F_33 ( struct V_12 * V_5 )
{
int V_27 = 0 ;
bool V_44 = false ;
F_22 ( V_5 ) ;
if ( ! F_34 ( V_5 -> V_34 ) ) {
V_27 = F_30 ( V_5 , F_35 ( V_5 -> V_34 ) ) ;
if ( V_27 )
F_20 ( V_5 , V_27 ) ;
else
V_44 = true ;
} else {
F_20 ( V_5 , V_27 ) ;
V_5 -> V_33 = true ;
F_36 ( & V_5 -> V_45 ) ;
}
return V_44 ;
}
static bool F_37 ( struct V_12 * V_5 )
{
int V_27 ;
bool V_44 = false ;
F_24 ( V_5 ) ;
if ( ! F_34 ( V_5 -> V_36 ) ) {
V_27 = F_32 ( V_5 , F_35 ( V_5 -> V_36 ) ) ;
if ( V_27 )
F_20 ( V_5 , V_27 ) ;
else
V_44 = true ;
}
return V_44 ;
}
static T_1 F_38 ( int V_46 , void * V_47 )
{
struct V_2 * V_3 = V_47 ;
struct V_12 * V_5 = F_39 ( V_3 ) ;
bool V_48 = false ;
bool V_49 = false ;
unsigned long V_50 ;
T_2 V_51 ;
F_40 ( & V_5 -> V_52 , V_50 ) ;
V_51 = F_41 ( V_5 , V_53 ) ;
if ( V_51 & V_54 )
V_49 = F_37 ( V_5 ) ;
if ( V_51 & V_55 )
V_48 = F_33 ( V_5 ) ;
F_6 ( V_5 , V_56 , V_51 ) ;
if ( V_48 )
F_9 ( V_5 , V_5 -> V_34 ) ;
if ( V_49 )
F_5 ( V_5 , V_5 -> V_36 ) ;
F_42 ( & V_5 -> V_52 , V_50 ) ;
return V_57 ;
}
static void F_43 ( struct V_12 * V_5 ,
T_3 * V_58 , T_3 * V_59 , unsigned int V_60 )
{
void T_4 * V_61 ;
if ( V_59 )
F_44 ( V_5 -> V_62 + F_45 ( 0 ) , V_59 , 0x10 ) ;
if ( V_60 == V_63 )
V_61 = V_5 -> V_62 + F_46 ( 0 ) ;
else if ( V_60 == V_64 )
V_61 = V_5 -> V_62 + F_46 ( 2 ) ;
else
V_61 = V_5 -> V_62 + F_46 ( 4 ) ;
F_44 ( V_61 , V_58 , V_60 ) ;
}
static bool F_47 ( struct V_13 * V_14 )
{
while ( V_14 ) {
if ( ! F_48 ( V_14 -> V_42 , V_22 ) )
return false ;
V_14 = F_35 ( V_14 ) ;
}
return true ;
}
static int F_49 ( struct V_12 * V_5 ,
struct V_65 * V_20 )
{
struct V_13 * V_14 ;
int V_27 ;
V_5 -> V_30 = NULL ;
V_14 = V_20 -> V_38 ;
if ( ! F_47 ( V_14 ) ) {
F_21 ( V_5 -> V_5 ,
L_2 ) ;
V_27 = F_25 ( V_5 , V_14 , & V_5 -> V_30 ) ;
if ( V_27 )
return V_27 ;
V_14 = V_5 -> V_30 ;
}
V_27 = F_32 ( V_5 , V_14 ) ;
if ( V_27 ) {
F_10 ( V_5 , & V_5 -> V_30 ) ;
return V_27 ;
}
return 0 ;
}
static int F_50 ( struct V_12 * V_5 ,
struct V_65 * V_20 )
{
struct V_13 * V_14 ;
int V_27 ;
V_5 -> V_28 = NULL ;
V_14 = V_20 -> V_29 ;
if ( ! F_47 ( V_14 ) ) {
F_21 ( V_5 -> V_5 ,
L_3 ) ;
V_27 = F_25 ( V_5 , V_14 , & V_5 -> V_28 ) ;
if ( V_27 )
return V_27 ;
V_14 = V_5 -> V_28 ;
}
V_27 = F_30 ( V_5 , V_14 ) ;
if ( V_27 ) {
F_10 ( V_5 , & V_5 -> V_28 ) ;
return V_27 ;
}
return 0 ;
}
static void F_51 ( struct V_12 * V_5 , unsigned long V_66 )
{
struct V_65 * V_20 = V_5 -> V_20 ;
T_2 V_67 ;
unsigned long V_50 ;
int V_27 ;
V_67 = V_68 ;
if ( V_66 & V_69 )
V_67 |= V_70 ;
if ( ( V_66 & V_71 ) == V_72 )
V_67 |= V_73 ;
else if ( ( V_66 & V_71 ) == V_74 )
V_67 |= V_75 ;
if ( V_5 -> V_76 -> V_60 == V_64 )
V_67 |= V_77 ;
else if ( V_5 -> V_76 -> V_60 == V_63 )
V_67 |= V_78 ;
V_67 |= V_79 ;
V_67 |= V_80
| V_81
| V_82
| V_83
| V_84 ;
F_40 ( & V_5 -> V_52 , V_50 ) ;
F_6 ( V_5 , V_85 ,
V_86 | V_87 ) ;
F_6 ( V_5 , V_88 , 0x00 ) ;
V_27 = F_49 ( V_5 , V_20 ) ;
if ( V_27 )
goto V_89;
V_27 = F_50 ( V_5 , V_20 ) ;
if ( V_27 )
goto V_90;
F_52 ( V_5 , V_91 , V_67 ) ;
F_43 ( V_5 , V_5 -> V_76 -> V_92 , V_20 -> V_93 , V_5 -> V_76 -> V_60 ) ;
F_5 ( V_5 , V_5 -> V_36 ) ;
F_9 ( V_5 , V_5 -> V_34 ) ;
F_6 ( V_5 , V_94 ,
V_95 | V_96 ) ;
F_42 ( & V_5 -> V_52 , V_50 ) ;
return;
V_90:
F_24 ( V_5 ) ;
V_89:
F_20 ( V_5 , V_27 ) ;
F_42 ( & V_5 -> V_52 , V_50 ) ;
}
static void F_53 ( unsigned long V_10 )
{
struct V_12 * V_5 = (struct V_12 * ) V_10 ;
struct V_97 * V_98 , * V_99 ;
struct V_100 * V_101 ;
unsigned long V_50 ;
F_40 ( & V_5 -> V_52 , V_50 ) ;
V_99 = F_54 ( & V_5 -> V_102 ) ;
V_98 = F_55 ( & V_5 -> V_102 ) ;
if ( ! V_98 ) {
V_5 -> V_33 = false ;
F_42 ( & V_5 -> V_52 , V_50 ) ;
return;
}
F_42 ( & V_5 -> V_52 , V_50 ) ;
if ( V_99 )
V_99 -> V_32 ( V_99 , - V_103 ) ;
V_5 -> V_20 = F_56 ( V_98 ) ;
V_5 -> V_76 = F_57 ( V_5 -> V_20 -> V_31 . V_104 ) ;
V_101 = F_58 ( V_5 -> V_20 ) ;
F_51 ( V_5 , V_101 -> V_66 ) ;
}
static int F_59 ( struct V_12 * V_5 ,
struct V_65 * V_20 )
{
unsigned long V_50 ;
int V_27 ;
F_40 ( & V_5 -> V_52 , V_50 ) ;
V_27 = F_60 ( & V_5 -> V_102 , V_20 ) ;
if ( V_5 -> V_33 ) {
F_42 ( & V_5 -> V_52 , V_50 ) ;
goto exit;
}
V_5 -> V_33 = true ;
F_42 ( & V_5 -> V_52 , V_50 ) ;
F_36 ( & V_5 -> V_45 ) ;
exit:
return V_27 ;
}
static int F_61 ( struct V_65 * V_20 , unsigned long V_66 )
{
struct V_105 * V_104 = F_62 ( V_20 ) ;
struct V_100 * V_101 = F_58 ( V_20 ) ;
struct V_106 * V_76 = F_63 ( V_104 ) ;
struct V_12 * V_5 = V_76 -> V_5 ;
if ( ! F_48 ( V_20 -> V_21 , V_22 ) ) {
F_64 ( V_5 -> V_5 , L_4 ) ;
return - V_43 ;
}
V_101 -> V_66 = V_66 ;
return F_59 ( V_5 , V_20 ) ;
}
static int F_65 ( struct V_105 * V_107 ,
const T_3 * V_58 , unsigned int V_60 )
{
struct V_108 * V_104 = F_66 ( V_107 ) ;
struct V_106 * V_76 = F_57 ( V_104 ) ;
if ( V_60 != V_109 &&
V_60 != V_64 &&
V_60 != V_63 )
return - V_43 ;
memcpy ( V_76 -> V_92 , V_58 , V_60 ) ;
V_76 -> V_60 = V_60 ;
return 0 ;
}
static int F_67 ( struct V_65 * V_20 )
{
return F_61 ( V_20 , 0 ) ;
}
static int F_68 ( struct V_65 * V_20 )
{
return F_61 ( V_20 , V_69 ) ;
}
static int F_69 ( struct V_65 * V_20 )
{
return F_61 ( V_20 , V_72 ) ;
}
static int F_70 ( struct V_65 * V_20 )
{
return F_61 ( V_20 , V_69 | V_72 ) ;
}
static int F_71 ( struct V_108 * V_104 )
{
struct V_106 * V_76 = F_57 ( V_104 ) ;
V_76 -> V_5 = V_110 ;
V_104 -> V_111 . V_112 = sizeof( struct V_100 ) ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_113 * V_5 = & V_3 -> V_5 ;
int V_114 , V_115 , V_27 = - V_116 ;
struct V_1 * V_117 ;
struct V_12 * V_118 ;
struct V_119 * V_120 ;
if ( V_110 )
return - V_121 ;
V_118 = F_73 ( V_5 , sizeof( * V_118 ) , V_122 ) ;
if ( ! V_118 )
return - V_41 ;
V_120 = F_74 ( V_3 , V_123 , 0 ) ;
V_118 -> V_124 = F_75 ( & V_3 -> V_5 , V_120 ) ;
if ( F_76 ( V_118 -> V_124 ) )
return F_77 ( V_118 -> V_124 ) ;
V_117 = F_1 ( V_3 ) ;
V_118 -> V_125 = F_78 ( V_5 , L_5 ) ;
if ( F_76 ( V_118 -> V_125 ) ) {
F_64 ( V_5 , L_6 ) ;
return - V_126 ;
}
V_27 = F_79 ( V_118 -> V_125 ) ;
if ( V_27 < 0 ) {
F_64 ( V_5 , L_7 , V_27 ) ;
return V_27 ;
}
F_80 ( & V_118 -> V_52 ) ;
V_118 -> V_62 = V_118 -> V_124 + V_117 -> V_127 ;
V_118 -> V_128 = F_81 ( V_3 , 0 ) ;
if ( V_118 -> V_128 < 0 ) {
V_27 = V_118 -> V_128 ;
F_82 ( V_5 , L_8 ) ;
goto V_129;
}
V_27 = F_83 ( V_5 , V_118 -> V_128 , F_38 ,
V_130 , V_3 -> V_131 , V_3 ) ;
if ( V_27 < 0 ) {
F_82 ( V_5 , L_8 ) ;
goto V_129;
}
V_118 -> V_33 = false ;
V_118 -> V_117 = V_117 ;
V_118 -> V_5 = V_5 ;
F_84 ( V_3 , V_118 ) ;
V_110 = V_118 ;
F_85 ( & V_118 -> V_45 , F_53 , ( unsigned long ) V_118 ) ;
F_86 ( & V_118 -> V_102 , V_132 ) ;
for ( V_114 = 0 ; V_114 < F_87 ( V_133 ) ; V_114 ++ ) {
V_27 = F_88 ( & V_133 [ V_114 ] ) ;
if ( V_27 )
goto V_134;
}
F_89 ( V_5 , L_9 ) ;
return 0 ;
V_134:
F_64 ( V_5 , L_10 , V_133 [ V_114 ] . V_135 , V_27 ) ;
for ( V_115 = 0 ; V_115 < V_114 ; V_115 ++ )
F_90 ( & V_133 [ V_115 ] ) ;
F_91 ( & V_118 -> V_45 ) ;
V_129:
F_92 ( V_118 -> V_125 ) ;
V_110 = NULL ;
return V_27 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_12 * V_118 = F_39 ( V_3 ) ;
int V_114 ;
if ( ! V_118 )
return - V_116 ;
for ( V_114 = 0 ; V_114 < F_87 ( V_133 ) ; V_114 ++ )
F_90 ( & V_133 [ V_114 ] ) ;
F_91 ( & V_118 -> V_45 ) ;
F_92 ( V_118 -> V_125 ) ;
V_110 = NULL ;
return 0 ;
}
