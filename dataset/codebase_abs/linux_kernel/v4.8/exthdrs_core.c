bool F_1 ( T_1 V_1 )
{
return ( V_1 == V_2 ) ||
( V_1 == V_3 ) ||
( V_1 == V_4 ) ||
( V_1 == V_5 ) ||
( V_1 == V_6 ) ||
( V_1 == V_7 ) ;
}
int F_2 ( const struct V_8 * V_9 , int V_10 , T_1 * V_11 ,
T_2 * V_12 )
{
T_1 V_1 = * V_11 ;
* V_12 = 0 ;
while ( F_1 ( V_1 ) ) {
struct V_13 V_14 , * V_15 ;
int V_16 ;
if ( V_1 == V_6 )
return - 1 ;
V_15 = F_3 ( V_9 , V_10 , sizeof( V_14 ) , & V_14 ) ;
if ( ! V_15 )
return - 1 ;
if ( V_1 == V_4 ) {
T_2 V_17 , * V_18 ;
V_18 = F_3 ( V_9 ,
V_10 + F_4 ( struct V_19 ,
V_20 ) ,
sizeof( V_17 ) ,
& V_17 ) ;
if ( ! V_18 )
return - 1 ;
* V_12 = * V_18 ;
if ( F_5 ( * V_12 ) & ~ 0x7 )
break;
V_16 = 8 ;
} else if ( V_1 == V_5 )
V_16 = ( V_15 -> V_16 + 2 ) << 2 ;
else
V_16 = F_6 ( V_15 ) ;
V_1 = V_15 -> V_1 ;
V_10 += V_16 ;
}
* V_11 = V_1 ;
return V_10 ;
}
int F_7 ( const struct V_8 * V_9 , int V_21 , int type )
{
const unsigned char * V_22 = F_8 ( V_9 ) ;
int V_23 = F_9 ( V_9 ) - F_8 ( V_9 ) ;
struct V_13 * V_24 ;
int V_25 ;
if ( V_21 + 2 > V_23 )
goto V_26;
V_24 = (struct V_13 * ) ( V_22 + V_21 ) ;
V_25 = ( ( V_24 -> V_16 + 1 ) << 3 ) ;
if ( V_21 + V_25 > V_23 )
goto V_26;
V_21 += 2 ;
V_25 -= 2 ;
while ( V_25 > 0 ) {
int V_27 = V_22 [ V_21 ] ;
int V_28 ;
if ( V_27 == type )
return V_21 ;
switch ( V_27 ) {
case V_29 :
V_28 = 1 ;
break;
default:
V_28 = V_22 [ V_21 + 1 ] + 2 ;
if ( V_28 > V_25 )
goto V_26;
break;
}
V_21 += V_28 ;
V_25 -= V_28 ;
}
V_26:
return - 1 ;
}
int F_10 ( const struct V_8 * V_9 , unsigned int * V_21 ,
int V_30 , unsigned short * V_31 , int * V_32 )
{
unsigned int V_10 = F_11 ( V_9 ) + sizeof( struct V_33 ) ;
T_1 V_1 = F_12 ( V_9 ) -> V_1 ;
unsigned int V_25 ;
bool V_34 ;
if ( V_31 )
* V_31 = 0 ;
if ( * V_21 ) {
struct V_33 V_35 , * V_36 ;
V_36 = F_3 ( V_9 , * V_21 , sizeof( V_35 ) , & V_35 ) ;
if ( ! V_36 || ( V_36 -> V_37 != 6 ) ) {
F_13 ( V_38 L_1 ) ;
return - V_39 ;
}
V_10 = * V_21 + sizeof( struct V_33 ) ;
V_1 = V_36 -> V_1 ;
}
V_25 = V_9 -> V_25 - V_10 ;
do {
struct V_13 V_14 , * V_15 ;
unsigned int V_16 ;
V_34 = ( V_1 == V_30 ) ;
if ( ( ! F_1 ( V_1 ) ) || V_1 == V_6 ) {
if ( V_30 < 0 || V_34 )
break;
return - V_40 ;
}
V_15 = F_3 ( V_9 , V_10 , sizeof( V_14 ) , & V_14 ) ;
if ( ! V_15 )
return - V_39 ;
if ( V_1 == V_3 ) {
struct V_41 V_42 , * V_43 ;
V_43 = F_3 ( V_9 , V_10 , sizeof( V_42 ) ,
& V_42 ) ;
if ( ! V_43 )
return - V_39 ;
if ( V_32 && ( * V_32 & V_44 ) &&
V_43 -> V_45 == 0 )
V_34 = false ;
}
if ( V_1 == V_4 ) {
unsigned short V_17 ;
T_2 * V_18 ;
if ( V_32 )
* V_32 |= V_46 ;
V_18 = F_3 ( V_9 ,
V_10 + F_4 ( struct V_19 ,
V_20 ) ,
sizeof( V_17 ) ,
& V_17 ) ;
if ( ! V_18 )
return - V_39 ;
V_17 = F_5 ( * V_18 ) & ~ 0x7 ;
if ( V_17 ) {
if ( V_30 < 0 &&
( ( ! F_1 ( V_15 -> V_1 ) ) ||
V_15 -> V_1 == V_6 ) ) {
if ( V_31 )
* V_31 = V_17 ;
return V_15 -> V_1 ;
}
if ( ! V_34 )
return - V_40 ;
if ( V_31 )
* V_31 = V_17 ;
break;
}
V_16 = 8 ;
} else if ( V_1 == V_5 ) {
if ( V_32 && ( * V_32 & V_47 ) && ( V_30 < 0 ) )
break;
V_16 = ( V_15 -> V_16 + 2 ) << 2 ;
} else
V_16 = F_6 ( V_15 ) ;
if ( ! V_34 ) {
V_1 = V_15 -> V_1 ;
V_25 -= V_16 ;
V_10 += V_16 ;
}
} while ( ! V_34 );
* V_21 = V_10 ;
return V_1 ;
}
