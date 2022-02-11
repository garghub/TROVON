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
int F_7 ( T_1 V_13 )
{
struct V_14 * V_15 = F_8 () ;
unsigned long V_16 , V_17 ;
V_16 = F_9 ( V_18 ) >> V_19 ;
V_17 = F_10 ( & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
if ( V_17 + V_13 > V_16 )
return - V_21 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_6 )
{
struct V_14 * V_15 = F_8 () ;
unsigned long V_16 ;
V_16 = F_9 ( V_18 ) >> V_19 ;
F_13 ( V_6 -> V_13 , & V_15 -> V_20 ) ;
if ( F_10 ( & V_15 -> V_20 ) > V_16 ) {
F_14 ( V_6 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
return - V_21 ;
}
V_6 -> V_15 = V_15 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
F_14 ( V_6 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_6 = F_17 ( V_23 , struct V_1 , V_23 ) ;
F_15 ( V_6 ) ;
V_6 -> V_8 -> V_24 ( V_6 ) ;
}
static void F_18 ( struct V_1 * V_6 )
{
if ( F_19 ( & V_6 -> V_25 ) ) {
if ( V_6 -> V_7 == V_26 )
F_20 ( V_6 ) ;
}
}
void F_21 ( struct V_1 * V_6 )
{
if ( F_19 ( & V_6 -> V_27 ) ) {
F_22 ( & V_6 -> V_23 , F_16 ) ;
F_23 ( & V_6 -> V_23 ) ;
}
}
void F_24 ( struct V_1 * V_6 )
{
F_18 ( V_6 ) ;
F_21 ( V_6 ) ;
}
static int F_25 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
struct V_1 * V_6 = V_30 -> V_31 ;
if ( V_6 -> V_8 -> V_32 )
V_6 -> V_8 -> V_32 ( V_6 , V_30 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static void F_26 ( struct V_33 * V_34 , struct V_29 * V_30 )
{
const struct V_1 * V_6 = V_30 -> V_31 ;
F_27 ( V_34 ,
L_1
L_2
L_3
L_4
L_5 ,
V_6 -> V_7 ,
V_6 -> V_35 ,
V_6 -> V_36 ,
V_6 -> V_37 ,
V_6 -> V_38 ) ;
}
int F_28 ( struct V_1 * V_6 )
{
return F_29 ( L_6 , & V_39 , V_6 ,
V_40 | V_41 ) ;
}
static int F_30 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_42 ;
V_42 = F_31 ( V_43 ) ;
if ( V_42 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
F_33 ( & V_6 -> V_27 , 1 ) ;
F_33 ( & V_6 -> V_25 , 1 ) ;
V_42 = F_12 ( V_6 ) ;
if ( V_42 )
goto V_44;
V_42 = F_28 ( V_6 ) ;
if ( V_42 < 0 )
goto V_45;
return V_42 ;
V_45:
F_15 ( V_6 ) ;
V_44:
V_6 -> V_8 -> V_24 ( V_6 ) ;
return V_42 ;
}
struct V_1 * F_34 ( struct V_46 V_47 )
{
if ( ! V_47 . V_29 )
return F_4 ( - V_48 ) ;
if ( V_47 . V_29 -> V_49 != & V_39 ) {
F_35 ( V_47 ) ;
return F_4 ( - V_10 ) ;
}
return V_47 . V_29 -> V_31 ;
}
struct V_1 * F_36 ( struct V_1 * V_6 , bool V_50 )
{
if ( F_37 ( & V_6 -> V_27 ) > V_51 ) {
F_38 ( & V_6 -> V_27 ) ;
return F_4 ( - V_52 ) ;
}
if ( V_50 )
F_39 ( & V_6 -> V_25 ) ;
return V_6 ;
}
struct V_1 * F_40 ( T_1 V_53 )
{
struct V_46 V_47 = F_41 ( V_53 ) ;
struct V_1 * V_6 ;
V_6 = F_34 ( V_47 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
V_6 = F_36 ( V_6 , true ) ;
F_35 ( V_47 ) ;
return V_6 ;
}
static void T_2 * F_42 ( T_3 V_54 )
{
return ( void T_2 * ) ( unsigned long ) V_54 ;
}
int __weak F_43 ( struct V_1 * V_6 , void * V_55 , void * V_56 )
{
return - V_57 ;
}
static int F_44 ( union V_2 * V_3 )
{
void T_2 * V_58 = F_42 ( V_3 -> V_55 ) ;
void T_2 * V_59 = F_42 ( V_3 -> V_56 ) ;
int V_53 = V_3 -> V_60 ;
struct V_1 * V_6 ;
void * V_55 , * V_56 , * V_61 ;
T_1 V_36 ;
struct V_46 V_47 ;
int V_42 ;
if ( F_31 ( V_62 ) )
return - V_10 ;
V_47 = F_41 ( V_53 ) ;
V_6 = F_34 ( V_47 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_63 ;
V_55 = F_45 ( V_6 -> V_35 , V_64 ) ;
if ( ! V_55 )
goto V_65;
V_42 = - V_66 ;
if ( F_46 ( V_55 , V_58 , V_6 -> V_35 ) != 0 )
goto V_67;
if ( V_6 -> V_7 == V_68 ||
V_6 -> V_7 == V_69 )
V_36 = F_47 ( V_6 -> V_36 , 8 ) * F_48 () ;
else
V_36 = V_6 -> V_36 ;
V_42 = - V_63 ;
V_56 = F_45 ( V_36 , V_64 | V_70 ) ;
if ( ! V_56 )
goto V_67;
if ( V_6 -> V_7 == V_68 ) {
V_42 = F_49 ( V_6 , V_55 , V_56 ) ;
} else if ( V_6 -> V_7 == V_69 ) {
V_42 = F_50 ( V_6 , V_55 , V_56 ) ;
} else if ( V_6 -> V_7 == V_71 ) {
V_42 = F_43 ( V_6 , V_55 , V_56 ) ;
} else {
F_51 () ;
V_61 = V_6 -> V_8 -> F_44 ( V_6 , V_55 ) ;
if ( V_61 )
memcpy ( V_56 , V_61 , V_36 ) ;
F_52 () ;
V_42 = V_61 ? 0 : - V_72 ;
}
if ( V_42 )
goto V_73;
V_42 = - V_66 ;
if ( F_53 ( V_59 , V_56 , V_36 ) != 0 )
goto V_73;
V_42 = 0 ;
V_73:
F_54 ( V_56 ) ;
V_67:
F_54 ( V_55 ) ;
V_65:
F_35 ( V_47 ) ;
return V_42 ;
}
static int F_55 ( union V_2 * V_3 )
{
void T_2 * V_58 = F_42 ( V_3 -> V_55 ) ;
void T_2 * V_59 = F_42 ( V_3 -> V_56 ) ;
int V_53 = V_3 -> V_60 ;
struct V_1 * V_6 ;
void * V_55 , * V_56 ;
T_1 V_36 ;
struct V_46 V_47 ;
int V_42 ;
if ( F_31 ( V_74 ) )
return - V_10 ;
V_47 = F_41 ( V_53 ) ;
V_6 = F_34 ( V_47 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_63 ;
V_55 = F_45 ( V_6 -> V_35 , V_64 ) ;
if ( ! V_55 )
goto V_65;
V_42 = - V_66 ;
if ( F_46 ( V_55 , V_58 , V_6 -> V_35 ) != 0 )
goto V_67;
if ( V_6 -> V_7 == V_68 ||
V_6 -> V_7 == V_69 )
V_36 = F_47 ( V_6 -> V_36 , 8 ) * F_48 () ;
else
V_36 = V_6 -> V_36 ;
V_42 = - V_63 ;
V_56 = F_45 ( V_36 , V_64 | V_70 ) ;
if ( ! V_56 )
goto V_67;
V_42 = - V_66 ;
if ( F_46 ( V_56 , V_59 , V_36 ) != 0 )
goto V_73;
F_56 () ;
F_57 ( V_75 ) ;
if ( V_6 -> V_7 == V_68 ) {
V_42 = F_58 ( V_6 , V_55 , V_56 , V_3 -> V_76 ) ;
} else if ( V_6 -> V_7 == V_69 ) {
V_42 = F_59 ( V_6 , V_55 , V_56 , V_3 -> V_76 ) ;
} else if ( V_6 -> V_7 == V_77 ||
V_6 -> V_7 == V_26 ||
V_6 -> V_7 == V_78 ) {
F_51 () ;
V_42 = F_60 ( V_6 , V_47 . V_29 , V_55 , V_56 ,
V_3 -> V_76 ) ;
F_52 () ;
} else {
F_51 () ;
V_42 = V_6 -> V_8 -> F_55 ( V_6 , V_55 , V_56 , V_3 -> V_76 ) ;
F_52 () ;
}
F_61 ( V_75 ) ;
F_62 () ;
V_73:
F_54 ( V_56 ) ;
V_67:
F_54 ( V_55 ) ;
V_65:
F_35 ( V_47 ) ;
return V_42 ;
}
static int F_63 ( union V_2 * V_3 )
{
void T_2 * V_58 = F_42 ( V_3 -> V_55 ) ;
int V_53 = V_3 -> V_60 ;
struct V_1 * V_6 ;
struct V_46 V_47 ;
void * V_55 ;
int V_42 ;
if ( F_31 ( V_79 ) )
return - V_10 ;
V_47 = F_41 ( V_53 ) ;
V_6 = F_34 ( V_47 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_63 ;
V_55 = F_45 ( V_6 -> V_35 , V_64 ) ;
if ( ! V_55 )
goto V_65;
V_42 = - V_66 ;
if ( F_46 ( V_55 , V_58 , V_6 -> V_35 ) != 0 )
goto V_67;
F_56 () ;
F_57 ( V_75 ) ;
F_51 () ;
V_42 = V_6 -> V_8 -> F_63 ( V_6 , V_55 ) ;
F_52 () ;
F_61 ( V_75 ) ;
F_62 () ;
V_67:
F_54 ( V_55 ) ;
V_65:
F_35 ( V_47 ) ;
return V_42 ;
}
static int F_64 ( union V_2 * V_3 )
{
void T_2 * V_58 = F_42 ( V_3 -> V_55 ) ;
void T_2 * V_80 = F_42 ( V_3 -> V_81 ) ;
int V_53 = V_3 -> V_60 ;
struct V_1 * V_6 ;
void * V_55 , * V_81 ;
struct V_46 V_47 ;
int V_42 ;
if ( F_31 ( V_82 ) )
return - V_10 ;
V_47 = F_41 ( V_53 ) ;
V_6 = F_34 ( V_47 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_63 ;
V_55 = F_45 ( V_6 -> V_35 , V_64 ) ;
if ( ! V_55 )
goto V_65;
V_42 = - V_66 ;
if ( F_46 ( V_55 , V_58 , V_6 -> V_35 ) != 0 )
goto V_67;
V_42 = - V_63 ;
V_81 = F_45 ( V_6 -> V_35 , V_64 ) ;
if ( ! V_81 )
goto V_67;
F_51 () ;
V_42 = V_6 -> V_8 -> F_64 ( V_6 , V_55 , V_81 ) ;
F_52 () ;
if ( V_42 )
goto V_83;
V_42 = - V_66 ;
if ( F_53 ( V_80 , V_81 , V_6 -> V_35 ) != 0 )
goto V_83;
V_42 = 0 ;
V_83:
F_54 ( V_81 ) ;
V_67:
F_54 ( V_55 ) ;
V_65:
F_35 ( V_47 ) ;
return V_42 ;
}
static int F_65 ( enum V_84 type , struct V_85 * V_86 )
{
struct V_87 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_86 -> V_88 -> V_8 = V_5 -> V_8 ;
V_86 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_66 ( struct V_87 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_89 ) ;
}
static void F_67 ( struct V_85 * V_86 )
{
const struct V_90 * V_91 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_86 -> V_93 ; V_92 ++ ) {
struct V_94 * V_95 = & V_86 -> V_96 [ V_92 ] ;
if ( V_95 -> V_97 == ( V_98 | V_99 ) ) {
F_68 ( ! V_86 -> V_88 -> V_8 -> V_100 ) ;
if ( V_95 -> V_101 == V_102 )
V_86 -> V_103 = 1 ;
if ( V_95 -> V_101 == V_104 )
F_69 () ;
if ( V_95 -> V_101 == V_105 ) {
V_95 -> V_101 = 0 ;
V_95 -> V_97 |= V_106 ;
continue;
}
V_91 = V_86 -> V_88 -> V_8 -> V_100 ( V_95 -> V_101 ) ;
F_68 ( ! V_91 -> V_107 ) ;
V_95 -> V_101 = V_91 -> V_107 - V_108 ;
}
}
}
static void F_70 ( struct V_109 * V_88 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_88 -> V_110 ; V_92 ++ )
F_21 ( V_88 -> V_111 [ V_92 ] ) ;
F_54 ( V_88 -> V_111 ) ;
}
static int F_71 ( struct V_85 * V_86 )
{
struct V_14 * V_15 = F_8 () ;
unsigned long V_16 ;
V_16 = F_9 ( V_18 ) >> V_19 ;
F_13 ( V_86 -> V_13 , & V_15 -> V_20 ) ;
if ( F_10 ( & V_15 -> V_20 ) > V_16 ) {
F_14 ( V_86 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
return - V_21 ;
}
V_86 -> V_88 -> V_15 = V_15 ;
return 0 ;
}
static void F_72 ( struct V_85 * V_86 )
{
struct V_14 * V_15 = V_86 -> V_88 -> V_15 ;
F_14 ( V_86 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
}
static void F_73 ( struct V_112 * V_113 )
{
struct V_109 * V_88 = F_17 ( V_113 , struct V_109 , V_113 ) ;
F_70 ( V_88 ) ;
F_72 ( V_88 -> V_86 ) ;
F_74 ( V_88 -> V_86 ) ;
}
void F_75 ( struct V_85 * V_86 )
{
if ( F_19 ( & V_86 -> V_88 -> V_27 ) )
F_76 ( & V_86 -> V_88 -> V_113 , F_73 ) ;
}
static int F_77 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
struct V_85 * V_86 = V_30 -> V_31 ;
F_75 ( V_86 ) ;
return 0 ;
}
int F_78 ( struct V_85 * V_86 )
{
return F_29 ( L_7 , & V_114 , V_86 ,
V_40 | V_41 ) ;
}
static struct V_85 * F_79 ( struct V_46 V_47 )
{
if ( ! V_47 . V_29 )
return F_4 ( - V_48 ) ;
if ( V_47 . V_29 -> V_49 != & V_114 ) {
F_35 ( V_47 ) ;
return F_4 ( - V_10 ) ;
}
return V_47 . V_29 -> V_31 ;
}
struct V_85 * F_80 ( struct V_85 * V_86 , int V_92 )
{
if ( F_81 ( V_92 , & V_86 -> V_88 -> V_27 ) > V_51 ) {
F_82 ( V_92 , & V_86 -> V_88 -> V_27 ) ;
return F_4 ( - V_52 ) ;
}
return V_86 ;
}
struct V_85 * F_83 ( struct V_85 * V_86 )
{
return F_80 ( V_86 , 1 ) ;
}
static struct V_85 * F_84 ( T_1 V_53 , enum V_84 * type )
{
struct V_46 V_47 = F_41 ( V_53 ) ;
struct V_85 * V_86 ;
V_86 = F_79 ( V_47 ) ;
if ( F_3 ( V_86 ) )
return V_86 ;
if ( type && V_86 -> type != * type ) {
V_86 = F_4 ( - V_10 ) ;
goto V_115;
}
V_86 = F_83 ( V_86 ) ;
V_115:
F_35 ( V_47 ) ;
return V_86 ;
}
struct V_85 * F_85 ( T_1 V_53 )
{
return F_84 ( V_53 , NULL ) ;
}
struct V_85 * F_86 ( T_1 V_53 , enum V_84 type )
{
return F_84 ( V_53 , & type ) ;
}
static int F_87 ( union V_2 * V_3 )
{
enum V_84 type = V_3 -> V_116 ;
struct V_85 * V_86 ;
int V_42 ;
char V_117 [ 128 ] ;
bool V_118 ;
if ( F_31 ( V_119 ) )
return - V_10 ;
if ( F_88 ( V_117 , F_42 ( V_3 -> V_117 ) ,
sizeof( V_117 ) - 1 ) < 0 )
return - V_66 ;
V_117 [ sizeof( V_117 ) - 1 ] = 0 ;
V_118 = F_89 ( V_117 ) ;
if ( V_3 -> V_120 >= V_121 )
return - V_10 ;
if ( type == V_122 &&
V_3 -> V_123 != V_124 )
return - V_10 ;
if ( type != V_125 && ! F_90 ( V_126 ) )
return - V_21 ;
V_86 = F_91 ( F_92 ( V_3 -> V_120 ) , V_64 ) ;
if ( ! V_86 )
return - V_63 ;
V_42 = F_71 ( V_86 ) ;
if ( V_42 )
goto V_127;
V_86 -> V_93 = V_3 -> V_120 ;
V_42 = - V_66 ;
if ( F_46 ( V_86 -> V_128 , F_42 ( V_3 -> V_128 ) ,
V_86 -> V_93 * sizeof( struct V_94 ) ) != 0 )
goto V_129;
V_86 -> V_130 = NULL ;
V_86 -> V_131 = 0 ;
F_33 ( & V_86 -> V_88 -> V_27 , 1 ) ;
V_86 -> V_132 = V_118 ? 1 : 0 ;
V_42 = F_65 ( type , V_86 ) ;
if ( V_42 < 0 )
goto V_129;
V_42 = F_93 ( & V_86 , V_3 ) ;
if ( V_42 < 0 )
goto F_70;
F_67 ( V_86 ) ;
V_86 = F_94 ( V_86 , & V_42 ) ;
if ( V_42 < 0 )
goto F_70;
V_42 = F_78 ( V_86 ) ;
if ( V_42 < 0 )
goto F_70;
return V_42 ;
F_70:
F_70 ( V_86 -> V_88 ) ;
V_129:
F_72 ( V_86 ) ;
V_127:
F_74 ( V_86 ) ;
return V_42 ;
}
static int F_95 ( const union V_2 * V_3 )
{
if ( F_31 ( V_133 ) )
return - V_10 ;
return F_96 ( V_3 -> V_134 , F_42 ( V_3 -> V_135 ) ) ;
}
static int F_97 ( const union V_2 * V_3 )
{
if ( F_31 ( V_133 ) || V_3 -> V_134 != 0 )
return - V_10 ;
return F_98 ( F_42 ( V_3 -> V_135 ) ) ;
}
