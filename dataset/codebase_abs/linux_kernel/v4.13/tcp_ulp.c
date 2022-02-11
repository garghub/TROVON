static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (e, &tcp_ulp_list, list) {
if ( strcmp ( V_3 -> V_2 , V_2 ) == 0 )
return V_3 ;
}
return NULL ;
}
static const struct V_1 * F_3 ( const char * V_2 )
{
const struct V_1 * V_4 = NULL ;
F_4 () ;
V_4 = F_1 ( V_2 ) ;
#ifdef F_5
if ( ! V_4 && F_6 ( V_5 ) ) {
F_7 () ;
F_8 ( L_1 , V_2 ) ;
F_4 () ;
V_4 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_4 || ! F_9 ( V_4 -> V_6 ) )
V_4 = NULL ;
F_7 () ;
return V_4 ;
}
int F_10 ( struct V_1 * V_4 )
{
int V_7 = 0 ;
F_11 ( & V_8 ) ;
if ( F_1 ( V_4 -> V_2 ) ) {
F_12 ( L_2 ,
V_4 -> V_2 ) ;
V_7 = - V_9 ;
} else {
F_13 ( & V_4 -> V_10 , & V_11 ) ;
}
F_14 ( & V_8 ) ;
return V_7 ;
}
void F_15 ( struct V_1 * V_4 )
{
F_11 ( & V_8 ) ;
F_16 ( & V_4 -> V_10 ) ;
F_14 ( & V_8 ) ;
F_17 () ;
}
void F_18 ( char * V_12 , T_1 V_13 )
{
struct V_1 * V_14 ;
T_1 V_15 = 0 ;
* V_12 = '\0' ;
F_4 () ;
F_2 (ulp_ops, &tcp_ulp_list, list) {
V_15 += snprintf ( V_12 + V_15 , V_13 - V_15 ,
L_3 ,
V_15 == 0 ? L_4 : L_5 , V_14 -> V_2 ) ;
}
F_7 () ;
}
void F_19 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_20 ( V_17 ) ;
if ( ! V_19 -> V_20 )
return;
if ( V_19 -> V_20 -> V_21 )
V_19 -> V_20 -> V_21 ( V_17 ) ;
F_21 ( V_19 -> V_20 -> V_6 ) ;
}
int F_22 ( struct V_16 * V_17 , const char * V_2 )
{
struct V_18 * V_19 = F_20 ( V_17 ) ;
const struct V_1 * V_14 ;
int V_22 = 0 ;
if ( V_19 -> V_20 )
return - V_9 ;
V_14 = F_3 ( V_2 ) ;
if ( ! V_14 )
return - V_23 ;
V_22 = V_14 -> V_24 ( V_17 ) ;
if ( V_22 ) {
F_21 ( V_14 -> V_6 ) ;
return V_22 ;
}
V_19 -> V_20 = V_14 ;
return 0 ;
}
