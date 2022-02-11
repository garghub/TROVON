void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
V_4 = & V_6 [ V_5 ] ;
if ( F_3 ( V_2 -> V_7 ) == V_8 ) {
if ( ! ( V_4 -> V_9 & V_10 ) )
continue;
F_4 ( V_2 , V_4 -> V_11 , V_4 -> V_12 ) ;
} else {
if ( ! ( V_4 -> V_9 & V_13 ) )
continue;
F_4 ( V_2 , V_4 -> V_11 , V_4 -> V_14 ) ;
}
}
}
void F_5 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_15 ) ; V_5 ++ ) {
V_4 = & V_15 [ V_5 ] ;
if ( F_3 ( V_2 -> V_7 ) == V_8 ) {
if ( ! ( V_4 -> V_9 & V_10 ) )
continue;
F_4 ( V_2 , V_4 -> V_11 , V_4 -> V_12 ) ;
} else {
if ( ! ( V_4 -> V_9 & V_13 ) )
continue;
F_4 ( V_2 , V_4 -> V_11 , V_4 -> V_14 ) ;
}
}
}
T_1 F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
T_1 type , V_16 ;
type = V_11 & V_17 ;
V_11 &= ~ V_17 ;
F_7 ( V_11 > 0xFFFF ) ;
switch ( type ) {
case V_18 :
F_8 ( V_2 , V_19 , V_11 ) ;
V_16 = F_9 ( V_2 , V_20 ) & 0xFF ;
break;
case V_21 :
F_8 ( V_2 , V_19 , V_11 ) ;
V_16 = F_9 ( V_2 , V_20 ) ;
break;
case V_22 :
F_8 ( V_2 , V_19 , V_11 ) ;
V_16 = F_9 ( V_2 , V_23 ) ;
V_16 <<= 16 ;
V_16 |= F_9 ( V_2 , V_20 ) ;
break;
default:
F_7 ( 1 ) ;
V_16 = 0 ;
}
return V_16 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_11 ,
unsigned int V_24 , void * V_25 )
{
T_1 type ;
T_2 * V_26 = V_25 ;
unsigned int V_5 ;
type = V_11 & V_17 ;
V_11 &= ~ V_17 ;
F_7 ( V_11 > 0xFFFF ) ;
F_8 ( V_2 , V_19 , V_11 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
switch ( type ) {
case V_18 :
* V_26 = F_9 ( V_2 , V_20 ) & 0xFF ;
V_26 ++ ;
break;
case V_21 :
* ( ( V_27 * ) V_26 ) = F_9 ( V_2 , V_20 ) ;
V_26 += 2 ;
break;
case V_22 :
* ( ( T_1 * ) V_26 ) = F_9 ( V_2 , V_23 ) ;
* ( ( T_1 * ) V_26 ) <<= 16 ;
* ( ( T_1 * ) V_26 ) |= F_9 ( V_2 , V_20 ) ;
V_26 += 4 ;
break;
default:
F_7 ( 1 ) ;
}
}
}
void F_11 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_16 )
{
T_1 type ;
type = V_11 & V_17 ;
V_11 &= ~ V_17 ;
F_7 ( V_11 > 0xFFFF ) ;
switch ( type ) {
case V_18 :
F_7 ( V_16 & ~ 0xFF ) ;
F_8 ( V_2 , V_19 , V_11 ) ;
F_8 ( V_2 , V_20 , V_16 ) ;
break;
case V_21 :
F_7 ( V_16 & ~ 0xFFFF ) ;
F_8 ( V_2 , V_19 , V_11 ) ;
F_8 ( V_2 , V_20 , V_16 ) ;
break;
case V_22 :
F_8 ( V_2 , V_19 , V_11 ) ;
F_8 ( V_2 , V_23 , V_16 >> 16 ) ;
F_8 ( V_2 , V_20 , V_16 ) ;
break;
default:
F_7 ( 1 ) ;
}
}
void F_12 ( struct V_1 * V_2 , T_1 V_11 ,
unsigned int V_24 , const void * V_25 )
{
T_1 type , V_16 ;
const T_2 * V_26 = V_25 ;
unsigned int V_5 ;
type = V_11 & V_17 ;
V_11 &= ~ V_17 ;
F_7 ( V_11 > 0xFFFF ) ;
F_8 ( V_2 , V_19 , V_11 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
switch ( type ) {
case V_18 :
V_16 = * V_26 ;
V_26 ++ ;
F_7 ( V_16 & ~ 0xFF ) ;
F_8 ( V_2 , V_20 , V_16 ) ;
break;
case V_21 :
V_16 = * ( ( V_27 * ) V_26 ) ;
V_26 += 2 ;
F_7 ( V_16 & ~ 0xFFFF ) ;
F_8 ( V_2 , V_20 , V_16 ) ;
break;
case V_22 :
V_16 = * ( ( T_1 * ) V_26 ) ;
V_26 += 4 ;
F_8 ( V_2 , V_23 , V_16 >> 16 ) ;
F_8 ( V_2 , V_20 , V_16 ) ;
break;
default:
F_7 ( 1 ) ;
}
}
}
void F_13 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_28 . V_29 >= 2 ) ;
F_12 ( V_2 , F_14 ( 2 , 0 ) ,
F_2 ( V_30 ) , V_30 ) ;
F_12 ( V_2 , F_15 ( 1 , 0 ) ,
F_2 ( V_31 ) , V_31 ) ;
F_12 ( V_2 , F_15 ( 14 , 0 ) ,
F_2 ( V_32 ) , V_32 ) ;
F_12 ( V_2 , F_15 ( 8 , 0 ) ,
F_2 ( V_33 ) , V_33 ) ;
F_12 ( V_2 , F_16 ( 9 , 0 ) ,
F_2 ( V_34 ) , V_34 ) ;
F_12 ( V_2 , F_14 ( 6 , 0 ) ,
F_2 ( V_35 ) , V_35 ) ;
F_12 ( V_2 , F_15 ( 0 , 0 ) ,
F_2 ( V_36 ) , V_36 ) ;
if ( V_2 -> V_28 . V_29 == 0 ) {
F_12 ( V_2 , F_15 ( 13 , 0 ) ,
F_2 ( V_37 ) , V_37 ) ;
F_12 ( V_2 , F_15 ( 12 , 0 ) ,
F_2 ( V_37 ) , V_37 ) ;
} else {
F_12 ( V_2 , F_15 ( 13 , 0 ) ,
F_2 ( V_38 ) , V_38 ) ;
F_12 ( V_2 , F_15 ( 12 , 0 ) ,
F_2 ( V_38 ) , V_38 ) ;
}
F_12 ( V_2 , F_15 ( 15 , 0 ) ,
F_2 ( V_39 ) , V_39 ) ;
F_12 ( V_2 , F_16 ( 10 , 0 ) ,
F_2 ( V_40 ) , V_40 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
int V_5 ;
F_7 ( V_2 -> V_28 . V_29 < 2 ) ;
for ( V_5 = 0 ; V_5 < 704 ; V_5 ++ )
F_11 ( V_2 , F_16 ( 7 , V_5 ) , 0 ) ;
F_12 ( V_2 , F_14 ( 2 , 0 ) ,
F_2 ( V_30 ) , V_30 ) ;
F_12 ( V_2 , F_15 ( 1 , 0 ) ,
F_2 ( V_41 ) , V_41 ) ;
F_12 ( V_2 , F_16 ( 11 , 0 ) ,
F_2 ( V_42 ) , V_42 ) ;
F_12 ( V_2 , F_16 ( 12 , 0 ) ,
F_2 ( V_43 ) , V_43 ) ;
F_12 ( V_2 , F_16 ( 13 , 0 ) ,
F_2 ( V_44 ) , V_44 ) ;
F_12 ( V_2 , F_15 ( 14 , 0 ) ,
F_2 ( V_45 ) , V_45 ) ;
F_12 ( V_2 , F_15 ( 15 , 0 ) ,
F_2 ( V_46 ) , V_46 ) ;
F_12 ( V_2 , F_14 ( 16 , 0 ) ,
F_2 ( V_47 ) , V_47 ) ;
F_12 ( V_2 , F_16 ( 17 , 0 ) ,
F_2 ( V_48 ) , V_48 ) ;
F_12 ( V_2 , F_15 ( 18 , 0 ) ,
F_2 ( V_49 ) , V_49 ) ;
F_12 ( V_2 , F_14 ( 6 , 0 ) ,
F_2 ( V_35 ) , V_35 ) ;
F_12 ( V_2 , F_15 ( 0 , 0 ) ,
F_2 ( V_36 ) , V_36 ) ;
F_12 ( V_2 , F_16 ( 9 , 0 ) ,
F_2 ( V_50 ) , V_50 ) ;
F_12 ( V_2 , F_16 ( 10 , 0 ) ,
F_2 ( V_51 ) , V_51 ) ;
if ( ( V_2 -> V_2 -> V_52 == 0x4325 ) && ( V_2 -> V_2 -> V_53 == 0 ) ) {
F_12 ( V_2 , F_16 ( 13 , 0 ) ,
F_2 ( V_54 ) , V_54 ) ;
F_12 ( V_2 , F_15 ( 14 , 0 ) ,
F_2 ( V_55 ) , V_55 ) ;
F_12 ( V_2 , F_16 ( 17 , 0 ) ,
F_2 ( V_56 ) , V_56 ) ;
F_12 ( V_2 , F_15 ( 18 , 0 ) ,
F_2 ( V_57 ) , V_57 ) ;
}
}
static void F_18 ( struct V_1 * V_2 , int V_11 ,
struct V_58 V_26 )
{
T_1 V_59 ;
F_7 ( V_2 -> V_28 . V_29 >= 2 ) ;
V_59 = V_26 . V_60 << 11 ;
V_59 |= V_26 . V_61 << 7 ;
V_59 |= V_26 . V_62 << 4 ;
V_59 |= V_26 . V_63 ;
F_11 ( V_2 , F_16 ( 10 , 0xC0 + V_11 ) , V_59 ) ;
V_59 = V_26 . V_64 << 20 ;
F_11 ( V_2 , F_16 ( 10 , 0x140 + V_11 ) , V_59 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_11 ,
struct V_58 V_26 )
{
T_1 V_59 ;
F_7 ( V_2 -> V_28 . V_29 < 2 ) ;
V_59 = V_26 . V_60 << 16 ;
V_59 |= V_26 . V_61 << 8 ;
V_59 |= V_26 . V_62 ;
if ( V_2 -> V_28 . V_29 >= 3 ) {
if ( F_3 ( V_2 -> V_7 ) == V_65 )
V_59 |= 0x10 << 24 ;
else
V_59 |= 0x70 << 24 ;
} else {
if ( F_3 ( V_2 -> V_7 ) == V_65 )
V_59 |= 0x14 << 24 ;
else
V_59 |= 0x7F << 24 ;
}
F_11 ( V_2 , F_16 ( 7 , 0xC0 + V_11 ) , V_59 ) ;
V_59 = V_26 . V_64 << 20 ;
V_59 |= V_26 . V_63 << 28 ;
F_11 ( V_2 , F_16 ( 7 , 0x140 + V_11 ) , V_59 ) ;
}
void F_20 ( struct V_1 * V_2 , int V_11 ,
struct V_58 V_26 )
{
if ( V_2 -> V_28 . V_29 >= 2 )
F_19 ( V_2 , V_11 , V_26 ) ;
else
F_18 ( V_2 , V_11 , V_26 ) ;
}
void F_21 ( struct V_1 * V_2 , int V_11 , int V_66 ,
struct V_58 * V_67 )
{
int V_5 ;
for ( V_5 = V_11 ; V_5 < V_66 ; V_5 ++ )
F_20 ( V_2 , V_5 , V_67 [ V_5 ] ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_2 -> V_70 ;
switch ( V_2 -> V_28 . V_29 ) {
case 0 :
if ( ( V_69 -> V_71 & V_72 ) ||
( V_69 -> V_73 & V_74 ) )
F_21 ( V_2 , 0 , 128 ,
V_75 ) ;
else if ( F_3 ( V_2 -> V_7 ) == V_8 )
F_21 ( V_2 , 0 , 128 ,
V_76 ) ;
else
F_21 ( V_2 , 0 , 128 ,
V_77 ) ;
break;
case 1 :
if ( ( V_69 -> V_71 & V_72 ) ||
( V_69 -> V_73 & V_74 ) )
F_21 ( V_2 , 0 , 128 ,
V_78 ) ;
else if ( F_3 ( V_2 -> V_7 ) == V_8 )
F_21 ( V_2 , 0 , 128 ,
V_79 ) ;
else
F_21 ( V_2 , 0 , 128 ,
V_80 ) ;
break;
default:
if ( V_69 -> V_71 & V_72 )
F_21 ( V_2 , 0 , 128 ,
V_81 ) ;
else if ( F_3 ( V_2 -> V_7 ) == V_8 )
F_21 ( V_2 , 0 , 128 ,
V_82 ) ;
else
F_21 ( V_2 , 0 , 128 ,
V_83 ) ;
}
}
