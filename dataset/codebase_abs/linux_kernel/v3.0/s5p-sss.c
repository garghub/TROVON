static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 , V_5 , F_3 ( V_4 ) ) ;
F_2 ( V_2 , V_6 , F_4 ( V_4 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 , V_7 , F_3 ( V_4 ) ) ;
F_2 ( V_2 , V_8 , F_4 ( V_4 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_9 )
{
V_2 -> V_10 -> V_11 . V_12 ( & V_2 -> V_10 -> V_11 , V_9 ) ;
V_2 -> V_13 = false ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_2 , V_2 -> V_14 , 1 , V_15 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_2 , V_2 -> V_16 , 1 , V_17 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_9 ;
if ( ! F_11 ( F_4 ( V_4 ) , V_18 ) ) {
V_9 = - V_19 ;
goto exit;
}
if ( ! F_4 ( V_4 ) ) {
V_9 = - V_19 ;
goto exit;
}
V_9 = F_12 ( V_2 -> V_2 , V_4 , 1 , V_15 ) ;
if ( ! V_9 ) {
V_9 = - V_20 ;
goto exit;
}
V_2 -> V_14 = V_4 ;
V_9 = 0 ;
exit:
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_9 ;
if ( ! F_11 ( F_4 ( V_4 ) , V_18 ) ) {
V_9 = - V_19 ;
goto exit;
}
if ( ! F_4 ( V_4 ) ) {
V_9 = - V_19 ;
goto exit;
}
V_9 = F_12 ( V_2 -> V_2 , V_4 , 1 , V_17 ) ;
if ( ! V_9 ) {
V_9 = - V_20 ;
goto exit;
}
V_2 -> V_16 = V_4 ;
V_9 = 0 ;
exit:
return V_9 ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
F_7 ( V_2 ) ;
if ( ! F_15 ( V_2 -> V_14 ) ) {
V_9 = F_10 ( V_2 , F_16 ( V_2 -> V_14 ) ) ;
if ( V_9 ) {
F_6 ( V_2 , V_9 ) ;
return;
}
F_5 ( V_2 , V_2 -> V_14 ) ;
} else
F_6 ( V_2 , V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_9 ;
F_9 ( V_2 ) ;
if ( ! F_15 ( V_2 -> V_16 ) ) {
V_9 = F_13 ( V_2 , F_16 ( V_2 -> V_16 ) ) ;
if ( V_9 ) {
F_6 ( V_2 , V_9 ) ;
return;
}
F_1 ( V_2 , V_2 -> V_16 ) ;
}
}
static T_1 F_18 ( int V_21 , void * V_22 )
{
struct V_23 * V_24 = V_22 ;
struct V_1 * V_2 = F_19 ( V_24 ) ;
T_2 V_25 ;
unsigned long V_26 ;
F_20 ( & V_2 -> V_27 , V_26 ) ;
if ( V_21 == V_2 -> V_28 ) {
V_25 = F_21 ( V_2 , V_29 ) ;
if ( V_25 & V_30 )
F_17 ( V_2 ) ;
if ( V_25 & V_31 )
F_14 ( V_2 ) ;
F_2 ( V_2 , V_32 , V_25 ) ;
}
F_22 ( & V_2 -> V_27 , V_26 ) ;
return V_33 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_3 * V_34 , T_3 * V_35 , unsigned int V_36 )
{
void T_4 * V_37 ;
memcpy ( V_2 -> V_38 + F_24 ( 0 ) , V_35 , 0x10 ) ;
if ( V_36 == V_39 )
V_37 = V_2 -> V_38 + F_25 ( 0 ) ;
else if ( V_36 == V_40 )
V_37 = V_2 -> V_38 + F_25 ( 2 ) ;
else
V_37 = V_2 -> V_38 + F_25 ( 4 ) ;
memcpy ( V_37 , V_34 , V_36 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned long V_41 )
{
struct V_42 * V_10 = V_2 -> V_10 ;
T_2 V_43 ;
int V_9 ;
unsigned long V_26 ;
V_43 = V_44 ;
if ( V_41 & V_45 )
V_43 |= V_46 ;
if ( ( V_41 & V_47 ) == V_48 )
V_43 |= V_49 ;
else if ( ( V_41 & V_47 ) == V_50 )
V_43 |= V_51 ;
if ( V_2 -> V_52 -> V_36 == V_40 )
V_43 |= V_53 ;
else if ( V_2 -> V_52 -> V_36 == V_39 )
V_43 |= V_54 ;
V_43 |= V_55 ;
V_43 |= V_56
| V_57
| V_58
| V_59
| V_60 ;
F_20 ( & V_2 -> V_27 , V_26 ) ;
F_2 ( V_2 , V_61 ,
V_62 | V_63 ) ;
F_2 ( V_2 , V_64 , 0x00 ) ;
V_9 = F_13 ( V_2 , V_10 -> V_65 ) ;
if ( V_9 )
goto V_66;
V_9 = F_10 ( V_2 , V_10 -> V_67 ) ;
if ( V_9 )
goto V_68;
F_2 ( V_2 , V_69 , V_43 ) ;
F_23 ( V_2 , V_2 -> V_52 -> V_70 , V_10 -> V_71 , V_2 -> V_52 -> V_36 ) ;
F_1 ( V_2 , V_10 -> V_65 ) ;
F_5 ( V_2 , V_10 -> V_67 ) ;
F_2 ( V_2 , V_72 ,
V_73 | V_74 ) ;
F_22 ( & V_2 -> V_27 , V_26 ) ;
return;
V_68:
F_9 ( V_2 ) ;
V_66:
F_6 ( V_2 , V_9 ) ;
F_22 ( & V_2 -> V_27 , V_26 ) ;
}
static void F_27 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
struct V_76 * V_77 , * V_78 ;
struct V_79 * V_80 ;
unsigned long V_26 ;
F_20 ( & V_2 -> V_27 , V_26 ) ;
V_78 = F_28 ( & V_2 -> V_81 ) ;
V_77 = F_29 ( & V_2 -> V_81 ) ;
F_22 ( & V_2 -> V_27 , V_26 ) ;
if ( ! V_77 )
return;
if ( V_78 )
V_78 -> V_12 ( V_78 , - V_82 ) ;
V_2 -> V_10 = F_30 ( V_77 ) ;
V_2 -> V_52 = F_31 ( V_2 -> V_10 -> V_11 . V_83 ) ;
V_80 = F_32 ( V_2 -> V_10 ) ;
F_26 ( V_2 , V_80 -> V_41 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_42 * V_10 )
{
unsigned long V_26 ;
int V_9 ;
F_20 ( & V_2 -> V_27 , V_26 ) ;
if ( V_2 -> V_13 ) {
V_9 = - V_84 ;
F_22 ( & V_2 -> V_27 , V_26 ) ;
goto exit;
}
V_2 -> V_13 = true ;
V_9 = F_34 ( & V_2 -> V_81 , V_10 ) ;
F_22 ( & V_2 -> V_27 , V_26 ) ;
F_35 ( & V_2 -> V_85 ) ;
exit:
return V_9 ;
}
static int F_36 ( struct V_42 * V_10 , unsigned long V_41 )
{
struct V_86 * V_83 = F_37 ( V_10 ) ;
struct V_87 * V_52 = F_38 ( V_83 ) ;
struct V_79 * V_80 = F_32 ( V_10 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
if ( ! F_11 ( V_10 -> V_88 , V_18 ) ) {
F_39 ( L_1 ) ;
return - V_19 ;
}
V_80 -> V_41 = V_41 ;
return F_33 ( V_2 , V_10 ) ;
}
static int F_40 ( struct V_86 * V_89 ,
const T_3 * V_34 , unsigned int V_36 )
{
struct V_90 * V_83 = F_41 ( V_89 ) ;
struct V_87 * V_52 = F_31 ( V_83 ) ;
if ( V_36 != V_91 &&
V_36 != V_40 &&
V_36 != V_39 )
return - V_19 ;
memcpy ( V_52 -> V_70 , V_34 , V_36 ) ;
V_52 -> V_36 = V_36 ;
return 0 ;
}
static int F_42 ( struct V_42 * V_10 )
{
return F_36 ( V_10 , 0 ) ;
}
static int F_43 ( struct V_42 * V_10 )
{
return F_36 ( V_10 , V_45 ) ;
}
static int F_44 ( struct V_42 * V_10 )
{
return F_36 ( V_10 , V_48 ) ;
}
static int F_45 ( struct V_42 * V_10 )
{
return F_36 ( V_10 , V_45 | V_48 ) ;
}
static int F_46 ( struct V_90 * V_83 )
{
struct V_87 * V_52 = F_31 ( V_83 ) ;
V_52 -> V_2 = V_92 ;
V_83 -> V_93 . V_94 = sizeof( struct V_79 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_24 )
{
int V_95 , V_96 , V_9 = - V_97 ;
struct V_1 * V_98 ;
struct V_99 * V_2 = & V_24 -> V_2 ;
struct V_100 * V_101 ;
if ( V_92 )
return - V_102 ;
V_101 = F_48 ( V_24 , V_103 , 0 ) ;
if ( ! V_101 )
return - V_97 ;
V_98 = F_49 ( V_2 , sizeof( * V_98 ) , V_104 ) ;
if ( ! V_98 )
return - V_20 ;
if ( ! F_50 ( V_2 , V_101 -> V_105 ,
F_51 ( V_101 ) , V_24 -> V_106 ) )
return - V_107 ;
V_98 -> V_108 = F_52 ( V_2 , L_2 ) ;
if ( F_53 ( V_98 -> V_108 ) ) {
F_54 ( V_2 , L_3 ) ;
return - V_109 ;
}
F_55 ( V_98 -> V_108 ) ;
F_56 ( & V_98 -> V_27 ) ;
V_98 -> V_38 = F_57 ( V_2 , V_101 -> V_105 ,
F_51 ( V_101 ) ) ;
V_98 -> V_110 = F_58 ( V_24 , L_4 ) ;
if ( V_98 -> V_110 < 0 ) {
V_9 = V_98 -> V_110 ;
F_59 ( V_2 , L_5 ) ;
goto V_111;
}
V_9 = F_60 ( V_2 , V_98 -> V_110 , F_18 ,
V_112 , V_24 -> V_106 , V_24 ) ;
if ( V_9 < 0 ) {
F_59 ( V_2 , L_5 ) ;
goto V_111;
}
V_98 -> V_28 = F_58 ( V_24 , L_6 ) ;
if ( V_98 -> V_28 < 0 ) {
V_9 = V_98 -> V_28 ;
F_59 ( V_2 , L_7 ) ;
goto V_111;
}
V_9 = F_60 ( V_2 , V_98 -> V_28 , F_18 ,
V_112 , V_24 -> V_106 , V_24 ) ;
if ( V_9 < 0 ) {
F_59 ( V_2 , L_7 ) ;
goto V_111;
}
V_98 -> V_2 = V_2 ;
F_61 ( V_24 , V_98 ) ;
V_92 = V_98 ;
F_62 ( & V_98 -> V_85 , F_27 , ( unsigned long ) V_98 ) ;
F_63 ( & V_98 -> V_81 , V_113 ) ;
for ( V_95 = 0 ; V_95 < F_64 ( V_114 ) ; V_95 ++ ) {
F_65 ( & V_114 [ V_95 ] . V_115 ) ;
V_9 = F_66 ( & V_114 [ V_95 ] ) ;
if ( V_9 )
goto V_116;
}
F_67 ( L_8 ) ;
return 0 ;
V_116:
F_54 ( V_2 , L_9 , V_114 [ V_95 ] . V_117 , V_9 ) ;
for ( V_96 = 0 ; V_96 < V_95 ; V_96 ++ )
F_68 ( & V_114 [ V_96 ] ) ;
F_69 ( & V_98 -> V_85 ) ;
V_111:
F_70 ( V_98 -> V_108 ) ;
F_71 ( V_98 -> V_108 ) ;
V_92 = NULL ;
F_61 ( V_24 , NULL ) ;
return V_9 ;
}
static int F_72 ( struct V_23 * V_24 )
{
struct V_1 * V_98 = F_19 ( V_24 ) ;
int V_95 ;
if ( ! V_98 )
return - V_97 ;
for ( V_95 = 0 ; V_95 < F_64 ( V_114 ) ; V_95 ++ )
F_68 ( & V_114 [ V_95 ] ) ;
F_69 ( & V_98 -> V_85 ) ;
F_70 ( V_98 -> V_108 ) ;
F_71 ( V_98 -> V_108 ) ;
V_92 = NULL ;
F_61 ( V_24 , NULL ) ;
return 0 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_118 ) ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_118 ) ;
}
