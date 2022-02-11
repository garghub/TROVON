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
F_3 ( V_7 ,
V_14 ,
0x0107 ,
0x0105 ) ;
F_2 ( V_7 , V_13 ,
0 ) ;
break;
case V_15 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 ,
V_14 , 0x0008 ) ;
break;
case V_16 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 ,
V_14 , 0x0100 ) ;
break;
case V_17 :
case V_18 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 , V_14 ,
0x0000 ) ;
F_2 ( V_7 , V_14 ,
0x0004 ) ;
break;
case V_19 :
F_2 ( V_7 , V_13 ,
V_9 ) ;
F_2 ( V_7 , V_14 ,
0x00f0 ) ;
F_2 ( V_7 , V_14 ,
0x00f4 ) ;
break;
}
F_4 () ;
return V_20 ;
}
static int T_1 F_5 ( void )
{
const struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
V_24 = F_6 ( NULL , V_26 ,
& V_22 ) ;
if ( ! V_24 )
return - V_27 ;
V_5 = (enum F_1 ) V_22 -> V_28 ;
V_7 = F_7 ( V_24 ) ;
if ( F_8 ( V_7 ) )
return F_9 ( V_7 ) ;
V_25 = F_10 ( & V_29 ) ;
if ( V_25 )
return V_25 ;
F_11 ( L_1 ) ;
return 0 ;
}
