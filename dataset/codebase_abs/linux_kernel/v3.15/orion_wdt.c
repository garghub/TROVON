static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_4 -> V_6 = F_2 ( & V_2 -> V_4 , NULL ) ;
if ( F_3 ( V_4 -> V_6 ) )
return F_4 ( V_4 -> V_6 ) ;
V_5 = F_5 ( V_4 -> V_6 ) ;
if ( V_5 ) {
F_6 ( V_4 -> V_6 ) ;
return V_5 ;
}
V_4 -> V_7 = F_7 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_4 -> V_6 = F_2 ( & V_2 -> V_4 , NULL ) ;
if ( F_3 ( V_4 -> V_6 ) )
return F_4 ( V_4 -> V_6 ) ;
V_5 = F_5 ( V_4 -> V_6 ) ;
if ( V_5 ) {
F_6 ( V_4 -> V_6 ) ;
return V_5 ;
}
F_9 ( V_4 -> V_8 + V_9 ,
F_10 ( V_10 ) ,
F_10 ( V_10 ) ) ;
V_4 -> V_7 = F_7 ( V_4 -> V_6 ) / V_11 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_4 -> V_6 = F_12 ( V_2 -> V_4 . V_12 , L_1 ) ;
if ( F_3 ( V_4 -> V_6 ) )
return F_4 ( V_4 -> V_6 ) ;
V_5 = F_5 ( V_4 -> V_6 ) ;
if ( V_5 ) {
F_6 ( V_4 -> V_6 ) ;
return V_5 ;
}
F_9 ( V_4 -> V_8 + V_9 ,
V_13 ,
V_13 ) ;
V_4 -> V_7 = F_7 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_15 ( V_4 -> V_7 * V_15 -> V_16 ,
V_4 -> V_8 + V_4 -> V_17 -> V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_15 ( V_4 -> V_7 * V_15 -> V_16 ,
V_4 -> V_8 + V_4 -> V_17 -> V_18 ) ;
F_9 ( V_4 -> V_8 + V_19 , V_20 , 0 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 ,
V_4 -> V_17 -> V_21 ) ;
F_9 ( V_4 -> V_22 , V_4 -> V_17 -> V_23 ,
V_4 -> V_17 -> V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_15 ( V_4 -> V_7 * V_15 -> V_16 ,
V_4 -> V_8 + V_4 -> V_17 -> V_18 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 ,
V_4 -> V_17 -> V_21 ) ;
F_9 ( V_4 -> V_22 , V_4 -> V_17 -> V_23 ,
V_4 -> V_17 -> V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
return V_4 -> V_17 -> V_24 ( V_15 ) ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_9 ( V_4 -> V_22 , V_4 -> V_17 -> V_23 , 0 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
bool V_25 , V_26 ;
V_25 = F_21 ( V_4 -> V_22 ) & V_4 -> V_17 -> V_23 ;
V_26 = F_21 ( V_4 -> V_8 + V_9 ) & V_4 -> V_17 -> V_21 ;
return V_25 && V_26 ;
}
static unsigned int F_22 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
return F_21 ( V_4 -> V_8 + V_4 -> V_17 -> V_18 ) / V_4 -> V_7 ;
}
static int F_23 ( struct V_14 * V_15 ,
unsigned int V_16 )
{
V_15 -> V_16 = V_16 ;
return 0 ;
}
static T_1 F_24 ( int V_27 , void * V_28 )
{
F_25 ( L_2 ) ;
return V_29 ;
}
static void T_2 * F_26 ( struct V_1 * V_2 ,
T_3 V_30 )
{
struct V_31 * V_32 ;
T_3 V_22 ;
V_32 = F_27 ( V_2 , V_33 , 1 ) ;
if ( V_32 )
return F_28 ( & V_2 -> V_4 , V_32 -> V_24 ,
F_29 ( V_32 ) ) ;
if ( ! F_30 ( V_2 -> V_4 . V_12 , L_3 ) )
return NULL ;
V_22 = V_30 + V_34 ;
F_31 ( 1 , V_35 L_4 , & V_22 ) ;
return F_28 ( & V_2 -> V_4 , V_22 , 0x4 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_36 * V_37 ;
unsigned int V_38 ;
struct V_31 * V_32 ;
int V_5 , V_27 ;
V_4 = F_33 ( & V_2 -> V_4 , sizeof( struct V_3 ) ,
V_39 ) ;
if ( ! V_4 )
return - V_40 ;
V_37 = F_34 ( V_41 , & V_2 -> V_4 ) ;
if ( ! V_37 )
V_37 = & V_41 [ 0 ] ;
V_4 -> V_42 . V_43 = & V_44 ;
V_4 -> V_42 . V_45 = & V_46 ;
V_4 -> V_42 . V_47 = 1 ;
V_4 -> V_17 = V_37 -> V_17 ;
V_32 = F_27 ( V_2 , V_33 , 0 ) ;
if ( ! V_32 )
return - V_48 ;
V_4 -> V_8 = F_28 ( & V_2 -> V_4 , V_32 -> V_24 ,
F_29 ( V_32 ) ) ;
if ( ! V_4 -> V_8 )
return - V_40 ;
V_4 -> V_22 = F_26 ( V_2 , V_32 -> V_24 &
V_49 ) ;
if ( ! V_4 -> V_22 )
return - V_48 ;
V_5 = V_4 -> V_17 -> V_50 ( V_2 , V_4 ) ;
if ( V_5 ) {
F_35 ( & V_2 -> V_4 , L_5 ) ;
return V_5 ;
}
V_38 = V_51 / V_4 -> V_7 ;
V_4 -> V_42 . V_16 = V_38 ;
V_4 -> V_42 . V_52 = V_38 ;
F_36 ( & V_4 -> V_42 , V_53 , & V_2 -> V_4 ) ;
F_37 ( V_2 , & V_4 -> V_42 ) ;
F_38 ( & V_4 -> V_42 , V_4 ) ;
if ( ! F_20 ( V_4 ) )
F_19 ( & V_4 -> V_42 ) ;
V_27 = F_39 ( V_2 , 0 ) ;
if ( V_27 > 0 ) {
V_5 = F_40 ( & V_2 -> V_4 , V_27 , F_24 , 0 ,
V_2 -> V_54 , V_4 ) ;
if ( V_5 < 0 ) {
F_35 ( & V_2 -> V_4 , L_6 ) ;
goto V_55;
}
}
F_41 ( & V_4 -> V_42 , V_56 ) ;
V_5 = F_42 ( & V_4 -> V_42 ) ;
if ( V_5 )
goto V_55;
F_43 ( L_7 ,
V_4 -> V_42 . V_16 , V_56 ? L_8 : L_9 ) ;
return 0 ;
V_55:
F_44 ( V_4 -> V_6 ) ;
F_6 ( V_4 -> V_6 ) ;
return V_5 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_46 ( V_2 ) ;
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_47 ( V_15 ) ;
F_44 ( V_4 -> V_6 ) ;
F_6 ( V_4 -> V_6 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_46 ( V_2 ) ;
F_19 ( V_15 ) ;
}
