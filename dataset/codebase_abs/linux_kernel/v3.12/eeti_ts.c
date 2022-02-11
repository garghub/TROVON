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
struct V_37 * V_38 = V_14 -> V_15 . V_39 ;
struct V_1 * V_2 ;
struct V_33 * V_25 ;
unsigned int V_40 ;
int V_41 = - V_42 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 ) {
F_7 ( & V_14 -> V_15 , L_2 ) ;
goto V_44;
}
F_25 ( & V_2 -> V_13 ) ;
V_25 = F_26 () ;
if ( ! V_25 ) {
F_7 ( & V_14 -> V_15 , L_3 ) ;
goto V_45;
}
V_25 -> V_46 [ 0 ] = F_27 ( V_47 ) | F_27 ( V_48 ) ;
V_25 -> V_49 [ F_28 ( V_29 ) ] = F_27 ( V_29 ) ;
F_29 ( V_25 , V_27 , 0 , V_22 , 0 , 0 ) ;
F_29 ( V_25 , V_28 , 0 , V_22 , 0 , 0 ) ;
F_29 ( V_25 , V_26 , 0 , 0xff , 0 , 0 ) ;
V_25 -> V_50 = V_14 -> V_50 ;
V_25 -> V_51 . V_52 = V_53 ;
V_25 -> V_15 . V_54 = & V_14 -> V_15 ;
V_25 -> V_55 = F_20 ;
V_25 -> V_56 = F_22 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_3 = V_38 -> V_3 ;
V_2 -> V_30 = F_30 ( V_38 -> V_3 ) ;
V_41 = F_31 ( V_38 -> V_3 , V_57 , V_14 -> V_50 ) ;
if ( V_41 < 0 )
goto V_45;
V_2 -> V_4 = V_38 -> V_4 ;
V_40 = V_2 -> V_4 ?
V_58 : V_59 ;
F_32 ( & V_2 -> V_6 , F_3 ) ;
F_33 ( V_14 , V_2 ) ;
F_34 ( V_25 , V_2 ) ;
V_41 = F_35 ( V_25 ) ;
if ( V_41 )
goto V_60;
V_41 = F_36 ( V_2 -> V_30 , F_13 , V_40 ,
V_14 -> V_50 , V_2 ) ;
if ( V_41 ) {
F_7 ( & V_14 -> V_15 , L_4 ) ;
goto V_61;
}
F_17 ( V_2 ) ;
F_37 ( & V_14 -> V_15 , 0 ) ;
return 0 ;
V_61:
F_38 ( V_25 ) ;
V_25 = NULL ;
V_60:
F_39 ( V_38 -> V_3 ) ;
V_45:
F_40 ( V_25 ) ;
F_41 ( V_2 ) ;
V_44:
return V_41 ;
}
static int F_42 ( struct V_34 * V_14 )
{
struct V_1 * V_2 = F_43 ( V_14 ) ;
F_44 ( V_2 -> V_30 , V_2 ) ;
F_16 ( V_2 -> V_30 ) ;
F_38 ( V_2 -> V_25 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_62 * V_15 )
{
struct V_34 * V_14 = F_46 ( V_15 ) ;
struct V_1 * V_2 = F_43 ( V_14 ) ;
struct V_33 * V_33 = V_2 -> V_25 ;
F_5 ( & V_33 -> V_13 ) ;
if ( V_33 -> V_63 )
F_17 ( V_2 ) ;
F_12 ( & V_33 -> V_13 ) ;
if ( F_47 ( & V_14 -> V_15 ) )
F_48 ( V_2 -> V_30 ) ;
return 0 ;
}
static int F_49 ( struct V_62 * V_15 )
{
struct V_34 * V_14 = F_46 ( V_15 ) ;
struct V_1 * V_2 = F_43 ( V_14 ) ;
struct V_33 * V_33 = V_2 -> V_25 ;
if ( F_47 ( & V_14 -> V_15 ) )
F_50 ( V_2 -> V_30 ) ;
F_5 ( & V_33 -> V_13 ) ;
if ( V_33 -> V_63 )
F_15 ( V_2 ) ;
F_12 ( & V_33 -> V_13 ) ;
return 0 ;
}
