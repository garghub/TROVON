static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 . V_5 == V_6 &&
V_2 -> V_3 -> V_4 . V_7 == 0 && V_2 -> V_5 . V_5 == V_8 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 -> V_4 . V_5 == V_9 ||
V_2 -> V_3 -> V_4 . V_5 == V_10 ) &&
V_2 -> V_3 -> V_4 . V_11 == 11 &&
V_2 -> V_5 . V_5 == V_12 ;
}
static inline T_1 F_3 ( struct V_13 * V_14 ,
T_2 V_15 )
{
return F_4 ( V_14 -> V_16 , V_15 ) ;
}
static inline void F_5 ( struct V_13 * V_14 ,
T_2 V_15 ,
T_1 V_17 )
{
F_6 ( V_14 -> V_16 , V_15 , V_17 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_18 ;
if ( F_1 ( V_2 ) )
return V_2 -> V_19 ;
if ( F_2 ( V_2 ) )
return V_2 -> V_19 ;
V_18 = F_8 ( V_2 , V_20 ) ;
if ( V_18 )
return V_18 & 0x1F ;
else
return 0x3f ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_21 = V_2 -> V_3 -> V_22 . V_16 ;
T_1 V_23 ;
unsigned int V_24 ;
V_23 = F_7 ( V_2 ) ;
if ( V_23 == 0x3f )
return 6 ;
for ( V_24 = 0 ; V_24 <= 4 ; V_24 ++ )
if ( F_4 ( V_21 , F_10 ( V_24 ) ) &
( 1 << V_23 ) )
return V_24 ;
return 5 ;
}
unsigned int F_11 ( struct V_1 * V_2 )
{
unsigned int V_25 = F_9 ( V_2 ) ;
return V_25 <= 4 ? V_25 + 2 : 0 ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_24 )
{
unsigned int V_26 = F_9 ( V_2 ) ;
struct V_27 * V_3 = V_2 -> V_3 ;
struct V_1 * V_21 = V_3 -> V_22 . V_16 ;
T_1 V_23 ;
V_23 = F_7 ( V_2 ) ;
F_13 ( V_26 == 6 ) ;
V_2 -> V_24 = V_24 + 2 ;
if ( V_26 == 0 )
F_6 ( V_21 , F_10 ( 0 ) ,
F_4 ( V_21 , F_10 ( 0 ) ) &
~ ( 1 << V_23 ) ) ;
else if ( V_26 != 5 )
F_6 ( V_21 , F_10 ( V_26 ) , 0 ) ;
if ( V_24 == 0 ) {
F_6 ( V_21 , F_10 ( 0 ) ,
F_4 ( V_21 , F_10 ( 0 ) ) |
( 1 << V_23 ) ) ;
} else {
T_1 V_28 = F_4 ( V_21 ,
F_10 ( V_24 ) ) ;
if ( V_28 ) {
struct V_1 * V_16 ;
F_14 (core, &bus->cores, list) {
if ( ( 1 << F_7 ( V_16 ) ) ==
V_28 ) {
F_12 ( V_16 , 0 ) ;
break;
}
}
}
F_6 ( V_21 , F_10 ( V_24 ) ,
1 << V_23 ) ;
}
F_15 ( V_3 , L_1 ,
V_2 -> V_5 . V_5 , V_26 <= 4 ? V_26 + 2 : 0 , V_24 + 2 ) ;
}
static void F_16 ( struct V_27 * V_3 , unsigned int V_24 ,
T_2 V_29 , T_3 V_30 )
{
struct V_1 * V_16 ;
V_16 = F_17 ( V_3 , V_29 , V_30 ) ;
if ( ! V_16 ) {
F_18 ( V_3 ,
L_2 ,
V_29 , V_30 ) ;
return;
}
F_12 ( V_16 , V_24 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_24 )
{
int V_31 ;
static const char * V_32 [] = { L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 } ;
F_20 (KERN_DEBUG KBUILD_MODNAME L_10 , dev->id.id) ;
for ( V_31 = 0 ; V_31 <= 6 ; V_31 ++ )
F_20 ( L_11 , V_32 [ V_31 ] , V_31 == V_24 ? L_12 : L_13 ) ;
F_20 ( L_14 ) ;
}
static void F_21 ( struct V_27 * V_3 )
{
struct V_1 * V_16 ;
F_14 (core, &bus->cores, list) {
F_19 ( V_16 , F_9 ( V_16 ) ) ;
}
}
T_1 F_22 ( struct V_13 * V_14 )
{
struct V_27 * V_3 = V_14 -> V_16 -> V_3 ;
if ( V_3 -> V_33 . V_34 & V_35 )
return F_23 ( & V_3 -> V_33 ) ;
F_24 ( V_3 , L_15 ) ;
return 0 ;
}
static enum V_36 V_36 ( struct V_27 * V_3 )
{
struct V_37 * V_38 = & V_3 -> V_33 ;
T_3 V_39 = V_38 -> V_16 -> V_5 . V_7 ;
if ( V_39 == 42 ) {
struct V_1 * V_16 ;
V_16 = F_25 ( V_3 , V_40 ) ;
if ( V_16 ) {
switch ( F_8 ( V_16 , V_41 ) &
V_42 ) {
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
case V_47 :
default:
return V_48 ;
}
}
} else {
if ( V_39 == 38 ) {
if ( V_38 -> V_49 & V_50 )
return V_46 ;
else if ( V_38 -> V_49 & F_26 ( 5 ) )
return V_48 ;
}
if ( ( V_38 -> V_34 & V_51 ) ==
V_52 )
return V_53 ;
else
return V_44 ;
}
return V_44 ;
}
static void F_27 ( struct V_13 * V_14 )
{
struct V_27 * V_3 = V_14 -> V_16 -> V_3 ;
struct V_37 * V_38 = & V_3 -> V_33 ;
struct V_54 * V_55 = & V_38 -> V_55 ;
enum V_36 V_56 ;
switch ( V_38 -> V_34 & V_51 ) {
case V_57 :
case V_58 :
F_15 ( V_3 , L_16 ) ;
F_28 ( V_38 ) ;
break;
case V_52 :
F_15 ( V_3 , L_17 ) ;
V_55 -> V_59 = true ;
V_55 -> V_60 = V_61 ;
V_55 -> V_62 = V_63 ;
if ( ( F_4 ( V_38 -> V_16 , V_64 ) &
V_65 ) == 0 )
V_55 -> V_66 = 1 ;
else
V_55 -> V_66 = 2 ;
V_67 . V_68 = V_55 -> V_66 ;
V_69 . V_70 = V_55 -> V_60 ;
V_69 . V_71 = V_55 -> V_60 + V_55 -> V_62 ;
break;
default:
F_24 ( V_3 , L_18 ) ;
}
if ( V_38 -> V_16 -> V_5 . V_7 == 38 ||
V_3 -> V_4 . V_5 == V_72 ) {
if ( V_38 -> V_34 & V_73 ) {
F_15 ( V_3 , L_19 ) ;
F_29 ( V_38 ) ;
}
}
V_56 = V_36 ( V_3 ) ;
switch ( V_56 ) {
case V_53 :
case V_44 :
break;
case V_46 :
break;
default:
break;
}
}
void F_30 ( struct V_13 * V_14 )
{
struct V_27 * V_3 = V_14 -> V_16 -> V_3 ;
if ( V_14 -> V_74 )
return;
F_31 ( & V_3 -> V_33 ) ;
F_27 ( V_14 ) ;
V_14 -> V_74 = true ;
}
static void F_32 ( struct V_27 * V_3 )
{
struct V_1 * V_75 , * V_76 , * V_77 ;
if ( V_3 -> V_4 . V_5 != V_78 &&
V_3 -> V_4 . V_5 != V_79 )
return;
V_75 = F_25 ( V_3 , V_8 ) ;
V_76 = F_25 ( V_3 , V_80 ) ;
V_77 = F_25 ( V_3 , V_81 ) ;
if ( V_75 && V_76 && V_77 &&
F_8 ( V_75 , V_82 ) == 0x08060504 &&
F_8 ( V_76 , V_82 ) == 0x08060504 &&
F_8 ( V_77 , V_20 ) == 0x88 ) {
F_33 ( V_75 , V_82 , 0x07060504 ) ;
F_33 ( V_76 , V_82 , 0x07060504 ) ;
F_33 ( V_77 , V_20 , 0x87 ) ;
F_15 ( V_3 ,
L_20 ) ;
}
}
void F_34 ( struct V_13 * V_14 )
{
struct V_27 * V_3 ;
struct V_1 * V_16 ;
V_3 = V_14 -> V_16 -> V_3 ;
if ( V_14 -> V_83 )
return;
F_15 ( V_3 , L_21 ) ;
F_30 ( V_14 ) ;
F_32 ( V_3 ) ;
switch ( V_3 -> V_4 . V_5 ) {
case V_78 :
case V_79 :
F_16 ( V_3 , 1 , V_84 , 0 ) ;
F_16 ( V_3 , 2 , V_85 , 0 ) ;
F_16 ( V_3 , 3 , V_12 , 0 ) ;
F_16 ( V_3 , 4 , V_80 , 0 ) ;
F_16 ( V_3 , 0 , V_86 , 0 ) ;
F_16 ( V_3 , 0 , V_81 , 0 ) ;
break;
case V_87 :
case V_6 :
case V_88 :
F_16 ( V_3 , 1 , V_84 , 0 ) ;
F_16 ( V_3 , 2 , V_85 , 0 ) ;
F_16 ( V_3 , 0 , V_86 , 0 ) ;
break;
case V_9 :
case V_10 :
F_16 ( V_3 , 1 , V_84 , 0 ) ;
F_16 ( V_3 , 2 , V_85 , 0 ) ;
F_16 ( V_3 , 3 , V_12 , 0 ) ;
F_16 ( V_3 , 0 , V_86 , 0 ) ;
F_16 ( V_3 , 0 , V_81 , 0 ) ;
break;
case V_72 :
F_16 ( V_3 , 1 , V_80 , 0 ) ;
F_16 ( V_3 , 2 , V_89 ,
0 ) ;
F_16 ( V_3 , 3 , V_80 , 1 ) ;
F_16 ( V_3 , 4 , V_12 , 0 ) ;
F_16 ( V_3 , 0 , V_90 ,
0 ) ;
break;
default:
F_14 (core, &bus->cores, list) {
V_16 -> V_24 = F_11 ( V_16 ) ;
}
F_24 ( V_3 ,
L_22 ,
V_3 -> V_4 . V_5 ) ;
}
F_15 ( V_3 , L_23 ) ;
F_21 ( V_3 ) ;
V_14 -> V_83 = true ;
}
