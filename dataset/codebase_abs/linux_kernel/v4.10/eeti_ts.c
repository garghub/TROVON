static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) == V_2 -> V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
char V_7 [ 6 ] ;
unsigned int V_8 , V_9 , V_10 , V_11 , V_12 = 100 ;
struct V_1 * V_2 =
F_4 ( V_6 , struct V_1 , V_6 ) ;
F_5 ( & V_2 -> V_13 ) ;
while ( F_1 ( V_2 ) && -- V_12 )
F_6 ( V_2 -> V_14 , V_7 , sizeof( V_7 ) ) ;
if ( ! V_12 ) {
F_7 ( & V_2 -> V_14 -> V_15 ,
L_1 ) ;
goto V_16;
}
if ( ! ( V_7 [ 0 ] & 0x80 ) )
goto V_16;
V_11 = V_7 [ 0 ] & V_17 ;
V_10 = F_8 ( V_7 [ 0 ] & ( V_18 | V_19 ) ) ;
V_8 = V_7 [ 2 ] | ( V_7 [ 1 ] << 8 ) ;
V_9 = V_7 [ 4 ] | ( V_7 [ 3 ] << 8 ) ;
V_8 >>= V_10 - V_20 ;
V_9 >>= V_10 - V_20 ;
if ( V_21 )
V_8 = V_22 - V_8 ;
if ( V_23 )
V_9 = V_22 - V_9 ;
if ( V_7 [ 0 ] & V_24 )
F_9 ( V_2 -> V_25 , V_26 , V_7 [ 5 ] ) ;
F_9 ( V_2 -> V_25 , V_27 , V_8 ) ;
F_9 ( V_2 -> V_25 , V_28 , V_9 ) ;
F_10 ( V_2 -> V_25 , V_29 , ! ! V_11 ) ;
F_11 ( V_2 -> V_25 ) ;
V_16:
F_12 ( & V_2 -> V_13 ) ;
}
static T_1 F_13 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
F_14 ( & V_2 -> V_6 ) ;
return V_32 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_30 ) ;
F_3 ( & V_2 -> V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_30 ) ;
F_19 ( & V_2 -> V_6 ) ;
}
static int F_20 ( struct V_33 * V_15 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_33 * V_15 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
F_17 ( V_2 ) ;
}
static int F_23 ( struct V_34 * V_14 ,
const struct V_35 * V_36 )
{
struct V_37 * V_38 = F_24 ( & V_14 -> V_15 ) ;
struct V_1 * V_2 ;
struct V_33 * V_25 ;
unsigned int V_39 ;
int V_40 = - V_41 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 ) {
F_7 ( & V_14 -> V_15 , L_2 ) ;
goto V_43;
}
F_26 ( & V_2 -> V_13 ) ;
V_25 = F_27 () ;
if ( ! V_25 ) {
F_7 ( & V_14 -> V_15 , L_3 ) ;
goto V_44;
}
V_25 -> V_45 [ 0 ] = F_28 ( V_46 ) | F_28 ( V_47 ) ;
V_25 -> V_48 [ F_29 ( V_29 ) ] = F_28 ( V_29 ) ;
F_30 ( V_25 , V_27 , 0 , V_22 , 0 , 0 ) ;
F_30 ( V_25 , V_28 , 0 , V_22 , 0 , 0 ) ;
F_30 ( V_25 , V_26 , 0 , 0xff , 0 , 0 ) ;
V_25 -> V_49 = V_14 -> V_49 ;
V_25 -> V_50 . V_51 = V_52 ;
V_25 -> V_15 . V_53 = & V_14 -> V_15 ;
V_25 -> V_54 = F_20 ;
V_25 -> V_55 = F_22 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_3 = V_38 -> V_3 ;
V_2 -> V_30 = F_31 ( V_38 -> V_3 ) ;
V_40 = F_32 ( V_38 -> V_3 , V_56 , V_14 -> V_49 ) ;
if ( V_40 < 0 )
goto V_44;
V_2 -> V_4 = V_38 -> V_4 ;
V_39 = V_2 -> V_4 ?
V_57 : V_58 ;
F_33 ( & V_2 -> V_6 , F_3 ) ;
F_34 ( V_14 , V_2 ) ;
F_35 ( V_25 , V_2 ) ;
V_40 = F_36 ( V_25 ) ;
if ( V_40 )
goto V_59;
V_40 = F_37 ( V_2 -> V_30 , F_13 , V_39 ,
V_14 -> V_49 , V_2 ) ;
if ( V_40 ) {
F_7 ( & V_14 -> V_15 , L_4 ) ;
goto V_60;
}
F_17 ( V_2 ) ;
F_38 ( & V_14 -> V_15 , 0 ) ;
return 0 ;
V_60:
F_39 ( V_25 ) ;
V_25 = NULL ;
V_59:
F_40 ( V_38 -> V_3 ) ;
V_44:
F_41 ( V_25 ) ;
F_42 ( V_2 ) ;
V_43:
return V_40 ;
}
static int F_43 ( struct V_34 * V_14 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
F_45 ( V_2 -> V_30 , V_2 ) ;
F_16 ( V_2 -> V_30 ) ;
F_39 ( V_2 -> V_25 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int T_2 F_46 ( struct V_61 * V_15 )
{
struct V_34 * V_14 = F_47 ( V_15 ) ;
struct V_1 * V_2 = F_44 ( V_14 ) ;
struct V_33 * V_33 = V_2 -> V_25 ;
F_5 ( & V_33 -> V_13 ) ;
if ( V_33 -> V_62 )
F_17 ( V_2 ) ;
F_12 ( & V_33 -> V_13 ) ;
if ( F_48 ( & V_14 -> V_15 ) )
F_49 ( V_2 -> V_30 ) ;
return 0 ;
}
static int T_2 F_50 ( struct V_61 * V_15 )
{
struct V_34 * V_14 = F_47 ( V_15 ) ;
struct V_1 * V_2 = F_44 ( V_14 ) ;
struct V_33 * V_33 = V_2 -> V_25 ;
if ( F_48 ( & V_14 -> V_15 ) )
F_51 ( V_2 -> V_30 ) ;
F_5 ( & V_33 -> V_13 ) ;
if ( V_33 -> V_62 )
F_15 ( V_2 ) ;
F_12 ( & V_33 -> V_13 ) ;
return 0 ;
}
