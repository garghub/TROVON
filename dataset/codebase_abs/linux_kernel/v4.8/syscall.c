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
goto V_44;
return V_42 ;
V_44:
V_6 -> V_8 -> V_24 ( V_6 ) ;
return V_42 ;
}
struct V_1 * F_34 ( struct V_45 V_46 )
{
if ( ! V_46 . V_29 )
return F_4 ( - V_47 ) ;
if ( V_46 . V_29 -> V_48 != & V_39 ) {
F_35 ( V_46 ) ;
return F_4 ( - V_10 ) ;
}
return V_46 . V_29 -> V_31 ;
}
struct V_1 * F_36 ( struct V_1 * V_6 , bool V_49 )
{
if ( F_37 ( & V_6 -> V_27 ) > V_50 ) {
F_38 ( & V_6 -> V_27 ) ;
return F_4 ( - V_51 ) ;
}
if ( V_49 )
F_39 ( & V_6 -> V_25 ) ;
return V_6 ;
}
struct V_1 * F_40 ( T_1 V_52 )
{
struct V_45 V_46 = F_41 ( V_52 ) ;
struct V_1 * V_6 ;
V_6 = F_34 ( V_46 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
V_6 = F_36 ( V_6 , true ) ;
F_35 ( V_46 ) ;
return V_6 ;
}
static void T_2 * F_42 ( T_3 V_53 )
{
return ( void T_2 * ) ( unsigned long ) V_53 ;
}
int __weak F_43 ( struct V_1 * V_6 , void * V_54 , void * V_55 )
{
return - V_56 ;
}
static int F_44 ( union V_2 * V_3 )
{
void T_2 * V_57 = F_42 ( V_3 -> V_54 ) ;
void T_2 * V_58 = F_42 ( V_3 -> V_55 ) ;
int V_52 = V_3 -> V_59 ;
struct V_1 * V_6 ;
void * V_54 , * V_55 , * V_60 ;
T_1 V_36 ;
struct V_45 V_46 ;
int V_42 ;
if ( F_31 ( V_61 ) )
return - V_10 ;
V_46 = F_41 ( V_52 ) ;
V_6 = F_34 ( V_46 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_62 ;
V_54 = F_45 ( V_6 -> V_35 , V_63 ) ;
if ( ! V_54 )
goto V_64;
V_42 = - V_65 ;
if ( F_46 ( V_54 , V_57 , V_6 -> V_35 ) != 0 )
goto V_66;
if ( V_6 -> V_7 == V_67 ||
V_6 -> V_7 == V_68 )
V_36 = F_47 ( V_6 -> V_36 , 8 ) * F_48 () ;
else
V_36 = V_6 -> V_36 ;
V_42 = - V_62 ;
V_55 = F_45 ( V_36 , V_63 | V_69 ) ;
if ( ! V_55 )
goto V_66;
if ( V_6 -> V_7 == V_67 ) {
V_42 = F_49 ( V_6 , V_54 , V_55 ) ;
} else if ( V_6 -> V_7 == V_68 ) {
V_42 = F_50 ( V_6 , V_54 , V_55 ) ;
} else if ( V_6 -> V_7 == V_70 ) {
V_42 = F_43 ( V_6 , V_54 , V_55 ) ;
} else {
F_51 () ;
V_60 = V_6 -> V_8 -> F_44 ( V_6 , V_54 ) ;
if ( V_60 )
memcpy ( V_55 , V_60 , V_36 ) ;
F_52 () ;
V_42 = V_60 ? 0 : - V_71 ;
}
if ( V_42 )
goto V_72;
V_42 = - V_65 ;
if ( F_53 ( V_58 , V_55 , V_36 ) != 0 )
goto V_72;
V_42 = 0 ;
V_72:
F_54 ( V_55 ) ;
V_66:
F_54 ( V_54 ) ;
V_64:
F_35 ( V_46 ) ;
return V_42 ;
}
static int F_55 ( union V_2 * V_3 )
{
void T_2 * V_57 = F_42 ( V_3 -> V_54 ) ;
void T_2 * V_58 = F_42 ( V_3 -> V_55 ) ;
int V_52 = V_3 -> V_59 ;
struct V_1 * V_6 ;
void * V_54 , * V_55 ;
T_1 V_36 ;
struct V_45 V_46 ;
int V_42 ;
if ( F_31 ( V_73 ) )
return - V_10 ;
V_46 = F_41 ( V_52 ) ;
V_6 = F_34 ( V_46 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_62 ;
V_54 = F_45 ( V_6 -> V_35 , V_63 ) ;
if ( ! V_54 )
goto V_64;
V_42 = - V_65 ;
if ( F_46 ( V_54 , V_57 , V_6 -> V_35 ) != 0 )
goto V_66;
if ( V_6 -> V_7 == V_67 ||
V_6 -> V_7 == V_68 )
V_36 = F_47 ( V_6 -> V_36 , 8 ) * F_48 () ;
else
V_36 = V_6 -> V_36 ;
V_42 = - V_62 ;
V_55 = F_45 ( V_36 , V_63 | V_69 ) ;
if ( ! V_55 )
goto V_66;
V_42 = - V_65 ;
if ( F_46 ( V_55 , V_58 , V_36 ) != 0 )
goto V_72;
F_56 () ;
F_57 ( V_74 ) ;
if ( V_6 -> V_7 == V_67 ) {
V_42 = F_58 ( V_6 , V_54 , V_55 , V_3 -> V_75 ) ;
} else if ( V_6 -> V_7 == V_68 ) {
V_42 = F_59 ( V_6 , V_54 , V_55 , V_3 -> V_75 ) ;
} else if ( V_6 -> V_7 == V_76 ||
V_6 -> V_7 == V_26 ||
V_6 -> V_7 == V_77 ) {
F_51 () ;
V_42 = F_60 ( V_6 , V_46 . V_29 , V_54 , V_55 ,
V_3 -> V_75 ) ;
F_52 () ;
} else {
F_51 () ;
V_42 = V_6 -> V_8 -> F_55 ( V_6 , V_54 , V_55 , V_3 -> V_75 ) ;
F_52 () ;
}
F_61 ( V_74 ) ;
F_62 () ;
V_72:
F_54 ( V_55 ) ;
V_66:
F_54 ( V_54 ) ;
V_64:
F_35 ( V_46 ) ;
return V_42 ;
}
static int F_63 ( union V_2 * V_3 )
{
void T_2 * V_57 = F_42 ( V_3 -> V_54 ) ;
int V_52 = V_3 -> V_59 ;
struct V_1 * V_6 ;
struct V_45 V_46 ;
void * V_54 ;
int V_42 ;
if ( F_31 ( V_78 ) )
return - V_10 ;
V_46 = F_41 ( V_52 ) ;
V_6 = F_34 ( V_46 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_62 ;
V_54 = F_45 ( V_6 -> V_35 , V_63 ) ;
if ( ! V_54 )
goto V_64;
V_42 = - V_65 ;
if ( F_46 ( V_54 , V_57 , V_6 -> V_35 ) != 0 )
goto V_66;
F_56 () ;
F_57 ( V_74 ) ;
F_51 () ;
V_42 = V_6 -> V_8 -> F_63 ( V_6 , V_54 ) ;
F_52 () ;
F_61 ( V_74 ) ;
F_62 () ;
V_66:
F_54 ( V_54 ) ;
V_64:
F_35 ( V_46 ) ;
return V_42 ;
}
static int F_64 ( union V_2 * V_3 )
{
void T_2 * V_57 = F_42 ( V_3 -> V_54 ) ;
void T_2 * V_79 = F_42 ( V_3 -> V_80 ) ;
int V_52 = V_3 -> V_59 ;
struct V_1 * V_6 ;
void * V_54 , * V_80 ;
struct V_45 V_46 ;
int V_42 ;
if ( F_31 ( V_81 ) )
return - V_10 ;
V_46 = F_41 ( V_52 ) ;
V_6 = F_34 ( V_46 ) ;
if ( F_3 ( V_6 ) )
return F_32 ( V_6 ) ;
V_42 = - V_62 ;
V_54 = F_45 ( V_6 -> V_35 , V_63 ) ;
if ( ! V_54 )
goto V_64;
V_42 = - V_65 ;
if ( F_46 ( V_54 , V_57 , V_6 -> V_35 ) != 0 )
goto V_66;
V_42 = - V_62 ;
V_80 = F_45 ( V_6 -> V_35 , V_63 ) ;
if ( ! V_80 )
goto V_66;
F_51 () ;
V_42 = V_6 -> V_8 -> F_64 ( V_6 , V_54 , V_80 ) ;
F_52 () ;
if ( V_42 )
goto V_82;
V_42 = - V_65 ;
if ( F_53 ( V_79 , V_80 , V_6 -> V_35 ) != 0 )
goto V_82;
V_42 = 0 ;
V_82:
F_54 ( V_80 ) ;
V_66:
F_54 ( V_54 ) ;
V_64:
F_35 ( V_46 ) ;
return V_42 ;
}
static int F_65 ( enum V_83 type , struct V_84 * V_85 )
{
struct V_86 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_85 -> V_87 -> V_8 = V_5 -> V_8 ;
V_85 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_66 ( struct V_86 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_88 ) ;
}
static void F_67 ( struct V_84 * V_85 )
{
const struct V_89 * V_90 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_85 -> V_92 ; V_91 ++ ) {
struct V_93 * V_94 = & V_85 -> V_95 [ V_91 ] ;
if ( V_94 -> V_96 == ( V_97 | V_98 ) ) {
F_68 ( ! V_85 -> V_87 -> V_8 -> V_99 ) ;
if ( V_94 -> V_100 == V_101 )
V_85 -> V_102 = 1 ;
if ( V_94 -> V_100 == V_103 )
F_69 () ;
if ( V_94 -> V_100 == V_104 ) {
V_94 -> V_100 = 0 ;
V_94 -> V_96 |= V_105 ;
continue;
}
V_90 = V_85 -> V_87 -> V_8 -> V_99 ( V_94 -> V_100 ) ;
F_68 ( ! V_90 -> V_106 ) ;
V_94 -> V_100 = V_90 -> V_106 - V_107 ;
}
}
}
static void F_70 ( struct V_108 * V_87 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_87 -> V_109 ; V_91 ++ )
F_21 ( V_87 -> V_110 [ V_91 ] ) ;
F_54 ( V_87 -> V_110 ) ;
}
static int F_71 ( struct V_84 * V_85 )
{
struct V_14 * V_15 = F_8 () ;
unsigned long V_16 ;
V_16 = F_9 ( V_18 ) >> V_19 ;
F_13 ( V_85 -> V_13 , & V_15 -> V_20 ) ;
if ( F_10 ( & V_15 -> V_20 ) > V_16 ) {
F_14 ( V_85 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
return - V_21 ;
}
V_85 -> V_87 -> V_15 = V_15 ;
return 0 ;
}
static void F_72 ( struct V_84 * V_85 )
{
struct V_14 * V_15 = V_85 -> V_87 -> V_15 ;
F_14 ( V_85 -> V_13 , & V_15 -> V_20 ) ;
F_11 ( V_15 ) ;
}
static void F_73 ( struct V_111 * V_112 )
{
struct V_108 * V_87 = F_17 ( V_112 , struct V_108 , V_112 ) ;
F_70 ( V_87 ) ;
F_72 ( V_87 -> V_85 ) ;
F_74 ( V_87 -> V_85 ) ;
}
void F_75 ( struct V_84 * V_85 )
{
if ( F_19 ( & V_85 -> V_87 -> V_27 ) )
F_76 ( & V_85 -> V_87 -> V_112 , F_73 ) ;
}
static int F_77 ( struct V_28 * V_28 , struct V_29 * V_30 )
{
struct V_84 * V_85 = V_30 -> V_31 ;
F_75 ( V_85 ) ;
return 0 ;
}
int F_78 ( struct V_84 * V_85 )
{
return F_29 ( L_7 , & V_113 , V_85 ,
V_40 | V_41 ) ;
}
static struct V_84 * F_79 ( struct V_45 V_46 )
{
if ( ! V_46 . V_29 )
return F_4 ( - V_47 ) ;
if ( V_46 . V_29 -> V_48 != & V_113 ) {
F_35 ( V_46 ) ;
return F_4 ( - V_10 ) ;
}
return V_46 . V_29 -> V_31 ;
}
struct V_84 * F_80 ( struct V_84 * V_85 , int V_91 )
{
if ( F_81 ( V_91 , & V_85 -> V_87 -> V_27 ) > V_50 ) {
F_82 ( V_91 , & V_85 -> V_87 -> V_27 ) ;
return F_4 ( - V_51 ) ;
}
return V_85 ;
}
struct V_84 * F_83 ( struct V_84 * V_85 )
{
return F_80 ( V_85 , 1 ) ;
}
static struct V_84 * F_84 ( T_1 V_52 , enum V_83 * type )
{
struct V_45 V_46 = F_41 ( V_52 ) ;
struct V_84 * V_85 ;
V_85 = F_79 ( V_46 ) ;
if ( F_3 ( V_85 ) )
return V_85 ;
if ( type && V_85 -> type != * type ) {
V_85 = F_4 ( - V_10 ) ;
goto V_114;
}
V_85 = F_83 ( V_85 ) ;
V_114:
F_35 ( V_46 ) ;
return V_85 ;
}
struct V_84 * F_85 ( T_1 V_52 )
{
return F_84 ( V_52 , NULL ) ;
}
struct V_84 * F_86 ( T_1 V_52 , enum V_83 type )
{
return F_84 ( V_52 , & type ) ;
}
static int F_87 ( union V_2 * V_3 )
{
enum V_83 type = V_3 -> V_115 ;
struct V_84 * V_85 ;
int V_42 ;
char V_116 [ 128 ] ;
bool V_117 ;
if ( F_31 ( V_118 ) )
return - V_10 ;
if ( F_88 ( V_116 , F_42 ( V_3 -> V_116 ) ,
sizeof( V_116 ) - 1 ) < 0 )
return - V_65 ;
V_116 [ sizeof( V_116 ) - 1 ] = 0 ;
V_117 = F_89 ( V_116 ) ;
if ( V_3 -> V_119 >= V_120 )
return - V_10 ;
if ( type == V_121 &&
V_3 -> V_122 != V_123 )
return - V_10 ;
if ( type != V_124 && ! F_90 ( V_125 ) )
return - V_21 ;
V_85 = F_91 ( F_92 ( V_3 -> V_119 ) , V_63 ) ;
if ( ! V_85 )
return - V_62 ;
V_42 = F_71 ( V_85 ) ;
if ( V_42 )
goto V_126;
V_85 -> V_92 = V_3 -> V_119 ;
V_42 = - V_65 ;
if ( F_46 ( V_85 -> V_127 , F_42 ( V_3 -> V_127 ) ,
V_85 -> V_92 * sizeof( struct V_93 ) ) != 0 )
goto V_128;
V_85 -> V_129 = NULL ;
V_85 -> V_130 = 0 ;
F_33 ( & V_85 -> V_87 -> V_27 , 1 ) ;
V_85 -> V_131 = V_117 ? 1 : 0 ;
V_42 = F_65 ( type , V_85 ) ;
if ( V_42 < 0 )
goto V_128;
V_42 = F_93 ( & V_85 , V_3 ) ;
if ( V_42 < 0 )
goto F_70;
F_67 ( V_85 ) ;
V_85 = F_94 ( V_85 , & V_42 ) ;
if ( V_42 < 0 )
goto F_70;
V_42 = F_78 ( V_85 ) ;
if ( V_42 < 0 )
goto F_70;
return V_42 ;
F_70:
F_70 ( V_85 -> V_87 ) ;
V_128:
F_72 ( V_85 ) ;
V_126:
F_74 ( V_85 ) ;
return V_42 ;
}
static int F_95 ( const union V_2 * V_3 )
{
if ( F_31 ( V_132 ) )
return - V_10 ;
return F_96 ( V_3 -> V_133 , F_42 ( V_3 -> V_134 ) ) ;
}
static int F_97 ( const union V_2 * V_3 )
{
if ( F_31 ( V_132 ) || V_3 -> V_133 != 0 )
return - V_10 ;
return F_98 ( F_42 ( V_3 -> V_134 ) ) ;
}
