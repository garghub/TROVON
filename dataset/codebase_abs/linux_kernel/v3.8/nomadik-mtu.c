static T_1 T_2 F_1 ( void )
{
if ( F_2 ( ! V_1 ) )
return 0 ;
return - F_3 ( V_1 + F_4 ( 0 ) ) ;
}
static int F_5 ( unsigned long V_2 , struct V_3 * V_4 )
{
F_6 ( 1 << 1 , V_1 + V_5 ) ;
F_6 ( V_2 , V_1 + F_7 ( 1 ) ) ;
F_6 ( V_6 | V_7 |
V_8 | V_9 ,
V_1 + F_8 ( 1 ) ) ;
return 0 ;
}
void F_9 ( void )
{
if ( V_10 ) {
F_6 ( V_11 , V_1 + F_7 ( 1 ) ) ;
F_6 ( V_11 , V_1 + F_10 ( 1 ) ) ;
F_6 ( V_12 | V_7 |
V_8 | V_9 ,
V_1 + F_8 ( 1 ) ) ;
F_6 ( 1 << 1 , V_1 + V_5 ) ;
} else {
( void ) F_5 ( V_11 , NULL ) ;
}
}
static void F_11 ( enum V_13 V_14 ,
struct V_3 * V_15 )
{
switch ( V_14 ) {
case V_16 :
V_10 = true ;
F_9 () ;
break;
case V_17 :
V_10 = false ;
break;
case V_18 :
case V_19 :
F_6 ( 0 , V_1 + V_5 ) ;
F_6 ( 0 , V_1 + F_8 ( 1 ) ) ;
F_6 ( 0xffffffff , V_1 + F_7 ( 1 ) ) ;
break;
case V_20 :
break;
}
}
static T_3 F_12 ( int V_21 , void * V_22 )
{
struct V_3 * V_23 = V_22 ;
F_6 ( 1 << 1 , V_1 + V_24 ) ;
V_23 -> V_25 ( V_23 ) ;
return V_26 ;
}
void F_13 ( void )
{
F_6 ( 0 , V_1 + F_8 ( 0 ) ) ;
F_6 ( V_11 , V_1 + F_7 ( 0 ) ) ;
F_6 ( V_11 , V_1 + F_10 ( 0 ) ) ;
F_6 ( V_7 | V_8 | V_9 ,
V_1 + F_8 ( 0 ) ) ;
}
void T_4 F_14 ( void T_5 * V_27 , int V_21 )
{
unsigned long V_28 ;
struct V_29 * V_30 , * V_31 ;
V_1 = V_27 ;
V_31 = F_15 ( L_1 , L_2 ) ;
F_16 ( F_17 ( V_31 ) ) ;
F_16 ( F_18 ( V_31 ) < 0 ) ;
F_16 ( F_19 ( V_31 ) < 0 ) ;
V_30 = F_15 ( L_1 , NULL ) ;
F_16 ( F_17 ( V_30 ) ) ;
F_16 ( F_18 ( V_30 ) < 0 ) ;
F_16 ( F_19 ( V_30 ) < 0 ) ;
V_28 = F_20 ( V_30 ) ;
if ( V_28 > 32000000 ) {
V_28 /= 16 ;
V_7 = V_32 ;
} else {
V_7 = V_33 ;
}
V_11 = F_21 ( V_28 , V_34 ) ;
F_13 () ;
if ( F_22 ( V_1 + F_4 ( 0 ) , L_3 ,
V_28 , 200 , 32 , V_35 ) )
F_23 ( L_4 ,
L_3 ) ;
#ifdef F_24
F_25 ( F_1 , 32 , V_28 ) ;
#endif
F_26 ( V_21 , & V_36 ) ;
V_37 . V_38 = F_27 ( 0 ) ;
F_28 ( & V_37 , V_28 , 2 , 0xffffffffU ) ;
}
