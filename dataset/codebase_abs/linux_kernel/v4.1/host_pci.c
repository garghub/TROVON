static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 -> V_5 ?
V_6 : V_7 ;
F_2 ( V_2 -> V_4 -> V_8 , V_9 ,
V_2 -> V_10 ) ;
F_2 ( V_2 -> V_4 -> V_8 , V_3 , V_2 -> V_11 ) ;
V_2 -> V_4 -> V_12 = V_2 ;
F_3 ( V_2 -> V_4 , L_1 , V_2 -> V_13 . V_13 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 . V_13 ) {
case V_14 :
return 3 * V_15 ;
case V_16 :
return 2 * V_15 ;
}
if ( V_2 -> V_4 -> V_12 != V_2 )
F_1 ( V_2 ) ;
return 0 ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_1 V_17 )
{
V_17 += F_4 ( V_2 ) ;
return F_6 ( V_2 -> V_4 -> V_18 + V_17 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_17 )
{
V_17 += F_4 ( V_2 ) ;
return F_8 ( V_2 -> V_4 -> V_18 + V_17 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 , T_1 V_17 )
{
V_17 += F_4 ( V_2 ) ;
return F_10 ( V_2 -> V_4 -> V_18 + V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_17 ,
T_2 V_19 )
{
V_17 += F_4 ( V_2 ) ;
F_12 ( V_19 , V_2 -> V_4 -> V_18 + V_17 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_19 )
{
V_17 += F_4 ( V_2 ) ;
F_14 ( V_19 , V_2 -> V_4 -> V_18 + V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_17 ,
T_3 V_19 )
{
V_17 += F_4 ( V_2 ) ;
F_16 ( V_19 , V_2 -> V_4 -> V_18 + V_17 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_20 ,
T_4 V_21 , T_1 V_17 , T_2 V_22 )
{
void T_5 * V_10 = V_2 -> V_4 -> V_18 + V_17 ;
if ( V_2 -> V_4 -> V_12 != V_2 )
F_1 ( V_2 ) ;
switch ( V_22 ) {
case sizeof( T_2 ) :
F_18 ( V_10 , V_20 , V_21 ) ;
break;
case sizeof( T_1 ) :
F_19 ( V_21 & 1 ) ;
F_20 ( V_10 , V_20 , V_21 >> 1 ) ;
break;
case sizeof( T_3 ) :
F_19 ( V_21 & 3 ) ;
F_21 ( V_10 , V_20 , V_21 >> 2 ) ;
break;
default:
F_19 ( 1 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
const void * V_20 , T_4 V_21 ,
T_1 V_17 , T_2 V_22 )
{
void T_5 * V_10 = V_2 -> V_4 -> V_18 + V_17 ;
if ( V_2 -> V_4 -> V_12 != V_2 )
F_1 ( V_2 ) ;
switch ( V_22 ) {
case sizeof( T_2 ) :
F_23 ( V_10 , V_20 , V_21 ) ;
break;
case sizeof( T_1 ) :
F_19 ( V_21 & 1 ) ;
F_24 ( V_10 , V_20 , V_21 >> 1 ) ;
break;
case sizeof( T_3 ) :
F_19 ( V_21 & 3 ) ;
F_25 ( V_10 , V_20 , V_21 >> 2 ) ;
break;
default:
F_19 ( 1 ) ;
}
}
static T_3 F_26 ( struct V_1 * V_2 , T_1 V_17 )
{
if ( V_2 -> V_4 -> V_12 != V_2 )
F_1 ( V_2 ) ;
return F_10 ( V_2 -> V_4 -> V_18 + ( 1 * V_15 ) + V_17 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_17 ,
T_3 V_19 )
{
if ( V_2 -> V_4 -> V_12 != V_2 )
F_1 ( V_2 ) ;
F_16 ( V_19 , V_2 -> V_4 -> V_18 + ( 1 * V_15 ) + V_17 ) ;
}
static int F_28 ( struct V_23 * V_24 ,
const struct V_25 * V_13 )
{
struct V_26 * V_4 ;
int V_27 = - V_28 ;
const char * V_29 ;
T_3 V_30 ;
V_4 = F_29 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
goto V_32;
V_27 = F_30 ( V_24 ) ;
if ( V_27 )
goto V_33;
V_29 = F_31 ( & V_24 -> V_24 ) ;
if ( V_24 -> V_34 && V_24 -> V_34 -> V_29 )
V_29 = V_24 -> V_34 -> V_29 ;
V_27 = F_32 ( V_24 , V_29 ) ;
if ( V_27 )
goto V_35;
F_33 ( V_24 ) ;
F_34 ( V_24 , 0x40 , & V_30 ) ;
if ( ( V_30 & 0x0000ff00 ) != 0 )
F_2 ( V_24 , 0x40 , V_30 & 0xffff00ff ) ;
if ( ! F_35 ( V_24 ) ) {
F_36 ( V_4 , L_2 ) ;
V_27 = - V_36 ;
goto V_37;
}
V_27 = - V_28 ;
V_4 -> V_18 = F_37 ( V_24 , 0 , ~ 0UL ) ;
if ( ! V_4 -> V_18 )
goto V_37;
V_4 -> V_8 = V_24 ;
V_4 -> V_38 = V_39 ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_42 . V_43 = V_4 -> V_8 -> V_44 ;
V_4 -> V_42 . type = V_4 -> V_8 -> V_45 ;
F_38 ( V_4 ) ;
V_27 = F_39 ( V_4 ) ;
if ( V_27 )
goto V_46;
if ( F_40 ( V_4 , V_47 ) )
V_4 -> V_5 = true ;
V_27 = F_41 ( V_4 ) ;
if ( V_27 )
goto V_48;
F_42 ( V_24 , V_4 ) ;
V_32:
return V_27 ;
V_48:
F_43 ( V_4 ) ;
V_46:
F_44 ( V_24 , V_4 -> V_18 ) ;
V_37:
F_45 ( V_24 ) ;
V_35:
F_46 ( V_24 ) ;
V_33:
F_47 ( V_4 ) ;
return V_27 ;
}
static void F_48 ( struct V_23 * V_24 )
{
struct V_26 * V_4 = F_49 ( V_24 ) ;
F_50 ( V_4 ) ;
F_44 ( V_24 , V_4 -> V_18 ) ;
F_45 ( V_24 ) ;
F_46 ( V_24 ) ;
F_47 ( V_4 ) ;
}
static int F_51 ( struct V_49 * V_24 )
{
struct V_23 * V_50 = F_52 ( V_24 ) ;
struct V_26 * V_4 = F_49 ( V_50 ) ;
V_4 -> V_12 = NULL ;
return F_53 ( V_4 ) ;
}
static int F_54 ( struct V_49 * V_24 )
{
struct V_23 * V_50 = F_52 ( V_24 ) ;
struct V_26 * V_4 = F_49 ( V_50 ) ;
return F_55 ( V_4 ) ;
}
int T_6 F_56 ( void )
{
return F_57 ( & V_51 ) ;
}
void T_7 F_58 ( void )
{
F_59 ( & V_51 ) ;
}
void F_60 ( struct V_26 * V_4 )
{
if ( V_4 -> V_38 != V_39 )
return;
if ( V_4 -> V_5 )
F_61 ( & V_4 -> V_52 ) ;
else
F_62 ( & V_4 -> V_53 [ 0 ] ) ;
}
void F_63 ( struct V_26 * V_4 )
{
if ( V_4 -> V_38 != V_39 )
return;
if ( ! V_4 -> V_5 )
F_64 ( & V_4 -> V_53 [ 0 ] ) ;
}
int F_65 ( struct V_26 * V_4 , struct V_1 * V_2 ,
bool V_54 )
{
struct V_23 * V_50 ;
T_3 V_55 , V_56 ;
int V_27 = 0 ;
if ( V_4 -> V_38 != V_39 ) {
goto V_32;
}
V_50 = V_4 -> V_8 ;
V_27 = F_34 ( V_50 , V_57 , & V_56 ) ;
if ( V_27 )
goto V_32;
V_55 = F_66 ( V_2 -> V_58 ) << 8 ;
if ( V_54 )
V_56 |= V_55 ;
else
V_56 &= ~ V_55 ;
V_27 = F_2 ( V_50 , V_57 , V_56 ) ;
V_32:
return V_27 ;
}
