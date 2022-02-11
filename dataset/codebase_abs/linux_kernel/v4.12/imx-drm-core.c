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
struct V_17 * V_18 ;
bool V_19 = false ;
int V_20 ;
F_15 ( V_11 , V_13 ) ;
F_16 ( V_11 , V_13 ,
V_21 |
V_22 ) ;
F_17 ( V_11 , V_13 ) ;
F_18 (state, plane, old_plane_state, i) {
if ( F_19 ( V_18 , V_16 -> V_13 ) )
V_19 = true ;
}
if ( V_19 ) {
F_20 ( V_11 , V_13 ) ;
F_18 (state, plane, old_plane_state, i)
F_21 ( V_16 ) ;
}
F_22 ( V_13 ) ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_23 * V_24 )
{
T_1 V_25 = F_24 ( V_2 , V_24 ) ;
if ( V_25 == 0 )
return - V_26 ;
V_10 -> V_27 = V_25 ;
V_10 -> V_28 = ~ 0 ;
return 0 ;
}
static int F_25 ( struct V_29 * V_11 , void * V_30 )
{
struct V_23 * V_24 = V_30 ;
if ( strcmp ( V_11 -> V_31 -> V_32 , L_1 ) == 0 ) {
struct V_33 * V_34 = V_11 -> V_35 ;
return V_34 -> V_36 == V_24 ;
}
if ( F_26 ( V_24 -> V_32 , L_2 ) == 0 ) {
V_24 = F_27 ( V_24 ) ;
F_28 ( V_24 ) ;
}
return V_11 -> V_36 == V_24 ;
}
static int F_29 ( struct V_29 * V_11 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_14 ;
V_2 = F_30 ( & V_37 , V_11 ) ;
if ( F_31 ( V_2 ) )
return F_32 ( V_2 ) ;
V_4 = F_33 ( V_11 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
V_14 = - V_39 ;
goto V_40;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_41 = true ;
V_2 -> V_42 . V_43 = 1 ;
V_2 -> V_42 . V_44 = 1 ;
V_2 -> V_42 . V_45 = 4096 ;
V_2 -> V_42 . V_46 = 4096 ;
V_2 -> V_42 . V_47 = & V_48 ;
V_2 -> V_42 . V_49 = & V_50 ;
F_34 ( V_2 ) ;
V_14 = F_35 ( V_2 , V_51 ) ;
if ( V_14 )
goto V_52;
F_36 ( V_11 , V_2 ) ;
V_14 = F_37 ( V_11 , V_2 ) ;
if ( V_14 )
goto V_53;
F_38 ( V_2 ) ;
#if F_39 ( V_54 )
if ( V_55 != 16 && V_55 != 32 ) {
F_40 ( V_11 , L_3 ) ;
V_55 = 16 ;
}
V_4 -> V_6 = F_41 ( V_2 , V_55 , V_51 ) ;
if ( F_31 ( V_4 -> V_6 ) ) {
V_14 = F_32 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
goto V_56;
}
#endif
F_42 ( V_2 ) ;
V_14 = F_43 ( V_2 , 0 ) ;
if ( V_14 )
goto V_57;
return 0 ;
V_57:
F_44 ( V_2 ) ;
#if F_39 ( V_54 )
if ( V_4 -> V_6 )
F_45 ( V_4 -> V_6 ) ;
V_56:
#endif
F_46 ( V_2 -> V_11 , V_2 ) ;
V_53:
F_47 ( V_2 ) ;
V_52:
F_48 ( V_2 ) ;
V_40:
F_49 ( V_2 ) ;
return V_14 ;
}
static void F_50 ( struct V_29 * V_11 )
{
struct V_1 * V_2 = F_51 ( V_11 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_52 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_4 -> V_6 )
F_45 ( V_4 -> V_6 ) ;
F_48 ( V_2 ) ;
F_46 ( V_2 -> V_11 , V_2 ) ;
F_36 ( V_11 , NULL ) ;
F_49 ( V_2 ) ;
}
static int F_53 ( struct V_58 * V_59 )
{
int V_14 = F_54 ( & V_59 -> V_11 , F_25 , & V_60 ) ;
if ( ! V_14 )
V_14 = F_55 ( & V_59 -> V_11 , F_56 ( 32 ) ) ;
return V_14 ;
}
static int F_57 ( struct V_58 * V_59 )
{
F_58 ( & V_59 -> V_11 , & V_60 ) ;
return 0 ;
}
static int F_59 ( struct V_29 * V_11 )
{
struct V_1 * V_61 = F_51 ( V_11 ) ;
struct V_3 * V_4 ;
if ( V_61 == NULL )
return 0 ;
F_60 ( V_61 ) ;
V_4 = V_61 -> V_5 ;
V_4 -> V_13 = F_61 ( V_61 ) ;
if ( F_31 ( V_4 -> V_13 ) ) {
F_62 ( V_61 ) ;
return F_32 ( V_4 -> V_13 ) ;
}
return 0 ;
}
static int F_63 ( struct V_29 * V_11 )
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
