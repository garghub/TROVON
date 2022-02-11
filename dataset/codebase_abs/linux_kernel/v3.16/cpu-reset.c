int F_1 ( int V_1 )
{
T_1 V_2 ;
if ( ! V_3 )
return - V_4 ;
if ( F_2 ( V_1 ) >= V_5 )
return - V_6 ;
V_2 = F_3 ( V_3 + F_2 ( V_1 ) ) ;
V_2 &= ~ V_7 ;
F_4 ( V_2 , V_3 + F_2 ( V_1 ) ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 V_12 ;
if ( F_6 ( V_9 , V_10 , & V_12 ) ) {
F_7 ( L_1 ) ;
return - V_13 ;
}
if ( ! F_8 ( V_12 . V_14 , F_9 ( & V_12 ) ,
V_9 -> V_15 ) ) {
F_7 ( L_2 ) ;
return - V_16 ;
}
V_3 = F_10 ( V_12 . V_14 , F_9 ( & V_12 ) ) ;
if ( ! V_3 ) {
F_7 ( L_3 ) ;
F_11 ( V_12 . V_14 , F_9 ( & V_12 ) ) ;
return - V_17 ;
}
V_5 = F_9 ( & V_12 ) ;
return 0 ;
}
int T_2 F_12 ( void )
{
struct V_8 * V_9 ;
int V_10 ;
int V_18 ;
V_9 = F_13 ( NULL , NULL ,
L_4 ) ;
if ( V_9 ) {
V_10 = 0 ;
} else {
V_9 = F_13 ( NULL , NULL ,
L_5 ) ;
if ( V_9 ) {
F_14 ( V_19 L_6 ) ;
V_10 = 1 ;
}
}
if ( ! V_9 )
return - V_4 ;
V_18 = F_5 ( V_9 , V_10 ) ;
F_15 ( V_9 ) ;
return V_18 ;
}
