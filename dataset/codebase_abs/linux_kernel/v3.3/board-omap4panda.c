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
int V_1 = 0 ;
struct V_10 * V_11 = F_13 ( V_9 ,
struct V_10 , V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
if ( ! V_13 ) {
F_14 ( V_9 , L_4 , V_15 ) ;
return - V_16 ;
}
if ( V_11 -> V_17 == 0 ) {
V_1 = F_15 () ;
if ( V_1 )
F_14 ( V_9 , L_5 ,
V_15 , V_1 ) ;
else
V_13 -> V_18 [ 0 ] . V_19 = V_20 ;
}
return V_1 ;
}
static T_1 void F_16 ( struct V_8 * V_9 )
{
struct V_12 * V_13 ;
if ( ! V_9 ) {
F_4 ( L_6 ) ;
return;
}
V_13 = V_9 -> V_14 ;
V_13 -> V_21 = F_12 ;
}
static int T_1 F_17 ( struct V_22 * V_23 )
{
struct V_22 * V_24 ;
F_18 ( V_23 ) ;
for ( V_24 = V_23 ; V_24 -> V_25 ; V_24 ++ )
F_16 ( V_24 -> V_9 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
F_20 ( & V_26 , V_27 ,
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 ) ;
F_21 ( L_7 , & V_26 ) ;
F_22 ( 2 , 400 , NULL , 0 ) ;
F_22 ( 3 , 100 , V_37 ,
F_8 ( V_37 ) ) ;
F_22 ( 4 , 400 , NULL , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 )
{
F_10 ( V_39 -> V_40 , 1 ) ;
return 0 ;
}
static void F_24 ( struct V_38 * V_39 )
{
F_10 ( V_39 -> V_40 , 0 ) ;
}
int T_1 F_25 ( void )
{
int V_41 ;
V_41 = F_26 ( V_42 . V_40 ,
V_43 , L_8 ) ;
if ( V_41 )
F_4 ( L_9 ) ;
return V_41 ;
}
static int F_27 ( struct V_38 * V_39 )
{
int V_44 ;
V_44 = F_7 ( V_45 ,
F_8 ( V_45 ) ) ;
if ( V_44 )
F_4 ( L_10 ) ;
return V_44 ;
}
static void F_28 ( struct V_38 * V_39 )
{
F_29 ( V_45 , F_8 ( V_45 ) ) ;
}
void F_30 ( void )
{
int V_41 ;
V_41 = F_25 () ;
if ( V_41 )
F_4 ( L_11 ) ;
F_31 ( & V_46 ) ;
if ( F_32 () || F_33 () > V_47 )
F_34 ( V_48 ) ;
else
F_34 ( 0 ) ;
F_35 ( V_49 , V_50 ) ;
F_35 ( V_51 , V_50 ) ;
F_35 ( V_52 , V_53 ) ;
}
static void T_1 F_36 ( void )
{
int V_54 = V_55 ;
int V_1 ;
if ( F_33 () == V_56 )
V_54 = V_57 ;
F_37 ( V_58 , NULL , V_54 ) ;
V_1 = F_38 ( & V_59 ) ;
if ( V_1 )
F_4 ( L_12 , V_1 ) ;
F_19 () ;
F_39 ( V_60 , F_8 ( V_60 ) ) ;
F_40 ( & V_61 ) ;
F_41 () ;
F_42 ( NULL , NULL ) ;
F_17 ( V_25 ) ;
F_1 () ;
F_43 ( & V_62 ) ;
F_30 () ;
}
