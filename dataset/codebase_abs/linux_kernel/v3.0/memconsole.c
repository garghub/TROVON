static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
return F_2 ( V_7 , V_9 , & V_8 , V_10 ,
V_11 ) ;
}
static void F_3 ( struct V_12 * V_13 )
{
F_4 ( V_14 L_1 , V_13 ) ;
F_4 ( V_14 L_2
L_3 ,
V_13 -> V_15 . V_16 , V_13 -> V_15 . V_17 ,
V_13 -> V_15 . V_18 , V_13 -> V_15 . V_19 ) ;
V_11 = V_13 -> V_15 . V_19 ;
V_10 = F_5 ( V_13 -> V_15 . V_16 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
F_4 ( V_14 L_4 , V_13 ) ;
F_4 ( V_14 L_2
L_5 ,
V_13 -> V_20 . V_16 , V_13 -> V_20 . V_17 ,
V_13 -> V_20 . V_18 , V_13 -> V_20 . V_21 ) ;
V_11 = V_13 -> V_20 . V_18 - V_13 -> V_20 . V_17 ;
V_10 = F_5 ( V_13 -> V_20 . V_16
+ V_13 -> V_20 . V_17 ) ;
}
static bool F_7 ( void )
{
unsigned int V_22 ;
T_3 V_23 , V_24 ;
V_22 = F_8 () ;
if ( ! V_22 ) {
F_4 ( V_14 L_6 ) ;
return false ;
}
V_23 = * ( V_25 * ) F_5 ( V_22 ) ;
V_23 <<= 10 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
struct V_12 * V_13 = F_5 ( V_22 + V_24 ) ;
if ( V_13 -> V_26 == V_27 ) {
F_3 ( V_13 ) ;
return true ;
}
if ( V_13 -> V_26 == V_28 ) {
F_6 ( V_13 ) ;
return true ;
}
}
F_4 ( V_14 L_7 ) ;
return false ;
}
static int T_4 F_9 ( void )
{
int V_29 ;
if ( ! F_10 ( V_30 ) )
return - V_31 ;
if ( ! F_7 () )
return - V_31 ;
V_32 . V_33 = V_11 ;
V_29 = F_11 ( V_34 , & V_32 ) ;
return V_29 ;
}
static void T_5 F_12 ( void )
{
F_13 ( V_34 , & V_32 ) ;
}
