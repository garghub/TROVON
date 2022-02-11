static void F_1 ( struct V_1 * V_2 , int V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_6 ( V_2 , V_3 ) ;
F_2 ( V_7 ) ;
V_5 -> V_8 ( V_2 , 1 ) ;
F_2 ( V_7 ) ;
V_5 -> V_8 ( V_2 , 0 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_7 ) ;
V_5 -> V_8 ( V_2 , 1 ) ;
F_2 ( V_9 ) ;
V_5 -> V_8 ( V_2 , 0 ) ;
return V_5 -> V_10 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , int V_11 )
{
int V_12 ;
for ( V_12 = V_11 - 1 ; V_12 >= 0 ; V_12 -- )
F_1 ( V_2 , ( V_3 >> V_12 ) & 1 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_11 )
{
int V_12 ;
T_1 V_13 = 0 ;
for ( V_12 = V_11 - 1 ; V_12 >= 0 ; V_12 -- ) {
V_13 <<= 1 ;
V_13 |= F_3 ( V_2 ) ;
}
return V_13 ;
}
static void F_6 ( struct V_1 * V_2 , int V_14 , T_2 V_15 , T_2 V_16 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
int V_12 ;
V_5 -> V_17 ( V_2 , 1 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ )
F_1 ( V_2 , 1 ) ;
F_1 ( V_2 , 0 ) ;
if ( V_14 & V_18 )
F_1 ( V_2 , 0 ) ;
else
F_1 ( V_2 , 1 ) ;
F_1 ( V_2 , ( V_14 >> 1 ) & 1 ) ;
F_1 ( V_2 , ( V_14 >> 0 ) & 1 ) ;
F_4 ( V_2 , V_15 , 5 ) ;
F_4 ( V_2 , V_16 , 5 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_15 , T_3 V_19 )
{
unsigned int V_20 = ( V_19 >> 16 ) & 0x1F ;
unsigned int V_16 = V_19 & 0xFFFF ;
F_6 ( V_2 , V_21 , V_15 , V_20 ) ;
F_1 ( V_2 , 1 ) ;
F_1 ( V_2 , 0 ) ;
F_4 ( V_2 , V_16 , 16 ) ;
V_2 -> V_5 -> V_17 ( V_2 , 0 ) ;
F_3 ( V_2 ) ;
return V_20 ;
}
static int F_8 ( struct V_22 * V_23 , int V_15 , int V_16 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_13 , V_12 ;
if ( V_16 & V_25 ) {
V_16 = F_7 ( V_2 , V_15 , V_16 ) ;
F_6 ( V_2 , V_26 , V_15 , V_16 ) ;
} else
F_6 ( V_2 , V_27 , V_15 , V_16 ) ;
V_2 -> V_5 -> V_17 ( V_2 , 0 ) ;
if ( F_3 ( V_2 ) != 0 &&
! ( V_23 -> V_28 & ( 1 << V_15 ) ) ) {
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ )
F_3 ( V_2 ) ;
return 0xffff ;
}
V_13 = F_5 ( V_2 , 16 ) ;
F_3 ( V_2 ) ;
return V_13 ;
}
static int F_9 ( struct V_22 * V_23 , int V_15 , int V_16 , T_1 V_3 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
if ( V_16 & V_25 ) {
V_16 = F_7 ( V_2 , V_15 , V_16 ) ;
F_6 ( V_2 , V_29 , V_15 , V_16 ) ;
} else
F_6 ( V_2 , V_30 , V_15 , V_16 ) ;
F_1 ( V_2 , 1 ) ;
F_1 ( V_2 , 0 ) ;
F_4 ( V_2 , V_3 , 16 ) ;
V_2 -> V_5 -> V_17 ( V_2 , 0 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
if ( V_2 -> V_31 )
V_2 -> V_31 ( V_23 ) ;
return 0 ;
}
struct V_22 * F_11 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_12 () ;
if ( ! V_23 )
return NULL ;
F_13 ( V_2 -> V_5 -> V_32 ) ;
V_23 -> V_33 = F_8 ;
V_23 -> V_34 = F_9 ;
V_23 -> V_31 = F_10 ;
V_23 -> V_24 = V_2 ;
return V_23 ;
}
void F_14 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_15 ( V_2 -> V_5 -> V_32 ) ;
F_16 ( V_23 ) ;
}
