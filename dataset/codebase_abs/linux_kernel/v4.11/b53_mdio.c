static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 V_5 )
{
int V_6 ;
T_2 V_7 ;
int V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_2 -> V_12 != V_3 ) {
V_7 = ( V_3 << 8 ) | V_13 ;
V_8 = F_2 ( V_10 , V_14 ,
V_15 , V_7 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_12 = V_3 ;
}
V_7 = ( V_4 << 8 ) | V_5 ;
V_8 = F_2 ( V_10 , V_14 , V_16 , V_7 ) ;
if ( V_8 )
return V_8 ;
for ( V_6 = 0 ; V_6 < 5 ; ++ V_6 ) {
V_7 = F_3 ( V_10 , V_14 ,
V_16 ) ;
if ( ! ( V_7 & ( V_17 | V_18 ) ) )
break;
F_4 ( 10 , 100 ) ;
}
if ( F_5 ( V_6 == 5 ) )
return - V_19 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_20 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
if ( V_8 )
return V_8 ;
* V_20 = F_3 ( V_10 , V_14 ,
V_21 ) & 0xff ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_2 * V_20 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
if ( V_8 )
return V_8 ;
* V_20 = F_3 ( V_10 , V_14 , V_21 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_3 * V_20 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
if ( V_8 )
return V_8 ;
* V_20 = F_3 ( V_10 , V_14 , V_21 ) ;
* V_20 |= F_3 ( V_10 , V_14 ,
V_22 ) << 16 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_4 * V_20 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_4 V_23 = 0 ;
int V_6 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
if ( V_8 )
return V_8 ;
for ( V_6 = 2 ; V_6 >= 0 ; V_6 -- ) {
V_23 <<= 16 ;
V_23 |= F_3 ( V_10 , V_14 ,
V_21 + V_6 ) ;
}
* V_20 = V_23 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_4 * V_20 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_4 V_23 = 0 ;
int V_6 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_3 , V_4 , V_18 ) ;
if ( V_8 )
return V_8 ;
for ( V_6 = 3 ; V_6 >= 0 ; V_6 -- ) {
V_23 <<= 16 ;
V_23 |= F_3 ( V_10 , V_14 ,
V_21 + V_6 ) ;
}
* V_20 = V_23 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_24 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_8 ;
V_8 = F_2 ( V_10 , V_14 ,
V_21 , V_24 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_3 , V_4 , V_17 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_24 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_8 ;
V_8 = F_2 ( V_10 , V_14 ,
V_21 , V_24 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_2 , V_3 , V_4 , V_17 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_3 V_24 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_6 ;
T_3 V_23 = V_24 ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
int V_8 = F_2 ( V_10 , V_14 ,
V_21 + V_6 ,
V_23 & 0xffff ) ;
if ( V_8 )
return V_8 ;
V_23 >>= 16 ;
}
return F_1 ( V_2 , V_3 , V_4 , V_17 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_4 V_24 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_6 ;
T_4 V_23 = V_24 ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
int V_8 = F_2 ( V_10 , V_14 ,
V_21 + V_6 ,
V_23 & 0xffff ) ;
if ( V_8 )
return V_8 ;
V_23 >>= 16 ;
}
return F_1 ( V_2 , V_3 , V_4 , V_17 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_4 V_24 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_6 ;
T_4 V_23 = V_24 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
int V_8 = F_2 ( V_10 , V_14 ,
V_21 + V_6 ,
V_23 & 0xffff ) ;
if ( V_8 )
return V_8 ;
V_23 >>= 16 ;
}
return F_1 ( V_2 , V_3 , V_4 , V_17 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_25 , int V_4 ,
T_2 * V_24 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_24 = F_3 ( V_10 , V_25 , V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_25 , int V_4 ,
T_2 V_24 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
return F_2 ( V_10 , V_25 , V_4 , V_24 ) ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
T_3 V_28 ;
int V_8 ;
if ( V_27 -> V_25 != V_14 && V_27 -> V_25 != 0 ) {
F_19 ( & V_27 -> V_2 , L_1 ,
V_27 -> V_25 ) ;
return - V_29 ;
}
V_28 = F_20 ( V_27 -> V_10 , 0 , 2 ) << 16 ;
V_28 |= F_20 ( V_27 -> V_10 , 0 , 3 ) ;
if ( ( V_28 & 0xfffffc00 ) != V_30 &&
( V_28 & 0xfffffc00 ) != V_31 &&
( V_28 & 0xfffffc00 ) != V_32 ) {
F_19 ( & V_27 -> V_2 , L_2 , V_28 ) ;
return - V_29 ;
}
if ( F_21 ( L_3 ) &&
strcmp ( V_27 -> V_10 -> V_33 , L_4 ) )
return - V_34 ;
V_2 = F_22 ( & V_27 -> V_2 , & V_35 , V_27 -> V_10 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_12 = 0xff ;
V_2 -> V_10 = V_27 -> V_10 ;
F_23 ( & V_27 -> V_2 , V_2 ) ;
V_8 = F_24 ( V_2 ) ;
if ( V_8 ) {
F_19 ( & V_27 -> V_2 , L_5 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
static void F_25 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_26 ( & V_27 -> V_2 ) ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_27 ( V_38 ) ;
}
