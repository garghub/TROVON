int F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , const struct V_6 * V_7 )
{
if ( V_4 -> V_8 )
return - V_9 ;
if ( V_5 < F_2 ( & V_4 -> V_10 ) )
return - V_9 ;
V_2 -> V_11 = V_4 ;
V_2 -> V_12 = F_2 ( & V_4 -> V_10 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = F_3 ( & V_4 -> V_15 ) ;
V_2 -> V_16 = ( V_17 * ) V_4 + sizeof( * V_4 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = & V_4 -> V_15 ;
V_2 -> V_19 ++ ;
V_2 -> V_20 = V_7 ;
V_2 -> V_21 = & V_22 ;
V_2 -> V_23 = 1 ;
if ( V_2 -> V_14 & ( 1 << V_24 ) ) {
while ( F_3 ( V_2 -> V_16 ) &
( 1 << V_24 ) ) {
V_2 -> V_16 += sizeof( V_25 ) ;
if ( ( unsigned long ) V_2 -> V_16 -
( unsigned long ) V_2 -> V_11 >
( unsigned long ) V_2 -> V_12 )
return - V_9 ;
}
V_2 -> V_16 += sizeof( V_25 ) ;
}
V_2 -> V_26 = V_2 -> V_16 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
V_25 V_27 , V_17 V_28 )
{
int V_29 ;
V_2 -> V_21 = NULL ;
if ( ! V_2 -> V_20 )
return;
for ( V_29 = 0 ; V_29 < V_2 -> V_20 -> V_30 ; V_29 ++ ) {
if ( V_2 -> V_20 -> V_31 [ V_29 ] . V_27 != V_27 )
continue;
if ( V_2 -> V_20 -> V_31 [ V_29 ] . V_28 != V_28 )
continue;
V_2 -> V_21 = & V_2 -> V_20 -> V_31 [ V_29 ] ;
break;
}
}
int F_5 (
struct V_1 * V_2 )
{
while ( 1 ) {
int V_32 = 0 ;
int V_33 , V_34 , V_35 , V_28 ;
V_25 V_27 ;
if ( ( V_2 -> V_13 % 32 ) == V_24 &&
! ( V_2 -> V_14 & 1 ) )
return - V_36 ;
if ( ! ( V_2 -> V_14 & 1 ) )
goto V_37;
switch ( V_2 -> V_13 % 32 ) {
case V_38 :
case V_24 :
V_34 = 1 ;
V_35 = 0 ;
break;
case V_39 :
V_34 = 2 ;
V_35 = 6 ;
break;
default:
if ( ! V_2 -> V_21 ||
V_2 -> V_13 >= V_2 -> V_21 -> V_40 ) {
if ( V_2 -> V_21 == & V_22 )
return - V_36 ;
V_34 = 0 ;
} else {
V_34 = V_2 -> V_21 -> V_41 [ V_2 -> V_13 ] . V_34 ;
V_35 = V_2 -> V_21 -> V_41 [ V_2 -> V_13 ] . V_35 ;
}
if ( ! V_34 ) {
V_2 -> V_16 = V_2 -> V_42 ;
V_2 -> V_21 = NULL ;
goto V_37;
}
break;
}
V_33 = ( ( unsigned long ) V_2 -> V_16 -
( unsigned long ) V_2 -> V_11 ) & ( V_34 - 1 ) ;
if ( V_33 )
V_2 -> V_16 += V_34 - V_33 ;
if ( V_2 -> V_13 % 32 == V_39 ) {
int V_43 ;
if ( ( unsigned long ) V_2 -> V_16 + V_35 -
( unsigned long ) V_2 -> V_11 >
( unsigned long ) V_2 -> V_12 )
return - V_9 ;
V_27 = ( * V_2 -> V_16 << 16 ) |
( * ( V_2 -> V_16 + 1 ) << 8 ) |
* ( V_2 -> V_16 + 2 ) ;
V_28 = * ( V_2 -> V_16 + 3 ) ;
F_4 ( V_2 , V_27 , V_28 ) ;
V_43 = F_2 ( V_2 -> V_16 + 4 ) ;
V_2 -> V_42 = V_2 -> V_16 + V_35 + V_43 ;
if ( ! V_2 -> V_21 )
V_35 += V_43 ;
}
V_2 -> V_44 = V_2 -> V_13 ;
V_2 -> V_26 = V_2 -> V_16 ;
V_2 -> V_45 = V_35 ;
V_2 -> V_16 += V_35 ;
if ( ( unsigned long ) V_2 -> V_16 -
( unsigned long ) V_2 -> V_11 >
( unsigned long ) V_2 -> V_12 )
return - V_9 ;
switch ( V_2 -> V_13 % 32 ) {
case V_39 :
V_2 -> V_18 = 1 ;
V_2 -> V_23 = 0 ;
V_2 -> V_44 =
V_39 ;
if ( ! V_2 -> V_21 )
V_32 = 1 ;
goto V_37;
case V_38 :
V_2 -> V_18 = 1 ;
V_2 -> V_21 = & V_22 ;
V_2 -> V_23 = 1 ;
goto V_37;
case V_24 :
V_2 -> V_14 =
F_3 ( V_2 -> V_19 ) ;
V_2 -> V_19 ++ ;
if ( V_2 -> V_18 )
V_2 -> V_13 = 0 ;
else
V_2 -> V_13 ++ ;
V_2 -> V_18 = 0 ;
break;
default:
V_32 = 1 ;
V_37:
V_2 -> V_14 >>= 1 ;
V_2 -> V_13 ++ ;
}
if ( V_32 )
return 0 ;
}
}
