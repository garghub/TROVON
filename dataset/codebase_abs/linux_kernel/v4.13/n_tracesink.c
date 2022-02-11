static int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
F_2 ( & V_5 ) ;
if ( V_6 == NULL ) {
V_6 = F_3 ( V_2 ) ;
if ( V_6 == NULL ) {
V_3 = - V_7 ;
} else {
V_2 -> V_8 = V_6 ;
F_4 ( V_2 ) ;
V_3 = 0 ;
}
}
F_5 ( & V_5 ) ;
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( & V_5 ) ;
F_4 ( V_2 ) ;
F_7 ( V_6 ) ;
V_6 = NULL ;
V_2 -> V_8 = NULL ;
F_5 ( & V_5 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_9 * V_9 ,
unsigned char T_2 * V_10 , T_3 V_11 ) {
return - V_12 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_9 * V_9 ,
const unsigned char * V_10 , T_3 V_11 ) {
return - V_12 ;
}
void F_10 ( T_4 * V_10 , int V_13 )
{
F_2 ( & V_5 ) ;
if ( ( V_10 != NULL ) && ( V_13 > 0 ) && ( V_6 != NULL ) )
V_6 -> V_14 -> V_15 ( V_6 , V_10 , V_13 ) ;
F_5 ( & V_5 ) ;
}
static int T_5 F_11 ( void )
{
int V_3 = F_12 ( V_16 , & V_17 ) ;
if ( V_3 < 0 )
F_13 ( L_1 , V_18 , V_3 ) ;
return V_3 ;
}
static void T_6 F_14 ( void )
{
int V_3 = F_15 ( V_16 ) ;
if ( V_3 < 0 )
F_13 ( L_2 , V_18 , V_3 ) ;
}
