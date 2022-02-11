static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = 0 ;
int V_12 = 0 ;
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
V_12 = F_3 ( V_9 , V_13 , V_11 ,
V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_10 , V_15 , 0 ,
V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
int V_12 ;
V_12 = F_5 ( V_6 -> V_16 , L_1 , V_17 ,
& V_18 , V_19 ,
F_6 ( V_19 ) ) ;
if ( V_12 )
goto V_20;
V_12 = F_7 ( & V_18 , F_6 ( V_21 ) ,
V_21 ) ;
if ( V_12 )
goto V_20;
return 0 ;
V_20:
return V_12 ;
}
static int T_1 F_8 ( void )
{
int V_12 ;
if ( ! F_9 () )
return - V_22 ;
V_23 = F_10 ( L_2 , - 1 ) ;
if ( ! V_23 )
return - V_24 ;
F_11 ( V_23 , & V_25 ) ;
V_12 = F_12 ( V_23 ) ;
if ( V_12 )
F_13 ( V_23 ) ;
return V_12 ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_23 ) ;
}
