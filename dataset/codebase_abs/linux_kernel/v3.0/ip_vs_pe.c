void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 = V_4 ;
}
void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_4 = NULL ;
}
struct V_3 * F_3 ( const char * V_5 )
{
struct V_3 * V_4 ;
F_4 ( 10 , L_1 , V_6 ,
V_5 ) ;
F_5 ( & V_7 ) ;
F_6 (pe, &ip_vs_pe, n_list) {
if ( V_4 -> V_8 &&
! F_7 ( V_4 -> V_8 ) ) {
continue;
}
if ( strcmp ( V_5 , V_4 -> V_9 ) == 0 ) {
F_8 ( & V_7 ) ;
return V_4 ;
}
if ( V_4 -> V_8 )
F_9 ( V_4 -> V_8 ) ;
}
F_8 ( & V_7 ) ;
return NULL ;
}
struct V_3 * F_10 ( const char * V_9 )
{
struct V_3 * V_4 ;
V_4 = F_3 ( V_9 ) ;
if ( ! V_4 ) {
F_11 ( L_2 , V_9 ) ;
V_4 = F_3 ( V_9 ) ;
}
return V_4 ;
}
int F_12 ( struct V_3 * V_4 )
{
struct V_3 * V_10 ;
F_13 () ;
F_5 ( & V_7 ) ;
if ( ! F_14 ( & V_4 -> V_11 ) ) {
F_8 ( & V_7 ) ;
F_15 () ;
F_16 ( L_3 ,
V_6 , V_4 -> V_9 ) ;
return - V_12 ;
}
F_6 (tmp, &ip_vs_pe, n_list) {
if ( strcmp ( V_10 -> V_9 , V_4 -> V_9 ) == 0 ) {
F_8 ( & V_7 ) ;
F_15 () ;
F_16 ( L_4
L_5 , V_6 , V_4 -> V_9 ) ;
return - V_12 ;
}
}
F_17 ( & V_4 -> V_11 , & V_3 ) ;
F_8 ( & V_7 ) ;
F_18 ( L_6 , V_4 -> V_9 ) ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 )
{
F_5 ( & V_7 ) ;
if ( F_14 ( & V_4 -> V_11 ) ) {
F_8 ( & V_7 ) ;
F_16 ( L_7 ,
V_6 , V_4 -> V_9 ) ;
return - V_12 ;
}
F_20 ( & V_4 -> V_11 ) ;
F_8 ( & V_7 ) ;
F_15 () ;
F_18 ( L_8 , V_4 -> V_9 ) ;
return 0 ;
}
