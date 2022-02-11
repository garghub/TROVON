static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
F_2 ( V_4 , - V_1 ) ;
return 0 ;
}
static void F_3 ( enum V_5 V_6 ,
struct V_2 * V_7 )
{
switch ( V_6 ) {
case V_8 :
case V_9 :
break;
case V_10 :
break;
case V_11 :
case V_12 :
F_4 ( 1 ) ;
break;
} ;
}
static T_1 F_5 ( struct V_13 * V_14 )
{
return F_6 ( V_15 ) ;
}
static T_2 F_7 ( int V_16 , void * V_17 )
{
struct V_2 * V_7 = F_8 ( & V_18 ) ;
V_7 -> V_19 ( V_7 ) ;
return V_20 ;
}
unsigned long long F_9 ( void )
{
unsigned long long V_21 = F_6 ( V_15 ) ;
return V_21 << V_22 ;
}
static void F_10 ( unsigned int V_23 )
{
unsigned int V_24 ;
struct V_2 * V_25 = & F_11 ( V_18 , V_23 ) ;
char * V_26 = F_11 ( V_27 , V_23 ) ;
V_24 = F_6 ( V_28 ) ;
V_24 &= ~ V_29 ;
V_24 |= ( V_30 & V_29 ) ;
F_2 ( V_28 , V_24 ) ;
sprintf ( V_26 , L_1 , V_23 ) ;
V_25 -> V_26 = V_26 ;
V_25 -> V_31 = V_32 ,
V_25 -> V_33 = 200 ,
V_25 -> V_34 = 12 ,
V_25 -> V_16 = F_12 ( V_35 ) ,
V_25 -> V_36 = F_3 ,
V_25 -> V_37 = F_1 ,
V_25 -> V_38 = F_13 ( V_39 , V_40 , V_25 -> V_34 ) ;
V_25 -> V_41 = F_14 ( 0x7fffffff , V_25 ) ;
V_25 -> V_42 = F_14 ( 0xf , V_25 ) ;
V_25 -> V_43 = F_15 ( V_23 ) ;
F_16 ( V_25 ) ;
if ( V_23 ) {
unsigned int V_44 = V_45 [ 0 ] ;
unsigned long V_46 ;
V_46 = F_17 ( V_47 , V_48 , V_44 ) ;
F_2 ( V_15 , V_46 ) ;
}
}
static int F_18 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
int V_23 = ( long ) V_52 ;
switch ( V_51 ) {
case V_53 :
case V_54 :
F_10 ( V_23 ) ;
break;
}
return V_55 ;
}
int T_3 F_19 ( void )
{
#ifdef F_20
V_39 = F_21 () / ( F_22 ( V_56 ) + 1 ) ;
#endif
F_23 ( L_2 , V_39 ) ;
F_24 ( & V_57 , V_39 ) ;
F_25 ( F_12 ( V_35 ) , & V_58 ) ;
F_10 ( F_26 () ) ;
F_27 ( & V_59 ) ;
return 0 ;
}
