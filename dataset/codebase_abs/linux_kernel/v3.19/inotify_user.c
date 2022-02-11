static inline T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 ;
V_2 = ( V_3 | V_4 | V_5 ) ;
V_2 |= ( V_1 & ( V_6 | V_7 | V_8 ) ) ;
return V_2 ;
}
static inline T_2 F_2 ( T_1 V_2 )
{
return V_2 & ( V_6 | V_9 | V_10 | V_11 |
V_12 ) ;
}
static unsigned int F_3 ( struct V_13 * V_13 , T_3 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
int V_18 = 0 ;
F_4 ( V_13 , & V_16 -> V_19 , V_14 ) ;
F_5 ( & V_16 -> V_20 ) ;
if ( ! F_6 ( V_16 ) )
V_18 = V_21 | V_22 ;
F_7 ( & V_16 -> V_20 ) ;
return V_18 ;
}
static int F_8 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
V_26 = F_9 ( V_24 ) ;
if ( ! V_26 -> V_27 )
return 0 ;
return F_10 ( V_26 -> V_27 + 1 , sizeof( struct V_28 ) ) ;
}
static struct V_23 * F_11 ( struct V_15 * V_16 ,
T_4 V_29 )
{
T_4 V_30 = sizeof( struct V_28 ) ;
struct V_23 * V_26 ;
if ( F_6 ( V_16 ) )
return NULL ;
V_26 = F_12 ( V_16 ) ;
F_13 ( L_1 , V_31 , V_16 , V_26 ) ;
V_30 += F_8 ( V_26 ) ;
if ( V_30 > V_29 )
return F_14 ( - V_32 ) ;
F_15 ( V_16 ) ;
return V_26 ;
}
static T_5 F_16 ( struct V_15 * V_16 ,
struct V_23 * V_24 ,
char T_6 * V_33 )
{
struct V_28 V_28 ;
struct V_25 * V_26 ;
T_4 V_30 = sizeof( struct V_28 ) ;
T_4 V_27 ;
T_4 V_34 ;
F_13 ( L_1 , V_31 , V_16 , V_24 ) ;
V_26 = F_9 ( V_24 ) ;
V_27 = V_26 -> V_27 ;
V_34 = F_8 ( V_24 ) ;
V_28 . V_35 = V_34 ;
V_28 . V_2 = F_2 ( V_24 -> V_2 ) ;
V_28 . V_36 = V_26 -> V_36 ;
V_28 . V_37 = V_26 -> V_38 ;
if ( F_17 ( V_33 , & V_28 , V_30 ) )
return - V_39 ;
V_33 += V_30 ;
if ( V_34 ) {
if ( F_17 ( V_33 , V_26 -> V_40 , V_27 ) )
return - V_39 ;
V_33 += V_27 ;
if ( F_18 ( V_33 , V_34 - V_27 ) )
return - V_39 ;
V_30 += V_34 ;
}
return V_30 ;
}
static T_5 F_19 ( struct V_13 * V_13 , char T_6 * V_33 ,
T_4 V_29 , T_7 * V_41 )
{
struct V_15 * V_16 ;
struct V_23 * V_42 ;
char T_6 * V_43 ;
int V_18 ;
F_20 ( V_14 , V_44 ) ;
V_43 = V_33 ;
V_16 = V_13 -> V_17 ;
F_21 ( & V_16 -> V_19 , & V_14 ) ;
while ( 1 ) {
F_5 ( & V_16 -> V_20 ) ;
V_42 = F_11 ( V_16 , V_29 ) ;
F_7 ( & V_16 -> V_20 ) ;
F_13 ( L_2 , V_31 , V_16 , V_42 ) ;
if ( V_42 ) {
V_18 = F_22 ( V_42 ) ;
if ( F_23 ( V_42 ) )
break;
V_18 = F_16 ( V_16 , V_42 , V_33 ) ;
F_24 ( V_16 , V_42 ) ;
if ( V_18 < 0 )
break;
V_33 += V_18 ;
V_29 -= V_18 ;
continue;
}
V_18 = - V_45 ;
if ( V_13 -> V_46 & V_47 )
break;
V_18 = - V_48 ;
if ( F_25 ( V_49 ) )
break;
if ( V_43 != V_33 )
break;
F_26 ( & V_14 , V_50 , V_51 ) ;
}
F_27 ( & V_16 -> V_19 , & V_14 ) ;
if ( V_43 != V_33 && V_18 != - V_39 )
V_18 = V_33 - V_43 ;
return V_18 ;
}
static int F_28 ( struct V_52 * V_53 , struct V_13 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
F_13 ( L_3 , V_31 , V_16 ) ;
F_29 ( V_16 ) ;
return 0 ;
}
static long F_30 ( struct V_13 * V_13 , unsigned int V_54 ,
unsigned long V_1 )
{
struct V_15 * V_16 ;
struct V_23 * V_24 ;
void T_6 * V_55 ;
int V_18 = - V_56 ;
T_4 V_57 = 0 ;
V_16 = V_13 -> V_17 ;
V_55 = ( void T_6 * ) V_1 ;
F_13 ( L_4 , V_31 , V_16 , V_54 ) ;
switch ( V_54 ) {
case V_58 :
F_5 ( & V_16 -> V_20 ) ;
F_31 (fsn_event, &group->notification_list,
list) {
V_57 += sizeof( struct V_28 ) ;
V_57 += F_8 ( V_24 ) ;
}
F_7 ( & V_16 -> V_20 ) ;
V_18 = F_32 ( V_57 , ( int T_6 * ) V_55 ) ;
break;
}
return V_18 ;
}
static int F_33 ( const char T_6 * V_59 , struct V_60 * V_60 , unsigned V_61 )
{
int error ;
error = F_34 ( V_62 , V_59 , V_61 , V_60 ) ;
if ( error )
return error ;
error = F_35 ( V_60 -> V_63 -> V_64 , V_65 ) ;
if ( error )
F_36 ( V_60 ) ;
return error ;
}
static int F_37 ( struct V_66 * V_66 , T_8 * V_67 ,
struct V_68 * V_69 )
{
int V_18 ;
F_38 ( V_70 ) ;
F_39 ( V_67 ) ;
V_18 = F_40 ( V_66 , V_69 , 1 , 0 , V_71 ) ;
if ( V_18 >= 0 ) {
V_69 -> V_36 = V_18 ;
F_41 ( & V_69 -> V_72 ) ;
}
F_42 ( V_67 ) ;
F_43 () ;
return V_18 < 0 ? V_18 : 0 ;
}
static struct V_68 * F_44 ( struct V_15 * V_16 ,
int V_36 )
{
struct V_66 * V_66 = & V_16 -> V_73 . V_66 ;
T_8 * V_67 = & V_16 -> V_73 . V_67 ;
struct V_68 * V_69 ;
F_45 ( V_67 ) ;
V_69 = F_46 ( V_66 , V_36 ) ;
if ( V_69 ) {
struct V_74 * V_72 = & V_69 -> V_72 ;
F_41 ( V_72 ) ;
F_47 ( F_48 ( & V_72 -> V_75 ) < 2 ) ;
}
return V_69 ;
}
static struct V_68 * F_49 ( struct V_15 * V_16 ,
int V_36 )
{
struct V_68 * V_69 ;
T_8 * V_67 = & V_16 -> V_73 . V_67 ;
F_39 ( V_67 ) ;
V_69 = F_44 ( V_16 , V_36 ) ;
F_42 ( V_67 ) ;
return V_69 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_68 * V_69 )
{
struct V_66 * V_66 = & V_16 -> V_73 . V_66 ;
T_8 * V_67 = & V_16 -> V_73 . V_67 ;
int V_36 = V_69 -> V_36 ;
F_45 ( V_67 ) ;
F_51 ( V_66 , V_36 ) ;
F_52 ( & V_69 -> V_72 ) ;
}
static void F_53 ( struct V_15 * V_16 ,
struct V_68 * V_69 )
{
T_8 * V_67 = & V_16 -> V_73 . V_67 ;
struct V_68 * V_76 = NULL ;
int V_36 ;
F_39 ( V_67 ) ;
V_36 = V_69 -> V_36 ;
if ( V_36 == - 1 ) {
F_54 ( 1 , L_5
L_6 , V_31 , V_69 , V_69 -> V_36 ,
V_69 -> V_72 . V_16 , V_69 -> V_72 . V_52 ) ;
goto V_77;
}
V_76 = F_44 ( V_16 , V_36 ) ;
if ( F_55 ( ! V_76 ) ) {
F_54 ( 1 , L_5
L_6 , V_31 , V_69 , V_69 -> V_36 ,
V_69 -> V_72 . V_16 , V_69 -> V_72 . V_52 ) ;
goto V_77;
}
if ( F_55 ( V_76 != V_69 ) ) {
F_54 ( 1 , L_7
L_8
L_9 ,
V_31 , V_69 , V_69 -> V_36 , V_69 -> V_72 . V_16 ,
V_69 -> V_72 . V_52 , V_76 , V_76 -> V_36 ,
V_76 -> V_72 . V_16 ,
V_76 -> V_72 . V_52 ) ;
goto V_77;
}
if ( F_55 ( F_48 ( & V_69 -> V_72 . V_75 ) < 3 ) ) {
F_56 ( V_78 L_5
L_6 , V_31 , V_69 , V_69 -> V_36 ,
V_69 -> V_72 . V_16 , V_69 -> V_72 . V_52 ) ;
F_57 () ;
}
F_50 ( V_16 , V_69 ) ;
V_77:
if ( V_76 )
F_52 ( & V_76 -> V_72 ) ;
V_69 -> V_36 = - 1 ;
F_42 ( V_67 ) ;
}
void F_58 ( struct V_74 * V_72 ,
struct V_15 * V_16 )
{
struct V_68 * V_69 ;
F_59 ( V_16 , NULL , V_72 , NULL , V_3 ,
NULL , V_79 , NULL , 0 ) ;
V_69 = F_60 ( V_72 , struct V_68 , V_72 ) ;
F_53 ( V_16 , V_69 ) ;
F_61 ( & V_16 -> V_73 . V_80 -> V_81 ) ;
}
static void F_62 ( struct V_74 * V_72 )
{
struct V_68 * V_69 ;
V_69 = F_60 ( V_72 , struct V_68 , V_72 ) ;
F_63 ( V_82 , V_69 ) ;
}
static int F_64 ( struct V_15 * V_16 ,
struct V_52 * V_52 ,
T_2 V_1 )
{
struct V_74 * V_72 ;
struct V_68 * V_69 ;
T_1 V_83 , V_84 ;
T_1 V_2 ;
int V_85 = ( V_1 & V_86 ) ;
int V_18 ;
V_2 = F_1 ( V_1 ) ;
V_72 = F_65 ( V_16 , V_52 ) ;
if ( ! V_72 )
return - V_87 ;
V_69 = F_60 ( V_72 , struct V_68 , V_72 ) ;
F_39 ( & V_72 -> V_88 ) ;
V_83 = V_72 -> V_2 ;
if ( V_85 )
F_66 ( V_72 , ( V_72 -> V_2 | V_2 ) ) ;
else
F_66 ( V_72 , V_2 ) ;
V_84 = V_72 -> V_2 ;
F_42 ( & V_72 -> V_88 ) ;
if ( V_83 != V_84 ) {
int V_89 = ( V_83 & ~ V_84 ) ;
int V_90 = ( V_84 & ~ V_52 -> V_91 ) ;
if ( V_89 || V_90 )
F_67 ( V_52 ) ;
}
V_18 = V_69 -> V_36 ;
F_52 ( V_72 ) ;
return V_18 ;
}
static int F_68 ( struct V_15 * V_16 ,
struct V_52 * V_52 ,
T_2 V_1 )
{
struct V_68 * V_92 ;
T_1 V_2 ;
int V_18 ;
struct V_66 * V_66 = & V_16 -> V_73 . V_66 ;
T_8 * V_67 = & V_16 -> V_73 . V_67 ;
V_2 = F_1 ( V_1 ) ;
V_92 = F_69 ( V_82 , V_70 ) ;
if ( F_55 ( ! V_92 ) )
return - V_93 ;
F_70 ( & V_92 -> V_72 , F_62 ) ;
V_92 -> V_72 . V_2 = V_2 ;
V_92 -> V_36 = - 1 ;
V_18 = - V_94 ;
if ( F_48 ( & V_16 -> V_73 . V_80 -> V_81 ) >= V_95 )
goto V_96;
V_18 = F_37 ( V_66 , V_67 , V_92 ) ;
if ( V_18 )
goto V_96;
V_18 = F_71 ( & V_92 -> V_72 , V_16 , V_52 ,
NULL , 0 ) ;
if ( V_18 ) {
F_53 ( V_16 , V_92 ) ;
goto V_96;
}
F_72 ( & V_16 -> V_73 . V_80 -> V_81 ) ;
V_18 = V_92 -> V_36 ;
V_96:
F_52 ( & V_92 -> V_72 ) ;
return V_18 ;
}
static int F_73 ( struct V_15 * V_16 , struct V_52 * V_52 , T_2 V_1 )
{
int V_18 = 0 ;
F_5 ( & V_16 -> V_97 ) ;
V_18 = F_64 ( V_16 , V_52 , V_1 ) ;
if ( V_18 == - V_87 )
V_18 = F_68 ( V_16 , V_52 , V_1 ) ;
F_7 ( & V_16 -> V_97 ) ;
return V_18 ;
}
static struct V_15 * F_74 ( unsigned int V_98 )
{
struct V_15 * V_16 ;
struct V_25 * V_99 ;
V_16 = F_75 ( & V_100 ) ;
if ( F_23 ( V_16 ) )
return V_16 ;
V_99 = F_76 ( sizeof( struct V_25 ) , V_70 ) ;
if ( F_55 ( ! V_99 ) ) {
F_29 ( V_16 ) ;
return F_14 ( - V_93 ) ;
}
V_16 -> V_101 = & V_99 -> V_102 ;
F_77 ( V_16 -> V_101 , NULL , V_103 ) ;
V_99 -> V_36 = - 1 ;
V_99 -> V_38 = 0 ;
V_99 -> V_27 = 0 ;
V_16 -> V_98 = V_98 ;
F_78 ( & V_16 -> V_73 . V_67 ) ;
F_79 ( & V_16 -> V_73 . V_66 ) ;
V_16 -> V_73 . V_80 = F_80 () ;
if ( F_81 ( & V_16 -> V_73 . V_80 -> V_104 ) >
V_105 ) {
F_29 ( V_16 ) ;
return F_14 ( - V_106 ) ;
}
return V_16 ;
}
static int T_9 F_82 ( void )
{
F_83 ( V_107 != V_108 ) ;
F_83 ( V_109 != V_110 ) ;
F_83 ( V_111 != V_112 ) ;
F_83 ( V_113 != V_114 ) ;
F_83 ( V_115 != V_116 ) ;
F_83 ( V_117 != V_118 ) ;
F_83 ( V_119 != V_120 ) ;
F_83 ( V_121 != V_122 ) ;
F_83 ( V_123 != V_124 ) ;
F_83 ( V_125 != V_126 ) ;
F_83 ( V_127 != V_128 ) ;
F_83 ( V_129 != V_130 ) ;
F_83 ( V_10 != V_5 ) ;
F_83 ( V_12 != V_103 ) ;
F_83 ( V_11 != V_3 ) ;
F_83 ( V_8 != V_131 ) ;
F_83 ( V_9 != V_132 ) ;
F_83 ( V_7 != V_133 ) ;
F_47 ( F_84 ( V_134 ) != 21 ) ;
V_82 = F_85 ( V_68 , V_135 ) ;
V_136 = 16384 ;
V_105 = 128 ;
V_95 = 8192 ;
return 0 ;
}
