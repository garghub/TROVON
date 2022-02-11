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
static void F_11 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_12 -> V_20 ;
T_3 V_21 ;
V_21 = ( V_20 -> V_22 . V_13 & 0xFF00 ) ;
if ( V_21 != 0x4700 &&
V_21 != 0x5300 )
return false ;
#ifdef F_13
if ( V_20 -> V_23 . V_24 & V_25 )
return false ;
#endif
#if 0
u32 tmp;
return !mips_busprobe32(tmp, (bus->mmio +
(pc->core->core_index * BCMA_CORE_SIZE)));
#endif
return true ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) ) {
#ifdef F_15
F_16 ( V_2 ) ;
#else
F_17 ( L_1 ) ;
#endif
} else {
F_11 ( V_2 ) ;
}
}
int F_18 ( struct V_1 * V_2 , struct V_26 * V_12 ,
bool V_27 )
{
struct V_28 * V_29 = V_2 -> V_12 -> V_20 -> V_30 ;
T_1 V_31 , V_18 ;
int V_32 ;
V_32 = F_19 ( V_29 , V_33 , & V_18 ) ;
if ( V_32 )
goto V_34;
V_31 = F_20 ( V_12 -> V_35 ) << 8 ;
if ( V_27 )
V_18 |= V_31 ;
else
V_18 &= ~ V_31 ;
V_32 = F_21 ( V_29 , V_33 , V_18 ) ;
V_34:
return V_32 ;
}
