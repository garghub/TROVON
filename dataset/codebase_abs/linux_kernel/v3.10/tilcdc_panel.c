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
if ( ! V_6 )
return;
V_6 -> V_8 . V_9 = V_4 == V_10
? V_11 : V_12 ;
F_6 ( V_6 ) ;
}
static bool F_7 ( struct V_1 * V_2 ,
const struct V_13 * V_4 ,
struct V_13 * V_14 )
{
return true ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_15 ) ;
F_9 ( V_2 -> V_16 , V_3 -> V_7 -> V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_13 * V_4 ,
struct V_13 * V_14 )
{
}
static struct V_1 * F_12 ( struct V_18 * V_19 ,
struct V_20 * V_7 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_21 ;
V_3 = F_13 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 ) {
F_14 ( V_19 -> V_19 , L_1 ) ;
return NULL ;
}
V_3 -> V_7 = V_7 ;
V_2 = & V_3 -> V_23 ;
V_2 -> V_24 = 1 ;
V_21 = F_15 ( V_19 , V_2 , & V_25 ,
V_26 ) ;
if ( V_21 < 0 )
goto V_27;
F_16 ( V_2 , & V_28 ) ;
return V_2 ;
V_27:
F_1 ( V_2 ) ;
return NULL ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_31 * V_31 = F_18 ( V_30 ) ;
F_19 ( V_30 ) ;
F_4 ( V_31 ) ;
}
static enum V_32 F_20 (
struct V_29 * V_30 ,
bool V_33 )
{
return V_34 ;
}
static int F_21 ( struct V_29 * V_30 )
{
struct V_18 * V_19 = V_30 -> V_19 ;
struct V_31 * V_31 = F_18 ( V_30 ) ;
struct V_35 * V_36 = V_31 -> V_7 -> V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_36 -> V_38 ; V_37 ++ ) {
struct V_13 * V_4 = F_22 ( V_19 ) ;
struct V_39 V_40 ;
if ( F_23 ( V_36 , & V_40 , V_37 ) )
break;
F_24 ( & V_40 , V_4 ) ;
V_4 -> type = V_41 ;
if ( V_36 -> V_42 == V_37 )
V_4 -> type |= V_43 ;
F_25 ( V_4 ) ;
F_26 ( V_30 , V_4 ) ;
}
return V_37 ;
}
static int F_27 ( struct V_29 * V_30 ,
struct V_13 * V_4 )
{
struct V_44 * V_45 = V_30 -> V_19 -> V_46 ;
return F_28 ( V_45 -> V_16 , V_4 ) ;
}
static struct V_1 * F_29 (
struct V_29 * V_30 )
{
struct V_31 * V_31 = F_18 ( V_30 ) ;
return V_31 -> V_2 ;
}
static struct V_29 * F_30 ( struct V_18 * V_19 ,
struct V_20 * V_7 , struct V_1 * V_2 )
{
struct V_31 * V_31 ;
struct V_29 * V_30 ;
int V_21 ;
V_31 = F_13 ( sizeof( * V_31 ) , V_22 ) ;
if ( ! V_31 ) {
F_14 ( V_19 -> V_19 , L_1 ) ;
return NULL ;
}
V_31 -> V_2 = V_2 ;
V_31 -> V_7 = V_7 ;
V_30 = & V_31 -> V_23 ;
F_31 ( V_19 , V_30 , & V_47 ,
V_48 ) ;
F_32 ( V_30 , & V_49 ) ;
V_30 -> V_50 = 0 ;
V_30 -> V_51 = 0 ;
V_21 = F_33 ( V_30 , V_2 ) ;
if ( V_21 )
goto V_27;
F_34 ( V_30 ) ;
return V_30 ;
V_27:
F_17 ( V_30 ) ;
return NULL ;
}
static int F_35 ( struct V_52 * V_7 , struct V_18 * V_19 )
{
struct V_20 * V_53 = F_36 ( V_7 ) ;
struct V_44 * V_45 = V_19 -> V_46 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
V_2 = F_12 ( V_19 , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_30 = F_30 ( V_19 , V_53 , V_2 ) ;
if ( ! V_30 )
return - V_54 ;
V_45 -> V_55 [ V_45 -> V_56 ++ ] = V_2 ;
V_45 -> V_57 [ V_45 -> V_58 ++ ] = V_30 ;
return 0 ;
}
static void F_37 ( struct V_52 * V_7 )
{
struct V_20 * V_53 = F_36 ( V_7 ) ;
if ( V_53 -> V_36 ) {
F_38 ( V_53 -> V_36 ) ;
F_4 ( V_53 -> V_36 ) ;
}
F_39 ( V_7 ) ;
F_4 ( V_53 -> V_17 ) ;
F_4 ( V_53 ) ;
}
static struct V_59 * F_40 ( struct V_60 * V_61 )
{
struct V_60 * V_62 ;
struct V_59 * V_17 ;
int V_21 = 0 ;
if ( ! V_61 ) {
F_41 ( L_2 , V_63 ) ;
return NULL ;
}
V_62 = F_42 ( V_61 , L_3 ) ;
if ( ! V_62 ) {
F_41 ( L_4 , V_63 ) ;
return NULL ;
}
V_17 = F_13 ( sizeof( * V_17 ) , V_22 ) ;
if ( ! V_17 ) {
F_41 ( L_5 , V_63 ) ;
return NULL ;
}
V_21 |= F_43 ( V_62 , L_6 , & V_17 -> V_64 ) ;
V_21 |= F_43 ( V_62 , L_7 , & V_17 -> V_65 ) ;
V_21 |= F_43 ( V_62 , L_8 , & V_17 -> V_66 ) ;
V_21 |= F_43 ( V_62 , L_9 , & V_17 -> V_67 ) ;
V_21 |= F_43 ( V_62 , L_10 , & V_17 -> V_68 ) ;
V_21 |= F_43 ( V_62 , L_11 , & V_17 -> V_69 ) ;
V_21 |= F_43 ( V_62 , L_12 , & V_17 -> V_70 ) ;
V_21 |= F_43 ( V_62 , L_13 , & V_17 -> V_71 ) ;
V_21 |= F_43 ( V_62 , L_14 , & V_17 -> V_72 ) ;
V_17 -> V_73 = F_44 ( V_62 , L_15 ) ;
V_17 -> V_74 = F_44 ( V_62 , L_16 ) ;
if ( V_21 ) {
F_41 ( L_17 , V_63 ) ;
F_4 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
static int F_45 ( struct V_75 * V_76 )
{
struct V_60 * V_77 = V_76 -> V_19 . V_78 ;
struct V_20 * V_53 ;
struct V_52 * V_7 ;
struct V_79 * V_79 ;
int V_21 = - V_80 ;
if ( ! V_77 ) {
F_14 ( & V_76 -> V_19 , L_18 ) ;
return - V_81 ;
}
V_53 = F_13 ( sizeof( * V_53 ) , V_22 ) ;
if ( ! V_53 )
return - V_54 ;
V_7 = & V_53 -> V_23 ;
F_46 ( V_7 , L_19 , & V_82 ) ;
V_79 = F_47 ( & V_76 -> V_19 ) ;
if ( F_48 ( V_79 ) )
F_49 ( & V_76 -> V_19 , L_20 ) ;
V_53 -> V_36 = F_50 ( V_77 ) ;
if ( ! V_53 -> V_36 ) {
F_14 ( & V_76 -> V_19 , L_21 ) ;
goto V_27;
}
V_53 -> V_17 = F_40 ( V_77 ) ;
if ( ! V_53 -> V_17 ) {
F_14 ( & V_76 -> V_19 , L_22 ) ;
goto V_27;
}
V_53 -> V_6 = F_51 ( V_77 ) ;
if ( V_53 -> V_6 )
F_52 ( & V_76 -> V_19 , L_23 ) ;
return 0 ;
V_27:
F_37 ( V_7 ) ;
return V_21 ;
}
static int F_53 ( struct V_75 * V_76 )
{
return 0 ;
}
int T_1 F_54 ( void )
{
return F_55 ( & V_83 ) ;
}
void T_2 F_56 ( void )
{
F_57 ( & V_83 ) ;
}
