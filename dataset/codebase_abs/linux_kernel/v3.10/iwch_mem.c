static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_2 -> V_5 . V_6 = 1 ;
V_2 -> V_5 . V_3 = V_3 ;
V_4 = V_3 >> 8 ;
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_9 = V_3 ;
F_2 ( L_1 , V_10 , V_4 , V_2 ) ;
return F_3 ( V_2 -> V_11 , & V_2 -> V_11 -> V_12 , V_2 , V_4 ) ;
}
int F_4 ( struct V_13 * V_11 , struct V_14 * V_15 ,
struct V_1 * V_2 , int V_16 )
{
T_1 V_3 ;
int V_17 ;
if ( F_5 ( & V_11 -> V_18 ,
& V_3 , V_2 -> V_5 . V_19 ,
V_2 -> V_5 . V_20 ,
V_2 -> V_5 . V_21 ,
V_2 -> V_5 . V_22 ,
V_2 -> V_5 . V_23 ,
V_16 - 12 ,
V_2 -> V_5 . V_24 , V_2 -> V_5 . V_25 ) )
return - V_26 ;
V_17 = F_1 ( V_2 , V_3 ) ;
if ( V_17 )
F_6 ( & V_11 -> V_18 , V_2 -> V_5 . V_3 , V_2 -> V_5 . V_24 ,
V_2 -> V_5 . V_25 ) ;
return V_17 ;
}
int F_7 ( struct V_13 * V_11 , struct V_14 * V_15 ,
struct V_1 * V_2 ,
int V_16 ,
int V_27 )
{
T_1 V_3 ;
int V_17 ;
if ( V_27 > V_2 -> V_5 . V_24 )
return - V_26 ;
V_3 = V_2 -> V_5 . V_3 ;
if ( F_8 ( & V_11 -> V_18 ,
& V_3 , V_2 -> V_5 . V_19 ,
V_2 -> V_5 . V_20 ,
V_2 -> V_5 . V_21 ,
V_2 -> V_5 . V_22 ,
V_2 -> V_5 . V_23 ,
V_16 - 12 ,
V_2 -> V_5 . V_24 , V_2 -> V_5 . V_25 ) )
return - V_26 ;
V_17 = F_1 ( V_2 , V_3 ) ;
if ( V_17 )
F_6 ( & V_11 -> V_18 , V_2 -> V_5 . V_3 , V_2 -> V_5 . V_24 ,
V_2 -> V_5 . V_25 ) ;
return V_17 ;
}
int F_9 ( struct V_1 * V_2 , int V_27 )
{
V_2 -> V_5 . V_25 = F_10 ( & V_2 -> V_11 -> V_18 ,
V_27 << 3 ) ;
if ( ! V_2 -> V_5 . V_25 )
return - V_26 ;
V_2 -> V_5 . V_24 = V_27 ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_11 -> V_18 , V_2 -> V_5 . V_25 ,
V_2 -> V_5 . V_24 << 3 ) ;
}
int F_13 ( struct V_1 * V_2 , T_2 * V_28 , int V_27 , int V_29 )
{
return F_14 ( & V_2 -> V_11 -> V_18 , V_28 ,
V_2 -> V_5 . V_25 + ( V_29 << 3 ) , V_27 ) ;
}
int F_15 ( struct V_30 * V_31 ,
int V_32 ,
T_3 * V_33 ,
T_3 * V_34 ,
int * V_27 ,
int * V_16 ,
T_2 * * V_35 )
{
T_3 V_36 ;
int V_37 , V_38 , V_39 ;
V_36 = 0 ;
* V_34 = 0 ;
for ( V_37 = 0 ; V_37 < V_32 ; ++ V_37 ) {
if ( V_37 != 0 && V_31 [ V_37 ] . V_40 & ~ V_41 )
return - V_42 ;
if ( V_37 != 0 && V_37 != V_32 - 1 &&
( V_31 [ V_37 ] . V_43 & ~ V_41 ) )
return - V_42 ;
* V_34 += V_31 [ V_37 ] . V_43 ;
if ( V_37 > 0 )
V_36 |= V_31 [ V_37 ] . V_40 ;
else
V_36 |= V_31 [ V_37 ] . V_40 & V_41 ;
if ( V_37 != V_32 - 1 )
V_36 |= V_31 [ V_37 ] . V_40 + V_31 [ V_37 ] . V_43 ;
else
V_36 |= ( V_31 [ V_37 ] . V_40 + V_31 [ V_37 ] . V_43 +
V_44 - 1 ) & V_41 ;
}
if ( * V_34 > 0xFFFFFFFFULL )
return - V_26 ;
for ( * V_16 = V_45 ; * V_16 < 27 ; ++ ( * V_16 ) )
if ( ( 1ULL << * V_16 ) & V_36 )
break;
V_31 [ 0 ] . V_43 += V_31 [ 0 ] . V_40 & ( ( 1ULL << * V_16 ) - 1 ) ;
V_31 [ 0 ] . V_40 &= ~ 0ull << * V_16 ;
* V_27 = 0 ;
for ( V_37 = 0 ; V_37 < V_32 ; ++ V_37 )
* V_27 += ( V_31 [ V_37 ] . V_43 +
( 1ULL << * V_16 ) - 1 ) >> * V_16 ;
if ( ! * V_27 )
return - V_42 ;
* V_35 = F_16 ( sizeof( T_3 ) * * V_27 , V_46 ) ;
if ( ! * V_35 )
return - V_26 ;
V_39 = 0 ;
for ( V_37 = 0 ; V_37 < V_32 ; ++ V_37 )
for ( V_38 = 0 ;
V_38 < ( V_31 [ V_37 ] . V_43 + ( 1ULL << * V_16 ) - 1 ) >> * V_16 ;
++ V_38 )
( * V_35 ) [ V_39 ++ ] = F_17 ( V_31 [ V_37 ] . V_40 +
( ( T_3 ) V_38 << * V_16 ) ) ;
F_2 ( L_2 ,
V_10 , ( unsigned long long ) * V_33 ,
( unsigned long long ) V_36 , * V_16 , ( unsigned long long ) * V_34 ,
* V_27 ) ;
return 0 ;
}
