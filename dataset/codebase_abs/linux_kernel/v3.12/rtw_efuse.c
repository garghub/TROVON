bool
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
if ( V_3 >= V_5 )
return false ;
if ( V_6 == 0 )
* V_4 = V_7 [ V_3 ] ;
else
* V_4 = V_8 [ V_6 - 1 ] [ V_3 ] ;
return true ;
}
static bool
F_2 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
if ( V_3 >= V_5 )
return false ;
if ( V_6 == 0 ) {
V_7 [ V_3 ] = V_4 ;
} else {
V_8 [ V_6 - 1 ] [ V_3 ] = V_4 ;
}
return true ;
}
void
F_3 (
struct V_1 * V_2 ,
T_2 V_9 ,
T_2 V_10 )
{
V_2 -> V_11 . V_12 ( V_2 , V_9 , V_10 ) ;
}
T_1
F_4 (
struct V_1 * V_2 ,
T_2 V_13 ,
bool V_14 )
{
T_1 V_15 = 0 ;
V_15 = V_2 -> V_11 . V_16 ( V_2 , V_13 , V_14 ) ;
return V_15 ;
}
T_2
F_5 ( T_2 V_17 )
{
T_2 V_18 = 0 ;
if ( ! ( V_17 & F_6 ( 0 ) ) )
V_18 ++ ;
if ( ! ( V_17 & F_6 ( 1 ) ) )
V_18 ++ ;
if ( ! ( V_17 & F_6 ( 2 ) ) )
V_18 ++ ;
if ( ! ( V_17 & F_6 ( 3 ) ) )
V_18 ++ ;
return V_18 ;
}
void
F_7 (
struct V_1 * V_19 ,
T_1 V_20 ,
T_2 * V_21 ,
bool V_14 )
{
T_3 V_22 ;
T_2 V_23 ;
T_1 V_24 ;
if ( V_14 ) {
F_1 ( V_19 , V_20 , V_21 ) ;
return;
}
F_8 ( V_19 , V_25 + 1 , ( V_20 & 0xff ) ) ;
V_23 = F_9 ( V_19 , V_25 + 2 ) ;
F_8 ( V_19 , V_25 + 2 , ( ( V_20 >> 8 ) & 0x03 ) | ( V_23 & 0xfc ) ) ;
V_23 = F_9 ( V_19 , V_25 + 3 ) ;
F_8 ( V_19 , V_25 + 3 , ( V_23 & 0x7f ) ) ;
V_24 = 0 ;
V_22 = F_10 ( V_19 , V_25 ) ;
while ( ! ( ( ( V_22 >> 24 ) & 0xff ) & 0x80 ) && ( V_24 < 10000 ) ) {
V_22 = F_10 ( V_19 , V_25 ) ;
V_24 ++ ;
}
F_11 ( 50 ) ;
V_22 = F_10 ( V_19 , V_25 ) ;
* V_21 = ( T_2 ) ( V_22 & 0xff ) ;
}
static void F_12 ( struct V_1 * V_19 , T_2 V_13 , T_1 V_20 , T_1 V_26 , T_2 * V_21 , bool V_14 )
{
V_19 -> V_11 . V_27 ( V_19 , V_13 , V_20 , V_26 , V_21 , V_14 ) ;
}
void F_13 ( struct V_1 * V_2 , T_2 V_13 , T_2 type , void * V_28 , bool V_14
)
{
V_2 -> V_11 . V_29 ( V_2 , V_13 , type , V_28 , V_14 ) ;
}
T_2 F_14 ( struct V_1 * V_19 , T_1 V_30 )
{
T_2 V_31 ;
T_2 V_32 = { 0x00 } ;
T_2 V_33 = { 0x00 } ;
T_3 V_34 = 0 ;
T_1 V_35 = 0 ;
F_13 ( V_19 , V_36 , V_37 , ( void * ) & V_35 , false ) ;
if ( V_30 < V_35 ) {
V_33 = V_30 & 0xFF ;
F_8 ( V_19 , V_25 + 1 , V_33 ) ;
V_32 = F_9 ( V_19 , V_25 + 2 ) ;
V_33 = ( ( V_30 >> 8 ) & 0x03 ) | ( V_32 & 0xFC ) ;
F_8 ( V_19 , V_25 + 2 , V_33 ) ;
V_32 = F_9 ( V_19 , V_25 + 3 ) ;
V_33 = V_32 & 0x7F ;
F_8 ( V_19 , V_25 + 3 , V_33 ) ;
V_32 = F_9 ( V_19 , V_25 + 3 ) ;
while ( ! ( V_32 & 0x80 ) ) {
V_32 = F_9 ( V_19 , V_25 + 3 ) ;
V_34 ++ ;
if ( V_34 == 1000 ) {
V_34 = 0 ;
break;
}
}
V_31 = F_9 ( V_19 , V_25 ) ;
return V_31 ;
} else {
return 0xFF ;
}
}
T_2 F_15 ( struct V_1 * V_2 , T_1 V_38 , T_2 * V_31 , bool V_14 )
{
T_2 V_39 = 0 ;
T_2 V_40 ;
if ( V_14 ) {
V_40 = F_1 ( V_2 , V_38 , V_31 ) ;
return V_40 ;
}
F_8 ( V_2 , V_25 + 1 , ( T_2 ) ( V_38 & 0xff ) ) ;
F_8 ( V_2 , V_25 + 2 , ( ( T_2 ) ( ( V_38 >> 8 ) & 0x03 ) ) |
( F_9 ( V_2 , V_25 + 2 ) & 0xFC ) ) ;
F_8 ( V_2 , V_25 + 3 , 0x72 ) ;
while ( ! ( 0x80 & F_9 ( V_2 , V_25 + 3 ) ) && ( V_39 < 100 ) )
V_39 ++ ;
if ( V_39 < 100 ) {
* V_31 = F_9 ( V_2 , V_25 ) ;
V_40 = true ;
} else {
* V_31 = 0xff ;
V_40 = false ;
}
return V_40 ;
}
T_2 F_16 ( struct V_1 * V_2 , T_1 V_38 , T_2 V_31 , bool V_14 )
{
T_2 V_39 = 0 ;
T_2 V_40 ;
if ( V_14 ) {
V_40 = F_2 ( V_2 , V_38 , V_31 ) ;
return V_40 ;
}
F_8 ( V_2 , V_25 + 1 , ( T_2 ) ( V_38 & 0xff ) ) ;
F_8 ( V_2 , V_25 + 2 ,
( F_9 ( V_2 , V_25 + 2 ) & 0xFC ) |
( T_2 ) ( ( V_38 >> 8 ) & 0x03 ) ) ;
F_8 ( V_2 , V_25 , V_31 ) ;
F_8 ( V_2 , V_25 + 3 , 0xF2 ) ;
while ( ( 0x80 & F_9 ( V_2 , V_25 + 3 ) ) && ( V_39 < 100 ) )
V_39 ++ ;
if ( V_39 < 100 )
V_40 = true ;
else
V_40 = false ;
return V_40 ;
}
int F_17 ( struct V_1 * V_2 , T_2 V_41 , T_2 * V_31 , bool V_14 )
{
int V_15 = 0 ;
V_15 = V_2 -> V_11 . F_17 ( V_2 , V_41 , V_31 , V_14 ) ;
return V_15 ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_41 , T_2 V_17 , T_2 * V_31 , bool V_14 )
{
int V_15 ;
V_15 = V_2 -> V_11 . F_18 ( V_2 , V_41 , V_17 , V_31 , V_14 ) ;
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_41 , T_2 V_17 , T_2 * V_31 , bool V_14 )
{
int V_15 ;
V_15 = V_2 -> V_11 . F_19 ( V_2 , V_41 , V_17 , V_31 , V_14 ) ;
return V_15 ;
}
void F_20 ( T_2 V_17 , T_2 * V_42 , T_2 * V_43 )
{
if ( ! ( V_17 & F_6 ( 0 ) ) ) {
V_43 [ 0 ] = V_42 [ 0 ] ;
V_43 [ 1 ] = V_42 [ 1 ] ;
}
if ( ! ( V_17 & F_6 ( 1 ) ) ) {
V_43 [ 2 ] = V_42 [ 2 ] ;
V_43 [ 3 ] = V_42 [ 3 ] ;
}
if ( ! ( V_17 & F_6 ( 2 ) ) ) {
V_43 [ 4 ] = V_42 [ 4 ] ;
V_43 [ 5 ] = V_42 [ 5 ] ;
}
if ( ! ( V_17 & F_6 ( 3 ) ) ) {
V_43 [ 6 ] = V_42 [ 6 ] ;
V_43 [ 7 ] = V_42 [ 7 ] ;
}
}
T_2 F_21 ( struct V_1 * V_2 , T_1 V_44 , T_2 V_17 , T_2 * V_31 , bool V_14 )
{
T_2 V_15 = 0 ;
V_15 = V_2 -> V_11 . F_21 ( V_2 , V_44 , V_17 , V_31 , V_14 ) ;
return V_15 ;
}
static T_2 F_22 ( struct V_1 * V_45 , T_1 V_46 , T_2 * V_47 )
{
return F_15 ( V_45 , V_46 , V_47 , false ) ;
}
static T_2 F_23 ( struct V_1 * V_45 , T_1 V_46 , T_2 * V_47 )
{
return F_16 ( V_45 , V_46 , * V_47 , false ) ;
}
T_2 F_24 ( struct V_1 * V_45 , T_2 V_9 , T_1 V_48 , T_1 V_49 , T_2 * V_31 )
{
int V_50 = 0 ;
T_1 V_51 = 0 , V_52 = 0 ;
T_2 V_53 = V_54 ;
T_2 (* F_25)( struct V_1 * , T_1 , T_2 * );
F_13 ( V_45 , V_36 , V_37 , ( void * ) & V_51 , false ) ;
F_13 ( V_45 , V_36 , V_55 , ( void * ) & V_52 , false ) ;
if ( V_48 > V_51 )
return V_54 ;
if ( V_9 ) {
if ( ( V_48 + V_49 ) > V_52 )
return V_54 ;
F_25 = & F_23 ;
} else {
F_25 = & F_22 ;
}
F_3 ( V_45 , V_9 , true ) ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
if ( V_48 >= V_51 ) {
V_53 = V_54 ;
break;
}
V_53 = F_25 ( V_45 , V_48 ++ , V_31 ++ ) ;
if ( V_54 == V_53 )
break;
}
F_3 ( V_45 , V_9 , false ) ;
return V_53 ;
}
T_1 F_26 ( struct V_1 * V_45 )
{
T_1 V_56 ;
F_13 ( V_45 , V_36 , V_55 , ( void * ) & V_56 , false ) ;
return V_56 ;
}
T_2 F_27 ( struct V_1 * V_45 , T_1 * V_57 )
{
F_3 ( V_45 , false , true ) ;
* V_57 = F_4 ( V_45 , V_36 , false ) ;
F_3 ( V_45 , false , false ) ;
return V_58 ;
}
T_2 F_28 ( struct V_1 * V_45 , T_1 V_38 , T_1 V_49 , T_2 * V_31 )
{
T_1 V_59 = 0 ;
F_13 ( V_45 , V_36 , V_60 , ( void * ) & V_59 , false ) ;
if ( ( V_38 + V_49 ) > V_59 )
return V_54 ;
F_3 ( V_45 , false , true ) ;
F_12 ( V_45 , V_36 , V_38 , V_49 , V_31 , false ) ;
F_3 ( V_45 , false , false ) ;
return V_58 ;
}
T_2 F_29 ( struct V_1 * V_45 , T_1 V_38 , T_1 V_49 , T_2 * V_31 )
{
T_1 V_59 = 0 ;
F_13 ( V_45 , V_61 , V_60 , ( void * ) & V_59 , false ) ;
if ( ( V_38 + V_49 ) > V_59 )
return V_54 ;
F_3 ( V_45 , false , true ) ;
F_12 ( V_45 , V_61 , V_38 , V_49 , V_31 , false ) ;
F_3 ( V_45 , false , false ) ;
return V_58 ;
}
T_2 F_30 ( struct V_1 * V_45 , T_1 V_38 , T_1 V_49 , T_2 * V_31 )
{
T_2 V_41 , V_17 ;
T_2 * V_62 ;
T_2 V_63 [ V_64 ] ;
T_4 V_50 , V_65 ;
T_2 V_15 = V_58 ;
T_1 V_59 = 0 ;
F_13 ( V_45 , V_36 , V_60 , ( void * ) & V_59 , false ) ;
if ( ( V_38 + V_49 ) > V_59 )
return V_54 ;
V_62 = F_31 ( V_59 ) ;
if ( V_62 == NULL )
return V_54 ;
V_15 = F_28 ( V_45 , 0 , V_59 , V_62 ) ;
if ( V_15 == V_54 )
goto exit;
F_3 ( V_45 , true , true ) ;
V_41 = ( V_38 >> 3 ) ;
V_17 = 0xF ;
F_32 ( V_63 , 0xFF , V_64 ) ;
V_50 = V_38 & 0x7 ;
V_65 = 0 ;
if ( V_50 & 0x1 ) {
if ( V_31 [ V_65 ] != V_62 [ V_38 + V_65 ] ) {
V_17 &= ~ F_6 ( V_50 >> 1 ) ;
V_63 [ V_50 - 1 ] = V_62 [ V_38 + V_65 - 1 ] ;
V_63 [ V_50 ] = V_31 [ V_65 ] ;
}
V_50 ++ ;
V_65 ++ ;
}
do {
for (; V_50 < V_64 ; V_50 += 2 ) {
if ( V_49 == V_65 )
break;
if ( ( V_49 - V_65 ) == 1 ) {
if ( V_31 [ V_65 ] != V_62 [ V_38 + V_65 ] ) {
V_17 &= ~ F_6 ( V_50 >> 1 ) ;
V_63 [ V_50 ] = V_31 [ V_65 ] ;
V_63 [ V_50 + 1 ] = V_62 [ V_38 + V_65 + 1 ] ;
}
V_65 ++ ;
break;
} else {
if ( ( V_31 [ V_65 ] != V_62 [ V_38 + V_65 ] ) ||
( V_31 [ V_65 + 1 ] != V_62 [ V_38 + V_65 + 1 ] ) ) {
V_17 &= ~ F_6 ( V_50 >> 1 ) ;
V_63 [ V_50 ] = V_31 [ V_65 ] ;
V_63 [ V_50 + 1 ] = V_31 [ V_65 + 1 ] ;
}
V_65 += 2 ;
}
if ( V_65 == V_49 )
break;
}
if ( V_17 != 0xF ) {
V_15 = F_18 ( V_45 , V_41 , V_17 , V_63 , false ) ;
F_33 ( L_1 , V_41 ) ;
F_33 ( L_2 , V_17 ) ;
for ( V_50 = 0 ; V_50 < V_64 ; V_50 ++ )
F_33 ( L_3 , V_63 [ V_50 ] ) ;
if ( V_15 == V_54 )
break;
}
if ( V_65 == V_49 )
break;
V_41 ++ ;
V_50 = 0 ;
V_17 = 0xF ;
F_32 ( V_63 , 0xFF , V_64 ) ;
} while ( 1 );
F_3 ( V_45 , true , false ) ;
exit:
F_34 ( V_62 ) ;
return V_15 ;
}
T_2 F_35 ( struct V_1 * V_45 , T_1 V_38 , T_1 V_49 , T_2 * V_31 )
{
T_2 V_41 , V_17 ;
T_2 * V_62 ;
T_2 V_63 [ V_64 ] ;
T_4 V_50 , V_65 ;
T_2 V_15 = V_58 ;
T_1 V_59 = 0 ;
F_13 ( V_45 , V_61 , V_60 , ( void * ) & V_59 , false ) ;
if ( ( V_38 + V_49 ) > V_59 )
return V_54 ;
V_62 = F_31 ( V_59 ) ;
if ( V_62 == NULL )
return V_54 ;
V_15 = F_29 ( V_45 , 0 , V_59 , V_62 ) ;
if ( V_15 == V_54 )
goto exit;
F_3 ( V_45 , true , true ) ;
V_41 = ( V_38 >> 3 ) ;
V_17 = 0xF ;
F_32 ( V_63 , 0xFF , V_64 ) ;
V_50 = V_38 & 0x7 ;
V_65 = 0 ;
if ( V_50 & 0x1 ) {
if ( V_31 [ V_65 ] != V_62 [ V_38 + V_65 ] ) {
V_17 &= ~ F_6 ( V_50 >> 1 ) ;
V_63 [ V_50 - 1 ] = V_62 [ V_38 + V_65 - 1 ] ;
V_63 [ V_50 ] = V_31 [ V_65 ] ;
}
V_50 ++ ;
V_65 ++ ;
}
do {
for (; V_50 < V_64 ; V_50 += 2 ) {
if ( V_49 == V_65 )
break;
if ( ( V_49 - V_65 ) == 1 ) {
if ( V_31 [ V_65 ] != V_62 [ V_38 + V_65 ] ) {
V_17 &= ~ F_6 ( V_50 >> 1 ) ;
V_63 [ V_50 ] = V_31 [ V_65 ] ;
V_63 [ V_50 + 1 ] = V_62 [ V_38 + V_65 + 1 ] ;
}
V_65 ++ ;
break;
} else {
if ( ( V_31 [ V_65 ] != V_62 [ V_38 + V_65 ] ) ||
( V_31 [ V_65 + 1 ] != V_62 [ V_38 + V_65 + 1 ] ) ) {
V_17 &= ~ F_6 ( V_50 >> 1 ) ;
V_63 [ V_50 ] = V_31 [ V_65 ] ;
V_63 [ V_50 + 1 ] = V_31 [ V_65 + 1 ] ;
}
V_65 += 2 ;
}
if ( V_65 == V_49 )
break;
}
if ( V_17 != 0xF ) {
F_33 ( L_4 , V_66 , V_41 ) ;
F_33 ( L_5 , V_66 , V_17 ) ;
F_33 ( L_6 , V_66 ) ;
for ( V_50 = 0 ; V_50 < V_64 ; V_50 ++ )
F_33 ( L_7 , V_63 [ V_50 ] ) ;
F_33 ( L_8 ) ;
V_15 = F_19 ( V_45 , V_41 , V_17 , V_63 , false ) ;
if ( V_15 == V_54 )
break;
}
if ( V_65 == V_49 )
break;
V_41 ++ ;
V_50 = 0 ;
V_17 = 0xF ;
F_32 ( V_63 , 0xFF , V_64 ) ;
} while ( 1 );
F_3 ( V_45 , true , false ) ;
exit:
F_34 ( V_62 ) ;
return V_15 ;
}
static void
F_36 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 )
{
struct V_67 * V_68 = F_37 ( V_2 ) ;
* V_4 = V_68 -> V_69 [ V_3 ] ;
}
static void
F_38 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_4 )
{
struct V_67 * V_68 = F_37 ( V_2 ) ;
* V_4 = V_68 -> V_69 [ V_3 ] ;
* V_4 |= V_68 -> V_69 [ V_3 + 1 ] << 8 ;
}
static void
F_39 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_3 * V_4 )
{
struct V_67 * V_68 = F_37 ( V_2 ) ;
* V_4 = V_68 -> V_69 [ V_3 ] ;
* V_4 |= V_68 -> V_69 [ V_3 + 1 ] << 8 ;
* V_4 |= V_68 -> V_69 [ V_3 + 2 ] << 16 ;
* V_4 |= V_68 -> V_69 [ V_3 + 3 ] << 24 ;
}
static void F_40 ( struct V_1 * V_2 , T_2 V_13 , T_2 * V_70 , bool V_14 )
{
T_1 V_59 = 0 ;
F_3 ( V_2 , false , true ) ;
F_13 ( V_2 , V_13 , V_60 , ( void * ) & V_59 , V_14 ) ;
F_12 ( V_2 , V_13 , 0 , V_59 , V_70 , V_14 ) ;
F_3 ( V_2 , false , false ) ;
}
void F_41 (
struct V_1 * V_2 ,
T_2 V_13 ,
bool V_14 )
{
struct V_67 * V_68 = F_37 ( V_2 ) ;
T_1 V_59 = 0 ;
F_13 ( V_2 , V_13 , V_60 , ( void * ) & V_59 , V_14 ) ;
if ( V_68 -> V_71 )
F_32 ( V_68 -> V_69 , 0xFF , V_59 ) ;
else
F_40 ( V_2 , V_13 , V_68 -> V_69 , V_14 ) ;
}
void F_42 ( struct V_1 * V_2 , T_2 Type , T_1 V_3 , T_3 * V_4 )
{
if ( Type == 1 )
F_36 ( V_2 , V_3 , ( T_2 * ) V_4 ) ;
else if ( Type == 2 )
F_38 ( V_2 , V_3 , ( T_1 * ) V_4 ) ;
else if ( Type == 4 )
F_39 ( V_2 , V_3 , ( T_3 * ) V_4 ) ;
}
