static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
if ( V_2 < 0 )
return NULL ;
F_2 (module, &modules_list, list) {
if ( V_3 -> V_2 == V_2 )
return V_3 ;
}
return NULL ;
}
int F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_3 ;
int V_2 ;
int V_6 ;
V_2 = F_4 ( & V_7 , 0 , 0 , V_8 ) ;
V_6 = F_5 ( & V_3 , V_9 ,
V_2 , V_5 ) ;
if ( V_6 ) {
F_6 ( & V_7 , V_2 ) ;
return V_6 ;
}
F_7 ( & V_10 ) ;
F_8 ( & V_3 -> V_11 , & V_12 ) ;
F_9 ( & V_10 ) ;
return V_3 -> V_2 ;
}
int F_10 ( int V_2 )
{
struct V_1 * V_3 ;
F_7 ( & V_10 ) ;
V_3 = F_1 ( V_2 ) ;
if ( ! V_3 ) {
F_9 ( & V_10 ) ;
return - V_13 ;
}
F_11 ( & V_3 -> V_11 ) ;
F_12 ( & V_3 -> V_14 ) ;
F_9 ( & V_10 ) ;
F_6 ( & V_7 , V_2 ) ;
return 0 ;
}
void F_13 ( void )
{
struct V_1 * V_3 , * V_15 ;
int V_16 = 1 ;
F_7 ( & V_10 ) ;
F_14 (module, next, &modules_list, list) {
F_11 ( & V_3 -> V_11 ) ;
F_12 ( & V_3 -> V_14 ) ;
F_6 ( & V_7 , V_3 -> V_2 ) ;
}
V_16 = F_15 ( & V_12 ) ;
F_9 ( & V_10 ) ;
if ( ! V_16 )
F_16 ( L_1 ) ;
}
struct V_1 * F_17 ( int V_2 )
{
struct V_1 * V_3 ;
F_18 ( & V_10 ) ;
V_3 = F_1 ( V_2 ) ;
F_19 ( & V_3 -> V_14 ) ;
F_20 ( & V_10 ) ;
return V_3 ;
}
void F_21 ( struct V_1 * V_3 )
{
F_12 ( & V_3 -> V_14 ) ;
}
int F_22 ( int V_2 )
{
struct V_1 * V_3 ;
F_18 ( & V_10 ) ;
V_3 = F_1 ( V_2 ) ;
F_20 ( & V_10 ) ;
if ( ! V_3 )
return - V_13 ;
F_23 ( V_3 ) ;
return 0 ;
}
void F_24 ( void )
{
struct V_1 * V_3 ;
int V_17 = 0 ;
F_18 ( & V_10 ) ;
F_2 (module, &modules_list, list) {
F_23 ( V_3 ) ;
V_17 ++ ;
}
F_20 ( & V_10 ) ;
F_25 ( L_2 , V_17 ) ;
}
static int T_1 F_26 ( void )
{
V_9 = F_27 ( V_18 , NULL ,
V_19 ) ;
if ( ! V_9 )
return - V_20 ;
#ifdef F_28
F_29 ( & V_9 -> V_14 ) ;
#endif
return 0 ;
}
static void T_2 F_30 ( void )
{
F_13 () ;
F_31 ( V_9 ) ;
F_32 ( & V_7 ) ;
}
