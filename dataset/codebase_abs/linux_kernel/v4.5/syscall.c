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
static void F_25 ( struct V_31 * V_32 , struct V_28 * V_29 )
{
const struct V_1 * V_6 = V_29 -> V_30 ;
F_26 ( V_32 ,
L_1
L_2
L_3
L_4 ,
V_6 -> V_7 ,
V_6 -> V_33 ,
V_6 -> V_34 ,
V_6 -> V_35 ) ;
}
int F_27 ( struct V_1 * V_6 )
{
return F_28 ( L_5 , & V_36 , V_6 ,
V_37 | V_38 ) ;
}
static int F_29 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_39 ;
V_39 = F_30 ( V_40 ) ;
if ( V_39 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_31 ( V_6 ) ;
F_32 ( & V_6 -> V_26 , 1 ) ;
F_32 ( & V_6 -> V_24 , 1 ) ;
V_39 = F_7 ( V_6 ) ;
if ( V_39 )
goto V_41;
V_39 = F_27 ( V_6 ) ;
if ( V_39 < 0 )
goto V_41;
return V_39 ;
V_41:
V_6 -> V_8 -> V_23 ( V_6 ) ;
return V_39 ;
}
struct V_1 * F_33 ( struct V_42 V_43 )
{
if ( ! V_43 . V_28 )
return F_4 ( - V_44 ) ;
if ( V_43 . V_28 -> V_45 != & V_36 ) {
F_34 ( V_43 ) ;
return F_4 ( - V_10 ) ;
}
return V_43 . V_28 -> V_30 ;
}
void F_35 ( struct V_1 * V_6 , bool V_46 )
{
F_36 ( & V_6 -> V_26 ) ;
if ( V_46 )
F_36 ( & V_6 -> V_24 ) ;
}
struct V_1 * F_37 ( T_1 V_47 )
{
struct V_42 V_43 = F_38 ( V_47 ) ;
struct V_1 * V_6 ;
V_6 = F_33 ( V_43 ) ;
if ( F_3 ( V_6 ) )
return V_6 ;
F_35 ( V_6 , true ) ;
F_34 ( V_43 ) ;
return V_6 ;
}
static void T_2 * F_39 ( T_3 V_48 )
{
return ( void T_2 * ) ( unsigned long ) V_48 ;
}
static int F_40 ( union V_2 * V_3 )
{
void T_2 * V_49 = F_39 ( V_3 -> V_50 ) ;
void T_2 * V_51 = F_39 ( V_3 -> V_52 ) ;
int V_47 = V_3 -> V_53 ;
struct V_1 * V_6 ;
void * V_50 , * V_52 , * V_54 ;
struct V_42 V_43 ;
int V_39 ;
if ( F_30 ( V_55 ) )
return - V_10 ;
V_43 = F_38 ( V_47 ) ;
V_6 = F_33 ( V_43 ) ;
if ( F_3 ( V_6 ) )
return F_31 ( V_6 ) ;
V_39 = - V_56 ;
V_50 = F_41 ( V_6 -> V_33 , V_57 ) ;
if ( ! V_50 )
goto V_58;
V_39 = - V_59 ;
if ( F_42 ( V_50 , V_49 , V_6 -> V_33 ) != 0 )
goto V_60;
V_39 = - V_56 ;
V_52 = F_41 ( V_6 -> V_34 , V_57 | V_61 ) ;
if ( ! V_52 )
goto V_60;
F_43 () ;
V_54 = V_6 -> V_8 -> F_40 ( V_6 , V_50 ) ;
if ( V_54 )
memcpy ( V_52 , V_54 , V_6 -> V_34 ) ;
F_44 () ;
V_39 = - V_62 ;
if ( ! V_54 )
goto V_63;
V_39 = - V_59 ;
if ( F_45 ( V_51 , V_52 , V_6 -> V_34 ) != 0 )
goto V_63;
V_39 = 0 ;
V_63:
F_46 ( V_52 ) ;
V_60:
F_46 ( V_50 ) ;
V_58:
F_34 ( V_43 ) ;
return V_39 ;
}
static int F_47 ( union V_2 * V_3 )
{
void T_2 * V_49 = F_39 ( V_3 -> V_50 ) ;
void T_2 * V_51 = F_39 ( V_3 -> V_52 ) ;
int V_47 = V_3 -> V_53 ;
struct V_1 * V_6 ;
void * V_50 , * V_52 ;
struct V_42 V_43 ;
int V_39 ;
if ( F_30 ( V_64 ) )
return - V_10 ;
V_43 = F_38 ( V_47 ) ;
V_6 = F_33 ( V_43 ) ;
if ( F_3 ( V_6 ) )
return F_31 ( V_6 ) ;
V_39 = - V_56 ;
V_50 = F_41 ( V_6 -> V_33 , V_57 ) ;
if ( ! V_50 )
goto V_58;
V_39 = - V_59 ;
if ( F_42 ( V_50 , V_49 , V_6 -> V_33 ) != 0 )
goto V_60;
V_39 = - V_56 ;
V_52 = F_41 ( V_6 -> V_34 , V_57 | V_61 ) ;
if ( ! V_52 )
goto V_60;
V_39 = - V_59 ;
if ( F_42 ( V_52 , V_51 , V_6 -> V_34 ) != 0 )
goto V_63;
F_43 () ;
V_39 = V_6 -> V_8 -> F_47 ( V_6 , V_50 , V_52 , V_3 -> V_65 ) ;
F_44 () ;
V_63:
F_46 ( V_52 ) ;
V_60:
F_46 ( V_50 ) ;
V_58:
F_34 ( V_43 ) ;
return V_39 ;
}
static int F_48 ( union V_2 * V_3 )
{
void T_2 * V_49 = F_39 ( V_3 -> V_50 ) ;
int V_47 = V_3 -> V_53 ;
struct V_1 * V_6 ;
struct V_42 V_43 ;
void * V_50 ;
int V_39 ;
if ( F_30 ( V_66 ) )
return - V_10 ;
V_43 = F_38 ( V_47 ) ;
V_6 = F_33 ( V_43 ) ;
if ( F_3 ( V_6 ) )
return F_31 ( V_6 ) ;
V_39 = - V_56 ;
V_50 = F_41 ( V_6 -> V_33 , V_57 ) ;
if ( ! V_50 )
goto V_58;
V_39 = - V_59 ;
if ( F_42 ( V_50 , V_49 , V_6 -> V_33 ) != 0 )
goto V_60;
F_43 () ;
V_39 = V_6 -> V_8 -> F_48 ( V_6 , V_50 ) ;
F_44 () ;
V_60:
F_46 ( V_50 ) ;
V_58:
F_34 ( V_43 ) ;
return V_39 ;
}
static int F_49 ( union V_2 * V_3 )
{
void T_2 * V_49 = F_39 ( V_3 -> V_50 ) ;
void T_2 * V_67 = F_39 ( V_3 -> V_68 ) ;
int V_47 = V_3 -> V_53 ;
struct V_1 * V_6 ;
void * V_50 , * V_68 ;
struct V_42 V_43 ;
int V_39 ;
if ( F_30 ( V_69 ) )
return - V_10 ;
V_43 = F_38 ( V_47 ) ;
V_6 = F_33 ( V_43 ) ;
if ( F_3 ( V_6 ) )
return F_31 ( V_6 ) ;
V_39 = - V_56 ;
V_50 = F_41 ( V_6 -> V_33 , V_57 ) ;
if ( ! V_50 )
goto V_58;
V_39 = - V_59 ;
if ( F_42 ( V_50 , V_49 , V_6 -> V_33 ) != 0 )
goto V_60;
V_39 = - V_56 ;
V_68 = F_41 ( V_6 -> V_33 , V_57 ) ;
if ( ! V_68 )
goto V_60;
F_43 () ;
V_39 = V_6 -> V_8 -> F_49 ( V_6 , V_50 , V_68 ) ;
F_44 () ;
if ( V_39 )
goto V_70;
V_39 = - V_59 ;
if ( F_45 ( V_67 , V_68 , V_6 -> V_33 ) != 0 )
goto V_70;
V_39 = 0 ;
V_70:
F_46 ( V_68 ) ;
V_60:
F_46 ( V_50 ) ;
V_58:
F_34 ( V_43 ) ;
return V_39 ;
}
static int F_50 ( enum V_71 type , struct V_72 * V_73 )
{
struct V_74 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_73 -> V_75 -> V_8 = V_5 -> V_8 ;
V_73 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_51 ( struct V_74 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_76 ) ;
}
static void F_52 ( struct V_72 * V_73 )
{
const struct V_77 * V_78 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_73 -> V_80 ; V_79 ++ ) {
struct V_81 * V_82 = & V_73 -> V_83 [ V_79 ] ;
if ( V_82 -> V_84 == ( V_85 | V_86 ) ) {
F_53 ( ! V_73 -> V_75 -> V_8 -> V_87 ) ;
if ( V_82 -> V_88 == V_89 )
V_73 -> V_90 = 1 ;
if ( V_82 -> V_88 == V_91 )
F_54 () ;
if ( V_82 -> V_88 == V_92 ) {
V_82 -> V_88 = 0 ;
V_82 -> V_84 |= V_93 ;
continue;
}
V_78 = V_73 -> V_75 -> V_8 -> V_87 ( V_82 -> V_88 ) ;
F_53 ( ! V_78 -> V_94 ) ;
V_82 -> V_88 = V_78 -> V_94 - V_95 ;
}
}
}
static void F_55 ( struct V_96 * V_75 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_75 -> V_97 ; V_79 ++ )
F_20 ( V_75 -> V_98 [ V_79 ] ) ;
F_46 ( V_75 -> V_98 ) ;
}
static int F_56 ( struct V_72 * V_73 )
{
struct V_13 * V_14 = F_8 () ;
unsigned long V_15 ;
V_15 = F_9 ( V_16 ) >> V_17 ;
F_10 ( V_73 -> V_18 , & V_14 -> V_19 ) ;
if ( F_11 ( & V_14 -> V_19 ) > V_15 ) {
F_12 ( V_73 -> V_18 , & V_14 -> V_19 ) ;
F_13 ( V_14 ) ;
return - V_20 ;
}
V_73 -> V_75 -> V_14 = V_14 ;
return 0 ;
}
static void F_57 ( struct V_72 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_75 -> V_14 ;
F_12 ( V_73 -> V_18 , & V_14 -> V_19 ) ;
F_13 ( V_14 ) ;
}
static void F_58 ( struct V_99 * V_100 )
{
struct V_96 * V_75 = F_16 ( V_100 , struct V_96 , V_100 ) ;
F_55 ( V_75 ) ;
F_57 ( V_75 -> V_73 ) ;
F_59 ( V_75 -> V_73 ) ;
}
void F_60 ( struct V_72 * V_73 )
{
if ( F_18 ( & V_73 -> V_75 -> V_26 ) )
F_61 ( & V_73 -> V_75 -> V_100 , F_58 ) ;
}
void F_62 ( struct V_72 * V_73 )
{
if ( F_18 ( & V_73 -> V_75 -> V_26 ) )
F_58 ( & V_73 -> V_75 -> V_100 ) ;
}
static int F_63 ( struct V_27 * V_27 , struct V_28 * V_29 )
{
struct V_72 * V_73 = V_29 -> V_30 ;
F_60 ( V_73 ) ;
return 0 ;
}
int F_64 ( struct V_72 * V_73 )
{
return F_28 ( L_6 , & V_101 , V_73 ,
V_37 | V_38 ) ;
}
static struct V_72 * F_65 ( struct V_42 V_43 )
{
if ( ! V_43 . V_28 )
return F_4 ( - V_44 ) ;
if ( V_43 . V_28 -> V_45 != & V_101 ) {
F_34 ( V_43 ) ;
return F_4 ( - V_10 ) ;
}
return V_43 . V_28 -> V_30 ;
}
struct V_72 * F_66 ( T_1 V_47 )
{
struct V_42 V_43 = F_38 ( V_47 ) ;
struct V_72 * V_73 ;
V_73 = F_65 ( V_43 ) ;
if ( F_3 ( V_73 ) )
return V_73 ;
F_36 ( & V_73 -> V_75 -> V_26 ) ;
F_34 ( V_43 ) ;
return V_73 ;
}
static int F_67 ( union V_2 * V_3 )
{
enum V_71 type = V_3 -> V_102 ;
struct V_72 * V_73 ;
int V_39 ;
char V_103 [ 128 ] ;
bool V_104 ;
if ( F_30 ( V_105 ) )
return - V_10 ;
if ( F_68 ( V_103 , F_39 ( V_3 -> V_103 ) ,
sizeof( V_103 ) - 1 ) < 0 )
return - V_59 ;
V_103 [ sizeof( V_103 ) - 1 ] = 0 ;
V_104 = F_69 ( V_103 ) ;
if ( V_3 -> V_106 >= V_107 )
return - V_10 ;
if ( type == V_108 &&
V_3 -> V_109 != V_110 )
return - V_10 ;
if ( type != V_111 && ! F_70 ( V_112 ) )
return - V_20 ;
V_73 = F_71 ( F_72 ( V_3 -> V_106 ) , V_57 ) ;
if ( ! V_73 )
return - V_56 ;
V_39 = F_56 ( V_73 ) ;
if ( V_39 )
goto V_113;
V_73 -> V_80 = V_3 -> V_106 ;
V_39 = - V_59 ;
if ( F_42 ( V_73 -> V_114 , F_39 ( V_3 -> V_114 ) ,
V_73 -> V_80 * sizeof( struct V_81 ) ) != 0 )
goto V_115;
V_73 -> V_116 = NULL ;
V_73 -> V_117 = 0 ;
F_32 ( & V_73 -> V_75 -> V_26 , 1 ) ;
V_73 -> V_118 = V_104 ? 1 : 0 ;
V_39 = F_50 ( type , V_73 ) ;
if ( V_39 < 0 )
goto V_115;
V_39 = F_73 ( & V_73 , V_3 ) ;
if ( V_39 < 0 )
goto F_55;
F_52 ( V_73 ) ;
V_39 = F_74 ( V_73 ) ;
if ( V_39 < 0 )
goto F_55;
V_39 = F_64 ( V_73 ) ;
if ( V_39 < 0 )
goto F_55;
return V_39 ;
F_55:
F_55 ( V_73 -> V_75 ) ;
V_115:
F_57 ( V_73 ) ;
V_113:
F_59 ( V_73 ) ;
return V_39 ;
}
static int F_75 ( const union V_2 * V_3 )
{
if ( F_30 ( V_119 ) )
return - V_10 ;
return F_76 ( V_3 -> V_120 , F_39 ( V_3 -> V_121 ) ) ;
}
static int F_77 ( const union V_2 * V_3 )
{
if ( F_30 ( V_119 ) || V_3 -> V_120 != 0 )
return - V_10 ;
return F_78 ( F_39 ( V_3 -> V_121 ) ) ;
}
