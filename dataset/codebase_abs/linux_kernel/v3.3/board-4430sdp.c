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
static int F_8 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
struct V_7 * V_8 = F_9 ( V_2 ,
struct V_7 , V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_8 -> V_12 == 0 ) {
V_6 = F_10 () ;
if ( V_6 )
F_7 ( L_2 ) ;
V_10 -> V_13 [ 0 ] . V_14 = V_15 +
V_16 ;
V_10 -> V_13 [ 0 ] . V_17 = V_18 ;
}
return V_6 ;
}
static T_1 void F_11 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! V_2 ) {
F_7 ( L_3 , V_19 ) ;
return;
}
V_10 = V_2 -> V_11 ;
V_10 -> V_20 = F_8 ;
}
static int T_1 F_12 ( struct V_21 * V_22 )
{
struct V_21 * V_23 ;
F_13 ( V_22 ) ;
for ( V_23 = V_22 ; V_23 -> V_24 ; V_23 ++ )
F_11 ( V_23 -> V_2 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
F_15 ( & V_25 , V_26 ,
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ) ;
F_16 ( L_4 , & V_25 ) ;
F_17 ( 2 , 400 , NULL , 0 ) ;
F_17 ( 3 , 400 , V_36 ,
F_6 ( V_36 ) ) ;
F_17 ( 4 , 400 , V_37 ,
F_6 ( V_37 ) ) ;
return 0 ;
}
static void T_1 F_18 ( void )
{
int error ;
error = F_19 ( V_3 ,
V_38 , L_5 ) ;
if ( error < 0 )
F_7 ( L_6 ,
V_19 , V_3 , error ) ;
}
static int F_20 ( struct V_39 * V_40 )
{
int V_4 ;
V_4 = F_5 ( V_41 ,
F_6 ( V_41 ) ) ;
if ( V_4 )
F_7 ( L_7 , V_19 ) ;
return V_4 ;
}
static void F_21 ( struct V_39 * V_40 )
{
F_22 ( V_41 , F_6 ( V_41 ) ) ;
}
static void F_23 ( void )
{
int V_42 ;
V_42 = F_19 ( V_43 . V_44 , V_45 ,
L_8 ) ;
if ( V_42 )
F_7 ( L_9 , V_19 ) ;
V_42 = F_19 ( V_46 . V_44 , V_45 ,
L_10 ) ;
if ( V_42 )
F_7 ( L_11 , V_19 ) ;
}
static void F_24 ( void )
{
int V_42 ;
const struct V_47 V_48 [] = {
{ V_49 , V_38 ,
L_12 } ,
{ V_50 . V_51 , V_52 ,
L_13 } ,
{ V_50 . V_53 , V_38 ,
L_14 } ,
} ;
V_42 = F_5 ( V_48 , F_6 ( V_48 ) ) ;
if ( V_42 )
F_7 ( L_15 , V_42 ) ;
}
static int F_25 ( struct V_39 * V_40 )
{
F_2 ( V_54 , 0 ) ;
F_2 ( V_49 , 1 ) ;
return 0 ;
}
static void F_26 ( struct V_39 * V_40 )
{
F_2 ( V_49 , 0 ) ;
F_2 ( V_54 , 1 ) ;
}
static void T_1 F_27 ( void )
{
int V_42 ;
V_42 = F_19 ( V_54 , V_55 ,
L_16 ) ;
if ( V_42 )
F_7 ( L_17 , V_19 ) ;
F_23 () ;
F_24 () ;
F_28 ( & V_56 ) ;
if ( F_29 () || F_30 () > V_57 )
F_31 ( V_58 ) ;
else
F_31 ( 0 ) ;
F_32 ( V_59 , V_60 ) ;
F_32 ( V_61 , V_60 ) ;
F_32 ( V_62 , V_63 ) ;
}
static void T_1 F_33 ( void )
{
F_32 ( V_64 , V_65 |
V_66 ) ;
F_32 ( V_67 , V_60 ) ;
F_34 ( L_18 ,
V_68 | V_69 ) ;
F_34 ( L_19 ,
V_68 | V_69 ) ;
F_34 ( L_20 ,
V_68 | V_69 ) ;
F_34 ( L_21 ,
V_68 | V_69 ) ;
F_34 ( L_22 ,
V_68 | V_69 ) ;
F_34 ( L_23 ,
V_68 | V_69 ) ;
}
static void T_1 F_35 ( void )
{
int V_6 ;
F_33 () ;
V_6 = F_36 ( & V_70 ) ;
if ( V_6 )
F_7 ( L_24 , V_6 ) ;
V_6 = F_37 ( & V_71 ) ;
if ( V_6 )
F_7 ( L_25 , V_6 ) ;
}
static void T_1 F_38 ( void )
{
int V_4 ;
int V_72 = V_73 ;
if ( F_30 () == V_74 )
V_72 = V_75 ;
F_39 ( V_76 , NULL , V_72 ) ;
F_14 () ;
F_18 () ;
F_40 ( V_77 , F_6 ( V_77 ) ) ;
F_41 () ;
F_42 ( NULL , NULL ) ;
F_35 () ;
F_12 ( V_24 ) ;
F_43 ( & V_78 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_26 , V_4 ) ;
} else {
V_79 [ 0 ] . V_80 = F_44 ( V_81 ) ;
F_45 ( V_79 ,
F_6 ( V_79 ) ) ;
}
V_4 = F_46 ( & V_82 , & V_83 ) ;
if ( V_4 )
F_7 ( L_27 , V_4 ) ;
F_27 () ;
}
