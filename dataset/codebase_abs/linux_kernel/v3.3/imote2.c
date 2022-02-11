static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = 0 ;
int V_12 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_11 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_11 = 11289600 ;
break;
}
V_12 = F_3 ( V_9 , 0 , V_11 ,
V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_10 , V_14 , V_11 ,
V_15 ) ;
return V_12 ;
}
static int T_1 F_4 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_20 ;
int V_12 ;
V_19 -> V_21 = & V_17 -> V_21 ;
V_12 = F_5 ( V_19 ) ;
if ( V_12 )
F_6 ( & V_17 -> V_21 , L_1 ,
V_12 ) ;
return V_12 ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_8 ( V_17 ) ;
F_9 ( V_19 ) ;
return 0 ;
}
