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
return F_10 ( ( ~ V_23 ) & 0xf ) ;
}
void
F_11 ( struct V_1 * V_24 , T_2 V_25 , T_1 * V_26 )
{
T_3 V_27 ;
T_1 V_28 ;
T_2 V_29 ;
F_2 ( V_24 , V_30 + 1 , ( V_25 & 0xff ) ) ;
V_28 = F_5 ( V_24 , V_30 + 2 ) ;
F_2 ( V_24 , V_30 + 2 ,
( ( V_25 >> 8 ) & 0x03 ) | ( V_28 & 0xfc ) ) ;
V_28 = F_5 ( V_24 , V_30 + 3 ) ;
F_2 ( V_24 , V_30 + 3 , V_28 & 0x7f ) ;
V_29 = 0 ;
V_27 = F_12 ( V_24 , V_30 ) ;
while ( ! ( ( V_27 >> 24 ) & 0x80 ) && V_29 < 10000 ) {
V_27 = F_12 ( V_24 , V_30 ) ;
V_29 ++ ;
}
F_13 ( 50 ) ;
V_27 = F_12 ( V_24 , V_30 ) ;
* V_26 = ( T_1 ) ( V_27 & 0xff ) ;
}
void
F_14 ( struct V_1 * V_19 , T_1 V_20 ,
T_1 type , void * V_31 )
{
T_1 * V_32 ;
T_2 * V_33 ;
T_1 * V_34 ;
switch ( type ) {
case V_35 :
V_34 = V_31 ;
if ( V_20 == V_22 )
* V_34 = V_36 ;
else
* V_34 = V_37 ;
break;
case V_38 :
V_33 = V_31 ;
if ( V_20 == V_22 )
* V_33 = V_39 ;
else
* V_33 = V_40 ;
break;
case V_41 :
V_33 = V_31 ;
if ( V_20 == V_22 )
* V_33 = ( V_39 -
V_42 ) ;
else
* V_33 = ( V_43 -
V_44 ) ;
break;
case V_45 :
V_33 = V_31 ;
if ( V_20 == V_22 )
* V_33 = ( V_39 -
V_42 ) ;
else
* V_33 = ( V_40 -
( V_44 * 3 ) ) ;
break;
case V_46 :
V_33 = V_31 ;
if ( V_20 == V_22 )
* V_33 = V_47 ;
else
* V_33 = V_48 ;
break;
case V_49 :
V_32 = V_31 ;
if ( V_20 == V_22 )
* V_32 = V_42 ;
else
* V_32 = V_44 ;
break;
case V_50 :
V_33 = V_31 ;
if ( V_20 == V_22 )
* V_33 = V_39 ;
else
* V_33 = V_43 ;
break;
default:
V_32 = V_31 ;
* V_32 = 0 ;
break;
}
}
T_1
F_15 ( struct V_1 * V_24 , T_2 V_51 )
{
T_1 V_52 ;
T_1 V_53 = { 0x00 } ;
T_1 V_54 = { 0x00 } ;
T_3 V_55 = 0 ;
T_2 V_56 = 0 ;
F_14 ( V_24 , V_22 ,
V_38 ,
( void * ) & V_56 ) ;
if ( V_51 < V_56 ) {
V_54 = V_51 & 0xFF ;
F_2 ( V_24 , V_30 + 1 , V_54 ) ;
V_53 = F_5 ( V_24 , V_30 + 2 ) ;
V_54 = ( ( V_51 >> 8 ) & 0x03 ) | ( V_53 & 0xFC ) ;
F_2 ( V_24 , V_30 + 2 , V_54 ) ;
V_53 = F_5 ( V_24 , V_30 + 3 ) ;
V_54 = V_53 & 0x7F ;
F_2 ( V_24 , V_30 + 3 , V_54 ) ;
V_53 = F_5 ( V_24 , V_30 + 3 ) ;
while ( ! ( V_53 & 0x80 ) ) {
V_53 = F_5 ( V_24 , V_30 + 3 ) ;
V_55 ++ ;
if ( V_55 == 1000 ) {
V_55 = 0 ;
break;
}
}
V_52 = F_5 ( V_24 , V_30 ) ;
return V_52 ;
}
else
return 0xFF ;
}
void
F_16 ( struct V_1 * V_24 , T_2 V_51 , T_1 V_57 )
{
T_1 V_53 = { 0x00 } ;
T_1 V_54 = { 0x00 } ;
T_3 V_55 = 0 ;
T_2 V_56 = 0 ;
F_14 ( V_24 , V_22 ,
V_38 ,
( void * ) & V_56 ) ;
if ( V_51 < V_56 ) {
F_2 ( V_24 , V_30 , V_57 ) ;
V_54 = V_51 & 0xFF ;
F_2 ( V_24 , V_30 + 1 , V_54 ) ;
V_53 = F_5 ( V_24 , V_30 + 2 ) ;
V_54 = ( ( V_51 >> 8 ) & 0x03 ) | ( V_53 & 0xFC ) ;
F_2 ( V_24 , V_30 + 2 , V_54 ) ;
V_53 = F_5 ( V_24 , V_30 + 3 ) ;
V_54 = V_53 | 0x80 ;
F_2 ( V_24 , V_30 + 3 , V_54 ) ;
V_53 = F_5 ( V_24 , V_30 + 3 ) ;
while ( V_53 & 0x80 ) {
V_53 = F_5 ( V_24 , V_30 + 3 ) ;
V_55 ++ ;
if ( V_55 == 100 ) {
V_55 = 0 ;
break;
}
}
}
}
int
F_17 ( struct V_1 * V_19 , T_2 V_58 , T_1 * V_52 )
{
T_1 V_59 = 0 ;
int V_60 ;
F_2 ( V_19 , V_30 + 1 , ( T_1 ) ( V_58 & 0xff ) ) ;
F_2 ( V_19 , V_30 + 2 , ( ( T_1 ) ( ( V_58 >> 8 ) & 0x03 ) ) |
( F_5 ( V_19 , V_30 + 2 ) & 0xFC ) ) ;
F_2 ( V_19 , V_30 + 3 , 0x72 ) ;
while( ! ( 0x80 & F_5 ( V_19 , V_30 + 3 ) ) && ( V_59 < 100 ) )
V_59 ++ ;
if ( V_59 < 100 ) {
* V_52 = F_5 ( V_19 , V_30 ) ;
V_60 = V_61 ;
} else {
* V_52 = 0xff ;
V_60 = V_62 ;
}
return V_60 ;
}
int
F_18 ( struct V_1 * V_19 , T_2 V_58 , T_1 V_52 )
{
T_1 V_59 = 0 ;
int V_60 ;
F_2 ( V_19 , V_30 + 1 , ( T_1 ) ( V_58 & 0xff ) ) ;
F_2 ( V_19 , V_30 + 2 ,
( F_5 ( V_19 , V_30 + 2 ) & 0xFC ) | ( T_1 ) ( ( V_58 >> 8 ) & 0x03 ) ) ;
F_2 ( V_19 , V_30 , V_52 ) ;
F_2 ( V_19 , V_30 + 3 , 0xF2 ) ;
while( ( 0x80 & F_5 ( V_19 , V_30 + 3 ) ) &&
( V_59 < 100 ) ) {
V_59 ++ ;
}
if ( V_59 < 100 )
V_60 = V_61 ;
else
V_60 = V_62 ;
return V_60 ;
}
void
F_19 ( T_1 V_23 ,
T_1 * V_63 ,
T_1 * V_64 )
{
if ( ! ( V_23 & F_20 ( 0 ) ) ) {
V_64 [ 0 ] = V_63 [ 0 ] ;
V_64 [ 1 ] = V_63 [ 1 ] ;
}
if ( ! ( V_23 & F_20 ( 1 ) ) ) {
V_64 [ 2 ] = V_63 [ 2 ] ;
V_64 [ 3 ] = V_63 [ 3 ] ;
}
if ( ! ( V_23 & F_20 ( 2 ) ) ) {
V_64 [ 4 ] = V_63 [ 4 ] ;
V_64 [ 5 ] = V_63 [ 5 ] ;
}
if ( ! ( V_23 & F_20 ( 3 ) ) ) {
V_64 [ 6 ] = V_63 [ 6 ] ;
V_64 [ 7 ] = V_63 [ 7 ] ;
}
}
static int F_21 ( struct V_1 * V_2 , T_2 V_65 , T_1 * V_66 )
{
return F_17 ( V_2 , V_65 , V_66 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_65 , T_1 * V_66 )
{
return F_18 ( V_2 , V_65 , * V_66 ) ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_67 ,
T_2 V_68 , T_1 * V_52 )
{
int V_69 = 0 ;
T_2 V_70 = 0 , V_71 = 0 ;
int V_72 = V_62 ;
int (* F_24)( struct V_1 * , T_2 , T_1 * );
F_14 ( V_2 , V_22 ,
V_38 ,
( void * ) & V_70 ) ;
F_14 ( V_2 , V_22 ,
V_45 ,
( void * ) & V_71 ) ;
if ( V_67 > V_70 )
return V_62 ;
if ( true == V_3 ) {
if ( ( V_67 + V_68 ) > V_71 )
return V_62 ;
F_24 = & F_22 ;
} else
F_24 = & F_21 ;
F_1 ( V_2 , V_3 , true ) ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
if ( V_67 >= V_70 ) {
V_72 = V_62 ;
break;
}
V_72 = F_24 ( V_2 , V_67 ++ , V_52 ++ ) ;
if ( V_72 == V_62 )
break;
}
F_1 ( V_2 , V_3 , false ) ;
return V_72 ;
}
T_2 F_25 ( struct V_1 * V_2 )
{
T_2 V_73 ;
F_14 ( V_2 , V_22 ,
V_45 ,
( void * ) & V_73 ) ;
return V_73 ;
}
int F_26 ( struct V_1 * V_2 ,
T_2 V_58 , T_2 V_68 , T_1 * V_52 )
{
T_2 V_74 = 0 ;
F_14 ( V_2 , V_22 ,
V_46 , ( void * ) & V_74 ) ;
if ( ( V_58 + V_68 ) > V_74 )
return V_62 ;
F_1 ( V_2 , false , true ) ;
F_27 ( V_2 , V_22 , V_58 , V_68 , V_52 ) ;
F_1 ( V_2 , false , false ) ;
return V_61 ;
}
int F_28 ( struct V_1 * V_2 ,
T_2 V_58 , T_2 V_68 , T_1 * V_52 )
{
T_2 V_74 = 0 ;
F_14 ( V_2 , V_75 ,
V_46 , ( void * ) & V_74 ) ;
if ( ( V_58 + V_68 ) > V_74 )
return V_62 ;
F_1 ( V_2 , false , true ) ;
F_27 ( V_2 , V_75 , V_58 , V_68 , V_52 ) ;
F_1 ( V_2 , false , false ) ;
return V_61 ;
}
void
F_29 ( struct V_1 * V_19 , T_1 V_20 , T_1 * V_76 )
{
T_2 V_74 = 0 ;
F_1 ( V_19 , false , true ) ;
F_14 ( V_19 , V_20 , V_46 ,
( void * ) & V_74 ) ;
F_27 ( V_19 , V_20 , 0 , V_74 , V_76 ) ;
F_1 ( V_19 , false , false ) ;
}
static void
F_30 ( struct V_1 * V_19 , T_2 V_77 , T_1 * V_57 )
{
struct V_78 * V_79 = F_31 ( V_19 ) ;
* V_57 = V_79 -> V_80 [ V_77 ] ;
}
static void
F_32 ( struct V_1 * V_19 , T_2 V_77 , T_2 * V_57 )
{
struct V_78 * V_79 = F_31 ( V_19 ) ;
* V_57 = V_79 -> V_80 [ V_77 ] ;
* V_57 |= V_79 -> V_80 [ V_77 + 1 ] << 8 ;
}
static void
F_33 ( struct V_1 * V_19 , T_2 V_77 , T_3 * V_57 )
{
struct V_78 * V_79 = F_31 ( V_19 ) ;
* V_57 = V_79 -> V_80 [ V_77 ] ;
* V_57 |= V_79 -> V_80 [ V_77 + 1 ] << 8 ;
* V_57 |= V_79 -> V_80 [ V_77 + 2 ] << 16 ;
* V_57 |= V_79 -> V_80 [ V_77 + 3 ] << 24 ;
}
void F_34 ( struct V_1 * V_19 , T_1 V_20 )
{
struct V_78 * V_79 = F_31 ( V_19 ) ;
T_2 V_74 = 0 ;
F_14 ( V_19 , V_20 ,
V_46 , ( void * ) & V_74 ) ;
if ( V_79 -> V_81 == true )
memset ( V_79 -> V_80 , 0xFF , V_74 ) ;
else
F_29 ( V_19 , V_20 ,
V_79 -> V_80 ) ;
}
void
F_35 ( struct V_1 * V_19 ,
T_1 Type , T_2 V_77 , T_3 * V_57 )
{
if ( Type == 1 )
F_30 ( V_19 , V_77 , ( T_1 * ) V_57 ) ;
else if ( Type == 2 )
F_32 ( V_19 , V_77 , ( T_2 * ) V_57 ) ;
else if ( Type == 4 )
F_33 ( V_19 , V_77 , ( T_3 * ) V_57 ) ;
}
