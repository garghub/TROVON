static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
F_2 ( V_4 , - V_1 ) ;
return 0 ;
}
static T_1 F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_7 ) ;
}
static T_2 F_5 ( int V_8 , void * V_9 )
{
struct V_2 * V_10 = F_6 ( & V_11 ) ;
V_10 -> V_12 ( V_10 ) ;
return V_13 ;
}
unsigned long long F_7 ( void )
{
unsigned long long V_14 = F_4 ( V_7 ) ;
return V_14 << V_15 ;
}
static void F_8 ( unsigned int V_16 )
{
unsigned int V_17 ;
struct V_2 * V_18 = & F_9 ( V_11 , V_16 ) ;
char * V_19 = F_9 ( V_20 , V_16 ) ;
V_17 = F_4 ( V_21 ) ;
V_17 &= ~ V_22 ;
V_17 |= ( V_23 & V_22 ) ;
F_2 ( V_21 , V_17 ) ;
sprintf ( V_19 , L_1 , V_16 ) ;
V_18 -> V_19 = V_19 ;
V_18 -> V_24 = V_25 ,
V_18 -> V_26 = 200 ,
V_18 -> V_27 = 12 ,
V_18 -> V_8 = F_10 ( V_28 ) ,
V_18 -> V_29 = F_1 ,
V_18 -> V_30 = F_11 ( V_31 , V_32 , V_18 -> V_27 ) ;
V_18 -> V_33 = F_12 ( 0x7fffffff , V_18 ) ;
V_18 -> V_34 = F_12 ( 0xf , V_18 ) ;
V_18 -> V_35 = F_13 ( V_16 ) ;
F_14 ( V_18 ) ;
if ( V_16 ) {
unsigned int V_36 = V_37 [ 0 ] ;
unsigned long V_38 ;
V_38 = F_15 ( V_39 , V_40 , V_36 ) ;
F_2 ( V_7 , V_38 ) ;
}
}
static int F_16 ( struct V_41 * V_42 ,
unsigned long V_43 , void * V_44 )
{
int V_16 = ( long ) V_44 ;
switch ( V_43 ) {
case V_45 :
case V_46 :
F_8 ( V_16 ) ;
break;
}
return V_47 ;
}
int T_3 F_17 ( void )
{
#ifdef F_18
V_31 = F_19 () / ( F_20 ( V_48 ) + 1 ) ;
#endif
F_21 ( L_2 , V_31 ) ;
F_22 ( & V_49 , V_31 ) ;
F_23 ( F_10 ( V_28 ) , & V_50 ) ;
F_8 ( F_24 () ) ;
F_25 ( & V_51 ) ;
return 0 ;
}
