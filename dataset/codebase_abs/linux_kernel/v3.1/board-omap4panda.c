static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( NULL , NULL ) ;
}
static void T_1 F_4 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
V_3 = F_5 ( NULL , L_1 ) ;
if ( F_6 ( V_3 ) ) {
F_7 ( L_2 ) ;
return;
}
F_8 ( V_3 , 19200000 ) ;
F_9 ( V_3 ) ;
V_1 = F_10 ( V_4 ,
F_11 ( V_4 ) ) ;
if ( V_1 ) {
F_7 ( L_3 ) ;
return;
}
F_12 ( V_5 , 0 ) ;
F_12 ( V_6 , 0 ) ;
F_13 ( V_6 , 1 ) ;
F_14 ( & V_7 ) ;
F_13 ( V_5 , 1 ) ;
}
static int F_15 ( struct V_8 * V_9 )
{
int V_1 = 0 ;
struct V_10 * V_11 = F_16 ( V_9 ,
struct V_10 , V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
if ( ! V_13 ) {
F_17 ( V_9 , L_4 , V_15 ) ;
return - V_16 ;
}
if ( V_11 -> V_17 == 0 ) {
V_1 = F_18 () ;
if ( V_1 )
F_17 ( V_9 , L_5 ,
V_15 , V_1 ) ;
else
V_13 -> V_18 [ 0 ] . V_19 = V_20 ;
}
return V_1 ;
}
static T_1 void F_19 ( struct V_8 * V_9 )
{
struct V_12 * V_13 ;
if ( ! V_9 ) {
F_7 ( L_6 ) ;
return;
}
V_13 = V_9 -> V_14 ;
V_13 -> V_21 = F_15 ;
}
static int T_1 F_20 ( struct V_22 * V_23 )
{
struct V_22 * V_24 ;
F_21 ( V_23 ) ;
for ( V_24 = V_23 ; V_24 -> V_25 ; V_24 ++ )
F_19 ( V_24 -> V_9 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
F_23 ( & V_26 , V_27 ,
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 ) ;
F_24 ( L_7 , & V_26 ) ;
F_25 ( 2 , 400 , NULL , 0 ) ;
F_25 ( 3 , 100 , V_37 ,
F_11 ( V_37 ) ) ;
F_25 ( 4 , 400 , NULL , 0 ) ;
return 0 ;
}
static inline void F_26 ( void )
{
struct V_38 V_39 ;
V_39 . V_40 = 0 ;
V_39 . V_41 = NULL ;
V_39 . V_42 = 0 ;
V_39 . V_17 = 0 ;
F_27 ( & V_39 ) ;
F_27 ( & V_43 ) ;
F_27 ( & V_44 ) ;
F_27 ( & V_45 ) ;
}
static inline void F_26 ( void )
{
F_28 () ;
}
static int F_29 ( struct V_46 * V_47 )
{
F_13 ( V_47 -> V_48 , 1 ) ;
return 0 ;
}
static void F_30 ( struct V_46 * V_47 )
{
F_13 ( V_47 -> V_48 , 0 ) ;
}
int T_1 F_31 ( void )
{
int V_49 ;
V_49 = F_32 ( V_50 . V_48 ,
V_51 , L_8 ) ;
if ( V_49 )
F_7 ( L_9 ) ;
return V_49 ;
}
static void F_33 ( void )
{
F_34 ( L_10 ,
V_52 ) ;
F_34 ( L_11 ,
V_52 ) ;
F_34 ( L_12 ,
V_52 ) ;
F_34 ( L_13 ,
V_52 ) ;
}
static int F_35 ( struct V_46 * V_47 )
{
int V_53 ;
V_53 = F_10 ( V_54 ,
F_11 ( V_54 ) ) ;
if ( V_53 )
F_7 ( L_14 ) ;
return V_53 ;
}
static void F_36 ( struct V_46 * V_47 )
{
F_37 ( V_55 ) ;
F_37 ( V_56 ) ;
}
void F_38 ( void )
{
int V_49 ;
V_49 = F_31 () ;
if ( V_49 )
F_7 ( L_15 ) ;
F_33 () ;
F_39 ( & V_57 ) ;
}
static void T_1 F_40 ( void )
{
int V_58 = V_59 ;
if ( F_41 () == V_60 )
V_58 = V_61 ;
F_42 ( V_62 , NULL , V_58 ) ;
if ( F_43 ( & V_63 ) )
F_7 ( L_16 ) ;
F_22 () ;
F_44 ( V_64 , F_11 ( V_64 ) ) ;
F_45 ( & V_65 ) ;
F_26 () ;
F_20 ( V_25 ) ;
F_4 () ;
F_46 ( & V_66 ) ;
F_38 () ;
}
static void T_1 F_47 ( void )
{
F_48 () ;
F_49 () ;
}
