static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 div ;
unsigned int V_12 = 0 ;
int V_13 = 0 ;
switch ( F_2 ( V_4 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
V_12 = 12288000 ;
break;
case 11025 :
case 22050 :
case 44100 :
V_12 = 11289600 ;
break;
}
F_3 ( & div , NULL , F_2 ( V_4 ) ,
F_4 ( V_10 ) ) ;
V_13 = F_5 ( V_9 , V_14 |
V_15 |
V_16 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_10 , V_14 |
V_15 |
V_16 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_9 , V_17 , V_12 ,
V_18 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_10 , V_19 , div . V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_7 ( V_10 , V_21 ,
div . V_22 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_23 * V_24 = V_6 -> V_24 ;
struct V_25 * V_26 = & V_24 -> V_26 ;
int V_27 ;
F_9 ( V_26 , L_1 ) ;
F_9 ( V_26 , L_2 ) ;
F_9 ( V_26 , L_3 ) ;
F_9 ( V_26 , L_4 ) ;
F_9 ( V_26 , L_5 ) ;
F_9 ( V_26 , L_6 ) ;
V_27 = F_10 ( V_26 , V_28 ,
F_11 ( V_28 ) ) ;
if ( V_27 ) {
F_12 ( V_29 L_7 ,
V_30 , V_27 ) ;
return V_27 ;
}
F_13 ( V_26 , V_31 , F_11 ( V_31 ) ) ;
F_14 ( V_26 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
int V_13 ;
if ( ! F_16 () )
return 0 ;
F_12 ( L_8 ) ;
V_32 = F_17 ( L_9 , - 1 ) ;
if ( ! V_32 )
return - V_33 ;
F_18 ( V_32 , & V_34 ) ;
V_13 = F_19 ( V_32 ) ;
if ( V_13 )
F_20 ( V_32 ) ;
return V_13 ;
}
static void T_2 F_21 ( void )
{
F_22 ( V_32 ) ;
}
