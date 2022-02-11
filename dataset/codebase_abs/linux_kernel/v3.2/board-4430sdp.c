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
static void F_20 ( void )
{
F_21 ( L_7 ,
V_39 ) ;
F_21 ( L_8 ,
V_39 ) ;
F_21 ( L_9 ,
V_39 ) ;
F_21 ( L_10 ,
V_39 ) ;
}
static int F_22 ( struct V_40 * V_41 )
{
int V_4 ;
V_4 = F_5 ( V_42 ,
F_6 ( V_42 ) ) ;
if ( V_4 )
F_7 ( L_11 , V_19 ) ;
return V_4 ;
}
static void F_23 ( struct V_40 * V_41 )
{
F_24 ( V_43 ) ;
F_24 ( V_44 ) ;
}
static void F_25 ( void )
{
int V_45 ;
V_45 = F_19 ( V_46 . V_47 , V_48 ,
L_12 ) ;
if ( V_45 )
F_7 ( L_13 , V_19 ) ;
V_45 = F_19 ( V_49 . V_47 , V_48 ,
L_14 ) ;
if ( V_45 )
F_7 ( L_15 , V_19 ) ;
}
static void F_26 ( void )
{
int V_45 ;
const struct V_50 V_51 [] = {
{ V_52 , V_38 ,
L_16 } ,
{ V_53 . V_54 , V_55 ,
L_17 } ,
{ V_53 . V_56 , V_38 ,
L_18 } ,
} ;
V_45 = F_5 ( V_51 , F_6 ( V_51 ) ) ;
if ( V_45 )
F_7 ( L_19 , V_45 ) ;
}
static int F_27 ( struct V_40 * V_41 )
{
F_2 ( V_57 , 0 ) ;
F_2 ( V_52 , 1 ) ;
return 0 ;
}
static void F_28 ( struct V_40 * V_41 )
{
F_2 ( V_52 , 0 ) ;
F_2 ( V_57 , 1 ) ;
}
static void F_29 ( void )
{
int V_45 ;
V_45 = F_19 ( V_57 , V_58 ,
L_20 ) ;
if ( V_45 )
F_7 ( L_21 , V_19 ) ;
F_25 () ;
F_20 () ;
F_26 () ;
F_30 ( & V_59 ) ;
}
static inline void F_31 ( void )
{
struct V_60 V_61 ;
V_61 . V_62 = 0 ;
V_61 . V_63 = NULL ;
V_61 . V_64 = 0 ;
V_61 . V_12 = 0 ;
F_32 ( & V_61 ) ;
F_32 ( & V_65 ) ;
F_32 ( & V_66 ) ;
F_32 ( & V_67 ) ;
}
static inline void F_31 ( void )
{
F_33 () ;
}
static void F_34 ( void )
{
F_35 ( V_68 , V_69 |
V_70 ) ;
F_35 ( V_71 , V_72 ) ;
F_21 ( L_22 ,
V_73 | V_39 ) ;
F_21 ( L_23 ,
V_73 | V_39 ) ;
F_21 ( L_24 ,
V_73 | V_39 ) ;
F_21 ( L_25 ,
V_73 | V_39 ) ;
F_21 ( L_26 ,
V_73 | V_39 ) ;
F_21 ( L_27 ,
V_73 | V_39 ) ;
}
static void F_36 ( void )
{
F_34 () ;
if ( F_37 ( & V_74 ) )
F_7 ( L_28 ) ;
F_38 ( & V_75 ) ;
}
static void T_1 F_39 ( void )
{
int V_4 ;
int V_76 = V_77 ;
if ( F_40 () == V_78 )
V_76 = V_79 ;
F_41 ( V_80 , NULL , V_76 ) ;
F_14 () ;
F_18 () ;
F_42 ( V_81 , F_6 ( V_81 ) ) ;
F_31 () ;
F_43 ( NULL , NULL ) ;
F_36 () ;
F_12 ( V_24 ) ;
F_44 ( & V_82 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_29 , V_4 ) ;
} else {
V_83 [ 0 ] . V_84 = F_45 ( V_85 ) ;
F_46 ( V_83 ,
F_6 ( V_83 ) ) ;
}
V_4 = F_47 ( & V_86 , & V_87 ) ;
if ( V_4 )
F_7 ( L_30 , V_4 ) ;
F_29 () ;
}
