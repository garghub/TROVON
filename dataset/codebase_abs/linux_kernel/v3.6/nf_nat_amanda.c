static unsigned int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
unsigned int V_5 ,
unsigned int V_6 ,
struct V_7 * exp )
{
char V_8 [ sizeof( L_1 ) ] ;
T_1 V_9 ;
unsigned int V_10 ;
exp -> V_11 . V_12 . V_9 = exp -> V_13 . V_14 . V_15 . V_12 . V_9 ;
exp -> V_16 = V_17 ;
exp -> V_18 = V_19 ;
for ( V_9 = F_2 ( exp -> V_11 . V_12 . V_9 ) ; V_9 != 0 ; V_9 ++ ) {
int V_20 ;
exp -> V_13 . V_14 . V_15 . V_12 . V_9 = F_3 ( V_9 ) ;
V_20 = F_4 ( exp ) ;
if ( V_20 == 0 )
break;
else if ( V_20 != - V_21 ) {
V_9 = 0 ;
break;
}
}
if ( V_9 == 0 )
return V_22 ;
sprintf ( V_8 , L_2 , V_9 ) ;
V_10 = F_5 ( V_2 , exp -> V_23 , V_4 ,
V_5 , V_6 ,
V_8 , strlen ( V_8 ) ) ;
if ( V_10 != V_24 )
F_6 ( exp ) ;
return V_10 ;
}
static void T_2 F_7 ( void )
{
F_8 ( V_25 , NULL ) ;
F_9 () ;
}
static int T_3 F_10 ( void )
{
F_11 ( V_25 != NULL ) ;
F_8 ( V_25 , F_1 ) ;
return 0 ;
}
