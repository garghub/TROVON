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
F_2 ( & V_3 ) ;
}
static inline void F_5 ( void ) {}
static void T_1 F_6 ( void )
{
F_7 ( V_4 ,
F_8 ( V_4 ) ) ;
F_2 ( & V_5 ) ;
}
static inline void F_6 ( void ) {}
static void T_1 F_9 ( void )
{
F_10 ( NULL ) ;
}
static inline void F_9 ( void ) {}
static void T_1 F_11 ( void )
{
F_12 ( & V_6 ) ;
}
static inline void F_11 ( void ) {}
static int F_13 ( struct V_7 * V_8 ,
T_2 V_9 ,
void * V_10 )
{
return 0 ;
}
static void F_14 ( struct V_7 * V_8 , void * V_10 )
{
}
static void T_1 F_15 ( void )
{
F_16 ( & V_11 ) ;
F_17 ( & V_12 ) ;
}
static inline void F_15 ( void ) {}
static int F_18 ( void )
{
int V_13 ;
V_13 = F_19 ( V_14 , V_15 ,
L_1 ) ;
if ( V_13 ) {
F_20 ( L_2 , V_13 ) ;
return V_13 ;
}
F_21 ( 10 ) ;
F_22 ( V_14 , 1 ) ;
F_21 ( 10 ) ;
F_23 ( V_14 ) ;
return 0 ;
}
static inline int F_24 ( struct V_7 * V_8 )
{
int V_13 = 0 ;
if ( F_25 () ) {
V_16 = F_26 ( NULL , L_3 ) ;
if ( F_27 ( V_16 ) ) {
V_13 = F_28 ( V_16 ) ;
F_20 ( L_4 , V_13 ) ;
return V_13 ;
}
F_29 ( V_16 ) ;
V_13 = F_18 () ;
if ( V_13 ) {
F_30 ( V_16 ) ;
F_31 ( V_16 ) ;
}
}
return V_13 ;
}
static void F_32 ( struct V_7 * V_8 )
{
if ( F_25 () ) {
F_30 ( V_16 ) ;
F_31 ( V_16 ) ;
}
}
static void F_33 ( void )
{
F_34 ( & V_17 ) ;
}
static inline void F_33 ( void ) {}
static int F_35 ( struct V_7 * V_8 )
{
if ( F_36 () )
V_18 = V_19
| V_20 | V_21 | V_22 ;
return 0 ;
}
static void T_1 F_37 ( void )
{
F_38 ( & V_23 ) ;
}
static inline void F_37 ( void ) {}
static void T_1 F_39 ( void )
{
if ( V_24 < 130 )
V_25 [ 0 ] . V_26 = 79 ;
else
V_25 [ 0 ] . V_26 = 76 ;
F_2 ( & V_27 ) ;
}
static inline void F_39 ( void ) {}
static void T_1 F_40 ( void )
{
F_41 ( NULL ) ;
F_42 ( 0 , V_28 ,
F_8 ( V_28 ) ) ;
}
static inline void F_40 ( void ) {}
static void T_1 F_43 ( void )
{
F_2 ( & V_29 ) ;
}
static inline void F_43 ( void ) {}
static void F_44 ( void )
{
#if F_45 ( V_30 )
F_46 ( V_31 ) ;
#endif
}
static void F_47 ( void )
{
#if F_45 ( V_30 )
F_46 ( V_32 ) ;
#endif
}
static void T_1 F_48 ( void )
{
F_49 ( & V_33 ) ;
F_42 ( 1 , & V_34 , 1 ) ;
F_50 ( V_35 , 1 ) ;
}
static void T_1 F_51 ( void )
{
int V_13 ;
if ( V_24 < 130 ) {
V_36 [ 0 ] . V_26 = 77 ;
V_36 [ 1 ] . V_26 = 78 ;
}
V_13 = F_52 ( F_53 ( V_36 ) ) ;
if ( V_13 ) {
F_20 ( L_5 , V_13 ) ;
return;
}
F_54 ( 10 ) ;
F_22 ( V_36 [ 1 ] . V_26 , 0 ) ;
F_54 ( 10 ) ;
F_22 ( V_36 [ 1 ] . V_26 , 1 ) ;
F_55 ( F_53 ( V_36 ) ) ;
}
static void T_1 F_56 ( void )
{
F_57 ( F_53 ( V_37 ) ) ;
if ( V_24 < 130 )
F_57 ( F_53 ( V_38 ) ) ;
else
F_57 ( F_53 ( V_39 ) ) ;
if ( F_25 () )
F_57 ( F_53 ( V_40 ) ) ;
}
static void T_1 F_58 ( void )
{
F_56 () ;
F_59 ( NULL ) ;
F_60 ( NULL ) ;
if ( F_36 () )
F_61 ( NULL ) ;
F_48 () ;
F_1 () ;
F_3 () ;
F_33 () ;
F_37 () ;
F_15 () ;
F_11 () ;
F_39 () ;
F_40 () ;
F_6 () ;
F_43 () ;
F_9 () ;
F_51 () ;
F_5 () ;
}
static void T_1 F_62 ( struct V_41 * V_42 , char * * V_43 )
{
for (; V_42 -> V_44 . V_45 ; V_42 = F_63 ( V_42 ) )
if ( V_42 -> V_44 . V_41 == V_46 &&
V_42 -> V_47 . V_48 . V_49 == 0x80000000 ) {
V_42 -> V_47 . V_48 . V_49 = 0xa0000000 ;
break;
}
}
