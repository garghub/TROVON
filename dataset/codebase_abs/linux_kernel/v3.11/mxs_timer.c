static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 +
F_3 ( 0 ) + V_3 ) ;
}
static inline void F_4 ( void )
{
F_2 ( V_1 , V_2 +
F_3 ( 0 ) + V_4 ) ;
}
static void F_5 ( void )
{
F_2 ( V_5 , V_2 +
F_3 ( 0 ) + V_3 ) ;
}
static T_1 F_6 ( struct V_6 * V_7 )
{
return ~ ( ( F_7 ( V_2 + F_8 ( 1 ) )
& 0xffff0000 ) >> 16 ) ;
}
static int F_9 ( unsigned long V_8 ,
struct V_9 * V_10 )
{
F_2 ( V_8 , V_2 + F_8 ( 0 ) ) ;
return 0 ;
}
static int F_10 ( unsigned long V_8 ,
struct V_9 * V_10 )
{
F_2 ( V_8 , V_2 + F_11 ( 0 ) ) ;
return 0 ;
}
static T_2 F_12 ( int V_11 , void * V_12 )
{
struct V_9 * V_8 = V_12 ;
F_5 () ;
V_8 -> V_13 ( V_8 ) ;
return V_14 ;
}
static void F_13 ( enum V_15 V_16 ,
struct V_9 * V_8 )
{
F_1 () ;
if ( V_16 != V_17 ) {
if ( F_14 () )
F_2 ( 0xffff ,
V_2 + F_8 ( 1 ) ) ;
else
F_2 ( 0xffffffff ,
V_2 + F_11 ( 1 ) ) ;
F_5 () ;
}
#ifdef F_15
F_16 ( L_1 , V_18 ,
V_19 [ V_17 ] ,
V_19 [ V_16 ] ) ;
#endif
V_17 = V_16 ;
switch ( V_16 ) {
case V_20 :
F_17 ( L_2 , V_18 ) ;
break;
case V_21 :
F_4 () ;
break;
case V_22 :
case V_23 :
case V_24 :
break;
}
}
static int T_3 F_18 ( struct V_25 * V_26 )
{
if ( F_14 () )
V_27 . V_28 = F_9 ;
V_27 . V_29 = F_19 ( 0 ) ;
F_20 ( & V_27 ,
F_21 ( V_26 ) ,
F_14 () ? 0xf : 0x2 ,
F_14 () ? 0xfffe : 0xfffffffe ) ;
return 0 ;
}
static T_4 T_5 F_22 ( void )
{
return ~ F_23 ( V_2 + F_24 ( 1 ) ) ;
}
static int T_3 F_25 ( struct V_25 * V_26 )
{
unsigned int V_30 = F_21 ( V_26 ) ;
if ( F_14 () )
F_26 ( & V_31 , V_30 ) ;
else {
F_27 ( V_2 + F_24 ( 1 ) ,
L_3 , V_30 , 200 , 32 , V_32 ) ;
F_28 ( F_22 , 32 , V_30 ) ;
}
return 0 ;
}
static void T_3 F_29 ( struct V_33 * V_34 )
{
struct V_25 * V_26 ;
int V_11 ;
V_2 = F_30 ( V_34 , 0 ) ;
F_31 ( ! V_2 ) ;
V_26 = F_32 ( V_34 , 0 ) ;
if ( F_33 ( V_26 ) ) {
F_17 ( L_4 , V_18 ) ;
return;
}
F_34 ( V_26 ) ;
F_35 ( V_2 + V_35 ) ;
V_36 = F_7 ( V_2 +
( F_36 ( V_34 , L_5 ) ?
V_37 :
V_38 ) ) ;
V_36 >>= V_39 ;
F_2 ( ( F_14 () ?
V_40 :
V_41 ) |
V_42 |
V_1 ,
V_2 + F_3 ( 0 ) ) ;
F_2 ( ( F_14 () ?
V_40 :
V_41 ) |
V_43 ,
V_2 + F_3 ( 1 ) ) ;
if ( F_14 () )
F_2 ( 0xffff ,
V_2 + F_8 ( 1 ) ) ;
else
F_2 ( 0xffffffff ,
V_2 + F_11 ( 1 ) ) ;
F_25 ( V_26 ) ;
F_18 ( V_26 ) ;
V_11 = F_37 ( V_34 , 0 ) ;
F_38 ( V_11 , & V_44 ) ;
}
