static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 ;
int V_12 , V_13 , V_14 ;
switch ( F_2 ( V_4 ) ) {
case V_15 :
case V_16 :
V_12 = 16 ;
break;
case V_17 :
case V_18 :
V_12 = 32 ;
break;
default:
return - V_19 ;
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
return - V_19 ;
}
V_11 = F_3 ( V_4 ) * V_13 ;
V_14 = F_4 ( V_10 , V_20
| V_21
| V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_4 ( V_9 , V_20
| V_21
| V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_10 , V_23 ,
V_24 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_6 ( V_10 , V_25 , 0 ,
V_26 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_7 ( V_10 , V_24 ,
V_11 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
F_9 ( V_31 , V_32 ,
F_10 ( V_32 ) ) ;
F_11 ( V_31 , V_33 , F_10 ( V_33 ) ) ;
F_12 ( V_31 , L_1 ) ;
F_13 ( V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = V_6 -> V_29 ;
struct V_30 * V_31 = & V_29 -> V_31 ;
F_9 ( V_31 , V_34 ,
F_10 ( V_34 ) ) ;
F_11 ( V_31 , V_35 , F_10 ( V_35 ) ) ;
F_13 ( V_31 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
int V_14 ;
char * V_36 ;
if ( F_16 ()
|| F_17 () || F_18 () ) {
V_37 . V_38 = 3 ;
V_36 = ( char * ) V_39 [ V_40 ] . V_41 ;
V_36 [ strlen ( V_36 ) - 1 ] = '0' + V_42 ;
} else if ( F_19 () ) {
V_36 = ( char * ) V_39 [ V_43 ] . V_41 ;
V_36 [ strlen ( V_36 ) - 1 ] = '2' ;
V_36 = ( char * ) V_39 [ V_44 ] . V_41 ;
V_36 [ strlen ( V_36 ) - 1 ] = '2' ;
}
V_45 = F_20 ( L_2 , - 1 ) ;
if ( ! V_45 )
return - V_46 ;
F_21 ( V_45 , & V_37 ) ;
V_14 = F_22 ( V_45 ) ;
if ( V_14 )
F_23 ( V_45 ) ;
return V_14 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_45 ) ;
}
