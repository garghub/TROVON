static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , 0x130 , V_3 ) ;
F_3 ( V_2 , 0x130 ) ;
return F_3 ( V_2 , 0x134 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_4 )
{
const T_3 V_5 = 0x128 ;
const T_3 V_6 = 0x12C ;
T_1 V_7 ;
int V_8 ;
V_7 = ( 1 << 30 ) ;
V_7 |= ( 1 << 28 ) ;
V_7 |= ( 1 << 17 ) ;
V_7 |= ( 0x1F << 18 ) ;
V_7 |= ( V_4 << 4 ) ;
F_2 ( V_2 , V_6 , V_7 ) ;
F_5 ( 10 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_7 = F_3 ( V_2 , V_5 ) ;
if ( V_7 & 0x100 )
break;
F_6 ( 1 ) ;
}
}
static T_3 F_7 ( struct V_1 * V_2 , T_2 V_9 , T_2 V_3 )
{
const T_3 V_5 = 0x128 ;
const T_3 V_6 = 0x12C ;
int V_10 = 10 ;
T_3 V_11 = 0 ;
T_1 V_7 ;
int V_8 ;
V_7 = 0x80 ;
V_7 |= 0x2 ;
F_2 ( V_2 , V_5 , V_7 ) ;
if ( V_2 -> V_12 -> V_13 . V_14 >= 10 ) {
V_10 = 200 ;
F_4 ( V_2 , V_9 ) ;
}
V_7 = ( 1 << 30 ) ;
V_7 |= ( 1 << 29 ) ;
V_7 |= ( 1 << 17 ) ;
if ( V_2 -> V_12 -> V_13 . V_14 < 10 )
V_7 |= ( T_1 ) V_9 << 22 ;
V_7 |= ( T_1 ) V_3 << 18 ;
F_2 ( V_2 , V_6 , V_7 ) ;
F_5 ( 10 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_7 = F_3 ( V_2 , V_5 ) ;
if ( V_7 & 0x100 ) {
F_5 ( 10 ) ;
V_11 = F_3 ( V_2 , V_6 ) ;
break;
}
F_6 ( 1 ) ;
}
F_2 ( V_2 , V_5 , 0 ) ;
return V_11 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_9 ,
T_2 V_3 , T_3 V_15 )
{
const T_3 V_5 = 0x128 ;
const T_3 V_6 = 0x12C ;
int V_10 = 10 ;
T_1 V_7 ;
int V_8 ;
V_7 = 0x80 ;
V_7 |= 0x2 ;
F_2 ( V_2 , V_5 , V_7 ) ;
if ( V_2 -> V_12 -> V_13 . V_14 >= 10 ) {
V_10 = 200 ;
F_4 ( V_2 , V_9 ) ;
}
V_7 = ( 1 << 30 ) ;
V_7 |= ( 1 << 28 ) ;
V_7 |= ( 1 << 17 ) ;
if ( V_2 -> V_12 -> V_13 . V_14 < 10 )
V_7 |= ( T_1 ) V_9 << 22 ;
V_7 |= ( T_1 ) V_3 << 18 ;
V_7 |= V_15 ;
F_2 ( V_2 , V_6 , V_7 ) ;
F_5 ( 10 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_7 = F_3 ( V_2 , V_5 ) ;
if ( V_7 & 0x100 )
break;
F_6 ( 1 ) ;
}
F_2 ( V_2 , V_5 , 0 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 , 0x204 ) & 0x10 ) ? 0xC0 : 0x80 ;
}
static void F_10 ( struct V_1 * V_2 )
{
const T_2 V_16 = 0x1D ;
const T_2 V_17 = 0x1F ;
T_3 V_18 ;
F_8 ( V_2 , V_17 , 1 ,
F_9 ( V_2 ) ) ;
V_18 = F_7 ( V_2 , V_16 , 1 ) ;
if ( V_18 & 0x4000 )
F_8 ( V_2 , V_16 , 1 , V_18 & ~ 0x4000 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
