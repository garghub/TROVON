static inline T_1 F_1 ( T_2 V_1 , T_2 clock )
{
return ( ( V_1 * 1000 * clock ) / 1000000 ) + 1 ;
}
static int F_2 ( struct V_2 * V_3 , T_3 V_4 )
{
int V_5 = 0 ;
F_3 ( V_3 , V_6 , V_7 | V_4 ) ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( ! ( F_4 ( V_3 , V_6 ) & V_7 ) ) {
V_5 = 0 ;
break;
}
}
if ( V_5 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
if ( F_4 ( V_3 , V_6 ) & V_10 ) {
if ( F_4 ( V_3 , V_6 ) &
V_11 ) {
F_5 ( L_2 ) ;
return - V_9 ;
} else {
return 0 ;
}
}
}
F_5 ( L_3 ) ;
return - V_9 ;
}
static void F_7 ( struct V_12 * V_13 , T_4 * V_14 ,
int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
T_3 V_20 ;
T_3 * V_21 = ( T_3 * ) V_14 ;
int V_5 ;
int V_22 ;
F_8 ( V_19 -> V_23 & ~ V_16 -> V_24 ) ;
while ( V_15 ) {
V_22 = F_9 ( V_15 , 0x200 ) ;
F_3 ( V_19 -> V_3 , V_25 ,
V_19 -> V_26 ) ;
F_3 ( V_19 -> V_3 , V_27 ,
V_19 -> V_23 ) ;
V_20 = V_28 | V_29 | 0x00040000 | 0x00020000 |
V_30 ;
V_20 |= V_31 << 8 ;
if ( F_2 ( V_19 -> V_3 , V_20 ) )
return;
if ( F_6 ( V_19 -> V_3 ) )
return;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 += 4 , V_21 ++ ) {
V_20 = V_28 | 0x30000000 | V_32 ;
if ( V_5 == V_22 - 4 )
V_20 &= ~ V_28 ;
if ( F_2 ( V_19 -> V_3 ,
V_20 ) )
return;
* V_21 = F_4 ( V_19 -> V_3 , V_33 ) ;
}
V_19 -> V_26 += V_22 ;
V_15 -= V_22 ;
}
}
static void F_10 ( struct V_12 * V_13 ,
const T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
struct V_2 * V_3 = V_19 -> V_3 ;
T_3 V_20 ;
const T_3 * V_34 = ( T_3 * ) V_14 ;
int V_5 ;
F_8 ( V_19 -> V_23 & ~ V_16 -> V_24 ) ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 += 4 , V_34 ++ ) {
F_3 ( V_3 , V_33 , * V_34 ) ;
V_20 = V_28 | 0x30000000 | V_35 ;
if ( V_5 == V_15 - 4 )
V_20 &= ~ V_28 ;
if ( F_2 ( V_3 , V_20 ) ) {
F_5 ( L_4 , V_36 ) ;
return;
}
}
V_19 -> V_26 += V_15 ;
}
static void F_11 ( struct V_12 * V_13 ,
int V_37 )
{
return;
}
static void F_12 ( struct V_12 * V_13 ,
unsigned V_38 , int V_39 ,
int V_40 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
struct V_2 * V_3 = V_19 -> V_3 ;
T_3 V_20 ;
int V_5 ;
if ( V_39 != - 1 )
V_19 -> V_26 = V_39 ;
if ( V_40 != - 1 )
V_19 -> V_23 = V_40 ;
switch ( V_38 ) {
case V_41 :
F_13 ( L_5 ) ;
break;
case V_42 :
V_20 = V_28 | 0x01000000 | V_29 | V_30 ;
V_20 |= V_42 ;
if ( F_2 ( V_19 -> V_3 , V_20 ) ) {
F_5 ( L_6 ) ;
break;
}
for ( V_5 = 0 ; V_5 < F_14 ( V_19 -> V_43 ) ; V_5 ++ ) {
V_20 = V_28 | V_32 ;
if ( V_5 == F_14 ( V_19 -> V_43 ) - 1 )
V_20 &= ~ V_28 ;
if ( F_2 ( V_19 -> V_3 ,
V_20 ) ) {
F_5 ( L_6 ) ;
break;
}
V_19 -> V_43 [ V_5 ] =
F_4 ( V_19 -> V_3 , V_33 )
& 0xFF ;
}
break;
case V_44 :
V_20 = V_28 | V_30 | V_44 ;
if ( F_2 ( V_3 , V_20 ) )
F_5 ( L_7 ) ;
break;
case V_45 :
break;
case V_46 :
if ( V_40 != - 1 )
V_19 -> V_26 += V_13 -> V_47 ;
break;
case V_48 :
F_3 ( V_3 , V_27 ,
V_19 -> V_23 ) ;
V_20 = 0x00040000 | V_29 | V_30 |
V_48 | ( V_49 << 8 ) ;
if ( F_2 ( V_3 , V_20 ) )
F_5 ( L_8 ) ;
break;
case V_49 :
break;
case V_50 :
F_3 ( V_3 , V_25 ,
V_19 -> V_26 ) ;
F_3 ( V_3 , V_27 ,
V_19 -> V_23 ) ;
V_20 = 0x40000000 | 0x00040000 | 0x00020000 | 0x00010000 ;
V_20 |= V_50 ;
if ( F_2 ( V_3 , V_20 ) )
F_5 ( L_9 ) ;
break;
case V_51 :
if ( F_2 ( V_3 , 0x00010000 |
V_51 ) )
F_5 ( L_10 ) ;
if ( F_6 ( V_3 ) )
F_5 ( L_11 ) ;
break;
default:
F_5 ( L_12 , V_38 ) ;
break;
}
V_19 -> V_52 = V_38 ;
}
static T_1 F_15 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
struct V_2 * V_3 = V_19 -> V_3 ;
T_3 V_53 = 0 ;
switch ( V_19 -> V_52 ) {
case V_42 :
if ( V_19 -> V_26 >= F_14 ( V_19 -> V_43 ) ) {
F_5 ( L_13 ,
V_19 -> V_26 ) ;
return 0 ;
}
return V_19 -> V_43 [ V_19 -> V_26 ++ ] ;
case V_44 :
if ( F_2 ( V_3 , V_32 ) )
return 0 ;
return F_4 ( V_3 , V_33 ) & 0xff ;
case V_46 :
F_7 ( V_13 , ( T_1 * ) & V_53 , 4 ) ;
return V_53 & 0xFF ;
}
F_5 ( L_14 , V_19 -> V_52 ) ;
return 0 ;
}
static void F_16 ( struct V_12 * V_13 ,
T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
switch ( V_19 -> V_52 ) {
case V_45 :
case V_46 :
F_7 ( V_13 , V_14 , V_15 ) ;
return;
}
F_5 ( L_15 , V_19 -> V_52 ) ;
}
static void F_17 ( struct V_12 * V_13 ,
const T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
switch ( V_19 -> V_52 ) {
case V_50 :
F_10 ( V_13 , V_14 , V_15 ) ;
return;
}
F_5 ( L_16 , V_19 -> V_52 ) ;
}
int F_18 ( struct V_18 * V_19 )
{
int V_54 ;
T_3 V_55 ;
T_2 clock ;
T_1 V_56 , V_57 , V_58 , V_59 , V_60 ;
unsigned long V_61 ;
T_1 V_62 , V_63 , V_64 , V_65 , V_66 ;
T_3 V_67 ;
V_19 -> V_16 . V_68 = F_11 ;
V_19 -> V_16 . V_69 = F_12 ;
V_19 -> V_16 . V_70 = F_15 ;
V_19 -> V_16 . V_71 = F_16 ;
V_19 -> V_16 . V_72 = F_17 ;
V_19 -> V_16 . V_73 = V_74 ;
V_19 -> V_16 . V_75 . V_76 = V_77 ;
F_19 ( V_19 -> V_3 , V_78 ,
V_79 ) ;
if ( V_19 -> V_3 -> V_80 & V_81 ) {
V_55 = 100000000 ;
} else {
V_55 = F_20 ( V_19 -> V_3 , 4 ) ;
V_55 = ( V_55 * 0xFFF ) >> 3 ;
V_55 = ( V_55 * 25000000 ) >> 3 ;
}
clock = V_55 / 1000000 ;
V_56 = F_1 ( 15 , clock ) ;
V_57 = F_1 ( 20 , clock ) ;
V_58 = F_1 ( 10 , clock ) ;
V_59 = F_1 ( 10 , clock ) ;
V_60 = F_1 ( 100 , clock ) ;
F_3 ( V_19 -> V_3 , V_82 ,
( V_60 << 24 | V_59 << 18 | V_58 << 12 | V_57 << 6 | V_56 ) ) ;
V_54 = F_21 ( & V_19 -> V_13 , 1 ) ;
if ( V_54 ) {
F_5 ( L_17 , V_54 ) ;
goto exit;
}
V_61 = V_19 -> V_16 . V_61 >> 20 ;
V_62 = F_22 ( V_61 ) ;
if ( ! V_62 || V_62 != F_23 ( V_61 ) ) {
F_5 ( L_18 , V_61 ) ;
V_54 = - V_83 ;
goto exit;
}
V_62 += 19 ;
V_63 = V_19 -> V_16 . V_84 + 1 ;
V_64 = ( V_63 + 7 ) / 8 ;
V_65 = V_62 - V_63 + 1 ;
V_66 = ( V_65 + 7 ) / 8 ;
V_67 = ( ( V_66 - 1 ) << 6 ) | ( ( V_64 - 1 ) << 4 ) | 2 ;
F_3 ( V_19 -> V_3 , V_85 , V_67 ) ;
exit:
if ( V_54 )
F_24 ( V_19 -> V_3 , V_78 ,
~ V_79 ) ;
return V_54 ;
}
