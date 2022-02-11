static inline T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_5 )
{
F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static inline T_1 F_5 ( struct V_6 * V_4 )
{
T_1 V_7 = F_2 ( V_4 , V_8 ) ;
if ( V_7 )
return F_2 ( V_4 , V_8 ) & V_9 ;
else
return 0x3f ;
}
static struct V_6 * F_6 ( struct V_6 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
struct V_6 * V_4 ;
V_4 = & ( V_13 -> V_16 [ V_14 ] ) ;
if ( F_5 ( V_4 ) == V_11 )
return V_4 ;
}
return NULL ;
}
unsigned int F_7 ( struct V_6 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_6 * V_17 = V_13 -> V_18 . V_4 ;
T_1 V_11 ;
T_1 V_19 ;
T_1 V_20 ;
unsigned int V_21 ;
V_11 = F_5 ( V_4 ) ;
if ( V_11 == 0x3f )
return 6 ;
V_19 = F_2 ( V_13 -> V_18 . V_4 , V_22 ) ;
for ( V_21 = 1 ; V_21 <= 4 ; V_21 ++ ) {
V_20 = ( ( V_19 & V_23 [ V_21 ] ) >> V_24 [ V_21 ] ) ;
if ( V_20 == V_11 )
break;
}
if ( V_21 == 5 ) {
if ( ( 1 << V_11 ) & F_2 ( V_17 , V_25 ) )
V_21 = 0 ;
}
return V_21 ;
}
static void F_8 ( struct V_12 * V_13 , unsigned int V_21 )
{
struct V_6 * V_4 = V_13 -> V_18 . V_4 ;
if ( V_21 == 0 ) {
F_4 ( V_4 , V_25 , 0 ) ;
} else {
F_4 ( V_4 , V_22 ,
F_2 ( V_4 , V_22 ) |
V_23 [ V_21 ] ) ;
}
}
static void F_9 ( struct V_6 * V_4 , unsigned int V_21 )
{
unsigned int V_26 = F_7 ( V_4 ) ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_6 * V_17 = V_13 -> V_18 . V_4 ;
T_1 V_11 = F_5 ( V_4 ) ;
F_10 ( V_26 == 6 ) ;
V_4 -> V_21 = V_21 + 2 ;
if ( V_26 == 0 )
F_4 ( V_17 , V_25 , ( ~ ( 1 << V_11 ) & F_2 ( V_17 , V_25 ) ) ) ;
else if ( V_26 != 5 )
F_8 ( V_13 , V_26 ) ;
if ( V_21 == 0 ) {
F_4 ( V_17 , V_25 , ( ( 1 << V_11 ) | F_2 ( V_17 , V_25 ) ) ) ;
} else {
T_1 V_19 = F_2 ( V_17 , V_22 ) ;
if ( ( V_19 & V_23 [ V_21 ] ) != V_23 [ V_21 ] ) {
T_1 V_27 = ( V_19 & V_23 [ V_21 ] ) >> V_24 [ V_21 ] ;
struct V_6 * V_28 = F_6 ( V_4 , V_27 ) ;
if ( V_28 )
F_9 ( V_28 , 0 ) ;
}
V_11 <<= V_24 [ V_21 ] ;
V_11 |= ( V_19 & ~ V_23 [ V_21 ] ) ;
F_4 ( V_17 , V_22 , V_11 ) ;
}
F_11 (KERN_INFO PFX
L_1 ,
dev->id.coreid, oldirq+2 , irq+2 ) ;
}
static void F_12 ( struct V_6 * V_4 , unsigned int V_21 )
{
int V_14 ;
static const char * V_29 [] = { L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 } ;
F_11 (KERN_INFO PFX
L_9 , dev->id.coreid) ;
for ( V_14 = 0 ; V_14 <= 6 ; V_14 ++ ) {
F_11 ( L_10 , V_29 [ V_14 ] , V_14 == V_21 ? L_11 : L_12 ) ;
}
F_11 ( L_13 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
struct V_6 * V_4 ;
V_4 = & ( V_13 -> V_16 [ V_14 ] ) ;
F_12 ( V_4 , F_7 ( V_4 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
if ( V_13 -> V_30 . V_4 )
V_2 -> V_31 = F_15 ( & V_13 -> V_30 , V_2 -> V_32 ) ;
else if ( V_13 -> V_33 . V_4 )
V_2 -> V_31 = F_16 ( & V_13 -> V_33 , V_2 -> V_32 ) ;
else
V_2 -> V_31 = 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
if ( ! V_13 -> V_33 . V_4 ) {
V_2 -> V_34 = 2 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_38 ;
return;
}
switch ( V_13 -> V_33 . V_39 & V_40 ) {
case V_41 :
case V_42 :
F_18 ( L_14 ) ;
break;
case V_43 :
F_19 ( L_15 ) ;
V_2 -> V_35 = V_44 ;
V_2 -> V_37 = V_45 ;
if ( ( F_2 ( V_13 -> V_33 . V_4 , V_46 )
& V_47 ) == 0 )
V_2 -> V_34 = 1 ;
else
V_2 -> V_34 = 2 ;
break;
}
}
T_1 F_20 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
T_1 V_48 , V_49 , V_50 , V_51 = 0 ;
if ( V_13 -> V_33 . V_39 & V_52 )
return F_21 ( & V_13 -> V_33 ) ;
if ( V_13 -> V_30 . V_4 ) {
F_22 ( & V_13 -> V_30 , & V_48 , & V_49 , & V_50 ) ;
} else if ( V_13 -> V_33 . V_4 ) {
F_23 ( & V_13 -> V_33 , & V_48 , & V_49 , & V_50 ) ;
} else
return 0 ;
if ( ( V_48 == V_53 ) || ( V_13 -> V_54 == 0x5365 ) ) {
V_51 = 200000000 ;
} else {
V_51 = F_24 ( V_48 , V_49 , V_50 ) ;
}
if ( V_48 == V_55 ) {
V_51 *= 2 ;
}
return V_51 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_6 * V_4 ;
unsigned long V_56 , V_57 ;
unsigned int V_21 , V_14 ;
if ( ! V_2 -> V_4 )
return;
F_11 (KERN_INFO PFX L_16 ) ;
V_13 = V_2 -> V_4 -> V_13 ;
V_56 = F_26 ( V_13 ) ;
if ( ! V_56 )
V_56 = 100000000 ;
V_57 = 1000000000 / V_56 ;
if ( V_13 -> V_30 . V_4 )
F_27 ( & V_13 -> V_30 , V_57 ) ;
else if ( V_13 -> V_33 . V_4 )
F_28 ( & V_13 -> V_33 , V_57 ) ;
for ( V_21 = 2 , V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
int V_58 ;
V_4 = & ( V_13 -> V_16 [ V_14 ] ) ;
V_58 = F_7 ( V_4 ) ;
if ( V_58 > 4 )
V_4 -> V_21 = 0 ;
else
V_4 -> V_21 = V_58 + 2 ;
if ( V_4 -> V_21 > 5 )
continue;
switch ( V_4 -> V_59 . V_60 ) {
case V_61 :
if ( ( V_13 -> V_54 == 0x4710 ) && ( V_21 <= 4 ) ) {
F_9 ( V_4 , V_21 ++ ) ;
}
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
if ( V_21 <= 4 ) {
F_9 ( V_4 , V_21 ++ ) ;
break;
}
case V_67 :
F_9 ( V_4 , 0 ) ;
break;
}
}
F_11 (KERN_INFO PFX L_17 ) ;
F_13 ( V_13 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
}
