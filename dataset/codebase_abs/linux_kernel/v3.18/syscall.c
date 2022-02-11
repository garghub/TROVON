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
F_9 ( V_6 ) ;
return 0 ;
}
static int F_14 ( union V_2 * V_3 )
{
struct V_1 * V_6 ;
int V_21 ;
V_21 = F_15 ( V_22 ) ;
if ( V_21 )
return - V_10 ;
V_6 = F_1 ( V_3 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
F_17 ( & V_6 -> V_16 , 1 ) ;
V_21 = F_18 ( L_1 , & V_23 , V_6 , V_24 | V_25 ) ;
if ( V_21 < 0 )
goto V_26;
return V_21 ;
V_26:
V_6 -> V_8 -> V_15 ( V_6 ) ;
return V_21 ;
}
struct V_1 * F_19 ( struct V_27 V_28 )
{
struct V_1 * V_6 ;
if ( ! V_28 . V_18 )
return F_4 ( - V_29 ) ;
if ( V_28 . V_18 -> V_30 != & V_23 ) {
F_20 ( V_28 ) ;
return F_4 ( - V_10 ) ;
}
V_6 = V_28 . V_18 -> V_20 ;
return V_6 ;
}
static void T_1 * F_21 ( T_2 V_31 )
{
return ( void T_1 * ) ( unsigned long ) V_31 ;
}
static int F_22 ( union V_2 * V_3 )
{
void T_1 * V_32 = F_21 ( V_3 -> V_33 ) ;
void T_1 * V_34 = F_21 ( V_3 -> V_35 ) ;
int V_36 = V_3 -> V_37 ;
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_1 * V_6 ;
void * V_33 , * V_35 ;
int V_21 ;
if ( F_15 ( V_38 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_39 ;
V_33 = F_24 ( V_6 -> V_40 , V_41 ) ;
if ( ! V_33 )
goto V_42;
V_21 = - V_43 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_40 ) != 0 )
goto V_44;
V_21 = - V_45 ;
F_26 () ;
V_35 = V_6 -> V_8 -> F_22 ( V_6 , V_33 ) ;
if ( ! V_35 )
goto V_46;
V_21 = - V_43 ;
if ( F_27 ( V_34 , V_35 , V_6 -> V_47 ) != 0 )
goto V_46;
V_21 = 0 ;
V_46:
F_28 () ;
V_44:
F_29 ( V_33 ) ;
V_42:
F_20 ( V_28 ) ;
return V_21 ;
}
static int F_30 ( union V_2 * V_3 )
{
void T_1 * V_32 = F_21 ( V_3 -> V_33 ) ;
void T_1 * V_34 = F_21 ( V_3 -> V_35 ) ;
int V_36 = V_3 -> V_37 ;
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_1 * V_6 ;
void * V_33 , * V_35 ;
int V_21 ;
if ( F_15 ( V_48 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_39 ;
V_33 = F_24 ( V_6 -> V_40 , V_41 ) ;
if ( ! V_33 )
goto V_42;
V_21 = - V_43 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_40 ) != 0 )
goto V_44;
V_21 = - V_39 ;
V_35 = F_24 ( V_6 -> V_47 , V_41 ) ;
if ( ! V_35 )
goto V_44;
V_21 = - V_43 ;
if ( F_25 ( V_35 , V_34 , V_6 -> V_47 ) != 0 )
goto V_49;
F_26 () ;
V_21 = V_6 -> V_8 -> F_30 ( V_6 , V_33 , V_35 ) ;
F_28 () ;
V_49:
F_29 ( V_35 ) ;
V_44:
F_29 ( V_33 ) ;
V_42:
F_20 ( V_28 ) ;
return V_21 ;
}
static int F_31 ( union V_2 * V_3 )
{
void T_1 * V_32 = F_21 ( V_3 -> V_33 ) ;
int V_36 = V_3 -> V_37 ;
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_1 * V_6 ;
void * V_33 ;
int V_21 ;
if ( F_15 ( V_50 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_39 ;
V_33 = F_24 ( V_6 -> V_40 , V_41 ) ;
if ( ! V_33 )
goto V_42;
V_21 = - V_43 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_40 ) != 0 )
goto V_44;
F_26 () ;
V_21 = V_6 -> V_8 -> F_31 ( V_6 , V_33 ) ;
F_28 () ;
V_44:
F_29 ( V_33 ) ;
V_42:
F_20 ( V_28 ) ;
return V_21 ;
}
static int F_32 ( union V_2 * V_3 )
{
void T_1 * V_32 = F_21 ( V_3 -> V_33 ) ;
void T_1 * V_51 = F_21 ( V_3 -> V_52 ) ;
int V_36 = V_3 -> V_37 ;
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_1 * V_6 ;
void * V_33 , * V_52 ;
int V_21 ;
if ( F_15 ( V_53 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_39 ;
V_33 = F_24 ( V_6 -> V_40 , V_41 ) ;
if ( ! V_33 )
goto V_42;
V_21 = - V_43 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_40 ) != 0 )
goto V_44;
V_21 = - V_39 ;
V_52 = F_24 ( V_6 -> V_40 , V_41 ) ;
if ( ! V_52 )
goto V_44;
F_26 () ;
V_21 = V_6 -> V_8 -> F_32 ( V_6 , V_33 , V_52 ) ;
F_28 () ;
if ( V_21 )
goto V_54;
V_21 = - V_43 ;
if ( F_27 ( V_51 , V_52 , V_6 -> V_40 ) != 0 )
goto V_54;
V_21 = 0 ;
V_54:
F_29 ( V_52 ) ;
V_44:
F_29 ( V_33 ) ;
V_42:
F_20 ( V_28 ) ;
return V_21 ;
}
static int F_33 ( enum V_55 type , struct V_56 * V_57 )
{
struct V_58 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_57 -> V_59 -> V_8 = V_5 -> V_8 ;
V_57 -> V_59 -> V_60 = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_34 ( struct V_58 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_61 ) ;
}
static void F_35 ( struct V_56 * V_57 )
{
const struct V_62 * V_63 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_57 -> V_65 ; V_64 ++ ) {
struct V_66 * V_67 = & V_57 -> V_68 [ V_64 ] ;
if ( V_67 -> V_69 == ( V_70 | V_71 ) ) {
F_36 ( ! V_57 -> V_59 -> V_8 -> V_72 ) ;
V_63 = V_57 -> V_59 -> V_8 -> V_72 ( V_67 -> V_73 ) ;
F_36 ( ! V_63 -> V_74 ) ;
V_67 -> V_73 = V_63 -> V_74 - V_75 ;
}
}
}
static void F_37 ( struct V_76 * V_59 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_59 -> V_77 ; V_64 ++ )
F_9 ( V_59 -> V_78 [ V_64 ] ) ;
F_29 ( V_59 -> V_78 ) ;
}
void F_38 ( struct V_56 * V_57 )
{
if ( F_10 ( & V_57 -> V_59 -> V_16 ) ) {
F_37 ( V_57 -> V_59 ) ;
F_39 ( V_57 ) ;
}
}
static int F_40 ( struct V_17 * V_17 , struct V_18 * V_19 )
{
struct V_56 * V_57 = V_19 -> V_20 ;
F_38 ( V_57 ) ;
return 0 ;
}
static struct V_56 * F_41 ( struct V_27 V_28 )
{
struct V_56 * V_57 ;
if ( ! V_28 . V_18 )
return F_4 ( - V_29 ) ;
if ( V_28 . V_18 -> V_30 != & V_79 ) {
F_20 ( V_28 ) ;
return F_4 ( - V_10 ) ;
}
V_57 = V_28 . V_18 -> V_20 ;
return V_57 ;
}
struct V_56 * F_42 ( T_3 V_36 )
{
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_56 * V_57 ;
V_57 = F_41 ( V_28 ) ;
if ( F_3 ( V_57 ) )
return V_57 ;
F_43 ( & V_57 -> V_59 -> V_16 ) ;
F_20 ( V_28 ) ;
return V_57 ;
}
static int F_44 ( union V_2 * V_3 )
{
enum V_55 type = V_3 -> V_60 ;
struct V_56 * V_57 ;
int V_21 ;
char V_80 [ 128 ] ;
bool V_81 ;
if ( F_15 ( V_82 ) )
return - V_10 ;
if ( F_45 ( V_80 , F_21 ( V_3 -> V_80 ) ,
sizeof( V_80 ) - 1 ) < 0 )
return - V_43 ;
V_80 [ sizeof( V_80 ) - 1 ] = 0 ;
V_81 = F_46 ( V_80 ) ;
if ( V_3 -> V_83 >= V_84 )
return - V_10 ;
V_57 = F_47 ( F_48 ( V_3 -> V_83 ) , V_41 ) ;
if ( ! V_57 )
return - V_39 ;
V_57 -> V_65 = V_3 -> V_83 ;
V_21 = - V_43 ;
if ( F_25 ( V_57 -> V_85 , F_21 ( V_3 -> V_85 ) ,
V_57 -> V_65 * sizeof( struct V_66 ) ) != 0 )
goto V_86;
V_57 -> V_87 = NULL ;
V_57 -> V_88 = false ;
F_17 ( & V_57 -> V_59 -> V_16 , 1 ) ;
V_57 -> V_59 -> V_89 = V_81 ;
V_21 = F_33 ( type , V_57 ) ;
if ( V_21 < 0 )
goto V_86;
V_21 = F_49 ( V_57 , V_3 ) ;
if ( V_21 < 0 )
goto F_37;
F_35 ( V_57 ) ;
F_50 ( V_57 ) ;
V_21 = F_18 ( L_2 , & V_79 , V_57 , V_24 | V_25 ) ;
if ( V_21 < 0 )
goto F_37;
return V_21 ;
F_37:
F_37 ( V_57 -> V_59 ) ;
V_86:
F_39 ( V_57 ) ;
return V_21 ;
}
