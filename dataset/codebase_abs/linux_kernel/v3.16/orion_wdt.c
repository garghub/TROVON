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
T_1 V_8 ;
F_15 ( V_4 -> V_7 * V_15 -> V_16 ,
V_4 -> V_8 + V_4 -> V_17 -> V_18 ) ;
F_9 ( V_4 -> V_8 + V_19 , V_20 , 0 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 ,
V_4 -> V_17 -> V_21 ) ;
V_8 = F_17 ( V_4 -> V_22 ) ;
V_8 |= V_4 -> V_17 -> V_23 ;
F_15 ( V_8 , V_4 -> V_22 ) ;
F_9 ( V_4 -> V_24 , V_4 -> V_17 -> V_25 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
T_1 V_8 ;
F_15 ( V_4 -> V_7 * V_15 -> V_16 ,
V_4 -> V_8 + V_4 -> V_17 -> V_18 ) ;
F_9 ( V_4 -> V_8 + V_19 , V_20 , 0 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 ,
V_4 -> V_17 -> V_21 ) ;
V_8 = F_17 ( V_4 -> V_22 ) ;
V_8 |= V_4 -> V_17 -> V_23 ;
F_15 ( V_8 , V_4 -> V_22 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
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
static int F_20 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
return V_4 -> V_17 -> V_26 ( V_15 ) ;
}
static int F_21 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_9 ( V_4 -> V_22 , V_4 -> V_17 -> V_23 , 0 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
T_1 V_8 ;
F_9 ( V_4 -> V_24 , V_4 -> V_17 -> V_25 ,
V_4 -> V_17 -> V_25 ) ;
V_8 = F_17 ( V_4 -> V_22 ) ;
V_8 &= ~ V_4 -> V_17 -> V_23 ;
F_15 ( V_8 , V_4 -> V_22 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
T_1 V_8 ;
V_8 = F_17 ( V_4 -> V_22 ) ;
V_8 &= ~ V_4 -> V_17 -> V_23 ;
F_15 ( V_8 , V_4 -> V_22 ) ;
F_9 ( V_4 -> V_8 + V_9 , V_4 -> V_17 -> V_21 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
return V_4 -> V_17 -> V_27 ( V_15 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
bool V_28 , V_29 ;
V_28 = F_17 ( V_4 -> V_22 ) & V_4 -> V_17 -> V_23 ;
V_29 = F_17 ( V_4 -> V_8 + V_9 ) & V_4 -> V_17 -> V_21 ;
return V_28 && V_29 ;
}
static int F_26 ( struct V_3 * V_4 )
{
bool V_30 , V_28 , V_29 ;
V_30 = F_17 ( V_4 -> V_24 ) & V_4 -> V_17 -> V_25 ;
V_28 = F_17 ( V_4 -> V_22 ) & V_4 -> V_17 -> V_23 ;
V_29 = F_17 ( V_4 -> V_8 + V_9 ) & V_4 -> V_17 -> V_21 ;
return ! V_30 && V_28 && V_29 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
return V_4 -> V_17 -> V_28 ( V_4 ) ;
}
static unsigned int F_28 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_14 ( V_15 ) ;
return F_17 ( V_4 -> V_8 + V_4 -> V_17 -> V_18 ) / V_4 -> V_7 ;
}
static int F_29 ( struct V_14 * V_15 ,
unsigned int V_16 )
{
V_15 -> V_16 = V_16 ;
return 0 ;
}
static T_2 F_30 ( int V_31 , void * V_32 )
{
F_31 ( L_2 ) ;
return V_33 ;
}
static void T_3 * F_32 ( struct V_1 * V_2 ,
T_4 V_34 )
{
struct V_35 * V_36 ;
T_4 V_22 ;
V_36 = F_33 ( V_2 , V_37 , 1 ) ;
if ( V_36 )
return F_34 ( & V_2 -> V_4 , V_36 -> V_26 ,
F_35 ( V_36 ) ) ;
V_22 = V_34 + V_38 ;
F_36 ( 1 , V_39 L_3 , & V_22 ) ;
return F_34 ( & V_2 -> V_4 , V_22 , 0x4 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_40 * V_41 = V_2 -> V_4 . V_12 ;
struct V_35 * V_36 ;
V_36 = F_33 ( V_2 , V_37 , 0 ) ;
if ( ! V_36 )
return - V_42 ;
V_4 -> V_8 = F_34 ( & V_2 -> V_4 , V_36 -> V_26 ,
F_35 ( V_36 ) ) ;
if ( ! V_4 -> V_8 )
return - V_43 ;
if ( F_38 ( V_41 , L_4 ) ) {
V_4 -> V_22 = F_32 ( V_2 , V_36 -> V_26 &
V_44 ) ;
if ( ! V_4 -> V_22 )
return - V_42 ;
} else if ( F_38 ( V_41 , L_5 ) ||
F_38 ( V_41 , L_6 ) ) {
V_36 = F_33 ( V_2 , V_37 , 1 ) ;
V_4 -> V_22 = F_39 ( & V_2 -> V_4 , V_36 ) ;
if ( F_3 ( V_4 -> V_22 ) )
return F_4 ( V_4 -> V_22 ) ;
} else if ( F_38 ( V_41 , L_7 ) ||
F_38 ( V_41 , L_8 ) ) {
V_36 = F_33 ( V_2 , V_37 , 1 ) ;
V_4 -> V_22 = F_39 ( & V_2 -> V_4 , V_36 ) ;
if ( F_3 ( V_4 -> V_22 ) )
return F_4 ( V_4 -> V_22 ) ;
V_36 = F_33 ( V_2 , V_37 , 2 ) ;
if ( ! V_36 )
return - V_42 ;
V_4 -> V_24 = F_34 ( & V_2 -> V_4 , V_36 -> V_26 ,
F_35 ( V_36 ) ) ;
if ( ! V_4 -> V_24 )
return - V_43 ;
} else {
return - V_42 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const struct V_45 * V_46 ;
unsigned int V_47 ;
int V_5 , V_31 ;
V_4 = F_41 ( & V_2 -> V_4 , sizeof( struct V_3 ) ,
V_48 ) ;
if ( ! V_4 )
return - V_43 ;
V_46 = F_42 ( V_49 , & V_2 -> V_4 ) ;
if ( ! V_46 )
V_46 = & V_49 [ 0 ] ;
V_4 -> V_50 . V_51 = & V_52 ;
V_4 -> V_50 . V_53 = & V_54 ;
V_4 -> V_50 . V_55 = 1 ;
V_4 -> V_17 = V_46 -> V_17 ;
V_5 = F_37 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = V_4 -> V_17 -> V_56 ( V_2 , V_4 ) ;
if ( V_5 ) {
F_43 ( & V_2 -> V_4 , L_9 ) ;
return V_5 ;
}
V_47 = V_57 / V_4 -> V_7 ;
V_4 -> V_50 . V_16 = V_47 ;
V_4 -> V_50 . V_58 = V_47 ;
F_44 ( & V_4 -> V_50 , V_59 , & V_2 -> V_4 ) ;
F_45 ( V_2 , & V_4 -> V_50 ) ;
F_46 ( & V_4 -> V_50 , V_4 ) ;
if ( ! F_27 ( & V_4 -> V_50 ) )
F_24 ( & V_4 -> V_50 ) ;
V_31 = F_47 ( V_2 , 0 ) ;
if ( V_31 > 0 ) {
V_5 = F_48 ( & V_2 -> V_4 , V_31 , F_30 , 0 ,
V_2 -> V_60 , V_4 ) ;
if ( V_5 < 0 ) {
F_43 ( & V_2 -> V_4 , L_10 ) ;
goto V_61;
}
}
F_49 ( & V_4 -> V_50 , V_62 ) ;
V_5 = F_50 ( & V_4 -> V_50 ) ;
if ( V_5 )
goto V_61;
F_51 ( L_11 ,
V_4 -> V_50 . V_16 , V_62 ? L_12 : L_13 ) ;
return 0 ;
V_61:
F_52 ( V_4 -> V_6 ) ;
F_6 ( V_4 -> V_6 ) ;
return V_5 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_54 ( V_2 ) ;
struct V_3 * V_4 = F_14 ( V_15 ) ;
F_55 ( V_15 ) ;
F_52 ( V_4 -> V_6 ) ;
F_6 ( V_4 -> V_6 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_54 ( V_2 ) ;
F_24 ( V_15 ) ;
}
