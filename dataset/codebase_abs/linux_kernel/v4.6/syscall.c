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
F_24 ( V_30 -> V_31 ) ;
return 0 ;
}
static void F_26 ( struct V_32 * V_33 , struct V_29 * V_30 )
{
const struct V_1 * V_6 = V_30 -> V_31 ;
F_27 ( V_33 ,
L_1
L_2
L_3
L_4
L_5 ,
V_6 -> V_7 ,
V_6 -> V_34 ,
V_6 -> V_35 ,
V_6 -> V_36 ,
V_6 -> V_37 ) ;
}
int F_28 ( struct V_1 * V_6 )
{
return F_29 ( L_6 , & V_38 , V_6 ,
V_39 | V_40 ) ;
}
static int F_30 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_41 ;
V_41 = F_31 ( V_42 ) ;
if ( V_41 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
F_33 ( & V_6 -> V_27 , 1 ) ;
F_33 ( & V_6 -> V_25 , 1 ) ;
V_41 = F_12 ( V_6 ) ;
if ( V_41 )
goto V_43;
V_41 = F_28 ( V_6 ) ;
if ( V_41 < 0 )
goto V_43;
return V_41 ;
V_43:
V_6 -> V_8 -> V_24 ( V_6 ) ;
return V_41 ;
}
struct V_1 * F_34 ( struct V_44 V_45 )
{
if ( ! V_45 . V_29 )
return F_4 ( - V_46 ) ;
if ( V_45 . V_29 -> V_47 != & V_38 ) {
F_35 ( V_45 ) ;
return F_4 ( - V_10 ) ;
}
return V_45 . V_29 -> V_31 ;
}
struct V_1 * F_36 ( struct V_1 * V_6 , bool V_48 )
{
if ( F_37 ( & V_6 -> V_27 ) > V_49 ) {
F_38 ( & V_6 -> V_27 ) ;
return F_4 ( - V_50 ) ;
}
if ( V_48 )
F_39 ( & V_6 -> V_25 ) ;
return V_6 ;
}
struct V_1 * F_40 ( T_1 V_51 )
{
struct V_44 V_45 = F_41 ( V_51 ) ;
struct V_1 * V_6 ;
V_6 = F_34 ( V_45 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
V_6 = F_36 ( V_6 , true ) ;
F_35 ( V_45 ) ;
return V_6 ;
}
static void T_2 * F_42 ( T_3 V_52 )
{
return ( void T_2 * ) ( unsigned long ) V_52 ;
}
int __weak F_43 ( struct V_1 * V_6 , void * V_53 , void * V_54 )
{
return - V_55 ;
}
static int F_44 ( union V_2 * V_3 )
{
void T_2 * V_56 = F_42 ( V_3 -> V_53 ) ;
void T_2 * V_57 = F_42 ( V_3 -> V_54 ) ;
int V_51 = V_3 -> V_58 ;
struct V_1 * V_6 ;
void * V_53 , * V_54 , * V_59 ;
T_1 V_35 ;
struct V_44 V_45 ;
int V_41 ;
if ( F_31 ( V_60 ) )
return - V_10 ;
V_45 = F_41 ( V_51 ) ;
V_6 = F_34 ( V_45 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_41 = - V_61 ;
V_53 = F_45 ( V_6 -> V_34 , V_62 ) ;
if ( ! V_53 )
goto V_63;
V_41 = - V_64 ;
if ( F_46 ( V_53 , V_56 , V_6 -> V_34 ) != 0 )
goto V_65;
if ( V_6 -> V_7 == V_66 ||
V_6 -> V_7 == V_67 )
V_35 = F_47 ( V_6 -> V_35 , 8 ) * F_48 () ;
else
V_35 = V_6 -> V_35 ;
V_41 = - V_61 ;
V_54 = F_45 ( V_35 , V_62 | V_68 ) ;
if ( ! V_54 )
goto V_65;
if ( V_6 -> V_7 == V_66 ) {
V_41 = F_49 ( V_6 , V_53 , V_54 ) ;
} else if ( V_6 -> V_7 == V_67 ) {
V_41 = F_50 ( V_6 , V_53 , V_54 ) ;
} else if ( V_6 -> V_7 == V_69 ) {
V_41 = F_43 ( V_6 , V_53 , V_54 ) ;
} else {
F_51 () ;
V_59 = V_6 -> V_8 -> F_44 ( V_6 , V_53 ) ;
if ( V_59 )
memcpy ( V_54 , V_59 , V_35 ) ;
F_52 () ;
V_41 = V_59 ? 0 : - V_70 ;
}
if ( V_41 )
goto V_71;
V_41 = - V_64 ;
if ( F_53 ( V_57 , V_54 , V_35 ) != 0 )
goto V_71;
V_41 = 0 ;
V_71:
F_54 ( V_54 ) ;
V_65:
F_54 ( V_53 ) ;
V_63:
F_35 ( V_45 ) ;
return V_41 ;
}
static int F_55 ( union V_2 * V_3 )
{
void T_2 * V_56 = F_42 ( V_3 -> V_53 ) ;
void T_2 * V_57 = F_42 ( V_3 -> V_54 ) ;
int V_51 = V_3 -> V_58 ;
struct V_1 * V_6 ;
void * V_53 , * V_54 ;
T_1 V_35 ;
struct V_44 V_45 ;
int V_41 ;
if ( F_31 ( V_72 ) )
return - V_10 ;
V_45 = F_41 ( V_51 ) ;
V_6 = F_34 ( V_45 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_41 = - V_61 ;
V_53 = F_45 ( V_6 -> V_34 , V_62 ) ;
if ( ! V_53 )
goto V_63;
V_41 = - V_64 ;
if ( F_46 ( V_53 , V_56 , V_6 -> V_34 ) != 0 )
goto V_65;
if ( V_6 -> V_7 == V_66 ||
V_6 -> V_7 == V_67 )
V_35 = F_47 ( V_6 -> V_35 , 8 ) * F_48 () ;
else
V_35 = V_6 -> V_35 ;
V_41 = - V_61 ;
V_54 = F_45 ( V_35 , V_62 | V_68 ) ;
if ( ! V_54 )
goto V_65;
V_41 = - V_64 ;
if ( F_46 ( V_54 , V_57 , V_35 ) != 0 )
goto V_71;
F_56 () ;
F_57 ( V_73 ) ;
if ( V_6 -> V_7 == V_66 ) {
V_41 = F_58 ( V_6 , V_53 , V_54 , V_3 -> V_74 ) ;
} else if ( V_6 -> V_7 == V_67 ) {
V_41 = F_59 ( V_6 , V_53 , V_54 , V_3 -> V_74 ) ;
} else {
F_51 () ;
V_41 = V_6 -> V_8 -> F_55 ( V_6 , V_53 , V_54 , V_3 -> V_74 ) ;
F_52 () ;
}
F_60 ( V_73 ) ;
F_61 () ;
V_71:
F_54 ( V_54 ) ;
V_65:
F_54 ( V_53 ) ;
V_63:
F_35 ( V_45 ) ;
return V_41 ;
}
static int F_62 ( union V_2 * V_3 )
{
void T_2 * V_56 = F_42 ( V_3 -> V_53 ) ;
int V_51 = V_3 -> V_58 ;
struct V_1 * V_6 ;
struct V_44 V_45 ;
void * V_53 ;
int V_41 ;
if ( F_31 ( V_75 ) )
return - V_10 ;
V_45 = F_41 ( V_51 ) ;
V_6 = F_34 ( V_45 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_41 = - V_61 ;
V_53 = F_45 ( V_6 -> V_34 , V_62 ) ;
if ( ! V_53 )
goto V_63;
V_41 = - V_64 ;
if ( F_46 ( V_53 , V_56 , V_6 -> V_34 ) != 0 )
goto V_65;
F_56 () ;
F_57 ( V_73 ) ;
F_51 () ;
V_41 = V_6 -> V_8 -> F_62 ( V_6 , V_53 ) ;
F_52 () ;
F_60 ( V_73 ) ;
F_61 () ;
V_65:
F_54 ( V_53 ) ;
V_63:
F_35 ( V_45 ) ;
return V_41 ;
}
static int F_63 ( union V_2 * V_3 )
{
void T_2 * V_56 = F_42 ( V_3 -> V_53 ) ;
void T_2 * V_76 = F_42 ( V_3 -> V_77 ) ;
int V_51 = V_3 -> V_58 ;
struct V_1 * V_6 ;
void * V_53 , * V_77 ;
struct V_44 V_45 ;
int V_41 ;
if ( F_31 ( V_78 ) )
return - V_10 ;
V_45 = F_41 ( V_51 ) ;
V_6 = F_34 ( V_45 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_41 = - V_61 ;
V_53 = F_45 ( V_6 -> V_34 , V_62 ) ;
if ( ! V_53 )
goto V_63;
V_41 = - V_64 ;
if ( F_46 ( V_53 , V_56 , V_6 -> V_34 ) != 0 )
goto V_65;
V_41 = - V_61 ;
V_77 = F_45 ( V_6 -> V_34 , V_62 ) ;
if ( ! V_77 )
goto V_65;
F_51 () ;
V_41 = V_6 -> V_8 -> F_63 ( V_6 , V_53 , V_77 ) ;
F_52 () ;
if ( V_41 )
goto V_79;
V_41 = - V_64 ;
if ( F_53 ( V_76 , V_77 , V_6 -> V_34 ) != 0 )
goto V_79;
V_41 = 0 ;
V_79:
F_54 ( V_77 ) ;
V_65:
F_54 ( V_53 ) ;
V_63:
F_35 ( V_45 ) ;
return V_41 ;
}
static int F_64 ( enum V_80 type , struct V_81 * V_82 )
{
struct V_83 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_82 -> V_84 -> V_8 = V_5 -> V_8 ;
V_82 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_65 ( struct V_83 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_85 ) ;
}
static void F_66 ( struct V_81 * V_82 )
{
const struct V_86 * V_87 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_82 -> V_89 ; V_88 ++ ) {
struct V_90 * V_91 = & V_82 -> V_92 [ V_88 ] ;
if ( V_91 -> V_93 == ( V_94 | V_95 ) ) {
F_67 ( ! V_82 -> V_84 -> V_8 -> V_96 ) ;
if ( V_91 -> V_97 == V_98 )
V_82 -> V_99 = 1 ;
if ( V_91 -> V_97 == V_100 )
F_68 () ;
if ( V_91 -> V_97 == V_101 ) {
V_91 -> V_97 = 0 ;
V_91 -> V_93 |= V_102 ;
continue;
}
V_87 = V_82 -> V_84 -> V_8 -> V_96 ( V_91 -> V_97 ) ;
F_67 ( ! V_87 -> V_103 ) ;
V_91 -> V_97 = V_87 -> V_103 - V_104 ;
}
}
}
static void F_69 ( struct V_105 * V_84 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_84 -> V_106 ; V_88 ++ )
F_21 ( V_84 -> V_107 [ V_88 ] ) ;
F_54 ( V_84 -> V_107 ) ;
}
static int F_70 ( struct V_81 * V_82 )
{
struct V_14 * V_15 = F_8 () ;
unsigned long V_16 ;
V_16 = F_9 ( V_18 ) >> V_19 ;
F_13 ( V_82 -> V_13 , & V_15 -> V_20 ) ;
if ( F_10 ( & V_15 -> V_20 ) > V_16 ) {
F_14 ( V_82 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
return - V_21 ;
}
V_82 -> V_84 -> V_15 = V_15 ;
return 0 ;
}
static void F_71 ( struct V_81 * V_82 )
{
struct V_14 * V_15 = V_82 -> V_84 -> V_15 ;
F_14 ( V_82 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
}
static void F_72 ( struct V_108 * V_109 )
{
struct V_105 * V_84 = F_17 ( V_109 , struct V_105 , V_109 ) ;
F_69 ( V_84 ) ;
F_71 ( V_84 -> V_82 ) ;
F_73 ( V_84 -> V_82 ) ;
}
void F_74 ( struct V_81 * V_82 )
{
if ( F_19 ( & V_82 -> V_84 -> V_27 ) )
F_75 ( & V_82 -> V_84 -> V_109 , F_72 ) ;
}
void F_76 ( struct V_81 * V_82 )
{
if ( F_19 ( & V_82 -> V_84 -> V_27 ) )
F_72 ( & V_82 -> V_84 -> V_109 ) ;
}
static int F_77 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
struct V_81 * V_82 = V_30 -> V_31 ;
F_74 ( V_82 ) ;
return 0 ;
}
int F_78 ( struct V_81 * V_82 )
{
return F_29 ( L_7 , & V_110 , V_82 ,
V_39 | V_40 ) ;
}
static struct V_81 * F_79 ( struct V_44 V_45 )
{
if ( ! V_45 . V_29 )
return F_4 ( - V_46 ) ;
if ( V_45 . V_29 -> V_47 != & V_110 ) {
F_35 ( V_45 ) ;
return F_4 ( - V_10 ) ;
}
return V_45 . V_29 -> V_31 ;
}
struct V_81 * F_80 ( struct V_81 * V_82 )
{
if ( F_37 ( & V_82 -> V_84 -> V_27 ) > V_49 ) {
F_38 ( & V_82 -> V_84 -> V_27 ) ;
return F_4 ( - V_50 ) ;
}
return V_82 ;
}
struct V_81 * F_81 ( T_1 V_51 )
{
struct V_44 V_45 = F_41 ( V_51 ) ;
struct V_81 * V_82 ;
V_82 = F_79 ( V_45 ) ;
if ( F_3 ( V_82 ) )
return V_82 ;
V_82 = F_80 ( V_82 ) ;
F_35 ( V_45 ) ;
return V_82 ;
}
static int F_82 ( union V_2 * V_3 )
{
enum V_80 type = V_3 -> V_111 ;
struct V_81 * V_82 ;
int V_41 ;
char V_112 [ 128 ] ;
bool V_113 ;
if ( F_31 ( V_114 ) )
return - V_10 ;
if ( F_83 ( V_112 , F_42 ( V_3 -> V_112 ) ,
sizeof( V_112 ) - 1 ) < 0 )
return - V_64 ;
V_112 [ sizeof( V_112 ) - 1 ] = 0 ;
V_113 = F_84 ( V_112 ) ;
if ( V_3 -> V_115 >= V_116 )
return - V_10 ;
if ( type == V_117 &&
V_3 -> V_118 != V_119 )
return - V_10 ;
if ( type != V_120 && ! F_85 ( V_121 ) )
return - V_21 ;
V_82 = F_86 ( F_87 ( V_3 -> V_115 ) , V_62 ) ;
if ( ! V_82 )
return - V_61 ;
V_41 = F_70 ( V_82 ) ;
if ( V_41 )
goto V_122;
V_82 -> V_89 = V_3 -> V_115 ;
V_41 = - V_64 ;
if ( F_46 ( V_82 -> V_123 , F_42 ( V_3 -> V_123 ) ,
V_82 -> V_89 * sizeof( struct V_90 ) ) != 0 )
goto V_124;
V_82 -> V_125 = NULL ;
V_82 -> V_126 = 0 ;
F_33 ( & V_82 -> V_84 -> V_27 , 1 ) ;
V_82 -> V_127 = V_113 ? 1 : 0 ;
V_41 = F_64 ( type , V_82 ) ;
if ( V_41 < 0 )
goto V_124;
V_41 = F_88 ( & V_82 , V_3 ) ;
if ( V_41 < 0 )
goto F_69;
F_66 ( V_82 ) ;
V_41 = F_89 ( V_82 ) ;
if ( V_41 < 0 )
goto F_69;
V_41 = F_78 ( V_82 ) ;
if ( V_41 < 0 )
goto F_69;
return V_41 ;
F_69:
F_69 ( V_82 -> V_84 ) ;
V_124:
F_71 ( V_82 ) ;
V_122:
F_73 ( V_82 ) ;
return V_41 ;
}
static int F_90 ( const union V_2 * V_3 )
{
if ( F_31 ( V_128 ) )
return - V_10 ;
return F_91 ( V_3 -> V_129 , F_42 ( V_3 -> V_130 ) ) ;
}
static int F_92 ( const union V_2 * V_3 )
{
if ( F_31 ( V_128 ) || V_3 -> V_129 != 0 )
return - V_10 ;
return F_93 ( F_42 ( V_3 -> V_130 ) ) ;
}
