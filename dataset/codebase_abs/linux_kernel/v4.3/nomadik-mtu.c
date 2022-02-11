static T_1 T_2 F_1 ( void )
{
if ( F_2 ( ! V_1 ) )
return 0 ;
return - F_3 ( V_1 + F_4 ( 0 ) ) ;
}
static unsigned long F_5 ( void )
{
return ~ F_6 ( V_1 + F_4 ( 0 ) ) ;
}
static int F_7 ( unsigned long V_2 , struct V_3 * V_4 )
{
F_8 ( 1 << 1 , V_1 + V_5 ) ;
F_8 ( V_2 , V_1 + F_9 ( 1 ) ) ;
F_8 ( V_6 | V_7 |
V_8 | V_9 ,
V_1 + F_10 ( 1 ) ) ;
return 0 ;
}
static void F_11 ( void )
{
if ( V_10 ) {
F_8 ( V_11 , V_1 + F_9 ( 1 ) ) ;
F_8 ( V_11 , V_1 + F_12 ( 1 ) ) ;
F_8 ( V_12 | V_7 |
V_8 | V_9 ,
V_1 + F_10 ( 1 ) ) ;
F_8 ( 1 << 1 , V_1 + V_5 ) ;
} else {
( void ) F_7 ( V_11 , NULL ) ;
}
}
static int F_13 ( struct V_3 * V_2 )
{
F_8 ( 0 , V_1 + V_5 ) ;
F_8 ( 0 , V_1 + F_10 ( 1 ) ) ;
F_8 ( 0xffffffff , V_1 + F_9 ( 1 ) ) ;
return 0 ;
}
static int F_14 ( struct V_3 * V_2 )
{
V_10 = false ;
return 0 ;
}
static int F_15 ( struct V_3 * V_2 )
{
V_10 = true ;
F_11 () ;
return 0 ;
}
static void F_16 ( void )
{
F_8 ( 0 , V_1 + F_10 ( 0 ) ) ;
F_8 ( V_11 , V_1 + F_9 ( 0 ) ) ;
F_8 ( V_11 , V_1 + F_12 ( 0 ) ) ;
F_8 ( V_7 | V_8 | V_9 ,
V_1 + F_10 ( 0 ) ) ;
}
static void F_17 ( struct V_3 * V_13 )
{
F_11 () ;
F_16 () ;
}
static T_3 F_18 ( int V_14 , void * V_15 )
{
struct V_3 * V_16 = V_15 ;
F_8 ( 1 << 1 , V_1 + V_17 ) ;
V_16 -> V_18 ( V_16 ) ;
return V_19 ;
}
static void T_4 F_19 ( void T_5 * V_20 , int V_14 ,
struct V_21 * V_22 , struct V_21 * V_21 )
{
unsigned long V_23 ;
V_1 = V_20 ;
F_20 ( F_21 ( V_22 ) ) ;
F_20 ( F_21 ( V_21 ) ) ;
V_23 = F_22 ( V_21 ) ;
if ( V_23 > 32000000 ) {
V_23 /= 16 ;
V_7 = V_24 ;
} else {
V_7 = V_25 ;
}
V_11 = F_23 ( V_23 , V_26 ) ;
F_16 () ;
if ( F_24 ( V_1 + F_4 ( 0 ) , L_1 ,
V_23 , 200 , 32 , V_27 ) )
F_25 ( L_2 ,
L_1 ) ;
#ifdef F_26
F_27 ( F_1 , 32 , V_23 ) ;
#endif
F_28 ( V_14 , & V_28 ) ;
V_29 . V_30 = F_29 ( 0 ) ;
V_29 . V_14 = V_14 ;
F_30 ( & V_29 , V_23 , 2 , 0xffffffffU ) ;
V_31 . V_32 = & F_5 ;
V_31 . V_33 = V_23 ;
F_31 ( & V_31 ) ;
}
static void T_4 F_32 ( struct V_34 * V_35 )
{
struct V_21 * V_22 ;
struct V_21 * V_21 ;
void T_5 * V_20 ;
int V_14 ;
V_20 = F_33 ( V_35 , 0 ) ;
if ( ! V_20 )
F_34 ( L_3 ) ;
V_22 = F_35 ( V_35 , L_4 ) ;
if ( F_36 ( V_22 ) )
F_34 ( L_5 ) ;
V_21 = F_35 ( V_35 , L_6 ) ;
if ( F_36 ( V_21 ) )
F_34 ( L_7 ) ;
V_14 = F_37 ( V_35 , 0 ) ;
if ( V_14 <= 0 )
F_34 ( L_8 ) ;
F_19 ( V_20 , V_14 , V_22 , V_21 ) ;
}
