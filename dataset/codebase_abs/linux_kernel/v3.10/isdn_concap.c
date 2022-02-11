static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 * V_8 = ( ( V_9 * ) F_2 ( V_6 ) ) -> V_10 ;
V_9 * V_11 = F_3 ( V_8 ) ;
F_4 ( L_1 , V_2 -> V_7 -> V_12 ) ;
if ( ! V_11 ) {
F_4 ( L_2 , V_2 -> V_7 -> V_12 , 1 ) ;
return 1 ;
}
V_11 -> V_13 = 0 ;
F_5 ( V_11 , V_4 ) ;
F_6 ( & V_11 -> V_14 ) ;
F_4 ( L_2 , V_2 -> V_7 -> V_12 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_9 * V_11 = F_2 ( V_6 ) ;
int V_15 ;
F_4 ( L_3 , V_6 -> V_12 ) ;
V_15 = F_8 ( V_11 ) ;
if ( V_15 ) F_4 ( L_4 ) ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_4 ( L_5 , V_2 -> V_7 -> V_12 ) ;
F_10 ( V_2 -> V_7 ) ;
return 0 ;
}
struct V_1 * F_11 ( int V_16 )
{
switch ( V_16 ) {
case V_17 :
return F_12 () ;
}
return NULL ;
}
