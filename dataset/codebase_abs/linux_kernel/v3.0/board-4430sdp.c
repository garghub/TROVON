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
#ifdef F_11
F_12 ( 1 ) ;
#endif
}
static int F_13 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
struct V_7 * V_8 = F_14 ( V_2 ,
struct V_7 , V_2 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_8 -> V_12 == 0 ) {
V_6 = F_15 () ;
if ( V_6 )
F_7 ( L_2 ) ;
V_10 -> V_13 [ 0 ] . V_14 = V_15 +
V_16 ;
V_10 -> V_13 [ 0 ] . V_17 = V_18 ;
}
return V_6 ;
}
static T_1 void F_16 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! V_2 ) {
F_7 ( L_3 , V_19 ) ;
return;
}
V_10 = V_2 -> V_11 ;
V_10 -> V_20 = F_13 ;
}
static int T_1 F_17 ( struct V_21 * V_22 )
{
struct V_21 * V_23 ;
F_18 ( V_22 ) ;
for ( V_23 = V_22 ; V_23 -> V_24 ; V_23 ++ )
F_16 ( V_23 -> V_2 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
F_20 ( L_4 , & V_25 ) ;
F_21 ( 2 , 400 , NULL , 0 ) ;
F_21 ( 3 , 400 , V_26 ,
F_6 ( V_26 ) ) ;
F_21 ( 4 , 400 , V_27 ,
F_6 ( V_27 ) ) ;
return 0 ;
}
static void T_1 F_22 ( void )
{
int error ;
error = F_23 ( V_3 ,
V_28 , L_5 ) ;
if ( error < 0 )
F_7 ( L_6 ,
V_19 , V_3 , error ) ;
}
static void F_24 ( void )
{
F_25 ( L_7 ,
V_29 ) ;
F_25 ( L_8 ,
V_29 ) ;
F_25 ( L_9 ,
V_29 ) ;
F_25 ( L_10 ,
V_29 ) ;
}
static int F_26 ( struct V_30 * V_31 )
{
int V_4 ;
V_4 = F_5 ( V_32 ,
F_6 ( V_32 ) ) ;
if ( V_4 )
F_7 ( L_11 , V_19 ) ;
return V_4 ;
}
static void F_27 ( struct V_30 * V_31 )
{
F_28 ( V_33 ) ;
F_28 ( V_34 ) ;
}
void F_29 ( void )
{
F_24 () ;
F_30 ( & V_35 ) ;
}
static inline void F_31 ( void )
{
struct V_36 V_37 ;
V_37 . V_38 = 0 ;
V_37 . V_39 = NULL ;
V_37 . V_40 = 0 ;
V_37 . V_12 = 0 ;
F_32 ( & V_37 ) ;
F_32 ( & V_41 ) ;
F_32 ( & V_42 ) ;
F_32 ( & V_43 ) ;
}
static inline void F_31 ( void )
{
F_33 () ;
}
static void T_1 F_34 ( void )
{
int V_4 ;
int V_44 = V_45 ;
if ( F_35 () == V_46 )
V_44 = V_47 ;
F_36 ( V_48 , NULL , V_44 ) ;
V_49 = V_50 ;
V_51 = F_6 ( V_50 ) ;
F_19 () ;
F_22 () ;
F_37 ( V_52 , F_6 ( V_52 ) ) ;
F_31 () ;
F_17 ( V_24 ) ;
F_38 ( & V_53 ) ;
V_4 = F_4 () ;
if ( V_4 ) {
F_7 ( L_12 , V_4 ) ;
} else {
V_54 [ 0 ] . V_55 = F_39 ( V_56 ) ;
F_40 ( V_54 ,
F_6 ( V_54 ) ) ;
}
V_4 = F_41 ( & V_57 ) ;
if ( V_4 )
F_7 ( L_13 , V_4 ) ;
F_29 () ;
}
static void T_1 F_42 ( void )
{
F_43 () ;
F_44 () ;
}
