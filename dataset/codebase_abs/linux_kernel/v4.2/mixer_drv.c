void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 V_8 = {
. V_9 = V_10 ,
} ;
int V_11 ;
F_2 ( & V_2 -> V_12 ) ;
V_6 = F_3 ( V_2 ) ;
V_11 = F_4 ( V_6 , V_13 , V_14 , NULL , & V_8 ) ;
* V_4 = V_8 . V_15 ;
F_5 ( V_11 , L_1 , V_6 -> V_16 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_12 ) ;
++ V_2 -> V_17 ;
F_8 ( V_2 , L_2 , V_18 , V_2 -> V_17 ) ;
if ( V_2 -> V_17 == 1 ) {
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 V_8 = {
. V_9 = V_10 ,
} ;
struct V_3 * V_4 = & V_8 . V_15 ;
struct V_19 * V_20 = & V_2 -> V_20 ;
int V_11 ;
if ( F_9 ( V_2 ) -> V_21 == 0 )
F_10 ( V_20 -> V_22 , V_20 -> V_23 ) ;
else
F_10 ( V_20 -> V_22 , V_20 -> V_24 ) ;
F_11 ( V_2 , F_9 ( V_2 ) -> V_21 ) ;
V_11 = F_4 ( V_6 , V_13 , V_14 , NULL , & V_8 ) ;
F_5 ( V_11 , L_1 , V_6 -> V_16 ) ;
V_11 = F_4 ( V_6 , V_25 , V_26 , 1 ) ;
F_5 ( V_11 , L_3 , V_6 -> V_16 ) ;
F_12 ( V_2 , V_4 ) ;
F_13 ( V_2 ) ;
V_11 = F_14 ( V_2 ) ;
F_5 ( V_11 , L_4 , V_11 ) ;
}
F_6 ( & V_2 -> V_12 ) ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_12 ) ;
-- V_2 -> V_17 ;
F_8 ( V_2 , L_2 , V_18 , V_2 -> V_17 ) ;
if ( V_2 -> V_17 == 0 ) {
int V_11 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_17 ( V_2 ) ;
V_11 = F_14 ( V_2 ) ;
F_5 ( V_11 , L_4 , V_11 ) ;
V_11 = F_4 ( V_6 , V_25 , V_26 , 0 ) ;
F_5 ( V_11 , L_5 , V_6 -> V_16 ) ;
}
F_5 ( V_2 -> V_17 < 0 , L_6 ,
V_2 -> V_17 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_15 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_12 ) ;
++ V_2 -> V_27 ;
F_8 ( V_2 , L_2 , V_18 , V_2 -> V_27 ) ;
if ( V_2 -> V_27 == 1 )
F_4 ( F_3 ( V_2 ) , V_28 , V_29 , 1 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_12 ) ;
-- V_2 -> V_27 ;
F_8 ( V_2 , L_2 , V_18 , V_2 -> V_27 ) ;
if ( V_2 -> V_27 == 0 )
F_4 ( F_3 ( V_2 ) , V_28 , V_29 , 0 ) ;
F_5 ( V_2 -> V_27 < 0 , L_7 ,
V_2 -> V_27 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_11 = F_21 ( V_2 -> V_30 ) ;
if ( F_22 ( V_11 ) )
return V_11 ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_30 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_33 * V_20 ;
int V_11 ;
V_20 = F_26 ( V_32 , V_34 , L_8 ) ;
if ( V_20 == NULL ) {
F_27 ( V_2 , L_9 ) ;
V_11 = - V_35 ;
goto V_36;
}
V_2 -> V_20 . V_37 = F_28 ( V_20 -> V_38 , F_29 ( V_20 ) ) ;
if ( V_2 -> V_20 . V_37 == NULL ) {
F_27 ( V_2 , L_10 ) ;
V_11 = - V_35 ;
goto V_36;
}
V_20 = F_26 ( V_32 , V_34 , L_11 ) ;
if ( V_20 == NULL ) {
F_27 ( V_2 , L_9 ) ;
V_11 = - V_35 ;
goto V_39;
}
V_2 -> V_20 . V_40 = F_28 ( V_20 -> V_38 , F_29 ( V_20 ) ) ;
if ( V_2 -> V_20 . V_40 == NULL ) {
F_27 ( V_2 , L_10 ) ;
V_11 = - V_35 ;
goto V_39;
}
V_20 = F_26 ( V_32 , V_41 , L_12 ) ;
if ( V_20 == NULL ) {
F_27 ( V_2 , L_13 ) ;
V_11 = - V_35 ;
goto V_42;
}
V_11 = F_30 ( V_20 -> V_38 , V_43 , 0 , L_14 , V_2 ) ;
if ( V_11 ) {
F_27 ( V_2 , L_15 ) ;
goto V_42;
}
V_2 -> V_20 . V_44 = V_20 -> V_38 ;
return 0 ;
V_42:
F_31 ( V_2 -> V_20 . V_40 ) ;
V_39:
F_31 ( V_2 -> V_20 . V_37 ) ;
V_36:
return V_11 ;
}
static void F_32 ( struct V_19 * V_20 )
{
V_20 -> V_45 = F_33 ( - V_46 ) ;
V_20 -> V_47 = F_33 ( - V_46 ) ;
V_20 -> V_22 = F_33 ( - V_46 ) ;
V_20 -> V_24 = F_33 ( - V_46 ) ;
V_20 -> V_23 = F_33 ( - V_46 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_20 . V_44 , V_2 ) ;
F_31 ( V_2 -> V_20 . V_40 ) ;
F_31 ( V_2 -> V_20 . V_37 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
if ( ! F_37 ( V_20 -> V_23 ) )
F_38 ( V_20 -> V_23 ) ;
if ( ! F_37 ( V_20 -> V_24 ) )
F_38 ( V_20 -> V_24 ) ;
if ( ! F_37 ( V_20 -> V_22 ) )
F_38 ( V_20 -> V_22 ) ;
if ( ! F_37 ( V_20 -> V_47 ) )
F_38 ( V_20 -> V_47 ) ;
if ( ! F_37 ( V_20 -> V_45 ) )
F_38 ( V_20 -> V_45 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_20 ;
struct V_48 * V_30 = V_2 -> V_30 ;
F_32 ( V_20 ) ;
V_20 -> V_45 = F_40 ( V_30 , L_16 ) ;
if ( F_37 ( V_20 -> V_45 ) ) {
F_27 ( V_2 , L_17 ) ;
goto V_36;
}
V_20 -> V_47 = F_40 ( V_30 , L_11 ) ;
if ( F_37 ( V_20 -> V_47 ) ) {
F_27 ( V_2 , L_18 ) ;
goto V_36;
}
V_20 -> V_22 = F_40 ( V_30 , L_19 ) ;
if ( F_37 ( V_20 -> V_22 ) ) {
F_27 ( V_2 , L_20 ) ;
goto V_36;
}
V_20 -> V_24 = F_40 ( V_30 , L_21 ) ;
if ( F_37 ( V_20 -> V_24 ) ) {
F_27 ( V_2 , L_22 ) ;
goto V_36;
}
V_20 -> V_23 = F_40 ( V_30 , L_23 ) ;
if ( F_37 ( V_20 -> V_23 ) ) {
F_27 ( V_2 , L_24 ) ;
goto V_36;
}
return 0 ;
V_36:
F_36 ( V_2 ) ;
return - V_49 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_11 ;
V_11 = F_25 ( V_2 , V_32 ) ;
if ( V_11 )
goto V_36;
V_11 = F_39 ( V_2 ) ;
if ( V_11 )
goto V_50;
F_42 ( V_2 , L_25 ) ;
return 0 ;
V_50:
F_34 ( V_2 ) ;
V_36:
F_27 ( V_2 , L_26 ) ;
return V_11 ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
memset ( & V_2 -> V_20 , 0 , sizeof( V_2 -> V_20 ) ) ;
F_32 ( & V_2 -> V_20 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_45 ( V_2 -> V_52 ) ; ++ V_51 )
if ( V_2 -> V_52 [ V_51 ] )
F_46 ( V_2 -> V_52 [ V_51 ] ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
V_2 -> V_52 [ 0 ] = F_48 ( V_2 , 0 ) ;
V_2 -> V_52 [ 1 ] = F_48 ( V_2 , 1 ) ;
V_2 -> V_52 [ 2 ] = F_49 ( V_2 , 0 ) ;
if ( ! V_2 -> V_52 [ 0 ] || ! V_2 -> V_52 [ 1 ] || ! V_2 -> V_52 [ 2 ] ) {
F_27 ( V_2 , L_27 ) ;
goto V_36;
}
return 0 ;
V_36:
F_44 ( V_2 ) ;
return - V_49 ;
}
static int F_50 ( struct V_48 * V_30 )
{
struct V_1 * V_2 = F_51 ( V_30 ) ;
struct V_19 * V_20 = & V_2 -> V_20 ;
int V_11 ;
F_8 ( V_2 , L_28 ) ;
F_2 ( & V_2 -> V_12 ) ;
V_11 = F_52 ( V_20 -> V_45 ) ;
if ( V_11 < 0 ) {
F_53 ( V_2 -> V_30 , L_29 ) ;
goto V_36;
}
V_11 = F_52 ( V_20 -> V_47 ) ;
if ( V_11 < 0 ) {
F_53 ( V_2 -> V_30 , L_30 ) ;
goto V_55;
}
V_11 = F_52 ( V_20 -> V_22 ) ;
if ( V_11 < 0 ) {
F_53 ( V_2 -> V_30 , L_31 ) ;
goto V_56;
}
F_54 ( V_2 ) ;
F_8 ( V_2 , L_32 ) ;
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
V_56:
F_55 ( V_20 -> V_47 ) ;
V_55:
F_55 ( V_20 -> V_45 ) ;
V_36:
F_6 ( & V_2 -> V_12 ) ;
F_53 ( V_2 -> V_30 , L_33 ) ;
return V_11 ;
}
static int F_56 ( struct V_48 * V_30 )
{
struct V_1 * V_2 = F_51 ( V_30 ) ;
struct V_19 * V_20 = & V_2 -> V_20 ;
F_8 ( V_2 , L_34 ) ;
F_2 ( & V_2 -> V_12 ) ;
F_55 ( V_20 -> V_22 ) ;
F_55 ( V_20 -> V_47 ) ;
F_55 ( V_20 -> V_45 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_8 ( V_2 , L_35 ) ;
return 0 ;
}
static int F_57 ( struct V_31 * V_32 )
{
struct V_48 * V_30 = & V_32 -> V_30 ;
struct V_53 * V_54 = V_30 -> V_57 ;
struct V_1 * V_2 ;
int V_11 ;
F_58 ( V_30 , L_36 ) ;
V_2 = F_59 ( sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 ) {
F_53 ( V_30 , L_37 ) ;
V_11 = - V_59 ;
goto V_36;
}
V_2 -> V_30 = V_30 ;
F_60 ( & V_2 -> V_12 ) ;
F_61 ( & V_2 -> V_60 ) ;
F_62 ( & V_2 -> V_61 ) ;
V_11 = F_41 ( V_2 , V_32 ) ;
if ( V_11 )
goto V_62;
V_11 = F_63 ( V_2 , V_63 ,
F_45 ( V_63 ) ) ;
if ( V_11 )
goto V_64;
V_11 = F_47 ( V_2 , V_54 ) ;
if ( V_11 )
goto V_65;
F_64 ( V_30 ) ;
F_42 ( V_2 , L_38 ) ;
return 0 ;
V_65:
F_65 ( V_2 ) ;
V_64:
F_43 ( V_2 ) ;
V_62:
F_66 ( V_2 ) ;
V_36:
F_58 ( V_30 , L_39 ) ;
return V_11 ;
}
static int F_67 ( struct V_31 * V_32 )
{
struct V_48 * V_30 = & V_32 -> V_30 ;
struct V_1 * V_2 = F_51 ( V_30 ) ;
F_68 ( V_30 ) ;
F_44 ( V_2 ) ;
F_65 ( V_2 ) ;
F_43 ( V_2 ) ;
F_66 ( V_2 ) ;
F_58 ( V_30 , L_40 ) ;
return 0 ;
}
static int T_1 F_69 ( void )
{
int V_51 , V_11 ;
static const char V_66 [] V_67 =
L_41
L_42 ;
F_70 ( L_43 , V_66 ) ;
for ( V_51 = 0 ; V_51 < F_45 ( V_63 ) ; ++ V_51 )
F_71 ( V_63 [ V_51 ] . V_68 ) ;
V_11 = F_72 ( & V_69 ) ;
if ( V_11 != 0 ) {
F_73 ( L_44 ) ;
return - V_35 ;
}
return 0 ;
}
static void T_2 F_74 ( void )
{
F_75 ( & V_69 ) ;
}
