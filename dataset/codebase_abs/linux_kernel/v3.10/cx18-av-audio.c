static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_3 != 32000 && V_3 != 44100 && V_3 != 48000 )
return - V_7 ;
if ( V_5 -> V_8 > V_9 ) {
switch ( V_3 ) {
case 32000 :
F_2 ( V_2 , 0x108 , 0x200d040f ) ;
F_2 ( V_2 , 0x10c , 0x002be2fe ) ;
F_2 ( V_2 , 0x110 , 0x0176740c ) ;
F_2 ( V_2 , 0x900 , 0x0801f77f ) ;
F_2 ( V_2 , 0x904 , 0x0801f77f ) ;
F_2 ( V_2 , 0x90c , 0x0801f77f ) ;
F_3 ( V_2 , 0x127 , 0x60 ) ;
F_2 ( V_2 , 0x12c , 0x11202fff ) ;
F_2 ( V_2 , 0x128 , 0xa00d2ef8 ) ;
break;
case 44100 :
F_2 ( V_2 , 0x108 , 0x180e040f ) ;
F_2 ( V_2 , 0x10c , 0x002be2fe ) ;
F_2 ( V_2 , 0x110 , 0x0062a1f2 ) ;
F_2 ( V_2 , 0x900 , 0x08016d59 ) ;
F_2 ( V_2 , 0x904 , 0x08016d59 ) ;
F_2 ( V_2 , 0x90c , 0x08016d59 ) ;
F_3 ( V_2 , 0x127 , 0x58 ) ;
F_2 ( V_2 , 0x12c , 0x112092ff ) ;
F_2 ( V_2 , 0x128 , 0xa01d4bf8 ) ;
break;
case 48000 :
F_2 ( V_2 , 0x108 , 0x160e040f ) ;
F_2 ( V_2 , 0x10c , 0x002be2fe ) ;
F_2 ( V_2 , 0x110 , 0x005227ad ) ;
F_2 ( V_2 , 0x900 , 0x08014faa ) ;
F_2 ( V_2 , 0x904 , 0x08014faa ) ;
F_2 ( V_2 , 0x90c , 0x08014faa ) ;
F_3 ( V_2 , 0x127 , 0x56 ) ;
F_2 ( V_2 , 0x12c , 0x11205fff ) ;
F_2 ( V_2 , 0x128 , 0xa01193f8 ) ;
break;
}
} else {
switch ( V_3 ) {
case 32000 :
F_2 ( V_2 , 0x108 , 0x300d040f ) ;
F_2 ( V_2 , 0x10c , 0x002be2fe ) ;
F_2 ( V_2 , 0x110 , 0x0176740c ) ;
F_2 ( V_2 , 0x8f8 , 0x08010000 ) ;
F_2 ( V_2 , 0x900 , 0x08020000 ) ;
F_2 ( V_2 , 0x904 , 0x08020000 ) ;
F_2 ( V_2 , 0x90c , 0x08020000 ) ;
F_3 ( V_2 , 0x127 , 0x70 ) ;
F_2 ( V_2 , 0x12c , 0x11201fff ) ;
F_2 ( V_2 , 0x128 , 0xa00d2ef8 ) ;
break;
case 44100 :
F_2 ( V_2 , 0x108 , 0x240e040f ) ;
F_2 ( V_2 , 0x10c , 0x002be2fe ) ;
F_2 ( V_2 , 0x110 , 0x0062a1f2 ) ;
F_2 ( V_2 , 0x8f8 , 0x080160cd ) ;
F_2 ( V_2 , 0x900 , 0x08017385 ) ;
F_2 ( V_2 , 0x904 , 0x08017385 ) ;
F_2 ( V_2 , 0x90c , 0x08017385 ) ;
F_3 ( V_2 , 0x127 , 0x64 ) ;
F_2 ( V_2 , 0x12c , 0x112061ff ) ;
F_2 ( V_2 , 0x128 , 0xa01d4bf8 ) ;
break;
case 48000 :
F_2 ( V_2 , 0x108 , 0x200d040f ) ;
F_2 ( V_2 , 0x10c , 0x002be2fe ) ;
F_2 ( V_2 , 0x110 , 0x0176740c ) ;
F_2 ( V_2 , 0x8f8 , 0x08018000 ) ;
F_2 ( V_2 , 0x900 , 0x08015555 ) ;
F_2 ( V_2 , 0x904 , 0x08015555 ) ;
F_2 ( V_2 , 0x90c , 0x08015555 ) ;
F_3 ( V_2 , 0x127 , 0x60 ) ;
F_2 ( V_2 , 0x12c , 0x11203fff ) ;
F_2 ( V_2 , 0x128 , 0xa01193f8 ) ;
break;
}
}
V_5 -> V_10 = V_3 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
T_2 V_11 ;
V_11 = F_5 ( V_2 , 0x803 ) & ~ 0x10 ;
F_6 ( V_2 , 0x803 , V_11 , V_11 , 0x1f ) ;
V_11 = F_5 ( V_2 , 0x810 ) | 0x01 ;
F_6 ( V_2 , 0x810 , V_11 , V_11 , 0x0f ) ;
F_3 ( V_2 , 0x8d3 , 0x1f ) ;
if ( V_5 -> V_8 <= V_9 ) {
F_2 ( V_2 , 0x8d0 , 0x01011012 ) ;
} else {
F_2 ( V_2 , 0x8d0 , 0x1f063870 ) ;
}
F_1 ( V_2 , V_5 -> V_10 ) ;
V_11 = F_5 ( V_2 , 0x810 ) & ~ 0x01 ;
F_6 ( V_2 , 0x810 , V_11 , V_11 , 0x0f ) ;
if ( V_5 -> V_8 > V_9 ) {
V_11 = F_5 ( V_2 , 0x803 ) | 0x10 ;
F_6 ( V_2 , 0x803 , V_11 , V_11 , 0x1f ) ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_12 )
{
int V_13 = V_12 >> 9 ;
if ( V_13 <= 23 )
V_13 = 0 ;
else
V_13 -= 23 ;
F_3 ( V_2 , 0x8d4 , 228 - ( V_13 * 2 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_14 )
{
F_9 ( V_2 , 0x8d9 , ~ 0x3f , 48 - ( V_14 * 48 / 0xffff ) ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_15 )
{
F_9 ( V_2 , 0x8db , ~ 0x3f , 48 - ( V_15 * 48 / 0xffff ) ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_16 )
{
int V_17 = V_16 >> 8 ;
if ( V_17 > 0x80 ) {
F_9 ( V_2 , 0x8d5 , 0x7f , 0x80 ) ;
F_9 ( V_2 , 0x8d5 , ~ 0x7f , V_17 & 0x7f ) ;
} else {
F_9 ( V_2 , 0x8d5 , 0x7f , 0x00 ) ;
F_9 ( V_2 , 0x8d5 , ~ 0x7f , 0x80 - V_17 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_18 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
T_2 V_11 ;
if ( V_5 -> V_8 > V_9 ) {
V_11 = F_5 ( V_2 , 0x803 ) ;
if ( V_18 ) {
V_11 &= ~ 0x10 ;
F_6 ( V_2 , 0x803 , V_11 , V_11 , 0x1f ) ;
F_3 ( V_2 , 0x8d3 , 0x1f ) ;
} else {
V_11 |= 0x10 ;
F_6 ( V_2 , 0x803 , V_11 , V_11 , 0x1f ) ;
}
} else {
F_9 ( V_2 , 0x8d3 , ~ 0x2 , V_18 ? 0x02 : 0x00 ) ;
}
}
int F_13 ( struct V_19 * V_20 , T_1 V_3 )
{
struct V_1 * V_2 = F_14 ( V_20 ) ;
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_21 ;
T_2 V_11 ;
if ( V_5 -> V_8 > V_9 ) {
V_11 = F_5 ( V_2 , 0x803 ) & ~ 0x10 ;
F_6 ( V_2 , 0x803 , V_11 , V_11 , 0x1f ) ;
F_3 ( V_2 , 0x8d3 , 0x1f ) ;
}
V_11 = F_5 ( V_2 , 0x810 ) | 0x1 ;
F_6 ( V_2 , 0x810 , V_11 , V_11 , 0x0f ) ;
V_21 = F_1 ( V_2 , V_3 ) ;
V_11 = F_5 ( V_2 , 0x810 ) & ~ 0x1 ;
F_6 ( V_2 , 0x810 , V_11 , V_11 , 0x0f ) ;
if ( V_5 -> V_8 > V_9 ) {
V_11 = F_5 ( V_2 , 0x803 ) | 0x10 ;
F_6 ( V_2 , 0x803 , V_11 , V_11 , 0x1f ) ;
}
return V_21 ;
}
static int F_15 ( struct V_22 * V_23 )
{
struct V_19 * V_20 = F_16 ( V_23 ) ;
struct V_1 * V_2 = F_14 ( V_20 ) ;
switch ( V_23 -> V_24 ) {
case V_25 :
F_7 ( V_2 , V_23 -> V_26 ) ;
break;
case V_27 :
F_8 ( V_2 , V_23 -> V_26 ) ;
break;
case V_28 :
F_10 ( V_2 , V_23 -> V_26 ) ;
break;
case V_29 :
F_11 ( V_2 , V_23 -> V_26 ) ;
break;
case V_30 :
F_12 ( V_2 , V_23 -> V_26 ) ;
break;
default:
return - V_7 ;
}
return 0 ;
}
