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
static int F_17 ( struct V_30 * V_31 )
{
struct V_19 * V_20 = V_31 -> V_20 ;
struct V_32 * V_32 = F_18 ( V_31 ) ;
struct V_33 * V_34 = V_32 -> V_7 -> V_34 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_34 -> V_36 ; V_35 ++ ) {
struct V_17 * V_3 = F_19 ( V_20 ) ;
struct V_37 V_38 ;
if ( F_20 ( V_34 , & V_38 , V_35 ) )
break;
F_21 ( & V_38 , V_3 ) ;
V_3 -> type = V_39 ;
if ( V_34 -> V_40 == V_35 )
V_3 -> type |= V_41 ;
F_22 ( V_3 ) ;
F_23 ( V_31 , V_3 ) ;
}
return V_35 ;
}
static int F_24 ( struct V_30 * V_31 ,
struct V_17 * V_3 )
{
struct V_42 * V_43 = V_31 -> V_20 -> V_44 ;
return F_25 ( V_43 -> V_45 , V_3 ) ;
}
static struct V_1 * F_26 (
struct V_30 * V_31 )
{
struct V_32 * V_32 = F_18 ( V_31 ) ;
return V_32 -> V_2 ;
}
static struct V_30 * F_27 ( struct V_19 * V_20 ,
struct V_21 * V_7 , struct V_1 * V_2 )
{
struct V_32 * V_32 ;
struct V_30 * V_31 ;
int V_22 ;
V_32 = F_9 ( V_20 -> V_20 , sizeof( * V_32 ) ,
V_23 ) ;
if ( ! V_32 ) {
F_10 ( V_20 -> V_20 , L_1 ) ;
return NULL ;
}
V_32 -> V_2 = V_2 ;
V_32 -> V_7 = V_7 ;
V_31 = & V_32 -> V_24 ;
F_28 ( V_20 , V_31 , & V_46 ,
V_47 ) ;
F_29 ( V_31 , & V_48 ) ;
V_31 -> V_49 = 0 ;
V_31 -> V_50 = 0 ;
V_22 = F_30 ( V_31 , V_2 ) ;
if ( V_22 )
goto V_28;
return V_31 ;
V_28:
F_14 ( V_31 ) ;
return NULL ;
}
static int F_31 ( struct V_51 * V_7 , struct V_19 * V_20 )
{
struct V_21 * V_52 = F_32 ( V_7 ) ;
struct V_42 * V_43 = V_20 -> V_44 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
V_2 = F_8 ( V_20 , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_31 = F_27 ( V_20 , V_52 , V_2 ) ;
if ( ! V_31 )
return - V_53 ;
V_43 -> V_54 [ V_43 -> V_55 ++ ] = V_2 ;
V_43 -> V_56 [ V_43 -> V_57 ++ ] = V_31 ;
F_33 ( V_43 -> V_45 ,
F_2 ( V_2 ) -> V_7 -> V_58 ) ;
return 0 ;
}
static struct V_59 * F_34 ( struct V_60 * V_61 )
{
struct V_60 * V_62 ;
struct V_59 * V_58 ;
int V_22 = 0 ;
if ( ! V_61 ) {
F_35 ( L_2 , V_63 ) ;
return NULL ;
}
V_62 = F_36 ( V_61 , L_3 ) ;
if ( ! V_62 ) {
F_35 ( L_4 , V_63 ) ;
return NULL ;
}
V_58 = F_37 ( sizeof( * V_58 ) , V_23 ) ;
if ( ! V_58 ) {
F_35 ( L_5 , V_63 ) ;
F_38 ( V_62 ) ;
return NULL ;
}
V_22 |= F_39 ( V_62 , L_6 , & V_58 -> V_64 ) ;
V_22 |= F_39 ( V_62 , L_7 , & V_58 -> V_65 ) ;
V_22 |= F_39 ( V_62 , L_8 , & V_58 -> V_66 ) ;
V_22 |= F_39 ( V_62 , L_9 , & V_58 -> V_67 ) ;
V_22 |= F_39 ( V_62 , L_10 , & V_58 -> V_68 ) ;
V_22 |= F_39 ( V_62 , L_11 , & V_58 -> V_69 ) ;
V_22 |= F_39 ( V_62 , L_12 , & V_58 -> V_70 ) ;
V_22 |= F_39 ( V_62 , L_13 , & V_58 -> V_71 ) ;
V_22 |= F_39 ( V_62 , L_14 , & V_58 -> V_72 ) ;
V_58 -> V_73 = F_40 ( V_62 , L_15 ) ;
V_58 -> V_74 = F_40 ( V_62 , L_16 ) ;
if ( V_22 ) {
F_35 ( L_17 , V_63 ) ;
F_41 ( V_58 ) ;
F_38 ( V_62 ) ;
return NULL ;
}
F_38 ( V_62 ) ;
return V_58 ;
}
static int F_42 ( struct V_75 * V_76 )
{
struct V_60 * V_77 , * V_78 = V_76 -> V_20 . V_79 ;
struct V_21 * V_52 ;
struct V_51 * V_7 ;
struct V_80 * V_80 ;
int V_22 ;
if ( ! V_78 ) {
F_10 ( & V_76 -> V_20 , L_18 ) ;
return - V_81 ;
}
V_52 = F_9 ( & V_76 -> V_20 , sizeof( * V_52 ) , V_23 ) ;
if ( ! V_52 )
return - V_53 ;
V_77 = F_43 ( V_78 , L_19 , 0 ) ;
if ( V_77 ) {
V_52 -> V_6 = F_44 ( V_77 ) ;
F_38 ( V_77 ) ;
if ( ! V_52 -> V_6 )
return - V_82 ;
F_45 ( & V_76 -> V_20 , L_20 ) ;
}
V_52 -> V_10 = F_46 ( & V_76 -> V_20 , L_21 ,
V_83 ) ;
if ( F_47 ( V_52 -> V_10 ) ) {
V_22 = F_48 ( V_52 -> V_10 ) ;
F_10 ( & V_76 -> V_20 , L_22 ) ;
goto V_84;
}
if ( V_52 -> V_10 )
F_45 ( & V_76 -> V_20 , L_23 ) ;
V_7 = & V_52 -> V_24 ;
V_76 -> V_20 . V_85 = V_7 ;
F_49 ( V_7 , L_24 , & V_86 ) ;
V_80 = F_50 ( & V_76 -> V_20 ) ;
if ( F_47 ( V_80 ) )
F_51 ( & V_76 -> V_20 , L_25 ) ;
V_52 -> V_34 = F_52 ( V_78 ) ;
if ( ! V_52 -> V_34 ) {
F_10 ( & V_76 -> V_20 , L_26 ) ;
V_22 = - V_87 ;
goto V_88;
}
V_52 -> V_58 = F_34 ( V_78 ) ;
if ( ! V_52 -> V_58 ) {
F_10 ( & V_76 -> V_20 , L_27 ) ;
V_22 = - V_87 ;
goto V_89;
}
return 0 ;
V_89:
F_53 ( V_52 -> V_34 ) ;
V_88:
F_54 ( V_7 ) ;
V_84:
if ( V_52 -> V_6 )
F_55 ( & V_52 -> V_6 -> V_20 ) ;
return V_22 ;
}
static int F_56 ( struct V_75 * V_76 )
{
struct V_51 * V_7 = F_57 ( & V_76 -> V_20 ) ;
struct V_21 * V_52 = F_32 ( V_7 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
if ( V_6 )
F_55 ( & V_6 -> V_20 ) ;
F_53 ( V_52 -> V_34 ) ;
F_54 ( V_7 ) ;
F_41 ( V_52 -> V_58 ) ;
return 0 ;
}
int T_1 F_58 ( void )
{
return F_59 ( & V_90 ) ;
}
void T_2 F_60 ( void )
{
F_61 ( & V_90 ) ;
}
