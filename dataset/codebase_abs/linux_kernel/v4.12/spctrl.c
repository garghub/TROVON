enum V_1 F_1 ( T_1 V_2 ,
T_2 * V_3 )
{
T_3 V_4 = V_5 ;
struct V_6 * V_7 ;
if ( ( V_2 >= V_8 ) || ( V_3 == 0 ) )
return V_9 ;
V_10 [ V_2 ] . V_4 = V_5 ;
#if F_2 ( V_11 )
( void ) V_7 ;
V_4 = F_3 ( 1 ) ;
if ( V_4 == V_5 )
return V_12 ;
#else
V_7 = & V_10 [ V_2 ] . V_13 ;
V_7 -> V_14 = V_3 -> V_14 ;
V_7 -> V_15 = V_3 -> V_15 ;
V_7 -> V_16 = V_3 -> V_16 ;
V_7 -> V_17 = V_3 -> V_17 ;
V_7 -> V_2 = V_2 ;
V_10 [ V_2 ] . V_18 = V_3 -> V_18 ;
V_10 [ V_2 ] . V_19 = V_3 -> V_19 ;
V_4 = F_3 ( V_3 -> V_20 ) ;
if ( V_4 == V_5 )
return V_12 ;
F_4 ( V_4 , V_3 -> V_21 , V_3 -> V_20 ) ;
if ( sizeof( T_3 ) > sizeof( V_22 ) ) {
F_5 ( V_23 ,
L_1 ) ;
F_6 ( V_4 ) ;
V_4 = V_5 ;
return V_24 ;
}
V_7 -> V_25 = V_4 + V_3 -> V_26 ;
if ( ( V_7 -> V_25 % V_27 ) != 0 ) {
F_5 ( V_23 ,
L_2 ) ;
F_6 ( V_4 ) ;
V_4 = V_5 ;
return V_24 ;
}
#endif
V_10 [ V_2 ] . V_28 = V_3 -> V_28 ;
V_10 [ V_2 ] . V_4 = V_4 ;
V_10 [ V_2 ] . V_29 = V_3 -> V_29 ;
F_7 ( V_2 , V_30 , ( V_22 ) V_10 [ V_2 ] . V_4 ) ;
F_8 ( V_2 , V_31 , V_32 ) ;
V_33 [ V_2 ] = true ;
return V_34 ;
}
void F_9 ( T_1 V_2 )
{
F_7 ( V_2 , V_30 , ( V_22 ) V_10 [ V_2 ] . V_4 ) ;
F_8 ( V_2 , V_31 , V_32 ) ;
V_33 [ V_2 ] = true ;
}
T_3 F_10 ( T_1 V_2 )
{
return V_10 [ V_2 ] . V_4 ;
}
enum V_1 F_11 ( T_1 V_2 )
{
if ( ( V_2 >= V_8 ) || ( ( V_2 < V_8 ) && ( ! V_33 [ V_2 ] ) ) )
return V_9 ;
if ( V_10 [ V_2 ] . V_4 )
F_6 ( V_10 [ V_2 ] . V_4 ) ;
V_33 [ V_2 ] = false ;
return V_34 ;
}
enum V_1 F_12 ( T_1 V_2 )
{
if ( ( V_2 >= V_8 ) || ( ( V_2 < V_8 ) && ( ! V_33 [ V_2 ] ) ) )
return V_9 ;
assert ( sizeof( unsigned int ) <= sizeof( V_22 ) ) ;
F_13 ( V_2 ,
V_10 [ V_2 ] . V_18 ,
& V_10 [ V_2 ] . V_13 ,
sizeof( V_10 [ V_2 ] . V_13 ) ) ;
F_7 ( V_2 , V_35 , ( V_22 ) V_10 [ V_2 ] . V_28 ) ;
F_8 ( V_2 , V_36 , V_37 ) ;
F_8 ( V_2 , V_36 , V_38 ) ;
return V_34 ;
}
T_4 F_14 ( T_1 V_2 )
{
T_4 V_39 = 0 ;
unsigned int V_40 ;
if ( V_2 >= V_8 )
return V_41 ;
V_40 = V_10 [ V_2 ] . V_19 ;
( void ) V_40 ;
if ( V_2 == V_42 )
V_39 = F_15 ( V_2 , ( unsigned ) F_16 ( V_43 ) ) ;
return V_39 ;
}
int F_17 ( T_1 V_2 )
{
int V_39 = 0 ;
assert ( V_2 < V_8 ) ;
V_39 = F_18 ( V_2 , V_36 , V_44 ) ;
return V_39 ;
}
