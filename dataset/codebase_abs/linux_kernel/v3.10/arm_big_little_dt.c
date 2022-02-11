static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = NULL , * V_4 ;
int V_5 = 0 ;
V_4 = F_2 ( L_1 ) ;
if ( ! V_4 ) {
F_3 ( L_2 ) ;
return NULL ;
}
F_4 (parent, np) {
if ( V_5 ++ != V_2 )
continue;
if ( ! F_5 ( V_3 , L_3 , NULL ) ) {
F_6 ( V_3 ) ;
V_3 = NULL ;
}
break;
}
F_6 ( V_4 ) ;
return V_3 ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_3 ;
int V_8 ;
V_3 = F_1 ( V_7 -> V_9 ) ;
if ( ! V_3 )
return - V_10 ;
V_7 -> V_11 = V_3 ;
V_8 = F_8 ( V_7 ) ;
F_6 ( V_3 ) ;
return V_8 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_3 ;
T_1 V_12 = V_13 ;
V_3 = F_1 ( V_7 -> V_9 ) ;
if ( ! V_3 )
return V_13 ;
F_10 ( V_3 , L_4 , & V_12 ) ;
F_6 ( V_3 ) ;
F_11 ( L_5 , V_14 , V_12 ) ;
return V_12 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( 0 ) ;
if ( ! V_3 )
return - V_17 ;
F_6 ( V_3 ) ;
return F_13 ( & V_18 ) ;
}
static int F_14 ( struct V_15 * V_16 )
{
F_15 ( & V_18 ) ;
return 0 ;
}
