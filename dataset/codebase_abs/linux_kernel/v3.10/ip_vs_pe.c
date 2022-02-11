struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 ( 10 , L_1 , V_4 ,
V_2 ) ;
F_3 () ;
F_4 (pe, &ip_vs_pe, n_list) {
if ( V_3 -> V_5 &&
! F_5 ( V_3 -> V_5 ) ) {
continue;
}
if ( strcmp ( V_2 , V_3 -> V_6 ) == 0 ) {
F_6 () ;
return V_3 ;
}
if ( V_3 -> V_5 )
F_7 ( V_3 -> V_5 ) ;
}
F_6 () ;
return NULL ;
}
struct V_1 * F_8 ( const char * V_6 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_6 ) ;
if ( ! V_3 ) {
F_9 ( L_2 , V_6 ) ;
V_3 = F_1 ( V_6 ) ;
}
return V_3 ;
}
int F_10 ( struct V_1 * V_3 )
{
struct V_1 * V_7 ;
F_11 () ;
F_12 ( & V_8 ) ;
F_13 (tmp, &ip_vs_pe, n_list) {
if ( strcmp ( V_7 -> V_6 , V_3 -> V_6 ) == 0 ) {
F_14 ( & V_8 ) ;
F_15 () ;
F_16 ( L_3
L_4 , V_4 , V_3 -> V_6 ) ;
return - V_9 ;
}
}
F_17 ( & V_3 -> V_10 , & V_1 ) ;
F_14 ( & V_8 ) ;
F_18 ( L_5 , V_3 -> V_6 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_3 )
{
F_12 ( & V_8 ) ;
F_20 ( & V_3 -> V_10 ) ;
F_14 ( & V_8 ) ;
F_15 () ;
F_18 ( L_6 , V_3 -> V_6 ) ;
return 0 ;
}
