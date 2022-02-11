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
if ( V_15 == NULL )
return - 1 ;
if ( V_1 == V_4 ) {
T_2 V_17 , * V_18 ;
V_18 = F_3 ( V_9 ,
V_10 + F_4 ( struct V_19 ,
V_20 ) ,
sizeof( V_17 ) ,
& V_17 ) ;
if ( V_18 == NULL )
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
int F_7 ( struct V_8 * V_9 , int V_21 , int type )
{
const unsigned char * V_22 = F_8 ( V_9 ) ;
int V_23 = V_9 -> V_24 - V_9 -> V_25 ;
struct V_13 * V_26 ;
int V_27 ;
if ( V_21 + 2 > V_23 )
goto V_28;
V_26 = (struct V_13 * ) ( V_22 + V_21 ) ;
V_27 = ( ( V_26 -> V_16 + 1 ) << 3 ) ;
if ( V_21 + V_27 > V_23 )
goto V_28;
V_21 += 2 ;
V_27 -= 2 ;
while ( V_27 > 0 ) {
int V_29 = V_22 [ V_21 ] ;
int V_30 ;
if ( V_29 == type )
return V_21 ;
switch ( V_29 ) {
case V_31 :
V_30 = 1 ;
break;
default:
V_30 = V_22 [ V_21 + 1 ] + 2 ;
if ( V_30 > V_27 )
goto V_28;
break;
}
V_21 += V_30 ;
V_27 -= V_30 ;
}
V_28:
return - 1 ;
}
int F_9 ( const struct V_8 * V_9 , unsigned int * V_21 ,
int V_32 , unsigned short * V_33 , int * V_34 )
{
unsigned int V_10 = F_10 ( V_9 ) + sizeof( struct V_35 ) ;
T_1 V_1 = F_11 ( V_9 ) -> V_1 ;
unsigned int V_27 ;
bool V_36 ;
if ( V_33 )
* V_33 = 0 ;
if ( * V_21 ) {
struct V_35 V_37 , * V_38 ;
V_38 = F_3 ( V_9 , * V_21 , sizeof( V_37 ) , & V_37 ) ;
if ( ! V_38 || ( V_38 -> V_39 != 6 ) ) {
F_12 ( V_40 L_1 ) ;
return - V_41 ;
}
V_10 = * V_21 + sizeof( struct V_35 ) ;
V_1 = V_38 -> V_1 ;
}
V_27 = V_9 -> V_27 - V_10 ;
do {
struct V_13 V_14 , * V_15 ;
unsigned int V_16 ;
V_36 = ( V_1 == V_32 ) ;
if ( ( ! F_1 ( V_1 ) ) || V_1 == V_6 ) {
if ( V_32 < 0 )
break;
return - V_42 ;
}
V_15 = F_3 ( V_9 , V_10 , sizeof( V_14 ) , & V_14 ) ;
if ( V_15 == NULL )
return - V_41 ;
if ( V_1 == V_3 ) {
struct V_43 V_44 , * V_45 ;
V_45 = F_3 ( V_9 , V_10 , sizeof( V_44 ) ,
& V_44 ) ;
if ( V_45 == NULL )
return - V_41 ;
if ( V_34 && ( * V_34 & V_46 ) &&
V_45 -> V_47 == 0 )
V_36 = false ;
}
if ( V_1 == V_4 ) {
unsigned short V_17 ;
T_2 * V_18 ;
if ( V_34 )
* V_34 |= V_48 ;
V_18 = F_3 ( V_9 ,
V_10 + F_4 ( struct V_19 ,
V_20 ) ,
sizeof( V_17 ) ,
& V_17 ) ;
if ( V_18 == NULL )
return - V_41 ;
V_17 = F_5 ( * V_18 ) & ~ 0x7 ;
if ( V_17 ) {
if ( V_32 < 0 &&
( ( ! F_1 ( V_15 -> V_1 ) ) ||
V_15 -> V_1 == V_6 ) ) {
if ( V_33 )
* V_33 = V_17 ;
return V_15 -> V_1 ;
}
return - V_42 ;
}
V_16 = 8 ;
} else if ( V_1 == V_5 ) {
if ( V_34 && ( * V_34 & V_49 ) && ( V_32 < 0 ) )
break;
V_16 = ( V_15 -> V_16 + 2 ) << 2 ;
} else
V_16 = F_6 ( V_15 ) ;
if ( ! V_36 ) {
V_1 = V_15 -> V_1 ;
V_27 -= V_16 ;
V_10 += V_16 ;
}
} while ( ! V_36 );
* V_21 = V_10 ;
return V_1 ;
}
