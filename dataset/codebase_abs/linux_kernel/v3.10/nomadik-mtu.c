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
void F_11 ( void )
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
static void F_13 ( enum V_13 V_14 ,
struct V_3 * V_15 )
{
switch ( V_14 ) {
case V_16 :
V_10 = true ;
F_11 () ;
break;
case V_17 :
V_10 = false ;
break;
case V_18 :
case V_19 :
F_8 ( 0 , V_1 + V_5 ) ;
F_8 ( 0 , V_1 + F_10 ( 1 ) ) ;
F_8 ( 0xffffffff , V_1 + F_9 ( 1 ) ) ;
break;
case V_20 :
break;
}
}
void F_14 ( void )
{
F_8 ( 0 , V_1 + F_10 ( 0 ) ) ;
F_8 ( V_11 , V_1 + F_9 ( 0 ) ) ;
F_8 ( V_11 , V_1 + F_12 ( 0 ) ) ;
F_8 ( V_7 | V_8 | V_9 ,
V_1 + F_10 ( 0 ) ) ;
}
static void F_15 ( struct V_3 * V_21 )
{
F_11 () ;
F_14 () ;
}
static T_3 F_16 ( int V_22 , void * V_23 )
{
struct V_3 * V_24 = V_23 ;
F_8 ( 1 << 1 , V_1 + V_25 ) ;
V_24 -> V_26 ( V_24 ) ;
return V_27 ;
}
void T_4 F_17 ( void T_5 * V_28 , int V_22 )
{
unsigned long V_29 ;
struct V_30 * V_31 , * V_32 ;
V_1 = V_28 ;
V_32 = F_18 ( L_1 , L_2 ) ;
F_19 ( F_20 ( V_32 ) ) ;
F_19 ( F_21 ( V_32 ) < 0 ) ;
F_19 ( F_22 ( V_32 ) < 0 ) ;
V_31 = F_18 ( L_1 , NULL ) ;
F_19 ( F_20 ( V_31 ) ) ;
F_19 ( F_21 ( V_31 ) < 0 ) ;
F_19 ( F_22 ( V_31 ) < 0 ) ;
V_29 = F_23 ( V_31 ) ;
if ( V_29 > 32000000 ) {
V_29 /= 16 ;
V_7 = V_33 ;
} else {
V_7 = V_34 ;
}
V_11 = F_24 ( V_29 , V_35 ) ;
F_14 () ;
if ( F_25 ( V_1 + F_4 ( 0 ) , L_3 ,
V_29 , 200 , 32 , V_36 ) )
F_26 ( L_4 ,
L_3 ) ;
#ifdef F_27
F_28 ( F_1 , 32 , V_29 ) ;
#endif
F_29 ( V_22 , & V_37 ) ;
V_38 . V_39 = F_30 ( 0 ) ;
V_38 . V_22 = V_22 ;
F_31 ( & V_38 , V_29 , 2 , 0xffffffffU ) ;
V_40 . V_41 = & F_5 ;
V_40 . V_42 = V_29 ;
F_32 ( & V_40 ) ;
}
