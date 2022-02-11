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
static void F_20 ( struct V_12 * V_5 )
{
if ( V_5 -> V_27 ) {
F_21 ( V_5 -> V_5 ,
L_1 ,
V_5 -> V_20 -> V_21 ) ;
F_16 ( F_13 ( V_5 -> V_27 ) , V_5 -> V_20 -> V_28 ,
V_5 -> V_20 -> V_21 , 1 ) ;
}
F_10 ( V_5 , & V_5 -> V_29 ) ;
F_10 ( V_5 , & V_5 -> V_27 ) ;
}
static void F_22 ( struct V_12 * V_5 , int V_30 )
{
V_5 -> V_20 -> V_31 . V_32 ( & V_5 -> V_20 -> V_31 , V_30 ) ;
}
static void F_23 ( struct V_12 * V_5 )
{
F_24 ( V_5 -> V_5 , V_5 -> V_33 , 1 , V_34 ) ;
}
static void F_25 ( struct V_12 * V_5 )
{
F_24 ( V_5 -> V_5 , V_5 -> V_35 , 1 , V_36 ) ;
}
static int F_26 ( struct V_12 * V_5 , struct V_13 * V_37 ,
struct V_13 * * V_28 )
{
void * V_38 ;
int V_19 ;
* V_28 = F_27 ( sizeof( * * V_28 ) , V_39 ) ;
if ( ! * V_28 )
return - V_40 ;
V_19 = F_11 ( V_5 -> V_20 -> V_21 , V_22 ) ;
V_38 = ( void * ) F_28 ( V_39 , F_14 ( V_19 ) ) ;
if ( ! V_38 ) {
F_15 ( * V_28 ) ;
* V_28 = NULL ;
return - V_40 ;
}
F_16 ( V_38 , V_37 , V_5 -> V_20 -> V_21 , 0 ) ;
F_29 ( * V_28 , 1 ) ;
F_30 ( * V_28 , V_38 , V_19 ) ;
return 0 ;
}
static int F_31 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
int V_30 ;
if ( ! V_14 -> V_41 ) {
V_30 = - V_42 ;
goto exit;
}
V_30 = F_32 ( V_5 -> V_5 , V_14 , 1 , V_34 ) ;
if ( ! V_30 ) {
V_30 = - V_40 ;
goto exit;
}
V_5 -> V_33 = V_14 ;
V_30 = 0 ;
exit:
return V_30 ;
}
static int F_33 ( struct V_12 * V_5 , struct V_13 * V_14 )
{
int V_30 ;
if ( ! V_14 -> V_41 ) {
V_30 = - V_42 ;
goto exit;
}
V_30 = F_32 ( V_5 -> V_5 , V_14 , 1 , V_36 ) ;
if ( ! V_30 ) {
V_30 = - V_40 ;
goto exit;
}
V_5 -> V_35 = V_14 ;
V_30 = 0 ;
exit:
return V_30 ;
}
static int F_34 ( struct V_12 * V_5 )
{
int V_43 = 0 ;
F_23 ( V_5 ) ;
if ( ! F_35 ( V_5 -> V_33 ) ) {
V_43 = F_31 ( V_5 , F_36 ( V_5 -> V_33 ) ) ;
if ( ! V_43 )
V_43 = 1 ;
}
return V_43 ;
}
static int F_37 ( struct V_12 * V_5 )
{
int V_43 = 0 ;
F_25 ( V_5 ) ;
if ( ! F_35 ( V_5 -> V_35 ) ) {
V_43 = F_33 ( V_5 , F_36 ( V_5 -> V_35 ) ) ;
if ( ! V_43 )
V_43 = 1 ;
}
return V_43 ;
}
static T_1 F_38 ( int V_44 , void * V_45 )
{
struct V_2 * V_3 = V_45 ;
struct V_12 * V_5 = F_39 ( V_3 ) ;
int V_46 = 0 ;
int V_47 = 0 ;
bool V_48 = false ;
unsigned long V_49 ;
T_2 V_50 ;
int V_30 ;
F_40 ( & V_5 -> V_51 , V_49 ) ;
V_50 = F_41 ( V_5 , V_52 ) ;
if ( V_50 & V_53 )
V_47 = F_37 ( V_5 ) ;
if ( V_50 & V_54 ) {
if ( F_35 ( V_5 -> V_33 ) )
V_48 = true ;
V_46 = F_34 ( V_5 ) ;
}
F_6 ( V_5 , V_55 , V_50 ) ;
if ( V_47 < 0 ) {
V_30 = V_47 ;
goto error;
}
if ( V_46 < 0 ) {
V_30 = V_46 ;
goto error;
}
if ( V_48 ) {
F_20 ( V_5 ) ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
F_22 ( V_5 , 0 ) ;
F_43 ( & V_5 -> V_56 ) ;
} else {
if ( V_46 == 1 )
F_9 ( V_5 , V_5 -> V_33 ) ;
if ( V_47 == 1 )
F_5 ( V_5 , V_5 -> V_35 ) ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
}
return V_57 ;
error:
F_20 ( V_5 ) ;
V_5 -> V_58 = false ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
F_22 ( V_5 , V_30 ) ;
return V_57 ;
}
static void F_44 ( struct V_12 * V_5 ,
T_3 * V_59 , T_3 * V_60 , unsigned int V_61 )
{
void T_4 * V_62 ;
if ( V_60 )
F_45 ( V_5 -> V_63 + F_46 ( 0 ) , V_60 , 0x10 ) ;
if ( V_61 == V_64 )
V_62 = V_5 -> V_63 + F_47 ( 0 ) ;
else if ( V_61 == V_65 )
V_62 = V_5 -> V_63 + F_47 ( 2 ) ;
else
V_62 = V_5 -> V_63 + F_47 ( 4 ) ;
F_45 ( V_62 , V_59 , V_61 ) ;
}
static bool F_48 ( struct V_13 * V_14 )
{
while ( V_14 ) {
if ( ! F_49 ( V_14 -> V_41 , V_22 ) )
return false ;
V_14 = F_36 ( V_14 ) ;
}
return true ;
}
static int F_50 ( struct V_12 * V_5 ,
struct V_66 * V_20 )
{
struct V_13 * V_14 ;
int V_30 ;
V_5 -> V_29 = NULL ;
V_14 = V_20 -> V_37 ;
if ( ! F_48 ( V_14 ) ) {
F_21 ( V_5 -> V_5 ,
L_2 ) ;
V_30 = F_26 ( V_5 , V_14 , & V_5 -> V_29 ) ;
if ( V_30 )
return V_30 ;
V_14 = V_5 -> V_29 ;
}
V_30 = F_33 ( V_5 , V_14 ) ;
if ( V_30 ) {
F_10 ( V_5 , & V_5 -> V_29 ) ;
return V_30 ;
}
return 0 ;
}
static int F_51 ( struct V_12 * V_5 ,
struct V_66 * V_20 )
{
struct V_13 * V_14 ;
int V_30 ;
V_5 -> V_27 = NULL ;
V_14 = V_20 -> V_28 ;
if ( ! F_48 ( V_14 ) ) {
F_21 ( V_5 -> V_5 ,
L_3 ) ;
V_30 = F_26 ( V_5 , V_14 , & V_5 -> V_27 ) ;
if ( V_30 )
return V_30 ;
V_14 = V_5 -> V_27 ;
}
V_30 = F_31 ( V_5 , V_14 ) ;
if ( V_30 ) {
F_10 ( V_5 , & V_5 -> V_27 ) ;
return V_30 ;
}
return 0 ;
}
static void F_52 ( struct V_12 * V_5 , unsigned long V_67 )
{
struct V_66 * V_20 = V_5 -> V_20 ;
T_2 V_68 ;
unsigned long V_49 ;
int V_30 ;
V_68 = V_69 ;
if ( V_67 & V_70 )
V_68 |= V_71 ;
if ( ( V_67 & V_72 ) == V_73 )
V_68 |= V_74 ;
else if ( ( V_67 & V_72 ) == V_75 )
V_68 |= V_76 ;
if ( V_5 -> V_77 -> V_61 == V_65 )
V_68 |= V_78 ;
else if ( V_5 -> V_77 -> V_61 == V_64 )
V_68 |= V_79 ;
V_68 |= V_80 ;
V_68 |= V_81
| V_82
| V_83
| V_84
| V_85 ;
F_40 ( & V_5 -> V_51 , V_49 ) ;
F_6 ( V_5 , V_86 ,
V_87 | V_88 ) ;
F_6 ( V_5 , V_89 , 0x00 ) ;
V_30 = F_50 ( V_5 , V_20 ) ;
if ( V_30 )
goto V_90;
V_30 = F_51 ( V_5 , V_20 ) ;
if ( V_30 )
goto V_91;
F_53 ( V_5 , V_92 , V_68 ) ;
F_44 ( V_5 , V_5 -> V_77 -> V_93 , V_20 -> V_94 , V_5 -> V_77 -> V_61 ) ;
F_5 ( V_5 , V_5 -> V_35 ) ;
F_9 ( V_5 , V_5 -> V_33 ) ;
F_6 ( V_5 , V_95 ,
V_96 | V_97 ) ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
return;
V_91:
F_25 ( V_5 ) ;
V_90:
F_20 ( V_5 ) ;
V_5 -> V_58 = false ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
F_22 ( V_5 , V_30 ) ;
}
static void F_54 ( unsigned long V_10 )
{
struct V_12 * V_5 = (struct V_12 * ) V_10 ;
struct V_98 * V_99 , * V_100 ;
struct V_101 * V_102 ;
unsigned long V_49 ;
F_40 ( & V_5 -> V_51 , V_49 ) ;
V_100 = F_55 ( & V_5 -> V_103 ) ;
V_99 = F_56 ( & V_5 -> V_103 ) ;
if ( ! V_99 ) {
V_5 -> V_58 = false ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
return;
}
F_42 ( & V_5 -> V_51 , V_49 ) ;
if ( V_100 )
V_100 -> V_32 ( V_100 , - V_104 ) ;
V_5 -> V_20 = F_57 ( V_99 ) ;
V_5 -> V_77 = F_58 ( V_5 -> V_20 -> V_31 . V_105 ) ;
V_102 = F_59 ( V_5 -> V_20 ) ;
F_52 ( V_5 , V_102 -> V_67 ) ;
}
static int F_60 ( struct V_12 * V_5 ,
struct V_66 * V_20 )
{
unsigned long V_49 ;
int V_30 ;
F_40 ( & V_5 -> V_51 , V_49 ) ;
V_30 = F_61 ( & V_5 -> V_103 , V_20 ) ;
if ( V_5 -> V_58 ) {
F_42 ( & V_5 -> V_51 , V_49 ) ;
goto exit;
}
V_5 -> V_58 = true ;
F_42 ( & V_5 -> V_51 , V_49 ) ;
F_43 ( & V_5 -> V_56 ) ;
exit:
return V_30 ;
}
static int F_62 ( struct V_66 * V_20 , unsigned long V_67 )
{
struct V_106 * V_105 = F_63 ( V_20 ) ;
struct V_101 * V_102 = F_59 ( V_20 ) ;
struct V_107 * V_77 = F_64 ( V_105 ) ;
struct V_12 * V_5 = V_77 -> V_5 ;
if ( ! F_49 ( V_20 -> V_21 , V_22 ) ) {
F_65 ( V_5 -> V_5 , L_4 ) ;
return - V_42 ;
}
V_102 -> V_67 = V_67 ;
return F_60 ( V_5 , V_20 ) ;
}
static int F_66 ( struct V_106 * V_108 ,
const T_3 * V_59 , unsigned int V_61 )
{
struct V_109 * V_105 = F_67 ( V_108 ) ;
struct V_107 * V_77 = F_58 ( V_105 ) ;
if ( V_61 != V_110 &&
V_61 != V_65 &&
V_61 != V_64 )
return - V_42 ;
memcpy ( V_77 -> V_93 , V_59 , V_61 ) ;
V_77 -> V_61 = V_61 ;
return 0 ;
}
static int F_68 ( struct V_66 * V_20 )
{
return F_62 ( V_20 , 0 ) ;
}
static int F_69 ( struct V_66 * V_20 )
{
return F_62 ( V_20 , V_70 ) ;
}
static int F_70 ( struct V_66 * V_20 )
{
return F_62 ( V_20 , V_73 ) ;
}
static int F_71 ( struct V_66 * V_20 )
{
return F_62 ( V_20 , V_70 | V_73 ) ;
}
static int F_72 ( struct V_109 * V_105 )
{
struct V_107 * V_77 = F_58 ( V_105 ) ;
V_77 -> V_5 = V_111 ;
V_105 -> V_112 . V_113 = sizeof( struct V_101 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_114 * V_5 = & V_3 -> V_5 ;
int V_115 , V_116 , V_30 = - V_117 ;
struct V_1 * V_118 ;
struct V_12 * V_119 ;
struct V_120 * V_121 ;
if ( V_111 )
return - V_122 ;
V_119 = F_74 ( V_5 , sizeof( * V_119 ) , V_123 ) ;
if ( ! V_119 )
return - V_40 ;
V_121 = F_75 ( V_3 , V_124 , 0 ) ;
V_119 -> V_125 = F_76 ( & V_3 -> V_5 , V_121 ) ;
if ( F_77 ( V_119 -> V_125 ) )
return F_78 ( V_119 -> V_125 ) ;
V_118 = F_1 ( V_3 ) ;
V_119 -> V_126 = F_79 ( V_5 , L_5 ) ;
if ( F_77 ( V_119 -> V_126 ) ) {
F_65 ( V_5 , L_6 ) ;
return - V_127 ;
}
V_30 = F_80 ( V_119 -> V_126 ) ;
if ( V_30 < 0 ) {
F_65 ( V_5 , L_7 , V_30 ) ;
return V_30 ;
}
F_81 ( & V_119 -> V_51 ) ;
V_119 -> V_63 = V_119 -> V_125 + V_118 -> V_128 ;
V_119 -> V_129 = F_82 ( V_3 , 0 ) ;
if ( V_119 -> V_129 < 0 ) {
V_30 = V_119 -> V_129 ;
F_83 ( V_5 , L_8 ) ;
goto V_130;
}
V_30 = F_84 ( V_5 , V_119 -> V_129 , NULL ,
F_38 , V_131 ,
V_3 -> V_132 , V_3 ) ;
if ( V_30 < 0 ) {
F_83 ( V_5 , L_8 ) ;
goto V_130;
}
V_119 -> V_58 = false ;
V_119 -> V_5 = V_5 ;
F_85 ( V_3 , V_119 ) ;
V_111 = V_119 ;
F_86 ( & V_119 -> V_56 , F_54 , ( unsigned long ) V_119 ) ;
F_87 ( & V_119 -> V_103 , V_133 ) ;
for ( V_115 = 0 ; V_115 < F_88 ( V_134 ) ; V_115 ++ ) {
V_30 = F_89 ( & V_134 [ V_115 ] ) ;
if ( V_30 )
goto V_135;
}
F_90 ( V_5 , L_9 ) ;
return 0 ;
V_135:
F_65 ( V_5 , L_10 , V_134 [ V_115 ] . V_136 , V_30 ) ;
for ( V_116 = 0 ; V_116 < V_115 ; V_116 ++ )
F_91 ( & V_134 [ V_116 ] ) ;
F_92 ( & V_119 -> V_56 ) ;
V_130:
F_93 ( V_119 -> V_126 ) ;
V_111 = NULL ;
return V_30 ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_12 * V_119 = F_39 ( V_3 ) ;
int V_115 ;
if ( ! V_119 )
return - V_117 ;
for ( V_115 = 0 ; V_115 < F_88 ( V_134 ) ; V_115 ++ )
F_91 ( & V_134 [ V_115 ] ) ;
F_92 ( & V_119 -> V_56 ) ;
F_93 ( V_119 -> V_126 ) ;
V_111 = NULL ;
return 0 ;
}
