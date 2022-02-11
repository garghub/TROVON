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
V_20 = V_28 | V_29 | V_30 | V_31 |
V_32 ;
V_20 |= V_33 << 8 ;
if ( F_2 ( V_19 -> V_3 , V_20 ) )
return;
if ( F_6 ( V_19 -> V_3 ) )
return;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 += 4 , V_21 ++ ) {
V_20 = V_28 | 0x30000000 | V_34 ;
if ( V_5 == V_22 - 4 )
V_20 &= ~ V_28 ;
if ( F_2 ( V_19 -> V_3 ,
V_20 ) )
return;
* V_21 = F_4 ( V_19 -> V_3 , V_35 ) ;
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
const T_3 * V_36 = ( T_3 * ) V_14 ;
int V_5 ;
F_8 ( V_19 -> V_23 & ~ V_16 -> V_24 ) ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 += 4 , V_36 ++ ) {
F_3 ( V_3 , V_35 , * V_36 ) ;
V_20 = V_28 | 0x30000000 | V_37 ;
if ( V_5 == V_15 - 4 )
V_20 &= ~ V_28 ;
if ( F_2 ( V_3 , V_20 ) ) {
F_5 ( L_4 , V_38 ) ;
return;
}
}
V_19 -> V_26 += V_15 ;
}
static void F_11 ( struct V_12 * V_13 , int V_39 ,
unsigned int V_40 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
T_3 V_4 = 0 ;
if ( V_39 == V_41 )
return;
if ( V_39 & V_42 )
V_4 = V_39 | V_32 ;
if ( V_39 != V_43 )
V_4 |= V_28 ;
F_2 ( V_19 -> V_3 , V_4 ) ;
}
static void F_12 ( struct V_12 * V_13 ,
int V_44 )
{
return;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
return ! ! ( F_4 ( V_19 -> V_3 , V_6 ) & V_10 ) ;
}
static void F_14 ( struct V_12 * V_13 ,
unsigned V_45 , int V_46 ,
int V_47 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
struct V_2 * V_3 = V_19 -> V_3 ;
T_3 V_20 ;
int V_5 ;
if ( V_46 != - 1 )
V_19 -> V_26 = V_46 ;
if ( V_47 != - 1 )
V_19 -> V_23 = V_47 ;
switch ( V_45 ) {
case V_43 :
V_16 -> V_48 ( V_13 , V_45 , V_42 ) ;
F_15 ( 100 ) ;
F_16 ( V_13 ) ;
break;
case V_49 :
V_20 = V_28 | 0x01000000 | V_29 | V_32 ;
V_20 |= V_49 ;
if ( F_2 ( V_19 -> V_3 , V_20 ) ) {
F_5 ( L_5 ) ;
break;
}
for ( V_5 = 0 ; V_5 < F_17 ( V_19 -> V_50 ) ; V_5 ++ ) {
V_20 = V_28 | V_34 ;
if ( V_5 == F_17 ( V_19 -> V_50 ) - 1 )
V_20 &= ~ V_28 ;
if ( F_2 ( V_19 -> V_3 ,
V_20 ) ) {
F_5 ( L_5 ) ;
break;
}
V_19 -> V_50 [ V_5 ] =
F_4 ( V_19 -> V_3 , V_35 )
& 0xFF ;
}
break;
case V_51 :
V_20 = V_28 | V_32 | V_51 ;
if ( F_2 ( V_3 , V_20 ) )
F_5 ( L_6 ) ;
break;
case V_52 :
break;
case V_53 :
if ( V_47 != - 1 )
V_19 -> V_26 += V_13 -> V_54 ;
break;
case V_55 :
F_3 ( V_3 , V_27 ,
V_19 -> V_23 ) ;
V_20 = V_30 | V_29 | V_32 |
V_55 | ( V_56 << 8 ) ;
if ( F_2 ( V_3 , V_20 ) )
F_5 ( L_7 ) ;
break;
case V_56 :
break;
case V_57 :
F_3 ( V_3 , V_25 ,
V_19 -> V_26 ) ;
F_3 ( V_3 , V_27 ,
V_19 -> V_23 ) ;
V_20 = 0x40000000 | V_30 | V_31 | V_32 ;
V_20 |= V_57 ;
if ( F_2 ( V_3 , V_20 ) )
F_5 ( L_8 ) ;
break;
case V_58 :
if ( F_2 ( V_3 , V_32 |
V_58 ) )
F_5 ( L_9 ) ;
if ( F_6 ( V_3 ) )
F_5 ( L_10 ) ;
break;
default:
F_5 ( L_11 , V_45 ) ;
break;
}
V_19 -> V_59 = V_45 ;
}
static T_1 F_18 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
struct V_2 * V_3 = V_19 -> V_3 ;
T_3 V_60 = 0 ;
switch ( V_19 -> V_59 ) {
case V_49 :
if ( V_19 -> V_26 >= F_17 ( V_19 -> V_50 ) ) {
F_5 ( L_12 ,
V_19 -> V_26 ) ;
return 0 ;
}
return V_19 -> V_50 [ V_19 -> V_26 ++ ] ;
case V_51 :
if ( F_2 ( V_3 , V_34 ) )
return 0 ;
return F_4 ( V_3 , V_35 ) & 0xff ;
case V_53 :
F_7 ( V_13 , ( T_1 * ) & V_60 , 4 ) ;
return V_60 & 0xFF ;
}
F_5 ( L_13 , V_19 -> V_59 ) ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 ,
T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
switch ( V_19 -> V_59 ) {
case V_52 :
case V_53 :
F_7 ( V_13 , V_14 , V_15 ) ;
return;
}
F_5 ( L_14 , V_19 -> V_59 ) ;
}
static void F_20 ( struct V_12 * V_13 ,
const T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = (struct V_16 * ) V_13 -> V_17 ;
struct V_18 * V_19 = (struct V_18 * ) V_16 -> V_17 ;
switch ( V_19 -> V_59 ) {
case V_57 :
F_10 ( V_13 , V_14 , V_15 ) ;
return;
}
F_5 ( L_15 , V_19 -> V_59 ) ;
}
int F_21 ( struct V_18 * V_19 )
{
struct V_16 * V_16 = (struct V_16 * ) & V_19 -> V_16 ;
int V_61 ;
T_3 V_62 ;
T_2 clock ;
T_1 V_63 , V_64 , V_65 , V_66 , V_67 ;
unsigned long V_68 ;
T_1 V_69 , V_70 , V_71 , V_72 , V_73 ;
T_3 V_74 ;
V_19 -> V_16 . V_75 = F_12 ;
V_16 -> V_48 = F_11 ;
V_16 -> V_76 = F_13 ;
V_19 -> V_16 . V_77 = F_14 ;
V_19 -> V_16 . V_78 = F_18 ;
V_19 -> V_16 . V_79 = F_19 ;
V_19 -> V_16 . V_80 = F_20 ;
V_16 -> V_81 = 50 ;
V_19 -> V_16 . V_82 = V_83 ;
V_19 -> V_16 . V_84 . V_85 = V_86 ;
F_22 ( V_19 -> V_3 , V_87 ,
V_88 ) ;
if ( V_19 -> V_3 -> V_89 & V_90 ) {
V_62 = 400000000 / 4 ;
} else {
V_62 = F_23 ( V_19 -> V_3 , 4 ) ;
V_62 = ( V_62 & 0xFFF ) >> 3 ;
V_62 = ( V_62 * 25000000 / 2 ) / 4 ;
}
clock = V_62 / 1000000 ;
V_63 = F_1 ( 15 , clock ) ;
V_64 = F_1 ( 20 , clock ) ;
V_65 = F_1 ( 10 , clock ) ;
V_66 = F_1 ( 10 , clock ) ;
V_67 = F_1 ( 100 , clock ) ;
F_3 ( V_19 -> V_3 , V_91 ,
( V_67 << 24 | V_66 << 18 | V_65 << 12 | V_64 << 6 | V_63 ) ) ;
V_61 = F_24 ( & V_19 -> V_13 , 1 ) ;
if ( V_61 ) {
F_5 ( L_16 , V_61 ) ;
goto exit;
}
V_68 = V_19 -> V_16 . V_68 >> 20 ;
V_69 = F_25 ( V_68 ) ;
if ( ! V_69 || V_69 != F_26 ( V_68 ) ) {
F_5 ( L_17 , V_68 ) ;
V_61 = - V_92 ;
goto exit;
}
V_69 += 19 ;
V_70 = V_19 -> V_16 . V_93 + 1 ;
V_71 = ( V_70 + 7 ) / 8 ;
V_72 = V_69 - V_70 + 1 ;
V_73 = ( V_72 + 7 ) / 8 ;
V_74 = ( ( V_73 - 1 ) << 6 ) | ( ( V_71 - 1 ) << 4 ) | 2 ;
F_3 ( V_19 -> V_3 , V_94 , V_74 ) ;
exit:
if ( V_61 )
F_27 ( V_19 -> V_3 , V_87 ,
~ V_88 ) ;
return V_61 ;
}
