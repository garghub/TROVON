T_1 F_1 ( T_2 * V_1 , T_3 V_2 )
{
if ( ! V_1 )
return V_3 ;
* V_1 = ( V_4 << V_5 ) | V_2 ;
return 0 ;
}
static T_1 F_2 ( T_2 * V_1 , T_3 V_6 ,
const unsigned char * string )
{
T_2 V_7 = 0 , V_8 = 0 ;
T_2 * V_9 ;
if ( ! string || ! V_1 )
return V_3 ;
V_9 = & V_1 [ F_3 ( * V_1 ) ] ;
do {
if ( V_8 && ! ( V_8 % 4 ) ) {
V_9 [ V_8 / 4 ] = V_7 ;
V_7 = 0 ;
}
V_7 |= ( T_2 ) ( * string ) << ( 8 * ( V_8 % 4 ) ) ;
V_8 ++ ;
} while ( * ( string ++ ) );
V_9 [ ( V_8 + 3 ) / 4 ] = V_7 ;
V_8 <<= V_10 ;
V_9 [ 0 ] = V_8 | V_6 ;
V_8 += V_11 << V_10 ;
* V_1 += F_4 ( V_8 ) ;
return 0 ;
}
static T_1 F_5 ( T_2 * V_9 , unsigned char * string )
{
T_2 V_8 ;
if ( ! string || ! V_9 )
return V_3 ;
V_8 = * V_9 >> V_10 ;
V_9 ++ ;
while ( V_8 -- )
string [ V_8 ] = ( V_12 ) ( V_9 [ V_8 / 4 ] >> ( 8 * ( V_8 % 4 ) ) ) ;
return 0 ;
}
T_1 F_6 ( T_2 * V_1 , T_3 V_6 ,
const V_12 * V_13 , T_3 V_14 )
{
T_2 V_8 = V_15 << V_10 ;
T_2 * V_9 ;
if ( ! V_1 || ! V_13 )
return V_3 ;
V_9 = & V_1 [ F_3 ( * V_1 ) ] ;
V_9 [ 0 ] = V_8 | V_6 ;
V_9 [ 1 ] = F_7 ( * ( const V_16 * ) & V_13 [ 0 ] ) ;
V_9 [ 2 ] = F_8 ( * ( const V_17 * ) & V_13 [ 4 ] ) ;
V_9 [ 2 ] |= ( T_2 ) V_14 << 16 ;
V_8 += V_11 << V_10 ;
* V_1 += F_4 ( V_8 ) ;
return 0 ;
}
T_1 F_9 ( T_2 * V_9 , V_12 * V_13 , T_3 * V_14 )
{
if ( ! V_13 || ! V_9 )
return V_3 ;
* ( V_16 * ) & V_13 [ 0 ] = F_10 ( V_9 [ 1 ] ) ;
* ( V_17 * ) & V_13 [ 4 ] = F_11 ( ( T_3 ) ( V_9 [ 2 ] ) ) ;
* V_14 = ( T_3 ) ( V_9 [ 2 ] >> 16 ) ;
return 0 ;
}
T_1 F_12 ( T_2 * V_1 , T_3 V_6 )
{
if ( ! V_1 )
return V_3 ;
V_1 [ F_3 ( * V_1 ) ] = V_6 ;
* V_1 += V_11 << V_10 ;
return 0 ;
}
T_1 F_13 ( T_2 * V_1 , T_3 V_6 , T_4 V_18 , T_2 V_8 )
{
T_2 * V_9 ;
if ( ! V_1 || ! V_8 || V_8 > 8 || ( V_8 & ( V_8 - 1 ) ) )
return V_3 ;
V_9 = & V_1 [ F_3 ( * V_1 ) ] ;
if ( V_8 < 4 ) {
V_9 [ 1 ] = ( T_2 ) V_18 & ( F_14 ( 8 * V_8 ) - 1 ) ;
} else {
V_9 [ 1 ] = ( T_2 ) V_18 ;
if ( V_8 > 4 )
V_9 [ 2 ] = ( T_2 ) ( V_18 >> 32 ) ;
}
V_8 <<= V_10 ;
V_9 [ 0 ] = V_8 | V_6 ;
V_8 += V_11 << V_10 ;
* V_1 += F_4 ( V_8 ) ;
return 0 ;
}
T_1 F_15 ( T_2 * V_9 , void * V_18 , T_2 V_8 )
{
if ( ! V_9 || ! V_18 )
return V_3 ;
if ( ( * V_9 >> V_10 ) != V_8 )
return V_3 ;
if ( V_8 == 8 )
* ( V_19 * ) V_18 = ( ( V_19 ) V_9 [ 2 ] << 32 ) | V_9 [ 1 ] ;
else if ( V_8 == 4 )
* ( T_2 * ) V_18 = V_9 [ 1 ] ;
else if ( V_8 == 2 )
* ( T_3 * ) V_18 = ( T_3 ) V_9 [ 1 ] ;
else
* ( V_12 * ) V_18 = ( V_12 ) V_9 [ 1 ] ;
return 0 ;
}
T_1 F_16 ( T_2 * V_1 , T_3 V_6 ,
const void * V_20 , T_2 V_8 )
{
const V_16 * V_21 = ( const V_16 * ) V_20 ;
T_2 * V_9 ;
T_2 V_22 ;
if ( ! V_1 || ! V_8 || ( V_8 % 4 ) )
return V_3 ;
V_9 = & V_1 [ F_3 ( * V_1 ) ] ;
for ( V_22 = 0 ; V_22 < ( V_8 / 4 ) ; V_22 ++ )
V_9 [ V_22 + 1 ] = F_7 ( V_21 [ V_22 ] ) ;
V_8 <<= V_10 ;
V_9 [ 0 ] = V_8 | V_6 ;
V_8 += V_11 << V_10 ;
* V_1 += F_4 ( V_8 ) ;
return 0 ;
}
T_1 F_17 ( T_2 * V_9 , void * V_20 , T_2 V_8 )
{
V_16 * V_21 = ( V_16 * ) V_20 ;
T_2 V_22 ;
if ( ! V_20 || ! V_9 )
return V_3 ;
if ( ( * V_9 >> V_10 ) != V_8 )
return V_3 ;
V_9 ++ ;
for ( V_22 = 0 ; V_8 ; V_22 ++ , V_8 -= 4 )
V_21 [ V_22 ] = F_10 ( V_9 [ V_22 ] ) ;
return 0 ;
}
static T_2 * F_18 ( T_2 * V_1 , T_3 V_6 )
{
T_2 * V_9 ;
if ( ! V_1 )
return NULL ;
V_9 = & V_1 [ F_3 ( * V_1 ) ] ;
V_9 [ 0 ] = V_6 ;
return V_9 ;
}
static T_1 F_19 ( T_2 * V_1 )
{
T_2 * V_9 ;
T_2 V_8 ;
if ( ! V_1 )
return V_3 ;
V_9 = & V_1 [ F_3 ( * V_1 ) ] ;
V_8 = ( V_9 [ 0 ] >> V_10 ) << V_10 ;
if ( V_8 ) {
V_8 += V_11 << V_10 ;
* V_1 += V_8 ;
}
return 0 ;
}
static T_1 F_20 ( T_2 * V_9 ,
const struct V_23 * V_24 )
{
T_2 V_6 = * V_9 & V_25 ;
T_3 V_8 = * V_9 >> V_10 ;
if ( * V_9 & ( V_4 << V_5 ) )
return V_3 ;
while ( V_24 -> V_26 < V_6 )
V_24 ++ ;
if ( V_24 -> V_26 != V_6 )
return V_27 ;
V_9 ++ ;
switch ( V_24 -> type ) {
case V_28 :
if ( ! V_8 ||
( V_9 [ ( V_8 - 1 ) / 4 ] & ( 0xFF << ( 8 * ( ( V_8 - 1 ) % 4 ) ) ) ) )
return V_3 ;
if ( V_8 > V_24 -> V_8 )
return V_3 ;
break;
case V_29 :
if ( V_8 != V_15 )
return V_3 ;
break;
case V_30 :
if ( V_8 )
return V_3 ;
break;
case V_31 :
case V_32 :
if ( V_8 != V_24 -> V_8 )
return V_3 ;
break;
case V_33 :
if ( ( V_8 % 4 ) || V_8 != V_24 -> V_8 )
return V_3 ;
break;
case V_34 :
if ( V_8 % 4 )
return V_3 ;
break;
default:
return V_3 ;
}
return 0 ;
}
static T_1 F_21 ( T_2 * V_9 , T_2 * * V_35 ,
const struct V_23 * V_24 )
{
T_2 V_22 , V_6 , V_36 = 0 ;
T_1 V_37 = 0 ;
T_3 V_8 ;
if ( ! V_9 || ! V_35 )
return V_3 ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ )
V_35 [ V_22 ] = NULL ;
V_8 = * V_9 >> V_10 ;
if ( ! V_8 )
return 0 ;
if ( ! V_24 ) {
V_35 [ 0 ] = V_9 ;
return 0 ;
}
V_9 ++ ;
while ( V_36 < V_8 ) {
V_6 = * V_9 & V_25 ;
if ( V_6 >= V_38 )
return V_27 ;
V_37 = F_20 ( V_9 , V_24 ) ;
if ( V_37 == V_27 )
;
else if ( V_37 )
return V_37 ;
else
V_35 [ V_6 ] = V_9 ;
V_36 += F_3 ( * V_9 ) * 4 ;
V_9 = & V_9 [ F_3 ( * V_9 ) ] ;
}
if ( V_36 != V_8 )
return V_3 ;
return 0 ;
}
T_1 F_22 ( struct V_39 * V_40 , T_2 * V_1 ,
struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
T_2 * V_35 [ V_38 ] ;
T_2 V_2 ;
T_1 V_37 ;
if ( ! V_1 || ! V_44 )
return V_3 ;
if ( ! ( * V_1 & ( V_4 << V_5 ) ) )
return V_3 ;
V_2 = * V_1 & V_25 ;
while ( V_44 -> V_26 < V_2 )
V_44 ++ ;
if ( V_44 -> V_26 != V_2 ) {
while ( V_44 -> V_26 != V_45 )
V_44 ++ ;
}
V_37 = F_21 ( V_1 , V_35 , V_44 -> V_9 ) ;
if ( V_37 < 0 )
return V_37 ;
return V_44 -> V_46 ( V_40 , V_35 , V_42 ) ;
}
T_1 F_23 ( struct V_39 * V_40 , T_2 * * V_35 ,
struct V_41 * V_42 )
{
return V_27 ;
}
static void F_24 ( T_2 * V_1 , T_2 V_47 )
{
if ( V_47 & F_14 ( V_48 ) )
F_2 ( V_1 , V_48 ,
V_49 ) ;
if ( V_47 & F_14 ( V_50 ) )
F_6 ( V_1 , V_50 ,
V_51 , V_52 ) ;
if ( V_47 & F_14 ( V_53 ) )
F_25 ( V_1 , V_53 , V_54 ) ;
if ( V_47 & F_14 ( V_55 ) )
F_26 ( V_1 , V_55 , V_56 ) ;
if ( V_47 & F_14 ( V_57 ) )
F_27 ( V_1 , V_57 , V_58 ) ;
if ( V_47 & F_14 ( V_59 ) )
F_28 ( V_1 , V_59 , V_60 ) ;
if ( V_47 & F_14 ( V_61 ) )
F_29 ( V_1 , V_61 , V_62 ) ;
if ( V_47 & F_14 ( V_63 ) )
F_30 ( V_1 , V_63 , V_64 ) ;
if ( V_47 & F_14 ( V_65 ) )
F_31 ( V_1 , V_65 , V_66 ) ;
if ( V_47 & F_14 ( V_67 ) )
F_32 ( V_1 , V_67 , V_68 ) ;
if ( V_47 & F_14 ( V_69 ) )
F_16 ( V_1 , V_69 ,
V_70 , 8 ) ;
}
void F_33 ( T_2 * V_1 , T_2 V_47 )
{
T_2 * V_71 = NULL ;
F_1 ( V_1 , V_72 ) ;
F_24 ( V_1 , V_47 ) ;
V_47 >>= V_73 ;
if ( V_47 ) {
V_71 = F_18 ( V_1 , V_73 ) ;
F_24 ( V_71 , V_47 ) ;
F_19 ( V_1 ) ;
}
}
T_1 F_34 ( struct V_39 * V_40 , T_2 * * V_35 ,
struct V_41 * V_42 )
{
T_2 * V_74 [ V_38 ] ;
unsigned char V_75 [ 80 ] ;
unsigned char V_76 [ V_15 ] ;
T_1 V_37 = 0 ;
V_16 V_77 [ 2 ] ;
T_3 V_78 ;
V_19 V_79 ;
T_2 V_80 ;
T_3 V_81 ;
V_12 V_82 ;
T_4 V_83 ;
T_1 V_84 ;
T_5 V_85 ;
T_6 V_86 ;
T_2 V_87 [ 3 ] ;
if ( ! ! V_35 [ V_88 ] )
return F_35 ( V_35 [ V_88 ] ,
& V_42 -> V_89 ) ;
V_90:
if ( ! ! V_35 [ V_48 ] ) {
V_37 = F_5 (
V_35 [ V_48 ] ,
V_75 ) ;
if ( ! V_37 && memcmp ( V_49 , V_75 , sizeof( V_49 ) ) )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_50 ] ) {
V_37 = F_9 (
V_35 [ V_50 ] ,
V_76 , & V_78 ) ;
if ( ! V_37 && ! F_36 ( V_51 , V_76 ) )
V_37 = V_91 ;
if ( ! V_37 && V_52 != V_78 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_53 ] ) {
V_37 = F_37 ( V_35 [ V_53 ] ,
& V_82 ) ;
if ( ! V_37 && V_54 != V_82 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_55 ] ) {
V_37 = F_38 ( V_35 [ V_55 ] ,
& V_81 ) ;
if ( ! V_37 && V_56 != V_81 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_57 ] ) {
V_37 = F_39 ( V_35 [ V_57 ] ,
& V_80 ) ;
if ( ! V_37 && V_58 != V_80 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_59 ] ) {
V_37 = F_40 ( V_35 [ V_59 ] ,
& V_79 ) ;
if ( ! V_37 && V_60 != V_79 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_61 ] ) {
V_37 = F_41 ( V_35 [ V_61 ] ,
& V_86 ) ;
if ( ! V_37 && V_62 != V_86 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_63 ] ) {
V_37 = F_42 ( V_35 [ V_63 ] ,
& V_85 ) ;
if ( ! V_37 && V_64 != V_85 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_65 ] ) {
V_37 = F_35 ( V_35 [ V_65 ] ,
& V_84 ) ;
if ( ! V_37 && V_66 != V_84 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_67 ] ) {
V_37 = F_43 ( V_35 [ V_67 ] ,
& V_83 ) ;
if ( ! V_37 && V_68 != V_83 )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_69 ] ) {
V_37 = F_17 (
V_35 [ V_69 ] ,
V_77 ,
sizeof( V_77 ) ) ;
if ( ! V_37 && memcmp ( V_70 , V_77 , sizeof( V_70 ) ) )
V_37 = V_91 ;
if ( V_37 )
goto V_92;
}
if ( ! ! V_35 [ V_73 ] ) {
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
V_37 = F_21 ( V_35 [ V_73 ] ,
V_74 ,
V_93 ) ;
if ( V_37 )
goto V_92;
V_35 = V_74 ;
goto V_90;
}
V_92:
F_1 ( V_87 , V_72 ) ;
F_31 ( V_87 , V_88 , V_37 ) ;
return V_42 -> V_94 . V_95 ( V_40 , V_42 , V_87 ) ;
}
