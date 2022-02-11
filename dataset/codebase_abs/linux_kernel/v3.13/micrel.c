static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & V_5 ) {
V_3 = F_2 ( V_2 , V_6 ) ;
V_3 |= V_7 ;
return F_3 ( V_2 , V_6 , V_3 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_8 , T_2 V_9 )
{
F_3 ( V_2 , V_10 , V_11 | V_8 ) ;
return F_3 ( V_2 , V_12 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_8 )
{
F_3 ( V_2 , V_10 , V_8 ) ;
return F_2 ( V_2 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_2 ( V_2 , V_15 ) ;
return ( V_14 < 0 ) ? V_14 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = ( V_17 == V_2 -> V_18 ) ?
V_19 : 0 ;
return F_3 ( V_2 , V_15 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_16 , V_14 ;
V_16 = F_2 ( V_2 , V_6 ) ;
V_16 &= ~ V_20 ;
F_3 ( V_2 , V_6 , V_16 ) ;
V_14 = F_7 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_16 , V_14 ;
V_16 = F_2 ( V_2 , V_6 ) ;
V_16 &= ~ V_21 ;
F_3 ( V_2 , V_6 , V_16 ) ;
V_14 = F_7 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_16 , V_14 ;
V_16 = F_2 ( V_2 , V_6 ) ;
V_16 &= ~ V_22 ;
F_3 ( V_2 , V_6 , V_16 ) ;
V_14 = F_7 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_14 ;
const T_2 V_9 = V_23 | V_24 ;
F_3 ( V_2 , V_25 , V_9 ) ;
V_14 = F_1 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_1 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_26 * V_27 , T_2 V_28 ,
char * V_29 , char * V_30 ,
char * V_31 , char * V_32 )
{
int V_33 = - 1 ;
int V_34 = - 2 ;
int V_35 = - 3 ;
int V_36 = - 4 ;
int V_37 ;
int V_38 = 0 ;
if ( ! F_15 ( V_27 , V_29 , & V_33 ) )
V_38 ++ ;
if ( ! F_15 ( V_27 , V_30 , & V_34 ) )
V_38 ++ ;
if ( ! F_15 ( V_27 , V_31 , & V_35 ) )
V_38 ++ ;
if ( ! F_15 ( V_27 , V_32 , & V_36 ) )
V_38 ++ ;
if ( ! V_38 )
return 0 ;
if ( V_38 < 4 )
V_37 = F_5 ( V_2 , V_28 ) ;
else
V_37 = 0 ;
if ( V_33 != - 1 )
V_37 = ( ( V_37 & 0xfff0 ) | ( ( V_33 / V_39 ) & 0xf ) << 0 ) ;
if ( V_34 != - 1 )
V_37 = ( ( V_37 & 0xff0f ) | ( ( V_34 / V_39 ) & 0xf ) << 4 ) ;
if ( V_35 != - 1 )
V_37 = ( ( V_37 & 0xf0ff ) | ( ( V_35 / V_39 ) & 0xf ) << 8 ) ;
if ( V_36 != - 1 )
V_37 = ( ( V_37 & 0x0fff ) | ( ( V_36 / V_39 ) & 0xf ) << 12 ) ;
return F_4 ( V_2 , V_28 , V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
struct V_26 * V_27 = V_41 -> V_27 ;
if ( ! V_27 && V_41 -> V_42 -> V_27 )
V_27 = V_41 -> V_42 -> V_27 ;
if ( V_27 ) {
F_14 ( V_2 , V_27 ,
V_43 ,
L_1 , L_2 ,
L_3 , L_4 ) ;
F_14 ( V_2 , V_27 ,
V_44 ,
L_5 , L_6 ,
L_7 , L_8 ) ;
F_14 ( V_2 , V_27 ,
V_45 ,
L_9 , L_10 ,
L_11 , L_12 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_46 ) ;
V_3 = F_2 ( V_2 , V_46 ) ;
if ( V_3 & V_47 )
V_2 -> V_48 = V_49 ;
else
V_2 -> V_48 = V_50 ;
if ( V_3 & V_51 )
V_2 -> V_52 = V_53 ;
else
V_2 -> V_52 = V_54 ;
V_2 -> V_55 = 1 ;
V_2 -> V_56 = V_2 -> V_57 = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( V_58 ,
F_21 ( V_58 ) ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( V_58 ,
F_21 ( V_58 ) ) ;
}
