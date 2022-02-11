static int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
F_2 ( & V_5 ) ;
if ( V_6 -> V_7 == 0 ) {
V_6 -> V_8 = F_3 ( V_2 ) ;
if ( V_6 -> V_8 == NULL ) {
V_3 = - V_9 ;
} else {
V_6 -> V_7 = 1 ;
V_2 -> V_10 = V_6 ;
V_2 -> V_11 = V_12 ;
F_4 ( V_2 ) ;
V_3 = 0 ;
}
}
F_5 ( & V_5 ) ;
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_10 ;
F_2 ( & V_5 ) ;
F_7 ( V_14 -> V_8 != V_6 -> V_8 ) ;
F_4 ( V_2 ) ;
F_8 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
V_6 -> V_7 = 0 ;
V_2 -> V_10 = NULL ;
F_5 ( & V_5 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned char T_2 * V_16 , T_3 V_17 ) {
return - V_18 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_15 * V_15 ,
const unsigned char * V_16 , T_3 V_17 ) {
return - V_18 ;
}
static void F_11 ( struct V_1 * V_2 ,
const unsigned char * V_19 ,
char * V_20 , int V_21 )
{
F_2 ( & V_5 ) ;
F_12 ( ( V_22 * ) V_19 , V_21 ) ;
F_5 ( & V_5 ) ;
}
static int T_4 F_13 ( void )
{
int V_3 ;
V_6 = F_14 ( sizeof( struct V_13 ) , V_23 ) ;
if ( V_6 == NULL )
return - V_24 ;
V_3 = F_15 ( V_25 , & V_26 ) ;
if ( V_3 < 0 ) {
F_16 ( L_1 , V_27 , V_3 ) ;
F_17 ( V_6 ) ;
}
return V_3 ;
}
static void T_5 F_18 ( void )
{
int V_3 = F_19 ( V_25 ) ;
if ( V_3 < 0 )
F_16 ( L_2 , V_27 , V_3 ) ;
else
F_17 ( V_6 ) ;
}
