void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 ) ;
}
static bool F_3 ( struct V_5 * V_3 , T_1 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_3 ) ;
T_1 V_7 = F_5 ( F_6 ( 0 ) ) ;
* V_6 = V_7 ;
return F_7 ( V_7 ) ;
}
int F_8 ( struct V_5 * V_3 , const T_1 * V_8 , T_1 V_9 )
{
struct V_1 * V_2 = F_4 ( V_3 ) ;
T_1 V_6 ;
int V_10 ;
int V_11 ;
if ( F_9 ( V_9 < 1 || V_9 > 15 ) )
return - V_12 ;
F_10 ( & V_3 -> V_4 ) ;
F_11 ( V_2 , V_13 ) ;
V_2 -> V_3 . V_14 += 1 ;
V_2 -> V_3 . V_15 = V_8 [ 0 ] ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_12 ( F_6 ( V_10 ) , V_8 [ V_10 ] ) ;
F_13 ( F_6 ( V_10 - 1 ) ) ;
F_12 ( V_16 , V_17 ) ;
V_11 = F_14 ( F_3 ( V_3 , & V_6 ) , 10 ) ;
if ( V_11 )
V_11 = F_15 ( F_3 ( V_3 , & V_6 ) , 10 ) ;
if ( V_6 != V_18 ) {
if ( V_11 != - V_19 )
V_11 = - V_20 ;
F_16 ( L_1
L_2 ,
V_8 [ 0 ] , V_11 , V_6 , F_5 ( F_6 ( 15 ) ) ) ;
V_2 -> V_3 . V_21 += 1 ;
V_2 -> V_3 . V_22 = V_11 ;
}
V_2 -> V_3 . V_23 = V_6 ;
F_17 ( V_2 , V_13 ) ;
F_18 ( & V_3 -> V_4 ) ;
return V_11 ;
}
int F_19 ( struct V_5 * V_3 )
{
struct V_1 * V_2 = F_4 ( V_3 ) ;
T_1 V_8 [ 2 ] ;
V_8 [ 0 ] = V_24 ;
if ( ! F_20 () || F_21 ( V_2 ) )
V_8 [ 1 ] = 0 ;
else
V_8 [ 1 ] = V_25 | V_26 ;
return F_8 ( V_3 , V_8 , F_22 ( V_8 ) ) ;
}
