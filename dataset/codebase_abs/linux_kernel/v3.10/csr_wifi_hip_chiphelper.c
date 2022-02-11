T_1 * F_1 ( T_2 V_1 )
{
T_3 V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
{
if ( V_3 [ V_2 ] -> V_4 . V_5 == V_1 )
{
return V_3 [ V_2 ] ;
}
}
return & V_6 ;
}
T_1 * F_3 ( T_4 V_7 , T_4 V_8 )
{
T_3 V_2 ;
if ( ( V_7 & 0xFF00 ) != 0 )
{
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
{
if ( V_3 [ V_2 ] -> V_4 . V_9 &&
( ( V_7 & V_3 [ V_2 ] -> V_4 . V_10 ) ==
V_3 [ V_2 ] -> V_4 . V_11 ) )
{
return V_3 [ V_2 ] ;
}
}
}
else
{
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
{
if ( ! V_3 [ V_2 ] -> V_4 . V_9 &&
( ( V_8 & V_3 [ V_2 ] -> V_4 . V_10 ) ==
V_3 [ V_2 ] -> V_4 . V_11 ) )
{
return V_3 [ V_2 ] ;
}
}
}
return & V_6 ;
}
T_1 * F_4 ( T_4 V_12 )
{
return F_3 ( 0x0000 , V_12 ) ;
}
T_1 * F_5 ( void )
{
return & V_6 ;
}
T_1 * F_6 ( enum V_13 V_14 , T_4 V_15 )
{
if ( V_14 == V_16 )
{
return F_3 ( V_15 , 0x0000 ) ;
}
else
{
return F_3 ( 0x0000 , V_15 ) ;
}
}
T_4 F_7 ( T_1 * V_17 , T_4 V_18 )
{
T_3 V_2 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_19 . V_20 ; V_2 ++ )
{
if ( V_17 -> V_19 . V_21 [ V_2 ] . V_22 == V_18 )
{
return V_17 -> V_19 . V_21 [ V_2 ] . V_23 ;
}
}
return V_18 ;
}
T_4 F_8 ( T_1 * V_17 , T_4 V_18 )
{
T_3 V_2 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_19 . V_20 ; V_2 ++ )
{
if ( V_17 -> V_19 . V_21 [ V_2 ] . V_23 == V_18 )
{
return V_17 -> V_19 . V_21 [ V_2 ] . V_22 ;
}
}
return V_18 ;
}
T_4 F_9 ( T_1 * V_17 ,
enum V_24 V_25 )
{
if ( V_25 < V_26 &&
V_17 -> V_27 [ V_25 ] != NULL )
{
return V_17 -> V_27 [ V_25 ] -> V_28 + V_17 -> V_27 [ V_25 ] -> V_29 ;
}
return 0 ;
}
T_4 F_10 ( T_1 * V_17 ,
enum V_24 V_25 )
{
if ( V_25 < V_26 &&
V_17 -> V_27 [ V_25 ] != NULL )
{
return V_17 -> V_27 [ V_25 ] -> V_30 - V_17 -> V_27 [ V_25 ] -> V_29 ;
}
return 0 ;
}
T_3 F_11 ( T_1 * V_17 ,
const struct V_31 * * V_32 )
{
* V_32 = V_17 -> V_33 . V_21 ;
return V_17 -> V_33 . V_20 ;
}
T_3 F_12 ( T_1 * V_17 ,
const struct V_34 * * V_32 )
{
* V_32 = V_17 -> V_35 . V_21 ;
return V_17 -> V_35 . V_20 ;
}
T_5 F_13 ( T_1 * V_17 ,
enum V_24 V_25 ,
enum V_36 type ,
T_3 V_37 ,
T_4 * V_38 , T_4 * V_18 , T_3 * V_20 )
{
const struct V_39 * V_40 ;
const struct V_41 * V_42 ;
T_4 V_43 , V_44 ;
if ( V_25 >= V_26 )
{
return FALSE ;
}
if ( ( V_40 = V_17 -> V_27 [ V_25 ] ) == NULL )
{
return FALSE ;
}
if ( type >= V_45 )
{
return FALSE ;
}
if ( ( V_42 = & V_40 -> V_42 [ type ] ) == NULL )
{
return FALSE ;
}
if ( ! V_42 -> V_46 )
{
return FALSE ;
}
V_44 = ( T_4 ) ( V_37 >> V_42 -> V_47 ) + V_42 -> V_48 ;
V_43 = ( T_4 ) ( V_37 & ( ( 1 << V_42 -> V_47 ) - 1 ) ) ;
while ( V_43 < V_40 -> V_29 )
{
V_43 += 1 << V_42 -> V_47 ;
V_44 -- ;
}
* V_38 = V_44 ;
* V_18 = V_40 -> V_28 + V_43 ;
* V_20 = V_40 -> V_30 - V_43 ;
return TRUE ;
}
