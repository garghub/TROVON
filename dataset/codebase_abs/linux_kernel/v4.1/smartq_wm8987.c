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
struct V_22 * V_23 = V_6 -> V_23 ;
struct V_24 * V_25 = & V_23 -> V_25 ;
int V_26 = 0 ;
F_9 ( V_25 , L_1 ) ;
F_9 ( V_25 , L_2 ) ;
F_9 ( V_25 , L_3 ) ;
F_9 ( V_25 , L_4 ) ;
F_10 ( V_25 , L_5 ) ;
V_26 = F_11 ( V_6 -> V_27 , L_5 ,
V_28 , & V_29 ,
V_30 ,
F_12 ( V_30 ) ) ;
if ( V_26 )
return V_26 ;
V_26 = F_13 ( & V_29 ,
F_12 ( V_31 ) ,
V_31 ) ;
return V_26 ;
}
static int F_14 ( struct V_32 * V_27 )
{
F_15 ( & V_29 , F_12 ( V_31 ) ,
V_31 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_12 ;
if ( ! F_17 () && ! F_18 () ) {
F_19 ( L_6 ) ;
return - V_33 ;
}
V_34 = F_20 ( L_7 , - 1 ) ;
if ( ! V_34 )
return - V_35 ;
F_21 ( V_34 , & V_36 ) ;
V_12 = F_22 ( V_34 ) ;
if ( V_12 ) {
F_23 ( V_34 ) ;
return V_12 ;
}
V_12 = F_24 ( F_6 ( 12 ) , L_8 ) ;
if ( V_12 ) {
F_25 ( & V_34 -> V_37 , L_9 ) ;
goto V_38;
}
V_12 = F_26 ( F_6 ( 12 ) , 1 ) ;
if ( V_12 ) {
F_25 ( & V_34 -> V_37 , L_10 ) ;
goto V_39;
}
return 0 ;
V_39:
F_27 ( F_6 ( 12 ) ) ;
V_38:
F_28 ( V_34 ) ;
return V_12 ;
}
static void T_2 F_29 ( void )
{
F_27 ( F_6 ( 12 ) ) ;
F_28 ( V_34 ) ;
}
