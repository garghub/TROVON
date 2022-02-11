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
static int F_18 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
struct V_3 * V_4 = F_19 ( V_35 ,
struct V_3 , V_38 ) ;
if ( V_36 & V_4 -> V_39 )
F_9 ( V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_40 * V_41 )
{
struct V_3 * V_42 ;
struct V_43 * V_44 ;
T_5 V_45 ;
int V_15 ;
if ( ! V_41 || ! V_41 -> V_44 . V_46 )
return - V_47 ;
V_44 = & V_41 -> V_44 ;
V_42 = F_21 ( V_44 , sizeof( * V_42 ) , V_48 ) ;
if ( ! V_42 )
return - V_49 ;
F_22 ( & V_42 -> V_22 ) ;
V_15 = F_23 ( V_44 -> V_46 , L_8 ,
& V_45 ) ;
if ( V_15 ) {
F_24 ( V_44 , L_9 ) ;
goto V_50;
}
V_42 -> V_31 = V_45 ;
V_15 = F_23 ( V_44 -> V_46 , L_10 , & V_45 ) ;
if ( V_15 ) {
F_24 ( V_44 , L_11 ) ;
goto V_50;
}
V_42 -> V_39 = 1ull << V_45 ;
V_42 -> V_38 . V_51 = F_18 ;
V_15 = F_25 ( & V_42 -> V_38 ) ;
if ( V_15 ) {
F_24 ( V_44 , L_12 , V_15 ) ;
goto V_50;
}
V_42 -> V_12 = F_26 ( V_44 ,
sizeof( * V_42 -> V_12 ) + V_18 ,
V_48 ) ;
if ( ! V_42 -> V_12 ) {
V_15 = - V_49 ;
goto V_52;
}
V_15 = F_27 ( & V_53 , V_42 ,
& V_42 -> V_54 , V_44 , 0 ) ;
if ( V_15 ) {
F_24 ( V_44 , L_13 , V_15 ) ;
goto V_55;
}
F_28 ( V_44 , V_42 ) ;
return 0 ;
V_55:
F_29 ( V_44 , V_42 -> V_12 ) ;
V_52:
F_30 ( & V_42 -> V_38 ) ;
V_50:
F_29 ( V_44 , V_42 ) ;
return V_15 ;
}
static int F_31 ( struct V_40 * V_41 )
{
struct V_3 * V_4 = F_32 ( & V_41 -> V_44 ) ;
F_33 ( V_4 -> V_2 ) ;
F_30 ( & V_4 -> V_38 ) ;
return 0 ;
}
