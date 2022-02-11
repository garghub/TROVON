static struct V_1 * F_1 (
const unsigned long * V_2 ,
unsigned long V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( V_3 , sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_3 ; ++ V_5 )
V_4 [ V_5 ] . V_7 = V_2 [ V_5 ] ;
return V_4 ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
T_1 V_12 , V_13 , V_14 = 0 ;
T_1 V_15 [ 6 ] ;
T_1 V_16 , V_17 ;
if ( F_4 ( V_11 , L_1 , & V_12 ) )
return - V_18 ;
if ( F_4 ( V_11 , L_2 , & V_13 ) )
V_13 = 1 ;
if ( F_5 ( V_11 , L_3 ) )
V_14 = 1 << V_19 ;
if ( F_6 ( V_11 , L_4 , V_15 ,
F_7 ( V_15 ) ) )
return - V_18 ;
V_12 *= 4 ;
V_16 = 1 << V_20 ;
if ( V_13 == 2 )
V_16 |= 1 << V_21 ;
V_17 = F_8 ( V_9 -> V_22 + V_23 ) ;
V_17 = ( V_17 & ~ ( V_24 << V_12 ) ) | ( V_16 << V_12 ) ;
F_9 ( V_17 , V_9 -> V_22 + V_23 ) ;
F_9 ( V_14 | ( V_15 [ 0 ] << V_25 ) |
( V_15 [ 1 ] << V_26 ) |
( V_15 [ 2 ] << V_27 ) |
( V_15 [ 3 ] << V_28 ) |
( V_15 [ 4 ] << V_29 ) |
( V_15 [ 5 ] << V_30 ) ,
V_9 -> V_22 + V_31 + V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_10 * V_11 , * V_34 ;
struct V_8 * V_9 ;
struct V_35 * V_36 = & V_33 -> V_36 ;
bool V_37 = false ;
V_11 = V_36 -> V_38 ;
if ( ! V_11 ) {
F_11 ( & V_33 -> V_36 , L_5 ) ;
return - V_18 ;
}
V_9 = F_12 ( & V_33 -> V_36 ,
sizeof( struct V_8 ) , V_6 ) ;
if ( ! V_9 )
return - V_39 ;
V_9 -> V_36 = V_36 ;
V_9 -> V_22 = F_13 ( V_11 , 0 ) ;
if ( ! V_9 -> V_22 ) {
F_11 ( & V_33 -> V_36 , L_6 ) ;
return - V_39 ;
}
F_14 ( V_33 , V_9 ) ;
V_9 -> V_40 = F_1 ( V_41 ,
sizeof( V_41 ) ) ;
if ( ! V_9 -> V_40 ) {
F_15 ( V_9 -> V_22 ) ;
return - V_39 ;
}
F_16 (np, child) {
if ( F_3 ( V_9 , V_34 ) ) {
F_11 ( V_36 ,
L_7 ,
V_34 -> V_42 ) ;
V_37 = true ;
}
}
if ( V_37 )
return 0 ;
return F_17 ( V_11 , NULL , NULL , V_36 ) ;
}
static int F_18 ( struct V_32 * V_33 )
{
struct V_8 * V_9 = F_19 ( V_33 ) ;
F_20 ( V_9 -> V_40 ) ;
F_15 ( V_9 -> V_22 ) ;
return 0 ;
}
static void F_21 ( void T_2 * V_43 ,
struct V_1 * V_4 ,
unsigned int V_44 )
{
for (; V_44 > 0 ; -- V_44 , ++ V_4 )
V_4 -> V_45 = F_22 ( V_43 + V_4 -> V_7 ) ;
}
static void F_23 ( void T_2 * V_43 ,
const struct V_1 * V_4 ,
unsigned int V_44 )
{
for (; V_44 > 0 ; -- V_44 , ++ V_4 )
F_24 ( V_4 -> V_45 , V_43 + V_4 -> V_7 ) ;
}
static int F_25 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_26 ( V_36 ) ;
F_21 ( V_9 -> V_22 , V_9 -> V_40 ,
F_7 ( V_41 ) ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_26 ( V_36 ) ;
F_23 ( V_9 -> V_22 , V_9 -> V_40 ,
F_7 ( V_41 ) ) ;
return 0 ;
}
