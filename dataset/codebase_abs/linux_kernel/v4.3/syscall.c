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
static void F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_6 = F_8 ( V_14 , struct V_1 , V_14 ) ;
V_6 -> V_8 -> V_15 ( V_6 ) ;
}
void F_9 ( struct V_1 * V_6 )
{
if ( F_10 ( & V_6 -> V_16 ) ) {
F_11 ( & V_6 -> V_14 , F_7 ) ;
F_12 ( & V_6 -> V_14 ) ;
}
}
static int F_13 ( struct V_17 * V_17 , struct V_18 * V_19 )
{
struct V_1 * V_6 = V_19 -> V_20 ;
if ( V_6 -> V_7 == V_21 )
F_14 ( V_6 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static int F_15 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_22 ;
V_22 = F_16 ( V_23 ) ;
if ( V_22 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_17 ( V_6 ) ;
F_18 ( & V_6 -> V_16 , 1 ) ;
V_22 = F_19 ( L_1 , & V_24 , V_6 , V_25 | V_26 ) ;
if ( V_22 < 0 )
goto V_27;
return V_22 ;
V_27:
V_6 -> V_8 -> V_15 ( V_6 ) ;
return V_22 ;
}
struct V_1 * F_20 ( struct V_28 V_29 )
{
struct V_1 * V_6 ;
if ( ! V_29 . V_18 )
return F_4 ( - V_30 ) ;
if ( V_29 . V_18 -> V_31 != & V_24 ) {
F_21 ( V_29 ) ;
return F_4 ( - V_10 ) ;
}
V_6 = V_29 . V_18 -> V_20 ;
return V_6 ;
}
static void T_1 * F_22 ( T_2 V_32 )
{
return ( void T_1 * ) ( unsigned long ) V_32 ;
}
static int F_23 ( union V_2 * V_3 )
{
void T_1 * V_33 = F_22 ( V_3 -> V_34 ) ;
void T_1 * V_35 = F_22 ( V_3 -> V_36 ) ;
int V_37 = V_3 -> V_38 ;
struct V_1 * V_6 ;
void * V_34 , * V_36 , * V_39 ;
struct V_28 V_29 ;
int V_22 ;
if ( F_16 ( V_40 ) )
return - V_10 ;
V_29 = F_24 ( V_37 ) ;
V_6 = F_20 ( V_29 ) ;
if ( F_3 ( V_6 ) )
return F_17 ( V_6 ) ;
V_22 = - V_41 ;
V_34 = F_25 ( V_6 -> V_42 , V_43 ) ;
if ( ! V_34 )
goto V_44;
V_22 = - V_45 ;
if ( F_26 ( V_34 , V_33 , V_6 -> V_42 ) != 0 )
goto V_46;
V_22 = - V_41 ;
V_36 = F_25 ( V_6 -> V_47 , V_43 ) ;
if ( ! V_36 )
goto V_46;
F_27 () ;
V_39 = V_6 -> V_8 -> F_23 ( V_6 , V_34 ) ;
if ( V_39 )
memcpy ( V_36 , V_39 , V_6 -> V_47 ) ;
F_28 () ;
V_22 = - V_48 ;
if ( ! V_39 )
goto V_49;
V_22 = - V_45 ;
if ( F_29 ( V_35 , V_36 , V_6 -> V_47 ) != 0 )
goto V_49;
V_22 = 0 ;
V_49:
F_30 ( V_36 ) ;
V_46:
F_30 ( V_34 ) ;
V_44:
F_21 ( V_29 ) ;
return V_22 ;
}
static int F_31 ( union V_2 * V_3 )
{
void T_1 * V_33 = F_22 ( V_3 -> V_34 ) ;
void T_1 * V_35 = F_22 ( V_3 -> V_36 ) ;
int V_37 = V_3 -> V_38 ;
struct V_1 * V_6 ;
void * V_34 , * V_36 ;
struct V_28 V_29 ;
int V_22 ;
if ( F_16 ( V_50 ) )
return - V_10 ;
V_29 = F_24 ( V_37 ) ;
V_6 = F_20 ( V_29 ) ;
if ( F_3 ( V_6 ) )
return F_17 ( V_6 ) ;
V_22 = - V_41 ;
V_34 = F_25 ( V_6 -> V_42 , V_43 ) ;
if ( ! V_34 )
goto V_44;
V_22 = - V_45 ;
if ( F_26 ( V_34 , V_33 , V_6 -> V_42 ) != 0 )
goto V_46;
V_22 = - V_41 ;
V_36 = F_25 ( V_6 -> V_47 , V_43 ) ;
if ( ! V_36 )
goto V_46;
V_22 = - V_45 ;
if ( F_26 ( V_36 , V_35 , V_6 -> V_47 ) != 0 )
goto V_49;
F_27 () ;
V_22 = V_6 -> V_8 -> F_31 ( V_6 , V_34 , V_36 , V_3 -> V_51 ) ;
F_28 () ;
V_49:
F_30 ( V_36 ) ;
V_46:
F_30 ( V_34 ) ;
V_44:
F_21 ( V_29 ) ;
return V_22 ;
}
static int F_32 ( union V_2 * V_3 )
{
void T_1 * V_33 = F_22 ( V_3 -> V_34 ) ;
int V_37 = V_3 -> V_38 ;
struct V_1 * V_6 ;
struct V_28 V_29 ;
void * V_34 ;
int V_22 ;
if ( F_16 ( V_52 ) )
return - V_10 ;
V_29 = F_24 ( V_37 ) ;
V_6 = F_20 ( V_29 ) ;
if ( F_3 ( V_6 ) )
return F_17 ( V_6 ) ;
V_22 = - V_41 ;
V_34 = F_25 ( V_6 -> V_42 , V_43 ) ;
if ( ! V_34 )
goto V_44;
V_22 = - V_45 ;
if ( F_26 ( V_34 , V_33 , V_6 -> V_42 ) != 0 )
goto V_46;
F_27 () ;
V_22 = V_6 -> V_8 -> F_32 ( V_6 , V_34 ) ;
F_28 () ;
V_46:
F_30 ( V_34 ) ;
V_44:
F_21 ( V_29 ) ;
return V_22 ;
}
static int F_33 ( union V_2 * V_3 )
{
void T_1 * V_33 = F_22 ( V_3 -> V_34 ) ;
void T_1 * V_53 = F_22 ( V_3 -> V_54 ) ;
int V_37 = V_3 -> V_38 ;
struct V_1 * V_6 ;
void * V_34 , * V_54 ;
struct V_28 V_29 ;
int V_22 ;
if ( F_16 ( V_55 ) )
return - V_10 ;
V_29 = F_24 ( V_37 ) ;
V_6 = F_20 ( V_29 ) ;
if ( F_3 ( V_6 ) )
return F_17 ( V_6 ) ;
V_22 = - V_41 ;
V_34 = F_25 ( V_6 -> V_42 , V_43 ) ;
if ( ! V_34 )
goto V_44;
V_22 = - V_45 ;
if ( F_26 ( V_34 , V_33 , V_6 -> V_42 ) != 0 )
goto V_46;
V_22 = - V_41 ;
V_54 = F_25 ( V_6 -> V_42 , V_43 ) ;
if ( ! V_54 )
goto V_46;
F_27 () ;
V_22 = V_6 -> V_8 -> F_33 ( V_6 , V_34 , V_54 ) ;
F_28 () ;
if ( V_22 )
goto V_56;
V_22 = - V_45 ;
if ( F_29 ( V_53 , V_54 , V_6 -> V_42 ) != 0 )
goto V_56;
V_22 = 0 ;
V_56:
F_30 ( V_54 ) ;
V_46:
F_30 ( V_34 ) ;
V_44:
F_21 ( V_29 ) ;
return V_22 ;
}
static int F_34 ( enum V_57 type , struct V_58 * V_59 )
{
struct V_60 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_59 -> V_61 -> V_8 = V_5 -> V_8 ;
V_59 -> type = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_35 ( struct V_60 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_62 ) ;
}
static void F_36 ( struct V_58 * V_59 )
{
const struct V_63 * V_64 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_59 -> V_66 ; V_65 ++ ) {
struct V_67 * V_68 = & V_59 -> V_69 [ V_65 ] ;
if ( V_68 -> V_70 == ( V_71 | V_72 ) ) {
F_37 ( ! V_59 -> V_61 -> V_8 -> V_73 ) ;
if ( V_68 -> V_74 == V_75 ) {
V_68 -> V_74 = 0 ;
V_68 -> V_70 |= V_76 ;
continue;
}
V_64 = V_59 -> V_61 -> V_8 -> V_73 ( V_68 -> V_74 ) ;
F_37 ( ! V_64 -> V_77 ) ;
V_68 -> V_74 = V_64 -> V_77 - V_78 ;
}
}
}
static void F_38 ( struct V_79 * V_61 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_61 -> V_80 ; V_65 ++ )
F_9 ( V_61 -> V_81 [ V_65 ] ) ;
F_30 ( V_61 -> V_81 ) ;
}
static void F_39 ( struct V_82 * V_83 )
{
struct V_79 * V_61 = F_8 ( V_83 , struct V_79 , V_83 ) ;
F_38 ( V_61 ) ;
F_40 ( V_61 -> V_59 ) ;
}
void F_41 ( struct V_58 * V_59 )
{
if ( F_10 ( & V_59 -> V_61 -> V_16 ) ) {
V_59 -> V_61 -> V_59 = V_59 ;
F_42 ( & V_59 -> V_61 -> V_83 , F_39 ) ;
}
}
void F_43 ( struct V_58 * V_59 )
{
if ( F_10 ( & V_59 -> V_61 -> V_16 ) ) {
F_38 ( V_59 -> V_61 ) ;
F_40 ( V_59 ) ;
}
}
static int F_44 ( struct V_17 * V_17 , struct V_18 * V_19 )
{
struct V_58 * V_59 = V_19 -> V_20 ;
F_41 ( V_59 ) ;
return 0 ;
}
static struct V_58 * F_45 ( struct V_28 V_29 )
{
struct V_58 * V_59 ;
if ( ! V_29 . V_18 )
return F_4 ( - V_30 ) ;
if ( V_29 . V_18 -> V_31 != & V_84 ) {
F_21 ( V_29 ) ;
return F_4 ( - V_10 ) ;
}
V_59 = V_29 . V_18 -> V_20 ;
return V_59 ;
}
struct V_58 * F_46 ( T_3 V_37 )
{
struct V_28 V_29 = F_24 ( V_37 ) ;
struct V_58 * V_59 ;
V_59 = F_45 ( V_29 ) ;
if ( F_3 ( V_59 ) )
return V_59 ;
F_47 ( & V_59 -> V_61 -> V_16 ) ;
F_21 ( V_29 ) ;
return V_59 ;
}
static int F_48 ( union V_2 * V_3 )
{
enum V_57 type = V_3 -> V_85 ;
struct V_58 * V_59 ;
int V_22 ;
char V_86 [ 128 ] ;
bool V_87 ;
if ( F_16 ( V_88 ) )
return - V_10 ;
if ( F_49 ( V_86 , F_22 ( V_3 -> V_86 ) ,
sizeof( V_86 ) - 1 ) < 0 )
return - V_45 ;
V_86 [ sizeof( V_86 ) - 1 ] = 0 ;
V_87 = F_50 ( V_86 ) ;
if ( V_3 -> V_89 >= V_90 )
return - V_10 ;
if ( type == V_91 &&
V_3 -> V_92 != V_93 )
return - V_10 ;
V_59 = F_51 ( F_52 ( V_3 -> V_89 ) , V_43 ) ;
if ( ! V_59 )
return - V_41 ;
V_59 -> V_66 = V_3 -> V_89 ;
V_22 = - V_45 ;
if ( F_26 ( V_59 -> V_94 , F_22 ( V_3 -> V_94 ) ,
V_59 -> V_66 * sizeof( struct V_67 ) ) != 0 )
goto V_95;
V_59 -> V_96 = NULL ;
V_59 -> V_97 = false ;
F_18 ( & V_59 -> V_61 -> V_16 , 1 ) ;
V_59 -> V_98 = V_87 ;
V_22 = F_34 ( type , V_59 ) ;
if ( V_22 < 0 )
goto V_95;
V_22 = F_53 ( & V_59 , V_3 ) ;
if ( V_22 < 0 )
goto F_38;
F_36 ( V_59 ) ;
V_22 = F_54 ( V_59 ) ;
if ( V_22 < 0 )
goto F_38;
V_22 = F_19 ( L_2 , & V_84 , V_59 , V_25 | V_26 ) ;
if ( V_22 < 0 )
goto F_38;
return V_22 ;
F_38:
F_38 ( V_59 -> V_61 ) ;
V_95:
F_40 ( V_59 ) ;
return V_22 ;
}
