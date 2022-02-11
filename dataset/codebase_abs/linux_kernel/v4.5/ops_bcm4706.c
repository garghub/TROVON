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
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
T_3 V_19 ;
T_3 * V_20 = ( T_3 * ) V_14 ;
int V_5 ;
int V_21 ;
F_10 ( V_18 -> V_22 & ~ V_16 -> V_23 ) ;
while ( V_15 ) {
V_21 = F_11 ( V_15 , 0x200 ) ;
F_3 ( V_18 -> V_3 , V_24 ,
V_18 -> V_25 ) ;
F_3 ( V_18 -> V_3 , V_26 ,
V_18 -> V_22 ) ;
V_19 = V_27 | V_28 | V_29 | V_30 |
V_31 ;
V_19 |= V_32 << 8 ;
if ( F_2 ( V_18 -> V_3 , V_19 ) )
return;
if ( F_6 ( V_18 -> V_3 ) )
return;
for ( V_5 = 0 ; V_5 < V_21 ; V_5 += 4 , V_20 ++ ) {
V_19 = V_27 | 0x30000000 | V_33 ;
if ( V_5 == V_21 - 4 )
V_19 &= ~ V_27 ;
if ( F_2 ( V_18 -> V_3 ,
V_19 ) )
return;
* V_20 = F_4 ( V_18 -> V_3 , V_34 ) ;
}
V_18 -> V_25 += V_21 ;
V_15 -= V_21 ;
}
}
static void F_12 ( struct V_12 * V_13 ,
const T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
struct V_2 * V_3 = V_18 -> V_3 ;
T_3 V_19 ;
const T_3 * V_35 = ( T_3 * ) V_14 ;
int V_5 ;
F_10 ( V_18 -> V_22 & ~ V_16 -> V_23 ) ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 += 4 , V_35 ++ ) {
F_3 ( V_3 , V_34 , * V_35 ) ;
V_19 = V_27 | 0x30000000 | V_36 ;
if ( V_5 == V_15 - 4 )
V_19 &= ~ V_27 ;
if ( F_2 ( V_3 , V_19 ) ) {
F_5 ( L_4 , V_37 ) ;
return;
}
}
V_18 -> V_25 += V_15 ;
}
static void F_13 ( struct V_12 * V_13 , int V_38 ,
unsigned int V_39 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
T_3 V_4 = 0 ;
if ( V_38 == V_40 )
return;
if ( V_38 & V_41 )
V_4 = V_38 | V_31 ;
if ( V_38 != V_42 )
V_4 |= V_27 ;
F_2 ( V_18 -> V_3 , V_4 ) ;
}
static void F_14 ( struct V_12 * V_13 ,
int V_43 )
{
return;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
return ! ! ( F_4 ( V_18 -> V_3 , V_6 ) & V_10 ) ;
}
static void F_16 ( struct V_12 * V_13 ,
unsigned V_44 , int V_45 ,
int V_46 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
struct V_2 * V_3 = V_18 -> V_3 ;
T_3 V_19 ;
int V_5 ;
if ( V_45 != - 1 )
V_18 -> V_25 = V_45 ;
if ( V_46 != - 1 )
V_18 -> V_22 = V_46 ;
switch ( V_44 ) {
case V_42 :
V_16 -> V_47 ( V_13 , V_44 , V_41 ) ;
F_17 ( 100 ) ;
F_18 ( V_13 ) ;
break;
case V_48 :
V_19 = V_27 | 0x01000000 | V_28 | V_31 ;
V_19 |= V_48 ;
if ( F_2 ( V_18 -> V_3 , V_19 ) ) {
F_5 ( L_5 ) ;
break;
}
for ( V_5 = 0 ; V_5 < F_19 ( V_18 -> V_49 ) ; V_5 ++ ) {
V_19 = V_27 | V_33 ;
if ( V_5 == F_19 ( V_18 -> V_49 ) - 1 )
V_19 &= ~ V_27 ;
if ( F_2 ( V_18 -> V_3 ,
V_19 ) ) {
F_5 ( L_5 ) ;
break;
}
V_18 -> V_49 [ V_5 ] =
F_4 ( V_18 -> V_3 , V_34 )
& 0xFF ;
}
break;
case V_50 :
V_19 = V_27 | V_31 | V_50 ;
if ( F_2 ( V_3 , V_19 ) )
F_5 ( L_6 ) ;
break;
case V_51 :
break;
case V_52 :
if ( V_46 != - 1 )
V_18 -> V_25 += V_13 -> V_53 ;
break;
case V_54 :
F_3 ( V_3 , V_26 ,
V_18 -> V_22 ) ;
V_19 = V_29 | V_28 | V_31 |
V_54 | ( V_55 << 8 ) ;
if ( F_2 ( V_3 , V_19 ) )
F_5 ( L_7 ) ;
break;
case V_55 :
break;
case V_56 :
F_3 ( V_3 , V_24 ,
V_18 -> V_25 ) ;
F_3 ( V_3 , V_26 ,
V_18 -> V_22 ) ;
V_19 = 0x40000000 | V_29 | V_30 | V_31 ;
V_19 |= V_56 ;
if ( F_2 ( V_3 , V_19 ) )
F_5 ( L_8 ) ;
break;
case V_57 :
if ( F_2 ( V_3 , V_31 |
V_57 ) )
F_5 ( L_9 ) ;
if ( F_6 ( V_3 ) )
F_5 ( L_10 ) ;
break;
default:
F_5 ( L_11 , V_44 ) ;
break;
}
V_18 -> V_58 = V_44 ;
}
static T_1 F_20 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
struct V_2 * V_3 = V_18 -> V_3 ;
T_3 V_59 = 0 ;
switch ( V_18 -> V_58 ) {
case V_48 :
if ( V_18 -> V_25 >= F_19 ( V_18 -> V_49 ) ) {
F_5 ( L_12 ,
V_18 -> V_25 ) ;
return 0 ;
}
return V_18 -> V_49 [ V_18 -> V_25 ++ ] ;
case V_50 :
if ( F_2 ( V_3 , V_33 ) )
return 0 ;
return F_4 ( V_3 , V_34 ) & 0xff ;
case V_52 :
F_7 ( V_13 , ( T_1 * ) & V_59 , 4 ) ;
return V_59 & 0xFF ;
}
F_5 ( L_13 , V_18 -> V_58 ) ;
return 0 ;
}
static void F_21 ( struct V_12 * V_13 ,
T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
switch ( V_18 -> V_58 ) {
case V_51 :
case V_52 :
F_7 ( V_13 , V_14 , V_15 ) ;
return;
}
F_5 ( L_14 , V_18 -> V_58 ) ;
}
static void F_22 ( struct V_12 * V_13 ,
const T_4 * V_14 , int V_15 )
{
struct V_16 * V_16 = F_8 ( V_13 ) ;
struct V_17 * V_18 = F_9 ( V_16 ) ;
switch ( V_18 -> V_58 ) {
case V_56 :
F_12 ( V_13 , V_14 , V_15 ) ;
return;
}
F_5 ( L_15 , V_18 -> V_58 ) ;
}
int F_23 ( struct V_17 * V_18 )
{
struct V_16 * V_16 = (struct V_16 * ) & V_18 -> V_16 ;
int V_60 ;
T_3 V_61 ;
T_2 clock ;
T_1 V_62 , V_63 , V_64 , V_65 , V_66 ;
unsigned long V_67 ;
T_1 V_68 , V_69 , V_70 , V_71 , V_72 ;
T_3 V_73 ;
V_18 -> V_16 . V_74 = F_14 ;
V_16 -> V_47 = F_13 ;
V_16 -> V_75 = F_15 ;
V_18 -> V_16 . V_76 = F_16 ;
V_18 -> V_16 . V_77 = F_20 ;
V_18 -> V_16 . V_78 = F_21 ;
V_18 -> V_16 . V_79 = F_22 ;
V_16 -> V_80 = 50 ;
V_18 -> V_16 . V_81 = V_82 ;
V_18 -> V_16 . V_83 . V_84 = V_85 ;
F_24 ( V_18 -> V_3 , V_86 ,
V_87 ) ;
if ( V_18 -> V_3 -> V_88 & V_89 ) {
V_61 = 400000000 / 4 ;
} else {
V_61 = F_25 ( V_18 -> V_3 , 4 ) ;
V_61 = ( V_61 & 0xFFF ) >> 3 ;
V_61 = ( V_61 * 25000000 / 2 ) / 4 ;
}
clock = V_61 / 1000000 ;
V_62 = F_1 ( 15 , clock ) ;
V_63 = F_1 ( 20 , clock ) ;
V_64 = F_1 ( 10 , clock ) ;
V_65 = F_1 ( 10 , clock ) ;
V_66 = F_1 ( 100 , clock ) ;
F_3 ( V_18 -> V_3 , V_90 ,
( V_66 << 24 | V_65 << 18 | V_64 << 12 | V_63 << 6 | V_62 ) ) ;
V_60 = F_26 ( F_27 ( & V_18 -> V_16 ) , 1 ) ;
if ( V_60 ) {
F_5 ( L_16 , V_60 ) ;
goto exit;
}
V_67 = V_18 -> V_16 . V_67 >> 20 ;
V_68 = F_28 ( V_67 ) ;
if ( ! V_68 || V_68 != F_29 ( V_67 ) ) {
F_5 ( L_17 , V_67 ) ;
V_60 = - V_91 ;
goto exit;
}
V_68 += 19 ;
V_69 = V_18 -> V_16 . V_92 + 1 ;
V_70 = ( V_69 + 7 ) / 8 ;
V_71 = V_68 - V_69 + 1 ;
V_72 = ( V_71 + 7 ) / 8 ;
V_73 = ( ( V_72 - 1 ) << 6 ) | ( ( V_70 - 1 ) << 4 ) | 2 ;
F_3 ( V_18 -> V_3 , V_93 , V_73 ) ;
exit:
if ( V_60 )
F_30 ( V_18 -> V_3 , V_86 ,
~ V_87 ) ;
return V_60 ;
}
