static void
F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
V_2 /= 32 ;
V_4 -> V_5 &= ~ 0x00007f00 ;
V_4 -> V_5 |= V_2 << 8 ;
F_3 ( V_4 -> V_5 , F_4 ( V_4 ) ) ;
}
static void
F_5 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
V_2 /= 32 ;
V_4 -> V_5 &= ~ 0x0000007f ;
V_4 -> V_5 |= V_2 ;
F_3 ( V_4 -> V_5 , F_4 ( V_4 ) ) ;
}
static void
F_6 ( struct V_1 * V_1 , unsigned int V_6 , unsigned int V_7 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int V_8 = - V_9 ;
int V_10 ;
F_3 ( V_6 << 17 | V_11 | ( V_7 & 0xffff ) , F_7 ( V_4 ) ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_8 ( V_1 -> V_12 ) ;
if ( F_9 ( F_10 ( V_4 ) ) & V_13 ) {
V_8 = 0 ;
break;
}
}
if ( V_8 < 0 )
F_11 ( V_14 L_1 ) ;
}
static unsigned int
F_12 ( struct V_1 * V_1 , unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int V_8 = - V_9 ;
int V_10 ;
F_3 ( V_6 << 17 | V_15 , F_7 ( V_4 ) ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_8 ( V_1 -> V_12 ) ;
if ( F_9 ( F_10 ( V_4 ) ) & V_16 ) {
V_8 = F_9 ( F_7 ( V_4 ) ) & 0xffff ;
break;
}
}
if ( V_8 < 0 )
F_11 ( V_14 L_2 ) ;
return V_8 ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
F_14 ( - 1 , F_10 ( V_4 ) ) ;
V_4 -> V_5 |= V_17 ;
F_3 ( V_4 -> V_5 , F_4 ( V_4 ) ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
V_4 -> V_5 &= ~ V_17 ;
F_3 ( V_4 -> V_5 , F_4 ( V_4 ) ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_19 . V_22 ;
struct V_23 * V_24 , * V_25 ;
struct V_3 * V_4 ;
struct V_1 * V_1 ;
int V_8 ;
if ( ! V_21 )
return - V_26 ;
V_24 = F_17 ( V_19 , V_27 , 0 ) ;
V_25 = F_17 ( V_19 , V_27 , 1 ) ;
if ( ! V_24 || ! V_25 )
return - V_28 ;
if ( ! F_18 ( V_24 -> V_29 , F_19 ( V_24 ) ,
V_30 ) ) {
V_8 = - V_31 ;
goto V_32;
}
if ( ! F_18 ( V_25 -> V_29 , F_19 ( V_25 ) ,
V_30 ) ) {
V_8 = - V_31 ;
goto V_33;
}
V_1 = F_20 ( & V_19 -> V_19 , sizeof( struct V_3 ) ) ;
if ( ! V_1 ) {
V_8 = - V_34 ;
goto V_35;
}
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = & V_3 ;
V_1 -> V_39 = V_21 -> V_39 ;
V_4 = F_2 ( V_1 ) ;
V_4 -> V_5 = V_21 -> V_5 | 0x7f7f ;
V_4 -> V_40 = V_21 -> V_40 ;
V_4 -> V_41 = F_21 ( V_24 -> V_29 , F_19 ( V_24 ) ) ;
V_4 -> V_42 = F_21 ( V_25 -> V_29 , F_19 ( V_25 ) ) ;
if ( ! V_4 -> V_41 || ! V_4 -> V_42 ) {
V_8 = - V_34 ;
goto V_43;
}
F_22 ( V_19 , V_1 ) ;
F_3 ( - 1 , F_10 ( V_4 ) ) ;
F_3 ( V_4 -> V_40 , F_23 ( V_4 ) ) ;
F_3 ( V_4 -> V_5 , F_4 ( V_4 ) ) ;
V_1 -> V_12 = ( 64 * 3 * 1000000 + V_1 -> V_39 - 1 ) /
V_1 -> V_39 ;
V_8 = F_24 ( V_1 , V_21 -> V_44 ) ;
if ( V_8 == 0 )
return 0 ;
V_43:
F_25 ( V_4 -> V_42 ) ;
F_25 ( V_4 -> V_41 ) ;
F_26 ( V_1 ) ;
V_35:
F_27 ( V_25 -> V_29 , F_19 ( V_25 ) ) ;
V_33:
F_27 ( V_24 -> V_29 , F_19 ( V_24 ) ) ;
V_32:
return V_8 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = F_29 ( V_19 ) ;
struct V_3 * V_4 = F_2 ( V_1 ) ;
struct V_23 * V_24 , * V_25 ;
if ( V_4 -> V_5 & V_17 )
F_30 ( & V_19 -> V_19 ,
L_3 ) ;
V_24 = F_17 ( V_19 , V_27 , 0 ) ;
V_25 = F_17 ( V_19 , V_27 , 1 ) ;
F_31 ( V_1 ) ;
F_25 ( V_4 -> V_42 ) ;
F_25 ( V_4 -> V_41 ) ;
F_26 ( V_1 ) ;
F_27 ( V_25 -> V_29 , F_19 ( V_25 ) ) ;
F_27 ( V_24 -> V_29 , F_19 ( V_24 ) ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_19 )
{
struct V_3 * V_4 = F_2 ( F_33 ( V_19 ) ) ;
if ( V_4 -> V_5 & V_17 )
F_30 ( V_19 , L_3 ) ;
F_14 ( V_4 -> V_5 & ~ V_17 , F_4 ( V_4 ) ) ;
return 0 ;
}
static int F_34 ( struct V_45 * V_19 )
{
struct V_3 * V_4 = F_2 ( F_33 ( V_19 ) ) ;
F_3 ( V_4 -> V_40 , F_23 ( V_4 ) ) ;
F_3 ( V_4 -> V_5 , F_4 ( V_4 ) ) ;
return 0 ;
}
