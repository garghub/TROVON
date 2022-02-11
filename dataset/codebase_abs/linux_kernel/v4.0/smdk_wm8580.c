static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 ;
int V_11 , V_12 , V_13 ;
switch ( F_2 ( V_4 ) ) {
case 8 :
V_11 = 16 ;
break;
case 16 :
V_11 = 32 ;
break;
default:
return - V_14 ;
}
switch ( F_3 ( V_4 ) ) {
case 16000 :
case 22050 :
case 32000 :
case 44100 :
case 48000 :
case 88200 :
case 96000 :
V_12 = 256 ;
break;
case 64000 :
V_12 = 384 ;
break;
case 8000 :
case 11025 :
V_12 = 512 ;
break;
default:
return - V_14 ;
}
V_10 = F_3 ( V_4 ) * V_12 ;
V_13 = F_4 ( V_9 , V_15 ,
V_16 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 , V_17 , 0 ,
V_18 , V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_9 , V_16 ,
V_10 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_20 -> V_21 , L_1 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
int V_13 ;
char * V_22 ;
if ( F_10 ()
|| F_11 () || F_12 () ) {
V_23 . V_24 = 3 ;
} else if ( F_13 () ) {
V_22 = ( char * ) V_25 [ V_26 ] . V_27 ;
V_22 [ strlen ( V_22 ) - 1 ] = '2' ;
V_22 = ( char * ) V_25 [ V_28 ] . V_27 ;
V_22 [ strlen ( V_22 ) - 1 ] = '2' ;
}
V_29 = F_14 ( L_2 , - 1 ) ;
if ( ! V_29 )
return - V_30 ;
F_15 ( V_29 , & V_23 ) ;
V_13 = F_16 ( V_29 ) ;
if ( V_13 )
F_17 ( V_29 ) ;
return V_13 ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_29 ) ;
}
