int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_8 , V_9 ) ;
if ( ! V_4 )
return - V_10 ;
F_3 ( & V_4 -> V_11 ) ;
for ( V_7 = 0 ; V_7 < V_12 ; ++ V_7 )
F_4 ( V_4 -> V_13 + V_7 ) ;
V_6 = F_5 ( V_4 , 0 ) ;
if ( ! V_6 ) {
F_6 ( V_8 , V_4 ) ;
return - V_10 ;
}
V_4 -> V_14 = V_2 -> V_15 ;
V_2 -> V_15 = V_6 ;
V_2 -> V_16 = V_2 -> V_17 = V_2 -> V_18 = V_2 -> V_19 = 0 ;
V_2 -> V_20 = V_2 -> V_21 = V_2 -> V_22 = V_2 -> V_23 = 0 ;
F_7 ( V_2 -> V_24 ) ;
V_2 -> V_24 = F_8 ( & V_25 ) ;
#ifdef F_9
F_10 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
#endif
F_11 ( V_4 ) ;
return 0 ;
}
static void F_12 ( struct V_27 * V_28 )
{
struct V_3 * V_4 =
F_13 ( V_28 , struct V_3 , V_29 ) ;
F_14 ( V_4 -> V_14 ) ;
F_6 ( V_8 , V_4 ) ;
}
void F_15 ( struct V_11 * V_11 )
{
struct V_3 * V_4 =
F_13 ( V_11 , struct V_3 , V_11 ) ;
F_16 ( & V_4 -> V_29 , F_12 ) ;
F_17 ( & V_4 -> V_29 ) ;
}
T_1 F_18 ( struct V_3 * V_30 , const struct V_1 * V_1 , T_1 V_16 )
{
struct V_3 * V_31 ;
if ( F_19 ( V_30 == V_1 -> V_15 -> V_32 ) )
return V_16 ;
for ( V_31 = V_30 ; V_31 != & V_33 ;
V_31 = V_31 -> V_14 -> V_32 ) {
if ( V_1 -> V_15 == V_31 -> V_14 ) {
return ( T_1 ) 0 ;
}
}
return V_34 ;
}
T_2 F_20 ( struct V_3 * V_30 , const struct V_1 * V_1 , T_2 V_20 )
{
struct V_3 * V_31 ;
if ( F_19 ( V_30 == V_1 -> V_15 -> V_32 ) )
return V_20 ;
for ( V_31 = V_30 ; V_31 != & V_33 ;
V_31 = V_31 -> V_14 -> V_32 ) {
if ( V_1 -> V_15 == V_31 -> V_14 ) {
return ( T_2 ) 0 ;
}
}
return V_35 ;
}
static T_3 int F_21 ( void )
{
V_8 = F_22 ( V_3 , V_36 ) ;
return 0 ;
}
