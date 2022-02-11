static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_2 ( V_2 -> V_4 , L_1 , V_3 ) ;
F_3 ( V_2 -> V_5 + V_6 , V_3 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_5 ( V_2 -> V_5 + V_7 ) ;
F_2 ( V_2 -> V_4 , L_2 , V_3 ) ;
return V_3 ;
}
static inline void F_6 ( struct V_1 * V_2 ,
T_1 V_3 )
{
F_3 ( V_2 -> V_5 + V_8 , V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 + V_9 , V_10 ) ;
F_2 ( V_2 -> V_4 , L_3 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 + V_9 , V_11 ) ;
F_2 ( V_2 -> V_4 , L_4 ) ;
}
T_1 F_9 ( struct V_1 * V_2 )
{
T_1 V_12 = F_5 ( V_2 -> V_5 + V_13 ) ;
F_2 ( V_2 -> V_4 , L_5 , V_12 ) ;
return V_12 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_12 = F_5 ( V_2 -> V_5 + V_13 ) ;
return ( V_12 & V_14 ) ? 0 : 1 ;
}
static inline T_1 F_11 (
struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_5 + V_15 ) ;
}
static inline T_1 F_12 (
struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_5 + V_16 ) ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 * V_17 , T_1 V_18 )
{
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
T_1 V_21 ;
F_2 ( V_2 -> V_4 , L_6 ) ;
if ( F_10 ( V_2 ) )
return - V_22 ;
V_21 = V_18 ;
while ( V_21 > 0 ) {
while ( V_19 == 0 ) {
V_19 =
F_11 ( V_2 ) ;
V_20 ++ ;
if ( V_20 > V_23 )
return - V_24 ;
}
while ( ( V_19 != 0 ) &&
( V_21 > 0 ) ) {
F_1 ( V_2 , * V_17 ) ;
V_21 -- ;
V_19 -- ;
V_17 ++ ;
}
F_7 ( V_2 ) ;
}
while ( F_10 ( V_2 ) ) {
V_20 ++ ;
if ( V_20 > V_23 )
break;
}
F_2 ( V_2 -> V_4 , L_7 ) ;
if ( V_21 != 0 )
return - V_24 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
T_1 * V_17 , T_1 V_18 )
{
T_1 V_25 = 0 ;
T_1 V_20 = 0 ;
T_1 * V_3 = V_17 ;
T_1 V_21 ;
T_1 V_26 ;
F_2 ( V_2 -> V_4 , L_8 ) ;
if ( F_10 ( V_2 ) )
return - V_22 ;
V_21 = V_18 ;
while ( V_21 > 0 ) {
V_26 = V_21 ;
if ( V_26 > V_27 )
V_26 = V_27 ;
V_21 -= V_26 ;
F_6 ( V_2 , V_26 ) ;
F_8 ( V_2 ) ;
while ( V_26 > 0 ) {
while ( V_25 == 0 ) {
V_25 =
F_12 ( V_2 ) ;
V_20 ++ ;
if ( V_20 > V_23 )
return - V_24 ;
}
if ( V_25 > V_26 )
V_25 = V_26 ;
V_26 -= V_25 ;
while ( V_25 != 0 ) {
* V_3 ++ = F_4 ( V_2 ) ;
V_25 -- ;
}
}
}
F_2 ( V_2 -> V_4 , L_9 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_5 ( V_2 -> V_5 + V_9 ) ;
F_3 ( V_2 -> V_5 + V_9 ,
V_28 | V_29 ) ;
F_3 ( V_2 -> V_5 + V_9 ,
V_28 & ( ~ V_29 ) ) ;
}
void F_16 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_5 ( V_2 -> V_5 + V_9 ) ;
F_3 ( V_2 -> V_5 + V_9 ,
V_28 | V_30 ) ;
F_3 ( V_2 -> V_5 + V_9 ,
V_28 & ( ~ V_30 ) ) ;
}
