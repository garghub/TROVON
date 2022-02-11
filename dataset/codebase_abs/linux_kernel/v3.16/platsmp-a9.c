void F_1 ( void )
{
void T_1 * V_1 ;
F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_5 ,
V_6 , V_7 ) ;
V_1 = F_4 ( V_6 , V_7 ) ;
memcpy ( V_1 , & V_8 ,
& V_9
- & V_8 ) ;
}
static int T_2 F_5 ( unsigned int V_10 ,
struct V_11 * V_12 )
{
int V_13 , V_14 ;
F_6 ( L_1 , V_10 ) ;
V_14 = F_7 ( V_10 ) ;
if ( F_8 ( L_2 ) ) {
T_3 V_15 , V_16 ;
if ( F_9 ( & V_15 , & V_16 ) == 0 &&
V_16 == V_17 )
F_1 () ;
F_10 ( V_18 ) ;
}
else {
F_11 ( V_14 ,
V_18 ) ;
}
F_12 () ;
V_13 = F_13 ( V_14 ) ;
if ( V_13 ) {
F_14 ( L_3 , V_13 ) ;
return V_13 ;
}
F_15 ( F_16 ( V_10 ) ) ;
return 0 ;
}
