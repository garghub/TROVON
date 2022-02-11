static inline void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 &= ~ V_4 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static inline void F_4 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 |= V_4 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static void F_5 ( void )
{
F_3 ( V_5 , V_2 + V_6 ) ;
}
static int T_2 F_6 ( struct V_7 * V_8 )
{
unsigned int V_9 = F_7 ( V_8 ) ;
return F_8 ( V_2 + V_10 , L_1 , V_9 , 200 , 32 ,
V_11 ) ;
}
static int F_9 ( unsigned long V_12 ,
struct V_13 * V_14 )
{
unsigned long V_15 ;
V_15 = F_2 ( V_2 + V_10 ) ;
F_3 ( V_15 - V_12 , V_2 + V_16 ) ;
return 0 ;
}
static void F_10 ( enum V_17 V_18 ,
struct V_13 * V_12 )
{
unsigned long V_19 ;
F_11 ( V_19 ) ;
F_1 () ;
if ( V_18 != V_20 ) {
F_5 () ;
}
V_20 = V_18 ;
F_12 ( V_19 ) ;
switch ( V_18 ) {
case V_21 :
F_13 ( V_22 L_2
L_3 ) ;
break;
case V_23 :
F_11 ( V_19 ) ;
F_4 () ;
F_12 ( V_19 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
break;
}
}
static T_3 F_14 ( int V_27 , void * V_28 )
{
struct V_13 * V_12 = & V_29 ;
F_5 () ;
V_12 -> V_30 ( V_12 ) ;
return V_31 ;
}
static int T_2 F_15 ( struct V_7 * V_8 )
{
unsigned int V_9 = F_7 ( V_8 ) ;
V_29 . V_32 = F_16 ( V_9 , V_33 ,
V_29 . V_34 ) ;
V_29 . V_35 =
F_17 ( 0xfffffffe , & V_29 ) ;
V_29 . V_36 =
F_17 ( 0x800 , & V_29 ) ;
V_29 . V_37 = F_18 ( 0 ) ;
F_19 ( & V_29 ) ;
return 0 ;
}
void T_2 F_20 ( void T_4 * V_38 , int V_27 )
{
struct V_7 * V_8 ;
V_8 = F_21 ( L_4 , NULL ) ;
if ( F_22 ( V_8 ) ) {
F_23 ( L_5 ) ;
return;
}
F_24 ( V_8 ) ;
V_2 = V_38 ;
F_3 ( 0x0 , V_2 + V_3 ) ;
F_3 ( 0xffffffff , V_2 + V_39 ) ;
F_3 ( V_40 | V_41 | V_42 ,
V_2 + V_3 ) ;
F_6 ( V_8 ) ;
F_15 ( V_8 ) ;
F_25 ( V_27 , & V_43 ) ;
}
