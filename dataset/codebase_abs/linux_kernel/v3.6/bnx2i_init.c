void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
if ( ( V_2 -> V_4 == V_5 ) ||
( V_2 -> V_4 == V_6 ) )
F_2 ( V_7 , & V_2 -> V_3 ) ;
else if ( ( V_2 -> V_4 == V_8 ) ||
( V_2 -> V_4 == V_9 ) )
F_2 ( V_10 , & V_2 -> V_3 ) ;
else if ( ( V_2 -> V_4 == V_11 ) ||
( V_2 -> V_4 == V_12 ) ) {
F_2 ( V_13 , & V_2 -> V_3 ) ;
V_2 -> V_14 = V_15 ;
} else if ( V_2 -> V_4 == V_16 ||
V_2 -> V_4 == V_17 ||
V_2 -> V_4 == V_18 ||
V_2 -> V_4 == V_19 ||
V_2 -> V_4 == V_20 ||
V_2 -> V_4 == V_21 ||
V_2 -> V_4 == V_22 ||
V_2 -> V_4 == V_23 ||
V_2 -> V_4 == V_24 ||
V_2 -> V_4 == V_25 ||
V_2 -> V_4 == V_26 ||
V_2 -> V_4 == V_27 ||
V_2 -> V_4 == V_28 ||
V_2 -> V_4 == V_29 )
F_2 ( V_30 , & V_2 -> V_3 ) ;
else
F_3 ( V_31 L_1 ,
V_2 -> V_4 ) ;
}
struct V_1 * F_4 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_32 ;
if ( ! V_33 )
goto V_34;
F_5 ( & V_35 ) ;
F_6 (tmp_hba, &adapter_list, link) {
if ( V_32 -> V_36 && V_32 -> V_36 -> V_37 ) {
V_2 = V_32 ;
break;
}
}
F_7 ( & V_35 ) ;
V_34:
return V_2 ;
}
struct V_1 * F_8 ( struct V_38 * V_36 )
{
struct V_1 * V_2 , * V_39 ;
F_5 ( & V_35 ) ;
F_9 (hba, temp, &adapter_list, link) {
if ( V_2 -> V_36 == V_36 ) {
F_7 ( & V_35 ) ;
return V_2 ;
}
}
F_7 ( & V_35 ) ;
return NULL ;
}
void F_10 ( void * V_40 )
{
#define F_11 (1000 / HZ)
struct V_1 * V_2 = V_40 ;
int V_41 = V_42 ;
F_12 ( ! V_2 -> V_36 -> V_43 ) ;
F_13 ( V_2 ) ;
while ( ! F_14 ( V_44 , & V_2 -> V_45 ) && V_41 -- )
F_15 ( F_11 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 , * V_50 ;
if ( V_2 -> V_51 ) {
F_3 ( V_31 L_2
L_3 , V_2 -> V_52 -> V_53 ,
V_2 -> V_51 ) ;
F_5 ( & V_2 -> V_54 ) ;
F_17 (pos, tmp, &hba->ep_active_list) {
V_47 = F_18 ( V_49 , struct V_46 , V_55 ) ;
F_19 ( V_47 ) ;
V_47 -> V_56 = NULL ;
}
F_7 ( & V_2 -> V_54 ) ;
}
}
void F_20 ( void * V_40 )
{
struct V_1 * V_2 = V_40 ;
int V_57 ;
int V_58 = 1 * V_42 ;
if ( ! F_21 ( V_59 ,
& V_2 -> V_45 ) ) {
F_22 ( V_2 -> V_60 ,
V_61 ) ;
V_58 = V_2 -> V_62 ;
}
F_23 ( V_2 -> V_63 ,
( F_24 ( & V_2 -> V_64 ) &&
F_24 ( & V_2 -> V_65 ) ) ,
2 * V_42 ) ;
while ( V_2 -> V_51 ) {
V_57 = V_2 -> V_51 ;
F_23 ( V_2 -> V_63 ,
( V_2 -> V_51 != V_57 ) ,
V_58 ) ;
if ( V_2 -> V_51 == V_57 )
break;
}
F_16 ( V_2 ) ;
F_25 ( V_59 , & V_2 -> V_45 ) ;
F_25 ( V_44 , & V_2 -> V_45 ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_38 * V_36 )
{
int V_66 ;
F_5 ( & V_35 ) ;
if ( ! V_36 -> V_43 ) {
F_3 ( V_31 L_4
L_5 , V_2 -> V_52 -> V_53 ) ;
V_66 = - V_67 ;
goto V_68;
}
V_2 -> V_36 = V_36 ;
V_66 = V_36 -> V_69 ( V_36 , V_70 , V_2 ) ;
if ( ! V_66 ) {
V_2 -> V_71 ++ ;
F_2 ( V_72 , & V_2 -> V_73 ) ;
F_27 ( & V_2 -> V_55 , & V_74 ) ;
V_33 ++ ;
} else if ( V_66 == - V_75 )
F_3 ( V_31 L_6
L_7 , V_2 , V_36 ) ;
else if ( V_66 == - V_76 )
F_3 ( V_77 L_8 ) ;
else if ( V_66 == - V_78 )
F_3 ( V_77 L_9 , V_70 ) ;
else
F_3 ( V_77 L_10 , V_66 ) ;
V_68:
F_7 ( & V_35 ) ;
return V_66 ;
}
void F_28 ( struct V_38 * V_79 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_79 ) ;
if ( ! V_2 ) {
F_3 ( V_77 L_11 ) ;
return;
}
F_25 ( V_72 , & V_2 -> V_73 ) ;
if ( F_26 ( V_2 , V_79 ) ) {
F_3 ( V_77 L_12 , V_2 ) ;
F_30 ( V_2 ) ;
}
}
void F_31 ( struct V_38 * V_79 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_79 ) ;
if ( ! V_2 ) {
F_3 ( V_80 L_13
L_14 , V_79 ) ;
return;
}
F_5 ( & V_35 ) ;
F_32 ( & V_2 -> V_55 ) ;
V_33 -- ;
if ( F_14 ( V_72 , & V_2 -> V_73 ) ) {
V_2 -> V_36 -> V_81 ( V_2 -> V_36 , V_70 ) ;
F_25 ( V_72 , & V_2 -> V_73 ) ;
}
F_7 ( & V_35 ) ;
F_30 ( V_2 ) ;
}
int F_33 ( void * V_40 )
{
struct V_1 * V_2 = V_40 ;
struct V_82 * V_83 ;
if ( ! V_2 )
return - V_78 ;
V_83 = (struct V_82 * ) V_2 -> V_36 -> V_84 ;
if ( ! V_83 )
return - V_85 ;
F_34 ( V_83 -> V_86 , V_87 , sizeof( V_83 -> V_86 ) ) ;
memcpy ( V_83 -> V_88 + 2 , V_2 -> V_36 -> V_89 , V_90 ) ;
V_83 -> V_91 = V_2 -> V_52 -> V_92 ;
V_83 -> V_93 = V_2 -> V_94 ;
V_83 -> V_95 = V_2 -> V_96 ;
V_83 -> V_97 = 0 ;
V_83 -> V_98 = 0 ;
F_35 ( V_2 , V_83 , V_99 ) ;
F_35 ( V_2 , V_83 , V_100 ) ;
F_35 ( V_2 , V_83 , V_101 ) ;
F_35 ( V_2 , V_83 , V_102 ) ;
return 0 ;
}
static void F_36 ( unsigned int V_103 )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
V_105 = & F_37 ( V_108 , V_103 ) ;
V_107 = F_38 ( V_109 , ( void * ) V_105 ,
F_39 ( V_103 ) ,
L_15 , V_103 ) ;
if ( F_40 ( ! F_41 ( V_107 ) ) ) {
F_42 ( V_107 , V_103 ) ;
V_105 -> V_110 = V_107 ;
F_43 ( V_107 ) ;
}
}
static void F_44 ( unsigned int V_103 )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_111 * V_112 , * V_50 ;
V_105 = & F_37 ( V_108 , V_103 ) ;
F_45 ( & V_105 -> V_113 ) ;
V_107 = V_105 -> V_110 ;
V_105 -> V_110 = NULL ;
F_9 (work, tmp, &p->work_list, list) {
F_32 ( & V_112 -> V_114 ) ;
F_46 ( V_112 -> V_115 ,
V_112 -> V_116 , & V_112 -> V_117 ) ;
F_47 ( V_112 ) ;
}
F_48 ( & V_105 -> V_113 ) ;
if ( V_107 )
F_49 ( V_107 ) ;
}
static int F_50 ( struct V_118 * V_119 ,
unsigned long V_120 , void * V_121 )
{
unsigned V_103 = ( unsigned long ) V_121 ;
switch ( V_120 ) {
case V_122 :
case V_123 :
F_3 ( V_80 L_16 ,
V_103 ) ;
F_36 ( V_103 ) ;
break;
case V_124 :
case V_125 :
F_3 ( V_80 L_17 , V_103 ) ;
F_44 ( V_103 ) ;
break;
default:
break;
}
return V_126 ;
}
static int T_1 F_51 ( void )
{
int V_127 ;
unsigned V_103 = 0 ;
struct V_104 * V_105 ;
F_3 ( V_80 L_18 , V_86 ) ;
if ( V_128 && ! F_52 ( V_128 ) )
V_128 = F_53 ( V_128 ) ;
F_54 ( & V_35 ) ;
V_129 =
F_55 ( & V_130 ) ;
if ( ! V_129 ) {
F_3 ( V_77 L_19 ) ;
V_127 = - V_85 ;
goto V_68;
}
V_127 = F_56 ( V_70 , & V_131 ) ;
if ( V_127 ) {
F_3 ( V_77 L_20 ) ;
goto V_132;
}
F_57 (cpu) {
V_105 = & F_37 ( V_108 , V_103 ) ;
F_58 ( & V_105 -> V_133 ) ;
F_59 ( & V_105 -> V_113 ) ;
V_105 -> V_110 = NULL ;
}
F_60 (cpu)
F_36 ( V_103 ) ;
F_61 ( & V_134 ) ;
return 0 ;
V_132:
F_62 ( & V_130 ) ;
V_68:
return V_127 ;
}
static void T_2 F_63 ( void )
{
struct V_1 * V_2 ;
unsigned V_103 = 0 ;
F_5 ( & V_35 ) ;
while ( ! F_24 ( & V_74 ) ) {
V_2 = F_18 ( V_74 . V_135 , struct V_1 , V_55 ) ;
F_64 ( & V_2 -> V_55 ) ;
V_33 -- ;
if ( F_14 ( V_72 , & V_2 -> V_73 ) ) {
F_16 ( V_2 ) ;
V_2 -> V_36 -> V_81 ( V_2 -> V_36 , V_70 ) ;
F_25 ( V_72 , & V_2 -> V_73 ) ;
}
F_30 ( V_2 ) ;
}
F_7 ( & V_35 ) ;
F_65 ( & V_134 ) ;
F_60 (cpu)
F_44 ( V_103 ) ;
F_62 ( & V_130 ) ;
F_66 ( V_70 ) ;
}
