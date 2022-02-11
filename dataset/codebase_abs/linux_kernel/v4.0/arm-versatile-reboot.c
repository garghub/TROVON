static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
switch ( V_5 ) {
case V_6 :
F_2 ( V_7 , V_8 ,
V_9 ) ;
F_3 ( V_7 ,
V_10 ,
V_11 ,
V_11 ) ;
break;
case V_12 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 ,
V_14 , 0x0008 ) ;
break;
case V_15 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 ,
V_14 , 0x0100 ) ;
break;
case V_16 :
case V_17 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 , V_14 ,
0x0000 ) ;
F_2 ( V_7 , V_14 ,
0x0004 ) ;
break;
case V_18 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 , V_14 ,
0x00f0 ) ;
F_2 ( V_7 , V_14 ,
0x00f4 ) ;
break;
}
F_4 () ;
return V_19 ;
}
static int T_1 F_5 ( void )
{
const struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
V_23 = F_6 ( NULL , V_25 ,
& V_21 ) ;
if ( ! V_23 )
return - V_26 ;
V_5 = (enum F_1 ) V_21 -> V_27 ;
V_7 = F_7 ( V_23 ) ;
if ( F_8 ( V_7 ) )
return F_9 ( V_7 ) ;
V_24 = F_10 ( & V_28 ) ;
if ( V_24 )
return V_24 ;
F_11 ( L_1 ) ;
return 0 ;
}
