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
F_10 ( V_23 -> V_7 , V_31 ) ;
}
}
static unsigned long F_11 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_25 = F_12 ( V_3 , 8 ) ;
int V_35 ;
T_3 V_19 = 0 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
V_19 |= ( T_3 ) V_31 -> V_26 << ( V_35 * 8 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
return V_19 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = F_12 ( V_3 , 8 ) ;
T_4 V_36 = F_14 ( F_2 ( & V_2 -> V_7 -> V_15 ) - 1 , 0 ) ;
int V_35 ;
if ( V_25 < V_14 )
return;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , NULL , V_25 + V_35 ) ;
int V_37 ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_26 = ( V_19 >> ( V_35 * 8 ) ) & V_36 ;
V_37 = V_31 -> V_26 ? F_15 ( V_31 -> V_26 ) : 0 ;
V_31 -> V_38 = F_16 ( V_2 -> V_7 , V_37 ) ;
F_17 ( & V_31 -> V_32 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
}
static unsigned long F_18 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
T_3 V_19 = 0 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
V_19 |= ( T_3 ) V_31 -> V_34 << ( V_35 * 8 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
return V_19 ;
}
static void F_19 ( struct V_1 * V_2 ,
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
F_17 ( & V_31 -> V_32 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
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
F_17 ( & V_31 -> V_32 ) ;
}
F_10 ( V_2 -> V_7 , V_31 ) ;
}
}
static unsigned long F_21 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
struct V_39 V_40 ;
T_2 V_19 ;
F_22 ( V_2 , & V_40 ) ;
switch ( V_3 & 0xff ) {
case V_41 :
V_19 = V_40 . V_42 ;
break;
case V_43 :
V_19 = ( V_40 . V_44 & V_45 ) >>
V_46 ;
break;
case V_47 :
V_19 = V_40 . V_48 ;
break;
case V_49 :
V_19 = V_40 . V_50 ;
break;
case V_51 :
V_19 = ( ( V_17 << 20 ) |
( V_52 << 16 ) |
V_18 ) ;
break;
default:
return 0 ;
}
return V_19 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
struct V_39 V_40 ;
F_22 ( V_2 , & V_40 ) ;
switch ( V_3 & 0xff ) {
case V_41 :
V_40 . V_42 = V_19 ;
break;
case V_43 :
V_40 . V_44 = ( V_19 << V_46 ) &
V_45 ;
break;
case V_47 :
V_40 . V_48 = V_19 ;
break;
case V_49 :
V_40 . V_50 = V_19 ;
break;
}
F_24 ( V_2 , & V_40 ) ;
}
unsigned int F_25 ( struct V_53 * V_54 )
{
V_54 -> V_55 = V_56 ;
V_54 -> V_57 = F_26 ( V_56 ) ;
F_27 ( & V_54 -> V_54 , & V_58 ) ;
return V_59 ;
}
int F_28 ( struct V_60 * V_54 , struct V_61 * V_62 )
{
const struct V_63 * V_64 ;
struct V_53 V_65 ;
struct V_66 V_67 ;
struct V_1 * V_2 ;
T_1 V_3 ;
int V_68 ;
V_68 = F_29 ( V_54 , V_62 , & V_67 ) ;
if ( V_68 )
return V_68 ;
V_2 = V_67 . V_2 ;
V_3 = V_67 . V_3 ;
switch ( V_62 -> V_69 ) {
case V_70 :
V_65 . V_55 = V_56 ;
V_65 . V_57 = F_26 ( V_56 ) ;
V_65 . V_71 = 0 ;
break;
case V_72 :
V_65 . V_55 = V_73 ;
V_65 . V_57 = F_26 ( V_73 ) ;
V_65 . V_71 = 0 ;
break;
default:
return - V_74 ;
}
if ( V_3 & 3 )
return - V_74 ;
V_64 = F_30 ( V_2 , & V_65 , V_3 , sizeof( T_2 ) ) ;
if ( ! V_64 )
return - V_74 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , bool V_75 ,
int V_76 , T_2 * V_19 )
{
struct V_53 V_54 = {
. V_55 = V_73 ,
. V_57 = F_26 ( V_73 ) ,
. V_77 = V_78 ,
} ;
return F_32 ( V_2 , & V_54 , V_75 , V_76 , V_19 ) ;
}
int F_33 ( struct V_1 * V_2 , bool V_75 ,
int V_76 , T_2 * V_19 )
{
struct V_53 V_54 = {
. V_55 = V_56 ,
. V_57 = F_26 ( V_56 ) ,
. V_77 = V_79 ,
} ;
return F_32 ( V_2 , & V_54 , V_75 , V_76 , V_19 ) ;
}
