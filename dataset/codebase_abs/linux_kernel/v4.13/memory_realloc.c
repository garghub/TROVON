bool F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_2 V_3 ,
bool V_4 ,
enum V_5 * V_6 )
{
bool V_7 ;
T_3 V_8 = V_9 ;
F_2 ( L_1 ) ;
V_7 = F_3 ( V_1 ,
V_2 , V_3 , V_4 , V_6 , V_8 ) ;
F_4 ( L_2 , V_7 ) ;
return V_7 ;
}
static bool F_3 (
T_1 * V_1 ,
T_2 * V_2 ,
T_2 V_3 ,
bool V_4 ,
enum V_5 * V_6 ,
T_3 V_8 )
{
T_4 V_10 ;
* V_6 = V_11 ;
F_2 ( L_1 ) ;
if ( F_5 ( * V_1 ) && ! V_4 && * V_2 >= V_3 ) {
F_4 ( L_3 ) ;
return false ;
}
V_10 = V_12 ;
F_6 ( V_10 , * V_1 ) ;
* V_1 = F_7 ( V_10 , F_8 ( V_3 ,
V_8 ) ) ;
if ( ! * V_1 ) {
* V_6 = V_13 ;
* V_2 = 0 ;
} else {
* V_2 = V_3 ;
}
F_4 ( L_4 ) ;
return true ;
}
