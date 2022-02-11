T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_4 + ( V_3 ^ 0x2 ) ) ;
}
T_3 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_4 + ( V_3 ^ 0x3 ) ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_8 ( V_2 -> V_4 + V_3 , V_5 ) ;
}
void F_9 ( struct V_1 * V_2 , T_2 V_5 , int V_3 )
{
struct V_6 * V_7 = F_10 ( V_2 ) ;
int V_8 = V_3 & ~ 0x3 ;
int V_9 = ( V_3 & 0x2 ) * 8 ;
switch ( V_3 ) {
case V_10 :
V_7 -> V_11 = V_5 ;
return;
case V_12 :
F_7 ( V_2 , V_5 << 16 | V_7 -> V_11 ,
V_10 ) ;
return;
}
F_11 ( V_2 -> V_4 + V_8 , 0xffff << V_9 , V_5 << V_9 ) ;
}
void F_12 ( struct V_1 * V_2 , T_3 V_5 , int V_3 )
{
int V_8 = V_3 & ~ 0x3 ;
int V_9 = ( V_3 & 0x3 ) * 8 ;
F_11 ( V_2 -> V_4 + V_8 , 0xff << V_9 , V_5 << V_9 ) ;
}
static int F_13 ( struct V_13 * V_14 , T_4 V_15 )
{
struct V_1 * V_2 = F_14 ( & V_14 -> V_16 ) ;
return F_15 ( V_2 -> V_17 ) ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( & V_14 -> V_16 ) ;
return F_17 ( V_2 -> V_17 ) ;
}
static bool T_5 F_18 ( struct V_18 * V_19 )
{
if ( F_19 ( V_19 , L_1 , NULL ) )
return true ;
#ifdef F_20
return F_21 ( V_20 ) || F_21 ( V_21 ) ;
#else
return false ;
#endif
}
static int T_5 F_22 ( struct V_13 * V_14 )
{
const struct V_22 * V_23 ;
struct V_18 * V_19 = V_14 -> V_16 . V_24 ;
struct V_25 * V_25 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
const T_6 * V_26 ;
int V_27 ;
int V_28 ;
V_23 = F_23 ( V_29 , & V_14 -> V_16 ) ;
if ( ! V_23 )
return - V_30 ;
V_25 = V_23 -> V_31 ;
if ( ! F_24 ( V_19 ) )
return - V_32 ;
V_2 = F_25 ( & V_14 -> V_16 , sizeof( * V_7 ) ) ;
if ( F_26 ( V_2 ) )
return - V_33 ;
V_7 = F_10 ( V_2 ) ;
F_27 ( & V_14 -> V_16 , V_2 ) ;
V_2 -> V_4 = F_28 ( V_19 , 0 ) ;
if ( ! V_2 -> V_4 ) {
V_28 = - V_33 ;
goto V_34;
}
V_2 -> V_35 = F_29 ( V_19 , 0 ) ;
if ( ! V_2 -> V_35 ) {
V_28 = - V_30 ;
goto V_36;
}
V_2 -> V_37 = F_30 ( & V_14 -> V_16 ) ;
if ( V_25 ) {
V_2 -> V_38 = V_25 -> V_38 ;
V_2 -> V_39 = & V_25 -> V_39 ;
}
if ( F_19 ( V_19 , L_2 , NULL ) )
V_2 -> V_38 |= V_40 ;
if ( F_19 ( V_19 , L_3 , NULL ) )
V_2 -> V_38 |= V_41 ;
if ( F_18 ( V_19 ) )
V_2 -> V_38 |= V_42 ;
V_26 = F_19 ( V_19 , L_4 , & V_27 ) ;
if ( V_26 && V_27 == sizeof( * V_26 ) && * V_26 )
V_7 -> clock = F_31 ( V_26 ) ;
V_28 = F_32 ( V_2 ) ;
if ( V_28 )
goto V_43;
return 0 ;
V_43:
F_33 ( V_2 -> V_35 ) ;
V_36:
F_34 ( V_2 -> V_4 ) ;
V_34:
F_35 ( V_2 ) ;
return V_28 ;
}
static int T_7 F_36 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( & V_14 -> V_16 ) ;
F_37 ( V_2 , 0 ) ;
F_35 ( V_2 ) ;
F_33 ( V_2 -> V_35 ) ;
F_34 ( V_2 -> V_4 ) ;
return 0 ;
}
static int T_8 F_38 ( void )
{
return F_39 ( & V_44 ) ;
}
static void T_9 F_40 ( void )
{
F_41 ( & V_44 ) ;
}
