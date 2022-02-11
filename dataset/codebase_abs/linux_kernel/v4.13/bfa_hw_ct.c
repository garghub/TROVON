static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
}
void
F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_5 ;
void T_1 * V_7 = F_3 ( & V_2 -> V_8 ) ;
int V_9 = F_4 ( & V_2 -> V_8 ) ;
if ( V_9 == 0 ) {
V_5 -> V_10 = ( V_7 + V_11 ) ;
V_5 -> V_12 = ( V_7 + V_13 ) ;
} else {
V_5 -> V_10 = ( V_7 + V_14 ) ;
V_5 -> V_12 = ( V_7 + V_15 ) ;
}
}
void
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_5 ;
void T_1 * V_7 = F_3 ( & V_2 -> V_8 ) ;
V_5 -> V_10 = ( V_7 + V_16 ) ;
V_5 -> V_12 = ( V_7 + V_17 ) ;
}
void
F_6 ( struct V_1 * V_2 , int V_18 )
{
T_2 V_19 ;
V_19 = F_7 ( V_2 -> V_6 . V_5 . V_20 [ V_18 ] ) ;
F_8 ( V_19 , V_2 -> V_6 . V_5 . V_20 [ V_18 ] ) ;
}
void
F_9 ( struct V_1 * V_2 , int V_21 , T_2 V_22 )
{
T_2 V_19 ;
V_19 = F_7 ( V_2 -> V_6 . V_5 . V_23 [ V_21 ] ) ;
F_8 ( V_19 , V_2 -> V_6 . V_5 . V_23 [ V_21 ] ) ;
F_10 ( V_2 , V_21 ) = V_22 ;
F_8 ( V_22 , V_2 -> V_6 . V_5 . V_24 [ V_21 ] ) ;
F_11 () ;
}
void
F_12 ( struct V_1 * V_2 , int V_21 , T_2 V_22 )
{
F_10 ( V_2 , V_21 ) = V_22 ;
F_8 ( V_22 , V_2 -> V_6 . V_5 . V_24 [ V_21 ] ) ;
F_11 () ;
}
void
F_13 ( struct V_1 * V_2 , T_2 * V_25 ,
T_2 * V_26 , T_2 * V_27 )
{
* V_25 = ( 1 << V_28 ) - 1 ;
* V_27 = ( 1 << ( V_28 - 1 ) ) ;
* V_26 = V_28 ;
}
void
F_14 ( struct V_1 * V_2 , int V_29 )
{
F_15 ( ( V_29 != 1 ) && ( V_29 != V_28 ) ) ;
F_16 ( V_2 , V_29 ) ;
V_2 -> V_30 . V_29 = V_29 ;
F_17 ( V_2 ) ;
}
void
F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 . V_29 == 0 )
return;
if ( V_2 -> V_30 . V_29 == 1 )
V_2 -> V_30 . V_31 [ V_32 ] = V_33 ;
else
V_2 -> V_30 . V_31 [ V_32 ] = V_34 ;
}
void
F_19 ( struct V_1 * V_2 )
{
int V_35 ;
if ( V_2 -> V_30 . V_29 == 0 )
return;
if ( V_2 -> V_30 . V_29 == 1 ) {
for ( V_35 = V_36 ; V_35 < V_28 ; V_35 ++ )
V_2 -> V_30 . V_31 [ V_35 ] = V_33 ;
return;
}
for ( V_35 = V_36 ; V_35 <= V_37 ; V_35 ++ )
V_2 -> V_30 . V_31 [ V_35 ] = V_38 ;
for ( V_35 = V_39 ; V_35 <= V_40 ; V_35 ++ )
V_2 -> V_30 . V_31 [ V_35 ] = V_41 ;
}
void
F_17 ( struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_28 ; V_35 ++ )
V_2 -> V_30 . V_31 [ V_35 ] = F_1 ;
}
void
F_20 ( struct V_1 * V_2 , T_3 V_30 )
{
F_16 ( V_2 , 0 ) ;
F_21 ( & V_2 -> V_8 , V_30 ) ;
}
void
F_22 ( struct V_1 * V_2 , T_2 * V_42 , T_2 * V_43 )
{
* V_42 = V_39 ;
* V_43 = V_40 ;
}
