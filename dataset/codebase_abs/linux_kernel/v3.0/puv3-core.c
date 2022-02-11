unsigned long long F_1 ( void )
{
unsigned long long V_1 = F_2 ( F_3 ( V_2 ) ) ;
V_1 = ( ( V_1 & 0x7fffffffffffffffULL ) * 2235 ) >> 5 ;
return V_1 ;
}
static void F_4 ( unsigned long * V_3 )
{
}
static void F_5 ( unsigned long * V_3 )
{
}
static int F_6 ( void )
{
F_7 ( F_8 ( V_4 ) , V_5 ) ;
return 0 ;
}
static void F_9 ( T_1 V_6 )
{
F_7 ( V_7 | V_8
| V_9 | V_10 , V_11 ) ;
switch ( V_6 ) {
case V_12 :
F_6 () ;
F_10 ( V_13 ) ;
break;
}
}
static int F_11 ( T_1 V_6 )
{
return V_6 == V_12 ;
}
static void F_12 ( void )
{
}
static void T_2 F_13 ( void )
{
V_14 = & V_15 ;
}
static inline void F_13 ( void ) {}
void F_14 ( void )
{
struct V_16 * V_17 ;
V_17 = F_15 ( NULL , L_1 ) ;
F_7 ( F_16 ( V_17 ) / 200000 , V_18 ) ;
}
void T_2 F_17 ( void )
{
F_13 () ;
F_14 () ;
F_18 ( L_2 , - 1 ,
V_19 , F_19 ( V_19 ) ) ;
F_18 ( L_3 , - 1 ,
V_20 , F_19 ( V_20 ) ) ;
F_18 ( L_4 , - 1 ,
V_21 , F_19 ( V_21 ) ) ;
F_18 ( L_5 , - 1 ,
V_22 , F_19 ( V_22 ) ) ;
F_18 ( L_6 , - 1 ,
V_23 , F_19 ( V_23 ) ) ;
F_18 ( L_7 , 0 ,
V_24 , F_19 ( V_24 ) ) ;
F_18 ( L_7 , 1 ,
V_25 , F_19 ( V_25 ) ) ;
F_18 ( L_8 , - 1 , NULL , 0 ) ;
F_20 ( & V_26 , L_9 , - 1 ,
V_27 , F_19 ( V_27 ) ,
& V_28 , sizeof( V_28 ) ) ;
}
