static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 = 0 ;
int V_12 = 0 ;
F_2 ( L_1 , V_13 , F_3 ( V_4 ) ,
F_4 ( V_4 ) ) ;
switch ( F_3 ( V_4 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
case 11025 :
case 22050 :
case 44100 :
V_11 = 12000000 ;
break;
}
V_12 = F_5 ( V_9 , V_14 |
V_15 | V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_10 , V_14 |
V_15 | V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_9 , V_17 , V_11 ,
V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int T_1 F_7 ( void )
{
int V_12 ;
F_2 ( L_2 , V_13 ) ;
V_19 = F_8 ( L_3 , - 1 ) ;
if ( ! V_19 )
return - V_20 ;
F_9 ( V_19 , & V_21 ) ;
V_12 = F_10 ( V_19 ) ;
if ( V_12 )
F_11 ( V_19 ) ;
return V_12 ;
}
static void T_2 F_12 ( void )
{
F_2 ( L_2 , V_13 ) ;
F_13 ( V_19 ) ;
}
