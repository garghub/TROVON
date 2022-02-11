static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
int V_12 ;
V_11 = F_2 ( V_9 , V_13 |
V_14 | V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_2 ( V_10 , V_13 |
V_14 | V_15 ) ;
if ( V_11 )
return V_11 ;
switch ( F_3 ( V_4 ) ) {
case 48000 :
case 8000 :
case 12000 :
case 16000 :
case 24000 :
case 32000 :
V_12 = 48000 * 1024 ;
break;
case 44100 :
case 7350 :
case 11025 :
case 14700 :
case 22050 :
case 29400 :
V_12 = 44100 * 1024 ;
break;
default:
return - V_16 ;
}
V_11 = F_4 ( V_10 , V_17 ,
V_18 , 12288000 , V_12 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_10 , V_19 , V_12 ,
V_20 ) ;
return V_11 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_12 = 48000 * 1024 ;
int V_11 ;
V_11 = F_4 ( V_10 , V_17 ,
V_18 , 12288000 , V_12 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_10 , V_19 , V_12 ,
V_20 ) ;
return V_11 ;
}
static int F_7 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_25 ;
V_24 -> V_26 = & V_22 -> V_26 ;
return F_8 ( & V_25 ) ;
}
static int T_1 F_9 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_10 ( V_22 ) ;
F_11 ( V_24 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_27 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_27 ) ;
}
