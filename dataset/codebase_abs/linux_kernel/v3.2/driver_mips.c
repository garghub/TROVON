static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 . V_5 == 47162 && V_2 -> V_3 -> V_4 . V_6 == 0 &&
V_2 -> V_5 . V_5 == V_7 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 -> V_4 . V_5 == 0x5357 ||
V_2 -> V_3 -> V_4 . V_5 == 0x4749 ) &&
V_2 -> V_3 -> V_4 . V_8 == 11 &&
V_2 -> V_5 . V_5 == V_9 ;
}
static inline T_1 F_3 ( struct V_10 * V_11 ,
T_2 V_12 )
{
return F_4 ( V_11 -> V_13 , V_12 ) ;
}
static inline void F_5 ( struct V_10 * V_11 ,
T_2 V_12 ,
T_1 V_14 )
{
F_6 ( V_11 -> V_13 , V_12 , V_14 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( F_1 ( V_2 ) )
return V_2 -> V_16 ;
if ( F_2 ( V_2 ) )
return V_2 -> V_16 ;
V_15 = F_8 ( V_2 , V_17 ) ;
return V_15 & 0x1F ;
}
unsigned int F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_18 = V_2 -> V_3 -> V_19 . V_13 ;
T_1 V_20 ;
unsigned int V_21 ;
V_20 = F_7 ( V_2 ) ;
for ( V_21 = 1 ; V_21 <= 4 ; V_21 ++ )
if ( F_4 ( V_18 , F_10 ( V_21 ) ) &
( 1 << V_20 ) )
return V_21 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_21 )
{
unsigned int V_22 = F_9 ( V_2 ) ;
struct V_23 * V_3 = V_2 -> V_3 ;
struct V_1 * V_18 = V_3 -> V_19 . V_13 ;
T_1 V_20 ;
V_20 = F_7 ( V_2 ) ;
F_12 ( V_22 == 6 ) ;
V_2 -> V_21 = V_21 + 2 ;
if ( V_22 == 0 )
F_6 ( V_18 , F_10 ( 0 ) ,
F_4 ( V_18 , F_10 ( 0 ) ) &
~ ( 1 << V_20 ) ) ;
else
F_6 ( V_18 , F_10 ( V_21 ) , 0 ) ;
if ( V_21 == 0 ) {
F_6 ( V_18 , F_10 ( 0 ) ,
F_4 ( V_18 , F_10 ( 0 ) ) |
( 1 << V_20 ) ) ;
} else {
T_1 V_24 = F_4 ( V_18 ,
F_10 ( V_21 ) ) ;
if ( V_24 ) {
struct V_1 * V_13 ;
F_13 (core, &bus->cores, list) {
if ( ( 1 << F_7 ( V_13 ) ) ==
V_24 ) {
F_11 ( V_13 , 0 ) ;
break;
}
}
}
F_6 ( V_18 , F_10 ( V_21 ) ,
1 << V_20 ) ;
}
F_14 ( L_1 ,
V_2 -> V_5 . V_5 , V_22 + 2 , V_21 + 2 ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_21 )
{
int V_25 ;
static const char * V_26 [] = { L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 } ;
F_16 (KERN_INFO KBUILD_MODNAME L_9 , dev->id.id) ;
for ( V_25 = 0 ; V_25 <= 6 ; V_25 ++ )
F_16 ( L_10 , V_26 [ V_25 ] , V_25 == V_21 ? L_11 : L_12 ) ;
F_16 ( L_13 ) ;
}
static void F_17 ( struct V_23 * V_3 )
{
struct V_1 * V_13 ;
F_13 (core, &bus->cores, list) {
F_15 ( V_13 , F_9 ( V_13 ) ) ;
}
}
T_1 F_18 ( struct V_10 * V_11 )
{
struct V_23 * V_3 = V_11 -> V_13 -> V_3 ;
if ( V_3 -> V_27 . V_28 & V_29 )
return F_19 ( & V_3 -> V_27 ) ;
F_20 ( L_14 ) ;
return 0 ;
}
static void F_21 ( struct V_10 * V_11 )
{
struct V_23 * V_3 = V_11 -> V_13 -> V_3 ;
switch ( V_3 -> V_27 . V_28 & V_30 ) {
case V_31 :
case V_32 :
F_20 ( L_15 ) ;
break;
case V_33 :
F_14 ( L_16 ) ;
V_3 -> V_27 . V_34 . V_35 = 0x1c000000 ;
V_3 -> V_27 . V_34 . V_36 = 0x02000000 ;
if ( ( F_4 ( V_3 -> V_27 . V_13 , V_37 ) &
V_38 ) == 0 )
V_3 -> V_27 . V_34 . V_39 = 1 ;
else
V_3 -> V_27 . V_34 . V_39 = 2 ;
break;
default:
F_20 ( L_17 ) ;
}
}
void F_22 ( struct V_10 * V_11 )
{
struct V_23 * V_3 ;
struct V_1 * V_13 ;
V_3 = V_11 -> V_13 -> V_3 ;
F_14 ( L_18 ) ;
if ( ! V_11 -> V_40 )
V_11 -> V_41 = 1 ;
F_13 (core, &bus->cores, list) {
int V_42 ;
if ( V_13 -> V_21 )
continue;
V_42 = F_9 ( V_13 ) ;
if ( V_42 > 4 )
V_13 -> V_21 = 0 ;
else
V_13 -> V_21 = V_42 + 2 ;
if ( V_13 -> V_21 > 5 )
continue;
switch ( V_13 -> V_5 . V_5 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_9 :
if ( V_11 -> V_41 <= 4 )
F_11 ( V_13 ,
V_11 -> V_41 ++ ) ;
break;
}
}
F_14 ( L_19 ) ;
F_17 ( V_3 ) ;
if ( V_11 -> V_40 )
return;
F_23 ( & V_3 -> V_27 ) ;
F_21 ( V_11 ) ;
V_11 -> V_40 = true ;
}
