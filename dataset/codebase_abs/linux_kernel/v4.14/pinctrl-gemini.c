static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
return F_3 ( V_6 ) ;
if ( V_4 -> V_7 )
return F_3 ( V_8 ) ;
return 0 ;
}
static const char * F_4 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
return V_6 [ V_9 ] . V_10 ;
if ( V_4 -> V_7 )
return V_8 [ V_9 ] . V_10 ;
return NULL ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_9 ,
const unsigned int * * V_11 ,
unsigned int * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_13 &&
V_4 -> V_5 &&
! strcmp ( V_6 [ V_9 ] . V_10 , L_1 ) ) {
* V_11 = V_14 ;
* V_12 = F_3 ( V_14 ) ;
return 0 ;
}
if ( V_4 -> V_13 &&
V_4 -> V_7 &&
! strcmp ( V_8 [ V_9 ] . V_10 , L_1 ) ) {
* V_11 = V_15 ;
* V_12 = F_3 ( V_15 ) ;
return 0 ;
}
if ( V_4 -> V_5 ) {
* V_11 = V_6 [ V_9 ] . V_11 ;
* V_12 = V_6 [ V_9 ] . V_12 ;
}
if ( V_4 -> V_7 ) {
* V_11 = V_8 [ V_9 ] . V_11 ;
* V_12 = V_8 [ V_9 ] . V_12 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_16 * V_17 ,
unsigned int V_18 )
{
F_7 ( V_17 , L_2 V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * * V_23 ,
unsigned int * V_24 ,
unsigned int * V_25 )
{
int V_26 ;
const char * V_27 = NULL ;
const char * V_28 ;
struct V_29 * V_30 ;
V_26 = F_9 ( V_21 , L_3 , & V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_10 ( V_21 , L_4 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_11 ( V_2 , V_23 , V_24 ,
V_25 , V_26 ) ;
if ( V_26 < 0 )
return V_26 ;
F_12 (np, L_4 , prop, group) {
V_26 = F_13 ( V_2 , V_23 , V_24 ,
V_25 , V_28 , V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
F_14 ( L_5 ,
V_27 , V_28 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_31 ,
struct V_22 * * V_23 ,
unsigned int * V_25 )
{
unsigned int V_24 = 0 ;
struct V_20 * V_21 ;
int V_26 ;
* V_23 = NULL ;
* V_25 = 0 ;
F_16 (np_config, np) {
V_26 = F_8 ( V_2 , V_21 , V_23 ,
& V_24 , V_25 ) ;
if ( V_26 < 0 ) {
F_17 ( V_2 , * V_23 , * V_25 ) ;
return V_26 ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_9 ,
unsigned int V_28 )
{
struct V_3 * V_4 ;
const struct V_32 * V_33 ;
const struct V_34 * V_35 ;
T_1 V_36 , V_37 , V_38 ;
unsigned long V_39 ;
int V_40 ;
V_4 = F_2 ( V_2 ) ;
V_33 = & V_41 [ V_9 ] ;
if ( V_4 -> V_5 )
V_35 = & V_6 [ V_28 ] ;
else if ( V_4 -> V_7 )
V_35 = & V_8 [ V_28 ] ;
else {
F_19 ( V_4 -> V_42 , L_6 ) ;
return - V_43 ;
}
F_20 ( V_4 -> V_42 ,
L_7 ,
V_33 -> V_10 , V_35 -> V_10 ) ;
F_21 ( V_4 -> V_23 , V_44 , & V_36 ) ;
F_22 ( V_4 -> V_23 , V_44 , V_35 -> V_45 ,
V_35 -> V_46 ) ;
F_21 ( V_4 -> V_23 , V_44 , & V_37 ) ;
V_36 &= V_47 ;
V_37 &= V_47 ;
V_38 = V_36 &= ~ V_35 -> V_45 ;
V_38 |= V_35 -> V_46 ;
V_38 &= V_47 ;
V_39 = V_35 -> V_45 ;
F_23 (i, &tmp, PADS_MAXBIT) {
bool V_48 = ! ( V_40 > 3 ) ;
if ( V_37 & F_24 ( V_40 ) ) {
F_19 ( V_4 -> V_42 ,
L_8
L_9 ,
V_49 [ V_40 ] ,
V_48 ? L_10 : L_11 ) ;
F_19 ( V_4 -> V_42 ,
L_12 ,
V_36 , V_37 , V_38 ) ;
} else {
F_20 ( V_4 -> V_42 ,
L_13 ,
V_49 [ V_40 ] ,
V_48 ? L_10 : L_11 ) ;
}
}
V_39 = V_35 -> V_46 ;
F_23 (i, &tmp, PADS_MAXBIT) {
bool V_48 = ( V_40 > 3 ) ;
if ( ! ( V_37 & F_24 ( V_40 ) ) ) {
F_19 ( V_4 -> V_42 ,
L_8
L_9 ,
V_49 [ V_40 ] ,
V_48 ? L_10 : L_11 ) ;
F_19 ( V_4 -> V_42 ,
L_12 ,
V_36 , V_37 , V_38 ) ;
} else {
F_20 ( V_4 -> V_42 ,
L_13 ,
V_49 [ V_40 ] ,
V_48 ? L_10 : L_11 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_3 ( V_41 ) ;
}
static const char * F_26 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
return V_41 [ V_9 ] . V_10 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int V_9 ,
const char * const * * V_50 ,
unsigned int * const V_51 )
{
* V_50 = V_41 [ V_9 ] . V_50 ;
* V_51 = V_41 [ V_9 ] . V_51 ;
return 0 ;
}
static int F_28 ( struct V_52 * V_53 )
{
struct V_3 * V_4 ;
struct V_54 * V_23 ;
struct V_55 * V_42 = & V_53 -> V_42 ;
struct V_55 * V_56 ;
unsigned long V_39 ;
T_1 V_57 ;
int V_26 ;
int V_40 ;
V_4 = F_29 ( & V_53 -> V_42 , sizeof( * V_4 ) , V_58 ) ;
if ( ! V_4 )
return - V_59 ;
V_4 -> V_42 = & V_53 -> V_42 ;
V_56 = V_42 -> V_56 ;
if ( ! V_56 ) {
F_19 ( V_42 , L_14 ) ;
return - V_43 ;
}
V_23 = F_30 ( V_56 -> V_60 ) ;
if ( F_31 ( V_23 ) ) {
F_19 ( V_42 , L_15 ) ;
return F_32 ( V_23 ) ;
}
V_4 -> V_23 = V_23 ;
V_26 = F_21 ( V_23 , V_61 , & V_57 ) ;
if ( V_26 ) {
F_19 ( V_42 , L_16 ) ;
return V_26 ;
}
V_57 >>= 8 ;
V_57 &= 0xffff ;
if ( V_57 == 0x3512 ) {
V_4 -> V_5 = true ;
V_62 . V_11 = V_63 ;
V_62 . V_64 = F_3 ( V_63 ) ;
F_20 ( V_42 , L_17 ) ;
} else if ( V_57 == 0x3516 ) {
V_4 -> V_7 = true ;
V_62 . V_11 = V_65 ;
V_62 . V_64 = F_3 ( V_65 ) ;
F_20 ( V_42 , L_18 ) ;
} else {
F_19 ( V_42 , L_19 , V_57 ) ;
return - V_43 ;
}
V_26 = F_21 ( V_23 , V_44 , & V_57 ) ;
F_20 ( V_42 , L_20 , V_57 ) ;
V_57 &= V_47 ;
V_57 ^= 0x0f ;
V_39 = V_57 ;
F_23 (i, &tmp, PADS_MAXBIT) {
F_20 ( V_42 , L_21 , V_49 [ V_40 ] ,
( V_57 & F_24 ( V_40 ) ) ? L_10 : L_11 ) ;
}
F_21 ( V_23 , V_66 , & V_57 ) ;
V_4 -> V_13 = ! ! ( V_57 & V_67 ) ;
F_20 ( V_42 , L_22 , V_4 -> V_13 ? L_23 : L_24 ) ;
V_4 -> V_68 = F_33 ( V_42 , & V_62 , V_4 ) ;
if ( F_31 ( V_4 -> V_68 ) ) {
F_19 ( V_42 , L_25 ) ;
return F_32 ( V_4 -> V_68 ) ;
}
F_20 ( V_42 , L_26 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_69 ) ;
}
