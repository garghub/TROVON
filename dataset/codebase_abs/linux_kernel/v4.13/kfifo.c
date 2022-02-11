static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 + 1 ) - ( V_2 -> V_4 - V_2 -> V_5 ) ;
}
int F_2 ( struct V_1 * V_2 , unsigned int V_6 ,
T_1 V_7 , T_2 V_8 )
{
V_6 = F_3 ( V_6 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 = V_7 ;
if ( V_6 < 2 ) {
V_2 -> V_9 = NULL ;
V_2 -> V_3 = 0 ;
return - V_10 ;
}
V_2 -> V_9 = F_4 ( V_6 * V_7 , V_8 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_3 = 0 ;
return - V_11 ;
}
V_2 -> V_3 = V_6 - 1 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_9 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_9 = NULL ;
V_2 -> V_3 = 0 ;
}
int F_7 ( struct V_1 * V_2 , void * V_12 ,
unsigned int V_6 , T_1 V_7 )
{
V_6 /= V_7 ;
V_6 = F_3 ( V_6 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_12 ;
if ( V_6 < 2 ) {
V_2 -> V_3 = 0 ;
return - V_10 ;
}
V_2 -> V_3 = V_6 - 1 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , const void * V_13 ,
unsigned int V_14 , unsigned int V_15 )
{
unsigned int V_6 = V_2 -> V_3 + 1 ;
unsigned int V_7 = V_2 -> V_7 ;
unsigned int V_16 ;
V_15 &= V_2 -> V_3 ;
if ( V_7 != 1 ) {
V_15 *= V_7 ;
V_6 *= V_7 ;
V_14 *= V_7 ;
}
V_16 = F_9 ( V_14 , V_6 - V_15 ) ;
memcpy ( V_2 -> V_9 + V_15 , V_13 , V_16 ) ;
memcpy ( V_2 -> V_9 , V_13 + V_16 , V_14 - V_16 ) ;
F_10 () ;
}
unsigned int F_11 ( struct V_1 * V_2 ,
const void * V_17 , unsigned int V_14 )
{
unsigned int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_14 > V_16 )
V_14 = V_16 ;
F_8 ( V_2 , V_17 , V_14 , V_2 -> V_4 ) ;
V_2 -> V_4 += V_14 ;
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 , void * V_18 ,
unsigned int V_14 , unsigned int V_15 )
{
unsigned int V_6 = V_2 -> V_3 + 1 ;
unsigned int V_7 = V_2 -> V_7 ;
unsigned int V_16 ;
V_15 &= V_2 -> V_3 ;
if ( V_7 != 1 ) {
V_15 *= V_7 ;
V_6 *= V_7 ;
V_14 *= V_7 ;
}
V_16 = F_9 ( V_14 , V_6 - V_15 ) ;
memcpy ( V_18 , V_2 -> V_9 + V_15 , V_16 ) ;
memcpy ( V_18 + V_16 , V_2 -> V_9 , V_14 - V_16 ) ;
F_10 () ;
}
unsigned int F_13 ( struct V_1 * V_2 ,
void * V_17 , unsigned int V_14 )
{
unsigned int V_16 ;
V_16 = V_2 -> V_4 - V_2 -> V_5 ;
if ( V_14 > V_16 )
V_14 = V_16 ;
F_12 ( V_2 , V_17 , V_14 , V_2 -> V_5 ) ;
return V_14 ;
}
unsigned int F_14 ( struct V_1 * V_2 ,
void * V_17 , unsigned int V_14 )
{
V_14 = F_13 ( V_2 , V_17 , V_14 ) ;
V_2 -> V_5 += V_14 ;
return V_14 ;
}
static unsigned long F_15 ( struct V_1 * V_2 ,
const void T_3 * V_19 , unsigned int V_14 , unsigned int V_15 ,
unsigned int * V_20 )
{
unsigned int V_6 = V_2 -> V_3 + 1 ;
unsigned int V_7 = V_2 -> V_7 ;
unsigned int V_16 ;
unsigned long V_21 ;
V_15 &= V_2 -> V_3 ;
if ( V_7 != 1 ) {
V_15 *= V_7 ;
V_6 *= V_7 ;
V_14 *= V_7 ;
}
V_16 = F_9 ( V_14 , V_6 - V_15 ) ;
V_21 = F_16 ( V_2 -> V_9 + V_15 , V_19 , V_16 ) ;
if ( F_17 ( V_21 ) )
V_21 = F_18 ( V_21 + V_14 - V_16 , V_7 ) ;
else {
V_21 = F_16 ( V_2 -> V_9 , V_19 + V_16 , V_14 - V_16 ) ;
if ( F_17 ( V_21 ) )
V_21 = F_18 ( V_21 , V_7 ) ;
}
F_10 () ;
* V_20 = V_14 - V_21 * V_7 ;
return V_21 ;
}
int F_19 ( struct V_1 * V_2 , const void T_3 * V_19 ,
unsigned long V_14 , unsigned int * V_20 )
{
unsigned int V_16 ;
unsigned long V_21 ;
unsigned int V_7 = V_2 -> V_7 ;
int V_22 ;
if ( V_7 != 1 )
V_14 /= V_7 ;
V_16 = F_1 ( V_2 ) ;
if ( V_14 > V_16 )
V_14 = V_16 ;
V_21 = F_15 ( V_2 , V_19 , V_14 , V_2 -> V_4 , V_20 ) ;
if ( F_17 ( V_21 ) ) {
V_14 -= V_21 ;
V_22 = - V_23 ;
} else
V_22 = 0 ;
V_2 -> V_4 += V_14 ;
return V_22 ;
}
static unsigned long F_20 ( struct V_1 * V_2 , void T_3 * V_24 ,
unsigned int V_14 , unsigned int V_15 , unsigned int * V_20 )
{
unsigned int V_16 ;
unsigned long V_21 ;
unsigned int V_6 = V_2 -> V_3 + 1 ;
unsigned int V_7 = V_2 -> V_7 ;
V_15 &= V_2 -> V_3 ;
if ( V_7 != 1 ) {
V_15 *= V_7 ;
V_6 *= V_7 ;
V_14 *= V_7 ;
}
V_16 = F_9 ( V_14 , V_6 - V_15 ) ;
V_21 = F_21 ( V_24 , V_2 -> V_9 + V_15 , V_16 ) ;
if ( F_17 ( V_21 ) )
V_21 = F_18 ( V_21 + V_14 - V_16 , V_7 ) ;
else {
V_21 = F_21 ( V_24 + V_16 , V_2 -> V_9 , V_14 - V_16 ) ;
if ( F_17 ( V_21 ) )
V_21 = F_18 ( V_21 , V_7 ) ;
}
F_10 () ;
* V_20 = V_14 - V_21 * V_7 ;
return V_21 ;
}
int F_22 ( struct V_1 * V_2 , void T_3 * V_24 ,
unsigned long V_14 , unsigned int * V_20 )
{
unsigned int V_16 ;
unsigned long V_21 ;
unsigned int V_7 = V_2 -> V_7 ;
int V_22 ;
if ( V_7 != 1 )
V_14 /= V_7 ;
V_16 = V_2 -> V_4 - V_2 -> V_5 ;
if ( V_14 > V_16 )
V_14 = V_16 ;
V_21 = F_20 ( V_2 , V_24 , V_14 , V_2 -> V_5 , V_20 ) ;
if ( F_17 ( V_21 ) ) {
V_14 -= V_21 ;
V_22 = - V_23 ;
} else
V_22 = 0 ;
V_2 -> V_5 += V_14 ;
return V_22 ;
}
static int F_23 ( struct V_25 * V_26 , void * V_17 ,
int V_27 , unsigned int V_14 )
{
int V_28 ;
unsigned int V_16 ;
unsigned int V_15 ;
struct V_29 * V_29 ;
if ( ! V_27 )
return 0 ;
if ( ! V_14 )
return 0 ;
V_28 = 0 ;
V_29 = F_24 ( V_17 ) ;
V_15 = F_25 ( V_17 ) ;
V_16 = 0 ;
while ( V_14 >= V_16 + V_30 - V_15 ) {
struct V_29 * V_31 ;
V_16 += V_30 ;
V_17 += V_30 ;
V_31 = F_24 ( V_17 ) ;
if ( F_26 ( V_29 ) != F_26 ( V_31 ) - V_16 ) {
F_27 ( V_26 , V_29 , V_16 - V_15 , V_15 ) ;
V_26 = F_28 ( V_26 ) ;
if ( ++ V_28 == V_27 || V_26 == NULL )
return V_28 ;
V_29 = V_31 ;
V_14 -= V_16 - V_15 ;
V_16 = V_15 = 0 ;
}
}
F_27 ( V_26 , V_29 , V_14 , V_15 ) ;
return V_28 + 1 ;
}
static unsigned int F_29 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , unsigned int V_14 , unsigned int V_15 )
{
unsigned int V_6 = V_2 -> V_3 + 1 ;
unsigned int V_7 = V_2 -> V_7 ;
unsigned int V_16 ;
unsigned int V_28 ;
V_15 &= V_2 -> V_3 ;
if ( V_7 != 1 ) {
V_15 *= V_7 ;
V_6 *= V_7 ;
V_14 *= V_7 ;
}
V_16 = F_9 ( V_14 , V_6 - V_15 ) ;
V_28 = F_23 ( V_26 , V_2 -> V_9 + V_15 , V_27 , V_16 ) ;
V_28 += F_23 ( V_26 + V_28 , V_2 -> V_9 , V_27 - V_28 , V_14 - V_16 ) ;
return V_28 ;
}
unsigned int F_30 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_27 , unsigned int V_14 )
{
unsigned int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_14 > V_16 )
V_14 = V_16 ;
return F_29 ( V_2 , V_26 , V_27 , V_14 , V_2 -> V_4 ) ;
}
unsigned int F_31 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_27 , unsigned int V_14 )
{
unsigned int V_16 ;
V_16 = V_2 -> V_4 - V_2 -> V_5 ;
if ( V_14 > V_16 )
V_14 = V_16 ;
return F_29 ( V_2 , V_26 , V_27 , V_14 , V_2 -> V_5 ) ;
}
unsigned int F_32 ( unsigned int V_14 , T_1 V_32 )
{
unsigned int V_33 = ( 1 << ( V_32 << 3 ) ) - 1 ;
if ( V_14 > V_33 )
return V_33 ;
return V_14 ;
}
static unsigned int F_33 ( struct V_1 * V_2 , T_1 V_32 )
{
unsigned int V_16 ;
unsigned int V_3 = V_2 -> V_3 ;
unsigned char * V_9 = V_2 -> V_9 ;
V_16 = F_34 ( V_9 , V_2 -> V_5 , V_3 ) ;
if ( -- V_32 )
V_16 |= F_34 ( V_9 , V_2 -> V_5 + 1 , V_3 ) << 8 ;
return V_16 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_28 , T_1 V_32 )
{
unsigned int V_3 = V_2 -> V_3 ;
unsigned char * V_9 = V_2 -> V_9 ;
F_36 ( V_9 , V_2 -> V_4 , V_3 , V_28 ) ;
if ( V_32 > 1 )
F_36 ( V_9 , V_2 -> V_4 + 1 , V_3 , V_28 >> 8 ) ;
}
unsigned int F_37 ( struct V_1 * V_2 , T_1 V_32 )
{
return F_33 ( V_2 , V_32 ) ;
}
unsigned int F_38 ( struct V_1 * V_2 , const void * V_17 ,
unsigned int V_14 , T_1 V_32 )
{
if ( V_14 + V_32 > F_1 ( V_2 ) )
return 0 ;
F_35 ( V_2 , V_14 , V_32 ) ;
F_8 ( V_2 , V_17 , V_14 , V_2 -> V_4 + V_32 ) ;
V_2 -> V_4 += V_14 + V_32 ;
return V_14 ;
}
static unsigned int F_39 ( struct V_1 * V_2 ,
void * V_17 , unsigned int V_14 , T_1 V_32 , unsigned int * V_28 )
{
* V_28 = F_33 ( V_2 , V_32 ) ;
if ( V_14 > * V_28 )
V_14 = * V_28 ;
F_12 ( V_2 , V_17 , V_14 , V_2 -> V_5 + V_32 ) ;
return V_14 ;
}
unsigned int F_40 ( struct V_1 * V_2 , void * V_17 ,
unsigned int V_14 , T_1 V_32 )
{
unsigned int V_28 ;
if ( V_2 -> V_4 == V_2 -> V_5 )
return 0 ;
return F_39 ( V_2 , V_17 , V_14 , V_32 , & V_28 ) ;
}
unsigned int F_41 ( struct V_1 * V_2 , void * V_17 ,
unsigned int V_14 , T_1 V_32 )
{
unsigned int V_28 ;
if ( V_2 -> V_4 == V_2 -> V_5 )
return 0 ;
V_14 = F_39 ( V_2 , V_17 , V_14 , V_32 , & V_28 ) ;
V_2 -> V_5 += V_28 + V_32 ;
return V_14 ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_32 )
{
unsigned int V_28 ;
V_28 = F_33 ( V_2 , V_32 ) ;
V_2 -> V_5 += V_28 + V_32 ;
}
int F_43 ( struct V_1 * V_2 , const void T_3 * V_19 ,
unsigned long V_14 , unsigned int * V_20 , T_1 V_32 )
{
unsigned long V_21 ;
V_14 = F_32 ( V_14 , V_32 ) ;
if ( V_14 + V_32 > F_1 ( V_2 ) ) {
* V_20 = 0 ;
return 0 ;
}
F_35 ( V_2 , V_14 , V_32 ) ;
V_21 = F_15 ( V_2 , V_19 , V_14 , V_2 -> V_4 + V_32 , V_20 ) ;
if ( F_17 ( V_21 ) ) {
* V_20 = 0 ;
return - V_23 ;
}
V_2 -> V_4 += V_14 + V_32 ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 , void T_3 * V_24 ,
unsigned long V_14 , unsigned int * V_20 , T_1 V_32 )
{
unsigned long V_21 ;
unsigned int V_28 ;
if ( V_2 -> V_4 == V_2 -> V_5 ) {
* V_20 = 0 ;
return 0 ;
}
V_28 = F_33 ( V_2 , V_32 ) ;
if ( V_14 > V_28 )
V_14 = V_28 ;
V_21 = F_20 ( V_2 , V_24 , V_14 , V_2 -> V_5 + V_32 , V_20 ) ;
if ( F_17 ( V_21 ) ) {
* V_20 = 0 ;
return - V_23 ;
}
V_2 -> V_5 += V_28 + V_32 ;
return 0 ;
}
unsigned int F_45 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_27 , unsigned int V_14 , T_1 V_32 )
{
F_46 ( ! V_27 ) ;
V_14 = F_32 ( V_14 , V_32 ) ;
if ( V_14 + V_32 > F_1 ( V_2 ) )
return 0 ;
return F_29 ( V_2 , V_26 , V_27 , V_14 , V_2 -> V_4 + V_32 ) ;
}
void F_47 ( struct V_1 * V_2 ,
unsigned int V_14 , T_1 V_32 )
{
V_14 = F_32 ( V_14 , V_32 ) ;
F_35 ( V_2 , V_14 , V_32 ) ;
V_2 -> V_4 += V_14 + V_32 ;
}
unsigned int F_48 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_27 , unsigned int V_14 , T_1 V_32 )
{
F_46 ( ! V_27 ) ;
V_14 = F_32 ( V_14 , V_32 ) ;
if ( V_14 + V_32 > V_2 -> V_4 - V_2 -> V_5 )
return 0 ;
return F_29 ( V_2 , V_26 , V_27 , V_14 , V_2 -> V_5 + V_32 ) ;
}
void F_49 ( struct V_1 * V_2 , T_1 V_32 )
{
unsigned int V_14 ;
V_14 = F_33 ( V_2 , V_32 ) ;
V_2 -> V_5 += V_14 + V_32 ;
}
