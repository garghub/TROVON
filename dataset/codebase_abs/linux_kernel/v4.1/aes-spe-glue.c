static void F_1 ( void )
{
F_2 () ;
F_3 () ;
}
static void F_4 ( void )
{
F_5 () ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
if ( V_4 != V_7 &&
V_4 != V_8 &&
V_4 != V_9 ) {
V_2 -> V_10 |= V_11 ;
return - V_12 ;
}
switch ( V_4 ) {
case V_7 :
V_6 -> V_13 = 4 ;
F_8 ( V_6 -> V_14 , V_3 ) ;
break;
case V_8 :
V_6 -> V_13 = 5 ;
F_9 ( V_6 -> V_14 , V_3 ) ;
break;
case V_9 :
V_6 -> V_13 = 6 ;
F_10 ( V_6 -> V_14 , V_3 ) ;
break;
}
F_11 ( V_6 -> V_15 , V_6 -> V_14 , V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_16 * V_6 = F_7 ( V_2 ) ;
V_4 >>= 1 ;
if ( V_4 != V_7 &&
V_4 != V_8 &&
V_4 != V_9 ) {
V_2 -> V_10 |= V_11 ;
return - V_12 ;
}
switch ( V_4 ) {
case V_7 :
V_6 -> V_13 = 4 ;
F_8 ( V_6 -> V_14 , V_3 ) ;
F_8 ( V_6 -> V_17 , V_3 + V_7 ) ;
break;
case V_8 :
V_6 -> V_13 = 5 ;
F_9 ( V_6 -> V_14 , V_3 ) ;
F_9 ( V_6 -> V_17 , V_3 + V_8 ) ;
break;
case V_9 :
V_6 -> V_13 = 6 ;
F_10 ( V_6 -> V_14 , V_3 ) ;
F_10 ( V_6 -> V_17 , V_3 + V_9 ) ;
break;
}
F_11 ( V_6 -> V_15 , V_6 -> V_14 , V_4 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 * V_18 , const T_1 * V_19 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
F_1 () ;
F_14 ( V_18 , V_19 , V_6 -> V_14 , V_6 -> V_13 ) ;
F_4 () ;
}
static void F_15 ( struct V_1 * V_2 , T_1 * V_18 , const T_1 * V_19 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
F_1 () ;
F_16 ( V_18 , V_19 , V_6 -> V_15 , V_6 -> V_13 ) ;
F_4 () ;
}
static int F_17 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_5 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_28 ;
int V_29 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_20 ( V_21 , & V_27 ) ;
while ( ( V_25 = V_27 . V_25 ) ) {
V_28 = V_25 > V_32 ?
V_25 - V_32 : V_25 & ( V_33 - 1 ) ;
V_25 -= V_28 ;
F_1 () ;
F_21 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_14 , V_6 -> V_13 , V_25 ) ;
F_4 () ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int F_23 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_5 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_28 ;
int V_29 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_20 ( V_21 , & V_27 ) ;
while ( ( V_25 = V_27 . V_25 ) ) {
V_28 = V_25 > V_32 ?
V_25 - V_32 : V_25 & ( V_33 - 1 ) ;
V_25 -= V_28 ;
F_1 () ;
F_24 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_15 , V_6 -> V_13 , V_25 ) ;
F_4 () ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int F_25 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_5 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_28 ;
int V_29 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_20 ( V_21 , & V_27 ) ;
while ( ( V_25 = V_27 . V_25 ) ) {
V_28 = V_25 > V_32 ?
V_25 - V_32 : V_25 & ( V_33 - 1 ) ;
V_25 -= V_28 ;
F_1 () ;
F_26 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_14 , V_6 -> V_13 , V_25 , V_27 . V_36 ) ;
F_4 () ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int F_27 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_5 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_28 ;
int V_29 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_20 ( V_21 , & V_27 ) ;
while ( ( V_25 = V_27 . V_25 ) ) {
V_28 = V_25 > V_32 ?
V_25 - V_32 : V_25 & ( V_33 - 1 ) ;
V_25 -= V_28 ;
F_1 () ;
F_28 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_15 , V_6 -> V_13 , V_25 , V_27 . V_36 ) ;
F_4 () ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int F_29 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_5 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_37 , V_28 ;
int V_29 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_30 ( V_21 , & V_27 , V_33 ) ;
while ( ( V_37 = V_27 . V_25 ) ) {
V_37 = V_37 > V_32 ? V_32 : V_37 ;
V_37 = V_37 == V_25 ?
V_25 : V_37 & ~ ( V_33 - 1 ) ;
V_28 = V_27 . V_25 - V_37 ;
F_1 () ;
F_31 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_14 , V_6 -> V_13 , V_37 , V_27 . V_36 ) ;
F_4 () ;
V_25 -= V_37 ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int F_32 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_16 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_28 ;
int V_29 ;
T_2 * V_38 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_20 ( V_21 , & V_27 ) ;
V_38 = V_6 -> V_17 ;
while ( ( V_25 = V_27 . V_25 ) ) {
V_28 = V_25 > V_32 ?
V_25 - V_32 : V_25 & ( V_33 - 1 ) ;
V_25 -= V_28 ;
F_1 () ;
F_33 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_14 , V_6 -> V_13 , V_25 , V_27 . V_36 , V_38 ) ;
F_4 () ;
V_38 = NULL ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int F_34 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_22 * V_24 , unsigned int V_25 )
{
struct V_16 * V_6 = F_18 ( V_21 -> V_2 ) ;
struct V_26 V_27 ;
unsigned int V_28 ;
int V_29 ;
T_2 * V_38 ;
V_21 -> V_30 &= ~ V_31 ;
F_19 ( & V_27 , V_23 , V_24 , V_25 ) ;
V_29 = F_20 ( V_21 , & V_27 ) ;
V_38 = V_6 -> V_17 ;
while ( ( V_25 = V_27 . V_25 ) ) {
V_28 = V_25 > V_32 ?
V_25 - V_32 : V_25 & ( V_33 - 1 ) ;
V_25 -= V_28 ;
F_1 () ;
F_35 ( V_27 . V_23 . V_34 . V_35 , V_27 . V_24 . V_34 . V_35 ,
V_6 -> V_15 , V_6 -> V_13 , V_25 , V_27 . V_36 , V_38 ) ;
F_4 () ;
V_38 = NULL ;
V_29 = F_22 ( V_21 , & V_27 , V_28 ) ;
}
return V_29 ;
}
static int T_3 F_36 ( void )
{
return F_37 ( V_39 , F_38 ( V_39 ) ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( V_39 , F_38 ( V_39 ) ) ;
}
