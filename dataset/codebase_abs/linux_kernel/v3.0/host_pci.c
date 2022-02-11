static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 -> V_4 , V_5 ,
V_2 -> V_6 ) ;
F_2 ( V_2 -> V_3 -> V_4 , V_7 ,
V_2 -> V_8 ) ;
V_2 -> V_3 -> V_9 = V_2 ;
F_3 ( L_1 , V_2 -> V_10 . V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return F_5 ( V_2 -> V_3 -> V_12 + V_11 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return F_7 ( V_2 -> V_3 -> V_12 + V_11 ) ;
}
static T_3 F_8 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return F_9 ( V_2 -> V_3 -> V_12 + V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_11 ,
T_1 V_13 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
F_11 ( V_13 , V_2 -> V_3 -> V_12 + V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_2 V_11 ,
T_2 V_13 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
F_13 ( V_13 , V_2 -> V_3 -> V_12 + V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_2 V_11 ,
T_3 V_13 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
F_15 ( V_13 , V_2 -> V_3 -> V_12 + V_11 ) ;
}
static T_3 F_16 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return F_9 ( V_2 -> V_3 -> V_12 + ( 1 * V_14 ) + V_11 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_11 ,
T_3 V_13 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
F_15 ( V_13 , V_2 -> V_3 -> V_12 + ( 1 * V_14 ) + V_11 ) ;
}
static int F_18 ( struct V_15 * V_16 ,
const struct V_17 * V_10 )
{
struct V_18 * V_3 ;
int V_19 = - V_20 ;
const char * V_21 ;
T_3 V_22 ;
V_3 = F_19 ( sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 )
goto V_24;
V_19 = F_20 ( V_16 ) ;
if ( V_19 )
goto V_25;
V_21 = F_21 ( & V_16 -> V_16 ) ;
if ( V_16 -> V_26 && V_16 -> V_26 -> V_21 )
V_21 = V_16 -> V_26 -> V_21 ;
V_19 = F_22 ( V_16 , V_21 ) ;
if ( V_19 )
goto V_27;
F_23 ( V_16 ) ;
F_24 ( V_16 , 0x40 , & V_22 ) ;
if ( ( V_22 & 0x0000ff00 ) != 0 )
F_2 ( V_16 , 0x40 , V_22 & 0xffff00ff ) ;
if ( ! F_25 ( V_16 ) )
F_26 ( L_2 ) ;
V_19 = - V_20 ;
V_3 -> V_12 = F_27 ( V_16 , 0 , ~ 0UL ) ;
if ( ! V_3 -> V_12 )
goto V_28;
V_3 -> V_4 = V_16 ;
V_3 -> V_29 = V_30 ;
V_3 -> V_31 = & V_32 ;
V_19 = F_28 ( V_3 ) ;
if ( V_19 )
goto V_33;
F_29 ( V_16 , V_3 ) ;
V_24:
return V_19 ;
V_33:
F_30 ( V_16 , V_3 -> V_12 ) ;
V_28:
F_31 ( V_16 ) ;
V_27:
F_32 ( V_16 ) ;
V_25:
F_33 ( V_3 ) ;
return V_19 ;
}
static void F_34 ( struct V_15 * V_16 )
{
struct V_18 * V_3 = F_35 ( V_16 ) ;
F_36 ( V_3 ) ;
F_30 ( V_16 , V_3 -> V_12 ) ;
F_31 ( V_16 ) ;
F_32 ( V_16 ) ;
F_33 ( V_3 ) ;
F_29 ( V_16 , NULL ) ;
}
int T_4 F_37 ( void )
{
return F_38 ( & V_34 ) ;
}
void T_5 F_39 ( void )
{
F_40 ( & V_34 ) ;
}
