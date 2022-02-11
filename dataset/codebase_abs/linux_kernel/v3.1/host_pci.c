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
void F_16 ( struct V_1 * V_2 , void * V_14 ,
T_4 V_15 , T_2 V_11 , T_1 V_16 )
{
void T_5 * V_6 = V_2 -> V_3 -> V_12 + V_11 ;
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
switch ( V_16 ) {
case sizeof( T_1 ) :
F_17 ( V_6 , V_14 , V_15 ) ;
break;
case sizeof( T_2 ) :
F_18 ( V_15 & 1 ) ;
F_19 ( V_6 , V_14 , V_15 >> 1 ) ;
break;
case sizeof( T_3 ) :
F_18 ( V_15 & 3 ) ;
F_20 ( V_6 , V_14 , V_15 >> 2 ) ;
break;
default:
F_18 ( 1 ) ;
}
}
void F_21 ( struct V_1 * V_2 , const void * V_14 ,
T_4 V_15 , T_2 V_11 , T_1 V_16 )
{
void T_5 * V_6 = V_2 -> V_3 -> V_12 + V_11 ;
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
switch ( V_16 ) {
case sizeof( T_1 ) :
F_22 ( V_6 , V_14 , V_15 ) ;
break;
case sizeof( T_2 ) :
F_18 ( V_15 & 1 ) ;
F_23 ( V_6 , V_14 , V_15 >> 1 ) ;
break;
case sizeof( T_3 ) :
F_18 ( V_15 & 3 ) ;
F_24 ( V_6 , V_14 , V_15 >> 2 ) ;
break;
default:
F_18 ( 1 ) ;
}
}
static T_3 F_25 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
return F_9 ( V_2 -> V_3 -> V_12 + ( 1 * V_17 ) + V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_11 ,
T_3 V_13 )
{
if ( V_2 -> V_3 -> V_9 != V_2 )
F_1 ( V_2 ) ;
F_15 ( V_13 , V_2 -> V_3 -> V_12 + ( 1 * V_17 ) + V_11 ) ;
}
static int F_27 ( struct V_18 * V_19 ,
const struct V_20 * V_10 )
{
struct V_21 * V_3 ;
int V_22 = - V_23 ;
const char * V_24 ;
T_3 V_25 ;
V_3 = F_28 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
goto V_27;
V_22 = F_29 ( V_19 ) ;
if ( V_22 )
goto V_28;
V_24 = F_30 ( & V_19 -> V_19 ) ;
if ( V_19 -> V_29 && V_19 -> V_29 -> V_24 )
V_24 = V_19 -> V_29 -> V_24 ;
V_22 = F_31 ( V_19 , V_24 ) ;
if ( V_22 )
goto V_30;
F_32 ( V_19 ) ;
F_33 ( V_19 , 0x40 , & V_25 ) ;
if ( ( V_25 & 0x0000ff00 ) != 0 )
F_2 ( V_19 , 0x40 , V_25 & 0xffff00ff ) ;
if ( ! F_34 ( V_19 ) )
F_35 ( L_2 ) ;
V_22 = - V_23 ;
V_3 -> V_12 = F_36 ( V_19 , 0 , ~ 0UL ) ;
if ( ! V_3 -> V_12 )
goto V_31;
V_3 -> V_4 = V_19 ;
V_3 -> V_32 = V_33 ;
V_3 -> V_34 = & V_35 ;
V_22 = F_37 ( V_3 ) ;
if ( V_22 )
goto V_36;
F_38 ( V_19 , V_3 ) ;
V_27:
return V_22 ;
V_36:
F_39 ( V_19 , V_3 -> V_12 ) ;
V_31:
F_40 ( V_19 ) ;
V_30:
F_41 ( V_19 ) ;
V_28:
F_42 ( V_3 ) ;
return V_22 ;
}
static void F_43 ( struct V_18 * V_19 )
{
struct V_21 * V_3 = F_44 ( V_19 ) ;
F_45 ( V_3 ) ;
F_39 ( V_19 , V_3 -> V_12 ) ;
F_40 ( V_19 ) ;
F_41 ( V_19 ) ;
F_42 ( V_3 ) ;
F_38 ( V_19 , NULL ) ;
}
int T_6 F_46 ( void )
{
return F_47 ( & V_37 ) ;
}
void T_7 F_48 ( void )
{
F_49 ( & V_37 ) ;
}
