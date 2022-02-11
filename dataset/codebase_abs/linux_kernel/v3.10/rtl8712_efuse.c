static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 ;
if ( true == V_3 ) {
V_4 = F_2 ( V_2 , V_5 + 3 ) ;
V_4 |= 0x80 ;
F_3 ( V_2 , V_5 + 3 , V_4 ) ;
F_4 ( 20 ) ;
F_3 ( V_2 , V_6 , 0x03 ) ;
F_4 ( 20 ) ;
} else {
V_4 = F_2 ( V_2 , V_5 + 3 ) ;
V_4 &= 0x7F ;
F_3 ( V_2 , V_5 + 3 , V_4 ) ;
F_3 ( V_2 , V_6 , 0x02 ) ;
}
}
T_1 F_5 ( struct V_1 * V_2 )
{
return true ;
}
void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_2 V_7 , T_1 * V_8 )
{
T_1 V_9 = 0 , V_10 ;
F_3 ( V_2 , V_11 + 1 , ( T_1 ) ( V_7 & 0xFF ) ) ;
F_3 ( V_2 , V_11 + 2 , ( ( T_1 ) ( ( V_7 >> 8 ) & 0x03 ) ) |
( F_2 ( V_2 , V_11 + 2 ) & 0xFC ) ) ;
F_3 ( V_2 , V_11 + 3 , 0x72 ) ;
while ( ! ( 0x80 & F_2 ( V_2 , V_11 + 3 ) ) && ( V_9 < 100 ) )
V_9 ++ ;
if ( V_9 < 100 ) {
* V_8 = F_2 ( V_2 , V_11 ) ;
V_10 = true ;
} else {
* V_8 = 0xff ;
V_10 = false ;
}
return V_10 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_2 V_7 , T_1 V_8 )
{
T_1 V_9 = 0 , V_10 ;
F_3 ( V_2 , V_11 + 1 , ( T_1 ) ( V_7 & 0xFF ) ) ;
F_3 ( V_2 , V_11 + 2 , ( ( T_1 ) ( ( V_7 >> 8 ) & 0x03 ) ) |
( F_2 ( V_2 , V_11 + 2 ) & 0xFC ) ) ;
F_3 ( V_2 , V_11 , V_8 ) ;
F_3 ( V_2 , V_11 + 3 , 0xF2 ) ;
while ( ( 0x80 & F_2 ( V_2 , V_11 + 3 ) ) && ( V_9 < 100 ) )
V_9 ++ ;
if ( V_9 < 100 )
V_10 = true ;
else
V_10 = false ;
return V_10 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_7 ,
T_1 * V_8 )
{
T_1 V_9 = 0 , V_13 = 0 , V_10 ;
F_3 ( V_2 , V_11 + 1 , ( T_1 ) ( V_7 & 0xFF ) ) ;
V_13 = ( ( T_1 ) ( ( V_7 >> 8 ) & 0x03 ) ) |
( F_2 ( V_2 , V_11 + 2 ) & 0xFC ) ;
F_3 ( V_2 , V_11 + 2 , V_13 ) ;
if ( true == V_12 ) {
F_3 ( V_2 , V_11 + 3 , 0x72 ) ;
while ( ! ( 0x80 & F_2 ( V_2 , V_11 + 3 ) ) &&
( V_9 < 100 ) )
V_9 ++ ;
if ( V_9 < 100 ) {
* V_8 = F_2 ( V_2 , V_11 ) ;
V_10 = true ;
} else {
* V_8 = 0 ;
V_10 = false ;
}
} else {
F_3 ( V_2 , V_11 , * V_8 ) ;
F_3 ( V_2 , V_11 + 3 , 0xF2 ) ;
while ( ( 0x80 & F_2 ( V_2 , V_11 + 3 ) ) &&
( V_9 < 100 ) )
V_9 ++ ;
if ( V_9 < 100 )
V_10 = true ;
else
V_10 = false ;
}
return V_10 ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 * V_14 )
{
T_1 V_15 , V_16 = true ;
if ( F_9 ( V_2 , true , 0 , & V_15 ) == true ) {
if ( 0xFF == V_15 )
* V_14 = true ;
else
* V_14 = false ;
} else
V_16 = false ;
return V_16 ;
}
void F_11 ( struct V_1 * V_2 )
{
T_2 V_17 = 0x1FB ;
T_2 V_18 ;
T_2 V_19 = 5 ;
T_1 V_20 [ 5 ] ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_7 ( V_2 , V_17 + V_18 ,
& V_20 [ V_18 ] ) ;
if ( ( V_20 [ 0 ] == 0x03 ) && ( V_20 [ 1 ] == 0x00 ) &&
( V_20 [ 2 ] == 0x00 ) && ( V_20 [ 3 ] == 0x00 ) &&
( V_20 [ 4 ] == 0x0C ) )
V_21 -= V_19 ;
}
int F_12 ( struct V_1 * V_2 )
{
return V_21 ;
}
static T_1 F_13 ( const T_1 V_22 )
{
T_1 V_23 = 0 ;
T_1 V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
if ( ! ( V_22 & F_14 ( V_24 ) ) )
V_23 ++ ;
return V_23 ;
}
static void F_15 ( const T_1 V_22 , const T_1 * V_26 ,
T_1 * V_27 )
{
T_1 V_28 = 0 ;
T_1 V_24 , V_29 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( ! ( V_22 & F_14 ( V_24 ) ) ) {
V_29 = V_24 * 2 ;
V_27 [ V_29 ] = V_26 [ V_28 ++ ] ;
V_27 [ V_29 + 1 ] = V_26 [ V_28 ++ ] ;
}
}
}
T_2 F_16 ( struct V_1 * V_2 )
{
int V_30 = true ;
T_2 V_31 = 0 ;
T_1 V_32 = 0 , V_33 = 0 ;
T_1 V_34 , V_23 = 0 ;
while ( V_30 && F_7 ( V_2 , V_31 ,
& V_34 ) && ( V_31 < V_21 ) ) {
if ( V_34 != 0xFF ) {
V_32 = ( V_34 >> 4 ) & 0x0F ;
V_33 = V_34 & 0x0F ;
V_23 = F_13 ( V_33 ) ;
V_31 = V_31 + ( V_23 * 2 ) + 1 ;
} else
V_30 = false ;
}
return V_31 ;
}
T_1 F_17 ( struct V_1 * V_2 , T_1 V_35 , T_1 * V_8 )
{
T_1 V_32 = 0 , V_33 = 0 , V_23 = 0 ;
T_2 V_31 = 0 ;
T_1 V_34 ;
T_1 V_9 = 0 ;
T_1 V_36 [ V_37 ] ;
T_1 V_16 = true ;
if ( V_8 == NULL )
return false ;
if ( V_35 > 0x0f )
return false ;
memset ( V_8 , 0xFF , sizeof( T_1 ) * V_37 ) ;
while ( V_31 < V_21 ) {
if ( F_7 ( V_2 , V_31 , & V_34 ) ==
true ) {
if ( V_34 == 0xFF )
break;
V_32 = ( V_34 >> 4 ) & 0x0F ;
V_33 = V_34 & 0x0F ;
V_23 = F_13 ( V_33 ) ;
if ( V_32 == V_35 ) {
memset ( V_36 , 0xFF , V_37 ) ;
for ( V_9 = 0 ; V_9 < V_23 * 2 ;
V_9 ++ ) {
if ( F_7 ( V_2 ,
V_31 + 1 + V_9 , & V_34 ) ==
true ) {
V_36 [ V_9 ] = V_34 ;
} else
V_16 = false ;
}
F_15 ( V_33 , V_36 , V_8 ) ;
}
V_31 += 1 + ( V_23 * 2 ) ;
} else {
V_16 = false ;
break;
}
}
return V_16 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_1 V_38 , T_2 V_39 )
{
struct V_40 V_41 ;
T_1 V_35 , V_22 , V_15 ;
T_2 V_7 ;
int V_18 ;
T_1 V_16 = true ;
V_41 . V_35 = F_19 ( V_38 ) ;
V_41 . V_22 = F_20 ( V_38 ) ;
V_7 = V_39 + 1 + F_13 ( V_41 . V_22 ) * 2 ;
if ( V_7 > V_21 )
return false ;
V_7 = 0 ;
while ( V_7 < V_39 ) {
if ( F_7 ( V_2 , V_7 ++ , & V_15 ) == false ) {
V_16 = false ;
break;
}
V_35 = F_19 ( V_15 ) ;
V_22 = F_20 ( V_15 ) ;
if ( V_41 . V_35 != V_35 ) {
V_7 += F_13 ( V_22 ) * 2 ;
continue;
}
for ( V_18 = 0 ; V_18 < V_25 ; V_18 ++ ) {
if ( F_14 ( V_18 ) & V_22 ) {
if ( F_14 ( V_18 ) & V_41 . V_22 ) {
if ( F_7 (
V_2 , V_7 ,
& V_15 ) == true )
V_41 . V_8 [ V_18 * 2 ] = V_15 ;
else
return false ;
if ( F_7 (
V_2 ,
V_7 + 1 ,
& V_15 ) == true )
V_41 . V_8 [ V_18 * 2 + 1 ] =
V_15 ;
else
return false ;
}
V_7 += 2 ;
}
}
}
if ( V_7 != V_39 )
return false ;
V_7 ++ ;
for ( V_18 = 0 ; V_18 < V_25 ; V_18 ++ ) {
if ( F_14 ( V_18 ) & V_41 . V_22 ) {
F_8 ( V_2 , V_7 , V_41 . V_8 [ V_18 * 2 ] ) ;
F_8 ( V_2 , V_7 + 1 ,
V_41 . V_8 [ V_18 * 2 + 1 ] ) ;
if ( F_7 ( V_2 , V_7 , & V_15 )
== false )
V_16 = false ;
else if ( V_41 . V_8 [ V_18 * 2 ] != V_15 ) {
V_16 = false ;
if ( 0xFF == V_15 )
F_8 ( V_2 , V_7 ,
V_41 . V_8 [ V_18 * 2 ] ) ;
}
if ( F_7 ( V_2 , V_7 + 1 , & V_15 ) ==
false )
V_16 = false ;
else if ( V_41 . V_8 [ V_18 * 2 + 1 ] != V_15 ) {
V_16 = false ;
if ( 0xFF == V_15 )
F_8 ( V_2 , V_7 + 1 ,
V_41 . V_8 [ V_18 * 2 + 1 ] ) ;
}
}
V_7 += 2 ;
}
return V_16 ;
}
T_1 F_21 ( struct V_1 * V_2 , const T_1 V_35 ,
const T_1 V_22 , const T_1 * V_8 )
{
T_1 V_42 = 0 ;
T_2 V_31 = 0 , V_43 = 0 ;
T_1 V_34 , V_44 = 0 ;
static int V_45 ;
int V_46 ;
T_1 V_10 = true ;
V_34 = F_2 ( V_2 , V_6 ) ;
if ( V_34 != 0x03 )
return false ;
V_42 = F_22 ( V_35 , V_22 ) ;
V_44 = F_13 ( V_22 ) ;
V_45 = 0 ;
V_31 = 0 ;
while ( V_31 < V_21 ) {
V_43 = F_16 ( V_2 ) ;
if ( ( V_43 + 1 + V_44 * 2 ) >
V_21 )
return false ;
V_31 = V_43 ;
F_8 ( V_2 , V_31 , V_42 ) ;
V_46 = 0 ;
while ( F_7 ( V_2 , V_31 ,
& V_34 ) == false ) {
if ( ++ V_46 > V_47 ) {
V_10 = false ;
break;
}
}
if ( ( V_46 > V_47 ) ||
( V_42 == V_34 ) ) {
T_1 V_18 ;
V_31 ++ ;
for ( V_18 = 0 ; V_18 < V_44 * 2 ; V_18 ++ ) {
F_8 ( V_2 ,
V_31 + V_18 ,
* ( V_8 + V_18 ) ) ;
if ( F_7 ( V_2 ,
V_31 + V_18 , & V_34 ) == false )
V_10 = false ;
else if ( * ( V_8 + V_18 ) != V_34 )
V_10 = false ;
}
break;
} else {
V_10 = false ;
if ( 0xFF == V_34 )
return V_10 ;
if ( F_18 ( V_2 , V_34 , V_31 ) ==
false )
return false ;
if ( ++ V_45 > V_47 )
break;
}
}
return V_10 ;
}
T_1 F_23 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_48 ,
T_2 V_49 , T_1 * V_8 )
{
int V_18 ;
T_1 V_50 = true ;
if ( V_48 > V_51 )
return false ;
if ( ( V_12 == false ) && ( ( V_48 + V_49 ) >
V_21 ) )
return false ;
if ( ( false == V_12 ) && ( F_5 ( V_2 ) == false ) )
return false ;
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ ) {
if ( ( V_48 + V_18 ) > V_51 ) {
V_50 = false ;
break;
}
V_50 = F_9 ( V_2 , V_12 , V_48 + V_18 ,
V_8 + V_18 ) ;
if ( ( false == V_12 ) && ( false == V_50 ) )
break;
}
if ( false == V_12 )
F_6 ( V_2 ) ;
return V_50 ;
}
T_1 F_24 ( struct V_1 * V_2 , T_2 V_7 , T_2 V_49 , T_1 * V_8 )
{
T_1 V_35 , V_16 = true ;
T_1 V_52 [ V_37 ] ;
int V_18 , V_53 ;
if ( ( V_7 + V_49 ) > V_54 )
return false ;
if ( ( F_10 ( V_2 , & V_35 ) == true ) && ( V_35 ==
true ) ) {
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ )
V_8 [ V_18 ] = 0xFF ;
return V_16 ;
}
V_35 = ( V_7 >> 3 ) & 0xF ;
V_16 = F_17 ( V_2 , V_35 , V_52 ) ;
V_18 = V_7 & 0x7 ;
V_53 = 0 ;
do {
for (; V_18 < V_37 ; V_18 ++ ) {
V_8 [ V_53 ++ ] = V_52 [ V_18 ] ;
if ( V_53 == V_49 )
return V_16 ;
}
V_35 ++ ;
if ( ! F_17 ( V_2 , V_35 , V_52 ) )
V_16 = false ;
V_18 = 0 ;
} while ( 1 );
return V_16 ;
}
T_1 F_25 ( struct V_1 * V_2 , T_2 V_7 , T_2 V_49 ,
T_1 * V_8 )
{
T_1 V_35 , V_22 , V_14 ;
T_1 V_52 [ V_37 ] , V_55 [ V_37 ] ;
int V_18 , V_56 , V_53 ;
if ( ( V_7 + V_49 ) > V_54 )
return false ;
V_14 = F_2 ( V_2 , V_6 ) ;
if ( V_14 != 0x03 )
return false ;
if ( F_10 ( V_2 , & V_14 ) == true ) {
if ( true == V_14 )
memset ( V_52 , 0xFF , V_37 ) ;
} else
return false ;
V_35 = ( V_7 >> 3 ) & 0xF ;
if ( V_14 == false )
if ( ! F_17 ( V_2 , V_35 , V_52 ) )
return false ;
V_22 = 0xF ;
memset ( V_55 , 0xFF , V_37 ) ;
V_18 = V_7 & 0x7 ;
V_56 = 0 ;
V_53 = 0 ;
if ( V_18 & 0x1 ) {
if ( V_8 [ V_53 ] != V_52 [ V_18 ] ) {
V_22 &= ~ F_14 ( V_18 >> 1 ) ;
V_55 [ V_56 ++ ] = V_52 [ V_18 - 1 ] ;
V_55 [ V_56 ++ ] = V_8 [ V_53 ] ;
}
V_18 ++ ;
V_53 ++ ;
}
do {
for (; V_18 < V_37 ; V_18 += 2 ) {
if ( ( V_49 - V_53 ) == 1 ) {
if ( V_8 [ V_53 ] != V_52 [ V_18 ] ) {
V_22 &= ~ F_14 ( V_18 >> 1 ) ;
V_55 [ V_56 ++ ] = V_8 [ V_53 ] ;
V_55 [ V_56 ++ ] = V_52 [ 1 + 1 ] ;
}
V_53 ++ ;
break;
} else {
if ( ( V_8 [ V_53 ] != V_52 [ V_18 ] ) || ( V_8 [ V_53 + 1 ] !=
V_52 [ V_18 + 1 ] ) ) {
V_22 &= ~ F_14 ( V_18 >> 1 ) ;
V_55 [ V_56 ++ ] = V_8 [ V_53 ] ;
V_55 [ V_56 ++ ] = V_8 [ V_53 + 1 ] ;
}
V_53 += 2 ;
}
if ( V_53 == V_49 )
break;
}
if ( V_22 != 0xF )
if ( F_21 ( V_2 , V_35 ,
V_22 , V_55 ) == false )
return false ;
if ( V_53 == V_49 )
break;
V_35 ++ ;
if ( V_14 == false )
if ( ! F_17 ( V_2 , V_35 ,
V_52 ) )
return false ;
V_18 = 0 ;
V_56 = 0 ;
V_22 = 0xF ;
memset ( V_55 , 0xFF , V_37 ) ;
} while ( 1 );
return true ;
}
