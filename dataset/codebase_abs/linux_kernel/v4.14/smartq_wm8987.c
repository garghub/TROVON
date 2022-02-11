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
struct V_22 * V_23 = F_5 ( & V_24 ) ;
F_6 ( V_23 , F_7 ( V_21 ) ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = & V_6 -> V_27 -> V_26 ;
int V_28 = 0 ;
F_9 ( V_26 , L_1 ) ;
F_9 ( V_26 , L_2 ) ;
F_9 ( V_26 , L_3 ) ;
F_9 ( V_26 , L_4 ) ;
V_28 = F_10 ( V_6 -> V_27 , L_5 ,
V_29 , & V_30 ,
V_31 ,
F_11 ( V_31 ) ) ;
if ( V_28 )
return V_28 ;
V_28 = F_12 ( & V_30 ,
F_11 ( V_32 ) ,
V_32 ) ;
return V_28 ;
}
static int F_13 ( struct V_33 * V_34 )
{
struct V_22 * V_23 ;
int V_12 ;
F_14 ( V_34 , & V_24 ) ;
V_23 = F_15 ( & V_34 -> V_35 , L_6 ,
V_36 ) ;
if ( F_16 ( V_23 ) ) {
F_17 ( & V_34 -> V_35 , L_7 ) ;
V_12 = F_18 ( V_23 ) ;
goto V_37;
}
F_19 ( & V_24 , V_23 ) ;
V_12 = F_20 ( & V_34 -> V_35 , & V_24 ) ;
if ( V_12 )
F_17 ( & V_34 -> V_35 , L_8 ) ;
V_37:
return V_12 ;
}
