static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == 1 )
F_4 ( V_2 ) ;
}
static bool F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned int V_7 = F_7 ( V_6 ) ;
switch ( V_7 ) {
case V_8 :
return ! V_2 -> V_9 ;
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
case V_22 :
return true ;
}
return false ;
}
static bool F_8 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned int V_7 = F_7 ( V_6 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_24 . V_25 ; V_23 ++ ) {
unsigned int * V_26 = F_9 ( & V_2 -> V_24 , V_23 ) ;
if ( V_7 == * V_26 )
return true ;
}
if ( V_2 -> V_27 )
return true ;
switch ( V_7 & 0xf00 ) {
case V_28 :
case V_29 :
return true ;
case V_8 :
return V_2 -> V_9 ;
case 0xf00 :
break;
default:
return false ;
}
switch ( V_7 ) {
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
case V_44 :
return true ;
}
return false ;
}
static bool F_10 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned int V_7 = F_7 ( V_6 ) ;
if ( V_2 -> V_27 )
return true ;
switch ( V_7 ) {
case V_45 :
case V_46 :
case V_47 :
return true ;
case V_48 :
case V_49 :
case V_50 :
return true ;
}
return F_8 ( V_5 , V_6 ) ;
}
static bool F_11 ( unsigned int V_6 )
{
if ( ( ( V_6 >> 8 ) & 0x700 ) != V_51 )
return false ;
return ( V_6 & ( V_52 | V_53 ) ) ==
( V_52 | V_53 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int * V_54 )
{
unsigned int V_55 , V_56 ;
int V_57 ;
V_6 &= ~ ( V_52 | V_53 ) ;
V_57 = F_13 ( V_2 , V_6 | V_58 , 0 , & V_55 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_13 ( V_2 , V_6 | V_59 , 0 , & V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
* V_54 = V_55 | ( V_56 << 8 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_54 )
{
int V_57 ;
unsigned int V_7 , V_55 , V_56 ;
V_7 = V_51 << 8 ;
if ( V_6 & V_60 )
V_7 |= V_61 ;
else
V_7 |= V_62 | ( ( V_6 & 0xf ) << 8 ) ;
V_6 = ( V_6 & ~ 0xfffff ) | V_7 ;
V_55 = V_54 & 0xff ;
V_56 = ( V_54 >> 8 ) & 0xff ;
if ( V_55 == V_56 ) {
V_6 |= V_52 | V_53 ;
return F_13 ( V_2 , V_6 | V_55 , 0 , NULL ) ;
}
V_57 = F_13 ( V_2 , V_6 | V_52 | V_55 , 0 , NULL ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_13 ( V_2 , V_6 | V_53 | V_56 , 0 , NULL ) ;
if ( V_57 < 0 )
return V_57 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int * V_54 )
{
unsigned int V_7 ;
int V_57 ;
if ( ! V_2 -> V_9 )
return - V_63 ;
V_7 = ( V_6 & ~ 0xfff00 ) | ( V_64 << 8 ) ;
V_57 = F_13 ( V_2 , V_7 , 0 , NULL ) ;
if ( V_57 < 0 )
return V_57 ;
V_7 = ( V_6 & ~ 0xfffff ) | ( V_10 << 8 ) ;
return F_13 ( V_2 , V_7 , 0 , V_54 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_54 )
{
unsigned int V_7 ;
int V_57 ;
if ( ! V_2 -> V_9 )
return - V_63 ;
V_7 = ( V_6 & ~ 0xfff00 ) | ( V_64 << 8 ) ;
V_57 = F_13 ( V_2 , V_7 , 0 , NULL ) ;
if ( V_57 < 0 )
return V_57 ;
V_7 = ( V_6 & ~ 0xfffff ) | ( V_10 << 8 ) |
( V_54 & 0xffff ) ;
return F_13 ( V_2 , V_7 , 0 , NULL ) ;
}
static int F_17 ( void * V_65 , unsigned int V_6 , unsigned int * V_54 )
{
struct V_1 * V_2 = V_65 ;
int V_7 = F_7 ( V_6 ) ;
int V_57 ;
int V_66 = 0 ;
if ( V_7 != V_12 ) {
V_66 = F_1 ( V_2 ) ;
if ( V_66 < 0 )
return - V_67 ;
}
V_6 |= ( V_2 -> V_68 << 28 ) ;
if ( F_11 ( V_6 ) ) {
V_57 = F_12 ( V_2 , V_6 , V_54 ) ;
goto V_69;
}
if ( V_7 == V_8 ) {
V_57 = F_15 ( V_2 , V_6 , V_54 ) ;
goto V_69;
}
if ( ( V_7 & 0x700 ) == V_51 )
V_6 &= ~ V_70 ;
V_57 = F_13 ( V_2 , V_6 , 0 , V_54 ) ;
if ( V_57 < 0 )
goto V_69;
if ( V_7 == V_12 ) {
if ( * V_54 & V_71 )
* V_54 = - 1 ;
else
* V_54 = ( * V_54 >> 4 ) & 0x0f ;
}
V_69:
F_3 ( V_2 , V_66 ) ;
return V_57 ;
}
static int F_18 ( void * V_65 , unsigned int V_6 , unsigned int V_54 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_7 ;
int V_23 , V_72 , V_57 ;
int V_66 = 0 ;
if ( V_2 -> V_27 )
return 0 ;
V_6 &= ~ 0x00080000U ;
V_6 |= ( V_2 -> V_68 << 28 ) ;
V_7 = F_7 ( V_6 ) ;
if ( V_7 != V_73 ) {
V_66 = F_1 ( V_2 ) ;
if ( V_66 < 0 )
return V_2 -> V_74 ? 0 : - V_67 ;
}
if ( F_11 ( V_6 ) ) {
V_57 = F_14 ( V_2 , V_6 , V_54 ) ;
goto V_69;
}
if ( V_7 == V_75 ) {
V_57 = F_16 ( V_2 , V_6 , V_54 ) ;
goto V_69;
}
switch ( V_7 & 0xf00 ) {
case V_51 :
if ( ( V_6 & V_70 ) && ( V_54 & V_76 ) )
V_54 = 0 ;
V_7 = V_51 ;
if ( V_6 & V_58 )
V_7 |= V_52 >> 8 ;
else
V_7 |= V_53 >> 8 ;
if ( V_6 & V_60 ) {
V_7 |= V_61 >> 8 ;
} else {
V_7 |= V_62 >> 8 ;
V_7 |= V_6 & 0xf ;
}
break;
}
switch ( V_7 ) {
case V_77 :
V_72 = 2 ;
break;
case V_78 :
V_72 = 4 ;
break;
default:
V_72 = 1 ;
break;
}
for ( V_23 = 0 ; V_23 < V_72 ; V_23 ++ ) {
V_6 &= ~ 0xfffff ;
V_6 |= ( V_7 + V_23 ) << 8 | ( ( V_54 >> ( 8 * V_23 ) ) & 0xff ) ;
V_57 = F_13 ( V_2 , V_6 , 0 , NULL ) ;
if ( V_57 < 0 )
goto V_69;
}
V_69:
F_3 ( V_2 , V_66 ) ;
return V_57 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_79 * V_79 ;
V_79 = F_20 ( & V_2 -> V_5 , NULL , V_2 , & V_80 ) ;
if ( F_21 ( V_79 ) )
return F_22 ( V_79 ) ;
V_2 -> V_79 = V_79 ;
F_23 ( & V_2 -> V_24 , sizeof( unsigned int ) , 8 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 ) {
F_25 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
F_26 ( & V_2 -> V_24 ) ;
}
}
int F_27 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
unsigned int * V_81 = F_28 ( & V_2 -> V_24 ) ;
if ( ! V_81 )
return - V_82 ;
* V_81 = V_7 | 0x800 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_54 )
{
if ( ! V_2 -> V_79 )
return F_18 ( V_2 , V_6 , V_54 ) ;
else
return F_30 ( V_2 -> V_79 , V_6 , V_54 ) ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_54 )
{
int V_57 ;
V_57 = F_29 ( V_2 , V_6 , V_54 ) ;
if ( V_57 == - V_67 ) {
V_57 = F_32 ( V_2 ) ;
if ( ! V_57 )
V_57 = F_29 ( V_2 , V_6 , V_54 ) ;
F_4 ( V_2 ) ;
}
return V_57 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int * V_54 , bool V_83 )
{
if ( V_83 || ! V_2 -> V_79 )
return F_17 ( V_2 , V_6 , V_54 ) ;
else
return F_34 ( V_2 -> V_79 , V_6 , V_54 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int * V_54 ,
bool V_83 )
{
int V_57 ;
V_57 = F_33 ( V_2 , V_6 , V_54 , V_83 ) ;
if ( V_57 == - V_67 ) {
V_57 = F_32 ( V_2 ) ;
if ( ! V_57 )
V_57 = F_33 ( V_2 , V_6 , V_54 , V_83 ) ;
F_4 ( V_2 ) ;
}
return V_57 ;
}
int F_36 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int * V_54 )
{
return F_35 ( V_2 , V_6 , V_54 , false ) ;
}
int F_37 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int * V_54 )
{
return F_35 ( V_2 , V_6 , V_54 , true ) ;
}
int F_38 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_84 , unsigned int V_54 )
{
unsigned int V_85 ;
int V_57 ;
V_54 &= V_84 ;
V_57 = F_36 ( V_2 , V_6 , & V_85 ) ;
if ( V_57 < 0 )
return V_57 ;
V_54 |= V_85 & ~ V_84 ;
if ( V_54 == V_85 )
return 0 ;
V_57 = F_31 ( V_2 , V_6 , V_54 ) ;
if ( V_57 < 0 )
return V_57 ;
return 1 ;
}
