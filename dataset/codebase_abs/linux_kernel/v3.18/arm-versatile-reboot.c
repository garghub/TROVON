static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
F_2 ( V_4 , V_5 ,
V_6 ) ;
switch ( V_7 ) {
case V_8 :
F_2 ( V_4 ,
V_9 , 0x0008 ) ;
break;
case V_10 :
F_2 ( V_4 ,
V_9 , 0x0100 ) ;
break;
case V_11 :
case V_12 :
F_2 ( V_4 , V_9 ,
0x0000 ) ;
F_2 ( V_4 , V_9 ,
0x0004 ) ;
break;
case V_13 :
F_2 ( V_4 , V_9 ,
0x00f0 ) ;
F_2 ( V_4 , V_9 ,
0x00f4 ) ;
break;
}
F_3 () ;
}
static int T_1 F_4 ( void )
{
const struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_17 = F_5 ( NULL , V_18 ,
& V_15 ) ;
if ( ! V_17 )
return - V_19 ;
V_7 = (enum F_1 ) V_15 -> V_20 ;
V_4 = F_6 ( V_17 ) ;
if ( F_7 ( V_4 ) )
return F_8 ( V_4 ) ;
V_21 = F_1 ;
F_9 ( L_1 ) ;
return 0 ;
}
