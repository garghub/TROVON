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
V_11 = 48000 * 1024 ;
break;
case 44100 :
case 7350 :
case 11025 :
case 14700 :
case 22050 :
case 29400 :
V_11 = 44100 * 1024 ;
break;
default:
return - V_12 ;
}
V_10 = F_3 ( V_9 , V_13 ,
V_14 , 12288000 , V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_4 ( V_9 , V_15 , V_11 ,
V_16 ) ;
return V_10 ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_11 = 48000 * 1024 ;
int V_10 ;
V_10 = F_3 ( V_9 , V_13 ,
V_14 , 12288000 , V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_4 ( V_9 , V_15 , V_11 ,
V_16 ) ;
return V_10 ;
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_21 ;
V_20 -> V_22 = & V_18 -> V_22 ;
return F_7 ( & V_21 ) ;
}
static int T_1 F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_9 ( V_18 ) ;
F_10 ( V_20 ) ;
return 0 ;
}
