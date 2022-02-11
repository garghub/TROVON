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
enum V_35 V_53 ;
V_53 = V_35 ( V_3 ) ;
switch ( V_53 ) {
case V_52 :
case V_43 :
#ifdef F_27
F_28 ( V_54 ,
V_55 ) ;
#endif
break;
case V_45 :
#ifdef F_27
F_28 ( V_56 ,
V_57 ) ;
#endif
break;
default:
break;
}
}
void F_29 ( struct V_13 * V_14 )
{
if ( V_14 -> V_58 )
return;
F_26 ( V_14 ) ;
V_14 -> V_58 = true ;
}
static void F_30 ( struct V_26 * V_3 )
{
struct V_1 * V_59 , * V_60 , * V_61 ;
if ( V_3 -> V_4 . V_5 != V_62 &&
V_3 -> V_4 . V_5 != V_63 )
return;
V_59 = F_24 ( V_3 , V_8 ) ;
V_60 = F_24 ( V_3 , V_64 ) ;
V_61 = F_24 ( V_3 , V_65 ) ;
if ( V_59 && V_60 && V_61 &&
F_8 ( V_59 , V_66 ) == 0x08060504 &&
F_8 ( V_60 , V_66 ) == 0x08060504 &&
F_8 ( V_61 , V_20 ) == 0x88 ) {
F_31 ( V_59 , V_66 , 0x07060504 ) ;
F_31 ( V_60 , V_66 , 0x07060504 ) ;
F_31 ( V_61 , V_20 , 0x87 ) ;
F_14 ( V_3 ,
L_16 ) ;
}
}
void F_32 ( struct V_13 * V_14 )
{
struct V_26 * V_3 ;
struct V_1 * V_16 ;
V_3 = V_14 -> V_16 -> V_3 ;
if ( V_14 -> V_67 )
return;
F_14 ( V_3 , L_17 ) ;
F_29 ( V_14 ) ;
F_30 ( V_3 ) ;
switch ( V_3 -> V_4 . V_5 ) {
case V_62 :
case V_63 :
F_15 ( V_3 , 1 , V_68 , 0 ) ;
F_15 ( V_3 , 2 , V_69 , 0 ) ;
F_15 ( V_3 , 3 , V_12 , 0 ) ;
F_15 ( V_3 , 4 , V_64 , 0 ) ;
F_15 ( V_3 , 0 , V_70 , 0 ) ;
F_15 ( V_3 , 0 , V_65 , 0 ) ;
break;
case V_71 :
case V_6 :
case V_72 :
F_15 ( V_3 , 1 , V_68 , 0 ) ;
F_15 ( V_3 , 2 , V_69 , 0 ) ;
F_15 ( V_3 , 0 , V_70 , 0 ) ;
break;
case V_9 :
case V_10 :
F_15 ( V_3 , 1 , V_68 , 0 ) ;
F_15 ( V_3 , 2 , V_69 , 0 ) ;
F_15 ( V_3 , 3 , V_12 , 0 ) ;
F_15 ( V_3 , 0 , V_70 , 0 ) ;
F_15 ( V_3 , 0 , V_65 , 0 ) ;
break;
case V_73 :
F_15 ( V_3 , 1 , V_64 , 0 ) ;
F_15 ( V_3 , 2 , V_74 ,
0 ) ;
F_15 ( V_3 , 3 , V_64 , 1 ) ;
F_15 ( V_3 , 4 , V_12 , 0 ) ;
F_15 ( V_3 , 0 , V_75 ,
0 ) ;
break;
default:
F_13 (core, &bus->cores, list) {
V_16 -> V_24 = F_33 ( V_16 , 0 ) ;
}
F_23 ( V_3 ,
L_18 ,
V_3 -> V_4 . V_5 ) ;
}
F_14 ( V_3 , L_19 ) ;
F_20 ( V_3 ) ;
V_14 -> V_67 = true ;
}
