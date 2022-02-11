static unsigned int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
unsigned int V_5 ,
unsigned int V_6 ,
unsigned int V_7 ,
struct V_8 * exp )
{
char V_9 [ sizeof( L_1 ) ] ;
T_1 V_10 ;
unsigned int V_11 ;
exp -> V_12 . V_13 . V_10 = exp -> V_14 . V_15 . V_16 . V_13 . V_10 ;
exp -> V_17 = V_18 ;
exp -> V_19 = V_20 ;
for ( V_10 = F_2 ( exp -> V_12 . V_13 . V_10 ) ; V_10 != 0 ; V_10 ++ ) {
int V_21 ;
exp -> V_14 . V_15 . V_16 . V_13 . V_10 = F_3 ( V_10 ) ;
V_21 = F_4 ( exp ) ;
if ( V_21 == 0 )
break;
else if ( V_21 != - V_22 ) {
V_10 = 0 ;
break;
}
}
if ( V_10 == 0 ) {
F_5 ( V_2 , exp -> V_23 , L_2 ) ;
return V_24 ;
}
sprintf ( V_9 , L_3 , V_10 ) ;
V_11 = F_6 ( V_2 , exp -> V_23 , V_4 ,
V_5 , V_6 , V_7 ,
V_9 , strlen ( V_9 ) ) ;
if ( V_11 != V_25 ) {
F_5 ( V_2 , exp -> V_23 , L_4 ) ;
F_7 ( exp ) ;
}
return V_11 ;
}
static void T_2 F_8 ( void )
{
F_9 ( V_26 , NULL ) ;
F_10 () ;
}
static int T_3 F_11 ( void )
{
F_12 ( V_26 != NULL ) ;
F_9 ( V_26 , F_1 ) ;
return 0 ;
}
