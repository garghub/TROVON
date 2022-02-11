static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
} ;
F_2 ( V_2 , F_3 ( V_5 ) ,
V_6 , & V_4 ) ;
}
void T_1 F_4 ( void )
{
F_5 ( V_7 , F_6 ( V_7 ) ) ;
F_7 () ;
F_5 ( V_8 , F_6 ( V_8 ) ) ;
V_9 = F_8 ( V_10 ) ;
}
static void T_1 F_9 ( void )
{
struct V_11 V_12 [] = {
[ 0 ] = {
. V_13 = V_14 ,
. V_15 = V_14 ,
. V_16 = V_17 ,
} ,
[ 1 ] = {
. V_13 = V_18 ,
. V_15 = V_18 ,
. V_16 = V_17 ,
} ,
} ;
F_10 ( L_1 , V_19 ,
V_12 , F_6 ( V_12 ) ) ;
}
static const char * F_11 ( void )
{
return F_12 ( V_20 , L_2 ) ;
}
static struct V_1 * T_1 F_13 ( void )
{
const char * V_21 = F_11 () ;
return F_14 ( V_21 ) ;
}
struct V_1 * T_1 F_15 ( void )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_13 () ;
F_1 ( V_2 ) ;
F_9 () ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 , V_23 , V_24 ) ;
for ( V_22 = 0 ; V_22 < F_6 ( V_25 ) ; V_22 ++ )
V_25 [ V_22 ] -> V_26 . V_2 = V_2 ;
F_19 ( V_25 ,
F_6 ( V_25 ) ) ;
return V_2 ;
}
