static int T_1 F_1 ( char * V_1 )
{
if( ! strncmp ( V_1 , L_1 , strlen ( L_1 ) ) ) {
V_2 = 1 ;
return 1 ;
}
return 0 ;
}
static void F_2 ( void )
{
#ifdef F_3
F_4 ( 0x00 , V_3 ) ;
#endif
F_5 ( F_6 ( V_4 ) | V_5 , V_4 ) ;
#ifdef F_3
F_4 ( V_3 , 0x00 ) ;
#endif
}
static inline void F_7 ( struct V_6 * V_7 )
{
F_8 ( & V_7 -> V_8 [ 0 ] , V_9 , F_9 ( & V_7 -> V_8 [ 0 ] ) ) ;
}
static int F_10 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
return 0 ;
}
static int F_11 ( struct V_10 * V_10 , struct V_11 * V_12 )
{
return 0 ;
}
static long F_12 ( struct V_11 * V_12 , unsigned int V_13 , unsigned long V_14 )
{
T_2 V_15 , V_16 * V_17 = ( T_2 V_16 * ) V_14 ;
switch ( V_13 ) {
case V_18 :
if ( F_13 ( F_6 ( V_19 ) & V_20 , V_17 ) )
return - V_21 ;
break;
case V_22 :
if ( F_13 ( F_6 ( V_23 ) & V_20 , V_17 ) )
return - V_21 ;
break;
case V_24 :
if ( F_13 ( F_6 ( V_25 ) & V_26 , V_17 ) )
return - V_21 ;
break;
case V_27 :
if ( F_14 ( V_15 , V_17 ) )
return - V_21 ;
F_5 ( V_15 & V_20 , V_19 ) ;
break;
case V_28 :
if ( F_14 ( V_15 , V_17 ) )
return - V_21 ;
F_5 ( V_15 & V_20 , V_23 ) ;
break;
case V_29 :
if ( F_14 ( V_15 , V_17 ) )
return - V_21 ;
F_5 ( V_15 & V_26 , V_25 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int T_3 F_15 ( struct V_6 * V_7 )
{
int V_31 ;
V_9 = F_16 ( & V_7 -> V_8 [ 0 ] , 0 ,
F_9 ( & V_7 -> V_8 [ 0 ] ) , V_32 ) ;
if ( ! V_9 ) {
F_17 ( V_33 L_2 , V_34 ) ;
return - V_35 ;
}
V_31 = F_18 ( & V_36 ) ;
if ( V_31 ) {
F_17 ( V_33 L_3 , V_34 ) ;
F_7 ( V_7 ) ;
return - V_35 ;
}
if ( ! V_2 )
V_37 = F_2 ;
F_17 ( V_38 L_4 ,
V_34 , V_2 ? L_5 : L_6 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_39 ) ;
}
