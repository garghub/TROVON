static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_3 -> V_7 -> V_6 ;
struct V_8 * V_9 = V_3 -> V_7 -> V_10 ;
if ( V_6 ) {
V_6 -> V_11 . V_12 = V_4 == V_13 ?
V_14 : V_15 ;
F_6 ( V_6 ) ;
}
if ( V_9 )
F_7 ( V_9 ,
V_4 == V_13 ? 1 : 0 ) ;
}
static bool F_8 ( struct V_1 * V_2 ,
const struct V_16 * V_4 ,
struct V_16 * V_17 )
{
return true ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_18 ) ;
F_10 ( V_2 -> V_19 , V_3 -> V_7 -> V_20 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_16 * V_4 ,
struct V_16 * V_17 )
{
}
static struct V_1 * F_13 ( struct V_21 * V_22 ,
struct V_23 * V_7 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_24 ;
V_3 = F_14 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 ) {
F_15 ( V_22 -> V_22 , L_1 ) ;
return NULL ;
}
V_3 -> V_7 = V_7 ;
V_2 = & V_3 -> V_26 ;
V_2 -> V_27 = 1 ;
V_24 = F_16 ( V_22 , V_2 , & V_28 ,
V_29 ) ;
if ( V_24 < 0 )
goto V_30;
F_17 ( V_2 , & V_31 ) ;
return V_2 ;
V_30:
F_1 ( V_2 ) ;
return NULL ;
}
static void F_18 ( struct V_32 * V_33 )
{
struct V_34 * V_34 = F_19 ( V_33 ) ;
F_20 ( V_33 ) ;
F_21 ( V_33 ) ;
F_4 ( V_34 ) ;
}
static enum V_35 F_22 (
struct V_32 * V_33 ,
bool V_36 )
{
return V_37 ;
}
static int F_23 ( struct V_32 * V_33 )
{
struct V_21 * V_22 = V_33 -> V_22 ;
struct V_34 * V_34 = F_19 ( V_33 ) ;
struct V_38 * V_39 = V_34 -> V_7 -> V_39 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_39 -> V_41 ; V_40 ++ ) {
struct V_16 * V_4 = F_24 ( V_22 ) ;
struct V_42 V_43 ;
if ( F_25 ( V_39 , & V_43 , V_40 ) )
break;
F_26 ( & V_43 , V_4 ) ;
V_4 -> type = V_44 ;
if ( V_39 -> V_45 == V_40 )
V_4 -> type |= V_46 ;
F_27 ( V_4 ) ;
F_28 ( V_33 , V_4 ) ;
}
return V_40 ;
}
static int F_29 ( struct V_32 * V_33 ,
struct V_16 * V_4 )
{
struct V_47 * V_48 = V_33 -> V_22 -> V_49 ;
return F_30 ( V_48 -> V_19 , V_4 ) ;
}
static struct V_1 * F_31 (
struct V_32 * V_33 )
{
struct V_34 * V_34 = F_19 ( V_33 ) ;
return V_34 -> V_2 ;
}
static struct V_32 * F_32 ( struct V_21 * V_22 ,
struct V_23 * V_7 , struct V_1 * V_2 )
{
struct V_34 * V_34 ;
struct V_32 * V_33 ;
int V_24 ;
V_34 = F_14 ( sizeof( * V_34 ) , V_25 ) ;
if ( ! V_34 ) {
F_15 ( V_22 -> V_22 , L_1 ) ;
return NULL ;
}
V_34 -> V_2 = V_2 ;
V_34 -> V_7 = V_7 ;
V_33 = & V_34 -> V_26 ;
F_33 ( V_22 , V_33 , & V_50 ,
V_51 ) ;
F_34 ( V_33 , & V_52 ) ;
V_33 -> V_53 = 0 ;
V_33 -> V_54 = 0 ;
V_24 = F_35 ( V_33 , V_2 ) ;
if ( V_24 )
goto V_30;
F_36 ( V_33 ) ;
return V_33 ;
V_30:
F_18 ( V_33 ) ;
return NULL ;
}
static int F_37 ( struct V_55 * V_7 , struct V_21 * V_22 )
{
struct V_23 * V_56 = F_38 ( V_7 ) ;
struct V_47 * V_48 = V_22 -> V_49 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = F_13 ( V_22 , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_33 = F_32 ( V_22 , V_56 , V_2 ) ;
if ( ! V_33 )
return - V_57 ;
V_48 -> V_58 [ V_48 -> V_59 ++ ] = V_2 ;
V_48 -> V_60 [ V_48 -> V_61 ++ ] = V_33 ;
return 0 ;
}
static struct V_62 * F_39 ( struct V_63 * V_64 )
{
struct V_63 * V_65 ;
struct V_62 * V_20 ;
int V_24 = 0 ;
if ( ! V_64 ) {
F_40 ( L_2 , V_66 ) ;
return NULL ;
}
V_65 = F_41 ( V_64 , L_3 ) ;
if ( ! V_65 ) {
F_40 ( L_4 , V_66 ) ;
return NULL ;
}
V_20 = F_14 ( sizeof( * V_20 ) , V_25 ) ;
if ( ! V_20 ) {
F_40 ( L_5 , V_66 ) ;
F_42 ( V_65 ) ;
return NULL ;
}
V_24 |= F_43 ( V_65 , L_6 , & V_20 -> V_67 ) ;
V_24 |= F_43 ( V_65 , L_7 , & V_20 -> V_68 ) ;
V_24 |= F_43 ( V_65 , L_8 , & V_20 -> V_69 ) ;
V_24 |= F_43 ( V_65 , L_9 , & V_20 -> V_70 ) ;
V_24 |= F_43 ( V_65 , L_10 , & V_20 -> V_71 ) ;
V_24 |= F_43 ( V_65 , L_11 , & V_20 -> V_72 ) ;
V_24 |= F_43 ( V_65 , L_12 , & V_20 -> V_73 ) ;
V_24 |= F_43 ( V_65 , L_13 , & V_20 -> V_74 ) ;
V_24 |= F_43 ( V_65 , L_14 , & V_20 -> V_75 ) ;
V_20 -> V_76 = F_44 ( V_65 , L_15 ) ;
V_20 -> V_77 = F_44 ( V_65 , L_16 ) ;
if ( V_24 ) {
F_40 ( L_17 , V_66 ) ;
F_4 ( V_20 ) ;
F_42 ( V_65 ) ;
return NULL ;
}
F_42 ( V_65 ) ;
return V_20 ;
}
static int F_45 ( struct V_78 * V_79 )
{
struct V_63 * V_80 , * V_81 = V_79 -> V_22 . V_82 ;
struct V_23 * V_56 ;
struct V_55 * V_7 ;
struct V_83 * V_83 ;
int V_24 ;
if ( ! V_81 ) {
F_15 ( & V_79 -> V_22 , L_18 ) ;
return - V_84 ;
}
V_56 = F_46 ( & V_79 -> V_22 , sizeof( * V_56 ) , V_25 ) ;
if ( ! V_56 )
return - V_57 ;
V_80 = F_47 ( V_81 , L_19 , 0 ) ;
if ( V_80 ) {
V_56 -> V_6 = F_48 ( V_80 ) ;
F_42 ( V_80 ) ;
if ( ! V_56 -> V_6 )
return - V_85 ;
F_49 ( & V_79 -> V_22 , L_20 ) ;
}
V_56 -> V_10 = F_50 ( & V_79 -> V_22 , L_21 ) ;
if ( F_51 ( V_56 -> V_10 ) ) {
V_24 = F_52 ( V_56 -> V_10 ) ;
if ( V_24 != - V_86 ) {
F_15 ( & V_79 -> V_22 , L_22 ) ;
goto V_87;
}
V_56 -> V_10 = NULL ;
} else {
V_24 = F_53 ( V_56 -> V_10 , 0 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_79 -> V_22 , L_23 ) ;
goto V_87;
}
F_49 ( & V_79 -> V_22 , L_24 ) ;
}
V_7 = & V_56 -> V_26 ;
V_79 -> V_22 . V_88 = V_7 ;
F_54 ( V_7 , L_25 , & V_89 ) ;
V_83 = F_55 ( & V_79 -> V_22 ) ;
if ( F_51 ( V_83 ) )
F_56 ( & V_79 -> V_22 , L_26 ) ;
V_56 -> V_39 = F_57 ( V_81 ) ;
if ( ! V_56 -> V_39 ) {
F_15 ( & V_79 -> V_22 , L_27 ) ;
V_24 = - V_90 ;
goto V_91;
}
V_56 -> V_20 = F_39 ( V_81 ) ;
if ( ! V_56 -> V_20 ) {
F_15 ( & V_79 -> V_22 , L_28 ) ;
V_24 = - V_90 ;
goto V_92;
}
V_7 -> V_93 = V_56 -> V_20 -> V_70 ;
return 0 ;
V_92:
F_58 ( V_56 -> V_39 ) ;
V_91:
F_59 ( V_7 ) ;
V_87:
if ( V_56 -> V_6 )
F_60 ( & V_56 -> V_6 -> V_22 ) ;
return V_24 ;
}
static int F_61 ( struct V_78 * V_79 )
{
struct V_55 * V_7 = F_62 ( & V_79 -> V_22 ) ;
struct V_23 * V_56 = F_38 ( V_7 ) ;
struct V_5 * V_6 = V_56 -> V_6 ;
if ( V_6 )
F_60 ( & V_6 -> V_22 ) ;
F_58 ( V_56 -> V_39 ) ;
F_59 ( V_7 ) ;
F_4 ( V_56 -> V_20 ) ;
return 0 ;
}
int T_1 F_63 ( void )
{
return F_64 ( & V_94 ) ;
}
void T_2 F_65 ( void )
{
F_66 ( & V_94 ) ;
}
