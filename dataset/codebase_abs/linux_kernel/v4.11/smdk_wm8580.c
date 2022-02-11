static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
int V_11 , V_12 ;
switch ( F_2 ( V_4 ) ) {
case 8 :
case 16 :
break;
default:
return - V_13 ;
}
switch ( F_3 ( V_4 ) ) {
case 16000 :
case 22050 :
case 32000 :
case 44100 :
case 48000 :
case 88200 :
case 96000 :
V_11 = 256 ;
break;
case 64000 :
V_11 = 384 ;
break;
case 8000 :
case 11025 :
V_11 = 512 ;
break;
default:
return - V_13 ;
}
V_10 = F_3 ( V_4 ) * V_11 ;
V_12 = F_4 ( V_9 , V_14 ,
V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_9 , V_16 , 0 ,
V_17 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_9 , V_15 ,
V_10 , V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_19 -> V_20 , L_1 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
int V_12 ;
V_21 = F_10 ( L_2 , - 1 ) ;
if ( ! V_21 )
return - V_22 ;
F_11 ( V_21 , & V_23 ) ;
V_12 = F_12 ( V_21 ) ;
if ( V_12 )
F_13 ( V_21 ) ;
return V_12 ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_21 ) ;
}
