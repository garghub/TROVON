static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] & 0xff )
F_2 ( V_4 -> V_8 & 0xff , V_2 -> V_9 + V_10 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 & 0xff ;
V_7 [ 1 ] |= F_3 ( V_2 -> V_9 + V_11 ) ;
return V_6 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_13 = 1 << F_5 ( V_6 -> V_14 ) ;
switch ( V_7 [ 0 ] ) {
case V_15 :
break;
case V_16 :
break;
case V_17 :
V_7 [ 1 ] = ( V_4 -> V_18 & V_13 ) ? V_19 : V_20 ;
break;
default:
return - V_21 ;
}
return V_6 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
const struct V_24 * V_25 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_26 * V_27 ;
int V_28 ;
V_27 = V_29 ;
if ( ! V_27 )
return - V_30 ;
V_2 -> V_9 = V_27 -> V_31 [ 0 ] -> V_32 ;
if ( ! V_2 -> V_9 ) {
F_8 ( V_2 -> V_33 , L_1 ) ;
return - V_21 ;
}
V_2 -> V_34 = V_25 -> V_35 ;
V_28 = F_9 ( V_2 , 1 ) ;
if ( V_28 )
return V_28 ;
V_4 = V_2 -> V_36 + 0 ;
V_4 -> type = V_37 ;
V_4 -> V_38 = V_39 | V_40 ;
V_4 -> V_41 = 16 ;
V_4 -> V_42 = & V_43 ;
V_4 -> V_44 = 1 ;
V_4 -> V_45 = F_1 ;
V_4 -> V_46 = F_4 ;
V_4 -> V_8 = 0 ;
V_4 -> V_18 = 0x00ff ;
F_10 ( V_2 -> V_33 , L_2 ,
V_2 -> V_47 -> V_48 ,
V_2 -> V_34 ,
V_2 -> V_9 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
static int F_12 ( struct V_26 * V_49 ,
void * V_50 )
{
if ( V_49 -> V_51 == 0 )
return - V_21 ;
return F_13 ( V_49 ) ;
}
static int F_14 ( struct V_26 * V_27 )
{
int V_28 ;
V_27 -> V_52 |= V_53 | V_54 |
V_55 ;
V_28 = F_15 ( V_27 , F_12 , NULL ) ;
if ( V_28 )
goto V_56;
if ( ! V_27 -> V_57 )
goto V_56;
V_28 = F_16 ( V_27 ) ;
if ( V_28 )
goto V_56;
V_29 = V_27 ;
return 0 ;
V_56:
F_17 ( V_27 ) ;
return V_28 ;
}
static void F_18 ( struct V_26 * V_27 )
{
F_17 ( V_27 ) ;
V_29 = NULL ;
}
static int T_1 F_19 ( void )
{
int V_28 ;
V_28 = F_20 ( & V_58 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_21 ( & V_59 ) ;
if ( V_28 < 0 ) {
F_22 ( & V_58 ) ;
return V_28 ;
}
return 0 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_59 ) ;
F_22 ( & V_58 ) ;
}
