static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_5 -> V_6 != V_7 ) {
switch ( V_3 ) {
case 32000 :
F_4 ( V_2 , 0x108 , 0x1006040f ) ;
F_4 ( V_2 , 0x110 , 0x01bb39ee ) ;
F_5 ( V_2 , 0x127 , 0x50 ) ;
if ( F_6 ( V_5 ) )
break;
F_4 ( V_2 , 0x900 , 0x0801f77f ) ;
F_4 ( V_2 , 0x904 , 0x0801f77f ) ;
F_4 ( V_2 , 0x90c , 0x0801f77f ) ;
break;
case 44100 :
F_4 ( V_2 , 0x108 , 0x1009040f ) ;
F_4 ( V_2 , 0x110 , 0x00ec6bd6 ) ;
F_5 ( V_2 , 0x127 , 0x50 ) ;
if ( F_6 ( V_5 ) )
break;
F_4 ( V_2 , 0x900 , 0x08016d59 ) ;
F_4 ( V_2 , 0x904 , 0x08016d59 ) ;
F_4 ( V_2 , 0x90c , 0x08016d59 ) ;
break;
case 48000 :
F_4 ( V_2 , 0x108 , 0x100a040f ) ;
F_4 ( V_2 , 0x110 , 0x0098d6e5 ) ;
F_5 ( V_2 , 0x127 , 0x50 ) ;
if ( F_6 ( V_5 ) )
break;
F_4 ( V_2 , 0x900 , 0x08014faa ) ;
F_4 ( V_2 , 0x904 , 0x08014faa ) ;
F_4 ( V_2 , 0x90c , 0x08014faa ) ;
break;
}
} else {
switch ( V_3 ) {
case 32000 :
F_4 ( V_2 , 0x108 , 0x1e08040f ) ;
F_4 ( V_2 , 0x110 , 0x012a0869 ) ;
F_5 ( V_2 , 0x127 , 0x54 ) ;
if ( F_6 ( V_5 ) )
break;
F_4 ( V_2 , 0x8f8 , 0x08010000 ) ;
F_4 ( V_2 , 0x900 , 0x08020000 ) ;
F_4 ( V_2 , 0x904 , 0x08020000 ) ;
F_4 ( V_2 , 0x90c , 0x08020000 ) ;
break;
case 44100 :
F_4 ( V_2 , 0x108 , 0x1809040f ) ;
F_4 ( V_2 , 0x110 , 0x00ec6bd6 ) ;
F_5 ( V_2 , 0x127 , 0x50 ) ;
if ( F_6 ( V_5 ) )
break;
F_4 ( V_2 , 0x8f8 , 0x080160cd ) ;
F_4 ( V_2 , 0x900 , 0x08017385 ) ;
F_4 ( V_2 , 0x904 , 0x08017385 ) ;
F_4 ( V_2 , 0x90c , 0x08017385 ) ;
break;
case 48000 :
F_4 ( V_2 , 0x108 , 0x180a040f ) ;
F_4 ( V_2 , 0x110 , 0x0098d6e5 ) ;
F_5 ( V_2 , 0x127 , 0x50 ) ;
if ( F_6 ( V_5 ) )
break;
F_4 ( V_2 , 0x8f8 , 0x08018000 ) ;
F_4 ( V_2 , 0x900 , 0x08015555 ) ;
F_4 ( V_2 , 0x904 , 0x08015555 ) ;
F_4 ( V_2 , 0x90c , 0x08015555 ) ;
break;
}
}
V_5 -> V_8 = V_3 ;
return 0 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_1 ( V_2 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_5 -> V_6 != V_7 ) {
switch ( V_3 ) {
case 32000 :
case 44100 :
case 48000 :
break;
}
} else {
switch ( V_3 ) {
case 32000 :
case 44100 :
break;
case 48000 :
F_4 ( V_2 , 0x8f8 , 0x0801867c ) ;
F_4 ( V_2 , 0x900 , 0x08014faa ) ;
F_4 ( V_2 , 0x904 , 0x08014faa ) ;
F_4 ( V_2 , 0x90c , 0x08014faa ) ;
break;
}
}
V_5 -> V_8 = V_3 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_5 -> V_6 != V_7 ) {
switch ( V_3 ) {
case 32000 :
F_4 ( V_2 , 0x900 , 0x0801f77f ) ;
F_4 ( V_2 , 0x904 , 0x0801f77f ) ;
F_4 ( V_2 , 0x90c , 0x0801f77f ) ;
break;
case 44100 :
F_4 ( V_2 , 0x900 , 0x08016d59 ) ;
F_4 ( V_2 , 0x904 , 0x08016d59 ) ;
F_4 ( V_2 , 0x90c , 0x08016d59 ) ;
break;
case 48000 :
F_4 ( V_2 , 0x900 , 0x08014faa ) ;
F_4 ( V_2 , 0x904 , 0x08014faa ) ;
F_4 ( V_2 , 0x90c , 0x08014faa ) ;
break;
}
} else {
switch ( V_3 ) {
case 32000 :
F_4 ( V_2 , 0x8f8 , 0x08010000 ) ;
F_4 ( V_2 , 0x900 , 0x08020000 ) ;
F_4 ( V_2 , 0x904 , 0x08020000 ) ;
F_4 ( V_2 , 0x90c , 0x08020000 ) ;
break;
case 44100 :
F_4 ( V_2 , 0x8f8 , 0x080160cd ) ;
F_4 ( V_2 , 0x900 , 0x08017385 ) ;
F_4 ( V_2 , 0x904 , 0x08017385 ) ;
F_4 ( V_2 , 0x90c , 0x08017385 ) ;
break;
case 48000 :
F_4 ( V_2 , 0x8f8 , 0x0801867c ) ;
F_4 ( V_2 , 0x900 , 0x08014faa ) ;
F_4 ( V_2 , 0x904 , 0x08014faa ) ;
F_4 ( V_2 , 0x90c , 0x08014faa ) ;
break;
}
}
V_5 -> V_8 = V_3 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 != 32000 && V_3 != 44100 && V_3 != 48000 )
return - V_9 ;
if ( F_11 ( V_5 ) )
return F_9 ( V_2 , V_3 ) ;
if ( F_12 ( V_5 ) )
return F_8 ( V_2 , V_3 ) ;
if ( F_6 ( V_5 ) )
return F_7 ( V_2 , V_3 ) ;
return F_1 ( V_2 , V_3 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ) ;
if ( ! F_6 ( V_5 ) ) {
F_14 ( V_2 , 0x810 , ~ 0x1 , 0x01 ) ;
F_14 ( V_2 , 0x803 , ~ 0x10 , 0 ) ;
F_5 ( V_2 , 0x8d3 , 0x1f ) ;
if ( V_5 -> V_6 == V_7 ) {
F_4 ( V_2 , 0x8d0 , 0x01011012 ) ;
} else {
F_4 ( V_2 , 0x8d0 , 0x1f063870 ) ;
}
}
F_10 ( V_2 , V_5 -> V_8 ) ;
if ( ! F_6 ( V_5 ) ) {
if ( V_5 -> V_6 != V_7 ) {
F_14 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
}
F_14 ( V_2 , 0x810 , ~ 0x1 , 0x00 ) ;
if ( F_12 ( V_5 ) || F_11 ( V_5 ) )
F_14 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , int V_10 )
{
int V_11 ;
V_11 = V_10 >> 9 ;
if ( V_11 <= 23 ) {
V_11 = 0 ;
} else {
V_11 -= 23 ;
}
F_5 ( V_2 , 0x8d4 , 228 - ( V_11 * 2 ) ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_12 )
{
int V_13 = V_12 >> 8 ;
if ( V_13 > 0x80 ) {
F_14 ( V_2 , 0x8d5 , 0x7f , 0x80 ) ;
F_14 ( V_2 , 0x8d5 , ~ 0x7f , V_13 & 0x7f ) ;
} else {
F_14 ( V_2 , 0x8d5 , 0x7f , 0x00 ) ;
F_14 ( V_2 , 0x8d5 , ~ 0x7f , 0x80 - V_13 ) ;
}
}
int F_17 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_1 * V_2 = F_18 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_15 ) ;
int V_16 ;
if ( ! F_6 ( V_5 ) )
F_14 ( V_2 , 0x810 , ~ 0x1 , 1 ) ;
if ( V_5 -> V_6 != V_7 ) {
F_14 ( V_2 , 0x803 , ~ 0x10 , 0 ) ;
F_5 ( V_2 , 0x8d3 , 0x1f ) ;
}
V_16 = F_10 ( V_2 , V_3 ) ;
if ( V_5 -> V_6 != V_7 )
F_14 ( V_2 , 0x803 , ~ 0x10 , 0x10 ) ;
if ( ! F_6 ( V_5 ) )
F_14 ( V_2 , 0x810 , ~ 0x1 , 0 ) ;
return V_16 ;
}
static int F_19 ( struct V_17 * V_18 )
{
struct V_14 * V_15 = F_20 ( V_18 ) ;
struct V_4 * V_5 = F_2 ( V_15 ) ;
struct V_1 * V_2 = F_18 ( V_15 ) ;
switch ( V_18 -> V_19 ) {
case V_20 :
if ( V_5 -> V_21 -> V_22 )
F_15 ( V_2 , 0 ) ;
else
F_15 ( V_2 , V_5 -> V_10 -> V_22 ) ;
break;
case V_23 :
F_14 ( V_2 , 0x8d9 , ~ 0x3f ,
48 - ( V_18 -> V_22 * 48 / 0xffff ) ) ;
break;
case V_24 :
F_14 ( V_2 , 0x8db , ~ 0x3f ,
48 - ( V_18 -> V_22 * 48 / 0xffff ) ) ;
break;
case V_25 :
F_16 ( V_2 , V_18 -> V_22 ) ;
break;
default:
return - V_9 ;
}
return 0 ;
}
