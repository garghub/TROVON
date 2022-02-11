static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline void F_1 ( void ) {}
static void T_1 F_3 ( void )
{
F_4 ( NULL , & V_2 ) ;
}
static inline void F_3 ( void ) {}
static void F_5 ( void )
{
F_6 ( V_3 , F_7 ( V_3 ) ) ;
F_2 ( & V_4 ) ;
}
static inline void F_5 ( void ) {}
static void T_1 F_8 ( void )
{
F_9 ( V_5 ,
F_7 ( V_5 ) ) ;
F_2 ( & V_6 ) ;
}
static inline void F_8 ( void ) {}
static void T_1 F_10 ( void )
{
F_11 ( NULL ) ;
}
static inline void F_10 ( void ) {}
static void T_1 F_12 ( void )
{
F_13 ( & V_7 ) ;
}
static inline void F_12 ( void ) {}
static int F_14 ( struct V_8 * V_9 ,
T_2 V_10 ,
void * V_11 )
{
return 0 ;
}
static void F_15 ( struct V_8 * V_9 , void * V_11 )
{
}
static void T_1 F_16 ( void )
{
F_17 ( & V_12 ) ;
F_18 ( & V_13 ) ;
}
static inline void F_16 ( void ) {}
static int F_19 ( void )
{
int V_14 ;
V_14 = F_20 ( V_15 , V_16 ,
L_1 ) ;
if ( V_14 ) {
F_21 ( L_2 , V_14 ) ;
return V_14 ;
}
F_22 ( 10 ) ;
F_23 ( V_15 , 1 ) ;
F_22 ( 10 ) ;
F_24 ( V_15 ) ;
return 0 ;
}
static inline int F_25 ( struct V_8 * V_9 )
{
int V_14 = 0 ;
if ( F_26 () ) {
V_17 = F_27 ( NULL , L_3 ) ;
if ( F_28 ( V_17 ) ) {
V_14 = F_29 ( V_17 ) ;
F_21 ( L_4 , V_14 ) ;
return V_14 ;
}
F_30 ( V_17 ) ;
V_14 = F_19 () ;
if ( V_14 ) {
F_31 ( V_17 ) ;
F_32 ( V_17 ) ;
}
}
return V_14 ;
}
static void F_33 ( struct V_8 * V_9 )
{
if ( F_26 () ) {
F_31 ( V_17 ) ;
F_32 ( V_17 ) ;
}
}
static void F_34 ( void )
{
F_35 ( & V_18 ) ;
}
static inline void F_34 ( void ) {}
static int F_36 ( struct V_8 * V_9 )
{
if ( F_37 () )
V_19 = V_20
| V_21 | V_22 | V_23 ;
return 0 ;
}
static void T_1 F_38 ( void )
{
F_39 ( & V_24 ) ;
}
static inline void F_38 ( void ) {}
static void T_1 F_40 ( void )
{
if ( V_25 < 130 )
V_26 [ 0 ] . V_27 = 79 ;
else
V_26 [ 0 ] . V_27 = 76 ;
F_2 ( & V_28 ) ;
}
static inline void F_40 ( void ) {}
static void T_1 F_41 ( void )
{
F_42 ( NULL ) ;
F_43 ( 0 , V_29 ,
F_7 ( V_29 ) ) ;
}
static inline void F_41 ( void ) {}
static void T_1 F_44 ( void )
{
F_2 ( & V_30 ) ;
}
static inline void F_44 ( void ) {}
static void F_45 ( void )
{
#if F_46 ( V_31 )
F_47 ( V_32 ) ;
#endif
}
static void F_48 ( void )
{
#if F_46 ( V_31 )
F_47 ( V_33 ) ;
#endif
}
static void T_1 F_49 ( void )
{
F_50 ( & V_34 ) ;
F_43 ( 1 , & V_35 , 1 ) ;
F_51 ( V_36 , 1 ) ;
}
static void T_1 F_52 ( void )
{
int V_14 ;
if ( V_25 < 130 ) {
V_37 [ 0 ] . V_27 = 77 ;
V_37 [ 1 ] . V_27 = 78 ;
}
V_14 = F_53 ( F_54 ( V_37 ) ) ;
if ( V_14 ) {
F_21 ( L_5 , V_14 ) ;
return;
}
F_55 ( 10 ) ;
F_23 ( V_37 [ 1 ] . V_27 , 0 ) ;
F_55 ( 10 ) ;
F_23 ( V_37 [ 1 ] . V_27 , 1 ) ;
F_56 ( F_54 ( V_37 ) ) ;
}
static void T_1 F_57 ( void )
{
F_58 ( F_54 ( V_38 ) ) ;
if ( V_25 < 130 )
F_58 ( F_54 ( V_39 ) ) ;
else
F_58 ( F_54 ( V_40 ) ) ;
if ( F_26 () )
F_58 ( F_54 ( V_41 ) ) ;
}
static void T_1 F_59 ( void )
{
F_57 () ;
F_60 ( NULL ) ;
F_61 ( NULL ) ;
if ( F_37 () )
F_62 ( NULL ) ;
F_49 () ;
F_1 () ;
F_3 () ;
F_34 () ;
F_38 () ;
F_16 () ;
F_12 () ;
F_40 () ;
F_41 () ;
F_8 () ;
F_44 () ;
F_10 () ;
F_52 () ;
F_5 () ;
F_63 () ;
}
static void T_1 F_64 ( struct V_42 * V_43 , char * * V_44 )
{
for (; V_43 -> V_45 . V_46 ; V_43 = F_65 ( V_43 ) )
if ( V_43 -> V_45 . V_42 == V_47 &&
V_43 -> V_48 . V_49 . V_50 == 0x80000000 ) {
V_43 -> V_48 . V_49 . V_50 = 0xa0000000 ;
break;
}
}
