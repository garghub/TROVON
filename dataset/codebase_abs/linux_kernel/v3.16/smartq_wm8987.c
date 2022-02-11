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
V_12 = F_3 ( V_9 , V_13 |
V_14 |
V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_10 , V_13 |
V_14 |
V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_10 , V_16 ,
0 , V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_10 , V_18 ,
0 , V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_9 , V_19 , V_11 ,
V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_5 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
int V_24 )
{
F_6 ( F_7 ( 12 ) , F_8 ( V_24 ) ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = V_6 -> V_26 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
int V_29 = 0 ;
F_10 ( V_28 , L_1 ) ;
F_10 ( V_28 , L_2 ) ;
F_10 ( V_28 , L_3 ) ;
F_10 ( V_28 , L_4 ) ;
F_11 ( V_28 , L_5 ) ;
V_29 = F_12 ( V_26 , L_5 ,
V_30 , & V_31 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_13 ( & V_31 , F_14 ( V_32 ) ,
V_32 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_15 ( & V_31 ,
F_14 ( V_33 ) ,
V_33 ) ;
return V_29 ;
}
static int F_16 ( struct V_34 * V_35 )
{
F_17 ( & V_31 , F_14 ( V_33 ) ,
V_33 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
int V_12 ;
if ( ! F_19 () && ! F_20 () ) {
F_21 ( L_6 ) ;
return - V_36 ;
}
V_37 = F_22 ( L_7 , - 1 ) ;
if ( ! V_37 )
return - V_38 ;
F_23 ( V_37 , & V_39 ) ;
V_12 = F_24 ( V_37 ) ;
if ( V_12 ) {
F_25 ( V_37 ) ;
return V_12 ;
}
V_12 = F_26 ( F_7 ( 12 ) , L_8 ) ;
if ( V_12 ) {
F_27 ( & V_37 -> V_40 , L_9 ) ;
goto V_41;
}
V_12 = F_28 ( F_7 ( 12 ) , 1 ) ;
if ( V_12 ) {
F_27 ( & V_37 -> V_40 , L_10 ) ;
goto V_42;
}
return 0 ;
V_42:
F_29 ( F_7 ( 12 ) ) ;
V_41:
F_30 ( V_37 ) ;
return V_12 ;
}
static void T_2 F_31 ( void )
{
F_29 ( F_7 ( 12 ) ) ;
F_30 ( V_37 ) ;
}
