static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 ,
V_7 ) ;
if ( V_4 != 0 )
F_3 ( V_2 -> V_5 -> V_8 , L_1 ,
V_4 ) ;
V_2 -> V_9 = 1 ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 , 0 ) ;
if ( V_4 != 0 )
F_3 ( V_2 -> V_5 -> V_8 ,
L_2 , V_4 ) ;
V_2 -> V_9 = 0 ;
}
return V_4 ;
}
static T_1 F_4 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
F_1 ( V_2 , 0 ) ;
F_5 ( V_2 -> V_2 , 1 , V_12 | V_13 ) ;
return V_14 ;
}
static int F_6 ( struct V_5 * V_5 , struct V_15 * V_16 )
{
int V_4 ;
T_2 V_17 [ 5 ] ;
V_4 = F_7 ( V_5 , V_18 , 5 , V_17 ) ;
if ( V_4 != 0 ) {
F_3 ( V_5 -> V_8 , L_3 , V_4 ) ;
return V_4 ;
}
V_16 -> V_19 = ( V_17 [ 4 ] & V_20 ) + 100 ;
V_16 -> V_21 = ( V_17 [ 3 ] & V_22 ) - 1 ;
V_16 -> V_23 = V_17 [ 2 ] & V_24 ;
V_16 -> V_25 = V_17 [ 1 ] & V_26 ;
V_16 -> V_27 = V_17 [ 0 ] & V_28 ;
return F_8 ( V_16 ) ;
}
static int F_9 ( struct V_5 * V_5 , struct V_15 * V_16 )
{
int V_4 ;
T_2 V_17 [ 2 ] ;
V_16 -> V_19 -= 100 ;
V_16 -> V_21 += 1 ;
V_4 = F_2 ( V_5 , V_18 ,
V_28 , V_16 -> V_27 ) ;
if ( V_4 != 0 ) {
F_3 ( V_5 -> V_8 , L_4 , V_4 ) ;
return V_4 ;
}
V_17 [ 0 ] = V_16 -> V_25 ;
V_17 [ 1 ] = V_16 -> V_23 ;
V_4 = F_10 ( V_5 , V_29 , 2 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_5 , V_30 ,
V_22 , V_16 -> V_21 ) ;
if ( V_4 < 0 )
F_3 ( V_5 -> V_8 , L_5 , V_4 ) ;
V_4 = F_2 ( V_5 , V_6 ,
V_20 , V_16 -> V_19 ) ;
if ( V_4 < 0 )
F_3 ( V_5 -> V_8 , L_6 , V_4 ) ;
return V_4 ;
}
static int F_11 ( struct V_5 * V_5 )
{
int V_4 ;
V_4 = F_12 ( V_5 , V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( V_5 -> V_8 , L_7 , V_4 ) ;
return V_4 ;
}
V_4 &= V_7 ;
return ( V_4 > 0 ) ? 1 : 0 ;
}
static int F_13 ( struct V_31 * V_8 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
T_2 V_17 [ 6 ] ;
int V_4 ;
V_4 = F_12 ( V_2 -> V_5 , V_32 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_33 ) )
return - V_34 ;
V_4 = F_7 ( V_2 -> V_5 , V_32 , 6 , V_17 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_5 -> V_8 , L_8 ,
V_4 ) ;
return V_4 ;
}
V_16 -> V_19 = ( V_17 [ 5 ] & V_35 ) + 100 ;
V_16 -> V_21 = ( V_17 [ 4 ] & V_36 ) - 1 ;
V_16 -> V_23 = V_17 [ 3 ] & V_37 ;
V_16 -> V_25 = V_17 [ 2 ] & V_38 ;
V_16 -> V_27 = V_17 [ 1 ] & V_39 ;
V_16 -> V_40 = V_17 [ 0 ] & V_41 ;
return F_8 ( V_16 ) ;
}
static int F_15 ( struct V_31 * V_8 , struct V_15 * V_42 )
{
struct V_1 * V_2 ;
T_2 V_17 [ 6 ] ;
V_2 = F_14 ( V_8 ) ;
V_17 [ 0 ] = V_42 -> V_40 ;
V_17 [ 1 ] = V_42 -> V_27 ;
V_17 [ 2 ] = V_42 -> V_25 ;
V_17 [ 3 ] = V_42 -> V_23 ;
V_17 [ 4 ] = V_42 -> V_21 + 1 ;
V_17 [ 5 ] = V_42 -> V_19 - 100 ;
return F_10 ( V_2 -> V_5 , V_32 , 6 , V_17 ) ;
}
static int F_16 ( struct V_31 * V_8 , struct V_43 * V_44 )
{
int V_4 ;
struct V_15 * V_42 = & V_44 -> time ;
struct V_1 * V_2 = F_14 ( V_8 ) ;
V_4 = F_6 ( V_2 -> V_5 , V_42 ) ;
if ( V_4 )
return V_4 ;
V_44 -> V_45 = F_11 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_31 * V_8 , struct V_43 * V_44 )
{
int V_4 ;
struct V_15 * V_42 = & V_44 -> time ;
struct V_1 * V_2 = F_14 ( V_8 ) ;
V_4 = F_1 ( V_2 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_9 ( V_2 -> V_5 , V_42 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_1 ( V_2 , 1 ) ;
return V_4 ;
}
static int F_18 ( struct V_31 * V_8 , unsigned int V_45 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
return F_1 ( V_2 , V_45 ) ;
}
static int F_19 ( struct V_5 * V_5 ,
struct V_46 * V_47 )
{
int V_4 ;
V_4 = F_2 ( V_5 , V_48 ,
V_49 , V_49 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_5 , V_50 ,
V_51 , V_51 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_5 , V_48 ,
V_52 , V_52 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_47 && V_47 -> V_53 ) {
V_4 = F_2 ( V_5 , V_48 ,
V_54 ,
V_54 <<
V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_4 = F_2 ( V_5 , V_30 ,
V_56 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static int F_20 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 = NULL ;
int V_4 , V_59 ;
V_2 = F_21 ( & V_58 -> V_8 , sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_5 = F_14 ( V_58 -> V_8 . V_62 ) ;
V_47 = F_22 ( V_2 -> V_5 -> V_8 ) ;
F_23 ( V_58 , V_2 ) ;
V_4 = F_19 ( V_2 -> V_5 , V_47 ) ;
if ( V_4 < 0 )
goto V_63;
V_4 = F_12 ( V_2 -> V_5 , V_6 ) ;
if ( V_4 < 0 )
goto V_63;
if ( V_4 & V_7 )
V_2 -> V_9 = 1 ;
F_24 ( & V_58 -> V_8 , 1 ) ;
V_2 -> V_2 = F_25 ( & V_58 -> V_8 , V_58 -> V_64 ,
& V_65 , V_66 ) ;
if ( F_26 ( V_2 -> V_2 ) ) {
V_4 = F_27 ( V_2 -> V_2 ) ;
goto V_63;
}
V_59 = F_28 ( V_58 , L_9 ) ;
V_59 = F_29 ( V_2 -> V_5 -> V_67 , V_59 ) ;
V_4 = F_30 ( & V_58 -> V_8 , V_59 , NULL ,
F_4 ,
V_68 | V_69 ,
L_9 , V_2 ) ;
if ( V_4 != 0 )
F_3 ( V_2 -> V_5 -> V_8 , L_10 , V_4 ) ;
V_63:
return V_4 ;
}
static int F_31 ( struct V_31 * V_8 )
{
struct V_57 * V_58 = F_32 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( & V_58 -> V_8 ) ;
int V_4 ;
if ( ! F_33 ( & V_58 -> V_8 ) ) {
V_4 = F_1 ( V_2 , 0 ) ;
if ( V_4 < 0 )
F_3 ( & V_58 -> V_8 , L_11 ) ;
}
return 0 ;
}
static int F_34 ( struct V_31 * V_8 )
{
struct V_57 * V_58 = F_32 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( & V_58 -> V_8 ) ;
int V_4 ;
if ( ! F_33 ( & V_58 -> V_8 ) ) {
if ( V_2 -> V_9 ) {
V_4 = F_1 ( V_2 , 1 ) ;
if ( V_4 < 0 )
F_3 ( & V_58 -> V_8 ,
L_12 ) ;
}
}
return 0 ;
}
static int F_35 ( struct V_31 * V_8 )
{
struct V_57 * V_58 = F_32 ( V_8 ) ;
struct V_1 * V_2 = F_14 ( & V_58 -> V_8 ) ;
int V_4 ;
V_4 = F_1 ( V_2 , 0 ) ;
if ( V_4 < 0 )
F_3 ( & V_58 -> V_8 , L_13 ) ;
return 0 ;
}
