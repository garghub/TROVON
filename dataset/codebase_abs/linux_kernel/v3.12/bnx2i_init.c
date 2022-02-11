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
F_13 ( V_2 ) ;
while ( ! F_2 ( V_33 , & V_2 -> V_34 ) &&
! F_2 ( V_35 , & V_2 -> V_34 ) && V_31 -- )
F_14 ( F_12 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 , * V_40 ;
if ( V_2 -> V_41 ) {
F_4 ( V_22 L_2
L_3 , V_2 -> V_42 -> V_43 ,
V_2 -> V_41 ) ;
F_6 ( & V_2 -> V_44 ) ;
F_16 (pos, tmp, &hba->ep_active_list) {
V_37 = F_17 ( V_39 , struct V_36 , V_45 ) ;
F_18 ( V_37 ) ;
V_37 -> V_46 = NULL ;
}
F_8 ( & V_2 -> V_44 ) ;
}
}
void F_19 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
int V_47 ;
int V_48 = 1 * V_32 ;
if ( ! F_20 ( V_49 ,
& V_2 -> V_34 ) ) {
F_21 ( V_2 -> V_50 ,
V_51 ) ;
V_48 = V_2 -> V_52 ;
}
F_22 ( V_2 -> V_53 ,
( F_23 ( & V_2 -> V_54 ) &&
F_23 ( & V_2 -> V_55 ) ) ,
2 * V_32 ) ;
while ( V_2 -> V_41 ) {
V_47 = V_2 -> V_41 ;
F_22 ( V_2 -> V_53 ,
( V_2 -> V_41 != V_47 ) ,
V_48 ) ;
if ( V_2 -> V_41 == V_47 )
break;
}
F_15 ( V_2 ) ;
F_24 ( V_49 , & V_2 -> V_34 ) ;
F_24 ( V_33 , & V_2 -> V_34 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_27 )
{
int V_56 ;
F_6 ( & V_26 ) ;
if ( ! V_27 -> V_57 ) {
F_4 ( V_22 L_4
L_5 , V_2 -> V_42 -> V_43 ) ;
V_56 = - V_58 ;
goto V_59;
}
V_2 -> V_27 = V_27 ;
V_56 = V_27 -> V_60 ( V_27 , V_61 , V_2 ) ;
if ( ! V_56 ) {
V_2 -> V_62 ++ ;
F_3 ( V_63 , & V_2 -> V_64 ) ;
F_26 ( & V_2 -> V_45 , & V_65 ) ;
V_24 ++ ;
} else if ( V_56 == - V_66 )
F_4 ( V_22 L_6
L_7 , V_2 , V_27 ) ;
else if ( V_56 == - V_67 )
F_4 ( V_68 L_8 ) ;
else if ( V_56 == - V_69 )
F_4 ( V_68 L_9 , V_61 ) ;
else
F_4 ( V_68 L_10 , V_56 ) ;
V_59:
F_8 ( & V_26 ) ;
return V_56 ;
}
void F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( V_4 ) ;
if ( ! V_2 ) {
F_4 ( V_68 L_11 ) ;
return;
}
F_24 ( V_63 , & V_2 -> V_64 ) ;
if ( F_25 ( V_2 , V_4 ) ) {
F_4 ( V_68 L_12 , V_2 ) ;
F_29 ( V_2 ) ;
}
}
void F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 ) ;
if ( ! V_2 ) {
F_4 ( V_70 L_13
L_14 , V_4 ) ;
return;
}
F_6 ( & V_26 ) ;
F_31 ( & V_2 -> V_45 ) ;
V_24 -- ;
if ( F_2 ( V_63 , & V_2 -> V_64 ) ) {
V_2 -> V_27 -> V_71 ( V_2 -> V_27 , V_61 ) ;
F_24 ( V_63 , & V_2 -> V_64 ) ;
}
F_8 ( & V_26 ) ;
F_29 ( V_2 ) ;
}
int F_32 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_72 * V_73 ;
if ( ! V_2 )
return - V_69 ;
V_73 = (struct V_72 * ) V_2 -> V_27 -> V_74 ;
if ( ! V_73 )
return - V_75 ;
F_33 ( V_73 -> V_76 , V_77 , sizeof( V_73 -> V_76 ) ) ;
memcpy ( V_73 -> V_78 + 2 , V_2 -> V_27 -> V_79 , V_80 ) ;
V_73 -> V_81 = V_2 -> V_42 -> V_82 ;
V_73 -> V_83 = V_2 -> V_84 ;
V_73 -> V_85 = V_2 -> V_86 ;
V_73 -> V_87 = 0 ;
V_73 -> V_88 = 0 ;
F_34 ( V_2 , V_73 , V_89 ) ;
F_34 ( V_2 , V_73 , V_90 ) ;
F_34 ( V_2 , V_73 , V_91 ) ;
F_34 ( V_2 , V_73 , V_92 ) ;
return 0 ;
}
static void F_35 ( unsigned int V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
V_95 = & F_36 ( V_98 , V_93 ) ;
V_97 = F_37 ( V_99 , ( void * ) V_95 ,
F_38 ( V_93 ) ,
L_15 , V_93 ) ;
if ( F_39 ( ! F_40 ( V_97 ) ) ) {
F_41 ( V_97 , V_93 ) ;
V_95 -> V_100 = V_97 ;
F_42 ( V_97 ) ;
}
}
static void F_43 ( unsigned int V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_101 * V_102 , * V_40 ;
V_95 = & F_36 ( V_98 , V_93 ) ;
F_44 ( & V_95 -> V_103 ) ;
V_97 = V_95 -> V_100 ;
V_95 -> V_100 = NULL ;
F_10 (work, tmp, &p->work_list, list) {
F_31 ( & V_102 -> V_104 ) ;
F_45 ( V_102 -> V_105 ,
V_102 -> V_106 , & V_102 -> V_107 ) ;
F_46 ( V_102 ) ;
}
F_47 ( & V_95 -> V_103 ) ;
if ( V_97 )
F_48 ( V_97 ) ;
}
static int F_49 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_111 )
{
unsigned V_93 = ( unsigned long ) V_111 ;
switch ( V_110 ) {
case V_112 :
case V_113 :
F_4 ( V_70 L_16 ,
V_93 ) ;
F_35 ( V_93 ) ;
break;
case V_114 :
case V_115 :
F_4 ( V_70 L_17 , V_93 ) ;
F_43 ( V_93 ) ;
break;
default:
break;
}
return V_116 ;
}
static int T_1 F_50 ( void )
{
int V_117 ;
unsigned V_93 = 0 ;
struct V_94 * V_95 ;
F_4 ( V_70 L_18 , V_76 ) ;
if ( V_118 && ! F_51 ( V_118 ) )
V_118 = F_52 ( V_118 ) ;
F_53 ( & V_26 ) ;
V_119 =
F_54 ( & V_120 ) ;
if ( ! V_119 ) {
F_4 ( V_68 L_19 ) ;
V_117 = - V_75 ;
goto V_59;
}
V_117 = F_55 ( V_61 , & V_121 ) ;
if ( V_117 ) {
F_4 ( V_68 L_20 ) ;
goto V_122;
}
F_56 (cpu) {
V_95 = & F_36 ( V_98 , V_93 ) ;
F_57 ( & V_95 -> V_123 ) ;
F_58 ( & V_95 -> V_103 ) ;
V_95 -> V_100 = NULL ;
}
F_59 (cpu)
F_35 ( V_93 ) ;
F_60 ( & V_124 ) ;
return 0 ;
V_122:
F_61 ( & V_120 ) ;
V_59:
return V_117 ;
}
static void T_2 F_62 ( void )
{
struct V_1 * V_2 ;
unsigned V_93 = 0 ;
F_6 ( & V_26 ) ;
while ( ! F_23 ( & V_65 ) ) {
V_2 = F_17 ( V_65 . V_125 , struct V_1 , V_45 ) ;
F_63 ( & V_2 -> V_45 ) ;
V_24 -- ;
if ( F_2 ( V_63 , & V_2 -> V_64 ) ) {
F_15 ( V_2 ) ;
V_2 -> V_27 -> V_71 ( V_2 -> V_27 , V_61 ) ;
F_24 ( V_63 , & V_2 -> V_64 ) ;
}
F_29 ( V_2 ) ;
}
F_8 ( & V_26 ) ;
F_64 ( & V_124 ) ;
F_59 (cpu)
F_43 ( V_93 ) ;
F_61 ( & V_120 ) ;
F_65 ( V_61 ) ;
}
