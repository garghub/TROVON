void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_6 = F_3 ( V_2 ) ;
V_7 = F_4 ( V_6 , V_9 , V_10 , V_4 ) ;
F_5 ( V_7 , L_1 , V_6 -> V_11 ) ;
F_6 ( & V_2 -> V_8 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_8 ) ;
++ V_2 -> V_12 ;
F_8 ( V_2 , L_2 , V_13 , V_2 -> V_12 ) ;
if ( V_2 -> V_12 == 1 ) {
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_3 V_4 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
int V_7 ;
if ( F_9 ( V_2 ) -> V_16 == 0 )
F_10 ( V_15 -> V_17 , V_15 -> V_18 ) ;
else
F_10 ( V_15 -> V_17 , V_15 -> V_19 ) ;
F_11 ( V_2 , F_9 ( V_2 ) -> V_16 ) ;
V_7 = F_4 ( V_6 , V_9 , V_10 , & V_4 ) ;
F_5 ( V_7 , L_1 , V_6 -> V_11 ) ;
V_7 = F_4 ( V_6 , V_9 , V_20 , 1 ) ;
F_5 ( V_7 , L_3 , V_6 -> V_11 ) ;
F_12 ( V_2 , & V_4 ) ;
F_13 ( V_2 ) ;
V_7 = F_14 ( V_2 ) ;
F_5 ( V_7 , L_4 , V_7 ) ;
}
F_6 ( & V_2 -> V_8 ) ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_8 ) ;
-- V_2 -> V_12 ;
F_8 ( V_2 , L_2 , V_13 , V_2 -> V_12 ) ;
if ( V_2 -> V_12 == 0 ) {
int V_7 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_17 ( V_2 ) ;
V_7 = F_14 ( V_2 ) ;
F_5 ( V_7 , L_4 , V_7 ) ;
V_7 = F_4 ( V_6 , V_9 , V_20 , 0 ) ;
F_5 ( V_7 , L_5 , V_6 -> V_11 ) ;
}
F_5 ( V_2 -> V_12 < 0 , L_6 ,
V_2 -> V_12 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_15 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_8 ) ;
++ V_2 -> V_21 ;
F_8 ( V_2 , L_2 , V_13 , V_2 -> V_21 ) ;
if ( V_2 -> V_21 == 1 )
F_4 ( F_3 ( V_2 ) , V_22 , V_23 , 1 ) ;
F_6 ( & V_2 -> V_8 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_8 ) ;
-- V_2 -> V_21 ;
F_8 ( V_2 , L_2 , V_13 , V_2 -> V_21 ) ;
if ( V_2 -> V_21 == 0 )
F_4 ( F_3 ( V_2 ) , V_22 , V_23 , 0 ) ;
F_5 ( V_2 -> V_21 < 0 , L_7 ,
V_2 -> V_21 ) ;
F_6 ( & V_2 -> V_8 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_7 = F_21 ( V_2 -> V_24 ) ;
if ( F_22 ( V_7 ) )
return V_7 ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_24 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_27 * V_15 ;
int V_7 ;
V_15 = F_26 ( V_26 , V_28 , L_8 ) ;
if ( V_15 == NULL ) {
F_27 ( V_2 , L_9 ) ;
V_7 = - V_29 ;
goto V_30;
}
V_2 -> V_15 . V_31 = F_28 ( V_15 -> V_32 , F_29 ( V_15 ) ) ;
if ( V_2 -> V_15 . V_31 == NULL ) {
F_27 ( V_2 , L_10 ) ;
V_7 = - V_29 ;
goto V_30;
}
V_15 = F_26 ( V_26 , V_28 , L_11 ) ;
if ( V_15 == NULL ) {
F_27 ( V_2 , L_9 ) ;
V_7 = - V_29 ;
goto V_33;
}
V_2 -> V_15 . V_34 = F_28 ( V_15 -> V_32 , F_29 ( V_15 ) ) ;
if ( V_2 -> V_15 . V_34 == NULL ) {
F_27 ( V_2 , L_10 ) ;
V_7 = - V_29 ;
goto V_33;
}
V_15 = F_26 ( V_26 , V_35 , L_12 ) ;
if ( V_15 == NULL ) {
F_27 ( V_2 , L_13 ) ;
V_7 = - V_29 ;
goto V_36;
}
V_7 = F_30 ( V_15 -> V_32 , V_37 , 0 , L_14 , V_2 ) ;
if ( V_7 ) {
F_27 ( V_2 , L_15 ) ;
goto V_36;
}
V_2 -> V_15 . V_38 = V_15 -> V_32 ;
return 0 ;
V_36:
F_31 ( V_2 -> V_15 . V_34 ) ;
V_33:
F_31 ( V_2 -> V_15 . V_31 ) ;
V_30:
return V_7 ;
}
static void F_32 ( struct V_14 * V_15 )
{
V_15 -> V_39 = F_33 ( - V_40 ) ;
V_15 -> V_41 = F_33 ( - V_40 ) ;
V_15 -> V_17 = F_33 ( - V_40 ) ;
V_15 -> V_19 = F_33 ( - V_40 ) ;
V_15 -> V_18 = F_33 ( - V_40 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_15 . V_38 , V_2 ) ;
F_31 ( V_2 -> V_15 . V_34 ) ;
F_31 ( V_2 -> V_15 . V_31 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
if ( ! F_37 ( V_15 -> V_18 ) )
F_38 ( V_15 -> V_18 ) ;
if ( ! F_37 ( V_15 -> V_19 ) )
F_38 ( V_15 -> V_19 ) ;
if ( ! F_37 ( V_15 -> V_17 ) )
F_38 ( V_15 -> V_17 ) ;
if ( ! F_37 ( V_15 -> V_41 ) )
F_38 ( V_15 -> V_41 ) ;
if ( ! F_37 ( V_15 -> V_39 ) )
F_38 ( V_15 -> V_39 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_42 * V_24 = V_2 -> V_24 ;
F_32 ( V_15 ) ;
V_15 -> V_39 = F_40 ( V_24 , L_16 ) ;
if ( F_37 ( V_15 -> V_39 ) ) {
F_27 ( V_2 , L_17 ) ;
goto V_30;
}
V_15 -> V_41 = F_40 ( V_24 , L_11 ) ;
if ( F_37 ( V_15 -> V_41 ) ) {
F_27 ( V_2 , L_18 ) ;
goto V_30;
}
V_15 -> V_17 = F_40 ( V_24 , L_19 ) ;
if ( F_37 ( V_15 -> V_17 ) ) {
F_27 ( V_2 , L_20 ) ;
goto V_30;
}
V_15 -> V_19 = F_40 ( V_24 , L_21 ) ;
if ( F_37 ( V_15 -> V_19 ) ) {
F_27 ( V_2 , L_22 ) ;
goto V_30;
}
V_15 -> V_18 = F_40 ( V_24 , L_23 ) ;
if ( F_37 ( V_15 -> V_18 ) ) {
F_27 ( V_2 , L_24 ) ;
goto V_30;
}
return 0 ;
V_30:
F_36 ( V_2 ) ;
return - V_43 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
int V_7 ;
V_7 = F_25 ( V_2 , V_26 ) ;
if ( V_7 )
goto V_30;
V_7 = F_39 ( V_2 ) ;
if ( V_7 )
goto V_44;
F_42 ( V_2 , L_25 ) ;
return 0 ;
V_44:
F_34 ( V_2 ) ;
V_30:
F_27 ( V_2 , L_26 ) ;
return V_7 ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
memset ( & V_2 -> V_15 , 0 , sizeof( V_2 -> V_15 ) ) ;
F_32 ( & V_2 -> V_15 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < F_45 ( V_2 -> V_46 ) ; ++ V_45 )
if ( V_2 -> V_46 [ V_45 ] )
F_46 ( V_2 -> V_46 [ V_45 ] ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
V_2 -> V_46 [ 0 ] = F_48 ( V_2 , 0 ) ;
V_2 -> V_46 [ 1 ] = F_48 ( V_2 , 1 ) ;
V_2 -> V_46 [ 2 ] = F_49 ( V_2 , 0 ) ;
if ( ! V_2 -> V_46 [ 0 ] || ! V_2 -> V_46 [ 1 ] || ! V_2 -> V_46 [ 2 ] ) {
F_27 ( V_2 , L_27 ) ;
goto V_30;
}
return 0 ;
V_30:
F_44 ( V_2 ) ;
return - V_43 ;
}
static int F_50 ( struct V_42 * V_24 )
{
struct V_1 * V_2 = F_51 ( V_24 ) ;
struct V_14 * V_15 = & V_2 -> V_15 ;
F_8 ( V_2 , L_28 ) ;
F_2 ( & V_2 -> V_8 ) ;
F_52 ( V_15 -> V_39 ) ;
F_52 ( V_15 -> V_41 ) ;
F_52 ( V_15 -> V_17 ) ;
F_53 ( V_2 ) ;
F_8 ( V_2 , L_29 ) ;
F_6 ( & V_2 -> V_8 ) ;
return 0 ;
}
static int F_54 ( struct V_42 * V_24 )
{
struct V_1 * V_2 = F_51 ( V_24 ) ;
struct V_14 * V_15 = & V_2 -> V_15 ;
F_8 ( V_2 , L_30 ) ;
F_2 ( & V_2 -> V_8 ) ;
F_55 ( V_15 -> V_17 ) ;
F_55 ( V_15 -> V_41 ) ;
F_55 ( V_15 -> V_39 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_8 ( V_2 , L_31 ) ;
return 0 ;
}
static int F_56 ( struct V_25 * V_26 )
{
struct V_42 * V_24 = & V_26 -> V_24 ;
struct V_47 * V_48 = V_24 -> V_49 ;
struct V_1 * V_2 ;
int V_7 ;
F_57 ( V_24 , L_32 ) ;
V_2 = F_58 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 ) {
F_59 ( V_24 , L_33 ) ;
V_7 = - V_51 ;
goto V_30;
}
V_2 -> V_24 = V_24 ;
F_60 ( & V_2 -> V_8 ) ;
F_61 ( & V_2 -> V_52 ) ;
F_62 ( & V_2 -> V_53 ) ;
V_7 = F_41 ( V_2 , V_26 ) ;
if ( V_7 )
goto V_54;
V_7 = F_63 ( V_2 , V_55 ,
F_45 ( V_55 ) ) ;
if ( V_7 )
goto V_56;
V_7 = F_47 ( V_2 , V_48 ) ;
if ( V_7 )
goto V_57;
F_64 ( V_24 ) ;
F_42 ( V_2 , L_34 ) ;
return 0 ;
V_57:
F_65 ( V_2 ) ;
V_56:
F_43 ( V_2 ) ;
V_54:
F_66 ( V_2 ) ;
V_30:
F_57 ( V_24 , L_35 ) ;
return V_7 ;
}
static int F_67 ( struct V_25 * V_26 )
{
struct V_42 * V_24 = & V_26 -> V_24 ;
struct V_1 * V_2 = F_51 ( V_24 ) ;
F_68 ( V_24 ) ;
F_44 ( V_2 ) ;
F_65 ( V_2 ) ;
F_43 ( V_2 ) ;
F_66 ( V_2 ) ;
F_57 ( V_24 , L_36 ) ;
return 0 ;
}
static int T_1 F_69 ( void )
{
int V_45 , V_7 ;
static const char V_58 [] V_59 =
L_37
L_38 ;
F_70 ( L_39 , V_58 ) ;
for ( V_45 = 0 ; V_45 < F_45 ( V_55 ) ; ++ V_45 )
F_71 ( V_55 [ V_45 ] . V_60 ) ;
V_7 = F_72 ( & V_61 ) ;
if ( V_7 != 0 ) {
F_73 ( L_40 ) ;
return - V_29 ;
}
return 0 ;
}
static void T_2 F_74 ( void )
{
F_75 ( & V_61 ) ;
}
