static int F_1 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 , V_6 ;
if ( F_2 ( V_5 , & V_4 -> V_5 ) )
return - V_7 ;
V_6 = F_3 ( V_2 , V_5 >> 24 , 0 ,
( V_5 >> 8 ) & 0xffff , V_5 & 0xff ) ;
if ( F_4 ( V_6 , & V_4 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 , V_6 ;
if ( F_2 ( V_5 , & V_4 -> V_5 ) )
return - V_7 ;
V_6 = F_6 ( V_2 , V_5 >> 24 ) ;
if ( F_4 ( V_6 , & V_4 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , struct V_10 * V_10 ,
unsigned int V_11 , unsigned long V_4 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
void T_1 * V_13 = ( void T_1 * ) V_4 ;
switch ( V_11 ) {
case V_14 :
return F_4 ( V_15 , ( int T_1 * ) V_13 ) ;
case V_16 :
return F_1 ( V_2 , V_13 ) ;
case V_17 :
return F_5 ( V_2 , V_13 ) ;
}
return - V_18 ;
}
static int F_8 ( struct V_8 * V_9 , struct V_10 * V_10 ,
unsigned int V_11 , unsigned long V_4 )
{
return F_7 ( V_9 , V_10 , V_11 , ( unsigned long ) F_9 ( V_4 ) ) ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_10 )
{
#ifndef F_11
if ( ! F_12 ( V_19 ) )
return - V_20 ;
#endif
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
char V_21 [ 16 ] ;
struct V_8 * V_22 ;
int V_23 ;
sprintf ( V_21 , L_1 , V_2 -> V_24 ) ;
V_23 = F_14 ( V_2 -> V_25 -> V_26 , V_21 , V_2 -> V_24 , & V_22 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_22 = V_22 ;
sprintf ( V_22 -> V_27 , L_1 , V_2 -> V_24 ) ;
V_22 -> V_28 = V_29 ;
V_22 -> V_12 = V_2 ;
V_22 -> V_30 = 1 ;
V_22 -> V_31 = V_32 ;
V_22 -> V_33 . V_34 = F_10 ;
V_22 -> V_33 . V_35 = F_7 ;
#ifdef F_15
V_22 -> V_33 . V_36 = F_8 ;
#endif
V_22 -> V_37 = & V_2 -> V_37 ;
return 0 ;
}
