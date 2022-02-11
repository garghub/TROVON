static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
char * V_10 ;
T_1 V_11 ;
V_10 = F_2 ( V_12 , V_13 ) ;
if ( ! V_10 ) {
F_3 ( L_1 ) ;
return - V_14 ;
}
V_11 = F_4 ( V_7 , V_9 , & V_8 , V_10 ,
V_13 ) ;
F_5 ( V_10 ) ;
return V_11 ;
}
static void T_4 F_6 ( struct V_15 * V_16 )
{
F_7 ( L_2 , V_16 ) ;
F_7 ( L_3
L_4 ,
V_16 -> V_17 . V_18 , V_16 -> V_17 . V_19 ,
V_16 -> V_17 . V_20 , V_16 -> V_17 . V_21 ) ;
V_13 = V_16 -> V_17 . V_21 ;
V_12 = V_16 -> V_17 . V_18 ;
}
static void T_4 F_8 ( struct V_15 * V_16 )
{
F_7 ( L_5 , V_16 ) ;
F_7 ( L_3
L_6 ,
V_16 -> V_22 . V_18 , V_16 -> V_22 . V_19 ,
V_16 -> V_22 . V_20 , V_16 -> V_22 . V_23 ) ;
V_13 = V_16 -> V_22 . V_20 - V_16 -> V_22 . V_19 ;
V_12 = V_16 -> V_22 . V_18 + V_16 -> V_22 . V_19 ;
}
static bool T_4 F_9 ( void )
{
unsigned int V_24 ;
T_3 V_25 , V_26 ;
V_24 = F_10 () ;
if ( ! V_24 ) {
F_7 ( L_7 ) ;
return false ;
}
V_25 = * ( V_27 * ) F_11 ( V_24 ) ;
V_25 <<= 10 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
struct V_15 * V_16 = F_11 ( V_24 + V_26 ) ;
if ( V_16 -> V_28 == V_29 ) {
F_6 ( V_16 ) ;
return true ;
}
if ( V_16 -> V_28 == V_30 ) {
F_8 ( V_16 ) ;
return true ;
}
}
F_7 ( L_8 ) ;
return false ;
}
static int T_4 F_12 ( void )
{
if ( ! F_13 ( V_31 ) )
return - V_32 ;
if ( ! F_9 () )
return - V_32 ;
V_33 . V_34 = V_13 ;
return F_14 ( V_35 , & V_33 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( V_35 , & V_33 ) ;
}
