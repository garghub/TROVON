static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
int V_11 ;
switch ( F_2 ( V_4 ) ) {
case 48000 :
case 8000 :
case 12000 :
case 16000 :
case 24000 :
case 32000 :
case 96000 :
V_10 = 48000 * 1024 ;
break;
case 44100 :
case 7350 :
case 11025 :
case 14700 :
case 22050 :
case 29400 :
case 88200 :
V_10 = 44100 * 1024 ;
break;
default:
return - V_12 ;
}
V_11 = F_3 ( V_9 , V_13 ,
V_14 , 12288000 , V_10 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_4 ( V_9 , V_15 , V_10 ,
V_16 ) ;
return V_11 ;
}
static int F_5 ( struct V_17 * V_18 )
{
V_19 . V_20 = & V_18 -> V_20 ;
return F_6 ( & V_18 -> V_20 , & V_19 ) ;
}
