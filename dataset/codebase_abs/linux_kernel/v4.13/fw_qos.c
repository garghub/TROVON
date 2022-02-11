int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
T_2 V_10 ;
int V_11 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_8 = V_6 -> V_12 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 += 2 )
V_8 -> V_4 [ V_11 >> 1 ] = V_4 [ V_11 ] << 4 | V_4 [ V_11 + 1 ] ;
V_10 = V_14 << 8 | V_3 ;
V_9 = F_5 ( V_2 , V_6 -> V_15 , V_10 , 1 , V_16 ,
V_17 , V_18 ) ;
F_6 ( V_2 , V_6 ) ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_19 ,
T_1 * V_20 , T_3 * V_21 )
{
struct V_5 * V_6 ;
struct V_22 * V_8 ;
int V_9 ;
T_2 V_10 ;
int V_11 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_8 = V_6 -> V_12 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
struct V_24 * V_25 = & V_8 -> V_25 [ V_11 ] ;
T_3 V_26 ;
if ( V_21 && V_21 [ V_11 ] ) {
if ( V_21 [ V_11 ] <= V_27 ) {
V_26 = V_21 [ V_11 ] ;
V_25 -> V_28 =
F_8 ( V_29 ) ;
} else {
V_26 = V_21 [ V_11 ] / 10 ;
V_25 -> V_28 =
F_8 ( V_30 ) ;
}
V_25 -> V_31 = F_8 ( V_26 ) ;
} else {
V_25 -> V_31 = F_8 ( V_32 ) ;
V_25 -> V_28 = F_8 ( V_30 ) ;
}
V_25 -> V_20 = F_8 ( V_20 [ V_11 ] ) ;
V_25 -> V_33 = F_8 ( V_19 [ V_11 ] ) ;
}
V_10 = V_34 << 8 | V_3 ;
V_9 = F_5 ( V_2 , V_6 -> V_15 , V_10 , 1 , V_16 ,
V_17 , V_18 ) ;
F_6 ( V_2 , V_6 ) ;
return V_9 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 * V_35 , T_1 * V_36 )
{
int V_11 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_37 * V_38 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_38 = V_6 -> V_12 ;
V_9 = F_10 ( V_2 , 0 , V_6 -> V_15 , V_3 ,
V_39 ,
V_40 ,
V_41 ,
V_18 ) ;
if ( V_9 )
goto V_42;
* V_35 = ( T_3 ) F_11 ( V_38 -> V_35 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_36 [ V_11 ] = ( T_1 ) F_11 ( V_38 -> V_36 [ V_11 ] ) ;
V_42:
F_6 ( V_2 , V_6 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_36 )
{
int V_11 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_37 * V_43 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_43 = V_6 -> V_12 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_43 -> V_36 [ V_11 ] = F_13 ( V_36 [ V_11 ] ) ;
V_9 = F_5 ( V_2 , V_6 -> V_15 , V_3 ,
V_44 ,
V_40 ,
V_41 ,
V_18 ) ;
F_6 ( V_2 , V_6 ) ;
return V_9 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_45 ,
struct V_46 * V_38 )
{
int V_11 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_47 * V_48 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_48 = V_6 -> V_12 ;
V_9 = F_10 ( V_2 , 0 , V_6 -> V_15 , ( V_45 << 8 ) | V_3 ,
V_49 ,
V_50 ,
V_41 ,
V_18 ) ;
if ( V_9 )
goto V_42;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_38 [ V_11 ] . V_51 = F_11 ( V_48 -> V_52 [ V_11 ] . V_51 ) ;
V_38 [ V_11 ] . V_53 =
F_11 ( V_48 -> V_52 [ V_11 ] . V_53 ) ;
V_38 [ V_11 ] . V_54 =
! ! ( F_11 ( V_48 -> V_52 [ V_11 ] . V_54 ) & 31 ) ;
}
V_42:
F_6 ( V_2 , V_6 ) ;
return V_9 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_45 ,
struct V_46 * V_43 )
{
int V_11 ;
int V_9 ;
struct V_5 * V_6 ;
struct V_47 * V_48 ;
V_6 = F_2 ( V_2 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_48 = V_6 -> V_12 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_48 -> V_52 [ V_11 ] . V_51 = F_13 ( V_43 [ V_11 ] . V_51 ) ;
V_48 -> V_52 [ V_11 ] . V_53 =
F_13 ( V_43 [ V_11 ] . V_53 ) ;
V_48 -> V_52 [ V_11 ] . V_54 =
F_13 ( V_43 [ V_11 ] . V_54 << 31 ) ;
}
V_9 = F_5 ( V_2 , V_6 -> V_15 , ( V_45 << 8 ) | V_3 ,
V_55 ,
V_50 ,
V_41 ,
V_18 ) ;
F_6 ( V_2 , V_6 ) ;
return V_9 ;
}
