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
static int F_7 ( struct V_1 * V_6 )
{
struct V_13 * V_14 = F_8 () ;
unsigned long V_15 ;
V_15 = F_9 ( V_16 ) >> V_17 ;
F_10 ( V_6 -> V_18 , & V_14 -> V_19 ) ;
if ( F_11 ( & V_14 -> V_19 ) > V_15 ) {
F_12 ( V_6 -> V_18 , & V_14 -> V_19 ) ;
F_13 ( V_14 ) ;
return - V_20 ;
}
V_6 -> V_14 = V_14 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_14 ;
F_12 ( V_6 -> V_18 , & V_14 -> V_19 ) ;
F_13 ( V_14 ) ;
}
static void F_15 ( struct V_21 * V_22 )
{
struct V_1 * V_6 = F_16 ( V_22 , struct V_1 , V_22 ) ;
F_14 ( V_6 ) ;
V_6 -> V_8 -> V_23 ( V_6 ) ;
}
static void F_17 ( struct V_1 * V_6 )
{
if ( F_18 ( & V_6 -> V_24 ) ) {
if ( V_6 -> V_7 == V_25 )
F_19 ( V_6 ) ;
}
}
void F_20 ( struct V_1 * V_6 )
{
if ( F_18 ( & V_6 -> V_26 ) ) {
F_21 ( & V_6 -> V_22 , F_15 ) ;
F_22 ( & V_6 -> V_22 ) ;
}
}
void F_23 ( struct V_1 * V_6 )
{
F_17 ( V_6 ) ;
F_20 ( V_6 ) ;
}
static int F_24 ( struct V_27 * V_27 , struct V_28 * V_29 )
{
F_23 ( V_29 -> V_30 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_6 )
{
return F_26 ( L_1 , & V_31 , V_6 ,
V_32 | V_33 ) ;
}
static int F_27 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_34 ;
V_34 = F_28 ( V_35 ) ;
if ( V_34 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_29 ( V_6 ) ;
F_30 ( & V_6 -> V_26 , 1 ) ;
F_30 ( & V_6 -> V_24 , 1 ) ;
V_34 = F_7 ( V_6 ) ;
if ( V_34 )
goto V_36;
V_34 = F_25 ( V_6 ) ;
if ( V_34 < 0 )
goto V_36;
return V_34 ;
V_36:
V_6 -> V_8 -> V_23 ( V_6 ) ;
return V_34 ;
}
struct V_1 * F_31 ( struct V_37 V_38 )
{
if ( ! V_38 . V_28 )
return F_4 ( - V_39 ) ;
if ( V_38 . V_28 -> V_40 != & V_31 ) {
F_32 ( V_38 ) ;
return F_4 ( - V_10 ) ;
}
return V_38 . V_28 -> V_30 ;
}
void F_33 ( struct V_1 * V_6 , bool V_41 )
{
F_34 ( & V_6 -> V_26 ) ;
if ( V_41 )
F_34 ( & V_6 -> V_24 ) ;
}
struct V_1 * F_35 ( T_1 V_42 )
{
struct V_37 V_38 = F_36 ( V_42 ) ;
struct V_1 * V_6 ;
V_6 = F_31 ( V_38 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
F_33 ( V_6 , true ) ;
F_32 ( V_38 ) ;
return V_6 ;
}
static void T_2 * F_37 ( T_3 V_43 )
{
return ( void T_2 * ) ( unsigned long ) V_43 ;
}
static int F_38 ( union V_2 * V_3 )
{
void T_2 * V_44 = F_37 ( V_3 -> V_45 ) ;
void T_2 * V_46 = F_37 ( V_3 -> V_47 ) ;
int V_42 = V_3 -> V_48 ;
struct V_1 * V_6 ;
void * V_45 , * V_47 , * V_49 ;
struct V_37 V_38 ;
int V_34 ;
if ( F_28 ( V_50 ) )
return - V_10 ;
V_38 = F_36 ( V_42 ) ;
V_6 = F_31 ( V_38 ) ;
if ( F_3 ( V_6 ) )
return F_29 ( V_6 ) ;
V_34 = - V_51 ;
V_45 = F_39 ( V_6 -> V_52 , V_53 ) ;
if ( ! V_45 )
goto V_54;
V_34 = - V_55 ;
if ( F_40 ( V_45 , V_44 , V_6 -> V_52 ) != 0 )
goto V_56;
V_34 = - V_51 ;
V_47 = F_39 ( V_6 -> V_57 , V_53 | V_58 ) ;
if ( ! V_47 )
goto V_56;
F_41 () ;
V_49 = V_6 -> V_8 -> F_38 ( V_6 , V_45 ) ;
if ( V_49 )
memcpy ( V_47 , V_49 , V_6 -> V_57 ) ;
F_42 () ;
V_34 = - V_59 ;
if ( ! V_49 )
goto V_60;
V_34 = - V_55 ;
if ( F_43 ( V_46 , V_47 , V_6 -> V_57 ) != 0 )
goto V_60;
V_34 = 0 ;
V_60:
F_44 ( V_47 ) ;
V_56:
F_44 ( V_45 ) ;
V_54:
F_32 ( V_38 ) ;
return V_34 ;
}
static int F_45 ( union V_2 * V_3 )
{
void T_2 * V_44 = F_37 ( V_3 -> V_45 ) ;
void T_2 * V_46 = F_37 ( V_3 -> V_47 ) ;
int V_42 = V_3 -> V_48 ;
struct V_1 * V_6 ;
void * V_45 , * V_47 ;
struct V_37 V_38 ;
int V_34 ;
if ( F_28 ( V_61 ) )
return - V_10 ;
V_38 = F_36 ( V_42 ) ;
V_6 = F_31 ( V_38 ) ;
if ( F_3 ( V_6 ) )
return F_29 ( V_6 ) ;
V_34 = - V_51 ;
V_45 = F_39 ( V_6 -> V_52 , V_53 ) ;
if ( ! V_45 )
goto V_54;
V_34 = - V_55 ;
if ( F_40 ( V_45 , V_44 , V_6 -> V_52 ) != 0 )
goto V_56;
V_34 = - V_51 ;
V_47 = F_39 ( V_6 -> V_57 , V_53 | V_58 ) ;
if ( ! V_47 )
goto V_56;
V_34 = - V_55 ;
if ( F_40 ( V_47 , V_46 , V_6 -> V_57 ) != 0 )
goto V_60;
F_41 () ;
V_34 = V_6 -> V_8 -> F_45 ( V_6 , V_45 , V_47 , V_3 -> V_62 ) ;
F_42 () ;
V_60:
F_44 ( V_47 ) ;
V_56:
F_44 ( V_45 ) ;
V_54:
F_32 ( V_38 ) ;
return V_34 ;
}
static int F_46 ( union V_2 * V_3 )
{
void T_2 * V_44 = F_37 ( V_3 -> V_45 ) ;
int V_42 = V_3 -> V_48 ;
struct V_1 * V_6 ;
struct V_37 V_38 ;
void * V_45 ;
int V_34 ;
if ( F_28 ( V_63 ) )
return - V_10 ;
V_38 = F_36 ( V_42 ) ;
V_6 = F_31 ( V_38 ) ;
if ( F_3 ( V_6 ) )
return F_29 ( V_6 ) ;
V_34 = - V_51 ;
V_45 = F_39 ( V_6 -> V_52 , V_53 ) ;
if ( ! V_45 )
goto V_54;
V_34 = - V_55 ;
if ( F_40 ( V_45 , V_44 , V_6 -> V_52 ) != 0 )
goto V_56;
F_41 () ;
V_34 = V_6 -> V_8 -> F_46 ( V_6 , V_45 ) ;
F_42 () ;
V_56:
F_44 ( V_45 ) ;
V_54:
F_32 ( V_38 ) ;
return V_34 ;
}
static int F_47 ( union V_2 * V_3 )
{
void T_2 * V_44 = F_37 ( V_3 -> V_45 ) ;
void T_2 * V_64 = F_37 ( V_3 -> V_65 ) ;
int V_42 = V_3 -> V_48 ;
struct V_1 * V_6 ;
void * V_45 , * V_65 ;
struct V_37 V_38 ;
int V_34 ;
if ( F_28 ( V_66 ) )
return - V_10 ;
V_38 = F_36 ( V_42 ) ;
V_6 = F_31 ( V_38 ) ;
if ( F_3 ( V_6 ) )
return F_29 ( V_6 ) ;
V_34 = - V_51 ;
V_45 = F_39 ( V_6 -> V_52 , V_53 ) ;
if ( ! V_45 )
goto V_54;
V_34 = - V_55 ;
if ( F_40 ( V_45 , V_44 , V_6 -> V_52 ) != 0 )
goto V_56;
V_34 = - V_51 ;
V_65 = F_39 ( V_6 -> V_52 , V_53 ) ;
if ( ! V_65 )
goto V_56;
F_41 () ;
V_34 = V_6 -> V_8 -> F_47 ( V_6 , V_45 , V_65 ) ;
F_42 () ;
if ( V_34 )
goto V_67;
V_34 = - V_55 ;
if ( F_43 ( V_64 , V_65 , V_6 -> V_52 ) != 0 )
goto V_67;
V_34 = 0 ;
V_67:
F_44 ( V_65 ) ;
V_56:
F_44 ( V_45 ) ;
V_54:
F_32 ( V_38 ) ;
return V_34 ;
}
static int F_48 ( enum V_68 type , struct V_69 * V_70 )
{
struct V_71 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_70 -> V_72 -> V_8 = V_5 -> V_8 ;
V_70 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_49 ( struct V_71 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_73 ) ;
}
static void F_50 ( struct V_69 * V_70 )
{
const struct V_74 * V_75 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_70 -> V_77 ; V_76 ++ ) {
struct V_78 * V_79 = & V_70 -> V_80 [ V_76 ] ;
if ( V_79 -> V_81 == ( V_82 | V_83 ) ) {
F_51 ( ! V_70 -> V_72 -> V_8 -> V_84 ) ;
if ( V_79 -> V_85 == V_86 )
V_70 -> V_87 = 1 ;
if ( V_79 -> V_85 == V_88 )
F_52 () ;
if ( V_79 -> V_85 == V_89 ) {
V_79 -> V_85 = 0 ;
V_79 -> V_81 |= V_90 ;
continue;
}
V_75 = V_70 -> V_72 -> V_8 -> V_84 ( V_79 -> V_85 ) ;
F_51 ( ! V_75 -> V_91 ) ;
V_79 -> V_85 = V_75 -> V_91 - V_92 ;
}
}
}
static void F_53 ( struct V_93 * V_72 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_72 -> V_94 ; V_76 ++ )
F_20 ( V_72 -> V_95 [ V_76 ] ) ;
F_44 ( V_72 -> V_95 ) ;
}
static int F_54 ( struct V_69 * V_70 )
{
struct V_13 * V_14 = F_8 () ;
unsigned long V_15 ;
V_15 = F_9 ( V_16 ) >> V_17 ;
F_10 ( V_70 -> V_18 , & V_14 -> V_19 ) ;
if ( F_11 ( & V_14 -> V_19 ) > V_15 ) {
F_12 ( V_70 -> V_18 , & V_14 -> V_19 ) ;
F_13 ( V_14 ) ;
return - V_20 ;
}
V_70 -> V_72 -> V_14 = V_14 ;
return 0 ;
}
static void F_55 ( struct V_69 * V_70 )
{
struct V_13 * V_14 = V_70 -> V_72 -> V_14 ;
F_12 ( V_70 -> V_18 , & V_14 -> V_19 ) ;
F_13 ( V_14 ) ;
}
static void F_56 ( struct V_96 * V_97 )
{
struct V_93 * V_72 = F_16 ( V_97 , struct V_93 , V_97 ) ;
F_53 ( V_72 ) ;
F_55 ( V_72 -> V_70 ) ;
F_57 ( V_72 -> V_70 ) ;
}
void F_58 ( struct V_69 * V_70 )
{
if ( F_18 ( & V_70 -> V_72 -> V_26 ) )
F_59 ( & V_70 -> V_72 -> V_97 , F_56 ) ;
}
void F_60 ( struct V_69 * V_70 )
{
if ( F_18 ( & V_70 -> V_72 -> V_26 ) )
F_56 ( & V_70 -> V_72 -> V_97 ) ;
}
static int F_61 ( struct V_27 * V_27 , struct V_28 * V_29 )
{
struct V_69 * V_70 = V_29 -> V_30 ;
F_58 ( V_70 ) ;
return 0 ;
}
int F_62 ( struct V_69 * V_70 )
{
return F_26 ( L_2 , & V_98 , V_70 ,
V_32 | V_33 ) ;
}
static struct V_69 * F_63 ( struct V_37 V_38 )
{
if ( ! V_38 . V_28 )
return F_4 ( - V_39 ) ;
if ( V_38 . V_28 -> V_40 != & V_98 ) {
F_32 ( V_38 ) ;
return F_4 ( - V_10 ) ;
}
return V_38 . V_28 -> V_30 ;
}
struct V_69 * F_64 ( T_1 V_42 )
{
struct V_37 V_38 = F_36 ( V_42 ) ;
struct V_69 * V_70 ;
V_70 = F_63 ( V_38 ) ;
if ( F_3 ( V_70 ) )
return V_70 ;
F_34 ( & V_70 -> V_72 -> V_26 ) ;
F_32 ( V_38 ) ;
return V_70 ;
}
static int F_65 ( union V_2 * V_3 )
{
enum V_68 type = V_3 -> V_99 ;
struct V_69 * V_70 ;
int V_34 ;
char V_100 [ 128 ] ;
bool V_101 ;
if ( F_28 ( V_102 ) )
return - V_10 ;
if ( F_66 ( V_100 , F_37 ( V_3 -> V_100 ) ,
sizeof( V_100 ) - 1 ) < 0 )
return - V_55 ;
V_100 [ sizeof( V_100 ) - 1 ] = 0 ;
V_101 = F_67 ( V_100 ) ;
if ( V_3 -> V_103 >= V_104 )
return - V_10 ;
if ( type == V_105 &&
V_3 -> V_106 != V_107 )
return - V_10 ;
if ( type != V_108 && ! F_68 ( V_109 ) )
return - V_20 ;
V_70 = F_69 ( F_70 ( V_3 -> V_103 ) , V_53 ) ;
if ( ! V_70 )
return - V_51 ;
V_34 = F_54 ( V_70 ) ;
if ( V_34 )
goto V_110;
V_70 -> V_77 = V_3 -> V_103 ;
V_34 = - V_55 ;
if ( F_40 ( V_70 -> V_111 , F_37 ( V_3 -> V_111 ) ,
V_70 -> V_77 * sizeof( struct V_78 ) ) != 0 )
goto V_112;
V_70 -> V_113 = NULL ;
V_70 -> V_114 = 0 ;
F_30 ( & V_70 -> V_72 -> V_26 , 1 ) ;
V_70 -> V_115 = V_101 ? 1 : 0 ;
V_34 = F_48 ( type , V_70 ) ;
if ( V_34 < 0 )
goto V_112;
V_34 = F_71 ( & V_70 , V_3 ) ;
if ( V_34 < 0 )
goto F_53;
F_50 ( V_70 ) ;
V_34 = F_72 ( V_70 ) ;
if ( V_34 < 0 )
goto F_53;
V_34 = F_62 ( V_70 ) ;
if ( V_34 < 0 )
goto F_53;
return V_34 ;
F_53:
F_53 ( V_70 -> V_72 ) ;
V_112:
F_55 ( V_70 ) ;
V_110:
F_57 ( V_70 ) ;
return V_34 ;
}
static int F_73 ( const union V_2 * V_3 )
{
if ( F_28 ( V_116 ) )
return - V_10 ;
return F_74 ( V_3 -> V_117 , F_37 ( V_3 -> V_118 ) ) ;
}
static int F_75 ( const union V_2 * V_3 )
{
if ( F_28 ( V_116 ) || V_3 -> V_117 != 0 )
return - V_10 ;
return F_76 ( F_37 ( V_3 -> V_118 ) ) ;
}
