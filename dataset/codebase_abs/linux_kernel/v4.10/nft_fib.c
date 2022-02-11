int F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned int V_9 ;
switch ( V_8 -> V_10 ) {
case V_11 :
case V_12 :
V_9 = ( 1 << V_13 ) ;
break;
case V_14 :
if ( V_8 -> V_15 & V_16 )
V_9 = ( 1 << V_13 ) |
( 1 << V_17 ) |
( 1 << V_18 ) ;
else if ( V_8 -> V_15 & V_19 )
V_9 = ( 1 << V_20 ) |
( 1 << V_21 ) |
( 1 << V_18 ) ;
else
V_9 = ( 1 << V_17 ) |
( 1 << V_20 ) |
( 1 << V_18 ) |
( 1 << V_13 ) |
( 1 << V_21 ) ;
break;
default:
return - V_22 ;
}
return F_3 ( V_2 -> V_23 , V_9 ) ;
}
int F_4 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_24 * const V_25 [] )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned int V_26 ;
int V_27 ;
if ( ! V_25 [ V_28 ] || ! V_25 [ V_29 ] || ! V_25 [ V_30 ] )
return - V_22 ;
V_8 -> V_15 = F_5 ( F_6 ( V_25 [ V_30 ] ) ) ;
if ( V_8 -> V_15 == 0 || ( V_8 -> V_15 & ~ V_31 ) )
return - V_22 ;
if ( ( V_8 -> V_15 & ( V_32 | V_33 ) ) ==
( V_32 | V_33 ) )
return - V_22 ;
if ( ( V_8 -> V_15 & ( V_16 | V_19 ) ) ==
( V_16 | V_19 ) )
return - V_22 ;
if ( ( V_8 -> V_15 & ( V_32 | V_33 ) ) == 0 )
return - V_22 ;
V_8 -> V_10 = F_5 ( F_6 ( V_25 [ V_29 ] ) ) ;
V_8 -> V_34 = F_7 ( V_25 [ V_28 ] ) ;
switch ( V_8 -> V_10 ) {
case V_11 :
if ( V_8 -> V_15 & V_19 )
return - V_22 ;
V_26 = sizeof( int ) ;
break;
case V_12 :
if ( V_8 -> V_15 & V_19 )
return - V_22 ;
V_26 = V_35 ;
break;
case V_14 :
V_26 = sizeof( V_36 ) ;
break;
default:
return - V_22 ;
}
V_27 = F_8 ( V_2 , V_8 -> V_34 , NULL ,
V_37 , V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_1 ( V_2 , V_4 , NULL ) ;
}
int F_9 ( struct V_38 * V_39 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_10 ( V_39 , V_28 , V_8 -> V_34 ) )
return - 1 ;
if ( F_11 ( V_39 , V_29 , F_12 ( V_8 -> V_10 ) ) )
return - 1 ;
if ( F_11 ( V_39 , V_30 , F_12 ( V_8 -> V_15 ) ) )
return - 1 ;
return 0 ;
}
void F_13 ( void * V_40 , enum V_41 V_42 ,
const struct V_43 * V_44 , int V_45 )
{
struct V_46 * V_47 ;
V_36 * V_34 = V_40 ;
switch ( V_42 ) {
case V_11 :
* V_34 = V_45 ;
break;
case V_12 :
V_47 = F_14 ( F_15 ( V_44 ) , V_45 ) ;
strncpy ( V_40 , V_47 ? V_47 -> V_48 : L_1 , V_35 ) ;
break;
default:
F_16 ( 1 ) ;
* V_34 = 0 ;
break;
}
}
