static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
switch ( F_2 ( V_4 ) ) {
default:
case 44100 :
V_10 = 11289600 ;
break;
case 48000 :
V_10 = 12288000 ;
break;
case 96000 :
V_10 = 24576000 ;
break;
}
return F_3 ( V_9 , 0 , V_10 , V_11 ) ;
}
static int T_1 F_4 ( void )
{
int V_12 ;
if ( ! F_5 () && ! F_6 () )
return 0 ;
V_13 = F_7 ( L_1 , - 1 ) ;
if ( ! V_13 )
return - V_14 ;
F_8 ( V_13 ,
& V_15 ) ;
V_12 = F_9 ( V_13 ) ;
if ( V_12 ) {
F_10 ( V_16 L_2 , V_17 ) ;
F_11 ( V_13 ) ;
}
return V_12 ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_13 ) ;
}
