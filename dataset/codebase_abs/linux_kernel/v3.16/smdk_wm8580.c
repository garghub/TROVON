static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 ;
int V_12 , V_13 , V_14 ;
switch ( F_2 ( V_4 ) ) {
case 8 :
V_12 = 16 ;
break;
case 16 :
V_12 = 32 ;
break;
default:
return - V_15 ;
}
switch ( F_3 ( V_4 ) ) {
case 16000 :
case 22050 :
case 32000 :
case 44100 :
case 48000 :
case 88200 :
case 96000 :
V_13 = 256 ;
break;
case 64000 :
V_13 = 384 ;
break;
case 8000 :
case 11025 :
V_13 = 512 ;
break;
default:
return - V_15 ;
}
V_11 = F_3 ( V_4 ) * V_13 ;
V_14 = F_4 ( V_10 , V_16
| V_17
| V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_4 ( V_9 , V_16
| V_17
| V_18 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_10 , V_19 ,
V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_6 ( V_10 , V_21 , 0 ,
V_22 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_7 ( V_10 , V_20 ,
V_11 , V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = V_6 -> V_25 ;
struct V_26 * V_27 = & V_25 -> V_27 ;
F_9 ( V_27 , L_1 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
int V_14 ;
char * V_28 ;
if ( F_11 ()
|| F_12 () || F_13 () ) {
V_29 . V_30 = 3 ;
} else if ( F_14 () ) {
V_28 = ( char * ) V_31 [ V_32 ] . V_33 ;
V_28 [ strlen ( V_28 ) - 1 ] = '2' ;
V_28 = ( char * ) V_31 [ V_34 ] . V_33 ;
V_28 [ strlen ( V_28 ) - 1 ] = '2' ;
}
V_35 = F_15 ( L_2 , - 1 ) ;
if ( ! V_35 )
return - V_36 ;
F_16 ( V_35 , & V_29 ) ;
V_14 = F_17 ( V_35 ) ;
if ( V_14 )
F_18 ( V_35 ) ;
return V_14 ;
}
static void T_2 F_19 ( void )
{
F_20 ( V_35 ) ;
}
