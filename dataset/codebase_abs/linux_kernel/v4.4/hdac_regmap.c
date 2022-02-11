static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 = F_3 ( V_3 ) ;
switch ( V_6 ) {
case V_7 :
return ! V_5 -> V_8 ;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return true ;
}
return false ;
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 = F_3 ( V_3 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_5 -> V_23 . V_24 ; V_22 ++ ) {
unsigned int * V_25 = F_5 ( & V_5 -> V_23 , V_22 ) ;
if ( V_6 == * V_25 )
return true ;
}
if ( V_5 -> V_26 )
return true ;
switch ( V_6 & 0xf00 ) {
case V_27 :
case V_28 :
return true ;
case V_7 :
return V_5 -> V_8 ;
case 0xf00 :
break;
default:
return false ;
}
switch ( V_6 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
return true ;
}
return false ;
}
static bool F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 = F_3 ( V_3 ) ;
if ( V_5 -> V_26 )
return true ;
switch ( V_6 ) {
case V_44 :
case V_45 :
case V_46 :
return true ;
case V_47 :
case V_48 :
case V_49 :
return true ;
}
return F_4 ( V_2 , V_3 ) ;
}
static bool F_7 ( unsigned int V_3 )
{
if ( ( ( V_3 >> 8 ) & 0x700 ) != V_50 )
return false ;
return ( V_3 & ( V_51 | V_52 ) ) ==
( V_51 | V_52 ) ;
}
static int F_8 ( struct V_4 * V_5 ,
unsigned int V_3 , unsigned int * V_53 )
{
unsigned int V_54 , V_55 ;
int V_56 ;
V_3 &= ~ ( V_51 | V_52 ) ;
V_56 = F_9 ( V_5 , V_3 | V_57 , 0 , & V_54 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_9 ( V_5 , V_3 | V_58 , 0 , & V_55 ) ;
if ( V_56 < 0 )
return V_56 ;
* V_53 = V_54 | ( V_55 << 8 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 ,
unsigned int V_3 , unsigned int V_53 )
{
int V_56 ;
unsigned int V_6 , V_54 , V_55 ;
V_6 = V_50 << 8 ;
if ( V_3 & V_59 )
V_6 |= V_60 ;
else
V_6 |= V_61 | ( ( V_3 & 0xf ) << 8 ) ;
V_3 = ( V_3 & ~ 0xfffff ) | V_6 ;
V_54 = V_53 & 0xff ;
V_55 = ( V_53 >> 8 ) & 0xff ;
if ( V_54 == V_55 ) {
V_3 |= V_51 | V_52 ;
return F_9 ( V_5 , V_3 | V_54 , 0 , NULL ) ;
}
V_56 = F_9 ( V_5 , V_3 | V_51 | V_54 , 0 , NULL ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_9 ( V_5 , V_3 | V_52 | V_55 , 0 , NULL ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int * V_53 )
{
unsigned int V_6 ;
int V_56 ;
if ( ! V_5 -> V_8 )
return - V_62 ;
V_6 = ( V_3 & ~ 0xfff00 ) | ( V_63 << 8 ) ;
V_56 = F_9 ( V_5 , V_6 , 0 , NULL ) ;
if ( V_56 < 0 )
return V_56 ;
V_6 = ( V_3 & ~ 0xfffff ) | ( V_9 << 8 ) ;
return F_9 ( V_5 , V_6 , 0 , V_53 ) ;
}
static int F_12 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int V_53 )
{
unsigned int V_6 ;
int V_56 ;
if ( ! V_5 -> V_8 )
return - V_62 ;
V_6 = ( V_3 & ~ 0xfff00 ) | ( V_63 << 8 ) ;
V_56 = F_9 ( V_5 , V_6 , 0 , NULL ) ;
if ( V_56 < 0 )
return V_56 ;
V_6 = ( V_3 & ~ 0xfffff ) | ( V_9 << 8 ) |
( V_53 & 0xffff ) ;
return F_9 ( V_5 , V_6 , 0 , NULL ) ;
}
static int F_13 ( void * V_64 , unsigned int V_3 , unsigned int * V_53 )
{
struct V_4 * V_5 = V_64 ;
int V_6 = F_3 ( V_3 ) ;
int V_56 ;
if ( ! F_14 ( V_5 ) && V_6 != V_11 )
return - V_65 ;
V_3 |= ( V_5 -> V_66 << 28 ) ;
if ( F_7 ( V_3 ) )
return F_8 ( V_5 , V_3 , V_53 ) ;
if ( V_6 == V_7 )
return F_11 ( V_5 , V_3 , V_53 ) ;
if ( ( V_6 & 0x700 ) == V_50 )
V_3 &= ~ V_67 ;
V_56 = F_9 ( V_5 , V_3 , 0 , V_53 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_6 == V_11 ) {
if ( * V_53 & V_68 )
* V_53 = - 1 ;
else
* V_53 = ( * V_53 >> 4 ) & 0x0f ;
}
return 0 ;
}
static int F_15 ( void * V_64 , unsigned int V_3 , unsigned int V_53 )
{
struct V_4 * V_5 = V_64 ;
unsigned int V_6 ;
int V_22 , V_69 , V_56 ;
if ( V_5 -> V_26 )
return 0 ;
V_3 &= ~ 0x00080000U ;
V_3 |= ( V_5 -> V_66 << 28 ) ;
V_6 = F_3 ( V_3 ) ;
if ( ! F_14 ( V_5 ) && V_6 != V_70 )
return V_5 -> V_71 ? 0 : - V_65 ;
if ( F_7 ( V_3 ) )
return F_10 ( V_5 , V_3 , V_53 ) ;
if ( V_6 == V_72 )
return F_12 ( V_5 , V_3 , V_53 ) ;
switch ( V_6 & 0xf00 ) {
case V_50 :
if ( ( V_3 & V_67 ) && ( V_53 & V_73 ) )
V_53 = 0 ;
V_6 = V_50 ;
if ( V_3 & V_57 )
V_6 |= V_51 >> 8 ;
else
V_6 |= V_52 >> 8 ;
if ( V_3 & V_59 ) {
V_6 |= V_60 >> 8 ;
} else {
V_6 |= V_61 >> 8 ;
V_6 |= V_3 & 0xf ;
}
break;
}
switch ( V_6 ) {
case V_74 :
V_69 = 2 ;
break;
case V_75 :
V_69 = 4 ;
break;
default:
V_69 = 1 ;
break;
}
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ ) {
V_3 &= ~ 0xfffff ;
V_3 |= ( V_6 + V_22 ) << 8 | ( ( V_53 >> ( 8 * V_22 ) ) & 0xff ) ;
V_56 = F_9 ( V_5 , V_3 , 0 , NULL ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
int F_16 ( struct V_4 * V_5 )
{
struct V_76 * V_76 ;
V_76 = F_17 ( & V_5 -> V_2 , NULL , V_5 , & V_77 ) ;
if ( F_18 ( V_76 ) )
return F_19 ( V_76 ) ;
V_5 -> V_76 = V_76 ;
F_20 ( & V_5 -> V_23 , sizeof( unsigned int ) , 8 ) ;
return 0 ;
}
void F_21 ( struct V_4 * V_5 )
{
if ( V_5 -> V_76 ) {
F_22 ( V_5 -> V_76 ) ;
V_5 -> V_76 = NULL ;
F_23 ( & V_5 -> V_23 ) ;
}
}
int F_24 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
unsigned int * V_78 = F_25 ( & V_5 -> V_23 ) ;
if ( ! V_78 )
return - V_79 ;
* V_78 = V_6 | 0x800 ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int V_53 )
{
if ( ! V_5 -> V_76 )
return F_15 ( V_5 , V_3 , V_53 ) ;
else
return F_27 ( V_5 -> V_76 , V_3 , V_53 ) ;
}
int F_28 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int V_53 )
{
int V_56 ;
V_56 = F_26 ( V_5 , V_3 , V_53 ) ;
if ( V_56 == - V_65 ) {
V_56 = F_29 ( V_5 ) ;
if ( ! V_56 )
V_56 = F_26 ( V_5 , V_3 , V_53 ) ;
F_30 ( V_5 ) ;
}
return V_56 ;
}
static int F_31 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int * V_53 )
{
if ( ! V_5 -> V_76 )
return F_13 ( V_5 , V_3 , V_53 ) ;
else
return F_32 ( V_5 -> V_76 , V_3 , V_53 ) ;
}
int F_33 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int * V_53 )
{
int V_56 ;
V_56 = F_31 ( V_5 , V_3 , V_53 ) ;
if ( V_56 == - V_65 ) {
V_56 = F_29 ( V_5 ) ;
if ( ! V_56 )
V_56 = F_31 ( V_5 , V_3 , V_53 ) ;
F_30 ( V_5 ) ;
}
return V_56 ;
}
int F_34 ( struct V_4 * V_5 , unsigned int V_3 ,
unsigned int V_80 , unsigned int V_53 )
{
unsigned int V_81 ;
int V_56 ;
V_53 &= V_80 ;
V_56 = F_33 ( V_5 , V_3 , & V_81 ) ;
if ( V_56 < 0 )
return V_56 ;
V_53 |= V_81 & ~ V_80 ;
if ( V_53 == V_81 )
return 0 ;
V_56 = F_28 ( V_5 , V_3 , V_53 ) ;
if ( V_56 < 0 )
return V_56 ;
return 1 ;
}
