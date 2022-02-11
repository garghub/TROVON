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
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_1 ( V_2 , V_16 ) ;
F_6 ( V_2 -> V_17 , V_4 -> V_7 -> V_18 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_19 * V_3 ,
struct V_19 * V_20 )
{
}
static struct V_1 * F_9 ( struct V_21 * V_22 ,
struct V_23 * V_7 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
int V_24 ;
V_4 = F_10 ( V_22 -> V_22 , sizeof( * V_4 ) ,
V_25 ) ;
if ( ! V_4 ) {
F_11 ( V_22 -> V_22 , L_1 ) ;
return NULL ;
}
V_4 -> V_7 = V_7 ;
V_2 = & V_4 -> V_26 ;
V_2 -> V_27 = 1 ;
V_24 = F_12 ( V_22 , V_2 , & V_28 ,
V_29 , NULL ) ;
if ( V_24 < 0 )
goto V_30;
F_13 ( V_2 , & V_31 ) ;
return V_2 ;
V_30:
F_14 ( V_2 ) ;
return NULL ;
}
static void F_15 ( struct V_32 * V_33 )
{
F_16 ( V_33 ) ;
F_17 ( V_33 ) ;
}
static enum V_34 F_18 (
struct V_32 * V_33 ,
bool V_35 )
{
return V_36 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_21 * V_22 = V_33 -> V_22 ;
struct V_37 * V_37 = F_20 ( V_33 ) ;
struct V_38 * V_39 = V_37 -> V_7 -> V_39 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_39 -> V_41 ; V_40 ++ ) {
struct V_19 * V_3 = F_21 ( V_22 ) ;
struct V_42 V_43 ;
if ( F_22 ( V_39 , & V_43 , V_40 ) )
break;
F_23 ( & V_43 , V_3 ) ;
V_3 -> type = V_44 ;
if ( V_39 -> V_45 == V_40 )
V_3 -> type |= V_46 ;
F_24 ( V_3 ) ;
F_25 ( V_33 , V_3 ) ;
}
return V_40 ;
}
static int F_26 ( struct V_32 * V_33 ,
struct V_19 * V_3 )
{
struct V_47 * V_48 = V_33 -> V_22 -> V_49 ;
return F_27 ( V_48 -> V_17 , V_3 ) ;
}
static struct V_1 * F_28 (
struct V_32 * V_33 )
{
struct V_37 * V_37 = F_20 ( V_33 ) ;
return V_37 -> V_2 ;
}
static struct V_32 * F_29 ( struct V_21 * V_22 ,
struct V_23 * V_7 , struct V_1 * V_2 )
{
struct V_37 * V_37 ;
struct V_32 * V_33 ;
int V_24 ;
V_37 = F_10 ( V_22 -> V_22 , sizeof( * V_37 ) ,
V_25 ) ;
if ( ! V_37 ) {
F_11 ( V_22 -> V_22 , L_1 ) ;
return NULL ;
}
V_37 -> V_2 = V_2 ;
V_37 -> V_7 = V_7 ;
V_33 = & V_37 -> V_26 ;
F_30 ( V_22 , V_33 , & V_50 ,
V_51 ) ;
F_31 ( V_33 , & V_52 ) ;
V_33 -> V_53 = 0 ;
V_33 -> V_54 = 0 ;
V_24 = F_32 ( V_33 , V_2 ) ;
if ( V_24 )
goto V_30;
F_33 ( V_33 ) ;
return V_33 ;
V_30:
F_15 ( V_33 ) ;
return NULL ;
}
static int F_34 ( struct V_55 * V_7 , struct V_21 * V_22 )
{
struct V_23 * V_56 = F_35 ( V_7 ) ;
struct V_47 * V_48 = V_22 -> V_49 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
V_2 = F_9 ( V_22 , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_33 = F_29 ( V_22 , V_56 , V_2 ) ;
if ( ! V_33 )
return - V_57 ;
V_48 -> V_58 [ V_48 -> V_59 ++ ] = V_2 ;
V_48 -> V_60 [ V_48 -> V_61 ++ ] = V_33 ;
return 0 ;
}
static struct V_62 * F_36 ( struct V_63 * V_64 )
{
struct V_63 * V_65 ;
struct V_62 * V_18 ;
int V_24 = 0 ;
if ( ! V_64 ) {
F_37 ( L_2 , V_66 ) ;
return NULL ;
}
V_65 = F_38 ( V_64 , L_3 ) ;
if ( ! V_65 ) {
F_37 ( L_4 , V_66 ) ;
return NULL ;
}
V_18 = F_39 ( sizeof( * V_18 ) , V_25 ) ;
if ( ! V_18 ) {
F_37 ( L_5 , V_66 ) ;
F_40 ( V_65 ) ;
return NULL ;
}
V_24 |= F_41 ( V_65 , L_6 , & V_18 -> V_67 ) ;
V_24 |= F_41 ( V_65 , L_7 , & V_18 -> V_68 ) ;
V_24 |= F_41 ( V_65 , L_8 , & V_18 -> V_69 ) ;
V_24 |= F_41 ( V_65 , L_9 , & V_18 -> V_70 ) ;
V_24 |= F_41 ( V_65 , L_10 , & V_18 -> V_71 ) ;
V_24 |= F_41 ( V_65 , L_11 , & V_18 -> V_72 ) ;
V_24 |= F_41 ( V_65 , L_12 , & V_18 -> V_73 ) ;
V_24 |= F_41 ( V_65 , L_13 , & V_18 -> V_74 ) ;
V_24 |= F_41 ( V_65 , L_14 , & V_18 -> V_75 ) ;
V_18 -> V_76 = F_42 ( V_65 , L_15 ) ;
V_18 -> V_77 = F_42 ( V_65 , L_16 ) ;
if ( V_24 ) {
F_37 ( L_17 , V_66 ) ;
F_43 ( V_18 ) ;
F_40 ( V_65 ) ;
return NULL ;
}
F_40 ( V_65 ) ;
return V_18 ;
}
static int F_44 ( struct V_78 * V_79 )
{
struct V_63 * V_80 , * V_81 = V_79 -> V_22 . V_82 ;
struct V_23 * V_56 ;
struct V_55 * V_7 ;
struct V_83 * V_83 ;
int V_24 ;
if ( ! V_81 ) {
F_11 ( & V_79 -> V_22 , L_18 ) ;
return - V_84 ;
}
V_56 = F_10 ( & V_79 -> V_22 , sizeof( * V_56 ) , V_25 ) ;
if ( ! V_56 )
return - V_57 ;
V_80 = F_45 ( V_81 , L_19 , 0 ) ;
if ( V_80 ) {
V_56 -> V_6 = F_46 ( V_80 ) ;
F_40 ( V_80 ) ;
if ( ! V_56 -> V_6 )
return - V_85 ;
F_47 ( & V_79 -> V_22 , L_20 ) ;
}
V_56 -> V_10 = F_48 ( & V_79 -> V_22 , L_21 ,
V_86 ) ;
if ( F_49 ( V_56 -> V_10 ) ) {
V_24 = F_50 ( V_56 -> V_10 ) ;
F_11 ( & V_79 -> V_22 , L_22 ) ;
goto V_87;
}
if ( V_56 -> V_10 )
F_47 ( & V_79 -> V_22 , L_23 ) ;
V_7 = & V_56 -> V_26 ;
V_79 -> V_22 . V_88 = V_7 ;
F_51 ( V_7 , L_24 , & V_89 ) ;
V_83 = F_52 ( & V_79 -> V_22 ) ;
if ( F_49 ( V_83 ) )
F_53 ( & V_79 -> V_22 , L_25 ) ;
V_56 -> V_39 = F_54 ( V_81 ) ;
if ( ! V_56 -> V_39 ) {
F_11 ( & V_79 -> V_22 , L_26 ) ;
V_24 = - V_90 ;
goto V_91;
}
V_56 -> V_18 = F_36 ( V_81 ) ;
if ( ! V_56 -> V_18 ) {
F_11 ( & V_79 -> V_22 , L_27 ) ;
V_24 = - V_90 ;
goto V_92;
}
V_7 -> V_93 = V_56 -> V_18 -> V_70 ;
return 0 ;
V_92:
F_55 ( V_56 -> V_39 ) ;
V_91:
F_56 ( V_7 ) ;
V_87:
if ( V_56 -> V_6 )
F_57 ( & V_56 -> V_6 -> V_22 ) ;
return V_24 ;
}
static int F_58 ( struct V_78 * V_79 )
{
struct V_55 * V_7 = F_59 ( & V_79 -> V_22 ) ;
struct V_23 * V_56 = F_35 ( V_7 ) ;
struct V_5 * V_6 = V_56 -> V_6 ;
if ( V_6 )
F_57 ( & V_6 -> V_22 ) ;
F_55 ( V_56 -> V_39 ) ;
F_56 ( V_7 ) ;
F_43 ( V_56 -> V_18 ) ;
return 0 ;
}
int T_1 F_60 ( void )
{
return F_61 ( & V_94 ) ;
}
void T_2 F_62 ( void )
{
F_63 ( & V_94 ) ;
}
