static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
int V_4 ;
T_1 V_5 ;
V_4 = F_2 ( V_6 , V_7 , 1 ) ;
if ( V_4 ) {
F_3 ( L_1 , V_4 ) ;
return;
}
V_4 = F_4 ( V_6 , V_7 , & V_5 ) ;
if ( V_4 ) {
F_3 ( L_2 , V_4 ) ;
return;
}
V_4 = F_2 ( V_6 , V_8 , 1 ) ;
if ( V_4 ) {
F_3 ( L_3 , V_4 ) ;
return;
}
V_4 = F_4 ( V_6 , V_8 , & V_5 ) ;
if ( V_4 ) {
F_3 ( L_4 , V_4 ) ;
return;
}
while ( 1 )
;
}
static int F_5 ( struct V_9 * V_10 )
{
int V_4 ;
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
V_6 = F_6 ( V_12 , L_5 ) ;
if ( F_7 ( V_6 ) ) {
F_3 ( L_6 ) ;
return - V_15 ;
}
V_4 = F_8 ( V_12 , L_5 , V_16 ,
& V_7 ) ;
if ( V_4 ) {
F_3 ( L_7 , V_4 ) ;
return - V_15 ;
}
V_4 = F_8 ( V_12 , L_5 , V_17 ,
& V_8 ) ;
if ( V_4 ) {
F_3 ( L_8 , V_4 ) ;
return - V_15 ;
}
V_18 = F_1 ;
return 0 ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_19 ,
F_5 ) ;
}
