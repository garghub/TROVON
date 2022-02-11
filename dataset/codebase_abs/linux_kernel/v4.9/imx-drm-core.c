static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_8 = V_4 -> V_9 [ V_7 ] ;
int V_10 ;
if ( ! V_8 )
return - V_11 ;
if ( ! V_8 -> V_12 . V_13 )
return - V_14 ;
V_10 = V_8 -> V_12 . V_13 (
V_8 -> V_9 ) ;
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_8 = V_4 -> V_9 [ V_7 ] ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_12 . V_15 )
return;
V_8 -> V_12 . V_15 ( V_8 -> V_9 ) ;
}
void F_5 ( struct V_16 * V_17 )
{
F_6 ( V_17 ) ;
F_7 ( V_17 ) ;
}
void F_8 ( struct V_18 * V_19 )
{
F_9 ( V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_11 ( V_4 -> V_6 ) ;
}
static int F_12 ( struct V_1 * V_20 ,
struct V_21 * V_22 )
{
int V_10 ;
V_10 = F_13 ( V_20 , V_22 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_14 ( V_20 , V_22 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_13 ( V_20 , V_22 ) ;
if ( V_10 )
return V_10 ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_20 ,
struct V_21 * V_22 ,
bool V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
int V_29 ;
F_16 (state, plane, plane_state, i) {
if ( ( V_27 -> V_22 -> V_30 != V_25 -> V_30 ) && V_25 -> V_30 ) {
V_28 = F_17 ( V_25 -> V_30 ,
0 ) -> V_31 . V_28 ;
if ( ! V_28 )
continue;
V_25 -> V_32 =
F_18 ( V_28 -> V_33 ) ;
}
}
return F_19 ( V_20 , V_22 , V_23 ) ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_1 * V_20 = V_22 -> V_20 ;
F_21 ( V_20 , V_22 ) ;
F_22 ( V_20 , V_22 ,
V_34 |
V_35 ) ;
F_23 ( V_20 , V_22 ) ;
F_24 ( V_22 ) ;
F_25 ( V_20 , V_22 ) ;
F_26 ( V_20 , V_22 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_36 * V_9 ,
struct V_8 * * V_37 , struct V_26 * V_38 ,
const struct V_39 * V_12 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_8 ;
if ( V_4 -> V_42 >= V_43 )
return - V_11 ;
if ( V_4 -> V_2 -> V_44 )
return - V_45 ;
V_8 = F_28 ( sizeof( * V_8 ) , V_46 ) ;
if ( ! V_8 )
return - V_47 ;
V_8 -> V_12 = * V_12 ;
V_8 -> V_9 = V_9 ;
V_9 -> V_41 = V_41 ;
V_4 -> V_9 [ V_4 -> V_42 ++ ] = V_8 ;
* V_37 = V_8 ;
F_29 ( V_9 ,
V_8 -> V_12 . V_48 ) ;
F_30 ( V_2 , V_9 , V_38 , NULL ,
V_8 -> V_12 . V_49 , NULL ) ;
return 0 ;
}
int F_31 ( struct V_8 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_9 -> V_20 -> V_5 ;
unsigned int V_7 = F_32 ( V_8 -> V_9 ) ;
F_33 ( V_8 -> V_9 ) ;
V_4 -> V_9 [ V_7 ] = NULL ;
F_34 ( V_8 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_40 * V_50 )
{
T_1 V_51 = F_36 ( V_2 , V_50 ) ;
if ( V_51 == 0 )
return - V_52 ;
V_19 -> V_53 = V_51 ;
V_19 -> V_54 = ~ 0 ;
return 0 ;
}
static int F_37 ( struct V_55 * V_20 , void * V_56 )
{
struct V_40 * V_50 = V_56 ;
if ( strcmp ( V_20 -> V_57 -> V_58 , L_1 ) == 0 ) {
struct V_59 * V_60 = V_20 -> V_61 ;
return V_60 -> V_62 == V_50 ;
}
if ( F_38 ( V_50 -> V_58 , L_2 ) == 0 ) {
V_50 = F_39 ( V_50 ) ;
F_40 ( V_50 ) ;
}
return V_20 -> V_62 == V_50 ;
}
static int F_41 ( struct V_55 * V_20 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_10 ;
V_2 = F_42 ( & V_63 , V_20 ) ;
if ( F_43 ( V_2 ) )
return F_44 ( V_2 ) ;
V_4 = F_45 ( V_20 , sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 ) {
V_10 = - V_47 ;
goto V_64;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_65 = true ;
V_2 -> V_66 . V_67 = 64 ;
V_2 -> V_66 . V_68 = 64 ;
V_2 -> V_66 . V_69 = 4096 ;
V_2 -> V_66 . V_70 = 4096 ;
V_2 -> V_66 . V_71 = & V_72 ;
V_2 -> V_66 . V_73 = & V_74 ;
F_46 ( V_2 ) ;
V_10 = F_47 ( V_2 , V_43 ) ;
if ( V_10 )
goto V_75;
F_48 ( V_20 , V_2 ) ;
V_10 = F_49 ( V_20 , V_2 ) ;
if ( V_10 )
goto V_76;
F_50 ( V_2 ) ;
#if F_51 ( V_77 )
if ( V_78 != 16 && V_78 != 32 ) {
F_52 ( V_20 , L_3 ) ;
V_78 = 16 ;
}
V_4 -> V_6 = F_53 ( V_2 , V_78 ,
V_2 -> V_66 . V_79 , V_43 ) ;
if ( F_43 ( V_4 -> V_6 ) ) {
V_10 = F_44 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
goto V_80;
}
#endif
F_54 ( V_2 ) ;
V_10 = F_55 ( V_2 , 0 ) ;
if ( V_10 )
goto V_81;
return 0 ;
V_81:
F_56 ( V_2 ) ;
#if F_51 ( V_77 )
if ( V_4 -> V_6 )
F_57 ( V_4 -> V_6 ) ;
V_80:
#endif
F_58 ( V_2 -> V_20 , V_2 ) ;
V_76:
F_59 ( V_2 ) ;
V_75:
F_60 ( V_2 ) ;
V_64:
F_61 ( V_2 ) ;
return V_10 ;
}
static void F_62 ( struct V_55 * V_20 )
{
struct V_1 * V_2 = F_63 ( V_20 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_64 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_4 -> V_6 )
F_57 ( V_4 -> V_6 ) ;
F_60 ( V_2 ) ;
F_58 ( V_2 -> V_20 , V_2 ) ;
F_48 ( V_20 , NULL ) ;
F_61 ( V_2 ) ;
}
static int F_65 ( struct V_82 * V_83 )
{
int V_10 = F_66 ( & V_83 -> V_20 , F_37 , & V_84 ) ;
if ( ! V_10 )
V_10 = F_67 ( & V_83 -> V_20 , F_68 ( 32 ) ) ;
return V_10 ;
}
static int F_69 ( struct V_82 * V_83 )
{
F_70 ( & V_83 -> V_20 , & V_84 ) ;
return 0 ;
}
static int F_71 ( struct V_55 * V_20 )
{
struct V_1 * V_85 = F_63 ( V_20 ) ;
struct V_3 * V_4 ;
if ( V_85 == NULL )
return 0 ;
F_72 ( V_85 ) ;
V_4 = V_85 -> V_5 ;
V_4 -> V_22 = F_73 ( V_85 ) ;
if ( F_43 ( V_4 -> V_22 ) ) {
F_74 ( V_85 ) ;
return F_44 ( V_4 -> V_22 ) ;
}
return 0 ;
}
static int F_75 ( struct V_55 * V_20 )
{
struct V_1 * V_85 = F_63 ( V_20 ) ;
struct V_3 * V_86 ;
if ( V_85 == NULL )
return 0 ;
V_86 = V_85 -> V_5 ;
F_76 ( V_85 , V_86 -> V_22 ) ;
F_74 ( V_85 ) ;
return 0 ;
}
