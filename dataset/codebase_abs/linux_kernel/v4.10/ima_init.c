static int T_1 F_1 ( void )
{
static const char V_1 [] = L_1 ;
const char * V_2 = L_2 ;
struct V_3 * V_4 ;
struct V_5 V_6 , * V_7 = & V_6 ;
struct V_8 V_9 = { V_7 , NULL , V_10 ,
NULL , 0 , NULL } ;
int V_11 = - V_12 ;
int V_13 = 0 ;
struct {
struct V_14 V_15 ;
char V_16 [ V_17 ] ;
} V_18 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_7 -> V_19 = & V_18 . V_15 ;
V_7 -> V_19 -> V_20 = V_21 ;
V_7 -> V_19 -> V_22 = V_23 ;
if ( V_24 ) {
V_11 = F_2 ( & V_18 . V_15 ) ;
if ( V_11 < 0 ) {
V_2 = L_3 ;
goto V_25;
}
}
V_11 = F_3 ( & V_9 , & V_4 ) ;
if ( V_11 < 0 ) {
V_2 = L_4 ;
goto V_25;
}
V_11 = F_4 ( V_4 , V_13 , NULL ,
V_10 ,
V_26 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 ) ;
V_2 = L_5 ;
goto V_25;
}
return 0 ;
V_25:
F_6 ( V_27 , NULL , V_10 , V_1 ,
V_2 , V_11 , 0 ) ;
return V_11 ;
}
void T_1 F_7 ( void )
{
int V_28 = V_29 & V_30 ;
V_29 &= ~ V_28 ;
F_8 ( V_31 , V_32 ) ;
V_29 |= V_28 ;
}
int T_1 F_9 ( void )
{
T_2 V_33 [ V_17 ] ;
int V_34 ;
V_24 = 0 ;
V_34 = F_10 ( V_35 , 0 , V_33 ) ;
if ( V_34 == 0 )
V_24 = 1 ;
if ( ! V_24 )
F_11 ( L_6 ,
V_34 ) ;
V_34 = F_12 ( V_31 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_13 () ;
if ( V_34 )
return V_34 ;
V_34 = F_14 () ;
if ( V_34 != 0 )
return V_34 ;
F_15 () ;
V_34 = F_1 () ;
if ( V_34 != 0 )
return V_34 ;
F_16 () ;
return F_17 () ;
}
