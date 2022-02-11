static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 , V_3 + V_4 ) ;
F_3 ( V_5 , V_3 + V_4 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
T_1 V_6 ;
T_1 V_7 ;
unsigned long V_8 ;
V_8 = F_6 ( V_9 ) ;
F_2 ( & V_1 ) ;
F_3 ( 0 , V_3 + V_10 ) ;
F_3 ( 0 , V_3 + V_11 ) ;
V_6 = V_12 | V_13 | V_14 ;
F_3 ( V_6 , V_3 + V_11 ) ;
F_3 ( 0 , V_3 + V_15 ) ;
F_3 ( 0 , V_3 + V_16 ) ;
V_7 = ( ( ( V_17 ) V_18 * V_8 ) & 0xffffffff ) ;
F_3 ( V_7 , V_3 + V_19 ) ;
V_7 = ( ( ( V_17 ) V_18 * V_8 ) >> 32 ) ;
F_3 ( V_7 , V_3 + V_20 ) ;
F_3 ( V_21 , V_3 + V_10 ) ;
F_3 ( V_2 | V_22 , V_3 + V_4 ) ;
F_3 ( V_5 | V_22 , V_3 + V_4 ) ;
F_4 ( & V_1 ) ;
}
static int F_7 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
if ( F_8 ( V_25 , & V_26 ) )
return - V_27 ;
F_5 () ;
return F_9 ( V_23 , V_24 ) ;
}
static T_2
F_10 ( struct V_24 * V_24 , const char * V_28 , T_3 V_29 ,
T_4 * V_30 )
{
if ( V_29 )
F_1 () ;
return V_29 ;
}
static long F_11 ( struct V_24 * V_24 ,
unsigned int V_31 , unsigned long V_32 )
{
int V_33 = - V_34 ;
switch ( V_31 ) {
case V_35 :
V_33 = F_12 ( (struct V_36 * ) V_32 , & V_37 ,
sizeof( V_37 ) ) ? - V_38 : 0 ;
break;
case V_39 :
case V_40 :
V_33 = F_13 ( 0 , ( int * ) V_32 ) ;
break;
case V_41 :
F_1 () ;
V_33 = 0 ;
break;
case V_42 :
V_33 = F_13 ( V_18 , ( int * ) V_32 ) ;
break;
}
return V_33 ;
}
static int F_14 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
F_1 () ;
F_15 ( V_25 , & V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_43 * V_44 )
{
int V_33 = 0 ;
struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_47 * V_48 ;
V_9 = F_17 ( V_46 , NULL ) ;
if ( F_18 ( F_19 ( V_9 ) ) )
return F_20 ( V_9 ) ;
F_21 ( V_9 ) ;
if ( V_18 < 1 || V_18 > V_49 )
V_18 = V_50 ;
F_22 ( V_46 , L_1 , V_18 ) ;
V_48 = F_23 ( V_44 , V_51 , 0 ) ;
V_3 = F_24 ( V_46 , V_48 ) ;
if ( F_19 ( V_3 ) )
return F_20 ( V_3 ) ;
V_33 = F_25 ( & V_52 ) ;
if ( V_33 < 0 ) {
F_26 ( V_46 , L_2 ) ;
} else {
F_27 ( V_53 , & V_26 ) ;
}
return V_33 ;
}
static int F_28 ( struct V_43 * V_44 )
{
F_29 ( & V_52 ) ;
F_30 ( V_9 ) ;
return 0 ;
}
