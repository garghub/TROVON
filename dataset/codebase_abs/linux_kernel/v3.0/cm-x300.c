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
V_13 = F_19 ( V_14 , L_1 ) ;
if ( V_13 ) {
F_20 ( L_2 ,
V_15 , V_13 ) ;
return V_13 ;
}
F_21 ( V_14 , 0 ) ;
F_22 ( 10 ) ;
F_23 ( V_14 , 1 ) ;
F_22 ( 10 ) ;
F_24 ( V_14 ) ;
return 0 ;
}
static inline int F_25 ( struct V_7 * V_8 )
{
int V_13 = 0 ;
if ( F_26 () ) {
V_16 = F_27 ( NULL , L_3 ) ;
if ( F_28 ( V_16 ) ) {
V_13 = F_29 ( V_16 ) ;
F_20 ( L_4 ,
V_15 , V_13 ) ;
return V_13 ;
}
F_30 ( V_16 ) ;
V_13 = F_18 () ;
if ( V_13 ) {
F_31 ( V_16 ) ;
F_32 ( V_16 ) ;
}
}
return V_13 ;
}
static void F_33 ( struct V_7 * V_8 )
{
if ( F_26 () ) {
F_31 ( V_16 ) ;
F_32 ( V_16 ) ;
}
}
static void F_34 ( void )
{
F_35 ( & V_17 ) ;
}
static inline void F_34 ( void ) {}
static int F_36 ( struct V_7 * V_8 )
{
if ( F_37 () )
V_18 = V_19
| V_20 | V_21 | V_22 ;
return 0 ;
}
static void T_1 F_38 ( void )
{
F_39 ( & V_23 ) ;
}
static inline void F_38 ( void ) {}
static void T_1 F_40 ( void )
{
if ( V_24 < 130 )
V_25 [ 0 ] . V_26 = 79 ;
else
V_25 [ 0 ] . V_26 = 76 ;
F_2 ( & V_27 ) ;
}
static inline void F_40 ( void ) {}
static void T_1 F_41 ( void )
{
F_42 ( NULL ) ;
F_43 ( 0 , V_28 ,
F_8 ( V_28 ) ) ;
}
static inline void F_41 ( void ) {}
static void T_1 F_44 ( void )
{
F_2 ( & V_29 ) ;
}
static inline void F_44 ( void ) {}
static void F_45 ( void )
{
#if F_46 ( V_30 )
F_47 ( V_31 ) ;
#endif
}
static void F_48 ( void )
{
#if F_46 ( V_30 )
F_47 ( V_32 ) ;
#endif
}
static void T_1 F_49 ( void )
{
F_50 ( & V_33 ) ;
F_43 ( 1 , & V_34 , 1 ) ;
F_51 ( V_35 , 1 ) ;
}
static void T_1 F_52 ( void )
{
int V_36 , V_37 ;
int V_13 ;
if ( V_24 < 130 ) {
V_37 = 77 ;
V_36 = 78 ;
} else {
V_37 = 71 ;
V_36 = 70 ;
}
V_13 = F_19 ( V_37 , L_5 ) ;
if ( V_13 ) {
F_20 ( L_6 , V_13 ) ;
} else {
F_21 ( V_37 , 1 ) ;
F_24 ( V_37 ) ;
}
V_13 = F_19 ( V_36 , L_7 ) ;
if ( V_13 ) {
F_20 ( L_8 , V_13 ) ;
} else {
F_21 ( V_36 , 1 ) ;
F_53 ( 10 ) ;
F_23 ( V_36 , 0 ) ;
F_53 ( 10 ) ;
F_23 ( V_36 , 1 ) ;
F_24 ( V_36 ) ;
}
}
static void T_1 F_54 ( void )
{
F_55 ( F_56 ( V_38 ) ) ;
if ( V_24 < 130 )
F_55 ( F_56 ( V_39 ) ) ;
else
F_55 ( F_56 ( V_40 ) ) ;
if ( F_26 () )
F_55 ( F_56 ( V_41 ) ) ;
}
static void T_1 F_57 ( void )
{
F_54 () ;
F_58 ( NULL ) ;
F_59 ( NULL ) ;
if ( F_37 () )
F_60 ( NULL ) ;
F_49 () ;
F_1 () ;
F_3 () ;
F_34 () ;
F_38 () ;
F_15 () ;
F_11 () ;
F_40 () ;
F_41 () ;
F_6 () ;
F_44 () ;
F_9 () ;
F_52 () ;
F_5 () ;
}
static void T_1 F_61 ( struct V_42 * V_43 , struct V_44 * V_45 ,
char * * V_46 , struct V_47 * V_48 )
{
for (; V_45 -> V_49 . V_50 ; V_45 = F_62 ( V_45 ) )
if ( V_45 -> V_49 . V_44 == V_51 &&
V_45 -> V_52 . V_53 . V_54 == 0x80000000 ) {
V_45 -> V_52 . V_53 . V_54 = 0xa0000000 ;
break;
}
}
