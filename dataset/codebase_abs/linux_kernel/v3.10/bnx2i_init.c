void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = 0 ;
if ( F_2 ( V_6 , & V_4 -> V_7 ) ) {
if ( V_2 -> V_8 == V_9 ||
V_2 -> V_8 == V_10 ) {
F_3 ( V_11 , & V_2 -> V_5 ) ;
} else if ( V_2 -> V_8 == V_12 ||
V_2 -> V_8 == V_13 ) {
F_3 ( V_14 , & V_2 -> V_5 ) ;
} else if ( V_2 -> V_8 == V_15 ||
V_2 -> V_8 == V_16 ) {
F_3 ( V_17 , & V_2 -> V_5 ) ;
V_2 -> V_18 = V_19 ;
}
} else if ( F_2 ( V_20 , & V_4 -> V_7 ) ) {
F_3 ( V_21 , & V_2 -> V_5 ) ;
} else {
F_4 ( V_22 L_1 ,
V_2 -> V_8 ) ;
}
}
struct V_1 * F_5 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_23 ;
if ( ! V_24 )
goto V_25;
F_6 ( & V_26 ) ;
F_7 (tmp_hba, &adapter_list, link) {
if ( V_23 -> V_27 && V_23 -> V_27 -> V_28 ) {
V_2 = V_23 ;
break;
}
}
F_8 ( & V_26 ) ;
V_25:
return V_2 ;
}
struct V_1 * F_9 ( struct V_3 * V_27 )
{
struct V_1 * V_2 , * V_29 ;
F_6 ( & V_26 ) ;
F_10 (hba, temp, &adapter_list, link) {
if ( V_2 -> V_27 == V_27 ) {
F_8 ( & V_26 ) ;
return V_2 ;
}
}
F_8 ( & V_26 ) ;
return NULL ;
}
void F_11 ( void * V_30 )
{
#define F_12 (1000 / HZ)
struct V_1 * V_2 = V_30 ;
int V_31 = V_32 ;
F_13 ( ! V_2 -> V_27 -> V_33 ) ;
F_14 ( V_2 ) ;
while ( ! F_2 ( V_34 , & V_2 -> V_35 ) && V_31 -- )
F_15 ( F_12 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 , * V_40 ;
if ( V_2 -> V_41 ) {
F_4 ( V_22 L_2
L_3 , V_2 -> V_42 -> V_43 ,
V_2 -> V_41 ) ;
F_6 ( & V_2 -> V_44 ) ;
F_17 (pos, tmp, &hba->ep_active_list) {
V_37 = F_18 ( V_39 , struct V_36 , V_45 ) ;
F_19 ( V_37 ) ;
V_37 -> V_46 = NULL ;
}
F_8 ( & V_2 -> V_44 ) ;
}
}
void F_20 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
int V_47 ;
int V_48 = 1 * V_32 ;
if ( ! F_21 ( V_49 ,
& V_2 -> V_35 ) ) {
F_22 ( V_2 -> V_50 ,
V_51 ) ;
V_48 = V_2 -> V_52 ;
}
F_23 ( V_2 -> V_53 ,
( F_24 ( & V_2 -> V_54 ) &&
F_24 ( & V_2 -> V_55 ) ) ,
2 * V_32 ) ;
while ( V_2 -> V_41 ) {
V_47 = V_2 -> V_41 ;
F_23 ( V_2 -> V_53 ,
( V_2 -> V_41 != V_47 ) ,
V_48 ) ;
if ( V_2 -> V_41 == V_47 )
break;
}
F_16 ( V_2 ) ;
F_25 ( V_49 , & V_2 -> V_35 ) ;
F_25 ( V_34 , & V_2 -> V_35 ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_27 )
{
int V_56 ;
F_6 ( & V_26 ) ;
if ( ! V_27 -> V_33 ) {
F_4 ( V_22 L_4
L_5 , V_2 -> V_42 -> V_43 ) ;
V_56 = - V_57 ;
goto V_58;
}
V_2 -> V_27 = V_27 ;
V_56 = V_27 -> V_59 ( V_27 , V_60 , V_2 ) ;
if ( ! V_56 ) {
V_2 -> V_61 ++ ;
F_3 ( V_62 , & V_2 -> V_63 ) ;
F_27 ( & V_2 -> V_45 , & V_64 ) ;
V_24 ++ ;
} else if ( V_56 == - V_65 )
F_4 ( V_22 L_6
L_7 , V_2 , V_27 ) ;
else if ( V_56 == - V_66 )
F_4 ( V_67 L_8 ) ;
else if ( V_56 == - V_68 )
F_4 ( V_67 L_9 , V_60 ) ;
else
F_4 ( V_67 L_10 , V_56 ) ;
V_58:
F_8 ( & V_26 ) ;
return V_56 ;
}
void F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( V_4 ) ;
if ( ! V_2 ) {
F_4 ( V_67 L_11 ) ;
return;
}
F_25 ( V_62 , & V_2 -> V_63 ) ;
if ( F_26 ( V_2 , V_4 ) ) {
F_4 ( V_67 L_12 , V_2 ) ;
F_30 ( V_2 ) ;
}
}
void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 ) ;
if ( ! V_2 ) {
F_4 ( V_69 L_13
L_14 , V_4 ) ;
return;
}
F_6 ( & V_26 ) ;
F_32 ( & V_2 -> V_45 ) ;
V_24 -- ;
if ( F_2 ( V_62 , & V_2 -> V_63 ) ) {
V_2 -> V_27 -> V_70 ( V_2 -> V_27 , V_60 ) ;
F_25 ( V_62 , & V_2 -> V_63 ) ;
}
F_8 ( & V_26 ) ;
F_30 ( V_2 ) ;
}
int F_33 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_71 * V_72 ;
if ( ! V_2 )
return - V_68 ;
V_72 = (struct V_71 * ) V_2 -> V_27 -> V_73 ;
if ( ! V_72 )
return - V_74 ;
F_34 ( V_72 -> V_75 , V_76 , sizeof( V_72 -> V_75 ) ) ;
memcpy ( V_72 -> V_77 + 2 , V_2 -> V_27 -> V_78 , V_79 ) ;
V_72 -> V_80 = V_2 -> V_42 -> V_81 ;
V_72 -> V_82 = V_2 -> V_83 ;
V_72 -> V_84 = V_2 -> V_85 ;
V_72 -> V_86 = 0 ;
V_72 -> V_87 = 0 ;
F_35 ( V_2 , V_72 , V_88 ) ;
F_35 ( V_2 , V_72 , V_89 ) ;
F_35 ( V_2 , V_72 , V_90 ) ;
F_35 ( V_2 , V_72 , V_91 ) ;
return 0 ;
}
static void F_36 ( unsigned int V_92 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
V_94 = & F_37 ( V_97 , V_92 ) ;
V_96 = F_38 ( V_98 , ( void * ) V_94 ,
F_39 ( V_92 ) ,
L_15 , V_92 ) ;
if ( F_40 ( ! F_41 ( V_96 ) ) ) {
F_42 ( V_96 , V_92 ) ;
V_94 -> V_99 = V_96 ;
F_43 ( V_96 ) ;
}
}
static void F_44 ( unsigned int V_92 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_100 * V_101 , * V_40 ;
V_94 = & F_37 ( V_97 , V_92 ) ;
F_45 ( & V_94 -> V_102 ) ;
V_96 = V_94 -> V_99 ;
V_94 -> V_99 = NULL ;
F_10 (work, tmp, &p->work_list, list) {
F_32 ( & V_101 -> V_103 ) ;
F_46 ( V_101 -> V_104 ,
V_101 -> V_105 , & V_101 -> V_106 ) ;
F_47 ( V_101 ) ;
}
F_48 ( & V_94 -> V_102 ) ;
if ( V_96 )
F_49 ( V_96 ) ;
}
static int F_50 ( struct V_107 * V_108 ,
unsigned long V_109 , void * V_110 )
{
unsigned V_92 = ( unsigned long ) V_110 ;
switch ( V_109 ) {
case V_111 :
case V_112 :
F_4 ( V_69 L_16 ,
V_92 ) ;
F_36 ( V_92 ) ;
break;
case V_113 :
case V_114 :
F_4 ( V_69 L_17 , V_92 ) ;
F_44 ( V_92 ) ;
break;
default:
break;
}
return V_115 ;
}
static int T_1 F_51 ( void )
{
int V_116 ;
unsigned V_92 = 0 ;
struct V_93 * V_94 ;
F_4 ( V_69 L_18 , V_75 ) ;
if ( V_117 && ! F_52 ( V_117 ) )
V_117 = F_53 ( V_117 ) ;
F_54 ( & V_26 ) ;
V_118 =
F_55 ( & V_119 ) ;
if ( ! V_118 ) {
F_4 ( V_67 L_19 ) ;
V_116 = - V_74 ;
goto V_58;
}
V_116 = F_56 ( V_60 , & V_120 ) ;
if ( V_116 ) {
F_4 ( V_67 L_20 ) ;
goto V_121;
}
F_57 (cpu) {
V_94 = & F_37 ( V_97 , V_92 ) ;
F_58 ( & V_94 -> V_122 ) ;
F_59 ( & V_94 -> V_102 ) ;
V_94 -> V_99 = NULL ;
}
F_60 (cpu)
F_36 ( V_92 ) ;
F_61 ( & V_123 ) ;
return 0 ;
V_121:
F_62 ( & V_119 ) ;
V_58:
return V_116 ;
}
static void T_2 F_63 ( void )
{
struct V_1 * V_2 ;
unsigned V_92 = 0 ;
F_6 ( & V_26 ) ;
while ( ! F_24 ( & V_64 ) ) {
V_2 = F_18 ( V_64 . V_124 , struct V_1 , V_45 ) ;
F_64 ( & V_2 -> V_45 ) ;
V_24 -- ;
if ( F_2 ( V_62 , & V_2 -> V_63 ) ) {
F_16 ( V_2 ) ;
V_2 -> V_27 -> V_70 ( V_2 -> V_27 , V_60 ) ;
F_25 ( V_62 , & V_2 -> V_63 ) ;
}
F_30 ( V_2 ) ;
}
F_8 ( & V_26 ) ;
F_65 ( & V_123 ) ;
F_60 (cpu)
F_44 ( V_92 ) ;
F_62 ( & V_119 ) ;
F_66 ( V_60 ) ;
}
