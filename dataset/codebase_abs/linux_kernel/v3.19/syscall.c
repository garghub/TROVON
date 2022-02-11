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
void * V_33 , * V_35 , * V_38 ;
int V_21 ;
if ( F_15 ( V_39 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_40 ;
V_33 = F_24 ( V_6 -> V_41 , V_42 ) ;
if ( ! V_33 )
goto V_43;
V_21 = - V_44 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_41 ) != 0 )
goto V_45;
V_21 = - V_40 ;
V_35 = F_24 ( V_6 -> V_46 , V_42 ) ;
if ( ! V_35 )
goto V_45;
F_26 () ;
V_38 = V_6 -> V_8 -> F_22 ( V_6 , V_33 ) ;
if ( V_38 )
memcpy ( V_35 , V_38 , V_6 -> V_46 ) ;
F_27 () ;
V_21 = - V_47 ;
if ( ! V_38 )
goto V_48;
V_21 = - V_44 ;
if ( F_28 ( V_34 , V_35 , V_6 -> V_46 ) != 0 )
goto V_48;
V_21 = 0 ;
V_48:
F_29 ( V_35 ) ;
V_45:
F_29 ( V_33 ) ;
V_43:
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
if ( F_15 ( V_49 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_40 ;
V_33 = F_24 ( V_6 -> V_41 , V_42 ) ;
if ( ! V_33 )
goto V_43;
V_21 = - V_44 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_41 ) != 0 )
goto V_45;
V_21 = - V_40 ;
V_35 = F_24 ( V_6 -> V_46 , V_42 ) ;
if ( ! V_35 )
goto V_45;
V_21 = - V_44 ;
if ( F_25 ( V_35 , V_34 , V_6 -> V_46 ) != 0 )
goto V_48;
F_26 () ;
V_21 = V_6 -> V_8 -> F_30 ( V_6 , V_33 , V_35 , V_3 -> V_50 ) ;
F_27 () ;
V_48:
F_29 ( V_35 ) ;
V_45:
F_29 ( V_33 ) ;
V_43:
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
if ( F_15 ( V_51 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_40 ;
V_33 = F_24 ( V_6 -> V_41 , V_42 ) ;
if ( ! V_33 )
goto V_43;
V_21 = - V_44 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_41 ) != 0 )
goto V_45;
F_26 () ;
V_21 = V_6 -> V_8 -> F_31 ( V_6 , V_33 ) ;
F_27 () ;
V_45:
F_29 ( V_33 ) ;
V_43:
F_20 ( V_28 ) ;
return V_21 ;
}
static int F_32 ( union V_2 * V_3 )
{
void T_1 * V_32 = F_21 ( V_3 -> V_33 ) ;
void T_1 * V_52 = F_21 ( V_3 -> V_53 ) ;
int V_36 = V_3 -> V_37 ;
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_1 * V_6 ;
void * V_33 , * V_53 ;
int V_21 ;
if ( F_15 ( V_54 ) )
return - V_10 ;
V_6 = F_19 ( V_28 ) ;
if ( F_3 ( V_6 ) )
return F_16 ( V_6 ) ;
V_21 = - V_40 ;
V_33 = F_24 ( V_6 -> V_41 , V_42 ) ;
if ( ! V_33 )
goto V_43;
V_21 = - V_44 ;
if ( F_25 ( V_33 , V_32 , V_6 -> V_41 ) != 0 )
goto V_45;
V_21 = - V_40 ;
V_53 = F_24 ( V_6 -> V_41 , V_42 ) ;
if ( ! V_53 )
goto V_45;
F_26 () ;
V_21 = V_6 -> V_8 -> F_32 ( V_6 , V_33 , V_53 ) ;
F_27 () ;
if ( V_21 )
goto V_55;
V_21 = - V_44 ;
if ( F_28 ( V_52 , V_53 , V_6 -> V_41 ) != 0 )
goto V_55;
V_21 = 0 ;
V_55:
F_29 ( V_53 ) ;
V_45:
F_29 ( V_33 ) ;
V_43:
F_20 ( V_28 ) ;
return V_21 ;
}
static int F_33 ( enum V_56 type , struct V_57 * V_58 )
{
struct V_59 * V_5 ;
F_2 (tl, &bpf_prog_types, list_node) {
if ( V_5 -> type == type ) {
V_58 -> V_60 -> V_8 = V_5 -> V_8 ;
V_58 -> V_60 -> V_61 = type ;
return 0 ;
}
}
return - V_10 ;
}
void F_34 ( struct V_59 * V_5 )
{
F_6 ( & V_5 -> V_11 , & V_62 ) ;
}
static void F_35 ( struct V_57 * V_58 )
{
const struct V_63 * V_64 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_58 -> V_66 ; V_65 ++ ) {
struct V_67 * V_68 = & V_58 -> V_69 [ V_65 ] ;
if ( V_68 -> V_70 == ( V_71 | V_72 ) ) {
F_36 ( ! V_58 -> V_60 -> V_8 -> V_73 ) ;
V_64 = V_58 -> V_60 -> V_8 -> V_73 ( V_68 -> V_74 ) ;
F_36 ( ! V_64 -> V_75 ) ;
V_68 -> V_74 = V_64 -> V_75 - V_76 ;
}
}
}
static void F_37 ( struct V_77 * V_60 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_60 -> V_78 ; V_65 ++ )
F_9 ( V_60 -> V_79 [ V_65 ] ) ;
F_29 ( V_60 -> V_79 ) ;
}
void F_38 ( struct V_57 * V_58 )
{
if ( F_10 ( & V_58 -> V_60 -> V_16 ) ) {
F_37 ( V_58 -> V_60 ) ;
F_39 ( V_58 ) ;
}
}
static int F_40 ( struct V_17 * V_17 , struct V_18 * V_19 )
{
struct V_57 * V_58 = V_19 -> V_20 ;
F_38 ( V_58 ) ;
return 0 ;
}
static struct V_57 * F_41 ( struct V_27 V_28 )
{
struct V_57 * V_58 ;
if ( ! V_28 . V_18 )
return F_4 ( - V_29 ) ;
if ( V_28 . V_18 -> V_30 != & V_80 ) {
F_20 ( V_28 ) ;
return F_4 ( - V_10 ) ;
}
V_58 = V_28 . V_18 -> V_20 ;
return V_58 ;
}
struct V_57 * F_42 ( T_3 V_36 )
{
struct V_27 V_28 = F_23 ( V_36 ) ;
struct V_57 * V_58 ;
V_58 = F_41 ( V_28 ) ;
if ( F_3 ( V_58 ) )
return V_58 ;
F_43 ( & V_58 -> V_60 -> V_16 ) ;
F_20 ( V_28 ) ;
return V_58 ;
}
static int F_44 ( union V_2 * V_3 )
{
enum V_56 type = V_3 -> V_61 ;
struct V_57 * V_58 ;
int V_21 ;
char V_81 [ 128 ] ;
bool V_82 ;
if ( F_15 ( V_83 ) )
return - V_10 ;
if ( F_45 ( V_81 , F_21 ( V_3 -> V_81 ) ,
sizeof( V_81 ) - 1 ) < 0 )
return - V_44 ;
V_81 [ sizeof( V_81 ) - 1 ] = 0 ;
V_82 = F_46 ( V_81 ) ;
if ( V_3 -> V_84 >= V_85 )
return - V_10 ;
V_58 = F_47 ( F_48 ( V_3 -> V_84 ) , V_42 ) ;
if ( ! V_58 )
return - V_40 ;
V_58 -> V_66 = V_3 -> V_84 ;
V_21 = - V_44 ;
if ( F_25 ( V_58 -> V_86 , F_21 ( V_3 -> V_86 ) ,
V_58 -> V_66 * sizeof( struct V_67 ) ) != 0 )
goto V_87;
V_58 -> V_88 = NULL ;
V_58 -> V_89 = false ;
F_17 ( & V_58 -> V_60 -> V_16 , 1 ) ;
V_58 -> V_60 -> V_90 = V_82 ;
V_21 = F_33 ( type , V_58 ) ;
if ( V_21 < 0 )
goto V_87;
V_21 = F_49 ( V_58 , V_3 ) ;
if ( V_21 < 0 )
goto F_37;
F_35 ( V_58 ) ;
F_50 ( V_58 ) ;
V_21 = F_18 ( L_2 , & V_80 , V_58 , V_24 | V_25 ) ;
if ( V_21 < 0 )
goto F_37;
return V_21 ;
F_37:
F_37 ( V_58 -> V_60 ) ;
V_87:
F_39 ( V_58 ) ;
return V_21 ;
}
