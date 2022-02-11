static void T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
V_3 = F_2 ( NULL , L_1 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( L_2 ) ;
return;
}
F_5 ( V_3 , 19200000 ) ;
F_6 ( V_3 ) ;
V_1 = F_7 ( V_4 ,
F_8 ( V_4 ) ) ;
if ( V_1 ) {
F_4 ( L_3 ) ;
return;
}
F_9 ( V_5 , 0 ) ;
F_9 ( V_6 , 0 ) ;
F_10 ( V_6 , 1 ) ;
F_11 ( & V_7 ) ;
F_10 ( V_5 , 1 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_11 * V_12 = F_13 ( V_9 ,
struct V_11 , V_9 ) ;
struct V_13 * V_14 = V_9 -> V_15 ;
if ( ! V_14 ) {
F_14 ( V_9 , L_4 , V_16 ) ;
return - V_17 ;
}
if ( V_12 -> V_18 == 0 ) {
V_10 = F_15 () ;
if ( V_10 < 0 ) {
F_14 ( V_9 , L_5 ,
V_16 , V_10 ) ;
return V_10 ;
}
V_14 -> V_19 [ 0 ] . V_20 = V_21 ;
}
return 0 ;
}
static T_1 void F_16 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
if ( ! V_9 ) {
F_4 ( L_6 ) ;
return;
}
V_14 = V_9 -> V_15 ;
V_14 -> V_22 = F_12 ;
}
static int T_1 F_17 ( struct V_23 * V_24 )
{
struct V_23 * V_25 ;
F_18 ( V_24 ) ;
for ( V_25 = V_24 ; V_25 -> V_26 ; V_25 ++ )
F_16 ( & V_25 -> V_12 -> V_9 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
F_20 ( & V_27 , V_28 ,
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 ) ;
F_21 ( L_7 , & V_27 ,
& V_38 , V_39 ) ;
F_22 ( 2 , 400 , NULL , 0 ) ;
F_22 ( 3 , 100 , V_40 ,
F_8 ( V_40 ) ) ;
F_22 ( 4 , 400 , NULL , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 )
{
F_10 ( V_42 -> V_43 , 1 ) ;
return 0 ;
}
static void F_24 ( struct V_41 * V_42 )
{
F_10 ( V_42 -> V_43 , 0 ) ;
}
int T_1 F_25 ( void )
{
int V_44 ;
V_44 = F_26 ( V_45 . V_43 ,
V_46 , L_8 ) ;
if ( V_44 )
F_4 ( L_9 ) ;
return V_44 ;
}
static int F_27 ( struct V_41 * V_42 )
{
int V_47 ;
V_47 = F_7 ( V_48 ,
F_8 ( V_48 ) ) ;
if ( V_47 )
F_4 ( L_10 ) ;
return V_47 ;
}
static void F_28 ( struct V_41 * V_42 )
{
F_29 ( V_48 , F_8 ( V_48 ) ) ;
}
void T_1 F_30 ( void )
{
int V_44 ;
V_44 = F_25 () ;
if ( V_44 )
F_4 ( L_11 ) ;
F_31 ( & V_49 ) ;
if ( F_32 () || F_33 () > V_50 )
F_34 ( V_51 ) ;
else
F_34 ( 0 ) ;
F_35 ( V_52 , V_53 ) ;
F_35 ( V_54 , V_53 ) ;
F_35 ( V_55 , V_56 ) ;
}
static void F_36 ( void )
{
if ( F_37 () ) {
V_57 . V_58 = L_12 ;
V_57 . V_59 = 1 ;
} else {
V_57 . V_58 = L_13 ;
}
}
static void T_1 F_38 ( void )
{
int V_60 = V_61 ;
int V_1 ;
if ( F_33 () == V_62 )
V_60 = V_63 ;
F_39 ( V_64 , NULL , V_60 ) ;
V_65 . V_10 = F_40 ( V_66 ) ;
V_1 = F_41 ( & V_65 ) ;
if ( V_1 )
F_4 ( L_14 , V_1 ) ;
F_36 () ;
F_19 () ;
F_42 ( V_67 , F_8 ( V_67 ) ) ;
F_43 ( & V_68 ) ;
F_44 () ;
F_45 ( NULL , NULL ) ;
F_17 ( V_26 ) ;
F_1 () ;
F_46 ( & V_69 ) ;
F_30 () ;
}
