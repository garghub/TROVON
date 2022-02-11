static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 1 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
}
static int T_1 F_4 ( void )
{
int V_4 ;
V_4 = F_5 ( V_5 ,
F_6 ( V_5 ) ) ;
if ( V_4 )
F_7 ( L_1 ) ;
return V_4 ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_10 ( NULL , NULL ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
struct V_7 * V_8 = F_12 ( V_2 ,
struct V_7 , V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_8 -> V_12 == 0 ) {
V_6 = F_13 () ;
if ( V_6 )
F_7 ( L_2 ) ;
V_10 -> V_13 [ 0 ] . V_14 = V_15 +
V_16 ;
V_10 -> V_13 [ 0 ] . V_17 = V_18 ;
}
return V_6 ;
}
static T_1 void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! V_2 ) {
F_7 ( L_3 , V_19 ) ;
return;
}
V_10 = V_2 -> V_11 ;
V_10 -> V_20 = F_11 ;
}
static int T_1 F_15 ( struct V_21 * V_22 )
{
struct V_21 * V_23 ;
F_16 ( V_22 ) ;
for ( V_23 = V_22 ; V_23 -> V_24 ; V_23 ++ )
F_14 ( V_23 -> V_2 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
F_18 ( & V_25 , V_26 ,
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ) ;
F_19 ( L_4 , & V_25 ) ;
F_20 ( 2 , 400 , NULL , 0 ) ;
F_20 ( 3 , 400 , V_36 ,
F_6 ( V_36 ) ) ;
F_20 ( 4 , 400 , V_37 ,
F_6 ( V_37 ) ) ;
return 0 ;
}
static void T_1 F_21 ( void )
{
int error ;
error = F_22 ( V_3 ,
V_38 , L_5 ) ;
if ( error < 0 )
F_7 ( L_6 ,
V_19 , V_3 , error ) ;
}
static void F_23 ( void )
{
F_24 ( L_7 ,
V_39 ) ;
F_24 ( L_8 ,
V_39 ) ;
F_24 ( L_9 ,
V_39 ) ;
F_24 ( L_10 ,
V_39 ) ;
}
static int F_25 ( struct V_40 * V_41 )
{
int V_4 ;
V_4 = F_5 ( V_42 ,
F_6 ( V_42 ) ) ;
if ( V_4 )
F_7 ( L_11 , V_19 ) ;
return V_4 ;
}
static void F_26 ( struct V_40 * V_41 )
{
F_27 ( V_43 ) ;
F_27 ( V_44 ) ;
}
void F_28 ( void )
{
F_23 () ;
F_29 ( & V_45 ) ;
}
static inline void F_30 ( void )
{
struct V_46 V_47 ;
V_47 . V_48 = 0 ;
V_47 . V_49 = NULL ;
V_47 . V_50 = 0 ;
V_47 . V_12 = 0 ;
F_31 ( & V_47 ) ;
F_31 ( & V_51 ) ;
F_31 ( & V_52 ) ;
F_31 ( & V_53 ) ;
}
static inline void F_30 ( void )
{
F_32 () ;
}
static void F_33 ( void )
{
F_34 ( V_54 , V_55 |
V_56 ) ;
F_34 ( V_57 , V_58 ) ;
F_24 ( L_12 ,
V_59 | V_39 ) ;
F_24 ( L_13 ,
V_59 | V_39 ) ;
F_24 ( L_14 ,
V_59 | V_39 ) ;
F_24 ( L_15 ,
V_59 | V_39 ) ;
F_24 ( L_16 ,
V_59 | V_39 ) ;
F_24 ( L_17 ,
V_59 | V_39 ) ;
}
static void F_35 ( void )
{
F_33 () ;
if ( F_36 ( & V_60 ) )
F_7 ( L_18 ) ;
F_37 ( & V_61 ) ;
}
static void T_1 F_38 ( void )
{
int V_4 ;
int V_62 = V_63 ;
if ( F_39 () == V_64 )
V_62 = V_65 ;
F_40 ( V_66 , NULL , V_62 ) ;
V_67 = V_68 ;
V_69 = F_6 ( V_68 ) ;
F_17 () ;
F_21 () ;
F_41 ( V_70 , F_6 ( V_70 ) ) ;
F_30 () ;
F_35 () ;
F_15 ( V_24 ) ;
F_42 ( & V_71 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_19 , V_4 ) ;
} else {
V_72 [ 0 ] . V_73 = F_43 ( V_74 ) ;
F_44 ( V_72 ,
F_6 ( V_72 ) ) ;
}
V_4 = F_45 ( & V_75 , & V_76 ) ;
if ( V_4 )
F_7 ( L_20 , V_4 ) ;
F_28 () ;
}
static void T_1 F_46 ( void )
{
F_47 () ;
F_48 () ;
}
