static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
void F_3 ( struct V_7 * V_8 )
{
F_4 ( V_8 ) ;
F_5 ( V_8 ) ;
}
void F_6 ( struct V_9 * V_10 )
{
F_7 ( V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 -> V_6 ) ;
}
static int F_10 ( struct V_1 * V_11 ,
struct V_12 * V_13 )
{
int V_14 ;
V_14 = F_11 ( V_11 , V_13 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( V_11 , V_13 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_11 ( V_11 , V_13 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_13 ( V_11 , V_13 ) ;
if ( V_14 )
return V_14 ;
return V_14 ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_11 = V_13 -> V_11 ;
struct V_15 * V_16 ;
struct V_17 * V_18 , * V_19 ;
bool V_20 = false ;
int V_21 ;
F_15 ( V_11 , V_13 ) ;
F_16 ( V_11 , V_13 ,
V_22 |
V_23 ) ;
F_17 ( V_11 , V_13 ) ;
F_18 (state, plane, old_plane_state, new_plane_state, i) {
if ( F_19 ( V_18 , V_19 ) )
V_20 = true ;
}
if ( V_20 ) {
F_20 ( V_11 , V_13 ) ;
F_21 (state, plane, old_plane_state, i)
F_22 ( V_16 ) ;
}
F_23 ( V_13 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_24 * V_25 )
{
T_1 V_26 = F_25 ( V_2 , V_25 ) ;
if ( V_26 == 0 )
return - V_27 ;
V_10 -> V_28 = V_26 ;
V_10 -> V_29 = ~ 0 ;
return 0 ;
}
static int F_26 ( struct V_30 * V_11 , void * V_31 )
{
struct V_24 * V_25 = V_31 ;
if ( strcmp ( V_11 -> V_32 -> V_33 , L_1 ) == 0 ) {
struct V_34 * V_35 = V_11 -> V_36 ;
return V_35 -> V_37 == V_25 ;
}
if ( F_27 ( V_25 -> V_33 , L_2 ) == 0 ) {
V_25 = F_28 ( V_25 ) ;
F_29 ( V_25 ) ;
}
return V_11 -> V_37 == V_25 ;
}
static int F_30 ( struct V_30 * V_11 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_14 ;
V_2 = F_31 ( & V_38 , V_11 ) ;
if ( F_32 ( V_2 ) )
return F_33 ( V_2 ) ;
V_4 = F_34 ( V_11 , sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 ) {
V_14 = - V_40 ;
goto V_41;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_42 = true ;
V_2 -> V_43 . V_44 = 1 ;
V_2 -> V_43 . V_45 = 1 ;
V_2 -> V_43 . V_46 = 4096 ;
V_2 -> V_43 . V_47 = 4096 ;
V_2 -> V_43 . V_48 = & V_49 ;
V_2 -> V_43 . V_50 = & V_51 ;
F_35 ( V_2 ) ;
V_14 = F_36 ( V_2 , V_52 ) ;
if ( V_14 )
goto V_53;
F_37 ( V_11 , V_2 ) ;
V_14 = F_38 ( V_11 , V_2 ) ;
if ( V_14 )
goto V_53;
F_39 ( V_2 ) ;
#if F_40 ( V_54 )
if ( V_55 != 16 && V_55 != 32 ) {
F_41 ( V_11 , L_3 ) ;
V_55 = 16 ;
}
V_4 -> V_6 = F_42 ( V_2 , V_55 , V_52 ) ;
if ( F_32 ( V_4 -> V_6 ) ) {
V_14 = F_33 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
goto V_56;
}
#endif
F_43 ( V_2 ) ;
V_14 = F_44 ( V_2 , 0 ) ;
if ( V_14 )
goto V_57;
return 0 ;
V_57:
F_45 ( V_2 ) ;
#if F_40 ( V_54 )
if ( V_4 -> V_6 )
F_46 ( V_4 -> V_6 ) ;
V_56:
#endif
F_47 ( V_2 -> V_11 , V_2 ) ;
V_53:
F_48 ( V_2 ) ;
V_41:
F_49 ( V_2 ) ;
return V_14 ;
}
static void F_50 ( struct V_30 * V_11 )
{
struct V_1 * V_2 = F_51 ( V_11 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_52 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( V_4 -> V_6 )
F_46 ( V_4 -> V_6 ) ;
F_48 ( V_2 ) ;
F_47 ( V_2 -> V_11 , V_2 ) ;
F_37 ( V_11 , NULL ) ;
F_49 ( V_2 ) ;
}
static int F_53 ( struct V_58 * V_59 )
{
int V_14 = F_54 ( & V_59 -> V_11 , F_26 , & V_60 ) ;
if ( ! V_14 )
V_14 = F_55 ( & V_59 -> V_11 , F_56 ( 32 ) ) ;
return V_14 ;
}
static int F_57 ( struct V_58 * V_59 )
{
F_58 ( & V_59 -> V_11 , & V_60 ) ;
return 0 ;
}
static int F_59 ( struct V_30 * V_11 )
{
struct V_1 * V_61 = F_51 ( V_11 ) ;
struct V_3 * V_4 ;
if ( V_61 == NULL )
return 0 ;
F_60 ( V_61 ) ;
V_4 = V_61 -> V_5 ;
V_4 -> V_13 = F_61 ( V_61 ) ;
if ( F_32 ( V_4 -> V_13 ) ) {
F_62 ( V_61 ) ;
return F_33 ( V_4 -> V_13 ) ;
}
return 0 ;
}
static int F_63 ( struct V_30 * V_11 )
{
struct V_1 * V_61 = F_51 ( V_11 ) ;
struct V_3 * V_62 ;
if ( V_61 == NULL )
return 0 ;
V_62 = V_61 -> V_5 ;
F_64 ( V_61 , V_62 -> V_13 ) ;
F_62 ( V_61 ) ;
return 0 ;
}
static int T_2 F_65 ( void )
{
return F_66 ( V_63 , F_67 ( V_63 ) ) ;
}
static void T_3 F_68 ( void )
{
F_69 ( V_63 , F_67 ( V_63 ) ) ;
}
