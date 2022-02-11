static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 -> V_6 ;
struct V_8 * V_9 = V_4 -> V_7 -> V_10 ;
if ( V_6 ) {
V_6 -> V_11 . V_12 = V_3 == V_13 ?
V_14 : V_15 ;
F_3 ( V_6 ) ;
}
if ( V_9 )
F_4 ( V_9 ,
V_3 == V_13 ? 1 : 0 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_16 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_17 * V_3 ,
struct V_17 * V_18 )
{
}
static struct V_1 * F_8 ( struct V_19 * V_20 ,
struct V_21 * V_7 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
int V_22 ;
V_4 = F_9 ( V_20 -> V_20 , sizeof( * V_4 ) ,
V_23 ) ;
if ( ! V_4 ) {
F_10 ( V_20 -> V_20 , L_1 ) ;
return NULL ;
}
V_4 -> V_7 = V_7 ;
V_2 = & V_4 -> V_24 ;
V_2 -> V_25 = 1 ;
V_22 = F_11 ( V_20 , V_2 , & V_26 ,
V_27 , NULL ) ;
if ( V_22 < 0 )
goto V_28;
F_12 ( V_2 , & V_29 ) ;
return V_2 ;
V_28:
F_13 ( V_2 ) ;
return NULL ;
}
static void F_14 ( struct V_30 * V_31 )
{
F_15 ( V_31 ) ;
F_16 ( V_31 ) ;
}
static enum V_32 F_17 (
struct V_30 * V_31 ,
bool V_33 )
{
return V_34 ;
}
static int F_18 ( struct V_30 * V_31 )
{
struct V_19 * V_20 = V_31 -> V_20 ;
struct V_35 * V_35 = F_19 ( V_31 ) ;
struct V_36 * V_37 = V_35 -> V_7 -> V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 -> V_39 ; V_38 ++ ) {
struct V_17 * V_3 = F_20 ( V_20 ) ;
struct V_40 V_41 ;
if ( F_21 ( V_37 , & V_41 , V_38 ) )
break;
F_22 ( & V_41 , V_3 ) ;
V_3 -> type = V_42 ;
if ( V_37 -> V_43 == V_38 )
V_3 -> type |= V_44 ;
F_23 ( V_3 ) ;
F_24 ( V_31 , V_3 ) ;
}
return V_38 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_17 * V_3 )
{
struct V_45 * V_46 = V_31 -> V_20 -> V_47 ;
return F_26 ( V_46 -> V_48 , V_3 ) ;
}
static struct V_1 * F_27 (
struct V_30 * V_31 )
{
struct V_35 * V_35 = F_19 ( V_31 ) ;
return V_35 -> V_2 ;
}
static struct V_30 * F_28 ( struct V_19 * V_20 ,
struct V_21 * V_7 , struct V_1 * V_2 )
{
struct V_35 * V_35 ;
struct V_30 * V_31 ;
int V_22 ;
V_35 = F_9 ( V_20 -> V_20 , sizeof( * V_35 ) ,
V_23 ) ;
if ( ! V_35 ) {
F_10 ( V_20 -> V_20 , L_1 ) ;
return NULL ;
}
V_35 -> V_2 = V_2 ;
V_35 -> V_7 = V_7 ;
V_31 = & V_35 -> V_24 ;
F_29 ( V_20 , V_31 , & V_49 ,
V_50 ) ;
F_30 ( V_31 , & V_51 ) ;
V_31 -> V_52 = 0 ;
V_31 -> V_53 = 0 ;
V_22 = F_31 ( V_31 , V_2 ) ;
if ( V_22 )
goto V_28;
F_32 ( V_31 ) ;
return V_31 ;
V_28:
F_14 ( V_31 ) ;
return NULL ;
}
static int F_33 ( struct V_54 * V_7 , struct V_19 * V_20 )
{
struct V_21 * V_55 = F_34 ( V_7 ) ;
struct V_45 * V_46 = V_20 -> V_47 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
V_2 = F_8 ( V_20 , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_31 = F_28 ( V_20 , V_55 , V_2 ) ;
if ( ! V_31 )
return - V_56 ;
V_46 -> V_57 [ V_46 -> V_58 ++ ] = V_2 ;
V_46 -> V_59 [ V_46 -> V_60 ++ ] = V_31 ;
F_35 ( V_46 -> V_48 ,
F_2 ( V_2 ) -> V_7 -> V_61 ) ;
return 0 ;
}
static struct V_62 * F_36 ( struct V_63 * V_64 )
{
struct V_63 * V_65 ;
struct V_62 * V_61 ;
int V_22 = 0 ;
if ( ! V_64 ) {
F_37 ( L_2 , V_66 ) ;
return NULL ;
}
V_65 = F_38 ( V_64 , L_3 ) ;
if ( ! V_65 ) {
F_37 ( L_4 , V_66 ) ;
return NULL ;
}
V_61 = F_39 ( sizeof( * V_61 ) , V_23 ) ;
if ( ! V_61 ) {
F_37 ( L_5 , V_66 ) ;
F_40 ( V_65 ) ;
return NULL ;
}
V_22 |= F_41 ( V_65 , L_6 , & V_61 -> V_67 ) ;
V_22 |= F_41 ( V_65 , L_7 , & V_61 -> V_68 ) ;
V_22 |= F_41 ( V_65 , L_8 , & V_61 -> V_69 ) ;
V_22 |= F_41 ( V_65 , L_9 , & V_61 -> V_70 ) ;
V_22 |= F_41 ( V_65 , L_10 , & V_61 -> V_71 ) ;
V_22 |= F_41 ( V_65 , L_11 , & V_61 -> V_72 ) ;
V_22 |= F_41 ( V_65 , L_12 , & V_61 -> V_73 ) ;
V_22 |= F_41 ( V_65 , L_13 , & V_61 -> V_74 ) ;
V_22 |= F_41 ( V_65 , L_14 , & V_61 -> V_75 ) ;
V_61 -> V_76 = F_42 ( V_65 , L_15 ) ;
V_61 -> V_77 = F_42 ( V_65 , L_16 ) ;
if ( V_22 ) {
F_37 ( L_17 , V_66 ) ;
F_43 ( V_61 ) ;
F_40 ( V_65 ) ;
return NULL ;
}
F_40 ( V_65 ) ;
return V_61 ;
}
static int F_44 ( struct V_78 * V_79 )
{
struct V_63 * V_80 , * V_81 = V_79 -> V_20 . V_82 ;
struct V_21 * V_55 ;
struct V_54 * V_7 ;
struct V_83 * V_83 ;
int V_22 ;
if ( ! V_81 ) {
F_10 ( & V_79 -> V_20 , L_18 ) ;
return - V_84 ;
}
V_55 = F_9 ( & V_79 -> V_20 , sizeof( * V_55 ) , V_23 ) ;
if ( ! V_55 )
return - V_56 ;
V_80 = F_45 ( V_81 , L_19 , 0 ) ;
if ( V_80 ) {
V_55 -> V_6 = F_46 ( V_80 ) ;
F_40 ( V_80 ) ;
if ( ! V_55 -> V_6 )
return - V_85 ;
F_47 ( & V_79 -> V_20 , L_20 ) ;
}
V_55 -> V_10 = F_48 ( & V_79 -> V_20 , L_21 ,
V_86 ) ;
if ( F_49 ( V_55 -> V_10 ) ) {
V_22 = F_50 ( V_55 -> V_10 ) ;
F_10 ( & V_79 -> V_20 , L_22 ) ;
goto V_87;
}
if ( V_55 -> V_10 )
F_47 ( & V_79 -> V_20 , L_23 ) ;
V_7 = & V_55 -> V_24 ;
V_79 -> V_20 . V_88 = V_7 ;
F_51 ( V_7 , L_24 , & V_89 ) ;
V_83 = F_52 ( & V_79 -> V_20 ) ;
if ( F_49 ( V_83 ) )
F_53 ( & V_79 -> V_20 , L_25 ) ;
V_55 -> V_37 = F_54 ( V_81 ) ;
if ( ! V_55 -> V_37 ) {
F_10 ( & V_79 -> V_20 , L_26 ) ;
V_22 = - V_90 ;
goto V_91;
}
V_55 -> V_61 = F_36 ( V_81 ) ;
if ( ! V_55 -> V_61 ) {
F_10 ( & V_79 -> V_20 , L_27 ) ;
V_22 = - V_90 ;
goto V_92;
}
return 0 ;
V_92:
F_55 ( V_55 -> V_37 ) ;
V_91:
F_56 ( V_7 ) ;
V_87:
if ( V_55 -> V_6 )
F_57 ( & V_55 -> V_6 -> V_20 ) ;
return V_22 ;
}
static int F_58 ( struct V_78 * V_79 )
{
struct V_54 * V_7 = F_59 ( & V_79 -> V_20 ) ;
struct V_21 * V_55 = F_34 ( V_7 ) ;
struct V_5 * V_6 = V_55 -> V_6 ;
if ( V_6 )
F_57 ( & V_6 -> V_20 ) ;
F_55 ( V_55 -> V_37 ) ;
F_56 ( V_7 ) ;
F_43 ( V_55 -> V_61 ) ;
return 0 ;
}
int T_1 F_60 ( void )
{
return F_61 ( & V_93 ) ;
}
void T_2 F_62 ( void )
{
F_63 ( & V_93 ) ;
}
