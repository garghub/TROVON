static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return ( V_4 & V_2 -> V_6 -> V_8 ) == V_2 -> V_6 -> V_8 ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned int V_9 = V_2 -> V_10 -> V_11 ;
unsigned int V_12 = V_2 -> V_10 -> V_13 ;
T_1 V_14 , V_15 ;
unsigned int V_4 ;
int V_3 ;
V_3 = F_2 ( V_2 -> V_5 ,
V_16 , & V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
V_15 = V_14 & V_17 ;
if ( V_15 <= 3 )
V_15 = 0 ;
else
V_15 -= 3 ;
V_4 = V_9 + V_18 * V_15 ;
if ( V_4 > V_12 )
return - V_19 ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_11 , int V_13 )
{
unsigned int V_9 = V_2 -> V_10 -> V_11 ;
int V_15 = 0 ;
while ( V_9 + V_18 * V_15 < V_11 )
V_15 ++ ;
if ( V_9 + V_18 * V_15 > V_13 )
return - V_19 ;
V_15 += 3 ;
return F_5 ( V_2 -> V_5 ,
V_16 , V_15 ) ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_22 * * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_22 * V_28 ;
int V_29 , V_30 = 0 ;
V_25 = F_7 ( V_21 -> V_31 -> V_32 , L_1 ) ;
if ( ! V_25 )
return - V_19 ;
V_27 = F_8 ( V_21 ,
sizeof( * V_27 ) * F_9 ( V_33 ) , V_34 ) ;
if ( ! V_27 )
return - V_35 ;
for ( V_29 = 0 ; V_29 < F_9 ( V_33 ) ; V_29 ++ )
V_27 [ V_29 ] . V_36 = V_33 [ V_29 ] . V_36 ;
V_30 = V_26 ( V_21 , V_25 , V_27 , F_9 ( V_33 ) ) ;
if ( V_30 <= 0 )
return V_30 ;
* V_23 = F_8 ( V_21 , sizeof( * * V_23 ) * V_30 , V_34 ) ;
if ( ! ( * V_23 ) )
return - V_35 ;
V_28 = * V_23 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_28 -> V_37 = V_27 [ V_29 ] . V_38 ;
V_28 -> V_32 = V_27 [ V_29 ] . V_32 ;
V_28 -> V_39 = V_33 [ V_29 ] . V_39 ;
V_28 ++ ;
}
return V_30 ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_22 * * V_23 )
{
return 0 ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_22 * * V_23 )
{
struct V_40 * V_41 ;
int V_42 = 0 ;
V_41 = F_11 ( V_21 -> V_31 ) ;
if ( V_41 ) {
* V_23 = V_41 -> V_33 ;
V_42 = V_41 -> V_42 ;
}
if ( ! ( * V_23 ) && V_21 -> V_31 -> V_32 )
V_42 = F_6 ( V_21 , V_23 ) ;
return V_42 ;
}
static int F_12 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_13 ( V_44 -> V_21 . V_31 ) ;
struct V_47 * V_48 ;
struct V_22 * V_23 = NULL ;
int V_49 , V_29 ;
struct V_50 V_51 ;
V_49 = F_10 ( & V_44 -> V_21 , & V_23 ) ;
if ( ! V_23 || V_49 <= 0 ) {
F_14 ( & V_44 -> V_21 , L_2 ) ;
return - V_52 ;
}
V_48 = F_8 ( & V_44 -> V_21 ,
sizeof( struct V_47 ) ,
V_34 ) ;
if ( ! V_48 )
return - V_35 ;
V_48 -> V_2 = F_8 ( & V_44 -> V_21 ,
sizeof( struct V_1 * ) * V_49 ,
V_34 ) ;
if ( ! V_48 -> V_2 )
return - V_35 ;
V_48 -> V_21 = & V_44 -> V_21 ;
V_48 -> V_46 = V_46 ;
V_48 -> V_42 = V_49 ;
V_51 . V_21 = & V_44 -> V_21 ;
V_51 . V_5 = V_46 -> V_5 ;
V_51 . V_53 = V_48 ;
F_15 ( V_44 , V_48 ) ;
for ( V_29 = 0 ; V_29 < V_48 -> V_42 ; V_29 ++ ) {
int V_39 = V_23 [ V_29 ] . V_39 ;
V_51 . V_38 = V_23 [ V_29 ] . V_37 ;
V_51 . V_32 = V_23 [ V_29 ] . V_32 ;
V_48 -> V_2 [ V_29 ] = F_16 ( & V_44 -> V_21 ,
& V_33 [ V_39 ] , & V_51 ) ;
if ( F_17 ( V_48 -> V_2 [ V_29 ] ) ) {
F_14 ( V_48 -> V_21 ,
L_3 , V_39 ) ;
return F_18 ( V_48 -> V_2 [ V_29 ] ) ;
}
}
return 0 ;
}
