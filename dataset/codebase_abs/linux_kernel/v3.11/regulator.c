void F_1 ( void )
{
T_1 V_1 , V_2 ;
F_2 ( & V_2 ) ;
if ( ! F_3 ( V_3 , & V_2 , & V_1 ) ) {
if ( V_4 )
F_4 ( V_4 ) ;
else
F_5 ( L_1 ) ;
( void ) F_3 ( V_5 , & V_1 , NULL ) ;
}
return;
}
static int T_2 F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 . V_11 ;
struct V_8 * V_12 ;
struct V_13 * V_13 ;
int V_14 ;
F_7 ( L_2 ) ;
V_12 = F_8 ( V_9 , L_3 , 0 ) ;
if ( ! V_12 ) {
F_9 ( L_4 ) ;
return - V_15 ;
}
V_13 = F_10 ( V_12 ) ;
if ( ! V_13 ) {
F_9 ( L_5 ) ;
return - V_15 ;
}
V_4 = F_11 ( & V_7 -> V_10 , L_6 ) ;
if ( F_12 ( V_4 ) ) {
F_5 ( L_7 ) ;
return F_13 ( V_4 ) ;
}
V_14 = F_14 ( V_4 ) ;
if ( V_14 ) {
F_5 ( L_8 ) ;
return V_14 ;
}
F_7 ( L_9 ) ;
F_15 ( V_13 , V_16 ,
V_17 , 0 ) ;
V_18 = F_1 ;
return 0 ;
}
static int T_2 F_16 ( struct V_6 * V_7 )
{
return F_6 ( V_7 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_19 ,
F_16 ) ;
}
