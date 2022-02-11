static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
if ( V_2 -> V_6 > 0 ) {
F_2 ( V_4 , V_7 , & V_5 ) ;
V_5 &= ~ ( V_8 |
V_9 |
V_10 ) ;
F_3 ( V_4 , V_7 , V_5 ) ;
F_4 ( V_2 -> V_6 , V_2 ) ;
V_2 -> V_6 = 0 ;
}
if ( V_2 -> V_11 ) {
F_5 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
if ( V_4 -> V_12 )
F_6 ( V_4 ) ;
else if ( V_4 -> V_13 )
F_7 ( V_4 ) ;
}
static void F_8 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_9 ( V_14 ,
struct V_1 , V_14 ) ;
F_10 ( ! F_11 ( & V_2 -> V_15 ) ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 -> V_16 ) ;
F_12 ( V_2 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
if ( F_10 ( ! V_2 ) )
return;
F_14 ( & V_2 -> V_14 , F_8 ) ;
}
static struct V_1 * F_15 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_1 * V_19 , * V_20 ;
if ( V_2 -> V_18 == V_18 ) {
F_16 ( & V_2 -> V_14 ) ;
return V_2 ;
}
F_17 (tmp, &php_slot->children, link) {
V_19 = F_15 ( V_18 , V_20 ) ;
if ( V_19 )
return V_19 ;
}
return NULL ;
}
struct V_1 * F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_2 , * V_20 ;
unsigned long V_21 ;
F_19 ( & V_22 , V_21 ) ;
F_17 (tmp, &pnv_php_slot_list, link) {
V_2 = F_15 ( V_18 , V_20 ) ;
if ( V_2 ) {
F_20 ( & V_22 , V_21 ) ;
return V_2 ;
}
}
F_20 ( & V_22 , V_21 ) ;
return NULL ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_17 * V_23 ;
F_22 (dn, child) {
F_21 ( V_23 ) ;
F_23 ( V_23 ) ;
}
}
static void F_24 ( struct V_17 * V_24 )
{
struct V_17 * V_18 ;
int V_25 ;
F_22 (parent, dn) {
F_24 ( V_18 ) ;
F_25 ( V_18 ) ;
V_25 = F_26 ( & V_18 -> V_26 . V_14 . V_25 ) ;
if ( V_25 != 1 )
F_27 ( L_1 ,
V_25 , F_28 ( V_18 ) ) ;
F_29 ( V_18 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_18 ) ;
if ( V_2 -> V_27 )
F_31 ( & V_2 -> V_28 ) ;
F_24 ( V_2 -> V_18 ) ;
if ( V_2 -> V_27 ) {
F_12 ( V_2 -> V_29 ) ;
F_12 ( V_2 -> V_27 ) ;
V_2 -> V_29 = NULL ;
V_2 -> V_18 -> V_23 = NULL ;
V_2 -> V_27 = NULL ;
}
}
static void F_32 ( struct V_17 * V_24 )
{
struct V_17 * V_23 , * V_30 ;
F_22 (parent, child)
F_32 ( V_23 ) ;
V_23 = V_24 -> V_23 ;
V_24 -> V_23 = NULL ;
while ( V_23 ) {
V_30 = V_23 -> V_31 ;
V_23 -> V_31 = V_24 -> V_23 ;
V_24 -> V_23 = V_23 ;
V_23 = V_30 ;
}
}
static int F_33 ( struct V_32 * V_28 ,
struct V_17 * V_18 )
{
struct V_17 * V_23 ;
int V_33 = 0 ;
F_22 (dn, child) {
V_33 = F_34 ( V_28 , V_23 ) ;
if ( V_33 )
break;
V_33 = F_33 ( V_28 , V_23 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
static void * F_35 ( struct V_17 * V_18 , void * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 ;
struct V_37 * V_38 ;
V_38 = F_36 ( V_36 , V_18 ) ;
if ( ! V_38 )
return F_37 ( - V_39 ) ;
return NULL ;
}
static void F_38 ( struct V_1 * V_40 )
{
struct V_35 * V_36 = F_39 ( V_40 -> V_41 ) ;
F_40 ( V_40 -> V_18 , F_35 , V_36 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
void * V_27 , * V_42 , * V_29 ;
int V_33 ;
V_42 = F_42 ( 0x10000 , V_43 ) ;
if ( ! V_42 ) {
V_33 = - V_39 ;
F_43 ( & V_2 -> V_4 -> V_44 , L_2 ) ;
goto V_45;
}
V_33 = F_44 ( V_2 -> V_18 -> V_46 , V_42 , 0x10000 ) ;
if ( V_33 ) {
F_43 ( & V_2 -> V_4 -> V_44 , L_3 ,
V_33 ) ;
goto V_47;
}
V_27 = F_42 ( F_45 ( V_42 ) , V_43 ) ;
if ( ! V_27 ) {
V_33 = - V_39 ;
F_43 ( & V_2 -> V_4 -> V_44 , L_4 ,
F_45 ( V_42 ) ) ;
goto V_47;
}
memcpy ( V_27 , V_42 , F_45 ( V_42 ) ) ;
V_29 = F_46 ( V_27 , V_2 -> V_18 , NULL ) ;
if ( ! V_29 ) {
V_33 = - V_48 ;
F_43 ( & V_2 -> V_4 -> V_44 , L_5 ) ;
goto V_49;
}
F_47 ( & V_2 -> V_28 ) ;
F_32 ( V_2 -> V_18 ) ;
V_33 = F_33 ( & V_2 -> V_28 , V_2 -> V_18 ) ;
if ( V_33 ) {
F_32 ( V_2 -> V_18 ) ;
F_43 ( & V_2 -> V_4 -> V_44 , L_6 ,
V_33 ) ;
goto V_50;
}
V_2 -> V_18 -> V_23 = NULL ;
V_33 = F_48 ( & V_2 -> V_28 ) ;
if ( V_33 ) {
F_43 ( & V_2 -> V_4 -> V_44 , L_7 ,
V_33 ) ;
goto V_51;
}
F_38 ( V_2 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_29 = V_29 ;
F_12 ( V_42 ) ;
goto V_45;
V_51:
F_31 ( & V_2 -> V_28 ) ;
V_50:
F_12 ( V_29 ) ;
V_2 -> V_18 -> V_23 = NULL ;
V_49:
F_12 ( V_27 ) ;
V_47:
F_12 ( V_42 ) ;
V_45:
return V_33 ;
}
int F_49 ( struct V_52 * V_40 ,
T_2 V_53 )
{
struct V_1 * V_2 = V_40 -> V_54 ;
struct V_55 V_56 ;
int V_33 ;
V_33 = F_50 ( V_2 -> V_57 , V_53 , & V_56 ) ;
if ( V_33 > 0 ) {
if ( F_51 ( V_56 . V_58 [ 1 ] ) != V_2 -> V_18 -> V_46 ||
F_51 ( V_56 . V_58 [ 2 ] ) != V_53 ||
F_51 ( V_56 . V_58 [ 3 ] ) != V_59 ) {
F_43 ( & V_2 -> V_4 -> V_44 , L_8 ,
F_51 ( V_56 . V_58 [ 1 ] ) ,
F_51 ( V_56 . V_58 [ 2 ] ) ,
F_51 ( V_56 . V_58 [ 3 ] ) ) ;
return - V_60 ;
}
} else if ( V_33 < 0 ) {
F_43 ( & V_2 -> V_4 -> V_44 , L_9 ,
V_33 , ( V_53 == V_61 ) ? L_10 : L_11 ) ;
return V_33 ;
}
if ( V_53 == V_62 || V_53 == V_63 )
F_30 ( V_2 ) ;
else
V_33 = F_41 ( V_2 ) ;
return V_33 ;
}
static int F_52 ( struct V_52 * V_40 , T_3 * V_53 )
{
struct V_1 * V_2 = V_40 -> V_54 ;
T_2 V_64 = V_61 ;
int V_33 ;
V_33 = F_53 ( V_2 -> V_57 , & V_64 ) ;
if ( V_33 ) {
F_43 ( & V_2 -> V_4 -> V_44 , L_12 ,
V_33 ) ;
} else {
* V_53 = V_64 ;
V_40 -> V_65 -> V_66 = V_64 ;
}
return 0 ;
}
static int F_54 ( struct V_52 * V_40 , T_3 * V_53 )
{
struct V_1 * V_2 = V_40 -> V_54 ;
T_2 V_67 = V_68 ;
int V_33 ;
V_33 = F_55 ( V_2 -> V_57 , & V_67 ) ;
if ( V_33 >= 0 ) {
* V_53 = V_67 ;
V_40 -> V_65 -> V_69 = V_67 ;
V_33 = 0 ;
} else {
F_43 ( & V_2 -> V_4 -> V_44 , L_13 ,
V_33 ) ;
}
return V_33 ;
}
static int F_56 ( struct V_52 * V_40 , T_3 V_53 )
{
V_40 -> V_65 -> V_70 = V_53 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , bool V_71 )
{
struct V_52 * V_40 = & V_2 -> V_40 ;
T_2 V_67 = V_68 ;
T_2 V_66 = V_61 ;
int V_33 ;
if ( V_2 -> V_53 != V_72 )
return 0 ;
V_33 = F_54 ( V_40 , & V_67 ) ;
if ( V_33 )
return V_33 ;
if ( V_67 == V_68 )
goto V_73;
if ( ! V_2 -> V_74 ) {
V_2 -> V_74 = true ;
V_33 = F_52 ( V_40 , & V_66 ) ;
if ( V_33 )
return V_33 ;
if ( V_66 != V_61 )
return 0 ;
}
V_33 = F_52 ( V_40 , & V_66 ) ;
if ( V_33 )
return V_33 ;
if ( V_66 == V_61 )
goto V_73;
V_33 = F_49 ( V_40 , V_61 ) ;
if ( V_33 )
return V_33 ;
V_73:
if ( V_67 == V_75 ) {
if ( V_71 ) {
F_58 () ;
F_59 ( V_2 -> V_41 ) ;
F_60 () ;
}
V_2 -> V_53 = V_76 ;
if ( V_71 )
F_61 ( V_2 -> V_18 ) ;
} else {
V_2 -> V_53 = V_76 ;
}
return 0 ;
}
static int F_62 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_9 ( V_40 ,
struct V_1 , V_40 ) ;
return F_57 ( V_2 , true ) ;
}
static int F_63 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_54 ;
int V_33 ;
if ( V_2 -> V_53 != V_76 )
return 0 ;
F_58 () ;
F_64 ( V_2 -> V_41 ) ;
F_60 () ;
F_65 ( V_2 -> V_18 ) ;
V_33 = F_49 ( V_40 , V_62 ) ;
V_2 -> V_53 = V_72 ;
return V_33 ;
}
static void F_66 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_54 ;
unsigned long V_21 ;
F_19 ( & V_22 , V_21 ) ;
F_67 ( & V_2 -> V_77 ) ;
F_20 ( & V_22 , V_21 ) ;
F_13 ( V_2 ) ;
F_13 ( V_2 -> V_24 ) ;
}
static struct V_1 * F_68 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_78 * V_41 ;
const char * V_79 ;
T_4 V_57 ;
int V_33 ;
V_33 = F_69 ( V_18 , L_14 , & V_79 ) ;
if ( V_33 )
return NULL ;
if ( F_70 ( V_18 , & V_57 ) )
return NULL ;
V_41 = F_71 ( V_18 ) ;
if ( ! V_41 )
return NULL ;
V_2 = F_42 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_16 = F_72 ( V_79 , V_43 ) ;
if ( ! V_2 -> V_16 ) {
F_12 ( V_2 ) ;
return NULL ;
}
if ( V_18 -> V_23 && F_73 ( V_18 -> V_23 ) )
V_2 -> V_80 = F_74 ( F_73 ( V_18 -> V_23 ) -> V_81 ) ;
else
V_2 -> V_80 = - 1 ;
F_75 ( & V_2 -> V_14 ) ;
V_2 -> V_53 = V_82 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_4 = V_41 -> V_83 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_74 = false ;
V_2 -> V_40 . V_84 = & V_85 ;
V_2 -> V_40 . V_65 = & V_2 -> V_86 ;
V_2 -> V_40 . V_87 = F_66 ;
V_2 -> V_40 . V_54 = V_2 ;
F_76 ( & V_2 -> V_15 ) ;
F_76 ( & V_2 -> V_77 ) ;
return V_2 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_1 * V_24 ;
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned long V_21 ;
int V_33 ;
V_24 = F_18 ( V_2 -> V_18 ) ;
if ( V_24 ) {
F_13 ( V_24 ) ;
return - V_88 ;
}
V_33 = F_78 ( & V_2 -> V_40 , V_2 -> V_41 ,
V_2 -> V_80 , V_2 -> V_16 ) ;
if ( V_33 ) {
F_43 ( & V_2 -> V_4 -> V_44 , L_15 ,
V_33 ) ;
return V_33 ;
}
while ( ( V_18 = F_79 ( V_18 ) ) ) {
if ( ! F_73 ( V_18 ) ) {
F_25 ( V_18 ) ;
break;
}
V_24 = F_18 ( V_18 ) ;
if ( V_24 ) {
F_25 ( V_18 ) ;
break;
}
F_25 ( V_18 ) ;
}
F_19 ( & V_22 , V_21 ) ;
V_2 -> V_24 = V_24 ;
if ( V_24 )
F_80 ( & V_2 -> V_77 , & V_24 -> V_15 ) ;
else
F_80 ( & V_2 -> V_77 , & V_89 ) ;
F_20 ( & V_22 , V_21 ) ;
V_2 -> V_53 = V_72 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_90 V_91 ;
int V_92 , V_33 ;
T_1 V_93 ;
V_92 = F_82 ( V_4 ) ;
if ( V_92 < 0 )
return V_92 ;
F_2 ( V_4 , V_94 , & V_93 ) ;
V_91 . V_91 = ( V_93 & V_95 ) >> 9 ;
if ( V_91 . V_91 >= V_92 )
return - V_96 ;
V_33 = F_83 ( V_4 , & V_91 , 1 ) ;
if ( V_33 ) {
F_43 ( & V_4 -> V_44 , L_16 , V_33 ) ;
return V_33 ;
}
return V_91 . V_97 ;
}
static void F_84 ( struct V_98 * V_99 )
{
struct V_100 * V_101 =
F_9 ( V_99 , struct V_100 , V_99 ) ;
struct V_1 * V_2 = V_101 -> V_2 ;
if ( V_101 -> V_102 )
F_62 ( & V_2 -> V_40 ) ;
else
F_63 ( & V_2 -> V_40 ) ;
F_12 ( V_101 ) ;
}
static T_5 F_85 ( int V_6 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
struct V_3 * V_103 , * V_4 = V_2 -> V_4 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_100 * V_101 ;
T_1 V_108 , V_109 ;
T_3 V_67 ;
bool V_102 ;
unsigned long V_21 ;
int V_33 ;
F_2 ( V_4 , V_110 , & V_108 ) ;
V_108 &= ( V_111 | V_112 ) ;
F_3 ( V_4 , V_110 , V_108 ) ;
if ( V_108 & V_112 ) {
F_2 ( V_4 , V_113 , & V_109 ) ;
V_102 = ! ! ( V_109 & V_114 ) ;
} else if ( V_108 & V_111 ) {
V_33 = F_55 ( V_2 -> V_57 , & V_67 ) ;
if ( ! V_33 )
return V_115 ;
V_102 = ! ! ( V_67 == V_75 ) ;
} else {
return V_116 ;
}
if ( ! V_102 ) {
V_103 = F_86 ( & V_2 -> V_41 -> V_117 ,
struct V_3 , V_118 ) ;
V_105 = V_103 ? F_87 ( V_103 ) : NULL ;
V_107 = V_105 ? V_105 -> V_107 : NULL ;
if ( V_107 ) {
F_88 ( & V_21 ) ;
F_89 ( V_107 , V_119 ) ;
F_90 ( V_21 ) ;
F_91 ( V_107 , V_120 ) ;
}
}
V_101 = F_42 ( sizeof( * V_101 ) , V_121 ) ;
if ( ! V_101 ) {
F_43 ( & V_4 -> V_44 , L_17 ,
V_2 -> V_16 , V_108 ) ;
return V_115 ;
}
F_92 ( & V_4 -> V_44 , L_18 ,
V_2 -> V_16 , V_102 ? L_19 : L_20 , V_6 ) ;
F_93 ( & V_101 -> V_99 , F_84 ) ;
V_101 -> V_102 = V_102 ;
V_101 -> V_2 = V_2 ;
F_94 ( V_2 -> V_11 , & V_101 -> V_99 ) ;
return V_115 ;
}
static void F_95 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_108 , V_5 ;
int V_33 ;
V_2 -> V_11 = F_96 ( L_21 , 0 , 0 , V_2 -> V_16 ) ;
if ( ! V_2 -> V_11 ) {
F_43 ( & V_4 -> V_44 , L_22 ) ;
F_1 ( V_2 ) ;
return;
}
F_2 ( V_4 , V_110 , & V_108 ) ;
V_108 |= ( V_111 | V_112 ) ;
F_3 ( V_4 , V_110 , V_108 ) ;
V_33 = F_97 ( V_6 , F_85 , V_122 ,
V_2 -> V_16 , V_2 ) ;
if ( V_33 ) {
F_1 ( V_2 ) ;
F_43 ( & V_4 -> V_44 , L_23 , V_33 , V_6 ) ;
return;
}
F_2 ( V_4 , V_7 , & V_5 ) ;
V_5 |= ( V_8 |
V_9 |
V_10 ) ;
F_3 ( V_4 , V_7 , V_5 ) ;
V_2 -> V_6 = V_6 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 , V_33 ;
V_33 = F_99 ( V_4 ) ;
if ( V_33 ) {
F_43 ( & V_4 -> V_44 , L_24 , V_33 ) ;
return;
}
F_100 ( V_4 ) ;
V_6 = F_81 ( V_2 ) ;
if ( V_6 > 0 ) {
F_95 ( V_2 , V_6 ) ;
return;
}
V_33 = F_101 ( V_4 ) ;
if ( ! V_33 || V_4 -> V_6 ) {
V_6 = V_4 -> V_6 ;
F_95 ( V_2 , V_6 ) ;
}
}
static int F_102 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
T_6 V_123 ;
int V_33 ;
V_33 = F_103 ( V_18 , L_25 , & V_123 ) ;
if ( V_33 || ! V_123 )
return - V_124 ;
V_33 = F_103 ( V_18 , L_26 , & V_123 ) ;
if ( V_33 || ! V_123 )
return - V_124 ;
V_2 = F_68 ( V_18 ) ;
if ( ! V_2 )
return - V_125 ;
V_33 = F_77 ( V_2 ) ;
if ( V_33 )
goto V_126;
V_33 = F_57 ( V_2 , false ) ;
if ( V_33 )
goto V_127;
V_33 = F_103 ( V_18 , L_27 , & V_123 ) ;
if ( ! V_33 && V_123 )
F_98 ( V_2 ) ;
return 0 ;
V_127:
F_104 ( V_2 -> V_18 ) ;
V_126:
F_13 ( V_2 ) ;
return V_33 ;
}
static void F_61 ( struct V_17 * V_18 )
{
struct V_17 * V_23 ;
F_22 (dn, child) {
F_102 ( V_23 ) ;
F_61 ( V_23 ) ;
}
}
static void F_104 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_18 ) ;
if ( ! V_2 )
return;
V_2 -> V_53 = V_128 ;
F_13 ( V_2 ) ;
F_105 ( & V_2 -> V_40 ) ;
}
static void F_65 ( struct V_17 * V_18 )
{
struct V_17 * V_23 ;
F_22 (dn, child) {
F_65 ( V_23 ) ;
F_104 ( V_23 ) ;
}
}
static int T_7 F_106 ( void )
{
struct V_17 * V_18 ;
F_107 ( V_129 L_28 V_130 L_29 ) ;
F_108 (dn, NULL, L_30 )
F_61 ( V_18 ) ;
return 0 ;
}
static void T_8 F_109 ( void )
{
struct V_17 * V_18 ;
F_108 (dn, NULL, L_30 )
F_65 ( V_18 ) ;
}
