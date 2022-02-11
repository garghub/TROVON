static unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_5 ;
switch ( V_3 & 0x0c ) {
case V_6 :
V_5 = V_2 -> V_7 -> V_8 . V_9 . V_10 ? V_11 : 0 ;
break;
case V_12 :
V_5 = V_2 -> V_7 -> V_8 . V_9 . V_13 + V_14 ;
V_5 = ( V_5 >> 5 ) - 1 ;
V_5 |= ( F_2 ( & V_2 -> V_7 -> V_15 ) - 1 ) << 5 ;
break;
case V_16 :
V_5 = ( V_17 << 24 ) | ( V_18 << 0 ) ;
break;
default:
return 0 ;
}
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
struct V_20 * V_21 = & V_2 -> V_7 -> V_8 . V_9 ;
bool V_22 = V_21 -> V_10 ;
switch ( V_3 & 0x0c ) {
case V_6 :
V_21 -> V_10 = V_19 & V_11 ;
if ( ! V_22 && V_21 -> V_10 )
F_4 ( V_2 -> V_7 ) ;
break;
case V_12 :
case V_16 :
return;
}
}
static void F_5 ( struct V_1 * V_23 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
int V_24 = F_2 ( & V_23 -> V_7 -> V_15 ) ;
int V_25 = V_19 & 0xf ;
int V_26 = ( V_19 >> 16 ) & 0xff ;
int V_27 = ( V_19 >> 24 ) & 0x03 ;
int V_28 ;
struct V_1 * V_2 ;
switch ( V_27 ) {
case 0x0 :
break;
case 0x1 :
V_26 = ( 1U << V_24 ) - 1 ;
V_26 &= ~ ( 1U << V_23 -> V_29 ) ;
break;
case 0x2 :
V_26 = ( 1U << V_23 -> V_29 ) ;
break;
case 0x3 :
return;
}
F_6 (c, vcpu, source_vcpu->kvm) {
struct V_30 * V_31 ;
if ( ! ( V_26 & ( 1U << V_28 ) ) )
continue;
V_31 = F_7 ( V_23 -> V_7 , V_2 , V_25 ) ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_33 = true ;
V_31 -> V_34 |= 1U << V_23 -> V_29 ;
F_9 ( V_23 -> V_7 , V_31 ) ;
}
}
static unsigned long F_10 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_25 = F_11 ( V_3 , 8 ) ;
int V_35 ;
T_3 V_19 = 0 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
V_19 |= ( T_3 ) V_31 -> V_26 << ( V_35 * 8 ) ;
}
return V_19 ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = F_11 ( V_3 , 8 ) ;
int V_35 ;
if ( V_25 < V_14 )
return;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , NULL , V_25 + V_35 ) ;
int V_36 ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_26 = ( V_19 >> ( V_35 * 8 ) ) & 0xff ;
V_36 = V_31 -> V_26 ? F_13 ( V_31 -> V_26 ) : 0 ;
V_31 -> V_37 = F_14 ( V_2 -> V_7 , V_36 ) ;
F_15 ( & V_31 -> V_32 ) ;
}
}
static unsigned long F_16 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
T_3 V_19 = 0 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
V_19 |= ( T_3 ) V_31 -> V_34 << ( V_35 * 8 ) ;
}
return V_19 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_34 &= ~ ( ( V_19 >> ( V_35 * 8 ) ) & 0xff ) ;
if ( ! V_31 -> V_34 )
V_31 -> V_33 = false ;
F_15 ( & V_31 -> V_32 ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_34 |= ( V_19 >> ( V_35 * 8 ) ) & 0xff ;
if ( V_31 -> V_34 ) {
V_31 -> V_33 = true ;
F_9 ( V_2 -> V_7 , V_31 ) ;
} else {
F_15 ( & V_31 -> V_32 ) ;
}
}
}
static void F_19 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
if ( V_40 . type == V_41 )
F_20 ( V_2 , V_39 ) ;
else
F_21 ( V_2 , V_39 ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
if ( V_40 . type == V_41 )
F_23 ( V_2 , V_39 ) ;
else
F_24 ( V_2 , V_39 ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
struct V_38 V_39 ;
T_2 V_19 ;
F_22 ( V_2 , & V_39 ) ;
switch ( V_3 & 0xff ) {
case V_42 :
V_19 = V_39 . V_43 ;
break;
case V_44 :
V_19 = V_39 . V_45 ;
break;
case V_46 :
V_19 = V_39 . V_47 ;
break;
case V_48 :
V_19 = V_39 . V_49 ;
break;
case V_50 :
V_19 = ( ( V_17 << 20 ) |
( V_51 << 16 ) |
V_18 ) ;
break;
default:
return 0 ;
}
return V_19 ;
}
static void F_26 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
struct V_38 V_39 ;
F_22 ( V_2 , & V_39 ) ;
switch ( V_3 & 0xff ) {
case V_42 :
V_39 . V_43 = V_19 ;
break;
case V_44 :
V_39 . V_45 = V_19 ;
break;
case V_46 :
V_39 . V_47 = V_19 ;
break;
case V_48 :
V_39 . V_49 = V_19 ;
break;
}
F_19 ( V_2 , & V_39 ) ;
}
unsigned int F_27 ( struct V_52 * V_53 )
{
V_53 -> V_54 = V_55 ;
V_53 -> V_56 = F_28 ( V_55 ) ;
F_29 ( & V_53 -> V_53 , & V_57 ) ;
return V_58 ;
}
int F_30 ( struct V_59 * V_53 , struct V_60 * V_61 )
{
int V_62 = V_53 -> V_7 -> V_8 . V_9 . V_13 + V_14 ;
const struct V_63 * V_54 ;
T_1 V_3 ;
int V_56 , V_35 , V_4 ;
V_3 = V_61 -> V_61 & V_64 ;
switch ( V_61 -> V_65 ) {
case V_66 :
V_54 = V_55 ;
V_56 = F_28 ( V_55 ) ;
break;
case V_67 :
V_54 = V_68 ;
V_56 = F_28 ( V_68 ) ;
break;
default:
return - V_69 ;
}
if ( V_3 & 3 )
return - V_69 ;
for ( V_35 = 0 ; V_35 < V_56 ; V_35 ++ ) {
if ( V_54 [ V_35 ] . V_70 )
V_4 = ( V_54 [ V_35 ] . V_70 * V_62 ) / 8 ;
else
V_4 = V_54 [ V_35 ] . V_4 ;
if ( V_54 [ V_35 ] . V_71 <= V_3 &&
V_54 [ V_35 ] . V_71 + V_4 > V_3 )
return 0 ;
}
return - V_69 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_52 * V_53 ,
bool V_72 , int V_73 , T_2 * V_19 )
{
unsigned int V_4 = 4 ;
T_4 V_74 [ 4 ] ;
int V_75 ;
if ( V_72 ) {
F_32 ( V_74 , V_4 , * V_19 ) ;
V_75 = V_57 . V_76 ( V_2 , & V_53 -> V_53 , V_73 , V_4 , V_74 ) ;
} else {
V_75 = V_57 . V_77 ( V_2 , & V_53 -> V_53 , V_73 , V_4 , V_74 ) ;
if ( ! V_75 )
* V_19 = F_33 ( V_74 , V_4 ) ;
}
return V_75 ;
}
int F_34 ( struct V_1 * V_2 , bool V_72 ,
int V_73 , T_2 * V_19 )
{
struct V_52 V_53 = {
. V_54 = V_68 ,
. V_56 = F_28 ( V_68 ) ,
} ;
return F_31 ( V_2 , & V_53 , V_72 , V_73 , V_19 ) ;
}
int F_35 ( struct V_1 * V_2 , bool V_72 ,
int V_73 , T_2 * V_19 )
{
struct V_52 V_53 = {
. V_54 = V_55 ,
. V_56 = F_28 ( V_55 ) ,
} ;
return F_31 ( V_2 , & V_53 , V_72 , V_73 , V_19 ) ;
}
