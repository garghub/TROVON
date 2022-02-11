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
case 32000 :
case 48000 :
case 96000 :
V_11 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_11 = 11289600 ;
break;
}
V_12 = F_3 ( V_10 , V_13 ,
0 , V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_10 , V_15 ,
0 , V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_9 , V_16 , V_11 ,
V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_4 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
int V_21 )
{
F_5 ( F_6 ( 12 ) , F_7 ( V_21 ) ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_24 -> V_23 ;
int V_25 = 0 ;
F_9 ( V_23 , L_1 ) ;
F_9 ( V_23 , L_2 ) ;
F_9 ( V_23 , L_3 ) ;
F_9 ( V_23 , L_4 ) ;
V_25 = F_10 ( V_6 -> V_24 , L_5 ,
V_26 , & V_27 ,
V_28 ,
F_11 ( V_28 ) ) ;
if ( V_25 )
return V_25 ;
V_25 = F_12 ( & V_27 ,
F_11 ( V_29 ) ,
V_29 ) ;
return V_25 ;
}
static int F_13 ( struct V_30 * V_24 )
{
F_14 ( & V_27 , F_11 ( V_29 ) ,
V_29 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
int V_12 ;
if ( ! F_16 () && ! F_17 () ) {
F_18 ( L_6 ) ;
return - V_31 ;
}
V_32 = F_19 ( L_7 , - 1 ) ;
if ( ! V_32 )
return - V_33 ;
F_20 ( V_32 , & V_34 ) ;
V_12 = F_21 ( V_32 ) ;
if ( V_12 ) {
F_22 ( V_32 ) ;
return V_12 ;
}
V_12 = F_23 ( F_6 ( 12 ) , L_8 ) ;
if ( V_12 ) {
F_24 ( & V_32 -> V_35 , L_9 ) ;
goto V_36;
}
V_12 = F_25 ( F_6 ( 12 ) , 1 ) ;
if ( V_12 ) {
F_24 ( & V_32 -> V_35 , L_10 ) ;
goto V_37;
}
return 0 ;
V_37:
F_26 ( F_6 ( 12 ) ) ;
V_36:
F_27 ( V_32 ) ;
return V_12 ;
}
static void T_2 F_28 ( void )
{
F_26 ( F_6 ( 12 ) ) ;
F_27 ( V_32 ) ;
}
