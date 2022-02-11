static struct V_1 * F_1 ( union V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
F_2 (tl, &bpf_map_types, list_node) {
if ( V_5 -> type == V_3 -> V_7 ) {
V_6 = V_5 -> V_8 -> V_9 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
V_6 -> V_8 = V_5 -> V_8 ;
V_6 -> V_7 = V_3 -> V_7 ;
return V_6 ;
}
}
return F_4 ( - V_10 ) ;
}
void F_5 ( struct V_4 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_12 ) ;
}
void * F_7 ( T_1 V_13 )
{
const T_2 V_14 = V_15 | V_16 | V_17 ;
void * V_18 ;
if ( V_13 <= ( V_19 << V_20 ) ) {
V_18 = F_8 ( V_13 , V_21 | V_14 ) ;
if ( V_18 != NULL )
return V_18 ;
}
return F_9 ( V_13 , V_22 | V_23 | V_14 ,
V_24 ) ;
}
void F_10 ( void * V_18 )
{
F_11 ( V_18 ) ;
}
int F_12 ( T_3 V_25 )
{
struct V_26 * V_27 = F_13 () ;
unsigned long V_28 , V_29 ;
V_28 = F_14 ( V_30 ) >> V_31 ;
V_29 = F_15 ( & V_27 -> V_32 ) ;
F_16 ( V_27 ) ;
if ( V_29 + V_25 > V_28 )
return - V_33 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_6 )
{
struct V_26 * V_27 = F_13 () ;
unsigned long V_28 ;
V_28 = F_14 ( V_30 ) >> V_31 ;
F_18 ( V_6 -> V_25 , & V_27 -> V_32 ) ;
if ( F_15 ( & V_27 -> V_32 ) > V_28 ) {
F_19 ( V_6 -> V_25 , & V_27 -> V_32 ) ;
F_16 ( V_27 ) ;
return - V_33 ;
}
V_6 -> V_27 = V_27 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_6 )
{
struct V_26 * V_27 = V_6 -> V_27 ;
F_19 ( V_6 -> V_25 , & V_27 -> V_32 ) ;
F_16 ( V_27 ) ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_1 * V_6 = F_22 ( V_35 , struct V_1 , V_35 ) ;
F_20 ( V_6 ) ;
V_6 -> V_8 -> V_36 ( V_6 ) ;
}
static void F_23 ( struct V_1 * V_6 )
{
if ( F_24 ( & V_6 -> V_37 ) ) {
if ( V_6 -> V_7 == V_38 )
F_25 ( V_6 ) ;
}
}
void F_26 ( struct V_1 * V_6 )
{
if ( F_24 ( & V_6 -> V_39 ) ) {
F_27 ( & V_6 -> V_35 , F_21 ) ;
F_28 ( & V_6 -> V_35 ) ;
}
}
void F_29 ( struct V_1 * V_6 )
{
F_23 ( V_6 ) ;
F_26 ( V_6 ) ;
}
static int F_30 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_6 = V_42 -> V_43 ;
if ( V_6 -> V_8 -> V_44 )
V_6 -> V_8 -> V_44 ( V_6 , V_42 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
static void F_31 ( struct V_45 * V_46 , struct V_41 * V_42 )
{
const struct V_1 * V_6 = V_42 -> V_43 ;
const struct V_47 * V_48 ;
T_3 V_49 = 0 ;
if ( V_6 -> V_7 == V_38 ) {
V_48 = F_22 ( V_6 , struct V_47 , V_6 ) ;
V_49 = V_48 -> V_49 ;
}
F_32 ( V_46 ,
L_1
L_2
L_3
L_4
L_5
L_6 ,
V_6 -> V_7 ,
V_6 -> V_50 ,
V_6 -> V_51 ,
V_6 -> V_52 ,
V_6 -> V_53 ,
V_6 -> V_25 * 1ULL << V_31 ) ;
if ( V_49 )
F_32 ( V_46 , L_7 ,
V_49 ) ;
}
int F_33 ( struct V_1 * V_6 )
{
return F_34 ( L_8 , & V_54 , V_6 ,
V_55 | V_56 ) ;
}
static int F_35 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_57 ;
V_57 = F_36 ( V_58 ) ;
if ( V_57 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_37 ( V_6 ) ;
F_38 ( & V_6 -> V_39 , 1 ) ;
F_38 ( & V_6 -> V_37 , 1 ) ;
V_57 = F_17 ( V_6 ) ;
if ( V_57 )
goto V_59;
V_57 = F_33 ( V_6 ) ;
if ( V_57 < 0 )
goto V_60;
return V_57 ;
V_60:
F_20 ( V_6 ) ;
V_59:
V_6 -> V_8 -> V_36 ( V_6 ) ;
return V_57 ;
}
struct V_1 * F_39 ( struct V_61 V_62 )
{
if ( ! V_62 . V_41 )
return F_4 ( - V_63 ) ;
if ( V_62 . V_41 -> V_64 != & V_54 ) {
F_40 ( V_62 ) ;
return F_4 ( - V_10 ) ;
}
return V_62 . V_41 -> V_43 ;
}
struct V_1 * F_41 ( struct V_1 * V_6 , bool V_65 )
{
if ( F_42 ( & V_6 -> V_39 ) > V_66 ) {
F_43 ( & V_6 -> V_39 ) ;
return F_4 ( - V_67 ) ;
}
if ( V_65 )
F_44 ( & V_6 -> V_37 ) ;
return V_6 ;
}
struct V_1 * F_45 ( T_3 V_68 )
{
struct V_61 V_62 = F_46 ( V_68 ) ;
struct V_1 * V_6 ;
V_6 = F_39 ( V_62 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
V_6 = F_41 ( V_6 , true ) ;
F_40 ( V_62 ) ;
return V_6 ;
}
int __weak F_47 ( struct V_1 * V_6 , void * V_69 , void * V_70 )
{
return - V_71 ;
}
static int F_48 ( union V_2 * V_3 )
{
void T_4 * V_72 = F_49 ( V_3 -> V_69 ) ;
void T_4 * V_73 = F_49 ( V_3 -> V_70 ) ;
int V_68 = V_3 -> V_74 ;
struct V_1 * V_6 ;
void * V_69 , * V_70 , * V_75 ;
T_3 V_51 ;
struct V_61 V_62 ;
int V_57 ;
if ( F_36 ( V_76 ) )
return - V_10 ;
V_62 = F_46 ( V_68 ) ;
V_6 = F_39 ( V_62 ) ;
if ( F_3 ( V_6 ) )
return F_37 ( V_6 ) ;
V_57 = - V_77 ;
V_69 = F_8 ( V_6 -> V_50 , V_21 ) ;
if ( ! V_69 )
goto V_78;
V_57 = - V_79 ;
if ( F_50 ( V_69 , V_72 , V_6 -> V_50 ) != 0 )
goto V_80;
if ( V_6 -> V_7 == V_81 ||
V_6 -> V_7 == V_82 ||
V_6 -> V_7 == V_83 )
V_51 = F_51 ( V_6 -> V_51 , 8 ) * F_52 () ;
else
V_51 = V_6 -> V_51 ;
V_57 = - V_77 ;
V_70 = F_8 ( V_51 , V_21 | V_15 ) ;
if ( ! V_70 )
goto V_80;
if ( V_6 -> V_7 == V_81 ||
V_6 -> V_7 == V_82 ) {
V_57 = F_53 ( V_6 , V_69 , V_70 ) ;
} else if ( V_6 -> V_7 == V_83 ) {
V_57 = F_54 ( V_6 , V_69 , V_70 ) ;
} else if ( V_6 -> V_7 == V_84 ) {
V_57 = F_47 ( V_6 , V_69 , V_70 ) ;
} else {
F_55 () ;
V_75 = V_6 -> V_8 -> F_48 ( V_6 , V_69 ) ;
if ( V_75 )
memcpy ( V_70 , V_75 , V_51 ) ;
F_56 () ;
V_57 = V_75 ? 0 : - V_85 ;
}
if ( V_57 )
goto V_86;
V_57 = - V_79 ;
if ( F_57 ( V_73 , V_70 , V_51 ) != 0 )
goto V_86;
V_57 = 0 ;
V_86:
F_58 ( V_70 ) ;
V_80:
F_58 ( V_69 ) ;
V_78:
F_40 ( V_62 ) ;
return V_57 ;
}
static int F_59 ( union V_2 * V_3 )
{
void T_4 * V_72 = F_49 ( V_3 -> V_69 ) ;
void T_4 * V_73 = F_49 ( V_3 -> V_70 ) ;
int V_68 = V_3 -> V_74 ;
struct V_1 * V_6 ;
void * V_69 , * V_70 ;
T_3 V_51 ;
struct V_61 V_62 ;
int V_57 ;
if ( F_36 ( V_87 ) )
return - V_10 ;
V_62 = F_46 ( V_68 ) ;
V_6 = F_39 ( V_62 ) ;
if ( F_3 ( V_6 ) )
return F_37 ( V_6 ) ;
V_57 = - V_77 ;
V_69 = F_8 ( V_6 -> V_50 , V_21 ) ;
if ( ! V_69 )
goto V_78;
V_57 = - V_79 ;
if ( F_50 ( V_69 , V_72 , V_6 -> V_50 ) != 0 )
goto V_80;
if ( V_6 -> V_7 == V_81 ||
V_6 -> V_7 == V_82 ||
V_6 -> V_7 == V_83 )
V_51 = F_51 ( V_6 -> V_51 , 8 ) * F_52 () ;
else
V_51 = V_6 -> V_51 ;
V_57 = - V_77 ;
V_70 = F_8 ( V_51 , V_21 | V_15 ) ;
if ( ! V_70 )
goto V_80;
V_57 = - V_79 ;
if ( F_50 ( V_70 , V_73 , V_51 ) != 0 )
goto V_86;
F_60 () ;
F_61 ( V_88 ) ;
if ( V_6 -> V_7 == V_81 ||
V_6 -> V_7 == V_82 ) {
V_57 = F_62 ( V_6 , V_69 , V_70 , V_3 -> V_14 ) ;
} else if ( V_6 -> V_7 == V_83 ) {
V_57 = F_63 ( V_6 , V_69 , V_70 , V_3 -> V_14 ) ;
} else if ( V_6 -> V_7 == V_89 ||
V_6 -> V_7 == V_38 ||
V_6 -> V_7 == V_90 ) {
F_55 () ;
V_57 = F_64 ( V_6 , V_62 . V_41 , V_69 , V_70 ,
V_3 -> V_14 ) ;
F_56 () ;
} else {
F_55 () ;
V_57 = V_6 -> V_8 -> F_59 ( V_6 , V_69 , V_70 , V_3 -> V_14 ) ;
F_56 () ;
}
F_65 ( V_88 ) ;
F_66 () ;
V_86:
F_58 ( V_70 ) ;
V_80:
F_58 ( V_69 ) ;
V_78:
F_40 ( V_62 ) ;
return V_57 ;
}
static int F_67 ( union V_2 * V_3 )
{
void T_4 * V_72 = F_49 ( V_3 -> V_69 ) ;
int V_68 = V_3 -> V_74 ;
struct V_1 * V_6 ;
struct V_61 V_62 ;
void * V_69 ;
int V_57 ;
if ( F_36 ( V_91 ) )
return - V_10 ;
V_62 = F_46 ( V_68 ) ;
V_6 = F_39 ( V_62 ) ;
if ( F_3 ( V_6 ) )
return F_37 ( V_6 ) ;
V_57 = - V_77 ;
V_69 = F_8 ( V_6 -> V_50 , V_21 ) ;
if ( ! V_69 )
goto V_78;
V_57 = - V_79 ;
if ( F_50 ( V_69 , V_72 , V_6 -> V_50 ) != 0 )
goto V_80;
F_60 () ;
F_61 ( V_88 ) ;
F_55 () ;
V_57 = V_6 -> V_8 -> F_67 ( V_6 , V_69 ) ;
F_56 () ;
F_65 ( V_88 ) ;
F_66 () ;
V_80:
F_58 ( V_69 ) ;
V_78:
F_40 ( V_62 ) ;
return V_57 ;
}
static int F_68 ( union V_2 * V_3 )
{
void T_4 * V_72 = F_49 ( V_3 -> V_69 ) ;
void T_4 * V_92 = F_49 ( V_3 -> V_93 ) ;
int V_68 = V_3 -> V_74 ;
struct V_1 * V_6 ;
void * V_69 , * V_93 ;
struct V_61 V_62 ;
int V_57 ;
if ( F_36 ( V_94 ) )
return - V_10 ;
V_62 = F_46 ( V_68 ) ;
V_6 = F_39 ( V_62 ) ;
if ( F_3 ( V_6 ) )
return F_37 ( V_6 ) ;
V_57 = - V_77 ;
V_69 = F_8 ( V_6 -> V_50 , V_21 ) ;
if ( ! V_69 )
goto V_78;
V_57 = - V_79 ;
if ( F_50 ( V_69 , V_72 , V_6 -> V_50 ) != 0 )
goto V_80;
V_57 = - V_77 ;
V_93 = F_8 ( V_6 -> V_50 , V_21 ) ;
if ( ! V_93 )
goto V_80;
F_55 () ;
V_57 = V_6 -> V_8 -> F_68 ( V_6 , V_69 , V_93 ) ;
F_56 () ;
if ( V_57 )
goto V_95;
V_57 = - V_79 ;
if ( F_57 ( V_92 , V_93 , V_6 -> V_50 ) != 0 )
goto V_95;
V_57 = 0 ;
V_95:
F_58 ( V_93 ) ;
V_80:
F_58 ( V_69 ) ;
V_78:
F_40 ( V_62 ) ;
return V_57 ;
}
static int F_69 ( enum V_96 type , struct V_97 * V_98 )
{
struct V_99 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_98 -> V_100 -> V_8 = V_5 -> V_8 ;
V_98 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_70 ( struct V_99 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_101 ) ;
}
static void F_71 ( struct V_97 * V_98 )
{
const struct V_102 * V_103 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_98 -> V_105 ; V_104 ++ ) {
struct V_106 * V_107 = & V_98 -> V_108 [ V_104 ] ;
if ( V_107 -> V_109 == ( V_110 | V_111 ) ) {
F_72 ( ! V_98 -> V_100 -> V_8 -> V_112 ) ;
if ( V_107 -> V_113 == V_114 )
V_98 -> V_115 = 1 ;
if ( V_107 -> V_113 == V_116 )
F_73 () ;
if ( V_107 -> V_113 == V_117 )
V_98 -> V_118 = 1 ;
if ( V_107 -> V_113 == V_119 ) {
V_107 -> V_113 = 0 ;
V_107 -> V_109 |= V_120 ;
continue;
}
V_103 = V_98 -> V_100 -> V_8 -> V_112 ( V_107 -> V_113 ) ;
F_72 ( ! V_103 -> V_121 ) ;
V_107 -> V_113 = V_103 -> V_121 - V_122 ;
}
}
}
static void F_74 ( struct V_123 * V_100 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_100 -> V_124 ; V_104 ++ )
F_26 ( V_100 -> V_125 [ V_104 ] ) ;
F_58 ( V_100 -> V_125 ) ;
}
int F_75 ( struct V_26 * V_27 , T_3 V_25 )
{
unsigned long V_28 = F_14 ( V_30 ) >> V_31 ;
unsigned long V_126 ;
if ( V_27 ) {
V_126 = F_76 ( V_25 , & V_27 -> V_32 ) ;
if ( V_126 > V_28 ) {
F_19 ( V_25 , & V_27 -> V_32 ) ;
return - V_33 ;
}
}
return 0 ;
}
void F_77 ( struct V_26 * V_27 , T_3 V_25 )
{
if ( V_27 )
F_19 ( V_25 , & V_27 -> V_32 ) ;
}
static int F_78 ( struct V_97 * V_98 )
{
struct V_26 * V_27 = F_13 () ;
int V_127 ;
V_127 = F_75 ( V_27 , V_98 -> V_25 ) ;
if ( V_127 ) {
F_16 ( V_27 ) ;
return V_127 ;
}
V_98 -> V_100 -> V_27 = V_27 ;
return 0 ;
}
static void F_79 ( struct V_97 * V_98 )
{
struct V_26 * V_27 = V_98 -> V_100 -> V_27 ;
F_77 ( V_27 , V_98 -> V_25 ) ;
F_16 ( V_27 ) ;
}
static void F_80 ( struct V_128 * V_129 )
{
struct V_123 * V_100 = F_22 ( V_129 , struct V_123 , V_129 ) ;
F_74 ( V_100 ) ;
F_79 ( V_100 -> V_98 ) ;
F_81 ( V_100 -> V_98 ) ;
}
void F_82 ( struct V_97 * V_98 )
{
if ( F_24 ( & V_98 -> V_100 -> V_39 ) )
F_83 ( & V_98 -> V_100 -> V_129 , F_80 ) ;
}
static int F_84 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_97 * V_98 = V_42 -> V_43 ;
F_82 ( V_98 ) ;
return 0 ;
}
static void F_85 ( struct V_45 * V_46 , struct V_41 * V_42 )
{
const struct V_97 * V_98 = V_42 -> V_43 ;
char V_130 [ sizeof( V_98 -> V_131 ) * 2 + 1 ] = { } ;
F_86 ( V_130 , V_98 -> V_131 , sizeof( V_98 -> V_131 ) ) ;
F_32 ( V_46 ,
L_9
L_10
L_11
L_6 ,
V_98 -> type ,
V_98 -> V_132 ,
V_130 ,
V_98 -> V_25 * 1ULL << V_31 ) ;
}
int F_87 ( struct V_97 * V_98 )
{
return F_34 ( L_12 , & V_133 , V_98 ,
V_55 | V_56 ) ;
}
static struct V_97 * F_88 ( struct V_61 V_62 )
{
if ( ! V_62 . V_41 )
return F_4 ( - V_63 ) ;
if ( V_62 . V_41 -> V_64 != & V_133 ) {
F_40 ( V_62 ) ;
return F_4 ( - V_10 ) ;
}
return V_62 . V_41 -> V_43 ;
}
struct V_97 * F_89 ( struct V_97 * V_98 , int V_104 )
{
if ( F_90 ( V_104 , & V_98 -> V_100 -> V_39 ) > V_66 ) {
F_91 ( V_104 , & V_98 -> V_100 -> V_39 ) ;
return F_4 ( - V_67 ) ;
}
return V_98 ;
}
void F_92 ( struct V_97 * V_98 , int V_104 )
{
F_93 ( F_94 ( V_104 , & V_98 -> V_100 -> V_39 ) == 0 ) ;
}
struct V_97 * F_95 ( struct V_97 * V_98 )
{
return F_89 ( V_98 , 1 ) ;
}
static struct V_97 * F_96 ( T_3 V_68 , enum V_96 * type )
{
struct V_61 V_62 = F_46 ( V_68 ) ;
struct V_97 * V_98 ;
V_98 = F_88 ( V_62 ) ;
if ( F_3 ( V_98 ) )
return V_98 ;
if ( type && V_98 -> type != * type ) {
V_98 = F_4 ( - V_10 ) ;
goto V_134;
}
V_98 = F_95 ( V_98 ) ;
V_134:
F_40 ( V_62 ) ;
return V_98 ;
}
struct V_97 * F_97 ( T_3 V_68 )
{
return F_96 ( V_68 , NULL ) ;
}
struct V_97 * F_98 ( T_3 V_68 , enum V_96 type )
{
return F_96 ( V_68 , & type ) ;
}
static int F_99 ( union V_2 * V_3 )
{
enum V_96 type = V_3 -> V_135 ;
struct V_97 * V_98 ;
int V_57 ;
char V_136 [ 128 ] ;
bool V_137 ;
if ( F_36 ( V_138 ) )
return - V_10 ;
if ( F_100 ( V_136 , F_49 ( V_3 -> V_136 ) ,
sizeof( V_136 ) - 1 ) < 0 )
return - V_79 ;
V_136 [ sizeof( V_136 ) - 1 ] = 0 ;
V_137 = F_101 ( V_136 ) ;
if ( V_3 -> V_139 == 0 || V_3 -> V_139 > V_140 )
return - V_141 ;
if ( type == V_142 &&
V_3 -> V_143 != V_144 )
return - V_10 ;
if ( type != V_145 && ! F_102 ( V_146 ) )
return - V_33 ;
V_98 = F_103 ( F_104 ( V_3 -> V_139 ) , V_21 ) ;
if ( ! V_98 )
return - V_77 ;
V_57 = F_78 ( V_98 ) ;
if ( V_57 )
goto V_147;
V_98 -> V_105 = V_3 -> V_139 ;
V_57 = - V_79 ;
if ( F_50 ( V_98 -> V_148 , F_49 ( V_3 -> V_148 ) ,
F_105 ( V_98 ) ) != 0 )
goto V_149;
V_98 -> V_150 = NULL ;
V_98 -> V_132 = 0 ;
F_38 ( & V_98 -> V_100 -> V_39 , 1 ) ;
V_98 -> V_151 = V_137 ? 1 : 0 ;
V_57 = F_69 ( type , V_98 ) ;
if ( V_57 < 0 )
goto V_149;
V_57 = F_106 ( & V_98 , V_3 ) ;
if ( V_57 < 0 )
goto F_74;
F_71 ( V_98 ) ;
V_98 = F_107 ( V_98 , & V_57 ) ;
if ( V_57 < 0 )
goto F_74;
V_57 = F_87 ( V_98 ) ;
if ( V_57 < 0 )
goto F_74;
return V_57 ;
F_74:
F_74 ( V_98 -> V_100 ) ;
V_149:
F_79 ( V_98 ) ;
V_147:
F_81 ( V_98 ) ;
return V_57 ;
}
static int F_108 ( const union V_2 * V_3 )
{
if ( F_36 ( V_152 ) )
return - V_10 ;
return F_109 ( V_3 -> V_153 , F_49 ( V_3 -> V_154 ) ) ;
}
static int F_110 ( const union V_2 * V_3 )
{
if ( F_36 ( V_152 ) || V_3 -> V_153 != 0 )
return - V_10 ;
return F_111 ( F_49 ( V_3 -> V_154 ) ) ;
}
static int F_112 ( const union V_2 * V_3 )
{
enum V_96 V_155 ;
struct V_97 * V_98 ;
struct V_156 * V_157 ;
int V_127 ;
if ( ! F_102 ( V_158 ) )
return - V_33 ;
if ( F_36 ( V_159 ) )
return - V_10 ;
if ( V_3 -> V_160 & ~ V_161 )
return - V_10 ;
switch ( V_3 -> V_162 ) {
case V_163 :
case V_164 :
V_155 = V_165 ;
break;
case V_166 :
V_155 = V_167 ;
break;
default:
return - V_10 ;
}
V_98 = F_98 ( V_3 -> V_168 , V_155 ) ;
if ( F_3 ( V_98 ) )
return F_37 ( V_98 ) ;
V_157 = F_113 ( V_3 -> V_169 ) ;
if ( F_3 ( V_157 ) ) {
F_82 ( V_98 ) ;
return F_37 ( V_157 ) ;
}
V_127 = F_114 ( V_157 , V_98 , V_3 -> V_162 ,
V_3 -> V_160 & V_161 ) ;
if ( V_127 )
F_82 ( V_98 ) ;
F_115 ( V_157 ) ;
return V_127 ;
}
static int F_116 ( const union V_2 * V_3 )
{
struct V_156 * V_157 ;
int V_127 ;
if ( ! F_102 ( V_158 ) )
return - V_33 ;
if ( F_36 ( V_170 ) )
return - V_10 ;
switch ( V_3 -> V_162 ) {
case V_163 :
case V_164 :
case V_166 :
V_157 = F_113 ( V_3 -> V_169 ) ;
if ( F_3 ( V_157 ) )
return F_37 ( V_157 ) ;
V_127 = F_114 ( V_157 , NULL , V_3 -> V_162 , false ) ;
F_115 ( V_157 ) ;
break;
default:
return - V_10 ;
}
return V_127 ;
}
