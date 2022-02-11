void
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
V_2 -> V_5 . V_6 ( V_2 , V_3 , V_4 ) ;
}
T_2
F_2 ( struct V_1 * V_2 , T_1 V_7 )
{
T_2 V_8 = 0 ;
V_8 = V_2 -> V_5 . V_9 ( V_2 , V_7 ) ;
return V_8 ;
}
T_1
F_3 ( T_1 V_10 )
{
T_1 V_11 = 0 ;
if ( ! ( V_10 & F_4 ( 0 ) ) ) V_11 ++ ;
if ( ! ( V_10 & F_4 ( 1 ) ) ) V_11 ++ ;
if ( ! ( V_10 & F_4 ( 2 ) ) ) V_11 ++ ;
if ( ! ( V_10 & F_4 ( 3 ) ) ) V_11 ++ ;
return V_11 ;
}
void
F_5 ( struct V_1 * V_12 , T_2 V_13 , T_1 * V_14 )
{
T_3 V_15 ;
T_1 V_16 ;
T_2 V_17 ;
F_6 ( V_12 , V_18 + 1 , ( V_13 & 0xff ) ) ;
V_16 = F_7 ( V_12 , V_18 + 2 ) ;
F_6 ( V_12 , V_18 + 2 , ( ( V_13 >> 8 ) & 0x03 ) | ( V_16 & 0xfc ) ) ;
V_16 = F_7 ( V_12 , V_18 + 3 ) ;
F_6 ( V_12 , V_18 + 3 , ( V_16 & 0x7f ) ) ;
V_17 = 0 ;
V_15 = F_8 ( V_12 , V_18 ) ;
while( ! ( ( ( V_15 >> 24 ) & 0xff ) & 0x80 ) && ( V_17 < 10000 ) )
{
V_15 = F_8 ( V_12 , V_18 ) ;
V_17 ++ ;
}
F_9 ( 50 ) ;
V_15 = F_8 ( V_12 , V_18 ) ;
* V_14 = ( T_1 ) ( V_15 & 0xff ) ;
}
void
F_10 ( struct V_1 * V_12 , T_1 V_7 ,
T_2 V_13 , T_2 V_19 , T_1 * V_14 )
{
V_12 -> V_5 . V_20 ( V_12 , V_7 , V_13 ,
V_19 , V_14 ) ;
}
void
F_11 ( struct V_1 * V_2 , T_1 V_7 ,
T_1 type , void * V_21 )
{
V_2 -> V_5 . V_22 ( V_2 , V_7 ,
type , V_21 ) ;
}
T_1
F_12 ( struct V_1 * V_12 , T_2 V_23 )
{
T_1 V_24 ;
T_1 V_25 = { 0x00 } ;
T_1 V_26 = { 0x00 } ;
T_3 V_27 = 0 ;
T_2 V_28 = 0 ;
F_11 ( V_12 , V_29 ,
V_30 ,
( void * ) & V_28 ) ;
if ( V_23 < V_28 )
{
V_26 = V_23 & 0xFF ;
F_6 ( V_12 , V_18 + 1 , V_26 ) ;
V_25 = F_7 ( V_12 , V_18 + 2 ) ;
V_26 = ( ( V_23 >> 8 ) & 0x03 ) | ( V_25 & 0xFC ) ;
F_6 ( V_12 , V_18 + 2 , V_26 ) ;
V_25 = F_7 ( V_12 , V_18 + 3 ) ;
V_26 = V_25 & 0x7F ;
F_6 ( V_12 , V_18 + 3 , V_26 ) ;
V_25 = F_7 ( V_12 , V_18 + 3 ) ;
while( ! ( V_25 & 0x80 ) )
{
V_25 = F_7 ( V_12 , V_18 + 3 ) ;
V_27 ++ ;
if ( V_27 == 1000 )
{
V_27 = 0 ;
break;
}
}
V_24 = F_7 ( V_12 , V_18 ) ;
return V_24 ;
}
else
return 0xFF ;
}
void
F_13 (
struct V_1 * V_12 ,
T_2 V_23 ,
T_1 V_31 )
{
T_1 V_25 = { 0x00 } ;
T_1 V_26 = { 0x00 } ;
T_3 V_27 = 0 ;
T_2 V_28 = 0 ;
F_11 ( V_12 , V_29 ,
V_30 ,
( void * ) & V_28 ) ;
if ( V_23 < V_28 )
{
F_6 ( V_12 , V_18 , V_31 ) ;
V_26 = V_23 & 0xFF ;
F_6 ( V_12 , V_18 + 1 , V_26 ) ;
V_25 = F_7 ( V_12 , V_18 + 2 ) ;
V_26 = ( ( V_23 >> 8 ) & 0x03 ) | ( V_25 & 0xFC ) ;
F_6 ( V_12 , V_18 + 2 , V_26 ) ;
V_25 = F_7 ( V_12 , V_18 + 3 ) ;
V_26 = V_25 | 0x80 ;
F_6 ( V_12 , V_18 + 3 , V_26 ) ;
V_25 = F_7 ( V_12 , V_18 + 3 ) ;
while( V_25 & 0x80 )
{
V_25 = F_7 ( V_12 , V_18 + 3 ) ;
V_27 ++ ;
if ( V_27 == 100 )
{
V_27 = 0 ;
break;
}
}
}
}
T_1
F_14 ( struct V_1 * V_2 , T_2 V_32 , T_1 * V_24 )
{
T_1 V_33 = 0 ;
T_1 V_34 ;
F_6 ( V_2 , V_18 + 1 , ( T_1 ) ( V_32 & 0xff ) ) ;
F_6 ( V_2 , V_18 + 2 , ( ( T_1 ) ( ( V_32 >> 8 ) & 0x03 ) ) |
( F_7 ( V_2 , V_18 + 2 ) & 0xFC ) ) ;
F_6 ( V_2 , V_18 + 3 , 0x72 ) ;
while( ! ( 0x80 & F_7 ( V_2 , V_18 + 3 ) ) && ( V_33 < 100 ) )
V_33 ++ ;
if ( V_33 < 100 ) {
* V_24 = F_7 ( V_2 , V_18 ) ;
V_34 = true ;
} else {
* V_24 = 0xff ;
V_34 = false ;
}
return V_34 ;
}
T_1
F_15 ( struct V_1 * V_2 , T_2 V_32 , T_1 V_24 )
{
T_1 V_33 = 0 ;
T_1 V_34 ;
F_6 ( V_2 , V_18 + 1 , ( T_1 ) ( V_32 & 0xff ) ) ;
F_6 ( V_2 , V_18 + 2 ,
( F_7 ( V_2 , V_18 + 2 ) & 0xFC ) | ( T_1 ) ( ( V_32 >> 8 ) & 0x03 ) ) ;
F_6 ( V_2 , V_18 , V_24 ) ;
F_6 ( V_2 , V_18 + 3 , 0xF2 ) ;
while( ( 0x80 & F_7 ( V_2 , V_18 + 3 ) ) && ( V_33 < 100 ) ) {
V_33 ++ ;
}
if ( V_33 < 100 )
{
V_34 = true ;
}
else
{
V_34 = false ;
}
return V_34 ;
}
int
F_16 ( struct V_1 * V_2 , T_1 V_35 , T_1 * V_24 )
{
int V_8 = 0 ;
V_8 = V_2 -> V_5 . F_16 ( V_2 , V_35 , V_24 ) ;
return V_8 ;
}
int
F_17 ( struct V_1 * V_2 , T_1 V_35 ,
T_1 V_10 , T_1 * V_24 )
{
int V_8 ;
V_8 = V_2 -> V_5 . F_17 ( V_2 , V_35 ,
V_10 , V_24 ) ;
return V_8 ;
}
void
F_18 ( T_1 V_10 ,
T_1 * V_36 ,
T_1 * V_37 )
{
if ( ! ( V_10 & F_4 ( 0 ) ) )
{
V_37 [ 0 ] = V_36 [ 0 ] ;
V_37 [ 1 ] = V_36 [ 1 ] ;
}
if ( ! ( V_10 & F_4 ( 1 ) ) )
{
V_37 [ 2 ] = V_36 [ 2 ] ;
V_37 [ 3 ] = V_36 [ 3 ] ;
}
if ( ! ( V_10 & F_4 ( 2 ) ) )
{
V_37 [ 4 ] = V_36 [ 4 ] ;
V_37 [ 5 ] = V_36 [ 5 ] ;
}
if ( ! ( V_10 & F_4 ( 3 ) ) )
{
V_37 [ 6 ] = V_36 [ 6 ] ;
V_37 [ 7 ] = V_36 [ 7 ] ;
}
}
T_1
F_19 ( struct V_1 * V_2 , T_2 V_38 ,
T_1 V_10 , T_1 * V_24 )
{
T_1 V_8 = 0 ;
V_8 = V_2 -> V_5 . F_19 ( V_2 , V_38 ,
V_10 , V_24 ) ;
return V_8 ;
}
static T_1 F_20 ( struct V_1 * V_39 , T_2 V_40 , T_1 * V_41 )
{
return F_14 ( V_39 , V_40 , V_41 ) ;
}
static T_1 F_21 ( struct V_1 * V_39 , T_2 V_40 , T_1 * V_41 )
{
return F_15 ( V_39 , V_40 , * V_41 ) ;
}
T_1 F_22 ( struct V_1 * V_39 , T_1 V_3 , T_2 V_42 ,
T_2 V_43 , T_1 * V_24 )
{
int V_44 = 0 ;
T_2 V_45 = 0 , V_46 = 0 ;
T_1 V_47 = V_48 ;
T_1 (* F_23)( struct V_1 * , T_2 , T_1 * );
F_11 ( V_39 , V_29 ,
V_30 ,
( void * ) & V_45 ) ;
F_11 ( V_39 , V_29 ,
V_49 ,
( void * ) & V_46 ) ;
if ( V_42 > V_45 )
return V_48 ;
if ( true == V_3 ) {
if ( ( V_42 + V_43 ) > V_46 )
return V_48 ;
F_23 = & F_21 ;
} else
F_23 = & F_20 ;
F_1 ( V_39 , V_3 , true ) ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
if ( V_42 >= V_45 ) {
V_47 = V_48 ;
break;
}
V_47 = F_23 ( V_39 , V_42 ++ , V_24 ++ ) ;
if ( V_48 == V_47 ) break;
}
F_1 ( V_39 , V_3 , false ) ;
return V_47 ;
}
T_2 F_24 ( struct V_1 * V_39 )
{
T_2 V_50 ;
F_11 ( V_39 , V_29 ,
V_49 ,
( void * ) & V_50 ) ;
return V_50 ;
}
T_1 F_25 ( struct V_1 * V_39 , T_2 * V_51 )
{
F_1 ( V_39 , false , true ) ;
* V_51 = F_2 ( V_39 , V_29 ) ;
F_1 ( V_39 , false , false ) ;
return V_52 ;
}
T_1 F_26 ( struct V_1 * V_39 , T_2 V_32 , T_2 V_43 , T_1 * V_24 )
{
T_2 V_53 = 0 ;
F_11 ( V_39 , V_29 ,
V_54 , ( void * ) & V_53 ) ;
if ( ( V_32 + V_43 ) > V_53 )
return V_48 ;
F_1 ( V_39 , false , true ) ;
F_10 ( V_39 , V_29 , V_32 , V_43 , V_24 ) ;
F_1 ( V_39 , false , false ) ;
return V_52 ;
}
T_1 F_27 ( struct V_1 * V_39 , T_2 V_32 , T_2 V_43 , T_1 * V_24 )
{
T_2 V_53 = 0 ;
F_11 ( V_39 , V_55 ,
V_54 , ( void * ) & V_53 ) ;
if ( ( V_32 + V_43 ) > V_53 )
return V_48 ;
F_1 ( V_39 , false , true ) ;
F_10 ( V_39 , V_55 , V_32 , V_43 , V_24 ) ;
F_1 ( V_39 , false , false ) ;
return V_52 ;
}
void
F_28 ( struct V_1 * V_2 , T_1 V_7 , T_1 * V_56 )
{
T_2 V_53 = 0 ;
F_1 ( V_2 , false , true ) ;
F_11 ( V_2 , V_7 , V_54 ,
( void * ) & V_53 ) ;
F_10 ( V_2 , V_7 , 0 , V_53 , V_56 ) ;
F_1 ( V_2 , false , false ) ;
}
static void
F_29 (
struct V_1 * V_2 ,
T_2 V_57 ,
T_1 * V_31 )
{
struct V_58 * V_59 = F_30 ( V_2 ) ;
* V_31 = V_59 -> V_60 [ V_57 ] ;
}
static void
F_31 (
struct V_1 * V_2 ,
T_2 V_57 ,
T_2 * V_31 )
{
struct V_58 * V_59 = F_30 ( V_2 ) ;
* V_31 = V_59 -> V_60 [ V_57 ] ;
* V_31 |= V_59 -> V_60 [ V_57 + 1 ] << 8 ;
}
static void
F_32 (
struct V_1 * V_2 ,
T_2 V_57 ,
T_3 * V_31 )
{
struct V_58 * V_59 = F_30 ( V_2 ) ;
* V_31 = V_59 -> V_60 [ V_57 ] ;
* V_31 |= V_59 -> V_60 [ V_57 + 1 ] << 8 ;
* V_31 |= V_59 -> V_60 [ V_57 + 2 ] << 16 ;
* V_31 |= V_59 -> V_60 [ V_57 + 3 ] << 24 ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_58 * V_59 = F_30 ( V_2 ) ;
T_2 V_53 = 0 ;
F_11 ( V_2 , V_7 ,
V_54 , ( void * ) & V_53 ) ;
if ( V_59 -> V_61 == true )
memset ( V_59 -> V_60 , 0xFF , V_53 ) ;
else
F_28 ( V_2 , V_7 ,
V_59 -> V_60 ) ;
}
void
F_34 (
struct V_1 * V_2 ,
T_1 Type ,
T_2 V_57 ,
T_3 * V_31 )
{
if ( Type == 1 )
F_29 ( V_2 , V_57 , ( T_1 * ) V_31 ) ;
else if ( Type == 2 )
F_31 ( V_2 , V_57 , ( T_2 * ) V_31 ) ;
else if ( Type == 4 )
F_32 ( V_2 , V_57 , ( T_3 * ) V_31 ) ;
}
