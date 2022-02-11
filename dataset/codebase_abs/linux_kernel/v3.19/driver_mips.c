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
unsigned int F_9 ( struct V_1 * V_2 )
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
static void F_11 ( struct V_1 * V_2 , unsigned int V_24 )
{
unsigned int V_25 = F_9 ( V_2 ) ;
struct V_26 * V_3 = V_2 -> V_3 ;
struct V_1 * V_21 = V_3 -> V_22 . V_16 ;
T_1 V_23 ;
V_23 = F_7 ( V_2 ) ;
F_12 ( V_25 == 6 ) ;
V_2 -> V_24 = V_24 + 2 ;
if ( V_25 == 0 )
F_6 ( V_21 , F_10 ( 0 ) ,
F_4 ( V_21 , F_10 ( 0 ) ) &
~ ( 1 << V_23 ) ) ;
else if ( V_25 != 5 )
F_6 ( V_21 , F_10 ( V_25 ) , 0 ) ;
if ( V_24 == 0 ) {
F_6 ( V_21 , F_10 ( 0 ) ,
F_4 ( V_21 , F_10 ( 0 ) ) |
( 1 << V_23 ) ) ;
} else {
T_1 V_27 = F_4 ( V_21 ,
F_10 ( V_24 ) ) ;
if ( V_27 ) {
struct V_1 * V_16 ;
F_13 (core, &bus->cores, list) {
if ( ( 1 << F_7 ( V_16 ) ) ==
V_27 ) {
F_11 ( V_16 , 0 ) ;
break;
}
}
}
F_6 ( V_21 , F_10 ( V_24 ) ,
1 << V_23 ) ;
}
F_14 ( V_3 , L_1 ,
V_2 -> V_5 . V_5 , V_25 <= 4 ? V_25 + 2 : 0 , V_24 + 2 ) ;
}
static void F_15 ( struct V_26 * V_3 , unsigned int V_24 ,
T_2 V_28 , T_3 V_29 )
{
struct V_1 * V_16 ;
V_16 = F_16 ( V_3 , V_28 , V_29 ) ;
if ( ! V_16 ) {
F_17 ( V_3 ,
L_2 ,
V_28 , V_29 ) ;
return;
}
F_11 ( V_16 , V_24 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_24 )
{
int V_30 ;
static const char * V_31 [] = { L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 } ;
F_19 (KERN_DEBUG KBUILD_MODNAME L_10 , dev->id.id) ;
for ( V_30 = 0 ; V_30 <= 6 ; V_30 ++ )
F_19 ( L_11 , V_31 [ V_30 ] , V_30 == V_24 ? L_12 : L_13 ) ;
F_19 ( L_14 ) ;
}
static void F_20 ( struct V_26 * V_3 )
{
struct V_1 * V_16 ;
F_13 (core, &bus->cores, list) {
F_18 ( V_16 , F_9 ( V_16 ) ) ;
}
}
T_1 F_21 ( struct V_13 * V_14 )
{
struct V_26 * V_3 = V_14 -> V_16 -> V_3 ;
if ( V_3 -> V_32 . V_33 & V_34 )
return F_22 ( & V_3 -> V_32 ) ;
F_23 ( V_3 , L_15 ) ;
return 0 ;
}
static enum V_35 V_35 ( struct V_26 * V_3 )
{
struct V_36 * V_37 = & V_3 -> V_32 ;
T_3 V_38 = V_37 -> V_16 -> V_5 . V_7 ;
if ( V_38 == 42 ) {
struct V_1 * V_16 ;
V_16 = F_24 ( V_3 , V_39 ) ;
if ( V_16 ) {
switch ( F_8 ( V_16 , V_40 ) &
V_41 ) {
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
case V_46 :
default:
return V_47 ;
}
}
} else {
if ( V_38 == 38 ) {
if ( V_37 -> V_48 & V_49 )
return V_45 ;
else if ( V_37 -> V_48 & F_25 ( 5 ) )
return V_47 ;
}
if ( ( V_37 -> V_33 & V_50 ) ==
V_51 )
return V_52 ;
else
return V_43 ;
}
return V_43 ;
}
static void F_26 ( struct V_13 * V_14 )
{
struct V_26 * V_3 = V_14 -> V_16 -> V_3 ;
struct V_36 * V_37 = & V_3 -> V_32 ;
struct V_53 * V_54 = & V_37 -> V_54 ;
enum V_35 V_55 ;
switch ( V_37 -> V_33 & V_50 ) {
case V_56 :
case V_57 :
F_14 ( V_3 , L_16 ) ;
F_27 ( V_37 ) ;
break;
case V_51 :
F_14 ( V_3 , L_17 ) ;
V_54 -> V_58 = true ;
V_54 -> V_59 = V_60 ;
V_54 -> V_61 = V_62 ;
if ( ( F_4 ( V_37 -> V_16 , V_63 ) &
V_64 ) == 0 )
V_54 -> V_65 = 1 ;
else
V_54 -> V_65 = 2 ;
V_66 . V_67 = V_54 -> V_65 ;
V_68 . V_69 = V_54 -> V_59 ;
V_68 . V_70 = V_54 -> V_59 + V_54 -> V_61 ;
break;
default:
F_23 ( V_3 , L_18 ) ;
}
if ( V_37 -> V_16 -> V_5 . V_7 == 38 ||
V_3 -> V_4 . V_5 == V_71 ) {
if ( V_37 -> V_33 & V_72 ) {
F_14 ( V_3 , L_19 ) ;
F_28 ( V_37 ) ;
}
}
V_55 = V_35 ( V_3 ) ;
switch ( V_55 ) {
case V_52 :
case V_43 :
#ifdef F_29
F_30 ( V_60 ,
V_62 ) ;
#endif
break;
case V_45 :
#ifdef F_29
F_30 ( V_73 ,
V_74 ) ;
#endif
break;
default:
break;
}
}
void F_31 ( struct V_13 * V_14 )
{
struct V_26 * V_3 = V_14 -> V_16 -> V_3 ;
if ( V_14 -> V_75 )
return;
F_32 ( & V_3 -> V_32 ) ;
F_26 ( V_14 ) ;
V_14 -> V_75 = true ;
}
static void F_33 ( struct V_26 * V_3 )
{
struct V_1 * V_76 , * V_77 , * V_78 ;
if ( V_3 -> V_4 . V_5 != V_79 &&
V_3 -> V_4 . V_5 != V_80 )
return;
V_76 = F_24 ( V_3 , V_8 ) ;
V_77 = F_24 ( V_3 , V_81 ) ;
V_78 = F_24 ( V_3 , V_82 ) ;
if ( V_76 && V_77 && V_78 &&
F_8 ( V_76 , V_83 ) == 0x08060504 &&
F_8 ( V_77 , V_83 ) == 0x08060504 &&
F_8 ( V_78 , V_20 ) == 0x88 ) {
F_34 ( V_76 , V_83 , 0x07060504 ) ;
F_34 ( V_77 , V_83 , 0x07060504 ) ;
F_34 ( V_78 , V_20 , 0x87 ) ;
F_14 ( V_3 ,
L_20 ) ;
}
}
void F_35 ( struct V_13 * V_14 )
{
struct V_26 * V_3 ;
struct V_1 * V_16 ;
V_3 = V_14 -> V_16 -> V_3 ;
if ( V_14 -> V_84 )
return;
F_14 ( V_3 , L_21 ) ;
F_31 ( V_14 ) ;
F_33 ( V_3 ) ;
switch ( V_3 -> V_4 . V_5 ) {
case V_79 :
case V_80 :
F_15 ( V_3 , 1 , V_85 , 0 ) ;
F_15 ( V_3 , 2 , V_86 , 0 ) ;
F_15 ( V_3 , 3 , V_12 , 0 ) ;
F_15 ( V_3 , 4 , V_81 , 0 ) ;
F_15 ( V_3 , 0 , V_87 , 0 ) ;
F_15 ( V_3 , 0 , V_82 , 0 ) ;
break;
case V_88 :
case V_6 :
case V_89 :
F_15 ( V_3 , 1 , V_85 , 0 ) ;
F_15 ( V_3 , 2 , V_86 , 0 ) ;
F_15 ( V_3 , 0 , V_87 , 0 ) ;
break;
case V_9 :
case V_10 :
F_15 ( V_3 , 1 , V_85 , 0 ) ;
F_15 ( V_3 , 2 , V_86 , 0 ) ;
F_15 ( V_3 , 3 , V_12 , 0 ) ;
F_15 ( V_3 , 0 , V_87 , 0 ) ;
F_15 ( V_3 , 0 , V_82 , 0 ) ;
break;
case V_71 :
F_15 ( V_3 , 1 , V_81 , 0 ) ;
F_15 ( V_3 , 2 , V_90 ,
0 ) ;
F_15 ( V_3 , 3 , V_81 , 1 ) ;
F_15 ( V_3 , 4 , V_12 , 0 ) ;
F_15 ( V_3 , 0 , V_91 ,
0 ) ;
break;
default:
F_13 (core, &bus->cores, list) {
V_16 -> V_24 = F_36 ( V_16 , 0 ) ;
}
F_23 ( V_3 ,
L_22 ,
V_3 -> V_4 . V_5 ) ;
}
F_14 ( V_3 , L_23 ) ;
F_20 ( V_3 ) ;
V_14 -> V_84 = true ;
}
