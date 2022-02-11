static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
T_1 V_7 ;
if ( V_2 -> V_6 > 0 ) {
F_2 ( V_5 , V_8 , & V_7 ) ;
V_7 &= ~ ( V_9 |
V_10 |
V_11 ) ;
F_3 ( V_5 , V_8 , V_7 ) ;
F_4 ( V_2 -> V_6 , V_2 ) ;
V_2 -> V_6 = 0 ;
}
if ( V_2 -> V_12 ) {
F_5 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
if ( V_3 || V_6 > 0 ) {
if ( V_5 -> V_13 )
F_6 ( V_5 ) ;
else if ( V_5 -> V_14 )
F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
}
}
static void F_9 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ,
struct V_1 , V_15 ) ;
F_11 ( ! F_12 ( & V_2 -> V_16 ) ) ;
F_1 ( V_2 , false ) ;
F_13 ( V_2 -> V_17 ) ;
F_13 ( V_2 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_15 ( & V_2 -> V_15 , F_9 ) ;
}
static struct V_1 * F_16 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_1 * V_20 , * V_21 ;
if ( V_2 -> V_19 == V_19 ) {
F_17 ( & V_2 -> V_15 ) ;
return V_2 ;
}
F_18 (tmp, &php_slot->children, link) {
V_20 = F_16 ( V_19 , V_21 ) ;
if ( V_20 )
return V_20 ;
}
return NULL ;
}
struct V_1 * F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 , * V_21 ;
unsigned long V_22 ;
F_20 ( & V_23 , V_22 ) ;
F_18 (tmp, &pnv_php_slot_list, link) {
V_2 = F_16 ( V_19 , V_21 ) ;
if ( V_2 ) {
F_21 ( & V_23 , V_22 ) ;
return V_2 ;
}
}
F_21 ( & V_23 , V_22 ) ;
return NULL ;
}
static void F_22 ( struct V_18 * V_19 )
{
struct V_18 * V_24 ;
F_23 (dn, child) {
F_22 ( V_24 ) ;
F_24 ( V_24 ) ;
}
}
static void F_25 ( struct V_18 * V_25 )
{
struct V_18 * V_19 ;
int V_26 ;
F_23 (parent, dn) {
F_25 ( V_19 ) ;
F_26 ( V_19 ) ;
V_26 = F_27 ( & V_19 -> V_27 . V_15 ) ;
if ( V_26 != 1 )
F_28 ( L_1 ,
V_26 , F_29 ( V_19 ) ) ;
F_30 ( V_19 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_19 ) ;
if ( V_2 -> V_28 )
F_32 ( & V_2 -> V_29 ) ;
F_25 ( V_2 -> V_19 ) ;
if ( V_2 -> V_28 ) {
F_13 ( V_2 -> V_30 ) ;
F_13 ( V_2 -> V_28 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_19 -> V_24 = NULL ;
V_2 -> V_28 = NULL ;
}
}
static void F_33 ( struct V_18 * V_25 )
{
struct V_18 * V_24 , * V_31 ;
F_23 (parent, child)
F_33 ( V_24 ) ;
V_24 = V_25 -> V_24 ;
V_25 -> V_24 = NULL ;
while ( V_24 ) {
V_31 = V_24 -> V_32 ;
V_24 -> V_32 = V_25 -> V_24 ;
V_25 -> V_24 = V_24 ;
V_24 = V_31 ;
}
}
static int F_34 ( struct V_33 * V_29 ,
struct V_18 * V_19 )
{
struct V_18 * V_24 ;
int V_34 = 0 ;
F_23 (dn, child) {
V_34 = F_35 ( V_29 , V_24 ) ;
if ( V_34 )
break;
V_34 = F_34 ( V_29 , V_24 ) ;
if ( V_34 )
break;
}
return V_34 ;
}
static void * F_36 ( struct V_18 * V_19 , void * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
struct V_38 * V_39 ;
V_39 = F_37 ( V_37 , V_19 ) ;
if ( ! V_39 )
return F_38 ( - V_40 ) ;
return NULL ;
}
static void F_39 ( struct V_1 * V_41 )
{
struct V_36 * V_37 = F_40 ( V_41 -> V_42 ) ;
F_41 ( V_41 -> V_19 , F_36 , V_37 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
void * V_28 , * V_43 , * V_30 ;
int V_34 ;
V_43 = F_43 ( 0x10000 , V_44 ) ;
if ( ! V_43 ) {
V_34 = - V_40 ;
F_44 ( & V_2 -> V_5 -> V_45 , L_2 ) ;
goto V_46;
}
V_34 = F_45 ( V_2 -> V_19 -> V_47 , V_43 , 0x10000 ) ;
if ( V_34 ) {
F_44 ( & V_2 -> V_5 -> V_45 , L_3 ,
V_34 ) ;
goto V_48;
}
V_28 = F_43 ( F_46 ( V_43 ) , V_44 ) ;
if ( ! V_28 ) {
V_34 = - V_40 ;
F_44 ( & V_2 -> V_5 -> V_45 , L_4 ,
F_46 ( V_43 ) ) ;
goto V_48;
}
memcpy ( V_28 , V_43 , F_46 ( V_43 ) ) ;
V_30 = F_47 ( V_28 , V_2 -> V_19 , NULL ) ;
if ( ! V_30 ) {
V_34 = - V_49 ;
F_44 ( & V_2 -> V_5 -> V_45 , L_5 ) ;
goto V_50;
}
F_48 ( & V_2 -> V_29 ) ;
F_33 ( V_2 -> V_19 ) ;
V_34 = F_34 ( & V_2 -> V_29 , V_2 -> V_19 ) ;
if ( V_34 ) {
F_33 ( V_2 -> V_19 ) ;
F_44 ( & V_2 -> V_5 -> V_45 , L_6 ,
V_34 ) ;
goto V_51;
}
V_2 -> V_19 -> V_24 = NULL ;
V_34 = F_49 ( & V_2 -> V_29 ) ;
if ( V_34 ) {
F_44 ( & V_2 -> V_5 -> V_45 , L_7 ,
V_34 ) ;
goto V_52;
}
F_39 ( V_2 ) ;
V_2 -> V_28 = V_28 ;
V_2 -> V_30 = V_30 ;
F_13 ( V_43 ) ;
goto V_46;
V_52:
F_32 ( & V_2 -> V_29 ) ;
V_51:
F_13 ( V_30 ) ;
V_2 -> V_19 -> V_24 = NULL ;
V_50:
F_13 ( V_28 ) ;
V_48:
F_13 ( V_43 ) ;
V_46:
return V_34 ;
}
int F_50 ( struct V_53 * V_41 ,
T_2 V_54 )
{
struct V_1 * V_2 = V_41 -> V_55 ;
struct V_56 V_57 ;
int V_34 ;
V_34 = F_51 ( V_2 -> V_58 , V_54 , & V_57 ) ;
if ( V_34 > 0 ) {
if ( F_52 ( V_57 . V_59 [ 1 ] ) != V_2 -> V_19 -> V_47 ||
F_52 ( V_57 . V_59 [ 2 ] ) != V_54 ||
F_52 ( V_57 . V_59 [ 3 ] ) != V_60 ) {
F_44 ( & V_2 -> V_5 -> V_45 , L_8 ,
F_52 ( V_57 . V_59 [ 1 ] ) ,
F_52 ( V_57 . V_59 [ 2 ] ) ,
F_52 ( V_57 . V_59 [ 3 ] ) ) ;
return - V_61 ;
}
} else if ( V_34 < 0 ) {
F_44 ( & V_2 -> V_5 -> V_45 , L_9 ,
V_34 , ( V_54 == V_62 ) ? L_10 : L_11 ) ;
return V_34 ;
}
if ( V_54 == V_63 || V_54 == V_64 )
F_31 ( V_2 ) ;
else
V_34 = F_42 ( V_2 ) ;
return V_34 ;
}
static int F_53 ( struct V_53 * V_41 , T_3 * V_54 )
{
struct V_1 * V_2 = V_41 -> V_55 ;
T_2 V_65 = V_62 ;
int V_34 ;
V_34 = F_54 ( V_2 -> V_58 , & V_65 ) ;
if ( V_34 ) {
F_44 ( & V_2 -> V_5 -> V_45 , L_12 ,
V_34 ) ;
} else {
* V_54 = V_65 ;
V_41 -> V_66 -> V_67 = V_65 ;
}
return 0 ;
}
static int F_55 ( struct V_53 * V_41 , T_3 * V_54 )
{
struct V_1 * V_2 = V_41 -> V_55 ;
T_2 V_68 = V_69 ;
int V_34 ;
V_34 = F_56 ( V_2 -> V_58 , & V_68 ) ;
if ( V_34 >= 0 ) {
* V_54 = V_68 ;
V_41 -> V_66 -> V_70 = V_68 ;
V_34 = 0 ;
} else {
F_44 ( & V_2 -> V_5 -> V_45 , L_13 ,
V_34 ) ;
}
return V_34 ;
}
static int F_57 ( struct V_53 * V_41 , T_3 V_54 )
{
V_41 -> V_66 -> V_71 = V_54 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , bool V_72 )
{
struct V_53 * V_41 = & V_2 -> V_41 ;
T_2 V_68 = V_69 ;
T_2 V_67 = V_62 ;
int V_34 ;
if ( V_2 -> V_54 != V_73 )
return 0 ;
V_34 = F_55 ( V_41 , & V_68 ) ;
if ( V_34 )
return V_34 ;
if ( V_68 == V_69 ) {
if ( ! V_2 -> V_74 ) {
V_2 -> V_74 = true ;
return 0 ;
}
goto V_75;
}
if ( ! V_2 -> V_74 ) {
V_2 -> V_74 = true ;
V_34 = F_53 ( V_41 , & V_67 ) ;
if ( V_34 )
return V_34 ;
if ( V_67 != V_62 )
return 0 ;
}
V_34 = F_53 ( V_41 , & V_67 ) ;
if ( V_34 )
return V_34 ;
if ( V_67 == V_62 )
goto V_75;
V_34 = F_50 ( V_41 , V_62 ) ;
if ( V_34 )
return V_34 ;
V_75:
if ( V_68 == V_76 ) {
if ( V_72 ) {
F_59 () ;
F_60 ( V_2 -> V_42 ) ;
F_61 () ;
}
V_2 -> V_54 = V_77 ;
if ( V_72 )
F_62 ( V_2 -> V_19 ) ;
} else {
V_2 -> V_54 = V_77 ;
}
return 0 ;
}
static int F_63 ( struct V_53 * V_41 )
{
struct V_1 * V_2 = F_10 ( V_41 ,
struct V_1 , V_41 ) ;
return F_58 ( V_2 , true ) ;
}
static int F_64 ( struct V_53 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_55 ;
int V_34 ;
if ( V_2 -> V_54 != V_77 )
return 0 ;
F_59 () ;
F_65 ( V_2 -> V_42 ) ;
F_61 () ;
F_66 ( V_2 -> V_19 ) ;
V_34 = F_50 ( V_41 , V_63 ) ;
V_2 -> V_54 = V_73 ;
return V_34 ;
}
static void F_67 ( struct V_53 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_55 ;
unsigned long V_22 ;
F_20 ( & V_23 , V_22 ) ;
F_68 ( & V_2 -> V_78 ) ;
F_21 ( & V_23 , V_22 ) ;
F_14 ( V_2 ) ;
F_14 ( V_2 -> V_25 ) ;
}
static struct V_1 * F_69 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_79 * V_42 ;
const char * V_80 ;
T_4 V_58 ;
int V_34 ;
V_34 = F_70 ( V_19 , L_14 , & V_80 ) ;
if ( V_34 )
return NULL ;
if ( F_71 ( V_19 , & V_58 ) )
return NULL ;
V_42 = F_72 ( V_19 ) ;
if ( ! V_42 )
return NULL ;
V_2 = F_43 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_17 = F_73 ( V_80 , V_44 ) ;
if ( ! V_2 -> V_17 ) {
F_13 ( V_2 ) ;
return NULL ;
}
if ( V_19 -> V_24 && F_74 ( V_19 -> V_24 ) )
V_2 -> V_81 = F_75 ( F_74 ( V_19 -> V_24 ) -> V_82 ) ;
else
V_2 -> V_81 = - 1 ;
F_76 ( & V_2 -> V_15 ) ;
V_2 -> V_54 = V_83 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_42 -> V_84 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_74 = false ;
V_2 -> V_41 . V_85 = & V_86 ;
V_2 -> V_41 . V_66 = & V_2 -> V_87 ;
V_2 -> V_41 . V_88 = F_67 ;
V_2 -> V_41 . V_55 = V_2 ;
F_77 ( & V_2 -> V_16 ) ;
F_77 ( & V_2 -> V_78 ) ;
return V_2 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_1 * V_25 ;
struct V_18 * V_19 = V_2 -> V_19 ;
unsigned long V_22 ;
int V_34 ;
V_25 = F_19 ( V_2 -> V_19 ) ;
if ( V_25 ) {
F_14 ( V_25 ) ;
return - V_89 ;
}
V_34 = F_79 ( & V_2 -> V_41 , V_2 -> V_42 ,
V_2 -> V_81 , V_2 -> V_17 ) ;
if ( V_34 ) {
F_44 ( & V_2 -> V_5 -> V_45 , L_15 ,
V_34 ) ;
return V_34 ;
}
while ( ( V_19 = F_80 ( V_19 ) ) ) {
if ( ! F_74 ( V_19 ) ) {
F_26 ( V_19 ) ;
break;
}
V_25 = F_19 ( V_19 ) ;
if ( V_25 ) {
F_26 ( V_19 ) ;
break;
}
F_26 ( V_19 ) ;
}
F_20 ( & V_23 , V_22 ) ;
V_2 -> V_25 = V_25 ;
if ( V_25 )
F_81 ( & V_2 -> V_78 , & V_25 -> V_16 ) ;
else
F_81 ( & V_2 -> V_78 , & V_90 ) ;
F_21 ( & V_23 , V_22 ) ;
V_2 -> V_54 = V_73 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_91 V_92 ;
int V_93 , V_34 ;
T_1 V_94 ;
V_93 = F_83 ( V_5 ) ;
if ( V_93 < 0 )
return V_93 ;
F_2 ( V_5 , V_95 , & V_94 ) ;
V_92 . V_92 = ( V_94 & V_96 ) >> 9 ;
if ( V_92 . V_92 >= V_93 )
return - V_97 ;
V_34 = F_84 ( V_5 , & V_92 , 1 ) ;
if ( V_34 ) {
F_44 ( & V_5 -> V_45 , L_16 , V_34 ) ;
return V_34 ;
}
return V_92 . V_98 ;
}
static void F_85 ( struct V_99 * V_100 )
{
struct V_101 * V_102 =
F_10 ( V_100 , struct V_101 , V_100 ) ;
struct V_1 * V_2 = V_102 -> V_2 ;
if ( V_102 -> V_103 )
F_63 ( & V_2 -> V_41 ) ;
else
F_64 ( & V_2 -> V_41 ) ;
F_13 ( V_102 ) ;
}
static T_5 F_86 ( int V_6 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
struct V_4 * V_104 , * V_5 = V_2 -> V_5 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_101 * V_102 ;
T_1 V_109 , V_110 ;
T_3 V_68 ;
bool V_103 ;
unsigned long V_22 ;
int V_34 ;
F_2 ( V_5 , V_111 , & V_109 ) ;
V_109 &= ( V_112 | V_113 ) ;
F_3 ( V_5 , V_111 , V_109 ) ;
if ( V_109 & V_113 ) {
F_2 ( V_5 , V_114 , & V_110 ) ;
V_103 = ! ! ( V_110 & V_115 ) ;
} else if ( ! ( V_2 -> V_22 & V_116 ) &&
( V_109 & V_112 ) ) {
V_34 = F_56 ( V_2 -> V_58 , & V_68 ) ;
if ( V_34 ) {
F_44 ( & V_5 -> V_45 , L_17 ,
V_2 -> V_17 , V_34 , V_109 ) ;
return V_117 ;
}
V_103 = ! ! ( V_68 == V_76 ) ;
} else {
return V_118 ;
}
if ( ! V_103 ) {
V_104 = F_87 ( & V_2 -> V_42 -> V_119 ,
struct V_4 , V_120 ) ;
V_106 = V_104 ? F_88 ( V_104 ) : NULL ;
V_108 = V_106 ? V_106 -> V_108 : NULL ;
if ( V_108 ) {
F_89 ( & V_22 ) ;
F_90 ( V_108 , V_121 ) ;
F_91 ( V_22 ) ;
F_92 ( V_108 , V_122 ) ;
}
}
V_102 = F_43 ( sizeof( * V_102 ) , V_123 ) ;
if ( ! V_102 ) {
F_44 ( & V_5 -> V_45 , L_18 ,
V_2 -> V_17 , V_109 ) ;
return V_117 ;
}
F_93 ( & V_5 -> V_45 , L_19 ,
V_2 -> V_17 , V_103 ? L_20 : L_21 , V_6 ) ;
F_94 ( & V_102 -> V_100 , F_85 ) ;
V_102 -> V_103 = V_103 ;
V_102 -> V_2 = V_2 ;
F_95 ( V_2 -> V_12 , & V_102 -> V_100 ) ;
return V_117 ;
}
static void F_96 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_6 V_124 = 0 ;
T_1 V_109 , V_7 ;
int V_34 ;
V_2 -> V_12 = F_97 ( L_22 , 0 , 0 , V_2 -> V_17 ) ;
if ( ! V_2 -> V_12 ) {
F_44 ( & V_5 -> V_45 , L_23 ) ;
F_1 ( V_2 , true ) ;
return;
}
V_34 = F_98 ( V_2 -> V_19 , L_24 ,
& V_124 ) ;
if ( ! V_34 && V_124 )
V_2 -> V_22 |= V_116 ;
F_2 ( V_5 , V_111 , & V_109 ) ;
if ( V_2 -> V_22 & V_116 )
V_109 |= V_113 ;
else
V_109 |= ( V_112 | V_113 ) ;
F_3 ( V_5 , V_111 , V_109 ) ;
V_34 = F_99 ( V_6 , F_86 , V_125 ,
V_2 -> V_17 , V_2 ) ;
if ( V_34 ) {
F_1 ( V_2 , true ) ;
F_44 ( & V_5 -> V_45 , L_25 , V_34 , V_6 ) ;
return;
}
F_2 ( V_5 , V_8 , & V_7 ) ;
if ( V_2 -> V_22 & V_116 ) {
V_7 &= ~ V_10 ;
V_7 |= ( V_9 |
V_11 ) ;
} else {
V_7 |= ( V_9 |
V_10 |
V_11 ) ;
}
F_3 ( V_5 , V_8 , V_7 ) ;
V_2 -> V_6 = V_6 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_34 ;
if ( F_101 ( V_5 ) )
return;
V_34 = F_102 ( V_5 ) ;
if ( V_34 ) {
F_44 ( & V_5 -> V_45 , L_26 , V_34 ) ;
return;
}
F_103 ( V_5 ) ;
V_6 = F_82 ( V_2 ) ;
if ( V_6 > 0 ) {
F_96 ( V_2 , V_6 ) ;
return;
}
V_34 = F_104 ( V_5 ) ;
if ( ! V_34 || V_5 -> V_6 ) {
V_6 = V_5 -> V_6 ;
F_96 ( V_2 , V_6 ) ;
}
}
static int F_105 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
T_6 V_126 ;
int V_34 ;
V_34 = F_98 ( V_19 , L_27 , & V_126 ) ;
if ( V_34 || ! V_126 )
return - V_127 ;
V_34 = F_98 ( V_19 , L_28 , & V_126 ) ;
if ( V_34 || ! V_126 )
return - V_127 ;
V_2 = F_69 ( V_19 ) ;
if ( ! V_2 )
return - V_128 ;
V_34 = F_78 ( V_2 ) ;
if ( V_34 )
goto V_129;
V_34 = F_58 ( V_2 , false ) ;
if ( V_34 )
goto V_130;
V_34 = F_98 ( V_19 , L_29 , & V_126 ) ;
if ( ! V_34 && V_126 )
F_100 ( V_2 ) ;
return 0 ;
V_130:
F_106 ( V_2 -> V_19 ) ;
V_129:
F_14 ( V_2 ) ;
return V_34 ;
}
static void F_62 ( struct V_18 * V_19 )
{
struct V_18 * V_24 ;
F_23 (dn, child) {
F_105 ( V_24 ) ;
F_62 ( V_24 ) ;
}
}
static void F_106 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( V_19 ) ;
if ( ! V_2 )
return;
V_2 -> V_54 = V_131 ;
F_14 ( V_2 ) ;
F_107 ( & V_2 -> V_41 ) ;
}
static void F_66 ( struct V_18 * V_19 )
{
struct V_18 * V_24 ;
F_23 (dn, child) {
F_66 ( V_24 ) ;
F_106 ( V_24 ) ;
}
}
static int T_7 F_108 ( void )
{
struct V_18 * V_19 ;
F_109 ( V_132 L_30 V_133 L_31 ) ;
F_110 (dn, NULL, L_32 )
F_62 ( V_19 ) ;
return 0 ;
}
static void T_8 F_111 ( void )
{
struct V_18 * V_19 ;
F_110 (dn, NULL, L_32 )
F_66 ( V_19 ) ;
}
