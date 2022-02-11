static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 = 0 ;
int V_11 = 0 ;
F_2 ( L_1 , V_12 , F_3 ( V_4 ) ,
F_4 ( V_4 ) ) ;
switch ( F_3 ( V_4 ) ) {
case 8000 :
case 16000 :
case 48000 :
case 96000 :
case 11025 :
case 22050 :
case 44100 :
V_10 = 12000000 ;
break;
}
V_11 = F_5 ( V_9 , V_13 , V_10 ,
V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_11 ;
F_2 ( L_2 , V_12 ) ;
V_15 = F_7 ( L_3 , - 1 ) ;
if ( ! V_15 )
return - V_16 ;
F_8 ( V_15 , & V_17 ) ;
V_11 = F_9 ( V_15 ) ;
if ( V_11 )
F_10 ( V_15 ) ;
return V_11 ;
}
static void T_2 F_11 ( void )
{
F_2 ( L_2 , V_12 ) ;
F_12 ( V_15 ) ;
}
