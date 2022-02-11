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
V_13 = F_5 ( V_9 , V_14 , V_12 ,
V_15 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_10 , V_16 , div . V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_6 ( V_10 , V_18 ,
div . V_19 - 1 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int T_1 F_7 ( void )
{
int V_13 ;
if ( ! F_8 () )
return 0 ;
F_9 ( L_1 ) ;
V_20 = F_10 ( L_2 , - 1 ) ;
if ( ! V_20 )
return - V_21 ;
F_11 ( V_20 , & V_22 ) ;
V_13 = F_12 ( V_20 ) ;
if ( V_13 )
F_13 ( V_20 ) ;
return V_13 ;
}
static void T_2 F_14 ( void )
{
F_15 ( V_20 ) ;
}
