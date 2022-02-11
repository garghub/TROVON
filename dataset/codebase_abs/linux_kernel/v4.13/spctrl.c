enum V_1 F_1 ( T_1 V_2 ,
T_2 * V_3 )
{
T_3 V_4 = V_5 ;
struct V_6 * V_7 ;
if ( ( V_2 >= V_8 ) || ( V_3 == NULL ) )
return V_9 ;
V_10 [ V_2 ] . V_4 = V_5 ;
V_7 = & V_10 [ V_2 ] . V_11 ;
V_7 -> V_12 = V_3 -> V_12 ;
V_7 -> V_13 = V_3 -> V_13 ;
V_7 -> V_14 = V_3 -> V_14 ;
V_7 -> V_15 = V_3 -> V_15 ;
V_7 -> V_2 = V_2 ;
V_10 [ V_2 ] . V_16 = V_3 -> V_16 ;
V_10 [ V_2 ] . V_17 = V_3 -> V_17 ;
V_4 = F_2 ( V_3 -> V_18 ) ;
if ( V_4 == V_5 )
return V_19 ;
F_3 ( V_4 , V_3 -> V_20 , V_3 -> V_18 ) ;
if ( sizeof( T_3 ) > sizeof( V_21 ) ) {
F_4 ( V_22 ,
L_1 ) ;
F_5 ( V_4 ) ;
V_4 = V_5 ;
return V_23 ;
}
V_7 -> V_24 = V_4 + V_3 -> V_25 ;
if ( ( V_7 -> V_24 % V_26 ) != 0 ) {
F_4 ( V_22 ,
L_2 ) ;
F_5 ( V_4 ) ;
V_4 = V_5 ;
return V_23 ;
}
V_10 [ V_2 ] . V_27 = V_3 -> V_27 ;
V_10 [ V_2 ] . V_4 = V_4 ;
V_10 [ V_2 ] . V_28 = V_3 -> V_28 ;
F_6 ( V_2 , V_29 , ( V_21 ) V_10 [ V_2 ] . V_4 ) ;
F_7 ( V_2 , V_30 , V_31 ) ;
V_32 [ V_2 ] = true ;
return V_33 ;
}
void F_8 ( T_1 V_2 )
{
F_6 ( V_2 , V_29 , ( V_21 ) V_10 [ V_2 ] . V_4 ) ;
F_7 ( V_2 , V_30 , V_31 ) ;
V_32 [ V_2 ] = true ;
}
T_3 F_9 ( T_1 V_2 )
{
return V_10 [ V_2 ] . V_4 ;
}
enum V_1 F_10 ( T_1 V_2 )
{
if ( ( V_2 >= V_8 ) || ( ( V_2 < V_8 ) && ( ! V_32 [ V_2 ] ) ) )
return V_9 ;
if ( V_10 [ V_2 ] . V_4 )
F_5 ( V_10 [ V_2 ] . V_4 ) ;
V_32 [ V_2 ] = false ;
return V_33 ;
}
enum V_1 F_11 ( T_1 V_2 )
{
if ( ( V_2 >= V_8 ) || ( ( V_2 < V_8 ) && ( ! V_32 [ V_2 ] ) ) )
return V_9 ;
assert ( sizeof( unsigned int ) <= sizeof( V_21 ) ) ;
F_12 ( V_2 ,
V_10 [ V_2 ] . V_16 ,
& V_10 [ V_2 ] . V_11 ,
sizeof( V_10 [ V_2 ] . V_11 ) ) ;
F_6 ( V_2 , V_34 , ( V_21 ) V_10 [ V_2 ] . V_27 ) ;
F_7 ( V_2 , V_35 , V_36 ) ;
F_7 ( V_2 , V_35 , V_37 ) ;
return V_33 ;
}
T_4 F_13 ( T_1 V_2 )
{
T_4 V_38 = 0 ;
unsigned int V_39 ;
if ( V_2 >= V_8 )
return V_40 ;
V_39 = V_10 [ V_2 ] . V_17 ;
( void ) V_39 ;
if ( V_2 == V_41 )
V_38 = F_14 ( V_2 , ( unsigned ) F_15 ( V_42 ) ) ;
return V_38 ;
}
int F_16 ( T_1 V_2 )
{
int V_38 = 0 ;
assert ( V_2 < V_8 ) ;
V_38 = F_17 ( V_2 , V_35 , V_43 ) ;
return V_38 ;
}
