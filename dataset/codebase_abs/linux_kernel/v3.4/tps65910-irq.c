static inline int F_1 ( struct V_1 * V_1 ,
int V_2 )
{
return ( V_2 - V_1 -> V_3 ) ;
}
static T_1 F_2 ( int V_2 , void * V_4 )
{
struct V_1 * V_1 = V_4 ;
T_2 V_5 ;
T_2 V_6 ;
T_3 V_7 ;
int V_8 ;
V_1 -> V_9 ( V_1 , V_10 , 1 , & V_7 ) ;
V_5 = V_7 ;
V_1 -> V_9 ( V_1 , V_11 , 1 , & V_7 ) ;
V_5 |= V_7 << 8 ;
switch ( F_3 ( V_1 ) ) {
case V_12 :
V_1 -> V_9 ( V_1 , V_13 , 1 , & V_7 ) ;
V_5 |= V_7 << 16 ;
}
V_1 -> V_9 ( V_1 , V_14 , 1 , & V_7 ) ;
V_6 = V_7 ;
V_1 -> V_9 ( V_1 , V_15 , 1 , & V_7 ) ;
V_6 |= V_7 << 8 ;
switch ( F_3 ( V_1 ) ) {
case V_12 :
V_1 -> V_9 ( V_1 , V_16 , 1 , & V_7 ) ;
V_6 |= V_7 << 16 ;
}
V_5 &= ~ V_6 ;
if ( ! V_5 )
return V_17 ;
for ( V_8 = 0 ; V_8 < V_1 -> V_18 ; V_8 ++ ) {
if ( ! ( V_5 & ( 1 << V_8 ) ) )
continue;
F_4 ( V_1 -> V_3 + V_8 ) ;
}
V_7 = V_5 & 0xFF ;
V_5 >>= 8 ;
V_1 -> V_19 ( V_1 , V_10 , 1 , & V_7 ) ;
V_7 = V_5 & 0xFF ;
V_1 -> V_19 ( V_1 , V_11 , 1 , & V_7 ) ;
switch ( F_3 ( V_1 ) ) {
case V_12 :
V_7 = V_5 >> 8 ;
V_1 -> V_19 ( V_1 , V_13 , 1 , & V_7 ) ;
}
return V_20 ;
}
static void F_5 ( struct V_4 * V_21 )
{
struct V_1 * V_1 = F_6 ( V_21 ) ;
F_7 ( & V_1 -> V_22 ) ;
}
static void F_8 ( struct V_4 * V_21 )
{
struct V_1 * V_1 = F_6 ( V_21 ) ;
T_2 V_23 ;
T_3 V_7 ;
V_1 -> V_9 ( V_1 , V_14 , 1 , & V_7 ) ;
V_23 = V_7 ;
V_1 -> V_9 ( V_1 , V_15 , 1 , & V_7 ) ;
V_23 |= V_7 << 8 ;
switch ( F_3 ( V_1 ) ) {
case V_12 :
V_1 -> V_9 ( V_1 , V_16 , 1 , & V_7 ) ;
V_23 |= V_7 << 16 ;
}
if ( V_1 -> V_6 != V_23 ) {
V_7 = V_1 -> V_6 & 0xFF ;
V_1 -> V_19 ( V_1 , V_14 , 1 , & V_7 ) ;
V_7 = V_1 -> V_6 >> 8 & 0xFF ;
V_1 -> V_19 ( V_1 , V_15 , 1 , & V_7 ) ;
switch ( F_3 ( V_1 ) ) {
case V_12 :
V_7 = V_1 -> V_6 >> 16 ;
V_1 -> V_19 ( V_1 , V_16 , 1 , & V_7 ) ;
}
}
F_9 ( & V_1 -> V_22 ) ;
}
static void F_10 ( struct V_4 * V_21 )
{
struct V_1 * V_1 = F_6 ( V_21 ) ;
V_1 -> V_6 &= ~ ( 1 << F_1 ( V_1 , V_21 -> V_2 ) ) ;
}
static void F_11 ( struct V_4 * V_21 )
{
struct V_1 * V_1 = F_6 ( V_21 ) ;
V_1 -> V_6 |= ( 1 << F_1 ( V_1 , V_21 -> V_2 ) ) ;
}
static int F_12 ( struct V_4 * V_21 , unsigned int V_24 )
{
struct V_1 * V_1 = F_6 ( V_21 ) ;
return F_13 ( V_1 -> V_25 , V_24 ) ;
}
int F_14 ( struct V_1 * V_1 , int V_2 ,
struct V_26 * V_27 )
{
int V_28 , V_29 ;
int V_30 = V_31 ;
if ( ! V_2 ) {
F_15 ( V_1 -> V_32 , L_1 ) ;
return - V_33 ;
}
if ( ! V_27 || ! V_27 -> V_3 ) {
F_15 ( V_1 -> V_32 , L_2 ) ;
return - V_33 ;
}
V_1 -> V_6 = 0xFFFFFF ;
F_16 ( & V_1 -> V_22 ) ;
V_1 -> V_25 = V_2 ;
V_1 -> V_3 = V_27 -> V_3 ;
switch ( F_3 ( V_1 ) ) {
case V_34 :
V_1 -> V_18 = V_35 ;
break;
case V_12 :
V_1 -> V_18 = V_36 ;
break;
}
for ( V_29 = V_1 -> V_3 ;
V_29 < V_1 -> V_18 + V_1 -> V_3 ;
V_29 ++ ) {
F_17 ( V_29 , V_1 ) ;
F_18 ( V_29 , & V_37 ,
V_38 ) ;
F_19 ( V_29 , 1 ) ;
#ifdef F_20
F_21 ( V_29 , V_39 ) ;
#else
F_22 ( V_29 ) ;
#endif
}
V_28 = F_23 ( V_2 , NULL , F_2 , V_30 ,
L_3 , V_1 ) ;
F_24 ( V_2 , V_40 ) ;
if ( V_28 != 0 )
F_25 ( V_1 -> V_32 , L_4 , V_28 ) ;
return V_28 ;
}
int F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_25 )
F_27 ( V_1 -> V_25 , V_1 ) ;
return 0 ;
}
