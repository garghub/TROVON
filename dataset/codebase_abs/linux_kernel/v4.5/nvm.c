static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
* V_3 = * V_3 | V_4 ;
F_2 ( V_5 , * V_3 ) ;
F_3 () ;
F_4 ( V_2 -> V_6 . V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_3 )
{
* V_3 = * V_3 & ~ V_4 ;
F_2 ( V_5 , * V_3 ) ;
F_3 () ;
F_4 ( V_2 -> V_6 . V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_8 , T_2 V_9 )
{
struct V_10 * V_6 = & V_2 -> V_6 ;
T_1 V_3 = F_7 ( V_5 ) ;
T_1 V_11 ;
V_11 = 0x01 << ( V_9 - 1 ) ;
if ( V_6 -> type == V_12 )
V_3 |= V_13 ;
do {
V_3 &= ~ V_14 ;
if ( V_8 & V_11 )
V_3 |= V_14 ;
F_2 ( V_5 , V_3 ) ;
F_3 () ;
F_4 ( V_6 -> V_7 ) ;
F_1 ( V_2 , & V_3 ) ;
F_5 ( V_2 , & V_3 ) ;
V_11 >>= 1 ;
} while ( V_11 );
V_3 &= ~ V_14 ;
F_2 ( V_5 , V_3 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , T_2 V_9 )
{
T_1 V_3 ;
T_1 V_15 ;
T_2 V_8 ;
V_3 = F_7 ( V_5 ) ;
V_3 &= ~ ( V_13 | V_14 ) ;
V_8 = 0 ;
for ( V_15 = 0 ; V_15 < V_9 ; V_15 ++ ) {
V_8 <<= 1 ;
F_1 ( V_2 , & V_3 ) ;
V_3 = F_7 ( V_5 ) ;
V_3 &= ~ V_14 ;
if ( V_3 & V_13 )
V_8 |= 1 ;
F_5 ( V_2 , & V_3 ) ;
}
return V_8 ;
}
T_3 F_9 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_17 = 100000 ;
T_1 V_15 , V_18 = 0 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ ) {
if ( V_16 == V_19 )
V_18 = F_7 ( V_20 ) ;
else
V_18 = F_7 ( V_21 ) ;
if ( V_18 & V_22 )
return 0 ;
F_4 ( 5 ) ;
}
return - V_23 ;
}
T_3 F_10 ( struct V_1 * V_2 )
{
T_1 V_3 = F_7 ( V_5 ) ;
T_3 V_24 = V_25 ;
F_2 ( V_5 , V_3 | V_26 ) ;
V_3 = F_7 ( V_5 ) ;
while ( V_24 ) {
if ( V_3 & V_27 )
break;
F_4 ( 5 ) ;
V_3 = F_7 ( V_5 ) ;
V_24 -- ;
}
if ( ! V_24 ) {
V_3 &= ~ V_26 ;
F_2 ( V_5 , V_3 ) ;
F_11 ( L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = & V_2 -> V_6 ;
T_1 V_3 = F_7 ( V_5 ) ;
if ( V_6 -> type == V_12 ) {
V_3 |= V_28 ;
F_2 ( V_5 , V_3 ) ;
F_3 () ;
F_4 ( V_6 -> V_7 ) ;
V_3 &= ~ V_28 ;
F_2 ( V_5 , V_3 ) ;
F_3 () ;
F_4 ( V_6 -> V_7 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_7 ( V_5 ) ;
if ( V_2 -> V_6 . type == V_12 ) {
V_3 |= V_28 ;
F_5 ( V_2 , & V_3 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_13 ( V_2 ) ;
V_3 = F_7 ( V_5 ) ;
V_3 &= ~ V_26 ;
F_2 ( V_5 , V_3 ) ;
}
static T_3 F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_6 = & V_2 -> V_6 ;
T_1 V_3 = F_7 ( V_5 ) ;
T_4 V_29 ;
if ( V_6 -> type == V_12 ) {
T_2 V_24 = V_30 ;
V_3 &= ~ ( V_28 | V_4 ) ;
F_2 ( V_5 , V_3 ) ;
F_3 () ;
F_4 ( 1 ) ;
while ( V_24 ) {
F_6 ( V_2 , V_31 ,
V_2 -> V_6 . V_32 ) ;
V_29 = ( T_4 ) F_8 ( V_2 , 8 ) ;
if ( ! ( V_29 & V_33 ) )
break;
F_4 ( 5 ) ;
F_12 ( V_2 ) ;
V_24 -- ;
}
if ( ! V_24 ) {
F_11 ( L_2 ) ;
return - V_23 ;
}
}
return 0 ;
}
T_3 F_16 ( struct V_1 * V_2 , T_2 V_34 , T_2 V_35 , T_2 * V_8 )
{
struct V_10 * V_6 = & V_2 -> V_6 ;
T_1 V_15 , V_36 = 0 ;
T_3 V_37 = 0 ;
if ( ( V_34 >= V_6 -> V_38 ) || ( V_35 > ( V_6 -> V_38 - V_34 ) ) ||
( V_35 == 0 ) ) {
F_11 ( L_3 ) ;
return - V_23 ;
}
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
V_36 = ( ( V_34 + V_15 ) << V_39 ) +
V_40 ;
F_2 ( V_20 , V_36 ) ;
V_37 = F_9 ( V_2 , V_19 ) ;
if ( V_37 ) {
F_11 ( L_4 , V_37 ) ;
break;
}
V_8 [ V_15 ] = ( F_7 ( V_20 ) >> V_41 ) ;
}
return V_37 ;
}
T_3 F_17 ( struct V_1 * V_2 , T_2 V_34 , T_2 V_35 , T_2 * V_8 )
{
struct V_10 * V_6 = & V_2 -> V_6 ;
T_3 V_37 = - V_23 ;
T_2 V_42 = 0 ;
if ( ( V_34 >= V_6 -> V_38 ) || ( V_35 > ( V_6 -> V_38 - V_34 ) ) ||
( V_35 == 0 ) ) {
F_11 ( L_3 ) ;
return - V_23 ;
}
while ( V_42 < V_35 ) {
T_4 V_43 = V_44 ;
V_37 = V_6 -> V_45 . V_46 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_15 ( V_2 ) ;
if ( V_37 ) {
V_6 -> V_45 . V_47 ( V_2 ) ;
return V_37 ;
}
F_12 ( V_2 ) ;
F_6 ( V_2 , V_48 ,
V_6 -> V_32 ) ;
F_12 ( V_2 ) ;
if ( ( V_6 -> V_49 == 8 ) && ( V_34 >= 128 ) )
V_43 |= V_50 ;
F_6 ( V_2 , V_43 , V_6 -> V_32 ) ;
F_6 ( V_2 , ( T_2 ) ( ( V_34 + V_42 ) * 2 ) ,
V_6 -> V_49 ) ;
while ( V_42 < V_35 ) {
T_2 V_51 = V_8 [ V_42 ] ;
V_51 = ( V_51 >> 8 ) | ( V_51 << 8 ) ;
F_6 ( V_2 , V_51 , 16 ) ;
V_42 ++ ;
if ( ( ( ( V_34 + V_42 ) * 2 ) % V_6 -> V_52 ) == 0 ) {
F_12 ( V_2 ) ;
break;
}
}
F_18 ( 10000 , 20000 ) ;
V_6 -> V_45 . V_47 ( V_2 ) ;
}
return V_37 ;
}
T_3 F_19 ( struct V_1 * V_2 , T_4 * V_53 ,
T_1 V_54 )
{
T_3 V_37 ;
T_2 V_55 ;
T_2 V_56 ;
T_2 V_34 ;
T_2 V_57 ;
if ( V_53 == NULL ) {
F_11 ( L_5 ) ;
return - V_58 ;
}
V_37 = F_20 ( V_2 , V_59 , 1 , & V_55 ) ;
if ( V_37 ) {
F_11 ( L_6 ) ;
return V_37 ;
}
V_37 = F_20 ( V_2 , V_60 , 1 , & V_56 ) ;
if ( V_37 ) {
F_11 ( L_6 ) ;
return V_37 ;
}
if ( V_55 != V_61 ) {
F_11 ( L_7 ) ;
if ( V_54 < V_62 ) {
F_11 ( L_8 ) ;
return V_63 ;
}
V_53 [ 0 ] = ( V_55 >> 12 ) & 0xF ;
V_53 [ 1 ] = ( V_55 >> 8 ) & 0xF ;
V_53 [ 2 ] = ( V_55 >> 4 ) & 0xF ;
V_53 [ 3 ] = V_55 & 0xF ;
V_53 [ 4 ] = ( V_56 >> 12 ) & 0xF ;
V_53 [ 5 ] = ( V_56 >> 8 ) & 0xF ;
V_53 [ 6 ] = '-' ;
V_53 [ 7 ] = 0 ;
V_53 [ 8 ] = ( V_56 >> 4 ) & 0xF ;
V_53 [ 9 ] = V_56 & 0xF ;
V_53 [ 10 ] = '\0' ;
for ( V_34 = 0 ; V_34 < 10 ; V_34 ++ ) {
if ( V_53 [ V_34 ] < 0xA )
V_53 [ V_34 ] += '0' ;
else if ( V_53 [ V_34 ] < 0x10 )
V_53 [ V_34 ] += 'A' - 0xA ;
}
return 0 ;
}
V_37 = F_20 ( V_2 , V_56 , 1 , & V_57 ) ;
if ( V_37 ) {
F_11 ( L_6 ) ;
return V_37 ;
}
if ( V_57 == 0xFFFF || V_57 == 0 ) {
F_11 ( L_9 ) ;
return - V_64 ;
}
if ( V_54 < ( ( ( T_1 ) V_57 * 2 ) - 1 ) ) {
F_11 ( L_8 ) ;
return - V_63 ;
}
V_56 ++ ;
V_57 -- ;
for ( V_34 = 0 ; V_34 < V_57 ; V_34 ++ ) {
V_37 = F_20 ( V_2 , V_56 + V_34 , 1 , & V_55 ) ;
if ( V_37 ) {
F_11 ( L_6 ) ;
return V_37 ;
}
V_53 [ V_34 * 2 ] = ( T_4 ) ( V_55 >> 8 ) ;
V_53 [ ( V_34 * 2 ) + 1 ] = ( T_4 ) ( V_55 & 0xFF ) ;
}
V_53 [ V_34 * 2 ] = '\0' ;
return 0 ;
}
T_3 F_21 ( struct V_1 * V_2 )
{
T_1 V_65 ;
T_1 V_66 ;
T_2 V_15 ;
V_65 = F_7 ( F_22 ( 0 ) ) ;
V_66 = F_7 ( F_23 ( 0 ) ) ;
for ( V_15 = 0 ; V_15 < V_67 ; V_15 ++ )
V_2 -> V_68 . V_69 [ V_15 ] = ( T_4 ) ( V_66 >> ( V_15 * 8 ) ) ;
for ( V_15 = 0 ; V_15 < V_70 ; V_15 ++ )
V_2 -> V_68 . V_69 [ V_15 + 4 ] = ( T_4 ) ( V_65 >> ( V_15 * 8 ) ) ;
for ( V_15 = 0 ; V_15 < V_71 ; V_15 ++ )
V_2 -> V_68 . V_72 [ V_15 ] = V_2 -> V_68 . V_69 [ V_15 ] ;
return 0 ;
}
T_3 F_24 ( struct V_1 * V_2 )
{
T_3 V_37 ;
T_2 V_73 = 0 ;
T_2 V_15 , V_55 ;
for ( V_15 = 0 ; V_15 < ( V_74 + 1 ) ; V_15 ++ ) {
V_37 = F_20 ( V_2 , V_15 , 1 , & V_55 ) ;
if ( V_37 ) {
F_11 ( L_6 ) ;
return V_37 ;
}
V_73 += V_55 ;
}
if ( V_73 != ( T_2 ) V_75 ) {
F_11 ( L_10 ) ;
return - V_23 ;
}
return 0 ;
}
T_3 F_25 ( struct V_1 * V_2 )
{
T_3 V_37 ;
T_2 V_73 = 0 ;
T_2 V_15 , V_55 ;
for ( V_15 = 0 ; V_15 < V_74 ; V_15 ++ ) {
V_37 = F_20 ( V_2 , V_15 , 1 , & V_55 ) ;
if ( V_37 ) {
F_11 ( L_11 ) ;
return V_37 ;
}
V_73 += V_55 ;
}
V_73 = ( T_2 ) V_75 - V_73 ;
V_37 = F_26 ( V_2 , V_74 , 1 , & V_73 ) ;
if ( V_37 )
F_11 ( L_12 ) ;
return V_37 ;
}
void F_27 ( struct V_1 * V_2 )
{
T_1 V_76 ;
F_18 ( 10 , 20 ) ;
V_76 = F_7 ( V_77 ) ;
V_76 |= V_78 ;
F_2 ( V_77 , V_76 ) ;
F_3 () ;
}
