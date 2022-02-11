static void
F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
V_2 /= 32 ;
V_3 = V_4 & ~ 0x00007f00 ;
V_3 |= V_2 << 8 ;
V_4 = V_3 ;
}
static void
F_2 ( struct V_1 * V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
V_2 /= 32 ;
V_3 = V_4 & ~ 0x0000007f ;
V_3 |= V_2 ;
V_4 = V_3 ;
}
static void
F_3 ( struct V_1 * V_1 , unsigned int V_5 , unsigned int V_6 )
{
int V_7 = - V_8 ;
int V_9 ;
V_10 = V_5 << 17 | V_11 | ( V_6 & 0xffff ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
F_4 ( V_1 -> V_12 ) ;
if ( V_13 & V_14 ) {
V_7 = 0 ;
break;
}
}
if ( V_7 < 0 )
F_5 ( V_15 L_1 ) ;
}
static unsigned int
F_6 ( struct V_1 * V_1 , unsigned int V_5 )
{
int V_7 = - V_8 ;
int V_9 ;
V_10 = V_5 << 17 | V_16 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
F_4 ( V_1 -> V_12 ) ;
if ( V_13 & V_17 ) {
V_7 = V_10 & 0xffff ;
break;
}
}
if ( V_7 < 0 )
F_5 ( V_15 L_2 ) ;
return V_7 ;
}
static void F_7 ( struct V_1 * V_1 )
{
V_13 = - 1 ;
V_4 |= V_18 ;
}
static void F_8 ( struct V_1 * V_1 )
{
V_4 &= ~ V_18 ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_24 ;
struct V_1 * V_1 ;
int V_7 ;
if ( ! V_22 )
return - V_25 ;
if ( ! F_10 ( 0x80060000 , 0x60 , L_3 ) )
return - V_26 ;
V_1 = F_11 ( & V_20 -> V_23 , sizeof( struct V_27 ) ) ;
if ( ! V_1 ) {
V_7 = - V_28 ;
goto V_29;
}
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = & V_27 ;
V_1 -> V_33 = V_22 -> V_33 ;
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = V_22 -> V_42 ;
F_12 ( V_20 , V_1 ) ;
if ( F_13 () ) {
F_14 ( V_43 ) ;
}
V_44 &= ~ V_45 ;
V_44 |= V_46 | V_47 | V_48 ;
V_49 |= V_45 ;
V_49 &= ~ ( V_46 | V_47 | V_48 ) ;
V_50 &= ~ ( V_46 | V_47 | V_48 ) ;
V_13 = - 1 ;
V_51 = V_22 -> V_52 ;
V_4 = V_22 -> V_3 | 0x7f7f ;
V_1 -> V_12 = ( 64 * 3 * 1000000 + V_1 -> V_33 - 1 ) /
V_1 -> V_33 ;
V_7 = F_15 ( V_1 ) ;
if ( V_7 == 0 )
goto V_53;
V_29:
F_16 ( 0x80060000 , 0x60 ) ;
F_12 ( V_20 , NULL ) ;
V_53:
return V_7 ;
}
static int F_17 ( struct V_19 * V_23 )
{
struct V_1 * V_1 = F_18 ( V_23 ) ;
F_12 ( V_23 , NULL ) ;
F_19 ( V_1 ) ;
F_16 ( 0x80060000 , 0x60 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_23 , T_1 V_54 )
{
struct V_1 * V_1 = F_18 ( V_23 ) ;
F_21 ( V_1 ) -> V_3 = V_4 ;
F_21 ( V_1 ) -> V_52 = V_51 ;
V_4 &= ~ V_18 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_23 )
{
struct V_1 * V_1 = F_18 ( V_23 ) ;
V_51 = F_21 ( V_1 ) -> V_52 ;
V_4 = F_21 ( V_1 ) -> V_3 ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_55 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_55 ) ;
}
