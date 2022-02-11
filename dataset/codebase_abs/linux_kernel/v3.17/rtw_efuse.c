static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
if ( V_4 == true ) {
F_2 ( V_2 , V_7 , V_8 ) ;
V_6 = F_3 ( V_2 , V_9 ) ;
if ( ! ( V_6 & V_10 ) ) {
V_6 |= V_10 ;
F_4 ( V_2 , V_9 , V_6 ) ;
}
V_6 = F_3 ( V_2 , V_11 ) ;
if ( ! ( V_6 & V_12 ) ) {
V_6 |= V_12 ;
F_4 ( V_2 , V_11 , V_6 ) ;
}
V_6 = F_3 ( V_2 , V_13 ) ;
if ( ( ! ( V_6 & V_14 ) ) || ( ! ( V_6 & V_15 ) ) ) {
V_6 |= ( V_14 | V_15 ) ;
F_4 ( V_2 , V_13 , V_6 ) ;
}
if ( V_3 == true ) {
V_5 = F_5 ( V_2 , V_16 + 3 ) ;
V_5 &= 0x0F ;
V_5 |= ( V_17 << 4 ) ;
F_2 ( V_2 , V_16 + 3 ,
V_5 | 0x80 ) ;
}
} else {
F_2 ( V_2 , V_7 , V_18 ) ;
if ( V_3 == true ) {
V_5 = F_5 ( V_2 , V_16 + 3 ) ;
F_2 ( V_2 , V_16 + 3 ,
V_5 & 0x7F ) ;
}
}
}
T_2
F_6 ( struct V_1 * V_19 , T_1 V_20 )
{
T_2 V_21 = 0 ;
if ( V_20 == V_22 )
V_21 = F_7 ( V_19 ) ;
else
V_21 = F_8 ( V_19 ) ;
return V_21 ;
}
T_1
F_9 ( T_1 V_23 )
{
T_1 V_24 = 0 ;
if ( ! ( V_23 & F_10 ( 0 ) ) ) V_24 ++ ;
if ( ! ( V_23 & F_10 ( 1 ) ) ) V_24 ++ ;
if ( ! ( V_23 & F_10 ( 2 ) ) ) V_24 ++ ;
if ( ! ( V_23 & F_10 ( 3 ) ) ) V_24 ++ ;
return V_24 ;
}
void
F_11 ( struct V_1 * V_25 , T_2 V_26 , T_1 * V_27 )
{
T_3 V_28 ;
T_1 V_29 ;
T_2 V_30 ;
F_2 ( V_25 , V_31 + 1 , ( V_26 & 0xff ) ) ;
V_29 = F_5 ( V_25 , V_31 + 2 ) ;
F_2 ( V_25 , V_31 + 2 ,
( ( V_26 >> 8 ) & 0x03 ) | ( V_29 & 0xfc ) ) ;
V_29 = F_5 ( V_25 , V_31 + 3 ) ;
F_2 ( V_25 , V_31 + 3 , V_29 & 0x7f ) ;
V_30 = 0 ;
V_28 = F_12 ( V_25 , V_31 ) ;
while( ! ( ( ( V_28 >> 24 ) & 0xff ) & 0x80 ) && ( V_30 < 10000 ) )
{
V_28 = F_12 ( V_25 , V_31 ) ;
V_30 ++ ;
}
F_13 ( 50 ) ;
V_28 = F_12 ( V_25 , V_31 ) ;
* V_27 = ( T_1 ) ( V_28 & 0xff ) ;
}
void
F_14 ( struct V_1 * V_19 , T_1 V_20 ,
T_1 type , void * V_32 )
{
T_1 * V_33 ;
T_2 * V_34 ;
T_1 * V_35 ;
switch ( type ) {
case V_36 :
V_35 = ( T_1 * ) V_32 ;
if ( V_20 == V_22 )
* V_35 = V_37 ;
else
* V_35 = V_38 ;
break;
case V_39 :
V_34 = ( T_2 * ) V_32 ;
if ( V_20 == V_22 )
* V_34 = V_40 ;
else
* V_34 = V_41 ;
break;
case V_42 :
V_34 = ( T_2 * ) V_32 ;
if ( V_20 == V_22 )
* V_34 = ( V_40 -
V_43 ) ;
else
* V_34 = ( V_44 -
V_45 ) ;
break;
case V_46 :
V_34 = ( T_2 * ) V_32 ;
if ( V_20 == V_22 )
* V_34 = ( V_40 -
V_43 ) ;
else
* V_34 = ( V_41 -
( V_45 * 3 ) ) ;
break;
case V_47 :
V_34 = ( T_2 * ) V_32 ;
if ( V_20 == V_22 )
* V_34 = V_48 ;
else
* V_34 = V_49 ;
break;
case V_50 :
V_33 = ( T_1 * ) V_32 ;
if ( V_20 == V_22 )
* V_33 = V_43 ;
else
* V_33 = V_45 ;
break;
case V_51 :
V_34 = ( T_2 * ) V_32 ;
if ( V_20 == V_22 )
* V_34 = V_40 ;
else
* V_34 = V_44 ;
break;
default:
V_33 = ( T_1 * ) V_32 ;
* V_33 = 0 ;
break;
}
}
T_1
F_15 ( struct V_1 * V_25 , T_2 V_52 )
{
T_1 V_53 ;
T_1 V_54 = { 0x00 } ;
T_1 V_55 = { 0x00 } ;
T_3 V_56 = 0 ;
T_2 V_57 = 0 ;
F_14 ( V_25 , V_22 ,
V_39 ,
( void * ) & V_57 ) ;
if ( V_52 < V_57 )
{
V_55 = V_52 & 0xFF ;
F_2 ( V_25 , V_31 + 1 , V_55 ) ;
V_54 = F_5 ( V_25 , V_31 + 2 ) ;
V_55 = ( ( V_52 >> 8 ) & 0x03 ) | ( V_54 & 0xFC ) ;
F_2 ( V_25 , V_31 + 2 , V_55 ) ;
V_54 = F_5 ( V_25 , V_31 + 3 ) ;
V_55 = V_54 & 0x7F ;
F_2 ( V_25 , V_31 + 3 , V_55 ) ;
V_54 = F_5 ( V_25 , V_31 + 3 ) ;
while( ! ( V_54 & 0x80 ) )
{
V_54 = F_5 ( V_25 , V_31 + 3 ) ;
V_56 ++ ;
if ( V_56 == 1000 )
{
V_56 = 0 ;
break;
}
}
V_53 = F_5 ( V_25 , V_31 ) ;
return V_53 ;
}
else
return 0xFF ;
}
void
F_16 (
struct V_1 * V_25 ,
T_2 V_52 ,
T_1 V_58 )
{
T_1 V_54 = { 0x00 } ;
T_1 V_55 = { 0x00 } ;
T_3 V_56 = 0 ;
T_2 V_57 = 0 ;
F_14 ( V_25 , V_22 ,
V_39 ,
( void * ) & V_57 ) ;
if ( V_52 < V_57 )
{
F_2 ( V_25 , V_31 , V_58 ) ;
V_55 = V_52 & 0xFF ;
F_2 ( V_25 , V_31 + 1 , V_55 ) ;
V_54 = F_5 ( V_25 , V_31 + 2 ) ;
V_55 = ( ( V_52 >> 8 ) & 0x03 ) | ( V_54 & 0xFC ) ;
F_2 ( V_25 , V_31 + 2 , V_55 ) ;
V_54 = F_5 ( V_25 , V_31 + 3 ) ;
V_55 = V_54 | 0x80 ;
F_2 ( V_25 , V_31 + 3 , V_55 ) ;
V_54 = F_5 ( V_25 , V_31 + 3 ) ;
while( V_54 & 0x80 )
{
V_54 = F_5 ( V_25 , V_31 + 3 ) ;
V_56 ++ ;
if ( V_56 == 100 )
{
V_56 = 0 ;
break;
}
}
}
}
int
F_17 ( struct V_1 * V_19 , T_2 V_59 , T_1 * V_53 )
{
T_1 V_60 = 0 ;
int V_61 ;
F_2 ( V_19 , V_31 + 1 , ( T_1 ) ( V_59 & 0xff ) ) ;
F_2 ( V_19 , V_31 + 2 , ( ( T_1 ) ( ( V_59 >> 8 ) & 0x03 ) ) |
( F_5 ( V_19 , V_31 + 2 ) & 0xFC ) ) ;
F_2 ( V_19 , V_31 + 3 , 0x72 ) ;
while( ! ( 0x80 & F_5 ( V_19 , V_31 + 3 ) ) && ( V_60 < 100 ) )
V_60 ++ ;
if ( V_60 < 100 ) {
* V_53 = F_5 ( V_19 , V_31 ) ;
V_61 = V_62 ;
} else {
* V_53 = 0xff ;
V_61 = V_63 ;
}
return V_61 ;
}
int
F_18 ( struct V_1 * V_19 , T_2 V_59 , T_1 V_53 )
{
T_1 V_60 = 0 ;
int V_61 ;
F_2 ( V_19 , V_31 + 1 , ( T_1 ) ( V_59 & 0xff ) ) ;
F_2 ( V_19 , V_31 + 2 ,
( F_5 ( V_19 , V_31 + 2 ) & 0xFC ) | ( T_1 ) ( ( V_59 >> 8 ) & 0x03 ) ) ;
F_2 ( V_19 , V_31 , V_53 ) ;
F_2 ( V_19 , V_31 + 3 , 0xF2 ) ;
while( ( 0x80 & F_5 ( V_19 , V_31 + 3 ) ) &&
( V_60 < 100 ) ) {
V_60 ++ ;
}
if ( V_60 < 100 )
V_61 = V_62 ;
else
V_61 = V_63 ;
return V_61 ;
}
void
F_19 ( T_1 V_23 ,
T_1 * V_64 ,
T_1 * V_65 )
{
if ( ! ( V_23 & F_10 ( 0 ) ) )
{
V_65 [ 0 ] = V_64 [ 0 ] ;
V_65 [ 1 ] = V_64 [ 1 ] ;
}
if ( ! ( V_23 & F_10 ( 1 ) ) )
{
V_65 [ 2 ] = V_64 [ 2 ] ;
V_65 [ 3 ] = V_64 [ 3 ] ;
}
if ( ! ( V_23 & F_10 ( 2 ) ) )
{
V_65 [ 4 ] = V_64 [ 4 ] ;
V_65 [ 5 ] = V_64 [ 5 ] ;
}
if ( ! ( V_23 & F_10 ( 3 ) ) )
{
V_65 [ 6 ] = V_64 [ 6 ] ;
V_65 [ 7 ] = V_64 [ 7 ] ;
}
}
static int F_20 ( struct V_1 * V_2 , T_2 V_66 , T_1 * V_67 )
{
return F_17 ( V_2 , V_66 , V_67 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_66 , T_1 * V_67 )
{
return F_18 ( V_2 , V_66 , * V_67 ) ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_68 ,
T_2 V_69 , T_1 * V_53 )
{
int V_70 = 0 ;
T_2 V_71 = 0 , V_72 = 0 ;
int V_73 = V_63 ;
int (* F_23)( struct V_1 * , T_2 , T_1 * );
F_14 ( V_2 , V_22 ,
V_39 ,
( void * ) & V_71 ) ;
F_14 ( V_2 , V_22 ,
V_46 ,
( void * ) & V_72 ) ;
if ( V_68 > V_71 )
return V_63 ;
if ( true == V_3 ) {
if ( ( V_68 + V_69 ) > V_72 )
return V_63 ;
F_23 = & F_21 ;
} else
F_23 = & F_20 ;
F_1 ( V_2 , V_3 , true ) ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
if ( V_68 >= V_71 ) {
V_73 = V_63 ;
break;
}
V_73 = F_23 ( V_2 , V_68 ++ , V_53 ++ ) ;
if ( V_73 == V_63 )
break;
}
F_1 ( V_2 , V_3 , false ) ;
return V_73 ;
}
T_2 F_24 ( struct V_1 * V_2 )
{
T_2 V_74 ;
F_14 ( V_2 , V_22 ,
V_46 ,
( void * ) & V_74 ) ;
return V_74 ;
}
int F_25 ( struct V_1 * V_2 ,
T_2 V_59 , T_2 V_69 , T_1 * V_53 )
{
T_2 V_75 = 0 ;
F_14 ( V_2 , V_22 ,
V_47 , ( void * ) & V_75 ) ;
if ( ( V_59 + V_69 ) > V_75 )
return V_63 ;
F_1 ( V_2 , false , true ) ;
F_26 ( V_2 , V_22 , V_59 , V_69 , V_53 ) ;
F_1 ( V_2 , false , false ) ;
return V_62 ;
}
int F_27 ( struct V_1 * V_2 ,
T_2 V_59 , T_2 V_69 , T_1 * V_53 )
{
T_2 V_75 = 0 ;
F_14 ( V_2 , V_76 ,
V_47 , ( void * ) & V_75 ) ;
if ( ( V_59 + V_69 ) > V_75 )
return V_63 ;
F_1 ( V_2 , false , true ) ;
F_26 ( V_2 , V_76 , V_59 , V_69 , V_53 ) ;
F_1 ( V_2 , false , false ) ;
return V_62 ;
}
void
F_28 ( struct V_1 * V_19 , T_1 V_20 , T_1 * V_77 )
{
T_2 V_75 = 0 ;
F_1 ( V_19 , false , true ) ;
F_14 ( V_19 , V_20 , V_47 ,
( void * ) & V_75 ) ;
F_26 ( V_19 , V_20 , 0 , V_75 , V_77 ) ;
F_1 ( V_19 , false , false ) ;
}
static void
F_29 (
struct V_1 * V_19 ,
T_2 V_78 ,
T_1 * V_58 )
{
struct V_79 * V_80 = F_30 ( V_19 ) ;
* V_58 = V_80 -> V_81 [ V_78 ] ;
}
static void
F_31 (
struct V_1 * V_19 ,
T_2 V_78 ,
T_2 * V_58 )
{
struct V_79 * V_80 = F_30 ( V_19 ) ;
* V_58 = V_80 -> V_81 [ V_78 ] ;
* V_58 |= V_80 -> V_81 [ V_78 + 1 ] << 8 ;
}
static void
F_32 (
struct V_1 * V_19 ,
T_2 V_78 ,
T_3 * V_58 )
{
struct V_79 * V_80 = F_30 ( V_19 ) ;
* V_58 = V_80 -> V_81 [ V_78 ] ;
* V_58 |= V_80 -> V_81 [ V_78 + 1 ] << 8 ;
* V_58 |= V_80 -> V_81 [ V_78 + 2 ] << 16 ;
* V_58 |= V_80 -> V_81 [ V_78 + 3 ] << 24 ;
}
void F_33 ( struct V_1 * V_19 , T_1 V_20 )
{
struct V_79 * V_80 = F_30 ( V_19 ) ;
T_2 V_75 = 0 ;
F_14 ( V_19 , V_20 ,
V_47 , ( void * ) & V_75 ) ;
if ( V_80 -> V_82 == true )
memset ( V_80 -> V_81 , 0xFF , V_75 ) ;
else
F_28 ( V_19 , V_20 ,
V_80 -> V_81 ) ;
}
void
F_34 (
struct V_1 * V_19 ,
T_1 Type ,
T_2 V_78 ,
T_3 * V_58 )
{
if ( Type == 1 )
F_29 ( V_19 , V_78 , ( T_1 * ) V_58 ) ;
else if ( Type == 2 )
F_31 ( V_19 , V_78 , ( T_2 * ) V_58 ) ;
else if ( Type == 4 )
F_32 ( V_19 , V_78 , ( T_3 * ) V_58 ) ;
}
