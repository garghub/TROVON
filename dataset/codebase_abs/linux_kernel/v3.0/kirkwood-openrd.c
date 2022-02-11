static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
unsigned int V_12 , V_13 ;
V_13 = V_14 | V_15 ;
V_11 = F_2 ( V_10 , V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_2 ( V_9 , V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( F_3 ( V_4 ) ) {
default:
case 44100 :
V_12 = 11289600 ;
break;
case 48000 :
V_12 = 12288000 ;
break;
case 96000 :
V_12 = 24576000 ;
break;
}
return F_4 ( V_9 , 0 , V_12 , V_16 ) ;
}
static int T_1 F_5 ( void )
{
int V_11 ;
if ( ! F_6 () && ! F_7 () )
return 0 ;
V_17 = F_8 ( L_1 , - 1 ) ;
if ( ! V_17 )
return - V_18 ;
F_9 ( V_17 ,
& V_19 ) ;
V_11 = F_10 ( V_17 ) ;
if ( V_11 ) {
F_11 ( V_20 L_2 , V_21 ) ;
F_12 ( V_17 ) ;
}
return V_11 ;
}
static void T_2 F_13 ( void )
{
F_14 ( V_17 ) ;
}
