static void F_1 ( T_1 V_1 [] )
{
if ( V_2 . V_3 == V_4 )
V_1 [ V_5 ] = V_6 ;
else if ( V_2 . V_3 == V_7 ||
V_2 . V_3 == V_8 )
V_1 [ V_5 ] = V_9 ;
else if ( V_2 . V_3 >= V_10 )
V_1 [ V_5 ] = V_11 ;
}
T_1
F_2 ( T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_1 [] )
{
T_1 V_15 , V_16 ;
T_1 V_17 ;
F_3 ( sizeof( int ) == 4 ) ;
F_1 ( V_1 ) ;
V_17 = V_1 [ V_5 ] ;
V_15 = F_4 ( V_12 ) ;
if ( V_15 == 1 ) {
if ( V_17 & V_11 )
V_16 = F_5 ( V_12 ) ;
else
V_16 = F_6 ( V_12 ) ;
}
else
V_16 = F_7 ( V_12 ) ;
if ( V_18 ) F_8 ( L_1 , V_15 , V_16 ) ;
switch ( V_13 ) {
case V_19 :
case V_20 :
return ( F_9 ( V_12 , V_15 , V_16 , V_1 ) ) ;
case V_21 :
return ( F_10 ( V_12 , V_15 , V_16 , V_1 ) ) ;
case V_22 :
return ( F_11 ( V_12 , V_1 ) ) ;
case V_23 :
return ( F_12 ( V_12 , V_1 ) ) ;
case V_24 :
return ( F_13 ( V_12 , V_1 ) ) ;
default:
return ( V_25 ) ;
}
}
T_1
F_14 ( T_1 V_12 , T_1 V_26 , T_1 V_27 , T_1 V_1 [] )
{
T_1 V_15 , V_16 , V_28 ;
T_1 V_17 ;
F_3 ( sizeof( int ) == 4 ) ;
V_17 = V_1 [ V_5 ] ;
V_28 = F_15 ( V_12 ) ;
V_15 = F_4 ( V_12 ) ;
if ( V_15 == 1 ) {
if ( V_17 & V_11 )
V_16 = F_5 ( V_12 ) ;
else
V_16 = F_6 ( V_12 ) ;
}
else
V_16 = F_7 ( V_12 ) ;
switch ( V_28 ) {
case 0x0C :
return ( F_9 ( V_12 , V_15 , V_16 , V_1 ) ) ;
case 0x0E :
return ( F_10 ( V_12 , V_15 , V_16 , V_1 ) ) ;
case 0x06 :
return ( F_11 ( V_12 , V_1 ) ) ;
case 0x26 :
return ( F_12 ( V_12 , V_1 ) ) ;
case 0x2E :
return ( F_13 ( V_12 , V_1 ) ) ;
default:
return ( V_20 ) ;
}
}
static T_1
F_9 ( T_1 V_12 , T_1 V_15 , T_1 V_16 , T_1 V_1 [] )
{
T_1 V_29 , V_30 , V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_1 * V_34 ;
T_1 V_35 , V_36 ;
T_1 V_17 ;
if ( V_12 == V_37 ) {
V_1 [ 0 ] = V_38 << 11 ;
return ( V_39 ) ;
}
V_34 = & V_1 [ 0 ] ;
V_36 = V_1 [ 0 ] ;
V_29 = F_16 ( V_12 , V_40 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_29 == 0 )
V_29 = V_41 ;
V_31 = F_16 ( V_12 , V_42 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_31 == 0 && V_15 != 2 )
return ( V_19 ) ;
V_32 = F_16 ( V_12 , V_43 , 2 ) ;
switch ( V_15 ) {
case 0 :
switch ( V_16 ) {
case 0 :
case 1 :
return ( V_19 ) ;
case 2 :
switch ( V_32 ) {
case 2 :
return ( V_19 ) ;
case 3 :
V_31 &= ~ 3 ;
V_29 &= ~ 3 ;
V_1 [ V_31 + 3 ] = V_1 [ V_29 + 3 ] ;
V_1 [ V_31 + 2 ] = V_1 [ V_29 + 2 ] ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] ;
return ( V_39 ) ;
}
case 3 :
switch ( V_32 ) {
case 2 :
return ( V_19 ) ;
case 3 :
V_31 &= ~ 3 ;
V_29 &= ~ 3 ;
V_1 [ V_31 + 3 ] = V_1 [ V_29 + 3 ] ;
V_1 [ V_31 + 2 ] = V_1 [ V_29 + 2 ] ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] & 0x7fffffff ;
return ( V_39 ) ;
}
case 6 :
switch ( V_32 ) {
case 2 :
return ( V_19 ) ;
case 3 :
V_31 &= ~ 3 ;
V_29 &= ~ 3 ;
V_1 [ V_31 + 3 ] = V_1 [ V_29 + 3 ] ;
V_1 [ V_31 + 2 ] = V_1 [ V_29 + 2 ] ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] ^ 0x80000000 ;
return ( V_39 ) ;
}
case 7 :
switch ( V_32 ) {
case 2 :
return ( V_19 ) ;
case 3 :
V_31 &= ~ 3 ;
V_29 &= ~ 3 ;
V_1 [ V_31 + 3 ] = V_1 [ V_29 + 3 ] ;
V_1 [ V_31 + 2 ] = V_1 [ V_29 + 2 ] ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] | 0x80000000 ;
return ( V_39 ) ;
}
case 4 :
switch ( V_32 ) {
case 0 :
return ( F_17 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_18 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
case 5 :
switch ( V_32 ) {
case 0 :
return ( F_19 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_20 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
}
case 1 :
V_33 = F_16 ( V_12 , V_44 , 2 ) ;
if ( ( V_33 & 2 ) || ( V_32 & 2 ) ) {
return ( V_19 ) ;
}
V_32 = ( V_32 << 1 ) | V_33 ;
switch ( V_16 ) {
case 0 :
switch( V_32 ) {
case 0 :
return ( V_19 ) ;
case 1 :
return ( F_21 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_22 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( V_19 ) ;
}
case 1 :
switch( V_32 ) {
case 0 :
return ( F_23 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_24 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_25 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_26 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 2 :
switch( V_32 ) {
case 0 :
return ( F_27 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_28 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_29 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_30 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 3 :
switch( V_32 ) {
case 0 :
return ( F_31 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_32 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_33 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_34 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 5 :
switch( V_32 ) {
case 0 :
return ( F_35 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_36 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_37 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_38 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 6 :
switch( V_32 ) {
case 0 :
return ( F_39 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_40 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_41 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_42 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 7 :
switch( V_32 ) {
case 0 :
return ( F_43 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_44 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_45 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_46 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 4 :
return ( V_19 ) ;
}
case 2 :
V_17 = V_1 [ V_5 ] ;
V_30 = F_16 ( V_12 , V_45 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_30 == 0 )
V_30 = V_41 ;
if ( V_17 & V_11 ) {
if ( F_16 ( V_12 , V_46 , 1 ) ) {
switch ( V_32 ) {
case 0 :
F_47 () ;
case 1 :
case 2 :
case 3 :
return ( V_19 ) ;
}
} else {
switch ( V_32 ) {
case 0 :
V_35 = F_48 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
case 1 :
V_35 = F_50 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
}
}
else {
switch ( V_16 ) {
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 7 :
return ( V_19 ) ;
case 0 :
switch ( V_32 ) {
case 0 :
V_35 = F_48 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
case 1 :
V_35 = F_50 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
case 1 :
switch ( V_32 ) {
case 0 :
F_47 () ;
case 1 :
case 2 :
case 3 :
return ( V_19 ) ;
}
}
}
case 3 :
V_30 = F_16 ( V_12 , V_45 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_30 == 0 )
V_30 = V_41 ;
switch ( V_16 ) {
case 5 :
case 6 :
case 7 :
return ( V_19 ) ;
case 0 :
switch ( V_32 ) {
case 0 :
return ( F_51 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_52 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
case 1 :
switch ( V_32 ) {
case 0 :
return ( F_53 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_54 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
case 2 :
switch ( V_32 ) {
case 0 :
return ( F_55 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_56 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
case 3 :
switch ( V_32 ) {
case 0 :
return ( F_57 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_58 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
case 4 :
switch ( V_32 ) {
case 0 :
return ( F_59 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_60 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_19 ) ;
}
}
}
return ( V_19 ) ;
}
static T_1
F_10 ( V_12 , V_15 , V_16 , V_1 )
T_1 V_12 , V_15 , V_16 ;
T_1 V_1 [] ;
{
T_1 V_29 , V_30 , V_31 ;
T_1 V_32 ;
T_1 V_33 ;
T_1 * V_34 ;
T_1 V_35 , V_36 ;
T_1 V_17 ;
V_34 = & V_1 [ 0 ] ;
V_36 = V_1 [ 0 ] ;
V_29 = ( ( F_16 ( V_12 , V_40 , 5 ) << 1 ) | ( F_16 ( V_12 , V_47 , 1 ) ) ) ;
if ( V_29 == 0 )
V_29 = V_41 ;
V_31 = ( ( F_16 ( V_12 , V_42 , 5 ) << 1 ) | ( F_16 ( V_12 , V_48 , 1 ) ) ) ;
if ( V_31 == 0 && V_15 != 2 )
return ( V_21 ) ;
if ( V_15 < 2 )
V_32 = F_16 ( V_12 , V_43 , 2 ) ;
else
V_32 = F_16 ( V_12 , V_49 , 1 ) ;
if ( V_32 == V_50 ) {
V_29 &= ~ 1 ;
if ( V_15 != 1 )
V_31 &= ~ 1 ;
}
switch ( V_15 ) {
case 0 :
switch ( V_16 ) {
case 0 :
case 1 :
return ( V_21 ) ;
case 2 :
switch ( V_32 ) {
case 2 :
case 3 :
return ( V_21 ) ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] ;
return ( V_39 ) ;
}
case 3 :
switch ( V_32 ) {
case 2 :
case 3 :
return ( V_21 ) ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] & 0x7fffffff ;
return ( V_39 ) ;
}
case 6 :
switch ( V_32 ) {
case 2 :
case 3 :
return ( V_21 ) ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] ^ 0x80000000 ;
return ( V_39 ) ;
}
case 7 :
switch ( V_32 ) {
case 2 :
case 3 :
return ( V_21 ) ;
case 1 :
V_1 [ V_31 + 1 ] = V_1 [ V_29 + 1 ] ;
case 0 :
V_1 [ V_31 ] = V_1 [ V_29 ] | 0x80000000 ;
return ( V_39 ) ;
}
case 4 :
switch ( V_32 ) {
case 0 :
return ( F_17 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_18 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_21 ) ;
}
case 5 :
switch ( V_32 ) {
case 0 :
return ( F_19 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_20 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
case 3 :
return ( V_21 ) ;
}
}
case 1 :
V_33 = F_16 ( V_12 , V_44 , 2 ) ;
if ( V_33 == V_50 ) {
V_31 &= ~ 1 ;
}
if ( ( V_33 & 2 ) || ( V_32 & 2 ) )
return ( V_21 ) ;
V_32 = ( V_32 << 1 ) | V_33 ;
switch ( V_16 ) {
case 0 :
switch( V_32 ) {
case 0 :
return ( V_21 ) ;
case 1 :
return ( F_21 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_22 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( V_21 ) ;
}
case 1 :
switch( V_32 ) {
case 0 :
return ( F_23 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_24 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_25 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_26 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 2 :
switch( V_32 ) {
case 0 :
return ( F_27 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_28 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_29 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_30 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 3 :
switch( V_32 ) {
case 0 :
return ( F_31 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_32 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_33 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_34 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 5 :
switch( V_32 ) {
case 0 :
return ( F_35 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_36 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_37 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_38 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 6 :
switch( V_32 ) {
case 0 :
return ( F_39 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_40 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_41 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_42 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 7 :
switch( V_32 ) {
case 0 :
return ( F_43 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_44 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 2 :
return ( F_45 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 3 :
return ( F_46 ( & V_1 [ V_29 ] , 0 ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 4 :
return ( V_19 ) ;
}
case 2 :
if ( V_32 == V_50 )
V_30 = ( F_16 ( V_12 , V_45 , 5 ) << 1 ) ;
else
V_30 = ( ( F_16 ( V_12 , V_45 , 5 ) << 1 ) | ( F_16 ( V_12 , V_51 , 1 ) ) ) ;
V_17 = V_1 [ V_5 ] ;
if ( V_30 == 0 )
V_30 = V_41 ;
if ( V_17 & V_11 ) {
if ( F_16 ( V_12 , V_46 , 1 ) ) {
return ( V_21 ) ;
} else {
switch ( V_32 ) {
case 0 :
V_35 = F_48 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
case 1 :
V_35 = F_50 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
}
}
}
else {
switch ( V_16 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 7 :
return ( V_21 ) ;
case 0 :
switch ( V_32 ) {
case 0 :
V_35 = F_48 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
case 1 :
V_35 = F_50 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , F_16 ( V_12 , V_42 , 5 ) ,
& V_36 ) ;
F_49 ( V_34 , V_36 ,
V_17 , V_16 ) ;
return ( V_35 ) ;
}
}
}
case 3 :
if ( V_32 == V_50 )
V_30 = ( F_16 ( V_12 , V_45 , 5 ) << 1 ) ;
else
V_30 = ( ( F_16 ( V_12 , V_45 , 5 ) << 1 ) | ( F_16 ( V_12 , V_51 , 1 ) ) ) ;
if ( V_30 == 0 )
V_30 = V_41 ;
switch ( V_16 ) {
case 5 :
case 6 :
case 7 :
return ( V_21 ) ;
case 0 :
switch ( V_32 ) {
case 0 :
return ( F_51 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_52 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 1 :
switch ( V_32 ) {
case 0 :
return ( F_53 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_54 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 2 :
if ( F_16 ( V_12 , V_52 , 1 ) ) {
switch ( V_32 ) {
case 0 :
if ( V_31 & 1 )
return ( V_21 ) ;
F_47 () ;
return ( V_39 ) ;
case 1 :
return ( V_21 ) ;
}
}
else {
switch ( V_32 ) {
case 0 :
return ( F_55 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , & V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_56 ( & V_1 [ V_29 ] ,
& V_1 [ V_30 ] , & V_1 [ V_31 ] , V_34 ) ) ;
}
}
case 3 :
switch ( V_32 ) {
case 0 :
return ( F_57 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_58 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
case 4 :
switch ( V_32 ) {
case 0 :
return ( F_59 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
case 1 :
return ( F_60 ( & V_1 [ V_29 ] , & V_1 [ V_30 ] ,
& V_1 [ V_31 ] , V_34 ) ) ;
}
}
}
return ( V_21 ) ;
}
static T_1
F_11 ( V_12 , V_1 )
T_1 V_12 ;
T_1 V_1 [] ;
{
T_1 V_53 , V_54 , V_55 , V_56 , V_57 ;
T_1 V_32 ;
T_1 error = 0 ;
T_1 V_34 ;
T_1 V_17 ;
union {
double V_58 ;
float V_59 ;
struct { T_1 V_60 ; T_1 V_61 ; } V_62 ;
} V_63 , V_64 ;
V_34 = V_1 [ 0 ] ;
V_17 = V_1 [ V_5 ] ;
V_32 = F_16 ( V_12 , V_65 , 1 ) ;
if ( V_32 == 0 ) {
V_53 = F_16 ( V_12 , V_66 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_53 == 0 )
V_53 = V_41 ;
V_54 = F_16 ( V_12 , V_67 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_54 == 0 )
V_54 = V_41 ;
V_55 = F_16 ( V_12 , V_68 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_55 == 0 )
return ( V_22 ) ;
V_56 = F_16 ( V_12 , V_69 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
V_57 = F_16 ( V_12 , V_70 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_57 == 0 )
return ( V_22 ) ;
if ( V_17 & V_71 ) {
if ( V_56 == 0 ) {
if ( F_56 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] ,
& V_63 . V_62 . V_60 , & V_34 ) )
error = 1 ;
if ( F_33 ( & V_1 [ V_57 ] ,
& V_64 . V_62 . V_60 , & V_64 . V_62 . V_60 , & V_34 ) )
error = 1 ;
}
else {
if ( F_56 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] , & V_63 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
if ( F_52 ( & V_1 [ V_57 ] , & V_1 [ V_56 ] , & V_64 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
}
}
else
{
if ( V_56 == 0 )
V_56 = V_41 ;
if ( F_56 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] , & V_63 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
if ( F_52 ( & V_1 [ V_57 ] , & V_1 [ V_56 ] , & V_64 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
}
if ( error )
return ( V_22 ) ;
else {
V_1 [ V_55 ] = V_63 . V_62 . V_60 ;
V_1 [ V_55 + 1 ] = V_63 . V_62 . V_61 ;
V_1 [ V_57 ] = V_64 . V_62 . V_60 ;
V_1 [ V_57 + 1 ] = V_64 . V_62 . V_61 ;
V_1 [ 0 ] = V_34 ;
return ( V_39 ) ;
}
}
else {
V_53 = ( F_16 ( V_12 , V_66 , 4 ) | 0x10 ) << 1 ;
V_53 |= F_16 ( V_12 , V_66 - 4 , 1 ) ;
V_54 = ( F_16 ( V_12 , V_67 , 4 ) | 0x10 ) << 1 ;
V_54 |= F_16 ( V_12 , V_67 - 4 , 1 ) ;
V_55 = ( F_16 ( V_12 , V_68 , 4 ) | 0x10 ) << 1 ;
V_55 |= F_16 ( V_12 , V_68 - 4 , 1 ) ;
V_56 = ( F_16 ( V_12 , V_69 , 4 ) | 0x10 ) << 1 ;
V_56 |= F_16 ( V_12 , V_69 - 4 , 1 ) ;
V_57 = ( F_16 ( V_12 , V_70 , 4 ) | 0x10 ) << 1 ;
V_57 |= F_16 ( V_12 , V_70 - 4 , 1 ) ;
if ( V_56 == 0x20 && ( V_17 & V_71 ) ) {
if ( F_55 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] , & V_63 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
if ( F_31 ( & V_1 [ V_57 ] , & V_64 . V_62 . V_60 ,
& V_64 . V_62 . V_60 , & V_34 ) )
error = 1 ;
}
else {
if ( F_55 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] , & V_63 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
if ( F_51 ( & V_1 [ V_57 ] , & V_1 [ V_56 ] , & V_64 . V_62 . V_60 ,
& V_34 ) )
error = 1 ;
}
if ( error )
return ( V_22 ) ;
else {
V_1 [ V_55 ] = V_63 . V_62 . V_60 ;
V_1 [ V_57 ] = V_64 . V_62 . V_60 ;
V_1 [ 0 ] = V_34 ;
return ( V_39 ) ;
}
}
}
static T_1
F_12 ( V_12 , V_1 )
T_1 V_12 ;
T_1 V_1 [] ;
{
T_1 V_53 , V_54 , V_55 , V_56 , V_57 ;
T_1 V_32 ;
T_1 error = 0 ;
T_1 V_34 ;
union {
double V_58 ;
float V_59 ;
struct { T_1 V_60 ; T_1 V_61 ; } V_62 ;
} V_63 , V_64 ;
V_34 = V_1 [ 0 ] ;
V_32 = F_16 ( V_12 , V_65 , 1 ) ;
if ( V_32 == 0 ) {
V_53 = F_16 ( V_12 , V_66 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_53 == 0 )
V_53 = V_41 ;
V_54 = F_16 ( V_12 , V_67 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_54 == 0 )
V_54 = V_41 ;
V_55 = F_16 ( V_12 , V_68 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_55 == 0 )
return ( V_23 ) ;
V_56 = F_16 ( V_12 , V_69 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_56 == 0 )
return ( V_23 ) ;
V_57 = F_16 ( V_12 , V_70 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_57 == 0 )
return ( V_23 ) ;
if ( F_56 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] , & V_63 . V_62 . V_60 , & V_34 ) )
error = 1 ;
if ( F_54 ( & V_1 [ V_57 ] , & V_1 [ V_56 ] , & V_64 . V_62 . V_60 , & V_34 ) )
error = 1 ;
if ( error )
return ( V_23 ) ;
else {
V_1 [ V_55 ] = V_63 . V_62 . V_60 ;
V_1 [ V_55 + 1 ] = V_63 . V_62 . V_61 ;
V_1 [ V_57 ] = V_64 . V_62 . V_60 ;
V_1 [ V_57 + 1 ] = V_64 . V_62 . V_61 ;
V_1 [ 0 ] = V_34 ;
return ( V_39 ) ;
}
}
else {
V_53 = ( F_16 ( V_12 , V_66 , 4 ) | 0x10 ) << 1 ;
V_53 |= F_16 ( V_12 , V_66 - 4 , 1 ) ;
V_54 = ( F_16 ( V_12 , V_67 , 4 ) | 0x10 ) << 1 ;
V_54 |= F_16 ( V_12 , V_67 - 4 , 1 ) ;
V_55 = ( F_16 ( V_12 , V_68 , 4 ) | 0x10 ) << 1 ;
V_55 |= F_16 ( V_12 , V_68 - 4 , 1 ) ;
V_56 = ( F_16 ( V_12 , V_69 , 4 ) | 0x10 ) << 1 ;
V_56 |= F_16 ( V_12 , V_69 - 4 , 1 ) ;
V_57 = ( F_16 ( V_12 , V_70 , 4 ) | 0x10 ) << 1 ;
V_57 |= F_16 ( V_12 , V_70 - 4 , 1 ) ;
if ( F_55 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] , & V_63 . V_62 . V_60 , & V_34 ) )
error = 1 ;
if ( F_53 ( & V_1 [ V_57 ] , & V_1 [ V_56 ] , & V_64 . V_62 . V_60 , & V_34 ) )
error = 1 ;
if ( error )
return ( V_23 ) ;
else {
V_1 [ V_55 ] = V_63 . V_62 . V_60 ;
V_1 [ V_57 ] = V_64 . V_62 . V_60 ;
V_1 [ 0 ] = V_34 ;
return ( V_39 ) ;
}
}
}
static T_1
F_13 ( V_12 , V_1 )
T_1 V_12 ;
T_1 V_1 [] ;
{
T_1 V_53 , V_54 , V_56 , V_31 ;
T_1 V_32 ;
V_32 = F_16 ( V_12 , V_43 , 1 ) ;
if ( V_32 == V_50 ) {
V_53 = F_16 ( V_12 , V_66 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_53 == 0 )
V_53 = V_41 ;
V_54 = F_16 ( V_12 , V_67 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_54 == 0 )
V_54 = V_41 ;
V_56 = ( ( F_16 ( V_12 , V_72 , 3 ) << 2 ) | ( F_16 ( V_12 , V_73 , 3 ) >> 1 ) ) *
sizeof( double ) / sizeof( T_1 ) ;
if ( V_56 == 0 )
V_56 = V_41 ;
V_31 = F_16 ( V_12 , V_42 , 5 ) * sizeof( double ) / sizeof( T_1 ) ;
if ( V_31 == 0 )
return ( V_24 ) ;
if ( F_16 ( V_12 , V_74 , 1 ) ) {
return ( F_61 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] ,
& V_1 [ V_56 ] , & V_1 [ 0 ] , & V_1 [ V_31 ] ) ) ;
} else {
return ( F_62 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] ,
& V_1 [ V_56 ] , & V_1 [ 0 ] , & V_1 [ V_31 ] ) ) ;
}
}
else {
V_53 = ( F_16 ( V_12 , V_66 , 5 ) << 1 ) | ( F_16 ( V_12 , V_75 , 1 ) ) ;
if ( V_53 == 0 )
V_53 = V_41 ;
V_54 = ( F_16 ( V_12 , V_67 , 5 ) << 1 ) | ( F_16 ( V_12 , V_76 , 1 ) ) ;
if ( V_54 == 0 )
V_54 = V_41 ;
V_56 = ( F_16 ( V_12 , V_72 , 3 ) << 3 ) | F_16 ( V_12 , V_73 , 3 ) ;
if ( V_56 == 0 )
V_56 = V_41 ;
V_31 = ( ( F_16 ( V_12 , V_42 , 5 ) << 1 ) | ( F_16 ( V_12 , V_48 , 1 ) ) ) ;
if ( V_31 == 0 )
return ( V_24 ) ;
if ( F_16 ( V_12 , V_74 , 1 ) ) {
return ( F_63 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] ,
& V_1 [ V_56 ] , & V_1 [ 0 ] , & V_1 [ V_31 ] ) ) ;
} else {
return ( F_64 ( & V_1 [ V_53 ] , & V_1 [ V_54 ] ,
& V_1 [ V_56 ] , & V_1 [ 0 ] , & V_1 [ V_31 ] ) ) ;
}
}
}
static void
F_49 ( V_34 , T_2 , T_3 , T_4 )
T_1 * V_34 , T_2 ;
T_1 T_3 ;
T_1 T_4 ;
{
if ( ( T_3 & V_6 ) ||
( T_3 & V_9 ) ||
( T_3 & V_11 ) ) {
if ( T_4 == 0 ) {
* V_34 = ( ( * V_34 & 0x04000000 ) >> 5 ) |
( ( * V_34 & 0x003ff000 ) >> 1 ) |
( T_2 & 0xffc007ff ) ;
} else {
* V_34 = ( * V_34 & 0x04000000 ) |
( ( T_2 & 0x04000000 ) >> ( T_4 + 4 ) ) |
( T_2 & ~ 0x04000000 &
~ ( 0x04000000 >> ( T_4 + 4 ) ) ) ;
}
}
else {
* V_34 = T_2 ;
}
}
