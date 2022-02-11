static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 -> V_4 , V_5 ,
V_2 -> V_6 ) ;
F_2 ( V_2 -> V_3 -> V_4 , V_7 ,
V_2 -> V_8 ) ;
V_2 -> V_3 -> V_9 = V_2 ;
F_3 ( V_2 -> V_3 , L_1 , V_2 -> V_10 . V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 . V_10 ) {
case V_11 :
return 3 * V_12 ;
case V_13 :
return 2 * V_12 ;
}
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return 0 ;
}
static T_2 F_5 ( struct V_1 * V_2 , T_1 V_14 )
{
V_14 += F_4 ( V_2 ) ;
return F_6 ( V_2 -> V_3 -> V_15 + V_14 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_14 )
{
V_14 += F_4 ( V_2 ) ;
return F_8 ( V_2 -> V_3 -> V_15 + V_14 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 , T_1 V_14 )
{
V_14 += F_4 ( V_2 ) ;
return F_10 ( V_2 -> V_3 -> V_15 + V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_14 ,
T_2 V_16 )
{
V_14 += F_4 ( V_2 ) ;
F_12 ( V_16 , V_2 -> V_3 -> V_15 + V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_16 )
{
V_14 += F_4 ( V_2 ) ;
F_14 ( V_16 , V_2 -> V_3 -> V_15 + V_14 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_14 ,
T_3 V_16 )
{
V_14 += F_4 ( V_2 ) ;
F_16 ( V_16 , V_2 -> V_3 -> V_15 + V_14 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_17 ,
T_4 V_18 , T_1 V_14 , T_2 V_19 )
{
void T_5 * V_6 = V_2 -> V_3 -> V_15 + V_14 ;
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
switch ( V_19 ) {
case sizeof( T_2 ) :
F_18 ( V_6 , V_17 , V_18 ) ;
break;
case sizeof( T_1 ) :
F_19 ( V_18 & 1 ) ;
F_20 ( V_6 , V_17 , V_18 >> 1 ) ;
break;
case sizeof( T_3 ) :
F_19 ( V_18 & 3 ) ;
F_21 ( V_6 , V_17 , V_18 >> 2 ) ;
break;
default:
F_19 ( 1 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
const void * V_17 , T_4 V_18 ,
T_1 V_14 , T_2 V_19 )
{
void T_5 * V_6 = V_2 -> V_3 -> V_15 + V_14 ;
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
switch ( V_19 ) {
case sizeof( T_2 ) :
F_23 ( V_6 , V_17 , V_18 ) ;
break;
case sizeof( T_1 ) :
F_19 ( V_18 & 1 ) ;
F_24 ( V_6 , V_17 , V_18 >> 1 ) ;
break;
case sizeof( T_3 ) :
F_19 ( V_18 & 3 ) ;
F_25 ( V_6 , V_17 , V_18 >> 2 ) ;
break;
default:
F_19 ( 1 ) ;
}
}
static T_3 F_26 ( struct V_1 * V_2 , T_1 V_14 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return F_10 ( V_2 -> V_3 -> V_15 + ( 1 * V_12 ) + V_14 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_14 ,
T_3 V_16 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
F_16 ( V_16 , V_2 -> V_3 -> V_15 + ( 1 * V_12 ) + V_14 ) ;
}
static int T_6 F_28 ( struct V_20 * V_21 ,
const struct V_22 * V_10 )
{
struct V_23 * V_3 ;
int V_24 = - V_25 ;
const char * V_26 ;
T_3 V_27 ;
V_3 = F_29 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
goto V_29;
V_24 = F_30 ( V_21 ) ;
if ( V_24 )
goto V_30;
V_26 = F_31 ( & V_21 -> V_21 ) ;
if ( V_21 -> V_31 && V_21 -> V_31 -> V_26 )
V_26 = V_21 -> V_31 -> V_26 ;
V_24 = F_32 ( V_21 , V_26 ) ;
if ( V_24 )
goto V_32;
F_33 ( V_21 ) ;
F_34 ( V_21 , 0x40 , & V_27 ) ;
if ( ( V_27 & 0x0000ff00 ) != 0 )
F_2 ( V_21 , 0x40 , V_27 & 0xffff00ff ) ;
if ( ! F_35 ( V_21 ) )
F_36 ( V_3 , L_2 ) ;
V_24 = - V_25 ;
V_3 -> V_15 = F_37 ( V_21 , 0 , ~ 0UL ) ;
if ( ! V_3 -> V_15 )
goto V_33;
V_3 -> V_4 = V_21 ;
V_3 -> V_34 = V_35 ;
V_3 -> V_36 = & V_37 ;
V_3 -> V_38 . V_39 = V_3 -> V_4 -> V_40 ;
V_3 -> V_38 . type = V_3 -> V_4 -> V_41 ;
V_24 = F_38 ( V_3 ) ;
if ( V_24 )
goto V_42;
F_39 ( V_21 , V_3 ) ;
V_29:
return V_24 ;
V_42:
F_40 ( V_21 , V_3 -> V_15 ) ;
V_33:
F_41 ( V_21 ) ;
V_32:
F_42 ( V_21 ) ;
V_30:
F_43 ( V_3 ) ;
return V_24 ;
}
static void T_7 F_44 ( struct V_20 * V_21 )
{
struct V_23 * V_3 = F_45 ( V_21 ) ;
F_46 ( V_3 ) ;
F_40 ( V_21 , V_3 -> V_15 ) ;
F_41 ( V_21 ) ;
F_42 ( V_21 ) ;
F_43 ( V_3 ) ;
F_39 ( V_21 , NULL ) ;
}
static int F_47 ( struct V_43 * V_21 )
{
struct V_20 * V_44 = F_48 ( V_21 ) ;
struct V_23 * V_3 = F_45 ( V_44 ) ;
V_3 -> V_9 = NULL ;
return F_49 ( V_3 ) ;
}
static int F_50 ( struct V_43 * V_21 )
{
struct V_20 * V_44 = F_48 ( V_21 ) ;
struct V_23 * V_3 = F_45 ( V_44 ) ;
return F_51 ( V_3 ) ;
}
int T_8 F_52 ( void )
{
return F_53 ( & V_45 ) ;
}
void T_9 F_54 ( void )
{
F_55 ( & V_45 ) ;
}
