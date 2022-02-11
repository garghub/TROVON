static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( L_1 ) ;
if ( ! F_3 ( V_2 ) )
F_4 ( V_2 , V_3 , V_4 ,
V_5 ) ;
else
F_5 ( L_2 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
if ( V_7 && V_7 -> V_8 == V_9 ) {
F_7 ( V_7 , 0x1f , 0x8110 ) ;
F_7 ( V_7 , 0x16 , 0x201 ) ;
} else if ( V_7 && V_7 -> V_8 == V_10 ) {
F_7 ( V_7 , 0x1f , 0x8190 ) ;
F_7 ( V_7 , 0x16 , 0x202 ) ;
}
return 0 ;
}
static void T_1 F_8 ( void )
{
if ( F_9 ( V_11 ) )
F_10 ( V_12 , 0xffffffff ,
F_6 ) ;
}
static inline void F_11 ( void )
{
F_1 () ;
F_8 () ;
}
static void T_1 F_12 ( void )
{
struct V_13 * V_14 ;
V_14 = F_13 () ;
if ( V_14 == NULL )
F_14 ( L_3 ) ;
F_15 ( NULL , V_15 , NULL , NULL ) ;
F_11 () ;
F_16 () ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_19 () ;
F_20 () ;
}
