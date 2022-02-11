static int F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static void F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 , T_2 V_7 )
{
V_6 -> V_8 [ 0 ] = V_6 -> V_9 [ 0 ] | 0x4 ;
V_6 -> V_8 [ 1 ] = V_6 -> V_9 [ 1 ] ;
V_6 -> V_8 [ 2 ] = V_7 ;
V_6 -> V_10 = 3 ;
F_3 ( V_4 -> V_2 , V_6 ) ;
}
static void F_4 ( void * V_1 , struct V_5 * V_6 )
{
struct V_3 * V_4 = V_1 ;
struct V_11 * V_12 ;
unsigned long V_13 ;
int V_14 , V_15 ;
T_3 V_16 ;
if ( V_6 -> V_17 > V_18 ) {
V_14 = V_19 ;
goto V_20;
}
if ( V_6 -> V_17 < 2 ) {
V_14 = V_21 ;
goto V_20;
}
F_5 ( & V_4 -> V_22 , V_13 ) ;
if ( V_4 -> V_23 ) {
V_14 = V_24 ;
goto V_25;
}
V_12 = V_4 -> V_12 ;
V_12 -> V_26 = V_27 ;
V_12 -> V_28 = V_6 -> V_9 [ 0 ] ;
V_12 -> V_29 = V_6 -> V_9 [ 1 ] ;
if ( V_6 -> V_17 > 2 )
memcpy ( V_12 -> V_9 , V_6 -> V_9 + 2 , V_6 -> V_17 - 2 ) ;
V_16 = sizeof( * V_12 ) + V_6 -> V_17 - 2 ;
F_6 ( L_1 , V_30 ,
V_4 -> V_31 , V_12 , V_16 ) ;
V_15 = F_7 ( V_4 -> V_31 , V_12 , V_16 ) ;
F_6 ( L_2 , V_30 , V_15 ) ;
if ( ! V_15 ) {
V_4 -> V_23 = V_6 ;
F_8 ( & V_4 -> V_22 , V_13 ) ;
return;
}
V_14 = V_32 ;
V_25:
F_8 ( & V_4 -> V_22 , V_13 ) ;
V_20:
F_2 ( V_4 , V_6 , V_14 ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 ;
unsigned long V_13 ;
T_4 V_16 ;
int V_15 ;
F_6 ( L_3 , V_30 ,
V_4 -> V_31 ) ;
F_5 ( & V_4 -> V_22 , V_13 ) ;
if ( ! V_4 -> V_23 ) {
F_8 ( & V_4 -> V_22 , V_13 ) ;
F_10 ( L_4 ) ;
return 0 ;
}
V_6 = V_4 -> V_23 ;
V_12 = V_4 -> V_12 ;
V_16 = F_11 ( sizeof( * V_12 ) + V_18 ) ;
V_15 = F_12 ( V_4 -> V_31 ,
V_12 ,
& V_16 ) ;
V_16 = F_13 ( V_16 ) ;
F_6 ( L_5 , V_30 ,
V_15 , V_15 == 0 ? V_16 : 0 ) ;
if ( V_15 ) {
F_8 ( & V_4 -> V_22 , V_13 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
if ( V_16 < sizeof( * V_12 ) ) {
F_8 ( & V_4 -> V_22 , V_13 ) ;
F_10 ( L_6 , V_16 ) ;
return 0 ;
}
if ( V_12 -> V_26 != V_27 ) {
F_8 ( & V_4 -> V_22 , V_13 ) ;
F_10 ( L_7 ,
V_12 -> V_26 ) ;
return 0 ;
}
V_6 -> V_8 [ 0 ] = V_12 -> V_28 ;
V_6 -> V_8 [ 1 ] = V_12 -> V_29 ;
if ( V_16 > sizeof( * V_12 ) )
memcpy ( & V_6 -> V_8 [ 2 ] , V_12 -> V_9 , V_16 - sizeof( * V_12 ) ) ;
V_6 -> V_10 = 2 + V_16 - sizeof( * V_12 ) ;
V_4 -> V_23 = NULL ;
F_8 ( & V_4 -> V_22 , V_13 ) ;
F_3 ( V_4 -> V_2 , V_6 ) ;
return 0 ;
}
static void F_15 ( void * V_1 )
{
}
static void F_16 ( void * V_1 ,
bool V_33 )
{
}
static void F_17 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_9 ( V_4 ) ;
}
static T_5 F_18 ( int V_34 , void * V_9 )
{
struct V_3 * V_4 = V_9 ;
F_9 ( V_4 ) ;
return V_35 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_3 * V_38 ;
struct V_39 * V_40 ;
T_6 V_41 ;
int V_15 ;
if ( ! V_37 || ! V_37 -> V_40 . V_42 )
return - V_43 ;
V_40 = & V_37 -> V_40 ;
V_38 = F_20 ( V_40 , sizeof( * V_38 ) , V_44 ) ;
if ( ! V_38 )
return - V_45 ;
F_21 ( & V_38 -> V_22 ) ;
V_15 = F_22 ( V_40 -> V_42 , L_8 ,
& V_41 ) ;
if ( V_15 ) {
F_23 ( V_40 , L_9 ) ;
goto V_46;
}
V_38 -> V_31 = V_41 ;
V_15 = F_22 ( V_40 -> V_42 , L_10 , & V_41 ) ;
if ( V_15 ) {
F_23 ( V_40 , L_11 ) ;
goto V_46;
}
V_38 -> V_34 = F_24 ( V_40 -> V_42 , 0 ) ;
if ( ! V_38 -> V_34 ) {
F_25 ( V_40 , L_12 ) ;
V_38 -> V_34 = F_26 ( V_41 ) ;
}
if ( F_27 ( V_38 -> V_34 , F_18 , V_47 ,
L_13 , V_38 ) ) {
F_23 ( V_40 , L_14 ) ;
goto V_48;
}
V_38 -> V_12 = F_28 ( V_40 ,
sizeof( * V_38 -> V_12 ) + V_18 ,
V_44 ) ;
if ( ! V_38 -> V_12 ) {
V_15 = - V_45 ;
goto V_49;
}
V_15 = F_29 ( & V_50 , V_38 ,
& V_38 -> V_51 , V_40 , 0 ) ;
if ( V_15 ) {
F_23 ( V_40 , L_15 , V_15 ) ;
goto V_52;
}
F_30 ( V_40 , V_38 ) ;
return 0 ;
V_52:
F_31 ( V_40 , V_38 -> V_12 ) ;
V_49:
F_32 ( V_38 -> V_34 , V_38 ) ;
V_48:
F_33 ( V_38 -> V_34 ) ;
V_46:
F_31 ( V_40 , V_38 ) ;
return V_15 ;
}
static int F_34 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = F_35 ( & V_37 -> V_40 ) ;
F_36 ( V_4 -> V_2 ) ;
F_32 ( V_4 -> V_34 , V_4 ) ;
F_33 ( V_4 -> V_34 ) ;
return 0 ;
}
