void F_1 ( void )
{
#include "packet-novell_pkis-dis-tab.c"
}
void F_2 ( void )
{
static T_1 V_1 [] = {
#include "packet-novell_pkis-hfarr.c"
} ;
static T_2 * V_2 [] = {
#include "packet-novell_pkis-ettarr.c"
} ;
if ( V_3 != - 1 ) return;
V_3 = F_3 ( L_1 , L_2 , L_2 ) ;
F_4 ( V_3 , V_1 , F_5 ( V_1 ) ) ;
F_6 ( V_2 , F_5 ( V_2 ) ) ;
}
